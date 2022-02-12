static int tbf_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct tbf_sched_data *q = qdisc_priv(sch);
int ret;
if (qdisc_pkt_len(skb) > q->max_size)
return qdisc_reshape_fail(skb, sch);
ret = qdisc_enqueue(skb, q->qdisc);
if (ret != NET_XMIT_SUCCESS) {
if (net_xmit_drop_count(ret))
sch->qstats.drops++;
return ret;
}
sch->q.qlen++;
return NET_XMIT_SUCCESS;
}
static unsigned int tbf_drop(struct Qdisc *sch)
{
struct tbf_sched_data *q = qdisc_priv(sch);
unsigned int len = 0;
if (q->qdisc->ops->drop && (len = q->qdisc->ops->drop(q->qdisc)) != 0) {
sch->q.qlen--;
sch->qstats.drops++;
}
return len;
}
static struct sk_buff *tbf_dequeue(struct Qdisc *sch)
{
struct tbf_sched_data *q = qdisc_priv(sch);
struct sk_buff *skb;
skb = q->qdisc->ops->peek(q->qdisc);
if (skb) {
psched_time_t now;
long toks;
long ptoks = 0;
unsigned int len = qdisc_pkt_len(skb);
now = psched_get_time();
toks = psched_tdiff_bounded(now, q->t_c, q->buffer);
if (q->P_tab) {
ptoks = toks + q->ptokens;
if (ptoks > (long)q->mtu)
ptoks = q->mtu;
ptoks -= L2T_P(q, len);
}
toks += q->tokens;
if (toks > (long)q->buffer)
toks = q->buffer;
toks -= L2T(q, len);
if ((toks|ptoks) >= 0) {
skb = qdisc_dequeue_peeked(q->qdisc);
if (unlikely(!skb))
return NULL;
q->t_c = now;
q->tokens = toks;
q->ptokens = ptoks;
sch->q.qlen--;
qdisc_unthrottled(sch);
qdisc_bstats_update(sch, skb);
return skb;
}
qdisc_watchdog_schedule(&q->watchdog,
now + max_t(long, -toks, -ptoks));
sch->qstats.overlimits++;
}
return NULL;
}
static void tbf_reset(struct Qdisc *sch)
{
struct tbf_sched_data *q = qdisc_priv(sch);
qdisc_reset(q->qdisc);
sch->q.qlen = 0;
q->t_c = psched_get_time();
q->tokens = q->buffer;
q->ptokens = q->mtu;
qdisc_watchdog_cancel(&q->watchdog);
}
static int tbf_change(struct Qdisc *sch, struct nlattr *opt)
{
int err;
struct tbf_sched_data *q = qdisc_priv(sch);
struct nlattr *tb[TCA_TBF_PTAB + 1];
struct tc_tbf_qopt *qopt;
struct qdisc_rate_table *rtab = NULL;
struct qdisc_rate_table *ptab = NULL;
struct Qdisc *child = NULL;
int max_size, n;
err = nla_parse_nested(tb, TCA_TBF_PTAB, opt, tbf_policy);
if (err < 0)
return err;
err = -EINVAL;
if (tb[TCA_TBF_PARMS] == NULL)
goto done;
qopt = nla_data(tb[TCA_TBF_PARMS]);
rtab = qdisc_get_rtab(&qopt->rate, tb[TCA_TBF_RTAB]);
if (rtab == NULL)
goto done;
if (qopt->peakrate.rate) {
if (qopt->peakrate.rate > qopt->rate.rate)
ptab = qdisc_get_rtab(&qopt->peakrate, tb[TCA_TBF_PTAB]);
if (ptab == NULL)
goto done;
}
for (n = 0; n < 256; n++)
if (rtab->data[n] > qopt->buffer)
break;
max_size = (n << qopt->rate.cell_log) - 1;
if (ptab) {
int size;
for (n = 0; n < 256; n++)
if (ptab->data[n] > qopt->mtu)
break;
size = (n << qopt->peakrate.cell_log) - 1;
if (size < max_size)
max_size = size;
}
if (max_size < 0)
goto done;
if (q->qdisc != &noop_qdisc) {
err = fifo_set_limit(q->qdisc, qopt->limit);
if (err)
goto done;
} else if (qopt->limit > 0) {
child = fifo_create_dflt(sch, &bfifo_qdisc_ops, qopt->limit);
if (IS_ERR(child)) {
err = PTR_ERR(child);
goto done;
}
}
sch_tree_lock(sch);
if (child) {
qdisc_tree_decrease_qlen(q->qdisc, q->qdisc->q.qlen);
qdisc_destroy(q->qdisc);
q->qdisc = child;
}
q->limit = qopt->limit;
q->mtu = qopt->mtu;
q->max_size = max_size;
q->buffer = qopt->buffer;
q->tokens = q->buffer;
q->ptokens = q->mtu;
swap(q->R_tab, rtab);
swap(q->P_tab, ptab);
sch_tree_unlock(sch);
err = 0;
done:
if (rtab)
qdisc_put_rtab(rtab);
if (ptab)
qdisc_put_rtab(ptab);
return err;
}
static int tbf_init(struct Qdisc *sch, struct nlattr *opt)
{
struct tbf_sched_data *q = qdisc_priv(sch);
if (opt == NULL)
return -EINVAL;
q->t_c = psched_get_time();
qdisc_watchdog_init(&q->watchdog, sch);
q->qdisc = &noop_qdisc;
return tbf_change(sch, opt);
}
static void tbf_destroy(struct Qdisc *sch)
{
struct tbf_sched_data *q = qdisc_priv(sch);
qdisc_watchdog_cancel(&q->watchdog);
if (q->P_tab)
qdisc_put_rtab(q->P_tab);
if (q->R_tab)
qdisc_put_rtab(q->R_tab);
qdisc_destroy(q->qdisc);
}
static int tbf_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct tbf_sched_data *q = qdisc_priv(sch);
struct nlattr *nest;
struct tc_tbf_qopt opt;
sch->qstats.backlog = q->qdisc->qstats.backlog;
nest = nla_nest_start(skb, TCA_OPTIONS);
if (nest == NULL)
goto nla_put_failure;
opt.limit = q->limit;
opt.rate = q->R_tab->rate;
if (q->P_tab)
opt.peakrate = q->P_tab->rate;
else
memset(&opt.peakrate, 0, sizeof(opt.peakrate));
opt.mtu = q->mtu;
opt.buffer = q->buffer;
NLA_PUT(skb, TCA_TBF_PARMS, sizeof(opt), &opt);
nla_nest_end(skb, nest);
return skb->len;
nla_put_failure:
nla_nest_cancel(skb, nest);
return -1;
}
static int tbf_dump_class(struct Qdisc *sch, unsigned long cl,
struct sk_buff *skb, struct tcmsg *tcm)
{
struct tbf_sched_data *q = qdisc_priv(sch);
tcm->tcm_handle |= TC_H_MIN(1);
tcm->tcm_info = q->qdisc->handle;
return 0;
}
static int tbf_graft(struct Qdisc *sch, unsigned long arg, struct Qdisc *new,
struct Qdisc **old)
{
struct tbf_sched_data *q = qdisc_priv(sch);
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
static struct Qdisc *tbf_leaf(struct Qdisc *sch, unsigned long arg)
{
struct tbf_sched_data *q = qdisc_priv(sch);
return q->qdisc;
}
static unsigned long tbf_get(struct Qdisc *sch, u32 classid)
{
return 1;
}
static void tbf_put(struct Qdisc *sch, unsigned long arg)
{
}
static void tbf_walk(struct Qdisc *sch, struct qdisc_walker *walker)
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
static int __init tbf_module_init(void)
{
return register_qdisc(&tbf_qdisc_ops);
}
static void __exit tbf_module_exit(void)
{
unregister_qdisc(&tbf_qdisc_ops);
}
