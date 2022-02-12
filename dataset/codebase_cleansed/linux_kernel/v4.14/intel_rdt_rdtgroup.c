static void closid_init(void)
{
struct rdt_resource *r;
int rdt_min_closid = 32;
for_each_alloc_enabled_rdt_resource(r)
rdt_min_closid = min(rdt_min_closid, r->num_closid);
closid_free_map = BIT_MASK(rdt_min_closid) - 1;
closid_free_map &= ~1;
}
static int closid_alloc(void)
{
u32 closid = ffs(closid_free_map);
if (closid == 0)
return -ENOSPC;
closid--;
closid_free_map &= ~(1 << closid);
return closid;
}
static void closid_free(int closid)
{
closid_free_map |= 1 << closid;
}
static int rdtgroup_kn_set_ugid(struct kernfs_node *kn)
{
struct iattr iattr = { .ia_valid = ATTR_UID | ATTR_GID,
.ia_uid = current_fsuid(),
.ia_gid = current_fsgid(), };
if (uid_eq(iattr.ia_uid, GLOBAL_ROOT_UID) &&
gid_eq(iattr.ia_gid, GLOBAL_ROOT_GID))
return 0;
return kernfs_setattr(kn, &iattr);
}
static int rdtgroup_add_file(struct kernfs_node *parent_kn, struct rftype *rft)
{
struct kernfs_node *kn;
int ret;
kn = __kernfs_create_file(parent_kn, rft->name, rft->mode,
0, rft->kf_ops, rft, NULL, NULL);
if (IS_ERR(kn))
return PTR_ERR(kn);
ret = rdtgroup_kn_set_ugid(kn);
if (ret) {
kernfs_remove(kn);
return ret;
}
return 0;
}
static int rdtgroup_seqfile_show(struct seq_file *m, void *arg)
{
struct kernfs_open_file *of = m->private;
struct rftype *rft = of->kn->priv;
if (rft->seq_show)
return rft->seq_show(of, m, arg);
return 0;
}
static ssize_t rdtgroup_file_write(struct kernfs_open_file *of, char *buf,
size_t nbytes, loff_t off)
{
struct rftype *rft = of->kn->priv;
if (rft->write)
return rft->write(of, buf, nbytes, off);
return -EINVAL;
}
static bool is_cpu_list(struct kernfs_open_file *of)
{
struct rftype *rft = of->kn->priv;
return rft->flags & RFTYPE_FLAGS_CPUS_LIST;
}
static int rdtgroup_cpus_show(struct kernfs_open_file *of,
struct seq_file *s, void *v)
{
struct rdtgroup *rdtgrp;
int ret = 0;
rdtgrp = rdtgroup_kn_lock_live(of->kn);
if (rdtgrp) {
seq_printf(s, is_cpu_list(of) ? "%*pbl\n" : "%*pb\n",
cpumask_pr_args(&rdtgrp->cpu_mask));
} else {
ret = -ENOENT;
}
rdtgroup_kn_unlock(of->kn);
return ret;
}
static void update_cpu_closid_rmid(void *info)
{
struct rdtgroup *r = info;
if (r) {
this_cpu_write(pqr_state.default_closid, r->closid);
this_cpu_write(pqr_state.default_rmid, r->mon.rmid);
}
intel_rdt_sched_in();
}
static void
update_closid_rmid(const struct cpumask *cpu_mask, struct rdtgroup *r)
{
int cpu = get_cpu();
if (cpumask_test_cpu(cpu, cpu_mask))
update_cpu_closid_rmid(r);
smp_call_function_many(cpu_mask, update_cpu_closid_rmid, r, 1);
put_cpu();
}
static int cpus_mon_write(struct rdtgroup *rdtgrp, cpumask_var_t newmask,
cpumask_var_t tmpmask)
{
struct rdtgroup *prgrp = rdtgrp->mon.parent, *crgrp;
struct list_head *head;
cpumask_andnot(tmpmask, newmask, &prgrp->cpu_mask);
if (cpumask_weight(tmpmask))
return -EINVAL;
cpumask_andnot(tmpmask, &rdtgrp->cpu_mask, newmask);
if (cpumask_weight(tmpmask)) {
cpumask_or(&prgrp->cpu_mask, &prgrp->cpu_mask, tmpmask);
update_closid_rmid(tmpmask, prgrp);
}
cpumask_andnot(tmpmask, newmask, &rdtgrp->cpu_mask);
if (cpumask_weight(tmpmask)) {
head = &prgrp->mon.crdtgrp_list;
list_for_each_entry(crgrp, head, mon.crdtgrp_list) {
if (crgrp == rdtgrp)
continue;
cpumask_andnot(&crgrp->cpu_mask, &crgrp->cpu_mask,
tmpmask);
}
update_closid_rmid(tmpmask, rdtgrp);
}
cpumask_copy(&rdtgrp->cpu_mask, newmask);
return 0;
}
static void cpumask_rdtgrp_clear(struct rdtgroup *r, struct cpumask *m)
{
struct rdtgroup *crgrp;
cpumask_andnot(&r->cpu_mask, &r->cpu_mask, m);
list_for_each_entry(crgrp, &r->mon.crdtgrp_list, mon.crdtgrp_list)
cpumask_and(&crgrp->cpu_mask, &r->cpu_mask, &crgrp->cpu_mask);
}
static int cpus_ctrl_write(struct rdtgroup *rdtgrp, cpumask_var_t newmask,
cpumask_var_t tmpmask, cpumask_var_t tmpmask1)
{
struct rdtgroup *r, *crgrp;
struct list_head *head;
cpumask_andnot(tmpmask, &rdtgrp->cpu_mask, newmask);
if (cpumask_weight(tmpmask)) {
if (rdtgrp == &rdtgroup_default)
return -EINVAL;
cpumask_or(&rdtgroup_default.cpu_mask,
&rdtgroup_default.cpu_mask, tmpmask);
update_closid_rmid(tmpmask, &rdtgroup_default);
}
cpumask_andnot(tmpmask, newmask, &rdtgrp->cpu_mask);
if (cpumask_weight(tmpmask)) {
list_for_each_entry(r, &rdt_all_groups, rdtgroup_list) {
if (r == rdtgrp)
continue;
cpumask_and(tmpmask1, &r->cpu_mask, tmpmask);
if (cpumask_weight(tmpmask1))
cpumask_rdtgrp_clear(r, tmpmask1);
}
update_closid_rmid(tmpmask, rdtgrp);
}
cpumask_copy(&rdtgrp->cpu_mask, newmask);
head = &rdtgrp->mon.crdtgrp_list;
list_for_each_entry(crgrp, head, mon.crdtgrp_list) {
cpumask_and(tmpmask, &rdtgrp->cpu_mask, &crgrp->cpu_mask);
update_closid_rmid(tmpmask, rdtgrp);
cpumask_clear(&crgrp->cpu_mask);
}
return 0;
}
static ssize_t rdtgroup_cpus_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
cpumask_var_t tmpmask, newmask, tmpmask1;
struct rdtgroup *rdtgrp;
int ret;
if (!buf)
return -EINVAL;
if (!zalloc_cpumask_var(&tmpmask, GFP_KERNEL))
return -ENOMEM;
if (!zalloc_cpumask_var(&newmask, GFP_KERNEL)) {
free_cpumask_var(tmpmask);
return -ENOMEM;
}
if (!zalloc_cpumask_var(&tmpmask1, GFP_KERNEL)) {
free_cpumask_var(tmpmask);
free_cpumask_var(newmask);
return -ENOMEM;
}
rdtgrp = rdtgroup_kn_lock_live(of->kn);
if (!rdtgrp) {
ret = -ENOENT;
goto unlock;
}
if (is_cpu_list(of))
ret = cpulist_parse(buf, newmask);
else
ret = cpumask_parse(buf, newmask);
if (ret)
goto unlock;
cpumask_andnot(tmpmask, newmask, cpu_online_mask);
if (cpumask_weight(tmpmask)) {
ret = -EINVAL;
goto unlock;
}
if (rdtgrp->type == RDTCTRL_GROUP)
ret = cpus_ctrl_write(rdtgrp, newmask, tmpmask, tmpmask1);
else if (rdtgrp->type == RDTMON_GROUP)
ret = cpus_mon_write(rdtgrp, newmask, tmpmask);
else
ret = -EINVAL;
unlock:
rdtgroup_kn_unlock(of->kn);
free_cpumask_var(tmpmask);
free_cpumask_var(newmask);
free_cpumask_var(tmpmask1);
return ret ?: nbytes;
}
static void move_myself(struct callback_head *head)
{
struct task_move_callback *callback;
struct rdtgroup *rdtgrp;
callback = container_of(head, struct task_move_callback, work);
rdtgrp = callback->rdtgrp;
if (atomic_dec_and_test(&rdtgrp->waitcount) &&
(rdtgrp->flags & RDT_DELETED)) {
current->closid = 0;
current->rmid = 0;
kfree(rdtgrp);
}
preempt_disable();
intel_rdt_sched_in();
preempt_enable();
kfree(callback);
}
static int __rdtgroup_move_task(struct task_struct *tsk,
struct rdtgroup *rdtgrp)
{
struct task_move_callback *callback;
int ret;
callback = kzalloc(sizeof(*callback), GFP_KERNEL);
if (!callback)
return -ENOMEM;
callback->work.func = move_myself;
callback->rdtgrp = rdtgrp;
atomic_inc(&rdtgrp->waitcount);
ret = task_work_add(tsk, &callback->work, true);
if (ret) {
atomic_dec(&rdtgrp->waitcount);
kfree(callback);
} else {
if (rdtgrp->type == RDTCTRL_GROUP) {
tsk->closid = rdtgrp->closid;
tsk->rmid = rdtgrp->mon.rmid;
} else if (rdtgrp->type == RDTMON_GROUP) {
if (rdtgrp->mon.parent->closid == tsk->closid)
tsk->rmid = rdtgrp->mon.rmid;
else
ret = -EINVAL;
}
}
return ret;
}
static int rdtgroup_task_write_permission(struct task_struct *task,
struct kernfs_open_file *of)
{
const struct cred *tcred = get_task_cred(task);
const struct cred *cred = current_cred();
int ret = 0;
if (!uid_eq(cred->euid, GLOBAL_ROOT_UID) &&
!uid_eq(cred->euid, tcred->uid) &&
!uid_eq(cred->euid, tcred->suid))
ret = -EPERM;
put_cred(tcred);
return ret;
}
static int rdtgroup_move_task(pid_t pid, struct rdtgroup *rdtgrp,
struct kernfs_open_file *of)
{
struct task_struct *tsk;
int ret;
rcu_read_lock();
if (pid) {
tsk = find_task_by_vpid(pid);
if (!tsk) {
rcu_read_unlock();
return -ESRCH;
}
} else {
tsk = current;
}
get_task_struct(tsk);
rcu_read_unlock();
ret = rdtgroup_task_write_permission(tsk, of);
if (!ret)
ret = __rdtgroup_move_task(tsk, rdtgrp);
put_task_struct(tsk);
return ret;
}
static ssize_t rdtgroup_tasks_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct rdtgroup *rdtgrp;
int ret = 0;
pid_t pid;
if (kstrtoint(strstrip(buf), 0, &pid) || pid < 0)
return -EINVAL;
rdtgrp = rdtgroup_kn_lock_live(of->kn);
if (rdtgrp)
ret = rdtgroup_move_task(pid, rdtgrp, of);
else
ret = -ENOENT;
rdtgroup_kn_unlock(of->kn);
return ret ?: nbytes;
}
static void show_rdt_tasks(struct rdtgroup *r, struct seq_file *s)
{
struct task_struct *p, *t;
rcu_read_lock();
for_each_process_thread(p, t) {
if ((r->type == RDTCTRL_GROUP && t->closid == r->closid) ||
(r->type == RDTMON_GROUP && t->rmid == r->mon.rmid))
seq_printf(s, "%d\n", t->pid);
}
rcu_read_unlock();
}
static int rdtgroup_tasks_show(struct kernfs_open_file *of,
struct seq_file *s, void *v)
{
struct rdtgroup *rdtgrp;
int ret = 0;
rdtgrp = rdtgroup_kn_lock_live(of->kn);
if (rdtgrp)
show_rdt_tasks(rdtgrp, s);
else
ret = -ENOENT;
rdtgroup_kn_unlock(of->kn);
return ret;
}
static int rdt_num_closids_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
seq_printf(seq, "%d\n", r->num_closid);
return 0;
}
static int rdt_default_ctrl_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
seq_printf(seq, "%x\n", r->default_ctrl);
return 0;
}
static int rdt_min_cbm_bits_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
seq_printf(seq, "%u\n", r->cache.min_cbm_bits);
return 0;
}
static int rdt_shareable_bits_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
seq_printf(seq, "%x\n", r->cache.shareable_bits);
return 0;
}
static int rdt_min_bw_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
seq_printf(seq, "%u\n", r->membw.min_bw);
return 0;
}
static int rdt_num_rmids_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
seq_printf(seq, "%d\n", r->num_rmid);
return 0;
}
static int rdt_mon_features_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
struct mon_evt *mevt;
list_for_each_entry(mevt, &r->evt_list, list)
seq_printf(seq, "%s\n", mevt->name);
return 0;
}
static int rdt_bw_gran_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
seq_printf(seq, "%u\n", r->membw.bw_gran);
return 0;
}
static int rdt_delay_linear_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
seq_printf(seq, "%u\n", r->membw.delay_linear);
return 0;
}
static int max_threshold_occ_show(struct kernfs_open_file *of,
struct seq_file *seq, void *v)
{
struct rdt_resource *r = of->kn->parent->priv;
seq_printf(seq, "%u\n", intel_cqm_threshold * r->mon_scale);
return 0;
}
static ssize_t max_threshold_occ_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct rdt_resource *r = of->kn->parent->priv;
unsigned int bytes;
int ret;
ret = kstrtouint(buf, 0, &bytes);
if (ret)
return ret;
if (bytes > (boot_cpu_data.x86_cache_size * 1024))
return -EINVAL;
intel_cqm_threshold = bytes / r->mon_scale;
return nbytes;
}
static int rdtgroup_add_files(struct kernfs_node *kn, unsigned long fflags)
{
struct rftype *rfts, *rft;
int ret, len;
rfts = res_common_files;
len = ARRAY_SIZE(res_common_files);
lockdep_assert_held(&rdtgroup_mutex);
for (rft = rfts; rft < rfts + len; rft++) {
if ((fflags & rft->fflags) == rft->fflags) {
ret = rdtgroup_add_file(kn, rft);
if (ret)
goto error;
}
}
return 0;
error:
pr_warn("Failed to add %s, err=%d\n", rft->name, ret);
while (--rft >= rfts) {
if ((fflags & rft->fflags) == rft->fflags)
kernfs_remove_by_name(kn, rft->name);
}
return ret;
}
static int rdtgroup_mkdir_info_resdir(struct rdt_resource *r, char *name,
unsigned long fflags)
{
struct kernfs_node *kn_subdir;
int ret;
kn_subdir = kernfs_create_dir(kn_info, name,
kn_info->mode, r);
if (IS_ERR(kn_subdir))
return PTR_ERR(kn_subdir);
kernfs_get(kn_subdir);
ret = rdtgroup_kn_set_ugid(kn_subdir);
if (ret)
return ret;
ret = rdtgroup_add_files(kn_subdir, fflags);
if (!ret)
kernfs_activate(kn_subdir);
return ret;
}
static int rdtgroup_create_info_dir(struct kernfs_node *parent_kn)
{
struct rdt_resource *r;
unsigned long fflags;
char name[32];
int ret;
kn_info = kernfs_create_dir(parent_kn, "info", parent_kn->mode, NULL);
if (IS_ERR(kn_info))
return PTR_ERR(kn_info);
kernfs_get(kn_info);
for_each_alloc_enabled_rdt_resource(r) {
fflags = r->fflags | RF_CTRL_INFO;
ret = rdtgroup_mkdir_info_resdir(r, r->name, fflags);
if (ret)
goto out_destroy;
}
for_each_mon_enabled_rdt_resource(r) {
fflags = r->fflags | RF_MON_INFO;
sprintf(name, "%s_MON", r->name);
ret = rdtgroup_mkdir_info_resdir(r, name, fflags);
if (ret)
goto out_destroy;
}
kernfs_get(kn_info);
ret = rdtgroup_kn_set_ugid(kn_info);
if (ret)
goto out_destroy;
kernfs_activate(kn_info);
return 0;
out_destroy:
kernfs_remove(kn_info);
return ret;
}
static int
mongroup_create_dir(struct kernfs_node *parent_kn, struct rdtgroup *prgrp,
char *name, struct kernfs_node **dest_kn)
{
struct kernfs_node *kn;
int ret;
kn = kernfs_create_dir(parent_kn, name, parent_kn->mode, prgrp);
if (IS_ERR(kn))
return PTR_ERR(kn);
if (dest_kn)
*dest_kn = kn;
kernfs_get(kn);
ret = rdtgroup_kn_set_ugid(kn);
if (ret)
goto out_destroy;
kernfs_activate(kn);
return 0;
out_destroy:
kernfs_remove(kn);
return ret;
}
static void l3_qos_cfg_update(void *arg)
{
bool *enable = arg;
wrmsrl(IA32_L3_QOS_CFG, *enable ? L3_QOS_CDP_ENABLE : 0ULL);
}
static int set_l3_qos_cfg(struct rdt_resource *r, bool enable)
{
cpumask_var_t cpu_mask;
struct rdt_domain *d;
int cpu;
if (!zalloc_cpumask_var(&cpu_mask, GFP_KERNEL))
return -ENOMEM;
list_for_each_entry(d, &r->domains, list) {
cpumask_set_cpu(cpumask_any(&d->cpu_mask), cpu_mask);
}
cpu = get_cpu();
if (cpumask_test_cpu(cpu, cpu_mask))
l3_qos_cfg_update(&enable);
smp_call_function_many(cpu_mask, l3_qos_cfg_update, &enable, 1);
put_cpu();
free_cpumask_var(cpu_mask);
return 0;
}
static int cdp_enable(void)
{
struct rdt_resource *r_l3data = &rdt_resources_all[RDT_RESOURCE_L3DATA];
struct rdt_resource *r_l3code = &rdt_resources_all[RDT_RESOURCE_L3CODE];
struct rdt_resource *r_l3 = &rdt_resources_all[RDT_RESOURCE_L3];
int ret;
if (!r_l3->alloc_capable || !r_l3data->alloc_capable ||
!r_l3code->alloc_capable)
return -EINVAL;
ret = set_l3_qos_cfg(r_l3, true);
if (!ret) {
r_l3->alloc_enabled = false;
r_l3data->alloc_enabled = true;
r_l3code->alloc_enabled = true;
}
return ret;
}
static void cdp_disable(void)
{
struct rdt_resource *r = &rdt_resources_all[RDT_RESOURCE_L3];
r->alloc_enabled = r->alloc_capable;
if (rdt_resources_all[RDT_RESOURCE_L3DATA].alloc_enabled) {
rdt_resources_all[RDT_RESOURCE_L3DATA].alloc_enabled = false;
rdt_resources_all[RDT_RESOURCE_L3CODE].alloc_enabled = false;
set_l3_qos_cfg(r, false);
}
}
static int parse_rdtgroupfs_options(char *data)
{
char *token, *o = data;
int ret = 0;
while ((token = strsep(&o, ",")) != NULL) {
if (!*token)
return -EINVAL;
if (!strcmp(token, "cdp"))
ret = cdp_enable();
}
return ret;
}
static struct rdtgroup *kernfs_to_rdtgroup(struct kernfs_node *kn)
{
if (kernfs_type(kn) == KERNFS_DIR) {
if (kn == kn_info || kn->parent == kn_info)
return NULL;
else
return kn->priv;
} else {
return kn->parent->priv;
}
}
struct rdtgroup *rdtgroup_kn_lock_live(struct kernfs_node *kn)
{
struct rdtgroup *rdtgrp = kernfs_to_rdtgroup(kn);
if (!rdtgrp)
return NULL;
atomic_inc(&rdtgrp->waitcount);
kernfs_break_active_protection(kn);
mutex_lock(&rdtgroup_mutex);
if (rdtgrp->flags & RDT_DELETED)
return NULL;
return rdtgrp;
}
void rdtgroup_kn_unlock(struct kernfs_node *kn)
{
struct rdtgroup *rdtgrp = kernfs_to_rdtgroup(kn);
if (!rdtgrp)
return;
mutex_unlock(&rdtgroup_mutex);
if (atomic_dec_and_test(&rdtgrp->waitcount) &&
(rdtgrp->flags & RDT_DELETED)) {
kernfs_unbreak_active_protection(kn);
kernfs_put(rdtgrp->kn);
kfree(rdtgrp);
} else {
kernfs_unbreak_active_protection(kn);
}
}
static struct dentry *rdt_mount(struct file_system_type *fs_type,
int flags, const char *unused_dev_name,
void *data)
{
struct rdt_domain *dom;
struct rdt_resource *r;
struct dentry *dentry;
int ret;
mutex_lock(&rdtgroup_mutex);
if (static_branch_unlikely(&rdt_enable_key)) {
dentry = ERR_PTR(-EBUSY);
goto out;
}
ret = parse_rdtgroupfs_options(data);
if (ret) {
dentry = ERR_PTR(ret);
goto out_cdp;
}
closid_init();
ret = rdtgroup_create_info_dir(rdtgroup_default.kn);
if (ret) {
dentry = ERR_PTR(ret);
goto out_cdp;
}
if (rdt_mon_capable) {
ret = mongroup_create_dir(rdtgroup_default.kn,
NULL, "mon_groups",
&kn_mongrp);
if (ret) {
dentry = ERR_PTR(ret);
goto out_info;
}
kernfs_get(kn_mongrp);
ret = mkdir_mondata_all(rdtgroup_default.kn,
&rdtgroup_default, &kn_mondata);
if (ret) {
dentry = ERR_PTR(ret);
goto out_mongrp;
}
kernfs_get(kn_mondata);
rdtgroup_default.mon.mon_data_kn = kn_mondata;
}
dentry = kernfs_mount(fs_type, flags, rdt_root,
RDTGROUP_SUPER_MAGIC, NULL);
if (IS_ERR(dentry))
goto out_mondata;
if (rdt_alloc_capable)
static_branch_enable(&rdt_alloc_enable_key);
if (rdt_mon_capable)
static_branch_enable(&rdt_mon_enable_key);
if (rdt_alloc_capable || rdt_mon_capable)
static_branch_enable(&rdt_enable_key);
if (is_mbm_enabled()) {
r = &rdt_resources_all[RDT_RESOURCE_L3];
list_for_each_entry(dom, &r->domains, list)
mbm_setup_overflow_handler(dom, MBM_OVERFLOW_INTERVAL);
}
goto out;
out_mondata:
if (rdt_mon_capable)
kernfs_remove(kn_mondata);
out_mongrp:
if (rdt_mon_capable)
kernfs_remove(kn_mongrp);
out_info:
kernfs_remove(kn_info);
out_cdp:
cdp_disable();
out:
mutex_unlock(&rdtgroup_mutex);
return dentry;
}
static int reset_all_ctrls(struct rdt_resource *r)
{
struct msr_param msr_param;
cpumask_var_t cpu_mask;
struct rdt_domain *d;
int i, cpu;
if (!zalloc_cpumask_var(&cpu_mask, GFP_KERNEL))
return -ENOMEM;
msr_param.res = r;
msr_param.low = 0;
msr_param.high = r->num_closid;
list_for_each_entry(d, &r->domains, list) {
cpumask_set_cpu(cpumask_any(&d->cpu_mask), cpu_mask);
for (i = 0; i < r->num_closid; i++)
d->ctrl_val[i] = r->default_ctrl;
}
cpu = get_cpu();
if (cpumask_test_cpu(cpu, cpu_mask))
rdt_ctrl_update(&msr_param);
smp_call_function_many(cpu_mask, rdt_ctrl_update, &msr_param, 1);
put_cpu();
free_cpumask_var(cpu_mask);
return 0;
}
static bool is_closid_match(struct task_struct *t, struct rdtgroup *r)
{
return (rdt_alloc_capable &&
(r->type == RDTCTRL_GROUP) && (t->closid == r->closid));
}
static bool is_rmid_match(struct task_struct *t, struct rdtgroup *r)
{
return (rdt_mon_capable &&
(r->type == RDTMON_GROUP) && (t->rmid == r->mon.rmid));
}
static void rdt_move_group_tasks(struct rdtgroup *from, struct rdtgroup *to,
struct cpumask *mask)
{
struct task_struct *p, *t;
read_lock(&tasklist_lock);
for_each_process_thread(p, t) {
if (!from || is_closid_match(t, from) ||
is_rmid_match(t, from)) {
t->closid = to->closid;
t->rmid = to->mon.rmid;
#ifdef CONFIG_SMP
if (mask && t->on_cpu)
cpumask_set_cpu(task_cpu(t), mask);
#endif
}
}
read_unlock(&tasklist_lock);
}
static void free_all_child_rdtgrp(struct rdtgroup *rdtgrp)
{
struct rdtgroup *sentry, *stmp;
struct list_head *head;
head = &rdtgrp->mon.crdtgrp_list;
list_for_each_entry_safe(sentry, stmp, head, mon.crdtgrp_list) {
free_rmid(sentry->mon.rmid);
list_del(&sentry->mon.crdtgrp_list);
kfree(sentry);
}
}
static void rmdir_all_sub(void)
{
struct rdtgroup *rdtgrp, *tmp;
rdt_move_group_tasks(NULL, &rdtgroup_default, NULL);
list_for_each_entry_safe(rdtgrp, tmp, &rdt_all_groups, rdtgroup_list) {
free_all_child_rdtgrp(rdtgrp);
if (rdtgrp == &rdtgroup_default)
continue;
cpumask_or(&rdtgroup_default.cpu_mask,
&rdtgroup_default.cpu_mask, &rdtgrp->cpu_mask);
free_rmid(rdtgrp->mon.rmid);
kernfs_remove(rdtgrp->kn);
list_del(&rdtgrp->rdtgroup_list);
kfree(rdtgrp);
}
get_online_cpus();
update_closid_rmid(cpu_online_mask, &rdtgroup_default);
put_online_cpus();
kernfs_remove(kn_info);
kernfs_remove(kn_mongrp);
kernfs_remove(kn_mondata);
}
static void rdt_kill_sb(struct super_block *sb)
{
struct rdt_resource *r;
mutex_lock(&rdtgroup_mutex);
for_each_alloc_enabled_rdt_resource(r)
reset_all_ctrls(r);
cdp_disable();
rmdir_all_sub();
static_branch_disable(&rdt_alloc_enable_key);
static_branch_disable(&rdt_mon_enable_key);
static_branch_disable(&rdt_enable_key);
kernfs_kill_sb(sb);
mutex_unlock(&rdtgroup_mutex);
}
static int mon_addfile(struct kernfs_node *parent_kn, const char *name,
void *priv)
{
struct kernfs_node *kn;
int ret = 0;
kn = __kernfs_create_file(parent_kn, name, 0444, 0,
&kf_mondata_ops, priv, NULL, NULL);
if (IS_ERR(kn))
return PTR_ERR(kn);
ret = rdtgroup_kn_set_ugid(kn);
if (ret) {
kernfs_remove(kn);
return ret;
}
return ret;
}
void rmdir_mondata_subdir_allrdtgrp(struct rdt_resource *r, unsigned int dom_id)
{
struct rdtgroup *prgrp, *crgrp;
char name[32];
if (!r->mon_enabled)
return;
list_for_each_entry(prgrp, &rdt_all_groups, rdtgroup_list) {
sprintf(name, "mon_%s_%02d", r->name, dom_id);
kernfs_remove_by_name(prgrp->mon.mon_data_kn, name);
list_for_each_entry(crgrp, &prgrp->mon.crdtgrp_list, mon.crdtgrp_list)
kernfs_remove_by_name(crgrp->mon.mon_data_kn, name);
}
}
static int mkdir_mondata_subdir(struct kernfs_node *parent_kn,
struct rdt_domain *d,
struct rdt_resource *r, struct rdtgroup *prgrp)
{
union mon_data_bits priv;
struct kernfs_node *kn;
struct mon_evt *mevt;
struct rmid_read rr;
char name[32];
int ret;
sprintf(name, "mon_%s_%02d", r->name, d->id);
kn = kernfs_create_dir(parent_kn, name, parent_kn->mode, prgrp);
if (IS_ERR(kn))
return PTR_ERR(kn);
kernfs_get(kn);
ret = rdtgroup_kn_set_ugid(kn);
if (ret)
goto out_destroy;
if (WARN_ON(list_empty(&r->evt_list))) {
ret = -EPERM;
goto out_destroy;
}
priv.u.rid = r->rid;
priv.u.domid = d->id;
list_for_each_entry(mevt, &r->evt_list, list) {
priv.u.evtid = mevt->evtid;
ret = mon_addfile(kn, mevt->name, priv.priv);
if (ret)
goto out_destroy;
if (is_mbm_event(mevt->evtid))
mon_event_read(&rr, d, prgrp, mevt->evtid, true);
}
kernfs_activate(kn);
return 0;
out_destroy:
kernfs_remove(kn);
return ret;
}
void mkdir_mondata_subdir_allrdtgrp(struct rdt_resource *r,
struct rdt_domain *d)
{
struct kernfs_node *parent_kn;
struct rdtgroup *prgrp, *crgrp;
struct list_head *head;
if (!r->mon_enabled)
return;
list_for_each_entry(prgrp, &rdt_all_groups, rdtgroup_list) {
parent_kn = prgrp->mon.mon_data_kn;
mkdir_mondata_subdir(parent_kn, d, r, prgrp);
head = &prgrp->mon.crdtgrp_list;
list_for_each_entry(crgrp, head, mon.crdtgrp_list) {
parent_kn = crgrp->mon.mon_data_kn;
mkdir_mondata_subdir(parent_kn, d, r, crgrp);
}
}
}
static int mkdir_mondata_subdir_alldom(struct kernfs_node *parent_kn,
struct rdt_resource *r,
struct rdtgroup *prgrp)
{
struct rdt_domain *dom;
int ret;
list_for_each_entry(dom, &r->domains, list) {
ret = mkdir_mondata_subdir(parent_kn, dom, r, prgrp);
if (ret)
return ret;
}
return 0;
}
static int mkdir_mondata_all(struct kernfs_node *parent_kn,
struct rdtgroup *prgrp,
struct kernfs_node **dest_kn)
{
struct rdt_resource *r;
struct kernfs_node *kn;
int ret;
ret = mongroup_create_dir(parent_kn, NULL, "mon_data", &kn);
if (ret)
return ret;
if (dest_kn)
*dest_kn = kn;
for_each_mon_enabled_rdt_resource(r) {
ret = mkdir_mondata_subdir_alldom(kn, r, prgrp);
if (ret)
goto out_destroy;
}
return 0;
out_destroy:
kernfs_remove(kn);
return ret;
}
static int mkdir_rdt_prepare(struct kernfs_node *parent_kn,
struct kernfs_node *prgrp_kn,
const char *name, umode_t mode,
enum rdt_group_type rtype, struct rdtgroup **r)
{
struct rdtgroup *prdtgrp, *rdtgrp;
struct kernfs_node *kn;
uint files = 0;
int ret;
prdtgrp = rdtgroup_kn_lock_live(prgrp_kn);
if (!prdtgrp) {
ret = -ENODEV;
goto out_unlock;
}
rdtgrp = kzalloc(sizeof(*rdtgrp), GFP_KERNEL);
if (!rdtgrp) {
ret = -ENOSPC;
goto out_unlock;
}
*r = rdtgrp;
rdtgrp->mon.parent = prdtgrp;
rdtgrp->type = rtype;
INIT_LIST_HEAD(&rdtgrp->mon.crdtgrp_list);
kn = kernfs_create_dir(parent_kn, name, mode, rdtgrp);
if (IS_ERR(kn)) {
ret = PTR_ERR(kn);
goto out_free_rgrp;
}
rdtgrp->kn = kn;
kernfs_get(kn);
ret = rdtgroup_kn_set_ugid(kn);
if (ret)
goto out_destroy;
files = RFTYPE_BASE | RFTYPE_CTRL;
files = RFTYPE_BASE | BIT(RF_CTRLSHIFT + rtype);
ret = rdtgroup_add_files(kn, files);
if (ret)
goto out_destroy;
if (rdt_mon_capable) {
ret = alloc_rmid();
if (ret < 0)
goto out_destroy;
rdtgrp->mon.rmid = ret;
ret = mkdir_mondata_all(kn, rdtgrp, &rdtgrp->mon.mon_data_kn);
if (ret)
goto out_idfree;
}
kernfs_activate(kn);
return 0;
out_idfree:
free_rmid(rdtgrp->mon.rmid);
out_destroy:
kernfs_remove(rdtgrp->kn);
out_free_rgrp:
kfree(rdtgrp);
out_unlock:
rdtgroup_kn_unlock(prgrp_kn);
return ret;
}
static void mkdir_rdt_prepare_clean(struct rdtgroup *rgrp)
{
kernfs_remove(rgrp->kn);
free_rmid(rgrp->mon.rmid);
kfree(rgrp);
}
static int rdtgroup_mkdir_mon(struct kernfs_node *parent_kn,
struct kernfs_node *prgrp_kn,
const char *name,
umode_t mode)
{
struct rdtgroup *rdtgrp, *prgrp;
int ret;
ret = mkdir_rdt_prepare(parent_kn, prgrp_kn, name, mode, RDTMON_GROUP,
&rdtgrp);
if (ret)
return ret;
prgrp = rdtgrp->mon.parent;
rdtgrp->closid = prgrp->closid;
list_add_tail(&rdtgrp->mon.crdtgrp_list, &prgrp->mon.crdtgrp_list);
rdtgroup_kn_unlock(prgrp_kn);
return ret;
}
static int rdtgroup_mkdir_ctrl_mon(struct kernfs_node *parent_kn,
struct kernfs_node *prgrp_kn,
const char *name, umode_t mode)
{
struct rdtgroup *rdtgrp;
struct kernfs_node *kn;
u32 closid;
int ret;
ret = mkdir_rdt_prepare(parent_kn, prgrp_kn, name, mode, RDTCTRL_GROUP,
&rdtgrp);
if (ret)
return ret;
kn = rdtgrp->kn;
ret = closid_alloc();
if (ret < 0)
goto out_common_fail;
closid = ret;
rdtgrp->closid = closid;
list_add(&rdtgrp->rdtgroup_list, &rdt_all_groups);
if (rdt_mon_capable) {
ret = mongroup_create_dir(kn, NULL, "mon_groups", NULL);
if (ret)
goto out_id_free;
}
goto out_unlock;
out_id_free:
closid_free(closid);
list_del(&rdtgrp->rdtgroup_list);
out_common_fail:
mkdir_rdt_prepare_clean(rdtgrp);
out_unlock:
rdtgroup_kn_unlock(prgrp_kn);
return ret;
}
static bool is_mon_groups(struct kernfs_node *kn, const char *name)
{
return (!strcmp(kn->name, "mon_groups") &&
strcmp(name, "mon_groups"));
}
static int rdtgroup_mkdir(struct kernfs_node *parent_kn, const char *name,
umode_t mode)
{
if (strchr(name, '\n'))
return -EINVAL;
if (rdt_alloc_capable && parent_kn == rdtgroup_default.kn)
return rdtgroup_mkdir_ctrl_mon(parent_kn, parent_kn, name, mode);
if (rdt_mon_capable && is_mon_groups(parent_kn, name))
return rdtgroup_mkdir_mon(parent_kn, parent_kn->parent, name, mode);
return -EPERM;
}
static int rdtgroup_rmdir_mon(struct kernfs_node *kn, struct rdtgroup *rdtgrp,
cpumask_var_t tmpmask)
{
struct rdtgroup *prdtgrp = rdtgrp->mon.parent;
int cpu;
rdt_move_group_tasks(rdtgrp, prdtgrp, tmpmask);
for_each_cpu(cpu, &rdtgrp->cpu_mask)
per_cpu(pqr_state.default_rmid, cpu) = prdtgrp->mon.rmid;
cpumask_or(tmpmask, tmpmask, &rdtgrp->cpu_mask);
update_closid_rmid(tmpmask, NULL);
rdtgrp->flags = RDT_DELETED;
free_rmid(rdtgrp->mon.rmid);
WARN_ON(list_empty(&prdtgrp->mon.crdtgrp_list));
list_del(&rdtgrp->mon.crdtgrp_list);
kernfs_get(kn);
kernfs_remove(rdtgrp->kn);
return 0;
}
static int rdtgroup_rmdir_ctrl(struct kernfs_node *kn, struct rdtgroup *rdtgrp,
cpumask_var_t tmpmask)
{
int cpu;
rdt_move_group_tasks(rdtgrp, &rdtgroup_default, tmpmask);
cpumask_or(&rdtgroup_default.cpu_mask,
&rdtgroup_default.cpu_mask, &rdtgrp->cpu_mask);
for_each_cpu(cpu, &rdtgrp->cpu_mask) {
per_cpu(pqr_state.default_closid, cpu) = rdtgroup_default.closid;
per_cpu(pqr_state.default_rmid, cpu) = rdtgroup_default.mon.rmid;
}
cpumask_or(tmpmask, tmpmask, &rdtgrp->cpu_mask);
update_closid_rmid(tmpmask, NULL);
rdtgrp->flags = RDT_DELETED;
closid_free(rdtgrp->closid);
free_rmid(rdtgrp->mon.rmid);
free_all_child_rdtgrp(rdtgrp);
list_del(&rdtgrp->rdtgroup_list);
kernfs_get(kn);
kernfs_remove(rdtgrp->kn);
return 0;
}
static int rdtgroup_rmdir(struct kernfs_node *kn)
{
struct kernfs_node *parent_kn = kn->parent;
struct rdtgroup *rdtgrp;
cpumask_var_t tmpmask;
int ret = 0;
if (!zalloc_cpumask_var(&tmpmask, GFP_KERNEL))
return -ENOMEM;
rdtgrp = rdtgroup_kn_lock_live(kn);
if (!rdtgrp) {
ret = -EPERM;
goto out;
}
if (rdtgrp->type == RDTCTRL_GROUP && parent_kn == rdtgroup_default.kn)
ret = rdtgroup_rmdir_ctrl(kn, rdtgrp, tmpmask);
else if (rdtgrp->type == RDTMON_GROUP &&
is_mon_groups(parent_kn, kn->name))
ret = rdtgroup_rmdir_mon(kn, rdtgrp, tmpmask);
else
ret = -EPERM;
out:
rdtgroup_kn_unlock(kn);
free_cpumask_var(tmpmask);
return ret;
}
static int rdtgroup_show_options(struct seq_file *seq, struct kernfs_root *kf)
{
if (rdt_resources_all[RDT_RESOURCE_L3DATA].alloc_enabled)
seq_puts(seq, ",cdp");
return 0;
}
static int __init rdtgroup_setup_root(void)
{
int ret;
rdt_root = kernfs_create_root(&rdtgroup_kf_syscall_ops,
KERNFS_ROOT_CREATE_DEACTIVATED,
&rdtgroup_default);
if (IS_ERR(rdt_root))
return PTR_ERR(rdt_root);
mutex_lock(&rdtgroup_mutex);
rdtgroup_default.closid = 0;
rdtgroup_default.mon.rmid = 0;
rdtgroup_default.type = RDTCTRL_GROUP;
INIT_LIST_HEAD(&rdtgroup_default.mon.crdtgrp_list);
list_add(&rdtgroup_default.rdtgroup_list, &rdt_all_groups);
ret = rdtgroup_add_files(rdt_root->kn, RF_CTRL_BASE);
if (ret) {
kernfs_destroy_root(rdt_root);
goto out;
}
rdtgroup_default.kn = rdt_root->kn;
kernfs_activate(rdtgroup_default.kn);
out:
mutex_unlock(&rdtgroup_mutex);
return ret;
}
int __init rdtgroup_init(void)
{
int ret = 0;
ret = rdtgroup_setup_root();
if (ret)
return ret;
ret = sysfs_create_mount_point(fs_kobj, "resctrl");
if (ret)
goto cleanup_root;
ret = register_filesystem(&rdt_fs_type);
if (ret)
goto cleanup_mountpoint;
return 0;
cleanup_mountpoint:
sysfs_remove_mount_point(fs_kobj, "resctrl");
cleanup_root:
kernfs_destroy_root(rdt_root);
return ret;
}
