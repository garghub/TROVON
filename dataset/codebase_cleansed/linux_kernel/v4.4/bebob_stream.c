static unsigned int
get_formation_index(unsigned int rate)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(snd_bebob_rate_table); i++) {
if (snd_bebob_rate_table[i] == rate)
return i;
}
return -EINVAL;
}
int
snd_bebob_stream_get_rate(struct snd_bebob *bebob, unsigned int *curr_rate)
{
unsigned int tx_rate, rx_rate, trials;
int err;
trials = 0;
do {
err = avc_general_get_sig_fmt(bebob->unit, &tx_rate,
AVC_GENERAL_PLUG_DIR_OUT, 0);
} while (err == -EAGAIN && ++trials < 3);
if (err < 0)
goto end;
trials = 0;
do {
err = avc_general_get_sig_fmt(bebob->unit, &rx_rate,
AVC_GENERAL_PLUG_DIR_IN, 0);
} while (err == -EAGAIN && ++trials < 3);
if (err < 0)
goto end;
*curr_rate = rx_rate;
if (rx_rate == tx_rate)
goto end;
err = avc_general_set_sig_fmt(bebob->unit, rx_rate,
AVC_GENERAL_PLUG_DIR_IN, 0);
end:
return err;
}
int
snd_bebob_stream_set_rate(struct snd_bebob *bebob, unsigned int rate)
{
int err;
err = avc_general_set_sig_fmt(bebob->unit, rate,
AVC_GENERAL_PLUG_DIR_OUT, 0);
if (err < 0)
goto end;
err = avc_general_set_sig_fmt(bebob->unit, rate,
AVC_GENERAL_PLUG_DIR_IN, 0);
if (err < 0)
goto end;
msleep(300);
end:
return err;
}
int snd_bebob_stream_get_clock_src(struct snd_bebob *bebob,
enum snd_bebob_clock_type *src)
{
const struct snd_bebob_clock_spec *clk_spec = bebob->spec->clock;
u8 addr[AVC_BRIDGECO_ADDR_BYTES], input[7];
unsigned int id;
enum avc_bridgeco_plug_type type;
int err = 0;
if (clk_spec) {
err = clk_spec->get(bebob, &id);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get clock source: %d\n", err);
goto end;
}
if (id >= clk_spec->num) {
dev_err(&bebob->unit->device,
"clock source %d out of range 0..%d\n",
id, clk_spec->num - 1);
err = -EIO;
goto end;
}
*src = clk_spec->types[id];
goto end;
}
if (bebob->sync_input_plug < 0) {
*src = SND_BEBOB_CLOCK_TYPE_INTERNAL;
goto end;
}
avc_bridgeco_fill_msu_addr(addr, AVC_BRIDGECO_PLUG_DIR_IN,
bebob->sync_input_plug);
err = avc_bridgeco_get_plug_input(bebob->unit, addr, input);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get an input for MSU in plug %d: %d\n",
bebob->sync_input_plug, err);
goto end;
}
if (input[0] == 0xff) {
*src = SND_BEBOB_CLOCK_TYPE_INTERNAL;
goto end;
}
if (input[0] == AVC_BRIDGECO_PLUG_DIR_OUT) {
if (input[1] == AVC_BRIDGECO_PLUG_MODE_SUBUNIT &&
input[2] == 0x0c) {
*src = SND_BEBOB_CLOCK_TYPE_INTERNAL;
goto end;
}
} else if (input[1] == AVC_BRIDGECO_PLUG_MODE_UNIT) {
if (input[2] == AVC_BRIDGECO_PLUG_UNIT_ISOC) {
if (input[3] == 0x00) {
*src = SND_BEBOB_CLOCK_TYPE_SYT;
goto end;
} else {
*src = SND_BEBOB_CLOCK_TYPE_EXTERNAL;
goto end;
}
} else if (input[2] == AVC_BRIDGECO_PLUG_UNIT_EXT) {
avc_bridgeco_fill_unit_addr(addr,
AVC_BRIDGECO_PLUG_DIR_IN,
AVC_BRIDGECO_PLUG_UNIT_EXT,
input[3]);
err = avc_bridgeco_get_plug_type(bebob->unit, addr,
&type);
if (err < 0)
goto end;
if (type == AVC_BRIDGECO_PLUG_TYPE_DIG) {
*src = SND_BEBOB_CLOCK_TYPE_EXTERNAL;
goto end;
} else if (type == AVC_BRIDGECO_PLUG_TYPE_SYNC) {
*src = SND_BEBOB_CLOCK_TYPE_EXTERNAL;
goto end;
} else if (type == AVC_BRIDGECO_PLUG_TYPE_ADDITION) {
*src = SND_BEBOB_CLOCK_TYPE_INTERNAL;
goto end;
}
}
}
err = -EIO;
end:
return err;
}
static unsigned int
map_data_channels(struct snd_bebob *bebob, struct amdtp_stream *s)
{
unsigned int sec, sections, ch, channels;
unsigned int pcm, midi, location;
unsigned int stm_pos, sec_loc, pos;
u8 *buf, addr[AVC_BRIDGECO_ADDR_BYTES], type;
enum avc_bridgeco_plug_dir dir;
int err;
buf = kzalloc(256, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
if (s == &bebob->tx_stream)
dir = AVC_BRIDGECO_PLUG_DIR_OUT;
else
dir = AVC_BRIDGECO_PLUG_DIR_IN;
avc_bridgeco_fill_unit_addr(addr, dir, AVC_BRIDGECO_PLUG_UNIT_ISOC, 0);
err = avc_bridgeco_get_plug_ch_pos(bebob->unit, addr, buf, 256);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get channel position for isoc %s plug 0: %d\n",
(dir == AVC_BRIDGECO_PLUG_DIR_IN) ? "in" : "out",
err);
goto end;
}
pos = 0;
pcm = 0;
midi = 0;
sections = buf[pos++];
for (sec = 0; sec < sections; sec++) {
avc_bridgeco_fill_unit_addr(addr, dir,
AVC_BRIDGECO_PLUG_UNIT_ISOC, 0);
err = avc_bridgeco_get_plug_section_type(bebob->unit, addr,
sec, &type);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get section type for isoc %s plug 0: %d\n",
(dir == AVC_BRIDGECO_PLUG_DIR_IN) ? "in" :
"out",
err);
goto end;
}
if (type == 0xff) {
err = -ENOSYS;
goto end;
}
channels = buf[pos++];
for (ch = 0; ch < channels; ch++) {
stm_pos = buf[pos++] - 1;
sec_loc = buf[pos++] - 1;
if (sec_loc >= channels)
sec_loc = ch;
switch (type) {
case 0x0a:
if ((midi > 0) && (stm_pos != midi)) {
err = -ENOSYS;
goto end;
}
amdtp_am824_set_midi_position(s, stm_pos);
midi = stm_pos;
break;
case 0x01:
case 0x02:
case 0x03:
case 0x04:
case 0x05:
case 0x06:
case 0x07:
case 0x08:
case 0x09:
default:
location = pcm + sec_loc;
if (location >= AM824_MAX_CHANNELS_FOR_PCM) {
err = -ENOSYS;
goto end;
}
amdtp_am824_set_pcm_position(s, location,
stm_pos);
break;
}
}
if (type != 0x0a)
pcm += channels;
else
midi += channels;
}
end:
kfree(buf);
return err;
}
static int
init_both_connections(struct snd_bebob *bebob)
{
int err;
err = cmp_connection_init(&bebob->in_conn,
bebob->unit, CMP_INPUT, 0);
if (err < 0)
goto end;
err = cmp_connection_init(&bebob->out_conn,
bebob->unit, CMP_OUTPUT, 0);
if (err < 0)
cmp_connection_destroy(&bebob->in_conn);
end:
return err;
}
static int
check_connection_used_by_others(struct snd_bebob *bebob, struct amdtp_stream *s)
{
struct cmp_connection *conn;
bool used;
int err;
if (s == &bebob->tx_stream)
conn = &bebob->out_conn;
else
conn = &bebob->in_conn;
err = cmp_connection_check_used(conn, &used);
if ((err >= 0) && used && !amdtp_stream_running(s)) {
dev_err(&bebob->unit->device,
"Connection established by others: %cPCR[%d]\n",
(conn->direction == CMP_OUTPUT) ? 'o' : 'i',
conn->pcr_index);
err = -EBUSY;
}
return err;
}
static int
make_both_connections(struct snd_bebob *bebob, unsigned int rate)
{
int index, pcm_channels, midi_channels, err = 0;
if (bebob->connected)
goto end;
index = get_formation_index(rate);
pcm_channels = bebob->tx_stream_formations[index].pcm;
midi_channels = bebob->tx_stream_formations[index].midi;
err = amdtp_am824_set_parameters(&bebob->tx_stream, rate,
pcm_channels, midi_channels * 8,
false);
if (err < 0)
goto end;
pcm_channels = bebob->rx_stream_formations[index].pcm;
midi_channels = bebob->rx_stream_formations[index].midi;
err = amdtp_am824_set_parameters(&bebob->rx_stream, rate,
pcm_channels, midi_channels * 8,
false);
if (err < 0)
goto end;
err = cmp_connection_establish(&bebob->out_conn,
amdtp_stream_get_max_payload(&bebob->tx_stream));
if (err < 0)
goto end;
err = cmp_connection_establish(&bebob->in_conn,
amdtp_stream_get_max_payload(&bebob->rx_stream));
if (err < 0) {
cmp_connection_break(&bebob->out_conn);
goto end;
}
bebob->connected = true;
end:
return err;
}
static void
break_both_connections(struct snd_bebob *bebob)
{
cmp_connection_break(&bebob->in_conn);
cmp_connection_break(&bebob->out_conn);
bebob->connected = false;
if (bebob->maudio_special_quirk != NULL)
msleep(200);
}
static void
destroy_both_connections(struct snd_bebob *bebob)
{
cmp_connection_destroy(&bebob->in_conn);
cmp_connection_destroy(&bebob->out_conn);
}
static int
get_sync_mode(struct snd_bebob *bebob, enum cip_flags *sync_mode)
{
enum snd_bebob_clock_type src;
int err;
err = snd_bebob_stream_get_clock_src(bebob, &src);
if (err < 0)
return err;
switch (src) {
case SND_BEBOB_CLOCK_TYPE_INTERNAL:
case SND_BEBOB_CLOCK_TYPE_EXTERNAL:
*sync_mode = CIP_SYNC_TO_DEVICE;
break;
default:
case SND_BEBOB_CLOCK_TYPE_SYT:
*sync_mode = 0;
break;
}
return 0;
}
static int
start_stream(struct snd_bebob *bebob, struct amdtp_stream *stream,
unsigned int rate)
{
struct cmp_connection *conn;
int err = 0;
if (stream == &bebob->rx_stream)
conn = &bebob->in_conn;
else
conn = &bebob->out_conn;
if (bebob->maudio_special_quirk == NULL) {
err = map_data_channels(bebob, stream);
if (err < 0)
goto end;
}
err = amdtp_stream_start(stream,
conn->resources.channel,
conn->speed);
end:
return err;
}
int snd_bebob_stream_init_duplex(struct snd_bebob *bebob)
{
int err;
err = init_both_connections(bebob);
if (err < 0)
goto end;
err = amdtp_am824_init(&bebob->tx_stream, bebob->unit,
AMDTP_IN_STREAM, CIP_BLOCKING);
if (err < 0) {
amdtp_stream_destroy(&bebob->tx_stream);
destroy_both_connections(bebob);
goto end;
}
init_completion(&bebob->bus_reset);
bebob->tx_stream.flags |= CIP_SKIP_INIT_DBC_CHECK;
if (bebob->version > 2)
bebob->tx_stream.flags |= CIP_EMPTY_HAS_WRONG_DBC |
CIP_SKIP_DBC_ZERO_CHECK;
if (bebob->maudio_special_quirk)
bebob->tx_stream.flags |= CIP_EMPTY_HAS_WRONG_DBC;
err = amdtp_am824_init(&bebob->rx_stream, bebob->unit,
AMDTP_OUT_STREAM, CIP_BLOCKING);
if (err < 0) {
amdtp_stream_destroy(&bebob->tx_stream);
amdtp_stream_destroy(&bebob->rx_stream);
destroy_both_connections(bebob);
}
end:
return err;
}
int snd_bebob_stream_start_duplex(struct snd_bebob *bebob, unsigned int rate)
{
const struct snd_bebob_rate_spec *rate_spec = bebob->spec->rate;
struct amdtp_stream *master, *slave;
enum cip_flags sync_mode;
unsigned int curr_rate;
bool updated = false;
int err = 0;
if (amdtp_streaming_error(&bebob->tx_stream)) {
if (completion_done(&bebob->bus_reset))
reinit_completion(&bebob->bus_reset);
updated = (wait_for_completion_interruptible_timeout(
&bebob->bus_reset,
msecs_to_jiffies(FW_ISO_RESOURCE_DELAY)) > 0);
}
mutex_lock(&bebob->mutex);
if (atomic_read(&bebob->substreams_counter) == 0)
goto end;
err = get_sync_mode(bebob, &sync_mode);
if (err < 0)
goto end;
if (sync_mode == CIP_SYNC_TO_DEVICE) {
master = &bebob->tx_stream;
slave = &bebob->rx_stream;
} else {
master = &bebob->rx_stream;
slave = &bebob->tx_stream;
}
err = check_connection_used_by_others(bebob, master);
if (err < 0)
goto end;
if (amdtp_streaming_error(master))
amdtp_stream_stop(master);
if (amdtp_streaming_error(slave))
amdtp_stream_stop(slave);
if (!updated &&
!amdtp_stream_running(master) && !amdtp_stream_running(slave))
break_both_connections(bebob);
err = rate_spec->get(bebob, &curr_rate);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get sampling rate: %d\n", err);
goto end;
}
if (rate == 0)
rate = curr_rate;
if (rate != curr_rate) {
amdtp_stream_stop(master);
amdtp_stream_stop(slave);
break_both_connections(bebob);
}
if (!amdtp_stream_running(master)) {
amdtp_stream_set_sync(sync_mode, master, slave);
bebob->master = master;
if (bebob->maudio_special_quirk == NULL) {
err = rate_spec->set(bebob, rate);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to set sampling rate: %d\n",
err);
goto end;
}
}
err = make_both_connections(bebob, rate);
if (err < 0)
goto end;
err = start_stream(bebob, master, rate);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to run AMDTP master stream:%d\n", err);
break_both_connections(bebob);
goto end;
}
if (bebob->maudio_special_quirk != NULL) {
err = rate_spec->set(bebob, rate);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to ensure sampling rate: %d\n",
err);
amdtp_stream_stop(master);
break_both_connections(bebob);
goto end;
}
}
if (!amdtp_stream_wait_callback(master, CALLBACK_TIMEOUT)) {
amdtp_stream_stop(master);
break_both_connections(bebob);
err = -ETIMEDOUT;
goto end;
}
}
if (!amdtp_stream_running(slave)) {
err = start_stream(bebob, slave, rate);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to run AMDTP slave stream:%d\n", err);
amdtp_stream_stop(master);
break_both_connections(bebob);
goto end;
}
if (!amdtp_stream_wait_callback(slave, CALLBACK_TIMEOUT)) {
amdtp_stream_stop(slave);
amdtp_stream_stop(master);
break_both_connections(bebob);
err = -ETIMEDOUT;
}
}
end:
mutex_unlock(&bebob->mutex);
return err;
}
void snd_bebob_stream_stop_duplex(struct snd_bebob *bebob)
{
struct amdtp_stream *master, *slave;
if (bebob->master == &bebob->rx_stream) {
slave = &bebob->tx_stream;
master = &bebob->rx_stream;
} else {
slave = &bebob->rx_stream;
master = &bebob->tx_stream;
}
mutex_lock(&bebob->mutex);
if (atomic_read(&bebob->substreams_counter) == 0) {
amdtp_stream_pcm_abort(master);
amdtp_stream_stop(master);
amdtp_stream_pcm_abort(slave);
amdtp_stream_stop(slave);
break_both_connections(bebob);
}
mutex_unlock(&bebob->mutex);
}
void snd_bebob_stream_update_duplex(struct snd_bebob *bebob)
{
mutex_lock(&bebob->mutex);
if ((cmp_connection_update(&bebob->in_conn) < 0) ||
(cmp_connection_update(&bebob->out_conn) < 0)) {
amdtp_stream_pcm_abort(&bebob->rx_stream);
amdtp_stream_pcm_abort(&bebob->tx_stream);
amdtp_stream_stop(&bebob->rx_stream);
amdtp_stream_stop(&bebob->tx_stream);
break_both_connections(bebob);
} else {
amdtp_stream_update(&bebob->rx_stream);
amdtp_stream_update(&bebob->tx_stream);
}
if (!completion_done(&bebob->bus_reset))
complete_all(&bebob->bus_reset);
mutex_unlock(&bebob->mutex);
}
void snd_bebob_stream_destroy_duplex(struct snd_bebob *bebob)
{
amdtp_stream_destroy(&bebob->rx_stream);
amdtp_stream_destroy(&bebob->tx_stream);
destroy_both_connections(bebob);
}
static int
parse_stream_formation(u8 *buf, unsigned int len,
struct snd_bebob_stream_formation *formation)
{
unsigned int i, e, channels, format;
if ((buf[0] != 0x90) || (buf[1] != 0x40))
return -ENOSYS;
for (i = 0; i < ARRAY_SIZE(bridgeco_freq_table); i++) {
if (buf[2] == bridgeco_freq_table[i])
break;
}
if (i == ARRAY_SIZE(bridgeco_freq_table))
return -ENOSYS;
memset(&formation[i], 0, sizeof(struct snd_bebob_stream_formation));
for (e = 0; e < buf[4]; e++) {
channels = buf[5 + e * 2];
format = buf[6 + e * 2];
switch (format) {
case 0x00:
case 0x06:
formation[i].pcm += channels;
break;
case 0x0d:
formation[i].midi += channels;
break;
case 0x01:
case 0x02:
case 0x03:
case 0x04:
case 0x05:
case 0x07:
case 0x0c:
case 0x08:
case 0x09:
case 0x0a:
case 0x0b:
case 0x40:
case 0xff:
default:
return -ENOSYS;
}
}
if (formation[i].pcm > AM824_MAX_CHANNELS_FOR_PCM ||
formation[i].midi > AM824_MAX_CHANNELS_FOR_MIDI)
return -ENOSYS;
return 0;
}
static int
fill_stream_formations(struct snd_bebob *bebob, enum avc_bridgeco_plug_dir dir,
unsigned short pid)
{
u8 *buf;
struct snd_bebob_stream_formation *formations;
unsigned int len, eid;
u8 addr[AVC_BRIDGECO_ADDR_BYTES];
int err;
buf = kmalloc(FORMAT_MAXIMUM_LENGTH, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
if (dir == AVC_BRIDGECO_PLUG_DIR_IN)
formations = bebob->rx_stream_formations;
else
formations = bebob->tx_stream_formations;
for (eid = 0; eid < SND_BEBOB_STRM_FMT_ENTRIES; eid++) {
len = FORMAT_MAXIMUM_LENGTH;
avc_bridgeco_fill_unit_addr(addr, dir,
AVC_BRIDGECO_PLUG_UNIT_ISOC, pid);
err = avc_bridgeco_get_plug_strm_fmt(bebob->unit, addr, buf,
&len, eid);
if (err == -EINVAL && eid > 0) {
err = 0;
break;
} else if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get stream format %d for isoc %s plug %d:%d\n",
eid,
(dir == AVC_BRIDGECO_PLUG_DIR_IN) ? "in" :
"out",
pid, err);
break;
}
err = parse_stream_formation(buf, len, formations);
if (err < 0)
break;
}
kfree(buf);
return err;
}
static int
seek_msu_sync_input_plug(struct snd_bebob *bebob)
{
u8 plugs[AVC_PLUG_INFO_BUF_BYTES], addr[AVC_BRIDGECO_ADDR_BYTES];
unsigned int i;
enum avc_bridgeco_plug_type type;
int err;
err = avc_general_get_plug_info(bebob->unit, 0x0c, 0x00, 0x00, plugs);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get info for MSU in/out plugs: %d\n",
err);
goto end;
}
bebob->sync_input_plug = -1;
for (i = 0; i < plugs[0]; i++) {
avc_bridgeco_fill_msu_addr(addr, AVC_BRIDGECO_PLUG_DIR_IN, i);
err = avc_bridgeco_get_plug_type(bebob->unit, addr, &type);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get type for MSU in plug %d: %d\n",
i, err);
goto end;
}
if (type == AVC_BRIDGECO_PLUG_TYPE_SYNC) {
bebob->sync_input_plug = i;
break;
}
}
end:
return err;
}
int snd_bebob_stream_discover(struct snd_bebob *bebob)
{
const struct snd_bebob_clock_spec *clk_spec = bebob->spec->clock;
u8 plugs[AVC_PLUG_INFO_BUF_BYTES], addr[AVC_BRIDGECO_ADDR_BYTES];
enum avc_bridgeco_plug_type type;
unsigned int i;
int err;
err = avc_general_get_plug_info(bebob->unit, 0x1f, 0x07, 0x00, plugs);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get info for isoc/external in/out plugs: %d\n",
err);
goto end;
}
if ((plugs[0] == 0) || (plugs[1] == 0)) {
err = -ENOSYS;
goto end;
}
avc_bridgeco_fill_unit_addr(addr, AVC_BRIDGECO_PLUG_DIR_IN,
AVC_BRIDGECO_PLUG_UNIT_ISOC, 0);
err = avc_bridgeco_get_plug_type(bebob->unit, addr, &type);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get type for isoc in plug 0: %d\n", err);
goto end;
} else if (type != AVC_BRIDGECO_PLUG_TYPE_ISOC) {
err = -ENOSYS;
goto end;
}
err = fill_stream_formations(bebob, AVC_BRIDGECO_PLUG_DIR_IN, 0);
if (err < 0)
goto end;
avc_bridgeco_fill_unit_addr(addr, AVC_BRIDGECO_PLUG_DIR_OUT,
AVC_BRIDGECO_PLUG_UNIT_ISOC, 0);
err = avc_bridgeco_get_plug_type(bebob->unit, addr, &type);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get type for isoc out plug 0: %d\n", err);
goto end;
} else if (type != AVC_BRIDGECO_PLUG_TYPE_ISOC) {
err = -ENOSYS;
goto end;
}
err = fill_stream_formations(bebob, AVC_BRIDGECO_PLUG_DIR_OUT, 0);
if (err < 0)
goto end;
bebob->midi_input_ports = 0;
for (i = 0; i < plugs[2]; i++) {
avc_bridgeco_fill_unit_addr(addr, AVC_BRIDGECO_PLUG_DIR_IN,
AVC_BRIDGECO_PLUG_UNIT_EXT, i);
err = avc_bridgeco_get_plug_type(bebob->unit, addr, &type);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get type for external in plug %d: %d\n",
i, err);
goto end;
} else if (type == AVC_BRIDGECO_PLUG_TYPE_MIDI) {
bebob->midi_input_ports++;
}
}
bebob->midi_output_ports = 0;
for (i = 0; i < plugs[3]; i++) {
avc_bridgeco_fill_unit_addr(addr, AVC_BRIDGECO_PLUG_DIR_OUT,
AVC_BRIDGECO_PLUG_UNIT_EXT, i);
err = avc_bridgeco_get_plug_type(bebob->unit, addr, &type);
if (err < 0) {
dev_err(&bebob->unit->device,
"fail to get type for external out plug %d: %d\n",
i, err);
goto end;
} else if (type == AVC_BRIDGECO_PLUG_TYPE_MIDI) {
bebob->midi_output_ports++;
}
}
if (!clk_spec)
err = seek_msu_sync_input_plug(bebob);
end:
return err;
}
void snd_bebob_stream_lock_changed(struct snd_bebob *bebob)
{
bebob->dev_lock_changed = true;
wake_up(&bebob->hwdep_wait);
}
int snd_bebob_stream_lock_try(struct snd_bebob *bebob)
{
int err;
spin_lock_irq(&bebob->lock);
if (bebob->dev_lock_count < 0) {
err = -EBUSY;
goto end;
}
if (bebob->dev_lock_count++ == 0)
snd_bebob_stream_lock_changed(bebob);
err = 0;
end:
spin_unlock_irq(&bebob->lock);
return err;
}
void snd_bebob_stream_lock_release(struct snd_bebob *bebob)
{
spin_lock_irq(&bebob->lock);
if (WARN_ON(bebob->dev_lock_count <= 0))
goto end;
if (--bebob->dev_lock_count == 0)
snd_bebob_stream_lock_changed(bebob);
end:
spin_unlock_irq(&bebob->lock);
}
