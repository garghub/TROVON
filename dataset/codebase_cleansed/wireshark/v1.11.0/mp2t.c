static gboolean
mp2t_read_packet(mp2t_filetype_t *mp2t, FILE_T fh, gint64 offset,
struct wtap_pkthdr *phdr, Buffer *buf, int *err,
gchar **err_info)
{
guint64 tmp;
int bytes_read;
buffer_assure_space(buf, MP2T_SIZE);
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(buffer_start_ptr(buf), MP2T_SIZE, fh);
if (MP2T_SIZE != bytes_read) {
*err = file_error(fh, err_info);
if (bytes_read>0 && *err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
phdr->presence_flags = WTAP_HAS_TS;
tmp = ((guint64)(offset - mp2t->start_offset) * 8);
phdr->ts.secs = (time_t)(tmp / MP2T_QAM256_BITRATE);
phdr->ts.nsecs = (int)((tmp % MP2T_QAM256_BITRATE) * 1000000000 / MP2T_QAM256_BITRATE);
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
if (-1 == file_seek(wth->fh, mp2t->trailer_len, SEEK_CUR, err)) {
return FALSE;
}
}
return TRUE;
}
static gboolean
mp2t_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int length _U_, int *err, gchar **err_info)
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
int
mp2t_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
guint8 buffer[MP2T_SIZE+TRAILER_LEN_MAX];
guint8 trailer_len = 0;
guint sync_steps = 0;
int i;
int first;
mp2t_filetype_t *mp2t;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(buffer, MP2T_SIZE, wth->fh);
if (MP2T_SIZE != bytes_read) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
first = -1;
for (i = 0; i < MP2T_SIZE; i++) {
if (MP2T_SYNC_BYTE == buffer[i]) {
first = i;
break;
}
}
if (-1 == first) {
return 0;
}
if (-1 == file_seek(wth->fh, first, SEEK_SET, err)) {
return -1;
}
do {
bytes_read = file_read(buffer, MP2T_SIZE+trailer_len, wth->fh);
if (bytes_read < 0) {
*err = file_error(wth->fh, err_info);
return -1;
}
if (bytes_read < MP2T_SIZE+trailer_len) {
if(sync_steps<2) return 0;
break;
}
if (buffer[0] == MP2T_SYNC_BYTE) {
sync_steps++;
}
else {
if (trailer_len>0)
return 0;
for (i=0; i<TRAILER_LEN_MAX; i++) {
if (buffer[i] == MP2T_SYNC_BYTE) {
trailer_len = i;
if (-1 == file_seek(wth->fh, first, SEEK_SET, err)) {
return -1;
}
sync_steps = 0;
break;
}
}
if (i==TRAILER_LEN_MAX)
return 0;
}
} while (sync_steps < SYNC_STEPS);
if (-1 == file_seek(wth->fh, first, SEEK_SET, err)) {
return -1;
}
wth->file_type = WTAP_FILE_MPEG_2_TS;
wth->file_encap = WTAP_ENCAP_MPEG_2_TS;
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
wth->subtype_read = mp2t_read;
wth->subtype_seek_read = mp2t_seek_read;
wth->snapshot_length = 0;
mp2t = (mp2t_filetype_t*) g_malloc(sizeof(mp2t_filetype_t));
if (NULL == mp2t) {
return -1;
}
wth->priv = mp2t;
mp2t->start_offset = first;
mp2t->trailer_len = trailer_len;
return 1;
}
