static int bcm5301x_abort_handler(unsigned long addr, unsigned int fsr,
struct pt_regs *regs)
{
if (fsr == (FSR_EXTERNAL | FSR_READ | FSR_IMPRECISE))
return 0;
return 1;
}
static void __init bcm5301x_init_early(void)
{
hook_fault_code(16 + 6, bcm5301x_abort_handler, SIGBUS, BUS_OBJERR,
"imprecise external abort");
}
