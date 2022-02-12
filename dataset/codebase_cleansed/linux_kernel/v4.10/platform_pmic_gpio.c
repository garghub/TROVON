static void __init *pmic_gpio_platform_data(void *info)
{
static struct intel_pmic_gpio_platform_data pmic_gpio_pdata;
int gpio_base = get_gpio_by_name("pmic_gpio_base");
if (gpio_base < 0)
gpio_base = 64;
pmic_gpio_pdata.gpio_base = gpio_base;
pmic_gpio_pdata.irq_base = gpio_base + INTEL_MID_IRQ_OFFSET;
pmic_gpio_pdata.gpiointr = 0xffffeff8;
return &pmic_gpio_pdata;
}
