static void idp_backlight_power(int on)
{
if (on) {
IDP_CPLD_LCD |= (1<<1);
} else {
IDP_CPLD_LCD &= ~(1<<1);
}
}
static void idp_vlcd(int on)
{
if (on) {
IDP_CPLD_LCD |= (1<<2);
} else {
IDP_CPLD_LCD &= ~(1<<2);
}
}
static void idp_lcd_power(int on, struct fb_var_screeninfo *var)
{
if (on) {
IDP_CPLD_LCD |= (1<<0);
} else {
IDP_CPLD_LCD &= ~(1<<0);
}
idp_vlcd(on);
}
static void __init idp_init(void)
{
printk("idp_init()\n");
pxa2xx_mfp_config(ARRAY_AND_SIZE(idp_pin_config));
pxa_set_ffuart_info(NULL);
pxa_set_btuart_info(NULL);
pxa_set_stuart_info(NULL);
platform_device_register(&smc91x_device);
pxa_set_fb_info(NULL, &sharp_lm8v31);
pxa_set_mci_info(&idp_mci_platform_data);
}
static void __init idp_map_io(void)
{
pxa25x_map_io();
iotable_init(idp_io_desc, ARRAY_SIZE(idp_io_desc));
}
static void idp_led_set(struct led_classdev *cdev,
enum led_brightness b)
{
struct idp_led *led = container_of(cdev,
struct idp_led, cdev);
u32 reg = IDP_CPLD_LED_CONTROL;
if (b != LED_OFF)
reg &= ~led->mask;
else
reg |= led->mask;
IDP_CPLD_LED_CONTROL = reg;
}
static enum led_brightness idp_led_get(struct led_classdev *cdev)
{
struct idp_led *led = container_of(cdev,
struct idp_led, cdev);
return (IDP_CPLD_LED_CONTROL & led->mask) ? LED_OFF : LED_FULL;
}
static int __init idp_leds_init(void)
{
int i;
if (!machine_is_pxa_idp())
return -ENODEV;
for (i = 0; i < ARRAY_SIZE(idp_leds); i++) {
struct idp_led *led;
led = kzalloc(sizeof(*led), GFP_KERNEL);
if (!led)
break;
led->cdev.name = idp_leds[i].name;
led->cdev.brightness_set = idp_led_set;
led->cdev.brightness_get = idp_led_get;
led->cdev.default_trigger = idp_leds[i].trigger;
if (i == 0)
led->mask = IDP_HB_LED;
else
led->mask = IDP_BUSY_LED;
if (led_classdev_register(NULL, &led->cdev) < 0) {
kfree(led);
break;
}
}
return 0;
}
