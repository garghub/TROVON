static void hd44780_backlight(struct charlcd *lcd, int on)
{
struct hd44780 *hd = lcd->drvdata;
if (hd->pins[PIN_CTRL_BL])
gpiod_set_value_cansleep(hd->pins[PIN_CTRL_BL], on);
}
static void hd44780_strobe_gpio(struct hd44780 *hd)
{
udelay(20);
gpiod_set_value_cansleep(hd->pins[PIN_CTRL_E], 1);
udelay(40);
gpiod_set_value_cansleep(hd->pins[PIN_CTRL_E], 0);
}
static void hd44780_write_gpio8(struct hd44780 *hd, u8 val, unsigned int rs)
{
int values[10];
unsigned int i, n;
for (i = 0; i < 8; i++)
values[PIN_DATA0 + i] = !!(val & BIT(i));
values[PIN_CTRL_RS] = rs;
n = 9;
if (hd->pins[PIN_CTRL_RW]) {
values[PIN_CTRL_RW] = 0;
n++;
}
gpiod_set_array_value_cansleep(n, &hd->pins[PIN_DATA0], values);
hd44780_strobe_gpio(hd);
}
static void hd44780_write_gpio4(struct hd44780 *hd, u8 val, unsigned int rs)
{
int values[10];
unsigned int i, n;
for (i = 4; i < 8; i++)
values[PIN_DATA0 + i] = !!(val & BIT(i));
values[PIN_CTRL_RS] = rs;
n = 5;
if (hd->pins[PIN_CTRL_RW]) {
values[PIN_CTRL_RW] = 0;
n++;
}
gpiod_set_array_value_cansleep(n, &hd->pins[PIN_DATA4],
&values[PIN_DATA4]);
hd44780_strobe_gpio(hd);
for (i = 0; i < 4; i++)
values[PIN_DATA4 + i] = !!(val & BIT(i));
gpiod_set_array_value_cansleep(n, &hd->pins[PIN_DATA4],
&values[PIN_DATA4]);
hd44780_strobe_gpio(hd);
}
static void hd44780_write_cmd_gpio8(struct charlcd *lcd, int cmd)
{
struct hd44780 *hd = lcd->drvdata;
hd44780_write_gpio8(hd, cmd, 0);
udelay(120);
}
static void hd44780_write_data_gpio8(struct charlcd *lcd, int data)
{
struct hd44780 *hd = lcd->drvdata;
hd44780_write_gpio8(hd, data, 1);
udelay(45);
}
static void hd44780_write_cmd_gpio4(struct charlcd *lcd, int cmd)
{
struct hd44780 *hd = lcd->drvdata;
hd44780_write_gpio4(hd, cmd, 0);
udelay(120);
}
static void hd44780_write_cmd_raw_gpio4(struct charlcd *lcd, int cmd)
{
int values[10];
struct hd44780 *hd = lcd->drvdata;
unsigned int i, n;
for (i = 0; i < 4; i++)
values[PIN_DATA4 + i] = !!(cmd & BIT(i));
values[PIN_CTRL_RS] = 0;
n = 5;
if (hd->pins[PIN_CTRL_RW]) {
values[PIN_CTRL_RW] = 0;
n++;
}
gpiod_set_array_value_cansleep(n, &hd->pins[PIN_DATA4],
&values[PIN_DATA4]);
hd44780_strobe_gpio(hd);
}
static void hd44780_write_data_gpio4(struct charlcd *lcd, int data)
{
struct hd44780 *hd = lcd->drvdata;
hd44780_write_gpio4(hd, data, 1);
udelay(45);
}
static int hd44780_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
unsigned int i, base;
struct charlcd *lcd;
struct hd44780 *hd;
int ifwidth, ret;
ifwidth = gpiod_count(dev, "data");
if (ifwidth < 0)
return ifwidth;
switch (ifwidth) {
case 4:
base = PIN_DATA4;
break;
case 8:
base = PIN_DATA0;
break;
default:
return -EINVAL;
}
lcd = charlcd_alloc(sizeof(struct hd44780));
if (!lcd)
return -ENOMEM;
hd = lcd->drvdata;
for (i = 0; i < ifwidth; i++) {
hd->pins[base + i] = devm_gpiod_get_index(dev, "data", i,
GPIOD_OUT_LOW);
if (IS_ERR(hd->pins[base + i])) {
ret = PTR_ERR(hd->pins[base + i]);
goto fail;
}
}
hd->pins[PIN_CTRL_E] = devm_gpiod_get(dev, "enable", GPIOD_OUT_LOW);
if (IS_ERR(hd->pins[PIN_CTRL_E])) {
ret = PTR_ERR(hd->pins[PIN_CTRL_E]);
goto fail;
}
hd->pins[PIN_CTRL_RS] = devm_gpiod_get(dev, "rs", GPIOD_OUT_HIGH);
if (IS_ERR(hd->pins[PIN_CTRL_RS])) {
ret = PTR_ERR(hd->pins[PIN_CTRL_RS]);
goto fail;
}
hd->pins[PIN_CTRL_RW] = devm_gpiod_get_optional(dev, "rw",
GPIOD_OUT_LOW);
if (IS_ERR(hd->pins[PIN_CTRL_RW])) {
ret = PTR_ERR(hd->pins[PIN_CTRL_RW]);
goto fail;
}
hd->pins[PIN_CTRL_BL] = devm_gpiod_get_optional(dev, "backlight",
GPIOD_OUT_LOW);
if (IS_ERR(hd->pins[PIN_CTRL_BL])) {
ret = PTR_ERR(hd->pins[PIN_CTRL_BL]);
goto fail;
}
ret = device_property_read_u32(dev, "display-height-chars",
&lcd->height);
if (ret)
goto fail;
ret = device_property_read_u32(dev, "display-width-chars", &lcd->width);
if (ret)
goto fail;
if (lcd->height > 2)
lcd->bwidth = lcd->width;
device_property_read_u32(dev, "internal-buffer-width", &lcd->bwidth);
lcd->ifwidth = ifwidth;
lcd->ops = ifwidth == 8 ? &hd44780_ops_gpio8 : &hd44780_ops_gpio4;
ret = charlcd_register(lcd);
if (ret)
goto fail;
platform_set_drvdata(pdev, lcd);
return 0;
fail:
kfree(lcd);
return ret;
}
static int hd44780_remove(struct platform_device *pdev)
{
struct charlcd *lcd = platform_get_drvdata(pdev);
charlcd_unregister(lcd);
return 0;
}
