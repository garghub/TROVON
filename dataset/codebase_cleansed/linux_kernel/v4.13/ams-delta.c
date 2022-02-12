static int ams_delta_set_audio_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_context *dapm = &card->dapm;
struct soc_enum *control = (struct soc_enum *)kcontrol->private_value;
unsigned short pins;
int pin, changed = 0;
if (!cx20442_codec->hw_write)
return -EUNATCH;
if (ucontrol->value.enumerated.item[0] >= control->items)
return -EINVAL;
snd_soc_dapm_mutex_lock(dapm);
pins = ams_delta_audio_mode_pins[ucontrol->value.enumerated.item[0]];
pin = !!(pins & (1 << AMS_DELTA_MOUTHPIECE));
if (pin != snd_soc_dapm_get_pin_status(dapm, "Mouthpiece")) {
changed = 1;
if (pin)
snd_soc_dapm_enable_pin_unlocked(dapm, "Mouthpiece");
else
snd_soc_dapm_disable_pin_unlocked(dapm, "Mouthpiece");
}
pin = !!(pins & (1 << AMS_DELTA_EARPIECE));
if (pin != snd_soc_dapm_get_pin_status(dapm, "Earpiece")) {
changed = 1;
if (pin)
snd_soc_dapm_enable_pin_unlocked(dapm, "Earpiece");
else
snd_soc_dapm_disable_pin_unlocked(dapm, "Earpiece");
}
pin = !!(pins & (1 << AMS_DELTA_MICROPHONE));
if (pin != snd_soc_dapm_get_pin_status(dapm, "Microphone")) {
changed = 1;
if (pin)
snd_soc_dapm_enable_pin_unlocked(dapm, "Microphone");
else
snd_soc_dapm_disable_pin_unlocked(dapm, "Microphone");
}
pin = !!(pins & (1 << AMS_DELTA_SPEAKER));
if (pin != snd_soc_dapm_get_pin_status(dapm, "Speaker")) {
changed = 1;
if (pin)
snd_soc_dapm_enable_pin_unlocked(dapm, "Speaker");
else
snd_soc_dapm_disable_pin_unlocked(dapm, "Speaker");
}
pin = !!(pins & (1 << AMS_DELTA_AGC));
if (pin != ams_delta_audio_agc) {
ams_delta_audio_agc = pin;
changed = 1;
if (pin)
snd_soc_dapm_enable_pin_unlocked(dapm, "AGCIN");
else
snd_soc_dapm_disable_pin_unlocked(dapm, "AGCIN");
}
if (changed)
snd_soc_dapm_sync_unlocked(dapm);
snd_soc_dapm_mutex_unlock(dapm);
return changed;
}
static int ams_delta_get_audio_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
struct snd_soc_dapm_context *dapm = &card->dapm;
unsigned short pins, mode;
pins = ((snd_soc_dapm_get_pin_status(dapm, "Mouthpiece") <<
AMS_DELTA_MOUTHPIECE) |
(snd_soc_dapm_get_pin_status(dapm, "Earpiece") <<
AMS_DELTA_EARPIECE));
if (pins)
pins |= (snd_soc_dapm_get_pin_status(dapm, "Microphone") <<
AMS_DELTA_MICROPHONE);
else
pins = ((snd_soc_dapm_get_pin_status(dapm, "Microphone") <<
AMS_DELTA_MICROPHONE) |
(snd_soc_dapm_get_pin_status(dapm, "Speaker") <<
AMS_DELTA_SPEAKER) |
(ams_delta_audio_agc << AMS_DELTA_AGC));
for (mode = 0; mode < ARRAY_SIZE(ams_delta_audio_mode); mode++)
if (pins == ams_delta_audio_mode_pins[mode])
break;
if (mode >= ARRAY_SIZE(ams_delta_audio_mode))
return -EINVAL;
ucontrol->value.enumerated.item[0] = mode;
return 0;
}
static void cx81801_timeout(unsigned long data)
{
int muted;
spin_lock(&ams_delta_lock);
cx81801_cmd_pending = 0;
muted = ams_delta_muted;
spin_unlock(&ams_delta_lock);
if (!muted)
ams_delta_latch2_write(AMS_DELTA_LATCH2_MODEM_CODEC, 0);
}
static int cx81801_open(struct tty_struct *tty)
{
int ret;
if (!cx20442_codec)
return -ENODEV;
tty->disc_data = cx20442_codec;
ret = v253_ops.open(tty);
if (ret < 0)
tty->disc_data = NULL;
return ret;
}
static void cx81801_close(struct tty_struct *tty)
{
struct snd_soc_codec *codec = tty->disc_data;
struct snd_soc_dapm_context *dapm = &codec->component.card->dapm;
del_timer_sync(&cx81801_timer);
INIT_LIST_HEAD(&ams_delta_hook_switch.pins);
if (!codec)
return;
v253_ops.close(tty);
snd_soc_dapm_mutex_lock(dapm);
snd_soc_dapm_disable_pin_unlocked(dapm, "Mouthpiece");
snd_soc_dapm_enable_pin_unlocked(dapm, "Earpiece");
snd_soc_dapm_enable_pin_unlocked(dapm, "Microphone");
snd_soc_dapm_disable_pin_unlocked(dapm, "Speaker");
snd_soc_dapm_disable_pin_unlocked(dapm, "AGCIN");
snd_soc_dapm_sync_unlocked(dapm);
snd_soc_dapm_mutex_unlock(dapm);
}
static int cx81801_hangup(struct tty_struct *tty)
{
cx81801_close(tty);
return 0;
}
static void cx81801_receive(struct tty_struct *tty,
const unsigned char *cp, char *fp, int count)
{
struct snd_soc_codec *codec = tty->disc_data;
const unsigned char *c;
int apply, ret;
if (!codec)
return;
if (!codec->hw_write) {
setup_timer(&cx81801_timer, cx81801_timeout, 0);
v253_ops.receive_buf(tty, cp, fp, count);
ret = snd_soc_jack_add_pins(&ams_delta_hook_switch,
ARRAY_SIZE(ams_delta_hook_switch_pins),
ams_delta_hook_switch_pins);
if (ret)
dev_warn(codec->dev,
"Failed to link hook switch to DAPM pins, "
"will continue with hook switch unlinked.\n");
return;
}
v253_ops.receive_buf(tty, cp, fp, count);
for (c = &cp[count - 1]; c >= cp; c--) {
if (*c != '\r')
continue;
spin_lock_bh(&ams_delta_lock);
mod_timer(&cx81801_timer, jiffies + msecs_to_jiffies(150));
apply = !ams_delta_muted && !cx81801_cmd_pending;
cx81801_cmd_pending = 1;
spin_unlock_bh(&ams_delta_lock);
if (apply)
ams_delta_latch2_write(AMS_DELTA_LATCH2_MODEM_CODEC,
AMS_DELTA_LATCH2_MODEM_CODEC);
break;
}
}
static void cx81801_wakeup(struct tty_struct *tty)
{
v253_ops.write_wakeup(tty);
}
static int ams_delta_digital_mute(struct snd_soc_dai *dai, int mute)
{
int apply;
if (ams_delta_muted == mute)
return 0;
spin_lock_bh(&ams_delta_lock);
ams_delta_muted = mute;
apply = !cx81801_cmd_pending;
spin_unlock_bh(&ams_delta_lock);
if (apply)
ams_delta_latch2_write(AMS_DELTA_LATCH2_MODEM_CODEC,
mute ? AMS_DELTA_LATCH2_MODEM_CODEC : 0);
return 0;
}
static int ams_delta_startup(struct snd_pcm_substream *substream)
{
return ams_delta_digital_mute(NULL, 0);
}
static void ams_delta_shutdown(struct snd_pcm_substream *substream)
{
ams_delta_digital_mute(NULL, 1);
}
static int ams_delta_cx20442_init(struct snd_soc_pcm_runtime *rtd)
{
struct snd_soc_dai *codec_dai = rtd->codec_dai;
struct snd_soc_card *card = rtd->card;
struct snd_soc_dapm_context *dapm = &card->dapm;
int ret;
cx20442_codec = rtd->codec;
if (!codec_dai->driver->ops) {
codec_dai->driver->ops = &ams_delta_dai_ops;
} else {
ams_delta_ops.startup = ams_delta_startup;
ams_delta_ops.shutdown = ams_delta_shutdown;
}
ret = snd_soc_card_jack_new(card, "hook_switch", SND_JACK_HEADSET,
&ams_delta_hook_switch, NULL, 0);
if (ret)
dev_warn(card->dev,
"Failed to allocate resources for hook switch, "
"will continue without one.\n");
else {
ret = snd_soc_jack_add_gpios(&ams_delta_hook_switch,
ARRAY_SIZE(ams_delta_hook_switch_gpios),
ams_delta_hook_switch_gpios);
if (ret)
dev_warn(card->dev,
"Failed to set up hook switch GPIO line, "
"will continue with hook switch inactive.\n");
}
ret = tty_register_ldisc(N_V253, &cx81801_ops);
if (ret) {
dev_warn(card->dev,
"Failed to register line discipline, "
"will continue without any controls.\n");
return 0;
}
snd_soc_dapm_disable_pin(dapm, "Mouthpiece");
snd_soc_dapm_disable_pin(dapm, "Speaker");
snd_soc_dapm_disable_pin(dapm, "AGCIN");
snd_soc_dapm_disable_pin(dapm, "AGCOUT");
return 0;
}
static int ams_delta_card_remove(struct snd_soc_card *card)
{
snd_soc_jack_free_gpios(&ams_delta_hook_switch,
ARRAY_SIZE(ams_delta_hook_switch_gpios),
ams_delta_hook_switch_gpios);
return 0;
}
static int ams_delta_probe(struct platform_device *pdev)
{
struct snd_soc_card *card = &ams_delta_audio_card;
int ret;
card->dev = &pdev->dev;
ret = snd_soc_register_card(card);
if (ret) {
dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
card->dev = NULL;
return ret;
}
return 0;
}
static int ams_delta_remove(struct platform_device *pdev)
{
struct snd_soc_card *card = platform_get_drvdata(pdev);
if (tty_unregister_ldisc(N_V253) != 0)
dev_warn(&pdev->dev,
"failed to unregister V253 line discipline\n");
snd_soc_unregister_card(card);
card->dev = NULL;
return 0;
}
