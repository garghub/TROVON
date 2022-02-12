int dgap_init_module(void)
{
int rc = 0;
APR(("%s, Digi International Part Number %s\n", DG_NAME, DG_PART));
rc = dgap_start();
if (rc < 0) {
return(rc);
}
rc = dgap_init_pci();
if (rc < 0) {
if (dgap_NumBoards)
pci_unregister_driver(&dgap_driver);
else
printk("WARNING: dgap driver load failed. No DGAP boards found.\n");
dgap_cleanup_module();
}
else {
dgap_create_driver_sysfiles(&dgap_driver);
}
DPR_INIT(("Finished init_module. Returning %d\n", rc));
return (rc);
}
static int dgap_start(void)
{
int rc = 0;
unsigned long flags;
if (dgap_driver_start == FALSE) {
dgap_driver_start = TRUE;
dgap_init_globals();
dgap_NumBoards = 0;
APR(("For the tools package or updated drivers please visit http://www.digi.com\n"));
if (!dgap_Major_Control_Registered) {
rc = register_chrdev(DIGI_DGAP_MAJOR, "dgap", &DgapBoardFops);
if (rc < 0) {
APR(("Can't register dgap driver device (%d)\n", rc));
return (rc);
}
dgap_class = class_create(THIS_MODULE, "dgap_mgmt");
device_create(dgap_class, NULL,
MKDEV(DIGI_DGAP_MAJOR, 0),
NULL, "dgap_mgmt");
device_create(dgap_class, NULL,
MKDEV(DIGI_DGAP_MAJOR, 1),
NULL, "dgap_downld");
dgap_Major_Control_Registered = TRUE;
}
rc = dgap_tty_preinit();
if (rc < 0) {
APR(("tty preinit - not enough memory (%d)\n", rc));
return(rc);
}
DGAP_LOCK(dgap_poll_lock, flags);
init_timer(&dgap_poll_timer);
dgap_poll_timer.function = dgap_poll_handler;
dgap_poll_timer.data = 0;
dgap_poll_time = jiffies + dgap_jiffies_from_ms(dgap_poll_tick);
dgap_poll_timer.expires = dgap_poll_time;
DGAP_UNLOCK(dgap_poll_lock, flags);
add_timer(&dgap_poll_timer);
dgap_driver_state = DRIVER_NEED_CONFIG_LOAD;
}
return (rc);
}
static int dgap_init_pci(void)
{
return pci_register_driver(&dgap_driver);
}
static int dgap_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc;
rc = pci_enable_device(pdev);
if (rc < 0) {
rc = -EIO;
} else {
rc = dgap_probe1(pdev, ent->driver_data);
if (rc == 0) {
dgap_NumBoards++;
DPR_INIT(("Incrementing numboards to %d\n", dgap_NumBoards));
}
}
return rc;
}
static int dgap_probe1(struct pci_dev *pdev, int card_type)
{
return dgap_found_board(pdev, card_type);
}
static void dgap_remove_one(struct pci_dev *dev)
{
}
void dgap_cleanup_module(void)
{
int i;
ulong lock_flags;
DGAP_LOCK(dgap_poll_lock, lock_flags);
dgap_poll_stop = 1;
DGAP_UNLOCK(dgap_poll_lock, lock_flags);
del_timer_sync( &dgap_poll_timer);
dgap_remove_driver_sysfiles(&dgap_driver);
if (dgap_Major_Control_Registered) {
device_destroy(dgap_class, MKDEV(DIGI_DGAP_MAJOR, 0));
device_destroy(dgap_class, MKDEV(DIGI_DGAP_MAJOR, 1));
class_destroy(dgap_class);
unregister_chrdev(DIGI_DGAP_MAJOR, "dgap");
}
kfree(dgap_config_buf);
for (i = 0; i < dgap_NumBoards; ++i) {
dgap_remove_ports_sysfiles(dgap_Board[i]);
dgap_tty_uninit(dgap_Board[i]);
dgap_cleanup_board(dgap_Board[i]);
}
dgap_tty_post_uninit();
#if defined(DGAP_TRACER)
dgap_tracer_free();
#endif
if (dgap_NumBoards)
pci_unregister_driver(&dgap_driver);
}
static void dgap_cleanup_board(struct board_t *brd)
{
int i = 0;
if(!brd || brd->magic != DGAP_BOARD_MAGIC)
return;
if (brd->intr_used && brd->irq)
free_irq(brd->irq, brd);
tasklet_kill(&brd->helper_tasklet);
if (brd->re_map_port) {
release_mem_region(brd->membase + 0x200000, 0x200000);
iounmap(brd->re_map_port);
brd->re_map_port = NULL;
}
if (brd->re_map_membase) {
release_mem_region(brd->membase, 0x200000);
iounmap(brd->re_map_membase);
brd->re_map_membase = NULL;
}
if (brd->msgbuf_head) {
unsigned long flags;
DGAP_LOCK(dgap_global_lock, flags);
brd->msgbuf = NULL;
printk("%s", brd->msgbuf_head);
kfree(brd->msgbuf_head);
brd->msgbuf_head = NULL;
DGAP_UNLOCK(dgap_global_lock, flags);
}
for (i = 0; i < MAXPORTS ; i++) {
if (brd->channels[i]) {
kfree(brd->channels[i]);
brd->channels[i] = NULL;
}
}
kfree(brd->flipbuf);
kfree(brd->flipflagbuf);
dgap_Board[brd->boardnum] = NULL;
kfree(brd);
}
static int dgap_found_board(struct pci_dev *pdev, int id)
{
struct board_t *brd;
unsigned int pci_irq;
int i = 0;
unsigned long flags;
brd = dgap_Board[dgap_NumBoards] =
(struct board_t *) dgap_driver_kzmalloc(sizeof(struct board_t), GFP_KERNEL);
if (!brd) {
APR(("memory allocation for board structure failed\n"));
return(-ENOMEM);
}
brd->msgbuf = brd->msgbuf_head =
(char *) dgap_driver_kzmalloc(sizeof(char) * 8192, GFP_KERNEL);
if(!brd->msgbuf) {
kfree(brd);
APR(("memory allocation for board msgbuf failed\n"));
return(-ENOMEM);
}
brd->magic = DGAP_BOARD_MAGIC;
brd->boardnum = dgap_NumBoards;
brd->firstminor = 0;
brd->vendor = dgap_pci_tbl[id].vendor;
brd->device = dgap_pci_tbl[id].device;
brd->pdev = pdev;
brd->pci_bus = pdev->bus->number;
brd->pci_slot = PCI_SLOT(pdev->devfn);
brd->name = dgap_Ids[id].name;
brd->maxports = dgap_Ids[id].maxports;
brd->type = dgap_Ids[id].config_type;
brd->dpatype = dgap_Ids[id].dpatype;
brd->dpastatus = BD_NOFEP;
init_waitqueue_head(&brd->state_wait);
DGAP_SPINLOCK_INIT(brd->bd_lock);
brd->state = BOARD_FOUND;
brd->runwait = 0;
brd->inhibit_poller = FALSE;
brd->wait_for_bios = 0;
brd->wait_for_fep = 0;
for (i = 0; i < MAXPORTS; i++) {
brd->channels[i] = NULL;
}
pci_read_config_word(pdev, PCI_SUBSYSTEM_VENDOR_ID, &brd->subvendor);
pci_read_config_word(pdev, PCI_SUBSYSTEM_ID, &brd->subdevice);
pci_read_config_byte(pdev, PCI_REVISION_ID, &brd->rev);
pci_irq = pdev->irq;
brd->irq = pci_irq;
if (brd->device == PCI_DEVICE_XRJ_DID || brd->device == PCI_DEVICE_EPCJ_DID) {
brd->membase = pci_resource_start(pdev, 2);
brd->membase_end = pci_resource_end(pdev, 2);
}
else {
brd->membase = pci_resource_start(pdev, 0);
brd->membase_end = pci_resource_end(pdev, 0);
}
if (!brd->membase) {
APR(("card has no PCI IO resources, failing board.\n"));
return -ENODEV;
}
if (brd->membase & 1)
brd->membase &= ~3;
else
brd->membase &= ~15;
brd->port = brd->membase + PCI_IO_OFFSET;
brd->port_end = brd->port + PCI_IO_SIZE;
if (brd->device != PCI_DEVICE_XRJ_DID && brd->device != PCI_DEVICE_EPCJ_DID) {
unsigned short cmd;
pci_write_config_byte(pdev, 0x40, 0);
pci_write_config_byte(pdev, 0x46, 0);
pci_write_config_byte(pdev, 0x42, 1);
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
cmd |= (PCI_COMMAND_IO | PCI_COMMAND_MEMORY);
pci_write_config_word(pdev, PCI_COMMAND, cmd);
}
tasklet_init(&brd->helper_tasklet, dgap_poll_tasklet, (unsigned long) brd);
dgap_mbuf(brd, DRVSTR": board %d: %s (rev %d), irq %d\n",
dgap_NumBoards, brd->name, brd->rev, brd->irq);
DPR_INIT(("dgap_scan(%d) - printing out the msgbuf\n", i));
DGAP_LOCK(dgap_global_lock, flags);
brd->msgbuf = NULL;
printk("%s", brd->msgbuf_head);
kfree(brd->msgbuf_head);
brd->msgbuf_head = NULL;
DGAP_UNLOCK(dgap_global_lock, flags);
i = dgap_do_remap(brd);
if (i)
brd->state = BOARD_FAILED;
else
brd->state = NEED_RESET;
return(0);
}
int dgap_finalize_board_init(struct board_t *brd) {
int rc;
DPR_INIT(("dgap_finalize_board_init() - start\n"));
if (!brd || brd->magic != DGAP_BOARD_MAGIC)
return(-ENODEV);
DPR_INIT(("dgap_finalize_board_init() - start #2\n"));
brd->use_interrupts = dgap_config_get_useintr(brd);
if (brd->use_interrupts && brd->irq) {
rc = request_irq(brd->irq, dgap_intr, IRQF_SHARED, "DGAP", brd);
if (rc) {
dgap_mbuf(brd, DRVSTR": Failed to hook IRQ %d. Board will work in poll mode.\n",
brd->irq);
brd->intr_used = 0;
}
else
brd->intr_used = 1;
} else {
brd->intr_used = 0;
}
return(0);
}
static int dgap_do_remap(struct board_t *brd)
{
if (!brd || brd->magic != DGAP_BOARD_MAGIC)
return -ENXIO;
if (!request_mem_region(brd->membase, 0x200000, "dgap")) {
APR(("dgap: mem_region %lx already in use.\n", brd->membase));
return -ENOMEM;
}
if (!request_mem_region(brd->membase + PCI_IO_OFFSET, 0x200000, "dgap")) {
APR(("dgap: mem_region IO %lx already in use.\n",
brd->membase + PCI_IO_OFFSET));
release_mem_region(brd->membase, 0x200000);
return -ENOMEM;
}
brd->re_map_membase = ioremap(brd->membase, 0x200000);
if (!brd->re_map_membase) {
APR(("dgap: ioremap mem %lx cannot be mapped.\n", brd->membase));
release_mem_region(brd->membase, 0x200000);
release_mem_region(brd->membase + PCI_IO_OFFSET, 0x200000);
return -ENOMEM;
}
brd->re_map_port = ioremap((brd->membase + PCI_IO_OFFSET), 0x200000);
if (!brd->re_map_port) {
release_mem_region(brd->membase, 0x200000);
release_mem_region(brd->membase + PCI_IO_OFFSET, 0x200000);
iounmap(brd->re_map_membase);
APR(("dgap: ioremap IO mem %lx cannot be mapped.\n",
brd->membase + PCI_IO_OFFSET));
return -ENOMEM;
}
DPR_INIT(("remapped io: 0x%p remapped mem: 0x%p\n",
brd->re_map_port, brd->re_map_membase));
return 0;
}
static void dgap_poll_handler(ulong dummy)
{
int i;
struct board_t *brd;
unsigned long lock_flags;
unsigned long lock_flags2;
ulong new_time;
dgap_poll_counter++;
if (dgap_driver_state == DRIVER_NEED_CONFIG_LOAD) {
DGAP_LOCK(dgap_dl_lock, lock_flags2);
if (dgap_dl_action != 1) {
dgap_dl_action = 1;
wake_up_interruptible(&dgap_dl_wait);
}
DGAP_UNLOCK(dgap_dl_lock, lock_flags2);
goto schedule_poller;
}
else if (dgap_driver_state != DRIVER_READY) {
goto schedule_poller;
}
if ( (dgap_NumBoards == 1) || (num_online_cpus() <= 1) ) {
for (i = 0; i < dgap_NumBoards; i++) {
brd = dgap_Board[i];
if (brd->state == BOARD_FAILED) {
continue;
}
if (!brd->intr_running) {
dgap_poll_tasklet((unsigned long) brd);
}
}
}
else {
for (i = 0; i < dgap_NumBoards; i++) {
brd = dgap_Board[i];
if (!spin_trylock(&brd->bd_lock)) {
continue;
}
if (brd->state == BOARD_FAILED) {
spin_unlock(&brd->bd_lock);
continue;
}
if (!brd->intr_running) {
tasklet_schedule(&brd->helper_tasklet);
}
spin_unlock(&brd->bd_lock);
}
}
schedule_poller:
DGAP_LOCK(dgap_poll_lock, lock_flags );
dgap_poll_time += dgap_jiffies_from_ms(dgap_poll_tick);
new_time = dgap_poll_time - jiffies;
if ((ulong) new_time >= 2 * dgap_poll_tick) {
dgap_poll_time = jiffies + dgap_jiffies_from_ms(dgap_poll_tick);
}
dgap_poll_timer.function = dgap_poll_handler;
dgap_poll_timer.data = 0;
dgap_poll_timer.expires = dgap_poll_time;
DGAP_UNLOCK(dgap_poll_lock, lock_flags );
if (!dgap_poll_stop)
add_timer(&dgap_poll_timer);
}
static irqreturn_t dgap_intr(int irq, void *voidbrd)
{
struct board_t *brd = (struct board_t *) voidbrd;
if (!brd) {
APR(("Received interrupt (%d) with null board associated\n", irq));
return IRQ_NONE;
}
if (brd->magic != DGAP_BOARD_MAGIC) {
APR(("Received interrupt (%d) with a board pointer that wasn't ours!\n", irq));
return IRQ_NONE;
}
brd->intr_count++;
tasklet_schedule(&brd->helper_tasklet);
return IRQ_HANDLED;
}
static void dgap_init_globals(void)
{
int i = 0;
dgap_rawreadok = rawreadok;
dgap_trcbuf_size = trcbuf_size;
dgap_debug = debug;
for (i = 0; i < MAXBOARDS; i++) {
dgap_Board[i] = NULL;
}
init_timer( &dgap_poll_timer );
init_waitqueue_head(&dgap_dl_wait);
dgap_dl_action = 0;
}
void *dgap_driver_kzmalloc(size_t size, int priority)
{
void *p = kmalloc(size, priority);
if(p)
memset(p, 0, size);
return(p);
}
static void dgap_mbuf(struct board_t *brd, const char *fmt, ...) {
va_list ap;
char buf[1024];
int i;
unsigned long flags;
size_t length;
DGAP_LOCK(dgap_global_lock, flags);
va_start(ap, fmt);
i = vsnprintf(buf, sizeof(buf), fmt, ap);
va_end(ap);
DPR((buf));
if (!brd || !brd->msgbuf) {
printk("%s", buf);
DGAP_UNLOCK(dgap_global_lock, flags);
return;
}
length = strlen(buf) + 1;
if (brd->msgbuf - brd->msgbuf_head < length)
length = brd->msgbuf - brd->msgbuf_head;
memcpy(brd->msgbuf, buf, length);
brd->msgbuf += length;
DGAP_UNLOCK(dgap_global_lock, flags);
}
int dgap_ms_sleep(ulong ms)
{
current->state = TASK_INTERRUPTIBLE;
schedule_timeout((ms * HZ) / 1000);
return (signal_pending(current));
}
char *dgap_ioctl_name(int cmd)
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
