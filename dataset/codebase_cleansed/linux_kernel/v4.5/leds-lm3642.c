static int lm3642_chip_init(struct lm3642_chip_data *chip)
{
int ret;
struct lm3642_platform_data *pdata = chip->pdata;
ret = regmap_update_bits(chip->regmap, REG_ENABLE, EX_PIN_ENABLE_MASK,
pdata->tx_pin);
if (ret < 0)
dev_err(chip->dev, "Failed to update REG_ENABLE Register\n");
return ret;
}
static int lm3642_control(struct lm3642_chip_data *chip,
u8 brightness, enum lm3642_mode opmode)
{
int ret;
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
if (chip->torch_pin)
opmode |= (TORCH_PIN_EN_MASK << TORCH_PIN_EN_SHIFT);
break;
case MODES_FLASH:
ret = regmap_update_bits(chip->regmap, REG_I_CTRL,
FLASH_I_MASK << FLASH_I_SHIFT,
(brightness - 1) << FLASH_I_SHIFT);
if (chip->strobe_pin)
opmode |= (STROBE_PIN_EN_MASK << STROBE_PIN_EN_SHIFT);
break;
case MODES_INDIC:
ret = regmap_update_bits(chip->regmap, REG_I_CTRL,
TORCH_I_MASK << TORCH_I_SHIFT,
(brightness - 1) << TORCH_I_SHIFT);
break;
case MODES_STASNDBY:
break;
default:
return ret;
}
if (ret < 0) {
dev_err(chip->dev, "Failed to write REG_I_CTRL Register\n");
goto out;
}
if (chip->tx_pin)
opmode |= (TX_PIN_EN_MASK << TX_PIN_EN_SHIFT);
ret = regmap_update_bits(chip->regmap, REG_ENABLE,
MODE_BITS_MASK << MODE_BITS_SHIFT,
opmode << MODE_BITS_SHIFT);
out:
return ret;
}
static ssize_t lm3642_torch_pin_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
ssize_t ret;
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3642_chip_data *chip =
container_of(led_cdev, struct lm3642_chip_data, cdev_indicator);
unsigned int state;
ret = kstrtouint(buf, 10, &state);
if (ret)
goto out_strtoint;
if (state != 0)
state = 0x01 << TORCH_PIN_EN_SHIFT;
chip->torch_pin = state;
ret = regmap_update_bits(chip->regmap, REG_ENABLE,
TORCH_PIN_EN_MASK << TORCH_PIN_EN_SHIFT,
state);
if (ret < 0)
goto out;
return size;
out:
dev_err(chip->dev, "%s:i2c access fail to register\n", __func__);
return ret;
out_strtoint:
dev_err(chip->dev, "%s: fail to change str to int\n", __func__);
return ret;
}
static int lm3642_torch_brightness_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct lm3642_chip_data *chip =
container_of(cdev, struct lm3642_chip_data, cdev_torch);
int ret;
mutex_lock(&chip->lock);
chip->br_torch = brightness;
ret = lm3642_control(chip, chip->br_torch, MODES_TORCH);
mutex_unlock(&chip->lock);
return ret;
}
static ssize_t lm3642_strobe_pin_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
ssize_t ret;
struct led_classdev *led_cdev = dev_get_drvdata(dev);
struct lm3642_chip_data *chip =
container_of(led_cdev, struct lm3642_chip_data, cdev_indicator);
unsigned int state;
ret = kstrtouint(buf, 10, &state);
if (ret)
goto out_strtoint;
if (state != 0)
state = 0x01 << STROBE_PIN_EN_SHIFT;
chip->strobe_pin = state;
ret = regmap_update_bits(chip->regmap, REG_ENABLE,
STROBE_PIN_EN_MASK << STROBE_PIN_EN_SHIFT,
state);
if (ret < 0)
goto out;
return size;
out:
dev_err(chip->dev, "%s:i2c access fail to register\n", __func__);
return ret;
out_strtoint:
dev_err(chip->dev, "%s: fail to change str to int\n", __func__);
return ret;
}
static int lm3642_strobe_brightness_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct lm3642_chip_data *chip =
container_of(cdev, struct lm3642_chip_data, cdev_flash);
int ret;
mutex_lock(&chip->lock);
chip->br_flash = brightness;
ret = lm3642_control(chip, chip->br_flash, MODES_FLASH);
mutex_unlock(&chip->lock);
return ret;
}
static int lm3642_indicator_brightness_set(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct lm3642_chip_data *chip =
container_of(cdev, struct lm3642_chip_data, cdev_indicator);
int ret;
mutex_lock(&chip->lock);
chip->br_indicator = brightness;
ret = lm3642_control(chip, chip->br_indicator, MODES_INDIC);
mutex_unlock(&chip->lock);
return ret;
}
static int lm3642_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lm3642_platform_data *pdata = dev_get_platdata(&client->dev);
struct lm3642_chip_data *chip;
int err;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(&client->dev, "i2c functionality check fail.\n");
return -EOPNOTSUPP;
}
if (pdata == NULL) {
dev_err(&client->dev, "needs Platform Data.\n");
return -ENODATA;
}
chip = devm_kzalloc(&client->dev,
sizeof(struct lm3642_chip_data), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->dev = &client->dev;
chip->pdata = pdata;
chip->tx_pin = pdata->tx_pin;
chip->torch_pin = pdata->torch_pin;
chip->strobe_pin = pdata->strobe_pin;
chip->regmap = devm_regmap_init_i2c(client, &lm3642_regmap);
if (IS_ERR(chip->regmap)) {
err = PTR_ERR(chip->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
err);
return err;
}
mutex_init(&chip->lock);
i2c_set_clientdata(client, chip);
err = lm3642_chip_init(chip);
if (err < 0)
goto err_out;
chip->cdev_flash.name = "flash";
chip->cdev_flash.max_brightness = 16;
chip->cdev_flash.brightness_set_blocking = lm3642_strobe_brightness_set;
chip->cdev_flash.default_trigger = "flash";
chip->cdev_flash.groups = lm3642_flash_groups,
err = led_classdev_register((struct device *)
&client->dev, &chip->cdev_flash);
if (err < 0) {
dev_err(chip->dev, "failed to register flash\n");
goto err_out;
}
chip->cdev_torch.name = "torch";
chip->cdev_torch.max_brightness = 8;
chip->cdev_torch.brightness_set_blocking = lm3642_torch_brightness_set;
chip->cdev_torch.default_trigger = "torch";
chip->cdev_torch.groups = lm3642_torch_groups,
err = led_classdev_register((struct device *)
&client->dev, &chip->cdev_torch);
if (err < 0) {
dev_err(chip->dev, "failed to register torch\n");
goto err_create_torch_file;
}
chip->cdev_indicator.name = "indicator";
chip->cdev_indicator.max_brightness = 8;
chip->cdev_indicator.brightness_set_blocking =
lm3642_indicator_brightness_set;
err = led_classdev_register((struct device *)
&client->dev, &chip->cdev_indicator);
if (err < 0) {
dev_err(chip->dev, "failed to register indicator\n");
goto err_create_indicator_file;
}
dev_info(&client->dev, "LM3642 is initialized\n");
return 0;
err_create_indicator_file:
led_classdev_unregister(&chip->cdev_torch);
err_create_torch_file:
led_classdev_unregister(&chip->cdev_flash);
err_out:
return err;
}
static int lm3642_remove(struct i2c_client *client)
{
struct lm3642_chip_data *chip = i2c_get_clientdata(client);
led_classdev_unregister(&chip->cdev_indicator);
led_classdev_unregister(&chip->cdev_torch);
led_classdev_unregister(&chip->cdev_flash);
regmap_write(chip->regmap, REG_ENABLE, 0);
return 0;
}
