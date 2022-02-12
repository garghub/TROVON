static long
uctrl_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
switch (cmd) {
default:
return -EINVAL;
}
return 0;
}
static int
uctrl_open(struct inode *inode, struct file *file)
{
mutex_lock(&uctrl_mutex);
uctrl_get_event_status(global_driver);
uctrl_get_external_status(global_driver);
mutex_unlock(&uctrl_mutex);
return 0;
}
static irqreturn_t uctrl_interrupt(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static void uctrl_do_txn(struct uctrl_driver *driver, struct uctrl_txn *txn)
{
int stat, incnt, outcnt, bytecnt, intr;
u32 byte;
stat = sbus_readl(&driver->regs->uctrl_stat);
intr = sbus_readl(&driver->regs->uctrl_intr);
sbus_writel(stat, &driver->regs->uctrl_stat);
dprintk(("interrupt stat 0x%x int 0x%x\n", stat, intr));
incnt = txn->inbits;
outcnt = txn->outbits;
byte = (txn->opcode << 8);
WRITEUCTLDATA(byte);
bytecnt = 0;
while (incnt > 0) {
byte = (txn->inbuf[bytecnt] << 8);
WRITEUCTLDATA(byte);
incnt--;
bytecnt++;
}
READUCTLDATA(byte);
dprintk(("ack was %x\n", (byte >> 8)));
bytecnt = 0;
while (outcnt > 0) {
READUCTLDATA(byte);
txn->outbuf[bytecnt] = (byte >> 8);
dprintk(("set byte to %02x\n", byte));
outcnt--;
bytecnt++;
}
}
static void uctrl_get_event_status(struct uctrl_driver *driver)
{
struct uctrl_txn txn;
u8 outbits[2];
txn.opcode = READ_EVENT_STATUS;
txn.inbits = 0;
txn.outbits = 2;
txn.inbuf = NULL;
txn.outbuf = outbits;
uctrl_do_txn(driver, &txn);
dprintk(("bytes %x %x\n", (outbits[0] & 0xff), (outbits[1] & 0xff)));
driver->status.event_status =
((outbits[0] & 0xff) << 8) | (outbits[1] & 0xff);
dprintk(("ev is %x\n", driver->status.event_status));
}
static void uctrl_get_external_status(struct uctrl_driver *driver)
{
struct uctrl_txn txn;
u8 outbits[2];
int i, v;
txn.opcode = READ_EXTERNAL_STATUS;
txn.inbits = 0;
txn.outbits = 2;
txn.inbuf = NULL;
txn.outbuf = outbits;
uctrl_do_txn(driver, &txn);
dprintk(("bytes %x %x\n", (outbits[0] & 0xff), (outbits[1] & 0xff)));
driver->status.external_status =
((outbits[0] * 256) + (outbits[1]));
dprintk(("ex is %x\n", driver->status.external_status));
v = driver->status.external_status;
for (i = 0; v != 0; i++, v >>= 1) {
if (v & 1) {
dprintk(("%s%s", " ", uctrl_extstatus[i]));
}
}
dprintk(("\n"));
}
static int uctrl_probe(struct platform_device *op)
{
struct uctrl_driver *p;
int err = -ENOMEM;
p = kzalloc(sizeof(*p), GFP_KERNEL);
if (!p) {
printk(KERN_ERR "uctrl: Unable to allocate device struct.\n");
goto out;
}
p->regs = of_ioremap(&op->resource[0], 0,
resource_size(&op->resource[0]),
"uctrl");
if (!p->regs) {
printk(KERN_ERR "uctrl: Unable to map registers.\n");
goto out_free;
}
p->irq = op->archdata.irqs[0];
err = request_irq(p->irq, uctrl_interrupt, 0, "uctrl", p);
if (err) {
printk(KERN_ERR "uctrl: Unable to register irq.\n");
goto out_iounmap;
}
err = misc_register(&uctrl_dev);
if (err) {
printk(KERN_ERR "uctrl: Unable to register misc device.\n");
goto out_free_irq;
}
sbus_writel(UCTRL_INTR_RXNE_REQ|UCTRL_INTR_RXNE_MSK, &p->regs->uctrl_intr);
printk(KERN_INFO "%pOF: uctrl regs[0x%p] (irq %d)\n",
op->dev.of_node, p->regs, p->irq);
uctrl_get_event_status(p);
uctrl_get_external_status(p);
dev_set_drvdata(&op->dev, p);
global_driver = p;
out:
return err;
out_free_irq:
free_irq(p->irq, p);
out_iounmap:
of_iounmap(&op->resource[0], p->regs, resource_size(&op->resource[0]));
out_free:
kfree(p);
goto out;
}
static int uctrl_remove(struct platform_device *op)
{
struct uctrl_driver *p = dev_get_drvdata(&op->dev);
if (p) {
misc_deregister(&uctrl_dev);
free_irq(p->irq, p);
of_iounmap(&op->resource[0], p->regs, resource_size(&op->resource[0]));
kfree(p);
}
return 0;
}
