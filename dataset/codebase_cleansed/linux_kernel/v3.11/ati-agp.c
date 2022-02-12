static int ati_create_page_map(struct ati_page_map *page_map)
{
int i, err = 0;
page_map->real = (unsigned long *) __get_free_page(GFP_KERNEL);
if (page_map->real == NULL)
return -ENOMEM;
set_memory_uc((unsigned long)page_map->real, 1);
err = map_page_into_agp(virt_to_page(page_map->real));
page_map->remapped = page_map->real;
for (i = 0; i < PAGE_SIZE / sizeof(unsigned long); i++) {
writel(agp_bridge->scratch_page, page_map->remapped+i);
readl(page_map->remapped+i);
}
return 0;
}
static void ati_free_page_map(struct ati_page_map *page_map)
{
unmap_page_from_agp(virt_to_page(page_map->real));
set_memory_wb((unsigned long)page_map->real, 1);
free_page((unsigned long) page_map->real);
}
static void ati_free_gatt_pages(void)
{
int i;
struct ati_page_map **tables;
struct ati_page_map *entry;
tables = ati_generic_private.gatt_pages;
for (i = 0; i < ati_generic_private.num_tables; i++) {
entry = tables[i];
if (entry != NULL) {
if (entry->real != NULL)
ati_free_page_map(entry);
kfree(entry);
}
}
kfree(tables);
}
static int ati_create_gatt_pages(int nr_tables)
{
struct ati_page_map **tables;
struct ati_page_map *entry;
int retval = 0;
int i;
tables = kzalloc((nr_tables + 1) * sizeof(struct ati_page_map *),GFP_KERNEL);
if (tables == NULL)
return -ENOMEM;
for (i = 0; i < nr_tables; i++) {
entry = kzalloc(sizeof(struct ati_page_map), GFP_KERNEL);
tables[i] = entry;
if (entry == NULL) {
retval = -ENOMEM;
break;
}
retval = ati_create_page_map(entry);
if (retval != 0)
break;
}
ati_generic_private.num_tables = i;
ati_generic_private.gatt_pages = tables;
if (retval != 0)
ati_free_gatt_pages();
return retval;
}
static int is_r200(void)
{
if ((agp_bridge->dev->device == PCI_DEVICE_ID_ATI_RS100) ||
(agp_bridge->dev->device == PCI_DEVICE_ID_ATI_RS200) ||
(agp_bridge->dev->device == PCI_DEVICE_ID_ATI_RS200_B) ||
(agp_bridge->dev->device == PCI_DEVICE_ID_ATI_RS250))
return 1;
return 0;
}
static int ati_fetch_size(void)
{
int i;
u32 temp;
struct aper_size_info_lvl2 *values;
if (is_r200())
pci_read_config_dword(agp_bridge->dev, ATI_RS100_APSIZE, &temp);
else
pci_read_config_dword(agp_bridge->dev, ATI_RS300_APSIZE, &temp);
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
static void ati_tlbflush(struct agp_memory * mem)
{
writel(1, ati_generic_private.registers+ATI_GART_CACHE_CNTRL);
readl(ati_generic_private.registers+ATI_GART_CACHE_CNTRL);
}
static void ati_cleanup(void)
{
struct aper_size_info_lvl2 *previous_size;
u32 temp;
previous_size = A_SIZE_LVL2(agp_bridge->previous_size);
if (is_r200()) {
pci_read_config_dword(agp_bridge->dev, ATI_RS100_APSIZE, &temp);
temp = ((temp & ~(0x0000000f)) | previous_size->size_value);
pci_write_config_dword(agp_bridge->dev, ATI_RS100_APSIZE, temp);
} else {
pci_read_config_dword(agp_bridge->dev, ATI_RS300_APSIZE, &temp);
temp = ((temp & ~(0x0000000f)) | previous_size->size_value);
pci_write_config_dword(agp_bridge->dev, ATI_RS300_APSIZE, temp);
}
iounmap((volatile u8 __iomem *)ati_generic_private.registers);
}
static int ati_configure(void)
{
u32 temp;
pci_read_config_dword(agp_bridge->dev, ATI_GART_MMBASE_ADDR, &temp);
temp = (temp & 0xfffff000);
ati_generic_private.registers = (volatile u8 __iomem *) ioremap(temp, 4096);
if (!ati_generic_private.registers)
return -ENOMEM;
if (is_r200())
pci_write_config_dword(agp_bridge->dev, ATI_RS100_IG_AGPMODE, 0x20000);
else
pci_write_config_dword(agp_bridge->dev, ATI_RS300_IG_AGPMODE, 0x20000);
writel(0x60000, ati_generic_private.registers+ATI_GART_FEATURE_ID);
readl(ati_generic_private.registers+ATI_GART_FEATURE_ID);
pci_read_config_dword(agp_bridge->dev, 4, &temp);
pci_write_config_dword(agp_bridge->dev, 4, temp | (1<<14));
writel(agp_bridge->gatt_bus_addr, ati_generic_private.registers+ATI_GART_BASE);
readl(ati_generic_private.registers+ATI_GART_BASE);
return 0;
}
static int agp_ati_suspend(struct pci_dev *dev, pm_message_t state)
{
pci_save_state(dev);
pci_set_power_state(dev, PCI_D3hot);
return 0;
}
static int agp_ati_resume(struct pci_dev *dev)
{
pci_set_power_state(dev, PCI_D0);
pci_restore_state(dev);
return ati_configure();
}
static int ati_insert_memory(struct agp_memory * mem,
off_t pg_start, int type)
{
int i, j, num_entries;
unsigned long __iomem *cur_gatt;
unsigned long addr;
int mask_type;
num_entries = A_SIZE_LVL2(agp_bridge->current_size)->num_entries;
mask_type = agp_generic_type_to_mask_type(mem->bridge, type);
if (mask_type != 0 || type != mem->type)
return -EINVAL;
if (mem->page_count == 0)
return 0;
if ((pg_start + mem->page_count) > num_entries)
return -EINVAL;
j = pg_start;
while (j < (pg_start + mem->page_count)) {
addr = (j * PAGE_SIZE) + agp_bridge->gart_bus_addr;
cur_gatt = GET_GATT(addr);
if (!PGE_EMPTY(agp_bridge,readl(cur_gatt+GET_GATT_OFF(addr))))
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
writel(agp_bridge->driver->mask_memory(agp_bridge,
page_to_phys(mem->pages[i]),
mem->type),
cur_gatt+GET_GATT_OFF(addr));
}
readl(GET_GATT(agp_bridge->gart_bus_addr));
agp_bridge->driver->tlb_flush(mem);
return 0;
}
static int ati_remove_memory(struct agp_memory * mem, off_t pg_start,
int type)
{
int i;
unsigned long __iomem *cur_gatt;
unsigned long addr;
int mask_type;
mask_type = agp_generic_type_to_mask_type(mem->bridge, type);
if (mask_type != 0 || type != mem->type)
return -EINVAL;
if (mem->page_count == 0)
return 0;
for (i = pg_start; i < (mem->page_count + pg_start); i++) {
addr = (i * PAGE_SIZE) + agp_bridge->gart_bus_addr;
cur_gatt = GET_GATT(addr);
writel(agp_bridge->scratch_page, cur_gatt+GET_GATT_OFF(addr));
}
readl(GET_GATT(agp_bridge->gart_bus_addr));
agp_bridge->driver->tlb_flush(mem);
return 0;
}
static int ati_create_gatt_table(struct agp_bridge_data *bridge)
{
struct aper_size_info_lvl2 *value;
struct ati_page_map page_dir;
unsigned long __iomem *cur_gatt;
unsigned long addr;
int retval;
u32 temp;
int i;
struct aper_size_info_lvl2 *current_size;
value = A_SIZE_LVL2(agp_bridge->current_size);
retval = ati_create_page_map(&page_dir);
if (retval != 0)
return retval;
retval = ati_create_gatt_pages(value->num_entries / 1024);
if (retval != 0) {
ati_free_page_map(&page_dir);
return retval;
}
agp_bridge->gatt_table_real = (u32 *)page_dir.real;
agp_bridge->gatt_table = (u32 __iomem *) page_dir.remapped;
agp_bridge->gatt_bus_addr = virt_to_phys(page_dir.real);
current_size = A_SIZE_LVL2(agp_bridge->current_size);
if (is_r200()) {
pci_read_config_dword(agp_bridge->dev, ATI_RS100_APSIZE, &temp);
temp = (((temp & ~(0x0000000e)) | current_size->size_value)
| 0x00000001);
pci_write_config_dword(agp_bridge->dev, ATI_RS100_APSIZE, temp);
pci_read_config_dword(agp_bridge->dev, ATI_RS100_APSIZE, &temp);
} else {
pci_read_config_dword(agp_bridge->dev, ATI_RS300_APSIZE, &temp);
temp = (((temp & ~(0x0000000e)) | current_size->size_value)
| 0x00000001);
pci_write_config_dword(agp_bridge->dev, ATI_RS300_APSIZE, temp);
pci_read_config_dword(agp_bridge->dev, ATI_RS300_APSIZE, &temp);
}
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
agp_bridge->gart_bus_addr = addr;
for (i = 0; i < value->num_entries / 1024; i++, addr += 0x00400000) {
writel(virt_to_phys(ati_generic_private.gatt_pages[i]->real) | 1,
page_dir.remapped+GET_PAGE_DIR_OFF(addr));
readl(page_dir.remapped+GET_PAGE_DIR_OFF(addr));
}
for (i = 0; i < value->num_entries; i++) {
addr = (i * PAGE_SIZE) + agp_bridge->gart_bus_addr;
cur_gatt = GET_GATT(addr);
writel(agp_bridge->scratch_page, cur_gatt+GET_GATT_OFF(addr));
}
return 0;
}
static int ati_free_gatt_table(struct agp_bridge_data *bridge)
{
struct ati_page_map page_dir;
page_dir.real = (unsigned long *)agp_bridge->gatt_table_real;
page_dir.remapped = (unsigned long __iomem *)agp_bridge->gatt_table;
ati_free_gatt_pages();
ati_free_page_map(&page_dir);
return 0;
}
static int agp_ati_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct agp_device_ids *devs = ati_agp_device_ids;
struct agp_bridge_data *bridge;
u8 cap_ptr;
int j;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
if (!cap_ptr)
return -ENODEV;
for (j = 0; devs[j].chipset_name; j++) {
if (pdev->device == devs[j].device_id)
goto found;
}
dev_err(&pdev->dev, "unsupported Ati chipset [%04x/%04x])\n",
pdev->vendor, pdev->device);
return -ENODEV;
found:
bridge = agp_alloc_bridge();
if (!bridge)
return -ENOMEM;
bridge->dev = pdev;
bridge->capndx = cap_ptr;
bridge->driver = &ati_generic_bridge;
dev_info(&pdev->dev, "Ati %s chipset\n", devs[j].chipset_name);
pci_read_config_dword(pdev,
bridge->capndx+PCI_AGP_STATUS,
&bridge->mode);
pci_set_drvdata(pdev, bridge);
return agp_add_bridge(bridge);
}
static void agp_ati_remove(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
agp_remove_bridge(bridge);
agp_put_bridge(bridge);
}
static int __init agp_ati_init(void)
{
if (agp_off)
return -EINVAL;
return pci_register_driver(&agp_ati_pci_driver);
}
static void __exit agp_ati_cleanup(void)
{
pci_unregister_driver(&agp_ati_pci_driver);
}
