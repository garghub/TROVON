static inline void lp5521_wait_opmode_done(void)
{
usleep_range(200, 300);
}
static inline void lp5521_wait_enable_done(void)
{
usleep_range(500, 600);
}
static void lp5521_set_led_current(struct lp55xx_led *led, u8 led_current)
{
led->led_current = led_current;
lp55xx_write(led->chip, LP5521_REG_LED_CURRENT_BASE + led->chan_nr,
led_current);
}
static void lp5521_load_engine(struct lp55xx_chip *chip)
{
enum lp55xx_engine_index idx = chip->engine_idx;
u8 mask[] = {
[LP55XX_ENGINE_1] = LP5521_MODE_R_M,
[LP55XX_ENGINE_2] = LP5521_MODE_G_M,
[LP55XX_ENGINE_3] = LP5521_MODE_B_M,
};
u8 val[] = {
[LP55XX_ENGINE_1] = LP5521_LOAD_R,
[LP55XX_ENGINE_2] = LP5521_LOAD_G,
[LP55XX_ENGINE_3] = LP5521_LOAD_B,
};
lp55xx_update_bits(chip, LP5521_REG_OP_MODE, mask[idx], val[idx]);
lp5521_wait_opmode_done();
}
static void lp5521_stop_engine(struct lp55xx_chip *chip)
{
lp55xx_write(chip, LP5521_REG_OP_MODE, 0);
lp5521_wait_opmode_done();
}
static void lp5521_run_engine(struct lp55xx_chip *chip, bool start)
{
int ret;
u8 mode;
u8 exec;
if (!start) {
lp5521_stop_engine(chip);
lp55xx_write(chip, LP5521_REG_OP_MODE, LP5521_CMD_DIRECT);
lp5521_wait_opmode_done();
return;
}
ret = lp55xx_read(chip, LP5521_REG_OP_MODE, &mode);
if (ret)
return;
ret = lp55xx_read(chip, LP5521_REG_ENABLE, &exec);
if (ret)
return;
if (LP5521_R_IS_LOADING(mode)) {
mode = (mode & ~LP5521_MODE_R_M) | LP5521_RUN_R;
exec = (exec & ~LP5521_EXEC_R_M) | LP5521_RUN_R;
}
if (LP5521_G_IS_LOADING(mode)) {
mode = (mode & ~LP5521_MODE_G_M) | LP5521_RUN_G;
exec = (exec & ~LP5521_EXEC_G_M) | LP5521_RUN_G;
}
if (LP5521_B_IS_LOADING(mode)) {
mode = (mode & ~LP5521_MODE_B_M) | LP5521_RUN_B;
exec = (exec & ~LP5521_EXEC_B_M) | LP5521_RUN_B;
}
lp55xx_write(chip, LP5521_REG_OP_MODE, mode);
lp5521_wait_opmode_done();
lp55xx_update_bits(chip, LP5521_REG_ENABLE, LP5521_EXEC_M, exec);
lp5521_wait_enable_done();
}
static int lp5521_update_program_memory(struct lp55xx_chip *chip,
const u8 *data, size_t size)
{
enum lp55xx_engine_index idx = chip->engine_idx;
u8 pattern[LP5521_PROGRAM_LENGTH] = {0};
u8 addr[] = {
[LP55XX_ENGINE_1] = LP5521_REG_R_PROG_MEM,
[LP55XX_ENGINE_2] = LP5521_REG_G_PROG_MEM,
[LP55XX_ENGINE_3] = LP5521_REG_B_PROG_MEM,
};
unsigned cmd;
char c[3];
int nrchars;
int ret;
int offset = 0;
int i = 0;
while ((offset < size - 1) && (i < LP5521_PROGRAM_LENGTH)) {
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
mutex_lock(&chip->lock);
for (i = 0; i < LP5521_PROGRAM_LENGTH; i++) {
ret = lp55xx_write(chip, addr[idx] + i, pattern[i]);
if (ret) {
mutex_unlock(&chip->lock);
return -EINVAL;
}
}
mutex_unlock(&chip->lock);
return size;
err:
dev_err(&chip->cl->dev, "wrong pattern format\n");
return -EINVAL;
}
static void lp5521_firmware_loaded(struct lp55xx_chip *chip)
{
const struct firmware *fw = chip->fw;
if (fw->size > LP5521_PROGRAM_LENGTH) {
dev_err(&chip->cl->dev, "firmware data size overflow: %zu\n",
fw->size);
return;
}
lp5521_load_engine(chip);
lp5521_update_program_memory(chip, fw->data, fw->size);
}
static int lp5521_post_init_device(struct lp55xx_chip *chip)
{
int ret;
u8 val;
ret = lp55xx_read(chip, LP5521_REG_R_CURRENT, &val);
if (ret) {
dev_err(&chip->cl->dev, "error in resetting chip\n");
return ret;
}
if (val != LP5521_REG_R_CURR_DEFAULT) {
dev_err(&chip->cl->dev,
"unexpected data in register (expected 0x%x got 0x%x)\n",
LP5521_REG_R_CURR_DEFAULT, val);
ret = -EINVAL;
return ret;
}
usleep_range(10000, 20000);
ret = lp55xx_write(chip, LP5521_REG_OP_MODE, LP5521_CMD_DIRECT);
val = LP5521_DEFAULT_CFG;
if (!lp55xx_is_extclk_used(chip))
val |= LP5521_CLK_INT;
ret = lp55xx_write(chip, LP5521_REG_CONFIG, val);
if (ret)
return ret;
lp55xx_write(chip, LP5521_REG_R_PWM, 0);
lp55xx_write(chip, LP5521_REG_G_PWM, 0);
lp55xx_write(chip, LP5521_REG_B_PWM, 0);
ret = lp55xx_write(chip, LP5521_REG_ENABLE, LP5521_ENABLE_RUN_PROGRAM);
if (ret)
return ret;
lp5521_wait_enable_done();
return 0;
}
static int lp5521_run_selftest(struct lp55xx_chip *chip, char *buf)
{
struct lp55xx_platform_data *pdata = chip->pdata;
int ret;
u8 status;
ret = lp55xx_read(chip, LP5521_REG_STATUS, &status);
if (ret < 0)
return ret;
if (pdata->clock_mode != LP55XX_CLOCK_EXT)
return 0;
if ((status & LP5521_EXT_CLK_USED) == 0)
return -EIO;
return 0;
}
static void lp5521_led_brightness_work(struct work_struct *work)
{
struct lp55xx_led *led = container_of(work, struct lp55xx_led,
brightness_work);
struct lp55xx_chip *chip = led->chip;
mutex_lock(&chip->lock);
lp55xx_write(chip, LP5521_REG_LED_PWM_BASE + led->chan_nr,
led->brightness);
mutex_unlock(&chip->lock);
}
static ssize_t show_engine_mode(struct device *dev,
struct device_attribute *attr,
char *buf, int nr)
{
struct lp55xx_led *led = i2c_get_clientdata(to_i2c_client(dev));
struct lp55xx_chip *chip = led->chip;
enum lp55xx_engine_mode mode = chip->engines[nr - 1].mode;
switch (mode) {
case LP55XX_ENGINE_RUN:
return sprintf(buf, "run\n");
case LP55XX_ENGINE_LOAD:
return sprintf(buf, "load\n");
case LP55XX_ENGINE_DISABLED:
default:
return sprintf(buf, "disabled\n");
}
}
static ssize_t store_engine_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len, int nr)
{
struct lp55xx_led *led = i2c_get_clientdata(to_i2c_client(dev));
struct lp55xx_chip *chip = led->chip;
struct lp55xx_engine *engine = &chip->engines[nr - 1];
mutex_lock(&chip->lock);
chip->engine_idx = nr;
if (!strncmp(buf, "run", 3)) {
lp5521_run_engine(chip, true);
engine->mode = LP55XX_ENGINE_RUN;
} else if (!strncmp(buf, "load", 4)) {
lp5521_stop_engine(chip);
lp5521_load_engine(chip);
engine->mode = LP55XX_ENGINE_LOAD;
} else if (!strncmp(buf, "disabled", 8)) {
lp5521_stop_engine(chip);
engine->mode = LP55XX_ENGINE_DISABLED;
}
mutex_unlock(&chip->lock);
return len;
}
static ssize_t store_engine_load(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len, int nr)
{
struct lp55xx_led *led = i2c_get_clientdata(to_i2c_client(dev));
struct lp55xx_chip *chip = led->chip;
mutex_lock(&chip->lock);
chip->engine_idx = nr;
lp5521_load_engine(chip);
mutex_unlock(&chip->lock);
return lp5521_update_program_memory(chip, buf, len);
}
static ssize_t lp5521_selftest(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct lp55xx_led *led = i2c_get_clientdata(to_i2c_client(dev));
struct lp55xx_chip *chip = led->chip;
int ret;
mutex_lock(&chip->lock);
ret = lp5521_run_selftest(chip, buf);
mutex_unlock(&chip->lock);
return scnprintf(buf, PAGE_SIZE, "%s\n", ret ? "FAIL" : "OK");
}
static int lp5521_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct lp55xx_chip *chip;
struct lp55xx_led *led;
struct lp55xx_platform_data *pdata;
struct device_node *np = client->dev.of_node;
if (!dev_get_platdata(&client->dev)) {
if (np) {
ret = lp55xx_of_populate_pdata(&client->dev, np);
if (ret < 0)
return ret;
} else {
dev_err(&client->dev, "no platform data\n");
return -EINVAL;
}
}
pdata = dev_get_platdata(&client->dev);
chip = devm_kzalloc(&client->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
led = devm_kzalloc(&client->dev,
sizeof(*led) * pdata->num_channels, GFP_KERNEL);
if (!led)
return -ENOMEM;
chip->cl = client;
chip->pdata = pdata;
chip->cfg = &lp5521_cfg;
mutex_init(&chip->lock);
i2c_set_clientdata(client, led);
ret = lp55xx_init_device(chip);
if (ret)
goto err_init;
dev_info(&client->dev, "%s programmable led chip found\n", id->name);
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
static int lp5521_remove(struct i2c_client *client)
{
struct lp55xx_led *led = i2c_get_clientdata(client);
struct lp55xx_chip *chip = led->chip;
lp5521_stop_engine(chip);
lp55xx_unregister_sysfs(chip);
lp55xx_unregister_leds(led, chip);
lp55xx_deinit_device(chip);
return 0;
}
