static void pie_params_init(struct pie_params *params)
{
params->alpha = 2;
params->beta = 20;
params->tupdate = usecs_to_jiffies(30 * USEC_PER_MSEC);
params->limit = 1000;
params->target = PSCHED_NS2TICKS(20 * NSEC_PER_MSEC);
params->ecn = false;
params->bytemode = false;
}
static void pie_vars_init(struct pie_vars *vars)
{
vars->dq_count = DQCOUNT_INVALID;
vars->avg_dq_rate = 0;
vars->burst_time = PSCHED_NS2TICKS(100 * NSEC_PER_MSEC);
}
static bool drop_early(struct Qdisc *sch, u32 packet_size)
{
struct pie_sched_data *q = qdisc_priv(sch);
u32 rnd;
u32 local_prob = q->vars.prob;
u32 mtu = psched_mtu(qdisc_dev(sch));
if (q->vars.burst_time > 0)
return false;
if ((q->vars.qdelay < q->params.target / 2)
&& (q->vars.prob < MAX_PROB / 5))
return false;
if (sch->qstats.backlog < 2 * mtu)
return false;
if (q->params.bytemode && packet_size <= mtu)
local_prob = (local_prob / mtu) * packet_size;
else
local_prob = q->vars.prob;
rnd = prandom_u32();
if (rnd < local_prob)
return true;
return false;
}
static int pie_qdisc_enqueue(struct sk_buff *skb, struct Qdisc *sch,
struct sk_buff **to_free)
{
struct pie_sched_data *q = qdisc_priv(sch);
bool enqueue = false;
if (unlikely(qdisc_qlen(sch) >= sch->limit)) {
q->stats.overlimit++;
goto out;
}
if (!drop_early(sch, skb->len)) {
enqueue = true;
} else if (q->params.ecn && (q->vars.prob <= MAX_PROB / 10) &&
INET_ECN_set_ce(skb)) {
q->stats.ecn_mark++;
enqueue = true;
}
if (enqueue) {
q->stats.packets_in++;
if (qdisc_qlen(sch) > q->stats.maxq)
q->stats.maxq = qdisc_qlen(sch);
return qdisc_enqueue_tail(skb, sch);
}
out:
q->stats.dropped++;
return qdisc_drop(skb, sch, to_free);
}
static int pie_change(struct Qdisc *sch, struct nlattr *opt)
{
struct pie_sched_data *q = qdisc_priv(sch);
struct nlattr *tb[TCA_PIE_MAX + 1];
unsigned int qlen, dropped = 0;
int err;
if (!opt)
return -EINVAL;
err = nla_parse_nested(tb, TCA_PIE_MAX, opt, pie_policy);
if (err < 0)
return err;
sch_tree_lock(sch);
if (tb[TCA_PIE_TARGET]) {
u32 target = nla_get_u32(tb[TCA_PIE_TARGET]);
q->params.target = PSCHED_NS2TICKS((u64)target * NSEC_PER_USEC);
}
if (tb[TCA_PIE_TUPDATE])
q->params.tupdate = usecs_to_jiffies(nla_get_u32(tb[TCA_PIE_TUPDATE]));
if (tb[TCA_PIE_LIMIT]) {
u32 limit = nla_get_u32(tb[TCA_PIE_LIMIT]);
q->params.limit = limit;
sch->limit = limit;
}
if (tb[TCA_PIE_ALPHA])
q->params.alpha = nla_get_u32(tb[TCA_PIE_ALPHA]);
if (tb[TCA_PIE_BETA])
q->params.beta = nla_get_u32(tb[TCA_PIE_BETA]);
if (tb[TCA_PIE_ECN])
q->params.ecn = nla_get_u32(tb[TCA_PIE_ECN]);
if (tb[TCA_PIE_BYTEMODE])
q->params.bytemode = nla_get_u32(tb[TCA_PIE_BYTEMODE]);
qlen = sch->q.qlen;
while (sch->q.qlen > sch->limit) {
struct sk_buff *skb = __qdisc_dequeue_head(&sch->q);
dropped += qdisc_pkt_len(skb);
qdisc_qstats_backlog_dec(sch, skb);
rtnl_qdisc_drop(skb, sch);
}
qdisc_tree_reduce_backlog(sch, qlen - sch->q.qlen, dropped);
sch_tree_unlock(sch);
return 0;
}
static void pie_process_dequeue(struct Qdisc *sch, struct sk_buff *skb)
{
struct pie_sched_data *q = qdisc_priv(sch);
int qlen = sch->qstats.backlog;
if (qlen >= QUEUE_THRESHOLD && q->vars.dq_count == DQCOUNT_INVALID) {
q->vars.dq_tstamp = psched_get_time();
q->vars.dq_count = 0;
}
if (q->vars.dq_count != DQCOUNT_INVALID) {
q->vars.dq_count += skb->len;
if (q->vars.dq_count >= QUEUE_THRESHOLD) {
psched_time_t now = psched_get_time();
u32 dtime = now - q->vars.dq_tstamp;
u32 count = q->vars.dq_count << PIE_SCALE;
if (dtime == 0)
return;
count = count / dtime;
if (q->vars.avg_dq_rate == 0)
q->vars.avg_dq_rate = count;
else
q->vars.avg_dq_rate =
(q->vars.avg_dq_rate -
(q->vars.avg_dq_rate >> 3)) + (count >> 3);
if (qlen < QUEUE_THRESHOLD)
q->vars.dq_count = DQCOUNT_INVALID;
else {
q->vars.dq_count = 0;
q->vars.dq_tstamp = psched_get_time();
}
if (q->vars.burst_time > 0) {
if (q->vars.burst_time > dtime)
q->vars.burst_time -= dtime;
else
q->vars.burst_time = 0;
}
}
}
}
static void calculate_probability(struct Qdisc *sch)
{
struct pie_sched_data *q = qdisc_priv(sch);
u32 qlen = sch->qstats.backlog;
psched_time_t qdelay = 0;
psched_time_t qdelay_old = q->vars.qdelay;
s32 delta = 0;
u32 oldprob;
u32 alpha, beta;
bool update_prob = true;
q->vars.qdelay_old = q->vars.qdelay;
if (q->vars.avg_dq_rate > 0)
qdelay = (qlen << PIE_SCALE) / q->vars.avg_dq_rate;
else
qdelay = 0;
if (qdelay == 0 && qlen != 0)
update_prob = false;
if (q->vars.prob < MAX_PROB / 100) {
alpha =
(q->params.alpha * (MAX_PROB / PSCHED_TICKS_PER_SEC)) >> 7;
beta =
(q->params.beta * (MAX_PROB / PSCHED_TICKS_PER_SEC)) >> 7;
} else if (q->vars.prob < MAX_PROB / 10) {
alpha =
(q->params.alpha * (MAX_PROB / PSCHED_TICKS_PER_SEC)) >> 5;
beta =
(q->params.beta * (MAX_PROB / PSCHED_TICKS_PER_SEC)) >> 5;
} else {
alpha =
(q->params.alpha * (MAX_PROB / PSCHED_TICKS_PER_SEC)) >> 4;
beta =
(q->params.beta * (MAX_PROB / PSCHED_TICKS_PER_SEC)) >> 4;
}
delta += alpha * ((qdelay - q->params.target));
delta += beta * ((qdelay - qdelay_old));
oldprob = q->vars.prob;
if (delta > (s32) (MAX_PROB / (100 / 2)) &&
q->vars.prob >= MAX_PROB / 10)
delta = (MAX_PROB / 100) * 2;
if (qdelay > (PSCHED_NS2TICKS(250 * NSEC_PER_MSEC)))
delta += MAX_PROB / (100 / 2);
q->vars.prob += delta;
if (delta > 0) {
if (q->vars.prob < oldprob) {
q->vars.prob = MAX_PROB;
update_prob = false;
}
} else {
if (q->vars.prob > oldprob)
q->vars.prob = 0;
}
if ((qdelay == 0) && (qdelay_old == 0) && update_prob)
q->vars.prob = (q->vars.prob * 98) / 100;
q->vars.qdelay = qdelay;
q->vars.qlen_old = qlen;
if ((q->vars.qdelay < q->params.target / 2) &&
(q->vars.qdelay_old < q->params.target / 2) &&
(q->vars.prob == 0) &&
(q->vars.avg_dq_rate > 0))
pie_vars_init(&q->vars);
}
static void pie_timer(unsigned long arg)
{
struct Qdisc *sch = (struct Qdisc *)arg;
struct pie_sched_data *q = qdisc_priv(sch);
spinlock_t *root_lock = qdisc_lock(qdisc_root_sleeping(sch));
spin_lock(root_lock);
calculate_probability(sch);
if (q->params.tupdate)
mod_timer(&q->adapt_timer, jiffies + q->params.tupdate);
spin_unlock(root_lock);
}
static int pie_init(struct Qdisc *sch, struct nlattr *opt)
{
struct pie_sched_data *q = qdisc_priv(sch);
pie_params_init(&q->params);
pie_vars_init(&q->vars);
sch->limit = q->params.limit;
setup_timer(&q->adapt_timer, pie_timer, (unsigned long)sch);
if (opt) {
int err = pie_change(sch, opt);
if (err)
return err;
}
mod_timer(&q->adapt_timer, jiffies + HZ / 2);
return 0;
}
static int pie_dump(struct Qdisc *sch, struct sk_buff *skb)
{
struct pie_sched_data *q = qdisc_priv(sch);
struct nlattr *opts;
opts = nla_nest_start(skb, TCA_OPTIONS);
if (opts == NULL)
goto nla_put_failure;
if (nla_put_u32(skb, TCA_PIE_TARGET,
((u32) PSCHED_TICKS2NS(q->params.target)) /
NSEC_PER_USEC) ||
nla_put_u32(skb, TCA_PIE_LIMIT, sch->limit) ||
nla_put_u32(skb, TCA_PIE_TUPDATE, jiffies_to_usecs(q->params.tupdate)) ||
nla_put_u32(skb, TCA_PIE_ALPHA, q->params.alpha) ||
nla_put_u32(skb, TCA_PIE_BETA, q->params.beta) ||
nla_put_u32(skb, TCA_PIE_ECN, q->params.ecn) ||
nla_put_u32(skb, TCA_PIE_BYTEMODE, q->params.bytemode))
goto nla_put_failure;
return nla_nest_end(skb, opts);
nla_put_failure:
nla_nest_cancel(skb, opts);
return -1;
}
static int pie_dump_stats(struct Qdisc *sch, struct gnet_dump *d)
{
struct pie_sched_data *q = qdisc_priv(sch);
struct tc_pie_xstats st = {
.prob = q->vars.prob,
.delay = ((u32) PSCHED_TICKS2NS(q->vars.qdelay)) /
NSEC_PER_USEC,
.avg_dq_rate = q->vars.avg_dq_rate *
(PSCHED_TICKS_PER_SEC) >> PIE_SCALE,
.packets_in = q->stats.packets_in,
.overlimit = q->stats.overlimit,
.maxq = q->stats.maxq,
.dropped = q->stats.dropped,
.ecn_mark = q->stats.ecn_mark,
};
return gnet_stats_copy_app(d, &st, sizeof(st));
}
static struct sk_buff *pie_qdisc_dequeue(struct Qdisc *sch)
{
struct sk_buff *skb;
skb = qdisc_dequeue_head(sch);
if (!skb)
return NULL;
pie_process_dequeue(sch, skb);
return skb;
}
static void pie_reset(struct Qdisc *sch)
{
struct pie_sched_data *q = qdisc_priv(sch);
qdisc_reset_queue(sch);
pie_vars_init(&q->vars);
}
static void pie_destroy(struct Qdisc *sch)
{
struct pie_sched_data *q = qdisc_priv(sch);
q->params.tupdate = 0;
del_timer_sync(&q->adapt_timer);
}
static int __init pie_module_init(void)
{
return register_qdisc(&pie_qdisc_ops);
}
static void __exit pie_module_exit(void)
{
unregister_qdisc(&pie_qdisc_ops);
}
