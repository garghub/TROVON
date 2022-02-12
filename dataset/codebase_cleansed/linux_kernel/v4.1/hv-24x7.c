static const char *event_domain_suffix(unsigned domain)
{
switch (domain) {
#define DOMAIN(n, v, x, c) \
case HV_PERF_DOMAIN_##n: \
return "__" #n;
#include "hv-24x7-domains.h"
#undef DOMAIN
default:
WARN(1, "unknown domain %d\n", domain);
return "__UNKNOWN_DOMAIN_SUFFIX";
}
}
static bool domain_is_valid(unsigned domain)
{
switch (domain) {
#define DOMAIN(n, v, x, c) \
case HV_PERF_DOMAIN_##n: \
#include "hv-24x7-domains.h"
#undef DOMAIN
return true;
default:
return false;
}
}
static bool is_physical_domain(unsigned domain)
{
switch (domain) {
#define DOMAIN(n, v, x, c) \
case HV_PERF_DOMAIN_##n: \
return c;
#include "hv-24x7-domains.h"
#undef DOMAIN
default:
return false;
}
}
static bool catalog_entry_domain_is_valid(unsigned domain)
{
return is_physical_domain(domain);
}
static char *event_name(struct hv_24x7_event_data *ev, int *len)
{
*len = be16_to_cpu(ev->event_name_len) - 2;
return (char *)ev->remainder;
}
static char *event_desc(struct hv_24x7_event_data *ev, int *len)
{
unsigned nl = be16_to_cpu(ev->event_name_len);
__be16 *desc_len = (__be16 *)(ev->remainder + nl - 2);
*len = be16_to_cpu(*desc_len) - 2;
return (char *)ev->remainder + nl;
}
static char *event_long_desc(struct hv_24x7_event_data *ev, int *len)
{
unsigned nl = be16_to_cpu(ev->event_name_len);
__be16 *desc_len_ = (__be16 *)(ev->remainder + nl - 2);
unsigned desc_len = be16_to_cpu(*desc_len_);
__be16 *long_desc_len = (__be16 *)(ev->remainder + nl + desc_len - 2);
*len = be16_to_cpu(*long_desc_len) - 2;
return (char *)ev->remainder + nl + desc_len;
}
static bool event_fixed_portion_is_within(struct hv_24x7_event_data *ev,
void *end)
{
void *start = ev;
return (start + offsetof(struct hv_24x7_event_data, remainder)) < end;
}
static void *event_end(struct hv_24x7_event_data *ev, void *end)
{
void *start = ev;
__be16 *dl_, *ldl_;
unsigned dl, ldl;
unsigned nl = be16_to_cpu(ev->event_name_len);
if (nl < 2) {
pr_debug("%s: name length too short: %d", __func__, nl);
return NULL;
}
if (start + nl > end) {
pr_debug("%s: start=%p + nl=%u > end=%p",
__func__, start, nl, end);
return NULL;
}
dl_ = (__be16 *)(ev->remainder + nl - 2);
if (!IS_ALIGNED((uintptr_t)dl_, 2))
pr_warn("desc len not aligned %p", dl_);
dl = be16_to_cpu(*dl_);
if (dl < 2) {
pr_debug("%s: desc len too short: %d", __func__, dl);
return NULL;
}
if (start + nl + dl > end) {
pr_debug("%s: (start=%p + nl=%u + dl=%u)=%p > end=%p",
__func__, start, nl, dl, start + nl + dl, end);
return NULL;
}
ldl_ = (__be16 *)(ev->remainder + nl + dl - 2);
if (!IS_ALIGNED((uintptr_t)ldl_, 2))
pr_warn("long desc len not aligned %p", ldl_);
ldl = be16_to_cpu(*ldl_);
if (ldl < 2) {
pr_debug("%s: long desc len too short (ldl=%u)",
__func__, ldl);
return NULL;
}
if (start + nl + dl + ldl > end) {
pr_debug("%s: start=%p + nl=%u + dl=%u + ldl=%u > end=%p",
__func__, start, nl, dl, ldl, end);
return NULL;
}
return start + nl + dl + ldl;
}
static unsigned long h_get_24x7_catalog_page_(unsigned long phys_4096,
unsigned long version,
unsigned long index)
{
pr_devel("h_get_24x7_catalog_page(0x%lx, %lu, %lu)",
phys_4096, version, index);
WARN_ON(!IS_ALIGNED(phys_4096, 4096));
return plpar_hcall_norets(H_GET_24X7_CATALOG_PAGE,
phys_4096, version, index);
}
static unsigned long h_get_24x7_catalog_page(char page[],
u64 version, u32 index)
{
return h_get_24x7_catalog_page_(virt_to_phys(page),
version, index);
}
static char *event_fmt(struct hv_24x7_event_data *event, unsigned domain)
{
const char *sindex;
const char *lpar;
if (is_physical_domain(domain)) {
lpar = "0x0";
sindex = "core";
} else {
lpar = "?";
sindex = "vcpu";
}
return kasprintf(GFP_KERNEL,
"domain=0x%x,offset=0x%x,%s=?,lpar=%s",
domain,
be16_to_cpu(event->event_counter_offs) +
be16_to_cpu(event->event_group_record_offs),
sindex,
lpar);
}
static char *memdup_to_str(char *maybe_str, int max_len, gfp_t gfp)
{
return kasprintf(gfp, "%.*s", max_len, maybe_str);
}
static ssize_t device_show_string(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dev_ext_attribute *d;
d = container_of(attr, struct dev_ext_attribute, attr);
return sprintf(buf, "%s\n", (char *)d->var);
}
static struct attribute *device_str_attr_create_(char *name, char *str)
{
struct dev_ext_attribute *attr = kzalloc(sizeof(*attr), GFP_KERNEL);
if (!attr)
return NULL;
attr->var = str;
attr->attr.attr.name = name;
attr->attr.attr.mode = 0444;
attr->attr.show = device_show_string;
return &attr->attr.attr;
}
static struct attribute *device_str_attr_create(char *name, int name_max,
int name_nonce,
char *str, size_t str_max)
{
char *n;
char *s = memdup_to_str(str, str_max, GFP_KERNEL);
struct attribute *a;
if (!s)
return NULL;
if (!name_nonce)
n = kasprintf(GFP_KERNEL, "%.*s", name_max, name);
else
n = kasprintf(GFP_KERNEL, "%.*s__%d", name_max, name,
name_nonce);
if (!n)
goto out_s;
a = device_str_attr_create_(n, s);
if (!a)
goto out_n;
return a;
out_n:
kfree(n);
out_s:
kfree(s);
return NULL;
}
static void device_str_attr_destroy(struct attribute *attr)
{
struct dev_ext_attribute *d;
d = container_of(attr, struct dev_ext_attribute, attr.attr);
kfree(d->var);
kfree(d->attr.attr.name);
kfree(d);
}
static struct attribute *event_to_attr(unsigned ix,
struct hv_24x7_event_data *event,
unsigned domain,
int nonce)
{
int event_name_len;
char *ev_name, *a_ev_name, *val;
const char *ev_suffix;
struct attribute *attr;
if (!domain_is_valid(domain)) {
pr_warn("catalog event %u has invalid domain %u\n",
ix, domain);
return NULL;
}
val = event_fmt(event, domain);
if (!val)
return NULL;
ev_suffix = event_domain_suffix(domain);
ev_name = event_name(event, &event_name_len);
if (!nonce)
a_ev_name = kasprintf(GFP_KERNEL, "%.*s%s",
(int)event_name_len, ev_name, ev_suffix);
else
a_ev_name = kasprintf(GFP_KERNEL, "%.*s%s__%d",
(int)event_name_len, ev_name, ev_suffix, nonce);
if (!a_ev_name)
goto out_val;
attr = device_str_attr_create_(a_ev_name, val);
if (!attr)
goto out_name;
return attr;
out_name:
kfree(a_ev_name);
out_val:
kfree(val);
return NULL;
}
static struct attribute *event_to_desc_attr(struct hv_24x7_event_data *event,
int nonce)
{
int nl, dl;
char *name = event_name(event, &nl);
char *desc = event_desc(event, &dl);
if (!dl)
return NULL;
return device_str_attr_create(name, nl, nonce, desc, dl);
}
static struct attribute *
event_to_long_desc_attr(struct hv_24x7_event_data *event, int nonce)
{
int nl, dl;
char *name = event_name(event, &nl);
char *desc = event_long_desc(event, &dl);
if (!dl)
return NULL;
return device_str_attr_create(name, nl, nonce, desc, dl);
}
static ssize_t event_data_to_attrs(unsigned ix, struct attribute **attrs,
struct hv_24x7_event_data *event, int nonce)
{
unsigned i;
switch (event->domain) {
case HV_PERF_DOMAIN_PHYS_CHIP:
*attrs = event_to_attr(ix, event, event->domain, nonce);
return 1;
case HV_PERF_DOMAIN_PHYS_CORE:
for (i = 0; i < ARRAY_SIZE(core_domains); i++) {
attrs[i] = event_to_attr(ix, event, core_domains[i],
nonce);
if (!attrs[i]) {
pr_warn("catalog event %u: individual attr %u "
"creation failure\n", ix, i);
for (; i; i--)
device_str_attr_destroy(attrs[i - 1]);
return -1;
}
}
return i;
default:
pr_warn("catalog event %u: domain %u is not allowed in the "
"catalog\n", ix, event->domain);
return -1;
}
}
static size_t event_to_attr_ct(struct hv_24x7_event_data *event)
{
switch (event->domain) {
case HV_PERF_DOMAIN_PHYS_CHIP:
return 1;
case HV_PERF_DOMAIN_PHYS_CORE:
return ARRAY_SIZE(core_domains);
default:
return 0;
}
}
static unsigned long vmalloc_to_phys(void *v)
{
struct page *p = vmalloc_to_page(v);
BUG_ON(!p);
return page_to_phys(p) + offset_in_page(v);
}
static int memord(const void *d1, size_t s1, const void *d2, size_t s2)
{
if (s1 < s2)
return 1;
if (s2 > s1)
return -1;
return memcmp(d1, d2, s1);
}
static int ev_uniq_ord(const void *v1, size_t s1, unsigned d1, const void *v2,
size_t s2, unsigned d2)
{
int r = memord(v1, s1, v2, s2);
if (r)
return r;
if (d1 > d2)
return 1;
if (d2 > d1)
return -1;
return 0;
}
static int event_uniq_add(struct rb_root *root, const char *name, int nl,
unsigned domain)
{
struct rb_node **new = &(root->rb_node), *parent = NULL;
struct event_uniq *data;
while (*new) {
struct event_uniq *it;
int result;
it = container_of(*new, struct event_uniq, node);
result = ev_uniq_ord(name, nl, domain, it->name, it->nl,
it->domain);
parent = *new;
if (result < 0)
new = &((*new)->rb_left);
else if (result > 0)
new = &((*new)->rb_right);
else {
it->ct++;
pr_info("found a duplicate event %.*s, ct=%u\n", nl,
name, it->ct);
return it->ct;
}
}
data = kmalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
*data = (struct event_uniq) {
.name = name,
.nl = nl,
.ct = 0,
.domain = domain,
};
rb_link_node(&data->node, parent, new);
rb_insert_color(&data->node, root);
return 0;
}
static void event_uniq_destroy(struct rb_root *root)
{
struct event_uniq *pos, *n;
rbtree_postorder_for_each_entry_safe(pos, n, root, node)
kfree(pos);
}
static ssize_t catalog_event_len_validate(struct hv_24x7_event_data *event,
size_t event_idx,
size_t event_data_bytes,
size_t event_entry_count,
size_t offset, void *end)
{
ssize_t ev_len;
void *ev_end, *calc_ev_end;
if (offset >= event_data_bytes)
return -1;
if (event_idx >= event_entry_count) {
pr_devel("catalog event data has %zu bytes of padding after last event\n",
event_data_bytes - offset);
return -1;
}
if (!event_fixed_portion_is_within(event, end)) {
pr_warn("event %zu fixed portion is not within range\n",
event_idx);
return -1;
}
ev_len = be16_to_cpu(event->length);
if (ev_len % 16)
pr_info("event %zu has length %zu not divisible by 16: event=%pK\n",
event_idx, ev_len, event);
ev_end = (__u8 *)event + ev_len;
if (ev_end > end) {
pr_warn("event %zu has .length=%zu, ends after buffer end: ev_end=%pK > end=%pK, offset=%zu\n",
event_idx, ev_len, ev_end, end,
offset);
return -1;
}
calc_ev_end = event_end(event, end);
if (!calc_ev_end) {
pr_warn("event %zu has a calculated length which exceeds buffer length %zu: event=%pK end=%pK, offset=%zu\n",
event_idx, event_data_bytes, event, end,
offset);
return -1;
}
if (calc_ev_end > ev_end) {
pr_warn("event %zu exceeds it's own length: event=%pK, end=%pK, offset=%zu, calc_ev_end=%pK\n",
event_idx, event, ev_end, offset, calc_ev_end);
return -1;
}
return ev_len;
}
static int create_events_from_catalog(struct attribute ***events_,
struct attribute ***event_descs_,
struct attribute ***event_long_descs_)
{
unsigned long hret;
size_t catalog_len, catalog_page_len, event_entry_count,
event_data_len, event_data_offs,
event_data_bytes, junk_events, event_idx, event_attr_ct, i,
attr_max, event_idx_last, desc_ct, long_desc_ct;
ssize_t ct, ev_len;
uint32_t catalog_version_num;
struct attribute **events, **event_descs, **event_long_descs;
struct hv_24x7_catalog_page_0 *page_0 =
kmem_cache_alloc(hv_page_cache, GFP_KERNEL);
void *page = page_0;
void *event_data, *end;
struct hv_24x7_event_data *event;
struct rb_root ev_uniq = RB_ROOT;
int ret = 0;
if (!page) {
ret = -ENOMEM;
goto e_out;
}
hret = h_get_24x7_catalog_page(page, 0, 0);
if (hret) {
ret = -EIO;
goto e_free;
}
catalog_version_num = be64_to_cpu(page_0->version);
catalog_page_len = be32_to_cpu(page_0->length);
if (MAX_4K < catalog_page_len) {
pr_err("invalid page count: %zu\n", catalog_page_len);
ret = -EIO;
goto e_free;
}
catalog_len = catalog_page_len * 4096;
event_entry_count = be16_to_cpu(page_0->event_entry_count);
event_data_offs = be16_to_cpu(page_0->event_data_offs);
event_data_len = be16_to_cpu(page_0->event_data_len);
pr_devel("cv %zu cl %zu eec %zu edo %zu edl %zu\n",
(size_t)catalog_version_num, catalog_len,
event_entry_count, event_data_offs, event_data_len);
if ((MAX_4K < event_data_len)
|| (MAX_4K < event_data_offs)
|| (MAX_4K - event_data_offs < event_data_len)) {
pr_err("invalid event data offs %zu and/or len %zu\n",
event_data_offs, event_data_len);
ret = -EIO;
goto e_free;
}
if ((event_data_offs + event_data_len) > catalog_page_len) {
pr_err("event data %zu-%zu does not fit inside catalog 0-%zu\n",
event_data_offs,
event_data_offs + event_data_len,
catalog_page_len);
ret = -EIO;
goto e_free;
}
if (SIZE_MAX / MAX_EVENTS_PER_EVENT_DATA - 1 < event_entry_count) {
pr_err("event_entry_count %zu is invalid\n",
event_entry_count);
ret = -EIO;
goto e_free;
}
event_data_bytes = event_data_len * 4096;
event_data = vmalloc(event_data_bytes);
if (!event_data) {
pr_err("could not allocate event data\n");
ret = -ENOMEM;
goto e_free;
}
end = event_data + event_data_bytes;
BUILD_BUG_ON(PAGE_SIZE % 4096);
for (i = 0; i < event_data_len; i++) {
hret = h_get_24x7_catalog_page_(
vmalloc_to_phys(event_data + i * 4096),
catalog_version_num,
i + event_data_offs);
if (hret) {
pr_err("failed to get event data in page %zu\n",
i + event_data_offs);
ret = -EIO;
goto e_event_data;
}
}
for (junk_events = 0, event = event_data, event_idx = 0, attr_max = 0;
;
event_idx++, event = (void *)event + ev_len) {
size_t offset = (void *)event - (void *)event_data;
char *name;
int nl;
ev_len = catalog_event_len_validate(event, event_idx,
event_data_bytes,
event_entry_count,
offset, end);
if (ev_len < 0)
break;
name = event_name(event, &nl);
if (event->event_group_record_len == 0) {
pr_devel("invalid event %zu (%.*s): group_record_len == 0, skipping\n",
event_idx, nl, name);
junk_events++;
continue;
}
if (!catalog_entry_domain_is_valid(event->domain)) {
pr_info("event %zu (%.*s) has invalid domain %d\n",
event_idx, nl, name, event->domain);
junk_events++;
continue;
}
attr_max += event_to_attr_ct(event);
}
event_idx_last = event_idx;
if (event_idx_last != event_entry_count)
pr_warn("event buffer ended before listed # of events were parsed (got %zu, wanted %zu, junk %zu)\n",
event_idx_last, event_entry_count, junk_events);
events = kmalloc_array(attr_max + 1, sizeof(*events), GFP_KERNEL);
if (!events) {
ret = -ENOMEM;
goto e_event_data;
}
event_descs = kmalloc_array(event_idx + 1, sizeof(*event_descs),
GFP_KERNEL);
if (!event_descs) {
ret = -ENOMEM;
goto e_event_attrs;
}
event_long_descs = kmalloc_array(event_idx + 1,
sizeof(*event_long_descs), GFP_KERNEL);
if (!event_long_descs) {
ret = -ENOMEM;
goto e_event_descs;
}
for (junk_events = 0, event_attr_ct = 0, desc_ct = 0, long_desc_ct = 0,
event = event_data, event_idx = 0;
event_idx < event_idx_last;
event_idx++, ev_len = be16_to_cpu(event->length),
event = (void *)event + ev_len) {
char *name;
int nl;
int nonce;
if (event->event_group_record_len == 0)
continue;
if (!catalog_entry_domain_is_valid(event->domain))
continue;
name = event_name(event, &nl);
nonce = event_uniq_add(&ev_uniq, name, nl, event->domain);
ct = event_data_to_attrs(event_idx, events + event_attr_ct,
event, nonce);
if (ct <= 0) {
pr_warn("event %zu (%.*s) creation failure, skipping\n",
event_idx, nl, name);
junk_events++;
} else {
event_attr_ct += ct;
event_descs[desc_ct] = event_to_desc_attr(event, nonce);
if (event_descs[desc_ct])
desc_ct++;
event_long_descs[long_desc_ct] =
event_to_long_desc_attr(event, nonce);
if (event_long_descs[long_desc_ct])
long_desc_ct++;
}
}
pr_info("read %zu catalog entries, created %zu event attrs (%zu failures), %zu descs\n",
event_idx, event_attr_ct, junk_events, desc_ct);
events[event_attr_ct] = NULL;
event_descs[desc_ct] = NULL;
event_long_descs[long_desc_ct] = NULL;
event_uniq_destroy(&ev_uniq);
vfree(event_data);
kmem_cache_free(hv_page_cache, page);
*events_ = events;
*event_descs_ = event_descs;
*event_long_descs_ = event_long_descs;
return 0;
e_event_descs:
kfree(event_descs);
e_event_attrs:
kfree(events);
e_event_data:
vfree(event_data);
e_free:
kmem_cache_free(hv_page_cache, page);
e_out:
*events_ = NULL;
*event_descs_ = NULL;
*event_long_descs_ = NULL;
return ret;
}
static ssize_t catalog_read(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr, char *buf,
loff_t offset, size_t count)
{
unsigned long hret;
ssize_t ret = 0;
size_t catalog_len = 0, catalog_page_len = 0;
loff_t page_offset = 0;
loff_t offset_in_page;
size_t copy_len;
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
offset_in_page = offset % 4096;
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
copy_len = 4096 - offset_in_page;
if (copy_len > count)
copy_len = count;
memcpy(buf, page+offset_in_page, copy_len);
ret = copy_len;
e_free:
if (hret)
pr_err("h_get_24x7_catalog_page(ver=%lld, page=%lld) failed:"
" rc=%ld\n",
catalog_version_num, page_offset, hret);
kmem_cache_free(hv_page_cache, page);
pr_devel("catalog_read: offset=%lld(%lld) count=%zu "
"catalog_len=%zu(%zu) => %zd\n", offset, page_offset,
count, catalog_len, catalog_page_len, ret);
return ret;
}
static void log_24x7_hcall(struct hv_24x7_request_buffer *request_buffer,
struct hv_24x7_data_result_buffer *result_buffer,
unsigned long ret)
{
struct hv_24x7_request *req;
req = &request_buffer->requests[0];
pr_notice_ratelimited("hcall failed: [%d %#x %#x %d] => "
"ret 0x%lx (%ld) detail=0x%x failing ix=%x\n",
req->performance_domain, req->data_offset,
req->starting_ix, req->starting_lpar_ix, ret, ret,
result_buffer->detailed_rc,
result_buffer->failing_request_ix);
}
static void init_24x7_request(struct hv_24x7_request_buffer *request_buffer,
struct hv_24x7_data_result_buffer *result_buffer)
{
memset(request_buffer, 0, 4096);
memset(result_buffer, 0, 4096);
request_buffer->interface_version = HV_24X7_IF_VERSION_CURRENT;
}
static int make_24x7_request(struct hv_24x7_request_buffer *request_buffer,
struct hv_24x7_data_result_buffer *result_buffer)
{
unsigned long ret;
ret = plpar_hcall_norets(H_GET_24X7_DATA,
virt_to_phys(request_buffer), H24x7_DATA_BUFFER_SIZE,
virt_to_phys(result_buffer), H24x7_DATA_BUFFER_SIZE);
if (ret)
log_24x7_hcall(request_buffer, result_buffer, ret);
return ret;
}
static int add_event_to_24x7_request(struct perf_event *event,
struct hv_24x7_request_buffer *request_buffer)
{
u16 idx;
int i;
struct hv_24x7_request *req;
if (request_buffer->num_requests > 254) {
pr_devel("Too many requests for 24x7 HCALL %d\n",
request_buffer->num_requests);
return -EINVAL;
}
if (is_physical_domain(event_get_domain(event)))
idx = event_get_core(event);
else
idx = event_get_vcpu(event);
i = request_buffer->num_requests++;
req = &request_buffer->requests[i];
req->performance_domain = event_get_domain(event);
req->data_size = cpu_to_be16(8);
req->data_offset = cpu_to_be32(event_get_offset(event));
req->starting_lpar_ix = cpu_to_be16(event_get_lpar(event)),
req->max_num_lpars = cpu_to_be16(1);
req->starting_ix = cpu_to_be16(idx);
req->max_ix = cpu_to_be16(1);
return 0;
}
static unsigned long single_24x7_request(struct perf_event *event, u64 *count)
{
unsigned long ret;
struct hv_24x7_request_buffer *request_buffer;
struct hv_24x7_data_result_buffer *result_buffer;
struct hv_24x7_result *resb;
BUILD_BUG_ON(sizeof(*request_buffer) > 4096);
BUILD_BUG_ON(sizeof(*result_buffer) > 4096);
request_buffer = (void *)get_cpu_var(hv_24x7_reqb);
result_buffer = (void *)get_cpu_var(hv_24x7_resb);
init_24x7_request(request_buffer, result_buffer);
ret = add_event_to_24x7_request(event, request_buffer);
if (ret)
goto out;
ret = make_24x7_request(request_buffer, result_buffer);
if (ret) {
log_24x7_hcall(request_buffer, result_buffer, ret);
goto out;
}
resb = &result_buffer->results[0];
*count = be64_to_cpu(resb->elements[0].element_data[0]);
out:
put_cpu_var(hv_24x7_reqb);
put_cpu_var(hv_24x7_resb);
return ret;
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
event->attr.exclude_guest)
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
pr_devel("hv permissions disallow: is_physical_domain:%d, lpar=0x%llx\n",
is_physical_domain(domain),
event_get_lpar(event));
return -EACCES;
}
if (single_24x7_request(event, &ct)) {
pr_devel("test hcall failed\n");
return -EIO;
}
return 0;
}
static u64 h_24x7_get_value(struct perf_event *event)
{
unsigned long ret;
u64 ct;
ret = single_24x7_request(event, &ct);
if (ret)
return 0;
return ct;
}
static void update_event_count(struct perf_event *event, u64 now)
{
s64 prev;
prev = local64_xchg(&event->hw.prev_count, now);
local64_add(now - prev, &event->count);
}
static void h_24x7_event_read(struct perf_event *event)
{
u64 now;
now = h_24x7_get_value(event);
update_event_count(event, now);
}
static void h_24x7_event_start(struct perf_event *event, int flags)
{
if (flags & PERF_EF_RELOAD)
local64_set(&event->hw.prev_count, h_24x7_get_value(event));
}
static void h_24x7_event_stop(struct perf_event *event, int flags)
{
h_24x7_event_read(event);
}
static int h_24x7_event_add(struct perf_event *event, int flags)
{
if (flags & PERF_EF_START)
h_24x7_event_start(event, flags);
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
h_24x7_pmu.capabilities |= PERF_PMU_CAP_NO_INTERRUPT;
r = create_events_from_catalog(&event_group.attrs,
&event_desc_group.attrs,
&event_long_desc_group.attrs);
if (r)
return r;
r = perf_pmu_register(&h_24x7_pmu, h_24x7_pmu.name, -1);
if (r)
return r;
return 0;
}
