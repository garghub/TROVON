int i4btrace_open(wtap *wth, int *err, gchar **err_info)
{
int bytes_read;
i4b_trace_hdr_t hdr;
gboolean byte_swapped = FALSE;
i4btrace_t *i4btrace;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(&hdr, sizeof(hdr), wth->fh);
if (bytes_read != sizeof(hdr)) {
*err = file_error(wth->fh, err_info);
if (*err != 0)
return -1;
return 0;
}
if (!I4B_HDR_IS_OK(hdr)) {
hdr.length = BSWAP32(hdr.length);
hdr.unit = BSWAP32(hdr.unit);
hdr.type = BSWAP32(hdr.type);
hdr.dir = BSWAP32(hdr.dir);
hdr.trunc = BSWAP32(hdr.trunc);
if (!I4B_HDR_IS_OK(hdr)) {
return 0;
}
byte_swapped = TRUE;
}
if (file_seek(wth->fh, 0, SEEK_SET, err) == -1)
return -1;
wth->file_type = WTAP_FILE_I4BTRACE;
i4btrace = (i4btrace_t *)g_malloc(sizeof(i4btrace_t));
wth->priv = (void *)i4btrace;
wth->subtype_read = i4btrace_read;
wth->subtype_seek_read = i4btrace_seek_read;
wth->snapshot_length = 0;
i4btrace->byte_swapped = byte_swapped;
wth->file_encap = WTAP_ENCAP_ISDN;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
return 1;
}
static gboolean i4btrace_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
int ret;
i4b_trace_hdr_t hdr;
guint32 length;
void *bufp;
*data_offset = file_tell(wth->fh);
ret = i4b_read_rec_header(wth->fh, &hdr, err, err_info);
if (ret <= 0) {
return FALSE;
}
i4b_byte_swap_header(wth, &hdr);
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
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.len = length;
wth->phdr.caplen = length;
wth->phdr.ts.secs = hdr.ts_sec;
wth->phdr.ts.nsecs = hdr.ts_usec * 1000;
buffer_assure_space(wth->frame_buffer, length);
bufp = buffer_start_ptr(wth->frame_buffer);
if (!i4b_read_rec_data(wth->fh, bufp, length, err, err_info))
return FALSE;
switch (hdr.type) {
case TRC_CH_I:
wth->phdr.pkt_encap = WTAP_ENCAP_NULL;
break;
case TRC_CH_D:
case TRC_CH_B1:
case TRC_CH_B2:
wth->phdr.pkt_encap = WTAP_ENCAP_ISDN;
break;
}
i4b_set_pseudo_header(&hdr, &wth->pseudo_header);
return TRUE;
}
static gboolean
i4btrace_seek_read(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int length,
int *err, gchar **err_info)
{
int ret;
i4b_trace_hdr_t hdr;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
ret = i4b_read_rec_header(wth->random_fh, &hdr, err, err_info);
if (ret <= 0) {
if (ret == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
i4b_byte_swap_header(wth, &hdr);
i4b_set_pseudo_header(&hdr, pseudo_header);
return i4b_read_rec_data(wth->random_fh, pd, length, err, err_info);
}
static int
i4b_read_rec_header(FILE_T fh, i4b_trace_hdr_t *hdr, int *err, gchar **err_info)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(hdr, sizeof *hdr, fh);
if (bytes_read != sizeof *hdr) {
*err = file_error(fh, err_info);
if (*err != 0)
return -1;
if (bytes_read != 0) {
*err = WTAP_ERR_SHORT_READ;
return -1;
}
return 0;
}
return 1;
}
static void
i4b_byte_swap_header(wtap *wth, i4b_trace_hdr_t *hdr)
{
i4btrace_t *i4btrace = (i4btrace_t *)wth->priv;
if (i4btrace->byte_swapped) {
hdr->length = BSWAP32(hdr->length);
hdr->unit = BSWAP32(hdr->unit);
hdr->type = BSWAP32(hdr->type);
hdr->dir = BSWAP32(hdr->dir);
hdr->trunc = BSWAP32(hdr->trunc);
hdr->count = BSWAP32(hdr->count);
hdr->ts_sec = BSWAP32(hdr->ts_sec);
hdr->ts_usec = BSWAP32(hdr->ts_usec);
}
}
static gboolean
i4b_read_rec_data(FILE_T fh, guint8 *pd, int length, int *err, gchar **err_info)
{
int bytes_read;
errno = WTAP_ERR_CANT_READ;
bytes_read = file_read(pd, length, fh);
if (bytes_read != length) {
*err = file_error(fh, err_info);
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static void
i4b_set_pseudo_header(i4b_trace_hdr_t *hdr,
union wtap_pseudo_header *pseudo_header)
{
pseudo_header->isdn.uton = (hdr->dir == FROM_TE);
switch (hdr->type) {
case TRC_CH_D:
pseudo_header->isdn.channel = 0;
break;
case TRC_CH_B1:
pseudo_header->isdn.channel = 1;
break;
case TRC_CH_B2:
pseudo_header->isdn.channel = 2;
break;
}
}
