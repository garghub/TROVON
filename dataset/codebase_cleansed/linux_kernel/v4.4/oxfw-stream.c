static int set_rate(struct snd_oxfw *oxfw, unsigned int rate)
{
int err;
err = avc_general_set_sig_fmt(oxfw->unit, rate,
AVC_GENERAL_PLUG_DIR_IN, 0);
if (err < 0)
goto end;
if (oxfw->has_output)
err = avc_general_set_sig_fmt(oxfw->unit, rate,
AVC_GENERAL_PLUG_DIR_OUT, 0);
end:
return err;
}
static int set_stream_format(struct snd_oxfw *oxfw, struct amdtp_stream *s,
unsigned int rate, unsigned int pcm_channels)
{
u8 **formats;
struct snd_oxfw_stream_formation formation;
enum avc_general_plug_dir dir;
unsigned int len;
int i, err;
if (s == &oxfw->tx_stream) {
formats = oxfw->tx_stream_formats;
dir = AVC_GENERAL_PLUG_DIR_OUT;
} else {
formats = oxfw->rx_stream_formats;
dir = AVC_GENERAL_PLUG_DIR_IN;
}
for (i = 0; i < SND_OXFW_STREAM_FORMAT_ENTRIES; i++) {
err = snd_oxfw_stream_parse_format(formats[i], &formation);
if (err < 0)
return err;
if ((formation.rate == rate) && (formation.pcm == pcm_channels))
break;
}
if (i == SND_OXFW_STREAM_FORMAT_ENTRIES)
return -EINVAL;
if (oxfw->assumed)
return set_rate(oxfw, rate);
len = 5 + formats[i][4] * 2;
err = avc_stream_set_format(oxfw->unit, dir, 0, formats[i], len);
if (err < 0)
return err;
msleep(100);
return 0;
}
static void stop_stream(struct snd_oxfw *oxfw, struct amdtp_stream *stream)
{
amdtp_stream_pcm_abort(stream);
amdtp_stream_stop(stream);
if (stream == &oxfw->tx_stream)
cmp_connection_break(&oxfw->out_conn);
else
cmp_connection_break(&oxfw->in_conn);
}
static int start_stream(struct snd_oxfw *oxfw, struct amdtp_stream *stream,
unsigned int rate, unsigned int pcm_channels)
{
u8 **formats;
struct cmp_connection *conn;
struct snd_oxfw_stream_formation formation;
unsigned int i, midi_ports;
int err;
if (stream == &oxfw->rx_stream) {
formats = oxfw->rx_stream_formats;
conn = &oxfw->in_conn;
} else {
formats = oxfw->tx_stream_formats;
conn = &oxfw->out_conn;
}
for (i = 0; i < SND_OXFW_STREAM_FORMAT_ENTRIES; i++) {
if (formats[i] == NULL)
break;
err = snd_oxfw_stream_parse_format(formats[i], &formation);
if (err < 0)
goto end;
if (rate != formation.rate)
continue;
if (pcm_channels == 0 || pcm_channels == formation.pcm)
break;
}
if (i == SND_OXFW_STREAM_FORMAT_ENTRIES) {
err = -EINVAL;
goto end;
}
pcm_channels = formation.pcm;
midi_ports = formation.midi * 8;
if (pcm_channels == 0) {
err = -EINVAL;
goto end;
}
err = amdtp_am824_set_parameters(stream, rate, pcm_channels, midi_ports,
false);
if (err < 0)
goto end;
err = cmp_connection_establish(conn,
amdtp_stream_get_max_payload(stream));
if (err < 0)
goto end;
err = amdtp_stream_start(stream,
conn->resources.channel,
conn->speed);
if (err < 0) {
cmp_connection_break(conn);
goto end;
}
if (!amdtp_stream_wait_callback(stream, CALLBACK_TIMEOUT)) {
stop_stream(oxfw, stream);
err = -ETIMEDOUT;
}
end:
return err;
}
static int check_connection_used_by_others(struct snd_oxfw *oxfw,
struct amdtp_stream *stream)
{
struct cmp_connection *conn;
bool used;
int err;
if (stream == &oxfw->tx_stream)
conn = &oxfw->out_conn;
else
conn = &oxfw->in_conn;
err = cmp_connection_check_used(conn, &used);
if ((err >= 0) && used && !amdtp_stream_running(stream)) {
dev_err(&oxfw->unit->device,
"Connection established by others: %cPCR[%d]\n",
(conn->direction == CMP_OUTPUT) ? 'o' : 'i',
conn->pcr_index);
err = -EBUSY;
}
return err;
}
int snd_oxfw_stream_init_simplex(struct snd_oxfw *oxfw,
struct amdtp_stream *stream)
{
struct cmp_connection *conn;
enum cmp_direction c_dir;
enum amdtp_stream_direction s_dir;
int err;
if (stream == &oxfw->tx_stream) {
conn = &oxfw->out_conn;
c_dir = CMP_OUTPUT;
s_dir = AMDTP_IN_STREAM;
} else {
conn = &oxfw->in_conn;
c_dir = CMP_INPUT;
s_dir = AMDTP_OUT_STREAM;
}
err = cmp_connection_init(conn, oxfw->unit, c_dir, 0);
if (err < 0)
goto end;
err = amdtp_am824_init(stream, oxfw->unit, s_dir, CIP_NONBLOCKING);
if (err < 0) {
amdtp_stream_destroy(stream);
cmp_connection_destroy(conn);
goto end;
}
if (stream == &oxfw->tx_stream) {
oxfw->tx_stream.flags |= CIP_SKIP_INIT_DBC_CHECK |
CIP_JUMBO_PAYLOAD;
if (oxfw->wrong_dbs)
oxfw->tx_stream.flags |= CIP_WRONG_DBS;
}
end:
return err;
}
int snd_oxfw_stream_start_simplex(struct snd_oxfw *oxfw,
struct amdtp_stream *stream,
unsigned int rate, unsigned int pcm_channels)
{
struct amdtp_stream *opposite;
struct snd_oxfw_stream_formation formation;
enum avc_general_plug_dir dir;
unsigned int substreams, opposite_substreams;
int err = 0;
if (stream == &oxfw->tx_stream) {
substreams = oxfw->capture_substreams;
opposite = &oxfw->rx_stream;
opposite_substreams = oxfw->playback_substreams;
dir = AVC_GENERAL_PLUG_DIR_OUT;
} else {
substreams = oxfw->playback_substreams;
opposite_substreams = oxfw->capture_substreams;
if (oxfw->has_output)
opposite = &oxfw->rx_stream;
else
opposite = NULL;
dir = AVC_GENERAL_PLUG_DIR_IN;
}
if (substreams == 0)
goto end;
err = check_connection_used_by_others(oxfw, stream);
if (err < 0)
goto end;
if (amdtp_streaming_error(stream))
stop_stream(oxfw, stream);
err = snd_oxfw_stream_get_current_formation(oxfw, dir, &formation);
if (err < 0)
goto end;
if (rate == 0)
rate = formation.rate;
if (pcm_channels == 0)
pcm_channels = formation.pcm;
if ((formation.rate != rate) || (formation.pcm != pcm_channels)) {
if (opposite != NULL) {
err = check_connection_used_by_others(oxfw, opposite);
if (err < 0)
goto end;
stop_stream(oxfw, opposite);
}
stop_stream(oxfw, stream);
err = set_stream_format(oxfw, stream, rate, pcm_channels);
if (err < 0) {
dev_err(&oxfw->unit->device,
"fail to set stream format: %d\n", err);
goto end;
}
if (opposite && !amdtp_stream_running(opposite) &&
(opposite_substreams > 0)) {
err = start_stream(oxfw, opposite, rate, 0);
if (err < 0) {
dev_err(&oxfw->unit->device,
"fail to restart stream: %d\n", err);
goto end;
}
}
}
if (!amdtp_stream_running(stream)) {
err = start_stream(oxfw, stream, rate, pcm_channels);
if (err < 0)
dev_err(&oxfw->unit->device,
"fail to start stream: %d\n", err);
}
end:
return err;
}
void snd_oxfw_stream_stop_simplex(struct snd_oxfw *oxfw,
struct amdtp_stream *stream)
{
if (((stream == &oxfw->tx_stream) && (oxfw->capture_substreams > 0)) ||
((stream == &oxfw->rx_stream) && (oxfw->playback_substreams > 0)))
return;
stop_stream(oxfw, stream);
}
void snd_oxfw_stream_destroy_simplex(struct snd_oxfw *oxfw,
struct amdtp_stream *stream)
{
struct cmp_connection *conn;
if (stream == &oxfw->tx_stream)
conn = &oxfw->out_conn;
else
conn = &oxfw->in_conn;
amdtp_stream_destroy(stream);
cmp_connection_destroy(conn);
}
void snd_oxfw_stream_update_simplex(struct snd_oxfw *oxfw,
struct amdtp_stream *stream)
{
struct cmp_connection *conn;
if (stream == &oxfw->tx_stream)
conn = &oxfw->out_conn;
else
conn = &oxfw->in_conn;
if (cmp_connection_update(conn) < 0)
stop_stream(oxfw, stream);
else
amdtp_stream_update(stream);
}
int snd_oxfw_stream_get_current_formation(struct snd_oxfw *oxfw,
enum avc_general_plug_dir dir,
struct snd_oxfw_stream_formation *formation)
{
u8 *format;
unsigned int len;
int err;
len = AVC_GENERIC_FRAME_MAXIMUM_BYTES;
format = kmalloc(len, GFP_KERNEL);
if (format == NULL)
return -ENOMEM;
err = avc_stream_get_format_single(oxfw->unit, dir, 0, format, &len);
if (err < 0)
goto end;
if (len < 3) {
err = -EIO;
goto end;
}
err = snd_oxfw_stream_parse_format(format, formation);
end:
kfree(format);
return err;
}
int snd_oxfw_stream_parse_format(u8 *format,
struct snd_oxfw_stream_formation *formation)
{
unsigned int i, e, channels, type;
memset(formation, 0, sizeof(struct snd_oxfw_stream_formation));
if ((format[0] != 0x90) || (format[1] != 0x40))
return -ENOSYS;
for (i = 0; i < ARRAY_SIZE(avc_stream_rate_table); i++) {
if (format[2] == avc_stream_rate_table[i])
break;
}
if (i == ARRAY_SIZE(avc_stream_rate_table))
return -ENOSYS;
formation->rate = oxfw_rate_table[i];
for (e = 0; e < format[4]; e++) {
channels = format[5 + e * 2];
type = format[6 + e * 2];
switch (type) {
case 0x00:
case 0x06:
formation->pcm += channels;
break;
case 0x0d:
formation->midi = channels;
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
case 0x0e:
case 0x0f:
case 0x10:
case 0x40:
case 0xff:
default:
return -ENOSYS;
}
}
if (formation->pcm > AM824_MAX_CHANNELS_FOR_PCM ||
formation->midi > AM824_MAX_CHANNELS_FOR_MIDI)
return -ENOSYS;
return 0;
}
static int
assume_stream_formats(struct snd_oxfw *oxfw, enum avc_general_plug_dir dir,
unsigned int pid, u8 *buf, unsigned int *len,
u8 **formats)
{
struct snd_oxfw_stream_formation formation;
unsigned int i, eid;
int err;
err = avc_stream_get_format_single(oxfw->unit, dir, pid, buf, len);
if (err < 0) {
dev_err(&oxfw->unit->device,
"fail to get current stream format for isoc %s plug %d:%d\n",
(dir == AVC_GENERAL_PLUG_DIR_IN) ? "in" : "out",
pid, err);
goto end;
}
eid = 0;
err = snd_oxfw_stream_parse_format(buf, &formation);
if (err < 0)
goto end;
formats[eid] = kmemdup(buf, *len, GFP_KERNEL);
if (formats[eid] == NULL) {
err = -ENOMEM;
goto end;
}
for (i = 0; i < ARRAY_SIZE(oxfw_rate_table); i++) {
if (formation.rate == oxfw_rate_table[i])
continue;
err = avc_general_inquiry_sig_fmt(oxfw->unit,
oxfw_rate_table[i],
dir, pid);
if (err < 0)
continue;
eid++;
formats[eid] = kmemdup(buf, *len, GFP_KERNEL);
if (formats[eid] == NULL) {
err = -ENOMEM;
goto end;
}
formats[eid][2] = avc_stream_rate_table[i];
}
err = 0;
oxfw->assumed = true;
end:
return err;
}
static int fill_stream_formats(struct snd_oxfw *oxfw,
enum avc_general_plug_dir dir,
unsigned short pid)
{
u8 *buf, **formats;
unsigned int len, eid = 0;
struct snd_oxfw_stream_formation dummy;
int err;
buf = kmalloc(AVC_GENERIC_FRAME_MAXIMUM_BYTES, GFP_KERNEL);
if (buf == NULL)
return -ENOMEM;
if (dir == AVC_GENERAL_PLUG_DIR_OUT)
formats = oxfw->tx_stream_formats;
else
formats = oxfw->rx_stream_formats;
len = AVC_GENERIC_FRAME_MAXIMUM_BYTES;
err = avc_stream_get_format_list(oxfw->unit, dir, 0, buf, &len, 0);
if (err == -ENOSYS) {
len = AVC_GENERIC_FRAME_MAXIMUM_BYTES;
err = assume_stream_formats(oxfw, dir, pid, buf, &len,
formats);
goto end;
} else if (err < 0) {
dev_err(&oxfw->unit->device,
"fail to get stream format %d for isoc %s plug %d:%d\n",
eid, (dir == AVC_GENERAL_PLUG_DIR_IN) ? "in" : "out",
pid, err);
goto end;
}
while (eid < SND_OXFW_STREAM_FORMAT_ENTRIES) {
if (len < 3) {
err = -EIO;
break;
}
err = snd_oxfw_stream_parse_format(buf, &dummy);
if (err < 0)
break;
formats[eid] = kmemdup(buf, len, GFP_KERNEL);
if (formats[eid] == NULL) {
err = -ENOMEM;
break;
}
len = AVC_GENERIC_FRAME_MAXIMUM_BYTES;
err = avc_stream_get_format_list(oxfw->unit, dir, 0,
buf, &len, ++eid);
if (err == -EINVAL) {
err = 0;
break;
} else if (err < 0) {
dev_err(&oxfw->unit->device,
"fail to get stream format %d for isoc %s plug %d:%d\n",
eid, (dir == AVC_GENERAL_PLUG_DIR_IN) ? "in" :
"out",
pid, err);
break;
}
}
end:
kfree(buf);
return err;
}
int snd_oxfw_stream_discover(struct snd_oxfw *oxfw)
{
u8 plugs[AVC_PLUG_INFO_BUF_BYTES];
struct snd_oxfw_stream_formation formation;
u8 *format;
unsigned int i;
int err;
err = avc_general_get_plug_info(oxfw->unit, 0x1f, 0x07, 0x00, plugs);
if (err < 0) {
dev_err(&oxfw->unit->device,
"fail to get info for isoc/external in/out plugs: %d\n",
err);
goto end;
} else if ((plugs[0] == 0) && (plugs[1] == 0)) {
err = -ENOSYS;
goto end;
}
if (plugs[1] > 0) {
err = fill_stream_formats(oxfw, AVC_GENERAL_PLUG_DIR_OUT, 0);
if (err < 0)
goto end;
for (i = 0; i < SND_OXFW_STREAM_FORMAT_ENTRIES; i++) {
format = oxfw->tx_stream_formats[i];
if (format == NULL)
continue;
err = snd_oxfw_stream_parse_format(format, &formation);
if (err < 0)
continue;
if (formation.midi > 0)
oxfw->midi_input_ports = 1;
}
oxfw->has_output = true;
}
if (plugs[0] > 0) {
err = fill_stream_formats(oxfw, AVC_GENERAL_PLUG_DIR_IN, 0);
if (err < 0)
goto end;
for (i = 0; i < SND_OXFW_STREAM_FORMAT_ENTRIES; i++) {
format = oxfw->rx_stream_formats[i];
if (format == NULL)
continue;
err = snd_oxfw_stream_parse_format(format, &formation);
if (err < 0)
continue;
if (formation.midi > 0)
oxfw->midi_output_ports = 1;
}
}
end:
return err;
}
void snd_oxfw_stream_lock_changed(struct snd_oxfw *oxfw)
{
oxfw->dev_lock_changed = true;
wake_up(&oxfw->hwdep_wait);
}
int snd_oxfw_stream_lock_try(struct snd_oxfw *oxfw)
{
int err;
spin_lock_irq(&oxfw->lock);
if (oxfw->dev_lock_count < 0) {
err = -EBUSY;
goto end;
}
if (oxfw->dev_lock_count++ == 0)
snd_oxfw_stream_lock_changed(oxfw);
err = 0;
end:
spin_unlock_irq(&oxfw->lock);
return err;
}
void snd_oxfw_stream_lock_release(struct snd_oxfw *oxfw)
{
spin_lock_irq(&oxfw->lock);
if (WARN_ON(oxfw->dev_lock_count <= 0))
goto end;
if (--oxfw->dev_lock_count == 0)
snd_oxfw_stream_lock_changed(oxfw);
end:
spin_unlock_irq(&oxfw->lock);
}
