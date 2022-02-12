static inline struct gpio_twl4030_priv *to_gpio_twl4030(struct gpio_chip *chip)
{
return container_of(chip, struct gpio_twl4030_priv, gpio_chip);
}
static inline int gpio_twl4030_write(u8 address, u8 data)
{
return twl_i2c_write_u8(TWL4030_MODULE_GPIO, data, address);
}
static inline int gpio_twl4030_read(u8 address)
{
u8 data;
int ret = 0;
ret = twl_i2c_read_u8(TWL4030_MODULE_GPIO, &data, address);
return (ret < 0) ? ret : data;
}
static void twl4030_led_set_value(int led, int value)
{
u8 mask = LEDEN_LEDAON | LEDEN_LEDAPWM;
int status;
if (led)
mask <<= 1;
if (value)
cached_leden &= ~mask;
else
cached_leden |= mask;
status = twl_i2c_write_u8(TWL4030_MODULE_LED, cached_leden,
TWL4030_LED_LEDEN_REG);
}
static int twl4030_set_gpio_direction(int gpio, int is_input)
{
u8 d_bnk = gpio >> 3;
u8 d_msk = BIT(gpio & 0x7);
u8 reg = 0;
u8 base = REG_GPIODATADIR1 + d_bnk;
int ret = 0;
ret = gpio_twl4030_read(base);
if (ret >= 0) {
if (is_input)
reg = ret & ~d_msk;
else
reg = ret | d_msk;
ret = gpio_twl4030_write(base, reg);
}
return ret;
}
static int twl4030_set_gpio_dataout(int gpio, int enable)
{
u8 d_bnk = gpio >> 3;
u8 d_msk = BIT(gpio & 0x7);
u8 base = 0;
if (enable)
base = REG_SETGPIODATAOUT1 + d_bnk;
else
base = REG_CLEARGPIODATAOUT1 + d_bnk;
return gpio_twl4030_write(base, d_msk);
}
static int twl4030_get_gpio_datain(int gpio)
{
u8 d_bnk = gpio >> 3;
u8 d_off = gpio & 0x7;
u8 base = 0;
int ret = 0;
base = REG_GPIODATAIN1 + d_bnk;
ret = gpio_twl4030_read(base);
if (ret > 0)
ret = (ret >> d_off) & 0x1;
return ret;
}
static int twl_request(struct gpio_chip *chip, unsigned offset)
{
struct gpio_twl4030_priv *priv = to_gpio_twl4030(chip);
int status = 0;
mutex_lock(&priv->mutex);
if (offset >= TWL4030_GPIO_MAX) {
u8 ledclr_mask = LEDEN_LEDAON | LEDEN_LEDAEXT
| LEDEN_LEDAPWM | LEDEN_PWM_LENGTHA;
u8 reg = TWL4030_PWMAON_REG;
offset -= TWL4030_GPIO_MAX;
if (offset) {
ledclr_mask <<= 1;
reg = TWL4030_PWMBON_REG;
}
status = twl_i2c_write_u8(TWL4030_MODULE_LED, 0x7f, reg + 1);
if (status < 0)
goto done;
status = twl_i2c_write_u8(TWL4030_MODULE_LED, 0x7f, reg);
if (status < 0)
goto done;
status = twl_i2c_read_u8(TWL4030_MODULE_LED, &cached_leden,
TWL4030_LED_LEDEN_REG);
if (status < 0)
goto done;
cached_leden &= ~ledclr_mask;
status = twl_i2c_write_u8(TWL4030_MODULE_LED, cached_leden,
TWL4030_LED_LEDEN_REG);
if (status < 0)
goto done;
status = 0;
goto done;
}
if (!priv->usage_count) {
struct twl4030_gpio_platform_data *pdata;
u8 value = MASK_GPIO_CTRL_GPIO_ON;
pdata = dev_get_platdata(chip->dev);
if (pdata)
value |= pdata->mmc_cd & 0x03;
status = gpio_twl4030_write(REG_GPIO_CTRL, value);
}
done:
if (!status)
priv->usage_count |= BIT(offset);
mutex_unlock(&priv->mutex);
return status;
}
static void twl_free(struct gpio_chip *chip, unsigned offset)
{
struct gpio_twl4030_priv *priv = to_gpio_twl4030(chip);
mutex_lock(&priv->mutex);
if (offset >= TWL4030_GPIO_MAX) {
twl4030_led_set_value(offset - TWL4030_GPIO_MAX, 1);
goto out;
}
priv->usage_count &= ~BIT(offset);
if (!priv->usage_count)
gpio_twl4030_write(REG_GPIO_CTRL, 0x0);
out:
mutex_unlock(&priv->mutex);
}
static int twl_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct gpio_twl4030_priv *priv = to_gpio_twl4030(chip);
int ret;
mutex_lock(&priv->mutex);
if (offset < TWL4030_GPIO_MAX)
ret = twl4030_set_gpio_direction(offset, 1);
else
ret = -EINVAL;
if (!ret)
priv->direction &= ~BIT(offset);
mutex_unlock(&priv->mutex);
return ret;
}
static int twl_get(struct gpio_chip *chip, unsigned offset)
{
struct gpio_twl4030_priv *priv = to_gpio_twl4030(chip);
int ret;
int status = 0;
mutex_lock(&priv->mutex);
if (!(priv->usage_count & BIT(offset))) {
ret = -EPERM;
goto out;
}
if (priv->direction & BIT(offset))
status = priv->out_state & BIT(offset);
else
status = twl4030_get_gpio_datain(offset);
ret = (status <= 0) ? 0 : 1;
out:
mutex_unlock(&priv->mutex);
return ret;
}
static void twl_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct gpio_twl4030_priv *priv = to_gpio_twl4030(chip);
mutex_lock(&priv->mutex);
if (offset < TWL4030_GPIO_MAX)
twl4030_set_gpio_dataout(offset, value);
else
twl4030_led_set_value(offset - TWL4030_GPIO_MAX, value);
if (value)
priv->out_state |= BIT(offset);
else
priv->out_state &= ~BIT(offset);
mutex_unlock(&priv->mutex);
}
static int twl_direction_out(struct gpio_chip *chip, unsigned offset, int value)
{
struct gpio_twl4030_priv *priv = to_gpio_twl4030(chip);
int ret = 0;
mutex_lock(&priv->mutex);
if (offset < TWL4030_GPIO_MAX) {
ret = twl4030_set_gpio_direction(offset, 0);
if (ret) {
mutex_unlock(&priv->mutex);
return ret;
}
}
priv->direction |= BIT(offset);
mutex_unlock(&priv->mutex);
twl_set(chip, offset, value);
return ret;
}
static int twl_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct gpio_twl4030_priv *priv = to_gpio_twl4030(chip);
return (priv->irq_base && (offset < TWL4030_GPIO_MAX))
? (priv->irq_base + offset)
: -EINVAL;
}
static int gpio_twl4030_pulls(u32 ups, u32 downs)
{
u8 message[5];
unsigned i, gpio_bit;
for (gpio_bit = 1, i = 0; i < 5; i++) {
u8 bit_mask;
unsigned j;
for (bit_mask = 0, j = 0; j < 8; j += 2, gpio_bit <<= 1) {
if (ups & gpio_bit)
bit_mask |= 1 << (j + 1);
else if (downs & gpio_bit)
bit_mask |= 1 << (j + 0);
}
message[i] = bit_mask;
}
return twl_i2c_write(TWL4030_MODULE_GPIO, message,
REG_GPIOPUPDCTR1, 5);
}
static int gpio_twl4030_debounce(u32 debounce, u8 mmc_cd)
{
u8 message[3];
message[0] = (debounce & 0xff) | (mmc_cd & 0x03);
debounce >>= 8;
message[1] = (debounce & 0xff);
debounce >>= 8;
message[2] = (debounce & 0x03);
return twl_i2c_write(TWL4030_MODULE_GPIO, message,
REG_GPIO_DEBEN1, 3);
}
static struct twl4030_gpio_platform_data *of_gpio_twl4030(struct device *dev,
struct twl4030_gpio_platform_data *pdata)
{
struct twl4030_gpio_platform_data *omap_twl_info;
omap_twl_info = devm_kzalloc(dev, sizeof(*omap_twl_info), GFP_KERNEL);
if (!omap_twl_info)
return NULL;
if (pdata)
*omap_twl_info = *pdata;
omap_twl_info->use_leds = of_property_read_bool(dev->of_node,
"ti,use-leds");
of_property_read_u32(dev->of_node, "ti,debounce",
&omap_twl_info->debounce);
of_property_read_u32(dev->of_node, "ti,mmc-cd",
(u32 *)&omap_twl_info->mmc_cd);
of_property_read_u32(dev->of_node, "ti,pullups",
&omap_twl_info->pullups);
of_property_read_u32(dev->of_node, "ti,pulldowns",
&omap_twl_info->pulldowns);
return omap_twl_info;
}
static int gpio_twl4030_probe(struct platform_device *pdev)
{
struct twl4030_gpio_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct device_node *node = pdev->dev.of_node;
struct gpio_twl4030_priv *priv;
int ret, irq_base;
priv = devm_kzalloc(&pdev->dev, sizeof(struct gpio_twl4030_priv),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (is_module()) {
dev_err(&pdev->dev, "can't dispatch IRQs from modules\n");
goto no_irqs;
}
irq_base = irq_alloc_descs(-1, 0, TWL4030_GPIO_MAX, 0);
if (irq_base < 0) {
dev_err(&pdev->dev, "Failed to alloc irq_descs\n");
return irq_base;
}
irq_domain_add_legacy(node, TWL4030_GPIO_MAX, irq_base, 0,
&irq_domain_simple_ops, NULL);
ret = twl4030_sih_setup(&pdev->dev, TWL4030_MODULE_GPIO, irq_base);
if (ret < 0)
return ret;
priv->irq_base = irq_base;
no_irqs:
priv->gpio_chip = template_chip;
priv->gpio_chip.base = -1;
priv->gpio_chip.ngpio = TWL4030_GPIO_MAX;
priv->gpio_chip.dev = &pdev->dev;
mutex_init(&priv->mutex);
if (node)
pdata = of_gpio_twl4030(&pdev->dev, pdata);
if (pdata == NULL) {
dev_err(&pdev->dev, "Platform data is missing\n");
return -ENXIO;
}
ret = gpio_twl4030_pulls(pdata->pullups, pdata->pulldowns);
if (ret)
dev_dbg(&pdev->dev, "pullups %.05x %.05x --> %d\n",
pdata->pullups, pdata->pulldowns, ret);
ret = gpio_twl4030_debounce(pdata->debounce, pdata->mmc_cd);
if (ret)
dev_dbg(&pdev->dev, "debounce %.03x %.01x --> %d\n",
pdata->debounce, pdata->mmc_cd, ret);
if (pdata->use_leds)
priv->gpio_chip.ngpio += 2;
ret = gpiochip_add(&priv->gpio_chip);
if (ret < 0) {
dev_err(&pdev->dev, "could not register gpiochip, %d\n", ret);
priv->gpio_chip.ngpio = 0;
gpio_twl4030_remove(pdev);
goto out;
}
platform_set_drvdata(pdev, priv);
if (pdata && pdata->setup) {
int status;
status = pdata->setup(&pdev->dev, priv->gpio_chip.base,
TWL4030_GPIO_MAX);
if (status)
dev_dbg(&pdev->dev, "setup --> %d\n", status);
}
out:
return ret;
}
static int gpio_twl4030_remove(struct platform_device *pdev)
{
struct twl4030_gpio_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct gpio_twl4030_priv *priv = platform_get_drvdata(pdev);
int status;
if (pdata && pdata->teardown) {
status = pdata->teardown(&pdev->dev, priv->gpio_chip.base,
TWL4030_GPIO_MAX);
if (status) {
dev_dbg(&pdev->dev, "teardown --> %d\n", status);
return status;
}
}
status = gpiochip_remove(&priv->gpio_chip);
if (status < 0)
return status;
if (is_module())
return 0;
WARN_ON(1);
return -EIO;
}
static int __init gpio_twl4030_init(void)
{
return platform_driver_register(&gpio_twl4030_driver);
}
static void __exit gpio_twl4030_exit(void)
{
platform_driver_unregister(&gpio_twl4030_driver);
}
