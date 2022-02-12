struct prom_pmemblock * __init prom_getmdesc(void)
{
unsigned int memsize;
memsize = 0x02000000;
pr_info("Setting default memory size 0x%08x\n", memsize);
memset(mdesc, 0, sizeof(mdesc));
mdesc[0].type = simmem_reserved;
mdesc[0].base = 0x00000000;
mdesc[0].size = 0x00001000;
mdesc[1].type = simmem_free;
mdesc[1].base = 0x00001000;
mdesc[1].size = 0x000ff000;
mdesc[2].type = simmem_reserved;
mdesc[2].base = 0x00100000;
mdesc[2].size = CPHYSADDR(PFN_ALIGN(&_end)) - mdesc[2].base;
mdesc[3].type = simmem_free;
mdesc[3].base = CPHYSADDR(PFN_ALIGN(&_end));
mdesc[3].size = memsize - mdesc[3].base;
return &mdesc[0];
}
static int __init prom_memtype_classify(unsigned int type)
{
switch (type) {
case simmem_free:
return BOOT_MEM_RAM;
case simmem_reserved:
default:
return BOOT_MEM_RESERVED;
}
}
void __init prom_meminit(void)
{
struct prom_pmemblock *p;
p = prom_getmdesc();
while (p->size) {
long type;
unsigned long base, size;
type = prom_memtype_classify(p->type);
base = p->base;
size = p->size;
add_memory_region(base, size, type);
p++;
}
}
void __init prom_free_prom_memory(void)
{
int i;
unsigned long addr;
for (i = 0; i < boot_mem_map.nr_map; i++) {
if (boot_mem_map.map[i].type != BOOT_MEM_ROM_DATA)
continue;
addr = boot_mem_map.map[i].addr;
free_init_pages("prom memory",
addr, addr + boot_mem_map.map[i].size);
}
}
