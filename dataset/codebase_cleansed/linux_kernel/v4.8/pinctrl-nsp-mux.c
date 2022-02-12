static int nsp_get_groups_count(struct pinctrl_dev *pctrl_dev)
{
struct nsp_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->num_groups;
}
static const char *nsp_get_group_name(struct pinctrl_dev *pctrl_dev,
unsigned int selector)
{
struct nsp_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->groups[selector].name;
}
static int nsp_get_group_pins(struct pinctrl_dev *pctrl_dev,
unsigned int selector, const unsigned int **pins,
unsigned int *num_pins)
{
struct nsp_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
*pins = pinctrl->groups[selector].pins;
*num_pins = pinctrl->groups[selector].num_pins;
return 0;
}
static void nsp_pin_dbg_show(struct pinctrl_dev *pctrl_dev,
struct seq_file *s, unsigned int offset)
{
seq_printf(s, " %s", dev_name(pctrl_dev->dev));
}
static int nsp_get_functions_count(struct pinctrl_dev *pctrl_dev)
{
struct nsp_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->num_functions;
}
static const char *nsp_get_function_name(struct pinctrl_dev *pctrl_dev,
unsigned int selector)
{
struct nsp_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->functions[selector].name;
}
static int nsp_get_function_groups(struct pinctrl_dev *pctrl_dev,
unsigned int selector,
const char * const **groups,
unsigned * const num_groups)
{
struct nsp_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
*groups = pinctrl->functions[selector].groups;
*num_groups = pinctrl->functions[selector].num_groups;
return 0;
}
static int nsp_pinmux_set(struct nsp_pinctrl *pinctrl,
const struct nsp_pin_function *func,
const struct nsp_pin_group *grp,
struct nsp_mux_log *mux_log)
{
const struct nsp_mux *mux = &grp->mux;
int i;
u32 val, mask;
unsigned long flags;
void __iomem *base_address;
for (i = 0; i < pinctrl->num_groups; i++) {
if ((mux->shift != mux_log[i].mux.shift) ||
(mux->base != mux_log[i].mux.base))
continue;
if (!mux_log[i].is_configured)
break;
if (mux_log[i].mux.alt != mux->alt) {
dev_err(pinctrl->dev,
"double configuration error detected!\n");
dev_err(pinctrl->dev, "func:%s grp:%s\n",
func->name, grp->name);
return -EINVAL;
}
return 0;
}
if (i == pinctrl->num_groups)
return -EINVAL;
mask = mux->mask;
mux_log[i].mux.alt = mux->alt;
mux_log[i].is_configured = true;
switch (mux->base) {
case NSP_MUX_BASE0:
base_address = pinctrl->base0;
break;
case NSP_MUX_BASE1:
base_address = pinctrl->base1;
break;
case NSP_MUX_BASE2:
base_address = pinctrl->base2;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(base_address);
val &= ~(mask << grp->mux.shift);
val |= grp->mux.alt << grp->mux.shift;
writel(val, base_address);
spin_unlock_irqrestore(&pinctrl->lock, flags);
return 0;
}
static int nsp_pinmux_enable(struct pinctrl_dev *pctrl_dev,
unsigned int func_select, unsigned int grp_select)
{
struct nsp_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
const struct nsp_pin_function *func;
const struct nsp_pin_group *grp;
if (grp_select > pinctrl->num_groups ||
func_select > pinctrl->num_functions)
return -EINVAL;
func = &pinctrl->functions[func_select];
grp = &pinctrl->groups[grp_select];
dev_dbg(pctrl_dev->dev, "func:%u name:%s grp:%u name:%s\n",
func_select, func->name, grp_select, grp->name);
dev_dbg(pctrl_dev->dev, "shift:%u alt:%u\n", grp->mux.shift,
grp->mux.alt);
return nsp_pinmux_set(pinctrl, func, grp, pinctrl->mux_log);
}
static int nsp_gpio_request_enable(struct pinctrl_dev *pctrl_dev,
struct pinctrl_gpio_range *range,
unsigned int pin)
{
struct nsp_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
u32 *gpio_select = pctrl_dev->desc->pins[pin].drv_data;
u32 val;
unsigned long flags;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(pinctrl->base0);
if ((val & BIT(pin)) != (*gpio_select << pin)) {
val &= ~BIT(pin);
val |= *gpio_select << pin;
writel(val, pinctrl->base0);
}
spin_unlock_irqrestore(&pinctrl->lock, flags);
return 0;
}
static void nsp_gpio_disable_free(struct pinctrl_dev *pctrl_dev,
struct pinctrl_gpio_range *range,
unsigned int pin)
{
struct nsp_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
u32 *gpio_select = pctrl_dev->desc->pins[pin].drv_data;
u32 val;
unsigned long flags;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(pinctrl->base0);
if ((val & (1 << pin)) == (*gpio_select << pin)) {
val &= ~(1 << pin);
if (!(*gpio_select))
val |= (1 << pin);
writel(val, pinctrl->base0);
}
spin_unlock_irqrestore(&pinctrl->lock, flags);
}
static int nsp_mux_log_init(struct nsp_pinctrl *pinctrl)
{
struct nsp_mux_log *log;
unsigned int i;
u32 no_of_groups = ARRAY_SIZE(nsp_pin_groups);
pinctrl->mux_log = devm_kcalloc(pinctrl->dev, no_of_groups,
sizeof(struct nsp_mux_log),
GFP_KERNEL);
if (!pinctrl->mux_log)
return -ENOMEM;
for (i = 0; i < no_of_groups; i++) {
log = &pinctrl->mux_log[i];
log->mux.base = nsp_pin_groups[i].mux.base;
log->mux.shift = nsp_pin_groups[i].mux.shift;
log->mux.alt = 0;
log->is_configured = false;
}
return 0;
}
static int nsp_pinmux_probe(struct platform_device *pdev)
{
struct nsp_pinctrl *pinctrl;
struct resource *res;
int i, ret;
struct pinctrl_pin_desc *pins;
unsigned int num_pins = ARRAY_SIZE(nsp_pins);
pinctrl = devm_kzalloc(&pdev->dev, sizeof(*pinctrl), GFP_KERNEL);
if (!pinctrl)
return -ENOMEM;
pinctrl->dev = &pdev->dev;
platform_set_drvdata(pdev, pinctrl);
spin_lock_init(&pinctrl->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pinctrl->base0 = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pinctrl->base0))
return PTR_ERR(pinctrl->base0);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
pinctrl->base1 = devm_ioremap_nocache(&pdev->dev, res->start,
resource_size(res));
if (!pinctrl->base1) {
dev_err(&pdev->dev, "unable to map I/O space\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
pinctrl->base2 = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pinctrl->base2))
return PTR_ERR(pinctrl->base2);
ret = nsp_mux_log_init(pinctrl);
if (ret) {
dev_err(&pdev->dev, "unable to initialize IOMUX log\n");
return ret;
}
pins = devm_kcalloc(&pdev->dev, num_pins, sizeof(*pins), GFP_KERNEL);
if (!pins)
return -ENOMEM;
for (i = 0; i < num_pins; i++) {
pins[i].number = nsp_pins[i].pin;
pins[i].name = nsp_pins[i].name;
pins[i].drv_data = &nsp_pins[i].gpio_select;
}
pinctrl->groups = nsp_pin_groups;
pinctrl->num_groups = ARRAY_SIZE(nsp_pin_groups);
pinctrl->functions = nsp_pin_functions;
pinctrl->num_functions = ARRAY_SIZE(nsp_pin_functions);
nsp_pinctrl_desc.pins = pins;
nsp_pinctrl_desc.npins = num_pins;
pinctrl->pctl = devm_pinctrl_register(&pdev->dev, &nsp_pinctrl_desc,
pinctrl);
if (IS_ERR(pinctrl->pctl)) {
dev_err(&pdev->dev, "unable to register nsp IOMUX pinctrl\n");
return PTR_ERR(pinctrl->pctl);
}
return 0;
}
static int __init nsp_pinmux_init(void)
{
return platform_driver_register(&nsp_pinmux_driver);
}
