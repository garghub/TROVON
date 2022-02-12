static void name_card(struct snd_motu *motu)
{
struct fw_device *fw_dev = fw_parent_device(motu->unit);
struct fw_csr_iterator it;
int key, val;
u32 version = 0;
fw_csr_iterator_init(&it, motu->unit->directory);
while (fw_csr_iterator_next(&it, &key, &val)) {
switch (key) {
case CSR_VERSION:
version = val;
break;
}
}
strcpy(motu->card->driver, "FW-MOTU");
strcpy(motu->card->shortname, motu->spec->name);
strcpy(motu->card->mixername, motu->spec->name);
snprintf(motu->card->longname, sizeof(motu->card->longname),
"MOTU %s (version:%d), GUID %08x%08x at %s, S%d",
motu->spec->name, version,
fw_dev->config_rom[3], fw_dev->config_rom[4],
dev_name(&motu->unit->device), 100 << fw_dev->max_speed);
}
static void motu_free(struct snd_motu *motu)
{
snd_motu_transaction_unregister(motu);
snd_motu_stream_destroy_duplex(motu);
fw_unit_put(motu->unit);
mutex_destroy(&motu->mutex);
kfree(motu);
}
static void motu_card_free(struct snd_card *card)
{
motu_free(card->private_data);
}
static void do_registration(struct work_struct *work)
{
struct snd_motu *motu = container_of(work, struct snd_motu, dwork.work);
int err;
if (motu->registered)
return;
err = snd_card_new(&motu->unit->device, -1, NULL, THIS_MODULE, 0,
&motu->card);
if (err < 0)
return;
name_card(motu);
err = snd_motu_transaction_register(motu);
if (err < 0)
goto error;
err = snd_motu_stream_init_duplex(motu);
if (err < 0)
goto error;
snd_motu_proc_init(motu);
err = snd_motu_create_pcm_devices(motu);
if (err < 0)
goto error;
if (motu->spec->flags & SND_MOTU_SPEC_HAS_MIDI) {
err = snd_motu_create_midi_devices(motu);
if (err < 0)
goto error;
}
err = snd_motu_create_hwdep_device(motu);
if (err < 0)
goto error;
err = snd_card_register(motu->card);
if (err < 0)
goto error;
motu->card->private_free = motu_card_free;
motu->card->private_data = motu;
motu->registered = true;
return;
error:
snd_motu_transaction_unregister(motu);
snd_card_free(motu->card);
dev_info(&motu->unit->device,
"Sound card registration failed: %d\n", err);
}
static int motu_probe(struct fw_unit *unit,
const struct ieee1394_device_id *entry)
{
struct snd_motu *motu;
motu = kzalloc(sizeof(struct snd_motu), GFP_KERNEL);
if (motu == NULL)
return -ENOMEM;
motu->spec = (const struct snd_motu_spec *)entry->driver_data;
motu->unit = fw_unit_get(unit);
dev_set_drvdata(&unit->device, motu);
mutex_init(&motu->mutex);
spin_lock_init(&motu->lock);
init_waitqueue_head(&motu->hwdep_wait);
INIT_DEFERRABLE_WORK(&motu->dwork, do_registration);
snd_fw_schedule_registration(unit, &motu->dwork);
return 0;
}
static void motu_remove(struct fw_unit *unit)
{
struct snd_motu *motu = dev_get_drvdata(&unit->device);
cancel_delayed_work_sync(&motu->dwork);
if (motu->registered) {
snd_card_free_when_closed(motu->card);
} else {
motu_free(motu);
}
}
static void motu_bus_update(struct fw_unit *unit)
{
struct snd_motu *motu = dev_get_drvdata(&unit->device);
if (!motu->registered)
snd_fw_schedule_registration(unit, &motu->dwork);
snd_motu_transaction_reregister(motu);
}
static int __init alsa_motu_init(void)
{
return driver_register(&motu_driver.driver);
}
static void __exit alsa_motu_exit(void)
{
driver_unregister(&motu_driver.driver);
}
