static gboolean
mp2t_read_packet(mp2t_filetype_t *mp2t, FILE_T fh, gint64 offset,
struct wtap_pkthdr *phdr, Buffer *buf, int *err,
gchar **err_info)
{
guint64 tmp;
ws_buffer_assure_space(buf, MP2T_SIZE);
if (!wtap_read_bytes_or_eof(fh, ws_buffer_start_ptr(buf), MP2T_SIZE, err, err_info))
return FALSE;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
tmp = ((guint64)(offset - mp2t->start_offset) * 8);
phdr->ts.secs = (time_t)(tmp / mp2t->bitrate);
phdr->ts.nsecs = (int)((tmp % mp2t->bitrate) * 1000000000 / mp2t->bitrate);
phdr->caplen = MP2T_SIZE;
phdr->len = MP2T_SIZE;
return TRUE;
}
static gboolean
mp2t_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
mp2t_filetype_t *mp2t;
mp2t = (mp2t_filetype_t*) wth->priv;
*data_offset = file_tell(wth->fh);
if (!mp2t_read_packet(mp2t, wth->fh, *data_offset, &wth->phdr,
wth->frame_buffer, err, err_info)) {
return FALSE;
}
if (mp2t->trailer_len!=0) {
if (!wtap_read_bytes(wth->fh, NULL, mp2t->trailer_len, err, err_info)) {
return FALSE;
}
}
return TRUE;
}
static gboolean
mp2t_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
mp2t_filetype_t *mp2t;
if (-1 == file_seek(wth->random_fh, seek_off, SEEK_SET, err)) {
return FALSE;
}
mp2t = (mp2t_filetype_t*) wth->priv;
if (!mp2t_read_packet(mp2t, wth->random_fh, seek_off, phdr, buf,
err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static guint64
mp2t_read_pcr(guint8 *buffer)
{
guint64 base;
guint64 ext;
base = pntoh40(buffer);
base >>= 7;
ext = pntoh16(&buffer[4]);
ext &= 0x01ff;
return (base * 300 + ext);
}
static gboolean
mp2t_find_next_pcr(wtap *wth, guint8 trailer_len,
int *err, gchar **err_info, guint32 *idx, guint64 *pcr, guint16 *pid)
{
guint8 buffer[MP2T_SIZE+TRAILER_LEN_MAX];
gboolean found;
guint8 afc;
guint timeout = 0;
found = FALSE;
while (FALSE == found && timeout++ < SYNC_STEPS * SYNC_STEPS) {
(*idx)++;
if (!wtap_read_bytes_or_eof(
wth->fh, buffer, MP2T_SIZE+trailer_len, err, err_info)) {
return FALSE;
}
if (MP2T_SYNC_BYTE != buffer[0]) {
continue;
}
afc = 3 & (buffer[3] >> 4);
if (afc < 2) {
continue;
}
if (buffer[4] < 7) {
continue;
}
if (0x10 != (0x10 & buffer[5])) {
continue;
}
*pcr = mp2t_read_pcr(&buffer[6]);
*pid = 0x01ff & pntoh16(&buffer[1]);
found = TRUE;
}
return found;
}
static wtap_open_return_val
mp2t_bits_per_second(wtap *wth, guint32 first, guint8 trailer_len,
guint64 *bitrate, int *err, gchar **err_info)
{
guint32 pn1, pn2;
guint64 pcr1, pcr2;
guint16 pid1, pid2;
guint32 idx;
guint64 pcr_delta, bits_passed;
idx = first;
if (!mp2t_find_next_pcr(wth, trailer_len, err, err_info, &idx, &pcr1, &pid1)) {
if (*err == WTAP_ERR_SHORT_READ)
return WTAP_OPEN_NOT_MINE;
if (*err != 0)
return WTAP_OPEN_ERROR;
*bitrate = MP2T_QAM64_BITRATE;
return WTAP_OPEN_MINE;
}
pn1 = idx;
pn2 = pn1;
while (pn1 == pn2) {
if (!mp2t_find_next_pcr(wth, trailer_len, err, err_info, &idx, &pcr2, &pid2)) {
if (*err == WTAP_ERR_SHORT_READ)
return WTAP_OPEN_NOT_MINE;
if (*err != 0)
return WTAP_OPEN_ERROR;
*bitrate = MP2T_QAM64_BITRATE;
return WTAP_OPEN_MINE;
}
if (pid1 == pid2) {
pn2 = idx;
}
}
if (pcr2 <= pcr1) {
return WTAP_OPEN_NOT_MINE;
}
pcr_delta = pcr2 - pcr1;
bits_passed = (guint64)MP2T_SIZE * (pn2 - pn1) * 8;
*bitrate = ((MP2T_PCR_CLOCK * bits_passed) / pcr_delta);
if (*bitrate == 0) {
return WTAP_OPEN_ERROR;
}
return WTAP_OPEN_MINE;
}
wtap_open_return_val
mp2t_open(wtap *wth, int *err, gchar **err_info)
{
guint8 buffer[MP2T_SIZE+TRAILER_LEN_MAX];
guint8 trailer_len = 0;
guint sync_steps = 0;
guint i;
guint32 first = 0;
mp2t_filetype_t *mp2t;
wtap_open_return_val status;
guint64 bitrate;
if (!wtap_read_bytes(wth->fh, buffer, MP2T_SIZE, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
for (i = 0; i < MP2T_SIZE; i++) {
if (MP2T_SYNC_BYTE == buffer[i]) {
first = i;
goto found;
}
}
return WTAP_OPEN_NOT_MINE;
found:
if (-1 == file_seek(wth->fh, first, SEEK_SET, err)) {
return WTAP_OPEN_ERROR;
}
do {
if (!wtap_read_bytes(wth->fh, buffer, MP2T_SIZE+trailer_len, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
if(sync_steps<2) return WTAP_OPEN_NOT_MINE;
break;
}
if (buffer[0] == MP2T_SYNC_BYTE) {
sync_steps++;
}
else {
if (trailer_len>0)
return WTAP_OPEN_NOT_MINE;
for (i=0; i<TRAILER_LEN_MAX; i++) {
if (buffer[i] == MP2T_SYNC_BYTE) {
trailer_len = i;
if (-1 == file_seek(wth->fh, first, SEEK_SET, err)) {
return WTAP_OPEN_ERROR;
}
sync_steps = 0;
break;
}
}
if (i==TRAILER_LEN_MAX)
return WTAP_OPEN_NOT_MINE;
}
} while (sync_steps < SYNC_STEPS);
if (-1 == file_seek(wth->fh, first, SEEK_SET, err)) {
return WTAP_OPEN_ERROR;
}
status = mp2t_bits_per_second(wth, first, trailer_len,
&bitrate, err, err_info);
if (status != WTAP_OPEN_MINE) {
return status;
}
if (-1 == file_seek(wth->fh, first, SEEK_SET, err)) {
return WTAP_OPEN_ERROR;
}
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_MPEG_2_TS;
wth->file_encap = WTAP_ENCAP_MPEG_2_TS;
wth->file_tsprec = WTAP_TSPREC_NSEC;
wth->subtype_read = mp2t_read;
wth->subtype_seek_read = mp2t_seek_read;
wth->snapshot_length = 0;
mp2t = (mp2t_filetype_t*) g_malloc(sizeof(mp2t_filetype_t));
wth->priv = mp2t;
mp2t->start_offset = first;
mp2t->trailer_len = trailer_len;
mp2t->bitrate = bitrate;
return WTAP_OPEN_MINE;
}
