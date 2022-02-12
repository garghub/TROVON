static int amd_create_page_map(struct amd_page_map *page_map)
{
int i;
page_map->real = (unsigned long *) __get_free_page(GFP_KERNEL);
if (page_map->real == NULL)
return -ENOMEM;
set_memory_uc((unsigned long)page_map->real, 1);
page_map->remapped = page_map->real;
for (i = 0; i < PAGE_SIZE / sizeof(unsigned long); i++) {
writel(agp_bridge->scratch_page, page_map->remapped+i);
readl(page_map->remapped+i);
}
return 0;
}
static void amd_free_page_map(struct amd_page_map *page_map)
{
set_memory_wb((unsigned long)page_map->real, 1);
free_page((unsigned long) page_map->real);
}
static void amd_free_gatt_pages(void)
{
int i;
struct amd_page_map **tables;
struct amd_page_map *entry;
tables = amd_irongate_private.gatt_pages;
for (i = 0; i < amd_irongate_private.num_tables; i++) {
entry = tables[i];
if (entry != NULL) {
if (entry->real != NULL)
amd_free_page_map(entry);
kfree(entry);
}
}
kfree(tables);
amd_irongate_private.gatt_pages = NULL;
}
static int amd_create_gatt_pages(int nr_tables)
{
struct amd_page_map **tables;
struct amd_page_map *entry;
int retval = 0;
int i;
tables = kzalloc((nr_tables + 1) * sizeof(struct amd_page_map *),GFP_KERNEL);
if (tables == NULL)
return -ENOMEM;
for (i = 0; i < nr_tables; i++) {
entry = kzalloc(sizeof(struct amd_page_map), GFP_KERNEL);
tables[i] = entry;
if (entry == NULL) {
retval = -ENOMEM;
break;
}
retval = amd_create_page_map(entry);
if (retval != 0)
break;
}
amd_irongate_private.num_tables = i;
amd_irongate_private.gatt_pages = tables;
if (retval != 0)
amd_free_gatt_pages();
return retval;
}
static int amd_create_gatt_table(struct agp_bridge_data *bridge)
{
struct aper_size_info_lvl2 *value;
struct amd_page_map page_dir;
unsigned long __iomem *cur_gatt;
unsigned long addr;
int retval;
u32 temp;
int i;
value = A_SIZE_LVL2(agp_bridge->current_size);
retval = amd_create_page_map(&page_dir);
if (retval != 0)
return retval;
retval = amd_create_gatt_pages(value->num_entries / 1024);
if (retval != 0) {
amd_free_page_map(&page_dir);
return retval;
}
agp_bridge->gatt_table_real = (u32 *)page_dir.real;
agp_bridge->gatt_table = (u32 __iomem *)page_dir.remapped;
agp_bridge->gatt_bus_addr = virt_to_phys(page_dir.real);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
agp_bridge->gart_bus_addr = addr;
for (i = 0; i < value->num_entries / 1024; i++, addr += 0x00400000) {
writel(virt_to_phys(amd_irongate_private.gatt_pages[i]->real) | 1,
page_dir.remapped+GET_PAGE_DIR_OFF(addr));
readl(page_dir.remapped+GET_PAGE_DIR_OFF(addr));
}
for (i = 0; i < value->num_entries; i++) {
addr = (i * PAGE_SIZE) + agp_bridge->gart_bus_addr;
cur_gatt = GET_GATT(addr);
writel(agp_bridge->scratch_page, cur_gatt+GET_GATT_OFF(addr));
readl(cur_gatt+GET_GATT_OFF(addr));
}
return 0;
}
static int amd_free_gatt_table(struct agp_bridge_data *bridge)
{
struct amd_page_map page_dir;
page_dir.real = (unsigned long *)agp_bridge->gatt_table_real;
page_dir.remapped = (unsigned long __iomem *)agp_bridge->gatt_table;
amd_free_gatt_pages();
amd_free_page_map(&page_dir);
return 0;
}
static int amd_irongate_fetch_size(void)
{
int i;
u32 temp;
struct aper_size_info_lvl2 *values;
pci_read_config_dword(agp_bridge->dev, AMD_APSIZE, &temp);
temp = (temp & 0x0000000e);
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
static int amd_irongate_configure(void)
{
struct aper_size_info_lvl2 *current_size;
u32 temp;
u16 enable_reg;
current_size = A_SIZE_LVL2(agp_bridge->current_size);
if (!amd_irongate_private.registers) {
pci_read_config_dword(agp_bridge->dev, AMD_MMBASE, &temp);
temp = (temp & PCI_BASE_ADDRESS_MEM_MASK);
amd_irongate_private.registers = (volatile u8 __iomem *) ioremap(temp, 4096);
if (!amd_irongate_private.registers)
return -ENOMEM;
}
writel(agp_bridge->gatt_bus_addr, amd_irongate_private.registers+AMD_ATTBASE);
readl(amd_irongate_private.registers+AMD_ATTBASE);
pci_write_config_byte(agp_bridge->dev, AMD_MODECNTL, 0x80);
pci_write_config_byte(agp_bridge->dev, AMD_MODECNTL2, 0x00);
enable_reg = readw(amd_irongate_private.registers+AMD_GARTENABLE);
enable_reg = (enable_reg | 0x0004);
writew(enable_reg, amd_irongate_private.registers+AMD_GARTENABLE);
readw(amd_irongate_private.registers+AMD_GARTENABLE);
pci_read_config_dword(agp_bridge->dev, AMD_APSIZE, &temp);
temp = (((temp & ~(0x0000000e)) | current_size->size_value) | 1);
pci_write_config_dword(agp_bridge->dev, AMD_APSIZE, temp);
writel(1, amd_irongate_private.registers+AMD_TLBFLUSH);
readl(amd_irongate_private.registers+AMD_TLBFLUSH);
return 0;
}
static void amd_irongate_cleanup(void)
{
struct aper_size_info_lvl2 *previous_size;
u32 temp;
u16 enable_reg;
previous_size = A_SIZE_LVL2(agp_bridge->previous_size);
enable_reg = readw(amd_irongate_private.registers+AMD_GARTENABLE);
enable_reg = (enable_reg & ~(0x0004));
writew(enable_reg, amd_irongate_private.registers+AMD_GARTENABLE);
readw(amd_irongate_private.registers+AMD_GARTENABLE);
pci_read_config_dword(agp_bridge->dev, AMD_APSIZE, &temp);
temp = ((temp & ~(0x0000000f)) | previous_size->size_value);
pci_write_config_dword(agp_bridge->dev, AMD_APSIZE, temp);
iounmap((void __iomem *) amd_irongate_private.registers);
}
static void amd_irongate_tlbflush(struct agp_memory *temp)
{
writel(1, amd_irongate_private.registers+AMD_TLBFLUSH);
readl(amd_irongate_private.registers+AMD_TLBFLUSH);
}
static int amd_insert_memory(struct agp_memory *mem, off_t pg_start, int type)
{
int i, j, num_entries;
unsigned long __iomem *cur_gatt;
unsigned long addr;
num_entries = A_SIZE_LVL2(agp_bridge->current_size)->num_entries;
if (type != mem->type ||
agp_bridge->driver->agp_type_to_mask_type(agp_bridge, type))
return -EINVAL;
if ((pg_start + mem->page_count) > num_entries)
return -EINVAL;
j = pg_start;
while (j < (pg_start + mem->page_count)) {
addr = (j * PAGE_SIZE) + agp_bridge->gart_bus_addr;
cur_gatt = GET_GATT(addr);
if (!PGE_EMPTY(agp_bridge, readl(cur_gatt+GET_GATT_OFF(addr))))
return -EBUSY;
j++;
}
if (!mem->is_flushed) {
global_cache_flush();
mem->is_flushed = true;
}
for (i = 0, j = pg_start; i < mem->page_count; i++, j++) {
addr = (j * PAGE_SIZE) + agp_bridge->gart_bus_addr;
cur_gatt = GET_GATT(addr);
writel(agp_generic_mask_memory(agp_bridge,
page_to_phys(mem->pages[i]),
mem->type),
cur_gatt+GET_GATT_OFF(addr));
readl(cur_gatt+GET_GATT_OFF(addr));
}
amd_irongate_tlbflush(mem);
return 0;
}
static int amd_remove_memory(struct agp_memory *mem, off_t pg_start, int type)
{
int i;
unsigned long __iomem *cur_gatt;
unsigned long addr;
if (type != mem->type ||
agp_bridge->driver->agp_type_to_mask_type(agp_bridge, type))
return -EINVAL;
for (i = pg_start; i < (mem->page_count + pg_start); i++) {
addr = (i * PAGE_SIZE) + agp_bridge->gart_bus_addr;
cur_gatt = GET_GATT(addr);
writel(agp_bridge->scratch_page, cur_gatt+GET_GATT_OFF(addr));
readl(cur_gatt+GET_GATT_OFF(addr));
}
amd_irongate_tlbflush(mem);
return 0;
}
static int agp_amdk7_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct agp_bridge_data *bridge;
u8 cap_ptr;
int j;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
if (!cap_ptr)
return -ENODEV;
j = ent - agp_amdk7_pci_table;
dev_info(&pdev->dev, "AMD %s chipset\n",
amd_agp_device_ids[j].chipset_name);
bridge = agp_alloc_bridge();
if (!bridge)
return -ENOMEM;
bridge->driver = &amd_irongate_driver;
bridge->dev_private_data = &amd_irongate_private,
bridge->dev = pdev;
bridge->capndx = cap_ptr;
if (agp_bridge->dev->device == PCI_DEVICE_ID_AMD_FE_GATE_7006) {
struct pci_dev *gfxcard=NULL;
cap_ptr = 0;
while (!cap_ptr) {
gfxcard = pci_get_class(PCI_CLASS_DISPLAY_VGA<<8, gfxcard);
if (!gfxcard) {
dev_info(&pdev->dev, "no AGP VGA controller\n");
return -ENODEV;
}
cap_ptr = pci_find_capability(gfxcard, PCI_CAP_ID_AGP);
}
if (gfxcard->vendor == PCI_VENDOR_ID_NVIDIA) {
agp_bridge->flags |= AGP_ERRATA_1X;
dev_info(&pdev->dev, "AMD 751 chipset with NVidia GeForce; forcing 1X due to errata\n");
}
pci_dev_put(gfxcard);
}
if (agp_bridge->dev->device == PCI_DEVICE_ID_AMD_FE_GATE_700E) {
if (pdev->revision == 0x10 || pdev->revision == 0x11) {
agp_bridge->flags = AGP_ERRATA_FASTWRITES;
agp_bridge->flags |= AGP_ERRATA_SBA;
agp_bridge->flags |= AGP_ERRATA_1X;
dev_info(&pdev->dev, "AMD 761 chipset with errata; disabling AGP fast writes & SBA and forcing to 1X\n");
}
}
pci_read_config_dword(pdev,
bridge->capndx+PCI_AGP_STATUS,
&bridge->mode);
pci_set_drvdata(pdev, bridge);
return agp_add_bridge(bridge);
}
static void agp_amdk7_remove(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
agp_remove_bridge(bridge);
agp_put_bridge(bridge);
}
static int agp_amdk7_suspend(struct pci_dev *pdev, pm_message_t state)
{
pci_save_state(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int agp_amdk7_resume(struct pci_dev *pdev)
{
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
return amd_irongate_driver.configure();
}
static int __init agp_amdk7_init(void)
{
if (agp_off)
return -EINVAL;
return pci_register_driver(&agp_amdk7_pci_driver);
}
static void __exit agp_amdk7_cleanup(void)
{
pci_unregister_driver(&agp_amdk7_pci_driver);
}
