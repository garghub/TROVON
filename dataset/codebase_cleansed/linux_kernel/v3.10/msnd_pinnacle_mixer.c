static int snd_msndmix_info_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static char *texts[3] = {
"Analog", "MASS", "SPDIF",
};
struct snd_msnd *chip = snd_kcontrol_chip(kcontrol);
unsigned items = test_bit(F_HAVEDIGITAL, &chip->flags) ? 3 : 2;
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = items;
if (uinfo->value.enumerated.item >= items)
uinfo->value.enumerated.item = items - 1;
strcpy(uinfo->value.enumerated.name,
texts[uinfo->value.enumerated.item]);
return 0;
}
static int snd_msndmix_get_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_msnd *chip = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = 0;
if (chip->recsrc & MSND_MASK_SYNTH) {
ucontrol->value.enumerated.item[0] = 1;
} else if ((chip->recsrc & MSND_MASK_DIGITAL) &&
test_bit(F_HAVEDIGITAL, &chip->flags)) {
ucontrol->value.enumerated.item[0] = 2;
}
return 0;
}
static int snd_msndmix_set_mux(struct snd_msnd *chip, int val)
{
unsigned newrecsrc;
int change;
unsigned char msndbyte;
switch (val) {
case 0:
newrecsrc = MSND_MASK_IMIX;
msndbyte = HDEXAR_SET_ANA_IN;
break;
case 1:
newrecsrc = MSND_MASK_SYNTH;
msndbyte = HDEXAR_SET_SYNTH_IN;
break;
case 2:
newrecsrc = MSND_MASK_DIGITAL;
msndbyte = HDEXAR_SET_DAT_IN;
break;
default:
return -EINVAL;
}
change = newrecsrc != chip->recsrc;
if (change) {
change = 0;
if (!snd_msnd_send_word(chip, 0, 0, msndbyte))
if (!snd_msnd_send_dsp_cmd(chip, HDEX_AUX_REQ)) {
chip->recsrc = newrecsrc;
change = 1;
}
}
return change;
}
static int snd_msndmix_put_mux(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_msnd *msnd = snd_kcontrol_chip(kcontrol);
return snd_msndmix_set_mux(msnd, ucontrol->value.enumerated.item[0]);
}
static int snd_msndmix_volume_info(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 100;
return 0;
}
static int snd_msndmix_volume_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_msnd *msnd = snd_kcontrol_chip(kcontrol);
int addr = kcontrol->private_value;
unsigned long flags;
spin_lock_irqsave(&msnd->mixer_lock, flags);
ucontrol->value.integer.value[0] = msnd->left_levels[addr] * 100;
ucontrol->value.integer.value[0] /= 0xFFFF;
ucontrol->value.integer.value[1] = msnd->right_levels[addr] * 100;
ucontrol->value.integer.value[1] /= 0xFFFF;
spin_unlock_irqrestore(&msnd->mixer_lock, flags);
return 0;
}
static int snd_msndmix_set(struct snd_msnd *dev, int d, int left, int right)
{
int bLeft, bRight;
int wLeft, wRight;
int updatemaster = 0;
if (d >= LEVEL_ENTRIES)
return -EINVAL;
bLeft = left * 0xff / 100;
wLeft = left * 0xffff / 100;
bRight = right * 0xff / 100;
wRight = right * 0xffff / 100;
dev->left_levels[d] = wLeft;
dev->right_levels[d] = wRight;
switch (d) {
case MSND_MIXER_LINE:
writeb(bLeft, dev->SMA + SMA_bInPotPosLeft);
writeb(bRight, dev->SMA + SMA_bInPotPosRight);
if (snd_msnd_send_word(dev, 0, 0, HDEXAR_IN_SET_POTS) == 0)
snd_msnd_send_dsp_cmd(dev, HDEX_AUX_REQ);
break;
case MSND_MIXER_MIC:
if (dev->type == msndClassic)
return -EINVAL;
writeb(bLeft, dev->SMA + SMA_bMicPotPosLeft);
writeb(bRight, dev->SMA + SMA_bMicPotPosRight);
if (snd_msnd_send_word(dev, 0, 0, HDEXAR_MIC_SET_POTS) == 0)
snd_msnd_send_dsp_cmd(dev, HDEX_AUX_REQ);
break;
case MSND_MIXER_VOLUME:
writew(wLeft, dev->SMA + SMA_wCurrMastVolLeft);
writew(wRight, dev->SMA + SMA_wCurrMastVolRight);
case MSND_MIXER_AUX:
case MSND_MIXER_SYNTH:
case MSND_MIXER_PCM:
case MSND_MIXER_IMIX:
updatemaster = 1;
break;
default:
return -EINVAL;
}
if (updatemaster) {
update_volm(MSND_MIXER_PCM, wCurrPlayVol);
update_volm(MSND_MIXER_IMIX, wCurrInVol);
if (dev->type == msndPinnacle)
update_volm(MSND_MIXER_SYNTH, wCurrMHdrVol);
update_potm(MSND_MIXER_AUX, bAuxPotPos, HDEXAR_AUX_SET_POTS);
}
return 0;
}
static int snd_msndmix_volume_put(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct snd_msnd *msnd = snd_kcontrol_chip(kcontrol);
int change, addr = kcontrol->private_value;
int left, right;
unsigned long flags;
left = ucontrol->value.integer.value[0] % 101;
right = ucontrol->value.integer.value[1] % 101;
spin_lock_irqsave(&msnd->mixer_lock, flags);
change = msnd->left_levels[addr] != left
|| msnd->right_levels[addr] != right;
snd_msndmix_set(msnd, addr, left, right);
spin_unlock_irqrestore(&msnd->mixer_lock, flags);
return change;
}
int snd_msndmix_new(struct snd_card *card)
{
struct snd_msnd *chip = card->private_data;
unsigned int idx;
int err;
if (snd_BUG_ON(!chip))
return -EINVAL;
spin_lock_init(&chip->mixer_lock);
strcpy(card->mixername, "MSND Pinnacle Mixer");
for (idx = 0; idx < ARRAY_SIZE(snd_msnd_controls); idx++)
err = snd_ctl_add(card,
snd_ctl_new1(snd_msnd_controls + idx, chip));
if (err < 0)
return err;
return 0;
}
void snd_msndmix_setup(struct snd_msnd *dev)
{
update_pot(MSND_MIXER_LINE, bInPotPos, HDEXAR_IN_SET_POTS);
update_potm(MSND_MIXER_AUX, bAuxPotPos, HDEXAR_AUX_SET_POTS);
update_volm(MSND_MIXER_PCM, wCurrPlayVol);
update_volm(MSND_MIXER_IMIX, wCurrInVol);
if (dev->type == msndPinnacle) {
update_pot(MSND_MIXER_MIC, bMicPotPos, HDEXAR_MIC_SET_POTS);
update_volm(MSND_MIXER_SYNTH, wCurrMHdrVol);
}
}
int snd_msndmix_force_recsrc(struct snd_msnd *dev, int recsrc)
{
dev->recsrc = -1;
return snd_msndmix_set_mux(dev, recsrc);
}
