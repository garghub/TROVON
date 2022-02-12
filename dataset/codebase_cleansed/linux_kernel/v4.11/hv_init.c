static u64 read_hv_clock_tsc(struct clocksource *arg)
{
u64 current_tick;
if (tsc_pg->tsc_sequence != 0) {
while (1) {
u64 tmp;
u32 sequence = tsc_pg->tsc_sequence;
u64 cur_tsc;
u64 scale = tsc_pg->tsc_scale;
s64 offset = tsc_pg->tsc_offset;
rdtscll(cur_tsc);
asm("mulq %3"
: "=d" (current_tick), "=a" (tmp)
: "a" (cur_tsc), "r" (scale));
current_tick += offset;
if (tsc_pg->tsc_sequence == sequence)
return current_tick;
if (tsc_pg->tsc_sequence != 0)
continue;
break;
}
}
rdmsrl(HV_X64_MSR_TIME_REF_COUNT, current_tick);
return current_tick;
}
static u64 read_hv_clock_msr(struct clocksource *arg)
{
u64 current_tick;
rdmsrl(HV_X64_MSR_TIME_REF_COUNT, current_tick);
return current_tick;
}
void hyperv_init(void)
{
u64 guest_id;
union hv_x64_msr_hypercall_contents hypercall_msr;
if (x86_hyper != &x86_hyper_ms_hyperv)
return;
guest_id = generate_guest_id(0, LINUX_VERSION_CODE, 0);
wrmsrl(HV_X64_MSR_GUEST_OS_ID, guest_id);
hypercall_pg = __vmalloc(PAGE_SIZE, GFP_KERNEL, PAGE_KERNEL_RX);
if (hypercall_pg == NULL) {
wrmsrl(HV_X64_MSR_GUEST_OS_ID, 0);
return;
}
rdmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
hypercall_msr.enable = 1;
hypercall_msr.guest_physical_address = vmalloc_to_pfn(hypercall_pg);
wrmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
#ifdef CONFIG_X86_64
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
clocksource_register_hz(&hyperv_cs_tsc, NSEC_PER_SEC/100);
return;
}
register_msr_cs:
#endif
hyperv_cs = &hyperv_cs_msr;
if (ms_hyperv.features & HV_X64_MSR_TIME_REF_COUNT_AVAILABLE)
clocksource_register_hz(&hyperv_cs_msr, NSEC_PER_SEC/100);
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
u64 hv_do_hypercall(u64 control, void *input, void *output)
{
u64 input_address = (input) ? virt_to_phys(input) : 0;
u64 output_address = (output) ? virt_to_phys(output) : 0;
#ifdef CONFIG_X86_64
u64 hv_status = 0;
if (!hypercall_pg)
return (u64)ULLONG_MAX;
__asm__ __volatile__("mov %0, %%r8" : : "r" (output_address) : "r8");
__asm__ __volatile__("call *%3" : "=a" (hv_status) :
"c" (control), "d" (input_address),
"m" (hypercall_pg));
return hv_status;
#else
u32 control_hi = control >> 32;
u32 control_lo = control & 0xFFFFFFFF;
u32 hv_status_hi = 1;
u32 hv_status_lo = 1;
u32 input_address_hi = input_address >> 32;
u32 input_address_lo = input_address & 0xFFFFFFFF;
u32 output_address_hi = output_address >> 32;
u32 output_address_lo = output_address & 0xFFFFFFFF;
if (!hypercall_pg)
return (u64)ULLONG_MAX;
__asm__ __volatile__ ("call *%8" : "=d"(hv_status_hi),
"=a"(hv_status_lo) : "d" (control_hi),
"a" (control_lo), "b" (input_address_hi),
"c" (input_address_lo), "D"(output_address_hi),
"S"(output_address_lo), "m" (hypercall_pg));
return hv_status_lo | ((u64)hv_status_hi << 32);
#endif
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
