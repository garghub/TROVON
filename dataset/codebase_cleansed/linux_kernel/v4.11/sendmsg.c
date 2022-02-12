static int rxrpc_wait_for_tx_window(struct rxrpc_sock *rx,
struct rxrpc_call *call,
long *timeo)
{
DECLARE_WAITQUEUE(myself, current);
int ret;
_enter(",{%u,%u,%u}",
call->tx_hard_ack, call->tx_top, call->tx_winsize);
add_wait_queue(&call->waitq, &myself);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
ret = 0;
if (call->tx_top - call->tx_hard_ack <
min_t(unsigned int, call->tx_winsize,
call->cong_cwnd + call->cong_extra))
break;
if (call->state >= RXRPC_CALL_COMPLETE) {
ret = -call->error;
break;
}
if (signal_pending(current)) {
ret = sock_intr_errno(*timeo);
break;
}
trace_rxrpc_transmit(call, rxrpc_transmit_wait);
mutex_unlock(&call->user_mutex);
*timeo = schedule_timeout(*timeo);
if (mutex_lock_interruptible(&call->user_mutex) < 0) {
ret = sock_intr_errno(*timeo);
break;
}
}
remove_wait_queue(&call->waitq, &myself);
set_current_state(TASK_RUNNING);
_leave(" = %d", ret);
return ret;
}
static inline void rxrpc_instant_resend(struct rxrpc_call *call, int ix)
{
spin_lock_bh(&call->lock);
if (call->state < RXRPC_CALL_COMPLETE) {
call->rxtx_annotations[ix] = RXRPC_TX_ANNO_RETRANS;
if (!test_and_set_bit(RXRPC_CALL_EV_RESEND, &call->events))
rxrpc_queue_call(call);
}
spin_unlock_bh(&call->lock);
}
static void rxrpc_queue_packet(struct rxrpc_call *call, struct sk_buff *skb,
bool last)
{
struct rxrpc_skb_priv *sp = rxrpc_skb(skb);
rxrpc_seq_t seq = sp->hdr.seq;
int ret, ix;
u8 annotation = RXRPC_TX_ANNO_UNACK;
_net("queue skb %p [%d]", skb, seq);
ASSERTCMP(seq, ==, call->tx_top + 1);
if (last)
annotation |= RXRPC_TX_ANNO_LAST;
skb->tstamp = ktime_get_real();
ix = seq & RXRPC_RXTX_BUFF_MASK;
rxrpc_get_skb(skb, rxrpc_skb_tx_got);
call->rxtx_annotations[ix] = annotation;
smp_wmb();
call->rxtx_buffer[ix] = skb;
call->tx_top = seq;
if (last)
trace_rxrpc_transmit(call, rxrpc_transmit_queue_last);
else
trace_rxrpc_transmit(call, rxrpc_transmit_queue);
if (last || call->state == RXRPC_CALL_SERVER_ACK_REQUEST) {
_debug("________awaiting reply/ACK__________");
write_lock_bh(&call->state_lock);
switch (call->state) {
case RXRPC_CALL_CLIENT_SEND_REQUEST:
call->state = RXRPC_CALL_CLIENT_AWAIT_REPLY;
break;
case RXRPC_CALL_SERVER_ACK_REQUEST:
call->state = RXRPC_CALL_SERVER_SEND_REPLY;
call->ack_at = call->expire_at;
if (call->ackr_reason == RXRPC_ACK_DELAY)
call->ackr_reason = 0;
__rxrpc_set_timer(call, rxrpc_timer_init_for_send_reply,
ktime_get_real());
if (!last)
break;
case RXRPC_CALL_SERVER_SEND_REPLY:
call->state = RXRPC_CALL_SERVER_AWAIT_ACK;
break;
default:
break;
}
write_unlock_bh(&call->state_lock);
}
if (seq == 1 && rxrpc_is_client_call(call))
rxrpc_expose_client_call(call);
ret = rxrpc_send_data_packet(call, skb, false);
if (ret < 0) {
_debug("need instant resend %d", ret);
rxrpc_instant_resend(call, ix);
} else {
ktime_t now = ktime_get_real(), resend_at;
resend_at = ktime_add_ms(now, rxrpc_resend_timeout);
if (ktime_before(resend_at, call->resend_at)) {
call->resend_at = resend_at;
rxrpc_set_timer(call, rxrpc_timer_set_for_send, now);
}
}
rxrpc_free_skb(skb, rxrpc_skb_tx_freed);
_leave("");
}
static int rxrpc_send_data(struct rxrpc_sock *rx,
struct rxrpc_call *call,
struct msghdr *msg, size_t len)
{
struct rxrpc_skb_priv *sp;
struct sk_buff *skb;
struct sock *sk = &rx->sk;
long timeo;
bool more;
int ret, copied;
timeo = sock_sndtimeo(sk, msg->msg_flags & MSG_DONTWAIT);
sk_clear_bit(SOCKWQ_ASYNC_NOSPACE, sk);
if (sk->sk_err || (sk->sk_shutdown & SEND_SHUTDOWN))
return -EPIPE;
more = msg->msg_flags & MSG_MORE;
skb = call->tx_pending;
call->tx_pending = NULL;
rxrpc_see_skb(skb, rxrpc_skb_tx_seen);
copied = 0;
do {
if (call->ackr_reason == RXRPC_ACK_PING_RESPONSE)
rxrpc_send_ack_packet(call, false);
if (!skb) {
size_t size, chunk, max, space;
_debug("alloc");
if (call->tx_top - call->tx_hard_ack >=
min_t(unsigned int, call->tx_winsize,
call->cong_cwnd + call->cong_extra)) {
ret = -EAGAIN;
if (msg->msg_flags & MSG_DONTWAIT)
goto maybe_error;
ret = rxrpc_wait_for_tx_window(rx, call,
&timeo);
if (ret < 0)
goto maybe_error;
}
max = RXRPC_JUMBO_DATALEN;
max -= call->conn->security_size;
max &= ~(call->conn->size_align - 1UL);
chunk = max;
if (chunk > msg_data_left(msg) && !more)
chunk = msg_data_left(msg);
space = chunk + call->conn->size_align;
space &= ~(call->conn->size_align - 1UL);
size = space + call->conn->security_size;
_debug("SIZE: %zu/%zu/%zu", chunk, space, size);
skb = sock_alloc_send_skb(
sk, size, msg->msg_flags & MSG_DONTWAIT, &ret);
if (!skb)
goto maybe_error;
rxrpc_new_skb(skb, rxrpc_skb_tx_new);
_debug("ALLOC SEND %p", skb);
ASSERTCMP(skb->mark, ==, 0);
_debug("HS: %u", call->conn->security_size);
skb_reserve(skb, call->conn->security_size);
skb->len += call->conn->security_size;
sp = rxrpc_skb(skb);
sp->remain = chunk;
if (sp->remain > skb_tailroom(skb))
sp->remain = skb_tailroom(skb);
_net("skb: hr %d, tr %d, hl %d, rm %d",
skb_headroom(skb),
skb_tailroom(skb),
skb_headlen(skb),
sp->remain);
skb->ip_summed = CHECKSUM_UNNECESSARY;
}
_debug("append");
sp = rxrpc_skb(skb);
if (msg_data_left(msg) > 0) {
int copy = skb_tailroom(skb);
ASSERTCMP(copy, >, 0);
if (copy > msg_data_left(msg))
copy = msg_data_left(msg);
if (copy > sp->remain)
copy = sp->remain;
_debug("add");
ret = skb_add_data(skb, &msg->msg_iter, copy);
_debug("added");
if (ret < 0)
goto efault;
sp->remain -= copy;
skb->mark += copy;
copied += copy;
}
if (call->state == RXRPC_CALL_COMPLETE)
goto call_terminated;
if (sp->remain <= 0 ||
(msg_data_left(msg) == 0 && !more)) {
struct rxrpc_connection *conn = call->conn;
uint32_t seq;
size_t pad;
if (conn->security_ix) {
pad = conn->security_size + skb->mark;
pad = conn->size_align - pad;
pad &= conn->size_align - 1;
_debug("pad %zu", pad);
if (pad)
memset(skb_put(skb, pad), 0, pad);
}
seq = call->tx_top + 1;
sp->hdr.seq = seq;
sp->hdr._rsvd = 0;
sp->hdr.flags = conn->out_clientflag;
if (msg_data_left(msg) == 0 && !more)
sp->hdr.flags |= RXRPC_LAST_PACKET;
else if (call->tx_top - call->tx_hard_ack <
call->tx_winsize)
sp->hdr.flags |= RXRPC_MORE_PACKETS;
ret = conn->security->secure_packet(
call, skb, skb->mark, skb->head);
if (ret < 0)
goto out;
rxrpc_queue_packet(call, skb, !msg_data_left(msg) && !more);
skb = NULL;
}
} while (msg_data_left(msg) > 0);
success:
ret = copied;
out:
call->tx_pending = skb;
_leave(" = %d", ret);
return ret;
call_terminated:
rxrpc_free_skb(skb, rxrpc_skb_tx_freed);
_leave(" = %d", -call->error);
return -call->error;
maybe_error:
if (copied)
goto success;
goto out;
efault:
ret = -EFAULT;
goto out;
}
static int rxrpc_sendmsg_cmsg(struct msghdr *msg,
unsigned long *user_call_ID,
enum rxrpc_command *command,
u32 *abort_code,
bool *_exclusive)
{
struct cmsghdr *cmsg;
bool got_user_ID = false;
int len;
*command = RXRPC_CMD_SEND_DATA;
if (msg->msg_controllen == 0)
return -EINVAL;
for_each_cmsghdr(cmsg, msg) {
if (!CMSG_OK(msg, cmsg))
return -EINVAL;
len = cmsg->cmsg_len - sizeof(struct cmsghdr);
_debug("CMSG %d, %d, %d",
cmsg->cmsg_level, cmsg->cmsg_type, len);
if (cmsg->cmsg_level != SOL_RXRPC)
continue;
switch (cmsg->cmsg_type) {
case RXRPC_USER_CALL_ID:
if (msg->msg_flags & MSG_CMSG_COMPAT) {
if (len != sizeof(u32))
return -EINVAL;
*user_call_ID = *(u32 *) CMSG_DATA(cmsg);
} else {
if (len != sizeof(unsigned long))
return -EINVAL;
*user_call_ID = *(unsigned long *)
CMSG_DATA(cmsg);
}
_debug("User Call ID %lx", *user_call_ID);
got_user_ID = true;
break;
case RXRPC_ABORT:
if (*command != RXRPC_CMD_SEND_DATA)
return -EINVAL;
*command = RXRPC_CMD_SEND_ABORT;
if (len != sizeof(*abort_code))
return -EINVAL;
*abort_code = *(unsigned int *) CMSG_DATA(cmsg);
_debug("Abort %x", *abort_code);
if (*abort_code == 0)
return -EINVAL;
break;
case RXRPC_ACCEPT:
if (*command != RXRPC_CMD_SEND_DATA)
return -EINVAL;
*command = RXRPC_CMD_ACCEPT;
if (len != 0)
return -EINVAL;
break;
case RXRPC_EXCLUSIVE_CALL:
*_exclusive = true;
if (len != 0)
return -EINVAL;
break;
default:
return -EINVAL;
}
}
if (!got_user_ID)
return -EINVAL;
_leave(" = 0");
return 0;
}
static struct rxrpc_call *
rxrpc_new_client_call_for_sendmsg(struct rxrpc_sock *rx, struct msghdr *msg,
unsigned long user_call_ID, bool exclusive)
__releases(&rx->sk.sk_lock.slock
int rxrpc_do_sendmsg(struct rxrpc_sock *rx, struct msghdr *msg, size_t len)
__releases(&rx->sk.sk_lock.slock
int rxrpc_kernel_send_data(struct socket *sock, struct rxrpc_call *call,
struct msghdr *msg, size_t len)
{
int ret;
_enter("{%d,%s},", call->debug_id, rxrpc_call_states[call->state]);
ASSERTCMP(msg->msg_name, ==, NULL);
ASSERTCMP(msg->msg_control, ==, NULL);
mutex_lock(&call->user_mutex);
_debug("CALL %d USR %lx ST %d on CONN %p",
call->debug_id, call->user_call_ID, call->state, call->conn);
switch (READ_ONCE(call->state)) {
case RXRPC_CALL_CLIENT_SEND_REQUEST:
case RXRPC_CALL_SERVER_ACK_REQUEST:
case RXRPC_CALL_SERVER_SEND_REPLY:
ret = rxrpc_send_data(rxrpc_sk(sock->sk), call, msg, len);
break;
case RXRPC_CALL_COMPLETE:
read_lock_bh(&call->state_lock);
ret = -call->error;
read_unlock_bh(&call->state_lock);
break;
default:
ret = -EPROTO;
break;
}
mutex_unlock(&call->user_mutex);
_leave(" = %d", ret);
return ret;
}
void rxrpc_kernel_abort_call(struct socket *sock, struct rxrpc_call *call,
u32 abort_code, int error, const char *why)
{
_enter("{%d},%d,%d,%s", call->debug_id, abort_code, error, why);
mutex_lock(&call->user_mutex);
if (rxrpc_abort_call(why, call, 0, abort_code, error))
rxrpc_send_abort_packet(call);
mutex_unlock(&call->user_mutex);
_leave("");
}
