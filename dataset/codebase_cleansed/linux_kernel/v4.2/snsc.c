static irqreturn_t
scdrv_interrupt(int irq, void *subch_data)
{
struct subch_data_s *sd = subch_data;
unsigned long flags;
int status;
spin_lock_irqsave(&sd->sd_rlock, flags);
spin_lock(&sd->sd_wlock);
status = ia64_sn_irtr_intr(sd->sd_nasid, sd->sd_subch);
if (status > 0) {
if (status & SAL_IROUTER_INTR_RECV) {
wake_up(&sd->sd_rq);
}
if (status & SAL_IROUTER_INTR_XMIT) {
ia64_sn_irtr_intr_disable
(sd->sd_nasid, sd->sd_subch,
SAL_IROUTER_INTR_XMIT);
wake_up(&sd->sd_wq);
}
}
spin_unlock(&sd->sd_wlock);
spin_unlock_irqrestore(&sd->sd_rlock, flags);
return IRQ_HANDLED;
}
static int
scdrv_open(struct inode *inode, struct file *file)
{
struct sysctl_data_s *scd;
struct subch_data_s *sd;
int rv;
scd = container_of(inode->i_cdev, struct sysctl_data_s, scd_cdev);
sd = kzalloc(sizeof (struct subch_data_s), GFP_KERNEL);
if (sd == NULL) {
printk("%s: couldn't allocate subchannel data\n",
__func__);
return -ENOMEM;
}
sd->sd_nasid = scd->scd_nasid;
sd->sd_subch = ia64_sn_irtr_open(scd->scd_nasid);
if (sd->sd_subch < 0) {
kfree(sd);
printk("%s: couldn't allocate subchannel\n", __func__);
return -EBUSY;
}
spin_lock_init(&sd->sd_rlock);
spin_lock_init(&sd->sd_wlock);
init_waitqueue_head(&sd->sd_rq);
init_waitqueue_head(&sd->sd_wq);
sema_init(&sd->sd_rbs, 1);
sema_init(&sd->sd_wbs, 1);
file->private_data = sd;
mutex_lock(&scdrv_mutex);
rv = request_irq(SGI_UART_VECTOR, scdrv_interrupt,
IRQF_SHARED, SYSCTL_BASENAME, sd);
if (rv) {
ia64_sn_irtr_close(sd->sd_nasid, sd->sd_subch);
kfree(sd);
printk("%s: irq request failed (%d)\n", __func__, rv);
mutex_unlock(&scdrv_mutex);
return -EBUSY;
}
mutex_unlock(&scdrv_mutex);
return 0;
}
static int
scdrv_release(struct inode *inode, struct file *file)
{
struct subch_data_s *sd = (struct subch_data_s *) file->private_data;
int rv;
free_irq(SGI_UART_VECTOR, sd);
rv = ia64_sn_irtr_close(sd->sd_nasid, sd->sd_subch);
kfree(sd);
return rv;
}
static inline int
read_status_check(struct subch_data_s *sd, int *len)
{
return ia64_sn_irtr_recv(sd->sd_nasid, sd->sd_subch, sd->sd_rb, len);
}
static ssize_t
scdrv_read(struct file *file, char __user *buf, size_t count, loff_t *f_pos)
{
int status;
int len;
unsigned long flags;
struct subch_data_s *sd = (struct subch_data_s *) file->private_data;
if (down_trylock(&sd->sd_rbs)) {
if (file->f_flags & O_NONBLOCK) {
return -EAGAIN;
}
if (down_interruptible(&sd->sd_rbs)) {
return -ERESTARTSYS;
}
}
len = CHUNKSIZE;
spin_lock_irqsave(&sd->sd_rlock, flags);
status = read_status_check(sd, &len);
while (status < 0) {
DECLARE_WAITQUEUE(wait, current);
if (file->f_flags & O_NONBLOCK) {
spin_unlock_irqrestore(&sd->sd_rlock, flags);
up(&sd->sd_rbs);
return -EAGAIN;
}
len = CHUNKSIZE;
set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue(&sd->sd_rq, &wait);
spin_unlock_irqrestore(&sd->sd_rlock, flags);
schedule_timeout(msecs_to_jiffies(SCDRV_TIMEOUT));
remove_wait_queue(&sd->sd_rq, &wait);
if (signal_pending(current)) {
up(&sd->sd_rbs);
return -ERESTARTSYS;
}
spin_lock_irqsave(&sd->sd_rlock, flags);
status = read_status_check(sd, &len);
}
spin_unlock_irqrestore(&sd->sd_rlock, flags);
if (len > 0) {
if (count < len) {
pr_debug("%s: only accepting %d of %d bytes\n",
__func__, (int) count, len);
}
len = min((int) count, len);
if (copy_to_user(buf, sd->sd_rb, len))
len = -EFAULT;
}
up(&sd->sd_rbs);
return len;
}
static inline int
write_status_check(struct subch_data_s *sd, int count)
{
return ia64_sn_irtr_send(sd->sd_nasid, sd->sd_subch, sd->sd_wb, count);
}
static ssize_t
scdrv_write(struct file *file, const char __user *buf,
size_t count, loff_t *f_pos)
{
unsigned long flags;
int status;
struct subch_data_s *sd = (struct subch_data_s *) file->private_data;
if (down_trylock(&sd->sd_wbs)) {
if (file->f_flags & O_NONBLOCK) {
return -EAGAIN;
}
if (down_interruptible(&sd->sd_wbs)) {
return -ERESTARTSYS;
}
}
count = min((int) count, CHUNKSIZE);
if (copy_from_user(sd->sd_wb, buf, count)) {
up(&sd->sd_wbs);
return -EFAULT;
}
spin_lock_irqsave(&sd->sd_wlock, flags);
status = write_status_check(sd, count);
while (status <= 0) {
DECLARE_WAITQUEUE(wait, current);
if (file->f_flags & O_NONBLOCK) {
spin_unlock(&sd->sd_wlock);
up(&sd->sd_wbs);
return -EAGAIN;
}
set_current_state(TASK_INTERRUPTIBLE);
add_wait_queue(&sd->sd_wq, &wait);
spin_unlock_irqrestore(&sd->sd_wlock, flags);
schedule_timeout(msecs_to_jiffies(SCDRV_TIMEOUT));
remove_wait_queue(&sd->sd_wq, &wait);
if (signal_pending(current)) {
up(&sd->sd_wbs);
return -ERESTARTSYS;
}
spin_lock_irqsave(&sd->sd_wlock, flags);
status = write_status_check(sd, count);
}
spin_unlock_irqrestore(&sd->sd_wlock, flags);
up(&sd->sd_wbs);
if ((status >= 0) && (status < count)) {
pr_debug("Didn't accept the full chunk; %d of %d\n",
status, (int) count);
}
return status;
}
static unsigned int
scdrv_poll(struct file *file, struct poll_table_struct *wait)
{
unsigned int mask = 0;
int status = 0;
struct subch_data_s *sd = (struct subch_data_s *) file->private_data;
unsigned long flags;
poll_wait(file, &sd->sd_rq, wait);
poll_wait(file, &sd->sd_wq, wait);
spin_lock_irqsave(&sd->sd_rlock, flags);
spin_lock(&sd->sd_wlock);
status = ia64_sn_irtr_intr(sd->sd_nasid, sd->sd_subch);
spin_unlock(&sd->sd_wlock);
spin_unlock_irqrestore(&sd->sd_rlock, flags);
if (status > 0) {
if (status & SAL_IROUTER_INTR_RECV) {
mask |= POLLIN | POLLRDNORM;
}
if (status & SAL_IROUTER_INTR_XMIT) {
mask |= POLLOUT | POLLWRNORM;
}
}
return mask;
}
int __init
scdrv_init(void)
{
geoid_t geoid;
cnodeid_t cnode;
char devname[32];
char *devnamep;
struct sysctl_data_s *scd;
void *salbuf;
dev_t first_dev, dev;
nasid_t event_nasid;
if (!ia64_platform_is("sn2"))
return -ENODEV;
event_nasid = ia64_sn_get_console_nasid();
if (alloc_chrdev_region(&first_dev, 0, num_cnodes,
SYSCTL_BASENAME) < 0) {
printk("%s: failed to register SN system controller device\n",
__func__);
return -ENODEV;
}
snsc_class = class_create(THIS_MODULE, SYSCTL_BASENAME);
for (cnode = 0; cnode < num_cnodes; cnode++) {
geoid = cnodeid_get_geoid(cnode);
devnamep = devname;
format_module_id(devnamep, geo_module(geoid),
MODULE_FORMAT_BRIEF);
devnamep = devname + strlen(devname);
sprintf(devnamep, "^%d#%d", geo_slot(geoid),
geo_slab(geoid));
scd = kzalloc(sizeof (struct sysctl_data_s),
GFP_KERNEL);
if (!scd) {
printk("%s: failed to allocate device info"
"for %s/%s\n", __func__,
SYSCTL_BASENAME, devname);
continue;
}
scd->scd_nasid = cnodeid_to_nasid(cnode);
if (!(salbuf = kmalloc(SCDRV_BUFSZ, GFP_KERNEL))) {
printk("%s: failed to allocate driver buffer"
"(%s%s)\n", __func__,
SYSCTL_BASENAME, devname);
kfree(scd);
continue;
}
if (ia64_sn_irtr_init(scd->scd_nasid, salbuf,
SCDRV_BUFSZ) < 0) {
printk
("%s: failed to initialize SAL for"
" system controller communication"
" (%s/%s): outdated PROM?\n",
__func__, SYSCTL_BASENAME, devname);
kfree(scd);
kfree(salbuf);
continue;
}
dev = first_dev + cnode;
cdev_init(&scd->scd_cdev, &scdrv_fops);
if (cdev_add(&scd->scd_cdev, dev, 1)) {
printk("%s: failed to register system"
" controller device (%s%s)\n",
__func__, SYSCTL_BASENAME, devname);
kfree(scd);
kfree(salbuf);
continue;
}
device_create(snsc_class, NULL, dev, NULL,
"%s", devname);
ia64_sn_irtr_intr_enable(scd->scd_nasid,
0 ,
SAL_IROUTER_INTR_RECV);
if(scd->scd_nasid == event_nasid) {
scdrv_event_init(scd);
}
}
return 0;
}
