void chipcHw_reset(uint32_t mask)
{
int i = 0;
RUNFUNC runFunc = (RUNFUNC) (unsigned long)MM_ADDR_IO_ARAM;
intcHw_irq_disable(INTCHW_INTC0, 0xffffffff);
intcHw_irq_disable(INTCHW_INTC1, 0xffffffff);
intcHw_irq_disable(INTCHW_SINTC, 0xffffffff);
{
REG_LOCAL_IRQ_SAVE;
if (mask & chipcHw_REG_SOFT_RESET_CHIP_SOFT) {
chipcHw_softReset(chipcHw_REG_SOFT_RESET_CHIP_SOFT);
}
pChipcHw->UARTClock |= chipcHw_REG_PLL_CLOCK_BYPASS_SELECT;
pChipcHw->SPIClock |= chipcHw_REG_PLL_CLOCK_BYPASS_SELECT;
do {
((uint32_t *) MM_IO_BASE_ARAM)[i] =
((uint32_t *) &chipcHw_reset_run_from_aram)[i];
i++;
} while (((uint32_t *) MM_IO_BASE_ARAM)[i - 1] != 0xe1a0f00f);
CSP_CACHE_FLUSH_ALL;
runFunc();
REG_LOCAL_IRQ_RESTORE;
}
}
void chipcHw_reset_run_from_aram(void)
{
__asm (" nop \n\t"
" nop \n\t"
#if defined(__KERNEL__) && !defined(STANDALONE)
" MRC p15,#0x0,r0,c1,c0,#0 \n\t"
" BIC r0,r0,#0xd \n\t"
" MCR p15,#0x0,r0,c1,c0,#0 \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
#endif
" nop \n\t"
" nop \n\t"
" MOV r2,#0x80000000 \n\t"
" LDR r3,[r2,#8] \n\t"
" ORR r3,r3,#0x20000 \n\t"
" STR r3,[r2,#8] \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" nop \n\t"
" MOV r3,#0x2 \n\t"
" STR r3,[r2,#0x80] \n\t"
" MOV pc,pc \n\t");
