int daintree_sna_open(wtap *wth, int *err _U_, gchar **err_info _U_)
{
char readLine[DAINTREE_MAX_LINE_SIZE];
guint i;
if (file_gets(readLine, DAINTREE_MAX_LINE_SIZE, wth->fh)==NULL) return 0;
i = 0;
while (i < DAINTREE_MAGIC_TEXT_SIZE) {
if (readLine[i] != daintree_magic_text[i]) return 0;
i++;
}
if (file_gets(readLine, DAINTREE_MAX_LINE_SIZE, wth->fh)==NULL) return 0;
if (readLine[0] != COMMENT_LINE) return 0;
wth->subtype_read = daintree_sna_read;
wth->subtype_seek_read = daintree_sna_seek_read;
wth->file_type = WTAP_FILE_DAINTREE_SNA;
wth->file_encap = WTAP_ENCAP_IEEE802_15_4_NOFCS;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
wth->snapshot_length = 0;
return 1;
}
static gboolean
daintree_sna_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
char readLine[DAINTREE_MAX_LINE_SIZE];
guint64 seconds;
char readData[READDATA_BUF_SIZE];
*data_offset = file_tell(wth->fh);
do {
if (file_gets(readLine, DAINTREE_MAX_LINE_SIZE, wth->fh) == NULL) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
} while (readLine[0] == COMMENT_LINE);
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
if (sscanf(readLine, "%*s %18" G_GINT64_MODIFIER "u.%9d %9u %" READDATA_MAX_FIELD_SIZE "s",
&seconds, &wth->phdr.ts.nsecs, &wth->phdr.len, readData) != 4) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("daintree_sna: invalid read record");
return FALSE;
}
if (wth->phdr.len <= FCS_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("daintree_sna: packet length <= %u bytes, no frame data present",
FCS_LENGTH);
return FALSE;
}
wth->phdr.len -= FCS_LENGTH;
wth->phdr.ts.secs = (time_t) seconds;
wth->phdr.ts.nsecs *= 1000;
if ((wth->phdr.caplen = daintree_sna_hex_char(readData, err)) > FCS_LENGTH) {
wth->phdr.caplen -= FCS_LENGTH;
if (wth->phdr.caplen <= wth->phdr.len) {
buffer_assure_space(wth->frame_buffer, wth->phdr.caplen);
memcpy(buffer_start_ptr(wth->frame_buffer), readData, wth->phdr.caplen);
} else {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("daintree_sna: capture length (%u) > packet length (%u)",
wth->phdr.caplen, wth->phdr.len);
return FALSE;
}
} else {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("daintree_sna: invalid packet data");
return FALSE;
}
return TRUE;
}
static gboolean
daintree_sna_seek_read(wtap *wth, gint64 seek_off, union wtap_pseudo_header
*pseudo_header _U_, guint8 *pd, int len, int *err,
gchar **err_info)
{
char readLine[DAINTREE_MAX_LINE_SIZE];
guint pkt_len;
char readData[READDATA_BUF_SIZE];
if(file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
do {
if (file_gets(readLine, DAINTREE_MAX_LINE_SIZE, wth->random_fh) == NULL) {
*err = file_error(wth->random_fh, err_info);
return FALSE;
}
} while (readLine[0] == COMMENT_LINE);
if (sscanf(readLine, "%*s %*u.%*u %*u %" READDATA_MAX_FIELD_SIZE "s", readData) != 1) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("daintree_sna: corrupted seek record");
return FALSE;
}
if ((pkt_len = daintree_sna_hex_char(readData, err)) <= FCS_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("daintree_sna: corrupted packet data");
return FALSE;
}
pkt_len -= FCS_LENGTH;
if (pkt_len == (guint) len) {
memcpy(pd, readData, pkt_len);
} else {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("daintree-sna: corrupted frame");
return FALSE;
}
return TRUE;
}
static guint
daintree_sna_hex_char(guchar *str, int *err _U_) {
guint bytes;
guint8 *p;
p = str;
bytes = 0;
while(*str) {
if (!isxdigit((guchar)*str)) return 0;
if(isdigit((guchar)*str)) {
*p = (*str - '0') << 4;
} else {
*p = ((tolower(*str) - 'a') + 10) << 4;
}
str++;
if (!isxdigit((guchar)*str)) return 0;
if(isdigit((guchar)*str)) {
*p += *str - '0';
} else {
*p += (tolower(*str) - 'a') + 10;
}
str++;
p++;
bytes++;
}
return bytes;
}
