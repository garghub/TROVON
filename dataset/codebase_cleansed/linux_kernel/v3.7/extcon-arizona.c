static void arizona_extcon_set_mode(struct arizona_extcon_info *info, int mode)
{
struct arizona *arizona = info->arizona;
gpio_set_value_cansleep(arizona->pdata.micd_pol_gpio,
info->micd_modes[mode].gpio);
regmap_update_bits(arizona->regmap, ARIZONA_MIC_DETECT_1,
ARIZONA_MICD_BIAS_SRC_MASK,
info->micd_modes[mode].bias);
regmap_update_bits(arizona->regmap, ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_SRC, info->micd_modes[mode].src);
info->micd_mode = mode;
dev_dbg(arizona->dev, "Set jack polarity to %d\n", mode);
}
static void arizona_start_mic(struct arizona_extcon_info *info)
{
struct arizona *arizona = info->arizona;
bool change;
int ret;
info->detecting = true;
info->mic = false;
info->jack_flips = 0;
pm_runtime_get(info->dev);
ret = regulator_enable(info->micvdd);
if (ret != 0) {
dev_err(arizona->dev, "Failed to enable MICVDD: %d\n",
ret);
}
if (info->micd_reva) {
regmap_write(arizona->regmap, 0x80, 0x3);
regmap_write(arizona->regmap, 0x294, 0);
regmap_write(arizona->regmap, 0x80, 0x0);
}
regmap_update_bits_check(arizona->regmap, ARIZONA_MIC_DETECT_1,
ARIZONA_MICD_ENA, ARIZONA_MICD_ENA,
&change);
if (!change) {
regulator_disable(info->micvdd);
pm_runtime_put_autosuspend(info->dev);
}
}
static void arizona_stop_mic(struct arizona_extcon_info *info)
{
struct arizona *arizona = info->arizona;
bool change;
regmap_update_bits_check(arizona->regmap, ARIZONA_MIC_DETECT_1,
ARIZONA_MICD_ENA, 0,
&change);
if (info->micd_reva) {
regmap_write(arizona->regmap, 0x80, 0x3);
regmap_write(arizona->regmap, 0x294, 2);
regmap_write(arizona->regmap, 0x80, 0x0);
}
if (change) {
regulator_disable(info->micvdd);
pm_runtime_mark_last_busy(info->dev);
pm_runtime_put_autosuspend(info->dev);
}
}
static irqreturn_t arizona_micdet(int irq, void *data)
{
struct arizona_extcon_info *info = data;
struct arizona *arizona = info->arizona;
unsigned int val, lvl;
int ret, i;
mutex_lock(&info->lock);
ret = regmap_read(arizona->regmap, ARIZONA_MIC_DETECT_3, &val);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read MICDET: %d\n", ret);
return IRQ_NONE;
}
dev_dbg(arizona->dev, "MICDET: %x\n", val);
if (!(val & ARIZONA_MICD_VALID)) {
dev_warn(arizona->dev, "Microphone detection state invalid\n");
mutex_unlock(&info->lock);
return IRQ_NONE;
}
if (!(val & ARIZONA_MICD_STS)) {
dev_warn(arizona->dev, "Detected open circuit\n");
info->detecting = false;
goto handled;
}
if (info->detecting && (val & 0x400)) {
ret = extcon_update_state(&info->edev,
1 << ARIZONA_CABLE_MICROPHONE |
1 << ARIZONA_CABLE_HEADPHONE,
1 << ARIZONA_CABLE_MICROPHONE |
1 << ARIZONA_CABLE_HEADPHONE);
if (ret != 0)
dev_err(arizona->dev, "Headset report failed: %d\n",
ret);
info->mic = true;
info->detecting = false;
goto handled;
}
if (info->detecting && (val & 0x3f8)) {
info->jack_flips++;
if (info->jack_flips >= info->micd_num_modes) {
dev_dbg(arizona->dev, "Detected headphone\n");
info->detecting = false;
arizona_stop_mic(info);
ret = extcon_set_cable_state_(&info->edev,
ARIZONA_CABLE_HEADPHONE,
true);
if (ret != 0)
dev_err(arizona->dev,
"Headphone report failed: %d\n",
ret);
} else {
info->micd_mode++;
if (info->micd_mode == info->micd_num_modes)
info->micd_mode = 0;
arizona_extcon_set_mode(info, info->micd_mode);
info->jack_flips++;
}
goto handled;
}
if (val & 0x3fc) {
if (info->mic) {
dev_dbg(arizona->dev, "Mic button detected\n");
lvl = val & ARIZONA_MICD_LVL_MASK;
lvl >>= ARIZONA_MICD_LVL_SHIFT;
for (i = 0; i < ARIZONA_NUM_BUTTONS; i++)
if (lvl & arizona_lvl_to_key[i].status)
input_report_key(info->input,
arizona_lvl_to_key[i].report,
1);
input_sync(info->input);
} else if (info->detecting) {
dev_dbg(arizona->dev, "Headphone detected\n");
info->detecting = false;
arizona_stop_mic(info);
ret = extcon_set_cable_state_(&info->edev,
ARIZONA_CABLE_HEADPHONE,
true);
if (ret != 0)
dev_err(arizona->dev,
"Headphone report failed: %d\n",
ret);
} else {
dev_warn(arizona->dev, "Button with no mic: %x\n",
val);
}
} else {
dev_dbg(arizona->dev, "Mic button released\n");
for (i = 0; i < ARIZONA_NUM_BUTTONS; i++)
input_report_key(info->input,
arizona_lvl_to_key[i].report, 0);
input_sync(info->input);
}
handled:
pm_runtime_mark_last_busy(info->dev);
mutex_unlock(&info->lock);
return IRQ_HANDLED;
}
static irqreturn_t arizona_jackdet(int irq, void *data)
{
struct arizona_extcon_info *info = data;
struct arizona *arizona = info->arizona;
unsigned int val;
int ret, i;
pm_runtime_get_sync(info->dev);
mutex_lock(&info->lock);
ret = regmap_read(arizona->regmap, ARIZONA_AOD_IRQ_RAW_STATUS, &val);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read jackdet status: %d\n",
ret);
mutex_unlock(&info->lock);
pm_runtime_put_autosuspend(info->dev);
return IRQ_NONE;
}
if (val & ARIZONA_JD1_STS) {
dev_dbg(arizona->dev, "Detected jack\n");
ret = extcon_set_cable_state_(&info->edev,
ARIZONA_CABLE_MECHANICAL, true);
if (ret != 0)
dev_err(arizona->dev, "Mechanical report failed: %d\n",
ret);
arizona_start_mic(info);
} else {
dev_dbg(arizona->dev, "Detected jack removal\n");
arizona_stop_mic(info);
for (i = 0; i < ARIZONA_NUM_BUTTONS; i++)
input_report_key(info->input,
arizona_lvl_to_key[i].report, 0);
input_sync(info->input);
ret = extcon_update_state(&info->edev, 0xffffffff, 0);
if (ret != 0)
dev_err(arizona->dev, "Removal report failed: %d\n",
ret);
}
mutex_unlock(&info->lock);
pm_runtime_mark_last_busy(info->dev);
pm_runtime_put_autosuspend(info->dev);
return IRQ_HANDLED;
}
static int __devinit arizona_extcon_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct arizona_pdata *pdata;
struct arizona_extcon_info *info;
int ret, mode, i;
pdata = dev_get_platdata(arizona->dev);
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info) {
dev_err(&pdev->dev, "Failed to allocate memory\n");
ret = -ENOMEM;
goto err;
}
info->micvdd = devm_regulator_get(arizona->dev, "MICVDD");
if (IS_ERR(info->micvdd)) {
ret = PTR_ERR(info->micvdd);
dev_err(arizona->dev, "Failed to get MICVDD: %d\n", ret);
goto err;
}
mutex_init(&info->lock);
info->arizona = arizona;
info->dev = &pdev->dev;
info->detecting = true;
platform_set_drvdata(pdev, info);
switch (arizona->type) {
case WM5102:
switch (arizona->rev) {
case 0:
info->micd_reva = true;
break;
default:
break;
}
break;
default:
break;
}
info->edev.name = "Headset Jack";
info->edev.supported_cable = arizona_cable;
ret = extcon_dev_register(&info->edev, arizona->dev);
if (ret < 0) {
dev_err(arizona->dev, "extcon_dev_register() failed: %d\n",
ret);
goto err;
}
if (pdata->num_micd_configs) {
info->micd_modes = pdata->micd_configs;
info->micd_num_modes = pdata->num_micd_configs;
} else {
info->micd_modes = micd_default_modes;
info->micd_num_modes = ARRAY_SIZE(micd_default_modes);
}
if (arizona->pdata.micd_pol_gpio > 0) {
if (info->micd_modes[0].gpio)
mode = GPIOF_OUT_INIT_HIGH;
else
mode = GPIOF_OUT_INIT_LOW;
ret = devm_gpio_request_one(&pdev->dev,
arizona->pdata.micd_pol_gpio,
mode,
"MICD polarity");
if (ret != 0) {
dev_err(arizona->dev, "Failed to request GPIO%d: %d\n",
arizona->pdata.micd_pol_gpio, ret);
goto err_register;
}
}
arizona_extcon_set_mode(info, 0);
info->input = input_allocate_device();
if (!info->input) {
dev_err(arizona->dev, "Can't allocate input dev\n");
ret = -ENOMEM;
goto err_register;
}
for (i = 0; i < ARIZONA_NUM_BUTTONS; i++)
input_set_capability(info->input, EV_KEY,
arizona_lvl_to_key[i].report);
info->input->name = "Headset";
info->input->phys = "arizona/extcon";
info->input->dev.parent = &pdev->dev;
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
ret = arizona_request_irq(arizona, ARIZONA_IRQ_JD_RISE,
"JACKDET rise", arizona_jackdet, info);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to get JACKDET rise IRQ: %d\n",
ret);
goto err_input;
}
ret = arizona_set_irq_wake(arizona, ARIZONA_IRQ_JD_RISE, 1);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to set JD rise IRQ wake: %d\n",
ret);
goto err_rise;
}
ret = arizona_request_irq(arizona, ARIZONA_IRQ_JD_FALL,
"JACKDET fall", arizona_jackdet, info);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to get JD fall IRQ: %d\n", ret);
goto err_rise_wake;
}
ret = arizona_set_irq_wake(arizona, ARIZONA_IRQ_JD_FALL, 1);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to set JD fall IRQ wake: %d\n",
ret);
goto err_fall;
}
ret = arizona_request_irq(arizona, ARIZONA_IRQ_MICDET,
"MICDET", arizona_micdet, info);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to get MICDET IRQ: %d\n", ret);
goto err_fall_wake;
}
regmap_update_bits(arizona->regmap, ARIZONA_MIC_DETECT_1,
ARIZONA_MICD_BIAS_STARTTIME_MASK |
ARIZONA_MICD_RATE_MASK,
7 << ARIZONA_MICD_BIAS_STARTTIME_SHIFT |
8 << ARIZONA_MICD_RATE_SHIFT);
arizona_clk32k_enable(arizona);
regmap_update_bits(arizona->regmap, ARIZONA_JACK_DETECT_DEBOUNCE,
ARIZONA_JD1_DB, ARIZONA_JD1_DB);
regmap_update_bits(arizona->regmap, ARIZONA_JACK_DETECT_ANALOGUE,
ARIZONA_JD1_ENA, ARIZONA_JD1_ENA);
ret = regulator_allow_bypass(info->micvdd, true);
if (ret != 0)
dev_warn(arizona->dev, "Failed to set MICVDD to bypass: %d\n",
ret);
pm_runtime_put(&pdev->dev);
ret = input_register_device(info->input);
if (ret) {
dev_err(&pdev->dev, "Can't register input device: %d\n", ret);
goto err_micdet;
}
return 0;
err_micdet:
arizona_free_irq(arizona, ARIZONA_IRQ_MICDET, info);
err_fall_wake:
arizona_set_irq_wake(arizona, ARIZONA_IRQ_JD_FALL, 0);
err_fall:
arizona_free_irq(arizona, ARIZONA_IRQ_JD_FALL, info);
err_rise_wake:
arizona_set_irq_wake(arizona, ARIZONA_IRQ_JD_RISE, 0);
err_rise:
arizona_free_irq(arizona, ARIZONA_IRQ_JD_RISE, info);
err_input:
input_free_device(info->input);
err_register:
pm_runtime_disable(&pdev->dev);
extcon_dev_unregister(&info->edev);
err:
return ret;
}
static int __devexit arizona_extcon_remove(struct platform_device *pdev)
{
struct arizona_extcon_info *info = platform_get_drvdata(pdev);
struct arizona *arizona = info->arizona;
pm_runtime_disable(&pdev->dev);
arizona_set_irq_wake(arizona, ARIZONA_IRQ_JD_RISE, 0);
arizona_set_irq_wake(arizona, ARIZONA_IRQ_JD_FALL, 0);
arizona_free_irq(arizona, ARIZONA_IRQ_MICDET, info);
arizona_free_irq(arizona, ARIZONA_IRQ_JD_RISE, info);
arizona_free_irq(arizona, ARIZONA_IRQ_JD_FALL, info);
regmap_update_bits(arizona->regmap, ARIZONA_JACK_DETECT_ANALOGUE,
ARIZONA_JD1_ENA, 0);
arizona_clk32k_disable(arizona);
input_unregister_device(info->input);
extcon_dev_unregister(&info->edev);
return 0;
}
