static int dgnc_do_remap(struct dgnc_board *brd)
{
brd->re_map_membase = ioremap(brd->membase, 0x1000);
if (!brd->re_map_membase)
return -ENOMEM;
return 0;
}
static struct dgnc_board *dgnc_found_board(struct pci_dev *pdev, int id)
{
struct dgnc_board *brd;
unsigned int pci_irq;
int i = 0;
int rc = 0;
brd = kzalloc(sizeof(*brd), GFP_KERNEL);
if (!brd)
return ERR_PTR(-ENOMEM);
brd->boardnum = dgnc_num_boards;
brd->vendor = dgnc_pci_tbl[id].vendor;
brd->device = dgnc_pci_tbl[id].device;
brd->pdev = pdev;
brd->pci_bus = pdev->bus->number;
brd->pci_slot = PCI_SLOT(pdev->devfn);
brd->name = dgnc_ids[id].name;
brd->maxports = dgnc_ids[id].maxports;
if (dgnc_ids[i].is_pci_express)
brd->bd_flags |= BD_IS_PCI_EXPRESS;
brd->dpastatus = BD_NOFEP;
init_waitqueue_head(&brd->state_wait);
spin_lock_init(&brd->bd_lock);
spin_lock_init(&brd->bd_intr_lock);
brd->state = BOARD_FOUND;
pci_read_config_word(pdev, PCI_SUBSYSTEM_VENDOR_ID, &brd->subvendor);
pci_read_config_word(pdev, PCI_SUBSYSTEM_ID, &brd->subdevice);
pci_read_config_byte(pdev, PCI_REVISION_ID, &brd->rev);
pci_irq = pdev->irq;
brd->irq = pci_irq;
switch (brd->device) {
case PCI_DEVICE_CLASSIC_4_DID:
case PCI_DEVICE_CLASSIC_8_DID:
case PCI_DEVICE_CLASSIC_4_422_DID:
case PCI_DEVICE_CLASSIC_8_422_DID:
brd->dpatype = T_CLASSIC | T_PCIBUS;
brd->membase = pci_resource_start(pdev, 4);
if (!brd->membase) {
dev_err(&brd->pdev->dev,
"Card has no PCI IO resources, failing.\n");
rc = -ENODEV;
goto failed;
}
brd->membase_end = pci_resource_end(pdev, 4);
if (brd->membase & 1)
brd->membase &= ~3;
else
brd->membase &= ~15;
brd->iobase = pci_resource_start(pdev, 1);
brd->iobase_end = pci_resource_end(pdev, 1);
brd->iobase = ((unsigned int)(brd->iobase)) & 0xFFFE;
brd->bd_ops = &dgnc_cls_ops;
brd->bd_uart_offset = 0x8;
brd->bd_dividend = 921600;
rc = dgnc_do_remap(brd);
if (rc < 0)
goto failed;
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
brd->membase = pci_resource_start(pdev, 0);
brd->membase_end = pci_resource_end(pdev, 0);
if (brd->membase & 1)
brd->membase &= ~3;
else
brd->membase &= ~15;
brd->bd_ops = &dgnc_neo_ops;
brd->bd_uart_offset = 0x200;
brd->bd_dividend = 921600;
rc = dgnc_do_remap(brd);
if (rc < 0)
goto failed;
brd->dvid = readb(brd->re_map_membase + 0x8D);
brd->bd_ops->vpd(brd);
break;
default:
dev_err(&brd->pdev->dev,
"Didn't find any compatible Neo/Classic PCI boards.\n");
rc = -ENXIO;
goto failed;
}
tasklet_init(&brd->helper_tasklet,
brd->bd_ops->tasklet,
(unsigned long)brd);
wake_up_interruptible(&brd->state_wait);
return brd;
failed:
kfree(brd);
return ERR_PTR(rc);
}
static int dgnc_request_irq(struct dgnc_board *brd)
{
if (brd->irq) {
int rc = request_irq(brd->irq, brd->bd_ops->intr,
IRQF_SHARED, "DGNC", brd);
if (rc) {
dev_err(&brd->pdev->dev,
"Failed to hook IRQ %d\n", brd->irq);
brd->state = BOARD_FAILED;
brd->dpastatus = BD_NOFEP;
return -ENODEV;
}
}
return 0;
}
static void dgnc_free_irq(struct dgnc_board *brd)
{
if (brd->irq)
free_irq(brd->irq, brd);
}
static void dgnc_poll_handler(ulong dummy)
{
struct dgnc_board *brd;
unsigned long flags;
int i;
unsigned long new_time;
for (i = 0; i < dgnc_num_boards; i++) {
brd = dgnc_board[i];
spin_lock_irqsave(&brd->bd_lock, flags);
if (brd->state == BOARD_FAILED) {
spin_unlock_irqrestore(&brd->bd_lock, flags);
continue;
}
tasklet_schedule(&brd->helper_tasklet);
spin_unlock_irqrestore(&brd->bd_lock, flags);
}
spin_lock_irqsave(&dgnc_poll_lock, flags);
dgnc_poll_time += dgnc_jiffies_from_ms(dgnc_poll_tick);
new_time = dgnc_poll_time - jiffies;
if ((ulong)new_time >= 2 * dgnc_poll_tick)
dgnc_poll_time = jiffies + dgnc_jiffies_from_ms(dgnc_poll_tick);
setup_timer(&dgnc_poll_timer, dgnc_poll_handler, 0);
dgnc_poll_timer.expires = dgnc_poll_time;
spin_unlock_irqrestore(&dgnc_poll_lock, flags);
if (!dgnc_poll_stop)
add_timer(&dgnc_poll_timer);
}
static int dgnc_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
int rc;
struct dgnc_board *brd;
rc = pci_enable_device(pdev);
if (rc)
return -EIO;
brd = dgnc_found_board(pdev, ent->driver_data);
if (IS_ERR(brd))
return PTR_ERR(brd);
rc = dgnc_tty_register(brd);
if (rc < 0) {
pr_err(DRVSTR ": Can't register tty devices (%d)\n", rc);
goto failed;
}
rc = dgnc_request_irq(brd);
if (rc < 0) {
pr_err(DRVSTR ": Can't finalize board init (%d)\n", rc);
goto unregister_tty;
}
rc = dgnc_tty_init(brd);
if (rc < 0) {
pr_err(DRVSTR ": Can't init tty devices (%d)\n", rc);
goto free_irq;
}
brd->state = BOARD_READY;
brd->dpastatus = BD_RUNNING;
dgnc_board[dgnc_num_boards++] = brd;
return 0;
free_irq:
dgnc_free_irq(brd);
unregister_tty:
dgnc_tty_unregister(brd);
failed:
kfree(brd);
return rc;
}
static int dgnc_start(void)
{
int rc = 0;
unsigned long flags;
struct device *dev;
init_timer(&dgnc_poll_timer);
rc = register_chrdev(0, "dgnc", &dgnc_board_fops);
if (rc < 0) {
pr_err(DRVSTR ": Can't register dgnc driver device (%d)\n", rc);
return rc;
}
dgnc_major = rc;
dgnc_class = class_create(THIS_MODULE, "dgnc_mgmt");
if (IS_ERR(dgnc_class)) {
rc = PTR_ERR(dgnc_class);
pr_err(DRVSTR ": Can't create dgnc_mgmt class (%d)\n", rc);
goto failed_class;
}
dev = device_create(dgnc_class, NULL,
MKDEV(dgnc_major, 0),
NULL, "dgnc_mgmt");
if (IS_ERR(dev)) {
rc = PTR_ERR(dev);
pr_err(DRVSTR ": Can't create device (%d)\n", rc);
goto failed_device;
}
spin_lock_irqsave(&dgnc_poll_lock, flags);
setup_timer(&dgnc_poll_timer, dgnc_poll_handler, 0);
dgnc_poll_time = jiffies + dgnc_jiffies_from_ms(dgnc_poll_tick);
dgnc_poll_timer.expires = dgnc_poll_time;
spin_unlock_irqrestore(&dgnc_poll_lock, flags);
add_timer(&dgnc_poll_timer);
return 0;
failed_device:
class_destroy(dgnc_class);
failed_class:
unregister_chrdev(dgnc_major, "dgnc");
return rc;
}
static void dgnc_cleanup_board(struct dgnc_board *brd)
{
int i = 0;
if (!brd)
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
for (i = 0; i < MAXPORTS ; i++) {
if (brd->channels[i]) {
kfree(brd->channels[i]->ch_rqueue);
kfree(brd->channels[i]->ch_equeue);
kfree(brd->channels[i]->ch_wqueue);
kfree(brd->channels[i]);
brd->channels[i] = NULL;
}
}
dgnc_board[brd->boardnum] = NULL;
kfree(brd);
}
static void cleanup(void)
{
int i;
unsigned long flags;
spin_lock_irqsave(&dgnc_poll_lock, flags);
dgnc_poll_stop = 1;
spin_unlock_irqrestore(&dgnc_poll_lock, flags);
del_timer_sync(&dgnc_poll_timer);
device_destroy(dgnc_class, MKDEV(dgnc_major, 0));
class_destroy(dgnc_class);
unregister_chrdev(dgnc_major, "dgnc");
for (i = 0; i < dgnc_num_boards; ++i) {
dgnc_cleanup_tty(dgnc_board[i]);
dgnc_cleanup_board(dgnc_board[i]);
}
}
static void __exit dgnc_cleanup_module(void)
{
cleanup();
pci_unregister_driver(&dgnc_driver);
}
static int __init dgnc_init_module(void)
{
int rc;
rc = dgnc_start();
if (rc < 0)
return rc;
rc = pci_register_driver(&dgnc_driver);
if (rc) {
pr_warn("WARNING: dgnc driver load failed. No Digi Neo or Classic boards found.\n");
cleanup();
return rc;
}
return 0;
}
