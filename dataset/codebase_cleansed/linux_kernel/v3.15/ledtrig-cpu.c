void ledtrig_cpu(enum cpu_led_event ledevt)
{
struct led_trigger_cpu *trig = &__get_cpu_var(cpu_trig);
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
static int ledtrig_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_STARTING:
ledtrig_cpu(CPU_LED_START);
break;
case CPU_DYING:
ledtrig_cpu(CPU_LED_STOP);
break;
}
return NOTIFY_OK;
}
static int __init ledtrig_cpu_init(void)
{
int cpu;
BUILD_BUG_ON(CONFIG_NR_CPUS > 9999);
for_each_possible_cpu(cpu) {
struct led_trigger_cpu *trig = &per_cpu(cpu_trig, cpu);
snprintf(trig->name, MAX_NAME_LEN, "cpu%d", cpu);
led_trigger_register_simple(trig->name, &trig->_trig);
}
register_syscore_ops(&ledtrig_cpu_syscore_ops);
register_cpu_notifier(&ledtrig_cpu_nb);
pr_info("ledtrig-cpu: registered to indicate activity on CPUs\n");
return 0;
}
static void __exit ledtrig_cpu_exit(void)
{
int cpu;
unregister_cpu_notifier(&ledtrig_cpu_nb);
for_each_possible_cpu(cpu) {
struct led_trigger_cpu *trig = &per_cpu(cpu_trig, cpu);
led_trigger_unregister_simple(trig->_trig);
trig->_trig = NULL;
memset(trig->name, 0, MAX_NAME_LEN);
}
unregister_syscore_ops(&ledtrig_cpu_syscore_ops);
}
