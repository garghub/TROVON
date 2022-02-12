static int jack_detect_kctl_get(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
ucontrol->value.integer.value[0] = kcontrol->private_value;
return 0;
}
static int get_available_index(struct snd_card *card, const char *name)
{
struct snd_ctl_elem_id sid;
memset(&sid, 0, sizeof(sid));
sid.index = 0;
sid.iface = SNDRV_CTL_ELEM_IFACE_CARD;
strlcpy(sid.name, name, sizeof(sid.name));
while (snd_ctl_find_id(card, &sid)) {
sid.index++;
sid.numid = 0;
}
return sid.index;
}
static void jack_kctl_name_gen(char *name, const char *src_name, int size)
{
size_t count = strlen(src_name);
bool need_cat = true;
if (count >= 5)
need_cat = strncmp(&src_name[count - 5], " Jack", 5) ? true : false;
snprintf(name, size, need_cat ? "%s Jack" : "%s", src_name);
}
struct snd_kcontrol *
snd_kctl_jack_new(const char *name, struct snd_card *card)
{
struct snd_kcontrol *kctl;
kctl = snd_ctl_new1(&jack_detect_kctl, NULL);
if (!kctl)
return NULL;
jack_kctl_name_gen(kctl->id.name, name, sizeof(kctl->id.name));
kctl->id.index = get_available_index(card, kctl->id.name);
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
