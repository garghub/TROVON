static inline char mon_text_get_setup(struct mon_event_text *ep,
struct urb *urb, char ev_type, struct mon_bus *mbus)
{
if (ep->xfertype != USB_ENDPOINT_XFER_CONTROL || ev_type != 'S')
return '-';
if (urb->setup_packet == NULL)
return 'Z';
memcpy(ep->setup, urb->setup_packet, SETUP_MAX);
return 0;
}
static inline char mon_text_get_data(struct mon_event_text *ep, struct urb *urb,
int len, char ev_type, struct mon_bus *mbus)
{
void *src;
if (len <= 0)
return 'L';
if (len >= DATA_MAX)
len = DATA_MAX;
if (ep->is_in) {
if (ev_type != 'C')
return '<';
} else {
if (ev_type != 'S')
return '>';
}
if (urb->num_sgs == 0) {
src = urb->transfer_buffer;
if (src == NULL)
return 'Z';
} else {
struct scatterlist *sg = urb->sg;
if (PageHighMem(sg_page(sg)))
return 'D';
len = min_t(int, sg->length, len);
src = sg_virt(sg);
}
memcpy(ep->data, src, len);
return 0;
}
static inline unsigned int mon_get_timestamp(void)
{
struct timeval tval;
unsigned int stamp;
do_gettimeofday(&tval);
stamp = tval.tv_sec & 0xFFF;
stamp = stamp * 1000000 + tval.tv_usec;
return stamp;
}
static void mon_text_event(struct mon_reader_text *rp, struct urb *urb,
char ev_type, int status)
{
struct mon_event_text *ep;
unsigned int stamp;
struct usb_iso_packet_descriptor *fp;
struct mon_iso_desc *dp;
int i, ndesc;
stamp = mon_get_timestamp();
if (rp->nevents >= EVENT_MAX ||
(ep = kmem_cache_alloc(rp->e_slab, GFP_ATOMIC)) == NULL) {
rp->r.m_bus->cnt_text_lost++;
return;
}
ep->type = ev_type;
ep->id = (unsigned long) urb;
ep->busnum = urb->dev->bus->busnum;
ep->devnum = urb->dev->devnum;
ep->epnum = usb_endpoint_num(&urb->ep->desc);
ep->xfertype = usb_endpoint_type(&urb->ep->desc);
ep->is_in = usb_urb_dir_in(urb);
ep->tstamp = stamp;
ep->length = (ev_type == 'S') ?
urb->transfer_buffer_length : urb->actual_length;
ep->status = status;
if (ep->xfertype == USB_ENDPOINT_XFER_INT) {
ep->interval = urb->interval;
} else if (ep->xfertype == USB_ENDPOINT_XFER_ISOC) {
ep->interval = urb->interval;
ep->start_frame = urb->start_frame;
ep->error_count = urb->error_count;
}
ep->numdesc = urb->number_of_packets;
if (ep->xfertype == USB_ENDPOINT_XFER_ISOC &&
urb->number_of_packets > 0) {
if ((ndesc = urb->number_of_packets) > ISODESC_MAX)
ndesc = ISODESC_MAX;
fp = urb->iso_frame_desc;
dp = ep->isodesc;
for (i = 0; i < ndesc; i++) {
dp->status = fp->status;
dp->offset = fp->offset;
dp->length = (ev_type == 'S') ?
fp->length : fp->actual_length;
fp++;
dp++;
}
if (ev_type == 'C')
ep->length = urb->transfer_buffer_length;
}
ep->setup_flag = mon_text_get_setup(ep, urb, ev_type, rp->r.m_bus);
ep->data_flag = mon_text_get_data(ep, urb, ep->length, ev_type,
rp->r.m_bus);
rp->nevents++;
list_add_tail(&ep->e_link, &rp->e_list);
wake_up(&rp->wait);
}
static void mon_text_submit(void *data, struct urb *urb)
{
struct mon_reader_text *rp = data;
mon_text_event(rp, urb, 'S', -EINPROGRESS);
}
static void mon_text_complete(void *data, struct urb *urb, int status)
{
struct mon_reader_text *rp = data;
mon_text_event(rp, urb, 'C', status);
}
static void mon_text_error(void *data, struct urb *urb, int error)
{
struct mon_reader_text *rp = data;
struct mon_event_text *ep;
if (rp->nevents >= EVENT_MAX ||
(ep = kmem_cache_alloc(rp->e_slab, GFP_ATOMIC)) == NULL) {
rp->r.m_bus->cnt_text_lost++;
return;
}
ep->type = 'E';
ep->id = (unsigned long) urb;
ep->busnum = urb->dev->bus->busnum;
ep->devnum = urb->dev->devnum;
ep->epnum = usb_endpoint_num(&urb->ep->desc);
ep->xfertype = usb_endpoint_type(&urb->ep->desc);
ep->is_in = usb_urb_dir_in(urb);
ep->tstamp = mon_get_timestamp();
ep->length = 0;
ep->status = error;
ep->setup_flag = '-';
ep->data_flag = 'E';
rp->nevents++;
list_add_tail(&ep->e_link, &rp->e_list);
wake_up(&rp->wait);
}
static struct mon_event_text *mon_text_fetch(struct mon_reader_text *rp,
struct mon_bus *mbus)
{
struct list_head *p;
unsigned long flags;
spin_lock_irqsave(&mbus->lock, flags);
if (list_empty(&rp->e_list)) {
spin_unlock_irqrestore(&mbus->lock, flags);
return NULL;
}
p = rp->e_list.next;
list_del(p);
--rp->nevents;
spin_unlock_irqrestore(&mbus->lock, flags);
return list_entry(p, struct mon_event_text, e_link);
}
static int mon_text_open(struct inode *inode, struct file *file)
{
struct mon_bus *mbus;
struct mon_reader_text *rp;
int rc;
mutex_lock(&mon_lock);
mbus = inode->i_private;
rp = kzalloc(sizeof(struct mon_reader_text), GFP_KERNEL);
if (rp == NULL) {
rc = -ENOMEM;
goto err_alloc;
}
INIT_LIST_HEAD(&rp->e_list);
init_waitqueue_head(&rp->wait);
mutex_init(&rp->printf_lock);
rp->printf_size = PRINTF_DFL;
rp->printf_buf = kmalloc(rp->printf_size, GFP_KERNEL);
if (rp->printf_buf == NULL) {
rc = -ENOMEM;
goto err_alloc_pr;
}
rp->r.m_bus = mbus;
rp->r.r_data = rp;
rp->r.rnf_submit = mon_text_submit;
rp->r.rnf_error = mon_text_error;
rp->r.rnf_complete = mon_text_complete;
snprintf(rp->slab_name, SLAB_NAME_SZ, "mon_text_%p", rp);
rp->e_slab = kmem_cache_create(rp->slab_name,
sizeof(struct mon_event_text), sizeof(long), 0,
mon_text_ctor);
if (rp->e_slab == NULL) {
rc = -ENOMEM;
goto err_slab;
}
mon_reader_add(mbus, &rp->r);
file->private_data = rp;
mutex_unlock(&mon_lock);
return 0;
err_slab:
kfree(rp->printf_buf);
err_alloc_pr:
kfree(rp);
err_alloc:
mutex_unlock(&mon_lock);
return rc;
}
static ssize_t mon_text_read_t(struct file *file, char __user *buf,
size_t nbytes, loff_t *ppos)
{
struct mon_reader_text *rp = file->private_data;
struct mon_event_text *ep;
struct mon_text_ptr ptr;
if (IS_ERR(ep = mon_text_read_wait(rp, file)))
return PTR_ERR(ep);
mutex_lock(&rp->printf_lock);
ptr.cnt = 0;
ptr.pbuf = rp->printf_buf;
ptr.limit = rp->printf_size;
mon_text_read_head_t(rp, &ptr, ep);
mon_text_read_statset(rp, &ptr, ep);
ptr.cnt += snprintf(ptr.pbuf + ptr.cnt, ptr.limit - ptr.cnt,
" %d", ep->length);
mon_text_read_data(rp, &ptr, ep);
if (copy_to_user(buf, rp->printf_buf, ptr.cnt))
ptr.cnt = -EFAULT;
mutex_unlock(&rp->printf_lock);
kmem_cache_free(rp->e_slab, ep);
return ptr.cnt;
}
static ssize_t mon_text_read_u(struct file *file, char __user *buf,
size_t nbytes, loff_t *ppos)
{
struct mon_reader_text *rp = file->private_data;
struct mon_event_text *ep;
struct mon_text_ptr ptr;
if (IS_ERR(ep = mon_text_read_wait(rp, file)))
return PTR_ERR(ep);
mutex_lock(&rp->printf_lock);
ptr.cnt = 0;
ptr.pbuf = rp->printf_buf;
ptr.limit = rp->printf_size;
mon_text_read_head_u(rp, &ptr, ep);
if (ep->type == 'E') {
mon_text_read_statset(rp, &ptr, ep);
} else if (ep->xfertype == USB_ENDPOINT_XFER_ISOC) {
mon_text_read_isostat(rp, &ptr, ep);
mon_text_read_isodesc(rp, &ptr, ep);
} else if (ep->xfertype == USB_ENDPOINT_XFER_INT) {
mon_text_read_intstat(rp, &ptr, ep);
} else {
mon_text_read_statset(rp, &ptr, ep);
}
ptr.cnt += snprintf(ptr.pbuf + ptr.cnt, ptr.limit - ptr.cnt,
" %d", ep->length);
mon_text_read_data(rp, &ptr, ep);
if (copy_to_user(buf, rp->printf_buf, ptr.cnt))
ptr.cnt = -EFAULT;
mutex_unlock(&rp->printf_lock);
kmem_cache_free(rp->e_slab, ep);
return ptr.cnt;
}
static struct mon_event_text *mon_text_read_wait(struct mon_reader_text *rp,
struct file *file)
{
struct mon_bus *mbus = rp->r.m_bus;
DECLARE_WAITQUEUE(waita, current);
struct mon_event_text *ep;
add_wait_queue(&rp->wait, &waita);
set_current_state(TASK_INTERRUPTIBLE);
while ((ep = mon_text_fetch(rp, mbus)) == NULL) {
if (file->f_flags & O_NONBLOCK) {
set_current_state(TASK_RUNNING);
remove_wait_queue(&rp->wait, &waita);
return ERR_PTR(-EWOULDBLOCK);
}
schedule();
if (signal_pending(current)) {
remove_wait_queue(&rp->wait, &waita);
return ERR_PTR(-EINTR);
}
set_current_state(TASK_INTERRUPTIBLE);
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&rp->wait, &waita);
return ep;
}
static void mon_text_read_head_t(struct mon_reader_text *rp,
struct mon_text_ptr *p, const struct mon_event_text *ep)
{
char udir, utype;
udir = (ep->is_in ? 'i' : 'o');
switch (ep->xfertype) {
case USB_ENDPOINT_XFER_ISOC: utype = 'Z'; break;
case USB_ENDPOINT_XFER_INT: utype = 'I'; break;
case USB_ENDPOINT_XFER_CONTROL: utype = 'C'; break;
default: utype = 'B';
}
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
"%lx %u %c %c%c:%03u:%02u",
ep->id, ep->tstamp, ep->type,
utype, udir, ep->devnum, ep->epnum);
}
static void mon_text_read_head_u(struct mon_reader_text *rp,
struct mon_text_ptr *p, const struct mon_event_text *ep)
{
char udir, utype;
udir = (ep->is_in ? 'i' : 'o');
switch (ep->xfertype) {
case USB_ENDPOINT_XFER_ISOC: utype = 'Z'; break;
case USB_ENDPOINT_XFER_INT: utype = 'I'; break;
case USB_ENDPOINT_XFER_CONTROL: utype = 'C'; break;
default: utype = 'B';
}
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
"%lx %u %c %c%c:%d:%03u:%u",
ep->id, ep->tstamp, ep->type,
utype, udir, ep->busnum, ep->devnum, ep->epnum);
}
static void mon_text_read_statset(struct mon_reader_text *rp,
struct mon_text_ptr *p, const struct mon_event_text *ep)
{
if (ep->setup_flag == 0) {
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" s %02x %02x %04x %04x %04x",
ep->setup[0],
ep->setup[1],
(ep->setup[3] << 8) | ep->setup[2],
(ep->setup[5] << 8) | ep->setup[4],
(ep->setup[7] << 8) | ep->setup[6]);
} else if (ep->setup_flag != '-') {
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" %c __ __ ____ ____ ____", ep->setup_flag);
} else {
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" %d", ep->status);
}
}
static void mon_text_read_intstat(struct mon_reader_text *rp,
struct mon_text_ptr *p, const struct mon_event_text *ep)
{
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" %d:%d", ep->status, ep->interval);
}
static void mon_text_read_isostat(struct mon_reader_text *rp,
struct mon_text_ptr *p, const struct mon_event_text *ep)
{
if (ep->type == 'S') {
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" %d:%d:%d", ep->status, ep->interval, ep->start_frame);
} else {
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" %d:%d:%d:%d",
ep->status, ep->interval, ep->start_frame, ep->error_count);
}
}
static void mon_text_read_isodesc(struct mon_reader_text *rp,
struct mon_text_ptr *p, const struct mon_event_text *ep)
{
int ndesc;
int i;
const struct mon_iso_desc *dp;
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" %d", ep->numdesc);
ndesc = ep->numdesc;
if (ndesc > ISODESC_MAX)
ndesc = ISODESC_MAX;
if (ndesc < 0)
ndesc = 0;
dp = ep->isodesc;
for (i = 0; i < ndesc; i++) {
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" %d:%u:%u", dp->status, dp->offset, dp->length);
dp++;
}
}
static void mon_text_read_data(struct mon_reader_text *rp,
struct mon_text_ptr *p, const struct mon_event_text *ep)
{
int data_len, i;
if ((data_len = ep->length) > 0) {
if (ep->data_flag == 0) {
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" =");
if (data_len >= DATA_MAX)
data_len = DATA_MAX;
for (i = 0; i < data_len; i++) {
if (i % 4 == 0) {
p->cnt += snprintf(p->pbuf + p->cnt,
p->limit - p->cnt,
" ");
}
p->cnt += snprintf(p->pbuf + p->cnt,
p->limit - p->cnt,
"%02x", ep->data[i]);
}
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
"\n");
} else {
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt,
" %c\n", ep->data_flag);
}
} else {
p->cnt += snprintf(p->pbuf + p->cnt, p->limit - p->cnt, "\n");
}
}
static int mon_text_release(struct inode *inode, struct file *file)
{
struct mon_reader_text *rp = file->private_data;
struct mon_bus *mbus;
struct list_head *p;
struct mon_event_text *ep;
mutex_lock(&mon_lock);
mbus = inode->i_private;
if (mbus->nreaders <= 0) {
printk(KERN_ERR TAG ": consistency error on close\n");
mutex_unlock(&mon_lock);
return 0;
}
mon_reader_del(mbus, &rp->r);
while (!list_empty(&rp->e_list)) {
p = rp->e_list.next;
ep = list_entry(p, struct mon_event_text, e_link);
list_del(p);
--rp->nevents;
kmem_cache_free(rp->e_slab, ep);
}
kmem_cache_destroy(rp->e_slab);
kfree(rp->printf_buf);
kfree(rp);
mutex_unlock(&mon_lock);
return 0;
}
int mon_text_add(struct mon_bus *mbus, const struct usb_bus *ubus)
{
struct dentry *d;
enum { NAMESZ = 10 };
char name[NAMESZ];
int busnum = ubus? ubus->busnum: 0;
int rc;
if (ubus != NULL) {
rc = snprintf(name, NAMESZ, "%dt", busnum);
if (rc <= 0 || rc >= NAMESZ)
goto err_print_t;
d = debugfs_create_file(name, 0600, mon_dir, mbus,
&mon_fops_text_t);
if (d == NULL)
goto err_create_t;
mbus->dent_t = d;
}
rc = snprintf(name, NAMESZ, "%du", busnum);
if (rc <= 0 || rc >= NAMESZ)
goto err_print_u;
d = debugfs_create_file(name, 0600, mon_dir, mbus, &mon_fops_text_u);
if (d == NULL)
goto err_create_u;
mbus->dent_u = d;
rc = snprintf(name, NAMESZ, "%ds", busnum);
if (rc <= 0 || rc >= NAMESZ)
goto err_print_s;
d = debugfs_create_file(name, 0600, mon_dir, mbus, &mon_fops_stat);
if (d == NULL)
goto err_create_s;
mbus->dent_s = d;
return 1;
err_create_s:
err_print_s:
debugfs_remove(mbus->dent_u);
mbus->dent_u = NULL;
err_create_u:
err_print_u:
if (ubus != NULL) {
debugfs_remove(mbus->dent_t);
mbus->dent_t = NULL;
}
err_create_t:
err_print_t:
return 0;
}
void mon_text_del(struct mon_bus *mbus)
{
debugfs_remove(mbus->dent_u);
if (mbus->dent_t != NULL)
debugfs_remove(mbus->dent_t);
debugfs_remove(mbus->dent_s);
}
static void mon_text_ctor(void *mem)
{
memset(mem, 0xe5, sizeof(struct mon_event_text));
}
int __init mon_text_init(void)
{
struct dentry *mondir;
mondir = debugfs_create_dir("usbmon", usb_debug_root);
if (IS_ERR(mondir)) {
printk(KERN_NOTICE TAG ": debugfs is not available\n");
return -ENODEV;
}
if (mondir == NULL) {
printk(KERN_NOTICE TAG ": unable to create usbmon directory\n");
return -ENODEV;
}
mon_dir = mondir;
return 0;
}
void mon_text_exit(void)
{
debugfs_remove(mon_dir);
}
