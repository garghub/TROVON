static void w90p910_report_event(struct w90p910_ts *w90p910_ts, bool down)
{
struct input_dev *dev = w90p910_ts->input;
if (down) {
input_report_abs(dev, ABS_X,
__raw_readl(w90p910_ts->ts_reg + 0x0c));
input_report_abs(dev, ABS_Y,
__raw_readl(w90p910_ts->ts_reg + 0x10));
}
input_report_key(dev, BTN_TOUCH, down);
input_sync(dev);
}
static void w90p910_prepare_x_reading(struct w90p910_ts *w90p910_ts)
{
unsigned long ctlreg;
__raw_writel(ADC_TSC_X, w90p910_ts->ts_reg + 0x04);
ctlreg = __raw_readl(w90p910_ts->ts_reg);
ctlreg &= ~(ADC_WAITTRIG | WT_INT | WT_INT_EN);
ctlreg |= ADC_SEMIAUTO | ADC_INT_EN | ADC_CONV;
__raw_writel(ctlreg, w90p910_ts->ts_reg);
w90p910_ts->state = TS_WAIT_X_COORD;
}
static void w90p910_prepare_y_reading(struct w90p910_ts *w90p910_ts)
{
unsigned long ctlreg;
__raw_writel(ADC_TSC_Y, w90p910_ts->ts_reg + 0x04);
ctlreg = __raw_readl(w90p910_ts->ts_reg);
ctlreg &= ~(ADC_WAITTRIG | ADC_INT | WT_INT_EN);
ctlreg |= ADC_SEMIAUTO | ADC_INT_EN | ADC_CONV;
__raw_writel(ctlreg, w90p910_ts->ts_reg);
w90p910_ts->state = TS_WAIT_Y_COORD;
}
static void w90p910_prepare_next_packet(struct w90p910_ts *w90p910_ts)
{
unsigned long ctlreg;
ctlreg = __raw_readl(w90p910_ts->ts_reg);
ctlreg &= ~(ADC_INT | ADC_INT_EN | ADC_SEMIAUTO | ADC_CONV);
ctlreg |= ADC_WAITTRIG | WT_INT_EN;
__raw_writel(ctlreg, w90p910_ts->ts_reg);
w90p910_ts->state = TS_WAIT_NEW_PACKET;
}
static irqreturn_t w90p910_ts_interrupt(int irq, void *dev_id)
{
struct w90p910_ts *w90p910_ts = dev_id;
unsigned long flags;
spin_lock_irqsave(&w90p910_ts->lock, flags);
switch (w90p910_ts->state) {
case TS_WAIT_NEW_PACKET:
del_timer(&w90p910_ts->timer);
w90p910_prepare_x_reading(w90p910_ts);
break;
case TS_WAIT_X_COORD:
w90p910_prepare_y_reading(w90p910_ts);
break;
case TS_WAIT_Y_COORD:
w90p910_report_event(w90p910_ts, true);
w90p910_prepare_next_packet(w90p910_ts);
mod_timer(&w90p910_ts->timer, jiffies + msecs_to_jiffies(100));
break;
case TS_IDLE:
break;
}
spin_unlock_irqrestore(&w90p910_ts->lock, flags);
return IRQ_HANDLED;
}
static void w90p910_check_pen_up(unsigned long data)
{
struct w90p910_ts *w90p910_ts = (struct w90p910_ts *) data;
unsigned long flags;
spin_lock_irqsave(&w90p910_ts->lock, flags);
if (w90p910_ts->state == TS_WAIT_NEW_PACKET &&
!(__raw_readl(w90p910_ts->ts_reg + 0x04) & ADC_DOWN)) {
w90p910_report_event(w90p910_ts, false);
}
spin_unlock_irqrestore(&w90p910_ts->lock, flags);
}
static int w90p910_open(struct input_dev *dev)
{
struct w90p910_ts *w90p910_ts = input_get_drvdata(dev);
unsigned long val;
clk_enable(w90p910_ts->clk);
__raw_writel(ADC_RST1, w90p910_ts->ts_reg);
msleep(1);
__raw_writel(ADC_RST0, w90p910_ts->ts_reg);
msleep(1);
val = __raw_readl(w90p910_ts->ts_reg + 0x04);
__raw_writel(val & TSC_FOURWIRE, w90p910_ts->ts_reg + 0x04);
__raw_writel(ADC_DELAY, w90p910_ts->ts_reg + 0x08);
w90p910_ts->state = TS_WAIT_NEW_PACKET;
wmb();
val = __raw_readl(w90p910_ts->ts_reg);
val |= ADC_WAITTRIG | ADC_DIV | ADC_EN | WT_INT_EN;
__raw_writel(val, w90p910_ts->ts_reg);
return 0;
}
static void w90p910_close(struct input_dev *dev)
{
struct w90p910_ts *w90p910_ts = input_get_drvdata(dev);
unsigned long val;
spin_lock_irq(&w90p910_ts->lock);
w90p910_ts->state = TS_IDLE;
val = __raw_readl(w90p910_ts->ts_reg);
val &= ~(ADC_WAITTRIG | ADC_DIV | ADC_EN | WT_INT_EN | ADC_INT_EN);
__raw_writel(val, w90p910_ts->ts_reg);
spin_unlock_irq(&w90p910_ts->lock);
del_timer_sync(&w90p910_ts->timer);
clk_disable(w90p910_ts->clk);
}
static int __devinit w90x900ts_probe(struct platform_device *pdev)
{
struct w90p910_ts *w90p910_ts;
struct input_dev *input_dev;
struct resource *res;
int err;
w90p910_ts = kzalloc(sizeof(struct w90p910_ts), GFP_KERNEL);
input_dev = input_allocate_device();
if (!w90p910_ts || !input_dev) {
err = -ENOMEM;
goto fail1;
}
w90p910_ts->input = input_dev;
w90p910_ts->state = TS_IDLE;
spin_lock_init(&w90p910_ts->lock);
setup_timer(&w90p910_ts->timer, w90p910_check_pen_up,
(unsigned long)w90p910_ts);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
err = -ENXIO;
goto fail1;
}
if (!request_mem_region(res->start, resource_size(res),
pdev->name)) {
err = -EBUSY;
goto fail1;
}
w90p910_ts->ts_reg = ioremap(res->start, resource_size(res));
if (!w90p910_ts->ts_reg) {
err = -ENOMEM;
goto fail2;
}
w90p910_ts->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(w90p910_ts->clk)) {
err = PTR_ERR(w90p910_ts->clk);
goto fail3;
}
input_dev->name = "W90P910 TouchScreen";
input_dev->phys = "w90p910ts/event0";
input_dev->id.bustype = BUS_HOST;
input_dev->id.vendor = 0x0005;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &pdev->dev;
input_dev->open = w90p910_open;
input_dev->close = w90p910_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, 0, 0x400, 0, 0);
input_set_abs_params(input_dev, ABS_Y, 0, 0x400, 0, 0);
input_set_drvdata(input_dev, w90p910_ts);
w90p910_ts->irq_num = platform_get_irq(pdev, 0);
if (request_irq(w90p910_ts->irq_num, w90p910_ts_interrupt,
IRQF_DISABLED, "w90p910ts", w90p910_ts)) {
err = -EBUSY;
goto fail4;
}
err = input_register_device(w90p910_ts->input);
if (err)
goto fail5;
platform_set_drvdata(pdev, w90p910_ts);
return 0;
fail5: free_irq(w90p910_ts->irq_num, w90p910_ts);
fail4: clk_put(w90p910_ts->clk);
fail3: iounmap(w90p910_ts->ts_reg);
fail2: release_mem_region(res->start, resource_size(res));
fail1: input_free_device(input_dev);
kfree(w90p910_ts);
return err;
}
static int __devexit w90x900ts_remove(struct platform_device *pdev)
{
struct w90p910_ts *w90p910_ts = platform_get_drvdata(pdev);
struct resource *res;
free_irq(w90p910_ts->irq_num, w90p910_ts);
del_timer_sync(&w90p910_ts->timer);
iounmap(w90p910_ts->ts_reg);
clk_put(w90p910_ts->clk);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
input_unregister_device(w90p910_ts->input);
kfree(w90p910_ts);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init w90x900ts_init(void)
{
return platform_driver_register(&w90x900ts_driver);
}
static void __exit w90x900ts_exit(void)
{
platform_driver_unregister(&w90x900ts_driver);
}
