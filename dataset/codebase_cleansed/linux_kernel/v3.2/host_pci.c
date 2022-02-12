static void bcma_host_pci_switch_core(struct bcma_device *core)
{
pci_write_config_dword(core->bus->host_pci, BCMA_PCI_BAR0_WIN,
core->addr);
pci_write_config_dword(core->bus->host_pci, BCMA_PCI_BAR0_WIN2,
core->wrap);
core->bus->mapped_core = core;
pr_debug("Switched to core: 0x%X\n", core->id.id);
}
static u8 bcma_host_pci_read8(struct bcma_device *core, u16 offset)
{
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
return ioread8(core->bus->mmio + offset);
}
static u16 bcma_host_pci_read16(struct bcma_device *core, u16 offset)
{
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
return ioread16(core->bus->mmio + offset);
}
static u32 bcma_host_pci_read32(struct bcma_device *core, u16 offset)
{
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
return ioread32(core->bus->mmio + offset);
}
static void bcma_host_pci_write8(struct bcma_device *core, u16 offset,
u8 value)
{
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
iowrite8(value, core->bus->mmio + offset);
}
static void bcma_host_pci_write16(struct bcma_device *core, u16 offset,
u16 value)
{
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
iowrite16(value, core->bus->mmio + offset);
}
static void bcma_host_pci_write32(struct bcma_device *core, u16 offset,
u32 value)
{
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
iowrite32(value, core->bus->mmio + offset);
}
void bcma_host_pci_block_read(struct bcma_device *core, void *buffer,
size_t count, u16 offset, u8 reg_width)
{
void __iomem *addr = core->bus->mmio + offset;
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
switch (reg_width) {
case sizeof(u8):
ioread8_rep(addr, buffer, count);
break;
case sizeof(u16):
WARN_ON(count & 1);
ioread16_rep(addr, buffer, count >> 1);
break;
case sizeof(u32):
WARN_ON(count & 3);
ioread32_rep(addr, buffer, count >> 2);
break;
default:
WARN_ON(1);
}
}
void bcma_host_pci_block_write(struct bcma_device *core, const void *buffer,
size_t count, u16 offset, u8 reg_width)
{
void __iomem *addr = core->bus->mmio + offset;
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
switch (reg_width) {
case sizeof(u8):
iowrite8_rep(addr, buffer, count);
break;
case sizeof(u16):
WARN_ON(count & 1);
iowrite16_rep(addr, buffer, count >> 1);
break;
case sizeof(u32):
WARN_ON(count & 3);
iowrite32_rep(addr, buffer, count >> 2);
break;
default:
WARN_ON(1);
}
}
static u32 bcma_host_pci_aread32(struct bcma_device *core, u16 offset)
{
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
return ioread32(core->bus->mmio + (1 * BCMA_CORE_SIZE) + offset);
}
static void bcma_host_pci_awrite32(struct bcma_device *core, u16 offset,
u32 value)
{
if (core->bus->mapped_core != core)
bcma_host_pci_switch_core(core);
iowrite32(value, core->bus->mmio + (1 * BCMA_CORE_SIZE) + offset);
}
static int bcma_host_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct bcma_bus *bus;
int err = -ENOMEM;
const char *name;
u32 val;
bus = kzalloc(sizeof(*bus), GFP_KERNEL);
if (!bus)
goto out;
err = pci_enable_device(dev);
if (err)
goto err_kfree_bus;
name = dev_name(&dev->dev);
if (dev->driver && dev->driver->name)
name = dev->driver->name;
err = pci_request_regions(dev, name);
if (err)
goto err_pci_disable;
pci_set_master(dev);
pci_read_config_dword(dev, 0x40, &val);
if ((val & 0x0000ff00) != 0)
pci_write_config_dword(dev, 0x40, val & 0xffff00ff);
if (!pci_is_pcie(dev))
pr_err("PCI card detected, report problems.\n");
err = -ENOMEM;
bus->mmio = pci_iomap(dev, 0, ~0UL);
if (!bus->mmio)
goto err_pci_release_regions;
bus->host_pci = dev;
bus->hosttype = BCMA_HOSTTYPE_PCI;
bus->ops = &bcma_host_pci_ops;
err = bcma_bus_register(bus);
if (err)
goto err_pci_unmap_mmio;
pci_set_drvdata(dev, bus);
out:
return err;
err_pci_unmap_mmio:
pci_iounmap(dev, bus->mmio);
err_pci_release_regions:
pci_release_regions(dev);
err_pci_disable:
pci_disable_device(dev);
err_kfree_bus:
kfree(bus);
return err;
}
static void bcma_host_pci_remove(struct pci_dev *dev)
{
struct bcma_bus *bus = pci_get_drvdata(dev);
bcma_bus_unregister(bus);
pci_iounmap(dev, bus->mmio);
pci_release_regions(dev);
pci_disable_device(dev);
kfree(bus);
pci_set_drvdata(dev, NULL);
}
int __init bcma_host_pci_init(void)
{
return pci_register_driver(&bcma_pci_bridge_driver);
}
void __exit bcma_host_pci_exit(void)
{
pci_unregister_driver(&bcma_pci_bridge_driver);
}
