static gboolean tnef_read_file(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
gint64 file_size;
int packet_size;
if ((file_size = wtap_file_size(wth, err)) == -1)
return FALSE;
if (file_size > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("tnef: File has %" G_GINT64_MODIFIER "d-byte packet, bigger than maximum of %u",
file_size, WTAP_MAX_PACKET_SIZE);
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
static gboolean tnef_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
gint64 offset;
*err = 0;
offset = file_tell(wth->fh);
if (offset)
return FALSE;
*data_offset = offset;
return tnef_read_file(wth, wth->fh, &wth->phdr, wth->frame_buffer, err, err_info);
}
static gboolean tnef_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
if(seek_off > 0) {
*err = 0;
return FALSE;
}
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
return tnef_read_file(wth, wth->random_fh, phdr, buf, err, err_info);
}
wtap_open_return_val tnef_open(wtap *wth, int *err, gchar **err_info)
{
guint32 magic;
if (!wtap_read_bytes(wth->fh, &magic, sizeof magic, err, err_info))
return (*err != WTAP_ERR_SHORT_READ) ? WTAP_OPEN_ERROR : WTAP_OPEN_NOT_MINE;
if (GUINT32_TO_LE(magic) != TNEF_SIGNATURE)
return WTAP_OPEN_NOT_MINE;
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return WTAP_OPEN_ERROR;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_TNEF;
wth->file_encap = WTAP_ENCAP_TNEF;
wth->snapshot_length = 0;
wth->subtype_read = tnef_read;
wth->subtype_seek_read = tnef_seek_read;
wth->file_tsprec = WTAP_TSPREC_SEC;
return WTAP_OPEN_MINE;
}
