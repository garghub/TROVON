void __spin_yield(arch_spinlock_t *lock)
{
unsigned int lock_value, holder_cpu, yield_count;
lock_value = lock->slock;
if (lock_value == 0)
return;
holder_cpu = lock_value & 0xffff;
BUG_ON(holder_cpu >= NR_CPUS);
yield_count = be32_to_cpu(lppaca_of(holder_cpu).yield_count);
if ((yield_count & 1) == 0)
return;
rmb();
if (lock->slock != lock_value)
return;
plpar_hcall_norets(H_CONFER,
get_hard_smp_processor_id(holder_cpu), yield_count);
}
void __rw_yield(arch_rwlock_t *rw)
{
int lock_value;
unsigned int holder_cpu, yield_count;
lock_value = rw->lock;
if (lock_value >= 0)
return;
holder_cpu = lock_value & 0xffff;
BUG_ON(holder_cpu >= NR_CPUS);
yield_count = be32_to_cpu(lppaca_of(holder_cpu).yield_count);
if ((yield_count & 1) == 0)
return;
rmb();
if (rw->lock != lock_value)
return;
plpar_hcall_norets(H_CONFER,
get_hard_smp_processor_id(holder_cpu), yield_count);
}
