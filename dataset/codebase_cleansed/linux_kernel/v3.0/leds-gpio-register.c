struct platform_device *__init gpio_led_register_device(
int id, const struct gpio_led_platform_data *pdata)
{
struct platform_device *ret;
struct gpio_led_platform_data _pdata = *pdata;
_pdata.leds = kmemdup(pdata->leds,
pdata->num_leds * sizeof(*pdata->leds), GFP_KERNEL);
if (!_pdata.leds)
return ERR_PTR(-ENOMEM);
ret = platform_device_register_resndata(NULL, "leds-gpio", id,
NULL, 0, &_pdata, sizeof(_pdata));
if (IS_ERR(ret))
kfree(_pdata.leds);
return ret;
}
