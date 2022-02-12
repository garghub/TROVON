static long vms_seek_next_packet(wtap *wth, int *err, gchar **err_info)
{
long cur_off;
char buf[VMS_LINE_LENGTH];
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
if (strstr(buf, VMS_REC_MAGIC_STR1) ||
strstr(buf, VMS_REC_MAGIC_STR2) ||
strstr(buf, VMS_REC_MAGIC_STR2)) {
g_strlcpy(hdr, buf,VMS_LINE_LENGTH);
return cur_off;
}
}
return -1;
}
static gboolean vms_check_file_type(wtap *wth, int *err, gchar **err_info)
{
char buf[VMS_LINE_LENGTH];
guint reclen, line;
gint64 mpos;
buf[VMS_LINE_LENGTH-1] = '\0';
for (line = 0; line < VMS_HEADER_LINES_TO_CHECK; line++) {
mpos = file_tell(wth->fh);
if (mpos == -1) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
if (file_gets(buf, VMS_LINE_LENGTH, wth->fh) == NULL) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
reclen = (guint) strlen(buf);
if (reclen < strlen(VMS_HDR_MAGIC_STR1) ||
reclen < strlen(VMS_HDR_MAGIC_STR2) ||
reclen < strlen(VMS_HDR_MAGIC_STR3)) {
continue;
}
if (strstr(buf, VMS_HDR_MAGIC_STR1) ||
strstr(buf, VMS_HDR_MAGIC_STR2) ||
strstr(buf, VMS_HDR_MAGIC_STR3)) {
if (file_seek(wth->fh, mpos, SEEK_SET, err) == -1) {
return FALSE;
}
return TRUE;
}
}
*err = 0;
return FALSE;
}
wtap_open_return_val vms_open(wtap *wth, int *err, gchar **err_info)
{
if (!vms_check_file_type(wth, err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
wth->file_encap = WTAP_ENCAP_RAW_IP;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_VMS;
wth->snapshot_length = 0;
wth->subtype_read = vms_read;
wth->subtype_seek_read = vms_seek_read;
wth->file_tsprec = WTAP_TSPREC_CSEC;
return WTAP_OPEN_MINE;
}
static gboolean vms_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset = 0;
#ifdef TCPIPTRACE_FRAGMENTS_HAVE_HEADER_LINE
offset = vms_seek_next_packet(wth, err, err_info);
#else
offset = file_tell(wth->fh);
#endif
if (offset < 1) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
*data_offset = offset;
return parse_vms_packet(wth->fh, &wth->phdr, wth->frame_buffer, err, err_info);
}
static gboolean
vms_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off - 1, SEEK_SET, err) == -1)
return FALSE;
if (!parse_vms_packet(wth->random_fh, phdr, buf, err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static int
isdumpline( gchar *line )
{
int i, j;
while (*line && !g_ascii_isalnum(*line))
line++;
for (j=0; j<4; j++) {
for (i=0; i<8; i++, line++)
if (! g_ascii_isxdigit(*line))
return FALSE;
for (i=0; i<3; i++, line++)
if (*line != ' ')
return FALSE;
}
return g_ascii_isspace(*line);
}
static gboolean
parse_vms_packet(FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf, int *err, gchar **err_info)
{
char line[VMS_LINE_LENGTH + 1];
int num_items_scanned;
guint32 pkt_len = 0;
int pktnum;
int csec = 101;
struct tm tm;
char mon[4] = {'J', 'A', 'N', 0};
gchar *p;
const gchar *endp;
static const gchar months[] = "JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";
guint32 i;
int offset = 0;
guint8 *pd;
tm.tm_year = 1970;
tm.tm_mon = 0;
tm.tm_mday = 1;
tm.tm_hour = 1;
tm.tm_min = 1;
tm.tm_sec = 1;
do {
if (file_gets(line, VMS_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if ((*err == 0) && (csec != 101)) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
line[VMS_LINE_LENGTH] = '\0';
if ((csec == 101) && (p = strstr(line, "packet ")) != NULL
&& (! strstr(line, "could not save "))) {
num_items_scanned = sscanf(p,
"packet %9d at %2d-%3s-%4d %2d:%2d:%2d.%9d",
&pktnum, &tm.tm_mday, mon,
&tm.tm_year, &tm.tm_hour,
&tm.tm_min, &tm.tm_sec, &csec);
if (num_items_scanned != 8) {
num_items_scanned = sscanf(p,
"packet seq # = %9d at %2d-%3s-%4d %2d:%2d:%2d.%9d",
&pktnum, &tm.tm_mday, mon,
&tm.tm_year, &tm.tm_hour,
&tm.tm_min, &tm.tm_sec, &csec);
}
if (num_items_scanned != 8) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("vms: header line not valid");
return FALSE;
}
}
if ( (! pkt_len) && (p = strstr(line, "Length"))) {
p += sizeof("Length ");
while (*p && ! g_ascii_isdigit(*p))
p++;
if ( !*p ) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("vms: Length field not valid");
return FALSE;
}
if (!ws_strtou32(p, &endp, &pkt_len) || (*endp != '\0' && !g_ascii_isspace(*endp))) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("vms: Length field '%s' not valid", p);
return FALSE;
}
break;
}
} while (! isdumpline(line));
if (pkt_len > WTAP_MAX_PACKET_SIZE_STANDARD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("vms: File has %u-byte packet, bigger than maximum of %u",
pkt_len, WTAP_MAX_PACKET_SIZE_STANDARD);
return FALSE;
}
p = strstr(months, mon);
if (p)
tm.tm_mon = (int) (p - months) / 3;
tm.tm_year -= 1900;
tm.tm_isdst = -1;
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS;
phdr->ts.secs = mktime(&tm);
phdr->ts.nsecs = csec * 10000000;
phdr->caplen = pkt_len;
phdr->len = pkt_len;
ws_buffer_assure_space(buf, pkt_len);
pd = ws_buffer_start_ptr(buf);
for (i = 0; i < pkt_len; i += 16) {
if (file_gets(line, VMS_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
line[VMS_LINE_LENGTH] = '\0';
if (i == 0) {
while (! isdumpline(line)) {
if (file_gets(line, VMS_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
line[VMS_LINE_LENGTH] = '\0';
}
while (line[offset] && !g_ascii_isxdigit(line[offset]))
offset++;
}
if (!parse_single_hex_dump_line(line, pd, i,
offset, pkt_len - i)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("vms: hex dump not valid");
return FALSE;
}
}
if (!file_gets(line, VMS_LINE_LENGTH, fh)) {
*err = file_error(fh, err_info);
if (*err == 0) {
return TRUE;
}
return FALSE;
}
return TRUE;
}
static gboolean
parse_single_hex_dump_line(char* rec, guint8 *buf, long byte_offset,
int in_off, int remaining) {
int i;
char *s;
int value;
static const int offsets[16] = {39,37,35,33,28,26,24,22,17,15,13,11,6,4,2,0};
char lbuf[3] = {0,0,0};
s = rec;
value = (int)strtoul(s + 45 + in_off, NULL, 16);
if (value != byte_offset) {
return FALSE;
}
if (remaining > 16)
remaining = 16;
for (i = 0; i < remaining; i++) {
lbuf[0] = rec[offsets[i] + in_off];
lbuf[1] = rec[offsets[i] + 1 + in_off];
buf[byte_offset + i] = (guint8) strtoul(lbuf, NULL, 16);
}
return TRUE;
}
