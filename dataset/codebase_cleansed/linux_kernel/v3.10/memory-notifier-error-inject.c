static int err_inject_init(void)
{
int err;
dir = notifier_err_inject_init("memory", notifier_err_inject_dir,
&memory_notifier_err_inject, priority);
if (IS_ERR(dir))
return PTR_ERR(dir);
err = register_memory_notifier(&memory_notifier_err_inject.nb);
if (err)
debugfs_remove_recursive(dir);
return err;
}
static void err_inject_exit(void)
{
unregister_memory_notifier(&memory_notifier_err_inject.nb);
debugfs_remove_recursive(dir);
}
