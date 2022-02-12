static int u300_get_groups_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(u300_pin_groups);
}
static const char *u300_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
return u300_pin_groups[selector].name;
}
static int u300_get_group_pins(struct pinctrl_dev *pctldev, unsigned selector,
const unsigned **pins,
unsigned *num_pins)
{
*pins = u300_pin_groups[selector].pins;
*num_pins = u300_pin_groups[selector].num_pins;
return 0;
}
static void u300_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned offset)
{
seq_printf(s, " " DRIVER_NAME);
}
static void u300_pmx_endisable(struct u300_pmx *upmx, unsigned selector,
bool enable)
{
u16 regval, val, mask;
int i;
const struct u300_pmx_mask *upmx_mask;
upmx_mask = u300_pmx_functions[selector].mask;
for (i = 0; i < ARRAY_SIZE(u300_pmx_registers); i++) {
if (enable)
val = upmx_mask->bits;
else
val = 0;
mask = upmx_mask->mask;
if (mask != 0) {
regval = readw(upmx->virtbase + u300_pmx_registers[i]);
regval &= ~mask;
regval |= val;
writew(regval, upmx->virtbase + u300_pmx_registers[i]);
}
upmx_mask++;
}
}
static int u300_pmx_set_mux(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct u300_pmx *upmx;
if (selector == 0)
return 0;
upmx = pinctrl_dev_get_drvdata(pctldev);
u300_pmx_endisable(upmx, selector, true);
return 0;
}
static int u300_pmx_get_funcs_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(u300_pmx_functions);
}
static const char *u300_pmx_get_func_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
return u300_pmx_functions[selector].name;
}
static int u300_pmx_get_groups(struct pinctrl_dev *pctldev, unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
*groups = u300_pmx_functions[selector].groups;
*num_groups = u300_pmx_functions[selector].num_groups;
return 0;
}
static int u300_pin_config_get(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
struct pinctrl_gpio_range *range =
pinctrl_find_gpio_range_from_pin(pctldev, pin);
if (!range)
return -ENOTSUPP;
return u300_gpio_config_get(range->gc,
(pin - range->pin_base + range->base),
config);
}
static int u300_pin_config_set(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *configs, unsigned num_configs)
{
struct pinctrl_gpio_range *range =
pinctrl_find_gpio_range_from_pin(pctldev, pin);
int ret, i;
if (!range)
return -EINVAL;
for (i = 0; i < num_configs; i++) {
ret = u300_gpio_config_set(range->gc,
(pin - range->pin_base + range->base),
pinconf_to_config_param(configs[i]));
if (ret)
return ret;
}
return 0;
}
static int u300_pmx_probe(struct platform_device *pdev)
{
struct u300_pmx *upmx;
struct resource *res;
upmx = devm_kzalloc(&pdev->dev, sizeof(*upmx), GFP_KERNEL);
if (!upmx)
return -ENOMEM;
upmx->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
upmx->virtbase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(upmx->virtbase))
return PTR_ERR(upmx->virtbase);
upmx->pctl = devm_pinctrl_register(&pdev->dev, &u300_pmx_desc, upmx);
if (IS_ERR(upmx->pctl)) {
dev_err(&pdev->dev, "could not register U300 pinmux driver\n");
return PTR_ERR(upmx->pctl);
}
platform_set_drvdata(pdev, upmx);
dev_info(&pdev->dev, "initialized U300 pin control driver\n");
return 0;
}
static int __init u300_pmx_init(void)
{
return platform_driver_register(&u300_pmx_driver);
}
static void __exit u300_pmx_exit(void)
{
platform_driver_unregister(&u300_pmx_driver);
}
