static void lpc_ich_restore_config_space(struct pci_dev *dev)
{
struct lpc_ich_priv *priv = pci_get_drvdata(dev);
if (priv->acpi.save >= 0) {
pci_write_config_byte(dev, priv->acpi.ctrl, priv->acpi.save);
priv->acpi.save = -1;
}
if (priv->gpio.save >= 0) {
pci_write_config_byte(dev, priv->gpio.ctrl, priv->gpio.save);
priv->gpio.save = -1;
}
}
static void lpc_ich_enable_acpi_space(struct pci_dev *dev)
{
struct lpc_ich_priv *priv = pci_get_drvdata(dev);
u8 reg_save;
pci_read_config_byte(dev, priv->acpi.ctrl, &reg_save);
pci_write_config_byte(dev, priv->acpi.ctrl, reg_save | 0x10);
priv->acpi.save = reg_save;
}
static void lpc_ich_enable_gpio_space(struct pci_dev *dev)
{
struct lpc_ich_priv *priv = pci_get_drvdata(dev);
u8 reg_save;
pci_read_config_byte(dev, priv->gpio.ctrl, &reg_save);
pci_write_config_byte(dev, priv->gpio.ctrl, reg_save | 0x10);
priv->gpio.save = reg_save;
}
static void lpc_ich_finalize_cell(struct pci_dev *dev, struct mfd_cell *cell)
{
struct lpc_ich_priv *priv = pci_get_drvdata(dev);
cell->platform_data = &lpc_chipset_info[priv->chipset];
cell->pdata_size = sizeof(struct lpc_ich_info);
}
static int lpc_ich_check_conflict_gpio(struct resource *res)
{
int ret;
u8 use_gpio = 0;
if (resource_size(res) >= 0x50 &&
!acpi_check_region(res->start + 0x40, 0x10, "LPC ICH GPIO3"))
use_gpio |= 1 << 2;
if (!acpi_check_region(res->start + 0x30, 0x10, "LPC ICH GPIO2"))
use_gpio |= 1 << 1;
ret = acpi_check_region(res->start + 0x00, 0x30, "LPC ICH GPIO1");
if (!ret)
use_gpio |= 1 << 0;
return use_gpio ? use_gpio : ret;
}
static int lpc_ich_init_gpio(struct pci_dev *dev)
{
struct lpc_ich_priv *priv = pci_get_drvdata(dev);
u32 base_addr_cfg;
u32 base_addr;
int ret;
bool acpi_conflict = false;
struct resource *res;
pci_read_config_dword(dev, priv->acpi.base, &base_addr_cfg);
base_addr = base_addr_cfg & 0x0000ff80;
if (!base_addr) {
dev_notice(&dev->dev, "I/O space for ACPI uninitialized\n");
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
pci_read_config_dword(dev, priv->gpio.base, &base_addr_cfg);
base_addr = base_addr_cfg & 0x0000ff80;
if (!base_addr) {
dev_notice(&dev->dev, "I/O space for GPIO uninitialized\n");
ret = -ENODEV;
goto gpio_done;
}
res = &gpio_ich_res[ICH_RES_GPIO];
res->start = base_addr;
switch (lpc_chipset_info[priv->chipset].gpio_version) {
case ICH_V5_GPIO:
case ICH_V10CORP_GPIO:
res->end = res->start + 128 - 1;
break;
default:
res->end = res->start + 64 - 1;
break;
}
ret = lpc_ich_check_conflict_gpio(res);
if (ret < 0) {
acpi_conflict = true;
goto gpio_done;
}
lpc_chipset_info[priv->chipset].use_gpio = ret;
lpc_ich_enable_gpio_space(dev);
lpc_ich_finalize_cell(dev, &lpc_ich_cells[LPC_GPIO]);
ret = mfd_add_devices(&dev->dev, -1, &lpc_ich_cells[LPC_GPIO],
1, NULL, 0, NULL);
gpio_done:
if (acpi_conflict)
pr_warn("Resource conflict(s) found affecting %s\n",
lpc_ich_cells[LPC_GPIO].name);
return ret;
}
static int lpc_ich_init_wdt(struct pci_dev *dev)
{
struct lpc_ich_priv *priv = pci_get_drvdata(dev);
u32 base_addr_cfg;
u32 base_addr;
int ret;
struct resource *res;
pci_read_config_dword(dev, priv->acpi.base, &base_addr_cfg);
base_addr = base_addr_cfg & 0x0000ff80;
if (!base_addr) {
dev_notice(&dev->dev, "I/O space for ACPI uninitialized\n");
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
if (lpc_chipset_info[priv->chipset].iTCO_version == 1) {
lpc_ich_cells[LPC_WDT].num_resources--;
} else {
pci_read_config_dword(dev, RCBABASE, &base_addr_cfg);
base_addr = base_addr_cfg & 0xffffc000;
if (!(base_addr_cfg & 1)) {
dev_notice(&dev->dev, "RCBA is disabled by "
"hardware/BIOS, device disabled\n");
ret = -ENODEV;
goto wdt_done;
}
res = wdt_mem_res(ICH_RES_MEM_GCS);
res->start = base_addr + ACPIBASE_GCS_OFF;
res->end = base_addr + ACPIBASE_GCS_END;
}
lpc_ich_finalize_cell(dev, &lpc_ich_cells[LPC_WDT]);
ret = mfd_add_devices(&dev->dev, -1, &lpc_ich_cells[LPC_WDT],
1, NULL, 0, NULL);
wdt_done:
return ret;
}
static int lpc_ich_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct lpc_ich_priv *priv;
int ret;
bool cell_added = false;
priv = devm_kzalloc(&dev->dev,
sizeof(struct lpc_ich_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->chipset = id->driver_data;
priv->acpi.save = -1;
priv->acpi.base = ACPIBASE;
priv->acpi.ctrl = ACPICTRL;
priv->gpio.save = -1;
if (priv->chipset <= LPC_ICH5) {
priv->gpio.base = GPIOBASE_ICH0;
priv->gpio.ctrl = GPIOCTRL_ICH0;
} else {
priv->gpio.base = GPIOBASE_ICH6;
priv->gpio.ctrl = GPIOCTRL_ICH6;
}
pci_set_drvdata(dev, priv);
ret = lpc_ich_init_wdt(dev);
if (!ret)
cell_added = true;
ret = lpc_ich_init_gpio(dev);
if (!ret)
cell_added = true;
if (!cell_added) {
dev_warn(&dev->dev, "No MFD cells added\n");
lpc_ich_restore_config_space(dev);
return -ENODEV;
}
return 0;
}
static void lpc_ich_remove(struct pci_dev *dev)
{
mfd_remove_devices(&dev->dev);
lpc_ich_restore_config_space(dev);
}
