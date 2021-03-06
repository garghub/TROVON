static inline int red_use_ecn(struct red_sched_data *q)
{
return q->flags & TC_RED_ECN;
}
static inline int red_use_harddrop(struct red_sched_data *q)
{
return q->flags & TC_RED_HARDDROP;
}
static int red_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct red_sched_data *q = qdisc_priv(sch);
struct Qdisc *child = q->qdisc;
int ret;
q->parms.qavg = red_calc_qavg(&q->parms, child->qstats.backlog);
if (red_is_idling(&q->parms))
red_end_of_idle_period(&q->parms);
switch (red_action(&q->parms, q->parms.qavg)) {
case RED_DONT_MARK:
break;
case RED_PROB_MARK:
sch->qstats.overlimits++;
if (!red_use_ecn(q) || !INET_ECN_set_ce(skb)) {
q->stats.prob_drop++;
goto congestion_drop;
}
q->stats.prob_mark++;
break;
case RED_HARD_MARK:
sch->qstats.overlimits++;
if (red_use_harddrop(q) || !red_use_ecn(q) ||
!INET_ECN_set_ce(skb)) {
q->stats.forced_drop++;
goto congestion_drop;
}
q->stats.forced_mark++;
break;
}
ret = qdisc_enqueue(skb, child);
if (likely(ret == NET_XMIT_SUCCESS)) {
sch->q.qlen++;
} else if (net_xmit_drop_count(ret)) {
q->stats.pdrop++;
sch->qstats.drops++;
}
return ret;
congestion_drop:
qdisc_drop(skb, sch);
return NET_XMIT_CN;
}
static struct sk_buff *red_dequeue(struct Qdisc *sch)
{
struct sk_buff *skb;
struct red_sched_data *q = qdisc_priv(sch);
struct Qdisc *child = q->qdisc;
skb = child->dequeue(child);
if (skb) {
qdisc_bstats_update(sch, skb);
sch->q.qlen--;
} else {
if (!red_is_idling(&q->parms))
red_start_of_idle_period(&q->parms);
}
return skb;
}
static struct sk_buff *red_peek(struct Qdisc *sch)
{
struct red_sched_data *q = qdisc_priv(sch);
struct Qdisc *child = q->qdisc;
return child->ops->peek(child);
}
static unsigned int red_drop(struct Qdisc *sch)
{
struct red_sched_data *q = qdisc_priv(sch);
struct Qdisc *child = q->qdisc;
unsigned int len;
if (child->ops->drop && (len = child->ops->drop(child)) > 0) {
q->stats.other++;
sch->qstats.drops++;
sch->q.qlen--;
return len;
}
if (!red_is_idling(&q->parms))
red_start_of_idle_period(&q->parms);
return 0;
}
static void red_reset(struct Qdisc *sch)
{
struct red_sched_data *q = qdisc_priv(sch);
qdisc_reset(q->qdisc);
sch->q.qlen = 0;
red_restart(&q->parms);
}
static void red_destroy(struct Qdisc *sch)
{
struct red_sched_data *q = qdisc_priv(sch);
qdisc_destroy(q->qdisc);
}
static int red_change(struct Qdisc *sch, struct nlattr *opt)
{
struct red_sched_data *q = qdisc_priv(sch);
struct nlattr *tb[TCA_RED_MAX + 1];
struct tc_red_qopt *ctl;
struct Qdisc *child = NULL;
int err;
if (opt == NULL)
return -EINVAL;
err = nla_parse_nested(tb, TCA_RED_MAX, opt, red_policy);
if (err < 0)
return err;
if (tb[TCA_RED_PARMS] == NULL ||
tb[TCA_RED_STAB] == NULL)
return -EINVAL;
ctl = nla_data(tb[TCA_RED_PARMS]);
if (ctl->limit > 0) {
child = fifo_create_dflt(sch, &bfifo_qdisc_ops, ctl->limit);
if (IS_ERR(child))
return PTR_ERR(child);
}
sch_tree_lock(sch);
q->flags = ctl->flags;
q->limit = ctl->limit;
if (child) {
qdisc_tree_decrease_qlen(q->qdisc, q->qdisc->q.qlen);
qdisc_destroy(q->qdisc);
q->qdisc = child;
}
red_set_parms(&q->parms, ctl->qth_min, ctl->qth_max, ctl->Wlog,
ctl->Plog, ctl->Scell_log,
nla_data(tb[TCA_RED_STAB]));
if (!q->qdisc->q.qlen)
red_start_of_idle_period(&q->parms);
sch_tree_unlock(sch);
return 0;
}
static int red_init(struct Qdisc *sch, struct nlattr *opt)
{
struct red_sched_data *q = qdisc_priv(sch);
q->qdisc = &noop_qdisc;
return red_change(sch, opt);
}
static int red_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct red_sched_data *q = qdisc_priv(sch);
struct nlattr *opts = NULL;
struct tc_red_qopt opt = {
.limit = q->limit,
.flags = q->flags,
.qth_min = q->parms.qth_min >> q->parms.Wlog,
.qth_max = q->parms.qth_max >> q->parms.Wlog,
.Wlog = q->parms.Wlog,
.Plog = q->parms.Plog,
.Scell_log = q->parms.Scell_log,
};
sch->qstats.backlog = q->qdisc->qstats.backlog;
opts = nla_nest_start(skb, TCA_OPTIONS);
if (opts == NULL)
goto nla_put_failure;
NLA_PUT(skb, TCA_RED_PARMS, sizeof(opt), &opt);
return nla_nest_end(skb, opts);
nla_put_failure:
nla_nest_cancel(skb, opts);
return -EMSGSIZE;
}
static int red_dump_stats(struct Qdisc *sch, struct gnet_dump *d)
{
struct red_sched_data *q = qdisc_priv(sch);
struct tc_red_xstats st = {
.early = q->stats.prob_drop + q->stats.forced_drop,
.pdrop = q->stats.pdrop,
.other = q->stats.other,
.marked = q->stats.prob_mark + q->stats.forced_mark,
};
return gnet_stats_copy_app(d, &st, sizeof(st));
}
static int red_dump_class(struct Qdisc *sch, unsigned long cl,
struct sk_buff *skb, struct tcmsg *tcm)
{
struct red_sched_data *q = qdisc_priv(sch);
tcm->tcm_handle |= TC_H_MIN(1);
tcm->tcm_info = q->qdisc->handle;
return 0;
}
static int red_graft(struct Qdisc *sch, unsigned long arg, struct Qdisc *new,
struct Qdisc **old)
{
struct red_sched_data *q = qdisc_priv(sch);
if (new == NULL)
new = &noop_qdisc;
sch_tree_lock(sch);
*old = q->qdisc;
q->qdisc = new;
qdisc_tree_decrease_qlen(*old, (*old)->q.qlen);
qdisc_reset(*old);
sch_tree_unlock(sch);
return 0;
}
static struct Qdisc *red_leaf(struct Qdisc *sch, unsigned long arg)
{
struct red_sched_data *q = qdisc_priv(sch);
return q->qdisc;
}
static unsigned long red_get(struct Qdisc *sch, u32 classid)
{
return 1;
}
static void red_put(struct Qdisc *sch, unsigned long arg)
{
}
static void red_walk(struct Qdisc *sch, struct qdisc_walker *walker)
{
if (!walker->stop) {
if (walker->count >= walker->skip)
if (walker->fn(sch, 1, walker) < 0) {
walker->stop = 1;
return;
}
walker->count++;
}
}
static int __init red_module_init(void)
{
return register_qdisc(&red_qdisc_ops);
}
static void __exit red_module_exit(void)
{
unregister_qdisc(&red_qdisc_ops);
}
