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
