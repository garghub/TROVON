static char *
input_file_description(const char *fname)
{
char *fstring;
if (strcmp(fname, "-") == 0) {
fstring = g_strdup("standard input");
} else {
fstring = g_strdup_printf("file \"%s\"", fname);
}
return fstring;
}
static char *
output_file_description(const char *fname)
{
char *fstring;
if (strcmp(fname, "-") == 0) {
fstring = g_strdup("standard output");
} else {
fstring = g_strdup_printf("file \"%s\"", fname);
}
return fstring;
}
void
cfile_open_failure_message(const char *progname, const char *filename,
int err, gchar *err_info)
{
char *file_description;
file_description = input_file_description(filename);
if (err < 0) {
switch (err) {
case WTAP_ERR_NOT_REGULAR_FILE:
cmdarg_err("The %s is a \"special file\" or socket or other non-regular file.",
file_description);
break;
case WTAP_ERR_RANDOM_OPEN_PIPE:
cmdarg_err("The %s is a pipe or FIFO; %s can't read pipe or FIFO files in two-pass mode.",
file_description, progname);
break;
case WTAP_ERR_FILE_UNKNOWN_FORMAT:
cmdarg_err("The %s isn't a capture file in a format %s understands.",
file_description, progname);
break;
case WTAP_ERR_UNSUPPORTED:
cmdarg_err("The %s contains record data that %s doesn't support.\n"
"(%s)",
file_description, progname,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED:
cmdarg_err("The %s is a capture for a network type that %s doesn't support.",
file_description, progname);
break;
case WTAP_ERR_BAD_FILE:
cmdarg_err("The %s appears to be damaged or corrupt.\n"
"(%s)",
file_description,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_CANT_OPEN:
cmdarg_err("The %s could not be opened for some unknown reason.",
file_description);
break;
case WTAP_ERR_SHORT_READ:
cmdarg_err("The %s appears to have been cut short in the middle of a packet or other data.",
file_description);
break;
case WTAP_ERR_DECOMPRESS:
cmdarg_err("The %s cannot be decompressed; it may be damaged or corrupt."
"(%s)",
file_description,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
cmdarg_err("The %s could not be opened: %s.",
file_description,
wtap_strerror(err));
break;
}
g_free(file_description);
} else
cmdarg_err(file_open_error_message(err, FALSE), filename);
}
void
cfile_dump_open_failure_message(const char *progname, const char *filename,
int err, int file_type_subtype)
{
char *file_description;
file_description = output_file_description(filename);
if (err < 0) {
switch (err) {
case WTAP_ERR_NOT_REGULAR_FILE:
cmdarg_err("The %s is a \"special file\" or socket or other non-regular file.",
file_description);
break;
case WTAP_ERR_CANT_WRITE_TO_PIPE:
cmdarg_err("The %s is a pipe, and \"%s\" capture files can't be written to a pipe.",
file_description,
wtap_file_type_subtype_short_string(file_type_subtype));
break;
case WTAP_ERR_UNWRITABLE_FILE_TYPE:
cmdarg_err("%s doesn't support writing capture files in that format.",
progname);
break;
case WTAP_ERR_UNWRITABLE_ENCAP:
cmdarg_err("The capture file being read can't be written as a \"%s\" file.",
wtap_file_type_subtype_short_string(file_type_subtype));
break;
case WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED:
cmdarg_err("The capture file being read can't be written as a \"%s\" file.",
wtap_file_type_subtype_short_string(file_type_subtype));
break;
case WTAP_ERR_CANT_OPEN:
cmdarg_err("The %s could not be created for some unknown reason.",
file_description);
break;
case WTAP_ERR_SHORT_WRITE:
cmdarg_err("A full header couldn't be written to the %s.",
file_description);
break;
case WTAP_ERR_COMPRESSION_NOT_SUPPORTED:
cmdarg_err("This file type cannot be written as a compressed file.");
break;
default:
cmdarg_err("The %s could not be created: %s.",
file_description,
wtap_strerror(err));
break;
}
g_free(file_description);
} else
cmdarg_err(file_open_error_message(err, TRUE), filename);
}
void
cfile_read_failure_message(const char *progname, const char *filename,
int err, gchar *err_info)
{
char *file_string;
file_string = input_file_description(filename);
switch (err) {
case WTAP_ERR_UNSUPPORTED:
cmdarg_err("The %s contains record data that %s doesn't support.\n"
"(%s)",
file_string, progname,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_SHORT_READ:
cmdarg_err("The %s appears to have been cut short in the middle of a packet.",
file_string);
break;
case WTAP_ERR_BAD_FILE:
cmdarg_err("The %s appears to be damaged or corrupt.\n"
"(%s)",
file_string,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_DECOMPRESS:
cmdarg_err("The %s cannot be decompressed; it may be damaged or corrupt.\n"
"(%s)",
file_string,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
cmdarg_err("An error occurred while reading the %s: %s.",
file_string, wtap_strerror(err));
break;
}
g_free(file_string);
}
void
cfile_write_failure_message(const char *progname, const char *in_filename,
const char *out_filename, int err, gchar *err_info,
guint32 framenum, int file_type_subtype)
{
char *in_file_string;
char *in_frame_string;
char *out_file_string;
if (in_filename == NULL) {
in_frame_string = g_strdup("");
} else {
in_file_string = input_file_description(in_filename);
in_frame_string = g_strdup_printf(" %u of %s", framenum,
in_file_string);
g_free(in_file_string);
}
out_file_string = output_file_description(out_filename);
switch (err) {
case WTAP_ERR_UNWRITABLE_ENCAP:
cmdarg_err("Frame%s has a network type that can't be saved in a \"%s\" file.",
in_frame_string,
wtap_file_type_subtype_short_string(file_type_subtype));
break;
case WTAP_ERR_PACKET_TOO_LARGE:
cmdarg_err("Frame%s is larger than %s supports in a \"%s\" file.",
in_frame_string, progname,
wtap_file_type_subtype_short_string(file_type_subtype));
break;
case WTAP_ERR_UNWRITABLE_REC_TYPE:
cmdarg_err("Record%s has a record type that can't be saved in a \"%s\" file.",
in_frame_string,
wtap_file_type_subtype_short_string(file_type_subtype));
break;
case WTAP_ERR_UNWRITABLE_REC_DATA:
cmdarg_err("Record%s has data that can't be saved in a \"%s\" file.\n"
"(%s)",
in_frame_string,
wtap_file_type_subtype_short_string(file_type_subtype),
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case ENOSPC:
cmdarg_err("Not all the packets could be written to the %s because there is "
"no space left on the file system.",
out_file_string);
break;
#ifdef EDQUOT
case EDQUOT:
cmdarg_err("Not all the packets could be written to the %s because you are "
"too close to, or over your disk quota.",
out_file_string);
break;
#endif
case WTAP_ERR_SHORT_WRITE:
cmdarg_err("A full write couldn't be done to the %s.",
out_file_string);
break;
default:
cmdarg_err("An error occurred while writing to the %s: %s.",
out_file_string, wtap_strerror(err));
break;
}
g_free(in_frame_string);
g_free(out_file_string);
}
void
cfile_close_failure_message(const char *filename, int err)
{
char *file_string;
file_string = output_file_description(filename);
switch (err) {
case ENOSPC:
cmdarg_err("Not all the packets could be written to the %s because there is "
"no space left on the file system.",
file_string);
break;
#ifdef EDQUOT
case EDQUOT:
cmdarg_err("Not all the packets could be written to the %s because you are "
"too close to, or over your disk quota.",
file_string);
break;
#endif
case WTAP_ERR_CANT_CLOSE:
cmdarg_err("The %s couldn't be closed for some unknown reason.",
file_string);
break;
case WTAP_ERR_SHORT_WRITE:
cmdarg_err("A full write couldn't be done to the %s.",
file_string);
break;
default:
cmdarg_err("An error occurred while closing the file %s: %s.",
file_string, wtap_strerror(err));
break;
}
g_free(file_string);
}
