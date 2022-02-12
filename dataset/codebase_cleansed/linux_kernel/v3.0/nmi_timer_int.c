static int profile_timer_exceptions_notify(struct notifier_block *self,
unsigned long val, void *data)
{
struct die_args *args = (struct die_args *)data;
int ret = NOTIFY_DONE;
switch (val) {
case DIE_NMI:
oprofile_add_sample(args->regs, 0);
ret = NOTIFY_STOP;
break;
default:
break;
}
return ret;
}
static int timer_start(void)
{
if (register_die_notifier(&profile_timer_exceptions_nb))
return 1;
return 0;
}
static void timer_stop(void)
{
unregister_die_notifier(&profile_timer_exceptions_nb);
synchronize_sched();
}
int __init op_nmi_timer_init(struct oprofile_operations *ops)
{
ops->start = timer_start;
ops->stop = timer_stop;
ops->cpu_type = "timer";
printk(KERN_INFO "oprofile: using NMI timer interrupt.\n");
return 0;
}
