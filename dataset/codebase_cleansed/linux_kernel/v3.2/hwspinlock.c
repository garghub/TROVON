int __init hwspinlocks_init(void)
{
int retval = 0;
struct omap_hwmod *oh;
struct platform_device *pdev;
const char *oh_name = "spinlock";
const char *dev_name = "omap_hwspinlock";
oh = omap_hwmod_lookup(oh_name);
if (oh == NULL)
return -EINVAL;
pdev = omap_device_build(dev_name, 0, oh, &omap_hwspinlock_pdata,
sizeof(struct hwspinlock_pdata),
NULL, 0, false);
if (IS_ERR(pdev)) {
pr_err("Can't build omap_device for %s:%s\n", dev_name,
oh_name);
retval = PTR_ERR(pdev);
}
return retval;
}
