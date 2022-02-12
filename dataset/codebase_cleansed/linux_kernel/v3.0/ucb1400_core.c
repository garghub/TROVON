unsigned int ucb1400_adc_read(struct snd_ac97 *ac97, u16 adc_channel,
int adcsync)
{
unsigned int val;
if (adcsync)
adc_channel |= UCB_ADC_SYNC_ENA;
ucb1400_reg_write(ac97, UCB_ADC_CR, UCB_ADC_ENA | adc_channel);
ucb1400_reg_write(ac97, UCB_ADC_CR, UCB_ADC_ENA | adc_channel |
UCB_ADC_START);
while (!((val = ucb1400_reg_read(ac97, UCB_ADC_DATA))
& UCB_ADC_DAT_VALID))
schedule_timeout_uninterruptible(1);
return val & UCB_ADC_DAT_MASK;
}
static int ucb1400_core_probe(struct device *dev)
{
int err;
struct ucb1400 *ucb;
struct ucb1400_ts ucb_ts;
struct ucb1400_gpio ucb_gpio;
struct snd_ac97 *ac97;
struct ucb1400_pdata *pdata = dev->platform_data;
memset(&ucb_ts, 0, sizeof(ucb_ts));
memset(&ucb_gpio, 0, sizeof(ucb_gpio));
ucb = kzalloc(sizeof(struct ucb1400), GFP_KERNEL);
if (!ucb) {
err = -ENOMEM;
goto err;
}
dev_set_drvdata(dev, ucb);
ac97 = to_ac97_t(dev);
ucb_ts.id = ucb1400_reg_read(ac97, UCB_ID);
if (ucb_ts.id != UCB_ID_1400) {
err = -ENODEV;
goto err0;
}
ucb_gpio.ac97 = ac97;
ucb->ucb1400_gpio = platform_device_alloc("ucb1400_gpio", -1);
if (!ucb->ucb1400_gpio) {
err = -ENOMEM;
goto err0;
}
err = platform_device_add_data(ucb->ucb1400_gpio, &ucb_gpio,
sizeof(ucb_gpio));
if (err)
goto err1;
err = platform_device_add(ucb->ucb1400_gpio);
if (err)
goto err1;
ucb_ts.ac97 = ac97;
if (pdata != NULL && pdata->irq >= 0)
ucb_ts.irq = pdata->irq;
else
ucb_ts.irq = -1;
ucb->ucb1400_ts = platform_device_alloc("ucb1400_ts", -1);
if (!ucb->ucb1400_ts) {
err = -ENOMEM;
goto err2;
}
err = platform_device_add_data(ucb->ucb1400_ts, &ucb_ts,
sizeof(ucb_ts));
if (err)
goto err3;
err = platform_device_add(ucb->ucb1400_ts);
if (err)
goto err3;
return 0;
err3:
platform_device_put(ucb->ucb1400_ts);
err2:
platform_device_del(ucb->ucb1400_gpio);
err1:
platform_device_put(ucb->ucb1400_gpio);
err0:
kfree(ucb);
err:
return err;
}
static int ucb1400_core_remove(struct device *dev)
{
struct ucb1400 *ucb = dev_get_drvdata(dev);
platform_device_unregister(ucb->ucb1400_ts);
platform_device_unregister(ucb->ucb1400_gpio);
kfree(ucb);
return 0;
}
static int __init ucb1400_core_init(void)
{
return driver_register(&ucb1400_core_driver);
}
static void __exit ucb1400_core_exit(void)
{
driver_unregister(&ucb1400_core_driver);
}
