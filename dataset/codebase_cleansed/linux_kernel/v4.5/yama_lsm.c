static void yama_relation_cleanup(struct work_struct *work)
{
struct ptrace_relation *relation;
spin_lock(&ptracer_relations_lock);
rcu_read_lock();
list_for_each_entry_rcu(relation, &ptracer_relations, node) {
if (relation->invalid) {
list_del_rcu(&relation->node);
kfree_rcu(relation, rcu);
}
}
rcu_read_unlock();
spin_unlock(&ptracer_relations_lock);
}
static int yama_ptracer_add(struct task_struct *tracer,
struct task_struct *tracee)
{
struct ptrace_relation *relation, *added;
added = kmalloc(sizeof(*added), GFP_KERNEL);
if (!added)
return -ENOMEM;
added->tracee = tracee;
added->tracer = tracer;
added->invalid = false;
spin_lock(&ptracer_relations_lock);
rcu_read_lock();
list_for_each_entry_rcu(relation, &ptracer_relations, node) {
if (relation->invalid)
continue;
if (relation->tracee == tracee) {
list_replace_rcu(&relation->node, &added->node);
kfree_rcu(relation, rcu);
goto out;
}
}
list_add_rcu(&added->node, &ptracer_relations);
out:
rcu_read_unlock();
spin_unlock(&ptracer_relations_lock);
return 0;
}
static void yama_ptracer_del(struct task_struct *tracer,
struct task_struct *tracee)
{
struct ptrace_relation *relation;
bool marked = false;
rcu_read_lock();
list_for_each_entry_rcu(relation, &ptracer_relations, node) {
if (relation->invalid)
continue;
if (relation->tracee == tracee ||
(tracer && relation->tracer == tracer)) {
relation->invalid = true;
marked = true;
}
}
rcu_read_unlock();
if (marked)
schedule_work(&yama_relation_work);
}
void yama_task_free(struct task_struct *task)
{
yama_ptracer_del(task, task);
}
int yama_task_prctl(int option, unsigned long arg2, unsigned long arg3,
unsigned long arg4, unsigned long arg5)
{
int rc = -ENOSYS;
struct task_struct *myself = current;
switch (option) {
case PR_SET_PTRACER:
rcu_read_lock();
if (!thread_group_leader(myself))
myself = rcu_dereference(myself->group_leader);
get_task_struct(myself);
rcu_read_unlock();
if (arg2 == 0) {
yama_ptracer_del(NULL, myself);
rc = 0;
} else if (arg2 == PR_SET_PTRACER_ANY || (int)arg2 == -1) {
rc = yama_ptracer_add(NULL, myself);
} else {
struct task_struct *tracer;
rcu_read_lock();
tracer = find_task_by_vpid(arg2);
if (tracer)
get_task_struct(tracer);
else
rc = -EINVAL;
rcu_read_unlock();
if (tracer) {
rc = yama_ptracer_add(tracer, myself);
put_task_struct(tracer);
}
}
put_task_struct(myself);
break;
}
return rc;
}
static int task_is_descendant(struct task_struct *parent,
struct task_struct *child)
{
int rc = 0;
struct task_struct *walker = child;
if (!parent || !child)
return 0;
rcu_read_lock();
if (!thread_group_leader(parent))
parent = rcu_dereference(parent->group_leader);
while (walker->pid > 0) {
if (!thread_group_leader(walker))
walker = rcu_dereference(walker->group_leader);
if (walker == parent) {
rc = 1;
break;
}
walker = rcu_dereference(walker->real_parent);
}
rcu_read_unlock();
return rc;
}
static int ptracer_exception_found(struct task_struct *tracer,
struct task_struct *tracee)
{
int rc = 0;
struct ptrace_relation *relation;
struct task_struct *parent = NULL;
bool found = false;
rcu_read_lock();
if (!thread_group_leader(tracee))
tracee = rcu_dereference(tracee->group_leader);
list_for_each_entry_rcu(relation, &ptracer_relations, node) {
if (relation->invalid)
continue;
if (relation->tracee == tracee) {
parent = relation->tracer;
found = true;
break;
}
}
if (found && (parent == NULL || task_is_descendant(parent, tracer)))
rc = 1;
rcu_read_unlock();
return rc;
}
static int yama_ptrace_access_check(struct task_struct *child,
unsigned int mode)
{
int rc = 0;
if (mode & PTRACE_MODE_ATTACH) {
switch (ptrace_scope) {
case YAMA_SCOPE_DISABLED:
break;
case YAMA_SCOPE_RELATIONAL:
rcu_read_lock();
if (!task_is_descendant(current, child) &&
!ptracer_exception_found(current, child) &&
!ns_capable(__task_cred(child)->user_ns, CAP_SYS_PTRACE))
rc = -EPERM;
rcu_read_unlock();
break;
case YAMA_SCOPE_CAPABILITY:
rcu_read_lock();
if (!ns_capable(__task_cred(child)->user_ns, CAP_SYS_PTRACE))
rc = -EPERM;
rcu_read_unlock();
break;
case YAMA_SCOPE_NO_ATTACH:
default:
rc = -EPERM;
break;
}
}
if (rc && (mode & PTRACE_MODE_NOAUDIT) == 0) {
printk_ratelimited(KERN_NOTICE
"ptrace of pid %d was attempted by: %s (pid %d)\n",
child->pid, current->comm, current->pid);
}
return rc;
}
int yama_ptrace_traceme(struct task_struct *parent)
{
int rc = 0;
switch (ptrace_scope) {
case YAMA_SCOPE_CAPABILITY:
if (!has_ns_capability(parent, current_user_ns(), CAP_SYS_PTRACE))
rc = -EPERM;
break;
case YAMA_SCOPE_NO_ATTACH:
rc = -EPERM;
break;
}
if (rc) {
printk_ratelimited(KERN_NOTICE
"ptraceme of pid %d was attempted by: %s (pid %d)\n",
current->pid, parent->comm, parent->pid);
}
return rc;
}
static int yama_dointvec_minmax(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table table_copy;
if (write && !capable(CAP_SYS_PTRACE))
return -EPERM;
table_copy = *table;
if (*(int *)table_copy.data == *(int *)table_copy.extra2)
table_copy.extra1 = table_copy.extra2;
return proc_dointvec_minmax(&table_copy, write, buffer, lenp, ppos);
}
static void __init yama_init_sysctl(void)
{
if (!register_sysctl_paths(yama_sysctl_path, yama_sysctl_table))
panic("Yama: sysctl registration failed.\n");
}
static inline void yama_init_sysctl(void) { }
void __init yama_add_hooks(void)
{
pr_info("Yama: becoming mindful.\n");
security_add_hooks(yama_hooks, ARRAY_SIZE(yama_hooks));
yama_init_sysctl();
}
