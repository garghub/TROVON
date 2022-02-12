static int blackhole_enqueue(struct sk_buff *skb, struct Qdisc *sch,
struct sk_buff **to_free)
{
qdisc_drop(skb, sch, to_free);
return NET_XMIT_SUCCESS;
}
static struct sk_buff *blackhole_dequeue(struct Qdisc *sch)
{
return NULL;
}
static int __init blackhole_init(void)
{
return register_qdisc(&blackhole_qdisc_ops);
}
