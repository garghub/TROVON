static int imx6q_enter_wait(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
int cpu = dev->cpu;
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ENTER, &cpu);
if (atomic_inc_return(&master) == num_online_cpus()) {
if (!spin_trylock(&master_lock))
goto idle;
imx6q_set_lpm(WAIT_UNCLOCKED);
cpu_do_idle();
imx6q_set_lpm(WAIT_CLOCKED);
spin_unlock(&master_lock);
goto done;
}
idle:
cpu_do_idle();
done:
atomic_dec(&master);
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_EXIT, &cpu);
return index;
}
static void imx6q_setup_broadcast_timer(void *arg)
{
int cpu = smp_processor_id();
clockevents_notify(CLOCK_EVT_NOTIFY_BROADCAST_ON, &cpu);
}
int __init imx6q_cpuidle_init(void)
{
imx_scu_standby_enable();
imx6q_set_chicken_bit();
on_each_cpu(imx6q_setup_broadcast_timer, NULL, 1);
return imx_cpuidle_init(&imx6q_cpuidle_driver);
}
