static void cbe_power_save(void)
{
unsigned long ctrl, thread_switch_control;
if (!prep_irq_for_idle())
return;
ctrl = mfspr(SPRN_CTRLF);
thread_switch_control = mfspr(SPRN_TSC_CELL);
thread_switch_control |= TSC_CELL_EE_ENABLE | TSC_CELL_EE_BOOST;
switch (ctrl & CTRL_CT) {
case CTRL_CT0:
thread_switch_control |= TSC_CELL_DEC_ENABLE_0;
break;
case CTRL_CT1:
thread_switch_control |= TSC_CELL_DEC_ENABLE_1;
break;
default:
printk(KERN_WARNING "%s: unknown configuration\n",
__func__);
break;
}
mtspr(SPRN_TSC_CELL, thread_switch_control);
HMT_low();
ctrl &= ~(CTRL_RUNLATCH | CTRL_TE);
mtspr(SPRN_CTRLT, ctrl);
__hard_irq_enable();
}
static int cbe_system_reset_exception(struct pt_regs *regs)
{
switch (regs->msr & SRR1_WAKEMASK) {
case SRR1_WAKEEE:
do_IRQ(regs);
break;
case SRR1_WAKEDEC:
timer_interrupt(regs);
break;
case SRR1_WAKEMT:
return cbe_sysreset_hack();
#ifdef CONFIG_CBE_RAS
case SRR1_WAKESYSERR:
cbe_system_error_exception(regs);
break;
case SRR1_WAKETHERM:
cbe_thermal_exception(regs);
break;
#endif
default:
return 0;
}
return 1;
}
void __init cbe_pervasive_init(void)
{
int cpu;
if (!cpu_has_feature(CPU_FTR_PAUSE_ZERO))
return;
for_each_possible_cpu(cpu) {
struct cbe_pmd_regs __iomem *regs = cbe_get_cpu_pmd_regs(cpu);
if (!regs)
continue;
out_be64(&regs->pmcr, in_be64(&regs->pmcr) |
CBE_PMD_PAUSE_ZERO_CONTROL);
}
ppc_md.power_save = cbe_power_save;
ppc_md.system_reset_exception = cbe_system_reset_exception;
}
