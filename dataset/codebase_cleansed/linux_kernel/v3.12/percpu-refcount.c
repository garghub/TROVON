int percpu_ref_init(struct percpu_ref *ref, percpu_ref_func_t *release)
{
atomic_set(&ref->count, 1 + PCPU_COUNT_BIAS);
ref->pcpu_count = alloc_percpu(unsigned);
if (!ref->pcpu_count)
return -ENOMEM;
ref->release = release;
return 0;
}
void percpu_ref_cancel_init(struct percpu_ref *ref)
{
unsigned __percpu *pcpu_count = ref->pcpu_count;
int cpu;
WARN_ON_ONCE(atomic_read(&ref->count) != 1 + PCPU_COUNT_BIAS);
if (pcpu_count) {
for_each_possible_cpu(cpu)
WARN_ON_ONCE(*per_cpu_ptr(pcpu_count, cpu));
free_percpu(ref->pcpu_count);
}
}
static void percpu_ref_kill_rcu(struct rcu_head *rcu)
{
struct percpu_ref *ref = container_of(rcu, struct percpu_ref, rcu);
unsigned __percpu *pcpu_count = ref->pcpu_count;
unsigned count = 0;
int cpu;
pcpu_count = (unsigned __percpu *)
(((unsigned long) pcpu_count) & ~PCPU_STATUS_MASK);
for_each_possible_cpu(cpu)
count += *per_cpu_ptr(pcpu_count, cpu);
free_percpu(pcpu_count);
pr_debug("global %i pcpu %i", atomic_read(&ref->count), (int) count);
atomic_add((int) count - PCPU_COUNT_BIAS, &ref->count);
if (ref->confirm_kill)
ref->confirm_kill(ref);
percpu_ref_put(ref);
}
void percpu_ref_kill_and_confirm(struct percpu_ref *ref,
percpu_ref_func_t *confirm_kill)
{
WARN_ONCE(REF_STATUS(ref->pcpu_count) == PCPU_REF_DEAD,
"percpu_ref_kill() called more than once!\n");
ref->pcpu_count = (unsigned __percpu *)
(((unsigned long) ref->pcpu_count)|PCPU_REF_DEAD);
ref->confirm_kill = confirm_kill;
call_rcu_sched(&ref->rcu, percpu_ref_kill_rcu);
}
