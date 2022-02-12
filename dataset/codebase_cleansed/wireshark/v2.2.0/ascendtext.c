static gint64 ascend_seek(wtap *wth, int *err, gchar **err_info)
{
int byte;
gint64 date_off = -1, cur_off, packet_off;
size_t string_level[ASCEND_MAGIC_STRINGS];
guint string_i = 0, type = 0;
static const gchar ascend_date[] = ASCEND_DATE;
size_t ascend_date_len = sizeof ascend_date - 1;
size_t ascend_date_string_level;
guint excessive_read_count = 262144;
memset(&string_level, 0, sizeof(string_level));
ascend_date_string_level = 0;
while (((byte = file_getc(wth->fh)) != EOF)) {
excessive_read_count--;
if (!excessive_read_count) {
*err = 0;
return -1;
}
for (string_i = 0; string_i < ASCEND_MAGIC_STRINGS; string_i++) {
const gchar *strptr = ascend_magic[string_i].strptr;
size_t len = ascend_magic[string_i].strlength;
if (byte == *(strptr + string_level[string_i])) {
string_level[string_i]++;
if (string_level[string_i] >= len) {
cur_off = file_tell(wth->fh);
if (cur_off == -1) {
*err = file_error(wth->fh, err_info);
return -1;
}
if (date_off == -1) {
packet_off = cur_off - len;
} else {
packet_off = date_off;
}
type = ascend_magic[string_i].type;
goto found;
}
} else {
string_level[string_i] = 0;
}
}
if (byte == *(ascend_date + ascend_date_string_level)) {
ascend_date_string_level++;
if (ascend_date_string_level >= ascend_date_len) {
cur_off = file_tell(wth->fh);
if (cur_off == -1) {
*err = file_error(wth->fh, err_info);
return -1;
}
date_off = cur_off - ascend_date_len;
ascend_date_string_level = 0;
}
} else {
ascend_date_string_level = 0;
}
}
*err = file_error(wth->fh, err_info);
return -1;
found:
if (file_seek(wth->fh, packet_off, SEEK_SET, err) == -1)
return -1;
wth->phdr.pseudo_header.ascend.type = type;
return packet_off;
}
wtap_open_return_val ascend_open(wtap *wth, int *err, gchar **err_info)
{
gint64 offset;
guint8 buf[ASCEND_MAX_PKT_LEN];
ascend_state_t parser_state;
ws_statb64 statbuf;
ascend_t *ascend;
wth->priv = NULL;
offset = ascend_seek(wth, err, err_info);
if (offset == -1) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return WTAP_OPEN_ERROR;
return WTAP_OPEN_NOT_MINE;
}
if (run_ascend_parser(wth->fh, &wth->phdr, buf, &parser_state, err,
err_info) != 0 && *err != 0) {
return WTAP_OPEN_ERROR;
}
if (parser_state.caplen == 0) {
return WTAP_OPEN_NOT_MINE;
}
wth->file_type_subtype = WTAP_FILE_TYPE_SUBTYPE_ASCEND;
switch(wth->phdr.pseudo_header.ascend.type) {
case ASCEND_PFX_ISDN_X:
case ASCEND_PFX_ISDN_R:
wth->file_encap = WTAP_ENCAP_ISDN;
break;
case ASCEND_PFX_ETHER:
wth->file_encap = WTAP_ENCAP_ETHERNET;
break;
default:
wth->file_encap = WTAP_ENCAP_ASCEND;
}
wth->snapshot_length = ASCEND_MAX_PKT_LEN;
wth->subtype_read = ascend_read;
wth->subtype_seek_read = ascend_seek_read;
ascend = (ascend_t *)g_malloc(sizeof(ascend_t));
wth->priv = (void *)ascend;
ascend->next_packet_seek_start = offset;
if (wtap_fstat(wth, &statbuf, err) == -1) {
return WTAP_OPEN_ERROR;
}
ascend->inittime = statbuf.st_ctime;
ascend->adjusted = FALSE;
wth->file_tsprec = WTAP_TSPREC_USEC;
return WTAP_OPEN_MINE;
}
static gboolean
parse_ascend(ascend_t *ascend, FILE_T fh, struct wtap_pkthdr *phdr, Buffer *buf,
guint length, int *err, gchar **err_info)
{
ascend_state_t parser_state;
int retval;
ws_buffer_assure_space(buf, length);
retval = run_ascend_parser(fh, phdr, ws_buffer_start_ptr(buf), &parser_state,
err, err_info);
if (parser_state.first_hexbyte) {
ascend->next_packet_seek_start = parser_state.first_hexbyte;
} else {
ascend->next_packet_seek_start = file_tell(fh);
retval = 0;
}
if (parser_state.caplen) {
if (! ascend->adjusted) {
ascend->adjusted = TRUE;
if (parser_state.saw_timestamp) {
ascend->inittime = parser_state.timestamp;
}
if (ascend->inittime > parser_state.secs)
ascend->inittime -= parser_state.secs;
}
phdr->presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
phdr->ts.secs = parser_state.secs + ascend->inittime;
phdr->ts.nsecs = parser_state.usecs * 1000;
phdr->caplen = parser_state.caplen;
phdr->len = parser_state.wirelen;
switch(phdr->pseudo_header.ascend.type) {
case ASCEND_PFX_ISDN_X:
phdr->pseudo_header.isdn.uton = TRUE;
phdr->pseudo_header.isdn.channel = 0;
break;
case ASCEND_PFX_ISDN_R:
phdr->pseudo_header.isdn.uton = FALSE;
phdr->pseudo_header.isdn.channel = 0;
break;
case ASCEND_PFX_ETHER:
phdr->pseudo_header.eth.fcs_len = 0;
break;
}
return TRUE;
}
if (retval) {
if (*err == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup((parser_state.ascend_parse_error != NULL) ? parser_state.ascend_parse_error : "parse error");
}
} else {
if (*err == 0) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup("no data returned by parse");
}
}
return FALSE;
}
static gboolean ascend_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
ascend_t *ascend = (ascend_t *)wth->priv;
gint64 offset;
if (file_seek(wth->fh, ascend->next_packet_seek_start,
SEEK_SET, err) == -1)
return FALSE;
offset = ascend_seek(wth, err, err_info);
if (offset == -1)
return FALSE;
if (!parse_ascend(ascend, wth->fh, &wth->phdr, wth->frame_buffer,
wth->snapshot_length, err, err_info))
return FALSE;
*data_offset = offset;
return TRUE;
}
static gboolean ascend_seek_read(wtap *wth, gint64 seek_off,
struct wtap_pkthdr *phdr, Buffer *buf,
int *err, gchar **err_info)
{
ascend_t *ascend = (ascend_t *)wth->priv;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (!parse_ascend(ascend, wth->random_fh, phdr, buf,
wth->snapshot_length, err, err_info))
return FALSE;
return TRUE;
}
