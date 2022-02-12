static void lpc32xx_mod_states(struct lpc32xx_kscan_drv *kscandat, int col)
{
struct input_dev *input = kscandat->input;
unsigned row, changed, scancode, keycode;
u8 key;
key = readl(LPC32XX_KS_DATA(kscandat->kscan_base, col));
changed = key ^ kscandat->lastkeystates[col];
kscandat->lastkeystates[col] = key;
for (row = 0; changed; row++, changed >>= 1) {
if (changed & 1) {
scancode = MATRIX_SCAN_CODE(row, col,
kscandat->row_shift);
keycode = kscandat->keymap[scancode];
input_event(input, EV_MSC, MSC_SCAN, scancode);
input_report_key(input, keycode, key & (1 << row));
}
}
}
static irqreturn_t lpc32xx_kscan_irq(int irq, void *dev_id)
{
struct lpc32xx_kscan_drv *kscandat = dev_id;
int i;
for (i = 0; i < kscandat->matrix_sz; i++)
lpc32xx_mod_states(kscandat, i);
writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));
input_sync(kscandat->input);
return IRQ_HANDLED;
}
static int lpc32xx_kscan_open(struct input_dev *dev)
{
struct lpc32xx_kscan_drv *kscandat = input_get_drvdata(dev);
int error;
error = clk_prepare_enable(kscandat->clk);
if (error)
return error;
writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));
return 0;
}
static void lpc32xx_kscan_close(struct input_dev *dev)
{
struct lpc32xx_kscan_drv *kscandat = input_get_drvdata(dev);
writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));
clk_disable_unprepare(kscandat->clk);
}
static int lpc32xx_parse_dt(struct device *dev,
struct lpc32xx_kscan_drv *kscandat)
{
struct device_node *np = dev->of_node;
u32 rows = 0, columns = 0;
of_property_read_u32(np, "keypad,num-rows", &rows);
of_property_read_u32(np, "keypad,num-columns", &columns);
if (!rows || rows != columns) {
dev_err(dev,
"rows and columns must be specified and be equal!\n");
return -EINVAL;
}
kscandat->matrix_sz = rows;
kscandat->row_shift = get_count_order(columns);
of_property_read_u32(np, "nxp,debounce-delay-ms", &kscandat->deb_clks);
of_property_read_u32(np, "nxp,scan-delay-ms", &kscandat->scan_delay);
if (!kscandat->deb_clks || !kscandat->scan_delay) {
dev_err(dev, "debounce or scan delay not specified\n");
return -EINVAL;
}
return 0;
}
static int lpc32xx_kscan_probe(struct platform_device *pdev)
{
struct lpc32xx_kscan_drv *kscandat;
struct input_dev *input;
struct resource *res;
size_t keymap_size;
int error;
int irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get platform I/O memory\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0 || irq >= NR_IRQS) {
dev_err(&pdev->dev, "failed to get platform irq\n");
return -EINVAL;
}
kscandat = kzalloc(sizeof(struct lpc32xx_kscan_drv), GFP_KERNEL);
if (!kscandat) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
error = lpc32xx_parse_dt(&pdev->dev, kscandat);
if (error) {
dev_err(&pdev->dev, "failed to parse device tree\n");
goto err_free_mem;
}
keymap_size = sizeof(kscandat->keymap[0]) *
(kscandat->matrix_sz << kscandat->row_shift);
kscandat->keymap = kzalloc(keymap_size, GFP_KERNEL);
if (!kscandat->keymap) {
dev_err(&pdev->dev, "could not allocate memory for keymap\n");
error = -ENOMEM;
goto err_free_mem;
}
kscandat->input = input = input_allocate_device();
if (!input) {
dev_err(&pdev->dev, "failed to allocate input device\n");
error = -ENOMEM;
goto err_free_keymap;
}
input->name = pdev->name;
input->phys = "lpc32xx/input0";
input->id.vendor = 0x0001;
input->id.product = 0x0001;
input->id.version = 0x0100;
input->open = lpc32xx_kscan_open;
input->close = lpc32xx_kscan_close;
input->dev.parent = &pdev->dev;
input_set_capability(input, EV_MSC, MSC_SCAN);
error = matrix_keypad_build_keymap(NULL, NULL,
kscandat->matrix_sz,
kscandat->matrix_sz,
kscandat->keymap, kscandat->input);
if (error) {
dev_err(&pdev->dev, "failed to build keymap\n");
goto err_free_input;
}
input_set_drvdata(kscandat->input, kscandat);
kscandat->iores = request_mem_region(res->start, resource_size(res),
pdev->name);
if (!kscandat->iores) {
dev_err(&pdev->dev, "failed to request I/O memory\n");
error = -EBUSY;
goto err_free_input;
}
kscandat->kscan_base = ioremap(kscandat->iores->start,
resource_size(kscandat->iores));
if (!kscandat->kscan_base) {
dev_err(&pdev->dev, "failed to remap I/O memory\n");
error = -EBUSY;
goto err_release_memregion;
}
kscandat->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(kscandat->clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
error = PTR_ERR(kscandat->clk);
goto err_unmap;
}
error = clk_prepare_enable(kscandat->clk);
if (error)
goto err_clk_put;
writel(kscandat->deb_clks, LPC32XX_KS_DEB(kscandat->kscan_base));
writel(kscandat->scan_delay, LPC32XX_KS_SCAN_CTL(kscandat->kscan_base));
writel(LPC32XX_KSCAN_FTST_USE32K_CLK,
LPC32XX_KS_FAST_TST(kscandat->kscan_base));
writel(kscandat->matrix_sz,
LPC32XX_KS_MATRIX_DIM(kscandat->kscan_base));
writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));
clk_disable_unprepare(kscandat->clk);
error = request_irq(irq, lpc32xx_kscan_irq, 0, pdev->name, kscandat);
if (error) {
dev_err(&pdev->dev, "failed to request irq\n");
goto err_clk_put;
}
error = input_register_device(kscandat->input);
if (error) {
dev_err(&pdev->dev, "failed to register input device\n");
goto err_free_irq;
}
platform_set_drvdata(pdev, kscandat);
return 0;
err_free_irq:
free_irq(irq, kscandat);
err_clk_put:
clk_put(kscandat->clk);
err_unmap:
iounmap(kscandat->kscan_base);
err_release_memregion:
release_mem_region(kscandat->iores->start,
resource_size(kscandat->iores));
err_free_input:
input_free_device(kscandat->input);
err_free_keymap:
kfree(kscandat->keymap);
err_free_mem:
kfree(kscandat);
return error;
}
static int lpc32xx_kscan_remove(struct platform_device *pdev)
{
struct lpc32xx_kscan_drv *kscandat = platform_get_drvdata(pdev);
free_irq(platform_get_irq(pdev, 0), kscandat);
clk_put(kscandat->clk);
iounmap(kscandat->kscan_base);
release_mem_region(kscandat->iores->start,
resource_size(kscandat->iores));
input_unregister_device(kscandat->input);
kfree(kscandat->keymap);
kfree(kscandat);
return 0;
}
static int lpc32xx_kscan_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct lpc32xx_kscan_drv *kscandat = platform_get_drvdata(pdev);
struct input_dev *input = kscandat->input;
mutex_lock(&input->mutex);
if (input->users) {
writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));
clk_disable_unprepare(kscandat->clk);
}
mutex_unlock(&input->mutex);
return 0;
}
static int lpc32xx_kscan_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct lpc32xx_kscan_drv *kscandat = platform_get_drvdata(pdev);
struct input_dev *input = kscandat->input;
int retval = 0;
mutex_lock(&input->mutex);
if (input->users) {
retval = clk_prepare_enable(kscandat->clk);
if (retval == 0)
writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));
}
mutex_unlock(&input->mutex);
return retval;
}
