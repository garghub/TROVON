static void __init *msic_gpio_platform_data(void *info)
{
static struct intel_msic_gpio_pdata msic_gpio_pdata;
int gpio = get_gpio_by_name("msic_gpio_base");
if (gpio < 0)
return NULL;
msic_gpio_pdata.gpio_base = gpio;
msic_pdata.gpio = &msic_gpio_pdata;
return msic_generic_platform_data(info, INTEL_MSIC_BLOCK_GPIO);
}
