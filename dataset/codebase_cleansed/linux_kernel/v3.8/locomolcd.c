static void locomolcd_on(int comadj)
{
locomo_gpio_set_dir(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHA_ON, 0);
locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHA_ON, 1);
mdelay(2);
locomo_gpio_set_dir(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHD_ON, 0);
locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHD_ON, 1);
mdelay(2);
locomo_m62332_senddata(locomolcd_dev, comadj, 0);
mdelay(5);
locomo_gpio_set_dir(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VEE_ON, 0);
locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VEE_ON, 1);
mdelay(10);
locomo_writel(0x01, locomolcd_dev->mapbase + LOCOMO_TC);
locomo_writel(6, locomolcd_dev->mapbase + LOCOMO_CPSD);
locomo_writel((0x04 | 0x01), locomolcd_dev->mapbase + LOCOMO_TC);
mdelay(10);
locomo_gpio_set_dir(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_MOD, 0);
locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_MOD, 1);
}
static void locomolcd_off(int comadj)
{
locomo_writel(0x06, locomolcd_dev->mapbase + LOCOMO_TC);
mdelay(1);
locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHA_ON, 0);
mdelay(110);
locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VEE_ON, 0);
mdelay(700);
locomo_writel(0, locomolcd_dev->mapbase + LOCOMO_TC);
locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_MOD, 0);
locomo_gpio_write(locomolcd_dev->dev.parent, LOCOMO_GPIO_LCD_VSHD_ON, 0);
}
void locomolcd_power(int on)
{
int comadj = sharpsl_param.comadj;
unsigned long flags;
local_irq_save(flags);
if (!locomolcd_dev) {
local_irq_restore(flags);
return;
}
if (comadj == -1 && machine_is_collie())
comadj = 128;
if (comadj == -1 && machine_is_poodle())
comadj = 118;
if (on)
locomolcd_on(comadj);
else
locomolcd_off(comadj);
local_irq_restore(flags);
}
static int locomolcd_set_intensity(struct backlight_device *bd)
{
int intensity = bd->props.brightness;
if (bd->props.power != FB_BLANK_UNBLANK)
intensity = 0;
if (bd->props.fb_blank != FB_BLANK_UNBLANK)
intensity = 0;
if (locomolcd_flags & LOCOMOLCD_SUSPENDED)
intensity = 0;
switch (intensity) {
case 0:
locomo_frontlight_set(locomolcd_dev, 0, 0, 161);
break;
case 1:
locomo_frontlight_set(locomolcd_dev, 117, 0, 161);
break;
case 2:
locomo_frontlight_set(locomolcd_dev, 163, 0, 148);
break;
case 3:
locomo_frontlight_set(locomolcd_dev, 194, 0, 161);
break;
case 4:
locomo_frontlight_set(locomolcd_dev, 194, 1, 161);
break;
default:
return -ENODEV;
}
current_intensity = intensity;
return 0;
}
static int locomolcd_get_intensity(struct backlight_device *bd)
{
return current_intensity;
}
static int locomolcd_suspend(struct locomo_dev *dev, pm_message_t state)
{
locomolcd_flags |= LOCOMOLCD_SUSPENDED;
locomolcd_set_intensity(locomolcd_bl_device);
return 0;
}
static int locomolcd_resume(struct locomo_dev *dev)
{
locomolcd_flags &= ~LOCOMOLCD_SUSPENDED;
locomolcd_set_intensity(locomolcd_bl_device);
return 0;
}
static int locomolcd_probe(struct locomo_dev *ldev)
{
struct backlight_properties props;
unsigned long flags;
local_irq_save(flags);
locomolcd_dev = ldev;
locomo_gpio_set_dir(ldev->dev.parent, LOCOMO_GPIO_FL_VR, 0);
if (machine_is_poodle())
locomolcd_power(1);
local_irq_restore(flags);
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = 4;
locomolcd_bl_device = backlight_device_register("locomo-bl",
&ldev->dev, NULL,
&locomobl_data, &props);
if (IS_ERR(locomolcd_bl_device))
return PTR_ERR(locomolcd_bl_device);
locomolcd_bl_device->props.brightness = 2;
locomolcd_set_intensity(locomolcd_bl_device);
return 0;
}
static int locomolcd_remove(struct locomo_dev *dev)
{
unsigned long flags;
locomolcd_bl_device->props.brightness = 0;
locomolcd_bl_device->props.power = 0;
locomolcd_set_intensity(locomolcd_bl_device);
backlight_device_unregister(locomolcd_bl_device);
local_irq_save(flags);
locomolcd_dev = NULL;
local_irq_restore(flags);
return 0;
}
static int __init locomolcd_init(void)
{
return locomo_driver_register(&poodle_lcd_driver);
}
static void __exit locomolcd_exit(void)
{
locomo_driver_unregister(&poodle_lcd_driver);
}
