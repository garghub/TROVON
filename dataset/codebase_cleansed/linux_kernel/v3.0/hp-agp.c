static int __init hp_zx1_ioc_shared(void)
{
struct _hp_private *hp = &hp_private;
printk(KERN_INFO PFX "HP ZX1 IOC: IOPDIR shared with sba_iommu\n");
hp->io_tlb_ps = readq(hp->ioc_regs+HP_ZX1_TCNFG);
switch (hp->io_tlb_ps) {
case 0: hp->io_tlb_shift = 12; break;
case 1: hp->io_tlb_shift = 13; break;
case 2: hp->io_tlb_shift = 14; break;
case 3: hp->io_tlb_shift = 16; break;
default:
printk(KERN_ERR PFX "Invalid IOTLB page size "
"configuration 0x%x\n", hp->io_tlb_ps);
hp->gatt = NULL;
hp->gatt_entries = 0;
return -ENODEV;
}
hp->io_page_size = 1 << hp->io_tlb_shift;
hp->io_pages_per_kpage = PAGE_SIZE / hp->io_page_size;
hp->iova_base = readq(hp->ioc_regs+HP_ZX1_IBASE) & ~0x1;
hp->gart_base = hp->iova_base + HP_ZX1_IOVA_SIZE - HP_ZX1_GART_SIZE;
hp->gart_size = HP_ZX1_GART_SIZE;
hp->gatt_entries = hp->gart_size / hp->io_page_size;
hp->io_pdir = phys_to_virt(readq(hp->ioc_regs+HP_ZX1_PDIR_BASE));
hp->gatt = &hp->io_pdir[HP_ZX1_IOVA_TO_PDIR(hp->gart_base)];
if (hp->gatt[0] != HP_ZX1_SBA_IOMMU_COOKIE) {
hp->gatt = NULL;
hp->gatt_entries = 0;
printk(KERN_ERR PFX "No reserved IO PDIR entry found; "
"GART disabled\n");
return -ENODEV;
}
return 0;
}
static int __init
hp_zx1_ioc_owner (void)
{
struct _hp_private *hp = &hp_private;
printk(KERN_INFO PFX "HP ZX1 IOC: IOPDIR dedicated to GART\n");
if (PAGE_SIZE >= KB(64)) {
hp->io_tlb_shift = 16;
hp->io_tlb_ps = 3;
} else if (PAGE_SIZE >= KB(16)) {
hp->io_tlb_shift = 14;
hp->io_tlb_ps = 2;
} else if (PAGE_SIZE >= KB(8)) {
hp->io_tlb_shift = 13;
hp->io_tlb_ps = 1;
} else {
hp->io_tlb_shift = 12;
hp->io_tlb_ps = 0;
}
hp->io_page_size = 1 << hp->io_tlb_shift;
hp->io_pages_per_kpage = PAGE_SIZE / hp->io_page_size;
hp->iova_base = HP_ZX1_IOVA_BASE;
hp->gart_size = HP_ZX1_GART_SIZE;
hp->gart_base = hp->iova_base + HP_ZX1_IOVA_SIZE - hp->gart_size;
hp->gatt_entries = hp->gart_size / hp->io_page_size;
hp->io_pdir_size = (HP_ZX1_IOVA_SIZE / hp->io_page_size) * sizeof(u64);
return 0;
}
static int __init
hp_zx1_ioc_init (u64 hpa)
{
struct _hp_private *hp = &hp_private;
hp->ioc_regs = ioremap(hpa, 1024);
if (!hp->ioc_regs)
return -ENOMEM;
hp->io_pdir_owner = (readq(hp->ioc_regs+HP_ZX1_IBASE) & 0x1) == 0;
if (hp->io_pdir_owner)
return hp_zx1_ioc_owner();
return hp_zx1_ioc_shared();
}
static int
hp_zx1_lba_find_capability (volatile u8 __iomem *hpa, int cap)
{
u16 status;
u8 pos, id;
int ttl = 48;
status = readw(hpa+PCI_STATUS);
if (!(status & PCI_STATUS_CAP_LIST))
return 0;
pos = readb(hpa+PCI_CAPABILITY_LIST);
while (ttl-- && pos >= 0x40) {
pos &= ~3;
id = readb(hpa+pos+PCI_CAP_LIST_ID);
if (id == 0xff)
break;
if (id == cap)
return pos;
pos = readb(hpa+pos+PCI_CAP_LIST_NEXT);
}
return 0;
}
static int __init
hp_zx1_lba_init (u64 hpa)
{
struct _hp_private *hp = &hp_private;
int cap;
hp->lba_regs = ioremap(hpa, 256);
if (!hp->lba_regs)
return -ENOMEM;
hp->lba_cap_offset = hp_zx1_lba_find_capability(hp->lba_regs, PCI_CAP_ID_AGP);
cap = readl(hp->lba_regs+hp->lba_cap_offset) & 0xff;
if (cap != PCI_CAP_ID_AGP) {
printk(KERN_ERR PFX "Invalid capability ID 0x%02x at 0x%x\n",
cap, hp->lba_cap_offset);
iounmap(hp->lba_regs);
return -ENODEV;
}
return 0;
}
static int
hp_zx1_fetch_size(void)
{
int size;
size = hp_private.gart_size / MB(1);
hp_zx1_sizes[0].size = size;
agp_bridge->current_size = (void *) &hp_zx1_sizes[0];
return size;
}
static int
hp_zx1_configure (void)
{
struct _hp_private *hp = &hp_private;
agp_bridge->gart_bus_addr = hp->gart_base;
agp_bridge->capndx = hp->lba_cap_offset;
agp_bridge->mode = readl(hp->lba_regs+hp->lba_cap_offset+PCI_AGP_STATUS);
if (hp->io_pdir_owner) {
writel(virt_to_phys(hp->io_pdir), hp->ioc_regs+HP_ZX1_PDIR_BASE);
readl(hp->ioc_regs+HP_ZX1_PDIR_BASE);
writel(hp->io_tlb_ps, hp->ioc_regs+HP_ZX1_TCNFG);
readl(hp->ioc_regs+HP_ZX1_TCNFG);
writel((unsigned int)(~(HP_ZX1_IOVA_SIZE-1)), hp->ioc_regs+HP_ZX1_IMASK);
readl(hp->ioc_regs+HP_ZX1_IMASK);
writel(hp->iova_base|1, hp->ioc_regs+HP_ZX1_IBASE);
readl(hp->ioc_regs+HP_ZX1_IBASE);
writel(hp->iova_base|ilog2(HP_ZX1_IOVA_SIZE), hp->ioc_regs+HP_ZX1_PCOM);
readl(hp->ioc_regs+HP_ZX1_PCOM);
}
return 0;
}
static void
hp_zx1_cleanup (void)
{
struct _hp_private *hp = &hp_private;
if (hp->ioc_regs) {
if (hp->io_pdir_owner) {
writeq(0, hp->ioc_regs+HP_ZX1_IBASE);
readq(hp->ioc_regs+HP_ZX1_IBASE);
}
iounmap(hp->ioc_regs);
}
if (hp->lba_regs)
iounmap(hp->lba_regs);
}
static void
hp_zx1_tlbflush (struct agp_memory *mem)
{
struct _hp_private *hp = &hp_private;
writeq(hp->gart_base | ilog2(hp->gart_size), hp->ioc_regs+HP_ZX1_PCOM);
readq(hp->ioc_regs+HP_ZX1_PCOM);
}
static int
hp_zx1_create_gatt_table (struct agp_bridge_data *bridge)
{
struct _hp_private *hp = &hp_private;
int i;
if (hp->io_pdir_owner) {
hp->io_pdir = (u64 *) __get_free_pages(GFP_KERNEL,
get_order(hp->io_pdir_size));
if (!hp->io_pdir) {
printk(KERN_ERR PFX "Couldn't allocate contiguous "
"memory for I/O PDIR\n");
hp->gatt = NULL;
hp->gatt_entries = 0;
return -ENOMEM;
}
memset(hp->io_pdir, 0, hp->io_pdir_size);
hp->gatt = &hp->io_pdir[HP_ZX1_IOVA_TO_PDIR(hp->gart_base)];
}
for (i = 0; i < hp->gatt_entries; i++) {
hp->gatt[i] = (unsigned long) agp_bridge->scratch_page;
}
return 0;
}
static int
hp_zx1_free_gatt_table (struct agp_bridge_data *bridge)
{
struct _hp_private *hp = &hp_private;
if (hp->io_pdir_owner)
free_pages((unsigned long) hp->io_pdir,
get_order(hp->io_pdir_size));
else
hp->gatt[0] = HP_ZX1_SBA_IOMMU_COOKIE;
return 0;
}
static int
hp_zx1_insert_memory (struct agp_memory *mem, off_t pg_start, int type)
{
struct _hp_private *hp = &hp_private;
int i, k;
off_t j, io_pg_start;
int io_pg_count;
if (type != 0 || mem->type != 0) {
return -EINVAL;
}
io_pg_start = hp->io_pages_per_kpage * pg_start;
io_pg_count = hp->io_pages_per_kpage * mem->page_count;
if ((io_pg_start + io_pg_count) > hp->gatt_entries) {
return -EINVAL;
}
j = io_pg_start;
while (j < (io_pg_start + io_pg_count)) {
if (hp->gatt[j]) {
return -EBUSY;
}
j++;
}
if (!mem->is_flushed) {
global_cache_flush();
mem->is_flushed = true;
}
for (i = 0, j = io_pg_start; i < mem->page_count; i++) {
unsigned long paddr;
paddr = page_to_phys(mem->pages[i]);
for (k = 0;
k < hp->io_pages_per_kpage;
k++, j++, paddr += hp->io_page_size) {
hp->gatt[j] = HP_ZX1_PDIR_VALID_BIT | paddr;
}
}
agp_bridge->driver->tlb_flush(mem);
return 0;
}
static int
hp_zx1_remove_memory (struct agp_memory *mem, off_t pg_start, int type)
{
struct _hp_private *hp = &hp_private;
int i, io_pg_start, io_pg_count;
if (type != 0 || mem->type != 0) {
return -EINVAL;
}
io_pg_start = hp->io_pages_per_kpage * pg_start;
io_pg_count = hp->io_pages_per_kpage * mem->page_count;
for (i = io_pg_start; i < io_pg_count + io_pg_start; i++) {
hp->gatt[i] = agp_bridge->scratch_page;
}
agp_bridge->driver->tlb_flush(mem);
return 0;
}
static unsigned long
hp_zx1_mask_memory (struct agp_bridge_data *bridge, dma_addr_t addr, int type)
{
return HP_ZX1_PDIR_VALID_BIT | addr;
}
static void
hp_zx1_enable (struct agp_bridge_data *bridge, u32 mode)
{
struct _hp_private *hp = &hp_private;
u32 command;
command = readl(hp->lba_regs+hp->lba_cap_offset+PCI_AGP_STATUS);
command = agp_collect_device_status(bridge, mode, command);
command |= 0x00000100;
writel(command, hp->lba_regs+hp->lba_cap_offset+PCI_AGP_COMMAND);
agp_device_command(command, (mode & AGP8X_MODE) != 0);
}
static int __init
hp_zx1_setup (u64 ioc_hpa, u64 lba_hpa)
{
struct agp_bridge_data *bridge;
int error = 0;
error = hp_zx1_ioc_init(ioc_hpa);
if (error)
goto fail;
error = hp_zx1_lba_init(lba_hpa);
if (error)
goto fail;
bridge = agp_alloc_bridge();
if (!bridge) {
error = -ENOMEM;
goto fail;
}
bridge->driver = &hp_zx1_driver;
fake_bridge_dev.vendor = PCI_VENDOR_ID_HP;
fake_bridge_dev.device = PCI_DEVICE_ID_HP_PCIX_LBA;
bridge->dev = &fake_bridge_dev;
error = agp_add_bridge(bridge);
fail:
if (error)
hp_zx1_cleanup();
return error;
}
static acpi_status __init
zx1_gart_probe (acpi_handle obj, u32 depth, void *context, void **ret)
{
acpi_handle handle, parent;
acpi_status status;
struct acpi_device_info *info;
u64 lba_hpa, sba_hpa, length;
int match;
status = hp_acpi_csr_space(obj, &lba_hpa, &length);
if (ACPI_FAILURE(status))
return AE_OK;
handle = obj;
do {
status = acpi_get_object_info(handle, &info);
if (ACPI_SUCCESS(status) && (info->valid & ACPI_VALID_HID)) {
match = (strcmp(info->hardware_id.string, "HWP0001") == 0);
kfree(info);
if (match) {
status = hp_acpi_csr_space(handle, &sba_hpa, &length);
if (ACPI_SUCCESS(status))
break;
else {
printk(KERN_ERR PFX "Detected HP ZX1 "
"AGP LBA but no IOC.\n");
return AE_OK;
}
}
}
status = acpi_get_parent(handle, &parent);
handle = parent;
} while (ACPI_SUCCESS(status));
if (ACPI_FAILURE(status))
return AE_OK;
if (hp_zx1_setup(sba_hpa + HP_ZX1_IOC_OFFSET, lba_hpa))
return AE_OK;
printk(KERN_INFO PFX "Detected HP ZX1 %s AGP chipset "
"(ioc=%llx, lba=%llx)\n", (char *)context,
sba_hpa + HP_ZX1_IOC_OFFSET, lba_hpa);
hp_zx1_gart_found = 1;
return AE_CTRL_TERMINATE;
}
static int __init
agp_hp_init (void)
{
if (agp_off)
return -EINVAL;
acpi_get_devices("HWP0003", zx1_gart_probe, "HWP0003", NULL);
if (hp_zx1_gart_found)
return 0;
acpi_get_devices("HWP0007", zx1_gart_probe, "HWP0007", NULL);
if (hp_zx1_gart_found)
return 0;
return -ENODEV;
}
static void __exit
agp_hp_cleanup (void)
{
}
