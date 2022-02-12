static int __devinit lm3556_chip_init(struct lm3556_chip_data *chip)
{
unsigned int reg_val;
int ret;
struct lm3556_platform_data *pdata = chip->pdata;
ret = regmap_read(chip->regmap, REG_CONF, &reg_val);
if (ret < 0) {
dev_err(chip->dev, "Failed to read REG_CONF Register\n");
goto out;
}
reg_val &= (~EX_PIN_CONTROL_MASK);
reg_val |= ((pdata->torch_pin_polarity & 0x01)
<< TORCH_PIN_POLARITY_SHIFT);
reg_val |= ((pdata->strobe_usuage & 0x01) << STROBE_USUAGE_SHIFT);
reg_val |= ((pdata->strobe_pin_polarity & 0x01)
<< STROBE_PIN_POLARITY_SHIFT);
reg_val |= ((pdata->tx_pin_polarity & 0x01) << TX_PIN_POLARITY_SHIFT);
reg_val |= ((pdata->indicator_mode & 0x01) << INDIC_MODE_SHIFT);
ret = regmap_write(chip->regmap, REG_CONF, reg_val);
if (ret < 0) {
dev_err(chip->dev, "Failed to write REG_CONF Regisgter\n");
goto out;
}
ret = regmap_read(chip->regmap, REG_ENABLE, &reg_val);
if (ret < 0) {
dev_err(chip->dev, "Failed to read REG_ENABLE Register\n");
goto out;
}
reg_val &= (~EX_PIN_ENABLE_MASK);
reg_val |= ((pdata->torch_pin_en & 0x01) << TORCH_PIN_EN_SHIFT);
reg_val |= ((pdata->strobe_pin_en & 0x01) << STROBE_PIN_EN_SHIFT);
reg_val |= ((pdata->tx_pin_en & 0x01) << TX_PIN_EN_SHIFT);
ret = regmap_write(chip->regmap, REG_ENABLE, reg_val);
if (ret < 0) {
dev_err(chip->dev, "Failed to write REG_ENABLE Regisgter\n");
goto out;
}
out:
return ret;
}
static int lm3556_control(struct lm3556_chip_data *chip,
u8 brightness, enum lm3556_mode opmode)
{
int ret;
struct lm3556_platform_data *pdata = chip->pdata;
ret = regmap_read(chip->regmap, REG_FLAG, &chip->last_flag);
if (ret < 0) {
dev_err(chip->dev, "Failed to read REG_FLAG Register\n");
goto out;
}
if (chip->last_flag)
dev_info(chip->dev, "Last FLAG is 0x%x\n", chip->last_flag);
if (!brightness)
opmode = MODES_STASNDBY;
switch (opmode) {
case MODES_TORCH:
ret = regmap_update_bits(chip->regmap, REG_I_CTRL,
TORCH_I_MASK << TORCH_I_SHIFT,
(brightness - 1) << TORCH_I_SHIFT);
if (pdata->torch_pin_en)
opmode |= (TORCH_PIN_EN_MASK << TORCH_PIN_EN_SHIFT);
break;
case MODES_FLASH:
ret = regmap_update_bits(chip->regmap, REG_I_CTRL,
FLASH_I_MASK << FLASH_I_SHIFT,
(brightness - 1) << FLASH_I_SHIFT);
break;
case MODES_INDIC:
ret = regmap_update_bits(chip->regmap, REG_I_CTRL,
TORCH_I_MASK << TORCH_I_SHIFT,
(brightness - 1) << TORCH_I_SHIFT);
break;
case MODES_STASNDBY:
if (pdata->torch_pin_en)
opmode |= (TORCH_PIN_EN_MASK << TORCH_PIN_EN_SHIFT);
break;
default:
return ret;
}
if (ret < 0) {
dev_err(chip->dev, "Failed to write REG_I_CTRL Register\n");
goto out;
}
ret = regmap_update_bits(chip->regmap, REG_ENABLE,
MODE_BITS_MASK << MODE_BITS_SHIFT,
opmode << MODE_BITS_SHIFT);
out:
return ret;
}
static void lm3556_torch_brightness_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct lm3556_chip_data *chip =
container_of(cdev, struct lm3556_chip_data, cdev_torch);
mutex_lock(&chip->lock);
lm3556_control(chip, brightness, MODES_TORCH);
mutex_unlock(&chip->lock);
}
static void lm3556_strobe_brightness_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct lm3556_chip_data *chip =
container_of(cdev, struct lm3556_chip_data, cdev_flash);
mutex_lock(&chip->lock);
lm3556_control(chip, brightness, MODES_FLASH);
mutex_unlock(&chip->lock);
}
static void lm3556_indicator_brightness_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct lm3556_chip_data *chip =
container_of(cdev, struct lm3556_chip_data, cdev_indicator);
mutex_lock(&chip->lock);
lm3556_control(chip, brightness, MODES_INDIC);
mutex_unlock(&chip->lock);
}
static ssize_t lm3556_indicator_pattern_store(struct device *dev,
struct device_attribute *devAttr,
const char *buf, size_t size)
{
ssize_t ret;
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3556_chip_data *chip =
container_of(led_cdev, struct lm3556_chip_data, cdev_indicator);
unsigned int state;
ret = kstrtouint(buf, 10, &state);
if (ret)
goto out;
if (state > INDIC_PATTERN_SIZE - 1)
state = INDIC_PATTERN_SIZE - 1;
ret = regmap_write(chip->regmap, REG_INDIC_BLINK,
indicator_pattern[state].blinking);
if (ret < 0) {
dev_err(chip->dev, "Failed to write REG_ENABLE Regisgter\n");
goto out;
}
ret = regmap_write(chip->regmap, REG_INDIC_PERIOD,
indicator_pattern[state].period_cnt);
if (ret < 0) {
dev_err(chip->dev, "Failed to write REG_ENABLE Regisgter\n");
goto out;
}
return size;
out:
dev_err(chip->dev, "Indicator pattern doesn't saved\n");
return size;
}
static int __devinit lm3556_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lm3556_platform_data *pdata = client->dev.platform_data;
struct lm3556_chip_data *chip;
int err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "i2c functionality check fail.\n");
return -EOPNOTSUPP;
}
if (pdata == NULL) {
dev_err(&client->dev, "Needs Platform Data.\n");
return -ENODATA;
}
chip =
devm_kzalloc(&client->dev, sizeof(struct lm3556_chip_data),
GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->dev = &client->dev;
chip->pdata = pdata;
chip->regmap = devm_regmap_init_i2c(client, &lm3556_regmap);
if (IS_ERR(chip->regmap)) {
err = PTR_ERR(chip->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
err);
return err;
}
mutex_init(&chip->lock);
i2c_set_clientdata(client, chip);
err = lm3556_chip_init(chip);
if (err < 0)
goto err_out;
chip->cdev_flash.name = "flash";
chip->cdev_flash.max_brightness = 16;
chip->cdev_flash.brightness_set = lm3556_strobe_brightness_set;
err = led_classdev_register((struct device *)
&client->dev, &chip->cdev_flash);
if (err < 0)
goto err_out;
chip->cdev_torch.name = "torch";
chip->cdev_torch.max_brightness = 8;
chip->cdev_torch.brightness_set = lm3556_torch_brightness_set;
err = led_classdev_register((struct device *)
&client->dev, &chip->cdev_torch);
if (err < 0)
goto err_create_torch_file;
chip->cdev_indicator.name = "indicator";
chip->cdev_indicator.max_brightness = 8;
chip->cdev_indicator.brightness_set = lm3556_indicator_brightness_set;
err = led_classdev_register((struct device *)
&client->dev, &chip->cdev_indicator);
if (err < 0)
goto err_create_indicator_file;
err = device_create_file(chip->cdev_indicator.dev, &dev_attr_pattern);
if (err < 0)
goto err_create_pattern_file;
dev_info(&client->dev, "LM3556 is initialized\n");
return 0;
err_create_pattern_file:
led_classdev_unregister(&chip->cdev_indicator);
err_create_indicator_file:
led_classdev_unregister(&chip->cdev_torch);
err_create_torch_file:
led_classdev_unregister(&chip->cdev_flash);
err_out:
return err;
}
static int __devexit lm3556_remove(struct i2c_client *client)
{
struct lm3556_chip_data *chip = i2c_get_clientdata(client);
device_remove_file(chip->cdev_indicator.dev, &dev_attr_pattern);
led_classdev_unregister(&chip->cdev_indicator);
led_classdev_unregister(&chip->cdev_torch);
led_classdev_unregister(&chip->cdev_flash);
regmap_write(chip->regmap, REG_ENABLE, 0);
return 0;
}
