static int __init davinci_ks_initialize(struct davinci_ks *davinci_ks)
{
struct device *dev = &davinci_ks->input->dev;
struct davinci_ks_platform_data *pdata = davinci_ks->pdata;
u32 matrix_ctrl;
__raw_writel(DAVINCI_KEYSCAN_INT_ALL,
davinci_ks->base + DAVINCI_KEYSCAN_INTENA);
__raw_writel(DAVINCI_KEYSCAN_INT_ALL,
davinci_ks->base + DAVINCI_KEYSCAN_INTCLR);
__raw_writel(pdata->strobe,
davinci_ks->base + DAVINCI_KEYSCAN_STRBWIDTH);
__raw_writel(pdata->interval,
davinci_ks->base + DAVINCI_KEYSCAN_INTERVAL);
__raw_writel(0x01,
davinci_ks->base + DAVINCI_KEYSCAN_CONTTIME);
switch (pdata->matrix_type) {
case DAVINCI_KEYSCAN_MATRIX_4X4:
matrix_ctrl = 0;
break;
case DAVINCI_KEYSCAN_MATRIX_5X3:
matrix_ctrl = (1 << 6);
break;
default:
dev_err(dev->parent, "wrong matrix type\n");
return -EINVAL;
}
__raw_writel(DAVINCI_KEYSCAN_AUTODET | DAVINCI_KEYSCAN_KEYEN |
matrix_ctrl, davinci_ks->base + DAVINCI_KEYSCAN_KEYCTRL);
return 0;
}
static irqreturn_t davinci_ks_interrupt(int irq, void *dev_id)
{
struct davinci_ks *davinci_ks = dev_id;
struct device *dev = &davinci_ks->input->dev;
unsigned short *keymap = davinci_ks->keymap;
int keymapsize = davinci_ks->pdata->keymapsize;
u32 prev_status, new_status, changed;
bool release;
int keycode = KEY_UNKNOWN;
int i;
__raw_writel(0x0, davinci_ks->base + DAVINCI_KEYSCAN_INTENA);
prev_status = __raw_readl(davinci_ks->base + DAVINCI_KEYSCAN_PREVSTATE);
new_status = __raw_readl(davinci_ks->base + DAVINCI_KEYSCAN_CURRENTST);
changed = prev_status ^ new_status;
if (changed) {
for (i = 0 ; i < keymapsize; i++) {
if ((changed>>i) & 0x1) {
keycode = keymap[i];
release = (new_status >> i) & 0x1;
dev_dbg(dev->parent, "key %d %s\n", keycode,
release ? "released" : "pressed");
input_report_key(davinci_ks->input, keycode,
!release);
input_sync(davinci_ks->input);
}
}
__raw_writel(DAVINCI_KEYSCAN_INT_ALL,
davinci_ks->base + DAVINCI_KEYSCAN_INTCLR);
}
__raw_writel(0x1, davinci_ks->base + DAVINCI_KEYSCAN_INTENA);
return IRQ_HANDLED;
}
static int __init davinci_ks_probe(struct platform_device *pdev)
{
struct davinci_ks *davinci_ks;
struct input_dev *key_dev;
struct resource *res, *mem;
struct device *dev = &pdev->dev;
struct davinci_ks_platform_data *pdata = pdev->dev.platform_data;
int error, i;
if (pdata->device_enable) {
error = pdata->device_enable(dev);
if (error < 0) {
dev_dbg(dev, "device enable function failed\n");
return error;
}
}
if (!pdata->keymap) {
dev_dbg(dev, "no keymap from pdata\n");
return -EINVAL;
}
davinci_ks = kzalloc(sizeof(struct davinci_ks) +
sizeof(unsigned short) * pdata->keymapsize, GFP_KERNEL);
if (!davinci_ks) {
dev_dbg(dev, "could not allocate memory for private data\n");
return -ENOMEM;
}
memcpy(davinci_ks->keymap, pdata->keymap,
sizeof(unsigned short) * pdata->keymapsize);
key_dev = input_allocate_device();
if (!key_dev) {
dev_dbg(dev, "could not allocate input device\n");
error = -ENOMEM;
goto fail1;
}
davinci_ks->input = key_dev;
davinci_ks->irq = platform_get_irq(pdev, 0);
if (davinci_ks->irq < 0) {
dev_err(dev, "no key scan irq\n");
error = davinci_ks->irq;
goto fail2;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "no mem resource\n");
error = -EINVAL;
goto fail2;
}
davinci_ks->pbase = res->start;
davinci_ks->base_size = resource_size(res);
mem = request_mem_region(davinci_ks->pbase, davinci_ks->base_size,
pdev->name);
if (!mem) {
dev_err(dev, "key scan registers at %08x are not free\n",
davinci_ks->pbase);
error = -EBUSY;
goto fail2;
}
davinci_ks->base = ioremap(davinci_ks->pbase, davinci_ks->base_size);
if (!davinci_ks->base) {
dev_err(dev, "can't ioremap MEM resource.\n");
error = -ENOMEM;
goto fail3;
}
if (pdata->rep)
__set_bit(EV_REP, key_dev->evbit);
__set_bit(EV_KEY, key_dev->evbit);
davinci_ks->pdata = pdata;
for (i = 0; i < davinci_ks->pdata->keymapsize; i++)
__set_bit(davinci_ks->pdata->keymap[i], key_dev->keybit);
key_dev->name = "davinci_keyscan";
key_dev->phys = "davinci_keyscan/input0";
key_dev->dev.parent = &pdev->dev;
key_dev->id.bustype = BUS_HOST;
key_dev->id.vendor = 0x0001;
key_dev->id.product = 0x0001;
key_dev->id.version = 0x0001;
key_dev->keycode = davinci_ks->keymap;
key_dev->keycodesize = sizeof(davinci_ks->keymap[0]);
key_dev->keycodemax = davinci_ks->pdata->keymapsize;
error = input_register_device(davinci_ks->input);
if (error < 0) {
dev_err(dev, "unable to register davinci key scan device\n");
goto fail4;
}
error = request_irq(davinci_ks->irq, davinci_ks_interrupt,
0, pdev->name, davinci_ks);
if (error < 0) {
dev_err(dev, "unable to register davinci key scan interrupt\n");
goto fail5;
}
error = davinci_ks_initialize(davinci_ks);
if (error < 0) {
dev_err(dev, "unable to initialize davinci key scan device\n");
goto fail6;
}
platform_set_drvdata(pdev, davinci_ks);
return 0;
fail6:
free_irq(davinci_ks->irq, davinci_ks);
fail5:
input_unregister_device(davinci_ks->input);
key_dev = NULL;
fail4:
iounmap(davinci_ks->base);
fail3:
release_mem_region(davinci_ks->pbase, davinci_ks->base_size);
fail2:
input_free_device(key_dev);
fail1:
kfree(davinci_ks);
return error;
}
static int davinci_ks_remove(struct platform_device *pdev)
{
struct davinci_ks *davinci_ks = platform_get_drvdata(pdev);
free_irq(davinci_ks->irq, davinci_ks);
input_unregister_device(davinci_ks->input);
iounmap(davinci_ks->base);
release_mem_region(davinci_ks->pbase, davinci_ks->base_size);
kfree(davinci_ks);
return 0;
}
