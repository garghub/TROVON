static int b53_mmap_read8(struct b53_device *dev, u8 page, u8 reg, u8 *val)
{
u8 __iomem *regs = dev->priv;
*val = readb(regs + (page << 8) + reg);
return 0;
}
static int b53_mmap_read16(struct b53_device *dev, u8 page, u8 reg, u16 *val)
{
u8 __iomem *regs = dev->priv;
if (WARN_ON(reg % 2))
return -EINVAL;
if (dev->pdata && dev->pdata->big_endian)
*val = ioread16be(regs + (page << 8) + reg);
else
*val = readw(regs + (page << 8) + reg);
return 0;
}
static int b53_mmap_read32(struct b53_device *dev, u8 page, u8 reg, u32 *val)
{
u8 __iomem *regs = dev->priv;
if (WARN_ON(reg % 4))
return -EINVAL;
if (dev->pdata && dev->pdata->big_endian)
*val = ioread32be(regs + (page << 8) + reg);
else
*val = readl(regs + (page << 8) + reg);
return 0;
}
static int b53_mmap_read48(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
u8 __iomem *regs = dev->priv;
if (WARN_ON(reg % 2))
return -EINVAL;
if (reg % 4) {
u16 lo;
u32 hi;
if (dev->pdata && dev->pdata->big_endian) {
lo = ioread16be(regs + (page << 8) + reg);
hi = ioread32be(regs + (page << 8) + reg + 2);
} else {
lo = readw(regs + (page << 8) + reg);
hi = readl(regs + (page << 8) + reg + 2);
}
*val = ((u64)hi << 16) | lo;
} else {
u32 lo;
u16 hi;
if (dev->pdata && dev->pdata->big_endian) {
lo = ioread32be(regs + (page << 8) + reg);
hi = ioread16be(regs + (page << 8) + reg + 4);
} else {
lo = readl(regs + (page << 8) + reg);
hi = readw(regs + (page << 8) + reg + 4);
}
*val = ((u64)hi << 32) | lo;
}
return 0;
}
static int b53_mmap_read64(struct b53_device *dev, u8 page, u8 reg, u64 *val)
{
u8 __iomem *regs = dev->priv;
u32 hi, lo;
if (WARN_ON(reg % 4))
return -EINVAL;
if (dev->pdata && dev->pdata->big_endian) {
lo = ioread32be(regs + (page << 8) + reg);
hi = ioread32be(regs + (page << 8) + reg + 4);
} else {
lo = readl(regs + (page << 8) + reg);
hi = readl(regs + (page << 8) + reg + 4);
}
*val = ((u64)hi << 32) | lo;
return 0;
}
static int b53_mmap_write8(struct b53_device *dev, u8 page, u8 reg, u8 value)
{
u8 __iomem *regs = dev->priv;
writeb(value, regs + (page << 8) + reg);
return 0;
}
static int b53_mmap_write16(struct b53_device *dev, u8 page, u8 reg,
u16 value)
{
u8 __iomem *regs = dev->priv;
if (WARN_ON(reg % 2))
return -EINVAL;
if (dev->pdata && dev->pdata->big_endian)
iowrite16be(value, regs + (page << 8) + reg);
else
writew(value, regs + (page << 8) + reg);
return 0;
}
static int b53_mmap_write32(struct b53_device *dev, u8 page, u8 reg,
u32 value)
{
u8 __iomem *regs = dev->priv;
if (WARN_ON(reg % 4))
return -EINVAL;
if (dev->pdata && dev->pdata->big_endian)
iowrite32be(value, regs + (page << 8) + reg);
else
writel(value, regs + (page << 8) + reg);
return 0;
}
static int b53_mmap_write48(struct b53_device *dev, u8 page, u8 reg,
u64 value)
{
if (WARN_ON(reg % 2))
return -EINVAL;
if (reg % 4) {
u32 hi = (u32)(value >> 16);
u16 lo = (u16)value;
b53_mmap_write16(dev, page, reg, lo);
b53_mmap_write32(dev, page, reg + 2, hi);
} else {
u16 hi = (u16)(value >> 32);
u32 lo = (u32)value;
b53_mmap_write32(dev, page, reg, lo);
b53_mmap_write16(dev, page, reg + 4, hi);
}
return 0;
}
static int b53_mmap_write64(struct b53_device *dev, u8 page, u8 reg,
u64 value)
{
u32 hi, lo;
hi = upper_32_bits(value);
lo = lower_32_bits(value);
if (WARN_ON(reg % 4))
return -EINVAL;
b53_mmap_write32(dev, page, reg, lo);
b53_mmap_write32(dev, page, reg + 4, hi);
return 0;
}
static int b53_mmap_probe(struct platform_device *pdev)
{
struct b53_platform_data *pdata = pdev->dev.platform_data;
struct b53_device *dev;
if (!pdata)
return -EINVAL;
dev = b53_switch_alloc(&pdev->dev, &b53_mmap_ops, pdata->regs);
if (!dev)
return -ENOMEM;
dev->pdata = pdata;
platform_set_drvdata(pdev, dev);
return b53_switch_register(dev);
}
static int b53_mmap_remove(struct platform_device *pdev)
{
struct b53_device *dev = platform_get_drvdata(pdev);
if (dev)
b53_switch_remove(dev);
return 0;
}
