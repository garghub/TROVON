static int ff400_get_clock(struct snd_ff *ff, unsigned int *rate,
enum snd_ff_clock_src *src)
{
__le32 reg;
u32 data;
int err;
err = snd_fw_transaction(ff->unit, TCODE_READ_QUADLET_REQUEST,
FF400_SYNC_STATUS, &reg, sizeof(reg), 0);
if (err < 0)
return err;
data = le32_to_cpu(reg);
switch ((data >> 1) & 0x03) {
case 0x01:
*rate = 32000;
break;
case 0x00:
*rate = 44100;
break;
case 0x03:
*rate = 48000;
break;
case 0x02:
default:
return -EIO;
}
if (data & 0x08)
*rate *= 2;
else if (data & 0x10)
*rate *= 4;
if (data & 0x01) {
*src = SND_FF_CLOCK_SRC_INTERNAL;
} else {
switch ((data >> 10) & 0x07) {
case 0x03:
*src = SND_FF_CLOCK_SRC_SPDIF;
break;
case 0x04:
*src = SND_FF_CLOCK_SRC_WORD;
break;
case 0x05:
*src = SND_FF_CLOCK_SRC_LTC;
break;
case 0x00:
default:
*src = SND_FF_CLOCK_SRC_ADAT;
break;
}
}
return 0;
}
static int ff400_begin_session(struct snd_ff *ff, unsigned int rate)
{
__le32 reg;
int i, err;
for (i = 0; i < CIP_SFC_COUNT; i++) {
if (amdtp_rate_table[i] == rate)
break;
}
if (i == CIP_SFC_COUNT)
return -EINVAL;
reg = cpu_to_le32(rate);
err = snd_fw_transaction(ff->unit, TCODE_WRITE_QUADLET_REQUEST,
FF400_STF, &reg, sizeof(reg), 0);
if (err < 0)
return err;
msleep(100);
reg = cpu_to_le32(((ff->rx_stream.data_block_quadlets << 3) << 8) |
ff->rx_resources.channel);
err = snd_fw_transaction(ff->unit, TCODE_WRITE_QUADLET_REQUEST,
FF400_RX_PACKET_FORMAT, &reg, sizeof(reg), 0);
if (err < 0)
return err;
reg = cpu_to_le32((0x80 << 24) |
(ff->tx_resources.channel << 5) |
(ff->tx_stream.data_block_quadlets));
err = snd_fw_transaction(ff->unit, TCODE_WRITE_QUADLET_REQUEST,
FF400_TX_PACKET_FORMAT, &reg, sizeof(reg), 0);
if (err < 0)
return err;
reg = cpu_to_le32(0x00000001);
return snd_fw_transaction(ff->unit, TCODE_WRITE_QUADLET_REQUEST,
FF400_ISOC_COMM_START, &reg, sizeof(reg), 0);
}
static void ff400_finish_session(struct snd_ff *ff)
{
__le32 reg;
reg = cpu_to_le32(0x80000000);
snd_fw_transaction(ff->unit, TCODE_WRITE_QUADLET_REQUEST,
FF400_ISOC_COMM_STOP, &reg, sizeof(reg), 0);
}
static int ff400_switch_fetching_mode(struct snd_ff *ff, bool enable)
{
__le32 *reg;
int i;
reg = kzalloc(sizeof(__le32) * 18, GFP_KERNEL);
if (reg == NULL)
return -ENOMEM;
if (enable) {
for (i = 0; i < 18; ++i)
reg[i] = cpu_to_le32(0x00000001);
}
return snd_fw_transaction(ff->unit, TCODE_WRITE_BLOCK_REQUEST,
FF400_FETCH_PCM_FRAMES, reg,
sizeof(__le32) * 18, 0);
}
static void ff400_dump_sync_status(struct snd_ff *ff,
struct snd_info_buffer *buffer)
{
__le32 reg;
u32 data;
int err;
err = snd_fw_transaction(ff->unit, TCODE_READ_QUADLET_REQUEST,
FF400_SYNC_STATUS, &reg, sizeof(reg), 0);
if (err < 0)
return;
data = le32_to_cpu(reg);
snd_iprintf(buffer, "External source detection:\n");
snd_iprintf(buffer, "Word Clock:");
if ((data >> 24) & 0x20) {
if ((data >> 24) & 0x40)
snd_iprintf(buffer, "sync\n");
else
snd_iprintf(buffer, "lock\n");
} else {
snd_iprintf(buffer, "none\n");
}
snd_iprintf(buffer, "S/PDIF:");
if ((data >> 16) & 0x10) {
if ((data >> 16) & 0x04)
snd_iprintf(buffer, "sync\n");
else
snd_iprintf(buffer, "lock\n");
} else {
snd_iprintf(buffer, "none\n");
}
snd_iprintf(buffer, "ADAT:");
if ((data >> 8) & 0x04) {
if ((data >> 8) & 0x10)
snd_iprintf(buffer, "sync\n");
else
snd_iprintf(buffer, "lock\n");
} else {
snd_iprintf(buffer, "none\n");
}
snd_iprintf(buffer, "\nUsed external source:\n");
if (((data >> 22) & 0x07) == 0x07) {
snd_iprintf(buffer, "None\n");
} else {
switch ((data >> 22) & 0x07) {
case 0x00:
snd_iprintf(buffer, "ADAT:");
break;
case 0x03:
snd_iprintf(buffer, "S/PDIF:");
break;
case 0x04:
snd_iprintf(buffer, "Word:");
break;
case 0x07:
snd_iprintf(buffer, "Nothing:");
break;
case 0x01:
case 0x02:
case 0x05:
case 0x06:
default:
snd_iprintf(buffer, "unknown:");
break;
}
if ((data >> 25) & 0x07) {
switch ((data >> 25) & 0x07) {
case 0x01:
snd_iprintf(buffer, "32000\n");
break;
case 0x02:
snd_iprintf(buffer, "44100\n");
break;
case 0x03:
snd_iprintf(buffer, "48000\n");
break;
case 0x04:
snd_iprintf(buffer, "64000\n");
break;
case 0x05:
snd_iprintf(buffer, "88200\n");
break;
case 0x06:
snd_iprintf(buffer, "96000\n");
break;
case 0x07:
snd_iprintf(buffer, "128000\n");
break;
case 0x08:
snd_iprintf(buffer, "176400\n");
break;
case 0x09:
snd_iprintf(buffer, "192000\n");
break;
case 0x00:
snd_iprintf(buffer, "unknown\n");
break;
}
}
}
snd_iprintf(buffer, "Multiplied:");
snd_iprintf(buffer, "%d\n", (data & 0x3ff) * 250);
}
static void ff400_dump_clock_config(struct snd_ff *ff,
struct snd_info_buffer *buffer)
{
__le32 reg;
u32 data;
unsigned int rate;
const char *src;
int err;
err = snd_fw_transaction(ff->unit, TCODE_READ_BLOCK_REQUEST,
FF400_CLOCK_CONFIG, &reg, sizeof(reg), 0);
if (err < 0)
return;
data = le32_to_cpu(reg);
snd_iprintf(buffer, "Output S/PDIF format: %s (Emphasis: %s)\n",
(data & 0x20) ? "Professional" : "Consumer",
(data & 0x40) ? "on" : "off");
snd_iprintf(buffer, "Optical output interface format: %s\n",
((data >> 8) & 0x01) ? "S/PDIF" : "ADAT");
snd_iprintf(buffer, "Word output single speed: %s\n",
((data >> 8) & 0x20) ? "on" : "off");
snd_iprintf(buffer, "S/PDIF input interface: %s\n",
((data >> 8) & 0x02) ? "Optical" : "Coaxial");
switch ((data >> 1) & 0x03) {
case 0x01:
rate = 32000;
break;
case 0x00:
rate = 44100;
break;
case 0x03:
rate = 48000;
break;
case 0x02:
default:
return;
}
if (data & 0x08)
rate *= 2;
else if (data & 0x10)
rate *= 4;
snd_iprintf(buffer, "Sampling rate: %d\n", rate);
if (data & 0x01) {
src = "Internal";
} else {
switch ((data >> 10) & 0x07) {
case 0x00:
src = "ADAT";
break;
case 0x03:
src = "S/PDIF";
break;
case 0x04:
src = "Word";
break;
case 0x05:
src = "LTC";
break;
default:
return;
}
}
snd_iprintf(buffer, "Sync to clock source: %s\n", src);
}
