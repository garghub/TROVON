static gboolean
mime_read_file(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
gint64 file_size;
int packet_size;
if ((file_size = wtap_file_size(wth, err)) == -1)
return FALSE;
if (file_size > MAX_FILE_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("mime_file: File has %" G_GINT64_MODIFIER "d-byte packet, bigger than maximum of %u",
file_size, MAX_FILE_SIZE);
return FALSE;
}
packet_size = (int)file_size;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = 0;
phdr->caplen = packet_size;
phdr->len = packet_size;
phdr->ts.secs = 0;
phdr->ts.nsecs = 0;
return wtap_read_packet_bytes(fh, buf, packet_size, err, err_info);
}
static gboolean
mime_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
gint64 offset;
*err = 0;
offset = file_tell(wth->fh);
if (offset != 0)
return FALSE;
*data_offset = offset;
return mime_read_file(wth, wth->fh, &wth->phdr, wth->frame_buffer, err, err_info);
}
static gboolean
mime_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
if (seek_off > 0) {
*err = 0;
return FALSE;
}
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
return mime_read_file(wth, wth->random_fh, phdr, buf, err, err_info);
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
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_MIME;
wth->file_encap = WTAP_ENCAP_MIME;
wth->file_tsprec = WTAP_TSPREC_SEC;
wth->subtype_read = mime_read;
wth->subtype_seek_read = mime_seek_read;
wth->snapshot_length = 0;
return 1;
}
