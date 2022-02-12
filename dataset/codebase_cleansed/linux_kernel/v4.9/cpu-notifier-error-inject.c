static int notf_err_handle(struct notifier_err_inject_action *action)
{
int ret;
ret = action->error;
if (ret)
pr_info("Injecting error (%d) to %s\n", ret, action->name);
return ret;
}
static int notf_err_inj_up_prepare(unsigned int cpu)
{
if (!cpuhp_tasks_frozen)
return notf_err_handle(&cpu_notifier_err_inject.actions[0]);
else
return notf_err_handle(&cpu_notifier_err_inject.actions[1]);
}
static int notf_err_inj_dead(unsigned int cpu)
{
if (!cpuhp_tasks_frozen)
return notf_err_handle(&cpu_notifier_err_inject.actions[2]);
else
return notf_err_handle(&cpu_notifier_err_inject.actions[3]);
}
static int err_inject_init(void)
{
int err;
dir = notifier_err_inject_init("cpu", notifier_err_inject_dir,
&cpu_notifier_err_inject, priority);
if (IS_ERR(dir))
return PTR_ERR(dir);
err = cpuhp_setup_state_nocalls(CPUHP_NOTF_ERR_INJ_PREPARE,
"cpu-err-notif:prepare",
notf_err_inj_up_prepare,
notf_err_inj_dead);
if (err)
debugfs_remove_recursive(dir);
return err;
}
static void err_inject_exit(void)
{
cpuhp_remove_state_nocalls(CPUHP_NOTF_ERR_INJ_PREPARE);
debugfs_remove_recursive(dir);
}
