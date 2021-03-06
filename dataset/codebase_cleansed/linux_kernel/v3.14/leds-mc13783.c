static void mc13xxx_led_work(struct work_struct *work)
{
struct mc13xxx_led *led = container_of(work, struct mc13xxx_led, work);
int reg, mask, value, bank, off, shift;
switch (led->id) {
case MC13783_LED_MD:
reg = MC13XXX_REG_LED_CONTROL(2);
shift = 9;
mask = 0x0f;
value = led->new_brightness >> 4;
break;
case MC13783_LED_AD:
reg = MC13XXX_REG_LED_CONTROL(2);
shift = 13;
mask = 0x0f;
value = led->new_brightness >> 4;
break;
case MC13783_LED_KP:
reg = MC13XXX_REG_LED_CONTROL(2);
shift = 17;
mask = 0x0f;
value = led->new_brightness >> 4;
break;
case MC13783_LED_R1:
case MC13783_LED_G1:
case MC13783_LED_B1:
case MC13783_LED_R2:
case MC13783_LED_G2:
case MC13783_LED_B2:
case MC13783_LED_R3:
case MC13783_LED_G3:
case MC13783_LED_B3:
off = led->id - MC13783_LED_R1;
bank = off / 3;
reg = MC13XXX_REG_LED_CONTROL(3) + bank;
shift = (off - bank * 3) * 5 + 6;
value = led->new_brightness >> 3;
mask = 0x1f;
break;
case MC13892_LED_MD:
reg = MC13XXX_REG_LED_CONTROL(0);
shift = 3;
mask = 0x3f;
value = led->new_brightness >> 2;
break;
case MC13892_LED_AD:
reg = MC13XXX_REG_LED_CONTROL(0);
shift = 15;
mask = 0x3f;
value = led->new_brightness >> 2;
break;
case MC13892_LED_KP:
reg = MC13XXX_REG_LED_CONTROL(1);
shift = 3;
mask = 0x3f;
value = led->new_brightness >> 2;
break;
case MC13892_LED_R:
case MC13892_LED_G:
case MC13892_LED_B:
off = led->id - MC13892_LED_R;
bank = off / 2;
reg = MC13XXX_REG_LED_CONTROL(2) + bank;
shift = (off - bank * 2) * 12 + 3;
value = led->new_brightness >> 2;
mask = 0x3f;
break;
default:
BUG();
}
mc13xxx_reg_rmw(led->master, reg, mask << shift, value << shift);
}
static void mc13xxx_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct mc13xxx_led *led =
container_of(led_cdev, struct mc13xxx_led, cdev);
led->new_brightness = value;
schedule_work(&led->work);
}
static int __init mc13xxx_led_probe(struct platform_device *pdev)
{
struct mc13xxx_leds_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct mc13xxx *mcdev = dev_get_drvdata(pdev->dev.parent);
struct mc13xxx_led_devtype *devtype =
(struct mc13xxx_led_devtype *)pdev->id_entry->driver_data;
struct mc13xxx_leds *leds;
int i, id, num_leds, ret = -ENODATA;
u32 reg, init_led = 0;
if (!pdata) {
dev_err(&pdev->dev, "Missing platform data\n");
return -ENODEV;
}
num_leds = pdata->num_leds;
if ((num_leds < 1) ||
(num_leds > (devtype->led_max - devtype->led_min + 1))) {
dev_err(&pdev->dev, "Invalid LED count %d\n", num_leds);
return -EINVAL;
}
leds = devm_kzalloc(&pdev->dev, num_leds * sizeof(struct mc13xxx_led) +
sizeof(struct mc13xxx_leds), GFP_KERNEL);
if (!leds)
return -ENOMEM;
leds->devtype = devtype;
leds->num_leds = num_leds;
platform_set_drvdata(pdev, leds);
for (i = 0; i < devtype->num_regs; i++) {
reg = pdata->led_control[i];
WARN_ON(reg >= (1 << 24));
ret = mc13xxx_reg_write(mcdev, MC13XXX_REG_LED_CONTROL(i), reg);
if (ret)
return ret;
}
for (i = 0; i < num_leds; i++) {
const char *name, *trig;
ret = -EINVAL;
id = pdata->led[i].id;
name = pdata->led[i].name;
trig = pdata->led[i].default_trigger;
if ((id > devtype->led_max) || (id < devtype->led_min)) {
dev_err(&pdev->dev, "Invalid ID %i\n", id);
break;
}
if (init_led & (1 << id)) {
dev_warn(&pdev->dev,
"LED %i already initialized\n", id);
break;
}
init_led |= 1 << id;
leds->led[i].id = id;
leds->led[i].master = mcdev;
leds->led[i].cdev.name = name;
leds->led[i].cdev.default_trigger = trig;
leds->led[i].cdev.brightness_set = mc13xxx_led_set;
leds->led[i].cdev.brightness = LED_OFF;
INIT_WORK(&leds->led[i].work, mc13xxx_led_work);
ret = led_classdev_register(pdev->dev.parent,
&leds->led[i].cdev);
if (ret) {
dev_err(&pdev->dev, "Failed to register LED %i\n", id);
break;
}
}
if (ret)
while (--i >= 0) {
led_classdev_unregister(&leds->led[i].cdev);
cancel_work_sync(&leds->led[i].work);
}
return ret;
}
static int mc13xxx_led_remove(struct platform_device *pdev)
{
struct mc13xxx *mcdev = dev_get_drvdata(pdev->dev.parent);
struct mc13xxx_leds *leds = platform_get_drvdata(pdev);
int i;
for (i = 0; i < leds->num_leds; i++) {
led_classdev_unregister(&leds->led[i].cdev);
cancel_work_sync(&leds->led[i].work);
}
for (i = 0; i < leds->devtype->num_regs; i++)
mc13xxx_reg_write(mcdev, MC13XXX_REG_LED_CONTROL(i), 0);
return 0;
}
