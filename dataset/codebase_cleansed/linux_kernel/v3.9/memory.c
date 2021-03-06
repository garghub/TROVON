struct linux_mdesc * __init ArcGetMemoryDescriptor(struct linux_mdesc *Current)
{
return (struct linux_mdesc *) ARC_CALL1(get_mdesc, Current);
}
static inline int memtype_classify_arcs(union linux_memtypes type)
{
switch (type.arcs) {
case arcs_fcontig:
case arcs_free:
return BOOT_MEM_RAM;
case arcs_atmp:
return BOOT_MEM_ROM_DATA;
case arcs_eblock:
case arcs_rvpage:
case arcs_bmem:
case arcs_prog:
case arcs_aperm:
return BOOT_MEM_RESERVED;
default:
BUG();
}
while(1);
}
static inline int memtype_classify_arc(union linux_memtypes type)
{
switch (type.arc) {
case arc_free:
case arc_fcontig:
return BOOT_MEM_RAM;
case arc_atmp:
return BOOT_MEM_ROM_DATA;
case arc_eblock:
case arc_rvpage:
case arc_bmem:
case arc_prog:
case arc_aperm:
return BOOT_MEM_RESERVED;
default:
BUG();
}
while(1);
}
static int __init prom_memtype_classify(union linux_memtypes type)
{
if (prom_flags & PROM_FLAG_ARCS)
return memtype_classify_arcs(type);
return memtype_classify_arc(type);
}
void __init prom_meminit(void)
{
struct linux_mdesc *p;
#ifdef DEBUG
int i = 0;
printk("ARCS MEMORY DESCRIPTOR dump:\n");
p = ArcGetMemoryDescriptor(PROM_NULL_MDESC);
while(p) {
printk("[%d,%p]: base<%08lx> pages<%08lx> type<%s>\n",
i, p, p->base, p->pages, mtypes(p->type));
p = ArcGetMemoryDescriptor(p);
i++;
}
#endif
p = PROM_NULL_MDESC;
while ((p = ArcGetMemoryDescriptor(p))) {
unsigned long base, size;
long type;
base = p->base << ARC_PAGE_SHIFT;
size = p->pages << ARC_PAGE_SHIFT;
type = prom_memtype_classify(p->type);
add_memory_region(base, size, type);
}
}
void __init prom_free_prom_memory(void)
{
unsigned long addr;
int i;
if (prom_flags & PROM_FLAG_DONT_FREE_TEMP)
return;
for (i = 0; i < boot_mem_map.nr_map; i++) {
if (boot_mem_map.map[i].type != BOOT_MEM_ROM_DATA)
continue;
addr = boot_mem_map.map[i].addr;
free_init_pages("prom memory",
addr, addr + boot_mem_map.map[i].size);
}
}
