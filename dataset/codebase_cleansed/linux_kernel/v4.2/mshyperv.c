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
static cycle_t read_hv_clock(struct clocksource *arg)
{
cycle_t current_tick;
rdmsrl(HV_X64_MSR_TIME_REF_COUNT, current_tick);
return current_tick;
}
static void __init ms_hyperv_init_platform(void)
{
ms_hyperv.features = cpuid_eax(HYPERV_CPUID_FEATURES);
ms_hyperv.hints = cpuid_eax(HYPERV_CPUID_ENLIGHTMENT_INFO);
printk(KERN_INFO "HyperV: features 0x%x, hints 0x%x\n",
ms_hyperv.features, ms_hyperv.hints);
#ifdef CONFIG_X86_LOCAL_APIC
if (ms_hyperv.features & HV_X64_MSR_APIC_FREQUENCY_AVAILABLE) {
u64 hv_lapic_frequency;
rdmsrl(HV_X64_MSR_APIC_FREQUENCY, hv_lapic_frequency);
hv_lapic_frequency = div_u64(hv_lapic_frequency, HZ);
lapic_timer_frequency = hv_lapic_frequency;
printk(KERN_INFO "HyperV: LAPIC Timer Frequency: %#x\n",
lapic_timer_frequency);
}
#endif
if (ms_hyperv.features & HV_X64_MSR_TIME_REF_COUNT_AVAILABLE)
clocksource_register_hz(&hyperv_cs, NSEC_PER_SEC/100);
#ifdef CONFIG_X86_IO_APIC
no_timer_check = 1;
#endif
}
