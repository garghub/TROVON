int i4btrace_open(wtap *wth, int *err, gchar **err_info)
{
i4b_trace_hdr_t hdr;
gboolean byte_swapped = FALSE;
i4btrace_t *i4btrace;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes(wth->fh, &hdr, sizeof(hdr), err, err_info)) {
if (*err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (!I4B_HDR_IS_OK(hdr)) {
hdr.length = GUINT32_SWAP_LE_BE(hdr.length);
hdr.unit = GUINT32_SWAP_LE_BE(hdr.unit);
hdr.type = GUINT32_SWAP_LE_BE(hdr.type);
hdr.dir = GUINT32_SWAP_LE_BE(hdr.dir);
hdr.trunc = GUINT32_SWAP_LE_BE(hdr.trunc);
if (!I4B_HDR_IS_OK(hdr)) {
return 0;
}
byte_swapped = TRUE;
}
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_I4BTRACE;
i4btrace = (i4btrace_t *)g_malloc(sizeof(i4btrace_t));
wth->priv = (void *)i4btrace;
wth->subtype_read = i4btrace_read;
wth->subtype_seek_read = i4btrace_seek_read;
wth->snapshot_length = 0;
i4btrace->byte_swapped = byte_swapped;
wth->file_encap = WTAP_ENCAP_ISDN;
wth->file_tsprec = WTAP_TSPREC_USEC;
return 1;
}
static gboolean i4btrace_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
return i4b_read_rec(wth, wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info);
}
static gboolean
i4btrace_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!i4b_read_rec(wth, wth->random_fh, phdr, buf, err, err_info)) {
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
return TRUE;
}
static gboolean
i4b_read_rec(wtap *wth, FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
i4btrace_t *i4btrace = (i4btrace_t *)wth->priv;
i4b_trace_hdr_t hdr;
guint32 length;
errno = WTAP_ERR_CANT_READ;
if (!wtap_read_bytes_or_eof(fh, &hdr, sizeof hdr, err, err_info))
return FALSE;
if (i4btrace->byte_swapped) {
hdr.length = GUINT32_SWAP_LE_BE(hdr.length);
hdr.unit = GUINT32_SWAP_LE_BE(hdr.unit);
hdr.type = GUINT32_SWAP_LE_BE(hdr.type);
hdr.dir = GUINT32_SWAP_LE_BE(hdr.dir);
hdr.trunc = GUINT32_SWAP_LE_BE(hdr.trunc);
hdr.count = GUINT32_SWAP_LE_BE(hdr.count);
hdr.ts_sec = GUINT32_SWAP_LE_BE(hdr.ts_sec);
hdr.ts_usec = GUINT32_SWAP_LE_BE(hdr.ts_usec);
}
if (hdr.length < sizeof(hdr)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("i4btrace: record length %u < header length %lu",
hdr.length, (unsigned long)sizeof(hdr));
return FALSE;
}
length = hdr.length - (guint32)sizeof(hdr);
if (length > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("i4btrace: File has %u-byte packet, bigger than maximum of %u",
length, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->len = length;
phdr->caplen = length;
phdr->ts.secs = hdr.ts_sec;
phdr->ts.nsecs = hdr.ts_usec * 1000;
switch (hdr.type) {
case TRC_CH_I:
phdr->pkt_encap = WTAP_ENCAP_NULL;
break;
case TRC_CH_D:
phdr->pkt_encap = WTAP_ENCAP_ISDN;
phdr->pseudo_header.isdn.channel = 0;
break;
case TRC_CH_B1:
phdr->pkt_encap = WTAP_ENCAP_ISDN;
phdr->pseudo_header.isdn.channel = 1;
break;
case TRC_CH_B2:
phdr->pkt_encap = WTAP_ENCAP_ISDN;
phdr->pseudo_header.isdn.channel = 2;
break;
}
phdr->pseudo_header.isdn.uton = (hdr.dir == FROM_TE);
return wtap_read_packet_bytes(fh, buf, length, err, err_info);
}
