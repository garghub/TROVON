static int __init default_rootfs(void)
{
int err;
err = sys_mkdir((const char __user __force *) "/dev", 0755);
if (err < 0)
goto out;
err = sys_mknod((const char __user __force *) "/dev/console",
S_IFCHR | S_IRUSR | S_IWUSR,
new_encode_dev(MKDEV(5, 1)));
if (err < 0)
goto out;
err = sys_mkdir((const char __user __force *) "/root", 0700);
if (err < 0)
goto out;
return 0;
out:
printk(KERN_WARNING "Failed to create a rootfs\n");
return err;
}
