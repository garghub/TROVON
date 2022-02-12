static inline struct pca9685 *to_pca(struct pwm_chip *chip)
{
return container_of(chip, struct pca9685, chip);
}
static int pca9685_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
int duty_ns, int period_ns)
{
struct pca9685 *pca = to_pca(chip);
unsigned long long duty;
unsigned int reg;
int prescale;
if (period_ns != pca->period_ns) {
prescale = DIV_ROUND_CLOSEST(PCA9685_OSC_CLOCK_MHZ * period_ns,
PCA9685_COUNTER_RANGE * 1000) - 1;
if (prescale >= PCA9685_PRESCALE_MIN &&
prescale <= PCA9685_PRESCALE_MAX) {
regmap_update_bits(pca->regmap, PCA9685_MODE1,
MODE1_SLEEP, MODE1_SLEEP);
regmap_write(pca->regmap, PCA9685_PRESCALE, prescale);
regmap_update_bits(pca->regmap, PCA9685_MODE1,
MODE1_SLEEP, 0x0);
udelay(500);
pca->period_ns = period_ns;
if (duty_ns == pca->duty_ns) {
regmap_update_bits(pca->regmap, PCA9685_MODE1,
MODE1_RESTART, 0x1);
return 0;
}
} else {
dev_err(chip->dev,
"prescaler not set: period out of bounds!\n");
return -EINVAL;
}
}
pca->duty_ns = duty_ns;
if (duty_ns < 1) {
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_OFF_H;
else
reg = LED_N_OFF_H(pwm->hwpwm);
regmap_write(pca->regmap, reg, LED_FULL);
return 0;
}
if (duty_ns == period_ns) {
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_OFF_L;
else
reg = LED_N_OFF_L(pwm->hwpwm);
regmap_write(pca->regmap, reg, 0x0);
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_OFF_H;
else
reg = LED_N_OFF_H(pwm->hwpwm);
regmap_write(pca->regmap, reg, 0x0);
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_ON_H;
else
reg = LED_N_ON_H(pwm->hwpwm);
regmap_write(pca->regmap, reg, LED_FULL);
return 0;
}
duty = PCA9685_COUNTER_RANGE * (unsigned long long)duty_ns;
duty = DIV_ROUND_UP_ULL(duty, period_ns);
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_OFF_L;
else
reg = LED_N_OFF_L(pwm->hwpwm);
regmap_write(pca->regmap, reg, (int)duty & 0xff);
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_OFF_H;
else
reg = LED_N_OFF_H(pwm->hwpwm);
regmap_write(pca->regmap, reg, ((int)duty >> 8) & 0xf);
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_ON_H;
else
reg = LED_N_ON_H(pwm->hwpwm);
regmap_write(pca->regmap, reg, 0);
return 0;
}
static int pca9685_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pca9685 *pca = to_pca(chip);
unsigned int reg;
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_ON_L;
else
reg = LED_N_ON_L(pwm->hwpwm);
regmap_write(pca->regmap, reg, 0);
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_ON_H;
else
reg = LED_N_ON_H(pwm->hwpwm);
regmap_write(pca->regmap, reg, 0);
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_OFF_H;
else
reg = LED_N_OFF_H(pwm->hwpwm);
regmap_update_bits(pca->regmap, reg, LED_FULL, 0x0);
return 0;
}
static void pca9685_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pca9685 *pca = to_pca(chip);
unsigned int reg;
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_OFF_H;
else
reg = LED_N_OFF_H(pwm->hwpwm);
regmap_write(pca->regmap, reg, LED_FULL);
if (pwm->hwpwm >= PCA9685_MAXCHAN)
reg = PCA9685_ALL_LED_OFF_L;
else
reg = LED_N_OFF_L(pwm->hwpwm);
regmap_write(pca->regmap, reg, 0x0);
}
static int pca9685_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pca9685 *pca = to_pca(chip);
if (pca->active_cnt++ == 0)
return regmap_update_bits(pca->regmap, PCA9685_MODE1,
MODE1_SLEEP, 0x0);
return 0;
}
static void pca9685_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
struct pca9685 *pca = to_pca(chip);
if (--pca->active_cnt == 0)
regmap_update_bits(pca->regmap, PCA9685_MODE1, MODE1_SLEEP,
MODE1_SLEEP);
}
static int pca9685_pwm_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device_node *np = client->dev.of_node;
struct pca9685 *pca;
int ret;
int mode2;
pca = devm_kzalloc(&client->dev, sizeof(*pca), GFP_KERNEL);
if (!pca)
return -ENOMEM;
pca->regmap = devm_regmap_init_i2c(client, &pca9685_regmap_i2c_config);
if (IS_ERR(pca->regmap)) {
ret = PTR_ERR(pca->regmap);
dev_err(&client->dev, "Failed to initialize register map: %d\n",
ret);
return ret;
}
pca->duty_ns = 0;
pca->period_ns = PCA9685_DEFAULT_PERIOD;
i2c_set_clientdata(client, pca);
regmap_read(pca->regmap, PCA9685_MODE2, &mode2);
if (of_property_read_bool(np, "invert"))
mode2 |= MODE2_INVRT;
else
mode2 &= ~MODE2_INVRT;
if (of_property_read_bool(np, "open-drain"))
mode2 &= ~MODE2_OUTDRV;
else
mode2 |= MODE2_OUTDRV;
regmap_write(pca->regmap, PCA9685_MODE2, mode2);
regmap_write(pca->regmap, PCA9685_ALL_LED_OFF_L, 0);
regmap_write(pca->regmap, PCA9685_ALL_LED_OFF_H, 0);
pca->chip.ops = &pca9685_pwm_ops;
pca->chip.npwm = PCA9685_MAXCHAN + 1;
pca->chip.dev = &client->dev;
pca->chip.base = -1;
pca->chip.can_sleep = true;
return pwmchip_add(&pca->chip);
}
static int pca9685_pwm_remove(struct i2c_client *client)
{
struct pca9685 *pca = i2c_get_clientdata(client);
regmap_update_bits(pca->regmap, PCA9685_MODE1, MODE1_SLEEP,
MODE1_SLEEP);
return pwmchip_remove(&pca->chip);
}
