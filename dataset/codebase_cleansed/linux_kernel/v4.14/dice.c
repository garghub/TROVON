static bool force_two_pcm_support(struct fw_unit *unit)
{
static const char *const models[] = {
"StudioKonnekt48",
"SAFFIRE_PRO_40",
"LIQUID_SAFFIRE_56",
"SAFFIRE_PRO_40_1",
};
char model[32];
unsigned int i;
int err;
err = fw_csr_string(unit->directory, CSR_MODEL, model, sizeof(model));
if (err < 0)
return false;
for (i = 0; i < ARRAY_SIZE(models); i++) {
if (strcmp(models[i], model) == 0)
break;
}
return i < ARRAY_SIZE(models);
}
static int check_dice_category(struct fw_unit *unit)
{
struct fw_device *device = fw_parent_device(unit);
struct fw_csr_iterator it;
int key, val, vendor = -1, model = -1;
unsigned int category;
fw_csr_iterator_init(&it, unit->directory);
while (fw_csr_iterator_next(&it, &key, &val)) {
switch (key) {
case CSR_SPECIFIER_ID:
vendor = val;
break;
case CSR_MODEL:
model = val;
break;
}
}
if (vendor == OUI_FOCUSRITE || vendor == OUI_TCELECTRONIC) {
if (force_two_pcm_support(unit))
return 0;
}
if (vendor == OUI_WEISS)
category = WEISS_CATEGORY_ID;
else if (vendor == OUI_LOUD)
category = LOUD_CATEGORY_ID;
else
category = DICE_CATEGORY_ID;
if (device->config_rom[3] != ((vendor << 8) | category) ||
device->config_rom[4] >> 22 != model)
return -ENODEV;
return 0;
}
static int check_clock_caps(struct snd_dice *dice)
{
__be32 value;
int err;
if (dice->clock_caps > 0) {
err = snd_dice_transaction_read_global(dice,
GLOBAL_CLOCK_CAPABILITIES,
&value, 4);
if (err < 0)
return err;
dice->clock_caps = be32_to_cpu(value);
} else {
dice->clock_caps = CLOCK_CAP_RATE_44100 |
CLOCK_CAP_RATE_48000 |
CLOCK_CAP_SOURCE_ARX1 |
CLOCK_CAP_SOURCE_INTERNAL;
}
return 0;
}
static void dice_card_strings(struct snd_dice *dice)
{
struct snd_card *card = dice->card;
struct fw_device *dev = fw_parent_device(dice->unit);
char vendor[32], model[32];
unsigned int i;
int err;
strcpy(card->driver, "DICE");
strcpy(card->shortname, "DICE");
BUILD_BUG_ON(NICK_NAME_SIZE < sizeof(card->shortname));
err = snd_dice_transaction_read_global(dice, GLOBAL_NICK_NAME,
card->shortname,
sizeof(card->shortname));
if (err >= 0) {
BUILD_BUG_ON(sizeof(card->shortname) % 4 != 0);
for (i = 0; i < sizeof(card->shortname); i += 4)
swab32s((u32 *)&card->shortname[i]);
card->shortname[sizeof(card->shortname) - 1] = '\0';
}
strcpy(vendor, "?");
fw_csr_string(dev->config_rom + 5, CSR_VENDOR, vendor, sizeof(vendor));
strcpy(model, "?");
fw_csr_string(dice->unit->directory, CSR_MODEL, model, sizeof(model));
snprintf(card->longname, sizeof(card->longname),
"%s %s (serial %u) at %s, S%d",
vendor, model, dev->config_rom[4] & 0x3fffff,
dev_name(&dice->unit->device), 100 << dev->max_speed);
strcpy(card->mixername, "DICE");
}
static void dice_free(struct snd_dice *dice)
{
snd_dice_stream_destroy_duplex(dice);
snd_dice_transaction_destroy(dice);
fw_unit_put(dice->unit);
mutex_destroy(&dice->mutex);
kfree(dice);
}
static void dice_card_free(struct snd_card *card)
{
dice_free(card->private_data);
}
static void do_registration(struct work_struct *work)
{
struct snd_dice *dice = container_of(work, struct snd_dice, dwork.work);
int err;
if (dice->registered)
return;
err = snd_card_new(&dice->unit->device, -1, NULL, THIS_MODULE, 0,
&dice->card);
if (err < 0)
return;
if (force_two_pcm_support(dice->unit))
dice->force_two_pcms = true;
err = snd_dice_transaction_init(dice);
if (err < 0)
goto error;
err = check_clock_caps(dice);
if (err < 0)
goto error;
dice_card_strings(dice);
err = snd_dice_stream_init_duplex(dice);
if (err < 0)
goto error;
snd_dice_create_proc(dice);
err = snd_dice_create_pcm(dice);
if (err < 0)
goto error;
err = snd_dice_create_midi(dice);
if (err < 0)
goto error;
err = snd_dice_create_hwdep(dice);
if (err < 0)
goto error;
err = snd_card_register(dice->card);
if (err < 0)
goto error;
dice->card->private_free = dice_card_free;
dice->card->private_data = dice;
dice->registered = true;
return;
error:
snd_dice_stream_destroy_duplex(dice);
snd_dice_transaction_destroy(dice);
snd_dice_stream_destroy_duplex(dice);
snd_card_free(dice->card);
dev_info(&dice->unit->device,
"Sound card registration failed: %d\n", err);
}
static int dice_probe(struct fw_unit *unit, const struct ieee1394_device_id *id)
{
struct snd_dice *dice;
int err;
err = check_dice_category(unit);
if (err < 0)
return -ENODEV;
dice = kzalloc(sizeof(struct snd_dice), GFP_KERNEL);
if (dice == NULL)
return -ENOMEM;
dice->unit = fw_unit_get(unit);
dev_set_drvdata(&unit->device, dice);
spin_lock_init(&dice->lock);
mutex_init(&dice->mutex);
init_completion(&dice->clock_accepted);
init_waitqueue_head(&dice->hwdep_wait);
INIT_DEFERRABLE_WORK(&dice->dwork, do_registration);
snd_fw_schedule_registration(unit, &dice->dwork);
return 0;
}
static void dice_remove(struct fw_unit *unit)
{
struct snd_dice *dice = dev_get_drvdata(&unit->device);
cancel_delayed_work_sync(&dice->dwork);
if (dice->registered) {
snd_card_free_when_closed(dice->card);
} else {
dice_free(dice);
}
}
static void dice_bus_reset(struct fw_unit *unit)
{
struct snd_dice *dice = dev_get_drvdata(&unit->device);
if (!dice->registered)
snd_fw_schedule_registration(unit, &dice->dwork);
snd_dice_transaction_reinit(dice);
if (dice->registered) {
mutex_lock(&dice->mutex);
snd_dice_stream_update_duplex(dice);
mutex_unlock(&dice->mutex);
}
}
static int __init alsa_dice_init(void)
{
return driver_register(&dice_driver.driver);
}
static void __exit alsa_dice_exit(void)
{
driver_unregister(&dice_driver.driver);
}
