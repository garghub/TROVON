static void est_timer(unsigned long arg)
{
int idx = (int)arg;
struct gen_estimator *e;
rcu_read_lock();
list_for_each_entry_rcu(e, &elist[idx].list, list) {
struct gnet_stats_basic_packed b = {0};
unsigned long rate;
u64 brate;
if (e->stats_lock)
spin_lock(e->stats_lock);
read_lock(&est_lock);
if (e->bstats == NULL)
goto skip;
__gnet_stats_copy_basic(e->running, &b, e->cpu_bstats, e->bstats);
brate = (b.bytes - e->last_bytes)<<(7 - idx);
e->last_bytes = b.bytes;
e->avbps += (brate >> e->ewma_log) - (e->avbps >> e->ewma_log);
WRITE_ONCE(e->rate_est->bps, (e->avbps + 0xF) >> 5);
rate = b.packets - e->last_packets;
rate <<= (7 - idx);
e->last_packets = b.packets;
e->avpps += (rate >> e->ewma_log) - (e->avpps >> e->ewma_log);
WRITE_ONCE(e->rate_est->pps, (e->avpps + 0xF) >> 5);
skip:
read_unlock(&est_lock);
if (e->stats_lock)
spin_unlock(e->stats_lock);
}
if (!list_empty(&elist[idx].list))
mod_timer(&elist[idx].timer, jiffies + ((HZ/4) << idx));
rcu_read_unlock();
}
static void gen_add_node(struct gen_estimator *est)
{
struct rb_node **p = &est_root.rb_node, *parent = NULL;
while (*p) {
struct gen_estimator *e;
parent = *p;
e = rb_entry(parent, struct gen_estimator, node);
if (est->bstats > e->bstats)
p = &parent->rb_right;
else
p = &parent->rb_left;
}
rb_link_node(&est->node, parent, p);
rb_insert_color(&est->node, &est_root);
}
static
struct gen_estimator *gen_find_node(const struct gnet_stats_basic_packed *bstats,
const struct gnet_stats_rate_est64 *rate_est)
{
struct rb_node *p = est_root.rb_node;
while (p) {
struct gen_estimator *e;
e = rb_entry(p, struct gen_estimator, node);
if (bstats > e->bstats)
p = p->rb_right;
else if (bstats < e->bstats || rate_est != e->rate_est)
p = p->rb_left;
else
return e;
}
return NULL;
}
int gen_new_estimator(struct gnet_stats_basic_packed *bstats,
struct gnet_stats_basic_cpu __percpu *cpu_bstats,
struct gnet_stats_rate_est64 *rate_est,
spinlock_t *stats_lock,
seqcount_t *running,
struct nlattr *opt)
{
struct gen_estimator *est;
struct gnet_estimator *parm = nla_data(opt);
struct gnet_stats_basic_packed b = {0};
int idx;
if (nla_len(opt) < sizeof(*parm))
return -EINVAL;
if (parm->interval < -2 || parm->interval > 3)
return -EINVAL;
est = kzalloc(sizeof(*est), GFP_KERNEL);
if (est == NULL)
return -ENOBUFS;
__gnet_stats_copy_basic(running, &b, cpu_bstats, bstats);
idx = parm->interval + 2;
est->bstats = bstats;
est->rate_est = rate_est;
est->stats_lock = stats_lock;
est->running = running;
est->ewma_log = parm->ewma_log;
est->last_bytes = b.bytes;
est->avbps = rate_est->bps<<5;
est->last_packets = b.packets;
est->avpps = rate_est->pps<<10;
est->cpu_bstats = cpu_bstats;
spin_lock_bh(&est_tree_lock);
if (!elist[idx].timer.function) {
INIT_LIST_HEAD(&elist[idx].list);
setup_timer(&elist[idx].timer, est_timer, idx);
}
if (list_empty(&elist[idx].list))
mod_timer(&elist[idx].timer, jiffies + ((HZ/4) << idx));
list_add_rcu(&est->list, &elist[idx].list);
gen_add_node(est);
spin_unlock_bh(&est_tree_lock);
return 0;
}
void gen_kill_estimator(struct gnet_stats_basic_packed *bstats,
struct gnet_stats_rate_est64 *rate_est)
{
struct gen_estimator *e;
spin_lock_bh(&est_tree_lock);
while ((e = gen_find_node(bstats, rate_est))) {
rb_erase(&e->node, &est_root);
write_lock(&est_lock);
e->bstats = NULL;
write_unlock(&est_lock);
list_del_rcu(&e->list);
kfree_rcu(e, e_rcu);
}
spin_unlock_bh(&est_tree_lock);
}
int gen_replace_estimator(struct gnet_stats_basic_packed *bstats,
struct gnet_stats_basic_cpu __percpu *cpu_bstats,
struct gnet_stats_rate_est64 *rate_est,
spinlock_t *stats_lock,
seqcount_t *running, struct nlattr *opt)
{
gen_kill_estimator(bstats, rate_est);
return gen_new_estimator(bstats, cpu_bstats, rate_est, stats_lock, running, opt);
}
bool gen_estimator_active(const struct gnet_stats_basic_packed *bstats,
const struct gnet_stats_rate_est64 *rate_est)
{
bool res;
ASSERT_RTNL();
spin_lock_bh(&est_tree_lock);
res = gen_find_node(bstats, rate_est) != NULL;
spin_unlock_bh(&est_tree_lock);
return res;
}
