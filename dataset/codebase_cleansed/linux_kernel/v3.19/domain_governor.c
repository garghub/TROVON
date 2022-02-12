static int dev_update_qos_constraint(struct device *dev, void *data)
{
s64 *constraint_ns_p = data;
s32 constraint_ns = -1;
if (dev->power.subsys_data && dev->power.subsys_data->domain_data)
constraint_ns = dev_gpd_data(dev)->td.effective_constraint_ns;
if (constraint_ns < 0) {
constraint_ns = dev_pm_qos_read_value(dev);
constraint_ns *= NSEC_PER_USEC;
}
if (constraint_ns == 0)
return 0;
if (constraint_ns < *constraint_ns_p || *constraint_ns_p == 0)
*constraint_ns_p = constraint_ns;
return 0;
}
static bool default_stop_ok(struct device *dev)
{
struct gpd_timing_data *td = &dev_gpd_data(dev)->td;
unsigned long flags;
s64 constraint_ns;
dev_dbg(dev, "%s()\n", __func__);
spin_lock_irqsave(&dev->power.lock, flags);
if (!td->constraint_changed) {
bool ret = td->cached_stop_ok;
spin_unlock_irqrestore(&dev->power.lock, flags);
return ret;
}
td->constraint_changed = false;
td->cached_stop_ok = false;
td->effective_constraint_ns = -1;
constraint_ns = __dev_pm_qos_read_value(dev);
spin_unlock_irqrestore(&dev->power.lock, flags);
if (constraint_ns < 0)
return false;
constraint_ns *= NSEC_PER_USEC;
if (!dev->power.ignore_children)
device_for_each_child(dev, &constraint_ns,
dev_update_qos_constraint);
if (constraint_ns > 0) {
constraint_ns -= td->start_latency_ns;
if (constraint_ns == 0)
return false;
}
td->effective_constraint_ns = constraint_ns;
td->cached_stop_ok = constraint_ns > td->stop_latency_ns ||
constraint_ns == 0;
return td->cached_stop_ok;
}
static bool default_power_down_ok(struct dev_pm_domain *pd)
{
struct generic_pm_domain *genpd = pd_to_genpd(pd);
struct gpd_link *link;
struct pm_domain_data *pdd;
s64 min_off_time_ns;
s64 off_on_time_ns;
if (genpd->max_off_time_changed) {
struct gpd_link *link;
list_for_each_entry(link, &genpd->slave_links, slave_node)
link->master->max_off_time_changed = true;
genpd->max_off_time_changed = false;
genpd->cached_power_down_ok = false;
genpd->max_off_time_ns = -1;
} else {
return genpd->cached_power_down_ok;
}
off_on_time_ns = genpd->power_off_latency_ns +
genpd->power_on_latency_ns;
list_for_each_entry(pdd, &genpd->dev_list, list_node) {
if (pdd->dev->driver)
off_on_time_ns +=
to_gpd_data(pdd)->td.save_state_latency_ns;
}
min_off_time_ns = -1;
list_for_each_entry(link, &genpd->master_links, master_node) {
struct generic_pm_domain *sd = link->slave;
s64 sd_max_off_ns = sd->max_off_time_ns;
if (sd_max_off_ns < 0)
continue;
if (sd_max_off_ns <= off_on_time_ns)
return false;
if (min_off_time_ns > sd_max_off_ns || min_off_time_ns < 0)
min_off_time_ns = sd_max_off_ns;
}
list_for_each_entry(pdd, &genpd->dev_list, list_node) {
struct gpd_timing_data *td;
s64 constraint_ns;
if (!pdd->dev->driver)
continue;
td = &to_gpd_data(pdd)->td;
constraint_ns = td->effective_constraint_ns;
if (constraint_ns < 0) {
constraint_ns = dev_pm_qos_read_value(pdd->dev);
constraint_ns *= NSEC_PER_USEC;
}
if (constraint_ns == 0)
continue;
constraint_ns -= td->restore_state_latency_ns;
if (constraint_ns <= off_on_time_ns)
return false;
if (min_off_time_ns > constraint_ns || min_off_time_ns < 0)
min_off_time_ns = constraint_ns;
}
genpd->cached_power_down_ok = true;
if (min_off_time_ns < 0)
return true;
genpd->max_off_time_ns = min_off_time_ns - genpd->power_on_latency_ns;
return true;
}
static bool always_on_power_down_ok(struct dev_pm_domain *domain)
{
return false;
}
