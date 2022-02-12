static inline struct rmid_entry *__rmid_entry(u32 rmid)
{
struct rmid_entry *entry;
entry = &rmid_ptrs[rmid];
WARN_ON(entry->rmid != rmid);
return entry;
}
static u64 __rmid_read(u32 rmid, u32 eventid)
{
u64 val;
wrmsr(MSR_IA32_QM_EVTSEL, eventid, rmid);
rdmsrl(MSR_IA32_QM_CTR, val);
return val;
}
static bool rmid_dirty(struct rmid_entry *entry)
{
u64 val = __rmid_read(entry->rmid, QOS_L3_OCCUP_EVENT_ID);
return val >= intel_cqm_threshold;
}
void __check_limbo(struct rdt_domain *d, bool force_free)
{
struct rmid_entry *entry;
struct rdt_resource *r;
u32 crmid = 1, nrmid;
r = &rdt_resources_all[RDT_RESOURCE_L3];
for (;;) {
nrmid = find_next_bit(d->rmid_busy_llc, r->num_rmid, crmid);
if (nrmid >= r->num_rmid)
break;
entry = __rmid_entry(nrmid);
if (force_free || !rmid_dirty(entry)) {
clear_bit(entry->rmid, d->rmid_busy_llc);
if (!--entry->busy) {
rmid_limbo_count--;
list_add_tail(&entry->list, &rmid_free_lru);
}
}
crmid = nrmid + 1;
}
}
bool has_busy_rmid(struct rdt_resource *r, struct rdt_domain *d)
{
return find_first_bit(d->rmid_busy_llc, r->num_rmid) != r->num_rmid;
}
int alloc_rmid(void)
{
struct rmid_entry *entry;
lockdep_assert_held(&rdtgroup_mutex);
if (list_empty(&rmid_free_lru))
return rmid_limbo_count ? -EBUSY : -ENOSPC;
entry = list_first_entry(&rmid_free_lru,
struct rmid_entry, list);
list_del(&entry->list);
return entry->rmid;
}
static void add_rmid_to_limbo(struct rmid_entry *entry)
{
struct rdt_resource *r;
struct rdt_domain *d;
int cpu;
u64 val;
r = &rdt_resources_all[RDT_RESOURCE_L3];
entry->busy = 0;
cpu = get_cpu();
list_for_each_entry(d, &r->domains, list) {
if (cpumask_test_cpu(cpu, &d->cpu_mask)) {
val = __rmid_read(entry->rmid, QOS_L3_OCCUP_EVENT_ID);
if (val <= intel_cqm_threshold)
continue;
}
if (!has_busy_rmid(r, d))
cqm_setup_limbo_handler(d, CQM_LIMBOCHECK_INTERVAL);
set_bit(entry->rmid, d->rmid_busy_llc);
entry->busy++;
}
put_cpu();
if (entry->busy)
rmid_limbo_count++;
else
list_add_tail(&entry->list, &rmid_free_lru);
}
void free_rmid(u32 rmid)
{
struct rmid_entry *entry;
if (!rmid)
return;
lockdep_assert_held(&rdtgroup_mutex);
entry = __rmid_entry(rmid);
if (is_llc_occupancy_enabled())
add_rmid_to_limbo(entry);
else
list_add_tail(&entry->list, &rmid_free_lru);
}
static int __mon_event_count(u32 rmid, struct rmid_read *rr)
{
u64 chunks, shift, tval;
struct mbm_state *m;
tval = __rmid_read(rmid, rr->evtid);
if (tval & (RMID_VAL_ERROR | RMID_VAL_UNAVAIL)) {
rr->val = tval;
return -EINVAL;
}
switch (rr->evtid) {
case QOS_L3_OCCUP_EVENT_ID:
rr->val += tval;
return 0;
case QOS_L3_MBM_TOTAL_EVENT_ID:
m = &rr->d->mbm_total[rmid];
break;
case QOS_L3_MBM_LOCAL_EVENT_ID:
m = &rr->d->mbm_local[rmid];
break;
default:
return -EINVAL;
}
if (rr->first) {
m->prev_msr = tval;
m->chunks = 0;
return 0;
}
shift = 64 - MBM_CNTR_WIDTH;
chunks = (tval << shift) - (m->prev_msr << shift);
chunks >>= shift;
m->chunks += chunks;
m->prev_msr = tval;
rr->val += m->chunks;
return 0;
}
void mon_event_count(void *info)
{
struct rdtgroup *rdtgrp, *entry;
struct rmid_read *rr = info;
struct list_head *head;
rdtgrp = rr->rgrp;
if (__mon_event_count(rdtgrp->mon.rmid, rr))
return;
head = &rdtgrp->mon.crdtgrp_list;
if (rdtgrp->type == RDTCTRL_GROUP) {
list_for_each_entry(entry, head, mon.crdtgrp_list) {
if (__mon_event_count(entry->mon.rmid, rr))
return;
}
}
}
static void mbm_update(struct rdt_domain *d, int rmid)
{
struct rmid_read rr;
rr.first = false;
rr.d = d;
if (is_mbm_total_enabled()) {
rr.evtid = QOS_L3_MBM_TOTAL_EVENT_ID;
__mon_event_count(rmid, &rr);
}
if (is_mbm_local_enabled()) {
rr.evtid = QOS_L3_MBM_LOCAL_EVENT_ID;
__mon_event_count(rmid, &rr);
}
}
void cqm_handle_limbo(struct work_struct *work)
{
unsigned long delay = msecs_to_jiffies(CQM_LIMBOCHECK_INTERVAL);
int cpu = smp_processor_id();
struct rdt_resource *r;
struct rdt_domain *d;
mutex_lock(&rdtgroup_mutex);
r = &rdt_resources_all[RDT_RESOURCE_L3];
d = get_domain_from_cpu(cpu, r);
if (!d) {
pr_warn_once("Failure to get domain for limbo worker\n");
goto out_unlock;
}
__check_limbo(d, false);
if (has_busy_rmid(r, d))
schedule_delayed_work_on(cpu, &d->cqm_limbo, delay);
out_unlock:
mutex_unlock(&rdtgroup_mutex);
}
void cqm_setup_limbo_handler(struct rdt_domain *dom, unsigned long delay_ms)
{
unsigned long delay = msecs_to_jiffies(delay_ms);
struct rdt_resource *r;
int cpu;
r = &rdt_resources_all[RDT_RESOURCE_L3];
cpu = cpumask_any(&dom->cpu_mask);
dom->cqm_work_cpu = cpu;
schedule_delayed_work_on(cpu, &dom->cqm_limbo, delay);
}
void mbm_handle_overflow(struct work_struct *work)
{
unsigned long delay = msecs_to_jiffies(MBM_OVERFLOW_INTERVAL);
struct rdtgroup *prgrp, *crgrp;
int cpu = smp_processor_id();
struct list_head *head;
struct rdt_domain *d;
mutex_lock(&rdtgroup_mutex);
if (!static_branch_likely(&rdt_enable_key))
goto out_unlock;
d = get_domain_from_cpu(cpu, &rdt_resources_all[RDT_RESOURCE_L3]);
if (!d)
goto out_unlock;
list_for_each_entry(prgrp, &rdt_all_groups, rdtgroup_list) {
mbm_update(d, prgrp->mon.rmid);
head = &prgrp->mon.crdtgrp_list;
list_for_each_entry(crgrp, head, mon.crdtgrp_list)
mbm_update(d, crgrp->mon.rmid);
}
schedule_delayed_work_on(cpu, &d->mbm_over, delay);
out_unlock:
mutex_unlock(&rdtgroup_mutex);
}
void mbm_setup_overflow_handler(struct rdt_domain *dom, unsigned long delay_ms)
{
unsigned long delay = msecs_to_jiffies(delay_ms);
int cpu;
if (!static_branch_likely(&rdt_enable_key))
return;
cpu = cpumask_any(&dom->cpu_mask);
dom->mbm_work_cpu = cpu;
schedule_delayed_work_on(cpu, &dom->mbm_over, delay);
}
static int dom_data_init(struct rdt_resource *r)
{
struct rmid_entry *entry = NULL;
int i, nr_rmids;
nr_rmids = r->num_rmid;
rmid_ptrs = kcalloc(nr_rmids, sizeof(struct rmid_entry), GFP_KERNEL);
if (!rmid_ptrs)
return -ENOMEM;
for (i = 0; i < nr_rmids; i++) {
entry = &rmid_ptrs[i];
INIT_LIST_HEAD(&entry->list);
entry->rmid = i;
list_add_tail(&entry->list, &rmid_free_lru);
}
entry = __rmid_entry(0);
list_del(&entry->list);
return 0;
}
static void l3_mon_evt_init(struct rdt_resource *r)
{
INIT_LIST_HEAD(&r->evt_list);
if (is_llc_occupancy_enabled())
list_add_tail(&llc_occupancy_event.list, &r->evt_list);
if (is_mbm_total_enabled())
list_add_tail(&mbm_total_event.list, &r->evt_list);
if (is_mbm_local_enabled())
list_add_tail(&mbm_local_event.list, &r->evt_list);
}
int rdt_get_mon_l3_config(struct rdt_resource *r)
{
int ret;
r->mon_scale = boot_cpu_data.x86_cache_occ_scale;
r->num_rmid = boot_cpu_data.x86_cache_max_rmid + 1;
intel_cqm_threshold = boot_cpu_data.x86_cache_size * 1024 / r->num_rmid;
intel_cqm_threshold /= r->mon_scale;
ret = dom_data_init(r);
if (ret)
return ret;
l3_mon_evt_init(r);
r->mon_capable = true;
r->mon_enabled = true;
return 0;
}
