static
struct rxrpc_local *rxrpc_alloc_local(struct sockaddr_rxrpc *srx)
{
struct rxrpc_local *local;
local = kzalloc(sizeof(struct rxrpc_local), GFP_KERNEL);
if (local) {
INIT_WORK(&local->destroyer, &rxrpc_destroy_local);
INIT_WORK(&local->acceptor, &rxrpc_accept_incoming_calls);
INIT_WORK(&local->rejecter, &rxrpc_reject_packets);
INIT_WORK(&local->event_processor, &rxrpc_process_local_events);
INIT_LIST_HEAD(&local->services);
INIT_LIST_HEAD(&local->link);
init_rwsem(&local->defrag_sem);
skb_queue_head_init(&local->accept_queue);
skb_queue_head_init(&local->reject_queue);
skb_queue_head_init(&local->event_queue);
spin_lock_init(&local->lock);
rwlock_init(&local->services_lock);
atomic_set(&local->usage, 1);
local->debug_id = atomic_inc_return(&rxrpc_debug_id);
memcpy(&local->srx, srx, sizeof(*srx));
}
_leave(" = %p", local);
return local;
}
static int rxrpc_create_local(struct rxrpc_local *local)
{
struct sock *sock;
int ret, opt;
_enter("%p{%d}", local, local->srx.transport_type);
ret = sock_create_kern(PF_INET, local->srx.transport_type, IPPROTO_UDP,
&local->socket);
if (ret < 0) {
_leave(" = %d [socket]", ret);
return ret;
}
if (local->srx.transport_len > sizeof(sa_family_t)) {
_debug("bind");
ret = kernel_bind(local->socket,
(struct sockaddr *) &local->srx.transport,
local->srx.transport_len);
if (ret < 0) {
_debug("bind failed");
goto error;
}
}
opt = 1;
ret = kernel_setsockopt(local->socket, SOL_IP, IP_RECVERR,
(char *) &opt, sizeof(opt));
if (ret < 0) {
_debug("setsockopt failed");
goto error;
}
opt = IP_PMTUDISC_DO;
ret = kernel_setsockopt(local->socket, SOL_IP, IP_MTU_DISCOVER,
(char *) &opt, sizeof(opt));
if (ret < 0) {
_debug("setsockopt failed");
goto error;
}
write_lock_bh(&rxrpc_local_lock);
list_add(&local->link, &rxrpc_locals);
write_unlock_bh(&rxrpc_local_lock);
sock = local->socket->sk;
sock->sk_user_data = local;
sock->sk_data_ready = rxrpc_data_ready;
sock->sk_error_report = rxrpc_UDP_error_report;
_leave(" = 0");
return 0;
error:
kernel_sock_shutdown(local->socket, SHUT_RDWR);
local->socket->sk->sk_user_data = NULL;
sock_release(local->socket);
local->socket = NULL;
_leave(" = %d", ret);
return ret;
}
struct rxrpc_local *rxrpc_lookup_local(struct sockaddr_rxrpc *srx)
{
struct rxrpc_local *local;
int ret;
_enter("{%d,%u,%pI4+%hu}",
srx->transport_type,
srx->transport.family,
&srx->transport.sin.sin_addr,
ntohs(srx->transport.sin.sin_port));
down_write(&rxrpc_local_sem);
read_lock_bh(&rxrpc_local_lock);
list_for_each_entry(local, &rxrpc_locals, link) {
_debug("CMP {%d,%u,%pI4+%hu}",
local->srx.transport_type,
local->srx.transport.family,
&local->srx.transport.sin.sin_addr,
ntohs(local->srx.transport.sin.sin_port));
if (local->srx.transport_type != srx->transport_type ||
local->srx.transport.family != srx->transport.family)
continue;
switch (srx->transport.family) {
case AF_INET:
if (local->srx.transport.sin.sin_port !=
srx->transport.sin.sin_port)
continue;
if (memcmp(&local->srx.transport.sin.sin_addr,
&srx->transport.sin.sin_addr,
sizeof(struct in_addr)) != 0)
continue;
goto found_local;
default:
BUG();
}
}
read_unlock_bh(&rxrpc_local_lock);
local = rxrpc_alloc_local(srx);
if (!local) {
up_write(&rxrpc_local_sem);
return ERR_PTR(-ENOMEM);
}
ret = rxrpc_create_local(local);
if (ret < 0) {
up_write(&rxrpc_local_sem);
kfree(local);
_leave(" = %d", ret);
return ERR_PTR(ret);
}
up_write(&rxrpc_local_sem);
_net("LOCAL new %d {%d,%u,%pI4+%hu}",
local->debug_id,
local->srx.transport_type,
local->srx.transport.family,
&local->srx.transport.sin.sin_addr,
ntohs(local->srx.transport.sin.sin_port));
_leave(" = %p [new]", local);
return local;
found_local:
rxrpc_get_local(local);
read_unlock_bh(&rxrpc_local_lock);
up_write(&rxrpc_local_sem);
_net("LOCAL old %d {%d,%u,%pI4+%hu}",
local->debug_id,
local->srx.transport_type,
local->srx.transport.family,
&local->srx.transport.sin.sin_addr,
ntohs(local->srx.transport.sin.sin_port));
_leave(" = %p [reuse]", local);
return local;
}
void rxrpc_put_local(struct rxrpc_local *local)
{
_enter("%p{u=%d}", local, atomic_read(&local->usage));
ASSERTCMP(atomic_read(&local->usage), >, 0);
write_lock_bh(&rxrpc_local_lock);
if (unlikely(atomic_dec_and_test(&local->usage))) {
_debug("destroy local");
rxrpc_queue_work(&local->destroyer);
}
write_unlock_bh(&rxrpc_local_lock);
_leave("");
}
static void rxrpc_destroy_local(struct work_struct *work)
{
struct rxrpc_local *local =
container_of(work, struct rxrpc_local, destroyer);
_enter("%p{%d}", local, atomic_read(&local->usage));
down_write(&rxrpc_local_sem);
write_lock_bh(&rxrpc_local_lock);
if (atomic_read(&local->usage) > 0) {
write_unlock_bh(&rxrpc_local_lock);
up_read(&rxrpc_local_sem);
_leave(" [resurrected]");
return;
}
list_del(&local->link);
local->socket->sk->sk_user_data = NULL;
write_unlock_bh(&rxrpc_local_lock);
downgrade_write(&rxrpc_local_sem);
ASSERT(list_empty(&local->services));
ASSERT(!work_pending(&local->acceptor));
ASSERT(!work_pending(&local->rejecter));
ASSERT(!work_pending(&local->event_processor));
rxrpc_purge_queue(&local->accept_queue);
rxrpc_purge_queue(&local->reject_queue);
rxrpc_purge_queue(&local->event_queue);
kernel_sock_shutdown(local->socket, SHUT_RDWR);
sock_release(local->socket);
up_read(&rxrpc_local_sem);
_net("DESTROY LOCAL %d", local->debug_id);
kfree(local);
if (list_empty(&rxrpc_locals))
wake_up_all(&rxrpc_local_wq);
_leave("");
}
void __exit rxrpc_destroy_all_locals(void)
{
DECLARE_WAITQUEUE(myself,current);
_enter("");
if (!list_empty(&rxrpc_locals)) {
set_current_state(TASK_UNINTERRUPTIBLE);
add_wait_queue(&rxrpc_local_wq, &myself);
while (!list_empty(&rxrpc_locals)) {
schedule();
set_current_state(TASK_UNINTERRUPTIBLE);
}
remove_wait_queue(&rxrpc_local_wq, &myself);
set_current_state(TASK_RUNNING);
}
_leave("");
}
static void rxrpc_send_version_request(struct rxrpc_local *local,
struct rxrpc_header *hdr,
struct sk_buff *skb)
{
struct sockaddr_in sin;
struct msghdr msg;
struct kvec iov[2];
size_t len;
int ret;
_enter("");
sin.sin_family = AF_INET;
sin.sin_port = udp_hdr(skb)->source;
sin.sin_addr.s_addr = ip_hdr(skb)->saddr;
msg.msg_name = &sin;
msg.msg_namelen = sizeof(sin);
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
hdr->seq = 0;
hdr->serial = 0;
hdr->type = RXRPC_PACKET_TYPE_VERSION;
hdr->flags = RXRPC_LAST_PACKET | (~hdr->flags & RXRPC_CLIENT_INITIATED);
hdr->userStatus = 0;
hdr->_rsvd = 0;
iov[0].iov_base = hdr;
iov[0].iov_len = sizeof(*hdr);
iov[1].iov_base = (char *)rxrpc_version_string;
iov[1].iov_len = sizeof(rxrpc_version_string);
len = iov[0].iov_len + iov[1].iov_len;
_proto("Tx VERSION (reply)");
ret = kernel_sendmsg(local->socket, &msg, iov, 2, len);
if (ret < 0)
_debug("sendmsg failed: %d", ret);
_leave("");
}
static void rxrpc_process_local_events(struct work_struct *work)
{
struct rxrpc_local *local = container_of(work, struct rxrpc_local, event_processor);
struct sk_buff *skb;
char v;
_enter("");
atomic_inc(&local->usage);
while ((skb = skb_dequeue(&local->event_queue))) {
struct rxrpc_skb_priv *sp = rxrpc_skb(skb);
kdebug("{%d},{%u}", local->debug_id, sp->hdr.type);
switch (sp->hdr.type) {
case RXRPC_PACKET_TYPE_VERSION:
if (skb_copy_bits(skb, 0, &v, 1) < 0)
return;
_proto("Rx VERSION { %02x }", v);
if (v == 0)
rxrpc_send_version_request(local, &sp->hdr, skb);
break;
default:
break;
}
rxrpc_put_local(local);
rxrpc_free_skb(skb);
}
rxrpc_put_local(local);
_leave("");
}
