static int __init is_valid_irq(int irq)
{
int *i = Valid_Irqs;
while (*i != 0 && *i != irq)
i++;
return *i;
}
static void __init mark_requested_irq(char irq)
{
rirqs[iindx++] = irq;
}
static int __exit clear_requested_irq(char irq)
{
int i;
for (i = 0; i < IP2_MAX_BOARDS; ++i) {
if (rirqs[i] == irq) {
rirqs[i] = 0;
return 1;
}
}
return 0;
}
static int have_requested_irq(char irq)
{
int i;
for (i = 0; i < IP2_MAX_BOARDS; ++i)
if (rirqs[i] == irq)
return 1;
return 0;
}
static void __exit ip2_cleanup_module(void)
{
int err;
int i;
del_timer_sync(&PollTimer);
for (i = 0; i < IP2_MAX_BOARDS; i++)
if (i2BoardPtrTable[i])
iiReset(i2BoardPtrTable[i]);
for (i = 0; i < IP2_MAX_BOARDS; i++) {
if (i2BoardPtrTable[i]) {
iiResetDelay(i2BoardPtrTable[i]);
release_region(ip2config.addr[i], 8);
device_destroy(ip2_class, MKDEV(IP2_IPL_MAJOR, 4 * i));
device_destroy(ip2_class, MKDEV(IP2_IPL_MAJOR,
4 * i + 1));
}
if (ip2config.irq[i] > 0 &&
have_requested_irq(ip2config.irq[i])) {
free_irq(ip2config.irq[i], (void *)&pcName);
clear_requested_irq(ip2config.irq[i]);
}
}
class_destroy(ip2_class);
err = tty_unregister_driver(ip2_tty_driver);
if (err)
printk(KERN_ERR "IP2: failed to unregister tty driver (%d)\n",
err);
put_tty_driver(ip2_tty_driver);
unregister_chrdev(IP2_IPL_MAJOR, pcIpl);
remove_proc_entry("ip2mem", NULL);
for (i = 0; i < IP2_MAX_BOARDS; i++) {
void *pB;
#ifdef CONFIG_PCI
if (ip2config.type[i] == PCI && ip2config.pci_dev[i]) {
pci_disable_device(ip2config.pci_dev[i]);
pci_dev_put(ip2config.pci_dev[i]);
ip2config.pci_dev[i] = NULL;
}
#endif
pB = i2BoardPtrTable[i];
if (pB != NULL) {
kfree(pB);
i2BoardPtrTable[i] = NULL;
}
if (DevTableMem[i] != NULL) {
kfree(DevTableMem[i]);
DevTableMem[i] = NULL;
}
}
}
static const struct firmware *ip2_request_firmware(void)
{
struct platform_device *pdev;
const struct firmware *fw;
pdev = platform_device_register_simple("ip2", 0, NULL, 0);
if (IS_ERR(pdev)) {
printk(KERN_ERR "Failed to register platform device for ip2\n");
return NULL;
}
if (request_firmware(&fw, "intelliport2.bin", &pdev->dev)) {
printk(KERN_ERR "Failed to load firmware 'intelliport2.bin'\n");
fw = NULL;
}
platform_device_unregister(pdev);
return fw;
}
static int __init ip2_setup(char *str)
{
int j, ints[10];
unsigned int i;
str = get_options(str, ARRAY_SIZE(ints), ints);
for (i = 0, j = 1; i < 4; i++) {
if (j > ints[0])
break;
if (ints[j] >= 0)
io[i] = ints[j];
j++;
if (j > ints[0])
break;
if (ints[j] >= 0)
irq[i] = ints[j];
j++;
}
return 1;
}
static int __init ip2_loadmain(void)
{
int i, j, box;
int err = 0;
i2eBordStrPtr pB = NULL;
int rc = -1;
const struct firmware *fw = NULL;
char *str;
str = cmd;
if (poll_only) {
irq[0] = irq[1] = irq[2] = irq[3] = poll_only = 0;
}
if (!poll_only && (!strncmp(str, "ip2=", 4)))
ip2_setup(str);
ip2trace(ITRC_NO_PORT, ITRC_INIT, ITRC_ENTER, 0);
for (i = 0; i < IP2_MAX_BOARDS; ++i) {
ip2config.addr[i] = io[i];
if (irq[i] >= 0)
ip2config.irq[i] = irq[i];
else
ip2config.irq[i] = 0;
poll_only |= irq[i];
}
poll_only = !poll_only;
printk(KERN_INFO "%s version %s\n", pcName, pcVersion);
ip2_tty_driver = alloc_tty_driver(IP2_MAX_PORTS);
if (!ip2_tty_driver)
return -ENOMEM;
for (i = 0; i < IP2_MAX_BOARDS; ++i) {
switch (ip2config.addr[i]) {
case 0:
break;
default:
if (ip2config.addr[i] < 0x100 ||
ip2config.addr[i] > 0x3f8) {
printk(KERN_ERR "IP2: Bad ISA board %d "
"address %x\n", i,
ip2config.addr[i]);
ip2config.addr[i] = 0;
break;
}
ip2config.type[i] = ISA;
if (ip2config.irq[i] &&
!is_valid_irq(ip2config.irq[i])) {
printk(KERN_ERR "IP2: Bad IRQ(%d) specified\n",
ip2config.irq[i]);
ip2config.irq[i] = 0;
}
break;
case PCI:
#ifdef CONFIG_PCI
{
struct pci_dev *pdev = NULL;
u32 addr;
int status;
pdev = pci_get_device(PCI_VENDOR_ID_COMPUTONE,
PCI_DEVICE_ID_COMPUTONE_IP2EX, pdev);
if (pdev == NULL) {
ip2config.addr[i] = 0;
printk(KERN_ERR "IP2: PCI board %d not "
"found\n", i);
break;
}
if (pci_enable_device(pdev)) {
dev_err(&pdev->dev, "can't enable device\n");
goto out;
}
ip2config.type[i] = PCI;
ip2config.pci_dev[i] = pci_dev_get(pdev);
status = pci_read_config_dword(pdev, PCI_BASE_ADDRESS_1,
&addr);
if (addr & 1)
ip2config.addr[i] = (USHORT)(addr & 0xfffe);
else
dev_err(&pdev->dev, "I/O address error\n");
ip2config.irq[i] = pdev->irq;
out:
pci_dev_put(pdev);
}
#else
printk(KERN_ERR "IP2: PCI card specified but PCI "
"support not enabled.\n");
printk(KERN_ERR "IP2: Recompile kernel with CONFIG_PCI "
"defined!\n");
#endif
break;
case EISA:
ip2config.addr[i] = find_eisa_board(Eisa_slot + 1);
if (ip2config.addr[i] != 0) {
ip2config.type[i] = EISA;
}
ip2config.irq[i] = Eisa_irq;
break;
}
}
for (i = 0; i < IP2_MAX_BOARDS; ++i) {
if (ip2config.addr[i]) {
pB = kzalloc(sizeof(i2eBordStr), GFP_KERNEL);
if (pB) {
i2BoardPtrTable[i] = pB;
iiSetAddress(pB, ip2config.addr[i],
ii2DelayTimer);
iiReset(pB);
} else
printk(KERN_ERR "IP2: board memory allocation "
"error\n");
}
}
for (i = 0; i < IP2_MAX_BOARDS; ++i) {
pB = i2BoardPtrTable[i];
if (pB != NULL) {
iiResetDelay(pB);
break;
}
}
for (i = 0; i < IP2_MAX_BOARDS; ++i) {
if (i2BoardPtrTable[i] != NULL) {
if (!fw)
fw = ip2_request_firmware();
if (!fw)
break;
ip2_init_board(i, fw);
}
}
if (fw)
release_firmware(fw);
ip2trace(ITRC_NO_PORT, ITRC_INIT, 2, 0);
ip2_tty_driver->owner = THIS_MODULE;
ip2_tty_driver->name = "ttyF";
ip2_tty_driver->driver_name = pcDriver_name;
ip2_tty_driver->major = IP2_TTY_MAJOR;
ip2_tty_driver->minor_start = 0;
ip2_tty_driver->type = TTY_DRIVER_TYPE_SERIAL;
ip2_tty_driver->subtype = SERIAL_TYPE_NORMAL;
ip2_tty_driver->init_termios = tty_std_termios;
ip2_tty_driver->init_termios.c_cflag = B9600|CS8|CREAD|HUPCL|CLOCAL;
ip2_tty_driver->flags = TTY_DRIVER_REAL_RAW |
TTY_DRIVER_DYNAMIC_DEV;
tty_set_operations(ip2_tty_driver, &ip2_ops);
ip2trace(ITRC_NO_PORT, ITRC_INIT, 3, 0);
err = tty_register_driver(ip2_tty_driver);
if (err) {
printk(KERN_ERR "IP2: failed to register tty driver\n");
put_tty_driver(ip2_tty_driver);
return err;
}
err = register_chrdev(IP2_IPL_MAJOR, pcIpl, &ip2_ipl);
if (err) {
printk(KERN_ERR "IP2: failed to register IPL device (%d)\n",
err);
} else {
ip2_class = class_create(THIS_MODULE, "ip2");
if (IS_ERR(ip2_class)) {
err = PTR_ERR(ip2_class);
goto out_chrdev;
}
}
if (!proc_create("ip2mem",0,NULL,&ip2mem_proc_fops)) {
printk(KERN_ERR "IP2: failed to register read_procmem\n");
return -EIO;
}
ip2trace(ITRC_NO_PORT, ITRC_INIT, 4, 0);
for (i = 0; i < IP2_MAX_BOARDS; ++i) {
if (ip2config.addr[i] == 0)
continue;
pB = i2BoardPtrTable[i];
if (pB != NULL) {
device_create(ip2_class, NULL,
MKDEV(IP2_IPL_MAJOR, 4 * i),
NULL, "ipl%d", i);
device_create(ip2_class, NULL,
MKDEV(IP2_IPL_MAJOR, 4 * i + 1),
NULL, "stat%d", i);
for (box = 0; box < ABS_MAX_BOXES; box++)
for (j = 0; j < ABS_BIGGEST_BOX; j++)
if (pB->i2eChannelMap[box] & (1 << j))
tty_register_device(
ip2_tty_driver,
j + ABS_BIGGEST_BOX *
(box+i*ABS_MAX_BOXES),
NULL);
}
if (poll_only) {
ip2config.irq[i] = CIR_POLL;
}
if (ip2config.irq[i] == CIR_POLL) {
retry:
if (!timer_pending(&PollTimer)) {
mod_timer(&PollTimer, POLL_TIMEOUT);
printk(KERN_INFO "IP2: polling\n");
}
} else {
if (have_requested_irq(ip2config.irq[i]))
continue;
rc = request_irq(ip2config.irq[i], ip2_interrupt,
IP2_SA_FLAGS |
(ip2config.type[i] == PCI ? IRQF_SHARED : 0),
pcName, i2BoardPtrTable[i]);
if (rc) {
printk(KERN_ERR "IP2: request_irq failed: "
"error %d\n", rc);
ip2config.irq[i] = CIR_POLL;
printk(KERN_INFO "IP2: Polling %ld/sec.\n",
(POLL_TIMEOUT - jiffies));
goto retry;
}
mark_requested_irq(ip2config.irq[i]);
}
}
for (i = 0; i < IP2_MAX_BOARDS; ++i) {
if (i2BoardPtrTable[i]) {
set_irq(i, ip2config.irq[i]);
}
}
ip2trace(ITRC_NO_PORT, ITRC_INIT, ITRC_RETURN, 0);
return 0;
out_chrdev:
unregister_chrdev(IP2_IPL_MAJOR, "ip2");
return err;
}
static void
ip2_init_board(int boardnum, const struct firmware *fw)
{
int i;
int nports = 0, nboxes = 0;
i2ChanStrPtr pCh;
i2eBordStrPtr pB = i2BoardPtrTable[boardnum];
if ( !iiInitialize ( pB ) ) {
printk ( KERN_ERR "IP2: Failed to initialize board at 0x%x, error %d\n",
pB->i2eBase, pB->i2eError );
goto err_initialize;
}
printk(KERN_INFO "IP2: Board %d: addr=0x%x irq=%d\n", boardnum + 1,
ip2config.addr[boardnum], ip2config.irq[boardnum] );
if (!request_region( ip2config.addr[boardnum], 8, pcName )) {
printk(KERN_ERR "IP2: bad addr=0x%x\n", ip2config.addr[boardnum]);
goto err_initialize;
}
if ( iiDownloadAll ( pB, (loadHdrStrPtr)fw->data, 1, fw->size )
!= II_DOWN_GOOD ) {
printk ( KERN_ERR "IP2: failed to download loadware\n" );
goto err_release_region;
} else {
printk ( KERN_INFO "IP2: fv=%d.%d.%d lv=%d.%d.%d\n",
pB->i2ePom.e.porVersion,
pB->i2ePom.e.porRevision,
pB->i2ePom.e.porSubRev, pB->i2eLVersion,
pB->i2eLRevision, pB->i2eLSub );
}
switch ( pB->i2ePom.e.porID & ~POR_ID_RESERVED ) {
default:
printk( KERN_ERR "IP2: Unknown board type, ID = %x\n",
pB->i2ePom.e.porID );
nports = 0;
goto err_release_region;
break;
case POR_ID_II_4:
printk ( KERN_INFO "IP2: ISA-4\n" );
nports = 4;
break;
case POR_ID_II_8:
printk ( KERN_INFO "IP2: ISA-8 std\n" );
nports = 8;
break;
case POR_ID_II_8R:
printk ( KERN_INFO "IP2: ISA-8 RJ11\n" );
nports = 8;
break;
case POR_ID_FIIEX:
{
int portnum = IP2_PORTS_PER_BOARD * boardnum;
int box;
for( box = 0; box < ABS_MAX_BOXES; ++box ) {
if ( pB->i2eChannelMap[box] != 0 ) {
++nboxes;
}
for( i = 0; i < ABS_BIGGEST_BOX; ++i ) {
if ( pB->i2eChannelMap[box] & 1<< i ) {
++nports;
}
}
}
DevTableMem[boardnum] = pCh =
kmalloc( sizeof(i2ChanStr) * nports, GFP_KERNEL );
if ( !pCh ) {
printk ( KERN_ERR "IP2: (i2_init_channel:) Out of memory.\n");
goto err_release_region;
}
if ( !i2InitChannels( pB, nports, pCh ) ) {
printk(KERN_ERR "IP2: i2InitChannels failed: %d\n",pB->i2eError);
kfree ( pCh );
goto err_release_region;
}
pB->i2eChannelPtr = &DevTable[portnum];
pB->i2eChannelCnt = ABS_MOST_PORTS;
for( box = 0; box < ABS_MAX_BOXES; ++box, portnum += ABS_BIGGEST_BOX ) {
for( i = 0; i < ABS_BIGGEST_BOX; ++i ) {
if ( pB->i2eChannelMap[box] & (1 << i) ) {
DevTable[portnum + i] = pCh;
pCh->port_index = portnum + i;
pCh++;
}
}
}
printk(KERN_INFO "IP2: EX box=%d ports=%d %d bit\n",
nboxes, nports, pB->i2eDataWidth16 ? 16 : 8 );
}
goto ex_exit;
}
DevTableMem[boardnum] = pCh =
kmalloc ( sizeof (i2ChanStr) * nports, GFP_KERNEL );
if ( !pCh ) {
printk ( KERN_ERR "IP2: (i2_init_channel:) Out of memory.\n");
goto err_release_region;
}
pB->i2eChannelPtr = pCh;
pB->i2eChannelCnt = nports;
if ( !i2InitChannels( pB, nports, pCh ) ) {
printk(KERN_ERR "IP2: i2InitChannels failed: %d\n",pB->i2eError);
kfree ( pCh );
goto err_release_region;
}
pB->i2eChannelPtr = &DevTable[IP2_PORTS_PER_BOARD * boardnum];
for( i = 0; i < pB->i2eChannelCnt; ++i ) {
DevTable[IP2_PORTS_PER_BOARD * boardnum + i] = pCh;
pCh->port_index = (IP2_PORTS_PER_BOARD * boardnum) + i;
pCh++;
}
ex_exit:
INIT_WORK(&pB->tqueue_interrupt, ip2_interrupt_bh);
return;
err_release_region:
release_region(ip2config.addr[boardnum], 8);
err_initialize:
kfree ( pB );
i2BoardPtrTable[boardnum] = NULL;
return;
}
static unsigned short
find_eisa_board( int start_slot )
{
int i, j;
unsigned int idm = 0;
unsigned int idp = 0;
unsigned int base = 0;
unsigned int value;
int setup_address;
int setup_irq;
int ismine = 0;
i = 0x0c80;
value = (inb(i) << 24) + (inb(i+1) << 16) + (inb(i+2) << 8) + inb(i+3);
for( i = 0x1c80; i <= 0x4c80; i += 0x1000 ) {
j = (inb(i)<<24)+(inb(i+1)<<16)+(inb(i+2)<<8)+inb(i+3);
if ( value == j )
return 0;
}
for( i = start_slot; i < 16; i++ ) {
base = i << 12;
idm = (inb(base + 0xc80) << 8) | (inb(base + 0xc81) & 0xff);
idp = (inb(base + 0xc82) << 8) | (inb(base + 0xc83) & 0xff);
ismine = 0;
if ( idm == 0x0e8e ) {
if ( idp == 0x0281 || idp == 0x0218 ) {
ismine = 1;
} else if ( idp == 0x0282 || idp == 0x0283 ) {
ismine = 3;
}
if ( ismine ) {
Eisa_slot = i;
break;
}
}
}
if ( !ismine )
return 0;
setup_address = base + 0xc88;
value = inb(base + 0xc86);
setup_irq = (value & 8) ? Valid_Irqs[value & 7] : 0;
if ( (ismine & 2) && !(value & 0x10) ) {
ismine = 1;
}
if ( Eisa_irq == 0 ) {
Eisa_irq = setup_irq;
} else if ( Eisa_irq != setup_irq ) {
printk ( KERN_ERR "IP2: EISA irq mismatch between EISA controllers\n" );
}
#ifdef IP2DEBUG_INIT
printk(KERN_DEBUG "Computone EISA board in slot %d, I.D. 0x%x%x, Address 0x%x",
base >> 12, idm, idp, setup_address);
if ( Eisa_irq ) {
printk(KERN_DEBUG ", Interrupt %d %s\n",
setup_irq, (ismine & 2) ? "(edge)" : "(level)");
} else {
printk(KERN_DEBUG ", (polled)\n");
}
#endif
return setup_address;
}
static void
set_irq( int boardnum, int boardIrq )
{
unsigned char tempCommand[16];
i2eBordStrPtr pB = i2BoardPtrTable[boardnum];
unsigned long flags;
iiDisableMailIrq(pB);
CHANNEL_OF(tempCommand) = 0;
PTYPE_OF(tempCommand) = PTYPE_INLINE;
CMD_COUNT_OF(tempCommand) = 2;
(CMD_OF(tempCommand))[0] = CMDVALUE_IRQ;
(CMD_OF(tempCommand))[1] = boardIrq;
write_lock_irqsave(&pB->write_fifo_spinlock, flags);
iiWriteBuf(pB, tempCommand, 4);
write_unlock_irqrestore(&pB->write_fifo_spinlock, flags);
pB->i2eUsingIrq = boardIrq;
pB->i2eOutMailWaiting |= MB_OUT_STUFFED;
++i2nBoards;
CHANNEL_OF(tempCommand) = 0;
PTYPE_OF(tempCommand) = PTYPE_BYPASS;
CMD_COUNT_OF(tempCommand) = 6;
(CMD_OF(tempCommand))[0] = 88;
(CMD_OF(tempCommand))[1] = 64;
(CMD_OF(tempCommand))[2] = 32;
(CMD_OF(tempCommand))[3] = 28;
(CMD_OF(tempCommand))[4] = 64;
(CMD_OF(tempCommand))[5] = 87;
write_lock_irqsave(&pB->write_fifo_spinlock, flags);
iiWriteBuf(pB, tempCommand, 8);
write_unlock_irqrestore(&pB->write_fifo_spinlock, flags);
CHANNEL_OF(tempCommand) = 0;
PTYPE_OF(tempCommand) = PTYPE_BYPASS;
CMD_COUNT_OF(tempCommand) = 1;
(CMD_OF(tempCommand))[0] = 84;
iiWriteBuf(pB, tempCommand, 3);
#ifdef XXX
CHANNEL_OF(tempCommand) = 0;
PTYPE_OF(tempCommand) = PTYPE_BYPASS;
CMD_COUNT_OF(tempCommand) = 2;
(CMD_OF(tempCommand))[0] = 44;
(CMD_OF(tempCommand))[1] = 200;
write_lock_irqsave(&pB->write_fifo_spinlock, flags);
iiWriteBuf(pB, tempCommand, 4);
write_unlock_irqrestore(&pB->write_fifo_spinlock, flags);
#endif
iiEnableMailIrq(pB);
iiSendPendingMail(pB);
}
static inline void
service_all_boards(void)
{
int i;
i2eBordStrPtr pB;
for( i = 0; i < IP2_MAX_BOARDS; ++i ) {
pB = i2BoardPtrTable[i];
if ( pB ) {
i2ServiceBoard( pB );
}
}
}
static void
ip2_interrupt_bh(struct work_struct *work)
{
i2eBordStrPtr pB = container_of(work, i2eBordStr, tqueue_interrupt);
bh_counter++;
if ( pB ) {
i2ServiceBoard( pB );
if( pB->i2eUsingIrq ) {
iiEnableMailIrq(pB);
}
}
}
static void
ip2_irq_work(i2eBordStrPtr pB)
{
#ifdef USE_IQI
if (NO_MAIL_HERE != ( pB->i2eStartMail = iiGetMail(pB))) {
iiDisableMailIrq(pB);
schedule_work(&pB->tqueue_interrupt);
}
#else
i2ServiceBoard( pB );
#endif
}
static void
ip2_polled_interrupt(void)
{
int i;
i2eBordStrPtr pB;
ip2trace(ITRC_NO_PORT, ITRC_INTR, 99, 1, 0);
for( i = 0; i < i2nBoards; ++i ) {
pB = i2BoardPtrTable[i];
if (pB && pB->i2eUsingIrq == 0)
ip2_irq_work(pB);
}
++irq_counter;
ip2trace (ITRC_NO_PORT, ITRC_INTR, ITRC_RETURN, 0 );
}
static irqreturn_t
ip2_interrupt(int irq, void *dev_id)
{
i2eBordStrPtr pB = dev_id;
ip2trace (ITRC_NO_PORT, ITRC_INTR, 99, 1, pB->i2eUsingIrq );
ip2_irq_work(pB);
++irq_counter;
ip2trace (ITRC_NO_PORT, ITRC_INTR, ITRC_RETURN, 0 );
return IRQ_HANDLED;
}
static void
ip2_poll(unsigned long arg)
{
ip2trace (ITRC_NO_PORT, ITRC_INTR, 100, 0 );
ip2_polled_interrupt();
mod_timer(&PollTimer, POLL_TIMEOUT);
ip2trace (ITRC_NO_PORT, ITRC_INTR, ITRC_RETURN, 0 );
}
static void do_input(struct work_struct *work)
{
i2ChanStrPtr pCh = container_of(work, i2ChanStr, tqueue_input);
unsigned long flags;
ip2trace(CHANN, ITRC_INPUT, 21, 0 );
if ( pCh->pTTY != NULL ) {
read_lock_irqsave(&pCh->Ibuf_spinlock, flags);
if (!pCh->throttled && (pCh->Ibuf_stuff != pCh->Ibuf_strip)) {
read_unlock_irqrestore(&pCh->Ibuf_spinlock, flags);
i2Input( pCh );
} else
read_unlock_irqrestore(&pCh->Ibuf_spinlock, flags);
} else {
ip2trace(CHANN, ITRC_INPUT, 22, 0 );
i2InputFlush( pCh );
}
}
static inline void isig(int sig, struct tty_struct *tty, int flush)
{
if (tty->pgrp)
kill_pgrp(tty->pgrp, sig, 1);
if (flush || !L_NOFLSH(tty)) {
if ( tty->ldisc->ops->flush_buffer )
tty->ldisc->ops->flush_buffer(tty);
i2InputFlush( tty->driver_data );
}
}
static void do_status(struct work_struct *work)
{
i2ChanStrPtr pCh = container_of(work, i2ChanStr, tqueue_status);
int status;
status = i2GetStatus( pCh, (I2_BRK|I2_PAR|I2_FRA|I2_OVR) );
ip2trace (CHANN, ITRC_STATUS, 21, 1, status );
if (pCh->pTTY && (status & (I2_BRK|I2_PAR|I2_FRA|I2_OVR)) ) {
if ( (status & I2_BRK) ) {
if (I_IGNBRK(pCh->pTTY))
goto skip_this;
if (I_BRKINT(pCh->pTTY)) {
isig(SIGINT, pCh->pTTY, 1);
goto skip_this;
}
wake_up_interruptible(&pCh->pTTY->read_wait);
}
#ifdef NEVER_HAPPENS_AS_SETUP_XXX
{
char brkf = TTY_NORMAL;
unsigned char brkc = '\0';
unsigned char tmp;
if ( (status & I2_BRK) ) {
brkf = TTY_BREAK;
brkc = '\0';
}
else if (status & I2_PAR) {
brkf = TTY_PARITY;
brkc = the_char;
} else if (status & I2_FRA) {
brkf = TTY_FRAME;
brkc = the_char;
} else if (status & I2_OVR) {
brkf = TTY_OVERRUN;
brkc = the_char;
}
tmp = pCh->pTTY->real_raw;
pCh->pTTY->real_raw = 0;
pCh->pTTY->ldisc->ops.receive_buf( pCh->pTTY, &brkc, &brkf, 1 );
pCh->pTTY->real_raw = tmp;
}
#endif
}
skip_this:
if ( status & (I2_DDCD | I2_DDSR | I2_DCTS | I2_DRI) ) {
wake_up_interruptible(&pCh->delta_msr_wait);
if ( (pCh->flags & ASYNC_CHECK_CD) && (status & I2_DDCD) ) {
if ( status & I2_DCD ) {
if ( pCh->wopen ) {
wake_up_interruptible ( &pCh->open_wait );
}
} else {
if (pCh->pTTY && (!(pCh->pTTY->termios->c_cflag & CLOCAL)) ) {
tty_hangup( pCh->pTTY );
}
}
}
}
ip2trace (CHANN, ITRC_STATUS, 26, 0 );
}
static void
open_sanity_check( i2ChanStrPtr pCh, i2eBordStrPtr pBrd )
{
if ( pBrd->i2eValid != I2E_MAGIC ) {
printk(KERN_ERR "IP2: invalid board structure\n" );
} else if ( pBrd != pCh->pMyBord ) {
printk(KERN_ERR "IP2: board structure pointer mismatch (%p)\n",
pCh->pMyBord );
} else if ( pBrd->i2eChannelCnt < pCh->port_index ) {
printk(KERN_ERR "IP2: bad device index (%d)\n", pCh->port_index );
} else if (&((i2ChanStrPtr)pBrd->i2eChannelPtr)[pCh->port_index] != pCh) {
} else {
printk(KERN_INFO "IP2: all pointers check out!\n" );
}
}
static int
ip2_open( PTTY tty, struct file *pFile )
{
wait_queue_t wait;
int rc = 0;
int do_clocal = 0;
i2ChanStrPtr pCh = DevTable[tty->index];
ip2trace (tty->index, ITRC_OPEN, ITRC_ENTER, 0 );
if ( pCh == NULL ) {
return -ENODEV;
}
pCh->pTTY = tty;
tty->driver_data = pCh;
#ifdef IP2DEBUG_OPEN
printk(KERN_DEBUG \
"IP2:open(tty=%p,pFile=%p):dev=%s,ch=%d,idx=%d\n",
tty, pFile, tty->name, pCh->infl.hd.i2sChannel, pCh->port_index);
open_sanity_check ( pCh, pCh->pMyBord );
#endif
i2QueueCommands(PTYPE_INLINE, pCh, 100, 3, CMD_DTRUP,CMD_RTSUP,CMD_DCD_REP);
pCh->dataSetOut |= (I2_DTR | I2_RTS);
serviceOutgoingFifo( pCh->pMyBord );
init_waitqueue_entry(&wait, current);
add_wait_queue(&pCh->close_wait, &wait);
set_current_state( TASK_INTERRUPTIBLE );
if ( tty_hung_up_p(pFile) || ( pCh->flags & ASYNC_CLOSING )) {
if ( pCh->flags & ASYNC_CLOSING ) {
tty_unlock();
schedule();
tty_lock();
}
if ( tty_hung_up_p(pFile) ) {
set_current_state( TASK_RUNNING );
remove_wait_queue(&pCh->close_wait, &wait);
return( pCh->flags & ASYNC_HUP_NOTIFY ) ? -EAGAIN : -ERESTARTSYS;
}
}
set_current_state( TASK_RUNNING );
remove_wait_queue(&pCh->close_wait, &wait);
if ( (pFile->f_flags & O_NONBLOCK) || (tty->flags & (1<<TTY_IO_ERROR) )) {
pCh->flags |= ASYNC_NORMAL_ACTIVE;
goto noblock;
}
if ( tty->termios->c_cflag & CLOCAL )
do_clocal = 1;
#ifdef IP2DEBUG_OPEN
printk(KERN_DEBUG "OpenBlock: do_clocal = %d\n", do_clocal);
#endif
++pCh->wopen;
init_waitqueue_entry(&wait, current);
add_wait_queue(&pCh->open_wait, &wait);
for(;;) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 2, CMD_DTRUP, CMD_RTSUP);
pCh->dataSetOut |= (I2_DTR | I2_RTS);
set_current_state( TASK_INTERRUPTIBLE );
serviceOutgoingFifo( pCh->pMyBord );
if ( tty_hung_up_p(pFile) ) {
set_current_state( TASK_RUNNING );
remove_wait_queue(&pCh->open_wait, &wait);
return ( pCh->flags & ASYNC_HUP_NOTIFY ) ? -EBUSY : -ERESTARTSYS;
}
if (!(pCh->flags & ASYNC_CLOSING) &&
(do_clocal || (pCh->dataSetIn & I2_DCD) )) {
rc = 0;
break;
}
#ifdef IP2DEBUG_OPEN
printk(KERN_DEBUG "ASYNC_CLOSING = %s\n",
(pCh->flags & ASYNC_CLOSING)?"True":"False");
printk(KERN_DEBUG "OpenBlock: waiting for CD or signal\n");
#endif
ip2trace (CHANN, ITRC_OPEN, 3, 2, 0,
(pCh->flags & ASYNC_CLOSING) );
if (signal_pending(current)) {
rc = (( pCh->flags & ASYNC_HUP_NOTIFY ) ? -EAGAIN : -ERESTARTSYS);
break;
}
tty_unlock();
schedule();
tty_lock();
}
set_current_state( TASK_RUNNING );
remove_wait_queue(&pCh->open_wait, &wait);
--pCh->wopen;
ip2trace (CHANN, ITRC_OPEN, 4, 0 );
if (rc != 0 ) {
return rc;
}
pCh->flags |= ASYNC_NORMAL_ACTIVE;
noblock:
if ( tty->count == 1 ) {
i2QueueCommands(PTYPE_INLINE, pCh, 0, 2, CMD_CTSFL_DSAB, CMD_RTSFL_DSAB);
set_params( pCh, NULL );
}
pCh->channelOptions |= CO_NBLOCK_WRITE;
#ifdef IP2DEBUG_OPEN
printk (KERN_DEBUG "IP2: open completed\n" );
#endif
serviceOutgoingFifo( pCh->pMyBord );
ip2trace (CHANN, ITRC_OPEN, ITRC_RETURN, 0 );
return 0;
}
static void
ip2_close( PTTY tty, struct file *pFile )
{
i2ChanStrPtr pCh = tty->driver_data;
if ( !pCh ) {
return;
}
ip2trace (CHANN, ITRC_CLOSE, ITRC_ENTER, 0 );
#ifdef IP2DEBUG_OPEN
printk(KERN_DEBUG "IP2:close %s:\n",tty->name);
#endif
if ( tty_hung_up_p ( pFile ) ) {
ip2trace (CHANN, ITRC_CLOSE, 2, 1, 2 );
return;
}
if ( tty->count > 1 ) {
ip2trace (CHANN, ITRC_CLOSE, 2, 1, 3 );
return;
}
pCh->flags |= ASYNC_CLOSING;
tty->closing = 1;
if (pCh->ClosingWaitTime != ASYNC_CLOSING_WAIT_NONE) {
ip2_wait_until_sent(tty, pCh->ClosingWaitTime );
}
i2InputFlush( pCh );
i2QueueCommands(PTYPE_INLINE, pCh, 100, 4,
CMD_DCD_NREP, CMD_CTS_NREP, CMD_DSR_NREP, CMD_RI_NREP);
if (tty->termios->c_cflag & HUPCL) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 2, CMD_RTSDN, CMD_DTRDN);
pCh->dataSetOut &= ~(I2_DTR | I2_RTS);
i2QueueCommands( PTYPE_INLINE, pCh, 100, 1, CMD_PAUSE(25));
}
serviceOutgoingFifo ( pCh->pMyBord );
tty_ldisc_flush(tty);
tty_driver_flush_buffer(tty);
tty->closing = 0;
pCh->pTTY = NULL;
if (pCh->wopen) {
if (pCh->ClosingDelay) {
msleep_interruptible(jiffies_to_msecs(pCh->ClosingDelay));
}
wake_up_interruptible(&pCh->open_wait);
}
pCh->flags &=~(ASYNC_NORMAL_ACTIVE|ASYNC_CLOSING);
wake_up_interruptible(&pCh->close_wait);
#ifdef IP2DEBUG_OPEN
DBG_CNT("ip2_close: after wakeups--");
#endif
ip2trace (CHANN, ITRC_CLOSE, ITRC_RETURN, 1, 1 );
return;
}
static void
ip2_hangup ( PTTY tty )
{
i2ChanStrPtr pCh = tty->driver_data;
if( !pCh ) {
return;
}
ip2trace (CHANN, ITRC_HANGUP, ITRC_ENTER, 0 );
ip2_flush_buffer(tty);
i2QueueCommands(PTYPE_BYPASS, pCh, 0, 1, CMD_DCD_NREP);
i2QueueCommands(PTYPE_INLINE, pCh, 0, 2, CMD_CTSFL_DSAB, CMD_RTSFL_DSAB);
if ( (tty->termios->c_cflag & HUPCL) ) {
i2QueueCommands(PTYPE_BYPASS, pCh, 0, 2, CMD_RTSDN, CMD_DTRDN);
pCh->dataSetOut &= ~(I2_DTR | I2_RTS);
i2QueueCommands( PTYPE_INLINE, pCh, 100, 1, CMD_PAUSE(25));
}
i2QueueCommands(PTYPE_INLINE, pCh, 1, 3,
CMD_CTS_NREP, CMD_DSR_NREP, CMD_RI_NREP);
serviceOutgoingFifo ( pCh->pMyBord );
wake_up_interruptible ( &pCh->delta_msr_wait );
pCh->flags &= ~ASYNC_NORMAL_ACTIVE;
pCh->pTTY = NULL;
wake_up_interruptible ( &pCh->open_wait );
ip2trace (CHANN, ITRC_HANGUP, ITRC_RETURN, 0 );
}
static int
ip2_write( PTTY tty, const unsigned char *pData, int count)
{
i2ChanStrPtr pCh = tty->driver_data;
int bytesSent = 0;
unsigned long flags;
ip2trace (CHANN, ITRC_WRITE, ITRC_ENTER, 2, count, -1 );
ip2_flush_chars( tty );
write_lock_irqsave(&pCh->Pbuf_spinlock, flags);
bytesSent = i2Output( pCh, pData, count);
write_unlock_irqrestore(&pCh->Pbuf_spinlock, flags);
ip2trace (CHANN, ITRC_WRITE, ITRC_RETURN, 1, bytesSent );
return bytesSent > 0 ? bytesSent : 0;
}
static int
ip2_putchar( PTTY tty, unsigned char ch )
{
i2ChanStrPtr pCh = tty->driver_data;
unsigned long flags;
write_lock_irqsave(&pCh->Pbuf_spinlock, flags);
pCh->Pbuf[pCh->Pbuf_stuff++] = ch;
if ( pCh->Pbuf_stuff == sizeof pCh->Pbuf ) {
write_unlock_irqrestore(&pCh->Pbuf_spinlock, flags);
ip2_flush_chars( tty );
} else
write_unlock_irqrestore(&pCh->Pbuf_spinlock, flags);
return 1;
}
static void
ip2_flush_chars( PTTY tty )
{
int strip;
i2ChanStrPtr pCh = tty->driver_data;
unsigned long flags;
write_lock_irqsave(&pCh->Pbuf_spinlock, flags);
if ( pCh->Pbuf_stuff ) {
strip = i2Output( pCh, pCh->Pbuf, pCh->Pbuf_stuff);
if ( strip != pCh->Pbuf_stuff ) {
memmove( pCh->Pbuf, &pCh->Pbuf[strip], pCh->Pbuf_stuff - strip );
}
pCh->Pbuf_stuff -= strip;
}
write_unlock_irqrestore(&pCh->Pbuf_spinlock, flags);
}
static int
ip2_write_room ( PTTY tty )
{
int bytesFree;
i2ChanStrPtr pCh = tty->driver_data;
unsigned long flags;
read_lock_irqsave(&pCh->Pbuf_spinlock, flags);
bytesFree = i2OutputFree( pCh ) - pCh->Pbuf_stuff;
read_unlock_irqrestore(&pCh->Pbuf_spinlock, flags);
ip2trace (CHANN, ITRC_WRITE, 11, 1, bytesFree );
return ((bytesFree > 0) ? bytesFree : 0);
}
static int
ip2_chars_in_buf ( PTTY tty )
{
i2ChanStrPtr pCh = tty->driver_data;
int rc;
unsigned long flags;
ip2trace (CHANN, ITRC_WRITE, 12, 1, pCh->Obuf_char_count + pCh->Pbuf_stuff );
#ifdef IP2DEBUG_WRITE
printk (KERN_DEBUG "IP2: chars in buffer = %d (%d,%d)\n",
pCh->Obuf_char_count + pCh->Pbuf_stuff,
pCh->Obuf_char_count, pCh->Pbuf_stuff );
#endif
read_lock_irqsave(&pCh->Obuf_spinlock, flags);
rc = pCh->Obuf_char_count;
read_unlock_irqrestore(&pCh->Obuf_spinlock, flags);
read_lock_irqsave(&pCh->Pbuf_spinlock, flags);
rc += pCh->Pbuf_stuff;
read_unlock_irqrestore(&pCh->Pbuf_spinlock, flags);
return rc;
}
static void
ip2_flush_buffer( PTTY tty )
{
i2ChanStrPtr pCh = tty->driver_data;
unsigned long flags;
ip2trace (CHANN, ITRC_FLUSH, ITRC_ENTER, 0 );
#ifdef IP2DEBUG_WRITE
printk (KERN_DEBUG "IP2: flush buffer\n" );
#endif
write_lock_irqsave(&pCh->Pbuf_spinlock, flags);
pCh->Pbuf_stuff = 0;
write_unlock_irqrestore(&pCh->Pbuf_spinlock, flags);
i2FlushOutput( pCh );
ip2_owake(tty);
ip2trace (CHANN, ITRC_FLUSH, ITRC_RETURN, 0 );
}
static void
ip2_wait_until_sent ( PTTY tty, int timeout )
{
int i = jiffies;
i2ChanStrPtr pCh = tty->driver_data;
tty_wait_until_sent(tty, timeout );
if ( (i = timeout - (jiffies -i)) > 0)
i2DrainOutput( pCh, i );
}
static void
ip2_throttle ( PTTY tty )
{
i2ChanStrPtr pCh = tty->driver_data;
#ifdef IP2DEBUG_READ
printk (KERN_DEBUG "IP2: throttle\n" );
#endif
pCh->throttled = 1;
}
static void
ip2_unthrottle ( PTTY tty )
{
i2ChanStrPtr pCh = tty->driver_data;
unsigned long flags;
#ifdef IP2DEBUG_READ
printk (KERN_DEBUG "IP2: unthrottle\n" );
#endif
pCh->throttled = 0;
i2QueueCommands(PTYPE_BYPASS, pCh, 0, 1, CMD_RESUME);
serviceOutgoingFifo( pCh->pMyBord );
read_lock_irqsave(&pCh->Ibuf_spinlock, flags);
if ( pCh->Ibuf_stuff != pCh->Ibuf_strip ) {
read_unlock_irqrestore(&pCh->Ibuf_spinlock, flags);
#ifdef IP2DEBUG_READ
printk (KERN_DEBUG "i2Input called from unthrottle\n" );
#endif
i2Input( pCh );
} else
read_unlock_irqrestore(&pCh->Ibuf_spinlock, flags);
}
static void
ip2_start ( PTTY tty )
{
i2ChanStrPtr pCh = DevTable[tty->index];
i2QueueCommands(PTYPE_BYPASS, pCh, 0, 1, CMD_RESUME);
i2QueueCommands(PTYPE_BYPASS, pCh, 100, 1, CMD_UNSUSPEND);
i2QueueCommands(PTYPE_BYPASS, pCh, 100, 1, CMD_RESUME);
#ifdef IP2DEBUG_WRITE
printk (KERN_DEBUG "IP2: start tx\n" );
#endif
}
static void
ip2_stop ( PTTY tty )
{
i2ChanStrPtr pCh = DevTable[tty->index];
i2QueueCommands(PTYPE_BYPASS, pCh, 100, 1, CMD_SUSPEND);
#ifdef IP2DEBUG_WRITE
printk (KERN_DEBUG "IP2: stop tx\n" );
#endif
}
static int ip2_tiocmget(struct tty_struct *tty)
{
i2ChanStrPtr pCh = DevTable[tty->index];
#ifdef ENABLE_DSSNOW
wait_queue_t wait;
#endif
if (pCh == NULL)
return -ENODEV;
#ifdef ENABLE_DSSNOW
i2QueueCommands(PTYPE_BYPASS, pCh, 100, 1, CMD_DSS_NOW);
init_waitqueue_entry(&wait, current);
add_wait_queue(&pCh->dss_now_wait, &wait);
set_current_state( TASK_INTERRUPTIBLE );
serviceOutgoingFifo( pCh->pMyBord );
schedule();
set_current_state( TASK_RUNNING );
remove_wait_queue(&pCh->dss_now_wait, &wait);
if (signal_pending(current)) {
return -EINTR;
}
#endif
return ((pCh->dataSetOut & I2_RTS) ? TIOCM_RTS : 0)
| ((pCh->dataSetOut & I2_DTR) ? TIOCM_DTR : 0)
| ((pCh->dataSetIn & I2_DCD) ? TIOCM_CAR : 0)
| ((pCh->dataSetIn & I2_RI) ? TIOCM_RNG : 0)
| ((pCh->dataSetIn & I2_DSR) ? TIOCM_DSR : 0)
| ((pCh->dataSetIn & I2_CTS) ? TIOCM_CTS : 0);
}
static int ip2_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
i2ChanStrPtr pCh = DevTable[tty->index];
if (pCh == NULL)
return -ENODEV;
if (set & TIOCM_RTS) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_RTSUP);
pCh->dataSetOut |= I2_RTS;
}
if (set & TIOCM_DTR) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_DTRUP);
pCh->dataSetOut |= I2_DTR;
}
if (clear & TIOCM_RTS) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_RTSDN);
pCh->dataSetOut &= ~I2_RTS;
}
if (clear & TIOCM_DTR) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_DTRDN);
pCh->dataSetOut &= ~I2_DTR;
}
serviceOutgoingFifo( pCh->pMyBord );
return 0;
}
static int
ip2_ioctl ( PTTY tty, UINT cmd, ULONG arg )
{
wait_queue_t wait;
i2ChanStrPtr pCh = DevTable[tty->index];
i2eBordStrPtr pB;
struct async_icount cprev, cnow;
int rc = 0;
unsigned long flags;
void __user *argp = (void __user *)arg;
if ( pCh == NULL )
return -ENODEV;
pB = pCh->pMyBord;
ip2trace (CHANN, ITRC_IOCTL, ITRC_ENTER, 2, cmd, arg );
#ifdef IP2DEBUG_IOCTL
printk(KERN_DEBUG "IP2: ioctl cmd (%x), arg (%lx)\n", cmd, arg );
#endif
switch(cmd) {
case TIOCGSERIAL:
ip2trace (CHANN, ITRC_IOCTL, 2, 1, rc );
rc = get_serial_info(pCh, argp);
if (rc)
return rc;
break;
case TIOCSSERIAL:
ip2trace (CHANN, ITRC_IOCTL, 3, 1, rc );
rc = set_serial_info(pCh, argp);
if (rc)
return rc;
break;
case TCXONC:
rc = tty_check_change(tty);
if (rc)
return rc;
switch (arg) {
case TCOOFF:
break;
case TCOON:
break;
case TCIOFF:
if (STOP_CHAR(tty) != __DISABLED_CHAR) {
i2QueueCommands( PTYPE_BYPASS, pCh, 100, 1,
CMD_XMIT_NOW(STOP_CHAR(tty)));
}
break;
case TCION:
if (START_CHAR(tty) != __DISABLED_CHAR) {
i2QueueCommands( PTYPE_BYPASS, pCh, 100, 1,
CMD_XMIT_NOW(START_CHAR(tty)));
}
break;
default:
return -EINVAL;
}
return 0;
case TCSBRK:
rc = tty_check_change(tty);
ip2trace (CHANN, ITRC_IOCTL, 4, 1, rc );
if (!rc) {
ip2_wait_until_sent(tty,0);
if (!arg) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_SEND_BRK(250));
serviceOutgoingFifo( pCh->pMyBord );
}
}
break;
case TCSBRKP:
rc = tty_check_change(tty);
ip2trace (CHANN, ITRC_IOCTL, 5, 1, rc );
if (!rc) {
ip2_wait_until_sent(tty,0);
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1,
CMD_SEND_BRK(arg ? arg*100 : 250));
serviceOutgoingFifo ( pCh->pMyBord );
}
break;
case TIOCGSOFTCAR:
ip2trace (CHANN, ITRC_IOCTL, 6, 1, rc );
rc = put_user(C_CLOCAL(tty) ? 1 : 0, (unsigned long __user *)argp);
if (rc)
return rc;
break;
case TIOCSSOFTCAR:
ip2trace (CHANN, ITRC_IOCTL, 7, 1, rc );
rc = get_user(arg,(unsigned long __user *) argp);
if (rc)
return rc;
tty->termios->c_cflag = ((tty->termios->c_cflag & ~CLOCAL)
| (arg ? CLOCAL : 0));
break;
case TIOCMIWAIT:
write_lock_irqsave(&pB->read_fifo_spinlock, flags);
cprev = pCh->icount;
write_unlock_irqrestore(&pB->read_fifo_spinlock, flags);
i2QueueCommands(PTYPE_BYPASS, pCh, 100, 4,
CMD_DCD_REP, CMD_CTS_REP, CMD_DSR_REP, CMD_RI_REP);
init_waitqueue_entry(&wait, current);
add_wait_queue(&pCh->delta_msr_wait, &wait);
set_current_state( TASK_INTERRUPTIBLE );
serviceOutgoingFifo( pCh->pMyBord );
for(;;) {
ip2trace (CHANN, ITRC_IOCTL, 10, 0 );
schedule();
ip2trace (CHANN, ITRC_IOCTL, 11, 0 );
if (signal_pending(current)) {
rc = -ERESTARTSYS;
break;
}
write_lock_irqsave(&pB->read_fifo_spinlock, flags);
cnow = pCh->icount;
write_unlock_irqrestore(&pB->read_fifo_spinlock, flags);
if (cnow.rng == cprev.rng && cnow.dsr == cprev.dsr &&
cnow.dcd == cprev.dcd && cnow.cts == cprev.cts) {
rc = -EIO;
break;
}
if (((arg & TIOCM_RNG) && (cnow.rng != cprev.rng)) ||
((arg & TIOCM_DSR) && (cnow.dsr != cprev.dsr)) ||
((arg & TIOCM_CD) && (cnow.dcd != cprev.dcd)) ||
((arg & TIOCM_CTS) && (cnow.cts != cprev.cts)) ) {
rc = 0;
break;
}
cprev = cnow;
}
set_current_state( TASK_RUNNING );
remove_wait_queue(&pCh->delta_msr_wait, &wait);
i2QueueCommands(PTYPE_BYPASS, pCh, 100, 3,
CMD_CTS_NREP, CMD_DSR_NREP, CMD_RI_NREP);
if ( ! (pCh->flags & ASYNC_CHECK_CD)) {
i2QueueCommands(PTYPE_BYPASS, pCh, 100, 1, CMD_DCD_NREP);
}
serviceOutgoingFifo( pCh->pMyBord );
return rc;
break;
case TIOCSERCONFIG:
case TIOCSERGWILD:
case TIOCSERGETLSR:
case TIOCSERSWILD:
case TIOCSERGSTRUCT:
case TIOCSERGETMULTI:
case TIOCSERSETMULTI:
default:
ip2trace (CHANN, ITRC_IOCTL, 12, 0 );
rc = -ENOIOCTLCMD;
break;
}
ip2trace (CHANN, ITRC_IOCTL, ITRC_RETURN, 0 );
return rc;
}
static int ip2_get_icount(struct tty_struct *tty,
struct serial_icounter_struct *icount)
{
i2ChanStrPtr pCh = DevTable[tty->index];
i2eBordStrPtr pB;
struct async_icount cnow;
unsigned long flags;
if ( pCh == NULL )
return -ENODEV;
pB = pCh->pMyBord;
write_lock_irqsave(&pB->read_fifo_spinlock, flags);
cnow = pCh->icount;
write_unlock_irqrestore(&pB->read_fifo_spinlock, flags);
icount->cts = cnow.cts;
icount->dsr = cnow.dsr;
icount->rng = cnow.rng;
icount->dcd = cnow.dcd;
icount->rx = cnow.rx;
icount->tx = cnow.tx;
icount->frame = cnow.frame;
icount->overrun = cnow.overrun;
icount->parity = cnow.parity;
icount->brk = cnow.brk;
icount->buf_overrun = cnow.buf_overrun;
return 0;
}
static int
get_serial_info ( i2ChanStrPtr pCh, struct serial_struct __user *retinfo )
{
struct serial_struct tmp;
memset ( &tmp, 0, sizeof(tmp) );
tmp.type = pCh->pMyBord->channelBtypes.bid_value[(pCh->port_index & (IP2_PORTS_PER_BOARD-1))/16];
if (BID_HAS_654(tmp.type)) {
tmp.type = PORT_16650;
} else {
tmp.type = PORT_CIRRUS;
}
tmp.line = pCh->port_index;
tmp.port = pCh->pMyBord->i2eBase;
tmp.irq = ip2config.irq[pCh->port_index/64];
tmp.flags = pCh->flags;
tmp.baud_base = pCh->BaudBase;
tmp.close_delay = pCh->ClosingDelay;
tmp.closing_wait = pCh->ClosingWaitTime;
tmp.custom_divisor = pCh->BaudDivisor;
return copy_to_user(retinfo,&tmp,sizeof(*retinfo));
}
static int
set_serial_info( i2ChanStrPtr pCh, struct serial_struct __user *new_info )
{
struct serial_struct ns;
int old_flags, old_baud_divisor;
if (copy_from_user(&ns, new_info, sizeof (ns)))
return -EFAULT;
if ( (ns.irq != ip2config.irq[pCh->port_index])
|| ((int) ns.port != ((int) (pCh->pMyBord->i2eBase)))
|| (ns.baud_base != pCh->BaudBase)
|| (ns.line != pCh->port_index) ) {
return -EINVAL;
}
old_flags = pCh->flags;
old_baud_divisor = pCh->BaudDivisor;
if ( !capable(CAP_SYS_ADMIN) ) {
if ( ( ns.close_delay != pCh->ClosingDelay ) ||
( (ns.flags & ~ASYNC_USR_MASK) !=
(pCh->flags & ~ASYNC_USR_MASK) ) ) {
return -EPERM;
}
pCh->flags = (pCh->flags & ~ASYNC_USR_MASK) |
(ns.flags & ASYNC_USR_MASK);
pCh->BaudDivisor = ns.custom_divisor;
} else {
pCh->flags = (pCh->flags & ~ASYNC_FLAGS) |
(ns.flags & ASYNC_FLAGS);
pCh->BaudDivisor = ns.custom_divisor;
pCh->ClosingDelay = ns.close_delay * HZ/100;
pCh->ClosingWaitTime = ns.closing_wait * HZ/100;
}
if ( ( (old_flags & ASYNC_SPD_MASK) != (pCh->flags & ASYNC_SPD_MASK) )
|| (old_baud_divisor != pCh->BaudDivisor) ) {
set_params( pCh, NULL );
}
return 0;
}
static void
ip2_set_termios( PTTY tty, struct ktermios *old_termios )
{
i2ChanStrPtr pCh = (i2ChanStrPtr)tty->driver_data;
#ifdef IP2DEBUG_IOCTL
printk (KERN_DEBUG "IP2: set termios %p\n", old_termios );
#endif
set_params( pCh, old_termios );
}
static void
ip2_set_line_discipline ( PTTY tty )
{
#ifdef IP2DEBUG_IOCTL
printk (KERN_DEBUG "IP2: set line discipline\n" );
#endif
ip2trace (((i2ChanStrPtr)tty->driver_data)->port_index, ITRC_IOCTL, 16, 0 );
}
static void
set_params( i2ChanStrPtr pCh, struct ktermios *o_tios )
{
tcflag_t cflag, iflag, lflag;
char stop_char, start_char;
struct ktermios dummy;
lflag = pCh->pTTY->termios->c_lflag;
cflag = pCh->pTTY->termios->c_cflag;
iflag = pCh->pTTY->termios->c_iflag;
if (o_tios == NULL) {
dummy.c_lflag = ~lflag;
dummy.c_cflag = ~cflag;
dummy.c_iflag = ~iflag;
o_tios = &dummy;
}
{
switch ( cflag & CBAUD ) {
case B0:
i2QueueCommands( PTYPE_BYPASS, pCh, 100, 2, CMD_RTSDN, CMD_DTRDN);
pCh->dataSetOut &= ~(I2_DTR | I2_RTS);
i2QueueCommands( PTYPE_INLINE, pCh, 100, 1, CMD_PAUSE(25));
pCh->pTTY->termios->c_cflag |= (CBAUD & o_tios->c_cflag);
goto service_it;
break;
case B38400:
if ( ( pCh->flags & ASYNC_SPD_MASK ) == ASYNC_SPD_HI ) {
pCh->speed = CBR_57600;
} else if ( (pCh->flags & ASYNC_SPD_MASK) == ASYNC_SPD_VHI ) {
pCh->speed = CBR_115200;
} else if ( (pCh->flags & ASYNC_SPD_MASK) == ASYNC_SPD_CUST ) {
pCh->speed = CBR_C1;
} else {
pCh->speed = CBR_38400;
}
break;
case B50: pCh->speed = CBR_50; break;
case B75: pCh->speed = CBR_75; break;
case B110: pCh->speed = CBR_110; break;
case B134: pCh->speed = CBR_134; break;
case B150: pCh->speed = CBR_150; break;
case B200: pCh->speed = CBR_200; break;
case B300: pCh->speed = CBR_300; break;
case B600: pCh->speed = CBR_600; break;
case B1200: pCh->speed = CBR_1200; break;
case B1800: pCh->speed = CBR_1800; break;
case B2400: pCh->speed = CBR_2400; break;
case B4800: pCh->speed = CBR_4800; break;
case B9600: pCh->speed = CBR_9600; break;
case B19200: pCh->speed = CBR_19200; break;
case B57600: pCh->speed = CBR_57600; break;
case B115200: pCh->speed = CBR_115200; break;
case B153600: pCh->speed = CBR_153600; break;
case B230400: pCh->speed = CBR_230400; break;
case B307200: pCh->speed = CBR_307200; break;
case B460800: pCh->speed = CBR_460800; break;
case B921600: pCh->speed = CBR_921600; break;
default: pCh->speed = CBR_9600; break;
}
if ( pCh->speed == CBR_C1 ) {
int bps = pCh->BaudBase / pCh->BaudDivisor;
if ( bps == 921600 ) {
pCh->speed = CBR_921600;
} else {
bps = bps/10;
i2QueueCommands( PTYPE_INLINE, pCh, 100, 1, CMD_BAUD_DEF1(bps) );
}
}
i2QueueCommands( PTYPE_INLINE, pCh, 100, 1, CMD_SETBAUD(pCh->speed));
i2QueueCommands ( PTYPE_INLINE, pCh, 100, 2, CMD_DTRUP, CMD_RTSUP);
pCh->dataSetOut |= (I2_DTR | I2_RTS);
}
if ( (CSTOPB & cflag) ^ (CSTOPB & o_tios->c_cflag))
{
i2QueueCommands ( PTYPE_INLINE, pCh, 100, 1,
CMD_SETSTOP( ( cflag & CSTOPB ) ? CST_2 : CST_1));
}
if (((PARENB|PARODD) & cflag) ^ ((PARENB|PARODD) & o_tios->c_cflag))
{
i2QueueCommands ( PTYPE_INLINE, pCh, 100, 1,
CMD_SETPAR(
(cflag & PARENB ? (cflag & PARODD ? CSP_OD : CSP_EV) : CSP_NP)
)
);
}
if ( (CSIZE & cflag)^(CSIZE & o_tios->c_cflag))
{
int datasize;
switch ( cflag & CSIZE ) {
case CS5: datasize = CSZ_5; break;
case CS6: datasize = CSZ_6; break;
case CS7: datasize = CSZ_7; break;
case CS8: datasize = CSZ_8; break;
default: datasize = CSZ_5; break;
}
i2QueueCommands ( PTYPE_INLINE, pCh, 100, 1, CMD_SETBITS(datasize) );
}
if ( (cflag & CRTSCTS) ) {
i2QueueCommands(PTYPE_INLINE, pCh, 100,
2, CMD_CTSFL_ENAB, CMD_RTSFL_ENAB);
} else {
i2QueueCommands(PTYPE_INLINE, pCh, 100,
2, CMD_CTSFL_DSAB, CMD_RTSFL_DSAB);
}
stop_char = STOP_CHAR(pCh->pTTY);
start_char = START_CHAR(pCh->pTTY);
if (stop_char == __DISABLED_CHAR )
{
stop_char = ~__DISABLED_CHAR;
}
if (start_char == __DISABLED_CHAR )
{
start_char = ~__DISABLED_CHAR;
}
if ( o_tios->c_cc[VSTART] != start_char )
{
i2QueueCommands(PTYPE_BYPASS, pCh, 100, 1, CMD_DEF_IXON(start_char));
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_DEF_OXON(start_char));
}
if ( o_tios->c_cc[VSTOP] != stop_char )
{
i2QueueCommands(PTYPE_BYPASS, pCh, 100, 1, CMD_DEF_IXOFF(stop_char));
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_DEF_OXOFF(stop_char));
}
if (stop_char == __DISABLED_CHAR )
{
stop_char = ~__DISABLED_CHAR;
goto no_xoff;
}
if ((iflag & (IXOFF))^(o_tios->c_iflag & (IXOFF)))
{
if ( iflag & IXOFF ) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_OXON_OPT(COX_XON));
} else {
no_xoff:
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_OXON_OPT(COX_NONE));
}
}
if (start_char == __DISABLED_CHAR )
{
goto no_xon;
}
if ((iflag & (IXON|IXANY)) ^ (o_tios->c_iflag & (IXON|IXANY)))
{
if ( iflag & IXON ) {
if ( iflag & IXANY ) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_IXON_OPT(CIX_XANY));
} else {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_IXON_OPT(CIX_XON));
}
} else {
no_xon:
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_IXON_OPT(CIX_NONE));
}
}
if ( (iflag & ISTRIP) ^ ( o_tios->c_iflag & (ISTRIP)) )
{
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1,
CMD_ISTRIP_OPT((iflag & ISTRIP ? 1 : 0)));
}
if ( (iflag & INPCK) ^ ( o_tios->c_iflag & (INPCK)) )
{
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1,
CMD_PARCHK((iflag & INPCK) ? CPK_ENAB : CPK_DSAB));
}
if ( (iflag & (IGNBRK|PARMRK|BRKINT|IGNPAR))
^ ( o_tios->c_iflag & (IGNBRK|PARMRK|BRKINT|IGNPAR)) )
{
char brkrpt = 0;
char parrpt = 0;
if ( iflag & IGNBRK ) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_BRK_NREP);
} else {
if ( iflag & BRKINT ) {
if ( iflag & PARMRK ) {
brkrpt = 0x0a;
} else {
brkrpt = 0x1a;
}
brkrpt |= 0x04;
} else {
if ( iflag & PARMRK ) {
brkrpt = 0x0b;
} else {
brkrpt = 0x01;
}
}
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_BRK_REP(brkrpt));
}
if (iflag & IGNPAR) {
parrpt = 0x20;
} else {
if ( iflag & PARMRK ) {
parrpt = 0x04 ;
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_ISTRIP_OPT((char)0));
} else {
parrpt = 0x03;
}
}
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_SET_ERROR(parrpt));
}
if (cflag & CLOCAL) {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_DCD_NREP);
pCh->flags &= ~ASYNC_CHECK_CD;
} else {
i2QueueCommands(PTYPE_INLINE, pCh, 100, 1, CMD_DCD_REP);
pCh->flags |= ASYNC_CHECK_CD;
}
service_it:
i2DrainOutput( pCh, 100 );
}
static
ssize_t
ip2_ipl_read(struct file *pFile, char __user *pData, size_t count, loff_t *off )
{
unsigned int minor = iminor(pFile->f_path.dentry->d_inode);
int rc = 0;
#ifdef IP2DEBUG_IPL
printk (KERN_DEBUG "IP2IPL: read %p, %d bytes\n", pData, count );
#endif
switch( minor ) {
case 0:
rc = -EINVAL;
break;
case 1:
rc = -EINVAL;
break;
case 2:
rc = -EINVAL;
break;
case 3:
rc = DumpTraceBuffer ( pData, count );
break;
case 4:
rc = DumpFifoBuffer ( pData, count );
break;
default:
rc = -ENODEV;
break;
}
return rc;
}
static int
DumpFifoBuffer ( char __user *pData, int count )
{
#ifdef DEBUG_FIFO
int rc;
rc = copy_to_user(pData, DBGBuf, count);
printk(KERN_DEBUG "Last index %d\n", I );
return count;
#endif
return 0;
}
static int
DumpTraceBuffer ( char __user *pData, int count )
{
#ifdef IP2DEBUG_TRACE
int rc;
int dumpcount;
int chunk;
int *pIndex = (int __user *)pData;
if ( count < (sizeof(int) * 6) ) {
return -EIO;
}
rc = put_user(tracewrap, pIndex );
rc = put_user(TRACEMAX, ++pIndex );
rc = put_user(tracestrip, ++pIndex );
rc = put_user(tracestuff, ++pIndex );
pData += sizeof(int) * 6;
count -= sizeof(int) * 6;
dumpcount = tracestuff - tracestrip;
if ( dumpcount < 0 ) {
dumpcount += TRACEMAX;
}
if ( dumpcount > count ) {
dumpcount = count;
}
chunk = TRACEMAX - tracestrip;
if ( dumpcount > chunk ) {
rc = copy_to_user(pData, &tracebuf[tracestrip],
chunk * sizeof(tracebuf[0]) );
pData += chunk * sizeof(tracebuf[0]);
tracestrip = 0;
chunk = dumpcount - chunk;
} else {
chunk = dumpcount;
}
rc = copy_to_user(pData, &tracebuf[tracestrip],
chunk * sizeof(tracebuf[0]) );
tracestrip += chunk;
tracewrap = 0;
rc = put_user(tracestrip, ++pIndex );
rc = put_user(tracestuff, ++pIndex );
return dumpcount;
#else
return 0;
#endif
}
static ssize_t
ip2_ipl_write(struct file *pFile, const char __user *pData, size_t count, loff_t *off)
{
#ifdef IP2DEBUG_IPL
printk (KERN_DEBUG "IP2IPL: write %p, %d bytes\n", pData, count );
#endif
return 0;
}
static long
ip2_ipl_ioctl (struct file *pFile, UINT cmd, ULONG arg )
{
unsigned int iplminor = iminor(pFile->f_path.dentry->d_inode);
int rc = 0;
void __user *argp = (void __user *)arg;
ULONG __user *pIndex = argp;
i2eBordStrPtr pB = i2BoardPtrTable[iplminor / 4];
i2ChanStrPtr pCh;
#ifdef IP2DEBUG_IPL
printk (KERN_DEBUG "IP2IPL: ioctl cmd %d, arg %ld\n", cmd, arg );
#endif
mutex_lock(&ip2_mutex);
switch ( iplminor ) {
case 0:
rc = -EINVAL;
break;
case 1:
case 5:
case 9:
case 13:
switch ( cmd ) {
case 64:
rc = put_user(-1, pIndex++ );
rc = put_user(irq_counter, pIndex++ );
rc = put_user(bh_counter, pIndex++ );
break;
case 65:
if ( pB ) {
rc = copy_to_user(argp, pB, sizeof(i2eBordStr));
rc = put_user(inb(pB->i2eStatus),
(ULONG __user *)(arg + (ULONG)(&pB->i2eStatus) - (ULONG)pB ) );
} else {
rc = -ENODEV;
}
break;
default:
if (cmd < IP2_MAX_PORTS) {
pCh = DevTable[cmd];
if ( pCh )
{
rc = copy_to_user(argp, pCh, sizeof(i2ChanStr));
if (rc)
rc = -EFAULT;
} else {
rc = -ENODEV;
}
} else {
rc = -EINVAL;
}
}
break;
case 2:
rc = -EINVAL;
break;
case 3:
if (cmd == 1)
rc = 0;
else
rc = -EINVAL;
break;
default:
rc = -ENODEV;
break;
}
mutex_unlock(&ip2_mutex);
return rc;
}
static int
ip2_ipl_open( struct inode *pInode, struct file *pFile )
{
#ifdef IP2DEBUG_IPL
printk (KERN_DEBUG "IP2IPL: open\n" );
#endif
return 0;
}
static int
proc_ip2mem_show(struct seq_file *m, void *v)
{
i2eBordStrPtr pB;
i2ChanStrPtr pCh;
PTTY tty;
int i;
#define FMTLINE "%3d: 0x%08x 0x%08x 0%011o 0%011o\n"
#define FMTLIN2 " 0x%04x 0x%04x tx flow 0x%x\n"
#define FMTLIN3 " 0x%04x 0x%04x rc flow\n"
seq_printf(m,"\n");
for( i = 0; i < IP2_MAX_BOARDS; ++i ) {
pB = i2BoardPtrTable[i];
if ( pB ) {
seq_printf(m,"board %d:\n",i);
seq_printf(m,"\tFifo rem: %d mty: %x outM %x\n",
pB->i2eFifoRemains,pB->i2eWaitingForEmptyFifo,pB->i2eOutMailWaiting);
}
}
seq_printf(m,"#: tty flags, port flags, cflags, iflags\n");
for (i=0; i < IP2_MAX_PORTS; i++) {
pCh = DevTable[i];
if (pCh) {
tty = pCh->pTTY;
if (tty && tty->count) {
seq_printf(m,FMTLINE,i,(int)tty->flags,pCh->flags,
tty->termios->c_cflag,tty->termios->c_iflag);
seq_printf(m,FMTLIN2,
pCh->outfl.asof,pCh->outfl.room,pCh->channelNeeds);
seq_printf(m,FMTLIN3,pCh->infl.asof,pCh->infl.room);
}
}
}
return 0;
}
static int proc_ip2mem_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_ip2mem_show, NULL);
}
static int ip2_proc_show(struct seq_file *m, void *v)
{
int i, j, box;
int boxes = 0;
int ports = 0;
int tports = 0;
i2eBordStrPtr pB;
char *sep;
seq_printf(m, "ip2info: 1.0 driver: %s\n", pcVersion);
seq_printf(m, "Driver: SMajor=%d CMajor=%d IMajor=%d MaxBoards=%d MaxBoxes=%d MaxPorts=%d\n",
IP2_TTY_MAJOR, IP2_CALLOUT_MAJOR, IP2_IPL_MAJOR,
IP2_MAX_BOARDS, ABS_MAX_BOXES, ABS_BIGGEST_BOX);
for( i = 0; i < IP2_MAX_BOARDS; ++i ) {
boxes = 0;
pB = i2BoardPtrTable[i];
if( pB ) {
switch( pB->i2ePom.e.porID & ~POR_ID_RESERVED )
{
case POR_ID_FIIEX:
seq_printf(m, "Board %d: EX ports=", i);
sep = "";
for( box = 0; box < ABS_MAX_BOXES; ++box )
{
ports = 0;
if( pB->i2eChannelMap[box] != 0 ) ++boxes;
for( j = 0; j < ABS_BIGGEST_BOX; ++j )
{
if( pB->i2eChannelMap[box] & 1<< j ) {
++ports;
}
}
seq_printf(m, "%s%d", sep, ports);
sep = ",";
tports += ports;
}
seq_printf(m, " boxes=%d width=%d", boxes, pB->i2eDataWidth16 ? 16 : 8);
break;
case POR_ID_II_4:
seq_printf(m, "Board %d: ISA-4 ports=4 boxes=1", i);
tports = ports = 4;
break;
case POR_ID_II_8:
seq_printf(m, "Board %d: ISA-8-std ports=8 boxes=1", i);
tports = ports = 8;
break;
case POR_ID_II_8R:
seq_printf(m, "Board %d: ISA-8-RJ11 ports=8 boxes=1", i);
tports = ports = 8;
break;
default:
seq_printf(m, "Board %d: unknown", i);
tports = ports = 0;
}
} else {
seq_printf(m, "Board %d: vacant", i);
tports = ports = 0;
}
if( tports ) {
seq_puts(m, " minors=");
sep = "";
for ( box = 0; box < ABS_MAX_BOXES; ++box )
{
for ( j = 0; j < ABS_BIGGEST_BOX; ++j )
{
if ( pB->i2eChannelMap[box] & (1 << j) )
{
seq_printf(m, "%s%d", sep,
j + ABS_BIGGEST_BOX *
(box+i*ABS_MAX_BOXES));
sep = ",";
}
}
}
}
seq_putc(m, '\n');
}
return 0;
}
static int ip2_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, ip2_proc_show, NULL);
}
void
ip2trace (unsigned short pn, unsigned char cat, unsigned char label, unsigned long codes, ...)
{
long flags;
unsigned long *pCode = &codes;
union ip2breadcrumb bc;
i2ChanStrPtr pCh;
tracebuf[tracestuff++] = jiffies;
if ( tracestuff == TRACEMAX ) {
tracestuff = 0;
}
if ( tracestuff == tracestrip ) {
if ( ++tracestrip == TRACEMAX ) {
tracestrip = 0;
}
++tracewrap;
}
bc.hdr.port = 0xff & pn;
bc.hdr.cat = cat;
bc.hdr.codes = (unsigned char)( codes & 0xff );
bc.hdr.label = label;
tracebuf[tracestuff++] = bc.value;
for (;;) {
if ( tracestuff == TRACEMAX ) {
tracestuff = 0;
}
if ( tracestuff == tracestrip ) {
if ( ++tracestrip == TRACEMAX ) {
tracestrip = 0;
}
++tracewrap;
}
if ( !codes-- )
break;
tracebuf[tracestuff++] = *++pCode;
}
}
