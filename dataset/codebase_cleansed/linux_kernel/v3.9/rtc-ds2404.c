static int ds2404_gpio_map(struct ds2404 *chip, struct platform_device *pdev,
struct ds2404_platform_data *pdata)
{
int i, err;
ds2404_gpio[DS2404_RST].gpio = pdata->gpio_rst;
ds2404_gpio[DS2404_CLK].gpio = pdata->gpio_clk;
ds2404_gpio[DS2404_DQ].gpio = pdata->gpio_dq;
for (i = 0; i < ARRAY_SIZE(ds2404_gpio); i++) {
err = gpio_request(ds2404_gpio[i].gpio, ds2404_gpio[i].name);
if (err) {
dev_err(&pdev->dev, "error mapping gpio %s: %d\n",
ds2404_gpio[i].name, err);
goto err_request;
}
if (i != DS2404_DQ)
gpio_direction_output(ds2404_gpio[i].gpio, 1);
}
chip->gpio = ds2404_gpio;
return 0;
err_request:
while (--i >= 0)
gpio_free(ds2404_gpio[i].gpio);
return err;
}
static void ds2404_gpio_unmap(struct ds2404 *chip)
{
int i;
for (i = 0; i < ARRAY_SIZE(ds2404_gpio); i++)
gpio_free(ds2404_gpio[i].gpio);
}
static void ds2404_reset(struct device *dev)
{
gpio_set_value(ds2404_gpio[DS2404_RST].gpio, 0);
udelay(1000);
gpio_set_value(ds2404_gpio[DS2404_RST].gpio, 1);
gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 0);
gpio_direction_output(ds2404_gpio[DS2404_DQ].gpio, 0);
udelay(10);
}
static void ds2404_write_byte(struct device *dev, u8 byte)
{
int i;
gpio_direction_output(ds2404_gpio[DS2404_DQ].gpio, 1);
for (i = 0; i < 8; i++) {
gpio_set_value(ds2404_gpio[DS2404_DQ].gpio, byte & (1 << i));
udelay(10);
gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 1);
udelay(10);
gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 0);
udelay(10);
}
}
static u8 ds2404_read_byte(struct device *dev)
{
int i;
u8 ret = 0;
gpio_direction_input(ds2404_gpio[DS2404_DQ].gpio);
for (i = 0; i < 8; i++) {
gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 0);
udelay(10);
if (gpio_get_value(ds2404_gpio[DS2404_DQ].gpio))
ret |= 1 << i;
gpio_set_value(ds2404_gpio[DS2404_CLK].gpio, 1);
udelay(10);
}
return ret;
}
static void ds2404_read_memory(struct device *dev, u16 offset,
int length, u8 *out)
{
ds2404_reset(dev);
ds2404_write_byte(dev, DS2404_READ_MEMORY_CMD);
ds2404_write_byte(dev, offset & 0xff);
ds2404_write_byte(dev, (offset >> 8) & 0xff);
while (length--)
*out++ = ds2404_read_byte(dev);
}
static void ds2404_write_memory(struct device *dev, u16 offset,
int length, u8 *out)
{
int i;
u8 ta01, ta02, es;
ds2404_reset(dev);
ds2404_write_byte(dev, DS2404_WRITE_SCRATCHPAD_CMD);
ds2404_write_byte(dev, offset & 0xff);
ds2404_write_byte(dev, (offset >> 8) & 0xff);
for (i = 0; i < length; i++)
ds2404_write_byte(dev, out[i]);
ds2404_reset(dev);
ds2404_write_byte(dev, DS2404_READ_SCRATCHPAD_CMD);
ta01 = ds2404_read_byte(dev);
ta02 = ds2404_read_byte(dev);
es = ds2404_read_byte(dev);
for (i = 0; i < length; i++) {
if (out[i] != ds2404_read_byte(dev)) {
dev_err(dev, "read invalid data\n");
return;
}
}
ds2404_reset(dev);
ds2404_write_byte(dev, DS2404_COPY_SCRATCHPAD_CMD);
ds2404_write_byte(dev, ta01);
ds2404_write_byte(dev, ta02);
ds2404_write_byte(dev, es);
gpio_direction_input(ds2404_gpio[DS2404_DQ].gpio);
while (gpio_get_value(ds2404_gpio[DS2404_DQ].gpio))
;
}
static void ds2404_enable_osc(struct device *dev)
{
u8 in[1] = { 0x10 };
ds2404_write_memory(dev, 0x201, 1, in);
}
static int ds2404_read_time(struct device *dev, struct rtc_time *dt)
{
unsigned long time = 0;
ds2404_read_memory(dev, 0x203, 4, (u8 *)&time);
time = le32_to_cpu(time);
rtc_time_to_tm(time, dt);
return rtc_valid_tm(dt);
}
static int ds2404_set_mmss(struct device *dev, unsigned long secs)
{
u32 time = cpu_to_le32(secs);
ds2404_write_memory(dev, 0x203, 4, (u8 *)&time);
return 0;
}
static int rtc_probe(struct platform_device *pdev)
{
struct ds2404_platform_data *pdata = pdev->dev.platform_data;
struct ds2404 *chip;
int retval = -EBUSY;
chip = kzalloc(sizeof(struct ds2404), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->ops = &ds2404_gpio_ops;
retval = chip->ops->map_io(chip, pdev, pdata);
if (retval)
goto err_chip;
dev_info(&pdev->dev, "using GPIOs RST:%d, CLK:%d, DQ:%d\n",
chip->gpio[DS2404_RST].gpio, chip->gpio[DS2404_CLK].gpio,
chip->gpio[DS2404_DQ].gpio);
platform_set_drvdata(pdev, chip);
chip->rtc = rtc_device_register("ds2404",
&pdev->dev, &ds2404_rtc_ops, THIS_MODULE);
if (IS_ERR(chip->rtc)) {
retval = PTR_ERR(chip->rtc);
goto err_io;
}
ds2404_enable_osc(&pdev->dev);
return 0;
err_io:
chip->ops->unmap_io(chip);
err_chip:
kfree(chip);
return retval;
}
static int rtc_remove(struct platform_device *dev)
{
struct ds2404 *chip = platform_get_drvdata(dev);
struct rtc_device *rtc = chip->rtc;
if (rtc)
rtc_device_unregister(rtc);
chip->ops->unmap_io(chip);
kfree(chip);
return 0;
}
