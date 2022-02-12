static int sis_fetch_size(void)
{
u8 temp_size;
int i;
struct aper_size_info_8 *values;
pci_read_config_byte(agp_bridge->dev, SIS_APSIZE, &temp_size);
values = A_SIZE_8(agp_bridge->driver->aperture_sizes);
for (i = 0; i < agp_bridge->driver->num_aperture_sizes; i++) {
if ((temp_size == values[i].size_value) ||
((temp_size & ~(0x07)) ==
(values[i].size_value & ~(0x07)))) {
agp_bridge->previous_size =
agp_bridge->current_size = (void *) (values + i);
agp_bridge->aperture_size_idx = i;
return values[i].size;
}
}
return 0;
}
static void sis_tlbflush(struct agp_memory *mem)
{
pci_write_config_byte(agp_bridge->dev, SIS_TLBFLUSH, 0x02);
}
static int sis_configure(void)
{
u32 temp;
struct aper_size_info_8 *current_size;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, SIS_TLBCNTRL, 0x05);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, SIS_ATTBASE,
agp_bridge->gatt_bus_addr);
pci_write_config_byte(agp_bridge->dev, SIS_APSIZE,
current_size->size_value);
return 0;
}
static void sis_cleanup(void)
{
struct aper_size_info_8 *previous_size;
previous_size = A_SIZE_8(agp_bridge->previous_size);
pci_write_config_byte(agp_bridge->dev, SIS_APSIZE,
(previous_size->size_value & ~(0x03)));
}
static void sis_delayed_enable(struct agp_bridge_data *bridge, u32 mode)
{
struct pci_dev *device = NULL;
u32 command;
int rate;
dev_info(&agp_bridge->dev->dev, "AGP %d.%d bridge\n",
agp_bridge->major_version, agp_bridge->minor_version);
pci_read_config_dword(agp_bridge->dev, agp_bridge->capndx + PCI_AGP_STATUS, &command);
command = agp_collect_device_status(bridge, mode, command);
command |= AGPSTAT_AGP_ENABLE;
rate = (command & 0x7) << 2;
for_each_pci_dev(device) {
u8 agp = pci_find_capability(device, PCI_CAP_ID_AGP);
if (!agp)
continue;
dev_info(&agp_bridge->dev->dev, "putting AGP V3 device at %s into %dx mode\n",
pci_name(device), rate);
pci_write_config_dword(device, agp + PCI_AGP_COMMAND, command);
if (device->device == bridge->dev->device) {
dev_info(&agp_bridge->dev->dev, "SiS delay workaround: giving bridge time to recover\n");
msleep(10);
}
}
}
static void __devinit sis_get_driver(struct agp_bridge_data *bridge)
{
int i;
for (i=0; sis_broken_chipsets[i]!=0; ++i)
if (bridge->dev->device==sis_broken_chipsets[i])
break;
if (sis_broken_chipsets[i] || agp_sis_force_delay)
sis_driver.agp_enable=sis_delayed_enable;
if ((agp_bridge->major_version == 3 && agp_bridge->minor_version >= 5
&& agp_sis_agp_spec!=0) || agp_sis_agp_spec==1) {
sis_driver.aperture_sizes = agp3_generic_sizes;
sis_driver.size_type = U16_APER_SIZE;
sis_driver.num_aperture_sizes = AGP_GENERIC_SIZES_ENTRIES;
sis_driver.configure = agp3_generic_configure;
sis_driver.fetch_size = agp3_generic_fetch_size;
sis_driver.cleanup = agp3_generic_cleanup;
sis_driver.tlb_flush = agp3_generic_tlbflush;
}
}
static int __devinit agp_sis_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct agp_bridge_data *bridge;
u8 cap_ptr;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
if (!cap_ptr)
return -ENODEV;
dev_info(&pdev->dev, "SiS chipset [%04x/%04x]\n",
pdev->vendor, pdev->device);
bridge = agp_alloc_bridge();
if (!bridge)
return -ENOMEM;
bridge->driver = &sis_driver;
bridge->dev = pdev;
bridge->capndx = cap_ptr;
get_agp_version(bridge);
pci_read_config_dword(pdev, bridge->capndx+PCI_AGP_STATUS, &bridge->mode);
sis_get_driver(bridge);
pci_set_drvdata(pdev, bridge);
return agp_add_bridge(bridge);
}
static void __devexit agp_sis_remove(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
agp_remove_bridge(bridge);
agp_put_bridge(bridge);
}
static int agp_sis_suspend(struct pci_dev *pdev, pm_message_t state)
{
pci_save_state(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int agp_sis_resume(struct pci_dev *pdev)
{
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
return sis_driver.configure();
}
static int __init agp_sis_init(void)
{
if (agp_off)
return -EINVAL;
return pci_register_driver(&agp_sis_pci_driver);
}
static void __exit agp_sis_cleanup(void)
{
pci_unregister_driver(&agp_sis_pci_driver);
}
