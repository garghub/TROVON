static gint64 dbs_etherwatch_seek_next_packet(wtap *wth, int *err,
gchar **err_info)
{
int byte;
unsigned int level = 0;
gint64 cur_off;
while ((byte = file_getc(wth->fh)) != EOF) {
if (byte == dbs_etherwatch_rec_magic[level]) {
level++;
if (level >= DBS_ETHERWATCH_REC_MAGIC_SIZE) {
cur_off = file_tell(wth->fh);
if (cur_off == -1) {
*err = file_error(wth->fh, err_info);
return -1;
}
return cur_off + 1;
}
} else {
level = 0;
}
}
*err = file_error(wth->fh, err_info);
return -1;
}
static gboolean dbs_etherwatch_check_file_type(wtap *wth, int *err,
gchar **err_info)
{
char buf[DBS_ETHERWATCH_LINE_LENGTH];
int line, byte;
gsize reclen;
unsigned int i, level;
buf[DBS_ETHERWATCH_LINE_LENGTH-1] = 0;
for (line = 0; line < DBS_ETHERWATCH_HEADER_LINES_TO_CHECK; line++) {
if (file_gets(buf, DBS_ETHERWATCH_LINE_LENGTH, wth->fh) == NULL) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
reclen = strlen(buf);
if (reclen < DBS_ETHERWATCH_HDR_MAGIC_SIZE)
continue;
level = 0;
for (i = 0; i < reclen; i++) {
byte = buf[i];
if (byte == dbs_etherwatch_hdr_magic[level]) {
level++;
if (level >=
DBS_ETHERWATCH_HDR_MAGIC_SIZE) {
return TRUE;
}
}
else
level = 0;
}
}
*err = 0;
return FALSE;
}
int dbs_etherwatch_open(wtap *wth, int *err, gchar **err_info)
{
if (!dbs_etherwatch_check_file_type(wth, err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
wth->file_encap = WTAP_ENCAP_ETHERNET;
wth->file_type = WTAP_FILE_DBS_ETHERWATCH;
wth->snapshot_length = 0;
wth->subtype_read = dbs_etherwatch_read;
wth->subtype_seek_read = dbs_etherwatch_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_CSEC;
return 1;
}
static gboolean dbs_etherwatch_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset;
offset = dbs_etherwatch_seek_next_packet(wth, err, err_info);
if (offset < 1)
return FALSE;
*data_offset = offset;
return parse_dbs_etherwatch_packet(&wth->phdr, wth->fh,
wth->frame_buffer, err, err_info);
}
static gboolean
dbs_etherwatch_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf, int len _U_,
int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off - 1, SEEK_SET, err) == -1)
return FALSE;
return parse_dbs_etherwatch_packet(phdr, wth->random_fh, buf, err,
err_info);
}
static gboolean
parse_dbs_etherwatch_packet(struct wtap_pkthdr *phdr, FILE_T fh, Buffer* buf,
int *err, gchar **err_info)
{
guint8 *pd;
char line[DBS_ETHERWATCH_LINE_LENGTH];
int num_items_scanned;
int eth_hdr_len, pkt_len, csec;
int length_pos, length_from, length;
struct tm tm;
char mon[4] = "xxx";
gchar *p;
static const gchar months[] = "JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC";
int count, line_count;
buffer_assure_space(buf, DBS_ETHERWATCH_MAX_PACKET_LEN);
pd = buffer_start_ptr(buf);
eth_hdr_len = 0;
memset(&tm, 0, sizeof(tm));
if (file_gets(line, DBS_ETHERWATCH_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
p = strstr(line, DEST_MAC_PREFIX);
if(!p) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: destination address not found");
return FALSE;
}
p += strlen(DEST_MAC_PREFIX);
if(parse_hex_dump(p, &pd[eth_hdr_len], HEX_HDR_SPR, HEX_HDR_END)
!= MAC_ADDR_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: destination address not valid");
return FALSE;
}
eth_hdr_len += MAC_ADDR_LENGTH;
p = line;
while(!isxdigit((guchar)*p)) {
p++;
}
if(parse_hex_dump(p, &pd[eth_hdr_len], HEX_HDR_SPR,
HEX_HDR_END) != MAC_ADDR_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: source address not valid");
return FALSE;
}
eth_hdr_len += MAC_ADDR_LENGTH;
if (file_gets(line, DBS_ETHERWATCH_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
if(strlen(line) < LENGTH_POS) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: line too short");
return FALSE;
}
num_items_scanned = sscanf(line + LENGTH_POS,
"%9d byte buffer at %2d-%3s-%4d %2d:%2d:%2d.%9d",
&pkt_len,
&tm.tm_mday, mon,
&tm.tm_year, &tm.tm_hour, &tm.tm_min,
&tm.tm_sec, &csec);
if (num_items_scanned != 8) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: header line not valid");
return FALSE;
}
if(strncmp(&line[ETH_II_CHECK_POS], ETH_II_CHECK_STR,
strlen(ETH_II_CHECK_STR)) == 0) {
if(parse_hex_dump(&line[PROTOCOL_POS], &pd[eth_hdr_len], HEX_HDR_SPR,
HEX_HDR_END) != PROTOCOL_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: Ethernet II protocol value not valid");
return FALSE;
}
eth_hdr_len += PROTOCOL_LENGTH;
} else {
length_pos = eth_hdr_len;
eth_hdr_len += IEEE802_LEN_LEN;
length_from = eth_hdr_len;
if(parse_hex_dump(&line[SAP_POS], &pd[eth_hdr_len], HEX_HDR_SPR,
HEX_HDR_END) != SAP_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: 802.2 DSAP+SSAP value not valid");
return FALSE;
}
eth_hdr_len += SAP_LENGTH;
if(parse_hex_dump(&line[CTL_POS], &pd[eth_hdr_len], HEX_HDR_SPR,
HEX_HDR_END) != CTL_UNNUMB_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: 802.2 control field first part not valid");
return FALSE;
}
if((pd[eth_hdr_len] & CTL_UNNUMB_MASK) != CTL_UNNUMB_VALUE) {
if(parse_hex_dump(&line[PID_POS],
&pd[eth_hdr_len + CTL_UNNUMB_LENGTH], HEX_HDR_END,
HEX_HDR_SPR) != CTL_NUMB_LENGTH - CTL_UNNUMB_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: 802.2 control field second part value not valid");
return FALSE;
}
eth_hdr_len += CTL_NUMB_LENGTH;
} else {
eth_hdr_len += CTL_UNNUMB_LENGTH;
}
if(strncmp(&line[SNAP_CHECK_POS], SNAP_CHECK_STR,
strlen(SNAP_CHECK_STR)) == 0) {
if(parse_hex_dump(&line[PID_POS], &pd[eth_hdr_len], HEX_HDR_SPR,
HEX_PID_END) != PID_LENGTH) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: 802.2 PID value not valid");
return FALSE;
}
eth_hdr_len += PID_LENGTH;
}
length = eth_hdr_len - length_from + pkt_len;
pd[length_pos] = (length) >> 8;
pd[length_pos+1] = (length) & 0xFF;
}
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
p = strstr(months, mon);
if (p)
tm.tm_mon = (int)(p - months) / 3;
tm.tm_year -= 1900;
tm.tm_isdst = -1;
phdr->ts.secs = mktime(&tm);
phdr->ts.nsecs = csec * 10000000;
phdr->caplen = eth_hdr_len + pkt_len;
phdr->len = eth_hdr_len + pkt_len;
phdr->pseudo_header.eth.fcs_len = 0;
count = 0;
while (count < pkt_len) {
if (file_gets(line, DBS_ETHERWATCH_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
if (!(line_count = parse_single_hex_dump_line(line,
&pd[eth_hdr_len + count], count))) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: packet data value not valid");
return FALSE;
}
count += line_count;
if (count > pkt_len) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("dbs_etherwatch: packet data value has too many bytes");
return FALSE;
}
}
return TRUE;
}
static guint
parse_single_hex_dump_line(char* rec, guint8 *buf, int byte_offset) {
int pos, i;
int value;
for(i = 0; i < TYPE_CHECK_POS; i++)
{
if(rec[i] == '\0') {
return 0;
}
}
if(rec[TYPE_CHECK_POS] == TYPE_CHECK_BOTH)
{
pos = COUNT_POS_BOTH;
}
else
{
pos = COUNT_POS_HEX;
}
while(i < pos)
{
if(rec[i] == '\0') {
return 0;
}
i++;
}
value = 0;
for(i = 0; i < COUNT_SIZE; i++) {
if(!isspace((guchar)rec[pos])) {
if(isdigit((guchar)rec[pos])) {
value *= 10;
value += rec[pos] - '0';
} else {
return 0;
}
}
pos++;
}
if (value != byte_offset) {
return 0;
}
while(rec[pos] != HEX_DUMP_START) {
if(rec[pos] == '\0') {
return 0;
}
pos++;
}
pos++;
return parse_hex_dump(&rec[pos], buf, HEX_DUMP_SPR, HEX_DUMP_END);
}
static guint
parse_hex_dump(char* dump, guint8 *buf, char seperator, char end) {
int pos, count;
pos = 0;
count = 0;
while(dump[pos] != end) {
if(!(isxdigit((guchar)dump[pos]) &&
isxdigit((guchar)dump[pos + 1]))) {
return 0;
}
if(isdigit((guchar)dump[pos])) {
buf[count] = (dump[pos] - '0') << 4;
} else {
buf[count] = (toupper(dump[pos]) - 'A' + 10) << 4;
}
pos++;
if(isdigit((guchar)dump[pos])) {
buf[count] += dump[pos] - '0';
} else {
buf[count] += toupper(dump[pos]) - 'A' + 10;
}
pos++;
count++;
while(dump[pos] == seperator) {
pos++;
}
}
return count;
}
