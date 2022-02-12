static inline struct freezer *cgroup_freezer(
struct cgroup *cgroup)
{
return container_of(
cgroup_subsys_state(cgroup, freezer_subsys_id),
struct freezer, css);
}
static inline struct freezer *task_freezer(struct task_struct *task)
{
return container_of(task_subsys_state(task, freezer_subsys_id),
struct freezer, css);
}
static inline int __cgroup_freezing_or_frozen(struct task_struct *task)
{
enum freezer_state state = task_freezer(task)->state;
return (state == CGROUP_FREEZING) || (state == CGROUP_FROZEN);
}
int cgroup_freezing_or_frozen(struct task_struct *task)
{
int result;
task_lock(task);
result = __cgroup_freezing_or_frozen(task);
task_unlock(task);
return result;
}
static struct cgroup_subsys_state *freezer_create(struct cgroup_subsys *ss,
struct cgroup *cgroup)
{
struct freezer *freezer;
freezer = kzalloc(sizeof(struct freezer), GFP_KERNEL);
if (!freezer)
return ERR_PTR(-ENOMEM);
spin_lock_init(&freezer->lock);
freezer->state = CGROUP_THAWED;
return &freezer->css;
}
static void freezer_destroy(struct cgroup_subsys *ss,
struct cgroup *cgroup)
{
kfree(cgroup_freezer(cgroup));
}
static int freezer_can_attach(struct cgroup_subsys *ss,
struct cgroup *new_cgroup,
struct task_struct *task)
{
struct freezer *freezer;
freezer = cgroup_freezer(new_cgroup);
if (freezer->state != CGROUP_THAWED)
return -EBUSY;
return 0;
}
static int freezer_can_attach_task(struct cgroup *cgrp, struct task_struct *tsk)
{
rcu_read_lock();
if (__cgroup_freezing_or_frozen(tsk)) {
rcu_read_unlock();
return -EBUSY;
}
rcu_read_unlock();
return 0;
}
static void freezer_fork(struct cgroup_subsys *ss, struct task_struct *task)
{
struct freezer *freezer;
rcu_read_lock();
freezer = task_freezer(task);
rcu_read_unlock();
if (!freezer->css.cgroup->parent)
return;
spin_lock_irq(&freezer->lock);
BUG_ON(freezer->state == CGROUP_FROZEN);
if (freezer->state == CGROUP_FREEZING)
freeze_task(task, true);
spin_unlock_irq(&freezer->lock);
}
static void update_if_frozen(struct cgroup *cgroup,
struct freezer *freezer)
{
struct cgroup_iter it;
struct task_struct *task;
unsigned int nfrozen = 0, ntotal = 0;
enum freezer_state old_state = freezer->state;
cgroup_iter_start(cgroup, &it);
while ((task = cgroup_iter_next(cgroup, &it))) {
ntotal++;
if (frozen(task))
nfrozen++;
}
if (old_state == CGROUP_THAWED) {
BUG_ON(nfrozen > 0);
} else if (old_state == CGROUP_FREEZING) {
if (nfrozen == ntotal)
freezer->state = CGROUP_FROZEN;
} else {
BUG_ON(nfrozen != ntotal);
}
cgroup_iter_end(cgroup, &it);
}
static int freezer_read(struct cgroup *cgroup, struct cftype *cft,
struct seq_file *m)
{
struct freezer *freezer;
enum freezer_state state;
if (!cgroup_lock_live_group(cgroup))
return -ENODEV;
freezer = cgroup_freezer(cgroup);
spin_lock_irq(&freezer->lock);
state = freezer->state;
if (state == CGROUP_FREEZING) {
update_if_frozen(cgroup, freezer);
state = freezer->state;
}
spin_unlock_irq(&freezer->lock);
cgroup_unlock();
seq_puts(m, freezer_state_strs[state]);
seq_putc(m, '\n');
return 0;
}
static int try_to_freeze_cgroup(struct cgroup *cgroup, struct freezer *freezer)
{
struct cgroup_iter it;
struct task_struct *task;
unsigned int num_cant_freeze_now = 0;
freezer->state = CGROUP_FREEZING;
cgroup_iter_start(cgroup, &it);
while ((task = cgroup_iter_next(cgroup, &it))) {
if (!freeze_task(task, true))
continue;
if (frozen(task))
continue;
if (!freezing(task) && !freezer_should_skip(task))
num_cant_freeze_now++;
}
cgroup_iter_end(cgroup, &it);
return num_cant_freeze_now ? -EBUSY : 0;
}
static void unfreeze_cgroup(struct cgroup *cgroup, struct freezer *freezer)
{
struct cgroup_iter it;
struct task_struct *task;
cgroup_iter_start(cgroup, &it);
while ((task = cgroup_iter_next(cgroup, &it))) {
thaw_process(task);
}
cgroup_iter_end(cgroup, &it);
freezer->state = CGROUP_THAWED;
}
static int freezer_change_state(struct cgroup *cgroup,
enum freezer_state goal_state)
{
struct freezer *freezer;
int retval = 0;
freezer = cgroup_freezer(cgroup);
spin_lock_irq(&freezer->lock);
update_if_frozen(cgroup, freezer);
if (goal_state == freezer->state)
goto out;
switch (goal_state) {
case CGROUP_THAWED:
unfreeze_cgroup(cgroup, freezer);
break;
case CGROUP_FROZEN:
retval = try_to_freeze_cgroup(cgroup, freezer);
break;
default:
BUG();
}
out:
spin_unlock_irq(&freezer->lock);
return retval;
}
static int freezer_write(struct cgroup *cgroup,
struct cftype *cft,
const char *buffer)
{
int retval;
enum freezer_state goal_state;
if (strcmp(buffer, freezer_state_strs[CGROUP_THAWED]) == 0)
goal_state = CGROUP_THAWED;
else if (strcmp(buffer, freezer_state_strs[CGROUP_FROZEN]) == 0)
goal_state = CGROUP_FROZEN;
else
return -EINVAL;
if (!cgroup_lock_live_group(cgroup))
return -ENODEV;
retval = freezer_change_state(cgroup, goal_state);
cgroup_unlock();
return retval;
}
static int freezer_populate(struct cgroup_subsys *ss, struct cgroup *cgroup)
{
if (!cgroup->parent)
return 0;
return cgroup_add_files(cgroup, ss, files, ARRAY_SIZE(files));
}
