static inline __u64 dru(__u64 val, __u32 shift, int round_up)
{
return (val + (round_up ? (1 << shift) - 1 : 0)) >> shift;
}
static inline __u64 ldlm_pool_slv_max(__u32 L)
{
__u64 lim = (__u64)L * LDLM_POOL_MAX_AGE / 1;
return lim;
}
static inline __u64 ldlm_pool_slv_min(__u32 L)
{
return 1;
}
static inline struct ldlm_namespace *ldlm_pl2ns(struct ldlm_pool *pl)
{
return container_of(pl, struct ldlm_namespace, ns_pool);
}
static inline int ldlm_pool_t2gsp(unsigned int t)
{
return LDLM_POOL_MAX_GSP -
((LDLM_POOL_MAX_GSP - LDLM_POOL_MIN_GSP) >>
(t >> LDLM_POOL_GSP_STEP_SHIFT));
}
static void ldlm_pool_recalc_grant_plan(struct ldlm_pool *pl)
{
int granted, grant_step, limit;
limit = ldlm_pool_get_limit(pl);
granted = atomic_read(&pl->pl_granted);
grant_step = ldlm_pool_t2gsp(pl->pl_recalc_period);
grant_step = ((limit - granted) * grant_step) / 100;
pl->pl_grant_plan = granted + grant_step;
limit = (limit * 5) >> 2;
if (pl->pl_grant_plan > limit)
pl->pl_grant_plan = limit;
}
static void ldlm_pool_recalc_slv(struct ldlm_pool *pl)
{
int granted;
int grant_plan;
int round_up;
__u64 slv;
__u64 slv_factor;
__u64 grant_usage;
__u32 limit;
slv = pl->pl_server_lock_volume;
grant_plan = pl->pl_grant_plan;
limit = ldlm_pool_get_limit(pl);
granted = atomic_read(&pl->pl_granted);
round_up = granted < limit;
grant_usage = max_t(int, limit - (granted - grant_plan), 1);
slv_factor = grant_usage << LDLM_POOL_SLV_SHIFT;
do_div(slv_factor, limit);
slv = slv * slv_factor;
slv = dru(slv, LDLM_POOL_SLV_SHIFT, round_up);
if (slv > ldlm_pool_slv_max(limit))
slv = ldlm_pool_slv_max(limit);
else if (slv < ldlm_pool_slv_min(limit))
slv = ldlm_pool_slv_min(limit);
pl->pl_server_lock_volume = slv;
}
static void ldlm_pool_recalc_stats(struct ldlm_pool *pl)
{
int grant_plan = pl->pl_grant_plan;
__u64 slv = pl->pl_server_lock_volume;
int granted = atomic_read(&pl->pl_granted);
int grant_rate = atomic_read(&pl->pl_grant_rate);
int cancel_rate = atomic_read(&pl->pl_cancel_rate);
lprocfs_counter_add(pl->pl_stats, LDLM_POOL_SLV_STAT,
slv);
lprocfs_counter_add(pl->pl_stats, LDLM_POOL_GRANTED_STAT,
granted);
lprocfs_counter_add(pl->pl_stats, LDLM_POOL_GRANT_RATE_STAT,
grant_rate);
lprocfs_counter_add(pl->pl_stats, LDLM_POOL_GRANT_PLAN_STAT,
grant_plan);
lprocfs_counter_add(pl->pl_stats, LDLM_POOL_CANCEL_RATE_STAT,
cancel_rate);
}
static void ldlm_srv_pool_push_slv(struct ldlm_pool *pl)
{
struct obd_device *obd;
obd = ldlm_pl2ns(pl)->ns_obd;
LASSERT(obd != NULL);
write_lock(&obd->obd_pool_lock);
obd->obd_pool_slv = pl->pl_server_lock_volume;
write_unlock(&obd->obd_pool_lock);
}
static int ldlm_srv_pool_recalc(struct ldlm_pool *pl)
{
time_t recalc_interval_sec;
recalc_interval_sec = get_seconds() - pl->pl_recalc_time;
if (recalc_interval_sec < pl->pl_recalc_period)
return 0;
spin_lock(&pl->pl_lock);
recalc_interval_sec = get_seconds() - pl->pl_recalc_time;
if (recalc_interval_sec < pl->pl_recalc_period) {
spin_unlock(&pl->pl_lock);
return 0;
}
ldlm_pool_recalc_slv(pl);
ldlm_srv_pool_push_slv(pl);
ldlm_pool_recalc_grant_plan(pl);
pl->pl_recalc_time = get_seconds();
lprocfs_counter_add(pl->pl_stats, LDLM_POOL_TIMING_STAT,
recalc_interval_sec);
spin_unlock(&pl->pl_lock);
return 0;
}
static int ldlm_srv_pool_shrink(struct ldlm_pool *pl,
int nr, gfp_t gfp_mask)
{
__u32 limit;
if (nr == 0)
return atomic_read(&pl->pl_granted);
if (atomic_read(&pl->pl_granted) == 0)
return 0;
spin_lock(&pl->pl_lock);
if (nr < pl->pl_server_lock_volume) {
pl->pl_server_lock_volume = pl->pl_server_lock_volume - nr;
} else {
limit = ldlm_pool_get_limit(pl);
pl->pl_server_lock_volume = ldlm_pool_slv_min(limit);
}
ldlm_srv_pool_push_slv(pl);
spin_unlock(&pl->pl_lock);
return 0;
}
static int ldlm_srv_pool_setup(struct ldlm_pool *pl, int limit)
{
struct obd_device *obd;
obd = ldlm_pl2ns(pl)->ns_obd;
LASSERT(obd != NULL && obd != LP_POISON);
LASSERT(obd->obd_type != LP_POISON);
write_lock(&obd->obd_pool_lock);
obd->obd_pool_limit = limit;
write_unlock(&obd->obd_pool_lock);
ldlm_pool_set_limit(pl, limit);
return 0;
}
static void ldlm_cli_pool_pop_slv(struct ldlm_pool *pl)
{
struct obd_device *obd;
obd = ldlm_pl2ns(pl)->ns_obd;
LASSERT(obd != NULL);
read_lock(&obd->obd_pool_lock);
pl->pl_server_lock_volume = obd->obd_pool_slv;
ldlm_pool_set_limit(pl, obd->obd_pool_limit);
read_unlock(&obd->obd_pool_lock);
}
static int ldlm_cli_pool_recalc(struct ldlm_pool *pl)
{
time_t recalc_interval_sec;
int ret;
recalc_interval_sec = get_seconds() - pl->pl_recalc_time;
if (recalc_interval_sec < pl->pl_recalc_period)
return 0;
spin_lock(&pl->pl_lock);
recalc_interval_sec = get_seconds() - pl->pl_recalc_time;
if (recalc_interval_sec < pl->pl_recalc_period) {
spin_unlock(&pl->pl_lock);
return 0;
}
ldlm_cli_pool_pop_slv(pl);
spin_unlock(&pl->pl_lock);
if (!ns_connect_lru_resize(ldlm_pl2ns(pl))) {
ret = 0;
goto out;
}
ret = ldlm_cancel_lru(ldlm_pl2ns(pl), 0, LCF_ASYNC, LDLM_CANCEL_LRUR);
out:
spin_lock(&pl->pl_lock);
pl->pl_recalc_time = get_seconds();
lprocfs_counter_add(pl->pl_stats, LDLM_POOL_TIMING_STAT,
recalc_interval_sec);
spin_unlock(&pl->pl_lock);
return ret;
}
static int ldlm_cli_pool_shrink(struct ldlm_pool *pl,
int nr, gfp_t gfp_mask)
{
struct ldlm_namespace *ns;
int unused;
ns = ldlm_pl2ns(pl);
if (!ns_connect_lru_resize(ns))
return 0;
ldlm_cli_pool_pop_slv(pl);
spin_lock(&ns->ns_lock);
unused = ns->ns_nr_unused;
spin_unlock(&ns->ns_lock);
if (nr == 0)
return (unused / 100) * sysctl_vfs_cache_pressure;
else
return ldlm_cancel_lru(ns, nr, LCF_ASYNC, LDLM_CANCEL_SHRINK);
}
int ldlm_pool_recalc(struct ldlm_pool *pl)
{
time_t recalc_interval_sec;
int count;
recalc_interval_sec = get_seconds() - pl->pl_recalc_time;
if (recalc_interval_sec <= 0)
goto recalc;
spin_lock(&pl->pl_lock);
if (recalc_interval_sec > 0) {
ldlm_pool_recalc_stats(pl);
atomic_set(&pl->pl_grant_rate, 0);
atomic_set(&pl->pl_cancel_rate, 0);
}
spin_unlock(&pl->pl_lock);
recalc:
if (pl->pl_ops->po_recalc != NULL) {
count = pl->pl_ops->po_recalc(pl);
lprocfs_counter_add(pl->pl_stats, LDLM_POOL_RECALC_STAT,
count);
}
recalc_interval_sec = pl->pl_recalc_time - get_seconds() +
pl->pl_recalc_period;
if (recalc_interval_sec <= 0) {
CDEBUG(D_DLMTRACE, "Negative interval(%ld), "
"too short period(%ld)",
recalc_interval_sec,
pl->pl_recalc_period);
recalc_interval_sec = 1;
}
return recalc_interval_sec;
}
int ldlm_pool_shrink(struct ldlm_pool *pl, int nr,
gfp_t gfp_mask)
{
int cancel = 0;
if (pl->pl_ops->po_shrink != NULL) {
cancel = pl->pl_ops->po_shrink(pl, nr, gfp_mask);
if (nr > 0) {
lprocfs_counter_add(pl->pl_stats,
LDLM_POOL_SHRINK_REQTD_STAT,
nr);
lprocfs_counter_add(pl->pl_stats,
LDLM_POOL_SHRINK_FREED_STAT,
cancel);
CDEBUG(D_DLMTRACE, "%s: request to shrink %d locks, shrunk %d\n",
pl->pl_name, nr, cancel);
}
}
return cancel;
}
int ldlm_pool_setup(struct ldlm_pool *pl, int limit)
{
if (pl->pl_ops->po_setup != NULL)
return pl->pl_ops->po_setup(pl, limit);
return 0;
}
static int lprocfs_pool_state_seq_show(struct seq_file *m, void *unused)
{
int granted, grant_rate, cancel_rate, grant_step;
int grant_speed, grant_plan, lvf;
struct ldlm_pool *pl = m->private;
__u64 slv, clv;
__u32 limit;
spin_lock(&pl->pl_lock);
slv = pl->pl_server_lock_volume;
clv = pl->pl_client_lock_volume;
limit = ldlm_pool_get_limit(pl);
grant_plan = pl->pl_grant_plan;
granted = atomic_read(&pl->pl_granted);
grant_rate = atomic_read(&pl->pl_grant_rate);
cancel_rate = atomic_read(&pl->pl_cancel_rate);
grant_speed = grant_rate - cancel_rate;
lvf = atomic_read(&pl->pl_lock_volume_factor);
grant_step = ldlm_pool_t2gsp(pl->pl_recalc_period);
spin_unlock(&pl->pl_lock);
seq_printf(m, "LDLM pool state (%s):\n"
" SLV: %llu\n"
" CLV: %llu\n"
" LVF: %d\n",
pl->pl_name, slv, clv, lvf);
if (ns_is_server(ldlm_pl2ns(pl))) {
seq_printf(m, " GSP: %d%%\n"
" GP: %d\n",
grant_step, grant_plan);
}
seq_printf(m, " GR: %d\n CR: %d\n GS: %d\n"
" G: %d\n L: %d\n",
grant_rate, cancel_rate, grant_speed,
granted, limit);
return 0;
}
static int lprocfs_grant_speed_seq_show(struct seq_file *m, void *unused)
{
struct ldlm_pool *pl = m->private;
int grant_speed;
spin_lock(&pl->pl_lock);
grant_speed = atomic_read(&pl->pl_grant_rate) -
atomic_read(&pl->pl_cancel_rate);
spin_unlock(&pl->pl_lock);
return lprocfs_rd_uint(m, &grant_speed);
}
static ssize_t lprocfs_recalc_period_seq_write(struct file *file,
const char __user *buf,
size_t len, loff_t *off)
{
struct seq_file *seq = file->private_data;
return lprocfs_wr_recalc_period(file, buf, len, seq->private);
}
static int ldlm_pool_proc_init(struct ldlm_pool *pl)
{
struct ldlm_namespace *ns = ldlm_pl2ns(pl);
struct proc_dir_entry *parent_ns_proc;
struct lprocfs_vars pool_vars[2];
char *var_name = NULL;
int rc = 0;
OBD_ALLOC(var_name, MAX_STRING_SIZE + 1);
if (!var_name)
return -ENOMEM;
parent_ns_proc = ns->ns_proc_dir_entry;
if (parent_ns_proc == NULL) {
CERROR("%s: proc entry is not initialized\n",
ldlm_ns_name(ns));
rc = -EINVAL;
goto out_free_name;
}
pl->pl_proc_dir = lprocfs_register("pool", parent_ns_proc,
NULL, NULL);
if (IS_ERR(pl->pl_proc_dir)) {
CERROR("LProcFS failed in ldlm-pool-init\n");
rc = PTR_ERR(pl->pl_proc_dir);
pl->pl_proc_dir = NULL;
goto out_free_name;
}
var_name[MAX_STRING_SIZE] = '\0';
memset(pool_vars, 0, sizeof(pool_vars));
pool_vars[0].name = var_name;
LDLM_POOL_ADD_VAR("server_lock_volume", &pl->pl_server_lock_volume,
&ldlm_pool_u64_fops);
LDLM_POOL_ADD_VAR("limit", &pl->pl_limit, &ldlm_pool_rw_atomic_fops);
LDLM_POOL_ADD_VAR("granted", &pl->pl_granted, &ldlm_pool_atomic_fops);
LDLM_POOL_ADD_VAR("grant_speed", pl, &lprocfs_grant_speed_fops);
LDLM_POOL_ADD_VAR("cancel_rate", &pl->pl_cancel_rate,
&ldlm_pool_atomic_fops);
LDLM_POOL_ADD_VAR("grant_rate", &pl->pl_grant_rate,
&ldlm_pool_atomic_fops);
LDLM_POOL_ADD_VAR("grant_plan", pl, &lprocfs_grant_plan_fops);
LDLM_POOL_ADD_VAR("recalc_period", pl, &lprocfs_recalc_period_fops);
LDLM_POOL_ADD_VAR("lock_volume_factor", &pl->pl_lock_volume_factor,
&ldlm_pool_rw_atomic_fops);
LDLM_POOL_ADD_VAR("state", pl, &lprocfs_pool_state_fops);
pl->pl_stats = lprocfs_alloc_stats(LDLM_POOL_LAST_STAT -
LDLM_POOL_FIRST_STAT, 0);
if (!pl->pl_stats) {
rc = -ENOMEM;
goto out_free_name;
}
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_GRANTED_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"granted", "locks");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_GRANT_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"grant", "locks");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_CANCEL_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"cancel", "locks");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_GRANT_RATE_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"grant_rate", "locks/s");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_CANCEL_RATE_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"cancel_rate", "locks/s");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_GRANT_PLAN_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"grant_plan", "locks/s");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_SLV_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"slv", "slv");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_SHRINK_REQTD_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"shrink_request", "locks");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_SHRINK_FREED_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"shrink_freed", "locks");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_RECALC_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"recalc_freed", "locks");
lprocfs_counter_init(pl->pl_stats, LDLM_POOL_TIMING_STAT,
LPROCFS_CNTR_AVGMINMAX | LPROCFS_CNTR_STDDEV,
"recalc_timing", "sec");
rc = lprocfs_register_stats(pl->pl_proc_dir, "stats", pl->pl_stats);
out_free_name:
OBD_FREE(var_name, MAX_STRING_SIZE + 1);
return rc;
}
static void ldlm_pool_proc_fini(struct ldlm_pool *pl)
{
if (pl->pl_stats != NULL) {
lprocfs_free_stats(&pl->pl_stats);
pl->pl_stats = NULL;
}
if (pl->pl_proc_dir != NULL) {
lprocfs_remove(&pl->pl_proc_dir);
pl->pl_proc_dir = NULL;
}
}
static int ldlm_pool_proc_init(struct ldlm_pool *pl)
{
return 0;
}
static void ldlm_pool_proc_fini(struct ldlm_pool *pl) {}
int ldlm_pool_init(struct ldlm_pool *pl, struct ldlm_namespace *ns,
int idx, ldlm_side_t client)
{
int rc;
spin_lock_init(&pl->pl_lock);
atomic_set(&pl->pl_granted, 0);
pl->pl_recalc_time = get_seconds();
atomic_set(&pl->pl_lock_volume_factor, 1);
atomic_set(&pl->pl_grant_rate, 0);
atomic_set(&pl->pl_cancel_rate, 0);
pl->pl_grant_plan = LDLM_POOL_GP(LDLM_POOL_HOST_L);
snprintf(pl->pl_name, sizeof(pl->pl_name), "ldlm-pool-%s-%d",
ldlm_ns_name(ns), idx);
if (client == LDLM_NAMESPACE_SERVER) {
pl->pl_ops = &ldlm_srv_pool_ops;
ldlm_pool_set_limit(pl, LDLM_POOL_HOST_L);
pl->pl_recalc_period = LDLM_POOL_SRV_DEF_RECALC_PERIOD;
pl->pl_server_lock_volume = ldlm_pool_slv_max(LDLM_POOL_HOST_L);
} else {
ldlm_pool_set_limit(pl, 1);
pl->pl_server_lock_volume = 0;
pl->pl_ops = &ldlm_cli_pool_ops;
pl->pl_recalc_period = LDLM_POOL_CLI_DEF_RECALC_PERIOD;
}
pl->pl_client_lock_volume = 0;
rc = ldlm_pool_proc_init(pl);
if (rc)
return rc;
CDEBUG(D_DLMTRACE, "Lock pool %s is initialized\n", pl->pl_name);
return rc;
}
void ldlm_pool_fini(struct ldlm_pool *pl)
{
ldlm_pool_proc_fini(pl);
POISON(pl, 0x5a, sizeof(*pl));
}
void ldlm_pool_add(struct ldlm_pool *pl, struct ldlm_lock *lock)
{
if (lock->l_resource->lr_type == LDLM_FLOCK)
return;
atomic_inc(&pl->pl_granted);
atomic_inc(&pl->pl_grant_rate);
lprocfs_counter_incr(pl->pl_stats, LDLM_POOL_GRANT_STAT);
if (ns_is_server(ldlm_pl2ns(pl)))
ldlm_pool_recalc(pl);
}
void ldlm_pool_del(struct ldlm_pool *pl, struct ldlm_lock *lock)
{
if (lock->l_resource->lr_type == LDLM_FLOCK)
return;
LASSERT(atomic_read(&pl->pl_granted) > 0);
atomic_dec(&pl->pl_granted);
atomic_inc(&pl->pl_cancel_rate);
lprocfs_counter_incr(pl->pl_stats, LDLM_POOL_CANCEL_STAT);
if (ns_is_server(ldlm_pl2ns(pl)))
ldlm_pool_recalc(pl);
}
__u64 ldlm_pool_get_slv(struct ldlm_pool *pl)
{
__u64 slv;
spin_lock(&pl->pl_lock);
slv = pl->pl_server_lock_volume;
spin_unlock(&pl->pl_lock);
return slv;
}
void ldlm_pool_set_slv(struct ldlm_pool *pl, __u64 slv)
{
spin_lock(&pl->pl_lock);
pl->pl_server_lock_volume = slv;
spin_unlock(&pl->pl_lock);
}
__u64 ldlm_pool_get_clv(struct ldlm_pool *pl)
{
__u64 slv;
spin_lock(&pl->pl_lock);
slv = pl->pl_client_lock_volume;
spin_unlock(&pl->pl_lock);
return slv;
}
void ldlm_pool_set_clv(struct ldlm_pool *pl, __u64 clv)
{
spin_lock(&pl->pl_lock);
pl->pl_client_lock_volume = clv;
spin_unlock(&pl->pl_lock);
}
__u32 ldlm_pool_get_limit(struct ldlm_pool *pl)
{
return atomic_read(&pl->pl_limit);
}
void ldlm_pool_set_limit(struct ldlm_pool *pl, __u32 limit)
{
atomic_set(&pl->pl_limit, limit);
}
__u32 ldlm_pool_get_lvf(struct ldlm_pool *pl)
{
return atomic_read(&pl->pl_lock_volume_factor);
}
static int ldlm_pool_granted(struct ldlm_pool *pl)
{
return atomic_read(&pl->pl_granted);
}
static unsigned long ldlm_pools_count(ldlm_side_t client, gfp_t gfp_mask)
{
int total = 0, nr_ns;
struct ldlm_namespace *ns;
struct ldlm_namespace *ns_old = NULL;
void *cookie;
if (client == LDLM_NAMESPACE_CLIENT && !(gfp_mask & __GFP_FS))
return 0;
CDEBUG(D_DLMTRACE, "Request to count %s locks from all pools\n",
client == LDLM_NAMESPACE_CLIENT ? "client" : "server");
cookie = cl_env_reenter();
for (nr_ns = ldlm_namespace_nr_read(client);
nr_ns > 0; nr_ns--) {
mutex_lock(ldlm_namespace_lock(client));
if (list_empty(ldlm_namespace_list(client))) {
mutex_unlock(ldlm_namespace_lock(client));
cl_env_reexit(cookie);
return 0;
}
ns = ldlm_namespace_first_locked(client);
if (ns == ns_old) {
mutex_unlock(ldlm_namespace_lock(client));
break;
}
if (ldlm_ns_empty(ns)) {
ldlm_namespace_move_to_inactive_locked(ns, client);
mutex_unlock(ldlm_namespace_lock(client));
continue;
}
if (ns_old == NULL)
ns_old = ns;
ldlm_namespace_get(ns);
ldlm_namespace_move_to_active_locked(ns, client);
mutex_unlock(ldlm_namespace_lock(client));
total += ldlm_pool_shrink(&ns->ns_pool, 0, gfp_mask);
ldlm_namespace_put(ns);
}
cl_env_reexit(cookie);
return total;
}
static unsigned long ldlm_pools_scan(ldlm_side_t client, int nr, gfp_t gfp_mask)
{
unsigned long freed = 0;
int tmp, nr_ns;
struct ldlm_namespace *ns;
void *cookie;
if (client == LDLM_NAMESPACE_CLIENT && !(gfp_mask & __GFP_FS))
return -1;
cookie = cl_env_reenter();
for (tmp = nr_ns = ldlm_namespace_nr_read(client);
tmp > 0; tmp--) {
int cancel, nr_locks;
mutex_lock(ldlm_namespace_lock(client));
if (list_empty(ldlm_namespace_list(client))) {
mutex_unlock(ldlm_namespace_lock(client));
break;
}
ns = ldlm_namespace_first_locked(client);
ldlm_namespace_get(ns);
ldlm_namespace_move_to_active_locked(ns, client);
mutex_unlock(ldlm_namespace_lock(client));
nr_locks = ldlm_pool_granted(&ns->ns_pool);
cancel = 1 + min_t(int, nr_locks, nr / nr_ns);
freed += ldlm_pool_shrink(&ns->ns_pool, cancel, gfp_mask);
ldlm_namespace_put(ns);
}
cl_env_reexit(cookie);
return (client == LDLM_NAMESPACE_SERVER) ? SHRINK_STOP : freed;
}
static unsigned long ldlm_pools_srv_count(struct shrinker *s,
struct shrink_control *sc)
{
return ldlm_pools_count(LDLM_NAMESPACE_SERVER, sc->gfp_mask);
}
static unsigned long ldlm_pools_srv_scan(struct shrinker *s,
struct shrink_control *sc)
{
return ldlm_pools_scan(LDLM_NAMESPACE_SERVER, sc->nr_to_scan,
sc->gfp_mask);
}
static unsigned long ldlm_pools_cli_count(struct shrinker *s,
struct shrink_control *sc)
{
return ldlm_pools_count(LDLM_NAMESPACE_CLIENT, sc->gfp_mask);
}
static unsigned long ldlm_pools_cli_scan(struct shrinker *s,
struct shrink_control *sc)
{
return ldlm_pools_scan(LDLM_NAMESPACE_CLIENT, sc->nr_to_scan,
sc->gfp_mask);
}
int ldlm_pools_recalc(ldlm_side_t client)
{
__u32 nr_l = 0, nr_p = 0, l;
struct ldlm_namespace *ns;
struct ldlm_namespace *ns_old = NULL;
int nr, equal = 0;
int time = 50;
if (client == LDLM_NAMESPACE_SERVER) {
mutex_lock(ldlm_namespace_lock(client));
list_for_each_entry(ns, ldlm_namespace_list(client),
ns_list_chain) {
if (ns->ns_appetite != LDLM_NAMESPACE_MODEST)
continue;
l = ldlm_pool_granted(&ns->ns_pool);
if (l == 0)
l = 1;
l += dru(l, LDLM_POOLS_MODEST_MARGIN_SHIFT, 0);
ldlm_pool_setup(&ns->ns_pool, l);
nr_l += l;
nr_p++;
}
if (nr_l >= 2 * (LDLM_POOL_HOST_L / 3)) {
CWARN("\"Modest\" pools eat out 2/3 of server locks limit (%d of %lu). This means that you have too many clients for this amount of server RAM. Upgrade server!\n",
nr_l, LDLM_POOL_HOST_L);
equal = 1;
}
list_for_each_entry(ns, ldlm_namespace_list(client),
ns_list_chain) {
if (!equal && ns->ns_appetite != LDLM_NAMESPACE_GREEDY)
continue;
if (equal) {
l = LDLM_POOL_HOST_L /
ldlm_namespace_nr_read(client);
} else {
l = (LDLM_POOL_HOST_L - nr_l) /
(ldlm_namespace_nr_read(client) -
nr_p);
}
ldlm_pool_setup(&ns->ns_pool, l);
}
mutex_unlock(ldlm_namespace_lock(client));
}
for (nr = ldlm_namespace_nr_read(client); nr > 0; nr--) {
int skip;
mutex_lock(ldlm_namespace_lock(client));
if (list_empty(ldlm_namespace_list(client))) {
mutex_unlock(ldlm_namespace_lock(client));
break;
}
ns = ldlm_namespace_first_locked(client);
if (ns_old == ns) {
mutex_unlock(ldlm_namespace_lock(client));
break;
}
if (ldlm_ns_empty(ns)) {
ldlm_namespace_move_to_inactive_locked(ns, client);
mutex_unlock(ldlm_namespace_lock(client));
continue;
}
if (ns_old == NULL)
ns_old = ns;
spin_lock(&ns->ns_lock);
if (ns->ns_stopping) {
skip = 1;
} else {
skip = 0;
ldlm_namespace_get(ns);
}
spin_unlock(&ns->ns_lock);
ldlm_namespace_move_to_active_locked(ns, client);
mutex_unlock(ldlm_namespace_lock(client));
if (!skip) {
int ttime = ldlm_pool_recalc(&ns->ns_pool);
if (ttime < time)
time = ttime;
ldlm_namespace_put(ns);
}
}
return time;
}
static int ldlm_pools_thread_main(void *arg)
{
struct ptlrpc_thread *thread = (struct ptlrpc_thread *)arg;
int s_time, c_time;
thread_set_flags(thread, SVC_RUNNING);
wake_up(&thread->t_ctl_waitq);
CDEBUG(D_DLMTRACE, "%s: pool thread starting, process %d\n",
"ldlm_poold", current_pid());
while (1) {
struct l_wait_info lwi;
s_time = ldlm_pools_recalc(LDLM_NAMESPACE_SERVER);
c_time = ldlm_pools_recalc(LDLM_NAMESPACE_CLIENT);
lwi = LWI_TIMEOUT(cfs_time_seconds(min(s_time, c_time)),
NULL, NULL);
l_wait_event(thread->t_ctl_waitq,
thread_is_stopping(thread) ||
thread_is_event(thread),
&lwi);
if (thread_test_and_clear_flags(thread, SVC_STOPPING))
break;
else
thread_test_and_clear_flags(thread, SVC_EVENT);
}
thread_set_flags(thread, SVC_STOPPED);
wake_up(&thread->t_ctl_waitq);
CDEBUG(D_DLMTRACE, "%s: pool thread exiting, process %d\n",
"ldlm_poold", current_pid());
complete_and_exit(&ldlm_pools_comp, 0);
}
static int ldlm_pools_thread_start(void)
{
struct l_wait_info lwi = { 0 };
struct task_struct *task;
if (ldlm_pools_thread != NULL)
return -EALREADY;
OBD_ALLOC_PTR(ldlm_pools_thread);
if (ldlm_pools_thread == NULL)
return -ENOMEM;
init_completion(&ldlm_pools_comp);
init_waitqueue_head(&ldlm_pools_thread->t_ctl_waitq);
task = kthread_run(ldlm_pools_thread_main, ldlm_pools_thread,
"ldlm_poold");
if (IS_ERR(task)) {
CERROR("Can't start pool thread, error %ld\n", PTR_ERR(task));
OBD_FREE(ldlm_pools_thread, sizeof(*ldlm_pools_thread));
ldlm_pools_thread = NULL;
return PTR_ERR(task);
}
l_wait_event(ldlm_pools_thread->t_ctl_waitq,
thread_is_running(ldlm_pools_thread), &lwi);
return 0;
}
static void ldlm_pools_thread_stop(void)
{
if (ldlm_pools_thread == NULL)
return;
thread_set_flags(ldlm_pools_thread, SVC_STOPPING);
wake_up(&ldlm_pools_thread->t_ctl_waitq);
wait_for_completion(&ldlm_pools_comp);
OBD_FREE_PTR(ldlm_pools_thread);
ldlm_pools_thread = NULL;
}
int ldlm_pools_init(void)
{
int rc;
rc = ldlm_pools_thread_start();
if (rc == 0) {
register_shrinker(&ldlm_pools_srv_shrinker);
register_shrinker(&ldlm_pools_cli_shrinker);
}
return rc;
}
void ldlm_pools_fini(void)
{
unregister_shrinker(&ldlm_pools_srv_shrinker);
unregister_shrinker(&ldlm_pools_cli_shrinker);
ldlm_pools_thread_stop();
}
