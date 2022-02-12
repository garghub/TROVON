static void __init
xen_info_init(void)
{
unsigned long rsc = ia64_getreg(_IA64_REG_AR_RSC);
unsigned int rpl = (rsc & IA64_RSC_PL_MASK) >> IA64_RSC_PL_SHIFT;
xen_info.kernel_rpl = rpl;
}
static void
xen_panic_hypercall(struct unw_frame_info *info, void *arg)
{
current->thread.ksp = (__u64)info->sw - 16;
HYPERVISOR_shutdown(SHUTDOWN_crash);
}
static int
xen_panic_event(struct notifier_block *this, unsigned long event, void *ptr)
{
unw_init_running(xen_panic_hypercall, NULL);
return NOTIFY_DONE;
}
static void xen_pm_power_off(void)
{
local_irq_disable();
HYPERVISOR_shutdown(SHUTDOWN_poweroff);
}
static void __init
xen_banner(void)
{
printk(KERN_INFO
"Running on Xen! pl = %d start_info_pfn=0x%lx nr_pages=%ld "
"flags=0x%x\n",
xen_info.kernel_rpl,
HYPERVISOR_shared_info->arch.start_info_pfn,
xen_start_info->nr_pages, xen_start_info->flags);
}
static int __init
xen_reserve_memory(struct rsvd_region *region)
{
region->start = (unsigned long)__va(
(HYPERVISOR_shared_info->arch.start_info_pfn << PAGE_SHIFT));
region->end = region->start + PAGE_SIZE;
return 1;
}
static void __init
xen_arch_setup_early(void)
{
struct shared_info *s;
BUG_ON(!xen_pv_domain());
s = HYPERVISOR_shared_info;
xen_start_info = __va(s->arch.start_info_pfn << PAGE_SHIFT);
xencomm_initialize();
xen_setup_features();
atomic_notifier_chain_register(&panic_notifier_list,
&xen_panic_block);
pm_power_off = xen_pm_power_off;
xen_ia64_enable_opt_feature();
}
static void __init
xen_arch_setup_console(char **cmdline_p)
{
add_preferred_console("xenboot", 0, NULL);
add_preferred_console("tty", 0, NULL);
add_preferred_console("hvc", 0, NULL);
#if !defined(CONFIG_VT) || !defined(CONFIG_DUMMY_CONSOLE)
conswitchp = NULL;
#endif
}
static int __init
xen_arch_setup_nomca(void)
{
return 1;
}
static void __init
xen_post_smp_prepare_boot_cpu(void)
{
xen_setup_vcpu_info_placement();
}
static void
xen_set_itm_with_offset(unsigned long val)
{
xen_set_itm(val - XEN_MAPPEDREGS->itc_offset);
}
static unsigned long
xen_get_itm_with_offset(void)
{
printk(KERN_DEBUG "%s is called.\n", __func__);
WARN_ON(!irqs_disabled());
return ia64_native_getreg(_IA64_REG_CR_ITM) +
XEN_MAPPEDREGS->itc_offset;
}
static void
xen_set_itc(unsigned long val)
{
unsigned long mitc;
WARN_ON(!irqs_disabled());
mitc = ia64_native_getreg(_IA64_REG_AR_ITC);
XEN_MAPPEDREGS->itc_offset = val - mitc;
XEN_MAPPEDREGS->itc_last = val;
}
static unsigned long
xen_get_itc(void)
{
unsigned long res;
unsigned long itc_offset;
unsigned long itc_last;
unsigned long ret_itc_last;
itc_offset = XEN_MAPPEDREGS->itc_offset;
do {
itc_last = XEN_MAPPEDREGS->itc_last;
res = ia64_native_getreg(_IA64_REG_AR_ITC);
res += itc_offset;
if (itc_last >= res)
res = itc_last + 1;
ret_itc_last = cmpxchg(&XEN_MAPPEDREGS->itc_last,
itc_last, res);
} while (unlikely(ret_itc_last != itc_last));
return res;
#if 0
WARN_ON(!irqs_disabled());
itc_offset = XEN_MAPPEDREGS->itc_offset;
itc_last = XEN_MAPPEDREGS->itc_last;
res = ia64_native_getreg(_IA64_REG_AR_ITC);
res += itc_offset;
if (itc_last >= res)
res = itc_last + 1;
XEN_MAPPEDREGS->itc_last = res;
return res;
#endif
}
static void xen_setreg(int regnum, unsigned long val)
{
switch (regnum) {
case _IA64_REG_AR_KR0 ... _IA64_REG_AR_KR7:
xen_set_kr(regnum - _IA64_REG_AR_KR0, val);
break;
case _IA64_REG_AR_ITC:
xen_set_itc(val);
break;
case _IA64_REG_CR_TPR:
xen_set_tpr(val);
break;
case _IA64_REG_CR_ITM:
xen_set_itm_with_offset(val);
break;
case _IA64_REG_CR_EOI:
xen_eoi(val);
break;
default:
ia64_native_setreg_func(regnum, val);
break;
}
}
static unsigned long xen_getreg(int regnum)
{
unsigned long res;
switch (regnum) {
case _IA64_REG_PSR:
res = xen_get_psr();
break;
case _IA64_REG_AR_ITC:
res = xen_get_itc();
break;
case _IA64_REG_CR_ITM:
res = xen_get_itm_with_offset();
break;
case _IA64_REG_CR_IVR:
res = xen_get_ivr();
break;
case _IA64_REG_CR_TPR:
res = xen_get_tpr();
break;
default:
res = ia64_native_getreg_func(regnum);
break;
}
return res;
}
static void
xen_ssm_i(void)
{
int old = xen_get_virtual_psr_i();
xen_set_virtual_psr_i(1);
barrier();
if (!old && xen_get_virtual_pend())
xen_hyper_ssm_i();
}
static void
xen_rsm_i(void)
{
xen_set_virtual_psr_i(0);
barrier();
}
static unsigned long
xen_get_psr_i(void)
{
return xen_get_virtual_psr_i() ? IA64_PSR_I : 0;
}
static void
xen_intrin_local_irq_restore(unsigned long mask)
{
if (mask & IA64_PSR_I)
xen_ssm_i();
else
xen_rsm_i();
}
static void
xen_pcat_compat_init(void)
{
}
static struct irq_chip*
xen_iosapic_get_irq_chip(unsigned long trigger)
{
return NULL;
}
static unsigned int
xen_iosapic_read(char __iomem *iosapic, unsigned int reg)
{
struct physdev_apic apic_op;
int ret;
apic_op.apic_physbase = (unsigned long)iosapic -
__IA64_UNCACHED_OFFSET;
apic_op.reg = reg;
ret = HYPERVISOR_physdev_op(PHYSDEVOP_apic_read, &apic_op);
if (ret)
return ret;
return apic_op.value;
}
static void
xen_iosapic_write(char __iomem *iosapic, unsigned int reg, u32 val)
{
struct physdev_apic apic_op;
apic_op.apic_physbase = (unsigned long)iosapic -
__IA64_UNCACHED_OFFSET;
apic_op.reg = reg;
apic_op.value = val;
HYPERVISOR_physdev_op(PHYSDEVOP_apic_write, &apic_op);
}
void __init
xen_setup_pv_ops(void)
{
xen_info_init();
pv_info = xen_info;
pv_init_ops = xen_init_ops;
pv_fsys_data = xen_fsys_data;
pv_patchdata = xen_patchdata;
pv_cpu_ops = xen_cpu_ops;
pv_iosapic_ops = xen_iosapic_ops;
pv_irq_ops = xen_irq_ops;
pv_time_ops = xen_time_ops;
paravirt_cpu_asm_init(&xen_cpu_asm_switch);
}
static unsigned long __init_or_module
xen_patch_bundle(void *sbundle, void *ebundle, unsigned long type)
{
const unsigned long nelems = sizeof(xen_patch_bundle_elems) /
sizeof(xen_patch_bundle_elems[0]);
unsigned long used;
const struct paravirt_patch_bundle_elem *found;
used = __paravirt_patch_apply_bundle(sbundle, ebundle, type,
xen_patch_bundle_elems, nelems,
&found);
if (found == NULL)
return ia64_native_patch_bundle(sbundle, ebundle, type);
if (used == 0)
return used;
switch (type) {
case PARAVIRT_PATCH_TYPE_INTRIN_LOCAL_IRQ_RESTORE: {
unsigned long reloc =
__xen_intrin_local_irq_restore_direct_reloc;
unsigned long reloc_offset = reloc - (unsigned long)
__xen_intrin_local_irq_restore_direct_start;
unsigned long tag = (unsigned long)sbundle + reloc_offset;
paravirt_patch_reloc_brl(tag, xen_check_events);
break;
}
default:
break;
}
return used;
}
static void __init
xen_patch_branch(unsigned long tag, unsigned long type)
{
__paravirt_patch_apply_branch(tag, type, xen_branch_target,
ARRAY_SIZE(xen_branch_target));
}
