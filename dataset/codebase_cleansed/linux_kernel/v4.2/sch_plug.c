static int plug_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct plug_sched_data *q = qdisc_priv(sch);
if (likely(sch->qstats.backlog + skb->len <= q->limit)) {
if (!q->unplug_indefinite)
q->pkts_current_epoch++;
return qdisc_enqueue_tail(skb, sch);
}
return qdisc_reshape_fail(skb, sch);
}
static struct sk_buff *plug_dequeue(struct Qdisc *sch)
{
struct plug_sched_data *q = qdisc_priv(sch);
if (qdisc_is_throttled(sch))
return NULL;
if (!q->unplug_indefinite) {
if (!q->pkts_to_release) {
qdisc_throttled(sch);
return NULL;
}
q->pkts_to_release--;
}
return qdisc_dequeue_head(sch);
}
static int plug_init(struct Qdisc *sch, struct nlattr *opt)
{
struct plug_sched_data *q = qdisc_priv(sch);
q->pkts_current_epoch = 0;
q->pkts_last_epoch = 0;
q->pkts_to_release = 0;
q->unplug_indefinite = false;
if (opt == NULL) {
u32 pkt_limit = qdisc_dev(sch)->tx_queue_len ? : 100;
q->limit = pkt_limit * psched_mtu(qdisc_dev(sch));
} else {
struct tc_plug_qopt *ctl = nla_data(opt);
if (nla_len(opt) < sizeof(*ctl))
return -EINVAL;
q->limit = ctl->limit;
}
qdisc_throttled(sch);
return 0;
}
static int plug_change(struct Qdisc *sch, struct nlattr *opt)
{
struct plug_sched_data *q = qdisc_priv(sch);
struct tc_plug_qopt *msg;
if (opt == NULL)
return -EINVAL;
msg = nla_data(opt);
if (nla_len(opt) < sizeof(*msg))
return -EINVAL;
switch (msg->action) {
case TCQ_PLUG_BUFFER:
q->pkts_last_epoch = q->pkts_current_epoch;
q->pkts_current_epoch = 0;
if (q->unplug_indefinite)
qdisc_throttled(sch);
q->unplug_indefinite = false;
break;
case TCQ_PLUG_RELEASE_ONE:
q->pkts_to_release += q->pkts_last_epoch;
q->pkts_last_epoch = 0;
qdisc_unthrottled(sch);
netif_schedule_queue(sch->dev_queue);
break;
case TCQ_PLUG_RELEASE_INDEFINITE:
q->unplug_indefinite = true;
q->pkts_to_release = 0;
q->pkts_last_epoch = 0;
q->pkts_current_epoch = 0;
qdisc_unthrottled(sch);
netif_schedule_queue(sch->dev_queue);
break;
case TCQ_PLUG_LIMIT:
q->limit = msg->limit;
break;
default:
return -EINVAL;
}
return 0;
}
static int __init plug_module_init(void)
{
return register_qdisc(&plug_qdisc_ops);
}
static void __exit plug_module_exit(void)
{
unregister_qdisc(&plug_qdisc_ops);
}
