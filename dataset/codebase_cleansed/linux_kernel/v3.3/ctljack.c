static int jack_detect_kctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = kcontrol->private_value;
return 0;
}
struct snd_kcontrol *
snd_kctl_jack_new(const char *name, int idx, void *private_data)
{
struct snd_kcontrol *kctl;
kctl = snd_ctl_new1(&jack_detect_kctl, private_data);
if (!kctl)
return NULL;
snprintf(kctl->id.name, sizeof(kctl->id.name), "%s Jack", name);
kctl->id.index = idx;
kctl->private_value = 0;
return kctl;
}
void snd_kctl_jack_report(struct snd_card *card,
struct snd_kcontrol *kctl, bool status)
{
if (kctl->private_value == status)
return;
kctl->private_value = status;
snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE, &kctl->id);
}
