static int v2_get_clock_rate(struct snd_motu *motu, unsigned int *rate)
{
__be32 reg;
unsigned int index;
int err;
err = snd_motu_transaction_read(motu, V2_CLOCK_STATUS_OFFSET, &reg,
sizeof(reg));
if (err < 0)
return err;
index = (be32_to_cpu(reg) & V2_CLOCK_RATE_MASK) >> V2_CLOCK_RATE_SHIFT;
if (index >= ARRAY_SIZE(snd_motu_clock_rates))
return -EIO;
*rate = snd_motu_clock_rates[index];
return 0;
}
static int v2_set_clock_rate(struct snd_motu *motu, unsigned int rate)
{
__be32 reg;
u32 data;
int i;
int err;
for (i = 0; i < ARRAY_SIZE(snd_motu_clock_rates); ++i) {
if (snd_motu_clock_rates[i] == rate)
break;
}
if (i == ARRAY_SIZE(snd_motu_clock_rates))
return -EINVAL;
err = snd_motu_transaction_read(motu, V2_CLOCK_STATUS_OFFSET, &reg,
sizeof(reg));
if (err < 0)
return err;
data = be32_to_cpu(reg);
data &= ~V2_CLOCK_RATE_MASK;
data |= i << V2_CLOCK_RATE_SHIFT;
reg = cpu_to_be32(data);
return snd_motu_transaction_write(motu, V2_CLOCK_STATUS_OFFSET, &reg,
sizeof(reg));
}
static int v2_get_clock_source(struct snd_motu *motu,
enum snd_motu_clock_source *src)
{
__be32 reg;
unsigned int index;
int err;
err = snd_motu_transaction_read(motu, V2_CLOCK_STATUS_OFFSET, &reg,
sizeof(reg));
if (err < 0)
return err;
index = be32_to_cpu(reg) & V2_CLOCK_SRC_MASK;
if (index > 5)
return -EIO;
err = snd_motu_transaction_read(motu, V2_IN_OUT_CONF_OFFSET, &reg,
sizeof(reg));
if (err < 0)
return err;
switch (index) {
case 0:
*src = SND_MOTU_CLOCK_SOURCE_INTERNAL;
break;
case 1:
if (be32_to_cpu(reg) & 0x00000200)
*src = SND_MOTU_CLOCK_SOURCE_SPDIF_ON_OPT;
else
*src = SND_MOTU_CLOCK_SOURCE_ADAT_ON_OPT;
break;
case 2:
*src = SND_MOTU_CLOCK_SOURCE_SPDIF_ON_COAX;
break;
case 4:
*src = SND_MOTU_CLOCK_SOURCE_WORD_ON_BNC;
break;
case 5:
*src = SND_MOTU_CLOCK_SOURCE_ADAT_ON_DSUB;
break;
default:
return -EIO;
}
return 0;
}
static int v2_switch_fetching_mode(struct snd_motu *motu, bool enable)
{
return 0;
}
static void calculate_fixed_part(struct snd_motu_packet_format *formats,
enum amdtp_stream_direction dir,
enum snd_motu_spec_flags flags,
unsigned char analog_ports)
{
unsigned char pcm_chunks[3] = {0, 0, 0};
formats->msg_chunks = 2;
pcm_chunks[0] = analog_ports;
pcm_chunks[1] = analog_ports;
if (flags & SND_MOTU_SPEC_SUPPORT_CLOCK_X4)
pcm_chunks[2] = analog_ports;
if (dir == AMDTP_IN_STREAM) {
if (flags & SND_MOTU_SPEC_TX_MICINST_CHUNK) {
pcm_chunks[0] += 2;
pcm_chunks[1] += 2;
}
if (flags & SND_MOTU_SPEC_TX_RETURN_CHUNK) {
pcm_chunks[0] += 2;
pcm_chunks[1] += 2;
}
} else {
pcm_chunks[0] += 4;
pcm_chunks[1] += 4;
}
pcm_chunks[0] += 2;
pcm_chunks[1] += 2;
formats->fixed_part_pcm_chunks[0] = round_up(2 + pcm_chunks[0], 4) - 2;
formats->fixed_part_pcm_chunks[1] = round_up(2 + pcm_chunks[1], 4) - 2;
if (flags & SND_MOTU_SPEC_SUPPORT_CLOCK_X4)
formats->fixed_part_pcm_chunks[2] =
round_up(2 + pcm_chunks[2], 4) - 2;
}
static void calculate_differed_part(struct snd_motu_packet_format *formats,
enum snd_motu_spec_flags flags,
u32 data, u32 mask, u32 shift)
{
unsigned char pcm_chunks[3] = {0, 0};
data = (data & mask) >> shift;
if ((flags & SND_MOTU_SPEC_HAS_OPT_IFACE_A) &&
data == V2_OPT_IFACE_MODE_ADAT) {
pcm_chunks[0] += 8;
pcm_chunks[1] += 4;
}
formats->differed_part_pcm_chunks[0] = pcm_chunks[0];
formats->differed_part_pcm_chunks[1] = pcm_chunks[1];
}
static int v2_cache_packet_formats(struct snd_motu *motu)
{
__be32 reg;
u32 data;
int err;
err = snd_motu_transaction_read(motu, V2_IN_OUT_CONF_OFFSET, &reg,
sizeof(reg));
if (err < 0)
return err;
data = be32_to_cpu(reg);
calculate_fixed_part(&motu->tx_packet_formats, AMDTP_IN_STREAM,
motu->spec->flags, motu->spec->analog_in_ports);
calculate_differed_part(&motu->tx_packet_formats, motu->spec->flags,
data, V2_OPT_IN_IFACE_MASK, V2_OPT_IN_IFACE_SHIFT);
calculate_fixed_part(&motu->rx_packet_formats, AMDTP_OUT_STREAM,
motu->spec->flags, motu->spec->analog_out_ports);
calculate_differed_part(&motu->rx_packet_formats, motu->spec->flags,
data, V2_OPT_OUT_IFACE_MASK, V2_OPT_OUT_IFACE_SHIFT);
motu->tx_packet_formats.midi_flag_offset = 4;
motu->tx_packet_formats.midi_byte_offset = 6;
motu->tx_packet_formats.pcm_byte_offset = 10;
motu->rx_packet_formats.midi_flag_offset = 4;
motu->rx_packet_formats.midi_byte_offset = 6;
motu->rx_packet_formats.pcm_byte_offset = 10;
return 0;
}
