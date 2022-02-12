static void ipi_mb(void *info)
{
smp_mb();
}
static int membarrier_private_expedited(void)
{
int cpu;
bool fallback = false;
cpumask_var_t tmpmask;
if (!(atomic_read(&current->mm->membarrier_state)
& MEMBARRIER_STATE_PRIVATE_EXPEDITED_READY))
return -EPERM;
if (num_online_cpus() == 1)
return 0;
smp_mb();
if (!zalloc_cpumask_var(&tmpmask, GFP_NOWAIT)) {
fallback = true;
}
cpus_read_lock();
for_each_online_cpu(cpu) {
struct task_struct *p;
if (cpu == raw_smp_processor_id())
continue;
rcu_read_lock();
p = task_rcu_dereference(&cpu_rq(cpu)->curr);
if (p && p->mm == current->mm) {
if (!fallback)
__cpumask_set_cpu(cpu, tmpmask);
else
smp_call_function_single(cpu, ipi_mb, NULL, 1);
}
rcu_read_unlock();
}
if (!fallback) {
smp_call_function_many(tmpmask, ipi_mb, NULL, 1);
free_cpumask_var(tmpmask);
}
cpus_read_unlock();
smp_mb();
return 0;
}
static void membarrier_register_private_expedited(void)
{
struct task_struct *p = current;
struct mm_struct *mm = p->mm;
if (atomic_read(&mm->membarrier_state)
& MEMBARRIER_STATE_PRIVATE_EXPEDITED_READY)
return;
atomic_or(MEMBARRIER_STATE_PRIVATE_EXPEDITED_READY,
&mm->membarrier_state);
}
