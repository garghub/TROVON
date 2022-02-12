void
failure_alert_box(const char *msg_format, va_list ap)
{
vsimple_error_message_box(msg_format, ap);
}
void
open_failure_alert_box(const char *filename, int err, gboolean for_writing)
{
gchar *display_basename;
display_basename = g_filename_display_basename(filename);
simple_message_box(ESD_TYPE_ERROR, NULL, NULL,
file_open_error_message(err, for_writing),
display_basename);
g_free(display_basename);
}
void
read_failure_alert_box(const char *filename, int err)
{
gchar *display_basename;
display_basename = g_filename_display_basename(filename);
simple_message_box(ESD_TYPE_ERROR, NULL, NULL,
"An error occurred while reading from the file \"%s\": %s.",
display_basename, g_strerror(err));
g_free(display_basename);
}
void
write_failure_alert_box(const char *filename, int err)
{
gchar *display_basename;
display_basename = g_filename_display_basename(filename);
if (err < 0) {
switch (err) {
case WTAP_ERR_SHORT_WRITE:
simple_message_box(ESD_TYPE_ERROR, NULL, NULL,
"A full write couldn't be done to the file \"%s\".",
display_basename);
break;
default:
simple_message_box(ESD_TYPE_ERROR, NULL, NULL,
"An error occurred while writing to the file \"%s\": %s.",
display_basename, wtap_strerror(err));
break;
}
} else {
simple_message_box(ESD_TYPE_ERROR, NULL, NULL,
file_write_error_message(err), display_basename);
}
g_free(display_basename);
}
