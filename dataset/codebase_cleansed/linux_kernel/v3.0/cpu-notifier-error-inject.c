static int err_inject_cpu_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
int err = 0;
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
err = cpu_up_prepare_error;
break;
case CPU_DOWN_PREPARE:
case CPU_DOWN_PREPARE_FROZEN:
err = cpu_down_prepare_error;
break;
}
if (err)
printk(KERN_INFO "Injecting error (%d) at cpu notifier\n", err);
return notifier_from_errno(err);
}
static int err_inject_init(void)
{
err_inject_cpu_notifier.priority = priority;
return register_hotcpu_notifier(&err_inject_cpu_notifier);
}
static void err_inject_exit(void)
{
unregister_hotcpu_notifier(&err_inject_cpu_notifier);
}
