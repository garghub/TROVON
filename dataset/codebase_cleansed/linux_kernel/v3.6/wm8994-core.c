int wm8994_reg_read(struct wm8994 *wm8994, unsigned short reg)
{
unsigned int val;
int ret;
ret = regmap_read(wm8994->regmap, reg, &val);
if (ret < 0)
return ret;
else
return val;
}
int wm8994_bulk_read(struct wm8994 *wm8994, unsigned short reg,
int count, u16 *buf)
{
return regmap_bulk_read(wm8994->regmap, reg, buf, count);
}
int wm8994_reg_write(struct wm8994 *wm8994, unsigned short reg,
unsigned short val)
{
return regmap_write(wm8994->regmap, reg, val);
}
int wm8994_bulk_write(struct wm8994 *wm8994, unsigned short reg,
int count, const u16 *buf)
{
return regmap_raw_write(wm8994->regmap, reg, buf, count * sizeof(u16));
}
int wm8994_set_bits(struct wm8994 *wm8994, unsigned short reg,
unsigned short mask, unsigned short val)
{
return regmap_update_bits(wm8994->regmap, reg, mask, val);
}
static int wm8994_suspend(struct device *dev)
{
struct wm8994 *wm8994 = dev_get_drvdata(dev);
int ret;
ret = wm8994_reg_read(wm8994, WM8994_POWER_MANAGEMENT_1);
if (ret < 0) {
dev_err(dev, "Failed to read power status: %d\n", ret);
} else if (ret & WM8994_VMID_SEL_MASK) {
dev_dbg(dev, "CODEC still active, ignoring suspend\n");
return 0;
}
ret = wm8994_reg_read(wm8994, WM8994_POWER_MANAGEMENT_4);
if (ret < 0) {
dev_err(dev, "Failed to read power status: %d\n", ret);
} else if (ret & (WM8994_AIF2ADCL_ENA | WM8994_AIF2ADCR_ENA |
WM8994_AIF1ADC2L_ENA | WM8994_AIF1ADC2R_ENA |
WM8994_AIF1ADC1L_ENA | WM8994_AIF1ADC1R_ENA)) {
dev_dbg(dev, "CODEC still active, ignoring suspend\n");
return 0;
}
ret = wm8994_reg_read(wm8994, WM8994_POWER_MANAGEMENT_5);
if (ret < 0) {
dev_err(dev, "Failed to read power status: %d\n", ret);
} else if (ret & (WM8994_AIF2DACL_ENA | WM8994_AIF2DACR_ENA |
WM8994_AIF1DAC2L_ENA | WM8994_AIF1DAC2R_ENA |
WM8994_AIF1DAC1L_ENA | WM8994_AIF1DAC1R_ENA)) {
dev_dbg(dev, "CODEC still active, ignoring suspend\n");
return 0;
}
switch (wm8994->type) {
case WM8958:
case WM1811:
ret = wm8994_reg_read(wm8994, WM8958_MIC_DETECT_1);
if (ret < 0) {
dev_err(dev, "Failed to read power status: %d\n", ret);
} else if (ret & WM8958_MICD_ENA) {
dev_dbg(dev, "CODEC still active, ignoring suspend\n");
return 0;
}
break;
default:
break;
}
switch (wm8994->type) {
case WM1811:
ret = wm8994_reg_read(wm8994, WM8994_ANTIPOP_2);
if (ret < 0) {
dev_err(dev, "Failed to read jackdet: %d\n", ret);
} else if (ret & WM1811_JACKDET_MODE_MASK) {
dev_dbg(dev, "CODEC still active, ignoring suspend\n");
return 0;
}
break;
default:
break;
}
switch (wm8994->type) {
case WM1811:
ret = wm8994_reg_read(wm8994, WM8994_ANTIPOP_2);
if (ret < 0) {
dev_err(dev, "Failed to read jackdet: %d\n", ret);
} else if (ret & WM1811_JACKDET_MODE_MASK) {
dev_dbg(dev, "CODEC still active, ignoring suspend\n");
return 0;
}
break;
default:
break;
}
if (!wm8994->ldo_ena_always_driven)
wm8994_set_bits(wm8994, WM8994_PULL_CONTROL_2,
WM8994_LDO1ENA_PD | WM8994_LDO2ENA_PD,
WM8994_LDO1ENA_PD | WM8994_LDO2ENA_PD);
wm8994_reg_write(wm8994, WM8994_SOFTWARE_RESET,
wm8994_reg_read(wm8994, WM8994_SOFTWARE_RESET));
regcache_mark_dirty(wm8994->regmap);
ret = regcache_sync_region(wm8994->regmap, WM8994_GPIO_1,
WM8994_GPIO_11);
if (ret != 0)
dev_err(dev, "Failed to restore GPIO registers: %d\n", ret);
ret = regcache_sync_region(wm8994->regmap,
WM8994_INTERRUPT_STATUS_1_MASK,
WM8994_INTERRUPT_STATUS_1_MASK);
if (ret != 0)
dev_err(dev, "Failed to restore interrupt mask: %d\n", ret);
regcache_cache_only(wm8994->regmap, true);
wm8994->suspended = true;
ret = regulator_bulk_disable(wm8994->num_supplies,
wm8994->supplies);
if (ret != 0) {
dev_err(dev, "Failed to disable supplies: %d\n", ret);
return ret;
}
return 0;
}
static int wm8994_resume(struct device *dev)
{
struct wm8994 *wm8994 = dev_get_drvdata(dev);
int ret;
if (!wm8994->suspended)
return 0;
ret = regulator_bulk_enable(wm8994->num_supplies,
wm8994->supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable supplies: %d\n", ret);
return ret;
}
regcache_cache_only(wm8994->regmap, false);
ret = regcache_sync(wm8994->regmap);
if (ret != 0) {
dev_err(dev, "Failed to restore register map: %d\n", ret);
goto err_enable;
}
wm8994_set_bits(wm8994, WM8994_PULL_CONTROL_2,
WM8994_LDO1ENA_PD | WM8994_LDO2ENA_PD,
0);
wm8994->suspended = false;
return 0;
err_enable:
regulator_bulk_disable(wm8994->num_supplies, wm8994->supplies);
return ret;
}
static int wm8994_ldo_in_use(struct wm8994_pdata *pdata, int ldo)
{
struct wm8994_ldo_pdata *ldo_pdata;
if (!pdata)
return 0;
ldo_pdata = &pdata->ldo[ldo];
if (!ldo_pdata->init_data)
return 0;
return ldo_pdata->init_data->num_consumer_supplies != 0;
}
static int wm8994_ldo_in_use(struct wm8994_pdata *pdata, int ldo)
{
return 0;
}
static __devinit int wm8994_device_init(struct wm8994 *wm8994, int irq)
{
struct wm8994_pdata *pdata = wm8994->dev->platform_data;
struct regmap_config *regmap_config;
const struct reg_default *regmap_patch = NULL;
const char *devname;
int ret, i, patch_regs;
int pulls = 0;
dev_set_drvdata(wm8994->dev, wm8994);
ret = mfd_add_devices(wm8994->dev, -1,
wm8994_regulator_devs,
ARRAY_SIZE(wm8994_regulator_devs),
NULL, 0, NULL);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to add children: %d\n", ret);
goto err;
}
switch (wm8994->type) {
case WM1811:
wm8994->num_supplies = ARRAY_SIZE(wm1811_main_supplies);
break;
case WM8994:
wm8994->num_supplies = ARRAY_SIZE(wm8994_main_supplies);
break;
case WM8958:
wm8994->num_supplies = ARRAY_SIZE(wm8958_main_supplies);
break;
default:
BUG();
goto err;
}
wm8994->supplies = devm_kzalloc(wm8994->dev,
sizeof(struct regulator_bulk_data) *
wm8994->num_supplies, GFP_KERNEL);
if (!wm8994->supplies) {
ret = -ENOMEM;
goto err;
}
switch (wm8994->type) {
case WM1811:
for (i = 0; i < ARRAY_SIZE(wm1811_main_supplies); i++)
wm8994->supplies[i].supply = wm1811_main_supplies[i];
break;
case WM8994:
for (i = 0; i < ARRAY_SIZE(wm8994_main_supplies); i++)
wm8994->supplies[i].supply = wm8994_main_supplies[i];
break;
case WM8958:
for (i = 0; i < ARRAY_SIZE(wm8958_main_supplies); i++)
wm8994->supplies[i].supply = wm8958_main_supplies[i];
break;
default:
BUG();
goto err;
}
ret = regulator_bulk_get(wm8994->dev, wm8994->num_supplies,
wm8994->supplies);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to get supplies: %d\n", ret);
goto err;
}
ret = regulator_bulk_enable(wm8994->num_supplies,
wm8994->supplies);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to enable supplies: %d\n", ret);
goto err_get;
}
ret = wm8994_reg_read(wm8994, WM8994_SOFTWARE_RESET);
if (ret < 0) {
dev_err(wm8994->dev, "Failed to read ID register\n");
goto err_enable;
}
switch (ret) {
case 0x1811:
devname = "WM1811";
if (wm8994->type != WM1811)
dev_warn(wm8994->dev, "Device registered as type %d\n",
wm8994->type);
wm8994->type = WM1811;
break;
case 0x8994:
devname = "WM8994";
if (wm8994->type != WM8994)
dev_warn(wm8994->dev, "Device registered as type %d\n",
wm8994->type);
wm8994->type = WM8994;
break;
case 0x8958:
devname = "WM8958";
if (wm8994->type != WM8958)
dev_warn(wm8994->dev, "Device registered as type %d\n",
wm8994->type);
wm8994->type = WM8958;
break;
default:
dev_err(wm8994->dev, "Device is not a WM8994, ID is %x\n",
ret);
ret = -EINVAL;
goto err_enable;
}
ret = wm8994_reg_read(wm8994, WM8994_CHIP_REVISION);
if (ret < 0) {
dev_err(wm8994->dev, "Failed to read revision register: %d\n",
ret);
goto err_enable;
}
wm8994->revision = ret & WM8994_CHIP_REV_MASK;
wm8994->cust_id = (ret & WM8994_CUST_ID_MASK) >> WM8994_CUST_ID_SHIFT;
switch (wm8994->type) {
case WM8994:
switch (wm8994->revision) {
case 0:
case 1:
dev_warn(wm8994->dev,
"revision %c not fully supported\n",
'A' + wm8994->revision);
break;
case 2:
case 3:
regmap_patch = wm8994_revc_patch;
patch_regs = ARRAY_SIZE(wm8994_revc_patch);
break;
default:
break;
}
break;
case WM8958:
switch (wm8994->revision) {
case 0:
regmap_patch = wm8958_reva_patch;
patch_regs = ARRAY_SIZE(wm8958_reva_patch);
break;
default:
break;
}
break;
case WM1811:
if (wm8994->revision > 1)
wm8994->revision++;
switch (wm8994->revision) {
case 0:
case 1:
case 2:
case 3:
regmap_patch = wm1811_reva_patch;
patch_regs = ARRAY_SIZE(wm1811_reva_patch);
break;
default:
break;
}
break;
default:
break;
}
dev_info(wm8994->dev, "%s revision %c CUST_ID %02x\n", devname,
'A' + wm8994->revision, wm8994->cust_id);
switch (wm8994->type) {
case WM1811:
regmap_config = &wm1811_regmap_config;
break;
case WM8994:
regmap_config = &wm8994_regmap_config;
break;
case WM8958:
regmap_config = &wm8958_regmap_config;
break;
default:
dev_err(wm8994->dev, "Unknown device type %d\n", wm8994->type);
return -EINVAL;
}
ret = regmap_reinit_cache(wm8994->regmap, regmap_config);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to reinit register cache: %d\n",
ret);
return ret;
}
if (regmap_patch) {
ret = regmap_register_patch(wm8994->regmap, regmap_patch,
patch_regs);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to register patch: %d\n",
ret);
goto err;
}
}
if (pdata) {
wm8994->irq_base = pdata->irq_base;
wm8994->gpio_base = pdata->gpio_base;
for (i = 0; i < ARRAY_SIZE(pdata->gpio_defaults); i++) {
if (pdata->gpio_defaults[i]) {
wm8994_set_bits(wm8994, WM8994_GPIO_1 + i,
0xffff,
pdata->gpio_defaults[i]);
}
}
wm8994->ldo_ena_always_driven = pdata->ldo_ena_always_driven;
if (pdata->spkmode_pu)
pulls |= WM8994_SPKMODE_PU;
}
wm8994_set_bits(wm8994, WM8994_PULL_CONTROL_2,
WM8994_LDO1ENA_PD | WM8994_LDO2ENA_PD |
WM8994_SPKMODE_PU | WM8994_CSNADDR_PD,
pulls);
for (i = 0; i < WM8994_NUM_LDO_REGS; i++) {
if (wm8994_ldo_in_use(pdata, i))
wm8994_set_bits(wm8994, WM8994_LDO_1 + i,
WM8994_LDO1_DISCH, WM8994_LDO1_DISCH);
else
wm8994_set_bits(wm8994, WM8994_LDO_1 + i,
WM8994_LDO1_DISCH, 0);
}
wm8994_irq_init(wm8994);
ret = mfd_add_devices(wm8994->dev, -1,
wm8994_devs, ARRAY_SIZE(wm8994_devs),
NULL, 0, NULL);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to add children: %d\n", ret);
goto err_irq;
}
pm_runtime_enable(wm8994->dev);
pm_runtime_idle(wm8994->dev);
return 0;
err_irq:
wm8994_irq_exit(wm8994);
err_enable:
regulator_bulk_disable(wm8994->num_supplies,
wm8994->supplies);
err_get:
regulator_bulk_free(wm8994->num_supplies, wm8994->supplies);
err:
mfd_remove_devices(wm8994->dev);
return ret;
}
static __devexit void wm8994_device_exit(struct wm8994 *wm8994)
{
pm_runtime_disable(wm8994->dev);
mfd_remove_devices(wm8994->dev);
wm8994_irq_exit(wm8994);
regulator_bulk_disable(wm8994->num_supplies,
wm8994->supplies);
regulator_bulk_free(wm8994->num_supplies, wm8994->supplies);
}
static __devinit int wm8994_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8994 *wm8994;
int ret;
wm8994 = devm_kzalloc(&i2c->dev, sizeof(struct wm8994), GFP_KERNEL);
if (wm8994 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8994);
wm8994->dev = &i2c->dev;
wm8994->irq = i2c->irq;
wm8994->type = id->driver_data;
wm8994->regmap = devm_regmap_init_i2c(i2c, &wm8994_base_regmap_config);
if (IS_ERR(wm8994->regmap)) {
ret = PTR_ERR(wm8994->regmap);
dev_err(wm8994->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
return wm8994_device_init(wm8994, i2c->irq);
}
static __devexit int wm8994_i2c_remove(struct i2c_client *i2c)
{
struct wm8994 *wm8994 = i2c_get_clientdata(i2c);
wm8994_device_exit(wm8994);
return 0;
}
