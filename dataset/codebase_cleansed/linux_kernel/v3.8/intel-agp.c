static int intel_fetch_size(void)
{
int i;
u16 temp;
struct aper_size_info_16 *values;
pci_read_config_word(agp_bridge->dev, INTEL_APSIZE, &temp);
values = A_SIZE_16(agp_bridge->driver->aperture_sizes);
for (i = 0; i < agp_bridge->driver->num_aperture_sizes; i++) {
if (temp == values[i].size_value) {
agp_bridge->previous_size = agp_bridge->current_size = (void *) (values + i);
agp_bridge->aperture_size_idx = i;
return values[i].size;
}
}
return 0;
}
static int __intel_8xx_fetch_size(u8 temp)
{
int i;
struct aper_size_info_8 *values;
values = A_SIZE_8(agp_bridge->driver->aperture_sizes);
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
static int intel_8xx_fetch_size(void)
{
u8 temp;
pci_read_config_byte(agp_bridge->dev, INTEL_APSIZE, &temp);
return __intel_8xx_fetch_size(temp);
}
static int intel_815_fetch_size(void)
{
u8 temp;
pci_read_config_byte(agp_bridge->dev, INTEL_APSIZE, &temp);
temp &= (1 << 3);
return __intel_8xx_fetch_size(temp);
}
static void intel_tlbflush(struct agp_memory *mem)
{
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x2200);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x2280);
}
static void intel_8xx_tlbflush(struct agp_memory *mem)
{
u32 temp;
pci_read_config_dword(agp_bridge->dev, INTEL_AGPCTRL, &temp);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, temp & ~(1 << 7));
pci_read_config_dword(agp_bridge->dev, INTEL_AGPCTRL, &temp);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, temp | (1 << 7));
}
static void intel_cleanup(void)
{
u16 temp;
struct aper_size_info_16 *previous_size;
previous_size = A_SIZE_16(agp_bridge->previous_size);
pci_read_config_word(agp_bridge->dev, INTEL_NBXCFG, &temp);
pci_write_config_word(agp_bridge->dev, INTEL_NBXCFG, temp & ~(1 << 9));
pci_write_config_word(agp_bridge->dev, INTEL_APSIZE, previous_size->size_value);
}
static void intel_8xx_cleanup(void)
{
u16 temp;
struct aper_size_info_8 *previous_size;
previous_size = A_SIZE_8(agp_bridge->previous_size);
pci_read_config_word(agp_bridge->dev, INTEL_NBXCFG, &temp);
pci_write_config_word(agp_bridge->dev, INTEL_NBXCFG, temp & ~(1 << 9));
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE, previous_size->size_value);
}
static int intel_configure(void)
{
u32 temp;
u16 temp2;
struct aper_size_info_16 *current_size;
current_size = A_SIZE_16(agp_bridge->current_size);
pci_write_config_word(agp_bridge->dev, INTEL_APSIZE, current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, INTEL_ATTBASE, agp_bridge->gatt_bus_addr);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x2280);
pci_read_config_word(agp_bridge->dev, INTEL_NBXCFG, &temp2);
pci_write_config_word(agp_bridge->dev, INTEL_NBXCFG,
(temp2 & ~(1 << 10)) | (1 << 9));
pci_write_config_byte(agp_bridge->dev, INTEL_ERRSTS + 1, 7);
return 0;
}
static int intel_815_configure(void)
{
u32 temp, addr;
u8 temp2;
struct aper_size_info_8 *current_size;
if (agp_bridge->gatt_bus_addr & INTEL_815_ATTBASE_MASK) {
dev_emerg(&agp_bridge->dev->dev, "gatt bus addr too high");
return -EINVAL;
}
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE,
current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_read_config_dword(agp_bridge->dev, INTEL_ATTBASE, &addr);
addr &= INTEL_815_ATTBASE_MASK;
addr |= agp_bridge->gatt_bus_addr;
pci_write_config_dword(agp_bridge->dev, INTEL_ATTBASE, addr);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x0000);
pci_read_config_byte(agp_bridge->dev, INTEL_815_APCONT, &temp2);
pci_write_config_byte(agp_bridge->dev, INTEL_815_APCONT, temp2 | (1 << 1));
return 0;
}
static void intel_820_tlbflush(struct agp_memory *mem)
{
return;
}
static void intel_820_cleanup(void)
{
u8 temp;
struct aper_size_info_8 *previous_size;
previous_size = A_SIZE_8(agp_bridge->previous_size);
pci_read_config_byte(agp_bridge->dev, INTEL_I820_RDCR, &temp);
pci_write_config_byte(agp_bridge->dev, INTEL_I820_RDCR,
temp & ~(1 << 1));
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE,
previous_size->size_value);
}
static int intel_820_configure(void)
{
u32 temp;
u8 temp2;
struct aper_size_info_8 *current_size;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE, current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, INTEL_ATTBASE, agp_bridge->gatt_bus_addr);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x0000);
pci_read_config_byte(agp_bridge->dev, INTEL_I820_RDCR, &temp2);
pci_write_config_byte(agp_bridge->dev, INTEL_I820_RDCR, temp2 | (1 << 1));
pci_write_config_word(agp_bridge->dev, INTEL_I820_ERRSTS, 0x001c);
return 0;
}
static int intel_840_configure(void)
{
u32 temp;
u16 temp2;
struct aper_size_info_8 *current_size;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE, current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, INTEL_ATTBASE, agp_bridge->gatt_bus_addr);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x0000);
pci_read_config_word(agp_bridge->dev, INTEL_I840_MCHCFG, &temp2);
pci_write_config_word(agp_bridge->dev, INTEL_I840_MCHCFG, temp2 | (1 << 9));
pci_write_config_word(agp_bridge->dev, INTEL_I840_ERRSTS, 0xc000);
return 0;
}
static int intel_845_configure(void)
{
u32 temp;
u8 temp2;
struct aper_size_info_8 *current_size;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE, current_size->size_value);
if (agp_bridge->apbase_config != 0) {
pci_write_config_dword(agp_bridge->dev, AGP_APBASE,
agp_bridge->apbase_config);
} else {
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
agp_bridge->apbase_config = temp;
}
pci_write_config_dword(agp_bridge->dev, INTEL_ATTBASE, agp_bridge->gatt_bus_addr);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x0000);
pci_read_config_byte(agp_bridge->dev, INTEL_I845_AGPM, &temp2);
pci_write_config_byte(agp_bridge->dev, INTEL_I845_AGPM, temp2 | (1 << 1));
pci_write_config_word(agp_bridge->dev, INTEL_I845_ERRSTS, 0x001c);
return 0;
}
static int intel_850_configure(void)
{
u32 temp;
u16 temp2;
struct aper_size_info_8 *current_size;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE, current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, INTEL_ATTBASE, agp_bridge->gatt_bus_addr);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x0000);
pci_read_config_word(agp_bridge->dev, INTEL_I850_MCHCFG, &temp2);
pci_write_config_word(agp_bridge->dev, INTEL_I850_MCHCFG, temp2 | (1 << 9));
pci_write_config_word(agp_bridge->dev, INTEL_I850_ERRSTS, 0x001c);
return 0;
}
static int intel_860_configure(void)
{
u32 temp;
u16 temp2;
struct aper_size_info_8 *current_size;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE, current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, INTEL_ATTBASE, agp_bridge->gatt_bus_addr);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x0000);
pci_read_config_word(agp_bridge->dev, INTEL_I860_MCHCFG, &temp2);
pci_write_config_word(agp_bridge->dev, INTEL_I860_MCHCFG, temp2 | (1 << 9));
pci_write_config_word(agp_bridge->dev, INTEL_I860_ERRSTS, 0xf700);
return 0;
}
static int intel_830mp_configure(void)
{
u32 temp;
u16 temp2;
struct aper_size_info_8 *current_size;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE, current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, INTEL_ATTBASE, agp_bridge->gatt_bus_addr);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x0000);
pci_read_config_word(agp_bridge->dev, INTEL_NBXCFG, &temp2);
pci_write_config_word(agp_bridge->dev, INTEL_NBXCFG, temp2 | (1 << 9));
pci_write_config_word(agp_bridge->dev, INTEL_I830_ERRSTS, 0x1c);
return 0;
}
static int intel_7505_configure(void)
{
u32 temp;
u16 temp2;
struct aper_size_info_8 *current_size;
current_size = A_SIZE_8(agp_bridge->current_size);
pci_write_config_byte(agp_bridge->dev, INTEL_APSIZE, current_size->size_value);
pci_read_config_dword(agp_bridge->dev, AGP_APBASE, &temp);
agp_bridge->gart_bus_addr = (temp & PCI_BASE_ADDRESS_MEM_MASK);
pci_write_config_dword(agp_bridge->dev, INTEL_ATTBASE, agp_bridge->gatt_bus_addr);
pci_write_config_dword(agp_bridge->dev, INTEL_AGPCTRL, 0x0000);
pci_read_config_word(agp_bridge->dev, INTEL_I7505_MCHCFG, &temp2);
pci_write_config_word(agp_bridge->dev, INTEL_I7505_MCHCFG, temp2 | (1 << 9));
return 0;
}
static int agp_intel_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct agp_bridge_data *bridge;
u8 cap_ptr = 0;
struct resource *r;
int i, err;
cap_ptr = pci_find_capability(pdev, PCI_CAP_ID_AGP);
bridge = agp_alloc_bridge();
if (!bridge)
return -ENOMEM;
bridge->capndx = cap_ptr;
if (intel_gmch_probe(pdev, NULL, bridge))
goto found_gmch;
for (i = 0; intel_agp_chipsets[i].name != NULL; i++) {
if (pdev->device == intel_agp_chipsets[i].chip_id) {
bridge->driver = intel_agp_chipsets[i].driver;
break;
}
}
if (!bridge->driver) {
if (cap_ptr)
dev_warn(&pdev->dev, "unsupported Intel chipset [%04x/%04x]\n",
pdev->vendor, pdev->device);
agp_put_bridge(bridge);
return -ENODEV;
}
bridge->dev = pdev;
bridge->dev_private_data = NULL;
dev_info(&pdev->dev, "Intel %s Chipset\n", intel_agp_chipsets[i].name);
r = &pdev->resource[0];
if (!r->start && r->end) {
if (pci_assign_resource(pdev, 0)) {
dev_err(&pdev->dev, "can't assign resource 0\n");
agp_put_bridge(bridge);
return -ENODEV;
}
}
if (pci_enable_device(pdev)) {
dev_err(&pdev->dev, "can't enable PCI device\n");
agp_put_bridge(bridge);
return -ENODEV;
}
if (cap_ptr) {
pci_read_config_dword(pdev,
bridge->capndx+PCI_AGP_STATUS,
&bridge->mode);
}
found_gmch:
pci_set_drvdata(pdev, bridge);
err = agp_add_bridge(bridge);
if (!err)
intel_agp_enabled = 1;
return err;
}
static void agp_intel_remove(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
agp_remove_bridge(bridge);
intel_gmch_remove();
agp_put_bridge(bridge);
}
static int agp_intel_resume(struct pci_dev *pdev)
{
struct agp_bridge_data *bridge = pci_get_drvdata(pdev);
bridge->driver->configure();
return 0;
}
static int __init agp_intel_init(void)
{
if (agp_off)
return -EINVAL;
return pci_register_driver(&agp_intel_pci_driver);
}
static void __exit agp_intel_cleanup(void)
{
pci_unregister_driver(&agp_intel_pci_driver);
}
