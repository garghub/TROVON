static irqreturn_t altera_ps2_rxint(int irq, void *dev_id)
{
struct ps2if *ps2if = dev_id;
unsigned int status;
int handled = IRQ_NONE;
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
writel(0, ps2if->base);
}
static int altera_ps2_probe(struct platform_device *pdev)
{
struct ps2if *ps2if;
struct serio *serio;
int error, irq;
ps2if = kzalloc(sizeof(struct ps2if), GFP_KERNEL);
serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!ps2if || !serio) {
error = -ENOMEM;
goto err_free_mem;
}
serio->id.type = SERIO_8042;
serio->write = altera_ps2_write;
serio->open = altera_ps2_open;
serio->close = altera_ps2_close;
strlcpy(serio->name, dev_name(&pdev->dev), sizeof(serio->name));
strlcpy(serio->phys, dev_name(&pdev->dev), sizeof(serio->phys));
serio->port_data = ps2if;
serio->dev.parent = &pdev->dev;
ps2if->io = serio;
ps2if->iomem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (ps2if->iomem_res == NULL) {
error = -ENOENT;
goto err_free_mem;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
error = -ENXIO;
goto err_free_mem;
}
ps2if->irq = irq;
if (!request_mem_region(ps2if->iomem_res->start,
resource_size(ps2if->iomem_res), pdev->name)) {
error = -EBUSY;
goto err_free_mem;
}
ps2if->base = ioremap(ps2if->iomem_res->start,
resource_size(ps2if->iomem_res));
if (!ps2if->base) {
error = -ENOMEM;
goto err_free_res;
}
error = request_irq(ps2if->irq, altera_ps2_rxint, 0, pdev->name, ps2if);
if (error) {
dev_err(&pdev->dev, "could not allocate IRQ %d: %d\n",
ps2if->irq, error);
goto err_unmap;
}
dev_info(&pdev->dev, "base %p, irq %d\n", ps2if->base, ps2if->irq);
serio_register_port(ps2if->io);
platform_set_drvdata(pdev, ps2if);
return 0;
err_unmap:
iounmap(ps2if->base);
err_free_res:
release_mem_region(ps2if->iomem_res->start,
resource_size(ps2if->iomem_res));
err_free_mem:
kfree(ps2if);
kfree(serio);
return error;
}
static int altera_ps2_remove(struct platform_device *pdev)
{
struct ps2if *ps2if = platform_get_drvdata(pdev);
serio_unregister_port(ps2if->io);
free_irq(ps2if->irq, ps2if);
iounmap(ps2if->base);
release_mem_region(ps2if->iomem_res->start,
resource_size(ps2if->iomem_res));
kfree(ps2if);
return 0;
}
