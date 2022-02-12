static inline struct fsl_pwm_chip *to_fsl_chip(struct pwm_chip *chip)
{
return container_of(chip, struct fsl_pwm_chip, chip);
}
static int fsl_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct fsl_pwm_chip *fpc = to_fsl_chip(chip);
return clk_prepare_enable(fpc->clk[FSL_PWM_CLK_SYS]);
}
static void fsl_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct fsl_pwm_chip *fpc = to_fsl_chip(chip);
clk_disable_unprepare(fpc->clk[FSL_PWM_CLK_SYS]);
}
static int fsl_pwm_calculate_default_ps(struct fsl_pwm_chip *fpc,
enum fsl_pwm_clk index)
{
unsigned long sys_rate, cnt_rate;
unsigned long long ratio;
sys_rate = clk_get_rate(fpc->clk[FSL_PWM_CLK_SYS]);
if (!sys_rate)
return -EINVAL;
cnt_rate = clk_get_rate(fpc->clk[fpc->cnt_select]);
if (!cnt_rate)
return -EINVAL;
switch (index) {
case FSL_PWM_CLK_SYS:
fpc->clk_ps = 1;
break;
case FSL_PWM_CLK_FIX:
ratio = 2 * cnt_rate - 1;
do_div(ratio, sys_rate);
fpc->clk_ps = ratio;
break;
case FSL_PWM_CLK_EXT:
ratio = 4 * cnt_rate - 1;
do_div(ratio, sys_rate);
fpc->clk_ps = ratio;
break;
default:
return -EINVAL;
}
return 0;
}
static unsigned long fsl_pwm_calculate_cycles(struct fsl_pwm_chip *fpc,
unsigned long period_ns)
{
unsigned long long c, c0;
c = clk_get_rate(fpc->clk[fpc->cnt_select]);
c = c * period_ns;
do_div(c, 1000000000UL);
do {
c0 = c;
do_div(c0, (1 << fpc->clk_ps));
if (c0 <= 0xFFFF)
return (unsigned long)c0;
} while (++fpc->clk_ps < 8);
return 0;
}
static unsigned long fsl_pwm_calculate_period_cycles(struct fsl_pwm_chip *fpc,
unsigned long period_ns,
enum fsl_pwm_clk index)
{
int ret;
ret = fsl_pwm_calculate_default_ps(fpc, index);
if (ret) {
dev_err(fpc->chip.dev,
"failed to calculate default prescaler: %d\n",
ret);
return 0;
}
return fsl_pwm_calculate_cycles(fpc, period_ns);
}
static unsigned long fsl_pwm_calculate_period(struct fsl_pwm_chip *fpc,
unsigned long period_ns)
{
enum fsl_pwm_clk m0, m1;
unsigned long fix_rate, ext_rate, cycles;
cycles = fsl_pwm_calculate_period_cycles(fpc, period_ns,
FSL_PWM_CLK_SYS);
if (cycles) {
fpc->cnt_select = FSL_PWM_CLK_SYS;
return cycles;
}
fix_rate = clk_get_rate(fpc->clk[FSL_PWM_CLK_FIX]);
ext_rate = clk_get_rate(fpc->clk[FSL_PWM_CLK_EXT]);
if (fix_rate > ext_rate) {
m0 = FSL_PWM_CLK_FIX;
m1 = FSL_PWM_CLK_EXT;
} else {
m0 = FSL_PWM_CLK_EXT;
m1 = FSL_PWM_CLK_FIX;
}
cycles = fsl_pwm_calculate_period_cycles(fpc, period_ns, m0);
if (cycles) {
fpc->cnt_select = m0;
return cycles;
}
fpc->cnt_select = m1;
return fsl_pwm_calculate_period_cycles(fpc, period_ns, m1);
}
static unsigned long fsl_pwm_calculate_duty(struct fsl_pwm_chip *fpc,
unsigned long period_ns,
unsigned long duty_ns)
{
unsigned long long val, duty;
val = readl(fpc->base + FTM_MOD);
duty = duty_ns * (val + 1);
do_div(duty, period_ns);
return (unsigned long)duty;
}
static int fsl_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct fsl_pwm_chip *fpc = to_fsl_chip(chip);
u32 val, period, duty;
mutex_lock(&fpc->lock);
if (fpc->period_ns && fpc->period_ns != period_ns) {
dev_err(fpc->chip.dev,
"conflicting period requested for PWM %u\n",
pwm->hwpwm);
mutex_unlock(&fpc->lock);
return -EBUSY;
}
if (!fpc->period_ns && duty_ns) {
period = fsl_pwm_calculate_period(fpc, period_ns);
if (!period) {
dev_err(fpc->chip.dev, "failed to calculate period\n");
mutex_unlock(&fpc->lock);
return -EINVAL;
}
val = readl(fpc->base + FTM_SC);
val &= ~(FTM_SC_PS_MASK << FTM_SC_PS_SHIFT);
val |= fpc->clk_ps;
writel(val, fpc->base + FTM_SC);
writel(period - 1, fpc->base + FTM_MOD);
fpc->period_ns = period_ns;
}
mutex_unlock(&fpc->lock);
duty = fsl_pwm_calculate_duty(fpc, period_ns, duty_ns);
writel(FTM_CSC_MSB | FTM_CSC_ELSB, fpc->base + FTM_CSC(pwm->hwpwm));
writel(duty, fpc->base + FTM_CV(pwm->hwpwm));
return 0;
}
static int fsl_pwm_set_polarity(struct pwm_chip *chip,
struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct fsl_pwm_chip *fpc = to_fsl_chip(chip);
u32 val;
val = readl(fpc->base + FTM_POL);
if (polarity == PWM_POLARITY_INVERSED)
val |= BIT(pwm->hwpwm);
else
val &= ~BIT(pwm->hwpwm);
writel(val, fpc->base + FTM_POL);
return 0;
}
static int fsl_counter_clock_enable(struct fsl_pwm_chip *fpc)
{
u32 val;
int ret;
if (fpc->use_count != 0)
return 0;
val = readl(fpc->base + FTM_SC);
val &= ~(FTM_SC_CLK_MASK << FTM_SC_CLK_SHIFT);
val |= FTM_SC_CLK(fpc->cnt_select);
writel(val, fpc->base + FTM_SC);
ret = clk_prepare_enable(fpc->clk[fpc->cnt_select]);
if (ret)
return ret;
ret = clk_prepare_enable(fpc->clk[FSL_PWM_CLK_CNTEN]);
if (ret) {
clk_disable_unprepare(fpc->clk[fpc->cnt_select]);
return ret;
}
fpc->use_count++;
return 0;
}
static int fsl_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct fsl_pwm_chip *fpc = to_fsl_chip(chip);
u32 val;
int ret;
mutex_lock(&fpc->lock);
val = readl(fpc->base + FTM_OUTMASK);
val &= ~BIT(pwm->hwpwm);
writel(val, fpc->base + FTM_OUTMASK);
ret = fsl_counter_clock_enable(fpc);
mutex_unlock(&fpc->lock);
return ret;
}
static void fsl_counter_clock_disable(struct fsl_pwm_chip *fpc)
{
u32 val;
if (fpc->use_count == 0)
return;
if (--fpc->use_count > 0)
return;
val = readl(fpc->base + FTM_SC);
val &= ~(FTM_SC_CLK_MASK << FTM_SC_CLK_SHIFT);
writel(val, fpc->base + FTM_SC);
clk_disable_unprepare(fpc->clk[FSL_PWM_CLK_CNTEN]);
clk_disable_unprepare(fpc->clk[fpc->cnt_select]);
}
static void fsl_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct fsl_pwm_chip *fpc = to_fsl_chip(chip);
u32 val;
mutex_lock(&fpc->lock);
val = readl(fpc->base + FTM_OUTMASK);
val |= BIT(pwm->hwpwm);
writel(val, fpc->base + FTM_OUTMASK);
fsl_counter_clock_disable(fpc);
val = readl(fpc->base + FTM_OUTMASK);
if ((val & 0xFF) == 0xFF)
fpc->period_ns = 0;
mutex_unlock(&fpc->lock);
}
static int fsl_pwm_init(struct fsl_pwm_chip *fpc)
{
int ret;
ret = clk_prepare_enable(fpc->clk[FSL_PWM_CLK_SYS]);
if (ret)
return ret;
writel(0x00, fpc->base + FTM_CNTIN);
writel(0x00, fpc->base + FTM_OUTINIT);
writel(0xFF, fpc->base + FTM_OUTMASK);
clk_disable_unprepare(fpc->clk[FSL_PWM_CLK_SYS]);
return 0;
}
static int fsl_pwm_probe(struct platform_device *pdev)
{
struct fsl_pwm_chip *fpc;
struct resource *res;
int ret;
fpc = devm_kzalloc(&pdev->dev, sizeof(*fpc), GFP_KERNEL);
if (!fpc)
return -ENOMEM;
mutex_init(&fpc->lock);
fpc->chip.dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
fpc->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(fpc->base))
return PTR_ERR(fpc->base);
fpc->clk[FSL_PWM_CLK_SYS] = devm_clk_get(&pdev->dev, "ftm_sys");
if (IS_ERR(fpc->clk[FSL_PWM_CLK_SYS])) {
dev_err(&pdev->dev, "failed to get \"ftm_sys\" clock\n");
return PTR_ERR(fpc->clk[FSL_PWM_CLK_SYS]);
}
fpc->clk[FSL_PWM_CLK_FIX] = devm_clk_get(fpc->chip.dev, "ftm_fix");
if (IS_ERR(fpc->clk[FSL_PWM_CLK_FIX]))
return PTR_ERR(fpc->clk[FSL_PWM_CLK_FIX]);
fpc->clk[FSL_PWM_CLK_EXT] = devm_clk_get(fpc->chip.dev, "ftm_ext");
if (IS_ERR(fpc->clk[FSL_PWM_CLK_EXT]))
return PTR_ERR(fpc->clk[FSL_PWM_CLK_EXT]);
fpc->clk[FSL_PWM_CLK_CNTEN] =
devm_clk_get(fpc->chip.dev, "ftm_cnt_clk_en");
if (IS_ERR(fpc->clk[FSL_PWM_CLK_CNTEN]))
return PTR_ERR(fpc->clk[FSL_PWM_CLK_CNTEN]);
fpc->chip.ops = &fsl_pwm_ops;
fpc->chip.of_xlate = of_pwm_xlate_with_flags;
fpc->chip.of_pwm_n_cells = 3;
fpc->chip.base = -1;
fpc->chip.npwm = 8;
ret = pwmchip_add(&fpc->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add PWM chip: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, fpc);
return fsl_pwm_init(fpc);
}
static int fsl_pwm_remove(struct platform_device *pdev)
{
struct fsl_pwm_chip *fpc = platform_get_drvdata(pdev);
return pwmchip_remove(&fpc->chip);
}
