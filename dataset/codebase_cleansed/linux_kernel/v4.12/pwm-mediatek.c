static inline struct mtk_pwm_chip *to_mtk_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct mtk_pwm_chip, chip);
}
static inline u32 mtk_pwm_readl(struct mtk_pwm_chip *chip, unsigned int num,
unsigned int offset)
{
return readl(chip->regs + 0x10 + (num * 0x40) + offset);
}
static inline void mtk_pwm_writel(struct mtk_pwm_chip *chip,
unsigned int num, unsigned int offset,
u32 value)
{
writel(value, chip->regs + 0x10 + (num * 0x40) + offset);
}
static int mtk_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct mtk_pwm_chip *pc = to_mtk_pwm_chip(chip);
struct clk *clk = pc->clks[MTK_CLK_PWM1 + pwm->hwpwm];
u32 resolution, clkdiv = 0;
resolution = NSEC_PER_SEC / clk_get_rate(clk);
while (period_ns / resolution > 8191) {
resolution *= 2;
clkdiv++;
}
if (clkdiv > 7)
return -EINVAL;
mtk_pwm_writel(pc, pwm->hwpwm, PWMCON, BIT(15) | BIT(3) | clkdiv);
mtk_pwm_writel(pc, pwm->hwpwm, PWMDWIDTH, period_ns / resolution);
mtk_pwm_writel(pc, pwm->hwpwm, PWMTHRES, duty_ns / resolution);
return 0;
}
static int mtk_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct mtk_pwm_chip *pc = to_mtk_pwm_chip(chip);
u32 value;
int ret;
ret = clk_prepare(pc->clks[MTK_CLK_PWM1 + pwm->hwpwm]);
if (ret < 0)
return ret;
value = readl(pc->regs);
value |= BIT(pwm->hwpwm);
writel(value, pc->regs);
return 0;
}
static void mtk_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct mtk_pwm_chip *pc = to_mtk_pwm_chip(chip);
u32 value;
value = readl(pc->regs);
value &= ~BIT(pwm->hwpwm);
writel(value, pc->regs);
clk_unprepare(pc->clks[MTK_CLK_PWM1 + pwm->hwpwm]);
}
static int mtk_pwm_probe(struct platform_device *pdev)
{
struct mtk_pwm_chip *pc;
struct resource *res;
unsigned int i;
int ret;
pc = devm_kzalloc(&pdev->dev, sizeof(*pc), GFP_KERNEL);
if (!pc)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pc->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pc->regs))
return PTR_ERR(pc->regs);
for (i = 0; i < MTK_CLK_MAX; i++) {
pc->clks[i] = devm_clk_get(&pdev->dev, mtk_pwm_clk_name[i]);
if (IS_ERR(pc->clks[i]))
return PTR_ERR(pc->clks[i]);
}
ret = clk_prepare(pc->clks[MTK_CLK_TOP]);
if (ret < 0)
return ret;
ret = clk_prepare(pc->clks[MTK_CLK_MAIN]);
if (ret < 0)
goto disable_clk_top;
platform_set_drvdata(pdev, pc);
pc->chip.dev = &pdev->dev;
pc->chip.ops = &mtk_pwm_ops;
pc->chip.base = -1;
pc->chip.npwm = 5;
ret = pwmchip_add(&pc->chip);
if (ret < 0) {
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
goto disable_clk_main;
}
return 0;
disable_clk_main:
clk_unprepare(pc->clks[MTK_CLK_MAIN]);
disable_clk_top:
clk_unprepare(pc->clks[MTK_CLK_TOP]);
return ret;
}
static int mtk_pwm_remove(struct platform_device *pdev)
{
struct mtk_pwm_chip *pc = platform_get_drvdata(pdev);
unsigned int i;
for (i = 0; i < pc->chip.npwm; i++)
pwm_disable(&pc->chip.pwms[i]);
return pwmchip_remove(&pc->chip);
}
