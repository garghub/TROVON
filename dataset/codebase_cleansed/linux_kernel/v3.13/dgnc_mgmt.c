int dgnc_mgmt_open(struct inode *inode, struct file *file)
{
unsigned long lock_flags;
unsigned int minor = iminor(inode);
DPR_MGMT(("dgnc_mgmt_open start.\n"));
DGNC_LOCK(dgnc_global_lock, lock_flags);
if (minor < MAXMGMTDEVICES) {
if (dgnc_mgmt_in_use[minor]) {
DGNC_UNLOCK(dgnc_global_lock, lock_flags);
return -EBUSY;
}
dgnc_mgmt_in_use[minor]++;
}
else {
DGNC_UNLOCK(dgnc_global_lock, lock_flags);
return -ENXIO;
}
DGNC_UNLOCK(dgnc_global_lock, lock_flags);
DPR_MGMT(("dgnc_mgmt_open finish.\n"));
return 0;
}
int dgnc_mgmt_close(struct inode *inode, struct file *file)
{
unsigned long lock_flags;
unsigned int minor = iminor(inode);
DPR_MGMT(("dgnc_mgmt_close start.\n"));
DGNC_LOCK(dgnc_global_lock, lock_flags);
if (minor < MAXMGMTDEVICES) {
if (dgnc_mgmt_in_use[minor]) {
dgnc_mgmt_in_use[minor] = 0;
}
}
DGNC_UNLOCK(dgnc_global_lock, lock_flags);
DPR_MGMT(("dgnc_mgmt_close finish.\n"));
return 0;
}
long dgnc_mgmt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
unsigned long lock_flags;
void __user *uarg = (void __user *) arg;
DPR_MGMT(("dgnc_mgmt_ioctl start.\n"));
switch (cmd) {
case DIGI_GETDD:
{
struct digi_dinfo ddi;
DGNC_LOCK(dgnc_global_lock, lock_flags);
ddi.dinfo_nboards = dgnc_NumBoards;
sprintf(ddi.dinfo_version, "%s", DG_PART);
DGNC_UNLOCK(dgnc_global_lock, lock_flags);
DPR_MGMT(("DIGI_GETDD returning numboards: %d version: %s\n",
ddi.dinfo_nboards, ddi.dinfo_version));
if (copy_to_user(uarg, &ddi, sizeof (ddi)))
return -EFAULT;
break;
}
case DIGI_GETBD:
{
int brd;
struct digi_info di;
if (copy_from_user(&brd, uarg, sizeof(int))) {
return -EFAULT;
}
DPR_MGMT(("DIGI_GETBD asking about board: %d\n", brd));
if ((brd < 0) || (brd > dgnc_NumBoards) || (dgnc_NumBoards == 0))
return -ENODEV;
memset(&di, 0, sizeof(di));
di.info_bdnum = brd;
DGNC_LOCK(dgnc_Board[brd]->bd_lock, lock_flags);
di.info_bdtype = dgnc_Board[brd]->dpatype;
di.info_bdstate = dgnc_Board[brd]->dpastatus;
di.info_ioport = 0;
di.info_physaddr = (ulong) dgnc_Board[brd]->membase;
di.info_physsize = (ulong) dgnc_Board[brd]->membase - dgnc_Board[brd]->membase_end;
if (dgnc_Board[brd]->state != BOARD_FAILED)
di.info_nports = dgnc_Board[brd]->nasync;
else
di.info_nports = 0;
DGNC_UNLOCK(dgnc_Board[brd]->bd_lock, lock_flags);
DPR_MGMT(("DIGI_GETBD returning type: %x state: %x ports: %x size: %x\n",
di.info_bdtype, di.info_bdstate, di.info_nports, di.info_physsize));
if (copy_to_user(uarg, &di, sizeof (di)))
return -EFAULT;
break;
}
case DIGI_GET_NI_INFO:
{
struct channel_t *ch;
struct ni_info ni;
uchar mstat = 0;
uint board = 0;
uint channel = 0;
if (copy_from_user(&ni, uarg, sizeof(ni))) {
return -EFAULT;
}
DPR_MGMT(("DIGI_GETBD asking about board: %d channel: %d\n",
ni.board, ni.channel));
board = ni.board;
channel = ni.channel;
if ((board > dgnc_NumBoards) || (dgnc_NumBoards == 0))
return -ENODEV;
if ((channel < 0) || (channel > dgnc_Board[board]->nasync))
return -ENODEV;
ch = dgnc_Board[board]->channels[channel];
if (!ch || ch->magic != DGNC_CHANNEL_MAGIC)
return -ENODEV;
memset(&ni, 0, sizeof(ni));
ni.board = board;
ni.channel = channel;
DGNC_LOCK(ch->ch_lock, lock_flags);
mstat = (ch->ch_mostat | ch->ch_mistat);
if (mstat & UART_MCR_DTR) {
ni.mstat |= TIOCM_DTR;
ni.dtr = TIOCM_DTR;
}
if (mstat & UART_MCR_RTS) {
ni.mstat |= TIOCM_RTS;
ni.rts = TIOCM_RTS;
}
if (mstat & UART_MSR_CTS) {
ni.mstat |= TIOCM_CTS;
ni.cts = TIOCM_CTS;
}
if (mstat & UART_MSR_RI) {
ni.mstat |= TIOCM_RI;
ni.ri = TIOCM_RI;
}
if (mstat & UART_MSR_DCD) {
ni.mstat |= TIOCM_CD;
ni.dcd = TIOCM_CD;
}
if (mstat & UART_MSR_DSR)
ni.mstat |= TIOCM_DSR;
ni.iflag = ch->ch_c_iflag;
ni.oflag = ch->ch_c_oflag;
ni.cflag = ch->ch_c_cflag;
ni.lflag = ch->ch_c_lflag;
if (ch->ch_digi.digi_flags & CTSPACE || ch->ch_c_cflag & CRTSCTS)
ni.hflow = 1;
else
ni.hflow = 0;
if ((ch->ch_flags & CH_STOPI) || (ch->ch_flags & CH_FORCED_STOPI))
ni.recv_stopped = 1;
else
ni.recv_stopped = 0;
if ((ch->ch_flags & CH_STOP) || (ch->ch_flags & CH_FORCED_STOP))
ni.xmit_stopped = 1;
else
ni.xmit_stopped = 0;
ni.curtx = ch->ch_txcount;
ni.currx = ch->ch_rxcount;
ni.baud = ch->ch_old_baud;
DGNC_UNLOCK(ch->ch_lock, lock_flags);
if (copy_to_user(uarg, &ni, sizeof(ni)))
return -EFAULT;
break;
}
}
DPR_MGMT(("dgnc_mgmt_ioctl finish.\n"));
return 0;
}
