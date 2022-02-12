static int mt6323_led_hw_brightness(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct mt6323_led *led = container_of(cdev, struct mt6323_led, cdev);
struct mt6323_leds *leds = led->parent;
struct regmap *regmap = leds->hw->regmap;
u32 con2_mask = 0, con2_val = 0;
int ret;
con2_mask |= MT6323_ISINK_CH_STEP_MASK |
MT6323_ISINK_SFSTR0_TC_MASK |
MT6323_ISINK_SFSTR0_EN_MASK;
con2_val |= MT6323_ISINK_CH_STEP(brightness - 1) |
MT6323_ISINK_SFSTR0_TC(2) |
MT6323_ISINK_SFSTR0_EN;
ret = regmap_update_bits(regmap, MT6323_ISINK_CON2(led->id),
con2_mask, con2_val);
return ret;
}
static int mt6323_led_hw_off(struct led_classdev *cdev)
{
struct mt6323_led *led = container_of(cdev, struct mt6323_led, cdev);
struct mt6323_leds *leds = led->parent;
struct regmap *regmap = leds->hw->regmap;
unsigned int status;
int ret;
status = MT6323_ISINK_CH_EN(led->id);
ret = regmap_update_bits(regmap, MT6323_ISINK_EN_CTRL,
MT6323_ISINK_CH_EN_MASK(led->id), ~status);
if (ret < 0)
return ret;
usleep_range(100, 300);
ret = regmap_update_bits(regmap, MT6323_TOP_CKPDN2,
MT6323_RG_ISINK_CK_PDN_MASK(led->id),
MT6323_RG_ISINK_CK_PDN(led->id));
if (ret < 0)
return ret;
return 0;
}
static enum led_brightness
mt6323_get_led_hw_brightness(struct led_classdev *cdev)
{
struct mt6323_led *led = container_of(cdev, struct mt6323_led, cdev);
struct mt6323_leds *leds = led->parent;
struct regmap *regmap = leds->hw->regmap;
unsigned int status;
int ret;
ret = regmap_read(regmap, MT6323_TOP_CKPDN2, &status);
if (ret < 0)
return ret;
if (status & MT6323_RG_ISINK_CK_PDN_MASK(led->id))
return 0;
ret = regmap_read(regmap, MT6323_ISINK_EN_CTRL, &status);
if (ret < 0)
return ret;
if (!(status & MT6323_ISINK_CH_EN(led->id)))
return 0;
ret = regmap_read(regmap, MT6323_ISINK_CON2(led->id), &status);
if (ret < 0)
return ret;
return ((status & MT6323_ISINK_CH_STEP_MASK)
>> MT6323_ISINK_CH_STEP_SHIFT) + 1;
}
static int mt6323_led_hw_on(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct mt6323_led *led = container_of(cdev, struct mt6323_led, cdev);
struct mt6323_leds *leds = led->parent;
struct regmap *regmap = leds->hw->regmap;
unsigned int status;
int ret;
ret = regmap_update_bits(regmap, MT6323_TOP_CKCON1,
MT6323_RG_ISINK_CK_SEL_MASK(led->id), 0);
if (ret < 0)
return ret;
status = MT6323_RG_ISINK_CK_PDN(led->id);
ret = regmap_update_bits(regmap, MT6323_TOP_CKPDN2,
MT6323_RG_ISINK_CK_PDN_MASK(led->id),
~status);
if (ret < 0)
return ret;
usleep_range(100, 300);
ret = regmap_update_bits(regmap, MT6323_ISINK_EN_CTRL,
MT6323_ISINK_CH_EN_MASK(led->id),
MT6323_ISINK_CH_EN(led->id));
if (ret < 0)
return ret;
ret = mt6323_led_hw_brightness(cdev, brightness);
if (ret < 0)
return ret;
ret = regmap_update_bits(regmap, MT6323_ISINK_CON0(led->id),
MT6323_ISINK_DIM_DUTY_MASK,
MT6323_ISINK_DIM_DUTY(31));
if (ret < 0)
return ret;
ret = regmap_update_bits(regmap, MT6323_ISINK_CON1(led->id),
MT6323_ISINK_DIM_FSEL_MASK,
MT6323_ISINK_DIM_FSEL(1000));
if (ret < 0)
return ret;
return 0;
}
static int mt6323_led_set_blink(struct led_classdev *cdev,
unsigned long *delay_on,
unsigned long *delay_off)
{
struct mt6323_led *led = container_of(cdev, struct mt6323_led, cdev);
struct mt6323_leds *leds = led->parent;
struct regmap *regmap = leds->hw->regmap;
unsigned long period;
u8 duty_hw;
int ret;
period = *delay_on + *delay_off;
if (period > MT6323_MAX_PERIOD)
return -EINVAL;
if (!*delay_on && !*delay_off) {
*delay_on = 500;
*delay_off = 500;
}
duty_hw = MT6323_CAL_HW_DUTY(*delay_on, period);
if (!duty_hw)
return -EINVAL;
mutex_lock(&leds->lock);
if (!led->current_brightness) {
ret = mt6323_led_hw_on(cdev, cdev->max_brightness);
if (ret < 0)
goto out;
led->current_brightness = cdev->max_brightness;
}
ret = regmap_update_bits(regmap, MT6323_ISINK_CON0(led->id),
MT6323_ISINK_DIM_DUTY_MASK,
MT6323_ISINK_DIM_DUTY(duty_hw - 1));
if (ret < 0)
goto out;
ret = regmap_update_bits(regmap, MT6323_ISINK_CON1(led->id),
MT6323_ISINK_DIM_FSEL_MASK,
MT6323_ISINK_DIM_FSEL(period - 1));
out:
mutex_unlock(&leds->lock);
return ret;
}
static int mt6323_led_set_brightness(struct led_classdev *cdev,
enum led_brightness brightness)
{
struct mt6323_led *led = container_of(cdev, struct mt6323_led, cdev);
struct mt6323_leds *leds = led->parent;
int ret;
mutex_lock(&leds->lock);
if (!led->current_brightness && brightness) {
ret = mt6323_led_hw_on(cdev, brightness);
if (ret < 0)
goto out;
} else if (brightness) {
ret = mt6323_led_hw_brightness(cdev, brightness);
if (ret < 0)
goto out;
} else {
ret = mt6323_led_hw_off(cdev);
if (ret < 0)
goto out;
}
led->current_brightness = brightness;
out:
mutex_unlock(&leds->lock);
return ret;
}
static int mt6323_led_set_dt_default(struct led_classdev *cdev,
struct device_node *np)
{
struct mt6323_led *led = container_of(cdev, struct mt6323_led, cdev);
const char *state;
int ret = 0;
led->cdev.name = of_get_property(np, "label", NULL) ? : np->name;
led->cdev.default_trigger = of_get_property(np,
"linux,default-trigger",
NULL);
state = of_get_property(np, "default-state", NULL);
if (state) {
if (!strcmp(state, "keep")) {
ret = mt6323_get_led_hw_brightness(cdev);
if (ret < 0)
return ret;
led->current_brightness = ret;
ret = 0;
} else if (!strcmp(state, "on")) {
ret =
mt6323_led_set_brightness(cdev, cdev->max_brightness);
} else {
ret = mt6323_led_set_brightness(cdev, LED_OFF);
}
}
return ret;
}
static int mt6323_led_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = pdev->dev.of_node;
struct device_node *child;
struct mt6397_chip *hw = dev_get_drvdata(pdev->dev.parent);
struct mt6323_leds *leds;
struct mt6323_led *led;
int ret;
unsigned int status;
u32 reg;
leds = devm_kzalloc(dev, sizeof(*leds), GFP_KERNEL);
if (!leds)
return -ENOMEM;
platform_set_drvdata(pdev, leds);
leds->dev = dev;
leds->hw = hw;
mutex_init(&leds->lock);
status = MT6323_RG_DRV_32K_CK_PDN;
ret = regmap_update_bits(leds->hw->regmap, MT6323_TOP_CKPDN0,
MT6323_RG_DRV_32K_CK_PDN_MASK, ~status);
if (ret < 0) {
dev_err(leds->dev,
"Failed to update MT6323_TOP_CKPDN0 Register\n");
return ret;
}
for_each_available_child_of_node(np, child) {
ret = of_property_read_u32(child, "reg", &reg);
if (ret) {
dev_err(dev, "Failed to read led 'reg' property\n");
goto put_child_node;
}
if (reg >= MT6323_MAX_LEDS || leds->led[reg]) {
dev_err(dev, "Invalid led reg %u\n", reg);
ret = -EINVAL;
goto put_child_node;
}
led = devm_kzalloc(dev, sizeof(*led), GFP_KERNEL);
if (!led) {
ret = -ENOMEM;
goto put_child_node;
}
leds->led[reg] = led;
leds->led[reg]->id = reg;
leds->led[reg]->cdev.max_brightness = MT6323_MAX_BRIGHTNESS;
leds->led[reg]->cdev.brightness_set_blocking =
mt6323_led_set_brightness;
leds->led[reg]->cdev.blink_set = mt6323_led_set_blink;
leds->led[reg]->cdev.brightness_get =
mt6323_get_led_hw_brightness;
leds->led[reg]->parent = leds;
ret = mt6323_led_set_dt_default(&leds->led[reg]->cdev, child);
if (ret < 0) {
dev_err(leds->dev,
"Failed to LED set default from devicetree\n");
goto put_child_node;
}
ret = devm_led_classdev_register(dev, &leds->led[reg]->cdev);
if (ret) {
dev_err(&pdev->dev, "Failed to register LED: %d\n",
ret);
goto put_child_node;
}
leds->led[reg]->cdev.dev->of_node = child;
}
return 0;
put_child_node:
of_node_put(child);
return ret;
}
static int mt6323_led_remove(struct platform_device *pdev)
{
struct mt6323_leds *leds = platform_get_drvdata(pdev);
int i;
for (i = 0 ; leds->led[i] ; i++)
mt6323_led_hw_off(&leds->led[i]->cdev);
regmap_update_bits(leds->hw->regmap, MT6323_TOP_CKPDN0,
MT6323_RG_DRV_32K_CK_PDN_MASK,
MT6323_RG_DRV_32K_CK_PDN);
mutex_destroy(&leds->lock);
return 0;
}
