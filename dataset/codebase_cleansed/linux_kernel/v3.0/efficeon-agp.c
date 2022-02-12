static inline unsigned long efficeon_mask_memory(struct page *page)
{
unsigned long addr = page_to_phys(page);
return addr | 0x00000001;
}
static int efficeon_fetch_size(void)
{
int i;
u16 temp;
struct aper_size_info_lvl2 *values;
pci_read_config_word(agp_bridge->dev, INTEL_APSIZE, &temp);
values = A_SIZE_LVL2(agp_bridge->driver->aperture_sizes);
for (i = 0; i < agp_bridge->driver->num_aperture_sizes; i++) {
if (temp == values[i].size_value) {
agp_bridge->previous_size =
agp_bridge->current_size = (void *) (values + i);
agp_bridge->aperture_size_idx = i;
return values[i].size;
}
}
return 0;
}
static void efficeon_tlbflush(struct agp_memory * mem)
{
printk(KERN_DEBUG PFX "efficeon_tlbflush()\n");
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x2200);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x2280);
}
static void efficeon_cleanup(void)
{
u16 temp;
struct aper_size_info_lvl2 *previous_size;
printk(KERN_DEBUG PFX "efficeon_cleanup()\n");
previous_size = A_SIZE_LVL2(agp_bridge->previous_size);
pci_read_config_word(agp_bridge->dev, INTEL_NBXCFG, &temp);
pci_write_config_word(agp_bridge->dev, INTEL_NBXCFG, temp & ~(1 << 9));
pci_write_config_word(agp_bridge->dev, INTEL_APSIZE,
previous_size->size_value);
}
static int efficeon_configure(void)
{
u32 temp;
u16 temp2;
struct aper_size_info_lvl2 *current_size;
printk(KERN_DEBUG PFX "efficeon_configure()\n");
current_size = A_SIZE_LVL2(agp_bridge->current_size);
pci_write_config_word(agp_bridge->dev, INTEL_APSIZE,
current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x2280);
pci_read_config_word(agp_bridge->dev, INTEL_NBXCFG, &temp2);
pci_write_config_word(agp_bridge->dev, INTEL_NBXCFG,
(temp2 & ~(1 << 10)) | (1 << 9) | (1 << 11));
pci_write_config_byte(agp_bridge->dev, INTEL_ERRSTS + 1, 7);
return 0;
}
static int efficeon_free_gatt_table(struct agp_bridge_data *bridge)
{
int index, freed = 0;
for (index = 0; index < EFFICEON_L1_SIZE; index++) {
unsigned long page = efficeon_private.l1_table[index];
if (page) {
efficeon_private.l1_table[index] = 0;
ClearPageReserved(virt_to_page((char *)page));
free_page(page);
freed++;
}
printk(KERN_DEBUG PFX "efficeon_free_gatt_table(%p, %02x, %08x)\n",
agp_bridge->dev, EFFICEON_ATTPAGE, index);
pci_write_config_dword(agp_bridge->dev,
EFFICEON_ATTPAGE, index);
}
printk(KERN_DEBUG PFX "efficeon_free_gatt_table() freed %d pages\n", freed);
return 0;
}
static int efficeon_create_gatt_table(struct agp_bridge_data *bridge)
{
int index;
const int pati = EFFICEON_PATI;
const int present = EFFICEON_PRESENT;
const int clflush_chunk = ((cpuid_ebx(1) >> 8) & 0xff) << 3;
int num_entries, l1_pages;
num_entries = A_SIZE_LVL2(agp_bridge->current_size)->num_entries;
printk(KERN_DEBUG PFX "efficeon_create_gatt_table(%d)\n", num_entries);
BUG_ON(num_entries & 0x3ff);
l1_pages = num_entries >> 10;
for (index = 0 ; index < l1_pages ; index++) {
int offset;
unsigned long page;
unsigned long value;
page = efficeon_private.l1_table[index];
BUG_ON(page);
page = get_zeroed_page(GFP_KERNEL);
if (!page) {
efficeon_free_gatt_table(agp_bridge);
return -ENOMEM;
}
SetPageReserved(virt_to_page((char *)page));
for (offset = 0; offset < PAGE_SIZE; offset += clflush_chunk)
clflush((char *)page+offset);
efficeon_private.l1_table[index] = page;
value = virt_to_phys((unsigned long *)page) | pati | present | index;
pci_write_config_dword(agp_bridge->dev,
EFFICEON_ATTPAGE, value);
}
return 0;
}
static int efficeon_insert_memory(struct agp_memory * mem, off_t pg_start, int type)
{
int i, count = mem->page_count, num_entries;
unsigned int *page, *last_page;
const int clflush_chunk = ((cpuid_ebx(1) >> 8) & 0xff) << 3;
const unsigned long clflush_mask = ~(clflush_chunk-1);
printk(KERN_DEBUG PFX "efficeon_insert_memory(%lx, %d)\n", pg_start, count);
num_entries = A_SIZE_LVL2(agp_bridge->current_size)->num_entries;
if ((pg_start + mem->page_count) > num_entries)
return -EINVAL;
if (type != 0 || mem->type != 0)
return -EINVAL;
if (!mem->is_flushed) {
global_cache_flush();
mem->is_flushed = true;
}
last_page = NULL;
for (i = 0; i < count; i++) {
int index = pg_start + i;
unsigned long insert = efficeon_mask_memory(mem->pages[i]);
page = (unsigned int *) efficeon_private.l1_table[index >> 10];
if (!page)
continue;
page += (index & 0x3ff);
*page = insert;
if (last_page &&
(((unsigned long)page^(unsigned long)last_page) &
clflush_mask))
clflush(last_page);
last_page = page;
}
if ( last_page )
clflush(last_page);
agp_bridge->driver->tlb_flush(mem);
return 0;
}
static int efficeon_remove_memory(struct agp_memory * mem, off_t pg_start, int type)
{
int i, count = mem->page_count, num_entries;
printk(KERN_DEBUG PFX "efficeon_remove_memory(%lx, %d)\n", pg_start, count);
num_entries = A_SIZE_LVL2(agp_bridge->current_size)->num_entries;
if ((pg_start + mem->page_count) > num_entries)
return -EINVAL;
if (type != 0 || mem->type != 0)
return -EINVAL;
for (i = 0; i < count; i++) {
int index = pg_start + i;
unsigned int *page = (unsigned int *) efficeon_private.l1_table[index >> 10];
if (!page)
continue;
page += (index & 0x3ff);
*page = 0;
}
agp_bridge->driver->tlb_flush(mem);
return 0;
}
static int __devinit agp_efficeon_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct agp_bridge_data *bridge;
u8 cap_ptr;
struct resource *r;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
if (!cap_ptr)
return -ENODEV;
if (pdev->device != PCI_DEVICE_ID_EFFICEON) {
printk(KERN_ERR PFX "Unsupported Efficeon chipset (device id: %04x)\n",
pdev->device);
return -ENODEV;
}
printk(KERN_INFO PFX "Detected Transmeta Efficeon TM8000 series chipset\n");
bridge = agp_alloc_bridge();
if (!bridge)
return -ENOMEM;
bridge->driver = &efficeon_driver;
bridge->dev = pdev;
bridge->capndx = cap_ptr;
if (pci_enable_device(pdev)) {
printk(KERN_ERR PFX "Unable to Enable PCI device\n");
agp_put_bridge(bridge);
return -ENODEV;
}
r = &pdev->resource[0];
if (!r->start && r->end) {
if (pci_assign_resource(pdev, 0)) {
printk(KERN_ERR PFX "could not assign resource 0\n");
agp_put_bridge(bridge);
return -ENODEV;
}
}
if (cap_ptr) {
pci_read_config_dword(pdev,
bridge->capndx+PCI_AGP_STATUS,
&bridge->mode);
}
pci_set_drvdata(pdev, bridge);
return agp_add_bridge(bridge);
}
static void __devexit agp_efficeon_remove(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
agp_remove_bridge(bridge);
agp_put_bridge(bridge);
}
static int agp_efficeon_suspend(struct pci_dev *dev, pm_message_t state)
{
return 0;
}
static int agp_efficeon_resume(struct pci_dev *pdev)
{
printk(KERN_DEBUG PFX "agp_efficeon_resume()\n");
return efficeon_configure();
}
static int __init agp_efficeon_init(void)
{
static int agp_initialised=0;
if (agp_off)
return -EINVAL;
if (agp_initialised == 1)
return 0;
agp_initialised=1;
return pci_register_driver(&agp_efficeon_pci_driver);
}
static void __exit agp_efficeon_cleanup(void)
{
pci_unregister_driver(&agp_efficeon_pci_driver);
}
