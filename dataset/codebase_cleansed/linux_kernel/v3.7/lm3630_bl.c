static int __devinit lm3630_chip_init(struct lm3630_chip_data *pchip)
{
int ret;
unsigned int reg_val;
struct lm3630_platform_data *pdata = pchip->pdata;
reg_val = ((pdata->pwm_active & 0x01) << 2) | (pdata->pwm_ctrl & 0x03);
ret = regmap_update_bits(pchip->regmap, REG_CONFIG, 0x07, reg_val);
if (ret < 0)
goto out;
reg_val = ((pdata->bank_b_ctrl & 0x01) << 1) |
(pdata->bank_a_ctrl & 0x07);
ret = regmap_update_bits(pchip->regmap, REG_CTRL, 0x07, reg_val);
if (ret < 0)
goto out;
ret = regmap_update_bits(pchip->regmap, REG_CTRL, 0x80, 0x00);
if (ret < 0)
goto out;
if (pdata->bank_a_ctrl != BANK_A_CTRL_DISABLE) {
ret = regmap_write(pchip->regmap,
REG_BRT_A, pdata->init_brt_led1);
if (ret < 0)
goto out;
}
if (pdata->bank_b_ctrl != BANK_B_CTRL_DISABLE) {
ret = regmap_write(pchip->regmap,
REG_BRT_B, pdata->init_brt_led2);
if (ret < 0)
goto out;
}
return ret;
out:
dev_err(pchip->dev, "i2c failed to access register\n");
return ret;
}
static void lm3630_delayed_func(struct work_struct *work)
{
int ret;
unsigned int reg_val;
struct lm3630_chip_data *pchip;
pchip = container_of(work, struct lm3630_chip_data, work.work);
ret = regmap_read(pchip->regmap, REG_INT_STATUS, &reg_val);
if (ret < 0) {
dev_err(pchip->dev,
"i2c failed to access REG_INT_STATUS Register\n");
return;
}
dev_info(pchip->dev, "REG_INT_STATUS Register is 0x%x\n", reg_val);
}
static irqreturn_t lm3630_isr_func(int irq, void *chip)
{
int ret;
struct lm3630_chip_data *pchip = chip;
unsigned long delay = msecs_to_jiffies(INT_DEBOUNCE_MSEC);
queue_delayed_work(pchip->irqthread, &pchip->work, delay);
ret = regmap_update_bits(pchip->regmap, REG_CTRL, 0x80, 0x00);
if (ret < 0)
goto out;
return IRQ_HANDLED;
out:
dev_err(pchip->dev, "i2c failed to access register\n");
return IRQ_HANDLED;
}
static int lm3630_intr_config(struct lm3630_chip_data *pchip)
{
INIT_DELAYED_WORK(&pchip->work, lm3630_delayed_func);
pchip->irqthread = create_singlethread_workqueue("lm3630-irqthd");
if (!pchip->irqthread) {
dev_err(pchip->dev, "create irq thread fail...\n");
return -1;
}
if (request_threaded_irq
(pchip->irq, NULL, lm3630_isr_func,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT, "lm3630_irq", pchip)) {
dev_err(pchip->dev, "request threaded irq fail..\n");
return -1;
}
return 0;
}
static bool
set_intensity(struct backlight_device *bl, struct lm3630_chip_data *pchip)
{
if (!pchip->pdata->pwm_set_intensity)
return false;
pchip->pdata->pwm_set_intensity(bl->props.brightness - 1,
pchip->pdata->pwm_period);
return true;
}
static int lm3630_bank_a_update_status(struct backlight_device *bl)
{
int ret;
struct lm3630_chip_data *pchip = bl_get_data(bl);
enum lm3630_pwm_ctrl pwm_ctrl = pchip->pdata->pwm_ctrl;
if (!bl->props.brightness) {
ret = regmap_update_bits(pchip->regmap, REG_CTRL, 0x04, 0x00);
if (ret < 0)
goto out;
return bl->props.brightness;
}
if (pwm_ctrl == PWM_CTRL_BANK_A || pwm_ctrl == PWM_CTRL_BANK_ALL) {
if (!set_intensity(bl, pchip))
dev_err(pchip->dev, "No pwm control func. in plat-data\n");
} else {
ret = regmap_update_bits(pchip->regmap, REG_CTRL, 0x80, 0x00);
if (ret < 0)
goto out;
mdelay(1);
ret = regmap_write(pchip->regmap,
REG_BRT_A, bl->props.brightness - 1);
if (ret < 0)
goto out;
}
return bl->props.brightness;
out:
dev_err(pchip->dev, "i2c failed to access REG_CTRL\n");
return bl->props.brightness;
}
static int lm3630_bank_a_get_brightness(struct backlight_device *bl)
{
unsigned int reg_val;
int brightness, ret;
struct lm3630_chip_data *pchip = bl_get_data(bl);
enum lm3630_pwm_ctrl pwm_ctrl = pchip->pdata->pwm_ctrl;
if (pwm_ctrl == PWM_CTRL_BANK_A || pwm_ctrl == PWM_CTRL_BANK_ALL) {
ret = regmap_read(pchip->regmap, REG_PWM_OUTHIGH, &reg_val);
if (ret < 0)
goto out;
brightness = reg_val & 0x01;
ret = regmap_read(pchip->regmap, REG_PWM_OUTLOW, &reg_val);
if (ret < 0)
goto out;
brightness = ((brightness << 8) | reg_val) + 1;
} else {
ret = regmap_update_bits(pchip->regmap, REG_CTRL, 0x80, 0x00);
if (ret < 0)
goto out;
mdelay(1);
ret = regmap_read(pchip->regmap, REG_BRT_A, &reg_val);
if (ret < 0)
goto out;
brightness = reg_val + 1;
}
bl->props.brightness = brightness;
return bl->props.brightness;
out:
dev_err(pchip->dev, "i2c failed to access register\n");
return 0;
}
static int lm3630_bank_b_update_status(struct backlight_device *bl)
{
int ret;
struct lm3630_chip_data *pchip = bl_get_data(bl);
enum lm3630_pwm_ctrl pwm_ctrl = pchip->pdata->pwm_ctrl;
if (pwm_ctrl == PWM_CTRL_BANK_B || pwm_ctrl == PWM_CTRL_BANK_ALL) {
if (!set_intensity(bl, pchip))
dev_err(pchip->dev,
"no pwm control func. in plat-data\n");
} else {
ret = regmap_update_bits(pchip->regmap, REG_CTRL, 0x80, 0x00);
if (ret < 0)
goto out;
mdelay(1);
ret = regmap_write(pchip->regmap,
REG_BRT_B, bl->props.brightness - 1);
}
return bl->props.brightness;
out:
dev_err(pchip->dev, "i2c failed to access register\n");
return bl->props.brightness;
}
static int lm3630_bank_b_get_brightness(struct backlight_device *bl)
{
unsigned int reg_val;
int brightness, ret;
struct lm3630_chip_data *pchip = bl_get_data(bl);
enum lm3630_pwm_ctrl pwm_ctrl = pchip->pdata->pwm_ctrl;
if (pwm_ctrl == PWM_CTRL_BANK_B || pwm_ctrl == PWM_CTRL_BANK_ALL) {
ret = regmap_read(pchip->regmap, REG_PWM_OUTHIGH, &reg_val);
if (ret < 0)
goto out;
brightness = reg_val & 0x01;
ret = regmap_read(pchip->regmap, REG_PWM_OUTLOW, &reg_val);
if (ret < 0)
goto out;
brightness = ((brightness << 8) | reg_val) + 1;
} else {
ret = regmap_update_bits(pchip->regmap, REG_CTRL, 0x80, 0x00);
if (ret < 0)
goto out;
mdelay(1);
ret = regmap_read(pchip->regmap, REG_BRT_B, &reg_val);
if (ret < 0)
goto out;
brightness = reg_val + 1;
}
bl->props.brightness = brightness;
return bl->props.brightness;
out:
dev_err(pchip->dev, "i2c failed to access register\n");
return bl->props.brightness;
}
static int lm3630_backlight_register(struct lm3630_chip_data *pchip,
enum lm3630_leds ledno)
{
const char *name = bled_name[ledno];
struct backlight_properties props;
struct lm3630_platform_data *pdata = pchip->pdata;
props.type = BACKLIGHT_RAW;
switch (ledno) {
case BLED_1:
case BLED_ALL:
props.brightness = pdata->init_brt_led1;
props.max_brightness = pdata->max_brt_led1;
pchip->bled1 =
backlight_device_register(name, pchip->dev, pchip,
&lm3630_bank_a_ops, &props);
if (IS_ERR(pchip->bled1))
return -EIO;
break;
case BLED_2:
props.brightness = pdata->init_brt_led2;
props.max_brightness = pdata->max_brt_led2;
pchip->bled2 =
backlight_device_register(name, pchip->dev, pchip,
&lm3630_bank_b_ops, &props);
if (IS_ERR(pchip->bled2))
return -EIO;
break;
}
return 0;
}
static void lm3630_backlight_unregister(struct lm3630_chip_data *pchip)
{
if (pchip->bled1)
backlight_device_unregister(pchip->bled1);
if (pchip->bled2)
backlight_device_unregister(pchip->bled2);
}
static int __devinit lm3630_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lm3630_platform_data *pdata = client->dev.platform_data;
struct lm3630_chip_data *pchip;
int ret;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "fail : i2c functionality check...\n");
return -EOPNOTSUPP;
}
if (pdata == NULL) {
dev_err(&client->dev, "fail : no platform data.\n");
return -ENODATA;
}
pchip = devm_kzalloc(&client->dev, sizeof(struct lm3630_chip_data),
GFP_KERNEL);
if (!pchip)
return -ENOMEM;
pchip->pdata = pdata;
pchip->dev = &client->dev;
pchip->regmap = devm_regmap_init_i2c(client, &lm3630_regmap);
if (IS_ERR(pchip->regmap)) {
ret = PTR_ERR(pchip->regmap);
dev_err(&client->dev, "fail : allocate register map: %d\n",
ret);
return ret;
}
i2c_set_clientdata(client, pchip);
ret = lm3630_chip_init(pchip);
if (ret < 0) {
dev_err(&client->dev, "fail : init chip\n");
goto err_chip_init;
}
switch (pdata->bank_a_ctrl) {
case BANK_A_CTRL_ALL:
ret = lm3630_backlight_register(pchip, BLED_ALL);
pdata->bank_b_ctrl = BANK_B_CTRL_DISABLE;
break;
case BANK_A_CTRL_LED1:
ret = lm3630_backlight_register(pchip, BLED_1);
break;
case BANK_A_CTRL_LED2:
ret = lm3630_backlight_register(pchip, BLED_2);
pdata->bank_b_ctrl = BANK_B_CTRL_DISABLE;
break;
default:
break;
}
if (ret < 0)
goto err_bl_reg;
if (pdata->bank_b_ctrl && pchip->bled2 == NULL) {
ret = lm3630_backlight_register(pchip, BLED_2);
if (ret < 0)
goto err_bl_reg;
}
pchip->irq = client->irq;
if (pchip->irq)
lm3630_intr_config(pchip);
dev_info(&client->dev, "LM3630 backlight register OK.\n");
return 0;
err_bl_reg:
dev_err(&client->dev, "fail : backlight register.\n");
lm3630_backlight_unregister(pchip);
err_chip_init:
return ret;
}
static int __devexit lm3630_remove(struct i2c_client *client)
{
int ret;
struct lm3630_chip_data *pchip = i2c_get_clientdata(client);
ret = regmap_write(pchip->regmap, REG_BRT_A, 0);
if (ret < 0)
dev_err(pchip->dev, "i2c failed to access register\n");
ret = regmap_write(pchip->regmap, REG_BRT_B, 0);
if (ret < 0)
dev_err(pchip->dev, "i2c failed to access register\n");
lm3630_backlight_unregister(pchip);
if (pchip->irq) {
free_irq(pchip->irq, pchip);
flush_workqueue(pchip->irqthread);
destroy_workqueue(pchip->irqthread);
}
return 0;
}
