static int err_inject_init(void)
{
int err;
dir = notifier_err_inject_init("OF-reconfig",
notifier_err_inject_dir, &reconfig_err_inject, priority);
if (IS_ERR(dir))
return PTR_ERR(dir);
err = of_reconfig_notifier_register(&reconfig_err_inject.nb);
if (err)
debugfs_remove_recursive(dir);
return err;
}
static void err_inject_exit(void)
{
of_reconfig_notifier_unregister(&reconfig_err_inject.nb);
debugfs_remove_recursive(dir);
}
