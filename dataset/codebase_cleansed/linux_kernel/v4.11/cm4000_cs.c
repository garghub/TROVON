static inline void xoutb(unsigned char val, unsigned short port)
{
pr_debug("outb(val=%.2x,port=%.4x)\n", val, port);
outb(val, port);
}
static inline unsigned char xinb(unsigned short port)
{
unsigned char val;
val = inb(port);
pr_debug("%.2x=inb(%.4x)\n", val, port);
return val;
}
static inline unsigned char invert_revert(unsigned char ch)
{
return bitrev8(~ch);
}
static void str_invert_revert(unsigned char *b, int len)
{
int i;
for (i = 0; i < len; i++)
b[i] = invert_revert(b[i]);
}
static unsigned int calc_baudv(unsigned char fidi)
{
unsigned int wcrcf, wbrcf, fi_rfu, di_rfu;
fi_rfu = 372;
di_rfu = 1;
switch ((fidi >> 4) & 0x0F) {
case 0x00:
wcrcf = 372;
break;
case 0x01:
wcrcf = 372;
break;
case 0x02:
wcrcf = 558;
break;
case 0x03:
wcrcf = 744;
break;
case 0x04:
wcrcf = 1116;
break;
case 0x05:
wcrcf = 1488;
break;
case 0x06:
wcrcf = 1860;
break;
case 0x07:
wcrcf = fi_rfu;
break;
case 0x08:
wcrcf = fi_rfu;
break;
case 0x09:
wcrcf = 512;
break;
case 0x0A:
wcrcf = 768;
break;
case 0x0B:
wcrcf = 1024;
break;
case 0x0C:
wcrcf = 1536;
break;
case 0x0D:
wcrcf = 2048;
break;
default:
wcrcf = fi_rfu;
break;
}
switch (fidi & 0x0F) {
case 0x00:
wbrcf = di_rfu;
break;
case 0x01:
wbrcf = 1;
break;
case 0x02:
wbrcf = 2;
break;
case 0x03:
wbrcf = 4;
break;
case 0x04:
wbrcf = 8;
break;
case 0x05:
wbrcf = 16;
break;
case 0x06:
wbrcf = 32;
break;
case 0x07:
wbrcf = di_rfu;
break;
case 0x08:
wbrcf = 12;
break;
case 0x09:
wbrcf = 20;
break;
default:
wbrcf = di_rfu;
break;
}
return (wcrcf / wbrcf);
}
static unsigned short io_read_num_rec_bytes(unsigned int iobase,
unsigned short *s)
{
unsigned short tmp;
tmp = *s = 0;
do {
*s = tmp;
tmp = inb(REG_NUM_BYTES(iobase)) |
(inb(REG_FLAGS0(iobase)) & 4 ? 0x100 : 0);
} while (tmp != *s);
return *s;
}
static int parse_atr(struct cm4000_dev *dev)
{
unsigned char any_t1, any_t0;
unsigned char ch, ifno;
int ix, done;
DEBUGP(3, dev, "-> parse_atr: dev->atr_len = %i\n", dev->atr_len);
if (dev->atr_len < 3) {
DEBUGP(5, dev, "parse_atr: atr_len < 3\n");
return 0;
}
if (dev->atr[0] == 0x3f)
set_bit(IS_INVREV, &dev->flags);
else
clear_bit(IS_INVREV, &dev->flags);
ix = 1;
ifno = 1;
ch = dev->atr[1];
dev->proto = 0;
any_t1 = any_t0 = done = 0;
dev->ta1 = 0x11;
do {
if (ifno == 1 && (ch & 0x10)) {
dev->ta1 = dev->atr[2];
DEBUGP(5, dev, "Card says FiDi is 0x%.2x\n", dev->ta1);
ifno++;
} else if ((ifno == 2) && (ch & 0x10)) {
dev->ta1 = 0x11;
ifno++;
}
DEBUGP(5, dev, "Yi=%.2x\n", ch & 0xf0);
ix += ((ch & 0x10) >> 4)
+((ch & 0x20) >> 5)
+ ((ch & 0x40) >> 6)
+ ((ch & 0x80) >> 7);
if (ch & 0x80) {
ch = dev->atr[ix];
if ((ch & 0x0f)) {
any_t1 = 1;
DEBUGP(5, dev, "card is capable of T=1\n");
} else {
any_t0 = 1;
DEBUGP(5, dev, "card is capable of T=0\n");
}
} else
done = 1;
} while (!done);
DEBUGP(5, dev, "ix=%d noHist=%d any_t1=%d\n",
ix, dev->atr[1] & 15, any_t1);
if (ix + 1 + (dev->atr[1] & 0x0f) + any_t1 != dev->atr_len) {
DEBUGP(5, dev, "length error\n");
return 0;
}
if (any_t0)
set_bit(IS_ANY_T0, &dev->flags);
if (any_t1) {
dev->atr_csum = 0;
#ifdef ATR_CSUM
for (i = 1; i < dev->atr_len; i++)
dev->atr_csum ^= dev->atr[i];
if (dev->atr_csum) {
set_bit(IS_BAD_CSUM, &dev->flags);
DEBUGP(5, dev, "bad checksum\n");
goto return_0;
}
#endif
if (any_t0 == 0)
dev->proto = 1;
set_bit(IS_ANY_T1, &dev->flags);
}
return 1;
}
static void set_cardparameter(struct cm4000_dev *dev)
{
int i;
unsigned int iobase = dev->p_dev->resource[0]->start;
u_int8_t stopbits = 0x02;
DEBUGP(3, dev, "-> set_cardparameter\n");
dev->flags1 = dev->flags1 | (((dev->baudv - 1) & 0x0100) >> 8);
xoutb(dev->flags1, REG_FLAGS1(iobase));
DEBUGP(5, dev, "flags1 = 0x%02x\n", dev->flags1);
xoutb((unsigned char)((dev->baudv - 1) & 0xFF), REG_BAUDRATE(iobase));
DEBUGP(5, dev, "baudv = %i -> write 0x%02x\n", dev->baudv,
((dev->baudv - 1) & 0xFF));
for (i = 0; i < ARRAY_SIZE(card_fixups); i++) {
if (!memcmp(dev->atr, card_fixups[i].atr,
card_fixups[i].atr_len))
stopbits = card_fixups[i].stopbits;
}
xoutb(stopbits, REG_STOPBITS(iobase));
DEBUGP(3, dev, "<- set_cardparameter\n");
}
static int set_protocol(struct cm4000_dev *dev, struct ptsreq *ptsreq)
{
unsigned long tmp, i;
unsigned short num_bytes_read;
unsigned char pts_reply[4];
ssize_t rc;
unsigned int iobase = dev->p_dev->resource[0]->start;
rc = 0;
DEBUGP(3, dev, "-> set_protocol\n");
DEBUGP(5, dev, "ptsreq->Protocol = 0x%.8x, ptsreq->Flags=0x%.8x, "
"ptsreq->pts1=0x%.2x, ptsreq->pts2=0x%.2x, "
"ptsreq->pts3=0x%.2x\n", (unsigned int)ptsreq->protocol,
(unsigned int)ptsreq->flags, ptsreq->pts1, ptsreq->pts2,
ptsreq->pts3);
dev->pts[0] = 0xff;
dev->pts[1] = 0x00;
tmp = ptsreq->protocol;
while ((tmp = (tmp >> 1)) > 0)
dev->pts[1]++;
dev->proto = dev->pts[1];
dev->pts[1] = (0x01 << 4) | (dev->pts[1]);
DEBUGP(5, dev, "Ta(1) from ATR is 0x%.2x\n", dev->ta1);
dev->pts[2] = fi_di_table[dev->ta1 & 0x0F][(dev->ta1 >> 4) & 0x0F];
dev->pts[3] = dev->pts[0] ^ dev->pts[1] ^ dev->pts[2];
DEBUGP(5, dev, "pts0=%.2x, pts1=%.2x, pts2=%.2x, pts3=%.2x\n",
dev->pts[0], dev->pts[1], dev->pts[2], dev->pts[3]);
if (test_bit(IS_INVREV, &dev->flags))
str_invert_revert(dev->pts, 4);
xoutb(0x80, REG_FLAGS0(iobase));
DEBUGP(5, dev, "Enable access to the messages buffer\n");
dev->flags1 = 0x20
| (test_bit(IS_INVREV, &dev->flags) ? 0x02 : 0x00)
| ((dev->baudv >> 8) & 0x01);
xoutb(dev->flags1, REG_FLAGS1(iobase));
DEBUGP(5, dev, "Enable message buffer -> flags1 = 0x%.2x\n",
dev->flags1);
DEBUGP(5, dev, "Write challenge to buffer: ");
for (i = 0; i < 4; i++) {
xoutb(i, REG_BUF_ADDR(iobase));
xoutb(dev->pts[i], REG_BUF_DATA(iobase));
#ifdef CM4000_DEBUG
pr_debug("0x%.2x ", dev->pts[i]);
}
pr_debug("\n");
#else
}
int io_detect_cm4000(unsigned int iobase, struct cm4000_dev *dev)
{
if (inb(REG_FLAGS0(iobase)) & 8) {
clear_bit(IS_ATR_VALID, &dev->flags);
set_bit(IS_CMM_ABSENT, &dev->flags);
return 0;
}
xoutb(dev->flags1 | 0x40, REG_FLAGS1(iobase));
if ((inb(REG_FLAGS0(iobase)) & 8) == 0) {
clear_bit(IS_ATR_VALID, &dev->flags);
set_bit(IS_CMM_ABSENT, &dev->flags);
return 0;
}
xoutb(dev->flags1, REG_FLAGS1(iobase));
return 1;
}
static void terminate_monitor(struct cm4000_dev *dev)
{
DEBUGP(3, dev, "-> terminate_monitor\n");
wait_event_interruptible(dev->devq,
test_and_set_bit(LOCK_MONITOR,
(void *)&dev->flags));
DEBUGP(5, dev, "Now allow last cycle of monitor!\n");
while (test_bit(LOCK_MONITOR, (void *)&dev->flags))
msleep(25);
DEBUGP(5, dev, "Delete timer\n");
del_timer_sync(&dev->timer);
#ifdef CM4000_DEBUG
dev->monitor_running = 0;
#endif
DEBUGP(3, dev, "<- terminate_monitor\n");
}
static void monitor_card(unsigned long p)
{
struct cm4000_dev *dev = (struct cm4000_dev *) p;
unsigned int iobase = dev->p_dev->resource[0]->start;
unsigned short s;
struct ptsreq ptsreq;
int i, atrc;
DEBUGP(7, dev, "-> monitor_card\n");
if (test_and_set_bit(LOCK_MONITOR, &dev->flags)) {
DEBUGP(4, dev, "About to stop monitor\n");
dev->rlen =
dev->rpos =
dev->atr_csum = dev->atr_len_retry = dev->cwarn = 0;
dev->mstate = M_FETCH_ATR;
clear_bit(LOCK_MONITOR, &dev->flags);
wake_up_interruptible(&dev->devq);
DEBUGP(2, dev, "<- monitor_card (we are done now)\n");
return;
}
if (test_and_set_bit(LOCK_IO, (void *)&dev->flags)) {
DEBUGP(4, dev, "Couldn't get IO lock\n");
goto return_with_timer;
}
dev->flags0 = xinb(REG_FLAGS0(iobase));
DEBUGP(7, dev, "dev->flags0 = 0x%2x\n", dev->flags0);
DEBUGP(7, dev, "smartcard present: %s\n",
dev->flags0 & 1 ? "yes" : "no");
DEBUGP(7, dev, "cardman present: %s\n",
dev->flags0 == 0xff ? "no" : "yes");
if ((dev->flags0 & 1) == 0
|| dev->flags0 == 0xff) {
dev->rlen =
dev->rpos =
dev->atr_csum = dev->atr_len_retry = dev->cwarn = 0;
dev->mstate = M_FETCH_ATR;
dev->flags &= 0x000000ff;
if (dev->flags0 == 0xff) {
DEBUGP(4, dev, "set IS_CMM_ABSENT bit\n");
set_bit(IS_CMM_ABSENT, &dev->flags);
} else if (test_bit(IS_CMM_ABSENT, &dev->flags)) {
DEBUGP(4, dev, "clear IS_CMM_ABSENT bit "
"(card is removed)\n");
clear_bit(IS_CMM_ABSENT, &dev->flags);
}
goto release_io;
} else if ((dev->flags0 & 1) && test_bit(IS_CMM_ABSENT, &dev->flags)) {
DEBUGP(4, dev, "clear IS_CMM_ABSENT bit (card is inserted)\n");
clear_bit(IS_CMM_ABSENT, &dev->flags);
}
if (test_bit(IS_ATR_VALID, &dev->flags) == 1) {
DEBUGP(7, dev, "believe ATR is already valid (do nothing)\n");
goto release_io;
}
switch (dev->mstate) {
unsigned char flags0;
case M_CARDOFF:
DEBUGP(4, dev, "M_CARDOFF\n");
flags0 = inb(REG_FLAGS0(iobase));
if (flags0 & 0x02) {
dev->mdelay = T_10MSEC;
} else {
xoutb(0x80, REG_FLAGS0(iobase));
dev->rlen =
dev->rpos =
dev->atr_csum =
dev->atr_len_retry = dev->cwarn = 0;
dev->mstate = M_FETCH_ATR;
dev->mdelay = T_50MSEC;
}
break;
case M_FETCH_ATR:
DEBUGP(4, dev, "M_FETCH_ATR\n");
xoutb(0x80, REG_FLAGS0(iobase));
DEBUGP(4, dev, "Reset BAUDV to 9600\n");
dev->baudv = 0x173;
xoutb(0x02, REG_STOPBITS(iobase));
xoutb(0x73, REG_BAUDRATE(iobase));
xoutb(0x21, REG_FLAGS1(iobase));
xoutb(dev->flags0 & 2 ? 0x46 : 0x44, REG_FLAGS0(iobase));
dev->mdelay = T_40MSEC;
dev->mstate = M_TIMEOUT_WAIT;
break;
case M_TIMEOUT_WAIT:
DEBUGP(4, dev, "M_TIMEOUT_WAIT\n");
io_read_num_rec_bytes(iobase, &dev->atr_len);
dev->mdelay = T_10MSEC;
dev->mstate = M_READ_ATR_LEN;
break;
case M_READ_ATR_LEN:
DEBUGP(4, dev, "M_READ_ATR_LEN\n");
#define MAX_ATR_LEN_RETRY 100
if (dev->atr_len == io_read_num_rec_bytes(iobase, &s)) {
if (dev->atr_len_retry++ >= MAX_ATR_LEN_RETRY) {
dev->mdelay = T_10MSEC;
dev->mstate = M_READ_ATR;
}
} else {
dev->atr_len = s;
dev->atr_len_retry = 0;
}
DEBUGP(4, dev, "Current ATR_LEN = %i\n", dev->atr_len);
break;
case M_READ_ATR:
DEBUGP(4, dev, "M_READ_ATR\n");
xoutb(0x80, REG_FLAGS0(iobase));
for (i = 0; i < dev->atr_len; i++) {
xoutb(i, REG_BUF_ADDR(iobase));
dev->atr[i] = inb(REG_BUF_DATA(iobase));
}
DEBUGP(4, dev, "Deactivate T_Active flags\n");
dev->flags1 = 0x01;
xoutb(dev->flags1, REG_FLAGS1(iobase));
set_bit(IS_ATR_PRESENT, &dev->flags);
if (dev->atr[0] == 0x03)
str_invert_revert(dev->atr, dev->atr_len);
atrc = parse_atr(dev);
if (atrc == 0) {
dev->mdelay = 0;
dev->mstate = M_BAD_CARD;
} else {
dev->mdelay = T_50MSEC;
dev->mstate = M_ATR_PRESENT;
set_bit(IS_ATR_VALID, &dev->flags);
}
if (test_bit(IS_ATR_VALID, &dev->flags) == 1) {
DEBUGP(4, dev, "monitor_card: ATR valid\n");
if ((test_bit(IS_AUTOPPS_ACT, &dev->flags) == 0) &&
(dev->ta1 != 0x11) &&
!(test_bit(IS_ANY_T0, &dev->flags) &&
test_bit(IS_ANY_T1, &dev->flags))) {
DEBUGP(4, dev, "Perform AUTOPPS\n");
set_bit(IS_AUTOPPS_ACT, &dev->flags);
ptsreq.protocol = (0x01 << dev->proto);
ptsreq.flags = 0x01;
ptsreq.pts1 = 0x00;
ptsreq.pts2 = 0x00;
ptsreq.pts3 = 0x00;
if (set_protocol(dev, &ptsreq) == 0) {
DEBUGP(4, dev, "AUTOPPS ret SUCC\n");
clear_bit(IS_AUTOPPS_ACT, &dev->flags);
wake_up_interruptible(&dev->atrq);
} else {
DEBUGP(4, dev, "AUTOPPS failed: "
"repower using defaults\n");
clear_bit(IS_ATR_PRESENT, &dev->flags);
clear_bit(IS_ATR_VALID, &dev->flags);
dev->rlen =
dev->rpos =
dev->atr_csum =
dev->atr_len_retry = dev->cwarn = 0;
dev->mstate = M_FETCH_ATR;
dev->mdelay = T_50MSEC;
}
} else {
set_cardparameter(dev);
if (test_bit(IS_AUTOPPS_ACT, &dev->flags) == 1)
DEBUGP(4, dev, "AUTOPPS already active "
"2nd try:use default values\n");
if (dev->ta1 == 0x11)
DEBUGP(4, dev, "No AUTOPPS necessary "
"TA(1)==0x11\n");
if (test_bit(IS_ANY_T0, &dev->flags)
&& test_bit(IS_ANY_T1, &dev->flags))
DEBUGP(4, dev, "Do NOT perform AUTOPPS "
"with multiprotocol cards\n");
clear_bit(IS_AUTOPPS_ACT, &dev->flags);
wake_up_interruptible(&dev->atrq);
}
} else {
DEBUGP(4, dev, "ATR invalid\n");
wake_up_interruptible(&dev->atrq);
}
break;
case M_BAD_CARD:
DEBUGP(4, dev, "M_BAD_CARD\n");
if (dev->cwarn == 0 || dev->cwarn == 10) {
set_bit(IS_BAD_CARD, &dev->flags);
dev_warn(&dev->p_dev->dev, MODULE_NAME ": ");
if (test_bit(IS_BAD_CSUM, &dev->flags)) {
DEBUGP(4, dev, "ATR checksum (0x%.2x, should "
"be zero) failed\n", dev->atr_csum);
}
#ifdef CM4000_DEBUG
else if (test_bit(IS_BAD_LENGTH, &dev->flags)) {
DEBUGP(4, dev, "ATR length error\n");
} else {
DEBUGP(4, dev, "card damaged or wrong way "
"inserted\n");
}
#endif
dev->cwarn = 0;
wake_up_interruptible(&dev->atrq);
}
dev->cwarn++;
dev->mdelay = T_100MSEC;
dev->mstate = M_FETCH_ATR;
break;
default:
DEBUGP(7, dev, "Unknown action\n");
break;
}
release_io:
DEBUGP(7, dev, "release_io\n");
clear_bit(LOCK_IO, &dev->flags);
wake_up_interruptible(&dev->ioq);
return_with_timer:
DEBUGP(7, dev, "<- monitor_card (returns with timer)\n");
mod_timer(&dev->timer, jiffies + dev->mdelay);
clear_bit(LOCK_MONITOR, &dev->flags);
}
static ssize_t cmm_read(struct file *filp, __user char *buf, size_t count,
loff_t *ppos)
{
struct cm4000_dev *dev = filp->private_data;
unsigned int iobase = dev->p_dev->resource[0]->start;
ssize_t rc;
int i, j, k;
DEBUGP(2, dev, "-> cmm_read(%s,%d)\n", current->comm, current->pid);
if (count == 0)
return 0;
if (!pcmcia_dev_present(dev->p_dev) ||
test_bit(IS_CMM_ABSENT, &dev->flags))
return -ENODEV;
if (test_bit(IS_BAD_CSUM, &dev->flags))
return -EIO;
if (wait_event_interruptible
(dev->atrq,
((filp->f_flags & O_NONBLOCK)
|| (test_bit(IS_ATR_PRESENT, (void *)&dev->flags) != 0)))) {
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
return -ERESTARTSYS;
}
if (test_bit(IS_ATR_VALID, &dev->flags) == 0)
return -EIO;
if (wait_event_interruptible
(dev->readq,
((filp->f_flags & O_NONBLOCK) || (dev->rpos < dev->rlen)))) {
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
return -ERESTARTSYS;
}
if (wait_event_interruptible
(dev->ioq,
((filp->f_flags & O_NONBLOCK)
|| (test_and_set_bit(LOCK_IO, (void *)&dev->flags) == 0)))) {
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
return -ERESTARTSYS;
}
rc = 0;
dev->flags0 = inb(REG_FLAGS0(iobase));
if ((dev->flags0 & 1) == 0
|| dev->flags0 == 0xff) {
clear_bit(IS_ATR_VALID, &dev->flags);
if (dev->flags0 & 1) {
set_bit(IS_CMM_ABSENT, &dev->flags);
rc = -ENODEV;
} else {
rc = -EIO;
}
goto release_io;
}
DEBUGP(4, dev, "begin read answer\n");
j = min(count, (size_t)(dev->rlen - dev->rpos));
k = dev->rpos;
if (k + j > 255)
j = 256 - k;
DEBUGP(4, dev, "read1 j=%d\n", j);
for (i = 0; i < j; i++) {
xoutb(k++, REG_BUF_ADDR(iobase));
dev->rbuf[i] = xinb(REG_BUF_DATA(iobase));
}
j = min(count, (size_t)(dev->rlen - dev->rpos));
if (k + j > 255) {
DEBUGP(4, dev, "read2 j=%d\n", j);
dev->flags1 |= 0x10;
xoutb(dev->flags1, REG_FLAGS1(iobase));
for (; i < j; i++) {
xoutb(k++, REG_BUF_ADDR(iobase));
dev->rbuf[i] = xinb(REG_BUF_DATA(iobase));
}
}
if (dev->proto == 0 && count > dev->rlen - dev->rpos && i) {
DEBUGP(4, dev, "T=0 and count > buffer\n");
dev->rbuf[i] = dev->rbuf[i - 1];
dev->rbuf[i - 1] = dev->procbyte;
j++;
}
count = j;
dev->rpos = dev->rlen + 1;
DEBUGP(4, dev, "Clear T1Active\n");
dev->flags1 &= 0xdf;
xoutb(dev->flags1, REG_FLAGS1(iobase));
xoutb(0, REG_FLAGS1(iobase));
if (!io_detect_cm4000(iobase, dev)) {
rc = -ENODEV;
goto release_io;
}
if (test_bit(IS_INVREV, &dev->flags) && count > 0)
str_invert_revert(dev->rbuf, count);
if (copy_to_user(buf, dev->rbuf, count))
rc = -EFAULT;
release_io:
clear_bit(LOCK_IO, &dev->flags);
wake_up_interruptible(&dev->ioq);
DEBUGP(2, dev, "<- cmm_read returns: rc = %zi\n",
(rc < 0 ? rc : count));
return rc < 0 ? rc : count;
}
static ssize_t cmm_write(struct file *filp, const char __user *buf,
size_t count, loff_t *ppos)
{
struct cm4000_dev *dev = filp->private_data;
unsigned int iobase = dev->p_dev->resource[0]->start;
unsigned short s;
unsigned char tmp;
unsigned char infolen;
unsigned char sendT0;
unsigned short nsend;
unsigned short nr;
ssize_t rc;
int i;
DEBUGP(2, dev, "-> cmm_write(%s,%d)\n", current->comm, current->pid);
if (count == 0)
return 0;
if (dev->proto == 0 && count < 4) {
DEBUGP(4, dev, "T0 short write\n");
return -EIO;
}
nr = count & 0x1ff;
sendT0 = dev->proto ? 0 : nr > 5 ? 0x08 : 0;
if (!pcmcia_dev_present(dev->p_dev) ||
test_bit(IS_CMM_ABSENT, &dev->flags))
return -ENODEV;
if (test_bit(IS_BAD_CSUM, &dev->flags)) {
DEBUGP(4, dev, "bad csum\n");
return -EIO;
}
if (wait_event_interruptible
(dev->atrq,
((filp->f_flags & O_NONBLOCK)
|| (test_bit(IS_ATR_PRESENT, (void *)&dev->flags) != 0)))) {
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
return -ERESTARTSYS;
}
if (test_bit(IS_ATR_VALID, &dev->flags) == 0) {
DEBUGP(4, dev, "invalid ATR\n");
return -EIO;
}
if (wait_event_interruptible
(dev->ioq,
((filp->f_flags & O_NONBLOCK)
|| (test_and_set_bit(LOCK_IO, (void *)&dev->flags) == 0)))) {
if (filp->f_flags & O_NONBLOCK)
return -EAGAIN;
return -ERESTARTSYS;
}
if (copy_from_user(dev->sbuf, buf, ((count > 512) ? 512 : count)))
return -EFAULT;
rc = 0;
dev->flags0 = inb(REG_FLAGS0(iobase));
if ((dev->flags0 & 1) == 0
|| dev->flags0 == 0xff) {
clear_bit(IS_ATR_VALID, &dev->flags);
if (dev->flags0 & 1) {
set_bit(IS_CMM_ABSENT, &dev->flags);
rc = -ENODEV;
} else {
DEBUGP(4, dev, "IO error\n");
rc = -EIO;
}
goto release_io;
}
xoutb(0x80, REG_FLAGS0(iobase));
if (!io_detect_cm4000(iobase, dev)) {
rc = -ENODEV;
goto release_io;
}
dev->flags1 |= (sendT0);
set_cardparameter(dev);
tmp = inb(REG_FLAGS1(iobase));
dev->flags1 = 0x20
| (sendT0)
| (test_bit(IS_INVREV, &dev->flags) ? 2 : 0)
| (((dev->baudv - 1) & 0x0100) >> 8);
DEBUGP(1, dev, "set dev->flags1 = 0x%.2x\n", dev->flags1);
xoutb(dev->flags1, REG_FLAGS1(iobase));
DEBUGP(4, dev, "Xmit data\n");
for (i = 0; i < nr; i++) {
if (i >= 256) {
dev->flags1 = 0x20
| (sendT0)
| (test_bit(IS_INVREV, &dev->flags) ? 2 : 0)
| (((dev->baudv - 1) & 0x0100) >> 8)
| 0x10;
DEBUGP(4, dev, "dev->flags = 0x%.2x - set address "
"high\n", dev->flags1);
xoutb(dev->flags1, REG_FLAGS1(iobase));
}
if (test_bit(IS_INVREV, &dev->flags)) {
DEBUGP(4, dev, "Apply inverse convention for 0x%.2x "
"-> 0x%.2x\n", (unsigned char)dev->sbuf[i],
invert_revert(dev->sbuf[i]));
xoutb(i, REG_BUF_ADDR(iobase));
xoutb(invert_revert(dev->sbuf[i]),
REG_BUF_DATA(iobase));
} else {
xoutb(i, REG_BUF_ADDR(iobase));
xoutb(dev->sbuf[i], REG_BUF_DATA(iobase));
}
}
DEBUGP(4, dev, "Xmit done\n");
if (dev->proto == 0) {
if (nr == 4) {
DEBUGP(4, dev, "T=0 assumes 0 byte reply\n");
xoutb(i, REG_BUF_ADDR(iobase));
if (test_bit(IS_INVREV, &dev->flags))
xoutb(0xff, REG_BUF_DATA(iobase));
else
xoutb(0x00, REG_BUF_DATA(iobase));
}
if (sendT0)
nsend = nr;
else {
if (nr == 4)
nsend = 5;
else {
nsend = 5 + (unsigned char)dev->sbuf[4];
if (dev->sbuf[4] == 0)
nsend += 0x100;
}
}
} else
nsend = nr;
if (test_bit(IS_INVREV, &dev->flags)) {
DEBUGP(4, dev, "T=0 set Procedure byte (inverse-reverse) "
"0x%.2x\n", invert_revert(dev->sbuf[1]));
xoutb(invert_revert(dev->sbuf[1]), REG_NUM_BYTES(iobase));
} else {
DEBUGP(4, dev, "T=0 set Procedure byte 0x%.2x\n", dev->sbuf[1]);
xoutb(dev->sbuf[1], REG_NUM_BYTES(iobase));
}
DEBUGP(1, dev, "set NumSendBytes = 0x%.2x\n",
(unsigned char)(nsend & 0xff));
xoutb((unsigned char)(nsend & 0xff), REG_NUM_SEND(iobase));
DEBUGP(1, dev, "Trigger CARDMAN CONTROLLER (0x%.2x)\n",
0x40
| (dev->flags0 & 2 ? 0 : 4)
|(dev->proto ? 0x10 : 0x08)
|(nsend & 0x100) >> 8 );
xoutb(0x40
| (dev->flags0 & 2 ? 0 : 4)
|(dev->proto ? 0x10 : 0x08)
|(nsend & 0x100) >> 8,
REG_FLAGS0(iobase));
if (dev->proto == 1) {
DEBUGP(4, dev, "Wait for xmit done\n");
for (i = 0; i < 1000; i++) {
if (inb(REG_FLAGS0(iobase)) & 0x08)
break;
msleep_interruptible(10);
}
if (i == 1000) {
DEBUGP(4, dev, "timeout waiting for xmit done\n");
rc = -EIO;
goto release_io;
}
}
infolen = 0;
if (dev->proto) {
for (i = 0; i < 6000; i++) {
io_read_num_rec_bytes(iobase, &s);
if (s >= 3) {
infolen = inb(REG_FLAGS1(iobase));
DEBUGP(4, dev, "infolen=%d\n", infolen);
break;
}
msleep_interruptible(10);
}
if (i == 6000) {
DEBUGP(4, dev, "timeout waiting for infoLen\n");
rc = -EIO;
goto release_io;
}
} else
clear_bit(IS_PROCBYTE_PRESENT, &dev->flags);
io_read_num_rec_bytes(iobase, &dev->rlen);
for (i = 0; i < 600; i++) {
if (dev->proto) {
if (dev->rlen >= infolen + 4)
break;
}
msleep_interruptible(10);
io_read_num_rec_bytes(iobase, &s);
if (s > dev->rlen) {
DEBUGP(1, dev, "NumRecBytes inc (reset timeout)\n");
i = 0;
dev->rlen = s;
}
else if (dev->proto == 0) {
if ((inb(REG_BUF_ADDR(iobase)) & 0x80)) {
DEBUGP(1, dev, "NoProcedure byte set\n");
} else {
DEBUGP(1, dev, "NoProcedure byte unset "
"(reset timeout)\n");
dev->procbyte = inb(REG_FLAGS1(iobase));
DEBUGP(1, dev, "Read procedure byte 0x%.2x\n",
dev->procbyte);
i = 0;
}
if (inb(REG_FLAGS0(iobase)) & 0x08) {
DEBUGP(1, dev, "T0Done flag (read reply)\n");
break;
}
}
if (dev->proto)
infolen = inb(REG_FLAGS1(iobase));
}
if (i == 600) {
DEBUGP(1, dev, "timeout waiting for numRecBytes\n");
rc = -EIO;
goto release_io;
} else {
if (dev->proto == 0) {
DEBUGP(1, dev, "Wait for T0Done bit to be set\n");
for (i = 0; i < 1000; i++) {
if (inb(REG_FLAGS0(iobase)) & 0x08)
break;
msleep_interruptible(10);
}
if (i == 1000) {
DEBUGP(1, dev, "timeout waiting for T0Done\n");
rc = -EIO;
goto release_io;
}
dev->procbyte = inb(REG_FLAGS1(iobase));
DEBUGP(4, dev, "Read procedure byte 0x%.2x\n",
dev->procbyte);
io_read_num_rec_bytes(iobase, &dev->rlen);
DEBUGP(4, dev, "Read NumRecBytes = %i\n", dev->rlen);
}
}
dev->rpos = dev->proto ? 0 : nr == 4 ? 5 : nr > dev->rlen ? 5 : nr;
DEBUGP(4, dev, "dev->rlen = %i, dev->rpos = %i, nr = %i\n",
dev->rlen, dev->rpos, nr);
release_io:
DEBUGP(4, dev, "Reset SM\n");
xoutb(0x80, REG_FLAGS0(iobase));
if (rc < 0) {
DEBUGP(4, dev, "Write failed but clear T_Active\n");
dev->flags1 &= 0xdf;
xoutb(dev->flags1, REG_FLAGS1(iobase));
}
clear_bit(LOCK_IO, &dev->flags);
wake_up_interruptible(&dev->ioq);
wake_up_interruptible(&dev->readq);
memset((char *)dev->sbuf, 0, 512);
DEBUGP(2, dev, "<- cmm_write\n");
return rc < 0 ? rc : nr;
}
static void start_monitor(struct cm4000_dev *dev)
{
DEBUGP(3, dev, "-> start_monitor\n");
if (!dev->monitor_running) {
DEBUGP(5, dev, "create, init and add timer\n");
setup_timer(&dev->timer, monitor_card, (unsigned long)dev);
dev->monitor_running = 1;
mod_timer(&dev->timer, jiffies);
} else
DEBUGP(5, dev, "monitor already running\n");
DEBUGP(3, dev, "<- start_monitor\n");
}
static void stop_monitor(struct cm4000_dev *dev)
{
DEBUGP(3, dev, "-> stop_monitor\n");
if (dev->monitor_running) {
DEBUGP(5, dev, "stopping monitor\n");
terminate_monitor(dev);
clear_bit(IS_ATR_VALID, &dev->flags);
clear_bit(IS_ATR_PRESENT, &dev->flags);
} else
DEBUGP(5, dev, "monitor already stopped\n");
DEBUGP(3, dev, "<- stop_monitor\n");
}
static long cmm_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
struct cm4000_dev *dev = filp->private_data;
unsigned int iobase = dev->p_dev->resource[0]->start;
struct inode *inode = file_inode(filp);
struct pcmcia_device *link;
int size;
int rc;
void __user *argp = (void __user *)arg;
#ifdef CM4000_DEBUG
char *ioctl_names[CM_IOC_MAXNR + 1] = {
[_IOC_NR(CM_IOCGSTATUS)] "CM_IOCGSTATUS",
[_IOC_NR(CM_IOCGATR)] "CM_IOCGATR",
[_IOC_NR(CM_IOCARDOFF)] "CM_IOCARDOFF",
[_IOC_NR(CM_IOCSPTS)] "CM_IOCSPTS",
[_IOC_NR(CM_IOSDBGLVL)] "CM4000_DBGLVL",
};
DEBUGP(3, dev, "cmm_ioctl(device=%d.%d) %s\n", imajor(inode),
iminor(inode), ioctl_names[_IOC_NR(cmd)]);
#endif
mutex_lock(&cmm_mutex);
rc = -ENODEV;
link = dev_table[iminor(inode)];
if (!pcmcia_dev_present(link)) {
DEBUGP(4, dev, "DEV_OK false\n");
goto out;
}
if (test_bit(IS_CMM_ABSENT, &dev->flags)) {
DEBUGP(4, dev, "CMM_ABSENT flag set\n");
goto out;
}
rc = -EINVAL;
if (_IOC_TYPE(cmd) != CM_IOC_MAGIC) {
DEBUGP(4, dev, "ioctype mismatch\n");
goto out;
}
if (_IOC_NR(cmd) > CM_IOC_MAXNR) {
DEBUGP(4, dev, "iocnr mismatch\n");
goto out;
}
size = _IOC_SIZE(cmd);
rc = -EFAULT;
DEBUGP(4, dev, "iocdir=%.4x iocr=%.4x iocw=%.4x iocsize=%d cmd=%.4x\n",
_IOC_DIR(cmd), _IOC_READ, _IOC_WRITE, size, cmd);
if (_IOC_DIR(cmd) & _IOC_READ) {
if (!access_ok(VERIFY_WRITE, argp, size))
goto out;
}
if (_IOC_DIR(cmd) & _IOC_WRITE) {
if (!access_ok(VERIFY_READ, argp, size))
goto out;
}
rc = 0;
switch (cmd) {
case CM_IOCGSTATUS:
DEBUGP(4, dev, " ... in CM_IOCGSTATUS\n");
{
int status;
status = dev->flags0 & 3;
if (test_bit(IS_ATR_PRESENT, &dev->flags))
status |= CM_ATR_PRESENT;
if (test_bit(IS_ATR_VALID, &dev->flags))
status |= CM_ATR_VALID;
if (test_bit(IS_CMM_ABSENT, &dev->flags))
status |= CM_NO_READER;
if (test_bit(IS_BAD_CARD, &dev->flags))
status |= CM_BAD_CARD;
if (copy_to_user(argp, &status, sizeof(int)))
rc = -EFAULT;
}
break;
case CM_IOCGATR:
DEBUGP(4, dev, "... in CM_IOCGATR\n");
{
struct atreq __user *atreq = argp;
int tmp;
if (wait_event_interruptible
(dev->atrq,
((filp->f_flags & O_NONBLOCK)
|| (test_bit(IS_ATR_PRESENT, (void *)&dev->flags)
!= 0)))) {
if (filp->f_flags & O_NONBLOCK)
rc = -EAGAIN;
else
rc = -ERESTARTSYS;
break;
}
rc = -EFAULT;
if (test_bit(IS_ATR_VALID, &dev->flags) == 0) {
tmp = -1;
if (copy_to_user(&(atreq->atr_len), &tmp,
sizeof(int)))
break;
} else {
if (copy_to_user(atreq->atr, dev->atr,
dev->atr_len))
break;
tmp = dev->atr_len;
if (copy_to_user(&(atreq->atr_len), &tmp, sizeof(int)))
break;
}
rc = 0;
break;
}
case CM_IOCARDOFF:
#ifdef CM4000_DEBUG
DEBUGP(4, dev, "... in CM_IOCARDOFF\n");
if (dev->flags0 & 0x01) {
DEBUGP(4, dev, " Card inserted\n");
} else {
DEBUGP(2, dev, " No card inserted\n");
}
if (dev->flags0 & 0x02) {
DEBUGP(4, dev, " Card powered\n");
} else {
DEBUGP(2, dev, " Card not powered\n");
}
#endif
if ((dev->flags0 & 0x01) && (dev->flags0 & 0x02)) {
if (wait_event_interruptible
(dev->ioq,
((filp->f_flags & O_NONBLOCK)
|| (test_and_set_bit(LOCK_IO, (void *)&dev->flags)
== 0)))) {
if (filp->f_flags & O_NONBLOCK)
rc = -EAGAIN;
else
rc = -ERESTARTSYS;
break;
}
DEBUGP(4, dev, "Set Flags0=0x42 \n");
xoutb(0x42, REG_FLAGS0(iobase));
clear_bit(IS_ATR_PRESENT, &dev->flags);
clear_bit(IS_ATR_VALID, &dev->flags);
dev->mstate = M_CARDOFF;
clear_bit(LOCK_IO, &dev->flags);
if (wait_event_interruptible
(dev->atrq,
((filp->f_flags & O_NONBLOCK)
|| (test_bit(IS_ATR_VALID, (void *)&dev->flags) !=
0)))) {
if (filp->f_flags & O_NONBLOCK)
rc = -EAGAIN;
else
rc = -ERESTARTSYS;
break;
}
}
clear_bit(LOCK_IO, &dev->flags);
wake_up_interruptible(&dev->ioq);
rc = 0;
break;
case CM_IOCSPTS:
{
struct ptsreq krnptsreq;
if (copy_from_user(&krnptsreq, argp,
sizeof(struct ptsreq))) {
rc = -EFAULT;
break;
}
rc = 0;
DEBUGP(4, dev, "... in CM_IOCSPTS\n");
if (wait_event_interruptible
(dev->atrq,
((filp->f_flags & O_NONBLOCK)
|| (test_bit(IS_ATR_PRESENT, (void *)&dev->flags)
!= 0)))) {
if (filp->f_flags & O_NONBLOCK)
rc = -EAGAIN;
else
rc = -ERESTARTSYS;
break;
}
if (wait_event_interruptible
(dev->ioq,
((filp->f_flags & O_NONBLOCK)
|| (test_and_set_bit(LOCK_IO, (void *)&dev->flags)
== 0)))) {
if (filp->f_flags & O_NONBLOCK)
rc = -EAGAIN;
else
rc = -ERESTARTSYS;
break;
}
if ((rc = set_protocol(dev, &krnptsreq)) != 0) {
dev->mstate = M_FETCH_ATR;
clear_bit(IS_ATR_VALID, &dev->flags);
}
clear_bit(LOCK_IO, &dev->flags);
wake_up_interruptible(&dev->ioq);
}
break;
#ifdef CM4000_DEBUG
case CM_IOSDBGLVL:
rc = -ENOTTY;
break;
#endif
default:
DEBUGP(4, dev, "... in default (unknown IOCTL code)\n");
rc = -ENOTTY;
}
out:
mutex_unlock(&cmm_mutex);
return rc;
}
static int cmm_open(struct inode *inode, struct file *filp)
{
struct cm4000_dev *dev;
struct pcmcia_device *link;
int minor = iminor(inode);
int ret;
if (minor >= CM4000_MAX_DEV)
return -ENODEV;
mutex_lock(&cmm_mutex);
link = dev_table[minor];
if (link == NULL || !pcmcia_dev_present(link)) {
ret = -ENODEV;
goto out;
}
if (link->open) {
ret = -EBUSY;
goto out;
}
dev = link->priv;
filp->private_data = dev;
DEBUGP(2, dev, "-> cmm_open(device=%d.%d process=%s,%d)\n",
imajor(inode), minor, current->comm, current->pid);
ZERO_DEV(dev);
if (filp->f_flags & O_NONBLOCK) {
ret = -EAGAIN;
goto out;
}
dev->mdelay = T_50MSEC;
start_monitor(dev);
link->open = 1;
DEBUGP(2, dev, "<- cmm_open\n");
ret = nonseekable_open(inode, filp);
out:
mutex_unlock(&cmm_mutex);
return ret;
}
static int cmm_close(struct inode *inode, struct file *filp)
{
struct cm4000_dev *dev;
struct pcmcia_device *link;
int minor = iminor(inode);
if (minor >= CM4000_MAX_DEV)
return -ENODEV;
link = dev_table[minor];
if (link == NULL)
return -ENODEV;
dev = link->priv;
DEBUGP(2, dev, "-> cmm_close(maj/min=%d.%d)\n",
imajor(inode), minor);
stop_monitor(dev);
ZERO_DEV(dev);
link->open = 0;
wake_up(&dev->devq);
DEBUGP(2, dev, "cmm_close\n");
return 0;
}
static void cmm_cm4000_release(struct pcmcia_device * link)
{
struct cm4000_dev *dev = link->priv;
DEBUGP(3, dev, "-> cmm_cm4000_release\n");
while (link->open) {
printk(KERN_INFO MODULE_NAME ": delaying release until "
"process has terminated\n");
wait_event(dev->devq, (link->open == 0));
}
DEBUGP(3, dev, "<- cmm_cm4000_release\n");
return;
}
static int cm4000_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
return pcmcia_request_io(p_dev);
}
static int cm4000_config(struct pcmcia_device * link, int devno)
{
struct cm4000_dev *dev;
link->config_flags |= CONF_AUTO_SET_IO;
if (pcmcia_loop_config(link, cm4000_config_check, NULL))
goto cs_release;
if (pcmcia_enable_device(link))
goto cs_release;
dev = link->priv;
return 0;
cs_release:
cm4000_release(link);
return -ENODEV;
}
static int cm4000_suspend(struct pcmcia_device *link)
{
struct cm4000_dev *dev;
dev = link->priv;
stop_monitor(dev);
return 0;
}
static int cm4000_resume(struct pcmcia_device *link)
{
struct cm4000_dev *dev;
dev = link->priv;
if (link->open)
start_monitor(dev);
return 0;
}
static void cm4000_release(struct pcmcia_device *link)
{
cmm_cm4000_release(link);
pcmcia_disable_device(link);
}
static int cm4000_probe(struct pcmcia_device *link)
{
struct cm4000_dev *dev;
int i, ret;
for (i = 0; i < CM4000_MAX_DEV; i++)
if (dev_table[i] == NULL)
break;
if (i == CM4000_MAX_DEV) {
printk(KERN_NOTICE MODULE_NAME ": all devices in use\n");
return -ENODEV;
}
dev = kzalloc(sizeof(struct cm4000_dev), GFP_KERNEL);
if (dev == NULL)
return -ENOMEM;
dev->p_dev = link;
link->priv = dev;
dev_table[i] = link;
init_waitqueue_head(&dev->devq);
init_waitqueue_head(&dev->ioq);
init_waitqueue_head(&dev->atrq);
init_waitqueue_head(&dev->readq);
ret = cm4000_config(link, i);
if (ret) {
dev_table[i] = NULL;
kfree(dev);
return ret;
}
device_create(cmm_class, NULL, MKDEV(major, i), NULL, "cmm%d", i);
return 0;
}
static void cm4000_detach(struct pcmcia_device *link)
{
struct cm4000_dev *dev = link->priv;
int devno;
for (devno = 0; devno < CM4000_MAX_DEV; devno++)
if (dev_table[devno] == link)
break;
if (devno == CM4000_MAX_DEV)
return;
stop_monitor(dev);
cm4000_release(link);
dev_table[devno] = NULL;
kfree(dev);
device_destroy(cmm_class, MKDEV(major, devno));
return;
}
static int __init cmm_init(void)
{
int rc;
cmm_class = class_create(THIS_MODULE, "cardman_4000");
if (IS_ERR(cmm_class))
return PTR_ERR(cmm_class);
major = register_chrdev(0, DEVICE_NAME, &cm4000_fops);
if (major < 0) {
printk(KERN_WARNING MODULE_NAME
": could not get major number\n");
class_destroy(cmm_class);
return major;
}
rc = pcmcia_register_driver(&cm4000_driver);
if (rc < 0) {
unregister_chrdev(major, DEVICE_NAME);
class_destroy(cmm_class);
return rc;
}
return 0;
}
static void __exit cmm_exit(void)
{
pcmcia_unregister_driver(&cm4000_driver);
unregister_chrdev(major, DEVICE_NAME);
class_destroy(cmm_class);
}
