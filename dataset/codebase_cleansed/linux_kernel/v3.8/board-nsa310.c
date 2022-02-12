static void nsa310_power_off(void)
{
gpio_set_value(NSA310_GPIO_POWER_OFF, 1);
}
static int __init nsa310_gpio_request(unsigned int gpio, unsigned long flags,
const char *label)
{
int err;
err = gpio_request_one(gpio, flags, label);
if (err)
pr_err("NSA-310: can't setup GPIO%u (%s), err=%d\n",
gpio, label, err);
return err;
}
static void __init nsa310_gpio_init(void)
{
int err;
err = nsa310_gpio_request(NSA310_GPIO_POWER_OFF, GPIOF_OUT_INIT_LOW,
"Power Off");
if (!err)
pm_power_off = nsa310_power_off;
nsa310_gpio_request(NSA310_GPIO_USB_POWER_OFF, GPIOF_OUT_INIT_LOW,
"USB Power Off");
}
void __init nsa310_init(void)
{
u32 dev, rev;
kirkwood_mpp_conf(nsa310_mpp_config);
nsa310_gpio_init();
kirkwood_pcie_id(&dev, &rev);
i2c_register_board_info(0, ARRAY_AND_SIZE(nsa310_i2c_info));
}
static int __init nsa310_pci_init(void)
{
if (of_machine_is_compatible("zyxel,nsa310"))
kirkwood_pcie_init(KW_PCIE0);
return 0;
}
