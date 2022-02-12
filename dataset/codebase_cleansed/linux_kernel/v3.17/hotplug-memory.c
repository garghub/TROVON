unsigned long pseries_memory_block_size(void)
{
struct device_node *np;
unsigned int memblock_size = MIN_MEMORY_BLOCK_SIZE;
struct resource r;
np = of_find_node_by_path("/ibm,dynamic-reconfiguration-memory");
if (np) {
const __be64 *size;
size = of_get_property(np, "ibm,lmb-size", NULL);
if (size)
memblock_size = be64_to_cpup(size);
of_node_put(np);
} else if (machine_is(pseries)) {
unsigned int memzero_size = 0;
np = of_find_node_by_path("/memory@0");
if (np) {
if (!of_address_to_resource(np, 0, &r))
memzero_size = resource_size(&r);
of_node_put(np);
}
if (memzero_size) {
char buf[64];
sprintf(buf, "/memory@%x", memzero_size);
np = of_find_node_by_path(buf);
if (np) {
if (!of_address_to_resource(np, 0, &r))
memblock_size = resource_size(&r);
of_node_put(np);
}
}
}
return memblock_size;
}
static int pseries_remove_memory(u64 start, u64 size)
{
int ret;
start = (unsigned long)__va(start);
ret = remove_section_mapping(start, start + size);
vm_unmap_aliases();
return ret;
}
static int pseries_remove_memblock(unsigned long base, unsigned int memblock_size)
{
unsigned long block_sz, start_pfn;
int sections_per_block;
int i, nid;
start_pfn = base >> PAGE_SHIFT;
lock_device_hotplug();
if (!pfn_valid(start_pfn))
goto out;
block_sz = pseries_memory_block_size();
sections_per_block = block_sz / MIN_MEMORY_BLOCK_SIZE;
nid = memory_add_physaddr_to_nid(base);
for (i = 0; i < sections_per_block; i++) {
remove_memory(nid, base, MIN_MEMORY_BLOCK_SIZE);
base += MIN_MEMORY_BLOCK_SIZE;
}
out:
memblock_remove(base, memblock_size);
unlock_device_hotplug();
return 0;
}
static int pseries_remove_mem_node(struct device_node *np)
{
const char *type;
const __be32 *regs;
unsigned long base;
unsigned int lmb_size;
int ret = -EINVAL;
type = of_get_property(np, "device_type", NULL);
if (type == NULL || strcmp(type, "memory") != 0)
return 0;
regs = of_get_property(np, "reg", NULL);
if (!regs)
return ret;
base = be64_to_cpu(*(unsigned long *)regs);
lmb_size = be32_to_cpu(regs[3]);
pseries_remove_memblock(base, lmb_size);
return 0;
}
static inline int pseries_remove_memblock(unsigned long base,
unsigned int memblock_size)
{
return -EOPNOTSUPP;
}
static inline int pseries_remove_mem_node(struct device_node *np)
{
return 0;
}
static int pseries_add_mem_node(struct device_node *np)
{
const char *type;
const __be32 *regs;
unsigned long base;
unsigned int lmb_size;
int ret = -EINVAL;
type = of_get_property(np, "device_type", NULL);
if (type == NULL || strcmp(type, "memory") != 0)
return 0;
regs = of_get_property(np, "reg", NULL);
if (!regs)
return ret;
base = be64_to_cpu(*(unsigned long *)regs);
lmb_size = be32_to_cpu(regs[3]);
ret = memblock_add(base, lmb_size);
return (ret < 0) ? -EINVAL : 0;
}
static int pseries_update_drconf_memory(struct of_prop_reconfig *pr)
{
struct of_drconf_cell *new_drmem, *old_drmem;
unsigned long memblock_size;
u32 entries;
__be32 *p;
int i, rc = -EINVAL;
memblock_size = pseries_memory_block_size();
if (!memblock_size)
return -EINVAL;
p = (__be32 *) pr->old_prop->value;
if (!p)
return -EINVAL;
entries = be32_to_cpu(*p++);
old_drmem = (struct of_drconf_cell *)p;
p = (__be32 *)pr->prop->value;
p++;
new_drmem = (struct of_drconf_cell *)p;
for (i = 0; i < entries; i++) {
if ((be32_to_cpu(old_drmem[i].flags) & DRCONF_MEM_ASSIGNED) &&
(!(be32_to_cpu(new_drmem[i].flags) & DRCONF_MEM_ASSIGNED))) {
rc = pseries_remove_memblock(
be64_to_cpu(old_drmem[i].base_addr),
memblock_size);
break;
} else if ((!(be32_to_cpu(old_drmem[i].flags) &
DRCONF_MEM_ASSIGNED)) &&
(be32_to_cpu(new_drmem[i].flags) &
DRCONF_MEM_ASSIGNED)) {
rc = memblock_add(be64_to_cpu(old_drmem[i].base_addr),
memblock_size);
rc = (rc < 0) ? -EINVAL : 0;
break;
}
}
return rc;
}
static int pseries_memory_notifier(struct notifier_block *nb,
unsigned long action, void *node)
{
struct of_prop_reconfig *pr;
int err = 0;
switch (action) {
case OF_RECONFIG_ATTACH_NODE:
err = pseries_add_mem_node(node);
break;
case OF_RECONFIG_DETACH_NODE:
err = pseries_remove_mem_node(node);
break;
case OF_RECONFIG_UPDATE_PROPERTY:
pr = (struct of_prop_reconfig *)node;
if (!strcmp(pr->prop->name, "ibm,dynamic-memory"))
err = pseries_update_drconf_memory(pr);
break;
}
return notifier_from_errno(err);
}
static int __init pseries_memory_hotplug_init(void)
{
if (firmware_has_feature(FW_FEATURE_LPAR))
of_reconfig_notifier_register(&pseries_mem_nb);
#ifdef CONFIG_MEMORY_HOTREMOVE
ppc_md.remove_memory = pseries_remove_memory;
#endif
return 0;
}
