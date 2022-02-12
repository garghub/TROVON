static unsigned long get_memblock_size(void)
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
unsigned long memory_block_size_bytes(void)
{
return get_memblock_size();
}
static int pseries_remove_memblock(unsigned long base, unsigned int memblock_size)
{
unsigned long start, start_pfn;
struct zone *zone;
int ret;
unsigned long section;
unsigned long sections_to_remove;
start_pfn = base >> PAGE_SHIFT;
if (!pfn_valid(start_pfn)) {
memblock_remove(base, memblock_size);
return 0;
}
zone = page_zone(pfn_to_page(start_pfn));
sections_to_remove = (memblock_size >> PAGE_SHIFT) / PAGES_PER_SECTION;
for (section = 0; section < sections_to_remove; section++) {
unsigned long pfn = start_pfn + section * PAGES_PER_SECTION;
ret = __remove_pages(zone, pfn, PAGES_PER_SECTION);
if (ret)
return ret;
}
memblock_remove(base, memblock_size);
start = (unsigned long)__va(base);
ret = remove_section_mapping(start, start + memblock_size);
vm_unmap_aliases();
return ret;
}
static int pseries_remove_memory(struct device_node *np)
{
const char *type;
const unsigned int *regs;
unsigned long base;
unsigned int lmb_size;
int ret = -EINVAL;
type = of_get_property(np, "device_type", NULL);
if (type == NULL || strcmp(type, "memory") != 0)
return 0;
regs = of_get_property(np, "reg", NULL);
if (!regs)
return ret;
base = *(unsigned long *)regs;
lmb_size = regs[3];
ret = pseries_remove_memblock(base, lmb_size);
return ret;
}
static inline int pseries_remove_memblock(unsigned long base,
unsigned int memblock_size)
{
return -EOPNOTSUPP;
}
static inline int pseries_remove_memory(struct device_node *np)
{
return -EOPNOTSUPP;
}
static int pseries_add_memory(struct device_node *np)
{
const char *type;
const unsigned int *regs;
unsigned long base;
unsigned int lmb_size;
int ret = -EINVAL;
type = of_get_property(np, "device_type", NULL);
if (type == NULL || strcmp(type, "memory") != 0)
return 0;
regs = of_get_property(np, "reg", NULL);
if (!regs)
return ret;
base = *(unsigned long *)regs;
lmb_size = regs[3];
ret = memblock_add(base, lmb_size);
return (ret < 0) ? -EINVAL : 0;
}
static int pseries_update_drconf_memory(struct of_prop_reconfig *pr)
{
struct of_drconf_cell *new_drmem, *old_drmem;
unsigned long memblock_size;
u32 entries;
u32 *p;
int i, rc = -EINVAL;
memblock_size = get_memblock_size();
if (!memblock_size)
return -EINVAL;
p = (u32 *)of_get_property(pr->dn, "ibm,dynamic-memory", NULL);
if (!p)
return -EINVAL;
entries = *p++;
old_drmem = (struct of_drconf_cell *)p;
p = (u32 *)pr->prop->value;
p++;
new_drmem = (struct of_drconf_cell *)p;
for (i = 0; i < entries; i++) {
if ((old_drmem[i].flags & DRCONF_MEM_ASSIGNED) &&
(!(new_drmem[i].flags & DRCONF_MEM_ASSIGNED))) {
rc = pseries_remove_memblock(old_drmem[i].base_addr,
memblock_size);
break;
} else if ((!(old_drmem[i].flags & DRCONF_MEM_ASSIGNED)) &&
(new_drmem[i].flags & DRCONF_MEM_ASSIGNED)) {
rc = memblock_add(old_drmem[i].base_addr,
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
err = pseries_add_memory(node);
break;
case OF_RECONFIG_DETACH_NODE:
err = pseries_remove_memory(node);
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
return 0;
}
