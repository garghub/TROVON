static void ns2_power_off(void)
{
gpio_set_value(NS2_GPIO_POWER_OFF, 1);
}
void __init ns2_init(void)
{
if (of_machine_is_compatible("lacie,netspace_lite_v2") ||
of_machine_is_compatible("lacie,netspace_mini_v2"))
ns2_ge00_data.phy_addr = MV643XX_ETH_PHY_ADDR(0);
kirkwood_ge00_init(&ns2_ge00_data);
if (gpio_request(NS2_GPIO_POWER_OFF, "power-off") == 0 &&
gpio_direction_output(NS2_GPIO_POWER_OFF, 0) == 0)
pm_power_off = ns2_power_off;
else
pr_err("ns2: failed to configure power-off GPIO\n");
}
