static int snd_jack_dev_disconnect(struct snd_device *device)
{
struct snd_jack *jack = device->device_data;
if (!jack->input_dev)
return 0;
if (jack->registered)
input_unregister_device(jack->input_dev);
else
input_free_device(jack->input_dev);
jack->input_dev = NULL;
return 0;
}
static int snd_jack_dev_free(struct snd_device *device)
{
struct snd_jack *jack = device->device_data;
struct snd_card *card = device->card;
struct snd_jack_kctl *jack_kctl, *tmp_jack_kctl;
list_for_each_entry_safe(jack_kctl, tmp_jack_kctl, &jack->kctl_list, list) {
list_del_init(&jack_kctl->list);
snd_ctl_remove(card, jack_kctl->kctl);
}
if (jack->private_free)
jack->private_free(jack);
snd_jack_dev_disconnect(device);
kfree(jack->id);
kfree(jack);
return 0;
}
static int snd_jack_dev_register(struct snd_device *device)
{
struct snd_jack *jack = device->device_data;
struct snd_card *card = device->card;
int err, i;
snprintf(jack->name, sizeof(jack->name), "%s %s",
card->shortname, jack->id);
if (!jack->input_dev)
return 0;
jack->input_dev->name = jack->name;
if (!jack->input_dev->dev.parent)
jack->input_dev->dev.parent = snd_card_get_device_link(card);
for (i = 0; i < ARRAY_SIZE(jack->key); i++) {
int testbit = SND_JACK_BTN_0 >> i;
if (!(jack->type & testbit))
continue;
if (!jack->key[i])
jack->key[i] = BTN_0 + i;
input_set_capability(jack->input_dev, EV_KEY, jack->key[i]);
}
err = input_register_device(jack->input_dev);
if (err == 0)
jack->registered = 1;
return err;
}
static void snd_jack_kctl_private_free(struct snd_kcontrol *kctl)
{
struct snd_jack_kctl *jack_kctl;
jack_kctl = kctl->private_data;
if (jack_kctl) {
list_del(&jack_kctl->list);
kfree(jack_kctl);
}
}
static void snd_jack_kctl_add(struct snd_jack *jack, struct snd_jack_kctl *jack_kctl)
{
list_add_tail(&jack_kctl->list, &jack->kctl_list);
}
static struct snd_jack_kctl * snd_jack_kctl_new(struct snd_card *card, const char *name, unsigned int mask)
{
struct snd_kcontrol *kctl;
struct snd_jack_kctl *jack_kctl;
int err;
kctl = snd_kctl_jack_new(name, card);
if (!kctl)
return NULL;
err = snd_ctl_add(card, kctl);
if (err < 0)
return NULL;
jack_kctl = kzalloc(sizeof(*jack_kctl), GFP_KERNEL);
if (!jack_kctl)
goto error;
jack_kctl->kctl = kctl;
jack_kctl->mask_bits = mask;
kctl->private_data = jack_kctl;
kctl->private_free = snd_jack_kctl_private_free;
return jack_kctl;
error:
snd_ctl_free_one(kctl);
return NULL;
}
int snd_jack_add_new_kctl(struct snd_jack *jack, const char * name, int mask)
{
struct snd_jack_kctl *jack_kctl;
jack_kctl = snd_jack_kctl_new(jack->card, name, mask);
if (!jack_kctl)
return -ENOMEM;
snd_jack_kctl_add(jack, jack_kctl);
return 0;
}
int snd_jack_new(struct snd_card *card, const char *id, int type,
struct snd_jack **jjack, bool initial_kctl, bool phantom_jack)
{
struct snd_jack *jack;
struct snd_jack_kctl *jack_kctl = NULL;
int err;
int i;
static struct snd_device_ops ops = {
.dev_free = snd_jack_dev_free,
.dev_register = snd_jack_dev_register,
.dev_disconnect = snd_jack_dev_disconnect,
};
if (initial_kctl) {
jack_kctl = snd_jack_kctl_new(card, id, type);
if (!jack_kctl)
return -ENOMEM;
}
jack = kzalloc(sizeof(struct snd_jack), GFP_KERNEL);
if (jack == NULL)
return -ENOMEM;
jack->id = kstrdup(id, GFP_KERNEL);
if (!phantom_jack) {
jack->input_dev = input_allocate_device();
if (jack->input_dev == NULL) {
err = -ENOMEM;
goto fail_input;
}
jack->input_dev->phys = "ALSA";
jack->type = type;
for (i = 0; i < SND_JACK_SWITCH_TYPES; i++)
if (type & (1 << i))
input_set_capability(jack->input_dev, EV_SW,
jack_switch_types[i]);
}
err = snd_device_new(card, SNDRV_DEV_JACK, jack, &ops);
if (err < 0)
goto fail_input;
jack->card = card;
INIT_LIST_HEAD(&jack->kctl_list);
if (initial_kctl)
snd_jack_kctl_add(jack, jack_kctl);
*jjack = jack;
return 0;
fail_input:
input_free_device(jack->input_dev);
kfree(jack->id);
kfree(jack);
return err;
}
void snd_jack_set_parent(struct snd_jack *jack, struct device *parent)
{
WARN_ON(jack->registered);
if (!jack->input_dev)
return;
jack->input_dev->dev.parent = parent;
}
int snd_jack_set_key(struct snd_jack *jack, enum snd_jack_types type,
int keytype)
{
int key = fls(SND_JACK_BTN_0) - fls(type);
WARN_ON(jack->registered);
if (!keytype || key >= ARRAY_SIZE(jack->key))
return -EINVAL;
jack->type |= type;
jack->key[key] = keytype;
return 0;
}
void snd_jack_report(struct snd_jack *jack, int status)
{
struct snd_jack_kctl *jack_kctl;
int i;
if (!jack)
return;
list_for_each_entry(jack_kctl, &jack->kctl_list, list)
snd_kctl_jack_report(jack->card, jack_kctl->kctl,
status & jack_kctl->mask_bits);
if (!jack->input_dev)
return;
for (i = 0; i < ARRAY_SIZE(jack->key); i++) {
int testbit = SND_JACK_BTN_0 >> i;
if (jack->type & testbit)
input_report_key(jack->input_dev, jack->key[i],
status & testbit);
}
for (i = 0; i < ARRAY_SIZE(jack_switch_types); i++) {
int testbit = 1 << i;
if (jack->type & testbit)
input_report_switch(jack->input_dev,
jack_switch_types[i],
status & testbit);
}
input_sync(jack->input_dev);
}
