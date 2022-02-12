static void lpc_ich_restore_config_space(struct pci_dev *dev)
{
if (lpc_ich_acpi_save >= 0) {
pci_write_config_byte(dev, ACPICTRL, lpc_ich_acpi_save);
lpc_ich_acpi_save = -1;
}
if (lpc_ich_gpio_save >= 0) {
pci_write_config_byte(dev, GPIOCTRL, lpc_ich_gpio_save);
lpc_ich_gpio_save = -1;
}
}
static void __devinit lpc_ich_enable_acpi_space(struct pci_dev *dev)
{
u8 reg_save;
pci_read_config_byte(dev, ACPICTRL, &reg_save);
pci_write_config_byte(dev, ACPICTRL, reg_save | 0x10);
lpc_ich_acpi_save = reg_save;
}
static void __devinit lpc_ich_enable_gpio_space(struct pci_dev *dev)
{
u8 reg_save;
pci_read_config_byte(dev, GPIOCTRL, &reg_save);
pci_write_config_byte(dev, GPIOCTRL, reg_save | 0x10);
lpc_ich_gpio_save = reg_save;
}
static void __devinit lpc_ich_finalize_cell(struct mfd_cell *cell,
const struct pci_device_id *id)
{
cell->platform_data = &lpc_chipset_info[id->driver_data];
cell->pdata_size = sizeof(struct lpc_ich_info);
}
static int __devinit lpc_ich_init_gpio(struct pci_dev *dev,
const struct pci_device_id *id)
{
u32 base_addr_cfg;
u32 base_addr;
int ret;
bool acpi_conflict = false;
struct resource *res;
pci_read_config_dword(dev, ACPIBASE, &base_addr_cfg);
base_addr = base_addr_cfg & 0x0000ff80;
if (!base_addr) {
dev_err(&dev->dev, "I/O space for ACPI uninitialized\n");
lpc_ich_cells[LPC_GPIO].num_resources--;
goto gpe0_done;
}
res = &gpio_ich_res[ICH_RES_GPE0];
res->start = base_addr + ACPIBASE_GPE_OFF;
res->end = base_addr + ACPIBASE_GPE_END;
ret = acpi_check_resource_conflict(res);
if (ret) {
lpc_ich_cells[LPC_GPIO].num_resources--;
acpi_conflict = true;
} else {
lpc_ich_enable_acpi_space(dev);
}
gpe0_done:
pci_read_config_dword(dev, GPIOBASE, &base_addr_cfg);
base_addr = base_addr_cfg & 0x0000ff80;
if (!base_addr) {
dev_err(&dev->dev, "I/O space for GPIO uninitialized\n");
ret = -ENODEV;
goto gpio_done;
}
res = &gpio_ich_res[ICH_RES_GPIO];
res->start = base_addr;
switch (lpc_chipset_info[id->driver_data].gpio_version) {
case ICH_V5_GPIO:
case ICH_V10CORP_GPIO:
res->end = res->start + 128 - 1;
break;
default:
res->end = res->start + 64 - 1;
break;
}
ret = acpi_check_resource_conflict(res);
if (ret) {
acpi_conflict = true;
goto gpio_done;
}
lpc_ich_enable_gpio_space(dev);
lpc_ich_finalize_cell(&lpc_ich_cells[LPC_GPIO], id);
ret = mfd_add_devices(&dev->dev, -1, &lpc_ich_cells[LPC_GPIO],
1, NULL, 0, NULL);
gpio_done:
if (acpi_conflict)
pr_warn("Resource conflict(s) found affecting %s\n",
lpc_ich_cells[LPC_GPIO].name);
return ret;
}
static int __devinit lpc_ich_init_wdt(struct pci_dev *dev,
const struct pci_device_id *id)
{
u32 base_addr_cfg;
u32 base_addr;
int ret;
struct resource *res;
pci_read_config_dword(dev, ACPIBASE, &base_addr_cfg);
base_addr = base_addr_cfg & 0x0000ff80;
if (!base_addr) {
dev_err(&dev->dev, "I/O space for ACPI uninitialized\n");
ret = -ENODEV;
goto wdt_done;
}
res = wdt_io_res(ICH_RES_IO_TCO);
res->start = base_addr + ACPIBASE_TCO_OFF;
res->end = base_addr + ACPIBASE_TCO_END;
res = wdt_io_res(ICH_RES_IO_SMI);
res->start = base_addr + ACPIBASE_SMI_OFF;
res->end = base_addr + ACPIBASE_SMI_END;
lpc_ich_enable_acpi_space(dev);
if (lpc_chipset_info[id->driver_data].iTCO_version == 2) {
pci_read_config_dword(dev, RCBABASE, &base_addr_cfg);
base_addr = base_addr_cfg & 0xffffc000;
if (!(base_addr_cfg & 1)) {
pr_err("RCBA is disabled by hardware/BIOS, "
"device disabled\n");
ret = -ENODEV;
goto wdt_done;
}
res = wdt_mem_res(ICH_RES_MEM_GCS);
res->start = base_addr + ACPIBASE_GCS_OFF;
res->end = base_addr + ACPIBASE_GCS_END;
}
lpc_ich_finalize_cell(&lpc_ich_cells[LPC_WDT], id);
ret = mfd_add_devices(&dev->dev, -1, &lpc_ich_cells[LPC_WDT],
1, NULL, 0, NULL);
wdt_done:
return ret;
}
static int __devinit lpc_ich_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
int ret;
bool cell_added = false;
ret = lpc_ich_init_wdt(dev, id);
if (!ret)
cell_added = true;
ret = lpc_ich_init_gpio(dev, id);
if (!ret)
cell_added = true;
if (!cell_added) {
lpc_ich_restore_config_space(dev);
return -ENODEV;
}
return 0;
}
static void __devexit lpc_ich_remove(struct pci_dev *dev)
{
mfd_remove_devices(&dev->dev);
lpc_ich_restore_config_space(dev);
}
static int __init lpc_ich_init(void)
{
return pci_register_driver(&lpc_ich_driver);
}
static void __exit lpc_ich_exit(void)
{
pci_unregister_driver(&lpc_ich_driver);
}
