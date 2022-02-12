u32 omap_secure_dispatcher(u32 idx, u32 flag, u32 nargs, u32 arg1, u32 arg2,
u32 arg3, u32 arg4)
{
u32 ret;
u32 param[5];
param[0] = nargs;
param[1] = arg1;
param[2] = arg2;
param[3] = arg3;
param[4] = arg4;
flush_cache_all();
outer_clean_range(__pa(param), __pa(param + 5));
ret = omap_smc2(idx, flag, __pa(param));
return ret;
}
int __init omap_secure_ram_reserve_memblock(void)
{
u32 size = OMAP_SECURE_RAM_STORAGE;
size = ALIGN(size, SECTION_SIZE);
omap_secure_memblock_base = arm_memblock_steal(size, SECTION_SIZE);
return 0;
}
phys_addr_t omap_secure_ram_mempool_base(void)
{
return omap_secure_memblock_base;
}
u32 rx51_secure_dispatcher(u32 idx, u32 process, u32 flag, u32 nargs,
u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
u32 ret;
u32 param[5];
param[0] = nargs+1;
param[1] = arg1;
param[2] = arg2;
param[3] = arg3;
param[4] = arg4;
local_irq_disable();
local_fiq_disable();
flush_cache_all();
outer_clean_range(__pa(param), __pa(param + 5));
ret = omap_smc3(idx, process, flag, __pa(param));
flush_cache_all();
local_fiq_enable();
local_irq_enable();
return ret;
}
u32 rx51_secure_update_aux_cr(u32 set_bits, u32 clear_bits)
{
u32 acr;
asm volatile ("mrc p15, 0, %0, c1, c0, 1" : "=r" (acr));
acr &= ~clear_bits;
acr |= set_bits;
return rx51_secure_dispatcher(RX51_PPA_WRITE_ACR,
0,
FLAG_START_CRITICAL,
1, acr, 0, 0, 0);
}
u32 rx51_secure_rng_call(u32 ptr, u32 count, u32 flag)
{
return rx51_secure_dispatcher(RX51_PPA_HWRNG,
0,
NO_FLAG,
3, ptr, count, flag, 0);
}
