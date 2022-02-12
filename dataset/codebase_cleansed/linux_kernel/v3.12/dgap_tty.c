int dgap_tty_preinit(void)
{
unsigned long flags;
DGAP_LOCK(dgap_global_lock, flags);
dgap_TmpWriteBuf = kmalloc(WRITEBUFLEN, GFP_ATOMIC);
if (!dgap_TmpWriteBuf) {
DGAP_UNLOCK(dgap_global_lock, flags);
DPR_INIT(("unable to allocate tmp write buf"));
return (-ENOMEM);
}
DGAP_UNLOCK(dgap_global_lock, flags);
return(0);
}
int dgap_tty_register(struct board_t *brd)
{
int rc = 0;
DPR_INIT(("tty_register start"));
brd->SerialDriver = alloc_tty_driver(MAXPORTS);
snprintf(brd->SerialName, MAXTTYNAMELEN, "tty_dgap_%d_", brd->boardnum);
brd->SerialDriver->name = brd->SerialName;
brd->SerialDriver->name_base = 0;
brd->SerialDriver->major = 0;
brd->SerialDriver->minor_start = 0;
brd->SerialDriver->type = TTY_DRIVER_TYPE_SERIAL;
brd->SerialDriver->subtype = SERIAL_TYPE_NORMAL;
brd->SerialDriver->init_termios = DgapDefaultTermios;
brd->SerialDriver->driver_name = DRVSTR;
brd->SerialDriver->flags = (TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV | TTY_DRIVER_HARDWARE_BREAK);
brd->SerialDriver->ttys = dgap_driver_kzmalloc(MAXPORTS * sizeof(struct tty_struct *), GFP_KERNEL);
if (!brd->SerialDriver->ttys)
return(-ENOMEM);
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,28)
brd->SerialDriver->refcount = brd->TtyRefCnt;
#endif
tty_set_operations(brd->SerialDriver, &dgap_tty_ops);
brd->PrintDriver = alloc_tty_driver(MAXPORTS);
snprintf(brd->PrintName, MAXTTYNAMELEN, "pr_dgap_%d_", brd->boardnum);
brd->PrintDriver->name = brd->PrintName;
brd->PrintDriver->name_base = 0;
brd->PrintDriver->major = 0;
brd->PrintDriver->minor_start = 0;
brd->PrintDriver->type = TTY_DRIVER_TYPE_SERIAL;
brd->PrintDriver->subtype = SERIAL_TYPE_NORMAL;
brd->PrintDriver->init_termios = DgapDefaultTermios;
brd->PrintDriver->driver_name = DRVSTR;
brd->PrintDriver->flags = (TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV | TTY_DRIVER_HARDWARE_BREAK);
brd->PrintDriver->ttys = dgap_driver_kzmalloc(MAXPORTS * sizeof(struct tty_struct *), GFP_KERNEL);
if (!brd->PrintDriver->ttys)
return(-ENOMEM);
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,28)
brd->PrintDriver->refcount = brd->TtyRefCnt;
#endif
tty_set_operations(brd->PrintDriver, &dgap_tty_ops);
if (!brd->dgap_Major_Serial_Registered) {
rc = tty_register_driver(brd->SerialDriver);
if (rc < 0) {
APR(("Can't register tty device (%d)\n", rc));
return(rc);
}
brd->dgap_Major_Serial_Registered = TRUE;
dgap_BoardsByMajor[brd->SerialDriver->major] = brd;
brd->dgap_Serial_Major = brd->SerialDriver->major;
}
if (!brd->dgap_Major_TransparentPrint_Registered) {
rc = tty_register_driver(brd->PrintDriver);
if (rc < 0) {
APR(("Can't register Transparent Print device (%d)\n", rc));
return(rc);
}
brd->dgap_Major_TransparentPrint_Registered = TRUE;
dgap_BoardsByMajor[brd->PrintDriver->major] = brd;
brd->dgap_TransparentPrint_Major = brd->PrintDriver->major;
}
DPR_INIT(("DGAP REGISTER TTY: MAJORS: %d %d\n", brd->SerialDriver->major,
brd->PrintDriver->major));
return (rc);
}
int dgap_tty_init(struct board_t *brd)
{
int i;
int tlw;
uint true_count = 0;
uchar *vaddr;
uchar modem = 0;
struct channel_t *ch;
struct bs_t *bs;
struct cm_t *cm;
if (!brd)
return (-ENXIO);
DPR_INIT(("dgap_tty_init start\n"));
vaddr = brd->re_map_membase;
true_count = readw((vaddr + NCHAN));
brd->nasync = dgap_config_get_number_of_ports(brd);
if (!brd->nasync) {
brd->nasync = brd->maxports;
}
if (brd->nasync > brd->maxports) {
brd->nasync = brd->maxports;
}
if (true_count != brd->nasync) {
if ((brd->type == PPCM) && (true_count == 64)) {
APR(("***WARNING**** %s configured for %d ports, has %d ports.\nPlease make SURE the EBI cable running from the card\nto each EM module is plugged into EBI IN!\n",
brd->name, brd->nasync, true_count));
}
else if ((brd->type == PPCM) && (true_count == 0)) {
APR(("***WARNING**** %s configured for %d ports, has %d ports.\nPlease make SURE the EBI cable running from the card\nto each EM module is plugged into EBI IN!\n",
brd->name, brd->nasync, true_count));
}
else {
APR(("***WARNING**** %s configured for %d ports, has %d ports.\n",
brd->name, brd->nasync, true_count));
}
brd->nasync = true_count;
if (!brd->nasync) {
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
return(-ENXIO);
}
}
for (i = 0; i < brd->nasync; i++) {
if (!brd->channels[i]) {
brd->channels[i] = dgap_driver_kzmalloc(sizeof(struct channel_t), GFP_ATOMIC);
if (!brd->channels[i]) {
DPR_CORE(("%s:%d Unable to allocate memory for channel struct\n",
__FILE__, __LINE__));
}
}
}
ch = brd->channels[0];
vaddr = brd->re_map_membase;
bs = (struct bs_t *) ((ulong) vaddr + CHANBUF);
cm = (struct cm_t *) ((ulong) vaddr + CMDBUF);
brd->bd_bs = bs;
for (i = 0; i < brd->nasync; i++, ch = brd->channels[i], bs++) {
if (!brd->channels[i])
continue;
DGAP_SPINLOCK_INIT(ch->ch_lock);
ch->magic = DGAP_CHANNEL_MAGIC;
ch->ch_tun.magic = DGAP_UNIT_MAGIC;
ch->ch_tun.un_type = DGAP_SERIAL;
ch->ch_tun.un_ch = ch;
ch->ch_tun.un_dev = i;
ch->ch_pun.magic = DGAP_UNIT_MAGIC;
ch->ch_pun.un_type = DGAP_PRINT;
ch->ch_pun.un_ch = ch;
ch->ch_pun.un_dev = i;
ch->ch_vaddr = vaddr;
ch->ch_bs = bs;
ch->ch_cm = cm;
ch->ch_bd = brd;
ch->ch_portnum = i;
ch->ch_digi = dgap_digi_init;
if (dgap_config_get_altpin(brd)) {
ch->ch_dsr = DM_CD;
ch->ch_cd = DM_DSR;
ch->ch_digi.digi_flags |= DIGI_ALTPIN;
}
else {
ch->ch_cd = DM_CD;
ch->ch_dsr = DM_DSR;
}
ch->ch_taddr = vaddr + ((ch->ch_bs->tx_seg) << 4);
ch->ch_raddr = vaddr + ((ch->ch_bs->rx_seg) << 4);
ch->ch_tx_win = 0;
ch->ch_rx_win = 0;
ch->ch_tsize = readw(&(ch->ch_bs->tx_max)) + 1;
ch->ch_rsize = readw(&(ch->ch_bs->rx_max)) + 1;
ch->ch_tstart = 0;
ch->ch_rstart = 0;
ch->ch_close_delay = 250;
ch->ch_tlw = tlw = ch->ch_tsize >= 2000 ? ((ch->ch_tsize * 5) / 8) : ch->ch_tsize / 2;
dgap_cmdw(ch, STLOW, tlw, 0);
dgap_cmdw(ch, SRLOW, ch->ch_rsize / 2, 0);
dgap_cmdw(ch, SRHIGH, 7 * ch->ch_rsize / 8, 0);
ch->ch_mistat = readb(&(ch->ch_bs->m_stat));
init_waitqueue_head(&ch->ch_flags_wait);
init_waitqueue_head(&ch->ch_tun.un_flags_wait);
init_waitqueue_head(&ch->ch_pun.un_flags_wait);
init_waitqueue_head(&ch->ch_sniff_wait);
modem = (DM_CD | DM_DSR | DM_CTS | DM_RI);
writeb(modem, &(ch->ch_bs->m_int));
if (brd->intr_used)
writew(0, &(ch->ch_bs->edelay));
else
writew(100, &(ch->ch_bs->edelay));
writeb(1, &(ch->ch_bs->idata));
}
DPR_INIT(("dgap_tty_init finish\n"));
return (0);
}
void dgap_tty_post_uninit(void)
{
if (dgap_TmpWriteBuf) {
kfree(dgap_TmpWriteBuf);
dgap_TmpWriteBuf = NULL;
}
}
void dgap_tty_uninit(struct board_t *brd)
{
int i = 0;
if (brd->dgap_Major_Serial_Registered) {
dgap_BoardsByMajor[brd->SerialDriver->major] = NULL;
brd->dgap_Serial_Major = 0;
for (i = 0; i < brd->nasync; i++) {
dgap_remove_tty_sysfs(brd->channels[i]->ch_tun.un_sysfs);
tty_unregister_device(brd->SerialDriver, i);
}
tty_unregister_driver(brd->SerialDriver);
if (brd->SerialDriver->ttys) {
kfree(brd->SerialDriver->ttys);
brd->SerialDriver->ttys = NULL;
}
put_tty_driver(brd->SerialDriver);
brd->dgap_Major_Serial_Registered = FALSE;
}
if (brd->dgap_Major_TransparentPrint_Registered) {
dgap_BoardsByMajor[brd->PrintDriver->major] = NULL;
brd->dgap_TransparentPrint_Major = 0;
for (i = 0; i < brd->nasync; i++) {
dgap_remove_tty_sysfs(brd->channels[i]->ch_pun.un_sysfs);
tty_unregister_device(brd->PrintDriver, i);
}
tty_unregister_driver(brd->PrintDriver);
if (brd->PrintDriver->ttys) {
kfree(brd->PrintDriver->ttys);
brd->PrintDriver->ttys = NULL;
}
put_tty_driver(brd->PrintDriver);
brd->dgap_Major_TransparentPrint_Registered = FALSE;
}
}
static void dgap_sniff_nowait_nolock(struct channel_t *ch, uchar *text, uchar *buf, int len)
{
struct timeval tv;
int n;
int r;
int nbuf;
int i;
int tmpbuflen;
char tmpbuf[TMPBUFLEN];
char *p = tmpbuf;
int too_much_data;
if (!(ch->ch_sniff_flags & SNIFF_OPEN))
return;
do_gettimeofday(&tv);
p += sprintf(p, "<%ld %ld><%s><", tv.tv_sec, tv.tv_usec, text);
tmpbuflen = p - tmpbuf;
do {
too_much_data = 0;
for (i = 0; i < len && tmpbuflen < (TMPBUFLEN - 4); i++) {
p += sprintf(p, "%02x ", *buf);
buf++;
tmpbuflen = p - tmpbuf;
}
if (tmpbuflen < (TMPBUFLEN - 4)) {
if (i > 0)
p += sprintf(p - 1, "%s\n", ">");
else
p += sprintf(p, "%s\n", ">");
} else {
too_much_data = 1;
len -= i;
}
nbuf = strlen(tmpbuf);
p = tmpbuf;
while (nbuf > 0 && ch->ch_sniff_buf != 0) {
n = (ch->ch_sniff_out - ch->ch_sniff_in - 1) & SNIFF_MASK;
if (n == 0) {
return;
}
if (n > nbuf)
n = nbuf;
r = SNIFF_MAX - ch->ch_sniff_in;
if (r <= n) {
memcpy(ch->ch_sniff_buf + ch->ch_sniff_in, p, r);
n -= r;
ch->ch_sniff_in = 0;
p += r;
nbuf -= r;
}
memcpy(ch->ch_sniff_buf + ch->ch_sniff_in, p, n);
ch->ch_sniff_in += n;
p += n;
nbuf -= n;
if (ch->ch_sniff_flags & SNIFF_WAIT_DATA) {
ch->ch_sniff_flags &= ~SNIFF_WAIT_DATA;
wake_up_interruptible(&ch->ch_sniff_wait);
}
}
if (too_much_data) {
p = tmpbuf;
tmpbuflen = 0;
}
} while (too_much_data);
}
void dgap_input(struct channel_t *ch)
{
struct board_t *bd;
struct bs_t *bs;
struct tty_struct *tp;
struct tty_ldisc *ld;
uint rmask;
uint head;
uint tail;
int data_len;
ulong lock_flags;
ulong lock_flags2;
int flip_len;
int len = 0;
int n = 0;
uchar *buf;
uchar tmpchar;
int s = 0;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
tp = ch->ch_tun.un_tty;
bs = ch->ch_bs;
if (!bs) {
return;
}
bd = ch->ch_bd;
if(!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DPR_READ(("dgap_input start\n"));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
rmask = ch->ch_rsize - 1;
head = readw(&(bs->rx_head));
head &= rmask;
tail = readw(&(bs->rx_tail));
tail &= rmask;
data_len = (head - tail) & rmask;
if (data_len == 0) {
writeb(1, &(bs->idata));
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_READ(("No data on port %d\n", ch->ch_portnum));
return;
}
if ((bd->state != BOARD_READY) || !tp || (tp->magic != TTY_MAGIC) ||
!(ch->ch_tun.un_flags & UN_ISOPEN) || !(tp->termios.c_cflag & CREAD) ||
(ch->ch_tun.un_flags & UN_CLOSING)) {
DPR_READ(("input. dropping %d bytes on port %d...\n", data_len, ch->ch_portnum));
DPR_READ(("input. tp: %p tp->magic: %x MAGIC:%x ch flags: %x\n",
tp, tp ? tp->magic : 0, TTY_MAGIC, ch->ch_tun.un_flags));
writew(head, &(bs->rx_tail));
writeb(1, &(bs->idata));
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return;
}
if (ch->ch_flags & CH_RXBLOCK) {
writeb(1, &(bs->idata));
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_READ(("Port %d throttled, not reading any data. head: %x tail: %x\n",
ch->ch_portnum, head, tail));
return;
}
tmpchar = readb(&(bs->orun));
if (tmpchar) {
ch->ch_err_overrun++;
writeb(0, &(bs->orun));
}
DPR_READ(("dgap_input start 2\n"));
flip_len = TTY_FLIPBUF_SIZE;
len = min(data_len, flip_len);
len = min(len, (N_TTY_BUF_SIZE - 1));
ld = tty_ldisc_ref(tp);
#ifdef TTY_DONT_FLIP
if (test_bit(TTY_DONT_FLIP, &tp->flags))
len = 0;
#endif
if (!ld) {
len = 0;
} else {
if (!ld->ops->receive_buf) {
writew(head, &(bs->rx_tail));
len = 0;
}
}
if (len <= 0) {
writeb(1, &(bs->idata));
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_READ(("dgap_input 1 - finish\n"));
if (ld)
tty_ldisc_deref(ld);
return;
}
buf = ch->ch_bd->flipbuf;
n = len;
while (n) {
s = ((head >= tail) ? head : ch->ch_rsize) - tail;
s = min(s, n);
if (s <= 0)
break;
memcpy_fromio(buf, (char *) ch->ch_raddr + tail, s);
dgap_sniff_nowait_nolock(ch, "USER READ", buf, s);
tail += s;
buf += s;
n -= s;
tail &= rmask;
}
writew(tail, &(bs->rx_tail));
writeb(1, &(bs->idata));
ch->ch_rxcount += len;
if (I_PARMRK(tp) || I_BRKINT(tp) || I_INPCK(tp)) {
dgap_parity_scan(ch, ch->ch_bd->flipbuf, ch->ch_bd->flipflagbuf, &len);
len = tty_buffer_request_room(tp->port, len);
tty_insert_flip_string_flags(tp->port, ch->ch_bd->flipbuf,
ch->ch_bd->flipflagbuf, len);
}
else {
len = tty_buffer_request_room(tp->port, len);
tty_insert_flip_string(tp->port, ch->ch_bd->flipbuf, len);
}
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
tty_flip_buffer_push(tp->port);
if (ld)
tty_ldisc_deref(ld);
DPR_READ(("dgap_input - finish\n"));
}
void dgap_carrier(struct channel_t *ch)
{
struct board_t *bd;
int virt_carrier = 0;
int phys_carrier = 0;
DPR_CARR(("dgap_carrier called...\n"));
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
if (ch->ch_digi.digi_flags & DIGI_ALTPIN) {
ch->ch_dsr = DM_CD;
ch->ch_cd = DM_DSR;
}
else {
ch->ch_dsr = DM_DSR;
ch->ch_cd = DM_CD;
}
if (ch->ch_mistat & D_CD(ch)) {
DPR_CARR(("mistat: %x D_CD: %x\n", ch->ch_mistat, D_CD(ch)));
phys_carrier = 1;
}
if (ch->ch_digi.digi_flags & DIGI_FORCEDCD) {
virt_carrier = 1;
}
if (ch->ch_c_cflag & CLOCAL) {
virt_carrier = 1;
}
DPR_CARR(("DCD: physical: %d virt: %d\n", phys_carrier, virt_carrier));
if (((ch->ch_flags & CH_FCAR) == 0) && (virt_carrier == 1)) {
DPR_CARR(("carrier: virt DCD rose\n"));
if (waitqueue_active(&(ch->ch_flags_wait)))
wake_up_interruptible(&ch->ch_flags_wait);
}
if (((ch->ch_flags & CH_CD) == 0) && (phys_carrier == 1)) {
DPR_CARR(("carrier: physical DCD rose\n"));
if (waitqueue_active(&(ch->ch_flags_wait)))
wake_up_interruptible(&ch->ch_flags_wait);
}
if ((virt_carrier == 0) && ((ch->ch_flags & CH_CD) != 0) &&
(phys_carrier == 0))
{
if (waitqueue_active(&(ch->ch_flags_wait)))
wake_up_interruptible(&ch->ch_flags_wait);
if (ch->ch_tun.un_open_count > 0) {
DPR_CARR(("Sending tty hangup\n"));
tty_hangup(ch->ch_tun.un_tty);
}
if (ch->ch_pun.un_open_count > 0) {
DPR_CARR(("Sending pr hangup\n"));
tty_hangup(ch->ch_pun.un_tty);
}
}
if (virt_carrier == 1)
ch->ch_flags |= CH_FCAR;
else
ch->ch_flags &= ~CH_FCAR;
if (phys_carrier == 1)
ch->ch_flags |= CH_CD;
else
ch->ch_flags &= ~CH_CD;
}
static int dgap_tty_open(struct tty_struct *tty, struct file *file)
{
struct board_t *brd;
struct channel_t *ch;
struct un_t *un;
struct bs_t *bs;
uint major = 0;
uint minor = 0;
int rc = 0;
ulong lock_flags;
ulong lock_flags2;
u16 head;
rc = 0;
major = MAJOR(tty_devnum(tty));
minor = MINOR(tty_devnum(tty));
if (major > 255) {
return -ENXIO;
}
brd = dgap_BoardsByMajor[major];
if (!brd) {
return -ENXIO;
}
rc = wait_event_interruptible(brd->state_wait,
(brd->state & BOARD_READY));
if (rc) {
return rc;
}
DGAP_LOCK(brd->bd_lock, lock_flags);
if (brd->state != BOARD_READY) {
DGAP_UNLOCK(brd->bd_lock, lock_flags);
return -ENXIO;
}
if (MINOR(tty_devnum(tty)) > brd->nasync) {
DGAP_UNLOCK(brd->bd_lock, lock_flags);
return -ENXIO;
}
ch = brd->channels[minor];
if (!ch) {
DGAP_UNLOCK(brd->bd_lock, lock_flags);
return -ENXIO;
}
DGAP_LOCK(ch->ch_lock, lock_flags2);
if (major == brd->dgap_Serial_Major) {
un = &brd->channels[minor]->ch_tun;
un->un_type = DGAP_SERIAL;
}
else if (major == brd->dgap_TransparentPrint_Major) {
un = &brd->channels[minor]->ch_pun;
un->un_type = DGAP_PRINT;
}
else {
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(brd->bd_lock, lock_flags);
DPR_OPEN(("%d Unknown TYPE!\n", __LINE__));
return -ENXIO;
}
tty->driver_data = un;
DPR_OPEN(("Open called. MAJOR: %d MINOR:%d unit: %p NAME: %s\n",
MAJOR(tty_devnum(tty)), MINOR(tty_devnum(tty)), un, brd->name));
if ((bs = ch->ch_bs) == 0) {
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(brd->bd_lock, lock_flags);
DPR_OPEN(("%d BS is 0!\n", __LINE__));
return -ENXIO;
}
DPR_OPEN(("%d: tflag=%x pflag=%x\n", __LINE__, ch->ch_tun.un_flags, ch->ch_pun.un_flags));
if (!(un->un_flags & UN_ISOPEN)) {
un->un_tty = tty;
}
if (!((ch->ch_tun.un_flags | ch->ch_pun.un_flags) & UN_ISOPEN)) {
DPR_OPEN(("dgap_open: initializing channel in open...\n"));
ch->ch_mforce = 0;
ch->ch_mval = 0;
head = readw(&(bs->rx_head));
writew(head, &(bs->rx_tail));
ch->ch_flags = 0;
ch->pscan_state = 0;
ch->pscan_savechar = 0;
ch->ch_c_cflag = tty->termios.c_cflag;
ch->ch_c_iflag = tty->termios.c_iflag;
ch->ch_c_oflag = tty->termios.c_oflag;
ch->ch_c_lflag = tty->termios.c_lflag;
ch->ch_startc = tty->termios.c_cc[VSTART];
ch->ch_stopc = tty->termios.c_cc[VSTOP];
}
dgap_carrier(ch);
dgap_param(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(brd->bd_lock, lock_flags);
rc = dgap_block_til_ready(tty, file, ch);
if (!un->un_tty) {
return -ENODEV;
}
if (rc) {
DPR_OPEN(("dgap_tty_open returning after dgap_block_til_ready "
"with %d\n", rc));
}
DGAP_LOCK(ch->ch_lock, lock_flags);
ch->ch_open_count++;
un->un_open_count++;
un->un_flags |= (UN_ISOPEN);
DGAP_UNLOCK(ch->ch_lock, lock_flags);
DPR_OPEN(("dgap_tty_open finished\n"));
return (rc);
}
static int dgap_block_til_ready(struct tty_struct *tty, struct file *file, struct channel_t *ch)
{
int retval = 0;
struct un_t *un = NULL;
ulong lock_flags;
uint old_flags = 0;
int sleep_on_un_flags = 0;
if (!tty || tty->magic != TTY_MAGIC || !file || !ch || ch->magic != DGAP_CHANNEL_MAGIC) {
return (-ENXIO);
}
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC) {
return (-ENXIO);
}
DPR_OPEN(("dgap_block_til_ready - before block.\n"));
DGAP_LOCK(ch->ch_lock, lock_flags);
ch->ch_wopen++;
while (1) {
sleep_on_un_flags = 0;
if (ch->ch_bd->state == BOARD_FAILED) {
retval = -ENXIO;
break;
}
if (tty_hung_up_p(file)) {
retval = -EAGAIN;
break;
}
if (!((ch->ch_tun.un_flags | ch->ch_pun.un_flags) & UN_CLOSING)) {
if (file->f_flags & O_NONBLOCK) {
break;
}
if (tty->flags & (1 << TTY_IO_ERROR)) {
break;
}
if (ch->ch_flags & CH_CD) {
DPR_OPEN(("%d: ch_flags: %x\n", __LINE__, ch->ch_flags));
break;
}
if (ch->ch_flags & CH_FCAR) {
DPR_OPEN(("%d: ch_flags: %x\n", __LINE__, ch->ch_flags));
break;
}
}
else {
sleep_on_un_flags = 1;
}
if (signal_pending(current)) {
DPR_OPEN(("%d: signal pending...\n", __LINE__));
retval = -ERESTARTSYS;
break;
}
DPR_OPEN(("dgap_block_til_ready - blocking.\n"));
if (sleep_on_un_flags)
old_flags = ch->ch_tun.un_flags | ch->ch_pun.un_flags;
else
old_flags = ch->ch_flags;
DGAP_UNLOCK(ch->ch_lock, lock_flags);
DPR_OPEN(("Going to sleep on %s flags...\n",
(sleep_on_un_flags ? "un" : "ch")));
if (sleep_on_un_flags) {
retval = wait_event_interruptible(un->un_flags_wait,
(old_flags != (ch->ch_tun.un_flags | ch->ch_pun.un_flags)));
}
else {
retval = wait_event_interruptible(ch->ch_flags_wait,
(old_flags != ch->ch_flags));
}
DPR_OPEN(("After sleep... retval: %x\n", retval));
DGAP_LOCK(ch->ch_lock, lock_flags);
}
ch->ch_wopen--;
DGAP_UNLOCK(ch->ch_lock, lock_flags);
DPR_OPEN(("dgap_block_til_ready - after blocking.\n"));
if (retval) {
DPR_OPEN(("dgap_block_til_ready - done. error. retval: %x\n", retval));
return(retval);
}
DPR_OPEN(("dgap_block_til_ready - done no error. jiffies: %lu\n", jiffies));
return(0);
}
static void dgap_tty_hangup(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DPR_CLOSE(("dgap_hangup called. ch->ch_open_count: %d un->un_open_count: %d\n",
ch->ch_open_count, un->un_open_count));
dgap_tty_flush_buffer(tty);
DPR_CLOSE(("dgap_hangup finished. ch->ch_open_count: %d un->un_open_count: %d\n",
ch->ch_open_count, un->un_open_count));
}
static void dgap_tty_close(struct tty_struct *tty, struct file *file)
{
struct ktermios *ts;
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
int rc = 0;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
ts = &tty->termios;
DPR_CLOSE(("Close called\n"));
DGAP_LOCK(ch->ch_lock, lock_flags);
if ((tty->count == 1) && (un->un_open_count != 1)) {
APR(("tty->count is 1, un open count is %d\n", un->un_open_count));
un->un_open_count = 1;
}
if (--un->un_open_count < 0) {
APR(("bad serial port open count of %d\n", un->un_open_count));
un->un_open_count = 0;
}
ch->ch_open_count--;
if (ch->ch_open_count && un->un_open_count) {
DPR_CLOSE(("dgap_tty_close: not last close ch: %d un:%d\n",
ch->ch_open_count, un->un_open_count));
DGAP_UNLOCK(ch->ch_lock, lock_flags);
return;
}
DPR_CLOSE(("dgap_tty_close - last close on unit procedures\n"));
un->un_flags |= UN_CLOSING;
tty->closing = 1;
if ((ch->ch_open_count == 0) && !(ch->ch_digi.digi_flags & DIGI_PRINTER)) {
ch->ch_flags &= ~(CH_RXBLOCK);
DGAP_UNLOCK(ch->ch_lock, lock_flags);
DPR_CLOSE(("Calling wait_for_drain\n"));
rc = dgap_wait_for_drain(tty);
DPR_CLOSE(("After calling wait_for_drain\n"));
if (rc) {
DPR_BASIC(("dgap_tty_close - bad return: %d ", rc));
}
dgap_tty_flush_buffer(tty);
tty_ldisc_flush(tty);
DGAP_LOCK(ch->ch_lock, lock_flags);
tty->closing = 0;
if (ch->ch_c_cflag & HUPCL ) {
DPR_CLOSE(("Close. HUPCL set, dropping DTR/RTS\n"));
ch->ch_mostat &= ~(D_RTS(ch)|D_DTR(ch));
dgap_cmdb( ch, SMODEM, 0, D_DTR(ch)|D_RTS(ch), 0 );
if (ch->ch_close_delay) {
DPR_CLOSE(("Close. Sleeping for RTS/DTR drop\n"));
DGAP_UNLOCK(ch->ch_lock, lock_flags);
dgap_ms_sleep(ch->ch_close_delay);
DGAP_LOCK(ch->ch_lock, lock_flags);
DPR_CLOSE(("Close. After sleeping for RTS/DTR drop\n"));
}
}
ch->pscan_state = 0;
ch->pscan_savechar = 0;
ch->ch_baud_info = 0;
}
if ((un->un_type == DGAP_PRINT) && (ch->ch_flags & CH_PRON) ) {
dgap_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
ch->ch_flags &= ~CH_PRON;
}
un->un_tty = NULL;
un->un_flags &= ~(UN_ISOPEN | UN_CLOSING);
tty->driver_data = NULL;
DPR_CLOSE(("Close. Doing wakeups\n"));
wake_up_interruptible(&ch->ch_flags_wait);
wake_up_interruptible(&un->un_flags_wait);
DGAP_UNLOCK(ch->ch_lock, lock_flags);
DPR_BASIC(("dgap_tty_close - complete\n"));
}
static int dgap_tty_chars_in_buffer(struct tty_struct *tty)
{
struct board_t *bd = NULL;
struct channel_t *ch = NULL;
struct un_t *un = NULL;
struct bs_t *bs = NULL;
uchar tbusy;
uint chars = 0;
u16 thead, ttail, tmask, chead, ctail;
ulong lock_flags = 0;
ulong lock_flags2 = 0;
if (tty == NULL)
return(0);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (0);
bs = ch->ch_bs;
if (!bs)
return (0);
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
tmask = (ch->ch_tsize - 1);
thead = readw(&(bs->tx_head)) & tmask;
ttail = readw(&(bs->tx_tail)) & tmask;
tbusy = readb(&(bs->tbusy));
chead = readw(&(ch->ch_cm->cm_head));
ctail = readw(&(ch->ch_cm->cm_tail));
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
if ((ttail == thead) && (tbusy == 0) && (chead == ctail)) {
chars = 0;
}
else {
if (thead >= ttail)
chars = thead - ttail;
else
chars = thead - ttail + ch->ch_tsize;
if (chars == 0) {
if (tbusy != 0) {
DGAP_LOCK(ch->ch_lock, lock_flags);
un->un_flags |= UN_EMPTY;
writeb(1, &(bs->iempty));
DGAP_UNLOCK(ch->ch_lock, lock_flags);
}
chars = 1;
}
}
DPR_WRITE(("dgap_tty_chars_in_buffer. Port: %x - %d (head: %d tail: %d tsize: %d)\n",
ch->ch_portnum, chars, thead, ttail, ch->ch_tsize));
return(chars);
}
static int dgap_wait_for_drain(struct tty_struct *tty)
{
struct channel_t *ch;
struct un_t *un;
struct bs_t *bs;
int ret = -EIO;
uint count = 1;
ulong lock_flags = 0;
if (!tty || tty->magic != TTY_MAGIC)
return ret;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return ret;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return ret;
bs = ch->ch_bs;
if (!bs)
return ret;
ret = 0;
DPR_DRAIN(("dgap_wait_for_drain start\n"));
while (count != 0) {
count = dgap_tty_chars_in_buffer(tty);
if (count == 0)
break;
DGAP_LOCK(ch->ch_lock, lock_flags);
un->un_flags |= UN_EMPTY;
writeb(1, &(bs->iempty));
DGAP_UNLOCK(ch->ch_lock, lock_flags);
ret = wait_event_interruptible(un->un_flags_wait, ((un->un_flags & UN_EMPTY) == 0));
if (ret) {
break;
}
}
DGAP_LOCK(ch->ch_lock, lock_flags);
un->un_flags &= ~(UN_EMPTY);
DGAP_UNLOCK(ch->ch_lock, lock_flags);
DPR_DRAIN(("dgap_wait_for_drain finish\n"));
return (ret);
}
static int dgap_maxcps_room(struct tty_struct *tty, int bytes_available)
{
struct channel_t *ch = NULL;
struct un_t *un = NULL;
if (tty == NULL)
return (bytes_available);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (bytes_available);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (bytes_available);
if (un->un_type != DGAP_PRINT)
return (bytes_available);
if (ch->ch_digi.digi_maxcps > 0 && ch->ch_digi.digi_bufsize > 0 ) {
int cps_limit = 0;
unsigned long current_time = jiffies;
unsigned long buffer_time = current_time +
(HZ * ch->ch_digi.digi_bufsize) / ch->ch_digi.digi_maxcps;
if (ch->ch_cpstime < current_time) {
ch->ch_cpstime = current_time;
cps_limit = ch->ch_digi.digi_bufsize;
}
else if (ch->ch_cpstime < buffer_time) {
cps_limit = ((buffer_time - ch->ch_cpstime) * ch->ch_digi.digi_maxcps) / HZ;
}
else {
cps_limit = 0;
}
bytes_available = min(cps_limit, bytes_available);
}
return (bytes_available);
}
static inline void dgap_set_firmware_event(struct un_t *un, unsigned int event)
{
struct channel_t *ch = NULL;
struct bs_t *bs = NULL;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bs = ch->ch_bs;
if (!bs)
return;
if ((event & UN_LOW) != 0) {
if ((un->un_flags & UN_LOW) == 0) {
un->un_flags |= UN_LOW;
writeb(1, &(bs->ilow));
}
}
if ((event & UN_LOW) != 0) {
if ((un->un_flags & UN_EMPTY) == 0) {
un->un_flags |= UN_EMPTY;
writeb(1, &(bs->iempty));
}
}
}
static int dgap_tty_write_room(struct tty_struct *tty)
{
struct channel_t *ch = NULL;
struct un_t *un = NULL;
struct bs_t *bs = NULL;
u16 head, tail, tmask;
int ret = 0;
ulong lock_flags = 0;
if (tty == NULL || dgap_TmpWriteBuf == NULL)
return(0);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (0);
bs = ch->ch_bs;
if (!bs)
return (0);
DGAP_LOCK(ch->ch_lock, lock_flags);
tmask = ch->ch_tsize - 1;
head = readw(&(bs->tx_head)) & tmask;
tail = readw(&(bs->tx_tail)) & tmask;
if ((ret = tail - head - 1) < 0)
ret += ch->ch_tsize;
ret = dgap_maxcps_room(tty, ret);
if (un->un_type == DGAP_PRINT) {
if (!(ch->ch_flags & CH_PRON))
ret -= ch->ch_digi.digi_onlen;
ret -= ch->ch_digi.digi_offlen;
}
else {
if (ch->ch_flags & CH_PRON)
ret -= ch->ch_digi.digi_offlen;
}
if (ret < 0)
ret = 0;
dgap_set_firmware_event(un, UN_LOW | UN_EMPTY);
DGAP_UNLOCK(ch->ch_lock, lock_flags);
DPR_WRITE(("dgap_tty_write_room - %d tail: %d head: %d\n", ret, tail, head));
return(ret);
}
static int dgap_tty_put_char(struct tty_struct *tty, unsigned char c)
{
DPR_WRITE(("dgap_tty_put_char called\n"));
dgap_tty_write(tty, &c, 1);
return 1;
}
static int dgap_tty_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
struct channel_t *ch = NULL;
struct un_t *un = NULL;
struct bs_t *bs = NULL;
char *vaddr = NULL;
u16 head, tail, tmask, remain;
int bufcount = 0, n = 0;
int orig_count = 0;
ulong lock_flags;
int from_user = 0;
if (tty == NULL || dgap_TmpWriteBuf == NULL)
return(0);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (0);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return(0);
bs = ch->ch_bs;
if (!bs)
return(0);
if (!count)
return(0);
DPR_WRITE(("dgap_tty_write: Port: %x tty=%p user=%d len=%d\n",
ch->ch_portnum, tty, from_user, count));
orig_count = count;
DGAP_LOCK(ch->ch_lock, lock_flags);
tmask = ch->ch_tsize - 1;
head = readw(&(bs->tx_head)) & tmask;
tail = readw(&(bs->tx_tail)) & tmask;
if ((bufcount = tail - head - 1) < 0)
bufcount += ch->ch_tsize;
DPR_WRITE(("%d: bufcount: %x count: %x tail: %x head: %x tmask: %x\n",
__LINE__, bufcount, count, tail, head, tmask));
bufcount = dgap_maxcps_room(tty, bufcount);
count = min(count, bufcount);
if (count <= 0) {
dgap_set_firmware_event(un, UN_LOW | UN_EMPTY);
DGAP_UNLOCK(ch->ch_lock, lock_flags);
return(0);
}
if ((un->un_type == DGAP_PRINT) && !(ch->ch_flags & CH_PRON)) {
dgap_wmove(ch, ch->ch_digi.digi_onstr,
(int) ch->ch_digi.digi_onlen);
head = readw(&(bs->tx_head)) & tmask;
ch->ch_flags |= CH_PRON;
}
if ((un->un_type != DGAP_PRINT) && (ch->ch_flags & CH_PRON)) {
dgap_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
head = readw(&(bs->tx_head)) & tmask;
ch->ch_flags &= ~CH_PRON;
}
if (count <= 0) {
dgap_set_firmware_event(un, UN_LOW | UN_EMPTY);
DGAP_UNLOCK(ch->ch_lock, lock_flags);
return(0);
}
if (from_user) {
count = min(count, WRITEBUFLEN);
DGAP_UNLOCK(ch->ch_lock, lock_flags);
if (down_interruptible(&dgap_TmpWriteSem)) {
return (-EINTR);
}
if (copy_from_user(dgap_TmpWriteBuf, (const uchar __user *) buf, count)) {
up(&dgap_TmpWriteSem);
printk("Write: Copy from user failed!\n");
return -EFAULT;
}
DGAP_LOCK(ch->ch_lock, lock_flags);
buf = dgap_TmpWriteBuf;
}
n = count;
remain = ch->ch_tstart + ch->ch_tsize - head;
if (n >= remain) {
n -= remain;
vaddr = ch->ch_taddr + head;
memcpy_toio(vaddr, (uchar *) buf, remain);
dgap_sniff_nowait_nolock(ch, "USER WRITE", (uchar *) buf, remain);
head = ch->ch_tstart;
buf += remain;
}
if (n > 0) {
vaddr = ch->ch_taddr + head;
remain = n;
memcpy_toio(vaddr, (uchar *) buf, remain);
dgap_sniff_nowait_nolock(ch, "USER WRITE", (uchar *) buf, remain);
head += remain;
}
if (count) {
ch->ch_txcount += count;
head &= tmask;
writew(head, &(bs->tx_head));
}
dgap_set_firmware_event(un, UN_LOW | UN_EMPTY);
if ((un->un_type == DGAP_PRINT) && (ch->ch_flags & CH_PRON)) {
tail = readw(&(bs->tx_tail)) & tmask;
if (tail != head) {
un->un_flags |= UN_EMPTY;
writeb(1, &(bs->iempty));
}
else {
dgap_wmove(ch, ch->ch_digi.digi_offstr,
(int) ch->ch_digi.digi_offlen);
head = readw(&(bs->tx_head)) & tmask;
ch->ch_flags &= ~CH_PRON;
}
}
if ((un->un_type == DGAP_PRINT) && (ch->ch_digi.digi_maxcps > 0)
&& (ch->ch_digi.digi_bufsize > 0)) {
ch->ch_cpstime += (HZ * count) / ch->ch_digi.digi_maxcps;
}
if (from_user) {
DGAP_UNLOCK(ch->ch_lock, lock_flags);
up(&dgap_TmpWriteSem);
}
else {
DGAP_UNLOCK(ch->ch_lock, lock_flags);
}
DPR_WRITE(("Write finished - Write %d bytes of %d.\n", count, orig_count));
return (count);
}
static int dgap_tty_send_break(struct tty_struct *tty, int msec)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
int ret = -EIO;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return ret;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return ret;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return ret;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return ret;
switch (msec) {
case -1:
msec = 0xFFFF;
break;
case 0:
msec = 1;
break;
default:
msec /= 10;
break;
}
DPR_IOCTL(("dgap_tty_send_break start 1. %lx\n", jiffies));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
#if 0
dgap_cmdw(ch, SBREAK, (u16) SBREAK_TIME, 0);
#endif
dgap_cmdw(ch, SBREAK, (u16) msec, 0);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_send_break finish\n"));
return (0);
}
static void dgap_tty_wait_until_sent(struct tty_struct *tty, int timeout)
{
int rc;
rc = dgap_wait_for_drain(tty);
if (rc) {
DPR_IOCTL(("dgap_tty_ioctl - bad return: %d ", rc));
return;
}
return;
}
static void dgap_tty_send_xchar(struct tty_struct *tty, char c)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DPR_IOCTL(("dgap_tty_send_xchar start 1. %lx\n", jiffies));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
#if 0
if (c == STOP_CHAR(tty)) {
dgap_cmdw(ch, RPAUSE, 0, 0);
}
else if (c == START_CHAR(tty)) {
dgap_cmdw(ch, RRESUME, 0, 0);
}
else {
dgap_wmove(ch, &c, 1);
}
#else
dgap_wmove(ch, &c, 1);
#endif
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_send_xchar finish\n"));
return;
}
static int dgap_get_modem_info(struct channel_t *ch, unsigned int __user *value)
{
int result = 0;
uchar mstat = 0;
ulong lock_flags;
int rc = 0;
DPR_IOCTL(("dgap_get_modem_info start\n"));
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return(-ENXIO);
DGAP_LOCK(ch->ch_lock, lock_flags);
mstat = readb(&(ch->ch_bs->m_stat));
mstat |= ch->ch_mostat;
DGAP_UNLOCK(ch->ch_lock, lock_flags);
result = 0;
if (mstat & D_DTR(ch))
result |= TIOCM_DTR;
if (mstat & D_RTS(ch))
result |= TIOCM_RTS;
if (mstat & D_CTS(ch))
result |= TIOCM_CTS;
if (mstat & D_DSR(ch))
result |= TIOCM_DSR;
if (mstat & D_RI(ch))
result |= TIOCM_RI;
if (mstat & D_CD(ch))
result |= TIOCM_CD;
rc = put_user(result, value);
DPR_IOCTL(("dgap_get_modem_info finish\n"));
return(rc);
}
static int dgap_set_modem_info(struct tty_struct *tty, unsigned int command, unsigned int __user *value)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
int ret = -ENXIO;
unsigned int arg = 0;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return ret;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return ret;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return ret;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return ret;
DPR_IOCTL(("dgap_set_modem_info() start\n"));
ret = get_user(arg, value);
if (ret) {
DPR_IOCTL(("dgap_set_modem_info %d ret: %x. finished.\n", __LINE__, ret));
return(ret);
}
DPR_IOCTL(("dgap_set_modem_info: command: %x arg: %x\n", command, arg));
switch (command) {
case TIOCMBIS:
if (arg & TIOCM_RTS) {
ch->ch_mforce |= D_RTS(ch);
ch->ch_mval |= D_RTS(ch);
}
if (arg & TIOCM_DTR) {
ch->ch_mforce |= D_DTR(ch);
ch->ch_mval |= D_DTR(ch);
}
break;
case TIOCMBIC:
if (arg & TIOCM_RTS) {
ch->ch_mforce |= D_RTS(ch);
ch->ch_mval &= ~(D_RTS(ch));
}
if (arg & TIOCM_DTR) {
ch->ch_mforce |= D_DTR(ch);
ch->ch_mval &= ~(D_DTR(ch));
}
break;
case TIOCMSET:
ch->ch_mforce = D_DTR(ch)|D_RTS(ch);
if (arg & TIOCM_RTS) {
ch->ch_mval |= D_RTS(ch);
}
else {
ch->ch_mval &= ~(D_RTS(ch));
}
if (arg & TIOCM_DTR) {
ch->ch_mval |= (D_DTR(ch));
}
else {
ch->ch_mval &= ~(D_DTR(ch));
}
break;
default:
return(-EINVAL);
}
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
dgap_param(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_set_modem_info finish\n"));
return (0);
}
static int dgap_tty_digigeta(struct tty_struct *tty, struct digi_t __user *retinfo)
{
struct channel_t *ch;
struct un_t *un;
struct digi_t tmp;
ulong lock_flags;
if (!retinfo)
return (-EFAULT);
if (!tty || tty->magic != TTY_MAGIC)
return (-EFAULT);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (-EFAULT);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (-EFAULT);
memset(&tmp, 0, sizeof(tmp));
DGAP_LOCK(ch->ch_lock, lock_flags);
memcpy(&tmp, &ch->ch_digi, sizeof(tmp));
DGAP_UNLOCK(ch->ch_lock, lock_flags);
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return (-EFAULT);
return (0);
}
static int dgap_tty_digiseta(struct tty_struct *tty, struct digi_t __user *new_info)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
struct digi_t new_digi;
ulong lock_flags = 0;
unsigned long lock_flags2;
DPR_IOCTL(("DIGI_SETA start\n"));
if (!tty || tty->magic != TTY_MAGIC)
return (-EFAULT);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (-EFAULT);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (-EFAULT);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (-EFAULT);
if (copy_from_user(&new_digi, new_info, sizeof(struct digi_t))) {
DPR_IOCTL(("DIGI_SETA failed copy_from_user\n"));
return(-EFAULT);
}
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
memcpy(&ch->ch_digi, &new_digi, sizeof(struct digi_t));
if (ch->ch_digi.digi_maxcps < 1)
ch->ch_digi.digi_maxcps = 1;
if (ch->ch_digi.digi_maxcps > 10000)
ch->ch_digi.digi_maxcps = 10000;
if (ch->ch_digi.digi_bufsize < 10)
ch->ch_digi.digi_bufsize = 10;
if (ch->ch_digi.digi_maxchar < 1)
ch->ch_digi.digi_maxchar = 1;
if (ch->ch_digi.digi_maxchar > ch->ch_digi.digi_bufsize)
ch->ch_digi.digi_maxchar = ch->ch_digi.digi_bufsize;
if (ch->ch_digi.digi_onlen > DIGI_PLEN)
ch->ch_digi.digi_onlen = DIGI_PLEN;
if (ch->ch_digi.digi_offlen > DIGI_PLEN)
ch->ch_digi.digi_offlen = DIGI_PLEN;
dgap_param(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("DIGI_SETA finish\n"));
return(0);
}
static int dgap_tty_digigetedelay(struct tty_struct *tty, int __user *retinfo)
{
struct channel_t *ch;
struct un_t *un;
int tmp;
ulong lock_flags;
if (!retinfo)
return (-EFAULT);
if (!tty || tty->magic != TTY_MAGIC)
return (-EFAULT);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (-EFAULT);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (-EFAULT);
memset(&tmp, 0, sizeof(tmp));
DGAP_LOCK(ch->ch_lock, lock_flags);
tmp = readw(&(ch->ch_bs->edelay));
DGAP_UNLOCK(ch->ch_lock, lock_flags);
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return (-EFAULT);
return (0);
}
static int dgap_tty_digisetedelay(struct tty_struct *tty, int __user *new_info)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
int new_digi;
ulong lock_flags;
ulong lock_flags2;
DPR_IOCTL(("DIGI_SETA start\n"));
if (!tty || tty->magic != TTY_MAGIC)
return (-EFAULT);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (-EFAULT);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (-EFAULT);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (-EFAULT);
if (copy_from_user(&new_digi, new_info, sizeof(int))) {
DPR_IOCTL(("DIGI_SETEDELAY failed copy_from_user\n"));
return(-EFAULT);
}
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
writew((u16) new_digi, &(ch->ch_bs->edelay));
dgap_param(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("DIGI_SETA finish\n"));
return(0);
}
static int dgap_tty_digigetcustombaud(struct tty_struct *tty, int __user *retinfo)
{
struct channel_t *ch;
struct un_t *un;
int tmp;
ulong lock_flags;
if (!retinfo)
return (-EFAULT);
if (!tty || tty->magic != TTY_MAGIC)
return (-EFAULT);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (-EFAULT);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (-EFAULT);
memset(&tmp, 0, sizeof(tmp));
DGAP_LOCK(ch->ch_lock, lock_flags);
tmp = dgap_get_custom_baud(ch);
DGAP_UNLOCK(ch->ch_lock, lock_flags);
DPR_IOCTL(("DIGI_GETCUSTOMBAUD. Returning %d\n", tmp));
if (copy_to_user(retinfo, &tmp, sizeof(*retinfo)))
return (-EFAULT);
return (0);
}
static int dgap_tty_digisetcustombaud(struct tty_struct *tty, int __user *new_info)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
uint new_rate;
ulong lock_flags;
ulong lock_flags2;
DPR_IOCTL(("DIGI_SETCUSTOMBAUD start\n"));
if (!tty || tty->magic != TTY_MAGIC)
return (-EFAULT);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (-EFAULT);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (-EFAULT);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (-EFAULT);
if (copy_from_user(&new_rate, new_info, sizeof(unsigned int))) {
DPR_IOCTL(("DIGI_SETCUSTOMBAUD failed copy_from_user\n"));
return(-EFAULT);
}
if (bd->bd_flags & BD_FEP5PLUS) {
DPR_IOCTL(("DIGI_SETCUSTOMBAUD. Setting %d\n", new_rate));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
ch->ch_custom_speed = new_rate;
dgap_param(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
}
DPR_IOCTL(("DIGI_SETCUSTOMBAUD finish\n"));
return(0);
}
static void dgap_tty_set_termios(struct tty_struct *tty, struct ktermios *old_termios)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
unsigned long lock_flags;
unsigned long lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
ch->ch_c_cflag = tty->termios.c_cflag;
ch->ch_c_iflag = tty->termios.c_iflag;
ch->ch_c_oflag = tty->termios.c_oflag;
ch->ch_c_lflag = tty->termios.c_lflag;
ch->ch_startc = tty->termios.c_cc[VSTART];
ch->ch_stopc = tty->termios.c_cc[VSTOP];
dgap_carrier(ch);
dgap_param(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
}
static void dgap_tty_throttle(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DPR_IOCTL(("dgap_tty_throttle start\n"));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
ch->ch_flags |= (CH_RXBLOCK);
#if 1
dgap_cmdw(ch, RPAUSE, 0, 0);
#endif
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_throttle finish\n"));
}
static void dgap_tty_unthrottle(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DPR_IOCTL(("dgap_tty_unthrottle start\n"));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
ch->ch_flags &= ~(CH_RXBLOCK);
#if 1
dgap_cmdw(ch, RRESUME, 0, 0);
#endif
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_unthrottle finish\n"));
}
static void dgap_tty_start(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DPR_IOCTL(("dgap_tty_start start\n"));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
dgap_cmdw(ch, RESUMETX, 0, 0);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_start finish\n"));
}
static void dgap_tty_stop(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DPR_IOCTL(("dgap_tty_stop start\n"));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
dgap_cmdw(ch, PAUSETX, 0, 0);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_stop finish\n"));
}
static void dgap_tty_flush_chars(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DPR_IOCTL(("dgap_tty_flush_chars start\n"));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_flush_chars finish\n"));
}
static void dgap_tty_flush_buffer(struct tty_struct *tty)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
ulong lock_flags;
ulong lock_flags2;
u16 head = 0;
if (!tty || tty->magic != TTY_MAGIC)
return;
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return;
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return;
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return;
DPR_IOCTL(("dgap_tty_flush_buffer on port: %d start\n", ch->ch_portnum));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
ch->ch_flags &= ~CH_STOP;
head = readw(&(ch->ch_bs->tx_head));
dgap_cmdw(ch, FLUSHTX, (u16) head, 0);
dgap_cmdw(ch, RESUMETX, 0, 0);
if (ch->ch_tun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_tun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
if (ch->ch_pun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_pun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
if (waitqueue_active(&tty->write_wait))
wake_up_interruptible(&tty->write_wait);
tty_wakeup(tty);
DPR_IOCTL(("dgap_tty_flush_buffer finish\n"));
}
static int dgap_tty_ioctl(struct tty_struct *tty, unsigned int cmd,
unsigned long arg)
{
struct board_t *bd;
struct channel_t *ch;
struct un_t *un;
int rc;
u16 head = 0;
ulong lock_flags = 0;
ulong lock_flags2 = 0;
void __user *uarg = (void __user *) arg;
if (!tty || tty->magic != TTY_MAGIC)
return (-ENODEV);
un = tty->driver_data;
if (!un || un->magic != DGAP_UNIT_MAGIC)
return (-ENODEV);
ch = un->un_ch;
if (!ch || ch->magic != DGAP_CHANNEL_MAGIC)
return (-ENODEV);
bd = ch->ch_bd;
if (!bd || bd->magic != DGAP_BOARD_MAGIC)
return (-ENODEV);
DPR_IOCTL(("dgap_tty_ioctl start on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgap_ioctl_name(cmd), cmd, arg));
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
if (un->un_open_count <= 0) {
DPR_BASIC(("dgap_tty_ioctl - unit not open.\n"));
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(-EIO);
}
switch (cmd) {
case TCSBRK:
rc = tty_check_change(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
if (rc) {
return(rc);
}
rc = dgap_wait_for_drain(tty);
if (rc) {
DPR_IOCTL(("dgap_tty_ioctl - bad return: %d ", rc));
return(-EINTR);
}
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
if(((cmd == TCSBRK) && (!arg)) || (cmd == TCSBRKP)) {
dgap_cmdw(ch, SBREAK, (u16) SBREAK_TIME, 0);
}
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_ioctl finish on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgap_ioctl_name(cmd), cmd, arg));
return(0);
case TCSBRKP:
rc = tty_check_change(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
if (rc) {
return(rc);
}
rc = dgap_wait_for_drain(tty);
if (rc) {
DPR_IOCTL(("dgap_tty_ioctl - bad return: %d ", rc));
return(-EINTR);
}
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
dgap_cmdw(ch, SBREAK, (u16) SBREAK_TIME, 0);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_ioctl finish on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgap_ioctl_name(cmd), cmd, arg));
return(0);
case TIOCSBRK:
rc = tty_check_change(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
if (rc) {
return(rc);
}
rc = dgap_wait_for_drain(tty);
if (rc) {
DPR_IOCTL(("dgap_tty_ioctl - bad return: %d ", rc));
return(-EINTR);
}
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
dgap_cmdw(ch, SBREAK, (u16) SBREAK_TIME, 0);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_ioctl finish on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgap_ioctl_name(cmd), cmd, arg));
return 0;
case TIOCCBRK:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return 0;
case TIOCGSOFTCAR:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
rc = put_user(C_CLOCAL(tty) ? 1 : 0, (unsigned long __user *) arg);
return(rc);
case TIOCSSOFTCAR:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
rc = get_user(arg, (unsigned long __user *) arg);
if (rc)
return(rc);
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
tty->termios.c_cflag = ((tty->termios.c_cflag & ~CLOCAL) | (arg ? CLOCAL : 0));
dgap_param(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(0);
case TIOCMGET:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(dgap_get_modem_info(ch, uarg));
case TIOCMBIS:
case TIOCMBIC:
case TIOCMSET:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(dgap_set_modem_info(tty, cmd, uarg));
case TCFLSH:
rc = tty_check_change(tty);
if (rc) {
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(rc);
}
if ((arg == TCIFLUSH) || (arg == TCIOFLUSH)) {
if (!(un->un_type == DGAP_PRINT)) {
head = readw(&(ch->ch_bs->rx_head));
writew(head, &(ch->ch_bs->rx_tail));
writeb(0, &(ch->ch_bs->orun));
}
}
if ((arg == TCOFLUSH) || (arg == TCIOFLUSH)) {
ch->ch_flags &= ~CH_STOP;
head = readw(&(ch->ch_bs->tx_head));
dgap_cmdw(ch, FLUSHTX, (u16) head, 0 );
dgap_cmdw(ch, RESUMETX, 0, 0);
if (ch->ch_tun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_tun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_tun.un_flags_wait);
}
if (ch->ch_pun.un_flags & (UN_LOW|UN_EMPTY)) {
ch->ch_pun.un_flags &= ~(UN_LOW|UN_EMPTY);
wake_up_interruptible(&ch->ch_pun.un_flags_wait);
}
if (waitqueue_active(&tty->write_wait))
wake_up_interruptible(&tty->write_wait);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
tty_wakeup(tty);
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
}
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_ioctl (LINE:%d) finish on port %d - cmd %s (%x), arg %lx\n",
__LINE__, ch->ch_portnum, dgap_ioctl_name(cmd), cmd, arg));
return(-ENOIOCTLCMD);
case TCSETSF:
case TCSETSW:
if (cmd == TCSETSF) {
ch->ch_flags &= ~CH_STOP;
head = readw(&(ch->ch_bs->rx_head));
writew(head, &(ch->ch_bs->rx_tail));
}
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
rc = dgap_wait_for_drain(tty);
if (rc) {
DPR_IOCTL(("dgap_tty_ioctl - bad return: %d ", rc));
return(-EINTR);
}
DPR_IOCTL(("dgap_tty_ioctl finish on port %d - cmd %s (%x), arg %lx\n",
ch->ch_portnum, dgap_ioctl_name(cmd), cmd, arg));
return(-ENOIOCTLCMD);
case TCSETAW:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
rc = dgap_wait_for_drain(tty);
if (rc) {
DPR_IOCTL(("dgap_tty_ioctl - bad return: %d ", rc));
return(-EINTR);
}
return(-ENOIOCTLCMD);
case TCXONC:
rc = tty_check_change(tty);
if (rc) {
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(rc);
}
DPR_IOCTL(("dgap_ioctl - in TCXONC - %d\n", cmd));
switch (arg) {
case TCOON:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
dgap_tty_start(tty);
return(0);
case TCOOFF:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
dgap_tty_stop(tty);
return(0);
case TCION:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(-ENOIOCTLCMD);
case TCIOFF:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(-ENOIOCTLCMD);
default:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(-EINVAL);
}
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(-ENOIOCTLCMD);
case DIGI_GETA:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(dgap_tty_digigeta(tty, uarg));
case DIGI_SETAW:
case DIGI_SETAF:
if (cmd == (DIGI_SETAW)) {
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
rc = dgap_wait_for_drain(tty);
if (rc) {
DPR_IOCTL(("dgap_tty_ioctl - bad return: %d ", rc));
return(-EINTR);
}
DGAP_LOCK(bd->bd_lock, lock_flags);
DGAP_LOCK(ch->ch_lock, lock_flags2);
}
else {
tty_ldisc_flush(tty);
}
case DIGI_SETA:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(dgap_tty_digiseta(tty, uarg));
case DIGI_GEDELAY:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(dgap_tty_digigetedelay(tty, uarg));
case DIGI_SEDELAY:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(dgap_tty_digisetedelay(tty, uarg));
case DIGI_GETCUSTOMBAUD:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(dgap_tty_digigetcustombaud(tty, uarg));
case DIGI_SETCUSTOMBAUD:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return(dgap_tty_digisetcustombaud(tty, uarg));
case DIGI_RESET_PORT:
dgap_firmware_reset_port(ch);
dgap_param(tty);
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
return 0;
default:
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_ioctl - in default\n"));
DPR_IOCTL(("dgap_tty_ioctl end - cmd %s (%x), arg %lx\n",
dgap_ioctl_name(cmd), cmd, arg));
return(-ENOIOCTLCMD);
}
DGAP_UNLOCK(ch->ch_lock, lock_flags2);
DGAP_UNLOCK(bd->bd_lock, lock_flags);
DPR_IOCTL(("dgap_tty_ioctl end - cmd %s (%x), arg %lx\n",
dgap_ioctl_name(cmd), cmd, arg));
return(0);
}
