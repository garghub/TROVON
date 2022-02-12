static bool detect_loud_models(struct fw_unit *unit)
{
const char *const models[] = {
"Onyxi",
"Onyx-i",
"Onyx 1640i",
"d.Pro",
"Mackie Onyx Satellite",
"Tapco LINK.firewire 4x6",
"U.420"};
char model[32];
unsigned int i;
int err;
err = fw_csr_string(unit->directory, CSR_MODEL,
model, sizeof(model));
if (err < 0)
return false;
for (i = 0; i < ARRAY_SIZE(models); i++) {
if (strcmp(models[i], model) == 0)
break;
}
return (i < ARRAY_SIZE(models));
}
static int name_card(struct snd_oxfw *oxfw)
{
struct fw_device *fw_dev = fw_parent_device(oxfw->unit);
const struct compat_info *info;
char vendor[24];
char model[32];
const char *d, *v, *m;
u32 firmware;
int err;
err = fw_csr_string(fw_dev->config_rom + 5, CSR_VENDOR,
vendor, sizeof(vendor));
if (err < 0)
goto end;
err = fw_csr_string(oxfw->unit->directory, CSR_MODEL,
model, sizeof(model));
if (err < 0)
goto end;
err = snd_fw_transaction(oxfw->unit, TCODE_READ_QUADLET_REQUEST,
OXFORD_FIRMWARE_ID_ADDRESS, &firmware, 4, 0);
if (err < 0)
goto end;
be32_to_cpus(&firmware);
if (oxfw->entry->vendor_id == VENDOR_GRIFFIN ||
oxfw->entry->vendor_id == VENDOR_LACIE) {
info = (const struct compat_info *)oxfw->entry->driver_data;
d = info->driver_name;
v = info->vendor_name;
m = info->model_name;
} else {
d = "OXFW";
v = vendor;
m = model;
}
strcpy(oxfw->card->driver, d);
strcpy(oxfw->card->mixername, m);
strcpy(oxfw->card->shortname, m);
snprintf(oxfw->card->longname, sizeof(oxfw->card->longname),
"%s %s (OXFW%x %04x), GUID %08x%08x at %s, S%d",
v, m, firmware >> 20, firmware & 0xffff,
fw_dev->config_rom[3], fw_dev->config_rom[4],
dev_name(&oxfw->unit->device), 100 << fw_dev->max_speed);
end:
return err;
}
static void oxfw_free(struct snd_oxfw *oxfw)
{
unsigned int i;
snd_oxfw_stream_destroy_simplex(oxfw, &oxfw->rx_stream);
if (oxfw->has_output)
snd_oxfw_stream_destroy_simplex(oxfw, &oxfw->tx_stream);
fw_unit_put(oxfw->unit);
for (i = 0; i < SND_OXFW_STREAM_FORMAT_ENTRIES; i++) {
kfree(oxfw->tx_stream_formats[i]);
kfree(oxfw->rx_stream_formats[i]);
}
kfree(oxfw->spec);
mutex_destroy(&oxfw->mutex);
}
static void oxfw_card_free(struct snd_card *card)
{
oxfw_free(card->private_data);
}
static int detect_quirks(struct snd_oxfw *oxfw)
{
struct fw_device *fw_dev = fw_parent_device(oxfw->unit);
struct fw_csr_iterator it;
int key, val;
int vendor, model;
if (oxfw->entry->vendor_id == VENDOR_GRIFFIN)
return snd_oxfw_add_spkr(oxfw, false);
if (oxfw->entry->vendor_id == VENDOR_LACIE)
return snd_oxfw_add_spkr(oxfw, true);
if (oxfw->entry->vendor_id == OUI_STANTON) {
oxfw->midi_input_ports = 0;
oxfw->midi_output_ports = 0;
oxfw->has_output = false;
return snd_oxfw_scs1x_add(oxfw);
}
if (oxfw->entry->vendor_id == VENDOR_TASCAM) {
oxfw->midi_input_ports++;
oxfw->midi_output_ports++;
return 0;
}
vendor = model = 0;
fw_csr_iterator_init(&it, fw_dev->config_rom + 5);
while (fw_csr_iterator_next(&it, &key, &val)) {
if (key == CSR_VENDOR)
vendor = val;
else if (key == CSR_MODEL)
model = val;
}
if (vendor == VENDOR_LOUD && model == MODEL_SATELLITE)
oxfw->wrong_dbs = true;
return 0;
}
static void do_registration(struct work_struct *work)
{
struct snd_oxfw *oxfw = container_of(work, struct snd_oxfw, dwork.work);
int err;
if (oxfw->registered)
return;
err = snd_card_new(&oxfw->unit->device, -1, NULL, THIS_MODULE, 0,
&oxfw->card);
if (err < 0)
return;
err = name_card(oxfw);
if (err < 0)
goto error;
err = snd_oxfw_stream_discover(oxfw);
if (err < 0)
goto error;
err = detect_quirks(oxfw);
if (err < 0)
goto error;
err = snd_oxfw_stream_init_simplex(oxfw, &oxfw->rx_stream);
if (err < 0)
goto error;
if (oxfw->has_output) {
err = snd_oxfw_stream_init_simplex(oxfw, &oxfw->tx_stream);
if (err < 0)
goto error;
}
err = snd_oxfw_create_pcm(oxfw);
if (err < 0)
goto error;
snd_oxfw_proc_init(oxfw);
err = snd_oxfw_create_midi(oxfw);
if (err < 0)
goto error;
err = snd_oxfw_create_hwdep(oxfw);
if (err < 0)
goto error;
err = snd_card_register(oxfw->card);
if (err < 0)
goto error;
oxfw->card->private_free = oxfw_card_free;
oxfw->card->private_data = oxfw;
oxfw->registered = true;
return;
error:
snd_oxfw_stream_destroy_simplex(oxfw, &oxfw->rx_stream);
if (oxfw->has_output)
snd_oxfw_stream_destroy_simplex(oxfw, &oxfw->tx_stream);
snd_card_free(oxfw->card);
dev_info(&oxfw->unit->device,
"Sound card registration failed: %d\n", err);
}
static int oxfw_probe(struct fw_unit *unit,
const struct ieee1394_device_id *entry)
{
struct snd_oxfw *oxfw;
if (entry->vendor_id == VENDOR_LOUD && !detect_loud_models(unit))
return -ENODEV;
oxfw = kzalloc(sizeof(struct snd_oxfw), GFP_KERNEL);
if (oxfw == NULL)
return -ENOMEM;
oxfw->entry = entry;
oxfw->unit = fw_unit_get(unit);
dev_set_drvdata(&unit->device, oxfw);
mutex_init(&oxfw->mutex);
spin_lock_init(&oxfw->lock);
init_waitqueue_head(&oxfw->hwdep_wait);
INIT_DEFERRABLE_WORK(&oxfw->dwork, do_registration);
snd_fw_schedule_registration(unit, &oxfw->dwork);
return 0;
}
static void oxfw_bus_reset(struct fw_unit *unit)
{
struct snd_oxfw *oxfw = dev_get_drvdata(&unit->device);
if (!oxfw->registered)
snd_fw_schedule_registration(unit, &oxfw->dwork);
fcp_bus_reset(oxfw->unit);
if (oxfw->registered) {
mutex_lock(&oxfw->mutex);
snd_oxfw_stream_update_simplex(oxfw, &oxfw->rx_stream);
if (oxfw->has_output)
snd_oxfw_stream_update_simplex(oxfw, &oxfw->tx_stream);
mutex_unlock(&oxfw->mutex);
if (oxfw->entry->vendor_id == OUI_STANTON)
snd_oxfw_scs1x_update(oxfw);
}
}
static void oxfw_remove(struct fw_unit *unit)
{
struct snd_oxfw *oxfw = dev_get_drvdata(&unit->device);
cancel_delayed_work_sync(&oxfw->dwork);
if (oxfw->registered) {
snd_card_free_when_closed(oxfw->card);
} else {
oxfw_free(oxfw);
}
}
static int __init snd_oxfw_init(void)
{
return driver_register(&oxfw_driver.driver);
}
static void __exit snd_oxfw_exit(void)
{
driver_unregister(&oxfw_driver.driver);
}
