static ssize_t arcmsr_sysfs_iop_message_read(struct file *filp,
struct kobject *kobj,
struct bin_attribute *bin,
char *buf, loff_t off,
size_t count)
{
struct device *dev = container_of(kobj,struct device,kobj);
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb = (struct AdapterControlBlock *) host->hostdata;
uint8_t *pQbuffer,*ptmpQbuffer;
int32_t allxfer_len = 0;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
ptmpQbuffer = (uint8_t *)buf;
while ((acb->rqbuf_firstindex != acb->rqbuf_lastindex)
&& (allxfer_len < 1031)) {
pQbuffer = &acb->rqbuffer[acb->rqbuf_firstindex];
memcpy(ptmpQbuffer, pQbuffer, 1);
acb->rqbuf_firstindex++;
acb->rqbuf_firstindex %= ARCMSR_MAX_QBUFFER;
ptmpQbuffer++;
allxfer_len++;
}
if (acb->acb_flags & ACB_F_IOPDATA_OVERFLOW) {
struct QBUFFER __iomem *prbuffer;
uint8_t __iomem *iop_data;
int32_t iop_len;
acb->acb_flags &= ~ACB_F_IOPDATA_OVERFLOW;
prbuffer = arcmsr_get_iop_rqbuffer(acb);
iop_data = prbuffer->data;
iop_len = readl(&prbuffer->data_len);
while (iop_len > 0) {
acb->rqbuffer[acb->rqbuf_lastindex] = readb(iop_data);
acb->rqbuf_lastindex++;
acb->rqbuf_lastindex %= ARCMSR_MAX_QBUFFER;
iop_data++;
iop_len--;
}
arcmsr_iop_message_read(acb);
}
return (allxfer_len);
}
static ssize_t arcmsr_sysfs_iop_message_write(struct file *filp,
struct kobject *kobj,
struct bin_attribute *bin,
char *buf, loff_t off,
size_t count)
{
struct device *dev = container_of(kobj,struct device,kobj);
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb = (struct AdapterControlBlock *) host->hostdata;
int32_t my_empty_len, user_len, wqbuf_firstindex, wqbuf_lastindex;
uint8_t *pQbuffer, *ptmpuserbuffer;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (count > 1032)
return -EINVAL;
ptmpuserbuffer = (uint8_t *)buf;
user_len = (int32_t)count;
wqbuf_lastindex = acb->wqbuf_lastindex;
wqbuf_firstindex = acb->wqbuf_firstindex;
if (wqbuf_lastindex != wqbuf_firstindex) {
arcmsr_post_ioctldata2iop(acb);
return 0;
} else {
my_empty_len = (wqbuf_firstindex-wqbuf_lastindex - 1)
&(ARCMSR_MAX_QBUFFER - 1);
if (my_empty_len >= user_len) {
while (user_len > 0) {
pQbuffer =
&acb->wqbuffer[acb->wqbuf_lastindex];
memcpy(pQbuffer, ptmpuserbuffer, 1);
acb->wqbuf_lastindex++;
acb->wqbuf_lastindex %= ARCMSR_MAX_QBUFFER;
ptmpuserbuffer++;
user_len--;
}
if (acb->acb_flags & ACB_F_MESSAGE_WQBUFFER_CLEARED) {
acb->acb_flags &=
~ACB_F_MESSAGE_WQBUFFER_CLEARED;
arcmsr_post_ioctldata2iop(acb);
}
return count;
} else {
return 0;
}
}
}
static ssize_t arcmsr_sysfs_iop_message_clear(struct file *filp,
struct kobject *kobj,
struct bin_attribute *bin,
char *buf, loff_t off,
size_t count)
{
struct device *dev = container_of(kobj,struct device,kobj);
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb = (struct AdapterControlBlock *) host->hostdata;
uint8_t *pQbuffer;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (acb->acb_flags & ACB_F_IOPDATA_OVERFLOW) {
acb->acb_flags &= ~ACB_F_IOPDATA_OVERFLOW;
arcmsr_iop_message_read(acb);
}
acb->acb_flags |=
(ACB_F_MESSAGE_WQBUFFER_CLEARED
| ACB_F_MESSAGE_RQBUFFER_CLEARED
| ACB_F_MESSAGE_WQBUFFER_READED);
acb->rqbuf_firstindex = 0;
acb->rqbuf_lastindex = 0;
acb->wqbuf_firstindex = 0;
acb->wqbuf_lastindex = 0;
pQbuffer = acb->rqbuffer;
memset(pQbuffer, 0, sizeof (struct QBUFFER));
pQbuffer = acb->wqbuffer;
memset(pQbuffer, 0, sizeof (struct QBUFFER));
return 1;
}
int arcmsr_alloc_sysfs_attr(struct AdapterControlBlock *acb)
{
struct Scsi_Host *host = acb->host;
int error;
error = sysfs_create_bin_file(&host->shost_dev.kobj, &arcmsr_sysfs_message_read_attr);
if (error) {
printk(KERN_ERR "arcmsr: alloc sysfs mu_read failed\n");
goto error_bin_file_message_read;
}
error = sysfs_create_bin_file(&host->shost_dev.kobj, &arcmsr_sysfs_message_write_attr);
if (error) {
printk(KERN_ERR "arcmsr: alloc sysfs mu_write failed\n");
goto error_bin_file_message_write;
}
error = sysfs_create_bin_file(&host->shost_dev.kobj, &arcmsr_sysfs_message_clear_attr);
if (error) {
printk(KERN_ERR "arcmsr: alloc sysfs mu_clear failed\n");
goto error_bin_file_message_clear;
}
return 0;
error_bin_file_message_clear:
sysfs_remove_bin_file(&host->shost_dev.kobj, &arcmsr_sysfs_message_write_attr);
error_bin_file_message_write:
sysfs_remove_bin_file(&host->shost_dev.kobj, &arcmsr_sysfs_message_read_attr);
error_bin_file_message_read:
return error;
}
void arcmsr_free_sysfs_attr(struct AdapterControlBlock *acb)
{
struct Scsi_Host *host = acb->host;
sysfs_remove_bin_file(&host->shost_dev.kobj, &arcmsr_sysfs_message_clear_attr);
sysfs_remove_bin_file(&host->shost_dev.kobj, &arcmsr_sysfs_message_write_attr);
sysfs_remove_bin_file(&host->shost_dev.kobj, &arcmsr_sysfs_message_read_attr);
}
static ssize_t
arcmsr_attr_host_driver_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE,
"%s\n",
ARCMSR_DRIVER_VERSION);
}
static ssize_t
arcmsr_attr_host_driver_posted_cmd(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb =
(struct AdapterControlBlock *) host->hostdata;
return snprintf(buf, PAGE_SIZE,
"%4d\n",
atomic_read(&acb->ccboutstandingcount));
}
static ssize_t
arcmsr_attr_host_driver_reset(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb =
(struct AdapterControlBlock *) host->hostdata;
return snprintf(buf, PAGE_SIZE,
"%4d\n",
acb->num_resets);
}
static ssize_t
arcmsr_attr_host_driver_abort(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb =
(struct AdapterControlBlock *) host->hostdata;
return snprintf(buf, PAGE_SIZE,
"%4d\n",
acb->num_aborts);
}
static ssize_t
arcmsr_attr_host_fw_model(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb =
(struct AdapterControlBlock *) host->hostdata;
return snprintf(buf, PAGE_SIZE,
"%s\n",
acb->firm_model);
}
static ssize_t
arcmsr_attr_host_fw_version(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb =
(struct AdapterControlBlock *) host->hostdata;
return snprintf(buf, PAGE_SIZE,
"%s\n",
acb->firm_version);
}
static ssize_t
arcmsr_attr_host_fw_request_len(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb =
(struct AdapterControlBlock *) host->hostdata;
return snprintf(buf, PAGE_SIZE,
"%4d\n",
acb->firm_request_len);
}
static ssize_t
arcmsr_attr_host_fw_numbers_queue(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb =
(struct AdapterControlBlock *) host->hostdata;
return snprintf(buf, PAGE_SIZE,
"%4d\n",
acb->firm_numbers_queue);
}
static ssize_t
arcmsr_attr_host_fw_sdram_size(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb =
(struct AdapterControlBlock *) host->hostdata;
return snprintf(buf, PAGE_SIZE,
"%4d\n",
acb->firm_sdram_size);
}
static ssize_t
arcmsr_attr_host_fw_hd_channels(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb =
(struct AdapterControlBlock *) host->hostdata;
return snprintf(buf, PAGE_SIZE,
"%4d\n",
acb->firm_hd_channels);
}
