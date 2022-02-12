static irqreturn_t psif_interrupt(int irq, void *_ptr)
{
struct psif *psif = _ptr;
int retval = IRQ_NONE;
unsigned int io_flags = 0;
unsigned long status;
status = psif_readl(psif, SR);
if (status & PSIF_BIT(RXRDY)) {
unsigned char val = (unsigned char) psif_readl(psif, RHR);
if (status & PSIF_BIT(PARITY))
io_flags |= SERIO_PARITY;
if (status & PSIF_BIT(OVRUN))
dev_err(&psif->pdev->dev, "overrun read error\n");
serio_interrupt(psif->io, val, io_flags);
retval = IRQ_HANDLED;
}
return retval;
}
static int psif_write(struct serio *io, unsigned char val)
{
struct psif *psif = io->port_data;
unsigned long flags;
int timeout = 10;
int retval = 0;
spin_lock_irqsave(&psif->lock, flags);
while (!(psif_readl(psif, SR) & PSIF_BIT(TXEMPTY)) && timeout--)
udelay(50);
if (timeout >= 0) {
psif_writel(psif, THR, val);
} else {
dev_dbg(&psif->pdev->dev, "timeout writing to THR\n");
retval = -EBUSY;
}
spin_unlock_irqrestore(&psif->lock, flags);
return retval;
}
static int psif_open(struct serio *io)
{
struct psif *psif = io->port_data;
int retval;
retval = clk_enable(psif->pclk);
if (retval)
return retval;
psif_writel(psif, CR, PSIF_BIT(CR_TXEN) | PSIF_BIT(CR_RXEN));
psif_writel(psif, IER, PSIF_BIT(RXRDY));
psif->open = true;
return retval;
}
static void psif_close(struct serio *io)
{
struct psif *psif = io->port_data;
psif->open = false;
psif_writel(psif, IDR, ~0UL);
psif_writel(psif, CR, PSIF_BIT(CR_TXDIS) | PSIF_BIT(CR_RXDIS));
clk_disable(psif->pclk);
}
static void psif_set_prescaler(struct psif *psif)
{
unsigned long prscv;
unsigned long rate = clk_get_rate(psif->pclk);
prscv = 100 * (rate / 1000000UL);
if (prscv > ((1<<PSIF_PSR_PRSCV_SIZE) - 1)) {
prscv = (1<<PSIF_PSR_PRSCV_SIZE) - 1;
dev_dbg(&psif->pdev->dev, "pclk too fast, "
"prescaler set to max\n");
}
clk_enable(psif->pclk);
psif_writel(psif, PSR, prscv);
clk_disable(psif->pclk);
}
static int __init psif_probe(struct platform_device *pdev)
{
struct resource *regs;
struct psif *psif;
struct serio *io;
struct clk *pclk;
int irq;
int ret;
psif = kzalloc(sizeof(struct psif), GFP_KERNEL);
if (!psif)
return -ENOMEM;
psif->pdev = pdev;
io = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!io) {
ret = -ENOMEM;
goto out_free_psif;
}
psif->io = io;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!regs) {
dev_dbg(&pdev->dev, "no mmio resources defined\n");
ret = -ENOMEM;
goto out_free_io;
}
psif->regs = ioremap(regs->start, resource_size(regs));
if (!psif->regs) {
ret = -ENOMEM;
dev_dbg(&pdev->dev, "could not map I/O memory\n");
goto out_free_io;
}
pclk = clk_get(&pdev->dev, "pclk");
if (IS_ERR(pclk)) {
dev_dbg(&pdev->dev, "could not get peripheral clock\n");
ret = PTR_ERR(pclk);
goto out_iounmap;
}
psif->pclk = pclk;
ret = clk_enable(pclk);
if (ret) {
dev_dbg(&pdev->dev, "could not enable pclk\n");
goto out_put_clk;
}
psif_writel(psif, CR, PSIF_BIT(CR_SWRST));
clk_disable(pclk);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_dbg(&pdev->dev, "could not get irq\n");
ret = -ENXIO;
goto out_put_clk;
}
ret = request_irq(irq, psif_interrupt, IRQF_SHARED, "at32psif", psif);
if (ret) {
dev_dbg(&pdev->dev, "could not request irq %d\n", irq);
goto out_put_clk;
}
psif->irq = irq;
io->id.type = SERIO_8042;
io->write = psif_write;
io->open = psif_open;
io->close = psif_close;
snprintf(io->name, sizeof(io->name), "AVR32 PS/2 port%d", pdev->id);
snprintf(io->phys, sizeof(io->phys), "at32psif/serio%d", pdev->id);
io->port_data = psif;
io->dev.parent = &pdev->dev;
psif_set_prescaler(psif);
spin_lock_init(&psif->lock);
serio_register_port(psif->io);
platform_set_drvdata(pdev, psif);
dev_info(&pdev->dev, "Atmel AVR32 PSIF PS/2 driver on 0x%08x irq %d\n",
(int)psif->regs, psif->irq);
return 0;
out_put_clk:
clk_put(psif->pclk);
out_iounmap:
iounmap(psif->regs);
out_free_io:
kfree(io);
out_free_psif:
kfree(psif);
return ret;
}
static int __exit psif_remove(struct platform_device *pdev)
{
struct psif *psif = platform_get_drvdata(pdev);
psif_writel(psif, IDR, ~0UL);
psif_writel(psif, CR, PSIF_BIT(CR_TXDIS) | PSIF_BIT(CR_RXDIS));
serio_unregister_port(psif->io);
iounmap(psif->regs);
free_irq(psif->irq, psif);
clk_put(psif->pclk);
kfree(psif);
return 0;
}
static int psif_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct psif *psif = platform_get_drvdata(pdev);
if (psif->open) {
psif_writel(psif, CR, PSIF_BIT(CR_RXDIS) | PSIF_BIT(CR_TXDIS));
clk_disable(psif->pclk);
}
return 0;
}
static int psif_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct psif *psif = platform_get_drvdata(pdev);
if (psif->open) {
clk_enable(psif->pclk);
psif_set_prescaler(psif);
psif_writel(psif, CR, PSIF_BIT(CR_RXEN) | PSIF_BIT(CR_TXEN));
}
return 0;
}
