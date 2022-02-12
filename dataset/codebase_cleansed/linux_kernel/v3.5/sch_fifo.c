static int bfifo_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
if (likely(sch->qstats.backlog + qdisc_pkt_len(skb) <= sch->limit))
return qdisc_enqueue_tail(skb, sch);
return qdisc_reshape_fail(skb, sch);
}
static int pfifo_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
if (likely(skb_queue_len(&sch->q) < sch->limit))
return qdisc_enqueue_tail(skb, sch);
return qdisc_reshape_fail(skb, sch);
}
static int pfifo_tail_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
if (likely(skb_queue_len(&sch->q) < sch->limit))
return qdisc_enqueue_tail(skb, sch);
__qdisc_queue_drop_head(sch, &sch->q);
sch->qstats.drops++;
qdisc_enqueue_tail(skb, sch);
return NET_XMIT_CN;
}
static int fifo_init(struct Qdisc *sch, struct nlattr *opt)
{
bool bypass;
bool is_bfifo = sch->ops == &bfifo_qdisc_ops;
if (opt == NULL) {
u32 limit = qdisc_dev(sch)->tx_queue_len ? : 1;
if (is_bfifo)
limit *= psched_mtu(qdisc_dev(sch));
sch->limit = limit;
} else {
struct tc_fifo_qopt *ctl = nla_data(opt);
if (nla_len(opt) < sizeof(*ctl))
return -EINVAL;
sch->limit = ctl->limit;
}
if (is_bfifo)
bypass = sch->limit >= psched_mtu(qdisc_dev(sch));
else
bypass = sch->limit >= 1;
if (bypass)
sch->flags |= TCQ_F_CAN_BYPASS;
else
sch->flags &= ~TCQ_F_CAN_BYPASS;
return 0;
}
static int fifo_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct tc_fifo_qopt opt = { .limit = sch->limit };
if (nla_put(skb, TCA_OPTIONS, sizeof(opt), &opt))
goto nla_put_failure;
return skb->len;
nla_put_failure:
return -1;
}
int fifo_set_limit(struct Qdisc *q, unsigned int limit)
{
struct nlattr *nla;
int ret = -ENOMEM;
if (strncmp(q->ops->id + 1, "fifo", 4) != 0)
return 0;
nla = kmalloc(nla_attr_size(sizeof(struct tc_fifo_qopt)), GFP_KERNEL);
if (nla) {
nla->nla_type = RTM_NEWQDISC;
nla->nla_len = nla_attr_size(sizeof(struct tc_fifo_qopt));
((struct tc_fifo_qopt *)nla_data(nla))->limit = limit;
ret = q->ops->change(q, nla);
kfree(nla);
}
return ret;
}
struct Qdisc *fifo_create_dflt(struct Qdisc *sch, struct Qdisc_ops *ops,
unsigned int limit)
{
struct Qdisc *q;
int err = -ENOMEM;
q = qdisc_create_dflt(sch->dev_queue, ops, TC_H_MAKE(sch->handle, 1));
if (q) {
err = fifo_set_limit(q, limit);
if (err < 0) {
qdisc_destroy(q);
q = NULL;
}
}
return q ? : ERR_PTR(err);
}
