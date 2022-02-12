__visible void __native_queued_spin_unlock(struct qspinlock *lock)
{
native_queued_spin_unlock(lock);
}
bool pv_is_native_spin_unlock(void)
{
return pv_lock_ops.queued_spin_unlock.func ==
__raw_callee_save___native_queued_spin_unlock;
}
__visible bool __native_vcpu_is_preempted(int cpu)
{
return false;
}
bool pv_is_native_vcpu_is_preempted(void)
{
return pv_lock_ops.vcpu_is_preempted.func ==
__raw_callee_save___native_vcpu_is_preempted;
}
