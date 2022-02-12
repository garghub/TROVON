static irqreturn_t pxa930_trkball_interrupt(int irq, void *dev_id)
{
struct pxa930_trkball *trkball = dev_id;
struct input_dev *input = trkball->input;
int tbcntr, x, y;
tbcntr = __raw_readl(trkball->mmio_base + TBCNTR);
if (tbcntr == __raw_readl(trkball->mmio_base + TBCNTR)) {
x = (TBCNTR_XP(tbcntr) - TBCNTR_XM(tbcntr)) / 2;
y = (TBCNTR_YP(tbcntr) - TBCNTR_YM(tbcntr)) / 2;
input_report_rel(input, REL_X, x);
input_report_rel(input, REL_Y, y);
input_sync(input);
}
__raw_writel(TBSBC_TBSBC, trkball->mmio_base + TBSBC);
__raw_writel(0, trkball->mmio_base + TBSBC);
return IRQ_HANDLED;
}
static int write_tbcr(struct pxa930_trkball *trkball, int v)
{
int i = 100;
__raw_writel(v, trkball->mmio_base + TBCR);
while (--i) {
if (__raw_readl(trkball->mmio_base + TBCR) == v)
break;
msleep(1);
}
if (i == 0) {
pr_err("%s: timed out writing TBCR(%x)!\n", __func__, v);
return -ETIMEDOUT;
}
return 0;
}
static void pxa930_trkball_config(struct pxa930_trkball *trkball)
{
uint32_t tbcr;
tbcr = __raw_readl(trkball->mmio_base + TBCR);
write_tbcr(trkball, tbcr | TBCR_X_FLT(0xf) | TBCR_Y_FLT(0xf));
write_tbcr(trkball, TBCR_X_FLT(trkball->pdata->x_filter) |
TBCR_Y_FLT(trkball->pdata->y_filter));
tbcr = __raw_readl(trkball->mmio_base + TBCR);
write_tbcr(trkball, tbcr | TBCR_TBRST);
write_tbcr(trkball, tbcr & ~TBCR_TBRST);
__raw_writel(TBSBC_TBSBC, trkball->mmio_base + TBSBC);
__raw_writel(0, trkball->mmio_base + TBSBC);
pr_debug("%s: final TBCR=%x!\n", __func__,
__raw_readl(trkball->mmio_base + TBCR));
}
static int pxa930_trkball_open(struct input_dev *dev)
{
struct pxa930_trkball *trkball = input_get_drvdata(dev);
pxa930_trkball_config(trkball);
return 0;
}
static void pxa930_trkball_disable(struct pxa930_trkball *trkball)
{
uint32_t tbcr = __raw_readl(trkball->mmio_base + TBCR);
write_tbcr(trkball, tbcr | TBCR_TBRST);
}
static void pxa930_trkball_close(struct input_dev *dev)
{
struct pxa930_trkball *trkball = input_get_drvdata(dev);
pxa930_trkball_disable(trkball);
}
static int pxa930_trkball_probe(struct platform_device *pdev)
{
struct pxa930_trkball *trkball;
struct input_dev *input;
struct resource *res;
int irq, error;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get trkball irq\n");
return -ENXIO;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get register memory\n");
return -ENXIO;
}
trkball = kzalloc(sizeof(struct pxa930_trkball), GFP_KERNEL);
if (!trkball)
return -ENOMEM;
trkball->pdata = dev_get_platdata(&pdev->dev);
if (!trkball->pdata) {
dev_err(&pdev->dev, "no platform data defined\n");
error = -EINVAL;
goto failed;
}
trkball->mmio_base = ioremap_nocache(res->start, resource_size(res));
if (!trkball->mmio_base) {
dev_err(&pdev->dev, "failed to ioremap registers\n");
error = -ENXIO;
goto failed;
}
pxa930_trkball_disable(trkball);
error = request_irq(irq, pxa930_trkball_interrupt, 0,
pdev->name, trkball);
if (error) {
dev_err(&pdev->dev, "failed to request irq: %d\n", error);
goto failed_free_io;
}
platform_set_drvdata(pdev, trkball);
input = input_allocate_device();
if (!input) {
dev_err(&pdev->dev, "failed to allocate input device\n");
error = -ENOMEM;
goto failed_free_irq;
}
input->name = pdev->name;
input->id.bustype = BUS_HOST;
input->open = pxa930_trkball_open;
input->close = pxa930_trkball_close;
input->dev.parent = &pdev->dev;
input_set_drvdata(input, trkball);
trkball->input = input;
input_set_capability(input, EV_REL, REL_X);
input_set_capability(input, EV_REL, REL_Y);
error = input_register_device(input);
if (error) {
dev_err(&pdev->dev, "unable to register input device\n");
goto failed_free_input;
}
return 0;
failed_free_input:
input_free_device(input);
failed_free_irq:
free_irq(irq, trkball);
failed_free_io:
iounmap(trkball->mmio_base);
failed:
kfree(trkball);
return error;
}
static int pxa930_trkball_remove(struct platform_device *pdev)
{
struct pxa930_trkball *trkball = platform_get_drvdata(pdev);
int irq = platform_get_irq(pdev, 0);
input_unregister_device(trkball->input);
free_irq(irq, trkball);
iounmap(trkball->mmio_base);
kfree(trkball);
return 0;
}
