static ssize_t zfcp_sysfs_port_failed_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct zfcp_port *port = container_of(dev, struct zfcp_port, dev);
if (atomic_read(&port->status) & ZFCP_STATUS_COMMON_ERP_FAILED)
return sprintf(buf, "1\n");
return sprintf(buf, "0\n");
}
static ssize_t zfcp_sysfs_port_failed_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct zfcp_port *port = container_of(dev, struct zfcp_port, dev);
unsigned long val;
if (strict_strtoul(buf, 0, &val) || val != 0)
return -EINVAL;
zfcp_erp_set_port_status(port, ZFCP_STATUS_COMMON_RUNNING);
zfcp_erp_port_reopen(port, ZFCP_STATUS_COMMON_ERP_FAILED, "sypfai2");
zfcp_erp_wait(port->adapter);
return count;
}
static ssize_t zfcp_sysfs_unit_failed_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct zfcp_unit *unit = container_of(dev, struct zfcp_unit, dev);
struct scsi_device *sdev;
unsigned int status, failed = 1;
sdev = zfcp_unit_sdev(unit);
if (sdev) {
status = atomic_read(&sdev_to_zfcp(sdev)->status);
failed = status & ZFCP_STATUS_COMMON_ERP_FAILED ? 1 : 0;
scsi_device_put(sdev);
}
return sprintf(buf, "%d\n", failed);
}
static ssize_t zfcp_sysfs_unit_failed_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct zfcp_unit *unit = container_of(dev, struct zfcp_unit, dev);
unsigned long val;
struct scsi_device *sdev;
if (strict_strtoul(buf, 0, &val) || val != 0)
return -EINVAL;
sdev = zfcp_unit_sdev(unit);
if (sdev) {
zfcp_erp_set_lun_status(sdev, ZFCP_STATUS_COMMON_RUNNING);
zfcp_erp_lun_reopen(sdev, ZFCP_STATUS_COMMON_ERP_FAILED,
"syufai2");
zfcp_erp_wait(unit->port->adapter);
} else
zfcp_unit_scsi_scan(unit);
return count;
}
static ssize_t zfcp_sysfs_adapter_failed_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct ccw_device *cdev = to_ccwdev(dev);
struct zfcp_adapter *adapter = zfcp_ccw_adapter_by_cdev(cdev);
int i;
if (!adapter)
return -ENODEV;
if (atomic_read(&adapter->status) & ZFCP_STATUS_COMMON_ERP_FAILED)
i = sprintf(buf, "1\n");
else
i = sprintf(buf, "0\n");
zfcp_ccw_adapter_put(adapter);
return i;
}
static ssize_t zfcp_sysfs_adapter_failed_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ccw_device *cdev = to_ccwdev(dev);
struct zfcp_adapter *adapter = zfcp_ccw_adapter_by_cdev(cdev);
unsigned long val;
int retval = 0;
if (!adapter)
return -ENODEV;
if (strict_strtoul(buf, 0, &val) || val != 0) {
retval = -EINVAL;
goto out;
}
zfcp_erp_set_adapter_status(adapter, ZFCP_STATUS_COMMON_RUNNING);
zfcp_erp_adapter_reopen(adapter, ZFCP_STATUS_COMMON_ERP_FAILED,
"syafai2");
zfcp_erp_wait(adapter);
out:
zfcp_ccw_adapter_put(adapter);
return retval ? retval : (ssize_t) count;
}
static ssize_t zfcp_sysfs_port_rescan_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ccw_device *cdev = to_ccwdev(dev);
struct zfcp_adapter *adapter = zfcp_ccw_adapter_by_cdev(cdev);
if (!adapter)
return -ENODEV;
queue_work(adapter->work_queue, &adapter->scan_work);
flush_work(&adapter->scan_work);
zfcp_ccw_adapter_put(adapter);
return (ssize_t) count;
}
static ssize_t zfcp_sysfs_port_remove_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ccw_device *cdev = to_ccwdev(dev);
struct zfcp_adapter *adapter = zfcp_ccw_adapter_by_cdev(cdev);
struct zfcp_port *port;
u64 wwpn;
int retval = -EINVAL;
if (!adapter)
return -ENODEV;
if (strict_strtoull(buf, 0, (unsigned long long *) &wwpn))
goto out;
port = zfcp_get_port_by_wwpn(adapter, wwpn);
if (!port)
goto out;
else
retval = 0;
mutex_lock(&zfcp_sysfs_port_units_mutex);
if (atomic_read(&port->units) > 0) {
retval = -EBUSY;
mutex_unlock(&zfcp_sysfs_port_units_mutex);
goto out;
}
atomic_set(&port->units, -1);
mutex_unlock(&zfcp_sysfs_port_units_mutex);
write_lock_irq(&adapter->port_list_lock);
list_del(&port->list);
write_unlock_irq(&adapter->port_list_lock);
put_device(&port->dev);
zfcp_erp_port_shutdown(port, 0, "syprs_1");
zfcp_device_unregister(&port->dev, &zfcp_sysfs_port_attrs);
out:
zfcp_ccw_adapter_put(adapter);
return retval ? retval : (ssize_t) count;
}
static ssize_t zfcp_sysfs_unit_add_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct zfcp_port *port = container_of(dev, struct zfcp_port, dev);
u64 fcp_lun;
int retval;
if (strict_strtoull(buf, 0, (unsigned long long *) &fcp_lun))
return -EINVAL;
retval = zfcp_unit_add(port, fcp_lun);
if (retval)
return retval;
return count;
}
static ssize_t zfcp_sysfs_unit_remove_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct zfcp_port *port = container_of(dev, struct zfcp_port, dev);
u64 fcp_lun;
if (strict_strtoull(buf, 0, (unsigned long long *) &fcp_lun))
return -EINVAL;
if (zfcp_unit_remove(port, fcp_lun))
return -EINVAL;
return count;
}
static ssize_t zfcp_sysfs_scsi_fcp_lun_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
return sprintf(buf, "0x%016llx\n", zfcp_scsi_dev_lun(sdev));
}
static ssize_t zfcp_sysfs_adapter_util_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *scsi_host = dev_to_shost(dev);
struct fsf_qtcb_bottom_port *qtcb_port;
struct zfcp_adapter *adapter;
int retval;
adapter = (struct zfcp_adapter *) scsi_host->hostdata[0];
if (!(adapter->adapter_features & FSF_FEATURE_MEASUREMENT_DATA))
return -EOPNOTSUPP;
qtcb_port = kzalloc(sizeof(struct fsf_qtcb_bottom_port), GFP_KERNEL);
if (!qtcb_port)
return -ENOMEM;
retval = zfcp_fsf_exchange_port_data_sync(adapter->qdio, qtcb_port);
if (!retval)
retval = sprintf(buf, "%u %u %u\n", qtcb_port->cp_util,
qtcb_port->cb_util, qtcb_port->a_util);
kfree(qtcb_port);
return retval;
}
static int zfcp_sysfs_adapter_ex_config(struct device *dev,
struct fsf_statistics_info *stat_inf)
{
struct Scsi_Host *scsi_host = dev_to_shost(dev);
struct fsf_qtcb_bottom_config *qtcb_config;
struct zfcp_adapter *adapter;
int retval;
adapter = (struct zfcp_adapter *) scsi_host->hostdata[0];
if (!(adapter->adapter_features & FSF_FEATURE_MEASUREMENT_DATA))
return -EOPNOTSUPP;
qtcb_config = kzalloc(sizeof(struct fsf_qtcb_bottom_config),
GFP_KERNEL);
if (!qtcb_config)
return -ENOMEM;
retval = zfcp_fsf_exchange_config_data_sync(adapter->qdio, qtcb_config);
if (!retval)
*stat_inf = qtcb_config->stat_info;
kfree(qtcb_config);
return retval;
}
static ssize_t zfcp_sysfs_adapter_q_full_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *scsi_host = class_to_shost(dev);
struct zfcp_qdio *qdio =
((struct zfcp_adapter *) scsi_host->hostdata[0])->qdio;
u64 util;
spin_lock_bh(&qdio->stat_lock);
util = qdio->req_q_util;
spin_unlock_bh(&qdio->stat_lock);
return sprintf(buf, "%d %llu\n", atomic_read(&qdio->req_q_full),
(unsigned long long)util);
}
