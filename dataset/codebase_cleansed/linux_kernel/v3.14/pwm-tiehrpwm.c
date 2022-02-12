static inline struct ehrpwm_pwm_chip *to_ehrpwm_pwm_chip(struct pwm_chip *chip)
{
return container_of(chip, struct ehrpwm_pwm_chip, chip);
}
static u16 ehrpwm_read(void __iomem *base, int offset)
{
return readw(base + offset);
}
static void ehrpwm_write(void __iomem *base, int offset, unsigned int val)
{
writew(val & 0xFFFF, base + offset);
}
static void ehrpwm_modify(void __iomem *base, int offset,
unsigned short mask, unsigned short val)
{
unsigned short regval;
regval = readw(base + offset);
regval &= ~mask;
regval |= val & mask;
writew(regval, base + offset);
}
static int set_prescale_div(unsigned long rqst_prescaler,
unsigned short *prescale_div, unsigned short *tb_clk_div)
{
unsigned int clkdiv, hspclkdiv;
for (clkdiv = 0; clkdiv <= CLKDIV_MAX; clkdiv++) {
for (hspclkdiv = 0; hspclkdiv <= HSPCLKDIV_MAX; hspclkdiv++) {
*prescale_div = (1 << clkdiv) *
(hspclkdiv ? (hspclkdiv * 2) : 1);
if (*prescale_div > rqst_prescaler) {
*tb_clk_div = (clkdiv << TBCTL_CLKDIV_SHIFT) |
(hspclkdiv << TBCTL_HSPCLKDIV_SHIFT);
return 0;
}
}
}
return 1;
}
static void configure_polarity(struct ehrpwm_pwm_chip *pc, int chan)
{
int aqctl_reg;
unsigned short aqctl_val, aqctl_mask;
if (chan == 1) {
aqctl_reg = AQCTLB;
aqctl_mask = AQCTL_CBU_MASK;
if (pc->polarity[chan] == PWM_POLARITY_INVERSED)
aqctl_val = AQCTL_CHANB_POLINVERSED;
else
aqctl_val = AQCTL_CHANB_POLNORMAL;
} else {
aqctl_reg = AQCTLA;
aqctl_mask = AQCTL_CAU_MASK;
if (pc->polarity[chan] == PWM_POLARITY_INVERSED)
aqctl_val = AQCTL_CHANA_POLINVERSED;
else
aqctl_val = AQCTL_CHANA_POLNORMAL;
}
aqctl_mask |= AQCTL_PRD_MASK | AQCTL_ZRO_MASK;
ehrpwm_modify(pc->mmio_base, aqctl_reg, aqctl_mask, aqctl_val);
}
static int ehrpwm_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct ehrpwm_pwm_chip *pc = to_ehrpwm_pwm_chip(chip);
unsigned long long c;
unsigned long period_cycles, duty_cycles;
unsigned short ps_divval, tb_divval;
int i, cmp_reg;
if (period_ns > NSEC_PER_SEC)
return -ERANGE;
c = pc->clk_rate;
c = c * period_ns;
do_div(c, NSEC_PER_SEC);
period_cycles = (unsigned long)c;
if (period_cycles < 1) {
period_cycles = 1;
duty_cycles = 1;
} else {
c = pc->clk_rate;
c = c * duty_ns;
do_div(c, NSEC_PER_SEC);
duty_cycles = (unsigned long)c;
}
for (i = 0; i < NUM_PWM_CHANNEL; i++) {
if (pc->period_cycles[i] &&
(pc->period_cycles[i] != period_cycles)) {
if (i == pwm->hwpwm)
continue;
dev_err(chip->dev, "Period value conflicts with channel %d\n",
i);
return -EINVAL;
}
}
pc->period_cycles[pwm->hwpwm] = period_cycles;
if (set_prescale_div(period_cycles/PERIOD_MAX, &ps_divval,
&tb_divval)) {
dev_err(chip->dev, "Unsupported values\n");
return -EINVAL;
}
pm_runtime_get_sync(chip->dev);
ehrpwm_modify(pc->mmio_base, TBCTL, TBCTL_CLKDIV_MASK, tb_divval);
period_cycles = period_cycles / ps_divval;
duty_cycles = duty_cycles / ps_divval;
ehrpwm_modify(pc->mmio_base, TBCTL, TBCTL_PRDLD_MASK, TBCTL_PRDLD_SHDW);
ehrpwm_write(pc->mmio_base, TBPRD, period_cycles);
ehrpwm_modify(pc->mmio_base, TBCTL, TBCTL_CTRMODE_MASK,
TBCTL_CTRMODE_UP);
if (pwm->hwpwm == 1)
cmp_reg = CMPB;
else
cmp_reg = CMPA;
ehrpwm_write(pc->mmio_base, cmp_reg, duty_cycles);
pm_runtime_put_sync(chip->dev);
return 0;
}
static int ehrpwm_pwm_set_polarity(struct pwm_chip *chip,
struct pwm_device *pwm, enum pwm_polarity polarity)
{
struct ehrpwm_pwm_chip *pc = to_ehrpwm_pwm_chip(chip);
pc->polarity[pwm->hwpwm] = polarity;
return 0;
}
static int ehrpwm_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct ehrpwm_pwm_chip *pc = to_ehrpwm_pwm_chip(chip);
unsigned short aqcsfrc_val, aqcsfrc_mask;
int ret;
pm_runtime_get_sync(chip->dev);
if (pwm->hwpwm) {
aqcsfrc_val = AQCSFRC_CSFB_FRCDIS;
aqcsfrc_mask = AQCSFRC_CSFB_MASK;
} else {
aqcsfrc_val = AQCSFRC_CSFA_FRCDIS;
aqcsfrc_mask = AQCSFRC_CSFA_MASK;
}
ehrpwm_modify(pc->mmio_base, AQSFRC, AQSFRC_RLDCSF_MASK,
AQSFRC_RLDCSF_ZRO);
ehrpwm_modify(pc->mmio_base, AQCSFRC, aqcsfrc_mask, aqcsfrc_val);
configure_polarity(pc, pwm->hwpwm);
ret = clk_enable(pc->tbclk);
if (ret) {
dev_err(chip->dev, "Failed to enable TBCLK for %s\n",
dev_name(pc->chip.dev));
return ret;
}
ehrpwm_modify(pc->mmio_base, TBCTL, TBCTL_RUN_MASK, TBCTL_FREE_RUN);
return 0;
}
static void ehrpwm_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct ehrpwm_pwm_chip *pc = to_ehrpwm_pwm_chip(chip);
unsigned short aqcsfrc_val, aqcsfrc_mask;
if (pwm->hwpwm) {
aqcsfrc_val = AQCSFRC_CSFB_FRCLOW;
aqcsfrc_mask = AQCSFRC_CSFB_MASK;
} else {
aqcsfrc_val = AQCSFRC_CSFA_FRCLOW;
aqcsfrc_mask = AQCSFRC_CSFA_MASK;
}
ehrpwm_modify(pc->mmio_base, AQSFRC, AQSFRC_RLDCSF_MASK,
AQSFRC_RLDCSF_IMDT);
ehrpwm_modify(pc->mmio_base, AQCSFRC, aqcsfrc_mask, aqcsfrc_val);
clk_disable(pc->tbclk);
ehrpwm_modify(pc->mmio_base, TBCTL, TBCTL_RUN_MASK, TBCTL_STOP_NEXT);
pm_runtime_put_sync(chip->dev);
}
static void ehrpwm_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct ehrpwm_pwm_chip *pc = to_ehrpwm_pwm_chip(chip);
if (test_bit(PWMF_ENABLED, &pwm->flags)) {
dev_warn(chip->dev, "Removing PWM device without disabling\n");
pm_runtime_put_sync(chip->dev);
}
pc->period_cycles[pwm->hwpwm] = 0;
}
static int ehrpwm_pwm_probe(struct platform_device *pdev)
{
int ret;
struct resource *r;
struct clk *clk;
struct ehrpwm_pwm_chip *pc;
u16 status;
pc = devm_kzalloc(&pdev->dev, sizeof(*pc), GFP_KERNEL);
if (!pc) {
dev_err(&pdev->dev, "failed to allocate memory\n");
return -ENOMEM;
}
clk = devm_clk_get(&pdev->dev, "fck");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "failed to get clock\n");
return PTR_ERR(clk);
}
pc->clk_rate = clk_get_rate(clk);
if (!pc->clk_rate) {
dev_err(&pdev->dev, "failed to get clock rate\n");
return -EINVAL;
}
pc->chip.dev = &pdev->dev;
pc->chip.ops = &ehrpwm_pwm_ops;
pc->chip.of_xlate = of_pwm_xlate_with_flags;
pc->chip.of_pwm_n_cells = 3;
pc->chip.base = -1;
pc->chip.npwm = NUM_PWM_CHANNEL;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pc->mmio_base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(pc->mmio_base))
return PTR_ERR(pc->mmio_base);
pc->tbclk = devm_clk_get(&pdev->dev, "tbclk");
if (IS_ERR(pc->tbclk)) {
dev_err(&pdev->dev, "Failed to get tbclk\n");
return PTR_ERR(pc->tbclk);
}
ret = clk_prepare(pc->tbclk);
if (ret < 0) {
dev_err(&pdev->dev, "clk_prepare() failed: %d\n", ret);
return ret;
}
ret = pwmchip_add(&pc->chip);
if (ret < 0) {
dev_err(&pdev->dev, "pwmchip_add() failed: %d\n", ret);
return ret;
}
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
status = pwmss_submodule_state_change(pdev->dev.parent,
PWMSS_EPWMCLK_EN);
if (!(status & PWMSS_EPWMCLK_EN_ACK)) {
dev_err(&pdev->dev, "PWMSS config space clock enable failed\n");
ret = -EINVAL;
goto pwmss_clk_failure;
}
pm_runtime_put_sync(&pdev->dev);
platform_set_drvdata(pdev, pc);
return 0;
pwmss_clk_failure:
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
pwmchip_remove(&pc->chip);
clk_unprepare(pc->tbclk);
return ret;
}
static int ehrpwm_pwm_remove(struct platform_device *pdev)
{
struct ehrpwm_pwm_chip *pc = platform_get_drvdata(pdev);
clk_unprepare(pc->tbclk);
pm_runtime_get_sync(&pdev->dev);
pwmss_submodule_state_change(pdev->dev.parent, PWMSS_EPWMCLK_STOP_REQ);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return pwmchip_remove(&pc->chip);
}
static void ehrpwm_pwm_save_context(struct ehrpwm_pwm_chip *pc)
{
pm_runtime_get_sync(pc->chip.dev);
pc->ctx.tbctl = ehrpwm_read(pc->mmio_base, TBCTL);
pc->ctx.tbprd = ehrpwm_read(pc->mmio_base, TBPRD);
pc->ctx.cmpa = ehrpwm_read(pc->mmio_base, CMPA);
pc->ctx.cmpb = ehrpwm_read(pc->mmio_base, CMPB);
pc->ctx.aqctla = ehrpwm_read(pc->mmio_base, AQCTLA);
pc->ctx.aqctlb = ehrpwm_read(pc->mmio_base, AQCTLB);
pc->ctx.aqsfrc = ehrpwm_read(pc->mmio_base, AQSFRC);
pc->ctx.aqcsfrc = ehrpwm_read(pc->mmio_base, AQCSFRC);
pm_runtime_put_sync(pc->chip.dev);
}
static void ehrpwm_pwm_restore_context(struct ehrpwm_pwm_chip *pc)
{
ehrpwm_write(pc->mmio_base, TBPRD, pc->ctx.tbprd);
ehrpwm_write(pc->mmio_base, CMPA, pc->ctx.cmpa);
ehrpwm_write(pc->mmio_base, CMPB, pc->ctx.cmpb);
ehrpwm_write(pc->mmio_base, AQCTLA, pc->ctx.aqctla);
ehrpwm_write(pc->mmio_base, AQCTLB, pc->ctx.aqctlb);
ehrpwm_write(pc->mmio_base, AQSFRC, pc->ctx.aqsfrc);
ehrpwm_write(pc->mmio_base, AQCSFRC, pc->ctx.aqcsfrc);
ehrpwm_write(pc->mmio_base, TBCTL, pc->ctx.tbctl);
}
static int ehrpwm_pwm_suspend(struct device *dev)
{
struct ehrpwm_pwm_chip *pc = dev_get_drvdata(dev);
int i;
ehrpwm_pwm_save_context(pc);
for (i = 0; i < pc->chip.npwm; i++) {
struct pwm_device *pwm = &pc->chip.pwms[i];
if (!test_bit(PWMF_ENABLED, &pwm->flags))
continue;
pm_runtime_put_sync(dev);
}
return 0;
}
static int ehrpwm_pwm_resume(struct device *dev)
{
struct ehrpwm_pwm_chip *pc = dev_get_drvdata(dev);
int i;
for (i = 0; i < pc->chip.npwm; i++) {
struct pwm_device *pwm = &pc->chip.pwms[i];
if (!test_bit(PWMF_ENABLED, &pwm->flags))
continue;
pm_runtime_get_sync(dev);
}
ehrpwm_pwm_restore_context(pc);
return 0;
}
