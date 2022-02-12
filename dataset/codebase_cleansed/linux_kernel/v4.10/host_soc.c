static u8 bcma_host_soc_read8(struct bcma_device *core, u16 offset)
{
return readb(core->io_addr + offset);
}
static u16 bcma_host_soc_read16(struct bcma_device *core, u16 offset)
{
return readw(core->io_addr + offset);
}
static u32 bcma_host_soc_read32(struct bcma_device *core, u16 offset)
{
return readl(core->io_addr + offset);
}
static void bcma_host_soc_write8(struct bcma_device *core, u16 offset,
u8 value)
{
writeb(value, core->io_addr + offset);
}
static void bcma_host_soc_write16(struct bcma_device *core, u16 offset,
u16 value)
{
writew(value, core->io_addr + offset);
}
static void bcma_host_soc_write32(struct bcma_device *core, u16 offset,
u32 value)
{
writel(value, core->io_addr + offset);
}
static void bcma_host_soc_block_read(struct bcma_device *core, void *buffer,
size_t count, u16 offset, u8 reg_width)
{
void __iomem *addr = core->io_addr + offset;
switch (reg_width) {
case sizeof(u8): {
u8 *buf = buffer;
while (count) {
*buf = __raw_readb(addr);
buf++;
count--;
}
break;
}
case sizeof(u16): {
__le16 *buf = buffer;
WARN_ON(count & 1);
while (count) {
*buf = (__force __le16)__raw_readw(addr);
buf++;
count -= 2;
}
break;
}
case sizeof(u32): {
__le32 *buf = buffer;
WARN_ON(count & 3);
while (count) {
*buf = (__force __le32)__raw_readl(addr);
buf++;
count -= 4;
}
break;
}
default:
WARN_ON(1);
}
}
static void bcma_host_soc_block_write(struct bcma_device *core,
const void *buffer,
size_t count, u16 offset, u8 reg_width)
{
void __iomem *addr = core->io_addr + offset;
switch (reg_width) {
case sizeof(u8): {
const u8 *buf = buffer;
while (count) {
__raw_writeb(*buf, addr);
buf++;
count--;
}
break;
}
case sizeof(u16): {
const __le16 *buf = buffer;
WARN_ON(count & 1);
while (count) {
__raw_writew((__force u16)(*buf), addr);
buf++;
count -= 2;
}
break;
}
case sizeof(u32): {
const __le32 *buf = buffer;
WARN_ON(count & 3);
while (count) {
__raw_writel((__force u32)(*buf), addr);
buf++;
count -= 4;
}
break;
}
default:
WARN_ON(1);
}
}
static u32 bcma_host_soc_aread32(struct bcma_device *core, u16 offset)
{
if (WARN_ONCE(!core->io_wrap, "Accessed core has no wrapper/agent\n"))
return ~0;
return readl(core->io_wrap + offset);
}
static void bcma_host_soc_awrite32(struct bcma_device *core, u16 offset,
u32 value)
{
if (WARN_ONCE(!core->io_wrap, "Accessed core has no wrapper/agent\n"))
return;
writel(value, core->io_wrap + offset);
}
int __init bcma_host_soc_register(struct bcma_soc *soc)
{
struct bcma_bus *bus = &soc->bus;
bus->mmio = ioremap_nocache(BCMA_ADDR_BASE, BCMA_CORE_SIZE * 1);
if (!bus->mmio)
return -ENOMEM;
bus->hosttype = BCMA_HOSTTYPE_SOC;
bus->ops = &bcma_host_soc_ops;
bus->host_pdev = NULL;
bcma_init_bus(bus);
return 0;
}
int __init bcma_host_soc_init(struct bcma_soc *soc)
{
struct bcma_bus *bus = &soc->bus;
int err;
err = bcma_bus_early_register(bus);
if (err)
iounmap(bus->mmio);
return err;
}
static int bcma_host_soc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct bcma_bus *bus;
int err;
bus = devm_kzalloc(dev, sizeof(*bus), GFP_KERNEL);
if (!bus)
return -ENOMEM;
bus->mmio = of_iomap(np, 0);
if (!bus->mmio)
return -ENOMEM;
bus->hosttype = BCMA_HOSTTYPE_SOC;
bus->ops = &bcma_host_soc_ops;
bus->host_pdev = pdev;
bcma_init_bus(bus);
err = bcma_bus_register(bus);
if (err)
goto err_unmap_mmio;
platform_set_drvdata(pdev, bus);
return err;
err_unmap_mmio:
iounmap(bus->mmio);
return err;
}
static int bcma_host_soc_remove(struct platform_device *pdev)
{
struct bcma_bus *bus = platform_get_drvdata(pdev);
bcma_bus_unregister(bus);
iounmap(bus->mmio);
platform_set_drvdata(pdev, NULL);
return 0;
}
int __init bcma_host_soc_register_driver(void)
{
return platform_driver_register(&bcma_host_soc_driver);
}
void __exit bcma_host_soc_unregister_driver(void)
{
platform_driver_unregister(&bcma_host_soc_driver);
}
