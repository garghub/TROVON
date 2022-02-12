static gboolean info_line(const gchar *line)
{
int i=NETSCREEN_SPACES_ON_INFO_LINE;
while (i-- > 0) {
if (g_ascii_isspace(*line)) {
line++;
continue;
} else {
return FALSE;
}
}
return TRUE;
}
static gint64 netscreen_seek_next_packet(wtap *wth, int *err, gchar **err_info,
char *hdr)
{
gint64 cur_off;
char buf[NETSCREEN_LINE_LENGTH];
while (1) {
cur_off = file_tell(wth->fh);
if (cur_off == -1) {
*err = file_error(wth->fh, err_info);
return -1;
}
if (file_gets(buf, sizeof(buf), wth->fh) == NULL) {
*err = file_error(wth->fh, err_info);
break;
}
if (strstr(buf, NETSCREEN_REC_MAGIC_STR1) ||
strstr(buf, NETSCREEN_REC_MAGIC_STR2)) {
g_strlcpy(hdr, buf, NETSCREEN_LINE_LENGTH);
return cur_off;
}
}
return -1;
}
static gboolean netscreen_check_file_type(wtap *wth, int *err, gchar **err_info)
{
char buf[NETSCREEN_LINE_LENGTH];
guint reclen, line;
buf[NETSCREEN_LINE_LENGTH-1] = '\0';
for (line = 0; line < NETSCREEN_HEADER_LINES_TO_CHECK; line++) {
if (file_gets(buf, NETSCREEN_LINE_LENGTH, wth->fh) == NULL) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
reclen = (guint) strlen(buf);
if (reclen < strlen(NETSCREEN_HDR_MAGIC_STR1) ||
reclen < strlen(NETSCREEN_HDR_MAGIC_STR2)) {
continue;
}
if (strstr(buf, NETSCREEN_HDR_MAGIC_STR1) ||
strstr(buf, NETSCREEN_HDR_MAGIC_STR2)) {
return TRUE;
}
}
*err = 0;
return FALSE;
}
wtap_open_return_val netscreen_open(wtap *wth, int *err, gchar **err_info)
{
if (!netscreen_check_file_type(wth, err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (file_seek(wth->fh, 0L, SEEK_SET, err) == -1)
return WTAP_OPEN_ERROR;
wth->file_encap = WTAP_ENCAP_UNKNOWN;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_NETSCREEN;
wth->snapshot_length = 0;
wth->subtype_read = netscreen_read;
wth->subtype_seek_read = netscreen_seek_read;
wth->file_tsprec = WTAP_TSPREC_DSEC;
return WTAP_OPEN_MINE;
}
static gboolean netscreen_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset;
char line[NETSCREEN_LINE_LENGTH];
offset = netscreen_seek_next_packet(wth, err, err_info, line);
if (offset < 0)
return FALSE;
if (!parse_netscreen_packet(wth->fh, &wth->phdr,
wth->frame_buffer, line, err, err_info))
return FALSE;
if (wth->file_encap == WTAP_ENCAP_UNKNOWN)
wth->file_encap = wth->phdr.pkt_encap;
else {
if (wth->file_encap != wth->phdr.pkt_encap)
wth->file_encap = WTAP_ENCAP_PER_PACKET;
}
*data_offset = offset;
return TRUE;
}
static gboolean
netscreen_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
char line[NETSCREEN_LINE_LENGTH];
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
return FALSE;
}
if (file_gets(line, NETSCREEN_LINE_LENGTH, wth->random_fh) == NULL) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
return parse_netscreen_packet(wth->random_fh, phdr, buf, line,
err, err_info);
}
static gboolean
parse_netscreen_packet(FILE_T fh, struct wtap_pkthdr *phdr, Buffer* buf,
char *line, int *err, gchar **err_info)
{
int pkt_len;
int sec;
int dsec;
char cap_int[NETSCREEN_MAX_INT_NAME_LENGTH];
char direction[2];
char cap_src[13];
char cap_dst[13];
guint8 *pd;
gchar *p;
int n, i = 0;
int offset = 0;
gchar dststr[13];
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
if (sscanf(line, "%9d.%9d: %15[a-z0-9/:.-](%1[io]) len=%9d:%12s->%12s/",
&sec, &dsec, cap_int, direction, &pkt_len, cap_src, cap_dst) < 5) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netscreen: Can't parse packet-header");
return -1;
}
if (pkt_len < 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netscreen: packet header has a negative packet length");
return FALSE;
}
if (pkt_len > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("netscreen: File has %u-byte packet, bigger than maximum of %u",
pkt_len, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
phdr->ts.secs = sec;
phdr->ts.nsecs = dsec * 100000000;
phdr->len = pkt_len;
ws_buffer_assure_space(buf, pkt_len);
pd = ws_buffer_start_ptr(buf);
while(1) {
if (file_gets(line, NETSCREEN_LINE_LENGTH, fh) == NULL) {
break;
}
for (p = &line[0]; g_ascii_isspace(*p); p++)
;
if (*p == '\0') {
break;
}
n = parse_single_hex_dump_line(p, pd, offset);
if (offset == 0 && n < 6) {
if (info_line(line)) {
if (++i <= NETSCREEN_MAX_INFOLINES) {
continue;
}
} else {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netscreen: cannot parse hex-data");
return FALSE;
}
}
if (n == -1) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netscreen: cannot parse hex-data");
return FALSE;
}
offset += n;
if (offset > pkt_len) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netscreen: too much hex-data");
return FALSE;
}
}
if (strncmp(cap_int, "adsl", 4) == 0) {
g_snprintf(dststr, 13, "%02x%02x%02x%02x%02x%02x",
pd[0], pd[1], pd[2], pd[3], pd[4], pd[5]);
if (strncmp(dststr, cap_dst, 12) == 0)
phdr->pkt_encap = WTAP_ENCAP_ETHERNET;
else
phdr->pkt_encap = WTAP_ENCAP_PPP;
}
else if (strncmp(cap_int, "seri", 4) == 0)
phdr->pkt_encap = WTAP_ENCAP_PPP;
else
phdr->pkt_encap = WTAP_ENCAP_ETHERNET;
phdr->caplen = offset;
return TRUE;
}
static int
parse_single_hex_dump_line(char* rec, guint8 *buf, guint byte_offset)
{
int num_items_scanned;
guint8 character;
guint8 byte;
for (num_items_scanned = 0; num_items_scanned < 16; num_items_scanned++) {
character = *rec++;
if (character >= '0' && character <= '9')
byte = character - '0' + 0;
else if (character >= 'A' && character <= 'F')
byte = character - 'A' + 0xA;
else if (character >= 'a' && character <= 'f')
byte = character - 'a' + 0xa;
else if (character == ' ' || character == '\r' || character == '\n' || character == '\0') {
break;
} else
return -1;
byte <<= 4;
character = *rec++ & 0xFF;
if (character >= '0' && character <= '9')
byte += character - '0' + 0;
else if (character >= 'A' && character <= 'F')
byte += character - 'A' + 0xA;
else if (character >= 'a' && character <= 'f')
byte += character - 'a' + 0xa;
else
return -1;
buf[byte_offset + num_items_scanned] = byte;
character = *rec++ & 0xFF;
if (character == '\0' || character == '\r' || character == '\n') {
break;
} else if (character != ' ') {
return -1;
}
}
if (num_items_scanned == 0)
return -1;
return num_items_scanned;
}
