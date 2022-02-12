static int patch_cmi9880(struct hda_codec *codec)
{
struct cmi_spec *spec;
struct auto_pin_cfg *cfg;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (spec == NULL)
return -ENOMEM;
codec->spec = spec;
codec->patch_ops = cmi_auto_patch_ops;
cfg = &spec->gen.autocfg;
snd_hda_gen_spec_init(&spec->gen);
err = snd_hda_parse_pin_defcfg(codec, cfg, NULL, 0);
if (err < 0)
goto error;
err = snd_hda_gen_parse_auto_config(codec, cfg);
if (err < 0)
goto error;
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
static int patch_cmi8888(struct hda_codec *codec)
{
struct cmi_spec *spec;
struct auto_pin_cfg *cfg;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
codec->spec = spec;
codec->patch_ops = cmi_auto_patch_ops;
cfg = &spec->gen.autocfg;
snd_hda_gen_spec_init(&spec->gen);
spec->gen.out_vol_mask = (1ULL << 0x10);
err = snd_hda_parse_pin_defcfg(codec, cfg, NULL, 0);
if (err < 0)
goto error;
err = snd_hda_gen_parse_auto_config(codec, cfg);
if (err < 0)
goto error;
if (get_defcfg_device(snd_hda_codec_get_pincfg(codec, 0x10)) ==
AC_JACK_HP_OUT) {
static const struct snd_kcontrol_new amp_kctl =
HDA_CODEC_VOLUME("Headphone Amp Playback Volume",
0x10, 0, HDA_OUTPUT);
if (!snd_hda_gen_add_kctl(&spec->gen, NULL, &amp_kctl)) {
err = -ENOMEM;
goto error;
}
}
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
