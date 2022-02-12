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
int
gnet_stats_copy_basic(struct gnet_dump *d, struct gnet_stats_basic_packed *b)
{
if (d->compat_tc_stats) {
d->tc_stats.bytes = b->bytes;
d->tc_stats.packets = b->packets;
}
if (d->tail) {
struct gnet_stats_basic sb;
memset(&sb, 0, sizeof(sb));
sb.bytes = b->bytes;
sb.packets = b->packets;
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
int
gnet_stats_copy_queue(struct gnet_dump *d, struct gnet_stats_queue *q)
{
if (d->compat_tc_stats) {
d->tc_stats.drops = q->drops;
d->tc_stats.qlen = q->qlen;
d->tc_stats.backlog = q->backlog;
d->tc_stats.overlimits = q->overlimits;
}
if (d->tail)
return gnet_stats_copy(d, TCA_STATS_QUEUE, q, sizeof(*q));
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
