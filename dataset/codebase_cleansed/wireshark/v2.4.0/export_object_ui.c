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
