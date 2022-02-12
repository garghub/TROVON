static int si3054_switch_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uvalue)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
u16 reg = PRIVATE_REG(kcontrol->private_value);
u16 mask = PRIVATE_MASK(kcontrol->private_value);
uvalue->value.integer.value[0] = (GET_REG(codec, reg)) & mask ? 1 : 0 ;
return 0;
}
static int si3054_switch_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *uvalue)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
u16 reg = PRIVATE_REG(kcontrol->private_value);
u16 mask = PRIVATE_MASK(kcontrol->private_value);
if (uvalue->value.integer.value[0])
SET_REG_CACHE(codec, reg, (GET_REG(codec, reg)) | mask);
else
SET_REG_CACHE(codec, reg, (GET_REG(codec, reg)) & ~mask);
return 0;
}
static int si3054_build_controls(struct hda_codec *codec)
{
return snd_hda_add_new_ctls(codec, si3054_modem_mixer);
}
static int si3054_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
u16 val;
SET_REG(codec, SI3054_LINE_RATE, substream->runtime->rate);
val = GET_REG(codec, SI3054_LINE_LEVEL);
val &= 0xff << (8 * (substream->stream != SNDRV_PCM_STREAM_PLAYBACK));
val |= ((stream_tag & 0xf) << 4) << (8 * (substream->stream == SNDRV_PCM_STREAM_PLAYBACK));
SET_REG(codec, SI3054_LINE_LEVEL, val);
snd_hda_codec_setup_stream(codec, hinfo->nid,
stream_tag, 0, format);
return 0;
}
static int si3054_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
static unsigned int rates[] = { 8000, 9600, 16000 };
static struct snd_pcm_hw_constraint_list hw_constraints_rates = {
.count = ARRAY_SIZE(rates),
.list = rates,
.mask = 0,
};
substream->runtime->hw.period_bytes_min = 80;
return snd_pcm_hw_constraint_list(substream->runtime, 0,
SNDRV_PCM_HW_PARAM_RATE, &hw_constraints_rates);
}
static int si3054_build_pcms(struct hda_codec *codec)
{
struct si3054_spec *spec = codec->spec;
struct hda_pcm *info = &spec->pcm;
codec->num_pcms = 1;
codec->pcm_info = info;
info->name = "Si3054 Modem";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = si3054_pcm;
info->stream[SNDRV_PCM_STREAM_CAPTURE] = si3054_pcm;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = codec->mfg;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = codec->mfg;
info->pcm_type = HDA_PCM_TYPE_MODEM;
return 0;
}
static int si3054_init(struct hda_codec *codec)
{
struct si3054_spec *spec = codec->spec;
unsigned wait_count;
u16 val;
snd_hda_codec_write(codec, AC_NODE_ROOT, 0, AC_VERB_SET_CODEC_RESET, 0);
snd_hda_codec_write(codec, codec->mfg, 0, AC_VERB_SET_STREAM_FORMAT, 0);
SET_REG(codec, SI3054_LINE_RATE, 9600);
SET_REG(codec, SI3054_LINE_LEVEL, SI3054_DTAG_MASK|SI3054_ATAG_MASK);
SET_REG(codec, SI3054_EXTENDED_MID, 0);
wait_count = 10;
do {
msleep(2);
val = GET_REG(codec, SI3054_EXTENDED_MID);
} while ((val & SI3054_MEI_READY) != SI3054_MEI_READY && wait_count--);
if((val&SI3054_MEI_READY) != SI3054_MEI_READY) {
snd_printk(KERN_ERR "si3054: cannot initialize. EXT MID = %04x\n", val);
}
SET_REG(codec, SI3054_GPIO_POLARITY, 0xffff);
SET_REG(codec, SI3054_GPIO_CFG, 0x0);
SET_REG(codec, SI3054_MISC_AFE, 0);
SET_REG(codec, SI3054_LINE_CFG1,0x200);
if((GET_REG(codec,SI3054_LINE_STATUS) & (1<<6)) == 0) {
snd_printd("Link Frame Detect(FDT) is not ready (line status: %04x)\n",
GET_REG(codec,SI3054_LINE_STATUS));
}
spec->international = GET_REG(codec, SI3054_CHIPID) & SI3054_CHIPID_INTERNATIONAL;
return 0;
}
static void si3054_free(struct hda_codec *codec)
{
kfree(codec->spec);
}
static int patch_si3054(struct hda_codec *codec)
{
struct si3054_spec *spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
codec->patch_ops = si3054_patch_ops;
return 0;
}
static int __init patch_si3054_init(void)
{
return snd_hda_add_codec_preset(&si3054_list);
}
static void __exit patch_si3054_exit(void)
{
snd_hda_delete_codec_preset(&si3054_list);
}
