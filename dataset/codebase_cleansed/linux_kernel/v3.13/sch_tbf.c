static u64 psched_ns_t2l(const struct psched_ratecfg *r,
u64 time_in_ns)
{
u64 len = time_in_ns * r->rate_bytes_ps;
do_div(len, NSEC_PER_SEC);
if (unlikely(r->linklayer == TC_LINKLAYER_ATM)) {
do_div(len, 53);
len = len * 48;
}
if (len > r->overhead)
len -= r->overhead;
else
len = 0;
return len;
}
static unsigned int skb_gso_seglen(const struct sk_buff *skb)
{
unsigned int hdr_len = skb_transport_header(skb) - skb_mac_header(skb);
const struct skb_shared_info *shinfo = skb_shinfo(skb);
if (likely(shinfo->gso_type & (SKB_GSO_TCPV4 | SKB_GSO_TCPV6)))
hdr_len += tcp_hdrlen(skb);
else
hdr_len += sizeof(struct udphdr);
return hdr_len + shinfo->gso_size;
}
static int tbf_segment(struct sk_buff *skb, struct Qdisc *sch)
{
struct tbf_sched_data *q = qdisc_priv(sch);
struct sk_buff *segs, *nskb;
netdev_features_t features = netif_skb_features(skb);
int ret, nb;
segs = skb_gso_segment(skb, features & ~NETIF_F_GSO_MASK);
if (IS_ERR_OR_NULL(segs))
return qdisc_reshape_fail(skb, sch);
nb = 0;
while (segs) {
nskb = segs->next;
segs->next = NULL;
qdisc_skb_cb(segs)->pkt_len = segs->len;
ret = qdisc_enqueue(segs, q->qdisc);
if (ret != NET_XMIT_SUCCESS) {
if (net_xmit_drop_count(ret))
sch->qstats.drops++;
} else {
nb++;
}
segs = nskb;
}
sch->q.qlen += nb;
if (nb > 1)
qdisc_tree_decrease_qlen(sch, 1 - nb);
consume_skb(skb);
return nb > 0 ? NET_XMIT_SUCCESS : NET_XMIT_DROP;
}
static int tbf_enqueue(struct sk_buff *skb, struct Qdisc *sch)
{
struct tbf_sched_data *q = qdisc_priv(sch);
int ret;
if (qdisc_pkt_len(skb) > q->max_size) {
if (skb_is_gso(skb) && skb_gso_seglen(skb) <= q->max_size)
return tbf_segment(skb, sch);
return qdisc_reshape_fail(skb, sch);
}
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
s64 now;
s64 toks;
s64 ptoks = 0;
unsigned int len = qdisc_pkt_len(skb);
now = ktime_to_ns(ktime_get());
toks = min_t(s64, now - q->t_c, q->buffer);
if (q->peak_present) {
ptoks = toks + q->ptokens;
if (ptoks > q->mtu)
ptoks = q->mtu;
ptoks -= (s64) psched_l2t_ns(&q->peak, len);
}
toks += q->tokens;
if (toks > q->buffer)
toks = q->buffer;
toks -= (s64) psched_l2t_ns(&q->rate, len);
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
qdisc_watchdog_schedule_ns(&q->watchdog,
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
q->t_c = ktime_to_ns(ktime_get());
q->tokens = q->buffer;
q->ptokens = q->mtu;
qdisc_watchdog_cancel(&q->watchdog);
}
static int tbf_change(struct Qdisc *sch, struct nlattr *opt)
{
int err;
struct tbf_sched_data *q = qdisc_priv(sch);
struct nlattr *tb[TCA_TBF_MAX + 1];
struct tc_tbf_qopt *qopt;
struct Qdisc *child = NULL;
struct psched_ratecfg rate;
struct psched_ratecfg peak;
u64 max_size;
s64 buffer, mtu;
u64 rate64 = 0, prate64 = 0;
err = nla_parse_nested(tb, TCA_TBF_MAX, opt, tbf_policy);
if (err < 0)
return err;
err = -EINVAL;
if (tb[TCA_TBF_PARMS] == NULL)
goto done;
qopt = nla_data(tb[TCA_TBF_PARMS]);
if (qopt->rate.linklayer == TC_LINKLAYER_UNAWARE)
qdisc_put_rtab(qdisc_get_rtab(&qopt->rate,
tb[TCA_TBF_RTAB]));
if (qopt->peakrate.linklayer == TC_LINKLAYER_UNAWARE)
qdisc_put_rtab(qdisc_get_rtab(&qopt->peakrate,
tb[TCA_TBF_PTAB]));
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
buffer = min_t(u64, PSCHED_TICKS2NS(qopt->buffer), ~0U);
mtu = min_t(u64, PSCHED_TICKS2NS(qopt->mtu), ~0U);
if (tb[TCA_TBF_RATE64])
rate64 = nla_get_u64(tb[TCA_TBF_RATE64]);
psched_ratecfg_precompute(&rate, &qopt->rate, rate64);
max_size = min_t(u64, psched_ns_t2l(&rate, buffer), ~0U);
if (qopt->peakrate.rate) {
if (tb[TCA_TBF_PRATE64])
prate64 = nla_get_u64(tb[TCA_TBF_PRATE64]);
psched_ratecfg_precompute(&peak, &qopt->peakrate, prate64);
if (peak.rate_bytes_ps <= rate.rate_bytes_ps) {
pr_warn_ratelimited("sch_tbf: peakrate %llu is lower than or equals to rate %llu !\n",
peak.rate_bytes_ps, rate.rate_bytes_ps);
err = -EINVAL;
goto done;
}
max_size = min_t(u64, max_size, psched_ns_t2l(&peak, mtu));
}
if (max_size < psched_mtu(qdisc_dev(sch)))
pr_warn_ratelimited("sch_tbf: burst %llu is lower than device %s mtu (%u) !\n",
max_size, qdisc_dev(sch)->name,
psched_mtu(qdisc_dev(sch)));
if (!max_size) {
err = -EINVAL;
goto done;
}
sch_tree_lock(sch);
if (child) {
qdisc_tree_decrease_qlen(q->qdisc, q->qdisc->q.qlen);
qdisc_destroy(q->qdisc);
q->qdisc = child;
}
q->limit = qopt->limit;
q->mtu = PSCHED_TICKS2NS(qopt->mtu);
q->max_size = max_size;
q->buffer = PSCHED_TICKS2NS(qopt->buffer);
q->tokens = q->buffer;
q->ptokens = q->mtu;
memcpy(&q->rate, &rate, sizeof(struct psched_ratecfg));
if (qopt->peakrate.rate) {
memcpy(&q->peak, &peak, sizeof(struct psched_ratecfg));
q->peak_present = true;
} else {
q->peak_present = false;
}
sch_tree_unlock(sch);
err = 0;
done:
return err;
}
static int tbf_init(struct Qdisc *sch, struct nlattr *opt)
{
struct tbf_sched_data *q = qdisc_priv(sch);
if (opt == NULL)
return -EINVAL;
q->t_c = ktime_to_ns(ktime_get());
qdisc_watchdog_init(&q->watchdog, sch);
q->qdisc = &noop_qdisc;
return tbf_change(sch, opt);
}
static void tbf_destroy(struct Qdisc *sch)
{
struct tbf_sched_data *q = qdisc_priv(sch);
qdisc_watchdog_cancel(&q->watchdog);
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
psched_ratecfg_getrate(&opt.rate, &q->rate);
if (q->peak_present)
psched_ratecfg_getrate(&opt.peakrate, &q->peak);
else
memset(&opt.peakrate, 0, sizeof(opt.peakrate));
opt.mtu = PSCHED_NS2TICKS(q->mtu);
opt.buffer = PSCHED_NS2TICKS(q->buffer);
if (nla_put(skb, TCA_TBF_PARMS, sizeof(opt), &opt))
goto nla_put_failure;
if (q->rate.rate_bytes_ps >= (1ULL << 32) &&
nla_put_u64(skb, TCA_TBF_RATE64, q->rate.rate_bytes_ps))
goto nla_put_failure;
if (q->peak_present &&
q->peak.rate_bytes_ps >= (1ULL << 32) &&
nla_put_u64(skb, TCA_TBF_PRATE64, q->peak.rate_bytes_ps))
goto nla_put_failure;
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
