static s32 vmci_transport_error_to_vsock_error(s32 vmci_error)
{
int err;
switch (vmci_error) {
case VMCI_ERROR_NO_MEM:
err = ENOMEM;
break;
case VMCI_ERROR_DUPLICATE_ENTRY:
case VMCI_ERROR_ALREADY_EXISTS:
err = EADDRINUSE;
break;
case VMCI_ERROR_NO_ACCESS:
err = EPERM;
break;
case VMCI_ERROR_NO_RESOURCES:
err = ENOBUFS;
break;
case VMCI_ERROR_INVALID_RESOURCE:
err = EHOSTUNREACH;
break;
case VMCI_ERROR_INVALID_ARGS:
default:
err = EINVAL;
}
return err > 0 ? -err : err;
}
static u32 vmci_transport_peer_rid(u32 peer_cid)
{
if (VMADDR_CID_HYPERVISOR == peer_cid)
return VMCI_TRANSPORT_HYPERVISOR_PACKET_RID;
return VMCI_TRANSPORT_PACKET_RID;
}
static inline void
vmci_transport_packet_init(struct vmci_transport_packet *pkt,
struct sockaddr_vm *src,
struct sockaddr_vm *dst,
u8 type,
u64 size,
u64 mode,
struct vmci_transport_waiting_info *wait,
u16 proto,
struct vmci_handle handle)
{
pkt->dg.src = vmci_make_handle(VMADDR_CID_ANY,
VMCI_TRANSPORT_PACKET_RID);
pkt->dg.dst = vmci_make_handle(dst->svm_cid,
vmci_transport_peer_rid(dst->svm_cid));
pkt->dg.payload_size = sizeof(*pkt) - sizeof(pkt->dg);
pkt->version = VMCI_TRANSPORT_PACKET_VERSION;
pkt->type = type;
pkt->src_port = src->svm_port;
pkt->dst_port = dst->svm_port;
memset(&pkt->proto, 0, sizeof(pkt->proto));
memset(&pkt->_reserved2, 0, sizeof(pkt->_reserved2));
switch (pkt->type) {
case VMCI_TRANSPORT_PACKET_TYPE_INVALID:
pkt->u.size = 0;
break;
case VMCI_TRANSPORT_PACKET_TYPE_REQUEST:
case VMCI_TRANSPORT_PACKET_TYPE_NEGOTIATE:
pkt->u.size = size;
break;
case VMCI_TRANSPORT_PACKET_TYPE_OFFER:
case VMCI_TRANSPORT_PACKET_TYPE_ATTACH:
pkt->u.handle = handle;
break;
case VMCI_TRANSPORT_PACKET_TYPE_WROTE:
case VMCI_TRANSPORT_PACKET_TYPE_READ:
case VMCI_TRANSPORT_PACKET_TYPE_RST:
pkt->u.size = 0;
break;
case VMCI_TRANSPORT_PACKET_TYPE_SHUTDOWN:
pkt->u.mode = mode;
break;
case VMCI_TRANSPORT_PACKET_TYPE_WAITING_READ:
case VMCI_TRANSPORT_PACKET_TYPE_WAITING_WRITE:
memcpy(&pkt->u.wait, wait, sizeof(pkt->u.wait));
break;
case VMCI_TRANSPORT_PACKET_TYPE_REQUEST2:
case VMCI_TRANSPORT_PACKET_TYPE_NEGOTIATE2:
pkt->u.size = size;
pkt->proto = proto;
break;
}
}
static inline void
vmci_transport_packet_get_addresses(struct vmci_transport_packet *pkt,
struct sockaddr_vm *local,
struct sockaddr_vm *remote)
{
vsock_addr_init(local, pkt->dg.dst.context, pkt->dst_port);
vsock_addr_init(remote, pkt->dg.src.context, pkt->src_port);
}
static int
__vmci_transport_send_control_pkt(struct vmci_transport_packet *pkt,
struct sockaddr_vm *src,
struct sockaddr_vm *dst,
enum vmci_transport_packet_type type,
u64 size,
u64 mode,
struct vmci_transport_waiting_info *wait,
u16 proto,
struct vmci_handle handle,
bool convert_error)
{
int err;
vmci_transport_packet_init(pkt, src, dst, type, size, mode, wait,
proto, handle);
err = vmci_datagram_send(&pkt->dg);
if (convert_error && (err < 0))
return vmci_transport_error_to_vsock_error(err);
return err;
}
static int
vmci_transport_reply_control_pkt_fast(struct vmci_transport_packet *pkt,
enum vmci_transport_packet_type type,
u64 size,
u64 mode,
struct vmci_transport_waiting_info *wait,
struct vmci_handle handle)
{
struct vmci_transport_packet reply;
struct sockaddr_vm src, dst;
if (pkt->type == VMCI_TRANSPORT_PACKET_TYPE_RST) {
return 0;
} else {
vmci_transport_packet_get_addresses(pkt, &src, &dst);
return __vmci_transport_send_control_pkt(&reply, &src, &dst,
type,
size, mode, wait,
VSOCK_PROTO_INVALID,
handle, true);
}
}
static int
vmci_transport_send_control_pkt_bh(struct sockaddr_vm *src,
struct sockaddr_vm *dst,
enum vmci_transport_packet_type type,
u64 size,
u64 mode,
struct vmci_transport_waiting_info *wait,
struct vmci_handle handle)
{
static struct vmci_transport_packet pkt;
return __vmci_transport_send_control_pkt(&pkt, src, dst, type,
size, mode, wait,
VSOCK_PROTO_INVALID, handle,
false);
}
static int
vmci_transport_send_control_pkt(struct sock *sk,
enum vmci_transport_packet_type type,
u64 size,
u64 mode,
struct vmci_transport_waiting_info *wait,
u16 proto,
struct vmci_handle handle)
{
struct vmci_transport_packet *pkt;
struct vsock_sock *vsk;
int err;
vsk = vsock_sk(sk);
if (!vsock_addr_bound(&vsk->local_addr))
return -EINVAL;
if (!vsock_addr_bound(&vsk->remote_addr))
return -EINVAL;
pkt = kmalloc(sizeof(*pkt), GFP_KERNEL);
if (!pkt)
return -ENOMEM;
err = __vmci_transport_send_control_pkt(pkt, &vsk->local_addr,
&vsk->remote_addr, type, size,
mode, wait, proto, handle,
true);
kfree(pkt);
return err;
}
static int vmci_transport_send_reset_bh(struct sockaddr_vm *dst,
struct sockaddr_vm *src,
struct vmci_transport_packet *pkt)
{
if (pkt->type == VMCI_TRANSPORT_PACKET_TYPE_RST)
return 0;
return vmci_transport_send_control_pkt_bh(
dst, src,
VMCI_TRANSPORT_PACKET_TYPE_RST, 0,
0, NULL, VMCI_INVALID_HANDLE);
}
static int vmci_transport_send_reset(struct sock *sk,
struct vmci_transport_packet *pkt)
{
if (pkt->type == VMCI_TRANSPORT_PACKET_TYPE_RST)
return 0;
return vmci_transport_send_control_pkt(sk,
VMCI_TRANSPORT_PACKET_TYPE_RST,
0, 0, NULL, VSOCK_PROTO_INVALID,
VMCI_INVALID_HANDLE);
}
static int vmci_transport_send_negotiate(struct sock *sk, size_t size)
{
return vmci_transport_send_control_pkt(
sk,
VMCI_TRANSPORT_PACKET_TYPE_NEGOTIATE,
size, 0, NULL,
VSOCK_PROTO_INVALID,
VMCI_INVALID_HANDLE);
}
static int vmci_transport_send_negotiate2(struct sock *sk, size_t size,
u16 version)
{
return vmci_transport_send_control_pkt(
sk,
VMCI_TRANSPORT_PACKET_TYPE_NEGOTIATE2,
size, 0, NULL, version,
VMCI_INVALID_HANDLE);
}
static int vmci_transport_send_qp_offer(struct sock *sk,
struct vmci_handle handle)
{
return vmci_transport_send_control_pkt(
sk, VMCI_TRANSPORT_PACKET_TYPE_OFFER, 0,
0, NULL,
VSOCK_PROTO_INVALID, handle);
}
static int vmci_transport_send_attach(struct sock *sk,
struct vmci_handle handle)
{
return vmci_transport_send_control_pkt(
sk, VMCI_TRANSPORT_PACKET_TYPE_ATTACH,
0, 0, NULL, VSOCK_PROTO_INVALID,
handle);
}
static int vmci_transport_reply_reset(struct vmci_transport_packet *pkt)
{
return vmci_transport_reply_control_pkt_fast(
pkt,
VMCI_TRANSPORT_PACKET_TYPE_RST,
0, 0, NULL,
VMCI_INVALID_HANDLE);
}
static int vmci_transport_send_invalid_bh(struct sockaddr_vm *dst,
struct sockaddr_vm *src)
{
return vmci_transport_send_control_pkt_bh(
dst, src,
VMCI_TRANSPORT_PACKET_TYPE_INVALID,
0, 0, NULL, VMCI_INVALID_HANDLE);
}
int vmci_transport_send_wrote_bh(struct sockaddr_vm *dst,
struct sockaddr_vm *src)
{
return vmci_transport_send_control_pkt_bh(
dst, src,
VMCI_TRANSPORT_PACKET_TYPE_WROTE, 0,
0, NULL, VMCI_INVALID_HANDLE);
}
int vmci_transport_send_read_bh(struct sockaddr_vm *dst,
struct sockaddr_vm *src)
{
return vmci_transport_send_control_pkt_bh(
dst, src,
VMCI_TRANSPORT_PACKET_TYPE_READ, 0,
0, NULL, VMCI_INVALID_HANDLE);
}
int vmci_transport_send_wrote(struct sock *sk)
{
return vmci_transport_send_control_pkt(
sk, VMCI_TRANSPORT_PACKET_TYPE_WROTE, 0,
0, NULL, VSOCK_PROTO_INVALID,
VMCI_INVALID_HANDLE);
}
int vmci_transport_send_read(struct sock *sk)
{
return vmci_transport_send_control_pkt(
sk, VMCI_TRANSPORT_PACKET_TYPE_READ, 0,
0, NULL, VSOCK_PROTO_INVALID,
VMCI_INVALID_HANDLE);
}
int vmci_transport_send_waiting_write(struct sock *sk,
struct vmci_transport_waiting_info *wait)
{
return vmci_transport_send_control_pkt(
sk, VMCI_TRANSPORT_PACKET_TYPE_WAITING_WRITE,
0, 0, wait, VSOCK_PROTO_INVALID,
VMCI_INVALID_HANDLE);
}
int vmci_transport_send_waiting_read(struct sock *sk,
struct vmci_transport_waiting_info *wait)
{
return vmci_transport_send_control_pkt(
sk, VMCI_TRANSPORT_PACKET_TYPE_WAITING_READ,
0, 0, wait, VSOCK_PROTO_INVALID,
VMCI_INVALID_HANDLE);
}
static int vmci_transport_shutdown(struct vsock_sock *vsk, int mode)
{
return vmci_transport_send_control_pkt(
&vsk->sk,
VMCI_TRANSPORT_PACKET_TYPE_SHUTDOWN,
0, mode, NULL,
VSOCK_PROTO_INVALID,
VMCI_INVALID_HANDLE);
}
static int vmci_transport_send_conn_request(struct sock *sk, size_t size)
{
return vmci_transport_send_control_pkt(sk,
VMCI_TRANSPORT_PACKET_TYPE_REQUEST,
size, 0, NULL,
VSOCK_PROTO_INVALID,
VMCI_INVALID_HANDLE);
}
static int vmci_transport_send_conn_request2(struct sock *sk, size_t size,
u16 version)
{
return vmci_transport_send_control_pkt(
sk, VMCI_TRANSPORT_PACKET_TYPE_REQUEST2,
size, 0, NULL, version,
VMCI_INVALID_HANDLE);
}
static struct sock *vmci_transport_get_pending(
struct sock *listener,
struct vmci_transport_packet *pkt)
{
struct vsock_sock *vlistener;
struct vsock_sock *vpending;
struct sock *pending;
struct sockaddr_vm src;
vsock_addr_init(&src, pkt->dg.src.context, pkt->src_port);
vlistener = vsock_sk(listener);
list_for_each_entry(vpending, &vlistener->pending_links,
pending_links) {
if (vsock_addr_equals_addr(&src, &vpending->remote_addr) &&
pkt->dst_port == vpending->local_addr.svm_port) {
pending = sk_vsock(vpending);
sock_hold(pending);
goto found;
}
}
pending = NULL;
found:
return pending;
}
static void vmci_transport_release_pending(struct sock *pending)
{
sock_put(pending);
}
static bool vmci_transport_is_trusted(struct vsock_sock *vsock, u32 peer_cid)
{
return vsock->trusted ||
vmci_is_context_owner(peer_cid, vsock->owner->uid);
}
static bool vmci_transport_allow_dgram(struct vsock_sock *vsock, u32 peer_cid)
{
if (VMADDR_CID_HYPERVISOR == peer_cid)
return true;
if (vsock->cached_peer != peer_cid) {
vsock->cached_peer = peer_cid;
if (!vmci_transport_is_trusted(vsock, peer_cid) &&
(vmci_context_get_priv_flags(peer_cid) &
VMCI_PRIVILEGE_FLAG_RESTRICTED)) {
vsock->cached_peer_allow_dgram = false;
} else {
vsock->cached_peer_allow_dgram = true;
}
}
return vsock->cached_peer_allow_dgram;
}
static int
vmci_transport_queue_pair_alloc(struct vmci_qp **qpair,
struct vmci_handle *handle,
u64 produce_size,
u64 consume_size,
u32 peer, u32 flags, bool trusted)
{
int err = 0;
if (trusted) {
err = vmci_qpair_alloc(qpair, handle, produce_size,
consume_size,
peer, flags,
VMCI_PRIVILEGE_FLAG_TRUSTED);
if (err != VMCI_ERROR_NO_ACCESS)
goto out;
}
err = vmci_qpair_alloc(qpair, handle, produce_size, consume_size,
peer, flags, VMCI_NO_PRIVILEGE_FLAGS);
out:
if (err < 0) {
pr_err("Could not attach to queue pair with %d\n",
err);
err = vmci_transport_error_to_vsock_error(err);
}
return err;
}
static int
vmci_transport_datagram_create_hnd(u32 resource_id,
u32 flags,
vmci_datagram_recv_cb recv_cb,
void *client_data,
struct vmci_handle *out_handle)
{
int err = 0;
err = vmci_datagram_create_handle_priv(resource_id, flags,
VMCI_PRIVILEGE_FLAG_TRUSTED,
recv_cb,
client_data, out_handle);
if (err == VMCI_ERROR_NO_ACCESS)
err = vmci_datagram_create_handle(resource_id, flags,
recv_cb, client_data,
out_handle);
return err;
}
static int vmci_transport_recv_dgram_cb(void *data, struct vmci_datagram *dg)
{
struct sock *sk;
size_t size;
struct sk_buff *skb;
struct vsock_sock *vsk;
sk = (struct sock *)data;
vsk = vsock_sk(sk);
if (!vmci_transport_allow_dgram(vsk, dg->src.context))
return VMCI_ERROR_NO_ACCESS;
size = VMCI_DG_SIZE(dg);
skb = alloc_skb(size, GFP_ATOMIC);
if (!skb)
return VMCI_ERROR_NO_MEM;
sock_hold(sk);
skb_put(skb, size);
memcpy(skb->data, dg, size);
sk_receive_skb(sk, skb, 0);
return VMCI_SUCCESS;
}
static bool vmci_transport_stream_allow(u32 cid, u32 port)
{
static const u32 non_socket_contexts[] = {
VMADDR_CID_RESERVED,
};
int i;
BUILD_BUG_ON(sizeof(cid) != sizeof(*non_socket_contexts));
for (i = 0; i < ARRAY_SIZE(non_socket_contexts); i++) {
if (cid == non_socket_contexts[i])
return false;
}
return true;
}
static int vmci_transport_recv_stream_cb(void *data, struct vmci_datagram *dg)
{
struct sock *sk;
struct sockaddr_vm dst;
struct sockaddr_vm src;
struct vmci_transport_packet *pkt;
struct vsock_sock *vsk;
bool bh_process_pkt;
int err;
sk = NULL;
err = VMCI_SUCCESS;
bh_process_pkt = false;
if (!vmci_transport_stream_allow(dg->src.context, -1)
|| vmci_transport_peer_rid(dg->src.context) != dg->src.resource)
return VMCI_ERROR_NO_ACCESS;
if (VMCI_DG_SIZE(dg) < sizeof(*pkt))
return VMCI_ERROR_INVALID_ARGS;
pkt = (struct vmci_transport_packet *)dg;
vsock_addr_init(&src, pkt->dg.src.context, pkt->src_port);
vsock_addr_init(&dst, pkt->dg.dst.context, pkt->dst_port);
sk = vsock_find_connected_socket(&src, &dst);
if (!sk) {
sk = vsock_find_bound_socket(&dst);
if (!sk) {
if (vmci_transport_send_reset_bh(&dst, &src, pkt) < 0)
pr_err("unable to send reset\n");
err = VMCI_ERROR_NOT_FOUND;
goto out;
}
}
if (pkt->type >= VMCI_TRANSPORT_PACKET_TYPE_MAX) {
vmci_transport_send_invalid_bh(&dst, &src);
err = VMCI_ERROR_INVALID_ARGS;
goto out;
}
vsk = vsock_sk(sk);
if (!vmci_transport_allow_dgram(vsk, pkt->dg.src.context)) {
err = VMCI_ERROR_NO_ACCESS;
goto out;
}
bh_lock_sock(sk);
if (!sock_owned_by_user(sk)) {
vsk->local_addr.svm_cid = dst.svm_cid;
if (sk->sk_state == SS_CONNECTED)
vmci_trans(vsk)->notify_ops->handle_notify_pkt(
sk, pkt, true, &dst, &src,
&bh_process_pkt);
}
bh_unlock_sock(sk);
if (!bh_process_pkt) {
struct vmci_transport_recv_pkt_info *recv_pkt_info;
recv_pkt_info = kmalloc(sizeof(*recv_pkt_info), GFP_ATOMIC);
if (!recv_pkt_info) {
if (vmci_transport_send_reset_bh(&dst, &src, pkt) < 0)
pr_err("unable to send reset\n");
err = VMCI_ERROR_NO_MEM;
goto out;
}
recv_pkt_info->sk = sk;
memcpy(&recv_pkt_info->pkt, pkt, sizeof(recv_pkt_info->pkt));
INIT_WORK(&recv_pkt_info->work, vmci_transport_recv_pkt_work);
schedule_work(&recv_pkt_info->work);
sk = NULL;
}
out:
if (sk)
sock_put(sk);
return err;
}
static void vmci_transport_peer_attach_cb(u32 sub_id,
const struct vmci_event_data *e_data,
void *client_data)
{
struct sock *sk = client_data;
const struct vmci_event_payload_qp *e_payload;
struct vsock_sock *vsk;
e_payload = vmci_event_data_const_payload(e_data);
vsk = vsock_sk(sk);
local_bh_disable();
bh_lock_sock(sk);
if (vmci_handle_is_equal(vmci_trans(vsk)->qp_handle,
e_payload->handle)) {
goto out;
}
out:
bh_unlock_sock(sk);
local_bh_enable();
}
static void vmci_transport_handle_detach(struct sock *sk)
{
struct vsock_sock *vsk;
vsk = vsock_sk(sk);
if (!vmci_handle_is_invalid(vmci_trans(vsk)->qp_handle)) {
sock_set_flag(sk, SOCK_DONE);
vsk->peer_shutdown = SHUTDOWN_MASK;
if (vsock_stream_has_data(vsk) <= 0) {
if (sk->sk_state == SS_CONNECTING) {
sk->sk_state = SS_UNCONNECTED;
sk->sk_err = ECONNRESET;
sk->sk_error_report(sk);
return;
}
sk->sk_state = SS_UNCONNECTED;
}
sk->sk_state_change(sk);
}
}
static void vmci_transport_peer_detach_cb(u32 sub_id,
const struct vmci_event_data *e_data,
void *client_data)
{
struct sock *sk = client_data;
const struct vmci_event_payload_qp *e_payload;
struct vsock_sock *vsk;
e_payload = vmci_event_data_const_payload(e_data);
vsk = vsock_sk(sk);
if (vmci_handle_is_invalid(e_payload->handle))
return;
local_bh_disable();
bh_lock_sock(sk);
if (vmci_handle_is_equal(vmci_trans(vsk)->qp_handle,
e_payload->handle))
vmci_transport_handle_detach(sk);
bh_unlock_sock(sk);
local_bh_enable();
}
static void vmci_transport_qp_resumed_cb(u32 sub_id,
const struct vmci_event_data *e_data,
void *client_data)
{
vsock_for_each_connected_socket(vmci_transport_handle_detach);
}
static void vmci_transport_recv_pkt_work(struct work_struct *work)
{
struct vmci_transport_recv_pkt_info *recv_pkt_info;
struct vmci_transport_packet *pkt;
struct sock *sk;
recv_pkt_info =
container_of(work, struct vmci_transport_recv_pkt_info, work);
sk = recv_pkt_info->sk;
pkt = &recv_pkt_info->pkt;
lock_sock(sk);
vsock_sk(sk)->local_addr.svm_cid = pkt->dg.dst.context;
switch (sk->sk_state) {
case SS_LISTEN:
vmci_transport_recv_listen(sk, pkt);
break;
case SS_CONNECTING:
vmci_transport_recv_connecting_client(sk, pkt);
break;
case SS_CONNECTED:
vmci_transport_recv_connected(sk, pkt);
break;
default:
vmci_transport_send_reset(sk, pkt);
break;
}
release_sock(sk);
kfree(recv_pkt_info);
sock_put(sk);
}
static int vmci_transport_recv_listen(struct sock *sk,
struct vmci_transport_packet *pkt)
{
struct sock *pending;
struct vsock_sock *vpending;
int err;
u64 qp_size;
bool old_request = false;
bool old_pkt_proto = false;
err = 0;
pending = vmci_transport_get_pending(sk, pkt);
if (pending) {
lock_sock(pending);
vsock_sk(pending)->local_addr.svm_cid = pkt->dg.dst.context;
switch (pending->sk_state) {
case SS_CONNECTING:
err = vmci_transport_recv_connecting_server(sk,
pending,
pkt);
break;
default:
vmci_transport_send_reset(pending, pkt);
err = -EINVAL;
}
if (err < 0)
vsock_remove_pending(sk, pending);
release_sock(pending);
vmci_transport_release_pending(pending);
return err;
}
if (!(pkt->type == VMCI_TRANSPORT_PACKET_TYPE_REQUEST ||
pkt->type == VMCI_TRANSPORT_PACKET_TYPE_REQUEST2)) {
vmci_transport_reply_reset(pkt);
return -EINVAL;
}
if (pkt->u.size == 0) {
vmci_transport_reply_reset(pkt);
return -EINVAL;
}
if (sk->sk_ack_backlog >= sk->sk_max_ack_backlog) {
vmci_transport_reply_reset(pkt);
return -ECONNREFUSED;
}
pending = __vsock_create(sock_net(sk), NULL, sk, GFP_KERNEL,
sk->sk_type);
if (!pending) {
vmci_transport_send_reset(sk, pkt);
return -ENOMEM;
}
vpending = vsock_sk(pending);
vsock_addr_init(&vpending->local_addr, pkt->dg.dst.context,
pkt->dst_port);
vsock_addr_init(&vpending->remote_addr, pkt->dg.src.context,
pkt->src_port);
if (pkt->u.size >= vmci_trans(vpending)->queue_pair_min_size &&
pkt->u.size <= vmci_trans(vpending)->queue_pair_max_size) {
qp_size = pkt->u.size;
} else {
qp_size = vmci_trans(vpending)->queue_pair_size;
}
if (vmci_transport_old_proto_override(&old_pkt_proto)) {
old_request = old_pkt_proto;
} else {
if (pkt->type == VMCI_TRANSPORT_PACKET_TYPE_REQUEST)
old_request = true;
else if (pkt->type == VMCI_TRANSPORT_PACKET_TYPE_REQUEST2)
old_request = false;
}
if (old_request) {
u16 version = VSOCK_PROTO_INVALID;
if (vmci_transport_proto_to_notify_struct(
pending, &version, true))
err = vmci_transport_send_negotiate(pending, qp_size);
else
err = -EINVAL;
} else {
int proto_int = pkt->proto;
int pos;
u16 active_proto_version = 0;
proto_int &= vmci_transport_new_proto_supported_versions();
pos = fls(proto_int);
if (pos) {
active_proto_version = (1 << (pos - 1));
if (vmci_transport_proto_to_notify_struct(
pending, &active_proto_version, false))
err = vmci_transport_send_negotiate2(pending,
qp_size,
active_proto_version);
else
err = -EINVAL;
} else {
err = -EINVAL;
}
}
if (err < 0) {
vmci_transport_send_reset(sk, pkt);
sock_put(pending);
err = vmci_transport_error_to_vsock_error(err);
goto out;
}
vsock_add_pending(sk, pending);
sk->sk_ack_backlog++;
pending->sk_state = SS_CONNECTING;
vmci_trans(vpending)->produce_size =
vmci_trans(vpending)->consume_size = qp_size;
vmci_trans(vpending)->queue_pair_size = qp_size;
vmci_trans(vpending)->notify_ops->process_request(pending);
vpending->listener = sk;
sock_hold(sk);
sock_hold(pending);
INIT_DELAYED_WORK(&vpending->dwork, vsock_pending_work);
schedule_delayed_work(&vpending->dwork, HZ);
out:
return err;
}
static int
vmci_transport_recv_connecting_server(struct sock *listener,
struct sock *pending,
struct vmci_transport_packet *pkt)
{
struct vsock_sock *vpending;
struct vmci_handle handle;
struct vmci_qp *qpair;
bool is_local;
u32 flags;
u32 detach_sub_id;
int err;
int skerr;
vpending = vsock_sk(pending);
detach_sub_id = VMCI_INVALID_ID;
switch (pkt->type) {
case VMCI_TRANSPORT_PACKET_TYPE_OFFER:
if (vmci_handle_is_invalid(pkt->u.handle)) {
vmci_transport_send_reset(pending, pkt);
skerr = EPROTO;
err = -EINVAL;
goto destroy;
}
break;
default:
vmci_transport_send_reset(pending, pkt);
skerr = EPROTO;
err = pkt->type == VMCI_TRANSPORT_PACKET_TYPE_RST ? 0 : -EINVAL;
goto destroy;
}
err = vmci_event_subscribe(VMCI_EVENT_QP_PEER_DETACH,
vmci_transport_peer_detach_cb,
pending, &detach_sub_id);
if (err < VMCI_SUCCESS) {
vmci_transport_send_reset(pending, pkt);
err = vmci_transport_error_to_vsock_error(err);
skerr = -err;
goto destroy;
}
vmci_trans(vpending)->detach_sub_id = detach_sub_id;
handle = pkt->u.handle;
is_local =
vpending->remote_addr.svm_cid == vpending->local_addr.svm_cid;
flags = VMCI_QPFLAG_ATTACH_ONLY;
flags |= is_local ? VMCI_QPFLAG_LOCAL : 0;
err = vmci_transport_queue_pair_alloc(
&qpair,
&handle,
vmci_trans(vpending)->produce_size,
vmci_trans(vpending)->consume_size,
pkt->dg.src.context,
flags,
vmci_transport_is_trusted(
vpending,
vpending->remote_addr.svm_cid));
if (err < 0) {
vmci_transport_send_reset(pending, pkt);
skerr = -err;
goto destroy;
}
vmci_trans(vpending)->qp_handle = handle;
vmci_trans(vpending)->qpair = qpair;
pending->sk_state = SS_CONNECTED;
vsock_insert_connected(vpending);
err = vmci_transport_send_attach(pending, handle);
if (err < 0) {
vsock_remove_connected(vpending);
pr_err("Could not send attach\n");
vmci_transport_send_reset(pending, pkt);
err = vmci_transport_error_to_vsock_error(err);
skerr = -err;
goto destroy;
}
vsock_remove_pending(listener, pending);
vsock_enqueue_accept(listener, pending);
listener->sk_state_change(listener);
return 0;
destroy:
pending->sk_err = skerr;
pending->sk_state = SS_UNCONNECTED;
sock_put(pending);
return err;
}
static int
vmci_transport_recv_connecting_client(struct sock *sk,
struct vmci_transport_packet *pkt)
{
struct vsock_sock *vsk;
int err;
int skerr;
vsk = vsock_sk(sk);
switch (pkt->type) {
case VMCI_TRANSPORT_PACKET_TYPE_ATTACH:
if (vmci_handle_is_invalid(pkt->u.handle) ||
!vmci_handle_is_equal(pkt->u.handle,
vmci_trans(vsk)->qp_handle)) {
skerr = EPROTO;
err = -EINVAL;
goto destroy;
}
sk->sk_state = SS_CONNECTED;
sk->sk_socket->state = SS_CONNECTED;
vsock_insert_connected(vsk);
sk->sk_state_change(sk);
break;
case VMCI_TRANSPORT_PACKET_TYPE_NEGOTIATE:
case VMCI_TRANSPORT_PACKET_TYPE_NEGOTIATE2:
if (pkt->u.size == 0
|| pkt->dg.src.context != vsk->remote_addr.svm_cid
|| pkt->src_port != vsk->remote_addr.svm_port
|| !vmci_handle_is_invalid(vmci_trans(vsk)->qp_handle)
|| vmci_trans(vsk)->qpair
|| vmci_trans(vsk)->produce_size != 0
|| vmci_trans(vsk)->consume_size != 0
|| vmci_trans(vsk)->attach_sub_id != VMCI_INVALID_ID
|| vmci_trans(vsk)->detach_sub_id != VMCI_INVALID_ID) {
skerr = EPROTO;
err = -EINVAL;
goto destroy;
}
err = vmci_transport_recv_connecting_client_negotiate(sk, pkt);
if (err) {
skerr = -err;
goto destroy;
}
break;
case VMCI_TRANSPORT_PACKET_TYPE_INVALID:
err = vmci_transport_recv_connecting_client_invalid(sk, pkt);
if (err) {
skerr = -err;
goto destroy;
}
break;
case VMCI_TRANSPORT_PACKET_TYPE_RST:
if (vsk->ignore_connecting_rst) {
vsk->ignore_connecting_rst = false;
} else {
skerr = ECONNRESET;
err = 0;
goto destroy;
}
break;
default:
skerr = EPROTO;
err = -EINVAL;
goto destroy;
}
return 0;
destroy:
vmci_transport_send_reset(sk, pkt);
sk->sk_state = SS_UNCONNECTED;
sk->sk_err = skerr;
sk->sk_error_report(sk);
return err;
}
static int vmci_transport_recv_connecting_client_negotiate(
struct sock *sk,
struct vmci_transport_packet *pkt)
{
int err;
struct vsock_sock *vsk;
struct vmci_handle handle;
struct vmci_qp *qpair;
u32 attach_sub_id;
u32 detach_sub_id;
bool is_local;
u32 flags;
bool old_proto = true;
bool old_pkt_proto;
u16 version;
vsk = vsock_sk(sk);
handle = VMCI_INVALID_HANDLE;
attach_sub_id = VMCI_INVALID_ID;
detach_sub_id = VMCI_INVALID_ID;
vsk->sent_request = false;
vsk->ignore_connecting_rst = false;
if (pkt->u.size < vmci_trans(vsk)->queue_pair_min_size ||
pkt->u.size > vmci_trans(vsk)->queue_pair_max_size) {
err = -EINVAL;
goto destroy;
}
if (vsk->local_addr.svm_cid == VMADDR_CID_ANY)
vsk->local_addr.svm_cid = pkt->dg.dst.context;
if (vmci_transport_old_proto_override(&old_pkt_proto)) {
old_proto = old_pkt_proto;
} else {
if (pkt->type == VMCI_TRANSPORT_PACKET_TYPE_NEGOTIATE)
old_proto = true;
else if (pkt->type == VMCI_TRANSPORT_PACKET_TYPE_NEGOTIATE2)
old_proto = false;
}
if (old_proto)
version = VSOCK_PROTO_INVALID;
else
version = pkt->proto;
if (!vmci_transport_proto_to_notify_struct(sk, &version, old_proto)) {
err = -EINVAL;
goto destroy;
}
err = vmci_event_subscribe(VMCI_EVENT_QP_PEER_ATTACH,
vmci_transport_peer_attach_cb,
sk, &attach_sub_id);
if (err < VMCI_SUCCESS) {
err = vmci_transport_error_to_vsock_error(err);
goto destroy;
}
err = vmci_event_subscribe(VMCI_EVENT_QP_PEER_DETACH,
vmci_transport_peer_detach_cb,
sk, &detach_sub_id);
if (err < VMCI_SUCCESS) {
err = vmci_transport_error_to_vsock_error(err);
goto destroy;
}
handle = VMCI_INVALID_HANDLE;
is_local = vsk->remote_addr.svm_cid == vsk->local_addr.svm_cid;
flags = is_local ? VMCI_QPFLAG_LOCAL : 0;
err = vmci_transport_queue_pair_alloc(&qpair,
&handle,
pkt->u.size,
pkt->u.size,
vsk->remote_addr.svm_cid,
flags,
vmci_transport_is_trusted(
vsk,
vsk->
remote_addr.svm_cid));
if (err < 0)
goto destroy;
err = vmci_transport_send_qp_offer(sk, handle);
if (err < 0) {
err = vmci_transport_error_to_vsock_error(err);
goto destroy;
}
vmci_trans(vsk)->qp_handle = handle;
vmci_trans(vsk)->qpair = qpair;
vmci_trans(vsk)->produce_size = vmci_trans(vsk)->consume_size =
pkt->u.size;
vmci_trans(vsk)->attach_sub_id = attach_sub_id;
vmci_trans(vsk)->detach_sub_id = detach_sub_id;
vmci_trans(vsk)->notify_ops->process_negotiate(sk);
return 0;
destroy:
if (attach_sub_id != VMCI_INVALID_ID)
vmci_event_unsubscribe(attach_sub_id);
if (detach_sub_id != VMCI_INVALID_ID)
vmci_event_unsubscribe(detach_sub_id);
if (!vmci_handle_is_invalid(handle))
vmci_qpair_detach(&qpair);
return err;
}
static int
vmci_transport_recv_connecting_client_invalid(struct sock *sk,
struct vmci_transport_packet *pkt)
{
int err = 0;
struct vsock_sock *vsk = vsock_sk(sk);
if (vsk->sent_request) {
vsk->sent_request = false;
vsk->ignore_connecting_rst = true;
err = vmci_transport_send_conn_request(
sk, vmci_trans(vsk)->queue_pair_size);
if (err < 0)
err = vmci_transport_error_to_vsock_error(err);
else
err = 0;
}
return err;
}
static int vmci_transport_recv_connected(struct sock *sk,
struct vmci_transport_packet *pkt)
{
struct vsock_sock *vsk;
bool pkt_processed = false;
switch (pkt->type) {
case VMCI_TRANSPORT_PACKET_TYPE_SHUTDOWN:
if (pkt->u.mode) {
vsk = vsock_sk(sk);
vsk->peer_shutdown |= pkt->u.mode;
sk->sk_state_change(sk);
}
break;
case VMCI_TRANSPORT_PACKET_TYPE_RST:
vsk = vsock_sk(sk);
sock_set_flag(sk, SOCK_DONE);
vsk->peer_shutdown = SHUTDOWN_MASK;
if (vsock_stream_has_data(vsk) <= 0)
sk->sk_state = SS_DISCONNECTING;
sk->sk_state_change(sk);
break;
default:
vsk = vsock_sk(sk);
vmci_trans(vsk)->notify_ops->handle_notify_pkt(
sk, pkt, false, NULL, NULL,
&pkt_processed);
if (!pkt_processed)
return -EINVAL;
break;
}
return 0;
}
static int vmci_transport_socket_init(struct vsock_sock *vsk,
struct vsock_sock *psk)
{
vsk->trans = kmalloc(sizeof(struct vmci_transport), GFP_KERNEL);
if (!vsk->trans)
return -ENOMEM;
vmci_trans(vsk)->dg_handle = VMCI_INVALID_HANDLE;
vmci_trans(vsk)->qp_handle = VMCI_INVALID_HANDLE;
vmci_trans(vsk)->qpair = NULL;
vmci_trans(vsk)->produce_size = vmci_trans(vsk)->consume_size = 0;
vmci_trans(vsk)->attach_sub_id = vmci_trans(vsk)->detach_sub_id =
VMCI_INVALID_ID;
vmci_trans(vsk)->notify_ops = NULL;
if (psk) {
vmci_trans(vsk)->queue_pair_size =
vmci_trans(psk)->queue_pair_size;
vmci_trans(vsk)->queue_pair_min_size =
vmci_trans(psk)->queue_pair_min_size;
vmci_trans(vsk)->queue_pair_max_size =
vmci_trans(psk)->queue_pair_max_size;
} else {
vmci_trans(vsk)->queue_pair_size =
VMCI_TRANSPORT_DEFAULT_QP_SIZE;
vmci_trans(vsk)->queue_pair_min_size =
VMCI_TRANSPORT_DEFAULT_QP_SIZE_MIN;
vmci_trans(vsk)->queue_pair_max_size =
VMCI_TRANSPORT_DEFAULT_QP_SIZE_MAX;
}
return 0;
}
static void vmci_transport_destruct(struct vsock_sock *vsk)
{
if (vmci_trans(vsk)->attach_sub_id != VMCI_INVALID_ID) {
vmci_event_unsubscribe(vmci_trans(vsk)->attach_sub_id);
vmci_trans(vsk)->attach_sub_id = VMCI_INVALID_ID;
}
if (vmci_trans(vsk)->detach_sub_id != VMCI_INVALID_ID) {
vmci_event_unsubscribe(vmci_trans(vsk)->detach_sub_id);
vmci_trans(vsk)->detach_sub_id = VMCI_INVALID_ID;
}
if (!vmci_handle_is_invalid(vmci_trans(vsk)->qp_handle)) {
vmci_qpair_detach(&vmci_trans(vsk)->qpair);
vmci_trans(vsk)->qp_handle = VMCI_INVALID_HANDLE;
vmci_trans(vsk)->produce_size = 0;
vmci_trans(vsk)->consume_size = 0;
}
if (vmci_trans(vsk)->notify_ops)
vmci_trans(vsk)->notify_ops->socket_destruct(vsk);
kfree(vsk->trans);
vsk->trans = NULL;
}
static void vmci_transport_release(struct vsock_sock *vsk)
{
if (!vmci_handle_is_invalid(vmci_trans(vsk)->dg_handle)) {
vmci_datagram_destroy_handle(vmci_trans(vsk)->dg_handle);
vmci_trans(vsk)->dg_handle = VMCI_INVALID_HANDLE;
}
}
static int vmci_transport_dgram_bind(struct vsock_sock *vsk,
struct sockaddr_vm *addr)
{
u32 port;
u32 flags;
int err;
port = addr->svm_port == VMADDR_PORT_ANY ?
VMCI_INVALID_ID : addr->svm_port;
if (port <= LAST_RESERVED_PORT && !capable(CAP_NET_BIND_SERVICE))
return -EACCES;
flags = addr->svm_cid == VMADDR_CID_ANY ?
VMCI_FLAG_ANYCID_DG_HND : 0;
err = vmci_transport_datagram_create_hnd(port, flags,
vmci_transport_recv_dgram_cb,
&vsk->sk,
&vmci_trans(vsk)->dg_handle);
if (err < VMCI_SUCCESS)
return vmci_transport_error_to_vsock_error(err);
vsock_addr_init(&vsk->local_addr, addr->svm_cid,
vmci_trans(vsk)->dg_handle.resource);
return 0;
}
static int vmci_transport_dgram_enqueue(
struct vsock_sock *vsk,
struct sockaddr_vm *remote_addr,
struct msghdr *msg,
size_t len)
{
int err;
struct vmci_datagram *dg;
if (len > VMCI_MAX_DG_PAYLOAD_SIZE)
return -EMSGSIZE;
if (!vmci_transport_allow_dgram(vsk, remote_addr->svm_cid))
return -EPERM;
dg = kmalloc(len + sizeof(*dg), GFP_KERNEL);
if (!dg)
return -ENOMEM;
memcpy_from_msg(VMCI_DG_PAYLOAD(dg), msg, len);
dg->dst = vmci_make_handle(remote_addr->svm_cid,
remote_addr->svm_port);
dg->src = vmci_make_handle(vsk->local_addr.svm_cid,
vsk->local_addr.svm_port);
dg->payload_size = len;
err = vmci_datagram_send(dg);
kfree(dg);
if (err < 0)
return vmci_transport_error_to_vsock_error(err);
return err - sizeof(*dg);
}
static int vmci_transport_dgram_dequeue(struct vsock_sock *vsk,
struct msghdr *msg, size_t len,
int flags)
{
int err;
int noblock;
struct vmci_datagram *dg;
size_t payload_len;
struct sk_buff *skb;
noblock = flags & MSG_DONTWAIT;
if (flags & MSG_OOB || flags & MSG_ERRQUEUE)
return -EOPNOTSUPP;
err = 0;
skb = skb_recv_datagram(&vsk->sk, flags, noblock, &err);
if (err)
return err;
if (!skb)
return -EAGAIN;
dg = (struct vmci_datagram *)skb->data;
if (!dg)
goto out;
payload_len = dg->payload_size;
if (payload_len != skb->len - sizeof(*dg)) {
err = -EINVAL;
goto out;
}
if (payload_len > len) {
payload_len = len;
msg->msg_flags |= MSG_TRUNC;
}
err = skb_copy_datagram_msg(skb, sizeof(*dg), msg, payload_len);
if (err)
goto out;
if (msg->msg_name) {
DECLARE_SOCKADDR(struct sockaddr_vm *, vm_addr, msg->msg_name);
vsock_addr_init(vm_addr, dg->src.context, dg->src.resource);
msg->msg_namelen = sizeof(*vm_addr);
}
err = payload_len;
out:
skb_free_datagram(&vsk->sk, skb);
return err;
}
static bool vmci_transport_dgram_allow(u32 cid, u32 port)
{
if (cid == VMADDR_CID_HYPERVISOR) {
return port == VMCI_UNITY_PBRPC_REGISTER;
}
return true;
}
static int vmci_transport_connect(struct vsock_sock *vsk)
{
int err;
bool old_pkt_proto = false;
struct sock *sk = &vsk->sk;
if (vmci_transport_old_proto_override(&old_pkt_proto) &&
old_pkt_proto) {
err = vmci_transport_send_conn_request(
sk, vmci_trans(vsk)->queue_pair_size);
if (err < 0) {
sk->sk_state = SS_UNCONNECTED;
return err;
}
} else {
int supported_proto_versions =
vmci_transport_new_proto_supported_versions();
err = vmci_transport_send_conn_request2(
sk, vmci_trans(vsk)->queue_pair_size,
supported_proto_versions);
if (err < 0) {
sk->sk_state = SS_UNCONNECTED;
return err;
}
vsk->sent_request = true;
}
return err;
}
static ssize_t vmci_transport_stream_dequeue(
struct vsock_sock *vsk,
struct msghdr *msg,
size_t len,
int flags)
{
if (flags & MSG_PEEK)
return vmci_qpair_peekv(vmci_trans(vsk)->qpair, msg, len, 0);
else
return vmci_qpair_dequev(vmci_trans(vsk)->qpair, msg, len, 0);
}
static ssize_t vmci_transport_stream_enqueue(
struct vsock_sock *vsk,
struct msghdr *msg,
size_t len)
{
return vmci_qpair_enquev(vmci_trans(vsk)->qpair, msg, len, 0);
}
static s64 vmci_transport_stream_has_data(struct vsock_sock *vsk)
{
return vmci_qpair_consume_buf_ready(vmci_trans(vsk)->qpair);
}
static s64 vmci_transport_stream_has_space(struct vsock_sock *vsk)
{
return vmci_qpair_produce_free_space(vmci_trans(vsk)->qpair);
}
static u64 vmci_transport_stream_rcvhiwat(struct vsock_sock *vsk)
{
return vmci_trans(vsk)->consume_size;
}
static bool vmci_transport_stream_is_active(struct vsock_sock *vsk)
{
return !vmci_handle_is_invalid(vmci_trans(vsk)->qp_handle);
}
static u64 vmci_transport_get_buffer_size(struct vsock_sock *vsk)
{
return vmci_trans(vsk)->queue_pair_size;
}
static u64 vmci_transport_get_min_buffer_size(struct vsock_sock *vsk)
{
return vmci_trans(vsk)->queue_pair_min_size;
}
static u64 vmci_transport_get_max_buffer_size(struct vsock_sock *vsk)
{
return vmci_trans(vsk)->queue_pair_max_size;
}
static void vmci_transport_set_buffer_size(struct vsock_sock *vsk, u64 val)
{
if (val < vmci_trans(vsk)->queue_pair_min_size)
vmci_trans(vsk)->queue_pair_min_size = val;
if (val > vmci_trans(vsk)->queue_pair_max_size)
vmci_trans(vsk)->queue_pair_max_size = val;
vmci_trans(vsk)->queue_pair_size = val;
}
static void vmci_transport_set_min_buffer_size(struct vsock_sock *vsk,
u64 val)
{
if (val > vmci_trans(vsk)->queue_pair_size)
vmci_trans(vsk)->queue_pair_size = val;
vmci_trans(vsk)->queue_pair_min_size = val;
}
static void vmci_transport_set_max_buffer_size(struct vsock_sock *vsk,
u64 val)
{
if (val < vmci_trans(vsk)->queue_pair_size)
vmci_trans(vsk)->queue_pair_size = val;
vmci_trans(vsk)->queue_pair_max_size = val;
}
static int vmci_transport_notify_poll_in(
struct vsock_sock *vsk,
size_t target,
bool *data_ready_now)
{
return vmci_trans(vsk)->notify_ops->poll_in(
&vsk->sk, target, data_ready_now);
}
static int vmci_transport_notify_poll_out(
struct vsock_sock *vsk,
size_t target,
bool *space_available_now)
{
return vmci_trans(vsk)->notify_ops->poll_out(
&vsk->sk, target, space_available_now);
}
static int vmci_transport_notify_recv_init(
struct vsock_sock *vsk,
size_t target,
struct vsock_transport_recv_notify_data *data)
{
return vmci_trans(vsk)->notify_ops->recv_init(
&vsk->sk, target,
(struct vmci_transport_recv_notify_data *)data);
}
static int vmci_transport_notify_recv_pre_block(
struct vsock_sock *vsk,
size_t target,
struct vsock_transport_recv_notify_data *data)
{
return vmci_trans(vsk)->notify_ops->recv_pre_block(
&vsk->sk, target,
(struct vmci_transport_recv_notify_data *)data);
}
static int vmci_transport_notify_recv_pre_dequeue(
struct vsock_sock *vsk,
size_t target,
struct vsock_transport_recv_notify_data *data)
{
return vmci_trans(vsk)->notify_ops->recv_pre_dequeue(
&vsk->sk, target,
(struct vmci_transport_recv_notify_data *)data);
}
static int vmci_transport_notify_recv_post_dequeue(
struct vsock_sock *vsk,
size_t target,
ssize_t copied,
bool data_read,
struct vsock_transport_recv_notify_data *data)
{
return vmci_trans(vsk)->notify_ops->recv_post_dequeue(
&vsk->sk, target, copied, data_read,
(struct vmci_transport_recv_notify_data *)data);
}
static int vmci_transport_notify_send_init(
struct vsock_sock *vsk,
struct vsock_transport_send_notify_data *data)
{
return vmci_trans(vsk)->notify_ops->send_init(
&vsk->sk,
(struct vmci_transport_send_notify_data *)data);
}
static int vmci_transport_notify_send_pre_block(
struct vsock_sock *vsk,
struct vsock_transport_send_notify_data *data)
{
return vmci_trans(vsk)->notify_ops->send_pre_block(
&vsk->sk,
(struct vmci_transport_send_notify_data *)data);
}
static int vmci_transport_notify_send_pre_enqueue(
struct vsock_sock *vsk,
struct vsock_transport_send_notify_data *data)
{
return vmci_trans(vsk)->notify_ops->send_pre_enqueue(
&vsk->sk,
(struct vmci_transport_send_notify_data *)data);
}
static int vmci_transport_notify_send_post_enqueue(
struct vsock_sock *vsk,
ssize_t written,
struct vsock_transport_send_notify_data *data)
{
return vmci_trans(vsk)->notify_ops->send_post_enqueue(
&vsk->sk, written,
(struct vmci_transport_send_notify_data *)data);
}
static bool vmci_transport_old_proto_override(bool *old_pkt_proto)
{
if (PROTOCOL_OVERRIDE != -1) {
if (PROTOCOL_OVERRIDE == 0)
*old_pkt_proto = true;
else
*old_pkt_proto = false;
pr_info("Proto override in use\n");
return true;
}
return false;
}
static bool vmci_transport_proto_to_notify_struct(struct sock *sk,
u16 *proto,
bool old_pkt_proto)
{
struct vsock_sock *vsk = vsock_sk(sk);
if (old_pkt_proto) {
if (*proto != VSOCK_PROTO_INVALID) {
pr_err("Can't set both an old and new protocol\n");
return false;
}
vmci_trans(vsk)->notify_ops = &vmci_transport_notify_pkt_ops;
goto exit;
}
switch (*proto) {
case VSOCK_PROTO_PKT_ON_NOTIFY:
vmci_trans(vsk)->notify_ops =
&vmci_transport_notify_pkt_q_state_ops;
break;
default:
pr_err("Unknown notify protocol version\n");
return false;
}
exit:
vmci_trans(vsk)->notify_ops->socket_init(sk);
return true;
}
static u16 vmci_transport_new_proto_supported_versions(void)
{
if (PROTOCOL_OVERRIDE != -1)
return PROTOCOL_OVERRIDE;
return VSOCK_PROTO_ALL_SUPPORTED;
}
static u32 vmci_transport_get_local_cid(void)
{
return vmci_get_context_id();
}
static int __init vmci_transport_init(void)
{
int err;
err = vmci_transport_datagram_create_hnd(VMCI_TRANSPORT_PACKET_RID,
VMCI_FLAG_ANYCID_DG_HND,
vmci_transport_recv_stream_cb,
NULL,
&vmci_transport_stream_handle);
if (err < VMCI_SUCCESS) {
pr_err("Unable to create datagram handle. (%d)\n", err);
return vmci_transport_error_to_vsock_error(err);
}
err = vmci_event_subscribe(VMCI_EVENT_QP_RESUMED,
vmci_transport_qp_resumed_cb,
NULL, &vmci_transport_qp_resumed_sub_id);
if (err < VMCI_SUCCESS) {
pr_err("Unable to subscribe to resumed event. (%d)\n", err);
err = vmci_transport_error_to_vsock_error(err);
vmci_transport_qp_resumed_sub_id = VMCI_INVALID_ID;
goto err_destroy_stream_handle;
}
err = vsock_core_init(&vmci_transport);
if (err < 0)
goto err_unsubscribe;
return 0;
err_unsubscribe:
vmci_event_unsubscribe(vmci_transport_qp_resumed_sub_id);
err_destroy_stream_handle:
vmci_datagram_destroy_handle(vmci_transport_stream_handle);
return err;
}
static void __exit vmci_transport_exit(void)
{
if (!vmci_handle_is_invalid(vmci_transport_stream_handle)) {
if (vmci_datagram_destroy_handle(
vmci_transport_stream_handle) != VMCI_SUCCESS)
pr_err("Couldn't destroy datagram handle\n");
vmci_transport_stream_handle = VMCI_INVALID_HANDLE;
}
if (vmci_transport_qp_resumed_sub_id != VMCI_INVALID_ID) {
vmci_event_unsubscribe(vmci_transport_qp_resumed_sub_id);
vmci_transport_qp_resumed_sub_id = VMCI_INVALID_ID;
}
vsock_core_exit();
}
