static int imx6q_enter_wait(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
if (atomic_inc_return(&master) == num_online_cpus()) {
if (!spin_trylock(&master_lock))
goto idle;
imx6_set_lpm(WAIT_UNCLOCKED);
cpu_do_idle();
imx6_set_lpm(WAIT_CLOCKED);
spin_unlock(&master_lock);
goto done;
}
idle:
cpu_do_idle();
done:
atomic_dec(&master);
return index;
}
void imx6q_cpuidle_fec_irqs_used(void)
{
imx6q_cpuidle_driver.states[1].disabled = true;
}
void imx6q_cpuidle_fec_irqs_unused(void)
{
imx6q_cpuidle_driver.states[1].disabled = false;
}
int __init imx6q_cpuidle_init(void)
{
imx6q_set_int_mem_clk_lpm(true);
return cpuidle_register(&imx6q_cpuidle_driver, NULL);
}
