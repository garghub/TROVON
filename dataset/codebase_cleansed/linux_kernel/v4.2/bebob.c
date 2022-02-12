static int
name_device(struct snd_bebob *bebob, unsigned int vendor_id)
{
struct fw_device *fw_dev = fw_parent_device(bebob->unit);
char vendor[24] = {0};
char model[32] = {0};
u32 hw_id;
u32 data[2] = {0};
u32 revision;
u32 version;
int err;
err = fw_csr_string(fw_dev->config_rom + 5, CSR_VENDOR,
vendor, sizeof(vendor));
if (err < 0)
goto end;
err = fw_csr_string(bebob->unit->directory, CSR_MODEL,
model, sizeof(model));
if (err < 0)
goto end;
err = snd_bebob_read_quad(bebob->unit, INFO_OFFSET_HW_MODEL_ID,
&hw_id);
if (err < 0)
goto end;
err = snd_bebob_read_quad(bebob->unit, INFO_OFFSET_HW_MODEL_REVISION,
&revision);
if (err < 0)
goto end;
err = snd_bebob_read_block(bebob->unit, INFO_OFFSET_GUID,
data, sizeof(data));
if (err < 0)
goto end;
err = snd_bebob_read_quad(bebob->unit, INFO_OFFSET_BEBOB_VERSION,
&version);
if (err < 0)
goto end;
bebob->version = version;
strcpy(bebob->card->driver, "BeBoB");
strcpy(bebob->card->shortname, model);
strcpy(bebob->card->mixername, model);
snprintf(bebob->card->longname, sizeof(bebob->card->longname),
"%s %s (id:%d, rev:%d), GUID %08x%08x at %s, S%d",
vendor, model, hw_id, revision,
data[0], data[1], dev_name(&bebob->unit->device),
100 << fw_dev->max_speed);
end:
return err;
}
static void
bebob_card_free(struct snd_card *card)
{
struct snd_bebob *bebob = card->private_data;
snd_bebob_stream_destroy_duplex(bebob);
fw_unit_put(bebob->unit);
kfree(bebob->maudio_special_quirk);
if (bebob->card_index >= 0) {
mutex_lock(&devices_mutex);
clear_bit(bebob->card_index, devices_used);
mutex_unlock(&devices_mutex);
}
mutex_destroy(&bebob->mutex);
}
static const struct snd_bebob_spec *
get_saffire_spec(struct fw_unit *unit)
{
char name[24] = {0};
if (fw_csr_string(unit->directory, CSR_MODEL, name, sizeof(name)) < 0)
return NULL;
if (strcmp(name, "SaffireLE") == 0)
return &saffire_le_spec;
else
return &saffire_spec;
}
static bool
check_audiophile_booted(struct fw_unit *unit)
{
char name[24] = {0};
if (fw_csr_string(unit->directory, CSR_MODEL, name, sizeof(name)) < 0)
return false;
return strncmp(name, "FW Audiophile Bootloader", 15) != 0;
}
static int
bebob_probe(struct fw_unit *unit,
const struct ieee1394_device_id *entry)
{
struct snd_card *card;
struct snd_bebob *bebob;
const struct snd_bebob_spec *spec;
unsigned int card_index;
int err;
mutex_lock(&devices_mutex);
for (card_index = 0; card_index < SNDRV_CARDS; card_index++) {
if (!test_bit(card_index, devices_used) && enable[card_index])
break;
}
if (card_index >= SNDRV_CARDS) {
err = -ENOENT;
goto end;
}
if ((entry->vendor_id == VEN_FOCUSRITE) &&
(entry->model_id == MODEL_FOCUSRITE_SAFFIRE_BOTH))
spec = get_saffire_spec(unit);
else if ((entry->vendor_id == VEN_MAUDIO1) &&
(entry->model_id == MODEL_MAUDIO_AUDIOPHILE_BOTH) &&
!check_audiophile_booted(unit))
spec = NULL;
else
spec = (const struct snd_bebob_spec *)entry->driver_data;
if (spec == NULL) {
if ((entry->vendor_id == VEN_MAUDIO1) ||
(entry->vendor_id == VEN_MAUDIO2))
err = snd_bebob_maudio_load_firmware(unit);
else
err = -ENOSYS;
goto end;
}
err = snd_card_new(&unit->device, index[card_index], id[card_index],
THIS_MODULE, sizeof(struct snd_bebob), &card);
if (err < 0)
goto end;
bebob = card->private_data;
bebob->card_index = card_index;
set_bit(card_index, devices_used);
card->private_free = bebob_card_free;
bebob->card = card;
bebob->unit = fw_unit_get(unit);
bebob->spec = spec;
mutex_init(&bebob->mutex);
spin_lock_init(&bebob->lock);
init_waitqueue_head(&bebob->hwdep_wait);
err = name_device(bebob, entry->vendor_id);
if (err < 0)
goto error;
if ((entry->vendor_id == VEN_MAUDIO1) &&
(entry->model_id == MODEL_MAUDIO_FW1814))
err = snd_bebob_maudio_special_discover(bebob, true);
else if ((entry->vendor_id == VEN_MAUDIO1) &&
(entry->model_id == MODEL_MAUDIO_PROJECTMIX))
err = snd_bebob_maudio_special_discover(bebob, false);
else
err = snd_bebob_stream_discover(bebob);
if (err < 0)
goto error;
snd_bebob_proc_init(bebob);
if ((bebob->midi_input_ports > 0) ||
(bebob->midi_output_ports > 0)) {
err = snd_bebob_create_midi_devices(bebob);
if (err < 0)
goto error;
}
err = snd_bebob_create_pcm_devices(bebob);
if (err < 0)
goto error;
err = snd_bebob_create_hwdep_device(bebob);
if (err < 0)
goto error;
err = snd_bebob_stream_init_duplex(bebob);
if (err < 0)
goto error;
if (!bebob->maudio_special_quirk) {
err = snd_card_register(card);
if (err < 0) {
snd_bebob_stream_destroy_duplex(bebob);
goto error;
}
} else {
bebob->deferred_registration = true;
fw_schedule_bus_reset(fw_parent_device(bebob->unit)->card,
false, true);
}
dev_set_drvdata(&unit->device, bebob);
end:
mutex_unlock(&devices_mutex);
return err;
error:
mutex_unlock(&devices_mutex);
snd_card_free(card);
return err;
}
static void
bebob_update(struct fw_unit *unit)
{
struct snd_bebob *bebob = dev_get_drvdata(&unit->device);
if (bebob == NULL)
return;
fcp_bus_reset(bebob->unit);
snd_bebob_stream_update_duplex(bebob);
if (bebob->deferred_registration) {
if (snd_card_register(bebob->card) < 0) {
snd_bebob_stream_destroy_duplex(bebob);
snd_card_free(bebob->card);
}
bebob->deferred_registration = false;
}
}
static void bebob_remove(struct fw_unit *unit)
{
struct snd_bebob *bebob = dev_get_drvdata(&unit->device);
if (bebob == NULL)
return;
if (!completion_done(&bebob->bus_reset))
complete_all(&bebob->bus_reset);
snd_card_free_when_closed(bebob->card);
}
static int __init
snd_bebob_init(void)
{
return driver_register(&bebob_driver.driver);
}
static void __exit
snd_bebob_exit(void)
{
driver_unregister(&bebob_driver.driver);
}
