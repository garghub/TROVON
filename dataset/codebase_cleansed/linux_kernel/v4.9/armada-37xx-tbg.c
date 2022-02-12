static unsigned int tbg_get_mult(void __iomem *reg, const struct tbg_def *ptbg)
{
u32 val;
val = readl(reg + TBG_CTRL0);
return ((val >> ptbg->fbdiv_offset) & TBG_DIV_MASK) << 2;
}
static unsigned int tbg_get_div(void __iomem *reg, const struct tbg_def *ptbg)
{
u32 val;
unsigned int div;
val = readl(reg + TBG_CTRL7);
div = (val >> ptbg->refdiv_offset) & TBG_DIV_MASK;
if (div == 0)
div = 1;
val = readl(reg + ptbg->vcodiv_reg);
div *= 1 << ((val >> ptbg->vcodiv_offset) & TBG_DIV_MASK);
return div;
}
static int armada_3700_tbg_clock_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct clk_hw_onecell_data *hw_tbg_data;
struct device *dev = &pdev->dev;
const char *parent_name;
struct resource *res;
struct clk *parent;
void __iomem *reg;
int i, ret;
hw_tbg_data = devm_kzalloc(&pdev->dev, sizeof(*hw_tbg_data)
+ sizeof(*hw_tbg_data->hws) * NUM_TBG,
GFP_KERNEL);
if (!hw_tbg_data)
return -ENOMEM;
hw_tbg_data->num = NUM_TBG;
platform_set_drvdata(pdev, hw_tbg_data);
parent = devm_clk_get(dev, NULL);
if (IS_ERR(parent)) {
dev_err(dev, "Could get the clock parent\n");
return -EINVAL;
}
parent_name = __clk_get_name(parent);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(dev, res);
if (IS_ERR(reg))
return PTR_ERR(reg);
for (i = 0; i < NUM_TBG; i++) {
const char *name;
unsigned int mult, div;
name = tbg[i].name;
mult = tbg_get_mult(reg, &tbg[i]);
div = tbg_get_div(reg, &tbg[i]);
hw_tbg_data->hws[i] = clk_hw_register_fixed_factor(NULL, name,
parent_name, 0, mult, div);
if (IS_ERR(hw_tbg_data->hws[i]))
dev_err(dev, "Can't register TBG clock %s\n", name);
}
ret = of_clk_add_hw_provider(np, of_clk_hw_onecell_get, hw_tbg_data);
return ret;
}
static int armada_3700_tbg_clock_remove(struct platform_device *pdev)
{
int i;
struct clk_hw_onecell_data *hw_tbg_data = platform_get_drvdata(pdev);
of_clk_del_provider(pdev->dev.of_node);
for (i = 0; i < hw_tbg_data->num; i++)
clk_hw_unregister_fixed_factor(hw_tbg_data->hws[i]);
return 0;
}
