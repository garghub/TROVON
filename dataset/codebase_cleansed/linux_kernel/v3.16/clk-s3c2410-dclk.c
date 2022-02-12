static u8 s3c24xx_clkout_get_parent(struct clk_hw *hw)
{
struct s3c24xx_clkout *clkout = to_s3c24xx_clkout(hw);
int num_parents = __clk_get_num_parents(hw->clk);
u32 val;
val = readl_relaxed(S3C24XX_MISCCR) >> clkout->shift;
val >>= clkout->shift;
val &= clkout->mask;
if (val >= num_parents)
return -EINVAL;
return val;
}
static int s3c24xx_clkout_set_parent(struct clk_hw *hw, u8 index)
{
struct s3c24xx_clkout *clkout = to_s3c24xx_clkout(hw);
int ret = 0;
s3c2410_modify_misccr((clkout->mask << clkout->shift),
(index << clkout->shift));
return ret;
}
struct clk *s3c24xx_register_clkout(struct device *dev, const char *name,
const char **parent_names, u8 num_parents,
u8 shift, u32 mask)
{
struct s3c24xx_clkout *clkout;
struct clk *clk;
struct clk_init_data init;
clkout = kzalloc(sizeof(*clkout), GFP_KERNEL);
if (!clkout)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &s3c24xx_clkout_ops;
init.flags = CLK_IS_BASIC;
init.parent_names = parent_names;
init.num_parents = num_parents;
clkout->shift = shift;
clkout->mask = mask;
clkout->hw.init = &init;
clk = clk_register(dev, &clkout->hw);
return clk;
}
static void s3c24xx_dclk_update_cmp(struct s3c24xx_dclk *s3c24xx_dclk,
int div_shift, int cmp_shift)
{
unsigned long flags = 0;
u32 dclk_con, div, cmp;
spin_lock_irqsave(&s3c24xx_dclk->dclk_lock, flags);
dclk_con = readl_relaxed(s3c24xx_dclk->base);
div = ((dclk_con >> div_shift) & DCLKCON_DCLK_DIV_MASK) + 1;
cmp = ((div + 1) / 2) - 1;
dclk_con &= ~(DCLKCON_DCLK_DIV_MASK << cmp_shift);
dclk_con |= (cmp << cmp_shift);
writel_relaxed(dclk_con, s3c24xx_dclk->base);
spin_unlock_irqrestore(&s3c24xx_dclk->dclk_lock, flags);
}
static int s3c24xx_dclk0_div_notify(struct notifier_block *nb,
unsigned long event, void *data)
{
struct s3c24xx_dclk *s3c24xx_dclk = to_s3c24xx_dclk0(nb);
if (event == POST_RATE_CHANGE) {
s3c24xx_dclk_update_cmp(s3c24xx_dclk,
DCLKCON_DCLK0_DIV_SHIFT, DCLKCON_DCLK0_CMP_SHIFT);
}
return NOTIFY_DONE;
}
static int s3c24xx_dclk1_div_notify(struct notifier_block *nb,
unsigned long event, void *data)
{
struct s3c24xx_dclk *s3c24xx_dclk = to_s3c24xx_dclk1(nb);
if (event == POST_RATE_CHANGE) {
s3c24xx_dclk_update_cmp(s3c24xx_dclk,
DCLKCON_DCLK1_DIV_SHIFT, DCLKCON_DCLK1_CMP_SHIFT);
}
return NOTIFY_DONE;
}
static int s3c24xx_dclk_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct s3c24xx_dclk *s3c24xx_dclk = platform_get_drvdata(pdev);
s3c24xx_dclk->reg_save = readl_relaxed(s3c24xx_dclk->base);
return 0;
}
static int s3c24xx_dclk_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct s3c24xx_dclk *s3c24xx_dclk = platform_get_drvdata(pdev);
writel_relaxed(s3c24xx_dclk->reg_save, s3c24xx_dclk->base);
return 0;
}
static int s3c24xx_dclk_probe(struct platform_device *pdev)
{
struct s3c24xx_dclk *s3c24xx_dclk;
struct resource *mem;
struct clk **clk_table;
struct s3c24xx_dclk_drv_data *dclk_variant;
int ret, i;
s3c24xx_dclk = devm_kzalloc(&pdev->dev, sizeof(*s3c24xx_dclk),
GFP_KERNEL);
if (!s3c24xx_dclk)
return -ENOMEM;
s3c24xx_dclk->dev = &pdev->dev;
platform_set_drvdata(pdev, s3c24xx_dclk);
spin_lock_init(&s3c24xx_dclk->dclk_lock);
clk_table = devm_kzalloc(&pdev->dev,
sizeof(struct clk *) * DCLK_MAX_CLKS,
GFP_KERNEL);
if (!clk_table)
return -ENOMEM;
s3c24xx_dclk->clk_data.clks = clk_table;
s3c24xx_dclk->clk_data.clk_num = DCLK_MAX_CLKS;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
s3c24xx_dclk->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(s3c24xx_dclk->base))
return PTR_ERR(s3c24xx_dclk->base);
dclk_variant = (struct s3c24xx_dclk_drv_data *)
platform_get_device_id(pdev)->driver_data;
clk_table[MUX_DCLK0] = clk_register_mux(&pdev->dev, "mux_dclk0",
dclk_variant->mux_parent_names,
dclk_variant->mux_num_parents, 0,
s3c24xx_dclk->base, 1, 1, 0,
&s3c24xx_dclk->dclk_lock);
clk_table[MUX_DCLK1] = clk_register_mux(&pdev->dev, "mux_dclk1",
dclk_variant->mux_parent_names,
dclk_variant->mux_num_parents, 0,
s3c24xx_dclk->base, 17, 1, 0,
&s3c24xx_dclk->dclk_lock);
clk_table[DIV_DCLK0] = clk_register_divider(&pdev->dev, "div_dclk0",
"mux_dclk0", 0, s3c24xx_dclk->base,
4, 4, 0, &s3c24xx_dclk->dclk_lock);
clk_table[DIV_DCLK1] = clk_register_divider(&pdev->dev, "div_dclk1",
"mux_dclk1", 0, s3c24xx_dclk->base,
20, 4, 0, &s3c24xx_dclk->dclk_lock);
clk_table[GATE_DCLK0] = clk_register_gate(&pdev->dev, "gate_dclk0",
"div_dclk0", CLK_SET_RATE_PARENT,
s3c24xx_dclk->base, 0, 0,
&s3c24xx_dclk->dclk_lock);
clk_table[GATE_DCLK1] = clk_register_gate(&pdev->dev, "gate_dclk1",
"div_dclk1", CLK_SET_RATE_PARENT,
s3c24xx_dclk->base, 16, 0,
&s3c24xx_dclk->dclk_lock);
clk_table[MUX_CLKOUT0] = s3c24xx_register_clkout(&pdev->dev,
"clkout0", dclk_variant->clkout0_parent_names,
dclk_variant->clkout0_num_parents, 4, 7);
clk_table[MUX_CLKOUT1] = s3c24xx_register_clkout(&pdev->dev,
"clkout1", dclk_variant->clkout1_parent_names,
dclk_variant->clkout1_num_parents, 8, 7);
for (i = 0; i < DCLK_MAX_CLKS; i++)
if (IS_ERR(clk_table[i])) {
dev_err(&pdev->dev, "clock %d failed to register\n", i);
ret = PTR_ERR(clk_table[i]);
goto err_clk_register;
}
ret = clk_register_clkdev(clk_table[MUX_DCLK0], "dclk0", NULL);
if (!ret)
ret = clk_register_clkdev(clk_table[MUX_DCLK1], "dclk1", NULL);
if (!ret)
ret = clk_register_clkdev(clk_table[MUX_CLKOUT0],
"clkout0", NULL);
if (!ret)
ret = clk_register_clkdev(clk_table[MUX_CLKOUT1],
"clkout1", NULL);
if (ret) {
dev_err(&pdev->dev, "failed to register aliases, %d\n", ret);
goto err_clk_register;
}
s3c24xx_dclk->dclk0_div_change_nb.notifier_call =
s3c24xx_dclk0_div_notify;
s3c24xx_dclk->dclk1_div_change_nb.notifier_call =
s3c24xx_dclk1_div_notify;
ret = clk_notifier_register(clk_table[DIV_DCLK0],
&s3c24xx_dclk->dclk0_div_change_nb);
if (ret)
goto err_clk_register;
ret = clk_notifier_register(clk_table[DIV_DCLK1],
&s3c24xx_dclk->dclk1_div_change_nb);
if (ret)
goto err_dclk_notify;
return 0;
err_dclk_notify:
clk_notifier_unregister(clk_table[DIV_DCLK0],
&s3c24xx_dclk->dclk0_div_change_nb);
err_clk_register:
for (i = 0; i < DCLK_MAX_CLKS; i++)
if (clk_table[i] && !IS_ERR(clk_table[i]))
clk_unregister(clk_table[i]);
return ret;
}
static int s3c24xx_dclk_remove(struct platform_device *pdev)
{
struct s3c24xx_dclk *s3c24xx_dclk = platform_get_drvdata(pdev);
struct clk **clk_table = s3c24xx_dclk->clk_data.clks;
int i;
clk_notifier_unregister(clk_table[DIV_DCLK1],
&s3c24xx_dclk->dclk1_div_change_nb);
clk_notifier_unregister(clk_table[DIV_DCLK0],
&s3c24xx_dclk->dclk0_div_change_nb);
for (i = 0; i < DCLK_MAX_CLKS; i++)
clk_unregister(clk_table[i]);
return 0;
}
