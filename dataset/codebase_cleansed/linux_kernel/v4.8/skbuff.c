static void rxrpc_request_final_ACK(struct rxrpc_call *call)
{
write_lock(&call->state_lock);
switch (call->state) {
case RXRPC_CALL_CLIENT_RECV_REPLY:
call->state = RXRPC_CALL_CLIENT_FINAL_ACK;
_debug("request final ACK");
rxrpc_get_call(call);
set_bit(RXRPC_CALL_EV_ACK_FINAL, &call->events);
if (try_to_del_timer_sync(&call->ack_timer) >= 0)
rxrpc_queue_call(call);
break;
case RXRPC_CALL_SERVER_RECV_REQUEST:
call->state = RXRPC_CALL_SERVER_ACK_REQUEST;
default:
break;
}
write_unlock(&call->state_lock);
}
static void rxrpc_hard_ACK_data(struct rxrpc_call *call,
struct rxrpc_skb_priv *sp)
{
int loop;
u32 seq;
spin_lock_bh(&call->lock);
_debug("hard ACK #%u", sp->hdr.seq);
for (loop = 0; loop < RXRPC_ACKR_WINDOW_ASZ; loop++) {
call->ackr_window[loop] >>= 1;
call->ackr_window[loop] |=
call->ackr_window[loop + 1] << (BITS_PER_LONG - 1);
}
seq = sp->hdr.seq;
ASSERTCMP(seq, ==, call->rx_data_eaten + 1);
call->rx_data_eaten = seq;
if (call->ackr_win_top < UINT_MAX)
call->ackr_win_top++;
ASSERTIFCMP(call->state <= RXRPC_CALL_COMPLETE,
call->rx_data_post, >=, call->rx_data_recv);
ASSERTIFCMP(call->state <= RXRPC_CALL_COMPLETE,
call->rx_data_recv, >=, call->rx_data_eaten);
if (sp->hdr.flags & RXRPC_LAST_PACKET) {
rxrpc_request_final_ACK(call);
} else if (atomic_dec_and_test(&call->ackr_not_idle) &&
test_and_clear_bit(RXRPC_CALL_TX_SOFT_ACK, &call->flags)) {
_debug("send Rx idle ACK");
__rxrpc_propose_ACK(call, RXRPC_ACK_IDLE, sp->hdr.serial,
false);
}
spin_unlock_bh(&call->lock);
}
void rxrpc_kernel_data_consumed(struct rxrpc_call *call, struct sk_buff *skb)
{
struct rxrpc_skb_priv *sp = rxrpc_skb(skb);
_enter("%d,%p{%u}", call->debug_id, skb, sp->hdr.seq);
ASSERTCMP(sp->call, ==, call);
ASSERTCMP(sp->hdr.type, ==, RXRPC_PACKET_TYPE_DATA);
ASSERTCMP(sp->hdr.seq, >=, call->rx_data_recv);
ASSERTCMP(sp->hdr.seq, <=, call->rx_data_recv + 1);
ASSERTCMP(sp->hdr.seq, >, call->rx_data_eaten);
call->rx_data_recv = sp->hdr.seq;
rxrpc_hard_ACK_data(call, sp);
}
void rxrpc_packet_destructor(struct sk_buff *skb)
{
struct rxrpc_skb_priv *sp = rxrpc_skb(skb);
struct rxrpc_call *call = sp->call;
_enter("%p{%p}", skb, call);
if (call) {
if (atomic_dec_return(&call->skb_count) < 0)
BUG();
rxrpc_put_call(call);
sp->call = NULL;
}
if (skb->sk)
sock_rfree(skb);
_leave("");
}
void rxrpc_kernel_free_skb(struct sk_buff *skb)
{
rxrpc_free_skb(skb);
}
