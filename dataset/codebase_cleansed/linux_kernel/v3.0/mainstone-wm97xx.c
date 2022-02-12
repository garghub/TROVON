static void wm97xx_acc_pen_up(struct wm97xx *wm)
{
schedule_timeout_uninterruptible(1);
while (MISR & (1 << 2))
MODR;
}
static void wm97xx_acc_pen_up(struct wm97xx *wm)
{
unsigned int count;
schedule_timeout_uninterruptible(1);
for (count = 0; count < 16; count++)
MODR;
}
static int wm97xx_acc_pen_down(struct wm97xx *wm)
{
u16 x, y, p = 0x100 | WM97XX_ADCSEL_PRES;
int reads = 0;
schedule_timeout_uninterruptible(1);
if (tries > 5) {
tries = 0;
return RC_PENUP;
}
x = MODR;
if (x == last) {
tries++;
return RC_AGAIN;
}
last = x;
do {
if (reads)
x = MODR;
y = MODR;
if (pressure)
p = MODR;
dev_dbg(wm->dev, "Raw coordinates: x=%x, y=%x, p=%x\n",
x, y, p);
if ((x & WM97XX_ADCSRC_MASK) != WM97XX_ADCSEL_X ||
(y & WM97XX_ADCSRC_MASK) != WM97XX_ADCSEL_Y ||
(p & WM97XX_ADCSRC_MASK) != WM97XX_ADCSEL_PRES)
goto up;
tries = 0;
input_report_abs(wm->input_dev, ABS_X, x & 0xfff);
input_report_abs(wm->input_dev, ABS_Y, y & 0xfff);
input_report_abs(wm->input_dev, ABS_PRESSURE, p & 0xfff);
input_report_key(wm->input_dev, BTN_TOUCH, (p != 0));
input_sync(wm->input_dev);
reads++;
} while (reads < cinfo[sp_idx].reads);
up:
return RC_PENDOWN | RC_AGAIN;
}
static int wm97xx_acc_startup(struct wm97xx *wm)
{
int idx = 0, ret = 0;
if (wm->ac97 == NULL)
return -ENODEV;
for (idx = 0; idx < ARRAY_SIZE(cinfo); idx++) {
if (wm->id != cinfo[idx].id)
continue;
sp_idx = idx;
if (cont_rate <= cinfo[idx].speed)
break;
}
wm->acc_rate = cinfo[sp_idx].code;
wm->acc_slot = ac97_touch_slot;
dev_info(wm->dev,
"mainstone accelerated touchscreen driver, %d samples/sec\n",
cinfo[sp_idx].speed);
if (machine_is_palmt5() || machine_is_palmtx() || machine_is_palmld()) {
pen_int = 1;
irq = 27;
wm->variant = WM97xx_WM1613;
} else if (machine_is_mainstone() && pen_int)
irq = 4;
if (irq) {
ret = gpio_request(irq, "Touchscreen IRQ");
if (ret)
goto out;
ret = gpio_direction_input(irq);
if (ret) {
gpio_free(irq);
goto out;
}
wm->pen_irq = gpio_to_irq(irq);
irq_set_irq_type(wm->pen_irq, IRQ_TYPE_EDGE_BOTH);
} else
pen_int = 0;
if (pen_int) {
switch (wm->id) {
case WM9705_ID2:
break;
case WM9712_ID2:
case WM9713_ID2:
wm97xx_config_gpio(wm, WM97XX_GPIO_13, WM97XX_GPIO_IN,
WM97XX_GPIO_POL_HIGH,
WM97XX_GPIO_STICKY,
WM97XX_GPIO_WAKE);
wm97xx_config_gpio(wm, WM97XX_GPIO_2, WM97XX_GPIO_OUT,
WM97XX_GPIO_POL_HIGH,
WM97XX_GPIO_NOTSTICKY,
WM97XX_GPIO_NOWAKE);
break;
default:
dev_err(wm->dev,
"pen down irq not supported on this device\n");
pen_int = 0;
break;
}
}
out:
return ret;
}
static void wm97xx_acc_shutdown(struct wm97xx *wm)
{
if (pen_int) {
if (irq)
gpio_free(irq);
wm->pen_irq = 0;
}
}
static void wm97xx_irq_enable(struct wm97xx *wm, int enable)
{
if (enable)
enable_irq(wm->pen_irq);
else
disable_irq_nosync(wm->pen_irq);
}
static int mainstone_wm97xx_probe(struct platform_device *pdev)
{
struct wm97xx *wm = platform_get_drvdata(pdev);
return wm97xx_register_mach_ops(wm, &mainstone_mach_ops);
}
static int mainstone_wm97xx_remove(struct platform_device *pdev)
{
struct wm97xx *wm = platform_get_drvdata(pdev);
wm97xx_unregister_mach_ops(wm);
return 0;
}
static int __init mainstone_wm97xx_init(void)
{
return platform_driver_register(&mainstone_wm97xx_driver);
}
static void __exit mainstone_wm97xx_exit(void)
{
platform_driver_unregister(&mainstone_wm97xx_driver);
}
