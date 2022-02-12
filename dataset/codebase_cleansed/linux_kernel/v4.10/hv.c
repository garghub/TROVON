static int query_hypervisor_info(void)
{
unsigned int eax;
unsigned int ebx;
unsigned int ecx;
unsigned int edx;
unsigned int max_leaf;
unsigned int op;
eax = 0;
ebx = 0;
ecx = 0;
edx = 0;
op = HVCPUID_VENDOR_MAXFUNCTION;
cpuid(op, &eax, &ebx, &ecx, &edx);
max_leaf = eax;
if (max_leaf >= HVCPUID_VERSION) {
eax = 0;
ebx = 0;
ecx = 0;
edx = 0;
op = HVCPUID_VERSION;
cpuid(op, &eax, &ebx, &ecx, &edx);
host_info_eax = eax;
host_info_ebx = ebx;
host_info_ecx = ecx;
host_info_edx = edx;
}
return max_leaf;
}
u64 hv_do_hypercall(u64 control, void *input, void *output)
{
u64 input_address = (input) ? virt_to_phys(input) : 0;
u64 output_address = (output) ? virt_to_phys(output) : 0;
void *hypercall_page = hv_context.hypercall_page;
#ifdef CONFIG_X86_64
u64 hv_status = 0;
if (!hypercall_page)
return (u64)ULLONG_MAX;
__asm__ __volatile__("mov %0, %%r8" : : "r" (output_address) : "r8");
__asm__ __volatile__("call *%3" : "=a" (hv_status) :
"c" (control), "d" (input_address),
"m" (hypercall_page));
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
if (!hypercall_page)
return (u64)ULLONG_MAX;
__asm__ __volatile__ ("call *%8" : "=d"(hv_status_hi),
"=a"(hv_status_lo) : "d" (control_hi),
"a" (control_lo), "b" (input_address_hi),
"c" (input_address_lo), "D"(output_address_hi),
"S"(output_address_lo), "m" (hypercall_page));
return hv_status_lo | ((u64)hv_status_hi << 32);
#endif
}
static u64 read_hv_clock_tsc(struct clocksource *arg)
{
u64 current_tick;
struct ms_hyperv_tsc_page *tsc_pg = hv_context.tsc_page;
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
int hv_init(void)
{
int max_leaf;
union hv_x64_msr_hypercall_contents hypercall_msr;
void *virtaddr = NULL;
memset(hv_context.synic_event_page, 0, sizeof(void *) * NR_CPUS);
memset(hv_context.synic_message_page, 0,
sizeof(void *) * NR_CPUS);
memset(hv_context.post_msg_page, 0,
sizeof(void *) * NR_CPUS);
memset(hv_context.vp_index, 0,
sizeof(int) * NR_CPUS);
memset(hv_context.event_dpc, 0,
sizeof(void *) * NR_CPUS);
memset(hv_context.msg_dpc, 0,
sizeof(void *) * NR_CPUS);
memset(hv_context.clk_evt, 0,
sizeof(void *) * NR_CPUS);
max_leaf = query_hypervisor_info();
hv_context.guestid = generate_guest_id(0, LINUX_VERSION_CODE, 0);
wrmsrl(HV_X64_MSR_GUEST_OS_ID, hv_context.guestid);
rdmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
virtaddr = __vmalloc(PAGE_SIZE, GFP_KERNEL, PAGE_KERNEL_EXEC);
if (!virtaddr)
goto cleanup;
hypercall_msr.enable = 1;
hypercall_msr.guest_physical_address = vmalloc_to_pfn(virtaddr);
wrmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
hypercall_msr.as_uint64 = 0;
rdmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
if (!hypercall_msr.enable)
goto cleanup;
hv_context.hypercall_page = virtaddr;
#ifdef CONFIG_X86_64
if (ms_hyperv.features & HV_X64_MSR_REFERENCE_TSC_AVAILABLE) {
union hv_x64_msr_hypercall_contents tsc_msr;
void *va_tsc;
va_tsc = __vmalloc(PAGE_SIZE, GFP_KERNEL, PAGE_KERNEL);
if (!va_tsc)
goto cleanup;
hv_context.tsc_page = va_tsc;
rdmsrl(HV_X64_MSR_REFERENCE_TSC, tsc_msr.as_uint64);
tsc_msr.enable = 1;
tsc_msr.guest_physical_address = vmalloc_to_pfn(va_tsc);
wrmsrl(HV_X64_MSR_REFERENCE_TSC, tsc_msr.as_uint64);
clocksource_register_hz(&hyperv_cs_tsc, NSEC_PER_SEC/100);
}
#endif
return 0;
cleanup:
if (virtaddr) {
if (hypercall_msr.enable) {
hypercall_msr.as_uint64 = 0;
wrmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
}
vfree(virtaddr);
}
return -ENOTSUPP;
}
void hv_cleanup(bool crash)
{
union hv_x64_msr_hypercall_contents hypercall_msr;
wrmsrl(HV_X64_MSR_GUEST_OS_ID, 0);
if (hv_context.hypercall_page) {
hypercall_msr.as_uint64 = 0;
wrmsrl(HV_X64_MSR_HYPERCALL, hypercall_msr.as_uint64);
if (!crash)
vfree(hv_context.hypercall_page);
hv_context.hypercall_page = NULL;
}
#ifdef CONFIG_X86_64
if (ms_hyperv.features & HV_X64_MSR_REFERENCE_TSC_AVAILABLE) {
if (!oops_in_progress) {
clocksource_change_rating(&hyperv_cs_tsc, 10);
clocksource_unregister(&hyperv_cs_tsc);
}
hypercall_msr.as_uint64 = 0;
wrmsrl(HV_X64_MSR_REFERENCE_TSC, hypercall_msr.as_uint64);
if (!crash)
vfree(hv_context.tsc_page);
hv_context.tsc_page = NULL;
}
#endif
}
int hv_post_message(union hv_connection_id connection_id,
enum hv_message_type message_type,
void *payload, size_t payload_size)
{
struct hv_input_post_message *aligned_msg;
u64 status;
if (payload_size > HV_MESSAGE_PAYLOAD_BYTE_COUNT)
return -EMSGSIZE;
aligned_msg = (struct hv_input_post_message *)
hv_context.post_msg_page[get_cpu()];
aligned_msg->connectionid = connection_id;
aligned_msg->reserved = 0;
aligned_msg->message_type = message_type;
aligned_msg->payload_size = payload_size;
memcpy((void *)aligned_msg->payload, payload, payload_size);
status = hv_do_hypercall(HVCALL_POST_MESSAGE, aligned_msg, NULL);
put_cpu();
return status & 0xFFFF;
}
static int hv_ce_set_next_event(unsigned long delta,
struct clock_event_device *evt)
{
u64 current_tick;
WARN_ON(!clockevent_state_oneshot(evt));
rdmsrl(HV_X64_MSR_TIME_REF_COUNT, current_tick);
current_tick += delta;
wrmsrl(HV_X64_MSR_STIMER0_COUNT, current_tick);
return 0;
}
static int hv_ce_shutdown(struct clock_event_device *evt)
{
wrmsrl(HV_X64_MSR_STIMER0_COUNT, 0);
wrmsrl(HV_X64_MSR_STIMER0_CONFIG, 0);
return 0;
}
static int hv_ce_set_oneshot(struct clock_event_device *evt)
{
union hv_timer_config timer_cfg;
timer_cfg.enable = 1;
timer_cfg.auto_enable = 1;
timer_cfg.sintx = VMBUS_MESSAGE_SINT;
wrmsrl(HV_X64_MSR_STIMER0_CONFIG, timer_cfg.as_uint64);
return 0;
}
static void hv_init_clockevent_device(struct clock_event_device *dev, int cpu)
{
dev->name = "Hyper-V clockevent";
dev->features = CLOCK_EVT_FEAT_ONESHOT;
dev->cpumask = cpumask_of(cpu);
dev->rating = 1000;
dev->set_state_shutdown = hv_ce_shutdown;
dev->set_state_oneshot = hv_ce_set_oneshot;
dev->set_next_event = hv_ce_set_next_event;
}
int hv_synic_alloc(void)
{
size_t size = sizeof(struct tasklet_struct);
size_t ced_size = sizeof(struct clock_event_device);
int cpu;
hv_context.hv_numa_map = kzalloc(sizeof(struct cpumask) * nr_node_ids,
GFP_ATOMIC);
if (hv_context.hv_numa_map == NULL) {
pr_err("Unable to allocate NUMA map\n");
goto err;
}
for_each_online_cpu(cpu) {
hv_context.event_dpc[cpu] = kmalloc(size, GFP_ATOMIC);
if (hv_context.event_dpc[cpu] == NULL) {
pr_err("Unable to allocate event dpc\n");
goto err;
}
tasklet_init(hv_context.event_dpc[cpu], vmbus_on_event, cpu);
hv_context.msg_dpc[cpu] = kmalloc(size, GFP_ATOMIC);
if (hv_context.msg_dpc[cpu] == NULL) {
pr_err("Unable to allocate event dpc\n");
goto err;
}
tasklet_init(hv_context.msg_dpc[cpu], vmbus_on_msg_dpc, cpu);
hv_context.clk_evt[cpu] = kzalloc(ced_size, GFP_ATOMIC);
if (hv_context.clk_evt[cpu] == NULL) {
pr_err("Unable to allocate clock event device\n");
goto err;
}
hv_init_clockevent_device(hv_context.clk_evt[cpu], cpu);
hv_context.synic_message_page[cpu] =
(void *)get_zeroed_page(GFP_ATOMIC);
if (hv_context.synic_message_page[cpu] == NULL) {
pr_err("Unable to allocate SYNIC message page\n");
goto err;
}
hv_context.synic_event_page[cpu] =
(void *)get_zeroed_page(GFP_ATOMIC);
if (hv_context.synic_event_page[cpu] == NULL) {
pr_err("Unable to allocate SYNIC event page\n");
goto err;
}
hv_context.post_msg_page[cpu] =
(void *)get_zeroed_page(GFP_ATOMIC);
if (hv_context.post_msg_page[cpu] == NULL) {
pr_err("Unable to allocate post msg page\n");
goto err;
}
}
return 0;
err:
return -ENOMEM;
}
static void hv_synic_free_cpu(int cpu)
{
kfree(hv_context.event_dpc[cpu]);
kfree(hv_context.msg_dpc[cpu]);
kfree(hv_context.clk_evt[cpu]);
if (hv_context.synic_event_page[cpu])
free_page((unsigned long)hv_context.synic_event_page[cpu]);
if (hv_context.synic_message_page[cpu])
free_page((unsigned long)hv_context.synic_message_page[cpu]);
if (hv_context.post_msg_page[cpu])
free_page((unsigned long)hv_context.post_msg_page[cpu]);
}
void hv_synic_free(void)
{
int cpu;
kfree(hv_context.hv_numa_map);
for_each_online_cpu(cpu)
hv_synic_free_cpu(cpu);
}
void hv_synic_init(void *arg)
{
u64 version;
union hv_synic_simp simp;
union hv_synic_siefp siefp;
union hv_synic_sint shared_sint;
union hv_synic_scontrol sctrl;
u64 vp_index;
int cpu = smp_processor_id();
if (!hv_context.hypercall_page)
return;
rdmsrl(HV_X64_MSR_SVERSION, version);
rdmsrl(HV_X64_MSR_SIMP, simp.as_uint64);
simp.simp_enabled = 1;
simp.base_simp_gpa = virt_to_phys(hv_context.synic_message_page[cpu])
>> PAGE_SHIFT;
wrmsrl(HV_X64_MSR_SIMP, simp.as_uint64);
rdmsrl(HV_X64_MSR_SIEFP, siefp.as_uint64);
siefp.siefp_enabled = 1;
siefp.base_siefp_gpa = virt_to_phys(hv_context.synic_event_page[cpu])
>> PAGE_SHIFT;
wrmsrl(HV_X64_MSR_SIEFP, siefp.as_uint64);
rdmsrl(HV_X64_MSR_SINT0 + VMBUS_MESSAGE_SINT, shared_sint.as_uint64);
shared_sint.as_uint64 = 0;
shared_sint.vector = HYPERVISOR_CALLBACK_VECTOR;
shared_sint.masked = false;
shared_sint.auto_eoi = true;
wrmsrl(HV_X64_MSR_SINT0 + VMBUS_MESSAGE_SINT, shared_sint.as_uint64);
rdmsrl(HV_X64_MSR_SCONTROL, sctrl.as_uint64);
sctrl.enable = 1;
wrmsrl(HV_X64_MSR_SCONTROL, sctrl.as_uint64);
hv_context.synic_initialized = true;
rdmsrl(HV_X64_MSR_VP_INDEX, vp_index);
hv_context.vp_index[cpu] = (u32)vp_index;
INIT_LIST_HEAD(&hv_context.percpu_list[cpu]);
if (ms_hyperv.features & HV_X64_MSR_SYNTIMER_AVAILABLE)
clockevents_config_and_register(hv_context.clk_evt[cpu],
HV_TIMER_FREQUENCY,
HV_MIN_DELTA_TICKS,
HV_MAX_MAX_DELTA_TICKS);
return;
}
void hv_synic_clockevents_cleanup(void)
{
int cpu;
if (!(ms_hyperv.features & HV_X64_MSR_SYNTIMER_AVAILABLE))
return;
for_each_present_cpu(cpu)
clockevents_unbind_device(hv_context.clk_evt[cpu], cpu);
}
void hv_synic_cleanup(void *arg)
{
union hv_synic_sint shared_sint;
union hv_synic_simp simp;
union hv_synic_siefp siefp;
union hv_synic_scontrol sctrl;
int cpu = smp_processor_id();
if (!hv_context.synic_initialized)
return;
if (ms_hyperv.features & HV_X64_MSR_SYNTIMER_AVAILABLE) {
clockevents_unbind_device(hv_context.clk_evt[cpu], cpu);
hv_ce_shutdown(hv_context.clk_evt[cpu]);
}
rdmsrl(HV_X64_MSR_SINT0 + VMBUS_MESSAGE_SINT, shared_sint.as_uint64);
shared_sint.masked = 1;
wrmsrl(HV_X64_MSR_SINT0 + VMBUS_MESSAGE_SINT, shared_sint.as_uint64);
rdmsrl(HV_X64_MSR_SIMP, simp.as_uint64);
simp.simp_enabled = 0;
simp.base_simp_gpa = 0;
wrmsrl(HV_X64_MSR_SIMP, simp.as_uint64);
rdmsrl(HV_X64_MSR_SIEFP, siefp.as_uint64);
siefp.siefp_enabled = 0;
siefp.base_siefp_gpa = 0;
wrmsrl(HV_X64_MSR_SIEFP, siefp.as_uint64);
rdmsrl(HV_X64_MSR_SCONTROL, sctrl.as_uint64);
sctrl.enable = 0;
wrmsrl(HV_X64_MSR_SCONTROL, sctrl.as_uint64);
}
