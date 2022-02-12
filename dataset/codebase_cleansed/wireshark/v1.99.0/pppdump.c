static void
init_state(pppdump_t *state)
{
state->num_bytes = 0;
state->pkt = NULL;
state->spkt.dir = DIRECTION_SENT;
state->spkt.cnt = 0;
state->spkt.esc = FALSE;
state->spkt.id_offset = 0;
state->spkt.sd_offset = 0;
state->spkt.cd_offset = 0;
state->rpkt.dir = DIRECTION_RECV;
state->rpkt.cnt = 0;
state->rpkt.esc = FALSE;
state->rpkt.id_offset = 0;
state->rpkt.sd_offset = 0;
state->rpkt.cd_offset = 0;
state->seek_state = NULL;
state->offset = 0x100000;
}
int
pppdump_open(wtap *wth, int *err, gchar **err_info)
{
guint8 buffer[6];
pppdump_t *state;
if (!wtap_read_bytes(wth->fh, buffer, sizeof(buffer),
err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (buffer[0] == PPPD_RESET_TIME &&
(buffer[5] == PPPD_SENT_DATA ||
buffer[5] == PPPD_RECV_DATA ||
buffer[5] == PPPD_TIME_STEP_LONG ||
buffer[5] == PPPD_TIME_STEP_SHORT ||
buffer[5] == PPPD_RESET_TIME)) {
goto my_file_type;
}
else {
return 0;
}
my_file_type:
if (file_seek(wth->fh, 5, SEEK_SET, err) == -1)
return -1;
state = (pppdump_t *)g_malloc(sizeof(pppdump_t));
wth->priv = (void *)state;
state->timestamp = pntoh32(&buffer[1]);
state->tenths = 0;
init_state(state);
state->offset = 5;
wth->file_encap = WTAP_ENCAP_PPP_WITH_PHDR;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_PPPDUMP;
wth->snapshot_length = PPPD_BUF_SIZE;
wth->subtype_read = pppdump_read;
wth->subtype_seek_read = pppdump_seek_read;
wth->subtype_close = pppdump_close;
wth->file_tsprec = WTAP_TSPREC_DSEC;
state->seek_state = g_new(pppdump_t,1);
if (wth->random_fh != NULL)
state->pids = g_ptr_array_new();
else
state->pids = NULL;
state->pkt_cnt = 0;
return 1;
}
static void
pppdump_set_phdr(struct wtap_pkthdr *phdr, int num_bytes,
direction_enum direction)
{
phdr->rec_type = REC_TYPE_PACKET;
phdr->len = num_bytes;
phdr->caplen = num_bytes;
phdr->pkt_encap = WTAP_ENCAP_PPP_WITH_PHDR;
phdr->pseudo_header.p2p.sent = (direction == DIRECTION_SENT ? TRUE : FALSE);
}
static gboolean
pppdump_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
int num_bytes;
direction_enum direction;
guint8 *buf;
pppdump_t *state;
pkt_id *pid;
state = (pppdump_t *)wth->priv;
if (wth->random_fh != NULL) {
pid = g_new(pkt_id, 1);
if (!pid) {
*err = errno;
return FALSE;
}
pid->offset = 0;
} else
pid = NULL;
ws_buffer_assure_space(wth->frame_buffer, PPPD_BUF_SIZE);
buf = ws_buffer_start_ptr(wth->frame_buffer);
if (!collate(state, wth->fh, err, err_info, buf, &num_bytes, &direction,
pid, 0)) {
if (pid != NULL)
g_free(pid);
return FALSE;
}
if (pid != NULL)
pid->dir = direction;
if (pid != NULL)
g_ptr_array_add(state->pids, pid);
*data_offset = state->pkt_cnt;
state->pkt_cnt++;
pppdump_set_phdr(&wth->phdr, num_bytes, direction);
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.ts.secs = state->timestamp;
wth->phdr.ts.nsecs = state->tenths * 100000000;
return TRUE;
}
static int
process_data(pppdump_t *state, FILE_T fh, pkt_t *pkt, int n, guint8 *pd,
int *err, gchar **err_info, pkt_id *pid)
{
int c;
int num_bytes = n;
int num_written;
for (; num_bytes > 0; --num_bytes) {
c = file_getc(fh);
if (c == EOF) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
state->offset++;
switch (c) {
case 0x7e:
if (pkt->cnt > 0) {
pkt->esc = FALSE;
num_written = pkt->cnt;
pkt->cnt = 0;
if (num_written <= 0) {
return 0;
}
if (num_written > PPPD_BUF_SIZE) {
*err = WTAP_ERR_UNC_OVERFLOW;
return -1;
}
memcpy(pd, pkt->buf, num_written);
if (pid) {
pid->offset = pkt->id_offset;
pid->num_bytes_to_skip =
pkt->sd_offset - pkt->id_offset - 3;
g_assert(pid->num_bytes_to_skip >= 0);
}
num_bytes--;
if (num_bytes > 0) {
pkt->id_offset = pkt->cd_offset;
pkt->sd_offset = state->offset;
} else {
pkt->id_offset = 0;
pkt->sd_offset = 0;
}
state->num_bytes = num_bytes;
state->pkt = pkt;
return num_written;
}
break;
case 0x7d:
if (!pkt->esc) {
pkt->esc = TRUE;
break;
}
default:
if (pkt->esc) {
c ^= 0x20;
pkt->esc = FALSE;
}
if (pkt->cnt >= PPPD_BUF_SIZE) {
*err = WTAP_ERR_UNC_OVERFLOW;
return -1;
}
pkt->buf[pkt->cnt++] = c;
break;
}
}
return 0;
}
static gboolean
collate(pppdump_t* state, FILE_T fh, int *err, gchar **err_info, guint8 *pd,
int *num_bytes, direction_enum *direction, pkt_id *pid,
gint64 num_bytes_to_skip)
{
int id;
pkt_t *pkt = NULL;
int byte0, byte1;
int n, num_written = 0;
gint64 start_offset;
guint32 time_long;
guint8 time_short;
if (state->num_bytes > 0) {
g_assert(num_bytes_to_skip == 0);
pkt = state->pkt;
num_written = process_data(state, fh, pkt, state->num_bytes,
pd, err, err_info, pid);
if (num_written < 0) {
return FALSE;
}
else if (num_written > 0) {
*num_bytes = num_written;
*direction = pkt->dir;
return TRUE;
}
} else {
if (pid)
pid->num_bytes_to_skip = 0;
}
start_offset = state->offset;
while ((id = file_getc(fh)) != EOF) {
state->offset++;
switch (id) {
case PPPD_SENT_DATA:
case PPPD_RECV_DATA:
pkt = id == PPPD_SENT_DATA ? &state->spkt : &state->rpkt;
pkt->cd_offset = state->offset - 1;
byte0 = file_getc(fh);
if (byte0 == EOF)
goto done;
state->offset++;
byte1 = file_getc(fh);
if (byte1 == EOF)
goto done;
state->offset++;
n = (byte0 << 8) | byte1;
if (pkt->id_offset == 0) {
pkt->id_offset = pkt->cd_offset;
pkt->sd_offset = state->offset;
}
if (n == 0)
continue;
g_assert(num_bytes_to_skip < n);
while (num_bytes_to_skip) {
if (file_getc(fh) == EOF)
goto done;
state->offset++;
num_bytes_to_skip--;
n--;
}
num_written = process_data(state, fh, pkt, n,
pd, err, err_info, pid);
if (num_written < 0) {
return FALSE;
}
else if (num_written > 0) {
*num_bytes = num_written;
*direction = pkt->dir;
return TRUE;
}
break;
case PPPD_SEND_DELIM:
case PPPD_RECV_DELIM:
break;
case PPPD_RESET_TIME:
if (!wtap_read_bytes(fh, &time_long, sizeof(guint32), err, err_info))
return FALSE;
state->offset += sizeof(guint32);
state->timestamp = pntoh32(&time_long);
state->tenths = 0;
break;
case PPPD_TIME_STEP_LONG:
if (!wtap_read_bytes(fh, &time_long, sizeof(guint32), err, err_info))
return FALSE;
state->offset += sizeof(guint32);
state->tenths += pntoh32(&time_long);
if (state->tenths >= 10) {
state->timestamp += state->tenths / 10;
state->tenths = state->tenths % 10;
}
break;
case PPPD_TIME_STEP_SHORT:
if (!wtap_read_bytes(fh, &time_short, sizeof(guint8), err, err_info))
return FALSE;
state->offset += sizeof(guint8);
state->tenths += time_short;
if (state->tenths >= 10) {
state->timestamp += state->tenths / 10;
state->tenths = state->tenths % 10;
}
break;
default:
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("pppdump: bad ID byte 0x%02x", id);
return FALSE;
}
}
done:
*err = file_error(fh, err_info);
if (*err == 0) {
if (state->offset != start_offset) {
*err = WTAP_ERR_SHORT_READ;
}
}
return FALSE;
}
static gboolean
pppdump_seek_read(wtap *wth,
gint64 seek_off,
struct wtap_pkthdr *phdr,
Buffer *buf,
int *err,
gchar **err_info)
{
int num_bytes;
guint8 *pd;
direction_enum direction;
pppdump_t *state;
pkt_id *pid;
gint64 num_bytes_to_skip;
state = (pppdump_t *)wth->priv;
pid = (pkt_id *)g_ptr_array_index(state->pids, seek_off);
if (!pid) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("pppdump: PID not found for record");
return FALSE;
}
if (file_seek(wth->random_fh, pid->offset, SEEK_SET, err) == -1)
return FALSE;
init_state(state->seek_state);
state->seek_state->offset = pid->offset;
ws_buffer_assure_space(buf, PPPD_BUF_SIZE);
pd = ws_buffer_start_ptr(buf);
num_bytes_to_skip = pid->num_bytes_to_skip;
do {
if (!collate(state->seek_state, wth->random_fh, err, err_info,
pd, &num_bytes, &direction, NULL, num_bytes_to_skip))
return FALSE;
num_bytes_to_skip = 0;
} while (direction != pid->dir);
pppdump_set_phdr(phdr, num_bytes, pid->dir);
return TRUE;
}
static void
pppdump_close(wtap *wth)
{
pppdump_t *state;
state = (pppdump_t *)wth->priv;
if (state->seek_state) {
g_free(state->seek_state);
}
if (state->pids) {
unsigned int i;
for (i = 0; i < g_ptr_array_len(state->pids); i++) {
g_free(g_ptr_array_index(state->pids, i));
}
g_ptr_array_free(state->pids, TRUE);
}
}
