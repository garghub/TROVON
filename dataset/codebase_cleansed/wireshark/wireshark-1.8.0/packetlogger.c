int packetlogger_open(wtap *wth, int *err, gchar **err_info)
{
packetlogger_header_t pl_hdr;
guint8 type;
if(!packetlogger_read_header(&pl_hdr, wth->fh, err, err_info))
return -1;
if (file_read(&type, 1, wth->fh) <= 0)
return -1;
if (!((8 <= pl_hdr.len) && (pl_hdr.len < 65536) &&
(type < 0x04 || type == 0xFB || type == 0xFC || type == 0xFE || type == 0xFF)))
return 0;
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
wth->subtype_read = packetlogger_read;
wth->subtype_seek_read = packetlogger_seek_read;
wth->file_type = WTAP_FILE_PACKETLOGGER;
wth->file_encap = WTAP_ENCAP_PACKETLOGGER;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
return 1;
}
static gboolean
packetlogger_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
packetlogger_header_t pl_hdr;
guint bytes_read;
*data_offset = file_tell(wth->fh);
if(!packetlogger_read_header(&pl_hdr, wth->fh, err, err_info))
return FALSE;
if (pl_hdr.len < 8) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("packetlogger: record length %u is too small", pl_hdr.len);
return FALSE;
}
if (pl_hdr.len - 8 > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("packetlogger: File has %u-byte packet, bigger than maximum of %u",
pl_hdr.len - 8, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
buffer_assure_space(wth->frame_buffer, pl_hdr.len - 8);
bytes_read = file_read(buffer_start_ptr(wth->frame_buffer),
pl_hdr.len - 8,
wth->fh);
if(bytes_read != pl_hdr.len - 8) {
*err = file_error(wth->fh, err_info);
if(*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.len = pl_hdr.len - 8;
wth->phdr.caplen = pl_hdr.len - 8;
wth->phdr.ts.secs = (time_t) (pl_hdr.ts >> 32);
wth->phdr.ts.nsecs = (int)((pl_hdr.ts & 0xFFFFFFFF) * 1000);
return TRUE;
}
static gboolean
packetlogger_seek_read(wtap *wth, gint64 seek_off, union wtap_pseudo_header
*pseudo_header _U_, guint8 *pd, int length, int *err,
gchar **err_info)
{
packetlogger_header_t pl_hdr;
guint bytes_read;
if(file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if(!packetlogger_read_header(&pl_hdr, wth->random_fh, err, err_info)) {
if(*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
if(length != (int)pl_hdr.len - 8) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("packetlogger: record length %u doesn't match requested length %d", pl_hdr.len, length);
return FALSE;
}
bytes_read = file_read(pd, pl_hdr.len - 8, wth->random_fh);
if(bytes_read != (pl_hdr.len - 8)) {
*err = file_error(wth->random_fh, err_info);
if(*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
packetlogger_read_header(packetlogger_header_t *pl_hdr, FILE_T fh, int *err,
gchar **err_info)
{
wtap_file_read_expected_bytes(&pl_hdr->len, 4, fh, err, err_info);
wtap_file_read_expected_bytes(&pl_hdr->ts, 8, fh, err, err_info);
pl_hdr->len = GUINT32_FROM_BE(pl_hdr->len);
pl_hdr->ts = GUINT64_FROM_BE(pl_hdr->ts);
return TRUE;
}
