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
if (file_eof(wth->fh)) {
*err = 0;
} else {
*err = file_error(wth->fh, err_info);
}
return -1;
}
static gboolean toshiba_check_file_type(wtap *wth, int *err, gchar **err_info)
{
char buf[TOSHIBA_LINE_LENGTH];
guint i, reclen, level, line;
char byte;
buf[TOSHIBA_LINE_LENGTH-1] = 0;
for (line = 0; line < TOSHIBA_HEADER_LINES_TO_CHECK; line++) {
if (file_gets(buf, TOSHIBA_LINE_LENGTH, wth->fh) != NULL) {
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
else {
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
int toshiba_open(wtap *wth, int *err, gchar **err_info)
{
if (!toshiba_check_file_type(wth, err, err_info)) {
if (*err == 0)
return 0;
else
return -1;
}
wth->file_encap = WTAP_ENCAP_PER_PACKET;
wth->file_type = WTAP_FILE_TOSHIBA;
wth->snapshot_length = 0;
wth->subtype_read = toshiba_read;
wth->subtype_seek_read = toshiba_seek_read;
wth->tsprecision = WTAP_FILE_TSPREC_CSEC;
return 1;
}
static gboolean toshiba_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset;
guint8 *buf;
int pkt_len;
offset = toshiba_seek_next_packet(wth, err, err_info);
if (offset < 1)
return FALSE;
pkt_len = parse_toshiba_rec_hdr(wth, wth->fh, &wth->pseudo_header,
err, err_info);
if (pkt_len == -1)
return FALSE;
buffer_assure_space(wth->frame_buffer, TOSHIBA_MAX_PACKET_LEN);
buf = buffer_start_ptr(wth->frame_buffer);
if (!parse_toshiba_hex_dump(wth->fh, pkt_len, buf, err, err_info))
return FALSE;
*data_offset = offset;
return TRUE;
}
static gboolean
toshiba_seek_read (wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_header, guint8 *pd, int len,
int *err, gchar **err_info)
{
int pkt_len;
if (file_seek(wth->random_fh, seek_off - 1, SEEK_SET, err) == -1)
return FALSE;
pkt_len = parse_toshiba_rec_hdr(NULL, wth->random_fh, pseudo_header,
err, err_info);
if (pkt_len != len) {
if (pkt_len != -1) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup_printf("toshiba: requested length %d doesn't match record length %d",
len, pkt_len);
}
return FALSE;
}
return parse_toshiba_hex_dump(wth->random_fh, pkt_len, pd, err, err_info);
}
static int
parse_toshiba_rec_hdr(wtap *wth, FILE_T fh,
union wtap_pseudo_header *pseudo_header, int *err, gchar **err_info)
{
char line[TOSHIBA_LINE_LENGTH];
int num_items_scanned;
int pkt_len, pktnum, hr, min, sec, csec;
char channel[10], direction[10];
if (file_gets(line, TOSHIBA_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
num_items_scanned = sscanf(line, "%9d] %2d:%2d:%2d.%9d %9s %9s",
&pktnum, &hr, &min, &sec, &csec, channel, direction);
if (num_items_scanned != 7) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("toshiba: record header isn't valid");
return -1;
}
do {
if (file_gets(line, TOSHIBA_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return -1;
}
line[16] = '\0';
} while (strcmp(line, "OFFSET 0001-0203") != 0);
num_items_scanned = sscanf(line+64, "LEN=%9d", &pkt_len);
if (num_items_scanned != 1) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("toshiba: OFFSET line doesn't have valid LEN item");
return -1;
}
if (wth) {
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
wth->phdr.ts.secs = hr * 3600 + min * 60 + sec;
wth->phdr.ts.nsecs = csec * 10000000;
wth->phdr.caplen = pkt_len;
wth->phdr.len = pkt_len;
}
switch (channel[0]) {
case 'B':
if (wth)
wth->phdr.pkt_encap = WTAP_ENCAP_ISDN;
pseudo_header->isdn.uton = (direction[0] == 'T');
pseudo_header->isdn.channel = (guint8)
strtol(&channel[1], NULL, 10);
break;
case 'D':
if (wth)
wth->phdr.pkt_encap = WTAP_ENCAP_ISDN;
pseudo_header->isdn.uton = (direction[0] == 'T');
pseudo_header->isdn.channel = 0;
break;
default:
if (wth)
wth->phdr.pkt_encap = WTAP_ENCAP_ETHERNET;
pseudo_header->eth.fcs_len = -1;
break;
}
return pkt_len;
}
static gboolean
parse_toshiba_hex_dump(FILE_T fh, int pkt_len, guint8* buf, int *err,
gchar **err_info)
{
char line[TOSHIBA_LINE_LENGTH];
int i, hex_lines;
hex_lines = pkt_len / 16 + ((pkt_len % 16) ? 1 : 0);
for (i = 0; i < hex_lines; i++) {
if (file_gets(line, TOSHIBA_LINE_LENGTH, fh) == NULL) {
*err = file_error(fh, err_info);
if (*err == 0) {
*err = WTAP_ERR_SHORT_READ;
}
return FALSE;
}
if (!parse_single_hex_dump_line(line, buf, i * 16)) {
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
