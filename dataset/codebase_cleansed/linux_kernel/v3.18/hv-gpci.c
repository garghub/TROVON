static ssize_t kernel_version_show(struct device *dev,
struct device_attribute *attr,
char *page)
{
return sprintf(page, "0x%x\n", COUNTER_INFO_VERSION_CURRENT);
}
static unsigned long single_gpci_request(u32 req, u32 starting_index,
u16 secondary_index, u8 version_in, u32 offset, u8 length,
u64 *value)
{
unsigned long ret;
size_t i;
u64 count;
struct {
struct hv_get_perf_counter_info_params params;
uint8_t bytes[GPCI_MAX_DATA_BYTES];
} __packed __aligned(sizeof(uint64_t)) arg = {
.params = {
.counter_request = cpu_to_be32(req),
.starting_index = cpu_to_be32(starting_index),
.secondary_index = cpu_to_be16(secondary_index),
.counter_info_version_in = version_in,
}
};
ret = plpar_hcall_norets(H_GET_PERF_COUNTER_INFO,
virt_to_phys(&arg), sizeof(arg));
if (ret) {
pr_devel("hcall failed: 0x%lx\n", ret);
return ret;
}
count = 0;
for (i = offset; i < offset + length; i++)
count |= arg.bytes[i] << (i - offset);
*value = count;
return ret;
}
static u64 h_gpci_get_value(struct perf_event *event)
{
u64 count;
unsigned long ret = single_gpci_request(event_get_request(event),
event_get_starting_index(event),
event_get_secondary_index(event),
event_get_counter_info_version(event),
event_get_offset(event),
event_get_length(event),
&count);
if (ret)
return 0;
return count;
}
static void h_gpci_event_update(struct perf_event *event)
{
s64 prev;
u64 now = h_gpci_get_value(event);
prev = local64_xchg(&event->hw.prev_count, now);
local64_add(now - prev, &event->count);
}
static void h_gpci_event_start(struct perf_event *event, int flags)
{
local64_set(&event->hw.prev_count, h_gpci_get_value(event));
}
static void h_gpci_event_stop(struct perf_event *event, int flags)
{
h_gpci_event_update(event);
}
static int h_gpci_event_add(struct perf_event *event, int flags)
{
if (flags & PERF_EF_START)
h_gpci_event_start(event, flags);
return 0;
}
static int h_gpci_event_init(struct perf_event *event)
{
u64 count;
u8 length;
if (event->attr.type != event->pmu->type)
return -ENOENT;
if (event->attr.config2) {
pr_devel("config2 set when reserved\n");
return -EINVAL;
}
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest)
return -EINVAL;
if (has_branch_stack(event))
return -EOPNOTSUPP;
length = event_get_length(event);
if (length < 1 || length > 8) {
pr_devel("length invalid\n");
return -EINVAL;
}
if ((event_get_offset(event) + length) > GPCI_MAX_DATA_BYTES) {
pr_devel("request outside of buffer: %zu > %zu\n",
(size_t)event_get_offset(event) + length,
GPCI_MAX_DATA_BYTES);
return -EINVAL;
}
if (single_gpci_request(event_get_request(event),
event_get_starting_index(event),
event_get_secondary_index(event),
event_get_counter_info_version(event),
event_get_offset(event),
length,
&count)) {
pr_devel("gpci hcall failed\n");
return -EINVAL;
}
return 0;
}
static int hv_gpci_init(void)
{
int r;
unsigned long hret;
struct hv_perf_caps caps;
if (!firmware_has_feature(FW_FEATURE_LPAR)) {
pr_debug("not a virtualized system, not enabling\n");
return -ENODEV;
}
hret = hv_perf_caps_get(&caps);
if (hret) {
pr_debug("could not obtain capabilities, not enabling, rc=%ld\n",
hret);
return -ENODEV;
}
h_gpci_pmu.capabilities |= PERF_PMU_CAP_NO_INTERRUPT;
r = perf_pmu_register(&h_gpci_pmu, h_gpci_pmu.name, -1);
if (r)
return r;
return 0;
}
