static void
mime_set_pkthdr(struct wtap_pkthdr *phdr, int packet_size)
{
phdr->presence_flags = 0;
phdr->ts.secs = 0;
phdr->ts.nsecs = 0;
phdr->caplen = packet_size;
phdr->len = packet_size;
}
static gboolean
mime_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
mime_file_private_t *priv = (mime_file_private_t *) wth->priv;
char _buf[WTAP_MAX_PACKET_SIZE];
guint8 *buf;
int packet_size;
if (priv->last_packet) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
*data_offset = file_tell(wth->fh);
packet_size = file_read(_buf, sizeof(_buf), wth->fh);
if (packet_size <= 0) {
mime_set_pkthdr(&wth->phdr, 0);
priv->last_packet = TRUE;
if (packet_size < 0)
wth->phdr.ts.nsecs = 1000000000;
return TRUE;
}
mime_set_pkthdr(&wth->phdr, packet_size);
buffer_assure_space(wth->frame_buffer, packet_size);
buf = buffer_start_ptr(wth->frame_buffer);
memcpy(buf, _buf, packet_size);
return TRUE;
}
static gboolean
mime_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr, Buffer *buf, int length, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
*err_info = NULL;
return FALSE;
}
mime_set_pkthdr(phdr, length);
return wtap_read_packet_bytes(wth->random_fh, buf, length, err,
err_info);
}
int
mime_file_open(wtap *wth, int *err, gchar **err_info)
{
char magic_buf[128];
int bytes_read;
gboolean found_file;
guint i;
guint read_bytes = 0;
for (i = 0; i < N_MAGIC_TYPES; i++)
read_bytes = MAX(read_bytes, magic_files[i].magic_len);
read_bytes = (guint)MIN(read_bytes, sizeof(magic_buf));
bytes_read = file_read(magic_buf, read_bytes, wth->fh);
if (bytes_read < 0) {
*err = file_error(wth->fh, err_info);
return -1;
}
if (bytes_read == 0)
return 0;
found_file = FALSE;
for (i = 0; i < N_MAGIC_TYPES; i++) {
if ((guint) bytes_read >= magic_files[i].magic_len && !memcmp(magic_buf, magic_files[i].magic, MIN(magic_files[i].magic_len, (guint) bytes_read))) {
if (!found_file) {
found_file = TRUE;
} else
return 0;
}
}
if (!found_file)
return 0;
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
wth->file_type = WTAP_FILE_MIME;
wth->file_encap = WTAP_ENCAP_MIME;
wth->tsprecision = WTAP_FILE_TSPREC_SEC;
wth->subtype_read = mime_read;
wth->subtype_seek_read = mime_seek_read;
wth->snapshot_length = 0;
wth->priv = g_malloc0(sizeof(mime_file_private_t));
return 1;
}
