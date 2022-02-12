static int sirfsoc_list_groups(struct pinctrl_dev *pctldev, unsigned selector)
{
if (selector >= ARRAY_SIZE(sirfsoc_pin_groups))
return -EINVAL;
return 0;
}
static const char *sirfsoc_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
if (selector >= ARRAY_SIZE(sirfsoc_pin_groups))
return NULL;
return sirfsoc_pin_groups[selector].name;
}
static int sirfsoc_get_group_pins(struct pinctrl_dev *pctldev, unsigned selector,
const unsigned **pins,
unsigned *num_pins)
{
if (selector >= ARRAY_SIZE(sirfsoc_pin_groups))
return -EINVAL;
*pins = sirfsoc_pin_groups[selector].pins;
*num_pins = sirfsoc_pin_groups[selector].num_pins;
return 0;
}
static void sirfsoc_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned offset)
{
seq_printf(s, " " DRIVER_NAME);
}
static void sirfsoc_pinmux_endisable(struct sirfsoc_pmx *spmx, unsigned selector,
bool enable)
{
int i;
const struct sirfsoc_padmux *mux = sirfsoc_pmx_functions[selector].padmux;
const struct sirfsoc_muxmask *mask = mux->muxmask;
for (i = 0; i < mux->muxmask_counts; i++) {
u32 muxval;
muxval = readl(spmx->gpio_virtbase + SIRFSOC_GPIO_PAD_EN(mask[i].group));
if (enable)
muxval = muxval & ~mask[i].mask;
else
muxval = muxval | mask[i].mask;
writel(muxval, spmx->gpio_virtbase + SIRFSOC_GPIO_PAD_EN(mask[i].group));
}
if (mux->funcmask && enable) {
u32 func_en_val;
func_en_val =
readl(spmx->rsc_virtbase + SIRFSOC_RSC_PIN_MUX);
func_en_val =
(func_en_val & ~mux->funcmask) | (mux->
funcval);
writel(func_en_val, spmx->rsc_virtbase + SIRFSOC_RSC_PIN_MUX);
}
}
static int sirfsoc_pinmux_enable(struct pinctrl_dev *pmxdev, unsigned selector,
unsigned group)
{
struct sirfsoc_pmx *spmx;
spmx = pinctrl_dev_get_drvdata(pmxdev);
sirfsoc_pinmux_endisable(spmx, selector, true);
return 0;
}
static void sirfsoc_pinmux_disable(struct pinctrl_dev *pmxdev, unsigned selector,
unsigned group)
{
struct sirfsoc_pmx *spmx;
spmx = pinctrl_dev_get_drvdata(pmxdev);
sirfsoc_pinmux_endisable(spmx, selector, false);
}
static int sirfsoc_pinmux_list_funcs(struct pinctrl_dev *pmxdev, unsigned selector)
{
if (selector >= ARRAY_SIZE(sirfsoc_pmx_functions))
return -EINVAL;
return 0;
}
static const char *sirfsoc_pinmux_get_func_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
return sirfsoc_pmx_functions[selector].name;
}
static int sirfsoc_pinmux_get_groups(struct pinctrl_dev *pctldev, unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
*groups = sirfsoc_pmx_functions[selector].groups;
*num_groups = sirfsoc_pmx_functions[selector].num_groups;
return 0;
}
static int sirfsoc_pinmux_request_gpio(struct pinctrl_dev *pmxdev,
struct pinctrl_gpio_range *range, unsigned offset)
{
struct sirfsoc_pmx *spmx;
int group = range->id;
u32 muxval;
spmx = pinctrl_dev_get_drvdata(pmxdev);
muxval = readl(spmx->gpio_virtbase + SIRFSOC_GPIO_PAD_EN(group));
muxval = muxval | (1 << offset);
writel(muxval, spmx->gpio_virtbase + SIRFSOC_GPIO_PAD_EN(group));
return 0;
}
static void __iomem *sirfsoc_rsc_of_iomap(void)
{
const struct of_device_id rsc_ids[] = {
{ .compatible = "sirf,prima2-rsc" },
{}
};
struct device_node *np;
np = of_find_matching_node(NULL, rsc_ids);
if (!np)
panic("unable to find compatible rsc node in dtb\n");
return of_iomap(np, 0);
}
static int __devinit sirfsoc_pinmux_probe(struct platform_device *pdev)
{
int ret;
struct sirfsoc_pmx *spmx;
struct device_node *np = pdev->dev.of_node;
int i;
spmx = devm_kzalloc(&pdev->dev, sizeof(*spmx), GFP_KERNEL);
if (!spmx)
return -ENOMEM;
spmx->dev = &pdev->dev;
platform_set_drvdata(pdev, spmx);
spmx->gpio_virtbase = of_iomap(np, 0);
if (!spmx->gpio_virtbase) {
ret = -ENOMEM;
dev_err(&pdev->dev, "can't map gpio registers\n");
goto out_no_gpio_remap;
}
spmx->rsc_virtbase = sirfsoc_rsc_of_iomap();
if (!spmx->rsc_virtbase) {
ret = -ENOMEM;
dev_err(&pdev->dev, "can't map rsc registers\n");
goto out_no_rsc_remap;
}
spmx->pmx = pinctrl_register(&sirfsoc_pinmux_desc, &pdev->dev, spmx);
if (!spmx->pmx) {
dev_err(&pdev->dev, "could not register SIRFSOC pinmux driver\n");
ret = -EINVAL;
goto out_no_pmx;
}
for (i = 0; i < ARRAY_SIZE(sirfsoc_gpio_ranges); i++)
pinctrl_add_gpio_range(spmx->pmx, &sirfsoc_gpio_ranges[i]);
dev_info(&pdev->dev, "initialized SIRFSOC pinmux driver\n");
return 0;
out_no_pmx:
iounmap(spmx->rsc_virtbase);
out_no_rsc_remap:
iounmap(spmx->gpio_virtbase);
out_no_gpio_remap:
platform_set_drvdata(pdev, NULL);
devm_kfree(&pdev->dev, spmx);
return ret;
}
static int __init sirfsoc_pinmux_init(void)
{
return platform_driver_register(&sirfsoc_pinmux_driver);
}
