void mn10300_icache_inv(void)
{
unsigned long flags;
flags = smp_lock_cache();
mn10300_local_icache_inv();
smp_cache_call(SMP_ICACHE_INV, 0, 0);
smp_unlock_cache(flags);
}
void mn10300_icache_inv_page(unsigned long start)
{
unsigned long flags;
start &= ~(PAGE_SIZE-1);
flags = smp_lock_cache();
mn10300_local_icache_inv_page(start);
smp_cache_call(SMP_ICACHE_INV_RANGE, start, start + PAGE_SIZE);
smp_unlock_cache(flags);
}
void mn10300_icache_inv_range(unsigned long start, unsigned long end)
{
unsigned long flags;
flags = smp_lock_cache();
mn10300_local_icache_inv_range(start, end);
smp_cache_call(SMP_ICACHE_INV_RANGE, start, end);
smp_unlock_cache(flags);
}
void mn10300_icache_inv_range2(unsigned long start, unsigned long size)
{
unsigned long flags;
flags = smp_lock_cache();
mn10300_local_icache_inv_range2(start, size);
smp_cache_call(SMP_ICACHE_INV_RANGE, start, start + size);
smp_unlock_cache(flags);
}
void mn10300_dcache_inv(void)
{
unsigned long flags;
flags = smp_lock_cache();
mn10300_local_dcache_inv();
smp_cache_call(SMP_DCACHE_INV, 0, 0);
smp_unlock_cache(flags);
}
void mn10300_dcache_inv_page(unsigned long start)
{
unsigned long flags;
start &= ~(PAGE_SIZE-1);
flags = smp_lock_cache();
mn10300_local_dcache_inv_page(start);
smp_cache_call(SMP_DCACHE_INV_RANGE, start, start + PAGE_SIZE);
smp_unlock_cache(flags);
}
void mn10300_dcache_inv_range(unsigned long start, unsigned long end)
{
unsigned long flags;
flags = smp_lock_cache();
mn10300_local_dcache_inv_range(start, end);
smp_cache_call(SMP_DCACHE_INV_RANGE, start, end);
smp_unlock_cache(flags);
}
void mn10300_dcache_inv_range2(unsigned long start, unsigned long size)
{
unsigned long flags;
flags = smp_lock_cache();
mn10300_local_dcache_inv_range2(start, size);
smp_cache_call(SMP_DCACHE_INV_RANGE, start, start + size);
smp_unlock_cache(flags);
}
