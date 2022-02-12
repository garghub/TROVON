static irqreturn_t apbps2_isr(int irq, void *dev_id)
{
struct apbps2_priv *priv = dev_id;
unsigned long status, data, rxflags;
irqreturn_t ret = IRQ_NONE;
while ((status = ioread32be(&priv->regs->status)) & APBPS2_STATUS_DR) {
data = ioread32be(&priv->regs->data);
rxflags = (status & APBPS2_STATUS_PE) ? SERIO_PARITY : 0;
rxflags |= (status & APBPS2_STATUS_FE) ? SERIO_FRAME : 0;
if (rxflags)
iowrite32be(0, &priv->regs->status);
serio_interrupt(priv->io, data, rxflags);
ret = IRQ_HANDLED;
}
return ret;
}
static int apbps2_write(struct serio *io, unsigned char val)
{
struct apbps2_priv *priv = io->port_data;
unsigned int tleft = 10000;
while ((ioread32be(&priv->regs->status) & APBPS2_STATUS_TF) && tleft--)
udelay(10);
if ((ioread32be(&priv->regs->status) & APBPS2_STATUS_TF) == 0) {
iowrite32be(val, &priv->regs->data);
iowrite32be(APBPS2_CTRL_RE | APBPS2_CTRL_RI | APBPS2_CTRL_TE,
&priv->regs->ctrl);
return 0;
}
return -ETIMEDOUT;
}
static int apbps2_open(struct serio *io)
{
struct apbps2_priv *priv = io->port_data;
int limit;
unsigned long tmp;
iowrite32be(0, &priv->regs->status);
limit = 1024;
while ((ioread32be(&priv->regs->status) & APBPS2_STATUS_DR) && --limit)
tmp = ioread32be(&priv->regs->data);
iowrite32be(APBPS2_CTRL_RE | APBPS2_CTRL_RI, &priv->regs->ctrl);
return 0;
}
static void apbps2_close(struct serio *io)
{
struct apbps2_priv *priv = io->port_data;
iowrite32be(0, &priv->regs->ctrl);
}
static int apbps2_of_probe(struct platform_device *ofdev)
{
struct apbps2_priv *priv;
int irq, err;
u32 freq_hz;
struct resource *res;
priv = devm_kzalloc(&ofdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&ofdev->dev, "memory allocation failed\n");
return -ENOMEM;
}
res = platform_get_resource(ofdev, IORESOURCE_MEM, 0);
priv->regs = devm_ioremap_resource(&ofdev->dev, res);
if (IS_ERR(priv->regs))
return PTR_ERR(priv->regs);
iowrite32be(0, &priv->regs->ctrl);
irq = irq_of_parse_and_map(ofdev->dev.of_node, 0);
err = devm_request_irq(&ofdev->dev, irq, apbps2_isr,
IRQF_SHARED, "apbps2", priv);
if (err) {
dev_err(&ofdev->dev, "request IRQ%d failed\n", irq);
return err;
}
if (of_property_read_u32(ofdev->dev.of_node, "freq", &freq_hz)) {
dev_err(&ofdev->dev, "unable to get core frequency\n");
return -EINVAL;
}
iowrite32be(freq_hz / 10000, &priv->regs->reload);
priv->io = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!priv->io)
return -ENOMEM;
priv->io->id.type = SERIO_8042;
priv->io->open = apbps2_open;
priv->io->close = apbps2_close;
priv->io->write = apbps2_write;
priv->io->port_data = priv;
strlcpy(priv->io->name, "APBPS2 PS/2", sizeof(priv->io->name));
snprintf(priv->io->phys, sizeof(priv->io->phys),
"apbps2_%d", apbps2_idx++);
dev_info(&ofdev->dev, "irq = %d, base = 0x%p\n", irq, priv->regs);
serio_register_port(priv->io);
platform_set_drvdata(ofdev, priv);
return 0;
}
static int apbps2_of_remove(struct platform_device *of_dev)
{
struct apbps2_priv *priv = platform_get_drvdata(of_dev);
serio_unregister_port(priv->io);
return 0;
}
