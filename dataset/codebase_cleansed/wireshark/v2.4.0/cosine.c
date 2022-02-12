static gboolean empty_line(const gchar *line)
{
while (*line) {
if (g_ascii_isspace(*line)) {
line++;
continue;
} else {
break;
}
}
if (*line == '\0')
return TRUE;
else
return FALSE;
}
static gint64 cosine_seek_next_packet(wtap *wth, int *err, gchar **err_info,
char *hdr)
{
gint64 cur_off;
char buf[COSINE_LINE_LENGTH];
while (1) {
cur_off = file_tell(wth->fh);
if (cur_off == -1) {
*err = file_error(wth->fh, err_info);
return -1;
}
if (file_gets(buf, sizeof(buf), wth->fh) == NULL) {
*err = file_error(wth->fh, err_info);
return -1;
}
if (strstr(buf, COSINE_REC_MAGIC_STR1) ||
strstr(buf, COSINE_REC_MAGIC_STR2)) {
g_strlcpy(hdr, buf, COSINE_LINE_LENGTH);
return cur_off;
}
}
return -1;
}
static gboolean cosine_check_file_type(wtap *wth, int *err, gchar **err_info)
{
char buf[COSINE_LINE_LENGTH];
gsize reclen;
guint line;
buf[COSINE_LINE_LENGTH-1] = '\0';
for (line = 0; line < COSINE_HEADER_LINES_TO_CHECK; line++) {
if (file_gets(buf, COSINE_LINE_LENGTH, wth->fh) == NULL) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
reclen = strlen(buf);
if (reclen < strlen(COSINE_HDR_MAGIC_STR1) ||
reclen < strlen(COSINE_HDR_MAGIC_STR2)) {
continue;
}
if (strstr(buf, COSINE_HDR_MAGIC_STR1) ||
strstr(buf, COSINE_HDR_MAGIC_STR2)) {
return TRUE;
}
}
*err = 0;
return FALSE;
}
wtap_open_return_val cosine_open(wtap *wth, int *err, gchar **err_info)
{
if (!cosine_check_file_type(wth, err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (file_seek(wth->fh, 0L, SEEK_SET, err) == -1)
return WTAP_OPEN_ERROR;
wth->file_encap = WTAP_ENCAP_COSINE;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_COSINE;
wth->snapshot_length = 0;
wth->subtype_read = cosine_read;
wth->subtype_seek_read = cosine_seek_read;
wth->file_tsprec = WTAP_TSPREC_CSEC;
return WTAP_OPEN_MINE;
}
static gboolean cosine_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset;
char line[COSINE_LINE_LENGTH];
offset = cosine_seek_next_packet(wth, err, err_info, line);
if (offset < 0)
return FALSE;
*data_offset = offset;
return parse_cosine_packet(wth->fh, &wth->phdr, wth->frame_buffer,
line, err, err_info);
}
static gboolean
cosine_seek_read(wtap *wth, gint64 seek_off, struct wtap_pkthdr *phdr,
Buffer *buf, int *err, gchar **err_info)
{
char line[COSINE_LINE_LENGTH];
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (file_gets(line, COSINE_LINE_LENGTH, wth->random_fh) == NULL) {
*err = file_error(wth->random_fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
return parse_cosine_packet(wth->random_fh, phdr, buf, line, err,
err_info);
}
static gboolean
parse_cosine_packet(FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
char *line, int *err, gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
int num_items_scanned;
int yy, mm, dd, hr, min, sec, csec, pkt_len;
int pro, off, pri, rm, error;
guint code1, code2;
char if_name[COSINE_MAX_IF_NAME_LEN] = "", direction[6] = "";
struct tm tm;
guint8 *pd;
int i, hex_lines, n, caplen = 0;
if (sscanf(line, "%4d-%2d-%2d,%2d:%2d:%2d.%9d:",
&yy, &mm, &dd, &hr, &min, &sec, &csec) == 7) {
num_items_scanned = sscanf(line,
"%4d-%2d-%2d,%2d:%2d:%2d.%9d: %5s (%127[A-Za-z0-9/:]), Length:%9d, Pro:%9d, Off:%9d, Pri:%9d, RM:%9d, Err:%9d [%8x, %8x]",
&yy, &mm, &dd, &hr, &min, &sec, &csec,
direction, if_name, &pkt_len,
&pro, &off, &pri, &rm, &error,
&code1, &code2);
if (num_items_scanned != 17) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("cosine: purported control blade line doesn't have code values");
return FALSE;
}
} else {
num_items_scanned = sscanf(line,
"%5s (%127[A-Za-z0-9/:]), Length:%9d, Pro:%9d, Off:%9d, Pri:%9d, RM:%9d, Err:%9d [%8x, %8x]",
direction, if_name, &pkt_len,
&pro, &off, &pri, &rm, &error,
&code1, &code2);
if (num_items_scanned != 10) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("cosine: header line is neither control blade nor PE output");
return FALSE;
}
yy = mm = dd = hr = min = sec = csec = 0;
}
if (pkt_len < 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("cosine: packet header has a negative packet length");
return FALSE;
}
if (pkt_len > WTAP_MAX_PACKET_SIZE_STANDARD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("cosine: File has %u-byte packet, bigger than maximum of %u",
pkt_len, WTAP_MAX_PACKET_SIZE_STANDARD);
return FALSE;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
tm.tm_year = yy - 1900;
tm.tm_mon = mm - 1;
tm.tm_mday = dd;
tm.tm_hour = hr;
tm.tm_min = min;
tm.tm_sec = sec;
tm.tm_isdst = -1;
phdr->ts.secs = mktime(&tm);
phdr->ts.nsecs = csec * 10000000;
phdr->len = pkt_len;
if (strncmp(if_name, "TEST:", 5) == 0) {
pseudo_header->cosine.encap = COSINE_ENCAP_TEST;
} else if (strncmp(if_name, "PPoATM:", 7) == 0) {
pseudo_header->cosine.encap = COSINE_ENCAP_PPoATM;
} else if (strncmp(if_name, "PPoFR:", 6) == 0) {
pseudo_header->cosine.encap = COSINE_ENCAP_PPoFR;
} else if (strncmp(if_name, "ATM:", 4) == 0) {
pseudo_header->cosine.encap = COSINE_ENCAP_ATM;
} else if (strncmp(if_name, "FR:", 3) == 0) {
pseudo_header->cosine.encap = COSINE_ENCAP_FR;
} else if (strncmp(if_name, "HDLC:", 5) == 0) {
pseudo_header->cosine.encap = COSINE_ENCAP_HDLC;
} else if (strncmp(if_name, "PPP:", 4) == 0) {
pseudo_header->cosine.encap = COSINE_ENCAP_PPP;
} else if (strncmp(if_name, "ETH:", 4) == 0) {
pseudo_header->cosine.encap = COSINE_ENCAP_ETH;
} else {
pseudo_header->cosine.encap = COSINE_ENCAP_UNKNOWN;
}
if (strncmp(direction, "l2-tx", 5) == 0) {
pseudo_header->cosine.direction = COSINE_DIR_TX;
} else if (strncmp(direction, "l2-rx", 5) == 0) {
pseudo_header->cosine.direction = COSINE_DIR_RX;
}
g_strlcpy(pseudo_header->cosine.if_name, if_name,
COSINE_MAX_IF_NAME_LEN);
pseudo_header->cosine.pro = pro;
pseudo_header->cosine.off = off;
pseudo_header->cosine.pri = pri;
pseudo_header->cosine.rm = rm;
pseudo_header->cosine.err = error;
ws_buffer_assure_space(buf, pkt_len);
pd = ws_buffer_start_ptr(buf);
hex_lines = pkt_len / 16 + ((pkt_len % 16) ? 1 : 0);
for (i = 0; i < hex_lines; i++) {
if (file_gets(line, COSINE_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
if (empty_line(line)) {
break;
}
if ((n = parse_single_hex_dump_line(line, pd, i*16)) == -1) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("cosine: hex dump line doesn't have 16 numbers");
return FALSE;
}
caplen += n;
}
phdr->caplen = caplen;
return TRUE;
}
static int
parse_single_hex_dump_line(char* rec, guint8 *buf, guint byte_offset)
{
int num_items_scanned, i;
unsigned int bytes[16];
num_items_scanned = sscanf(rec, "%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x",
&bytes[0], &bytes[1], &bytes[2], &bytes[3],
&bytes[4], &bytes[5], &bytes[6], &bytes[7],
&bytes[8], &bytes[9], &bytes[10], &bytes[11],
&bytes[12], &bytes[13], &bytes[14], &bytes[15]);
if (num_items_scanned == 0)
return -1;
if (num_items_scanned > 16)
num_items_scanned = 16;
for (i=0; i<num_items_scanned; i++) {
buf[byte_offset + i] = (guint8)bytes[i];
}
return num_items_scanned;
}
