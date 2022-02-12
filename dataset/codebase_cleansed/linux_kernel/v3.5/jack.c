static int snd_jack_dev_free(struct snd_device *device)
{
struct snd_jack *jack = device->device_data;
if (jack->private_free)
jack->private_free(jack);
if (jack->registered)
input_unregister_device(jack->input_dev);
else
input_free_device(jack->input_dev);
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
int snd_jack_new(struct snd_card *card, const char *id, int type,
struct snd_jack **jjack)
{
struct snd_jack *jack;
int err;
int i;
static struct snd_device_ops ops = {
.dev_free = snd_jack_dev_free,
.dev_register = snd_jack_dev_register,
};
jack = kzalloc(sizeof(struct snd_jack), GFP_KERNEL);
if (jack == NULL)
return -ENOMEM;
jack->id = kstrdup(id, GFP_KERNEL);
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
err = snd_device_new(card, SNDRV_DEV_JACK, jack, &ops);
if (err < 0)
goto fail_input;
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
int i;
if (!jack)
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
