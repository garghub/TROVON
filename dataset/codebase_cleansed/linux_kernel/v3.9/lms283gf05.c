static void lms283gf05_reset(unsigned long gpio, bool inverted)
{
gpio_set_value(gpio, !inverted);
mdelay(100);
gpio_set_value(gpio, inverted);
mdelay(20);
gpio_set_value(gpio, !inverted);
mdelay(20);
}
static void lms283gf05_toggle(struct spi_device *spi,
const struct lms283gf05_seq *seq, int sz)
{
char buf[3];
int i;
for (i = 0; i < sz; i++) {
buf[0] = 0x74;
buf[1] = 0x00;
buf[2] = seq[i].reg;
spi_write(spi, buf, 3);
buf[0] = 0x76;
buf[1] = seq[i].value >> 8;
buf[2] = seq[i].value & 0xff;
spi_write(spi, buf, 3);
mdelay(seq[i].delay);
}
}
static int lms283gf05_power_set(struct lcd_device *ld, int power)
{
struct lms283gf05_state *st = lcd_get_data(ld);
struct spi_device *spi = st->spi;
struct lms283gf05_pdata *pdata = spi->dev.platform_data;
if (power <= FB_BLANK_NORMAL) {
if (pdata)
lms283gf05_reset(pdata->reset_gpio,
pdata->reset_inverted);
lms283gf05_toggle(spi, disp_initseq, ARRAY_SIZE(disp_initseq));
} else {
lms283gf05_toggle(spi, disp_pdwnseq, ARRAY_SIZE(disp_pdwnseq));
if (pdata)
gpio_set_value(pdata->reset_gpio,
pdata->reset_inverted);
}
return 0;
}
static int lms283gf05_probe(struct spi_device *spi)
{
struct lms283gf05_state *st;
struct lms283gf05_pdata *pdata = spi->dev.platform_data;
struct lcd_device *ld;
int ret = 0;
if (pdata != NULL) {
ret = devm_gpio_request_one(&spi->dev, pdata->reset_gpio,
GPIOF_DIR_OUT | (!pdata->reset_inverted ?
GPIOF_INIT_HIGH : GPIOF_INIT_LOW),
"LMS285GF05 RESET");
if (ret)
return ret;
}
st = devm_kzalloc(&spi->dev, sizeof(struct lms283gf05_state),
GFP_KERNEL);
if (st == NULL) {
dev_err(&spi->dev, "No memory for device state\n");
return -ENOMEM;
}
ld = lcd_device_register("lms283gf05", &spi->dev, st, &lms_ops);
if (IS_ERR(ld))
return PTR_ERR(ld);
st->spi = spi;
st->ld = ld;
spi_set_drvdata(spi, st);
if (pdata)
lms283gf05_reset(pdata->reset_gpio, pdata->reset_inverted);
lms283gf05_toggle(spi, disp_initseq, ARRAY_SIZE(disp_initseq));
return 0;
}
static int lms283gf05_remove(struct spi_device *spi)
{
struct lms283gf05_state *st = spi_get_drvdata(spi);
lcd_device_unregister(st->ld);
return 0;
}
