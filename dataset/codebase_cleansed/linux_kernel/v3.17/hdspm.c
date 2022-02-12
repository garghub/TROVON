static inline int HDSPM_bit2freq(int n)
{
static const int bit2freq_tab[] = {
0, 32000, 44100, 48000, 64000, 88200,
96000, 128000, 176400, 192000 };
if (n < 1 || n > 9)
return 0;
return bit2freq_tab[n];
}
static bool hdspm_is_raydat_or_aio(struct hdspm *hdspm)
{
return ((AIO == hdspm->io_type) || (RayDAT == hdspm->io_type));
}
static inline void hdspm_write(struct hdspm * hdspm, unsigned int reg,
unsigned int val)
{
writel(val, hdspm->iobase + reg);
}
static inline unsigned int hdspm_read(struct hdspm * hdspm, unsigned int reg)
{
return readl(hdspm->iobase + reg);
}
static inline int hdspm_read_in_gain(struct hdspm * hdspm, unsigned int chan,
unsigned int in)
{
if (chan >= HDSPM_MIXER_CHANNELS || in >= HDSPM_MIXER_CHANNELS)
return 0;
return hdspm->mixer->ch[chan].in[in];
}
static inline int hdspm_read_pb_gain(struct hdspm * hdspm, unsigned int chan,
unsigned int pb)
{
if (chan >= HDSPM_MIXER_CHANNELS || pb >= HDSPM_MIXER_CHANNELS)
return 0;
return hdspm->mixer->ch[chan].pb[pb];
}
static int hdspm_write_in_gain(struct hdspm *hdspm, unsigned int chan,
unsigned int in, unsigned short data)
{
if (chan >= HDSPM_MIXER_CHANNELS || in >= HDSPM_MIXER_CHANNELS)
return -1;
hdspm_write(hdspm,
HDSPM_MADI_mixerBase +
((in + 128 * chan) * sizeof(u32)),
(hdspm->mixer->ch[chan].in[in] = data & 0xFFFF));
return 0;
}
static int hdspm_write_pb_gain(struct hdspm *hdspm, unsigned int chan,
unsigned int pb, unsigned short data)
{
if (chan >= HDSPM_MIXER_CHANNELS || pb >= HDSPM_MIXER_CHANNELS)
return -1;
hdspm_write(hdspm,
HDSPM_MADI_mixerBase +
((64 + pb + 128 * chan) * sizeof(u32)),
(hdspm->mixer->ch[chan].pb[pb] = data & 0xFFFF));
return 0;
}
static inline void snd_hdspm_enable_in(struct hdspm * hdspm, int i, int v)
{
hdspm_write(hdspm, HDSPM_inputEnableBase + (4 * i), v);
}
static inline void snd_hdspm_enable_out(struct hdspm * hdspm, int i, int v)
{
hdspm_write(hdspm, HDSPM_outputEnableBase + (4 * i), v);
}
static int snd_hdspm_use_is_exclusive(struct hdspm *hdspm)
{
unsigned long flags;
int ret = 1;
spin_lock_irqsave(&hdspm->lock, flags);
if ((hdspm->playback_pid != hdspm->capture_pid) &&
(hdspm->playback_pid >= 0) && (hdspm->capture_pid >= 0)) {
ret = 0;
}
spin_unlock_irqrestore(&hdspm->lock, flags);
return ret;
}
static int hdspm_round_frequency(int rate)
{
if (rate < 38050)
return 32000;
if (rate < 46008)
return 44100;
else
return 48000;
}
static int hdspm_rate_multiplier(struct hdspm *hdspm, int rate)
{
if (rate <= 48000) {
if (hdspm->control_register & HDSPM_QuadSpeed)
return rate * 4;
else if (hdspm->control_register &
HDSPM_DoubleSpeed)
return rate * 2;
}
return rate;
}
static int hdspm_external_sample_rate(struct hdspm *hdspm)
{
unsigned int status, status2, timecode;
int syncref, rate = 0, rate_bits;
switch (hdspm->io_type) {
case AES32:
status2 = hdspm_read(hdspm, HDSPM_statusRegister2);
status = hdspm_read(hdspm, HDSPM_statusRegister);
timecode = hdspm_read(hdspm, HDSPM_timecodeRegister);
syncref = hdspm_autosync_ref(hdspm);
switch (syncref) {
case HDSPM_AES32_AUTOSYNC_FROM_WORD:
if (hdspm_wc_sync_check(hdspm))
return HDSPM_bit2freq(hdspm_get_wc_sample_rate(hdspm));
break;
case HDSPM_AES32_AUTOSYNC_FROM_AES1:
case HDSPM_AES32_AUTOSYNC_FROM_AES2:
case HDSPM_AES32_AUTOSYNC_FROM_AES3:
case HDSPM_AES32_AUTOSYNC_FROM_AES4:
case HDSPM_AES32_AUTOSYNC_FROM_AES5:
case HDSPM_AES32_AUTOSYNC_FROM_AES6:
case HDSPM_AES32_AUTOSYNC_FROM_AES7:
case HDSPM_AES32_AUTOSYNC_FROM_AES8:
if (hdspm_aes_sync_check(hdspm, syncref - HDSPM_AES32_AUTOSYNC_FROM_AES1))
return HDSPM_bit2freq(hdspm_get_aes_sample_rate(hdspm,
syncref - HDSPM_AES32_AUTOSYNC_FROM_AES1));
break;
case HDSPM_AES32_AUTOSYNC_FROM_TCO:
if (hdspm_tco_sync_check(hdspm))
return HDSPM_bit2freq(hdspm_get_tco_sample_rate(hdspm));
break;
default:
return 0;
}
break;
case MADIface:
status = hdspm_read(hdspm, HDSPM_statusRegister);
if (!(status & HDSPM_madiLock)) {
rate = 0;
} else {
switch (status & (HDSPM_status1_freqMask)) {
case HDSPM_status1_F_0*1:
rate = 32000; break;
case HDSPM_status1_F_0*2:
rate = 44100; break;
case HDSPM_status1_F_0*3:
rate = 48000; break;
case HDSPM_status1_F_0*4:
rate = 64000; break;
case HDSPM_status1_F_0*5:
rate = 88200; break;
case HDSPM_status1_F_0*6:
rate = 96000; break;
case HDSPM_status1_F_0*7:
rate = 128000; break;
case HDSPM_status1_F_0*8:
rate = 176400; break;
case HDSPM_status1_F_0*9:
rate = 192000; break;
default:
rate = 0; break;
}
}
break;
case MADI:
case AIO:
case RayDAT:
status2 = hdspm_read(hdspm, HDSPM_statusRegister2);
status = hdspm_read(hdspm, HDSPM_statusRegister);
rate = 0;
if ((status2 & HDSPM_wcLock) != 0 &&
(status2 & HDSPM_SelSyncRef0) == 0) {
rate_bits = status2 & HDSPM_wcFreqMask;
switch (rate_bits) {
case HDSPM_wcFreq32:
rate = 32000;
break;
case HDSPM_wcFreq44_1:
rate = 44100;
break;
case HDSPM_wcFreq48:
rate = 48000;
break;
case HDSPM_wcFreq64:
rate = 64000;
break;
case HDSPM_wcFreq88_2:
rate = 88200;
break;
case HDSPM_wcFreq96:
rate = 96000;
break;
case HDSPM_wcFreq128:
rate = 128000;
break;
case HDSPM_wcFreq176_4:
rate = 176400;
break;
case HDSPM_wcFreq192:
rate = 192000;
break;
default:
rate = 0;
break;
}
}
if (rate != 0 &&
(status2 & HDSPM_SelSyncRefMask) == HDSPM_SelSyncRef_WORD)
return hdspm_rate_multiplier(hdspm, rate);
if (status & HDSPM_madiLock) {
rate_bits = status & HDSPM_madiFreqMask;
switch (rate_bits) {
case HDSPM_madiFreq32:
rate = 32000;
break;
case HDSPM_madiFreq44_1:
rate = 44100;
break;
case HDSPM_madiFreq48:
rate = 48000;
break;
case HDSPM_madiFreq64:
rate = 64000;
break;
case HDSPM_madiFreq88_2:
rate = 88200;
break;
case HDSPM_madiFreq96:
rate = 96000;
break;
case HDSPM_madiFreq128:
rate = 128000;
break;
case HDSPM_madiFreq176_4:
rate = 176400;
break;
case HDSPM_madiFreq192:
rate = 192000;
break;
default:
rate = 0;
break;
}
}
{
bool is_valid_input = 0;
bool has_sync = 0;
syncref = hdspm_autosync_ref(hdspm);
if (HDSPM_AUTOSYNC_FROM_TCO == syncref) {
is_valid_input = 1;
has_sync = (HDSPM_SYNC_CHECK_SYNC ==
hdspm_tco_sync_check(hdspm));
} else if (HDSPM_AUTOSYNC_FROM_SYNC_IN == syncref) {
is_valid_input = 1;
has_sync = (HDSPM_SYNC_CHECK_SYNC ==
hdspm_sync_in_sync_check(hdspm));
}
if (is_valid_input && has_sync) {
rate = hdspm_round_frequency(
hdspm_get_pll_freq(hdspm));
}
}
rate = hdspm_rate_multiplier(hdspm, rate);
break;
}
return rate;
}
static int hdspm_get_latency(struct hdspm *hdspm)
{
int n;
n = hdspm_decode_latency(hdspm->control_register);
if ((7 == n) && (RayDAT == hdspm->io_type || AIO == hdspm->io_type))
n = -1;
return 1 << (n + 6);
}
static inline void hdspm_compute_period_size(struct hdspm *hdspm)
{
hdspm->period_bytes = 4 * hdspm_get_latency(hdspm);
}
static snd_pcm_uframes_t hdspm_hw_pointer(struct hdspm *hdspm)
{
int position;
position = hdspm_read(hdspm, HDSPM_statusRegister);
switch (hdspm->io_type) {
case RayDAT:
case AIO:
position &= HDSPM_BufferPositionMask;
position /= 4;
break;
default:
position = (position & HDSPM_BufferID) ?
(hdspm->period_bytes / 4) : 0;
}
return position;
}
static inline void hdspm_start_audio(struct hdspm * s)
{
s->control_register |= (HDSPM_AudioInterruptEnable | HDSPM_Start);
hdspm_write(s, HDSPM_controlRegister, s->control_register);
}
static inline void hdspm_stop_audio(struct hdspm * s)
{
s->control_register &= ~(HDSPM_Start | HDSPM_AudioInterruptEnable);
hdspm_write(s, HDSPM_controlRegister, s->control_register);
}
static void hdspm_silence_playback(struct hdspm *hdspm)
{
int i;
int n = hdspm->period_bytes;
void *buf = hdspm->playback_buffer;
if (buf == NULL)
return;
for (i = 0; i < HDSPM_MAX_CHANNELS; i++) {
memset(buf, 0, n);
buf += HDSPM_CHANNEL_BUFFER_BYTES;
}
}
static int hdspm_set_interrupt_interval(struct hdspm *s, unsigned int frames)
{
int n;
spin_lock_irq(&s->lock);
if (32 == frames) {
n = 7;
} else {
frames >>= 7;
n = 0;
while (frames) {
n++;
frames >>= 1;
}
}
s->control_register &= ~HDSPM_LatencyMask;
s->control_register |= hdspm_encode_latency(n);
hdspm_write(s, HDSPM_controlRegister, s->control_register);
hdspm_compute_period_size(s);
spin_unlock_irq(&s->lock);
return 0;
}
static u64 hdspm_calc_dds_value(struct hdspm *hdspm, u64 period)
{
u64 freq_const;
if (period == 0)
return 0;
switch (hdspm->io_type) {
case MADI:
case AES32:
freq_const = 110069313433624ULL;
break;
case RayDAT:
case AIO:
freq_const = 104857600000000ULL;
break;
case MADIface:
freq_const = 131072000000000ULL;
break;
default:
snd_BUG();
return 0;
}
return div_u64(freq_const, period);
}
static void hdspm_set_dds_value(struct hdspm *hdspm, int rate)
{
u64 n;
if (rate >= 112000)
rate /= 4;
else if (rate >= 56000)
rate /= 2;
switch (hdspm->io_type) {
case MADIface:
n = 131072000000000ULL;
break;
case MADI:
case AES32:
n = 110069313433624ULL;
break;
case RayDAT:
case AIO:
n = 104857600000000ULL;
break;
default:
snd_BUG();
return;
}
n = div_u64(n, rate);
snd_BUG_ON(n >> 32);
hdspm_write(hdspm, HDSPM_freqReg, (u32)n);
}
static int hdspm_set_rate(struct hdspm * hdspm, int rate, int called_internally)
{
int current_rate;
int rate_bits;
int not_set = 0;
int current_speed, target_speed;
if (!(hdspm->control_register & HDSPM_ClockModeMaster)) {
if (called_internally) {
dev_warn(hdspm->card->dev,
"Warning: device is not running as a clock master.\n");
not_set = 1;
} else {
int external_freq =
hdspm_external_sample_rate(hdspm);
if (hdspm_autosync_ref(hdspm) ==
HDSPM_AUTOSYNC_FROM_NONE) {
dev_warn(hdspm->card->dev,
"Detected no Externel Sync\n");
not_set = 1;
} else if (rate != external_freq) {
dev_warn(hdspm->card->dev,
"Warning: No AutoSync source for requested rate\n");
not_set = 1;
}
}
}
current_rate = hdspm->system_sample_rate;
if (current_rate <= 48000)
current_speed = HDSPM_SPEED_SINGLE;
else if (current_rate <= 96000)
current_speed = HDSPM_SPEED_DOUBLE;
else
current_speed = HDSPM_SPEED_QUAD;
if (rate <= 48000)
target_speed = HDSPM_SPEED_SINGLE;
else if (rate <= 96000)
target_speed = HDSPM_SPEED_DOUBLE;
else
target_speed = HDSPM_SPEED_QUAD;
switch (rate) {
case 32000:
rate_bits = HDSPM_Frequency32KHz;
break;
case 44100:
rate_bits = HDSPM_Frequency44_1KHz;
break;
case 48000:
rate_bits = HDSPM_Frequency48KHz;
break;
case 64000:
rate_bits = HDSPM_Frequency64KHz;
break;
case 88200:
rate_bits = HDSPM_Frequency88_2KHz;
break;
case 96000:
rate_bits = HDSPM_Frequency96KHz;
break;
case 128000:
rate_bits = HDSPM_Frequency128KHz;
break;
case 176400:
rate_bits = HDSPM_Frequency176_4KHz;
break;
case 192000:
rate_bits = HDSPM_Frequency192KHz;
break;
default:
return -EINVAL;
}
if (current_speed != target_speed
&& (hdspm->capture_pid >= 0 || hdspm->playback_pid >= 0)) {
dev_err(hdspm->card->dev,
"cannot change from %s speed to %s speed mode (capture PID = %d, playback PID = %d)\n",
hdspm_speed_names[current_speed],
hdspm_speed_names[target_speed],
hdspm->capture_pid, hdspm->playback_pid);
return -EBUSY;
}
hdspm->control_register &= ~HDSPM_FrequencyMask;
hdspm->control_register |= rate_bits;
hdspm_write(hdspm, HDSPM_controlRegister, hdspm->control_register);
hdspm_set_dds_value(hdspm, rate);
if (AES32 == hdspm->io_type && rate != current_rate)
hdspm_write(hdspm, HDSPM_eeprom_wr, 0);
hdspm->system_sample_rate = rate;
if (rate <= 48000) {
hdspm->channel_map_in = hdspm->channel_map_in_ss;
hdspm->channel_map_out = hdspm->channel_map_out_ss;
hdspm->max_channels_in = hdspm->ss_in_channels;
hdspm->max_channels_out = hdspm->ss_out_channels;
hdspm->port_names_in = hdspm->port_names_in_ss;
hdspm->port_names_out = hdspm->port_names_out_ss;
} else if (rate <= 96000) {
hdspm->channel_map_in = hdspm->channel_map_in_ds;
hdspm->channel_map_out = hdspm->channel_map_out_ds;
hdspm->max_channels_in = hdspm->ds_in_channels;
hdspm->max_channels_out = hdspm->ds_out_channels;
hdspm->port_names_in = hdspm->port_names_in_ds;
hdspm->port_names_out = hdspm->port_names_out_ds;
} else {
hdspm->channel_map_in = hdspm->channel_map_in_qs;
hdspm->channel_map_out = hdspm->channel_map_out_qs;
hdspm->max_channels_in = hdspm->qs_in_channels;
hdspm->max_channels_out = hdspm->qs_out_channels;
hdspm->port_names_in = hdspm->port_names_in_qs;
hdspm->port_names_out = hdspm->port_names_out_qs;
}
if (not_set != 0)
return -1;
return 0;
}
static void all_in_all_mixer(struct hdspm * hdspm, int sgain)
{
int i, j;
unsigned int gain;
if (sgain > UNITY_GAIN)
gain = UNITY_GAIN;
else if (sgain < 0)
gain = 0;
else
gain = sgain;
for (i = 0; i < HDSPM_MIXER_CHANNELS; i++)
for (j = 0; j < HDSPM_MIXER_CHANNELS; j++) {
hdspm_write_in_gain(hdspm, i, j, gain);
hdspm_write_pb_gain(hdspm, i, j, gain);
}
}
static inline unsigned char snd_hdspm_midi_read_byte (struct hdspm *hdspm,
int id)
{
return hdspm_read(hdspm, hdspm->midi[id].dataIn);
}
static inline void snd_hdspm_midi_write_byte (struct hdspm *hdspm, int id,
int val)
{
return hdspm_write(hdspm, hdspm->midi[id].dataOut, val);
}
static inline int snd_hdspm_midi_input_available (struct hdspm *hdspm, int id)
{
return hdspm_read(hdspm, hdspm->midi[id].statusIn) & 0xFF;
}
static inline int snd_hdspm_midi_output_possible (struct hdspm *hdspm, int id)
{
int fifo_bytes_used;
fifo_bytes_used = hdspm_read(hdspm, hdspm->midi[id].statusOut) & 0xFF;
if (fifo_bytes_used < 128)
return 128 - fifo_bytes_used;
else
return 0;
}
static void snd_hdspm_flush_midi_input(struct hdspm *hdspm, int id)
{
while (snd_hdspm_midi_input_available (hdspm, id))
snd_hdspm_midi_read_byte (hdspm, id);
}
static int snd_hdspm_midi_output_write (struct hdspm_midi *hmidi)
{
unsigned long flags;
int n_pending;
int to_write;
int i;
unsigned char buf[128];
spin_lock_irqsave (&hmidi->lock, flags);
if (hmidi->output &&
!snd_rawmidi_transmit_empty (hmidi->output)) {
n_pending = snd_hdspm_midi_output_possible (hmidi->hdspm,
hmidi->id);
if (n_pending > 0) {
if (n_pending > (int)sizeof (buf))
n_pending = sizeof (buf);
to_write = snd_rawmidi_transmit (hmidi->output, buf,
n_pending);
if (to_write > 0) {
for (i = 0; i < to_write; ++i)
snd_hdspm_midi_write_byte (hmidi->hdspm,
hmidi->id,
buf[i]);
}
}
}
spin_unlock_irqrestore (&hmidi->lock, flags);
return 0;
}
static int snd_hdspm_midi_input_read (struct hdspm_midi *hmidi)
{
unsigned char buf[128];
unsigned long flags;
int n_pending;
int i;
spin_lock_irqsave (&hmidi->lock, flags);
n_pending = snd_hdspm_midi_input_available (hmidi->hdspm, hmidi->id);
if (n_pending > 0) {
if (hmidi->input) {
if (n_pending > (int)sizeof (buf))
n_pending = sizeof (buf);
for (i = 0; i < n_pending; ++i)
buf[i] = snd_hdspm_midi_read_byte (hmidi->hdspm,
hmidi->id);
if (n_pending)
snd_rawmidi_receive (hmidi->input, buf,
n_pending);
} else {
while (n_pending--)
snd_hdspm_midi_read_byte (hmidi->hdspm,
hmidi->id);
}
}
hmidi->pending = 0;
spin_unlock_irqrestore(&hmidi->lock, flags);
spin_lock_irqsave(&hmidi->hdspm->lock, flags);
hmidi->hdspm->control_register |= hmidi->ie;
hdspm_write(hmidi->hdspm, HDSPM_controlRegister,
hmidi->hdspm->control_register);
spin_unlock_irqrestore(&hmidi->hdspm->lock, flags);
return snd_hdspm_midi_output_write (hmidi);
}
static void
snd_hdspm_midi_input_trigger(struct snd_rawmidi_substream *substream, int up)
{
struct hdspm *hdspm;
struct hdspm_midi *hmidi;
unsigned long flags;
hmidi = substream->rmidi->private_data;
hdspm = hmidi->hdspm;
spin_lock_irqsave (&hdspm->lock, flags);
if (up) {
if (!(hdspm->control_register & hmidi->ie)) {
snd_hdspm_flush_midi_input (hdspm, hmidi->id);
hdspm->control_register |= hmidi->ie;
}
} else {
hdspm->control_register &= ~hmidi->ie;
}
hdspm_write(hdspm, HDSPM_controlRegister, hdspm->control_register);
spin_unlock_irqrestore (&hdspm->lock, flags);
}
static void snd_hdspm_midi_output_timer(unsigned long data)
{
struct hdspm_midi *hmidi = (struct hdspm_midi *) data;
unsigned long flags;
snd_hdspm_midi_output_write(hmidi);
spin_lock_irqsave (&hmidi->lock, flags);
if (hmidi->istimer) {
hmidi->timer.expires = 1 + jiffies;
add_timer(&hmidi->timer);
}
spin_unlock_irqrestore (&hmidi->lock, flags);
}
static void
snd_hdspm_midi_output_trigger(struct snd_rawmidi_substream *substream, int up)
{
struct hdspm_midi *hmidi;
unsigned long flags;
hmidi = substream->rmidi->private_data;
spin_lock_irqsave (&hmidi->lock, flags);
if (up) {
if (!hmidi->istimer) {
init_timer(&hmidi->timer);
hmidi->timer.function = snd_hdspm_midi_output_timer;
hmidi->timer.data = (unsigned long) hmidi;
hmidi->timer.expires = 1 + jiffies;
add_timer(&hmidi->timer);
hmidi->istimer++;
}
} else {
if (hmidi->istimer && --hmidi->istimer <= 0)
del_timer (&hmidi->timer);
}
spin_unlock_irqrestore (&hmidi->lock, flags);
if (up)
snd_hdspm_midi_output_write(hmidi);
}
static int snd_hdspm_midi_input_open(struct snd_rawmidi_substream *substream)
{
struct hdspm_midi *hmidi;
hmidi = substream->rmidi->private_data;
spin_lock_irq (&hmidi->lock);
snd_hdspm_flush_midi_input (hmidi->hdspm, hmidi->id);
hmidi->input = substream;
spin_unlock_irq (&hmidi->lock);
return 0;
}
static int snd_hdspm_midi_output_open(struct snd_rawmidi_substream *substream)
{
struct hdspm_midi *hmidi;
hmidi = substream->rmidi->private_data;
spin_lock_irq (&hmidi->lock);
hmidi->output = substream;
spin_unlock_irq (&hmidi->lock);
return 0;
}
static int snd_hdspm_midi_input_close(struct snd_rawmidi_substream *substream)
{
struct hdspm_midi *hmidi;
snd_hdspm_midi_input_trigger (substream, 0);
hmidi = substream->rmidi->private_data;
spin_lock_irq (&hmidi->lock);
hmidi->input = NULL;
spin_unlock_irq (&hmidi->lock);
return 0;
}
static int snd_hdspm_midi_output_close(struct snd_rawmidi_substream *substream)
{
struct hdspm_midi *hmidi;
snd_hdspm_midi_output_trigger (substream, 0);
hmidi = substream->rmidi->private_data;
spin_lock_irq (&hmidi->lock);
hmidi->output = NULL;
spin_unlock_irq (&hmidi->lock);
return 0;
}
static int snd_hdspm_create_midi(struct snd_card *card,
struct hdspm *hdspm, int id)
{
int err;
char buf[32];
hdspm->midi[id].id = id;
hdspm->midi[id].hdspm = hdspm;
spin_lock_init (&hdspm->midi[id].lock);
if (0 == id) {
if (MADIface == hdspm->io_type) {
hdspm->midi[0].dataIn = HDSPM_midiDataIn2;
hdspm->midi[0].statusIn = HDSPM_midiStatusIn2;
hdspm->midi[0].dataOut = HDSPM_midiDataOut2;
hdspm->midi[0].statusOut = HDSPM_midiStatusOut2;
hdspm->midi[0].ie = HDSPM_Midi2InterruptEnable;
hdspm->midi[0].irq = HDSPM_midi2IRQPending;
} else {
hdspm->midi[0].dataIn = HDSPM_midiDataIn0;
hdspm->midi[0].statusIn = HDSPM_midiStatusIn0;
hdspm->midi[0].dataOut = HDSPM_midiDataOut0;
hdspm->midi[0].statusOut = HDSPM_midiStatusOut0;
hdspm->midi[0].ie = HDSPM_Midi0InterruptEnable;
hdspm->midi[0].irq = HDSPM_midi0IRQPending;
}
} else if (1 == id) {
hdspm->midi[1].dataIn = HDSPM_midiDataIn1;
hdspm->midi[1].statusIn = HDSPM_midiStatusIn1;
hdspm->midi[1].dataOut = HDSPM_midiDataOut1;
hdspm->midi[1].statusOut = HDSPM_midiStatusOut1;
hdspm->midi[1].ie = HDSPM_Midi1InterruptEnable;
hdspm->midi[1].irq = HDSPM_midi1IRQPending;
} else if ((2 == id) && (MADI == hdspm->io_type)) {
hdspm->midi[2].dataIn = HDSPM_midiDataIn2;
hdspm->midi[2].statusIn = HDSPM_midiStatusIn2;
hdspm->midi[2].dataOut = HDSPM_midiDataOut2;
hdspm->midi[2].statusOut = HDSPM_midiStatusOut2;
hdspm->midi[2].ie = HDSPM_Midi2InterruptEnable;
hdspm->midi[2].irq = HDSPM_midi2IRQPending;
} else if (2 == id) {
hdspm->midi[2].dataIn = HDSPM_midiDataIn2;
hdspm->midi[2].statusIn = HDSPM_midiStatusIn2;
hdspm->midi[2].dataOut = -1;
hdspm->midi[2].statusOut = -1;
hdspm->midi[2].ie = HDSPM_Midi2InterruptEnable;
hdspm->midi[2].irq = HDSPM_midi2IRQPendingAES;
} else if (3 == id) {
hdspm->midi[3].dataIn = HDSPM_midiDataIn3;
hdspm->midi[3].statusIn = HDSPM_midiStatusIn3;
hdspm->midi[3].dataOut = -1;
hdspm->midi[3].statusOut = -1;
hdspm->midi[3].ie = HDSPM_Midi3InterruptEnable;
hdspm->midi[3].irq = HDSPM_midi3IRQPending;
}
if ((id < 2) || ((2 == id) && ((MADI == hdspm->io_type) ||
(MADIface == hdspm->io_type)))) {
if ((id == 0) && (MADIface == hdspm->io_type)) {
sprintf(buf, "%s MIDIoverMADI", card->shortname);
} else if ((id == 2) && (MADI == hdspm->io_type)) {
sprintf(buf, "%s MIDIoverMADI", card->shortname);
} else {
sprintf(buf, "%s MIDI %d", card->shortname, id+1);
}
err = snd_rawmidi_new(card, buf, id, 1, 1,
&hdspm->midi[id].rmidi);
if (err < 0)
return err;
sprintf(hdspm->midi[id].rmidi->name, "%s MIDI %d",
card->id, id+1);
hdspm->midi[id].rmidi->private_data = &hdspm->midi[id];
snd_rawmidi_set_ops(hdspm->midi[id].rmidi,
SNDRV_RAWMIDI_STREAM_OUTPUT,
&snd_hdspm_midi_output);
snd_rawmidi_set_ops(hdspm->midi[id].rmidi,
SNDRV_RAWMIDI_STREAM_INPUT,
&snd_hdspm_midi_input);
hdspm->midi[id].rmidi->info_flags |=
SNDRV_RAWMIDI_INFO_OUTPUT |
SNDRV_RAWMIDI_INFO_INPUT |
SNDRV_RAWMIDI_INFO_DUPLEX;
} else {
sprintf(buf, "%s MTC %d", card->shortname, id+1);
err = snd_rawmidi_new(card, buf, id, 1, 1,
&hdspm->midi[id].rmidi);
if (err < 0)
return err;
sprintf(hdspm->midi[id].rmidi->name,
"%s MTC %d", card->id, id+1);
hdspm->midi[id].rmidi->private_data = &hdspm->midi[id];
snd_rawmidi_set_ops(hdspm->midi[id].rmidi,
SNDRV_RAWMIDI_STREAM_INPUT,
&snd_hdspm_midi_input);
hdspm->midi[id].rmidi->info_flags |= SNDRV_RAWMIDI_INFO_INPUT;
}
return 0;
}
static void hdspm_midi_tasklet(unsigned long arg)
{
struct hdspm *hdspm = (struct hdspm *)arg;
int i = 0;
while (i < hdspm->midiPorts) {
if (hdspm->midi[i].pending)
snd_hdspm_midi_input_read(&hdspm->midi[i]);
i++;
}
}
static inline int hdspm_get_pll_freq(struct hdspm *hdspm)
{
unsigned int period, rate;
period = hdspm_read(hdspm, HDSPM_RD_PLL_FREQ);
rate = hdspm_calc_dds_value(hdspm, period);
return rate;
}
static int hdspm_get_system_sample_rate(struct hdspm *hdspm)
{
unsigned int rate;
rate = hdspm_get_pll_freq(hdspm);
if (rate > 207000) {
if (0 == hdspm_system_clock_mode(hdspm)) {
rate = hdspm->system_sample_rate;
} else {
rate = hdspm_external_sample_rate(hdspm);
}
}
return rate;
}
static int snd_hdspm_info_system_sample_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 27000;
uinfo->value.integer.max = 207000;
uinfo->value.integer.step = 1;
return 0;
}
static int snd_hdspm_get_system_sample_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *
ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.integer.value[0] = hdspm_get_system_sample_rate(hdspm);
return 0;
}
static int snd_hdspm_put_system_sample_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *
ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
hdspm_set_dds_value(hdspm, ucontrol->value.enumerated.item[0]);
return 0;
}
static int hdspm_get_wc_sample_rate(struct hdspm *hdspm)
{
int status;
switch (hdspm->io_type) {
case RayDAT:
case AIO:
status = hdspm_read(hdspm, HDSPM_RD_STATUS_1);
return (status >> 16) & 0xF;
break;
case AES32:
status = hdspm_read(hdspm, HDSPM_statusRegister);
return (status >> HDSPM_AES32_wcFreq_bit) & 0xF;
default:
break;
}
return 0;
}
static int hdspm_get_tco_sample_rate(struct hdspm *hdspm)
{
int status;
if (hdspm->tco) {
switch (hdspm->io_type) {
case RayDAT:
case AIO:
status = hdspm_read(hdspm, HDSPM_RD_STATUS_1);
return (status >> 20) & 0xF;
break;
case AES32:
status = hdspm_read(hdspm, HDSPM_statusRegister);
return (status >> 1) & 0xF;
default:
break;
}
}
return 0;
}
static int hdspm_get_sync_in_sample_rate(struct hdspm *hdspm)
{
int status;
if (hdspm->tco) {
switch (hdspm->io_type) {
case RayDAT:
case AIO:
status = hdspm_read(hdspm, HDSPM_RD_STATUS_2);
return (status >> 12) & 0xF;
break;
default:
break;
}
}
return 0;
}
static int hdspm_get_aes_sample_rate(struct hdspm *hdspm, int index)
{
int timecode;
switch (hdspm->io_type) {
case AES32:
timecode = hdspm_read(hdspm, HDSPM_timecodeRegister);
return (timecode >> (4*index)) & 0xF;
break;
default:
break;
}
return 0;
}
static int hdspm_get_s1_sample_rate(struct hdspm *hdspm, unsigned int idx)
{
int status = hdspm_read(hdspm, HDSPM_RD_STATUS_2);
return (status >> (idx*4)) & 0xF;
}
static int hdspm_external_rate_to_enum(struct hdspm *hdspm)
{
int rate = hdspm_external_sample_rate(hdspm);
int i, selected_rate = 0;
for (i = 1; i < 10; i++)
if (HDSPM_bit2freq(i) == rate) {
selected_rate = i;
break;
}
return selected_rate;
}
static int snd_hdspm_info_autosync_sample_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
ENUMERATED_CTL_INFO(uinfo, texts_freq);
return 0;
}
static int snd_hdspm_get_autosync_sample_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *
ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
switch (hdspm->io_type) {
case RayDAT:
switch (kcontrol->private_value) {
case 0:
ucontrol->value.enumerated.item[0] =
hdspm_get_wc_sample_rate(hdspm);
break;
case 7:
ucontrol->value.enumerated.item[0] =
hdspm_get_tco_sample_rate(hdspm);
break;
case 8:
ucontrol->value.enumerated.item[0] =
hdspm_get_sync_in_sample_rate(hdspm);
break;
default:
ucontrol->value.enumerated.item[0] =
hdspm_get_s1_sample_rate(hdspm,
kcontrol->private_value-1);
}
break;
case AIO:
switch (kcontrol->private_value) {
case 0:
ucontrol->value.enumerated.item[0] =
hdspm_get_wc_sample_rate(hdspm);
break;
case 4:
ucontrol->value.enumerated.item[0] =
hdspm_get_tco_sample_rate(hdspm);
break;
case 5:
ucontrol->value.enumerated.item[0] =
hdspm_get_sync_in_sample_rate(hdspm);
break;
default:
ucontrol->value.enumerated.item[0] =
hdspm_get_s1_sample_rate(hdspm,
kcontrol->private_value-1);
}
break;
case AES32:
switch (kcontrol->private_value) {
case 0:
ucontrol->value.enumerated.item[0] =
hdspm_get_wc_sample_rate(hdspm);
break;
case 9:
ucontrol->value.enumerated.item[0] =
hdspm_get_tco_sample_rate(hdspm);
break;
case 10:
ucontrol->value.enumerated.item[0] =
hdspm_get_sync_in_sample_rate(hdspm);
break;
case 11:
ucontrol->value.enumerated.item[0] =
hdspm_external_rate_to_enum(hdspm);
break;
default:
ucontrol->value.enumerated.item[0] =
hdspm_get_aes_sample_rate(hdspm,
kcontrol->private_value -
HDSPM_AES32_AUTOSYNC_FROM_AES1);
break;
}
break;
case MADI:
case MADIface:
ucontrol->value.enumerated.item[0] =
hdspm_external_rate_to_enum(hdspm);
break;
default:
break;
}
return 0;
}
static int hdspm_system_clock_mode(struct hdspm *hdspm)
{
switch (hdspm->io_type) {
case AIO:
case RayDAT:
if (hdspm->settings_register & HDSPM_c0Master)
return 0;
break;
default:
if (hdspm->control_register & HDSPM_ClockModeMaster)
return 0;
}
return 1;
}
static void hdspm_set_system_clock_mode(struct hdspm *hdspm, int mode)
{
hdspm_set_toggle_setting(hdspm,
(hdspm_is_raydat_or_aio(hdspm)) ?
HDSPM_c0Master : HDSPM_ClockModeMaster,
(0 == mode));
}
static int snd_hdspm_info_system_clock_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "Master", "AutoSync" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_system_clock_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm_system_clock_mode(hdspm);
return 0;
}
static int snd_hdspm_put_system_clock_mode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int val;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
val = ucontrol->value.enumerated.item[0];
if (val < 0)
val = 0;
else if (val > 1)
val = 1;
hdspm_set_system_clock_mode(hdspm, val);
return 0;
}
static int hdspm_clock_source(struct hdspm * hdspm)
{
switch (hdspm->system_sample_rate) {
case 32000: return 0;
case 44100: return 1;
case 48000: return 2;
case 64000: return 3;
case 88200: return 4;
case 96000: return 5;
case 128000: return 6;
case 176400: return 7;
case 192000: return 8;
}
return -1;
}
static int hdspm_set_clock_source(struct hdspm * hdspm, int mode)
{
int rate;
switch (mode) {
case 0:
rate = 32000; break;
case 1:
rate = 44100; break;
case 2:
rate = 48000; break;
case 3:
rate = 64000; break;
case 4:
rate = 88200; break;
case 5:
rate = 96000; break;
case 6:
rate = 128000; break;
case 7:
rate = 176400; break;
case 8:
rate = 192000; break;
default:
rate = 48000;
}
hdspm_set_rate(hdspm, rate, 1);
return 0;
}
static int snd_hdspm_info_clock_source(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_ENUMERATED;
uinfo->count = 1;
uinfo->value.enumerated.items = 9;
if (uinfo->value.enumerated.item >= uinfo->value.enumerated.items)
uinfo->value.enumerated.item =
uinfo->value.enumerated.items - 1;
strcpy(uinfo->value.enumerated.name,
texts_freq[uinfo->value.enumerated.item+1]);
return 0;
}
static int snd_hdspm_get_clock_source(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm_clock_source(hdspm);
return 0;
}
static int snd_hdspm_put_clock_source(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int change;
int val;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
val = ucontrol->value.enumerated.item[0];
if (val < 0)
val = 0;
if (val > 9)
val = 9;
spin_lock_irq(&hdspm->lock);
if (val != hdspm_clock_source(hdspm))
change = (hdspm_set_clock_source(hdspm, val) == 0) ? 1 : 0;
else
change = 0;
spin_unlock_irq(&hdspm->lock);
return change;
}
static int hdspm_pref_sync_ref(struct hdspm * hdspm)
{
switch (hdspm->io_type) {
case AES32:
switch (hdspm->control_register & HDSPM_SyncRefMask) {
case 0: return 0;
case HDSPM_SyncRef0: return 1;
case HDSPM_SyncRef1: return 2;
case HDSPM_SyncRef1+HDSPM_SyncRef0: return 3;
case HDSPM_SyncRef2: return 4;
case HDSPM_SyncRef2+HDSPM_SyncRef0: return 5;
case HDSPM_SyncRef2+HDSPM_SyncRef1: return 6;
case HDSPM_SyncRef2+HDSPM_SyncRef1+HDSPM_SyncRef0:
return 7;
case HDSPM_SyncRef3: return 8;
case HDSPM_SyncRef3+HDSPM_SyncRef0: return 9;
}
break;
case MADI:
case MADIface:
if (hdspm->tco) {
switch (hdspm->control_register & HDSPM_SyncRefMask) {
case 0: return 0;
case HDSPM_SyncRef0: return 1;
case HDSPM_SyncRef1: return 2;
case HDSPM_SyncRef1+HDSPM_SyncRef0:
return 3;
}
} else {
switch (hdspm->control_register & HDSPM_SyncRefMask) {
case 0: return 0;
case HDSPM_SyncRef0: return 1;
case HDSPM_SyncRef1+HDSPM_SyncRef0:
return 2;
}
}
break;
case RayDAT:
if (hdspm->tco) {
switch ((hdspm->settings_register &
HDSPM_c0_SyncRefMask) / HDSPM_c0_SyncRef0) {
case 0: return 0;
case 3: return 1;
case 4: return 2;
case 5: return 3;
case 6: return 4;
case 1: return 5;
case 2: return 6;
case 9: return 7;
case 10: return 8;
}
} else {
switch ((hdspm->settings_register &
HDSPM_c0_SyncRefMask) / HDSPM_c0_SyncRef0) {
case 0: return 0;
case 3: return 1;
case 4: return 2;
case 5: return 3;
case 6: return 4;
case 1: return 5;
case 2: return 6;
case 10: return 7;
}
}
break;
case AIO:
if (hdspm->tco) {
switch ((hdspm->settings_register &
HDSPM_c0_SyncRefMask) / HDSPM_c0_SyncRef0) {
case 0: return 0;
case 3: return 1;
case 1: return 2;
case 2: return 3;
case 9: return 4;
case 10: return 5;
}
} else {
switch ((hdspm->settings_register &
HDSPM_c0_SyncRefMask) / HDSPM_c0_SyncRef0) {
case 0: return 0;
case 3: return 1;
case 1: return 2;
case 2: return 3;
case 10: return 4;
}
}
break;
}
return -1;
}
static int hdspm_set_pref_sync_ref(struct hdspm * hdspm, int pref)
{
int p = 0;
switch (hdspm->io_type) {
case AES32:
hdspm->control_register &= ~HDSPM_SyncRefMask;
switch (pref) {
case 0:
break;
case 1:
hdspm->control_register |= HDSPM_SyncRef0;
break;
case 2:
hdspm->control_register |= HDSPM_SyncRef1;
break;
case 3:
hdspm->control_register |=
HDSPM_SyncRef1+HDSPM_SyncRef0;
break;
case 4:
hdspm->control_register |= HDSPM_SyncRef2;
break;
case 5:
hdspm->control_register |=
HDSPM_SyncRef2+HDSPM_SyncRef0;
break;
case 6:
hdspm->control_register |=
HDSPM_SyncRef2+HDSPM_SyncRef1;
break;
case 7:
hdspm->control_register |=
HDSPM_SyncRef2+HDSPM_SyncRef1+HDSPM_SyncRef0;
break;
case 8:
hdspm->control_register |= HDSPM_SyncRef3;
break;
case 9:
hdspm->control_register |=
HDSPM_SyncRef3+HDSPM_SyncRef0;
break;
default:
return -1;
}
break;
case MADI:
case MADIface:
hdspm->control_register &= ~HDSPM_SyncRefMask;
if (hdspm->tco) {
switch (pref) {
case 0:
break;
case 1:
hdspm->control_register |= HDSPM_SyncRef0;
break;
case 2:
hdspm->control_register |= HDSPM_SyncRef1;
break;
case 3:
hdspm->control_register |=
HDSPM_SyncRef0+HDSPM_SyncRef1;
break;
default:
return -1;
}
} else {
switch (pref) {
case 0:
break;
case 1:
hdspm->control_register |= HDSPM_SyncRef0;
break;
case 2:
hdspm->control_register |=
HDSPM_SyncRef0+HDSPM_SyncRef1;
break;
default:
return -1;
}
}
break;
case RayDAT:
if (hdspm->tco) {
switch (pref) {
case 0: p = 0; break;
case 1: p = 3; break;
case 2: p = 4; break;
case 3: p = 5; break;
case 4: p = 6; break;
case 5: p = 1; break;
case 6: p = 2; break;
case 7: p = 9; break;
case 8: p = 10; break;
default: return -1;
}
} else {
switch (pref) {
case 0: p = 0; break;
case 1: p = 3; break;
case 2: p = 4; break;
case 3: p = 5; break;
case 4: p = 6; break;
case 5: p = 1; break;
case 6: p = 2; break;
case 7: p = 10; break;
default: return -1;
}
}
break;
case AIO:
if (hdspm->tco) {
switch (pref) {
case 0: p = 0; break;
case 1: p = 3; break;
case 2: p = 1; break;
case 3: p = 2; break;
case 4: p = 9; break;
case 5: p = 10; break;
default: return -1;
}
} else {
switch (pref) {
case 0: p = 0; break;
case 1: p = 3; break;
case 2: p = 1; break;
case 3: p = 2; break;
case 4: p = 10; break;
default: return -1;
}
}
break;
}
switch (hdspm->io_type) {
case RayDAT:
case AIO:
hdspm->settings_register &= ~HDSPM_c0_SyncRefMask;
hdspm->settings_register |= HDSPM_c0_SyncRef0 * p;
hdspm_write(hdspm, HDSPM_WR_SETTINGS, hdspm->settings_register);
break;
case MADI:
case MADIface:
case AES32:
hdspm_write(hdspm, HDSPM_controlRegister,
hdspm->control_register);
}
return 0;
}
static int snd_hdspm_info_pref_sync_ref(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
snd_ctl_enum_info(uinfo, 1, hdspm->texts_autosync_items, hdspm->texts_autosync);
return 0;
}
static int snd_hdspm_get_pref_sync_ref(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int psf = hdspm_pref_sync_ref(hdspm);
if (psf >= 0) {
ucontrol->value.enumerated.item[0] = psf;
return 0;
}
return -1;
}
static int snd_hdspm_put_pref_sync_ref(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int val, change = 0;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
val = ucontrol->value.enumerated.item[0];
if (val < 0)
val = 0;
else if (val >= hdspm->texts_autosync_items)
val = hdspm->texts_autosync_items-1;
spin_lock_irq(&hdspm->lock);
if (val != hdspm_pref_sync_ref(hdspm))
change = (0 == hdspm_set_pref_sync_ref(hdspm, val)) ? 1 : 0;
spin_unlock_irq(&hdspm->lock);
return change;
}
static int hdspm_autosync_ref(struct hdspm *hdspm)
{
if (AES32 == hdspm->io_type) {
unsigned int status = hdspm_read(hdspm, HDSPM_statusRegister);
unsigned int syncref = (status >> HDSPM_AES32_syncref_bit) & 0xF;
if ((syncref >= HDSPM_AES32_AUTOSYNC_FROM_WORD) &&
(syncref <= HDSPM_AES32_AUTOSYNC_FROM_SYNC_IN)) {
return syncref;
}
return HDSPM_AES32_AUTOSYNC_FROM_NONE;
} else if (MADI == hdspm->io_type) {
unsigned int status2 = hdspm_read(hdspm, HDSPM_statusRegister2);
switch (status2 & HDSPM_SelSyncRefMask) {
case HDSPM_SelSyncRef_WORD:
return HDSPM_AUTOSYNC_FROM_WORD;
case HDSPM_SelSyncRef_MADI:
return HDSPM_AUTOSYNC_FROM_MADI;
case HDSPM_SelSyncRef_TCO:
return HDSPM_AUTOSYNC_FROM_TCO;
case HDSPM_SelSyncRef_SyncIn:
return HDSPM_AUTOSYNC_FROM_SYNC_IN;
case HDSPM_SelSyncRef_NVALID:
return HDSPM_AUTOSYNC_FROM_NONE;
default:
return HDSPM_AUTOSYNC_FROM_NONE;
}
}
return 0;
}
static int snd_hdspm_info_autosync_ref(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
if (AES32 == hdspm->io_type) {
static const char *const texts[] = { "WordClock", "AES1", "AES2", "AES3",
"AES4", "AES5", "AES6", "AES7", "AES8", "TCO", "Sync In", "None"};
ENUMERATED_CTL_INFO(uinfo, texts);
} else if (MADI == hdspm->io_type) {
static const char *const texts[] = {"Word Clock", "MADI", "TCO",
"Sync In", "None" };
ENUMERATED_CTL_INFO(uinfo, texts);
}
return 0;
}
static int snd_hdspm_get_autosync_ref(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm_autosync_ref(hdspm);
return 0;
}
static int snd_hdspm_info_tco_video_input_format(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = {"No video", "NTSC", "PAL"};
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_tco_video_input_format(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
u32 status;
int ret = 0;
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
status = hdspm_read(hdspm, HDSPM_RD_TCO + 4);
switch (status & (HDSPM_TCO1_Video_Input_Format_NTSC |
HDSPM_TCO1_Video_Input_Format_PAL)) {
case HDSPM_TCO1_Video_Input_Format_NTSC:
ret = 1;
break;
case HDSPM_TCO1_Video_Input_Format_PAL:
ret = 2;
break;
default:
ret = 0;
break;
}
ucontrol->value.enumerated.item[0] = ret;
return 0;
}
static int snd_hdspm_info_tco_ltc_frames(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = {"No lock", "24 fps", "25 fps", "29.97 fps",
"30 fps"};
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int hdspm_tco_ltc_frames(struct hdspm *hdspm)
{
u32 status;
int ret = 0;
status = hdspm_read(hdspm, HDSPM_RD_TCO + 4);
if (status & HDSPM_TCO1_LTC_Input_valid) {
switch (status & (HDSPM_TCO1_LTC_Format_LSB |
HDSPM_TCO1_LTC_Format_MSB)) {
case 0:
ret = fps_24;
break;
case HDSPM_TCO1_LTC_Format_LSB:
ret = fps_25;
break;
case HDSPM_TCO1_LTC_Format_MSB:
ret = fps_2997;
break;
default:
ret = fps_30;
break;
}
}
return ret;
}
static int snd_hdspm_get_tco_ltc_frames(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm_tco_ltc_frames(hdspm);
return 0;
}
static int hdspm_toggle_setting(struct hdspm *hdspm, u32 regmask)
{
u32 reg;
if (hdspm_is_raydat_or_aio(hdspm))
reg = hdspm->settings_register;
else
reg = hdspm->control_register;
return (reg & regmask) ? 1 : 0;
}
static int hdspm_set_toggle_setting(struct hdspm *hdspm, u32 regmask, int out)
{
u32 *reg;
u32 target_reg;
if (hdspm_is_raydat_or_aio(hdspm)) {
reg = &(hdspm->settings_register);
target_reg = HDSPM_WR_SETTINGS;
} else {
reg = &(hdspm->control_register);
target_reg = HDSPM_controlRegister;
}
if (out)
*reg |= regmask;
else
*reg &= ~regmask;
hdspm_write(hdspm, target_reg, *reg);
return 0;
}
static int snd_hdspm_get_toggle_setting(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
u32 regmask = kcontrol->private_value;
spin_lock_irq(&hdspm->lock);
ucontrol->value.integer.value[0] = hdspm_toggle_setting(hdspm, regmask);
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_put_toggle_setting(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
u32 regmask = kcontrol->private_value;
int change;
unsigned int val;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
val = ucontrol->value.integer.value[0] & 1;
spin_lock_irq(&hdspm->lock);
change = (int) val != hdspm_toggle_setting(hdspm, regmask);
hdspm_set_toggle_setting(hdspm, regmask, val);
spin_unlock_irq(&hdspm->lock);
return change;
}
static int hdspm_input_select(struct hdspm * hdspm)
{
return (hdspm->control_register & HDSPM_InputSelect0) ? 1 : 0;
}
static int hdspm_set_input_select(struct hdspm * hdspm, int out)
{
if (out)
hdspm->control_register |= HDSPM_InputSelect0;
else
hdspm->control_register &= ~HDSPM_InputSelect0;
hdspm_write(hdspm, HDSPM_controlRegister, hdspm->control_register);
return 0;
}
static int snd_hdspm_info_input_select(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "optical", "coaxial" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_input_select(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&hdspm->lock);
ucontrol->value.enumerated.item[0] = hdspm_input_select(hdspm);
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_put_input_select(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int change;
unsigned int val;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
val = ucontrol->value.integer.value[0] & 1;
spin_lock_irq(&hdspm->lock);
change = (int) val != hdspm_input_select(hdspm);
hdspm_set_input_select(hdspm, val);
spin_unlock_irq(&hdspm->lock);
return change;
}
static int hdspm_ds_wire(struct hdspm * hdspm)
{
return (hdspm->control_register & HDSPM_DS_DoubleWire) ? 1 : 0;
}
static int hdspm_set_ds_wire(struct hdspm * hdspm, int ds)
{
if (ds)
hdspm->control_register |= HDSPM_DS_DoubleWire;
else
hdspm->control_register &= ~HDSPM_DS_DoubleWire;
hdspm_write(hdspm, HDSPM_controlRegister, hdspm->control_register);
return 0;
}
static int snd_hdspm_info_ds_wire(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "Single", "Double" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_ds_wire(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&hdspm->lock);
ucontrol->value.enumerated.item[0] = hdspm_ds_wire(hdspm);
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_put_ds_wire(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int change;
unsigned int val;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
val = ucontrol->value.integer.value[0] & 1;
spin_lock_irq(&hdspm->lock);
change = (int) val != hdspm_ds_wire(hdspm);
hdspm_set_ds_wire(hdspm, val);
spin_unlock_irq(&hdspm->lock);
return change;
}
static int hdspm_qs_wire(struct hdspm * hdspm)
{
if (hdspm->control_register & HDSPM_QS_DoubleWire)
return 1;
if (hdspm->control_register & HDSPM_QS_QuadWire)
return 2;
return 0;
}
static int hdspm_set_qs_wire(struct hdspm * hdspm, int mode)
{
hdspm->control_register &= ~(HDSPM_QS_DoubleWire | HDSPM_QS_QuadWire);
switch (mode) {
case 0:
break;
case 1:
hdspm->control_register |= HDSPM_QS_DoubleWire;
break;
case 2:
hdspm->control_register |= HDSPM_QS_QuadWire;
break;
}
hdspm_write(hdspm, HDSPM_controlRegister, hdspm->control_register);
return 0;
}
static int snd_hdspm_info_qs_wire(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "Single", "Double", "Quad" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_qs_wire(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&hdspm->lock);
ucontrol->value.enumerated.item[0] = hdspm_qs_wire(hdspm);
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_put_qs_wire(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int change;
int val;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
val = ucontrol->value.integer.value[0];
if (val < 0)
val = 0;
if (val > 2)
val = 2;
spin_lock_irq(&hdspm->lock);
change = val != hdspm_qs_wire(hdspm);
hdspm_set_qs_wire(hdspm, val);
spin_unlock_irq(&hdspm->lock);
return change;
}
static int hdspm_tristate(struct hdspm *hdspm, u32 regmask)
{
u32 reg = hdspm->settings_register & (regmask * 3);
return reg / regmask;
}
static int hdspm_set_tristate(struct hdspm *hdspm, int mode, u32 regmask)
{
hdspm->settings_register &= ~(regmask * 3);
hdspm->settings_register |= (regmask * mode);
hdspm_write(hdspm, HDSPM_WR_SETTINGS, hdspm->settings_register);
return 0;
}
static int snd_hdspm_info_tristate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
u32 regmask = kcontrol->private_value;
static const char *const texts_spdif[] = { "Optical", "Coaxial", "Internal" };
static const char *const texts_levels[] = { "Hi Gain", "+4 dBu", "-10 dBV" };
switch (regmask) {
case HDSPM_c0_Input0:
ENUMERATED_CTL_INFO(uinfo, texts_spdif);
break;
default:
ENUMERATED_CTL_INFO(uinfo, texts_levels);
break;
}
return 0;
}
static int snd_hdspm_get_tristate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
u32 regmask = kcontrol->private_value;
spin_lock_irq(&hdspm->lock);
ucontrol->value.enumerated.item[0] = hdspm_tristate(hdspm, regmask);
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_put_tristate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
u32 regmask = kcontrol->private_value;
int change;
int val;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
val = ucontrol->value.integer.value[0];
if (val < 0)
val = 0;
if (val > 2)
val = 2;
spin_lock_irq(&hdspm->lock);
change = val != hdspm_tristate(hdspm, regmask);
hdspm_set_tristate(hdspm, val, regmask);
spin_unlock_irq(&hdspm->lock);
return change;
}
static int hdspm_madi_speedmode(struct hdspm *hdspm)
{
if (hdspm->control_register & HDSPM_QuadSpeed)
return 2;
if (hdspm->control_register & HDSPM_DoubleSpeed)
return 1;
return 0;
}
static int hdspm_set_madi_speedmode(struct hdspm *hdspm, int mode)
{
hdspm->control_register &= ~(HDSPM_DoubleSpeed | HDSPM_QuadSpeed);
switch (mode) {
case 0:
break;
case 1:
hdspm->control_register |= HDSPM_DoubleSpeed;
break;
case 2:
hdspm->control_register |= HDSPM_QuadSpeed;
break;
}
hdspm_write(hdspm, HDSPM_controlRegister, hdspm->control_register);
return 0;
}
static int snd_hdspm_info_madi_speedmode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "Single", "Double", "Quad" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_madi_speedmode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
spin_lock_irq(&hdspm->lock);
ucontrol->value.enumerated.item[0] = hdspm_madi_speedmode(hdspm);
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_put_madi_speedmode(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int change;
int val;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
val = ucontrol->value.integer.value[0];
if (val < 0)
val = 0;
if (val > 2)
val = 2;
spin_lock_irq(&hdspm->lock);
change = val != hdspm_madi_speedmode(hdspm);
hdspm_set_madi_speedmode(hdspm, val);
spin_unlock_irq(&hdspm->lock);
return change;
}
static int snd_hdspm_info_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 3;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 65535;
uinfo->value.integer.step = 1;
return 0;
}
static int snd_hdspm_get_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int source;
int destination;
source = ucontrol->value.integer.value[0];
if (source < 0)
source = 0;
else if (source >= 2 * HDSPM_MAX_CHANNELS)
source = 2 * HDSPM_MAX_CHANNELS - 1;
destination = ucontrol->value.integer.value[1];
if (destination < 0)
destination = 0;
else if (destination >= HDSPM_MAX_CHANNELS)
destination = HDSPM_MAX_CHANNELS - 1;
spin_lock_irq(&hdspm->lock);
if (source >= HDSPM_MAX_CHANNELS)
ucontrol->value.integer.value[2] =
hdspm_read_pb_gain(hdspm, destination,
source - HDSPM_MAX_CHANNELS);
else
ucontrol->value.integer.value[2] =
hdspm_read_in_gain(hdspm, destination, source);
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_put_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int change;
int source;
int destination;
int gain;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
source = ucontrol->value.integer.value[0];
destination = ucontrol->value.integer.value[1];
if (source < 0 || source >= 2 * HDSPM_MAX_CHANNELS)
return -1;
if (destination < 0 || destination >= HDSPM_MAX_CHANNELS)
return -1;
gain = ucontrol->value.integer.value[2];
spin_lock_irq(&hdspm->lock);
if (source >= HDSPM_MAX_CHANNELS)
change = gain != hdspm_read_pb_gain(hdspm, destination,
source -
HDSPM_MAX_CHANNELS);
else
change = gain != hdspm_read_in_gain(hdspm, destination,
source);
if (change) {
if (source >= HDSPM_MAX_CHANNELS)
hdspm_write_pb_gain(hdspm, destination,
source - HDSPM_MAX_CHANNELS,
gain);
else
hdspm_write_in_gain(hdspm, destination, source,
gain);
}
spin_unlock_irq(&hdspm->lock);
return change;
}
static int snd_hdspm_info_playback_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 64;
uinfo->value.integer.step = 1;
return 0;
}
static int snd_hdspm_get_playback_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int channel;
channel = ucontrol->id.index - 1;
if (snd_BUG_ON(channel < 0 || channel >= HDSPM_MAX_CHANNELS))
return -EINVAL;
spin_lock_irq(&hdspm->lock);
ucontrol->value.integer.value[0] =
(hdspm_read_pb_gain(hdspm, channel, channel)*64)/UNITY_GAIN;
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_put_playback_mixer(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int change;
int channel;
int gain;
if (!snd_hdspm_use_is_exclusive(hdspm))
return -EBUSY;
channel = ucontrol->id.index - 1;
if (snd_BUG_ON(channel < 0 || channel >= HDSPM_MAX_CHANNELS))
return -EINVAL;
gain = ucontrol->value.integer.value[0]*UNITY_GAIN/64;
spin_lock_irq(&hdspm->lock);
change =
gain != hdspm_read_pb_gain(hdspm, channel,
channel);
if (change)
hdspm_write_pb_gain(hdspm, channel, channel,
gain);
spin_unlock_irq(&hdspm->lock);
return change;
}
static int snd_hdspm_info_sync_check(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "No Lock", "Lock", "Sync", "N/A" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_tco_info_lock_check(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "No Lock", "Lock" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int hdspm_wc_sync_check(struct hdspm *hdspm)
{
int status, status2;
switch (hdspm->io_type) {
case AES32:
status = hdspm_read(hdspm, HDSPM_statusRegister);
if (status & HDSPM_AES32_wcLock) {
if (status & HDSPM_AES32_wcSync)
return 2;
else
return 1;
}
return 0;
break;
case MADI:
status2 = hdspm_read(hdspm, HDSPM_statusRegister2);
if (status2 & HDSPM_wcLock) {
if (status2 & HDSPM_wcSync)
return 2;
else
return 1;
}
return 0;
break;
case RayDAT:
case AIO:
status = hdspm_read(hdspm, HDSPM_statusRegister);
if (status & 0x2000000)
return 2;
else if (status & 0x1000000)
return 1;
return 0;
break;
case MADIface:
break;
}
return 3;
}
static int hdspm_madi_sync_check(struct hdspm *hdspm)
{
int status = hdspm_read(hdspm, HDSPM_statusRegister);
if (status & HDSPM_madiLock) {
if (status & HDSPM_madiSync)
return 2;
else
return 1;
}
return 0;
}
static int hdspm_s1_sync_check(struct hdspm *hdspm, int idx)
{
int status, lock, sync;
status = hdspm_read(hdspm, HDSPM_RD_STATUS_1);
lock = (status & (0x1<<idx)) ? 1 : 0;
sync = (status & (0x100<<idx)) ? 1 : 0;
if (lock && sync)
return 2;
else if (lock)
return 1;
return 0;
}
static int hdspm_sync_in_sync_check(struct hdspm *hdspm)
{
int status, lock = 0, sync = 0;
switch (hdspm->io_type) {
case RayDAT:
case AIO:
status = hdspm_read(hdspm, HDSPM_RD_STATUS_3);
lock = (status & 0x400) ? 1 : 0;
sync = (status & 0x800) ? 1 : 0;
break;
case MADI:
status = hdspm_read(hdspm, HDSPM_statusRegister);
lock = (status & HDSPM_syncInLock) ? 1 : 0;
sync = (status & HDSPM_syncInSync) ? 1 : 0;
break;
case AES32:
status = hdspm_read(hdspm, HDSPM_statusRegister2);
lock = (status & 0x100000) ? 1 : 0;
sync = (status & 0x200000) ? 1 : 0;
break;
case MADIface:
break;
}
if (lock && sync)
return 2;
else if (lock)
return 1;
return 0;
}
static int hdspm_aes_sync_check(struct hdspm *hdspm, int idx)
{
int status2, lock, sync;
status2 = hdspm_read(hdspm, HDSPM_statusRegister2);
lock = (status2 & (0x0080 >> idx)) ? 1 : 0;
sync = (status2 & (0x8000 >> idx)) ? 1 : 0;
if (sync)
return 2;
else if (lock)
return 1;
return 0;
}
static int hdspm_tco_input_check(struct hdspm *hdspm, u32 mask)
{
u32 status;
status = hdspm_read(hdspm, HDSPM_RD_TCO + 4);
return (status & mask) ? 1 : 0;
}
static int hdspm_tco_sync_check(struct hdspm *hdspm)
{
int status;
if (hdspm->tco) {
switch (hdspm->io_type) {
case MADI:
status = hdspm_read(hdspm, HDSPM_statusRegister);
if (status & HDSPM_tcoLockMadi) {
if (status & HDSPM_tcoSync)
return 2;
else
return 1;
}
return 0;
case AES32:
status = hdspm_read(hdspm, HDSPM_statusRegister);
if (status & HDSPM_tcoLockAes) {
if (status & HDSPM_tcoSync)
return 2;
else
return 1;
}
return 0;
case RayDAT:
case AIO:
status = hdspm_read(hdspm, HDSPM_RD_STATUS_1);
if (status & 0x8000000)
return 2;
if (status & 0x4000000)
return 1;
return 0;
default:
break;
}
}
return 3;
}
static int snd_hdspm_get_sync_check(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
int val = -1;
switch (hdspm->io_type) {
case RayDAT:
switch (kcontrol->private_value) {
case 0:
val = hdspm_wc_sync_check(hdspm); break;
case 7:
val = hdspm_tco_sync_check(hdspm); break;
case 8:
val = hdspm_sync_in_sync_check(hdspm); break;
default:
val = hdspm_s1_sync_check(hdspm,
kcontrol->private_value-1);
}
break;
case AIO:
switch (kcontrol->private_value) {
case 0:
val = hdspm_wc_sync_check(hdspm); break;
case 4:
val = hdspm_tco_sync_check(hdspm); break;
case 5:
val = hdspm_sync_in_sync_check(hdspm); break;
default:
val = hdspm_s1_sync_check(hdspm,
kcontrol->private_value-1);
}
break;
case MADI:
switch (kcontrol->private_value) {
case 0:
val = hdspm_wc_sync_check(hdspm); break;
case 1:
val = hdspm_madi_sync_check(hdspm); break;
case 2:
val = hdspm_tco_sync_check(hdspm); break;
case 3:
val = hdspm_sync_in_sync_check(hdspm); break;
}
break;
case MADIface:
val = hdspm_madi_sync_check(hdspm);
break;
case AES32:
switch (kcontrol->private_value) {
case 0:
val = hdspm_wc_sync_check(hdspm); break;
case 9:
val = hdspm_tco_sync_check(hdspm); break;
case 10 :
val = hdspm_sync_in_sync_check(hdspm); break;
default:
val = hdspm_aes_sync_check(hdspm,
kcontrol->private_value-1);
}
break;
}
if (hdspm->tco) {
switch (kcontrol->private_value) {
case 11:
val = hdspm_tco_input_check(hdspm, HDSPM_TCO1_TCO_lock);
break;
case 12:
val = hdspm_tco_input_check(hdspm,
HDSPM_TCO1_LTC_Input_valid);
break;
default:
break;
}
}
if (-1 == val)
val = 3;
ucontrol->value.enumerated.item[0] = val;
return 0;
}
static void hdspm_tco_write(struct hdspm *hdspm)
{
unsigned int tc[4] = { 0, 0, 0, 0};
switch (hdspm->tco->input) {
case 0:
tc[2] |= HDSPM_TCO2_set_input_MSB;
break;
case 1:
tc[2] |= HDSPM_TCO2_set_input_LSB;
break;
default:
break;
}
switch (hdspm->tco->framerate) {
case 1:
tc[1] |= HDSPM_TCO1_LTC_Format_LSB;
break;
case 2:
tc[1] |= HDSPM_TCO1_LTC_Format_MSB;
break;
case 3:
tc[1] |= HDSPM_TCO1_LTC_Format_MSB +
HDSPM_TCO1_set_drop_frame_flag;
break;
case 4:
tc[1] |= HDSPM_TCO1_LTC_Format_LSB +
HDSPM_TCO1_LTC_Format_MSB;
break;
case 5:
tc[1] |= HDSPM_TCO1_LTC_Format_LSB +
HDSPM_TCO1_LTC_Format_MSB +
HDSPM_TCO1_set_drop_frame_flag;
break;
default:
break;
}
switch (hdspm->tco->wordclock) {
case 1:
tc[2] |= HDSPM_TCO2_WCK_IO_ratio_LSB;
break;
case 2:
tc[2] |= HDSPM_TCO2_WCK_IO_ratio_MSB;
break;
default:
break;
}
switch (hdspm->tco->samplerate) {
case 1:
tc[2] |= HDSPM_TCO2_set_freq;
break;
case 2:
tc[2] |= HDSPM_TCO2_set_freq_from_app;
break;
default:
break;
}
switch (hdspm->tco->pull) {
case 1:
tc[2] |= HDSPM_TCO2_set_pull_up;
break;
case 2:
tc[2] |= HDSPM_TCO2_set_pull_down;
break;
case 3:
tc[2] |= HDSPM_TCO2_set_pull_up + HDSPM_TCO2_set_01_4;
break;
case 4:
tc[2] |= HDSPM_TCO2_set_pull_down + HDSPM_TCO2_set_01_4;
break;
default:
break;
}
if (1 == hdspm->tco->term) {
tc[2] |= HDSPM_TCO2_set_term_75R;
}
hdspm_write(hdspm, HDSPM_WR_TCO, tc[0]);
hdspm_write(hdspm, HDSPM_WR_TCO+4, tc[1]);
hdspm_write(hdspm, HDSPM_WR_TCO+8, tc[2]);
hdspm_write(hdspm, HDSPM_WR_TCO+12, tc[3]);
}
static int snd_hdspm_info_tco_sample_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "44.1 kHz", "48 kHz" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_tco_sample_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm->tco->samplerate;
return 0;
}
static int snd_hdspm_put_tco_sample_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
if (hdspm->tco->samplerate != ucontrol->value.enumerated.item[0]) {
hdspm->tco->samplerate = ucontrol->value.enumerated.item[0];
hdspm_tco_write(hdspm);
return 1;
}
return 0;
}
static int snd_hdspm_info_tco_pull(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "0", "+ 0.1 %", "- 0.1 %",
"+ 4 %", "- 4 %" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_tco_pull(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm->tco->pull;
return 0;
}
static int snd_hdspm_put_tco_pull(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
if (hdspm->tco->pull != ucontrol->value.enumerated.item[0]) {
hdspm->tco->pull = ucontrol->value.enumerated.item[0];
hdspm_tco_write(hdspm);
return 1;
}
return 0;
}
static int snd_hdspm_info_tco_wck_conversion(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "1:1", "44.1 -> 48", "48 -> 44.1" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_tco_wck_conversion(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm->tco->wordclock;
return 0;
}
static int snd_hdspm_put_tco_wck_conversion(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
if (hdspm->tco->wordclock != ucontrol->value.enumerated.item[0]) {
hdspm->tco->wordclock = ucontrol->value.enumerated.item[0];
hdspm_tco_write(hdspm);
return 1;
}
return 0;
}
static int snd_hdspm_info_tco_frame_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "24 fps", "25 fps", "29.97fps",
"29.97 dfps", "30 fps", "30 dfps" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_tco_frame_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm->tco->framerate;
return 0;
}
static int snd_hdspm_put_tco_frame_rate(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
if (hdspm->tco->framerate != ucontrol->value.enumerated.item[0]) {
hdspm->tco->framerate = ucontrol->value.enumerated.item[0];
hdspm_tco_write(hdspm);
return 1;
}
return 0;
}
static int snd_hdspm_info_tco_sync_source(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
static const char *const texts[] = { "LTC", "Video", "WCK" };
ENUMERATED_CTL_INFO(uinfo, texts);
return 0;
}
static int snd_hdspm_get_tco_sync_source(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm->tco->input;
return 0;
}
static int snd_hdspm_put_tco_sync_source(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
if (hdspm->tco->input != ucontrol->value.enumerated.item[0]) {
hdspm->tco->input = ucontrol->value.enumerated.item[0];
hdspm_tco_write(hdspm);
return 1;
}
return 0;
}
static int snd_hdspm_info_tco_word_term(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_info *uinfo)
{
uinfo->type = SNDRV_CTL_ELEM_TYPE_BOOLEAN;
uinfo->count = 1;
uinfo->value.integer.min = 0;
uinfo->value.integer.max = 1;
return 0;
}
static int snd_hdspm_get_tco_word_term(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
ucontrol->value.enumerated.item[0] = hdspm->tco->term;
return 0;
}
static int snd_hdspm_put_tco_word_term(struct snd_kcontrol *kcontrol,
struct snd_ctl_elem_value *ucontrol)
{
struct hdspm *hdspm = snd_kcontrol_chip(kcontrol);
if (hdspm->tco->term != ucontrol->value.enumerated.item[0]) {
hdspm->tco->term = ucontrol->value.enumerated.item[0];
hdspm_tco_write(hdspm);
return 1;
}
return 0;
}
static int hdspm_update_simple_mixer_controls(struct hdspm * hdspm)
{
int i;
for (i = hdspm->ds_out_channels; i < hdspm->ss_out_channels; ++i) {
if (hdspm->system_sample_rate > 48000) {
hdspm->playback_mixer_ctls[i]->vd[0].access =
SNDRV_CTL_ELEM_ACCESS_INACTIVE |
SNDRV_CTL_ELEM_ACCESS_READ |
SNDRV_CTL_ELEM_ACCESS_VOLATILE;
} else {
hdspm->playback_mixer_ctls[i]->vd[0].access =
SNDRV_CTL_ELEM_ACCESS_READWRITE |
SNDRV_CTL_ELEM_ACCESS_VOLATILE;
}
snd_ctl_notify(hdspm->card, SNDRV_CTL_EVENT_MASK_VALUE |
SNDRV_CTL_EVENT_MASK_INFO,
&hdspm->playback_mixer_ctls[i]->id);
}
return 0;
}
static int snd_hdspm_create_controls(struct snd_card *card,
struct hdspm *hdspm)
{
unsigned int idx, limit;
int err;
struct snd_kcontrol *kctl;
struct snd_kcontrol_new *list = NULL;
switch (hdspm->io_type) {
case MADI:
list = snd_hdspm_controls_madi;
limit = ARRAY_SIZE(snd_hdspm_controls_madi);
break;
case MADIface:
list = snd_hdspm_controls_madiface;
limit = ARRAY_SIZE(snd_hdspm_controls_madiface);
break;
case AIO:
list = snd_hdspm_controls_aio;
limit = ARRAY_SIZE(snd_hdspm_controls_aio);
break;
case RayDAT:
list = snd_hdspm_controls_raydat;
limit = ARRAY_SIZE(snd_hdspm_controls_raydat);
break;
case AES32:
list = snd_hdspm_controls_aes32;
limit = ARRAY_SIZE(snd_hdspm_controls_aes32);
break;
}
if (NULL != list) {
for (idx = 0; idx < limit; idx++) {
err = snd_ctl_add(card,
snd_ctl_new1(&list[idx], hdspm));
if (err < 0)
return err;
}
}
snd_hdspm_playback_mixer.name = "Chn";
if (hdspm->system_sample_rate >= 128000) {
limit = hdspm->qs_out_channels;
} else if (hdspm->system_sample_rate >= 64000) {
limit = hdspm->ds_out_channels;
} else {
limit = hdspm->ss_out_channels;
}
for (idx = 0; idx < limit; ++idx) {
snd_hdspm_playback_mixer.index = idx + 1;
kctl = snd_ctl_new1(&snd_hdspm_playback_mixer, hdspm);
err = snd_ctl_add(card, kctl);
if (err < 0)
return err;
hdspm->playback_mixer_ctls[idx] = kctl;
}
if (hdspm->tco) {
list = snd_hdspm_controls_tco;
limit = ARRAY_SIZE(snd_hdspm_controls_tco);
for (idx = 0; idx < limit; idx++) {
err = snd_ctl_add(card,
snd_ctl_new1(&list[idx], hdspm));
if (err < 0)
return err;
}
}
return 0;
}
static void
snd_hdspm_proc_read_tco(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdspm *hdspm = entry->private_data;
unsigned int status, control;
int a, ltc, frames, seconds, minutes, hours;
unsigned int period;
u64 freq_const = 0;
u32 rate;
snd_iprintf(buffer, "--- TCO ---\n");
status = hdspm_read(hdspm, HDSPM_statusRegister);
control = hdspm->control_register;
if (status & HDSPM_tco_detect) {
snd_iprintf(buffer, "TCO module detected.\n");
a = hdspm_read(hdspm, HDSPM_RD_TCO+4);
if (a & HDSPM_TCO1_LTC_Input_valid) {
snd_iprintf(buffer, " LTC valid, ");
switch (a & (HDSPM_TCO1_LTC_Format_LSB |
HDSPM_TCO1_LTC_Format_MSB)) {
case 0:
snd_iprintf(buffer, "24 fps, ");
break;
case HDSPM_TCO1_LTC_Format_LSB:
snd_iprintf(buffer, "25 fps, ");
break;
case HDSPM_TCO1_LTC_Format_MSB:
snd_iprintf(buffer, "29.97 fps, ");
break;
default:
snd_iprintf(buffer, "30 fps, ");
break;
}
if (a & HDSPM_TCO1_set_drop_frame_flag) {
snd_iprintf(buffer, "drop frame\n");
} else {
snd_iprintf(buffer, "full frame\n");
}
} else {
snd_iprintf(buffer, " no LTC\n");
}
if (a & HDSPM_TCO1_Video_Input_Format_NTSC) {
snd_iprintf(buffer, " Video: NTSC\n");
} else if (a & HDSPM_TCO1_Video_Input_Format_PAL) {
snd_iprintf(buffer, " Video: PAL\n");
} else {
snd_iprintf(buffer, " No video\n");
}
if (a & HDSPM_TCO1_TCO_lock) {
snd_iprintf(buffer, " Sync: lock\n");
} else {
snd_iprintf(buffer, " Sync: no lock\n");
}
switch (hdspm->io_type) {
case MADI:
case AES32:
freq_const = 110069313433624ULL;
break;
case RayDAT:
case AIO:
freq_const = 104857600000000ULL;
break;
case MADIface:
break;
}
period = hdspm_read(hdspm, HDSPM_RD_PLL_FREQ);
snd_iprintf(buffer, " period: %u\n", period);
rate = div_u64(freq_const, period);
if (control & HDSPM_QuadSpeed) {
rate *= 4;
} else if (control & HDSPM_DoubleSpeed) {
rate *= 2;
}
snd_iprintf(buffer, " Frequency: %u Hz\n",
(unsigned int) rate);
ltc = hdspm_read(hdspm, HDSPM_RD_TCO);
frames = ltc & 0xF;
ltc >>= 4;
frames += (ltc & 0x3) * 10;
ltc >>= 4;
seconds = ltc & 0xF;
ltc >>= 4;
seconds += (ltc & 0x7) * 10;
ltc >>= 4;
minutes = ltc & 0xF;
ltc >>= 4;
minutes += (ltc & 0x7) * 10;
ltc >>= 4;
hours = ltc & 0xF;
ltc >>= 4;
hours += (ltc & 0x3) * 10;
snd_iprintf(buffer,
" LTC In: %02d:%02d:%02d:%02d\n",
hours, minutes, seconds, frames);
} else {
snd_iprintf(buffer, "No TCO module detected.\n");
}
}
static void
snd_hdspm_proc_read_madi(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdspm *hdspm = entry->private_data;
unsigned int status, status2, control, freq;
char *pref_sync_ref;
char *autosync_ref;
char *system_clock_mode;
char *insel;
int x, x2;
status = hdspm_read(hdspm, HDSPM_statusRegister);
status2 = hdspm_read(hdspm, HDSPM_statusRegister2);
control = hdspm->control_register;
freq = hdspm_read(hdspm, HDSPM_timecodeRegister);
snd_iprintf(buffer, "%s (Card #%d) Rev.%x Status2first3bits: %x\n",
hdspm->card_name, hdspm->card->number + 1,
hdspm->firmware_rev,
(status2 & HDSPM_version0) |
(status2 & HDSPM_version1) | (status2 &
HDSPM_version2));
snd_iprintf(buffer, "HW Serial: 0x%06x%06x\n",
(hdspm_read(hdspm, HDSPM_midiStatusIn1)>>8) & 0xFFFFFF,
hdspm->serial);
snd_iprintf(buffer, "IRQ: %d Registers bus: 0x%lx VM: 0x%lx\n",
hdspm->irq, hdspm->port, (unsigned long)hdspm->iobase);
snd_iprintf(buffer, "--- System ---\n");
snd_iprintf(buffer,
"IRQ Pending: Audio=%d, MIDI0=%d, MIDI1=%d, IRQcount=%d\n",
status & HDSPM_audioIRQPending,
(status & HDSPM_midi0IRQPending) ? 1 : 0,
(status & HDSPM_midi1IRQPending) ? 1 : 0,
hdspm->irq_count);
snd_iprintf(buffer,
"HW pointer: id = %d, rawptr = %d (%d->%d) "
"estimated= %ld (bytes)\n",
((status & HDSPM_BufferID) ? 1 : 0),
(status & HDSPM_BufferPositionMask),
(status & HDSPM_BufferPositionMask) %
(2 * (int)hdspm->period_bytes),
((status & HDSPM_BufferPositionMask) - 64) %
(2 * (int)hdspm->period_bytes),
(long) hdspm_hw_pointer(hdspm) * 4);
snd_iprintf(buffer,
"MIDI FIFO: Out1=0x%x, Out2=0x%x, In1=0x%x, In2=0x%x \n",
hdspm_read(hdspm, HDSPM_midiStatusOut0) & 0xFF,
hdspm_read(hdspm, HDSPM_midiStatusOut1) & 0xFF,
hdspm_read(hdspm, HDSPM_midiStatusIn0) & 0xFF,
hdspm_read(hdspm, HDSPM_midiStatusIn1) & 0xFF);
snd_iprintf(buffer,
"MIDIoverMADI FIFO: In=0x%x, Out=0x%x \n",
hdspm_read(hdspm, HDSPM_midiStatusIn2) & 0xFF,
hdspm_read(hdspm, HDSPM_midiStatusOut2) & 0xFF);
snd_iprintf(buffer,
"Register: ctrl1=0x%x, ctrl2=0x%x, status1=0x%x, "
"status2=0x%x\n",
hdspm->control_register, hdspm->control2_register,
status, status2);
snd_iprintf(buffer, "--- Settings ---\n");
x = hdspm_get_latency(hdspm);
snd_iprintf(buffer,
"Size (Latency): %d samples (2 periods of %lu bytes)\n",
x, (unsigned long) hdspm->period_bytes);
snd_iprintf(buffer, "Line out: %s\n",
(hdspm->control_register & HDSPM_LineOut) ? "on " : "off");
switch (hdspm->control_register & HDSPM_InputMask) {
case HDSPM_InputOptical:
insel = "Optical";
break;
case HDSPM_InputCoaxial:
insel = "Coaxial";
break;
default:
insel = "Unknown";
}
snd_iprintf(buffer,
"ClearTrackMarker = %s, Transmit in %s Channel Mode, "
"Auto Input %s\n",
(hdspm->control_register & HDSPM_clr_tms) ? "on" : "off",
(hdspm->control_register & HDSPM_TX_64ch) ? "64" : "56",
(hdspm->control_register & HDSPM_AutoInp) ? "on" : "off");
if (!(hdspm->control_register & HDSPM_ClockModeMaster))
system_clock_mode = "AutoSync";
else
system_clock_mode = "Master";
snd_iprintf(buffer, "AutoSync Reference: %s\n", system_clock_mode);
switch (hdspm_pref_sync_ref(hdspm)) {
case HDSPM_SYNC_FROM_WORD:
pref_sync_ref = "Word Clock";
break;
case HDSPM_SYNC_FROM_MADI:
pref_sync_ref = "MADI Sync";
break;
case HDSPM_SYNC_FROM_TCO:
pref_sync_ref = "TCO";
break;
case HDSPM_SYNC_FROM_SYNC_IN:
pref_sync_ref = "Sync In";
break;
default:
pref_sync_ref = "XXXX Clock";
break;
}
snd_iprintf(buffer, "Preferred Sync Reference: %s\n",
pref_sync_ref);
snd_iprintf(buffer, "System Clock Frequency: %d\n",
hdspm->system_sample_rate);
snd_iprintf(buffer, "--- Status:\n");
x = status & HDSPM_madiSync;
x2 = status2 & HDSPM_wcSync;
snd_iprintf(buffer, "Inputs MADI=%s, WordClock=%s\n",
(status & HDSPM_madiLock) ? (x ? "Sync" : "Lock") :
"NoLock",
(status2 & HDSPM_wcLock) ? (x2 ? "Sync" : "Lock") :
"NoLock");
switch (hdspm_autosync_ref(hdspm)) {
case HDSPM_AUTOSYNC_FROM_SYNC_IN:
autosync_ref = "Sync In";
break;
case HDSPM_AUTOSYNC_FROM_TCO:
autosync_ref = "TCO";
break;
case HDSPM_AUTOSYNC_FROM_WORD:
autosync_ref = "Word Clock";
break;
case HDSPM_AUTOSYNC_FROM_MADI:
autosync_ref = "MADI Sync";
break;
case HDSPM_AUTOSYNC_FROM_NONE:
autosync_ref = "Input not valid";
break;
default:
autosync_ref = "---";
break;
}
snd_iprintf(buffer,
"AutoSync: Reference= %s, Freq=%d (MADI = %d, Word = %d)\n",
autosync_ref, hdspm_external_sample_rate(hdspm),
(status & HDSPM_madiFreqMask) >> 22,
(status2 & HDSPM_wcFreqMask) >> 5);
snd_iprintf(buffer, "Input: %s, Mode=%s\n",
(status & HDSPM_AB_int) ? "Coax" : "Optical",
(status & HDSPM_RX_64ch) ? "64 channels" :
"56 channels");
snd_hdspm_proc_read_tco(entry, buffer);
snd_iprintf(buffer, "\n");
}
static void
snd_hdspm_proc_read_aes32(struct snd_info_entry * entry,
struct snd_info_buffer *buffer)
{
struct hdspm *hdspm = entry->private_data;
unsigned int status;
unsigned int status2;
unsigned int timecode;
unsigned int wcLock, wcSync;
int pref_syncref;
char *autosync_ref;
int x;
status = hdspm_read(hdspm, HDSPM_statusRegister);
status2 = hdspm_read(hdspm, HDSPM_statusRegister2);
timecode = hdspm_read(hdspm, HDSPM_timecodeRegister);
snd_iprintf(buffer, "%s (Card #%d) Rev.%x\n",
hdspm->card_name, hdspm->card->number + 1,
hdspm->firmware_rev);
snd_iprintf(buffer, "IRQ: %d Registers bus: 0x%lx VM: 0x%lx\n",
hdspm->irq, hdspm->port, (unsigned long)hdspm->iobase);
snd_iprintf(buffer, "--- System ---\n");
snd_iprintf(buffer,
"IRQ Pending: Audio=%d, MIDI0=%d, MIDI1=%d, IRQcount=%d\n",
status & HDSPM_audioIRQPending,
(status & HDSPM_midi0IRQPending) ? 1 : 0,
(status & HDSPM_midi1IRQPending) ? 1 : 0,
hdspm->irq_count);
snd_iprintf(buffer,
"HW pointer: id = %d, rawptr = %d (%d->%d) "
"estimated= %ld (bytes)\n",
((status & HDSPM_BufferID) ? 1 : 0),
(status & HDSPM_BufferPositionMask),
(status & HDSPM_BufferPositionMask) %
(2 * (int)hdspm->period_bytes),
((status & HDSPM_BufferPositionMask) - 64) %
(2 * (int)hdspm->period_bytes),
(long) hdspm_hw_pointer(hdspm) * 4);
snd_iprintf(buffer,
"MIDI FIFO: Out1=0x%x, Out2=0x%x, In1=0x%x, In2=0x%x \n",
hdspm_read(hdspm, HDSPM_midiStatusOut0) & 0xFF,
hdspm_read(hdspm, HDSPM_midiStatusOut1) & 0xFF,
hdspm_read(hdspm, HDSPM_midiStatusIn0) & 0xFF,
hdspm_read(hdspm, HDSPM_midiStatusIn1) & 0xFF);
snd_iprintf(buffer,
"MIDIoverMADI FIFO: In=0x%x, Out=0x%x \n",
hdspm_read(hdspm, HDSPM_midiStatusIn2) & 0xFF,
hdspm_read(hdspm, HDSPM_midiStatusOut2) & 0xFF);
snd_iprintf(buffer,
"Register: ctrl1=0x%x, ctrl2=0x%x, status1=0x%x, "
"status2=0x%x\n",
hdspm->control_register, hdspm->control2_register,
status, status2);
snd_iprintf(buffer, "--- Settings ---\n");
x = hdspm_get_latency(hdspm);
snd_iprintf(buffer,
"Size (Latency): %d samples (2 periods of %lu bytes)\n",
x, (unsigned long) hdspm->period_bytes);
snd_iprintf(buffer, "Line out: %s\n",
(hdspm->
control_register & HDSPM_LineOut) ? "on " : "off");
snd_iprintf(buffer,
"ClearTrackMarker %s, Emphasis %s, Dolby %s\n",
(hdspm->
control_register & HDSPM_clr_tms) ? "on" : "off",
(hdspm->
control_register & HDSPM_Emphasis) ? "on" : "off",
(hdspm->
control_register & HDSPM_Dolby) ? "on" : "off");
pref_syncref = hdspm_pref_sync_ref(hdspm);
if (pref_syncref == 0)
snd_iprintf(buffer, "Preferred Sync Reference: Word Clock\n");
else
snd_iprintf(buffer, "Preferred Sync Reference: AES%d\n",
pref_syncref);
snd_iprintf(buffer, "System Clock Frequency: %d\n",
hdspm->system_sample_rate);
snd_iprintf(buffer, "Double speed: %s\n",
hdspm->control_register & HDSPM_DS_DoubleWire?
"Double wire" : "Single wire");
snd_iprintf(buffer, "Quad speed: %s\n",
hdspm->control_register & HDSPM_QS_DoubleWire?
"Double wire" :
hdspm->control_register & HDSPM_QS_QuadWire?
"Quad wire" : "Single wire");
snd_iprintf(buffer, "--- Status:\n");
wcLock = status & HDSPM_AES32_wcLock;
wcSync = wcLock && (status & HDSPM_AES32_wcSync);
snd_iprintf(buffer, "Word: %s Frequency: %d\n",
(wcLock) ? (wcSync ? "Sync " : "Lock ") : "No Lock",
HDSPM_bit2freq((status >> HDSPM_AES32_wcFreq_bit) & 0xF));
for (x = 0; x < 8; x++) {
snd_iprintf(buffer, "AES%d: %s Frequency: %d\n",
x+1,
(status2 & (HDSPM_LockAES >> x)) ?
"Sync " : "No Lock",
HDSPM_bit2freq((timecode >> (4*x)) & 0xF));
}
switch (hdspm_autosync_ref(hdspm)) {
case HDSPM_AES32_AUTOSYNC_FROM_NONE:
autosync_ref = "None"; break;
case HDSPM_AES32_AUTOSYNC_FROM_WORD:
autosync_ref = "Word Clock"; break;
case HDSPM_AES32_AUTOSYNC_FROM_AES1:
autosync_ref = "AES1"; break;
case HDSPM_AES32_AUTOSYNC_FROM_AES2:
autosync_ref = "AES2"; break;
case HDSPM_AES32_AUTOSYNC_FROM_AES3:
autosync_ref = "AES3"; break;
case HDSPM_AES32_AUTOSYNC_FROM_AES4:
autosync_ref = "AES4"; break;
case HDSPM_AES32_AUTOSYNC_FROM_AES5:
autosync_ref = "AES5"; break;
case HDSPM_AES32_AUTOSYNC_FROM_AES6:
autosync_ref = "AES6"; break;
case HDSPM_AES32_AUTOSYNC_FROM_AES7:
autosync_ref = "AES7"; break;
case HDSPM_AES32_AUTOSYNC_FROM_AES8:
autosync_ref = "AES8"; break;
case HDSPM_AES32_AUTOSYNC_FROM_TCO:
autosync_ref = "TCO"; break;
case HDSPM_AES32_AUTOSYNC_FROM_SYNC_IN:
autosync_ref = "Sync In"; break;
default:
autosync_ref = "---"; break;
}
snd_iprintf(buffer, "AutoSync ref = %s\n", autosync_ref);
snd_hdspm_proc_read_tco(entry, buffer);
snd_iprintf(buffer, "\n");
}
static void
snd_hdspm_proc_read_raydat(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdspm *hdspm = entry->private_data;
unsigned int status1, status2, status3, control, i;
unsigned int lock, sync;
status1 = hdspm_read(hdspm, HDSPM_RD_STATUS_1);
status2 = hdspm_read(hdspm, HDSPM_RD_STATUS_2);
status3 = hdspm_read(hdspm, HDSPM_RD_STATUS_3);
control = hdspm->control_register;
snd_iprintf(buffer, "STATUS1: 0x%08x\n", status1);
snd_iprintf(buffer, "STATUS2: 0x%08x\n", status2);
snd_iprintf(buffer, "STATUS3: 0x%08x\n", status3);
snd_iprintf(buffer, "\n*** CLOCK MODE\n\n");
snd_iprintf(buffer, "Clock mode : %s\n",
(hdspm_system_clock_mode(hdspm) == 0) ? "master" : "slave");
snd_iprintf(buffer, "System frequency: %d Hz\n",
hdspm_get_system_sample_rate(hdspm));
snd_iprintf(buffer, "\n*** INPUT STATUS\n\n");
lock = 0x1;
sync = 0x100;
for (i = 0; i < 8; i++) {
snd_iprintf(buffer, "s1_input %d: Lock %d, Sync %d, Freq %s\n",
i,
(status1 & lock) ? 1 : 0,
(status1 & sync) ? 1 : 0,
texts_freq[(status2 >> (i * 4)) & 0xF]);
lock = lock<<1;
sync = sync<<1;
}
snd_iprintf(buffer, "WC input: Lock %d, Sync %d, Freq %s\n",
(status1 & 0x1000000) ? 1 : 0,
(status1 & 0x2000000) ? 1 : 0,
texts_freq[(status1 >> 16) & 0xF]);
snd_iprintf(buffer, "TCO input: Lock %d, Sync %d, Freq %s\n",
(status1 & 0x4000000) ? 1 : 0,
(status1 & 0x8000000) ? 1 : 0,
texts_freq[(status1 >> 20) & 0xF]);
snd_iprintf(buffer, "SYNC IN: Lock %d, Sync %d, Freq %s\n",
(status3 & 0x400) ? 1 : 0,
(status3 & 0x800) ? 1 : 0,
texts_freq[(status2 >> 12) & 0xF]);
}
static void
snd_hdspm_proc_read_debug(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdspm *hdspm = entry->private_data;
int j,i;
for (i = 0; i < 256 ; i += j) {
snd_iprintf(buffer, "0x%08X: ", i);
for (j = 0; j < 16; j += 4)
snd_iprintf(buffer, "%08X ", hdspm_read(hdspm, i + j));
snd_iprintf(buffer, "\n");
}
}
static void snd_hdspm_proc_ports_in(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdspm *hdspm = entry->private_data;
int i;
snd_iprintf(buffer, "# generated by hdspm\n");
for (i = 0; i < hdspm->max_channels_in; i++) {
snd_iprintf(buffer, "%d=%s\n", i+1, hdspm->port_names_in[i]);
}
}
static void snd_hdspm_proc_ports_out(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct hdspm *hdspm = entry->private_data;
int i;
snd_iprintf(buffer, "# generated by hdspm\n");
for (i = 0; i < hdspm->max_channels_out; i++) {
snd_iprintf(buffer, "%d=%s\n", i+1, hdspm->port_names_out[i]);
}
}
static void snd_hdspm_proc_init(struct hdspm *hdspm)
{
struct snd_info_entry *entry;
if (!snd_card_proc_new(hdspm->card, "hdspm", &entry)) {
switch (hdspm->io_type) {
case AES32:
snd_info_set_text_ops(entry, hdspm,
snd_hdspm_proc_read_aes32);
break;
case MADI:
snd_info_set_text_ops(entry, hdspm,
snd_hdspm_proc_read_madi);
break;
case MADIface:
break;
case RayDAT:
snd_info_set_text_ops(entry, hdspm,
snd_hdspm_proc_read_raydat);
break;
case AIO:
break;
}
}
if (!snd_card_proc_new(hdspm->card, "ports.in", &entry)) {
snd_info_set_text_ops(entry, hdspm, snd_hdspm_proc_ports_in);
}
if (!snd_card_proc_new(hdspm->card, "ports.out", &entry)) {
snd_info_set_text_ops(entry, hdspm, snd_hdspm_proc_ports_out);
}
#ifdef CONFIG_SND_DEBUG
if (!snd_card_proc_new(hdspm->card, "debug", &entry))
snd_info_set_text_ops(entry, hdspm,
snd_hdspm_proc_read_debug);
#endif
}
static int snd_hdspm_set_defaults(struct hdspm * hdspm)
{
hdspm->settings_register = 0;
switch (hdspm->io_type) {
case MADI:
case MADIface:
hdspm->control_register =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000;
break;
case RayDAT:
case AIO:
hdspm->settings_register = 0x1 + 0x1000;
hdspm->control_register =
0x2 + 0x8 + 0x10 + 0x80 + 0x400 + 0x4000 + 0x1000000;
break;
case AES32:
hdspm->control_register =
HDSPM_ClockModeMaster |
hdspm_encode_latency(7) |
HDSPM_SyncRef0 |
HDSPM_LineOut |
HDSPM_Professional;
break;
}
hdspm_write(hdspm, HDSPM_controlRegister, hdspm->control_register);
if (AES32 == hdspm->io_type) {
#ifdef SNDRV_BIG_ENDIAN
hdspm->control2_register = HDSPM_BIGENDIAN_MODE;
#else
hdspm->control2_register = 0;
#endif
hdspm_write(hdspm, HDSPM_control2Reg, hdspm->control2_register);
}
hdspm_compute_period_size(hdspm);
all_in_all_mixer(hdspm, 0 * UNITY_GAIN);
if (hdspm_is_raydat_or_aio(hdspm))
hdspm_write(hdspm, HDSPM_WR_SETTINGS, hdspm->settings_register);
hdspm_set_rate(hdspm, 48000, 1);
return 0;
}
static irqreturn_t snd_hdspm_interrupt(int irq, void *dev_id)
{
struct hdspm *hdspm = (struct hdspm *) dev_id;
unsigned int status;
int i, audio, midi, schedule = 0;
status = hdspm_read(hdspm, HDSPM_statusRegister);
audio = status & HDSPM_audioIRQPending;
midi = status & (HDSPM_midi0IRQPending | HDSPM_midi1IRQPending |
HDSPM_midi2IRQPending | HDSPM_midi3IRQPending);
if (!audio && !midi)
return IRQ_NONE;
hdspm_write(hdspm, HDSPM_interruptConfirmation, 0);
hdspm->irq_count++;
if (audio) {
if (hdspm->capture_substream)
snd_pcm_period_elapsed(hdspm->capture_substream);
if (hdspm->playback_substream)
snd_pcm_period_elapsed(hdspm->playback_substream);
}
if (midi) {
i = 0;
while (i < hdspm->midiPorts) {
if ((hdspm_read(hdspm,
hdspm->midi[i].statusIn) & 0xff) &&
(status & hdspm->midi[i].irq)) {
hdspm->control_register &= ~hdspm->midi[i].ie;
hdspm_write(hdspm, HDSPM_controlRegister,
hdspm->control_register);
hdspm->midi[i].pending = 1;
schedule = 1;
}
i++;
}
if (schedule)
tasklet_hi_schedule(&hdspm->midi_tasklet);
}
return IRQ_HANDLED;
}
static snd_pcm_uframes_t snd_hdspm_hw_pointer(struct snd_pcm_substream
*substream)
{
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
return hdspm_hw_pointer(hdspm);
}
static int snd_hdspm_reset(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime = substream->runtime;
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
struct snd_pcm_substream *other;
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
other = hdspm->capture_substream;
else
other = hdspm->playback_substream;
if (hdspm->running)
runtime->status->hw_ptr = hdspm_hw_pointer(hdspm);
else
runtime->status->hw_ptr = 0;
if (other) {
struct snd_pcm_substream *s;
struct snd_pcm_runtime *oruntime = other->runtime;
snd_pcm_group_for_each_entry(s, substream) {
if (s == other) {
oruntime->status->hw_ptr =
runtime->status->hw_ptr;
break;
}
}
}
return 0;
}
static int snd_hdspm_hw_params(struct snd_pcm_substream *substream,
struct snd_pcm_hw_params *params)
{
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
int err;
int i;
pid_t this_pid;
pid_t other_pid;
spin_lock_irq(&hdspm->lock);
if (substream->pstr->stream == SNDRV_PCM_STREAM_PLAYBACK) {
this_pid = hdspm->playback_pid;
other_pid = hdspm->capture_pid;
} else {
this_pid = hdspm->capture_pid;
other_pid = hdspm->playback_pid;
}
if (other_pid > 0 && this_pid != other_pid) {
if (params_rate(params) != hdspm->system_sample_rate) {
spin_unlock_irq(&hdspm->lock);
_snd_pcm_hw_param_setempty(params,
SNDRV_PCM_HW_PARAM_RATE);
return -EBUSY;
}
if (params_period_size(params) != hdspm->period_bytes / 4) {
spin_unlock_irq(&hdspm->lock);
_snd_pcm_hw_param_setempty(params,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE);
return -EBUSY;
}
}
spin_unlock_irq(&hdspm->lock);
spin_lock_irq(&hdspm->lock);
err = hdspm_set_rate(hdspm, params_rate(params), 0);
if (err < 0) {
dev_info(hdspm->card->dev, "err on hdspm_set_rate: %d\n", err);
spin_unlock_irq(&hdspm->lock);
_snd_pcm_hw_param_setempty(params,
SNDRV_PCM_HW_PARAM_RATE);
return err;
}
spin_unlock_irq(&hdspm->lock);
err = hdspm_set_interrupt_interval(hdspm,
params_period_size(params));
if (err < 0) {
dev_info(hdspm->card->dev,
"err on hdspm_set_interrupt_interval: %d\n", err);
_snd_pcm_hw_param_setempty(params,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE);
return err;
}
err =
snd_pcm_lib_malloc_pages(substream, HDSPM_DMA_AREA_BYTES);
if (err < 0) {
dev_info(hdspm->card->dev,
"err on snd_pcm_lib_malloc_pages: %d\n", err);
return err;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
hdspm_set_sgbuf(hdspm, substream, HDSPM_pageAddressBufferOut,
params_channels(params));
for (i = 0; i < params_channels(params); ++i)
snd_hdspm_enable_out(hdspm, i, 1);
hdspm->playback_buffer =
(unsigned char *) substream->runtime->dma_area;
dev_dbg(hdspm->card->dev,
"Allocated sample buffer for playback at %p\n",
hdspm->playback_buffer);
} else {
hdspm_set_sgbuf(hdspm, substream, HDSPM_pageAddressBufferIn,
params_channels(params));
for (i = 0; i < params_channels(params); ++i)
snd_hdspm_enable_in(hdspm, i, 1);
hdspm->capture_buffer =
(unsigned char *) substream->runtime->dma_area;
dev_dbg(hdspm->card->dev,
"Allocated sample buffer for capture at %p\n",
hdspm->capture_buffer);
}
if (hdspm->io_type == AES32) {
return 0;
}
if (SNDRV_PCM_FORMAT_FLOAT_LE == params_format(params)) {
if (!(hdspm->control_register & HDSPe_FLOAT_FORMAT))
dev_info(hdspm->card->dev,
"Switching to native 32bit LE float format.\n");
hdspm->control_register |= HDSPe_FLOAT_FORMAT;
} else if (SNDRV_PCM_FORMAT_S32_LE == params_format(params)) {
if (hdspm->control_register & HDSPe_FLOAT_FORMAT)
dev_info(hdspm->card->dev,
"Switching to native 32bit LE integer format.\n");
hdspm->control_register &= ~HDSPe_FLOAT_FORMAT;
}
hdspm_write(hdspm, HDSPM_controlRegister, hdspm->control_register);
return 0;
}
static int snd_hdspm_hw_free(struct snd_pcm_substream *substream)
{
int i;
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
for (i = 0; i < hdspm->max_channels_out; ++i)
snd_hdspm_enable_out(hdspm, i, 0);
hdspm->playback_buffer = NULL;
} else {
for (i = 0; i < hdspm->max_channels_in; ++i)
snd_hdspm_enable_in(hdspm, i, 0);
hdspm->capture_buffer = NULL;
}
snd_pcm_lib_free_pages(substream);
return 0;
}
static int snd_hdspm_channel_info(struct snd_pcm_substream *substream,
struct snd_pcm_channel_info *info)
{
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK) {
if (snd_BUG_ON(info->channel >= hdspm->max_channels_out)) {
dev_info(hdspm->card->dev,
"snd_hdspm_channel_info: output channel out of range (%d)\n",
info->channel);
return -EINVAL;
}
if (hdspm->channel_map_out[info->channel] < 0) {
dev_info(hdspm->card->dev,
"snd_hdspm_channel_info: output channel %d mapped out\n",
info->channel);
return -EINVAL;
}
info->offset = hdspm->channel_map_out[info->channel] *
HDSPM_CHANNEL_BUFFER_BYTES;
} else {
if (snd_BUG_ON(info->channel >= hdspm->max_channels_in)) {
dev_info(hdspm->card->dev,
"snd_hdspm_channel_info: input channel out of range (%d)\n",
info->channel);
return -EINVAL;
}
if (hdspm->channel_map_in[info->channel] < 0) {
dev_info(hdspm->card->dev,
"snd_hdspm_channel_info: input channel %d mapped out\n",
info->channel);
return -EINVAL;
}
info->offset = hdspm->channel_map_in[info->channel] *
HDSPM_CHANNEL_BUFFER_BYTES;
}
info->first = 0;
info->step = 32;
return 0;
}
static int snd_hdspm_ioctl(struct snd_pcm_substream *substream,
unsigned int cmd, void *arg)
{
switch (cmd) {
case SNDRV_PCM_IOCTL1_RESET:
return snd_hdspm_reset(substream);
case SNDRV_PCM_IOCTL1_CHANNEL_INFO:
{
struct snd_pcm_channel_info *info = arg;
return snd_hdspm_channel_info(substream, info);
}
default:
break;
}
return snd_pcm_lib_ioctl(substream, cmd, arg);
}
static int snd_hdspm_trigger(struct snd_pcm_substream *substream, int cmd)
{
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
struct snd_pcm_substream *other;
int running;
spin_lock(&hdspm->lock);
running = hdspm->running;
switch (cmd) {
case SNDRV_PCM_TRIGGER_START:
running |= 1 << substream->stream;
break;
case SNDRV_PCM_TRIGGER_STOP:
running &= ~(1 << substream->stream);
break;
default:
snd_BUG();
spin_unlock(&hdspm->lock);
return -EINVAL;
}
if (substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
other = hdspm->capture_substream;
else
other = hdspm->playback_substream;
if (other) {
struct snd_pcm_substream *s;
snd_pcm_group_for_each_entry(s, substream) {
if (s == other) {
snd_pcm_trigger_done(s, substream);
if (cmd == SNDRV_PCM_TRIGGER_START)
running |= 1 << s->stream;
else
running &= ~(1 << s->stream);
goto _ok;
}
}
if (cmd == SNDRV_PCM_TRIGGER_START) {
if (!(running & (1 << SNDRV_PCM_STREAM_PLAYBACK))
&& substream->stream ==
SNDRV_PCM_STREAM_CAPTURE)
hdspm_silence_playback(hdspm);
} else {
if (running &&
substream->stream == SNDRV_PCM_STREAM_PLAYBACK)
hdspm_silence_playback(hdspm);
}
} else {
if (substream->stream == SNDRV_PCM_STREAM_CAPTURE)
hdspm_silence_playback(hdspm);
}
_ok:
snd_pcm_trigger_done(substream, substream);
if (!hdspm->running && running)
hdspm_start_audio(hdspm);
else if (hdspm->running && !running)
hdspm_stop_audio(hdspm);
hdspm->running = running;
spin_unlock(&hdspm->lock);
return 0;
}
static int snd_hdspm_prepare(struct snd_pcm_substream *substream)
{
return 0;
}
static int snd_hdspm_hw_rule_in_channels_rate(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct hdspm *hdspm = rule->private;
struct snd_interval *c =
hw_param_interval(params, SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_interval *r =
hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE);
if (r->min > 96000 && r->max <= 192000) {
struct snd_interval t = {
.min = hdspm->qs_in_channels,
.max = hdspm->qs_in_channels,
.integer = 1,
};
return snd_interval_refine(c, &t);
} else if (r->min > 48000 && r->max <= 96000) {
struct snd_interval t = {
.min = hdspm->ds_in_channels,
.max = hdspm->ds_in_channels,
.integer = 1,
};
return snd_interval_refine(c, &t);
} else if (r->max < 64000) {
struct snd_interval t = {
.min = hdspm->ss_in_channels,
.max = hdspm->ss_in_channels,
.integer = 1,
};
return snd_interval_refine(c, &t);
}
return 0;
}
static int snd_hdspm_hw_rule_out_channels_rate(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule * rule)
{
struct hdspm *hdspm = rule->private;
struct snd_interval *c =
hw_param_interval(params, SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_interval *r =
hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE);
if (r->min > 96000 && r->max <= 192000) {
struct snd_interval t = {
.min = hdspm->qs_out_channels,
.max = hdspm->qs_out_channels,
.integer = 1,
};
return snd_interval_refine(c, &t);
} else if (r->min > 48000 && r->max <= 96000) {
struct snd_interval t = {
.min = hdspm->ds_out_channels,
.max = hdspm->ds_out_channels,
.integer = 1,
};
return snd_interval_refine(c, &t);
} else if (r->max < 64000) {
struct snd_interval t = {
.min = hdspm->ss_out_channels,
.max = hdspm->ss_out_channels,
.integer = 1,
};
return snd_interval_refine(c, &t);
} else {
}
return 0;
}
static int snd_hdspm_hw_rule_rate_in_channels(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule * rule)
{
struct hdspm *hdspm = rule->private;
struct snd_interval *c =
hw_param_interval(params, SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_interval *r =
hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE);
if (c->min >= hdspm->ss_in_channels) {
struct snd_interval t = {
.min = 32000,
.max = 48000,
.integer = 1,
};
return snd_interval_refine(r, &t);
} else if (c->max <= hdspm->qs_in_channels) {
struct snd_interval t = {
.min = 128000,
.max = 192000,
.integer = 1,
};
return snd_interval_refine(r, &t);
} else if (c->max <= hdspm->ds_in_channels) {
struct snd_interval t = {
.min = 64000,
.max = 96000,
.integer = 1,
};
return snd_interval_refine(r, &t);
}
return 0;
}
static int snd_hdspm_hw_rule_rate_out_channels(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
struct hdspm *hdspm = rule->private;
struct snd_interval *c =
hw_param_interval(params, SNDRV_PCM_HW_PARAM_CHANNELS);
struct snd_interval *r =
hw_param_interval(params, SNDRV_PCM_HW_PARAM_RATE);
if (c->min >= hdspm->ss_out_channels) {
struct snd_interval t = {
.min = 32000,
.max = 48000,
.integer = 1,
};
return snd_interval_refine(r, &t);
} else if (c->max <= hdspm->qs_out_channels) {
struct snd_interval t = {
.min = 128000,
.max = 192000,
.integer = 1,
};
return snd_interval_refine(r, &t);
} else if (c->max <= hdspm->ds_out_channels) {
struct snd_interval t = {
.min = 64000,
.max = 96000,
.integer = 1,
};
return snd_interval_refine(r, &t);
}
return 0;
}
static int snd_hdspm_hw_rule_in_channels(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
unsigned int list[3];
struct hdspm *hdspm = rule->private;
struct snd_interval *c = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
list[0] = hdspm->qs_in_channels;
list[1] = hdspm->ds_in_channels;
list[2] = hdspm->ss_in_channels;
return snd_interval_list(c, 3, list, 0);
}
static int snd_hdspm_hw_rule_out_channels(struct snd_pcm_hw_params *params,
struct snd_pcm_hw_rule *rule)
{
unsigned int list[3];
struct hdspm *hdspm = rule->private;
struct snd_interval *c = hw_param_interval(params,
SNDRV_PCM_HW_PARAM_CHANNELS);
list[0] = hdspm->qs_out_channels;
list[1] = hdspm->ds_out_channels;
list[2] = hdspm->ss_out_channels;
return snd_interval_list(c, 3, list, 0);
}
static int snd_hdspm_playback_open(struct snd_pcm_substream *substream)
{
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
spin_lock_irq(&hdspm->lock);
snd_pcm_set_sync(substream);
runtime->hw = snd_hdspm_playback_subinfo;
if (hdspm->capture_substream == NULL)
hdspm_stop_audio(hdspm);
hdspm->playback_pid = current->pid;
hdspm->playback_substream = substream;
spin_unlock_irq(&hdspm->lock);
snd_pcm_hw_constraint_msbits(runtime, 0, 32, 24);
snd_pcm_hw_constraint_pow2(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_SIZE);
switch (hdspm->io_type) {
case AIO:
case RayDAT:
snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE,
32, 4096);
snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE,
16384, 16384);
break;
default:
snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE,
64, 8192);
break;
}
if (AES32 == hdspm->io_type) {
runtime->hw.rates |= SNDRV_PCM_RATE_KNOT;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hdspm_hw_constraints_aes32_sample_rates);
} else {
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
snd_hdspm_hw_rule_rate_out_channels, hdspm,
SNDRV_PCM_HW_PARAM_CHANNELS, -1);
}
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
snd_hdspm_hw_rule_out_channels, hdspm,
SNDRV_PCM_HW_PARAM_CHANNELS, -1);
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
snd_hdspm_hw_rule_out_channels_rate, hdspm,
SNDRV_PCM_HW_PARAM_RATE, -1);
return 0;
}
static int snd_hdspm_playback_release(struct snd_pcm_substream *substream)
{
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
spin_lock_irq(&hdspm->lock);
hdspm->playback_pid = -1;
hdspm->playback_substream = NULL;
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_capture_open(struct snd_pcm_substream *substream)
{
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
struct snd_pcm_runtime *runtime = substream->runtime;
spin_lock_irq(&hdspm->lock);
snd_pcm_set_sync(substream);
runtime->hw = snd_hdspm_capture_subinfo;
if (hdspm->playback_substream == NULL)
hdspm_stop_audio(hdspm);
hdspm->capture_pid = current->pid;
hdspm->capture_substream = substream;
spin_unlock_irq(&hdspm->lock);
snd_pcm_hw_constraint_msbits(runtime, 0, 32, 24);
snd_pcm_hw_constraint_pow2(runtime, 0, SNDRV_PCM_HW_PARAM_PERIOD_SIZE);
switch (hdspm->io_type) {
case AIO:
case RayDAT:
snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE,
32, 4096);
snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_BUFFER_SIZE,
16384, 16384);
break;
default:
snd_pcm_hw_constraint_minmax(runtime,
SNDRV_PCM_HW_PARAM_PERIOD_SIZE,
64, 8192);
break;
}
if (AES32 == hdspm->io_type) {
runtime->hw.rates |= SNDRV_PCM_RATE_KNOT;
snd_pcm_hw_constraint_list(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
&hdspm_hw_constraints_aes32_sample_rates);
} else {
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_RATE,
snd_hdspm_hw_rule_rate_in_channels, hdspm,
SNDRV_PCM_HW_PARAM_CHANNELS, -1);
}
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
snd_hdspm_hw_rule_in_channels, hdspm,
SNDRV_PCM_HW_PARAM_CHANNELS, -1);
snd_pcm_hw_rule_add(runtime, 0, SNDRV_PCM_HW_PARAM_CHANNELS,
snd_hdspm_hw_rule_in_channels_rate, hdspm,
SNDRV_PCM_HW_PARAM_RATE, -1);
return 0;
}
static int snd_hdspm_capture_release(struct snd_pcm_substream *substream)
{
struct hdspm *hdspm = snd_pcm_substream_chip(substream);
spin_lock_irq(&hdspm->lock);
hdspm->capture_pid = -1;
hdspm->capture_substream = NULL;
spin_unlock_irq(&hdspm->lock);
return 0;
}
static int snd_hdspm_hwdep_dummy_op(struct snd_hwdep *hw, struct file *file)
{
return 0;
}
static inline int copy_u32_le(void __user *dest, void __iomem *src)
{
u32 val = readl(src);
return copy_to_user(dest, &val, 4);
}
static int snd_hdspm_hwdep_ioctl(struct snd_hwdep *hw, struct file *file,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
struct hdspm *hdspm = hw->private_data;
struct hdspm_mixer_ioctl mixer;
struct hdspm_config info;
struct hdspm_status status;
struct hdspm_version hdspm_version;
struct hdspm_peak_rms *levels;
struct hdspm_ltc ltc;
unsigned int statusregister;
long unsigned int s;
int i = 0;
switch (cmd) {
case SNDRV_HDSPM_IOCTL_GET_PEAK_RMS:
levels = &hdspm->peak_rms;
for (i = 0; i < HDSPM_MAX_CHANNELS; i++) {
levels->input_peaks[i] =
readl(hdspm->iobase +
HDSPM_MADI_INPUT_PEAK + i*4);
levels->playback_peaks[i] =
readl(hdspm->iobase +
HDSPM_MADI_PLAYBACK_PEAK + i*4);
levels->output_peaks[i] =
readl(hdspm->iobase +
HDSPM_MADI_OUTPUT_PEAK + i*4);
levels->input_rms[i] =
((uint64_t) readl(hdspm->iobase +
HDSPM_MADI_INPUT_RMS_H + i*4) << 32) |
(uint64_t) readl(hdspm->iobase +
HDSPM_MADI_INPUT_RMS_L + i*4);
levels->playback_rms[i] =
((uint64_t)readl(hdspm->iobase +
HDSPM_MADI_PLAYBACK_RMS_H+i*4) << 32) |
(uint64_t)readl(hdspm->iobase +
HDSPM_MADI_PLAYBACK_RMS_L + i*4);
levels->output_rms[i] =
((uint64_t)readl(hdspm->iobase +
HDSPM_MADI_OUTPUT_RMS_H + i*4) << 32) |
(uint64_t)readl(hdspm->iobase +
HDSPM_MADI_OUTPUT_RMS_L + i*4);
}
if (hdspm->system_sample_rate > 96000) {
levels->speed = qs;
} else if (hdspm->system_sample_rate > 48000) {
levels->speed = ds;
} else {
levels->speed = ss;
}
levels->status2 = hdspm_read(hdspm, HDSPM_statusRegister2);
s = copy_to_user(argp, levels, sizeof(struct hdspm_peak_rms));
if (0 != s) {
return -EFAULT;
}
break;
case SNDRV_HDSPM_IOCTL_GET_LTC:
ltc.ltc = hdspm_read(hdspm, HDSPM_RD_TCO);
i = hdspm_read(hdspm, HDSPM_RD_TCO + 4);
if (i & HDSPM_TCO1_LTC_Input_valid) {
switch (i & (HDSPM_TCO1_LTC_Format_LSB |
HDSPM_TCO1_LTC_Format_MSB)) {
case 0:
ltc.format = fps_24;
break;
case HDSPM_TCO1_LTC_Format_LSB:
ltc.format = fps_25;
break;
case HDSPM_TCO1_LTC_Format_MSB:
ltc.format = fps_2997;
break;
default:
ltc.format = fps_30;
break;
}
if (i & HDSPM_TCO1_set_drop_frame_flag) {
ltc.frame = drop_frame;
} else {
ltc.frame = full_frame;
}
} else {
ltc.format = format_invalid;
ltc.frame = frame_invalid;
}
if (i & HDSPM_TCO1_Video_Input_Format_NTSC) {
ltc.input_format = ntsc;
} else if (i & HDSPM_TCO1_Video_Input_Format_PAL) {
ltc.input_format = pal;
} else {
ltc.input_format = no_video;
}
s = copy_to_user(argp, &ltc, sizeof(struct hdspm_ltc));
if (0 != s) {
return -EFAULT;
}
break;
case SNDRV_HDSPM_IOCTL_GET_CONFIG:
memset(&info, 0, sizeof(info));
spin_lock_irq(&hdspm->lock);
info.pref_sync_ref = hdspm_pref_sync_ref(hdspm);
info.wordclock_sync_check = hdspm_wc_sync_check(hdspm);
info.system_sample_rate = hdspm->system_sample_rate;
info.autosync_sample_rate =
hdspm_external_sample_rate(hdspm);
info.system_clock_mode = hdspm_system_clock_mode(hdspm);
info.clock_source = hdspm_clock_source(hdspm);
info.autosync_ref = hdspm_autosync_ref(hdspm);
info.line_out = hdspm_toggle_setting(hdspm, HDSPM_LineOut);
info.passthru = 0;
spin_unlock_irq(&hdspm->lock);
if (copy_to_user(argp, &info, sizeof(info)))
return -EFAULT;
break;
case SNDRV_HDSPM_IOCTL_GET_STATUS:
memset(&status, 0, sizeof(status));
status.card_type = hdspm->io_type;
status.autosync_source = hdspm_autosync_ref(hdspm);
status.card_clock = 110069313433624ULL;
status.master_period = hdspm_read(hdspm, HDSPM_RD_PLL_FREQ);
switch (hdspm->io_type) {
case MADI:
case MADIface:
status.card_specific.madi.sync_wc =
hdspm_wc_sync_check(hdspm);
status.card_specific.madi.sync_madi =
hdspm_madi_sync_check(hdspm);
status.card_specific.madi.sync_tco =
hdspm_tco_sync_check(hdspm);
status.card_specific.madi.sync_in =
hdspm_sync_in_sync_check(hdspm);
statusregister =
hdspm_read(hdspm, HDSPM_statusRegister);
status.card_specific.madi.madi_input =
(statusregister & HDSPM_AB_int) ? 1 : 0;
status.card_specific.madi.channel_format =
(statusregister & HDSPM_RX_64ch) ? 1 : 0;
status.card_specific.madi.frame_format = 0;
default:
break;
}
if (copy_to_user(argp, &status, sizeof(status)))
return -EFAULT;
break;
case SNDRV_HDSPM_IOCTL_GET_VERSION:
memset(&hdspm_version, 0, sizeof(hdspm_version));
hdspm_version.card_type = hdspm->io_type;
strlcpy(hdspm_version.cardname, hdspm->card_name,
sizeof(hdspm_version.cardname));
hdspm_version.serial = hdspm->serial;
hdspm_version.firmware_rev = hdspm->firmware_rev;
hdspm_version.addons = 0;
if (hdspm->tco)
hdspm_version.addons |= HDSPM_ADDON_TCO;
if (copy_to_user(argp, &hdspm_version,
sizeof(hdspm_version)))
return -EFAULT;
break;
case SNDRV_HDSPM_IOCTL_GET_MIXER:
if (copy_from_user(&mixer, argp, sizeof(mixer)))
return -EFAULT;
if (copy_to_user((void __user *)mixer.mixer, hdspm->mixer,
sizeof(struct hdspm_mixer)))
return -EFAULT;
break;
default:
return -EINVAL;
}
return 0;
}
static int snd_hdspm_create_hwdep(struct snd_card *card,
struct hdspm *hdspm)
{
struct snd_hwdep *hw;
int err;
err = snd_hwdep_new(card, "HDSPM hwdep", 0, &hw);
if (err < 0)
return err;
hdspm->hwdep = hw;
hw->private_data = hdspm;
strcpy(hw->name, "HDSPM hwdep interface");
hw->ops.open = snd_hdspm_hwdep_dummy_op;
hw->ops.ioctl = snd_hdspm_hwdep_ioctl;
hw->ops.ioctl_compat = snd_hdspm_hwdep_ioctl;
hw->ops.release = snd_hdspm_hwdep_dummy_op;
return 0;
}
static int snd_hdspm_preallocate_memory(struct hdspm *hdspm)
{
int err;
struct snd_pcm *pcm;
size_t wanted;
pcm = hdspm->pcm;
wanted = HDSPM_DMA_AREA_BYTES;
err =
snd_pcm_lib_preallocate_pages_for_all(pcm,
SNDRV_DMA_TYPE_DEV_SG,
snd_dma_pci_data(hdspm->pci),
wanted,
wanted);
if (err < 0) {
dev_dbg(hdspm->card->dev,
"Could not preallocate %zd Bytes\n", wanted);
return err;
} else
dev_dbg(hdspm->card->dev,
" Preallocated %zd Bytes\n", wanted);
return 0;
}
static void hdspm_set_sgbuf(struct hdspm *hdspm,
struct snd_pcm_substream *substream,
unsigned int reg, int channels)
{
int i;
for (i = 0; i < (channels * 16); i++)
hdspm_write(hdspm, reg + 4 * i,
snd_pcm_sgbuf_get_addr(substream, 4096 * i));
}
static int snd_hdspm_create_pcm(struct snd_card *card,
struct hdspm *hdspm)
{
struct snd_pcm *pcm;
int err;
err = snd_pcm_new(card, hdspm->card_name, 0, 1, 1, &pcm);
if (err < 0)
return err;
hdspm->pcm = pcm;
pcm->private_data = hdspm;
strcpy(pcm->name, hdspm->card_name);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_PLAYBACK,
&snd_hdspm_playback_ops);
snd_pcm_set_ops(pcm, SNDRV_PCM_STREAM_CAPTURE,
&snd_hdspm_capture_ops);
pcm->info_flags = SNDRV_PCM_INFO_JOINT_DUPLEX;
err = snd_hdspm_preallocate_memory(hdspm);
if (err < 0)
return err;
return 0;
}
static inline void snd_hdspm_initialize_midi_flush(struct hdspm * hdspm)
{
int i;
for (i = 0; i < hdspm->midiPorts; i++)
snd_hdspm_flush_midi_input(hdspm, i);
}
static int snd_hdspm_create_alsa_devices(struct snd_card *card,
struct hdspm *hdspm)
{
int err, i;
dev_dbg(card->dev, "Create card...\n");
err = snd_hdspm_create_pcm(card, hdspm);
if (err < 0)
return err;
i = 0;
while (i < hdspm->midiPorts) {
err = snd_hdspm_create_midi(card, hdspm, i);
if (err < 0) {
return err;
}
i++;
}
err = snd_hdspm_create_controls(card, hdspm);
if (err < 0)
return err;
err = snd_hdspm_create_hwdep(card, hdspm);
if (err < 0)
return err;
dev_dbg(card->dev, "proc init...\n");
snd_hdspm_proc_init(hdspm);
hdspm->system_sample_rate = -1;
hdspm->last_external_sample_rate = -1;
hdspm->last_internal_sample_rate = -1;
hdspm->playback_pid = -1;
hdspm->capture_pid = -1;
hdspm->capture_substream = NULL;
hdspm->playback_substream = NULL;
dev_dbg(card->dev, "Set defaults...\n");
err = snd_hdspm_set_defaults(hdspm);
if (err < 0)
return err;
dev_dbg(card->dev, "Update mixer controls...\n");
hdspm_update_simple_mixer_controls(hdspm);
dev_dbg(card->dev, "Initializeing complete ???\n");
err = snd_card_register(card);
if (err < 0) {
dev_err(card->dev, "error registering card\n");
return err;
}
dev_dbg(card->dev, "... yes now\n");
return 0;
}
static int snd_hdspm_create(struct snd_card *card,
struct hdspm *hdspm)
{
struct pci_dev *pci = hdspm->pci;
int err;
unsigned long io_extent;
hdspm->irq = -1;
hdspm->card = card;
spin_lock_init(&hdspm->lock);
pci_read_config_word(hdspm->pci,
PCI_CLASS_REVISION, &hdspm->firmware_rev);
strcpy(card->mixername, "Xilinx FPGA");
strcpy(card->driver, "HDSPM");
switch (hdspm->firmware_rev) {
case HDSPM_RAYDAT_REV:
hdspm->io_type = RayDAT;
hdspm->card_name = "RME RayDAT";
hdspm->midiPorts = 2;
break;
case HDSPM_AIO_REV:
hdspm->io_type = AIO;
hdspm->card_name = "RME AIO";
hdspm->midiPorts = 1;
break;
case HDSPM_MADIFACE_REV:
hdspm->io_type = MADIface;
hdspm->card_name = "RME MADIface";
hdspm->midiPorts = 1;
break;
default:
if ((hdspm->firmware_rev == 0xf0) ||
((hdspm->firmware_rev >= 0xe6) &&
(hdspm->firmware_rev <= 0xea))) {
hdspm->io_type = AES32;
hdspm->card_name = "RME AES32";
hdspm->midiPorts = 2;
} else if ((hdspm->firmware_rev == 0xd2) ||
((hdspm->firmware_rev >= 0xc8) &&
(hdspm->firmware_rev <= 0xcf))) {
hdspm->io_type = MADI;
hdspm->card_name = "RME MADI";
hdspm->midiPorts = 3;
} else {
dev_err(card->dev,
"unknown firmware revision %x\n",
hdspm->firmware_rev);
return -ENODEV;
}
}
err = pci_enable_device(pci);
if (err < 0)
return err;
pci_set_master(hdspm->pci);
err = pci_request_regions(pci, "hdspm");
if (err < 0)
return err;
hdspm->port = pci_resource_start(pci, 0);
io_extent = pci_resource_len(pci, 0);
dev_dbg(card->dev, "grabbed memory region 0x%lx-0x%lx\n",
hdspm->port, hdspm->port + io_extent - 1);
hdspm->iobase = ioremap_nocache(hdspm->port, io_extent);
if (!hdspm->iobase) {
dev_err(card->dev, "unable to remap region 0x%lx-0x%lx\n",
hdspm->port, hdspm->port + io_extent - 1);
return -EBUSY;
}
dev_dbg(card->dev, "remapped region (0x%lx) 0x%lx-0x%lx\n",
(unsigned long)hdspm->iobase, hdspm->port,
hdspm->port + io_extent - 1);
if (request_irq(pci->irq, snd_hdspm_interrupt,
IRQF_SHARED, KBUILD_MODNAME, hdspm)) {
dev_err(card->dev, "unable to use IRQ %d\n", pci->irq);
return -EBUSY;
}
dev_dbg(card->dev, "use IRQ %d\n", pci->irq);
hdspm->irq = pci->irq;
dev_dbg(card->dev, "kmalloc Mixer memory of %zd Bytes\n",
sizeof(struct hdspm_mixer));
hdspm->mixer = kzalloc(sizeof(struct hdspm_mixer), GFP_KERNEL);
if (!hdspm->mixer) {
dev_err(card->dev,
"unable to kmalloc Mixer memory of %d Bytes\n",
(int)sizeof(struct hdspm_mixer));
return -ENOMEM;
}
hdspm->port_names_in = NULL;
hdspm->port_names_out = NULL;
switch (hdspm->io_type) {
case AES32:
hdspm->ss_in_channels = hdspm->ss_out_channels = AES32_CHANNELS;
hdspm->ds_in_channels = hdspm->ds_out_channels = AES32_CHANNELS;
hdspm->qs_in_channels = hdspm->qs_out_channels = AES32_CHANNELS;
hdspm->channel_map_in_ss = hdspm->channel_map_out_ss =
channel_map_aes32;
hdspm->channel_map_in_ds = hdspm->channel_map_out_ds =
channel_map_aes32;
hdspm->channel_map_in_qs = hdspm->channel_map_out_qs =
channel_map_aes32;
hdspm->port_names_in_ss = hdspm->port_names_out_ss =
texts_ports_aes32;
hdspm->port_names_in_ds = hdspm->port_names_out_ds =
texts_ports_aes32;
hdspm->port_names_in_qs = hdspm->port_names_out_qs =
texts_ports_aes32;
hdspm->max_channels_out = hdspm->max_channels_in =
AES32_CHANNELS;
hdspm->port_names_in = hdspm->port_names_out =
texts_ports_aes32;
hdspm->channel_map_in = hdspm->channel_map_out =
channel_map_aes32;
break;
case MADI:
case MADIface:
hdspm->ss_in_channels = hdspm->ss_out_channels =
MADI_SS_CHANNELS;
hdspm->ds_in_channels = hdspm->ds_out_channels =
MADI_DS_CHANNELS;
hdspm->qs_in_channels = hdspm->qs_out_channels =
MADI_QS_CHANNELS;
hdspm->channel_map_in_ss = hdspm->channel_map_out_ss =
channel_map_unity_ss;
hdspm->channel_map_in_ds = hdspm->channel_map_out_ds =
channel_map_unity_ss;
hdspm->channel_map_in_qs = hdspm->channel_map_out_qs =
channel_map_unity_ss;
hdspm->port_names_in_ss = hdspm->port_names_out_ss =
texts_ports_madi;
hdspm->port_names_in_ds = hdspm->port_names_out_ds =
texts_ports_madi;
hdspm->port_names_in_qs = hdspm->port_names_out_qs =
texts_ports_madi;
break;
case AIO:
hdspm->ss_in_channels = AIO_IN_SS_CHANNELS;
hdspm->ds_in_channels = AIO_IN_DS_CHANNELS;
hdspm->qs_in_channels = AIO_IN_QS_CHANNELS;
hdspm->ss_out_channels = AIO_OUT_SS_CHANNELS;
hdspm->ds_out_channels = AIO_OUT_DS_CHANNELS;
hdspm->qs_out_channels = AIO_OUT_QS_CHANNELS;
if (0 == (hdspm_read(hdspm, HDSPM_statusRegister2) & HDSPM_s2_AEBI_D)) {
dev_info(card->dev, "AEB input board found\n");
hdspm->ss_in_channels += 4;
hdspm->ds_in_channels += 4;
hdspm->qs_in_channels += 4;
}
if (0 == (hdspm_read(hdspm, HDSPM_statusRegister2) & HDSPM_s2_AEBO_D)) {
dev_info(card->dev, "AEB output board found\n");
hdspm->ss_out_channels += 4;
hdspm->ds_out_channels += 4;
hdspm->qs_out_channels += 4;
}
hdspm->channel_map_out_ss = channel_map_aio_out_ss;
hdspm->channel_map_out_ds = channel_map_aio_out_ds;
hdspm->channel_map_out_qs = channel_map_aio_out_qs;
hdspm->channel_map_in_ss = channel_map_aio_in_ss;
hdspm->channel_map_in_ds = channel_map_aio_in_ds;
hdspm->channel_map_in_qs = channel_map_aio_in_qs;
hdspm->port_names_in_ss = texts_ports_aio_in_ss;
hdspm->port_names_out_ss = texts_ports_aio_out_ss;
hdspm->port_names_in_ds = texts_ports_aio_in_ds;
hdspm->port_names_out_ds = texts_ports_aio_out_ds;
hdspm->port_names_in_qs = texts_ports_aio_in_qs;
hdspm->port_names_out_qs = texts_ports_aio_out_qs;
break;
case RayDAT:
hdspm->ss_in_channels = hdspm->ss_out_channels =
RAYDAT_SS_CHANNELS;
hdspm->ds_in_channels = hdspm->ds_out_channels =
RAYDAT_DS_CHANNELS;
hdspm->qs_in_channels = hdspm->qs_out_channels =
RAYDAT_QS_CHANNELS;
hdspm->max_channels_in = RAYDAT_SS_CHANNELS;
hdspm->max_channels_out = RAYDAT_SS_CHANNELS;
hdspm->channel_map_in_ss = hdspm->channel_map_out_ss =
channel_map_raydat_ss;
hdspm->channel_map_in_ds = hdspm->channel_map_out_ds =
channel_map_raydat_ds;
hdspm->channel_map_in_qs = hdspm->channel_map_out_qs =
channel_map_raydat_qs;
hdspm->channel_map_in = hdspm->channel_map_out =
channel_map_raydat_ss;
hdspm->port_names_in_ss = hdspm->port_names_out_ss =
texts_ports_raydat_ss;
hdspm->port_names_in_ds = hdspm->port_names_out_ds =
texts_ports_raydat_ds;
hdspm->port_names_in_qs = hdspm->port_names_out_qs =
texts_ports_raydat_qs;
break;
}
switch (hdspm->io_type) {
case AIO:
case RayDAT:
if (hdspm_read(hdspm, HDSPM_statusRegister2) &
HDSPM_s2_tco_detect) {
hdspm->midiPorts++;
hdspm->tco = kzalloc(sizeof(struct hdspm_tco),
GFP_KERNEL);
if (NULL != hdspm->tco) {
hdspm_tco_write(hdspm);
}
dev_info(card->dev, "AIO/RayDAT TCO module found\n");
} else {
hdspm->tco = NULL;
}
break;
case MADI:
case AES32:
if (hdspm_read(hdspm, HDSPM_statusRegister) & HDSPM_tco_detect) {
hdspm->midiPorts++;
hdspm->tco = kzalloc(sizeof(struct hdspm_tco),
GFP_KERNEL);
if (NULL != hdspm->tco) {
hdspm_tco_write(hdspm);
}
dev_info(card->dev, "MADI/AES TCO module found\n");
} else {
hdspm->tco = NULL;
}
break;
default:
hdspm->tco = NULL;
}
switch (hdspm->io_type) {
case AES32:
if (hdspm->tco) {
hdspm->texts_autosync = texts_autosync_aes_tco;
hdspm->texts_autosync_items =
ARRAY_SIZE(texts_autosync_aes_tco);
} else {
hdspm->texts_autosync = texts_autosync_aes;
hdspm->texts_autosync_items =
ARRAY_SIZE(texts_autosync_aes);
}
break;
case MADI:
if (hdspm->tco) {
hdspm->texts_autosync = texts_autosync_madi_tco;
hdspm->texts_autosync_items = 4;
} else {
hdspm->texts_autosync = texts_autosync_madi;
hdspm->texts_autosync_items = 3;
}
break;
case MADIface:
break;
case RayDAT:
if (hdspm->tco) {
hdspm->texts_autosync = texts_autosync_raydat_tco;
hdspm->texts_autosync_items = 9;
} else {
hdspm->texts_autosync = texts_autosync_raydat;
hdspm->texts_autosync_items = 8;
}
break;
case AIO:
if (hdspm->tco) {
hdspm->texts_autosync = texts_autosync_aio_tco;
hdspm->texts_autosync_items = 6;
} else {
hdspm->texts_autosync = texts_autosync_aio;
hdspm->texts_autosync_items = 5;
}
break;
}
tasklet_init(&hdspm->midi_tasklet,
hdspm_midi_tasklet, (unsigned long) hdspm);
if (hdspm->io_type != MADIface) {
hdspm->serial = (hdspm_read(hdspm,
HDSPM_midiStatusIn0)>>8) & 0xFFFFFF;
if (NULL == id[hdspm->dev] && hdspm->serial != 0xFFFFFF) {
sprintf(card->id, "HDSPMx%06x", hdspm->serial);
snd_card_set_id(card, card->id);
}
}
dev_dbg(card->dev, "create alsa devices.\n");
err = snd_hdspm_create_alsa_devices(card, hdspm);
if (err < 0)
return err;
snd_hdspm_initialize_midi_flush(hdspm);
return 0;
}
static int snd_hdspm_free(struct hdspm * hdspm)
{
if (hdspm->port) {
hdspm->control_register &=
~(HDSPM_Start | HDSPM_AudioInterruptEnable |
HDSPM_Midi0InterruptEnable | HDSPM_Midi1InterruptEnable |
HDSPM_Midi2InterruptEnable | HDSPM_Midi3InterruptEnable);
hdspm_write(hdspm, HDSPM_controlRegister,
hdspm->control_register);
}
if (hdspm->irq >= 0)
free_irq(hdspm->irq, (void *) hdspm);
kfree(hdspm->mixer);
if (hdspm->iobase)
iounmap(hdspm->iobase);
if (hdspm->port)
pci_release_regions(hdspm->pci);
pci_disable_device(hdspm->pci);
return 0;
}
static void snd_hdspm_card_free(struct snd_card *card)
{
struct hdspm *hdspm = card->private_data;
if (hdspm)
snd_hdspm_free(hdspm);
}
static int snd_hdspm_probe(struct pci_dev *pci,
const struct pci_device_id *pci_id)
{
static int dev;
struct hdspm *hdspm;
struct snd_card *card;
int err;
if (dev >= SNDRV_CARDS)
return -ENODEV;
if (!enable[dev]) {
dev++;
return -ENOENT;
}
err = snd_card_new(&pci->dev, index[dev], id[dev],
THIS_MODULE, sizeof(struct hdspm), &card);
if (err < 0)
return err;
hdspm = card->private_data;
card->private_free = snd_hdspm_card_free;
hdspm->dev = dev;
hdspm->pci = pci;
err = snd_hdspm_create(card, hdspm);
if (err < 0) {
snd_card_free(card);
return err;
}
if (hdspm->io_type != MADIface) {
sprintf(card->shortname, "%s_%x",
hdspm->card_name,
hdspm->serial);
sprintf(card->longname, "%s S/N 0x%x at 0x%lx, irq %d",
hdspm->card_name,
hdspm->serial,
hdspm->port, hdspm->irq);
} else {
sprintf(card->shortname, "%s", hdspm->card_name);
sprintf(card->longname, "%s at 0x%lx, irq %d",
hdspm->card_name, hdspm->port, hdspm->irq);
}
err = snd_card_register(card);
if (err < 0) {
snd_card_free(card);
return err;
}
pci_set_drvdata(pci, card);
dev++;
return 0;
}
static void snd_hdspm_remove(struct pci_dev *pci)
{
snd_card_free(pci_get_drvdata(pci));
}
