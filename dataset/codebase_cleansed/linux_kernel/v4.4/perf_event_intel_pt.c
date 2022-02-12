static u32 pt_cap_get(enum pt_capabilities cap)
{
struct pt_cap_desc *cd = &pt_caps[cap];
u32 c = pt_pmu.caps[cd->leaf * PT_CPUID_REGS_NUM + cd->reg];
unsigned int shift = __ffs(cd->mask);
return (c & cd->mask) >> shift;
}
static ssize_t pt_cap_show(struct device *cdev,
struct device_attribute *attr,
char *buf)
{
struct dev_ext_attribute *ea =
container_of(attr, struct dev_ext_attribute, attr);
enum pt_capabilities cap = (long)ea->var;
return snprintf(buf, PAGE_SIZE, "%x\n", pt_cap_get(cap));
}
static int __init pt_pmu_hw_init(void)
{
struct dev_ext_attribute *de_attrs;
struct attribute **attrs;
size_t size;
int ret;
long i;
attrs = NULL;
for (i = 0; i < PT_CPUID_LEAVES; i++) {
cpuid_count(20, i,
&pt_pmu.caps[CR_EAX + i*PT_CPUID_REGS_NUM],
&pt_pmu.caps[CR_EBX + i*PT_CPUID_REGS_NUM],
&pt_pmu.caps[CR_ECX + i*PT_CPUID_REGS_NUM],
&pt_pmu.caps[CR_EDX + i*PT_CPUID_REGS_NUM]);
}
ret = -ENOMEM;
size = sizeof(struct attribute *) * (ARRAY_SIZE(pt_caps)+1);
attrs = kzalloc(size, GFP_KERNEL);
if (!attrs)
goto fail;
size = sizeof(struct dev_ext_attribute) * (ARRAY_SIZE(pt_caps)+1);
de_attrs = kzalloc(size, GFP_KERNEL);
if (!de_attrs)
goto fail;
for (i = 0; i < ARRAY_SIZE(pt_caps); i++) {
struct dev_ext_attribute *de_attr = de_attrs + i;
de_attr->attr.attr.name = pt_caps[i].name;
sysfs_attr_init(&de_attr->attr.attr);
de_attr->attr.attr.mode = S_IRUGO;
de_attr->attr.show = pt_cap_show;
de_attr->var = (void *)i;
attrs[i] = &de_attr->attr.attr;
}
pt_cap_group.attrs = attrs;
return 0;
fail:
kfree(attrs);
return ret;
}
static bool pt_event_valid(struct perf_event *event)
{
u64 config = event->attr.config;
u64 allowed, requested;
if ((config & PT_CONFIG_MASK) != config)
return false;
if (config & RTIT_CTL_CYC_PSB) {
if (!pt_cap_get(PT_CAP_psb_cyc))
return false;
allowed = pt_cap_get(PT_CAP_psb_periods);
requested = (config & RTIT_CTL_PSB_FREQ) >>
RTIT_CTL_PSB_FREQ_OFFSET;
if (requested && (!(allowed & BIT(requested))))
return false;
allowed = pt_cap_get(PT_CAP_cycle_thresholds);
requested = (config & RTIT_CTL_CYC_THRESH) >>
RTIT_CTL_CYC_THRESH_OFFSET;
if (requested && (!(allowed & BIT(requested))))
return false;
}
if (config & RTIT_CTL_MTC) {
if (!pt_cap_get(PT_CAP_mtc))
return false;
allowed = pt_cap_get(PT_CAP_mtc_periods);
if (!allowed)
return false;
requested = (config & RTIT_CTL_MTC_RANGE) >>
RTIT_CTL_MTC_RANGE_OFFSET;
if (!(allowed & BIT(requested)))
return false;
}
return true;
}
static void pt_config(struct perf_event *event)
{
u64 reg;
if (!event->hw.itrace_started) {
event->hw.itrace_started = 1;
wrmsrl(MSR_IA32_RTIT_STATUS, 0);
}
reg = RTIT_CTL_TOPA | RTIT_CTL_BRANCH_EN | RTIT_CTL_TRACEEN;
if (!event->attr.exclude_kernel)
reg |= RTIT_CTL_OS;
if (!event->attr.exclude_user)
reg |= RTIT_CTL_USR;
reg |= (event->attr.config & PT_CONFIG_MASK);
wrmsrl(MSR_IA32_RTIT_CTL, reg);
}
static void pt_config_start(bool start)
{
u64 ctl;
rdmsrl(MSR_IA32_RTIT_CTL, ctl);
if (start)
ctl |= RTIT_CTL_TRACEEN;
else
ctl &= ~RTIT_CTL_TRACEEN;
wrmsrl(MSR_IA32_RTIT_CTL, ctl);
if (!start)
wmb();
}
static void pt_config_buffer(void *buf, unsigned int topa_idx,
unsigned int output_off)
{
u64 reg;
wrmsrl(MSR_IA32_RTIT_OUTPUT_BASE, virt_to_phys(buf));
reg = 0x7f | ((u64)topa_idx << 7) | ((u64)output_off << 32);
wrmsrl(MSR_IA32_RTIT_OUTPUT_MASK, reg);
}
static struct topa *topa_alloc(int cpu, gfp_t gfp)
{
int node = cpu_to_node(cpu);
struct topa *topa;
struct page *p;
p = alloc_pages_node(node, gfp | __GFP_ZERO, 0);
if (!p)
return NULL;
topa = page_address(p);
topa->last = 0;
topa->phys = page_to_phys(p);
if (!pt_cap_get(PT_CAP_topa_multiple_entries)) {
TOPA_ENTRY(topa, 1)->base = topa->phys >> TOPA_SHIFT;
TOPA_ENTRY(topa, 1)->end = 1;
}
return topa;
}
static void topa_free(struct topa *topa)
{
free_page((unsigned long)topa);
}
static void topa_insert_table(struct pt_buffer *buf, struct topa *topa)
{
struct topa *last = buf->last;
list_add_tail(&topa->list, &buf->tables);
if (!buf->first) {
buf->first = buf->last = buf->cur = topa;
return;
}
topa->offset = last->offset + last->size;
buf->last = topa;
if (!pt_cap_get(PT_CAP_topa_multiple_entries))
return;
BUG_ON(last->last != TENTS_PER_PAGE - 1);
TOPA_ENTRY(last, -1)->base = topa->phys >> TOPA_SHIFT;
TOPA_ENTRY(last, -1)->end = 1;
}
static bool topa_table_full(struct topa *topa)
{
if (!pt_cap_get(PT_CAP_topa_multiple_entries))
return !!topa->last;
return topa->last == TENTS_PER_PAGE - 1;
}
static int topa_insert_pages(struct pt_buffer *buf, gfp_t gfp)
{
struct topa *topa = buf->last;
int order = 0;
struct page *p;
p = virt_to_page(buf->data_pages[buf->nr_pages]);
if (PagePrivate(p))
order = page_private(p);
if (topa_table_full(topa)) {
topa = topa_alloc(buf->cpu, gfp);
if (!topa)
return -ENOMEM;
topa_insert_table(buf, topa);
}
TOPA_ENTRY(topa, -1)->base = page_to_phys(p) >> TOPA_SHIFT;
TOPA_ENTRY(topa, -1)->size = order;
if (!buf->snapshot && !pt_cap_get(PT_CAP_topa_multiple_entries)) {
TOPA_ENTRY(topa, -1)->intr = 1;
TOPA_ENTRY(topa, -1)->stop = 1;
}
topa->last++;
topa->size += sizes(order);
buf->nr_pages += 1ul << order;
return 0;
}
static void pt_topa_dump(struct pt_buffer *buf)
{
struct topa *topa;
list_for_each_entry(topa, &buf->tables, list) {
int i;
pr_debug("# table @%p (%016Lx), off %llx size %zx\n", topa->table,
topa->phys, topa->offset, topa->size);
for (i = 0; i < TENTS_PER_PAGE; i++) {
pr_debug("# entry @%p (%lx sz %u %c%c%c) raw=%16llx\n",
&topa->table[i],
(unsigned long)topa->table[i].base << TOPA_SHIFT,
sizes(topa->table[i].size),
topa->table[i].end ? 'E' : ' ',
topa->table[i].intr ? 'I' : ' ',
topa->table[i].stop ? 'S' : ' ',
*(u64 *)&topa->table[i]);
if ((pt_cap_get(PT_CAP_topa_multiple_entries) &&
topa->table[i].stop) ||
topa->table[i].end)
break;
}
}
}
static void pt_buffer_advance(struct pt_buffer *buf)
{
buf->output_off = 0;
buf->cur_idx++;
if (buf->cur_idx == buf->cur->last) {
if (buf->cur == buf->last)
buf->cur = buf->first;
else
buf->cur = list_entry(buf->cur->list.next, struct topa,
list);
buf->cur_idx = 0;
}
}
static void pt_update_head(struct pt *pt)
{
struct pt_buffer *buf = perf_get_aux(&pt->handle);
u64 topa_idx, base, old;
base = buf->cur->offset + buf->output_off;
for (topa_idx = 0; topa_idx < buf->cur_idx; topa_idx++)
base += sizes(buf->cur->table[topa_idx].size);
if (buf->snapshot) {
local_set(&buf->data_size, base);
} else {
old = (local64_xchg(&buf->head, base) &
((buf->nr_pages << PAGE_SHIFT) - 1));
if (base < old)
base += buf->nr_pages << PAGE_SHIFT;
local_add(base - old, &buf->data_size);
}
}
static void *pt_buffer_region(struct pt_buffer *buf)
{
return phys_to_virt(buf->cur->table[buf->cur_idx].base << TOPA_SHIFT);
}
static size_t pt_buffer_region_size(struct pt_buffer *buf)
{
return sizes(buf->cur->table[buf->cur_idx].size);
}
static void pt_handle_status(struct pt *pt)
{
struct pt_buffer *buf = perf_get_aux(&pt->handle);
int advance = 0;
u64 status;
rdmsrl(MSR_IA32_RTIT_STATUS, status);
if (status & RTIT_STATUS_ERROR) {
pr_err_ratelimited("ToPA ERROR encountered, trying to recover\n");
pt_topa_dump(buf);
status &= ~RTIT_STATUS_ERROR;
}
if (status & RTIT_STATUS_STOPPED) {
status &= ~RTIT_STATUS_STOPPED;
if (!pt_cap_get(PT_CAP_topa_multiple_entries) ||
buf->output_off == sizes(TOPA_ENTRY(buf->cur, buf->cur_idx)->size)) {
local_inc(&buf->lost);
advance++;
}
}
if (!pt_cap_get(PT_CAP_topa_multiple_entries) && !buf->snapshot &&
pt_buffer_region_size(buf) - buf->output_off <= TOPA_PMI_MARGIN) {
void *head = pt_buffer_region(buf);
memset(head + buf->output_off, 0,
pt_buffer_region_size(buf) -
buf->output_off);
advance++;
}
if (advance)
pt_buffer_advance(buf);
wrmsrl(MSR_IA32_RTIT_STATUS, status);
}
static void pt_read_offset(struct pt_buffer *buf)
{
u64 offset, base_topa;
rdmsrl(MSR_IA32_RTIT_OUTPUT_BASE, base_topa);
buf->cur = phys_to_virt(base_topa);
rdmsrl(MSR_IA32_RTIT_OUTPUT_MASK, offset);
buf->output_off = offset >> 32;
buf->cur_idx = (offset & 0xffffff80) >> 7;
}
static unsigned int pt_topa_next_entry(struct pt_buffer *buf, unsigned int pg)
{
struct topa_entry *te = buf->topa_index[pg];
if (buf->first == buf->last && buf->first->last == 1)
return pg;
do {
pg++;
pg &= buf->nr_pages - 1;
} while (buf->topa_index[pg] == te);
return pg;
}
static int pt_buffer_reset_markers(struct pt_buffer *buf,
struct perf_output_handle *handle)
{
unsigned long head = local64_read(&buf->head);
unsigned long idx, npages, wakeup;
if (buf->output_off + handle->size + 1 <
sizes(TOPA_ENTRY(buf->cur, buf->cur_idx)->size))
return -EINVAL;
if (!pt_cap_get(PT_CAP_topa_multiple_entries))
return 0;
buf->topa_index[buf->stop_pos]->stop = 0;
buf->topa_index[buf->intr_pos]->intr = 0;
npages = handle->size >> PAGE_SHIFT;
if (!offset_in_page(head + handle->size + 1))
npages++;
idx = (head >> PAGE_SHIFT) + npages;
idx &= buf->nr_pages - 1;
buf->stop_pos = idx;
wakeup = handle->wakeup >> PAGE_SHIFT;
idx = (head >> PAGE_SHIFT) + npages - 1;
if (idx > wakeup)
idx = wakeup;
idx &= buf->nr_pages - 1;
buf->intr_pos = idx;
buf->topa_index[buf->stop_pos]->stop = 1;
buf->topa_index[buf->intr_pos]->intr = 1;
return 0;
}
static void pt_buffer_setup_topa_index(struct pt_buffer *buf)
{
struct topa *cur = buf->first, *prev = buf->last;
struct topa_entry *te_cur = TOPA_ENTRY(cur, 0),
*te_prev = TOPA_ENTRY(prev, prev->last - 1);
int pg = 0, idx = 0;
while (pg < buf->nr_pages) {
int tidx;
for (tidx = 0; tidx < 1 << te_cur->size; tidx++, pg++)
buf->topa_index[pg] = te_prev;
te_prev = te_cur;
if (idx == cur->last - 1) {
idx = 0;
cur = list_entry(cur->list.next, struct topa, list);
} else {
idx++;
}
te_cur = TOPA_ENTRY(cur, idx);
}
}
static void pt_buffer_reset_offsets(struct pt_buffer *buf, unsigned long head)
{
int pg;
if (buf->snapshot)
head &= (buf->nr_pages << PAGE_SHIFT) - 1;
pg = (head >> PAGE_SHIFT) & (buf->nr_pages - 1);
pg = pt_topa_next_entry(buf, pg);
buf->cur = (struct topa *)((unsigned long)buf->topa_index[pg] & PAGE_MASK);
buf->cur_idx = ((unsigned long)buf->topa_index[pg] -
(unsigned long)buf->cur) / sizeof(struct topa_entry);
buf->output_off = head & (sizes(buf->cur->table[buf->cur_idx].size) - 1);
local64_set(&buf->head, head);
local_set(&buf->data_size, 0);
}
static void pt_buffer_fini_topa(struct pt_buffer *buf)
{
struct topa *topa, *iter;
list_for_each_entry_safe(topa, iter, &buf->tables, list) {
topa_free(topa);
}
}
static int pt_buffer_init_topa(struct pt_buffer *buf, unsigned long nr_pages,
gfp_t gfp)
{
struct topa *topa;
int err;
topa = topa_alloc(buf->cpu, gfp);
if (!topa)
return -ENOMEM;
topa_insert_table(buf, topa);
while (buf->nr_pages < nr_pages) {
err = topa_insert_pages(buf, gfp);
if (err) {
pt_buffer_fini_topa(buf);
return -ENOMEM;
}
}
pt_buffer_setup_topa_index(buf);
if (pt_cap_get(PT_CAP_topa_multiple_entries)) {
TOPA_ENTRY(buf->last, -1)->base = buf->first->phys >> TOPA_SHIFT;
TOPA_ENTRY(buf->last, -1)->end = 1;
}
pt_topa_dump(buf);
return 0;
}
static void *
pt_buffer_setup_aux(int cpu, void **pages, int nr_pages, bool snapshot)
{
struct pt_buffer *buf;
int node, ret;
if (!nr_pages)
return NULL;
if (cpu == -1)
cpu = raw_smp_processor_id();
node = cpu_to_node(cpu);
buf = kzalloc_node(offsetof(struct pt_buffer, topa_index[nr_pages]),
GFP_KERNEL, node);
if (!buf)
return NULL;
buf->cpu = cpu;
buf->snapshot = snapshot;
buf->data_pages = pages;
INIT_LIST_HEAD(&buf->tables);
ret = pt_buffer_init_topa(buf, nr_pages, GFP_KERNEL);
if (ret) {
kfree(buf);
return NULL;
}
return buf;
}
static void pt_buffer_free_aux(void *data)
{
struct pt_buffer *buf = data;
pt_buffer_fini_topa(buf);
kfree(buf);
}
static bool pt_buffer_is_full(struct pt_buffer *buf, struct pt *pt)
{
if (buf->snapshot)
return false;
if (local_read(&buf->data_size) >= pt->handle.size)
return true;
return false;
}
void intel_pt_interrupt(void)
{
struct pt *pt = this_cpu_ptr(&pt_ctx);
struct pt_buffer *buf;
struct perf_event *event = pt->handle.event;
if (!ACCESS_ONCE(pt->handle_nmi))
return;
pt_config_start(false);
if (!event)
return;
buf = perf_get_aux(&pt->handle);
if (!buf)
return;
pt_read_offset(buf);
pt_handle_status(pt);
pt_update_head(pt);
perf_aux_output_end(&pt->handle, local_xchg(&buf->data_size, 0),
local_xchg(&buf->lost, 0));
if (!event->hw.state) {
int ret;
buf = perf_aux_output_begin(&pt->handle, event);
if (!buf) {
event->hw.state = PERF_HES_STOPPED;
return;
}
pt_buffer_reset_offsets(buf, pt->handle.head);
ret = pt_buffer_reset_markers(buf, &pt->handle);
if (ret) {
perf_aux_output_end(&pt->handle, 0, true);
return;
}
pt_config_buffer(buf->cur->table, buf->cur_idx,
buf->output_off);
pt_config(event);
}
}
static void pt_event_start(struct perf_event *event, int mode)
{
struct pt *pt = this_cpu_ptr(&pt_ctx);
struct pt_buffer *buf = perf_get_aux(&pt->handle);
if (!buf || pt_buffer_is_full(buf, pt)) {
event->hw.state = PERF_HES_STOPPED;
return;
}
ACCESS_ONCE(pt->handle_nmi) = 1;
event->hw.state = 0;
pt_config_buffer(buf->cur->table, buf->cur_idx,
buf->output_off);
pt_config(event);
}
static void pt_event_stop(struct perf_event *event, int mode)
{
struct pt *pt = this_cpu_ptr(&pt_ctx);
ACCESS_ONCE(pt->handle_nmi) = 0;
pt_config_start(false);
if (event->hw.state == PERF_HES_STOPPED)
return;
event->hw.state = PERF_HES_STOPPED;
if (mode & PERF_EF_UPDATE) {
struct pt_buffer *buf = perf_get_aux(&pt->handle);
if (!buf)
return;
if (WARN_ON_ONCE(pt->handle.event != event))
return;
pt_read_offset(buf);
pt_handle_status(pt);
pt_update_head(pt);
}
}
static void pt_event_del(struct perf_event *event, int mode)
{
struct pt *pt = this_cpu_ptr(&pt_ctx);
struct pt_buffer *buf;
pt_event_stop(event, PERF_EF_UPDATE);
buf = perf_get_aux(&pt->handle);
if (buf) {
if (buf->snapshot)
pt->handle.head =
local_xchg(&buf->data_size,
buf->nr_pages << PAGE_SHIFT);
perf_aux_output_end(&pt->handle, local_xchg(&buf->data_size, 0),
local_xchg(&buf->lost, 0));
}
}
static int pt_event_add(struct perf_event *event, int mode)
{
struct pt_buffer *buf;
struct pt *pt = this_cpu_ptr(&pt_ctx);
struct hw_perf_event *hwc = &event->hw;
int ret = -EBUSY;
if (pt->handle.event)
goto fail;
buf = perf_aux_output_begin(&pt->handle, event);
ret = -EINVAL;
if (!buf)
goto fail_stop;
pt_buffer_reset_offsets(buf, pt->handle.head);
if (!buf->snapshot) {
ret = pt_buffer_reset_markers(buf, &pt->handle);
if (ret)
goto fail_end_stop;
}
if (mode & PERF_EF_START) {
pt_event_start(event, 0);
ret = -EBUSY;
if (hwc->state == PERF_HES_STOPPED)
goto fail_end_stop;
} else {
hwc->state = PERF_HES_STOPPED;
}
return 0;
fail_end_stop:
perf_aux_output_end(&pt->handle, 0, true);
fail_stop:
hwc->state = PERF_HES_STOPPED;
fail:
return ret;
}
static void pt_event_read(struct perf_event *event)
{
}
static void pt_event_destroy(struct perf_event *event)
{
x86_del_exclusive(x86_lbr_exclusive_pt);
}
static int pt_event_init(struct perf_event *event)
{
if (event->attr.type != pt_pmu.pmu.type)
return -ENOENT;
if (!pt_event_valid(event))
return -EINVAL;
if (x86_add_exclusive(x86_lbr_exclusive_pt))
return -EBUSY;
event->destroy = pt_event_destroy;
return 0;
}
static __init int pt_init(void)
{
int ret, cpu, prior_warn = 0;
BUILD_BUG_ON(sizeof(struct topa) > PAGE_SIZE);
if (!test_cpu_cap(&boot_cpu_data, X86_FEATURE_INTEL_PT))
return -ENODEV;
get_online_cpus();
for_each_online_cpu(cpu) {
u64 ctl;
ret = rdmsrl_safe_on_cpu(cpu, MSR_IA32_RTIT_CTL, &ctl);
if (!ret && (ctl & RTIT_CTL_TRACEEN))
prior_warn++;
}
put_online_cpus();
if (prior_warn) {
x86_add_exclusive(x86_lbr_exclusive_pt);
pr_warn("PT is enabled at boot time, doing nothing\n");
return -EBUSY;
}
ret = pt_pmu_hw_init();
if (ret)
return ret;
if (!pt_cap_get(PT_CAP_topa_output)) {
pr_warn("ToPA output is not supported on this CPU\n");
return -ENODEV;
}
if (!pt_cap_get(PT_CAP_topa_multiple_entries))
pt_pmu.pmu.capabilities =
PERF_PMU_CAP_AUX_NO_SG | PERF_PMU_CAP_AUX_SW_DOUBLEBUF;
pt_pmu.pmu.capabilities |= PERF_PMU_CAP_EXCLUSIVE | PERF_PMU_CAP_ITRACE;
pt_pmu.pmu.attr_groups = pt_attr_groups;
pt_pmu.pmu.task_ctx_nr = perf_sw_context;
pt_pmu.pmu.event_init = pt_event_init;
pt_pmu.pmu.add = pt_event_add;
pt_pmu.pmu.del = pt_event_del;
pt_pmu.pmu.start = pt_event_start;
pt_pmu.pmu.stop = pt_event_stop;
pt_pmu.pmu.read = pt_event_read;
pt_pmu.pmu.setup_aux = pt_buffer_setup_aux;
pt_pmu.pmu.free_aux = pt_buffer_free_aux;
ret = perf_pmu_register(&pt_pmu.pmu, "intel_pt", -1);
return ret;
}
