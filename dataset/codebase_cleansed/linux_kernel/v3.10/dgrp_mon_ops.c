static int dgrp_mon_open(struct inode *inode, struct file *file)
{
struct nd_struct *nd;
struct timeval tv;
uint32_t time;
u8 *buf;
int rtn;
rtn = try_module_get(THIS_MODULE);
if (!rtn)
return -ENXIO;
rtn = 0;
if (!capable(CAP_SYS_ADMIN)) {
rtn = -EPERM;
goto done;
}
if (file->private_data) {
rtn = -EINVAL;
goto done;
}
nd = PDE_DATA(inode);
if (!nd) {
rtn = -ENXIO;
goto done;
}
file->private_data = (void *) nd;
down(&nd->nd_mon_semaphore);
if (nd->nd_mon_buf) {
rtn = -EBUSY;
goto done_up;
}
nd->nd_mon_buf = kmalloc(MON_MAX, GFP_KERNEL);
if (!nd->nd_mon_buf) {
rtn = -ENOMEM;
goto done_up;
}
buf = nd->nd_mon_buf;
strcpy(buf, RPDUMP_MAGIC);
buf += strlen(buf) + 1;
do_gettimeofday(&tv);
time = (uint32_t) (tv.tv_sec & 0xffffffff);
put_unaligned_be32(time, buf);
put_unaligned_be16(0, buf + 4);
buf += 6;
if (nd->nd_tx_module) {
buf[0] = RPDUMP_CLIENT;
put_unaligned_be32(0, buf + 1);
put_unaligned_be16(1, buf + 5);
buf[7] = 0xf0 + nd->nd_tx_module;
buf += 8;
}
if (nd->nd_rx_module) {
buf[0] = RPDUMP_SERVER;
put_unaligned_be32(0, buf + 1);
put_unaligned_be16(1, buf + 5);
buf[7] = 0xf0 + nd->nd_rx_module;
buf += 8;
}
nd->nd_mon_out = 0;
nd->nd_mon_in = buf - nd->nd_mon_buf;
nd->nd_mon_lbolt = jiffies;
done_up:
up(&nd->nd_mon_semaphore);
done:
if (rtn)
module_put(THIS_MODULE);
return rtn;
}
static int dgrp_mon_release(struct inode *inode, struct file *file)
{
struct nd_struct *nd;
nd = (struct nd_struct *)(file->private_data);
if (!nd)
goto done;
down(&nd->nd_mon_semaphore);
kfree(nd->nd_mon_buf);
nd->nd_mon_buf = NULL;
nd->nd_mon_out = nd->nd_mon_in;
if (nd->nd_mon_flag & MON_WAIT_SPACE) {
nd->nd_mon_flag &= ~MON_WAIT_SPACE;
wake_up_interruptible(&nd->nd_mon_wqueue);
}
up(&nd->nd_mon_semaphore);
down(&nd->nd_net_semaphore);
up(&nd->nd_net_semaphore);
done:
module_put(THIS_MODULE);
file->private_data = NULL;
return 0;
}
static ssize_t dgrp_mon_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
struct nd_struct *nd;
int r;
int offset = 0;
int res = 0;
ssize_t rtn;
nd = (struct nd_struct *)(file->private_data);
if (!nd)
return -ENXIO;
down(&nd->nd_mon_semaphore);
for (;;) {
res = (nd->nd_mon_in - nd->nd_mon_out) & MON_MASK;
if (res)
break;
nd->nd_mon_flag |= MON_WAIT_DATA;
up(&nd->nd_mon_semaphore);
rtn = wait_event_interruptible(nd->nd_mon_wqueue,
((nd->nd_mon_flag & MON_WAIT_DATA) == 0));
if (rtn)
return rtn;
down(&nd->nd_mon_semaphore);
}
if (res > count)
res = count;
r = MON_MAX - nd->nd_mon_out;
if (r <= res) {
rtn = copy_to_user((void __user *)buf,
nd->nd_mon_buf + nd->nd_mon_out, r);
if (rtn) {
up(&nd->nd_mon_semaphore);
return -EFAULT;
}
nd->nd_mon_out = 0;
res -= r;
offset = r;
}
rtn = copy_to_user((void __user *) buf + offset,
nd->nd_mon_buf + nd->nd_mon_out, res);
if (rtn) {
up(&nd->nd_mon_semaphore);
return -EFAULT;
}
nd->nd_mon_out += res;
*ppos += res;
up(&nd->nd_mon_semaphore);
if (nd->nd_mon_flag & MON_WAIT_SPACE) {
nd->nd_mon_flag &= ~MON_WAIT_SPACE;
wake_up_interruptible(&nd->nd_mon_wqueue);
}
return res;
}
static long dgrp_mon_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
return -EINVAL;
}
