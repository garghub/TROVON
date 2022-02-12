static void uv_rtc_send_IPI(int cpu)
{
unsigned long apicid, val;
int pnode;
apicid = cpu_physical_id(cpu);
pnode = uv_apicid_to_pnode(apicid);
apicid |= uv_apicid_hibits;
val = (1UL << UVH_IPI_INT_SEND_SHFT) |
(apicid << UVH_IPI_INT_APIC_ID_SHFT) |
(X86_PLATFORM_IPI_VECTOR << UVH_IPI_INT_VECTOR_SHFT);
uv_write_global_mmr64(pnode, UVH_IPI_INT, val);
}
static int uv_intr_pending(int pnode)
{
if (is_uv1_hub())
return uv_read_global_mmr64(pnode, UVH_EVENT_OCCURRED0) &
UV1H_EVENT_OCCURRED0_RTC1_MASK;
else if (is_uvx_hub())
return uv_read_global_mmr64(pnode, UVXH_EVENT_OCCURRED2) &
UVXH_EVENT_OCCURRED2_RTC_1_MASK;
return 0;
}
static int uv_setup_intr(int cpu, u64 expires)
{
u64 val;
unsigned long apicid = cpu_physical_id(cpu) | uv_apicid_hibits;
int pnode = uv_cpu_to_pnode(cpu);
uv_write_global_mmr64(pnode, UVH_RTC1_INT_CONFIG,
UVH_RTC1_INT_CONFIG_M_MASK);
uv_write_global_mmr64(pnode, UVH_INT_CMPB, -1L);
if (is_uv1_hub())
uv_write_global_mmr64(pnode, UVH_EVENT_OCCURRED0_ALIAS,
UV1H_EVENT_OCCURRED0_RTC1_MASK);
else
uv_write_global_mmr64(pnode, UVXH_EVENT_OCCURRED2_ALIAS,
UVXH_EVENT_OCCURRED2_RTC_1_MASK);
val = (X86_PLATFORM_IPI_VECTOR << UVH_RTC1_INT_CONFIG_VECTOR_SHFT) |
((u64)apicid << UVH_RTC1_INT_CONFIG_APIC_ID_SHFT);
uv_write_global_mmr64(pnode, UVH_RTC1_INT_CONFIG, val);
uv_write_global_mmr64(pnode, UVH_INT_CMPB, expires);
if (uv_read_rtc(NULL) <= expires)
return 0;
return !uv_intr_pending(pnode);
}
static __init void uv_rtc_deallocate_timers(void)
{
int bid;
for_each_possible_blade(bid) {
kfree(blade_info[bid]);
}
kfree(blade_info);
}
static __init int uv_rtc_allocate_timers(void)
{
int cpu;
blade_info = kzalloc(uv_possible_blades * sizeof(void *), GFP_KERNEL);
if (!blade_info)
return -ENOMEM;
for_each_present_cpu(cpu) {
int nid = cpu_to_node(cpu);
int bid = uv_cpu_to_blade_id(cpu);
int bcpu = uv_cpu_blade_processor_id(cpu);
struct uv_rtc_timer_head *head = blade_info[bid];
if (!head) {
head = kmalloc_node(sizeof(struct uv_rtc_timer_head) +
(uv_blade_nr_possible_cpus(bid) *
2 * sizeof(u64)),
GFP_KERNEL, nid);
if (!head) {
uv_rtc_deallocate_timers();
return -ENOMEM;
}
spin_lock_init(&head->lock);
head->ncpus = uv_blade_nr_possible_cpus(bid);
head->next_cpu = -1;
blade_info[bid] = head;
}
head->cpu[bcpu].lcpu = cpu;
head->cpu[bcpu].expires = ULLONG_MAX;
}
return 0;
}
static void uv_rtc_find_next_timer(struct uv_rtc_timer_head *head, int pnode)
{
u64 lowest = ULLONG_MAX;
int c, bcpu = -1;
head->next_cpu = -1;
for (c = 0; c < head->ncpus; c++) {
u64 exp = head->cpu[c].expires;
if (exp < lowest) {
bcpu = c;
lowest = exp;
}
}
if (bcpu >= 0) {
head->next_cpu = bcpu;
c = head->cpu[bcpu].lcpu;
if (uv_setup_intr(c, lowest))
uv_rtc_send_IPI(c);
} else {
uv_write_global_mmr64(pnode, UVH_RTC1_INT_CONFIG,
UVH_RTC1_INT_CONFIG_M_MASK);
}
}
static int uv_rtc_set_timer(int cpu, u64 expires)
{
int pnode = uv_cpu_to_pnode(cpu);
int bid = uv_cpu_to_blade_id(cpu);
struct uv_rtc_timer_head *head = blade_info[bid];
int bcpu = uv_cpu_blade_processor_id(cpu);
u64 *t = &head->cpu[bcpu].expires;
unsigned long flags;
int next_cpu;
spin_lock_irqsave(&head->lock, flags);
next_cpu = head->next_cpu;
*t = expires;
if (next_cpu < 0 || bcpu == next_cpu ||
expires < head->cpu[next_cpu].expires) {
head->next_cpu = bcpu;
if (uv_setup_intr(cpu, expires)) {
*t = ULLONG_MAX;
uv_rtc_find_next_timer(head, pnode);
spin_unlock_irqrestore(&head->lock, flags);
return -ETIME;
}
}
spin_unlock_irqrestore(&head->lock, flags);
return 0;
}
static int uv_rtc_unset_timer(int cpu, int force)
{
int pnode = uv_cpu_to_pnode(cpu);
int bid = uv_cpu_to_blade_id(cpu);
struct uv_rtc_timer_head *head = blade_info[bid];
int bcpu = uv_cpu_blade_processor_id(cpu);
u64 *t = &head->cpu[bcpu].expires;
unsigned long flags;
int rc = 0;
spin_lock_irqsave(&head->lock, flags);
if ((head->next_cpu == bcpu && uv_read_rtc(NULL) >= *t) || force)
rc = 1;
if (rc) {
*t = ULLONG_MAX;
if (head->next_cpu == bcpu)
uv_rtc_find_next_timer(head, pnode);
}
spin_unlock_irqrestore(&head->lock, flags);
return rc;
}
static cycle_t uv_read_rtc(struct clocksource *cs)
{
unsigned long offset;
if (uv_get_min_hub_revision_id() == 1)
offset = 0;
else
offset = (uv_blade_processor_id() * L1_CACHE_BYTES) % PAGE_SIZE;
return (cycle_t)uv_read_local_mmr(UVH_RTC | offset);
}
static int uv_rtc_next_event(unsigned long delta,
struct clock_event_device *ced)
{
int ced_cpu = cpumask_first(ced->cpumask);
return uv_rtc_set_timer(ced_cpu, delta + uv_read_rtc(NULL));
}
static int uv_rtc_shutdown(struct clock_event_device *evt)
{
int ced_cpu = cpumask_first(evt->cpumask);
uv_rtc_unset_timer(ced_cpu, 1);
return 0;
}
static void uv_rtc_interrupt(void)
{
int cpu = smp_processor_id();
struct clock_event_device *ced = &per_cpu(cpu_ced, cpu);
if (!ced || !ced->event_handler)
return;
if (uv_rtc_unset_timer(cpu, 0) != 1)
return;
ced->event_handler(ced);
}
static int __init uv_enable_evt_rtc(char *str)
{
uv_rtc_evt_enable = 1;
return 1;
}
static __init void uv_rtc_register_clockevents(struct work_struct *dummy)
{
struct clock_event_device *ced = this_cpu_ptr(&cpu_ced);
*ced = clock_event_device_uv;
ced->cpumask = cpumask_of(smp_processor_id());
clockevents_register_device(ced);
}
static __init int uv_rtc_setup_clock(void)
{
int rc;
if (!is_uv_system())
return -ENODEV;
rc = clocksource_register_hz(&clocksource_uv, sn_rtc_cycles_per_second);
if (rc)
printk(KERN_INFO "UV RTC clocksource failed rc %d\n", rc);
else
printk(KERN_INFO "UV RTC clocksource registered freq %lu MHz\n",
sn_rtc_cycles_per_second/(unsigned long)1E6);
if (rc || !uv_rtc_evt_enable || x86_platform_ipi_callback)
return rc;
rc = uv_rtc_allocate_timers();
if (rc)
goto error;
x86_platform_ipi_callback = uv_rtc_interrupt;
clock_event_device_uv.mult = div_sc(sn_rtc_cycles_per_second,
NSEC_PER_SEC, clock_event_device_uv.shift);
clock_event_device_uv.min_delta_ns = NSEC_PER_SEC /
sn_rtc_cycles_per_second;
clock_event_device_uv.max_delta_ns = clocksource_uv.mask *
(NSEC_PER_SEC / sn_rtc_cycles_per_second);
rc = schedule_on_each_cpu(uv_rtc_register_clockevents);
if (rc) {
x86_platform_ipi_callback = NULL;
uv_rtc_deallocate_timers();
goto error;
}
printk(KERN_INFO "UV RTC clockevents registered\n");
return 0;
error:
clocksource_unregister(&clocksource_uv);
printk(KERN_INFO "UV RTC clockevents failed rc %d\n", rc);
return rc;
}
