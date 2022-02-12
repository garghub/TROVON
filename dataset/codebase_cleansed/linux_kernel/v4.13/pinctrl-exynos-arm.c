static void s5pv210_retention_disable(struct samsung_pinctrl_drv_data *drvdata)
{
void __iomem *clk_base = (void __iomem *)drvdata->retention_ctrl->priv;
u32 tmp;
tmp = __raw_readl(clk_base + S5P_OTHERS);
tmp |= (S5P_OTHERS_RET_IO | S5P_OTHERS_RET_CF | S5P_OTHERS_RET_MMC |
S5P_OTHERS_RET_UART);
__raw_writel(tmp, clk_base + S5P_OTHERS);
}
static struct samsung_retention_ctrl *
s5pv210_retention_init(struct samsung_pinctrl_drv_data *drvdata,
const struct samsung_retention_data *data)
{
struct samsung_retention_ctrl *ctrl;
struct device_node *np;
void __iomem *clk_base;
ctrl = devm_kzalloc(drvdata->dev, sizeof(*ctrl), GFP_KERNEL);
if (!ctrl)
return ERR_PTR(-ENOMEM);
np = of_find_compatible_node(NULL, NULL, "samsung,s5pv210-clock");
if (!np) {
pr_err("%s: failed to find clock controller DT node\n",
__func__);
return ERR_PTR(-ENODEV);
}
clk_base = of_iomap(np, 0);
if (!clk_base) {
pr_err("%s: failed to map clock registers\n", __func__);
return ERR_PTR(-EINVAL);
}
ctrl->priv = (void __force *)clk_base;
ctrl->disable = s5pv210_retention_disable;
return ctrl;
}
