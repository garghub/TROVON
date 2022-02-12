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
static unsigned long bgpio_pin2mask(struct gpio_chip *gc, unsigned int pin)
{
return BIT(pin);
}
static unsigned long bgpio_pin2mask_be(struct gpio_chip *gc,
unsigned int pin)
{
return BIT(gc->bgpio_bits - 1 - pin);
}
static int bgpio_get_set(struct gpio_chip *gc, unsigned int gpio)
{
unsigned long pinmask = gc->pin2mask(gc, gpio);
if (gc->bgpio_dir & pinmask)
return !!(gc->read_reg(gc->reg_set) & pinmask);
else
return !!(gc->read_reg(gc->reg_dat) & pinmask);
}
static int bgpio_get(struct gpio_chip *gc, unsigned int gpio)
{
return !!(gc->read_reg(gc->reg_dat) & gc->pin2mask(gc, gpio));
}
static void bgpio_set_none(struct gpio_chip *gc, unsigned int gpio, int val)
{
}
static void bgpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long mask = gc->pin2mask(gc, gpio);
unsigned long flags;
spin_lock_irqsave(&gc->bgpio_lock, flags);
if (val)
gc->bgpio_data |= mask;
else
gc->bgpio_data &= ~mask;
gc->write_reg(gc->reg_dat, gc->bgpio_data);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
}
static void bgpio_set_with_clear(struct gpio_chip *gc, unsigned int gpio,
int val)
{
unsigned long mask = gc->pin2mask(gc, gpio);
if (val)
gc->write_reg(gc->reg_set, mask);
else
gc->write_reg(gc->reg_clr, mask);
}
static void bgpio_set_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long mask = gc->pin2mask(gc, gpio);
unsigned long flags;
spin_lock_irqsave(&gc->bgpio_lock, flags);
if (val)
gc->bgpio_data |= mask;
else
gc->bgpio_data &= ~mask;
gc->write_reg(gc->reg_set, gc->bgpio_data);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
}
static void bgpio_multiple_get_masks(struct gpio_chip *gc,
unsigned long *mask, unsigned long *bits,
unsigned long *set_mask,
unsigned long *clear_mask)
{
int i;
*set_mask = 0;
*clear_mask = 0;
for (i = 0; i < gc->bgpio_bits; i++) {
if (*mask == 0)
break;
if (__test_and_clear_bit(i, mask)) {
if (test_bit(i, bits))
*set_mask |= gc->pin2mask(gc, i);
else
*clear_mask |= gc->pin2mask(gc, i);
}
}
}
static void bgpio_set_multiple_single_reg(struct gpio_chip *gc,
unsigned long *mask,
unsigned long *bits,
void __iomem *reg)
{
unsigned long flags;
unsigned long set_mask, clear_mask;
spin_lock_irqsave(&gc->bgpio_lock, flags);
bgpio_multiple_get_masks(gc, mask, bits, &set_mask, &clear_mask);
gc->bgpio_data |= set_mask;
gc->bgpio_data &= ~clear_mask;
gc->write_reg(reg, gc->bgpio_data);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
}
static void bgpio_set_multiple(struct gpio_chip *gc, unsigned long *mask,
unsigned long *bits)
{
bgpio_set_multiple_single_reg(gc, mask, bits, gc->reg_dat);
}
static void bgpio_set_multiple_set(struct gpio_chip *gc, unsigned long *mask,
unsigned long *bits)
{
bgpio_set_multiple_single_reg(gc, mask, bits, gc->reg_set);
}
static void bgpio_set_multiple_with_clear(struct gpio_chip *gc,
unsigned long *mask,
unsigned long *bits)
{
unsigned long set_mask, clear_mask;
bgpio_multiple_get_masks(gc, mask, bits, &set_mask, &clear_mask);
if (set_mask)
gc->write_reg(gc->reg_set, set_mask);
if (clear_mask)
gc->write_reg(gc->reg_clr, clear_mask);
}
static int bgpio_simple_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
return 0;
}
static int bgpio_dir_out_err(struct gpio_chip *gc, unsigned int gpio,
int val)
{
return -EINVAL;
}
static int bgpio_simple_dir_out(struct gpio_chip *gc, unsigned int gpio,
int val)
{
gc->set(gc, gpio, val);
return 0;
}
static int bgpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
unsigned long flags;
spin_lock_irqsave(&gc->bgpio_lock, flags);
gc->bgpio_dir &= ~gc->pin2mask(gc, gpio);
gc->write_reg(gc->reg_dir, gc->bgpio_dir);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
return 0;
}
static int bgpio_get_dir(struct gpio_chip *gc, unsigned int gpio)
{
return !(gc->read_reg(gc->reg_dir) & gc->pin2mask(gc, gpio));
}
static int bgpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
gc->set(gc, gpio, val);
spin_lock_irqsave(&gc->bgpio_lock, flags);
gc->bgpio_dir |= gc->pin2mask(gc, gpio);
gc->write_reg(gc->reg_dir, gc->bgpio_dir);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
return 0;
}
static int bgpio_dir_in_inv(struct gpio_chip *gc, unsigned int gpio)
{
unsigned long flags;
spin_lock_irqsave(&gc->bgpio_lock, flags);
gc->bgpio_dir |= gc->pin2mask(gc, gpio);
gc->write_reg(gc->reg_dir, gc->bgpio_dir);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
return 0;
}
static int bgpio_dir_out_inv(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
gc->set(gc, gpio, val);
spin_lock_irqsave(&gc->bgpio_lock, flags);
gc->bgpio_dir &= ~gc->pin2mask(gc, gpio);
gc->write_reg(gc->reg_dir, gc->bgpio_dir);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
return 0;
}
static int bgpio_get_dir_inv(struct gpio_chip *gc, unsigned int gpio)
{
return !!(gc->read_reg(gc->reg_dir) & gc->pin2mask(gc, gpio));
}
static int bgpio_setup_accessors(struct device *dev,
struct gpio_chip *gc,
bool bit_be,
bool byte_be)
{
switch (gc->bgpio_bits) {
case 8:
gc->read_reg = bgpio_read8;
gc->write_reg = bgpio_write8;
break;
case 16:
if (byte_be) {
gc->read_reg = bgpio_read16be;
gc->write_reg = bgpio_write16be;
} else {
gc->read_reg = bgpio_read16;
gc->write_reg = bgpio_write16;
}
break;
case 32:
if (byte_be) {
gc->read_reg = bgpio_read32be;
gc->write_reg = bgpio_write32be;
} else {
gc->read_reg = bgpio_read32;
gc->write_reg = bgpio_write32;
}
break;
#if BITS_PER_LONG >= 64
case 64:
if (byte_be) {
dev_err(dev,
"64 bit big endian byte order unsupported\n");
return -EINVAL;
} else {
gc->read_reg = bgpio_read64;
gc->write_reg = bgpio_write64;
}
break;
#endif
default:
dev_err(dev, "unsupported data width %u bits\n", gc->bgpio_bits);
return -EINVAL;
}
gc->pin2mask = bit_be ? bgpio_pin2mask_be : bgpio_pin2mask;
return 0;
}
static int bgpio_setup_io(struct gpio_chip *gc,
void __iomem *dat,
void __iomem *set,
void __iomem *clr,
unsigned long flags)
{
gc->reg_dat = dat;
if (!gc->reg_dat)
return -EINVAL;
if (set && clr) {
gc->reg_set = set;
gc->reg_clr = clr;
gc->set = bgpio_set_with_clear;
gc->set_multiple = bgpio_set_multiple_with_clear;
} else if (set && !clr) {
gc->reg_set = set;
gc->set = bgpio_set_set;
gc->set_multiple = bgpio_set_multiple_set;
} else if (flags & BGPIOF_NO_OUTPUT) {
gc->set = bgpio_set_none;
gc->set_multiple = NULL;
} else {
gc->set = bgpio_set;
gc->set_multiple = bgpio_set_multiple;
}
if (!(flags & BGPIOF_UNREADABLE_REG_SET) &&
(flags & BGPIOF_READ_OUTPUT_REG_SET))
gc->get = bgpio_get_set;
else
gc->get = bgpio_get;
return 0;
}
static int bgpio_setup_direction(struct gpio_chip *gc,
void __iomem *dirout,
void __iomem *dirin,
unsigned long flags)
{
if (dirout && dirin) {
return -EINVAL;
} else if (dirout) {
gc->reg_dir = dirout;
gc->direction_output = bgpio_dir_out;
gc->direction_input = bgpio_dir_in;
gc->get_direction = bgpio_get_dir;
} else if (dirin) {
gc->reg_dir = dirin;
gc->direction_output = bgpio_dir_out_inv;
gc->direction_input = bgpio_dir_in_inv;
gc->get_direction = bgpio_get_dir_inv;
} else {
if (flags & BGPIOF_NO_OUTPUT)
gc->direction_output = bgpio_dir_out_err;
else
gc->direction_output = bgpio_simple_dir_out;
gc->direction_input = bgpio_simple_dir_in;
}
return 0;
}
static int bgpio_request(struct gpio_chip *chip, unsigned gpio_pin)
{
if (gpio_pin < chip->ngpio)
return 0;
return -EINVAL;
}
int bgpio_init(struct gpio_chip *gc, struct device *dev,
unsigned long sz, void __iomem *dat, void __iomem *set,
void __iomem *clr, void __iomem *dirout, void __iomem *dirin,
unsigned long flags)
{
int ret;
if (!is_power_of_2(sz))
return -EINVAL;
gc->bgpio_bits = sz * 8;
if (gc->bgpio_bits > BITS_PER_LONG)
return -EINVAL;
spin_lock_init(&gc->bgpio_lock);
gc->parent = dev;
gc->label = dev_name(dev);
gc->base = -1;
gc->ngpio = gc->bgpio_bits;
gc->request = bgpio_request;
ret = bgpio_setup_io(gc, dat, set, clr, flags);
if (ret)
return ret;
ret = bgpio_setup_accessors(dev, gc, flags & BGPIOF_BIG_ENDIAN,
flags & BGPIOF_BIG_ENDIAN_BYTE_ORDER);
if (ret)
return ret;
ret = bgpio_setup_direction(gc, dirout, dirin, flags);
if (ret)
return ret;
gc->bgpio_data = gc->read_reg(gc->reg_dat);
if (gc->set == bgpio_set_set &&
!(flags & BGPIOF_UNREADABLE_REG_SET))
gc->bgpio_data = gc->read_reg(gc->reg_set);
if (gc->reg_dir && !(flags & BGPIOF_UNREADABLE_REG_DIR))
gc->bgpio_dir = gc->read_reg(gc->reg_dir);
return ret;
}
static void __iomem *bgpio_map(struct platform_device *pdev,
const char *name,
resource_size_t sane_sz)
{
struct resource *r;
resource_size_t sz;
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, name);
if (!r)
return NULL;
sz = resource_size(r);
if (sz != sane_sz)
return IOMEM_ERR_PTR(-EINVAL);
return devm_ioremap_resource(&pdev->dev, r);
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
struct gpio_chip *gc;
struct bgpio_pdata *pdata = dev_get_platdata(dev);
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "dat");
if (!r)
return -EINVAL;
sz = resource_size(r);
dat = bgpio_map(pdev, "dat", sz);
if (IS_ERR(dat))
return PTR_ERR(dat);
set = bgpio_map(pdev, "set", sz);
if (IS_ERR(set))
return PTR_ERR(set);
clr = bgpio_map(pdev, "clr", sz);
if (IS_ERR(clr))
return PTR_ERR(clr);
dirout = bgpio_map(pdev, "dirout", sz);
if (IS_ERR(dirout))
return PTR_ERR(dirout);
dirin = bgpio_map(pdev, "dirin", sz);
if (IS_ERR(dirin))
return PTR_ERR(dirin);
gc = devm_kzalloc(&pdev->dev, sizeof(*gc), GFP_KERNEL);
if (!gc)
return -ENOMEM;
err = bgpio_init(gc, dev, sz, dat, set, clr, dirout, dirin, flags);
if (err)
return err;
if (pdata) {
if (pdata->label)
gc->label = pdata->label;
gc->base = pdata->base;
if (pdata->ngpio > 0)
gc->ngpio = pdata->ngpio;
}
platform_set_drvdata(pdev, gc);
return devm_gpiochip_add_data(&pdev->dev, gc, NULL);
}
