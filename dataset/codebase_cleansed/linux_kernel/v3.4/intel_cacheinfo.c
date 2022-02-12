static void __cpuinit
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
static void __cpuinit amd_calc_l3_indices(struct amd_northbridge *nb)
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
static void __cpuinit amd_init_l3_cache(struct _cpuid4_info_regs *this_leaf, int index)
{
int node;
if (index < 3)
return;
node = amd_get_nb_id(smp_processor_id());
this_leaf->nb = node_to_amd_nb(node);
if (this_leaf->nb && !this_leaf->nb->l3_cache.indices)
amd_calc_l3_indices(this_leaf->nb);
}
int amd_get_l3_disable_slot(struct amd_northbridge *nb, unsigned slot)
{
unsigned int reg = 0;
pci_read_config_dword(nb->misc, 0x1BC + slot * 4, &reg);
if (reg & (3UL << 30))
return reg & 0xfff;
return -1;
}
static ssize_t show_cache_disable(struct _cpuid4_info *this_leaf, char *buf,
unsigned int slot)
{
int index;
if (!this_leaf->base.nb || !amd_nb_has_feature(AMD_NB_L3_INDEX_DISABLE))
return -EINVAL;
index = amd_get_l3_disable_slot(this_leaf->base.nb, slot);
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
int amd_set_l3_disable_slot(struct amd_northbridge *nb, int cpu, unsigned slot,
unsigned long index)
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
static ssize_t store_cache_disable(struct _cpuid4_info *this_leaf,
const char *buf, size_t count,
unsigned int slot)
{
unsigned long val = 0;
int cpu, err = 0;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (!this_leaf->base.nb || !amd_nb_has_feature(AMD_NB_L3_INDEX_DISABLE))
return -EINVAL;
cpu = cpumask_first(to_cpumask(this_leaf->shared_cpu_map));
if (strict_strtoul(buf, 10, &val) < 0)
return -EINVAL;
err = amd_set_l3_disable_slot(this_leaf->base.nb, cpu, slot, val);
if (err) {
if (err == -EEXIST)
pr_warning("L3 slot %d in use/index already disabled!\n",
slot);
return err;
}
return count;
}
static ssize_t
show_subcaches(struct _cpuid4_info *this_leaf, char *buf, unsigned int cpu)
{
if (!this_leaf->base.nb || !amd_nb_has_feature(AMD_NB_L3_PARTITIONING))
return -EINVAL;
return sprintf(buf, "%x\n", amd_get_subcaches(cpu));
}
static ssize_t
store_subcaches(struct _cpuid4_info *this_leaf, const char *buf, size_t count,
unsigned int cpu)
{
unsigned long val;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (!this_leaf->base.nb || !amd_nb_has_feature(AMD_NB_L3_PARTITIONING))
return -EINVAL;
if (strict_strtoul(buf, 16, &val) < 0)
return -EINVAL;
if (amd_set_subcaches(cpu, val))
return -EINVAL;
return count;
}
static int
__cpuinit cpuid4_cache_lookup_regs(int index,
struct _cpuid4_info_regs *this_leaf)
{
union _cpuid4_leaf_eax eax;
union _cpuid4_leaf_ebx ebx;
union _cpuid4_leaf_ecx ecx;
unsigned edx;
if (boot_cpu_data.x86_vendor == X86_VENDOR_AMD) {
amd_cpuid4(index, &eax, &ebx, &ecx);
amd_init_l3_cache(this_leaf, index);
} else {
cpuid_count(4, index, &eax.full, &ebx.full, &ecx.full, &edx);
}
if (eax.split.type == CACHE_TYPE_NULL)
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
static int __cpuinit find_num_cache_leaves(void)
{
unsigned int eax, ebx, ecx, edx;
union _cpuid4_leaf_eax cache_eax;
int i = -1;
do {
++i;
cpuid_count(4, i, &eax, &ebx, &ecx, &edx);
cache_eax.full = eax;
} while (cache_eax.split.type != CACHE_TYPE_NULL);
return i;
}
unsigned int __cpuinit init_intel_cacheinfo(struct cpuinfo_x86 *c)
{
unsigned int trace = 0, l1i = 0, l1d = 0, l2 = 0, l3 = 0;
unsigned int new_l1d = 0, new_l1i = 0;
unsigned int new_l2 = 0, new_l3 = 0, i;
unsigned int l2_id = 0, l3_id = 0, num_threads_sharing, index_msb;
#ifdef CONFIG_X86_HT
unsigned int cpu = c->cpu_index;
#endif
if (c->cpuid_level > 3) {
static int is_initialized;
if (is_initialized == 0) {
num_cache_leaves = find_num_cache_leaves();
is_initialized++;
}
for (i = 0; i < num_cache_leaves; i++) {
struct _cpuid4_info_regs this_leaf;
int retval;
retval = cpuid4_cache_lookup_regs(i, &this_leaf);
if (retval >= 0) {
switch (this_leaf.eax.split.level) {
case 1:
if (this_leaf.eax.split.type ==
CACHE_TYPE_DATA)
new_l1d = this_leaf.size/1024;
else if (this_leaf.eax.split.type ==
CACHE_TYPE_INST)
new_l1i = this_leaf.size/1024;
break;
case 2:
new_l2 = this_leaf.size/1024;
num_threads_sharing = 1 + this_leaf.eax.split.num_threads_sharing;
index_msb = get_count_order(num_threads_sharing);
l2_id = c->apicid >> index_msb;
break;
case 3:
new_l3 = this_leaf.size/1024;
num_threads_sharing = 1 + this_leaf.eax.split.num_threads_sharing;
index_msb = get_count_order(
num_threads_sharing);
l3_id = c->apicid >> index_msb;
break;
default:
break;
}
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
#ifdef CONFIG_X86_HT
per_cpu(cpu_llc_id, cpu) = l2_id;
#endif
}
if (new_l3) {
l3 = new_l3;
#ifdef CONFIG_X86_HT
per_cpu(cpu_llc_id, cpu) = l3_id;
#endif
}
c->x86_cache_size = l3 ? l3 : (l2 ? l2 : (l1i+l1d));
return l2;
}
static int __cpuinit cache_shared_amd_cpu_map_setup(unsigned int cpu, int index)
{
struct _cpuid4_info *this_leaf;
int ret, i, sibling;
struct cpuinfo_x86 *c = &cpu_data(cpu);
ret = 0;
if (index == 3) {
ret = 1;
for_each_cpu(i, cpu_llc_shared_mask(cpu)) {
if (!per_cpu(ici_cpuid4_info, i))
continue;
this_leaf = CPUID4_INFO_IDX(i, index);
for_each_cpu(sibling, cpu_llc_shared_mask(cpu)) {
if (!cpu_online(sibling))
continue;
set_bit(sibling, this_leaf->shared_cpu_map);
}
}
} else if ((c->x86 == 0x15) && ((index == 1) || (index == 2))) {
ret = 1;
for_each_cpu(i, cpu_sibling_mask(cpu)) {
if (!per_cpu(ici_cpuid4_info, i))
continue;
this_leaf = CPUID4_INFO_IDX(i, index);
for_each_cpu(sibling, cpu_sibling_mask(cpu)) {
if (!cpu_online(sibling))
continue;
set_bit(sibling, this_leaf->shared_cpu_map);
}
}
}
return ret;
}
static void __cpuinit cache_shared_cpu_map_setup(unsigned int cpu, int index)
{
struct _cpuid4_info *this_leaf, *sibling_leaf;
unsigned long num_threads_sharing;
int index_msb, i;
struct cpuinfo_x86 *c = &cpu_data(cpu);
if (c->x86_vendor == X86_VENDOR_AMD) {
if (cache_shared_amd_cpu_map_setup(cpu, index))
return;
}
this_leaf = CPUID4_INFO_IDX(cpu, index);
num_threads_sharing = 1 + this_leaf->base.eax.split.num_threads_sharing;
if (num_threads_sharing == 1)
cpumask_set_cpu(cpu, to_cpumask(this_leaf->shared_cpu_map));
else {
index_msb = get_count_order(num_threads_sharing);
for_each_online_cpu(i) {
if (cpu_data(i).apicid >> index_msb ==
c->apicid >> index_msb) {
cpumask_set_cpu(i,
to_cpumask(this_leaf->shared_cpu_map));
if (i != cpu && per_cpu(ici_cpuid4_info, i)) {
sibling_leaf =
CPUID4_INFO_IDX(i, index);
cpumask_set_cpu(cpu, to_cpumask(
sibling_leaf->shared_cpu_map));
}
}
}
}
}
static void __cpuinit cache_remove_shared_cpu_map(unsigned int cpu, int index)
{
struct _cpuid4_info *this_leaf, *sibling_leaf;
int sibling;
this_leaf = CPUID4_INFO_IDX(cpu, index);
for_each_cpu(sibling, to_cpumask(this_leaf->shared_cpu_map)) {
sibling_leaf = CPUID4_INFO_IDX(sibling, index);
cpumask_clear_cpu(cpu,
to_cpumask(sibling_leaf->shared_cpu_map));
}
}
static void __cpuinit cache_shared_cpu_map_setup(unsigned int cpu, int index)
{
}
static void __cpuinit cache_remove_shared_cpu_map(unsigned int cpu, int index)
{
}
static void __cpuinit free_cache_attributes(unsigned int cpu)
{
int i;
for (i = 0; i < num_cache_leaves; i++)
cache_remove_shared_cpu_map(cpu, i);
kfree(per_cpu(ici_cpuid4_info, cpu));
per_cpu(ici_cpuid4_info, cpu) = NULL;
}
static void __cpuinit get_cpu_leaves(void *_retval)
{
int j, *retval = _retval, cpu = smp_processor_id();
for (j = 0; j < num_cache_leaves; j++) {
struct _cpuid4_info *this_leaf = CPUID4_INFO_IDX(cpu, j);
*retval = cpuid4_cache_lookup_regs(j, &this_leaf->base);
if (unlikely(*retval < 0)) {
int i;
for (i = 0; i < j; i++)
cache_remove_shared_cpu_map(cpu, i);
break;
}
cache_shared_cpu_map_setup(cpu, j);
}
}
static int __cpuinit detect_cache_attributes(unsigned int cpu)
{
int retval;
if (num_cache_leaves == 0)
return -ENOENT;
per_cpu(ici_cpuid4_info, cpu) = kzalloc(
sizeof(struct _cpuid4_info) * num_cache_leaves, GFP_KERNEL);
if (per_cpu(ici_cpuid4_info, cpu) == NULL)
return -ENOMEM;
smp_call_function_single(cpu, get_cpu_leaves, &retval, true);
if (retval) {
kfree(per_cpu(ici_cpuid4_info, cpu));
per_cpu(ici_cpuid4_info, cpu) = NULL;
}
return retval;
}
static ssize_t show_size(struct _cpuid4_info *this_leaf, char *buf,
unsigned int cpu)
{
return sprintf(buf, "%luK\n", this_leaf->base.size / 1024);
}
static ssize_t show_shared_cpu_map_func(struct _cpuid4_info *this_leaf,
int type, char *buf)
{
ptrdiff_t len = PTR_ALIGN(buf + PAGE_SIZE - 1, PAGE_SIZE) - buf;
int n = 0;
if (len > 1) {
const struct cpumask *mask;
mask = to_cpumask(this_leaf->shared_cpu_map);
n = type ?
cpulist_scnprintf(buf, len-2, mask) :
cpumask_scnprintf(buf, len-2, mask);
buf[n++] = '\n';
buf[n] = '\0';
}
return n;
}
static inline ssize_t show_shared_cpu_map(struct _cpuid4_info *leaf, char *buf,
unsigned int cpu)
{
return show_shared_cpu_map_func(leaf, 0, buf);
}
static inline ssize_t show_shared_cpu_list(struct _cpuid4_info *leaf, char *buf,
unsigned int cpu)
{
return show_shared_cpu_map_func(leaf, 1, buf);
}
static ssize_t show_type(struct _cpuid4_info *this_leaf, char *buf,
unsigned int cpu)
{
switch (this_leaf->base.eax.split.type) {
case CACHE_TYPE_DATA:
return sprintf(buf, "Data\n");
case CACHE_TYPE_INST:
return sprintf(buf, "Instruction\n");
case CACHE_TYPE_UNIFIED:
return sprintf(buf, "Unified\n");
default:
return sprintf(buf, "Unknown\n");
}
}
static struct attribute ** __cpuinit amd_l3_attrs(void)
{
static struct attribute **attrs;
int n;
if (attrs)
return attrs;
n = sizeof (default_attrs) / sizeof (struct attribute *);
if (amd_nb_has_feature(AMD_NB_L3_INDEX_DISABLE))
n += 2;
if (amd_nb_has_feature(AMD_NB_L3_PARTITIONING))
n += 1;
attrs = kzalloc(n * sizeof (struct attribute *), GFP_KERNEL);
if (attrs == NULL)
return attrs = default_attrs;
for (n = 0; default_attrs[n]; n++)
attrs[n] = default_attrs[n];
if (amd_nb_has_feature(AMD_NB_L3_INDEX_DISABLE)) {
attrs[n++] = &cache_disable_0.attr;
attrs[n++] = &cache_disable_1.attr;
}
if (amd_nb_has_feature(AMD_NB_L3_PARTITIONING))
attrs[n++] = &subcaches.attr;
return attrs;
}
static ssize_t show(struct kobject *kobj, struct attribute *attr, char *buf)
{
struct _cache_attr *fattr = to_attr(attr);
struct _index_kobject *this_leaf = to_object(kobj);
ssize_t ret;
ret = fattr->show ?
fattr->show(CPUID4_INFO_IDX(this_leaf->cpu, this_leaf->index),
buf, this_leaf->cpu) :
0;
return ret;
}
static ssize_t store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct _cache_attr *fattr = to_attr(attr);
struct _index_kobject *this_leaf = to_object(kobj);
ssize_t ret;
ret = fattr->store ?
fattr->store(CPUID4_INFO_IDX(this_leaf->cpu, this_leaf->index),
buf, count, this_leaf->cpu) :
0;
return ret;
}
static void __cpuinit cpuid4_cache_sysfs_exit(unsigned int cpu)
{
kfree(per_cpu(ici_cache_kobject, cpu));
kfree(per_cpu(ici_index_kobject, cpu));
per_cpu(ici_cache_kobject, cpu) = NULL;
per_cpu(ici_index_kobject, cpu) = NULL;
free_cache_attributes(cpu);
}
static int __cpuinit cpuid4_cache_sysfs_init(unsigned int cpu)
{
int err;
if (num_cache_leaves == 0)
return -ENOENT;
err = detect_cache_attributes(cpu);
if (err)
return err;
per_cpu(ici_cache_kobject, cpu) =
kzalloc(sizeof(struct kobject), GFP_KERNEL);
if (unlikely(per_cpu(ici_cache_kobject, cpu) == NULL))
goto err_out;
per_cpu(ici_index_kobject, cpu) = kzalloc(
sizeof(struct _index_kobject) * num_cache_leaves, GFP_KERNEL);
if (unlikely(per_cpu(ici_index_kobject, cpu) == NULL))
goto err_out;
return 0;
err_out:
cpuid4_cache_sysfs_exit(cpu);
return -ENOMEM;
}
static int __cpuinit cache_add_dev(struct device *dev)
{
unsigned int cpu = dev->id;
unsigned long i, j;
struct _index_kobject *this_object;
struct _cpuid4_info *this_leaf;
int retval;
retval = cpuid4_cache_sysfs_init(cpu);
if (unlikely(retval < 0))
return retval;
retval = kobject_init_and_add(per_cpu(ici_cache_kobject, cpu),
&ktype_percpu_entry,
&dev->kobj, "%s", "cache");
if (retval < 0) {
cpuid4_cache_sysfs_exit(cpu);
return retval;
}
for (i = 0; i < num_cache_leaves; i++) {
this_object = INDEX_KOBJECT_PTR(cpu, i);
this_object->cpu = cpu;
this_object->index = i;
this_leaf = CPUID4_INFO_IDX(cpu, i);
ktype_cache.default_attrs = default_attrs;
#ifdef CONFIG_AMD_NB
if (this_leaf->base.nb)
ktype_cache.default_attrs = amd_l3_attrs();
#endif
retval = kobject_init_and_add(&(this_object->kobj),
&ktype_cache,
per_cpu(ici_cache_kobject, cpu),
"index%1lu", i);
if (unlikely(retval)) {
for (j = 0; j < i; j++)
kobject_put(&(INDEX_KOBJECT_PTR(cpu, j)->kobj));
kobject_put(per_cpu(ici_cache_kobject, cpu));
cpuid4_cache_sysfs_exit(cpu);
return retval;
}
kobject_uevent(&(this_object->kobj), KOBJ_ADD);
}
cpumask_set_cpu(cpu, to_cpumask(cache_dev_map));
kobject_uevent(per_cpu(ici_cache_kobject, cpu), KOBJ_ADD);
return 0;
}
static void __cpuinit cache_remove_dev(struct device *dev)
{
unsigned int cpu = dev->id;
unsigned long i;
if (per_cpu(ici_cpuid4_info, cpu) == NULL)
return;
if (!cpumask_test_cpu(cpu, to_cpumask(cache_dev_map)))
return;
cpumask_clear_cpu(cpu, to_cpumask(cache_dev_map));
for (i = 0; i < num_cache_leaves; i++)
kobject_put(&(INDEX_KOBJECT_PTR(cpu, i)->kobj));
kobject_put(per_cpu(ici_cache_kobject, cpu));
cpuid4_cache_sysfs_exit(cpu);
}
static int __cpuinit cacheinfo_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
struct device *dev;
dev = get_cpu_device(cpu);
switch (action) {
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
cache_add_dev(dev);
break;
case CPU_DEAD:
case CPU_DEAD_FROZEN:
cache_remove_dev(dev);
break;
}
return NOTIFY_OK;
}
static int __cpuinit cache_sysfs_init(void)
{
int i;
if (num_cache_leaves == 0)
return 0;
for_each_online_cpu(i) {
int err;
struct device *dev = get_cpu_device(i);
err = cache_add_dev(dev);
if (err)
return err;
}
register_hotcpu_notifier(&cacheinfo_cpu_notifier);
return 0;
}
