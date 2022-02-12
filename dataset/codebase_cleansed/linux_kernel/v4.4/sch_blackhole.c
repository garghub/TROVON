static int blackhole_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
qdisc_drop(skb, sch);
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
