static void wm97xx_acc_pen_up(struct wm97xx *wm)
{
int i;
msleep(1);
for (i = 0; i < 16; i++)
MODR;
}
static int wm97xx_acc_pen_down(struct wm97xx *wm)
{
u16 x, y, p = 0x100 | WM97XX_ADCSEL_PRES;
int reads = 0;
static u16 last, tries;
msleep(1);
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
if ((x & WM97XX_ADCSEL_MASK) != WM97XX_ADCSEL_X ||
(y & WM97XX_ADCSEL_MASK) != WM97XX_ADCSEL_Y ||
(p & WM97XX_ADCSEL_MASK) != WM97XX_ADCSEL_PRES)
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
int idx;
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
"zylonite accelerated touchscreen driver, %d samples/sec\n",
cinfo[sp_idx].speed);
return 0;
}
static void wm97xx_irq_enable(struct wm97xx *wm, int enable)
{
if (enable)
enable_irq(wm->pen_irq);
else
disable_irq_nosync(wm->pen_irq);
}
static int zylonite_wm97xx_probe(struct platform_device *pdev)
{
struct wm97xx *wm = platform_get_drvdata(pdev);
int gpio_touch_irq;
if (cpu_is_pxa320())
gpio_touch_irq = mfp_to_gpio(MFP_PIN_GPIO15);
else
gpio_touch_irq = mfp_to_gpio(MFP_PIN_GPIO26);
wm->pen_irq = IRQ_GPIO(gpio_touch_irq);
irq_set_irq_type(IRQ_GPIO(gpio_touch_irq), IRQ_TYPE_EDGE_BOTH);
wm97xx_config_gpio(wm, WM97XX_GPIO_13, WM97XX_GPIO_IN,
WM97XX_GPIO_POL_HIGH,
WM97XX_GPIO_STICKY,
WM97XX_GPIO_WAKE);
wm97xx_config_gpio(wm, WM97XX_GPIO_2, WM97XX_GPIO_OUT,
WM97XX_GPIO_POL_HIGH,
WM97XX_GPIO_NOTSTICKY,
WM97XX_GPIO_NOWAKE);
return wm97xx_register_mach_ops(wm, &zylonite_mach_ops);
}
static int zylonite_wm97xx_remove(struct platform_device *pdev)
{
struct wm97xx *wm = platform_get_drvdata(pdev);
wm97xx_unregister_mach_ops(wm);
return 0;
}
static int __init zylonite_wm97xx_init(void)
{
return platform_driver_register(&zylonite_wm97xx_driver);
}
static void __exit zylonite_wm97xx_exit(void)
{
platform_driver_unregister(&zylonite_wm97xx_driver);
}
