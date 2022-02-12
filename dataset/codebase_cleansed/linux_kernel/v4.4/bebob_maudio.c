int snd_bebob_maudio_load_firmware(struct fw_unit *unit)
{
struct fw_device *device = fw_parent_device(unit);
int err, rcode;
u64 date;
__le32 cues[3] = {
cpu_to_le32(MAUDIO_BOOTLOADER_CUE1),
cpu_to_le32(MAUDIO_BOOTLOADER_CUE2),
cpu_to_le32(MAUDIO_BOOTLOADER_CUE3)
};
err = snd_bebob_read_block(unit, INFO_OFFSET_SW_DATE,
&date, sizeof(u64));
if (err < 0)
goto end;
if (date < 0x3230303730343031LL) {
dev_err(&unit->device,
"Use firmware version 5058 or later\n");
err = -ENOSYS;
goto end;
}
rcode = fw_run_transaction(device->card, TCODE_WRITE_BLOCK_REQUEST,
device->node_id, device->generation,
device->max_speed, BEBOB_ADDR_REG_REQ,
cues, sizeof(cues));
if (rcode != RCODE_COMPLETE) {
dev_err(&unit->device,
"Failed to send a cue to load firmware\n");
err = -EIO;
}
end:
return err;
}
static inline int
get_meter(struct snd_bebob *bebob, void *buf, unsigned int size)
{
return snd_fw_transaction(bebob->unit, TCODE_READ_BLOCK_REQUEST,
MAUDIO_SPECIFIC_ADDRESS + METER_OFFSET,
buf, size, 0);
}
static int
check_clk_sync(struct snd_bebob *bebob, unsigned int size, bool *sync)
{
int err;
u8 *buf;
buf = kmalloc(size, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
err = get_meter(bebob, buf, size);
if (err < 0)
goto end;
*sync = (buf[size - 2] != 0xff);
end:
kfree(buf);
return err;
}
static int
avc_maudio_set_special_clk(struct snd_bebob *bebob, unsigned int clk_src,
unsigned int dig_in_fmt, unsigned int dig_out_fmt,
unsigned int clk_lock)
{
struct special_params *params = bebob->maudio_special_quirk;
int err;
u8 *buf;
if (amdtp_stream_running(&bebob->rx_stream) ||
amdtp_stream_running(&bebob->tx_stream))
return -EBUSY;
buf = kmalloc(12, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
buf[0] = 0x00;
buf[1] = 0xff;
buf[2] = 0x00;
buf[3] = 0x04;
buf[4] = 0x00;
buf[5] = 0x04;
buf[6] = 0xff & clk_src;
buf[7] = 0xff & dig_in_fmt;
buf[8] = 0xff & dig_out_fmt;
buf[9] = 0xff & clk_lock;
buf[10] = 0x00;
buf[11] = 0x00;
err = fcp_avc_transaction(bebob->unit, buf, 12, buf, 12,
BIT(1) | BIT(2) | BIT(3) | BIT(4) |
BIT(5) | BIT(6) | BIT(7) | BIT(8) |
BIT(9));
if ((err > 0) && (err < 10))
err = -EIO;
else if (buf[0] == 0x08)
err = -ENOSYS;
else if (buf[0] == 0x0a)
err = -EINVAL;
if (err < 0)
goto end;
params->clk_src = buf[6];
params->dig_in_fmt = buf[7];
params->dig_out_fmt = buf[8];
params->clk_lock = buf[9];
if (params->ctl_id_sync)
snd_ctl_notify(bebob->card, SNDRV_CTL_EVENT_MASK_VALUE,
params->ctl_id_sync);
err = 0;
end:
kfree(buf);
return err;
}
static void
special_stream_formation_set(struct snd_bebob *bebob)
{
static const unsigned int ch_table[2][2][3] = {
{ { 6, 6, 4 },
{ 12, 8, 4 } },
{ { 10, 10, 2 },
{ 16, 12, 2 } }
};
struct special_params *params = bebob->maudio_special_quirk;
unsigned int i, max;
max = SND_BEBOB_STRM_FMT_ENTRIES - 1;
if (!params->is1814)
max -= 2;
for (i = 0; i < max; i++) {
bebob->tx_stream_formations[i + 1].pcm =
ch_table[AMDTP_IN_STREAM][params->dig_in_fmt][i / 2];
bebob->tx_stream_formations[i + 1].midi = 1;
bebob->rx_stream_formations[i + 1].pcm =
ch_table[AMDTP_OUT_STREAM][params->dig_out_fmt][i / 2];
bebob->rx_stream_formations[i + 1].midi = 1;
}
}
int
snd_bebob_maudio_special_discover(struct snd_bebob *bebob, bool is1814)
{
struct special_params *params;
int err;
params = kzalloc(sizeof(struct special_params), GFP_KERNEL);
if (params == NULL)
return -ENOMEM;
mutex_lock(&bebob->mutex);
bebob->maudio_special_quirk = (void *)params;
params->is1814 = is1814;
bebob->rx_stream.context = ERR_PTR(-1);
bebob->tx_stream.context = ERR_PTR(-1);
err = avc_maudio_set_special_clk(bebob, 0x03, 0x00, 0x00, 0x00);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to initialize clock params: %d\n", err);
goto end;
}
err = add_special_controls(bebob);
if (err < 0)
goto end;
special_stream_formation_set(bebob);
if (params->is1814) {
bebob->midi_input_ports = 1;
bebob->midi_output_ports = 1;
} else {
bebob->midi_input_ports = 2;
bebob->midi_output_ports = 2;
}
end:
if (err < 0) {
kfree(params);
bebob->maudio_special_quirk = NULL;
}
mutex_unlock(&bebob->mutex);
return err;
}
static int special_get_rate(struct snd_bebob *bebob, unsigned int *rate)
{
int err, trials;
trials = 0;
do {
err = avc_general_get_sig_fmt(bebob->unit, rate,
AVC_GENERAL_PLUG_DIR_IN, 0);
} while (err == -EAGAIN && ++trials < 3);
return err;
}
static int special_set_rate(struct snd_bebob *bebob, unsigned int rate)
{
struct special_params *params = bebob->maudio_special_quirk;
int err;
err = avc_general_set_sig_fmt(bebob->unit, rate,
AVC_GENERAL_PLUG_DIR_OUT, 0);
if (err < 0)
goto end;
msleep(100);
err = avc_general_set_sig_fmt(bebob->unit, rate,
AVC_GENERAL_PLUG_DIR_IN, 0);
if (err < 0)
goto end;
if (params->ctl_id_sync)
snd_ctl_notify(bebob->card, SNDRV_CTL_EVENT_MASK_VALUE,
params->ctl_id_sync);
end:
return err;
}
static int special_clk_get(struct snd_bebob *bebob, unsigned int *id)
{
struct special_params *params = bebob->maudio_special_quirk;
*id = params->clk_src;
return 0;
}
static int special_clk_ctl_info(struct snd_kcontrol *kctl,
struct snd_ctl_elem_info *einf)
{
static const char *const special_clk_labels[] = {
"Internal with Digital Mute",
"Digital",
"Word Clock",
"Internal"
};
return snd_ctl_enum_info(einf, 1, ARRAY_SIZE(special_clk_types),
special_clk_labels);
}
static int special_clk_ctl_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uval)
{
struct snd_bebob *bebob = snd_kcontrol_chip(kctl);
struct special_params *params = bebob->maudio_special_quirk;
uval->value.enumerated.item[0] = params->clk_src;
return 0;
}
static int special_clk_ctl_put(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uval)
{
struct snd_bebob *bebob = snd_kcontrol_chip(kctl);
struct special_params *params = bebob->maudio_special_quirk;
int err, id;
id = uval->value.enumerated.item[0];
if (id >= ARRAY_SIZE(special_clk_types))
return -EINVAL;
mutex_lock(&bebob->mutex);
err = avc_maudio_set_special_clk(bebob, id,
params->dig_in_fmt,
params->dig_out_fmt,
params->clk_lock);
mutex_unlock(&bebob->mutex);
if (err >= 0)
err = 1;
return err;
}
static int special_sync_ctl_info(struct snd_kcontrol *kctl,
struct snd_ctl_elem_info *einf)
{
einf->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
einf->count = 1;
einf->value.integer.min = 0;
einf->value.integer.max = 1;
return 0;
}
static int special_sync_ctl_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uval)
{
struct snd_bebob *bebob = snd_kcontrol_chip(kctl);
int err;
bool synced = 0;
err = check_clk_sync(bebob, METER_SIZE_SPECIAL, &synced);
if (err >= 0)
uval->value.integer.value[0] = synced;
return 0;
}
static int special_dig_in_iface_ctl_info(struct snd_kcontrol *kctl,
struct snd_ctl_elem_info *einf)
{
return snd_ctl_enum_info(einf, 1,
ARRAY_SIZE(special_dig_in_iface_labels),
special_dig_in_iface_labels);
}
static int special_dig_in_iface_ctl_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uval)
{
struct snd_bebob *bebob = snd_kcontrol_chip(kctl);
struct special_params *params = bebob->maudio_special_quirk;
unsigned int dig_in_iface;
int err, val;
mutex_lock(&bebob->mutex);
err = avc_audio_get_selector(bebob->unit, 0x00, 0x04,
&dig_in_iface);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get digital input interface: %d\n", err);
goto end;
}
val = (params->dig_in_fmt << 1) | (dig_in_iface & 0x01);
if (val > 2)
val = 2;
uval->value.enumerated.item[0] = val;
end:
mutex_unlock(&bebob->mutex);
return err;
}
static int special_dig_in_iface_ctl_set(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uval)
{
struct snd_bebob *bebob = snd_kcontrol_chip(kctl);
struct special_params *params = bebob->maudio_special_quirk;
unsigned int id, dig_in_fmt, dig_in_iface;
int err;
id = uval->value.enumerated.item[0];
if (id >= ARRAY_SIZE(special_dig_in_iface_labels))
return -EINVAL;
dig_in_fmt = (id >> 1) & 0x01;
dig_in_iface = id & 0x01;
mutex_lock(&bebob->mutex);
err = avc_maudio_set_special_clk(bebob,
params->clk_src,
dig_in_fmt,
params->dig_out_fmt,
params->clk_lock);
if (err < 0)
goto end;
if (params->dig_in_fmt > 0) {
err = 1;
goto end;
}
err = avc_audio_set_selector(bebob->unit, 0x00, 0x04, dig_in_iface);
if (err < 0)
dev_err(&bebob->unit->device,
"fail to set digital input interface: %d\n", err);
err = 1;
end:
special_stream_formation_set(bebob);
mutex_unlock(&bebob->mutex);
return err;
}
static int special_dig_out_iface_ctl_info(struct snd_kcontrol *kctl,
struct snd_ctl_elem_info *einf)
{
return snd_ctl_enum_info(einf, 1,
ARRAY_SIZE(special_dig_out_iface_labels),
special_dig_out_iface_labels);
}
static int special_dig_out_iface_ctl_get(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uval)
{
struct snd_bebob *bebob = snd_kcontrol_chip(kctl);
struct special_params *params = bebob->maudio_special_quirk;
mutex_lock(&bebob->mutex);
uval->value.enumerated.item[0] = params->dig_out_fmt;
mutex_unlock(&bebob->mutex);
return 0;
}
static int special_dig_out_iface_ctl_set(struct snd_kcontrol *kctl,
struct snd_ctl_elem_value *uval)
{
struct snd_bebob *bebob = snd_kcontrol_chip(kctl);
struct special_params *params = bebob->maudio_special_quirk;
unsigned int id;
int err;
id = uval->value.enumerated.item[0];
if (id >= ARRAY_SIZE(special_dig_out_iface_labels))
return -EINVAL;
mutex_lock(&bebob->mutex);
err = avc_maudio_set_special_clk(bebob,
params->clk_src,
params->dig_in_fmt,
id, params->clk_lock);
if (err >= 0) {
special_stream_formation_set(bebob);
err = 1;
}
mutex_unlock(&bebob->mutex);
return err;
}
static int add_special_controls(struct snd_bebob *bebob)
{
struct snd_kcontrol *kctl;
struct special_params *params = bebob->maudio_special_quirk;
int err;
kctl = snd_ctl_new1(&special_clk_ctl, bebob);
err = snd_ctl_add(bebob->card, kctl);
if (err < 0)
goto end;
kctl = snd_ctl_new1(&special_sync_ctl, bebob);
err = snd_ctl_add(bebob->card, kctl);
if (err < 0)
goto end;
params->ctl_id_sync = &kctl->id;
kctl = snd_ctl_new1(&special_dig_in_iface_ctl, bebob);
err = snd_ctl_add(bebob->card, kctl);
if (err < 0)
goto end;
kctl = snd_ctl_new1(&special_dig_out_iface_ctl, bebob);
err = snd_ctl_add(bebob->card, kctl);
end:
return err;
}
static int
special_meter_get(struct snd_bebob *bebob, u32 *target, unsigned int size)
{
__be16 *buf;
unsigned int i, c, channels;
int err;
channels = ARRAY_SIZE(special_meter_labels) * 2;
if (size < channels * sizeof(u32))
return -EINVAL;
buf = kmalloc(METER_SIZE_SPECIAL - 4, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
err = get_meter(bebob, (void *)buf, METER_SIZE_SPECIAL - 4);
if (err < 0)
goto end;
i = 0;
for (c = 2; c < channels + 2; c++)
target[i++] = be16_to_cpu(buf[c]) << 16;
end:
kfree(buf);
return err;
}
static int
normal_meter_get(struct snd_bebob *bebob, u32 *buf, unsigned int size)
{
const struct snd_bebob_meter_spec *spec = bebob->spec->meter;
unsigned int c, channels;
int err;
channels = spec->num * 2;
if (size < channels * sizeof(u32))
return -EINVAL;
err = get_meter(bebob, (void *)buf, size);
if (err < 0)
goto end;
for (c = 0; c < channels; c++)
be32_to_cpus(&buf[c]);
if (spec->labels == solo_meter_labels) {
swap(buf[4], buf[6]);
swap(buf[5], buf[7]);
}
end:
return err;
}
