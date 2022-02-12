static long vms_seek_next_packet(wtap *wth, int *err)
{
long cur_off;
char buf[VMS_LINE_LENGTH];
while (1) {
cur_off = file_tell(wth->fh);
if (cur_off == -1) {
*err = file_error(wth->fh, err_info);
hdr = NULL;
return -1;
}
if (file_gets(buf, sizeof(buf), wth->fh) != NULL) {
if (strstr(buf, VMS_REC_MAGIC_STR1) ||
strstr(buf, VMS_REC_MAGIC_STR2) ||
strstr(buf, VMS_REC_MAGIC_STR2)) {
g_strlcpy(hdr, buf,VMS_LINE_LENGTH);
return cur_off;
}
} else {
if (file_eof(wth->fh)) {
*err = 0;
} else {
*err = file_error(wth->fh, err_info);
}
break;
}
}
hdr = NULL;
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
if (file_gets(buf, VMS_LINE_LENGTH, wth->fh) != NULL) {
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
} else {
if (file_eof(wth->fh))
*err = 0;
else
*err = file_error(wth->fh, err_info);
return FALSE;
}
}
*err = 0;
return FALSE;
}
int vms_open(wtap *wth, int *err, gchar **err_info)
{
if (!vms_check_file_type(wth, err, err_info)) {
if (*err == 0)
return 0;
else
return -1;
}
wth->file_encap = WTAP_ENCAP_RAW_IP;
wth->file_type = WTAP_FILE_VMS;
wth->snapshot_length = 0;
wth->subtype_read = vms_read;
wth->subtype_seek_read = vms_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_CSEC;
return 1;
}
static gboolean vms_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset = 0;
guint8 *buf;
int pkt_len;
#ifdef TCPIPTRACE_FRAGMENTS_HAVE_HEADER_LINE
offset = vms_seek_next_packet(wth, err);
#else
offset = file_tell(wth->fh);
#endif
if (offset < 1) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
pkt_len = parse_vms_rec_hdr(wth, wth->fh, err, err_info);
if (pkt_len == -1)
return FALSE;
buffer_assure_space(wth->frame_buffer, pkt_len);
buf = buffer_start_ptr(wth->frame_buffer);
if (!parse_vms_hex_dump(wth->fh, pkt_len, buf, err, err_info))
return FALSE;
*data_offset = offset;
return TRUE;
}
static gboolean
vms_seek_read (wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header _U_,
guint8 *pd, int len, int *err, gchar **err_info)
{
int pkt_len;
if (file_seek(wth->random_fh, seek_off - 1, SEEK_SET, err) == -1)
return FALSE;
pkt_len = parse_vms_rec_hdr(NULL, wth->random_fh, err, err_info);
if (pkt_len != len) {
if (pkt_len != -1) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("vms: requested length %d doesn't match length %d",
len, pkt_len);
}
return FALSE;
}
return parse_vms_hex_dump(wth->random_fh, pkt_len, pd, err, err_info);
}
static int
isdumpline( gchar *line )
{
int i, j;
while (*line && !isalnum((guchar)*line))
line++;
for (j=0; j<4; j++) {
for (i=0; i<8; i++, line++)
if (! isxdigit((guchar)*line))
return FALSE;
for (i=0; i<3; i++, line++)
if (*line != ' ')
return FALSE;
}
return isspace((guchar)*line);
}
static int
parse_vms_rec_hdr(wtap *wth, FILE_T fh, int *err, gchar **err_info)
{
char line[VMS_LINE_LENGTH + 1];
int num_items_scanned;
int pkt_len = 0;
int pktnum;
int csec = 101;
struct tm tm;
char mon[4] = {'J', 'A', 'N', 0};
gchar *p;
static const gchar months[] = "JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";
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
return -1;
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
*err_info = g_strdup_printf("vms: header line not valid");
return -1;
}
}
if ( (! pkt_len) && (p = strstr(line, "Length"))) {
p += sizeof("Length ");
while (*p && ! isdigit((guchar)*p))
p++;
if ( !*p ) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("vms: Length field not valid");
return -1;
}
pkt_len = atoi(p);
break;
}
} while (! isdumpline(line));
if (wth) {
p = strstr(months, mon);
if (p)
tm.tm_mon = (int) (p - months) / 3;
tm.tm_year -= 1900;
tm.tm_isdst = -1;
wth->phdr.presence_flags = WTAP_HAS_TS;
wth->phdr.ts.secs = mktime(&tm);
wth->phdr.ts.nsecs = csec * 10000000;
wth->phdr.caplen = pkt_len;
wth->phdr.len = pkt_len;
}
return pkt_len;
}
static gboolean
parse_vms_hex_dump(FILE_T fh, int pkt_len, guint8* buf, int *err,
gchar **err_info)
{
gchar line[VMS_LINE_LENGTH + 1];
int i;
int offset = 0;
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
while (line[offset] && !isxdigit((guchar)line[offset]))
offset++;
}
if (!parse_single_hex_dump_line(line, buf, i,
offset, pkt_len - i)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("vms: hex dump not valid");
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
