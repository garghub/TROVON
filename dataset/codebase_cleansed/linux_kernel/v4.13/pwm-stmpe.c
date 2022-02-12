static inline struct stmpe_pwm *to_stmpe_pwm(struct pwm_chip *chip)
{
return container_of(chip, struct stmpe_pwm, chip);
}
static int stmpe_24xx_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct stmpe_pwm *stmpe_pwm = to_stmpe_pwm(chip);
u8 value;
int ret;
ret = stmpe_reg_read(stmpe_pwm->stmpe, STMPE24XX_PWMCS);
if (ret < 0) {
dev_err(chip->dev, "error reading PWM#%u control\n",
pwm->hwpwm);
return ret;
}
value = ret | BIT(pwm->hwpwm);
ret = stmpe_reg_write(stmpe_pwm->stmpe, STMPE24XX_PWMCS, value);
if (ret) {
dev_err(chip->dev, "error writing PWM#%u control\n",
pwm->hwpwm);
return ret;
}
return 0;
}
static void stmpe_24xx_pwm_disable(struct pwm_chip *chip,
struct pwm_device *pwm)
{
struct stmpe_pwm *stmpe_pwm = to_stmpe_pwm(chip);
u8 value;
int ret;
ret = stmpe_reg_read(stmpe_pwm->stmpe, STMPE24XX_PWMCS);
if (ret < 0) {
dev_err(chip->dev, "error reading PWM#%u control\n",
pwm->hwpwm);
return;
}
value = ret & ~BIT(pwm->hwpwm);
ret = stmpe_reg_write(stmpe_pwm->stmpe, STMPE24XX_PWMCS, value);
if (ret) {
dev_err(chip->dev, "error writing PWM#%u control\n",
pwm->hwpwm);
return;
}
}
static int stmpe_24xx_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct stmpe_pwm *stmpe_pwm = to_stmpe_pwm(chip);
unsigned int i, pin;
u16 program[3] = {
SMAX,
GTS,
GTS,
};
u8 offset;
int ret;
if (pwm_is_enabled(pwm)) {
stmpe_24xx_pwm_disable(chip, pwm);
} else {
pin = pwm->hwpwm;
if (stmpe_pwm->stmpe->partnum == STMPE2401 ||
stmpe_pwm->stmpe->partnum == STMPE2403)
pin += STMPE_PWM_24XX_PINBASE;
ret = stmpe_set_altfunc(stmpe_pwm->stmpe, BIT(pin),
STMPE_BLOCK_PWM);
if (ret) {
dev_err(chip->dev, "unable to connect PWM#%u to pin\n",
pwm->hwpwm);
return ret;
}
}
switch (pwm->hwpwm) {
case 0:
offset = STMPE24XX_PWMIC0;
break;
case 1:
offset = STMPE24XX_PWMIC1;
break;
case 2:
offset = STMPE24XX_PWMIC1;
break;
default:
return -ENODEV;
}
dev_dbg(chip->dev, "PWM#%u: config duty %d ns, period %d ns\n",
pwm->hwpwm, duty_ns, period_ns);
if (duty_ns == 0) {
if (stmpe_pwm->stmpe->partnum == STMPE2401)
program[0] = SMAX;
if (stmpe_pwm->stmpe->partnum == STMPE2403)
program[0] = LOAD | 0xff;
stmpe_pwm->last_duty = 0x00;
} else if (duty_ns == period_ns) {
if (stmpe_pwm->stmpe->partnum == STMPE2401)
program[0] = SMIN;
if (stmpe_pwm->stmpe->partnum == STMPE2403)
program[0] = LOAD | 0x00;
stmpe_pwm->last_duty = 0xff;
} else {
u8 value, last = stmpe_pwm->last_duty;
unsigned long duty;
duty = duty_ns * 256;
duty = DIV_ROUND_CLOSEST(duty, period_ns);
value = duty;
if (value == last) {
if (pwm_is_enabled(pwm))
stmpe_24xx_pwm_enable(chip, pwm);
return 0;
} else if (stmpe_pwm->stmpe->partnum == STMPE2403) {
program[0] = LOAD | value;
program[1] = 0x0000;
} else if (stmpe_pwm->stmpe->partnum == STMPE2401) {
u16 incdec = 0x0000;
if (last < value)
incdec = RAMPUP | (value - last);
else
incdec = RAMPDOWN | (last - value);
program[0] = PRESCALE_512 | STEPTIME_1 | incdec;
program[1] = BRANCH;
}
dev_dbg(chip->dev,
"PWM#%u: value = %02x, last_duty = %02x, program=%04x,%04x,%04x\n",
pwm->hwpwm, value, last, program[0], program[1],
program[2]);
stmpe_pwm->last_duty = value;
}
for (i = 0; i < ARRAY_SIZE(program); i++) {
u8 value;
value = (program[i] >> 8) & 0xff;
ret = stmpe_reg_write(stmpe_pwm->stmpe, offset, value);
if (ret) {
dev_err(chip->dev, "error writing register %02x: %d\n",
offset, ret);
return ret;
}
value = program[i] & 0xff;
ret = stmpe_reg_write(stmpe_pwm->stmpe, offset, value);
if (ret) {
dev_err(chip->dev, "error writing register %02x: %d\n",
offset, ret);
return ret;
}
}
if (pwm_is_enabled(pwm))
stmpe_24xx_pwm_enable(chip, pwm);
msleep(200);
dev_dbg(chip->dev, "programmed PWM#%u, %u bytes\n", pwm->hwpwm, i);
return 0;
}
static int __init stmpe_pwm_probe(struct platform_device *pdev)
{
struct stmpe *stmpe = dev_get_drvdata(pdev->dev.parent);
struct stmpe_pwm *pwm;
int ret;
pwm = devm_kzalloc(&pdev->dev, sizeof(*pwm), GFP_KERNEL);
if (!pwm)
return -ENOMEM;
pwm->stmpe = stmpe;
pwm->chip.dev = &pdev->dev;
pwm->chip.base = -1;
if (stmpe->partnum == STMPE2401 || stmpe->partnum == STMPE2403) {
pwm->chip.ops = &stmpe_24xx_pwm_ops;
pwm->chip.npwm = 3;
} else {
if (stmpe->partnum == STMPE1601)
dev_err(&pdev->dev, "STMPE1601 not yet supported\n");
else
dev_err(&pdev->dev, "Unknown STMPE PWM\n");
return -ENODEV;
}
ret = stmpe_enable(stmpe, STMPE_BLOCK_PWM);
if (ret)
return ret;
ret = pwmchip_add(&pwm->chip);
if (ret) {
stmpe_disable(stmpe, STMPE_BLOCK_PWM);
return ret;
}
platform_set_drvdata(pdev, pwm);
return 0;
}
