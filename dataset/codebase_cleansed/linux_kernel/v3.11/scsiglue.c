static const char *host_info(struct Scsi_Host *host)
{
return "SCSI emulation for USB Mass Storage devices";
}
static int slave_alloc(struct scsi_device *sdev)
{
struct us_data *us = host_to_us(sdev->host);
sdev->inquiry_len = 36;
blk_queue_update_dma_alignment(sdev->request_queue, (512 - 1));
if (us->subclass == USB_SC_UFI)
sdev->sdev_target->pdt_1f_for_no_lun = 1;
return 0;
}
static int slave_configure(struct scsi_device *sdev)
{
struct us_data *us = host_to_us(sdev->host);
if (us->fflags & (US_FL_MAX_SECTORS_64 | US_FL_MAX_SECTORS_MIN)) {
unsigned int max_sectors = 64;
if (us->fflags & US_FL_MAX_SECTORS_MIN)
max_sectors = PAGE_CACHE_SIZE >> 9;
if (queue_max_sectors(sdev->request_queue) > max_sectors)
blk_queue_max_hw_sectors(sdev->request_queue,
max_sectors);
}
if (sdev->type == TYPE_DISK) {
if (us->subclass != USB_SC_SCSI &&
us->subclass != USB_SC_CYP_ATACB)
sdev->use_10_for_ms = 1;
sdev->use_192_bytes_for_3f = 1;
if (us->fflags & US_FL_NO_WP_DETECT)
sdev->skip_ms_page_3f = 1;
sdev->skip_ms_page_8 = 1;
if (us->fflags & US_FL_FIX_CAPACITY)
sdev->fix_capacity = 1;
if (us->fflags & US_FL_CAPACITY_HEURISTICS)
sdev->guess_capacity = 1;
if (sdev->scsi_level > SCSI_2)
sdev->sdev_target->scsi_level = sdev->scsi_level
= SCSI_2;
sdev->retry_hwerror = 1;
sdev->allow_restart = 1;
sdev->last_sector_bug = 1;
} else {
sdev->use_10_for_ms = 1;
}
if ((us->protocol == USB_PR_CB || us->protocol == USB_PR_CBI) &&
sdev->scsi_level == SCSI_UNKNOWN)
us->max_lun = 0;
if (us->fflags & US_FL_NOT_LOCKABLE)
sdev->lockable = 0;
return 0;
}
static int queuecommand_lck(struct scsi_cmnd *srb,
void (*done)(struct scsi_cmnd *))
{
struct us_data *us = host_to_us(srb->device->host);
if (us->srb != NULL) {
return SCSI_MLQUEUE_HOST_BUSY;
}
if (test_bit(US_FLIDX_DISCONNECTING, &us->dflags)) {
pr_info("Fail command during disconnect\n");
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
mutex_lock(&(us->dev_mutex));
result = us->transport_reset(us);
mutex_unlock(&us->dev_mutex);
return result < 0 ? FAILED : SUCCESS;
}
static int bus_reset(struct scsi_cmnd *srb)
{
struct us_data *us = host_to_us(srb->device->host);
int result;
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
static int show_info(struct seq_file *m, struct Scsi_Host *host)
{
struct us_data *us = host_to_us(host);
const char *string;
SPRINTF(" Host scsi%d: usb-storage\n", host->host_no);
if (us->pusb_dev->manufacturer)
string = us->pusb_dev->manufacturer;
else if (us->unusual_dev->vendorName)
string = us->unusual_dev->vendorName;
else
string = "Unknown";
SPRINTF(" Vendor: %s\n", string);
if (us->pusb_dev->product)
string = us->pusb_dev->product;
else if (us->unusual_dev->productName)
string = us->unusual_dev->productName;
else
string = "Unknown";
SPRINTF(" Product: %s\n", string);
if (us->pusb_dev->serial)
string = us->pusb_dev->serial;
else
string = "None";
SPRINTF("Serial Number: %s\n", string);
SPRINTF(" Protocol: %s\n", us->protocol_name);
SPRINTF(" Transport: %s\n", us->transport_name);
SPRINTF(" Quirks:");
#define US_FLAG(name, value) \
do { \
if (us->fflags & value) \
SPRINTF(" " #name); \
} while (0);
US_DO_ALL_FLAGS
#undef US_FLAG
seq_putc(m, '\n');
return 0;
}
static ssize_t show_max_sectors(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct scsi_device *sdev = to_scsi_device(dev);
return sprintf(buf, "%u\n", queue_max_sectors(sdev->request_queue));
}
static ssize_t store_max_sectors(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct scsi_device *sdev = to_scsi_device(dev);
unsigned short ms;
if (sscanf(buf, "%hu", &ms) > 0 && ms <= SCSI_DEFAULT_MAX_SECTORS) {
blk_queue_max_hw_sectors(sdev->request_queue, ms);
return strlen(buf);
}
return -EINVAL;
}
unsigned int usb_stor_access_xfer_buf(struct us_data *us,
unsigned char *buffer, unsigned int buflen,
struct scsi_cmnd *srb, struct scatterlist **sgptr,
unsigned int *offset, enum xfer_buf_dir dir)
{
unsigned int cnt;
struct scatterlist *sg = *sgptr;
if (!sg)
sg = scsi_sglist(srb);
cnt = 0;
while (cnt < buflen && sg) {
struct page *page = sg_page(sg) +
((sg->offset + *offset) >> PAGE_SHIFT);
unsigned int poff = (sg->offset + *offset) & (PAGE_SIZE-1);
unsigned int sglen = sg->length - *offset;
if (sglen > buflen - cnt) {
sglen = buflen - cnt;
*offset += sglen;
} else {
*offset = 0;
sg = sg_next(sg);
}
while (sglen > 0) {
unsigned int plen = min(sglen,
(unsigned int)PAGE_SIZE - poff);
unsigned char *ptr = kmap(page);
if (dir == TO_XFER_BUF)
memcpy(ptr + poff, buffer + cnt, plen);
else
memcpy(buffer + cnt, ptr + poff, plen);
kunmap(page);
poff = 0;
++page;
cnt += plen;
sglen -= plen;
}
}
*sgptr = sg;
return cnt;
}
void usb_stor_set_xfer_buf(struct us_data *us, unsigned char *buffer,
unsigned int buflen, struct scsi_cmnd *srb, unsigned int dir)
{
unsigned int offset = 0;
struct scatterlist *sg = NULL;
buflen = min(buflen, scsi_bufflen(srb));
buflen = usb_stor_access_xfer_buf(us, buffer, buflen, srb,
&sg, &offset, dir);
if (buflen < scsi_bufflen(srb))
scsi_set_resid(srb, scsi_bufflen(srb) - buflen);
}
