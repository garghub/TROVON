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
struct lms283gf05_seq *seq, int sz)
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
static int __devinit lms283gf05_probe(struct spi_device *spi)
{
struct lms283gf05_state *st;
struct lms283gf05_pdata *pdata = spi->dev.platform_data;
struct lcd_device *ld;
int ret = 0;
if (pdata != NULL) {
ret = gpio_request(pdata->reset_gpio, "LMS285GF05 RESET");
if (ret)
return ret;
ret = gpio_direction_output(pdata->reset_gpio,
!pdata->reset_inverted);
if (ret)
goto err;
}
st = kzalloc(sizeof(struct lms283gf05_state), GFP_KERNEL);
if (st == NULL) {
dev_err(&spi->dev, "No memory for device state\n");
ret = -ENOMEM;
goto err;
}
ld = lcd_device_register("lms283gf05", &spi->dev, st, &lms_ops);
if (IS_ERR(ld)) {
ret = PTR_ERR(ld);
goto err2;
}
st->spi = spi;
st->ld = ld;
dev_set_drvdata(&spi->dev, st);
if (pdata)
lms283gf05_reset(pdata->reset_gpio, pdata->reset_inverted);
lms283gf05_toggle(spi, disp_initseq, ARRAY_SIZE(disp_initseq));
return 0;
err2:
kfree(st);
err:
if (pdata != NULL)
gpio_free(pdata->reset_gpio);
return ret;
}
static int __devexit lms283gf05_remove(struct spi_device *spi)
{
struct lms283gf05_state *st = dev_get_drvdata(&spi->dev);
struct lms283gf05_pdata *pdata = st->spi->dev.platform_data;
lcd_device_unregister(st->ld);
if (pdata != NULL)
gpio_free(pdata->reset_gpio);
kfree(st);
return 0;
}
