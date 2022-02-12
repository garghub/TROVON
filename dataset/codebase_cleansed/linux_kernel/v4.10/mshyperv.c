void hyperv_vector_handler(struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
entering_irq();
inc_irq_stat(irq_hv_callback_count);
if (vmbus_handler)
vmbus_handler();
exiting_irq();
set_irq_regs(old_regs);
}
void hv_setup_vmbus_irq(void (*handler)(void))
{
vmbus_handler = handler;
if (!test_bit(HYPERVISOR_CALLBACK_VECTOR, used_vectors))
alloc_intr_gate(HYPERVISOR_CALLBACK_VECTOR,
hyperv_callback_vector);
}
void hv_remove_vmbus_irq(void)
{
vmbus_handler = NULL;
}
void hv_setup_kexec_handler(void (*handler)(void))
{
hv_kexec_handler = handler;
}
void hv_remove_kexec_handler(void)
{
hv_kexec_handler = NULL;
}
void hv_setup_crash_handler(void (*handler)(struct pt_regs *regs))
{
hv_crash_handler = handler;
}
void hv_remove_crash_handler(void)
{
hv_crash_handler = NULL;
}
static void hv_machine_shutdown(void)
{
if (kexec_in_progress && hv_kexec_handler)
hv_kexec_handler();
native_machine_shutdown();
}
static void hv_machine_crash_shutdown(struct pt_regs *regs)
{
if (hv_crash_handler)
hv_crash_handler(regs);
native_machine_crash_shutdown(regs);
}
static uint32_t __init ms_hyperv_platform(void)
{
u32 eax;
u32 hyp_signature[3];
if (!boot_cpu_has(X86_FEATURE_HYPERVISOR))
return 0;
cpuid(HYPERV_CPUID_VENDOR_AND_MAX_FUNCTIONS,
&eax, &hyp_signature[0], &hyp_signature[1], &hyp_signature[2]);
if (eax >= HYPERV_CPUID_MIN &&
eax <= HYPERV_CPUID_MAX &&
!memcmp("Microsoft Hv", hyp_signature, 12))
return HYPERV_CPUID_VENDOR_AND_MAX_FUNCTIONS;
return 0;
}
static u64 read_hv_clock(struct clocksource *arg)
{
u64 current_tick;
rdmsrl(HV_X64_MSR_TIME_REF_COUNT, current_tick);
return current_tick;
}
static unsigned char hv_get_nmi_reason(void)
{
return 0;
}
static int hv_nmi_unknown(unsigned int val, struct pt_regs *regs)
{
static atomic_t nmi_cpu = ATOMIC_INIT(-1);
if (!unknown_nmi_panic)
return NMI_DONE;
if (atomic_cmpxchg(&nmi_cpu, -1, raw_smp_processor_id()) != -1)
return NMI_HANDLED;
return NMI_DONE;
}
static void __init ms_hyperv_init_platform(void)
{
ms_hyperv.features = cpuid_eax(HYPERV_CPUID_FEATURES);
ms_hyperv.misc_features = cpuid_edx(HYPERV_CPUID_FEATURES);
ms_hyperv.hints = cpuid_eax(HYPERV_CPUID_ENLIGHTMENT_INFO);
pr_info("HyperV: features 0x%x, hints 0x%x\n",
ms_hyperv.features, ms_hyperv.hints);
#ifdef CONFIG_X86_LOCAL_APIC
if (ms_hyperv.features & HV_X64_MSR_APIC_FREQUENCY_AVAILABLE) {
u64 hv_lapic_frequency;
rdmsrl(HV_X64_MSR_APIC_FREQUENCY, hv_lapic_frequency);
hv_lapic_frequency = div_u64(hv_lapic_frequency, HZ);
lapic_timer_frequency = hv_lapic_frequency;
pr_info("HyperV: LAPIC Timer Frequency: %#x\n",
lapic_timer_frequency);
}
register_nmi_handler(NMI_UNKNOWN, hv_nmi_unknown, NMI_FLAG_FIRST,
"hv_nmi_unknown");
#endif
if (ms_hyperv.features & HV_X64_MSR_TIME_REF_COUNT_AVAILABLE)
clocksource_register_hz(&hyperv_cs, NSEC_PER_SEC/100);
#ifdef CONFIG_X86_IO_APIC
no_timer_check = 1;
#endif
#if IS_ENABLED(CONFIG_HYPERV) && defined(CONFIG_KEXEC_CORE)
machine_ops.shutdown = hv_machine_shutdown;
machine_ops.crash_shutdown = hv_machine_crash_shutdown;
#endif
mark_tsc_unstable("running on Hyper-V");
if (efi_enabled(EFI_BOOT))
x86_platform.get_nmi_reason = hv_get_nmi_reason;
}
