static int rxrpc_busy(struct rxrpc_local *local, struct sockaddr_rxrpc *srx,
struct rxrpc_wire_header *whdr)
{
struct msghdr msg;
struct kvec iov[1];
size_t len;
int ret;
_enter("%d,,", local->debug_id);
whdr->type = RXRPC_PACKET_TYPE_BUSY;
whdr->serial = htonl(1);
msg.msg_name = &srx->transport.sin;
msg.msg_namelen = sizeof(srx->transport.sin);
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
iov[0].iov_base = whdr;
iov[0].iov_len = sizeof(*whdr);
len = iov[0].iov_len;
_proto("Tx BUSY %%1");
ret = kernel_sendmsg(local->socket, &msg, iov, 1, len);
if (ret < 0) {
_leave(" = -EAGAIN [sendmsg failed: %d]", ret);
return -EAGAIN;
}
_leave(" = 0");
return 0;
}
static int rxrpc_accept_incoming_call(struct rxrpc_local *local,
struct rxrpc_sock *rx,
struct sk_buff *skb,
struct sockaddr_rxrpc *srx)
{
struct rxrpc_connection *conn;
struct rxrpc_skb_priv *sp, *nsp;
struct rxrpc_call *call;
struct sk_buff *notification;
int ret;
_enter("");
sp = rxrpc_skb(skb);
notification = alloc_skb(0, GFP_NOFS);
if (!notification) {
_debug("no memory");
ret = -ENOMEM;
goto error_nofree;
}
rxrpc_new_skb(notification);
notification->mark = RXRPC_SKB_MARK_NEW_CALL;
conn = rxrpc_incoming_connection(local, srx, skb);
if (IS_ERR(conn)) {
_debug("no conn");
ret = PTR_ERR(conn);
goto error;
}
call = rxrpc_incoming_call(rx, conn, skb);
rxrpc_put_connection(conn);
if (IS_ERR(call)) {
_debug("no call");
ret = PTR_ERR(call);
goto error;
}
read_lock_bh(&local->services_lock);
if (rx->sk.sk_state == RXRPC_CLOSE)
goto invalid_service;
write_lock(&rx->call_lock);
if (!test_and_set_bit(RXRPC_CALL_INIT_ACCEPT, &call->flags)) {
rxrpc_get_call(call);
spin_lock(&call->conn->state_lock);
if (sp->hdr.securityIndex > 0 &&
call->conn->state == RXRPC_CONN_SERVICE_UNSECURED) {
_debug("await conn sec");
list_add_tail(&call->accept_link, &rx->secureq);
call->conn->state = RXRPC_CONN_SERVICE_CHALLENGING;
set_bit(RXRPC_CONN_EV_CHALLENGE, &call->conn->events);
rxrpc_queue_conn(call->conn);
} else {
_debug("conn ready");
call->state = RXRPC_CALL_SERVER_ACCEPTING;
list_add_tail(&call->accept_link, &rx->acceptq);
rxrpc_get_call(call);
atomic_inc(&call->skb_count);
nsp = rxrpc_skb(notification);
nsp->call = call;
ASSERTCMP(atomic_read(&call->usage), >=, 3);
_debug("notify");
spin_lock(&call->lock);
ret = rxrpc_queue_rcv_skb(call, notification, true,
false);
spin_unlock(&call->lock);
notification = NULL;
BUG_ON(ret < 0);
}
spin_unlock(&call->conn->state_lock);
_debug("queued");
}
write_unlock(&rx->call_lock);
_debug("process");
rxrpc_fast_process_packet(call, skb);
_debug("done");
read_unlock_bh(&local->services_lock);
rxrpc_free_skb(notification);
rxrpc_put_call(call);
_leave(" = 0");
return 0;
invalid_service:
_debug("invalid");
read_unlock_bh(&local->services_lock);
read_lock_bh(&call->state_lock);
if (!test_bit(RXRPC_CALL_RELEASED, &call->flags) &&
!test_and_set_bit(RXRPC_CALL_EV_RELEASE, &call->events)) {
rxrpc_get_call(call);
rxrpc_queue_call(call);
}
read_unlock_bh(&call->state_lock);
rxrpc_put_call(call);
ret = -ECONNREFUSED;
error:
rxrpc_free_skb(notification);
error_nofree:
_leave(" = %d", ret);
return ret;
}
void rxrpc_accept_incoming_calls(struct rxrpc_local *local)
{
struct rxrpc_skb_priv *sp;
struct sockaddr_rxrpc srx;
struct rxrpc_sock *rx;
struct rxrpc_wire_header whdr;
struct sk_buff *skb;
int ret;
_enter("%d", local->debug_id);
skb = skb_dequeue(&local->accept_queue);
if (!skb) {
_leave("\n");
return;
}
_net("incoming call skb %p", skb);
sp = rxrpc_skb(skb);
whdr.epoch = htonl(sp->hdr.epoch);
whdr.cid = htonl(sp->hdr.cid);
whdr.callNumber = htonl(sp->hdr.callNumber);
whdr.seq = htonl(sp->hdr.seq);
whdr.serial = 0;
whdr.flags = 0;
whdr.type = 0;
whdr.userStatus = 0;
whdr.securityIndex = sp->hdr.securityIndex;
whdr._rsvd = 0;
whdr.serviceId = htons(sp->hdr.serviceId);
if (rxrpc_extract_addr_from_skb(&srx, skb) < 0)
goto drop;
read_lock_bh(&local->services_lock);
list_for_each_entry(rx, &local->services, listen_link) {
if (rx->srx.srx_service == sp->hdr.serviceId &&
rx->sk.sk_state != RXRPC_CLOSE)
goto found_service;
}
read_unlock_bh(&local->services_lock);
goto invalid_service;
found_service:
_debug("found service %hd", rx->srx.srx_service);
if (sk_acceptq_is_full(&rx->sk))
goto backlog_full;
sk_acceptq_added(&rx->sk);
sock_hold(&rx->sk);
read_unlock_bh(&local->services_lock);
ret = rxrpc_accept_incoming_call(local, rx, skb, &srx);
if (ret < 0)
sk_acceptq_removed(&rx->sk);
sock_put(&rx->sk);
switch (ret) {
case -ECONNRESET:
case -ECONNABORTED:
case 0:
return;
case -ECONNREFUSED:
goto invalid_service;
case -EBUSY:
goto busy;
case -EKEYREJECTED:
goto security_mismatch;
default:
BUG();
}
backlog_full:
read_unlock_bh(&local->services_lock);
busy:
rxrpc_busy(local, &srx, &whdr);
rxrpc_free_skb(skb);
return;
drop:
rxrpc_free_skb(skb);
return;
invalid_service:
skb->priority = RX_INVALID_OPERATION;
rxrpc_reject_packet(local, skb);
return;
security_mismatch:
skb->priority = RX_PROTOCOL_ERROR;
rxrpc_reject_packet(local, skb);
return;
}
struct rxrpc_call *rxrpc_accept_call(struct rxrpc_sock *rx,
unsigned long user_call_ID)
{
struct rxrpc_call *call;
struct rb_node *parent, **pp;
int ret;
_enter(",%lx", user_call_ID);
ASSERT(!irqs_disabled());
write_lock(&rx->call_lock);
ret = -ENODATA;
if (list_empty(&rx->acceptq))
goto out;
ret = -EBADSLT;
pp = &rx->calls.rb_node;
parent = NULL;
while (*pp) {
parent = *pp;
call = rb_entry(parent, struct rxrpc_call, sock_node);
if (user_call_ID < call->user_call_ID)
pp = &(*pp)->rb_left;
else if (user_call_ID > call->user_call_ID)
pp = &(*pp)->rb_right;
else
goto out;
}
call = list_entry(rx->acceptq.next, struct rxrpc_call, accept_link);
list_del_init(&call->accept_link);
sk_acceptq_removed(&rx->sk);
write_lock_bh(&call->state_lock);
switch (call->state) {
case RXRPC_CALL_SERVER_ACCEPTING:
call->state = RXRPC_CALL_SERVER_RECV_REQUEST;
break;
case RXRPC_CALL_REMOTELY_ABORTED:
case RXRPC_CALL_LOCALLY_ABORTED:
ret = -ECONNABORTED;
goto out_release;
case RXRPC_CALL_NETWORK_ERROR:
ret = call->conn->error;
goto out_release;
case RXRPC_CALL_DEAD:
ret = -ETIME;
goto out_discard;
default:
BUG();
}
call->user_call_ID = user_call_ID;
rb_link_node(&call->sock_node, parent, pp);
rb_insert_color(&call->sock_node, &rx->calls);
if (test_and_set_bit(RXRPC_CALL_HAS_USERID, &call->flags))
BUG();
if (test_and_set_bit(RXRPC_CALL_EV_ACCEPTED, &call->events))
BUG();
rxrpc_queue_call(call);
rxrpc_get_call(call);
write_unlock_bh(&call->state_lock);
write_unlock(&rx->call_lock);
_leave(" = %p{%d}", call, call->debug_id);
return call;
out_release:
_debug("release %p", call);
if (!test_bit(RXRPC_CALL_RELEASED, &call->flags) &&
!test_and_set_bit(RXRPC_CALL_EV_RELEASE, &call->events))
rxrpc_queue_call(call);
out_discard:
write_unlock_bh(&call->state_lock);
_debug("discard %p", call);
out:
write_unlock(&rx->call_lock);
_leave(" = %d", ret);
return ERR_PTR(ret);
}
int rxrpc_reject_call(struct rxrpc_sock *rx)
{
struct rxrpc_call *call;
int ret;
_enter("");
ASSERT(!irqs_disabled());
write_lock(&rx->call_lock);
ret = -ENODATA;
if (list_empty(&rx->acceptq))
goto out;
call = list_entry(rx->acceptq.next, struct rxrpc_call, accept_link);
list_del_init(&call->accept_link);
sk_acceptq_removed(&rx->sk);
write_lock_bh(&call->state_lock);
switch (call->state) {
case RXRPC_CALL_SERVER_ACCEPTING:
call->state = RXRPC_CALL_SERVER_BUSY;
if (test_and_set_bit(RXRPC_CALL_EV_REJECT_BUSY, &call->events))
rxrpc_queue_call(call);
ret = 0;
goto out_release;
case RXRPC_CALL_REMOTELY_ABORTED:
case RXRPC_CALL_LOCALLY_ABORTED:
ret = -ECONNABORTED;
goto out_release;
case RXRPC_CALL_NETWORK_ERROR:
ret = call->conn->error;
goto out_release;
case RXRPC_CALL_DEAD:
ret = -ETIME;
goto out_discard;
default:
BUG();
}
out_release:
_debug("release %p", call);
if (!test_bit(RXRPC_CALL_RELEASED, &call->flags) &&
!test_and_set_bit(RXRPC_CALL_EV_RELEASE, &call->events))
rxrpc_queue_call(call);
out_discard:
write_unlock_bh(&call->state_lock);
_debug("discard %p", call);
out:
write_unlock(&rx->call_lock);
_leave(" = %d", ret);
return ret;
}
struct rxrpc_call *rxrpc_kernel_accept_call(struct socket *sock,
unsigned long user_call_ID)
{
struct rxrpc_call *call;
_enter(",%lx", user_call_ID);
call = rxrpc_accept_call(rxrpc_sk(sock->sk), user_call_ID);
_leave(" = %p", call);
return call;
}
int rxrpc_kernel_reject_call(struct socket *sock)
{
int ret;
_enter("");
ret = rxrpc_reject_call(rxrpc_sk(sock->sk));
_leave(" = %d", ret);
return ret;
}
