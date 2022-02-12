static int cpu_pm_notify(enum cpu_pm_event event, int nr_to_call, int *nr_calls)
{
int ret;
rcu_irq_enter_irqson();
ret = __atomic_notifier_call_chain(&cpu_pm_notifier_chain, event, NULL,
nr_to_call, nr_calls);
rcu_irq_exit_irqson();
return notifier_to_errno(ret);
}
int cpu_pm_register_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_register(&cpu_pm_notifier_chain, nb);
}
int cpu_pm_unregister_notifier(struct notifier_block *nb)
{
return atomic_notifier_chain_unregister(&cpu_pm_notifier_chain, nb);
}
int cpu_pm_enter(void)
{
int nr_calls;
int ret = 0;
ret = cpu_pm_notify(CPU_PM_ENTER, -1, &nr_calls);
if (ret)
cpu_pm_notify(CPU_PM_ENTER_FAILED, nr_calls - 1, NULL);
return ret;
}
int cpu_pm_exit(void)
{
return cpu_pm_notify(CPU_PM_EXIT, -1, NULL);
}
int cpu_cluster_pm_enter(void)
{
int nr_calls;
int ret = 0;
ret = cpu_pm_notify(CPU_CLUSTER_PM_ENTER, -1, &nr_calls);
if (ret)
cpu_pm_notify(CPU_CLUSTER_PM_ENTER_FAILED, nr_calls - 1, NULL);
return ret;
}
int cpu_cluster_pm_exit(void)
{
return cpu_pm_notify(CPU_CLUSTER_PM_EXIT, -1, NULL);
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
