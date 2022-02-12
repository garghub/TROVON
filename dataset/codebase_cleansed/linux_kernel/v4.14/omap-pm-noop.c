int omap_pm_set_max_mpu_wakeup_lat(struct device *dev, long t)
{
if (!dev || t < -1) {
WARN(1, "OMAP PM: %s: invalid parameter(s)", __func__);
return -EINVAL;
}
if (t == -1)
pr_debug("OMAP PM: remove max MPU wakeup latency constraint: dev %s\n",
dev_name(dev));
else
pr_debug("OMAP PM: add max MPU wakeup latency constraint: dev %s, t = %ld usec\n",
dev_name(dev), t);
return 0;
}
int omap_pm_set_min_bus_tput(struct device *dev, u8 agent_id, unsigned long r)
{
if (!dev || (agent_id != OCP_INITIATOR_AGENT &&
agent_id != OCP_TARGET_AGENT)) {
WARN(1, "OMAP PM: %s: invalid parameter(s)", __func__);
return -EINVAL;
}
if (r == 0)
pr_debug("OMAP PM: remove min bus tput constraint: dev %s for agent_id %d\n",
dev_name(dev), agent_id);
else
pr_debug("OMAP PM: add min bus tput constraint: dev %s for agent_id %d: rate %ld KiB\n",
dev_name(dev), agent_id, r);
return 0;
}
void omap_pm_enable_off_mode(void)
{
off_mode_enabled = true;
}
void omap_pm_disable_off_mode(void)
{
off_mode_enabled = false;
}
int omap_pm_get_dev_context_loss_count(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
int count;
if (WARN_ON(!dev))
return -ENODEV;
if (dev->pm_domain == &omap_device_pm_domain) {
count = omap_device_get_context_loss_count(pdev);
} else {
WARN_ONCE(off_mode_enabled, "omap_pm: using dummy context loss counter; device %s should be converted to omap_device",
dev_name(dev));
count = dummy_context_loss_counter;
if (off_mode_enabled) {
count++;
count &= INT_MAX;
dummy_context_loss_counter = count;
}
}
pr_debug("OMAP PM: context loss count for dev %s = %d\n",
dev_name(dev), count);
return count;
}
int omap_pm_get_dev_context_loss_count(struct device *dev)
{
return dummy_context_loss_counter;
}
int __init omap_pm_if_early_init(void)
{
return 0;
}
int __init omap_pm_if_init(void)
{
return 0;
}
