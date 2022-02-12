static inline int plt_reg_to_parent(int reg)
{
switch (reg & PMC_MASK_CLK_FREQ) {
default:
case PMC_CLK_FREQ_XTAL:
return 0;
case PMC_CLK_FREQ_PLL:
return 1;
}
}
static inline int plt_parent_to_reg(int index)
{
switch (index) {
default:
case 0:
return PMC_CLK_FREQ_XTAL;
case 1:
return PMC_CLK_FREQ_PLL;
}
}
static inline int plt_reg_to_enabled(int reg)
{
switch (reg & PMC_MASK_CLK_CTL) {
case PMC_CLK_CTL_GATED_ON_D3:
case PMC_CLK_CTL_FORCE_ON:
return 1;
case PMC_CLK_CTL_FORCE_OFF:
case PMC_CLK_CTL_RESERVED:
default:
return 0;
}
}
static void plt_clk_reg_update(struct clk_plt *clk, u32 mask, u32 val)
{
u32 tmp;
unsigned long flags;
spin_lock_irqsave(&clk->lock, flags);
tmp = readl(clk->reg);
tmp = (tmp & ~mask) | (val & mask);
writel(tmp, clk->reg);
spin_unlock_irqrestore(&clk->lock, flags);
}
static int plt_clk_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_plt *clk = to_clk_plt(hw);
plt_clk_reg_update(clk, PMC_MASK_CLK_FREQ, plt_parent_to_reg(index));
return 0;
}
static u8 plt_clk_get_parent(struct clk_hw *hw)
{
struct clk_plt *clk = to_clk_plt(hw);
u32 value;
value = readl(clk->reg);
return plt_reg_to_parent(value);
}
static int plt_clk_enable(struct clk_hw *hw)
{
struct clk_plt *clk = to_clk_plt(hw);
plt_clk_reg_update(clk, PMC_MASK_CLK_CTL, PMC_CLK_CTL_FORCE_ON);
return 0;
}
static void plt_clk_disable(struct clk_hw *hw)
{
struct clk_plt *clk = to_clk_plt(hw);
plt_clk_reg_update(clk, PMC_MASK_CLK_CTL, PMC_CLK_CTL_FORCE_OFF);
}
static int plt_clk_is_enabled(struct clk_hw *hw)
{
struct clk_plt *clk = to_clk_plt(hw);
u32 value;
value = readl(clk->reg);
return plt_reg_to_enabled(value);
}
static struct clk_plt *plt_clk_register(struct platform_device *pdev, int id,
void __iomem *base,
const char **parent_names,
int num_parents)
{
struct clk_plt *pclk;
struct clk_init_data init;
int ret;
pclk = devm_kzalloc(&pdev->dev, sizeof(*pclk), GFP_KERNEL);
if (!pclk)
return ERR_PTR(-ENOMEM);
init.name = kasprintf(GFP_KERNEL, "%s_%d", PLT_CLK_NAME_BASE, id);
init.ops = &plt_clk_ops;
init.flags = 0;
init.parent_names = parent_names;
init.num_parents = num_parents;
pclk->hw.init = &init;
pclk->reg = base + PMC_CLK_CTL_OFFSET + id * PMC_CLK_CTL_SIZE;
spin_lock_init(&pclk->lock);
if (plt_clk_is_enabled(&pclk->hw))
init.flags |= CLK_IS_CRITICAL;
ret = devm_clk_hw_register(&pdev->dev, &pclk->hw);
if (ret) {
pclk = ERR_PTR(ret);
goto err_free_init;
}
pclk->lookup = clkdev_hw_create(&pclk->hw, init.name, NULL);
if (!pclk->lookup) {
pclk = ERR_PTR(-ENOMEM);
goto err_free_init;
}
err_free_init:
kfree(init.name);
return pclk;
}
static void plt_clk_unregister(struct clk_plt *pclk)
{
clkdev_drop(pclk->lookup);
}
static struct clk_plt_fixed *plt_clk_register_fixed_rate(struct platform_device *pdev,
const char *name,
const char *parent_name,
unsigned long fixed_rate)
{
struct clk_plt_fixed *pclk;
pclk = devm_kzalloc(&pdev->dev, sizeof(*pclk), GFP_KERNEL);
if (!pclk)
return ERR_PTR(-ENOMEM);
pclk->clk = clk_hw_register_fixed_rate(&pdev->dev, name, parent_name,
0, fixed_rate);
if (IS_ERR(pclk->clk))
return ERR_CAST(pclk->clk);
pclk->lookup = clkdev_hw_create(pclk->clk, name, NULL);
if (!pclk->lookup) {
clk_hw_unregister_fixed_rate(pclk->clk);
return ERR_PTR(-ENOMEM);
}
return pclk;
}
static void plt_clk_unregister_fixed_rate(struct clk_plt_fixed *pclk)
{
clkdev_drop(pclk->lookup);
clk_hw_unregister_fixed_rate(pclk->clk);
}
static void plt_clk_unregister_fixed_rate_loop(struct clk_plt_data *data,
unsigned int i)
{
while (i--)
plt_clk_unregister_fixed_rate(data->parents[i]);
}
static void plt_clk_free_parent_names_loop(const char **parent_names,
unsigned int i)
{
while (i--)
kfree_const(parent_names[i]);
kfree(parent_names);
}
static void plt_clk_unregister_loop(struct clk_plt_data *data,
unsigned int i)
{
while (i--)
plt_clk_unregister(data->clks[i]);
}
static const char **plt_clk_register_parents(struct platform_device *pdev,
struct clk_plt_data *data,
const struct pmc_clk *clks)
{
const char **parent_names;
unsigned int i;
int err;
int nparents = 0;
data->nparents = 0;
while (clks[nparents].name)
nparents++;
data->parents = devm_kcalloc(&pdev->dev, nparents,
sizeof(*data->parents), GFP_KERNEL);
if (!data->parents)
return ERR_PTR(-ENOMEM);
parent_names = kcalloc(nparents, sizeof(*parent_names),
GFP_KERNEL);
if (!parent_names)
return ERR_PTR(-ENOMEM);
for (i = 0; i < nparents; i++) {
data->parents[i] =
plt_clk_register_fixed_rate(pdev, clks[i].name,
clks[i].parent_name,
clks[i].freq);
if (IS_ERR(data->parents[i])) {
err = PTR_ERR(data->parents[i]);
goto err_unreg;
}
parent_names[i] = kstrdup_const(clks[i].name, GFP_KERNEL);
}
data->nparents = nparents;
return parent_names;
err_unreg:
plt_clk_unregister_fixed_rate_loop(data, i);
plt_clk_free_parent_names_loop(parent_names, i);
return ERR_PTR(err);
}
static void plt_clk_unregister_parents(struct clk_plt_data *data)
{
plt_clk_unregister_fixed_rate_loop(data, data->nparents);
}
static int plt_clk_probe(struct platform_device *pdev)
{
const struct pmc_clk_data *pmc_data;
const char **parent_names;
struct clk_plt_data *data;
unsigned int i;
int err;
pmc_data = dev_get_platdata(&pdev->dev);
if (!pmc_data || !pmc_data->clks)
return -EINVAL;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
parent_names = plt_clk_register_parents(pdev, data, pmc_data->clks);
if (IS_ERR(parent_names))
return PTR_ERR(parent_names);
for (i = 0; i < PMC_CLK_NUM; i++) {
data->clks[i] = plt_clk_register(pdev, i, pmc_data->base,
parent_names, data->nparents);
if (IS_ERR(data->clks[i])) {
err = PTR_ERR(data->clks[i]);
goto err_unreg_clk_plt;
}
}
data->mclk_lookup = clkdev_hw_create(&data->clks[3]->hw, "mclk", NULL);
if (!data->mclk_lookup) {
err = -ENOMEM;
goto err_unreg_clk_plt;
}
plt_clk_free_parent_names_loop(parent_names, data->nparents);
platform_set_drvdata(pdev, data);
return 0;
err_unreg_clk_plt:
plt_clk_unregister_loop(data, i);
plt_clk_unregister_parents(data);
plt_clk_free_parent_names_loop(parent_names, data->nparents);
return err;
}
static int plt_clk_remove(struct platform_device *pdev)
{
struct clk_plt_data *data;
data = platform_get_drvdata(pdev);
clkdev_drop(data->mclk_lookup);
plt_clk_unregister_loop(data, PMC_CLK_NUM);
plt_clk_unregister_parents(data);
return 0;
}
