static void dummy_timer_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
}
static void dummy_timer_setup(void)
{
int cpu = smp_processor_id();
struct clock_event_device *evt = raw_cpu_ptr(&dummy_timer_evt);
evt->name = "dummy_timer";
evt->features = CLOCK_EVT_FEAT_PERIODIC |
CLOCK_EVT_FEAT_ONESHOT |
CLOCK_EVT_FEAT_DUMMY;
evt->rating = 100;
evt->set_mode = dummy_timer_set_mode;
evt->cpumask = cpumask_of(cpu);
clockevents_register_device(evt);
}
static int dummy_timer_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
if ((action & ~CPU_TASKS_FROZEN) == CPU_STARTING)
dummy_timer_setup();
return NOTIFY_OK;
}
static int __init dummy_timer_register(void)
{
int err = 0;
cpu_notifier_register_begin();
err = __register_cpu_notifier(&dummy_timer_cpu_nb);
if (err)
goto out;
if (num_possible_cpus() > 1)
dummy_timer_setup();
out:
cpu_notifier_register_done();
return err;
}
