static int dasd_eer_get_free_bytes(struct eerbuffer *eerb)
{
if (eerb->head < eerb->tail)
return eerb->tail - eerb->head - 1;
return eerb->buffersize - eerb->head + eerb->tail -1;
}
static int dasd_eer_get_filled_bytes(struct eerbuffer *eerb)
{
if (eerb->head >= eerb->tail)
return eerb->head - eerb->tail;
return eerb->buffersize - eerb->tail + eerb->head;
}
static void dasd_eer_write_buffer(struct eerbuffer *eerb,
char *data, int count)
{
unsigned long headindex,localhead;
unsigned long rest, len;
char *nextdata;
nextdata = data;
rest = count;
while (rest > 0) {
headindex = eerb->head / PAGE_SIZE;
localhead = eerb->head % PAGE_SIZE;
len = min(rest, PAGE_SIZE - localhead);
memcpy(eerb->buffer[headindex]+localhead, nextdata, len);
nextdata += len;
rest -= len;
eerb->head += len;
if (eerb->head == eerb->buffersize)
eerb->head = 0;
BUG_ON(eerb->head > eerb->buffersize);
}
}
static int dasd_eer_read_buffer(struct eerbuffer *eerb, char *data, int count)
{
unsigned long tailindex,localtail;
unsigned long rest, len, finalcount;
char *nextdata;
finalcount = min(count, dasd_eer_get_filled_bytes(eerb));
nextdata = data;
rest = finalcount;
while (rest > 0) {
tailindex = eerb->tail / PAGE_SIZE;
localtail = eerb->tail % PAGE_SIZE;
len = min(rest, PAGE_SIZE - localtail);
memcpy(nextdata, eerb->buffer[tailindex] + localtail, len);
nextdata += len;
rest -= len;
eerb->tail += len;
if (eerb->tail == eerb->buffersize)
eerb->tail = 0;
BUG_ON(eerb->tail > eerb->buffersize);
}
return finalcount;
}
static int dasd_eer_start_record(struct eerbuffer *eerb, int count)
{
int tailcount;
if (count + sizeof(count) > eerb->buffersize)
return -ENOMEM;
while (dasd_eer_get_free_bytes(eerb) < count + sizeof(count)) {
if (eerb->residual > 0) {
eerb->tail += eerb->residual;
if (eerb->tail >= eerb->buffersize)
eerb->tail -= eerb->buffersize;
eerb->residual = -1;
}
dasd_eer_read_buffer(eerb, (char *) &tailcount,
sizeof(tailcount));
eerb->tail += tailcount;
if (eerb->tail >= eerb->buffersize)
eerb->tail -= eerb->buffersize;
}
dasd_eer_write_buffer(eerb, (char*) &count, sizeof(count));
return 0;
}
static void dasd_eer_free_buffer_pages(char **buf, int no_pages)
{
int i;
for (i = 0; i < no_pages; i++)
free_page((unsigned long) buf[i]);
}
static int dasd_eer_allocate_buffer_pages(char **buf, int no_pages)
{
int i;
for (i = 0; i < no_pages; i++) {
buf[i] = (char *) get_zeroed_page(GFP_KERNEL);
if (!buf[i]) {
dasd_eer_free_buffer_pages(buf, i);
return -ENOMEM;
}
}
return 0;
}
static void dasd_eer_write_standard_trigger(struct dasd_device *device,
struct dasd_ccw_req *cqr,
int trigger)
{
struct dasd_ccw_req *temp_cqr;
int data_size;
struct timeval tv;
struct dasd_eer_header header;
unsigned long flags;
struct eerbuffer *eerb;
char *sense;
data_size = 0;
for (temp_cqr = cqr; temp_cqr; temp_cqr = temp_cqr->refers)
if (dasd_get_sense(&temp_cqr->irb))
data_size += 32;
header.total_size = sizeof(header) + data_size + 4;
header.trigger = trigger;
do_gettimeofday(&tv);
header.tv_sec = tv.tv_sec;
header.tv_usec = tv.tv_usec;
strncpy(header.busid, dev_name(&device->cdev->dev),
DASD_EER_BUSID_SIZE);
spin_lock_irqsave(&bufferlock, flags);
list_for_each_entry(eerb, &bufferlist, list) {
dasd_eer_start_record(eerb, header.total_size);
dasd_eer_write_buffer(eerb, (char *) &header, sizeof(header));
for (temp_cqr = cqr; temp_cqr; temp_cqr = temp_cqr->refers) {
sense = dasd_get_sense(&temp_cqr->irb);
if (sense)
dasd_eer_write_buffer(eerb, sense, 32);
}
dasd_eer_write_buffer(eerb, "EOR", 4);
}
spin_unlock_irqrestore(&bufferlock, flags);
wake_up_interruptible(&dasd_eer_read_wait_queue);
}
static void dasd_eer_write_snss_trigger(struct dasd_device *device,
struct dasd_ccw_req *cqr,
int trigger)
{
int data_size;
int snss_rc;
struct timeval tv;
struct dasd_eer_header header;
unsigned long flags;
struct eerbuffer *eerb;
snss_rc = (cqr->status == DASD_CQR_DONE) ? 0 : -EIO;
if (snss_rc)
data_size = 0;
else
data_size = SNSS_DATA_SIZE;
header.total_size = sizeof(header) + data_size + 4;
header.trigger = DASD_EER_STATECHANGE;
do_gettimeofday(&tv);
header.tv_sec = tv.tv_sec;
header.tv_usec = tv.tv_usec;
strncpy(header.busid, dev_name(&device->cdev->dev),
DASD_EER_BUSID_SIZE);
spin_lock_irqsave(&bufferlock, flags);
list_for_each_entry(eerb, &bufferlist, list) {
dasd_eer_start_record(eerb, header.total_size);
dasd_eer_write_buffer(eerb, (char *) &header , sizeof(header));
if (!snss_rc)
dasd_eer_write_buffer(eerb, cqr->data, SNSS_DATA_SIZE);
dasd_eer_write_buffer(eerb, "EOR", 4);
}
spin_unlock_irqrestore(&bufferlock, flags);
wake_up_interruptible(&dasd_eer_read_wait_queue);
}
void dasd_eer_write(struct dasd_device *device, struct dasd_ccw_req *cqr,
unsigned int id)
{
if (!device->eer_cqr)
return;
switch (id) {
case DASD_EER_FATALERROR:
case DASD_EER_PPRCSUSPEND:
dasd_eer_write_standard_trigger(device, cqr, id);
break;
case DASD_EER_NOPATH:
dasd_eer_write_standard_trigger(device, NULL, id);
break;
case DASD_EER_STATECHANGE:
dasd_eer_write_snss_trigger(device, cqr, id);
break;
default:
dasd_eer_write_standard_trigger(device, NULL, id);
break;
}
}
void dasd_eer_snss(struct dasd_device *device)
{
struct dasd_ccw_req *cqr;
cqr = device->eer_cqr;
if (!cqr)
return;
if (test_and_set_bit(DASD_FLAG_EER_IN_USE, &device->flags)) {
set_bit(DASD_FLAG_EER_SNSS, &device->flags);
return;
}
clear_bit(DASD_FLAG_EER_SNSS, &device->flags);
cqr->status = DASD_CQR_QUEUED;
list_add(&cqr->devlist, &device->ccw_queue);
dasd_schedule_device_bh(device);
}
static void dasd_eer_snss_cb(struct dasd_ccw_req *cqr, void *data)
{
struct dasd_device *device = cqr->startdev;
unsigned long flags;
dasd_eer_write(device, cqr, DASD_EER_STATECHANGE);
spin_lock_irqsave(get_ccwdev_lock(device->cdev), flags);
if (device->eer_cqr == cqr) {
clear_bit(DASD_FLAG_EER_IN_USE, &device->flags);
if (test_bit(DASD_FLAG_EER_SNSS, &device->flags))
dasd_eer_snss(device);
cqr = NULL;
}
spin_unlock_irqrestore(get_ccwdev_lock(device->cdev), flags);
if (cqr)
dasd_kfree_request(cqr, device);
}
int dasd_eer_enable(struct dasd_device *device)
{
struct dasd_ccw_req *cqr;
unsigned long flags;
struct ccw1 *ccw;
if (device->eer_cqr)
return 0;
if (!device->discipline || strcmp(device->discipline->name, "ECKD"))
return -EPERM;
cqr = dasd_kmalloc_request(DASD_ECKD_MAGIC, 1 ,
SNSS_DATA_SIZE, device);
if (IS_ERR(cqr))
return -ENOMEM;
cqr->startdev = device;
cqr->retries = 255;
cqr->expires = 10 * HZ;
clear_bit(DASD_CQR_FLAGS_USE_ERP, &cqr->flags);
set_bit(DASD_CQR_ALLOW_SLOCK, &cqr->flags);
ccw = cqr->cpaddr;
ccw->cmd_code = DASD_ECKD_CCW_SNSS;
ccw->count = SNSS_DATA_SIZE;
ccw->flags = 0;
ccw->cda = (__u32)(addr_t) cqr->data;
cqr->buildclk = get_clock();
cqr->status = DASD_CQR_FILLED;
cqr->callback = dasd_eer_snss_cb;
spin_lock_irqsave(get_ccwdev_lock(device->cdev), flags);
if (!device->eer_cqr) {
device->eer_cqr = cqr;
cqr = NULL;
}
spin_unlock_irqrestore(get_ccwdev_lock(device->cdev), flags);
if (cqr)
dasd_kfree_request(cqr, device);
return 0;
}
void dasd_eer_disable(struct dasd_device *device)
{
struct dasd_ccw_req *cqr;
unsigned long flags;
int in_use;
if (!device->eer_cqr)
return;
spin_lock_irqsave(get_ccwdev_lock(device->cdev), flags);
cqr = device->eer_cqr;
device->eer_cqr = NULL;
clear_bit(DASD_FLAG_EER_SNSS, &device->flags);
in_use = test_and_clear_bit(DASD_FLAG_EER_IN_USE, &device->flags);
spin_unlock_irqrestore(get_ccwdev_lock(device->cdev), flags);
if (cqr && !in_use)
dasd_kfree_request(cqr, device);
}
static int dasd_eer_open(struct inode *inp, struct file *filp)
{
struct eerbuffer *eerb;
unsigned long flags;
eerb = kzalloc(sizeof(struct eerbuffer), GFP_KERNEL);
if (!eerb)
return -ENOMEM;
eerb->buffer_page_count = eer_pages;
if (eerb->buffer_page_count < 1 ||
eerb->buffer_page_count > INT_MAX / PAGE_SIZE) {
kfree(eerb);
DBF_EVENT(DBF_WARNING, "can't open device since module "
"parameter eer_pages is smaller than 1 or"
" bigger than %d", (int)(INT_MAX / PAGE_SIZE));
return -EINVAL;
}
eerb->buffersize = eerb->buffer_page_count * PAGE_SIZE;
eerb->buffer = kmalloc(eerb->buffer_page_count * sizeof(char *),
GFP_KERNEL);
if (!eerb->buffer) {
kfree(eerb);
return -ENOMEM;
}
if (dasd_eer_allocate_buffer_pages(eerb->buffer,
eerb->buffer_page_count)) {
kfree(eerb->buffer);
kfree(eerb);
return -ENOMEM;
}
filp->private_data = eerb;
spin_lock_irqsave(&bufferlock, flags);
list_add(&eerb->list, &bufferlist);
spin_unlock_irqrestore(&bufferlock, flags);
return nonseekable_open(inp,filp);
}
static int dasd_eer_close(struct inode *inp, struct file *filp)
{
struct eerbuffer *eerb;
unsigned long flags;
eerb = (struct eerbuffer *) filp->private_data;
spin_lock_irqsave(&bufferlock, flags);
list_del(&eerb->list);
spin_unlock_irqrestore(&bufferlock, flags);
dasd_eer_free_buffer_pages(eerb->buffer, eerb->buffer_page_count);
kfree(eerb->buffer);
kfree(eerb);
return 0;
}
static ssize_t dasd_eer_read(struct file *filp, char __user *buf,
size_t count, loff_t *ppos)
{
int tc,rc;
int tailcount,effective_count;
unsigned long flags;
struct eerbuffer *eerb;
eerb = (struct eerbuffer *) filp->private_data;
if (mutex_lock_interruptible(&readbuffer_mutex))
return -ERESTARTSYS;
spin_lock_irqsave(&bufferlock, flags);
if (eerb->residual < 0) {
eerb->residual = 0;
spin_unlock_irqrestore(&bufferlock, flags);
mutex_unlock(&readbuffer_mutex);
return -EIO;
} else if (eerb->residual > 0) {
effective_count = min(eerb->residual, (int) count);
eerb->residual -= effective_count;
} else {
tc = 0;
while (!tc) {
tc = dasd_eer_read_buffer(eerb, (char *) &tailcount,
sizeof(tailcount));
if (!tc) {
spin_unlock_irqrestore(&bufferlock, flags);
mutex_unlock(&readbuffer_mutex);
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
rc = wait_event_interruptible(
dasd_eer_read_wait_queue,
eerb->head != eerb->tail);
if (rc)
return rc;
if (mutex_lock_interruptible(&readbuffer_mutex))
return -ERESTARTSYS;
spin_lock_irqsave(&bufferlock, flags);
}
}
WARN_ON(tc != sizeof(tailcount));
effective_count = min(tailcount,(int)count);
eerb->residual = tailcount - effective_count;
}
tc = dasd_eer_read_buffer(eerb, readbuffer, effective_count);
WARN_ON(tc != effective_count);
spin_unlock_irqrestore(&bufferlock, flags);
if (copy_to_user(buf, readbuffer, effective_count)) {
mutex_unlock(&readbuffer_mutex);
return -EFAULT;
}
mutex_unlock(&readbuffer_mutex);
return effective_count;
}
static unsigned int dasd_eer_poll(struct file *filp, poll_table *ptable)
{
unsigned int mask;
unsigned long flags;
struct eerbuffer *eerb;
eerb = (struct eerbuffer *) filp->private_data;
poll_wait(filp, &dasd_eer_read_wait_queue, ptable);
spin_lock_irqsave(&bufferlock, flags);
if (eerb->head != eerb->tail)
mask = POLLIN | POLLRDNORM ;
else
mask = 0;
spin_unlock_irqrestore(&bufferlock, flags);
return mask;
}
int __init dasd_eer_init(void)
{
int rc;
dasd_eer_dev = kzalloc(sizeof(*dasd_eer_dev), GFP_KERNEL);
if (!dasd_eer_dev)
return -ENOMEM;
dasd_eer_dev->minor = MISC_DYNAMIC_MINOR;
dasd_eer_dev->name = "dasd_eer";
dasd_eer_dev->fops = &dasd_eer_fops;
rc = misc_register(dasd_eer_dev);
if (rc) {
kfree(dasd_eer_dev);
dasd_eer_dev = NULL;
DBF_EVENT(DBF_ERR, "%s", "dasd_eer_init could not "
"register misc device");
return rc;
}
return 0;
}
void dasd_eer_exit(void)
{
if (dasd_eer_dev) {
misc_deregister(dasd_eer_dev);
kfree(dasd_eer_dev);
dasd_eer_dev = NULL;
}
}
