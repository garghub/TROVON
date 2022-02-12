fw_memblock_t * __init fw_getmdesc(void)
{
char *memsize_str, *ptr;
unsigned int memsize;
static char cmdline[COMMAND_LINE_SIZE] __initdata;
long val;
int tmp;
memsize_str = fw_getenv("memsize");
if (!memsize_str) {
pr_warn("memsize not set in YAMON, set to default (32Mb)\n");
physical_memsize = 0x02000000;
} else {
tmp = kstrtol(memsize_str, 0, &val);
physical_memsize = (unsigned long)val;
}
#ifdef CONFIG_CPU_BIG_ENDIAN
physical_memsize -= PAGE_SIZE;
#endif
strcpy(cmdline, arcs_cmdline);
ptr = strstr(cmdline, "memsize=");
if (ptr && (ptr != cmdline) && (*(ptr - 1) != ' '))
ptr = strstr(ptr, " memsize=");
if (ptr)
memsize = memparse(ptr + 8, &ptr);
else
memsize = physical_memsize;
memset(mdesc, 0, sizeof(mdesc));
mdesc[0].type = fw_dontuse;
mdesc[0].base = 0x00000000;
mdesc[0].size = 0x00001000;
mdesc[1].type = fw_code;
mdesc[1].base = 0x00001000;
mdesc[1].size = 0x000ef000;
mdesc[2].type = fw_dontuse;
mdesc[2].base = 0x000f0000;
mdesc[2].size = 0x00010000;
mdesc[3].type = fw_dontuse;
mdesc[3].base = 0x00100000;
mdesc[3].size = CPHYSADDR(PFN_ALIGN((unsigned long)&_end)) -
mdesc[3].base;
mdesc[4].type = fw_free;
mdesc[4].base = CPHYSADDR(PFN_ALIGN(&_end));
mdesc[4].size = memsize - mdesc[4].base;
return &mdesc[0];
}
static int __init fw_memtype_classify(unsigned int type)
{
switch (type) {
case fw_free:
return BOOT_MEM_RAM;
case fw_code:
return BOOT_MEM_ROM_DATA;
default:
return BOOT_MEM_RESERVED;
}
}
void __init fw_meminit(void)
{
fw_memblock_t *p;
p = fw_getmdesc();
while (p->size) {
long type;
unsigned long base, size;
type = fw_memtype_classify(p->type);
base = p->base;
size = p->size;
add_memory_region(base, size, type);
p++;
}
}
void __init prom_free_prom_memory(void)
{
unsigned long addr;
int i;
for (i = 0; i < boot_mem_map.nr_map; i++) {
if (boot_mem_map.map[i].type != BOOT_MEM_ROM_DATA)
continue;
addr = boot_mem_map.map[i].addr;
free_init_pages("YAMON memory",
addr, addr + boot_mem_map.map[i].size);
}
}
