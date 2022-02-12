void dgrp_register_net_hook(struct proc_dir_entry *de)
{
struct nd_struct *node = de->data;
de->proc_iops = &net_inode_ops;
de->proc_fops = &net_ops;
node->nd_net_de = de;
sema_init(&node->nd_net_semaphore, 1);
node->nd_state = NS_CLOSED;
dgrp_create_node_class_sysfs_files(node);
}
static void dgrp_dump(u8 *mem, int len)
{
int i;
pr_debug("dgrp dump length = %d, data = ", len);
for (i = 0; i < len; ++i)
pr_debug("%.2x ", mem[i]);
pr_debug("\n");
}
static void dgrp_read_data_block(struct ch_struct *ch, u8 *flipbuf,
int flipbuf_size)
{
int t;
int n;
if (flipbuf_size <= 0)
return;
t = RBUF_MAX - ch->ch_rout;
n = flipbuf_size;
if (n >= t) {
memcpy(flipbuf, ch->ch_rbuf + ch->ch_rout, t);
flipbuf += t;
n -= t;
ch->ch_rout = 0;
}
memcpy(flipbuf, ch->ch_rbuf + ch->ch_rout, n);
flipbuf += n;
ch->ch_rout += n;
}
static void dgrp_input(struct ch_struct *ch)
{
struct nd_struct *nd;
struct tty_struct *tty;
int data_len;
int len;
int tty_count;
ulong lock_flags;
u8 *myflipbuf;
u8 *myflipflagbuf;
if (!ch)
return;
nd = ch->ch_nd;
if (!nd)
return;
spin_lock_irqsave(&nd->nd_lock, lock_flags);
myflipbuf = nd->nd_inputbuf;
myflipflagbuf = nd->nd_inputflagbuf;
if (!ch->ch_open_count) {
ch->ch_rout = ch->ch_rin;
goto out;
}
if (ch->ch_tun.un_flag & UN_CLOSING) {
ch->ch_rout = ch->ch_rin;
goto out;
}
tty = (ch->ch_tun).un_tty;
if (!tty || tty->magic != TTY_MAGIC) {
ch->ch_rout = ch->ch_rin;
goto out;
}
tty_count = tty->count;
if (!tty_count) {
ch->ch_rout = ch->ch_rin;
goto out;
}
if (tty->closing || test_bit(TTY_CLOSING, &tty->flags)) {
ch->ch_rout = ch->ch_rin;
goto out;
}
spin_unlock_irqrestore(&nd->nd_lock, lock_flags);
data_len = (ch->ch_rin - ch->ch_rout) & RBUF_MASK;
len = tty_buffer_request_room(tty, data_len);
if ((nd->nd_dpa_debug) &&
(nd->nd_dpa_flag & DPA_WAIT_SPACE) &&
(nd->nd_dpa_port == MINOR(tty_devnum(ch->ch_tun.un_tty))))
len = 0;
if ((len) && !(ch->ch_flag & CH_RXSTOP)) {
dgrp_read_data_block(ch, myflipbuf, len);
if (I_PARMRK(tty) || I_BRKINT(tty) || I_INPCK(tty))
parity_scan(ch, myflipbuf, myflipflagbuf, &len);
else
memset(myflipflagbuf, TTY_NORMAL, len);
if ((nd->nd_dpa_debug) &&
(nd->nd_dpa_port == PORT_NUM(MINOR(tty_devnum(tty)))))
dgrp_dpa_data(nd, 1, myflipbuf, len);
tty_insert_flip_string_flags(tty, myflipbuf,
myflipflagbuf, len);
tty_flip_buffer_push(tty);
ch->ch_rxcount += len;
}
wake_up_interruptible(&ch->ch_flag_wait);
return;
out:
spin_unlock_irqrestore(&nd->nd_lock, lock_flags);
}
static void parity_scan(struct ch_struct *ch, unsigned char *cbuf,
unsigned char *fbuf, int *len)
{
int l = *len;
int count = 0;
int DOS = ((ch->ch_iflag & IF_DOSMODE) == 0 ? 0 : 1);
unsigned char *cout;
unsigned char *fout;
unsigned char *in;
unsigned char c;
in = cbuf;
cout = cbuf;
fout = fbuf;
while (l--) {
c = *in;
in++;
switch (ch->ch_pscan_state) {
default:
ch->ch_pscan_state = 0 ;
case 0:
if (c == 0xff)
ch->ch_pscan_state = 1;
else {
*cout++ = c;
*fout++ = TTY_NORMAL;
count += 1;
}
break;
case 1:
if (c == 0xff) {
*cout++ = c;
*fout++ = TTY_NORMAL;
count += 1;
ch->ch_pscan_state = 0;
} else {
ch->ch_pscan_savechar = c;
ch->ch_pscan_state = 2;
}
break;
case 2:
*cout++ = c;
if (DOS) {
if (ch->ch_pscan_savechar & 0x10)
*fout++ = TTY_BREAK;
else if (ch->ch_pscan_savechar & 0x08)
*fout++ = TTY_FRAME;
else
*fout++ = TTY_PARITY;
} else {
if (ch->ch_pscan_savechar & 0xff) {
pr_info("%s: parity_scan: error unexpected byte\n",
__func__);
*fout++ = TTY_PARITY;
}
else if (c == 0xff)
*fout++ = TTY_PARITY;
else
*fout++ = TTY_BREAK;
}
count += 1;
ch->ch_pscan_state = 0;
}
}
*len = count;
}
static void dgrp_net_idle(struct nd_struct *nd)
{
struct ch_struct *ch;
int i;
nd->nd_tx_work = 1;
nd->nd_state = NS_IDLE;
nd->nd_flag = 0;
for (i = nd->nd_seq_out; ; i = (i + 1) & SEQ_MASK) {
if (!nd->nd_seq_wait[i]) {
nd->nd_seq_wait[i] = 0;
wake_up_interruptible(&nd->nd_seq_wque[i]);
}
if (i == nd->nd_seq_in)
break;
}
nd->nd_seq_out = nd->nd_seq_in;
nd->nd_unack = 0;
nd->nd_remain = 0;
nd->nd_tx_module = 0x10;
nd->nd_rx_module = 0x00;
for (i = 0, ch = nd->nd_chan; i < CHAN_MAX; i++, ch++) {
ch->ch_state = CS_IDLE;
ch->ch_otype = 0;
ch->ch_otype_waiting = 0;
}
}
static void increase_channel_count(struct nd_struct *nd, int n)
{
struct ch_struct *ch;
struct device *classp;
char name[DEVICE_NAME_SIZE];
int ret;
u8 *buf;
int i;
for (i = nd->nd_chan_count; i < n; ++i) {
ch = nd->nd_chan + i;
buf = kmalloc(TBUF_MAX, GFP_KERNEL);
if (!buf)
return;
if (ch->ch_tbuf)
pr_info_ratelimited("%s - ch_tbuf was not NULL\n",
__func__);
ch->ch_tbuf = buf;
buf = kmalloc(RBUF_MAX, GFP_KERNEL);
if (!buf)
return;
if (ch->ch_rbuf)
pr_info("%s - ch_rbuf was not NULL\n",
__func__);
ch->ch_rbuf = buf;
classp = tty_port_register_device(&ch->port,
nd->nd_serial_ttdriver, i,
NULL);
ch->ch_tun.un_sysfs = classp;
snprintf(name, DEVICE_NAME_SIZE, "tty_%d", i);
dgrp_create_tty_sysfs(&ch->ch_tun, classp);
ret = sysfs_create_link(&nd->nd_class_dev->kobj,
&classp->kobj, name);
if (dgrp_register_prdevices) {
classp = tty_register_device(nd->nd_xprint_ttdriver,
i, NULL);
ch->ch_pun.un_sysfs = classp;
snprintf(name, DEVICE_NAME_SIZE, "pr_%d", i);
dgrp_create_tty_sysfs(&ch->ch_pun, classp);
ret = sysfs_create_link(&nd->nd_class_dev->kobj,
&classp->kobj, name);
}
nd->nd_chan_count = i + 1;
wake_up_interruptible(&ch->ch_flag_wait);
}
}
static void decrease_channel_count(struct nd_struct *nd, int n)
{
struct ch_struct *ch;
char name[DEVICE_NAME_SIZE];
int i;
for (i = nd->nd_chan_count - 1; i >= n; --i) {
ch = nd->nd_chan + i;
ch->ch_state = CS_IDLE;
ch->ch_otype = 0;
ch->ch_otype_waiting = 0;
if (ch->ch_open_count != 0) {
ch->ch_flag |= CH_HANGUP;
dgrp_carrier(ch);
}
if (ch->ch_open_count != 0)
ch->ch_flag |= CH_PORT_GONE;
wake_up_interruptible(&ch->ch_flag_wait);
nd->nd_chan_count = i;
kfree(ch->ch_tbuf);
ch->ch_tbuf = NULL;
kfree(ch->ch_rbuf);
ch->ch_rbuf = NULL;
nd->nd_chan_count = i;
dgrp_remove_tty_sysfs(ch->ch_tun.un_sysfs);
snprintf(name, DEVICE_NAME_SIZE, "tty_%d", i);
sysfs_remove_link(&nd->nd_class_dev->kobj, name);
tty_unregister_device(nd->nd_serial_ttdriver, i);
if (dgrp_register_prdevices) {
dgrp_remove_tty_sysfs(ch->ch_pun.un_sysfs);
snprintf(name, DEVICE_NAME_SIZE, "pr_%d", i);
sysfs_remove_link(&nd->nd_class_dev->kobj, name);
tty_unregister_device(nd->nd_xprint_ttdriver, i);
}
}
}
static void dgrp_chan_count(struct nd_struct *nd, int n)
{
if (n == nd->nd_chan_count)
return;
if (n > nd->nd_chan_count)
increase_channel_count(nd, n);
if (n < nd->nd_chan_count)
decrease_channel_count(nd, n);
}
static void dgrp_monitor(struct nd_struct *nd, u8 *buf, int len)
{
int n;
int r;
int rtn;
down(&nd->nd_mon_semaphore);
while ((len > 0) && (nd->nd_mon_buf)) {
n = (nd->nd_mon_out - nd->nd_mon_in - 1) & MON_MASK;
if (!n) {
nd->nd_mon_flag |= MON_WAIT_SPACE;
up(&nd->nd_mon_semaphore);
rtn = wait_event_interruptible(nd->nd_mon_wqueue,
((nd->nd_mon_flag & MON_WAIT_SPACE) == 0));
down(&nd->nd_mon_semaphore);
continue;
}
if (n > len)
n = len;
r = MON_MAX - nd->nd_mon_in;
if (r <= n) {
memcpy(nd->nd_mon_buf + nd->nd_mon_in, buf, r);
n -= r;
nd->nd_mon_in = 0;
buf += r;
len -= r;
}
memcpy(nd->nd_mon_buf + nd->nd_mon_in, buf, n);
nd->nd_mon_in += n;
buf += n;
len -= n;
if (nd->nd_mon_in >= MON_MAX)
pr_info_ratelimited("%s - nd_mon_in (%i) >= MON_MAX\n",
__func__, nd->nd_mon_in);
if (nd->nd_mon_flag & MON_WAIT_DATA) {
nd->nd_mon_flag &= ~MON_WAIT_DATA;
wake_up_interruptible(&nd->nd_mon_wqueue);
}
}
up(&nd->nd_mon_semaphore);
}
static void dgrp_encode_time(struct nd_struct *nd, u8 *buf)
{
ulong t;
t = jiffies - nd->nd_mon_lbolt;
t = 1000 * (t / HZ) + 1000 * (t % HZ) / HZ;
put_unaligned_be32((uint)(t & 0xffffffff), buf);
}
static void dgrp_monitor_message(struct nd_struct *nd, char *message)
{
u8 header[7];
int n;
header[0] = RPDUMP_MESSAGE;
dgrp_encode_time(nd, header + 1);
n = strlen(message);
put_unaligned_be16(n, header + 5);
dgrp_monitor(nd, header, sizeof(header));
dgrp_monitor(nd, (u8 *) message, n);
}
static void dgrp_monitor_reset(struct nd_struct *nd)
{
u8 header[5];
header[0] = RPDUMP_RESET;
dgrp_encode_time(nd, header + 1);
dgrp_monitor(nd, header, sizeof(header));
}
static void dgrp_monitor_data(struct nd_struct *nd, u8 type, u8 *buf, int size)
{
u8 header[7];
header[0] = type;
dgrp_encode_time(nd, header + 1);
put_unaligned_be16(size, header + 5);
dgrp_monitor(nd, header, sizeof(header));
dgrp_monitor(nd, buf, size);
}
static int alloc_nd_buffers(struct nd_struct *nd)
{
nd->nd_iobuf = NULL;
nd->nd_writebuf = NULL;
nd->nd_inputbuf = NULL;
nd->nd_inputflagbuf = NULL;
nd->nd_iobuf = kzalloc(UIO_MAX + 10, GFP_KERNEL);
if (!nd->nd_iobuf)
goto out_err;
nd->nd_writebuf = kzalloc(WRITEBUFLEN, GFP_KERNEL);
if (!nd->nd_writebuf)
goto out_err;
nd->nd_inputbuf = kzalloc(MYFLIPLEN, GFP_KERNEL);
if (!nd->nd_inputbuf)
goto out_err;
nd->nd_inputflagbuf = kzalloc(MYFLIPLEN, GFP_KERNEL);
if (!nd->nd_inputflagbuf)
goto out_err;
return 0;
out_err:
kfree(nd->nd_iobuf);
kfree(nd->nd_writebuf);
kfree(nd->nd_inputbuf);
kfree(nd->nd_inputflagbuf);
return -ENOMEM;
}
static int dgrp_net_open(struct inode *inode, struct file *file)
{
struct nd_struct *nd;
struct proc_dir_entry *de;
ulong lock_flags;
int rtn;
rtn = try_module_get(THIS_MODULE);
if (!rtn)
return -EAGAIN;
if (!capable(CAP_SYS_ADMIN)) {
rtn = -EPERM;
goto done;
}
if (file->private_data) {
rtn = -EINVAL;
goto done;
}
de = PDE(inode);
if (!de) {
rtn = -ENXIO;
goto done;
}
nd = (struct nd_struct *) de->data;
if (!nd) {
rtn = -ENXIO;
goto done;
}
file->private_data = (void *) nd;
down(&nd->nd_net_semaphore);
if (nd->nd_state != NS_CLOSED) {
rtn = -EBUSY;
goto unlock;
}
nd->nd_link.lk_fast_rate = UIO_MAX;
nd->nd_link.lk_slow_rate = UIO_MAX;
nd->nd_link.lk_fast_delay = 1000;
nd->nd_link.lk_slow_delay = 1000;
nd->nd_link.lk_header_size = 46;
rtn = alloc_nd_buffers(nd);
if (rtn)
goto unlock;
dgrp_net_idle(nd);
nd->nd_tx_time = jiffies;
spin_lock_irqsave(&dgrp_poll_data.poll_lock, lock_flags);
if (!dgrp_poll_data.node_active_count) {
dgrp_poll_data.node_active_count = 2;
dgrp_poll_data.timer.expires = jiffies +
dgrp_poll_tick * HZ / 1000;
add_timer(&dgrp_poll_data.timer);
}
spin_unlock_irqrestore(&dgrp_poll_data.poll_lock, lock_flags);
dgrp_monitor_message(nd, "Net Open");
unlock:
up(&nd->nd_net_semaphore);
done:
if (rtn)
module_put(THIS_MODULE);
return rtn;
}
static int dgrp_net_release(struct inode *inode, struct file *file)
{
struct nd_struct *nd;
ulong lock_flags;
nd = (struct nd_struct *)(file->private_data);
if (!nd)
goto done;
down(&nd->nd_net_semaphore);
dgrp_net_idle(nd);
nd->nd_state = NS_CLOSED;
nd->nd_flag = 0;
if (waitqueue_active(&nd->nd_tx_waitq))
pr_info("%s - expected waitqueue_active to be false\n",
__func__);
nd->nd_send = 0;
kfree(nd->nd_iobuf);
nd->nd_iobuf = NULL;
kfree(nd->nd_writebuf);
nd->nd_writebuf = NULL;
kfree(nd->nd_inputbuf);
nd->nd_inputbuf = NULL;
kfree(nd->nd_inputflagbuf);
nd->nd_inputflagbuf = NULL;
dgrp_chan_count(nd, 0);
up(&nd->nd_net_semaphore);
spin_lock_irqsave(&dgrp_poll_data.poll_lock, lock_flags);
if (dgrp_poll_data.node_active_count == 2) {
del_timer(&dgrp_poll_data.timer);
dgrp_poll_data.node_active_count = 0;
}
spin_unlock_irqrestore(&dgrp_poll_data.poll_lock, lock_flags);
down(&nd->nd_net_semaphore);
dgrp_monitor_message(nd, "Net Close");
up(&nd->nd_net_semaphore);
done:
module_put(THIS_MODULE);
file->private_data = NULL;
return 0;
}
static inline u8 *set_cmd_header(u8 *b, u8 port, u8 cmd)
{
*b++ = 0xb0 + (port & 0x0f);
*b++ = cmd;
return b;
}
static int dgrp_send(struct nd_struct *nd, long tmax)
{
struct ch_struct *ch = nd->nd_chan;
u8 *b;
u8 *buf;
u8 *mbuf;
u8 port;
int mod;
long send;
int maxport;
long lastport = -1;
ushort rwin;
long in;
ushort n;
long t;
long ttotal;
long tchan;
long tsend;
ushort tsafe;
long work;
long send_sync;
long wanted_sync_port = -1;
ushort tdata[CHAN_MAX];
long used_buffer;
mbuf = nd->nd_iobuf + UIO_BASE;
buf = b = mbuf;
send_sync = nd->nd_link.lk_slow_rate < UIO_MAX;
ttotal = 0;
tchan = 0;
memset(tdata, 0, sizeof(tdata));
if (nd->nd_send & NR_PASSWORD) {
b[0] = 0xfc;
b[1] = 0x20;
put_unaligned_be16(strlen(nd->password), b + 2);
b += 4;
b += strlen(nd->password);
nd->nd_send &= ~(NR_PASSWORD);
}
for (mod = 0, port = 0; port < nd->nd_chan_count; mod++) {
if (mod != nd->nd_tx_module)
mbuf = ++b;
maxport = port + 16;
if (maxport > nd->nd_chan_count)
maxport = nd->nd_chan_count;
for (; port < maxport; port++, ch++) {
switch (ch->ch_state) {
case CS_IDLE:
if (ch->ch_open_error) {
if (ch->ch_wait_count[ch->ch_otype]) {
work = 1;
break;
}
ch->ch_open_error = 0;
}
if ((ch->ch_flag & CH_HANGUP) != 0)
break;
if ((ch->ch_flag & CH_PORT_GONE) ||
ch->ch_wait_count[OTYPE_IMMEDIATE] != 0) {
b = set_cmd_header(b, port, 10);
*b++ = 0;
ch->ch_state = CS_WAIT_OPEN;
ch->ch_otype = OTYPE_IMMEDIATE;
break;
}
if (ch->ch_otype_waiting == 0) {
if (ch->ch_wait_count[OTYPE_PERSISTENT] != 0) {
b = set_cmd_header(b, port, 10);
*b++ = 1;
ch->ch_state = CS_WAIT_OPEN;
ch->ch_otype = OTYPE_PERSISTENT;
} else if (ch->ch_wait_count[OTYPE_INCOMING] != 0) {
b = set_cmd_header(b, port, 10);
*b++ = 2;
ch->ch_state = CS_WAIT_OPEN;
ch->ch_otype = OTYPE_INCOMING;
}
break;
}
if (ch->ch_wait_count[ch->ch_otype_waiting] == 0) {
b = set_cmd_header(b, port, 10);
*b++ = 4;
ch->ch_state = CS_WAIT_CANCEL;
ch->ch_otype = ch->ch_otype_waiting;
}
break;
case CS_SEND_QUERY:
ch->ch_flag |= CH_PARAM;
ch->ch_flag &= ~CH_RX_FLUSH;
ch->ch_expect = 0;
ch->ch_s_tin = 0;
ch->ch_s_tpos = 0;
ch->ch_s_tsize = 0;
ch->ch_s_treq = 0;
ch->ch_s_elast = 0;
ch->ch_s_rin = 0;
ch->ch_s_rwin = 0;
ch->ch_s_rsize = 0;
ch->ch_s_tmax = 0;
ch->ch_s_ttime = 0;
ch->ch_s_rmax = 0;
ch->ch_s_rtime = 0;
ch->ch_s_rlow = 0;
ch->ch_s_rhigh = 0;
ch->ch_s_brate = 0;
ch->ch_s_iflag = 0;
ch->ch_s_cflag = 0;
ch->ch_s_oflag = 0;
ch->ch_s_xflag = 0;
ch->ch_s_mout = 0;
ch->ch_s_mflow = 0;
ch->ch_s_mctrl = 0;
ch->ch_s_xon = 0;
ch->ch_s_xoff = 0;
ch->ch_s_lnext = 0;
ch->ch_s_xxon = 0;
ch->ch_s_xxoff = 0;
b = set_cmd_header(b, port, 14);
b = set_cmd_header(b, port, 42);
put_unaligned_be16(0x02c0, b);
b += 2;
*b++ = (DM_DTR | DM_RTS | DM_CTS |
DM_DSR | DM_RI | DM_CD);
b = set_cmd_header(b, port, 16);
b = set_cmd_header(b, port, 20);
b = set_cmd_header(b, port, 22);
ch->ch_expect = (RR_SEQUENCE |
RR_STATUS |
RR_BUFFER |
RR_CAPABILITY);
ch->ch_state = CS_WAIT_QUERY;
b = set_cmd_header(b, port, 44);
if (ch->ch_flag & CH_PORT_GONE)
ch->ch_s_mout = ch->ch_mout;
else
ch->ch_s_mout = ch->ch_mout = DM_DTR | DM_RTS;
*b++ = ch->ch_mout;
*b++ = ch->ch_s_mflow = 0;
*b++ = ch->ch_s_mctrl = ch->ch_mctrl = 0;
if (ch->ch_flag & CH_PORT_GONE)
ch->ch_flag &= ~CH_PORT_GONE;
break;
case CS_READY:
if (ch->ch_open_count == 0 &&
ch->ch_wait_count[ch->ch_otype] == 0) {
goto send_close;
}
if (ch->ch_rin != ch->ch_rout) {
if (ch->ch_tun.un_open_count == 0 ||
(ch->ch_tun.un_flag & UN_CLOSING) ||
(ch->ch_cflag & CF_CREAD) == 0) {
ch->ch_rout = ch->ch_rin;
} else if ((ch->ch_flag & CH_FAST_READ) == 0 ||
ch->ch_inwait != 0) {
dgrp_input(ch);
if (ch->ch_rin != ch->ch_rout)
work = 1;
}
}
if (ch->ch_flag & (CH_RX_FLUSH | CH_PARAM)) {
if (ch->ch_flag & CH_RX_FLUSH) {
if (((ch->ch_flush_seq - nd->nd_seq_out) & SEQ_MASK) >
((nd->nd_seq_in - nd->nd_seq_out) & SEQ_MASK))
ch->ch_flag &= ~CH_RX_FLUSH;
else
work = 1;
}
if (ch->ch_s_tmax != ch->ch_tmax ||
ch->ch_s_ttime != ch->ch_ttime) {
b = set_cmd_header(b, port, 48);
ch->ch_s_tmax = ch->ch_tmax;
ch->ch_s_ttime = ch->ch_ttime;
put_unaligned_be16(ch->ch_s_tmax,
b);
b += 2;
put_unaligned_be16(ch->ch_s_ttime,
b);
b += 2;
}
if (ch->ch_s_rlow != ch->ch_rlow ||
ch->ch_s_rhigh != ch->ch_rhigh) {
b = set_cmd_header(b, port, 45);
ch->ch_s_rlow = ch->ch_rlow;
ch->ch_s_rhigh = ch->ch_rhigh;
put_unaligned_be16(ch->ch_s_rlow,
b);
b += 2;
put_unaligned_be16(ch->ch_s_rhigh,
b);
b += 2;
}
if (ch->ch_s_brate != ch->ch_brate ||
ch->ch_s_cflag != ch->ch_cflag ||
ch->ch_s_iflag != ch->ch_iflag ||
ch->ch_s_oflag != ch->ch_oflag ||
ch->ch_s_xflag != ch->ch_xflag) {
b = set_cmd_header(b, port, 40);
ch->ch_s_brate = ch->ch_brate;
ch->ch_s_cflag = ch->ch_cflag;
ch->ch_s_iflag = ch->ch_iflag;
ch->ch_s_oflag = ch->ch_oflag;
ch->ch_s_xflag = ch->ch_xflag;
put_unaligned_be16(ch->ch_s_brate,
b);
b += 2;
put_unaligned_be16(ch->ch_s_cflag,
b);
b += 2;
put_unaligned_be16(ch->ch_s_iflag,
b);
b += 2;
put_unaligned_be16(ch->ch_s_oflag,
b);
b += 2;
put_unaligned_be16(ch->ch_s_xflag,
b);
b += 2;
}
if (ch->ch_s_mout != ch->ch_mout ||
ch->ch_s_mflow != ch->ch_mflow ||
ch->ch_s_mctrl != ch->ch_mctrl) {
b = set_cmd_header(b, port, 44);
*b++ = ch->ch_s_mout = ch->ch_mout;
*b++ = ch->ch_s_mflow = ch->ch_mflow;
*b++ = ch->ch_s_mctrl = ch->ch_mctrl;
}
if (ch->ch_s_xon != ch->ch_xon ||
ch->ch_s_xoff != ch->ch_xoff ||
ch->ch_s_lnext != ch->ch_lnext ||
ch->ch_s_xxon != ch->ch_xxon ||
ch->ch_s_xxoff != ch->ch_xxoff) {
b = set_cmd_header(b, port, 46);
*b++ = ch->ch_s_xon = ch->ch_xon;
*b++ = ch->ch_s_xoff = ch->ch_xoff;
*b++ = ch->ch_s_lnext = ch->ch_lnext;
*b++ = ch->ch_s_xxon = ch->ch_xxon;
*b++ = ch->ch_s_xxoff = ch->ch_xxoff;
}
if (ch->ch_s_rmax != ch->ch_rmax ||
ch->ch_s_rtime != ch->ch_rtime) {
b = set_cmd_header(b, port, 47);
ch->ch_s_rmax = ch->ch_rmax;
ch->ch_s_rtime = ch->ch_rtime;
put_unaligned_be16(ch->ch_s_rmax,
b);
b += 2;
put_unaligned_be16(ch->ch_s_rtime,
b);
b += 2;
}
ch->ch_flag &= ~CH_PARAM;
wake_up_interruptible(&ch->ch_flag_wait);
}
if (ch->ch_send != 0) {
send = ch->ch_send & ~ch->ch_expect;
if ((send & RR_TX_ICHAR) != 0) {
b = set_cmd_header(b, port, 60);
*b++ = ch->ch_xon;
ch->ch_expect |= RR_TX_ICHAR;
}
if ((send & RR_TX_BREAK) != 0) {
if (ch->ch_break_time != 0) {
b = set_cmd_header(b, port, 61);
put_unaligned_be16(ch->ch_break_time,
b);
b += 2;
ch->ch_expect |= RR_TX_BREAK;
ch->ch_break_time = 0;
} else {
ch->ch_send &= ~RR_TX_BREAK;
ch->ch_flag &= ~CH_TX_BREAK;
wake_up_interruptible(&ch->ch_flag_wait);
}
}
if ((send & (RR_RX_FLUSH | RR_TX_FLUSH)) != 0) {
b = set_cmd_header(b, port, 62);
*b++ = ((send & RR_TX_FLUSH) == 0 ? 1 :
(send & RR_RX_FLUSH) == 0 ? 2 : 3);
if (send & RR_RX_FLUSH) {
ch->ch_flush_seq = nd->nd_seq_in;
ch->ch_flag |= CH_RX_FLUSH;
work = 1;
send_sync = 1;
wanted_sync_port = port;
}
ch->ch_send &= ~(RR_RX_FLUSH | RR_TX_FLUSH);
}
if ((send & (RR_RX_STOP | RR_TX_STOP)) != 0) {
b = set_cmd_header(b, port, 63);
*b = 0;
if ((send & RR_TX_STOP) != 0)
*b |= EV_OPU;
if ((send & RR_RX_STOP) != 0)
*b |= EV_IPU;
b++;
ch->ch_send &= ~(RR_RX_STOP | RR_TX_STOP);
}
if ((send & (RR_RX_START | RR_TX_START)) != 0) {
b = set_cmd_header(b, port, 64);
*b = 0;
if ((send & RR_TX_START) != 0)
*b |= EV_OPU | EV_OPS | EV_OPX;
if ((send & RR_RX_START) != 0)
*b |= EV_IPU | EV_IPS;
b++;
ch->ch_send &= ~(RR_RX_START | RR_TX_START);
}
}
rwin = (ch->ch_s_rin +
((ch->ch_rout - ch->ch_rin - 1) & RBUF_MASK));
n = (rwin - ch->ch_s_rwin) & 0xffff;
if (n >= RBUF_MAX / 4) {
b[0] = 0xa0 + (port & 0xf);
ch->ch_s_rwin = rwin;
put_unaligned_be16(rwin, b + 1);
b += 3;
}
n = (ch->ch_tin - ch->ch_tout) & TBUF_MASK;
if ((ch->ch_tun.un_flag & (UN_EMPTY|UN_LOW)) != 0) {
if ((ch->ch_tun.un_flag & UN_LOW) != 0 ?
(n <= TBUF_LOW) :
(n == 0 && ch->ch_s_tpos == ch->ch_s_tin)) {
ch->ch_tun.un_flag &= ~(UN_EMPTY|UN_LOW);
if (waitqueue_active(&((ch->ch_tun.un_tty)->write_wait)))
wake_up_interruptible(&((ch->ch_tun.un_tty)->write_wait));
tty_wakeup(ch->ch_tun.un_tty);
n = (ch->ch_tin - ch->ch_tout) & TBUF_MASK;
}
}
if (ch->ch_pun.un_open_count &&
(ch->ch_pun.un_flag &
(UN_EMPTY|UN_TIME|UN_LOW|UN_PWAIT)) != 0) {
if ((ch->ch_pun.un_flag & UN_LOW) != 0 ?
(n <= TBUF_LOW) :
(ch->ch_pun.un_flag & UN_TIME) != 0 ?
((jiffies - ch->ch_waketime) >= 0) :
(n == 0 && ch->ch_s_tpos == ch->ch_s_tin) &&
((ch->ch_pun.un_flag & UN_EMPTY) != 0 ||
((ch->ch_tun.un_open_count &&
ch->ch_tun.un_tty->ops->chars_in_buffer) ?
(ch->ch_tun.un_tty->ops->chars_in_buffer)(ch->ch_tun.un_tty) == 0
: 1
)
)) {
ch->ch_pun.un_flag &= ~(UN_EMPTY | UN_TIME | UN_LOW | UN_PWAIT);
if (waitqueue_active(&((ch->ch_pun.un_tty)->write_wait)))
wake_up_interruptible(&((ch->ch_pun.un_tty)->write_wait));
tty_wakeup(ch->ch_pun.un_tty);
n = (ch->ch_tin - ch->ch_tout) & TBUF_MASK;
} else if ((ch->ch_pun.un_flag & UN_TIME) != 0) {
work = 1;
}
}
t = ((ch->ch_s_tsize + ch->ch_s_tpos - ch->ch_s_tin) & 0xffff);
if (n > t)
n = t;
if (n != 0) {
n += (n <= 8 ? 1 : n <= 255 ? 2 : 3);
tdata[tchan++] = n;
ttotal += n;
}
break;
send_close:
case CS_SEND_CLOSE:
b = set_cmd_header(b, port, 10);
if (ch->ch_otype == OTYPE_IMMEDIATE)
*b++ = 3;
else
*b++ = 4;
ch->ch_state = CS_WAIT_CLOSE;
break;
case CS_WAIT_OPEN:
case CS_WAIT_CANCEL:
case CS_WAIT_FAIL:
case CS_WAIT_QUERY:
case CS_WAIT_CLOSE:
break;
default:
pr_info("%s - unexpected channel state (%i)\n",
__func__, ch->ch_state);
}
}
if (mod != nd->nd_tx_module) {
if (b != mbuf) {
mbuf[-1] = 0xf0 | mod;
nd->nd_tx_module = mod;
} else {
b--;
}
}
}
n = UIO_MAX - UIO_BASE;
if (tmax > n)
tmax = n;
tmax -= 64;
tsafe = tmax;
tmax -= 5 + 3 + 4 * nd->nd_chan_count;
n = nd->nd_tx_deposit - nd->nd_tx_charge - nd->nd_link.lk_header_size;
if (tmax > n)
tmax = n;
tmax -= b - buf;
if (tmax < 2 * nd->nd_chan_count) {
tsend = 1;
} else if (tchan > 1 && ttotal > tmax) {
long tm = tmax;
int tc = tchan;
int try;
tsend = tm / tc;
for (try = 0; try < 3; try++) {
int i;
int c = 0;
for (i = 0; i < tc; i++) {
if (tsend < tdata[i])
tdata[c++] = tdata[i];
else
tm -= tdata[i];
}
if (c == tc)
break;
tsend = tm / c;
if (c == 1)
break;
tc = c;
}
tsend = tm / nd->nd_chan_count;
if (tsend < 2)
tsend = 1;
} else {
tsend = tmax;
}
tsend -= (tsend <= 9) ? 1 : (tsend <= 257) ? 2 : 3;
port = 0;
ch = nd->nd_chan;
used_buffer = tmax;
for (mod = 0; port < nd->nd_chan_count; mod++) {
if (mod != nd->nd_tx_module)
mbuf = ++b;
maxport = port + 16;
if (maxport > nd->nd_chan_count)
maxport = nd->nd_chan_count;
for (; port < maxport; port++, ch++) {
if (ch->ch_state != CS_READY)
continue;
lastport = port;
n = (ch->ch_tin - ch->ch_tout) & TBUF_MASK;
if (n != 0 && used_buffer > 0) {
t = (ch->ch_s_tsize + ch->ch_s_tpos - ch->ch_s_tin) & 0xffff;
if (n > t)
n = t;
if (n > tsend) {
work = 1;
n = tsend;
}
if (n > used_buffer) {
work = 1;
n = used_buffer;
}
if (n <= 0)
continue;
if (n <= 8) {
b[0] = ((n - 1) << 4) + (port & 0xf);
b += 1;
} else if (n <= 255) {
b[0] = 0x80 + (port & 0xf);
b[1] = n;
b += 2;
} else {
b[0] = 0x90 + (port & 0xf);
put_unaligned_be16(n, b + 1);
b += 3;
}
ch->ch_s_tin = (ch->ch_s_tin + n) & 0xffff;
t = TBUF_MAX - ch->ch_tout;
if (n >= t) {
memcpy(b, ch->ch_tbuf + ch->ch_tout, t);
b += t;
n -= t;
used_buffer -= t;
ch->ch_tout = 0;
}
memcpy(b, ch->ch_tbuf + ch->ch_tout, n);
b += n;
used_buffer -= n;
ch->ch_tout += n;
n = (ch->ch_tin - ch->ch_tout) & TBUF_MASK;
}
if (n > TBUF_LOW)
continue;
if ((ch->ch_flag & CH_LOW) != 0) {
ch->ch_flag &= ~CH_LOW;
wake_up_interruptible(&ch->ch_flag_wait);
}
if (ch->ch_tun.un_open_count) {
struct tty_struct *tty = (ch->ch_tun.un_tty);
if (waitqueue_active(&tty->write_wait))
wake_up_interruptible(&tty->write_wait);
tty_wakeup(tty);
}
if (ch->ch_pun.un_open_count) {
struct tty_struct *tty = (ch->ch_pun.un_tty);
if (waitqueue_active(&tty->write_wait))
wake_up_interruptible(&tty->write_wait);
tty_wakeup(tty);
}
if (n != 0)
continue;
if ((ch->ch_flag & (CH_EMPTY | CH_DRAIN)) != 0 ||
(ch->ch_pun.un_flag & UN_EMPTY) != 0) {
if (ch->ch_s_treq != ch->ch_s_tin) {
b = set_cmd_header(b, port, 43);
ch->ch_s_treq = ch->ch_s_tin;
put_unaligned_be16(ch->ch_s_treq,
b);
b += 2;
}
else if ((ch->ch_flag & CH_EMPTY) != 0 &&
(ch->ch_send & RR_TX_BREAK) == 0) {
ch->ch_flag &= ~CH_EMPTY;
wake_up_interruptible(&ch->ch_flag_wait);
}
}
}
if (mod != nd->nd_tx_module) {
if (b != mbuf) {
mbuf[-1] = 0xf0 | mod;
nd->nd_tx_module = mod;
} else {
b--;
}
}
}
in = nd->nd_seq_in;
if ((send_sync || nd->nd_seq_wait[in] != 0) && lastport >= 0) {
u8 *bb = b;
if (wanted_sync_port >= 0)
lastport = wanted_sync_port;
ch = nd->nd_chan + lastport;
ch->ch_flag |= CH_WAITING_SYNC;
mod = lastport >> 4;
if (mod != nd->nd_tx_module) {
bb[0] = 0xf0 + mod;
bb += 1;
nd->nd_tx_module = mod;
}
bb = set_cmd_header(bb, lastport, 12);
*bb++ = in;
nd->nd_seq_size[in] = bb - buf;
nd->nd_seq_time[in] = jiffies;
if (++in >= SEQ_MAX)
in = 0;
if (in != nd->nd_seq_out) {
b = bb;
nd->nd_seq_in = in;
nd->nd_unack += b - buf;
}
}
else if (nd->nd_seq_wait[in] != 0) {
nd->nd_seq_wait[in] = 0;
wake_up_interruptible(&nd->nd_seq_wque[in]);
}
if (b != buf) {
nd->nd_tx_time = jiffies;
} else if ((ulong)(jiffies - nd->nd_tx_time) >= IDLE_MAX) {
*b++ = 0xf0 | nd->nd_tx_module;
nd->nd_tx_time = jiffies;
}
n = b - buf;
if (n >= tsafe)
pr_info("%s - n(%i) >= tsafe(%i)\n",
__func__, n, tsafe);
if (tsend < 0)
dgrp_dump(buf, n);
nd->nd_tx_work = work;
return n;
}
static ssize_t dgrp_net_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
struct nd_struct *nd;
long n;
u8 *local_buf;
u8 *b;
ssize_t rtn;
nd = (struct nd_struct *)(file->private_data);
if (!nd)
return -ENXIO;
if (count < UIO_MIN)
return -EINVAL;
down(&nd->nd_net_semaphore);
nd->nd_read_count++;
nd->nd_tx_ready = 0;
if (nd->nd_remain > UIO_BASE)
pr_info_ratelimited("%s - nd_remain(%i) > UIO_BASE\n",
__func__, nd->nd_remain);
b = local_buf = nd->nd_iobuf + UIO_BASE;
switch (nd->nd_state) {
case NS_IDLE:
if (nd->nd_mon_buf)
dgrp_monitor_reset(nd);
b[0] = 0xfb;
b[1] = 0x01;
b += 2;
nd->nd_expect |= NR_IDENT;
b[0] = 0xfb;
b[1] = 0x02;
b += 2;
nd->nd_expect |= NR_CAPABILITY;
b[0] = 0xfb;
b[1] = 0x18;
b += 2;
nd->nd_expect |= NR_VPD;
nd->nd_state = NS_WAIT_QUERY;
break;
case NS_READY:
b = dgrp_send(nd, count) + local_buf;
break;
case NS_SEND_ERROR:
n = strlen(nd->nd_error);
b[0] = 0xff;
b[1] = n;
memcpy(b + 2, nd->nd_error, n);
b += 2 + n;
dgrp_net_idle(nd);
dgrp_chan_count(nd, 0);
break;
default:
break;
}
n = b - local_buf;
if (n != 0) {
nd->nd_send_count++;
nd->nd_tx_byte += n + nd->nd_link.lk_header_size;
nd->nd_tx_charge += n + nd->nd_link.lk_header_size;
}
rtn = copy_to_user((void __user *)buf, local_buf, n);
if (rtn) {
rtn = -EFAULT;
goto done;
}
*ppos += n;
rtn = n;
if (nd->nd_mon_buf)
dgrp_monitor_data(nd, RPDUMP_CLIENT, local_buf, n);
done:
up(&nd->nd_net_semaphore);
return rtn;
}
static void dgrp_receive(struct nd_struct *nd)
{
struct ch_struct *ch;
u8 *buf;
u8 *b;
u8 *dbuf;
char *error;
long port;
long dlen;
long plen;
long remain;
long n;
long mlast;
long elast;
long mstat;
long estat;
char ID[3];
nd->nd_tx_time = jiffies;
ID_TO_CHAR(nd->nd_ID, ID);
b = buf = nd->nd_iobuf;
remain = nd->nd_remain;
while (remain > 0) {
int n0 = b[0] >> 4;
int n1 = b[0] & 0x0f;
if (n0 <= 12) {
port = (nd->nd_rx_module << 4) + n1;
if (port >= nd->nd_chan_count) {
error = "Improper Port Number";
goto prot_error;
}
ch = nd->nd_chan + port;
} else {
port = -1;
ch = NULL;
}
switch (n0) {
case 0:
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
dlen = n0 + 1;
plen = dlen + 1;
dbuf = b + 1;
goto data;
case 8:
if (remain < 3)
goto done;
dlen = b[1];
plen = dlen + 2;
dbuf = b + 2;
goto data;
case 9:
if (remain < 4)
goto done;
dlen = get_unaligned_be16(b + 1);
plen = dlen + 3;
dbuf = b + 3;
data:
nd->nd_tx_work = 1;
if (ch->ch_state < CS_READY) {
error = "Data received before RWIN established";
goto prot_error;
}
n = (ch->ch_s_rwin - ch->ch_s_rin) & 0xffff;
if (dlen > n) {
error = "Receive data overrun";
goto prot_error;
}
if (ch->ch_edelay != DGRP_RTIME) {
if (ch->ch_rtime != ch->ch_edelay) {
ch->ch_rtime = ch->ch_edelay;
ch->ch_flag |= CH_PARAM;
}
} else if (dlen <= 3) {
if (ch->ch_rtime != 10) {
ch->ch_rtime = 10;
ch->ch_flag |= CH_PARAM;
}
} else {
if (ch->ch_rtime != DGRP_RTIME) {
ch->ch_rtime = DGRP_RTIME;
ch->ch_flag |= CH_PARAM;
}
}
if (remain < plen)
dlen -= plen - remain;
if ((ch->ch_flag & CH_RX_FLUSH) != 0 &&
((ch->ch_flush_seq - nd->nd_seq_out) & SEQ_MASK) >=
((nd->nd_seq_in - nd->nd_seq_out) & SEQ_MASK)) {
ch->ch_flag &= ~CH_RX_FLUSH;
}
ch->ch_s_rin = (ch->ch_s_rin + dlen) & 0xffff;
if (ch->ch_state == CS_READY &&
(ch->ch_tun.un_open_count != 0) &&
(ch->ch_tun.un_flag & UN_CLOSING) == 0 &&
(ch->ch_cflag & CF_CREAD) != 0 &&
(ch->ch_flag & (CH_BAUD0 | CH_RX_FLUSH)) == 0 &&
(ch->ch_send & RR_RX_FLUSH) == 0) {
if (ch->ch_rin + dlen >= RBUF_MAX) {
n = RBUF_MAX - ch->ch_rin;
memcpy(ch->ch_rbuf + ch->ch_rin, dbuf, n);
ch->ch_rin = 0;
dbuf += n;
dlen -= n;
}
memcpy(ch->ch_rbuf + ch->ch_rin, dbuf, dlen);
ch->ch_rin += dlen;
if ((ch->ch_flag & CH_FAST_READ) == 0 ||
ch->ch_inwait != 0) {
dgrp_input(ch);
}
if (waitqueue_active(&ch->ch_tun.un_tty->read_wait) &&
(ch->ch_flag & CH_FAST_READ) != 0)
wake_up_interruptible(&ch->ch_tun.un_tty->read_wait);
if ((ch->ch_flag & CH_INPUT) != 0) {
ch->ch_flag &= ~CH_INPUT;
wake_up_interruptible(&ch->ch_flag_wait);
}
}
if (remain < plen) {
dlen = plen - remain;
b = buf;
b[0] = 0x90 + n1;
put_unaligned_be16(dlen, b + 1);
remain = 3;
goto done;
}
break;
case 10:
plen = 3;
if (remain < plen)
goto done;
nd->nd_tx_work = 1;
{
ushort tpos = get_unaligned_be16(b + 1);
ushort ack = (tpos - ch->ch_s_tpos) & 0xffff;
ushort unack = (ch->ch_s_tin - ch->ch_s_tpos) & 0xffff;
ushort notify = (ch->ch_s_treq - ch->ch_s_tpos) & 0xffff;
if (ch->ch_state < CS_READY || ack > unack) {
error = "Improper Window Sequence";
goto prot_error;
}
ch->ch_s_tpos = tpos;
if (notify <= ack)
ch->ch_s_treq = tpos;
}
break;
case 11:
if (remain < 2)
goto done;
switch (b[1]) {
case 11:
plen = 6;
if (remain < plen)
goto done;
nd->nd_tx_work = 1;
{
int req = b[2];
int resp = b[3];
port = get_unaligned_be16(b + 4);
if (port >= nd->nd_chan_count) {
error = "Open channel number out of range";
goto prot_error;
}
ch = nd->nd_chan + port;
switch (ch->ch_state) {
case CS_IDLE:
if (ch->ch_otype_waiting != 0 &&
req == ch->ch_otype_waiting &&
resp == 0) {
ch->ch_otype = req;
ch->ch_otype_waiting = 0;
ch->ch_state = CS_SEND_QUERY;
break;
}
goto open_error;
case CS_WAIT_OPEN:
if (req == ch->ch_otype) {
switch (resp) {
case 0:
ch->ch_state = CS_SEND_QUERY;
break;
case 1:
case 2:
if (req != OTYPE_IMMEDIATE) {
ch->ch_otype_waiting = req;
ch->ch_state = CS_IDLE;
break;
}
default:
if (ch->ch_open_count != 0) {
ch->ch_flag |= CH_HANGUP;
dgrp_carrier(ch);
ch->ch_state = CS_IDLE;
break;
}
ch->ch_open_error = resp;
ch->ch_state = CS_IDLE;
wake_up_interruptible(&ch->ch_flag_wait);
}
break;
}
if (ch->ch_otype_waiting != 0 &&
req == ch->ch_otype_waiting &&
resp == 0) {
ch->ch_otype = ch->ch_otype_waiting;
ch->ch_otype_waiting = 0;
ch->ch_state = CS_WAIT_FAIL;
break;
}
goto open_error;
case CS_WAIT_FAIL:
if (req == OTYPE_IMMEDIATE) {
ch->ch_state = CS_SEND_QUERY;
break;
}
goto open_error;
case CS_WAIT_CANCEL:
if (req == ch->ch_otype_waiting &&
resp == 0) {
ch->ch_otype_waiting = 0;
break;
}
if (req == 4 && resp == 0) {
ch->ch_otype_waiting = 0;
ch->ch_state = CS_IDLE;
break;
}
goto open_error;
case CS_WAIT_CLOSE:
if (req >= 3) {
ch->ch_state = CS_IDLE;
break;
}
goto open_error;
open_error:
default:
{
error = "Improper Open Response";
goto prot_error;
}
}
}
break;
case 13:
plen = 3;
if (remain < plen)
goto done;
{
int seq = b[2];
int s;
if (ch->ch_flag & CH_WAITING_SYNC) {
ch->ch_flag &= ~(CH_WAITING_SYNC);
wake_up_interruptible(&ch->ch_flag_wait);
}
if (((seq - nd->nd_seq_out) & SEQ_MASK) >=
((nd->nd_seq_in - nd->nd_seq_out) & SEQ_MASK)) {
break;
}
for (s = nd->nd_seq_out;; s = (s + 1) & SEQ_MASK) {
if (nd->nd_seq_wait[s] != 0) {
nd->nd_seq_wait[s] = 0;
wake_up_interruptible(&nd->nd_seq_wque[s]);
}
nd->nd_unack -= nd->nd_seq_size[s];
if (s == seq)
break;
}
nd->nd_seq_out = (seq + 1) & SEQ_MASK;
}
break;
case 15:
plen = 6;
if (remain < plen)
goto done;
{
ch->ch_send &= ~RR_SEQUENCE;
ch->ch_expect &= ~RR_SEQUENCE;
}
goto check_query;
case 17:
plen = 5;
if (remain < plen)
goto done;
{
ch->ch_s_elast = get_unaligned_be16(b + 2);
ch->ch_s_mlast = b[4];
ch->ch_expect &= ~RR_STATUS;
ch->ch_send &= ~RR_STATUS;
ch->ch_flag &= ~CH_PHYS_CD;
dgrp_carrier(ch);
}
goto check_query;
case 19:
plen = 14;
if (remain < plen)
goto done;
break;
case 21:
plen = 6;
if (remain < plen)
goto done;
{
ch->ch_s_rsize = get_unaligned_be16(b + 2);
ch->ch_s_tsize = get_unaligned_be16(b + 4);
ch->ch_send &= ~RR_BUFFER;
ch->ch_expect &= ~RR_BUFFER;
}
goto check_query;
case 23:
plen = 32;
if (remain < plen)
goto done;
{
ch->ch_send &= ~RR_CAPABILITY;
ch->ch_expect &= ~RR_CAPABILITY;
}
check_query:
if (ch->ch_state == CS_WAIT_QUERY &&
(ch->ch_expect & (RR_SEQUENCE |
RR_STATUS |
RR_BUFFER |
RR_CAPABILITY)) == 0) {
ch->ch_tmax = ch->ch_s_tsize / 4;
if (ch->ch_edelay == DGRP_TTIME)
ch->ch_ttime = DGRP_TTIME;
else
ch->ch_ttime = ch->ch_edelay;
ch->ch_rmax = ch->ch_s_rsize / 4;
if (ch->ch_edelay == DGRP_RTIME)
ch->ch_rtime = DGRP_RTIME;
else
ch->ch_rtime = ch->ch_edelay;
ch->ch_rlow = 2 * ch->ch_s_rsize / 8;
ch->ch_rhigh = 6 * ch->ch_s_rsize / 8;
ch->ch_state = CS_READY;
nd->nd_tx_work = 1;
wake_up_interruptible(&ch->ch_flag_wait);
}
break;
default:
goto decode_error;
}
break;
case 12:
plen = 4;
if (remain < plen)
goto done;
mlast = ch->ch_s_mlast;
elast = ch->ch_s_elast;
mstat = ch->ch_s_mlast = b[1];
estat = ch->ch_s_elast = get_unaligned_be16(b + 2);
if (((mstat ^ mlast) & DM_CD) != 0)
dgrp_carrier(ch);
if ((estat & ~elast & EV_RXB) != 0 &&
(ch->ch_tun.un_open_count != 0) &&
I_BRKINT(ch->ch_tun.un_tty) &&
!(I_IGNBRK(ch->ch_tun.un_tty))) {
tty_buffer_request_room(ch->ch_tun.un_tty, 1);
tty_insert_flip_char(ch->ch_tun.un_tty, 0, TTY_BREAK);
tty_flip_buffer_push(ch->ch_tun.un_tty);
}
if ((~estat & elast & EV_TXB) != 0 &&
(ch->ch_expect & RR_TX_BREAK) != 0) {
nd->nd_tx_work = 1;
ch->ch_expect &= ~RR_TX_BREAK;
if (ch->ch_break_time != 0) {
ch->ch_send |= RR_TX_BREAK;
} else {
ch->ch_send &= ~RR_TX_BREAK;
ch->ch_flag &= ~CH_TX_BREAK;
wake_up_interruptible(&ch->ch_flag_wait);
}
}
break;
case 13:
case 14:
error = "Unrecognized command";
goto prot_error;
case 15:
switch (n1) {
case 0:
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 7:
plen = 1;
nd->nd_rx_module = n1;
break;
case 8:
plen = 2;
if (remain < plen)
goto done;
nd->nd_rx_module = b[1];
break;
case 11:
if (remain < 4)
goto done;
plen = get_unaligned_be16(b + 2);
if (plen < 12 || plen > 1000) {
error = "Response Packet length error";
goto prot_error;
}
nd->nd_tx_work = 1;
switch (b[1]) {
case 0:
nd->nd_send |= NR_ECHO;
break;
case 1:
nd->nd_send |= NR_IDENT;
break;
case 32:
nd->nd_send |= NR_PASSWORD;
break;
}
break;
case 12:
if (remain < 4)
goto done;
plen = get_unaligned_be16(b + 2);
if (plen < 4 || plen > 1000) {
error = "Response Packet length error";
goto prot_error;
}
nd->nd_tx_work = 1;
switch (b[1]) {
case 0:
nd->nd_expect &= ~NR_ECHO;
break;
case 1:
{
int desclen;
nd->nd_hw_ver = (b[8] << 8) | b[9];
nd->nd_sw_ver = (b[10] << 8) | b[11];
nd->nd_hw_id = b[6];
desclen = ((plen - 12) > MAX_DESC_LEN) ? MAX_DESC_LEN :
plen - 12;
if (desclen <= 0) {
error = "Response Packet desclen error";
goto prot_error;
}
strncpy(nd->nd_ps_desc, b + 12, desclen);
nd->nd_ps_desc[desclen] = 0;
}
nd->nd_expect &= ~NR_IDENT;
break;
case 2:
{
int nn = get_unaligned_be16(b + 4);
if (nn > CHAN_MAX)
nn = CHAN_MAX;
dgrp_chan_count(nd, nn);
}
nd->nd_expect &= ~NR_CAPABILITY;
break;
case 15:
case 24:
if (plen > 4) {
memcpy(nd->nd_vpd, b + 4, min(plen - 4, (long) VPDSIZE));
nd->nd_vpd_len = min(plen - 4, (long) VPDSIZE);
}
nd->nd_expect &= ~NR_VPD;
break;
default:
goto decode_error;
}
if (nd->nd_expect == 0 &&
nd->nd_state == NS_WAIT_QUERY) {
nd->nd_state = NS_READY;
}
break;
case 14:
if (remain < 4)
goto done;
plen = get_unaligned_be16(b + 2) + 4;
if (plen > 1000) {
error = "Debug Packet too large";
goto prot_error;
}
if (remain < plen)
goto done;
break;
case 15:
if (remain < 2)
goto done;
plen = 2 + b[1];
if (remain < plen)
goto done;
nd->nd_tx_work = 1;
n = b[plen];
b[plen] = 0;
b[plen] = n;
error = "Client Reset Acknowledge";
goto prot_error;
default:
goto decode_error;
}
break;
default:
goto decode_error;
}
b += plen;
remain -= plen;
}
done:
if (remain > 0 && b != buf)
memcpy(buf, b, remain);
nd->nd_remain = remain;
return;
decode_error:
error = "Protocol decode error";
prot_error:
nd->nd_remain = 0;
nd->nd_state = NS_SEND_ERROR;
nd->nd_error = error;
}
static ssize_t dgrp_net_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct nd_struct *nd;
ssize_t rtn = 0;
long n;
long total = 0;
nd = (struct nd_struct *)(file->private_data);
if (!nd)
return -ENXIO;
down(&nd->nd_net_semaphore);
nd->nd_write_count++;
if (count == 0) {
dgrp_net_idle(nd);
dgrp_chan_count(nd, 0);
goto unlock;
}
while (count > 0) {
n = UIO_MAX - nd->nd_remain;
if (n > count)
n = count;
nd->nd_rx_byte += n + nd->nd_link.lk_header_size;
rtn = copy_from_user(nd->nd_iobuf + nd->nd_remain,
(void __user *) buf + total, n);
if (rtn) {
rtn = -EFAULT;
goto unlock;
}
*ppos += n;
total += n;
count -= n;
if (nd->nd_mon_buf)
dgrp_monitor_data(nd, RPDUMP_SERVER,
nd->nd_iobuf + nd->nd_remain, n);
nd->nd_remain += n;
dgrp_receive(nd);
}
rtn = total;
unlock:
up(&nd->nd_net_semaphore);
return rtn;
}
static unsigned int dgrp_net_select(struct file *file,
struct poll_table_struct *table)
{
unsigned int retval = 0;
struct nd_struct *nd = file->private_data;
poll_wait(file, &nd->nd_tx_waitq, table);
if (nd->nd_tx_ready)
retval |= POLLIN | POLLRDNORM;
retval |= POLLOUT | POLLWRNORM;
return retval;
}
static long dgrp_net_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct nd_struct *nd;
int rtn = 0;
long size = _IOC_SIZE(cmd);
struct link_struct link;
nd = file->private_data;
if (_IOC_DIR(cmd) & _IOC_READ)
rtn = access_ok(VERIFY_WRITE, (void __user *) arg, size);
else if (_IOC_DIR(cmd) & _IOC_WRITE)
rtn = access_ok(VERIFY_READ, (void __user *) arg, size);
if (!rtn)
return rtn;
switch (cmd) {
case DIGI_SETLINK:
if (size != sizeof(struct link_struct))
return -EINVAL;
if (copy_from_user((void *)(&link), (void __user *) arg, size))
return -EFAULT;
if (link.lk_fast_rate < 9600)
link.lk_fast_rate = 9600;
if (link.lk_slow_rate < 2400)
link.lk_slow_rate = 2400;
if (link.lk_fast_rate > 10000000)
link.lk_fast_rate = 10000000;
if (link.lk_slow_rate > link.lk_fast_rate)
link.lk_slow_rate = link.lk_fast_rate;
if (link.lk_fast_delay > 2000)
link.lk_fast_delay = 2000;
if (link.lk_slow_delay > 10000)
link.lk_slow_delay = 10000;
if (link.lk_fast_delay < 60)
link.lk_fast_delay = 60;
if (link.lk_slow_delay < link.lk_fast_delay)
link.lk_slow_delay = link.lk_fast_delay;
if (link.lk_header_size < 2)
link.lk_header_size = 2;
if (link.lk_header_size > 128)
link.lk_header_size = 128;
link.lk_fast_rate /= 8 * 1000 / dgrp_poll_tick;
link.lk_slow_rate /= 8 * 1000 / dgrp_poll_tick;
link.lk_fast_delay /= dgrp_poll_tick;
link.lk_slow_delay /= dgrp_poll_tick;
nd->nd_link = link;
break;
case DIGI_GETLINK:
if (size != sizeof(struct link_struct))
return -EINVAL;
if (copy_to_user((void __user *)arg, (void *)(&nd->nd_link),
size))
return -EFAULT;
break;
default:
return -EINVAL;
}
return 0;
}
void dgrp_poll_handler(unsigned long arg)
{
struct dgrp_poll_data *poll_data;
struct nd_struct *nd;
struct link_struct *lk;
ulong time;
ulong poll_time;
ulong freq;
ulong lock_flags;
poll_data = (struct dgrp_poll_data *) arg;
freq = 1000 / poll_data->poll_tick;
poll_data->poll_round += 17;
if (poll_data->poll_round >= freq)
poll_data->poll_round -= freq;
list_for_each_entry(nd, &nd_struct_list, list) {
lk = &nd->nd_link;
nd->nd_read_count -= (nd->nd_read_count +
poll_data->poll_round) / freq;
nd->nd_write_count -= (nd->nd_write_count +
poll_data->poll_round) / freq;
nd->nd_send_count -= (nd->nd_send_count +
poll_data->poll_round) / freq;
nd->nd_tx_byte -= (nd->nd_tx_byte +
poll_data->poll_round) / freq;
nd->nd_rx_byte -= (nd->nd_rx_byte +
poll_data->poll_round) / freq;
if (lk->lk_slow_rate >= UIO_MAX) {
nd->nd_delay = 0;
nd->nd_rate = UIO_MAX;
nd->nd_tx_deposit = nd->nd_tx_charge + 3 * UIO_MAX;
nd->nd_tx_credit = 3 * UIO_MAX;
} else {
long rate;
long delay;
long deposit;
long charge;
long size;
long excess;
long seq_in = nd->nd_seq_in;
long seq_out = nd->nd_seq_out;
if (seq_in == seq_out) {
delay = 0;
rate = lk->lk_fast_rate;
}
else {
delay = ((jiffies - nd->nd_seq_time[seq_out])
- (nd->nd_seq_size[seq_out] /
lk->lk_fast_rate));
rate =
(delay <= lk->lk_fast_delay ?
lk->lk_fast_rate :
delay >= lk->lk_slow_delay ?
lk->lk_slow_rate :
(lk->lk_slow_rate +
(lk->lk_slow_delay - delay) *
(lk->lk_fast_rate - lk->lk_slow_rate) /
(lk->lk_slow_delay - lk->lk_fast_delay)
)
);
}
nd->nd_delay = delay;
nd->nd_rate = rate;
deposit = nd->nd_tx_deposit;
charge = nd->nd_tx_charge;
deposit += rate;
size = 2 * nd->nd_link.lk_header_size;
if (size < rate)
size = rate;
size *= 3;
excess = deposit - charge - size;
if (excess > 0)
deposit -= excess;
nd->nd_tx_deposit = deposit;
nd->nd_tx_credit = deposit - charge;
size = 3 * lk->lk_header_size;
if (nd->nd_tx_credit < size)
continue;
}
if (waitqueue_active(&nd->nd_tx_waitq) &&
(nd->nd_tx_work != 0 ||
(ulong)(jiffies - nd->nd_tx_time) >= IDLE_MAX)) {
nd->nd_tx_ready = 1;
wake_up_interruptible(&nd->nd_tx_waitq);
}
}
spin_lock_irqsave(&poll_data->poll_lock, lock_flags);
poll_data->node_active_count--;
if (poll_data->node_active_count > 0) {
poll_data->node_active_count++;
poll_time = poll_data->timer.expires +
poll_data->poll_tick * HZ / 1000;
time = poll_time - jiffies;
if (time >= 2 * poll_data->poll_tick)
poll_time = jiffies + dgrp_poll_tick * HZ / 1000;
poll_data->timer.expires = poll_time;
add_timer(&poll_data->timer);
}
spin_unlock_irqrestore(&poll_data->poll_lock, lock_flags);
}
