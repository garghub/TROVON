static unsigned long __percpu *percpu_count_ptr(struct percpu_ref *ref)
{
return (unsigned long __percpu *)
(ref->percpu_count_ptr & ~__PERCPU_REF_ATOMIC_DEAD);
}
int percpu_ref_init(struct percpu_ref *ref, percpu_ref_func_t *release,
unsigned int flags, gfp_t gfp)
{
size_t align = max_t(size_t, 1 << __PERCPU_REF_FLAG_BITS,
__alignof__(unsigned long));
unsigned long start_count = 0;
ref->percpu_count_ptr = (unsigned long)
__alloc_percpu_gfp(sizeof(unsigned long), align, gfp);
if (!ref->percpu_count_ptr)
return -ENOMEM;
ref->force_atomic = flags & PERCPU_REF_INIT_ATOMIC;
if (flags & (PERCPU_REF_INIT_ATOMIC | PERCPU_REF_INIT_DEAD))
ref->percpu_count_ptr |= __PERCPU_REF_ATOMIC;
else
start_count += PERCPU_COUNT_BIAS;
if (flags & PERCPU_REF_INIT_DEAD)
ref->percpu_count_ptr |= __PERCPU_REF_DEAD;
else
start_count++;
atomic_long_set(&ref->count, start_count);
ref->release = release;
return 0;
}
void percpu_ref_exit(struct percpu_ref *ref)
{
unsigned long __percpu *percpu_count = percpu_count_ptr(ref);
if (percpu_count) {
free_percpu(percpu_count);
ref->percpu_count_ptr = __PERCPU_REF_ATOMIC_DEAD;
}
}
static void percpu_ref_call_confirm_rcu(struct rcu_head *rcu)
{
struct percpu_ref *ref = container_of(rcu, struct percpu_ref, rcu);
ref->confirm_switch(ref);
ref->confirm_switch = NULL;
wake_up_all(&percpu_ref_switch_waitq);
percpu_ref_put(ref);
}
static void percpu_ref_switch_to_atomic_rcu(struct rcu_head *rcu)
{
struct percpu_ref *ref = container_of(rcu, struct percpu_ref, rcu);
unsigned long __percpu *percpu_count = percpu_count_ptr(ref);
unsigned long count = 0;
int cpu;
for_each_possible_cpu(cpu)
count += *per_cpu_ptr(percpu_count, cpu);
pr_debug("global %ld percpu %ld",
atomic_long_read(&ref->count), (long)count);
atomic_long_add((long)count - PERCPU_COUNT_BIAS, &ref->count);
WARN_ONCE(atomic_long_read(&ref->count) <= 0,
"percpu ref (%pf) <= 0 (%ld) after switching to atomic",
ref->release, atomic_long_read(&ref->count));
percpu_ref_call_confirm_rcu(rcu);
}
static void percpu_ref_noop_confirm_switch(struct percpu_ref *ref)
{
}
static void __percpu_ref_switch_to_atomic(struct percpu_ref *ref,
percpu_ref_func_t *confirm_switch)
{
if (!(ref->percpu_count_ptr & __PERCPU_REF_ATOMIC)) {
ref->percpu_count_ptr |= __PERCPU_REF_ATOMIC;
WARN_ON_ONCE(ref->confirm_switch);
ref->confirm_switch =
confirm_switch ?: percpu_ref_noop_confirm_switch;
percpu_ref_get(ref);
call_rcu_sched(&ref->rcu, percpu_ref_switch_to_atomic_rcu);
} else if (confirm_switch) {
wait_event(percpu_ref_switch_waitq, !ref->confirm_switch);
ref->confirm_switch = confirm_switch;
percpu_ref_get(ref);
call_rcu_sched(&ref->rcu, percpu_ref_call_confirm_rcu);
}
}
void percpu_ref_switch_to_atomic(struct percpu_ref *ref,
percpu_ref_func_t *confirm_switch)
{
ref->force_atomic = true;
__percpu_ref_switch_to_atomic(ref, confirm_switch);
}
static void __percpu_ref_switch_to_percpu(struct percpu_ref *ref)
{
unsigned long __percpu *percpu_count = percpu_count_ptr(ref);
int cpu;
BUG_ON(!percpu_count);
if (!(ref->percpu_count_ptr & __PERCPU_REF_ATOMIC))
return;
wait_event(percpu_ref_switch_waitq, !ref->confirm_switch);
atomic_long_add(PERCPU_COUNT_BIAS, &ref->count);
for_each_possible_cpu(cpu)
*per_cpu_ptr(percpu_count, cpu) = 0;
smp_store_release(&ref->percpu_count_ptr,
ref->percpu_count_ptr & ~__PERCPU_REF_ATOMIC);
}
void percpu_ref_switch_to_percpu(struct percpu_ref *ref)
{
ref->force_atomic = false;
if (!(ref->percpu_count_ptr & __PERCPU_REF_DEAD))
__percpu_ref_switch_to_percpu(ref);
}
void percpu_ref_kill_and_confirm(struct percpu_ref *ref,
percpu_ref_func_t *confirm_kill)
{
WARN_ONCE(ref->percpu_count_ptr & __PERCPU_REF_DEAD,
"%s called more than once on %pf!", __func__, ref->release);
ref->percpu_count_ptr |= __PERCPU_REF_DEAD;
__percpu_ref_switch_to_atomic(ref, confirm_kill);
percpu_ref_put(ref);
}
void percpu_ref_reinit(struct percpu_ref *ref)
{
WARN_ON_ONCE(!percpu_ref_is_zero(ref));
ref->percpu_count_ptr &= ~__PERCPU_REF_DEAD;
percpu_ref_get(ref);
if (!ref->force_atomic)
__percpu_ref_switch_to_percpu(ref);
}
