static int sch_gpio_core_direction_in(struct gpio_chip *gc, unsigned gpio_num)
{
u8 curr_dirs;
unsigned short offset, bit;
spin_lock(&gpio_lock);
offset = CGIO + gpio_num / 8;
bit = gpio_num % 8;
curr_dirs = inb(gpio_ba + offset);
if (!(curr_dirs & (1 << bit)))
outb(curr_dirs | (1 << bit), gpio_ba + offset);
spin_unlock(&gpio_lock);
return 0;
}
static int sch_gpio_core_get(struct gpio_chip *gc, unsigned gpio_num)
{
int res;
unsigned short offset, bit;
offset = CGLV + gpio_num / 8;
bit = gpio_num % 8;
res = !!(inb(gpio_ba + offset) & (1 << bit));
return res;
}
static void sch_gpio_core_set(struct gpio_chip *gc, unsigned gpio_num, int val)
{
u8 curr_vals;
unsigned short offset, bit;
spin_lock(&gpio_lock);
offset = CGLV + gpio_num / 8;
bit = gpio_num % 8;
curr_vals = inb(gpio_ba + offset);
if (val)
outb(curr_vals | (1 << bit), gpio_ba + offset);
else
outb((curr_vals & ~(1 << bit)), gpio_ba + offset);
spin_unlock(&gpio_lock);
}
static int sch_gpio_core_direction_out(struct gpio_chip *gc,
unsigned gpio_num, int val)
{
u8 curr_dirs;
unsigned short offset, bit;
spin_lock(&gpio_lock);
offset = CGIO + gpio_num / 8;
bit = gpio_num % 8;
curr_dirs = inb(gpio_ba + offset);
if (curr_dirs & (1 << bit))
outb(curr_dirs & ~(1 << bit), gpio_ba + offset);
spin_unlock(&gpio_lock);
sch_gpio_core_set(gc, gpio_num, val);
return 0;
}
static int sch_gpio_resume_direction_in(struct gpio_chip *gc,
unsigned gpio_num)
{
u8 curr_dirs;
unsigned short offset, bit;
spin_lock(&gpio_lock);
offset = RGIO + gpio_num / 8;
bit = gpio_num % 8;
curr_dirs = inb(gpio_ba + offset);
if (!(curr_dirs & (1 << bit)))
outb(curr_dirs | (1 << bit), gpio_ba + offset);
spin_unlock(&gpio_lock);
return 0;
}
static int sch_gpio_resume_get(struct gpio_chip *gc, unsigned gpio_num)
{
unsigned short offset, bit;
offset = RGLV + gpio_num / 8;
bit = gpio_num % 8;
return !!(inb(gpio_ba + offset) & (1 << bit));
}
static void sch_gpio_resume_set(struct gpio_chip *gc,
unsigned gpio_num, int val)
{
u8 curr_vals;
unsigned short offset, bit;
spin_lock(&gpio_lock);
offset = RGLV + gpio_num / 8;
bit = gpio_num % 8;
curr_vals = inb(gpio_ba + offset);
if (val)
outb(curr_vals | (1 << bit), gpio_ba + offset);
else
outb((curr_vals & ~(1 << bit)), gpio_ba + offset);
spin_unlock(&gpio_lock);
}
static int sch_gpio_resume_direction_out(struct gpio_chip *gc,
unsigned gpio_num, int val)
{
u8 curr_dirs;
unsigned short offset, bit;
offset = RGIO + gpio_num / 8;
bit = gpio_num % 8;
spin_lock(&gpio_lock);
curr_dirs = inb(gpio_ba + offset);
if (curr_dirs & (1 << bit))
outb(curr_dirs & ~(1 << bit), gpio_ba + offset);
spin_unlock(&gpio_lock);
sch_gpio_resume_set(gc, gpio_num, val);
return 0;
}
static int sch_gpio_probe(struct platform_device *pdev)
{
struct resource *res;
int err, id;
id = pdev->id;
if (!id)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!res)
return -EBUSY;
if (!request_region(res->start, resource_size(res), pdev->name))
return -EBUSY;
gpio_ba = res->start;
switch (id) {
case PCI_DEVICE_ID_INTEL_SCH_LPC:
sch_gpio_core.base = 0;
sch_gpio_core.ngpio = 10;
sch_gpio_resume.base = 10;
sch_gpio_resume.ngpio = 4;
outb(0x3, gpio_ba + CGEN + 1);
outb(0x8, gpio_ba + RGEN);
break;
case PCI_DEVICE_ID_INTEL_ITC_LPC:
sch_gpio_core.base = 0;
sch_gpio_core.ngpio = 5;
sch_gpio_resume.base = 5;
sch_gpio_resume.ngpio = 9;
break;
case PCI_DEVICE_ID_INTEL_CENTERTON_ILB:
sch_gpio_core.base = 0;
sch_gpio_core.ngpio = 21;
sch_gpio_resume.base = 21;
sch_gpio_resume.ngpio = 9;
break;
default:
err = -ENODEV;
goto err_sch_gpio_core;
}
sch_gpio_core.dev = &pdev->dev;
sch_gpio_resume.dev = &pdev->dev;
err = gpiochip_add(&sch_gpio_core);
if (err < 0)
goto err_sch_gpio_core;
err = gpiochip_add(&sch_gpio_resume);
if (err < 0)
goto err_sch_gpio_resume;
return 0;
err_sch_gpio_resume:
if (gpiochip_remove(&sch_gpio_core))
dev_err(&pdev->dev, "%s gpiochip_remove failed\n", __func__);
err_sch_gpio_core:
release_region(res->start, resource_size(res));
gpio_ba = 0;
return err;
}
static int sch_gpio_remove(struct platform_device *pdev)
{
struct resource *res;
if (gpio_ba) {
int err;
err = gpiochip_remove(&sch_gpio_core);
if (err)
dev_err(&pdev->dev, "%s failed, %d\n",
"gpiochip_remove()", err);
err = gpiochip_remove(&sch_gpio_resume);
if (err)
dev_err(&pdev->dev, "%s failed, %d\n",
"gpiochip_remove()", err);
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
release_region(res->start, resource_size(res));
gpio_ba = 0;
return err;
}
return 0;
}
