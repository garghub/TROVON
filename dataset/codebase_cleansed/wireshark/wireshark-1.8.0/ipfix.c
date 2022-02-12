static gboolean
ipfix_read_message_header(ipfix_message_header_t *pfx_hdr, FILE_T fh, int *err, gchar **err_info)
{
wtap_file_read_expected_bytes(pfx_hdr, IPFIX_MSG_HDR_SIZE, fh, err, err_info);
pfx_hdr->version = g_ntohs(pfx_hdr->version);
pfx_hdr->message_length = g_ntohs(pfx_hdr->message_length);
pfx_hdr->export_time_secs = g_ntohl(pfx_hdr->export_time_secs);
pfx_hdr->sequence_number = g_ntohl(pfx_hdr->sequence_number);
pfx_hdr->observation_id = g_ntohl(pfx_hdr->observation_id);
if (pfx_hdr->version != IPFIX_VERSION) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("ipfix: wrong version %d", pfx_hdr->version);
return FALSE;
}
if (pfx_hdr->message_length < 16) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("ipfix: message length %u is too short", pfx_hdr->message_length);
return FALSE;
}
if (file_seek(fh, 0 - IPFIX_MSG_HDR_SIZE, SEEK_CUR, err) == -1) {
ipfix_debug0("ipfix_read: couldn't go back in file before header");
return FALSE;
}
return TRUE;
}
int
ipfix_open(wtap *wth, int *err, gchar **err_info)
{
gint i, n, records_for_ipfix_check = RECORDS_FOR_IPFIX_CHECK;
gchar *s;
guint16 checked_len = 0;
ipfix_message_header_t msg_hdr;
ipfix_set_header_t set_hdr;
ipfix_debug0("ipfix_open: opening file");
if ((s = getenv("IPFIX_RECORDS_TO_CHECK")) != NULL) {
if ((n = atoi(s)) > 0 && n < 101) {
records_for_ipfix_check = n;
}
}
for (i = 0; i < records_for_ipfix_check; i++) {
if (!ipfix_read_message_header(&msg_hdr, wth->fh, err, err_info)) {
ipfix_debug3("ipfix_open: couldn't read message header #%d with err code #%d (%s)",
i, *err, *err_info);
if (*err == WTAP_ERR_BAD_FILE) {
*err = 0;
g_free(*err_info);
*err_info = NULL;
return 0;
}
if (*err != 0)
return -1;
if (i < 1) {
return 0;
}
break;
}
if (file_seek(wth->fh, IPFIX_MSG_HDR_SIZE, SEEK_CUR, err) == -1) {
ipfix_debug1("ipfix_open: failed seek to next message in file, %d bytes away",
msg_hdr.message_length);
return 0;
}
checked_len = IPFIX_MSG_HDR_SIZE;
while (checked_len < msg_hdr.message_length) {
wtap_file_read_expected_bytes(&set_hdr, IPFIX_SET_HDR_SIZE, wth->fh, err, err_info);
set_hdr.set_length = g_ntohs(set_hdr.set_length);
if ((set_hdr.set_length < IPFIX_SET_HDR_SIZE) ||
((set_hdr.set_length + checked_len) > msg_hdr.message_length)) {
ipfix_debug1("ipfix_open: found invalid set_length of %d",
set_hdr.set_length);
return 0;
}
if (file_seek(wth->fh, set_hdr.set_length - IPFIX_SET_HDR_SIZE,
SEEK_CUR, err) == -1)
{
ipfix_debug1("ipfix_open: failed seek to next set in file, %d bytes away",
set_hdr.set_length - IPFIX_SET_HDR_SIZE);
return 0;
}
checked_len += set_hdr.set_length;
}
}
wth->file_encap = WTAP_ENCAP_RAW_IPFIX;
wth->snapshot_length = 0;
wth->tsprecision = WTAP_FILE_TSPREC_SEC;
wth->subtype_read = ipfix_read;
wth->subtype_seek_read = ipfix_seek_read;
wth->subtype_close = ipfix_close;
wth->file_type = WTAP_FILE_IPFIX;
if (file_seek (wth->fh, 0, SEEK_SET, err) != 0)
{
return -1;
}
return 1;
}
static gboolean
ipfix_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
ipfix_message_header_t msg_hdr;
*data_offset = file_tell(wth->fh);
ipfix_debug1("ipfix_read: data_offset is initially %" G_GINT64_MODIFIER "d", *data_offset);
if (!ipfix_read_message_header(&msg_hdr, wth->fh, err, err_info)) {
ipfix_debug2("ipfix_read: couldn't read message header with code: %d\n, and error '%s'",
*err, *err_info);
return FALSE;
}
buffer_assure_space(wth->frame_buffer, msg_hdr.message_length);
wtap_file_read_expected_bytes(buffer_start_ptr(wth->frame_buffer),
msg_hdr.message_length, wth->fh, err, err_info);
wth->phdr.presence_flags = 0;
wth->phdr.len = msg_hdr.message_length;
wth->phdr.caplen = msg_hdr.message_length;
wth->phdr.ts.secs = 0;
wth->phdr.ts.nsecs = 0;
ipfix_debug1("ipfix_read: data_offset is finally %" G_GINT64_MODIFIER "d", file_tell(wth->fh));
return TRUE;
}
static gboolean
ipfix_seek_read(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int length _U_,
int *err, gchar **err_info)
{
ipfix_message_header_t msg_hdr;
(void) pseudo_header;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
ipfix_debug2("ipfix_seek_read: couldn't read message header with code: %d\n, and error '%s'",
*err, *err_info);
return FALSE;
}
ipfix_debug1("ipfix_seek_read: reading at offset %" G_GINT64_MODIFIER "u", seek_off);
if (!ipfix_read_message_header(&msg_hdr, wth->random_fh, err, err_info)) {
ipfix_debug0("ipfix_read: couldn't read message header");
return FALSE;
}
if(length != (int)msg_hdr.message_length) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("ipfix: record length %u doesn't match requested length %d",
msg_hdr.message_length, length);
ipfix_debug1("ipfix_seek_read: %s", *err_info);
return FALSE;
}
wtap_file_read_expected_bytes(pd, length, wth->random_fh, err, err_info);
return TRUE;
}
static void
ipfix_close(wtap *wth _U_)
{
ipfix_debug0("ipfix_close: closing file");
}
