static gboolean tnef_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
gint64 offset;
guint8 *buf;
gint64 file_size;
int packet_size;
*err = 0;
offset = file_tell(wth->fh);
if (offset)
return FALSE;
*data_offset = offset;
if ((file_size = wtap_file_size(wth, err)) == -1)
return FALSE;
if (file_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("tnef: File has %" G_GINT64_MODIFIER "d-byte packet, bigger than maximum of %u",
file_size, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
packet_size = (int)file_size;
buffer_assure_space(wth->frame_buffer, packet_size);
buf = buffer_start_ptr(wth->frame_buffer);
wtap_file_read_expected_bytes(buf, packet_size, wth->fh, err, err_info);
wth->phdr.presence_flags = 0;
wth->phdr.caplen = packet_size;
wth->phdr.len = packet_size;
wth->phdr.ts.secs = 0;
wth->phdr.ts.nsecs = 0;
return TRUE;
}
static gboolean tnef_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr _U_,
guint8 *pd, int length, int *err, gchar **err_info)
{
int packet_size = length;
if(seek_off > 0) {
*err = 0;
return FALSE;
}
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
wtap_file_read_expected_bytes(pd, packet_size, wth->random_fh, err, err_info);
return TRUE;
}
int tnef_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
guint32 magic;
bytes_read = file_read(&magic, sizeof magic, wth->fh);
if (bytes_read != sizeof magic) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (htolel(magic) != TNEF_SIGNATURE)
return 0;
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
wth->file_type = WTAP_FILE_TNEF;
wth->file_encap = WTAP_ENCAP_TNEF;
wth->snapshot_length = 0;
wth->subtype_read = tnef_read;
wth->subtype_seek_read = tnef_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_SEC;
return 1;
}
