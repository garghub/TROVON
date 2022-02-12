wtap_open_return_val packetlogger_open(wtap *wth, int *err, gchar **err_info)
{
gboolean little_endian = FALSE;
packetlogger_header_t pl_hdr;
guint8 type;
packetlogger_t *packetlogger;
if(!packetlogger_read_header(&pl_hdr, wth->fh, little_endian,
err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (!wtap_read_bytes(wth->fh, &type, 1, err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if ((pl_hdr.len & 0x0000FFFF) == 0 &&
(pl_hdr.len & 0xFFFF0000) != 0) {
pl_hdr.len = ((pl_hdr.len >> 24) & 0xFF) |
(((pl_hdr.len >> 16) & 0xFF) << 8);
little_endian = TRUE;
}
if (!((8 <= pl_hdr.len) && (pl_hdr.len < 65536) &&
(type < 0x04 || type == 0xFB || type == 0xFC || type == 0xFE || type == 0xFF)))
return WTAP_OPEN_NOT_MINE;
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return WTAP_OPEN_ERROR;
packetlogger = (packetlogger_t *)g_malloc(sizeof(packetlogger_t));
packetlogger->little_endian = little_endian;
wth->priv = (void *)packetlogger;
wth->subtype_read = packetlogger_read;
wth->subtype_seek_read = packetlogger_seek_read;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_PACKETLOGGER;
wth->file_encap = WTAP_ENCAP_PACKETLOGGER;
wth->file_tsprec = WTAP_TSPREC_USEC;
return WTAP_OPEN_MINE;
}
static gboolean
packetlogger_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
return packetlogger_read_packet(wth, wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info);
}
static gboolean
packetlogger_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
if(file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if(!packetlogger_read_packet(wth, wth->random_fh, phdr, buf, err, err_info)) {
if(*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
packetlogger_read_header(packetlogger_header_t *pl_hdr, FILE_T fh,
gboolean little_endian, int *err, gchar **err_info)
{
if (!wtap_read_bytes_or_eof(fh, &pl_hdr->len, 4, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &pl_hdr->ts_secs, 4, err, err_info))
return FALSE;
if (!wtap_read_bytes(fh, &pl_hdr->ts_usecs, 4, err, err_info))
return FALSE;
if (little_endian) {
pl_hdr->len = GUINT32_FROM_LE(pl_hdr->len);
pl_hdr->ts_secs = GUINT32_FROM_LE(pl_hdr->ts_secs);
pl_hdr->ts_usecs = GUINT32_FROM_LE(pl_hdr->ts_usecs);
} else {
pl_hdr->len = GUINT32_FROM_BE(pl_hdr->len);
pl_hdr->ts_secs = GUINT32_FROM_BE(pl_hdr->ts_secs);
pl_hdr->ts_usecs = GUINT32_FROM_BE(pl_hdr->ts_usecs);
}
return TRUE;
}
static gboolean
packetlogger_read_packet(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
packetlogger_t *packetlogger = (packetlogger_t *)wth->priv;
packetlogger_header_t pl_hdr;
if(!packetlogger_read_header(&pl_hdr, fh, packetlogger->little_endian,
err, err_info))
return FALSE;
if (pl_hdr.len < 8) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("packetlogger: record length %u is too small", pl_hdr.len);
return FALSE;
}
if (pl_hdr.len - 8 > WTAP_MAX_PACKET_SIZE_STANDARD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("packetlogger: File has %u-byte packet, bigger than maximum of %u",
pl_hdr.len - 8, WTAP_MAX_PACKET_SIZE_STANDARD);
return FALSE;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->len = pl_hdr.len - 8;
phdr->caplen = pl_hdr.len - 8;
phdr->ts.secs = (time_t)pl_hdr.ts_secs;
phdr->ts.nsecs = (int)(pl_hdr.ts_usecs * 1000);
return wtap_read_packet_bytes(fh, buf, phdr->caplen, err, err_info);
}
