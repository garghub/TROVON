static void snd_hda_generate_beep(struct work_struct *work)
{
struct hda_beep *beep =
container_of(work, struct hda_beep, beep_work);
struct hda_codec *codec = beep->codec;
int tone;
if (!beep->enabled)
return;
tone = beep->tone;
if (tone && !beep->playing) {
snd_hda_power_up(codec);
beep->playing = 1;
}
snd_hda_codec_write(codec, beep->nid, 0,
AC_VERB_SET_BEEP_CONTROL, tone);
if (!tone && beep->playing) {
beep->playing = 0;
snd_hda_power_down(codec);
}
}
static int beep_linear_tone(struct hda_beep *beep, int hz)
{
if (hz <= 0)
return 0;
hz *= 1000;
hz = hz - DIGBEEP_HZ_MIN
+ DIGBEEP_HZ_STEP / 2;
if (hz < 0)
hz = 0;
else if (hz >= (DIGBEEP_HZ_MAX - DIGBEEP_HZ_MIN))
hz = 1;
else {
hz /= DIGBEEP_HZ_STEP;
hz = 255 - hz;
}
return hz;
}
static int beep_standard_tone(struct hda_beep *beep, int hz)
{
if (hz <= 0)
return 0;
hz = 12000 / hz;
if (hz > 0xff)
return 0xff;
if (hz <= 0)
return 1;
return hz;
}
static int snd_hda_beep_event(struct input_dev *dev, unsigned int type,
unsigned int code, int hz)
{
struct hda_beep *beep = input_get_drvdata(dev);
switch (code) {
case SND_BELL:
if (hz)
hz = 1000;
case SND_TONE:
if (beep->linear_tone)
beep->tone = beep_linear_tone(beep, hz);
else
beep->tone = beep_standard_tone(beep, hz);
break;
default:
return -1;
}
schedule_work(&beep->beep_work);
return 0;
}
static void turn_off_beep(struct hda_beep *beep)
{
cancel_work_sync(&beep->beep_work);
if (beep->playing) {
snd_hda_codec_write(beep->codec, beep->nid, 0,
AC_VERB_SET_BEEP_CONTROL, 0);
beep->playing = 0;
snd_hda_power_down(beep->codec);
}
}
static void snd_hda_do_detach(struct hda_beep *beep)
{
input_unregister_device(beep->dev);
beep->dev = NULL;
turn_off_beep(beep);
}
static int snd_hda_do_attach(struct hda_beep *beep)
{
struct input_dev *input_dev;
struct hda_codec *codec = beep->codec;
int err;
input_dev = input_allocate_device();
if (!input_dev) {
printk(KERN_INFO "hda_beep: unable to allocate input device\n");
return -ENOMEM;
}
input_dev->name = "HDA Digital PCBeep";
input_dev->phys = beep->phys;
input_dev->id.bustype = BUS_PCI;
input_dev->id.vendor = codec->vendor_id >> 16;
input_dev->id.product = codec->vendor_id & 0xffff;
input_dev->id.version = 0x01;
input_dev->evbit[0] = BIT_MASK(EV_SND);
input_dev->sndbit[0] = BIT_MASK(SND_BELL) | BIT_MASK(SND_TONE);
input_dev->event = snd_hda_beep_event;
input_dev->dev.parent = &codec->bus->pci->dev;
input_set_drvdata(input_dev, beep);
err = input_register_device(input_dev);
if (err < 0) {
input_free_device(input_dev);
printk(KERN_INFO "hda_beep: unable to register input device\n");
return err;
}
beep->dev = input_dev;
return 0;
}
int snd_hda_enable_beep_device(struct hda_codec *codec, int enable)
{
struct hda_beep *beep = codec->beep;
if (!beep)
return 0;
enable = !!enable;
if (beep->enabled != enable) {
beep->enabled = enable;
if (!enable)
turn_off_beep(beep);
return 1;
}
return 0;
}
int snd_hda_attach_beep_device(struct hda_codec *codec, int nid)
{
struct hda_beep *beep;
int err;
if (!snd_hda_get_bool_hint(codec, "beep"))
return 0;
if (codec->beep_mode == HDA_BEEP_MODE_OFF)
return 0;
beep = kzalloc(sizeof(*beep), GFP_KERNEL);
if (beep == NULL)
return -ENOMEM;
snprintf(beep->phys, sizeof(beep->phys),
"card%d/codec#%d/beep0", codec->bus->card->number, codec->addr);
snd_hda_codec_write_cache(codec, nid, 0,
AC_VERB_SET_DIGI_CONVERT_2, 0x01);
beep->nid = nid;
beep->codec = codec;
codec->beep = beep;
INIT_WORK(&beep->beep_work, &snd_hda_generate_beep);
mutex_init(&beep->mutex);
err = snd_hda_do_attach(beep);
if (err < 0) {
kfree(beep);
codec->beep = NULL;
return err;
}
return 0;
}
void snd_hda_detach_beep_device(struct hda_codec *codec)
{
struct hda_beep *beep = codec->beep;
if (beep) {
if (beep->dev)
snd_hda_do_detach(beep);
codec->beep = NULL;
kfree(beep);
}
}
static bool ctl_has_mute(struct snd_kcontrol *kcontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
return query_amp_caps(codec, get_amp_nid(kcontrol),
get_amp_direction(kcontrol)) & AC_AMPCAP_MUTE;
}
int snd_hda_mixer_amp_switch_get_beep(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hda_beep *beep = codec->beep;
if (beep && (!beep->enabled || !ctl_has_mute(kcontrol))) {
ucontrol->value.integer.value[0] =
ucontrol->value.integer.value[1] = beep->enabled;
return 0;
}
return snd_hda_mixer_amp_switch_get(kcontrol, ucontrol);
}
int snd_hda_mixer_amp_switch_put_beep(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct hda_beep *beep = codec->beep;
if (beep) {
u8 chs = get_amp_channels(kcontrol);
int enable = 0;
long *valp = ucontrol->value.integer.value;
if (chs & 1) {
enable |= *valp;
valp++;
}
if (chs & 2)
enable |= *valp;
snd_hda_enable_beep_device(codec, enable);
}
if (!ctl_has_mute(kcontrol))
return 0;
return snd_hda_mixer_amp_switch_put(kcontrol, ucontrol);
}
