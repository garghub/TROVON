static int lms501kf03_spi_write_byte(struct lms501kf03 *lcd, int addr, int data)
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
static int lms501kf03_spi_write(struct lms501kf03 *lcd, unsigned char address,
unsigned char command)
{
return lms501kf03_spi_write_byte(lcd, address, command);
}
static int lms501kf03_panel_send_sequence(struct lms501kf03 *lcd,
const unsigned char *wbuf,
unsigned int len)
{
int ret = 0, i = 0;
while (i < len) {
if (i == 0)
ret = lms501kf03_spi_write(lcd, COMMAND_ONLY, wbuf[i]);
else
ret = lms501kf03_spi_write(lcd, DATA_ONLY, wbuf[i]);
if (ret)
break;
i += 1;
}
return ret;
}
static int lms501kf03_ldi_init(struct lms501kf03 *lcd)
{
int ret, i;
static const unsigned char *init_seq[] = {
seq_password,
seq_power,
seq_display,
seq_rgb_if,
seq_display_inv,
seq_vcom,
seq_gate,
seq_panel,
seq_col_mod,
seq_w_gamma,
seq_rgb_gamma,
seq_sleep_out,
};
static const unsigned int size_seq[] = {
ARRAY_SIZE(seq_password),
ARRAY_SIZE(seq_power),
ARRAY_SIZE(seq_display),
ARRAY_SIZE(seq_rgb_if),
ARRAY_SIZE(seq_display_inv),
ARRAY_SIZE(seq_vcom),
ARRAY_SIZE(seq_gate),
ARRAY_SIZE(seq_panel),
ARRAY_SIZE(seq_col_mod),
ARRAY_SIZE(seq_w_gamma),
ARRAY_SIZE(seq_rgb_gamma),
ARRAY_SIZE(seq_sleep_out),
};
for (i = 0; i < ARRAY_SIZE(init_seq); i++) {
ret = lms501kf03_panel_send_sequence(lcd, init_seq[i],
size_seq[i]);
if (ret)
break;
}
msleep(120);
return ret;
}
static int lms501kf03_ldi_enable(struct lms501kf03 *lcd)
{
return lms501kf03_panel_send_sequence(lcd, seq_display_on,
ARRAY_SIZE(seq_display_on));
}
static int lms501kf03_ldi_disable(struct lms501kf03 *lcd)
{
return lms501kf03_panel_send_sequence(lcd, seq_display_off,
ARRAY_SIZE(seq_display_off));
}
static int lms501kf03_power_is_on(int power)
{
return (power) <= FB_BLANK_NORMAL;
}
static int lms501kf03_power_on(struct lms501kf03 *lcd)
{
int ret = 0;
struct lcd_platform_data *pd;
pd = lcd->lcd_pd;
if (!pd->power_on) {
dev_err(lcd->dev, "power_on is NULL.\n");
return -EINVAL;
} else {
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
ret = lms501kf03_ldi_init(lcd);
if (ret) {
dev_err(lcd->dev, "failed to initialize ldi.\n");
return ret;
}
ret = lms501kf03_ldi_enable(lcd);
if (ret) {
dev_err(lcd->dev, "failed to enable ldi.\n");
return ret;
}
return 0;
}
static int lms501kf03_power_off(struct lms501kf03 *lcd)
{
int ret = 0;
struct lcd_platform_data *pd;
pd = lcd->lcd_pd;
ret = lms501kf03_ldi_disable(lcd);
if (ret) {
dev_err(lcd->dev, "lcd setting failed.\n");
return -EIO;
}
msleep(pd->power_off_delay);
pd->power_on(lcd->ld, 0);
return 0;
}
static int lms501kf03_power(struct lms501kf03 *lcd, int power)
{
int ret = 0;
if (lms501kf03_power_is_on(power) &&
!lms501kf03_power_is_on(lcd->power))
ret = lms501kf03_power_on(lcd);
else if (!lms501kf03_power_is_on(power) &&
lms501kf03_power_is_on(lcd->power))
ret = lms501kf03_power_off(lcd);
if (!ret)
lcd->power = power;
return ret;
}
static int lms501kf03_get_power(struct lcd_device *ld)
{
struct lms501kf03 *lcd = lcd_get_data(ld);
return lcd->power;
}
static int lms501kf03_set_power(struct lcd_device *ld, int power)
{
struct lms501kf03 *lcd = lcd_get_data(ld);
if (power != FB_BLANK_UNBLANK && power != FB_BLANK_POWERDOWN &&
power != FB_BLANK_NORMAL) {
dev_err(lcd->dev, "power value should be 0, 1 or 4.\n");
return -EINVAL;
}
return lms501kf03_power(lcd, power);
}
static int lms501kf03_probe(struct spi_device *spi)
{
struct lms501kf03 *lcd = NULL;
struct lcd_device *ld = NULL;
int ret = 0;
lcd = devm_kzalloc(&spi->dev, sizeof(struct lms501kf03), GFP_KERNEL);
if (!lcd)
return -ENOMEM;
spi->bits_per_word = 9;
ret = spi_setup(spi);
if (ret < 0) {
dev_err(&spi->dev, "spi setup failed.\n");
return ret;
}
lcd->spi = spi;
lcd->dev = &spi->dev;
lcd->lcd_pd = dev_get_platdata(&spi->dev);
if (!lcd->lcd_pd) {
dev_err(&spi->dev, "platform data is NULL\n");
return -EINVAL;
}
ld = devm_lcd_device_register(&spi->dev, "lms501kf03", &spi->dev, lcd,
&lms501kf03_lcd_ops);
if (IS_ERR(ld))
return PTR_ERR(ld);
lcd->ld = ld;
if (!lcd->lcd_pd->lcd_enabled) {
lcd->power = FB_BLANK_POWERDOWN;
lms501kf03_power(lcd, FB_BLANK_UNBLANK);
} else {
lcd->power = FB_BLANK_UNBLANK;
}
spi_set_drvdata(spi, lcd);
dev_info(&spi->dev, "lms501kf03 panel driver has been probed.\n");
return 0;
}
static int lms501kf03_remove(struct spi_device *spi)
{
struct lms501kf03 *lcd = spi_get_drvdata(spi);
lms501kf03_power(lcd, FB_BLANK_POWERDOWN);
return 0;
}
static int lms501kf03_suspend(struct device *dev)
{
struct lms501kf03 *lcd = dev_get_drvdata(dev);
dev_dbg(dev, "lcd->power = %d\n", lcd->power);
return lms501kf03_power(lcd, FB_BLANK_POWERDOWN);
}
static int lms501kf03_resume(struct device *dev)
{
struct lms501kf03 *lcd = dev_get_drvdata(dev);
lcd->power = FB_BLANK_POWERDOWN;
return lms501kf03_power(lcd, FB_BLANK_UNBLANK);
}
static void lms501kf03_shutdown(struct spi_device *spi)
{
struct lms501kf03 *lcd = spi_get_drvdata(spi);
lms501kf03_power(lcd, FB_BLANK_POWERDOWN);
}
