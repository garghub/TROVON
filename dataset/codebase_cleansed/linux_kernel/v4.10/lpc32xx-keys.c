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
int err;
err = matrix_keypad_parse_of_params(dev, &rows, &columns);
if (err)
return err;
if (rows != columns) {
dev_err(dev, "rows and columns must be equal!\n");
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
if (irq < 0) {
dev_err(&pdev->dev, "failed to get platform irq\n");
return -EINVAL;
}
kscandat = devm_kzalloc(&pdev->dev, sizeof(*kscandat),
GFP_KERNEL);
if (!kscandat)
return -ENOMEM;
error = lpc32xx_parse_dt(&pdev->dev, kscandat);
if (error) {
dev_err(&pdev->dev, "failed to parse device tree\n");
return error;
}
keymap_size = sizeof(kscandat->keymap[0]) *
(kscandat->matrix_sz << kscandat->row_shift);
kscandat->keymap = devm_kzalloc(&pdev->dev, keymap_size, GFP_KERNEL);
if (!kscandat->keymap)
return -ENOMEM;
kscandat->input = input = devm_input_allocate_device(&pdev->dev);
if (!input) {
dev_err(&pdev->dev, "failed to allocate input device\n");
return -ENOMEM;
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
return error;
}
input_set_drvdata(kscandat->input, kscandat);
kscandat->kscan_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(kscandat->kscan_base))
return PTR_ERR(kscandat->kscan_base);
kscandat->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(kscandat->clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
return PTR_ERR(kscandat->clk);
}
error = clk_prepare_enable(kscandat->clk);
if (error)
return error;
writel(kscandat->deb_clks, LPC32XX_KS_DEB(kscandat->kscan_base));
writel(kscandat->scan_delay, LPC32XX_KS_SCAN_CTL(kscandat->kscan_base));
writel(LPC32XX_KSCAN_FTST_USE32K_CLK,
LPC32XX_KS_FAST_TST(kscandat->kscan_base));
writel(kscandat->matrix_sz,
LPC32XX_KS_MATRIX_DIM(kscandat->kscan_base));
writel(1, LPC32XX_KS_IRQ(kscandat->kscan_base));
clk_disable_unprepare(kscandat->clk);
error = devm_request_irq(&pdev->dev, irq, lpc32xx_kscan_irq, 0,
pdev->name, kscandat);
if (error) {
dev_err(&pdev->dev, "failed to request irq\n");
return error;
}
error = input_register_device(kscandat->input);
if (error) {
dev_err(&pdev->dev, "failed to register input device\n");
return error;
}
platform_set_drvdata(pdev, kscandat);
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
