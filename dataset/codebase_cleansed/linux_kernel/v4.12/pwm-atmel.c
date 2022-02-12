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
static int atmel_pwm_calculate_cprd_and_pres(struct pwm_chip *chip,
const struct pwm_state *state,
unsigned long *cprd, u32 *pres)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
unsigned long long cycles = state->period;
cycles *= clk_get_rate(atmel_pwm->clk);
do_div(cycles, NSEC_PER_SEC);
for (*pres = 0; cycles > PWM_MAX_PRD; cycles >>= 1)
(*pres)++;
if (*pres > PRD_MAX_PRES) {
dev_err(chip->dev, "pres exceeds the maximum value\n");
return -EINVAL;
}
*cprd = cycles;
return 0;
}
static void atmel_pwm_calculate_cdty(const struct pwm_state *state,
unsigned long cprd, unsigned long *cdty)
{
unsigned long long cycles = state->duty_cycle;
cycles *= cprd;
do_div(cycles, state->period);
*cdty = cprd - cycles;
}
static void atmel_pwm_update_cdty(struct pwm_chip *chip, struct pwm_device *pwm,
unsigned long cdty)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
u32 val;
if (atmel_pwm->regs->duty_upd ==
atmel_pwm->regs->period_upd) {
val = atmel_pwm_ch_readl(atmel_pwm, pwm->hwpwm, PWM_CMR);
val &= ~PWM_CMR_UPD_CDTY;
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWM_CMR, val);
}
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm,
atmel_pwm->regs->duty_upd, cdty);
}
static void atmel_pwm_set_cprd_cdty(struct pwm_chip *chip,
struct pwm_device *pwm,
unsigned long cprd, unsigned long cdty)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm,
atmel_pwm->regs->duty, cdty);
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm,
atmel_pwm->regs->period, cprd);
}
static void atmel_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm,
bool disable_clk)
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
if (disable_clk)
clk_disable(atmel_pwm->clk);
}
static int atmel_pwm_apply(struct pwm_chip *chip, struct pwm_device *pwm,
struct pwm_state *state)
{
struct atmel_pwm_chip *atmel_pwm = to_atmel_pwm_chip(chip);
struct pwm_state cstate;
unsigned long cprd, cdty;
u32 pres, val;
int ret;
pwm_get_state(pwm, &cstate);
if (state->enabled) {
if (cstate.enabled &&
cstate.polarity == state->polarity &&
cstate.period == state->period) {
cprd = atmel_pwm_ch_readl(atmel_pwm, pwm->hwpwm,
atmel_pwm->regs->period);
atmel_pwm_calculate_cdty(state, cprd, &cdty);
atmel_pwm_update_cdty(chip, pwm, cdty);
return 0;
}
ret = atmel_pwm_calculate_cprd_and_pres(chip, state, &cprd,
&pres);
if (ret) {
dev_err(chip->dev,
"failed to calculate cprd and prescaler\n");
return ret;
}
atmel_pwm_calculate_cdty(state, cprd, &cdty);
if (cstate.enabled) {
atmel_pwm_disable(chip, pwm, false);
} else {
ret = clk_enable(atmel_pwm->clk);
if (ret) {
dev_err(chip->dev, "failed to enable clock\n");
return ret;
}
}
val = atmel_pwm_ch_readl(atmel_pwm, pwm->hwpwm, PWM_CMR);
val = (val & ~PWM_CMR_CPRE_MSK) | (pres & PWM_CMR_CPRE_MSK);
if (state->polarity == PWM_POLARITY_NORMAL)
val &= ~PWM_CMR_CPOL;
else
val |= PWM_CMR_CPOL;
atmel_pwm_ch_writel(atmel_pwm, pwm->hwpwm, PWM_CMR, val);
atmel_pwm_set_cprd_cdty(chip, pwm, cprd, cdty);
mutex_lock(&atmel_pwm->isr_lock);
atmel_pwm->updated_pwms |= atmel_pwm_readl(atmel_pwm, PWM_ISR);
atmel_pwm->updated_pwms &= ~(1 << pwm->hwpwm);
mutex_unlock(&atmel_pwm->isr_lock);
atmel_pwm_writel(atmel_pwm, PWM_ENA, 1 << pwm->hwpwm);
} else if (cstate.enabled) {
atmel_pwm_disable(chip, pwm, true);
}
return 0;
}
static inline const struct atmel_pwm_registers *
atmel_pwm_get_driver_data(struct platform_device *pdev)
{
const struct platform_device_id *id;
if (pdev->dev.of_node)
return of_device_get_match_data(&pdev->dev);
id = platform_get_device_id(pdev);
return (struct atmel_pwm_registers *)id->driver_data;
}
static int atmel_pwm_probe(struct platform_device *pdev)
{
const struct atmel_pwm_registers *regs;
struct atmel_pwm_chip *atmel_pwm;
struct resource *res;
int ret;
regs = atmel_pwm_get_driver_data(pdev);
if (!regs)
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
atmel_pwm->regs = regs;
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
