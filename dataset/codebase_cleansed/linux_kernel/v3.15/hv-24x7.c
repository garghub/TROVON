static ssize_t read_offset_data(void *dest, size_t dest_len,
loff_t requested_offset, void *src,
size_t src_len, loff_t source_offset)
{
size_t w_offset_in_s = requested_offset - source_offset;
size_t z_offset_in_s = src_len;
size_t v_offset_in_s = requested_offset + dest_len - src_len;
size_t u_offset_in_s = min(z_offset_in_s, v_offset_in_s);
size_t copy_len = u_offset_in_s - w_offset_in_s;
if (requested_offset < 0 || source_offset < 0)
return -EINVAL;
if (z_offset_in_s <= w_offset_in_s)
return 0;
memcpy(dest, src + w_offset_in_s, copy_len);
return copy_len;
}
static unsigned long h_get_24x7_catalog_page_(unsigned long phys_4096,
unsigned long version,
unsigned long index)
{
pr_devel("h_get_24x7_catalog_page(0x%lx, %lu, %lu)",
phys_4096,
version,
index);
WARN_ON(!IS_ALIGNED(phys_4096, 4096));
return plpar_hcall_norets(H_GET_24X7_CATALOG_PAGE,
phys_4096,
version,
index);
}
static unsigned long h_get_24x7_catalog_page(char page[],
u64 version, u32 index)
{
return h_get_24x7_catalog_page_(virt_to_phys(page),
version, index);
}
static ssize_t catalog_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t offset, size_t count)
{
unsigned long hret;
ssize_t ret = 0;
size_t catalog_len = 0, catalog_page_len = 0, page_count = 0;
loff_t page_offset = 0;
uint64_t catalog_version_num = 0;
void *page = kmem_cache_alloc(hv_page_cache, GFP_USER);
struct hv_24x7_catalog_page_0 *page_0 = page;
if (!page)
return -ENOMEM;
hret = h_get_24x7_catalog_page(page, 0, 0);
if (hret) {
ret = -EIO;
goto e_free;
}
catalog_version_num = be64_to_cpu(page_0->version);
catalog_page_len = be32_to_cpu(page_0->length);
catalog_len = catalog_page_len * 4096;
page_offset = offset / 4096;
page_count = count / 4096;
if (page_offset >= catalog_page_len)
goto e_free;
if (page_offset != 0) {
hret = h_get_24x7_catalog_page(page, catalog_version_num,
page_offset);
if (hret) {
ret = -EIO;
goto e_free;
}
}
ret = read_offset_data(buf, count, offset,
page, 4096, page_offset * 4096);
e_free:
if (hret)
pr_err("h_get_24x7_catalog_page(ver=%lld, page=%lld) failed:"
" rc=%ld\n",
catalog_version_num, page_offset, hret);
kfree(page);
pr_devel("catalog_read: offset=%lld(%lld) count=%zu(%zu) catalog_len=%zu(%zu) => %zd\n",
offset, page_offset, count, page_count, catalog_len,
catalog_page_len, ret);
return ret;
}
static bool is_physical_domain(int domain)
{
return domain == HV_24X7_PERF_DOMAIN_PHYSICAL_CHIP ||
domain == HV_24X7_PERF_DOMAIN_PHYSICAL_CORE;
}
static unsigned long single_24x7_request(u8 domain, u32 offset, u16 ix,
u16 lpar, u64 *res,
bool success_expected)
{
unsigned long ret;
struct reqb {
struct hv_24x7_request_buffer buf;
struct hv_24x7_request req;
} __packed __aligned(4096) request_buffer = {
.buf = {
.interface_version = HV_24X7_IF_VERSION_CURRENT,
.num_requests = 1,
},
.req = {
.performance_domain = domain,
.data_size = cpu_to_be16(8),
.data_offset = cpu_to_be32(offset),
.starting_lpar_ix = cpu_to_be16(lpar),
.max_num_lpars = cpu_to_be16(1),
.starting_ix = cpu_to_be16(ix),
.max_ix = cpu_to_be16(1),
}
};
struct resb {
struct hv_24x7_data_result_buffer buf;
struct hv_24x7_result res;
struct hv_24x7_result_element elem;
__be64 result;
} __packed __aligned(4096) result_buffer = {};
ret = plpar_hcall_norets(H_GET_24X7_DATA,
virt_to_phys(&request_buffer), sizeof(request_buffer),
virt_to_phys(&result_buffer), sizeof(result_buffer));
if (ret) {
if (success_expected)
pr_err_ratelimited("hcall failed: %d %#x %#x %d => 0x%lx (%ld) detail=0x%x failing ix=%x\n",
domain, offset, ix, lpar,
ret, ret,
result_buffer.buf.detailed_rc,
result_buffer.buf.failing_request_ix);
return ret;
}
*res = be64_to_cpu(result_buffer.result);
return ret;
}
static unsigned long event_24x7_request(struct perf_event *event, u64 *res,
bool success_expected)
{
return single_24x7_request(event_get_domain(event),
event_get_offset(event),
event_get_starting_index(event),
event_get_lpar(event),
res,
success_expected);
}
static int h_24x7_event_init(struct perf_event *event)
{
struct hv_perf_caps caps;
unsigned domain;
unsigned long hret;
u64 ct;
if (event->attr.type != event->pmu->type)
return -ENOENT;
if (event_get_reserved1(event) ||
event_get_reserved2(event) ||
event_get_reserved3(event)) {
pr_devel("reserved set when forbidden 0x%llx(0x%llx) 0x%llx(0x%llx) 0x%llx(0x%llx)\n",
event->attr.config,
event_get_reserved1(event),
event->attr.config1,
event_get_reserved2(event),
event->attr.config2,
event_get_reserved3(event));
return -EINVAL;
}
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest ||
is_sampling_event(event))
return -EINVAL;
if (has_branch_stack(event))
return -EOPNOTSUPP;
if (event_get_offset(event) % 8) {
pr_devel("bad alignment\n");
return -EINVAL;
}
domain = event_get_domain(event);
if (domain > 6) {
pr_devel("invalid domain %d\n", domain);
return -EINVAL;
}
hret = hv_perf_caps_get(&caps);
if (hret) {
pr_devel("could not get capabilities: rc=%ld\n", hret);
return -EIO;
}
if (!caps.collect_privileged && (is_physical_domain(domain) ||
(event_get_lpar(event) != event_get_lpar_max()))) {
pr_devel("hv permisions disallow: is_physical_domain:%d, lpar=0x%llx\n",
is_physical_domain(domain),
event_get_lpar(event));
return -EACCES;
}
if (event_24x7_request(event, &ct, false)) {
pr_devel("test hcall failed\n");
return -EIO;
}
return 0;
}
static u64 h_24x7_get_value(struct perf_event *event)
{
unsigned long ret;
u64 ct;
ret = event_24x7_request(event, &ct, true);
if (ret)
return 0;
return ct;
}
static void h_24x7_event_update(struct perf_event *event)
{
s64 prev;
u64 now;
now = h_24x7_get_value(event);
prev = local64_xchg(&event->hw.prev_count, now);
local64_add(now - prev, &event->count);
}
static void h_24x7_event_start(struct perf_event *event, int flags)
{
if (flags & PERF_EF_RELOAD)
local64_set(&event->hw.prev_count, h_24x7_get_value(event));
}
static void h_24x7_event_stop(struct perf_event *event, int flags)
{
h_24x7_event_update(event);
}
static int h_24x7_event_add(struct perf_event *event, int flags)
{
if (flags & PERF_EF_START)
h_24x7_event_start(event, flags);
return 0;
}
static int h_24x7_event_idx(struct perf_event *event)
{
return 0;
}
static int hv_24x7_init(void)
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
hv_page_cache = kmem_cache_create("hv-page-4096", 4096, 4096, 0, NULL);
if (!hv_page_cache)
return -ENOMEM;
r = perf_pmu_register(&h_24x7_pmu, h_24x7_pmu.name, -1);
if (r)
return r;
return 0;
}
