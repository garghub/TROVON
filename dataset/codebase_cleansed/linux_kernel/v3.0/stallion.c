static void stl_cd_change(struct stlport *portp)
{
unsigned int oldsigs = portp->sigs;
struct tty_struct *tty = tty_port_tty_get(&portp->port);
if (!tty)
return;
portp->sigs = stl_getsignals(portp);
if ((portp->sigs & TIOCM_CD) && ((oldsigs & TIOCM_CD) == 0))
wake_up_interruptible(&portp->port.open_wait);
if ((oldsigs & TIOCM_CD) && ((portp->sigs & TIOCM_CD) == 0))
if (portp->port.flags & ASYNC_CHECK_CD)
tty_hangup(tty);
tty_kref_put(tty);
}
static int __init stl_parsebrd(struct stlconf *confp, char **argp)
{
char *sp;
unsigned int i;
pr_debug("stl_parsebrd(confp=%p,argp=%p)\n", confp, argp);
if ((argp[0] == NULL) || (*argp[0] == 0))
return 0;
for (sp = argp[0], i = 0; (*sp != 0) && (i < 25); sp++, i++)
*sp = tolower(*sp);
for (i = 0; i < ARRAY_SIZE(stl_brdstr); i++)
if (strcmp(stl_brdstr[i].name, argp[0]) == 0)
break;
if (i == ARRAY_SIZE(stl_brdstr)) {
printk("STALLION: unknown board name, %s?\n", argp[0]);
return 0;
}
confp->brdtype = stl_brdstr[i].type;
i = 1;
if ((argp[i] != NULL) && (*argp[i] != 0))
confp->ioaddr1 = simple_strtoul(argp[i], NULL, 0);
i++;
if (confp->brdtype == BRD_ECH) {
if ((argp[i] != NULL) && (*argp[i] != 0))
confp->ioaddr2 = simple_strtoul(argp[i], NULL, 0);
i++;
}
if ((argp[i] != NULL) && (*argp[i] != 0))
confp->irq = simple_strtoul(argp[i], NULL, 0);
return 1;
}
static struct stlbrd *stl_allocbrd(void)
{
struct stlbrd *brdp;
brdp = kzalloc(sizeof(struct stlbrd), GFP_KERNEL);
if (!brdp) {
printk("STALLION: failed to allocate memory (size=%Zd)\n",
sizeof(struct stlbrd));
return NULL;
}
brdp->magic = STL_BOARDMAGIC;
return brdp;
}
static int stl_activate(struct tty_port *port, struct tty_struct *tty)
{
struct stlport *portp = container_of(port, struct stlport, port);
if (!portp->tx.buf) {
portp->tx.buf = kmalloc(STL_TXBUFSIZE, GFP_KERNEL);
if (!portp->tx.buf)
return -ENOMEM;
portp->tx.head = portp->tx.buf;
portp->tx.tail = portp->tx.buf;
}
stl_setport(portp, tty->termios);
portp->sigs = stl_getsignals(portp);
stl_setsignals(portp, 1, 1);
stl_enablerxtx(portp, 1, 1);
stl_startrxtx(portp, 1, 0);
return 0;
}
static int stl_open(struct tty_struct *tty, struct file *filp)
{
struct stlport *portp;
struct stlbrd *brdp;
unsigned int minordev, brdnr, panelnr;
int portnr;
pr_debug("stl_open(tty=%p,filp=%p): device=%s\n", tty, filp, tty->name);
minordev = tty->index;
brdnr = MINOR2BRD(minordev);
if (brdnr >= stl_nrbrds)
return -ENODEV;
brdp = stl_brds[brdnr];
if (brdp == NULL)
return -ENODEV;
minordev = MINOR2PORT(minordev);
for (portnr = -1, panelnr = 0; panelnr < STL_MAXPANELS; panelnr++) {
if (brdp->panels[panelnr] == NULL)
break;
if (minordev < brdp->panels[panelnr]->nrports) {
portnr = minordev;
break;
}
minordev -= brdp->panels[panelnr]->nrports;
}
if (portnr < 0)
return -ENODEV;
portp = brdp->panels[panelnr]->ports[portnr];
if (portp == NULL)
return -ENODEV;
tty->driver_data = portp;
return tty_port_open(&portp->port, tty, filp);
}
static int stl_carrier_raised(struct tty_port *port)
{
struct stlport *portp = container_of(port, struct stlport, port);
return (portp->sigs & TIOCM_CD) ? 1 : 0;
}
static void stl_dtr_rts(struct tty_port *port, int on)
{
struct stlport *portp = container_of(port, struct stlport, port);
stl_setsignals(portp, on, on);
}
static void stl_flushbuffer(struct tty_struct *tty)
{
struct stlport *portp;
pr_debug("stl_flushbuffer(tty=%p)\n", tty);
portp = tty->driver_data;
if (portp == NULL)
return;
stl_flush(portp);
tty_wakeup(tty);
}
static void stl_waituntilsent(struct tty_struct *tty, int timeout)
{
struct stlport *portp;
unsigned long tend;
pr_debug("stl_waituntilsent(tty=%p,timeout=%d)\n", tty, timeout);
portp = tty->driver_data;
if (portp == NULL)
return;
if (timeout == 0)
timeout = HZ;
tend = jiffies + timeout;
while (stl_datastate(portp)) {
if (signal_pending(current))
break;
msleep_interruptible(20);
if (time_after_eq(jiffies, tend))
break;
}
}
static void stl_shutdown(struct tty_port *port)
{
struct stlport *portp = container_of(port, struct stlport, port);
stl_disableintrs(portp);
stl_enablerxtx(portp, 0, 0);
stl_flush(portp);
portp->istate = 0;
if (portp->tx.buf != NULL) {
kfree(portp->tx.buf);
portp->tx.buf = NULL;
portp->tx.head = NULL;
portp->tx.tail = NULL;
}
}
static void stl_close(struct tty_struct *tty, struct file *filp)
{
struct stlport*portp;
pr_debug("stl_close(tty=%p,filp=%p)\n", tty, filp);
portp = tty->driver_data;
if(portp == NULL)
return;
tty_port_close(&portp->port, tty, filp);
}
static int stl_write(struct tty_struct *tty, const unsigned char *buf, int count)
{
struct stlport *portp;
unsigned int len, stlen;
unsigned char *chbuf;
char *head, *tail;
pr_debug("stl_write(tty=%p,buf=%p,count=%d)\n", tty, buf, count);
portp = tty->driver_data;
if (portp == NULL)
return 0;
if (portp->tx.buf == NULL)
return 0;
chbuf = (unsigned char *) buf;
head = portp->tx.head;
tail = portp->tx.tail;
if (head >= tail) {
len = STL_TXBUFSIZE - (head - tail) - 1;
stlen = STL_TXBUFSIZE - (head - portp->tx.buf);
} else {
len = tail - head - 1;
stlen = len;
}
len = min(len, (unsigned int)count);
count = 0;
while (len > 0) {
stlen = min(len, stlen);
memcpy(head, chbuf, stlen);
len -= stlen;
chbuf += stlen;
count += stlen;
head += stlen;
if (head >= (portp->tx.buf + STL_TXBUFSIZE)) {
head = portp->tx.buf;
stlen = tail - head;
}
}
portp->tx.head = head;
clear_bit(ASYI_TXLOW, &portp->istate);
stl_startrxtx(portp, -1, 1);
return count;
}
static int stl_putchar(struct tty_struct *tty, unsigned char ch)
{
struct stlport *portp;
unsigned int len;
char *head, *tail;
pr_debug("stl_putchar(tty=%p,ch=%x)\n", tty, ch);
portp = tty->driver_data;
if (portp == NULL)
return -EINVAL;
if (portp->tx.buf == NULL)
return -EINVAL;
head = portp->tx.head;
tail = portp->tx.tail;
len = (head >= tail) ? (STL_TXBUFSIZE - (head - tail)) : (tail - head);
len--;
if (len > 0) {
*head++ = ch;
if (head >= (portp->tx.buf + STL_TXBUFSIZE))
head = portp->tx.buf;
}
portp->tx.head = head;
return 0;
}
static void stl_flushchars(struct tty_struct *tty)
{
struct stlport *portp;
pr_debug("stl_flushchars(tty=%p)\n", tty);
portp = tty->driver_data;
if (portp == NULL)
return;
if (portp->tx.buf == NULL)
return;
stl_startrxtx(portp, -1, 1);
}
static int stl_writeroom(struct tty_struct *tty)
{
struct stlport *portp;
char *head, *tail;
pr_debug("stl_writeroom(tty=%p)\n", tty);
portp = tty->driver_data;
if (portp == NULL)
return 0;
if (portp->tx.buf == NULL)
return 0;
head = portp->tx.head;
tail = portp->tx.tail;
return (head >= tail) ? (STL_TXBUFSIZE - (head - tail) - 1) : (tail - head - 1);
}
static int stl_charsinbuffer(struct tty_struct *tty)
{
struct stlport *portp;
unsigned int size;
char *head, *tail;
pr_debug("stl_charsinbuffer(tty=%p)\n", tty);
portp = tty->driver_data;
if (portp == NULL)
return 0;
if (portp->tx.buf == NULL)
return 0;
head = portp->tx.head;
tail = portp->tx.tail;
size = (head >= tail) ? (head - tail) : (STL_TXBUFSIZE - (tail - head));
if ((size == 0) && test_bit(ASYI_TXBUSY, &portp->istate))
size = 1;
return size;
}
static int stl_getserial(struct stlport *portp, struct serial_struct __user *sp)
{
struct serial_struct sio;
struct stlbrd *brdp;
pr_debug("stl_getserial(portp=%p,sp=%p)\n", portp, sp);
memset(&sio, 0, sizeof(struct serial_struct));
mutex_lock(&portp->port.mutex);
sio.line = portp->portnr;
sio.port = portp->ioaddr;
sio.flags = portp->port.flags;
sio.baud_base = portp->baud_base;
sio.close_delay = portp->close_delay;
sio.closing_wait = portp->closing_wait;
sio.custom_divisor = portp->custom_divisor;
sio.hub6 = 0;
if (portp->uartp == &stl_cd1400uart) {
sio.type = PORT_CIRRUS;
sio.xmit_fifo_size = CD1400_TXFIFOSIZE;
} else {
sio.type = PORT_UNKNOWN;
sio.xmit_fifo_size = SC26198_TXFIFOSIZE;
}
brdp = stl_brds[portp->brdnr];
if (brdp != NULL)
sio.irq = brdp->irq;
mutex_unlock(&portp->port.mutex);
return copy_to_user(sp, &sio, sizeof(struct serial_struct)) ? -EFAULT : 0;
}
static int stl_setserial(struct tty_struct *tty, struct serial_struct __user *sp)
{
struct stlport * portp = tty->driver_data;
struct serial_struct sio;
pr_debug("stl_setserial(portp=%p,sp=%p)\n", portp, sp);
if (copy_from_user(&sio, sp, sizeof(struct serial_struct)))
return -EFAULT;
mutex_lock(&portp->port.mutex);
if (!capable(CAP_SYS_ADMIN)) {
if ((sio.baud_base != portp->baud_base) ||
(sio.close_delay != portp->close_delay) ||
((sio.flags & ~ASYNC_USR_MASK) !=
(portp->port.flags & ~ASYNC_USR_MASK))) {
mutex_unlock(&portp->port.mutex);
return -EPERM;
}
}
portp->port.flags = (portp->port.flags & ~ASYNC_USR_MASK) |
(sio.flags & ASYNC_USR_MASK);
portp->baud_base = sio.baud_base;
portp->close_delay = sio.close_delay;
portp->closing_wait = sio.closing_wait;
portp->custom_divisor = sio.custom_divisor;
mutex_unlock(&portp->port.mutex);
stl_setport(portp, tty->termios);
return 0;
}
static int stl_tiocmget(struct tty_struct *tty)
{
struct stlport *portp;
portp = tty->driver_data;
if (portp == NULL)
return -ENODEV;
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
return stl_getsignals(portp);
}
static int stl_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct stlport *portp;
int rts = -1, dtr = -1;
portp = tty->driver_data;
if (portp == NULL)
return -ENODEV;
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
stl_setsignals(portp, dtr, rts);
return 0;
}
static int stl_ioctl(struct tty_struct *tty, unsigned int cmd, unsigned long arg)
{
struct stlport *portp;
int rc;
void __user *argp = (void __user *)arg;
pr_debug("stl_ioctl(tty=%p,cmd=%x,arg=%lx)\n", tty, cmd, arg);
portp = tty->driver_data;
if (portp == NULL)
return -ENODEV;
if ((cmd != TIOCGSERIAL) && (cmd != TIOCSSERIAL) &&
(cmd != COM_GETPORTSTATS) && (cmd != COM_CLRPORTSTATS))
if (tty->flags & (1 << TTY_IO_ERROR))
return -EIO;
rc = 0;
switch (cmd) {
case TIOCGSERIAL:
rc = stl_getserial(portp, argp);
break;
case TIOCSSERIAL:
rc = stl_setserial(tty, argp);
break;
case COM_GETPORTSTATS:
rc = stl_getportstats(tty, portp, argp);
break;
case COM_CLRPORTSTATS:
rc = stl_clrportstats(portp, argp);
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
static void stl_start(struct tty_struct *tty)
{
struct stlport *portp;
pr_debug("stl_start(tty=%p)\n", tty);
portp = tty->driver_data;
if (portp == NULL)
return;
stl_startrxtx(portp, -1, 1);
}
static void stl_settermios(struct tty_struct *tty, struct ktermios *old)
{
struct stlport *portp;
struct ktermios *tiosp;
pr_debug("stl_settermios(tty=%p,old=%p)\n", tty, old);
portp = tty->driver_data;
if (portp == NULL)
return;
tiosp = tty->termios;
if ((tiosp->c_cflag == old->c_cflag) &&
(tiosp->c_iflag == old->c_iflag))
return;
stl_setport(portp, tiosp);
stl_setsignals(portp, ((tiosp->c_cflag & (CBAUD & ~CBAUDEX)) ? 1 : 0),
-1);
if ((old->c_cflag & CRTSCTS) && ((tiosp->c_cflag & CRTSCTS) == 0)) {
tty->hw_stopped = 0;
stl_start(tty);
}
if (((old->c_cflag & CLOCAL) == 0) && (tiosp->c_cflag & CLOCAL))
wake_up_interruptible(&portp->port.open_wait);
}
static void stl_throttle(struct tty_struct *tty)
{
struct stlport *portp;
pr_debug("stl_throttle(tty=%p)\n", tty);
portp = tty->driver_data;
if (portp == NULL)
return;
stl_flowctrl(portp, 0);
}
static void stl_unthrottle(struct tty_struct *tty)
{
struct stlport *portp;
pr_debug("stl_unthrottle(tty=%p)\n", tty);
portp = tty->driver_data;
if (portp == NULL)
return;
stl_flowctrl(portp, 1);
}
static void stl_stop(struct tty_struct *tty)
{
struct stlport *portp;
pr_debug("stl_stop(tty=%p)\n", tty);
portp = tty->driver_data;
if (portp == NULL)
return;
stl_startrxtx(portp, -1, 0);
}
static void stl_hangup(struct tty_struct *tty)
{
struct stlport *portp = tty->driver_data;
pr_debug("stl_hangup(tty=%p)\n", tty);
if (portp == NULL)
return;
tty_port_hangup(&portp->port);
}
static int stl_breakctl(struct tty_struct *tty, int state)
{
struct stlport *portp;
pr_debug("stl_breakctl(tty=%p,state=%d)\n", tty, state);
portp = tty->driver_data;
if (portp == NULL)
return -EINVAL;
stl_sendbreak(portp, ((state == -1) ? 1 : 2));
return 0;
}
static void stl_sendxchar(struct tty_struct *tty, char ch)
{
struct stlport *portp;
pr_debug("stl_sendxchar(tty=%p,ch=%x)\n", tty, ch);
portp = tty->driver_data;
if (portp == NULL)
return;
if (ch == STOP_CHAR(tty))
stl_sendflow(portp, 0);
else if (ch == START_CHAR(tty))
stl_sendflow(portp, 1);
else
stl_putchar(tty, ch);
}
static void stl_portinfo(struct seq_file *m, struct stlport *portp, int portnr)
{
int sigs;
char sep;
seq_printf(m, "%d: uart:%s tx:%d rx:%d",
portnr, (portp->hwid == 1) ? "SC26198" : "CD1400",
(int) portp->stats.txtotal, (int) portp->stats.rxtotal);
if (portp->stats.rxframing)
seq_printf(m, " fe:%d", (int) portp->stats.rxframing);
if (portp->stats.rxparity)
seq_printf(m, " pe:%d", (int) portp->stats.rxparity);
if (portp->stats.rxbreaks)
seq_printf(m, " brk:%d", (int) portp->stats.rxbreaks);
if (portp->stats.rxoverrun)
seq_printf(m, " oe:%d", (int) portp->stats.rxoverrun);
sigs = stl_getsignals(portp);
sep = ' ';
if (sigs & TIOCM_RTS) {
seq_printf(m, "%c%s", sep, "RTS");
sep = '|';
}
if (sigs & TIOCM_CTS) {
seq_printf(m, "%c%s", sep, "CTS");
sep = '|';
}
if (sigs & TIOCM_DTR) {
seq_printf(m, "%c%s", sep, "DTR");
sep = '|';
}
if (sigs & TIOCM_CD) {
seq_printf(m, "%c%s", sep, "DCD");
sep = '|';
}
if (sigs & TIOCM_DSR) {
seq_printf(m, "%c%s", sep, "DSR");
sep = '|';
}
seq_putc(m, '\n');
}
static int stl_proc_show(struct seq_file *m, void *v)
{
struct stlbrd *brdp;
struct stlpanel *panelp;
struct stlport *portp;
unsigned int brdnr, panelnr, portnr;
int totalport;
totalport = 0;
seq_printf(m, "%s: version %s\n", stl_drvtitle, stl_drvversion);
for (brdnr = 0; brdnr < stl_nrbrds; brdnr++) {
brdp = stl_brds[brdnr];
if (brdp == NULL)
continue;
if (brdp->state == 0)
continue;
totalport = brdnr * STL_MAXPORTS;
for (panelnr = 0; panelnr < brdp->nrpanels; panelnr++) {
panelp = brdp->panels[panelnr];
if (panelp == NULL)
continue;
for (portnr = 0; portnr < panelp->nrports; portnr++,
totalport++) {
portp = panelp->ports[portnr];
if (portp == NULL)
continue;
stl_portinfo(m, portp, totalport);
}
}
}
return 0;
}
static int stl_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, stl_proc_show, NULL);
}
static irqreturn_t stl_intr(int irq, void *dev_id)
{
struct stlbrd *brdp = dev_id;
pr_debug("stl_intr(brdp=%p,irq=%d)\n", brdp, brdp->irq);
return IRQ_RETVAL((* brdp->isr)(brdp));
}
static int stl_eiointr(struct stlbrd *brdp)
{
struct stlpanel *panelp;
unsigned int iobase;
int handled = 0;
spin_lock(&brd_lock);
panelp = brdp->panels[0];
iobase = panelp->iobase;
while (inb(brdp->iostatus) & EIO_INTRPEND) {
handled = 1;
(* panelp->isr)(panelp, iobase);
}
spin_unlock(&brd_lock);
return handled;
}
static int stl_echatintr(struct stlbrd *brdp)
{
struct stlpanel *panelp;
unsigned int ioaddr, bnknr;
int handled = 0;
outb((brdp->ioctrlval | ECH_BRDENABLE), brdp->ioctrl);
while (inb(brdp->iostatus) & ECH_INTRPEND) {
handled = 1;
for (bnknr = 0; bnknr < brdp->nrbnks; bnknr++) {
ioaddr = brdp->bnkstataddr[bnknr];
if (inb(ioaddr) & ECH_PNLINTRPEND) {
panelp = brdp->bnk2panel[bnknr];
(* panelp->isr)(panelp, (ioaddr & 0xfffc));
}
}
}
outb((brdp->ioctrlval | ECH_BRDDISABLE), brdp->ioctrl);
return handled;
}
static int stl_echmcaintr(struct stlbrd *brdp)
{
struct stlpanel *panelp;
unsigned int ioaddr, bnknr;
int handled = 0;
while (inb(brdp->iostatus) & ECH_INTRPEND) {
handled = 1;
for (bnknr = 0; bnknr < brdp->nrbnks; bnknr++) {
ioaddr = brdp->bnkstataddr[bnknr];
if (inb(ioaddr) & ECH_PNLINTRPEND) {
panelp = brdp->bnk2panel[bnknr];
(* panelp->isr)(panelp, (ioaddr & 0xfffc));
}
}
}
return handled;
}
static int stl_echpciintr(struct stlbrd *brdp)
{
struct stlpanel *panelp;
unsigned int ioaddr, bnknr, recheck;
int handled = 0;
while (1) {
recheck = 0;
for (bnknr = 0; bnknr < brdp->nrbnks; bnknr++) {
outb(brdp->bnkpageaddr[bnknr], brdp->ioctrl);
ioaddr = brdp->bnkstataddr[bnknr];
if (inb(ioaddr) & ECH_PNLINTRPEND) {
panelp = brdp->bnk2panel[bnknr];
(* panelp->isr)(panelp, (ioaddr & 0xfffc));
recheck++;
handled = 1;
}
}
if (! recheck)
break;
}
return handled;
}
static int stl_echpci64intr(struct stlbrd *brdp)
{
struct stlpanel *panelp;
unsigned int ioaddr, bnknr;
int handled = 0;
while (inb(brdp->ioctrl) & 0x1) {
handled = 1;
for (bnknr = 0; bnknr < brdp->nrbnks; bnknr++) {
ioaddr = brdp->bnkstataddr[bnknr];
if (inb(ioaddr) & ECH_PNLINTRPEND) {
panelp = brdp->bnk2panel[bnknr];
(* panelp->isr)(panelp, (ioaddr & 0xfffc));
}
}
}
return handled;
}
static int __devinit stl_initports(struct stlbrd *brdp, struct stlpanel *panelp)
{
struct stlport *portp;
unsigned int i;
int chipmask;
pr_debug("stl_initports(brdp=%p,panelp=%p)\n", brdp, panelp);
chipmask = stl_panelinit(brdp, panelp);
for (i = 0; i < panelp->nrports; i++) {
portp = kzalloc(sizeof(struct stlport), GFP_KERNEL);
if (!portp) {
printk("STALLION: failed to allocate memory "
"(size=%Zd)\n", sizeof(struct stlport));
break;
}
tty_port_init(&portp->port);
portp->port.ops = &stl_port_ops;
portp->magic = STL_PORTMAGIC;
portp->portnr = i;
portp->brdnr = panelp->brdnr;
portp->panelnr = panelp->panelnr;
portp->uartp = panelp->uartp;
portp->clk = brdp->clk;
portp->baud_base = STL_BAUDBASE;
portp->close_delay = STL_CLOSEDELAY;
portp->closing_wait = 30 * HZ;
init_waitqueue_head(&portp->port.open_wait);
init_waitqueue_head(&portp->port.close_wait);
portp->stats.brd = portp->brdnr;
portp->stats.panel = portp->panelnr;
portp->stats.port = portp->portnr;
panelp->ports[i] = portp;
stl_portinit(brdp, panelp, portp);
}
return 0;
}
static void stl_cleanup_panels(struct stlbrd *brdp)
{
struct stlpanel *panelp;
struct stlport *portp;
unsigned int j, k;
struct tty_struct *tty;
for (j = 0; j < STL_MAXPANELS; j++) {
panelp = brdp->panels[j];
if (panelp == NULL)
continue;
for (k = 0; k < STL_PORTSPERPANEL; k++) {
portp = panelp->ports[k];
if (portp == NULL)
continue;
tty = tty_port_tty_get(&portp->port);
if (tty != NULL) {
stl_hangup(tty);
tty_kref_put(tty);
}
kfree(portp->tx.buf);
kfree(portp);
}
kfree(panelp);
}
}
static int __devinit stl_initeio(struct stlbrd *brdp)
{
struct stlpanel *panelp;
unsigned int status;
char *name;
int retval;
pr_debug("stl_initeio(brdp=%p)\n", brdp);
brdp->ioctrl = brdp->ioaddr1 + 1;
brdp->iostatus = brdp->ioaddr1 + 2;
status = inb(brdp->iostatus);
if ((status & EIO_IDBITMASK) == EIO_MK3)
brdp->ioctrl++;
if (brdp->brdtype == BRD_EASYIOPCI) {
brdp->iosize1 = 0x80;
brdp->iosize2 = 0x80;
name = "serial(EIO-PCI)";
outb(0x41, (brdp->ioaddr2 + 0x4c));
} else {
brdp->iosize1 = 8;
name = "serial(EIO)";
if ((brdp->irq < 0) || (brdp->irq > 15) ||
(stl_vecmap[brdp->irq] == (unsigned char) 0xff)) {
printk("STALLION: invalid irq=%d for brd=%d\n",
brdp->irq, brdp->brdnr);
retval = -EINVAL;
goto err;
}
outb((stl_vecmap[brdp->irq] | EIO_0WS |
((brdp->irqtype) ? EIO_INTLEVEL : EIO_INTEDGE)),
brdp->ioctrl);
}
retval = -EBUSY;
if (!request_region(brdp->ioaddr1, brdp->iosize1, name)) {
printk(KERN_WARNING "STALLION: Warning, board %d I/O address "
"%x conflicts with another device\n", brdp->brdnr,
brdp->ioaddr1);
goto err;
}
if (brdp->iosize2 > 0)
if (!request_region(brdp->ioaddr2, brdp->iosize2, name)) {
printk(KERN_WARNING "STALLION: Warning, board %d I/O "
"address %x conflicts with another device\n",
brdp->brdnr, brdp->ioaddr2);
printk(KERN_WARNING "STALLION: Warning, also "
"releasing board %d I/O address %x \n",
brdp->brdnr, brdp->ioaddr1);
goto err_rel1;
}
brdp->clk = CD1400_CLK;
brdp->isr = stl_eiointr;
retval = -ENODEV;
switch (status & EIO_IDBITMASK) {
case EIO_8PORTM:
brdp->clk = CD1400_CLK8M;
case EIO_8PORTRS:
case EIO_8PORTDI:
brdp->nrports = 8;
break;
case EIO_4PORTRS:
brdp->nrports = 4;
break;
case EIO_MK3:
switch (status & EIO_BRDMASK) {
case ID_BRD4:
brdp->nrports = 4;
break;
case ID_BRD8:
brdp->nrports = 8;
break;
case ID_BRD16:
brdp->nrports = 16;
break;
default:
goto err_rel2;
}
break;
default:
goto err_rel2;
}
panelp = kzalloc(sizeof(struct stlpanel), GFP_KERNEL);
if (!panelp) {
printk(KERN_WARNING "STALLION: failed to allocate memory "
"(size=%Zd)\n", sizeof(struct stlpanel));
retval = -ENOMEM;
goto err_rel2;
}
panelp->magic = STL_PANELMAGIC;
panelp->brdnr = brdp->brdnr;
panelp->panelnr = 0;
panelp->nrports = brdp->nrports;
panelp->iobase = brdp->ioaddr1;
panelp->hwid = status;
if ((status & EIO_IDBITMASK) == EIO_MK3) {
panelp->uartp = &stl_sc26198uart;
panelp->isr = stl_sc26198intr;
} else {
panelp->uartp = &stl_cd1400uart;
panelp->isr = stl_cd1400eiointr;
}
brdp->panels[0] = panelp;
brdp->nrpanels = 1;
brdp->state |= BRD_FOUND;
brdp->hwid = status;
if (request_irq(brdp->irq, stl_intr, IRQF_SHARED, name, brdp) != 0) {
printk("STALLION: failed to register interrupt "
"routine for %s irq=%d\n", name, brdp->irq);
retval = -ENODEV;
goto err_fr;
}
return 0;
err_fr:
stl_cleanup_panels(brdp);
err_rel2:
if (brdp->iosize2 > 0)
release_region(brdp->ioaddr2, brdp->iosize2);
err_rel1:
release_region(brdp->ioaddr1, brdp->iosize1);
err:
return retval;
}
static int __devinit stl_initech(struct stlbrd *brdp)
{
struct stlpanel *panelp;
unsigned int status, nxtid, ioaddr, conflict, panelnr, banknr, i;
int retval;
char *name;
pr_debug("stl_initech(brdp=%p)\n", brdp);
status = 0;
conflict = 0;
switch (brdp->brdtype) {
case BRD_ECH:
brdp->isr = stl_echatintr;
brdp->ioctrl = brdp->ioaddr1 + 1;
brdp->iostatus = brdp->ioaddr1 + 1;
status = inb(brdp->iostatus);
if ((status & ECH_IDBITMASK) != ECH_ID) {
retval = -ENODEV;
goto err;
}
if ((brdp->irq < 0) || (brdp->irq > 15) ||
(stl_vecmap[brdp->irq] == (unsigned char) 0xff)) {
printk("STALLION: invalid irq=%d for brd=%d\n",
brdp->irq, brdp->brdnr);
retval = -EINVAL;
goto err;
}
status = ((brdp->ioaddr2 & ECH_ADDR2MASK) >> 1);
status |= (stl_vecmap[brdp->irq] << 1);
outb((status | ECH_BRDRESET), brdp->ioaddr1);
brdp->ioctrlval = ECH_INTENABLE |
((brdp->irqtype) ? ECH_INTLEVEL : ECH_INTEDGE);
for (i = 0; i < 10; i++)
outb((brdp->ioctrlval | ECH_BRDENABLE), brdp->ioctrl);
brdp->iosize1 = 2;
brdp->iosize2 = 32;
name = "serial(EC8/32)";
outb(status, brdp->ioaddr1);
break;
case BRD_ECHMC:
brdp->isr = stl_echmcaintr;
brdp->ioctrl = brdp->ioaddr1 + 0x20;
brdp->iostatus = brdp->ioctrl;
status = inb(brdp->iostatus);
if ((status & ECH_IDBITMASK) != ECH_ID) {
retval = -ENODEV;
goto err;
}
if ((brdp->irq < 0) || (brdp->irq > 15) ||
(stl_vecmap[brdp->irq] == (unsigned char) 0xff)) {
printk("STALLION: invalid irq=%d for brd=%d\n",
brdp->irq, brdp->brdnr);
retval = -EINVAL;
goto err;
}
outb(ECHMC_BRDRESET, brdp->ioctrl);
outb(ECHMC_INTENABLE, brdp->ioctrl);
brdp->iosize1 = 64;
name = "serial(EC8/32-MC)";
break;
case BRD_ECHPCI:
brdp->isr = stl_echpciintr;
brdp->ioctrl = brdp->ioaddr1 + 2;
brdp->iosize1 = 4;
brdp->iosize2 = 8;
name = "serial(EC8/32-PCI)";
break;
case BRD_ECH64PCI:
brdp->isr = stl_echpci64intr;
brdp->ioctrl = brdp->ioaddr2 + 0x40;
outb(0x43, (brdp->ioaddr1 + 0x4c));
brdp->iosize1 = 0x80;
brdp->iosize2 = 0x80;
name = "serial(EC8/64-PCI)";
break;
default:
printk("STALLION: unknown board type=%d\n", brdp->brdtype);
retval = -EINVAL;
goto err;
}
retval = -EBUSY;
if (!request_region(brdp->ioaddr1, brdp->iosize1, name)) {
printk(KERN_WARNING "STALLION: Warning, board %d I/O address "
"%x conflicts with another device\n", brdp->brdnr,
brdp->ioaddr1);
goto err;
}
if (brdp->iosize2 > 0)
if (!request_region(brdp->ioaddr2, brdp->iosize2, name)) {
printk(KERN_WARNING "STALLION: Warning, board %d I/O "
"address %x conflicts with another device\n",
brdp->brdnr, brdp->ioaddr2);
printk(KERN_WARNING "STALLION: Warning, also "
"releasing board %d I/O address %x \n",
brdp->brdnr, brdp->ioaddr1);
goto err_rel1;
}
brdp->clk = CD1400_CLK;
brdp->hwid = status;
ioaddr = brdp->ioaddr2;
banknr = 0;
panelnr = 0;
nxtid = 0;
for (i = 0; i < STL_MAXPANELS; i++) {
if (brdp->brdtype == BRD_ECHPCI) {
outb(nxtid, brdp->ioctrl);
ioaddr = brdp->ioaddr2;
}
status = inb(ioaddr + ECH_PNLSTATUS);
if ((status & ECH_PNLIDMASK) != nxtid)
break;
panelp = kzalloc(sizeof(struct stlpanel), GFP_KERNEL);
if (!panelp) {
printk("STALLION: failed to allocate memory "
"(size=%Zd)\n", sizeof(struct stlpanel));
retval = -ENOMEM;
goto err_fr;
}
panelp->magic = STL_PANELMAGIC;
panelp->brdnr = brdp->brdnr;
panelp->panelnr = panelnr;
panelp->iobase = ioaddr;
panelp->pagenr = nxtid;
panelp->hwid = status;
brdp->bnk2panel[banknr] = panelp;
brdp->bnkpageaddr[banknr] = nxtid;
brdp->bnkstataddr[banknr++] = ioaddr + ECH_PNLSTATUS;
if (status & ECH_PNLXPID) {
panelp->uartp = &stl_sc26198uart;
panelp->isr = stl_sc26198intr;
if (status & ECH_PNL16PORT) {
panelp->nrports = 16;
brdp->bnk2panel[banknr] = panelp;
brdp->bnkpageaddr[banknr] = nxtid;
brdp->bnkstataddr[banknr++] = ioaddr + 4 +
ECH_PNLSTATUS;
} else
panelp->nrports = 8;
} else {
panelp->uartp = &stl_cd1400uart;
panelp->isr = stl_cd1400echintr;
if (status & ECH_PNL16PORT) {
panelp->nrports = 16;
panelp->ackmask = 0x80;
if (brdp->brdtype != BRD_ECHPCI)
ioaddr += EREG_BANKSIZE;
brdp->bnk2panel[banknr] = panelp;
brdp->bnkpageaddr[banknr] = ++nxtid;
brdp->bnkstataddr[banknr++] = ioaddr +
ECH_PNLSTATUS;
} else {
panelp->nrports = 8;
panelp->ackmask = 0xc0;
}
}
nxtid++;
ioaddr += EREG_BANKSIZE;
brdp->nrports += panelp->nrports;
brdp->panels[panelnr++] = panelp;
if ((brdp->brdtype != BRD_ECHPCI) &&
(ioaddr >= (brdp->ioaddr2 + brdp->iosize2))) {
retval = -EINVAL;
goto err_fr;
}
}
brdp->nrpanels = panelnr;
brdp->nrbnks = banknr;
if (brdp->brdtype == BRD_ECH)
outb((brdp->ioctrlval | ECH_BRDDISABLE), brdp->ioctrl);
brdp->state |= BRD_FOUND;
if (request_irq(brdp->irq, stl_intr, IRQF_SHARED, name, brdp) != 0) {
printk("STALLION: failed to register interrupt "
"routine for %s irq=%d\n", name, brdp->irq);
retval = -ENODEV;
goto err_fr;
}
return 0;
err_fr:
stl_cleanup_panels(brdp);
if (brdp->iosize2 > 0)
release_region(brdp->ioaddr2, brdp->iosize2);
err_rel1:
release_region(brdp->ioaddr1, brdp->iosize1);
err:
return retval;
}
static int __devinit stl_brdinit(struct stlbrd *brdp)
{
int i, retval;
pr_debug("stl_brdinit(brdp=%p)\n", brdp);
switch (brdp->brdtype) {
case BRD_EASYIO:
case BRD_EASYIOPCI:
retval = stl_initeio(brdp);
if (retval)
goto err;
break;
case BRD_ECH:
case BRD_ECHMC:
case BRD_ECHPCI:
case BRD_ECH64PCI:
retval = stl_initech(brdp);
if (retval)
goto err;
break;
default:
printk("STALLION: board=%d is unknown board type=%d\n",
brdp->brdnr, brdp->brdtype);
retval = -ENODEV;
goto err;
}
if ((brdp->state & BRD_FOUND) == 0) {
printk("STALLION: %s board not found, board=%d io=%x irq=%d\n",
stl_brdnames[brdp->brdtype], brdp->brdnr,
brdp->ioaddr1, brdp->irq);
goto err_free;
}
for (i = 0; i < STL_MAXPANELS; i++)
if (brdp->panels[i] != NULL)
stl_initports(brdp, brdp->panels[i]);
printk("STALLION: %s found, board=%d io=%x irq=%d "
"nrpanels=%d nrports=%d\n", stl_brdnames[brdp->brdtype],
brdp->brdnr, brdp->ioaddr1, brdp->irq, brdp->nrpanels,
brdp->nrports);
return 0;
err_free:
free_irq(brdp->irq, brdp);
stl_cleanup_panels(brdp);
release_region(brdp->ioaddr1, brdp->iosize1);
if (brdp->iosize2 > 0)
release_region(brdp->ioaddr2, brdp->iosize2);
err:
return retval;
}
static int __devinit stl_getbrdnr(void)
{
unsigned int i;
for (i = 0; i < STL_MAXBRDS; i++)
if (stl_brds[i] == NULL) {
if (i >= stl_nrbrds)
stl_nrbrds = i + 1;
return i;
}
return -1;
}
static int __devinit stl_pciprobe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct stlbrd *brdp;
unsigned int i, brdtype = ent->driver_data;
int brdnr, retval = -ENODEV;
if ((pdev->class >> 8) == PCI_CLASS_STORAGE_IDE)
goto err;
retval = pci_enable_device(pdev);
if (retval)
goto err;
brdp = stl_allocbrd();
if (brdp == NULL) {
retval = -ENOMEM;
goto err;
}
mutex_lock(&stl_brdslock);
brdnr = stl_getbrdnr();
if (brdnr < 0) {
dev_err(&pdev->dev, "too many boards found, "
"maximum supported %d\n", STL_MAXBRDS);
mutex_unlock(&stl_brdslock);
retval = -ENODEV;
goto err_fr;
}
brdp->brdnr = (unsigned int)brdnr;
stl_brds[brdp->brdnr] = brdp;
mutex_unlock(&stl_brdslock);
brdp->brdtype = brdtype;
brdp->state |= STL_PROBED;
switch (brdtype) {
case BRD_ECHPCI:
brdp->ioaddr2 = pci_resource_start(pdev, 0);
brdp->ioaddr1 = pci_resource_start(pdev, 1);
break;
case BRD_ECH64PCI:
brdp->ioaddr2 = pci_resource_start(pdev, 2);
brdp->ioaddr1 = pci_resource_start(pdev, 1);
break;
case BRD_EASYIOPCI:
brdp->ioaddr1 = pci_resource_start(pdev, 2);
brdp->ioaddr2 = pci_resource_start(pdev, 1);
break;
default:
dev_err(&pdev->dev, "unknown PCI board type=%u\n", brdtype);
break;
}
brdp->irq = pdev->irq;
retval = stl_brdinit(brdp);
if (retval)
goto err_null;
pci_set_drvdata(pdev, brdp);
for (i = 0; i < brdp->nrports; i++)
tty_register_device(stl_serial,
brdp->brdnr * STL_MAXPORTS + i, &pdev->dev);
return 0;
err_null:
stl_brds[brdp->brdnr] = NULL;
err_fr:
kfree(brdp);
err:
return retval;
}
static void __devexit stl_pciremove(struct pci_dev *pdev)
{
struct stlbrd *brdp = pci_get_drvdata(pdev);
unsigned int i;
free_irq(brdp->irq, brdp);
stl_cleanup_panels(brdp);
release_region(brdp->ioaddr1, brdp->iosize1);
if (brdp->iosize2 > 0)
release_region(brdp->ioaddr2, brdp->iosize2);
for (i = 0; i < brdp->nrports; i++)
tty_unregister_device(stl_serial,
brdp->brdnr * STL_MAXPORTS + i);
stl_brds[brdp->brdnr] = NULL;
kfree(brdp);
}
static int stl_getbrdstats(combrd_t __user *bp)
{
combrd_t stl_brdstats;
struct stlbrd *brdp;
struct stlpanel *panelp;
unsigned int i;
if (copy_from_user(&stl_brdstats, bp, sizeof(combrd_t)))
return -EFAULT;
if (stl_brdstats.brd >= STL_MAXBRDS)
return -ENODEV;
brdp = stl_brds[stl_brdstats.brd];
if (brdp == NULL)
return -ENODEV;
memset(&stl_brdstats, 0, sizeof(combrd_t));
stl_brdstats.brd = brdp->brdnr;
stl_brdstats.type = brdp->brdtype;
stl_brdstats.hwid = brdp->hwid;
stl_brdstats.state = brdp->state;
stl_brdstats.ioaddr = brdp->ioaddr1;
stl_brdstats.ioaddr2 = brdp->ioaddr2;
stl_brdstats.irq = brdp->irq;
stl_brdstats.nrpanels = brdp->nrpanels;
stl_brdstats.nrports = brdp->nrports;
for (i = 0; i < brdp->nrpanels; i++) {
panelp = brdp->panels[i];
stl_brdstats.panels[i].panel = i;
stl_brdstats.panels[i].hwid = panelp->hwid;
stl_brdstats.panels[i].nrports = panelp->nrports;
}
return copy_to_user(bp, &stl_brdstats, sizeof(combrd_t)) ? -EFAULT : 0;
}
static struct stlport *stl_getport(int brdnr, int panelnr, int portnr)
{
struct stlbrd *brdp;
struct stlpanel *panelp;
if (brdnr < 0 || brdnr >= STL_MAXBRDS)
return NULL;
brdp = stl_brds[brdnr];
if (brdp == NULL)
return NULL;
if (panelnr < 0 || (unsigned int)panelnr >= brdp->nrpanels)
return NULL;
panelp = brdp->panels[panelnr];
if (panelp == NULL)
return NULL;
if (portnr < 0 || (unsigned int)portnr >= panelp->nrports)
return NULL;
return panelp->ports[portnr];
}
static int stl_getportstats(struct tty_struct *tty, struct stlport *portp, comstats_t __user *cp)
{
comstats_t stl_comstats;
unsigned char *head, *tail;
unsigned long flags;
if (!portp) {
if (copy_from_user(&stl_comstats, cp, sizeof(comstats_t)))
return -EFAULT;
portp = stl_getport(stl_comstats.brd, stl_comstats.panel,
stl_comstats.port);
if (portp == NULL)
return -ENODEV;
}
mutex_lock(&portp->port.mutex);
portp->stats.state = portp->istate;
portp->stats.flags = portp->port.flags;
portp->stats.hwid = portp->hwid;
portp->stats.ttystate = 0;
portp->stats.cflags = 0;
portp->stats.iflags = 0;
portp->stats.oflags = 0;
portp->stats.lflags = 0;
portp->stats.rxbuffered = 0;
spin_lock_irqsave(&stallion_lock, flags);
if (tty != NULL && portp->port.tty == tty) {
portp->stats.ttystate = tty->flags;
portp->stats.rxbuffered = 1;
if (tty->termios != NULL) {
portp->stats.cflags = tty->termios->c_cflag;
portp->stats.iflags = tty->termios->c_iflag;
portp->stats.oflags = tty->termios->c_oflag;
portp->stats.lflags = tty->termios->c_lflag;
}
}
spin_unlock_irqrestore(&stallion_lock, flags);
head = portp->tx.head;
tail = portp->tx.tail;
portp->stats.txbuffered = (head >= tail) ? (head - tail) :
(STL_TXBUFSIZE - (tail - head));
portp->stats.signals = (unsigned long) stl_getsignals(portp);
mutex_unlock(&portp->port.mutex);
return copy_to_user(cp, &portp->stats,
sizeof(comstats_t)) ? -EFAULT : 0;
}
static int stl_clrportstats(struct stlport *portp, comstats_t __user *cp)
{
comstats_t stl_comstats;
if (!portp) {
if (copy_from_user(&stl_comstats, cp, sizeof(comstats_t)))
return -EFAULT;
portp = stl_getport(stl_comstats.brd, stl_comstats.panel,
stl_comstats.port);
if (portp == NULL)
return -ENODEV;
}
mutex_lock(&portp->port.mutex);
memset(&portp->stats, 0, sizeof(comstats_t));
portp->stats.brd = portp->brdnr;
portp->stats.panel = portp->panelnr;
portp->stats.port = portp->portnr;
mutex_unlock(&portp->port.mutex);
return copy_to_user(cp, &portp->stats,
sizeof(comstats_t)) ? -EFAULT : 0;
}
static int stl_getportstruct(struct stlport __user *arg)
{
struct stlport stl_dummyport;
struct stlport *portp;
if (copy_from_user(&stl_dummyport, arg, sizeof(struct stlport)))
return -EFAULT;
portp = stl_getport(stl_dummyport.brdnr, stl_dummyport.panelnr,
stl_dummyport.portnr);
if (!portp)
return -ENODEV;
return copy_to_user(arg, portp, sizeof(struct stlport)) ? -EFAULT : 0;
}
static int stl_getbrdstruct(struct stlbrd __user *arg)
{
struct stlbrd stl_dummybrd;
struct stlbrd *brdp;
if (copy_from_user(&stl_dummybrd, arg, sizeof(struct stlbrd)))
return -EFAULT;
if (stl_dummybrd.brdnr >= STL_MAXBRDS)
return -ENODEV;
brdp = stl_brds[stl_dummybrd.brdnr];
if (!brdp)
return -ENODEV;
return copy_to_user(arg, brdp, sizeof(struct stlbrd)) ? -EFAULT : 0;
}
static long stl_memioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
int brdnr, rc;
void __user *argp = (void __user *)arg;
pr_debug("stl_memioctl(fp=%p,cmd=%x,arg=%lx)\n", fp, cmd,arg);
brdnr = iminor(fp->f_dentry->d_inode);
if (brdnr >= STL_MAXBRDS)
return -ENODEV;
rc = 0;
switch (cmd) {
case COM_GETPORTSTATS:
rc = stl_getportstats(NULL, NULL, argp);
break;
case COM_CLRPORTSTATS:
rc = stl_clrportstats(NULL, argp);
break;
case COM_GETBRDSTATS:
rc = stl_getbrdstats(argp);
break;
case COM_READPORT:
rc = stl_getportstruct(argp);
break;
case COM_READBOARD:
rc = stl_getbrdstruct(argp);
break;
default:
rc = -ENOIOCTLCMD;
break;
}
return rc;
}
static int stl_cd1400getreg(struct stlport *portp, int regnr)
{
outb((regnr + portp->uartaddr), portp->ioaddr);
return inb(portp->ioaddr + EREG_DATA);
}
static void stl_cd1400setreg(struct stlport *portp, int regnr, int value)
{
outb(regnr + portp->uartaddr, portp->ioaddr);
outb(value, portp->ioaddr + EREG_DATA);
}
static int stl_cd1400updatereg(struct stlport *portp, int regnr, int value)
{
outb(regnr + portp->uartaddr, portp->ioaddr);
if (inb(portp->ioaddr + EREG_DATA) != value) {
outb(value, portp->ioaddr + EREG_DATA);
return 1;
}
return 0;
}
static int stl_cd1400panelinit(struct stlbrd *brdp, struct stlpanel *panelp)
{
unsigned int gfrcr;
int chipmask, i, j;
int nrchips, uartaddr, ioaddr;
unsigned long flags;
pr_debug("stl_panelinit(brdp=%p,panelp=%p)\n", brdp, panelp);
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(panelp->brdnr, panelp->pagenr);
chipmask = 0;
nrchips = panelp->nrports / CD1400_PORTS;
for (i = 0; i < nrchips; i++) {
if (brdp->brdtype == BRD_ECHPCI) {
outb((panelp->pagenr + (i >> 1)), brdp->ioctrl);
ioaddr = panelp->iobase;
} else
ioaddr = panelp->iobase + (EREG_BANKSIZE * (i >> 1));
uartaddr = (i & 0x01) ? 0x080 : 0;
outb((GFRCR + uartaddr), ioaddr);
outb(0, (ioaddr + EREG_DATA));
outb((CCR + uartaddr), ioaddr);
outb(CCR_RESETFULL, (ioaddr + EREG_DATA));
outb(CCR_RESETFULL, (ioaddr + EREG_DATA));
outb((GFRCR + uartaddr), ioaddr);
for (j = 0; j < CCR_MAXWAIT; j++)
if ((gfrcr = inb(ioaddr + EREG_DATA)) != 0)
break;
if ((j >= CCR_MAXWAIT) || (gfrcr < 0x40) || (gfrcr > 0x60)) {
printk("STALLION: cd1400 not responding, "
"brd=%d panel=%d chip=%d\n",
panelp->brdnr, panelp->panelnr, i);
continue;
}
chipmask |= (0x1 << i);
outb((PPR + uartaddr), ioaddr);
outb(PPR_SCALAR, (ioaddr + EREG_DATA));
}
BRDDISABLE(panelp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
return chipmask;
}
static void stl_cd1400portinit(struct stlbrd *brdp, struct stlpanel *panelp, struct stlport *portp)
{
unsigned long flags;
pr_debug("stl_cd1400portinit(brdp=%p,panelp=%p,portp=%p)\n", brdp,
panelp, portp);
if ((brdp == NULL) || (panelp == NULL) ||
(portp == NULL))
return;
spin_lock_irqsave(&brd_lock, flags);
portp->ioaddr = panelp->iobase + (((brdp->brdtype == BRD_ECHPCI) ||
(portp->portnr < 8)) ? 0 : EREG_BANKSIZE);
portp->uartaddr = (portp->portnr & 0x04) << 5;
portp->pagenr = panelp->pagenr + (portp->portnr >> 3);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
stl_cd1400setreg(portp, LIVR, (portp->portnr << 3));
portp->hwid = stl_cd1400getreg(portp, GFRCR);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_cd1400ccrwait(struct stlport *portp)
{
int i;
for (i = 0; i < CCR_MAXWAIT; i++)
if (stl_cd1400getreg(portp, CCR) == 0)
return;
printk("STALLION: cd1400 not responding, port=%d panel=%d brd=%d\n",
portp->portnr, portp->panelnr, portp->brdnr);
}
static void stl_cd1400setport(struct stlport *portp, struct ktermios *tiosp)
{
struct stlbrd *brdp;
unsigned long flags;
unsigned int clkdiv, baudrate;
unsigned char cor1, cor2, cor3;
unsigned char cor4, cor5, ccr;
unsigned char srer, sreron, sreroff;
unsigned char mcor1, mcor2, rtpr;
unsigned char clk, div;
cor1 = 0;
cor2 = 0;
cor3 = 0;
cor4 = 0;
cor5 = 0;
ccr = 0;
rtpr = 0;
clk = 0;
div = 0;
mcor1 = 0;
mcor2 = 0;
sreron = 0;
sreroff = 0;
brdp = stl_brds[portp->brdnr];
if (brdp == NULL)
return;
portp->rxignoremsk = 0;
if (tiosp->c_iflag & IGNPAR) {
portp->rxignoremsk |= (ST_PARITY | ST_FRAMING | ST_OVERRUN);
cor1 |= COR1_PARIGNORE;
}
if (tiosp->c_iflag & IGNBRK) {
portp->rxignoremsk |= ST_BREAK;
cor4 |= COR4_IGNBRK;
}
portp->rxmarkmsk = ST_OVERRUN;
if (tiosp->c_iflag & (INPCK | PARMRK))
portp->rxmarkmsk |= (ST_PARITY | ST_FRAMING);
if (tiosp->c_iflag & BRKINT)
portp->rxmarkmsk |= ST_BREAK;
switch (tiosp->c_cflag & CSIZE) {
case CS5:
cor1 |= COR1_CHL5;
break;
case CS6:
cor1 |= COR1_CHL6;
break;
case CS7:
cor1 |= COR1_CHL7;
break;
default:
cor1 |= COR1_CHL8;
break;
}
if (tiosp->c_cflag & CSTOPB)
cor1 |= COR1_STOP2;
else
cor1 |= COR1_STOP1;
if (tiosp->c_cflag & PARENB) {
if (tiosp->c_cflag & PARODD)
cor1 |= (COR1_PARENB | COR1_PARODD);
else
cor1 |= (COR1_PARENB | COR1_PAREVEN);
} else {
cor1 |= COR1_PARNONE;
}
cor3 |= FIFO_RXTHRESHOLD;
rtpr = 2;
baudrate = tiosp->c_cflag & CBAUD;
if (baudrate & CBAUDEX) {
baudrate &= ~CBAUDEX;
if ((baudrate < 1) || (baudrate > 4))
tiosp->c_cflag &= ~CBAUDEX;
else
baudrate += 15;
}
baudrate = stl_baudrates[baudrate];
if ((tiosp->c_cflag & CBAUD) == B38400) {
if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
baudrate = 57600;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
baudrate = 115200;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
baudrate = 230400;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
baudrate = 460800;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_CUST)
baudrate = (portp->baud_base / portp->custom_divisor);
}
if (baudrate > STL_CD1400MAXBAUD)
baudrate = STL_CD1400MAXBAUD;
if (baudrate > 0) {
for (clk = 0; clk < CD1400_NUMCLKS; clk++) {
clkdiv = (portp->clk / stl_cd1400clkdivs[clk]) / baudrate;
if (clkdiv < 0x100)
break;
}
div = (unsigned char) clkdiv;
}
if ((tiosp->c_cflag & CLOCAL) == 0) {
mcor1 |= MCOR1_DCD;
mcor2 |= MCOR2_DCD;
sreron |= SRER_MODEM;
portp->port.flags |= ASYNC_CHECK_CD;
} else
portp->port.flags &= ~ASYNC_CHECK_CD;
if (tiosp->c_iflag & IXON) {
cor2 |= COR2_TXIBE;
cor3 |= COR3_SCD12;
if (tiosp->c_iflag & IXANY)
cor2 |= COR2_IXM;
}
if (tiosp->c_cflag & CRTSCTS) {
cor2 |= COR2_CTSAE;
mcor1 |= FIFO_RTSTHRESHOLD;
}
pr_debug("SETPORT: portnr=%d panelnr=%d brdnr=%d\n",
portp->portnr, portp->panelnr, portp->brdnr);
pr_debug(" cor1=%x cor2=%x cor3=%x cor4=%x cor5=%x\n",
cor1, cor2, cor3, cor4, cor5);
pr_debug(" mcor1=%x mcor2=%x rtpr=%x sreron=%x sreroff=%x\n",
mcor1, mcor2, rtpr, sreron, sreroff);
pr_debug(" tcor=%x tbpr=%x rcor=%x rbpr=%x\n", clk, div, clk, div);
pr_debug(" schr1=%x schr2=%x schr3=%x schr4=%x\n",
tiosp->c_cc[VSTART], tiosp->c_cc[VSTOP],
tiosp->c_cc[VSTART], tiosp->c_cc[VSTOP]);
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x3));
srer = stl_cd1400getreg(portp, SRER);
stl_cd1400setreg(portp, SRER, 0);
if (stl_cd1400updatereg(portp, COR1, cor1))
ccr = 1;
if (stl_cd1400updatereg(portp, COR2, cor2))
ccr = 1;
if (stl_cd1400updatereg(portp, COR3, cor3))
ccr = 1;
if (ccr) {
stl_cd1400ccrwait(portp);
stl_cd1400setreg(portp, CCR, CCR_CORCHANGE);
}
stl_cd1400setreg(portp, COR4, cor4);
stl_cd1400setreg(portp, COR5, cor5);
stl_cd1400setreg(portp, MCOR1, mcor1);
stl_cd1400setreg(portp, MCOR2, mcor2);
if (baudrate > 0) {
stl_cd1400setreg(portp, TCOR, clk);
stl_cd1400setreg(portp, TBPR, div);
stl_cd1400setreg(portp, RCOR, clk);
stl_cd1400setreg(portp, RBPR, div);
}
stl_cd1400setreg(portp, SCHR1, tiosp->c_cc[VSTART]);
stl_cd1400setreg(portp, SCHR2, tiosp->c_cc[VSTOP]);
stl_cd1400setreg(portp, SCHR3, tiosp->c_cc[VSTART]);
stl_cd1400setreg(portp, SCHR4, tiosp->c_cc[VSTOP]);
stl_cd1400setreg(portp, RTPR, rtpr);
mcor1 = stl_cd1400getreg(portp, MSVR1);
if (mcor1 & MSVR1_DCD)
portp->sigs |= TIOCM_CD;
else
portp->sigs &= ~TIOCM_CD;
stl_cd1400setreg(portp, SRER, ((srer & ~sreroff) | sreron));
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_cd1400setsignals(struct stlport *portp, int dtr, int rts)
{
unsigned char msvr1, msvr2;
unsigned long flags;
pr_debug("stl_cd1400setsignals(portp=%p,dtr=%d,rts=%d)\n",
portp, dtr, rts);
msvr1 = 0;
msvr2 = 0;
if (dtr > 0)
msvr1 = MSVR1_DTR;
if (rts > 0)
msvr2 = MSVR2_RTS;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
if (rts >= 0)
stl_cd1400setreg(portp, MSVR2, msvr2);
if (dtr >= 0)
stl_cd1400setreg(portp, MSVR1, msvr1);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static int stl_cd1400getsignals(struct stlport *portp)
{
unsigned char msvr1, msvr2;
unsigned long flags;
int sigs;
pr_debug("stl_cd1400getsignals(portp=%p)\n", portp);
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
msvr1 = stl_cd1400getreg(portp, MSVR1);
msvr2 = stl_cd1400getreg(portp, MSVR2);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
sigs = 0;
sigs |= (msvr1 & MSVR1_DCD) ? TIOCM_CD : 0;
sigs |= (msvr1 & MSVR1_CTS) ? TIOCM_CTS : 0;
sigs |= (msvr1 & MSVR1_DTR) ? TIOCM_DTR : 0;
sigs |= (msvr2 & MSVR2_RTS) ? TIOCM_RTS : 0;
#if 0
sigs |= (msvr1 & MSVR1_RI) ? TIOCM_RI : 0;
sigs |= (msvr1 & MSVR1_DSR) ? TIOCM_DSR : 0;
#else
sigs |= TIOCM_DSR;
#endif
return sigs;
}
static void stl_cd1400enablerxtx(struct stlport *portp, int rx, int tx)
{
unsigned char ccr;
unsigned long flags;
pr_debug("stl_cd1400enablerxtx(portp=%p,rx=%d,tx=%d)\n", portp, rx, tx);
ccr = 0;
if (tx == 0)
ccr |= CCR_TXDISABLE;
else if (tx > 0)
ccr |= CCR_TXENABLE;
if (rx == 0)
ccr |= CCR_RXDISABLE;
else if (rx > 0)
ccr |= CCR_RXENABLE;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
stl_cd1400ccrwait(portp);
stl_cd1400setreg(portp, CCR, ccr);
stl_cd1400ccrwait(portp);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_cd1400startrxtx(struct stlport *portp, int rx, int tx)
{
unsigned char sreron, sreroff;
unsigned long flags;
pr_debug("stl_cd1400startrxtx(portp=%p,rx=%d,tx=%d)\n", portp, rx, tx);
sreron = 0;
sreroff = 0;
if (tx == 0)
sreroff |= (SRER_TXDATA | SRER_TXEMPTY);
else if (tx == 1)
sreron |= SRER_TXDATA;
else if (tx >= 2)
sreron |= SRER_TXEMPTY;
if (rx == 0)
sreroff |= SRER_RXDATA;
else if (rx > 0)
sreron |= SRER_RXDATA;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
stl_cd1400setreg(portp, SRER,
((stl_cd1400getreg(portp, SRER) & ~sreroff) | sreron));
BRDDISABLE(portp->brdnr);
if (tx > 0)
set_bit(ASYI_TXBUSY, &portp->istate);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_cd1400disableintrs(struct stlport *portp)
{
unsigned long flags;
pr_debug("stl_cd1400disableintrs(portp=%p)\n", portp);
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
stl_cd1400setreg(portp, SRER, 0);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_cd1400sendbreak(struct stlport *portp, int len)
{
unsigned long flags;
pr_debug("stl_cd1400sendbreak(portp=%p,len=%d)\n", portp, len);
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
stl_cd1400setreg(portp, SRER,
((stl_cd1400getreg(portp, SRER) & ~SRER_TXDATA) |
SRER_TXEMPTY));
BRDDISABLE(portp->brdnr);
portp->brklen = len;
if (len == 1)
portp->stats.txbreaks++;
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_cd1400flowctrl(struct stlport *portp, int state)
{
struct tty_struct *tty;
unsigned long flags;
pr_debug("stl_cd1400flowctrl(portp=%p,state=%x)\n", portp, state);
if (portp == NULL)
return;
tty = tty_port_tty_get(&portp->port);
if (tty == NULL)
return;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
if (state) {
if (tty->termios->c_iflag & IXOFF) {
stl_cd1400ccrwait(portp);
stl_cd1400setreg(portp, CCR, CCR_SENDSCHR1);
portp->stats.rxxon++;
stl_cd1400ccrwait(portp);
}
if (tty->termios->c_cflag & CRTSCTS) {
stl_cd1400setreg(portp, MCOR1,
(stl_cd1400getreg(portp, MCOR1) |
FIFO_RTSTHRESHOLD));
stl_cd1400setreg(portp, MSVR2, MSVR2_RTS);
portp->stats.rxrtson++;
}
} else {
if (tty->termios->c_iflag & IXOFF) {
stl_cd1400ccrwait(portp);
stl_cd1400setreg(portp, CCR, CCR_SENDSCHR2);
portp->stats.rxxoff++;
stl_cd1400ccrwait(portp);
}
if (tty->termios->c_cflag & CRTSCTS) {
stl_cd1400setreg(portp, MCOR1,
(stl_cd1400getreg(portp, MCOR1) & 0xf0));
stl_cd1400setreg(portp, MSVR2, 0);
portp->stats.rxrtsoff++;
}
}
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
tty_kref_put(tty);
}
static void stl_cd1400sendflow(struct stlport *portp, int state)
{
struct tty_struct *tty;
unsigned long flags;
pr_debug("stl_cd1400sendflow(portp=%p,state=%x)\n", portp, state);
if (portp == NULL)
return;
tty = tty_port_tty_get(&portp->port);
if (tty == NULL)
return;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
if (state) {
stl_cd1400ccrwait(portp);
stl_cd1400setreg(portp, CCR, CCR_SENDSCHR1);
portp->stats.rxxon++;
stl_cd1400ccrwait(portp);
} else {
stl_cd1400ccrwait(portp);
stl_cd1400setreg(portp, CCR, CCR_SENDSCHR2);
portp->stats.rxxoff++;
stl_cd1400ccrwait(portp);
}
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
tty_kref_put(tty);
}
static void stl_cd1400flush(struct stlport *portp)
{
unsigned long flags;
pr_debug("stl_cd1400flush(portp=%p)\n", portp);
if (portp == NULL)
return;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_cd1400setreg(portp, CAR, (portp->portnr & 0x03));
stl_cd1400ccrwait(portp);
stl_cd1400setreg(portp, CCR, CCR_TXFLUSHFIFO);
stl_cd1400ccrwait(portp);
portp->tx.tail = portp->tx.head;
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static int stl_cd1400datastate(struct stlport *portp)
{
pr_debug("stl_cd1400datastate(portp=%p)\n", portp);
if (portp == NULL)
return 0;
return test_bit(ASYI_TXBUSY, &portp->istate) ? 1 : 0;
}
static void stl_cd1400eiointr(struct stlpanel *panelp, unsigned int iobase)
{
unsigned char svrtype;
pr_debug("stl_cd1400eiointr(panelp=%p,iobase=%x)\n", panelp, iobase);
spin_lock(&brd_lock);
outb(SVRR, iobase);
svrtype = inb(iobase + EREG_DATA);
if (panelp->nrports > 4) {
outb((SVRR + 0x80), iobase);
svrtype |= inb(iobase + EREG_DATA);
}
if (svrtype & SVRR_RX)
stl_cd1400rxisr(panelp, iobase);
else if (svrtype & SVRR_TX)
stl_cd1400txisr(panelp, iobase);
else if (svrtype & SVRR_MDM)
stl_cd1400mdmisr(panelp, iobase);
spin_unlock(&brd_lock);
}
static void stl_cd1400echintr(struct stlpanel *panelp, unsigned int iobase)
{
unsigned char svrtype;
pr_debug("stl_cd1400echintr(panelp=%p,iobase=%x)\n", panelp, iobase);
outb(SVRR, iobase);
svrtype = inb(iobase + EREG_DATA);
outb((SVRR + 0x80), iobase);
svrtype |= inb(iobase + EREG_DATA);
if (svrtype & SVRR_RX)
stl_cd1400rxisr(panelp, iobase);
else if (svrtype & SVRR_TX)
stl_cd1400txisr(panelp, iobase);
else if (svrtype & SVRR_MDM)
stl_cd1400mdmisr(panelp, iobase);
}
static int stl_cd1400breakisr(struct stlport *portp, int ioaddr)
{
if (portp->brklen == 1) {
outb((COR2 + portp->uartaddr), ioaddr);
outb((inb(ioaddr + EREG_DATA) | COR2_ETC),
(ioaddr + EREG_DATA));
outb((TDR + portp->uartaddr), ioaddr);
outb(ETC_CMD, (ioaddr + EREG_DATA));
outb(ETC_STARTBREAK, (ioaddr + EREG_DATA));
outb((SRER + portp->uartaddr), ioaddr);
outb((inb(ioaddr + EREG_DATA) & ~(SRER_TXDATA | SRER_TXEMPTY)),
(ioaddr + EREG_DATA));
return 1;
} else if (portp->brklen > 1) {
outb((TDR + portp->uartaddr), ioaddr);
outb(ETC_CMD, (ioaddr + EREG_DATA));
outb(ETC_STOPBREAK, (ioaddr + EREG_DATA));
portp->brklen = -1;
return 1;
} else {
outb((COR2 + portp->uartaddr), ioaddr);
outb((inb(ioaddr + EREG_DATA) & ~COR2_ETC),
(ioaddr + EREG_DATA));
portp->brklen = 0;
}
return 0;
}
static void stl_cd1400txisr(struct stlpanel *panelp, int ioaddr)
{
struct stlport *portp;
int len, stlen;
char *head, *tail;
unsigned char ioack, srer;
struct tty_struct *tty;
pr_debug("stl_cd1400txisr(panelp=%p,ioaddr=%x)\n", panelp, ioaddr);
ioack = inb(ioaddr + EREG_TXACK);
if (((ioack & panelp->ackmask) != 0) ||
((ioack & ACK_TYPMASK) != ACK_TYPTX)) {
printk("STALLION: bad TX interrupt ack value=%x\n", ioack);
return;
}
portp = panelp->ports[(ioack >> 3)];
if (portp->brklen != 0)
if (stl_cd1400breakisr(portp, ioaddr))
goto stl_txalldone;
head = portp->tx.head;
tail = portp->tx.tail;
len = (head >= tail) ? (head - tail) : (STL_TXBUFSIZE - (tail - head));
if ((len == 0) || ((len < STL_TXBUFLOW) &&
(test_bit(ASYI_TXLOW, &portp->istate) == 0))) {
set_bit(ASYI_TXLOW, &portp->istate);
tty = tty_port_tty_get(&portp->port);
if (tty) {
tty_wakeup(tty);
tty_kref_put(tty);
}
}
if (len == 0) {
outb((SRER + portp->uartaddr), ioaddr);
srer = inb(ioaddr + EREG_DATA);
if (srer & SRER_TXDATA) {
srer = (srer & ~SRER_TXDATA) | SRER_TXEMPTY;
} else {
srer &= ~(SRER_TXDATA | SRER_TXEMPTY);
clear_bit(ASYI_TXBUSY, &portp->istate);
}
outb(srer, (ioaddr + EREG_DATA));
} else {
len = min(len, CD1400_TXFIFOSIZE);
portp->stats.txtotal += len;
stlen = min_t(unsigned int, len,
(portp->tx.buf + STL_TXBUFSIZE) - tail);
outb((TDR + portp->uartaddr), ioaddr);
outsb((ioaddr + EREG_DATA), tail, stlen);
len -= stlen;
tail += stlen;
if (tail >= (portp->tx.buf + STL_TXBUFSIZE))
tail = portp->tx.buf;
if (len > 0) {
outsb((ioaddr + EREG_DATA), tail, len);
tail += len;
}
portp->tx.tail = tail;
}
stl_txalldone:
outb((EOSRR + portp->uartaddr), ioaddr);
outb(0, (ioaddr + EREG_DATA));
}
static void stl_cd1400rxisr(struct stlpanel *panelp, int ioaddr)
{
struct stlport *portp;
struct tty_struct *tty;
unsigned int ioack, len, buflen;
unsigned char status;
char ch;
pr_debug("stl_cd1400rxisr(panelp=%p,ioaddr=%x)\n", panelp, ioaddr);
ioack = inb(ioaddr + EREG_RXACK);
if ((ioack & panelp->ackmask) != 0) {
printk("STALLION: bad RX interrupt ack value=%x\n", ioack);
return;
}
portp = panelp->ports[(ioack >> 3)];
tty = tty_port_tty_get(&portp->port);
if ((ioack & ACK_TYPMASK) == ACK_TYPRXGOOD) {
outb((RDCR + portp->uartaddr), ioaddr);
len = inb(ioaddr + EREG_DATA);
if (tty == NULL || (buflen = tty_buffer_request_room(tty, len)) == 0) {
len = min_t(unsigned int, len, sizeof(stl_unwanted));
outb((RDSR + portp->uartaddr), ioaddr);
insb((ioaddr + EREG_DATA), &stl_unwanted[0], len);
portp->stats.rxlost += len;
portp->stats.rxtotal += len;
} else {
len = min(len, buflen);
if (len > 0) {
unsigned char *ptr;
outb((RDSR + portp->uartaddr), ioaddr);
tty_prepare_flip_string(tty, &ptr, len);
insb((ioaddr + EREG_DATA), ptr, len);
tty_schedule_flip(tty);
portp->stats.rxtotal += len;
}
}
} else if ((ioack & ACK_TYPMASK) == ACK_TYPRXBAD) {
outb((RDSR + portp->uartaddr), ioaddr);
status = inb(ioaddr + EREG_DATA);
ch = inb(ioaddr + EREG_DATA);
if (status & ST_PARITY)
portp->stats.rxparity++;
if (status & ST_FRAMING)
portp->stats.rxframing++;
if (status & ST_OVERRUN)
portp->stats.rxoverrun++;
if (status & ST_BREAK)
portp->stats.rxbreaks++;
if (status & ST_SCHARMASK) {
if ((status & ST_SCHARMASK) == ST_SCHAR1)
portp->stats.txxon++;
if ((status & ST_SCHARMASK) == ST_SCHAR2)
portp->stats.txxoff++;
goto stl_rxalldone;
}
if (tty != NULL && (portp->rxignoremsk & status) == 0) {
if (portp->rxmarkmsk & status) {
if (status & ST_BREAK) {
status = TTY_BREAK;
if (portp->port.flags & ASYNC_SAK) {
do_SAK(tty);
BRDENABLE(portp->brdnr, portp->pagenr);
}
} else if (status & ST_PARITY)
status = TTY_PARITY;
else if (status & ST_FRAMING)
status = TTY_FRAME;
else if(status & ST_OVERRUN)
status = TTY_OVERRUN;
else
status = 0;
} else
status = 0;
tty_insert_flip_char(tty, ch, status);
tty_schedule_flip(tty);
}
} else {
printk("STALLION: bad RX interrupt ack value=%x\n", ioack);
tty_kref_put(tty);
return;
}
stl_rxalldone:
tty_kref_put(tty);
outb((EOSRR + portp->uartaddr), ioaddr);
outb(0, (ioaddr + EREG_DATA));
}
static void stl_cd1400mdmisr(struct stlpanel *panelp, int ioaddr)
{
struct stlport *portp;
unsigned int ioack;
unsigned char misr;
pr_debug("stl_cd1400mdmisr(panelp=%p)\n", panelp);
ioack = inb(ioaddr + EREG_MDACK);
if (((ioack & panelp->ackmask) != 0) ||
((ioack & ACK_TYPMASK) != ACK_TYPMDM)) {
printk("STALLION: bad MODEM interrupt ack value=%x\n", ioack);
return;
}
portp = panelp->ports[(ioack >> 3)];
outb((MISR + portp->uartaddr), ioaddr);
misr = inb(ioaddr + EREG_DATA);
if (misr & MISR_DCD) {
stl_cd_change(portp);
portp->stats.modem++;
}
outb((EOSRR + portp->uartaddr), ioaddr);
outb(0, (ioaddr + EREG_DATA));
}
static int stl_sc26198getreg(struct stlport *portp, int regnr)
{
outb((regnr | portp->uartaddr), (portp->ioaddr + XP_ADDR));
return inb(portp->ioaddr + XP_DATA);
}
static void stl_sc26198setreg(struct stlport *portp, int regnr, int value)
{
outb((regnr | portp->uartaddr), (portp->ioaddr + XP_ADDR));
outb(value, (portp->ioaddr + XP_DATA));
}
static int stl_sc26198updatereg(struct stlport *portp, int regnr, int value)
{
outb((regnr | portp->uartaddr), (portp->ioaddr + XP_ADDR));
if (inb(portp->ioaddr + XP_DATA) != value) {
outb(value, (portp->ioaddr + XP_DATA));
return 1;
}
return 0;
}
static int stl_sc26198getglobreg(struct stlport *portp, int regnr)
{
outb(regnr, (portp->ioaddr + XP_ADDR));
return inb(portp->ioaddr + XP_DATA);
}
static int stl_sc26198panelinit(struct stlbrd *brdp, struct stlpanel *panelp)
{
int chipmask, i;
int nrchips, ioaddr;
pr_debug("stl_sc26198panelinit(brdp=%p,panelp=%p)\n", brdp, panelp);
BRDENABLE(panelp->brdnr, panelp->pagenr);
chipmask = 0;
nrchips = (panelp->nrports + 4) / SC26198_PORTS;
if (brdp->brdtype == BRD_ECHPCI)
outb(panelp->pagenr, brdp->ioctrl);
for (i = 0; i < nrchips; i++) {
ioaddr = panelp->iobase + (i * 4);
outb(SCCR, (ioaddr + XP_ADDR));
outb(CR_RESETALL, (ioaddr + XP_DATA));
outb(TSTR, (ioaddr + XP_ADDR));
if (inb(ioaddr + XP_DATA) != 0) {
printk("STALLION: sc26198 not responding, "
"brd=%d panel=%d chip=%d\n",
panelp->brdnr, panelp->panelnr, i);
continue;
}
chipmask |= (0x1 << i);
outb(GCCR, (ioaddr + XP_ADDR));
outb(GCCR_IVRTYPCHANACK, (ioaddr + XP_DATA));
outb(WDTRCR, (ioaddr + XP_ADDR));
outb(0xff, (ioaddr + XP_DATA));
}
BRDDISABLE(panelp->brdnr);
return chipmask;
}
static void stl_sc26198portinit(struct stlbrd *brdp, struct stlpanel *panelp, struct stlport *portp)
{
pr_debug("stl_sc26198portinit(brdp=%p,panelp=%p,portp=%p)\n", brdp,
panelp, portp);
if ((brdp == NULL) || (panelp == NULL) ||
(portp == NULL))
return;
portp->ioaddr = panelp->iobase + ((portp->portnr < 8) ? 0 : 4);
portp->uartaddr = (portp->portnr & 0x07) << 4;
portp->pagenr = panelp->pagenr;
portp->hwid = 0x1;
BRDENABLE(portp->brdnr, portp->pagenr);
stl_sc26198setreg(portp, IOPCR, IOPCR_SETSIGS);
BRDDISABLE(portp->brdnr);
}
static void stl_sc26198setport(struct stlport *portp, struct ktermios *tiosp)
{
struct stlbrd *brdp;
unsigned long flags;
unsigned int baudrate;
unsigned char mr0, mr1, mr2, clk;
unsigned char imron, imroff, iopr, ipr;
mr0 = 0;
mr1 = 0;
mr2 = 0;
clk = 0;
iopr = 0;
imron = 0;
imroff = 0;
brdp = stl_brds[portp->brdnr];
if (brdp == NULL)
return;
portp->rxignoremsk = 0;
if (tiosp->c_iflag & IGNPAR)
portp->rxignoremsk |= (SR_RXPARITY | SR_RXFRAMING |
SR_RXOVERRUN);
if (tiosp->c_iflag & IGNBRK)
portp->rxignoremsk |= SR_RXBREAK;
portp->rxmarkmsk = SR_RXOVERRUN;
if (tiosp->c_iflag & (INPCK | PARMRK))
portp->rxmarkmsk |= (SR_RXPARITY | SR_RXFRAMING);
if (tiosp->c_iflag & BRKINT)
portp->rxmarkmsk |= SR_RXBREAK;
switch (tiosp->c_cflag & CSIZE) {
case CS5:
mr1 |= MR1_CS5;
break;
case CS6:
mr1 |= MR1_CS6;
break;
case CS7:
mr1 |= MR1_CS7;
break;
default:
mr1 |= MR1_CS8;
break;
}
if (tiosp->c_cflag & CSTOPB)
mr2 |= MR2_STOP2;
else
mr2 |= MR2_STOP1;
if (tiosp->c_cflag & PARENB) {
if (tiosp->c_cflag & PARODD)
mr1 |= (MR1_PARENB | MR1_PARODD);
else
mr1 |= (MR1_PARENB | MR1_PAREVEN);
} else
mr1 |= MR1_PARNONE;
mr1 |= MR1_ERRBLOCK;
mr2 |= MR2_RXFIFOHALF;
baudrate = tiosp->c_cflag & CBAUD;
if (baudrate & CBAUDEX) {
baudrate &= ~CBAUDEX;
if ((baudrate < 1) || (baudrate > 4))
tiosp->c_cflag &= ~CBAUDEX;
else
baudrate += 15;
}
baudrate = stl_baudrates[baudrate];
if ((tiosp->c_cflag & CBAUD) == B38400) {
if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_HI)
baudrate = 57600;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI)
baudrate = 115200;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_SHI)
baudrate = 230400;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_WARP)
baudrate = 460800;
else if ((portp->port.flags & ASYNC_SPD_MASK) == ASYNC_SPD_CUST)
baudrate = (portp->baud_base / portp->custom_divisor);
}
if (baudrate > STL_SC26198MAXBAUD)
baudrate = STL_SC26198MAXBAUD;
if (baudrate > 0)
for (clk = 0; clk < SC26198_NRBAUDS; clk++)
if (baudrate <= sc26198_baudtable[clk])
break;
if (tiosp->c_cflag & CLOCAL) {
portp->port.flags &= ~ASYNC_CHECK_CD;
} else {
iopr |= IOPR_DCDCOS;
imron |= IR_IOPORT;
portp->port.flags |= ASYNC_CHECK_CD;
}
if (tiosp->c_iflag & IXON) {
mr0 |= MR0_SWFTX | MR0_SWFT;
imron |= IR_XONXOFF;
} else
imroff |= IR_XONXOFF;
if (tiosp->c_iflag & IXOFF)
mr0 |= MR0_SWFRX;
if (tiosp->c_cflag & CRTSCTS) {
mr2 |= MR2_AUTOCTS;
mr1 |= MR1_AUTORTS;
}
pr_debug("SETPORT: portnr=%d panelnr=%d brdnr=%d\n",
portp->portnr, portp->panelnr, portp->brdnr);
pr_debug(" mr0=%x mr1=%x mr2=%x clk=%x\n", mr0, mr1, mr2, clk);
pr_debug(" iopr=%x imron=%x imroff=%x\n", iopr, imron, imroff);
pr_debug(" schr1=%x schr2=%x schr3=%x schr4=%x\n",
tiosp->c_cc[VSTART], tiosp->c_cc[VSTOP],
tiosp->c_cc[VSTART], tiosp->c_cc[VSTOP]);
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_sc26198setreg(portp, IMR, 0);
stl_sc26198updatereg(portp, MR0, mr0);
stl_sc26198updatereg(portp, MR1, mr1);
stl_sc26198setreg(portp, SCCR, CR_RXERRBLOCK);
stl_sc26198updatereg(portp, MR2, mr2);
stl_sc26198updatereg(portp, IOPIOR,
((stl_sc26198getreg(portp, IOPIOR) & ~IPR_CHANGEMASK) | iopr));
if (baudrate > 0) {
stl_sc26198setreg(portp, TXCSR, clk);
stl_sc26198setreg(portp, RXCSR, clk);
}
stl_sc26198setreg(portp, XONCR, tiosp->c_cc[VSTART]);
stl_sc26198setreg(portp, XOFFCR, tiosp->c_cc[VSTOP]);
ipr = stl_sc26198getreg(portp, IPR);
if (ipr & IPR_DCD)
portp->sigs &= ~TIOCM_CD;
else
portp->sigs |= TIOCM_CD;
portp->imr = (portp->imr & ~imroff) | imron;
stl_sc26198setreg(portp, IMR, portp->imr);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_sc26198setsignals(struct stlport *portp, int dtr, int rts)
{
unsigned char iopioron, iopioroff;
unsigned long flags;
pr_debug("stl_sc26198setsignals(portp=%p,dtr=%d,rts=%d)\n", portp,
dtr, rts);
iopioron = 0;
iopioroff = 0;
if (dtr == 0)
iopioroff |= IPR_DTR;
else if (dtr > 0)
iopioron |= IPR_DTR;
if (rts == 0)
iopioroff |= IPR_RTS;
else if (rts > 0)
iopioron |= IPR_RTS;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_sc26198setreg(portp, IOPIOR,
((stl_sc26198getreg(portp, IOPIOR) & ~iopioroff) | iopioron));
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static int stl_sc26198getsignals(struct stlport *portp)
{
unsigned char ipr;
unsigned long flags;
int sigs;
pr_debug("stl_sc26198getsignals(portp=%p)\n", portp);
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
ipr = stl_sc26198getreg(portp, IPR);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
sigs = 0;
sigs |= (ipr & IPR_DCD) ? 0 : TIOCM_CD;
sigs |= (ipr & IPR_CTS) ? 0 : TIOCM_CTS;
sigs |= (ipr & IPR_DTR) ? 0: TIOCM_DTR;
sigs |= (ipr & IPR_RTS) ? 0: TIOCM_RTS;
sigs |= TIOCM_DSR;
return sigs;
}
static void stl_sc26198enablerxtx(struct stlport *portp, int rx, int tx)
{
unsigned char ccr;
unsigned long flags;
pr_debug("stl_sc26198enablerxtx(portp=%p,rx=%d,tx=%d)\n", portp, rx,tx);
ccr = portp->crenable;
if (tx == 0)
ccr &= ~CR_TXENABLE;
else if (tx > 0)
ccr |= CR_TXENABLE;
if (rx == 0)
ccr &= ~CR_RXENABLE;
else if (rx > 0)
ccr |= CR_RXENABLE;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_sc26198setreg(portp, SCCR, ccr);
BRDDISABLE(portp->brdnr);
portp->crenable = ccr;
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_sc26198startrxtx(struct stlport *portp, int rx, int tx)
{
unsigned char imr;
unsigned long flags;
pr_debug("stl_sc26198startrxtx(portp=%p,rx=%d,tx=%d)\n", portp, rx, tx);
imr = portp->imr;
if (tx == 0)
imr &= ~IR_TXRDY;
else if (tx == 1)
imr |= IR_TXRDY;
if (rx == 0)
imr &= ~(IR_RXRDY | IR_RXBREAK | IR_RXWATCHDOG);
else if (rx > 0)
imr |= IR_RXRDY | IR_RXBREAK | IR_RXWATCHDOG;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_sc26198setreg(portp, IMR, imr);
BRDDISABLE(portp->brdnr);
portp->imr = imr;
if (tx > 0)
set_bit(ASYI_TXBUSY, &portp->istate);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_sc26198disableintrs(struct stlport *portp)
{
unsigned long flags;
pr_debug("stl_sc26198disableintrs(portp=%p)\n", portp);
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
portp->imr = 0;
stl_sc26198setreg(portp, IMR, 0);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_sc26198sendbreak(struct stlport *portp, int len)
{
unsigned long flags;
pr_debug("stl_sc26198sendbreak(portp=%p,len=%d)\n", portp, len);
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
if (len == 1) {
stl_sc26198setreg(portp, SCCR, CR_TXSTARTBREAK);
portp->stats.txbreaks++;
} else
stl_sc26198setreg(portp, SCCR, CR_TXSTOPBREAK);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
}
static void stl_sc26198flowctrl(struct stlport *portp, int state)
{
struct tty_struct *tty;
unsigned long flags;
unsigned char mr0;
pr_debug("stl_sc26198flowctrl(portp=%p,state=%x)\n", portp, state);
if (portp == NULL)
return;
tty = tty_port_tty_get(&portp->port);
if (tty == NULL)
return;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
if (state) {
if (tty->termios->c_iflag & IXOFF) {
mr0 = stl_sc26198getreg(portp, MR0);
stl_sc26198setreg(portp, MR0, (mr0 & ~MR0_SWFRXTX));
stl_sc26198setreg(portp, SCCR, CR_TXSENDXON);
mr0 |= MR0_SWFRX;
portp->stats.rxxon++;
stl_sc26198wait(portp);
stl_sc26198setreg(portp, MR0, mr0);
}
if (tty->termios->c_cflag & CRTSCTS) {
stl_sc26198setreg(portp, MR1,
(stl_sc26198getreg(portp, MR1) | MR1_AUTORTS));
stl_sc26198setreg(portp, IOPIOR,
(stl_sc26198getreg(portp, IOPIOR) | IOPR_RTS));
portp->stats.rxrtson++;
}
} else {
if (tty->termios->c_iflag & IXOFF) {
mr0 = stl_sc26198getreg(portp, MR0);
stl_sc26198setreg(portp, MR0, (mr0 & ~MR0_SWFRXTX));
stl_sc26198setreg(portp, SCCR, CR_TXSENDXOFF);
mr0 &= ~MR0_SWFRX;
portp->stats.rxxoff++;
stl_sc26198wait(portp);
stl_sc26198setreg(portp, MR0, mr0);
}
if (tty->termios->c_cflag & CRTSCTS) {
stl_sc26198setreg(portp, MR1,
(stl_sc26198getreg(portp, MR1) & ~MR1_AUTORTS));
stl_sc26198setreg(portp, IOPIOR,
(stl_sc26198getreg(portp, IOPIOR) & ~IOPR_RTS));
portp->stats.rxrtsoff++;
}
}
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
tty_kref_put(tty);
}
static void stl_sc26198sendflow(struct stlport *portp, int state)
{
struct tty_struct *tty;
unsigned long flags;
unsigned char mr0;
pr_debug("stl_sc26198sendflow(portp=%p,state=%x)\n", portp, state);
if (portp == NULL)
return;
tty = tty_port_tty_get(&portp->port);
if (tty == NULL)
return;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
if (state) {
mr0 = stl_sc26198getreg(portp, MR0);
stl_sc26198setreg(portp, MR0, (mr0 & ~MR0_SWFRXTX));
stl_sc26198setreg(portp, SCCR, CR_TXSENDXON);
mr0 |= MR0_SWFRX;
portp->stats.rxxon++;
stl_sc26198wait(portp);
stl_sc26198setreg(portp, MR0, mr0);
} else {
mr0 = stl_sc26198getreg(portp, MR0);
stl_sc26198setreg(portp, MR0, (mr0 & ~MR0_SWFRXTX));
stl_sc26198setreg(portp, SCCR, CR_TXSENDXOFF);
mr0 &= ~MR0_SWFRX;
portp->stats.rxxoff++;
stl_sc26198wait(portp);
stl_sc26198setreg(portp, MR0, mr0);
}
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
tty_kref_put(tty);
}
static void stl_sc26198flush(struct stlport *portp)
{
unsigned long flags;
pr_debug("stl_sc26198flush(portp=%p)\n", portp);
if (portp == NULL)
return;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
stl_sc26198setreg(portp, SCCR, CR_TXRESET);
stl_sc26198setreg(portp, SCCR, portp->crenable);
BRDDISABLE(portp->brdnr);
portp->tx.tail = portp->tx.head;
spin_unlock_irqrestore(&brd_lock, flags);
}
static int stl_sc26198datastate(struct stlport *portp)
{
unsigned long flags;
unsigned char sr;
pr_debug("stl_sc26198datastate(portp=%p)\n", portp);
if (portp == NULL)
return 0;
if (test_bit(ASYI_TXBUSY, &portp->istate))
return 1;
spin_lock_irqsave(&brd_lock, flags);
BRDENABLE(portp->brdnr, portp->pagenr);
sr = stl_sc26198getreg(portp, SR);
BRDDISABLE(portp->brdnr);
spin_unlock_irqrestore(&brd_lock, flags);
return (sr & SR_TXEMPTY) ? 0 : 1;
}
static void stl_sc26198wait(struct stlport *portp)
{
int i;
pr_debug("stl_sc26198wait(portp=%p)\n", portp);
if (portp == NULL)
return;
for (i = 0; i < 20; i++)
stl_sc26198getglobreg(portp, TSTR);
}
static void stl_sc26198txunflow(struct stlport *portp, struct tty_struct *tty)
{
unsigned char mr0;
mr0 = stl_sc26198getreg(portp, MR0);
stl_sc26198setreg(portp, MR0, (mr0 & ~MR0_SWFRXTX));
stl_sc26198setreg(portp, SCCR, CR_HOSTXON);
stl_sc26198wait(portp);
stl_sc26198setreg(portp, MR0, mr0);
clear_bit(ASYI_TXFLOWED, &portp->istate);
}
static void stl_sc26198intr(struct stlpanel *panelp, unsigned int iobase)
{
struct stlport *portp;
unsigned int iack;
spin_lock(&brd_lock);
outb(0, (iobase + 1));
iack = inb(iobase + XP_IACK);
portp = panelp->ports[(iack & IVR_CHANMASK) + ((iobase & 0x4) << 1)];
if (iack & IVR_RXDATA)
stl_sc26198rxisr(portp, iack);
else if (iack & IVR_TXDATA)
stl_sc26198txisr(portp);
else
stl_sc26198otherisr(portp, iack);
spin_unlock(&brd_lock);
}
static void stl_sc26198txisr(struct stlport *portp)
{
struct tty_struct *tty;
unsigned int ioaddr;
unsigned char mr0;
int len, stlen;
char *head, *tail;
pr_debug("stl_sc26198txisr(portp=%p)\n", portp);
ioaddr = portp->ioaddr;
head = portp->tx.head;
tail = portp->tx.tail;
len = (head >= tail) ? (head - tail) : (STL_TXBUFSIZE - (tail - head));
if ((len == 0) || ((len < STL_TXBUFLOW) &&
(test_bit(ASYI_TXLOW, &portp->istate) == 0))) {
set_bit(ASYI_TXLOW, &portp->istate);
tty = tty_port_tty_get(&portp->port);
if (tty) {
tty_wakeup(tty);
tty_kref_put(tty);
}
}
if (len == 0) {
outb((MR0 | portp->uartaddr), (ioaddr + XP_ADDR));
mr0 = inb(ioaddr + XP_DATA);
if ((mr0 & MR0_TXMASK) == MR0_TXEMPTY) {
portp->imr &= ~IR_TXRDY;
outb((IMR | portp->uartaddr), (ioaddr + XP_ADDR));
outb(portp->imr, (ioaddr + XP_DATA));
clear_bit(ASYI_TXBUSY, &portp->istate);
} else {
mr0 |= ((mr0 & ~MR0_TXMASK) | MR0_TXEMPTY);
outb(mr0, (ioaddr + XP_DATA));
}
} else {
len = min(len, SC26198_TXFIFOSIZE);
portp->stats.txtotal += len;
stlen = min_t(unsigned int, len,
(portp->tx.buf + STL_TXBUFSIZE) - tail);
outb(GTXFIFO, (ioaddr + XP_ADDR));
outsb((ioaddr + XP_DATA), tail, stlen);
len -= stlen;
tail += stlen;
if (tail >= (portp->tx.buf + STL_TXBUFSIZE))
tail = portp->tx.buf;
if (len > 0) {
outsb((ioaddr + XP_DATA), tail, len);
tail += len;
}
portp->tx.tail = tail;
}
}
static void stl_sc26198rxisr(struct stlport *portp, unsigned int iack)
{
struct tty_struct *tty;
unsigned int len, buflen, ioaddr;
pr_debug("stl_sc26198rxisr(portp=%p,iack=%x)\n", portp, iack);
tty = tty_port_tty_get(&portp->port);
ioaddr = portp->ioaddr;
outb(GIBCR, (ioaddr + XP_ADDR));
len = inb(ioaddr + XP_DATA) + 1;
if ((iack & IVR_TYPEMASK) == IVR_RXDATA) {
if (tty == NULL || (buflen = tty_buffer_request_room(tty, len)) == 0) {
len = min_t(unsigned int, len, sizeof(stl_unwanted));
outb(GRXFIFO, (ioaddr + XP_ADDR));
insb((ioaddr + XP_DATA), &stl_unwanted[0], len);
portp->stats.rxlost += len;
portp->stats.rxtotal += len;
} else {
len = min(len, buflen);
if (len > 0) {
unsigned char *ptr;
outb(GRXFIFO, (ioaddr + XP_ADDR));
tty_prepare_flip_string(tty, &ptr, len);
insb((ioaddr + XP_DATA), ptr, len);
tty_schedule_flip(tty);
portp->stats.rxtotal += len;
}
}
} else {
stl_sc26198rxbadchars(portp);
}
if (test_bit(ASYI_TXFLOWED, &portp->istate)) {
if ((tty != NULL) &&
(tty->termios != NULL) &&
(tty->termios->c_iflag & IXANY)) {
stl_sc26198txunflow(portp, tty);
}
}
tty_kref_put(tty);
}
static void stl_sc26198rxbadch(struct stlport *portp, unsigned char status, char ch)
{
struct tty_struct *tty;
unsigned int ioaddr;
tty = tty_port_tty_get(&portp->port);
ioaddr = portp->ioaddr;
if (status & SR_RXPARITY)
portp->stats.rxparity++;
if (status & SR_RXFRAMING)
portp->stats.rxframing++;
if (status & SR_RXOVERRUN)
portp->stats.rxoverrun++;
if (status & SR_RXBREAK)
portp->stats.rxbreaks++;
if ((tty != NULL) &&
((portp->rxignoremsk & status) == 0)) {
if (portp->rxmarkmsk & status) {
if (status & SR_RXBREAK) {
status = TTY_BREAK;
if (portp->port.flags & ASYNC_SAK) {
do_SAK(tty);
BRDENABLE(portp->brdnr, portp->pagenr);
}
} else if (status & SR_RXPARITY)
status = TTY_PARITY;
else if (status & SR_RXFRAMING)
status = TTY_FRAME;
else if(status & SR_RXOVERRUN)
status = TTY_OVERRUN;
else
status = 0;
} else
status = 0;
tty_insert_flip_char(tty, ch, status);
tty_schedule_flip(tty);
if (status == 0)
portp->stats.rxtotal++;
}
tty_kref_put(tty);
}
static void stl_sc26198rxbadchars(struct stlport *portp)
{
unsigned char status, mr1;
char ch;
mr1 = stl_sc26198getreg(portp, MR1);
stl_sc26198setreg(portp, MR1, (mr1 & ~MR1_ERRBLOCK));
while ((status = stl_sc26198getreg(portp, SR)) & SR_RXRDY) {
stl_sc26198setreg(portp, SCCR, CR_CLEARRXERR);
ch = stl_sc26198getreg(portp, RXFIFO);
stl_sc26198rxbadch(portp, status, ch);
}
stl_sc26198setreg(portp, MR1, mr1);
}
static void stl_sc26198otherisr(struct stlport *portp, unsigned int iack)
{
unsigned char cir, ipr, xisr;
pr_debug("stl_sc26198otherisr(portp=%p,iack=%x)\n", portp, iack);
cir = stl_sc26198getglobreg(portp, CIR);
switch (cir & CIR_SUBTYPEMASK) {
case CIR_SUBCOS:
ipr = stl_sc26198getreg(portp, IPR);
if (ipr & IPR_DCDCHANGE) {
stl_cd_change(portp);
portp->stats.modem++;
}
break;
case CIR_SUBXONXOFF:
xisr = stl_sc26198getreg(portp, XISR);
if (xisr & XISR_RXXONGOT) {
set_bit(ASYI_TXFLOWED, &portp->istate);
portp->stats.txxoff++;
}
if (xisr & XISR_RXXOFFGOT) {
clear_bit(ASYI_TXFLOWED, &portp->istate);
portp->stats.txxon++;
}
break;
case CIR_SUBBREAK:
stl_sc26198setreg(portp, SCCR, CR_BREAKRESET);
stl_sc26198rxbadchars(portp);
break;
default:
break;
}
}
static void stl_free_isabrds(void)
{
struct stlbrd *brdp;
unsigned int i;
for (i = 0; i < stl_nrbrds; i++) {
if ((brdp = stl_brds[i]) == NULL || (brdp->state & STL_PROBED))
continue;
free_irq(brdp->irq, brdp);
stl_cleanup_panels(brdp);
release_region(brdp->ioaddr1, brdp->iosize1);
if (brdp->iosize2 > 0)
release_region(brdp->ioaddr2, brdp->iosize2);
kfree(brdp);
stl_brds[i] = NULL;
}
}
static int __init stallion_module_init(void)
{
struct stlbrd *brdp;
struct stlconf conf;
unsigned int i, j;
int retval;
printk(KERN_INFO "%s: version %s\n", stl_drvtitle, stl_drvversion);
spin_lock_init(&stallion_lock);
spin_lock_init(&brd_lock);
stl_serial = alloc_tty_driver(STL_MAXBRDS * STL_MAXPORTS);
if (!stl_serial) {
retval = -ENOMEM;
goto err;
}
stl_serial->owner = THIS_MODULE;
stl_serial->driver_name = stl_drvname;
stl_serial->name = "ttyE";
stl_serial->major = STL_SERIALMAJOR;
stl_serial->minor_start = 0;
stl_serial->type = TTY_DRIVER_TYPE_SERIAL;
stl_serial->subtype = SERIAL_TYPE_NORMAL;
stl_serial->init_termios = stl_deftermios;
stl_serial->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
tty_set_operations(stl_serial, &stl_ops);
retval = tty_register_driver(stl_serial);
if (retval) {
printk("STALLION: failed to register serial driver\n");
goto err_frtty;
}
for (i = stl_nrbrds; i < stl_nargs; i++) {
memset(&conf, 0, sizeof(conf));
if (stl_parsebrd(&conf, stl_brdsp[i]) == 0)
continue;
if ((brdp = stl_allocbrd()) == NULL)
continue;
brdp->brdnr = i;
brdp->brdtype = conf.brdtype;
brdp->ioaddr1 = conf.ioaddr1;
brdp->ioaddr2 = conf.ioaddr2;
brdp->irq = conf.irq;
brdp->irqtype = conf.irqtype;
stl_brds[brdp->brdnr] = brdp;
if (stl_brdinit(brdp)) {
stl_brds[brdp->brdnr] = NULL;
kfree(brdp);
} else {
for (j = 0; j < brdp->nrports; j++)
tty_register_device(stl_serial,
brdp->brdnr * STL_MAXPORTS + j, NULL);
stl_nrbrds = i + 1;
}
}
retval = pci_register_driver(&stl_pcidriver);
if (retval && stl_nrbrds == 0) {
printk(KERN_ERR "STALLION: can't register pci driver\n");
goto err_unrtty;
}
if (register_chrdev(STL_SIOMEMMAJOR, "staliomem", &stl_fsiomem))
printk("STALLION: failed to register serial board device\n");
stallion_class = class_create(THIS_MODULE, "staliomem");
if (IS_ERR(stallion_class))
printk("STALLION: failed to create class\n");
for (i = 0; i < 4; i++)
device_create(stallion_class, NULL, MKDEV(STL_SIOMEMMAJOR, i),
NULL, "staliomem%d", i);
return 0;
err_unrtty:
tty_unregister_driver(stl_serial);
err_frtty:
put_tty_driver(stl_serial);
err:
return retval;
}
static void __exit stallion_module_exit(void)
{
struct stlbrd *brdp;
unsigned int i, j;
pr_debug("cleanup_module()\n");
printk(KERN_INFO "Unloading %s: version %s\n", stl_drvtitle,
stl_drvversion);
for (i = 0; i < stl_nrbrds; i++) {
if ((brdp = stl_brds[i]) == NULL || (brdp->state & STL_PROBED))
continue;
for (j = 0; j < brdp->nrports; j++)
tty_unregister_device(stl_serial,
brdp->brdnr * STL_MAXPORTS + j);
}
for (i = 0; i < 4; i++)
device_destroy(stallion_class, MKDEV(STL_SIOMEMMAJOR, i));
unregister_chrdev(STL_SIOMEMMAJOR, "staliomem");
class_destroy(stallion_class);
pci_unregister_driver(&stl_pcidriver);
stl_free_isabrds();
tty_unregister_driver(stl_serial);
put_tty_driver(stl_serial);
}
