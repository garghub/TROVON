static void do_poweroff(struct work_struct *dummy)
{
kernel_power_off();
}
static void handle_poweroff(int key)
{
schedule_work_on(cpumask_first(cpu_online_mask), &poweroff_work);
}
static int __init pm_sysrq_init(void)
{
register_sysrq_key('o', &sysrq_poweroff_op);
return 0;
}
