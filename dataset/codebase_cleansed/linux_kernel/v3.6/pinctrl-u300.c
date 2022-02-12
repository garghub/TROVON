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
static int u300_pmx_enable(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct u300_pmx *upmx;
if (selector == 0)
return 0;
upmx = pinctrl_dev_get_drvdata(pctldev);
u300_pmx_endisable(upmx, selector, true);
return 0;
}
static void u300_pmx_disable(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct u300_pmx *upmx;
if (selector == 0)
return;
upmx = pinctrl_dev_get_drvdata(pctldev);
u300_pmx_endisable(upmx, selector, false);
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
static struct pinctrl_gpio_range *u300_match_gpio_range(unsigned pin)
{
int i;
for (i = 0; i < ARRAY_SIZE(u300_gpio_ranges); i++) {
struct pinctrl_gpio_range *range;
range = &u300_gpio_ranges[i];
if (pin >= range->pin_base &&
pin <= (range->pin_base + range->npins - 1))
return range;
}
return NULL;
}
int u300_pin_config_get(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *config)
{
struct pinctrl_gpio_range *range = u300_match_gpio_range(pin);
if (!range)
return -ENOTSUPP;
return u300_gpio_config_get(range->gc,
(pin - range->pin_base + range->base),
config);
}
int u300_pin_config_set(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long config)
{
struct pinctrl_gpio_range *range = u300_match_gpio_range(pin);
int ret;
if (!range)
return -EINVAL;
ret = u300_gpio_config_set(range->gc,
(pin - range->pin_base + range->base),
pinconf_to_config_param(config));
if (ret)
return ret;
return 0;
}
static int __devinit u300_pmx_probe(struct platform_device *pdev)
{
struct u300_pmx *upmx;
struct resource *res;
struct gpio_chip *gpio_chip = dev_get_platdata(&pdev->dev);
int ret;
int i;
upmx = devm_kzalloc(&pdev->dev, sizeof(*upmx), GFP_KERNEL);
if (!upmx)
return -ENOMEM;
upmx->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOENT;
upmx->phybase = res->start;
upmx->physize = resource_size(res);
if (request_mem_region(upmx->phybase, upmx->physize,
DRIVER_NAME) == NULL) {
ret = -ENOMEM;
goto out_no_memregion;
}
upmx->virtbase = ioremap(upmx->phybase, upmx->physize);
if (!upmx->virtbase) {
ret = -ENOMEM;
goto out_no_remap;
}
upmx->pctl = pinctrl_register(&u300_pmx_desc, &pdev->dev, upmx);
if (!upmx->pctl) {
dev_err(&pdev->dev, "could not register U300 pinmux driver\n");
ret = -EINVAL;
goto out_no_pmx;
}
for (i = 0; i < ARRAY_SIZE(u300_gpio_ranges); i++) {
u300_gpio_ranges[i].gc = gpio_chip;
pinctrl_add_gpio_range(upmx->pctl, &u300_gpio_ranges[i]);
}
platform_set_drvdata(pdev, upmx);
dev_info(&pdev->dev, "initialized U300 pin control driver\n");
return 0;
out_no_pmx:
iounmap(upmx->virtbase);
out_no_remap:
platform_set_drvdata(pdev, NULL);
out_no_memregion:
release_mem_region(upmx->phybase, upmx->physize);
return ret;
}
static int __devexit u300_pmx_remove(struct platform_device *pdev)
{
struct u300_pmx *upmx = platform_get_drvdata(pdev);
pinctrl_unregister(upmx->pctl);
iounmap(upmx->virtbase);
release_mem_region(upmx->phybase, upmx->physize);
platform_set_drvdata(pdev, NULL);
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
