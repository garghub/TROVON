static void name_card(struct snd_ff *ff)
{
struct fw_device *fw_dev = fw_parent_device(ff->unit);
strcpy(ff->card->driver, "Fireface");
strcpy(ff->card->shortname, ff->spec->name);
strcpy(ff->card->mixername, ff->spec->name);
snprintf(ff->card->longname, sizeof(ff->card->longname),
"RME %s, GUID %08x%08x at %s, S%d", ff->spec->name,
fw_dev->config_rom[3], fw_dev->config_rom[4],
dev_name(&ff->unit->device), 100 << fw_dev->max_speed);
}
static void ff_free(struct snd_ff *ff)
{
snd_ff_stream_destroy_duplex(ff);
snd_ff_transaction_unregister(ff);
fw_unit_put(ff->unit);
mutex_destroy(&ff->mutex);
kfree(ff);
}
static void ff_card_free(struct snd_card *card)
{
ff_free(card->private_data);
}
static void do_registration(struct work_struct *work)
{
struct snd_ff *ff = container_of(work, struct snd_ff, dwork.work);
int err;
if (ff->registered)
return;
err = snd_card_new(&ff->unit->device, -1, NULL, THIS_MODULE, 0,
&ff->card);
if (err < 0)
return;
err = snd_ff_transaction_register(ff);
if (err < 0)
goto error;
name_card(ff);
err = snd_ff_stream_init_duplex(ff);
if (err < 0)
goto error;
snd_ff_proc_init(ff);
err = snd_ff_create_midi_devices(ff);
if (err < 0)
goto error;
err = snd_ff_create_pcm_devices(ff);
if (err < 0)
goto error;
err = snd_ff_create_hwdep_devices(ff);
if (err < 0)
goto error;
err = snd_card_register(ff->card);
if (err < 0)
goto error;
ff->card->private_free = ff_card_free;
ff->card->private_data = ff;
ff->registered = true;
return;
error:
snd_ff_transaction_unregister(ff);
snd_ff_stream_destroy_duplex(ff);
snd_card_free(ff->card);
dev_info(&ff->unit->device,
"Sound card registration failed: %d\n", err);
}
static int snd_ff_probe(struct fw_unit *unit,
const struct ieee1394_device_id *entry)
{
struct snd_ff *ff;
ff = kzalloc(sizeof(struct snd_ff), GFP_KERNEL);
if (ff == NULL)
return -ENOMEM;
ff->unit = fw_unit_get(unit);
dev_set_drvdata(&unit->device, ff);
mutex_init(&ff->mutex);
spin_lock_init(&ff->lock);
init_waitqueue_head(&ff->hwdep_wait);
ff->spec = (const struct snd_ff_spec *)entry->driver_data;
INIT_DEFERRABLE_WORK(&ff->dwork, do_registration);
snd_fw_schedule_registration(unit, &ff->dwork);
return 0;
}
static void snd_ff_update(struct fw_unit *unit)
{
struct snd_ff *ff = dev_get_drvdata(&unit->device);
if (!ff->registered)
snd_fw_schedule_registration(unit, &ff->dwork);
snd_ff_transaction_reregister(ff);
if (ff->registered)
snd_ff_stream_update_duplex(ff);
}
static void snd_ff_remove(struct fw_unit *unit)
{
struct snd_ff *ff = dev_get_drvdata(&unit->device);
cancel_work_sync(&ff->dwork.work);
if (ff->registered) {
snd_card_free_when_closed(ff->card);
} else {
ff_free(ff);
}
}
static int __init snd_ff_init(void)
{
return driver_register(&ff_driver.driver);
}
static void __exit snd_ff_exit(void)
{
driver_unregister(&ff_driver.driver);
}
