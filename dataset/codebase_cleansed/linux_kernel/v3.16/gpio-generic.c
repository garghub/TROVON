static void bgpio_write8(void __iomem *reg, unsigned long data)
{
writeb(data, reg);
}
static unsigned long bgpio_read8(void __iomem *reg)
{
return readb(reg);
}
static void bgpio_write16(void __iomem *reg, unsigned long data)
{
writew(data, reg);
}
static unsigned long bgpio_read16(void __iomem *reg)
{
return readw(reg);
}
static void bgpio_write32(void __iomem *reg, unsigned long data)
{
writel(data, reg);
}
static unsigned long bgpio_read32(void __iomem *reg)
{
return readl(reg);
}
static void bgpio_write64(void __iomem *reg, unsigned long data)
{
writeq(data, reg);
}
static unsigned long bgpio_read64(void __iomem *reg)
{
return readq(reg);
}
static void bgpio_write16be(void __iomem *reg, unsigned long data)
{
iowrite16be(data, reg);
}
static unsigned long bgpio_read16be(void __iomem *reg)
{
return ioread16be(reg);
}
static void bgpio_write32be(void __iomem *reg, unsigned long data)
{
iowrite32be(data, reg);
}
static unsigned long bgpio_read32be(void __iomem *reg)
{
return ioread32be(reg);
}
static unsigned long bgpio_pin2mask(struct bgpio_chip *bgc, unsigned int pin)
{
return 1 << pin;
}
static unsigned long bgpio_pin2mask_be(struct bgpio_chip *bgc,
unsigned int pin)
{
return 1 << (bgc->bits - 1 - pin);
}
static int bgpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
return !!(bgc->read_reg(bgc->reg_dat) & bgc->pin2mask(bgc, gpio));
}
static void bgpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
unsigned long mask = bgc->pin2mask(bgc, gpio);
unsigned long flags;
spin_lock_irqsave(&bgc->lock, flags);
if (val)
bgc->data |= mask;
else
bgc->data &= ~mask;
bgc->write_reg(bgc->reg_dat, bgc->data);
spin_unlock_irqrestore(&bgc->lock, flags);
}
static void bgpio_set_with_clear(struct gpio_chip *gc, unsigned int gpio,
int val)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
unsigned long mask = bgc->pin2mask(bgc, gpio);
if (val)
bgc->write_reg(bgc->reg_set, mask);
else
bgc->write_reg(bgc->reg_clr, mask);
}
static void bgpio_set_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
unsigned long mask = bgc->pin2mask(bgc, gpio);
unsigned long flags;
spin_lock_irqsave(&bgc->lock, flags);
if (val)
bgc->data |= mask;
else
bgc->data &= ~mask;
bgc->write_reg(bgc->reg_set, bgc->data);
spin_unlock_irqrestore(&bgc->lock, flags);
}
static int bgpio_simple_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
return 0;
}
static int bgpio_simple_dir_out(struct gpio_chip *gc, unsigned int gpio,
int val)
{
gc->set(gc, gpio, val);
return 0;
}
static int bgpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
unsigned long flags;
spin_lock_irqsave(&bgc->lock, flags);
bgc->dir &= ~bgc->pin2mask(bgc, gpio);
bgc->write_reg(bgc->reg_dir, bgc->dir);
spin_unlock_irqrestore(&bgc->lock, flags);
return 0;
}
static int bgpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
unsigned long flags;
gc->set(gc, gpio, val);
spin_lock_irqsave(&bgc->lock, flags);
bgc->dir |= bgc->pin2mask(bgc, gpio);
bgc->write_reg(bgc->reg_dir, bgc->dir);
spin_unlock_irqrestore(&bgc->lock, flags);
return 0;
}
static int bgpio_dir_in_inv(struct gpio_chip *gc, unsigned int gpio)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
unsigned long flags;
spin_lock_irqsave(&bgc->lock, flags);
bgc->dir |= bgc->pin2mask(bgc, gpio);
bgc->write_reg(bgc->reg_dir, bgc->dir);
spin_unlock_irqrestore(&bgc->lock, flags);
return 0;
}
static int bgpio_dir_out_inv(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct bgpio_chip *bgc = to_bgpio_chip(gc);
unsigned long flags;
gc->set(gc, gpio, val);
spin_lock_irqsave(&bgc->lock, flags);
bgc->dir &= ~bgc->pin2mask(bgc, gpio);
bgc->write_reg(bgc->reg_dir, bgc->dir);
spin_unlock_irqrestore(&bgc->lock, flags);
return 0;
}
static int bgpio_setup_accessors(struct device *dev,
struct bgpio_chip *bgc,
bool bit_be,
bool byte_be)
{
switch (bgc->bits) {
case 8:
bgc->read_reg = bgpio_read8;
bgc->write_reg = bgpio_write8;
break;
case 16:
if (byte_be) {
bgc->read_reg = bgpio_read16be;
bgc->write_reg = bgpio_write16be;
} else {
bgc->read_reg = bgpio_read16;
bgc->write_reg = bgpio_write16;
}
break;
case 32:
if (byte_be) {
bgc->read_reg = bgpio_read32be;
bgc->write_reg = bgpio_write32be;
} else {
bgc->read_reg = bgpio_read32;
bgc->write_reg = bgpio_write32;
}
break;
#if BITS_PER_LONG >= 64
case 64:
if (byte_be) {
dev_err(dev,
"64 bit big endian byte order unsupported\n");
return -EINVAL;
} else {
bgc->read_reg = bgpio_read64;
bgc->write_reg = bgpio_write64;
}
break;
#endif
default:
dev_err(dev, "unsupported data width %u bits\n", bgc->bits);
return -EINVAL;
}
bgc->pin2mask = bit_be ? bgpio_pin2mask_be : bgpio_pin2mask;
return 0;
}
static int bgpio_setup_io(struct bgpio_chip *bgc,
void __iomem *dat,
void __iomem *set,
void __iomem *clr)
{
bgc->reg_dat = dat;
if (!bgc->reg_dat)
return -EINVAL;
if (set && clr) {
bgc->reg_set = set;
bgc->reg_clr = clr;
bgc->gc.set = bgpio_set_with_clear;
} else if (set && !clr) {
bgc->reg_set = set;
bgc->gc.set = bgpio_set_set;
} else {
bgc->gc.set = bgpio_set;
}
bgc->gc.get = bgpio_get;
return 0;
}
static int bgpio_setup_direction(struct bgpio_chip *bgc,
void __iomem *dirout,
void __iomem *dirin)
{
if (dirout && dirin) {
return -EINVAL;
} else if (dirout) {
bgc->reg_dir = dirout;
bgc->gc.direction_output = bgpio_dir_out;
bgc->gc.direction_input = bgpio_dir_in;
} else if (dirin) {
bgc->reg_dir = dirin;
bgc->gc.direction_output = bgpio_dir_out_inv;
bgc->gc.direction_input = bgpio_dir_in_inv;
} else {
bgc->gc.direction_output = bgpio_simple_dir_out;
bgc->gc.direction_input = bgpio_simple_dir_in;
}
return 0;
}
static int bgpio_request(struct gpio_chip *chip, unsigned gpio_pin)
{
if (gpio_pin < chip->ngpio)
return 0;
return -EINVAL;
}
int bgpio_remove(struct bgpio_chip *bgc)
{
return gpiochip_remove(&bgc->gc);
}
int bgpio_init(struct bgpio_chip *bgc, struct device *dev,
unsigned long sz, void __iomem *dat, void __iomem *set,
void __iomem *clr, void __iomem *dirout, void __iomem *dirin,
unsigned long flags)
{
int ret;
if (!is_power_of_2(sz))
return -EINVAL;
bgc->bits = sz * 8;
if (bgc->bits > BITS_PER_LONG)
return -EINVAL;
spin_lock_init(&bgc->lock);
bgc->gc.dev = dev;
bgc->gc.label = dev_name(dev);
bgc->gc.base = -1;
bgc->gc.ngpio = bgc->bits;
bgc->gc.request = bgpio_request;
ret = bgpio_setup_io(bgc, dat, set, clr);
if (ret)
return ret;
ret = bgpio_setup_accessors(dev, bgc, flags & BGPIOF_BIG_ENDIAN,
flags & BGPIOF_BIG_ENDIAN_BYTE_ORDER);
if (ret)
return ret;
ret = bgpio_setup_direction(bgc, dirout, dirin);
if (ret)
return ret;
bgc->data = bgc->read_reg(bgc->reg_dat);
if (bgc->gc.set == bgpio_set_set &&
!(flags & BGPIOF_UNREADABLE_REG_SET))
bgc->data = bgc->read_reg(bgc->reg_set);
if (bgc->reg_dir && !(flags & BGPIOF_UNREADABLE_REG_DIR))
bgc->dir = bgc->read_reg(bgc->reg_dir);
return ret;
}
static void __iomem *bgpio_map(struct platform_device *pdev,
const char *name,
resource_size_t sane_sz,
int *err)
{
struct device *dev = &pdev->dev;
struct resource *r;
resource_size_t start;
resource_size_t sz;
void __iomem *ret;
*err = 0;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, name);
if (!r)
return NULL;
sz = resource_size(r);
if (sz != sane_sz) {
*err = -EINVAL;
return NULL;
}
start = r->start;
if (!devm_request_mem_region(dev, start, sz, r->name)) {
*err = -EBUSY;
return NULL;
}
ret = devm_ioremap(dev, start, sz);
if (!ret) {
*err = -ENOMEM;
return NULL;
}
return ret;
}
static int bgpio_pdev_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *r;
void __iomem *dat;
void __iomem *set;
void __iomem *clr;
void __iomem *dirout;
void __iomem *dirin;
unsigned long sz;
unsigned long flags = pdev->id_entry->driver_data;
int err;
struct bgpio_chip *bgc;
struct bgpio_pdata *pdata = dev_get_platdata(dev);
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dat");
if (!r)
return -EINVAL;
sz = resource_size(r);
dat = bgpio_map(pdev, "dat", sz, &err);
if (!dat)
return err ? err : -EINVAL;
set = bgpio_map(pdev, "set", sz, &err);
if (err)
return err;
clr = bgpio_map(pdev, "clr", sz, &err);
if (err)
return err;
dirout = bgpio_map(pdev, "dirout", sz, &err);
if (err)
return err;
dirin = bgpio_map(pdev, "dirin", sz, &err);
if (err)
return err;
bgc = devm_kzalloc(&pdev->dev, sizeof(*bgc), GFP_KERNEL);
if (!bgc)
return -ENOMEM;
err = bgpio_init(bgc, dev, sz, dat, set, clr, dirout, dirin, flags);
if (err)
return err;
if (pdata) {
if (pdata->label)
bgc->gc.label = pdata->label;
bgc->gc.base = pdata->base;
if (pdata->ngpio > 0)
bgc->gc.ngpio = pdata->ngpio;
}
platform_set_drvdata(pdev, bgc);
return gpiochip_add(&bgc->gc);
}
static int bgpio_pdev_remove(struct platform_device *pdev)
{
struct bgpio_chip *bgc = platform_get_drvdata(pdev);
return bgpio_remove(bgc);
}
