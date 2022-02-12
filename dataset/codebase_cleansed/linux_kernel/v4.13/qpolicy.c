static void qpolicy_simple_push(struct sock *sk, struct sk_buff *skb)
{
skb_queue_tail(&sk->sk_write_queue, skb);
}
static bool qpolicy_simple_full(struct sock *sk)
{
return dccp_sk(sk)->dccps_tx_qlen &&
sk->sk_write_queue.qlen >= dccp_sk(sk)->dccps_tx_qlen;
}
static struct sk_buff *qpolicy_simple_top(struct sock *sk)
{
return skb_peek(&sk->sk_write_queue);
}
static struct sk_buff *qpolicy_prio_best_skb(struct sock *sk)
{
struct sk_buff *skb, *best = NULL;
skb_queue_walk(&sk->sk_write_queue, skb)
if (best == NULL || skb->priority > best->priority)
best = skb;
return best;
}
static struct sk_buff *qpolicy_prio_worst_skb(struct sock *sk)
{
struct sk_buff *skb, *worst = NULL;
skb_queue_walk(&sk->sk_write_queue, skb)
if (worst == NULL || skb->priority < worst->priority)
worst = skb;
return worst;
}
static bool qpolicy_prio_full(struct sock *sk)
{
if (qpolicy_simple_full(sk))
dccp_qpolicy_drop(sk, qpolicy_prio_worst_skb(sk));
return false;
}
void dccp_qpolicy_push(struct sock *sk, struct sk_buff *skb)
{
qpol_table[dccp_sk(sk)->dccps_qpolicy].push(sk, skb);
}
bool dccp_qpolicy_full(struct sock *sk)
{
return qpol_table[dccp_sk(sk)->dccps_qpolicy].full(sk);
}
void dccp_qpolicy_drop(struct sock *sk, struct sk_buff *skb)
{
if (skb != NULL) {
skb_unlink(skb, &sk->sk_write_queue);
kfree_skb(skb);
}
}
struct sk_buff *dccp_qpolicy_top(struct sock *sk)
{
return qpol_table[dccp_sk(sk)->dccps_qpolicy].top(sk);
}
struct sk_buff *dccp_qpolicy_pop(struct sock *sk)
{
struct sk_buff *skb = dccp_qpolicy_top(sk);
if (skb != NULL) {
skb->priority = 0;
skb_unlink(skb, &sk->sk_write_queue);
}
return skb;
}
bool dccp_qpolicy_param_ok(struct sock *sk, __be32 param)
{
if (!param || (param & (param - 1)))
return false;
return (qpol_table[dccp_sk(sk)->dccps_qpolicy].params & param) == param;
}
