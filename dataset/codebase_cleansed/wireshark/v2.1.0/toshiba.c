static gint64 toshiba_seek_next_packet(wtap *wth, int *err, gchar **err_info)
{
int byte;
guint level = 0;
gint64 cur_off;
while ((byte = file_getc(wth->fh)) != EOF) {
if (byte == toshiba_rec_magic[level]) {
level++;
if (level >= TOSHIBA_REC_MAGIC_SIZE) {
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
static gboolean toshiba_check_file_type(wtap *wth, int *err, gchar **err_info)
{
char buf[TOSHIBA_LINE_LENGTH];
guint i, reclen, level, line;
char byte;
buf[TOSHIBA_LINE_LENGTH-1] = 0;
for (line = 0; line < TOSHIBA_HEADER_LINES_TO_CHECK; line++) {
if (file_gets(buf, TOSHIBA_LINE_LENGTH, wth->fh) == NULL) {
*err = file_error(wth->fh, err_info);
return FALSE;
}
reclen = (guint) strlen(buf);
if (reclen < TOSHIBA_HDR_MAGIC_SIZE) {
continue;
}
level = 0;
for (i = 0; i < reclen; i++) {
byte = buf[i];
if (byte == toshiba_hdr_magic[level]) {
level++;
if (level >= TOSHIBA_HDR_MAGIC_SIZE) {
return TRUE;
}
}
else {
level = 0;
}
}
}
*err = 0;
return FALSE;
}
wtap_open_return_val toshiba_open(wtap *wth, int *err, gchar **err_info)
{
if (!toshiba_check_file_type(wth, err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
wth->file_encap = WTAP_ENCAP_PER_PACKET;
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_TOSHIBA;
wth->snapshot_length = 0;
wth->subtype_read = toshiba_read;
wth->subtype_seek_read = toshiba_seek_read;
wth->file_tsprec = WTAP_TSPREC_CSEC;
return WTAP_OPEN_MINE;
}
static gboolean toshiba_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset;
offset = toshiba_seek_next_packet(wth, err, err_info);
if (offset < 1)
return FALSE;
*data_offset = offset;
return parse_toshiba_packet(wth->fh, &wth->phdr, wth->frame_buffer,
err, err_info);
}
static gboolean
toshiba_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
if (file_seek(wth->random_fh, seek_off - 1, SEEK_SET, err) == -1)
return FALSE;
if (!parse_toshiba_packet(wth->random_fh, phdr, buf, err, err_info)) {
if (*err == 0)
*err = WTAP_ERR_SHORT_READ;
return FALSE;
}
return TRUE;
}
static gboolean
parse_toshiba_packet(FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
char line[TOSHIBA_LINE_LENGTH];
int num_items_scanned;
int pkt_len, pktnum, hr, min, sec, csec;
char channel[10], direction[10];
int i, hex_lines;
guint8 *pd;
if (file_gets(line, TOSHIBA_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
num_items_scanned = sscanf(line, "%9d] %2d:%2d:%2d.%9d %9s %9s",
&pktnum, &hr, &min, &sec, &csec, channel, direction);
if (num_items_scanned != 7) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("toshiba: record header isn't valid");
return FALSE;
}
do {
if (file_gets(line, TOSHIBA_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
line[16] = '\0';
} while (strcmp(line, "OFFSET 0001-0203") != 0);
num_items_scanned = sscanf(line+64, "LEN=%9d", &pkt_len);
if (num_items_scanned != 1) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("toshiba: OFFSET line doesn't have valid LEN item");
return FALSE;
}
if (pkt_len < 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("toshiba: packet header has a negative packet length");
return FALSE;
}
if (pkt_len > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("toshiba: File has %u-byte packet, bigger than maximum of %u",
pkt_len, WTAP_MAX_PACKET_SIZE);
return FALSE;
}
phdr->rec_type = REC_TYPE_PACKET;
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->ts.secs = hr * 3600 + min * 60 + sec;
phdr->ts.nsecs = csec * 10000000;
phdr->caplen = pkt_len;
phdr->len = pkt_len;
switch (channel[0]) {
case 'B':
phdr->pkt_encap = WTAP_ENCAP_ISDN;
pseudo_header->isdn.uton = (direction[0] == 'T');
pseudo_header->isdn.channel = (guint8)
strtol(&channel[1], NULL, 10);
break;
case 'D':
phdr->pkt_encap = WTAP_ENCAP_ISDN;
pseudo_header->isdn.uton = (direction[0] == 'T');
pseudo_header->isdn.channel = 0;
break;
default:
phdr->pkt_encap = WTAP_ENCAP_ETHERNET;
pseudo_header->eth.fcs_len = -1;
break;
}
ws_buffer_assure_space(buf, pkt_len);
pd = ws_buffer_start_ptr(buf);
hex_lines = pkt_len / 16 + ((pkt_len % 16) ? 1 : 0);
for (i = 0; i < hex_lines; i++) {
if (file_gets(line, TOSHIBA_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
if (!parse_single_hex_dump_line(line, pd, i * 16)) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("toshiba: hex dump not valid");
return FALSE;
}
}
return TRUE;
}
static gboolean
parse_single_hex_dump_line(char* rec, guint8 *buf, guint byte_offset) {
int pos, i;
char *s;
unsigned long value;
guint16 word_value;
rec[4] = '\0';
s = rec;
value = strtoul(s, NULL, 16);
if (value != byte_offset) {
return FALSE;
}
for (pos = START_POS; pos < START_POS + HEX_LENGTH; pos++) {
if (rec[pos] == ' ') {
rec[pos] = '0';
}
}
pos = START_POS;
for (i = 0; i < 8; i++) {
rec[pos+4] = '\0';
word_value = (guint16) strtoul(&rec[pos], NULL, 16);
buf[byte_offset + i * 2 + 0] = (guint8) (word_value >> 8);
buf[byte_offset + i * 2 + 1] = (guint8) (word_value & 0x00ff);
pos += 5;
}
return TRUE;
}
