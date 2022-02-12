static inline struct ax_drvdata *pp_to_drv(struct parport *p)
{
return p->private_data;
}
static unsigned char
parport_ax88796_read_data(struct parport *p)
{
struct ax_drvdata *dd = pp_to_drv(p);
return readb(dd->spp_data);
}
static void
parport_ax88796_write_data(struct parport *p, unsigned char data)
{
struct ax_drvdata *dd = pp_to_drv(p);
writeb(data, dd->spp_data);
}
static unsigned char
parport_ax88796_read_control(struct parport *p)
{
struct ax_drvdata *dd = pp_to_drv(p);
unsigned int cpr = readb(dd->spp_cpr);
unsigned int ret = 0;
if (!(cpr & AX_CPR_STRB))
ret |= PARPORT_CONTROL_STROBE;
if (!(cpr & AX_CPR_ATFD))
ret |= PARPORT_CONTROL_AUTOFD;
if (cpr & AX_CPR_nINIT)
ret |= PARPORT_CONTROL_INIT;
if (!(cpr & AX_CPR_SLCTIN))
ret |= PARPORT_CONTROL_SELECT;
return ret;
}
static void
parport_ax88796_write_control(struct parport *p, unsigned char control)
{
struct ax_drvdata *dd = pp_to_drv(p);
unsigned int cpr = readb(dd->spp_cpr);
cpr &= AX_CPR_nDOE;
if (!(control & PARPORT_CONTROL_STROBE))
cpr |= AX_CPR_STRB;
if (!(control & PARPORT_CONTROL_AUTOFD))
cpr |= AX_CPR_ATFD;
if (control & PARPORT_CONTROL_INIT)
cpr |= AX_CPR_nINIT;
if (!(control & PARPORT_CONTROL_SELECT))
cpr |= AX_CPR_SLCTIN;
dev_dbg(dd->dev, "write_control: ctrl=%02x, cpr=%02x\n", control, cpr);
writeb(cpr, dd->spp_cpr);
if (parport_ax88796_read_control(p) != control) {
dev_err(dd->dev, "write_control: read != set (%02x, %02x)\n",
parport_ax88796_read_control(p), control);
}
}
static unsigned char
parport_ax88796_read_status(struct parport *p)
{
struct ax_drvdata *dd = pp_to_drv(p);
unsigned int status = readb(dd->spp_spr);
unsigned int ret = 0;
if (status & AX_SPR_BUSY)
ret |= PARPORT_STATUS_BUSY;
if (status & AX_SPR_ACK)
ret |= PARPORT_STATUS_ACK;
if (status & AX_SPR_ERR)
ret |= PARPORT_STATUS_ERROR;
if (status & AX_SPR_SLCT)
ret |= PARPORT_STATUS_SELECT;
if (status & AX_SPR_PE)
ret |= PARPORT_STATUS_PAPEROUT;
return ret;
}
static unsigned char
parport_ax88796_frob_control(struct parport *p, unsigned char mask,
unsigned char val)
{
struct ax_drvdata *dd = pp_to_drv(p);
unsigned char old = parport_ax88796_read_control(p);
dev_dbg(dd->dev, "frob: mask=%02x, val=%02x, old=%02x\n",
mask, val, old);
parport_ax88796_write_control(p, (old & ~mask) | val);
return old;
}
static void
parport_ax88796_enable_irq(struct parport *p)
{
struct ax_drvdata *dd = pp_to_drv(p);
unsigned long flags;
local_irq_save(flags);
if (!dd->irq_enabled) {
enable_irq(p->irq);
dd->irq_enabled = 1;
}
local_irq_restore(flags);
}
static void
parport_ax88796_disable_irq(struct parport *p)
{
struct ax_drvdata *dd = pp_to_drv(p);
unsigned long flags;
local_irq_save(flags);
if (dd->irq_enabled) {
disable_irq(p->irq);
dd->irq_enabled = 0;
}
local_irq_restore(flags);
}
static void
parport_ax88796_data_forward(struct parport *p)
{
struct ax_drvdata *dd = pp_to_drv(p);
void __iomem *cpr = dd->spp_cpr;
writeb((readb(cpr) & ~AX_CPR_nDOE), cpr);
}
static void
parport_ax88796_data_reverse(struct parport *p)
{
struct ax_drvdata *dd = pp_to_drv(p);
void __iomem *cpr = dd->spp_cpr;
writeb(readb(cpr) | AX_CPR_nDOE, cpr);
}
static void
parport_ax88796_init_state(struct pardevice *d, struct parport_state *s)
{
struct ax_drvdata *dd = pp_to_drv(d->port);
memset(s, 0, sizeof(struct parport_state));
dev_dbg(dd->dev, "init_state: %p: state=%p\n", d, s);
s->u.ax88796.cpr = readb(dd->spp_cpr);
}
static void
parport_ax88796_save_state(struct parport *p, struct parport_state *s)
{
struct ax_drvdata *dd = pp_to_drv(p);
dev_dbg(dd->dev, "save_state: %p: state=%p\n", p, s);
s->u.ax88796.cpr = readb(dd->spp_cpr);
}
static void
parport_ax88796_restore_state(struct parport *p, struct parport_state *s)
{
struct ax_drvdata *dd = pp_to_drv(p);
dev_dbg(dd->dev, "restore_state: %p: state=%p\n", p, s);
writeb(s->u.ax88796.cpr, dd->spp_cpr);
}
static int parport_ax88796_probe(struct platform_device *pdev)
{
struct device *_dev = &pdev->dev;
struct ax_drvdata *dd;
struct parport *pp = NULL;
struct resource *res;
unsigned long size;
int spacing;
int irq;
int ret;
dd = kzalloc(sizeof(struct ax_drvdata), GFP_KERNEL);
if (dd == NULL) {
dev_err(_dev, "no memory for private data\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(_dev, "no MEM specified\n");
ret = -ENXIO;
goto exit_mem;
}
size = resource_size(res);
spacing = size / 3;
dd->io = request_mem_region(res->start, size, pdev->name);
if (dd->io == NULL) {
dev_err(_dev, "cannot reserve memory\n");
ret = -ENXIO;
goto exit_mem;
}
dd->base = ioremap(res->start, size);
if (dd->base == NULL) {
dev_err(_dev, "cannot ioremap region\n");
ret = -ENXIO;
goto exit_res;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
irq = PARPORT_IRQ_NONE;
pp = parport_register_port((unsigned long)dd->base, irq,
PARPORT_DMA_NONE,
&parport_ax88796_ops);
if (pp == NULL) {
dev_err(_dev, "failed to register parallel port\n");
ret = -ENOMEM;
goto exit_unmap;
}
pp->private_data = dd;
dd->parport = pp;
dd->dev = _dev;
dd->spp_data = dd->base;
dd->spp_spr = dd->base + (spacing * 1);
dd->spp_cpr = dd->base + (spacing * 2);
writeb(AX_CPR_STRB, dd->spp_cpr);
if (irq >= 0) {
ret = request_irq(irq, parport_irq_handler,
IRQF_TRIGGER_FALLING, pdev->name, pp);
if (ret < 0)
goto exit_port;
dd->irq_enabled = 1;
}
platform_set_drvdata(pdev, pp);
dev_info(_dev, "attached parallel port driver\n");
parport_announce_port(pp);
return 0;
exit_port:
parport_remove_port(pp);
exit_unmap:
iounmap(dd->base);
exit_res:
release_mem_region(dd->io->start, size);
exit_mem:
kfree(dd);
return ret;
}
static int parport_ax88796_remove(struct platform_device *pdev)
{
struct parport *p = platform_get_drvdata(pdev);
struct ax_drvdata *dd = pp_to_drv(p);
free_irq(p->irq, p);
parport_remove_port(p);
iounmap(dd->base);
release_mem_region(dd->io->start, resource_size(dd->io));
kfree(dd);
return 0;
}
static int parport_ax88796_suspend(struct platform_device *dev,
pm_message_t state)
{
struct parport *p = platform_get_drvdata(dev);
struct ax_drvdata *dd = pp_to_drv(p);
parport_ax88796_save_state(p, &dd->suspend);
writeb(AX_CPR_nDOE | AX_CPR_STRB, dd->spp_cpr);
return 0;
}
static int parport_ax88796_resume(struct platform_device *dev)
{
struct parport *p = platform_get_drvdata(dev);
struct ax_drvdata *dd = pp_to_drv(p);
parport_ax88796_restore_state(p, &dd->suspend);
return 0;
}
