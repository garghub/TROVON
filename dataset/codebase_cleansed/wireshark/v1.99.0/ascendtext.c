static gint64 ascend_seek(wtap *wth, int *err, gchar **err_info)
{
int byte;
gint64 date_off = -1, cur_off, packet_off;
size_t string_level[ASCEND_MAGIC_STRINGS];
guint string_i = 0, type = 0;
guint excessive_read_count = 262144;
memset(&string_level, 0, sizeof(string_level));
while (((byte = file_getc(wth->fh)) != EOF)) {
excessive_read_count--;
if (!excessive_read_count) {
*err = 0;
return -1;
}
for (string_i = 0; string_i < ASCEND_MAGIC_STRINGS; string_i++) {
const gchar *strptr = ascend_magic[string_i].strptr;
size_t len = strlen(strptr);
if (byte == *(strptr + string_level[string_i])) {
string_level[string_i]++;
if (string_level[string_i] >= len) {
cur_off = file_tell(wth->fh);
if (cur_off == -1) {
*err = file_error(wth->fh, err_info);
return -1;
}
if (strcmp(strptr, ASCEND_DATE) == 0) {
date_off = cur_off - len;
} else {
if (date_off == -1) {
packet_off = cur_off - len;
} else {
packet_off = date_off;
}
type = ascend_magic[string_i].type;
goto found;
}
}
} else {
string_level[string_i] = 0;
}
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
int ascend_open(wtap *wth, int *err, gchar **err_info)
{
gint64 offset;
ws_statb64 statbuf;
ascend_t *ascend;
wth->priv = NULL;
offset = ascend_seek(wth, err, err_info);
if (offset == -1) {
if (*err != 0 && *err != WTAP_ERR_SHORT_READ)
return -1;
return 0;
}
init_parse_ascend();
if (!check_ascend(wth->fh, &wth->phdr)) {
return 0;
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
return -1;
}
ascend->inittime = statbuf.st_ctime;
ascend->adjusted = FALSE;
wth->file_tsprec = WTAP_TSPREC_USEC;
init_parse_ascend();
return 1;
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
if (parse_ascend(ascend, wth->fh, &wth->phdr, wth->frame_buffer,
wth->snapshot_length) != PARSED_RECORD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup((ascend_parse_error != NULL) ? ascend_parse_error : "parse error");
return FALSE;
}
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
if (parse_ascend(ascend, wth->random_fh, phdr, buf,
wth->snapshot_length) != PARSED_RECORD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup((ascend_parse_error != NULL) ? ascend_parse_error : "parse error");
return FALSE;
}
return TRUE;
}
