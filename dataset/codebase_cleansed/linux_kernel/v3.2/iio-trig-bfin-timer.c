static ssize_t iio_bfin_tmr_frequency_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct iio_trigger *trig = dev_get_drvdata(dev);
struct bfin_tmr_state *st = trig->private_data;
long val;
int ret;
ret = strict_strtoul(buf, 10, &val);
if (ret)
goto error_ret;
if (val > 100000) {
ret = -EINVAL;
goto error_ret;
}
disable_gptimers(st->t->bit);
if (!val)
goto error_ret;
val = get_sclk() / val;
if (val <= 4) {
ret = -EINVAL;
goto error_ret;
}
set_gptimer_period(st->t->id, val);
set_gptimer_pwidth(st->t->id, 1);
enable_gptimers(st->t->bit);
error_ret:
return ret ? ret : count;
}
static ssize_t iio_bfin_tmr_frequency_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_trigger *trig = dev_get_drvdata(dev);
struct bfin_tmr_state *st = trig->private_data;
return sprintf(buf, "%lu\n",
get_sclk() / get_gptimer_period(st->t->id));
}
static irqreturn_t iio_bfin_tmr_trigger_isr(int irq, void *devid)
{
struct bfin_tmr_state *st = devid;
clear_gptimer_intr(st->t->id);
iio_trigger_poll(st->trig, 0);
return IRQ_HANDLED;
}
static int iio_bfin_tmr_get_number(int irq)
{
int i;
for (i = 0; i < MAX_BLACKFIN_GPTIMERS; i++)
if (iio_bfin_timer_code[i].irq == irq)
return i;
return -ENODEV;
}
static int __devinit iio_bfin_tmr_trigger_probe(struct platform_device *pdev)
{
struct bfin_tmr_state *st;
int ret;
st = kzalloc(sizeof(*st), GFP_KERNEL);
if (st == NULL) {
ret = -ENOMEM;
goto out;
}
st->irq = platform_get_irq(pdev, 0);
if (!st->irq) {
dev_err(&pdev->dev, "No IRQs specified");
ret = -ENODEV;
goto out1;
}
ret = iio_bfin_tmr_get_number(st->irq);
if (ret < 0)
goto out1;
st->timer_num = ret;
st->t = &iio_bfin_timer_code[st->timer_num];
st->trig = iio_allocate_trigger("bfintmr%d", st->timer_num);
if (!st->trig) {
ret = -ENOMEM;
goto out1;
}
st->trig->private_data = st;
st->trig->ops = &iio_bfin_tmr_trigger_ops;
st->trig->dev.groups = iio_bfin_tmr_trigger_attr_groups;
ret = iio_trigger_register(st->trig);
if (ret)
goto out2;
ret = request_irq(st->irq, iio_bfin_tmr_trigger_isr,
0, st->trig->name, st);
if (ret) {
dev_err(&pdev->dev,
"request IRQ-%d failed", st->irq);
goto out4;
}
set_gptimer_config(st->t->id, OUT_DIS | PWM_OUT | PERIOD_CNT | IRQ_ENA);
dev_info(&pdev->dev, "iio trigger Blackfin TMR%d, IRQ-%d",
st->timer_num, st->irq);
platform_set_drvdata(pdev, st);
return 0;
out4:
iio_trigger_unregister(st->trig);
out2:
iio_put_trigger(st->trig);
out1:
kfree(st);
out:
return ret;
}
static int __devexit iio_bfin_tmr_trigger_remove(struct platform_device *pdev)
{
struct bfin_tmr_state *st = platform_get_drvdata(pdev);
disable_gptimers(st->t->bit);
free_irq(st->irq, st);
iio_trigger_unregister(st->trig);
iio_put_trigger(st->trig);
kfree(st);
return 0;
}
static int __init iio_bfin_tmr_trig_init(void)
{
return platform_driver_register(&iio_bfin_tmr_trigger_driver);
}
static void __exit iio_bfin_tmr_trig_exit(void)
{
platform_driver_unregister(&iio_bfin_tmr_trigger_driver);
}
