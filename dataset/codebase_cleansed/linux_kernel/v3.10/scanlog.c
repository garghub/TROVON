static ssize_t scanlog_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
unsigned int *data = scanlog_buffer;
int status;
unsigned long len, off;
unsigned int wait_time;
if (count > RTAS_DATA_BUF_SIZE)
count = RTAS_DATA_BUF_SIZE;
if (count < 1024) {
printk(KERN_ERR "scanlog: cannot perform a small read (%ld)\n", count);
return -EINVAL;
}
if (!access_ok(VERIFY_WRITE, buf, count))
return -EFAULT;
for (;;) {
wait_time = 500;
spin_lock(&rtas_data_buf_lock);
memcpy(rtas_data_buf, data, RTAS_DATA_BUF_SIZE);
status = rtas_call(ibm_scan_log_dump, 2, 1, NULL,
(u32) __pa(rtas_data_buf), (u32) count);
memcpy(data, rtas_data_buf, RTAS_DATA_BUF_SIZE);
spin_unlock(&rtas_data_buf_lock);
pr_debug("scanlog: status=%d, data[0]=%x, data[1]=%x, " \
"data[2]=%x\n", status, data[0], data[1], data[2]);
switch (status) {
case SCANLOG_COMPLETE:
pr_debug("scanlog: hit eof\n");
return 0;
case SCANLOG_HWERROR:
pr_debug("scanlog: hardware error reading data\n");
return -EIO;
case SCANLOG_CONTINUE:
len = data[1];
off = data[2];
if (len > 0) {
if (copy_to_user(buf, ((char *)data)+off, len))
return -EFAULT;
return len;
}
break;
default:
wait_time = rtas_busy_delay_time(status);
if (!wait_time) {
printk(KERN_ERR "scanlog: unknown error " \
"from rtas: %d\n", status);
return -EIO;
}
}
msleep_interruptible(wait_time);
}
}
static ssize_t scanlog_write(struct file * file, const char __user * buf,
size_t count, loff_t *ppos)
{
char stkbuf[20];
int status;
if (count > 19) count = 19;
if (copy_from_user (stkbuf, buf, count)) {
return -EFAULT;
}
stkbuf[count] = 0;
if (buf) {
if (strncmp(stkbuf, "reset", 5) == 0) {
pr_debug("scanlog: reset scanlog\n");
status = rtas_call(ibm_scan_log_dump, 2, 1, NULL, 0, 0);
pr_debug("scanlog: rtas returns %d\n", status);
}
}
return count;
}
static int scanlog_open(struct inode * inode, struct file * file)
{
unsigned int *data = scanlog_buffer;
if (data[0] != 0) {
return -EBUSY;
}
data[0] = 0;
return 0;
}
static int scanlog_release(struct inode * inode, struct file * file)
{
unsigned int *data = scanlog_buffer;
data[0] = 0;
return 0;
}
static int __init scanlog_init(void)
{
struct proc_dir_entry *ent;
int err = -ENOMEM;
ibm_scan_log_dump = rtas_token("ibm,scan-log-dump");
if (ibm_scan_log_dump == RTAS_UNKNOWN_SERVICE)
return -ENODEV;
scanlog_buffer = kzalloc(RTAS_DATA_BUF_SIZE, GFP_KERNEL);
if (!scanlog_buffer)
goto err;
ent = proc_create("powerpc/rtas/scan-log-dump", S_IRUSR, NULL,
&scanlog_fops);
if (!ent)
goto err;
return 0;
err:
kfree(scanlog_buffer);
return err;
}
static void __exit scanlog_cleanup(void)
{
remove_proc_entry("powerpc/rtas/scan-log-dump", NULL);
kfree(scanlog_buffer);
}
