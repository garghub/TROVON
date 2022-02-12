static int imx6sl_enter_wait(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
imx6q_set_lpm(WAIT_UNCLOCKED);
imx6sl_set_wait_clk(true);
cpu_do_idle();
imx6sl_set_wait_clk(false);
imx6q_set_lpm(WAIT_CLOCKED);
return index;
}
int __init imx6sl_cpuidle_init(void)
{
return cpuidle_register(&imx6sl_cpuidle_driver, NULL);
}
