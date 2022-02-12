static unsigned __percpu *pcpu_count_ptr(struct percpu_ref *ref)
{
return (unsigned __percpu *)(ref->pcpu_count_ptr & ~PCPU_REF_DEAD);
}
int percpu_ref_init(struct percpu_ref *ref, percpu_ref_func_t *release)
{
atomic_set(&ref->count, 1 + PCPU_COUNT_BIAS);
ref->pcpu_count_ptr = (unsigned long)alloc_percpu(unsigned);
if (!ref->pcpu_count_ptr)
return -ENOMEM;
ref->release = release;
return 0;
}
void percpu_ref_reinit(struct percpu_ref *ref)
{
unsigned __percpu *pcpu_count = pcpu_count_ptr(ref);
int cpu;
BUG_ON(!pcpu_count);
WARN_ON(!percpu_ref_is_zero(ref));
atomic_set(&ref->count, 1 + PCPU_COUNT_BIAS);
for_each_possible_cpu(cpu)
*per_cpu_ptr(pcpu_count, cpu) = 0;
smp_store_release(&ref->pcpu_count_ptr,
ref->pcpu_count_ptr & ~PCPU_REF_DEAD);
}
void percpu_ref_exit(struct percpu_ref *ref)
{
unsigned __percpu *pcpu_count = pcpu_count_ptr(ref);
if (pcpu_count) {
free_percpu(pcpu_count);
ref->pcpu_count_ptr = PCPU_REF_DEAD;
}
}
static void percpu_ref_kill_rcu(struct rcu_head *rcu)
{
struct percpu_ref *ref = container_of(rcu, struct percpu_ref, rcu);
unsigned __percpu *pcpu_count = pcpu_count_ptr(ref);
unsigned count = 0;
int cpu;
for_each_possible_cpu(cpu)
count += *per_cpu_ptr(pcpu_count, cpu);
pr_debug("global %i pcpu %i", atomic_read(&ref->count), (int) count);
atomic_add((int) count - PCPU_COUNT_BIAS, &ref->count);
WARN_ONCE(atomic_read(&ref->count) <= 0, "percpu ref <= 0 (%i)",
atomic_read(&ref->count));
if (ref->confirm_kill)
ref->confirm_kill(ref);
percpu_ref_put(ref);
}
void percpu_ref_kill_and_confirm(struct percpu_ref *ref,
percpu_ref_func_t *confirm_kill)
{
WARN_ONCE(ref->pcpu_count_ptr & PCPU_REF_DEAD,
"percpu_ref_kill() called more than once!\n");
ref->pcpu_count_ptr |= PCPU_REF_DEAD;
ref->confirm_kill = confirm_kill;
call_rcu_sched(&ref->rcu, percpu_ref_kill_rcu);
}
void __percpu_ref_kill_expedited(struct percpu_ref *ref)
{
WARN_ONCE(ref->pcpu_count_ptr & PCPU_REF_DEAD,
"percpu_ref_kill() called more than once on %pf!",
ref->release);
ref->pcpu_count_ptr |= PCPU_REF_DEAD;
synchronize_sched_expedited();
percpu_ref_kill_rcu(&ref->rcu);
}
