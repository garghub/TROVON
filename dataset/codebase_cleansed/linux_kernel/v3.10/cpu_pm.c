static int cpu_pm_notify(enum cpu_pm_event event, int nr_to_call, int *nr_calls)
{
int ret;
ret = __raw_notifier_call_chain(&cpu_pm_notifier_chain, event, NULL,
nr_to_call, nr_calls);
return notifier_to_errno(ret);
}
int cpu_pm_register_notifier(struct notifier_block *nb)
{
unsigned long flags;
int ret;
write_lock_irqsave(&cpu_pm_notifier_lock, flags);
ret = raw_notifier_chain_register(&cpu_pm_notifier_chain, nb);
write_unlock_irqrestore(&cpu_pm_notifier_lock, flags);
return ret;
}
int cpu_pm_unregister_notifier(struct notifier_block *nb)
{
unsigned long flags;
int ret;
write_lock_irqsave(&cpu_pm_notifier_lock, flags);
ret = raw_notifier_chain_unregister(&cpu_pm_notifier_chain, nb);
write_unlock_irqrestore(&cpu_pm_notifier_lock, flags);
return ret;
}
int cpu_pm_enter(void)
{
int nr_calls;
int ret = 0;
read_lock(&cpu_pm_notifier_lock);
ret = cpu_pm_notify(CPU_PM_ENTER, -1, &nr_calls);
if (ret)
cpu_pm_notify(CPU_PM_ENTER_FAILED, nr_calls - 1, NULL);
read_unlock(&cpu_pm_notifier_lock);
return ret;
}
int cpu_pm_exit(void)
{
int ret;
read_lock(&cpu_pm_notifier_lock);
ret = cpu_pm_notify(CPU_PM_EXIT, -1, NULL);
read_unlock(&cpu_pm_notifier_lock);
return ret;
}
int cpu_cluster_pm_enter(void)
{
int nr_calls;
int ret = 0;
read_lock(&cpu_pm_notifier_lock);
ret = cpu_pm_notify(CPU_CLUSTER_PM_ENTER, -1, &nr_calls);
if (ret)
cpu_pm_notify(CPU_CLUSTER_PM_ENTER_FAILED, nr_calls - 1, NULL);
read_unlock(&cpu_pm_notifier_lock);
return ret;
}
int cpu_cluster_pm_exit(void)
{
int ret;
read_lock(&cpu_pm_notifier_lock);
ret = cpu_pm_notify(CPU_CLUSTER_PM_EXIT, -1, NULL);
read_unlock(&cpu_pm_notifier_lock);
return ret;
}
static int cpu_pm_suspend(void)
{
int ret;
ret = cpu_pm_enter();
if (ret)
return ret;
ret = cpu_cluster_pm_enter();
return ret;
}
static void cpu_pm_resume(void)
{
cpu_cluster_pm_exit();
cpu_pm_exit();
}
static int cpu_pm_init(void)
{
register_syscore_ops(&cpu_pm_syscore_ops);
return 0;
}
