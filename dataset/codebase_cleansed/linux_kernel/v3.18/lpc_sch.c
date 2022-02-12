static int lpc_sch_get_io(struct pci_dev *pdev, int where, const char *name,
struct resource *res, int size)
{
unsigned int base_addr_cfg;
unsigned short base_addr;
if (size == 0)
return LPC_NO_RESOURCE;
pci_read_config_dword(pdev, where, &base_addr_cfg);
base_addr = 0;
if (!(base_addr_cfg & (1 << 31)))
dev_warn(&pdev->dev, "Decode of the %s I/O range disabled\n",
name);
else
base_addr = (unsigned short)base_addr_cfg;
if (base_addr == 0) {
dev_warn(&pdev->dev, "I/O space for %s uninitialized\n", name);
return LPC_SKIP_RESOURCE;
}
res->start = base_addr;
res->end = base_addr + size - 1;
res->flags = IORESOURCE_IO;
return 0;
}
static int lpc_sch_populate_cell(struct pci_dev *pdev, int where,
const char *name, int size, int irq,
int id, struct mfd_cell *cell)
{
struct resource *res;
int ret;
res = devm_kcalloc(&pdev->dev, 2, sizeof(*res), GFP_KERNEL);
if (!res)
return -ENOMEM;
ret = lpc_sch_get_io(pdev, where, name, res, size);
if (ret)
return ret;
memset(cell, 0, sizeof(*cell));
cell->name = name;
cell->resources = res;
cell->num_resources = 1;
cell->ignore_resource_conflicts = true;
cell->id = id;
if (irq < 0)
return 0;
res++;
res->start = irq;
res->end = irq;
res->flags = IORESOURCE_IRQ;
cell->num_resources++;
return 0;
}
static int lpc_sch_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct mfd_cell lpc_sch_cells[3];
struct lpc_sch_info *info = &sch_chipset_info[id->driver_data];
unsigned int cells = 0;
int ret;
ret = lpc_sch_populate_cell(dev, SMBASE, "isch_smbus",
info->io_size_smbus, -1,
id->device, &lpc_sch_cells[cells]);
if (ret < 0)
return ret;
if (ret == 0)
cells++;
ret = lpc_sch_populate_cell(dev, GPIOBASE, "sch_gpio",
info->io_size_gpio, info->irq_gpio,
id->device, &lpc_sch_cells[cells]);
if (ret < 0)
return ret;
if (ret == 0)
cells++;
ret = lpc_sch_populate_cell(dev, WDTBASE, "ie6xx_wdt",
info->io_size_wdt, -1,
id->device, &lpc_sch_cells[cells]);
if (ret < 0)
return ret;
if (ret == 0)
cells++;
if (cells == 0) {
dev_err(&dev->dev, "All decode registers disabled.\n");
return -ENODEV;
}
ret = mfd_add_devices(&dev->dev, 0, lpc_sch_cells, cells, NULL, 0, NULL);
if (ret)
mfd_remove_devices(&dev->dev);
return ret;
}
static void lpc_sch_remove(struct pci_dev *dev)
{
mfd_remove_devices(&dev->dev);
}
