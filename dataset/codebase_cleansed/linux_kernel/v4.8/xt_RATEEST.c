static unsigned int xt_rateest_hash(const char *name)
{
return jhash(name, FIELD_SIZEOF(struct xt_rateest, name), jhash_rnd) &
(RATEEST_HSIZE - 1);
}
static void xt_rateest_hash_insert(struct xt_rateest *est)
{
unsigned int h;
h = xt_rateest_hash(est->name);
hlist_add_head(&est->list, &rateest_hash[h]);
}
struct xt_rateest *xt_rateest_lookup(const char *name)
{
struct xt_rateest *est;
unsigned int h;
h = xt_rateest_hash(name);
mutex_lock(&xt_rateest_mutex);
hlist_for_each_entry(est, &rateest_hash[h], list) {
if (strcmp(est->name, name) == 0) {
est->refcnt++;
mutex_unlock(&xt_rateest_mutex);
return est;
}
}
mutex_unlock(&xt_rateest_mutex);
return NULL;
}
void xt_rateest_put(struct xt_rateest *est)
{
mutex_lock(&xt_rateest_mutex);
if (--est->refcnt == 0) {
hlist_del(&est->list);
gen_kill_estimator(&est->bstats, &est->rstats);
kfree_rcu(est, rcu);
}
mutex_unlock(&xt_rateest_mutex);
}
static unsigned int
xt_rateest_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_rateest_target_info *info = par->targinfo;
struct gnet_stats_basic_packed *stats = &info->est->bstats;
spin_lock_bh(&info->est->lock);
stats->bytes += skb->len;
stats->packets++;
spin_unlock_bh(&info->est->lock);
return XT_CONTINUE;
}
static int xt_rateest_tg_checkentry(const struct xt_tgchk_param *par)
{
struct xt_rateest_target_info *info = par->targinfo;
struct xt_rateest *est;
struct {
struct nlattr opt;
struct gnet_estimator est;
} cfg;
int ret;
if (unlikely(!rnd_inited)) {
get_random_bytes(&jhash_rnd, sizeof(jhash_rnd));
rnd_inited = true;
}
est = xt_rateest_lookup(info->name);
if (est) {
if ((!info->interval && !info->ewma_log) ||
(info->interval != est->params.interval ||
info->ewma_log != est->params.ewma_log)) {
xt_rateest_put(est);
return -EINVAL;
}
info->est = est;
return 0;
}
ret = -ENOMEM;
est = kzalloc(sizeof(*est), GFP_KERNEL);
if (!est)
goto err1;
strlcpy(est->name, info->name, sizeof(est->name));
spin_lock_init(&est->lock);
est->refcnt = 1;
est->params.interval = info->interval;
est->params.ewma_log = info->ewma_log;
cfg.opt.nla_len = nla_attr_size(sizeof(cfg.est));
cfg.opt.nla_type = TCA_STATS_RATE_EST;
cfg.est.interval = info->interval;
cfg.est.ewma_log = info->ewma_log;
ret = gen_new_estimator(&est->bstats, NULL, &est->rstats,
&est->lock, NULL, &cfg.opt);
if (ret < 0)
goto err2;
info->est = est;
xt_rateest_hash_insert(est);
return 0;
err2:
kfree(est);
err1:
return ret;
}
static void xt_rateest_tg_destroy(const struct xt_tgdtor_param *par)
{
struct xt_rateest_target_info *info = par->targinfo;
xt_rateest_put(info->est);
}
static int __init xt_rateest_tg_init(void)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(rateest_hash); i++)
INIT_HLIST_HEAD(&rateest_hash[i]);
return xt_register_target(&xt_rateest_tg_reg);
}
static void __exit xt_rateest_tg_fini(void)
{
xt_unregister_target(&xt_rateest_tg_reg);
}
