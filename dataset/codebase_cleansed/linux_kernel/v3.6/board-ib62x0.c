static void ib62x0_power_off(void)
{
gpio_set_value(IB62X0_GPIO_POWER_OFF, 1);
}
void __init ib62x0_init(void)
{
kirkwood_mpp_conf(ib62x0_mpp_config);
kirkwood_ehci_init();
kirkwood_ge00_init(&ib62x0_ge00_data);
if (gpio_request(IB62X0_GPIO_POWER_OFF, "ib62x0:power:off") == 0 &&
gpio_direction_output(IB62X0_GPIO_POWER_OFF, 0) == 0)
pm_power_off = ib62x0_power_off;
else
pr_err("board-ib62x0: failed to configure power-off GPIO\n");
}
