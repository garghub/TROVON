static int da850_pupd_get_groups_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(da850_pupd_group_names);
}
static const char *da850_pupd_get_group_name(struct pinctrl_dev *pctldev,
unsigned int selector)
{
return da850_pupd_group_names[selector];
}
static int da850_pupd_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int selector,
const unsigned int **pins,
unsigned int *num_pins)
{
*num_pins = 0;
return 0;
}
static int da850_pupd_pin_config_group_get(struct pinctrl_dev *pctldev,
unsigned int selector,
unsigned long *config)
{
struct da850_pupd_data *data = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
u32 val;
u16 arg;
val = readl(data->base + DA850_PUPD_ENA);
arg = !!(~val & BIT(selector));
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
break;
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
if (arg) {
arg = 0;
break;
}
val = readl(data->base + DA850_PUPD_SEL);
if (param == PIN_CONFIG_BIAS_PULL_DOWN)
val = ~val;
arg = !!(val & BIT(selector));
break;
default:
return -EINVAL;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int da850_pupd_pin_config_group_set(struct pinctrl_dev *pctldev,
unsigned int selector,
unsigned long *configs,
unsigned int num_configs)
{
struct da850_pupd_data *data = pinctrl_dev_get_drvdata(pctldev);
u32 ena, sel;
enum pin_config_param param;
u16 arg;
int i;
ena = readl(data->base + DA850_PUPD_ENA);
sel = readl(data->base + DA850_PUPD_SEL);
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
ena &= ~BIT(selector);
break;
case PIN_CONFIG_BIAS_PULL_UP:
ena |= BIT(selector);
sel |= BIT(selector);
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
ena |= BIT(selector);
sel &= ~BIT(selector);
break;
default:
return -EINVAL;
}
}
writel(sel, data->base + DA850_PUPD_SEL);
writel(ena, data->base + DA850_PUPD_ENA);
return 0;
}
static int da850_pupd_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct da850_pupd_data *data;
struct resource *res;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_ioremap_resource(dev, res);
if (IS_ERR(data->base)) {
dev_err(dev, "Could not map resource\n");
return PTR_ERR(data->base);
}
data->desc.name = dev_name(dev);
data->desc.pctlops = &da850_pupd_pctlops;
data->desc.confops = &da850_pupd_confops;
data->desc.owner = THIS_MODULE;
data->pinctrl = devm_pinctrl_register(dev, &data->desc, data);
if (IS_ERR(data->pinctrl)) {
dev_err(dev, "Failed to register pinctrl\n");
return PTR_ERR(data->pinctrl);
}
platform_set_drvdata(pdev, data);
return 0;
}
static int da850_pupd_remove(struct platform_device *pdev)
{
return 0;
}
