static const char* host_info(struct Scsi_Host *host)
{
struct us_data *us = host_to_us(host);
return us->scsi_name;
}
static int slave_alloc (struct scsi_device *sdev)
{
struct us_data *us = host_to_us(sdev->host);
sdev->inquiry_len = 36;
blk_queue_update_dma_alignment(sdev->request_queue, (512 - 1));
if (us->protocol == USB_PR_BULK && us->max_lun > 0)
sdev->sdev_bflags |= BLIST_FORCELUN;
return 0;
}
static int slave_configure(struct scsi_device *sdev)
{
struct us_data *us = host_to_us(sdev->host);
if (us->fflags & (US_FL_MAX_SECTORS_64 | US_FL_MAX_SECTORS_MIN)) {
unsigned int max_sectors = 64;
if (us->fflags & US_FL_MAX_SECTORS_MIN)
max_sectors = PAGE_CACHE_SIZE >> 9;
if (queue_max_hw_sectors(sdev->request_queue) > max_sectors)
blk_queue_max_hw_sectors(sdev->request_queue,
max_sectors);
} else if (sdev->type == TYPE_TAPE) {
blk_queue_max_hw_sectors(sdev->request_queue, 0x7FFFFF);
}
if (!us->pusb_dev->bus->controller->dma_mask)
blk_queue_bounce_limit(sdev->request_queue, BLK_BOUNCE_HIGH);
if (sdev->type == TYPE_DISK) {
switch (le16_to_cpu(us->pusb_dev->descriptor.idVendor)) {
case VENDOR_ID_NOKIA:
case VENDOR_ID_NIKON:
case VENDOR_ID_PENTAX:
case VENDOR_ID_MOTOROLA:
if (!(us->fflags & (US_FL_FIX_CAPACITY |
US_FL_CAPACITY_OK)))
us->fflags |= US_FL_CAPACITY_HEURISTICS;
break;
}
if (us->subclass != USB_SC_SCSI && us->subclass != USB_SC_CYP_ATACB)
sdev->use_10_for_ms = 1;
sdev->use_192_bytes_for_3f = 1;
if (us->fflags & US_FL_NO_WP_DETECT)
sdev->skip_ms_page_3f = 1;
sdev->skip_ms_page_8 = 1;
sdev->skip_vpd_pages = 1;
sdev->no_report_opcodes = 1;
sdev->no_write_same = 1;
if (us->fflags & US_FL_FIX_CAPACITY)
sdev->fix_capacity = 1;
if (us->fflags & US_FL_CAPACITY_HEURISTICS)
sdev->guess_capacity = 1;
if (us->fflags & US_FL_NO_READ_CAPACITY_16)
sdev->no_read_capacity_16 = 1;
if (!(us->fflags & US_FL_NEEDS_CAP16))
sdev->try_rc_10_first = 1;
if (sdev->scsi_level > SCSI_SPC_2)
us->fflags |= US_FL_SANE_SENSE;
sdev->retry_hwerror = 1;
sdev->allow_restart = 1;
sdev->last_sector_bug = 1;
if (!(us->fflags & (US_FL_FIX_CAPACITY | US_FL_CAPACITY_OK |
US_FL_SCM_MULT_TARG)) &&
us->protocol == USB_PR_BULK)
us->use_last_sector_hacks = 1;
if (us->fflags & US_FL_WRITE_CACHE)
sdev->wce_default_on = 1;
if (us->fflags & US_FL_BROKEN_FUA)
sdev->broken_fua = 1;
} else {
sdev->use_10_for_ms = 1;
if (us->fflags & US_FL_NO_READ_DISC_INFO)
sdev->no_read_disc_info = 1;
}
if ((us->protocol == USB_PR_CB || us->protocol == USB_PR_CBI) &&
sdev->scsi_level == SCSI_UNKNOWN)
us->max_lun = 0;
if (us->fflags & US_FL_NOT_LOCKABLE)
sdev->lockable = 0;
return 0;
}
static int target_alloc(struct scsi_target *starget)
{
struct us_data *us = host_to_us(dev_to_shost(starget->dev.parent));
starget->no_report_luns = 1;
if (us->subclass == USB_SC_UFI)
starget->pdt_1f_for_no_lun = 1;
return 0;
}
static int queuecommand_lck(struct scsi_cmnd *srb,
void (*done)(struct scsi_cmnd *))
{
struct us_data *us = host_to_us(srb->device->host);
if (us->srb != NULL) {
printk(KERN_ERR USB_STORAGE "Error in %s: us->srb = %p\n",
__func__, us->srb);
return SCSI_MLQUEUE_HOST_BUSY;
}
if (test_bit(US_FLIDX_DISCONNECTING, &us->dflags)) {
usb_stor_dbg(us, "Fail command during disconnect\n");
srb->result = DID_NO_CONNECT << 16;
done(srb);
return 0;
}
srb->scsi_done = done;
us->srb = srb;
complete(&us->cmnd_ready);
return 0;
}
int device_reset(struct scsi_cmnd *srb)
{
struct us_data *us = host_to_us(srb->device->host);
int result;
usb_stor_dbg(us, "%s called\n", __func__);
mutex_lock(&(us->dev_mutex));
result = us->transport_reset(us);
mutex_unlock(&us->dev_mutex);
return result < 0 ? FAILED : SUCCESS;
}
static int bus_reset(struct scsi_cmnd *srb)
{
struct us_data *us = host_to_us(srb->device->host);
int result;
usb_stor_dbg(us, "%s called\n", __func__);
result = usb_stor_port_reset(us);
return result < 0 ? FAILED : SUCCESS;
}
void usb_stor_report_device_reset(struct us_data *us)
{
int i;
struct Scsi_Host *host = us_to_host(us);
scsi_report_device_reset(host, 0, 0);
if (us->fflags & US_FL_SCM_MULT_TARG) {
for (i = 1; i < host->max_id; ++i)
scsi_report_device_reset(host, 0, i);
}
}
void usb_stor_report_bus_reset(struct us_data *us)
{
struct Scsi_Host *host = us_to_host(us);
scsi_lock(host);
scsi_report_bus_reset(host, 0);
scsi_unlock(host);
}
static int write_info(struct Scsi_Host *host, char *buffer, int length)
{
return length;
}
static int show_info (struct seq_file *m, struct Scsi_Host *host)
{
struct us_data *us = host_to_us(host);
const char *string;
seq_printf(m, " Host scsi%d: usb-storage\n", host->host_no);
if (us->pusb_dev->manufacturer)
string = us->pusb_dev->manufacturer;
else if (us->unusual_dev->vendorName)
string = us->unusual_dev->vendorName;
else
string = "Unknown";
seq_printf(m, " Vendor: %s\n", string);
if (us->pusb_dev->product)
string = us->pusb_dev->product;
else if (us->unusual_dev->productName)
string = us->unusual_dev->productName;
else
string = "Unknown";
seq_printf(m, " Product: %s\n", string);
if (us->pusb_dev->serial)
string = us->pusb_dev->serial;
else
string = "None";
seq_printf(m, "Serial Number: %s\n", string);
seq_printf(m, " Protocol: %s\n", us->protocol_name);
seq_printf(m, " Transport: %s\n", us->transport_name);
seq_printf(m, " Quirks:");
#define US_FLAG(name, value) \
if (us->fflags & value) seq_printf(m, " " #name);
US_DO_ALL_FLAGS
#undef US_FLAG
seq_putc(m, '\n');
return 0;
}
static ssize_t max_sectors_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
return sprintf(buf, "%u\n", queue_max_hw_sectors(sdev->request_queue));
}
static ssize_t max_sectors_store(struct device *dev, struct device_attribute *attr, const char *buf,
size_t count)
{
struct scsi_device *sdev = to_scsi_device(dev);
unsigned short ms;
if (sscanf(buf, "%hu", &ms) > 0) {
blk_queue_max_hw_sectors(sdev->request_queue, ms);
return count;
}
return -EINVAL;
}
void usb_stor_host_template_init(struct scsi_host_template *sht,
const char *name, struct module *owner)
{
*sht = usb_stor_host_template;
sht->name = name;
sht->proc_name = name;
sht->module = owner;
}
