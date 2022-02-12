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
if (byte != EOF || file_eof(wth->fh)) {
*err = 0;
} else {
*err = file_error(wth->fh, err_info);
}
return -1;
found:
if (file_seek(wth->fh, packet_off, SEEK_SET, err) == -1)
return -1;
wth->pseudo_header.ascend.type = type;
return packet_off;
}
int ascend_open(wtap *wth, int *err, gchar **err_info)
{
gint64 offset;
ws_statb64 statbuf;
guint8 buf[ASCEND_MAX_PKT_LEN];
ascend_pkthdr header;
gint64 dummy_seek_start;
ascend_t *ascend;
wth->priv = NULL;
offset = ascend_seek(wth, err, err_info);
if (offset == -1) {
if (*err == 0)
return 0;
else
return -1;
}
init_parse_ascend();
if (parse_ascend(wth->fh, buf, &wth->pseudo_header.ascend, &header,
&dummy_seek_start) != PARSED_RECORD) {
return 0;
}
wth->file_type = WTAP_FILE_ASCEND;
switch(wth->pseudo_header.ascend.type) {
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
g_free(ascend);
return -1;
}
ascend->inittime = statbuf.st_ctime;
ascend->adjusted = 0;
wth->tsprecision = WTAP_FILE_TSPREC_USEC;
init_parse_ascend();
return 1;
}
static void config_pseudo_header(union wtap_pseudo_header *pseudo_head)
{
switch(pseudo_head->ascend.type) {
case ASCEND_PFX_ISDN_X:
pseudo_head->isdn.uton = TRUE;
pseudo_head->isdn.channel = 0;
break;
case ASCEND_PFX_ISDN_R:
pseudo_head->isdn.uton = FALSE;
pseudo_head->isdn.channel = 0;
break;
case ASCEND_PFX_ETHER:
pseudo_head->eth.fcs_len = 0;
break;
}
}
static gboolean ascend_read(wtap *wth, int *err, gchar **err_info,
gint64 *data_offset)
{
ascend_t *ascend = (ascend_t *)wth->priv;
gint64 offset;
guint8 *buf = buffer_start_ptr(wth->frame_buffer);
ascend_pkthdr header;
if (file_seek(wth->fh, ascend->next_packet_seek_start,
SEEK_SET, err) == -1)
return FALSE;
offset = ascend_seek(wth, err, err_info);
if (offset == -1)
return FALSE;
if (parse_ascend(wth->fh, buf, &wth->pseudo_header.ascend, &header,
&(ascend->next_packet_seek_start)) != PARSED_RECORD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup((ascend_parse_error != NULL) ? ascend_parse_error : "parse error");
return FALSE;
}
buffer_assure_space(wth->frame_buffer, wth->snapshot_length);
config_pseudo_header(&wth->pseudo_header);
if (! ascend->adjusted) {
ascend->adjusted = 1;
if (header.start_time != 0) {
ascend->inittime = header.start_time;
}
if (ascend->inittime > header.secs)
ascend->inittime -= header.secs;
}
wth->phdr.presence_flags = WTAP_HAS_TS|WTAP_HAS_CAP_LEN;
wth->phdr.ts.secs = header.secs + ascend->inittime;
wth->phdr.ts.nsecs = header.usecs * 1000;
wth->phdr.caplen = header.caplen;
wth->phdr.len = header.len;
*data_offset = offset;
return TRUE;
}
static gboolean ascend_seek_read(wtap *wth, gint64 seek_off,
union wtap_pseudo_header *pseudo_head, guint8 *pd, int len _U_,
int *err, gchar **err_info)
{
ascend_t *ascend = (ascend_t *)wth->priv;
if (file_seek(wth->random_fh, seek_off, SEEK_SET, err) == -1)
return FALSE;
if (parse_ascend(wth->random_fh, pd, &pseudo_head->ascend, NULL,
&(ascend->next_packet_seek_start)) != PARSED_RECORD) {
*err = WTAP_ERR_BAD_FILE;
*err_info = g_strdup((ascend_parse_error != NULL) ? ascend_parse_error : "parse error");
return FALSE;
}
config_pseudo_header(pseudo_head);
return TRUE;
}
