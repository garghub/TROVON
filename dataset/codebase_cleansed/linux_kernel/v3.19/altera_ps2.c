static irqreturn_t altera_ps2_rxint(int irq, void *dev_id)
{
struct ps2if *ps2if = dev_id;
unsigned int status;
irqreturn_t handled = IRQ_NONE;
while ((status = readl(ps2if->base)) & 0xffff0000) {
serio_interrupt(ps2if->io, status & 0xff, 0);
handled = IRQ_HANDLED;
}
return handled;
}
static int altera_ps2_write(struct serio *io, unsigned char val)
{
struct ps2if *ps2if = io->port_data;
writel(val, ps2if->base);
return 0;
}
static int altera_ps2_open(struct serio *io)
{
struct ps2if *ps2if = io->port_data;
while (readl(ps2if->base) & 0xffff0000)
;
writel(1, ps2if->base + 4);
return 0;
}
static void altera_ps2_close(struct serio *io)
{
struct ps2if *ps2if = io->port_data;
writel(0, ps2if->base + 4);
}
static int altera_ps2_probe(struct platform_device *pdev)
{
struct ps2if *ps2if;
struct resource *res;
struct serio *serio;
int error, irq;
ps2if = devm_kzalloc(&pdev->dev, sizeof(struct ps2if), GFP_KERNEL);
if (!ps2if)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ps2if->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ps2if->base))
return PTR_ERR(ps2if->base);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -ENXIO;
error = devm_request_irq(&pdev->dev, irq, altera_ps2_rxint, 0,
pdev->name, ps2if);
if (error) {
dev_err(&pdev->dev, "could not request IRQ %d\n", irq);
return error;
}
serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!serio)
return -ENOMEM;
serio->id.type = SERIO_8042;
serio->write = altera_ps2_write;
serio->open = altera_ps2_open;
serio->close = altera_ps2_close;
strlcpy(serio->name, dev_name(&pdev->dev), sizeof(serio->name));
strlcpy(serio->phys, dev_name(&pdev->dev), sizeof(serio->phys));
serio->port_data = ps2if;
serio->dev.parent = &pdev->dev;
ps2if->io = serio;
dev_info(&pdev->dev, "base %p, irq %d\n", ps2if->base, irq);
serio_register_port(ps2if->io);
platform_set_drvdata(pdev, ps2if);
return 0;
}
static int altera_ps2_remove(struct platform_device *pdev)
{
struct ps2if *ps2if = platform_get_drvdata(pdev);
serio_unregister_port(ps2if->io);
return 0;
}
