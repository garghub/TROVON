static void __init *msic_ocd_platform_data(void *info)
{
static struct intel_msic_ocd_pdata msic_ocd_pdata;
int gpio;
gpio = get_gpio_by_name("ocd_gpio");
if (gpio < 0)
return NULL;
msic_ocd_pdata.gpio = gpio;
msic_pdata.ocd = &msic_ocd_pdata;
return msic_generic_platform_data(info, INTEL_MSIC_BLOCK_OCD);
}
