static int dgrp_dpa_open(struct inode *inode, struct file *file)
{
struct nd_struct *nd;
int rtn = 0;
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
if (nd->nd_dpa_buf) {
rtn = -EBUSY;
} else {
nd->nd_dpa_buf = kmalloc(DPA_MAX, GFP_KERNEL);
if (!nd->nd_dpa_buf) {
rtn = -ENOMEM;
} else {
nd->nd_dpa_out = 0;
nd->nd_dpa_in = 0;
nd->nd_dpa_lbolt = jiffies;
}
}
done:
if (rtn)
module_put(THIS_MODULE);
return rtn;
}
static int dgrp_dpa_release(struct inode *inode, struct file *file)
{
struct nd_struct *nd;
u8 *buf;
unsigned long lock_flags;
nd = (struct nd_struct *)(file->private_data);
if (!nd)
goto done;
spin_lock_irqsave(&nd->nd_dpa_lock, lock_flags);
buf = nd->nd_dpa_buf;
nd->nd_dpa_buf = NULL;
nd->nd_dpa_out = nd->nd_dpa_in;
if (nd->nd_dpa_flag & DPA_WAIT_SPACE) {
nd->nd_dpa_flag &= ~DPA_WAIT_SPACE;
wake_up_interruptible(&nd->nd_dpa_wqueue);
}
spin_unlock_irqrestore(&nd->nd_dpa_lock, lock_flags);
kfree(buf);
done:
module_put(THIS_MODULE);
file->private_data = NULL;
return 0;
}
static ssize_t dgrp_dpa_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
struct nd_struct *nd;
int n;
int r;
int offset = 0;
int res = 0;
ssize_t rtn;
unsigned long lock_flags;
nd = (struct nd_struct *)(file->private_data);
if (!nd)
return -ENXIO;
spin_lock_irqsave(&nd->nd_dpa_lock, lock_flags);
for (;;) {
n = (nd->nd_dpa_in - nd->nd_dpa_out) & DPA_MASK;
if (n != 0)
break;
nd->nd_dpa_flag |= DPA_WAIT_DATA;
spin_unlock_irqrestore(&nd->nd_dpa_lock, lock_flags);
rtn = wait_event_interruptible(nd->nd_dpa_wqueue,
((nd->nd_dpa_flag & DPA_WAIT_DATA) == 0));
if (rtn)
return rtn;
spin_lock_irqsave(&nd->nd_dpa_lock, lock_flags);
}
if (n > count)
n = count;
res = n;
r = DPA_MAX - nd->nd_dpa_out;
if (r <= n) {
spin_unlock_irqrestore(&nd->nd_dpa_lock, lock_flags);
rtn = copy_to_user((void __user *)buf,
nd->nd_dpa_buf + nd->nd_dpa_out, r);
spin_lock_irqsave(&nd->nd_dpa_lock, lock_flags);
if (rtn) {
rtn = -EFAULT;
goto done;
}
nd->nd_dpa_out = 0;
n -= r;
offset = r;
}
spin_unlock_irqrestore(&nd->nd_dpa_lock, lock_flags);
rtn = copy_to_user((void __user *)buf + offset,
nd->nd_dpa_buf + nd->nd_dpa_out, n);
spin_lock_irqsave(&nd->nd_dpa_lock, lock_flags);
if (rtn) {
rtn = -EFAULT;
goto done;
}
nd->nd_dpa_out += n;
*ppos += res;
rtn = res;
n = (nd->nd_dpa_in - nd->nd_dpa_out) & DPA_MASK;
if (nd->nd_dpa_flag & DPA_WAIT_SPACE &&
(DPA_MAX - n) > DPA_HIGH_WATER) {
nd->nd_dpa_flag &= ~DPA_WAIT_SPACE;
wake_up_interruptible(&nd->nd_dpa_wqueue);
}
done:
spin_unlock_irqrestore(&nd->nd_dpa_lock, lock_flags);
return rtn;
}
static unsigned int dgrp_dpa_select(struct file *file,
struct poll_table_struct *table)
{
unsigned int retval = 0;
struct nd_struct *nd = file->private_data;
if (nd->nd_dpa_out != nd->nd_dpa_in)
retval |= POLLIN | POLLRDNORM;
retval |= POLLOUT | POLLWRNORM;
return retval;
}
static long dgrp_dpa_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct nd_struct *nd;
struct digi_chan getchan;
struct digi_node getnode;
struct ch_struct *ch;
struct digi_debug setdebug;
struct digi_vpd vpd;
unsigned int port;
void __user *uarg = (void __user *) arg;
nd = file->private_data;
switch (cmd) {
case DIGI_GETCHAN:
if (copy_from_user(&getchan, uarg, sizeof(struct digi_chan)))
return -EFAULT;
port = getchan.ch_port;
if (port > nd->nd_chan_count)
return -EINVAL;
ch = nd->nd_chan + port;
getchan.ch_open = (ch->ch_open_count > 0) ? 1 : 0;
getchan.ch_txcount = ch->ch_txcount;
getchan.ch_rxcount = ch->ch_rxcount;
getchan.ch_s_brate = ch->ch_s_brate;
getchan.ch_s_estat = ch->ch_s_elast;
getchan.ch_s_cflag = ch->ch_s_cflag;
getchan.ch_s_iflag = ch->ch_s_iflag;
getchan.ch_s_oflag = ch->ch_s_oflag;
getchan.ch_s_xflag = ch->ch_s_xflag;
getchan.ch_s_mstat = ch->ch_s_mlast;
if (copy_to_user(uarg, &getchan, sizeof(struct digi_chan)))
return -EFAULT;
break;
case DIGI_GETNODE:
getnode.nd_state = (nd->nd_state & NS_READY) ? 1 : 0;
getnode.nd_chan_count = nd->nd_chan_count;
getnode.nd_tx_byte = nd->nd_tx_byte;
getnode.nd_rx_byte = nd->nd_rx_byte;
memset(&getnode.nd_ps_desc, 0, MAX_DESC_LEN);
strlcpy(getnode.nd_ps_desc, nd->nd_ps_desc, MAX_DESC_LEN);
if (copy_to_user(uarg, &getnode, sizeof(struct digi_node)))
return -EFAULT;
break;
case DIGI_SETDEBUG:
if (copy_from_user(&setdebug, uarg, sizeof(struct digi_debug)))
return -EFAULT;
nd->nd_dpa_debug = setdebug.onoff;
nd->nd_dpa_port = setdebug.port;
break;
case DIGI_GETVPD:
memset(&vpd, 0, sizeof(vpd));
if (nd->nd_vpd_len > 0) {
vpd.vpd_len = nd->nd_vpd_len;
memcpy(&vpd.vpd_data, &nd->nd_vpd, nd->nd_vpd_len);
} else {
vpd.vpd_len = 0;
}
if (copy_to_user(uarg, &vpd, sizeof(struct digi_vpd)))
return -EFAULT;
break;
}
return 0;
}
static void dgrp_dpa(struct nd_struct *nd, u8 *buf, int nbuf)
{
int n;
int r;
unsigned long lock_flags;
spin_lock_irqsave(&nd->nd_dpa_lock, lock_flags);
while (nbuf > 0 && nd->nd_dpa_buf != NULL) {
n = (nd->nd_dpa_out - nd->nd_dpa_in - 1) & DPA_MASK;
if (n < (DPA_MAX - DPA_HIGH_WATER))
nd->nd_dpa_flag |= DPA_WAIT_SPACE;
if (n == 0) {
spin_unlock_irqrestore(&nd->nd_dpa_lock, lock_flags);
return;
}
if (n > nbuf)
n = nbuf;
r = DPA_MAX - nd->nd_dpa_in;
if (r <= n) {
memcpy(nd->nd_dpa_buf + nd->nd_dpa_in, buf, r);
n -= r;
nd->nd_dpa_in = 0;
buf += r;
nbuf -= r;
}
memcpy(nd->nd_dpa_buf + nd->nd_dpa_in, buf, n);
nd->nd_dpa_in += n;
buf += n;
nbuf -= n;
if (nd->nd_dpa_in >= DPA_MAX)
pr_info_ratelimited("%s - nd->nd_dpa_in (%i) >= DPA_MAX\n",
__func__, nd->nd_dpa_in);
if (nd->nd_dpa_flag & DPA_WAIT_DATA) {
nd->nd_dpa_flag &= ~DPA_WAIT_DATA;
wake_up_interruptible(&nd->nd_dpa_wqueue);
}
}
spin_unlock_irqrestore(&nd->nd_dpa_lock, lock_flags);
}
void dgrp_dpa_data(struct nd_struct *nd, int type, u8 *buf, int size)
{
u8 header[5];
header[0] = type;
put_unaligned_be32(size, header + 1);
dgrp_dpa(nd, header, sizeof(header));
dgrp_dpa(nd, buf, size);
}
