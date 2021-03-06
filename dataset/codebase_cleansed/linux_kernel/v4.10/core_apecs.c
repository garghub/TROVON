static int
mk_conf_addr(struct pci_bus *pbus, unsigned int device_fn, int where,
unsigned long *pci_addr, unsigned char *type1)
{
unsigned long addr;
u8 bus = pbus->number;
DBGC(("mk_conf_addr(bus=%d ,device_fn=0x%x, where=0x%x,"
" pci_addr=0x%p, type1=0x%p)\n",
bus, device_fn, where, pci_addr, type1));
if (bus == 0) {
int device = device_fn >> 3;
if (device > 20) {
DBGC(("mk_conf_addr: device (%d) > 20, returning -1\n",
device));
return -1;
}
*type1 = 0;
addr = (device_fn << 8) | (where);
} else {
*type1 = 1;
addr = (bus << 16) | (device_fn << 8) | (where);
}
*pci_addr = addr;
DBGC(("mk_conf_addr: returning pci_addr 0x%lx\n", addr));
return 0;
}
static unsigned int
conf_read(unsigned long addr, unsigned char type1)
{
unsigned long flags;
unsigned int stat0, value;
unsigned int haxr2 = 0;
local_irq_save(flags);
DBGC(("conf_read(addr=0x%lx, type1=%d)\n", addr, type1));
stat0 = *(vuip)APECS_IOC_DCSR;
*(vuip)APECS_IOC_DCSR = stat0;
mb();
DBGC(("conf_read: APECS DCSR was 0x%x\n", stat0));
if (type1) {
haxr2 = *(vuip)APECS_IOC_HAXR2;
mb();
*(vuip)APECS_IOC_HAXR2 = haxr2 | 1;
DBGC(("conf_read: TYPE1 access\n"));
}
draina();
mcheck_expected(0) = 1;
mcheck_taken(0) = 0;
mb();
asm volatile("ldl %0,%1; mb; mb" : "=r"(value) : "m"(*(vuip)addr)
: "$9", "$10", "$11", "$12", "$13", "$14", "memory");
if (mcheck_taken(0)) {
mcheck_taken(0) = 0;
value = 0xffffffffU;
mb();
}
mcheck_expected(0) = 0;
mb();
#if 1
draina();
stat0 = *(vuip)APECS_IOC_DCSR;
DBGC(("conf_read: APECS DCSR after read 0x%x\n", stat0));
if (stat0 & 0xffe0U) {
if (!(stat0 & 0x0800)) {
printk("apecs.c:conf_read: got stat0=%x\n", stat0);
}
*(vuip)APECS_IOC_DCSR = stat0;
mb();
wrmces(0x7);
value = 0xffffffff;
}
#endif
if (type1) {
*(vuip)APECS_IOC_HAXR2 = haxr2 & ~1;
mb();
}
local_irq_restore(flags);
return value;
}
static void
conf_write(unsigned long addr, unsigned int value, unsigned char type1)
{
unsigned long flags;
unsigned int stat0;
unsigned int haxr2 = 0;
local_irq_save(flags);
stat0 = *(vuip)APECS_IOC_DCSR;
*(vuip)APECS_IOC_DCSR = stat0;
mb();
if (type1) {
haxr2 = *(vuip)APECS_IOC_HAXR2;
mb();
*(vuip)APECS_IOC_HAXR2 = haxr2 | 1;
}
draina();
mcheck_expected(0) = 1;
mb();
*(vuip)addr = value;
mb();
mb();
mcheck_expected(0) = 0;
mb();
#if 1
draina();
stat0 = *(vuip)APECS_IOC_DCSR;
if (stat0 & 0xffe0U) {
if (!(stat0 & 0x0800)) {
printk("apecs.c:conf_write: got stat0=%x\n", stat0);
}
*(vuip)APECS_IOC_DCSR = stat0;
mb();
wrmces(0x7);
}
#endif
if (type1) {
*(vuip)APECS_IOC_HAXR2 = haxr2 & ~1;
mb();
}
local_irq_restore(flags);
}
static int
apecs_read_config(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 *value)
{
unsigned long addr, pci_addr;
unsigned char type1;
long mask;
int shift;
if (mk_conf_addr(bus, devfn, where, &pci_addr, &type1))
return PCIBIOS_DEVICE_NOT_FOUND;
mask = (size - 1) * 8;
shift = (where & 3) * 8;
addr = (pci_addr << 5) + mask + APECS_CONF;
*value = conf_read(addr, type1) >> (shift);
return PCIBIOS_SUCCESSFUL;
}
static int
apecs_write_config(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 value)
{
unsigned long addr, pci_addr;
unsigned char type1;
long mask;
if (mk_conf_addr(bus, devfn, where, &pci_addr, &type1))
return PCIBIOS_DEVICE_NOT_FOUND;
mask = (size - 1) * 8;
addr = (pci_addr << 5) + mask + APECS_CONF;
conf_write(addr, value << ((where & 3) * 8), type1);
return PCIBIOS_SUCCESSFUL;
}
void
apecs_pci_tbi(struct pci_controller *hose, dma_addr_t start, dma_addr_t end)
{
wmb();
*(vip)APECS_IOC_TBIA = 0;
mb();
}
void __init
apecs_init_arch(void)
{
struct pci_controller *hose;
pci_isa_hose = hose = alloc_pci_controller();
hose->io_space = &ioport_resource;
hose->mem_space = &iomem_resource;
hose->index = 0;
hose->sparse_mem_base = APECS_SPARSE_MEM - IDENT_ADDR;
hose->dense_mem_base = APECS_DENSE_MEM - IDENT_ADDR;
hose->sparse_io_base = APECS_IO - IDENT_ADDR;
hose->dense_io_base = 0;
hose->sg_isa = iommu_arena_new(hose, 0x00800000, 0x00800000, 0);
hose->sg_pci = NULL;
__direct_map_base = 0x40000000;
__direct_map_size = 0x40000000;
*(vuip)APECS_IOC_PB1R = __direct_map_base | 0x00080000;
*(vuip)APECS_IOC_PM1R = (__direct_map_size - 1) & 0xfff00000U;
*(vuip)APECS_IOC_TB1R = 0;
*(vuip)APECS_IOC_PB2R = hose->sg_isa->dma_base | 0x000c0000;
*(vuip)APECS_IOC_PM2R = (hose->sg_isa->size - 1) & 0xfff00000;
*(vuip)APECS_IOC_TB2R = virt_to_phys(hose->sg_isa->ptes) >> 1;
apecs_pci_tbi(hose, 0, -1);
*(vuip)APECS_IOC_HAXR2 = 0;
mb();
}
void
apecs_pci_clr_err(void)
{
unsigned int jd;
jd = *(vuip)APECS_IOC_DCSR;
if (jd & 0xffe0L) {
*(vuip)APECS_IOC_SEAR;
*(vuip)APECS_IOC_DCSR = jd | 0xffe1L;
mb();
*(vuip)APECS_IOC_DCSR;
}
*(vuip)APECS_IOC_TBIA = (unsigned int)APECS_IOC_TBIA;
mb();
*(vuip)APECS_IOC_TBIA;
}
void
apecs_machine_check(unsigned long vector, unsigned long la_ptr)
{
struct el_common *mchk_header;
struct el_apecs_procdata *mchk_procdata;
struct el_apecs_sysdata_mcheck *mchk_sysdata;
mchk_header = (struct el_common *)la_ptr;
mchk_procdata = (struct el_apecs_procdata *)
(la_ptr + mchk_header->proc_offset
- sizeof(mchk_procdata->paltemp));
mchk_sysdata = (struct el_apecs_sysdata_mcheck *)
(la_ptr + mchk_header->sys_offset);
mb();
mb();
draina();
apecs_pci_clr_err();
wrmces(0x7);
mb();
process_mcheck_info(vector, la_ptr, "APECS",
(mcheck_expected(0)
&& (mchk_sysdata->epic_dcsr & 0x0c00UL)));
}
