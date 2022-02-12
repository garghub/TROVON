static int ns2_get_groups_count(struct pinctrl_dev *pctrl_dev)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->num_groups;
}
static const char *ns2_get_group_name(struct pinctrl_dev *pctrl_dev,
unsigned int selector)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->groups[selector].name;
}
static int ns2_get_group_pins(struct pinctrl_dev *pctrl_dev,
unsigned int selector, const unsigned int **pins,
unsigned int *num_pins)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
*pins = pinctrl->groups[selector].pins;
*num_pins = pinctrl->groups[selector].num_pins;
return 0;
}
static void ns2_pin_dbg_show(struct pinctrl_dev *pctrl_dev,
struct seq_file *s, unsigned int offset)
{
seq_printf(s, " %s", dev_name(pctrl_dev->dev));
}
static int ns2_get_functions_count(struct pinctrl_dev *pctrl_dev)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->num_functions;
}
static const char *ns2_get_function_name(struct pinctrl_dev *pctrl_dev,
unsigned int selector)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
return pinctrl->functions[selector].name;
}
static int ns2_get_function_groups(struct pinctrl_dev *pctrl_dev,
unsigned int selector,
const char * const **groups,
unsigned int * const num_groups)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
*groups = pinctrl->functions[selector].groups;
*num_groups = pinctrl->functions[selector].num_groups;
return 0;
}
static int ns2_pinmux_set(struct ns2_pinctrl *pinctrl,
const struct ns2_pin_function *func,
const struct ns2_pin_group *grp,
struct ns2_mux_log *mux_log)
{
const struct ns2_mux *mux = &grp->mux;
int i;
u32 val, mask;
unsigned long flags;
void __iomem *base_address;
for (i = 0; i < NS2_NUM_IOMUX; i++) {
if ((mux->shift != mux_log[i].mux.shift) ||
(mux->base != mux_log[i].mux.base) ||
(mux->offset != mux_log[i].mux.offset))
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
if (i == NS2_NUM_IOMUX)
return -EINVAL;
mask = mux->mask;
mux_log[i].mux.alt = mux->alt;
mux_log[i].is_configured = true;
switch (mux->base) {
case NS2_PIN_MUX_BASE0:
base_address = pinctrl->base0;
break;
case NS2_PIN_MUX_BASE1:
base_address = pinctrl->base1;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(base_address + grp->mux.offset);
val &= ~(mask << grp->mux.shift);
val |= grp->mux.alt << grp->mux.shift;
writel(val, (base_address + grp->mux.offset));
spin_unlock_irqrestore(&pinctrl->lock, flags);
return 0;
}
static int ns2_pinmux_enable(struct pinctrl_dev *pctrl_dev,
unsigned int func_select, unsigned int grp_select)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrl_dev);
const struct ns2_pin_function *func;
const struct ns2_pin_group *grp;
if (grp_select > pinctrl->num_groups ||
func_select > pinctrl->num_functions)
return -EINVAL;
func = &pinctrl->functions[func_select];
grp = &pinctrl->groups[grp_select];
dev_dbg(pctrl_dev->dev, "func:%u name:%s grp:%u name:%s\n",
func_select, func->name, grp_select, grp->name);
dev_dbg(pctrl_dev->dev, "offset:0x%08x shift:%u alt:%u\n",
grp->mux.offset, grp->mux.shift, grp->mux.alt);
return ns2_pinmux_set(pinctrl, func, grp, pinctrl->mux_log);
}
static int ns2_pin_set_enable(struct pinctrl_dev *pctrldev, unsigned int pin,
u16 enable)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrldev);
struct ns2_pin *pin_data = pctrldev->desc->pins[pin].drv_data;
unsigned long flags;
u32 val;
void __iomem *base_address;
base_address = pinctrl->pinconf_base;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(base_address + pin_data->pin_conf.offset);
val &= ~(NS2_PIN_SRC_MASK << pin_data->pin_conf.input_en);
if (!enable)
val |= NS2_PIN_INPUT_EN_MASK << pin_data->pin_conf.input_en;
writel(val, (base_address + pin_data->pin_conf.offset));
spin_unlock_irqrestore(&pinctrl->lock, flags);
dev_dbg(pctrldev->dev, "pin:%u set enable:%d\n", pin, enable);
return 0;
}
static int ns2_pin_get_enable(struct pinctrl_dev *pctrldev, unsigned int pin)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrldev);
struct ns2_pin *pin_data = pctrldev->desc->pins[pin].drv_data;
unsigned long flags;
int enable;
spin_lock_irqsave(&pinctrl->lock, flags);
enable = readl(pinctrl->pinconf_base + pin_data->pin_conf.offset);
enable = (enable >> pin_data->pin_conf.input_en) &
NS2_PIN_INPUT_EN_MASK;
spin_unlock_irqrestore(&pinctrl->lock, flags);
if (!enable)
enable = NS2_PIN_INPUT_EN_MASK;
else
enable = 0;
dev_dbg(pctrldev->dev, "pin:%u get disable:%d\n", pin, enable);
return enable;
}
static int ns2_pin_set_slew(struct pinctrl_dev *pctrldev, unsigned int pin,
u32 slew)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrldev);
struct ns2_pin *pin_data = pctrldev->desc->pins[pin].drv_data;
unsigned long flags;
u32 val;
void __iomem *base_address;
base_address = pinctrl->pinconf_base;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(base_address + pin_data->pin_conf.offset);
val &= ~(NS2_PIN_SRC_MASK << pin_data->pin_conf.src_shift);
if (slew)
val |= NS2_PIN_SRC_MASK << pin_data->pin_conf.src_shift;
writel(val, (base_address + pin_data->pin_conf.offset));
spin_unlock_irqrestore(&pinctrl->lock, flags);
dev_dbg(pctrldev->dev, "pin:%u set slew:%d\n", pin, slew);
return 0;
}
static int ns2_pin_get_slew(struct pinctrl_dev *pctrldev, unsigned int pin,
u16 *slew)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrldev);
struct ns2_pin *pin_data = pctrldev->desc->pins[pin].drv_data;
unsigned long flags;
u32 val;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(pinctrl->pinconf_base + pin_data->pin_conf.offset);
*slew = (val >> pin_data->pin_conf.src_shift) & NS2_PIN_SRC_MASK;
spin_unlock_irqrestore(&pinctrl->lock, flags);
dev_dbg(pctrldev->dev, "pin:%u get slew:%d\n", pin, *slew);
return 0;
}
static int ns2_pin_set_pull(struct pinctrl_dev *pctrldev, unsigned int pin,
bool pull_up, bool pull_down)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrldev);
struct ns2_pin *pin_data = pctrldev->desc->pins[pin].drv_data;
unsigned long flags;
u32 val;
void __iomem *base_address;
base_address = pinctrl->pinconf_base;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(base_address + pin_data->pin_conf.offset);
val &= ~(NS2_PIN_PULL_MASK << pin_data->pin_conf.pull_shift);
if (pull_up == true)
val |= NS2_PIN_PULL_UP << pin_data->pin_conf.pull_shift;
if (pull_down == true)
val |= NS2_PIN_PULL_DOWN << pin_data->pin_conf.pull_shift;
writel(val, (base_address + pin_data->pin_conf.offset));
spin_unlock_irqrestore(&pinctrl->lock, flags);
dev_dbg(pctrldev->dev, "pin:%u set pullup:%d pulldown: %d\n",
pin, pull_up, pull_down);
return 0;
}
static void ns2_pin_get_pull(struct pinctrl_dev *pctrldev,
unsigned int pin, bool *pull_up,
bool *pull_down)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrldev);
struct ns2_pin *pin_data = pctrldev->desc->pins[pin].drv_data;
unsigned long flags;
u32 val;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(pinctrl->pinconf_base + pin_data->pin_conf.offset);
val = (val >> pin_data->pin_conf.pull_shift) & NS2_PIN_PULL_MASK;
*pull_up = false;
*pull_down = false;
if (val == NS2_PIN_PULL_UP)
*pull_up = true;
if (val == NS2_PIN_PULL_DOWN)
*pull_down = true;
spin_unlock_irqrestore(&pinctrl->lock, flags);
}
static int ns2_pin_set_strength(struct pinctrl_dev *pctrldev, unsigned int pin,
u32 strength)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrldev);
struct ns2_pin *pin_data = pctrldev->desc->pins[pin].drv_data;
u32 val;
unsigned long flags;
void __iomem *base_address;
if (strength < 2 || strength > 16 || (strength % 2))
return -ENOTSUPP;
base_address = pinctrl->pinconf_base;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(base_address + pin_data->pin_conf.offset);
val &= ~(NS2_PIN_DRIVE_STRENGTH_MASK << pin_data->pin_conf.drive_shift);
val |= ((strength / 2) - 1) << pin_data->pin_conf.drive_shift;
writel(val, (base_address + pin_data->pin_conf.offset));
spin_unlock_irqrestore(&pinctrl->lock, flags);
dev_dbg(pctrldev->dev, "pin:%u set drive strength:%d mA\n",
pin, strength);
return 0;
}
static int ns2_pin_get_strength(struct pinctrl_dev *pctrldev, unsigned int pin,
u16 *strength)
{
struct ns2_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctrldev);
struct ns2_pin *pin_data = pctrldev->desc->pins[pin].drv_data;
u32 val;
unsigned long flags;
spin_lock_irqsave(&pinctrl->lock, flags);
val = readl(pinctrl->pinconf_base + pin_data->pin_conf.offset);
*strength = (val >> pin_data->pin_conf.drive_shift) &
NS2_PIN_DRIVE_STRENGTH_MASK;
*strength = (*strength + 1) * 2;
spin_unlock_irqrestore(&pinctrl->lock, flags);
dev_dbg(pctrldev->dev, "pin:%u get drive strength:%d mA\n",
pin, *strength);
return 0;
}
static int ns2_pin_config_get(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *config)
{
struct ns2_pin *pin_data = pctldev->desc->pins[pin].drv_data;
enum pin_config_param param = pinconf_to_config_param(*config);
bool pull_up, pull_down;
u16 arg = 0;
int ret;
if (pin_data->pin_conf.base == -1)
return -ENOTSUPP;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
ns2_pin_get_pull(pctldev, pin, &pull_up, &pull_down);
if ((pull_up == false) && (pull_down == false))
return 0;
else
return -EINVAL;
case PIN_CONFIG_BIAS_PULL_UP:
ns2_pin_get_pull(pctldev, pin, &pull_up, &pull_down);
if (pull_up)
return 0;
else
return -EINVAL;
case PIN_CONFIG_BIAS_PULL_DOWN:
ns2_pin_get_pull(pctldev, pin, &pull_up, &pull_down);
if (pull_down)
return 0;
else
return -EINVAL;
case PIN_CONFIG_DRIVE_STRENGTH:
ret = ns2_pin_get_strength(pctldev, pin, &arg);
if (ret)
return ret;
*config = pinconf_to_config_packed(param, arg);
return 0;
case PIN_CONFIG_SLEW_RATE:
ret = ns2_pin_get_slew(pctldev, pin, &arg);
if (ret)
return ret;
*config = pinconf_to_config_packed(param, arg);
return 0;
case PIN_CONFIG_INPUT_ENABLE:
ret = ns2_pin_get_enable(pctldev, pin);
if (ret)
return 0;
else
return -EINVAL;
default:
return -ENOTSUPP;
}
}
static int ns2_pin_config_set(struct pinctrl_dev *pctrldev, unsigned int pin,
unsigned long *configs, unsigned int num_configs)
{
struct ns2_pin *pin_data = pctrldev->desc->pins[pin].drv_data;
enum pin_config_param param;
unsigned int i;
u32 arg;
int ret = -ENOTSUPP;
if (pin_data->pin_conf.base == -1)
return -ENOTSUPP;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
ret = ns2_pin_set_pull(pctrldev, pin, false, false);
if (ret < 0)
goto out;
break;
case PIN_CONFIG_BIAS_PULL_UP:
ret = ns2_pin_set_pull(pctrldev, pin, true, false);
if (ret < 0)
goto out;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
ret = ns2_pin_set_pull(pctrldev, pin, false, true);
if (ret < 0)
goto out;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
ret = ns2_pin_set_strength(pctrldev, pin, arg);
if (ret < 0)
goto out;
break;
case PIN_CONFIG_SLEW_RATE:
ret = ns2_pin_set_slew(pctrldev, pin, arg);
if (ret < 0)
goto out;
break;
case PIN_CONFIG_INPUT_ENABLE:
ret = ns2_pin_set_enable(pctrldev, pin, arg);
if (ret < 0)
goto out;
break;
default:
dev_err(pctrldev->dev, "invalid configuration\n");
return -ENOTSUPP;
}
}
out:
return ret;
}
static int ns2_mux_log_init(struct ns2_pinctrl *pinctrl)
{
struct ns2_mux_log *log;
unsigned int i;
pinctrl->mux_log = devm_kcalloc(pinctrl->dev, NS2_NUM_IOMUX,
sizeof(struct ns2_mux_log),
GFP_KERNEL);
if (!pinctrl->mux_log)
return -ENOMEM;
for (i = 0; i < NS2_NUM_IOMUX; i++)
pinctrl->mux_log[i].is_configured = false;
log = &pinctrl->mux_log[0];
log->mux.base = NS2_PIN_MUX_BASE0;
log->mux.offset = 0;
log->mux.shift = 31;
log->mux.alt = 0;
for (i = 1; i < (NS2_NUM_IOMUX - NS2_NUM_PWM_MUX); i++) {
log = &pinctrl->mux_log[i];
log->mux.base = NS2_PIN_MUX_BASE0;
log->mux.offset = NS2_MUX_PAD_FUNC1_OFFSET;
log->mux.shift = 32 - (i * 2);
log->mux.alt = 0;
}
for (i = 0; i < NS2_NUM_PWM_MUX; i++) {
log = &pinctrl->mux_log[(NS2_NUM_IOMUX - NS2_NUM_PWM_MUX) + i];
log->mux.base = NS2_PIN_MUX_BASE1;
log->mux.offset = 0;
log->mux.shift = i;
log->mux.alt = 0;
}
return 0;
}
static int ns2_pinmux_probe(struct platform_device *pdev)
{
struct ns2_pinctrl *pinctrl;
struct resource *res;
int i, ret;
struct pinctrl_pin_desc *pins;
unsigned int num_pins = ARRAY_SIZE(ns2_pins);
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
pinctrl->pinconf_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pinctrl->pinconf_base))
return PTR_ERR(pinctrl->pinconf_base);
ret = ns2_mux_log_init(pinctrl);
if (ret) {
dev_err(&pdev->dev, "unable to initialize IOMUX log\n");
return ret;
}
pins = devm_kcalloc(&pdev->dev, num_pins, sizeof(*pins), GFP_KERNEL);
if (!pins)
return -ENOMEM;
for (i = 0; i < num_pins; i++) {
pins[i].number = ns2_pins[i].pin;
pins[i].name = ns2_pins[i].name;
pins[i].drv_data = &ns2_pins[i];
}
pinctrl->groups = ns2_pin_groups;
pinctrl->num_groups = ARRAY_SIZE(ns2_pin_groups);
pinctrl->functions = ns2_pin_functions;
pinctrl->num_functions = ARRAY_SIZE(ns2_pin_functions);
ns2_pinctrl_desc.pins = pins;
ns2_pinctrl_desc.npins = num_pins;
pinctrl->pctl = pinctrl_register(&ns2_pinctrl_desc, &pdev->dev,
pinctrl);
if (IS_ERR(pinctrl->pctl)) {
dev_err(&pdev->dev, "unable to register IOMUX pinctrl\n");
return PTR_ERR(pinctrl->pctl);
}
return 0;
}
static int __init ns2_pinmux_init(void)
{
return platform_driver_register(&ns2_pinmux_driver);
}
