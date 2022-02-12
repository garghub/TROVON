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
static u64 direct_pcr_read(unsigned long reg_num)
{
u64 val;
WARN_ON_ONCE(reg_num != 0);
__asm__ __volatile__("rd %%pcr, %0" : "=r" (val));
return val;
}
static void direct_pcr_write(unsigned long reg_num, u64 val)
{
WARN_ON_ONCE(reg_num != 0);
__asm__ __volatile__("wr %0, 0x0, %%pcr" : : "r" (val));
}
static u64 direct_pic_read(unsigned long reg_num)
{
u64 val;
WARN_ON_ONCE(reg_num != 0);
__asm__ __volatile__("rd %%pic, %0" : "=r" (val));
return val;
}
static void direct_pic_write(unsigned long reg_num, u64 val)
{
WARN_ON_ONCE(reg_num != 0);
__asm__ __volatile__("ba,pt %%xcc, 99f\n\t"
" nop\n\t"
".align 64\n"
"99:wr %0, 0x0, %%pic\n\t"
"rd %%pic, %%g0" : : "r" (val));
}
static u64 direct_picl_value(unsigned int nmi_hz)
{
u32 delta = local_cpu_data().clock_tick / nmi_hz;
return ((u64)((0 - delta) & 0xffffffff)) << 32;
}
static void n2_pcr_write(unsigned long reg_num, u64 val)
{
unsigned long ret;
WARN_ON_ONCE(reg_num != 0);
if (val & PCR_N2_HTRACE) {
ret = sun4v_niagara2_setperf(HV_N2_PERF_SPARC_CTL, val);
if (ret != HV_EOK)
direct_pcr_write(reg_num, val);
} else
direct_pcr_write(reg_num, val);
}
static u64 n2_picl_value(unsigned int nmi_hz)
{
u32 delta = local_cpu_data().clock_tick / (nmi_hz << 2);
return ((u64)((0 - delta) & 0xffffffff)) << 32;
}
static u64 n4_pcr_read(unsigned long reg_num)
{
unsigned long val;
(void) sun4v_vt_get_perfreg(reg_num, &val);
return val;
}
static void n4_pcr_write(unsigned long reg_num, u64 val)
{
(void) sun4v_vt_set_perfreg(reg_num, val);
}
static u64 n4_pic_read(unsigned long reg_num)
{
unsigned long val;
__asm__ __volatile__("ldxa [%1] %2, %0"
: "=r" (val)
: "r" (reg_num * 0x8UL), "i" (ASI_PIC));
return val;
}
static void n4_pic_write(unsigned long reg_num, u64 val)
{
__asm__ __volatile__("stxa %0, [%1] %2"
:
: "r" (val), "r" (reg_num * 0x8UL), "i" (ASI_PIC));
}
static u64 n4_picl_value(unsigned int nmi_hz)
{
u32 delta = local_cpu_data().clock_tick / (nmi_hz << 2);
return ((u64)((0 - delta) & 0xffffffff));
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
case SUN4V_CHIP_NIAGARA4:
perf_hsvc_group = HV_GRP_VT_CPU;
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
static int __init setup_sun4v_pcr_ops(void)
{
int ret = 0;
switch (sun4v_chip_type) {
case SUN4V_CHIP_NIAGARA1:
case SUN4V_CHIP_NIAGARA2:
case SUN4V_CHIP_NIAGARA3:
pcr_ops = &n2_pcr_ops;
break;
case SUN4V_CHIP_NIAGARA4:
pcr_ops = &n4_pcr_ops;
break;
default:
ret = -ENODEV;
break;
}
return ret;
}
int __init pcr_arch_init(void)
{
int err = register_perf_hsvc();
if (err)
return err;
switch (tlb_type) {
case hypervisor:
err = setup_sun4v_pcr_ops();
if (err)
goto out_unregister;
break;
case cheetah:
case cheetah_plus:
pcr_ops = &direct_pcr_ops;
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
