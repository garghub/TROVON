static int init_srcu_struct_fields(struct srcu_struct *sp)
{
sp->completed = 0;
mutex_init(&sp->mutex);
sp->per_cpu_ref = alloc_percpu(struct srcu_struct_array);
return sp->per_cpu_ref ? 0 : -ENOMEM;
}
int __init_srcu_struct(struct srcu_struct *sp, const char *name,
struct lock_class_key *key)
{
debug_check_no_locks_freed((void *)sp, sizeof(*sp));
lockdep_init_map(&sp->dep_map, name, key, 0);
return init_srcu_struct_fields(sp);
}
int init_srcu_struct(struct srcu_struct *sp)
{
return init_srcu_struct_fields(sp);
}
static int srcu_readers_active_idx(struct srcu_struct *sp, int idx)
{
int cpu;
int sum;
sum = 0;
for_each_possible_cpu(cpu)
sum += per_cpu_ptr(sp->per_cpu_ref, cpu)->c[idx];
return sum;
}
static int srcu_readers_active(struct srcu_struct *sp)
{
return srcu_readers_active_idx(sp, 0) + srcu_readers_active_idx(sp, 1);
}
void cleanup_srcu_struct(struct srcu_struct *sp)
{
int sum;
sum = srcu_readers_active(sp);
WARN_ON(sum);
if (sum != 0)
return;
free_percpu(sp->per_cpu_ref);
sp->per_cpu_ref = NULL;
}
int __srcu_read_lock(struct srcu_struct *sp)
{
int idx;
preempt_disable();
idx = sp->completed & 0x1;
barrier();
per_cpu_ptr(sp->per_cpu_ref, smp_processor_id())->c[idx]++;
srcu_barrier();
preempt_enable();
return idx;
}
void __srcu_read_unlock(struct srcu_struct *sp, int idx)
{
preempt_disable();
srcu_barrier();
per_cpu_ptr(sp->per_cpu_ref, smp_processor_id())->c[idx]--;
preempt_enable();
}
static void __synchronize_srcu(struct srcu_struct *sp, void (*sync_func)(void))
{
int idx;
rcu_lockdep_assert(!lock_is_held(&sp->dep_map) &&
!lock_is_held(&rcu_bh_lock_map) &&
!lock_is_held(&rcu_lock_map) &&
!lock_is_held(&rcu_sched_lock_map),
"Illegal synchronize_srcu() in same-type SRCU (or RCU) read-side critical section");
idx = sp->completed;
mutex_lock(&sp->mutex);
if ((sp->completed - idx) >= 2) {
mutex_unlock(&sp->mutex);
return;
}
sync_func();
idx = sp->completed & 0x1;
sp->completed++;
sync_func();
if (srcu_readers_active_idx(sp, idx))
udelay(SYNCHRONIZE_SRCU_READER_DELAY);
while (srcu_readers_active_idx(sp, idx))
schedule_timeout_interruptible(1);
sync_func();
mutex_unlock(&sp->mutex);
}
void synchronize_srcu(struct srcu_struct *sp)
{
__synchronize_srcu(sp, synchronize_sched);
}
void synchronize_srcu_expedited(struct srcu_struct *sp)
{
__synchronize_srcu(sp, synchronize_sched_expedited);
}
long srcu_batches_completed(struct srcu_struct *sp)
{
return sp->completed;
}
