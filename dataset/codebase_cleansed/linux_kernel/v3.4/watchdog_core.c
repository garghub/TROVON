int watchdog_register_device(struct watchdog_device *wdd)
{
int ret;
if (wdd == NULL || wdd->info == NULL || wdd->ops == NULL)
return -EINVAL;
if (wdd->ops->start == NULL || wdd->ops->stop == NULL)
return -EINVAL;
if (wdd->min_timeout > wdd->max_timeout) {
pr_info("Invalid min and max timeout values, resetting to 0!\n");
wdd->min_timeout = 0;
wdd->max_timeout = 0;
}
ret = watchdog_dev_register(wdd);
if (ret) {
pr_err("error registering /dev/watchdog (err=%d)\n", ret);
return ret;
}
return 0;
}
void watchdog_unregister_device(struct watchdog_device *wdd)
{
int ret;
if (wdd == NULL)
return;
ret = watchdog_dev_unregister(wdd);
if (ret)
pr_err("error unregistering /dev/watchdog (err=%d)\n", ret);
}
