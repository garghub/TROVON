int __init hwspinlocks_init(void)
{
int retval = 0;
struct omap_hwmod *oh;
struct omap_device *od;
const char *oh_name = "spinlock";
const char *dev_name = "omap_hwspinlock";
oh = omap_hwmod_lookup(oh_name);
if (oh == NULL)
return -EINVAL;
od = omap_device_build(dev_name, 0, oh, NULL, 0,
omap_spinlock_latency,
ARRAY_SIZE(omap_spinlock_latency), false);
if (IS_ERR(od)) {
pr_err("Can't build omap_device for %s:%s\n", dev_name,
oh_name);
retval = PTR_ERR(od);
}
return retval;
}
