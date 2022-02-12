static inline struct freezer *css_freezer(struct cgroup_subsys_state *css)
{
return css ? container_of(css, struct freezer, css) : NULL;
}
static inline struct freezer *task_freezer(struct task_struct *task)
{
return css_freezer(task_css(task, freezer_subsys_id));
}
static struct freezer *parent_freezer(struct freezer *freezer)
{
return css_freezer(css_parent(&freezer->css));
}
bool cgroup_freezing(struct task_struct *task)
{
bool ret;
rcu_read_lock();
ret = task_freezer(task)->state & CGROUP_FREEZING;
rcu_read_unlock();
return ret;
}
static const char *freezer_state_strs(unsigned int state)
{
if (state & CGROUP_FROZEN)
return "FROZEN";
if (state & CGROUP_FREEZING)
return "FREEZING";
return "THAWED";
}
static struct cgroup_subsys_state *
freezer_css_alloc(struct cgroup_subsys_state *parent_css)
{
struct freezer *freezer;
freezer = kzalloc(sizeof(struct freezer), GFP_KERNEL);
if (!freezer)
return ERR_PTR(-ENOMEM);
spin_lock_init(&freezer->lock);
return &freezer->css;
}
static int freezer_css_online(struct cgroup_subsys_state *css)
{
struct freezer *freezer = css_freezer(css);
struct freezer *parent = parent_freezer(freezer);
if (parent)
spin_lock_irq(&parent->lock);
spin_lock_nested(&freezer->lock, SINGLE_DEPTH_NESTING);
freezer->state |= CGROUP_FREEZER_ONLINE;
if (parent && (parent->state & CGROUP_FREEZING)) {
freezer->state |= CGROUP_FREEZING_PARENT | CGROUP_FROZEN;
atomic_inc(&system_freezing_cnt);
}
spin_unlock(&freezer->lock);
if (parent)
spin_unlock_irq(&parent->lock);
return 0;
}
static void freezer_css_offline(struct cgroup_subsys_state *css)
{
struct freezer *freezer = css_freezer(css);
spin_lock_irq(&freezer->lock);
if (freezer->state & CGROUP_FREEZING)
atomic_dec(&system_freezing_cnt);
freezer->state = 0;
spin_unlock_irq(&freezer->lock);
}
static void freezer_css_free(struct cgroup_subsys_state *css)
{
kfree(css_freezer(css));
}
static void freezer_attach(struct cgroup_subsys_state *new_css,
struct cgroup_taskset *tset)
{
struct freezer *freezer = css_freezer(new_css);
struct task_struct *task;
bool clear_frozen = false;
spin_lock_irq(&freezer->lock);
cgroup_taskset_for_each(task, new_css, tset) {
if (!(freezer->state & CGROUP_FREEZING)) {
__thaw_task(task);
} else {
freeze_task(task);
freezer->state &= ~CGROUP_FROZEN;
clear_frozen = true;
}
}
spin_unlock_irq(&freezer->lock);
while (clear_frozen && (freezer = parent_freezer(freezer))) {
spin_lock_irq(&freezer->lock);
freezer->state &= ~CGROUP_FROZEN;
clear_frozen = freezer->state & CGROUP_FREEZING;
spin_unlock_irq(&freezer->lock);
}
}
static void freezer_fork(struct task_struct *task)
{
struct freezer *freezer;
rcu_read_lock();
freezer = task_freezer(task);
if (!parent_freezer(freezer))
goto out;
spin_lock_irq(&freezer->lock);
if (freezer->state & CGROUP_FREEZING)
freeze_task(task);
spin_unlock_irq(&freezer->lock);
out:
rcu_read_unlock();
}
static void update_if_frozen(struct cgroup_subsys_state *css)
{
struct freezer *freezer = css_freezer(css);
struct cgroup_subsys_state *pos;
struct css_task_iter it;
struct task_struct *task;
WARN_ON_ONCE(!rcu_read_lock_held());
spin_lock_irq(&freezer->lock);
if (!(freezer->state & CGROUP_FREEZING) ||
(freezer->state & CGROUP_FROZEN))
goto out_unlock;
css_for_each_child(pos, css) {
struct freezer *child = css_freezer(pos);
if ((child->state & CGROUP_FREEZER_ONLINE) &&
!(child->state & CGROUP_FROZEN))
goto out_unlock;
}
css_task_iter_start(css, &it);
while ((task = css_task_iter_next(&it))) {
if (freezing(task)) {
if (!frozen(task) && !freezer_should_skip(task))
goto out_iter_end;
}
}
freezer->state |= CGROUP_FROZEN;
out_iter_end:
css_task_iter_end(&it);
out_unlock:
spin_unlock_irq(&freezer->lock);
}
static int freezer_read(struct seq_file *m, void *v)
{
struct cgroup_subsys_state *css = seq_css(m), *pos;
rcu_read_lock();
css_for_each_descendant_post(pos, css)
update_if_frozen(pos);
rcu_read_unlock();
seq_puts(m, freezer_state_strs(css_freezer(css)->state));
seq_putc(m, '\n');
return 0;
}
static void freeze_cgroup(struct freezer *freezer)
{
struct css_task_iter it;
struct task_struct *task;
css_task_iter_start(&freezer->css, &it);
while ((task = css_task_iter_next(&it)))
freeze_task(task);
css_task_iter_end(&it);
}
static void unfreeze_cgroup(struct freezer *freezer)
{
struct css_task_iter it;
struct task_struct *task;
css_task_iter_start(&freezer->css, &it);
while ((task = css_task_iter_next(&it)))
__thaw_task(task);
css_task_iter_end(&it);
}
static void freezer_apply_state(struct freezer *freezer, bool freeze,
unsigned int state)
{
lockdep_assert_held(&freezer->lock);
if (!(freezer->state & CGROUP_FREEZER_ONLINE))
return;
if (freeze) {
if (!(freezer->state & CGROUP_FREEZING))
atomic_inc(&system_freezing_cnt);
freezer->state |= state;
freeze_cgroup(freezer);
} else {
bool was_freezing = freezer->state & CGROUP_FREEZING;
freezer->state &= ~state;
if (!(freezer->state & CGROUP_FREEZING)) {
if (was_freezing)
atomic_dec(&system_freezing_cnt);
freezer->state &= ~CGROUP_FROZEN;
unfreeze_cgroup(freezer);
}
}
}
static void freezer_change_state(struct freezer *freezer, bool freeze)
{
struct cgroup_subsys_state *pos;
rcu_read_lock();
css_for_each_descendant_pre(pos, &freezer->css) {
struct freezer *pos_f = css_freezer(pos);
struct freezer *parent = parent_freezer(pos_f);
spin_lock_irq(&pos_f->lock);
if (pos_f == freezer) {
freezer_apply_state(pos_f, freeze,
CGROUP_FREEZING_SELF);
} else {
freezer_apply_state(pos_f,
parent->state & CGROUP_FREEZING,
CGROUP_FREEZING_PARENT);
}
spin_unlock_irq(&pos_f->lock);
}
rcu_read_unlock();
}
static int freezer_write(struct cgroup_subsys_state *css, struct cftype *cft,
const char *buffer)
{
bool freeze;
if (strcmp(buffer, freezer_state_strs(0)) == 0)
freeze = false;
else if (strcmp(buffer, freezer_state_strs(CGROUP_FROZEN)) == 0)
freeze = true;
else
return -EINVAL;
freezer_change_state(css_freezer(css), freeze);
return 0;
}
static u64 freezer_self_freezing_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
struct freezer *freezer = css_freezer(css);
return (bool)(freezer->state & CGROUP_FREEZING_SELF);
}
static u64 freezer_parent_freezing_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
struct freezer *freezer = css_freezer(css);
return (bool)(freezer->state & CGROUP_FREEZING_PARENT);
}
