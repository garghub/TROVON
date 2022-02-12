static ssize_t
qla4_8xxx_sysfs_read_fw_dump(struct file *filep, struct kobject *kobj,
struct bin_attribute *ba, char *buf, loff_t off,
size_t count)
{
struct scsi_qla_host *ha = to_qla_host(dev_to_shost(container_of(kobj,
struct device, kobj)));
if (!is_qla8022(ha))
return -EINVAL;
if (!test_bit(AF_82XX_DUMP_READING, &ha->flags))
return 0;
return memory_read_from_buffer(buf, count, &off, ha->fw_dump,
ha->fw_dump_size);
}
static ssize_t
qla4_8xxx_sysfs_write_fw_dump(struct file *filep, struct kobject *kobj,
struct bin_attribute *ba, char *buf, loff_t off,
size_t count)
{
struct scsi_qla_host *ha = to_qla_host(dev_to_shost(container_of(kobj,
struct device, kobj)));
uint32_t dev_state;
long reading;
int ret = 0;
if (!is_qla8022(ha))
return -EINVAL;
if (off != 0)
return ret;
buf[1] = 0;
ret = kstrtol(buf, 10, &reading);
if (ret) {
ql4_printk(KERN_ERR, ha, "%s: Invalid input. Return err %d\n",
__func__, ret);
return ret;
}
switch (reading) {
case 0:
if (test_and_clear_bit(AF_82XX_DUMP_READING, &ha->flags)) {
clear_bit(AF_82XX_FW_DUMPED, &ha->flags);
qla4xxx_alloc_fw_dump(ha);
DEBUG2(ql4_printk(KERN_INFO, ha,
"Firmware template reloaded\n"));
}
break;
case 1:
if (test_bit(AF_82XX_FW_DUMPED, &ha->flags) &&
!test_bit(AF_82XX_DUMP_READING, &ha->flags)) {
set_bit(AF_82XX_DUMP_READING, &ha->flags);
DEBUG2(ql4_printk(KERN_INFO, ha,
"Raw firmware dump ready for read on (%ld).\n",
ha->host_no));
}
break;
case 2:
qla4_8xxx_idc_lock(ha);
dev_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DEV_STATE);
if (dev_state == QLA82XX_DEV_READY) {
ql4_printk(KERN_INFO, ha,
"%s: Setting Need reset, reset_owner is 0x%x.\n",
__func__, ha->func_num);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE,
QLA82XX_DEV_NEED_RESET);
set_bit(AF_82XX_RST_OWNER, &ha->flags);
} else
ql4_printk(KERN_INFO, ha,
"%s: Reset not performed as device state is 0x%x\n",
__func__, dev_state);
qla4_8xxx_idc_unlock(ha);
break;
default:
break;
}
return count;
}
void qla4_8xxx_alloc_sysfs_attr(struct scsi_qla_host *ha)
{
struct Scsi_Host *host = ha->host;
struct sysfs_entry *iter;
int ret;
for (iter = bin_file_entries; iter->name; iter++) {
ret = sysfs_create_bin_file(&host->shost_gendev.kobj,
iter->attr);
if (ret)
ql4_printk(KERN_ERR, ha,
"Unable to create sysfs %s binary attribute (%d).\n",
iter->name, ret);
}
}
void qla4_8xxx_free_sysfs_attr(struct scsi_qla_host *ha)
{
struct Scsi_Host *host = ha->host;
struct sysfs_entry *iter;
for (iter = bin_file_entries; iter->name; iter++)
sysfs_remove_bin_file(&host->shost_gendev.kobj,
iter->attr);
}
static ssize_t
qla4xxx_fw_version_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
if (is_qla8022(ha))
return snprintf(buf, PAGE_SIZE, "%d.%02d.%02d (%x)\n",
ha->firmware_version[0],
ha->firmware_version[1],
ha->patch_number, ha->build_number);
else
return snprintf(buf, PAGE_SIZE, "%d.%02d.%02d.%02d\n",
ha->firmware_version[0],
ha->firmware_version[1],
ha->patch_number, ha->build_number);
}
static ssize_t
qla4xxx_serial_num_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
return snprintf(buf, PAGE_SIZE, "%s\n", ha->serial_number);
}
static ssize_t
qla4xxx_iscsi_version_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
return snprintf(buf, PAGE_SIZE, "%d.%02d\n", ha->iscsi_major,
ha->iscsi_minor);
}
static ssize_t
qla4xxx_optrom_version_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
return snprintf(buf, PAGE_SIZE, "%d.%02d.%02d.%02d\n",
ha->bootload_major, ha->bootload_minor,
ha->bootload_patch, ha->bootload_build);
}
static ssize_t
qla4xxx_board_id_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
return snprintf(buf, PAGE_SIZE, "0x%08X\n", ha->board_id);
}
static ssize_t
qla4xxx_fw_state_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
qla4xxx_get_firmware_state(ha);
return snprintf(buf, PAGE_SIZE, "0x%08X%8X\n", ha->firmware_state,
ha->addl_fw_state);
}
static ssize_t
qla4xxx_phy_port_cnt_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
if (!is_qla8022(ha))
return -ENOSYS;
return snprintf(buf, PAGE_SIZE, "0x%04X\n", ha->phy_port_cnt);
}
static ssize_t
qla4xxx_phy_port_num_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
if (!is_qla8022(ha))
return -ENOSYS;
return snprintf(buf, PAGE_SIZE, "0x%04X\n", ha->phy_port_num);
}
static ssize_t
qla4xxx_iscsi_func_cnt_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
if (!is_qla8022(ha))
return -ENOSYS;
return snprintf(buf, PAGE_SIZE, "0x%04X\n", ha->iscsi_pci_func_cnt);
}
static ssize_t
qla4xxx_hba_model_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct scsi_qla_host *ha = to_qla_host(class_to_shost(dev));
return snprintf(buf, PAGE_SIZE, "%s\n", ha->model_name);
}
