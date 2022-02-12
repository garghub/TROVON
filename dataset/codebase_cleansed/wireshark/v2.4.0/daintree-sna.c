wtap_open_return_val daintree_sna_open(wtap *wth, int *err, gchar **err_info)
{
char readLine[DAINTREE_MAX_LINE_SIZE];
if (file_gets(readLine, DAINTREE_MAX_LINE_SIZE, wth->fh)==NULL) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (strncmp(readLine, daintree_magic_text, DAINTREE_MAGIC_TEXT_SIZE) != 0)
return WTAP_OPEN_NOT_MINE;
if (file_gets(readLine, DAINTREE_MAX_LINE_SIZE, wth->fh)==NULL) {
*err = file_error(wth->fh, err_info);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (readLine[0] != COMMENT_LINE)
return WTAP_OPEN_NOT_MINE;
wth->subtype_read = daintree_sna_read;
wth->subtype_seek_read = daintree_sna_seek_read;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_DAINTREE_SNA;
wth->file_encap = WTAP_ENCAP_IEEE802_15_4_NOFCS;
wth->file_tsprec = WTAP_TSPREC_USEC;
wth->snapshot_length = 0;
return WTAP_OPEN_MINE;
}
static gboolean
daintree_sna_read(wtap *wth, int *err, gchar **err_info, gint64 *data_offset)
{
*data_offset = file_tell(wth->fh);
return daintree_sna_read_packet(wth->fh, &wth->phdr,
wth->frame_buffer, err, err_info);
}
static gboolean
daintree_sna_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
if(file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
return daintree_sna_read_packet(wth->random_fh, phdr, buf, err,
err_info);
}
static gboolean
daintree_sna_read_packet(FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
guint64 seconds;
int useconds;
char readLine[DAINTREE_MAX_LINE_SIZE];
char readData[READDATA_BUF_SIZE];
guchar *str = (guchar *)readData;
guint bytes;
guint8 *p;
do {
if (file_gets(readLine, DAINTREE_MAX_LINE_SIZE, fh) == NULL) {
*err = file_error(fh, err_info);
return FALSE;
}
} while (readLine[0] == COMMENT_LINE);
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
if (sscanf(readLine, "%*s %18" G_GINT64_MODIFIER "u.%9d %9u %" READDATA_MAX_FIELD_SIZE "s",
&seconds, &useconds, &phdr->len, readData) != 4) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("daintree_sna: invalid read record");
return FALSE;
}
if (phdr->len <= FCS_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("daintree_sna: packet length <= %u bytes, no frame data present",
FCS_LENGTH);
return FALSE;
}
phdr->len -= FCS_LENGTH;
phdr->ts.secs = (time_t) seconds;
phdr->ts.nsecs = useconds * 1000;
p = str;
bytes = 0;
while(*str) {
if (!g_ascii_isxdigit(*str)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("daintree_sna: non-hex digit in hex data");
return FALSE;
}
if(g_ascii_isdigit(*str)) {
*p = (*str - '0') << 4;
} else {
*p = ((g_ascii_tolower(*str) - 'a') + 10) << 4;
}
str++;
if (!g_ascii_isxdigit(*str)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("daintree_sna: non-hex digit in hex data");
return FALSE;
}
if(g_ascii_isdigit(*str)) {
*p += *str - '0';
} else {
*p += (g_ascii_tolower(*str) - 'a') + 10;
}
str++;
p++;
bytes++;
}
if (bytes <= FCS_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("daintree_sna: Only %u bytes of packet data",
bytes);
return FALSE;
}
bytes -= FCS_LENGTH;
if (bytes > phdr->len) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("daintree_sna: capture length (%u) > packet length (%u)",
bytes, phdr->len);
return FALSE;
}
phdr->caplen = bytes;
ws_buffer_assure_space(buf, bytes);
memcpy(ws_buffer_start_ptr(buf), readData, bytes);
return TRUE;
}
