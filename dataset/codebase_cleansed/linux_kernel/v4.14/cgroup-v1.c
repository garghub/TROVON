bool cgroup1_ssid_disabled(int ssid)
{
return cgroup_no_v1_mask & (1 << ssid);
}
int cgroup_attach_task_all(struct task_struct *from, struct task_struct *tsk)
{
struct cgroup_root *root;
int retval = 0;
mutex_lock(&cgroup_mutex);
percpu_down_write(&cgroup_threadgroup_rwsem);
for_each_root(root) {
struct cgroup *from_cgrp;
if (root == &cgrp_dfl_root)
continue;
spin_lock_irq(&css_set_lock);
from_cgrp = task_cgroup_from_root(from, root);
spin_unlock_irq(&css_set_lock);
retval = cgroup_attach_task(from_cgrp, tsk, false);
if (retval)
break;
}
percpu_up_write(&cgroup_threadgroup_rwsem);
mutex_unlock(&cgroup_mutex);
return retval;
}
int cgroup_transfer_tasks(struct cgroup *to, struct cgroup *from)
{
DEFINE_CGROUP_MGCTX(mgctx);
struct cgrp_cset_link *link;
struct css_task_iter it;
struct task_struct *task;
int ret;
if (cgroup_on_dfl(to))
return -EINVAL;
ret = cgroup_migrate_vet_dst(to);
if (ret)
return ret;
mutex_lock(&cgroup_mutex);
percpu_down_write(&cgroup_threadgroup_rwsem);
spin_lock_irq(&css_set_lock);
list_for_each_entry(link, &from->cset_links, cset_link)
cgroup_migrate_add_src(link->cset, to, &mgctx);
spin_unlock_irq(&css_set_lock);
ret = cgroup_migrate_prepare_dst(&mgctx);
if (ret)
goto out_err;
do {
css_task_iter_start(&from->self, 0, &it);
task = css_task_iter_next(&it);
if (task)
get_task_struct(task);
css_task_iter_end(&it);
if (task) {
ret = cgroup_migrate(task, false, &mgctx);
if (!ret)
trace_cgroup_transfer_tasks(to, task, false);
put_task_struct(task);
}
} while (task && !ret);
out_err:
cgroup_migrate_finish(&mgctx);
percpu_up_write(&cgroup_threadgroup_rwsem);
mutex_unlock(&cgroup_mutex);
return ret;
}
static void *pidlist_allocate(int count)
{
if (PIDLIST_TOO_LARGE(count))
return vmalloc(count * sizeof(pid_t));
else
return kmalloc(count * sizeof(pid_t), GFP_KERNEL);
}
static void pidlist_free(void *p)
{
kvfree(p);
}
void cgroup1_pidlist_destroy_all(struct cgroup *cgrp)
{
struct cgroup_pidlist *l, *tmp_l;
mutex_lock(&cgrp->pidlist_mutex);
list_for_each_entry_safe(l, tmp_l, &cgrp->pidlists, links)
mod_delayed_work(cgroup_pidlist_destroy_wq, &l->destroy_dwork, 0);
mutex_unlock(&cgrp->pidlist_mutex);
flush_workqueue(cgroup_pidlist_destroy_wq);
BUG_ON(!list_empty(&cgrp->pidlists));
}
static void cgroup_pidlist_destroy_work_fn(struct work_struct *work)
{
struct delayed_work *dwork = to_delayed_work(work);
struct cgroup_pidlist *l = container_of(dwork, struct cgroup_pidlist,
destroy_dwork);
struct cgroup_pidlist *tofree = NULL;
mutex_lock(&l->owner->pidlist_mutex);
if (!delayed_work_pending(dwork)) {
list_del(&l->links);
pidlist_free(l->list);
put_pid_ns(l->key.ns);
tofree = l;
}
mutex_unlock(&l->owner->pidlist_mutex);
kfree(tofree);
}
static int pidlist_uniq(pid_t *list, int length)
{
int src, dest = 1;
if (length == 0 || length == 1)
return length;
for (src = 1; src < length; src++) {
while (list[src] == list[src-1]) {
src++;
if (src == length)
goto after;
}
list[dest] = list[src];
dest++;
}
after:
return dest;
}
static int cmppid(const void *a, const void *b)
{
return *(pid_t *)a - *(pid_t *)b;
}
static struct cgroup_pidlist *cgroup_pidlist_find(struct cgroup *cgrp,
enum cgroup_filetype type)
{
struct cgroup_pidlist *l;
struct pid_namespace *ns = task_active_pid_ns(current);
lockdep_assert_held(&cgrp->pidlist_mutex);
list_for_each_entry(l, &cgrp->pidlists, links)
if (l->key.type == type && l->key.ns == ns)
return l;
return NULL;
}
static struct cgroup_pidlist *cgroup_pidlist_find_create(struct cgroup *cgrp,
enum cgroup_filetype type)
{
struct cgroup_pidlist *l;
lockdep_assert_held(&cgrp->pidlist_mutex);
l = cgroup_pidlist_find(cgrp, type);
if (l)
return l;
l = kzalloc(sizeof(struct cgroup_pidlist), GFP_KERNEL);
if (!l)
return l;
INIT_DELAYED_WORK(&l->destroy_dwork, cgroup_pidlist_destroy_work_fn);
l->key.type = type;
l->key.ns = get_pid_ns(task_active_pid_ns(current));
l->owner = cgrp;
list_add(&l->links, &cgrp->pidlists);
return l;
}
int cgroup_task_count(const struct cgroup *cgrp)
{
int count = 0;
struct cgrp_cset_link *link;
spin_lock_irq(&css_set_lock);
list_for_each_entry(link, &cgrp->cset_links, cset_link)
count += link->cset->nr_tasks;
spin_unlock_irq(&css_set_lock);
return count;
}
static int pidlist_array_load(struct cgroup *cgrp, enum cgroup_filetype type,
struct cgroup_pidlist **lp)
{
pid_t *array;
int length;
int pid, n = 0;
struct css_task_iter it;
struct task_struct *tsk;
struct cgroup_pidlist *l;
lockdep_assert_held(&cgrp->pidlist_mutex);
length = cgroup_task_count(cgrp);
array = pidlist_allocate(length);
if (!array)
return -ENOMEM;
css_task_iter_start(&cgrp->self, 0, &it);
while ((tsk = css_task_iter_next(&it))) {
if (unlikely(n == length))
break;
if (type == CGROUP_FILE_PROCS)
pid = task_tgid_vnr(tsk);
else
pid = task_pid_vnr(tsk);
if (pid > 0)
array[n++] = pid;
}
css_task_iter_end(&it);
length = n;
sort(array, length, sizeof(pid_t), cmppid, NULL);
if (type == CGROUP_FILE_PROCS)
length = pidlist_uniq(array, length);
l = cgroup_pidlist_find_create(cgrp, type);
if (!l) {
pidlist_free(array);
return -ENOMEM;
}
pidlist_free(l->list);
l->list = array;
l->length = length;
*lp = l;
return 0;
}
static void *cgroup_pidlist_start(struct seq_file *s, loff_t *pos)
{
struct kernfs_open_file *of = s->private;
struct cgroup *cgrp = seq_css(s)->cgroup;
struct cgroup_pidlist *l;
enum cgroup_filetype type = seq_cft(s)->private;
int index = 0, pid = *pos;
int *iter, ret;
mutex_lock(&cgrp->pidlist_mutex);
if (of->priv)
of->priv = cgroup_pidlist_find(cgrp, type);
if (!of->priv) {
ret = pidlist_array_load(cgrp, type,
(struct cgroup_pidlist **)&of->priv);
if (ret)
return ERR_PTR(ret);
}
l = of->priv;
if (pid) {
int end = l->length;
while (index < end) {
int mid = (index + end) / 2;
if (l->list[mid] == pid) {
index = mid;
break;
} else if (l->list[mid] <= pid)
index = mid + 1;
else
end = mid;
}
}
if (index >= l->length)
return NULL;
iter = l->list + index;
*pos = *iter;
return iter;
}
static void cgroup_pidlist_stop(struct seq_file *s, void *v)
{
struct kernfs_open_file *of = s->private;
struct cgroup_pidlist *l = of->priv;
if (l)
mod_delayed_work(cgroup_pidlist_destroy_wq, &l->destroy_dwork,
CGROUP_PIDLIST_DESTROY_DELAY);
mutex_unlock(&seq_css(s)->cgroup->pidlist_mutex);
}
static void *cgroup_pidlist_next(struct seq_file *s, void *v, loff_t *pos)
{
struct kernfs_open_file *of = s->private;
struct cgroup_pidlist *l = of->priv;
pid_t *p = v;
pid_t *end = l->list + l->length;
p++;
if (p >= end) {
return NULL;
} else {
*pos = *p;
return p;
}
}
static int cgroup_pidlist_show(struct seq_file *s, void *v)
{
seq_printf(s, "%d\n", *(int *)v);
return 0;
}
static ssize_t __cgroup1_procs_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off,
bool threadgroup)
{
struct cgroup *cgrp;
struct task_struct *task;
const struct cred *cred, *tcred;
ssize_t ret;
cgrp = cgroup_kn_lock_live(of->kn, false);
if (!cgrp)
return -ENODEV;
task = cgroup_procs_write_start(buf, threadgroup);
ret = PTR_ERR_OR_ZERO(task);
if (ret)
goto out_unlock;
cred = current_cred();
tcred = get_task_cred(task);
if (!uid_eq(cred->euid, GLOBAL_ROOT_UID) &&
!uid_eq(cred->euid, tcred->uid) &&
!uid_eq(cred->euid, tcred->suid))
ret = -EACCES;
put_cred(tcred);
if (ret)
goto out_finish;
ret = cgroup_attach_task(cgrp, task, threadgroup);
out_finish:
cgroup_procs_write_finish(task);
out_unlock:
cgroup_kn_unlock(of->kn);
return ret ?: nbytes;
}
static ssize_t cgroup1_procs_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
return __cgroup1_procs_write(of, buf, nbytes, off, true);
}
static ssize_t cgroup1_tasks_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
return __cgroup1_procs_write(of, buf, nbytes, off, false);
}
static ssize_t cgroup_release_agent_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct cgroup *cgrp;
BUILD_BUG_ON(sizeof(cgrp->root->release_agent_path) < PATH_MAX);
cgrp = cgroup_kn_lock_live(of->kn, false);
if (!cgrp)
return -ENODEV;
spin_lock(&release_agent_path_lock);
strlcpy(cgrp->root->release_agent_path, strstrip(buf),
sizeof(cgrp->root->release_agent_path));
spin_unlock(&release_agent_path_lock);
cgroup_kn_unlock(of->kn);
return nbytes;
}
static int cgroup_release_agent_show(struct seq_file *seq, void *v)
{
struct cgroup *cgrp = seq_css(seq)->cgroup;
spin_lock(&release_agent_path_lock);
seq_puts(seq, cgrp->root->release_agent_path);
spin_unlock(&release_agent_path_lock);
seq_putc(seq, '\n');
return 0;
}
static int cgroup_sane_behavior_show(struct seq_file *seq, void *v)
{
seq_puts(seq, "0\n");
return 0;
}
static u64 cgroup_read_notify_on_release(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return notify_on_release(css->cgroup);
}
static int cgroup_write_notify_on_release(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
if (val)
set_bit(CGRP_NOTIFY_ON_RELEASE, &css->cgroup->flags);
else
clear_bit(CGRP_NOTIFY_ON_RELEASE, &css->cgroup->flags);
return 0;
}
static u64 cgroup_clone_children_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return test_bit(CGRP_CPUSET_CLONE_CHILDREN, &css->cgroup->flags);
}
static int cgroup_clone_children_write(struct cgroup_subsys_state *css,
struct cftype *cft, u64 val)
{
if (val)
set_bit(CGRP_CPUSET_CLONE_CHILDREN, &css->cgroup->flags);
else
clear_bit(CGRP_CPUSET_CLONE_CHILDREN, &css->cgroup->flags);
return 0;
}
static int proc_cgroupstats_show(struct seq_file *m, void *v)
{
struct cgroup_subsys *ss;
int i;
seq_puts(m, "#subsys_name\thierarchy\tnum_cgroups\tenabled\n");
mutex_lock(&cgroup_mutex);
for_each_subsys(ss, i)
seq_printf(m, "%s\t%d\t%d\t%d\n",
ss->legacy_name, ss->root->hierarchy_id,
atomic_read(&ss->root->nr_cgrps),
cgroup_ssid_enabled(i));
mutex_unlock(&cgroup_mutex);
return 0;
}
static int cgroupstats_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_cgroupstats_show, NULL);
}
int cgroupstats_build(struct cgroupstats *stats, struct dentry *dentry)
{
struct kernfs_node *kn = kernfs_node_from_dentry(dentry);
struct cgroup *cgrp;
struct css_task_iter it;
struct task_struct *tsk;
if (dentry->d_sb->s_type != &cgroup_fs_type || !kn ||
kernfs_type(kn) != KERNFS_DIR)
return -EINVAL;
mutex_lock(&cgroup_mutex);
rcu_read_lock();
cgrp = rcu_dereference(*(void __rcu __force **)&kn->priv);
if (!cgrp || cgroup_is_dead(cgrp)) {
rcu_read_unlock();
mutex_unlock(&cgroup_mutex);
return -ENOENT;
}
rcu_read_unlock();
css_task_iter_start(&cgrp->self, 0, &it);
while ((tsk = css_task_iter_next(&it))) {
switch (tsk->state) {
case TASK_RUNNING:
stats->nr_running++;
break;
case TASK_INTERRUPTIBLE:
stats->nr_sleeping++;
break;
case TASK_UNINTERRUPTIBLE:
stats->nr_uninterruptible++;
break;
case TASK_STOPPED:
stats->nr_stopped++;
break;
default:
if (delayacct_is_task_waiting_on_io(tsk))
stats->nr_io_wait++;
break;
}
}
css_task_iter_end(&it);
mutex_unlock(&cgroup_mutex);
return 0;
}
void cgroup1_check_for_release(struct cgroup *cgrp)
{
if (notify_on_release(cgrp) && !cgroup_is_populated(cgrp) &&
!css_has_online_children(&cgrp->self) && !cgroup_is_dead(cgrp))
schedule_work(&cgrp->release_agent_work);
}
void cgroup1_release_agent(struct work_struct *work)
{
struct cgroup *cgrp =
container_of(work, struct cgroup, release_agent_work);
char *pathbuf = NULL, *agentbuf = NULL;
char *argv[3], *envp[3];
int ret;
mutex_lock(&cgroup_mutex);
pathbuf = kmalloc(PATH_MAX, GFP_KERNEL);
agentbuf = kstrdup(cgrp->root->release_agent_path, GFP_KERNEL);
if (!pathbuf || !agentbuf)
goto out;
spin_lock_irq(&css_set_lock);
ret = cgroup_path_ns_locked(cgrp, pathbuf, PATH_MAX, &init_cgroup_ns);
spin_unlock_irq(&css_set_lock);
if (ret < 0 || ret >= PATH_MAX)
goto out;
argv[0] = agentbuf;
argv[1] = pathbuf;
argv[2] = NULL;
envp[0] = "HOME=/";
envp[1] = "PATH=/sbin:/bin:/usr/sbin:/usr/bin";
envp[2] = NULL;
mutex_unlock(&cgroup_mutex);
call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
goto out_free;
out:
mutex_unlock(&cgroup_mutex);
out_free:
kfree(agentbuf);
kfree(pathbuf);
}
static int cgroup1_rename(struct kernfs_node *kn, struct kernfs_node *new_parent,
const char *new_name_str)
{
struct cgroup *cgrp = kn->priv;
int ret;
if (kernfs_type(kn) != KERNFS_DIR)
return -ENOTDIR;
if (kn->parent != new_parent)
return -EIO;
kernfs_break_active_protection(new_parent);
kernfs_break_active_protection(kn);
mutex_lock(&cgroup_mutex);
ret = kernfs_rename(kn, new_parent, new_name_str);
if (!ret)
trace_cgroup_rename(cgrp);
mutex_unlock(&cgroup_mutex);
kernfs_unbreak_active_protection(kn);
kernfs_unbreak_active_protection(new_parent);
return ret;
}
static int cgroup1_show_options(struct seq_file *seq, struct kernfs_root *kf_root)
{
struct cgroup_root *root = cgroup_root_from_kf(kf_root);
struct cgroup_subsys *ss;
int ssid;
for_each_subsys(ss, ssid)
if (root->subsys_mask & (1 << ssid))
seq_show_option(seq, ss->legacy_name, NULL);
if (root->flags & CGRP_ROOT_NOPREFIX)
seq_puts(seq, ",noprefix");
if (root->flags & CGRP_ROOT_XATTR)
seq_puts(seq, ",xattr");
if (root->flags & CGRP_ROOT_CPUSET_V2_MODE)
seq_puts(seq, ",cpuset_v2_mode");
spin_lock(&release_agent_path_lock);
if (strlen(root->release_agent_path))
seq_show_option(seq, "release_agent",
root->release_agent_path);
spin_unlock(&release_agent_path_lock);
if (test_bit(CGRP_CPUSET_CLONE_CHILDREN, &root->cgrp.flags))
seq_puts(seq, ",clone_children");
if (strlen(root->name))
seq_show_option(seq, "name", root->name);
return 0;
}
static int parse_cgroupfs_options(char *data, struct cgroup_sb_opts *opts)
{
char *token, *o = data;
bool all_ss = false, one_ss = false;
u16 mask = U16_MAX;
struct cgroup_subsys *ss;
int nr_opts = 0;
int i;
#ifdef CONFIG_CPUSETS
mask = ~((u16)1 << cpuset_cgrp_id);
#endif
memset(opts, 0, sizeof(*opts));
while ((token = strsep(&o, ",")) != NULL) {
nr_opts++;
if (!*token)
return -EINVAL;
if (!strcmp(token, "none")) {
opts->none = true;
continue;
}
if (!strcmp(token, "all")) {
if (one_ss)
return -EINVAL;
all_ss = true;
continue;
}
if (!strcmp(token, "noprefix")) {
opts->flags |= CGRP_ROOT_NOPREFIX;
continue;
}
if (!strcmp(token, "clone_children")) {
opts->cpuset_clone_children = true;
continue;
}
if (!strcmp(token, "cpuset_v2_mode")) {
opts->flags |= CGRP_ROOT_CPUSET_V2_MODE;
continue;
}
if (!strcmp(token, "xattr")) {
opts->flags |= CGRP_ROOT_XATTR;
continue;
}
if (!strncmp(token, "release_agent=", 14)) {
if (opts->release_agent)
return -EINVAL;
opts->release_agent =
kstrndup(token + 14, PATH_MAX - 1, GFP_KERNEL);
if (!opts->release_agent)
return -ENOMEM;
continue;
}
if (!strncmp(token, "name=", 5)) {
const char *name = token + 5;
if (!strlen(name))
return -EINVAL;
for (i = 0; i < strlen(name); i++) {
char c = name[i];
if (isalnum(c))
continue;
if ((c == '.') || (c == '-') || (c == '_'))
continue;
return -EINVAL;
}
if (opts->name)
return -EINVAL;
opts->name = kstrndup(name,
MAX_CGROUP_ROOT_NAMELEN - 1,
GFP_KERNEL);
if (!opts->name)
return -ENOMEM;
continue;
}
for_each_subsys(ss, i) {
if (strcmp(token, ss->legacy_name))
continue;
if (!cgroup_ssid_enabled(i))
continue;
if (cgroup1_ssid_disabled(i))
continue;
if (all_ss)
return -EINVAL;
opts->subsys_mask |= (1 << i);
one_ss = true;
break;
}
if (i == CGROUP_SUBSYS_COUNT)
return -ENOENT;
}
if (all_ss || (!one_ss && !opts->none && !opts->name))
for_each_subsys(ss, i)
if (cgroup_ssid_enabled(i) && !cgroup1_ssid_disabled(i))
opts->subsys_mask |= (1 << i);
if (!opts->subsys_mask && !opts->name)
return -EINVAL;
if ((opts->flags & CGRP_ROOT_NOPREFIX) && (opts->subsys_mask & mask))
return -EINVAL;
if (opts->subsys_mask && opts->none)
return -EINVAL;
return 0;
}
static int cgroup1_remount(struct kernfs_root *kf_root, int *flags, char *data)
{
int ret = 0;
struct cgroup_root *root = cgroup_root_from_kf(kf_root);
struct cgroup_sb_opts opts;
u16 added_mask, removed_mask;
cgroup_lock_and_drain_offline(&cgrp_dfl_root.cgrp);
ret = parse_cgroupfs_options(data, &opts);
if (ret)
goto out_unlock;
if (opts.subsys_mask != root->subsys_mask || opts.release_agent)
pr_warn("option changes via remount are deprecated (pid=%d comm=%s)\n",
task_tgid_nr(current), current->comm);
added_mask = opts.subsys_mask & ~root->subsys_mask;
removed_mask = root->subsys_mask & ~opts.subsys_mask;
if ((opts.flags ^ root->flags) ||
(opts.name && strcmp(opts.name, root->name))) {
pr_err("option or name mismatch, new: 0x%x \"%s\", old: 0x%x \"%s\"\n",
opts.flags, opts.name ?: "", root->flags, root->name);
ret = -EINVAL;
goto out_unlock;
}
if (!list_empty(&root->cgrp.self.children)) {
ret = -EBUSY;
goto out_unlock;
}
ret = rebind_subsystems(root, added_mask);
if (ret)
goto out_unlock;
WARN_ON(rebind_subsystems(&cgrp_dfl_root, removed_mask));
if (opts.release_agent) {
spin_lock(&release_agent_path_lock);
strcpy(root->release_agent_path, opts.release_agent);
spin_unlock(&release_agent_path_lock);
}
trace_cgroup_remount(root);
out_unlock:
kfree(opts.release_agent);
kfree(opts.name);
mutex_unlock(&cgroup_mutex);
return ret;
}
struct dentry *cgroup1_mount(struct file_system_type *fs_type, int flags,
void *data, unsigned long magic,
struct cgroup_namespace *ns)
{
struct super_block *pinned_sb = NULL;
struct cgroup_sb_opts opts;
struct cgroup_root *root;
struct cgroup_subsys *ss;
struct dentry *dentry;
int i, ret;
bool new_root = false;
cgroup_lock_and_drain_offline(&cgrp_dfl_root.cgrp);
ret = parse_cgroupfs_options(data, &opts);
if (ret)
goto out_unlock;
for_each_subsys(ss, i) {
if (!(opts.subsys_mask & (1 << i)) ||
ss->root == &cgrp_dfl_root)
continue;
if (!percpu_ref_tryget_live(&ss->root->cgrp.self.refcnt)) {
mutex_unlock(&cgroup_mutex);
msleep(10);
ret = restart_syscall();
goto out_free;
}
cgroup_put(&ss->root->cgrp);
}
for_each_root(root) {
bool name_match = false;
if (root == &cgrp_dfl_root)
continue;
if (opts.name) {
if (strcmp(opts.name, root->name))
continue;
name_match = true;
}
if ((opts.subsys_mask || opts.none) &&
(opts.subsys_mask != root->subsys_mask)) {
if (!name_match)
continue;
ret = -EBUSY;
goto out_unlock;
}
if (root->flags ^ opts.flags)
pr_warn("new mount options do not match the existing superblock, will be ignored\n");
pinned_sb = kernfs_pin_sb(root->kf_root, NULL);
if (IS_ERR(pinned_sb) ||
!percpu_ref_tryget_live(&root->cgrp.self.refcnt)) {
mutex_unlock(&cgroup_mutex);
if (!IS_ERR_OR_NULL(pinned_sb))
deactivate_super(pinned_sb);
msleep(10);
ret = restart_syscall();
goto out_free;
}
ret = 0;
goto out_unlock;
}
if (!opts.subsys_mask && !opts.none) {
ret = -EINVAL;
goto out_unlock;
}
if (ns != &init_cgroup_ns) {
ret = -EPERM;
goto out_unlock;
}
root = kzalloc(sizeof(*root), GFP_KERNEL);
if (!root) {
ret = -ENOMEM;
goto out_unlock;
}
new_root = true;
init_cgroup_root(root, &opts);
ret = cgroup_setup_root(root, opts.subsys_mask, PERCPU_REF_INIT_DEAD);
if (ret)
cgroup_free_root(root);
out_unlock:
mutex_unlock(&cgroup_mutex);
out_free:
kfree(opts.release_agent);
kfree(opts.name);
if (ret)
return ERR_PTR(ret);
dentry = cgroup_do_mount(&cgroup_fs_type, flags, root,
CGROUP_SUPER_MAGIC, ns);
if (new_root) {
mutex_lock(&cgroup_mutex);
percpu_ref_reinit(&root->cgrp.self.refcnt);
mutex_unlock(&cgroup_mutex);
}
if (pinned_sb)
deactivate_super(pinned_sb);
return dentry;
}
static int __init cgroup1_wq_init(void)
{
cgroup_pidlist_destroy_wq = alloc_workqueue("cgroup_pidlist_destroy",
0, 1);
BUG_ON(!cgroup_pidlist_destroy_wq);
return 0;
}
static int __init cgroup_no_v1(char *str)
{
struct cgroup_subsys *ss;
char *token;
int i;
while ((token = strsep(&str, ",")) != NULL) {
if (!*token)
continue;
if (!strcmp(token, "all")) {
cgroup_no_v1_mask = U16_MAX;
break;
}
for_each_subsys(ss, i) {
if (strcmp(token, ss->name) &&
strcmp(token, ss->legacy_name))
continue;
cgroup_no_v1_mask |= 1 << i;
}
}
return 1;
}
