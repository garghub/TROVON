static int err_inject_init(void)
{
int err;
dir = notifier_err_inject_init("pm", notifier_err_inject_dir,
&pm_notifier_err_inject, priority);
if (IS_ERR(dir))
return PTR_ERR(dir);
err = register_pm_notifier(&pm_notifier_err_inject.nb);
if (err)
debugfs_remove_recursive(dir);
return err;
}
static void err_inject_exit(void)
{
unregister_pm_notifier(&pm_notifier_err_inject.nb);
debugfs_remove_recursive(dir);
}
