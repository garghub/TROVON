int hv_init(void)
{
if (!hv_is_hypercall_page_setup())
return -ENOTSUPP;
hv_context.cpu_context = alloc_percpu(struct hv_per_cpu_context);
if (!hv_context.cpu_context)
return -ENOMEM;
return 0;
}
int hv_post_message(union hv_connection_id connection_id,
enum hv_message_type message_type,
void *payload, size_t payload_size)
{
struct hv_input_post_message *aligned_msg;
struct hv_per_cpu_context *hv_cpu;
u64 status;
if (payload_size > HV_MESSAGE_PAYLOAD_BYTE_COUNT)
return -EMSGSIZE;
hv_cpu = get_cpu_ptr(hv_context.cpu_context);
aligned_msg = hv_cpu->post_msg_page;
aligned_msg->connectionid = connection_id;
aligned_msg->reserved = 0;
aligned_msg->message_type = message_type;
aligned_msg->payload_size = payload_size;
memcpy((void *)aligned_msg->payload, payload, payload_size);
put_cpu_ptr(hv_cpu);
status = hv_do_hypercall(HVCALL_POST_MESSAGE, aligned_msg, NULL);
return status & 0xFFFF;
}
static int hv_ce_set_next_event(unsigned long delta,
struct clock_event_device *evt)
{
u64 current_tick;
WARN_ON(!clockevent_state_oneshot(evt));
hv_get_current_tick(current_tick);
current_tick += delta;
hv_init_timer(HV_X64_MSR_STIMER0_COUNT, current_tick);
return 0;
}
static int hv_ce_shutdown(struct clock_event_device *evt)
{
hv_init_timer(HV_X64_MSR_STIMER0_COUNT, 0);
hv_init_timer_config(HV_X64_MSR_STIMER0_CONFIG, 0);
return 0;
}
static int hv_ce_set_oneshot(struct clock_event_device *evt)
{
union hv_timer_config timer_cfg;
timer_cfg.enable = 1;
timer_cfg.auto_enable = 1;
timer_cfg.sintx = VMBUS_MESSAGE_SINT;
hv_init_timer_config(HV_X64_MSR_STIMER0_CONFIG, timer_cfg.as_uint64);
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
int cpu;
hv_context.hv_numa_map = kzalloc(sizeof(struct cpumask) * nr_node_ids,
GFP_ATOMIC);
if (hv_context.hv_numa_map == NULL) {
pr_err("Unable to allocate NUMA map\n");
goto err;
}
for_each_present_cpu(cpu) {
struct hv_per_cpu_context *hv_cpu
= per_cpu_ptr(hv_context.cpu_context, cpu);
memset(hv_cpu, 0, sizeof(*hv_cpu));
tasklet_init(&hv_cpu->msg_dpc,
vmbus_on_msg_dpc, (unsigned long) hv_cpu);
hv_cpu->clk_evt = kzalloc(sizeof(struct clock_event_device),
GFP_KERNEL);
if (hv_cpu->clk_evt == NULL) {
pr_err("Unable to allocate clock event device\n");
goto err;
}
hv_init_clockevent_device(hv_cpu->clk_evt, cpu);
hv_cpu->synic_message_page =
(void *)get_zeroed_page(GFP_ATOMIC);
if (hv_cpu->synic_message_page == NULL) {
pr_err("Unable to allocate SYNIC message page\n");
goto err;
}
hv_cpu->synic_event_page = (void *)get_zeroed_page(GFP_ATOMIC);
if (hv_cpu->synic_event_page == NULL) {
pr_err("Unable to allocate SYNIC event page\n");
goto err;
}
hv_cpu->post_msg_page = (void *)get_zeroed_page(GFP_ATOMIC);
if (hv_cpu->post_msg_page == NULL) {
pr_err("Unable to allocate post msg page\n");
goto err;
}
INIT_LIST_HEAD(&hv_cpu->chan_list);
}
return 0;
err:
return -ENOMEM;
}
void hv_synic_free(void)
{
int cpu;
for_each_present_cpu(cpu) {
struct hv_per_cpu_context *hv_cpu
= per_cpu_ptr(hv_context.cpu_context, cpu);
if (hv_cpu->synic_event_page)
free_page((unsigned long)hv_cpu->synic_event_page);
if (hv_cpu->synic_message_page)
free_page((unsigned long)hv_cpu->synic_message_page);
if (hv_cpu->post_msg_page)
free_page((unsigned long)hv_cpu->post_msg_page);
}
kfree(hv_context.hv_numa_map);
}
int hv_synic_init(unsigned int cpu)
{
struct hv_per_cpu_context *hv_cpu
= per_cpu_ptr(hv_context.cpu_context, cpu);
union hv_synic_simp simp;
union hv_synic_siefp siefp;
union hv_synic_sint shared_sint;
union hv_synic_scontrol sctrl;
u64 vp_index;
hv_get_simp(simp.as_uint64);
simp.simp_enabled = 1;
simp.base_simp_gpa = virt_to_phys(hv_cpu->synic_message_page)
>> PAGE_SHIFT;
hv_set_simp(simp.as_uint64);
hv_get_siefp(siefp.as_uint64);
siefp.siefp_enabled = 1;
siefp.base_siefp_gpa = virt_to_phys(hv_cpu->synic_event_page)
>> PAGE_SHIFT;
hv_set_siefp(siefp.as_uint64);
hv_get_synint_state(HV_X64_MSR_SINT0 + VMBUS_MESSAGE_SINT,
shared_sint.as_uint64);
shared_sint.as_uint64 = 0;
shared_sint.vector = HYPERVISOR_CALLBACK_VECTOR;
shared_sint.masked = false;
if (ms_hyperv.hints & HV_X64_DEPRECATING_AEOI_RECOMMENDED)
shared_sint.auto_eoi = false;
else
shared_sint.auto_eoi = true;
hv_set_synint_state(HV_X64_MSR_SINT0 + VMBUS_MESSAGE_SINT,
shared_sint.as_uint64);
hv_get_synic_state(sctrl.as_uint64);
sctrl.enable = 1;
hv_set_synic_state(sctrl.as_uint64);
hv_context.synic_initialized = true;
hv_get_vp_index(vp_index);
hv_context.vp_index[cpu] = (u32)vp_index;
if (ms_hyperv.features & HV_X64_MSR_SYNTIMER_AVAILABLE)
clockevents_config_and_register(hv_cpu->clk_evt,
HV_TIMER_FREQUENCY,
HV_MIN_DELTA_TICKS,
HV_MAX_MAX_DELTA_TICKS);
return 0;
}
void hv_synic_clockevents_cleanup(void)
{
int cpu;
if (!(ms_hyperv.features & HV_X64_MSR_SYNTIMER_AVAILABLE))
return;
for_each_present_cpu(cpu) {
struct hv_per_cpu_context *hv_cpu
= per_cpu_ptr(hv_context.cpu_context, cpu);
clockevents_unbind_device(hv_cpu->clk_evt, cpu);
}
}
int hv_synic_cleanup(unsigned int cpu)
{
union hv_synic_sint shared_sint;
union hv_synic_simp simp;
union hv_synic_siefp siefp;
union hv_synic_scontrol sctrl;
struct vmbus_channel *channel, *sc;
bool channel_found = false;
unsigned long flags;
if (!hv_context.synic_initialized)
return -EFAULT;
mutex_lock(&vmbus_connection.channel_mutex);
list_for_each_entry(channel, &vmbus_connection.chn_list, listentry) {
if (channel->target_cpu == cpu) {
channel_found = true;
break;
}
spin_lock_irqsave(&channel->lock, flags);
list_for_each_entry(sc, &channel->sc_list, sc_list) {
if (sc->target_cpu == cpu) {
channel_found = true;
break;
}
}
spin_unlock_irqrestore(&channel->lock, flags);
if (channel_found)
break;
}
mutex_unlock(&vmbus_connection.channel_mutex);
if (channel_found && vmbus_connection.conn_state == CONNECTED)
return -EBUSY;
if (ms_hyperv.features & HV_X64_MSR_SYNTIMER_AVAILABLE) {
struct hv_per_cpu_context *hv_cpu
= this_cpu_ptr(hv_context.cpu_context);
clockevents_unbind_device(hv_cpu->clk_evt, cpu);
hv_ce_shutdown(hv_cpu->clk_evt);
put_cpu_ptr(hv_cpu);
}
hv_get_synint_state(HV_X64_MSR_SINT0 + VMBUS_MESSAGE_SINT,
shared_sint.as_uint64);
shared_sint.masked = 1;
hv_set_synint_state(HV_X64_MSR_SINT0 + VMBUS_MESSAGE_SINT,
shared_sint.as_uint64);
hv_get_simp(simp.as_uint64);
simp.simp_enabled = 0;
simp.base_simp_gpa = 0;
hv_set_simp(simp.as_uint64);
hv_get_siefp(siefp.as_uint64);
siefp.siefp_enabled = 0;
siefp.base_siefp_gpa = 0;
hv_set_siefp(siefp.as_uint64);
hv_get_synic_state(sctrl.as_uint64);
sctrl.enable = 0;
hv_set_synic_state(sctrl.as_uint64);
return 0;
}
