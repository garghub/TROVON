static bool ts3a227e_readable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TS3A227E_REG_DEVICE_ID ... TS3A227E_REG_KP_THRESHOLD_3:
return true;
default:
return false;
}
}
static bool ts3a227e_writeable_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TS3A227E_REG_INTERRUPT_DISABLE ... TS3A227E_REG_SWITCH_CONTROL_2:
case TS3A227E_REG_KP_THRESHOLD_1 ... TS3A227E_REG_KP_THRESHOLD_3:
return true;
default:
return false;
}
}
static bool ts3a227e_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TS3A227E_REG_INTERRUPT ... TS3A227E_REG_INTERRUPT_DISABLE:
case TS3A227E_REG_SETTING_2:
case TS3A227E_REG_SWITCH_STATUS_1 ... TS3A227E_REG_ADC_OUTPUT:
return true;
default:
return false;
}
}
static void ts3a227e_jack_report(struct ts3a227e *ts3a227e)
{
unsigned int i;
int report = 0;
if (!ts3a227e->jack)
return;
if (ts3a227e->plugged)
report = SND_JACK_HEADPHONE;
if (ts3a227e->mic_present)
report |= SND_JACK_MICROPHONE;
for (i = 0; i < TS3A227E_NUM_BUTTONS; i++) {
if (ts3a227e->buttons_held & (1 << i))
report |= ts3a227e_buttons[i];
}
snd_soc_jack_report(ts3a227e->jack, report, TS3A227E_JACK_MASK);
}
static void ts3a227e_new_jack_state(struct ts3a227e *ts3a227e, unsigned acc_reg)
{
bool plugged, mic_present;
plugged = !!(acc_reg & JACK_INSERTED);
mic_present = plugged && !!(acc_reg & EITHER_MIC_MASK);
ts3a227e->plugged = plugged;
if (mic_present != ts3a227e->mic_present) {
ts3a227e->mic_present = mic_present;
ts3a227e->buttons_held = 0;
if (mic_present) {
regmap_update_bits(ts3a227e->regmap,
TS3A227E_REG_SETTING_2,
KP_ENABLE, KP_ENABLE);
}
}
}
static irqreturn_t ts3a227e_interrupt(int irq, void *data)
{
struct ts3a227e *ts3a227e = (struct ts3a227e *)data;
struct regmap *regmap = ts3a227e->regmap;
unsigned int int_reg, kp_int_reg, acc_reg, i;
struct device *dev = ts3a227e->dev;
int ret;
ret = regmap_read(regmap, TS3A227E_REG_INTERRUPT, &int_reg);
if (ret) {
dev_err(dev, "failed to clear interrupt ret=%d\n", ret);
return IRQ_NONE;
}
if (int_reg & (DETECTION_COMPLETE_EVENT | INS_REM_EVENT)) {
regmap_read(regmap, TS3A227E_REG_ACCESSORY_STATUS, &acc_reg);
ts3a227e_new_jack_state(ts3a227e, acc_reg);
}
ret = regmap_read(regmap, TS3A227E_REG_KP_INTERRUPT, &kp_int_reg);
if (ret) {
dev_err(dev, "failed to clear key interrupt ret=%d\n", ret);
return IRQ_NONE;
}
for (i = 0; i < TS3A227E_NUM_BUTTONS; i++) {
if (kp_int_reg & PRESS_MASK(i))
ts3a227e->buttons_held |= (1 << i);
if (kp_int_reg & RELEASE_MASK(i))
ts3a227e->buttons_held &= ~(1 << i);
}
ts3a227e_jack_report(ts3a227e);
return IRQ_HANDLED;
}
int ts3a227e_enable_jack_detect(struct snd_soc_component *component,
struct snd_soc_jack *jack)
{
struct ts3a227e *ts3a227e = snd_soc_component_get_drvdata(component);
snd_jack_set_key(jack->jack, SND_JACK_BTN_0, KEY_MEDIA);
snd_jack_set_key(jack->jack, SND_JACK_BTN_1, KEY_VOICECOMMAND);
snd_jack_set_key(jack->jack, SND_JACK_BTN_2, KEY_VOLUMEUP);
snd_jack_set_key(jack->jack, SND_JACK_BTN_3, KEY_VOLUMEDOWN);
ts3a227e->jack = jack;
ts3a227e_jack_report(ts3a227e);
return 0;
}
static int ts3a227e_parse_device_property(struct ts3a227e *ts3a227e,
struct device *dev)
{
u32 micbias;
int err;
err = device_property_read_u32(dev, "ti,micbias", &micbias);
if (!err) {
regmap_update_bits(ts3a227e->regmap, TS3A227E_REG_SETTING_3,
MICBIAS_SETTING_MASK,
(micbias & 0x07) << MICBIAS_SETTING_SFT);
}
return 0;
}
static int ts3a227e_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct ts3a227e *ts3a227e;
struct device *dev = &i2c->dev;
int ret;
unsigned int acc_reg;
ts3a227e = devm_kzalloc(&i2c->dev, sizeof(*ts3a227e), GFP_KERNEL);
if (ts3a227e == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, ts3a227e);
ts3a227e->dev = dev;
ts3a227e->irq = i2c->irq;
ts3a227e->regmap = devm_regmap_init_i2c(i2c, &ts3a227e_regmap_config);
if (IS_ERR(ts3a227e->regmap))
return PTR_ERR(ts3a227e->regmap);
ret = ts3a227e_parse_device_property(ts3a227e, dev);
if (ret) {
dev_err(dev, "Failed to parse device property: %d\n", ret);
return ret;
}
ret = devm_request_threaded_irq(dev, i2c->irq, NULL, ts3a227e_interrupt,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"TS3A227E", ts3a227e);
if (ret) {
dev_err(dev, "Cannot request irq %d (%d)\n", i2c->irq, ret);
return ret;
}
ret = devm_snd_soc_register_component(&i2c->dev, &ts3a227e_soc_driver,
NULL, 0);
if (ret)
return ret;
regmap_update_bits(ts3a227e->regmap, TS3A227E_REG_INTERRUPT_DISABLE,
INTB_DISABLE | ADC_COMPLETE_INT_DISABLE,
ADC_COMPLETE_INT_DISABLE);
regmap_read(ts3a227e->regmap, TS3A227E_REG_ACCESSORY_STATUS, &acc_reg);
ts3a227e_new_jack_state(ts3a227e, acc_reg);
ts3a227e_jack_report(ts3a227e);
return 0;
}
static int ts3a227e_suspend(struct device *dev)
{
struct ts3a227e *ts3a227e = dev_get_drvdata(dev);
dev_dbg(ts3a227e->dev, "suspend disable irq\n");
disable_irq(ts3a227e->irq);
return 0;
}
static int ts3a227e_resume(struct device *dev)
{
struct ts3a227e *ts3a227e = dev_get_drvdata(dev);
dev_dbg(ts3a227e->dev, "resume enable irq\n");
enable_irq(ts3a227e->irq);
return 0;
}
