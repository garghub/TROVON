gboolean
eo_save_entry(const gchar *save_as_filename, export_object_entry_t *entry, gboolean show_err)
{
int to_fd;
gint64 bytes_left;
int bytes_to_write;
ssize_t bytes_written;
guint8 *ptr;
int err;
to_fd = ws_open(save_as_filename, O_WRONLY | O_CREAT | O_EXCL |
O_BINARY, 0644);
if(to_fd == -1) {
if (show_err)
open_failure_alert_box(save_as_filename, errno, TRUE);
return FALSE;
}
ptr = entry->payload_data;
bytes_left = entry->payload_len;
while (bytes_left != 0) {
if (bytes_left > 0x40000000)
bytes_to_write = 0x40000000;
else
bytes_to_write = (int)bytes_left;
bytes_written = ws_write(to_fd, ptr, bytes_to_write);
if(bytes_written <= 0) {
if (bytes_written < 0)
err = errno;
else
err = WTAP_ERR_SHORT_WRITE;
if (show_err)
write_failure_alert_box(save_as_filename, err);
ws_close(to_fd);
return FALSE;
}
bytes_left -= bytes_written;
ptr += bytes_written;
}
if (ws_close(to_fd) < 0) {
if (show_err)
write_failure_alert_box(save_as_filename, errno);
return FALSE;
}
return TRUE;
}
static GString *eo_rename(GString *gstr, int dupn)
{
GString *gstr_tmp;
gchar *tmp_ptr;
GString *ext_str;
gstr_tmp = g_string_new("(");
g_string_append_printf (gstr_tmp, "%d)", dupn);
if ( (tmp_ptr = strrchr(gstr->str, '.')) != NULL ) {
ext_str = g_string_new(tmp_ptr);
gstr = g_string_truncate(gstr, gstr->len - ext_str->len);
if ( gstr->len >= (MAXFILELEN - (strlen(gstr_tmp->str) + ext_str->len)) )
gstr = g_string_truncate(gstr, MAXFILELEN - (strlen(gstr_tmp->str) + ext_str->len));
gstr = g_string_append(gstr, gstr_tmp->str);
gstr = g_string_append(gstr, ext_str->str);
g_string_free(ext_str, TRUE);
}
else {
if ( gstr->len >= (MAXFILELEN - strlen(gstr_tmp->str)) )
gstr = g_string_truncate(gstr, MAXFILELEN - strlen(gstr_tmp->str));
gstr = g_string_append(gstr, gstr_tmp->str);
}
g_string_free(gstr_tmp, TRUE);
return gstr;
}
GString *
eo_massage_str(const gchar *in_str, gsize maxlen, int dupn)
{
gchar *tmp_ptr;
const gchar *reject = "<>:\"/\\|?*"
"\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a"
"\x0b\x0c\x0d\x0e\x0f\x10\x11\x12\x13\x14"
"\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f";
GString *out_str;
GString *ext_str;
out_str = g_string_new("");
while ( (tmp_ptr = strpbrk(in_str, reject)) != NULL ) {
out_str = g_string_append_len(out_str, in_str, tmp_ptr - in_str);
out_str = g_string_append_c(out_str, '%');
out_str = g_string_append_c(out_str, HEXTOASCII(HINIBBLE(*tmp_ptr)));
out_str = g_string_append_c(out_str, HEXTOASCII(LONIBBLE(*tmp_ptr)));
in_str = tmp_ptr + 1;
}
out_str = g_string_append(out_str, in_str);
if ( out_str->len > maxlen ) {
if ( (tmp_ptr = strrchr(out_str->str, '.')) != NULL ) {
ext_str = g_string_new(tmp_ptr);
out_str = g_string_truncate(out_str, maxlen - ext_str->len);
out_str = g_string_append(out_str, ext_str->str);
g_string_free(ext_str, TRUE);
}
else
out_str = g_string_truncate(out_str, maxlen);
}
if ( dupn != 0 )
out_str = eo_rename(out_str, dupn);
return out_str;
}
const char *
ct2ext(const char *content_type)
{
return content_type;
}
