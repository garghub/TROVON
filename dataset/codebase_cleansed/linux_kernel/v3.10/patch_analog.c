static int ad198x_mux_enum_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
return snd_hda_input_mux_info(spec->input_mux, uinfo);
}
static int ad198x_mux_enum_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
ucontrol->value.enumerated.item[0] = spec->cur_mux[adc_idx];
return 0;
}
static int ad198x_mux_enum_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
unsigned int adc_idx = snd_ctl_get_ioffidx(kcontrol, &ucontrol->id);
return snd_hda_input_mux_put(codec, spec->input_mux, ucontrol,
spec->capsrc_nids[adc_idx],
&spec->cur_mux[adc_idx]);
}
static int ad198x_init(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
int i;
for (i = 0; i < spec->num_init_verbs; i++)
snd_hda_sequence_write(codec, spec->init_verbs[i]);
return 0;
}
static int create_beep_ctls(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
const struct snd_kcontrol_new *knew;
if (!spec->beep_amp)
return 0;
knew = spec->analog_beep ? ad_beep2_mixer : ad_beep_mixer;
for ( ; knew->name; knew++) {
int err;
struct snd_kcontrol *kctl;
kctl = snd_ctl_new1(knew, codec);
if (!kctl)
return -ENOMEM;
kctl->private_value = spec->beep_amp;
err = snd_hda_ctl_add(codec, 0, kctl);
if (err < 0)
return err;
}
return 0;
}
static int ad198x_build_controls(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
struct snd_kcontrol *kctl;
unsigned int i;
int err;
for (i = 0; i < spec->num_mixers; i++) {
err = snd_hda_add_new_ctls(codec, spec->mixers[i]);
if (err < 0)
return err;
}
if (spec->multiout.dig_out_nid) {
err = snd_hda_create_spdif_out_ctls(codec,
spec->multiout.dig_out_nid,
spec->multiout.dig_out_nid);
if (err < 0)
return err;
err = snd_hda_create_spdif_share_sw(codec,
&spec->multiout);
if (err < 0)
return err;
spec->multiout.share_spdif = 1;
}
if (spec->dig_in_nid) {
err = snd_hda_create_spdif_in_ctls(codec, spec->dig_in_nid);
if (err < 0)
return err;
}
err = create_beep_ctls(codec);
if (err < 0)
return err;
if (!snd_hda_find_mixer_ctl(codec, "Master Playback Volume")) {
unsigned int vmaster_tlv[4];
snd_hda_set_vmaster_tlv(codec, spec->vmaster_nid,
HDA_OUTPUT, vmaster_tlv);
err = __snd_hda_add_vmaster(codec, "Master Playback Volume",
vmaster_tlv,
(spec->slave_vols ?
spec->slave_vols : ad_slave_pfxs),
"Playback Volume",
!spec->avoid_init_slave_vol, NULL);
if (err < 0)
return err;
}
if (!snd_hda_find_mixer_ctl(codec, "Master Playback Switch")) {
err = snd_hda_add_vmaster(codec, "Master Playback Switch",
NULL,
(spec->slave_sws ?
spec->slave_sws : ad_slave_pfxs),
"Playback Switch");
if (err < 0)
return err;
}
kctl = snd_hda_find_mixer_ctl(codec, "Capture Source");
if (!kctl)
kctl = snd_hda_find_mixer_ctl(codec, "Input Source");
for (i = 0; kctl && i < kctl->count; i++) {
err = snd_hda_add_nid(codec, kctl, i, spec->capsrc_nids[i]);
if (err < 0)
return err;
}
kctl = snd_hda_find_mixer_ctl(codec,
SNDRV_CTL_NAME_IEC958("",PLAYBACK,NONE) "Source");
if (kctl) {
err = snd_hda_add_nid(codec, kctl, 0,
spec->multiout.dig_out_nid);
if (err < 0)
return err;
}
return 0;
}
static int ad198x_check_power_status(struct hda_codec *codec, hda_nid_t nid)
{
struct ad198x_spec *spec = codec->spec;
return snd_hda_check_amp_list_power(codec, &spec->loopback, nid);
}
static int ad198x_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ad198x_spec *spec = codec->spec;
return snd_hda_multi_out_analog_open(codec, &spec->multiout, substream,
hinfo);
}
static int ad198x_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ad198x_spec *spec = codec->spec;
return snd_hda_multi_out_analog_prepare(codec, &spec->multiout, stream_tag,
format, substream);
}
static int ad198x_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ad198x_spec *spec = codec->spec;
return snd_hda_multi_out_analog_cleanup(codec, &spec->multiout);
}
static int ad198x_dig_playback_pcm_open(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ad198x_spec *spec = codec->spec;
return snd_hda_multi_out_dig_open(codec, &spec->multiout);
}
static int ad198x_dig_playback_pcm_close(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ad198x_spec *spec = codec->spec;
return snd_hda_multi_out_dig_close(codec, &spec->multiout);
}
static int ad198x_dig_playback_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ad198x_spec *spec = codec->spec;
return snd_hda_multi_out_dig_prepare(codec, &spec->multiout, stream_tag,
format, substream);
}
static int ad198x_dig_playback_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ad198x_spec *spec = codec->spec;
return snd_hda_multi_out_dig_cleanup(codec, &spec->multiout);
}
static int ad198x_capture_pcm_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
struct ad198x_spec *spec = codec->spec;
snd_hda_codec_setup_stream(codec, spec->adc_nids[substream->number],
stream_tag, 0, format);
return 0;
}
static int ad198x_capture_pcm_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
struct ad198x_spec *spec = codec->spec;
snd_hda_codec_cleanup_stream(codec, spec->adc_nids[substream->number]);
return 0;
}
static int ad198x_build_pcms(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
struct hda_pcm *info = spec->pcm_rec;
codec->num_pcms = 1;
codec->pcm_info = info;
info->name = "AD198x Analog";
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = ad198x_pcm_analog_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].channels_max = spec->multiout.max_channels;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->multiout.dac_nids[0];
info->stream[SNDRV_PCM_STREAM_CAPTURE] = ad198x_pcm_analog_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].substreams = spec->num_adc_nids;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->adc_nids[0];
if (spec->multiout.dig_out_nid) {
info++;
codec->num_pcms++;
codec->spdif_status_reset = 1;
info->name = "AD198x Digital";
info->pcm_type = HDA_PCM_TYPE_SPDIF;
info->stream[SNDRV_PCM_STREAM_PLAYBACK] = ad198x_pcm_digital_playback;
info->stream[SNDRV_PCM_STREAM_PLAYBACK].nid = spec->multiout.dig_out_nid;
if (spec->dig_in_nid) {
info->stream[SNDRV_PCM_STREAM_CAPTURE] = ad198x_pcm_digital_capture;
info->stream[SNDRV_PCM_STREAM_CAPTURE].nid = spec->dig_in_nid;
}
}
return 0;
}
static void ad198x_power_eapd_write(struct hda_codec *codec, hda_nid_t front,
hda_nid_t hp)
{
if (snd_hda_query_pin_caps(codec, front) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, front, 0, AC_VERB_SET_EAPD_BTLENABLE,
!codec->inv_eapd ? 0x00 : 0x02);
if (snd_hda_query_pin_caps(codec, hp) & AC_PINCAP_EAPD)
snd_hda_codec_write(codec, hp, 0, AC_VERB_SET_EAPD_BTLENABLE,
!codec->inv_eapd ? 0x00 : 0x02);
}
static void ad198x_power_eapd(struct hda_codec *codec)
{
switch (codec->vendor_id) {
case 0x11d41882:
case 0x11d4882a:
case 0x11d41884:
case 0x11d41984:
case 0x11d41883:
case 0x11d4184a:
case 0x11d4194a:
case 0x11d4194b:
case 0x11d41988:
case 0x11d4198b:
case 0x11d4989a:
case 0x11d4989b:
ad198x_power_eapd_write(codec, 0x12, 0x11);
break;
case 0x11d41981:
case 0x11d41983:
ad198x_power_eapd_write(codec, 0x05, 0x06);
break;
case 0x11d41986:
ad198x_power_eapd_write(codec, 0x1b, 0x1a);
break;
}
}
static void ad198x_shutup(struct hda_codec *codec)
{
snd_hda_shutup_pins(codec);
ad198x_power_eapd(codec);
}
static void ad198x_free(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
if (!spec)
return;
snd_hda_gen_spec_free(&spec->gen);
kfree(spec);
snd_hda_detach_beep_device(codec);
}
static int ad198x_suspend(struct hda_codec *codec)
{
ad198x_shutup(codec);
return 0;
}
static int ad198x_eapd_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
if (codec->inv_eapd)
ucontrol->value.integer.value[0] = ! spec->cur_eapd;
else
ucontrol->value.integer.value[0] = spec->cur_eapd;
return 0;
}
static int ad198x_eapd_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
hda_nid_t nid = kcontrol->private_value & 0xff;
unsigned int eapd;
eapd = !!ucontrol->value.integer.value[0];
if (codec->inv_eapd)
eapd = !eapd;
if (eapd == spec->cur_eapd)
return 0;
spec->cur_eapd = eapd;
snd_hda_codec_write_cache(codec, nid,
0, AC_VERB_SET_EAPD_BTLENABLE,
eapd ? 0x02 : 0x00);
return 1;
}
static int ad198x_auto_build_controls(struct hda_codec *codec)
{
int err;
err = snd_hda_gen_build_controls(codec);
if (err < 0)
return err;
err = create_beep_ctls(codec);
if (err < 0)
return err;
return 0;
}
static int ad198x_parse_auto_config(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
struct auto_pin_cfg *cfg = &spec->gen.autocfg;
int err;
codec->spdif_status_reset = 1;
codec->no_trigger_sense = 1;
codec->no_sticky_stream = 1;
spec->gen.indep_hp = 1;
err = snd_hda_parse_pin_defcfg(codec, cfg, NULL, 0);
if (err < 0)
return err;
err = snd_hda_gen_parse_auto_config(codec, cfg);
if (err < 0)
return err;
codec->patch_ops = ad198x_auto_patch_ops;
return 0;
}
static void ad1986a_automic(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x1f);
snd_hda_codec_write(codec, 0x0f, 0, AC_VERB_SET_CONNECT_SEL,
present ? 0 : 2);
}
static void ad1986a_automic_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) != AD1986A_MIC_EVENT)
return;
ad1986a_automic(codec);
}
static int ad1986a_automic_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1986a_automic(codec);
return 0;
}
static void ad1986a_update_hp(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
unsigned int mute;
if (spec->jack_present)
mute = HDA_AMP_MUTE;
else
mute = snd_hda_codec_amp_read(codec, 0x1a, 0, HDA_OUTPUT, 0);
snd_hda_codec_amp_stereo(codec, 0x1b, HDA_OUTPUT, 0,
HDA_AMP_MUTE, mute);
}
static void ad1986a_hp_automute(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
spec->jack_present = snd_hda_jack_detect(codec, 0x1a);
if (spec->inv_jack_detect)
spec->jack_present = !spec->jack_present;
ad1986a_update_hp(codec);
}
static void ad1986a_hp_unsol_event(struct hda_codec *codec, unsigned int res)
{
if ((res >> 26) != AD1986A_HP_EVENT)
return;
ad1986a_hp_automute(codec);
}
static int ad1986a_hp_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1986a_hp_automute(codec);
return 0;
}
static int ad1986a_hp_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
int change = snd_hda_mixer_amp_switch_put(kcontrol, ucontrol);
if (change)
ad1986a_update_hp(codec);
return change;
}
static void ad1986a_samsung_p50_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case AD1986A_HP_EVENT:
ad1986a_hp_automute(codec);
break;
case AD1986A_MIC_EVENT:
ad1986a_automic(codec);
break;
}
}
static int ad1986a_samsung_p50_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1986a_hp_automute(codec);
ad1986a_automic(codec);
return 0;
}
static int is_jack_available(struct hda_codec *codec, hda_nid_t nid)
{
unsigned int conf = snd_hda_codec_get_pincfg(codec, nid);
return get_defcfg_connect(conf) != AC_JACK_PORT_NONE;
}
static int alloc_ad_spec(struct hda_codec *codec)
{
struct ad198x_spec *spec;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
snd_hda_gen_spec_init(&spec->gen);
return 0;
}
static void ad_fixup_inv_jack_detect(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE)
codec->inv_jack_detect = 1;
}
static int ad1986a_parse_auto_config(struct hda_codec *codec)
{
int err;
struct ad198x_spec *spec;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
codec->inv_eapd = 1;
spec->gen.mixer_nid = 0x07;
spec->gen.beep_nid = 0x19;
set_beep_amp(spec, 0x18, 0, HDA_OUTPUT);
spec->gen.multiout.no_share_stream = 1;
snd_hda_pick_fixup(codec, NULL, ad1986a_fixup_tbl, ad1986a_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = ad198x_parse_auto_config(codec);
if (err < 0) {
snd_hda_gen_free(codec);
return err;
}
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
}
static int patch_ad1986a(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err, board_config;
board_config = snd_hda_check_board_config(codec, AD1986A_MODELS,
ad1986a_models,
ad1986a_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = AD1986A_AUTO;
}
if (board_config == AD1986A_AUTO)
return ad1986a_parse_auto_config(codec);
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
err = snd_hda_attach_beep_device(codec, 0x19);
if (err < 0) {
ad198x_free(codec);
return err;
}
set_beep_amp(spec, 0x18, 0, HDA_OUTPUT);
spec->multiout.max_channels = 6;
spec->multiout.num_dacs = ARRAY_SIZE(ad1986a_dac_nids);
spec->multiout.dac_nids = ad1986a_dac_nids;
spec->multiout.dig_out_nid = AD1986A_SPDIF_OUT;
spec->num_adc_nids = 1;
spec->adc_nids = ad1986a_adc_nids;
spec->capsrc_nids = ad1986a_capsrc_nids;
spec->input_mux = &ad1986a_capture_source;
spec->num_mixers = 1;
spec->mixers[0] = ad1986a_mixers;
spec->num_init_verbs = 1;
spec->init_verbs[0] = ad1986a_init_verbs;
#ifdef CONFIG_PM
spec->loopback.amplist = ad1986a_loopbacks;
#endif
spec->vmaster_nid = 0x1b;
codec->inv_eapd = 1;
codec->patch_ops = ad198x_patch_ops;
switch (board_config) {
case AD1986A_3STACK:
spec->num_mixers = 2;
spec->mixers[1] = ad1986a_3st_mixers;
spec->num_init_verbs = 2;
spec->init_verbs[1] = ad1986a_ch2_init;
spec->channel_mode = ad1986a_modes;
spec->num_channel_mode = ARRAY_SIZE(ad1986a_modes);
spec->need_dac_fix = 1;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
break;
case AD1986A_LAPTOP:
spec->mixers[0] = ad1986a_laptop_mixers;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = ad1986a_laptop_dac_nids;
break;
case AD1986A_LAPTOP_EAPD:
spec->num_mixers = 3;
spec->mixers[0] = ad1986a_laptop_master_mixers;
spec->mixers[1] = ad1986a_laptop_eapd_mixers;
spec->mixers[2] = ad1986a_laptop_intmic_mixers;
spec->num_init_verbs = 2;
spec->init_verbs[1] = ad1986a_eapd_init_verbs;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = ad1986a_laptop_dac_nids;
if (!is_jack_available(codec, 0x25))
spec->multiout.dig_out_nid = 0;
spec->input_mux = &ad1986a_laptop_eapd_capture_source;
break;
case AD1986A_SAMSUNG:
spec->num_mixers = 2;
spec->mixers[0] = ad1986a_laptop_master_mixers;
spec->mixers[1] = ad1986a_laptop_eapd_mixers;
spec->num_init_verbs = 3;
spec->init_verbs[1] = ad1986a_eapd_init_verbs;
spec->init_verbs[2] = ad1986a_automic_verbs;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = ad1986a_laptop_dac_nids;
if (!is_jack_available(codec, 0x25))
spec->multiout.dig_out_nid = 0;
spec->input_mux = &ad1986a_automic_capture_source;
codec->patch_ops.unsol_event = ad1986a_automic_unsol_event;
codec->patch_ops.init = ad1986a_automic_init;
break;
case AD1986A_SAMSUNG_P50:
spec->num_mixers = 2;
spec->mixers[0] = ad1986a_automute_master_mixers;
spec->mixers[1] = ad1986a_laptop_eapd_mixers;
spec->num_init_verbs = 4;
spec->init_verbs[1] = ad1986a_eapd_init_verbs;
spec->init_verbs[2] = ad1986a_automic_verbs;
spec->init_verbs[3] = ad1986a_hp_init_verbs;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = ad1986a_laptop_dac_nids;
if (!is_jack_available(codec, 0x25))
spec->multiout.dig_out_nid = 0;
spec->input_mux = &ad1986a_automic_capture_source;
codec->patch_ops.unsol_event = ad1986a_samsung_p50_unsol_event;
codec->patch_ops.init = ad1986a_samsung_p50_init;
break;
case AD1986A_LAPTOP_AUTOMUTE:
spec->num_mixers = 3;
spec->mixers[0] = ad1986a_automute_master_mixers;
spec->mixers[1] = ad1986a_laptop_eapd_mixers;
spec->mixers[2] = ad1986a_laptop_intmic_mixers;
spec->num_init_verbs = 3;
spec->init_verbs[1] = ad1986a_eapd_init_verbs;
spec->init_verbs[2] = ad1986a_hp_init_verbs;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = ad1986a_laptop_dac_nids;
if (!is_jack_available(codec, 0x25))
spec->multiout.dig_out_nid = 0;
spec->input_mux = &ad1986a_laptop_eapd_capture_source;
codec->patch_ops.unsol_event = ad1986a_hp_unsol_event;
codec->patch_ops.init = ad1986a_hp_init;
spec->inv_jack_detect = 1;
break;
case AD1986A_ULTRA:
spec->mixers[0] = ad1986a_laptop_eapd_mixers;
spec->num_init_verbs = 2;
spec->init_verbs[1] = ad1986a_ultra_init;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = ad1986a_laptop_dac_nids;
spec->multiout.dig_out_nid = 0;
break;
}
spec->multiout.no_share_stream = 1;
codec->no_trigger_sense = 1;
codec->no_sticky_stream = 1;
return 0;
}
static int ad1983_spdif_route_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = { "PCM", "ADC" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item > 1)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int ad1983_spdif_route_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->spdif_route;
return 0;
}
static int ad1983_spdif_route_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
if (ucontrol->value.enumerated.item[0] > 1)
return -EINVAL;
if (spec->spdif_route != ucontrol->value.enumerated.item[0]) {
spec->spdif_route = ucontrol->value.enumerated.item[0];
snd_hda_codec_write_cache(codec, spec->multiout.dig_out_nid, 0,
AC_VERB_SET_CONNECT_SEL,
spec->spdif_route);
return 1;
}
return 0;
}
static int ad1983_auto_smux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
static const char * const texts2[] = { "PCM", "ADC" };
static const char * const texts3[] = { "PCM", "ADC1", "ADC2" };
hda_nid_t dig_out = spec->gen.multiout.dig_out_nid;
int num_conns = snd_hda_get_num_conns(codec, dig_out);
if (num_conns == 2)
return snd_hda_enum_helper_info(kcontrol, uinfo, 2, texts2);
else if (num_conns == 3)
return snd_hda_enum_helper_info(kcontrol, uinfo, 3, texts3);
else
return -EINVAL;
}
static int ad1983_auto_smux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->cur_smux;
return 0;
}
static int ad1983_auto_smux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
unsigned int val = ucontrol->value.enumerated.item[0];
hda_nid_t dig_out = spec->gen.multiout.dig_out_nid;
int num_conns = snd_hda_get_num_conns(codec, dig_out);
if (val >= num_conns)
return -EINVAL;
if (spec->cur_smux == val)
return 0;
spec->cur_smux = val;
snd_hda_codec_write_cache(codec, dig_out, 0,
AC_VERB_SET_CONNECT_SEL, val);
return 1;
}
static int ad1983_add_spdif_mux_ctl(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
hda_nid_t dig_out = spec->gen.multiout.dig_out_nid;
int num_conns;
if (!dig_out)
return 0;
num_conns = snd_hda_get_num_conns(codec, dig_out);
if (num_conns != 2 && num_conns != 3)
return 0;
if (!snd_hda_gen_add_kctl(&spec->gen, NULL, &ad1983_auto_smux_mixer))
return -ENOMEM;
return 0;
}
static int ad1983_parse_auto_config(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
err = ad198x_parse_auto_config(codec);
if (err < 0)
goto error;
err = ad1983_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int patch_ad1983(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int board_config;
int err;
board_config = snd_hda_check_board_config(codec, AD1983_MODELS,
ad1983_models, NULL);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = AD1983_AUTO;
}
if (board_config == AD1983_AUTO)
return ad1983_parse_auto_config(codec);
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
err = snd_hda_attach_beep_device(codec, 0x10);
if (err < 0) {
ad198x_free(codec);
return err;
}
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = ARRAY_SIZE(ad1983_dac_nids);
spec->multiout.dac_nids = ad1983_dac_nids;
spec->multiout.dig_out_nid = AD1983_SPDIF_OUT;
spec->num_adc_nids = 1;
spec->adc_nids = ad1983_adc_nids;
spec->capsrc_nids = ad1983_capsrc_nids;
spec->input_mux = &ad1983_capture_source;
spec->num_mixers = 1;
spec->mixers[0] = ad1983_mixers;
spec->num_init_verbs = 1;
spec->init_verbs[0] = ad1983_init_verbs;
spec->spdif_route = 0;
#ifdef CONFIG_PM
spec->loopback.amplist = ad1983_loopbacks;
#endif
spec->vmaster_nid = 0x05;
codec->patch_ops = ad198x_patch_ops;
codec->no_trigger_sense = 1;
codec->no_sticky_stream = 1;
return 0;
}
static int ad1981_hp_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
if (! ad198x_eapd_put(kcontrol, ucontrol))
return 0;
snd_hda_set_pin_ctl(codec, 0x05, spec->cur_eapd ? PIN_OUT : 0);
snd_hda_codec_amp_stereo(codec, 0x06, HDA_OUTPUT, 0,
HDA_AMP_MUTE,
spec->cur_eapd ? 0 : HDA_AMP_MUTE);
return 1;
}
static void ad1981_hp_automute(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x06);
snd_hda_codec_amp_stereo(codec, 0x05, HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
}
static void ad1981_hp_automic(struct hda_codec *codec)
{
static const struct hda_verb mic_jack_on[] = {
{0x1f, AC_VERB_SET_AMP_GAIN_MUTE, 0xb080},
{0x1e, AC_VERB_SET_AMP_GAIN_MUTE, 0xb000},
{}
};
static const struct hda_verb mic_jack_off[] = {
{0x1e, AC_VERB_SET_AMP_GAIN_MUTE, 0xb080},
{0x1f, AC_VERB_SET_AMP_GAIN_MUTE, 0xb000},
{}
};
unsigned int present;
present = snd_hda_jack_detect(codec, 0x08);
if (present)
snd_hda_sequence_write(codec, mic_jack_on);
else
snd_hda_sequence_write(codec, mic_jack_off);
}
static void ad1981_hp_unsol_event(struct hda_codec *codec,
unsigned int res)
{
res >>= 26;
switch (res) {
case AD1981_HP_EVENT:
ad1981_hp_automute(codec);
break;
case AD1981_MIC_EVENT:
ad1981_hp_automic(codec);
break;
}
}
static int ad1981_hp_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1981_hp_automute(codec);
ad1981_hp_automic(codec);
return 0;
}
static void ad_vmaster_eapd_hook(void *private_data, int enabled)
{
struct hda_codec *codec = private_data;
struct ad198x_spec *spec = codec->spec;
snd_hda_codec_update_cache(codec, spec->eapd_nid, 0,
AC_VERB_SET_EAPD_BTLENABLE,
enabled ? 0x02 : 0x00);
}
static void ad1981_fixup_hp_eapd(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct ad198x_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
spec->gen.vmaster_mute.hook = ad_vmaster_eapd_hook;
spec->eapd_nid = 0x05;
}
}
static void ad1981_fixup_amp_override(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE)
snd_hda_override_amp_caps(codec, 0x11, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
}
static int ad1981_parse_auto_config(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return -ENOMEM;
spec = codec->spec;
spec->gen.mixer_nid = 0x0e;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x0d, 0, HDA_OUTPUT);
snd_hda_pick_fixup(codec, NULL, ad1981_fixup_tbl, ad1981_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = ad198x_parse_auto_config(codec);
if (err < 0)
goto error;
err = ad1983_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int patch_ad1981(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err, board_config;
board_config = snd_hda_check_board_config(codec, AD1981_MODELS,
ad1981_models,
ad1981_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = AD1981_AUTO;
}
if (board_config == AD1981_AUTO)
return ad1981_parse_auto_config(codec);
err = alloc_ad_spec(codec);
if (err < 0)
return -ENOMEM;
spec = codec->spec;
err = snd_hda_attach_beep_device(codec, 0x10);
if (err < 0) {
ad198x_free(codec);
return err;
}
set_beep_amp(spec, 0x0d, 0, HDA_OUTPUT);
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = ARRAY_SIZE(ad1981_dac_nids);
spec->multiout.dac_nids = ad1981_dac_nids;
spec->multiout.dig_out_nid = AD1981_SPDIF_OUT;
spec->num_adc_nids = 1;
spec->adc_nids = ad1981_adc_nids;
spec->capsrc_nids = ad1981_capsrc_nids;
spec->input_mux = &ad1981_capture_source;
spec->num_mixers = 1;
spec->mixers[0] = ad1981_mixers;
spec->num_init_verbs = 1;
spec->init_verbs[0] = ad1981_init_verbs;
spec->spdif_route = 0;
#ifdef CONFIG_PM
spec->loopback.amplist = ad1981_loopbacks;
#endif
spec->vmaster_nid = 0x05;
codec->patch_ops = ad198x_patch_ops;
switch (board_config) {
case AD1981_HP:
spec->mixers[0] = ad1981_hp_mixers;
spec->num_init_verbs = 2;
spec->init_verbs[1] = ad1981_hp_init_verbs;
if (!is_jack_available(codec, 0x0a))
spec->multiout.dig_out_nid = 0;
spec->input_mux = &ad1981_hp_capture_source;
codec->patch_ops.init = ad1981_hp_init;
codec->patch_ops.unsol_event = ad1981_hp_unsol_event;
snd_hda_override_amp_caps(codec, 0x11, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
break;
case AD1981_THINKPAD:
spec->mixers[0] = ad1981_thinkpad_mixers;
spec->input_mux = &ad1981_thinkpad_capture_source;
snd_hda_override_amp_caps(codec, 0x11, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
break;
case AD1981_TOSHIBA:
spec->mixers[0] = ad1981_hp_mixers;
spec->mixers[1] = ad1981_toshiba_mixers;
spec->num_init_verbs = 2;
spec->init_verbs[1] = ad1981_toshiba_init_verbs;
spec->multiout.dig_out_nid = 0;
spec->input_mux = &ad1981_hp_capture_source;
codec->patch_ops.init = ad1981_hp_init;
codec->patch_ops.unsol_event = ad1981_hp_unsol_event;
break;
}
codec->no_trigger_sense = 1;
codec->no_sticky_stream = 1;
return 0;
}
static int ad198x_ch_mode_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
return snd_hda_ch_mode_info(codec, uinfo, spec->channel_mode,
spec->num_channel_mode);
}
static int ad198x_ch_mode_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
return snd_hda_ch_mode_get(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode, spec->multiout.max_channels);
}
static int ad198x_ch_mode_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
int err = snd_hda_ch_mode_put(codec, ucontrol, spec->channel_mode,
spec->num_channel_mode,
&spec->multiout.max_channels);
if (err >= 0 && spec->need_dac_fix)
spec->multiout.num_dacs = spec->multiout.max_channels / 2;
return err;
}
static int ad1988_spdif_playback_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char * const texts[] = {
"PCM", "ADC1", "ADC2", "ADC3"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 4;
if (uinfo->value.enumerated.item >= 4)
uinfo->value.enumerated.item = 3;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int ad1988_spdif_playback_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int sel;
sel = snd_hda_codec_read(codec, 0x1d, 0, AC_VERB_GET_AMP_GAIN_MUTE,
AC_AMP_GET_INPUT);
if (!(sel & 0x80))
ucontrol->value.enumerated.item[0] = 0;
else {
sel = snd_hda_codec_read(codec, 0x0b, 0,
AC_VERB_GET_CONNECT_SEL, 0);
if (sel < 3)
sel++;
else
sel = 0;
ucontrol->value.enumerated.item[0] = sel;
}
return 0;
}
static int ad1988_spdif_playback_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
unsigned int val, sel;
int change;
val = ucontrol->value.enumerated.item[0];
if (val > 3)
return -EINVAL;
if (!val) {
sel = snd_hda_codec_read(codec, 0x1d, 0,
AC_VERB_GET_AMP_GAIN_MUTE,
AC_AMP_GET_INPUT);
change = sel & 0x80;
if (change) {
snd_hda_codec_write_cache(codec, 0x1d, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(0));
snd_hda_codec_write_cache(codec, 0x1d, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_MUTE(1));
}
} else {
sel = snd_hda_codec_read(codec, 0x1d, 0,
AC_VERB_GET_AMP_GAIN_MUTE,
AC_AMP_GET_INPUT | 0x01);
change = sel & 0x80;
if (change) {
snd_hda_codec_write_cache(codec, 0x1d, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_MUTE(0));
snd_hda_codec_write_cache(codec, 0x1d, 0,
AC_VERB_SET_AMP_GAIN_MUTE,
AMP_IN_UNMUTE(1));
}
sel = snd_hda_codec_read(codec, 0x0b, 0,
AC_VERB_GET_CONNECT_SEL, 0) + 1;
change |= sel != val;
if (change)
snd_hda_codec_write_cache(codec, 0x0b, 0,
AC_VERB_SET_CONNECT_SEL,
val - 1);
}
return change;
}
static void ad1988_laptop_unsol_event(struct hda_codec *codec, unsigned int res)
{
if ((res >> 26) != AD1988_HP_EVENT)
return;
if (snd_hda_jack_detect(codec, 0x11))
snd_hda_sequence_write(codec, ad1988_laptop_hp_on);
else
snd_hda_sequence_write(codec, ad1988_laptop_hp_off);
}
static int ad1988_auto_smux_enum_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
static const char * const texts[] = {
"PCM", "ADC1", "ADC2", "ADC3",
};
int num_conns = snd_hda_get_num_conns(codec, 0x0b) + 1;
if (num_conns > 4)
num_conns = 4;
return snd_hda_enum_helper_info(kcontrol, uinfo, num_conns, texts);
}
static int ad1988_auto_smux_enum_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
ucontrol->value.enumerated.item[0] = spec->cur_smux;
return 0;
}
static int ad1988_auto_smux_enum_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
struct ad198x_spec *spec = codec->spec;
unsigned int val = ucontrol->value.enumerated.item[0];
struct nid_path *path;
int num_conns = snd_hda_get_num_conns(codec, 0x0b) + 1;
if (val >= num_conns)
return -EINVAL;
if (spec->cur_smux == val)
return 0;
mutex_lock(&codec->control_mutex);
codec->cached_write = 1;
path = snd_hda_get_path_from_idx(codec,
spec->smux_paths[spec->cur_smux]);
if (path)
snd_hda_activate_path(codec, path, false, true);
path = snd_hda_get_path_from_idx(codec, spec->smux_paths[val]);
if (path)
snd_hda_activate_path(codec, path, true, true);
spec->cur_smux = val;
codec->cached_write = 0;
mutex_unlock(&codec->control_mutex);
snd_hda_codec_flush_cache(codec);
return 1;
}
static int ad1988_auto_init(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
int i, err;
err = snd_hda_gen_init(codec);
if (err < 0)
return err;
if (!spec->gen.autocfg.dig_outs)
return 0;
for (i = 0; i < 4; i++) {
struct nid_path *path;
path = snd_hda_get_path_from_idx(codec, spec->smux_paths[i]);
if (path)
snd_hda_activate_path(codec, path, path->active, false);
}
return 0;
}
static int ad1988_add_spdif_mux_ctl(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
int i, num_conns;
static struct nid_path fake_paths[4] = {
{
.depth = 3,
.path = { 0x02, 0x1d, 0x1b },
.idx = { 0, 0, 0 },
.multi = { 0, 0, 0 },
},
{
.depth = 4,
.path = { 0x08, 0x0b, 0x1d, 0x1b },
.idx = { 0, 0, 1, 0 },
.multi = { 0, 1, 0, 0 },
},
{
.depth = 4,
.path = { 0x09, 0x0b, 0x1d, 0x1b },
.idx = { 0, 1, 1, 0 },
.multi = { 0, 1, 0, 0 },
},
{
.depth = 4,
.path = { 0x0f, 0x0b, 0x1d, 0x1b },
.idx = { 0, 2, 1, 0 },
.multi = { 0, 1, 0, 0 },
},
};
if (!spec->gen.autocfg.dig_outs ||
get_wcaps_type(get_wcaps(codec, 0x1d)) != AC_WID_AUD_MIX)
return 0;
num_conns = snd_hda_get_num_conns(codec, 0x0b) + 1;
if (num_conns != 3 && num_conns != 4)
return 0;
for (i = 0; i < num_conns; i++) {
struct nid_path *path = snd_array_new(&spec->gen.paths);
if (!path)
return -ENOMEM;
*path = fake_paths[i];
if (!i)
path->active = 1;
spec->smux_paths[i] = snd_hda_get_path_idx(codec, path);
}
if (!snd_hda_gen_add_kctl(&spec->gen, NULL, &ad1988_auto_smux_mixer))
return -ENOMEM;
codec->patch_ops.init = ad1988_auto_init;
return 0;
}
static int ad1988_parse_auto_config(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.mixer_nid = 0x20;
spec->gen.mixer_merge_nid = 0x21;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
err = ad198x_parse_auto_config(codec);
if (err < 0)
goto error;
err = ad1988_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int patch_ad1988(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err, board_config;
board_config = snd_hda_check_board_config(codec, AD1988_MODEL_LAST,
ad1988_models, ad1988_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = AD1988_AUTO;
}
if (board_config == AD1988_AUTO)
return ad1988_parse_auto_config(codec);
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
if (is_rev2(codec))
snd_printk(KERN_INFO "patch_analog: AD1988A rev.2 is detected, enable workarounds\n");
err = snd_hda_attach_beep_device(codec, 0x10);
if (err < 0) {
ad198x_free(codec);
return err;
}
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
if (!spec->multiout.hp_nid)
spec->multiout.hp_nid = ad1988_alt_dac_nid[0];
switch (board_config) {
case AD1988_6STACK:
case AD1988_6STACK_DIG:
spec->multiout.max_channels = 8;
spec->multiout.num_dacs = 4;
if (is_rev2(codec))
spec->multiout.dac_nids = ad1988_6stack_dac_nids_rev2;
else
spec->multiout.dac_nids = ad1988_6stack_dac_nids;
spec->input_mux = &ad1988_6stack_capture_source;
spec->num_mixers = 2;
if (is_rev2(codec))
spec->mixers[0] = ad1988_6stack_mixers1_rev2;
else
spec->mixers[0] = ad1988_6stack_mixers1;
spec->mixers[1] = ad1988_6stack_mixers2;
spec->num_init_verbs = 1;
spec->init_verbs[0] = ad1988_6stack_init_verbs;
if (board_config == AD1988_6STACK_DIG) {
spec->multiout.dig_out_nid = AD1988_SPDIF_OUT;
spec->dig_in_nid = AD1988_SPDIF_IN;
}
break;
case AD1988_3STACK:
case AD1988_3STACK_DIG:
spec->multiout.max_channels = 6;
spec->multiout.num_dacs = 3;
if (is_rev2(codec))
spec->multiout.dac_nids = ad1988_3stack_dac_nids_rev2;
else
spec->multiout.dac_nids = ad1988_3stack_dac_nids;
spec->input_mux = &ad1988_6stack_capture_source;
spec->channel_mode = ad1988_3stack_modes;
spec->num_channel_mode = ARRAY_SIZE(ad1988_3stack_modes);
spec->num_mixers = 2;
if (is_rev2(codec))
spec->mixers[0] = ad1988_3stack_mixers1_rev2;
else
spec->mixers[0] = ad1988_3stack_mixers1;
spec->mixers[1] = ad1988_3stack_mixers2;
spec->num_init_verbs = 1;
spec->init_verbs[0] = ad1988_3stack_init_verbs;
if (board_config == AD1988_3STACK_DIG)
spec->multiout.dig_out_nid = AD1988_SPDIF_OUT;
break;
case AD1988_LAPTOP:
case AD1988_LAPTOP_DIG:
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
spec->multiout.dac_nids = ad1988_3stack_dac_nids;
spec->input_mux = &ad1988_laptop_capture_source;
spec->num_mixers = 1;
spec->mixers[0] = ad1988_laptop_mixers;
codec->inv_eapd = 1;
spec->num_init_verbs = 1;
spec->init_verbs[0] = ad1988_laptop_init_verbs;
if (board_config == AD1988_LAPTOP_DIG)
spec->multiout.dig_out_nid = AD1988_SPDIF_OUT;
break;
}
spec->num_adc_nids = ARRAY_SIZE(ad1988_adc_nids);
spec->adc_nids = ad1988_adc_nids;
spec->capsrc_nids = ad1988_capsrc_nids;
spec->mixers[spec->num_mixers++] = ad1988_capture_mixers;
spec->init_verbs[spec->num_init_verbs++] = ad1988_capture_init_verbs;
if (spec->multiout.dig_out_nid) {
if (codec->vendor_id >= 0x11d4989a) {
spec->mixers[spec->num_mixers++] =
ad1989_spdif_out_mixers;
spec->init_verbs[spec->num_init_verbs++] =
ad1989_spdif_init_verbs;
codec->slave_dig_outs = ad1989b_slave_dig_outs;
} else {
spec->mixers[spec->num_mixers++] =
ad1988_spdif_out_mixers;
spec->init_verbs[spec->num_init_verbs++] =
ad1988_spdif_init_verbs;
}
}
if (spec->dig_in_nid && codec->vendor_id < 0x11d4989a) {
spec->mixers[spec->num_mixers++] = ad1988_spdif_in_mixers;
spec->init_verbs[spec->num_init_verbs++] =
ad1988_spdif_in_init_verbs;
}
codec->patch_ops = ad198x_patch_ops;
switch (board_config) {
case AD1988_LAPTOP:
case AD1988_LAPTOP_DIG:
codec->patch_ops.unsol_event = ad1988_laptop_unsol_event;
break;
}
#ifdef CONFIG_PM
spec->loopback.amplist = ad1988_loopbacks;
#endif
spec->vmaster_nid = 0x04;
codec->no_trigger_sense = 1;
codec->no_sticky_stream = 1;
return 0;
}
static void ad1884_fixup_amp_override(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
if (action == HDA_FIXUP_ACT_PRE_PROBE)
snd_hda_override_amp_caps(codec, 0x20, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
}
static void ad1884_fixup_hp_eapd(struct hda_codec *codec,
const struct hda_fixup *fix, int action)
{
struct ad198x_spec *spec = codec->spec;
if (action == HDA_FIXUP_ACT_PRE_PROBE) {
if (spec->gen.autocfg.line_out_type == AUTO_PIN_SPEAKER_OUT)
spec->eapd_nid = spec->gen.autocfg.line_out_pins[0];
else
spec->eapd_nid = spec->gen.autocfg.speaker_pins[0];
if (spec->eapd_nid)
spec->gen.vmaster_mute.hook = ad_vmaster_eapd_hook;
}
}
static int ad1884_parse_auto_config(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.mixer_nid = 0x20;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
snd_hda_pick_fixup(codec, NULL, ad1884_fixup_tbl, ad1884_fixups);
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);
err = ad198x_parse_auto_config(codec);
if (err < 0)
goto error;
err = ad1983_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int patch_ad1884_basic(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
err = snd_hda_attach_beep_device(codec, 0x10);
if (err < 0) {
ad198x_free(codec);
return err;
}
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = ARRAY_SIZE(ad1884_dac_nids);
spec->multiout.dac_nids = ad1884_dac_nids;
spec->multiout.dig_out_nid = AD1884_SPDIF_OUT;
spec->num_adc_nids = ARRAY_SIZE(ad1884_adc_nids);
spec->adc_nids = ad1884_adc_nids;
spec->capsrc_nids = ad1884_capsrc_nids;
spec->input_mux = &ad1884_capture_source;
spec->num_mixers = 1;
spec->mixers[0] = ad1884_base_mixers;
spec->num_init_verbs = 1;
spec->init_verbs[0] = ad1884_init_verbs;
spec->spdif_route = 0;
#ifdef CONFIG_PM
spec->loopback.amplist = ad1884_loopbacks;
#endif
spec->vmaster_nid = 0x04;
spec->slave_vols = ad1884_slave_vols;
spec->avoid_init_slave_vol = 1;
codec->patch_ops = ad198x_patch_ops;
codec->no_trigger_sense = 1;
codec->no_sticky_stream = 1;
return 0;
}
static int patch_ad1884(struct hda_codec *codec)
{
int board_config;
board_config = snd_hda_check_board_config(codec, AD1884_MODELS,
ad1884_models, NULL);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = AD1884_AUTO;
}
if (board_config == AD1884_AUTO)
return ad1884_parse_auto_config(codec);
else
return patch_ad1884_basic(codec);
}
static int ad1984_pcm_dmic_prepare(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
unsigned int stream_tag,
unsigned int format,
struct snd_pcm_substream *substream)
{
snd_hda_codec_setup_stream(codec, 0x05 + substream->number,
stream_tag, 0, format);
return 0;
}
static int ad1984_pcm_dmic_cleanup(struct hda_pcm_stream *hinfo,
struct hda_codec *codec,
struct snd_pcm_substream *substream)
{
snd_hda_codec_cleanup_stream(codec, 0x05 + substream->number);
return 0;
}
static int ad1984_build_pcms(struct hda_codec *codec)
{
struct ad198x_spec *spec = codec->spec;
struct hda_pcm *info;
int err;
err = ad198x_build_pcms(codec);
if (err < 0)
return err;
info = spec->pcm_rec + codec->num_pcms;
codec->num_pcms++;
info->name = "AD1984 Digital Mic";
info->stream[SNDRV_PCM_STREAM_CAPTURE] = ad1984_pcm_dmic_capture;
return 0;
}
static int patch_ad1984(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int board_config, err;
board_config = snd_hda_check_board_config(codec, AD1984_MODELS,
ad1984_models, ad1984_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = AD1984_AUTO;
}
if (board_config == AD1984_AUTO)
return ad1884_parse_auto_config(codec);
err = patch_ad1884_basic(codec);
if (err < 0)
return err;
spec = codec->spec;
switch (board_config) {
case AD1984_BASIC:
spec->mixers[spec->num_mixers++] = ad1984_dmic_mixers;
codec->patch_ops.build_pcms = ad1984_build_pcms;
break;
case AD1984_THINKPAD:
if (codec->subsystem_id == 0x17aa20fb) {
spec->multiout.dig_out_nid = 0;
} else
spec->multiout.dig_out_nid = AD1884_SPDIF_OUT;
spec->input_mux = &ad1984_thinkpad_capture_source;
spec->mixers[0] = ad1984_thinkpad_mixers;
spec->init_verbs[spec->num_init_verbs++] = ad1984_thinkpad_init_verbs;
spec->analog_beep = 1;
break;
case AD1984_DELL_DESKTOP:
spec->multiout.dig_out_nid = 0;
spec->input_mux = &ad1984_dell_desktop_capture_source;
spec->mixers[0] = ad1984_dell_desktop_mixers;
break;
}
return 0;
}
static int ad1884a_mobile_master_sw_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
int ret = snd_hda_mixer_amp_switch_put(kcontrol, ucontrol);
int mute = (!ucontrol->value.integer.value[0] &&
!ucontrol->value.integer.value[1]);
snd_hda_codec_write_cache(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
mute ? 0x02 : 0x0);
return ret;
}
static void ad1884a_hp_automute(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x11);
snd_hda_codec_amp_stereo(codec, 0x16, HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
snd_hda_codec_write(codec, 0x16, 0, AC_VERB_SET_EAPD_BTLENABLE,
present ? 0x00 : 0x02);
}
static void ad1884a_hp_automic(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x14);
snd_hda_codec_write(codec, 0x0c, 0, AC_VERB_SET_CONNECT_SEL,
present ? 0 : 1);
}
static void ad1884a_hp_unsol_event(struct hda_codec *codec, unsigned int res)
{
switch (res >> 26) {
case AD1884A_HP_EVENT:
ad1884a_hp_automute(codec);
break;
case AD1884A_MIC_EVENT:
ad1884a_hp_automic(codec);
break;
}
}
static int ad1884a_hp_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1884a_hp_automute(codec);
ad1884a_hp_automic(codec);
return 0;
}
static void ad1884a_laptop_automute(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x11);
if (!present)
present = snd_hda_jack_detect(codec, 0x12);
snd_hda_codec_amp_stereo(codec, 0x16, HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
snd_hda_codec_write(codec, 0x16, 0, AC_VERB_SET_EAPD_BTLENABLE,
present ? 0x00 : 0x02);
}
static void ad1884a_laptop_automic(struct hda_codec *codec)
{
unsigned int idx;
if (snd_hda_jack_detect(codec, 0x14))
idx = 0;
else if (snd_hda_jack_detect(codec, 0x1c))
idx = 4;
else
idx = 1;
snd_hda_codec_write(codec, 0x0c, 0, AC_VERB_SET_CONNECT_SEL, idx);
}
static void ad1884a_laptop_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case AD1884A_HP_EVENT:
ad1884a_laptop_automute(codec);
break;
case AD1884A_MIC_EVENT:
ad1884a_laptop_automic(codec);
break;
}
}
static int ad1884a_laptop_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1884a_laptop_automute(codec);
ad1884a_laptop_automic(codec);
return 0;
}
static void ad1984a_thinkpad_automute(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x11);
snd_hda_codec_amp_stereo(codec, 0x12, HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
}
static void ad1984a_thinkpad_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) != AD1884A_HP_EVENT)
return;
ad1984a_thinkpad_automute(codec);
}
static int ad1984a_thinkpad_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1984a_thinkpad_automute(codec);
return 0;
}
static void ad1984a_precision_automute(struct hda_codec *codec)
{
unsigned int present;
present = snd_hda_jack_detect(codec, 0x12);
snd_hda_codec_amp_stereo(codec, 0x13, HDA_OUTPUT, 0,
HDA_AMP_MUTE, present ? HDA_AMP_MUTE : 0);
}
static void ad1984a_precision_unsol_event(struct hda_codec *codec,
unsigned int res)
{
if ((res >> 26) != AD1884A_HP_EVENT)
return;
ad1984a_precision_automute(codec);
}
static int ad1984a_precision_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1984a_precision_automute(codec);
return 0;
}
static void ad1984a_touchsmart_automic(struct hda_codec *codec)
{
if (snd_hda_jack_detect(codec, 0x1c))
snd_hda_codec_write(codec, 0x0c, 0,
AC_VERB_SET_CONNECT_SEL, 0x4);
else
snd_hda_codec_write(codec, 0x0c, 0,
AC_VERB_SET_CONNECT_SEL, 0x5);
}
static void ad1984a_touchsmart_unsol_event(struct hda_codec *codec,
unsigned int res)
{
switch (res >> 26) {
case AD1884A_HP_EVENT:
ad1884a_hp_automute(codec);
break;
case AD1884A_MIC_EVENT:
ad1984a_touchsmart_automic(codec);
break;
}
}
static int ad1984a_touchsmart_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1884a_hp_automute(codec);
ad1984a_touchsmart_automic(codec);
return 0;
}
static int patch_ad1884a(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err, board_config;
board_config = snd_hda_check_board_config(codec, AD1884A_MODELS,
ad1884a_models,
ad1884a_cfg_tbl);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = AD1884A_AUTO;
}
if (board_config == AD1884A_AUTO)
return ad1884_parse_auto_config(codec);
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
err = snd_hda_attach_beep_device(codec, 0x10);
if (err < 0) {
ad198x_free(codec);
return err;
}
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = ARRAY_SIZE(ad1884a_dac_nids);
spec->multiout.dac_nids = ad1884a_dac_nids;
spec->multiout.dig_out_nid = AD1884A_SPDIF_OUT;
spec->num_adc_nids = ARRAY_SIZE(ad1884a_adc_nids);
spec->adc_nids = ad1884a_adc_nids;
spec->capsrc_nids = ad1884a_capsrc_nids;
spec->input_mux = &ad1884a_capture_source;
spec->num_mixers = 1;
spec->mixers[0] = ad1884a_base_mixers;
spec->num_init_verbs = 1;
spec->init_verbs[0] = ad1884a_init_verbs;
spec->spdif_route = 0;
#ifdef CONFIG_PM
spec->loopback.amplist = ad1884a_loopbacks;
#endif
codec->patch_ops = ad198x_patch_ops;
switch (board_config) {
case AD1884A_LAPTOP:
spec->mixers[0] = ad1884a_laptop_mixers;
spec->init_verbs[spec->num_init_verbs++] = ad1884a_laptop_verbs;
spec->multiout.dig_out_nid = 0;
codec->patch_ops.unsol_event = ad1884a_laptop_unsol_event;
codec->patch_ops.init = ad1884a_laptop_init;
snd_hda_override_amp_caps(codec, 0x20, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
break;
case AD1884A_MOBILE:
spec->mixers[0] = ad1884a_mobile_mixers;
spec->init_verbs[0] = ad1884a_mobile_verbs;
spec->multiout.dig_out_nid = 0;
codec->patch_ops.unsol_event = ad1884a_hp_unsol_event;
codec->patch_ops.init = ad1884a_hp_init;
snd_hda_override_amp_caps(codec, 0x20, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
break;
case AD1884A_THINKPAD:
spec->mixers[0] = ad1984a_thinkpad_mixers;
spec->init_verbs[spec->num_init_verbs++] =
ad1984a_thinkpad_verbs;
spec->multiout.dig_out_nid = 0;
spec->input_mux = &ad1984a_thinkpad_capture_source;
codec->patch_ops.unsol_event = ad1984a_thinkpad_unsol_event;
codec->patch_ops.init = ad1984a_thinkpad_init;
break;
case AD1984A_PRECISION:
spec->mixers[0] = ad1984a_precision_mixers;
spec->init_verbs[spec->num_init_verbs++] =
ad1984a_precision_verbs;
spec->multiout.dig_out_nid = 0;
codec->patch_ops.unsol_event = ad1984a_precision_unsol_event;
codec->patch_ops.init = ad1984a_precision_init;
break;
case AD1984A_TOUCHSMART:
spec->mixers[0] = ad1984a_touchsmart_mixers;
spec->init_verbs[0] = ad1984a_touchsmart_verbs;
spec->multiout.dig_out_nid = 0;
codec->patch_ops.unsol_event = ad1984a_touchsmart_unsol_event;
codec->patch_ops.init = ad1984a_touchsmart_init;
snd_hda_override_amp_caps(codec, 0x20, HDA_INPUT,
(0x17 << AC_AMPCAP_OFFSET_SHIFT) |
(0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
(0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
(1 << AC_AMPCAP_MUTE_SHIFT));
break;
}
codec->no_trigger_sense = 1;
codec->no_sticky_stream = 1;
return 0;
}
static void ad1882_3stack_automute(struct hda_codec *codec)
{
bool mute = snd_hda_jack_detect(codec, 0x11);
snd_hda_codec_write(codec, 0x12, 0, AC_VERB_SET_PIN_WIDGET_CONTROL,
mute ? 0 : PIN_OUT);
}
static int ad1882_3stack_automute_init(struct hda_codec *codec)
{
ad198x_init(codec);
ad1882_3stack_automute(codec);
return 0;
}
static void ad1882_3stack_unsol_event(struct hda_codec *codec, unsigned int res)
{
switch (res >> 26) {
case AD1882_HP_EVENT:
ad1882_3stack_automute(codec);
break;
}
}
static int ad1882_parse_auto_config(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err;
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
spec->gen.mixer_nid = 0x20;
spec->gen.mixer_merge_nid = 0x21;
spec->gen.beep_nid = 0x10;
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
err = ad198x_parse_auto_config(codec);
if (err < 0)
goto error;
err = ad1988_add_spdif_mux_ctl(codec);
if (err < 0)
goto error;
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int patch_ad1882(struct hda_codec *codec)
{
struct ad198x_spec *spec;
int err, board_config;
board_config = snd_hda_check_board_config(codec, AD1882_MODELS,
ad1882_models, NULL);
if (board_config < 0) {
printk(KERN_INFO "hda_codec: %s: BIOS auto-probing.\n",
codec->chip_name);
board_config = AD1882_AUTO;
}
if (board_config == AD1882_AUTO)
return ad1882_parse_auto_config(codec);
err = alloc_ad_spec(codec);
if (err < 0)
return err;
spec = codec->spec;
err = snd_hda_attach_beep_device(codec, 0x10);
if (err < 0) {
ad198x_free(codec);
return err;
}
set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
spec->multiout.max_channels = 6;
spec->multiout.num_dacs = 3;
spec->multiout.dac_nids = ad1882_dac_nids;
spec->multiout.dig_out_nid = AD1882_SPDIF_OUT;
spec->num_adc_nids = ARRAY_SIZE(ad1882_adc_nids);
spec->adc_nids = ad1882_adc_nids;
spec->capsrc_nids = ad1882_capsrc_nids;
if (codec->vendor_id == 0x11d41882)
spec->input_mux = &ad1882_capture_source;
else
spec->input_mux = &ad1882a_capture_source;
spec->num_mixers = 2;
spec->mixers[0] = ad1882_base_mixers;
if (codec->vendor_id == 0x11d41882)
spec->mixers[1] = ad1882_loopback_mixers;
else
spec->mixers[1] = ad1882a_loopback_mixers;
spec->num_init_verbs = 1;
spec->init_verbs[0] = ad1882_init_verbs;
spec->spdif_route = 0;
#ifdef CONFIG_PM
spec->loopback.amplist = ad1882_loopbacks;
#endif
spec->vmaster_nid = 0x04;
codec->patch_ops = ad198x_patch_ops;
switch (board_config) {
default:
case AD1882_3STACK:
case AD1882_3STACK_AUTOMUTE:
spec->num_mixers = 3;
spec->mixers[2] = ad1882_3stack_mixers;
spec->channel_mode = ad1882_modes;
spec->num_channel_mode = ARRAY_SIZE(ad1882_modes);
spec->need_dac_fix = 1;
spec->multiout.max_channels = 2;
spec->multiout.num_dacs = 1;
if (board_config != AD1882_3STACK) {
spec->init_verbs[spec->num_init_verbs++] =
ad1882_3stack_automute_verbs;
codec->patch_ops.unsol_event = ad1882_3stack_unsol_event;
codec->patch_ops.init = ad1882_3stack_automute_init;
}
break;
case AD1882_6STACK:
spec->num_mixers = 3;
spec->mixers[2] = ad1882_6stack_mixers;
break;
}
codec->no_trigger_sense = 1;
codec->no_sticky_stream = 1;
return 0;
}
static int __init patch_analog_init(void)
{
return snd_hda_add_codec_preset(&analog_list);
}
static void __exit patch_analog_exit(void)
{
snd_hda_delete_codec_preset(&analog_list);
}
