void ledtrig_cpu(enum cpu_led_event ledevt)
{
struct led_trigger_cpu *trig = this_cpu_ptr(&cpu_trig);
switch (ledevt) {
case CPU_LED_IDLE_END:
case CPU_LED_START:
led_trigger_event(trig->_trig, LED_FULL);
break;
case CPU_LED_IDLE_START:
case CPU_LED_STOP:
case CPU_LED_HALTED:
led_trigger_event(trig->_trig, LED_OFF);
break;
default:
break;
}
}
static int ledtrig_cpu_syscore_suspend(void)
{
ledtrig_cpu(CPU_LED_STOP);
return 0;
}
static void ledtrig_cpu_syscore_resume(void)
{
ledtrig_cpu(CPU_LED_START);
}
static void ledtrig_cpu_syscore_shutdown(void)
{
ledtrig_cpu(CPU_LED_HALTED);
}
static int ledtrig_online_cpu(unsigned int cpu)
{
ledtrig_cpu(CPU_LED_START);
return 0;
}
static int ledtrig_prepare_down_cpu(unsigned int cpu)
{
ledtrig_cpu(CPU_LED_STOP);
return 0;
}
static int __init ledtrig_cpu_init(void)
{
int cpu;
int ret;
BUILD_BUG_ON(CONFIG_NR_CPUS > 9999);
for_each_possible_cpu(cpu) {
struct led_trigger_cpu *trig = &per_cpu(cpu_trig, cpu);
snprintf(trig->name, MAX_NAME_LEN, "cpu%d", cpu);
led_trigger_register_simple(trig->name, &trig->_trig);
}
register_syscore_ops(&ledtrig_cpu_syscore_ops);
ret = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "AP_LEDTRIG_STARTING",
ledtrig_online_cpu, ledtrig_prepare_down_cpu);
if (ret < 0)
pr_err("CPU hotplug notifier for ledtrig-cpu could not be registered: %d\n",
ret);
pr_info("ledtrig-cpu: registered to indicate activity on CPUs\n");
return 0;
}
