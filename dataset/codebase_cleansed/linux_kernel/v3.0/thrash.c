static struct mem_cgroup *swap_token_memcg_from_mm(struct mm_struct *mm)
{
struct mem_cgroup *memcg;
memcg = try_get_mem_cgroup_from_mm(mm);
if (memcg)
css_put(mem_cgroup_css(memcg));
return memcg;
}
static struct mem_cgroup *swap_token_memcg_from_mm(struct mm_struct *mm)
{
return NULL;
}
void grab_swap_token(struct mm_struct *mm)
{
int current_interval;
unsigned int old_prio = mm->token_priority;
global_faults++;
current_interval = global_faults - mm->faultstamp;
if (!spin_trylock(&swap_token_lock))
return;
if (!swap_token_mm)
goto replace_token;
if ((global_faults - last_aging) > TOKEN_AGING_INTERVAL) {
swap_token_mm->token_priority /= 2;
last_aging = global_faults;
}
if (mm == swap_token_mm) {
mm->token_priority += 2;
goto update_priority;
}
if (current_interval < mm->last_interval)
mm->token_priority++;
else {
if (likely(mm->token_priority > 0))
mm->token_priority--;
}
if (mm->token_priority > swap_token_mm->token_priority)
goto replace_token;
update_priority:
trace_update_swap_token_priority(mm, old_prio, swap_token_mm);
out:
mm->faultstamp = global_faults;
mm->last_interval = current_interval;
spin_unlock(&swap_token_lock);
return;
replace_token:
mm->token_priority += 2;
trace_replace_swap_token(swap_token_mm, mm);
swap_token_mm = mm;
swap_token_memcg = swap_token_memcg_from_mm(mm);
last_aging = global_faults;
goto out;
}
void __put_swap_token(struct mm_struct *mm)
{
spin_lock(&swap_token_lock);
if (likely(mm == swap_token_mm)) {
trace_put_swap_token(swap_token_mm);
swap_token_mm = NULL;
swap_token_memcg = NULL;
}
spin_unlock(&swap_token_lock);
}
static bool match_memcg(struct mem_cgroup *a, struct mem_cgroup *b)
{
if (!a)
return true;
if (!b)
return true;
if (a == b)
return true;
return false;
}
void disable_swap_token(struct mem_cgroup *memcg)
{
if (match_memcg(memcg, swap_token_memcg)) {
spin_lock(&swap_token_lock);
if (match_memcg(memcg, swap_token_memcg)) {
trace_disable_swap_token(swap_token_mm);
swap_token_mm = NULL;
swap_token_memcg = NULL;
}
spin_unlock(&swap_token_lock);
}
}
