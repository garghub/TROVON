static void snd_hda_generate_beep(struct work_struct *work)
{
struct hda_beep *beep =
container_of(work, struct hda_beep, beep_work);
struct hda_codec *codec = beep->codec;
if (!beep->enabled)
return;
snd_hda_codec_write(codec, beep->nid, 0,
AC_VERB_SET_BEEP_CONTROL, beep->tone);
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
static void snd_hda_do_detach(struct hda_beep *beep)
{
input_unregister_device(beep->dev);
beep->dev = NULL;
cancel_work_sync(&beep->beep_work);
snd_hda_codec_write(beep->codec, beep->nid, 0,
AC_VERB_SET_BEEP_CONTROL, 0);
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
static void snd_hda_do_register(struct work_struct *work)
{
struct hda_beep *beep =
container_of(work, struct hda_beep, register_work);
mutex_lock(&beep->mutex);
if (beep->enabled && !beep->dev)
snd_hda_do_attach(beep);
mutex_unlock(&beep->mutex);
}
static void snd_hda_do_unregister(struct work_struct *work)
{
struct hda_beep *beep =
container_of(work, struct hda_beep, unregister_work.work);
mutex_lock(&beep->mutex);
if (!beep->enabled && beep->dev)
snd_hda_do_detach(beep);
mutex_unlock(&beep->mutex);
}
int snd_hda_enable_beep_device(struct hda_codec *codec, int enable)
{
struct hda_beep *beep = codec->beep;
enable = !!enable;
if (beep == NULL)
return 0;
if (beep->enabled != enable) {
beep->enabled = enable;
if (!enable) {
snd_hda_codec_write(beep->codec, beep->nid, 0,
AC_VERB_SET_BEEP_CONTROL, 0);
}
if (beep->mode == HDA_BEEP_MODE_SWREG) {
if (enable) {
cancel_delayed_work(&beep->unregister_work);
schedule_work(&beep->register_work);
} else {
schedule_delayed_work(&beep->unregister_work,
HZ);
}
}
return 1;
}
return 0;
}
int snd_hda_attach_beep_device(struct hda_codec *codec, int nid)
{
struct hda_beep *beep;
if (!snd_hda_get_bool_hint(codec, "beep"))
return 0;
if (codec->beep_mode == HDA_BEEP_MODE_OFF)
return 0;
beep = kzalloc(sizeof(*beep), GFP_KERNEL);
if (beep == NULL)
return -ENOMEM;
snprintf(beep->phys, sizeof(beep->phys),
"card%d/codec#%d/beep0", codec->bus->card->number, codec->addr);
snd_hda_codec_write(codec, nid, 0,
AC_VERB_SET_DIGI_CONVERT_2, 0x01);
beep->nid = nid;
beep->codec = codec;
beep->mode = codec->beep_mode;
codec->beep = beep;
INIT_WORK(&beep->register_work, &snd_hda_do_register);
INIT_DELAYED_WORK(&beep->unregister_work, &snd_hda_do_unregister);
INIT_WORK(&beep->beep_work, &snd_hda_generate_beep);
mutex_init(&beep->mutex);
if (beep->mode == HDA_BEEP_MODE_ON) {
int err = snd_hda_do_attach(beep);
if (err < 0) {
kfree(beep);
codec->beep = NULL;
return err;
}
}
return 0;
}
void snd_hda_detach_beep_device(struct hda_codec *codec)
{
struct hda_beep *beep = codec->beep;
if (beep) {
cancel_work_sync(&beep->register_work);
cancel_delayed_work(&beep->unregister_work);
if (beep->dev)
snd_hda_do_detach(beep);
codec->beep = NULL;
kfree(beep);
}
}
