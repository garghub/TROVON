static inline void *allocate_probes(int count)
{
struct tp_probes *p = kmalloc(count * sizeof(struct tracepoint_func)
+ sizeof(struct tp_probes), GFP_KERNEL);
return p == NULL ? NULL : p->probes;
}
static void rcu_free_old_probes(struct rcu_head *head)
{
kfree(container_of(head, struct tp_probes, u.rcu));
}
static inline void release_probes(struct tracepoint_func *old)
{
if (old) {
struct tp_probes *tp_probes = container_of(old,
struct tp_probes, probes[0]);
call_rcu_sched(&tp_probes->u.rcu, rcu_free_old_probes);
}
}
static void debug_print_probes(struct tracepoint_entry *entry)
{
int i;
if (!tracepoint_debug || !entry->funcs)
return;
for (i = 0; entry->funcs[i].func; i++)
printk(KERN_DEBUG "Probe %d : %p\n", i, entry->funcs[i].func);
}
static struct tracepoint_func *
tracepoint_entry_add_probe(struct tracepoint_entry *entry,
void *probe, void *data)
{
int nr_probes = 0;
struct tracepoint_func *old, *new;
WARN_ON(!probe);
debug_print_probes(entry);
old = entry->funcs;
if (old) {
for (nr_probes = 0; old[nr_probes].func; nr_probes++)
if (old[nr_probes].func == probe &&
old[nr_probes].data == data)
return ERR_PTR(-EEXIST);
}
new = allocate_probes(nr_probes + 2);
if (new == NULL)
return ERR_PTR(-ENOMEM);
if (old)
memcpy(new, old, nr_probes * sizeof(struct tracepoint_func));
new[nr_probes].func = probe;
new[nr_probes].data = data;
new[nr_probes + 1].func = NULL;
entry->refcount = nr_probes + 1;
entry->funcs = new;
debug_print_probes(entry);
return old;
}
static void *
tracepoint_entry_remove_probe(struct tracepoint_entry *entry,
void *probe, void *data)
{
int nr_probes = 0, nr_del = 0, i;
struct tracepoint_func *old, *new;
old = entry->funcs;
if (!old)
return ERR_PTR(-ENOENT);
debug_print_probes(entry);
for (nr_probes = 0; old[nr_probes].func; nr_probes++) {
if (!probe ||
(old[nr_probes].func == probe &&
old[nr_probes].data == data))
nr_del++;
}
if (nr_probes - nr_del == 0) {
entry->funcs = NULL;
entry->refcount = 0;
debug_print_probes(entry);
return old;
} else {
int j = 0;
new = allocate_probes(nr_probes - nr_del + 1);
if (new == NULL)
return ERR_PTR(-ENOMEM);
for (i = 0; old[i].func; i++)
if (probe &&
(old[i].func != probe || old[i].data != data))
new[j++] = old[i];
new[nr_probes - nr_del].func = NULL;
entry->refcount = nr_probes - nr_del;
entry->funcs = new;
}
debug_print_probes(entry);
return old;
}
static struct tracepoint_entry *get_tracepoint(const char *name)
{
struct hlist_head *head;
struct hlist_node *node;
struct tracepoint_entry *e;
u32 hash = jhash(name, strlen(name), 0);
head = &tracepoint_table[hash & (TRACEPOINT_TABLE_SIZE - 1)];
hlist_for_each_entry(e, node, head, hlist) {
if (!strcmp(name, e->name))
return e;
}
return NULL;
}
static struct tracepoint_entry *add_tracepoint(const char *name)
{
struct hlist_head *head;
struct hlist_node *node;
struct tracepoint_entry *e;
size_t name_len = strlen(name) + 1;
u32 hash = jhash(name, name_len-1, 0);
head = &tracepoint_table[hash & (TRACEPOINT_TABLE_SIZE - 1)];
hlist_for_each_entry(e, node, head, hlist) {
if (!strcmp(name, e->name)) {
printk(KERN_NOTICE
"tracepoint %s busy\n", name);
return ERR_PTR(-EEXIST);
}
}
e = kmalloc(sizeof(struct tracepoint_entry) + name_len, GFP_KERNEL);
if (!e)
return ERR_PTR(-ENOMEM);
memcpy(&e->name[0], name, name_len);
e->funcs = NULL;
e->refcount = 0;
hlist_add_head(&e->hlist, head);
return e;
}
static inline void remove_tracepoint(struct tracepoint_entry *e)
{
hlist_del(&e->hlist);
kfree(e);
}
static void set_tracepoint(struct tracepoint_entry **entry,
struct tracepoint *elem, int active)
{
WARN_ON(strcmp((*entry)->name, elem->name) != 0);
if (elem->regfunc && !jump_label_enabled(&elem->key) && active)
elem->regfunc();
else if (elem->unregfunc && jump_label_enabled(&elem->key) && !active)
elem->unregfunc();
rcu_assign_pointer(elem->funcs, (*entry)->funcs);
if (active && !jump_label_enabled(&elem->key))
jump_label_inc(&elem->key);
else if (!active && jump_label_enabled(&elem->key))
jump_label_dec(&elem->key);
}
static void disable_tracepoint(struct tracepoint *elem)
{
if (elem->unregfunc && jump_label_enabled(&elem->key))
elem->unregfunc();
if (jump_label_enabled(&elem->key))
jump_label_dec(&elem->key);
rcu_assign_pointer(elem->funcs, NULL);
}
void tracepoint_update_probe_range(struct tracepoint * const *begin,
struct tracepoint * const *end)
{
struct tracepoint * const *iter;
struct tracepoint_entry *mark_entry;
if (!begin)
return;
mutex_lock(&tracepoints_mutex);
for (iter = begin; iter < end; iter++) {
mark_entry = get_tracepoint((*iter)->name);
if (mark_entry) {
set_tracepoint(&mark_entry, *iter,
!!mark_entry->refcount);
} else {
disable_tracepoint(*iter);
}
}
mutex_unlock(&tracepoints_mutex);
}
static void tracepoint_update_probes(void)
{
tracepoint_update_probe_range(__start___tracepoints_ptrs,
__stop___tracepoints_ptrs);
module_update_tracepoints();
}
static struct tracepoint_func *
tracepoint_add_probe(const char *name, void *probe, void *data)
{
struct tracepoint_entry *entry;
struct tracepoint_func *old;
entry = get_tracepoint(name);
if (!entry) {
entry = add_tracepoint(name);
if (IS_ERR(entry))
return (struct tracepoint_func *)entry;
}
old = tracepoint_entry_add_probe(entry, probe, data);
if (IS_ERR(old) && !entry->refcount)
remove_tracepoint(entry);
return old;
}
int tracepoint_probe_register(const char *name, void *probe, void *data)
{
struct tracepoint_func *old;
mutex_lock(&tracepoints_mutex);
old = tracepoint_add_probe(name, probe, data);
mutex_unlock(&tracepoints_mutex);
if (IS_ERR(old))
return PTR_ERR(old);
tracepoint_update_probes();
release_probes(old);
return 0;
}
static struct tracepoint_func *
tracepoint_remove_probe(const char *name, void *probe, void *data)
{
struct tracepoint_entry *entry;
struct tracepoint_func *old;
entry = get_tracepoint(name);
if (!entry)
return ERR_PTR(-ENOENT);
old = tracepoint_entry_remove_probe(entry, probe, data);
if (IS_ERR(old))
return old;
if (!entry->refcount)
remove_tracepoint(entry);
return old;
}
int tracepoint_probe_unregister(const char *name, void *probe, void *data)
{
struct tracepoint_func *old;
mutex_lock(&tracepoints_mutex);
old = tracepoint_remove_probe(name, probe, data);
mutex_unlock(&tracepoints_mutex);
if (IS_ERR(old))
return PTR_ERR(old);
tracepoint_update_probes();
release_probes(old);
return 0;
}
static void tracepoint_add_old_probes(void *old)
{
need_update = 1;
if (old) {
struct tp_probes *tp_probes = container_of(old,
struct tp_probes, probes[0]);
list_add(&tp_probes->u.list, &old_probes);
}
}
int tracepoint_probe_register_noupdate(const char *name, void *probe,
void *data)
{
struct tracepoint_func *old;
mutex_lock(&tracepoints_mutex);
old = tracepoint_add_probe(name, probe, data);
if (IS_ERR(old)) {
mutex_unlock(&tracepoints_mutex);
return PTR_ERR(old);
}
tracepoint_add_old_probes(old);
mutex_unlock(&tracepoints_mutex);
return 0;
}
int tracepoint_probe_unregister_noupdate(const char *name, void *probe,
void *data)
{
struct tracepoint_func *old;
mutex_lock(&tracepoints_mutex);
old = tracepoint_remove_probe(name, probe, data);
if (IS_ERR(old)) {
mutex_unlock(&tracepoints_mutex);
return PTR_ERR(old);
}
tracepoint_add_old_probes(old);
mutex_unlock(&tracepoints_mutex);
return 0;
}
void tracepoint_probe_update_all(void)
{
LIST_HEAD(release_probes);
struct tp_probes *pos, *next;
mutex_lock(&tracepoints_mutex);
if (!need_update) {
mutex_unlock(&tracepoints_mutex);
return;
}
if (!list_empty(&old_probes))
list_replace_init(&old_probes, &release_probes);
need_update = 0;
mutex_unlock(&tracepoints_mutex);
tracepoint_update_probes();
list_for_each_entry_safe(pos, next, &release_probes, u.list) {
list_del(&pos->u.list);
call_rcu_sched(&pos->u.rcu, rcu_free_old_probes);
}
}
int tracepoint_get_iter_range(struct tracepoint * const **tracepoint,
struct tracepoint * const *begin, struct tracepoint * const *end)
{
if (!*tracepoint && begin != end) {
*tracepoint = begin;
return 1;
}
if (*tracepoint >= begin && *tracepoint < end)
return 1;
return 0;
}
static void tracepoint_get_iter(struct tracepoint_iter *iter)
{
int found = 0;
if (!iter->module) {
found = tracepoint_get_iter_range(&iter->tracepoint,
__start___tracepoints_ptrs,
__stop___tracepoints_ptrs);
if (found)
goto end;
}
found = module_get_iter_tracepoints(iter);
end:
if (!found)
tracepoint_iter_reset(iter);
}
void tracepoint_iter_start(struct tracepoint_iter *iter)
{
tracepoint_get_iter(iter);
}
void tracepoint_iter_next(struct tracepoint_iter *iter)
{
iter->tracepoint++;
tracepoint_get_iter(iter);
}
void tracepoint_iter_stop(struct tracepoint_iter *iter)
{
}
void tracepoint_iter_reset(struct tracepoint_iter *iter)
{
iter->module = NULL;
iter->tracepoint = NULL;
}
int tracepoint_module_notify(struct notifier_block *self,
unsigned long val, void *data)
{
struct module *mod = data;
switch (val) {
case MODULE_STATE_COMING:
case MODULE_STATE_GOING:
tracepoint_update_probe_range(mod->tracepoints_ptrs,
mod->tracepoints_ptrs + mod->num_tracepoints);
break;
}
return 0;
}
static int init_tracepoints(void)
{
return register_module_notifier(&tracepoint_module_nb);
}
void syscall_regfunc(void)
{
unsigned long flags;
struct task_struct *g, *t;
if (!sys_tracepoint_refcount) {
read_lock_irqsave(&tasklist_lock, flags);
do_each_thread(g, t) {
if (t->mm)
set_tsk_thread_flag(t, TIF_SYSCALL_TRACEPOINT);
} while_each_thread(g, t);
read_unlock_irqrestore(&tasklist_lock, flags);
}
sys_tracepoint_refcount++;
}
void syscall_unregfunc(void)
{
unsigned long flags;
struct task_struct *g, *t;
sys_tracepoint_refcount--;
if (!sys_tracepoint_refcount) {
read_lock_irqsave(&tasklist_lock, flags);
do_each_thread(g, t) {
clear_tsk_thread_flag(t, TIF_SYSCALL_TRACEPOINT);
} while_each_thread(g, t);
read_unlock_irqrestore(&tasklist_lock, flags);
}
}
