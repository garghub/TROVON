static int uncore_pcibus_to_physid(struct pci_bus *bus)
{
struct pci2phy_map *map;
int phys_id = -1;
raw_spin_lock(&pci2phy_map_lock);
list_for_each_entry(map, &pci2phy_map_head, list) {
if (map->segment == pci_domain_nr(bus)) {
phys_id = map->pbus_to_physid[bus->number];
break;
}
}
raw_spin_unlock(&pci2phy_map_lock);
return phys_id;
}
static void uncore_free_pcibus_map(void)
{
struct pci2phy_map *map, *tmp;
list_for_each_entry_safe(map, tmp, &pci2phy_map_head, list) {
list_del(&map->list);
kfree(map);
}
}
struct pci2phy_map *__find_pci2phy_map(int segment)
{
struct pci2phy_map *map, *alloc = NULL;
int i;
lockdep_assert_held(&pci2phy_map_lock);
lookup:
list_for_each_entry(map, &pci2phy_map_head, list) {
if (map->segment == segment)
goto end;
}
if (!alloc) {
raw_spin_unlock(&pci2phy_map_lock);
alloc = kmalloc(sizeof(struct pci2phy_map), GFP_KERNEL);
raw_spin_lock(&pci2phy_map_lock);
if (!alloc)
return NULL;
goto lookup;
}
map = alloc;
alloc = NULL;
map->segment = segment;
for (i = 0; i < 256; i++)
map->pbus_to_physid[i] = -1;
list_add_tail(&map->list, &pci2phy_map_head);
end:
kfree(alloc);
return map;
}
ssize_t uncore_event_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct uncore_event_desc *event =
container_of(attr, struct uncore_event_desc, attr);
return sprintf(buf, "%s", event->config);
}
struct intel_uncore_box *uncore_pmu_to_box(struct intel_uncore_pmu *pmu, int cpu)
{
return pmu->boxes[topology_logical_package_id(cpu)];
}
u64 uncore_msr_read_counter(struct intel_uncore_box *box, struct perf_event *event)
{
u64 count;
rdmsrl(event->hw.event_base, count);
return count;
}
struct event_constraint *
uncore_get_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct intel_uncore_extra_reg *er;
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct hw_perf_event_extra *reg2 = &event->hw.branch_reg;
unsigned long flags;
bool ok = false;
if (reg1->idx == EXTRA_REG_NONE ||
(!uncore_box_is_fake(box) && reg1->alloc))
return NULL;
er = &box->shared_regs[reg1->idx];
raw_spin_lock_irqsave(&er->lock, flags);
if (!atomic_read(&er->ref) ||
(er->config1 == reg1->config && er->config2 == reg2->config)) {
atomic_inc(&er->ref);
er->config1 = reg1->config;
er->config2 = reg2->config;
ok = true;
}
raw_spin_unlock_irqrestore(&er->lock, flags);
if (ok) {
if (!uncore_box_is_fake(box))
reg1->alloc = 1;
return NULL;
}
return &uncore_constraint_empty;
}
void uncore_put_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct intel_uncore_extra_reg *er;
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
if (uncore_box_is_fake(box) || !reg1->alloc)
return;
er = &box->shared_regs[reg1->idx];
atomic_dec(&er->ref);
reg1->alloc = 0;
}
u64 uncore_shared_reg_config(struct intel_uncore_box *box, int idx)
{
struct intel_uncore_extra_reg *er;
unsigned long flags;
u64 config;
er = &box->shared_regs[idx];
raw_spin_lock_irqsave(&er->lock, flags);
config = er->config;
raw_spin_unlock_irqrestore(&er->lock, flags);
return config;
}
static void uncore_assign_hw_event(struct intel_uncore_box *box,
struct perf_event *event, int idx)
{
struct hw_perf_event *hwc = &event->hw;
hwc->idx = idx;
hwc->last_tag = ++box->tags[idx];
if (hwc->idx == UNCORE_PMC_IDX_FIXED) {
hwc->event_base = uncore_fixed_ctr(box);
hwc->config_base = uncore_fixed_ctl(box);
return;
}
hwc->config_base = uncore_event_ctl(box, hwc->idx);
hwc->event_base = uncore_perf_ctr(box, hwc->idx);
}
void uncore_perf_event_update(struct intel_uncore_box *box, struct perf_event *event)
{
u64 prev_count, new_count, delta;
int shift;
if (event->hw.idx >= UNCORE_PMC_IDX_FIXED)
shift = 64 - uncore_fixed_ctr_bits(box);
else
shift = 64 - uncore_perf_ctr_bits(box);
again:
prev_count = local64_read(&event->hw.prev_count);
new_count = uncore_read_counter(box, event);
if (local64_xchg(&event->hw.prev_count, new_count) != prev_count)
goto again;
delta = (new_count << shift) - (prev_count << shift);
delta >>= shift;
local64_add(delta, &event->count);
}
static enum hrtimer_restart uncore_pmu_hrtimer(struct hrtimer *hrtimer)
{
struct intel_uncore_box *box;
struct perf_event *event;
unsigned long flags;
int bit;
box = container_of(hrtimer, struct intel_uncore_box, hrtimer);
if (!box->n_active || box->cpu != smp_processor_id())
return HRTIMER_NORESTART;
local_irq_save(flags);
list_for_each_entry(event, &box->active_list, active_entry) {
uncore_perf_event_update(box, event);
}
for_each_set_bit(bit, box->active_mask, UNCORE_PMC_IDX_MAX)
uncore_perf_event_update(box, box->events[bit]);
local_irq_restore(flags);
hrtimer_forward_now(hrtimer, ns_to_ktime(box->hrtimer_duration));
return HRTIMER_RESTART;
}
void uncore_pmu_start_hrtimer(struct intel_uncore_box *box)
{
hrtimer_start(&box->hrtimer, ns_to_ktime(box->hrtimer_duration),
HRTIMER_MODE_REL_PINNED);
}
void uncore_pmu_cancel_hrtimer(struct intel_uncore_box *box)
{
hrtimer_cancel(&box->hrtimer);
}
static void uncore_pmu_init_hrtimer(struct intel_uncore_box *box)
{
hrtimer_init(&box->hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
box->hrtimer.function = uncore_pmu_hrtimer;
}
static struct intel_uncore_box *uncore_alloc_box(struct intel_uncore_type *type,
int node)
{
int i, size, numshared = type->num_shared_regs ;
struct intel_uncore_box *box;
size = sizeof(*box) + numshared * sizeof(struct intel_uncore_extra_reg);
box = kzalloc_node(size, GFP_KERNEL, node);
if (!box)
return NULL;
for (i = 0; i < numshared; i++)
raw_spin_lock_init(&box->shared_regs[i].lock);
uncore_pmu_init_hrtimer(box);
box->cpu = -1;
box->pci_phys_id = -1;
box->pkgid = -1;
box->hrtimer_duration = UNCORE_PMU_HRTIMER_INTERVAL;
INIT_LIST_HEAD(&box->active_list);
return box;
}
static bool is_uncore_event(struct perf_event *event)
{
return event->pmu->event_init == uncore_pmu_event_init;
}
static int
uncore_collect_events(struct intel_uncore_box *box, struct perf_event *leader,
bool dogrp)
{
struct perf_event *event;
int n, max_count;
max_count = box->pmu->type->num_counters;
if (box->pmu->type->fixed_ctl)
max_count++;
if (box->n_events >= max_count)
return -EINVAL;
n = box->n_events;
if (is_uncore_event(leader)) {
box->event_list[n] = leader;
n++;
}
if (!dogrp)
return n;
list_for_each_entry(event, &leader->sibling_list, group_entry) {
if (!is_uncore_event(event) ||
event->state <= PERF_EVENT_STATE_OFF)
continue;
if (n >= max_count)
return -EINVAL;
box->event_list[n] = event;
n++;
}
return n;
}
static struct event_constraint *
uncore_get_event_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct intel_uncore_type *type = box->pmu->type;
struct event_constraint *c;
if (type->ops->get_constraint) {
c = type->ops->get_constraint(box, event);
if (c)
return c;
}
if (event->attr.config == UNCORE_FIXED_EVENT)
return &uncore_constraint_fixed;
if (type->constraints) {
for_each_event_constraint(c, type->constraints) {
if ((event->hw.config & c->cmask) == c->code)
return c;
}
}
return &type->unconstrainted;
}
static void uncore_put_event_constraint(struct intel_uncore_box *box,
struct perf_event *event)
{
if (box->pmu->type->ops->put_constraint)
box->pmu->type->ops->put_constraint(box, event);
}
static int uncore_assign_events(struct intel_uncore_box *box, int assign[], int n)
{
unsigned long used_mask[BITS_TO_LONGS(UNCORE_PMC_IDX_MAX)];
struct event_constraint *c;
int i, wmin, wmax, ret = 0;
struct hw_perf_event *hwc;
bitmap_zero(used_mask, UNCORE_PMC_IDX_MAX);
for (i = 0, wmin = UNCORE_PMC_IDX_MAX, wmax = 0; i < n; i++) {
c = uncore_get_event_constraint(box, box->event_list[i]);
box->event_constraint[i] = c;
wmin = min(wmin, c->weight);
wmax = max(wmax, c->weight);
}
for (i = 0; i < n; i++) {
hwc = &box->event_list[i]->hw;
c = box->event_constraint[i];
if (hwc->idx == -1)
break;
if (!test_bit(hwc->idx, c->idxmsk))
break;
if (test_bit(hwc->idx, used_mask))
break;
__set_bit(hwc->idx, used_mask);
if (assign)
assign[i] = hwc->idx;
}
if (i != n)
ret = perf_assign_events(box->event_constraint, n,
wmin, wmax, n, assign);
if (!assign || ret) {
for (i = 0; i < n; i++)
uncore_put_event_constraint(box, box->event_list[i]);
}
return ret ? -EINVAL : 0;
}
static void uncore_pmu_event_start(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
int idx = event->hw.idx;
if (WARN_ON_ONCE(!(event->hw.state & PERF_HES_STOPPED)))
return;
if (WARN_ON_ONCE(idx == -1 || idx >= UNCORE_PMC_IDX_MAX))
return;
event->hw.state = 0;
box->events[idx] = event;
box->n_active++;
__set_bit(idx, box->active_mask);
local64_set(&event->hw.prev_count, uncore_read_counter(box, event));
uncore_enable_event(box, event);
if (box->n_active == 1) {
uncore_enable_box(box);
uncore_pmu_start_hrtimer(box);
}
}
static void uncore_pmu_event_stop(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
struct hw_perf_event *hwc = &event->hw;
if (__test_and_clear_bit(hwc->idx, box->active_mask)) {
uncore_disable_event(box, event);
box->n_active--;
box->events[hwc->idx] = NULL;
WARN_ON_ONCE(hwc->state & PERF_HES_STOPPED);
hwc->state |= PERF_HES_STOPPED;
if (box->n_active == 0) {
uncore_disable_box(box);
uncore_pmu_cancel_hrtimer(box);
}
}
if ((flags & PERF_EF_UPDATE) && !(hwc->state & PERF_HES_UPTODATE)) {
uncore_perf_event_update(box, event);
hwc->state |= PERF_HES_UPTODATE;
}
}
static int uncore_pmu_event_add(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
struct hw_perf_event *hwc = &event->hw;
int assign[UNCORE_PMC_IDX_MAX];
int i, n, ret;
if (!box)
return -ENODEV;
ret = n = uncore_collect_events(box, event, false);
if (ret < 0)
return ret;
hwc->state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
if (!(flags & PERF_EF_START))
hwc->state |= PERF_HES_ARCH;
ret = uncore_assign_events(box, assign, n);
if (ret)
return ret;
for (i = 0; i < box->n_events; i++) {
event = box->event_list[i];
hwc = &event->hw;
if (hwc->idx == assign[i] &&
hwc->last_tag == box->tags[assign[i]])
continue;
if (hwc->state & PERF_HES_STOPPED)
hwc->state |= PERF_HES_ARCH;
uncore_pmu_event_stop(event, PERF_EF_UPDATE);
}
for (i = 0; i < n; i++) {
event = box->event_list[i];
hwc = &event->hw;
if (hwc->idx != assign[i] ||
hwc->last_tag != box->tags[assign[i]])
uncore_assign_hw_event(box, event, assign[i]);
else if (i < box->n_events)
continue;
if (hwc->state & PERF_HES_ARCH)
continue;
uncore_pmu_event_start(event, 0);
}
box->n_events = n;
return 0;
}
static void uncore_pmu_event_del(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
int i;
uncore_pmu_event_stop(event, PERF_EF_UPDATE);
for (i = 0; i < box->n_events; i++) {
if (event == box->event_list[i]) {
uncore_put_event_constraint(box, event);
for (++i; i < box->n_events; i++)
box->event_list[i - 1] = box->event_list[i];
--box->n_events;
break;
}
}
event->hw.idx = -1;
event->hw.last_tag = ~0ULL;
}
void uncore_pmu_event_read(struct perf_event *event)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
uncore_perf_event_update(box, event);
}
static int uncore_validate_group(struct intel_uncore_pmu *pmu,
struct perf_event *event)
{
struct perf_event *leader = event->group_leader;
struct intel_uncore_box *fake_box;
int ret = -EINVAL, n;
fake_box = uncore_alloc_box(pmu->type, NUMA_NO_NODE);
if (!fake_box)
return -ENOMEM;
fake_box->pmu = pmu;
n = uncore_collect_events(fake_box, leader, true);
if (n < 0)
goto out;
fake_box->n_events = n;
n = uncore_collect_events(fake_box, event, false);
if (n < 0)
goto out;
fake_box->n_events = n;
ret = uncore_assign_events(fake_box, NULL, n);
out:
kfree(fake_box);
return ret;
}
static int uncore_pmu_event_init(struct perf_event *event)
{
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
struct hw_perf_event *hwc = &event->hw;
int ret;
if (event->attr.type != event->pmu->type)
return -ENOENT;
pmu = uncore_event_to_pmu(event);
if (pmu->func_id < 0)
return -ENOENT;
if (event->attr.exclude_user || event->attr.exclude_kernel ||
event->attr.exclude_hv || event->attr.exclude_idle)
return -EINVAL;
if (hwc->sample_period)
return -EINVAL;
if (event->cpu < 0)
return -EINVAL;
box = uncore_pmu_to_box(pmu, event->cpu);
if (!box || box->cpu < 0)
return -EINVAL;
event->cpu = box->cpu;
event->pmu_private = box;
event->hw.idx = -1;
event->hw.last_tag = ~0ULL;
event->hw.extra_reg.idx = EXTRA_REG_NONE;
event->hw.branch_reg.idx = EXTRA_REG_NONE;
if (event->attr.config == UNCORE_FIXED_EVENT) {
if (!pmu->type->fixed_ctl)
return -EINVAL;
if (pmu->type->single_fixed && pmu->pmu_idx > 0)
return -EINVAL;
hwc->config = 0ULL;
} else {
hwc->config = event->attr.config & pmu->type->event_mask;
if (pmu->type->ops->hw_config) {
ret = pmu->type->ops->hw_config(box, event);
if (ret)
return ret;
}
}
if (event->group_leader != event)
ret = uncore_validate_group(pmu, event);
else
ret = 0;
return ret;
}
static ssize_t uncore_get_attr_cpumask(struct device *dev,
struct device_attribute *attr, char *buf)
{
return cpumap_print_to_pagebuf(true, buf, &uncore_cpu_mask);
}
static int uncore_pmu_register(struct intel_uncore_pmu *pmu)
{
int ret;
if (!pmu->type->pmu) {
pmu->pmu = (struct pmu) {
.attr_groups = pmu->type->attr_groups,
.task_ctx_nr = perf_invalid_context,
.event_init = uncore_pmu_event_init,
.add = uncore_pmu_event_add,
.del = uncore_pmu_event_del,
.start = uncore_pmu_event_start,
.stop = uncore_pmu_event_stop,
.read = uncore_pmu_event_read,
};
} else {
pmu->pmu = *pmu->type->pmu;
pmu->pmu.attr_groups = pmu->type->attr_groups;
}
if (pmu->type->num_boxes == 1) {
if (strlen(pmu->type->name) > 0)
sprintf(pmu->name, "uncore_%s", pmu->type->name);
else
sprintf(pmu->name, "uncore");
} else {
sprintf(pmu->name, "uncore_%s_%d", pmu->type->name,
pmu->pmu_idx);
}
ret = perf_pmu_register(&pmu->pmu, pmu->name, -1);
if (!ret)
pmu->registered = true;
return ret;
}
static void uncore_pmu_unregister(struct intel_uncore_pmu *pmu)
{
if (!pmu->registered)
return;
perf_pmu_unregister(&pmu->pmu);
pmu->registered = false;
}
static void __init __uncore_exit_boxes(struct intel_uncore_type *type, int cpu)
{
struct intel_uncore_pmu *pmu = type->pmus;
struct intel_uncore_box *box;
int i, pkg;
if (pmu) {
pkg = topology_physical_package_id(cpu);
for (i = 0; i < type->num_boxes; i++, pmu++) {
box = pmu->boxes[pkg];
if (box)
uncore_box_exit(box);
}
}
}
static void __init uncore_exit_boxes(void *dummy)
{
struct intel_uncore_type **types;
for (types = uncore_msr_uncores; *types; types++)
__uncore_exit_boxes(*types++, smp_processor_id());
}
static void uncore_free_boxes(struct intel_uncore_pmu *pmu)
{
int pkg;
for (pkg = 0; pkg < max_packages; pkg++)
kfree(pmu->boxes[pkg]);
kfree(pmu->boxes);
}
static void __init uncore_type_exit(struct intel_uncore_type *type)
{
struct intel_uncore_pmu *pmu = type->pmus;
int i;
if (pmu) {
for (i = 0; i < type->num_boxes; i++, pmu++) {
uncore_pmu_unregister(pmu);
uncore_free_boxes(pmu);
}
kfree(type->pmus);
type->pmus = NULL;
}
kfree(type->events_group);
type->events_group = NULL;
}
static void __init uncore_types_exit(struct intel_uncore_type **types)
{
for (; *types; types++)
uncore_type_exit(*types);
}
static int __init uncore_type_init(struct intel_uncore_type *type, bool setid)
{
struct intel_uncore_pmu *pmus;
struct attribute_group *attr_group;
struct attribute **attrs;
size_t size;
int i, j;
pmus = kzalloc(sizeof(*pmus) * type->num_boxes, GFP_KERNEL);
if (!pmus)
return -ENOMEM;
size = max_packages * sizeof(struct intel_uncore_box *);
for (i = 0; i < type->num_boxes; i++) {
pmus[i].func_id = setid ? i : -1;
pmus[i].pmu_idx = i;
pmus[i].type = type;
pmus[i].boxes = kzalloc(size, GFP_KERNEL);
if (!pmus[i].boxes)
return -ENOMEM;
}
type->pmus = pmus;
type->unconstrainted = (struct event_constraint)
__EVENT_CONSTRAINT(0, (1ULL << type->num_counters) - 1,
0, type->num_counters, 0, 0);
if (type->event_descs) {
for (i = 0; type->event_descs[i].attr.attr.name; i++);
attr_group = kzalloc(sizeof(struct attribute *) * (i + 1) +
sizeof(*attr_group), GFP_KERNEL);
if (!attr_group)
return -ENOMEM;
attrs = (struct attribute **)(attr_group + 1);
attr_group->name = "events";
attr_group->attrs = attrs;
for (j = 0; j < i; j++)
attrs[j] = &type->event_descs[j].attr.attr;
type->events_group = attr_group;
}
type->pmu_group = &uncore_pmu_attr_group;
return 0;
}
static int __init
uncore_types_init(struct intel_uncore_type **types, bool setid)
{
int ret;
for (; *types; types++) {
ret = uncore_type_init(*types, setid);
if (ret)
return ret;
}
return 0;
}
static int uncore_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct intel_uncore_type *type;
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
int phys_id, pkg, ret;
phys_id = uncore_pcibus_to_physid(pdev->bus);
if (phys_id < 0)
return -ENODEV;
pkg = topology_phys_to_logical_pkg(phys_id);
if (WARN_ON_ONCE(pkg < 0))
return -EINVAL;
if (UNCORE_PCI_DEV_TYPE(id->driver_data) == UNCORE_EXTRA_PCI_DEV) {
int idx = UNCORE_PCI_DEV_IDX(id->driver_data);
uncore_extra_pci_dev[pkg].dev[idx] = pdev;
pci_set_drvdata(pdev, NULL);
return 0;
}
type = uncore_pci_uncores[UNCORE_PCI_DEV_TYPE(id->driver_data)];
pmu = &type->pmus[UNCORE_PCI_DEV_IDX(id->driver_data)];
if (boot_cpu_data.x86_model == 87) {
while (pmu->func_id >= 0)
pmu++;
}
if (WARN_ON_ONCE(pmu->boxes[pkg] != NULL))
return -EINVAL;
box = uncore_alloc_box(type, NUMA_NO_NODE);
if (!box)
return -ENOMEM;
if (pmu->func_id < 0)
pmu->func_id = pdev->devfn;
else
WARN_ON_ONCE(pmu->func_id != pdev->devfn);
atomic_inc(&box->refcnt);
box->pci_phys_id = phys_id;
box->pkgid = pkg;
box->pci_dev = pdev;
box->pmu = pmu;
uncore_box_init(box);
pci_set_drvdata(pdev, box);
pmu->boxes[pkg] = box;
if (atomic_inc_return(&pmu->activeboxes) > 1)
return 0;
ret = uncore_pmu_register(pmu);
if (ret) {
pci_set_drvdata(pdev, NULL);
pmu->boxes[pkg] = NULL;
uncore_box_exit(box);
kfree(box);
}
return ret;
}
static void uncore_pci_remove(struct pci_dev *pdev)
{
struct intel_uncore_box *box = pci_get_drvdata(pdev);
struct intel_uncore_pmu *pmu;
int i, phys_id, pkg;
phys_id = uncore_pcibus_to_physid(pdev->bus);
pkg = topology_phys_to_logical_pkg(phys_id);
box = pci_get_drvdata(pdev);
if (!box) {
for (i = 0; i < UNCORE_EXTRA_PCI_DEV_MAX; i++) {
if (uncore_extra_pci_dev[pkg].dev[i] == pdev) {
uncore_extra_pci_dev[pkg].dev[i] = NULL;
break;
}
}
WARN_ON_ONCE(i >= UNCORE_EXTRA_PCI_DEV_MAX);
return;
}
pmu = box->pmu;
if (WARN_ON_ONCE(phys_id != box->pci_phys_id))
return;
pci_set_drvdata(pdev, NULL);
pmu->boxes[pkg] = NULL;
if (atomic_dec_return(&pmu->activeboxes) == 0)
uncore_pmu_unregister(pmu);
uncore_box_exit(box);
kfree(box);
}
static int __init uncore_pci_init(void)
{
size_t size;
int ret;
switch (boot_cpu_data.x86_model) {
case 45:
ret = snbep_uncore_pci_init();
break;
case 62:
ret = ivbep_uncore_pci_init();
break;
case 63:
ret = hswep_uncore_pci_init();
break;
case 79:
case 86:
ret = bdx_uncore_pci_init();
break;
case 42:
ret = snb_uncore_pci_init();
break;
case 58:
ret = ivb_uncore_pci_init();
break;
case 60:
case 69:
ret = hsw_uncore_pci_init();
break;
case 61:
ret = bdw_uncore_pci_init();
break;
case 87:
ret = knl_uncore_pci_init();
break;
case 94:
ret = skl_uncore_pci_init();
break;
default:
return -ENODEV;
}
if (ret)
return ret;
size = max_packages * sizeof(struct pci_extra_dev);
uncore_extra_pci_dev = kzalloc(size, GFP_KERNEL);
if (!uncore_extra_pci_dev) {
ret = -ENOMEM;
goto err;
}
ret = uncore_types_init(uncore_pci_uncores, false);
if (ret)
goto errtype;
uncore_pci_driver->probe = uncore_pci_probe;
uncore_pci_driver->remove = uncore_pci_remove;
ret = pci_register_driver(uncore_pci_driver);
if (ret)
goto errtype;
pcidrv_registered = true;
return 0;
errtype:
uncore_types_exit(uncore_pci_uncores);
kfree(uncore_extra_pci_dev);
uncore_extra_pci_dev = NULL;
uncore_free_pcibus_map();
err:
uncore_pci_uncores = empty_uncore;
return ret;
}
static void __init uncore_pci_exit(void)
{
if (pcidrv_registered) {
pcidrv_registered = false;
pci_unregister_driver(uncore_pci_driver);
uncore_types_exit(uncore_pci_uncores);
kfree(uncore_extra_pci_dev);
uncore_free_pcibus_map();
}
}
static void uncore_cpu_dying(int cpu)
{
struct intel_uncore_type *type, **types = uncore_msr_uncores;
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
int i, pkg;
pkg = topology_logical_package_id(cpu);
for (; *types; types++) {
type = *types;
pmu = type->pmus;
for (i = 0; i < type->num_boxes; i++, pmu++) {
box = pmu->boxes[pkg];
if (box && atomic_dec_return(&box->refcnt) == 0)
uncore_box_exit(box);
}
}
}
static void uncore_cpu_starting(int cpu, bool init)
{
struct intel_uncore_type *type, **types = uncore_msr_uncores;
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
int i, pkg, ncpus = 1;
if (init) {
ncpus = cpumask_weight(topology_core_cpumask(cpu));
}
pkg = topology_logical_package_id(cpu);
for (; *types; types++) {
type = *types;
pmu = type->pmus;
for (i = 0; i < type->num_boxes; i++, pmu++) {
box = pmu->boxes[pkg];
if (!box)
continue;
if (atomic_add_return(ncpus, &box->refcnt) == ncpus)
uncore_box_init(box);
}
}
}
static int uncore_cpu_prepare(int cpu)
{
struct intel_uncore_type *type, **types = uncore_msr_uncores;
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
int i, pkg;
pkg = topology_logical_package_id(cpu);
for (; *types; types++) {
type = *types;
pmu = type->pmus;
for (i = 0; i < type->num_boxes; i++, pmu++) {
if (pmu->boxes[pkg])
continue;
box = uncore_alloc_box(type, cpu_to_node(cpu));
if (!box)
return -ENOMEM;
box->pmu = pmu;
box->pkgid = pkg;
pmu->boxes[pkg] = box;
}
}
return 0;
}
static void uncore_change_type_ctx(struct intel_uncore_type *type, int old_cpu,
int new_cpu)
{
struct intel_uncore_pmu *pmu = type->pmus;
struct intel_uncore_box *box;
int i, pkg;
pkg = topology_logical_package_id(old_cpu < 0 ? new_cpu : old_cpu);
for (i = 0; i < type->num_boxes; i++, pmu++) {
box = pmu->boxes[pkg];
if (!box)
continue;
if (old_cpu < 0) {
WARN_ON_ONCE(box->cpu != -1);
box->cpu = new_cpu;
continue;
}
WARN_ON_ONCE(box->cpu != old_cpu);
box->cpu = -1;
if (new_cpu < 0)
continue;
uncore_pmu_cancel_hrtimer(box);
perf_pmu_migrate_context(&pmu->pmu, old_cpu, new_cpu);
box->cpu = new_cpu;
}
}
static void uncore_change_context(struct intel_uncore_type **uncores,
int old_cpu, int new_cpu)
{
for (; *uncores; uncores++)
uncore_change_type_ctx(*uncores, old_cpu, new_cpu);
}
static void uncore_event_exit_cpu(int cpu)
{
int target;
if (!cpumask_test_and_clear_cpu(cpu, &uncore_cpu_mask))
return;
target = cpumask_any_but(topology_core_cpumask(cpu), cpu);
if (target < nr_cpu_ids)
cpumask_set_cpu(target, &uncore_cpu_mask);
else
target = -1;
uncore_change_context(uncore_msr_uncores, cpu, target);
uncore_change_context(uncore_pci_uncores, cpu, target);
}
static void uncore_event_init_cpu(int cpu)
{
int target;
target = cpumask_any_and(&uncore_cpu_mask, topology_core_cpumask(cpu));
if (target < nr_cpu_ids)
return;
cpumask_set_cpu(cpu, &uncore_cpu_mask);
uncore_change_context(uncore_msr_uncores, -1, cpu);
uncore_change_context(uncore_pci_uncores, -1, cpu);
}
static int uncore_cpu_notifier(struct notifier_block *self,
unsigned long action, void *hcpu)
{
unsigned int cpu = (long)hcpu;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_UP_PREPARE:
return notifier_from_errno(uncore_cpu_prepare(cpu));
case CPU_STARTING:
uncore_cpu_starting(cpu, false);
case CPU_DOWN_FAILED:
uncore_event_init_cpu(cpu);
break;
case CPU_UP_CANCELED:
case CPU_DYING:
uncore_cpu_dying(cpu);
break;
case CPU_DOWN_PREPARE:
uncore_event_exit_cpu(cpu);
break;
}
return NOTIFY_OK;
}
static int __init type_pmu_register(struct intel_uncore_type *type)
{
int i, ret;
for (i = 0; i < type->num_boxes; i++) {
ret = uncore_pmu_register(&type->pmus[i]);
if (ret)
return ret;
}
return 0;
}
static int __init uncore_msr_pmus_register(void)
{
struct intel_uncore_type **types = uncore_msr_uncores;
int ret;
for (; *types; types++) {
ret = type_pmu_register(*types);
if (ret)
return ret;
}
return 0;
}
static int __init uncore_cpu_init(void)
{
int ret;
switch (boot_cpu_data.x86_model) {
case 26:
case 30:
case 37:
case 44:
nhm_uncore_cpu_init();
break;
case 42:
case 58:
case 60:
case 69:
case 70:
case 61:
case 71:
snb_uncore_cpu_init();
break;
case 45:
snbep_uncore_cpu_init();
break;
case 46:
case 47:
nhmex_uncore_cpu_init();
break;
case 62:
ivbep_uncore_cpu_init();
break;
case 63:
hswep_uncore_cpu_init();
break;
case 79:
case 86:
bdx_uncore_cpu_init();
break;
case 87:
knl_uncore_cpu_init();
break;
default:
return -ENODEV;
}
ret = uncore_types_init(uncore_msr_uncores, true);
if (ret)
goto err;
ret = uncore_msr_pmus_register();
if (ret)
goto err;
return 0;
err:
uncore_types_exit(uncore_msr_uncores);
uncore_msr_uncores = empty_uncore;
return ret;
}
static void __init uncore_cpu_setup(void *dummy)
{
uncore_cpu_starting(smp_processor_id(), true);
}
static int __init uncore_cpumask_init(bool msr)
{
unsigned int cpu;
for_each_online_cpu(cpu) {
unsigned int pkg = topology_logical_package_id(cpu);
int ret;
if (test_and_set_bit(pkg, packages))
continue;
if (msr) {
ret = uncore_cpu_prepare(cpu);
if (ret)
return ret;
}
uncore_event_init_cpu(cpu);
smp_call_function_single(cpu, uncore_cpu_setup, NULL, 1);
}
__register_cpu_notifier(&uncore_cpu_nb);
return 0;
}
static int __init intel_uncore_init(void)
{
int pret, cret, ret;
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
return -ENODEV;
if (cpu_has_hypervisor)
return -ENODEV;
max_packages = topology_max_packages();
pret = uncore_pci_init();
cret = uncore_cpu_init();
if (cret && pret)
return -ENODEV;
cpu_notifier_register_begin();
ret = uncore_cpumask_init(!cret);
if (ret)
goto err;
cpu_notifier_register_done();
return 0;
err:
on_each_cpu_mask(&uncore_cpu_mask, uncore_exit_boxes, NULL, 1);
uncore_types_exit(uncore_msr_uncores);
uncore_pci_exit();
cpu_notifier_register_done();
return ret;
}
