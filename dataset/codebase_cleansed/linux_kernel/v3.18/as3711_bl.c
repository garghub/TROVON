static struct as3711_bl_supply *to_supply(struct as3711_bl_data *su)
{
switch (su->type) {
case AS3711_BL_SU1:
return container_of(su, struct as3711_bl_supply, su1);
case AS3711_BL_SU2:
return container_of(su, struct as3711_bl_supply, su2);
}
return NULL;
}
static int as3711_set_brightness_auto_i(struct as3711_bl_data *data,
unsigned int brightness)
{
struct as3711_bl_supply *supply = to_supply(data);
struct as3711 *as3711 = supply->as3711;
const struct as3711_bl_pdata *pdata = supply->pdata;
int ret = 0;
if (pdata->su2_auto_curr1)
ret = regmap_write(as3711->regmap, AS3711_CURR1_VALUE,
brightness);
if (!ret && pdata->su2_auto_curr2)
ret = regmap_write(as3711->regmap, AS3711_CURR2_VALUE,
brightness);
if (!ret && pdata->su2_auto_curr3)
ret = regmap_write(as3711->regmap, AS3711_CURR3_VALUE,
brightness);
return ret;
}
static int as3711_set_brightness_v(struct as3711 *as3711,
unsigned int brightness,
unsigned int reg)
{
if (brightness > 31)
return -EINVAL;
return regmap_update_bits(as3711->regmap, reg, 0xf0,
brightness << 4);
}
static int as3711_bl_su2_reset(struct as3711_bl_supply *supply)
{
struct as3711 *as3711 = supply->as3711;
int ret = regmap_update_bits(as3711->regmap, AS3711_STEPUP_CONTROL_5,
3, supply->pdata->su2_fbprot);
if (!ret)
ret = regmap_update_bits(as3711->regmap,
AS3711_STEPUP_CONTROL_2, 1, 0);
if (!ret)
ret = regmap_update_bits(as3711->regmap,
AS3711_STEPUP_CONTROL_2, 1, 1);
return ret;
}
static int as3711_bl_update_status(struct backlight_device *bl)
{
struct as3711_bl_data *data = bl_get_data(bl);
struct as3711_bl_supply *supply = to_supply(data);
struct as3711 *as3711 = supply->as3711;
int brightness = bl->props.brightness;
int ret = 0;
dev_dbg(&bl->dev, "%s(): brightness %u, pwr %x, blank %x, state %x\n",
__func__, bl->props.brightness, bl->props.power,
bl->props.fb_blank, bl->props.state);
if (bl->props.power != FB_BLANK_UNBLANK ||
bl->props.fb_blank != FB_BLANK_UNBLANK ||
bl->props.state & (BL_CORE_SUSPENDED | BL_CORE_FBBLANK))
brightness = 0;
if (data->type == AS3711_BL_SU1) {
ret = as3711_set_brightness_v(as3711, brightness,
AS3711_STEPUP_CONTROL_1);
} else {
const struct as3711_bl_pdata *pdata = supply->pdata;
switch (pdata->su2_feedback) {
case AS3711_SU2_VOLTAGE:
ret = as3711_set_brightness_v(as3711, brightness,
AS3711_STEPUP_CONTROL_2);
break;
case AS3711_SU2_CURR_AUTO:
ret = as3711_set_brightness_auto_i(data, brightness / 4);
if (ret < 0)
return ret;
if (brightness) {
ret = as3711_bl_su2_reset(supply);
if (ret < 0)
return ret;
udelay(500);
ret = as3711_set_brightness_auto_i(data, brightness);
} else {
ret = regmap_update_bits(as3711->regmap,
AS3711_STEPUP_CONTROL_2, 1, 0);
}
break;
case AS3711_SU2_CURR1:
ret = regmap_write(as3711->regmap, AS3711_CURR1_VALUE,
brightness);
break;
case AS3711_SU2_CURR2:
ret = regmap_write(as3711->regmap, AS3711_CURR2_VALUE,
brightness);
break;
case AS3711_SU2_CURR3:
ret = regmap_write(as3711->regmap, AS3711_CURR3_VALUE,
brightness);
break;
default:
ret = -EINVAL;
}
}
if (!ret)
data->brightness = brightness;
return ret;
}
static int as3711_bl_get_brightness(struct backlight_device *bl)
{
struct as3711_bl_data *data = bl_get_data(bl);
return data->brightness;
}
static int as3711_bl_init_su2(struct as3711_bl_supply *supply)
{
struct as3711 *as3711 = supply->as3711;
const struct as3711_bl_pdata *pdata = supply->pdata;
u8 ctl = 0;
int ret;
dev_dbg(as3711->dev, "%s(): use %u\n", __func__, pdata->su2_feedback);
ret = regmap_write(as3711->regmap, AS3711_STEPUP_CONTROL_2, 0);
if (ret < 0)
return ret;
switch (pdata->su2_feedback) {
case AS3711_SU2_VOLTAGE:
ret = regmap_update_bits(as3711->regmap, AS3711_STEPUP_CONTROL_4, 3, 0);
break;
case AS3711_SU2_CURR1:
ctl = 1;
ret = regmap_update_bits(as3711->regmap, AS3711_STEPUP_CONTROL_4, 3, 1);
break;
case AS3711_SU2_CURR2:
ctl = 4;
ret = regmap_update_bits(as3711->regmap, AS3711_STEPUP_CONTROL_4, 3, 2);
break;
case AS3711_SU2_CURR3:
ctl = 0x10;
ret = regmap_update_bits(as3711->regmap, AS3711_STEPUP_CONTROL_4, 3, 3);
break;
case AS3711_SU2_CURR_AUTO:
if (pdata->su2_auto_curr1)
ctl = 2;
if (pdata->su2_auto_curr2)
ctl |= 8;
if (pdata->su2_auto_curr3)
ctl |= 0x20;
ret = 0;
break;
default:
return -EINVAL;
}
if (!ret)
ret = regmap_write(as3711->regmap, AS3711_CURR_CONTROL, ctl);
return ret;
}
static int as3711_bl_register(struct platform_device *pdev,
unsigned int max_brightness, struct as3711_bl_data *su)
{
struct backlight_properties props = {.type = BACKLIGHT_RAW,};
struct backlight_device *bl;
props.max_brightness = max_brightness;
bl = devm_backlight_device_register(&pdev->dev,
su->type == AS3711_BL_SU1 ?
"as3711-su1" : "as3711-su2",
&pdev->dev, su,
&as3711_bl_ops, &props);
if (IS_ERR(bl)) {
dev_err(&pdev->dev, "failed to register backlight\n");
return PTR_ERR(bl);
}
bl->props.brightness = props.max_brightness;
backlight_update_status(bl);
su->bl = bl;
return 0;
}
static int as3711_backlight_parse_dt(struct device *dev)
{
struct as3711_bl_pdata *pdata = dev_get_platdata(dev);
struct device_node *bl =
of_find_node_by_name(dev->parent->of_node, "backlight"), *fb;
int ret;
if (!bl) {
dev_dbg(dev, "backlight node not found\n");
return -ENODEV;
}
fb = of_parse_phandle(bl, "su1-dev", 0);
if (fb) {
pdata->su1_fb = fb->full_name;
ret = of_property_read_u32(bl, "su1-max-uA", &pdata->su1_max_uA);
if (pdata->su1_max_uA <= 0)
ret = -EINVAL;
if (ret < 0)
return ret;
}
fb = of_parse_phandle(bl, "su2-dev", 0);
if (fb) {
int count = 0;
pdata->su2_fb = fb->full_name;
ret = of_property_read_u32(bl, "su2-max-uA", &pdata->su2_max_uA);
if (pdata->su2_max_uA <= 0)
ret = -EINVAL;
if (ret < 0)
return ret;
if (of_find_property(bl, "su2-feedback-voltage", NULL)) {
pdata->su2_feedback = AS3711_SU2_VOLTAGE;
count++;
}
if (of_find_property(bl, "su2-feedback-curr1", NULL)) {
pdata->su2_feedback = AS3711_SU2_CURR1;
count++;
}
if (of_find_property(bl, "su2-feedback-curr2", NULL)) {
pdata->su2_feedback = AS3711_SU2_CURR2;
count++;
}
if (of_find_property(bl, "su2-feedback-curr3", NULL)) {
pdata->su2_feedback = AS3711_SU2_CURR3;
count++;
}
if (of_find_property(bl, "su2-feedback-curr-auto", NULL)) {
pdata->su2_feedback = AS3711_SU2_CURR_AUTO;
count++;
}
if (count != 1)
return -EINVAL;
count = 0;
if (of_find_property(bl, "su2-fbprot-lx-sd4", NULL)) {
pdata->su2_fbprot = AS3711_SU2_LX_SD4;
count++;
}
if (of_find_property(bl, "su2-fbprot-gpio2", NULL)) {
pdata->su2_fbprot = AS3711_SU2_GPIO2;
count++;
}
if (of_find_property(bl, "su2-fbprot-gpio3", NULL)) {
pdata->su2_fbprot = AS3711_SU2_GPIO3;
count++;
}
if (of_find_property(bl, "su2-fbprot-gpio4", NULL)) {
pdata->su2_fbprot = AS3711_SU2_GPIO4;
count++;
}
if (count != 1)
return -EINVAL;
count = 0;
if (of_find_property(bl, "su2-auto-curr1", NULL)) {
pdata->su2_auto_curr1 = true;
count++;
}
if (of_find_property(bl, "su2-auto-curr2", NULL)) {
pdata->su2_auto_curr2 = true;
count++;
}
if (of_find_property(bl, "su2-auto-curr3", NULL)) {
pdata->su2_auto_curr3 = true;
count++;
}
if (!count ^ (pdata->su2_feedback != AS3711_SU2_CURR_AUTO))
return -EINVAL;
}
return 0;
}
static int as3711_backlight_probe(struct platform_device *pdev)
{
struct as3711_bl_pdata *pdata = dev_get_platdata(&pdev->dev);
struct as3711 *as3711 = dev_get_drvdata(pdev->dev.parent);
struct as3711_bl_supply *supply;
struct as3711_bl_data *su;
unsigned int max_brightness;
int ret;
if (!pdata) {
dev_err(&pdev->dev, "No platform data, exiting...\n");
return -ENODEV;
}
if (pdev->dev.parent->of_node) {
ret = as3711_backlight_parse_dt(&pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "DT parsing failed: %d\n", ret);
return ret;
}
}
if (!pdata->su1_fb && !pdata->su2_fb) {
dev_err(&pdev->dev, "No framebuffer specified\n");
return -EINVAL;
}
if (pdata->su1_fb ||
pdata->su2_fbprot != AS3711_SU2_GPIO4 ||
pdata->su2_feedback != AS3711_SU2_CURR_AUTO) {
dev_warn(&pdev->dev,
"Attention! An untested mode has been chosen!\n"
"Please, review the code, enable, test, and report success:-)\n");
return -EINVAL;
}
supply = devm_kzalloc(&pdev->dev, sizeof(*supply), GFP_KERNEL);
if (!supply)
return -ENOMEM;
supply->as3711 = as3711;
supply->pdata = pdata;
if (pdata->su1_fb) {
su = &supply->su1;
su->fb_name = pdata->su1_fb;
su->type = AS3711_BL_SU1;
max_brightness = min(pdata->su1_max_uA, 31);
ret = as3711_bl_register(pdev, max_brightness, su);
if (ret < 0)
return ret;
}
if (pdata->su2_fb) {
su = &supply->su2;
su->fb_name = pdata->su2_fb;
su->type = AS3711_BL_SU2;
switch (pdata->su2_fbprot) {
case AS3711_SU2_GPIO2:
case AS3711_SU2_GPIO3:
case AS3711_SU2_GPIO4:
case AS3711_SU2_LX_SD4:
break;
default:
return -EINVAL;
}
switch (pdata->su2_feedback) {
case AS3711_SU2_VOLTAGE:
max_brightness = min(pdata->su2_max_uA, 31);
break;
case AS3711_SU2_CURR1:
case AS3711_SU2_CURR2:
case AS3711_SU2_CURR3:
case AS3711_SU2_CURR_AUTO:
max_brightness = min(pdata->su2_max_uA / 150, 255);
break;
default:
return -EINVAL;
}
ret = as3711_bl_init_su2(supply);
if (ret < 0)
return ret;
ret = as3711_bl_register(pdev, max_brightness, su);
if (ret < 0)
return ret;
}
platform_set_drvdata(pdev, supply);
return 0;
}
