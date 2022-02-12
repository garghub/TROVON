static void
print_usage(FILE *output)
{
fprintf(output, "\n");
fprintf(output, "Usage: mergecap [options] -w <outfile>|- <infile> [<infile> ...]\n");
fprintf(output, "\n");
fprintf(output, "Output:\n");
fprintf(output, " -a concatenate rather than merge files.\n");
fprintf(output, " default is to merge based on frame timestamps.\n");
fprintf(output, " -s <snaplen> truncate packets to <snaplen> bytes of data.\n");
fprintf(output, " -w <outfile>|- set the output filename to <outfile> or '-' for stdout.\n");
fprintf(output, " -F <capture type> set the output file type; default is pcapng.\n");
fprintf(output, " an empty \"-F\" option will list the file types.\n");
fprintf(output, " -I <IDB merge mode> set the merge mode for Interface Description Blocks; default is 'all'.\n");
fprintf(output, " an empty \"-I\" option will list the merge modes.\n");
fprintf(output, "\n");
fprintf(output, "Miscellaneous:\n");
fprintf(output, " -h display this help and exit.\n");
fprintf(output, " -v verbose output.\n");
}
static void
mergecap_cmdarg_err(const char *fmt, va_list ap)
{
fprintf(stderr, "mergecap: ");
vfprintf(stderr, fmt, ap);
fprintf(stderr, "\n");
}
static void
mergecap_cmdarg_err_cont(const char *fmt, va_list ap)
{
vfprintf(stderr, fmt, ap);
fprintf(stderr, "\n");
}
static gint
string_compare(gconstpointer a, gconstpointer b)
{
return strcmp(((const struct string_elem *)a)->sstr,
((const struct string_elem *)b)->sstr);
}
static void
string_elem_print(gpointer data, gpointer not_used _U_)
{
fprintf(stderr, " %s - %s\n", ((struct string_elem *)data)->sstr,
((struct string_elem *)data)->lstr);
}
static void
list_capture_types(void) {
int i;
struct string_elem *captypes;
GSList *list = NULL;
captypes = g_new(struct string_elem,WTAP_NUM_FILE_TYPES_SUBTYPES);
fprintf(stderr, "mergecap: The available capture file types for the \"-F\" flag are:\n");
for (i = 0; i < WTAP_NUM_FILE_TYPES_SUBTYPES; i++) {
if (wtap_dump_can_open(i)) {
captypes[i].sstr = wtap_file_type_subtype_short_string(i);
captypes[i].lstr = wtap_file_type_subtype_string(i);
list = g_slist_insert_sorted(list, &captypes[i], string_compare);
}
}
g_slist_foreach(list, string_elem_print, NULL);
g_slist_free(list);
g_free(captypes);
}
static void
list_idb_merge_modes(void) {
int i;
fprintf(stderr, "mergecap: The available IDB merge modes for the \"-I\" flag are:\n");
for (i = 0; i < IDB_MERGE_MODE_MAX; i++) {
fprintf(stderr, " %s\n", merge_idb_merge_mode_to_string(i));
}
}
static void
get_mergecap_compiled_info(GString *str)
{
g_string_append(str, ", ");
#ifdef HAVE_LIBZ
g_string_append(str, "with libz ");
#ifdef ZLIB_VERSION
g_string_append(str, ZLIB_VERSION);
#else
g_string_append(str, "(version unknown)");
#endif
#else
g_string_append(str, "without libz");
#endif
}
static void
get_mergecap_runtime_info(GString *str)
{
#if defined(HAVE_LIBZ) && !defined(_WIN32)
g_string_append_printf(str, ", with libz %s", zlibVersion());
#endif
}
static gboolean
merge_callback(merge_event event, int num,
const merge_in_file_t in_files[], const guint in_file_count,
void *data _U_)
{
guint i;
switch (event) {
case MERGE_EVENT_INPUT_FILES_OPENED:
for (i = 0; i < in_file_count; i++) {
fprintf(stderr, "mergecap: %s is type %s.\n", in_files[i].filename,
wtap_file_type_subtype_string(wtap_file_type_subtype(in_files[i].wth)));
}
break;
case MERGE_EVENT_FRAME_TYPE_SELECTED:
if (num == WTAP_ENCAP_PER_PACKET) {
int first_frame_type, this_frame_type;
first_frame_type = wtap_file_encap(in_files[0].wth);
for (i = 1; i < in_file_count; i++) {
this_frame_type = wtap_file_encap(in_files[i].wth);
if (first_frame_type != this_frame_type) {
fprintf(stderr, "mergecap: multiple frame encapsulation types detected\n");
fprintf(stderr, " defaulting to WTAP_ENCAP_PER_PACKET\n");
fprintf(stderr, " %s had type %s (%s)\n",
in_files[0].filename,
wtap_encap_string(first_frame_type),
wtap_encap_short_string(first_frame_type));
fprintf(stderr, " %s had type %s (%s)\n",
in_files[i].filename,
wtap_encap_string(this_frame_type),
wtap_encap_short_string(this_frame_type));
break;
}
}
}
fprintf(stderr, "mergecap: selected frame_type %s (%s)\n",
wtap_encap_string(num),
wtap_encap_short_string(num));
break;
case MERGE_EVENT_READY_TO_MERGE:
fprintf(stderr, "mergecap: ready to merge records\n");
break;
case MERGE_EVENT_PACKET_WAS_READ:
fprintf(stderr, "Record: %d\n", num);
break;
case MERGE_EVENT_DONE:
fprintf(stderr, "mergecap: merging complete\n");
break;
}
return FALSE;
}
int
main(int argc, char *argv[])
{
GString *comp_info_str;
GString *runtime_info_str;
int opt;
DIAG_OFF(cast-qual)
static const struct option long_options[] = {
{(char *)"help", no_argument, NULL, 'h'},
{(char *)"version", no_argument, NULL, 'V'},
{0, 0, 0, 0 }
};
DIAG_ON(cast-qual)
gboolean do_append = FALSE;
gboolean verbose = FALSE;
int in_file_count = 0;
guint snaplen = 0;
#ifdef PCAP_NG_DEFAULT
int file_type = WTAP_FILE_TYPE_SUBTYPE_PCAPNG;
#else
int file_type = WTAP_FILE_TYPE_SUBTYPE_PCAP;
#endif
int out_fd;
int err = 0;
gchar *err_info = NULL;
int err_fileno;
char *out_filename = NULL;
merge_result status;
idb_merge_mode mode = IDB_MERGE_MODE_MAX;
gboolean use_stdout = FALSE;
merge_progress_callback_t cb;
cmdarg_err_init(mergecap_cmdarg_err, mergecap_cmdarg_err_cont);
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#endif
comp_info_str = get_compiled_version_info(NULL, get_mergecap_compiled_info);
runtime_info_str = get_runtime_version_info(get_mergecap_runtime_info);
ws_add_crash_info("Mergecap (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), comp_info_str->str, runtime_info_str->str);
while ((opt = getopt_long(argc, argv, "aF:hI:s:vVw:", long_options, NULL)) != -1) {
switch (opt) {
case 'a':
do_append = !do_append;
break;
case 'F':
file_type = wtap_short_string_to_file_type_subtype(optarg);
if (file_type < 0) {
fprintf(stderr, "mergecap: \"%s\" isn't a valid capture file type\n",
optarg);
list_capture_types();
exit(1);
}
break;
case 'h':
printf("Mergecap (Wireshark) %s\n"
"Merge two or more capture files into one.\n"
"See https://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
print_usage(stdout);
exit(0);
break;
case 'I':
mode = merge_string_to_idb_merge_mode(optarg);
if (mode == IDB_MERGE_MODE_MAX) {
fprintf(stderr, "mergecap: \"%s\" isn't a valid IDB merge mode\n",
optarg);
list_idb_merge_modes();
exit(1);
}
break;
case 's':
snaplen = get_positive_int(optarg, "snapshot length");
break;
case 'v':
verbose = TRUE;
break;
case 'V':
show_version("Mergecap (Wireshark)", comp_info_str, runtime_info_str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
exit(0);
break;
case 'w':
out_filename = optarg;
break;
case '?':
switch(optopt) {
case'F':
list_capture_types();
break;
case'I':
list_idb_merge_modes();
break;
default:
print_usage(stderr);
}
exit(1);
break;
}
}
cb.callback_func = merge_callback;
cb.data = NULL;
in_file_count = argc - optind;
if (!out_filename) {
fprintf(stderr, "mergecap: an output filename must be set with -w\n");
fprintf(stderr, " run with -h for help\n");
return 1;
}
if (in_file_count < 1) {
fprintf(stderr, "mergecap: No input files were specified\n");
return 1;
}
if (mode != IDB_MERGE_MODE_MAX && file_type != WTAP_FILE_TYPE_SUBTYPE_PCAPNG) {
fprintf(stderr, "The IDB merge mode can only be used with PCAPNG output format\n");
return 1;
}
if (mode == IDB_MERGE_MODE_MAX) {
mode = IDB_MERGE_MODE_ALL_SAME;
}
if (strncmp(out_filename, "-", 2) == 0) {
use_stdout = TRUE;
out_fd = 1 ;
} else {
out_fd = ws_open(out_filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0644);
if (out_fd == -1) {
fprintf(stderr, "mergecap: Couldn't open output file %s: %s\n",
out_filename, g_strerror(errno));
exit(1);
}
}
status = merge_files(out_fd, out_filename, file_type,
(const char *const *) &argv[optind], in_file_count,
do_append, mode, snaplen, "mergecap", verbose ? &cb : NULL,
&err, &err_info, &err_fileno);
switch (status) {
case MERGE_OK:
break;
case MERGE_USER_ABORTED:
g_assert(FALSE);
break;
case MERGE_ERR_CANT_OPEN_INFILE:
fprintf(stderr, "mergecap: Can't open %s: %s (%s)\n", argv[optind + err_fileno],
wtap_strerror(err), err_info ? err_info : "no more information");
break;
case MERGE_ERR_CANT_OPEN_OUTFILE:
fprintf(stderr, "mergecap: Can't open or create %s: %s\n", out_filename,
wtap_strerror(err));
if (!use_stdout)
ws_close(out_fd);
break;
case MERGE_ERR_CANT_READ_INFILE:
case MERGE_ERR_BAD_PHDR_INTERFACE_ID:
case MERGE_ERR_CANT_WRITE_OUTFILE:
case MERGE_ERR_CANT_CLOSE_OUTFILE:
default:
fprintf(stderr, "mergecap: %s\n", err_info ? err_info : "unknown error");
break;
}
g_free(err_info);
return (status == MERGE_OK) ? 0 : 2;
}
