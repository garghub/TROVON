static int
mpeg_resync(wtap *wth, int *err, gchar **err_info _U_)
{
gint64 offset = file_tell(wth->fh);
int count = 0;
int byte = file_getc(wth->fh);
while (byte != EOF) {
if (byte == 0xff && count > 0) {
byte = file_getc(wth->fh);
if (byte != EOF && (byte & 0xe0) == 0xe0)
break;
} else
byte = file_getc(wth->fh);
count++;
}
if (file_seek(wth->fh, offset, SEEK_SET, err) == -1)
return 0;
return count;
}
static int
mpeg_read_header(wtap *wth, int *err, gchar **err_info, guint32 *n)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(n, sizeof *n, wth->fh);
if (bytes_read != sizeof *n) {
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0)
*err = WTAP_ERR_SHORT_READ;
return -1;
}
*n = g_ntohl(*n);
if (file_seek(wth->fh, -(gint64)(sizeof *n), SEEK_CUR, err) == -1)
return -1;
return bytes_read;
}
static gboolean
mpeg_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
mpeg_t *mpeg = (mpeg_t *)wth->priv;
guint32 n;
int bytes_read = mpeg_read_header(wth, err, err_info, &n);
unsigned int packet_size;
struct wtap_nstime ts = mpeg->now;
if (bytes_read == -1)
return FALSE;
if (PES_VALID(n)) {
gint64 offset = file_tell(wth->fh);
guint8 stream;
if (offset == -1)
return -1;
if (file_seek(wth->fh, 3, SEEK_CUR, err) == -1)
return FALSE;
bytes_read = file_read(&stream, sizeof stream, wth->fh);
if (bytes_read != sizeof stream) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
if (stream == 0xba) {
guint32 pack1;
guint32 pack0;
guint64 pack;
guint8 stuffing;
bytes_read = file_read(&pack1, sizeof pack1, wth->fh);
if (bytes_read != sizeof pack1) {
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
bytes_read = file_read(&pack0, sizeof pack0, wth->fh);
if (bytes_read != sizeof pack0) {
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
pack = (guint64)g_ntohl(pack1) << 32 | g_ntohl(pack0);
switch (pack >> 62) {
case 1:
if (file_seek(wth->fh, 1, SEEK_CUR, err) == -1)
return FALSE;
bytes_read = file_read(&stuffing,
sizeof stuffing, wth->fh);
if (bytes_read != sizeof stuffing) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
stuffing &= 0x07;
packet_size = 14 + stuffing;
{
guint64 bytes = pack >> 16;
guint64 ts_val =
(bytes >> 43 & 0x0007) << 30 |
(bytes >> 27 & 0x7fff) << 15 |
(bytes >> 11 & 0x7fff) << 0;
guint ext = (guint)((bytes >> 1) & 0x1ff);
guint64 cr = 300 * ts_val + ext;
guint rem = (guint)(cr % SCRHZ);
mpeg->now.secs
= mpeg->t0 + (time_t)(cr / SCRHZ);
mpeg->now.nsecs
= (int)(G_GINT64_CONSTANT(1000000000) * rem / SCRHZ);
}
ts = mpeg->now;
break;
default:
packet_size = 12;
}
} else {
guint16 length;
bytes_read = file_read(&length, sizeof length, wth->fh);
if (bytes_read != sizeof length) {
*err = file_error(wth->fh, err_info);
if (*err == 0 && bytes_read != 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
length = g_ntohs(length);
packet_size = 6 + length;
}
if (file_seek(wth->fh, offset, SEEK_SET, err) == -1)
return FALSE;
} else {
struct mpa mpa;
MPA_UNMARSHAL(&mpa, n);
if (MPA_VALID(&mpa)) {
packet_size = MPA_BYTES(&mpa);
mpeg->now.nsecs += MPA_DURATION_NS(&mpa);
if (mpeg->now.nsecs >= 1000000000) {
mpeg->now.secs++;
mpeg->now.nsecs -= 1000000000;
}
} else {
packet_size = mpeg_resync(wth, err, err_info);
if (packet_size == 0)
return FALSE;
}
}
*data_offset = file_tell(wth->fh);
if (!wtap_read_packet_bytes(wth->fh, wth->frame_buffer,
packet_size, err, err_info))
return FALSE;
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.ts = ts;
wth->phdr.caplen = packet_size;
wth->phdr.len = packet_size;
return TRUE;
}
static gboolean
mpeg_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr _U_, Buffer *buf, int length,
int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
return wtap_read_packet_bytes(wth->random_fh, buf, length, err, err_info);
}
int
mpeg_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
char magic_buf[16];
struct _mpeg_magic* m;
mpeg_t *mpeg;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(magic_buf, sizeof magic_buf, wth->fh);
if (bytes_read != (int) sizeof magic_buf) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
for (m=magic; m->match; m++) {
if (memcmp(magic_buf, m->match, m->len) == 0)
goto good_magic;
}
return 0;
good_magic:
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
wth->file_type = WTAP_FILE_MPEG;
wth->file_encap = WTAP_ENCAP_MPEG;
wth->tsprecision = WTAP_FILE_TSPREC_NSEC;
wth->subtype_read = mpeg_read;
wth->subtype_seek_read = mpeg_seek_read;
wth->snapshot_length = 0;
mpeg = (mpeg_t *)g_malloc(sizeof(mpeg_t));
wth->priv = (void *)mpeg;
mpeg->now.secs = 0;
mpeg->now.nsecs = 0;
mpeg->t0 = mpeg->now.secs;
return 1;
}
