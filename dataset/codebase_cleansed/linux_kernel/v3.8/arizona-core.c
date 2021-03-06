int arizona_clk32k_enable(struct arizona *arizona)
{
int ret = 0;
mutex_lock(&arizona->clk_lock);
arizona->clk32k_ref++;
if (arizona->clk32k_ref == 1)
ret = regmap_update_bits(arizona->regmap, ARIZONA_CLOCK_32K_1,
ARIZONA_CLK_32K_ENA,
ARIZONA_CLK_32K_ENA);
if (ret != 0)
arizona->clk32k_ref--;
mutex_unlock(&arizona->clk_lock);
return ret;
}
int arizona_clk32k_disable(struct arizona *arizona)
{
int ret = 0;
mutex_lock(&arizona->clk_lock);
BUG_ON(arizona->clk32k_ref <= 0);
arizona->clk32k_ref--;
if (arizona->clk32k_ref == 0)
regmap_update_bits(arizona->regmap, ARIZONA_CLOCK_32K_1,
ARIZONA_CLK_32K_ENA, 0);
mutex_unlock(&arizona->clk_lock);
return ret;
}
static irqreturn_t arizona_clkgen_err(int irq, void *data)
{
struct arizona *arizona = data;
dev_err(arizona->dev, "CLKGEN error\n");
return IRQ_HANDLED;
}
static irqreturn_t arizona_underclocked(int irq, void *data)
{
struct arizona *arizona = data;
unsigned int val;
int ret;
ret = regmap_read(arizona->regmap, ARIZONA_INTERRUPT_RAW_STATUS_8,
&val);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read underclock status: %d\n",
ret);
return IRQ_NONE;
}
if (val & ARIZONA_AIF3_UNDERCLOCKED_STS)
dev_err(arizona->dev, "AIF3 underclocked\n");
if (val & ARIZONA_AIF2_UNDERCLOCKED_STS)
dev_err(arizona->dev, "AIF2 underclocked\n");
if (val & ARIZONA_AIF1_UNDERCLOCKED_STS)
dev_err(arizona->dev, "AIF1 underclocked\n");
if (val & ARIZONA_ISRC2_UNDERCLOCKED_STS)
dev_err(arizona->dev, "ISRC2 underclocked\n");
if (val & ARIZONA_ISRC1_UNDERCLOCKED_STS)
dev_err(arizona->dev, "ISRC1 underclocked\n");
if (val & ARIZONA_FX_UNDERCLOCKED_STS)
dev_err(arizona->dev, "FX underclocked\n");
if (val & ARIZONA_ASRC_UNDERCLOCKED_STS)
dev_err(arizona->dev, "ASRC underclocked\n");
if (val & ARIZONA_DAC_UNDERCLOCKED_STS)
dev_err(arizona->dev, "DAC underclocked\n");
if (val & ARIZONA_ADC_UNDERCLOCKED_STS)
dev_err(arizona->dev, "ADC underclocked\n");
if (val & ARIZONA_MIXER_UNDERCLOCKED_STS)
dev_err(arizona->dev, "Mixer underclocked\n");
return IRQ_HANDLED;
}
static irqreturn_t arizona_overclocked(int irq, void *data)
{
struct arizona *arizona = data;
unsigned int val[2];
int ret;
ret = regmap_bulk_read(arizona->regmap, ARIZONA_INTERRUPT_RAW_STATUS_6,
&val[0], 2);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read overclock status: %d\n",
ret);
return IRQ_NONE;
}
if (val[0] & ARIZONA_PWM_OVERCLOCKED_STS)
dev_err(arizona->dev, "PWM overclocked\n");
if (val[0] & ARIZONA_FX_CORE_OVERCLOCKED_STS)
dev_err(arizona->dev, "FX core overclocked\n");
if (val[0] & ARIZONA_DAC_SYS_OVERCLOCKED_STS)
dev_err(arizona->dev, "DAC SYS overclocked\n");
if (val[0] & ARIZONA_DAC_WARP_OVERCLOCKED_STS)
dev_err(arizona->dev, "DAC WARP overclocked\n");
if (val[0] & ARIZONA_ADC_OVERCLOCKED_STS)
dev_err(arizona->dev, "ADC overclocked\n");
if (val[0] & ARIZONA_MIXER_OVERCLOCKED_STS)
dev_err(arizona->dev, "Mixer overclocked\n");
if (val[0] & ARIZONA_AIF3_SYNC_OVERCLOCKED_STS)
dev_err(arizona->dev, "AIF3 overclocked\n");
if (val[0] & ARIZONA_AIF2_SYNC_OVERCLOCKED_STS)
dev_err(arizona->dev, "AIF2 overclocked\n");
if (val[0] & ARIZONA_AIF1_SYNC_OVERCLOCKED_STS)
dev_err(arizona->dev, "AIF1 overclocked\n");
if (val[0] & ARIZONA_PAD_CTRL_OVERCLOCKED_STS)
dev_err(arizona->dev, "Pad control overclocked\n");
if (val[1] & ARIZONA_SLIMBUS_SUBSYS_OVERCLOCKED_STS)
dev_err(arizona->dev, "Slimbus subsystem overclocked\n");
if (val[1] & ARIZONA_SLIMBUS_ASYNC_OVERCLOCKED_STS)
dev_err(arizona->dev, "Slimbus async overclocked\n");
if (val[1] & ARIZONA_SLIMBUS_SYNC_OVERCLOCKED_STS)
dev_err(arizona->dev, "Slimbus sync overclocked\n");
if (val[1] & ARIZONA_ASRC_ASYNC_SYS_OVERCLOCKED_STS)
dev_err(arizona->dev, "ASRC async system overclocked\n");
if (val[1] & ARIZONA_ASRC_ASYNC_WARP_OVERCLOCKED_STS)
dev_err(arizona->dev, "ASRC async WARP overclocked\n");
if (val[1] & ARIZONA_ASRC_SYNC_SYS_OVERCLOCKED_STS)
dev_err(arizona->dev, "ASRC sync system overclocked\n");
if (val[1] & ARIZONA_ASRC_SYNC_WARP_OVERCLOCKED_STS)
dev_err(arizona->dev, "ASRC sync WARP overclocked\n");
if (val[1] & ARIZONA_ADSP2_1_OVERCLOCKED_STS)
dev_err(arizona->dev, "DSP1 overclocked\n");
if (val[1] & ARIZONA_ISRC2_OVERCLOCKED_STS)
dev_err(arizona->dev, "ISRC2 overclocked\n");
if (val[1] & ARIZONA_ISRC1_OVERCLOCKED_STS)
dev_err(arizona->dev, "ISRC1 overclocked\n");
return IRQ_HANDLED;
}
static int arizona_wait_for_boot(struct arizona *arizona)
{
unsigned int reg;
int ret, i;
for (i = 0; i < 5; i++) {
msleep(1);
ret = regmap_read(arizona->regmap,
ARIZONA_INTERRUPT_RAW_STATUS_5, &reg);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read boot state: %d\n",
ret);
continue;
}
if (reg & ARIZONA_BOOT_DONE_STS)
break;
}
if (reg & ARIZONA_BOOT_DONE_STS) {
regmap_write(arizona->regmap, ARIZONA_INTERRUPT_STATUS_5,
ARIZONA_BOOT_DONE_STS);
} else {
dev_err(arizona->dev, "Device boot timed out: %x\n", reg);
return -ETIMEDOUT;
}
pm_runtime_mark_last_busy(arizona->dev);
return 0;
}
static int arizona_runtime_resume(struct device *dev)
{
struct arizona *arizona = dev_get_drvdata(dev);
int ret;
dev_dbg(arizona->dev, "Leaving AoD mode\n");
ret = regulator_enable(arizona->dcvdd);
if (ret != 0) {
dev_err(arizona->dev, "Failed to enable DCVDD: %d\n", ret);
return ret;
}
regcache_cache_only(arizona->regmap, false);
ret = arizona_wait_for_boot(arizona);
if (ret != 0) {
regulator_disable(arizona->dcvdd);
return ret;
}
ret = regcache_sync(arizona->regmap);
if (ret != 0) {
dev_err(arizona->dev, "Failed to restore register cache\n");
regulator_disable(arizona->dcvdd);
return ret;
}
return 0;
}
static int arizona_runtime_suspend(struct device *dev)
{
struct arizona *arizona = dev_get_drvdata(dev);
dev_dbg(arizona->dev, "Entering AoD mode\n");
regulator_disable(arizona->dcvdd);
regcache_cache_only(arizona->regmap, true);
regcache_mark_dirty(arizona->regmap);
return 0;
}
int arizona_dev_init(struct arizona *arizona)
{
struct device *dev = arizona->dev;
const char *type_name;
unsigned int reg, val;
int (*apply_patch)(struct arizona *) = NULL;
int ret, i;
dev_set_drvdata(arizona->dev, arizona);
mutex_init(&arizona->clk_lock);
if (dev_get_platdata(arizona->dev))
memcpy(&arizona->pdata, dev_get_platdata(arizona->dev),
sizeof(arizona->pdata));
regcache_cache_only(arizona->regmap, true);
switch (arizona->type) {
case WM5102:
case WM5110:
for (i = 0; i < ARRAY_SIZE(wm5102_core_supplies); i++)
arizona->core_supplies[i].supply
= wm5102_core_supplies[i];
arizona->num_core_supplies = ARRAY_SIZE(wm5102_core_supplies);
break;
default:
dev_err(arizona->dev, "Unknown device type %d\n",
arizona->type);
return -EINVAL;
}
ret = mfd_add_devices(arizona->dev, -1, early_devs,
ARRAY_SIZE(early_devs), NULL, 0, NULL);
if (ret != 0) {
dev_err(dev, "Failed to add early children: %d\n", ret);
return ret;
}
ret = devm_regulator_bulk_get(dev, arizona->num_core_supplies,
arizona->core_supplies);
if (ret != 0) {
dev_err(dev, "Failed to request core supplies: %d\n",
ret);
goto err_early;
}
arizona->dcvdd = devm_regulator_get(arizona->dev, "DCVDD");
if (IS_ERR(arizona->dcvdd)) {
ret = PTR_ERR(arizona->dcvdd);
dev_err(dev, "Failed to request DCVDD: %d\n", ret);
goto err_early;
}
ret = regulator_bulk_enable(arizona->num_core_supplies,
arizona->core_supplies);
if (ret != 0) {
dev_err(dev, "Failed to enable core supplies: %d\n",
ret);
goto err_early;
}
ret = regulator_enable(arizona->dcvdd);
if (ret != 0) {
dev_err(dev, "Failed to enable DCVDD: %d\n", ret);
goto err_enable;
}
if (arizona->pdata.reset) {
ret = gpio_request_one(arizona->pdata.reset,
GPIOF_DIR_OUT | GPIOF_INIT_LOW,
"arizona /RESET");
if (ret != 0) {
dev_err(dev, "Failed to request /RESET: %d\n", ret);
goto err_dcvdd;
}
gpio_set_value_cansleep(arizona->pdata.reset, 1);
}
regcache_cache_only(arizona->regmap, false);
ret = regmap_read(arizona->regmap, ARIZONA_SOFTWARE_RESET, &reg);
if (ret != 0) {
dev_err(dev, "Failed to read ID register: %d\n", ret);
goto err_reset;
}
ret = regmap_read(arizona->regmap, ARIZONA_DEVICE_REVISION,
&arizona->rev);
if (ret != 0) {
dev_err(dev, "Failed to read revision register: %d\n", ret);
goto err_reset;
}
arizona->rev &= ARIZONA_DEVICE_REVISION_MASK;
switch (reg) {
#ifdef CONFIG_MFD_WM5102
case 0x5102:
type_name = "WM5102";
if (arizona->type != WM5102) {
dev_err(arizona->dev, "WM5102 registered as %d\n",
arizona->type);
arizona->type = WM5102;
}
apply_patch = wm5102_patch;
break;
#endif
#ifdef CONFIG_MFD_WM5110
case 0x5110:
type_name = "WM5110";
if (arizona->type != WM5110) {
dev_err(arizona->dev, "WM5110 registered as %d\n",
arizona->type);
arizona->type = WM5110;
}
apply_patch = wm5110_patch;
break;
#endif
default:
dev_err(arizona->dev, "Unknown device ID %x\n", reg);
goto err_reset;
}
dev_info(dev, "%s revision %c\n", type_name, arizona->rev + 'A');
if (!arizona->pdata.reset) {
regcache_mark_dirty(arizona->regmap);
ret = regmap_write(arizona->regmap, ARIZONA_SOFTWARE_RESET, 0);
if (ret != 0) {
dev_err(dev, "Failed to reset device: %d\n", ret);
goto err_reset;
}
ret = regcache_sync(arizona->regmap);
if (ret != 0) {
dev_err(dev, "Failed to sync device: %d\n", ret);
goto err_reset;
}
}
ret = arizona_wait_for_boot(arizona);
if (ret != 0) {
dev_err(arizona->dev, "Device failed initial boot: %d\n", ret);
goto err_reset;
}
if (apply_patch) {
ret = apply_patch(arizona);
if (ret != 0) {
dev_err(arizona->dev, "Failed to apply patch: %d\n",
ret);
goto err_reset;
}
}
for (i = 0; i < ARRAY_SIZE(arizona->pdata.gpio_defaults); i++) {
if (!arizona->pdata.gpio_defaults[i])
continue;
regmap_write(arizona->regmap, ARIZONA_GPIO1_CTRL + i,
arizona->pdata.gpio_defaults[i]);
}
pm_runtime_set_autosuspend_delay(arizona->dev, 100);
pm_runtime_use_autosuspend(arizona->dev);
pm_runtime_enable(arizona->dev);
if (!arizona->pdata.clk32k_src)
arizona->pdata.clk32k_src = ARIZONA_32KZ_MCLK2;
switch (arizona->pdata.clk32k_src) {
case ARIZONA_32KZ_MCLK1:
case ARIZONA_32KZ_MCLK2:
regmap_update_bits(arizona->regmap, ARIZONA_CLOCK_32K_1,
ARIZONA_CLK_32K_SRC_MASK,
arizona->pdata.clk32k_src - 1);
break;
case ARIZONA_32KZ_NONE:
regmap_update_bits(arizona->regmap, ARIZONA_CLOCK_32K_1,
ARIZONA_CLK_32K_SRC_MASK, 2);
break;
default:
dev_err(arizona->dev, "Invalid 32kHz clock source: %d\n",
arizona->pdata.clk32k_src);
ret = -EINVAL;
goto err_reset;
}
for (i = 0; i < ARIZONA_MAX_INPUT; i++) {
val = arizona->pdata.dmic_ref[i]
<< ARIZONA_IN1_DMIC_SUP_SHIFT;
val |= arizona->pdata.inmode[i] << ARIZONA_IN1_MODE_SHIFT;
regmap_update_bits(arizona->regmap,
ARIZONA_IN1L_CONTROL + (i * 8),
ARIZONA_IN1_DMIC_SUP_MASK |
ARIZONA_IN1_MODE_MASK, val);
}
for (i = 0; i < ARIZONA_MAX_OUTPUT; i++) {
if (arizona->pdata.out_mono[i])
val = ARIZONA_OUT1_MONO;
else
val = 0;
regmap_update_bits(arizona->regmap,
ARIZONA_OUTPUT_PATH_CONFIG_1L + (i * 8),
ARIZONA_OUT1_MONO, val);
}
for (i = 0; i < ARIZONA_MAX_PDM_SPK; i++) {
if (arizona->pdata.spk_mute[i])
regmap_update_bits(arizona->regmap,
ARIZONA_PDM_SPK1_CTRL_1 + (i * 2),
ARIZONA_SPK1_MUTE_ENDIAN_MASK |
ARIZONA_SPK1_MUTE_SEQ1_MASK,
arizona->pdata.spk_mute[i]);
if (arizona->pdata.spk_fmt[i])
regmap_update_bits(arizona->regmap,
ARIZONA_PDM_SPK1_CTRL_2 + (i * 2),
ARIZONA_SPK1_FMT_MASK,
arizona->pdata.spk_fmt[i]);
}
ret = arizona_irq_init(arizona);
if (ret != 0)
goto err_reset;
arizona_request_irq(arizona, ARIZONA_IRQ_CLKGEN_ERR, "CLKGEN error",
arizona_clkgen_err, arizona);
arizona_request_irq(arizona, ARIZONA_IRQ_OVERCLOCKED, "Overclocked",
arizona_overclocked, arizona);
arizona_request_irq(arizona, ARIZONA_IRQ_UNDERCLOCKED, "Underclocked",
arizona_underclocked, arizona);
switch (arizona->type) {
case WM5102:
ret = mfd_add_devices(arizona->dev, -1, wm5102_devs,
ARRAY_SIZE(wm5102_devs), NULL, 0, NULL);
break;
case WM5110:
ret = mfd_add_devices(arizona->dev, -1, wm5110_devs,
ARRAY_SIZE(wm5110_devs), NULL, 0, NULL);
break;
}
if (ret != 0) {
dev_err(arizona->dev, "Failed to add subdevices: %d\n", ret);
goto err_irq;
}
#ifdef CONFIG_PM_RUNTIME
regulator_disable(arizona->dcvdd);
#endif
return 0;
err_irq:
arizona_irq_exit(arizona);
err_reset:
if (arizona->pdata.reset) {
gpio_set_value_cansleep(arizona->pdata.reset, 1);
gpio_free(arizona->pdata.reset);
}
err_dcvdd:
regulator_disable(arizona->dcvdd);
err_enable:
regulator_bulk_disable(arizona->num_core_supplies,
arizona->core_supplies);
err_early:
mfd_remove_devices(dev);
return ret;
}
int arizona_dev_exit(struct arizona *arizona)
{
mfd_remove_devices(arizona->dev);
arizona_free_irq(arizona, ARIZONA_IRQ_UNDERCLOCKED, arizona);
arizona_free_irq(arizona, ARIZONA_IRQ_OVERCLOCKED, arizona);
arizona_free_irq(arizona, ARIZONA_IRQ_CLKGEN_ERR, arizona);
pm_runtime_disable(arizona->dev);
arizona_irq_exit(arizona);
return 0;
}
