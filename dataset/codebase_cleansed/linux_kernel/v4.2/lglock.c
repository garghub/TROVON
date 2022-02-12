void lg_lock_init(struct lglock *lg, char *name)
{
LOCKDEP_INIT_MAP(&lg->lock_dep_map, name, &lg->lock_key, 0);
}
void lg_local_lock(struct lglock *lg)
{
arch_spinlock_t *lock;
preempt_disable();
lock_acquire_shared(&lg->lock_dep_map, 0, 0, NULL, _RET_IP_);
lock = this_cpu_ptr(lg->lock);
arch_spin_lock(lock);
}
void lg_local_unlock(struct lglock *lg)
{
arch_spinlock_t *lock;
lock_release(&lg->lock_dep_map, 1, _RET_IP_);
lock = this_cpu_ptr(lg->lock);
arch_spin_unlock(lock);
preempt_enable();
}
void lg_local_lock_cpu(struct lglock *lg, int cpu)
{
arch_spinlock_t *lock;
preempt_disable();
lock_acquire_shared(&lg->lock_dep_map, 0, 0, NULL, _RET_IP_);
lock = per_cpu_ptr(lg->lock, cpu);
arch_spin_lock(lock);
}
void lg_local_unlock_cpu(struct lglock *lg, int cpu)
{
arch_spinlock_t *lock;
lock_release(&lg->lock_dep_map, 1, _RET_IP_);
lock = per_cpu_ptr(lg->lock, cpu);
arch_spin_unlock(lock);
preempt_enable();
}
void lg_double_lock(struct lglock *lg, int cpu1, int cpu2)
{
BUG_ON(cpu1 == cpu2);
if (cpu2 < cpu1)
swap(cpu1, cpu2);
preempt_disable();
lock_acquire_shared(&lg->lock_dep_map, 0, 0, NULL, _RET_IP_);
arch_spin_lock(per_cpu_ptr(lg->lock, cpu1));
arch_spin_lock(per_cpu_ptr(lg->lock, cpu2));
}
void lg_double_unlock(struct lglock *lg, int cpu1, int cpu2)
{
lock_release(&lg->lock_dep_map, 1, _RET_IP_);
arch_spin_unlock(per_cpu_ptr(lg->lock, cpu1));
arch_spin_unlock(per_cpu_ptr(lg->lock, cpu2));
preempt_enable();
}
void lg_global_lock(struct lglock *lg)
{
int i;
preempt_disable();
lock_acquire_exclusive(&lg->lock_dep_map, 0, 0, NULL, _RET_IP_);
for_each_possible_cpu(i) {
arch_spinlock_t *lock;
lock = per_cpu_ptr(lg->lock, i);
arch_spin_lock(lock);
}
}
void lg_global_unlock(struct lglock *lg)
{
int i;
lock_release(&lg->lock_dep_map, 1, _RET_IP_);
for_each_possible_cpu(i) {
arch_spinlock_t *lock;
lock = per_cpu_ptr(lg->lock, i);
arch_spin_unlock(lock);
}
preempt_enable();
}
