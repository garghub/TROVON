static void rxrpc_abort_calls(struct rxrpc_connection *conn, int state,
u32 abort_code)
{
struct rxrpc_call *call;
struct rb_node *p;
_enter("{%d},%x", conn->debug_id, abort_code);
read_lock_bh(&conn->lock);
for (p = rb_first(&conn->calls); p; p = rb_next(p)) {
call = rb_entry(p, struct rxrpc_call, conn_node);
write_lock(&call->state_lock);
if (call->state <= RXRPC_CALL_COMPLETE) {
call->state = state;
call->abort_code = abort_code;
if (state == RXRPC_CALL_LOCALLY_ABORTED)
set_bit(RXRPC_CALL_EV_CONN_ABORT, &call->events);
else
set_bit(RXRPC_CALL_EV_RCVD_ABORT, &call->events);
rxrpc_queue_call(call);
}
write_unlock(&call->state_lock);
}
read_unlock_bh(&conn->lock);
_leave("");
}
static int rxrpc_abort_connection(struct rxrpc_connection *conn,
u32 error, u32 abort_code)
{
struct rxrpc_wire_header whdr;
struct msghdr msg;
struct kvec iov[2];
__be32 word;
size_t len;
u32 serial;
int ret;
_enter("%d,,%u,%u", conn->debug_id, error, abort_code);
spin_lock_bh(&conn->state_lock);
if (conn->state < RXRPC_CONN_REMOTELY_ABORTED) {
conn->state = RXRPC_CONN_LOCALLY_ABORTED;
conn->error = error;
spin_unlock_bh(&conn->state_lock);
} else {
spin_unlock_bh(&conn->state_lock);
_leave(" = 0 [already dead]");
return 0;
}
rxrpc_abort_calls(conn, RXRPC_CALL_LOCALLY_ABORTED, abort_code);
msg.msg_name = &conn->trans->peer->srx.transport.sin;
msg.msg_namelen = sizeof(conn->trans->peer->srx.transport.sin);
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
whdr.epoch = htonl(conn->epoch);
whdr.cid = htonl(conn->cid);
whdr.callNumber = 0;
whdr.seq = 0;
whdr.type = RXRPC_PACKET_TYPE_ABORT;
whdr.flags = conn->out_clientflag;
whdr.userStatus = 0;
whdr.securityIndex = conn->security_ix;
whdr._rsvd = 0;
whdr.serviceId = htons(conn->service_id);
word = htonl(abort_code);
iov[0].iov_base = &whdr;
iov[0].iov_len = sizeof(whdr);
iov[1].iov_base = &word;
iov[1].iov_len = sizeof(word);
len = iov[0].iov_len + iov[1].iov_len;
serial = atomic_inc_return(&conn->serial);
whdr.serial = htonl(serial);
_proto("Tx CONN ABORT %%%u { %d }", serial, abort_code);
ret = kernel_sendmsg(conn->trans->local->socket, &msg, iov, 2, len);
if (ret < 0) {
_debug("sendmsg failed: %d", ret);
return -EAGAIN;
}
_leave(" = 0");
return 0;
}
static void rxrpc_call_is_secure(struct rxrpc_call *call)
{
_enter("%p", call);
if (call) {
read_lock(&call->state_lock);
if (call->state < RXRPC_CALL_COMPLETE &&
!test_and_set_bit(RXRPC_CALL_EV_SECURED, &call->events))
rxrpc_queue_call(call);
read_unlock(&call->state_lock);
}
}
static int rxrpc_process_event(struct rxrpc_connection *conn,
struct sk_buff *skb,
u32 *_abort_code)
{
struct rxrpc_skb_priv *sp = rxrpc_skb(skb);
__be32 wtmp;
u32 abort_code;
int loop, ret;
if (conn->state >= RXRPC_CONN_REMOTELY_ABORTED) {
kleave(" = -ECONNABORTED [%u]", conn->state);
return -ECONNABORTED;
}
_enter("{%d},{%u,%%%u},", conn->debug_id, sp->hdr.type, sp->hdr.serial);
switch (sp->hdr.type) {
case RXRPC_PACKET_TYPE_ABORT:
if (skb_copy_bits(skb, 0, &wtmp, sizeof(wtmp)) < 0)
return -EPROTO;
abort_code = ntohl(wtmp);
_proto("Rx ABORT %%%u { ac=%d }", sp->hdr.serial, abort_code);
conn->state = RXRPC_CONN_REMOTELY_ABORTED;
rxrpc_abort_calls(conn, RXRPC_CALL_REMOTELY_ABORTED,
abort_code);
return -ECONNABORTED;
case RXRPC_PACKET_TYPE_CHALLENGE:
if (conn->security)
return conn->security->respond_to_challenge(
conn, skb, _abort_code);
return -EPROTO;
case RXRPC_PACKET_TYPE_RESPONSE:
if (!conn->security)
return -EPROTO;
ret = conn->security->verify_response(conn, skb, _abort_code);
if (ret < 0)
return ret;
ret = conn->security->init_connection_security(conn);
if (ret < 0)
return ret;
conn->security->prime_packet_security(conn);
read_lock_bh(&conn->lock);
spin_lock(&conn->state_lock);
if (conn->state == RXRPC_CONN_SERVER_CHALLENGING) {
conn->state = RXRPC_CONN_SERVER;
for (loop = 0; loop < RXRPC_MAXCALLS; loop++)
rxrpc_call_is_secure(conn->channels[loop]);
}
spin_unlock(&conn->state_lock);
read_unlock_bh(&conn->lock);
return 0;
default:
_leave(" = -EPROTO [%u]", sp->hdr.type);
return -EPROTO;
}
}
static void rxrpc_secure_connection(struct rxrpc_connection *conn)
{
u32 abort_code;
int ret;
_enter("{%d}", conn->debug_id);
ASSERT(conn->security_ix != 0);
if (!conn->key) {
_debug("set up security");
ret = rxrpc_init_server_conn_security(conn);
switch (ret) {
case 0:
break;
case -ENOENT:
abort_code = RX_CALL_DEAD;
goto abort;
default:
abort_code = RXKADNOAUTH;
goto abort;
}
}
ASSERT(conn->security != NULL);
if (conn->security->issue_challenge(conn) < 0) {
abort_code = RX_CALL_DEAD;
ret = -ENOMEM;
goto abort;
}
_leave("");
return;
abort:
_debug("abort %d, %d", ret, abort_code);
rxrpc_abort_connection(conn, -ret, abort_code);
_leave(" [aborted]");
}
void rxrpc_process_connection(struct work_struct *work)
{
struct rxrpc_connection *conn =
container_of(work, struct rxrpc_connection, processor);
struct sk_buff *skb;
u32 abort_code = RX_PROTOCOL_ERROR;
int ret;
_enter("{%d}", conn->debug_id);
atomic_inc(&conn->usage);
if (test_and_clear_bit(RXRPC_CONN_CHALLENGE, &conn->events)) {
rxrpc_secure_connection(conn);
rxrpc_put_connection(conn);
}
while ((skb = skb_dequeue(&conn->rx_queue))) {
ret = rxrpc_process_event(conn, skb, &abort_code);
switch (ret) {
case -EPROTO:
case -EKEYEXPIRED:
case -EKEYREJECTED:
goto protocol_error;
case -EAGAIN:
goto requeue_and_leave;
case -ECONNABORTED:
default:
rxrpc_put_connection(conn);
rxrpc_free_skb(skb);
break;
}
}
out:
rxrpc_put_connection(conn);
_leave("");
return;
requeue_and_leave:
skb_queue_head(&conn->rx_queue, skb);
goto out;
protocol_error:
if (rxrpc_abort_connection(conn, -ret, abort_code) < 0)
goto requeue_and_leave;
rxrpc_put_connection(conn);
rxrpc_free_skb(skb);
_leave(" [EPROTO]");
goto out;
}
void rxrpc_reject_packet(struct rxrpc_local *local, struct sk_buff *skb)
{
CHECK_SLAB_OKAY(&local->usage);
if (!atomic_inc_not_zero(&local->usage)) {
printk("resurrected on reject\n");
BUG();
}
skb_queue_tail(&local->reject_queue, skb);
rxrpc_queue_work(&local->rejecter);
}
void rxrpc_reject_packets(struct work_struct *work)
{
union {
struct sockaddr sa;
struct sockaddr_in sin;
} sa;
struct rxrpc_skb_priv *sp;
struct rxrpc_wire_header whdr;
struct rxrpc_local *local;
struct sk_buff *skb;
struct msghdr msg;
struct kvec iov[2];
size_t size;
__be32 code;
local = container_of(work, struct rxrpc_local, rejecter);
rxrpc_get_local(local);
_enter("%d", local->debug_id);
iov[0].iov_base = &whdr;
iov[0].iov_len = sizeof(whdr);
iov[1].iov_base = &code;
iov[1].iov_len = sizeof(code);
size = sizeof(whdr) + sizeof(code);
msg.msg_name = &sa;
msg.msg_control = NULL;
msg.msg_controllen = 0;
msg.msg_flags = 0;
memset(&sa, 0, sizeof(sa));
sa.sa.sa_family = local->srx.transport.family;
switch (sa.sa.sa_family) {
case AF_INET:
msg.msg_namelen = sizeof(sa.sin);
break;
default:
msg.msg_namelen = 0;
break;
}
memset(&whdr, 0, sizeof(whdr));
whdr.type = RXRPC_PACKET_TYPE_ABORT;
while ((skb = skb_dequeue(&local->reject_queue))) {
sp = rxrpc_skb(skb);
switch (sa.sa.sa_family) {
case AF_INET:
sa.sin.sin_port = udp_hdr(skb)->source;
sa.sin.sin_addr.s_addr = ip_hdr(skb)->saddr;
code = htonl(skb->priority);
whdr.epoch = htonl(sp->hdr.epoch);
whdr.cid = htonl(sp->hdr.cid);
whdr.callNumber = htonl(sp->hdr.callNumber);
whdr.serviceId = htons(sp->hdr.serviceId);
whdr.flags = sp->hdr.flags;
whdr.flags ^= RXRPC_CLIENT_INITIATED;
whdr.flags &= RXRPC_CLIENT_INITIATED;
kernel_sendmsg(local->socket, &msg, iov, 2, size);
break;
default:
break;
}
rxrpc_free_skb(skb);
rxrpc_put_local(local);
}
rxrpc_put_local(local);
_leave("");
}
