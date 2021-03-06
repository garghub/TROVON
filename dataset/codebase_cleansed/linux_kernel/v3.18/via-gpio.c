static void via_gpio_set(struct gpio_chip *chip, unsigned int nr,
int value)
{
struct viafb_gpio_cfg *cfg = container_of(chip,
struct viafb_gpio_cfg,
gpio_chip);
u8 reg;
struct viafb_gpio *gpio;
unsigned long flags;
spin_lock_irqsave(&cfg->vdev->reg_lock, flags);
gpio = cfg->active_gpios[nr];
reg = via_read_reg(VIASR, gpio->vg_port_index);
reg |= 0x40 << gpio->vg_mask_shift;
if (value)
reg |= 0x10 << gpio->vg_mask_shift;
else
reg &= ~(0x10 << gpio->vg_mask_shift);
via_write_reg(VIASR, gpio->vg_port_index, reg);
spin_unlock_irqrestore(&cfg->vdev->reg_lock, flags);
}
static int via_gpio_dir_out(struct gpio_chip *chip, unsigned int nr,
int value)
{
via_gpio_set(chip, nr, value);
return 0;
}
static int via_gpio_dir_input(struct gpio_chip *chip, unsigned int nr)
{
struct viafb_gpio_cfg *cfg = container_of(chip,
struct viafb_gpio_cfg,
gpio_chip);
struct viafb_gpio *gpio;
unsigned long flags;
spin_lock_irqsave(&cfg->vdev->reg_lock, flags);
gpio = cfg->active_gpios[nr];
via_write_reg_mask(VIASR, gpio->vg_port_index, 0,
0x40 << gpio->vg_mask_shift);
spin_unlock_irqrestore(&cfg->vdev->reg_lock, flags);
return 0;
}
static int via_gpio_get(struct gpio_chip *chip, unsigned int nr)
{
struct viafb_gpio_cfg *cfg = container_of(chip,
struct viafb_gpio_cfg,
gpio_chip);
u8 reg;
struct viafb_gpio *gpio;
unsigned long flags;
spin_lock_irqsave(&cfg->vdev->reg_lock, flags);
gpio = cfg->active_gpios[nr];
reg = via_read_reg(VIASR, gpio->vg_port_index);
spin_unlock_irqrestore(&cfg->vdev->reg_lock, flags);
return reg & (0x04 << gpio->vg_mask_shift);
}
static void viafb_gpio_enable(struct viafb_gpio *gpio)
{
via_write_reg_mask(VIASR, gpio->vg_port_index, 0x02, 0x02);
}
static void viafb_gpio_disable(struct viafb_gpio *gpio)
{
via_write_reg_mask(VIASR, gpio->vg_port_index, 0, 0x02);
}
static int viafb_gpio_suspend(void *private)
{
return 0;
}
static int viafb_gpio_resume(void *private)
{
int i;
for (i = 0; i < viafb_gpio_config.gpio_chip.ngpio; i += 2)
viafb_gpio_enable(viafb_gpio_config.active_gpios[i]);
return 0;
}
int viafb_gpio_lookup(const char *name)
{
int i;
for (i = 0; i < viafb_gpio_config.gpio_chip.ngpio; i++)
if (!strcmp(name, viafb_gpio_config.active_gpios[i]->vg_name))
return viafb_gpio_config.gpio_chip.base + i;
return -1;
}
static int viafb_gpio_probe(struct platform_device *platdev)
{
struct viafb_dev *vdev = platdev->dev.platform_data;
struct via_port_cfg *port_cfg = vdev->port_cfg;
int i, ngpio = 0, ret;
struct viafb_gpio *gpio;
unsigned long flags;
for (i = 0; i < VIAFB_NUM_PORTS; i++) {
if (port_cfg[i].mode != VIA_MODE_GPIO)
continue;
for (gpio = viafb_all_gpios;
gpio < viafb_all_gpios + VIAFB_NUM_GPIOS; gpio++)
if (gpio->vg_port_index == port_cfg[i].ioport_index) {
viafb_gpio_config.active_gpios[ngpio] = gpio;
viafb_gpio_config.gpio_names[ngpio] =
gpio->vg_name;
ngpio++;
}
}
viafb_gpio_config.gpio_chip.ngpio = ngpio;
viafb_gpio_config.gpio_chip.names = viafb_gpio_config.gpio_names;
viafb_gpio_config.vdev = vdev;
if (ngpio == 0) {
printk(KERN_INFO "viafb: no GPIOs configured\n");
return 0;
}
spin_lock_irqsave(&viafb_gpio_config.vdev->reg_lock, flags);
for (i = 0; i < ngpio; i += 2)
viafb_gpio_enable(viafb_gpio_config.active_gpios[i]);
spin_unlock_irqrestore(&viafb_gpio_config.vdev->reg_lock, flags);
viafb_gpio_config.gpio_chip.base = -1;
ret = gpiochip_add(&viafb_gpio_config.gpio_chip);
if (ret) {
printk(KERN_ERR "viafb: failed to add gpios (%d)\n", ret);
viafb_gpio_config.gpio_chip.ngpio = 0;
}
#ifdef CONFIG_PM
viafb_pm_register(&viafb_gpio_pm_hooks);
#endif
return ret;
}
static int viafb_gpio_remove(struct platform_device *platdev)
{
unsigned long flags;
int i;
#ifdef CONFIG_PM
viafb_pm_unregister(&viafb_gpio_pm_hooks);
#endif
if (viafb_gpio_config.gpio_chip.ngpio > 0) {
gpiochip_remove(&viafb_gpio_config.gpio_chip);
}
spin_lock_irqsave(&viafb_gpio_config.vdev->reg_lock, flags);
for (i = 0; i < viafb_gpio_config.gpio_chip.ngpio; i += 2)
viafb_gpio_disable(viafb_gpio_config.active_gpios[i]);
viafb_gpio_config.gpio_chip.ngpio = 0;
spin_unlock_irqrestore(&viafb_gpio_config.vdev->reg_lock, flags);
return 0;
}
int viafb_gpio_init(void)
{
return platform_driver_register(&via_gpio_driver);
}
void viafb_gpio_exit(void)
{
platform_driver_unregister(&via_gpio_driver);
}
