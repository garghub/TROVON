static inline struct cpuset *css_cs(struct cgroup_subsys_state *css)
{
return css ? container_of(css, struct cpuset, css) : NULL;
}
static inline struct cpuset *task_cs(struct task_struct *task)
{
return css_cs(task_css(task, cpuset_cgrp_id));
}
static inline struct cpuset *parent_cs(struct cpuset *cs)
{
return css_cs(cs->css.parent);
}
static inline bool task_has_mempolicy(struct task_struct *task)
{
return task->mempolicy;
}
static inline bool task_has_mempolicy(struct task_struct *task)
{
return false;
}
static inline bool is_cpuset_online(const struct cpuset *cs)
{
return test_bit(CS_ONLINE, &cs->flags);
}
static inline int is_cpu_exclusive(const struct cpuset *cs)
{
return test_bit(CS_CPU_EXCLUSIVE, &cs->flags);
}
static inline int is_mem_exclusive(const struct cpuset *cs)
{
return test_bit(CS_MEM_EXCLUSIVE, &cs->flags);
}
static inline int is_mem_hardwall(const struct cpuset *cs)
{
return test_bit(CS_MEM_HARDWALL, &cs->flags);
}
static inline int is_sched_load_balance(const struct cpuset *cs)
{
return test_bit(CS_SCHED_LOAD_BALANCE, &cs->flags);
}
static inline int is_memory_migrate(const struct cpuset *cs)
{
return test_bit(CS_MEMORY_MIGRATE, &cs->flags);
}
static inline int is_spread_page(const struct cpuset *cs)
{
return test_bit(CS_SPREAD_PAGE, &cs->flags);
}
static inline int is_spread_slab(const struct cpuset *cs)
{
return test_bit(CS_SPREAD_SLAB, &cs->flags);
}
static struct dentry *cpuset_mount(struct file_system_type *fs_type,
int flags, const char *unused_dev_name, void *data)
{
struct file_system_type *cgroup_fs = get_fs_type("cgroup");
struct dentry *ret = ERR_PTR(-ENODEV);
if (cgroup_fs) {
char mountopts[] =
"cpuset,noprefix,"
"release_agent=/sbin/cpuset_release_agent";
ret = cgroup_fs->mount(cgroup_fs, flags,
unused_dev_name, mountopts);
put_filesystem(cgroup_fs);
}
return ret;
}
static void guarantee_online_cpus(struct cpuset *cs, struct cpumask *pmask)
{
while (!cpumask_intersects(cs->effective_cpus, cpu_online_mask))
cs = parent_cs(cs);
cpumask_and(pmask, cs->effective_cpus, cpu_online_mask);
}
static void guarantee_online_mems(struct cpuset *cs, nodemask_t *pmask)
{
while (!nodes_intersects(cs->effective_mems, node_states[N_MEMORY]))
cs = parent_cs(cs);
nodes_and(*pmask, cs->effective_mems, node_states[N_MEMORY]);
}
static void cpuset_update_task_spread_flag(struct cpuset *cs,
struct task_struct *tsk)
{
if (is_spread_page(cs))
task_set_spread_page(tsk);
else
task_clear_spread_page(tsk);
if (is_spread_slab(cs))
task_set_spread_slab(tsk);
else
task_clear_spread_slab(tsk);
}
static int is_cpuset_subset(const struct cpuset *p, const struct cpuset *q)
{
return cpumask_subset(p->cpus_allowed, q->cpus_allowed) &&
nodes_subset(p->mems_allowed, q->mems_allowed) &&
is_cpu_exclusive(p) <= is_cpu_exclusive(q) &&
is_mem_exclusive(p) <= is_mem_exclusive(q);
}
static struct cpuset *alloc_trial_cpuset(struct cpuset *cs)
{
struct cpuset *trial;
trial = kmemdup(cs, sizeof(*cs), GFP_KERNEL);
if (!trial)
return NULL;
if (!alloc_cpumask_var(&trial->cpus_allowed, GFP_KERNEL))
goto free_cs;
if (!alloc_cpumask_var(&trial->effective_cpus, GFP_KERNEL))
goto free_cpus;
cpumask_copy(trial->cpus_allowed, cs->cpus_allowed);
cpumask_copy(trial->effective_cpus, cs->effective_cpus);
return trial;
free_cpus:
free_cpumask_var(trial->cpus_allowed);
free_cs:
kfree(trial);
return NULL;
}
static void free_trial_cpuset(struct cpuset *trial)
{
free_cpumask_var(trial->effective_cpus);
free_cpumask_var(trial->cpus_allowed);
kfree(trial);
}
static int validate_change(struct cpuset *cur, struct cpuset *trial)
{
struct cgroup_subsys_state *css;
struct cpuset *c, *par;
int ret;
rcu_read_lock();
ret = -EBUSY;
cpuset_for_each_child(c, css, cur)
if (!is_cpuset_subset(c, trial))
goto out;
ret = 0;
if (cur == &top_cpuset)
goto out;
par = parent_cs(cur);
ret = -EACCES;
if (!cgroup_on_dfl(cur->css.cgroup) && !is_cpuset_subset(trial, par))
goto out;
ret = -EINVAL;
cpuset_for_each_child(c, css, par) {
if ((is_cpu_exclusive(trial) || is_cpu_exclusive(c)) &&
c != cur &&
cpumask_intersects(trial->cpus_allowed, c->cpus_allowed))
goto out;
if ((is_mem_exclusive(trial) || is_mem_exclusive(c)) &&
c != cur &&
nodes_intersects(trial->mems_allowed, c->mems_allowed))
goto out;
}
ret = -ENOSPC;
if ((cgroup_has_tasks(cur->css.cgroup) || cur->attach_in_progress)) {
if (!cpumask_empty(cur->cpus_allowed) &&
cpumask_empty(trial->cpus_allowed))
goto out;
if (!nodes_empty(cur->mems_allowed) &&
nodes_empty(trial->mems_allowed))
goto out;
}
ret = -EBUSY;
if (is_cpu_exclusive(cur) &&
!cpuset_cpumask_can_shrink(cur->cpus_allowed,
trial->cpus_allowed))
goto out;
ret = 0;
out:
rcu_read_unlock();
return ret;
}
static int cpusets_overlap(struct cpuset *a, struct cpuset *b)
{
return cpumask_intersects(a->effective_cpus, b->effective_cpus);
}
static void
update_domain_attr(struct sched_domain_attr *dattr, struct cpuset *c)
{
if (dattr->relax_domain_level < c->relax_domain_level)
dattr->relax_domain_level = c->relax_domain_level;
return;
}
static void update_domain_attr_tree(struct sched_domain_attr *dattr,
struct cpuset *root_cs)
{
struct cpuset *cp;
struct cgroup_subsys_state *pos_css;
rcu_read_lock();
cpuset_for_each_descendant_pre(cp, pos_css, root_cs) {
if (cpumask_empty(cp->cpus_allowed)) {
pos_css = css_rightmost_descendant(pos_css);
continue;
}
if (is_sched_load_balance(cp))
update_domain_attr(dattr, cp);
}
rcu_read_unlock();
}
static int generate_sched_domains(cpumask_var_t **domains,
struct sched_domain_attr **attributes)
{
struct cpuset *cp;
struct cpuset **csa;
int csn;
int i, j, k;
cpumask_var_t *doms;
struct sched_domain_attr *dattr;
int ndoms = 0;
int nslot;
struct cgroup_subsys_state *pos_css;
doms = NULL;
dattr = NULL;
csa = NULL;
if (is_sched_load_balance(&top_cpuset)) {
ndoms = 1;
doms = alloc_sched_domains(ndoms);
if (!doms)
goto done;
dattr = kmalloc(sizeof(struct sched_domain_attr), GFP_KERNEL);
if (dattr) {
*dattr = SD_ATTR_INIT;
update_domain_attr_tree(dattr, &top_cpuset);
}
cpumask_copy(doms[0], top_cpuset.effective_cpus);
goto done;
}
csa = kmalloc(nr_cpusets() * sizeof(cp), GFP_KERNEL);
if (!csa)
goto done;
csn = 0;
rcu_read_lock();
cpuset_for_each_descendant_pre(cp, pos_css, &top_cpuset) {
if (cp == &top_cpuset)
continue;
if (!cpumask_empty(cp->cpus_allowed) &&
!is_sched_load_balance(cp))
continue;
if (is_sched_load_balance(cp))
csa[csn++] = cp;
pos_css = css_rightmost_descendant(pos_css);
}
rcu_read_unlock();
for (i = 0; i < csn; i++)
csa[i]->pn = i;
ndoms = csn;
restart:
for (i = 0; i < csn; i++) {
struct cpuset *a = csa[i];
int apn = a->pn;
for (j = 0; j < csn; j++) {
struct cpuset *b = csa[j];
int bpn = b->pn;
if (apn != bpn && cpusets_overlap(a, b)) {
for (k = 0; k < csn; k++) {
struct cpuset *c = csa[k];
if (c->pn == bpn)
c->pn = apn;
}
ndoms--;
goto restart;
}
}
}
doms = alloc_sched_domains(ndoms);
if (!doms)
goto done;
dattr = kmalloc(ndoms * sizeof(struct sched_domain_attr), GFP_KERNEL);
for (nslot = 0, i = 0; i < csn; i++) {
struct cpuset *a = csa[i];
struct cpumask *dp;
int apn = a->pn;
if (apn < 0) {
continue;
}
dp = doms[nslot];
if (nslot == ndoms) {
static int warnings = 10;
if (warnings) {
pr_warn("rebuild_sched_domains confused: nslot %d, ndoms %d, csn %d, i %d, apn %d\n",
nslot, ndoms, csn, i, apn);
warnings--;
}
continue;
}
cpumask_clear(dp);
if (dattr)
*(dattr + nslot) = SD_ATTR_INIT;
for (j = i; j < csn; j++) {
struct cpuset *b = csa[j];
if (apn == b->pn) {
cpumask_or(dp, dp, b->effective_cpus);
if (dattr)
update_domain_attr_tree(dattr + nslot, b);
b->pn = -1;
}
}
nslot++;
}
BUG_ON(nslot != ndoms);
done:
kfree(csa);
if (doms == NULL)
ndoms = 1;
*domains = doms;
*attributes = dattr;
return ndoms;
}
static void rebuild_sched_domains_locked(void)
{
struct sched_domain_attr *attr;
cpumask_var_t *doms;
int ndoms;
lockdep_assert_held(&cpuset_mutex);
get_online_cpus();
if (!cpumask_equal(top_cpuset.effective_cpus, cpu_active_mask))
goto out;
ndoms = generate_sched_domains(&doms, &attr);
partition_sched_domains(ndoms, doms, attr);
out:
put_online_cpus();
}
static void rebuild_sched_domains_locked(void)
{
}
void rebuild_sched_domains(void)
{
mutex_lock(&cpuset_mutex);
rebuild_sched_domains_locked();
mutex_unlock(&cpuset_mutex);
}
static void update_tasks_cpumask(struct cpuset *cs)
{
struct css_task_iter it;
struct task_struct *task;
css_task_iter_start(&cs->css, &it);
while ((task = css_task_iter_next(&it)))
set_cpus_allowed_ptr(task, cs->effective_cpus);
css_task_iter_end(&it);
}
static void update_cpumasks_hier(struct cpuset *cs, struct cpumask *new_cpus)
{
struct cpuset *cp;
struct cgroup_subsys_state *pos_css;
bool need_rebuild_sched_domains = false;
rcu_read_lock();
cpuset_for_each_descendant_pre(cp, pos_css, cs) {
struct cpuset *parent = parent_cs(cp);
cpumask_and(new_cpus, cp->cpus_allowed, parent->effective_cpus);
if (cgroup_on_dfl(cp->css.cgroup) && cpumask_empty(new_cpus))
cpumask_copy(new_cpus, parent->effective_cpus);
if (cpumask_equal(new_cpus, cp->effective_cpus)) {
pos_css = css_rightmost_descendant(pos_css);
continue;
}
if (!css_tryget_online(&cp->css))
continue;
rcu_read_unlock();
spin_lock_irq(&callback_lock);
cpumask_copy(cp->effective_cpus, new_cpus);
spin_unlock_irq(&callback_lock);
WARN_ON(!cgroup_on_dfl(cp->css.cgroup) &&
!cpumask_equal(cp->cpus_allowed, cp->effective_cpus));
update_tasks_cpumask(cp);
if (!cpumask_empty(cp->cpus_allowed) &&
is_sched_load_balance(cp))
need_rebuild_sched_domains = true;
rcu_read_lock();
css_put(&cp->css);
}
rcu_read_unlock();
if (need_rebuild_sched_domains)
rebuild_sched_domains_locked();
}
static int update_cpumask(struct cpuset *cs, struct cpuset *trialcs,
const char *buf)
{
int retval;
if (cs == &top_cpuset)
return -EACCES;
if (!*buf) {
cpumask_clear(trialcs->cpus_allowed);
} else {
retval = cpulist_parse(buf, trialcs->cpus_allowed);
if (retval < 0)
return retval;
if (!cpumask_subset(trialcs->cpus_allowed,
top_cpuset.cpus_allowed))
return -EINVAL;
}
if (cpumask_equal(cs->cpus_allowed, trialcs->cpus_allowed))
return 0;
retval = validate_change(cs, trialcs);
if (retval < 0)
return retval;
spin_lock_irq(&callback_lock);
cpumask_copy(cs->cpus_allowed, trialcs->cpus_allowed);
spin_unlock_irq(&callback_lock);
update_cpumasks_hier(cs, trialcs->cpus_allowed);
return 0;
}
static void cpuset_migrate_mm(struct mm_struct *mm, const nodemask_t *from,
const nodemask_t *to)
{
struct task_struct *tsk = current;
tsk->mems_allowed = *to;
do_migrate_pages(mm, from, to, MPOL_MF_MOVE_ALL);
rcu_read_lock();
guarantee_online_mems(task_cs(tsk), &tsk->mems_allowed);
rcu_read_unlock();
}
static void cpuset_change_task_nodemask(struct task_struct *tsk,
nodemask_t *newmems)
{
bool need_loop;
if (unlikely(test_thread_flag(TIF_MEMDIE)))
return;
if (current->flags & PF_EXITING)
return;
task_lock(tsk);
need_loop = task_has_mempolicy(tsk) ||
!nodes_intersects(*newmems, tsk->mems_allowed);
if (need_loop) {
local_irq_disable();
write_seqcount_begin(&tsk->mems_allowed_seq);
}
nodes_or(tsk->mems_allowed, tsk->mems_allowed, *newmems);
mpol_rebind_task(tsk, newmems, MPOL_REBIND_STEP1);
mpol_rebind_task(tsk, newmems, MPOL_REBIND_STEP2);
tsk->mems_allowed = *newmems;
if (need_loop) {
write_seqcount_end(&tsk->mems_allowed_seq);
local_irq_enable();
}
task_unlock(tsk);
}
static void update_tasks_nodemask(struct cpuset *cs)
{
static nodemask_t newmems;
struct css_task_iter it;
struct task_struct *task;
cpuset_being_rebound = cs;
guarantee_online_mems(cs, &newmems);
css_task_iter_start(&cs->css, &it);
while ((task = css_task_iter_next(&it))) {
struct mm_struct *mm;
bool migrate;
cpuset_change_task_nodemask(task, &newmems);
mm = get_task_mm(task);
if (!mm)
continue;
migrate = is_memory_migrate(cs);
mpol_rebind_mm(mm, &cs->mems_allowed);
if (migrate)
cpuset_migrate_mm(mm, &cs->old_mems_allowed, &newmems);
mmput(mm);
}
css_task_iter_end(&it);
cs->old_mems_allowed = newmems;
cpuset_being_rebound = NULL;
}
static void update_nodemasks_hier(struct cpuset *cs, nodemask_t *new_mems)
{
struct cpuset *cp;
struct cgroup_subsys_state *pos_css;
rcu_read_lock();
cpuset_for_each_descendant_pre(cp, pos_css, cs) {
struct cpuset *parent = parent_cs(cp);
nodes_and(*new_mems, cp->mems_allowed, parent->effective_mems);
if (cgroup_on_dfl(cp->css.cgroup) && nodes_empty(*new_mems))
*new_mems = parent->effective_mems;
if (nodes_equal(*new_mems, cp->effective_mems)) {
pos_css = css_rightmost_descendant(pos_css);
continue;
}
if (!css_tryget_online(&cp->css))
continue;
rcu_read_unlock();
spin_lock_irq(&callback_lock);
cp->effective_mems = *new_mems;
spin_unlock_irq(&callback_lock);
WARN_ON(!cgroup_on_dfl(cp->css.cgroup) &&
!nodes_equal(cp->mems_allowed, cp->effective_mems));
update_tasks_nodemask(cp);
rcu_read_lock();
css_put(&cp->css);
}
rcu_read_unlock();
}
static int update_nodemask(struct cpuset *cs, struct cpuset *trialcs,
const char *buf)
{
int retval;
if (cs == &top_cpuset) {
retval = -EACCES;
goto done;
}
if (!*buf) {
nodes_clear(trialcs->mems_allowed);
} else {
retval = nodelist_parse(buf, trialcs->mems_allowed);
if (retval < 0)
goto done;
if (!nodes_subset(trialcs->mems_allowed,
top_cpuset.mems_allowed)) {
retval = -EINVAL;
goto done;
}
}
if (nodes_equal(cs->mems_allowed, trialcs->mems_allowed)) {
retval = 0;
goto done;
}
retval = validate_change(cs, trialcs);
if (retval < 0)
goto done;
spin_lock_irq(&callback_lock);
cs->mems_allowed = trialcs->mems_allowed;
spin_unlock_irq(&callback_lock);
update_nodemasks_hier(cs, &cs->mems_allowed);
done:
return retval;
}
int current_cpuset_is_being_rebound(void)
{
int ret;
rcu_read_lock();
ret = task_cs(current) == cpuset_being_rebound;
rcu_read_unlock();
return ret;
}
static int update_relax_domain_level(struct cpuset *cs, s64 val)
{
#ifdef CONFIG_SMP
if (val < -1 || val >= sched_domain_level_max)
return -EINVAL;
#endif
if (val != cs->relax_domain_level) {
cs->relax_domain_level = val;
if (!cpumask_empty(cs->cpus_allowed) &&
is_sched_load_balance(cs))
rebuild_sched_domains_locked();
}
return 0;
}
static void update_tasks_flags(struct cpuset *cs)
{
struct css_task_iter it;
struct task_struct *task;
css_task_iter_start(&cs->css, &it);
while ((task = css_task_iter_next(&it)))
cpuset_update_task_spread_flag(cs, task);
css_task_iter_end(&it);
}
static int update_flag(cpuset_flagbits_t bit, struct cpuset *cs,
int turning_on)
{
struct cpuset *trialcs;
int balance_flag_changed;
int spread_flag_changed;
int err;
trialcs = alloc_trial_cpuset(cs);
if (!trialcs)
return -ENOMEM;
if (turning_on)
set_bit(bit, &trialcs->flags);
else
clear_bit(bit, &trialcs->flags);
err = validate_change(cs, trialcs);
if (err < 0)
goto out;
balance_flag_changed = (is_sched_load_balance(cs) !=
is_sched_load_balance(trialcs));
spread_flag_changed = ((is_spread_slab(cs) != is_spread_slab(trialcs))
|| (is_spread_page(cs) != is_spread_page(trialcs)));
spin_lock_irq(&callback_lock);
cs->flags = trialcs->flags;
spin_unlock_irq(&callback_lock);
if (!cpumask_empty(trialcs->cpus_allowed) && balance_flag_changed)
rebuild_sched_domains_locked();
if (spread_flag_changed)
update_tasks_flags(cs);
out:
free_trial_cpuset(trialcs);
return err;
}
static void fmeter_init(struct fmeter *fmp)
{
fmp->cnt = 0;
fmp->val = 0;
fmp->time = 0;
spin_lock_init(&fmp->lock);
}
static void fmeter_update(struct fmeter *fmp)
{
time_t now = get_seconds();
time_t ticks = now - fmp->time;
if (ticks == 0)
return;
ticks = min(FM_MAXTICKS, ticks);
while (ticks-- > 0)
fmp->val = (FM_COEF * fmp->val) / FM_SCALE;
fmp->time = now;
fmp->val += ((FM_SCALE - FM_COEF) * fmp->cnt) / FM_SCALE;
fmp->cnt = 0;
}
static void fmeter_markevent(struct fmeter *fmp)
{
spin_lock(&fmp->lock);
fmeter_update(fmp);
fmp->cnt = min(FM_MAXCNT, fmp->cnt + FM_SCALE);
spin_unlock(&fmp->lock);
}
static int fmeter_getrate(struct fmeter *fmp)
{
int val;
spin_lock(&fmp->lock);
fmeter_update(fmp);
val = fmp->val;
spin_unlock(&fmp->lock);
return val;
}
static int cpuset_can_attach(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
struct cpuset *cs = css_cs(css);
struct task_struct *task;
int ret;
cpuset_attach_old_cs = task_cs(cgroup_taskset_first(tset));
mutex_lock(&cpuset_mutex);
ret = -ENOSPC;
if (!cgroup_on_dfl(css->cgroup) &&
(cpumask_empty(cs->cpus_allowed) || nodes_empty(cs->mems_allowed)))
goto out_unlock;
cgroup_taskset_for_each(task, tset) {
ret = task_can_attach(task, cs->cpus_allowed);
if (ret)
goto out_unlock;
ret = security_task_setscheduler(task);
if (ret)
goto out_unlock;
}
cs->attach_in_progress++;
ret = 0;
out_unlock:
mutex_unlock(&cpuset_mutex);
return ret;
}
static void cpuset_cancel_attach(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
mutex_lock(&cpuset_mutex);
css_cs(css)->attach_in_progress--;
mutex_unlock(&cpuset_mutex);
}
static void cpuset_attach(struct cgroup_subsys_state *css,
struct cgroup_taskset *tset)
{
static nodemask_t cpuset_attach_nodemask_to;
struct mm_struct *mm;
struct task_struct *task;
struct task_struct *leader = cgroup_taskset_first(tset);
struct cpuset *cs = css_cs(css);
struct cpuset *oldcs = cpuset_attach_old_cs;
mutex_lock(&cpuset_mutex);
if (cs == &top_cpuset)
cpumask_copy(cpus_attach, cpu_possible_mask);
else
guarantee_online_cpus(cs, cpus_attach);
guarantee_online_mems(cs, &cpuset_attach_nodemask_to);
cgroup_taskset_for_each(task, tset) {
WARN_ON_ONCE(set_cpus_allowed_ptr(task, cpus_attach));
cpuset_change_task_nodemask(task, &cpuset_attach_nodemask_to);
cpuset_update_task_spread_flag(cs, task);
}
cpuset_attach_nodemask_to = cs->effective_mems;
mm = get_task_mm(leader);
if (mm) {
mpol_rebind_mm(mm, &cpuset_attach_nodemask_to);
if (is_memory_migrate(cs)) {
cpuset_migrate_mm(mm, &oldcs->old_mems_allowed,
&cpuset_attach_nodemask_to);
}
mmput(mm);
}
cs->old_mems_allowed = cpuset_attach_nodemask_to;
cs->attach_in_progress--;
if (!cs->attach_in_progress)
wake_up(&cpuset_attach_wq);
mutex_unlock(&cpuset_mutex);
}
static int cpuset_write_u64(struct cgroup_subsys_state *css, struct cftype *cft,
u64 val)
{
struct cpuset *cs = css_cs(css);
cpuset_filetype_t type = cft->private;
int retval = 0;
mutex_lock(&cpuset_mutex);
if (!is_cpuset_online(cs)) {
retval = -ENODEV;
goto out_unlock;
}
switch (type) {
case FILE_CPU_EXCLUSIVE:
retval = update_flag(CS_CPU_EXCLUSIVE, cs, val);
break;
case FILE_MEM_EXCLUSIVE:
retval = update_flag(CS_MEM_EXCLUSIVE, cs, val);
break;
case FILE_MEM_HARDWALL:
retval = update_flag(CS_MEM_HARDWALL, cs, val);
break;
case FILE_SCHED_LOAD_BALANCE:
retval = update_flag(CS_SCHED_LOAD_BALANCE, cs, val);
break;
case FILE_MEMORY_MIGRATE:
retval = update_flag(CS_MEMORY_MIGRATE, cs, val);
break;
case FILE_MEMORY_PRESSURE_ENABLED:
cpuset_memory_pressure_enabled = !!val;
break;
case FILE_MEMORY_PRESSURE:
retval = -EACCES;
break;
case FILE_SPREAD_PAGE:
retval = update_flag(CS_SPREAD_PAGE, cs, val);
break;
case FILE_SPREAD_SLAB:
retval = update_flag(CS_SPREAD_SLAB, cs, val);
break;
default:
retval = -EINVAL;
break;
}
out_unlock:
mutex_unlock(&cpuset_mutex);
return retval;
}
static int cpuset_write_s64(struct cgroup_subsys_state *css, struct cftype *cft,
s64 val)
{
struct cpuset *cs = css_cs(css);
cpuset_filetype_t type = cft->private;
int retval = -ENODEV;
mutex_lock(&cpuset_mutex);
if (!is_cpuset_online(cs))
goto out_unlock;
switch (type) {
case FILE_SCHED_RELAX_DOMAIN_LEVEL:
retval = update_relax_domain_level(cs, val);
break;
default:
retval = -EINVAL;
break;
}
out_unlock:
mutex_unlock(&cpuset_mutex);
return retval;
}
static ssize_t cpuset_write_resmask(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct cpuset *cs = css_cs(of_css(of));
struct cpuset *trialcs;
int retval = -ENODEV;
buf = strstrip(buf);
css_get(&cs->css);
kernfs_break_active_protection(of->kn);
flush_work(&cpuset_hotplug_work);
mutex_lock(&cpuset_mutex);
if (!is_cpuset_online(cs))
goto out_unlock;
trialcs = alloc_trial_cpuset(cs);
if (!trialcs) {
retval = -ENOMEM;
goto out_unlock;
}
switch (of_cft(of)->private) {
case FILE_CPULIST:
retval = update_cpumask(cs, trialcs, buf);
break;
case FILE_MEMLIST:
retval = update_nodemask(cs, trialcs, buf);
break;
default:
retval = -EINVAL;
break;
}
free_trial_cpuset(trialcs);
out_unlock:
mutex_unlock(&cpuset_mutex);
kernfs_unbreak_active_protection(of->kn);
css_put(&cs->css);
return retval ?: nbytes;
}
static int cpuset_common_seq_show(struct seq_file *sf, void *v)
{
struct cpuset *cs = css_cs(seq_css(sf));
cpuset_filetype_t type = seq_cft(sf)->private;
int ret = 0;
spin_lock_irq(&callback_lock);
switch (type) {
case FILE_CPULIST:
seq_printf(sf, "%*pbl\n", cpumask_pr_args(cs->cpus_allowed));
break;
case FILE_MEMLIST:
seq_printf(sf, "%*pbl\n", nodemask_pr_args(&cs->mems_allowed));
break;
case FILE_EFFECTIVE_CPULIST:
seq_printf(sf, "%*pbl\n", cpumask_pr_args(cs->effective_cpus));
break;
case FILE_EFFECTIVE_MEMLIST:
seq_printf(sf, "%*pbl\n", nodemask_pr_args(&cs->effective_mems));
break;
default:
ret = -EINVAL;
}
spin_unlock_irq(&callback_lock);
return ret;
}
static u64 cpuset_read_u64(struct cgroup_subsys_state *css, struct cftype *cft)
{
struct cpuset *cs = css_cs(css);
cpuset_filetype_t type = cft->private;
switch (type) {
case FILE_CPU_EXCLUSIVE:
return is_cpu_exclusive(cs);
case FILE_MEM_EXCLUSIVE:
return is_mem_exclusive(cs);
case FILE_MEM_HARDWALL:
return is_mem_hardwall(cs);
case FILE_SCHED_LOAD_BALANCE:
return is_sched_load_balance(cs);
case FILE_MEMORY_MIGRATE:
return is_memory_migrate(cs);
case FILE_MEMORY_PRESSURE_ENABLED:
return cpuset_memory_pressure_enabled;
case FILE_MEMORY_PRESSURE:
return fmeter_getrate(&cs->fmeter);
case FILE_SPREAD_PAGE:
return is_spread_page(cs);
case FILE_SPREAD_SLAB:
return is_spread_slab(cs);
default:
BUG();
}
return 0;
}
static s64 cpuset_read_s64(struct cgroup_subsys_state *css, struct cftype *cft)
{
struct cpuset *cs = css_cs(css);
cpuset_filetype_t type = cft->private;
switch (type) {
case FILE_SCHED_RELAX_DOMAIN_LEVEL:
return cs->relax_domain_level;
default:
BUG();
}
return 0;
}
static struct cgroup_subsys_state *
cpuset_css_alloc(struct cgroup_subsys_state *parent_css)
{
struct cpuset *cs;
if (!parent_css)
return &top_cpuset.css;
cs = kzalloc(sizeof(*cs), GFP_KERNEL);
if (!cs)
return ERR_PTR(-ENOMEM);
if (!alloc_cpumask_var(&cs->cpus_allowed, GFP_KERNEL))
goto free_cs;
if (!alloc_cpumask_var(&cs->effective_cpus, GFP_KERNEL))
goto free_cpus;
set_bit(CS_SCHED_LOAD_BALANCE, &cs->flags);
cpumask_clear(cs->cpus_allowed);
nodes_clear(cs->mems_allowed);
cpumask_clear(cs->effective_cpus);
nodes_clear(cs->effective_mems);
fmeter_init(&cs->fmeter);
cs->relax_domain_level = -1;
return &cs->css;
free_cpus:
free_cpumask_var(cs->cpus_allowed);
free_cs:
kfree(cs);
return ERR_PTR(-ENOMEM);
}
static int cpuset_css_online(struct cgroup_subsys_state *css)
{
struct cpuset *cs = css_cs(css);
struct cpuset *parent = parent_cs(cs);
struct cpuset *tmp_cs;
struct cgroup_subsys_state *pos_css;
if (!parent)
return 0;
mutex_lock(&cpuset_mutex);
set_bit(CS_ONLINE, &cs->flags);
if (is_spread_page(parent))
set_bit(CS_SPREAD_PAGE, &cs->flags);
if (is_spread_slab(parent))
set_bit(CS_SPREAD_SLAB, &cs->flags);
cpuset_inc();
spin_lock_irq(&callback_lock);
if (cgroup_on_dfl(cs->css.cgroup)) {
cpumask_copy(cs->effective_cpus, parent->effective_cpus);
cs->effective_mems = parent->effective_mems;
}
spin_unlock_irq(&callback_lock);
if (!test_bit(CGRP_CPUSET_CLONE_CHILDREN, &css->cgroup->flags))
goto out_unlock;
rcu_read_lock();
cpuset_for_each_child(tmp_cs, pos_css, parent) {
if (is_mem_exclusive(tmp_cs) || is_cpu_exclusive(tmp_cs)) {
rcu_read_unlock();
goto out_unlock;
}
}
rcu_read_unlock();
spin_lock_irq(&callback_lock);
cs->mems_allowed = parent->mems_allowed;
cs->effective_mems = parent->mems_allowed;
cpumask_copy(cs->cpus_allowed, parent->cpus_allowed);
cpumask_copy(cs->effective_cpus, parent->cpus_allowed);
spin_unlock_irq(&callback_lock);
out_unlock:
mutex_unlock(&cpuset_mutex);
return 0;
}
static void cpuset_css_offline(struct cgroup_subsys_state *css)
{
struct cpuset *cs = css_cs(css);
mutex_lock(&cpuset_mutex);
if (is_sched_load_balance(cs))
update_flag(CS_SCHED_LOAD_BALANCE, cs, 0);
cpuset_dec();
clear_bit(CS_ONLINE, &cs->flags);
mutex_unlock(&cpuset_mutex);
}
static void cpuset_css_free(struct cgroup_subsys_state *css)
{
struct cpuset *cs = css_cs(css);
free_cpumask_var(cs->effective_cpus);
free_cpumask_var(cs->cpus_allowed);
kfree(cs);
}
static void cpuset_bind(struct cgroup_subsys_state *root_css)
{
mutex_lock(&cpuset_mutex);
spin_lock_irq(&callback_lock);
if (cgroup_on_dfl(root_css->cgroup)) {
cpumask_copy(top_cpuset.cpus_allowed, cpu_possible_mask);
top_cpuset.mems_allowed = node_possible_map;
} else {
cpumask_copy(top_cpuset.cpus_allowed,
top_cpuset.effective_cpus);
top_cpuset.mems_allowed = top_cpuset.effective_mems;
}
spin_unlock_irq(&callback_lock);
mutex_unlock(&cpuset_mutex);
}
int __init cpuset_init(void)
{
int err = 0;
if (!alloc_cpumask_var(&top_cpuset.cpus_allowed, GFP_KERNEL))
BUG();
if (!alloc_cpumask_var(&top_cpuset.effective_cpus, GFP_KERNEL))
BUG();
cpumask_setall(top_cpuset.cpus_allowed);
nodes_setall(top_cpuset.mems_allowed);
cpumask_setall(top_cpuset.effective_cpus);
nodes_setall(top_cpuset.effective_mems);
fmeter_init(&top_cpuset.fmeter);
set_bit(CS_SCHED_LOAD_BALANCE, &top_cpuset.flags);
top_cpuset.relax_domain_level = -1;
err = register_filesystem(&cpuset_fs_type);
if (err < 0)
return err;
if (!alloc_cpumask_var(&cpus_attach, GFP_KERNEL))
BUG();
return 0;
}
static void remove_tasks_in_empty_cpuset(struct cpuset *cs)
{
struct cpuset *parent;
parent = parent_cs(cs);
while (cpumask_empty(parent->cpus_allowed) ||
nodes_empty(parent->mems_allowed))
parent = parent_cs(parent);
if (cgroup_transfer_tasks(parent->css.cgroup, cs->css.cgroup)) {
pr_err("cpuset: failed to transfer tasks out of empty cpuset ");
pr_cont_cgroup_name(cs->css.cgroup);
pr_cont("\n");
}
}
static void
hotplug_update_tasks_legacy(struct cpuset *cs,
struct cpumask *new_cpus, nodemask_t *new_mems,
bool cpus_updated, bool mems_updated)
{
bool is_empty;
spin_lock_irq(&callback_lock);
cpumask_copy(cs->cpus_allowed, new_cpus);
cpumask_copy(cs->effective_cpus, new_cpus);
cs->mems_allowed = *new_mems;
cs->effective_mems = *new_mems;
spin_unlock_irq(&callback_lock);
if (cpus_updated && !cpumask_empty(cs->cpus_allowed))
update_tasks_cpumask(cs);
if (mems_updated && !nodes_empty(cs->mems_allowed))
update_tasks_nodemask(cs);
is_empty = cpumask_empty(cs->cpus_allowed) ||
nodes_empty(cs->mems_allowed);
mutex_unlock(&cpuset_mutex);
if (is_empty)
remove_tasks_in_empty_cpuset(cs);
mutex_lock(&cpuset_mutex);
}
static void
hotplug_update_tasks(struct cpuset *cs,
struct cpumask *new_cpus, nodemask_t *new_mems,
bool cpus_updated, bool mems_updated)
{
if (cpumask_empty(new_cpus))
cpumask_copy(new_cpus, parent_cs(cs)->effective_cpus);
if (nodes_empty(*new_mems))
*new_mems = parent_cs(cs)->effective_mems;
spin_lock_irq(&callback_lock);
cpumask_copy(cs->effective_cpus, new_cpus);
cs->effective_mems = *new_mems;
spin_unlock_irq(&callback_lock);
if (cpus_updated)
update_tasks_cpumask(cs);
if (mems_updated)
update_tasks_nodemask(cs);
}
static void cpuset_hotplug_update_tasks(struct cpuset *cs)
{
static cpumask_t new_cpus;
static nodemask_t new_mems;
bool cpus_updated;
bool mems_updated;
retry:
wait_event(cpuset_attach_wq, cs->attach_in_progress == 0);
mutex_lock(&cpuset_mutex);
if (cs->attach_in_progress) {
mutex_unlock(&cpuset_mutex);
goto retry;
}
cpumask_and(&new_cpus, cs->cpus_allowed, parent_cs(cs)->effective_cpus);
nodes_and(new_mems, cs->mems_allowed, parent_cs(cs)->effective_mems);
cpus_updated = !cpumask_equal(&new_cpus, cs->effective_cpus);
mems_updated = !nodes_equal(new_mems, cs->effective_mems);
if (cgroup_on_dfl(cs->css.cgroup))
hotplug_update_tasks(cs, &new_cpus, &new_mems,
cpus_updated, mems_updated);
else
hotplug_update_tasks_legacy(cs, &new_cpus, &new_mems,
cpus_updated, mems_updated);
mutex_unlock(&cpuset_mutex);
}
static void cpuset_hotplug_workfn(struct work_struct *work)
{
static cpumask_t new_cpus;
static nodemask_t new_mems;
bool cpus_updated, mems_updated;
bool on_dfl = cgroup_on_dfl(top_cpuset.css.cgroup);
mutex_lock(&cpuset_mutex);
cpumask_copy(&new_cpus, cpu_active_mask);
new_mems = node_states[N_MEMORY];
cpus_updated = !cpumask_equal(top_cpuset.effective_cpus, &new_cpus);
mems_updated = !nodes_equal(top_cpuset.effective_mems, new_mems);
if (cpus_updated) {
spin_lock_irq(&callback_lock);
if (!on_dfl)
cpumask_copy(top_cpuset.cpus_allowed, &new_cpus);
cpumask_copy(top_cpuset.effective_cpus, &new_cpus);
spin_unlock_irq(&callback_lock);
}
if (mems_updated) {
spin_lock_irq(&callback_lock);
if (!on_dfl)
top_cpuset.mems_allowed = new_mems;
top_cpuset.effective_mems = new_mems;
spin_unlock_irq(&callback_lock);
update_tasks_nodemask(&top_cpuset);
}
mutex_unlock(&cpuset_mutex);
if (cpus_updated || mems_updated) {
struct cpuset *cs;
struct cgroup_subsys_state *pos_css;
rcu_read_lock();
cpuset_for_each_descendant_pre(cs, pos_css, &top_cpuset) {
if (cs == &top_cpuset || !css_tryget_online(&cs->css))
continue;
rcu_read_unlock();
cpuset_hotplug_update_tasks(cs);
rcu_read_lock();
css_put(&cs->css);
}
rcu_read_unlock();
}
if (cpus_updated)
rebuild_sched_domains();
}
void cpuset_update_active_cpus(bool cpu_online)
{
partition_sched_domains(1, NULL, NULL);
schedule_work(&cpuset_hotplug_work);
}
static int cpuset_track_online_nodes(struct notifier_block *self,
unsigned long action, void *arg)
{
schedule_work(&cpuset_hotplug_work);
return NOTIFY_OK;
}
void __init cpuset_init_smp(void)
{
cpumask_copy(top_cpuset.cpus_allowed, cpu_active_mask);
top_cpuset.mems_allowed = node_states[N_MEMORY];
top_cpuset.old_mems_allowed = top_cpuset.mems_allowed;
cpumask_copy(top_cpuset.effective_cpus, cpu_active_mask);
top_cpuset.effective_mems = node_states[N_MEMORY];
register_hotmemory_notifier(&cpuset_track_online_nodes_nb);
}
void cpuset_cpus_allowed(struct task_struct *tsk, struct cpumask *pmask)
{
unsigned long flags;
spin_lock_irqsave(&callback_lock, flags);
rcu_read_lock();
guarantee_online_cpus(task_cs(tsk), pmask);
rcu_read_unlock();
spin_unlock_irqrestore(&callback_lock, flags);
}
void cpuset_cpus_allowed_fallback(struct task_struct *tsk)
{
rcu_read_lock();
do_set_cpus_allowed(tsk, task_cs(tsk)->effective_cpus);
rcu_read_unlock();
}
void __init cpuset_init_current_mems_allowed(void)
{
nodes_setall(current->mems_allowed);
}
nodemask_t cpuset_mems_allowed(struct task_struct *tsk)
{
nodemask_t mask;
unsigned long flags;
spin_lock_irqsave(&callback_lock, flags);
rcu_read_lock();
guarantee_online_mems(task_cs(tsk), &mask);
rcu_read_unlock();
spin_unlock_irqrestore(&callback_lock, flags);
return mask;
}
int cpuset_nodemask_valid_mems_allowed(nodemask_t *nodemask)
{
return nodes_intersects(*nodemask, current->mems_allowed);
}
static struct cpuset *nearest_hardwall_ancestor(struct cpuset *cs)
{
while (!(is_mem_exclusive(cs) || is_mem_hardwall(cs)) && parent_cs(cs))
cs = parent_cs(cs);
return cs;
}
int __cpuset_node_allowed(int node, gfp_t gfp_mask)
{
struct cpuset *cs;
int allowed;
unsigned long flags;
if (in_interrupt() || (gfp_mask & __GFP_THISNODE))
return 1;
if (node_isset(node, current->mems_allowed))
return 1;
if (unlikely(test_thread_flag(TIF_MEMDIE)))
return 1;
if (gfp_mask & __GFP_HARDWALL)
return 0;
if (current->flags & PF_EXITING)
return 1;
spin_lock_irqsave(&callback_lock, flags);
rcu_read_lock();
cs = nearest_hardwall_ancestor(task_cs(current));
allowed = node_isset(node, cs->mems_allowed);
rcu_read_unlock();
spin_unlock_irqrestore(&callback_lock, flags);
return allowed;
}
static int cpuset_spread_node(int *rotor)
{
int node;
node = next_node(*rotor, current->mems_allowed);
if (node == MAX_NUMNODES)
node = first_node(current->mems_allowed);
*rotor = node;
return node;
}
int cpuset_mem_spread_node(void)
{
if (current->cpuset_mem_spread_rotor == NUMA_NO_NODE)
current->cpuset_mem_spread_rotor =
node_random(&current->mems_allowed);
return cpuset_spread_node(&current->cpuset_mem_spread_rotor);
}
int cpuset_slab_spread_node(void)
{
if (current->cpuset_slab_spread_rotor == NUMA_NO_NODE)
current->cpuset_slab_spread_rotor =
node_random(&current->mems_allowed);
return cpuset_spread_node(&current->cpuset_slab_spread_rotor);
}
int cpuset_mems_allowed_intersects(const struct task_struct *tsk1,
const struct task_struct *tsk2)
{
return nodes_intersects(tsk1->mems_allowed, tsk2->mems_allowed);
}
void cpuset_print_task_mems_allowed(struct task_struct *tsk)
{
struct cgroup *cgrp;
rcu_read_lock();
cgrp = task_cs(tsk)->css.cgroup;
pr_info("%s cpuset=", tsk->comm);
pr_cont_cgroup_name(cgrp);
pr_cont(" mems_allowed=%*pbl\n", nodemask_pr_args(&tsk->mems_allowed));
rcu_read_unlock();
}
void __cpuset_memory_pressure_bump(void)
{
rcu_read_lock();
fmeter_markevent(&task_cs(current)->fmeter);
rcu_read_unlock();
}
int proc_cpuset_show(struct seq_file *m, struct pid_namespace *ns,
struct pid *pid, struct task_struct *tsk)
{
char *buf, *p;
struct cgroup_subsys_state *css;
int retval;
retval = -ENOMEM;
buf = kmalloc(PATH_MAX, GFP_KERNEL);
if (!buf)
goto out;
retval = -ENAMETOOLONG;
rcu_read_lock();
css = task_css(tsk, cpuset_cgrp_id);
p = cgroup_path(css->cgroup, buf, PATH_MAX);
rcu_read_unlock();
if (!p)
goto out_free;
seq_puts(m, p);
seq_putc(m, '\n');
retval = 0;
out_free:
kfree(buf);
out:
return retval;
}
void cpuset_task_status_allowed(struct seq_file *m, struct task_struct *task)
{
seq_printf(m, "Mems_allowed:\t%*pb\n",
nodemask_pr_args(&task->mems_allowed));
seq_printf(m, "Mems_allowed_list:\t%*pbl\n",
nodemask_pr_args(&task->mems_allowed));
}
