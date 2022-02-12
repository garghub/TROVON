static int rmobile_reset_handler(struct notifier_block *this,
unsigned long mode, void *cmd)
{
pr_debug("%s %lu\n", __func__, mode);
writel(RESCNT2_PRES, sysc_base2 + RESCNT2);
return NOTIFY_DONE;
}
static int rmobile_reset_probe(struct platform_device *pdev)
{
int error;
sysc_base2 = of_iomap(pdev->dev.of_node, 1);
if (!sysc_base2)
return -ENODEV;
error = register_restart_handler(&rmobile_reset_nb);
if (error) {
dev_err(&pdev->dev,
"cannot register restart handler (err=%d)\n", error);
goto fail_unmap;
}
return 0;
fail_unmap:
iounmap(sysc_base2);
return error;
}
static int rmobile_reset_remove(struct platform_device *pdev)
{
unregister_restart_handler(&rmobile_reset_nb);
iounmap(sysc_base2);
return 0;
}
