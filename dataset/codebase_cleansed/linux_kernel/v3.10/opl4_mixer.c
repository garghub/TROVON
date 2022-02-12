static int snd_opl4_ctl_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 2;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 7;
return 0;
}
static int snd_opl4_ctl_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_opl4 *opl4 = snd_kcontrol_chip(kcontrol);
unsigned long flags;
u8 reg = kcontrol->private_value;
u8 value;
spin_lock_irqsave(&opl4->reg_lock, flags);
value = snd_opl4_read(opl4, reg);
spin_unlock_irqrestore(&opl4->reg_lock, flags);
ucontrol->value.integer.value[0] = 7 - (value & 7);
ucontrol->value.integer.value[1] = 7 - ((value >> 3) & 7);
return 0;
}
static int snd_opl4_ctl_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
struct snd_opl4 *opl4 = snd_kcontrol_chip(kcontrol);
unsigned long flags;
u8 reg = kcontrol->private_value;
u8 value, old_value;
value = (7 - (ucontrol->value.integer.value[0] & 7)) |
((7 - (ucontrol->value.integer.value[1] & 7)) << 3);
spin_lock_irqsave(&opl4->reg_lock, flags);
old_value = snd_opl4_read(opl4, reg);
snd_opl4_write(opl4, reg, value);
spin_unlock_irqrestore(&opl4->reg_lock, flags);
return value != old_value;
}
int snd_opl4_create_mixer(struct snd_opl4 *opl4)
{
struct snd_card *card = opl4->card;
int i, err;
strcat(card->mixername, ",OPL4");
for (i = 0; i < 2; ++i) {
err = snd_ctl_add(card, snd_ctl_new1(&snd_opl4_controls[i], opl4));
if (err < 0)
return err;
}
return 0;
}
