static int convert_prio(int prio)
{
int cpupri;
if (prio == CPUPRI_INVALID)
cpupri = CPUPRI_INVALID;
else if (prio == MAX_PRIO)
cpupri = CPUPRI_IDLE;
else if (prio >= MAX_RT_PRIO)
cpupri = CPUPRI_NORMAL;
else
cpupri = MAX_RT_PRIO - prio + 1;
return cpupri;
}
int cpupri_find(struct cpupri *cp, struct task_struct *p,
struct cpumask *lowest_mask)
{
int idx = 0;
int task_pri = convert_prio(p->prio);
for_each_cpupri_active(cp->pri_active, idx) {
struct cpupri_vec *vec = &cp->pri_to_cpu[idx];
if (idx >= task_pri)
break;
if (cpumask_any_and(&p->cpus_allowed, vec->mask) >= nr_cpu_ids)
continue;
if (lowest_mask) {
cpumask_and(lowest_mask, &p->cpus_allowed, vec->mask);
if (cpumask_any(lowest_mask) >= nr_cpu_ids)
continue;
}
return 1;
}
return 0;
}
void cpupri_set(struct cpupri *cp, int cpu, int newpri)
{
int *currpri = &cp->cpu_to_pri[cpu];
int oldpri = *currpri;
unsigned long flags;
newpri = convert_prio(newpri);
BUG_ON(newpri >= CPUPRI_NR_PRIORITIES);
if (newpri == oldpri)
return;
if (likely(newpri != CPUPRI_INVALID)) {
struct cpupri_vec *vec = &cp->pri_to_cpu[newpri];
raw_spin_lock_irqsave(&vec->lock, flags);
cpumask_set_cpu(cpu, vec->mask);
vec->count++;
if (vec->count == 1)
set_bit(newpri, cp->pri_active);
raw_spin_unlock_irqrestore(&vec->lock, flags);
}
if (likely(oldpri != CPUPRI_INVALID)) {
struct cpupri_vec *vec = &cp->pri_to_cpu[oldpri];
raw_spin_lock_irqsave(&vec->lock, flags);
vec->count--;
if (!vec->count)
clear_bit(oldpri, cp->pri_active);
cpumask_clear_cpu(cpu, vec->mask);
raw_spin_unlock_irqrestore(&vec->lock, flags);
}
*currpri = newpri;
}
int cpupri_init(struct cpupri *cp)
{
int i;
memset(cp, 0, sizeof(*cp));
for (i = 0; i < CPUPRI_NR_PRIORITIES; i++) {
struct cpupri_vec *vec = &cp->pri_to_cpu[i];
raw_spin_lock_init(&vec->lock);
vec->count = 0;
if (!zalloc_cpumask_var(&vec->mask, GFP_KERNEL))
goto cleanup;
}
for_each_possible_cpu(i)
cp->cpu_to_pri[i] = CPUPRI_INVALID;
return 0;
cleanup:
for (i--; i >= 0; i--)
free_cpumask_var(cp->pri_to_cpu[i].mask);
return -ENOMEM;
}
void cpupri_cleanup(struct cpupri *cp)
{
int i;
for (i = 0; i < CPUPRI_NR_PRIORITIES; i++)
free_cpumask_var(cp->pri_to_cpu[i].mask);
}
