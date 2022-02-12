static int ams369fg06_spi_write_byte(struct ams369fg06 *lcd, int addr, int data)
{
u16 buf[1];
struct spi_message msg;
struct spi_transfer xfer = {
.len = 2,
.tx_buf = buf,
};
buf[0] = (addr << 8) | data;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
return spi_sync(lcd->spi, &msg);
}
static int ams369fg06_spi_write(struct ams369fg06 *lcd, unsigned char address,
unsigned char command)
{
int ret = 0;
if (address != DATA_ONLY)
ret = ams369fg06_spi_write_byte(lcd, 0x70, address);
if (command != COMMAND_ONLY)
ret = ams369fg06_spi_write_byte(lcd, 0x72, command);
return ret;
}
static int ams369fg06_panel_send_sequence(struct ams369fg06 *lcd,
const unsigned short *wbuf)
{
int ret = 0, i = 0;
while ((wbuf[i] & DEFMASK) != ENDDEF) {
if ((wbuf[i] & DEFMASK) != SLEEPMSEC) {
ret = ams369fg06_spi_write(lcd, wbuf[i], wbuf[i+1]);
if (ret)
break;
} else {
msleep(wbuf[i+1]);
}
i += 2;
}
return ret;
}
static int _ams369fg06_gamma_ctl(struct ams369fg06 *lcd,
const unsigned int *gamma)
{
unsigned int i = 0;
int ret = 0;
for (i = 0 ; i < GAMMA_TABLE_COUNT / 3; i++) {
ret = ams369fg06_spi_write(lcd, 0x40 + i, gamma[i]);
ret = ams369fg06_spi_write(lcd, 0x50 + i, gamma[i+7*1]);
ret = ams369fg06_spi_write(lcd, 0x60 + i, gamma[i+7*2]);
if (ret) {
dev_err(lcd->dev, "failed to set gamma table.\n");
goto gamma_err;
}
}
gamma_err:
return ret;
}
static int ams369fg06_gamma_ctl(struct ams369fg06 *lcd, int brightness)
{
int ret = 0;
int gamma = 0;
if ((brightness >= 0) && (brightness <= 50))
gamma = 0;
else if ((brightness > 50) && (brightness <= 100))
gamma = 1;
else if ((brightness > 100) && (brightness <= 150))
gamma = 2;
else if ((brightness > 150) && (brightness <= 200))
gamma = 3;
else if ((brightness > 200) && (brightness <= 255))
gamma = 4;
ret = _ams369fg06_gamma_ctl(lcd, gamma_table.gamma_22_table[gamma]);
return ret;
}
static int ams369fg06_ldi_init(struct ams369fg06 *lcd)
{
int ret, i;
static const unsigned short *init_seq[] = {
seq_setting,
seq_stand_by_off,
};
for (i = 0; i < ARRAY_SIZE(init_seq); i++) {
ret = ams369fg06_panel_send_sequence(lcd, init_seq[i]);
if (ret)
break;
}
return ret;
}
static int ams369fg06_ldi_enable(struct ams369fg06 *lcd)
{
int ret, i;
static const unsigned short *init_seq[] = {
seq_stand_by_off,
seq_display_on,
};
for (i = 0; i < ARRAY_SIZE(init_seq); i++) {
ret = ams369fg06_panel_send_sequence(lcd, init_seq[i]);
if (ret)
break;
}
return ret;
}
static int ams369fg06_ldi_disable(struct ams369fg06 *lcd)
{
int ret, i;
static const unsigned short *init_seq[] = {
seq_display_off,
seq_stand_by_on,
};
for (i = 0; i < ARRAY_SIZE(init_seq); i++) {
ret = ams369fg06_panel_send_sequence(lcd, init_seq[i]);
if (ret)
break;
}
return ret;
}
static int ams369fg06_power_is_on(int power)
{
return power <= FB_BLANK_NORMAL;
}
static int ams369fg06_power_on(struct ams369fg06 *lcd)
{
int ret = 0;
struct lcd_platform_data *pd;
struct backlight_device *bd;
pd = lcd->lcd_pd;
bd = lcd->bd;
if (pd->power_on) {
pd->power_on(lcd->ld, 1);
msleep(pd->power_on_delay);
}
if (!pd->reset) {
dev_err(lcd->dev, "reset is NULL.\n");
return -EINVAL;
} else {
pd->reset(lcd->ld);
msleep(pd->reset_delay);
}
ret = ams369fg06_ldi_init(lcd);
if (ret) {
dev_err(lcd->dev, "failed to initialize ldi.\n");
return ret;
}
ret = ams369fg06_ldi_enable(lcd);
if (ret) {
dev_err(lcd->dev, "failed to enable ldi.\n");
return ret;
}
ret = ams369fg06_gamma_ctl(lcd, bd->props.brightness);
if (ret) {
dev_err(lcd->dev, "lcd gamma setting failed.\n");
return ret;
}
return 0;
}
static int ams369fg06_power_off(struct ams369fg06 *lcd)
{
int ret;
struct lcd_platform_data *pd;
pd = lcd->lcd_pd;
ret = ams369fg06_ldi_disable(lcd);
if (ret) {
dev_err(lcd->dev, "lcd setting failed.\n");
return -EIO;
}
msleep(pd->power_off_delay);
if (pd->power_on)
pd->power_on(lcd->ld, 0);
return 0;
}
static int ams369fg06_power(struct ams369fg06 *lcd, int power)
{
int ret = 0;
if (ams369fg06_power_is_on(power) &&
!ams369fg06_power_is_on(lcd->power))
ret = ams369fg06_power_on(lcd);
else if (!ams369fg06_power_is_on(power) &&
ams369fg06_power_is_on(lcd->power))
ret = ams369fg06_power_off(lcd);
if (!ret)
lcd->power = power;
return ret;
}
static int ams369fg06_get_power(struct lcd_device *ld)
{
struct ams369fg06 *lcd = lcd_get_data(ld);
return lcd->power;
}
static int ams369fg06_set_power(struct lcd_device *ld, int power)
{
struct ams369fg06 *lcd = lcd_get_data(ld);
if (power != FB_BLANK_UNBLANK && power != FB_BLANK_POWERDOWN &&
power != FB_BLANK_NORMAL) {
dev_err(lcd->dev, "power value should be 0, 1 or 4.\n");
return -EINVAL;
}
return ams369fg06_power(lcd, power);
}
static int ams369fg06_get_brightness(struct backlight_device *bd)
{
return bd->props.brightness;
}
static int ams369fg06_set_brightness(struct backlight_device *bd)
{
int ret = 0;
int brightness = bd->props.brightness;
struct ams369fg06 *lcd = bl_get_data(bd);
if (brightness < MIN_BRIGHTNESS ||
brightness > bd->props.max_brightness) {
dev_err(&bd->dev, "lcd brightness should be %d to %d.\n",
MIN_BRIGHTNESS, MAX_BRIGHTNESS);
return -EINVAL;
}
ret = ams369fg06_gamma_ctl(lcd, bd->props.brightness);
if (ret) {
dev_err(&bd->dev, "lcd brightness setting failed.\n");
return -EIO;
}
return ret;
}
static int ams369fg06_probe(struct spi_device *spi)
{
int ret = 0;
struct ams369fg06 *lcd = NULL;
struct lcd_device *ld = NULL;
struct backlight_device *bd = NULL;
struct backlight_properties props;
lcd = devm_kzalloc(&spi->dev, sizeof(struct ams369fg06), GFP_KERNEL);
if (!lcd)
return -ENOMEM;
spi->bits_per_word = 16;
ret = spi_setup(spi);
if (ret < 0) {
dev_err(&spi->dev, "spi setup failed.\n");
return ret;
}
lcd->spi = spi;
lcd->dev = &spi->dev;
lcd->lcd_pd = spi->dev.platform_data;
if (!lcd->lcd_pd) {
dev_err(&spi->dev, "platform data is NULL\n");
return -EINVAL;
}
ld = lcd_device_register("ams369fg06", &spi->dev, lcd,
&ams369fg06_lcd_ops);
if (IS_ERR(ld))
return PTR_ERR(ld);
lcd->ld = ld;
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.max_brightness = MAX_BRIGHTNESS;
bd = backlight_device_register("ams369fg06-bl", &spi->dev, lcd,
&ams369fg06_backlight_ops, &props);
if (IS_ERR(bd)) {
ret = PTR_ERR(bd);
goto out_lcd_unregister;
}
bd->props.brightness = DEFAULT_BRIGHTNESS;
lcd->bd = bd;
if (!lcd->lcd_pd->lcd_enabled) {
lcd->power = FB_BLANK_POWERDOWN;
ams369fg06_power(lcd, FB_BLANK_UNBLANK);
} else {
lcd->power = FB_BLANK_UNBLANK;
}
spi_set_drvdata(spi, lcd);
dev_info(&spi->dev, "ams369fg06 panel driver has been probed.\n");
return 0;
out_lcd_unregister:
lcd_device_unregister(ld);
return ret;
}
static int ams369fg06_remove(struct spi_device *spi)
{
struct ams369fg06 *lcd = spi_get_drvdata(spi);
ams369fg06_power(lcd, FB_BLANK_POWERDOWN);
backlight_device_unregister(lcd->bd);
lcd_device_unregister(lcd->ld);
return 0;
}
static int ams369fg06_suspend(struct device *dev)
{
struct ams369fg06 *lcd = dev_get_drvdata(dev);
dev_dbg(dev, "lcd->power = %d\n", lcd->power);
return ams369fg06_power(lcd, FB_BLANK_POWERDOWN);
}
static int ams369fg06_resume(struct device *dev)
{
struct ams369fg06 *lcd = dev_get_drvdata(dev);
lcd->power = FB_BLANK_POWERDOWN;
return ams369fg06_power(lcd, FB_BLANK_UNBLANK);
}
static void ams369fg06_shutdown(struct spi_device *spi)
{
struct ams369fg06 *lcd = spi_get_drvdata(spi);
ams369fg06_power(lcd, FB_BLANK_POWERDOWN);
}
