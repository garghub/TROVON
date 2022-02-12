static int headset_get_switch(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = hs_switch;
return 0;
}
static int headset_set_switch(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
if (ucontrol->value.integer.value[0] == hs_switch)
return 0;
if (ucontrol->value.integer.value[0]) {
pr_debug("hs_set HS path\n");
snd_soc_dapm_enable_pin(&codec->dapm, "Headphones");
snd_soc_dapm_disable_pin(&codec->dapm, "EPOUT");
} else {
pr_debug("hs_set EP path\n");
snd_soc_dapm_disable_pin(&codec->dapm, "Headphones");
snd_soc_dapm_enable_pin(&codec->dapm, "EPOUT");
}
snd_soc_dapm_sync(&codec->dapm);
hs_switch = ucontrol->value.integer.value[0];
return 0;
}
static void lo_enable_out_pins(struct snd_soc_codec *codec)
{
snd_soc_dapm_enable_pin(&codec->dapm, "IHFOUTL");
snd_soc_dapm_enable_pin(&codec->dapm, "IHFOUTR");
snd_soc_dapm_enable_pin(&codec->dapm, "LINEOUTL");
snd_soc_dapm_enable_pin(&codec->dapm, "LINEOUTR");
snd_soc_dapm_enable_pin(&codec->dapm, "VIB1OUT");
snd_soc_dapm_enable_pin(&codec->dapm, "VIB2OUT");
if (hs_switch) {
snd_soc_dapm_enable_pin(&codec->dapm, "Headphones");
snd_soc_dapm_disable_pin(&codec->dapm, "EPOUT");
} else {
snd_soc_dapm_disable_pin(&codec->dapm, "Headphones");
snd_soc_dapm_enable_pin(&codec->dapm, "EPOUT");
}
}
static int lo_get_switch(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = lo_dac;
return 0;
}
static int lo_set_switch(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);
if (ucontrol->value.integer.value[0] == lo_dac)
return 0;
lo_enable_out_pins(codec);
switch (ucontrol->value.integer.value[0]) {
case 0:
pr_debug("set vibra path\n");
snd_soc_dapm_disable_pin(&codec->dapm, "VIB1OUT");
snd_soc_dapm_disable_pin(&codec->dapm, "VIB2OUT");
snd_soc_update_bits(codec, SN95031_LOCTL, 0x66, 0);
break;
case 1:
pr_debug("set hs path\n");
snd_soc_dapm_disable_pin(&codec->dapm, "Headphones");
snd_soc_dapm_disable_pin(&codec->dapm, "EPOUT");
snd_soc_update_bits(codec, SN95031_LOCTL, 0x66, 0x22);
break;
case 2:
pr_debug("set spkr path\n");
snd_soc_dapm_disable_pin(&codec->dapm, "IHFOUTL");
snd_soc_dapm_disable_pin(&codec->dapm, "IHFOUTR");
snd_soc_update_bits(codec, SN95031_LOCTL, 0x66, 0x44);
break;
case 3:
pr_debug("set null path\n");
snd_soc_dapm_disable_pin(&codec->dapm, "LINEOUTL");
snd_soc_dapm_disable_pin(&codec->dapm, "LINEOUTR");
snd_soc_update_bits(codec, SN95031_LOCTL, 0x66, 0x66);
break;
}
snd_soc_dapm_sync(&codec->dapm);
lo_dac = ucontrol->value.integer.value[0];
return 0;
}
static void mfld_jack_check(unsigned int intr_status)
{
struct mfld_jack_data jack_data;
jack_data.mfld_jack = &mfld_jack;
jack_data.intr_id = intr_status;
sn95031_jack_detection(&jack_data);
}
static int mfld_init(struct snd_soc_pcm_runtime *runtime)
{
struct snd_soc_codec *codec = runtime->codec;
struct snd_soc_dapm_context *dapm = &codec->dapm;
int ret_val;
snd_soc_dapm_new_controls(dapm, mfld_widgets, ARRAY_SIZE(mfld_widgets));
snd_soc_dapm_add_routes(dapm, mfld_map, ARRAY_SIZE(mfld_map));
snd_soc_dapm_enable_pin(dapm, "Headphones");
snd_soc_dapm_enable_pin(dapm, "Mic");
ret_val = snd_soc_add_codec_controls(codec, mfld_snd_controls,
ARRAY_SIZE(mfld_snd_controls));
if (ret_val) {
pr_err("soc_add_controls failed %d", ret_val);
return ret_val;
}
snd_soc_dapm_disable_pin(dapm, "Headphones");
snd_soc_dapm_disable_pin(dapm, "LINEOUTL");
snd_soc_dapm_disable_pin(dapm, "LINEOUTR");
lo_dac = 3;
hs_switch = 0;
snd_soc_dapm_disable_pin(dapm, "LINEINL");
snd_soc_dapm_disable_pin(dapm, "LINEINR");
ret_val = snd_soc_jack_new(codec, "Intel(R) MID Audio Jack",
SND_JACK_HEADSET | SND_JACK_BTN_0 |
SND_JACK_BTN_1, &mfld_jack);
if (ret_val) {
pr_err("jack creation failed\n");
return ret_val;
}
ret_val = snd_soc_jack_add_pins(&mfld_jack,
ARRAY_SIZE(mfld_jack_pins), mfld_jack_pins);
if (ret_val) {
pr_err("adding jack pins failed\n");
return ret_val;
}
ret_val = snd_soc_jack_add_zones(&mfld_jack,
ARRAY_SIZE(mfld_zones), mfld_zones);
if (ret_val) {
pr_err("adding jack zones failed\n");
return ret_val;
}
mfld_jack_check(MFLD_JACK_INSERT);
return ret_val;
}
static irqreturn_t snd_mfld_jack_intr_handler(int irq, void *dev)
{
struct mfld_mc_private *mc_private = (struct mfld_mc_private *) dev;
memcpy_fromio(&mc_private->interrupt_status,
((void *)(mc_private->int_base)),
sizeof(u8));
return IRQ_WAKE_THREAD;
}
static irqreturn_t snd_mfld_jack_detection(int irq, void *data)
{
struct mfld_mc_private *mc_drv_ctx = (struct mfld_mc_private *) data;
if (mfld_jack.codec == NULL)
return IRQ_HANDLED;
mfld_jack_check(mc_drv_ctx->interrupt_status);
return IRQ_HANDLED;
}
static int snd_mfld_mc_probe(struct platform_device *pdev)
{
int ret_val = 0, irq;
struct mfld_mc_private *mc_drv_ctx;
struct resource *irq_mem;
pr_debug("snd_mfld_mc_probe called\n");
irq = platform_get_irq(pdev, 0);
mc_drv_ctx = kzalloc(sizeof(*mc_drv_ctx), GFP_ATOMIC);
if (!mc_drv_ctx) {
pr_err("allocation failed\n");
return -ENOMEM;
}
irq_mem = platform_get_resource_byname(
pdev, IORESOURCE_MEM, "IRQ_BASE");
if (!irq_mem) {
pr_err("no mem resource given\n");
ret_val = -ENODEV;
goto unalloc;
}
mc_drv_ctx->int_base = ioremap_nocache(irq_mem->start,
resource_size(irq_mem));
if (!mc_drv_ctx->int_base) {
pr_err("Mapping of cache failed\n");
ret_val = -ENOMEM;
goto unalloc;
}
ret_val = request_threaded_irq(irq, snd_mfld_jack_intr_handler,
snd_mfld_jack_detection,
IRQF_SHARED, pdev->dev.driver->name, mc_drv_ctx);
if (ret_val) {
pr_err("cannot register IRQ\n");
goto unalloc;
}
snd_soc_card_mfld.dev = &pdev->dev;
ret_val = snd_soc_register_card(&snd_soc_card_mfld);
if (ret_val) {
pr_debug("snd_soc_register_card failed %d\n", ret_val);
goto freeirq;
}
platform_set_drvdata(pdev, mc_drv_ctx);
pr_debug("successfully exited probe\n");
return ret_val;
freeirq:
free_irq(irq, mc_drv_ctx);
unalloc:
kfree(mc_drv_ctx);
return ret_val;
}
static int snd_mfld_mc_remove(struct platform_device *pdev)
{
struct mfld_mc_private *mc_drv_ctx = platform_get_drvdata(pdev);
pr_debug("snd_mfld_mc_remove called\n");
free_irq(platform_get_irq(pdev, 0), mc_drv_ctx);
snd_soc_unregister_card(&snd_soc_card_mfld);
kfree(mc_drv_ctx);
platform_set_drvdata(pdev, NULL);
return 0;
}
