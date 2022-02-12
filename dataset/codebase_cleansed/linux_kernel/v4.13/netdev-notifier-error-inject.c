static int netdev_err_inject_init(void)
{
int err;
dir = notifier_err_inject_init("netdev", notifier_err_inject_dir,
&netdev_notifier_err_inject, priority);
if (IS_ERR(dir))
return PTR_ERR(dir);
err = register_netdevice_notifier(&netdev_notifier_err_inject.nb);
if (err)
debugfs_remove_recursive(dir);
return err;
}
static void netdev_err_inject_exit(void)
{
unregister_netdevice_notifier(&netdev_notifier_err_inject.nb);
debugfs_remove_recursive(dir);
}
