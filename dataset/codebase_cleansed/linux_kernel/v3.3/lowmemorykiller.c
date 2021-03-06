static int
task_notify_func(struct notifier_block *self, unsigned long val, void *data)
{
struct task_struct *task = data;
if (task == lowmem_deathpending) {
lowmem_deathpending = NULL;
task_handoff_unregister(&task_nb);
}
return NOTIFY_OK;
}
static int lowmem_shrink(struct shrinker *s, struct shrink_control *sc)
{
struct task_struct *p;
struct task_struct *selected = NULL;
int rem = 0;
int tasksize;
int i;
int min_adj = OOM_ADJUST_MAX + 1;
int selected_tasksize = 0;
int selected_oom_adj;
int array_size = ARRAY_SIZE(lowmem_adj);
int other_free = global_page_state(NR_FREE_PAGES);
int other_file = global_page_state(NR_FILE_PAGES) -
global_page_state(NR_SHMEM);
if (lowmem_deathpending &&
time_before_eq(jiffies, lowmem_deathpending_timeout))
return 0;
if (lowmem_adj_size < array_size)
array_size = lowmem_adj_size;
if (lowmem_minfree_size < array_size)
array_size = lowmem_minfree_size;
for (i = 0; i < array_size; i++) {
if (other_free < lowmem_minfree[i] &&
other_file < lowmem_minfree[i]) {
min_adj = lowmem_adj[i];
break;
}
}
if (sc->nr_to_scan > 0)
lowmem_print(3, "lowmem_shrink %lu, %x, ofree %d %d, ma %d\n",
sc->nr_to_scan, sc->gfp_mask, other_free,
other_file, min_adj);
rem = global_page_state(NR_ACTIVE_ANON) +
global_page_state(NR_ACTIVE_FILE) +
global_page_state(NR_INACTIVE_ANON) +
global_page_state(NR_INACTIVE_FILE);
if (sc->nr_to_scan <= 0 || min_adj == OOM_ADJUST_MAX + 1) {
lowmem_print(5, "lowmem_shrink %lu, %x, return %d\n",
sc->nr_to_scan, sc->gfp_mask, rem);
return rem;
}
selected_oom_adj = min_adj;
read_lock(&tasklist_lock);
for_each_process(p) {
struct mm_struct *mm;
struct signal_struct *sig;
int oom_adj;
task_lock(p);
mm = p->mm;
sig = p->signal;
if (!mm || !sig) {
task_unlock(p);
continue;
}
oom_adj = sig->oom_adj;
if (oom_adj < min_adj) {
task_unlock(p);
continue;
}
tasksize = get_mm_rss(mm);
task_unlock(p);
if (tasksize <= 0)
continue;
if (selected) {
if (oom_adj < selected_oom_adj)
continue;
if (oom_adj == selected_oom_adj &&
tasksize <= selected_tasksize)
continue;
}
selected = p;
selected_tasksize = tasksize;
selected_oom_adj = oom_adj;
lowmem_print(2, "select %d (%s), adj %d, size %d, to kill\n",
p->pid, p->comm, oom_adj, tasksize);
}
if (selected) {
lowmem_print(1, "send sigkill to %d (%s), adj %d, size %d\n",
selected->pid, selected->comm,
selected_oom_adj, selected_tasksize);
#ifdef CONFIG_PROFILING
lowmem_deathpending = selected;
lowmem_deathpending_timeout = jiffies + HZ;
task_handoff_register(&task_nb);
#endif
force_sig(SIGKILL, selected);
rem -= selected_tasksize;
}
lowmem_print(4, "lowmem_shrink %lu, %x, return %d\n",
sc->nr_to_scan, sc->gfp_mask, rem);
read_unlock(&tasklist_lock);
return rem;
}
static int __init lowmem_init(void)
{
register_shrinker(&lowmem_shrinker);
return 0;
}
static void __exit lowmem_exit(void)
{
unregister_shrinker(&lowmem_shrinker);
}
