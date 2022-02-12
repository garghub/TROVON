static int ca0110_parse_auto_config(struct hda_codec *codec)
{
struct hda_gen_spec *spec = codec->spec;
int err;
err = snd_hda_parse_pin_defcfg(codec, &spec->autocfg, NULL, 0);
if (err < 0)
return err;
err = snd_hda_gen_parse_auto_config(codec, &spec->autocfg);
if (err < 0)
return err;
return 0;
}
static int patch_ca0110(struct hda_codec *codec)
{
struct hda_gen_spec *spec;
int err;
spec = kzalloc(sizeof(*spec), GFP_KERNEL);
if (!spec)
return -ENOMEM;
snd_hda_gen_spec_init(spec);
codec->spec = spec;
spec->multi_cap_vol = 1;
codec->bus->needs_damn_long_delay = 1;
err = ca0110_parse_auto_config(codec);
if (err < 0)
goto error;
codec->patch_ops = ca0110_patch_ops;
return 0;
error:
snd_hda_gen_free(codec);
return err;
}
