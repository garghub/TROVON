static int lowmem_shrink(struct shrinker *s, struct shrink_control *sc)
{
struct task_struct *tsk;
struct task_struct *selected = NULL;
int rem = 0;
int tasksize;
int i;
short min_score_adj = OOM_SCORE_ADJ_MAX + 1;
int selected_tasksize = 0;
short selected_oom_score_adj;
int array_size = ARRAY_SIZE(lowmem_adj);
int other_free = global_page_state(NR_FREE_PAGES) - totalreserve_pages;
int other_file = global_page_state(NR_FILE_PAGES) -
global_page_state(NR_SHMEM);
if (lowmem_adj_size < array_size)
array_size = lowmem_adj_size;
if (lowmem_minfree_size < array_size)
array_size = lowmem_minfree_size;
for (i = 0; i < array_size; i++) {
if (other_free < lowmem_minfree[i] &&
other_file < lowmem_minfree[i]) {
min_score_adj = lowmem_adj[i];
break;
}
}
if (sc->nr_to_scan > 0)
lowmem_print(3, "lowmem_shrink %lu, %x, ofree %d %d, ma %hd\n",
sc->nr_to_scan, sc->gfp_mask, other_free,
other_file, min_score_adj);
rem = global_page_state(NR_ACTIVE_ANON) +
global_page_state(NR_ACTIVE_FILE) +
global_page_state(NR_INACTIVE_ANON) +
global_page_state(NR_INACTIVE_FILE);
if (sc->nr_to_scan <= 0 || min_score_adj == OOM_SCORE_ADJ_MAX + 1) {
lowmem_print(5, "lowmem_shrink %lu, %x, return %d\n",
sc->nr_to_scan, sc->gfp_mask, rem);
return rem;
}
selected_oom_score_adj = min_score_adj;
rcu_read_lock();
for_each_process(tsk) {
struct task_struct *p;
short oom_score_adj;
if (tsk->flags & PF_KTHREAD)
continue;
p = find_lock_task_mm(tsk);
if (!p)
continue;
if (test_tsk_thread_flag(p, TIF_MEMDIE) &&
time_before_eq(jiffies, lowmem_deathpending_timeout)) {
task_unlock(p);
rcu_read_unlock();
return 0;
}
oom_score_adj = p->signal->oom_score_adj;
if (oom_score_adj < min_score_adj) {
task_unlock(p);
continue;
}
tasksize = get_mm_rss(p->mm);
task_unlock(p);
if (tasksize <= 0)
continue;
if (selected) {
if (oom_score_adj < selected_oom_score_adj)
continue;
if (oom_score_adj == selected_oom_score_adj &&
tasksize <= selected_tasksize)
continue;
}
selected = p;
selected_tasksize = tasksize;
selected_oom_score_adj = oom_score_adj;
lowmem_print(2, "select %d (%s), adj %hd, size %d, to kill\n",
p->pid, p->comm, oom_score_adj, tasksize);
}
if (selected) {
lowmem_print(1, "send sigkill to %d (%s), adj %hd, size %d\n",
selected->pid, selected->comm,
selected_oom_score_adj, selected_tasksize);
lowmem_deathpending_timeout = jiffies + HZ;
send_sig(SIGKILL, selected, 0);
set_tsk_thread_flag(selected, TIF_MEMDIE);
rem -= selected_tasksize;
}
lowmem_print(4, "lowmem_shrink %lu, %x, return %d\n",
sc->nr_to_scan, sc->gfp_mask, rem);
rcu_read_unlock();
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
