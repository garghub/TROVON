static int
get_hardware_info(struct snd_efw *efw)
{
struct fw_device *fw_dev = fw_parent_device(efw->unit);
struct snd_efw_hwinfo *hwinfo;
char version[12] = {0};
int err;
hwinfo = kzalloc(sizeof(struct snd_efw_hwinfo), GFP_KERNEL);
if (hwinfo == NULL)
return -ENOMEM;
err = snd_efw_command_get_hwinfo(efw, hwinfo);
if (err < 0)
goto end;
snprintf(version, sizeof(version), "%u.%u",
(hwinfo->arm_version >> 24) & 0xff,
(hwinfo->arm_version >> 16) & 0xff);
efw->firmware_version = hwinfo->arm_version;
strcpy(efw->card->driver, "Fireworks");
strcpy(efw->card->shortname, hwinfo->model_name);
strcpy(efw->card->mixername, hwinfo->model_name);
snprintf(efw->card->longname, sizeof(efw->card->longname),
"%s %s v%s, GUID %08x%08x at %s, S%d",
hwinfo->vendor_name, hwinfo->model_name, version,
hwinfo->guid_hi, hwinfo->guid_lo,
dev_name(&efw->unit->device), 100 << fw_dev->max_speed);
if (hwinfo->flags & BIT(FLAG_RESP_ADDR_CHANGABLE))
efw->resp_addr_changable = true;
efw->supported_sampling_rate = 0;
if ((hwinfo->min_sample_rate <= 22050)
&& (22050 <= hwinfo->max_sample_rate))
efw->supported_sampling_rate |= SNDRV_PCM_RATE_22050;
if ((hwinfo->min_sample_rate <= 32000)
&& (32000 <= hwinfo->max_sample_rate))
efw->supported_sampling_rate |= SNDRV_PCM_RATE_32000;
if ((hwinfo->min_sample_rate <= 44100)
&& (44100 <= hwinfo->max_sample_rate))
efw->supported_sampling_rate |= SNDRV_PCM_RATE_44100;
if ((hwinfo->min_sample_rate <= 48000)
&& (48000 <= hwinfo->max_sample_rate))
efw->supported_sampling_rate |= SNDRV_PCM_RATE_48000;
if ((hwinfo->min_sample_rate <= 88200)
&& (88200 <= hwinfo->max_sample_rate))
efw->supported_sampling_rate |= SNDRV_PCM_RATE_88200;
if ((hwinfo->min_sample_rate <= 96000)
&& (96000 <= hwinfo->max_sample_rate))
efw->supported_sampling_rate |= SNDRV_PCM_RATE_96000;
if ((hwinfo->min_sample_rate <= 176400)
&& (176400 <= hwinfo->max_sample_rate))
efw->supported_sampling_rate |= SNDRV_PCM_RATE_176400;
if ((hwinfo->min_sample_rate <= 192000)
&& (192000 <= hwinfo->max_sample_rate))
efw->supported_sampling_rate |= SNDRV_PCM_RATE_192000;
if (hwinfo->midi_out_ports > SND_EFW_MAX_MIDI_OUT_PORTS ||
hwinfo->midi_in_ports > SND_EFW_MAX_MIDI_IN_PORTS) {
err = -EIO;
goto end;
}
efw->midi_out_ports = hwinfo->midi_out_ports;
efw->midi_in_ports = hwinfo->midi_in_ports;
if (hwinfo->amdtp_tx_pcm_channels > AM824_MAX_CHANNELS_FOR_PCM ||
hwinfo->amdtp_tx_pcm_channels_2x > AM824_MAX_CHANNELS_FOR_PCM ||
hwinfo->amdtp_tx_pcm_channels_4x > AM824_MAX_CHANNELS_FOR_PCM ||
hwinfo->amdtp_rx_pcm_channels > AM824_MAX_CHANNELS_FOR_PCM ||
hwinfo->amdtp_rx_pcm_channels_2x > AM824_MAX_CHANNELS_FOR_PCM ||
hwinfo->amdtp_rx_pcm_channels_4x > AM824_MAX_CHANNELS_FOR_PCM) {
err = -ENOSYS;
goto end;
}
efw->pcm_capture_channels[0] = hwinfo->amdtp_tx_pcm_channels;
efw->pcm_capture_channels[1] = hwinfo->amdtp_tx_pcm_channels_2x;
efw->pcm_capture_channels[2] = hwinfo->amdtp_tx_pcm_channels_4x;
efw->pcm_playback_channels[0] = hwinfo->amdtp_rx_pcm_channels;
efw->pcm_playback_channels[1] = hwinfo->amdtp_rx_pcm_channels_2x;
efw->pcm_playback_channels[2] = hwinfo->amdtp_rx_pcm_channels_4x;
if (hwinfo->phys_in_grp_count > HWINFO_MAX_CAPS_GROUPS ||
hwinfo->phys_out_grp_count > HWINFO_MAX_CAPS_GROUPS) {
err = -EIO;
goto end;
}
efw->phys_in = hwinfo->phys_in;
efw->phys_out = hwinfo->phys_out;
efw->phys_in_grp_count = hwinfo->phys_in_grp_count;
efw->phys_out_grp_count = hwinfo->phys_out_grp_count;
memcpy(&efw->phys_in_grps, hwinfo->phys_in_grps,
sizeof(struct snd_efw_phys_grp) * hwinfo->phys_in_grp_count);
memcpy(&efw->phys_out_grps, hwinfo->phys_out_grps,
sizeof(struct snd_efw_phys_grp) * hwinfo->phys_out_grp_count);
if (hwinfo->type == MODEL_ECHO_AUDIOFIRE_9)
efw->is_af9 = true;
if (hwinfo->type == MODEL_ECHO_AUDIOFIRE_2 ||
hwinfo->type == MODEL_ECHO_AUDIOFIRE_4 ||
hwinfo->type == MODEL_ECHO_AUDIOFIRE_9 ||
hwinfo->type == MODEL_GIBSON_RIP ||
hwinfo->type == MODEL_GIBSON_GOLDTOP)
efw->is_fireworks3 = true;
end:
kfree(hwinfo);
return err;
}
static void efw_free(struct snd_efw *efw)
{
snd_efw_stream_destroy_duplex(efw);
snd_efw_transaction_remove_instance(efw);
fw_unit_put(efw->unit);
kfree(efw->resp_buf);
mutex_destroy(&efw->mutex);
kfree(efw);
}
static void
efw_card_free(struct snd_card *card)
{
struct snd_efw *efw = card->private_data;
if (efw->card_index >= 0) {
mutex_lock(&devices_mutex);
clear_bit(efw->card_index, devices_used);
mutex_unlock(&devices_mutex);
}
efw_free(card->private_data);
}
static void
do_registration(struct work_struct *work)
{
struct snd_efw *efw = container_of(work, struct snd_efw, dwork.work);
unsigned int card_index;
int err;
if (efw->registered)
return;
mutex_lock(&devices_mutex);
for (card_index = 0; card_index < SNDRV_CARDS; ++card_index) {
if (!test_bit(card_index, devices_used) && enable[card_index])
break;
}
if (card_index >= SNDRV_CARDS) {
mutex_unlock(&devices_mutex);
return;
}
err = snd_card_new(&efw->unit->device, index[card_index],
id[card_index], THIS_MODULE, 0, &efw->card);
if (err < 0) {
mutex_unlock(&devices_mutex);
return;
}
snd_efw_resp_buf_size = clamp(snd_efw_resp_buf_size,
SND_EFW_RESPONSE_MAXIMUM_BYTES, 4096U);
efw->resp_buf = kzalloc(snd_efw_resp_buf_size, GFP_KERNEL);
if (efw->resp_buf == NULL) {
err = -ENOMEM;
goto error;
}
efw->pull_ptr = efw->push_ptr = efw->resp_buf;
snd_efw_transaction_add_instance(efw);
err = get_hardware_info(efw);
if (err < 0)
goto error;
err = snd_efw_stream_init_duplex(efw);
if (err < 0)
goto error;
snd_efw_proc_init(efw);
if (efw->midi_out_ports || efw->midi_in_ports) {
err = snd_efw_create_midi_devices(efw);
if (err < 0)
goto error;
}
err = snd_efw_create_pcm_devices(efw);
if (err < 0)
goto error;
err = snd_efw_create_hwdep_device(efw);
if (err < 0)
goto error;
err = snd_card_register(efw->card);
if (err < 0)
goto error;
set_bit(card_index, devices_used);
mutex_unlock(&devices_mutex);
efw->card->private_free = efw_card_free;
efw->card->private_data = efw;
efw->registered = true;
return;
error:
mutex_unlock(&devices_mutex);
snd_efw_transaction_remove_instance(efw);
snd_efw_stream_destroy_duplex(efw);
snd_card_free(efw->card);
dev_info(&efw->unit->device,
"Sound card registration failed: %d\n", err);
}
static int
efw_probe(struct fw_unit *unit, const struct ieee1394_device_id *entry)
{
struct snd_efw *efw;
efw = kzalloc(sizeof(struct snd_efw), GFP_KERNEL);
if (efw == NULL)
return -ENOMEM;
efw->unit = fw_unit_get(unit);
dev_set_drvdata(&unit->device, efw);
mutex_init(&efw->mutex);
spin_lock_init(&efw->lock);
init_waitqueue_head(&efw->hwdep_wait);
INIT_DEFERRABLE_WORK(&efw->dwork, do_registration);
snd_fw_schedule_registration(unit, &efw->dwork);
return 0;
}
static void efw_update(struct fw_unit *unit)
{
struct snd_efw *efw = dev_get_drvdata(&unit->device);
if (!efw->registered)
snd_fw_schedule_registration(unit, &efw->dwork);
snd_efw_transaction_bus_reset(efw->unit);
if (efw->registered) {
mutex_lock(&efw->mutex);
snd_efw_stream_update_duplex(efw);
mutex_unlock(&efw->mutex);
}
}
static void efw_remove(struct fw_unit *unit)
{
struct snd_efw *efw = dev_get_drvdata(&unit->device);
cancel_delayed_work_sync(&efw->dwork);
if (efw->registered) {
snd_card_free_when_closed(efw->card);
} else {
efw_free(efw);
}
}
static int __init snd_efw_init(void)
{
int err;
err = snd_efw_transaction_register();
if (err < 0)
goto end;
err = driver_register(&efw_driver.driver);
if (err < 0)
snd_efw_transaction_unregister();
end:
return err;
}
static void __exit snd_efw_exit(void)
{
snd_efw_transaction_unregister();
driver_unregister(&efw_driver.driver);
}
