static int cygnus_get_groups_count(struct pinctrl_dev *pctrl_dev)
{
struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->num_groups;
}
static const char *cygnus_get_group_name(struct pinctrl_dev *pctrl_dev,
unsigned selector)
{
struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->groups[selector].name;
}
static int cygnus_get_group_pins(struct pinctrl_dev *pctrl_dev,
unsigned selector, const unsigned **pins,
unsigned *num_pins)
{
struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
*pins = pinctrl->groups[selector].pins;
*num_pins = pinctrl->groups[selector].num_pins;
return 0;
}
static void cygnus_pin_dbg_show(struct pinctrl_dev *pctrl_dev,
struct seq_file *s, unsigned offset)
{
seq_printf(s, " %s", dev_name(pctrl_dev->dev));
}
static int cygnus_get_functions_count(struct pinctrl_dev *pctrl_dev)
{
struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->num_functions;
}
static const char *cygnus_get_function_name(struct pinctrl_dev *pctrl_dev,
unsigned selector)
{
struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->functions[selector].name;
}
static int cygnus_get_function_groups(struct pinctrl_dev *pctrl_dev,
unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
*groups = pinctrl->functions[selector].groups;
*num_groups = pinctrl->functions[selector].num_groups;
return 0;
}
static int cygnus_pinmux_set(struct cygnus_pinctrl *pinctrl,
const struct cygnus_pin_function *func,
const struct cygnus_pin_group *grp,
struct cygnus_mux_log *mux_log)
{
const struct cygnus_mux *mux = &grp->mux;
int i;
u32 val, mask = 0x7;
unsigned long flags;
for (i = 0; i < CYGNUS_NUM_IOMUX; i++) {
if (mux->offset != mux_log[i].mux.offset ||
mux->shift != mux_log[i].mux.shift)
continue;
if (!mux_log[i].is_configured)
break;
if (mux_log[i].mux.alt != mux->alt) {
dev_err(pinctrl->dev,
"double configuration error detected!\n");
dev_err(pinctrl->dev, "func:%s grp:%s\n",
func->name, grp->name);
return -EINVAL;
} else {
return 0;
}
}
mux_log[i].mux.alt = mux->alt;
mux_log[i].is_configured = true;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(pinctrl->base0 + grp->mux.offset);
val &= ~(mask << grp->mux.shift);
val |= grp->mux.alt << grp->mux.shift;
writel(val, pinctrl->base0 + grp->mux.offset);
spin_unlock_irqrestore(&pinctrl->lock, flags);
return 0;
}
static int cygnus_pinmux_set_mux(struct pinctrl_dev *pctrl_dev,
unsigned func_select, unsigned grp_select)
{
struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
const struct cygnus_pin_function *func =
&pinctrl->functions[func_select];
const struct cygnus_pin_group *grp = &pinctrl->groups[grp_select];
dev_dbg(pctrl_dev->dev, "func:%u name:%s grp:%u name:%s\n",
func_select, func->name, grp_select, grp->name);
dev_dbg(pctrl_dev->dev, "offset:0x%08x shift:%u alt:%u\n",
grp->mux.offset, grp->mux.shift, grp->mux.alt);
return cygnus_pinmux_set(pinctrl, func, grp, pinctrl->mux_log);
}
static int cygnus_gpio_request_enable(struct pinctrl_dev *pctrl_dev,
struct pinctrl_gpio_range *range,
unsigned pin)
{
struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
const struct cygnus_gpio_mux *mux = pctrl_dev->desc->pins[pin].drv_data;
u32 val;
unsigned long flags;
if (!mux->is_supported)
return -ENOTSUPP;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(pinctrl->base1 + mux->offset);
val |= 0x3 << mux->shift;
writel(val, pinctrl->base1 + mux->offset);
spin_unlock_irqrestore(&pinctrl->lock, flags);
dev_dbg(pctrl_dev->dev,
"gpio request enable pin=%u offset=0x%x shift=%u\n",
pin, mux->offset, mux->shift);
return 0;
}
static void cygnus_gpio_disable_free(struct pinctrl_dev *pctrl_dev,
struct pinctrl_gpio_range *range,
unsigned pin)
{
struct cygnus_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
struct cygnus_gpio_mux *mux = pctrl_dev->desc->pins[pin].drv_data;
u32 val;
unsigned long flags;
if (!mux->is_supported)
return;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(pinctrl->base1 + mux->offset);
val &= ~(0x3 << mux->shift);
writel(val, pinctrl->base1 + mux->offset);
spin_unlock_irqrestore(&pinctrl->lock, flags);
dev_err(pctrl_dev->dev,
"gpio disable free pin=%u offset=0x%x shift=%u\n",
pin, mux->offset, mux->shift);
}
static int cygnus_mux_log_init(struct cygnus_pinctrl *pinctrl)
{
struct cygnus_mux_log *log;
unsigned int i, j;
pinctrl->mux_log = devm_kcalloc(pinctrl->dev, CYGNUS_NUM_IOMUX,
sizeof(struct cygnus_mux_log),
GFP_KERNEL);
if (!pinctrl->mux_log)
return -ENOMEM;
log = pinctrl->mux_log;
for (i = 0; i < CYGNUS_NUM_IOMUX_REGS; i++) {
for (j = 0; j < CYGNUS_NUM_MUX_PER_REG; j++) {
log = &pinctrl->mux_log[i * CYGNUS_NUM_MUX_PER_REG
+ j];
log->mux.offset = i * 4;
log->mux.shift = j * 4;
log->mux.alt = 0;
log->is_configured = false;
}
}
return 0;
}
static int cygnus_pinmux_probe(struct platform_device *pdev)
{
struct cygnus_pinctrl *pinctrl;
struct resource *res;
int i, ret;
struct pinctrl_pin_desc *pins;
unsigned num_pins = ARRAY_SIZE(cygnus_pins);
pinctrl = devm_kzalloc(&pdev->dev, sizeof(*pinctrl), GFP_KERNEL);
if (!pinctrl)
return -ENOMEM;
pinctrl->dev = &pdev->dev;
platform_set_drvdata(pdev, pinctrl);
spin_lock_init(&pinctrl->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pinctrl->base0 = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pinctrl->base0)) {
dev_err(&pdev->dev, "unable to map I/O space\n");
return PTR_ERR(pinctrl->base0);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
pinctrl->base1 = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pinctrl->base1)) {
dev_err(&pdev->dev, "unable to map I/O space\n");
return PTR_ERR(pinctrl->base1);
}
ret = cygnus_mux_log_init(pinctrl);
if (ret) {
dev_err(&pdev->dev, "unable to initialize IOMUX log\n");
return ret;
}
pins = devm_kcalloc(&pdev->dev, num_pins, sizeof(*pins), GFP_KERNEL);
if (!pins)
return -ENOMEM;
for (i = 0; i < num_pins; i++) {
pins[i].number = cygnus_pins[i].pin;
pins[i].name = cygnus_pins[i].name;
pins[i].drv_data = &cygnus_pins[i].gpio_mux;
}
pinctrl->groups = cygnus_pin_groups;
pinctrl->num_groups = ARRAY_SIZE(cygnus_pin_groups);
pinctrl->functions = cygnus_pin_functions;
pinctrl->num_functions = ARRAY_SIZE(cygnus_pin_functions);
cygnus_pinctrl_desc.pins = pins;
cygnus_pinctrl_desc.npins = num_pins;
pinctrl->pctl = devm_pinctrl_register(&pdev->dev, &cygnus_pinctrl_desc,
pinctrl);
if (IS_ERR(pinctrl->pctl)) {
dev_err(&pdev->dev, "unable to register Cygnus IOMUX pinctrl\n");
return PTR_ERR(pinctrl->pctl);
}
return 0;
}
static int __init cygnus_pinmux_init(void)
{
return platform_driver_register(&cygnus_pinmux_driver);
}
