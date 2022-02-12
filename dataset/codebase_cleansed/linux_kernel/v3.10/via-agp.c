static int via_fetch_size(void)
{
int i;
u8 temp;
struct aper_size_info_8 *values;
values = A_SIZE_8(agp_bridge->driver->aperture_sizes);
pci_read_config_byte(agp_bridge->dev, VIA_APSIZE, &temp);
for (i = 0; i < agp_bridge->driver->num_aperture_sizes; i++) {
if (temp == values[i].size_value) {
agp_bridge->previous_size =
agp_bridge->current_size = (void *) (values + i);
agp_bridge->aperture_size_idx = i;
return values[i].size;
}
}
printk(KERN_ERR PFX "Unknown aperture size from AGP bridge (0x%x)\n", temp);
return 0;
}
static int via_configure(void)
{
u32 temp;
struct aper_size_info_8 *current_size;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, VIA_APSIZE,
current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, VIA_GARTCTRL, 0x0000000f);
pci_write_config_dword(agp_bridge->dev, VIA_ATTBASE,
(agp_bridge->gatt_bus_addr & 0xfffff000) | 3);
return 0;
}
static void via_cleanup(void)
{
struct aper_size_info_8 *previous_size;
previous_size = A_SIZE_8(agp_bridge->previous_size);
pci_write_config_byte(agp_bridge->dev, VIA_APSIZE,
previous_size->size_value);
}
static void via_tlbflush(struct agp_memory *mem)
{
u32 temp;
pci_read_config_dword(agp_bridge->dev, VIA_GARTCTRL, &temp);
temp |= (1<<7);
pci_write_config_dword(agp_bridge->dev, VIA_GARTCTRL, temp);
temp &= ~(1<<7);
pci_write_config_dword(agp_bridge->dev, VIA_GARTCTRL, temp);
}
static int via_fetch_size_agp3(void)
{
int i;
u16 temp;
struct aper_size_info_16 *values;
values = A_SIZE_16(agp_bridge->driver->aperture_sizes);
pci_read_config_word(agp_bridge->dev, VIA_AGP3_APSIZE, &temp);
temp &= 0xfff;
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
static int via_configure_agp3(void)
{
u32 temp;
struct aper_size_info_16 *current_size;
current_size = A_SIZE_16(agp_bridge->current_size);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, VIA_AGP3_ATTBASE,
agp_bridge->gatt_bus_addr & 0xfffff000);
pci_read_config_dword(agp_bridge->dev, VIA_AGP3_GARTCTRL, &temp);
pci_write_config_dword(agp_bridge->dev, VIA_AGP3_GARTCTRL, temp | (3<<7));
return 0;
}
static void via_cleanup_agp3(void)
{
struct aper_size_info_16 *previous_size;
previous_size = A_SIZE_16(agp_bridge->previous_size);
pci_write_config_byte(agp_bridge->dev, VIA_APSIZE, previous_size->size_value);
}
static void via_tlbflush_agp3(struct agp_memory *mem)
{
u32 temp;
pci_read_config_dword(agp_bridge->dev, VIA_AGP3_GARTCTRL, &temp);
pci_write_config_dword(agp_bridge->dev, VIA_AGP3_GARTCTRL, temp & ~(1<<7));
pci_write_config_dword(agp_bridge->dev, VIA_AGP3_GARTCTRL, temp);
}
static void check_via_agp3 (struct agp_bridge_data *bridge)
{
u8 reg;
pci_read_config_byte(bridge->dev, VIA_AGPSEL, &reg);
if ((reg & (1<<1))==0)
bridge->driver = &via_agp3_driver;
}
static int agp_via_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct agp_device_ids *devs = via_agp_device_ids;
struct agp_bridge_data *bridge;
int j = 0;
u8 cap_ptr;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
if (!cap_ptr)
return -ENODEV;
j = ent - agp_via_pci_table;
printk (KERN_INFO PFX "Detected VIA %s chipset\n", devs[j].chipset_name);
bridge = agp_alloc_bridge();
if (!bridge)
return -ENOMEM;
bridge->dev = pdev;
bridge->capndx = cap_ptr;
bridge->driver = &via_driver;
if (pdev->device == PCI_DEVICE_ID_VIA_8367_0) {
if (pdev->subsystem_device == PCI_DEVICE_ID_VIA_8377_0) {
printk(KERN_INFO PFX "Found KT400 in disguise as a KT266.\n");
check_via_agp3(bridge);
}
}
get_agp_version(bridge);
if (bridge->major_version >= 3)
check_via_agp3(bridge);
pci_read_config_dword(pdev,
bridge->capndx+PCI_AGP_STATUS, &bridge->mode);
pci_set_drvdata(pdev, bridge);
return agp_add_bridge(bridge);
}
static void agp_via_remove(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
agp_remove_bridge(bridge);
agp_put_bridge(bridge);
}
static int agp_via_suspend(struct pci_dev *pdev, pm_message_t state)
{
pci_save_state (pdev);
pci_set_power_state (pdev, PCI_D3hot);
return 0;
}
static int agp_via_resume(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
pci_set_power_state (pdev, PCI_D0);
pci_restore_state(pdev);
if (bridge->driver == &via_agp3_driver)
return via_configure_agp3();
else if (bridge->driver == &via_driver)
return via_configure();
return 0;
}
static int __init agp_via_init(void)
{
if (agp_off)
return -EINVAL;
return pci_register_driver(&agp_via_pci_driver);
}
static void __exit agp_via_cleanup(void)
{
pci_unregister_driver(&agp_via_pci_driver);
}
