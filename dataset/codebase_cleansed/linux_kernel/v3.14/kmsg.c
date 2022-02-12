static int kmsg_open(struct inode * inode, struct file * file)
{
return do_syslog(SYSLOG_ACTION_OPEN, NULL, 0, SYSLOG_FROM_PROC);
}
static int kmsg_release(struct inode * inode, struct file * file)
{
(void) do_syslog(SYSLOG_ACTION_CLOSE, NULL, 0, SYSLOG_FROM_PROC);
return 0;
}
static ssize_t kmsg_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
if ((file->f_flags & O_NONBLOCK) &&
!do_syslog(SYSLOG_ACTION_SIZE_UNREAD, NULL, 0, SYSLOG_FROM_PROC))
return -EAGAIN;
return do_syslog(SYSLOG_ACTION_READ, buf, count, SYSLOG_FROM_PROC);
}
static unsigned int kmsg_poll(struct file *file, poll_table *wait)
{
poll_wait(file, &log_wait, wait);
if (do_syslog(SYSLOG_ACTION_SIZE_UNREAD, NULL, 0, SYSLOG_FROM_PROC))
return POLLIN | POLLRDNORM;
return 0;
}
static int __init proc_kmsg_init(void)
{
proc_create("kmsg", S_IRUSR, NULL, &proc_kmsg_operations);
return 0;
}
