int dgnc_init_module(void)
{
int rc = 0;
APR(("%s, Digi International Part Number %s\n", DG_NAME, DG_PART));
rc = dgnc_start();
if (rc < 0) {
return(rc);
}
rc = dgnc_init_pci();
if (rc < 0) {
if (dgnc_NumBoards)
pci_unregister_driver(&dgnc_driver);
else
printk("WARNING: dgnc driver load failed. No Digi Neo or Classic boards found.\n");
dgnc_cleanup_module();
}
else {
dgnc_create_driver_sysfiles(&dgnc_driver);
}
DPR_INIT(("Finished init_module. Returning %d\n", rc));
return (rc);
}
static int dgnc_start(void)
{
int rc = 0;
unsigned long flags;
if (dgnc_driver_start == FALSE) {
dgnc_driver_start = TRUE;
dgnc_init_globals();
dgnc_NumBoards = 0;
APR(("For the tools package or updated drivers please visit http://www.digi.com\n"));
if (!dgnc_Major_Control_Registered) {
rc = register_chrdev(0, "dgnc", &dgnc_BoardFops);
if (rc <= 0) {
APR(("Can't register dgnc driver device (%d)\n", rc));
rc = -ENXIO;
return(rc);
}
dgnc_Major = rc;
dgnc_class = class_create(THIS_MODULE, "dgnc_mgmt");
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,28)
device_create_drvdata(dgnc_class, NULL,
MKDEV(dgnc_Major, 0),
NULL, "dgnc_mgmt");
#else
device_create(dgnc_class, NULL,
MKDEV(dgnc_Major, 0),
NULL, "dgnc_mgmt");
#endif
dgnc_Major_Control_Registered = TRUE;
}
rc = dgnc_tty_preinit();
if (rc < 0) {
APR(("tty preinit - not enough memory (%d)\n", rc));
return(rc);
}
DGNC_LOCK(dgnc_poll_lock, flags);
init_timer(&dgnc_poll_timer);
dgnc_poll_timer.function = dgnc_poll_handler;
dgnc_poll_timer.data = 0;
dgnc_poll_time = jiffies + dgnc_jiffies_from_ms(dgnc_poll_tick);
dgnc_poll_timer.expires = dgnc_poll_time;
DGNC_UNLOCK(dgnc_poll_lock, flags);
add_timer(&dgnc_poll_timer);
dgnc_driver_state = DRIVER_READY;
}
return(rc);
}
static int dgnc_init_pci(void)
{
return pci_register_driver(&dgnc_driver);
}
static int dgnc_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc;
rc = pci_enable_device(pdev);
if (rc < 0) {
rc = -EIO;
} else {
rc = dgnc_probe1(pdev, ent->driver_data);
if (rc == 0) {
dgnc_NumBoards++;
DPR_INIT(("Incrementing numboards to %d\n", dgnc_NumBoards));
}
}
return rc;
}
static int dgnc_probe1(struct pci_dev *pdev, int card_type)
{
return dgnc_found_board(pdev, card_type);
}
static void dgnc_remove_one(struct pci_dev *dev)
{
}
void dgnc_cleanup_module(void)
{
int i;
ulong lock_flags;
DGNC_LOCK(dgnc_poll_lock, lock_flags);
dgnc_poll_stop = 1;
DGNC_UNLOCK(dgnc_poll_lock, lock_flags);
del_timer_sync(&dgnc_poll_timer);
dgnc_remove_driver_sysfiles(&dgnc_driver);
if (dgnc_Major_Control_Registered) {
device_destroy(dgnc_class, MKDEV(dgnc_Major, 0));
class_destroy(dgnc_class);
unregister_chrdev(dgnc_Major, "dgnc");
}
for (i = 0; i < dgnc_NumBoards; ++i) {
dgnc_remove_ports_sysfiles(dgnc_Board[i]);
dgnc_tty_uninit(dgnc_Board[i]);
dgnc_cleanup_board(dgnc_Board[i]);
}
dgnc_tty_post_uninit();
#if defined(DGNC_TRACER)
dgnc_tracer_free();
#endif
if (dgnc_NumBoards)
pci_unregister_driver(&dgnc_driver);
}
static void dgnc_cleanup_board(struct board_t *brd)
{
int i = 0;
if(!brd || brd->magic != DGNC_BOARD_MAGIC)
return;
switch (brd->device) {
case PCI_DEVICE_CLASSIC_4_DID:
case PCI_DEVICE_CLASSIC_8_DID:
case PCI_DEVICE_CLASSIC_4_422_DID:
case PCI_DEVICE_CLASSIC_8_422_DID:
outb(0, brd->iobase + 0x4c);
break;
default:
break;
}
if (brd->irq)
free_irq(brd->irq, brd);
tasklet_kill(&brd->helper_tasklet);
if (brd->re_map_membase) {
iounmap(brd->re_map_membase);
brd->re_map_membase = NULL;
}
if (brd->msgbuf_head) {
unsigned long flags;
DGNC_LOCK(dgnc_global_lock, flags);
brd->msgbuf = NULL;
printk("%s", brd->msgbuf_head);
kfree(brd->msgbuf_head);
brd->msgbuf_head = NULL;
DGNC_UNLOCK(dgnc_global_lock, flags);
}
for (i = 0; i < MAXPORTS ; i++) {
if (brd->channels[i]) {
if (brd->channels[i]->ch_rqueue)
kfree(brd->channels[i]->ch_rqueue);
if (brd->channels[i]->ch_equeue)
kfree(brd->channels[i]->ch_equeue);
if (brd->channels[i]->ch_wqueue)
kfree(brd->channels[i]->ch_wqueue);
kfree(brd->channels[i]);
brd->channels[i] = NULL;
}
}
if (brd->flipbuf)
kfree(brd->flipbuf);
dgnc_Board[brd->boardnum] = NULL;
kfree(brd);
}
static int dgnc_found_board(struct pci_dev *pdev, int id)
{
struct board_t *brd;
unsigned int pci_irq;
int i = 0;
int rc = 0;
unsigned long flags;
brd = dgnc_Board[dgnc_NumBoards] =
(struct board_t *) kzalloc(sizeof(struct board_t), GFP_KERNEL);
if (!brd) {
APR(("memory allocation for board structure failed\n"));
return(-ENOMEM);
}
brd->msgbuf = brd->msgbuf_head =
(char *) kzalloc(sizeof(char) * 8192, GFP_KERNEL);
if (!brd->msgbuf) {
kfree(brd);
APR(("memory allocation for board msgbuf failed\n"));
return(-ENOMEM);
}
brd->magic = DGNC_BOARD_MAGIC;
brd->boardnum = dgnc_NumBoards;
brd->vendor = dgnc_pci_tbl[id].vendor;
brd->device = dgnc_pci_tbl[id].device;
brd->pdev = pdev;
brd->pci_bus = pdev->bus->number;
brd->pci_slot = PCI_SLOT(pdev->devfn);
brd->name = dgnc_Ids[id].name;
brd->maxports = dgnc_Ids[id].maxports;
if (dgnc_Ids[i].is_pci_express)
brd->bd_flags |= BD_IS_PCI_EXPRESS;
brd->dpastatus = BD_NOFEP;
init_waitqueue_head(&brd->state_wait);
DGNC_SPINLOCK_INIT(brd->bd_lock);
DGNC_SPINLOCK_INIT(brd->bd_intr_lock);
brd->state = BOARD_FOUND;
for (i = 0; i < MAXPORTS; i++) {
brd->channels[i] = NULL;
}
pci_read_config_word(pdev, PCI_SUBSYSTEM_VENDOR_ID, &brd->subvendor);
pci_read_config_word(pdev, PCI_SUBSYSTEM_ID, &brd->subdevice);
pci_read_config_byte(pdev, PCI_REVISION_ID, &brd->rev);
pci_irq = pdev->irq;
brd->irq = pci_irq;
switch(brd->device) {
case PCI_DEVICE_CLASSIC_4_DID:
case PCI_DEVICE_CLASSIC_8_DID:
case PCI_DEVICE_CLASSIC_4_422_DID:
case PCI_DEVICE_CLASSIC_8_422_DID:
brd->dpatype = T_CLASSIC | T_PCIBUS;
DPR_INIT(("dgnc_found_board - Classic.\n"));
brd->membase = pci_resource_start(pdev, 4);
if (!brd->membase) {
APR(("card has no PCI IO resources, failing board.\n"));
return -ENODEV;
}
brd->membase_end = pci_resource_end(pdev, 4);
if (brd->membase & 1)
brd->membase &= ~3;
else
brd->membase &= ~15;
brd->iobase = pci_resource_start(pdev, 1);
brd->iobase_end = pci_resource_end(pdev, 1);
brd->iobase = ((unsigned int) (brd->iobase)) & 0xFFFE;
brd->bd_ops = &dgnc_cls_ops;
brd->bd_uart_offset = 0x8;
brd->bd_dividend = 921600;
dgnc_do_remap(brd);
brd->bd_ops->vpd(brd);
outb(0x43, brd->iobase + 0x4c);
break;
case PCI_DEVICE_NEO_4_DID:
case PCI_DEVICE_NEO_8_DID:
case PCI_DEVICE_NEO_2DB9_DID:
case PCI_DEVICE_NEO_2DB9PRI_DID:
case PCI_DEVICE_NEO_2RJ45_DID:
case PCI_DEVICE_NEO_2RJ45PRI_DID:
case PCI_DEVICE_NEO_1_422_DID:
case PCI_DEVICE_NEO_1_422_485_DID:
case PCI_DEVICE_NEO_2_422_485_DID:
case PCI_DEVICE_NEO_EXPRESS_8_DID:
case PCI_DEVICE_NEO_EXPRESS_4_DID:
case PCI_DEVICE_NEO_EXPRESS_4RJ45_DID:
case PCI_DEVICE_NEO_EXPRESS_8RJ45_DID:
if (brd->bd_flags & BD_IS_PCI_EXPRESS)
brd->dpatype = T_NEO_EXPRESS | T_PCIBUS;
else
brd->dpatype = T_NEO | T_PCIBUS;
DPR_INIT(("dgnc_found_board - NEO.\n"));
brd->membase = pci_resource_start(pdev, 0);
brd->membase_end = pci_resource_end(pdev, 0);
if (brd->membase & 1)
brd->membase &= ~3;
else
brd->membase &= ~15;
brd->bd_ops = &dgnc_neo_ops;
brd->bd_uart_offset = 0x200;
brd->bd_dividend = 921600;
dgnc_do_remap(brd);
if (brd->re_map_membase) {
brd->dvid = readb(brd->re_map_membase + 0x8D);
brd->bd_ops->vpd(brd);
}
break;
default:
APR(("Did not find any compatible Neo or Classic PCI boards in system.\n"));
return (-ENXIO);
}
rc = dgnc_tty_register(brd);
if (rc < 0) {
dgnc_tty_uninit(brd);
APR(("Can't register tty devices (%d)\n", rc));
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
goto failed;
}
rc = dgnc_finalize_board_init(brd);
if (rc < 0) {
APR(("Can't finalize board init (%d)\n", rc));
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
goto failed;
}
rc = dgnc_tty_init(brd);
if (rc < 0) {
dgnc_tty_uninit(brd);
APR(("Can't init tty devices (%d)\n", rc));
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
goto failed;
}
brd->state = BOARD_READY;
brd->dpastatus = BD_RUNNING;
dgnc_create_ports_sysfiles(brd);
tasklet_init(&brd->helper_tasklet, brd->bd_ops->tasklet, (unsigned long) brd);
DPR_INIT(("dgnc_scan(%d) - printing out the msgbuf\n", i));
DGNC_LOCK(dgnc_global_lock, flags);
brd->msgbuf = NULL;
printk("%s", brd->msgbuf_head);
kfree(brd->msgbuf_head);
brd->msgbuf_head = NULL;
DGNC_UNLOCK(dgnc_global_lock, flags);
brd->flipbuf = kzalloc(MYFLIPLEN, GFP_KERNEL);
wake_up_interruptible(&brd->state_wait);
return(0);
failed:
return (-ENXIO);
}
static int dgnc_finalize_board_init(struct board_t *brd) {
int rc = 0;
DPR_INIT(("dgnc_finalize_board_init() - start\n"));
if (!brd || brd->magic != DGNC_BOARD_MAGIC)
return(-ENODEV);
DPR_INIT(("dgnc_finalize_board_init() - start #2\n"));
if (brd->irq) {
rc = request_irq(brd->irq, brd->bd_ops->intr, IRQF_SHARED, "DGNC", brd);
if (rc) {
printk("Failed to hook IRQ %d\n",brd->irq);
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
rc = -ENODEV;
} else {
DPR_INIT(("Requested and received usage of IRQ %d\n", brd->irq));
}
}
return(rc);
}
static void dgnc_do_remap(struct board_t *brd)
{
if (!brd || brd->magic != DGNC_BOARD_MAGIC)
return;
brd->re_map_membase = ioremap(brd->membase, 0x1000);
DPR_INIT(("remapped mem: 0x%p\n", brd->re_map_membase));
}
static void dgnc_poll_handler(ulong dummy)
{
struct board_t *brd;
unsigned long lock_flags;
int i;
unsigned long new_time;
dgnc_poll_counter++;
if (dgnc_driver_state != DRIVER_READY) {
goto schedule_poller;
}
for (i = 0; i < dgnc_NumBoards; i++) {
brd = dgnc_Board[i];
DGNC_LOCK(brd->bd_lock, lock_flags);
if (brd->state == BOARD_FAILED) {
DGNC_UNLOCK(brd->bd_lock, lock_flags);
continue;
}
tasklet_schedule(&brd->helper_tasklet);
DGNC_UNLOCK(brd->bd_lock, lock_flags);
}
schedule_poller:
DGNC_LOCK(dgnc_poll_lock, lock_flags);
dgnc_poll_time += dgnc_jiffies_from_ms(dgnc_poll_tick);
new_time = dgnc_poll_time - jiffies;
if ((ulong) new_time >= 2 * dgnc_poll_tick) {
dgnc_poll_time = jiffies + dgnc_jiffies_from_ms(dgnc_poll_tick);
}
init_timer(&dgnc_poll_timer);
dgnc_poll_timer.function = dgnc_poll_handler;
dgnc_poll_timer.data = 0;
dgnc_poll_timer.expires = dgnc_poll_time;
DGNC_UNLOCK(dgnc_poll_lock, lock_flags);
if (!dgnc_poll_stop)
add_timer(&dgnc_poll_timer);
}
static void dgnc_init_globals(void)
{
int i = 0;
dgnc_rawreadok = rawreadok;
dgnc_trcbuf_size = trcbuf_size;
dgnc_debug = debug;
for (i = 0; i < MAXBOARDS; i++) {
dgnc_Board[i] = NULL;
}
init_timer(&dgnc_poll_timer);
}
int dgnc_ms_sleep(ulong ms)
{
current->state = TASK_INTERRUPTIBLE;
schedule_timeout((ms * HZ) / 1000);
return (signal_pending(current));
}
char *dgnc_ioctl_name(int cmd)
{
switch(cmd) {
case TCGETA: return("TCGETA");
case TCGETS: return("TCGETS");
case TCSETA: return("TCSETA");
case TCSETS: return("TCSETS");
case TCSETAW: return("TCSETAW");
case TCSETSW: return("TCSETSW");
case TCSETAF: return("TCSETAF");
case TCSETSF: return("TCSETSF");
case TCSBRK: return("TCSBRK");
case TCXONC: return("TCXONC");
case TCFLSH: return("TCFLSH");
case TIOCGSID: return("TIOCGSID");
case TIOCGETD: return("TIOCGETD");
case TIOCSETD: return("TIOCSETD");
case TIOCGWINSZ: return("TIOCGWINSZ");
case TIOCSWINSZ: return("TIOCSWINSZ");
case TIOCMGET: return("TIOCMGET");
case TIOCMSET: return("TIOCMSET");
case TIOCMBIS: return("TIOCMBIS");
case TIOCMBIC: return("TIOCMBIC");
case DIGI_SETA: return("DIGI_SETA");
case DIGI_SETAW: return("DIGI_SETAW");
case DIGI_SETAF: return("DIGI_SETAF");
case DIGI_SETFLOW: return("DIGI_SETFLOW");
case DIGI_SETAFLOW: return("DIGI_SETAFLOW");
case DIGI_GETFLOW: return("DIGI_GETFLOW");
case DIGI_GETAFLOW: return("DIGI_GETAFLOW");
case DIGI_GETA: return("DIGI_GETA");
case DIGI_GEDELAY: return("DIGI_GEDELAY");
case DIGI_SEDELAY: return("DIGI_SEDELAY");
case DIGI_GETCUSTOMBAUD: return("DIGI_GETCUSTOMBAUD");
case DIGI_SETCUSTOMBAUD: return("DIGI_SETCUSTOMBAUD");
case TIOCMODG: return("TIOCMODG");
case TIOCMODS: return("TIOCMODS");
case TIOCSDTR: return("TIOCSDTR");
case TIOCCDTR: return("TIOCCDTR");
default: return("unknown");
}
}
