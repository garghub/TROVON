static inline int
gnet_stats_copy(struct gnet_dump *d, int type, void *buf, int size)
{
if (nla_put(d->skb, type, size, buf))
goto nla_put_failure;
return 0;
nla_put_failure:
spin_unlock_bh(d->lock);
return -1;
}
int
gnet_stats_start_copy_compat(struct sk_buff *skb, int type, int tc_stats_type,
int xstats_type, spinlock_t *lock, struct gnet_dump *d)
__acquires(lock)
{
memset(d, 0, sizeof(*d));
spin_lock_bh(lock);
d->lock = lock;
if (type)
d->tail = (struct nlattr *)skb_tail_pointer(skb);
d->skb = skb;
d->compat_tc_stats = tc_stats_type;
d->compat_xstats = xstats_type;
if (d->tail)
return gnet_stats_copy(d, type, NULL, 0);
return 0;
}
int
gnet_stats_start_copy(struct sk_buff *skb, int type, spinlock_t *lock,
struct gnet_dump *d)
{
return gnet_stats_start_copy_compat(skb, type, 0, 0, lock, d);
}
static void
__gnet_stats_copy_basic_cpu(struct gnet_stats_basic_packed *bstats,
struct gnet_stats_basic_cpu __percpu *cpu)
{
int i;
for_each_possible_cpu(i) {
struct gnet_stats_basic_cpu *bcpu = per_cpu_ptr(cpu, i);
unsigned int start;
u64 bytes;
u32 packets;
do {
start = u64_stats_fetch_begin_irq(&bcpu->syncp);
bytes = bcpu->bstats.bytes;
packets = bcpu->bstats.packets;
} while (u64_stats_fetch_retry_irq(&bcpu->syncp, start));
bstats->bytes += bytes;
bstats->packets += packets;
}
}
void
__gnet_stats_copy_basic(struct gnet_stats_basic_packed *bstats,
struct gnet_stats_basic_cpu __percpu *cpu,
struct gnet_stats_basic_packed *b)
{
if (cpu) {
__gnet_stats_copy_basic_cpu(bstats, cpu);
} else {
bstats->bytes = b->bytes;
bstats->packets = b->packets;
}
}
int
gnet_stats_copy_basic(struct gnet_dump *d,
struct gnet_stats_basic_cpu __percpu *cpu,
struct gnet_stats_basic_packed *b)
{
struct gnet_stats_basic_packed bstats = {0};
__gnet_stats_copy_basic(&bstats, cpu, b);
if (d->compat_tc_stats) {
d->tc_stats.bytes = bstats.bytes;
d->tc_stats.packets = bstats.packets;
}
if (d->tail) {
struct gnet_stats_basic sb;
memset(&sb, 0, sizeof(sb));
sb.bytes = bstats.bytes;
sb.packets = bstats.packets;
return gnet_stats_copy(d, TCA_STATS_BASIC, &sb, sizeof(sb));
}
return 0;
}
int
gnet_stats_copy_rate_est(struct gnet_dump *d,
const struct gnet_stats_basic_packed *b,
struct gnet_stats_rate_est64 *r)
{
struct gnet_stats_rate_est est;
int res;
if (b && !gen_estimator_active(b, r))
return 0;
est.bps = min_t(u64, UINT_MAX, r->bps);
est.pps = r->pps;
if (d->compat_tc_stats) {
d->tc_stats.bps = est.bps;
d->tc_stats.pps = est.pps;
}
if (d->tail) {
res = gnet_stats_copy(d, TCA_STATS_RATE_EST, &est, sizeof(est));
if (res < 0 || est.bps == r->bps)
return res;
return gnet_stats_copy(d, TCA_STATS_RATE_EST64, r, sizeof(*r));
}
return 0;
}
static void
__gnet_stats_copy_queue_cpu(struct gnet_stats_queue *qstats,
const struct gnet_stats_queue __percpu *q)
{
int i;
for_each_possible_cpu(i) {
const struct gnet_stats_queue *qcpu = per_cpu_ptr(q, i);
qstats->qlen = 0;
qstats->backlog += qcpu->backlog;
qstats->drops += qcpu->drops;
qstats->requeues += qcpu->requeues;
qstats->overlimits += qcpu->overlimits;
}
}
static void __gnet_stats_copy_queue(struct gnet_stats_queue *qstats,
const struct gnet_stats_queue __percpu *cpu,
const struct gnet_stats_queue *q,
__u32 qlen)
{
if (cpu) {
__gnet_stats_copy_queue_cpu(qstats, cpu);
} else {
qstats->qlen = q->qlen;
qstats->backlog = q->backlog;
qstats->drops = q->drops;
qstats->requeues = q->requeues;
qstats->overlimits = q->overlimits;
}
qstats->qlen = qlen;
}
int
gnet_stats_copy_queue(struct gnet_dump *d,
struct gnet_stats_queue __percpu *cpu_q,
struct gnet_stats_queue *q, __u32 qlen)
{
struct gnet_stats_queue qstats = {0};
__gnet_stats_copy_queue(&qstats, cpu_q, q, qlen);
if (d->compat_tc_stats) {
d->tc_stats.drops = qstats.drops;
d->tc_stats.qlen = qstats.qlen;
d->tc_stats.backlog = qstats.backlog;
d->tc_stats.overlimits = qstats.overlimits;
}
if (d->tail)
return gnet_stats_copy(d, TCA_STATS_QUEUE,
&qstats, sizeof(qstats));
return 0;
}
int
gnet_stats_copy_app(struct gnet_dump *d, void *st, int len)
{
if (d->compat_xstats) {
d->xstats = st;
d->xstats_len = len;
}
if (d->tail)
return gnet_stats_copy(d, TCA_STATS_APP, st, len);
return 0;
}
int
gnet_stats_finish_copy(struct gnet_dump *d)
{
if (d->tail)
d->tail->nla_len = skb_tail_pointer(d->skb) - (u8 *)d->tail;
if (d->compat_tc_stats)
if (gnet_stats_copy(d, d->compat_tc_stats, &d->tc_stats,
sizeof(d->tc_stats)) < 0)
return -1;
if (d->compat_xstats && d->xstats) {
if (gnet_stats_copy(d, d->compat_xstats, d->xstats,
d->xstats_len) < 0)
return -1;
}
spin_unlock_bh(d->lock);
return 0;
}
