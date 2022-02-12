void __irq_entry deferred_pcr_work_irq(int irq, struct pt_regs *regs)
{
struct pt_regs *old_regs;
clear_softint(1 << PIL_DEFERRED_PCR_WORK);
old_regs = set_irq_regs(regs);
irq_enter();
#ifdef CONFIG_IRQ_WORK
irq_work_run();
#endif
irq_exit();
set_irq_regs(old_regs);
}
void arch_irq_work_raise(void)
{
set_softint(1 << PIL_DEFERRED_PCR_WORK);
}
static u64 direct_pcr_read(void)
{
u64 val;
read_pcr(val);
return val;
}
static void direct_pcr_write(u64 val)
{
write_pcr(val);
}
static void n2_pcr_write(u64 val)
{
unsigned long ret;
if (val & PCR_N2_HTRACE) {
ret = sun4v_niagara2_setperf(HV_N2_PERF_SPARC_CTL, val);
if (ret != HV_EOK)
write_pcr(val);
} else
write_pcr(val);
}
static int __init register_perf_hsvc(void)
{
if (tlb_type == hypervisor) {
switch (sun4v_chip_type) {
case SUN4V_CHIP_NIAGARA1:
perf_hsvc_group = HV_GRP_NIAG_PERF;
break;
case SUN4V_CHIP_NIAGARA2:
perf_hsvc_group = HV_GRP_N2_CPU;
break;
case SUN4V_CHIP_NIAGARA3:
perf_hsvc_group = HV_GRP_KT_CPU;
break;
default:
return -ENODEV;
}
perf_hsvc_major = 1;
perf_hsvc_minor = 0;
if (sun4v_hvapi_register(perf_hsvc_group,
perf_hsvc_major,
&perf_hsvc_minor)) {
printk("perfmon: Could not register hvapi.\n");
return -ENODEV;
}
}
return 0;
}
static void __init unregister_perf_hsvc(void)
{
if (tlb_type != hypervisor)
return;
sun4v_hvapi_unregister(perf_hsvc_group);
}
int __init pcr_arch_init(void)
{
int err = register_perf_hsvc();
if (err)
return err;
switch (tlb_type) {
case hypervisor:
pcr_ops = &n2_pcr_ops;
pcr_enable = PCR_N2_ENABLE;
picl_shift = 2;
break;
case cheetah:
case cheetah_plus:
pcr_ops = &direct_pcr_ops;
pcr_enable = PCR_SUN4U_ENABLE;
break;
case spitfire:
default:
err = -ENODEV;
goto out_unregister;
}
return nmi_init();
out_unregister:
unregister_perf_hsvc();
return err;
}
