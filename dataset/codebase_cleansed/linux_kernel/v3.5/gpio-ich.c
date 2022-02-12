static int ichx_write_bit(int reg, unsigned nr, int val, int verify)
{
unsigned long flags;
u32 data, tmp;
int reg_nr = nr / 32;
int bit = nr & 0x1f;
int ret = 0;
spin_lock_irqsave(&ichx_priv.lock, flags);
data = ICHX_READ(ichx_regs[reg][reg_nr], ichx_priv.gpio_base);
if (val)
data |= 1 << bit;
else
data &= ~(1 << bit);
ICHX_WRITE(data, ichx_regs[reg][reg_nr], ichx_priv.gpio_base);
tmp = ICHX_READ(ichx_regs[reg][reg_nr], ichx_priv.gpio_base);
if (verify && data != tmp)
ret = -EPERM;
spin_unlock_irqrestore(&ichx_priv.lock, flags);
return ret;
}
static int ichx_read_bit(int reg, unsigned nr)
{
unsigned long flags;
u32 data;
int reg_nr = nr / 32;
int bit = nr & 0x1f;
spin_lock_irqsave(&ichx_priv.lock, flags);
data = ICHX_READ(ichx_regs[reg][reg_nr], ichx_priv.gpio_base);
spin_unlock_irqrestore(&ichx_priv.lock, flags);
return data & (1 << bit) ? 1 : 0;
}
static int ichx_gpio_direction_input(struct gpio_chip *gpio, unsigned nr)
{
if (ichx_write_bit(GPIO_IO_SEL, nr, 1, 1))
return -EINVAL;
return 0;
}
static int ichx_gpio_direction_output(struct gpio_chip *gpio, unsigned nr,
int val)
{
ichx_write_bit(GPIO_LVL, nr, val, 0);
if (ichx_write_bit(GPIO_IO_SEL, nr, 0, 1))
return -EINVAL;
return 0;
}
static int ichx_gpio_get(struct gpio_chip *chip, unsigned nr)
{
return ichx_read_bit(GPIO_LVL, nr);
}
static int ich6_gpio_get(struct gpio_chip *chip, unsigned nr)
{
unsigned long flags;
u32 data;
if (nr < 16) {
if (!ichx_priv.pm_base)
return -ENXIO;
spin_lock_irqsave(&ichx_priv.lock, flags);
ICHX_WRITE(1 << (16 + nr), 0, ichx_priv.pm_base);
data = ICHX_READ(0, ichx_priv.pm_base);
spin_unlock_irqrestore(&ichx_priv.lock, flags);
return (data >> 16) & (1 << nr) ? 1 : 0;
} else {
return ichx_gpio_get(chip, nr);
}
}
static int ichx_gpio_request(struct gpio_chip *chip, unsigned nr)
{
if (ichx_priv.desc->use_sel_ignore[nr / 32] & (1 << (nr & 0x1f)))
return 1;
return ichx_read_bit(GPIO_USE_SEL, nr) ? 0 : -ENODEV;
}
static int ich6_gpio_request(struct gpio_chip *chip, unsigned nr)
{
if (nr == 16 || nr == 17)
nr -= 16;
return ichx_gpio_request(chip, nr);
}
static void ichx_gpio_set(struct gpio_chip *chip, unsigned nr, int val)
{
ichx_write_bit(GPIO_LVL, nr, val, 0);
}
static void __devinit ichx_gpiolib_setup(struct gpio_chip *chip)
{
chip->owner = THIS_MODULE;
chip->label = DRV_NAME;
chip->dev = &ichx_priv.dev->dev;
chip->request = ichx_priv.desc->request ?
ichx_priv.desc->request : ichx_gpio_request;
chip->get = ichx_priv.desc->get ?
ichx_priv.desc->get : ichx_gpio_get;
chip->set = ichx_gpio_set;
chip->direction_input = ichx_gpio_direction_input;
chip->direction_output = ichx_gpio_direction_output;
chip->base = modparam_gpiobase;
chip->ngpio = ichx_priv.desc->ngpio;
chip->can_sleep = 0;
chip->dbg_show = NULL;
}
static int __devinit ichx_gpio_probe(struct platform_device *pdev)
{
struct resource *res_base, *res_pm;
int err;
struct lpc_ich_info *ich_info = pdev->dev.platform_data;
if (!ich_info)
return -ENODEV;
ichx_priv.dev = pdev;
switch (ich_info->gpio_version) {
case ICH_I3100_GPIO:
ichx_priv.desc = &i3100_desc;
break;
case ICH_V5_GPIO:
ichx_priv.desc = &intel5_desc;
break;
case ICH_V6_GPIO:
ichx_priv.desc = &ich6_desc;
break;
case ICH_V7_GPIO:
ichx_priv.desc = &ich7_desc;
break;
case ICH_V9_GPIO:
ichx_priv.desc = &ich9_desc;
break;
case ICH_V10CORP_GPIO:
ichx_priv.desc = &ich10_corp_desc;
break;
case ICH_V10CONS_GPIO:
ichx_priv.desc = &ich10_cons_desc;
break;
default:
return -ENODEV;
}
res_base = platform_get_resource(pdev, IORESOURCE_IO, ICH_RES_GPIO);
if (!res_base || !res_base->start || !res_base->end)
return -ENODEV;
if (!request_region(res_base->start, resource_size(res_base),
pdev->name))
return -EBUSY;
ichx_priv.gpio_base = res_base;
if (!ichx_priv.desc->uses_gpe0)
goto init;
res_pm = platform_get_resource(pdev, IORESOURCE_IO, ICH_RES_GPE0);
if (!res_pm) {
pr_warn("ACPI BAR is unavailable, GPI 0 - 15 unavailable\n");
goto init;
}
if (!request_region(res_pm->start, resource_size(res_pm),
pdev->name)) {
pr_warn("ACPI BAR is busy, GPI 0 - 15 unavailable\n");
goto init;
}
ichx_priv.pm_base = res_pm;
init:
ichx_gpiolib_setup(&ichx_priv.chip);
err = gpiochip_add(&ichx_priv.chip);
if (err) {
pr_err("Failed to register GPIOs\n");
goto add_err;
}
pr_info("GPIO from %d to %d on %s\n", ichx_priv.chip.base,
ichx_priv.chip.base + ichx_priv.chip.ngpio - 1, DRV_NAME);
return 0;
add_err:
release_region(ichx_priv.gpio_base->start,
resource_size(ichx_priv.gpio_base));
if (ichx_priv.pm_base)
release_region(ichx_priv.pm_base->start,
resource_size(ichx_priv.pm_base));
return err;
}
static int __devexit ichx_gpio_remove(struct platform_device *pdev)
{
int err;
err = gpiochip_remove(&ichx_priv.chip);
if (err) {
dev_err(&pdev->dev, "%s failed, %d\n",
"gpiochip_remove()", err);
return err;
}
release_region(ichx_priv.gpio_base->start,
resource_size(ichx_priv.gpio_base));
if (ichx_priv.pm_base)
release_region(ichx_priv.pm_base->start,
resource_size(ichx_priv.pm_base));
return 0;
}
