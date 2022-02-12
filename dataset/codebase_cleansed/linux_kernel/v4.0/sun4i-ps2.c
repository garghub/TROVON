static irqreturn_t sun4i_ps2_interrupt(int irq, void *dev_id)
{
struct sun4i_ps2data *drvdata = dev_id;
u32 intr_status;
u32 fifo_status;
unsigned char byte;
unsigned int rxflags = 0;
u32 rval;
spin_lock(&drvdata->lock);
intr_status = readl(drvdata->reg_base + PS2_REG_LSTS);
fifo_status = readl(drvdata->reg_base + PS2_REG_FSTS);
if (intr_status & PS2_LINE_ERROR_BIT) {
rxflags = (intr_status & PS2_LINE_ERROR_BIT) ? SERIO_FRAME : 0;
rxflags |= (intr_status & PS2_LSTS_PARERR) ? SERIO_PARITY : 0;
rxflags |= (intr_status & PS2_LSTS_PARERR) ? SERIO_TIMEOUT : 0;
rval = PS2_LSTS_TXTDO | PS2_LSTS_STOPERR | PS2_LSTS_ACKERR |
PS2_LSTS_PARERR | PS2_LSTS_RXTDO;
writel(rval, drvdata->reg_base + PS2_REG_LSTS);
}
if (fifo_status & PS2_FIFO_ERROR_BIT) {
rval = PS2_FSTS_TXUF | PS2_FSTS_TXOF | PS2_FSTS_TXRDY |
PS2_FSTS_RXUF | PS2_FSTS_RXOF | PS2_FSTS_RXRDY;
writel(rval, drvdata->reg_base + PS2_REG_FSTS);
}
rval = (fifo_status >> 16) & 0x3;
while (rval--) {
byte = readl(drvdata->reg_base + PS2_REG_DATA) & 0xff;
serio_interrupt(drvdata->serio, byte, rxflags);
}
writel(intr_status, drvdata->reg_base + PS2_REG_LSTS);
writel(fifo_status, drvdata->reg_base + PS2_REG_FSTS);
spin_unlock(&drvdata->lock);
return IRQ_HANDLED;
}
static int sun4i_ps2_open(struct serio *serio)
{
struct sun4i_ps2data *drvdata = serio->port_data;
u32 src_clk = 0;
u32 clk_scdf;
u32 clk_pcdf;
u32 rval;
unsigned long flags;
rval = PS2_LCTL_STOPERREN | PS2_LCTL_ACKERREN
| PS2_LCTL_PARERREN | PS2_LCTL_RXDTOEN;
writel(rval, drvdata->reg_base + PS2_REG_LCTL);
rval = PS2_FCTL_TXRST | PS2_FCTL_RXRST | PS2_FCTL_TXUFIEN
| PS2_FCTL_TXOFIEN | PS2_FCTL_RXUFIEN
| PS2_FCTL_RXOFIEN | PS2_FCTL_RXRDYIEN;
writel(rval, drvdata->reg_base + PS2_REG_FCTL);
src_clk = clk_get_rate(drvdata->clk);
clk_scdf = src_clk / PS2_SAMPLE_CLK - 1;
clk_pcdf = PS2_SAMPLE_CLK / PS2_SCLK - 1;
rval = (clk_scdf << 8) | clk_pcdf;
writel(rval, drvdata->reg_base + PS2_REG_CLKDR);
rval = PS2_GCTL_RESET | PS2_GCTL_INTEN | PS2_GCTL_MASTER
| PS2_GCTL_BUSEN;
spin_lock_irqsave(&drvdata->lock, flags);
writel(rval, drvdata->reg_base + PS2_REG_GCTL);
spin_unlock_irqrestore(&drvdata->lock, flags);
return 0;
}
static void sun4i_ps2_close(struct serio *serio)
{
struct sun4i_ps2data *drvdata = serio->port_data;
u32 rval;
rval = readl(drvdata->reg_base + PS2_REG_GCTL);
writel(rval & ~(PS2_GCTL_INTEN), drvdata->reg_base + PS2_REG_GCTL);
synchronize_irq(drvdata->irq);
}
static int sun4i_ps2_write(struct serio *serio, unsigned char val)
{
unsigned long expire = jiffies + msecs_to_jiffies(10000);
struct sun4i_ps2data *drvdata = serio->port_data;
do {
if (readl(drvdata->reg_base + PS2_REG_FSTS) & PS2_FSTS_TXRDY) {
writel(val, drvdata->reg_base + PS2_REG_DATA);
return 0;
}
} while (time_before(jiffies, expire));
return SERIO_TIMEOUT;
}
static int sun4i_ps2_probe(struct platform_device *pdev)
{
struct resource *res;
struct sun4i_ps2data *drvdata;
struct serio *serio;
struct device *dev = &pdev->dev;
unsigned int irq;
int error;
drvdata = kzalloc(sizeof(struct sun4i_ps2data), GFP_KERNEL);
serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!drvdata || !serio) {
error = -ENOMEM;
goto err_free_mem;
}
spin_lock_init(&drvdata->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "failed to locate registers\n");
error = -ENXIO;
goto err_free_mem;
}
drvdata->reg_base = ioremap(res->start, resource_size(res));
if (!drvdata->reg_base) {
dev_err(dev, "failed to map registers\n");
error = -ENOMEM;
goto err_free_mem;
}
drvdata->clk = clk_get(dev, NULL);
if (IS_ERR(drvdata->clk)) {
error = PTR_ERR(drvdata->clk);
dev_err(dev, "couldn't get clock %d\n", error);
goto err_ioremap;
}
error = clk_prepare_enable(drvdata->clk);
if (error) {
dev_err(dev, "failed to enable clock %d\n", error);
goto err_clk;
}
serio->id.type = SERIO_8042;
serio->write = sun4i_ps2_write;
serio->open = sun4i_ps2_open;
serio->close = sun4i_ps2_close;
serio->port_data = drvdata;
serio->dev.parent = dev;
strlcpy(serio->name, dev_name(dev), sizeof(serio->name));
strlcpy(serio->phys, dev_name(dev), sizeof(serio->phys));
writel(0, drvdata->reg_base + PS2_REG_GCTL);
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(dev, "no IRQ found\n");
error = -ENXIO;
goto err_disable_clk;
}
drvdata->irq = irq;
drvdata->serio = serio;
drvdata->dev = dev;
error = request_irq(drvdata->irq, sun4i_ps2_interrupt, 0,
DRIVER_NAME, drvdata);
if (error) {
dev_err(drvdata->dev, "failed to allocate interrupt %d: %d\n",
drvdata->irq, error);
goto err_disable_clk;
}
serio_register_port(serio);
platform_set_drvdata(pdev, drvdata);
return 0;
err_disable_clk:
clk_disable_unprepare(drvdata->clk);
err_clk:
clk_put(drvdata->clk);
err_ioremap:
iounmap(drvdata->reg_base);
err_free_mem:
kfree(serio);
kfree(drvdata);
return error;
}
static int sun4i_ps2_remove(struct platform_device *pdev)
{
struct sun4i_ps2data *drvdata = platform_get_drvdata(pdev);
serio_unregister_port(drvdata->serio);
free_irq(drvdata->irq, drvdata);
clk_disable_unprepare(drvdata->clk);
clk_put(drvdata->clk);
iounmap(drvdata->reg_base);
kfree(drvdata);
return 0;
}
