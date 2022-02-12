static void
print_usage(FILE *output)
{
fprintf(output, "\n");
fprintf(output, "Usage: tfshark [options] ...\n");
fprintf(output, "\n");
fprintf(output, "Input file:\n");
fprintf(output, " -r <infile> set the filename to read from (no pipes or stdin)\n");
fprintf(output, "\n");
fprintf(output, "Processing:\n");
fprintf(output, " -2 perform a two-pass analysis\n");
fprintf(output, " -R <read filter> packet Read filter in Wireshark display filter syntax\n");
fprintf(output, " (requires -2)\n");
fprintf(output, " -Y <display filter> packet displaY filter in Wireshark display filter\n");
fprintf(output, " syntax\n");
fprintf(output, " -d %s ...\n", DECODE_AS_ARG_TEMPLATE);
fprintf(output, " \"Decode As\", see the man page for details\n");
fprintf(output, " Example: tcp.port==8888,http\n");
fprintf(output, "Output:\n");
fprintf(output, " -C <config profile> start with specified configuration profile\n");
fprintf(output, " -V add output of packet tree (Packet Details)\n");
fprintf(output, " -O <protocols> Only show packet details of these protocols, comma\n");
fprintf(output, " separated\n");
fprintf(output, " -S <separator> the line separator to print between packets\n");
fprintf(output, " -x add output of hex and ASCII dump (Packet Bytes)\n");
fprintf(output, " -T pdml|ps|psml|text|fields\n");
fprintf(output, " format of text output (def: text)\n");
fprintf(output, " -e <field> field to print if -Tfields selected (e.g. tcp.port,\n");
fprintf(output, " _ws.col.Info)\n");
fprintf(output, " this option can be repeated to print multiple fields\n");
fprintf(output, " -E<fieldsoption>=<value> set options for output when -Tfields selected:\n");
fprintf(output, " header=y|n switch headers on and off\n");
fprintf(output, " separator=/t|/s|<char> select tab, space, printable character as separator\n");
fprintf(output, " occurrence=f|l|a print first, last or all occurrences of each field\n");
fprintf(output, " aggregator=,|/s|<char> select comma, space, printable character as\n");
fprintf(output, " aggregator\n");
fprintf(output, " quote=d|s|n select double, single, no quotes for values\n");
fprintf(output, " -t a|ad|d|dd|e|r|u|ud output format of time stamps (def: r: rel. to first)\n");
fprintf(output, " -u s|hms output format of seconds (def: s: seconds)\n");
fprintf(output, " -l flush standard output after each packet\n");
fprintf(output, " -q be more quiet on stdout (e.g. when using statistics)\n");
fprintf(output, " -Q only log true errors to stderr (quieter than -q)\n");
fprintf(output, " -X <key>:<value> eXtension options, see the man page for details\n");
fprintf(output, " -z <statistics> various statistics, see the man page for details\n");
fprintf(output, "\n");
fprintf(output, "Miscellaneous:\n");
fprintf(output, " -h display this help and exit\n");
fprintf(output, " -v display version info and exit\n");
fprintf(output, " -o <name>:<value> ... override preference setting\n");
fprintf(output, " -K <keytab> keytab file to use for kerberos decryption\n");
fprintf(output, " -G [report] dump one of several available reports and exit\n");
fprintf(output, " default report=\"fields\"\n");
fprintf(output, " use \"-G ?\" for more help\n");
}
static void
glossary_option_help(void)
{
FILE *output;
output = stdout;
fprintf(output, "TFShark (Wireshark) %s\n", get_ws_vcs_version_info());
fprintf(output, "\n");
fprintf(output, "Usage: tfshark -G [report]\n");
fprintf(output, "\n");
fprintf(output, "Glossary table reports:\n");
fprintf(output, " -G column-formats dump column format codes and exit\n");
fprintf(output, " -G decodes dump \"layer type\"/\"decode as\" associations and exit\n");
fprintf(output, " -G dissector-tables dump dissector table names, types, and properties\n");
fprintf(output, " -G fields dump fields glossary and exit\n");
fprintf(output, " -G ftypes dump field type basic and descriptive names\n");
fprintf(output, " -G heuristic-decodes dump heuristic dissector tables\n");
fprintf(output, " -G plugins dump installed plugins and exit\n");
fprintf(output, " -G protocols dump protocols in registration database and exit\n");
fprintf(output, " -G values dump value, range, true/false strings and exit\n");
fprintf(output, "\n");
fprintf(output, "Preference reports:\n");
fprintf(output, " -G currentprefs dump current preferences and exit\n");
fprintf(output, " -G defaultprefs dump default preferences and exit\n");
fprintf(output, "\n");
}
static void
tfshark_log_handler (const gchar *log_domain, GLogLevelFlags log_level,
const gchar *message, gpointer user_data)
{
if ((log_level & G_LOG_LEVEL_MASK & prefs.console_log_level) == 0 &&
prefs.console_log_level != 0) {
return;
}
g_log_default_handler(log_domain, log_level, message, user_data);
}
static void
print_current_user(void) {
gchar *cur_user, *cur_group;
if (started_with_special_privs()) {
cur_user = get_cur_username();
cur_group = get_cur_groupname();
fprintf(stderr, "Running as user \"%s\" and group \"%s\".",
cur_user, cur_group);
g_free(cur_user);
g_free(cur_group);
if (running_with_special_privs()) {
fprintf(stderr, " This could be dangerous.");
}
fprintf(stderr, "\n");
}
}
static void
get_tfshark_runtime_version_info(GString *str)
{
epan_get_runtime_version_info(str);
}
int
main(int argc, char *argv[])
{
GString *comp_info_str;
GString *runtime_info_str;
char *init_progfile_dir_error;
int opt;
static const struct option long_options[] = {
{"help", no_argument, NULL, 'h'},
{"version", no_argument, NULL, 'v'},
{0, 0, 0, 0 }
};
gboolean arg_error = FALSE;
int err;
volatile gboolean success;
volatile int exit_status = 0;
gboolean quiet = FALSE;
gchar *volatile cf_name = NULL;
gchar *rfilter = NULL;
gchar *dfilter = NULL;
dfilter_t *rfcode = NULL;
dfilter_t *dfcode = NULL;
gchar *err_msg;
e_prefs *prefs_p;
int log_flags;
gchar *output_only = NULL;
#define OPTSTRING "+2C:d:e:E:hK:lo:O:qQr:R:S:t:T:u:vVxX:Y:z:"
static const char optstring[] = OPTSTRING;
setlocale(LC_ALL, "");
cmdarg_err_init(failure_warning_message, failure_message_cont);
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#if !GLIB_CHECK_VERSION(2,31,0)
g_thread_init(NULL);
#endif
#endif
init_process_policies();
relinquish_special_privs_perm();
print_current_user();
init_progfile_dir_error = init_progfile_dir(argv[0], main);
if (init_progfile_dir_error != NULL) {
fprintf(stderr,
"tfshark: Can't get pathname of directory containing the tfshark program: %s.\n",
init_progfile_dir_error);
g_free(init_progfile_dir_error);
}
initialize_funnel_ops();
comp_info_str = get_compiled_version_info(NULL, epan_get_compiled_version_info);
runtime_info_str = get_runtime_version_info(get_tfshark_runtime_version_info);
ws_add_crash_info("TFShark (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), comp_info_str->str, runtime_info_str->str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
opterr = 0;
while ((opt = getopt_long(argc, argv, optstring, long_options, NULL)) != -1) {
switch (opt) {
case 'C':
if (profile_exists (optarg, FALSE)) {
set_profile_name (optarg);
} else {
cmdarg_err("Configuration Profile \"%s\" does not exist", optarg);
return 1;
}
break;
case 'O':
output_only = g_strdup(optarg);
case 'V':
print_details = TRUE;
print_packet_info = TRUE;
break;
case 'x':
print_hex = TRUE;
print_packet_info = TRUE;
break;
case 'X':
ex_opt_add(optarg);
break;
default:
break;
}
}
if (print_summary == -1)
print_summary = (print_details || print_hex) ? FALSE : TRUE;
log_flags =
G_LOG_LEVEL_ERROR|
G_LOG_LEVEL_CRITICAL|
G_LOG_LEVEL_WARNING|
G_LOG_LEVEL_MESSAGE|
G_LOG_LEVEL_INFO|
G_LOG_LEVEL_DEBUG|
G_LOG_FLAG_FATAL|G_LOG_FLAG_RECURSION;
g_log_set_handler(NULL,
(GLogLevelFlags)log_flags,
tfshark_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_MAIN,
(GLogLevelFlags)log_flags,
tfshark_log_handler, NULL );
init_report_message(failure_warning_message, failure_warning_message,
open_failure_message, read_failure_message,
write_failure_message);
timestamp_set_type(TS_RELATIVE);
timestamp_set_precision(TS_PREC_AUTO);
timestamp_set_seconds_type(TS_SECONDS_DEFAULT);
wtap_init();
#ifdef HAVE_PLUGINS
epan_register_plugin_types();
scan_plugins(REPORT_LOAD_FAILURE);
#endif
if (!epan_init(register_all_protocols, register_all_protocol_handoffs, NULL,
NULL)) {
exit_status = INIT_ERROR;
goto clean_exit;
}
if (argc >= 2 && strcmp(argv[1], "-G") == 0) {
proto_initialize_all_prefixes();
if (argc == 2)
proto_registrar_dump_fields();
else {
if (strcmp(argv[2], "column-formats") == 0)
column_dump_column_formats();
else if (strcmp(argv[2], "currentprefs") == 0) {
epan_load_settings();
write_prefs(NULL);
}
else if (strcmp(argv[2], "decodes") == 0)
dissector_dump_decodes();
else if (strcmp(argv[2], "defaultprefs") == 0)
write_prefs(NULL);
else if (strcmp(argv[2], "dissector-tables") == 0)
dissector_dump_dissector_tables();
else if (strcmp(argv[2], "fields") == 0)
proto_registrar_dump_fields();
else if (strcmp(argv[2], "ftypes") == 0)
proto_registrar_dump_ftypes();
else if (strcmp(argv[2], "heuristic-decodes") == 0)
dissector_dump_heur_decodes();
else if (strcmp(argv[2], "plugins") == 0) {
#ifdef HAVE_PLUGINS
plugins_dump_all();
#endif
#ifdef HAVE_LUA
wslua_plugins_dump_all();
#endif
}
else if (strcmp(argv[2], "protocols") == 0)
proto_registrar_dump_protocols();
else if (strcmp(argv[2], "values") == 0)
proto_registrar_dump_values();
else if (strcmp(argv[2], "?") == 0)
glossary_option_help();
else if (strcmp(argv[2], "-?") == 0)
glossary_option_help();
else {
cmdarg_err("Invalid \"%s\" option for -G flag, enter -G ? for more help.", argv[2]);
exit_status = INVALID_OPTION;
goto clean_exit;
}
}
goto clean_exit;
}
prefs_p = epan_load_settings();
cap_file_init(&cfile);
print_format = PR_FMT_TEXT;
output_fields = output_fields_new();
#ifdef HAVE_OPTRESET
optreset = 1;
optind = 1;
#else
optind = 0;
#endif
opterr = 1;
while ((opt = getopt_long(argc, argv, optstring, long_options, NULL)) != -1) {
switch (opt) {
case '2':
perform_two_pass_analysis = TRUE;
break;
case 'C':
break;
case 'e':
output_fields_add(output_fields, optarg);
break;
case 'E':
if (!output_fields_set_option(output_fields, optarg)) {
cmdarg_err("\"%s\" is not a valid field output option=value pair.", optarg);
output_fields_list_options(stderr);
exit_status = INVALID_OPTION;
goto clean_exit;
}
break;
case 'h':
printf("TFShark (Wireshark) %s\n"
"Dump and analyze network traffic.\n"
"See https://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
print_usage(stdout);
goto clean_exit;
break;
case 'l':
line_buffered = TRUE;
break;
case 'o':
{
char *errmsg = NULL;
switch (prefs_set_pref(optarg, &errmsg)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
cmdarg_err("Invalid -o flag \"%s\"%s%s", optarg,
errmsg ? ": " : "", errmsg ? errmsg : "");
g_free(errmsg);
return 1;
break;
case PREFS_SET_NO_SUCH_PREF:
case PREFS_SET_OBSOLETE:
cmdarg_err("-o flag \"%s\" specifies unknown preference", optarg);
exit_status = INVALID_OPTION;
goto clean_exit;
break;
}
break;
}
case 'q':
quiet = TRUE;
break;
case 'Q':
quiet = TRUE;
really_quiet = TRUE;
break;
case 'r':
cf_name = g_strdup(optarg);
break;
case 'R':
rfilter = optarg;
break;
case 'S':
separator = g_strdup(optarg);
break;
case 'T':
if (strcmp(optarg, "text") == 0) {
output_action = WRITE_TEXT;
print_format = PR_FMT_TEXT;
} else if (strcmp(optarg, "ps") == 0) {
output_action = WRITE_TEXT;
print_format = PR_FMT_PS;
} else if (strcmp(optarg, "pdml") == 0) {
output_action = WRITE_XML;
print_details = TRUE;
print_summary = FALSE;
} else if (strcmp(optarg, "psml") == 0) {
output_action = WRITE_XML;
print_details = FALSE;
print_summary = TRUE;
} else if (strcmp(optarg, "fields") == 0) {
output_action = WRITE_FIELDS;
print_details = TRUE;
print_summary = FALSE;
} else {
cmdarg_err("Invalid -T parameter \"%s\"; it must be one of:", optarg);
cmdarg_err_cont("\t\"fields\" The values of fields specified with the -e option, in a form\n"
"\t specified by the -E option.\n"
"\t\"pdml\" Packet Details Markup Language, an XML-based format for the\n"
"\t details of a decoded packet. This information is equivalent to\n"
"\t the packet details printed with the -V flag.\n"
"\t\"ps\" PostScript for a human-readable one-line summary of each of\n"
"\t the packets, or a multi-line view of the details of each of\n"
"\t the packets, depending on whether the -V flag was specified.\n"
"\t\"psml\" Packet Summary Markup Language, an XML-based format for the\n"
"\t summary information of a decoded packet. This information is\n"
"\t equivalent to the information shown in the one-line summary\n"
"\t printed by default.\n"
"\t\"text\" Text of a human-readable one-line summary of each of the\n"
"\t packets, or a multi-line view of the details of each of the\n"
"\t packets, depending on whether the -V flag was specified.\n"
"\t This is the default.");
exit_status = INVALID_OPTION;
goto clean_exit;
}
break;
case 'v':
comp_info_str = get_compiled_version_info(NULL, epan_get_compiled_version_info);
runtime_info_str = get_runtime_version_info(get_tfshark_runtime_version_info);
show_version("TFShark (Wireshark)", comp_info_str, runtime_info_str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
goto clean_exit;
case 'O':
break;
case 'V':
break;
case 'x':
break;
case 'X':
break;
case 'Y':
dfilter = optarg;
break;
case 'z':
if (strcmp("help", optarg) == 0) {
fprintf(stderr, "tfshark: The available statistics for the \"-z\" option are:\n");
list_stat_cmd_args();
goto clean_exit;
}
if (!process_stat_cmd_arg(optarg)) {
cmdarg_err("Invalid -z argument \"%s\"; it must be one of:", optarg);
list_stat_cmd_args();
exit_status = INVALID_OPTION;
goto clean_exit;
}
break;
case 'd':
case 'K':
case 't':
case 'u':
case LONGOPT_DISABLE_PROTOCOL:
case LONGOPT_ENABLE_HEURISTIC:
case LONGOPT_DISABLE_HEURISTIC:
case LONGOPT_ENABLE_PROTOCOL:
if (!dissect_opts_handle_opt(opt, optarg)) {
exit_status = INVALID_OPTION;
goto clean_exit;
}
break;
default:
case '?':
print_usage(stderr);
exit_status = INVALID_OPTION;
goto clean_exit;
break;
}
}
if (WRITE_FIELDS != output_action && 0 != output_fields_num_fields(output_fields)) {
cmdarg_err("Output fields were specified with \"-e\", "
"but \"-Tfields\" was not specified.");
return 1;
} else if (WRITE_FIELDS == output_action && 0 == output_fields_num_fields(output_fields)) {
cmdarg_err("\"-Tfields\" was specified, but no fields were "
"specified with \"-e\".");
exit_status = INVALID_OPTION;
goto clean_exit;
}
if (optind < argc) {
if (cf_name != NULL) {
if (dfilter != NULL) {
cmdarg_err("Display filters were specified both with \"-d\" "
"and with additional command-line arguments.");
exit_status = INVALID_OPTION;
goto clean_exit;
}
dfilter = get_args_as_string(argc, argv, optind);
}
}
if (!quiet)
print_packet_info = TRUE;
if (arg_error) {
print_usage(stderr);
exit_status = INVALID_OPTION;
goto clean_exit;
}
if (print_hex) {
if (output_action != WRITE_TEXT) {
cmdarg_err("Raw packet hex data can only be printed as text or PostScript");
exit_status = INVALID_OPTION;
goto clean_exit;
}
}
if (output_only != NULL) {
char *ps;
if (!print_details) {
cmdarg_err("-O requires -V");
exit_status = INVALID_OPTION;
goto clean_exit;
}
output_only_tables = g_hash_table_new (g_str_hash, g_str_equal);
for (ps = strtok (output_only, ","); ps; ps = strtok (NULL, ",")) {
g_hash_table_insert(output_only_tables, (gpointer)ps, (gpointer)ps);
}
}
if (rfilter != NULL && !perform_two_pass_analysis) {
cmdarg_err("-R without -2 is deprecated. For single-pass filtering use -Y.");
exit_status = INVALID_OPTION;
goto clean_exit;
}
prefs_apply_all();
start_requested_stats();
if (!setup_enabled_and_disabled_protocols()) {
exit_status = INVALID_OPTION;
goto clean_exit;
}
build_column_format_array(&cfile.cinfo, prefs_p->num_cols, TRUE);
if (rfilter != NULL) {
if (!dfilter_compile(rfilter, &rfcode, &err_msg)) {
cmdarg_err("%s", err_msg);
g_free(err_msg);
exit_status = INVALID_FILTER;
goto clean_exit;
}
}
cfile.rfcode = rfcode;
if (dfilter != NULL) {
if (!dfilter_compile(dfilter, &dfcode, &err_msg)) {
cmdarg_err("%s", err_msg);
g_free(err_msg);
exit_status = INVALID_FILTER;
goto clean_exit;
}
}
cfile.dfcode = dfcode;
if (print_packet_info) {
if (output_action == WRITE_TEXT) {
switch (print_format) {
case PR_FMT_TEXT:
print_stream = print_stream_text_stdio_new(stdout);
break;
case PR_FMT_PS:
print_stream = print_stream_ps_stdio_new(stdout);
break;
default:
g_assert_not_reached();
}
}
}
do_dissection = print_packet_info || rfcode || dfcode || tap_listeners_require_dissection();
if (cf_name) {
if (cf_open(&cfile, cf_name, WTAP_TYPE_AUTO, FALSE, &err) != CF_OK) {
exit_status = OPEN_ERROR;
goto clean_exit;
}
TRY {
success = process_file(&cfile, 1, 0);
}
CATCH(OutOfMemoryError) {
fprintf(stderr,
"Out Of Memory.\n"
"\n"
"Sorry, but TFShark has to terminate now.\n"
"\n"
"Some infos / workarounds can be found at:\n"
"https://wiki.wireshark.org/KnownBugs/OutOfMemory\n");
success = FALSE;
}
ENDTRY;
if (!success) {
exit_status = 2;
}
}
g_free(cf_name);
if (cfile.frames != NULL) {
free_frame_data_sequence(cfile.frames);
cfile.frames = NULL;
}
draw_tap_listeners(TRUE);
funnel_dump_all_text_windows();
clean_exit:
destroy_print_stream(print_stream);
epan_free(cfile.epan);
epan_cleanup();
#ifdef HAVE_EXTCAP
extcap_cleanup();
#endif
output_fields_free(output_fields);
output_fields = NULL;
col_cleanup(&cfile.cinfo);
wtap_cleanup();
return exit_status;
}
static const nstime_t *
tfshark_get_frame_ts(void *data, guint32 frame_num)
{
capture_file *cf = (capture_file *) data;
if (ref && ref->num == frame_num)
return &ref->abs_ts;
if (prev_dis && prev_dis->num == frame_num)
return &prev_dis->abs_ts;
if (prev_cap && prev_cap->num == frame_num)
return &prev_cap->abs_ts;
if (cf->frames) {
frame_data *fd = frame_data_sequence_find(cf->frames, frame_num);
return (fd) ? &fd->abs_ts : NULL;
}
return NULL;
}
static const char *
no_interface_name(void *data _U_, guint32 interface_id _U_)
{
return "";
}
static epan_t *
tfshark_epan_new(capture_file *cf)
{
epan_t *epan = epan_new();
epan->data = cf;
epan->get_frame_ts = tfshark_get_frame_ts;
epan->get_interface_name = no_interface_name;
epan->get_user_comment = NULL;
return epan;
}
static gboolean
process_packet_first_pass(capture_file *cf, epan_dissect_t *edt,
gint64 offset, struct wtap_pkthdr *whdr,
const guchar *pd)
{
frame_data fdlocal;
guint32 framenum;
gboolean passed;
framenum = cf->count + 1;
passed = TRUE;
frame_data_init(&fdlocal, framenum, whdr, offset, cum_bytes);
if (edt) {
if (cf->rfcode)
epan_dissect_prime_with_dfilter(edt, cf->rfcode);
prime_epan_dissect_with_postdissector_wanted_hfids(edt);
frame_data_set_before_dissect(&fdlocal, &cf->elapsed_time,
&ref, prev_dis);
if (ref == &fdlocal) {
ref_frame = fdlocal;
ref = &ref_frame;
}
epan_dissect_file_run(edt, whdr, file_tvbuff_new(&fdlocal, pd), &fdlocal, NULL);
if (cf->rfcode)
passed = dfilter_apply_edt(cf->rfcode, edt);
}
if (passed) {
frame_data_set_after_dissect(&fdlocal, &cum_bytes);
prev_cap = prev_dis = frame_data_sequence_add(cf->frames, &fdlocal);
if (edt) {
g_slist_foreach(edt->pi.dependent_frames, find_and_mark_frame_depended_upon, cf->frames);
}
cf->count++;
} else {
frame_data_destroy(&fdlocal);
}
if (edt)
epan_dissect_reset(edt);
return passed;
}
static gboolean
process_packet_second_pass(capture_file *cf, epan_dissect_t *edt,
frame_data *fdata, struct wtap_pkthdr *phdr,
Buffer *buf, guint tap_flags)
{
column_info *cinfo;
gboolean passed;
passed = TRUE;
if (edt) {
if (cf->dfcode)
epan_dissect_prime_with_dfilter(edt, cf->dfcode);
prime_epan_dissect_with_postdissector_wanted_hfids(edt);
col_custom_prime_edt(edt, &cf->cinfo);
if ((tap_flags & TL_REQUIRES_COLUMNS) || (print_packet_info && print_summary))
cinfo = &cf->cinfo;
else
cinfo = NULL;
frame_data_set_before_dissect(fdata, &cf->elapsed_time,
&ref, prev_dis);
if (ref == fdata) {
ref_frame = *fdata;
ref = &ref_frame;
}
epan_dissect_file_run_with_taps(edt, phdr, file_tvbuff_new_buffer(fdata, buf), fdata, cinfo);
if (cf->dfcode)
passed = dfilter_apply_edt(cf->dfcode, edt);
}
if (passed) {
frame_data_set_after_dissect(fdata, &cum_bytes);
if (print_packet_info) {
print_packet(cf, edt);
if (line_buffered)
fflush(stdout);
if (ferror(stdout)) {
show_print_file_io_error(errno);
return FALSE;
}
}
prev_dis = fdata;
}
prev_cap = fdata;
if (edt) {
epan_dissect_reset(edt);
}
return passed || fdata->flags.dependent_of_displayed;
}
static gboolean
local_wtap_read(capture_file *cf, struct wtap_pkthdr* file_phdr _U_, int *err, gchar **err_info _U_, gint64 *data_offset _U_, guint8** data_buffer)
{
gint64 packet_size = wtap_file_size(cf->wth, err);
*data_buffer = (guint8*)g_malloc((gsize)packet_size);
file_read(*data_buffer, (unsigned int)packet_size, cf->wth->fh);
#if 0
if (bytes_read < 0) {
*err = file_error(cf->wth->fh, err_info);
if (*err == 0)
*err = FTAP_ERR_SHORT_READ;
return FALSE;
} else if (bytes_read == 0) {
return FALSE;
}
file_phdr->caplen = (guint32)packet_size;
file_phdr->len = (guint32)packet_size;
wth->phdr.pkt_encap = wth->file_encap;
if (!wth->subtype_read(wth, err, err_info, data_offset)) {
if (*err == 0)
*err = file_error(wth->fh, err_info);
return FALSE;
}
if (wth->phdr.caplen > wth->phdr.len)
wth->phdr.caplen = wth->phdr.len;
g_assert(wth->phdr.pkt_encap != WTAP_ENCAP_PER_PACKET);
#endif
return TRUE;
}
static gboolean
process_file(capture_file *cf, int max_packet_count, gint64 max_byte_count)
{
guint32 framenum;
int err;
gchar *err_info = NULL;
gint64 data_offset = 0;
gboolean filtering_tap_listeners;
guint tap_flags;
Buffer buf;
epan_dissect_t *edt = NULL;
struct wtap_pkthdr file_phdr;
guint8* raw_data;
if (print_packet_info) {
if (!write_preamble(cf)) {
err = errno;
show_print_file_io_error(err);
goto out;
}
}
filtering_tap_listeners = have_filtering_tap_listeners();
tap_flags = union_of_tap_listener_flags();
wtap_phdr_init(&file_phdr);
file_phdr.pkt_encap = 1234;
if (perform_two_pass_analysis) {
frame_data *fdata;
cf->frames = new_frame_data_sequence();
if (do_dissection) {
gboolean create_proto_tree;
create_proto_tree =
(cf->rfcode != NULL || postdissectors_want_hfids());
edt = epan_dissect_new(cf->epan, create_proto_tree, FALSE);
}
while (local_wtap_read(cf, &file_phdr, &err, &err_info, &data_offset, &raw_data)) {
if (process_packet_first_pass(cf, edt, data_offset, &file_phdr,
wtap_buf_ptr(cf->wth))) {
if ( (--max_packet_count == 0) || (max_byte_count != 0 && data_offset >= max_byte_count)) {
err = 0;
break;
}
}
}
if (edt) {
epan_dissect_free(edt);
edt = NULL;
}
#if 0
wtap_sequential_close(cf->wth);
#endif
postseq_cleanup_all_protocols();
prev_dis = NULL;
prev_cap = NULL;
ws_buffer_init(&buf, 1500);
if (do_dissection) {
gboolean create_proto_tree;
create_proto_tree =
(cf->dfcode || print_details || filtering_tap_listeners ||
(tap_flags & TL_REQUIRES_PROTO_TREE) || have_custom_cols(&cf->cinfo));
edt = epan_dissect_new(cf->epan, create_proto_tree, print_packet_info && print_details);
}
for (framenum = 1; err == 0 && framenum <= cf->count; framenum++) {
fdata = frame_data_sequence_find(cf->frames, framenum);
#if 0
if (wtap_seek_read(cf->wth, fdata->file_off,
&buf, fdata->cap_len, &err, &err_info)) {
process_packet_second_pass(cf, edt, fdata, &cf->phdr, &buf, tap_flags);
}
#else
if (!process_packet_second_pass(cf, edt, fdata, &cf->phdr, &buf,
tap_flags))
return FALSE;
#endif
}
if (edt) {
epan_dissect_free(edt);
edt = NULL;
}
ws_buffer_free(&buf);
}
else {
framenum = 0;
if (do_dissection) {
gboolean create_proto_tree;
create_proto_tree =
(cf->rfcode || cf->dfcode || print_details || filtering_tap_listeners ||
(tap_flags & TL_REQUIRES_PROTO_TREE) || postdissectors_want_hfids() ||
have_custom_cols(&cf->cinfo));
edt = epan_dissect_new(cf->epan, create_proto_tree, print_packet_info && print_details);
}
while (local_wtap_read(cf, &file_phdr, &err, &err_info, &data_offset, &raw_data)) {
framenum++;
if (!process_packet_single_pass(cf, edt, data_offset,
&file_phdr,
raw_data, tap_flags))
return FALSE;
if ( (--max_packet_count == 0) || (max_byte_count != 0 && data_offset >= max_byte_count)) {
err = 0;
break;
}
}
if (edt) {
epan_dissect_free(edt);
edt = NULL;
}
}
wtap_phdr_cleanup(&file_phdr);
if (err != 0) {
#ifndef _WIN32
if (print_packet_info) {
ws_statb64 stat_stdout, stat_stderr;
if (ws_fstat64(1, &stat_stdout) == 0 && ws_fstat64(2, &stat_stderr) == 0) {
if (stat_stdout.st_dev == stat_stderr.st_dev &&
stat_stdout.st_ino == stat_stderr.st_ino) {
fflush(stdout);
fprintf(stderr, "\n");
}
}
}
#endif
#if 0
switch (err) {
case FTAP_ERR_UNSUPPORTED:
cmdarg_err("The file \"%s\" contains record data that TFShark doesn't support.\n(%s)",
cf->filename, err_info);
g_free(err_info);
break;
case FTAP_ERR_UNSUPPORTED_ENCAP:
cmdarg_err("The file \"%s\" has a packet with a network type that TFShark doesn't support.\n(%s)",
cf->filename, err_info);
g_free(err_info);
break;
case FTAP_ERR_CANT_READ:
cmdarg_err("An attempt to read from the file \"%s\" failed for some unknown reason.",
cf->filename);
break;
case FTAP_ERR_SHORT_READ:
cmdarg_err("The file \"%s\" appears to have been cut short in the middle of a packet.",
cf->filename);
break;
case FTAP_ERR_BAD_FILE:
cmdarg_err("The file \"%s\" appears to be damaged or corrupt.\n(%s)",
cf->filename, err_info);
g_free(err_info);
break;
case FTAP_ERR_DECOMPRESS:
cmdarg_err("The compressed file \"%s\" appears to be damaged or corrupt.\n"
"(%s)", cf->filename, err_info);
break;
default:
cmdarg_err("An error occurred while reading the file \"%s\": %s.",
cf->filename, ftap_strerror(err));
break;
}
#endif
} else {
if (print_packet_info) {
if (!write_finale()) {
err = errno;
show_print_file_io_error(err);
}
}
}
out:
wtap_close(cf->wth);
cf->wth = NULL;
return (err != 0);
}
static gboolean
process_packet_single_pass(capture_file *cf, epan_dissect_t *edt, gint64 offset,
struct wtap_pkthdr *whdr, const guchar *pd,
guint tap_flags)
{
frame_data fdata;
column_info *cinfo;
gboolean passed;
cf->count++;
passed = TRUE;
frame_data_init(&fdata, cf->count, whdr, offset, cum_bytes);
if (edt) {
if (cf->dfcode)
epan_dissect_prime_with_dfilter(edt, cf->dfcode);
col_custom_prime_edt(edt, &cf->cinfo);
if ((tap_flags & TL_REQUIRES_COLUMNS) || (print_packet_info && print_summary) || output_fields_has_cols(output_fields))
cinfo = &cf->cinfo;
else
cinfo = NULL;
frame_data_set_before_dissect(&fdata, &cf->elapsed_time,
&ref, prev_dis);
if (ref == &fdata) {
ref_frame = fdata;
ref = &ref_frame;
}
epan_dissect_file_run_with_taps(edt, whdr, frame_tvbuff_new(&fdata, pd), &fdata, cinfo);
if (cf->dfcode)
passed = dfilter_apply_edt(cf->dfcode, edt);
}
if (passed) {
frame_data_set_after_dissect(&fdata, &cum_bytes);
if (print_packet_info) {
print_packet(cf, edt);
if (line_buffered)
fflush(stdout);
if (ferror(stdout)) {
show_print_file_io_error(errno);
return FALSE;
}
}
prev_dis_frame = fdata;
prev_dis = &prev_dis_frame;
}
prev_cap_frame = fdata;
prev_cap = &prev_cap_frame;
if (edt) {
epan_dissect_reset(edt);
frame_data_destroy(&fdata);
}
return passed;
}
static gboolean
write_preamble(capture_file *cf)
{
switch (output_action) {
case WRITE_TEXT:
return print_preamble(print_stream, cf->filename, get_ws_vcs_version_info());
case WRITE_XML:
if (print_details)
write_pdml_preamble(stdout, cf->filename);
else
write_psml_preamble(&cf->cinfo, stdout);
return !ferror(stdout);
case WRITE_FIELDS:
write_fields_preamble(output_fields, stdout);
return !ferror(stdout);
default:
g_assert_not_reached();
return FALSE;
}
}
static char *
get_line_buf(size_t len)
{
static char *line_bufp = NULL;
static size_t line_buf_len = 256;
size_t new_line_buf_len;
for (new_line_buf_len = line_buf_len; len > new_line_buf_len;
new_line_buf_len *= 2)
;
if (line_bufp == NULL) {
line_buf_len = new_line_buf_len;
line_bufp = (char *)g_malloc(line_buf_len + 1);
} else {
if (new_line_buf_len > line_buf_len) {
line_buf_len = new_line_buf_len;
line_bufp = (char *)g_realloc(line_bufp, line_buf_len + 1);
}
}
return line_bufp;
}
static inline void
put_string(char *dest, const char *str, size_t str_len)
{
memcpy(dest, str, str_len);
dest[str_len] = '\0';
}
static inline void
put_spaces_string(char *dest, const char *str, size_t str_len, size_t str_with_spaces)
{
size_t i;
for (i = str_len; i < str_with_spaces; i++)
*dest++ = ' ';
put_string(dest, str, str_len);
}
static inline void
put_string_spaces(char *dest, const char *str, size_t str_len, size_t str_with_spaces)
{
size_t i;
memcpy(dest, str, str_len);
for (i = str_len; i < str_with_spaces; i++)
dest[i] = ' ';
dest[str_with_spaces] = '\0';
}
static gboolean
print_columns(capture_file *cf)
{
char *line_bufp;
int i;
size_t buf_offset;
size_t column_len;
size_t col_len;
col_item_t* col_item;
line_bufp = get_line_buf(256);
buf_offset = 0;
*line_bufp = '\0';
for (i = 0; i < cf->cinfo.num_cols; i++) {
col_item = &cf->cinfo.columns[i];
if (!get_column_visible(i))
continue;
switch (col_item->col_fmt) {
case COL_NUMBER:
column_len = col_len = strlen(col_item->col_data);
if (column_len < 3)
column_len = 3;
line_bufp = get_line_buf(buf_offset + column_len);
put_spaces_string(line_bufp + buf_offset, col_item->col_data, col_len, column_len);
break;
case COL_CLS_TIME:
case COL_REL_TIME:
case COL_ABS_TIME:
case COL_ABS_YMD_TIME:
case COL_ABS_YDOY_TIME:
case COL_UTC_TIME:
case COL_UTC_YMD_TIME:
case COL_UTC_YDOY_TIME:
column_len = col_len = strlen(col_item->col_data);
if (column_len < 10)
column_len = 10;
line_bufp = get_line_buf(buf_offset + column_len);
put_spaces_string(line_bufp + buf_offset, col_item->col_data, col_len, column_len);
break;
case COL_DEF_SRC:
case COL_RES_SRC:
case COL_UNRES_SRC:
case COL_DEF_DL_SRC:
case COL_RES_DL_SRC:
case COL_UNRES_DL_SRC:
case COL_DEF_NET_SRC:
case COL_RES_NET_SRC:
case COL_UNRES_NET_SRC:
column_len = col_len = strlen(col_item->col_data);
if (column_len < 12)
column_len = 12;
line_bufp = get_line_buf(buf_offset + column_len);
put_spaces_string(line_bufp + buf_offset, col_item->col_data, col_len, column_len);
break;
case COL_DEF_DST:
case COL_RES_DST:
case COL_UNRES_DST:
case COL_DEF_DL_DST:
case COL_RES_DL_DST:
case COL_UNRES_DL_DST:
case COL_DEF_NET_DST:
case COL_RES_NET_DST:
case COL_UNRES_NET_DST:
column_len = col_len = strlen(col_item->col_data);
if (column_len < 12)
column_len = 12;
line_bufp = get_line_buf(buf_offset + column_len);
put_string_spaces(line_bufp + buf_offset, col_item->col_data, col_len, column_len);
break;
default:
column_len = strlen(col_item->col_data);
line_bufp = get_line_buf(buf_offset + column_len);
put_string(line_bufp + buf_offset, col_item->col_data, column_len);
break;
}
buf_offset += column_len;
if (i != cf->cinfo.num_cols - 1) {
line_bufp = get_line_buf(buf_offset + 4);
switch (col_item->col_fmt) {
case COL_DEF_SRC:
case COL_RES_SRC:
case COL_UNRES_SRC:
switch (cf->cinfo.columns[i+1].col_fmt) {
case COL_DEF_DST:
case COL_RES_DST:
case COL_UNRES_DST:
put_string(line_bufp + buf_offset, " -> ", 4);
buf_offset += 4;
break;
default:
put_string(line_bufp + buf_offset, " ", 1);
buf_offset += 1;
break;
}
break;
case COL_DEF_DL_SRC:
case COL_RES_DL_SRC:
case COL_UNRES_DL_SRC:
switch (cf->cinfo.columns[i+1].col_fmt) {
case COL_DEF_DL_DST:
case COL_RES_DL_DST:
case COL_UNRES_DL_DST:
put_string(line_bufp + buf_offset, " -> ", 4);
buf_offset += 4;
break;
default:
put_string(line_bufp + buf_offset, " ", 1);
buf_offset += 1;
break;
}
break;
case COL_DEF_NET_SRC:
case COL_RES_NET_SRC:
case COL_UNRES_NET_SRC:
switch (cf->cinfo.columns[i+1].col_fmt) {
case COL_DEF_NET_DST:
case COL_RES_NET_DST:
case COL_UNRES_NET_DST:
put_string(line_bufp + buf_offset, " -> ", 4);
buf_offset += 4;
break;
default:
put_string(line_bufp + buf_offset, " ", 1);
buf_offset += 1;
break;
}
break;
case COL_DEF_DST:
case COL_RES_DST:
case COL_UNRES_DST:
switch (cf->cinfo.columns[i+1].col_fmt) {
case COL_DEF_SRC:
case COL_RES_SRC:
case COL_UNRES_SRC:
put_string(line_bufp + buf_offset, " <- ", 4);
buf_offset += 4;
break;
default:
put_string(line_bufp + buf_offset, " ", 1);
buf_offset += 1;
break;
}
break;
case COL_DEF_DL_DST:
case COL_RES_DL_DST:
case COL_UNRES_DL_DST:
switch (cf->cinfo.columns[i+1].col_fmt) {
case COL_DEF_DL_SRC:
case COL_RES_DL_SRC:
case COL_UNRES_DL_SRC:
put_string(line_bufp + buf_offset, " <- ", 4);
buf_offset += 4;
break;
default:
put_string(line_bufp + buf_offset, " ", 1);
buf_offset += 1;
break;
}
break;
case COL_DEF_NET_DST:
case COL_RES_NET_DST:
case COL_UNRES_NET_DST:
switch (cf->cinfo.columns[i+1].col_fmt) {
case COL_DEF_NET_SRC:
case COL_RES_NET_SRC:
case COL_UNRES_NET_SRC:
put_string(line_bufp + buf_offset, " <- ", 4);
buf_offset += 4;
break;
default:
put_string(line_bufp + buf_offset, " ", 1);
buf_offset += 1;
break;
}
break;
default:
put_string(line_bufp + buf_offset, " ", 1);
buf_offset += 1;
break;
}
}
}
return print_line(print_stream, 0, line_bufp);
}
static gboolean
print_packet(capture_file *cf, epan_dissect_t *edt)
{
if (print_summary || output_fields_has_cols(output_fields)) {
epan_dissect_fill_in_columns(edt, FALSE, TRUE);
if (print_summary) {
switch (output_action) {
case WRITE_TEXT:
if (!print_columns(cf))
return FALSE;
break;
case WRITE_XML:
write_psml_columns(edt, stdout);
return !ferror(stdout);
case WRITE_FIELDS:
g_assert_not_reached();
break;
}
}
}
if (print_details) {
switch (output_action) {
case WRITE_TEXT:
if (!proto_tree_print(print_details ? print_dissections_expanded : print_dissections_none,
print_hex, edt, output_only_tables, print_stream))
return FALSE;
if (!print_hex) {
if (!print_line(print_stream, 0, separator))
return FALSE;
}
break;
case WRITE_XML:
write_pdml_proto_tree(NULL, NULL, PF_NONE, edt, stdout);
printf("\n");
return !ferror(stdout);
case WRITE_FIELDS:
write_fields_proto_tree(output_fields, edt, &cf->cinfo, stdout);
printf("\n");
return !ferror(stdout);
}
}
if (print_hex) {
if (print_summary || print_details) {
if (!print_line(print_stream, 0, ""))
return FALSE;
}
if (!print_hex_data(print_stream, edt))
return FALSE;
if (!print_line(print_stream, 0, separator))
return FALSE;
}
return TRUE;
}
static gboolean
write_finale(void)
{
switch (output_action) {
case WRITE_TEXT:
return print_finale(print_stream);
case WRITE_XML:
if (print_details)
write_pdml_finale(stdout);
else
write_psml_finale(stdout);
return !ferror(stdout);
case WRITE_FIELDS:
write_fields_finale(output_fields, stdout);
return !ferror(stdout);
default:
g_assert_not_reached();
return FALSE;
}
}
cf_status_t
cf_open(capture_file *cf, const char *fname, unsigned int type, gboolean is_tempfile, int *err)
{
gchar *err_info;
char err_msg[2048+1];
epan_free(cf->epan);
cf->epan = tfshark_epan_new(cf);
cf->wth = NULL;
cf->f_datalen = 0;
cf->filename = g_strdup(fname);
cf->is_tempfile = is_tempfile;
cf->unsaved_changes = FALSE;
cf->cd_t = 0;
cf->open_type = type;
cf->count = 0;
cf->drops_known = FALSE;
cf->drops = 0;
cf->snap = 0;
nstime_set_zero(&cf->elapsed_time);
ref = NULL;
prev_dis = NULL;
prev_cap = NULL;
cf->state = FILE_READ_IN_PROGRESS;
return CF_OK;
g_snprintf(err_msg, sizeof err_msg,
cf_open_error_message(*err, err_info, FALSE, cf->cd_t), fname);
cmdarg_err("%s", err_msg);
return CF_ERROR;
}
static void
show_print_file_io_error(int err)
{
switch (err) {
case ENOSPC:
cmdarg_err("Not all the packets could be printed because there is "
"no space left on the file system.");
break;
#ifdef EDQUOT
case EDQUOT:
cmdarg_err("Not all the packets could be printed because you are "
"too close to, or over your disk quota.");
break;
#endif
default:
cmdarg_err("An error occurred while printing packets: %s.",
g_strerror(err));
break;
}
}
static const char *
cf_open_error_message(int err, gchar *err_info _U_, gboolean for_writing,
int file_type _U_)
{
const char *errmsg;
#if 0
if (err < 0) {
switch (err) {
case FTAP_ERR_NOT_REGULAR_FILE:
errmsg = "The file \"%s\" is a \"special file\" or socket or other non-regular file.";
break;
case FTAP_ERR_RANDOM_OPEN_PIPE:
errmsg = "The file \"%s\" is a pipe or FIFO; TFShark can't read pipe or FIFO files in two-pass mode.";
break;
case FTAP_ERR_FILE_UNKNOWN_FORMAT:
errmsg = "The file \"%s\" isn't a capture file in a format TFShark understands.";
break;
case FTAP_ERR_UNSUPPORTED:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" isn't a capture file in a format TFShark understands.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
case FTAP_ERR_CANT_WRITE_TO_PIPE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a pipe, and \"%s\" capture files can't be "
"written to a pipe.", ftap_file_type_subtype_short_string(file_type));
errmsg = errmsg_errno;
break;
case FTAP_ERR_UNSUPPORTED_FILE_TYPE:
errmsg = "TFShark doesn't support writing capture files in that format.";
break;
case FTAP_ERR_UNSUPPORTED_ENCAP:
if (for_writing) {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"TFShark can't save this capture as a \"%s\" file.",
ftap_file_type_subtype_short_string(file_type));
} else {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a capture for a network type that TFShark doesn't support.\n"
"(%s)", err_info);
g_free(err_info);
}
errmsg = errmsg_errno;
break;
case FTAP_ERR_ENCAP_PER_RECORD_UNSUPPORTED:
if (for_writing) {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"TFShark can't save this capture as a \"%s\" file.",
ftap_file_type_subtype_short_string(file_type));
errmsg = errmsg_errno;
} else
errmsg = "The file \"%s\" is a capture for a network type that TFShark doesn't support.";
break;
case FTAP_ERR_BAD_FILE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
case FTAP_ERR_CANT_OPEN:
if (for_writing)
errmsg = "The file \"%s\" could not be created for some unknown reason.";
else
errmsg = "The file \"%s\" could not be opened for some unknown reason.";
break;
case FTAP_ERR_SHORT_READ:
errmsg = "The file \"%s\" appears to have been cut short"
" in the middle of a packet or other data.";
break;
case FTAP_ERR_SHORT_WRITE:
errmsg = "A full header couldn't be written to the file \"%s\".";
break;
case FTAP_ERR_COMPRESSION_NOT_SUPPORTED:
errmsg = "This file type cannot be written as a compressed file.";
break;
case FTAP_ERR_DECOMPRESS:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The compressed file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)", err_info);
g_free(err_info);
errmsg = errmsg_errno;
break;
default:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" could not be %s: %s.",
for_writing ? "created" : "opened",
ftap_strerror(err));
errmsg = errmsg_errno;
break;
}
} else
#endif
errmsg = file_open_error_message(err, for_writing);
return errmsg;
}
static void
failure_warning_message(const char *msg_format, va_list ap)
{
fprintf(stderr, "tfshark: ");
vfprintf(stderr, msg_format, ap);
fprintf(stderr, "\n");
}
static void
open_failure_message(const char *filename, int err, gboolean for_writing)
{
fprintf(stderr, "tfshark: ");
fprintf(stderr, file_open_error_message(err, for_writing), filename);
fprintf(stderr, "\n");
}
static void
read_failure_message(const char *filename, int err)
{
cmdarg_err("An error occurred while reading from the file \"%s\": %s.",
filename, g_strerror(err));
}
static void
write_failure_message(const char *filename, int err)
{
cmdarg_err("An error occurred while writing to the file \"%s\": %s.",
filename, g_strerror(err));
}
static void
failure_message_cont(const char *msg_format, va_list ap)
{
vfprintf(stderr, msg_format, ap);
fprintf(stderr, "\n");
}
