static void pcap_ts_read_xy(void *data, u16 res[2])
{
struct pcap_ts *pcap_ts = data;
switch (pcap_ts->read_state) {
case PCAP_ADC_TS_M_PRESSURE:
if (res[0] > PRESSURE_MIN && res[0] < PRESSURE_MAX)
pcap_ts->pressure = res[0];
pcap_ts->read_state = PCAP_ADC_TS_M_XY;
schedule_delayed_work(&pcap_ts->work, 0);
break;
case PCAP_ADC_TS_M_XY:
pcap_ts->y = res[0];
pcap_ts->x = res[1];
if (pcap_ts->x <= X_AXIS_MIN || pcap_ts->x >= X_AXIS_MAX ||
pcap_ts->y <= Y_AXIS_MIN || pcap_ts->y >= Y_AXIS_MAX) {
input_report_abs(pcap_ts->input, ABS_PRESSURE, 0);
input_report_key(pcap_ts->input, BTN_TOUCH, 0);
pcap_ts->read_state = PCAP_ADC_TS_M_STANDBY;
schedule_delayed_work(&pcap_ts->work, 0);
} else {
input_report_abs(pcap_ts->input, ABS_X, pcap_ts->x);
input_report_abs(pcap_ts->input, ABS_Y, pcap_ts->y);
input_report_key(pcap_ts->input, BTN_TOUCH, 1);
input_report_abs(pcap_ts->input, ABS_PRESSURE,
pcap_ts->pressure);
pcap_ts->read_state = PCAP_ADC_TS_M_PRESSURE;
schedule_delayed_work(&pcap_ts->work,
msecs_to_jiffies(SAMPLE_DELAY));
}
input_sync(pcap_ts->input);
break;
default:
dev_warn(&pcap_ts->input->dev,
"pcap_ts: Warning, unhandled read_state %d\n",
pcap_ts->read_state);
break;
}
}
static void pcap_ts_work(struct work_struct *work)
{
struct delayed_work *dw = container_of(work, struct delayed_work, work);
struct pcap_ts *pcap_ts = container_of(dw, struct pcap_ts, work);
u8 ch[2];
pcap_set_ts_bits(pcap_ts->pcap,
pcap_ts->read_state << PCAP_ADC_TS_M_SHIFT);
if (pcap_ts->read_state == PCAP_ADC_TS_M_STANDBY)
return;
ch[0] = PCAP_ADC_CH_TS_X1;
ch[1] = PCAP_ADC_CH_TS_Y1;
pcap_adc_async(pcap_ts->pcap, PCAP_ADC_BANK_1, 0, ch,
pcap_ts_read_xy, pcap_ts);
}
static irqreturn_t pcap_ts_event_touch(int pirq, void *data)
{
struct pcap_ts *pcap_ts = data;
if (pcap_ts->read_state == PCAP_ADC_TS_M_STANDBY) {
pcap_ts->read_state = PCAP_ADC_TS_M_PRESSURE;
schedule_delayed_work(&pcap_ts->work, 0);
}
return IRQ_HANDLED;
}
static int pcap_ts_open(struct input_dev *dev)
{
struct pcap_ts *pcap_ts = input_get_drvdata(dev);
pcap_ts->read_state = PCAP_ADC_TS_M_STANDBY;
schedule_delayed_work(&pcap_ts->work, 0);
return 0;
}
static void pcap_ts_close(struct input_dev *dev)
{
struct pcap_ts *pcap_ts = input_get_drvdata(dev);
cancel_delayed_work_sync(&pcap_ts->work);
pcap_ts->read_state = PCAP_ADC_TS_M_NONTS;
pcap_set_ts_bits(pcap_ts->pcap,
pcap_ts->read_state << PCAP_ADC_TS_M_SHIFT);
}
static int __devinit pcap_ts_probe(struct platform_device *pdev)
{
struct input_dev *input_dev;
struct pcap_ts *pcap_ts;
int err = -ENOMEM;
pcap_ts = kzalloc(sizeof(*pcap_ts), GFP_KERNEL);
if (!pcap_ts)
return err;
pcap_ts->pcap = dev_get_drvdata(pdev->dev.parent);
platform_set_drvdata(pdev, pcap_ts);
input_dev = input_allocate_device();
if (!input_dev)
goto fail;
INIT_DELAYED_WORK(&pcap_ts->work, pcap_ts_work);
pcap_ts->read_state = PCAP_ADC_TS_M_NONTS;
pcap_set_ts_bits(pcap_ts->pcap,
pcap_ts->read_state << PCAP_ADC_TS_M_SHIFT);
pcap_ts->input = input_dev;
input_set_drvdata(input_dev, pcap_ts);
input_dev->name = "pcap-touchscreen";
input_dev->phys = "pcap_ts/input0";
input_dev->id.bustype = BUS_HOST;
input_dev->id.vendor = 0x0001;
input_dev->id.product = 0x0002;
input_dev->id.version = 0x0100;
input_dev->dev.parent = &pdev->dev;
input_dev->open = pcap_ts_open;
input_dev->close = pcap_ts_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input_dev, ABS_X, X_AXIS_MIN, X_AXIS_MAX, 0, 0);
input_set_abs_params(input_dev, ABS_Y, Y_AXIS_MIN, Y_AXIS_MAX, 0, 0);
input_set_abs_params(input_dev, ABS_PRESSURE, PRESSURE_MIN,
PRESSURE_MAX, 0, 0);
err = input_register_device(pcap_ts->input);
if (err)
goto fail_allocate;
err = request_irq(pcap_to_irq(pcap_ts->pcap, PCAP_IRQ_TS),
pcap_ts_event_touch, 0, "Touch Screen", pcap_ts);
if (err)
goto fail_register;
return 0;
fail_register:
input_unregister_device(input_dev);
goto fail;
fail_allocate:
input_free_device(input_dev);
fail:
kfree(pcap_ts);
return err;
}
static int __devexit pcap_ts_remove(struct platform_device *pdev)
{
struct pcap_ts *pcap_ts = platform_get_drvdata(pdev);
free_irq(pcap_to_irq(pcap_ts->pcap, PCAP_IRQ_TS), pcap_ts);
cancel_delayed_work_sync(&pcap_ts->work);
input_unregister_device(pcap_ts->input);
kfree(pcap_ts);
return 0;
}
static int pcap_ts_suspend(struct device *dev)
{
struct pcap_ts *pcap_ts = dev_get_drvdata(dev);
pcap_set_ts_bits(pcap_ts->pcap, PCAP_ADC_TS_REF_LOWPWR);
return 0;
}
static int pcap_ts_resume(struct device *dev)
{
struct pcap_ts *pcap_ts = dev_get_drvdata(dev);
pcap_set_ts_bits(pcap_ts->pcap,
pcap_ts->read_state << PCAP_ADC_TS_M_SHIFT);
return 0;
}
static int __init pcap_ts_init(void)
{
return platform_driver_register(&pcap_ts_driver);
}
static void __exit pcap_ts_exit(void)
{
platform_driver_unregister(&pcap_ts_driver);
}
