static ssize_t
snic_show_sym_name(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct snic *snic = shost_priv(class_to_shost(dev));
return snprintf(buf, PAGE_SIZE, "%s\n", snic->name);
}
static ssize_t
snic_show_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct snic *snic = shost_priv(class_to_shost(dev));
return snprintf(buf, PAGE_SIZE, "%s\n",
snic_state_str[snic_get_state(snic)]);
}
static ssize_t
snic_show_drv_version(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", SNIC_DRV_VERSION);
}
static ssize_t
snic_show_link_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct snic *snic = shost_priv(class_to_shost(dev));
if (snic->config.xpt_type == SNIC_DAS)
snic->link_status = svnic_dev_link_status(snic->vdev);
return snprintf(buf, PAGE_SIZE, "%s\n",
(snic->link_status) ? "Link Up" : "Link Down");
}
