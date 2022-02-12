static void stli_cleanup_ports(struct stlibrd *brdp)
{
struct stliport *portp;
unsigned int j;
struct tty_struct *tty;
for (j = 0; j < STL_MAXPORTS; j++) {
portp = brdp->ports[j];
if (portp != NULL) {
tty = tty_port_tty_get(&portp->port);
if (tty != NULL) {
tty_hangup(tty);
tty_kref_put(tty);
}
kfree(portp);
}
}
}
static int stli_parsebrd(struct stlconf *confp, char **argp)
{
unsigned int i;
char *sp;
if (argp[0] == NULL || *argp[0] == 0)
return 0;
for (sp = argp[0], i = 0; ((*sp != 0) && (i < 25)); sp++, i++)
*sp = tolower(*sp);
for (i = 0; i < ARRAY_SIZE(stli_brdstr); i++) {
if (strcmp(stli_brdstr[i].name, argp[0]) == 0)
break;
}
if (i == ARRAY_SIZE(stli_brdstr)) {
printk(KERN_WARNING "istallion: unknown board name, %s?\n", argp[0]);
return 0;
}
confp->brdtype = stli_brdstr[i].type;
if (argp[1] != NULL && *argp[1] != 0)
confp->ioaddr1 = simple_strtoul(argp[1], NULL, 0);
if (argp[2] != NULL && *argp[2] != 0)
confp->memaddr = simple_strtoul(argp[2], NULL, 0);
return(1);
}
static int stli_activate(struct tty_port *port, struct tty_struct *tty)
{
struct stliport *portp = container_of(port, struct stliport, port);
struct stlibrd *brdp = stli_brds[portp->brdnr];
int rc;
if ((rc = stli_initopen(tty, brdp, portp)) >= 0)
clear_bit(TTY_IO_ERROR, &tty->flags);
wake_up_interruptible(&portp->raw_wait);
return rc;
}
static int stli_open(struct tty_struct *tty, struct file *filp)
{
struct stlibrd *brdp;
struct stliport *portp;
unsigned int minordev, brdnr, portnr;
minordev = tty->index;
brdnr = MINOR2BRD(minordev);
if (brdnr >= stli_nrbrds)
return -ENODEV;
brdp = stli_brds[brdnr];
if (brdp == NULL)
return -ENODEV;
if (!test_bit(BST_STARTED, &brdp->state))
return -ENODEV;
portnr = MINOR2PORT(minordev);
if (portnr > brdp->nrports)
return -ENODEV;
portp = brdp->ports[portnr];
if (portp == NULL)
return -ENODEV;
if (portp->devnr < 1)
return -ENODEV;
tty->driver_data = portp;
return tty_port_open(&portp->port, tty, filp);
}
static void stli_shutdown(struct tty_port *port)
{
struct stlibrd *brdp;
unsigned long ftype;
unsigned long flags;
struct stliport *portp = container_of(port, struct stliport, port);
if (portp->brdnr >= stli_nrbrds)
return;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return;
if (!test_bit(ST_CLOSING, &portp->state))
stli_rawclose(brdp, portp, 0, 0);
spin_lock_irqsave(&stli_lock, flags);
clear_bit(ST_TXBUSY, &portp->state);
clear_bit(ST_RXSTOP, &portp->state);
spin_unlock_irqrestore(&stli_lock, flags);
ftype = FLUSHTX | FLUSHRX;
stli_cmdwait(brdp, portp, A_FLUSH, &ftype, sizeof(u32), 0);
}
static void stli_close(struct tty_struct *tty, struct file *filp)
{
struct stliport *portp = tty->driver_data;
unsigned long flags;
if (portp == NULL)
return;
spin_lock_irqsave(&stli_lock, flags);
if (tty == stli_txcooktty)
stli_flushchars(tty);
spin_unlock_irqrestore(&stli_lock, flags);
tty_port_close(&portp->port, tty, filp);
}
static int stli_initopen(struct tty_struct *tty,
struct stlibrd *brdp, struct stliport *portp)
{
asynotify_t nt;
asyport_t aport;
int rc;
if ((rc = stli_rawopen(brdp, portp, 0, 1)) < 0)
return rc;
memset(&nt, 0, sizeof(asynotify_t));
nt.data = (DT_TXLOW | DT_TXEMPTY | DT_RXBUSY | DT_RXBREAK);
nt.signal = SG_DCD;
if ((rc = stli_cmdwait(brdp, portp, A_SETNOTIFY, &nt,
sizeof(asynotify_t), 0)) < 0)
return rc;
stli_mkasyport(tty, portp, &aport, tty->termios);
if ((rc = stli_cmdwait(brdp, portp, A_SETPORT, &aport,
sizeof(asyport_t), 0)) < 0)
return rc;
set_bit(ST_GETSIGS, &portp->state);
if ((rc = stli_cmdwait(brdp, portp, A_GETSIGNALS, &portp->asig,
sizeof(asysigs_t), 1)) < 0)
return rc;
if (test_and_clear_bit(ST_GETSIGS, &portp->state))
portp->sigs = stli_mktiocm(portp->asig.sigvalue);
stli_mkasysigs(&portp->asig, 1, 1);
if ((rc = stli_cmdwait(brdp, portp, A_SETSIGNALS, &portp->asig,
sizeof(asysigs_t), 0)) < 0)
return rc;
return 0;
}
static int stli_rawopen(struct stlibrd *brdp, struct stliport *portp, unsigned long arg, int wait)
{
cdkhdr_t __iomem *hdrp;
cdkctrl_t __iomem *cp;
unsigned char __iomem *bits;
unsigned long flags;
int rc;
wait_event_interruptible_tty(portp->raw_wait,
!test_bit(ST_CLOSING, &portp->state));
if (signal_pending(current)) {
return -ERESTARTSYS;
}
spin_lock_irqsave(&brd_lock, flags);
EBRDENABLE(brdp);
cp = &((cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr))->ctrl;
writel(arg, &cp->openarg);
writeb(1, &cp->open);
hdrp = (cdkhdr_t __iomem *) EBRDGETMEMPTR(brdp, CDK_CDKADDR);
bits = ((unsigned char __iomem *) hdrp) + brdp->slaveoffset +
portp->portidx;
writeb(readb(bits) | portp->portbit, bits);
EBRDDISABLE(brdp);
if (wait == 0) {
spin_unlock_irqrestore(&brd_lock, flags);
return 0;
}
rc = 0;
set_bit(ST_OPENING, &portp->state);
spin_unlock_irqrestore(&brd_lock, flags);
wait_event_interruptible_tty(portp->raw_wait,
!test_bit(ST_OPENING, &portp->state));
if (signal_pending(current))
rc = -ERESTARTSYS;
if ((rc == 0) && (portp->rc != 0))
rc = -EIO;
return rc;
}
static int stli_rawclose(struct stlibrd *brdp, struct stliport *portp, unsigned long arg, int wait)
{
cdkhdr_t __iomem *hdrp;
cdkctrl_t __iomem *cp;
unsigned char __iomem *bits;
unsigned long flags;
int rc;
if (wait) {
wait_event_interruptible_tty(portp->raw_wait,
!test_bit(ST_CLOSING, &portp->state));
if (signal_pending(current)) {
return -ERESTARTSYS;
}
}
spin_lock_irqsave(&brd_lock, flags);
EBRDENABLE(brdp);
cp = &((cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr))->ctrl;
writel(arg, &cp->closearg);
writeb(1, &cp->close);
hdrp = (cdkhdr_t __iomem *) EBRDGETMEMPTR(brdp, CDK_CDKADDR);
bits = ((unsigned char __iomem *) hdrp) + brdp->slaveoffset +
portp->portidx;
writeb(readb(bits) |portp->portbit, bits);
EBRDDISABLE(brdp);
set_bit(ST_CLOSING, &portp->state);
spin_unlock_irqrestore(&brd_lock, flags);
if (wait == 0)
return 0;
rc = 0;
wait_event_interruptible_tty(portp->raw_wait,
!test_bit(ST_CLOSING, &portp->state));
if (signal_pending(current))
rc = -ERESTARTSYS;
if ((rc == 0) && (portp->rc != 0))
rc = -EIO;
return rc;
}
static int stli_cmdwait(struct stlibrd *brdp, struct stliport *portp, unsigned long cmd, void *arg, int size, int copyback)
{
wait_event_interruptible(portp->raw_wait,
!test_bit(ST_CMDING, &portp->state));
if (signal_pending(current))
return -ERESTARTSYS;
stli_sendcmd(brdp, portp, cmd, arg, size, copyback);
wait_event_interruptible(portp->raw_wait,
!test_bit(ST_CMDING, &portp->state));
if (signal_pending(current))
return -ERESTARTSYS;
if (portp->rc != 0)
return -EIO;
return 0;
}
static int stli_setport(struct tty_struct *tty)
{
struct stliport *portp = tty->driver_data;
struct stlibrd *brdp;
asyport_t aport;
if (portp == NULL)
return -ENODEV;
if (portp->brdnr >= stli_nrbrds)
return -ENODEV;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return -ENODEV;
stli_mkasyport(tty, portp, &aport, tty->termios);
return(stli_cmdwait(brdp, portp, A_SETPORT, &aport, sizeof(asyport_t), 0));
}
static int stli_carrier_raised(struct tty_port *port)
{
struct stliport *portp = container_of(port, struct stliport, port);
return (portp->sigs & TIOCM_CD) ? 1 : 0;
}
static void stli_dtr_rts(struct tty_port *port, int on)
{
struct stliport *portp = container_of(port, struct stliport, port);
struct stlibrd *brdp = stli_brds[portp->brdnr];
stli_mkasysigs(&portp->asig, on, on);
if (stli_cmdwait(brdp, portp, A_SETSIGNALS, &portp->asig,
sizeof(asysigs_t), 0) < 0)
printk(KERN_WARNING "istallion: dtr set failed.\n");
}
static int stli_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
cdkasy_t __iomem *ap;
cdkhdr_t __iomem *hdrp;
unsigned char __iomem *bits;
unsigned char __iomem *shbuf;
unsigned char *chbuf;
struct stliport *portp;
struct stlibrd *brdp;
unsigned int len, stlen, head, tail, size;
unsigned long flags;
if (tty == stli_txcooktty)
stli_flushchars(tty);
portp = tty->driver_data;
if (portp == NULL)
return 0;
if (portp->brdnr >= stli_nrbrds)
return 0;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return 0;
chbuf = (unsigned char *) buf;
spin_lock_irqsave(&brd_lock, flags);
EBRDENABLE(brdp);
ap = (cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr);
head = (unsigned int) readw(&ap->txq.head);
tail = (unsigned int) readw(&ap->txq.tail);
if (tail != ((unsigned int) readw(&ap->txq.tail)))
tail = (unsigned int) readw(&ap->txq.tail);
size = portp->txsize;
if (head >= tail) {
len = size - (head - tail) - 1;
stlen = size - head;
} else {
len = tail - head - 1;
stlen = len;
}
len = min(len, (unsigned int)count);
count = 0;
shbuf = (char __iomem *) EBRDGETMEMPTR(brdp, portp->txoffset);
while (len > 0) {
stlen = min(len, stlen);
memcpy_toio(shbuf + head, chbuf, stlen);
chbuf += stlen;
len -= stlen;
count += stlen;
head += stlen;
if (head >= size) {
head = 0;
stlen = tail;
}
}
ap = (cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr);
writew(head, &ap->txq.head);
if (test_bit(ST_TXBUSY, &portp->state)) {
if (readl(&ap->changed.data) & DT_TXEMPTY)
writel(readl(&ap->changed.data) & ~DT_TXEMPTY, &ap->changed.data);
}
hdrp = (cdkhdr_t __iomem *) EBRDGETMEMPTR(brdp, CDK_CDKADDR);
bits = ((unsigned char __iomem *) hdrp) + brdp->slaveoffset +
portp->portidx;
writeb(readb(bits) | portp->portbit, bits);
set_bit(ST_TXBUSY, &portp->state);
EBRDDISABLE(brdp);
spin_unlock_irqrestore(&brd_lock, flags);
return(count);
}
static int stli_putchar(struct tty_struct *tty, unsigned char ch)
{
if (tty != stli_txcooktty) {
if (stli_txcooktty != NULL)
stli_flushchars(stli_txcooktty);
stli_txcooktty = tty;
}
stli_txcookbuf[stli_txcooksize++] = ch;
return 0;
}
static void stli_flushchars(struct tty_struct *tty)
{
cdkhdr_t __iomem *hdrp;
unsigned char __iomem *bits;
cdkasy_t __iomem *ap;
struct tty_struct *cooktty;
struct stliport *portp;
struct stlibrd *brdp;
unsigned int len, stlen, head, tail, size, count, cooksize;
unsigned char *buf;
unsigned char __iomem *shbuf;
unsigned long flags;
cooksize = stli_txcooksize;
cooktty = stli_txcooktty;
stli_txcooksize = 0;
stli_txcookrealsize = 0;
stli_txcooktty = NULL;
if (cooktty == NULL)
return;
if (tty != cooktty)
tty = cooktty;
if (cooksize == 0)
return;
portp = tty->driver_data;
if (portp == NULL)
return;
if (portp->brdnr >= stli_nrbrds)
return;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return;
spin_lock_irqsave(&brd_lock, flags);
EBRDENABLE(brdp);
ap = (cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr);
head = (unsigned int) readw(&ap->txq.head);
tail = (unsigned int) readw(&ap->txq.tail);
if (tail != ((unsigned int) readw(&ap->txq.tail)))
tail = (unsigned int) readw(&ap->txq.tail);
size = portp->txsize;
if (head >= tail) {
len = size - (head - tail) - 1;
stlen = size - head;
} else {
len = tail - head - 1;
stlen = len;
}
len = min(len, cooksize);
count = 0;
shbuf = EBRDGETMEMPTR(brdp, portp->txoffset);
buf = stli_txcookbuf;
while (len > 0) {
stlen = min(len, stlen);
memcpy_toio(shbuf + head, buf, stlen);
buf += stlen;
len -= stlen;
count += stlen;
head += stlen;
if (head >= size) {
head = 0;
stlen = tail;
}
}
ap = (cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr);
writew(head, &ap->txq.head);
if (test_bit(ST_TXBUSY, &portp->state)) {
if (readl(&ap->changed.data) & DT_TXEMPTY)
writel(readl(&ap->changed.data) & ~DT_TXEMPTY, &ap->changed.data);
}
hdrp = (cdkhdr_t __iomem *) EBRDGETMEMPTR(brdp, CDK_CDKADDR);
bits = ((unsigned char __iomem *) hdrp) + brdp->slaveoffset +
portp->portidx;
writeb(readb(bits) | portp->portbit, bits);
set_bit(ST_TXBUSY, &portp->state);
EBRDDISABLE(brdp);
spin_unlock_irqrestore(&brd_lock, flags);
}
static int stli_writeroom(struct tty_struct *tty)
{
cdkasyrq_t __iomem *rp;
struct stliport *portp;
struct stlibrd *brdp;
unsigned int head, tail, len;
unsigned long flags;
if (tty == stli_txcooktty) {
if (stli_txcookrealsize != 0) {
len = stli_txcookrealsize - stli_txcooksize;
return len;
}
}
portp = tty->driver_data;
if (portp == NULL)
return 0;
if (portp->brdnr >= stli_nrbrds)
return 0;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return 0;
spin_lock_irqsave(&brd_lock, flags);
EBRDENABLE(brdp);
rp = &((cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr))->txq;
head = (unsigned int) readw(&rp->head);
tail = (unsigned int) readw(&rp->tail);
if (tail != ((unsigned int) readw(&rp->tail)))
tail = (unsigned int) readw(&rp->tail);
len = (head >= tail) ? (portp->txsize - (head - tail)) : (tail - head);
len--;
EBRDDISABLE(brdp);
spin_unlock_irqrestore(&brd_lock, flags);
if (tty == stli_txcooktty) {
stli_txcookrealsize = len;
len -= stli_txcooksize;
}
return len;
}
static int stli_charsinbuffer(struct tty_struct *tty)
{
cdkasyrq_t __iomem *rp;
struct stliport *portp;
struct stlibrd *brdp;
unsigned int head, tail, len;
unsigned long flags;
if (tty == stli_txcooktty)
stli_flushchars(tty);
portp = tty->driver_data;
if (portp == NULL)
return 0;
if (portp->brdnr >= stli_nrbrds)
return 0;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return 0;
spin_lock_irqsave(&brd_lock, flags);
EBRDENABLE(brdp);
rp = &((cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr))->txq;
head = (unsigned int) readw(&rp->head);
tail = (unsigned int) readw(&rp->tail);
if (tail != ((unsigned int) readw(&rp->tail)))
tail = (unsigned int) readw(&rp->tail);
len = (head >= tail) ? (head - tail) : (portp->txsize - (tail - head));
if ((len == 0) && test_bit(ST_TXBUSY, &portp->state))
len = 1;
EBRDDISABLE(brdp);
spin_unlock_irqrestore(&brd_lock, flags);
return len;
}
static int stli_getserial(struct stliport *portp, struct serial_struct __user *sp)
{
struct serial_struct sio;
struct stlibrd *brdp;
memset(&sio, 0, sizeof(struct serial_struct));
sio.type = PORT_UNKNOWN;
sio.line = portp->portnr;
sio.irq = 0;
sio.flags = portp->port.flags;
sio.baud_base = portp->baud_base;
sio.close_delay = portp->port.close_delay;
sio.closing_wait = portp->closing_wait;
sio.custom_divisor = portp->custom_divisor;
sio.xmit_fifo_size = 0;
sio.hub6 = 0;
brdp = stli_brds[portp->brdnr];
if (brdp != NULL)
sio.port = brdp->iobase;
return copy_to_user(sp, &sio, sizeof(struct serial_struct)) ?
-EFAULT : 0;
}
static int stli_setserial(struct tty_struct *tty, struct serial_struct __user *sp)
{
struct serial_struct sio;
int rc;
struct stliport *portp = tty->driver_data;
if (copy_from_user(&sio, sp, sizeof(struct serial_struct)))
return -EFAULT;
if (!capable(CAP_SYS_ADMIN)) {
if ((sio.baud_base != portp->baud_base) ||
(sio.close_delay != portp->port.close_delay) ||
((sio.flags & ~ASYNC_USR_MASK) !=
(portp->port.flags & ~ASYNC_USR_MASK)))
return -EPERM;
}
portp->port.flags = (portp->port.flags & ~ASYNC_USR_MASK) |
(sio.flags & ASYNC_USR_MASK);
portp->baud_base = sio.baud_base;
portp->port.close_delay = sio.close_delay;
portp->closing_wait = sio.closing_wait;
portp->custom_divisor = sio.custom_divisor;
if ((rc = stli_setport(tty)) < 0)
return rc;
return 0;
}
static int stli_tiocmget(struct tty_struct *tty)
{
struct stliport *portp = tty->driver_data;
struct stlibrd *brdp;
int rc;
if (portp == NULL)
return -ENODEV;
if (portp->brdnr >= stli_nrbrds)
return 0;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return 0;
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
if ((rc = stli_cmdwait(brdp, portp, A_GETSIGNALS,
&portp->asig, sizeof(asysigs_t), 1)) < 0)
return rc;
return stli_mktiocm(portp->asig.sigvalue);
}
static int stli_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct stliport *portp = tty->driver_data;
struct stlibrd *brdp;
int rts = -1, dtr = -1;
if (portp == NULL)
return -ENODEV;
if (portp->brdnr >= stli_nrbrds)
return 0;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return 0;
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
if (set & TIOCM_RTS)
rts = 1;
if (set & TIOCM_DTR)
dtr = 1;
if (clear & TIOCM_RTS)
rts = 0;
if (clear & TIOCM_DTR)
dtr = 0;
stli_mkasysigs(&portp->asig, dtr, rts);
return stli_cmdwait(brdp, portp, A_SETSIGNALS, &portp->asig,
sizeof(asysigs_t), 0);
}
static int stli_ioctl(struct tty_struct *tty, unsigned int cmd, unsigned long arg)
{
struct stliport *portp;
struct stlibrd *brdp;
int rc;
void __user *argp = (void __user *)arg;
portp = tty->driver_data;
if (portp == NULL)
return -ENODEV;
if (portp->brdnr >= stli_nrbrds)
return 0;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return 0;
if ((cmd != TIOCGSERIAL) && (cmd != TIOCSSERIAL) &&
(cmd != COM_GETPORTSTATS) && (cmd != COM_CLRPORTSTATS)) {
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
}
rc = 0;
switch (cmd) {
case TIOCGSERIAL:
rc = stli_getserial(portp, argp);
break;
case TIOCSSERIAL:
rc = stli_setserial(tty, argp);
break;
case STL_GETPFLAG:
rc = put_user(portp->pflag, (unsigned __user *)argp);
break;
case STL_SETPFLAG:
if ((rc = get_user(portp->pflag, (unsigned __user *)argp)) == 0)
stli_setport(tty);
break;
case COM_GETPORTSTATS:
rc = stli_getportstats(tty, portp, argp);
break;
case COM_CLRPORTSTATS:
rc = stli_clrportstats(portp, argp);
break;
case TIOCSERCONFIG:
case TIOCSERGWILD:
case TIOCSERSWILD:
case TIOCSERGETLSR:
case TIOCSERGSTRUCT:
case TIOCSERGETMULTI:
case TIOCSERSETMULTI:
default:
rc = -ENOIOCTLCMD;
break;
}
return rc;
}
static void stli_settermios(struct tty_struct *tty, struct ktermios *old)
{
struct stliport *portp;
struct stlibrd *brdp;
struct ktermios *tiosp;
asyport_t aport;
portp = tty->driver_data;
if (portp == NULL)
return;
if (portp->brdnr >= stli_nrbrds)
return;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return;
tiosp = tty->termios;
stli_mkasyport(tty, portp, &aport, tiosp);
stli_cmdwait(brdp, portp, A_SETPORT, &aport, sizeof(asyport_t), 0);
stli_mkasysigs(&portp->asig, ((tiosp->c_cflag & CBAUD) ? 1 : 0), -1);
stli_cmdwait(brdp, portp, A_SETSIGNALS, &portp->asig,
sizeof(asysigs_t), 0);
if ((old->c_cflag & CRTSCTS) && ((tiosp->c_cflag & CRTSCTS) == 0))
tty->hw_stopped = 0;
if (((old->c_cflag & CLOCAL) == 0) && (tiosp->c_cflag & CLOCAL))
wake_up_interruptible(&portp->port.open_wait);
}
static void stli_throttle(struct tty_struct *tty)
{
struct stliport *portp = tty->driver_data;
if (portp == NULL)
return;
set_bit(ST_RXSTOP, &portp->state);
}
static void stli_unthrottle(struct tty_struct *tty)
{
struct stliport *portp = tty->driver_data;
if (portp == NULL)
return;
clear_bit(ST_RXSTOP, &portp->state);
}
static void stli_stop(struct tty_struct *tty)
{
}
static void stli_start(struct tty_struct *tty)
{
}
static void stli_hangup(struct tty_struct *tty)
{
struct stliport *portp = tty->driver_data;
tty_port_hangup(&portp->port);
}
static void stli_flushbuffer(struct tty_struct *tty)
{
struct stliport *portp;
struct stlibrd *brdp;
unsigned long ftype, flags;
portp = tty->driver_data;
if (portp == NULL)
return;
if (portp->brdnr >= stli_nrbrds)
return;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return;
spin_lock_irqsave(&brd_lock, flags);
if (tty == stli_txcooktty) {
stli_txcooktty = NULL;
stli_txcooksize = 0;
stli_txcookrealsize = 0;
}
if (test_bit(ST_CMDING, &portp->state)) {
set_bit(ST_DOFLUSHTX, &portp->state);
} else {
ftype = FLUSHTX;
if (test_bit(ST_DOFLUSHRX, &portp->state)) {
ftype |= FLUSHRX;
clear_bit(ST_DOFLUSHRX, &portp->state);
}
__stli_sendcmd(brdp, portp, A_FLUSH, &ftype, sizeof(u32), 0);
}
spin_unlock_irqrestore(&brd_lock, flags);
tty_wakeup(tty);
}
static int stli_breakctl(struct tty_struct *tty, int state)
{
struct stlibrd *brdp;
struct stliport *portp;
long arg;
portp = tty->driver_data;
if (portp == NULL)
return -EINVAL;
if (portp->brdnr >= stli_nrbrds)
return -EINVAL;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return -EINVAL;
arg = (state == -1) ? BREAKON : BREAKOFF;
stli_cmdwait(brdp, portp, A_BREAK, &arg, sizeof(long), 0);
return 0;
}
static void stli_waituntilsent(struct tty_struct *tty, int timeout)
{
struct stliport *portp;
unsigned long tend;
portp = tty->driver_data;
if (portp == NULL)
return;
if (timeout == 0)
timeout = HZ;
tend = jiffies + timeout;
while (test_bit(ST_TXBUSY, &portp->state)) {
if (signal_pending(current))
break;
msleep_interruptible(20);
if (time_after_eq(jiffies, tend))
break;
}
}
static void stli_sendxchar(struct tty_struct *tty, char ch)
{
struct stlibrd *brdp;
struct stliport *portp;
asyctrl_t actrl;
portp = tty->driver_data;
if (portp == NULL)
return;
if (portp->brdnr >= stli_nrbrds)
return;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return;
memset(&actrl, 0, sizeof(asyctrl_t));
if (ch == STOP_CHAR(tty)) {
actrl.rxctrl = CT_STOPFLOW;
} else if (ch == START_CHAR(tty)) {
actrl.rxctrl = CT_STARTFLOW;
} else {
actrl.txctrl = CT_SENDCHR;
actrl.tximdch = ch;
}
stli_cmdwait(brdp, portp, A_PORTCTRL, &actrl, sizeof(asyctrl_t), 0);
}
static void stli_portinfo(struct seq_file *m, struct stlibrd *brdp, struct stliport *portp, int portnr)
{
char *uart;
int rc;
rc = stli_portcmdstats(NULL, portp);
uart = "UNKNOWN";
if (test_bit(BST_STARTED, &brdp->state)) {
switch (stli_comstats.hwid) {
case 0: uart = "2681"; break;
case 1: uart = "SC26198"; break;
default:uart = "CD1400"; break;
}
}
seq_printf(m, "%d: uart:%s ", portnr, uart);
if (test_bit(BST_STARTED, &brdp->state) && rc >= 0) {
char sep;
seq_printf(m, "tx:%d rx:%d", (int) stli_comstats.txtotal,
(int) stli_comstats.rxtotal);
if (stli_comstats.rxframing)
seq_printf(m, " fe:%d",
(int) stli_comstats.rxframing);
if (stli_comstats.rxparity)
seq_printf(m, " pe:%d",
(int) stli_comstats.rxparity);
if (stli_comstats.rxbreaks)
seq_printf(m, " brk:%d",
(int) stli_comstats.rxbreaks);
if (stli_comstats.rxoverrun)
seq_printf(m, " oe:%d",
(int) stli_comstats.rxoverrun);
sep = ' ';
if (stli_comstats.signals & TIOCM_RTS) {
seq_printf(m, "%c%s", sep, "RTS");
sep = '|';
}
if (stli_comstats.signals & TIOCM_CTS) {
seq_printf(m, "%c%s", sep, "CTS");
sep = '|';
}
if (stli_comstats.signals & TIOCM_DTR) {
seq_printf(m, "%c%s", sep, "DTR");
sep = '|';
}
if (stli_comstats.signals & TIOCM_CD) {
seq_printf(m, "%c%s", sep, "DCD");
sep = '|';
}
if (stli_comstats.signals & TIOCM_DSR) {
seq_printf(m, "%c%s", sep, "DSR");
sep = '|';
}
}
seq_putc(m, '\n');
}
static int stli_proc_show(struct seq_file *m, void *v)
{
struct stlibrd *brdp;
struct stliport *portp;
unsigned int brdnr, portnr, totalport;
totalport = 0;
seq_printf(m, "%s: version %s\n", stli_drvtitle, stli_drvversion);
for (brdnr = 0; (brdnr < stli_nrbrds); brdnr++) {
brdp = stli_brds[brdnr];
if (brdp == NULL)
continue;
if (brdp->state == 0)
continue;
totalport = brdnr * STL_MAXPORTS;
for (portnr = 0; (portnr < brdp->nrports); portnr++,
totalport++) {
portp = brdp->ports[portnr];
if (portp == NULL)
continue;
stli_portinfo(m, brdp, portp, totalport);
}
}
return 0;
}
static int stli_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, stli_proc_show, NULL);
}
static void __stli_sendcmd(struct stlibrd *brdp, struct stliport *portp, unsigned long cmd, void *arg, int size, int copyback)
{
cdkhdr_t __iomem *hdrp;
cdkctrl_t __iomem *cp;
unsigned char __iomem *bits;
if (test_bit(ST_CMDING, &portp->state)) {
printk(KERN_ERR "istallion: command already busy, cmd=%x!\n",
(int) cmd);
return;
}
EBRDENABLE(brdp);
cp = &((cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr))->ctrl;
if (size > 0) {
memcpy_toio((void __iomem *) &(cp->args[0]), arg, size);
if (copyback) {
portp->argp = arg;
portp->argsize = size;
}
}
writel(0, &cp->status);
writel(cmd, &cp->cmd);
hdrp = (cdkhdr_t __iomem *) EBRDGETMEMPTR(brdp, CDK_CDKADDR);
bits = ((unsigned char __iomem *) hdrp) + brdp->slaveoffset +
portp->portidx;
writeb(readb(bits) | portp->portbit, bits);
set_bit(ST_CMDING, &portp->state);
EBRDDISABLE(brdp);
}
static void stli_sendcmd(struct stlibrd *brdp, struct stliport *portp, unsigned long cmd, void *arg, int size, int copyback)
{
unsigned long flags;
spin_lock_irqsave(&brd_lock, flags);
__stli_sendcmd(brdp, portp, cmd, arg, size, copyback);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stli_read(struct stlibrd *brdp, struct stliport *portp)
{
cdkasyrq_t __iomem *rp;
char __iomem *shbuf;
struct tty_struct *tty;
unsigned int head, tail, size;
unsigned int len, stlen;
if (test_bit(ST_RXSTOP, &portp->state))
return;
tty = tty_port_tty_get(&portp->port);
if (tty == NULL)
return;
rp = &((cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr))->rxq;
head = (unsigned int) readw(&rp->head);
if (head != ((unsigned int) readw(&rp->head)))
head = (unsigned int) readw(&rp->head);
tail = (unsigned int) readw(&rp->tail);
size = portp->rxsize;
if (head >= tail) {
len = head - tail;
stlen = len;
} else {
len = size - (tail - head);
stlen = size - tail;
}
len = tty_buffer_request_room(tty, len);
shbuf = (char __iomem *) EBRDGETMEMPTR(brdp, portp->rxoffset);
while (len > 0) {
unsigned char *cptr;
stlen = min(len, stlen);
tty_prepare_flip_string(tty, &cptr, stlen);
memcpy_fromio(cptr, shbuf + tail, stlen);
len -= stlen;
tail += stlen;
if (tail >= size) {
tail = 0;
stlen = head;
}
}
rp = &((cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr))->rxq;
writew(tail, &rp->tail);
if (head != tail)
set_bit(ST_RXING, &portp->state);
tty_schedule_flip(tty);
tty_kref_put(tty);
}
static void stli_dodelaycmd(struct stliport *portp, cdkctrl_t __iomem *cp)
{
int cmd;
if (test_bit(ST_DOSIGS, &portp->state)) {
if (test_bit(ST_DOFLUSHTX, &portp->state) &&
test_bit(ST_DOFLUSHRX, &portp->state))
cmd = A_SETSIGNALSF;
else if (test_bit(ST_DOFLUSHTX, &portp->state))
cmd = A_SETSIGNALSFTX;
else if (test_bit(ST_DOFLUSHRX, &portp->state))
cmd = A_SETSIGNALSFRX;
else
cmd = A_SETSIGNALS;
clear_bit(ST_DOFLUSHTX, &portp->state);
clear_bit(ST_DOFLUSHRX, &portp->state);
clear_bit(ST_DOSIGS, &portp->state);
memcpy_toio((void __iomem *) &(cp->args[0]), (void *) &portp->asig,
sizeof(asysigs_t));
writel(0, &cp->status);
writel(cmd, &cp->cmd);
set_bit(ST_CMDING, &portp->state);
} else if (test_bit(ST_DOFLUSHTX, &portp->state) ||
test_bit(ST_DOFLUSHRX, &portp->state)) {
cmd = ((test_bit(ST_DOFLUSHTX, &portp->state)) ? FLUSHTX : 0);
cmd |= ((test_bit(ST_DOFLUSHRX, &portp->state)) ? FLUSHRX : 0);
clear_bit(ST_DOFLUSHTX, &portp->state);
clear_bit(ST_DOFLUSHRX, &portp->state);
memcpy_toio((void __iomem *) &(cp->args[0]), (void *) &cmd, sizeof(int));
writel(0, &cp->status);
writel(A_FLUSH, &cp->cmd);
set_bit(ST_CMDING, &portp->state);
}
}
static int stli_hostcmd(struct stlibrd *brdp, struct stliport *portp)
{
cdkasy_t __iomem *ap;
cdkctrl_t __iomem *cp;
struct tty_struct *tty;
asynotify_t nt;
unsigned long oldsigs;
int rc, donerx;
ap = (cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr);
cp = &ap->ctrl;
if (test_bit(ST_OPENING, &portp->state)) {
rc = readl(&cp->openarg);
if (readb(&cp->open) == 0 && rc != 0) {
if (rc > 0)
rc--;
writel(0, &cp->openarg);
portp->rc = rc;
clear_bit(ST_OPENING, &portp->state);
wake_up_interruptible(&portp->raw_wait);
}
}
if (test_bit(ST_CLOSING, &portp->state)) {
rc = (int) readl(&cp->closearg);
if (readb(&cp->close) == 0 && rc != 0) {
if (rc > 0)
rc--;
writel(0, &cp->closearg);
portp->rc = rc;
clear_bit(ST_CLOSING, &portp->state);
wake_up_interruptible(&portp->raw_wait);
}
}
if (test_bit(ST_CMDING, &portp->state)) {
rc = readl(&cp->status);
if (readl(&cp->cmd) == 0 && rc != 0) {
if (rc > 0)
rc--;
if (portp->argp != NULL) {
memcpy_fromio(portp->argp, (void __iomem *) &(cp->args[0]),
portp->argsize);
portp->argp = NULL;
}
writel(0, &cp->status);
portp->rc = rc;
clear_bit(ST_CMDING, &portp->state);
stli_dodelaycmd(portp, cp);
wake_up_interruptible(&portp->raw_wait);
}
}
donerx = 0;
if (ap->notify) {
nt = ap->changed;
ap->notify = 0;
tty = tty_port_tty_get(&portp->port);
if (nt.signal & SG_DCD) {
oldsigs = portp->sigs;
portp->sigs = stli_mktiocm(nt.sigvalue);
clear_bit(ST_GETSIGS, &portp->state);
if ((portp->sigs & TIOCM_CD) &&
((oldsigs & TIOCM_CD) == 0))
wake_up_interruptible(&portp->port.open_wait);
if ((oldsigs & TIOCM_CD) &&
((portp->sigs & TIOCM_CD) == 0)) {
if (portp->port.flags & ASYNC_CHECK_CD) {
if (tty)
tty_hangup(tty);
}
}
}
if (nt.data & DT_TXEMPTY)
clear_bit(ST_TXBUSY, &portp->state);
if (nt.data & (DT_TXEMPTY | DT_TXLOW)) {
if (tty != NULL) {
tty_wakeup(tty);
EBRDENABLE(brdp);
}
}
if ((nt.data & DT_RXBREAK) && (portp->rxmarkmsk & BRKINT)) {
if (tty != NULL) {
tty_insert_flip_char(tty, 0, TTY_BREAK);
if (portp->port.flags & ASYNC_SAK) {
do_SAK(tty);
EBRDENABLE(brdp);
}
tty_schedule_flip(tty);
}
}
tty_kref_put(tty);
if (nt.data & DT_RXBUSY) {
donerx++;
stli_read(brdp, portp);
}
}
if ((!donerx) && test_bit(ST_RXING, &portp->state)) {
clear_bit(ST_RXING, &portp->state);
stli_read(brdp, portp);
}
return((test_bit(ST_OPENING, &portp->state) ||
test_bit(ST_CLOSING, &portp->state) ||
test_bit(ST_CMDING, &portp->state) ||
test_bit(ST_TXBUSY, &portp->state) ||
test_bit(ST_RXING, &portp->state)) ? 0 : 1);
}
static void stli_brdpoll(struct stlibrd *brdp, cdkhdr_t __iomem *hdrp)
{
struct stliport *portp;
unsigned char hostbits[(STL_MAXCHANS / 8) + 1];
unsigned char slavebits[(STL_MAXCHANS / 8) + 1];
unsigned char __iomem *slavep;
int bitpos, bitat, bitsize;
int channr, nrdevs, slavebitchange;
bitsize = brdp->bitsize;
nrdevs = brdp->nrdevs;
memcpy_fromio(&hostbits[0], (((unsigned char __iomem *) hdrp) + brdp->hostoffset),
bitsize);
memset(&slavebits[0], 0, bitsize);
slavebitchange = 0;
for (bitpos = 0; (bitpos < bitsize); bitpos++) {
if (hostbits[bitpos] == 0)
continue;
channr = bitpos * 8;
for (bitat = 0x1; (channr < nrdevs); channr++, bitat <<= 1) {
if (hostbits[bitpos] & bitat) {
portp = brdp->ports[(channr - 1)];
if (stli_hostcmd(brdp, portp)) {
slavebitchange++;
slavebits[bitpos] |= bitat;
}
}
}
}
if (slavebitchange) {
hdrp = (cdkhdr_t __iomem *) EBRDGETMEMPTR(brdp, CDK_CDKADDR);
slavep = ((unsigned char __iomem *) hdrp) + brdp->slaveoffset;
for (bitpos = 0; (bitpos < bitsize); bitpos++) {
if (readb(slavebits + bitpos))
writeb(readb(slavep + bitpos) & ~slavebits[bitpos], slavebits + bitpos);
}
}
}
static void stli_poll(unsigned long arg)
{
cdkhdr_t __iomem *hdrp;
struct stlibrd *brdp;
unsigned int brdnr;
mod_timer(&stli_timerlist, STLI_TIMEOUT);
for (brdnr = 0; (brdnr < stli_nrbrds); brdnr++) {
brdp = stli_brds[brdnr];
if (brdp == NULL)
continue;
if (!test_bit(BST_STARTED, &brdp->state))
continue;
spin_lock(&brd_lock);
EBRDENABLE(brdp);
hdrp = (cdkhdr_t __iomem *) EBRDGETMEMPTR(brdp, CDK_CDKADDR);
if (readb(&hdrp->hostreq))
stli_brdpoll(brdp, hdrp);
EBRDDISABLE(brdp);
spin_unlock(&brd_lock);
}
}
static void stli_mkasyport(struct tty_struct *tty, struct stliport *portp,
asyport_t *pp, struct ktermios *tiosp)
{
memset(pp, 0, sizeof(asyport_t));
pp->baudout = tty_get_baud_rate(tty);
if ((tiosp->c_cflag & CBAUD) == B38400) {
if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
pp->baudout = 57600;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
pp->baudout = 115200;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
pp->baudout = 230400;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
pp->baudout = 460800;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_CUST)
pp->baudout = (portp->baud_base / portp->custom_divisor);
}
if (pp->baudout > STL_MAXBAUD)
pp->baudout = STL_MAXBAUD;
pp->baudin = pp->baudout;
switch (tiosp->c_cflag & CSIZE) {
case CS5:
pp->csize = 5;
break;
case CS6:
pp->csize = 6;
break;
case CS7:
pp->csize = 7;
break;
default:
pp->csize = 8;
break;
}
if (tiosp->c_cflag & CSTOPB)
pp->stopbs = PT_STOP2;
else
pp->stopbs = PT_STOP1;
if (tiosp->c_cflag & PARENB) {
if (tiosp->c_cflag & PARODD)
pp->parity = PT_ODDPARITY;
else
pp->parity = PT_EVENPARITY;
} else {
pp->parity = PT_NOPARITY;
}
if (tiosp->c_iflag & IXON) {
pp->flow |= F_IXON;
if (tiosp->c_iflag & IXANY)
pp->flow |= F_IXANY;
}
if (tiosp->c_cflag & CRTSCTS)
pp->flow |= (F_RTSFLOW | F_CTSFLOW);
pp->startin = tiosp->c_cc[VSTART];
pp->stopin = tiosp->c_cc[VSTOP];
pp->startout = tiosp->c_cc[VSTART];
pp->stopout = tiosp->c_cc[VSTOP];
if (tiosp->c_iflag & IGNPAR)
pp->iflag |= FI_IGNRXERRS;
if (tiosp->c_iflag & IGNBRK)
pp->iflag |= FI_IGNBREAK;
portp->rxmarkmsk = 0;
if (tiosp->c_iflag & (INPCK | PARMRK))
pp->iflag |= FI_1MARKRXERRS;
if (tiosp->c_iflag & BRKINT)
portp->rxmarkmsk |= BRKINT;
if (tiosp->c_cflag & CLOCAL)
portp->port.flags &= ~ASYNC_CHECK_CD;
else
portp->port.flags |= ASYNC_CHECK_CD;
pp->pflag = (portp->pflag & 0xffff);
pp->vmin = (portp->pflag & P_RXIMIN) ? 1 : 0;
pp->vtime = (portp->pflag & P_RXITIME) ? 1 : 0;
pp->cc[1] = (portp->pflag & P_RXTHOLD) ? 1 : 0;
}
static void stli_mkasysigs(asysigs_t *sp, int dtr, int rts)
{
memset(sp, 0, sizeof(asysigs_t));
if (dtr >= 0) {
sp->signal |= SG_DTR;
sp->sigvalue |= ((dtr > 0) ? SG_DTR : 0);
}
if (rts >= 0) {
sp->signal |= SG_RTS;
sp->sigvalue |= ((rts > 0) ? SG_RTS : 0);
}
}
static long stli_mktiocm(unsigned long sigvalue)
{
long tiocm = 0;
tiocm |= ((sigvalue & SG_DCD) ? TIOCM_CD : 0);
tiocm |= ((sigvalue & SG_CTS) ? TIOCM_CTS : 0);
tiocm |= ((sigvalue & SG_RI) ? TIOCM_RI : 0);
tiocm |= ((sigvalue & SG_DSR) ? TIOCM_DSR : 0);
tiocm |= ((sigvalue & SG_DTR) ? TIOCM_DTR : 0);
tiocm |= ((sigvalue & SG_RTS) ? TIOCM_RTS : 0);
return(tiocm);
}
static int stli_initports(struct stlibrd *brdp)
{
struct stliport *portp;
unsigned int i, panelnr, panelport;
for (i = 0, panelnr = 0, panelport = 0; (i < brdp->nrports); i++) {
portp = kzalloc(sizeof(struct stliport), GFP_KERNEL);
if (!portp) {
printk(KERN_WARNING "istallion: failed to allocate port structure\n");
continue;
}
tty_port_init(&portp->port);
portp->port.ops = &stli_port_ops;
portp->magic = STLI_PORTMAGIC;
portp->portnr = i;
portp->brdnr = brdp->brdnr;
portp->panelnr = panelnr;
portp->baud_base = STL_BAUDBASE;
portp->port.close_delay = STL_CLOSEDELAY;
portp->closing_wait = 30 * HZ;
init_waitqueue_head(&portp->port.open_wait);
init_waitqueue_head(&portp->port.close_wait);
init_waitqueue_head(&portp->raw_wait);
panelport++;
if (panelport >= brdp->panels[panelnr]) {
panelport = 0;
panelnr++;
}
brdp->ports[i] = portp;
}
return 0;
}
static void stli_ecpinit(struct stlibrd *brdp)
{
unsigned long memconf;
outb(ECP_ATSTOP, (brdp->iobase + ECP_ATCONFR));
udelay(10);
outb(ECP_ATDISABLE, (brdp->iobase + ECP_ATCONFR));
udelay(100);
memconf = (brdp->memaddr & ECP_ATADDRMASK) >> ECP_ATADDRSHFT;
outb(memconf, (brdp->iobase + ECP_ATMEMAR));
}
static void stli_ecpenable(struct stlibrd *brdp)
{
outb(ECP_ATENABLE, (brdp->iobase + ECP_ATCONFR));
}
static void stli_ecpdisable(struct stlibrd *brdp)
{
outb(ECP_ATDISABLE, (brdp->iobase + ECP_ATCONFR));
}
static void __iomem *stli_ecpgetmemptr(struct stlibrd *brdp, unsigned long offset, int line)
{
void __iomem *ptr;
unsigned char val;
if (offset > brdp->memsize) {
printk(KERN_ERR "istallion: shared memory pointer=%x out of "
"range at line=%d(%d), brd=%d\n",
(int) offset, line, __LINE__, brdp->brdnr);
ptr = NULL;
val = 0;
} else {
ptr = brdp->membase + (offset % ECP_ATPAGESIZE);
val = (unsigned char) (offset / ECP_ATPAGESIZE);
}
outb(val, (brdp->iobase + ECP_ATMEMPR));
return(ptr);
}
static void stli_ecpreset(struct stlibrd *brdp)
{
outb(ECP_ATSTOP, (brdp->iobase + ECP_ATCONFR));
udelay(10);
outb(ECP_ATDISABLE, (brdp->iobase + ECP_ATCONFR));
udelay(500);
}
static void stli_ecpintr(struct stlibrd *brdp)
{
outb(0x1, brdp->iobase);
}
static void stli_ecpeiinit(struct stlibrd *brdp)
{
unsigned long memconf;
outb(0x1, (brdp->iobase + ECP_EIBRDENAB));
outb(ECP_EISTOP, (brdp->iobase + ECP_EICONFR));
udelay(10);
outb(ECP_EIDISABLE, (brdp->iobase + ECP_EICONFR));
udelay(500);
memconf = (brdp->memaddr & ECP_EIADDRMASKL) >> ECP_EIADDRSHFTL;
outb(memconf, (brdp->iobase + ECP_EIMEMARL));
memconf = (brdp->memaddr & ECP_EIADDRMASKH) >> ECP_EIADDRSHFTH;
outb(memconf, (brdp->iobase + ECP_EIMEMARH));
}
static void stli_ecpeienable(struct stlibrd *brdp)
{
outb(ECP_EIENABLE, (brdp->iobase + ECP_EICONFR));
}
static void stli_ecpeidisable(struct stlibrd *brdp)
{
outb(ECP_EIDISABLE, (brdp->iobase + ECP_EICONFR));
}
static void __iomem *stli_ecpeigetmemptr(struct stlibrd *brdp, unsigned long offset, int line)
{
void __iomem *ptr;
unsigned char val;
if (offset > brdp->memsize) {
printk(KERN_ERR "istallion: shared memory pointer=%x out of "
"range at line=%d(%d), brd=%d\n",
(int) offset, line, __LINE__, brdp->brdnr);
ptr = NULL;
val = 0;
} else {
ptr = brdp->membase + (offset % ECP_EIPAGESIZE);
if (offset < ECP_EIPAGESIZE)
val = ECP_EIENABLE;
else
val = ECP_EIENABLE | 0x40;
}
outb(val, (brdp->iobase + ECP_EICONFR));
return(ptr);
}
static void stli_ecpeireset(struct stlibrd *brdp)
{
outb(ECP_EISTOP, (brdp->iobase + ECP_EICONFR));
udelay(10);
outb(ECP_EIDISABLE, (brdp->iobase + ECP_EICONFR));
udelay(500);
}
static void stli_ecpmcenable(struct stlibrd *brdp)
{
outb(ECP_MCENABLE, (brdp->iobase + ECP_MCCONFR));
}
static void stli_ecpmcdisable(struct stlibrd *brdp)
{
outb(ECP_MCDISABLE, (brdp->iobase + ECP_MCCONFR));
}
static void __iomem *stli_ecpmcgetmemptr(struct stlibrd *brdp, unsigned long offset, int line)
{
void __iomem *ptr;
unsigned char val;
if (offset > brdp->memsize) {
printk(KERN_ERR "istallion: shared memory pointer=%x out of "
"range at line=%d(%d), brd=%d\n",
(int) offset, line, __LINE__, brdp->brdnr);
ptr = NULL;
val = 0;
} else {
ptr = brdp->membase + (offset % ECP_MCPAGESIZE);
val = ((unsigned char) (offset / ECP_MCPAGESIZE)) | ECP_MCENABLE;
}
outb(val, (brdp->iobase + ECP_MCCONFR));
return(ptr);
}
static void stli_ecpmcreset(struct stlibrd *brdp)
{
outb(ECP_MCSTOP, (brdp->iobase + ECP_MCCONFR));
udelay(10);
outb(ECP_MCDISABLE, (brdp->iobase + ECP_MCCONFR));
udelay(500);
}
static void stli_ecppciinit(struct stlibrd *brdp)
{
outb(ECP_PCISTOP, (brdp->iobase + ECP_PCICONFR));
udelay(10);
outb(0, (brdp->iobase + ECP_PCICONFR));
udelay(500);
}
static void __iomem *stli_ecppcigetmemptr(struct stlibrd *brdp, unsigned long offset, int line)
{
void __iomem *ptr;
unsigned char val;
if (offset > brdp->memsize) {
printk(KERN_ERR "istallion: shared memory pointer=%x out of "
"range at line=%d(%d), board=%d\n",
(int) offset, line, __LINE__, brdp->brdnr);
ptr = NULL;
val = 0;
} else {
ptr = brdp->membase + (offset % ECP_PCIPAGESIZE);
val = (offset / ECP_PCIPAGESIZE) << 1;
}
outb(val, (brdp->iobase + ECP_PCICONFR));
return(ptr);
}
static void stli_ecppcireset(struct stlibrd *brdp)
{
outb(ECP_PCISTOP, (brdp->iobase + ECP_PCICONFR));
udelay(10);
outb(0, (brdp->iobase + ECP_PCICONFR));
udelay(500);
}
static void stli_onbinit(struct stlibrd *brdp)
{
unsigned long memconf;
outb(ONB_ATSTOP, (brdp->iobase + ONB_ATCONFR));
udelay(10);
outb(ONB_ATDISABLE, (brdp->iobase + ONB_ATCONFR));
mdelay(1000);
memconf = (brdp->memaddr & ONB_ATADDRMASK) >> ONB_ATADDRSHFT;
outb(memconf, (brdp->iobase + ONB_ATMEMAR));
outb(0x1, brdp->iobase);
mdelay(1);
}
static void stli_onbenable(struct stlibrd *brdp)
{
outb((brdp->enabval | ONB_ATENABLE), (brdp->iobase + ONB_ATCONFR));
}
static void stli_onbdisable(struct stlibrd *brdp)
{
outb((brdp->enabval | ONB_ATDISABLE), (brdp->iobase + ONB_ATCONFR));
}
static void __iomem *stli_onbgetmemptr(struct stlibrd *brdp, unsigned long offset, int line)
{
void __iomem *ptr;
if (offset > brdp->memsize) {
printk(KERN_ERR "istallion: shared memory pointer=%x out of "
"range at line=%d(%d), brd=%d\n",
(int) offset, line, __LINE__, brdp->brdnr);
ptr = NULL;
} else {
ptr = brdp->membase + (offset % ONB_ATPAGESIZE);
}
return(ptr);
}
static void stli_onbreset(struct stlibrd *brdp)
{
outb(ONB_ATSTOP, (brdp->iobase + ONB_ATCONFR));
udelay(10);
outb(ONB_ATDISABLE, (brdp->iobase + ONB_ATCONFR));
mdelay(1000);
}
static void stli_onbeinit(struct stlibrd *brdp)
{
unsigned long memconf;
outb(0x1, (brdp->iobase + ONB_EIBRDENAB));
outb(ONB_EISTOP, (brdp->iobase + ONB_EICONFR));
udelay(10);
outb(ONB_EIDISABLE, (brdp->iobase + ONB_EICONFR));
mdelay(1000);
memconf = (brdp->memaddr & ONB_EIADDRMASKL) >> ONB_EIADDRSHFTL;
outb(memconf, (brdp->iobase + ONB_EIMEMARL));
memconf = (brdp->memaddr & ONB_EIADDRMASKH) >> ONB_EIADDRSHFTH;
outb(memconf, (brdp->iobase + ONB_EIMEMARH));
outb(0x1, brdp->iobase);
mdelay(1);
}
static void stli_onbeenable(struct stlibrd *brdp)
{
outb(ONB_EIENABLE, (brdp->iobase + ONB_EICONFR));
}
static void stli_onbedisable(struct stlibrd *brdp)
{
outb(ONB_EIDISABLE, (brdp->iobase + ONB_EICONFR));
}
static void __iomem *stli_onbegetmemptr(struct stlibrd *brdp, unsigned long offset, int line)
{
void __iomem *ptr;
unsigned char val;
if (offset > brdp->memsize) {
printk(KERN_ERR "istallion: shared memory pointer=%x out of "
"range at line=%d(%d), brd=%d\n",
(int) offset, line, __LINE__, brdp->brdnr);
ptr = NULL;
val = 0;
} else {
ptr = brdp->membase + (offset % ONB_EIPAGESIZE);
if (offset < ONB_EIPAGESIZE)
val = ONB_EIENABLE;
else
val = ONB_EIENABLE | 0x40;
}
outb(val, (brdp->iobase + ONB_EICONFR));
return(ptr);
}
static void stli_onbereset(struct stlibrd *brdp)
{
outb(ONB_EISTOP, (brdp->iobase + ONB_EICONFR));
udelay(10);
outb(ONB_EIDISABLE, (brdp->iobase + ONB_EICONFR));
mdelay(1000);
}
static void stli_bbyinit(struct stlibrd *brdp)
{
outb(BBY_ATSTOP, (brdp->iobase + BBY_ATCONFR));
udelay(10);
outb(0, (brdp->iobase + BBY_ATCONFR));
mdelay(1000);
outb(0x1, brdp->iobase);
mdelay(1);
}
static void __iomem *stli_bbygetmemptr(struct stlibrd *brdp, unsigned long offset, int line)
{
void __iomem *ptr;
unsigned char val;
BUG_ON(offset > brdp->memsize);
ptr = brdp->membase + (offset % BBY_PAGESIZE);
val = (unsigned char) (offset / BBY_PAGESIZE);
outb(val, (brdp->iobase + BBY_ATCONFR));
return(ptr);
}
static void stli_bbyreset(struct stlibrd *brdp)
{
outb(BBY_ATSTOP, (brdp->iobase + BBY_ATCONFR));
udelay(10);
outb(0, (brdp->iobase + BBY_ATCONFR));
mdelay(1000);
}
static void stli_stalinit(struct stlibrd *brdp)
{
outb(0x1, brdp->iobase);
mdelay(1000);
}
static void __iomem *stli_stalgetmemptr(struct stlibrd *brdp, unsigned long offset, int line)
{
BUG_ON(offset > brdp->memsize);
return brdp->membase + (offset % STAL_PAGESIZE);
}
static void stli_stalreset(struct stlibrd *brdp)
{
u32 __iomem *vecp;
vecp = (u32 __iomem *) (brdp->membase + 0x30);
writel(0xffff0000, vecp);
outb(0, brdp->iobase);
mdelay(1000);
}
static int stli_initecp(struct stlibrd *brdp)
{
cdkecpsig_t sig;
cdkecpsig_t __iomem *sigsp;
unsigned int status, nxtid;
char *name;
int retval, panelnr, nrports;
if ((brdp->iobase == 0) || (brdp->memaddr == 0)) {
retval = -ENODEV;
goto err;
}
brdp->iosize = ECP_IOSIZE;
if (!request_region(brdp->iobase, brdp->iosize, "istallion")) {
retval = -EIO;
goto err;
}
switch (brdp->brdtype) {
case BRD_ECP:
brdp->memsize = ECP_MEMSIZE;
brdp->pagesize = ECP_ATPAGESIZE;
brdp->init = stli_ecpinit;
brdp->enable = stli_ecpenable;
brdp->reenable = stli_ecpenable;
brdp->disable = stli_ecpdisable;
brdp->getmemptr = stli_ecpgetmemptr;
brdp->intr = stli_ecpintr;
brdp->reset = stli_ecpreset;
name = "serial(EC8/64)";
break;
case BRD_ECPE:
brdp->memsize = ECP_MEMSIZE;
brdp->pagesize = ECP_EIPAGESIZE;
brdp->init = stli_ecpeiinit;
brdp->enable = stli_ecpeienable;
brdp->reenable = stli_ecpeienable;
brdp->disable = stli_ecpeidisable;
brdp->getmemptr = stli_ecpeigetmemptr;
brdp->intr = stli_ecpintr;
brdp->reset = stli_ecpeireset;
name = "serial(EC8/64-EI)";
break;
case BRD_ECPMC:
brdp->memsize = ECP_MEMSIZE;
brdp->pagesize = ECP_MCPAGESIZE;
brdp->init = NULL;
brdp->enable = stli_ecpmcenable;
brdp->reenable = stli_ecpmcenable;
brdp->disable = stli_ecpmcdisable;
brdp->getmemptr = stli_ecpmcgetmemptr;
brdp->intr = stli_ecpintr;
brdp->reset = stli_ecpmcreset;
name = "serial(EC8/64-MCA)";
break;
case BRD_ECPPCI:
brdp->memsize = ECP_PCIMEMSIZE;
brdp->pagesize = ECP_PCIPAGESIZE;
brdp->init = stli_ecppciinit;
brdp->enable = NULL;
brdp->reenable = NULL;
brdp->disable = NULL;
brdp->getmemptr = stli_ecppcigetmemptr;
brdp->intr = stli_ecpintr;
brdp->reset = stli_ecppcireset;
name = "serial(EC/RA-PCI)";
break;
default:
retval = -EINVAL;
goto err_reg;
}
EBRDINIT(brdp);
brdp->membase = ioremap_nocache(brdp->memaddr, brdp->memsize);
if (brdp->membase == NULL) {
retval = -ENOMEM;
goto err_reg;
}
EBRDENABLE(brdp);
sigsp = (cdkecpsig_t __iomem *) EBRDGETMEMPTR(brdp, CDK_SIGADDR);
memcpy_fromio(&sig, sigsp, sizeof(cdkecpsig_t));
EBRDDISABLE(brdp);
if (sig.magic != cpu_to_le32(ECP_MAGIC)) {
retval = -ENODEV;
goto err_unmap;
}
for (panelnr = 0, nxtid = 0; (panelnr < STL_MAXPANELS); panelnr++) {
status = sig.panelid[nxtid];
if ((status & ECH_PNLIDMASK) != nxtid)
break;
brdp->panelids[panelnr] = status;
nrports = (status & ECH_PNL16PORT) ? 16 : 8;
if ((nrports == 16) && ((status & ECH_PNLXPID) == 0))
nxtid++;
brdp->panels[panelnr] = nrports;
brdp->nrports += nrports;
nxtid++;
brdp->nrpanels++;
}
set_bit(BST_FOUND, &brdp->state);
return 0;
err_unmap:
iounmap(brdp->membase);
brdp->membase = NULL;
err_reg:
release_region(brdp->iobase, brdp->iosize);
err:
return retval;
}
static int stli_initonb(struct stlibrd *brdp)
{
cdkonbsig_t sig;
cdkonbsig_t __iomem *sigsp;
char *name;
int i, retval;
if (brdp->iobase == 0 || brdp->memaddr == 0) {
retval = -ENODEV;
goto err;
}
brdp->iosize = ONB_IOSIZE;
if (!request_region(brdp->iobase, brdp->iosize, "istallion")) {
retval = -EIO;
goto err;
}
switch (brdp->brdtype) {
case BRD_ONBOARD:
case BRD_ONBOARD2:
brdp->memsize = ONB_MEMSIZE;
brdp->pagesize = ONB_ATPAGESIZE;
brdp->init = stli_onbinit;
brdp->enable = stli_onbenable;
brdp->reenable = stli_onbenable;
brdp->disable = stli_onbdisable;
brdp->getmemptr = stli_onbgetmemptr;
brdp->intr = stli_ecpintr;
brdp->reset = stli_onbreset;
if (brdp->memaddr > 0x100000)
brdp->enabval = ONB_MEMENABHI;
else
brdp->enabval = ONB_MEMENABLO;
name = "serial(ONBoard)";
break;
case BRD_ONBOARDE:
brdp->memsize = ONB_EIMEMSIZE;
brdp->pagesize = ONB_EIPAGESIZE;
brdp->init = stli_onbeinit;
brdp->enable = stli_onbeenable;
brdp->reenable = stli_onbeenable;
brdp->disable = stli_onbedisable;
brdp->getmemptr = stli_onbegetmemptr;
brdp->intr = stli_ecpintr;
brdp->reset = stli_onbereset;
name = "serial(ONBoard/E)";
break;
case BRD_BRUMBY4:
brdp->memsize = BBY_MEMSIZE;
brdp->pagesize = BBY_PAGESIZE;
brdp->init = stli_bbyinit;
brdp->enable = NULL;
brdp->reenable = NULL;
brdp->disable = NULL;
brdp->getmemptr = stli_bbygetmemptr;
brdp->intr = stli_ecpintr;
brdp->reset = stli_bbyreset;
name = "serial(Brumby)";
break;
case BRD_STALLION:
brdp->memsize = STAL_MEMSIZE;
brdp->pagesize = STAL_PAGESIZE;
brdp->init = stli_stalinit;
brdp->enable = NULL;
brdp->reenable = NULL;
brdp->disable = NULL;
brdp->getmemptr = stli_stalgetmemptr;
brdp->intr = stli_ecpintr;
brdp->reset = stli_stalreset;
name = "serial(Stallion)";
break;
default:
retval = -EINVAL;
goto err_reg;
}
EBRDINIT(brdp);
brdp->membase = ioremap_nocache(brdp->memaddr, brdp->memsize);
if (brdp->membase == NULL) {
retval = -ENOMEM;
goto err_reg;
}
EBRDENABLE(brdp);
sigsp = (cdkonbsig_t __iomem *) EBRDGETMEMPTR(brdp, CDK_SIGADDR);
memcpy_fromio(&sig, sigsp, sizeof(cdkonbsig_t));
EBRDDISABLE(brdp);
if (sig.magic0 != cpu_to_le16(ONB_MAGIC0) ||
sig.magic1 != cpu_to_le16(ONB_MAGIC1) ||
sig.magic2 != cpu_to_le16(ONB_MAGIC2) ||
sig.magic3 != cpu_to_le16(ONB_MAGIC3)) {
retval = -ENODEV;
goto err_unmap;
}
brdp->nrpanels = 1;
if (sig.amask1) {
brdp->nrports = 32;
} else {
for (i = 0; (i < 16); i++) {
if (((sig.amask0 << i) & 0x8000) == 0)
break;
}
brdp->nrports = i;
}
brdp->panels[0] = brdp->nrports;
set_bit(BST_FOUND, &brdp->state);
return 0;
err_unmap:
iounmap(brdp->membase);
brdp->membase = NULL;
err_reg:
release_region(brdp->iobase, brdp->iosize);
err:
return retval;
}
static int stli_startbrd(struct stlibrd *brdp)
{
cdkhdr_t __iomem *hdrp;
cdkmem_t __iomem *memp;
cdkasy_t __iomem *ap;
unsigned long flags;
unsigned int portnr, nrdevs, i;
struct stliport *portp;
int rc = 0;
u32 memoff;
spin_lock_irqsave(&brd_lock, flags);
EBRDENABLE(brdp);
hdrp = (cdkhdr_t __iomem *) EBRDGETMEMPTR(brdp, CDK_CDKADDR);
nrdevs = hdrp->nrdevs;
#if 0
printk("%s(%d): CDK version %d.%d.%d --> "
"nrdevs=%d memp=%x hostp=%x slavep=%x\n",
__FILE__, __LINE__, readb(&hdrp->ver_release), readb(&hdrp->ver_modification),
readb(&hdrp->ver_fix), nrdevs, (int) readl(&hdrp->memp), readl(&hdrp->hostp),
readl(&hdrp->slavep));
#endif
if (nrdevs < (brdp->nrports + 1)) {
printk(KERN_ERR "istallion: slave failed to allocate memory for "
"all devices, devices=%d\n", nrdevs);
brdp->nrports = nrdevs - 1;
}
brdp->nrdevs = nrdevs;
brdp->hostoffset = hdrp->hostp - CDK_CDKADDR;
brdp->slaveoffset = hdrp->slavep - CDK_CDKADDR;
brdp->bitsize = (nrdevs + 7) / 8;
memoff = readl(&hdrp->memp);
if (memoff > brdp->memsize) {
printk(KERN_ERR "istallion: corrupted shared memory region?\n");
rc = -EIO;
goto stli_donestartup;
}
memp = (cdkmem_t __iomem *) EBRDGETMEMPTR(brdp, memoff);
if (readw(&memp->dtype) != TYP_ASYNCTRL) {
printk(KERN_ERR "istallion: no slave control device found\n");
goto stli_donestartup;
}
memp++;
for (i = 1, portnr = 0; (i < nrdevs); i++, portnr++, memp++) {
if (readw(&memp->dtype) != TYP_ASYNC)
break;
portp = brdp->ports[portnr];
if (portp == NULL)
break;
portp->devnr = i;
portp->addr = readl(&memp->offset);
portp->reqbit = (unsigned char) (0x1 << (i * 8 / nrdevs));
portp->portidx = (unsigned char) (i / 8);
portp->portbit = (unsigned char) (0x1 << (i % 8));
}
writeb(0xff, &hdrp->slavereq);
for (i = 1, portnr = 0; (i < nrdevs); i++, portnr++) {
portp = brdp->ports[portnr];
if (portp == NULL)
break;
if (portp->addr == 0)
break;
ap = (cdkasy_t __iomem *) EBRDGETMEMPTR(brdp, portp->addr);
if (ap != NULL) {
portp->rxsize = readw(&ap->rxq.size);
portp->txsize = readw(&ap->txq.size);
portp->rxoffset = readl(&ap->rxq.offset);
portp->txoffset = readl(&ap->txq.offset);
}
}
stli_donestartup:
EBRDDISABLE(brdp);
spin_unlock_irqrestore(&brd_lock, flags);
if (rc == 0)
set_bit(BST_STARTED, &brdp->state);
if (! stli_timeron) {
stli_timeron++;
mod_timer(&stli_timerlist, STLI_TIMEOUT);
}
return rc;
}
static int __devinit stli_brdinit(struct stlibrd *brdp)
{
int retval;
switch (brdp->brdtype) {
case BRD_ECP:
case BRD_ECPE:
case BRD_ECPMC:
case BRD_ECPPCI:
retval = stli_initecp(brdp);
break;
case BRD_ONBOARD:
case BRD_ONBOARDE:
case BRD_ONBOARD2:
case BRD_BRUMBY4:
case BRD_STALLION:
retval = stli_initonb(brdp);
break;
default:
printk(KERN_ERR "istallion: board=%d is unknown board "
"type=%d\n", brdp->brdnr, brdp->brdtype);
retval = -ENODEV;
}
if (retval)
return retval;
stli_initports(brdp);
printk(KERN_INFO "istallion: %s found, board=%d io=%x mem=%x "
"nrpanels=%d nrports=%d\n", stli_brdnames[brdp->brdtype],
brdp->brdnr, brdp->iobase, (int) brdp->memaddr,
brdp->nrpanels, brdp->nrports);
return 0;
}
static int stli_eisamemprobe(struct stlibrd *brdp)
{
cdkecpsig_t ecpsig, __iomem *ecpsigp;
cdkonbsig_t onbsig, __iomem *onbsigp;
int i, foundit;
if (brdp->brdtype == BRD_ECPE) {
outb(0x1, (brdp->iobase + ECP_EIBRDENAB));
outb(ECP_EISTOP, (brdp->iobase + ECP_EICONFR));
udelay(10);
outb(ECP_EIDISABLE, (brdp->iobase + ECP_EICONFR));
udelay(500);
stli_ecpeienable(brdp);
} else if (brdp->brdtype == BRD_ONBOARDE) {
outb(0x1, (brdp->iobase + ONB_EIBRDENAB));
outb(ONB_EISTOP, (brdp->iobase + ONB_EICONFR));
udelay(10);
outb(ONB_EIDISABLE, (brdp->iobase + ONB_EICONFR));
mdelay(100);
outb(0x1, brdp->iobase);
mdelay(1);
stli_onbeenable(brdp);
} else {
return -ENODEV;
}
foundit = 0;
brdp->memsize = ECP_MEMSIZE;
for (i = 0; (i < stli_eisamempsize); i++) {
brdp->memaddr = stli_eisamemprobeaddrs[i];
brdp->membase = ioremap_nocache(brdp->memaddr, brdp->memsize);
if (brdp->membase == NULL)
continue;
if (brdp->brdtype == BRD_ECPE) {
ecpsigp = stli_ecpeigetmemptr(brdp,
CDK_SIGADDR, __LINE__);
memcpy_fromio(&ecpsig, ecpsigp, sizeof(cdkecpsig_t));
if (ecpsig.magic == cpu_to_le32(ECP_MAGIC))
foundit = 1;
} else {
onbsigp = (cdkonbsig_t __iomem *) stli_onbegetmemptr(brdp,
CDK_SIGADDR, __LINE__);
memcpy_fromio(&onbsig, onbsigp, sizeof(cdkonbsig_t));
if ((onbsig.magic0 == cpu_to_le16(ONB_MAGIC0)) &&
(onbsig.magic1 == cpu_to_le16(ONB_MAGIC1)) &&
(onbsig.magic2 == cpu_to_le16(ONB_MAGIC2)) &&
(onbsig.magic3 == cpu_to_le16(ONB_MAGIC3)))
foundit = 1;
}
iounmap(brdp->membase);
if (foundit)
break;
}
if (brdp->brdtype == BRD_ECPE)
stli_ecpeidisable(brdp);
else
stli_onbedisable(brdp);
if (! foundit) {
brdp->memaddr = 0;
brdp->membase = NULL;
printk(KERN_ERR "istallion: failed to probe shared memory "
"region for %s in EISA slot=%d\n",
stli_brdnames[brdp->brdtype], (brdp->iobase >> 12));
return -ENODEV;
}
return 0;
}
static int stli_getbrdnr(void)
{
unsigned int i;
for (i = 0; i < STL_MAXBRDS; i++) {
if (!stli_brds[i]) {
if (i >= stli_nrbrds)
stli_nrbrds = i + 1;
return i;
}
}
return -1;
}
static int __init stli_findeisabrds(void)
{
struct stlibrd *brdp;
unsigned int iobase, eid, i;
int brdnr, found = 0;
if (EISA_bus)
return 0;
for (iobase = 0x1000; (iobase <= 0xc000); iobase += 0x1000) {
outb(0xff, (iobase + 0xc80));
eid = inb(iobase + 0xc80);
eid |= inb(iobase + 0xc81) << 8;
if (eid != STL_EISAID)
continue;
for (i = 0; (i < STL_MAXBRDS); i++) {
brdp = stli_brds[i];
if (brdp == NULL)
continue;
if (brdp->iobase == iobase)
break;
}
if (i < STL_MAXBRDS)
continue;
if ((brdp = stli_allocbrd()) == NULL)
return found ? : -ENOMEM;
brdnr = stli_getbrdnr();
if (brdnr < 0)
return found ? : -ENOMEM;
brdp->brdnr = (unsigned int)brdnr;
eid = inb(iobase + 0xc82);
if (eid == ECP_EISAID)
brdp->brdtype = BRD_ECPE;
else if (eid == ONB_EISAID)
brdp->brdtype = BRD_ONBOARDE;
else
brdp->brdtype = BRD_UNKNOWN;
brdp->iobase = iobase;
outb(0x1, (iobase + 0xc84));
if (stli_eisamemprobe(brdp))
outb(0, (iobase + 0xc84));
if (stli_brdinit(brdp) < 0) {
kfree(brdp);
continue;
}
stli_brds[brdp->brdnr] = brdp;
found++;
for (i = 0; i < brdp->nrports; i++)
tty_register_device(stli_serial,
brdp->brdnr * STL_MAXPORTS + i, NULL);
}
return found;
}
static inline int stli_findeisabrds(void) { return 0; }
static int __devinit stli_pciprobe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct stlibrd *brdp;
unsigned int i;
int brdnr, retval = -EIO;
retval = pci_enable_device(pdev);
if (retval)
goto err;
brdp = stli_allocbrd();
if (brdp == NULL) {
retval = -ENOMEM;
goto err;
}
mutex_lock(&stli_brdslock);
brdnr = stli_getbrdnr();
if (brdnr < 0) {
printk(KERN_INFO "istallion: too many boards found, "
"maximum supported %d\n", STL_MAXBRDS);
mutex_unlock(&stli_brdslock);
retval = -EIO;
goto err_fr;
}
brdp->brdnr = (unsigned int)brdnr;
stli_brds[brdp->brdnr] = brdp;
mutex_unlock(&stli_brdslock);
brdp->brdtype = BRD_ECPPCI;
brdp->iobase = pci_resource_start(pdev, 3);
brdp->memaddr = pci_resource_start(pdev, 2);
retval = stli_brdinit(brdp);
if (retval)
goto err_null;
set_bit(BST_PROBED, &brdp->state);
pci_set_drvdata(pdev, brdp);
EBRDENABLE(brdp);
brdp->enable = NULL;
brdp->disable = NULL;
for (i = 0; i < brdp->nrports; i++)
tty_register_device(stli_serial, brdp->brdnr * STL_MAXPORTS + i,
&pdev->dev);
return 0;
err_null:
stli_brds[brdp->brdnr] = NULL;
err_fr:
kfree(brdp);
err:
return retval;
}
static void __devexit stli_pciremove(struct pci_dev *pdev)
{
struct stlibrd *brdp = pci_get_drvdata(pdev);
stli_cleanup_ports(brdp);
iounmap(brdp->membase);
if (brdp->iosize > 0)
release_region(brdp->iobase, brdp->iosize);
stli_brds[brdp->brdnr] = NULL;
kfree(brdp);
}
static struct stlibrd *stli_allocbrd(void)
{
struct stlibrd *brdp;
brdp = kzalloc(sizeof(struct stlibrd), GFP_KERNEL);
if (!brdp) {
printk(KERN_ERR "istallion: failed to allocate memory "
"(size=%Zd)\n", sizeof(struct stlibrd));
return NULL;
}
brdp->magic = STLI_BOARDMAGIC;
return brdp;
}
static int __init stli_initbrds(void)
{
struct stlibrd *brdp, *nxtbrdp;
struct stlconf conf;
unsigned int i, j, found = 0;
int retval;
for (stli_nrbrds = 0; stli_nrbrds < ARRAY_SIZE(stli_brdsp);
stli_nrbrds++) {
memset(&conf, 0, sizeof(conf));
if (stli_parsebrd(&conf, stli_brdsp[stli_nrbrds]) == 0)
continue;
if ((brdp = stli_allocbrd()) == NULL)
continue;
brdp->brdnr = stli_nrbrds;
brdp->brdtype = conf.brdtype;
brdp->iobase = conf.ioaddr1;
brdp->memaddr = conf.memaddr;
if (stli_brdinit(brdp) < 0) {
kfree(brdp);
continue;
}
stli_brds[brdp->brdnr] = brdp;
found++;
for (i = 0; i < brdp->nrports; i++)
tty_register_device(stli_serial,
brdp->brdnr * STL_MAXPORTS + i, NULL);
}
retval = stli_findeisabrds();
if (retval > 0)
found += retval;
stli_shared = 0;
if (stli_nrbrds > 1) {
for (i = 0; (i < stli_nrbrds); i++) {
brdp = stli_brds[i];
if (brdp == NULL)
continue;
for (j = i + 1; (j < stli_nrbrds); j++) {
nxtbrdp = stli_brds[j];
if (nxtbrdp == NULL)
continue;
if ((brdp->membase >= nxtbrdp->membase) &&
(brdp->membase <= (nxtbrdp->membase +
nxtbrdp->memsize - 1))) {
stli_shared++;
break;
}
}
}
}
if (stli_shared == 0) {
for (i = 0; (i < stli_nrbrds); i++) {
brdp = stli_brds[i];
if (brdp == NULL)
continue;
if (test_bit(BST_FOUND, &brdp->state)) {
EBRDENABLE(brdp);
brdp->enable = NULL;
brdp->disable = NULL;
}
}
}
retval = pci_register_driver(&stli_pcidriver);
if (retval && found == 0) {
printk(KERN_ERR "Neither isa nor eisa cards found nor pci "
"driver can be registered!\n");
goto err;
}
return 0;
err:
return retval;
}
static ssize_t stli_memread(struct file *fp, char __user *buf, size_t count, loff_t *offp)
{
unsigned long flags;
void __iomem *memptr;
struct stlibrd *brdp;
unsigned int brdnr;
int size, n;
void *p;
loff_t off = *offp;
brdnr = iminor(fp->f_path.dentry->d_inode);
if (brdnr >= stli_nrbrds)
return -ENODEV;
brdp = stli_brds[brdnr];
if (brdp == NULL)
return -ENODEV;
if (brdp->state == 0)
return -ENODEV;
if (off >= brdp->memsize || off + count < off)
return 0;
size = min(count, (size_t)(brdp->memsize - off));
p = (void *)__get_free_page(GFP_KERNEL);
if(p == NULL)
return -ENOMEM;
while (size > 0) {
spin_lock_irqsave(&brd_lock, flags);
EBRDENABLE(brdp);
memptr = EBRDGETMEMPTR(brdp, off);
n = min(size, (int)(brdp->pagesize - (((unsigned long) off) % brdp->pagesize)));
n = min(n, (int)PAGE_SIZE);
memcpy_fromio(p, memptr, n);
EBRDDISABLE(brdp);
spin_unlock_irqrestore(&brd_lock, flags);
if (copy_to_user(buf, p, n)) {
count = -EFAULT;
goto out;
}
off += n;
buf += n;
size -= n;
}
out:
*offp = off;
free_page((unsigned long)p);
return count;
}
static ssize_t stli_memwrite(struct file *fp, const char __user *buf, size_t count, loff_t *offp)
{
unsigned long flags;
void __iomem *memptr;
struct stlibrd *brdp;
char __user *chbuf;
unsigned int brdnr;
int size, n;
void *p;
loff_t off = *offp;
brdnr = iminor(fp->f_path.dentry->d_inode);
if (brdnr >= stli_nrbrds)
return -ENODEV;
brdp = stli_brds[brdnr];
if (brdp == NULL)
return -ENODEV;
if (brdp->state == 0)
return -ENODEV;
if (off >= brdp->memsize || off + count < off)
return 0;
chbuf = (char __user *) buf;
size = min(count, (size_t)(brdp->memsize - off));
p = (void *)__get_free_page(GFP_KERNEL);
if(p == NULL)
return -ENOMEM;
while (size > 0) {
n = min(size, (int)(brdp->pagesize - (((unsigned long) off) % brdp->pagesize)));
n = min(n, (int)PAGE_SIZE);
if (copy_from_user(p, chbuf, n)) {
if (count == 0)
count = -EFAULT;
goto out;
}
spin_lock_irqsave(&brd_lock, flags);
EBRDENABLE(brdp);
memptr = EBRDGETMEMPTR(brdp, off);
memcpy_toio(memptr, p, n);
EBRDDISABLE(brdp);
spin_unlock_irqrestore(&brd_lock, flags);
off += n;
chbuf += n;
size -= n;
}
out:
free_page((unsigned long) p);
*offp = off;
return count;
}
static int stli_getbrdstats(combrd_t __user *bp)
{
struct stlibrd *brdp;
unsigned int i;
combrd_t stli_brdstats;
if (copy_from_user(&stli_brdstats, bp, sizeof(combrd_t)))
return -EFAULT;
if (stli_brdstats.brd >= STL_MAXBRDS)
return -ENODEV;
brdp = stli_brds[stli_brdstats.brd];
if (brdp == NULL)
return -ENODEV;
memset(&stli_brdstats, 0, sizeof(combrd_t));
stli_brdstats.brd = brdp->brdnr;
stli_brdstats.type = brdp->brdtype;
stli_brdstats.hwid = 0;
stli_brdstats.state = brdp->state;
stli_brdstats.ioaddr = brdp->iobase;
stli_brdstats.memaddr = brdp->memaddr;
stli_brdstats.nrpanels = brdp->nrpanels;
stli_brdstats.nrports = brdp->nrports;
for (i = 0; (i < brdp->nrpanels); i++) {
stli_brdstats.panels[i].panel = i;
stli_brdstats.panels[i].hwid = brdp->panelids[i];
stli_brdstats.panels[i].nrports = brdp->panels[i];
}
if (copy_to_user(bp, &stli_brdstats, sizeof(combrd_t)))
return -EFAULT;
return 0;
}
static struct stliport *stli_getport(unsigned int brdnr, unsigned int panelnr,
unsigned int portnr)
{
struct stlibrd *brdp;
unsigned int i;
if (brdnr >= STL_MAXBRDS)
return NULL;
brdp = stli_brds[brdnr];
if (brdp == NULL)
return NULL;
for (i = 0; (i < panelnr); i++)
portnr += brdp->panels[i];
if (portnr >= brdp->nrports)
return NULL;
return brdp->ports[portnr];
}
static int stli_portcmdstats(struct tty_struct *tty, struct stliport *portp)
{
unsigned long flags;
struct stlibrd *brdp;
int rc;
memset(&stli_comstats, 0, sizeof(comstats_t));
if (portp == NULL)
return -ENODEV;
brdp = stli_brds[portp->brdnr];
if (brdp == NULL)
return -ENODEV;
mutex_lock(&portp->port.mutex);
if (test_bit(BST_STARTED, &brdp->state)) {
if ((rc = stli_cmdwait(brdp, portp, A_GETSTATS,
&stli_cdkstats, sizeof(asystats_t), 1)) < 0) {
mutex_unlock(&portp->port.mutex);
return rc;
}
} else {
memset(&stli_cdkstats, 0, sizeof(asystats_t));
}
stli_comstats.brd = portp->brdnr;
stli_comstats.panel = portp->panelnr;
stli_comstats.port = portp->portnr;
stli_comstats.state = portp->state;
stli_comstats.flags = portp->port.flags;
spin_lock_irqsave(&brd_lock, flags);
if (tty != NULL) {
if (portp->port.tty == tty) {
stli_comstats.ttystate = tty->flags;
stli_comstats.rxbuffered = -1;
if (tty->termios != NULL) {
stli_comstats.cflags = tty->termios->c_cflag;
stli_comstats.iflags = tty->termios->c_iflag;
stli_comstats.oflags = tty->termios->c_oflag;
stli_comstats.lflags = tty->termios->c_lflag;
}
}
}
spin_unlock_irqrestore(&brd_lock, flags);
stli_comstats.txtotal = stli_cdkstats.txchars;
stli_comstats.rxtotal = stli_cdkstats.rxchars + stli_cdkstats.ringover;
stli_comstats.txbuffered = stli_cdkstats.txringq;
stli_comstats.rxbuffered += stli_cdkstats.rxringq;
stli_comstats.rxoverrun = stli_cdkstats.overruns;
stli_comstats.rxparity = stli_cdkstats.parity;
stli_comstats.rxframing = stli_cdkstats.framing;
stli_comstats.rxlost = stli_cdkstats.ringover;
stli_comstats.rxbreaks = stli_cdkstats.rxbreaks;
stli_comstats.txbreaks = stli_cdkstats.txbreaks;
stli_comstats.txxon = stli_cdkstats.txstart;
stli_comstats.txxoff = stli_cdkstats.txstop;
stli_comstats.rxxon = stli_cdkstats.rxstart;
stli_comstats.rxxoff = stli_cdkstats.rxstop;
stli_comstats.rxrtsoff = stli_cdkstats.rtscnt / 2;
stli_comstats.rxrtson = stli_cdkstats.rtscnt - stli_comstats.rxrtsoff;
stli_comstats.modem = stli_cdkstats.dcdcnt;
stli_comstats.hwid = stli_cdkstats.hwid;
stli_comstats.signals = stli_mktiocm(stli_cdkstats.signals);
mutex_unlock(&portp->port.mutex);
return 0;
}
static int stli_getportstats(struct tty_struct *tty, struct stliport *portp,
comstats_t __user *cp)
{
struct stlibrd *brdp;
int rc;
if (!portp) {
if (copy_from_user(&stli_comstats, cp, sizeof(comstats_t)))
return -EFAULT;
portp = stli_getport(stli_comstats.brd, stli_comstats.panel,
stli_comstats.port);
if (!portp)
return -ENODEV;
}
brdp = stli_brds[portp->brdnr];
if (!brdp)
return -ENODEV;
if ((rc = stli_portcmdstats(tty, portp)) < 0)
return rc;
return copy_to_user(cp, &stli_comstats, sizeof(comstats_t)) ?
-EFAULT : 0;
}
static int stli_clrportstats(struct stliport *portp, comstats_t __user *cp)
{
struct stlibrd *brdp;
int rc;
if (!portp) {
if (copy_from_user(&stli_comstats, cp, sizeof(comstats_t)))
return -EFAULT;
portp = stli_getport(stli_comstats.brd, stli_comstats.panel,
stli_comstats.port);
if (!portp)
return -ENODEV;
}
brdp = stli_brds[portp->brdnr];
if (!brdp)
return -ENODEV;
mutex_lock(&portp->port.mutex);
if (test_bit(BST_STARTED, &brdp->state)) {
if ((rc = stli_cmdwait(brdp, portp, A_CLEARSTATS, NULL, 0, 0)) < 0) {
mutex_unlock(&portp->port.mutex);
return rc;
}
}
memset(&stli_comstats, 0, sizeof(comstats_t));
stli_comstats.brd = portp->brdnr;
stli_comstats.panel = portp->panelnr;
stli_comstats.port = portp->portnr;
mutex_unlock(&portp->port.mutex);
if (copy_to_user(cp, &stli_comstats, sizeof(comstats_t)))
return -EFAULT;
return 0;
}
static int stli_getportstruct(struct stliport __user *arg)
{
struct stliport stli_dummyport;
struct stliport *portp;
if (copy_from_user(&stli_dummyport, arg, sizeof(struct stliport)))
return -EFAULT;
portp = stli_getport(stli_dummyport.brdnr, stli_dummyport.panelnr,
stli_dummyport.portnr);
if (!portp)
return -ENODEV;
if (copy_to_user(arg, portp, sizeof(struct stliport)))
return -EFAULT;
return 0;
}
static int stli_getbrdstruct(struct stlibrd __user *arg)
{
struct stlibrd stli_dummybrd;
struct stlibrd *brdp;
if (copy_from_user(&stli_dummybrd, arg, sizeof(struct stlibrd)))
return -EFAULT;
if (stli_dummybrd.brdnr >= STL_MAXBRDS)
return -ENODEV;
brdp = stli_brds[stli_dummybrd.brdnr];
if (!brdp)
return -ENODEV;
if (copy_to_user(arg, brdp, sizeof(struct stlibrd)))
return -EFAULT;
return 0;
}
static long stli_memioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
struct stlibrd *brdp;
int brdnr, rc, done;
void __user *argp = (void __user *)arg;
done = 0;
rc = 0;
switch (cmd) {
case COM_GETPORTSTATS:
rc = stli_getportstats(NULL, NULL, argp);
done++;
break;
case COM_CLRPORTSTATS:
rc = stli_clrportstats(NULL, argp);
done++;
break;
case COM_GETBRDSTATS:
rc = stli_getbrdstats(argp);
done++;
break;
case COM_READPORT:
rc = stli_getportstruct(argp);
done++;
break;
case COM_READBOARD:
rc = stli_getbrdstruct(argp);
done++;
break;
}
if (done)
return rc;
brdnr = iminor(fp->f_dentry->d_inode);
if (brdnr >= STL_MAXBRDS)
return -ENODEV;
brdp = stli_brds[brdnr];
if (!brdp)
return -ENODEV;
if (brdp->state == 0)
return -ENODEV;
switch (cmd) {
case STL_BINTR:
EBRDINTR(brdp);
break;
case STL_BSTART:
rc = stli_startbrd(brdp);
break;
case STL_BSTOP:
clear_bit(BST_STARTED, &brdp->state);
break;
case STL_BRESET:
clear_bit(BST_STARTED, &brdp->state);
EBRDRESET(brdp);
if (stli_shared == 0) {
if (brdp->reenable != NULL)
(* brdp->reenable)(brdp);
}
break;
default:
rc = -ENOIOCTLCMD;
break;
}
return rc;
}
static void istallion_cleanup_isa(void)
{
struct stlibrd *brdp;
unsigned int j;
for (j = 0; (j < stli_nrbrds); j++) {
if ((brdp = stli_brds[j]) == NULL ||
test_bit(BST_PROBED, &brdp->state))
continue;
stli_cleanup_ports(brdp);
iounmap(brdp->membase);
if (brdp->iosize > 0)
release_region(brdp->iobase, brdp->iosize);
kfree(brdp);
stli_brds[j] = NULL;
}
}
static int __init istallion_module_init(void)
{
unsigned int i;
int retval;
printk(KERN_INFO "%s: version %s\n", stli_drvtitle, stli_drvversion);
spin_lock_init(&stli_lock);
spin_lock_init(&brd_lock);
stli_txcookbuf = kmalloc(STLI_TXBUFSIZE, GFP_KERNEL);
if (!stli_txcookbuf) {
printk(KERN_ERR "istallion: failed to allocate memory "
"(size=%d)\n", STLI_TXBUFSIZE);
retval = -ENOMEM;
goto err;
}
stli_serial = alloc_tty_driver(STL_MAXBRDS * STL_MAXPORTS);
if (!stli_serial) {
retval = -ENOMEM;
goto err_free;
}
stli_serial->owner = THIS_MODULE;
stli_serial->driver_name = stli_drvname;
stli_serial->name = stli_serialname;
stli_serial->major = STL_SERIALMAJOR;
stli_serial->minor_start = 0;
stli_serial->type = TTY_DRIVER_TYPE_SERIAL;
stli_serial->subtype = SERIAL_TYPE_NORMAL;
stli_serial->init_termios = stli_deftermios;
stli_serial->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
tty_set_operations(stli_serial, &stli_ops);
retval = tty_register_driver(stli_serial);
if (retval) {
printk(KERN_ERR "istallion: failed to register serial driver\n");
goto err_ttyput;
}
retval = stli_initbrds();
if (retval)
goto err_ttyunr;
retval = register_chrdev(STL_SIOMEMMAJOR, "staliomem", &stli_fsiomem);
if (retval) {
printk(KERN_ERR "istallion: failed to register serial memory "
"device\n");
goto err_deinit;
}
istallion_class = class_create(THIS_MODULE, "staliomem");
for (i = 0; i < 4; i++)
device_create(istallion_class, NULL, MKDEV(STL_SIOMEMMAJOR, i),
NULL, "staliomem%d", i);
return 0;
err_deinit:
pci_unregister_driver(&stli_pcidriver);
istallion_cleanup_isa();
err_ttyunr:
tty_unregister_driver(stli_serial);
err_ttyput:
put_tty_driver(stli_serial);
err_free:
kfree(stli_txcookbuf);
err:
return retval;
}
static void __exit istallion_module_exit(void)
{
unsigned int j;
printk(KERN_INFO "Unloading %s: version %s\n", stli_drvtitle,
stli_drvversion);
if (stli_timeron) {
stli_timeron = 0;
del_timer_sync(&stli_timerlist);
}
unregister_chrdev(STL_SIOMEMMAJOR, "staliomem");
for (j = 0; j < 4; j++)
device_destroy(istallion_class, MKDEV(STL_SIOMEMMAJOR, j));
class_destroy(istallion_class);
pci_unregister_driver(&stli_pcidriver);
istallion_cleanup_isa();
tty_unregister_driver(stli_serial);
put_tty_driver(stli_serial);
kfree(stli_txcookbuf);
}
