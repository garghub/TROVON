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
if (task_pri >= MAX_RT_PRIO)
return 0;
for (idx = 0; idx < task_pri; idx++) {
struct cpupri_vec *vec = &cp->pri_to_cpu[idx];
int skip = 0;
if (!atomic_read(&(vec)->count))
skip = 1;
smp_rmb();
if (skip)
continue;
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
int do_mb = 0;
newpri = convert_prio(newpri);
BUG_ON(newpri >= CPUPRI_NR_PRIORITIES);
if (newpri == oldpri)
return;
if (likely(newpri != CPUPRI_INVALID)) {
struct cpupri_vec *vec = &cp->pri_to_cpu[newpri];
cpumask_set_cpu(cpu, vec->mask);
smp_mb__before_atomic_inc();
atomic_inc(&(vec)->count);
do_mb = 1;
}
if (likely(oldpri != CPUPRI_INVALID)) {
struct cpupri_vec *vec = &cp->pri_to_cpu[oldpri];
if (do_mb)
smp_mb__after_atomic_inc();
atomic_dec(&(vec)->count);
smp_mb__after_atomic_inc();
cpumask_clear_cpu(cpu, vec->mask);
}
*currpri = newpri;
}
int cpupri_init(struct cpupri *cp)
{
int i;
memset(cp, 0, sizeof(*cp));
for (i = 0; i < CPUPRI_NR_PRIORITIES; i++) {
struct cpupri_vec *vec = &cp->pri_to_cpu[i];
atomic_set(&vec->count, 0);
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
