static ssize_t arcmsr_sysfs_iop_message_read(struct file *filp,
struct kobject *kobj,
struct bin_attribute *bin,
char *buf, loff_t off,
size_t count)
{
struct device *dev = container_of(kobj,struct device,kobj);
struct Scsi_Host *host = class_to_shost(dev);
struct AdapterControlBlock *acb = (struct AdapterControlBlock *) host->hostdata;
uint8_t *ptmpQbuffer;
int32_t allxfer_len = 0;
unsigned long flags;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
ptmpQbuffer = (uint8_t *)buf;
spin_lock_irqsave(&acb->rqbuffer_lock, flags);
if (acb->rqbuf_getIndex != acb->rqbuf_putIndex) {
unsigned int tail = acb->rqbuf_getIndex;
unsigned int head = acb->rqbuf_putIndex;
unsigned int cnt_to_end = CIRC_CNT_TO_END(head, tail, ARCMSR_MAX_QBUFFER);
allxfer_len = CIRC_CNT(head, tail, ARCMSR_MAX_QBUFFER);
if (allxfer_len > ARCMSR_API_DATA_BUFLEN)
allxfer_len = ARCMSR_API_DATA_BUFLEN;
if (allxfer_len <= cnt_to_end)
memcpy(ptmpQbuffer, acb->rqbuffer + tail, allxfer_len);
else {
memcpy(ptmpQbuffer, acb->rqbuffer + tail, cnt_to_end);
memcpy(ptmpQbuffer + cnt_to_end, acb->rqbuffer, allxfer_len - cnt_to_end);
}
acb->rqbuf_getIndex = (acb->rqbuf_getIndex + allxfer_len) % ARCMSR_MAX_QBUFFER;
}
if (acb->acb_flags & ACB_F_IOPDATA_OVERFLOW) {
struct QBUFFER __iomem *prbuffer;
acb->acb_flags &= ~ACB_F_IOPDATA_OVERFLOW;
prbuffer = arcmsr_get_iop_rqbuffer(acb);
if (arcmsr_Read_iop_rqbuffer_data(acb, prbuffer) == 0)
acb->acb_flags |= ACB_F_IOPDATA_OVERFLOW;
}
spin_unlock_irqrestore(&acb->rqbuffer_lock, flags);
return allxfer_len;
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
int32_t user_len, cnt2end;
uint8_t *pQbuffer, *ptmpuserbuffer;
unsigned long flags;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (count > ARCMSR_API_DATA_BUFLEN)
return -EINVAL;
ptmpuserbuffer = (uint8_t *)buf;
user_len = (int32_t)count;
spin_lock_irqsave(&acb->wqbuffer_lock, flags);
if (acb->wqbuf_putIndex != acb->wqbuf_getIndex) {
arcmsr_write_ioctldata2iop(acb);
spin_unlock_irqrestore(&acb->wqbuffer_lock, flags);
return 0;
} else {
pQbuffer = &acb->wqbuffer[acb->wqbuf_putIndex];
cnt2end = ARCMSR_MAX_QBUFFER - acb->wqbuf_putIndex;
if (user_len > cnt2end) {
memcpy(pQbuffer, ptmpuserbuffer, cnt2end);
ptmpuserbuffer += cnt2end;
user_len -= cnt2end;
acb->wqbuf_putIndex = 0;
pQbuffer = acb->wqbuffer;
}
memcpy(pQbuffer, ptmpuserbuffer, user_len);
acb->wqbuf_putIndex += user_len;
acb->wqbuf_putIndex %= ARCMSR_MAX_QBUFFER;
if (acb->acb_flags & ACB_F_MESSAGE_WQBUFFER_CLEARED) {
acb->acb_flags &=
~ACB_F_MESSAGE_WQBUFFER_CLEARED;
arcmsr_write_ioctldata2iop(acb);
}
spin_unlock_irqrestore(&acb->wqbuffer_lock, flags);
return count;
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
unsigned long flags;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
arcmsr_clear_iop2drv_rqueue_buffer(acb);
acb->acb_flags |=
(ACB_F_MESSAGE_WQBUFFER_CLEARED
| ACB_F_MESSAGE_RQBUFFER_CLEARED
| ACB_F_MESSAGE_WQBUFFER_READED);
spin_lock_irqsave(&acb->rqbuffer_lock, flags);
acb->rqbuf_getIndex = 0;
acb->rqbuf_putIndex = 0;
spin_unlock_irqrestore(&acb->rqbuffer_lock, flags);
spin_lock_irqsave(&acb->wqbuffer_lock, flags);
acb->wqbuf_getIndex = 0;
acb->wqbuf_putIndex = 0;
spin_unlock_irqrestore(&acb->wqbuffer_lock, flags);
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
