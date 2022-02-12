static int err_inject_init(void)
{
int err;
dir = notifier_err_inject_init("cpu", notifier_err_inject_dir,
&cpu_notifier_err_inject, priority);
if (IS_ERR(dir))
return PTR_ERR(dir);
err = register_hotcpu_notifier(&cpu_notifier_err_inject.nb);
if (err)
debugfs_remove_recursive(dir);
return err;
}
static void err_inject_exit(void)
{
unregister_hotcpu_notifier(&cpu_notifier_err_inject.nb);
debugfs_remove_recursive(dir);
}
