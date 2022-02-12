static int lpc18xx_rgu_restart(struct notifier_block *this, unsigned long mode,
void *cmd)
{
writel(BIT(LPC18XX_RGU_CORE_RST), rgu_base + LPC18XX_RGU_CTRL0);
mdelay(2000);
pr_emerg("%s: unable to restart system\n", __func__);
return NOTIFY_DONE;
}
static int lpc18xx_rgu_setclear_reset(struct reset_controller_dev *rcdev,
unsigned long id, bool set)
{
struct lpc18xx_rgu_data *rc = to_rgu_data(rcdev);
u32 stat_offset = LPC18XX_RGU_ACTIVE_STATUS0;
u32 ctrl_offset = LPC18XX_RGU_CTRL0;
unsigned long flags;
u32 stat, rst_bit;
stat_offset += (id / LPC18XX_RGU_RESETS_PER_REG) * sizeof(u32);
ctrl_offset += (id / LPC18XX_RGU_RESETS_PER_REG) * sizeof(u32);
rst_bit = 1 << (id % LPC18XX_RGU_RESETS_PER_REG);
spin_lock_irqsave(&rc->lock, flags);
stat = ~readl(rc->base + stat_offset);
if (set)
writel(stat | rst_bit, rc->base + ctrl_offset);
else
writel(stat & ~rst_bit, rc->base + ctrl_offset);
spin_unlock_irqrestore(&rc->lock, flags);
return 0;
}
static int lpc18xx_rgu_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return lpc18xx_rgu_setclear_reset(rcdev, id, true);
}
static int lpc18xx_rgu_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
return lpc18xx_rgu_setclear_reset(rcdev, id, false);
}
static int lpc18xx_rgu_reset(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct lpc18xx_rgu_data *rc = to_rgu_data(rcdev);
lpc18xx_rgu_assert(rcdev, id);
udelay(rc->delay_us);
switch (id) {
case LPC43XX_RGU_M0SUB_RST:
case LPC43XX_RGU_M0APP_RST:
lpc18xx_rgu_setclear_reset(rcdev, id, false);
}
return 0;
}
static int lpc18xx_rgu_status(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct lpc18xx_rgu_data *rc = to_rgu_data(rcdev);
u32 bit, offset = LPC18XX_RGU_ACTIVE_STATUS0;
offset += (id / LPC18XX_RGU_RESETS_PER_REG) * sizeof(u32);
bit = 1 << (id % LPC18XX_RGU_RESETS_PER_REG);
return !(readl(rc->base + offset) & bit);
}
static int lpc18xx_rgu_probe(struct platform_device *pdev)
{
struct lpc18xx_rgu_data *rc;
struct resource *res;
u32 fcclk, firc;
int ret;
rc = devm_kzalloc(&pdev->dev, sizeof(*rc), GFP_KERNEL);
if (!rc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rc->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rc->base))
return PTR_ERR(rc->base);
rc->clk_reg = devm_clk_get(&pdev->dev, "reg");
if (IS_ERR(rc->clk_reg)) {
dev_err(&pdev->dev, "reg clock not found\n");
return PTR_ERR(rc->clk_reg);
}
rc->clk_delay = devm_clk_get(&pdev->dev, "delay");
if (IS_ERR(rc->clk_delay)) {
dev_err(&pdev->dev, "delay clock not found\n");
return PTR_ERR(rc->clk_delay);
}
ret = clk_prepare_enable(rc->clk_reg);
if (ret) {
dev_err(&pdev->dev, "unable to enable reg clock\n");
return ret;
}
ret = clk_prepare_enable(rc->clk_delay);
if (ret) {
dev_err(&pdev->dev, "unable to enable delay clock\n");
goto dis_clk_reg;
}
fcclk = clk_get_rate(rc->clk_reg) / USEC_PER_SEC;
firc = clk_get_rate(rc->clk_delay) / USEC_PER_SEC;
if (fcclk == 0 || firc == 0)
rc->delay_us = 2;
else
rc->delay_us = DIV_ROUND_UP(fcclk, firc * firc);
spin_lock_init(&rc->lock);
rc->rcdev.owner = THIS_MODULE;
rc->rcdev.nr_resets = 64;
rc->rcdev.ops = &lpc18xx_rgu_ops;
rc->rcdev.of_node = pdev->dev.of_node;
platform_set_drvdata(pdev, rc);
ret = reset_controller_register(&rc->rcdev);
if (ret) {
dev_err(&pdev->dev, "unable to register device\n");
goto dis_clks;
}
rgu_base = rc->base;
ret = register_restart_handler(&lpc18xx_rgu_restart_nb);
if (ret)
dev_warn(&pdev->dev, "failed to register restart handler\n");
return 0;
dis_clks:
clk_disable_unprepare(rc->clk_delay);
dis_clk_reg:
clk_disable_unprepare(rc->clk_reg);
return ret;
}
static int lpc18xx_rgu_remove(struct platform_device *pdev)
{
struct lpc18xx_rgu_data *rc = platform_get_drvdata(pdev);
int ret;
ret = unregister_restart_handler(&lpc18xx_rgu_restart_nb);
if (ret)
dev_warn(&pdev->dev, "failed to unregister restart handler\n");
reset_controller_unregister(&rc->rcdev);
clk_disable_unprepare(rc->clk_delay);
clk_disable_unprepare(rc->clk_reg);
return 0;
}
