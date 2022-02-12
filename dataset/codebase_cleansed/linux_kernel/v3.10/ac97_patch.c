static int patch_build_controls(struct snd_ac97 * ac97, const struct snd_kcontrol_new *controls, int count)
{
int idx, err;
for (idx = 0; idx < count; idx++)
if ((err = snd_ctl_add(ac97->bus->card, snd_ac97_cnew(&controls[idx], ac97))) < 0)
return err;
return 0;
}
static void reset_tlv(struct snd_ac97 *ac97, const char *name,
const unsigned int *tlv)
{
struct snd_ctl_elem_id sid;
struct snd_kcontrol *kctl;
memset(&sid, 0, sizeof(sid));
strcpy(sid.name, name);
sid.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
kctl = snd_ctl_find_id(ac97->bus->card, &sid);
if (kctl && kctl->tlv.p)
kctl->tlv.p = tlv;
}
static int ac97_update_bits_page(struct snd_ac97 *ac97, unsigned short reg, unsigned short mask, unsigned short value, unsigned short page)
{
unsigned short page_save;
int ret;
mutex_lock(&ac97->page_mutex);
page_save = snd_ac97_read(ac97, AC97_INT_PAGING) & AC97_PAGE_MASK;
snd_ac97_update_bits(ac97, AC97_INT_PAGING, AC97_PAGE_MASK, page);
ret = snd_ac97_update_bits(ac97, reg, mask, value);
snd_ac97_update_bits(ac97, AC97_INT_PAGING, AC97_PAGE_MASK, page_save);
mutex_unlock(&ac97->page_mutex);
return ret;
}
static int ac97_enum_text_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo,
const char **texts, unsigned int nums)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = nums;
if (uinfo->value.enumerated.item > nums - 1)
uinfo->value.enumerated.item = nums - 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int ac97_surround_jack_mode_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static const char *texts[] = { "Shared", "Independent" };
return ac97_enum_text_info(kcontrol, uinfo, texts, 2);
}
static int ac97_surround_jack_mode_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = ac97->indep_surround;
return 0;
}
static int ac97_surround_jack_mode_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned char indep = !!ucontrol->value.enumerated.item[0];
if (indep != ac97->indep_surround) {
ac97->indep_surround = indep;
if (ac97->build_ops->update_jacks)
ac97->build_ops->update_jacks(ac97);
return 1;
}
return 0;
}
static int ac97_channel_mode_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static const char *texts[] = { "2ch", "4ch", "6ch", "8ch" };
return ac97_enum_text_info(kcontrol, uinfo, texts,
kcontrol->private_value);
}
static int ac97_channel_mode_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = ac97->channel_mode;
return 0;
}
static int ac97_channel_mode_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned char mode = ucontrol->value.enumerated.item[0];
if (mode >= kcontrol->private_value)
return -EINVAL;
if (mode != ac97->channel_mode) {
ac97->channel_mode = mode;
if (ac97->build_ops->update_jacks)
ac97->build_ops->update_jacks(ac97);
return 1;
}
return 0;
}
static inline int is_surround_on(struct snd_ac97 *ac97)
{
return ac97->channel_mode >= 1;
}
static inline int is_clfe_on(struct snd_ac97 *ac97)
{
return ac97->channel_mode >= 2;
}
static inline int is_shared_surrout(struct snd_ac97 *ac97)
{
return !ac97->indep_surround && is_surround_on(ac97);
}
static inline int is_shared_clfeout(struct snd_ac97 *ac97)
{
return !ac97->indep_surround && is_clfe_on(ac97);
}
static inline int is_shared_linein(struct snd_ac97 *ac97)
{
return !ac97->indep_surround && !is_surround_on(ac97);
}
static inline int is_shared_micin(struct snd_ac97 *ac97)
{
return !ac97->indep_surround && !is_clfe_on(ac97);
}
static inline int alc850_is_aux_back_surround(struct snd_ac97 *ac97)
{
return is_surround_on(ac97);
}
static int snd_ac97_ymf7x3_info_speaker(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[3] = {
"Standard", "Small", "Smaller"
};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 3;
if (uinfo->value.enumerated.item > 2)
uinfo->value.enumerated.item = 2;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_ymf7x3_get_speaker(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_YMF7X3_3D_MODE_SEL];
val = (val >> 10) & 3;
if (val > 0)
val--;
ucontrol->value.enumerated.item[0] = val;
return 0;
}
static int snd_ac97_ymf7x3_put_speaker(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
if (ucontrol->value.enumerated.item[0] > 2)
return -EINVAL;
val = (ucontrol->value.enumerated.item[0] + 1) << 10;
return snd_ac97_update(ac97, AC97_YMF7X3_3D_MODE_SEL, val);
}
static int snd_ac97_ymf7x3_spdif_source_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[2] = { "AC-Link", "A/D Converter" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item > 1)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_ymf7x3_spdif_source_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_YMF7X3_DIT_CTRL];
ucontrol->value.enumerated.item[0] = (val >> 1) & 1;
return 0;
}
static int snd_ac97_ymf7x3_spdif_source_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
if (ucontrol->value.enumerated.item[0] > 1)
return -EINVAL;
val = ucontrol->value.enumerated.item[0] << 1;
return snd_ac97_update_bits(ac97, AC97_YMF7X3_DIT_CTRL, 0x0002, val);
}
static int patch_yamaha_ymf7x3_3d(struct snd_ac97 *ac97)
{
struct snd_kcontrol *kctl;
int err;
kctl = snd_ac97_cnew(&snd_ac97_controls_3d[0], ac97);
err = snd_ctl_add(ac97->bus->card, kctl);
if (err < 0)
return err;
strcpy(kctl->id.name, "3D Control - Wide");
kctl->private_value = AC97_SINGLE_VALUE(AC97_3D_CONTROL, 9, 7, 0);
snd_ac97_write_cache(ac97, AC97_3D_CONTROL, 0x0000);
err = snd_ctl_add(ac97->bus->card,
snd_ac97_cnew(&snd_ac97_ymf7x3_controls_speaker,
ac97));
if (err < 0)
return err;
snd_ac97_write_cache(ac97, AC97_YMF7X3_3D_MODE_SEL, 0x0c00);
return 0;
}
static int patch_yamaha_ymf743_build_spdif(struct snd_ac97 *ac97)
{
int err;
err = patch_build_controls(ac97, &snd_ac97_controls_spdif[0], 3);
if (err < 0)
return err;
err = patch_build_controls(ac97,
snd_ac97_yamaha_ymf743_controls_spdif, 3);
if (err < 0)
return err;
snd_ac97_write_cache(ac97, AC97_YMF7X3_DIT_CTRL, 0xa201);
return 0;
}
static int patch_yamaha_ymf743(struct snd_ac97 *ac97)
{
ac97->build_ops = &patch_yamaha_ymf743_ops;
ac97->caps |= AC97_BC_BASS_TREBLE;
ac97->caps |= 0x04 << 10;
ac97->rates[AC97_RATES_SPDIF] = SNDRV_PCM_RATE_48000;
ac97->ext_id |= AC97_EI_SPDIF;
return 0;
}
static int snd_ac97_ymf753_spdif_output_pin_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[3] = { "Disabled", "Pin 43", "Pin 48" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 3;
if (uinfo->value.enumerated.item > 2)
uinfo->value.enumerated.item = 2;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_ymf753_spdif_output_pin_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_YMF7X3_DIT_CTRL];
ucontrol->value.enumerated.item[0] = (val & 0x0008) ? 2 : (val & 0x0020) ? 1 : 0;
return 0;
}
static int snd_ac97_ymf753_spdif_output_pin_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
if (ucontrol->value.enumerated.item[0] > 2)
return -EINVAL;
val = (ucontrol->value.enumerated.item[0] == 2) ? 0x0008 :
(ucontrol->value.enumerated.item[0] == 1) ? 0x0020 : 0;
return snd_ac97_update_bits(ac97, AC97_YMF7X3_DIT_CTRL, 0x0028, val);
}
static int patch_yamaha_ymf753_post_spdif(struct snd_ac97 * ac97)
{
int err;
if ((err = patch_build_controls(ac97, snd_ac97_ymf753_controls_spdif, ARRAY_SIZE(snd_ac97_ymf753_controls_spdif))) < 0)
return err;
return 0;
}
static int patch_yamaha_ymf753(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_yamaha_ymf753_ops;
ac97->caps |= AC97_BC_BASS_TREBLE;
ac97->caps |= 0x04 << 10;
return 0;
}
static int patch_wolfson_wm9703_specific(struct snd_ac97 * ac97)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(wm97xx_snd_ac97_controls); i++) {
if ((err = snd_ctl_add(ac97->bus->card, snd_ac97_cnew(&wm97xx_snd_ac97_controls[i], ac97))) < 0)
return err;
}
snd_ac97_write_cache(ac97, AC97_WM97XX_FMIXER_VOL, 0x0808);
return 0;
}
static int patch_wolfson03(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_wolfson_wm9703_ops;
return 0;
}
static int patch_wolfson_wm9704_specific(struct snd_ac97 * ac97)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(wm9704_snd_ac97_controls); i++) {
if ((err = snd_ctl_add(ac97->bus->card, snd_ac97_cnew(&wm9704_snd_ac97_controls[i], ac97))) < 0)
return err;
}
snd_ac97_write_cache(ac97, AC97_WM9704_TEST, 0x0200);
return 0;
}
static int patch_wolfson04(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_wolfson_wm9704_ops;
return 0;
}
static int patch_wolfson05(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_wolfson_wm9703_ops;
#ifdef CONFIG_TOUCHSCREEN_WM9705
ac97->flags |= AC97_HAS_NO_VIDEO | AC97_HAS_NO_AUX;
#endif
return 0;
}
static int patch_wolfson_wm9711_specific(struct snd_ac97 * ac97)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(wm9711_snd_ac97_controls); i++) {
if ((err = snd_ctl_add(ac97->bus->card, snd_ac97_cnew(&wm9711_snd_ac97_controls[i], ac97))) < 0)
return err;
}
snd_ac97_write_cache(ac97, AC97_CODEC_CLASS_REV, 0x0808);
snd_ac97_write_cache(ac97, AC97_PCI_SVID, 0x0808);
snd_ac97_write_cache(ac97, AC97_VIDEO, 0x0808);
snd_ac97_write_cache(ac97, AC97_AUX, 0x0808);
snd_ac97_write_cache(ac97, AC97_PC_BEEP, 0x0808);
snd_ac97_write_cache(ac97, AC97_CD, 0x0000);
return 0;
}
static int patch_wolfson11(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_wolfson_wm9711_ops;
ac97->flags |= AC97_HAS_NO_REC_GAIN | AC97_STEREO_MUTES | AC97_HAS_NO_MIC |
AC97_HAS_NO_PC_BEEP | AC97_HAS_NO_VIDEO | AC97_HAS_NO_CD;
return 0;
}
static int patch_wolfson_wm9713_3d (struct snd_ac97 * ac97)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(wm13_snd_ac97_controls_3d); i++) {
if ((err = snd_ctl_add(ac97->bus->card, snd_ac97_cnew(&wm13_snd_ac97_controls_3d[i], ac97))) < 0)
return err;
}
return 0;
}
static int patch_wolfson_wm9713_specific(struct snd_ac97 * ac97)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(wm13_snd_ac97_controls); i++) {
if ((err = snd_ctl_add(ac97->bus->card, snd_ac97_cnew(&wm13_snd_ac97_controls[i], ac97))) < 0)
return err;
}
snd_ac97_write_cache(ac97, AC97_PC_BEEP, 0x0808);
snd_ac97_write_cache(ac97, AC97_PHONE, 0x0808);
snd_ac97_write_cache(ac97, AC97_MIC, 0x0808);
snd_ac97_write_cache(ac97, AC97_LINE, 0x00da);
snd_ac97_write_cache(ac97, AC97_CD, 0x0808);
snd_ac97_write_cache(ac97, AC97_VIDEO, 0xd612);
snd_ac97_write_cache(ac97, AC97_REC_GAIN, 0x1ba0);
return 0;
}
static void patch_wolfson_wm9713_suspend (struct snd_ac97 * ac97)
{
snd_ac97_write_cache(ac97, AC97_EXTENDED_MID, 0xfeff);
snd_ac97_write_cache(ac97, AC97_EXTENDED_MSTATUS, 0xffff);
}
static void patch_wolfson_wm9713_resume (struct snd_ac97 * ac97)
{
snd_ac97_write_cache(ac97, AC97_EXTENDED_MID, 0xda00);
snd_ac97_write_cache(ac97, AC97_EXTENDED_MSTATUS, 0x3810);
snd_ac97_write_cache(ac97, AC97_POWERDOWN, 0x0);
}
static int patch_wolfson13(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_wolfson_wm9713_ops;
ac97->flags |= AC97_HAS_NO_REC_GAIN | AC97_STEREO_MUTES | AC97_HAS_NO_PHONE |
AC97_HAS_NO_PC_BEEP | AC97_HAS_NO_VIDEO | AC97_HAS_NO_CD | AC97_HAS_NO_TONE |
AC97_HAS_NO_STD_PCM;
ac97->scaps &= ~AC97_SCAP_MODEM;
snd_ac97_write_cache(ac97, AC97_EXTENDED_MID, 0xda00);
snd_ac97_write_cache(ac97, AC97_EXTENDED_MSTATUS, 0x3810);
snd_ac97_write_cache(ac97, AC97_POWERDOWN, 0x0);
return 0;
}
static int patch_tritech_tr28028(struct snd_ac97 * ac97)
{
snd_ac97_write_cache(ac97, 0x26, 0x0300);
snd_ac97_write_cache(ac97, 0x26, 0x0000);
snd_ac97_write_cache(ac97, AC97_SURROUND_MASTER, 0x0000);
snd_ac97_write_cache(ac97, AC97_SPDIF, 0x0000);
return 0;
}
static int patch_sigmatel_stac9700_3d(struct snd_ac97 * ac97)
{
struct snd_kcontrol *kctl;
int err;
if ((err = snd_ctl_add(ac97->bus->card, kctl = snd_ac97_cnew(&snd_ac97_controls_3d[0], ac97))) < 0)
return err;
strcpy(kctl->id.name, "3D Control Sigmatel - Depth");
kctl->private_value = AC97_SINGLE_VALUE(AC97_3D_CONTROL, 2, 3, 0);
snd_ac97_write_cache(ac97, AC97_3D_CONTROL, 0x0000);
return 0;
}
static int patch_sigmatel_stac9708_3d(struct snd_ac97 * ac97)
{
struct snd_kcontrol *kctl;
int err;
if ((err = snd_ctl_add(ac97->bus->card, kctl = snd_ac97_cnew(&snd_ac97_controls_3d[0], ac97))) < 0)
return err;
strcpy(kctl->id.name, "3D Control Sigmatel - Depth");
kctl->private_value = AC97_SINGLE_VALUE(AC97_3D_CONTROL, 0, 3, 0);
if ((err = snd_ctl_add(ac97->bus->card, kctl = snd_ac97_cnew(&snd_ac97_controls_3d[0], ac97))) < 0)
return err;
strcpy(kctl->id.name, "3D Control Sigmatel - Rear Depth");
kctl->private_value = AC97_SINGLE_VALUE(AC97_3D_CONTROL, 2, 3, 0);
snd_ac97_write_cache(ac97, AC97_3D_CONTROL, 0x0000);
return 0;
}
static int patch_sigmatel_stac97xx_specific(struct snd_ac97 * ac97)
{
int err;
snd_ac97_write_cache(ac97, AC97_SIGMATEL_ANALOG, snd_ac97_read(ac97, AC97_SIGMATEL_ANALOG) & ~0x0003);
if (snd_ac97_try_bit(ac97, AC97_SIGMATEL_ANALOG, 1))
if ((err = patch_build_controls(ac97, &snd_ac97_sigmatel_controls[0], 1)) < 0)
return err;
if (snd_ac97_try_bit(ac97, AC97_SIGMATEL_ANALOG, 0))
if ((err = patch_build_controls(ac97, &snd_ac97_sigmatel_controls[1], 1)) < 0)
return err;
if (snd_ac97_try_bit(ac97, AC97_SIGMATEL_DAC2INVERT, 2))
if ((err = patch_build_controls(ac97, &snd_ac97_sigmatel_4speaker, 1)) < 0)
return err;
if (snd_ac97_try_bit(ac97, AC97_SIGMATEL_DAC2INVERT, 3))
if ((err = patch_build_controls(ac97, &snd_ac97_sigmatel_phaseinvert, 1)) < 0)
return err;
return 0;
}
static int patch_sigmatel_stac9700(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_sigmatel_stac9700_ops;
return 0;
}
static int snd_ac97_stac9708_put_bias(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
int err;
mutex_lock(&ac97->page_mutex);
snd_ac97_write(ac97, AC97_SIGMATEL_BIAS1, 0xabba);
err = snd_ac97_update_bits(ac97, AC97_SIGMATEL_BIAS2, 0x0010,
(ucontrol->value.integer.value[0] & 1) << 4);
snd_ac97_write(ac97, AC97_SIGMATEL_BIAS1, 0);
mutex_unlock(&ac97->page_mutex);
return err;
}
static int patch_sigmatel_stac9708_specific(struct snd_ac97 *ac97)
{
int err;
snd_ac97_remove_ctl(ac97, "PCM Out Path & Mute", NULL);
snd_ac97_rename_vol_ctl(ac97, "Headphone Playback", "Sigmatel Surround Playback");
if ((err = patch_build_controls(ac97, &snd_ac97_stac9708_bias_control, 1)) < 0)
return err;
return patch_sigmatel_stac97xx_specific(ac97);
}
static int patch_sigmatel_stac9708(struct snd_ac97 * ac97)
{
unsigned int codec72, codec6c;
ac97->build_ops = &patch_sigmatel_stac9708_ops;
ac97->caps |= 0x10;
codec72 = snd_ac97_read(ac97, AC97_SIGMATEL_BIAS2) & 0x8000;
codec6c = snd_ac97_read(ac97, AC97_SIGMATEL_ANALOG);
if ((codec72==0) && (codec6c==0)) {
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC1, 0xabba);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC2, 0x1000);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_BIAS1, 0xabba);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_BIAS2, 0x0007);
} else if ((codec72==0x8000) && (codec6c==0)) {
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC1, 0xabba);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC2, 0x1001);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_DAC2INVERT, 0x0008);
} else if ((codec72==0x8000) && (codec6c==0x0080)) {
}
snd_ac97_write_cache(ac97, AC97_SIGMATEL_MULTICHN, 0x0000);
return 0;
}
static int patch_sigmatel_stac9721(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_sigmatel_stac9700_ops;
if (snd_ac97_read(ac97, AC97_SIGMATEL_ANALOG) == 0) {
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC1, 0xabba);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC2, 0x4000);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_BIAS1, 0xabba);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_BIAS2, 0x0002);
}
snd_ac97_write_cache(ac97, AC97_SIGMATEL_MULTICHN, 0x0000);
return 0;
}
static int patch_sigmatel_stac9744(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_sigmatel_stac9700_ops;
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC1, 0xabba);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC2, 0x0000);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_BIAS1, 0xabba);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_BIAS2, 0x0002);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_MULTICHN, 0x0000);
return 0;
}
static int patch_sigmatel_stac9756(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_sigmatel_stac9700_ops;
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC1, 0xabba);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_CIC2, 0x0000);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_BIAS1, 0xabba);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_BIAS2, 0x0002);
snd_ac97_write_cache(ac97, AC97_SIGMATEL_MULTICHN, 0x0000);
return 0;
}
static int snd_ac97_stac9758_output_jack_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[5] = { "Input/Disabled", "Front Output",
"Rear Output", "Center/LFE Output", "Mixer Output" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 5;
if (uinfo->value.enumerated.item > 4)
uinfo->value.enumerated.item = 4;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_stac9758_output_jack_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
int shift = kcontrol->private_value;
unsigned short val;
val = ac97->regs[AC97_SIGMATEL_OUTSEL] >> shift;
if (!(val & 4))
ucontrol->value.enumerated.item[0] = 0;
else
ucontrol->value.enumerated.item[0] = 1 + (val & 3);
return 0;
}
static int snd_ac97_stac9758_output_jack_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
int shift = kcontrol->private_value;
unsigned short val;
if (ucontrol->value.enumerated.item[0] > 4)
return -EINVAL;
if (ucontrol->value.enumerated.item[0] == 0)
val = 0;
else
val = 4 | (ucontrol->value.enumerated.item[0] - 1);
return ac97_update_bits_page(ac97, AC97_SIGMATEL_OUTSEL,
7 << shift, val << shift, 0);
}
static int snd_ac97_stac9758_input_jack_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[7] = { "Mic2 Jack", "Mic1 Jack", "Line In Jack",
"Front Jack", "Rear Jack", "Center/LFE Jack", "Mute" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 7;
if (uinfo->value.enumerated.item > 6)
uinfo->value.enumerated.item = 6;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_stac9758_input_jack_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
int shift = kcontrol->private_value;
unsigned short val;
val = ac97->regs[AC97_SIGMATEL_INSEL];
ucontrol->value.enumerated.item[0] = (val >> shift) & 7;
return 0;
}
static int snd_ac97_stac9758_input_jack_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
int shift = kcontrol->private_value;
return ac97_update_bits_page(ac97, AC97_SIGMATEL_INSEL, 7 << shift,
ucontrol->value.enumerated.item[0] << shift, 0);
}
static int snd_ac97_stac9758_phonesel_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[3] = { "None", "Front Jack", "Rear Jack" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 3;
if (uinfo->value.enumerated.item > 2)
uinfo->value.enumerated.item = 2;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_stac9758_phonesel_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = ac97->regs[AC97_SIGMATEL_IOMISC] & 3;
return 0;
}
static int snd_ac97_stac9758_phonesel_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
return ac97_update_bits_page(ac97, AC97_SIGMATEL_IOMISC, 3,
ucontrol->value.enumerated.item[0], 0);
}
static int patch_sigmatel_stac9758_specific(struct snd_ac97 *ac97)
{
int err;
err = patch_sigmatel_stac97xx_specific(ac97);
if (err < 0)
return err;
err = patch_build_controls(ac97, snd_ac97_sigmatel_stac9758_controls,
ARRAY_SIZE(snd_ac97_sigmatel_stac9758_controls));
if (err < 0)
return err;
snd_ac97_rename_vol_ctl(ac97, "Headphone Playback", "Front Playback");
snd_ac97_rename_vol_ctl(ac97, "Video Playback", "Surround Mix Playback");
return 0;
}
static int patch_sigmatel_stac9758(struct snd_ac97 * ac97)
{
static unsigned short regs[4] = {
AC97_SIGMATEL_OUTSEL,
AC97_SIGMATEL_IOMISC,
AC97_SIGMATEL_INSEL,
AC97_SIGMATEL_VARIOUS
};
static unsigned short def_regs[4] = {
0xd794,
0x2001,
0x0201,
0x0040
};
static unsigned short m675_regs[4] = {
0xfc70,
0x2102,
0x0203,
0x0041
};
unsigned short *pregs = def_regs;
int i;
if (ac97->pci &&
ac97->subsystem_vendor == 0x107b &&
ac97->subsystem_device == 0x0601)
pregs = m675_regs;
ac97->build_ops = &patch_sigmatel_stac9758_ops;
snd_ac97_update_bits(ac97, AC97_INT_PAGING, AC97_PAGE_MASK, AC97_PAGE_VENDOR);
for (i = 0; i < 4; i++)
snd_ac97_write_cache(ac97, regs[i], pregs[i]);
ac97->flags |= AC97_STEREO_MUTES;
return 0;
}
static int patch_cirrus_build_spdif(struct snd_ac97 * ac97)
{
int err;
if ((err = patch_build_controls(ac97, &snd_ac97_controls_spdif[0], 3)) < 0)
return err;
if ((err = patch_build_controls(ac97, &snd_ac97_cirrus_controls_spdif[0], 1)) < 0)
return err;
switch (ac97->id & AC97_ID_CS_MASK) {
case AC97_ID_CS4205:
if ((err = patch_build_controls(ac97, &snd_ac97_cirrus_controls_spdif[1], 1)) < 0)
return err;
break;
}
snd_ac97_write_cache(ac97, AC97_CSR_SPDIF, 0x0a20);
return 0;
}
static int patch_cirrus_spdif(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_cirrus_ops;
ac97->flags |= AC97_CS_SPDIF;
ac97->rates[AC97_RATES_SPDIF] &= ~SNDRV_PCM_RATE_32000;
ac97->ext_id |= AC97_EI_SPDIF;
snd_ac97_write_cache(ac97, AC97_CSR_ACMODE, 0x0080);
return 0;
}
static int patch_cirrus_cs4299(struct snd_ac97 * ac97)
{
ac97->flags |= AC97_HAS_PC_BEEP;
return patch_cirrus_spdif(ac97);
}
static int patch_conexant_build_spdif(struct snd_ac97 * ac97)
{
int err;
if ((err = patch_build_controls(ac97, &snd_ac97_controls_spdif[0], 3)) < 0)
return err;
if ((err = patch_build_controls(ac97, &snd_ac97_conexant_controls_spdif[0], 1)) < 0)
return err;
snd_ac97_write_cache(ac97, AC97_CXR_AUDIO_MISC,
snd_ac97_read(ac97, AC97_CXR_AUDIO_MISC) & ~(AC97_CXR_SPDIFEN|AC97_CXR_COPYRGT|AC97_CXR_SPDIF_MASK));
return 0;
}
static int patch_conexant(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_conexant_ops;
ac97->flags |= AC97_CX_SPDIF;
ac97->ext_id |= AC97_EI_SPDIF;
ac97->rates[AC97_RATES_SPDIF] = SNDRV_PCM_RATE_48000;
return 0;
}
static int patch_cx20551(struct snd_ac97 *ac97)
{
snd_ac97_update_bits(ac97, 0x5c, 0x01, 0x01);
return 0;
}
static void ad18xx_resume(struct snd_ac97 *ac97)
{
static unsigned short setup_regs[] = {
AC97_AD_MISC, AC97_AD_SERIAL_CFG, AC97_AD_JACK_SPDIF,
};
int i, codec;
for (i = 0; i < (int)ARRAY_SIZE(setup_regs); i++) {
unsigned short reg = setup_regs[i];
if (test_bit(reg, ac97->reg_accessed)) {
snd_ac97_write(ac97, reg, ac97->regs[reg]);
snd_ac97_read(ac97, reg);
}
}
if (! (ac97->flags & AC97_AD_MULTI))
snd_ac97_restore_status(ac97);
else {
for (codec = 0; codec < 3; codec++) {
if (! ac97->spec.ad18xx.id[codec])
continue;
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 0x7000,
ac97->spec.ad18xx.unchained[codec] | ac97->spec.ad18xx.chained[codec]);
ac97->bus->ops->write(ac97, AC97_AD_CODEC_CFG, ac97->spec.ad18xx.codec_cfg[codec]);
}
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 0x7000, 0x7000);
for (i = 2; i < 0x7c ; i += 2) {
if (i == AC97_POWERDOWN || i == AC97_EXTENDED_ID)
continue;
if (test_bit(i, ac97->reg_accessed)) {
if (i == AC97_PCM) {
for (codec = 0; codec < 3; codec++) {
if (! ac97->spec.ad18xx.id[codec])
continue;
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 0x7000,
ac97->spec.ad18xx.unchained[codec] | ac97->spec.ad18xx.chained[codec]);
ac97->bus->ops->write(ac97, AC97_PCM, ac97->spec.ad18xx.pcmreg[codec]);
}
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 0x7000, 0x7000);
continue;
} else if (i == AC97_AD_TEST ||
i == AC97_AD_CODEC_CFG ||
i == AC97_AD_SERIAL_CFG)
continue;
}
snd_ac97_write(ac97, i, ac97->regs[i]);
snd_ac97_read(ac97, i);
}
}
snd_ac97_restore_iec958(ac97);
}
static void ad1888_resume(struct snd_ac97 *ac97)
{
ad18xx_resume(ac97);
snd_ac97_write_cache(ac97, AC97_CODEC_CLASS_REV, 0x8080);
}
static int patch_ad1819(struct snd_ac97 * ac97)
{
unsigned short scfg;
scfg = snd_ac97_read(ac97, AC97_AD_SERIAL_CFG);
snd_ac97_write_cache(ac97, AC97_AD_SERIAL_CFG, scfg | 0x7000);
ac97->res_table = ad1819_restbl;
return 0;
}
static unsigned short patch_ad1881_unchained(struct snd_ac97 * ac97, int idx, unsigned short mask)
{
unsigned short val;
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 0x7000, mask);
snd_ac97_write_cache(ac97, AC97_AD_CODEC_CFG, 0x0000);
val = snd_ac97_read(ac97, AC97_VENDOR_ID2);
if ((val & 0xff40) != 0x5340)
return 0;
ac97->spec.ad18xx.unchained[idx] = mask;
ac97->spec.ad18xx.id[idx] = val;
ac97->spec.ad18xx.codec_cfg[idx] = 0x0000;
return mask;
}
static int patch_ad1881_chained1(struct snd_ac97 * ac97, int idx, unsigned short codec_bits)
{
static int cfg_bits[3] = { 1<<12, 1<<14, 1<<13 };
unsigned short val;
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 0x7000, cfg_bits[idx]);
snd_ac97_write_cache(ac97, AC97_AD_CODEC_CFG, 0x0004);
val = snd_ac97_read(ac97, AC97_VENDOR_ID2);
if ((val & 0xff40) != 0x5340)
return 0;
if (codec_bits)
snd_ac97_write_cache(ac97, AC97_AD_CODEC_CFG, codec_bits);
ac97->spec.ad18xx.chained[idx] = cfg_bits[idx];
ac97->spec.ad18xx.id[idx] = val;
ac97->spec.ad18xx.codec_cfg[idx] = codec_bits ? codec_bits : 0x0004;
return 1;
}
static void patch_ad1881_chained(struct snd_ac97 * ac97, int unchained_idx, int cidx1, int cidx2)
{
if (ac97->spec.ad18xx.unchained[cidx1] || ac97->spec.ad18xx.chained[cidx1])
cidx1 = -1;
if (ac97->spec.ad18xx.unchained[cidx2] || ac97->spec.ad18xx.chained[cidx2])
cidx2 = -1;
if (cidx1 < 0 && cidx2 < 0)
return;
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 0x7000,
ac97->spec.ad18xx.unchained[unchained_idx]);
snd_ac97_write_cache(ac97, AC97_AD_CODEC_CFG, 0x0002);
ac97->spec.ad18xx.codec_cfg[unchained_idx] = 0x0002;
if (cidx1 >= 0) {
if (cidx2 < 0)
patch_ad1881_chained1(ac97, cidx1, 0);
else if (patch_ad1881_chained1(ac97, cidx1, 0x0006))
patch_ad1881_chained1(ac97, cidx2, 0);
else if (patch_ad1881_chained1(ac97, cidx2, 0x0006))
patch_ad1881_chained1(ac97, cidx1, 0);
} else if (cidx2 >= 0) {
patch_ad1881_chained1(ac97, cidx2, 0);
}
}
static int patch_ad1881(struct snd_ac97 * ac97)
{
static const char cfg_idxs[3][2] = {
{2, 1},
{0, 2},
{0, 1}
};
unsigned short codecs[3];
unsigned short val;
int idx, num;
val = snd_ac97_read(ac97, AC97_AD_SERIAL_CFG);
snd_ac97_write_cache(ac97, AC97_AD_SERIAL_CFG, val);
codecs[0] = patch_ad1881_unchained(ac97, 0, (1<<12));
codecs[1] = patch_ad1881_unchained(ac97, 1, (1<<14));
codecs[2] = patch_ad1881_unchained(ac97, 2, (1<<13));
if (! (codecs[0] || codecs[1] || codecs[2]))
goto __end;
for (idx = 0; idx < 3; idx++)
if (ac97->spec.ad18xx.unchained[idx])
patch_ad1881_chained(ac97, idx, cfg_idxs[idx][0], cfg_idxs[idx][1]);
if (ac97->spec.ad18xx.id[1]) {
ac97->flags |= AC97_AD_MULTI;
ac97->scaps |= AC97_SCAP_SURROUND_DAC;
}
if (ac97->spec.ad18xx.id[2]) {
ac97->flags |= AC97_AD_MULTI;
ac97->scaps |= AC97_SCAP_CENTER_LFE_DAC;
}
__end:
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 0x7000, 0x7000);
for (idx = num = 0; idx < 3; idx++)
if (ac97->spec.ad18xx.id[idx])
num++;
if (num == 1) {
snd_ac97_write_cache(ac97, AC97_AD_CODEC_CFG, 0x0000);
ac97->spec.ad18xx.codec_cfg[0] =
ac97->spec.ad18xx.codec_cfg[1] =
ac97->spec.ad18xx.codec_cfg[2] = 0x0000;
}
ac97->ext_id = snd_ac97_read(ac97, AC97_EXTENDED_ID);
if (ac97->spec.ad18xx.id[0]) {
ac97->id &= 0xffff0000;
ac97->id |= ac97->spec.ad18xx.id[0];
}
ac97->build_ops = &patch_ad1881_build_ops;
return 0;
}
static int patch_ad1885_specific(struct snd_ac97 * ac97)
{
int err;
if ((err = patch_build_controls(ac97, snd_ac97_controls_ad1885, ARRAY_SIZE(snd_ac97_controls_ad1885))) < 0)
return err;
reset_tlv(ac97, "Headphone Playback Volume",
db_scale_6bit_6db_max);
return 0;
}
static int patch_ad1885(struct snd_ac97 * ac97)
{
patch_ad1881(ac97);
snd_ac97_write_cache(ac97, AC97_AD_MISC, 0x0404);
ac97->build_ops = &patch_ad1885_build_ops;
return 0;
}
static int patch_ad1886_specific(struct snd_ac97 * ac97)
{
reset_tlv(ac97, "Headphone Playback Volume",
db_scale_6bit_6db_max);
return 0;
}
static int patch_ad1886(struct snd_ac97 * ac97)
{
patch_ad1881(ac97);
snd_ac97_write_cache(ac97, AC97_AD_JACK_SPDIF, 0x0010);
ac97->build_ops = &patch_ad1886_build_ops;
return 0;
}
static int snd_ac97_ad198x_spdif_source_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[2] = { "AC-Link", "A/D Converter" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item > 1)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_ad198x_spdif_source_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_AD_SERIAL_CFG];
ucontrol->value.enumerated.item[0] = (val >> 2) & 1;
return 0;
}
static int snd_ac97_ad198x_spdif_source_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
if (ucontrol->value.enumerated.item[0] > 1)
return -EINVAL;
val = ucontrol->value.enumerated.item[0] << 2;
return snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 0x0004, val);
}
static int patch_ad198x_post_spdif(struct snd_ac97 * ac97)
{
return patch_build_controls(ac97, &snd_ac97_ad198x_spdif_source, 1);
}
static int check_list(struct snd_ac97 *ac97, const unsigned int *list)
{
u32 subid = ((u32)ac97->subsystem_vendor << 16) | ac97->subsystem_device;
for (; *list; list++)
if (*list == subid)
return 1;
return 0;
}
static int patch_ad1981a_specific(struct snd_ac97 * ac97)
{
if (check_list(ac97, ad1981_jacks_blacklist))
return 0;
return patch_build_controls(ac97, snd_ac97_ad1981x_jack_sense,
ARRAY_SIZE(snd_ac97_ad1981x_jack_sense));
}
static void check_ad1981_hp_jack_sense(struct snd_ac97 *ac97)
{
if (check_list(ac97, ad1981_jacks_whitelist))
snd_ac97_update_bits(ac97, AC97_AD_JACK_SPDIF, 1<<11, 1<<11);
}
static int patch_ad1981a(struct snd_ac97 *ac97)
{
patch_ad1881(ac97);
ac97->build_ops = &patch_ad1981a_build_ops;
snd_ac97_update_bits(ac97, AC97_AD_MISC, AC97_AD198X_MSPLT, AC97_AD198X_MSPLT);
ac97->flags |= AC97_STEREO_MUTES;
check_ad1981_hp_jack_sense(ac97);
return 0;
}
static int patch_ad1981b_specific(struct snd_ac97 *ac97)
{
int err;
if ((err = patch_build_controls(ac97, &snd_ac97_ad198x_2cmic, 1)) < 0)
return err;
if (check_list(ac97, ad1981_jacks_blacklist))
return 0;
return patch_build_controls(ac97, snd_ac97_ad1981x_jack_sense,
ARRAY_SIZE(snd_ac97_ad1981x_jack_sense));
}
static int patch_ad1981b(struct snd_ac97 *ac97)
{
patch_ad1881(ac97);
ac97->build_ops = &patch_ad1981b_build_ops;
snd_ac97_update_bits(ac97, AC97_AD_MISC, AC97_AD198X_MSPLT, AC97_AD198X_MSPLT);
ac97->flags |= AC97_STEREO_MUTES;
check_ad1981_hp_jack_sense(ac97);
return 0;
}
static int snd_ac97_ad1888_lohpsel_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_AD_MISC];
ucontrol->value.integer.value[0] = !(val & AC97_AD198X_LOSEL);
if (ac97->spec.ad18xx.lo_as_master)
ucontrol->value.integer.value[0] =
!ucontrol->value.integer.value[0];
return 0;
}
static int snd_ac97_ad1888_lohpsel_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = !ucontrol->value.integer.value[0];
if (ac97->spec.ad18xx.lo_as_master)
val = !val;
val = val ? (AC97_AD198X_LOSEL | AC97_AD198X_HPSEL) : 0;
return snd_ac97_update_bits(ac97, AC97_AD_MISC,
AC97_AD198X_LOSEL | AC97_AD198X_HPSEL, val);
}
static int snd_ac97_ad1888_downmix_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[3] = {"Off", "6 -> 4", "6 -> 2"};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 3;
if (uinfo->value.enumerated.item > 2)
uinfo->value.enumerated.item = 2;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_ad1888_downmix_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_AD_MISC];
if (!(val & AC97_AD198X_DMIX1))
ucontrol->value.enumerated.item[0] = 0;
else
ucontrol->value.enumerated.item[0] = 1 + ((val >> 8) & 1);
return 0;
}
static int snd_ac97_ad1888_downmix_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
if (ucontrol->value.enumerated.item[0] > 2)
return -EINVAL;
if (ucontrol->value.enumerated.item[0] == 0)
val = 0;
else
val = AC97_AD198X_DMIX1 |
((ucontrol->value.enumerated.item[0] - 1) << 8);
return snd_ac97_update_bits(ac97, AC97_AD_MISC,
AC97_AD198X_DMIX0 | AC97_AD198X_DMIX1, val);
}
static void ad1888_update_jacks(struct snd_ac97 *ac97)
{
unsigned short val = 0;
if (!ac97->spec.ad18xx.lo_as_master && is_shared_linein(ac97))
val |= (1 << 12);
if (is_shared_micin(ac97))
val |= (1 << 11);
snd_ac97_update_bits(ac97, AC97_AD_MISC, (1 << 11) | (1 << 12), val);
}
static int patch_ad1888_specific(struct snd_ac97 *ac97)
{
if (!ac97->spec.ad18xx.lo_as_master) {
snd_ac97_rename_vol_ctl(ac97, "Master Playback",
"Master Surround Playback");
snd_ac97_rename_vol_ctl(ac97, "Headphone Playback",
"Master Playback");
}
return patch_build_controls(ac97, snd_ac97_ad1888_controls, ARRAY_SIZE(snd_ac97_ad1888_controls));
}
static int patch_ad1888(struct snd_ac97 * ac97)
{
unsigned short misc;
patch_ad1881(ac97);
ac97->build_ops = &patch_ad1888_build_ops;
if (ac97->subsystem_vendor == 0x1043 &&
ac97->subsystem_device == 0x1193)
ac97->spec.ad18xx.lo_as_master = 1;
misc = snd_ac97_read(ac97, AC97_AD_MISC);
misc |= AC97_AD198X_MSPLT | AC97_AD198X_AC97NC;
if (!ac97->spec.ad18xx.lo_as_master)
misc |= AC97_AD198X_LOSEL | AC97_AD198X_HPSEL;
snd_ac97_write_cache(ac97, AC97_AD_MISC, misc);
ac97->flags |= AC97_STEREO_MUTES;
return 0;
}
static int patch_ad1980_specific(struct snd_ac97 *ac97)
{
int err;
if ((err = patch_ad1888_specific(ac97)) < 0)
return err;
return patch_build_controls(ac97, &snd_ac97_ad198x_2cmic, 1);
}
static int patch_ad1980(struct snd_ac97 * ac97)
{
patch_ad1888(ac97);
ac97->build_ops = &patch_ad1980_build_ops;
return 0;
}
static int snd_ac97_ad1985_vrefout_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[4] = {"High-Z", "3.7 V", "2.25 V", "0 V"};
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 4;
if (uinfo->value.enumerated.item > 3)
uinfo->value.enumerated.item = 3;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_ad1985_vrefout_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
static const int reg2ctrl[4] = {2, 0, 1, 3};
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = (ac97->regs[AC97_AD_MISC] & AC97_AD198X_VREF_MASK)
>> AC97_AD198X_VREF_SHIFT;
ucontrol->value.enumerated.item[0] = reg2ctrl[val];
return 0;
}
static int snd_ac97_ad1985_vrefout_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
static const int ctrl2reg[4] = {1, 2, 0, 3};
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
if (ucontrol->value.enumerated.item[0] > 3)
return -EINVAL;
val = ctrl2reg[ucontrol->value.enumerated.item[0]]
<< AC97_AD198X_VREF_SHIFT;
return snd_ac97_update_bits(ac97, AC97_AD_MISC,
AC97_AD198X_VREF_MASK, val);
}
static void ad1985_update_jacks(struct snd_ac97 *ac97)
{
ad1888_update_jacks(ac97);
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG, 1 << 9,
is_shared_micin(ac97) ? 1 << 9 : 0);
}
static int patch_ad1985_specific(struct snd_ac97 *ac97)
{
int err;
snd_ac97_rename_vol_ctl(ac97, "Master Playback",
"Master Surround Playback");
snd_ac97_rename_vol_ctl(ac97, "Headphone Playback", "Master Playback");
if ((err = patch_build_controls(ac97, &snd_ac97_ad198x_2cmic, 1)) < 0)
return err;
return patch_build_controls(ac97, snd_ac97_ad1985_controls,
ARRAY_SIZE(snd_ac97_ad1985_controls));
}
static int patch_ad1985(struct snd_ac97 * ac97)
{
unsigned short misc;
patch_ad1881(ac97);
ac97->build_ops = &patch_ad1985_build_ops;
misc = snd_ac97_read(ac97, AC97_AD_MISC);
snd_ac97_write_cache(ac97, AC97_AD_MISC, misc |
AC97_AD198X_LOSEL |
AC97_AD198X_HPSEL |
AC97_AD198X_MSPLT |
AC97_AD198X_AC97NC);
ac97->flags |= AC97_STEREO_MUTES;
ad1985_update_jacks(ac97);
ac97->ext_id = (ac97->ext_id & ~AC97_EI_REV_MASK) | AC97_EI_REV_23;
return 0;
}
static int snd_ac97_ad1986_lososel_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_AD_MISC3];
ucontrol->value.integer.value[0] = (val & AC97_AD1986_LOSEL) != 0;
return 0;
}
static int snd_ac97_ad1986_lososel_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
int ret0;
int ret1;
int sprd = (ac97->regs[AC97_AD_MISC] & AC97_AD1986_SPRD) != 0;
ret0 = snd_ac97_update_bits(ac97, AC97_AD_MISC3, AC97_AD1986_LOSEL,
ucontrol->value.integer.value[0] != 0
? AC97_AD1986_LOSEL : 0);
if (ret0 < 0)
return ret0;
ret1 = snd_ac97_update_bits(ac97, AC97_AD_MISC, AC97_AD1986_SOSEL,
(ucontrol->value.integer.value[0] != 0
|| sprd)
? AC97_AD1986_SOSEL : 0);
if (ret1 < 0)
return ret1;
return (ret0 > 0 || ret1 > 0) ? 1 : 0;
}
static int snd_ac97_ad1986_spread_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_AD_MISC];
ucontrol->value.integer.value[0] = (val & AC97_AD1986_SPRD) != 0;
return 0;
}
static int snd_ac97_ad1986_spread_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
int ret0;
int ret1;
int sprd = (ac97->regs[AC97_AD_MISC3] & AC97_AD1986_LOSEL) != 0;
ret0 = snd_ac97_update_bits(ac97, AC97_AD_MISC, AC97_AD1986_SPRD,
ucontrol->value.integer.value[0] != 0
? AC97_AD1986_SPRD : 0);
if (ret0 < 0)
return ret0;
ret1 = snd_ac97_update_bits(ac97, AC97_AD_MISC, AC97_AD1986_SOSEL,
(ucontrol->value.integer.value[0] != 0
|| sprd)
? AC97_AD1986_SOSEL : 0);
if (ret1 < 0)
return ret1;
return (ret0 > 0 || ret1 > 0) ? 1 : 0;
}
static int snd_ac97_ad1986_miclisel_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = ac97->spec.ad18xx.swap_mic_linein;
return 0;
}
static int snd_ac97_ad1986_miclisel_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned char swap = ucontrol->value.integer.value[0] != 0;
if (swap != ac97->spec.ad18xx.swap_mic_linein) {
ac97->spec.ad18xx.swap_mic_linein = swap;
if (ac97->build_ops->update_jacks)
ac97->build_ops->update_jacks(ac97);
return 1;
}
return 0;
}
static int snd_ac97_ad1986_vrefout_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
unsigned short reg = ac97->regs[AC97_AD_MISC2];
if ((reg & AC97_AD1986_MVREF0) != 0)
val = 2;
else if ((reg & AC97_AD1986_MVREF1) != 0)
val = 3;
else if ((reg & AC97_AD1986_MVREF2) != 0)
val = 1;
else
val = 0;
ucontrol->value.enumerated.item[0] = val;
return 0;
}
static int snd_ac97_ad1986_vrefout_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short cval;
unsigned short lval;
unsigned short mval;
int cret;
int lret;
int mret;
switch (ucontrol->value.enumerated.item[0])
{
case 0:
cval = 0;
lval = 0;
mval = 0;
break;
case 1:
cval = AC97_AD1986_CVREF2;
lval = AC97_AD1986_LVREF2;
mval = AC97_AD1986_MVREF2;
break;
case 2:
cval = AC97_AD1986_CVREF0;
lval = AC97_AD1986_LVREF0;
mval = AC97_AD1986_MVREF0;
break;
case 3:
cval = AC97_AD1986_CVREF1;
lval = AC97_AD1986_LVREF1;
mval = AC97_AD1986_MVREF1;
break;
default:
return -EINVAL;
}
cret = snd_ac97_update_bits(ac97, AC97_AD_MISC2,
AC97_AD1986_CVREF_MASK, cval);
if (cret < 0)
return cret;
lret = snd_ac97_update_bits(ac97, AC97_AD_MISC3,
AC97_AD1986_LVREF_MASK, lval);
if (lret < 0)
return lret;
mret = snd_ac97_update_bits(ac97, AC97_AD_MISC2,
AC97_AD1986_MVREF_MASK, mval);
if (mret < 0)
return mret;
return (cret > 0 || lret > 0 || mret > 0) ? 1 : 0;
}
static void ad1986_update_jacks(struct snd_ac97 *ac97)
{
unsigned short misc_val = 0;
unsigned short ser_val;
if (!is_surround_on(ac97))
misc_val |= AC97_AD1986_SODIS;
if (!is_clfe_on(ac97))
misc_val |= AC97_AD1986_CLDIS;
if (is_shared_linein(ac97))
misc_val |= AC97_AD1986_LISEL_SURR;
else if (ac97->spec.ad18xx.swap_mic_linein != 0)
misc_val |= AC97_AD1986_LISEL_MIC;
snd_ac97_update_bits(ac97, AC97_AD_MISC,
AC97_AD1986_SODIS | AC97_AD1986_CLDIS |
AC97_AD1986_LISEL_MASK,
misc_val);
if (is_shared_micin(ac97))
ser_val = AC97_AD1986_OMS_C;
else if (ac97->spec.ad18xx.swap_mic_linein != 0)
ser_val = AC97_AD1986_OMS_L;
else
ser_val = AC97_AD1986_OMS_M;
snd_ac97_update_bits(ac97, AC97_AD_SERIAL_CFG,
AC97_AD1986_OMS_MASK,
ser_val);
}
static int patch_ad1986_specific(struct snd_ac97 *ac97)
{
int err;
if ((err = patch_build_controls(ac97, &snd_ac97_ad198x_2cmic, 1)) < 0)
return err;
return patch_build_controls(ac97, snd_ac97_ad1986_controls,
ARRAY_SIZE(snd_ac97_ad1985_controls));
}
static int patch_ad1986(struct snd_ac97 * ac97)
{
patch_ad1881(ac97);
ac97->build_ops = &patch_ad1986_build_ops;
ac97->flags |= AC97_STEREO_MUTES;
ad1986_update_jacks(ac97);
return 0;
}
static int patch_alc203(struct snd_ac97 *ac97)
{
snd_ac97_update_bits(ac97, 0x7a, 0x400, 0x400);
return 0;
}
static void alc650_update_jacks(struct snd_ac97 *ac97)
{
int shared;
shared = is_shared_surrout(ac97);
snd_ac97_update_bits(ac97, AC97_ALC650_MULTICH, 1 << 9,
shared ? (1 << 9) : 0);
shared = is_shared_clfeout(ac97);
snd_ac97_update_bits(ac97, AC97_ALC650_CLOCK, 1 << 12,
shared ? (1 << 12) : 0);
snd_ac97_update_bits(ac97, AC97_ALC650_MULTICH, 1 << 10,
shared ? (1 << 10) : 0);
snd_ac97_update_bits(ac97, AC97_ALC650_GPIO_STATUS, 0x100,
shared ? 0 : 0x100);
}
static int alc650_swap_surround_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
struct snd_pcm_chmap *map = ac97->chmaps[SNDRV_PCM_STREAM_PLAYBACK];
if (map) {
if (ucontrol->value.integer.value[0])
map->chmap = snd_pcm_std_chmaps;
else
map->chmap = snd_pcm_alt_chmaps;
}
return snd_ac97_put_volsw(kcontrol, ucontrol);
}
static int patch_alc650_specific(struct snd_ac97 * ac97)
{
int err;
if ((err = patch_build_controls(ac97, snd_ac97_controls_alc650, ARRAY_SIZE(snd_ac97_controls_alc650))) < 0)
return err;
if (ac97->ext_id & AC97_EI_SPDIF) {
if ((err = patch_build_controls(ac97, snd_ac97_spdif_controls_alc650, ARRAY_SIZE(snd_ac97_spdif_controls_alc650))) < 0)
return err;
}
if (ac97->id != AC97_ID_ALC650F)
reset_tlv(ac97, "Master Playback Volume",
db_scale_5bit_3db_max);
return 0;
}
static int patch_alc650(struct snd_ac97 * ac97)
{
unsigned short val;
ac97->build_ops = &patch_alc650_ops;
val = snd_ac97_read(ac97, AC97_ALC650_REVISION) & 0x3f;
if (val < 3)
ac97->id = 0x414c4720;
else if (val < 0x10)
ac97->id = 0x414c4721;
else if (val < 0x20)
ac97->id = 0x414c4722;
else if (val < 0x30)
ac97->id = 0x414c4723;
ac97->spec.dev_flags = (ac97->id == 0x414c4722 ||
ac97->id == 0x414c4723);
snd_ac97_write_cache(ac97, AC97_ALC650_GPIO_STATUS,
snd_ac97_read(ac97, AC97_ALC650_GPIO_STATUS) | 0x8000);
val = snd_ac97_read(ac97, AC97_ALC650_CLOCK);
if (ac97->spec.dev_flags &&
! (ac97->subsystem_vendor == 0x1043 &&
ac97->subsystem_device == 0x1103))
val |= 0x03;
else
val &= ~0x03;
snd_ac97_write_cache(ac97, AC97_ALC650_CLOCK, val);
snd_ac97_write_cache(ac97, AC97_ALC650_MULTICH, 0);
snd_ac97_write_cache(ac97, AC97_ALC650_GPIO_SETUP,
snd_ac97_read(ac97, AC97_ALC650_GPIO_SETUP) | 0x01);
snd_ac97_write_cache(ac97, AC97_ALC650_GPIO_STATUS,
(snd_ac97_read(ac97, AC97_ALC650_GPIO_STATUS) | 0x100) & ~0x10);
snd_ac97_write_cache(ac97, AC97_ALC650_SURR_DAC_VOL, 0x0808);
snd_ac97_write_cache(ac97, AC97_ALC650_LFE_DAC_VOL, 0x0808);
return 0;
}
static void alc655_update_jacks(struct snd_ac97 *ac97)
{
int shared;
shared = is_shared_surrout(ac97);
ac97_update_bits_page(ac97, AC97_ALC650_MULTICH, 1 << 9,
shared ? (1 << 9) : 0, 0);
shared = is_shared_clfeout(ac97);
snd_ac97_update_bits(ac97, AC97_ALC650_CLOCK, 1 << 12,
shared ? (1 << 12) : 0);
ac97_update_bits_page(ac97, AC97_ALC650_MULTICH, 1 << 10,
shared ? (1 << 10) : 0, 0);
}
static int alc655_iec958_route_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts_655[3] = { "PCM", "Analog In", "IEC958 In" };
static char *texts_658[4] = { "PCM", "Analog1 In", "Analog2 In", "IEC958 In" };
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = ac97->spec.dev_flags ? 4 : 3;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item = uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name,
ac97->spec.dev_flags ?
texts_658[uinfo->value.enumerated.item] :
texts_655[uinfo->value.enumerated.item]);
return 0;
}
static int alc655_iec958_route_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_ALC650_MULTICH];
val = (val >> 12) & 3;
if (ac97->spec.dev_flags && val == 3)
val = 0;
ucontrol->value.enumerated.item[0] = val;
return 0;
}
static int alc655_iec958_route_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
return ac97_update_bits_page(ac97, AC97_ALC650_MULTICH, 3 << 12,
(unsigned short)ucontrol->value.enumerated.item[0] << 12,
0);
}
static int patch_alc655_specific(struct snd_ac97 * ac97)
{
int err;
if ((err = patch_build_controls(ac97, snd_ac97_controls_alc655, ARRAY_SIZE(snd_ac97_controls_alc655))) < 0)
return err;
if (ac97->ext_id & AC97_EI_SPDIF) {
if ((err = patch_build_controls(ac97, snd_ac97_spdif_controls_alc655, ARRAY_SIZE(snd_ac97_spdif_controls_alc655))) < 0)
return err;
}
return 0;
}
static int patch_alc655(struct snd_ac97 * ac97)
{
unsigned int val;
if (ac97->id == AC97_ID_ALC658) {
ac97->spec.dev_flags = 1;
if ((snd_ac97_read(ac97, AC97_ALC650_REVISION) & 0x3f) == 2) {
ac97->id = AC97_ID_ALC658D;
ac97->spec.dev_flags = 2;
}
}
ac97->build_ops = &patch_alc655_ops;
snd_ac97_update_bits(ac97, AC97_INT_PAGING, AC97_PAGE_MASK, AC97_PAGE_VENDOR);
val = snd_ac97_read(ac97, 0x7a);
if (ac97->spec.dev_flags)
val &= ~(1 << 1);
else {
if (ac97->subsystem_vendor == 0x1462 &&
(ac97->subsystem_device == 0x0131 ||
ac97->subsystem_device == 0x0161 ||
ac97->subsystem_device == 0x0351 ||
ac97->subsystem_device == 0x0471 ||
ac97->subsystem_device == 0x0061))
val &= ~(1 << 1);
else
val |= (1 << 1);
ac97->ext_id |= AC97_EI_SPDIF;
}
val &= ~(1 << 12);
snd_ac97_write_cache(ac97, 0x7a, val);
snd_ac97_write_cache(ac97, AC97_ALC650_MULTICH, 1<<15);
snd_ac97_write_cache(ac97, AC97_ALC650_SURR_DAC_VOL, 0x0808);
snd_ac97_write_cache(ac97, AC97_ALC650_LFE_DAC_VOL, 0x0808);
if (ac97->id == AC97_ID_ALC658D)
snd_ac97_update_bits(ac97, 0x74, 0x0800, 0x0800);
return 0;
}
static void alc850_update_jacks(struct snd_ac97 *ac97)
{
int shared;
int aux_is_back_surround;
shared = is_shared_surrout(ac97);
snd_ac97_update_bits(ac97, AC97_ALC850_MISC1, (1<<4)|(1<<5),
shared ? (1<<5) : (1<<4));
snd_ac97_update_bits(ac97, AC97_ALC850_JACK_SELECT, 7 << 12,
shared ? (2<<12) : (0<<12));
shared = is_shared_clfeout(ac97);
snd_ac97_update_bits(ac97, AC97_ALC850_MISC1, (1<<12)|(1<<13),
shared ? (1<<12) : (1<<13));
snd_ac97_update_bits(ac97, AC97_ALC850_JACK_SELECT, 7 << 4,
shared ? (5<<4) : (1<<4));
aux_is_back_surround = alc850_is_aux_back_surround(ac97);
snd_ac97_update_bits(ac97, AC97_ALC850_MULTICH, 1 << 10,
aux_is_back_surround ? (1<<10) : (0<<10));
}
static int patch_alc850_specific(struct snd_ac97 *ac97)
{
int err;
if ((err = patch_build_controls(ac97, snd_ac97_controls_alc850, ARRAY_SIZE(snd_ac97_controls_alc850))) < 0)
return err;
if (ac97->ext_id & AC97_EI_SPDIF) {
if ((err = patch_build_controls(ac97, snd_ac97_spdif_controls_alc655, ARRAY_SIZE(snd_ac97_spdif_controls_alc655))) < 0)
return err;
}
return 0;
}
static int patch_alc850(struct snd_ac97 *ac97)
{
ac97->build_ops = &patch_alc850_ops;
ac97->spec.dev_flags = 0;
ac97->flags |= AC97_HAS_8CH;
snd_ac97_update_bits(ac97, AC97_INT_PAGING, AC97_PAGE_MASK, AC97_PAGE_VENDOR);
snd_ac97_write_cache(ac97, AC97_ALC650_MULTICH, 1<<15);
snd_ac97_write_cache(ac97, 0x7a, (1<<1)|(1<<4)|(0<<5)|(1<<6)|
(1<<7)|(0<<12)|(1<<13)|(0<<14));
snd_ac97_write_cache(ac97, 0x76, (0<<0)|(0<<2)|(1<<4)|(1<<7)|(2<<8)|
(1<<11)|(0<<12)|(1<<15));
snd_ac97_write_cache(ac97, AC97_ALC650_SURR_DAC_VOL, 0x0808);
snd_ac97_write_cache(ac97, AC97_ALC650_LFE_DAC_VOL, 0x0808);
return 0;
}
static int patch_aztech_azf3328_specific(struct snd_ac97 *ac97)
{
struct snd_kcontrol *kctl_3d_center =
snd_ac97_find_mixer_ctl(ac97, "3D Control - Center");
struct snd_kcontrol *kctl_3d_depth =
snd_ac97_find_mixer_ctl(ac97, "3D Control - Depth");
if (kctl_3d_center) {
kctl_3d_center->private_value =
AC97_SINGLE_VALUE(AC97_3D_CONTROL, 1, 0x07, 0);
snd_ac97_rename_vol_ctl(ac97,
"3D Control - Center", "3D Control - Width"
);
}
if (kctl_3d_depth)
kctl_3d_depth->private_value =
AC97_SINGLE_VALUE(AC97_3D_CONTROL, 8, 0x03, 0);
snd_ac97_rename_vol_ctl(ac97,
"Master Mono Playback", "Modem Playback"
);
snd_ac97_rename_vol_ctl(ac97,
"Headphone Playback", "FM Synth Playback"
);
return 0;
}
static int patch_aztech_azf3328(struct snd_ac97 *ac97)
{
ac97->build_ops = &patch_aztech_azf3328_ops;
return 0;
}
static void cm9738_update_jacks(struct snd_ac97 *ac97)
{
snd_ac97_update_bits(ac97, AC97_CM9738_VENDOR_CTRL, 1 << 10,
is_shared_surrout(ac97) ? (1 << 10) : 0);
}
static int patch_cm9738_specific(struct snd_ac97 * ac97)
{
return patch_build_controls(ac97, snd_ac97_cm9738_controls, ARRAY_SIZE(snd_ac97_cm9738_controls));
}
static int patch_cm9738(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_cm9738_ops;
ac97->flags |= AC97_HAS_NO_PCM_VOL;
snd_ac97_write_cache(ac97, AC97_PCM, 0x8000);
return 0;
}
static int snd_ac97_cmedia_spdif_playback_source_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[] = { "Analog", "Digital" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 2;
if (uinfo->value.enumerated.item > 1)
uinfo->value.enumerated.item = 1;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_ac97_cmedia_spdif_playback_source_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
unsigned short val;
val = ac97->regs[AC97_CM9739_SPDIF_CTRL];
ucontrol->value.enumerated.item[0] = (val >> 1) & 0x01;
return 0;
}
static int snd_ac97_cmedia_spdif_playback_source_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
return snd_ac97_update_bits(ac97, AC97_CM9739_SPDIF_CTRL,
0x01 << 1,
(ucontrol->value.enumerated.item[0] & 0x01) << 1);
}
static void cm9739_update_jacks(struct snd_ac97 *ac97)
{
snd_ac97_update_bits(ac97, AC97_CM9739_MULTI_CHAN, 1 << 10,
is_shared_surrout(ac97) ? (1 << 10) : 0);
snd_ac97_update_bits(ac97, AC97_CM9739_MULTI_CHAN, 0x3000,
is_shared_clfeout(ac97) ? 0x1000 : 0x2000);
}
static int patch_cm9739_specific(struct snd_ac97 * ac97)
{
return patch_build_controls(ac97, snd_ac97_cm9739_controls, ARRAY_SIZE(snd_ac97_cm9739_controls));
}
static int patch_cm9739_post_spdif(struct snd_ac97 * ac97)
{
return patch_build_controls(ac97, snd_ac97_cm9739_controls_spdif, ARRAY_SIZE(snd_ac97_cm9739_controls_spdif));
}
static int patch_cm9739(struct snd_ac97 * ac97)
{
unsigned short val;
ac97->build_ops = &patch_cm9739_ops;
ac97->flags |= AC97_HAS_NO_MASTER_VOL | AC97_HAS_NO_PCM_VOL;
snd_ac97_write_cache(ac97, AC97_MASTER, 0x8000);
snd_ac97_write_cache(ac97, AC97_PCM, 0x8000);
val = snd_ac97_read(ac97, AC97_EXTENDED_STATUS);
if (val & AC97_EA_SPCV) {
snd_ac97_write_cache(ac97, AC97_CM9739_SPDIF_CTRL,
snd_ac97_read(ac97, AC97_CM9739_SPDIF_CTRL) | 0x01);
ac97->rates[AC97_RATES_SPDIF] = SNDRV_PCM_RATE_48000;
} else {
ac97->ext_id &= ~AC97_EI_SPDIF;
ac97->rates[AC97_RATES_SPDIF] = 0;
}
val = snd_ac97_read(ac97, AC97_CM9739_MULTI_CHAN) & (1 << 4);
val |= (1 << 3);
val |= (1 << 13);
if (! (ac97->ext_id & AC97_EI_SPDIF))
val |= (1 << 14);
snd_ac97_write_cache(ac97, AC97_CM9739_MULTI_CHAN, val);
snd_ac97_write_cache(ac97, 0x70, 0x0100);
snd_ac97_write_cache(ac97, 0x72, 0x0020);
if (ac97->pci &&
ac97->subsystem_vendor == 0x1043 &&
ac97->subsystem_device == 0x1843) {
snd_ac97_write_cache(ac97, AC97_CM9739_SPDIF_CTRL,
snd_ac97_read(ac97, AC97_CM9739_SPDIF_CTRL) & ~0x01);
snd_ac97_write_cache(ac97, AC97_CM9739_MULTI_CHAN,
snd_ac97_read(ac97, AC97_CM9739_MULTI_CHAN) | (1 << 14));
}
return 0;
}
static void cm9761_update_jacks(struct snd_ac97 *ac97)
{
static unsigned short surr_on[3][2] = {
{ 0x0008, 0x0000 },
{ 0x0000, 0x0008 },
{ 0x0000, 0x0008 },
};
static unsigned short clfe_on[3][2] = {
{ 0x0000, 0x1000 },
{ 0x1000, 0x0000 },
{ 0x0000, 0x1000 },
};
static unsigned short surr_shared[3][2] = {
{ 0x0000, 0x0400 },
{ 0x0000, 0x0400 },
{ 0x0000, 0x0400 },
};
static unsigned short clfe_shared[3][2] = {
{ 0x2000, 0x0880 },
{ 0x0000, 0x2880 },
{ 0x2000, 0x0800 },
};
unsigned short val = 0;
val |= surr_on[ac97->spec.dev_flags][is_surround_on(ac97)];
val |= clfe_on[ac97->spec.dev_flags][is_clfe_on(ac97)];
val |= surr_shared[ac97->spec.dev_flags][is_shared_surrout(ac97)];
val |= clfe_shared[ac97->spec.dev_flags][is_shared_clfeout(ac97)];
snd_ac97_update_bits(ac97, AC97_CM9761_MULTI_CHAN, 0x3c88, val);
}
static int cm9761_spdif_out_source_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
static char *texts[] = { "AC-Link", "ADC", "SPDIF-In" };
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 3;
if (uinfo->value.enumerated.item > 2)
uinfo->value.enumerated.item = 2;
strcpy(uinfo->value.enumerated.name, texts[uinfo->value.enumerated.item]);
return 0;
}
static int cm9761_spdif_out_source_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
if (ac97->regs[AC97_CM9761_FUNC] & 0x1)
ucontrol->value.enumerated.item[0] = 2;
else if (ac97->regs[AC97_CM9761_SPDIF_CTRL] & 0x2)
ucontrol->value.enumerated.item[0] = 1;
else
ucontrol->value.enumerated.item[0] = 0;
return 0;
}
static int cm9761_spdif_out_source_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_ac97 *ac97 = snd_kcontrol_chip(kcontrol);
if (ucontrol->value.enumerated.item[0] == 2)
return snd_ac97_update_bits(ac97, AC97_CM9761_FUNC, 0x1, 0x1);
snd_ac97_update_bits(ac97, AC97_CM9761_FUNC, 0x1, 0);
return snd_ac97_update_bits(ac97, AC97_CM9761_SPDIF_CTRL, 0x2,
ucontrol->value.enumerated.item[0] == 1 ? 0x2 : 0);
}
static int patch_cm9761_post_spdif(struct snd_ac97 * ac97)
{
return patch_build_controls(ac97, snd_ac97_cm9761_controls_spdif, ARRAY_SIZE(snd_ac97_cm9761_controls_spdif));
}
static int patch_cm9761_specific(struct snd_ac97 * ac97)
{
return patch_build_controls(ac97, snd_ac97_cm9761_controls, ARRAY_SIZE(snd_ac97_cm9761_controls));
}
static int patch_cm9761(struct snd_ac97 *ac97)
{
unsigned short val;
ac97->flags |= AC97_HAS_NO_PCM_VOL;
snd_ac97_write_cache(ac97, AC97_MASTER, 0x8808);
snd_ac97_write_cache(ac97, AC97_PCM, 0x8808);
ac97->spec.dev_flags = 0;
if (ac97->id == AC97_ID_CM9761_82) {
unsigned short tmp;
val = snd_ac97_read(ac97, AC97_INT_PAGING);
snd_ac97_write_cache(ac97, AC97_INT_PAGING, (val & ~0x0f) | 0x01);
tmp = snd_ac97_read(ac97, 0x60);
ac97->spec.dev_flags = tmp & 1;
snd_ac97_write_cache(ac97, AC97_INT_PAGING, val);
} else if (ac97->id == AC97_ID_CM9761_83)
ac97->spec.dev_flags = 2;
ac97->build_ops = &patch_cm9761_ops;
ac97->ext_id |= AC97_EI_SPDIF;
snd_ac97_write_cache(ac97, AC97_EXTENDED_STATUS, 0x05c0);
snd_ac97_write_cache(ac97, AC97_CM9761_SPDIF_CTRL, 0x0001);
ac97->rates[AC97_RATES_SPDIF] = SNDRV_PCM_RATE_48000;
#if 0
if (ac97->spec.dev_flags)
val = 0x0214;
else
val = 0x321c;
#endif
val = snd_ac97_read(ac97, AC97_CM9761_MULTI_CHAN);
val |= (1 << 4);
snd_ac97_write_cache(ac97, AC97_CM9761_MULTI_CHAN, val);
snd_ac97_write_cache(ac97, 0x70, 0x0100);
snd_ac97_write_cache(ac97, 0x72, 0x0020);
return 0;
}
static int patch_cm9780_specific(struct snd_ac97 *ac97)
{
return patch_build_controls(ac97, cm9780_controls, ARRAY_SIZE(cm9780_controls));
}
static int patch_cm9780(struct snd_ac97 *ac97)
{
unsigned short val;
ac97->build_ops = &patch_cm9780_ops;
if (ac97->ext_id & AC97_EI_SPDIF) {
ac97->rates[AC97_RATES_SPDIF] = SNDRV_PCM_RATE_48000;
val = snd_ac97_read(ac97, AC97_CM9780_SPDIF);
val |= 0x1;
snd_ac97_write_cache(ac97, AC97_CM9780_SPDIF, val);
}
return 0;
}
static struct snd_kcontrol *snd_ac97_find_mixer_ctl(struct snd_ac97 *ac97,
const char *name)
{
struct snd_ctl_elem_id id;
memset(&id, 0, sizeof(id));
id.iface = SNDRV_CTL_ELEM_IFACE_MIXER;
strcpy(id.name, name);
return snd_ctl_find_id(ac97->bus->card, &id);
}
static int snd_ac97_add_vmaster(struct snd_ac97 *ac97, char *name,
const unsigned int *tlv, const char **slaves)
{
struct snd_kcontrol *kctl;
const char **s;
int err;
kctl = snd_ctl_make_virtual_master(name, tlv);
if (!kctl)
return -ENOMEM;
err = snd_ctl_add(ac97->bus->card, kctl);
if (err < 0)
return err;
for (s = slaves; *s; s++) {
struct snd_kcontrol *sctl;
sctl = snd_ac97_find_mixer_ctl(ac97, *s);
if (!sctl) {
snd_printdd("Cannot find slave %s, skipped\n", *s);
continue;
}
err = snd_ctl_add_slave(kctl, sctl);
if (err < 0)
return err;
}
return 0;
}
static int patch_vt1616_specific(struct snd_ac97 * ac97)
{
struct snd_kcontrol *kctl;
int err;
if (snd_ac97_try_bit(ac97, 0x5a, 9))
if ((err = patch_build_controls(ac97, &snd_ac97_controls_vt1616[0], 1)) < 0)
return err;
if ((err = patch_build_controls(ac97, &snd_ac97_controls_vt1616[1], ARRAY_SIZE(snd_ac97_controls_vt1616) - 1)) < 0)
return err;
kctl = snd_ac97_find_mixer_ctl(ac97, "Master Playback Volume");
if (!kctl)
return -EINVAL;
snd_ac97_rename_vol_ctl(ac97, "Master Playback", "Front Playback");
err = snd_ac97_add_vmaster(ac97, "Master Playback Volume",
kctl->tlv.p, slave_vols_vt1616);
if (err < 0)
return err;
err = snd_ac97_add_vmaster(ac97, "Master Playback Switch",
NULL, slave_sws_vt1616);
if (err < 0)
return err;
return 0;
}
static int patch_vt1616(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_vt1616_ops;
return 0;
}
static int snd_ac97_vt1617a_smart51_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char* texts[] = { "LineIn Mic1", "LineIn Mic1 Mic3",
"Surr LFE/C Mic3", "LineIn LFE/C Mic3",
"LineIn Mic2", "LineIn Mic2 Mic1",
"Surr LFE Mic1", "Surr LFE Mic1 Mic2"};
return ac97_enum_text_info(kcontrol, uinfo, texts, 8);
}
static int snd_ac97_vt1617a_smart51_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ushort usSM51, usMS;
struct snd_ac97 *pac97;
pac97 = snd_kcontrol_chip(kcontrol);
usSM51 = snd_ac97_read(pac97, 0x7a) >> 14;
usMS = snd_ac97_read(pac97, 0x20) >> 8;
ucontrol->value.enumerated.item[0] = (usSM51 << 1) + usMS;
return 0;
}
static int snd_ac97_vt1617a_smart51_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ushort usSM51, usMS, usReg;
struct snd_ac97 *pac97;
pac97 = snd_kcontrol_chip(kcontrol);
usSM51 = ucontrol->value.enumerated.item[0] >> 1;
usMS = ucontrol->value.enumerated.item[0] & 1;
usReg = snd_ac97_read(pac97, 0x7a);
snd_ac97_write_cache(pac97, 0x7a, (usReg & 0x3FFF) + (usSM51 << 14));
usReg = snd_ac97_read(pac97, 0x20);
snd_ac97_write_cache(pac97, 0x20, (usReg & 0xFEFF) + (usMS << 8));
return 0;
}
static int patch_vt1617a(struct snd_ac97 * ac97)
{
int err = 0;
int val;
err = patch_build_controls(ac97, &snd_ac97_controls_vt1617a[0],
ARRAY_SIZE(snd_ac97_controls_vt1617a));
val = snd_ac97_read(ac97, 0x5c);
if (!(val & 0x20))
snd_ac97_write_cache(ac97, 0x5c, 0x20);
ac97->ext_id |= AC97_EI_SPDIF;
ac97->rates[AC97_RATES_SPDIF] = SNDRV_PCM_RATE_44100 | SNDRV_PCM_RATE_48000;
ac97->build_ops = &patch_vt1616_ops;
return err;
}
static int snd_ac97_vt1618_UAJ_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
return ac97_enum_text_info(kcontrol, uinfo,
vt1618_uaj[kcontrol->private_value].items,
4);
}
static int snd_ac97_vt1618_UAJ_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
unsigned short datpag, uaj;
struct snd_ac97 *pac97 = snd_kcontrol_chip(kcontrol);
mutex_lock(&pac97->page_mutex);
datpag = snd_ac97_read(pac97, AC97_INT_PAGING) & AC97_PAGE_MASK;
snd_ac97_update_bits(pac97, AC97_INT_PAGING, AC97_PAGE_MASK, 0);
uaj = snd_ac97_read(pac97, 0x60) &
vt1618_uaj[kcontrol->private_value].mask;
snd_ac97_update_bits(pac97, AC97_INT_PAGING, AC97_PAGE_MASK, datpag);
mutex_unlock(&pac97->page_mutex);
ucontrol->value.enumerated.item[0] = uaj >>
vt1618_uaj[kcontrol->private_value].shift;
return 0;
}
static int snd_ac97_vt1618_UAJ_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
return ac97_update_bits_page(snd_kcontrol_chip(kcontrol), 0x60,
vt1618_uaj[kcontrol->private_value].mask,
ucontrol->value.enumerated.item[0]<<
vt1618_uaj[kcontrol->private_value].shift,
0);
}
static int snd_ac97_vt1618_aux_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *txt_aux[] = {"Aux In", "Back Surr Out"};
return ac97_enum_text_info(kcontrol, uinfo, txt_aux, 2);
}
static int snd_ac97_vt1618_aux_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.enumerated.item[0] =
(snd_ac97_read(snd_kcontrol_chip(kcontrol), 0x5c) & 0x0008)>>3;
return 0;
}
static int snd_ac97_vt1618_aux_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
snd_ac97_update_bits(snd_kcontrol_chip(kcontrol), 0x5c, 0x0008,
ucontrol->value.enumerated.item[0] << 3);
return snd_ac97_update_bits(snd_kcontrol_chip(kcontrol), 0x76, 0x0008,
ucontrol->value.enumerated.item[0] << 3);
}
static int patch_vt1618(struct snd_ac97 *ac97)
{
return patch_build_controls(ac97, snd_ac97_controls_vt1618,
ARRAY_SIZE(snd_ac97_controls_vt1618));
}
static void it2646_update_jacks(struct snd_ac97 *ac97)
{
snd_ac97_update_bits(ac97, 0x76, 1 << 9,
is_shared_surrout(ac97) ? (1<<9) : 0);
snd_ac97_update_bits(ac97, 0x76, 1 << 10,
is_shared_clfeout(ac97) ? (1<<10) : 0);
}
static int patch_it2646_specific(struct snd_ac97 * ac97)
{
int err;
if ((err = patch_build_controls(ac97, snd_ac97_controls_it2646, ARRAY_SIZE(snd_ac97_controls_it2646))) < 0)
return err;
if ((err = patch_build_controls(ac97, snd_ac97_spdif_controls_it2646, ARRAY_SIZE(snd_ac97_spdif_controls_it2646))) < 0)
return err;
return 0;
}
static int patch_it2646(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_it2646_ops;
snd_ac97_write_cache(ac97, 0x5E, 0x0808);
snd_ac97_write_cache(ac97, 0x7A, 0x0808);
return 0;
}
static int patch_si3036_specific(struct snd_ac97 * ac97)
{
int idx, err;
for (idx = 0; idx < ARRAY_SIZE(snd_ac97_controls_si3036); idx++)
if ((err = snd_ctl_add(ac97->bus->card, snd_ctl_new1(&snd_ac97_controls_si3036[idx], ac97))) < 0)
return err;
return 0;
}
static int mpatch_si3036(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_si3036_ops;
snd_ac97_write_cache(ac97, 0x5c, 0xf210 );
snd_ac97_write_cache(ac97, 0x68, 0);
return 0;
}
static int patch_lm4550(struct snd_ac97 *ac97)
{
ac97->res_table = lm4550_restbl;
return 0;
}
static int patch_ucb1400_specific(struct snd_ac97 * ac97)
{
int idx, err;
for (idx = 0; idx < ARRAY_SIZE(snd_ac97_controls_ucb1400); idx++)
if ((err = snd_ctl_add(ac97->bus->card, snd_ctl_new1(&snd_ac97_controls_ucb1400[idx], ac97))) < 0)
return err;
return 0;
}
static int patch_ucb1400(struct snd_ac97 * ac97)
{
ac97->build_ops = &patch_ucb1400_ops;
snd_ac97_write_cache(ac97, 0x6a, 0x0050);
snd_ac97_write_cache(ac97, 0x6c, 0x0030);
return 0;
}
