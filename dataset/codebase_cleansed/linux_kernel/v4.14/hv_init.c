struct ms_hyperv_tsc_page *hv_get_tsc_page(void)
{
return tsc_pg;
}
static u64 read_hv_clock_tsc(struct clocksource *arg)
{
u64 current_tick = hv_read_tsc_page(tsc_pg);
if (current_tick == U64_MAX)
rdmsrl(HV_X64_MSR_TIME_REF_COUNT, current_tick);
return current_tick;
}
static u64 read_hv_clock_msr(struct clocksource *arg)
{
u64 current_tick;
rdmsrl(HV_X64_MSR_TIME_REF_COUNT, current_tick);
return current_tick;
}
static int hv_cpu_init(unsigned int cpu)
{
u64 msr_vp_index;
hv_get_vp_index(msr_vp_index);
hv_vp_index[smp_processor_id()] = msr_vp_index;
if (msr_vp_index > hv_max_vp_index)
hv_max_vp_index = msr_vp_index;
return 0;
}
void hyperv_init(void)
{
u64 guest_id;
union hv_x64_msr_hypercall_contents hypercall_msr;
if (x86_hyper != &x86_hyper_ms_hyperv)
return;
hv_vp_index = kmalloc_array(num_possible_cpus(), sizeof(*hv_vp_index),
GFP_KERNEL);
if (!hv_vp_index)
return;
if (cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "x86/hyperv_init:online",
hv_cpu_init, NULL) < 0)
goto free_vp_index;
guest_id = generate_guest_id(0, LINUX_VERSION_CODE, 0);
wrmsrl(HV_X64_MSR_GUEST_OS_ID, guest_id);
hv_hypercall_pg = __vmalloc(PAGE_SIZE, GFP_KERNEL, PAGE_KERNEL_RX);
if (hv_hypercall_pg == NULL) {
wrmsrl(HV_X64_MSR_GUEST_OS_ID, 0);
goto free_vp_index;
}
rdmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
hypercall_msr.enable = 1;
hypercall_msr.guest_physical_address = vmalloc_to_pfn(hv_hypercall_pg);
wrmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
hyper_alloc_mmu();
#ifdef CONFIG_HYPERV_TSCPAGE
if (ms_hyperv.features & HV_X64_MSR_REFERENCE_TSC_AVAILABLE) {
union hv_x64_msr_hypercall_contents tsc_msr;
tsc_pg = __vmalloc(PAGE_SIZE, GFP_KERNEL, PAGE_KERNEL);
if (!tsc_pg)
goto register_msr_cs;
hyperv_cs = &hyperv_cs_tsc;
rdmsrl(HV_X64_MSR_REFERENCE_TSC, tsc_msr.as_uint64);
tsc_msr.enable = 1;
tsc_msr.guest_physical_address = vmalloc_to_pfn(tsc_pg);
wrmsrl(HV_X64_MSR_REFERENCE_TSC, tsc_msr.as_uint64);
hyperv_cs_tsc.archdata.vclock_mode = VCLOCK_HVCLOCK;
clocksource_register_hz(&hyperv_cs_tsc, NSEC_PER_SEC/100);
return;
}
register_msr_cs:
#endif
hyperv_cs = &hyperv_cs_msr;
if (ms_hyperv.features & HV_X64_MSR_TIME_REF_COUNT_AVAILABLE)
clocksource_register_hz(&hyperv_cs_msr, NSEC_PER_SEC/100);
return;
free_vp_index:
kfree(hv_vp_index);
hv_vp_index = NULL;
}
void hyperv_cleanup(void)
{
union hv_x64_msr_hypercall_contents hypercall_msr;
wrmsrl(HV_X64_MSR_GUEST_OS_ID, 0);
hypercall_msr.as_uint64 = 0;
wrmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
hypercall_msr.as_uint64 = 0;
wrmsrl(HV_X64_MSR_REFERENCE_TSC, hypercall_msr.as_uint64);
}
void hyperv_report_panic(struct pt_regs *regs)
{
static bool panic_reported;
if (panic_reported)
return;
panic_reported = true;
wrmsrl(HV_X64_MSR_CRASH_P0, regs->ip);
wrmsrl(HV_X64_MSR_CRASH_P1, regs->ax);
wrmsrl(HV_X64_MSR_CRASH_P2, regs->bx);
wrmsrl(HV_X64_MSR_CRASH_P3, regs->cx);
wrmsrl(HV_X64_MSR_CRASH_P4, regs->dx);
wrmsrl(HV_X64_MSR_CRASH_CTL, HV_CRASH_CTL_CRASH_NOTIFY);
}
bool hv_is_hypercall_page_setup(void)
{
union hv_x64_msr_hypercall_contents hypercall_msr;
hypercall_msr.as_uint64 = 0;
rdmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
if (!hypercall_msr.enable)
return false;
return true;
}
