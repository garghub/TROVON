static int wait_TBE(char *addr)
{
int timeout = 25000;
while (gscps2_readb_status(addr) & GSC_STAT_TBNE) {
if (!--timeout)
return 0;
udelay(10);
}
return 1;
}
static void gscps2_flush(struct gscps2port *ps2port)
{
while (gscps2_readb_status(ps2port->addr) & GSC_STAT_RBNE)
gscps2_readb_input(ps2port->addr);
ps2port->act = ps2port->append = 0;
}
static inline int gscps2_writeb_output(struct gscps2port *ps2port, u8 data)
{
unsigned long flags;
char *addr = ps2port->addr;
if (!wait_TBE(addr)) {
printk(KERN_DEBUG PFX "timeout - could not write byte %#x\n", data);
return 0;
}
while (gscps2_readb_status(ps2port->addr) & GSC_STAT_RBNE)
;
spin_lock_irqsave(&ps2port->lock, flags);
writeb(data, addr+GSC_XMTDATA);
spin_unlock_irqrestore(&ps2port->lock, flags);
mdelay(6);
gscps2_interrupt(0, NULL);
return 1;
}
static void gscps2_enable(struct gscps2port *ps2port, int enable)
{
unsigned long flags;
u8 data;
spin_lock_irqsave(&ps2port->lock, flags);
gscps2_flush(ps2port);
data = gscps2_readb_control(ps2port->addr);
if (enable)
data |= GSC_CTRL_ENBL;
else
data &= ~GSC_CTRL_ENBL;
gscps2_writeb_control(data, ps2port->addr);
spin_unlock_irqrestore(&ps2port->lock, flags);
wait_TBE(ps2port->addr);
gscps2_flush(ps2port);
}
static void gscps2_reset(struct gscps2port *ps2port)
{
char *addr = ps2port->addr;
unsigned long flags;
spin_lock_irqsave(&ps2port->lock, flags);
gscps2_flush(ps2port);
writeb(0xff, addr+GSC_RESET);
gscps2_flush(ps2port);
spin_unlock_irqrestore(&ps2port->lock, flags);
}
static irqreturn_t gscps2_interrupt(int irq, void *dev)
{
struct gscps2port *ps2port;
list_for_each_entry(ps2port, &ps2port_list, node) {
unsigned long flags;
spin_lock_irqsave(&ps2port->lock, flags);
while ( (ps2port->buffer[ps2port->append].str =
gscps2_readb_status(ps2port->addr)) & GSC_STAT_RBNE ) {
ps2port->buffer[ps2port->append].data =
gscps2_readb_input(ps2port->addr);
ps2port->append = ((ps2port->append+1) & BUFFER_SIZE);
}
spin_unlock_irqrestore(&ps2port->lock, flags);
}
list_for_each_entry(ps2port, &ps2port_list, node) {
while (ps2port->act != ps2port->append) {
unsigned int rxflags;
u8 data, status;
if (gscps2_readb_status(ps2port->addr) & GSC_STAT_CMPINTR)
return IRQ_HANDLED;
status = ps2port->buffer[ps2port->act].str;
data = ps2port->buffer[ps2port->act].data;
ps2port->act = ((ps2port->act+1) & BUFFER_SIZE);
rxflags = ((status & GSC_STAT_TERR) ? SERIO_TIMEOUT : 0 ) |
((status & GSC_STAT_PERR) ? SERIO_PARITY : 0 );
serio_interrupt(ps2port->port, data, rxflags);
}
}
return IRQ_HANDLED;
}
static int gscps2_write(struct serio *port, unsigned char data)
{
struct gscps2port *ps2port = port->port_data;
if (!gscps2_writeb_output(ps2port, data)) {
printk(KERN_DEBUG PFX "sending byte %#x failed.\n", data);
return -1;
}
return 0;
}
static int gscps2_open(struct serio *port)
{
struct gscps2port *ps2port = port->port_data;
gscps2_reset(ps2port);
gscps2_enable(ps2port, ENABLE);
gscps2_interrupt(0, NULL);
return 0;
}
static void gscps2_close(struct serio *port)
{
struct gscps2port *ps2port = port->port_data;
gscps2_enable(ps2port, DISABLE);
}
static int gscps2_probe(struct parisc_device *dev)
{
struct gscps2port *ps2port;
struct serio *serio;
unsigned long hpa = dev->hpa.start;
int ret;
if (!dev->irq)
return -ENODEV;
if (dev->id.sversion == 0x96)
hpa += GSC_DINO_OFFSET;
ps2port = kzalloc(sizeof(struct gscps2port), GFP_KERNEL);
serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!ps2port || !serio) {
ret = -ENOMEM;
goto fail_nomem;
}
dev_set_drvdata(&dev->dev, ps2port);
ps2port->port = serio;
ps2port->padev = dev;
ps2port->addr = ioremap_nocache(hpa, GSC_STATUS + 4);
spin_lock_init(&ps2port->lock);
gscps2_reset(ps2port);
ps2port->id = readb(ps2port->addr + GSC_ID) & 0x0f;
snprintf(serio->name, sizeof(serio->name), "gsc-ps2-%s",
(ps2port->id == GSC_ID_KEYBOARD) ? "keyboard" : "mouse");
strlcpy(serio->phys, dev_name(&dev->dev), sizeof(serio->phys));
serio->id.type = SERIO_8042;
serio->write = gscps2_write;
serio->open = gscps2_open;
serio->close = gscps2_close;
serio->port_data = ps2port;
serio->dev.parent = &dev->dev;
ret = -EBUSY;
if (request_irq(dev->irq, gscps2_interrupt, IRQF_SHARED, ps2port->port->name, ps2port))
goto fail_miserably;
if (ps2port->id != GSC_ID_KEYBOARD && ps2port->id != GSC_ID_MOUSE) {
printk(KERN_WARNING PFX "Unsupported PS/2 port at 0x%08lx (id=%d) ignored\n",
hpa, ps2port->id);
ret = -ENODEV;
goto fail;
}
#if 0
if (!request_mem_region(hpa, GSC_STATUS + 4, ps2port->port.name))
goto fail;
#endif
printk(KERN_INFO "serio: %s port at 0x%p irq %d @ %s\n",
ps2port->port->name,
ps2port->addr,
ps2port->padev->irq,
ps2port->port->phys);
serio_register_port(ps2port->port);
list_add_tail(&ps2port->node, &ps2port_list);
return 0;
fail:
free_irq(dev->irq, ps2port);
fail_miserably:
iounmap(ps2port->addr);
release_mem_region(dev->hpa.start, GSC_STATUS + 4);
fail_nomem:
kfree(ps2port);
kfree(serio);
return ret;
}
static int gscps2_remove(struct parisc_device *dev)
{
struct gscps2port *ps2port = dev_get_drvdata(&dev->dev);
serio_unregister_port(ps2port->port);
free_irq(dev->irq, ps2port);
gscps2_flush(ps2port);
list_del(&ps2port->node);
iounmap(ps2port->addr);
#if 0
release_mem_region(dev->hpa, GSC_STATUS + 4);
#endif
dev_set_drvdata(&dev->dev, NULL);
kfree(ps2port);
return 0;
}
static int __init gscps2_init(void)
{
register_parisc_driver(&parisc_ps2_driver);
return 0;
}
static void __exit gscps2_exit(void)
{
unregister_parisc_driver(&parisc_ps2_driver);
}
