void core_reg_write(int unit, int reg, int thread, unsigned int val)
{
unsigned long flags;
if (unit == TXUCT_ID) {
void __iomem *cu_reg = __CU_addr(thread, reg);
metag_out32(val, cu_reg);
return;
}
__global_lock2(flags);
while (!(metag_in32(TXUXXRXRQ) & TXUXXRXRQ_DREADY_BIT))
udelay(10);
metag_out32(val, TXUXXRXDT);
val = UNIT_VAL(unit) | REG_VAL(reg) | THREAD_VAL(thread);
metag_out32(val, TXUXXRXRQ);
while (!(metag_in32(TXUXXRXRQ) & TXUXXRXRQ_DREADY_BIT))
udelay(10);
__global_unlock2(flags);
}
unsigned int core_reg_read(int unit, int reg, int thread)
{
unsigned long flags;
unsigned int val;
if (unit == TXUCT_ID) {
void __iomem *cu_reg = __CU_addr(thread, reg);
val = metag_in32(cu_reg);
return val;
}
__global_lock2(flags);
while (!(metag_in32(TXUXXRXRQ) & TXUXXRXRQ_DREADY_BIT))
udelay(10);
val = (UNIT_VAL(unit) | REG_VAL(reg) | THREAD_VAL(thread) |
TXUXXRXRQ_RDnWR_BIT);
metag_out32(val, TXUXXRXRQ);
while (!(metag_in32(TXUXXRXRQ) & TXUXXRXRQ_DREADY_BIT))
udelay(10);
val = metag_in32(TXUXXRXDT);
__global_unlock2(flags);
return val;
}
