static int olpc_apsp_write(struct serio *port, unsigned char val)
{
struct olpc_apsp *priv = port->port_data;
unsigned int i;
u32 which = 0;
if (port == priv->padio)
which = TOUCHPAD_PORT << PORT_SHIFT;
else
which = KEYBOARD_PORT << PORT_SHIFT;
dev_dbg(priv->dev, "olpc_apsp_write which=%x val=%x\n", which, val);
for (i = 0; i < 50; i++) {
u32 sts = readl(priv->base + COMMAND_FIFO_STATUS);
if ((sts & CMD_CNTR_MASK) < MAX_PENDING_CMDS) {
writel(which | val,
priv->base + SECURE_PROCESSOR_COMMAND);
return 0;
}
mdelay(1);
}
dev_dbg(priv->dev, "olpc_apsp_write timeout, status=%x\n",
readl(priv->base + COMMAND_FIFO_STATUS));
return -ETIMEDOUT;
}
static irqreturn_t olpc_apsp_rx(int irq, void *dev_id)
{
struct olpc_apsp *priv = dev_id;
unsigned int w, tmp;
struct serio *serio;
tmp = readl(priv->base + PJ_RST_INTERRUPT);
if (!(tmp & SP_COMMAND_COMPLETE_RESET)) {
dev_warn(priv->dev, "spurious interrupt?\n");
return IRQ_NONE;
}
w = readl(priv->base + COMMAND_RETURN_STATUS);
dev_dbg(priv->dev, "olpc_apsp_rx %x\n", w);
if (w >> PORT_SHIFT == KEYBOARD_PORT)
serio = priv->kbio;
else
serio = priv->padio;
serio_interrupt(serio, w & DATA_MASK, 0);
writel(tmp | SP_COMMAND_COMPLETE_RESET, priv->base + PJ_RST_INTERRUPT);
writel(PORT_MASK, priv->base + SECURE_PROCESSOR_COMMAND);
pm_wakeup_event(priv->dev, 1000);
return IRQ_HANDLED;
}
static int olpc_apsp_open(struct serio *port)
{
struct olpc_apsp *priv = port->port_data;
unsigned int tmp;
if (priv->open_count++ == 0) {
tmp = readl(priv->base + PJ_INTERRUPT_MASK);
writel(tmp & ~INT_0, priv->base + PJ_INTERRUPT_MASK);
}
return 0;
}
static void olpc_apsp_close(struct serio *port)
{
struct olpc_apsp *priv = port->port_data;
unsigned int tmp;
if (--priv->open_count == 0) {
tmp = readl(priv->base + PJ_INTERRUPT_MASK);
writel(tmp | INT_0, priv->base + PJ_INTERRUPT_MASK);
}
}
static int olpc_apsp_probe(struct platform_device *pdev)
{
struct serio *kb_serio, *pad_serio;
struct olpc_apsp *priv;
struct resource *res;
struct device_node *np;
unsigned long l;
int error;
priv = devm_kzalloc(&pdev->dev, sizeof(struct olpc_apsp), GFP_KERNEL);
if (!priv)
return -ENOMEM;
np = pdev->dev.of_node;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base)) {
dev_err(&pdev->dev, "Failed to map WTM registers\n");
return PTR_ERR(priv->base);
}
priv->irq = platform_get_irq(pdev, 0);
if (priv->irq < 0)
return priv->irq;
l = readl(priv->base + COMMAND_FIFO_STATUS);
if (!(l & CMD_STS_MASK)) {
dev_err(&pdev->dev, "SP cannot accept commands.\n");
return -EIO;
}
kb_serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!kb_serio)
return -ENOMEM;
kb_serio->id.type = SERIO_8042_XL;
kb_serio->write = olpc_apsp_write;
kb_serio->open = olpc_apsp_open;
kb_serio->close = olpc_apsp_close;
kb_serio->port_data = priv;
kb_serio->dev.parent = &pdev->dev;
strlcpy(kb_serio->name, "sp keyboard", sizeof(kb_serio->name));
strlcpy(kb_serio->phys, "sp/serio0", sizeof(kb_serio->phys));
priv->kbio = kb_serio;
serio_register_port(kb_serio);
pad_serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!pad_serio) {
error = -ENOMEM;
goto err_pad;
}
pad_serio->id.type = SERIO_8042;
pad_serio->write = olpc_apsp_write;
pad_serio->open = olpc_apsp_open;
pad_serio->close = olpc_apsp_close;
pad_serio->port_data = priv;
pad_serio->dev.parent = &pdev->dev;
strlcpy(pad_serio->name, "sp touchpad", sizeof(pad_serio->name));
strlcpy(pad_serio->phys, "sp/serio1", sizeof(pad_serio->phys));
priv->padio = pad_serio;
serio_register_port(pad_serio);
error = request_irq(priv->irq, olpc_apsp_rx, 0, "olpc-apsp", priv);
if (error) {
dev_err(&pdev->dev, "Failed to request IRQ\n");
goto err_irq;
}
priv->dev = &pdev->dev;
device_init_wakeup(priv->dev, 1);
platform_set_drvdata(pdev, priv);
dev_dbg(&pdev->dev, "probed successfully.\n");
return 0;
err_irq:
serio_unregister_port(pad_serio);
err_pad:
serio_unregister_port(kb_serio);
return error;
}
static int olpc_apsp_remove(struct platform_device *pdev)
{
struct olpc_apsp *priv = platform_get_drvdata(pdev);
free_irq(priv->irq, priv);
serio_unregister_port(priv->kbio);
serio_unregister_port(priv->padio);
return 0;
}
