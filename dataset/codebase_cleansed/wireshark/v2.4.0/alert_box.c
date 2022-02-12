void
failure_alert_box(const char *msg_format, ...)
{
va_list ap;
va_start(ap, msg_format);
vsimple_error_message_box(msg_format, ap);
va_end(ap);
}
void
vfailure_alert_box(const char *msg_format, va_list ap)
{
vsimple_error_message_box(msg_format, ap);
}
void
vwarning_alert_box(const char *msg_format, va_list ap)
{
vsimple_warning_message_box(msg_format, ap);
}
void
cfile_open_failure_alert_box(const char *filename, int err, gchar *err_info)
{
gchar *display_basename;
if (err < 0) {
display_basename = g_filename_display_basename(filename);
switch (err) {
case WTAP_ERR_NOT_REGULAR_FILE:
simple_error_message_box(
"The file \"%s\" is a \"special file\" or socket or other non-regular file.",
display_basename);
break;
case WTAP_ERR_RANDOM_OPEN_PIPE:
simple_error_message_box(
"The file \"%s\" is a pipe or FIFO; Wireshark can't read pipe or FIFO files.\n"
"To capture from a pipe or FIFO use wireshark -i -",
display_basename);
break;
case WTAP_ERR_FILE_UNKNOWN_FORMAT:
simple_error_message_box(
"The file \"%s\" isn't a capture file in a format Wireshark understands.",
display_basename);
break;
case WTAP_ERR_UNSUPPORTED:
simple_error_message_box(
"The file \"%s\" contains record data that Wireshark doesn't support.\n"
"(%s)",
display_basename,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED:
simple_error_message_box(
"The file \"%s\" is a capture for a network type that Wireshark doesn't support.",
display_basename);
break;
case WTAP_ERR_BAD_FILE:
simple_error_message_box(
"The file \"%s\" appears to be damaged or corrupt.\n"
"(%s)",
display_basename,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_CANT_OPEN:
simple_error_message_box(
"The file \"%s\" could not be opened for some unknown reason.",
display_basename);
break;
case WTAP_ERR_SHORT_READ:
simple_error_message_box(
"The file \"%s\" appears to have been cut short"
" in the middle of a packet or other data.",
display_basename);
break;
case WTAP_ERR_DECOMPRESS:
simple_error_message_box(
"The file \"%s\" cannot be decompressed; it may be damaged or corrupt.\n"
"(%s)", display_basename,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
simple_error_message_box(
"The file \"%s\" could not be opened: %s.",
display_basename,
wtap_strerror(err));
break;
}
g_free(display_basename);
} else {
open_failure_alert_box(filename, err, FALSE);
}
}
void
cfile_dump_open_failure_alert_box(const char *filename, int err,
int file_type_subtype)
{
gchar *display_basename;
if (err < 0) {
display_basename = g_filename_display_basename(filename);
switch (err) {
case WTAP_ERR_NOT_REGULAR_FILE:
simple_error_message_box(
"The file \"%s\" is a \"special file\" or socket or other non-regular file.",
display_basename);
break;
case WTAP_ERR_CANT_WRITE_TO_PIPE:
simple_error_message_box(
"The file \"%s\" is a pipe, and %s capture files can't be "
"written to a pipe.",
display_basename, wtap_file_type_subtype_string(file_type_subtype));
break;
case WTAP_ERR_UNWRITABLE_FILE_TYPE:
simple_error_message_box(
"Wireshark doesn't support writing capture files in that format.");
break;
case WTAP_ERR_UNWRITABLE_ENCAP:
simple_error_message_box("Wireshark can't save this capture in that format.");
break;
case WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED:
simple_error_message_box(
"Wireshark can't save this capture in that format.");
break;
case WTAP_ERR_CANT_OPEN:
simple_error_message_box(
"The file \"%s\" could not be created for some unknown reason.",
display_basename);
break;
case WTAP_ERR_SHORT_WRITE:
simple_error_message_box(
"A full header couldn't be written to the file \"%s\".",
display_basename);
break;
case WTAP_ERR_COMPRESSION_NOT_SUPPORTED:
simple_error_message_box(
"This file type cannot be written as a compressed file.");
break;
default:
simple_error_message_box(
"The file \"%s\" could not be created: %s.",
display_basename,
wtap_strerror(err));
break;
}
g_free(display_basename);
} else {
open_failure_alert_box(filename, err, TRUE);
}
}
void
cfile_read_failure_alert_box(const char *filename, int err, gchar *err_info)
{
gchar *display_name;
if (filename == NULL)
display_name = g_strdup("capture file");
else {
gchar *display_basename;
display_basename = g_filename_display_basename(filename);
display_name = g_strdup_printf("capture file \"%s\"", display_basename);
g_free(display_basename);
}
switch (err) {
case WTAP_ERR_UNSUPPORTED:
simple_error_message_box(
"The %s contains record data that Wireshark doesn't support.\n"
"(%s)",
display_name,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_SHORT_READ:
simple_error_message_box(
"The %s appears to have been cut short in the middle of a packet.",
display_name);
break;
case WTAP_ERR_BAD_FILE:
simple_error_message_box(
"The %s appears to be damaged or corrupt.\n"
"(%s)",
display_name,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_DECOMPRESS:
simple_error_message_box(
"The %s cannot be decompressed; it may be damaged or corrupt.\n"
"(%s)",
display_name,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
simple_error_message_box(
"An error occurred while reading the %s: %s.",
display_name,
wtap_strerror(err));
break;
}
g_free(display_name);
}
void
cfile_write_failure_alert_box(const char *in_filename, const char *out_filename,
int err, gchar *err_info, guint32 framenum,
int file_type_subtype)
{
char *in_file_string;
char *out_display_basename;
if (err < 0) {
if (in_filename == NULL)
in_file_string = g_strdup("");
else
in_file_string = g_strdup_printf(" of file \"%s\"", in_filename);
switch (err) {
case WTAP_ERR_UNWRITABLE_ENCAP:
simple_error_message_box(
"Frame %u%s has a network type that can't be saved in a \"%s\" file.",
framenum, in_file_string,
wtap_file_type_subtype_string(file_type_subtype));
break;
case WTAP_ERR_PACKET_TOO_LARGE:
simple_error_message_box(
"Frame %u%s is larger than Wireshark supports in a \"%s\" file.",
framenum, in_file_string,
wtap_file_type_subtype_string(file_type_subtype));
break;
case WTAP_ERR_UNWRITABLE_REC_TYPE:
simple_error_message_box(
"Record %u%s has a record type that can't be saved in a \"%s\" file.",
framenum, in_file_string,
wtap_file_type_subtype_string(file_type_subtype));
break;
case WTAP_ERR_UNWRITABLE_REC_DATA:
simple_error_message_box(
"Record %u%s has data that can't be saved in a \"%s\" file.\n"
"(%s)",
framenum, in_file_string,
wtap_file_type_subtype_string(file_type_subtype),
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_SHORT_WRITE:
out_display_basename = g_filename_display_basename(out_filename);
simple_error_message_box(
"A full write couldn't be done to the file \"%s\".",
out_display_basename);
g_free(out_display_basename);
break;
default:
out_display_basename = g_filename_display_basename(out_filename);
simple_error_message_box(
"An error occurred while writing to the file \"%s\": %s.",
out_display_basename, wtap_strerror(err));
g_free(out_display_basename);
break;
}
g_free(in_file_string);
} else {
write_failure_alert_box(out_filename, err);
}
}
void
cfile_close_failure_alert_box(const char *filename, int err)
{
gchar *display_basename;
if (err < 0) {
display_basename = g_filename_display_basename(filename);
switch (err) {
case WTAP_ERR_CANT_CLOSE:
simple_error_message_box(
"The file \"%s\" couldn't be closed for some unknown reason.",
display_basename);
break;
case WTAP_ERR_SHORT_WRITE:
simple_error_message_box(
"A full write couldn't be done to the file \"%s\".",
display_basename);
break;
default:
simple_error_message_box(
"An error occurred while closing the file \"%s\": %s.",
display_basename, wtap_strerror(err));
break;
}
g_free(display_basename);
} else {
write_failure_alert_box(filename, err);
}
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
