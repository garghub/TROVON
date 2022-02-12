void ledtrig_cpu(enum cpu_led_event ledevt)
{
struct led_trigger_cpu *trig = this_cpu_ptr(&cpu_trig);
bool is_active = trig->is_active;
switch (ledevt) {
case CPU_LED_IDLE_END:
case CPU_LED_START:
is_active = true;
break;
case CPU_LED_IDLE_START:
case CPU_LED_STOP:
case CPU_LED_HALTED:
is_active = false;
break;
default:
break;
}
if (is_active != trig->is_active) {
unsigned int active_cpus;
unsigned int total_cpus;
trig->is_active = is_active;
atomic_add(is_active ? 1 : -1, &num_active_cpus);
active_cpus = atomic_read(&num_active_cpus);
total_cpus = num_present_cpus();
led_trigger_event(trig->_trig,
is_active ? LED_FULL : LED_OFF);
led_trigger_event(trig_cpu_all,
DIV_ROUND_UP(LED_FULL * active_cpus, total_cpus));
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
led_trigger_register_simple("cpu", &trig_cpu_all);
for_each_possible_cpu(cpu) {
struct led_trigger_cpu *trig = &per_cpu(cpu_trig, cpu);
snprintf(trig->name, MAX_NAME_LEN, "cpu%d", cpu);
led_trigger_register_simple(trig->name, &trig->_trig);
}
register_syscore_ops(&ledtrig_cpu_syscore_ops);
ret = cpuhp_setup_state(CPUHP_AP_ONLINE_DYN, "leds/trigger:starting",
ledtrig_online_cpu, ledtrig_prepare_down_cpu);
if (ret < 0)
pr_err("CPU hotplug notifier for ledtrig-cpu could not be registered: %d\n",
ret);
pr_info("ledtrig-cpu: registered to indicate activity on CPUs\n");
return 0;
}
