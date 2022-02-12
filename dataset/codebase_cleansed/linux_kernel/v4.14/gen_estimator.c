static void est_fetch_counters(struct net_rate_estimator *e,
struct gnet_stats_basic_packed *b)
{
if (e->stats_lock)
spin_lock(e->stats_lock);
__gnet_stats_copy_basic(e->running, b, e->cpu_bstats, e->bstats);
if (e->stats_lock)
spin_unlock(e->stats_lock);
}
static void est_timer(unsigned long arg)
{
struct net_rate_estimator *est = (struct net_rate_estimator *)arg;
struct gnet_stats_basic_packed b;
u64 rate, brate;
est_fetch_counters(est, &b);
brate = (b.bytes - est->last_bytes) << (10 - est->ewma_log - est->intvl_log);
brate -= (est->avbps >> est->ewma_log);
rate = (u64)(b.packets - est->last_packets) << (10 - est->ewma_log - est->intvl_log);
rate -= (est->avpps >> est->ewma_log);
write_seqcount_begin(&est->seq);
est->avbps += brate;
est->avpps += rate;
write_seqcount_end(&est->seq);
est->last_bytes = b.bytes;
est->last_packets = b.packets;
est->next_jiffies += ((HZ/4) << est->intvl_log);
if (unlikely(time_after_eq(jiffies, est->next_jiffies))) {
est->next_jiffies = jiffies + 1;
}
mod_timer(&est->timer, est->next_jiffies);
}
int gen_new_estimator(struct gnet_stats_basic_packed *bstats,
struct gnet_stats_basic_cpu __percpu *cpu_bstats,
struct net_rate_estimator __rcu **rate_est,
spinlock_t *stats_lock,
seqcount_t *running,
struct nlattr *opt)
{
struct gnet_estimator *parm = nla_data(opt);
struct net_rate_estimator *old, *est;
struct gnet_stats_basic_packed b;
int intvl_log;
if (nla_len(opt) < sizeof(*parm))
return -EINVAL;
if (parm->interval < -2 || parm->interval > 3)
return -EINVAL;
est = kzalloc(sizeof(*est), GFP_KERNEL);
if (!est)
return -ENOBUFS;
seqcount_init(&est->seq);
intvl_log = parm->interval + 2;
est->bstats = bstats;
est->stats_lock = stats_lock;
est->running = running;
est->ewma_log = parm->ewma_log;
est->intvl_log = intvl_log;
est->cpu_bstats = cpu_bstats;
est_fetch_counters(est, &b);
est->last_bytes = b.bytes;
est->last_packets = b.packets;
old = rcu_dereference_protected(*rate_est, 1);
if (old) {
del_timer_sync(&old->timer);
est->avbps = old->avbps;
est->avpps = old->avpps;
}
est->next_jiffies = jiffies + ((HZ/4) << intvl_log);
setup_timer(&est->timer, est_timer, (unsigned long)est);
mod_timer(&est->timer, est->next_jiffies);
rcu_assign_pointer(*rate_est, est);
if (old)
kfree_rcu(old, rcu);
return 0;
}
void gen_kill_estimator(struct net_rate_estimator __rcu **rate_est)
{
struct net_rate_estimator *est;
est = xchg((__force struct net_rate_estimator **)rate_est, NULL);
if (est) {
del_timer_sync(&est->timer);
kfree_rcu(est, rcu);
}
}
int gen_replace_estimator(struct gnet_stats_basic_packed *bstats,
struct gnet_stats_basic_cpu __percpu *cpu_bstats,
struct net_rate_estimator __rcu **rate_est,
spinlock_t *stats_lock,
seqcount_t *running, struct nlattr *opt)
{
return gen_new_estimator(bstats, cpu_bstats, rate_est,
stats_lock, running, opt);
}
bool gen_estimator_active(struct net_rate_estimator __rcu **rate_est)
{
return !!rcu_access_pointer(*rate_est);
}
bool gen_estimator_read(struct net_rate_estimator __rcu **rate_est,
struct gnet_stats_rate_est64 *sample)
{
struct net_rate_estimator *est;
unsigned seq;
rcu_read_lock();
est = rcu_dereference(*rate_est);
if (!est) {
rcu_read_unlock();
return false;
}
do {
seq = read_seqcount_begin(&est->seq);
sample->bps = est->avbps >> 8;
sample->pps = est->avpps >> 8;
} while (read_seqcount_retry(&est->seq, seq));
rcu_read_unlock();
return true;
}
