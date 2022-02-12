static irqreturn_t atmel_wm97xx_channel_b_interrupt(int irq, void *dev_id)
{
struct atmel_wm97xx *atmel_wm97xx = dev_id;
struct wm97xx *wm = atmel_wm97xx->wm;
int status = ac97c_readl(atmel_wm97xx, CBSR);
irqreturn_t retval = IRQ_NONE;
if (status & AC97C_OVRUN) {
dev_dbg(&wm->touch_dev->dev, "AC97C overrun\n");
ac97c_readl(atmel_wm97xx, CBRHR);
retval = IRQ_HANDLED;
} else if (status & AC97C_RXRDY) {
u16 data;
u16 value;
u16 source;
u16 pen_down;
data = ac97c_readl(atmel_wm97xx, CBRHR);
value = data & 0x0fff;
source = data & WM97XX_ADCSEL_MASK;
pen_down = (data & WM97XX_PEN_DOWN) >> 8;
if (source == WM97XX_ADCSEL_X)
atmel_wm97xx->x = value;
if (source == WM97XX_ADCSEL_Y)
atmel_wm97xx->y = value;
if (!pressure && source == WM97XX_ADCSEL_Y) {
input_report_abs(wm->input_dev, ABS_X, atmel_wm97xx->x);
input_report_abs(wm->input_dev, ABS_Y, atmel_wm97xx->y);
input_report_key(wm->input_dev, BTN_TOUCH, pen_down);
input_sync(wm->input_dev);
} else if (pressure && source == WM97XX_ADCSEL_PRES) {
input_report_abs(wm->input_dev, ABS_X, atmel_wm97xx->x);
input_report_abs(wm->input_dev, ABS_Y, atmel_wm97xx->y);
input_report_abs(wm->input_dev, ABS_PRESSURE, value);
input_report_key(wm->input_dev, BTN_TOUCH, value);
input_sync(wm->input_dev);
}
retval = IRQ_HANDLED;
}
return retval;
}
static void atmel_wm97xx_acc_pen_up(struct wm97xx *wm)
{
struct atmel_wm97xx *atmel_wm97xx = platform_get_drvdata(wm->touch_dev);
struct input_dev *input_dev = wm->input_dev;
int pen_down = gpio_get_value(atmel_wm97xx->gpio_pen);
if (pen_down != 0) {
mod_timer(&atmel_wm97xx->pen_timer,
jiffies + msecs_to_jiffies(1));
} else {
if (pressure)
input_report_abs(input_dev, ABS_PRESSURE, 0);
input_report_key(input_dev, BTN_TOUCH, 0);
input_sync(input_dev);
}
}
static void atmel_wm97xx_pen_timer(unsigned long data)
{
atmel_wm97xx_acc_pen_up((struct wm97xx *)data);
}
static int atmel_wm97xx_acc_startup(struct wm97xx *wm)
{
struct atmel_wm97xx *atmel_wm97xx = platform_get_drvdata(wm->touch_dev);
int idx = 0;
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
dev_info(&wm->touch_dev->dev, "atmel accelerated touchscreen driver, "
"%d samples/sec\n", cinfo[sp_idx].speed);
if (pen_int) {
unsigned long reg;
wm->pen_irq = atmel_wm97xx->gpio_irq;
switch (wm->id) {
case WM9712_ID2:
case WM9713_ID2:
wm97xx_config_gpio(wm, WM97XX_GPIO_13, WM97XX_GPIO_IN,
WM97XX_GPIO_POL_HIGH,
WM97XX_GPIO_STICKY,
WM97XX_GPIO_WAKE);
wm97xx_config_gpio(wm, WM97XX_GPIO_3, WM97XX_GPIO_OUT,
WM97XX_GPIO_POL_HIGH,
WM97XX_GPIO_NOTSTICKY,
WM97XX_GPIO_NOWAKE);
case WM9705_ID2:
reg = ac97c_readl(atmel_wm97xx, ICA);
reg &= ~AC97C_CH_MASK(wm->acc_slot);
reg |= AC97C_CH_ASSIGN(wm->acc_slot, B);
ac97c_writel(atmel_wm97xx, ICA, reg);
ac97c_writel(atmel_wm97xx, CBMR, AC97C_CMR_CENA
| AC97C_CMR_CEM_BIG
| AC97C_CMR_SIZE_16
| AC97C_OVRUN
| AC97C_RXRDY);
ac97c_readl(atmel_wm97xx, CBRHR);
ac97c_writel(atmel_wm97xx, IER, AC97C_INT_CBEVT);
break;
default:
dev_err(&wm->touch_dev->dev, "pen down irq not "
"supported on this device\n");
pen_int = 0;
break;
}
}
return 0;
}
static void atmel_wm97xx_acc_shutdown(struct wm97xx *wm)
{
if (pen_int) {
struct atmel_wm97xx *atmel_wm97xx =
platform_get_drvdata(wm->touch_dev);
unsigned long ica;
switch (wm->id & 0xffff) {
case WM9705_ID2:
case WM9712_ID2:
case WM9713_ID2:
ica = ac97c_readl(atmel_wm97xx, ICA);
ica &= ~AC97C_CH_MASK(wm->acc_slot);
ac97c_writel(atmel_wm97xx, ICA, ica);
ac97c_writel(atmel_wm97xx, IDR, AC97C_INT_CBEVT);
ac97c_writel(atmel_wm97xx, CBMR, 0);
wm->pen_irq = 0;
break;
default:
dev_err(&wm->touch_dev->dev, "unknown codec\n");
break;
}
}
}
static void atmel_wm97xx_irq_enable(struct wm97xx *wm, int enable)
{
}
static int __init atmel_wm97xx_probe(struct platform_device *pdev)
{
struct wm97xx *wm = platform_get_drvdata(pdev);
struct atmel_wm97xx *atmel_wm97xx;
int ret;
atmel_wm97xx = kzalloc(sizeof(struct atmel_wm97xx), GFP_KERNEL);
if (!atmel_wm97xx)
return -ENOMEM;
atmel_wm97xx->wm = wm;
atmel_wm97xx->regs = (void *)ATMEL_WM97XX_AC97C_IOMEM;
atmel_wm97xx->ac97c_irq = ATMEL_WM97XX_AC97C_IRQ;
atmel_wm97xx->gpio_pen = atmel_gpio_line;
atmel_wm97xx->gpio_irq = gpio_to_irq(atmel_wm97xx->gpio_pen);
setup_timer(&atmel_wm97xx->pen_timer, atmel_wm97xx_pen_timer,
(unsigned long)wm);
ret = request_irq(atmel_wm97xx->ac97c_irq,
atmel_wm97xx_channel_b_interrupt,
IRQF_SHARED, "atmel-wm97xx-ch-b", atmel_wm97xx);
if (ret) {
dev_dbg(&pdev->dev, "could not request ac97c irq\n");
goto err;
}
platform_set_drvdata(pdev, atmel_wm97xx);
ret = wm97xx_register_mach_ops(wm, &atmel_mach_ops);
if (ret)
goto err_irq;
return ret;
err_irq:
free_irq(atmel_wm97xx->ac97c_irq, atmel_wm97xx);
err:
kfree(atmel_wm97xx);
return ret;
}
static int __exit atmel_wm97xx_remove(struct platform_device *pdev)
{
struct atmel_wm97xx *atmel_wm97xx = platform_get_drvdata(pdev);
struct wm97xx *wm = atmel_wm97xx->wm;
ac97c_writel(atmel_wm97xx, IDR, AC97C_INT_CBEVT);
free_irq(atmel_wm97xx->ac97c_irq, atmel_wm97xx);
del_timer_sync(&atmel_wm97xx->pen_timer);
wm97xx_unregister_mach_ops(wm);
kfree(atmel_wm97xx);
return 0;
}
static int atmel_wm97xx_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct atmel_wm97xx *atmel_wm97xx = platform_get_drvdata(pdev);
ac97c_writel(atmel_wm97xx, IDR, AC97C_INT_CBEVT);
disable_irq(atmel_wm97xx->gpio_irq);
del_timer_sync(&atmel_wm97xx->pen_timer);
return 0;
}
static int atmel_wm97xx_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct atmel_wm97xx *atmel_wm97xx = platform_get_drvdata(pdev);
struct wm97xx *wm = atmel_wm97xx->wm;
if (wm->input_dev->users) {
enable_irq(atmel_wm97xx->gpio_irq);
ac97c_writel(atmel_wm97xx, IER, AC97C_INT_CBEVT);
}
return 0;
}
