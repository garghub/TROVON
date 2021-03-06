static inline void lp5523_wait_opmode_done(void)
{
usleep_range(1000, 2000);
}
static void lp5523_set_led_current(struct lp55xx_led *led, u8 led_current)
{
led->led_current = led_current;
lp55xx_write(led->chip, LP5523_REG_LED_CURRENT_BASE + led->chan_nr,
led_current);
}
static int lp5523_post_init_device(struct lp55xx_chip *chip)
{
int ret;
ret = lp55xx_write(chip, LP5523_REG_ENABLE, LP5523_ENABLE);
if (ret)
return ret;
usleep_range(1000, 2000);
ret = lp55xx_write(chip, LP5523_REG_CONFIG,
LP5523_AUTO_INC | LP5523_PWR_SAVE |
LP5523_CP_AUTO | LP5523_AUTO_CLK |
LP5523_PWM_PWR_SAVE);
if (ret)
return ret;
ret = lp55xx_write(chip, LP5523_REG_ENABLE_LEDS_MSB, 0x01);
if (ret)
return ret;
return lp55xx_write(chip, LP5523_REG_ENABLE_LEDS_LSB, 0xff);
}
static void lp5523_load_engine(struct lp55xx_chip *chip)
{
enum lp55xx_engine_index idx = chip->engine_idx;
u8 mask[] = {
[LP55XX_ENGINE_1] = LP5523_MODE_ENG1_M,
[LP55XX_ENGINE_2] = LP5523_MODE_ENG2_M,
[LP55XX_ENGINE_3] = LP5523_MODE_ENG3_M,
};
u8 val[] = {
[LP55XX_ENGINE_1] = LP5523_LOAD_ENG1,
[LP55XX_ENGINE_2] = LP5523_LOAD_ENG2,
[LP55XX_ENGINE_3] = LP5523_LOAD_ENG3,
};
u8 page_sel[] = {
[LP55XX_ENGINE_1] = LP5523_PAGE_ENG1,
[LP55XX_ENGINE_2] = LP5523_PAGE_ENG2,
[LP55XX_ENGINE_3] = LP5523_PAGE_ENG3,
};
lp55xx_update_bits(chip, LP5523_REG_OP_MODE, mask[idx], val[idx]);
lp5523_wait_opmode_done();
lp55xx_write(chip, LP5523_REG_PROG_PAGE_SEL, page_sel[idx]);
}
static void lp5523_stop_engine(struct lp55xx_chip *chip)
{
lp55xx_write(chip, LP5523_REG_OP_MODE, 0);
lp5523_wait_opmode_done();
}
static void lp5523_turn_off_channels(struct lp55xx_chip *chip)
{
int i;
for (i = 0; i < LP5523_MAX_LEDS; i++)
lp55xx_write(chip, LP5523_REG_LED_PWM_BASE + i, 0);
}
static void lp5523_run_engine(struct lp55xx_chip *chip, bool start)
{
int ret;
u8 mode;
u8 exec;
if (!start) {
lp5523_stop_engine(chip);
lp5523_turn_off_channels(chip);
return;
}
ret = lp55xx_read(chip, LP5523_REG_OP_MODE, &mode);
if (ret)
return;
ret = lp55xx_read(chip, LP5523_REG_ENABLE, &exec);
if (ret)
return;
if (LP5523_ENG1_IS_LOADING(mode)) {
mode = (mode & ~LP5523_MODE_ENG1_M) | LP5523_RUN_ENG1;
exec = (exec & ~LP5523_EXEC_ENG1_M) | LP5523_RUN_ENG1;
}
if (LP5523_ENG2_IS_LOADING(mode)) {
mode = (mode & ~LP5523_MODE_ENG2_M) | LP5523_RUN_ENG2;
exec = (exec & ~LP5523_EXEC_ENG2_M) | LP5523_RUN_ENG2;
}
if (LP5523_ENG3_IS_LOADING(mode)) {
mode = (mode & ~LP5523_MODE_ENG3_M) | LP5523_RUN_ENG3;
exec = (exec & ~LP5523_EXEC_ENG3_M) | LP5523_RUN_ENG3;
}
lp55xx_write(chip, LP5523_REG_OP_MODE, mode);
lp5523_wait_opmode_done();
lp55xx_update_bits(chip, LP5523_REG_ENABLE, LP5523_EXEC_M, exec);
}
static int lp5523_update_program_memory(struct lp55xx_chip *chip,
const u8 *data, size_t size)
{
u8 pattern[LP5523_PROGRAM_LENGTH] = {0};
unsigned cmd;
char c[3];
int update_size;
int nrchars;
int offset = 0;
int ret;
int i;
for (i = 0; i < LP5523_PROGRAM_LENGTH; i++)
lp55xx_write(chip, LP5523_REG_PROG_MEM + i, 0);
i = 0;
while ((offset < size - 1) && (i < LP5523_PROGRAM_LENGTH)) {
ret = sscanf(data + offset, "%2s%n ", c, &nrchars);
if (ret != 1)
goto err;
ret = sscanf(c, "%2x", &cmd);
if (ret != 1)
goto err;
pattern[i] = (u8)cmd;
offset += nrchars;
i++;
}
if (i % 2)
goto err;
update_size = i;
for (i = 0; i < update_size; i++)
lp55xx_write(chip, LP5523_REG_PROG_MEM + i, pattern[i]);
return 0;
err:
dev_err(&chip->cl->dev, "wrong pattern format\n");
return -EINVAL;
}
static void lp5523_firmware_loaded(struct lp55xx_chip *chip)
{
const struct firmware *fw = chip->fw;
if (fw->size > LP5523_PROGRAM_LENGTH) {
dev_err(&chip->cl->dev, "firmware data size overflow: %zu\n",
fw->size);
return;
}
lp5523_load_engine(chip);
lp5523_update_program_memory(chip, fw->data, fw->size);
}
static ssize_t lp5523_selftest(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct lp55xx_led *led = i2c_get_clientdata(to_i2c_client(dev));
struct lp55xx_chip *chip = led->chip;
struct lp55xx_platform_data *pdata = chip->pdata;
int i, ret, pos = 0;
u8 status, adc, vdd;
mutex_lock(&chip->lock);
ret = lp55xx_read(chip, LP5523_REG_STATUS, &status);
if (ret < 0)
goto fail;
if (pdata->clock_mode == LP55XX_CLOCK_EXT) {
if ((status & LP5523_EXT_CLK_USED) == 0)
goto fail;
}
lp55xx_write(chip, LP5523_REG_LED_TEST_CTRL, LP5523_EN_LEDTEST | 16);
usleep_range(3000, 6000);
ret = lp55xx_read(chip, LP5523_REG_STATUS, &status);
if (ret < 0)
goto fail;
if (!(status & LP5523_LEDTEST_DONE))
usleep_range(3000, 6000);
ret = lp55xx_read(chip, LP5523_REG_LED_TEST_ADC, &vdd);
if (ret < 0)
goto fail;
vdd--;
for (i = 0; i < LP5523_MAX_LEDS; i++) {
if (pdata->led_config[i].led_current == 0)
continue;
lp55xx_write(chip, LP5523_REG_LED_CURRENT_BASE + i,
pdata->led_config[i].led_current);
lp55xx_write(chip, LP5523_REG_LED_PWM_BASE + i, 0xff);
usleep_range(2000, 4000);
lp55xx_write(chip, LP5523_REG_LED_TEST_CTRL,
LP5523_EN_LEDTEST | i);
usleep_range(3000, 6000);
ret = lp55xx_read(chip, LP5523_REG_STATUS, &status);
if (ret < 0)
goto fail;
if (!(status & LP5523_LEDTEST_DONE))
usleep_range(3000, 6000);
ret = lp55xx_read(chip, LP5523_REG_LED_TEST_ADC, &adc);
if (ret < 0)
goto fail;
if (adc >= vdd || adc < LP5523_ADC_SHORTCIRC_LIM)
pos += sprintf(buf + pos, "LED %d FAIL\n", i);
lp55xx_write(chip, LP5523_REG_LED_PWM_BASE + i, 0x00);
lp55xx_write(chip, LP5523_REG_LED_CURRENT_BASE + i,
led->led_current);
led++;
}
if (pos == 0)
pos = sprintf(buf, "OK\n");
goto release_lock;
fail:
pos = sprintf(buf, "FAIL\n");
release_lock:
mutex_unlock(&chip->lock);
return pos;
}
static void lp5523_led_brightness_work(struct work_struct *work)
{
struct lp55xx_led *led = container_of(work, struct lp55xx_led,
brightness_work);
struct lp55xx_chip *chip = led->chip;
mutex_lock(&chip->lock);
lp55xx_write(chip, LP5523_REG_LED_PWM_BASE + led->chan_nr,
led->brightness);
mutex_unlock(&chip->lock);
}
static int lp5523_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct lp55xx_chip *chip;
struct lp55xx_led *led;
struct lp55xx_platform_data *pdata;
struct device_node *np = client->dev.of_node;
if (!client->dev.platform_data) {
if (np) {
ret = lp55xx_of_populate_pdata(&client->dev, np);
if (ret < 0)
return ret;
} else {
dev_err(&client->dev, "no platform data\n");
return -EINVAL;
}
}
pdata = client->dev.platform_data;
chip = devm_kzalloc(&client->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
led = devm_kzalloc(&client->dev,
sizeof(*led) * pdata->num_channels, GFP_KERNEL);
if (!led)
return -ENOMEM;
chip->cl = client;
chip->pdata = pdata;
chip->cfg = &lp5523_cfg;
mutex_init(&chip->lock);
i2c_set_clientdata(client, led);
ret = lp55xx_init_device(chip);
if (ret)
goto err_init;
dev_info(&client->dev, "%s Programmable led chip found\n", id->name);
ret = lp55xx_register_leds(led, chip);
if (ret)
goto err_register_leds;
ret = lp55xx_register_sysfs(chip);
if (ret) {
dev_err(&client->dev, "registering sysfs failed\n");
goto err_register_sysfs;
}
return 0;
err_register_sysfs:
lp55xx_unregister_leds(led, chip);
err_register_leds:
lp55xx_deinit_device(chip);
err_init:
return ret;
}
static int lp5523_remove(struct i2c_client *client)
{
struct lp55xx_led *led = i2c_get_clientdata(client);
struct lp55xx_chip *chip = led->chip;
lp5523_stop_engine(chip);
lp55xx_unregister_sysfs(chip);
lp55xx_unregister_leds(led, chip);
lp55xx_deinit_device(chip);
return 0;
}
