int
catapult_dct2000_open(wtap *wth, int *err, gchar **err_info)
{
gint64 offset = 0;
time_t timestamp;
guint32 usecs;
gint firstline_length = 0;
dct2000_file_externals_t *file_externals;
static gchar linebuff[MAX_LINE_LENGTH];
static gboolean hex_byte_table_values_set = FALSE;
errno = 0;
if (!read_new_line(wth->fh, &offset, &firstline_length, linebuff,
sizeof linebuff, err, err_info)) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if (((size_t)firstline_length < strlen(catapult_dct2000_magic)) ||
firstline_length >= MAX_FIRST_LINE_LENGTH) {
return 0;
}
if (memcmp(catapult_dct2000_magic, linebuff, strlen(catapult_dct2000_magic)) != 0) {
return 0;
}
if (!hex_byte_table_values_set) {
prepare_hex_byte_from_chars_table();
hex_byte_table_values_set = TRUE;
}
file_externals = g_new(dct2000_file_externals_t,1);
memset((void*)file_externals, '\0', sizeof(dct2000_file_externals_t));
g_strlcpy(file_externals->firstline, linebuff, firstline_length+1);
file_externals->firstline_length = firstline_length;
if (!read_new_line(wth->fh, &offset, &(file_externals->secondline_length),
linebuff, sizeof linebuff, err, err_info)) {
g_free(file_externals);
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
if ((file_externals->secondline_length >= MAX_TIMESTAMP_LINE_LENGTH) ||
(!get_file_time_stamp(linebuff, &timestamp, &usecs))) {
g_free(file_externals);
return 0;
}
file_externals->start_secs = timestamp;
file_externals->start_usecs = usecs;
g_strlcpy(file_externals->secondline, linebuff, file_externals->secondline_length+1);
wth->file_type = WTAP_FILE_CATAPULT_DCT2000;
wth->file_encap = WTAP_ENCAP_CATAPULT_DCT2000;
wth->subtype_read = catapult_dct2000_read;
wth->subtype_seek_read = catapult_dct2000_seek_read;
wth->subtype_close = catapult_dct2000_close;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
file_externals->packet_prefix_table =
g_hash_table_new(packet_offset_hash_func, packet_offset_equal);
wth->priv = (void*)file_externals;
*err = errno;
return 1;
}
static void write_timestamp_string(char *timestamp_string, int secs, int tenthousandths)
{
int idx = 0;
if (secs < 10) {
timestamp_string[idx++] = ((secs % 10)) + '0';
}
else if (secs < 100) {
timestamp_string[idx++] = ( secs / 10) + '0';
timestamp_string[idx++] = ((secs % 10)) + '0';
}
else if (secs < 1000) {
timestamp_string[idx++] = ((secs) / 100) + '0';
timestamp_string[idx++] = ((secs % 100)) / 10 + '0';
timestamp_string[idx++] = ((secs % 10)) + '0';
}
else if (secs < 10000) {
timestamp_string[idx++] = ((secs) / 1000) + '0';
timestamp_string[idx++] = ((secs % 1000)) / 100 + '0';
timestamp_string[idx++] = ((secs % 100)) / 10 + '0';
timestamp_string[idx++] = ((secs % 10)) + '0';
}
else if (secs < 100000) {
timestamp_string[idx++] = ((secs) / 10000) + '0';
timestamp_string[idx++] = ((secs % 10000)) / 1000 + '0';
timestamp_string[idx++] = ((secs % 1000)) / 100 + '0';
timestamp_string[idx++] = ((secs % 100)) / 10 + '0';
timestamp_string[idx++] = ((secs % 10)) + '0';
}
else if (secs < 1000000) {
timestamp_string[idx++] = ((secs) / 100000) + '0';
timestamp_string[idx++] = ((secs % 100000)) / 10000 + '0';
timestamp_string[idx++] = ((secs % 10000)) / 1000 + '0';
timestamp_string[idx++] = ((secs % 1000)) / 100 + '0';
timestamp_string[idx++] = ((secs % 100)) / 10 + '0';
timestamp_string[idx++] = ((secs % 10)) + '0';
}
else {
g_snprintf(timestamp_string, MAX_TIMESTAMP_LEN, "%d.%04d", secs, tenthousandths);
return;
}
timestamp_string[idx++] = '.';
timestamp_string[idx++] = ( tenthousandths / 1000) + '0';
timestamp_string[idx++] = ((tenthousandths % 1000) / 100) + '0';
timestamp_string[idx++] = ((tenthousandths % 100) / 10) + '0';
timestamp_string[idx++] = ((tenthousandths % 10)) + '0';
timestamp_string[idx++] = '\0';
}
static gboolean
catapult_dct2000_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
gint64 offset = file_tell(wth->fh);
long dollar_offset, before_time_offset, after_time_offset;
packet_direction_t direction;
int encap;
dct2000_file_externals_t *file_externals =
(dct2000_file_externals_t*)wth->priv;
while (1) {
int line_length, seconds, useconds, data_chars;
int is_comment = FALSE;
int is_sprint = FALSE;
gint64 this_offset = offset;
static gchar linebuff[MAX_LINE_LENGTH+1];
gchar aal_header_chars[AAL_HEADER_CHARS];
gchar context_name[MAX_CONTEXT_NAME];
guint8 context_port = 0;
gchar protocol_name[MAX_PROTOCOL_NAME+1];
gchar variant_name[MAX_VARIANT_DIGITS+1];
gchar outhdr_name[MAX_OUTHDR_NAME+1];
if (file_tell(wth->fh) == 0) {
this_offset += (file_externals->firstline_length+1+
file_externals->secondline_length+1);
}
if (!read_new_line(wth->fh, &offset, &line_length, linebuff,
sizeof linebuff, err, err_info)) {
if (*err != 0)
return FALSE;
break;
}
if (parse_line(linebuff, line_length, &seconds, &useconds,
&before_time_offset, &after_time_offset,
&dollar_offset,
&data_chars, &direction, &encap, &is_comment, &is_sprint,
aal_header_chars,
context_name, &context_port,
protocol_name, variant_name, outhdr_name)) {
line_prefix_info_t *line_prefix_info;
char timestamp_string[MAX_TIMESTAMP_LEN+1];
gint64 *pkey = NULL;
write_timestamp_string(timestamp_string, seconds, useconds/100);
*data_offset = this_offset;
process_parsed_line(wth, file_externals,
&wth->phdr,
wth->frame_buffer, this_offset,
linebuff, dollar_offset,
seconds, useconds, timestamp_string,
direction, encap,
context_name, context_port,
protocol_name, variant_name,
outhdr_name, aal_header_chars,
is_comment, data_chars);
line_prefix_info = g_new(line_prefix_info_t,1);
line_prefix_info->before_time = (gchar *)g_malloc(before_time_offset+1);
memcpy(line_prefix_info->before_time, linebuff, before_time_offset);
line_prefix_info->before_time[before_time_offset] = '\0';
if (((size_t)(dollar_offset - after_time_offset -1) == strlen(" l ")) &&
(strncmp(linebuff+after_time_offset, " l ", strlen(" l ")) == 0)) {
line_prefix_info->after_time = NULL;
}
else {
line_prefix_info->after_time = (gchar *)g_malloc(dollar_offset - after_time_offset);
memcpy(line_prefix_info->after_time, linebuff+after_time_offset, dollar_offset - after_time_offset);
line_prefix_info->after_time[dollar_offset - after_time_offset-1] = '\0';
}
pkey = (gint64 *)g_malloc(sizeof(*pkey));
*pkey = this_offset;
g_hash_table_insert(file_externals->packet_prefix_table, pkey, line_prefix_info);
return TRUE;
}
}
return FALSE;
}
static gboolean
catapult_dct2000_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf,
int length, int *err, gchar **err_info)
{
gint64 offset = 0;
long dollar_offset, before_time_offset, after_time_offset;
static gchar linebuff[MAX_LINE_LENGTH+1];
gchar aal_header_chars[AAL_HEADER_CHARS];
gchar context_name[MAX_CONTEXT_NAME];
guint8 context_port = 0;
gchar protocol_name[MAX_PROTOCOL_NAME+1];
gchar variant_name[MAX_VARIANT_DIGITS+1];
gchar outhdr_name[MAX_OUTHDR_NAME+1];
int is_comment = FALSE;
int is_sprint = FALSE;
packet_direction_t direction;
int encap;
int seconds, useconds, data_chars;
dct2000_file_externals_t *file_externals =
(dct2000_file_externals_t*)wth->priv;
*err = errno = 0;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1) {
return FALSE;
}
if (!read_new_line(wth->random_fh, &offset, &length, linebuff,
sizeof linebuff, err, err_info)) {
return FALSE;
}
if (parse_line(linebuff, length, &seconds, &useconds,
&before_time_offset, &after_time_offset,
&dollar_offset,
&data_chars, &direction, &encap, &is_comment, &is_sprint,
aal_header_chars,
context_name, &context_port,
protocol_name, variant_name, outhdr_name)) {
char timestamp_string[MAX_TIMESTAMP_LEN+1];
write_timestamp_string(timestamp_string, seconds, useconds/100);
process_parsed_line(wth, file_externals,
phdr, buf, seek_off,
linebuff, dollar_offset,
seconds, useconds, timestamp_string,
direction, encap,
context_name, context_port,
protocol_name, variant_name,
outhdr_name, aal_header_chars,
is_comment, data_chars);
*err = errno = 0;
return TRUE;
}
*err = errno;
*err_info = g_strdup_printf("catapult dct2000: seek_read failed to read/parse "
"line at position %" G_GINT64_MODIFIER "d",
seek_off);
return FALSE;
}
static void
catapult_dct2000_close(wtap *wth)
{
dct2000_file_externals_t *file_externals =
(dct2000_file_externals_t*)wth->priv;
g_hash_table_foreach_remove(file_externals->packet_prefix_table,
free_line_prefix_info, NULL);
g_hash_table_destroy(file_externals->packet_prefix_table);
}
gboolean
catapult_dct2000_dump_open(wtap_dumper *wdh, int *err _U_)
{
wdh->subtype_write = catapult_dct2000_dump;
return TRUE;
}
int
catapult_dct2000_dump_can_write_encap(int encap)
{
switch (encap) {
case WTAP_ENCAP_CATAPULT_DCT2000:
return 0;
default:
return WTAP_ERR_UNSUPPORTED_ENCAP;
}
}
static gboolean
catapult_dct2000_dump(wtap_dumper *wdh, const struct wtap_pkthdr *phdr,
const guint8 *pd, int *err)
{
const union wtap_pseudo_header *pseudo_header = &phdr->pseudo_header;
guint32 n;
line_prefix_info_t *prefix = NULL;
gchar time_string[16];
gboolean is_comment;
gboolean is_sprint = FALSE;
dct2000_dump_t *dct2000;
int consecutive_slashes=0;
char *p_c;
dct2000_file_externals_t *file_externals =
(dct2000_file_externals_t*)pseudo_header->dct2000.wth->priv;
dct2000 = (dct2000_dump_t *)wdh->priv;
if (dct2000 == NULL) {
if (!wtap_dump_file_write(wdh, file_externals->firstline,
file_externals->firstline_length, err)) {
return FALSE;
}
if (!wtap_dump_file_write(wdh, "\n", 1, err)) {
return FALSE;
}
if (!wtap_dump_file_write(wdh, file_externals->secondline,
file_externals->secondline_length, err)) {
return FALSE;
}
if (!wtap_dump_file_write(wdh, "\n", 1, err)) {
return FALSE;
}
dct2000 = (dct2000_dump_t *)g_malloc(sizeof(dct2000_dump_t));
wdh->priv = (void *)dct2000;
dct2000->start_time.secs = file_externals->start_secs;
dct2000->start_time.nsecs =
(file_externals->start_usecs * 1000);
dct2000->first_packet_written = TRUE;
}
prefix = (line_prefix_info_t*)g_hash_table_lookup(file_externals->packet_prefix_table,
(const void*)&(pseudo_header->dct2000.seek_off));
if (!wtap_dump_file_write(wdh, prefix->before_time,
strlen(prefix->before_time), err)) {
return FALSE;
}
p_c = prefix->before_time;
while (p_c && (*p_c != '/')) {
p_c++;
}
while (p_c && (*p_c == '/')) {
consecutive_slashes++;
p_c++;
}
is_comment = (consecutive_slashes == 5);
if (phdr->ts.nsecs >= dct2000->start_time.nsecs) {
write_timestamp_string(time_string,
(int)(phdr->ts.secs - dct2000->start_time.secs),
(phdr->ts.nsecs - dct2000->start_time.nsecs) / 100000);
}
else {
write_timestamp_string(time_string,
(int)(phdr->ts.secs - dct2000->start_time.secs-1),
((1000000000 + (phdr->ts.nsecs / 100000)) - (dct2000->start_time.nsecs / 100000)) % 10000);
}
if (!wtap_dump_file_write(wdh, time_string, strlen(time_string), err)) {
return FALSE;
}
if (prefix->after_time == NULL) {
if (!wtap_dump_file_write(wdh, " l ", strlen(" l "), err)) {
return FALSE;
}
}
else {
if (!wtap_dump_file_write(wdh, prefix->after_time,
strlen(prefix->after_time), err)) {
return FALSE;
}
}
for (n=0; pd[n] != '\0'; n++);
n++;
n++;
for (; pd[n] != '\0'; n++);
n++;
if (is_comment) {
is_sprint = strcmp((const char *)pd+n, "sprint") == 0;
}
for (; pd[n] != '\0'; n++);
n++;
for (; pd[n] != '\0'; n++);
n++;
for (; pd[n] != '\0'; n++);
n++;
n += 2;
if (!wtap_dump_file_write(wdh, is_sprint ? " " : "$", 1, err)) {
return FALSE;
}
if (!is_comment) {
for (; n < phdr->len; n++) {
gchar c[2];
c[0] = char_from_hex((guint8)(pd[n] >> 4));
c[1] = char_from_hex((guint8)(pd[n] & 0x0f));
if (!wtap_dump_file_write(wdh, c, 2, err)) {
return FALSE;
}
}
}
else {
for (; n < phdr->len; n++) {
char c[1];
c[0] = pd[n];
if (!wtap_dump_file_write(wdh, c, 1, err)) {
return FALSE;
}
}
}
if (!wtap_dump_file_write(wdh, "\n", 1, err)) {
return FALSE;
}
return TRUE;
}
static gboolean
read_new_line(FILE_T fh, gint64 *offset, gint *length,
gchar *linebuff, size_t linebuffsize, int *err, gchar **err_info)
{
gint64 pos_before = file_tell(fh);
if (file_gets(linebuff, (int)linebuffsize - 1, fh) == NULL) {
*err = file_error(fh, err_info);
return FALSE;
}
*length = (gint)(file_tell(fh) - pos_before);
*offset = *offset + *length;
if (linebuff[*length-1] == '\n') {
linebuff[*length-1] = '\0';
*length = *length - 1;
}
if (linebuff[*length-1] == '\r') {
linebuff[*length-1] = '\0';
*length = *length - 1;
}
return TRUE;
}
static gboolean
parse_line(gchar *linebuff, gint line_length,
gint *seconds, gint *useconds,
long *before_time_offset, long *after_time_offset,
long *data_offset, gint *data_chars,
packet_direction_t *direction,
int *encap, int *is_comment, int *is_sprint,
gchar *aal_header_chars,
gchar *context_name, guint8 *context_portp,
gchar *protocol_name, gchar *variant_name,
gchar *outhdr_name)
{
int n = 0;
int port_digits;
char port_number_string[MAX_PORT_DIGITS+1];
int variant_digits = 0;
int variant = 1;
int protocol_chars = 0;
int outhdr_chars = 0;
char seconds_buff[MAX_SECONDS_CHARS+1];
int seconds_chars;
char subsecond_decimals_buff[MAX_SUBSECOND_DECIMALS+1];
int subsecond_decimals_chars;
int skip_first_byte = FALSE;
gboolean atm_header_present = FALSE;
*is_comment = FALSE;
*is_sprint = FALSE;
for (n=0; (linebuff[n] != '.') && (n < MAX_CONTEXT_NAME) && (n+1 < line_length); n++) {
if (linebuff[n] == '/') {
context_name[n] = '\0';
if (strncmp(linebuff+n, "/////", 5) != 0) {
return FALSE;
}
g_strlcpy(protocol_name, "comment", MAX_PROTOCOL_NAME);
*is_comment = TRUE;
break;
}
if (!isalnum((guchar)linebuff[n]) && (linebuff[n] != '_') && (linebuff[n] != '-')) {
return FALSE;
}
context_name[n] = linebuff[n];
}
if (n == MAX_CONTEXT_NAME || (n+1 >= line_length)) {
return FALSE;
}
variant_name[0] = '\0';
outhdr_name[0] = '\0';
port_number_string[0] = '\0';
if (!(*is_comment)) {
if (linebuff[n] != '.') {
return FALSE;
}
context_name[n] = '\0';
n++;
for (port_digits = 0;
(linebuff[n] != '/') && (port_digits <= MAX_PORT_DIGITS) && (n+1 < line_length);
n++, port_digits++) {
if (!isdigit((guchar)linebuff[n])) {
return FALSE;
}
port_number_string[port_digits] = linebuff[n];
}
if (port_digits > MAX_PORT_DIGITS || (n+1 >= line_length)) {
return FALSE;
}
if (linebuff[n] != '/')
{
return FALSE;
}
port_number_string[port_digits] = '\0';
if (port_digits == 1) {
*context_portp = port_number_string[0] - '0';
}
else {
*context_portp = atoi(port_number_string);
}
n++;
for (protocol_chars = 0;
(linebuff[n] != '/') && (protocol_chars < MAX_PROTOCOL_NAME) && (n < line_length);
n++, protocol_chars++) {
if (!isalnum((guchar)linebuff[n]) && linebuff[n] != '_') {
return FALSE;
}
protocol_name[protocol_chars] = linebuff[n];
}
if (protocol_chars == MAX_PROTOCOL_NAME || n >= line_length) {
return FALSE;
}
protocol_name[protocol_chars] = '\0';
if (linebuff[n] != '/') {
return FALSE;
}
n++;
for (variant_digits = 0;
(isdigit((guchar)linebuff[n])) && (variant_digits <= MAX_VARIANT_DIGITS) && (n+1 < line_length);
n++, variant_digits++) {
if (!isdigit((guchar)linebuff[n])) {
return FALSE;
}
variant_name[variant_digits] = linebuff[n];
}
if (variant_digits > MAX_VARIANT_DIGITS || (n+1 >= line_length)) {
return FALSE;
}
if (variant_digits > 0) {
variant_name[variant_digits] = '\0';
if (variant_digits == 1) {
variant = variant_name[0] - '0';
}
else {
variant = atoi(variant_name);
}
}
else {
variant_name[0] = '1';
variant_name[1] = '\0';
}
outhdr_name[0] = '\0';
if (linebuff[n] == ',') {
n++;
for (outhdr_chars = 0;
(isdigit((guchar)linebuff[n]) || linebuff[n] == ',') &&
(outhdr_chars <= MAX_OUTHDR_NAME) && (n+1 < line_length);
n++, outhdr_chars++) {
if (!isdigit((guchar)linebuff[n]) && (linebuff[n] != ',')) {
return FALSE;
}
outhdr_name[outhdr_chars] = linebuff[n];
}
if (outhdr_chars > MAX_OUTHDR_NAME || (n+1 >= line_length)) {
return FALSE;
}
outhdr_name[outhdr_chars] = '\0';
}
}
if ((strcmp(protocol_name, "ip") == 0) ||
(strcmp(protocol_name, "sctp") == 0) ||
(strcmp(protocol_name, "gre") == 0) ||
(strcmp(protocol_name, "mipv6") == 0) ||
(strcmp(protocol_name, "igmp") == 0)) {
*encap = WTAP_ENCAP_RAW_IP;
}
else
if ((strcmp(protocol_name, "fp") == 0) ||
(strncmp(protocol_name, "fp_r", 4) == 0)) {
if ((variant > 256) && (variant % 256 == 3)) {
*encap = 0;
}
else {
*encap = WTAP_ENCAP_ATM_PDUS_UNTRUNCATED;
atm_header_present = TRUE;
}
}
else if (strcmp(protocol_name, "fpiur_r5") == 0) {
*encap = WTAP_ENCAP_ATM_PDUS_UNTRUNCATED;
atm_header_present = TRUE;
}
else
if (strcmp(protocol_name, "ppp") == 0) {
*encap = WTAP_ENCAP_PPP;
}
else
if (strcmp(protocol_name, "isdn_l3") == 0) {
skip_first_byte = TRUE;
*encap = WTAP_ENCAP_ISDN;
}
else
if (strcmp(protocol_name, "isdn_l2") == 0) {
*encap = WTAP_ENCAP_ISDN;
}
else
if (strcmp(protocol_name, "ethernet") == 0) {
*encap = WTAP_ENCAP_ETHERNET;
}
else
if ((strcmp(protocol_name, "saalnni_sscop") == 0) ||
(strcmp(protocol_name, "saaluni_sscop") == 0)) {
*encap = DCT2000_ENCAP_SSCOP;
}
else
if (strcmp(protocol_name, "frelay_l2") == 0) {
*encap = WTAP_ENCAP_FRELAY;
}
else
if (strcmp(protocol_name, "ss7_mtp2") == 0) {
*encap = DCT2000_ENCAP_MTP2;
}
else
if ((strcmp(protocol_name, "nbap") == 0) ||
(strcmp(protocol_name, "nbap_r4") == 0) ||
(strncmp(protocol_name, "nbap_sscfuni", strlen("nbap_sscfuni")) == 0)) {
*encap = DCT2000_ENCAP_NBAP;
}
else {
*encap = DCT2000_ENCAP_UNHANDLED;
}
if (atm_header_present) {
int header_chars_seen = 0;
for (; (linebuff[n] != '$') && (n+1 < line_length); n++);
n++;
if (n+1 >= line_length) {
return FALSE;
}
for (;
((linebuff[n] >= '0') && (linebuff[n] <= '?') &&
(n < line_length) &&
(header_chars_seen < AAL_HEADER_CHARS));
n++, header_chars_seen++) {
aal_header_chars[header_chars_seen] = linebuff[n];
if (!isdigit((guchar)linebuff[n])) {
aal_header_chars[header_chars_seen] = 'a' + (linebuff[n] - '9') -1;
}
}
if (header_chars_seen != AAL_HEADER_CHARS || n >= line_length) {
return FALSE;
}
}
n++;
if (isdigit(linebuff[n])) {
while ((n+1 < line_length) && linebuff[n] != '/') {
n++;
}
}
while ((n+1 < line_length) && linebuff[n] == '/') {
n++;
}
if ((n+1 < line_length) && linebuff[n] == ' ') {
n++;
}
if (!(*is_comment)) {
if (linebuff[n] == 's') {
*direction = sent;
}
else
if (linebuff[n] == 'r') {
*direction = received;
}
else {
return FALSE;
}
n++;
}
else {
*direction = sent;
}
for (; ((linebuff[n] != 't') || (linebuff[n+1] != 'm')) && (n+1 < line_length); n++);
if (n >= line_length) {
return FALSE;
}
for (; !isdigit((guchar)linebuff[n]) && (n < line_length); n++);
if (n >= line_length) {
return FALSE;
}
*before_time_offset = n;
for (seconds_chars = 0;
(linebuff[n] != '.') &&
(seconds_chars <= MAX_SECONDS_CHARS) &&
(n < line_length);
n++, seconds_chars++) {
if (!isdigit((guchar)linebuff[n])) {
return FALSE;
}
seconds_buff[seconds_chars] = linebuff[n];
}
if (seconds_chars > MAX_SECONDS_CHARS || n >= line_length) {
return FALSE;
}
seconds_buff[seconds_chars] = '\0';
*seconds = atoi(seconds_buff);
if (linebuff[n] != '.') {
return FALSE;
}
n++;
for (subsecond_decimals_chars = 0;
(linebuff[n] != ' ') &&
(subsecond_decimals_chars <= MAX_SUBSECOND_DECIMALS) &&
(n < line_length);
n++, subsecond_decimals_chars++) {
if (!isdigit((guchar)linebuff[n])) {
return FALSE;
}
subsecond_decimals_buff[subsecond_decimals_chars] = linebuff[n];
}
if (subsecond_decimals_chars > MAX_SUBSECOND_DECIMALS || n >= line_length) {
return FALSE;
}
subsecond_decimals_buff[subsecond_decimals_chars] = '\0';
*useconds = atoi(subsecond_decimals_buff) * 100;
if (linebuff[n] != ' ') {
return FALSE;
}
*after_time_offset = n++;
if (*is_comment) {
if (strncmp(linebuff+n, "l $", 3) != 0) {
*is_sprint = TRUE;
g_strlcpy(protocol_name, "sprint", MAX_PROTOCOL_NAME);
}
}
if (!(*is_sprint)) {
for (; (linebuff[n] != '$') && (linebuff[n] != '\'') && (n+1 < line_length); n++);
if ((linebuff[n] == '\'') || (n+1 >= line_length)) {
return FALSE;
}
n++;
}
*data_offset = n;
*data_chars = line_length - n;
if (skip_first_byte) {
*data_offset += 2;
*data_chars -= 2;
}
return TRUE;
}
static void
process_parsed_line(wtap *wth, dct2000_file_externals_t *file_externals,
struct wtap_pkthdr *phdr,
Buffer *buf, gint64 file_offset,
char *linebuff, long dollar_offset,
int seconds, int useconds, gchar *timestamp_string,
packet_direction_t direction, int encap,
gchar *context_name, guint8 context_port,
gchar *protocol_name, gchar *variant_name,
gchar *outhdr_name, gchar *aal_header_chars,
gboolean is_comment, int data_chars)
{
int n;
int stub_offset = 0;
gsize length;
guint8 *frame_buffer;
phdr->presence_flags = WTAP_HAS_TS;
phdr->pkt_encap = WTAP_ENCAP_CATAPULT_DCT2000;
phdr->ts.secs = file_externals->start_secs + seconds;
if ((file_externals->start_usecs + useconds) >= 1000000) {
phdr->ts.secs++;
}
phdr->ts.nsecs =
((file_externals->start_usecs + useconds) % 1000000) *1000;
buffer_assure_space(buf,
strlen(context_name)+1 +
1 +
strlen(timestamp_string)+1 +
strlen(variant_name)+1 +
strlen(outhdr_name)+1 +
strlen(protocol_name)+1 +
1 +
1 +
(is_comment ? data_chars : (data_chars/2)));
frame_buffer = buffer_start_ptr(buf);
length = g_strlcpy((char*)frame_buffer, context_name, MAX_CONTEXT_NAME+1);
stub_offset += (int)(length + 1);
frame_buffer[stub_offset] = context_port;
stub_offset++;
length = g_strlcpy((char*)&frame_buffer[stub_offset], timestamp_string, MAX_TIMESTAMP_LEN+1);
stub_offset += (int)(length + 1);
length = g_strlcpy((char*)&frame_buffer[stub_offset], protocol_name, MAX_PROTOCOL_NAME+1);
stub_offset += (int)(length + 1);
length = g_strlcpy((gchar*)&frame_buffer[stub_offset], variant_name, MAX_VARIANT_DIGITS+1);
stub_offset += (int)(length + 1);
length = g_strlcpy((char*)&frame_buffer[stub_offset], outhdr_name, MAX_OUTHDR_NAME+1);
stub_offset += (int)(length + 1);
frame_buffer[stub_offset] = direction;
stub_offset++;
frame_buffer[stub_offset] = (guint8)encap;
stub_offset++;
phdr->len = stub_offset + (is_comment ? data_chars : (data_chars/2));
phdr->caplen = stub_offset + (is_comment ? data_chars : (data_chars/2));
if (!is_comment) {
for (n=0; n < data_chars; n+=2) {
frame_buffer[stub_offset + n/2] =
hex_byte_from_chars(linebuff+dollar_offset+n);
}
}
else {
for (n=0; n < data_chars; n++) {
frame_buffer[stub_offset + n] = linebuff[dollar_offset+n];
}
}
phdr->pseudo_header.dct2000.seek_off = file_offset;
phdr->pseudo_header.dct2000.wth = wth;
switch (encap) {
case WTAP_ENCAP_ATM_PDUS_UNTRUNCATED:
set_aal_info(&phdr->pseudo_header, direction, aal_header_chars);
break;
case WTAP_ENCAP_ISDN:
set_isdn_info(&phdr->pseudo_header, direction);
break;
case WTAP_ENCAP_PPP:
set_ppp_info(&phdr->pseudo_header, direction);
break;
default:
break;
}
}
static void
set_aal_info(union wtap_pseudo_header *pseudo_header,
packet_direction_t direction,
gchar *aal_header_chars)
{
pseudo_header->dct2000.inner_pseudo_header.atm.flags = 0x00;
pseudo_header->dct2000.inner_pseudo_header.atm.channel = (direction == received);
pseudo_header->dct2000.inner_pseudo_header.atm.aal = AAL_2;
pseudo_header->dct2000.inner_pseudo_header.atm.type = TRAF_UMTS_FP;
pseudo_header->dct2000.inner_pseudo_header.atm.subtype = TRAF_ST_UNKNOWN;
pseudo_header->dct2000.inner_pseudo_header.atm.vpi =
hex_byte_from_chars(aal_header_chars+1);
pseudo_header->dct2000.inner_pseudo_header.atm.vci =
((hex_from_char(aal_header_chars[3]) << 12) |
(hex_from_char(aal_header_chars[4]) << 8) |
(hex_from_char(aal_header_chars[5]) << 4) |
hex_from_char(aal_header_chars[6]));
pseudo_header->dct2000.inner_pseudo_header.atm.cells = 0;
if (isalnum((guchar)aal_header_chars[11])) {
pseudo_header->dct2000.inner_pseudo_header.atm.aal2_cid =
hex_byte_from_chars(aal_header_chars+10);
}
else {
pseudo_header->dct2000.inner_pseudo_header.atm.aal2_cid =
(int)aal_header_chars[11] - '0';
}
}
static void
set_isdn_info(union wtap_pseudo_header *pseudo_header,
packet_direction_t direction)
{
pseudo_header->dct2000.inner_pseudo_header.isdn.uton = (direction == received);
pseudo_header->dct2000.inner_pseudo_header.isdn.channel = 0;
}
static void
set_ppp_info(union wtap_pseudo_header *pseudo_header,
packet_direction_t direction)
{
pseudo_header->dct2000.inner_pseudo_header.p2p.sent = (direction == sent);
}
static guint8
hex_from_char(gchar c)
{
if ((c >= '0') && (c <= '9')) {
return c - '0';
}
if ((c >= 'a') && (c <= 'f')) {
return 0x0a + (c - 'a');
}
return 0xff;
}
static void prepare_hex_byte_from_chars_table(void)
{
guchar hex_char_array[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
'a', 'b', 'c', 'd', 'e', 'f' };
gint i, j;
for (i=0; i < 16; i++) {
for (j=0; j < 16; j++) {
s_tableValues[hex_char_array[i]][hex_char_array[j]] = i*16 + j;
}
}
}
static guint8 hex_byte_from_chars(gchar *c)
{
return s_tableValues[(unsigned char)c[0]][(unsigned char)c[1]];
}
static gchar
char_from_hex(guint8 hex)
{
static const char hex_lookup[16] =
{ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
if (hex > 15) {
return '?';
}
return hex_lookup[hex];
}
static gint
packet_offset_equal(gconstpointer v, gconstpointer v2)
{
return (*(const gint64*)v == *(const gint64*)v2);
}
static guint
packet_offset_hash_func(gconstpointer v)
{
return (guint)(*(const gint64*)v);
}
static gboolean
get_file_time_stamp(gchar *linebuff, time_t *secs, guint32 *usecs)
{
int n;
struct tm tm;
#define MAX_MONTH_LETTERS 9
char month[MAX_MONTH_LETTERS+1];
int day, year, hour, minute, second;
int scan_found;
if (strlen(linebuff) > MAX_TIMESTAMP_LINE_LENGTH) {
return FALSE;
}
for (n=0; (linebuff[n] != ' ') && (n < MAX_MONTH_LETTERS); n++) {
month[n] = linebuff[n];
}
month[n] = '\0';
if (strcmp(month, "January" ) == 0) tm.tm_mon = 0;
else if (strcmp(month, "February" ) == 0) tm.tm_mon = 1;
else if (strcmp(month, "March" ) == 0) tm.tm_mon = 2;
else if (strcmp(month, "April" ) == 0) tm.tm_mon = 3;
else if (strcmp(month, "May" ) == 0) tm.tm_mon = 4;
else if (strcmp(month, "June" ) == 0) tm.tm_mon = 5;
else if (strcmp(month, "July" ) == 0) tm.tm_mon = 6;
else if (strcmp(month, "August" ) == 0) tm.tm_mon = 7;
else if (strcmp(month, "September") == 0) tm.tm_mon = 8;
else if (strcmp(month, "October" ) == 0) tm.tm_mon = 9;
else if (strcmp(month, "November" ) == 0) tm.tm_mon = 10;
else if (strcmp(month, "December" ) == 0) tm.tm_mon = 11;
else {
return FALSE;
}
n++;
scan_found = sscanf(linebuff+n, "%2d, %4d %2d:%2d:%2d.%4u",
&day, &year, &hour, &minute, &second, usecs);
if (scan_found != 6) {
return FALSE;
}
tm.tm_year = year - 1900;
tm.tm_mday = day;
tm.tm_hour = hour;
tm.tm_min = minute;
tm.tm_sec = second;
tm.tm_isdst = -1;
*secs = mktime(&tm);
*usecs = *usecs * 100;
return TRUE;
}
static gboolean
free_line_prefix_info(gpointer key, gpointer value,
gpointer user_data _U_)
{
line_prefix_info_t *info = (line_prefix_info_t*)value;
g_free(key);
g_free(info->before_time);
if (info->after_time) {
g_free(info->after_time);
}
g_free(info);
return TRUE;
}
