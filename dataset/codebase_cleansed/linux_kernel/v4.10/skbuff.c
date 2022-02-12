void rxrpc_new_skb(struct sk_buff *skb, enum rxrpc_skb_trace op)
{
const void *here = __builtin_return_address(0);
int n = atomic_inc_return(select_skb_count(op));
trace_rxrpc_skb(skb, op, atomic_read(&skb->users), n, here);
}
void rxrpc_see_skb(struct sk_buff *skb, enum rxrpc_skb_trace op)
{
const void *here = __builtin_return_address(0);
if (skb) {
int n = atomic_read(select_skb_count(op));
trace_rxrpc_skb(skb, op, atomic_read(&skb->users), n, here);
}
}
void rxrpc_get_skb(struct sk_buff *skb, enum rxrpc_skb_trace op)
{
const void *here = __builtin_return_address(0);
int n = atomic_inc_return(select_skb_count(op));
trace_rxrpc_skb(skb, op, atomic_read(&skb->users), n, here);
skb_get(skb);
}
void rxrpc_free_skb(struct sk_buff *skb, enum rxrpc_skb_trace op)
{
const void *here = __builtin_return_address(0);
if (skb) {
int n;
CHECK_SLAB_OKAY(&skb->users);
n = atomic_dec_return(select_skb_count(op));
trace_rxrpc_skb(skb, op, atomic_read(&skb->users), n, here);
kfree_skb(skb);
}
}
void rxrpc_lose_skb(struct sk_buff *skb, enum rxrpc_skb_trace op)
{
const void *here = __builtin_return_address(0);
if (skb) {
int n;
CHECK_SLAB_OKAY(&skb->users);
n = atomic_dec_return(select_skb_count(op));
trace_rxrpc_skb(skb, op, atomic_read(&skb->users), n, here);
kfree_skb(skb);
}
}
void rxrpc_purge_queue(struct sk_buff_head *list)
{
const void *here = __builtin_return_address(0);
struct sk_buff *skb;
while ((skb = skb_dequeue((list))) != NULL) {
int n = atomic_dec_return(select_skb_count(rxrpc_skb_rx_purged));
trace_rxrpc_skb(skb, rxrpc_skb_rx_purged,
atomic_read(&skb->users), n, here);
kfree_skb(skb);
}
}
