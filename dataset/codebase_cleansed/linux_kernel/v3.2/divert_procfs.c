void
put_info_buffer(char *cp)
{
struct divert_info *ib;
unsigned long flags;
if (if_used <= 0)
return;
if (!cp)
return;
if (!*cp)
return;
if (!(ib = kmalloc(sizeof(struct divert_info) + strlen(cp), GFP_ATOMIC)))
return;
strcpy(ib->info_start, cp);
ib->next = NULL;
spin_lock_irqsave( &divert_info_lock, flags );
ib->usage_cnt = if_used;
if (!divert_info_head)
divert_info_head = ib;
else
divert_info_tail->next = ib;
divert_info_tail = ib;
while (divert_info_head->next) {
if ((divert_info_head->usage_cnt <= 0) &&
(divert_info_head->next->usage_cnt <= 0)) {
ib = divert_info_head;
divert_info_head = divert_info_head->next;
kfree(ib);
} else
break;
}
spin_unlock_irqrestore( &divert_info_lock, flags );
wake_up_interruptible(&(rd_queue));
}
static ssize_t
isdn_divert_read(struct file *file, char __user *buf, size_t count, loff_t * off)
{
struct divert_info *inf;
int len;
if (!*((struct divert_info **) file->private_data)) {
if (file->f_flags & O_NONBLOCK)
return -EAGAIN;
interruptible_sleep_on(&(rd_queue));
}
if (!(inf = *((struct divert_info **) file->private_data)))
return (0);
inf->usage_cnt--;
file->private_data = &inf->next;
if ((len = strlen(inf->info_start)) <= count) {
if (copy_to_user(buf, inf->info_start, len))
return -EFAULT;
*off += len;
return (len);
}
return (0);
}
static ssize_t
isdn_divert_write(struct file *file, const char __user *buf, size_t count, loff_t * off)
{
return (-ENODEV);
}
static unsigned int
isdn_divert_poll(struct file *file, poll_table * wait)
{
unsigned int mask = 0;
poll_wait(file, &(rd_queue), wait);
if (*((struct divert_info **) file->private_data)) {
mask |= POLLIN | POLLRDNORM;
}
return mask;
}
static int
isdn_divert_open(struct inode *ino, struct file *filep)
{
unsigned long flags;
spin_lock_irqsave( &divert_info_lock, flags );
if_used++;
if (divert_info_head)
filep->private_data = &(divert_info_tail->next);
else
filep->private_data = &divert_info_head;
spin_unlock_irqrestore( &divert_info_lock, flags );
return nonseekable_open(ino, filep);
}
static int
isdn_divert_close(struct inode *ino, struct file *filep)
{
struct divert_info *inf;
unsigned long flags;
spin_lock_irqsave( &divert_info_lock, flags );
if_used--;
inf = *((struct divert_info **) filep->private_data);
while (inf) {
inf->usage_cnt--;
inf = inf->next;
}
if (if_used <= 0)
while (divert_info_head) {
inf = divert_info_head;
divert_info_head = divert_info_head->next;
kfree(inf);
}
spin_unlock_irqrestore( &divert_info_lock, flags );
return (0);
}
static int isdn_divert_ioctl_unlocked(struct file *file, uint cmd, ulong arg)
{
divert_ioctl dioctl;
int i;
unsigned long flags;
divert_rule *rulep;
char *cp;
if (copy_from_user(&dioctl, (void __user *) arg, sizeof(dioctl)))
return -EFAULT;
switch (cmd) {
case IIOCGETVER:
dioctl.drv_version = DIVERT_IIOC_VERSION;
break;
case IIOCGETDRV:
if ((dioctl.getid.drvid = divert_if.name_to_drv(dioctl.getid.drvnam)) < 0)
return (-EINVAL);
break;
case IIOCGETNAM:
cp = divert_if.drv_to_name(dioctl.getid.drvid);
if (!cp)
return (-EINVAL);
if (!*cp)
return (-EINVAL);
strcpy(dioctl.getid.drvnam, cp);
break;
case IIOCGETRULE:
if (!(rulep = getruleptr(dioctl.getsetrule.ruleidx)))
return (-EINVAL);
dioctl.getsetrule.rule = *rulep;
break;
case IIOCMODRULE:
if (!(rulep = getruleptr(dioctl.getsetrule.ruleidx)))
return (-EINVAL);
spin_lock_irqsave(&divert_lock, flags);
*rulep = dioctl.getsetrule.rule;
spin_unlock_irqrestore(&divert_lock, flags);
return (0);
break;
case IIOCINSRULE:
return (insertrule(dioctl.getsetrule.ruleidx, &dioctl.getsetrule.rule));
break;
case IIOCDELRULE:
return (deleterule(dioctl.getsetrule.ruleidx));
break;
case IIOCDODFACT:
return (deflect_extern_action(dioctl.fwd_ctrl.subcmd,
dioctl.fwd_ctrl.callid,
dioctl.fwd_ctrl.to_nr));
case IIOCDOCFACT:
case IIOCDOCFDIS:
case IIOCDOCFINT:
if (!divert_if.drv_to_name(dioctl.cf_ctrl.drvid))
return (-EINVAL);
if (strnlen(dioctl.cf_ctrl.msn, sizeof(dioctl.cf_ctrl.msn)) ==
sizeof(dioctl.cf_ctrl.msn))
return -EINVAL;
if (strnlen(dioctl.cf_ctrl.fwd_nr, sizeof(dioctl.cf_ctrl.fwd_nr)) ==
sizeof(dioctl.cf_ctrl.fwd_nr))
return -EINVAL;
if ((i = cf_command(dioctl.cf_ctrl.drvid,
(cmd == IIOCDOCFACT) ? 1 : (cmd == IIOCDOCFDIS) ? 0 : 2,
dioctl.cf_ctrl.cfproc,
dioctl.cf_ctrl.msn,
dioctl.cf_ctrl.service,
dioctl.cf_ctrl.fwd_nr,
&dioctl.cf_ctrl.procid)))
return (i);
break;
default:
return (-EINVAL);
}
return copy_to_user((void __user *)arg, &dioctl, sizeof(dioctl)) ? -EFAULT : 0;
}
static long isdn_divert_ioctl(struct file *file, uint cmd, ulong arg)
{
long ret;
mutex_lock(&isdn_divert_mutex);
ret = isdn_divert_ioctl_unlocked(file, cmd, arg);
mutex_unlock(&isdn_divert_mutex);
return ret;
}
int
divert_dev_init(void)
{
init_waitqueue_head(&rd_queue);
#ifdef CONFIG_PROC_FS
isdn_proc_entry = proc_mkdir("isdn", init_net.proc_net);
if (!isdn_proc_entry)
return (-1);
isdn_divert_entry = proc_create("divert", S_IFREG | S_IRUGO,
isdn_proc_entry, &isdn_fops);
if (!isdn_divert_entry) {
remove_proc_entry("isdn", init_net.proc_net);
return (-1);
}
#endif
return (0);
}
int
divert_dev_deinit(void)
{
#ifdef CONFIG_PROC_FS
remove_proc_entry("divert", isdn_proc_entry);
remove_proc_entry("isdn", init_net.proc_net);
#endif
return (0);
}
