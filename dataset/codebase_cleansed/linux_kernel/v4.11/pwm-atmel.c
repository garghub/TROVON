static inline struct atmel_pwm_chip *to_atmel_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct atmel_pwm_chip, chip);
}
static inline u32 atmel_pwm_readl(struct atmel_pwm_chip *chip,
unsigned long offset)
{
return readl_relaxed(chip->base + offset);
}
static inline void atmel_pwm_writel(struct atmel_pwm_chip *chip,
unsigned long offset, unsigned long val)
{
writel_relaxed(val, chip->base + offset);
}
static inline u32 atmel_pwm_ch_readl(struct atmel_pwm_chip *chip,
unsigned int ch, unsigned long offset)
{
unsigned long base = PWM_CH_REG_OFFSET + ch * PWM_CH_REG_SIZE;
return readl_relaxed(chip->base + base + offset);
}
static inline void atmel_pwm_ch_writel(struct atmel_pwm_chip *chip,
unsigned int ch, unsigned long offset,
unsigned long val)
{
unsigned long base = PWM_CH_REG_OFFSET + ch * PWM_CH_REG_SIZE;
writel_relaxed(val, chip->base + base + offset);
}
static int atmel_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
unsigned long prd, dty;
unsigned long long div;
unsigned int pres = 0;
u32 val;
int ret;
if (pwm_is_enabled(pwm) && (period_ns != pwm_get_period(pwm))) {
dev_err(chip->dev, "cannot change PWM period while enabled\n");
return -EBUSY;
}
div = (unsigned long long)clk_get_rate(atmel_pwm->clk) * period_ns;
do_div(div, NSEC_PER_SEC);
while (div > PWM_MAX_PRD) {
div >>= 1;
pres++;
}
if (pres > PRD_MAX_PRES) {
dev_err(chip->dev, "pres exceeds the maximum value\n");
return -EINVAL;
}
prd = div;
div *= duty_ns;
do_div(div, period_ns);
dty = prd - div;
ret = clk_enable(atmel_pwm->clk);
if (ret) {
dev_err(chip->dev, "failed to enable PWM clock\n");
return ret;
}
val = atmel_pwm_ch_readl(atmel_pwm, pwm->hwpwm, PWM_CMR);
val = (val & ~PWM_CMR_CPRE_MSK) | (pres & PWM_CMR_CPRE_MSK);
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWM_CMR, val);
atmel_pwm->config(chip, pwm, dty, prd);
mutex_lock(&atmel_pwm->isr_lock);
atmel_pwm->updated_pwms |= atmel_pwm_readl(atmel_pwm, PWM_ISR);
atmel_pwm->updated_pwms &= ~(1 << pwm->hwpwm);
mutex_unlock(&atmel_pwm->isr_lock);
clk_disable(atmel_pwm->clk);
return ret;
}
static void atmel_pwm_config_v1(struct pwm_chip *chip, struct pwm_device *pwm,
unsigned long dty, unsigned long prd)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
unsigned int val;
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWMV1_CUPD, dty);
val = atmel_pwm_ch_readl(atmel_pwm, pwm->hwpwm, PWM_CMR);
val &= ~PWM_CMR_UPD_CDTY;
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWM_CMR, val);
if (pwm_is_enabled(pwm))
return;
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWMV1_CDTY, dty);
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWMV1_CPRD, prd);
}
static void atmel_pwm_config_v2(struct pwm_chip *chip, struct pwm_device *pwm,
unsigned long dty, unsigned long prd)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
if (pwm_is_enabled(pwm)) {
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWMV2_CDTYUPD, dty);
} else {
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWMV2_CDTY, dty);
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWMV2_CPRD, prd);
}
}
static int atmel_pwm_set_polarity(struct pwm_chip *chip, struct pwm_device *pwm,
enum pwm_polarity polarity)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
u32 val;
int ret;
val = atmel_pwm_ch_readl(atmel_pwm, pwm->hwpwm, PWM_CMR);
if (polarity == PWM_POLARITY_NORMAL)
val &= ~PWM_CMR_CPOL;
else
val |= PWM_CMR_CPOL;
ret = clk_enable(atmel_pwm->clk);
if (ret) {
dev_err(chip->dev, "failed to enable PWM clock\n");
return ret;
}
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWM_CMR, val);
clk_disable(atmel_pwm->clk);
return 0;
}
static int atmel_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
int ret;
ret = clk_enable(atmel_pwm->clk);
if (ret) {
dev_err(chip->dev, "failed to enable PWM clock\n");
return ret;
}
atmel_pwm_writel(atmel_pwm, PWM_ENA, 1 << pwm->hwpwm);
return 0;
}
static void atmel_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
unsigned long timeout = jiffies + 2 * HZ;
mutex_lock(&atmel_pwm->isr_lock);
atmel_pwm->updated_pwms |= atmel_pwm_readl(atmel_pwm, PWM_ISR);
while (!(atmel_pwm->updated_pwms & (1 << pwm->hwpwm)) &&
time_before(jiffies, timeout)) {
usleep_range(10, 100);
atmel_pwm->updated_pwms |= atmel_pwm_readl(atmel_pwm, PWM_ISR);
}
mutex_unlock(&atmel_pwm->isr_lock);
atmel_pwm_writel(atmel_pwm, PWM_DIS, 1 << pwm->hwpwm);
timeout = jiffies + 2 * HZ;
while ((atmel_pwm_readl(atmel_pwm, PWM_SR) & (1 << pwm->hwpwm)) &&
time_before(jiffies, timeout))
usleep_range(10, 100);
clk_disable(atmel_pwm->clk);
}
static inline const struct atmel_pwm_data *
atmel_pwm_get_driver_data(struct platform_device *pdev)
{
const struct platform_device_id *id;
if (pdev->dev.of_node)
return of_device_get_match_data(&pdev->dev);
id = platform_get_device_id(pdev);
return (struct atmel_pwm_data *)id->driver_data;
}
static int atmel_pwm_probe(struct platform_device *pdev)
{
const struct atmel_pwm_data *data;
struct atmel_pwm_chip *atmel_pwm;
struct resource *res;
int ret;
data = atmel_pwm_get_driver_data(pdev);
if (!data)
return -ENODEV;
atmel_pwm = devm_kzalloc(&pdev->dev, sizeof(*atmel_pwm), GFP_KERNEL);
if (!atmel_pwm)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
atmel_pwm->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(atmel_pwm->base))
return PTR_ERR(atmel_pwm->base);
atmel_pwm->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(atmel_pwm->clk))
return PTR_ERR(atmel_pwm->clk);
ret = clk_prepare(atmel_pwm->clk);
if (ret) {
dev_err(&pdev->dev, "failed to prepare PWM clock\n");
return ret;
}
atmel_pwm->chip.dev = &pdev->dev;
atmel_pwm->chip.ops = &atmel_pwm_ops;
if (pdev->dev.of_node) {
atmel_pwm->chip.of_xlate = of_pwm_xlate_with_flags;
atmel_pwm->chip.of_pwm_n_cells = 3;
}
atmel_pwm->chip.base = -1;
atmel_pwm->chip.npwm = 4;
atmel_pwm->config = data->config;
atmel_pwm->updated_pwms = 0;
mutex_init(&atmel_pwm->isr_lock);
ret = pwmchip_add(&atmel_pwm->chip);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add PWM chip %d\n", ret);
goto unprepare_clk;
}
platform_set_drvdata(pdev, atmel_pwm);
return ret;
unprepare_clk:
clk_unprepare(atmel_pwm->clk);
return ret;
}
static int atmel_pwm_remove(struct platform_device *pdev)
{
struct atmel_pwm_chip *atmel_pwm = platform_get_drvdata(pdev);
clk_unprepare(atmel_pwm->clk);
mutex_destroy(&atmel_pwm->isr_lock);
return pwmchip_remove(&atmel_pwm->chip);
}
