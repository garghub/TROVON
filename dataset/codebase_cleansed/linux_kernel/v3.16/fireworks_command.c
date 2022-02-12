static int
efw_transaction(struct snd_efw *efw, unsigned int category,
unsigned int command,
const __be32 *params, unsigned int param_bytes,
const __be32 *resp, unsigned int resp_bytes)
{
struct snd_efw_transaction *header;
__be32 *buf;
u32 seqnum;
unsigned int buf_bytes, cmd_bytes;
int err;
buf_bytes = sizeof(struct snd_efw_transaction) +
max(param_bytes, resp_bytes);
buf = kzalloc(buf_bytes, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
spin_lock(&efw->lock);
if ((efw->seqnum < KERNEL_SEQNUM_MIN) ||
(efw->seqnum >= KERNEL_SEQNUM_MAX - 2))
efw->seqnum = KERNEL_SEQNUM_MIN;
else
efw->seqnum += 2;
seqnum = efw->seqnum;
spin_unlock(&efw->lock);
cmd_bytes = sizeof(struct snd_efw_transaction) + param_bytes;
header = (struct snd_efw_transaction *)buf;
header->length = cpu_to_be32(cmd_bytes / sizeof(__be32));
header->version = cpu_to_be32(1);
header->seqnum = cpu_to_be32(seqnum);
header->category = cpu_to_be32(category);
header->command = cpu_to_be32(command);
header->status = 0;
memcpy(header->params, params, param_bytes);
err = snd_efw_transaction_run(efw->unit, buf, cmd_bytes,
buf, buf_bytes);
if (err < 0)
goto end;
if ((be32_to_cpu(header->version) < 1) ||
(be32_to_cpu(header->category) != category) ||
(be32_to_cpu(header->command) != command) ||
(be32_to_cpu(header->status) != EFR_STATUS_OK)) {
dev_err(&efw->unit->device, "EFW command failed [%u/%u]: %s\n",
be32_to_cpu(header->category),
be32_to_cpu(header->command),
efr_status_names[be32_to_cpu(header->status)]);
err = -EIO;
goto end;
}
if (resp == NULL)
goto end;
memset((void *)resp, 0, resp_bytes);
resp_bytes = min_t(unsigned int, resp_bytes,
be32_to_cpu(header->length) * sizeof(__be32) -
sizeof(struct snd_efw_transaction));
memcpy((void *)resp, &buf[6], resp_bytes);
end:
kfree(buf);
return err;
}
int snd_efw_command_set_resp_addr(struct snd_efw *efw,
u16 addr_high, u32 addr_low)
{
__be32 addr[2];
addr[0] = cpu_to_be32(addr_high);
addr[1] = cpu_to_be32(addr_low);
if (!efw->resp_addr_changable)
return -ENOSYS;
return efw_transaction(efw, EFC_CAT_HWCTL,
EFC_CMD_HWINFO_SET_RESP_ADDR,
addr, sizeof(addr), NULL, 0);
}
int snd_efw_command_set_tx_mode(struct snd_efw *efw,
enum snd_efw_transport_mode mode)
{
__be32 param = cpu_to_be32(mode);
return efw_transaction(efw, EFC_CAT_TRANSPORT,
EFC_CMD_TRANSPORT_SET_TX_MODE,
&param, sizeof(param), NULL, 0);
}
int snd_efw_command_get_hwinfo(struct snd_efw *efw,
struct snd_efw_hwinfo *hwinfo)
{
int err;
err = efw_transaction(efw, EFC_CAT_HWINFO,
EFC_CMD_HWINFO_GET_CAPS,
NULL, 0, (__be32 *)hwinfo, sizeof(*hwinfo));
if (err < 0)
goto end;
be32_to_cpus(&hwinfo->flags);
be32_to_cpus(&hwinfo->guid_hi);
be32_to_cpus(&hwinfo->guid_lo);
be32_to_cpus(&hwinfo->type);
be32_to_cpus(&hwinfo->version);
be32_to_cpus(&hwinfo->supported_clocks);
be32_to_cpus(&hwinfo->amdtp_rx_pcm_channels);
be32_to_cpus(&hwinfo->amdtp_tx_pcm_channels);
be32_to_cpus(&hwinfo->phys_out);
be32_to_cpus(&hwinfo->phys_in);
be32_to_cpus(&hwinfo->phys_out_grp_count);
be32_to_cpus(&hwinfo->phys_in_grp_count);
be32_to_cpus(&hwinfo->midi_out_ports);
be32_to_cpus(&hwinfo->midi_in_ports);
be32_to_cpus(&hwinfo->max_sample_rate);
be32_to_cpus(&hwinfo->min_sample_rate);
be32_to_cpus(&hwinfo->dsp_version);
be32_to_cpus(&hwinfo->arm_version);
be32_to_cpus(&hwinfo->mixer_playback_channels);
be32_to_cpus(&hwinfo->mixer_capture_channels);
be32_to_cpus(&hwinfo->fpga_version);
be32_to_cpus(&hwinfo->amdtp_rx_pcm_channels_2x);
be32_to_cpus(&hwinfo->amdtp_tx_pcm_channels_2x);
be32_to_cpus(&hwinfo->amdtp_rx_pcm_channels_4x);
be32_to_cpus(&hwinfo->amdtp_tx_pcm_channels_4x);
hwinfo->vendor_name[HWINFO_NAME_SIZE_BYTES - 1] = '\0';
hwinfo->model_name[HWINFO_NAME_SIZE_BYTES - 1] = '\0';
end:
return err;
}
int snd_efw_command_get_phys_meters(struct snd_efw *efw,
struct snd_efw_phys_meters *meters,
unsigned int len)
{
__be32 *buf = (__be32 *)meters;
unsigned int i;
int err;
err = efw_transaction(efw, EFC_CAT_HWINFO,
EFC_CMD_HWINFO_GET_POLLED,
NULL, 0, (__be32 *)meters, len);
if (err >= 0)
for (i = 0; i < len / sizeof(u32); i++)
be32_to_cpus(&buf[i]);
return err;
}
static int
command_get_clock(struct snd_efw *efw, struct efc_clock *clock)
{
int err;
err = efw_transaction(efw, EFC_CAT_HWCTL,
EFC_CMD_HWCTL_GET_CLOCK,
NULL, 0,
(__be32 *)clock, sizeof(struct efc_clock));
if (err >= 0) {
be32_to_cpus(&clock->source);
be32_to_cpus(&clock->sampling_rate);
be32_to_cpus(&clock->index);
}
return err;
}
static int
command_set_clock(struct snd_efw *efw,
unsigned int source, unsigned int rate)
{
struct efc_clock clock = {0};
int err;
if ((source == UINT_MAX) && (rate == UINT_MAX)) {
err = -EINVAL;
goto end;
}
err = command_get_clock(efw, &clock);
if (err < 0)
goto end;
if ((clock.source == source) && (clock.sampling_rate == rate))
goto end;
if ((source != UINT_MAX) && (clock.source != source))
clock.source = source;
if ((rate != UINT_MAX) && (clock.sampling_rate != rate))
clock.sampling_rate = rate;
clock.index = 0;
cpu_to_be32s(&clock.source);
cpu_to_be32s(&clock.sampling_rate);
cpu_to_be32s(&clock.index);
err = efw_transaction(efw, EFC_CAT_HWCTL,
EFC_CMD_HWCTL_SET_CLOCK,
(__be32 *)&clock, sizeof(struct efc_clock),
NULL, 0);
if (err < 0)
goto end;
msleep(150);
end:
return err;
}
int snd_efw_command_get_clock_source(struct snd_efw *efw,
enum snd_efw_clock_source *source)
{
int err;
struct efc_clock clock = {0};
err = command_get_clock(efw, &clock);
if (err >= 0)
*source = clock.source;
return err;
}
int snd_efw_command_get_sampling_rate(struct snd_efw *efw, unsigned int *rate)
{
int err;
struct efc_clock clock = {0};
err = command_get_clock(efw, &clock);
if (err >= 0)
*rate = clock.sampling_rate;
return err;
}
int snd_efw_command_set_sampling_rate(struct snd_efw *efw, unsigned int rate)
{
return command_set_clock(efw, UINT_MAX, rate);
}
