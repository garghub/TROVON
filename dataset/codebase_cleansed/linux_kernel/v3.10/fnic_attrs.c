static ssize_t fnic_show_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fc_lport *lp = shost_priv(class_to_shost(dev));
struct fnic *fnic = lport_priv(lp);
return snprintf(buf, PAGE_SIZE, "%s\n", fnic_state_str[fnic->state]);
}
static ssize_t fnic_show_drv_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", DRV_VERSION);
}
static ssize_t fnic_show_link_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct fc_lport *lp = shost_priv(class_to_shost(dev));
return snprintf(buf, PAGE_SIZE, "%s\n", (lp->link_up)
? "Link Up" : "Link Down");
}
