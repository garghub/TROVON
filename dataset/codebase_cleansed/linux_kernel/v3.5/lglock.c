void lg_lock_init(struct lglock *lg, char *name)
{
LOCKDEP_INIT_MAP(&lg->lock_dep_map, name, &lg->lock_key, 0);
}
void lg_local_lock(struct lglock *lg)
{
arch_spinlock_t *lock;
preempt_disable();
rwlock_acquire_read(&lg->lock_dep_map, 0, 0, _RET_IP_);
lock = this_cpu_ptr(lg->lock);
arch_spin_lock(lock);
}
void lg_local_unlock(struct lglock *lg)
{
arch_spinlock_t *lock;
rwlock_release(&lg->lock_dep_map, 1, _RET_IP_);
lock = this_cpu_ptr(lg->lock);
arch_spin_unlock(lock);
preempt_enable();
}
void lg_local_lock_cpu(struct lglock *lg, int cpu)
{
arch_spinlock_t *lock;
preempt_disable();
rwlock_acquire_read(&lg->lock_dep_map, 0, 0, _RET_IP_);
lock = per_cpu_ptr(lg->lock, cpu);
arch_spin_lock(lock);
}
void lg_local_unlock_cpu(struct lglock *lg, int cpu)
{
arch_spinlock_t *lock;
rwlock_release(&lg->lock_dep_map, 1, _RET_IP_);
lock = per_cpu_ptr(lg->lock, cpu);
arch_spin_unlock(lock);
preempt_enable();
}
void lg_global_lock(struct lglock *lg)
{
int i;
preempt_disable();
rwlock_acquire(&lg->lock_dep_map, 0, 0, _RET_IP_);
for_each_possible_cpu(i) {
arch_spinlock_t *lock;
lock = per_cpu_ptr(lg->lock, i);
arch_spin_lock(lock);
}
}
void lg_global_unlock(struct lglock *lg)
{
int i;
rwlock_release(&lg->lock_dep_map, 1, _RET_IP_);
for_each_possible_cpu(i) {
arch_spinlock_t *lock;
lock = per_cpu_ptr(lg->lock, i);
arch_spin_unlock(lock);
}
preempt_enable();
}
