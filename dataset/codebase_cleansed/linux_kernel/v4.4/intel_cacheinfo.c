static void
amd_cpuid4(int leaf, union _cpuid4_leaf_eax *eax,
union _cpuid4_leaf_ebx *ebx,
union _cpuid4_leaf_ecx *ecx)
{
unsigned dummy;
unsigned line_size, lines_per_tag, assoc, size_in_kb;
union l1_cache l1i, l1d;
union l2_cache l2;
union l3_cache l3;
union l1_cache *l1 = &l1d;
eax->full = 0;
ebx->full = 0;
ecx->full = 0;
cpuid(0x80000005, &dummy, &dummy, &l1d.val, &l1i.val);
cpuid(0x80000006, &dummy, &dummy, &l2.val, &l3.val);
switch (leaf) {
case 1:
l1 = &l1i;
case 0:
if (!l1->val)
return;
assoc = assocs[l1->assoc];
line_size = l1->line_size;
lines_per_tag = l1->lines_per_tag;
size_in_kb = l1->size_in_kb;
break;
case 2:
if (!l2.val)
return;
assoc = assocs[l2.assoc];
line_size = l2.line_size;
lines_per_tag = l2.lines_per_tag;
size_in_kb = __this_cpu_read(cpu_info.x86_cache_size);
break;
case 3:
if (!l3.val)
return;
assoc = assocs[l3.assoc];
line_size = l3.line_size;
lines_per_tag = l3.lines_per_tag;
size_in_kb = l3.size_encoded * 512;
if (boot_cpu_has(X86_FEATURE_AMD_DCM)) {
size_in_kb = size_in_kb >> 1;
assoc = assoc >> 1;
}
break;
default:
return;
}
eax->split.is_self_initializing = 1;
eax->split.type = types[leaf];
eax->split.level = levels[leaf];
eax->split.num_threads_sharing = 0;
eax->split.num_cores_on_die = __this_cpu_read(cpu_info.x86_max_cores) - 1;
if (assoc == 0xffff)
eax->split.is_fully_associative = 1;
ebx->split.coherency_line_size = line_size - 1;
ebx->split.ways_of_associativity = assoc - 1;
ebx->split.physical_line_partition = lines_per_tag - 1;
ecx->split.number_of_sets = (size_in_kb * 1024) / line_size /
(ebx->split.ways_of_associativity + 1) - 1;
}
static void amd_calc_l3_indices(struct amd_northbridge *nb)
{
struct amd_l3_cache *l3 = &nb->l3_cache;
unsigned int sc0, sc1, sc2, sc3;
u32 val = 0;
pci_read_config_dword(nb->misc, 0x1C4, &val);
l3->subcaches[0] = sc0 = !(val & BIT(0));
l3->subcaches[1] = sc1 = !(val & BIT(4));
if (boot_cpu_data.x86 == 0x15) {
l3->subcaches[0] = sc0 += !(val & BIT(1));
l3->subcaches[1] = sc1 += !(val & BIT(5));
}
l3->subcaches[2] = sc2 = !(val & BIT(8)) + !(val & BIT(9));
l3->subcaches[3] = sc3 = !(val & BIT(12)) + !(val & BIT(13));
l3->indices = (max(max3(sc0, sc1, sc2), sc3) << 10) - 1;
}
static int amd_get_l3_disable_slot(struct amd_northbridge *nb, unsigned slot)
{
unsigned int reg = 0;
pci_read_config_dword(nb->misc, 0x1BC + slot * 4, &reg);
if (reg & (3UL << 30))
return reg & 0xfff;
return -1;
}
static ssize_t show_cache_disable(struct cacheinfo *this_leaf, char *buf,
unsigned int slot)
{
int index;
struct amd_northbridge *nb = this_leaf->priv;
index = amd_get_l3_disable_slot(nb, slot);
if (index >= 0)
return sprintf(buf, "%d\n", index);
return sprintf(buf, "FREE\n");
}
static void amd_l3_disable_index(struct amd_northbridge *nb, int cpu,
unsigned slot, unsigned long idx)
{
int i;
idx |= BIT(30);
for (i = 0; i < 4; i++) {
u32 reg = idx | (i << 20);
if (!nb->l3_cache.subcaches[i])
continue;
pci_write_config_dword(nb->misc, 0x1BC + slot * 4, reg);
wbinvd_on_cpu(cpu);
reg |= BIT(31);
pci_write_config_dword(nb->misc, 0x1BC + slot * 4, reg);
}
}
static int amd_set_l3_disable_slot(struct amd_northbridge *nb, int cpu,
unsigned slot, unsigned long index)
{
int ret = 0;
ret = amd_get_l3_disable_slot(nb, slot);
if (ret >= 0)
return -EEXIST;
if (index > nb->l3_cache.indices)
return -EINVAL;
if (index == amd_get_l3_disable_slot(nb, !slot))
return -EEXIST;
amd_l3_disable_index(nb, cpu, slot, index);
return 0;
}
static ssize_t store_cache_disable(struct cacheinfo *this_leaf,
const char *buf, size_t count,
unsigned int slot)
{
unsigned long val = 0;
int cpu, err = 0;
struct amd_northbridge *nb = this_leaf->priv;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
cpu = cpumask_first(&this_leaf->shared_cpu_map);
if (kstrtoul(buf, 10, &val) < 0)
return -EINVAL;
err = amd_set_l3_disable_slot(nb, cpu, slot, val);
if (err) {
if (err == -EEXIST)
pr_warning("L3 slot %d in use/index already disabled!\n",
slot);
return err;
}
return count;
}
static ssize_t subcaches_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct cacheinfo *this_leaf = dev_get_drvdata(dev);
int cpu = cpumask_first(&this_leaf->shared_cpu_map);
return sprintf(buf, "%x\n", amd_get_subcaches(cpu));
}
static ssize_t subcaches_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cacheinfo *this_leaf = dev_get_drvdata(dev);
int cpu = cpumask_first(&this_leaf->shared_cpu_map);
unsigned long val;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (kstrtoul(buf, 16, &val) < 0)
return -EINVAL;
if (amd_set_subcaches(cpu, val))
return -EINVAL;
return count;
}
static umode_t
cache_private_attrs_is_visible(struct kobject *kobj,
struct attribute *attr, int unused)
{
struct device *dev = kobj_to_dev(kobj);
struct cacheinfo *this_leaf = dev_get_drvdata(dev);
umode_t mode = attr->mode;
if (!this_leaf->priv)
return 0;
if ((attr == &dev_attr_subcaches.attr) &&
amd_nb_has_feature(AMD_NB_L3_PARTITIONING))
return mode;
if ((attr == &dev_attr_cache_disable_0.attr ||
attr == &dev_attr_cache_disable_1.attr) &&
amd_nb_has_feature(AMD_NB_L3_INDEX_DISABLE))
return mode;
return 0;
}
static void init_amd_l3_attrs(void)
{
int n = 1;
static struct attribute **amd_l3_attrs;
if (amd_l3_attrs)
return;
if (amd_nb_has_feature(AMD_NB_L3_INDEX_DISABLE))
n += 2;
if (amd_nb_has_feature(AMD_NB_L3_PARTITIONING))
n += 1;
amd_l3_attrs = kcalloc(n, sizeof(*amd_l3_attrs), GFP_KERNEL);
if (!amd_l3_attrs)
return;
n = 0;
if (amd_nb_has_feature(AMD_NB_L3_INDEX_DISABLE)) {
amd_l3_attrs[n++] = &dev_attr_cache_disable_0.attr;
amd_l3_attrs[n++] = &dev_attr_cache_disable_1.attr;
}
if (amd_nb_has_feature(AMD_NB_L3_PARTITIONING))
amd_l3_attrs[n++] = &dev_attr_subcaches.attr;
cache_private_group.attrs = amd_l3_attrs;
}
const struct attribute_group *
cache_get_priv_group(struct cacheinfo *this_leaf)
{
struct amd_northbridge *nb = this_leaf->priv;
if (this_leaf->level < 3 || !nb)
return NULL;
if (nb && nb->l3_cache.indices)
init_amd_l3_attrs();
return &cache_private_group;
}
static void amd_init_l3_cache(struct _cpuid4_info_regs *this_leaf, int index)
{
int node;
if (index < 3)
return;
node = amd_get_nb_id(smp_processor_id());
this_leaf->nb = node_to_amd_nb(node);
if (this_leaf->nb && !this_leaf->nb->l3_cache.indices)
amd_calc_l3_indices(this_leaf->nb);
}
static int
cpuid4_cache_lookup_regs(int index, struct _cpuid4_info_regs *this_leaf)
{
union _cpuid4_leaf_eax eax;
union _cpuid4_leaf_ebx ebx;
union _cpuid4_leaf_ecx ecx;
unsigned edx;
if (boot_cpu_data.x86_vendor == X86_VENDOR_AMD) {
if (cpu_has_topoext)
cpuid_count(0x8000001d, index, &eax.full,
&ebx.full, &ecx.full, &edx);
else
amd_cpuid4(index, &eax, &ebx, &ecx);
amd_init_l3_cache(this_leaf, index);
} else {
cpuid_count(4, index, &eax.full, &ebx.full, &ecx.full, &edx);
}
if (eax.split.type == CTYPE_NULL)
return -EIO;
this_leaf->eax = eax;
this_leaf->ebx = ebx;
this_leaf->ecx = ecx;
this_leaf->size = (ecx.split.number_of_sets + 1) *
(ebx.split.coherency_line_size + 1) *
(ebx.split.physical_line_partition + 1) *
(ebx.split.ways_of_associativity + 1);
return 0;
}
static int find_num_cache_leaves(struct cpuinfo_x86 *c)
{
unsigned int eax, ebx, ecx, edx, op;
union _cpuid4_leaf_eax cache_eax;
int i = -1;
if (c->x86_vendor == X86_VENDOR_AMD)
op = 0x8000001d;
else
op = 4;
do {
++i;
cpuid_count(op, i, &eax, &ebx, &ecx, &edx);
cache_eax.full = eax;
} while (cache_eax.split.type != CTYPE_NULL);
return i;
}
void init_amd_cacheinfo(struct cpuinfo_x86 *c)
{
if (cpu_has_topoext) {
num_cache_leaves = find_num_cache_leaves(c);
} else if (c->extended_cpuid_level >= 0x80000006) {
if (cpuid_edx(0x80000006) & 0xf000)
num_cache_leaves = 4;
else
num_cache_leaves = 3;
}
}
unsigned int init_intel_cacheinfo(struct cpuinfo_x86 *c)
{
unsigned int trace = 0, l1i = 0, l1d = 0, l2 = 0, l3 = 0;
unsigned int new_l1d = 0, new_l1i = 0;
unsigned int new_l2 = 0, new_l3 = 0, i;
unsigned int l2_id = 0, l3_id = 0, num_threads_sharing, index_msb;
#ifdef CONFIG_SMP
unsigned int cpu = c->cpu_index;
#endif
if (c->cpuid_level > 3) {
static int is_initialized;
if (is_initialized == 0) {
num_cache_leaves = find_num_cache_leaves(c);
is_initialized++;
}
for (i = 0; i < num_cache_leaves; i++) {
struct _cpuid4_info_regs this_leaf = {};
int retval;
retval = cpuid4_cache_lookup_regs(i, &this_leaf);
if (retval < 0)
continue;
switch (this_leaf.eax.split.level) {
case 1:
if (this_leaf.eax.split.type == CTYPE_DATA)
new_l1d = this_leaf.size/1024;
else if (this_leaf.eax.split.type == CTYPE_INST)
new_l1i = this_leaf.size/1024;
break;
case 2:
new_l2 = this_leaf.size/1024;
num_threads_sharing = 1 + this_leaf.eax.split.num_threads_sharing;
index_msb = get_count_order(num_threads_sharing);
l2_id = c->apicid & ~((1 << index_msb) - 1);
break;
case 3:
new_l3 = this_leaf.size/1024;
num_threads_sharing = 1 + this_leaf.eax.split.num_threads_sharing;
index_msb = get_count_order(num_threads_sharing);
l3_id = c->apicid & ~((1 << index_msb) - 1);
break;
default:
break;
}
}
}
if ((num_cache_leaves == 0 || c->x86 == 15) && c->cpuid_level > 1) {
int j, n;
unsigned int regs[4];
unsigned char *dp = (unsigned char *)regs;
int only_trace = 0;
if (num_cache_leaves != 0 && c->x86 == 15)
only_trace = 1;
n = cpuid_eax(2) & 0xFF;
for (i = 0 ; i < n ; i++) {
cpuid(2, &regs[0], &regs[1], &regs[2], &regs[3]);
for (j = 0 ; j < 3 ; j++)
if (regs[j] & (1 << 31))
regs[j] = 0;
for (j = 1 ; j < 16 ; j++) {
unsigned char des = dp[j];
unsigned char k = 0;
while (cache_table[k].descriptor != 0) {
if (cache_table[k].descriptor == des) {
if (only_trace && cache_table[k].cache_type != LVL_TRACE)
break;
switch (cache_table[k].cache_type) {
case LVL_1_INST:
l1i += cache_table[k].size;
break;
case LVL_1_DATA:
l1d += cache_table[k].size;
break;
case LVL_2:
l2 += cache_table[k].size;
break;
case LVL_3:
l3 += cache_table[k].size;
break;
case LVL_TRACE:
trace += cache_table[k].size;
break;
}
break;
}
k++;
}
}
}
}
if (new_l1d)
l1d = new_l1d;
if (new_l1i)
l1i = new_l1i;
if (new_l2) {
l2 = new_l2;
#ifdef CONFIG_SMP
per_cpu(cpu_llc_id, cpu) = l2_id;
#endif
}
if (new_l3) {
l3 = new_l3;
#ifdef CONFIG_SMP
per_cpu(cpu_llc_id, cpu) = l3_id;
#endif
}
#ifdef CONFIG_SMP
if (per_cpu(cpu_llc_id, cpu) == BAD_APICID)
per_cpu(cpu_llc_id, cpu) = c->phys_proc_id;
#endif
c->x86_cache_size = l3 ? l3 : (l2 ? l2 : (l1i+l1d));
return l2;
}
static int __cache_amd_cpumap_setup(unsigned int cpu, int index,
struct _cpuid4_info_regs *base)
{
struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
struct cacheinfo *this_leaf;
int i, sibling;
if (cpu_has_topoext) {
unsigned int apicid, nshared, first, last;
this_leaf = this_cpu_ci->info_list + index;
nshared = base->eax.split.num_threads_sharing + 1;
apicid = cpu_data(cpu).apicid;
first = apicid - (apicid % nshared);
last = first + nshared - 1;
for_each_online_cpu(i) {
this_cpu_ci = get_cpu_cacheinfo(i);
if (!this_cpu_ci->info_list)
continue;
apicid = cpu_data(i).apicid;
if ((apicid < first) || (apicid > last))
continue;
this_leaf = this_cpu_ci->info_list + index;
for_each_online_cpu(sibling) {
apicid = cpu_data(sibling).apicid;
if ((apicid < first) || (apicid > last))
continue;
cpumask_set_cpu(sibling,
&this_leaf->shared_cpu_map);
}
}
} else if (index == 3) {
for_each_cpu(i, cpu_llc_shared_mask(cpu)) {
this_cpu_ci = get_cpu_cacheinfo(i);
if (!this_cpu_ci->info_list)
continue;
this_leaf = this_cpu_ci->info_list + index;
for_each_cpu(sibling, cpu_llc_shared_mask(cpu)) {
if (!cpu_online(sibling))
continue;
cpumask_set_cpu(sibling,
&this_leaf->shared_cpu_map);
}
}
} else
return 0;
return 1;
}
static void __cache_cpumap_setup(unsigned int cpu, int index,
struct _cpuid4_info_regs *base)
{
struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
struct cacheinfo *this_leaf, *sibling_leaf;
unsigned long num_threads_sharing;
int index_msb, i;
struct cpuinfo_x86 *c = &cpu_data(cpu);
if (c->x86_vendor == X86_VENDOR_AMD) {
if (__cache_amd_cpumap_setup(cpu, index, base))
return;
}
this_leaf = this_cpu_ci->info_list + index;
num_threads_sharing = 1 + base->eax.split.num_threads_sharing;
cpumask_set_cpu(cpu, &this_leaf->shared_cpu_map);
if (num_threads_sharing == 1)
return;
index_msb = get_count_order(num_threads_sharing);
for_each_online_cpu(i)
if (cpu_data(i).apicid >> index_msb == c->apicid >> index_msb) {
struct cpu_cacheinfo *sib_cpu_ci = get_cpu_cacheinfo(i);
if (i == cpu || !sib_cpu_ci->info_list)
continue;
sibling_leaf = sib_cpu_ci->info_list + index;
cpumask_set_cpu(i, &this_leaf->shared_cpu_map);
cpumask_set_cpu(cpu, &sibling_leaf->shared_cpu_map);
}
}
static void ci_leaf_init(struct cacheinfo *this_leaf,
struct _cpuid4_info_regs *base)
{
this_leaf->level = base->eax.split.level;
this_leaf->type = cache_type_map[base->eax.split.type];
this_leaf->coherency_line_size =
base->ebx.split.coherency_line_size + 1;
this_leaf->ways_of_associativity =
base->ebx.split.ways_of_associativity + 1;
this_leaf->size = base->size;
this_leaf->number_of_sets = base->ecx.split.number_of_sets + 1;
this_leaf->physical_line_partition =
base->ebx.split.physical_line_partition + 1;
this_leaf->priv = base->nb;
}
static int __init_cache_level(unsigned int cpu)
{
struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
if (!num_cache_leaves)
return -ENOENT;
if (!this_cpu_ci)
return -EINVAL;
this_cpu_ci->num_levels = 3;
this_cpu_ci->num_leaves = num_cache_leaves;
return 0;
}
static int __populate_cache_leaves(unsigned int cpu)
{
unsigned int idx, ret;
struct cpu_cacheinfo *this_cpu_ci = get_cpu_cacheinfo(cpu);
struct cacheinfo *this_leaf = this_cpu_ci->info_list;
struct _cpuid4_info_regs id4_regs = {};
for (idx = 0; idx < this_cpu_ci->num_leaves; idx++) {
ret = cpuid4_cache_lookup_regs(idx, &id4_regs);
if (ret)
return ret;
ci_leaf_init(this_leaf++, &id4_regs);
__cache_cpumap_setup(cpu, idx, &id4_regs);
}
return 0;
}
