static int identify_model(struct snd_tscm *tscm)
{
struct fw_device *fw_dev = fw_parent_device(tscm->unit);
const u32 *config_rom = fw_dev->config_rom;
char model[9];
unsigned int i;
u8 c;
if (fw_dev->config_rom_length < 30) {
dev_err(&tscm->unit->device,
"Configuration ROM is too short.\n");
return -ENODEV;
}
for (i = 0; i < 8; i++) {
c = config_rom[28 + i / 4] >> (24 - 8 * (i % 4));
if (c == '\0')
break;
model[i] = c;
}
model[i] = '\0';
for (i = 0; i < ARRAY_SIZE(model_specs); i++) {
if (strcmp(model, model_specs[i].name) == 0) {
tscm->spec = &model_specs[i];
break;
}
}
if (tscm->spec == NULL)
return -ENODEV;
strcpy(tscm->card->driver, "FW-TASCAM");
strcpy(tscm->card->shortname, model);
strcpy(tscm->card->mixername, model);
snprintf(tscm->card->longname, sizeof(tscm->card->longname),
"TASCAM %s, GUID %08x%08x at %s, S%d", model,
fw_dev->config_rom[3], fw_dev->config_rom[4],
dev_name(&tscm->unit->device), 100 << fw_dev->max_speed);
return 0;
}
static void tscm_card_free(struct snd_card *card)
{
struct snd_tscm *tscm = card->private_data;
snd_tscm_transaction_unregister(tscm);
snd_tscm_stream_destroy_duplex(tscm);
fw_unit_put(tscm->unit);
mutex_destroy(&tscm->mutex);
}
static int snd_tscm_probe(struct fw_unit *unit,
const struct ieee1394_device_id *entry)
{
struct snd_card *card;
struct snd_tscm *tscm;
int err;
err = snd_card_new(&unit->device, -1, NULL, THIS_MODULE,
sizeof(struct snd_tscm), &card);
if (err < 0)
return err;
card->private_free = tscm_card_free;
tscm = card->private_data;
tscm->card = card;
tscm->unit = fw_unit_get(unit);
mutex_init(&tscm->mutex);
spin_lock_init(&tscm->lock);
init_waitqueue_head(&tscm->hwdep_wait);
err = identify_model(tscm);
if (err < 0)
goto error;
snd_tscm_proc_init(tscm);
err = snd_tscm_stream_init_duplex(tscm);
if (err < 0)
goto error;
err = snd_tscm_create_pcm_devices(tscm);
if (err < 0)
goto error;
err = snd_tscm_transaction_register(tscm);
if (err < 0)
goto error;
err = snd_tscm_create_midi_devices(tscm);
if (err < 0)
goto error;
err = snd_tscm_create_hwdep_device(tscm);
if (err < 0)
goto error;
err = snd_card_register(card);
if (err < 0)
goto error;
dev_set_drvdata(&unit->device, tscm);
return err;
error:
snd_card_free(card);
return err;
}
static void snd_tscm_update(struct fw_unit *unit)
{
struct snd_tscm *tscm = dev_get_drvdata(&unit->device);
snd_tscm_transaction_reregister(tscm);
mutex_lock(&tscm->mutex);
snd_tscm_stream_update_duplex(tscm);
mutex_unlock(&tscm->mutex);
}
static void snd_tscm_remove(struct fw_unit *unit)
{
struct snd_tscm *tscm = dev_get_drvdata(&unit->device);
snd_card_free_when_closed(tscm->card);
}
static int __init snd_tscm_init(void)
{
return driver_register(&tscm_driver.driver);
}
static void __exit snd_tscm_exit(void)
{
driver_unregister(&tscm_driver.driver);
}
