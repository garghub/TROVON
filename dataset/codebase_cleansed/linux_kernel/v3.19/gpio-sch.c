static unsigned sch_gpio_offset(struct sch_gpio *sch, unsigned gpio,
unsigned reg)
{
unsigned base = 0;
if (gpio >= sch->resume_base) {
gpio -= sch->resume_base;
base += 0x20;
}
return base + reg + gpio / 8;
}
static unsigned sch_gpio_bit(struct sch_gpio *sch, unsigned gpio)
{
if (gpio >= sch->resume_base)
gpio -= sch->resume_base;
return gpio % 8;
}
static void sch_gpio_enable(struct sch_gpio *sch, unsigned gpio)
{
unsigned short offset, bit;
u8 enable;
spin_lock(&sch->lock);
offset = sch_gpio_offset(sch, gpio, GEN);
bit = sch_gpio_bit(sch, gpio);
enable = inb(sch->iobase + offset);
if (!(enable & (1 << bit)))
outb(enable | (1 << bit), sch->iobase + offset);
spin_unlock(&sch->lock);
}
static int sch_gpio_direction_in(struct gpio_chip *gc, unsigned gpio_num)
{
struct sch_gpio *sch = to_sch_gpio(gc);
u8 curr_dirs;
unsigned short offset, bit;
spin_lock(&sch->lock);
offset = sch_gpio_offset(sch, gpio_num, GIO);
bit = sch_gpio_bit(sch, gpio_num);
curr_dirs = inb(sch->iobase + offset);
if (!(curr_dirs & (1 << bit)))
outb(curr_dirs | (1 << bit), sch->iobase + offset);
spin_unlock(&sch->lock);
return 0;
}
static int sch_gpio_get(struct gpio_chip *gc, unsigned gpio_num)
{
struct sch_gpio *sch = to_sch_gpio(gc);
int res;
unsigned short offset, bit;
offset = sch_gpio_offset(sch, gpio_num, GLV);
bit = sch_gpio_bit(sch, gpio_num);
res = !!(inb(sch->iobase + offset) & (1 << bit));
return res;
}
static void sch_gpio_set(struct gpio_chip *gc, unsigned gpio_num, int val)
{
struct sch_gpio *sch = to_sch_gpio(gc);
u8 curr_vals;
unsigned short offset, bit;
spin_lock(&sch->lock);
offset = sch_gpio_offset(sch, gpio_num, GLV);
bit = sch_gpio_bit(sch, gpio_num);
curr_vals = inb(sch->iobase + offset);
if (val)
outb(curr_vals | (1 << bit), sch->iobase + offset);
else
outb((curr_vals & ~(1 << bit)), sch->iobase + offset);
spin_unlock(&sch->lock);
}
static int sch_gpio_direction_out(struct gpio_chip *gc, unsigned gpio_num,
int val)
{
struct sch_gpio *sch = to_sch_gpio(gc);
u8 curr_dirs;
unsigned short offset, bit;
spin_lock(&sch->lock);
offset = sch_gpio_offset(sch, gpio_num, GIO);
bit = sch_gpio_bit(sch, gpio_num);
curr_dirs = inb(sch->iobase + offset);
if (curr_dirs & (1 << bit))
outb(curr_dirs & ~(1 << bit), sch->iobase + offset);
spin_unlock(&sch->lock);
sch_gpio_set(gc, gpio_num, val);
return 0;
}
static int sch_gpio_probe(struct platform_device *pdev)
{
struct sch_gpio *sch;
struct resource *res;
sch = devm_kzalloc(&pdev->dev, sizeof(*sch), GFP_KERNEL);
if (!sch)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!res)
return -EBUSY;
if (!devm_request_region(&pdev->dev, res->start, resource_size(res),
pdev->name))
return -EBUSY;
spin_lock_init(&sch->lock);
sch->iobase = res->start;
sch->chip = sch_gpio_chip;
sch->chip.label = dev_name(&pdev->dev);
sch->chip.dev = &pdev->dev;
switch (pdev->id) {
case PCI_DEVICE_ID_INTEL_SCH_LPC:
sch->core_base = 0;
sch->resume_base = 10;
sch->chip.ngpio = 14;
sch_gpio_enable(sch, 8);
sch_gpio_enable(sch, 9);
sch_gpio_enable(sch, 13);
break;
case PCI_DEVICE_ID_INTEL_ITC_LPC:
sch->core_base = 0;
sch->resume_base = 5;
sch->chip.ngpio = 14;
break;
case PCI_DEVICE_ID_INTEL_CENTERTON_ILB:
sch->core_base = 0;
sch->resume_base = 21;
sch->chip.ngpio = 30;
break;
default:
return -ENODEV;
}
platform_set_drvdata(pdev, sch);
return gpiochip_add(&sch->chip);
}
static int sch_gpio_remove(struct platform_device *pdev)
{
struct sch_gpio *sch = platform_get_drvdata(pdev);
gpiochip_remove(&sch->chip);
return 0;
}
