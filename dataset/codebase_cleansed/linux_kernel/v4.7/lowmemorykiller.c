static unsigned long lowmem_count(struct shrinker *s,
struct shrink_control *sc)
{
return global_page_state(NR_ACTIVE_ANON) +
global_page_state(NR_ACTIVE_FILE) +
global_page_state(NR_INACTIVE_ANON) +
global_page_state(NR_INACTIVE_FILE);
}
static unsigned long lowmem_scan(struct shrinker *s, struct shrink_control *sc)
{
struct task_struct *tsk;
struct task_struct *selected = NULL;
unsigned long rem = 0;
int tasksize;
int i;
short min_score_adj = OOM_SCORE_ADJ_MAX + 1;
int minfree = 0;
int selected_tasksize = 0;
short selected_oom_score_adj;
int array_size = ARRAY_SIZE(lowmem_adj);
int other_free = global_page_state(NR_FREE_PAGES) - totalreserve_pages;
int other_file = global_page_state(NR_FILE_PAGES) -
global_page_state(NR_SHMEM) -
total_swapcache_pages();
if (lowmem_adj_size < array_size)
array_size = lowmem_adj_size;
if (lowmem_minfree_size < array_size)
array_size = lowmem_minfree_size;
for (i = 0; i < array_size; i++) {
minfree = lowmem_minfree[i];
if (other_free < minfree && other_file < minfree) {
min_score_adj = lowmem_adj[i];
break;
}
}
lowmem_print(3, "lowmem_scan %lu, %x, ofree %d %d, ma %hd\n",
sc->nr_to_scan, sc->gfp_mask, other_free,
other_file, min_score_adj);
if (min_score_adj == OOM_SCORE_ADJ_MAX + 1) {
lowmem_print(5, "lowmem_scan %lu, %x, return 0\n",
sc->nr_to_scan, sc->gfp_mask);
return 0;
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
if (task_lmk_waiting(p) &&
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
lowmem_print(2, "select '%s' (%d), adj %hd, size %d, to kill\n",
p->comm, p->pid, oom_score_adj, tasksize);
}
if (selected) {
task_lock(selected);
send_sig(SIGKILL, selected, 0);
if (selected->mm)
task_set_lmk_waiting(selected);
task_unlock(selected);
lowmem_print(1, "Killing '%s' (%d), adj %hd,\n"
" to free %ldkB on behalf of '%s' (%d) because\n"
" cache %ldkB is below limit %ldkB for oom_score_adj %hd\n"
" Free memory is %ldkB above reserved\n",
selected->comm, selected->pid,
selected_oom_score_adj,
selected_tasksize * (long)(PAGE_SIZE / 1024),
current->comm, current->pid,
other_file * (long)(PAGE_SIZE / 1024),
minfree * (long)(PAGE_SIZE / 1024),
min_score_adj,
other_free * (long)(PAGE_SIZE / 1024));
lowmem_deathpending_timeout = jiffies + HZ;
rem += selected_tasksize;
}
lowmem_print(4, "lowmem_scan %lu, %x, return %lu\n",
sc->nr_to_scan, sc->gfp_mask, rem);
rcu_read_unlock();
return rem;
}
static int __init lowmem_init(void)
{
register_shrinker(&lowmem_shrinker);
return 0;
}
