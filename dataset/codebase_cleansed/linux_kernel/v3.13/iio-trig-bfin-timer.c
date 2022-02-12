static int iio_bfin_tmr_set_state(struct iio_trigger *trig, bool state)
{
struct bfin_tmr_state *st = iio_trigger_get_drvdata(trig);
if (get_gptimer_period(st->t->id) == 0)
return -EINVAL;
if (state)
enable_gptimers(st->t->bit);
else
disable_gptimers(st->t->bit);
return 0;
}
static ssize_t iio_bfin_tmr_frequency_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct iio_trigger *trig = to_iio_trigger(dev);
struct bfin_tmr_state *st = iio_trigger_get_drvdata(trig);
unsigned int val;
bool enabled;
int ret;
ret = kstrtouint(buf, 10, &val);
if (ret)
return ret;
if (val > 100000)
return -EINVAL;
enabled = get_enabled_gptimers() & st->t->bit;
if (enabled)
disable_gptimers(st->t->bit);
if (val == 0)
return count;
val = get_sclk() / val;
if (val <= 4 || val <= st->duty)
return -EINVAL;
set_gptimer_period(st->t->id, val);
set_gptimer_pwidth(st->t->id, val - st->duty);
if (enabled)
enable_gptimers(st->t->bit);
return count;
}
static ssize_t iio_bfin_tmr_frequency_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_trigger *trig = to_iio_trigger(dev);
struct bfin_tmr_state *st = iio_trigger_get_drvdata(trig);
unsigned int period = get_gptimer_period(st->t->id);
unsigned long val;
if (period == 0)
val = 0;
else
val = get_sclk() / get_gptimer_period(st->t->id);
return sprintf(buf, "%lu\n", val);
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
static int iio_bfin_tmr_trigger_probe(struct platform_device *pdev)
{
struct iio_bfin_timer_trigger_pdata *pdata = pdev->dev.platform_data;
struct bfin_tmr_state *st;
unsigned int config;
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
st->trig = iio_trigger_alloc("bfintmr%d", st->timer_num);
if (!st->trig) {
ret = -ENOMEM;
goto out1;
}
st->trig->ops = &iio_bfin_tmr_trigger_ops;
st->trig->dev.groups = iio_bfin_tmr_trigger_attr_groups;
iio_trigger_set_drvdata(st->trig, st);
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
config = PWM_OUT | PERIOD_CNT | IRQ_ENA;
if (pdata && pdata->output_enable) {
unsigned long long val;
st->output_enable = true;
ret = peripheral_request(st->t->pin, st->trig->name);
if (ret)
goto out_free_irq;
val = (unsigned long long)get_sclk() * pdata->duty_ns;
do_div(val, NSEC_PER_SEC);
st->duty = val;
if (pdata->active_low)
config |= PULSE_HI;
} else {
st->duty = 1;
config |= OUT_DIS;
}
set_gptimer_config(st->t->id, config);
dev_info(&pdev->dev, "iio trigger Blackfin TMR%d, IRQ-%d",
st->timer_num, st->irq);
platform_set_drvdata(pdev, st);
return 0;
out_free_irq:
free_irq(st->irq, st);
out4:
iio_trigger_unregister(st->trig);
out2:
iio_trigger_put(st->trig);
out1:
kfree(st);
out:
return ret;
}
static int iio_bfin_tmr_trigger_remove(struct platform_device *pdev)
{
struct bfin_tmr_state *st = platform_get_drvdata(pdev);
disable_gptimers(st->t->bit);
if (st->output_enable)
peripheral_free(st->t->pin);
free_irq(st->irq, st);
iio_trigger_unregister(st->trig);
iio_trigger_put(st->trig);
kfree(st);
return 0;
}
