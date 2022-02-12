static unsigned int cbm_idx(struct rdt_resource *r, unsigned int closid)
{
return closid * r->cache.cbm_idx_mult + r->cache.cbm_idx_offset;
}
static inline void cache_alloc_hsw_probe(void)
{
struct rdt_resource *r = &rdt_resources_all[RDT_RESOURCE_L3];
u32 l, h, max_cbm = BIT_MASK(20) - 1;
if (wrmsr_safe(IA32_L3_CBM_BASE, max_cbm, 0))
return;
rdmsr(IA32_L3_CBM_BASE, l, h);
if (l != max_cbm)
return;
r->num_closid = 4;
r->default_ctrl = max_cbm;
r->cache.cbm_len = 20;
r->cache.shareable_bits = 0xc0000;
r->cache.min_cbm_bits = 2;
r->alloc_capable = true;
r->alloc_enabled = true;
rdt_alloc_capable = true;
}
static inline bool rdt_get_mb_table(struct rdt_resource *r)
{
pr_info("MBA b/w map not implemented for cpu:%d, model:%d",
boot_cpu_data.x86, boot_cpu_data.x86_model);
return false;
}
static bool rdt_get_mem_config(struct rdt_resource *r)
{
union cpuid_0x10_3_eax eax;
union cpuid_0x10_x_edx edx;
u32 ebx, ecx;
cpuid_count(0x00000010, 3, &eax.full, &ebx, &ecx, &edx.full);
r->num_closid = edx.split.cos_max + 1;
r->membw.max_delay = eax.split.max_delay + 1;
r->default_ctrl = MAX_MBA_BW;
if (ecx & MBA_IS_LINEAR) {
r->membw.delay_linear = true;
r->membw.min_bw = MAX_MBA_BW - r->membw.max_delay;
r->membw.bw_gran = MAX_MBA_BW - r->membw.max_delay;
} else {
if (!rdt_get_mb_table(r))
return false;
}
r->data_width = 3;
r->alloc_capable = true;
r->alloc_enabled = true;
return true;
}
static void rdt_get_cache_alloc_cfg(int idx, struct rdt_resource *r)
{
union cpuid_0x10_1_eax eax;
union cpuid_0x10_x_edx edx;
u32 ebx, ecx;
cpuid_count(0x00000010, idx, &eax.full, &ebx, &ecx, &edx.full);
r->num_closid = edx.split.cos_max + 1;
r->cache.cbm_len = eax.split.cbm_len + 1;
r->default_ctrl = BIT_MASK(eax.split.cbm_len + 1) - 1;
r->cache.shareable_bits = ebx & r->default_ctrl;
r->data_width = (r->cache.cbm_len + 3) / 4;
r->alloc_capable = true;
r->alloc_enabled = true;
}
static void rdt_get_cdp_l3_config(int type)
{
struct rdt_resource *r_l3 = &rdt_resources_all[RDT_RESOURCE_L3];
struct rdt_resource *r = &rdt_resources_all[type];
r->num_closid = r_l3->num_closid / 2;
r->cache.cbm_len = r_l3->cache.cbm_len;
r->default_ctrl = r_l3->default_ctrl;
r->data_width = (r->cache.cbm_len + 3) / 4;
r->alloc_capable = true;
r->alloc_enabled = false;
}
static int get_cache_id(int cpu, int level)
{
struct cpu_cacheinfo *ci = get_cpu_cacheinfo(cpu);
int i;
for (i = 0; i < ci->num_leaves; i++) {
if (ci->info_list[i].level == level)
return ci->info_list[i].id;
}
return -1;
}
static u32 delay_bw_map(unsigned long bw, struct rdt_resource *r)
{
if (r->membw.delay_linear)
return MAX_MBA_BW - bw;
pr_warn_once("Non Linear delay-bw map not supported but queried\n");
return r->default_ctrl;
}
static void
mba_wrmsr(struct rdt_domain *d, struct msr_param *m, struct rdt_resource *r)
{
unsigned int i;
for (i = m->low; i < m->high; i++)
wrmsrl(r->msr_base + i, delay_bw_map(d->ctrl_val[i], r));
}
static void
cat_wrmsr(struct rdt_domain *d, struct msr_param *m, struct rdt_resource *r)
{
unsigned int i;
for (i = m->low; i < m->high; i++)
wrmsrl(r->msr_base + cbm_idx(r, i), d->ctrl_val[i]);
}
struct rdt_domain *get_domain_from_cpu(int cpu, struct rdt_resource *r)
{
struct rdt_domain *d;
list_for_each_entry(d, &r->domains, list) {
if (cpumask_test_cpu(cpu, &d->cpu_mask))
return d;
}
return NULL;
}
void rdt_ctrl_update(void *arg)
{
struct msr_param *m = arg;
struct rdt_resource *r = m->res;
int cpu = smp_processor_id();
struct rdt_domain *d;
d = get_domain_from_cpu(cpu, r);
if (d) {
r->msr_update(d, m, r);
return;
}
pr_warn_once("cpu %d not found in any domain for resource %s\n",
cpu, r->name);
}
struct rdt_domain *rdt_find_domain(struct rdt_resource *r, int id,
struct list_head **pos)
{
struct rdt_domain *d;
struct list_head *l;
if (id < 0)
return ERR_PTR(id);
list_for_each(l, &r->domains) {
d = list_entry(l, struct rdt_domain, list);
if (id == d->id)
return d;
if (id < d->id)
break;
}
if (pos)
*pos = l;
return NULL;
}
static int domain_setup_ctrlval(struct rdt_resource *r, struct rdt_domain *d)
{
struct msr_param m;
u32 *dc;
int i;
dc = kmalloc_array(r->num_closid, sizeof(*d->ctrl_val), GFP_KERNEL);
if (!dc)
return -ENOMEM;
d->ctrl_val = dc;
for (i = 0; i < r->num_closid; i++, dc++)
*dc = r->default_ctrl;
m.low = 0;
m.high = r->num_closid;
r->msr_update(d, &m, r);
return 0;
}
static int domain_setup_mon_state(struct rdt_resource *r, struct rdt_domain *d)
{
size_t tsize;
if (is_llc_occupancy_enabled()) {
d->rmid_busy_llc = kcalloc(BITS_TO_LONGS(r->num_rmid),
sizeof(unsigned long),
GFP_KERNEL);
if (!d->rmid_busy_llc)
return -ENOMEM;
INIT_DELAYED_WORK(&d->cqm_limbo, cqm_handle_limbo);
}
if (is_mbm_total_enabled()) {
tsize = sizeof(*d->mbm_total);
d->mbm_total = kcalloc(r->num_rmid, tsize, GFP_KERNEL);
if (!d->mbm_total) {
kfree(d->rmid_busy_llc);
return -ENOMEM;
}
}
if (is_mbm_local_enabled()) {
tsize = sizeof(*d->mbm_local);
d->mbm_local = kcalloc(r->num_rmid, tsize, GFP_KERNEL);
if (!d->mbm_local) {
kfree(d->rmid_busy_llc);
kfree(d->mbm_total);
return -ENOMEM;
}
}
if (is_mbm_enabled()) {
INIT_DELAYED_WORK(&d->mbm_over, mbm_handle_overflow);
mbm_setup_overflow_handler(d, MBM_OVERFLOW_INTERVAL);
}
return 0;
}
static void domain_add_cpu(int cpu, struct rdt_resource *r)
{
int id = get_cache_id(cpu, r->cache_level);
struct list_head *add_pos = NULL;
struct rdt_domain *d;
d = rdt_find_domain(r, id, &add_pos);
if (IS_ERR(d)) {
pr_warn("Could't find cache id for cpu %d\n", cpu);
return;
}
if (d) {
cpumask_set_cpu(cpu, &d->cpu_mask);
return;
}
d = kzalloc_node(sizeof(*d), GFP_KERNEL, cpu_to_node(cpu));
if (!d)
return;
d->id = id;
cpumask_set_cpu(cpu, &d->cpu_mask);
if (r->alloc_capable && domain_setup_ctrlval(r, d)) {
kfree(d);
return;
}
if (r->mon_capable && domain_setup_mon_state(r, d)) {
kfree(d);
return;
}
list_add_tail(&d->list, add_pos);
if (static_branch_unlikely(&rdt_mon_enable_key))
mkdir_mondata_subdir_allrdtgrp(r, d);
}
static void domain_remove_cpu(int cpu, struct rdt_resource *r)
{
int id = get_cache_id(cpu, r->cache_level);
struct rdt_domain *d;
d = rdt_find_domain(r, id, NULL);
if (IS_ERR_OR_NULL(d)) {
pr_warn("Could't find cache id for cpu %d\n", cpu);
return;
}
cpumask_clear_cpu(cpu, &d->cpu_mask);
if (cpumask_empty(&d->cpu_mask)) {
if (static_branch_unlikely(&rdt_mon_enable_key))
rmdir_mondata_subdir_allrdtgrp(r, d->id);
kfree(d->ctrl_val);
kfree(d->rmid_busy_llc);
kfree(d->mbm_total);
kfree(d->mbm_local);
list_del(&d->list);
if (is_mbm_enabled())
cancel_delayed_work(&d->mbm_over);
if (is_llc_occupancy_enabled() && has_busy_rmid(r, d)) {
__check_limbo(d, true);
cancel_delayed_work(&d->cqm_limbo);
}
kfree(d);
return;
}
if (r == &rdt_resources_all[RDT_RESOURCE_L3]) {
if (is_mbm_enabled() && cpu == d->mbm_work_cpu) {
cancel_delayed_work(&d->mbm_over);
mbm_setup_overflow_handler(d, 0);
}
if (is_llc_occupancy_enabled() && cpu == d->cqm_work_cpu &&
has_busy_rmid(r, d)) {
cancel_delayed_work(&d->cqm_limbo);
cqm_setup_limbo_handler(d, 0);
}
}
}
static void clear_closid_rmid(int cpu)
{
struct intel_pqr_state *state = this_cpu_ptr(&pqr_state);
state->default_closid = 0;
state->default_rmid = 0;
state->cur_closid = 0;
state->cur_rmid = 0;
wrmsr(IA32_PQR_ASSOC, 0, 0);
}
static int intel_rdt_online_cpu(unsigned int cpu)
{
struct rdt_resource *r;
mutex_lock(&rdtgroup_mutex);
for_each_capable_rdt_resource(r)
domain_add_cpu(cpu, r);
cpumask_set_cpu(cpu, &rdtgroup_default.cpu_mask);
clear_closid_rmid(cpu);
mutex_unlock(&rdtgroup_mutex);
return 0;
}
static void clear_childcpus(struct rdtgroup *r, unsigned int cpu)
{
struct rdtgroup *cr;
list_for_each_entry(cr, &r->mon.crdtgrp_list, mon.crdtgrp_list) {
if (cpumask_test_and_clear_cpu(cpu, &cr->cpu_mask)) {
break;
}
}
}
static int intel_rdt_offline_cpu(unsigned int cpu)
{
struct rdtgroup *rdtgrp;
struct rdt_resource *r;
mutex_lock(&rdtgroup_mutex);
for_each_capable_rdt_resource(r)
domain_remove_cpu(cpu, r);
list_for_each_entry(rdtgrp, &rdt_all_groups, rdtgroup_list) {
if (cpumask_test_and_clear_cpu(cpu, &rdtgrp->cpu_mask)) {
clear_childcpus(rdtgrp, cpu);
break;
}
}
clear_closid_rmid(cpu);
mutex_unlock(&rdtgroup_mutex);
return 0;
}
static __init void rdt_init_padding(void)
{
struct rdt_resource *r;
int cl;
for_each_alloc_capable_rdt_resource(r) {
cl = strlen(r->name);
if (cl > max_name_width)
max_name_width = cl;
if (r->data_width > max_data_width)
max_data_width = r->data_width;
}
}
static int __init set_rdt_options(char *str)
{
struct rdt_options *o;
bool force_off;
char *tok;
if (*str == '=')
str++;
while ((tok = strsep(&str, ",")) != NULL) {
force_off = *tok == '!';
if (force_off)
tok++;
for (o = rdt_options; o < &rdt_options[NUM_RDT_OPTIONS]; o++) {
if (strcmp(tok, o->name) == 0) {
if (force_off)
o->force_off = true;
else
o->force_on = true;
break;
}
}
}
return 1;
}
static bool __init rdt_cpu_has(int flag)
{
bool ret = boot_cpu_has(flag);
struct rdt_options *o;
if (!ret)
return ret;
for (o = rdt_options; o < &rdt_options[NUM_RDT_OPTIONS]; o++) {
if (flag == o->flag) {
if (o->force_off)
ret = false;
if (o->force_on)
ret = true;
break;
}
}
return ret;
}
static __init bool get_rdt_alloc_resources(void)
{
bool ret = false;
if (rdt_alloc_capable)
return true;
if (!boot_cpu_has(X86_FEATURE_RDT_A))
return false;
if (rdt_cpu_has(X86_FEATURE_CAT_L3)) {
rdt_get_cache_alloc_cfg(1, &rdt_resources_all[RDT_RESOURCE_L3]);
if (rdt_cpu_has(X86_FEATURE_CDP_L3)) {
rdt_get_cdp_l3_config(RDT_RESOURCE_L3DATA);
rdt_get_cdp_l3_config(RDT_RESOURCE_L3CODE);
}
ret = true;
}
if (rdt_cpu_has(X86_FEATURE_CAT_L2)) {
rdt_get_cache_alloc_cfg(2, &rdt_resources_all[RDT_RESOURCE_L2]);
ret = true;
}
if (rdt_cpu_has(X86_FEATURE_MBA)) {
if (rdt_get_mem_config(&rdt_resources_all[RDT_RESOURCE_MBA]))
ret = true;
}
return ret;
}
static __init bool get_rdt_mon_resources(void)
{
if (rdt_cpu_has(X86_FEATURE_CQM_OCCUP_LLC))
rdt_mon_features |= (1 << QOS_L3_OCCUP_EVENT_ID);
if (rdt_cpu_has(X86_FEATURE_CQM_MBM_TOTAL))
rdt_mon_features |= (1 << QOS_L3_MBM_TOTAL_EVENT_ID);
if (rdt_cpu_has(X86_FEATURE_CQM_MBM_LOCAL))
rdt_mon_features |= (1 << QOS_L3_MBM_LOCAL_EVENT_ID);
if (!rdt_mon_features)
return false;
return !rdt_get_mon_l3_config(&rdt_resources_all[RDT_RESOURCE_L3]);
}
static __init void rdt_quirks(void)
{
switch (boot_cpu_data.x86_model) {
case INTEL_FAM6_HASWELL_X:
if (!rdt_options[RDT_FLAG_L3_CAT].force_off)
cache_alloc_hsw_probe();
break;
case INTEL_FAM6_SKYLAKE_X:
if (boot_cpu_data.x86_mask <= 4)
set_rdt_options("!cmt,!mbmtotal,!mbmlocal,!l3cat");
}
}
static __init bool get_rdt_resources(void)
{
rdt_quirks();
rdt_alloc_capable = get_rdt_alloc_resources();
rdt_mon_capable = get_rdt_mon_resources();
return (rdt_mon_capable || rdt_alloc_capable);
}
static int __init intel_rdt_late_init(void)
{
struct rdt_resource *r;
int state, ret;
if (!get_rdt_resources())
return -ENODEV;
rdt_init_padding();
state = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN,
"x86/rdt/cat:online:",
intel_rdt_online_cpu, intel_rdt_offline_cpu);
if (state < 0)
return state;
ret = rdtgroup_init();
if (ret) {
cpuhp_remove_state(state);
return ret;
}
for_each_alloc_capable_rdt_resource(r)
pr_info("Intel RDT %s allocation detected\n", r->name);
for_each_mon_capable_rdt_resource(r)
pr_info("Intel RDT %s monitoring detected\n", r->name);
return 0;
}
