static bool detect_loud_models(struct fw_unit *unit)
{
const char *const models[] = {
"Onyxi",
"Onyx-i",
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
if (oxfw->device_info) {
d = oxfw->device_info->driver_name;
v = oxfw->device_info->vendor_name;
m = oxfw->device_info->model_name;
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
static void oxfw_card_free(struct snd_card *card)
{
struct snd_oxfw *oxfw = card->private_data;
unsigned int i;
snd_oxfw_stream_destroy_simplex(oxfw, &oxfw->rx_stream);
if (oxfw->has_output)
snd_oxfw_stream_destroy_simplex(oxfw, &oxfw->tx_stream);
fw_unit_put(oxfw->unit);
for (i = 0; i < SND_OXFW_STREAM_FORMAT_ENTRIES; i++) {
kfree(oxfw->tx_stream_formats[i]);
kfree(oxfw->rx_stream_formats[i]);
}
mutex_destroy(&oxfw->mutex);
}
static void detect_quirks(struct snd_oxfw *oxfw)
{
struct fw_device *fw_dev = fw_parent_device(oxfw->unit);
struct fw_csr_iterator it;
int key, val;
int vendor, model;
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
if (vendor == VENDOR_TASCAM) {
oxfw->midi_input_ports++;
oxfw->midi_output_ports++;
}
}
static int oxfw_probe(struct fw_unit *unit,
const struct ieee1394_device_id *id)
{
struct snd_card *card;
struct snd_oxfw *oxfw;
int err;
if ((id->vendor_id == VENDOR_LOUD) && !detect_loud_models(unit))
return -ENODEV;
err = snd_card_new(&unit->device, -1, NULL, THIS_MODULE,
sizeof(*oxfw), &card);
if (err < 0)
return err;
card->private_free = oxfw_card_free;
oxfw = card->private_data;
oxfw->card = card;
mutex_init(&oxfw->mutex);
oxfw->unit = fw_unit_get(unit);
oxfw->device_info = (const struct device_info *)id->driver_data;
spin_lock_init(&oxfw->lock);
init_waitqueue_head(&oxfw->hwdep_wait);
err = snd_oxfw_stream_discover(oxfw);
if (err < 0)
goto error;
detect_quirks(oxfw);
err = name_card(oxfw);
if (err < 0)
goto error;
err = snd_oxfw_create_pcm(oxfw);
if (err < 0)
goto error;
if (oxfw->device_info) {
err = snd_oxfw_create_mixer(oxfw);
if (err < 0)
goto error;
}
snd_oxfw_proc_init(oxfw);
err = snd_oxfw_create_midi(oxfw);
if (err < 0)
goto error;
err = snd_oxfw_create_hwdep(oxfw);
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
err = snd_card_register(card);
if (err < 0) {
snd_oxfw_stream_destroy_simplex(oxfw, &oxfw->rx_stream);
if (oxfw->has_output)
snd_oxfw_stream_destroy_simplex(oxfw, &oxfw->tx_stream);
goto error;
}
dev_set_drvdata(&unit->device, oxfw);
return 0;
error:
snd_card_free(card);
return err;
}
static void oxfw_bus_reset(struct fw_unit *unit)
{
struct snd_oxfw *oxfw = dev_get_drvdata(&unit->device);
fcp_bus_reset(oxfw->unit);
mutex_lock(&oxfw->mutex);
snd_oxfw_stream_update_simplex(oxfw, &oxfw->rx_stream);
if (oxfw->has_output)
snd_oxfw_stream_update_simplex(oxfw, &oxfw->tx_stream);
mutex_unlock(&oxfw->mutex);
}
static void oxfw_remove(struct fw_unit *unit)
{
struct snd_oxfw *oxfw = dev_get_drvdata(&unit->device);
snd_card_free_when_closed(oxfw->card);
}
static int __init snd_oxfw_init(void)
{
return driver_register(&oxfw_driver.driver);
}
static void __exit snd_oxfw_exit(void)
{
driver_unregister(&oxfw_driver.driver);
}
