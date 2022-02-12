static int
nv50_gpio_location(int line, u32 *reg, u32 *shift)
{
const uint32_t nv50_gpio_reg[4] = { 0xe104, 0xe108, 0xe280, 0xe284 };
if (line >= 32)
return -EINVAL;
*reg = nv50_gpio_reg[line >> 3];
*shift = (line & 7) << 2;
return 0;
}
int
nv50_gpio_drive(struct drm_device *dev, int line, int dir, int out)
{
u32 reg, shift;
if (nv50_gpio_location(line, &reg, &shift))
return -EINVAL;
nv_mask(dev, reg, 7 << shift, (((dir ^ 1) << 1) | out) << shift);
return 0;
}
int
nv50_gpio_sense(struct drm_device *dev, int line)
{
u32 reg, shift;
if (nv50_gpio_location(line, &reg, &shift))
return -EINVAL;
return !!(nv_rd32(dev, reg) & (4 << shift));
}
void
nv50_gpio_irq_enable(struct drm_device *dev, int line, bool on)
{
u32 reg = line < 16 ? 0xe050 : 0xe070;
u32 mask = 0x00010001 << (line & 0xf);
nv_wr32(dev, reg + 4, mask);
nv_mask(dev, reg + 0, mask, on ? mask : 0);
}
int
nvd0_gpio_drive(struct drm_device *dev, int line, int dir, int out)
{
u32 data = ((dir ^ 1) << 13) | (out << 12);
nv_mask(dev, 0x00d610 + (line * 4), 0x00003000, data);
nv_mask(dev, 0x00d604, 0x00000001, 0x00000001);
return 0;
}
int
nvd0_gpio_sense(struct drm_device *dev, int line)
{
return !!(nv_rd32(dev, 0x00d610 + (line * 4)) & 0x00004000);
}
static void
nv50_gpio_isr(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
u32 intr0, intr1 = 0;
u32 hi, lo;
intr0 = nv_rd32(dev, 0xe054) & nv_rd32(dev, 0xe050);
if (dev_priv->chipset >= 0x90)
intr1 = nv_rd32(dev, 0xe074) & nv_rd32(dev, 0xe070);
hi = (intr0 & 0x0000ffff) | (intr1 << 16);
lo = (intr0 >> 16) | (intr1 & 0xffff0000);
nouveau_gpio_isr(dev, 0, hi | lo);
nv_wr32(dev, 0xe054, intr0);
if (dev_priv->chipset >= 0x90)
nv_wr32(dev, 0xe074, intr1);
}
int
nv50_gpio_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
nv_wr32(dev, 0xe050, 0x00000000);
nv_wr32(dev, 0xe054, 0xffffffff);
if (dev_priv->chipset >= 0x90) {
nv_wr32(dev, 0xe070, 0x00000000);
nv_wr32(dev, 0xe074, 0xffffffff);
}
nouveau_irq_register(dev, 21, nv50_gpio_isr);
return 0;
}
void
nv50_gpio_fini(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
nv_wr32(dev, 0xe050, 0x00000000);
if (dev_priv->chipset >= 0x90)
nv_wr32(dev, 0xe070, 0x00000000);
nouveau_irq_unregister(dev, 21);
}
