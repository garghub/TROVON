static void arizona_extcon_hp_clamp(struct arizona_extcon_info *info,
bool clamp)
{
struct arizona *arizona = info->arizona;
unsigned int mask = 0, val = 0;
int ret;
switch (arizona->type) {
case WM5110:
case WM8280:
mask = ARIZONA_HP1L_SHRTO | ARIZONA_HP1L_FLWR |
ARIZONA_HP1L_SHRTI;
if (clamp)
val = ARIZONA_HP1L_SHRTO;
else
val = ARIZONA_HP1L_FLWR | ARIZONA_HP1L_SHRTI;
break;
default:
mask = ARIZONA_RMV_SHRT_HP1L;
if (clamp)
val = ARIZONA_RMV_SHRT_HP1L;
break;
};
mutex_lock(&arizona->dapm->card->dapm_mutex);
arizona->hpdet_clamp = clamp;
if (clamp) {
ret = regmap_update_bits(arizona->regmap,
ARIZONA_OUTPUT_ENABLES_1,
ARIZONA_OUT1L_ENA |
ARIZONA_OUT1R_ENA, 0);
if (ret != 0)
dev_warn(arizona->dev,
"Failed to disable headphone outputs: %d\n",
ret);
}
ret = regmap_update_bits(arizona->regmap, ARIZONA_HP_CTRL_1L,
mask, val);
if (ret != 0)
dev_warn(arizona->dev, "Failed to do clamp: %d\n",
ret);
ret = regmap_update_bits(arizona->regmap, ARIZONA_HP_CTRL_1R,
mask, val);
if (ret != 0)
dev_warn(arizona->dev, "Failed to do clamp: %d\n",
ret);
if (!clamp) {
ret = regmap_update_bits(arizona->regmap,
ARIZONA_OUTPUT_ENABLES_1,
ARIZONA_OUT1L_ENA |
ARIZONA_OUT1R_ENA, arizona->hp_ena);
if (ret != 0)
dev_warn(arizona->dev,
"Failed to restore headphone outputs: %d\n",
ret);
}
mutex_unlock(&arizona->dapm->card->dapm_mutex);
}
static void arizona_extcon_set_mode(struct arizona_extcon_info *info, int mode)
{
struct arizona *arizona = info->arizona;
mode %= info->micd_num_modes;
if (arizona->pdata.micd_pol_gpio > 0)
gpio_set_value_cansleep(arizona->pdata.micd_pol_gpio,
info->micd_modes[mode].gpio);
regmap_update_bits(arizona->regmap, ARIZONA_MIC_DETECT_1,
ARIZONA_MICD_BIAS_SRC_MASK,
info->micd_modes[mode].bias <<
ARIZONA_MICD_BIAS_SRC_SHIFT);
regmap_update_bits(arizona->regmap, ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_SRC, info->micd_modes[mode].src);
info->micd_mode = mode;
dev_dbg(arizona->dev, "Set jack polarity to %d\n", mode);
}
static const char *arizona_extcon_get_micbias(struct arizona_extcon_info *info)
{
switch (info->micd_modes[0].bias) {
case 1:
return "MICBIAS1";
case 2:
return "MICBIAS2";
case 3:
return "MICBIAS3";
default:
return "MICVDD";
}
}
static void arizona_extcon_pulse_micbias(struct arizona_extcon_info *info)
{
struct arizona *arizona = info->arizona;
const char *widget = arizona_extcon_get_micbias(info);
struct snd_soc_dapm_context *dapm = arizona->dapm;
int ret;
ret = snd_soc_dapm_force_enable_pin(dapm, widget);
if (ret != 0)
dev_warn(arizona->dev, "Failed to enable %s: %d\n",
widget, ret);
snd_soc_dapm_sync(dapm);
if (!arizona->pdata.micd_force_micbias) {
ret = snd_soc_dapm_disable_pin(arizona->dapm, widget);
if (ret != 0)
dev_warn(arizona->dev, "Failed to disable %s: %d\n",
widget, ret);
snd_soc_dapm_sync(dapm);
}
}
static void arizona_start_mic(struct arizona_extcon_info *info)
{
struct arizona *arizona = info->arizona;
bool change;
int ret;
pm_runtime_get(info->dev);
if (info->detecting) {
ret = regulator_allow_bypass(info->micvdd, false);
if (ret != 0) {
dev_err(arizona->dev,
"Failed to regulate MICVDD: %d\n",
ret);
}
}
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
regmap_update_bits(arizona->regmap,
ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_MODE_MASK, ARIZONA_ACCDET_MODE_MIC);
arizona_extcon_pulse_micbias(info);
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
const char *widget = arizona_extcon_get_micbias(info);
struct snd_soc_dapm_context *dapm = arizona->dapm;
bool change;
int ret;
regmap_update_bits_check(arizona->regmap, ARIZONA_MIC_DETECT_1,
ARIZONA_MICD_ENA, 0,
&change);
ret = snd_soc_dapm_disable_pin(dapm, widget);
if (ret != 0)
dev_warn(arizona->dev,
"Failed to disable %s: %d\n",
widget, ret);
snd_soc_dapm_sync(dapm);
if (info->micd_reva) {
regmap_write(arizona->regmap, 0x80, 0x3);
regmap_write(arizona->regmap, 0x294, 2);
regmap_write(arizona->regmap, 0x80, 0x0);
}
ret = regulator_allow_bypass(info->micvdd, true);
if (ret != 0) {
dev_err(arizona->dev, "Failed to bypass MICVDD: %d\n",
ret);
}
if (change) {
regulator_disable(info->micvdd);
pm_runtime_mark_last_busy(info->dev);
pm_runtime_put_autosuspend(info->dev);
}
}
static int arizona_hpdet_read(struct arizona_extcon_info *info)
{
struct arizona *arizona = info->arizona;
unsigned int val, range;
int ret;
ret = regmap_read(arizona->regmap, ARIZONA_HEADPHONE_DETECT_2, &val);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read HPDET status: %d\n",
ret);
return ret;
}
switch (info->hpdet_ip_version) {
case 0:
if (!(val & ARIZONA_HP_DONE)) {
dev_err(arizona->dev, "HPDET did not complete: %x\n",
val);
return -EAGAIN;
}
val &= ARIZONA_HP_LVL_MASK;
break;
case 1:
if (!(val & ARIZONA_HP_DONE_B)) {
dev_err(arizona->dev, "HPDET did not complete: %x\n",
val);
return -EAGAIN;
}
ret = regmap_read(arizona->regmap, ARIZONA_HP_DACVAL, &val);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read HP value: %d\n",
ret);
return -EAGAIN;
}
regmap_read(arizona->regmap, ARIZONA_HEADPHONE_DETECT_1,
&range);
range = (range & ARIZONA_HP_IMPEDANCE_RANGE_MASK)
>> ARIZONA_HP_IMPEDANCE_RANGE_SHIFT;
if (range < ARRAY_SIZE(arizona_hpdet_b_ranges) - 1 &&
(val < arizona_hpdet_b_ranges[range].threshold ||
val >= ARIZONA_HPDET_B_RANGE_MAX)) {
range++;
dev_dbg(arizona->dev, "Moving to HPDET range %d\n",
range);
regmap_update_bits(arizona->regmap,
ARIZONA_HEADPHONE_DETECT_1,
ARIZONA_HP_IMPEDANCE_RANGE_MASK,
range <<
ARIZONA_HP_IMPEDANCE_RANGE_SHIFT);
return -EAGAIN;
}
if (val < arizona_hpdet_b_ranges[range].threshold ||
val >= ARIZONA_HPDET_B_RANGE_MAX) {
dev_dbg(arizona->dev, "Measurement out of range\n");
return ARIZONA_HPDET_MAX;
}
dev_dbg(arizona->dev, "HPDET read %d in range %d\n",
val, range);
val = arizona_hpdet_b_ranges[range].factor_b
/ ((val * 100) -
arizona_hpdet_b_ranges[range].factor_a);
break;
default:
dev_warn(arizona->dev, "Unknown HPDET IP revision %d\n",
info->hpdet_ip_version);
case 2:
if (!(val & ARIZONA_HP_DONE_B)) {
dev_err(arizona->dev, "HPDET did not complete: %x\n",
val);
return -EAGAIN;
}
val &= ARIZONA_HP_LVL_B_MASK;
val /= 2;
regmap_read(arizona->regmap, ARIZONA_HEADPHONE_DETECT_1,
&range);
range = (range & ARIZONA_HP_IMPEDANCE_RANGE_MASK)
>> ARIZONA_HP_IMPEDANCE_RANGE_SHIFT;
if (range < ARRAY_SIZE(arizona_hpdet_c_ranges) - 1 &&
(val >= arizona_hpdet_c_ranges[range].max)) {
range++;
dev_dbg(arizona->dev, "Moving to HPDET range %d-%d\n",
arizona_hpdet_c_ranges[range].min,
arizona_hpdet_c_ranges[range].max);
regmap_update_bits(arizona->regmap,
ARIZONA_HEADPHONE_DETECT_1,
ARIZONA_HP_IMPEDANCE_RANGE_MASK,
range <<
ARIZONA_HP_IMPEDANCE_RANGE_SHIFT);
return -EAGAIN;
}
if (range && (val < arizona_hpdet_c_ranges[range].min)) {
dev_dbg(arizona->dev, "Reporting range boundary %d\n",
arizona_hpdet_c_ranges[range].min);
val = arizona_hpdet_c_ranges[range].min;
}
}
dev_dbg(arizona->dev, "HP impedance %d ohms\n", val);
return val;
}
static int arizona_hpdet_do_id(struct arizona_extcon_info *info, int *reading,
bool *mic)
{
struct arizona *arizona = info->arizona;
int id_gpio = arizona->pdata.hpdet_id_gpio;
if (arizona->pdata.hpdet_acc_id) {
info->hpdet_res[info->num_hpdet_res++] = *reading;
if (id_gpio && info->num_hpdet_res == 1) {
dev_dbg(arizona->dev, "Measuring mic\n");
regmap_update_bits(arizona->regmap,
ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_MODE_MASK |
ARIZONA_ACCDET_SRC,
ARIZONA_ACCDET_MODE_HPR |
info->micd_modes[0].src);
gpio_set_value_cansleep(id_gpio, 1);
regmap_update_bits(arizona->regmap,
ARIZONA_HEADPHONE_DETECT_1,
ARIZONA_HP_POLL, ARIZONA_HP_POLL);
return -EAGAIN;
}
dev_dbg(arizona->dev, "HPDET measured %d %d\n",
info->hpdet_res[0], info->hpdet_res[1]);
*reading = info->hpdet_res[0];
if (*reading >= ARIZONA_HPDET_MAX && !info->hpdet_retried) {
dev_dbg(arizona->dev, "Retrying high impedance\n");
info->num_hpdet_res = 0;
info->hpdet_retried = true;
arizona_start_hpdet_acc_id(info);
pm_runtime_put(info->dev);
return -EAGAIN;
}
if (!id_gpio || info->hpdet_res[1] > 50) {
dev_dbg(arizona->dev, "Detected mic\n");
*mic = true;
info->detecting = true;
} else {
dev_dbg(arizona->dev, "Detected headphone\n");
}
regmap_update_bits(arizona->regmap,
ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_SRC,
info->micd_modes[0].src);
}
return 0;
}
static irqreturn_t arizona_hpdet_irq(int irq, void *data)
{
struct arizona_extcon_info *info = data;
struct arizona *arizona = info->arizona;
int id_gpio = arizona->pdata.hpdet_id_gpio;
unsigned int report = EXTCON_HEADPHONE;
int ret, reading;
bool mic = false;
mutex_lock(&info->lock);
if (!info->hpdet_active) {
dev_warn(arizona->dev, "Spurious HPDET IRQ\n");
mutex_unlock(&info->lock);
return IRQ_NONE;
}
ret = extcon_get_cable_state_(info->edev, EXTCON_MECHANICAL);
if (ret < 0) {
dev_err(arizona->dev, "Failed to check cable state: %d\n",
ret);
goto out;
} else if (!ret) {
dev_dbg(arizona->dev, "Ignoring HPDET for removed cable\n");
goto done;
}
ret = arizona_hpdet_read(info);
if (ret == -EAGAIN)
goto out;
else if (ret < 0)
goto done;
reading = ret;
regmap_update_bits(arizona->regmap,
ARIZONA_HEADPHONE_DETECT_1,
ARIZONA_HP_IMPEDANCE_RANGE_MASK | ARIZONA_HP_POLL,
0);
ret = arizona_hpdet_do_id(info, &reading, &mic);
if (ret == -EAGAIN)
goto out;
else if (ret < 0)
goto done;
if (reading >= 5000)
report = EXTCON_LINE_OUT;
else
report = EXTCON_HEADPHONE;
ret = extcon_set_cable_state_(info->edev, report, true);
if (ret != 0)
dev_err(arizona->dev, "Failed to report HP/line: %d\n",
ret);
done:
regmap_update_bits(arizona->regmap,
ARIZONA_HEADPHONE_DETECT_1,
ARIZONA_HP_IMPEDANCE_RANGE_MASK | ARIZONA_HP_POLL,
0);
arizona_extcon_hp_clamp(info, false);
if (id_gpio)
gpio_set_value_cansleep(id_gpio, 0);
regmap_update_bits(arizona->regmap,
ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_MODE_MASK, ARIZONA_ACCDET_MODE_MIC);
if (mic || info->mic)
arizona_start_mic(info);
if (info->hpdet_active) {
pm_runtime_put_autosuspend(info->dev);
info->hpdet_active = false;
}
info->hpdet_done = true;
out:
mutex_unlock(&info->lock);
return IRQ_HANDLED;
}
static void arizona_identify_headphone(struct arizona_extcon_info *info)
{
struct arizona *arizona = info->arizona;
int ret;
if (info->hpdet_done)
return;
dev_dbg(arizona->dev, "Starting HPDET\n");
pm_runtime_get(info->dev);
info->hpdet_active = true;
if (info->mic)
arizona_stop_mic(info);
arizona_extcon_hp_clamp(info, true);
ret = regmap_update_bits(arizona->regmap,
ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_MODE_MASK,
arizona->pdata.hpdet_channel);
if (ret != 0) {
dev_err(arizona->dev, "Failed to set HPDET mode: %d\n", ret);
goto err;
}
ret = regmap_update_bits(arizona->regmap, ARIZONA_HEADPHONE_DETECT_1,
ARIZONA_HP_POLL, ARIZONA_HP_POLL);
if (ret != 0) {
dev_err(arizona->dev, "Can't start HPDETL measurement: %d\n",
ret);
goto err;
}
return;
err:
regmap_update_bits(arizona->regmap, ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_MODE_MASK, ARIZONA_ACCDET_MODE_MIC);
ret = extcon_set_cable_state_(info->edev, EXTCON_HEADPHONE, true);
if (ret != 0)
dev_err(arizona->dev, "Failed to report headphone: %d\n", ret);
if (info->mic)
arizona_start_mic(info);
info->hpdet_active = false;
}
static void arizona_start_hpdet_acc_id(struct arizona_extcon_info *info)
{
struct arizona *arizona = info->arizona;
int hp_reading = 32;
bool mic;
int ret;
dev_dbg(arizona->dev, "Starting identification via HPDET\n");
pm_runtime_get_sync(info->dev);
info->hpdet_active = true;
arizona_extcon_hp_clamp(info, true);
ret = regmap_update_bits(arizona->regmap,
ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_SRC | ARIZONA_ACCDET_MODE_MASK,
info->micd_modes[0].src |
arizona->pdata.hpdet_channel);
if (ret != 0) {
dev_err(arizona->dev, "Failed to set HPDET mode: %d\n", ret);
goto err;
}
if (arizona->pdata.hpdet_acc_id_line) {
ret = regmap_update_bits(arizona->regmap,
ARIZONA_HEADPHONE_DETECT_1,
ARIZONA_HP_POLL, ARIZONA_HP_POLL);
if (ret != 0) {
dev_err(arizona->dev,
"Can't start HPDETL measurement: %d\n",
ret);
goto err;
}
} else {
arizona_hpdet_do_id(info, &hp_reading, &mic);
}
return;
err:
regmap_update_bits(arizona->regmap, ARIZONA_ACCESSORY_DETECT_MODE_1,
ARIZONA_ACCDET_MODE_MASK, ARIZONA_ACCDET_MODE_MIC);
ret = extcon_set_cable_state_(info->edev, EXTCON_HEADPHONE, true);
if (ret != 0)
dev_err(arizona->dev, "Failed to report headphone: %d\n", ret);
info->hpdet_active = false;
}
static void arizona_micd_timeout_work(struct work_struct *work)
{
struct arizona_extcon_info *info = container_of(work,
struct arizona_extcon_info,
micd_timeout_work.work);
mutex_lock(&info->lock);
dev_dbg(info->arizona->dev, "MICD timed out, reporting HP\n");
arizona_identify_headphone(info);
info->detecting = false;
arizona_stop_mic(info);
mutex_unlock(&info->lock);
}
static void arizona_micd_detect(struct work_struct *work)
{
struct arizona_extcon_info *info = container_of(work,
struct arizona_extcon_info,
micd_detect_work.work);
struct arizona *arizona = info->arizona;
unsigned int val = 0, lvl;
int ret, i, key;
cancel_delayed_work_sync(&info->micd_timeout_work);
mutex_lock(&info->lock);
ret = extcon_get_cable_state_(info->edev, EXTCON_MECHANICAL);
if (ret < 0) {
dev_err(arizona->dev, "Failed to check cable state: %d\n",
ret);
mutex_unlock(&info->lock);
return;
} else if (!ret) {
dev_dbg(arizona->dev, "Ignoring MICDET for removed cable\n");
mutex_unlock(&info->lock);
return;
}
for (i = 0; i < 10 && !(val & MICD_LVL_0_TO_8); i++) {
ret = regmap_read(arizona->regmap, ARIZONA_MIC_DETECT_3, &val);
if (ret != 0) {
dev_err(arizona->dev,
"Failed to read MICDET: %d\n", ret);
mutex_unlock(&info->lock);
return;
}
dev_dbg(arizona->dev, "MICDET: %x\n", val);
if (!(val & ARIZONA_MICD_VALID)) {
dev_warn(arizona->dev,
"Microphone detection state invalid\n");
mutex_unlock(&info->lock);
return;
}
}
if (i == 10 && !(val & MICD_LVL_0_TO_8)) {
dev_err(arizona->dev, "Failed to get valid MICDET value\n");
mutex_unlock(&info->lock);
return;
}
if (!(val & ARIZONA_MICD_STS)) {
dev_warn(arizona->dev, "Detected open circuit\n");
info->detecting = false;
goto handled;
}
if (info->detecting && (val & ARIZONA_MICD_LVL_8)) {
arizona_identify_headphone(info);
ret = extcon_set_cable_state_(info->edev,
EXTCON_MICROPHONE, true);
if (ret != 0)
dev_err(arizona->dev, "Headset report failed: %d\n",
ret);
ret = regulator_allow_bypass(info->micvdd, true);
if (ret != 0) {
dev_err(arizona->dev, "Failed to bypass MICVDD: %d\n",
ret);
}
info->mic = true;
info->detecting = false;
goto handled;
}
if (info->detecting && (val & MICD_LVL_1_TO_7)) {
if (info->jack_flips >= info->micd_num_modes * 10) {
dev_dbg(arizona->dev, "Detected HP/line\n");
arizona_identify_headphone(info);
info->detecting = false;
arizona_stop_mic(info);
} else {
info->micd_mode++;
if (info->micd_mode == info->micd_num_modes)
info->micd_mode = 0;
arizona_extcon_set_mode(info, info->micd_mode);
info->jack_flips++;
}
goto handled;
}
if (val & MICD_LVL_0_TO_7) {
if (info->mic) {
dev_dbg(arizona->dev, "Mic button detected\n");
lvl = val & ARIZONA_MICD_LVL_MASK;
lvl >>= ARIZONA_MICD_LVL_SHIFT;
for (i = 0; i < info->num_micd_ranges; i++)
input_report_key(info->input,
info->micd_ranges[i].key, 0);
WARN_ON(!lvl);
WARN_ON(ffs(lvl) - 1 >= info->num_micd_ranges);
if (lvl && ffs(lvl) - 1 < info->num_micd_ranges) {
key = info->micd_ranges[ffs(lvl) - 1].key;
input_report_key(info->input, key, 1);
input_sync(info->input);
}
} else if (info->detecting) {
dev_dbg(arizona->dev, "Headphone detected\n");
info->detecting = false;
arizona_stop_mic(info);
arizona_identify_headphone(info);
} else {
dev_warn(arizona->dev, "Button with no mic: %x\n",
val);
}
} else {
dev_dbg(arizona->dev, "Mic button released\n");
for (i = 0; i < info->num_micd_ranges; i++)
input_report_key(info->input,
info->micd_ranges[i].key, 0);
input_sync(info->input);
arizona_extcon_pulse_micbias(info);
}
handled:
if (info->detecting)
queue_delayed_work(system_power_efficient_wq,
&info->micd_timeout_work,
msecs_to_jiffies(info->micd_timeout));
pm_runtime_mark_last_busy(info->dev);
mutex_unlock(&info->lock);
}
static irqreturn_t arizona_micdet(int irq, void *data)
{
struct arizona_extcon_info *info = data;
struct arizona *arizona = info->arizona;
int debounce = arizona->pdata.micd_detect_debounce;
cancel_delayed_work_sync(&info->micd_detect_work);
cancel_delayed_work_sync(&info->micd_timeout_work);
mutex_lock(&info->lock);
if (!info->detecting)
debounce = 0;
mutex_unlock(&info->lock);
if (debounce)
queue_delayed_work(system_power_efficient_wq,
&info->micd_detect_work,
msecs_to_jiffies(debounce));
else
arizona_micd_detect(&info->micd_detect_work.work);
return IRQ_HANDLED;
}
static void arizona_hpdet_work(struct work_struct *work)
{
struct arizona_extcon_info *info = container_of(work,
struct arizona_extcon_info,
hpdet_work.work);
mutex_lock(&info->lock);
arizona_start_hpdet_acc_id(info);
mutex_unlock(&info->lock);
}
static irqreturn_t arizona_jackdet(int irq, void *data)
{
struct arizona_extcon_info *info = data;
struct arizona *arizona = info->arizona;
unsigned int val, present, mask;
bool cancelled_hp, cancelled_mic;
int ret, i;
cancelled_hp = cancel_delayed_work_sync(&info->hpdet_work);
cancelled_mic = cancel_delayed_work_sync(&info->micd_timeout_work);
pm_runtime_get_sync(info->dev);
mutex_lock(&info->lock);
if (arizona->pdata.jd_gpio5) {
mask = ARIZONA_MICD_CLAMP_STS;
if (arizona->pdata.jd_invert)
present = ARIZONA_MICD_CLAMP_STS;
else
present = 0;
} else {
mask = ARIZONA_JD1_STS;
if (arizona->pdata.jd_invert)
present = 0;
else
present = ARIZONA_JD1_STS;
}
ret = regmap_read(arizona->regmap, ARIZONA_AOD_IRQ_RAW_STATUS, &val);
if (ret != 0) {
dev_err(arizona->dev, "Failed to read jackdet status: %d\n",
ret);
mutex_unlock(&info->lock);
pm_runtime_put_autosuspend(info->dev);
return IRQ_NONE;
}
val &= mask;
if (val == info->last_jackdet) {
dev_dbg(arizona->dev, "Suppressing duplicate JACKDET\n");
if (cancelled_hp)
queue_delayed_work(system_power_efficient_wq,
&info->hpdet_work,
msecs_to_jiffies(HPDET_DEBOUNCE));
if (cancelled_mic) {
int micd_timeout = info->micd_timeout;
queue_delayed_work(system_power_efficient_wq,
&info->micd_timeout_work,
msecs_to_jiffies(micd_timeout));
}
goto out;
}
info->last_jackdet = val;
if (info->last_jackdet == present) {
dev_dbg(arizona->dev, "Detected jack\n");
ret = extcon_set_cable_state_(info->edev,
EXTCON_MECHANICAL, true);
if (ret != 0)
dev_err(arizona->dev, "Mechanical report failed: %d\n",
ret);
if (!arizona->pdata.hpdet_acc_id) {
info->detecting = true;
info->mic = false;
info->jack_flips = 0;
arizona_start_mic(info);
} else {
queue_delayed_work(system_power_efficient_wq,
&info->hpdet_work,
msecs_to_jiffies(HPDET_DEBOUNCE));
}
regmap_update_bits(arizona->regmap,
ARIZONA_JACK_DETECT_DEBOUNCE,
ARIZONA_MICD_CLAMP_DB | ARIZONA_JD1_DB, 0);
} else {
dev_dbg(arizona->dev, "Detected jack removal\n");
arizona_stop_mic(info);
info->num_hpdet_res = 0;
for (i = 0; i < ARRAY_SIZE(info->hpdet_res); i++)
info->hpdet_res[i] = 0;
info->mic = false;
info->hpdet_done = false;
info->hpdet_retried = false;
for (i = 0; i < info->num_micd_ranges; i++)
input_report_key(info->input,
info->micd_ranges[i].key, 0);
input_sync(info->input);
ret = extcon_update_state(info->edev, 0xffffffff, 0);
if (ret != 0)
dev_err(arizona->dev, "Removal report failed: %d\n",
ret);
regmap_update_bits(arizona->regmap,
ARIZONA_JACK_DETECT_DEBOUNCE,
ARIZONA_MICD_CLAMP_DB | ARIZONA_JD1_DB,
ARIZONA_MICD_CLAMP_DB | ARIZONA_JD1_DB);
}
if (arizona->pdata.micd_timeout)
info->micd_timeout = arizona->pdata.micd_timeout;
else
info->micd_timeout = DEFAULT_MICD_TIMEOUT;
out:
regmap_write(arizona->regmap, ARIZONA_AOD_WKUP_AND_TRIG,
ARIZONA_MICD_CLAMP_FALL_TRIG_STS |
ARIZONA_MICD_CLAMP_RISE_TRIG_STS |
ARIZONA_JD1_FALL_TRIG_STS |
ARIZONA_JD1_RISE_TRIG_STS);
mutex_unlock(&info->lock);
pm_runtime_mark_last_busy(info->dev);
pm_runtime_put_autosuspend(info->dev);
return IRQ_HANDLED;
}
static void arizona_micd_set_level(struct arizona *arizona, int index,
unsigned int level)
{
int reg;
unsigned int mask;
reg = ARIZONA_MIC_DETECT_LEVEL_4 - (index / 2);
if (!(index % 2)) {
mask = 0x3f00;
level <<= 8;
} else {
mask = 0x3f;
}
regmap_update_bits(arizona->regmap, reg, mask, level);
}
static int arizona_extcon_of_get_pdata(struct arizona *arizona)
{
struct arizona_pdata *pdata = &arizona->pdata;
unsigned int val = ARIZONA_ACCDET_MODE_HPL;
of_property_read_u32(arizona->dev->of_node, "wlf,hpdet-channel", &val);
switch (val) {
case ARIZONA_ACCDET_MODE_HPL:
case ARIZONA_ACCDET_MODE_HPR:
pdata->hpdet_channel = val;
break;
default:
dev_err(arizona->dev,
"Wrong wlf,hpdet-channel DT value %d\n", val);
pdata->hpdet_channel = ARIZONA_ACCDET_MODE_HPL;
}
return 0;
}
static int arizona_extcon_probe(struct platform_device *pdev)
{
struct arizona *arizona = dev_get_drvdata(pdev->dev.parent);
struct arizona_pdata *pdata = &arizona->pdata;
struct arizona_extcon_info *info;
unsigned int val;
unsigned int clamp_mode;
int jack_irq_fall, jack_irq_rise;
int ret, mode, i, j;
if (!arizona->dapm || !arizona->dapm->card)
return -EPROBE_DEFER;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
if (IS_ENABLED(CONFIG_OF)) {
if (!dev_get_platdata(arizona->dev))
arizona_extcon_of_get_pdata(arizona);
}
info->micvdd = devm_regulator_get(&pdev->dev, "MICVDD");
if (IS_ERR(info->micvdd)) {
ret = PTR_ERR(info->micvdd);
dev_err(arizona->dev, "Failed to get MICVDD: %d\n", ret);
return ret;
}
mutex_init(&info->lock);
info->arizona = arizona;
info->dev = &pdev->dev;
info->last_jackdet = ~(ARIZONA_MICD_CLAMP_STS | ARIZONA_JD1_STS);
INIT_DELAYED_WORK(&info->hpdet_work, arizona_hpdet_work);
INIT_DELAYED_WORK(&info->micd_detect_work, arizona_micd_detect);
INIT_DELAYED_WORK(&info->micd_timeout_work, arizona_micd_timeout_work);
platform_set_drvdata(pdev, info);
switch (arizona->type) {
case WM5102:
switch (arizona->rev) {
case 0:
info->micd_reva = true;
break;
default:
info->micd_clamp = true;
info->hpdet_ip_version = 1;
break;
}
break;
case WM5110:
case WM8280:
switch (arizona->rev) {
case 0 ... 2:
break;
default:
info->micd_clamp = true;
info->hpdet_ip_version = 2;
break;
}
break;
default:
break;
}
info->edev = devm_extcon_dev_allocate(&pdev->dev, arizona_cable);
if (IS_ERR(info->edev)) {
dev_err(&pdev->dev, "failed to allocate extcon device\n");
return -ENOMEM;
}
ret = devm_extcon_dev_register(&pdev->dev, info->edev);
if (ret < 0) {
dev_err(arizona->dev, "extcon_dev_register() failed: %d\n",
ret);
return ret;
}
info->input = devm_input_allocate_device(&pdev->dev);
if (!info->input) {
dev_err(arizona->dev, "Can't allocate input dev\n");
ret = -ENOMEM;
goto err_register;
}
info->input->name = "Headset";
info->input->phys = "arizona/extcon";
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
if (arizona->pdata.hpdet_id_gpio > 0) {
ret = devm_gpio_request_one(&pdev->dev,
arizona->pdata.hpdet_id_gpio,
GPIOF_OUT_INIT_LOW,
"HPDET");
if (ret != 0) {
dev_err(arizona->dev, "Failed to request GPIO%d: %d\n",
arizona->pdata.hpdet_id_gpio, ret);
goto err_register;
}
}
if (arizona->pdata.micd_bias_start_time)
regmap_update_bits(arizona->regmap, ARIZONA_MIC_DETECT_1,
ARIZONA_MICD_BIAS_STARTTIME_MASK,
arizona->pdata.micd_bias_start_time
<< ARIZONA_MICD_BIAS_STARTTIME_SHIFT);
if (arizona->pdata.micd_rate)
regmap_update_bits(arizona->regmap, ARIZONA_MIC_DETECT_1,
ARIZONA_MICD_RATE_MASK,
arizona->pdata.micd_rate
<< ARIZONA_MICD_RATE_SHIFT);
if (arizona->pdata.micd_dbtime)
regmap_update_bits(arizona->regmap, ARIZONA_MIC_DETECT_1,
ARIZONA_MICD_DBTIME_MASK,
arizona->pdata.micd_dbtime
<< ARIZONA_MICD_DBTIME_SHIFT);
BUILD_BUG_ON(ARRAY_SIZE(arizona_micd_levels) != 0x40);
if (arizona->pdata.num_micd_ranges) {
info->micd_ranges = pdata->micd_ranges;
info->num_micd_ranges = pdata->num_micd_ranges;
} else {
info->micd_ranges = micd_default_ranges;
info->num_micd_ranges = ARRAY_SIZE(micd_default_ranges);
}
if (arizona->pdata.num_micd_ranges > ARIZONA_MAX_MICD_RANGE) {
dev_err(arizona->dev, "Too many MICD ranges: %d\n",
arizona->pdata.num_micd_ranges);
}
if (info->num_micd_ranges > 1) {
for (i = 1; i < info->num_micd_ranges; i++) {
if (info->micd_ranges[i - 1].max >
info->micd_ranges[i].max) {
dev_err(arizona->dev,
"MICD ranges must be sorted\n");
ret = -EINVAL;
goto err_input;
}
}
}
regmap_update_bits(arizona->regmap, ARIZONA_MIC_DETECT_2,
ARIZONA_MICD_LVL_SEL_MASK, 0x81);
for (i = 0; i < info->num_micd_ranges; i++) {
for (j = 0; j < ARRAY_SIZE(arizona_micd_levels); j++)
if (arizona_micd_levels[j] >= info->micd_ranges[i].max)
break;
if (j == ARRAY_SIZE(arizona_micd_levels)) {
dev_err(arizona->dev, "Unsupported MICD level %d\n",
info->micd_ranges[i].max);
ret = -EINVAL;
goto err_input;
}
dev_dbg(arizona->dev, "%d ohms for MICD threshold %d\n",
arizona_micd_levels[j], i);
arizona_micd_set_level(arizona, i, j);
input_set_capability(info->input, EV_KEY,
info->micd_ranges[i].key);
regmap_update_bits(arizona->regmap, ARIZONA_MIC_DETECT_2,
1 << i, 1 << i);
}
for (; i < ARIZONA_MAX_MICD_RANGE; i++)
arizona_micd_set_level(arizona, i, 0x3f);
if (info->micd_clamp) {
if (arizona->pdata.jd_gpio5) {
val = 0xc101;
if (arizona->pdata.jd_gpio5_nopull)
val &= ~ARIZONA_GPN_PU;
regmap_write(arizona->regmap, ARIZONA_GPIO5_CTRL,
val);
if (arizona->pdata.jd_invert)
clamp_mode = ARIZONA_MICD_CLAMP_MODE_JDH_GP5H;
else
clamp_mode = ARIZONA_MICD_CLAMP_MODE_JDL_GP5H;
} else {
if (arizona->pdata.jd_invert)
clamp_mode = ARIZONA_MICD_CLAMP_MODE_JDH;
else
clamp_mode = ARIZONA_MICD_CLAMP_MODE_JDL;
}
regmap_update_bits(arizona->regmap,
ARIZONA_MICD_CLAMP_CONTROL,
ARIZONA_MICD_CLAMP_MODE_MASK, clamp_mode);
regmap_update_bits(arizona->regmap,
ARIZONA_JACK_DETECT_DEBOUNCE,
ARIZONA_MICD_CLAMP_DB,
ARIZONA_MICD_CLAMP_DB);
}
arizona_extcon_set_mode(info, 0);
pm_runtime_enable(&pdev->dev);
pm_runtime_idle(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
if (arizona->pdata.jd_gpio5) {
jack_irq_rise = ARIZONA_IRQ_MICD_CLAMP_RISE;
jack_irq_fall = ARIZONA_IRQ_MICD_CLAMP_FALL;
} else {
jack_irq_rise = ARIZONA_IRQ_JD_RISE;
jack_irq_fall = ARIZONA_IRQ_JD_FALL;
}
ret = arizona_request_irq(arizona, jack_irq_rise,
"JACKDET rise", arizona_jackdet, info);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to get JACKDET rise IRQ: %d\n",
ret);
goto err_input;
}
ret = arizona_set_irq_wake(arizona, jack_irq_rise, 1);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to set JD rise IRQ wake: %d\n",
ret);
goto err_rise;
}
ret = arizona_request_irq(arizona, jack_irq_fall,
"JACKDET fall", arizona_jackdet, info);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to get JD fall IRQ: %d\n", ret);
goto err_rise_wake;
}
ret = arizona_set_irq_wake(arizona, jack_irq_fall, 1);
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
ret = arizona_request_irq(arizona, ARIZONA_IRQ_HPDET,
"HPDET", arizona_hpdet_irq, info);
if (ret != 0) {
dev_err(&pdev->dev, "Failed to get HPDET IRQ: %d\n", ret);
goto err_micdet;
}
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
goto err_hpdet;
}
return 0;
err_hpdet:
arizona_free_irq(arizona, ARIZONA_IRQ_HPDET, info);
err_micdet:
arizona_free_irq(arizona, ARIZONA_IRQ_MICDET, info);
err_fall_wake:
arizona_set_irq_wake(arizona, jack_irq_fall, 0);
err_fall:
arizona_free_irq(arizona, jack_irq_fall, info);
err_rise_wake:
arizona_set_irq_wake(arizona, jack_irq_rise, 0);
err_rise:
arizona_free_irq(arizona, jack_irq_rise, info);
err_input:
err_register:
pm_runtime_disable(&pdev->dev);
return ret;
}
static int arizona_extcon_remove(struct platform_device *pdev)
{
struct arizona_extcon_info *info = platform_get_drvdata(pdev);
struct arizona *arizona = info->arizona;
int jack_irq_rise, jack_irq_fall;
pm_runtime_disable(&pdev->dev);
regmap_update_bits(arizona->regmap,
ARIZONA_MICD_CLAMP_CONTROL,
ARIZONA_MICD_CLAMP_MODE_MASK, 0);
if (arizona->pdata.jd_gpio5) {
jack_irq_rise = ARIZONA_IRQ_MICD_CLAMP_RISE;
jack_irq_fall = ARIZONA_IRQ_MICD_CLAMP_FALL;
} else {
jack_irq_rise = ARIZONA_IRQ_JD_RISE;
jack_irq_fall = ARIZONA_IRQ_JD_FALL;
}
arizona_set_irq_wake(arizona, jack_irq_rise, 0);
arizona_set_irq_wake(arizona, jack_irq_fall, 0);
arizona_free_irq(arizona, ARIZONA_IRQ_HPDET, info);
arizona_free_irq(arizona, ARIZONA_IRQ_MICDET, info);
arizona_free_irq(arizona, jack_irq_rise, info);
arizona_free_irq(arizona, jack_irq_fall, info);
cancel_delayed_work_sync(&info->hpdet_work);
regmap_update_bits(arizona->regmap, ARIZONA_JACK_DETECT_ANALOGUE,
ARIZONA_JD1_ENA, 0);
arizona_clk32k_disable(arizona);
return 0;
}
