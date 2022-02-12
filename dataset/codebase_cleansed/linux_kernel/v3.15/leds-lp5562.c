static inline void lp5562_wait_opmode_done(void)
{
usleep_range(200, 300);
}
static inline void lp5562_wait_enable_done(void)
{
usleep_range(500, 600);
}
static void lp5562_set_led_current(struct lp55xx_led *led, u8 led_current)
{
u8 addr[] = {
LP5562_REG_R_CURRENT,
LP5562_REG_G_CURRENT,
LP5562_REG_B_CURRENT,
LP5562_REG_W_CURRENT,
};
led->led_current = led_current;
lp55xx_write(led->chip, addr[led->chan_nr], led_current);
}
static void lp5562_load_engine(struct lp55xx_chip *chip)
{
enum lp55xx_engine_index idx = chip->engine_idx;
u8 mask[] = {
[LP55XX_ENGINE_1] = LP5562_MODE_ENG1_M,
[LP55XX_ENGINE_2] = LP5562_MODE_ENG2_M,
[LP55XX_ENGINE_3] = LP5562_MODE_ENG3_M,
};
u8 val[] = {
[LP55XX_ENGINE_1] = LP5562_LOAD_ENG1,
[LP55XX_ENGINE_2] = LP5562_LOAD_ENG2,
[LP55XX_ENGINE_3] = LP5562_LOAD_ENG3,
};
lp55xx_update_bits(chip, LP5562_REG_OP_MODE, mask[idx], val[idx]);
lp5562_wait_opmode_done();
}
static void lp5562_stop_engine(struct lp55xx_chip *chip)
{
lp55xx_write(chip, LP5562_REG_OP_MODE, LP5562_CMD_DISABLE);
lp5562_wait_opmode_done();
}
static void lp5562_run_engine(struct lp55xx_chip *chip, bool start)
{
int ret;
u8 mode;
u8 exec;
if (!start) {
lp55xx_write(chip, LP5562_REG_ENABLE, LP5562_ENABLE_DEFAULT);
lp5562_wait_enable_done();
lp5562_stop_engine(chip);
lp55xx_write(chip, LP5562_REG_ENG_SEL, LP5562_ENG_SEL_PWM);
lp55xx_write(chip, LP5562_REG_OP_MODE, LP5562_CMD_DIRECT);
lp5562_wait_opmode_done();
return;
}
ret = lp55xx_read(chip, LP5562_REG_OP_MODE, &mode);
if (ret)
return;
ret = lp55xx_read(chip, LP5562_REG_ENABLE, &exec);
if (ret)
return;
if (LP5562_ENG1_IS_LOADING(mode)) {
mode = (mode & ~LP5562_MODE_ENG1_M) | LP5562_RUN_ENG1;
exec = (exec & ~LP5562_EXEC_ENG1_M) | LP5562_RUN_ENG1;
}
if (LP5562_ENG2_IS_LOADING(mode)) {
mode = (mode & ~LP5562_MODE_ENG2_M) | LP5562_RUN_ENG2;
exec = (exec & ~LP5562_EXEC_ENG2_M) | LP5562_RUN_ENG2;
}
if (LP5562_ENG3_IS_LOADING(mode)) {
mode = (mode & ~LP5562_MODE_ENG3_M) | LP5562_RUN_ENG3;
exec = (exec & ~LP5562_EXEC_ENG3_M) | LP5562_RUN_ENG3;
}
lp55xx_write(chip, LP5562_REG_OP_MODE, mode);
lp5562_wait_opmode_done();
lp55xx_update_bits(chip, LP5562_REG_ENABLE, LP5562_EXEC_M, exec);
lp5562_wait_enable_done();
}
static int lp5562_update_firmware(struct lp55xx_chip *chip,
const u8 *data, size_t size)
{
enum lp55xx_engine_index idx = chip->engine_idx;
u8 pattern[LP5562_PROGRAM_LENGTH] = {0};
u8 addr[] = {
[LP55XX_ENGINE_1] = LP5562_REG_PROG_MEM_ENG1,
[LP55XX_ENGINE_2] = LP5562_REG_PROG_MEM_ENG2,
[LP55XX_ENGINE_3] = LP5562_REG_PROG_MEM_ENG3,
};
unsigned cmd;
char c[3];
int program_size;
int nrchars;
int offset = 0;
int ret;
int i;
for (i = 0; i < LP5562_PROGRAM_LENGTH; i++)
lp55xx_write(chip, addr[idx] + i, 0);
i = 0;
while ((offset < size - 1) && (i < LP5562_PROGRAM_LENGTH)) {
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
program_size = i;
for (i = 0; i < program_size; i++)
lp55xx_write(chip, addr[idx] + i, pattern[i]);
return 0;
err:
dev_err(&chip->cl->dev, "wrong pattern format\n");
return -EINVAL;
}
static void lp5562_firmware_loaded(struct lp55xx_chip *chip)
{
const struct firmware *fw = chip->fw;
if (fw->size > LP5562_PROGRAM_LENGTH) {
dev_err(&chip->cl->dev, "firmware data size overflow: %zu\n",
fw->size);
return;
}
lp5562_load_engine(chip);
lp5562_update_firmware(chip, fw->data, fw->size);
}
static int lp5562_post_init_device(struct lp55xx_chip *chip)
{
int ret;
u8 cfg = LP5562_DEFAULT_CFG;
ret = lp55xx_write(chip, LP5562_REG_OP_MODE, LP5562_CMD_DIRECT);
if (ret)
return ret;
lp5562_wait_opmode_done();
if (!lp55xx_is_extclk_used(chip))
cfg |= LP5562_CLK_INT;
ret = lp55xx_write(chip, LP5562_REG_CONFIG, cfg);
if (ret)
return ret;
lp55xx_write(chip, LP5562_REG_R_PWM, 0);
lp55xx_write(chip, LP5562_REG_G_PWM, 0);
lp55xx_write(chip, LP5562_REG_B_PWM, 0);
lp55xx_write(chip, LP5562_REG_W_PWM, 0);
lp55xx_write(chip, LP5562_REG_ENG_SEL, LP5562_ENG_SEL_PWM);
return 0;
}
static void lp5562_led_brightness_work(struct work_struct *work)
{
struct lp55xx_led *led = container_of(work, struct lp55xx_led,
brightness_work);
struct lp55xx_chip *chip = led->chip;
u8 addr[] = {
LP5562_REG_R_PWM,
LP5562_REG_G_PWM,
LP5562_REG_B_PWM,
LP5562_REG_W_PWM,
};
mutex_lock(&chip->lock);
lp55xx_write(chip, addr[led->chan_nr], led->brightness);
mutex_unlock(&chip->lock);
}
static void lp5562_write_program_memory(struct lp55xx_chip *chip,
u8 base, const u8 *rgb, int size)
{
int i;
if (!rgb || size <= 0)
return;
for (i = 0; i < size; i++)
lp55xx_write(chip, base + i, *(rgb + i));
lp55xx_write(chip, base + i, 0);
lp55xx_write(chip, base + i + 1, 0);
}
static inline bool _is_pc_overflow(struct lp55xx_predef_pattern *ptn)
{
return ptn->size_r >= LP5562_PROGRAM_LENGTH ||
ptn->size_g >= LP5562_PROGRAM_LENGTH ||
ptn->size_b >= LP5562_PROGRAM_LENGTH;
}
static int lp5562_run_predef_led_pattern(struct lp55xx_chip *chip, int mode)
{
struct lp55xx_predef_pattern *ptn;
int i;
if (mode == LP5562_PATTERN_OFF) {
lp5562_run_engine(chip, false);
return 0;
}
ptn = chip->pdata->patterns + (mode - 1);
if (!ptn || _is_pc_overflow(ptn)) {
dev_err(&chip->cl->dev, "invalid pattern data\n");
return -EINVAL;
}
lp5562_stop_engine(chip);
lp55xx_write(chip, LP5562_REG_ENG_SEL, LP5562_ENG_SEL_RGB);
for (i = LP55XX_ENGINE_1; i <= LP55XX_ENGINE_3; i++) {
chip->engine_idx = i;
lp5562_load_engine(chip);
}
lp55xx_write(chip, LP5562_REG_PROG_MEM_ENG1, 0);
lp55xx_write(chip, LP5562_REG_PROG_MEM_ENG1 + 1, 0);
lp55xx_write(chip, LP5562_REG_PROG_MEM_ENG2, 0);
lp55xx_write(chip, LP5562_REG_PROG_MEM_ENG2 + 1, 0);
lp55xx_write(chip, LP5562_REG_PROG_MEM_ENG3, 0);
lp55xx_write(chip, LP5562_REG_PROG_MEM_ENG3 + 1, 0);
lp5562_write_program_memory(chip, LP5562_REG_PROG_MEM_ENG1,
ptn->r, ptn->size_r);
lp5562_write_program_memory(chip, LP5562_REG_PROG_MEM_ENG2,
ptn->g, ptn->size_g);
lp5562_write_program_memory(chip, LP5562_REG_PROG_MEM_ENG3,
ptn->b, ptn->size_b);
lp5562_run_engine(chip, true);
return 0;
}
static ssize_t lp5562_store_pattern(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct lp55xx_led *led = i2c_get_clientdata(to_i2c_client(dev));
struct lp55xx_chip *chip = led->chip;
struct lp55xx_predef_pattern *ptn = chip->pdata->patterns;
int num_patterns = chip->pdata->num_patterns;
unsigned long mode;
int ret;
ret = kstrtoul(buf, 0, &mode);
if (ret)
return ret;
if (mode > num_patterns || !ptn)
return -EINVAL;
mutex_lock(&chip->lock);
ret = lp5562_run_predef_led_pattern(chip, mode);
mutex_unlock(&chip->lock);
if (ret)
return ret;
return len;
}
static ssize_t lp5562_store_engine_mux(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct lp55xx_led *led = i2c_get_clientdata(to_i2c_client(dev));
struct lp55xx_chip *chip = led->chip;
u8 mask;
u8 val;
if (sysfs_streq(buf, "RGB")) {
mask = LP5562_ENG_FOR_RGB_M;
val = LP5562_ENG_SEL_RGB;
} else if (sysfs_streq(buf, "W")) {
enum lp55xx_engine_index idx = chip->engine_idx;
mask = LP5562_ENG_FOR_W_M;
switch (idx) {
case LP55XX_ENGINE_1:
val = LP5562_ENG1_FOR_W;
break;
case LP55XX_ENGINE_2:
val = LP5562_ENG2_FOR_W;
break;
case LP55XX_ENGINE_3:
val = LP5562_ENG3_FOR_W;
break;
default:
return -EINVAL;
}
} else {
dev_err(dev, "choose RGB or W\n");
return -EINVAL;
}
mutex_lock(&chip->lock);
lp55xx_update_bits(chip, LP5562_REG_ENG_SEL, mask, val);
mutex_unlock(&chip->lock);
return len;
}
static int lp5562_probe(struct i2c_client *client,
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
chip->cfg = &lp5562_cfg;
mutex_init(&chip->lock);
i2c_set_clientdata(client, led);
ret = lp55xx_init_device(chip);
if (ret)
goto err_init;
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
static int lp5562_remove(struct i2c_client *client)
{
struct lp55xx_led *led = i2c_get_clientdata(client);
struct lp55xx_chip *chip = led->chip;
lp5562_stop_engine(chip);
lp55xx_unregister_sysfs(chip);
lp55xx_unregister_leds(led, chip);
lp55xx_deinit_device(chip);
return 0;
}
