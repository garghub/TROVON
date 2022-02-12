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
static inline int ldlm_pool_t2gsp(unsigned int t)
{
return LDLM_POOL_MAX_GSP -
((LDLM_POOL_MAX_GSP - LDLM_POOL_MIN_GSP) >>
(t >> LDLM_POOL_GSP_STEP_SHIFT));
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
static void ldlm_cli_pool_pop_slv(struct ldlm_pool *pl)
{
struct obd_device *obd;
obd = container_of(pl, struct ldlm_namespace,
ns_pool)->ns_obd;
read_lock(&obd->obd_pool_lock);
pl->pl_server_lock_volume = obd->obd_pool_slv;
atomic_set(&pl->pl_limit, obd->obd_pool_limit);
read_unlock(&obd->obd_pool_lock);
}
static int ldlm_cli_pool_recalc(struct ldlm_pool *pl)
{
time64_t recalc_interval_sec;
int ret;
recalc_interval_sec = ktime_get_real_seconds() - pl->pl_recalc_time;
if (recalc_interval_sec < pl->pl_recalc_period)
return 0;
spin_lock(&pl->pl_lock);
recalc_interval_sec = ktime_get_real_seconds() - pl->pl_recalc_time;
if (recalc_interval_sec < pl->pl_recalc_period) {
spin_unlock(&pl->pl_lock);
return 0;
}
ldlm_cli_pool_pop_slv(pl);
spin_unlock(&pl->pl_lock);
if (!ns_connect_lru_resize(container_of(pl, struct ldlm_namespace,
ns_pool))) {
ret = 0;
goto out;
}
ret = ldlm_cancel_lru(container_of(pl, struct ldlm_namespace, ns_pool),
0, LCF_ASYNC, LDLM_LRU_FLAG_LRUR);
out:
spin_lock(&pl->pl_lock);
pl->pl_recalc_time = ktime_get_real_seconds();
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
ns = container_of(pl, struct ldlm_namespace, ns_pool);
if (!ns_connect_lru_resize(ns))
return 0;
ldlm_cli_pool_pop_slv(pl);
spin_lock(&ns->ns_lock);
unused = ns->ns_nr_unused;
spin_unlock(&ns->ns_lock);
if (nr == 0)
return (unused / 100) * sysctl_vfs_cache_pressure;
else
return ldlm_cancel_lru(ns, nr, LCF_ASYNC, LDLM_LRU_FLAG_SHRINK);
}
static int ldlm_pool_recalc(struct ldlm_pool *pl)
{
u32 recalc_interval_sec;
int count;
recalc_interval_sec = ktime_get_real_seconds() - pl->pl_recalc_time;
if (recalc_interval_sec > 0) {
spin_lock(&pl->pl_lock);
recalc_interval_sec = ktime_get_real_seconds() - pl->pl_recalc_time;
if (recalc_interval_sec > 0) {
ldlm_pool_recalc_stats(pl);
atomic_set(&pl->pl_grant_rate, 0);
atomic_set(&pl->pl_cancel_rate, 0);
}
spin_unlock(&pl->pl_lock);
}
if (pl->pl_ops->po_recalc) {
count = pl->pl_ops->po_recalc(pl);
lprocfs_counter_add(pl->pl_stats, LDLM_POOL_RECALC_STAT,
count);
}
recalc_interval_sec = pl->pl_recalc_time - ktime_get_real_seconds() +
pl->pl_recalc_period;
if (recalc_interval_sec <= 0) {
CDEBUG(D_DLMTRACE, "%s: Negative interval(%ld), too short period(%ld)\n",
pl->pl_name, (long)recalc_interval_sec,
(long)pl->pl_recalc_period);
recalc_interval_sec = 1;
}
return recalc_interval_sec;
}
static int ldlm_pool_shrink(struct ldlm_pool *pl, int nr, gfp_t gfp_mask)
{
int cancel = 0;
if (pl->pl_ops->po_shrink) {
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
static int lprocfs_pool_state_seq_show(struct seq_file *m, void *unused)
{
int granted, grant_rate, cancel_rate;
int grant_speed, lvf;
struct ldlm_pool *pl = m->private;
__u64 slv, clv;
__u32 limit;
spin_lock(&pl->pl_lock);
slv = pl->pl_server_lock_volume;
clv = pl->pl_client_lock_volume;
limit = atomic_read(&pl->pl_limit);
granted = atomic_read(&pl->pl_granted);
grant_rate = atomic_read(&pl->pl_grant_rate);
cancel_rate = atomic_read(&pl->pl_cancel_rate);
grant_speed = grant_rate - cancel_rate;
lvf = atomic_read(&pl->pl_lock_volume_factor);
spin_unlock(&pl->pl_lock);
seq_printf(m, "LDLM pool state (%s):\n"
" SLV: %llu\n"
" CLV: %llu\n"
" LVF: %d\n",
pl->pl_name, slv, clv, lvf);
seq_printf(m, " GR: %d\n CR: %d\n GS: %d\n"
" G: %d\n L: %d\n",
grant_rate, cancel_rate, grant_speed,
granted, limit);
return 0;
}
static ssize_t grant_speed_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct ldlm_pool *pl = container_of(kobj, struct ldlm_pool,
pl_kobj);
int grant_speed;
spin_lock(&pl->pl_lock);
grant_speed = atomic_read(&pl->pl_grant_rate) -
atomic_read(&pl->pl_cancel_rate);
spin_unlock(&pl->pl_lock);
return sprintf(buf, "%d\n", grant_speed);
}
static void ldlm_pl_release(struct kobject *kobj)
{
struct ldlm_pool *pl = container_of(kobj, struct ldlm_pool,
pl_kobj);
complete(&pl->pl_kobj_unregister);
}
static int ldlm_pool_sysfs_init(struct ldlm_pool *pl)
{
struct ldlm_namespace *ns = container_of(pl, struct ldlm_namespace,
ns_pool);
int err;
init_completion(&pl->pl_kobj_unregister);
err = kobject_init_and_add(&pl->pl_kobj, &ldlm_pl_ktype, &ns->ns_kobj,
"pool");
return err;
}
static int ldlm_pool_debugfs_init(struct ldlm_pool *pl)
{
struct ldlm_namespace *ns = container_of(pl, struct ldlm_namespace,
ns_pool);
struct dentry *debugfs_ns_parent;
struct lprocfs_vars pool_vars[2];
char *var_name = NULL;
int rc = 0;
var_name = kzalloc(MAX_STRING_SIZE + 1, GFP_NOFS);
if (!var_name)
return -ENOMEM;
debugfs_ns_parent = ns->ns_debugfs_entry;
if (IS_ERR_OR_NULL(debugfs_ns_parent)) {
CERROR("%s: debugfs entry is not initialized\n",
ldlm_ns_name(ns));
rc = -EINVAL;
goto out_free_name;
}
pl->pl_debugfs_entry = ldebugfs_register("pool", debugfs_ns_parent,
NULL, NULL);
if (IS_ERR(pl->pl_debugfs_entry)) {
CERROR("LdebugFS failed in ldlm-pool-init\n");
rc = PTR_ERR(pl->pl_debugfs_entry);
pl->pl_debugfs_entry = NULL;
goto out_free_name;
}
var_name[MAX_STRING_SIZE] = '\0';
memset(pool_vars, 0, sizeof(pool_vars));
pool_vars[0].name = var_name;
LDLM_POOL_ADD_VAR(state, pl, &lprocfs_pool_state_fops);
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
rc = ldebugfs_register_stats(pl->pl_debugfs_entry, "stats",
pl->pl_stats);
out_free_name:
kfree(var_name);
return rc;
}
static void ldlm_pool_sysfs_fini(struct ldlm_pool *pl)
{
kobject_put(&pl->pl_kobj);
wait_for_completion(&pl->pl_kobj_unregister);
}
static void ldlm_pool_debugfs_fini(struct ldlm_pool *pl)
{
if (pl->pl_stats) {
lprocfs_free_stats(&pl->pl_stats);
pl->pl_stats = NULL;
}
if (pl->pl_debugfs_entry) {
ldebugfs_remove(&pl->pl_debugfs_entry);
pl->pl_debugfs_entry = NULL;
}
}
int ldlm_pool_init(struct ldlm_pool *pl, struct ldlm_namespace *ns,
int idx, enum ldlm_side client)
{
int rc;
spin_lock_init(&pl->pl_lock);
atomic_set(&pl->pl_granted, 0);
pl->pl_recalc_time = ktime_get_real_seconds();
atomic_set(&pl->pl_lock_volume_factor, 1);
atomic_set(&pl->pl_grant_rate, 0);
atomic_set(&pl->pl_cancel_rate, 0);
pl->pl_grant_plan = LDLM_POOL_GP(LDLM_POOL_HOST_L);
snprintf(pl->pl_name, sizeof(pl->pl_name), "ldlm-pool-%s-%d",
ldlm_ns_name(ns), idx);
atomic_set(&pl->pl_limit, 1);
pl->pl_server_lock_volume = 0;
pl->pl_ops = &ldlm_cli_pool_ops;
pl->pl_recalc_period = LDLM_POOL_CLI_DEF_RECALC_PERIOD;
pl->pl_client_lock_volume = 0;
rc = ldlm_pool_debugfs_init(pl);
if (rc)
return rc;
rc = ldlm_pool_sysfs_init(pl);
if (rc)
return rc;
CDEBUG(D_DLMTRACE, "Lock pool %s is initialized\n", pl->pl_name);
return rc;
}
void ldlm_pool_fini(struct ldlm_pool *pl)
{
ldlm_pool_sysfs_fini(pl);
ldlm_pool_debugfs_fini(pl);
POISON(pl, 0x5a, sizeof(*pl));
}
void ldlm_pool_add(struct ldlm_pool *pl, struct ldlm_lock *lock)
{
if (lock->l_resource->lr_type == LDLM_FLOCK)
return;
atomic_inc(&pl->pl_granted);
atomic_inc(&pl->pl_grant_rate);
lprocfs_counter_incr(pl->pl_stats, LDLM_POOL_GRANT_STAT);
}
void ldlm_pool_del(struct ldlm_pool *pl, struct ldlm_lock *lock)
{
if (lock->l_resource->lr_type == LDLM_FLOCK)
return;
LASSERT(atomic_read(&pl->pl_granted) > 0);
atomic_dec(&pl->pl_granted);
atomic_inc(&pl->pl_cancel_rate);
lprocfs_counter_incr(pl->pl_stats, LDLM_POOL_CANCEL_STAT);
}
__u64 ldlm_pool_get_slv(struct ldlm_pool *pl)
{
__u64 slv;
spin_lock(&pl->pl_lock);
slv = pl->pl_server_lock_volume;
spin_unlock(&pl->pl_lock);
return slv;
}
void ldlm_pool_set_clv(struct ldlm_pool *pl, __u64 clv)
{
spin_lock(&pl->pl_lock);
pl->pl_client_lock_volume = clv;
spin_unlock(&pl->pl_lock);
}
__u32 ldlm_pool_get_lvf(struct ldlm_pool *pl)
{
return atomic_read(&pl->pl_lock_volume_factor);
}
static int ldlm_pool_granted(struct ldlm_pool *pl)
{
return atomic_read(&pl->pl_granted);
}
static unsigned long ldlm_pools_count(enum ldlm_side client, gfp_t gfp_mask)
{
unsigned long total = 0;
int nr_ns;
struct ldlm_namespace *ns;
struct ldlm_namespace *ns_old = NULL;
if (client == LDLM_NAMESPACE_CLIENT && !(gfp_mask & __GFP_FS))
return 0;
CDEBUG(D_DLMTRACE, "Request to count %s locks from all pools\n",
client == LDLM_NAMESPACE_CLIENT ? "client" : "server");
for (nr_ns = ldlm_namespace_nr_read(client);
nr_ns > 0; nr_ns--) {
mutex_lock(ldlm_namespace_lock(client));
if (list_empty(ldlm_namespace_list(client))) {
mutex_unlock(ldlm_namespace_lock(client));
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
if (!ns_old)
ns_old = ns;
ldlm_namespace_get(ns);
ldlm_namespace_move_to_active_locked(ns, client);
mutex_unlock(ldlm_namespace_lock(client));
total += ldlm_pool_shrink(&ns->ns_pool, 0, gfp_mask);
ldlm_namespace_put(ns);
}
return total;
}
static unsigned long ldlm_pools_scan(enum ldlm_side client, int nr,
gfp_t gfp_mask)
{
unsigned long freed = 0;
int tmp, nr_ns;
struct ldlm_namespace *ns;
if (client == LDLM_NAMESPACE_CLIENT && !(gfp_mask & __GFP_FS))
return -1;
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
return freed;
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
static int ldlm_pools_recalc(enum ldlm_side client)
{
struct ldlm_namespace *ns;
struct ldlm_namespace *ns_old = NULL;
int time = LDLM_POOL_CLI_DEF_RECALC_PERIOD;
int nr;
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
if (!ns_old)
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
ldlm_bl_thread_wakeup();
return time;
}
static int ldlm_pools_thread_main(void *arg)
{
struct ptlrpc_thread *thread = (struct ptlrpc_thread *)arg;
int c_time;
thread_set_flags(thread, SVC_RUNNING);
wake_up(&thread->t_ctl_waitq);
CDEBUG(D_DLMTRACE, "%s: pool thread starting, process %d\n",
"ldlm_poold", current_pid());
while (1) {
struct l_wait_info lwi;
c_time = ldlm_pools_recalc(LDLM_NAMESPACE_CLIENT);
lwi = LWI_TIMEOUT(cfs_time_seconds(c_time),
NULL, NULL);
l_wait_event(thread->t_ctl_waitq,
thread_is_stopping(thread) ||
thread_is_event(thread),
&lwi);
if (thread_test_and_clear_flags(thread, SVC_STOPPING))
break;
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
if (ldlm_pools_thread)
return -EALREADY;
ldlm_pools_thread = kzalloc(sizeof(*ldlm_pools_thread), GFP_NOFS);
if (!ldlm_pools_thread)
return -ENOMEM;
init_completion(&ldlm_pools_comp);
init_waitqueue_head(&ldlm_pools_thread->t_ctl_waitq);
task = kthread_run(ldlm_pools_thread_main, ldlm_pools_thread,
"ldlm_poold");
if (IS_ERR(task)) {
CERROR("Can't start pool thread, error %ld\n", PTR_ERR(task));
kfree(ldlm_pools_thread);
ldlm_pools_thread = NULL;
return PTR_ERR(task);
}
l_wait_event(ldlm_pools_thread->t_ctl_waitq,
thread_is_running(ldlm_pools_thread), &lwi);
return 0;
}
static void ldlm_pools_thread_stop(void)
{
if (!ldlm_pools_thread)
return;
thread_set_flags(ldlm_pools_thread, SVC_STOPPING);
wake_up(&ldlm_pools_thread->t_ctl_waitq);
wait_for_completion(&ldlm_pools_comp);
kfree(ldlm_pools_thread);
ldlm_pools_thread = NULL;
}
int ldlm_pools_init(void)
{
int rc;
rc = ldlm_pools_thread_start();
if (rc == 0)
register_shrinker(&ldlm_pools_cli_shrinker);
return rc;
}
void ldlm_pools_fini(void)
{
if (ldlm_pools_thread)
unregister_shrinker(&ldlm_pools_cli_shrinker);
ldlm_pools_thread_stop();
}
