static inline struct bnx2i_hba *bnx2i_dev_to_hba(struct device *dev)
{
struct Scsi_Host *shost = class_to_shost(dev);
return iscsi_host_priv(shost);
}
static ssize_t bnx2i_show_sq_info(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bnx2i_hba *hba = bnx2i_dev_to_hba(dev);
return sprintf(buf, "0x%x\n", hba->max_sqes);
}
static ssize_t bnx2i_set_sq_info(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct bnx2i_hba *hba = bnx2i_dev_to_hba(dev);
u32 val;
int max_sq_size;
if (hba->ofld_conns_active)
goto skip_config;
if (test_bit(BNX2I_NX2_DEV_57710, &hba->cnic_dev_type))
max_sq_size = BNX2I_5770X_SQ_WQES_MAX;
else
max_sq_size = BNX2I_570X_SQ_WQES_MAX;
if (sscanf(buf, " 0x%x ", &val) > 0) {
if ((val >= BNX2I_SQ_WQES_MIN) && (val <= max_sq_size) &&
(is_power_of_2(val)))
hba->max_sqes = val;
}
return count;
skip_config:
printk(KERN_ERR "bnx2i: device busy, cannot change SQ size\n");
return 0;
}
static ssize_t bnx2i_show_ccell_info(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct bnx2i_hba *hba = bnx2i_dev_to_hba(dev);
return sprintf(buf, "0x%x\n", hba->num_ccell);
}
static ssize_t bnx2i_set_ccell_info(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
u32 val;
struct bnx2i_hba *hba = bnx2i_dev_to_hba(dev);
if (hba->ofld_conns_active)
goto skip_config;
if (sscanf(buf, " 0x%x ", &val) > 0) {
if ((val >= BNX2I_CCELLS_MIN) &&
(val <= BNX2I_CCELLS_MAX)) {
hba->num_ccell = val;
}
}
return count;
skip_config:
printk(KERN_ERR "bnx2i: device busy, cannot change CCELL size\n");
return 0;
}
