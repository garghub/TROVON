static bool is_valid_srv_id(const uuid_le *id)
{
return !memcmp(&id->b[4], &srv_id_template.b[4], sizeof(uuid_le) - 4);
}
static unsigned int get_port_by_srv_id(const uuid_le *svr_id)
{
return *((unsigned int *)svr_id);
}
static void hvs_addr_init(struct sockaddr_vm *addr, const uuid_le *svr_id)
{
unsigned int port = get_port_by_srv_id(svr_id);
vsock_addr_init(addr, VMADDR_CID_ANY, port);
}
static void hvs_remote_addr_init(struct sockaddr_vm *remote,
struct sockaddr_vm *local)
{
static u32 host_ephemeral_port = MIN_HOST_EPHEMERAL_PORT;
struct sock *sk;
vsock_addr_init(remote, VMADDR_CID_ANY, VMADDR_PORT_ANY);
while (1) {
if (host_ephemeral_port < MIN_HOST_EPHEMERAL_PORT ||
host_ephemeral_port == VMADDR_PORT_ANY)
host_ephemeral_port = MIN_HOST_EPHEMERAL_PORT;
remote->svm_port = host_ephemeral_port++;
sk = vsock_find_connected_socket(remote, local);
if (!sk) {
return;
}
sock_put(sk);
}
}
static void hvs_set_channel_pending_send_size(struct vmbus_channel *chan)
{
set_channel_pending_send_size(chan,
HVS_PKT_LEN(HVS_SEND_BUF_SIZE));
virt_mb();
}
static void hvs_clear_channel_pending_send_size(struct vmbus_channel *chan)
{
set_channel_pending_send_size(chan, 0);
virt_mb();
}
static bool hvs_channel_readable(struct vmbus_channel *chan)
{
u32 readable = hv_get_bytes_to_read(&chan->inbound);
return readable >= HVS_PKT_LEN(0);
}
static int hvs_channel_readable_payload(struct vmbus_channel *chan)
{
u32 readable = hv_get_bytes_to_read(&chan->inbound);
if (readable > HVS_PKT_LEN(0)) {
return 1;
}
if (readable == HVS_PKT_LEN(0)) {
return 0;
}
return -1;
}
static size_t hvs_channel_writable_bytes(struct vmbus_channel *chan)
{
u32 writeable = hv_get_bytes_to_write(&chan->outbound);
size_t ret;
if (writeable <= HVS_PKT_LEN(1) + HVS_PKT_LEN(0))
return 0;
ret = writeable - HVS_PKT_LEN(1) - HVS_PKT_LEN(0);
return round_down(ret, 8);
}
static int hvs_send_data(struct vmbus_channel *chan,
struct hvs_send_buf *send_buf, size_t to_write)
{
send_buf->hdr.pkt_type = 1;
send_buf->hdr.data_size = to_write;
return vmbus_sendpacket(chan, &send_buf->hdr,
sizeof(send_buf->hdr) + to_write,
0, VM_PKT_DATA_INBAND, 0);
}
static void hvs_channel_cb(void *ctx)
{
struct sock *sk = (struct sock *)ctx;
struct vsock_sock *vsk = vsock_sk(sk);
struct hvsock *hvs = vsk->trans;
struct vmbus_channel *chan = hvs->chan;
if (hvs_channel_readable(chan))
sk->sk_data_ready(sk);
if (hv_get_bytes_to_write(&chan->outbound) > 0)
sk->sk_write_space(sk);
}
static void hvs_close_connection(struct vmbus_channel *chan)
{
struct sock *sk = get_per_channel_state(chan);
struct vsock_sock *vsk = vsock_sk(sk);
lock_sock(sk);
sk->sk_state = SS_UNCONNECTED;
sock_set_flag(sk, SOCK_DONE);
vsk->peer_shutdown |= SEND_SHUTDOWN | RCV_SHUTDOWN;
sk->sk_state_change(sk);
release_sock(sk);
}
static void hvs_open_connection(struct vmbus_channel *chan)
{
uuid_le *if_instance, *if_type;
unsigned char conn_from_host;
struct sockaddr_vm addr;
struct sock *sk, *new = NULL;
struct vsock_sock *vnew;
struct hvsock *hvs, *hvs_new;
int ret;
if_type = &chan->offermsg.offer.if_type;
if_instance = &chan->offermsg.offer.if_instance;
conn_from_host = chan->offermsg.offer.u.pipe.user_def[0];
if (!is_valid_srv_id(if_type) ||
get_port_by_srv_id(if_type) > MAX_LISTEN_PORT)
return;
hvs_addr_init(&addr, conn_from_host ? if_type : if_instance);
sk = vsock_find_bound_socket(&addr);
if (!sk)
return;
lock_sock(sk);
if ((conn_from_host && sk->sk_state != VSOCK_SS_LISTEN) ||
(!conn_from_host && sk->sk_state != SS_CONNECTING))
goto out;
if (conn_from_host) {
if (sk->sk_ack_backlog >= sk->sk_max_ack_backlog)
goto out;
new = __vsock_create(sock_net(sk), NULL, sk, GFP_KERNEL,
sk->sk_type, 0);
if (!new)
goto out;
new->sk_state = SS_CONNECTING;
vnew = vsock_sk(new);
hvs_new = vnew->trans;
hvs_new->chan = chan;
} else {
hvs = vsock_sk(sk)->trans;
hvs->chan = chan;
}
set_channel_read_mode(chan, HV_CALL_DIRECT);
ret = vmbus_open(chan, RINGBUFFER_HVS_SND_SIZE,
RINGBUFFER_HVS_RCV_SIZE, NULL, 0,
hvs_channel_cb, conn_from_host ? new : sk);
if (ret != 0) {
if (conn_from_host) {
hvs_new->chan = NULL;
sock_put(new);
} else {
hvs->chan = NULL;
}
goto out;
}
set_per_channel_state(chan, conn_from_host ? new : sk);
vmbus_set_chn_rescind_callback(chan, hvs_close_connection);
if (conn_from_host) {
new->sk_state = SS_CONNECTED;
sk->sk_ack_backlog++;
hvs_addr_init(&vnew->local_addr, if_type);
hvs_remote_addr_init(&vnew->remote_addr, &vnew->local_addr);
hvs_new->vm_srv_id = *if_type;
hvs_new->host_srv_id = *if_instance;
vsock_insert_connected(vnew);
vsock_enqueue_accept(sk, new);
} else {
sk->sk_state = SS_CONNECTED;
sk->sk_socket->state = SS_CONNECTED;
vsock_insert_connected(vsock_sk(sk));
}
sk->sk_state_change(sk);
out:
sock_put(sk);
release_sock(sk);
}
static u32 hvs_get_local_cid(void)
{
return VMADDR_CID_ANY;
}
static int hvs_sock_init(struct vsock_sock *vsk, struct vsock_sock *psk)
{
struct hvsock *hvs;
hvs = kzalloc(sizeof(*hvs), GFP_KERNEL);
if (!hvs)
return -ENOMEM;
vsk->trans = hvs;
hvs->vsk = vsk;
return 0;
}
static int hvs_connect(struct vsock_sock *vsk)
{
union hvs_service_id vm, host;
struct hvsock *h = vsk->trans;
vm.srv_id = srv_id_template;
vm.svm_port = vsk->local_addr.svm_port;
h->vm_srv_id = vm.srv_id;
host.srv_id = srv_id_template;
host.svm_port = vsk->remote_addr.svm_port;
h->host_srv_id = host.srv_id;
return vmbus_send_tl_connect_request(&h->vm_srv_id, &h->host_srv_id);
}
static int hvs_shutdown(struct vsock_sock *vsk, int mode)
{
struct sock *sk = sk_vsock(vsk);
struct vmpipe_proto_header hdr;
struct hvs_send_buf *send_buf;
struct hvsock *hvs;
if (!(mode & SEND_SHUTDOWN))
return 0;
lock_sock(sk);
hvs = vsk->trans;
if (hvs->fin_sent)
goto out;
send_buf = (struct hvs_send_buf *)&hdr;
(void)hvs_send_data(hvs->chan, send_buf, 0);
hvs->fin_sent = true;
out:
release_sock(sk);
return 0;
}
static void hvs_release(struct vsock_sock *vsk)
{
struct sock *sk = sk_vsock(vsk);
struct hvsock *hvs = vsk->trans;
struct vmbus_channel *chan;
lock_sock(sk);
sk->sk_state = SS_DISCONNECTING;
vsock_remove_sock(vsk);
release_sock(sk);
chan = hvs->chan;
if (chan)
hvs_shutdown(vsk, RCV_SHUTDOWN | SEND_SHUTDOWN);
}
static void hvs_destruct(struct vsock_sock *vsk)
{
struct hvsock *hvs = vsk->trans;
struct vmbus_channel *chan = hvs->chan;
if (chan)
vmbus_hvsock_device_unregister(chan);
kfree(hvs);
}
static int hvs_dgram_bind(struct vsock_sock *vsk, struct sockaddr_vm *addr)
{
return -EOPNOTSUPP;
}
static int hvs_dgram_dequeue(struct vsock_sock *vsk, struct msghdr *msg,
size_t len, int flags)
{
return -EOPNOTSUPP;
}
static int hvs_dgram_enqueue(struct vsock_sock *vsk,
struct sockaddr_vm *remote, struct msghdr *msg,
size_t dgram_len)
{
return -EOPNOTSUPP;
}
static bool hvs_dgram_allow(u32 cid, u32 port)
{
return false;
}
static int hvs_update_recv_data(struct hvsock *hvs)
{
struct hvs_recv_buf *recv_buf;
u32 payload_len;
recv_buf = (struct hvs_recv_buf *)(hvs->recv_desc + 1);
payload_len = recv_buf->hdr.data_size;
if (payload_len > HVS_MTU_SIZE)
return -EIO;
if (payload_len == 0)
hvs->vsk->peer_shutdown |= SEND_SHUTDOWN;
hvs->recv_data_len = payload_len;
hvs->recv_data_off = 0;
return 0;
}
static ssize_t hvs_stream_dequeue(struct vsock_sock *vsk, struct msghdr *msg,
size_t len, int flags)
{
struct hvsock *hvs = vsk->trans;
bool need_refill = !hvs->recv_desc;
struct hvs_recv_buf *recv_buf;
u32 to_read;
int ret;
if (flags & MSG_PEEK)
return -EOPNOTSUPP;
if (need_refill) {
hvs->recv_desc = hv_pkt_iter_first(hvs->chan);
ret = hvs_update_recv_data(hvs);
if (ret)
return ret;
}
recv_buf = (struct hvs_recv_buf *)(hvs->recv_desc + 1);
to_read = min_t(u32, len, hvs->recv_data_len);
ret = memcpy_to_msg(msg, recv_buf->data + hvs->recv_data_off, to_read);
if (ret != 0)
return ret;
hvs->recv_data_len -= to_read;
if (hvs->recv_data_len == 0) {
hvs->recv_desc = hv_pkt_iter_next(hvs->chan, hvs->recv_desc);
if (hvs->recv_desc) {
ret = hvs_update_recv_data(hvs);
if (ret)
return ret;
}
} else {
hvs->recv_data_off += to_read;
}
return to_read;
}
static ssize_t hvs_stream_enqueue(struct vsock_sock *vsk, struct msghdr *msg,
size_t len)
{
struct hvsock *hvs = vsk->trans;
struct vmbus_channel *chan = hvs->chan;
struct hvs_send_buf *send_buf;
ssize_t to_write, max_writable, ret;
BUILD_BUG_ON(sizeof(*send_buf) != PAGE_SIZE_4K);
send_buf = kmalloc(sizeof(*send_buf), GFP_KERNEL);
if (!send_buf)
return -ENOMEM;
max_writable = hvs_channel_writable_bytes(chan);
to_write = min_t(ssize_t, len, max_writable);
to_write = min_t(ssize_t, to_write, HVS_SEND_BUF_SIZE);
ret = memcpy_from_msg(send_buf->data, msg, to_write);
if (ret < 0)
goto out;
ret = hvs_send_data(hvs->chan, send_buf, to_write);
if (ret < 0)
goto out;
ret = to_write;
out:
kfree(send_buf);
return ret;
}
static s64 hvs_stream_has_data(struct vsock_sock *vsk)
{
struct hvsock *hvs = vsk->trans;
s64 ret;
if (hvs->recv_data_len > 0)
return 1;
switch (hvs_channel_readable_payload(hvs->chan)) {
case 1:
ret = 1;
break;
case 0:
vsk->peer_shutdown |= SEND_SHUTDOWN;
ret = 0;
break;
default:
ret = 0;
break;
}
return ret;
}
static s64 hvs_stream_has_space(struct vsock_sock *vsk)
{
struct hvsock *hvs = vsk->trans;
struct vmbus_channel *chan = hvs->chan;
s64 ret;
ret = hvs_channel_writable_bytes(chan);
if (ret > 0) {
hvs_clear_channel_pending_send_size(chan);
} else {
hvs_set_channel_pending_send_size(chan);
ret = hvs_channel_writable_bytes(chan);
if (ret > 0)
hvs_clear_channel_pending_send_size(chan);
}
return ret;
}
static u64 hvs_stream_rcvhiwat(struct vsock_sock *vsk)
{
return HVS_MTU_SIZE + 1;
}
static bool hvs_stream_is_active(struct vsock_sock *vsk)
{
struct hvsock *hvs = vsk->trans;
return hvs->chan != NULL;
}
static bool hvs_stream_allow(u32 cid, u32 port)
{
if (port > MAX_HOST_LISTEN_PORT)
return false;
if (cid == VMADDR_CID_HOST)
return true;
return false;
}
static
int hvs_notify_poll_in(struct vsock_sock *vsk, size_t target, bool *readable)
{
struct hvsock *hvs = vsk->trans;
*readable = hvs_channel_readable(hvs->chan);
return 0;
}
static
int hvs_notify_poll_out(struct vsock_sock *vsk, size_t target, bool *writable)
{
*writable = hvs_stream_has_space(vsk) > 0;
return 0;
}
static
int hvs_notify_recv_init(struct vsock_sock *vsk, size_t target,
struct vsock_transport_recv_notify_data *d)
{
return 0;
}
static
int hvs_notify_recv_pre_block(struct vsock_sock *vsk, size_t target,
struct vsock_transport_recv_notify_data *d)
{
return 0;
}
static
int hvs_notify_recv_pre_dequeue(struct vsock_sock *vsk, size_t target,
struct vsock_transport_recv_notify_data *d)
{
return 0;
}
static
int hvs_notify_recv_post_dequeue(struct vsock_sock *vsk, size_t target,
ssize_t copied, bool data_read,
struct vsock_transport_recv_notify_data *d)
{
return 0;
}
static
int hvs_notify_send_init(struct vsock_sock *vsk,
struct vsock_transport_send_notify_data *d)
{
return 0;
}
static
int hvs_notify_send_pre_block(struct vsock_sock *vsk,
struct vsock_transport_send_notify_data *d)
{
return 0;
}
static
int hvs_notify_send_pre_enqueue(struct vsock_sock *vsk,
struct vsock_transport_send_notify_data *d)
{
return 0;
}
static
int hvs_notify_send_post_enqueue(struct vsock_sock *vsk, ssize_t written,
struct vsock_transport_send_notify_data *d)
{
return 0;
}
static void hvs_set_buffer_size(struct vsock_sock *vsk, u64 val)
{
}
static void hvs_set_min_buffer_size(struct vsock_sock *vsk, u64 val)
{
}
static void hvs_set_max_buffer_size(struct vsock_sock *vsk, u64 val)
{
}
static u64 hvs_get_buffer_size(struct vsock_sock *vsk)
{
return -ENOPROTOOPT;
}
static u64 hvs_get_min_buffer_size(struct vsock_sock *vsk)
{
return -ENOPROTOOPT;
}
static u64 hvs_get_max_buffer_size(struct vsock_sock *vsk)
{
return -ENOPROTOOPT;
}
static int hvs_probe(struct hv_device *hdev,
const struct hv_vmbus_device_id *dev_id)
{
struct vmbus_channel *chan = hdev->channel;
hvs_open_connection(chan);
return 0;
}
static int hvs_remove(struct hv_device *hdev)
{
struct vmbus_channel *chan = hdev->channel;
vmbus_close(chan);
return 0;
}
static int __init hvs_init(void)
{
int ret;
if (vmbus_proto_version < VERSION_WIN10)
return -ENODEV;
ret = vmbus_driver_register(&hvs_drv);
if (ret != 0)
return ret;
ret = vsock_core_init(&hvs_transport);
if (ret) {
vmbus_driver_unregister(&hvs_drv);
return ret;
}
return 0;
}
static void __exit hvs_exit(void)
{
vsock_core_exit();
vmbus_driver_unregister(&hvs_drv);
}
