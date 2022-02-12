static gboolean info_line(const gchar *line)
{
int i=NETSCREEN_SPACES_ON_INFO_LINE;
while (i-- > 0) {
if (isspace((guchar)*line)) {
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
int netscreen_open(wtap *wth, int *err, gchar **err_info)
{
if (!netscreen_check_file_type(wth, err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (file_seek(wth->fh, 0L, SEEK_SET, err) == -1)
return -1;
wth->file_encap = WTAP_ENCAP_UNKNOWN;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_NETSCREEN;
wth->snapshot_length = 0;
wth->subtype_read = netscreen_read;
wth->subtype_seek_read = netscreen_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_DSEC;
return 1;
}
static gboolean netscreen_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset;
int pkt_len;
char line[NETSCREEN_LINE_LENGTH];
char cap_int[NETSCREEN_MAX_INT_NAME_LENGTH];
gboolean cap_dir;
char cap_dst[13];
offset = netscreen_seek_next_packet(wth, err, err_info, line);
if (offset < 0)
return FALSE;
pkt_len = parse_netscreen_rec_hdr(&wth->phdr, line, cap_int, &cap_dir,
cap_dst, err, err_info);
if (pkt_len == -1)
return FALSE;
if (!parse_netscreen_hex_dump(wth->fh, pkt_len, cap_int,
cap_dst, &wth->phdr, wth->frame_buffer, err, err_info))
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
int pkt_len;
char line[NETSCREEN_LINE_LENGTH];
char cap_int[NETSCREEN_MAX_INT_NAME_LENGTH];
gboolean cap_dir;
char cap_dst[13];
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
pkt_len = parse_netscreen_rec_hdr(phdr, line, cap_int, &cap_dir,
cap_dst, err, err_info);
if (pkt_len == -1)
return FALSE;
if (!parse_netscreen_hex_dump(wth->random_fh, pkt_len, cap_int,
cap_dst, phdr, buf, err, err_info))
return FALSE;
return TRUE;
}
static int
parse_netscreen_rec_hdr(struct wtap_pkthdr *phdr, const char *line, char *cap_int,
gboolean *cap_dir, char *cap_dst, int *err, gchar **err_info)
{
int sec;
int dsec, pkt_len;
char direction[2];
char cap_src[13];
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
if (sscanf(line, "%9d.%9d: %15[a-z0-9/:.-](%1[io]) len=%9d:%12s->%12s/",
&sec, &dsec, cap_int, direction, &pkt_len, cap_src, cap_dst) < 5) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netscreen: Can't parse packet-header");
return -1;
}
*cap_dir = (direction[0] == 'o' ? NETSCREEN_EGRESS : NETSCREEN_INGRESS);
phdr->ts.secs = sec;
phdr->ts.nsecs = dsec * 100000000;
phdr->len = pkt_len;
return pkt_len;
}
static gboolean
parse_netscreen_hex_dump(FILE_T fh, int pkt_len, const char *cap_int,
const char *cap_dst, struct wtap_pkthdr *phdr, Buffer* buf,
int *err, gchar **err_info)
{
guint8 *pd;
gchar line[NETSCREEN_LINE_LENGTH];
gchar *p;
int n, i = 0, offset = 0;
gchar dststr[13];
buffer_assure_space(buf, NETSCREEN_MAX_PACKET_LEN);
pd = buffer_start_ptr(buf);
while(1) {
if (file_gets(line, NETSCREEN_LINE_LENGTH, fh) == NULL) {
break;
}
for (p = &line[0]; isspace((guchar)*p); p++)
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
if(n == -1) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("netscreen: cannot parse hex-data");
return FALSE;
}
offset += n;
if(offset > pkt_len) {
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
