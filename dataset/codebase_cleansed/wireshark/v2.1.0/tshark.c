static gint
string_compare(gconstpointer a, gconstpointer b)
{
return strcmp(((const struct string_elem *)a)->sstr,
((const struct string_elem *)b)->sstr);
}
static void
string_elem_print(gpointer data, gpointer not_used _U_)
{
fprintf(stderr, " %s - %s\n",
((struct string_elem *)data)->sstr,
((struct string_elem *)data)->lstr);
}
static void
list_capture_types(void) {
int i;
struct string_elem *captypes;
GSList *list = NULL;
captypes = g_new(struct string_elem, WTAP_NUM_FILE_TYPES_SUBTYPES);
fprintf(stderr, "tshark: The available capture file types for the \"-F\" flag are:\n");
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
list_read_capture_types(void) {
int i;
struct string_elem *captypes;
GSList *list = NULL;
const char *magic = "Magic-value-based";
const char *heuristic = "Heuristics-based";
captypes = g_new(struct string_elem, WTAP_NUM_FILE_TYPES_SUBTYPES);
fprintf(stderr, "tshark: The available read file types for the \"-X read_format:\" option are:\n");
for (i = 0; open_routines[i].name != NULL; i++) {
captypes[i].sstr = open_routines[i].name;
captypes[i].lstr = (open_routines[i].type == OPEN_INFO_MAGIC) ? magic : heuristic;
list = g_slist_insert_sorted(list, &captypes[i], string_compare);
}
g_slist_foreach(list, string_elem_print, NULL);
g_slist_free(list);
g_free(captypes);
}
static void
print_usage(FILE *output)
{
fprintf(output, "\n");
fprintf(output, "Usage: tshark [options] ...\n");
fprintf(output, "\n");
#ifdef HAVE_LIBPCAP
fprintf(output, "Capture interface:\n");
fprintf(output, " -i <interface> name or idx of interface (def: first non-loopback)\n");
fprintf(output, " -f <capture filter> packet filter in libpcap filter syntax\n");
fprintf(output, " -s <snaplen> packet snapshot length (def: 65535)\n");
fprintf(output, " -p don't capture in promiscuous mode\n");
#ifdef HAVE_PCAP_CREATE
fprintf(output, " -I capture in monitor mode, if available\n");
#endif
#ifdef CAN_SET_CAPTURE_BUFFER_SIZE
fprintf(output, " -B <buffer size> size of kernel buffer (def: %dMB)\n", DEFAULT_CAPTURE_BUFFER_SIZE);
#endif
fprintf(output, " -y <link type> link layer type (def: first appropriate)\n");
fprintf(output, " -D print list of interfaces and exit\n");
fprintf(output, " -L print list of link-layer types of iface and exit\n");
fprintf(output, "\n");
fprintf(output, "Capture stop conditions:\n");
fprintf(output, " -c <packet count> stop after n packets (def: infinite)\n");
fprintf(output, " -a <autostop cond.> ... duration:NUM - stop after NUM seconds\n");
fprintf(output, " filesize:NUM - stop this file after NUM KB\n");
fprintf(output, " files:NUM - stop after NUM files\n");
fprintf(output, "Capture output:\n");
fprintf(output, " -b <ringbuffer opt.> ... duration:NUM - switch to next file after NUM secs\n");
fprintf(output, " filesize:NUM - switch to next file after NUM KB\n");
fprintf(output, " files:NUM - ringbuffer: replace after NUM files\n");
#endif
#ifdef HAVE_PCAP_REMOTE
fprintf(output, "RPCAP options:\n");
fprintf(output, " -A <user>:<password> use RPCAP password authentication\n");
#endif
fprintf(output, "Input file:\n");
fprintf(output, " -r <infile> set the filename to read from (- to read from stdin)\n");
fprintf(output, "\n");
fprintf(output, "Processing:\n");
fprintf(output, " -2 perform a two-pass analysis\n");
fprintf(output, " -R <read filter> packet Read filter in Wireshark display filter syntax\n");
fprintf(output, " -Y <display filter> packet displaY filter in Wireshark display filter\n");
fprintf(output, " syntax\n");
fprintf(output, " -n disable all name resolutions (def: all enabled)\n");
fprintf(output, " -N <name resolve flags> enable specific name resolution(s): \"mnNtCd\"\n");
fprintf(output, " -d %s ...\n", decode_as_arg_template);
fprintf(output, " \"Decode As\", see the man page for details\n");
fprintf(output, " Example: tcp.port==8888,http\n");
fprintf(output, " -H <hosts file> read a list of entries from a hosts file, which will\n");
fprintf(output, " then be written to a capture file. (Implies -W n)\n");
fprintf(output, " --disable-protocol <proto_name>\n");
fprintf(output, " disable dissection of proto_name\n");
fprintf(output, " --enable-heuristic <short_name>\n");
fprintf(output, " enable dissection of heuristic protocol\n");
fprintf(output, " --disable-heuristic <short_name>\n");
fprintf(output, " disable dissection of heuristic protocol\n");
fprintf(output, "Output:\n");
fprintf(output, " -w <outfile|-> write packets to a pcap-format file named \"outfile\"\n");
fprintf(output, " (or to the standard output for \"-\")\n");
fprintf(output, " -C <config profile> start with specified configuration profile\n");
fprintf(output, " -F <output file type> set the output file type, default is pcapng\n");
fprintf(output, " an empty \"-F\" option will list the file types\n");
fprintf(output, " -V add output of packet tree (Packet Details)\n");
fprintf(output, " -O <protocols> Only show packet details of these protocols, comma\n");
fprintf(output, " separated\n");
fprintf(output, " -P print packet summary even when writing to a file\n");
fprintf(output, " -S <separator> the line separator to print between packets\n");
fprintf(output, " -x add output of hex and ASCII dump (Packet Bytes)\n");
fprintf(output, " -T pdml|ps|psml|text|fields\n");
fprintf(output, " format of text output (def: text)\n");
fprintf(output, " -e <field> field to print if -Tfields selected (e.g. tcp.port,\n");
fprintf(output, " _ws.col.Info)\n");
fprintf(output, " this option can be repeated to print multiple fields\n");
fprintf(output, " -E<fieldsoption>=<value> set options for output when -Tfields selected:\n");
fprintf(output, " bom=y|n print a UTF-8 BOM\n");
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
fprintf(output, " -g enable group read access on the output file(s)\n");
fprintf(output, " -W n Save extra information in the file, if supported.\n");
fprintf(output, " n = write network address resolution information\n");
fprintf(output, " -X <key>:<value> eXtension options, see the man page for details\n");
fprintf(output, " -U tap_name PDUs export mode, see the man page for details\n");
fprintf(output, " -z <statistics> various statistics, see the man page for details\n");
fprintf(output, " --capture-comment <comment>\n");
fprintf(output, " add a capture comment to the newly created\n");
fprintf(output, " output file (only for pcapng)\n");
fprintf(output, "\n");
fprintf(output, "Miscellaneous:\n");
fprintf(output, " -h display this help and exit\n");
fprintf(output, " -v display version info and exit\n");
fprintf(output, " -o <name>:<value> ... override preference setting\n");
fprintf(output, " -K <keytab> keytab file to use for kerberos decryption\n");
fprintf(output, " -G [report] dump one of several available reports and exit\n");
fprintf(output, " default report=\"fields\"\n");
fprintf(output, " use \"-G ?\" for more help\n");
#ifdef __linux__
fprintf(output, "\n");
fprintf(output, "WARNING: dumpcap will enable kernel BPF JIT compiler if available.\n");
fprintf(output, "You might want to reset it\n");
fprintf(output, "By doing \"echo 0 > /proc/sys/net/core/bpf_jit_enable\"\n");
fprintf(output, "\n");
#endif
}
static void
glossary_option_help(void)
{
FILE *output;
output = stdout;
fprintf(output, "TShark (Wireshark) %s\n", get_ws_vcs_version_info());
fprintf(output, "\n");
fprintf(output, "Usage: tshark -G [report]\n");
fprintf(output, "\n");
fprintf(output, "Glossary table reports:\n");
fprintf(output, " -G column-formats dump column format codes and exit\n");
fprintf(output, " -G decodes dump \"layer type\"/\"decode as\" associations and exit\n");
fprintf(output, " -G dissector-tables dump dissector table names, types, and properties\n");
fprintf(output, " -G fieldcount dump count of header fields and exit\n");
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
display_dissector_table_names(const char *table_name, const char *ui_name,
gpointer output)
{
if ((prev_display_dissector_name == NULL) ||
(strcmp(prev_display_dissector_name, table_name) != 0)) {
fprintf((FILE *)output, "\t%s (%s)\n", table_name, ui_name);
prev_display_dissector_name = table_name;
}
}
static void
display_dissector_names(const gchar *table _U_, gpointer handle, gpointer output)
{
int proto_id;
const gchar *proto_filter_name;
const gchar *proto_ui_name;
proto_id = dissector_handle_get_protocol_index((dissector_handle_t)handle);
if (proto_id != -1) {
proto_filter_name = proto_get_protocol_filter_name(proto_id);
proto_ui_name = proto_get_protocol_name(proto_id);
g_assert(proto_filter_name != NULL);
g_assert(proto_ui_name != NULL);
if ((prev_display_dissector_name == NULL) ||
(strcmp(prev_display_dissector_name, proto_filter_name) != 0)) {
fprintf((FILE *)output, "\t%s (%s)\n",
proto_filter_name,
proto_ui_name);
prev_display_dissector_name = proto_filter_name;
}
}
}
static void
find_protocol_name_func(const gchar *table _U_, gpointer handle, gpointer user_data)
{
int proto_id;
const gchar *protocol_filter_name;
protocol_name_search_t search_info;
g_assert(handle);
search_info = (protocol_name_search_t)user_data;
proto_id = dissector_handle_get_protocol_index((dissector_handle_t)handle);
if (proto_id != -1) {
protocol_filter_name = proto_get_protocol_filter_name(proto_id);
g_assert(protocol_filter_name != NULL);
if (strcmp(protocol_filter_name, search_info->searched_name) == 0) {
if (search_info->nb_match == 0) {
search_info->matched_handle = (dissector_handle_t)handle;
}
search_info->nb_match++;
}
}
}
static gint
compare_dissector_key_name(gconstpointer dissector_a, gconstpointer dissector_b)
{
return strcmp((const char*)dissector_a, (const char*)dissector_b);
}
static void
fprint_all_layer_types(FILE *output)
{
prev_display_dissector_name = NULL;
dissector_all_tables_foreach_table(display_dissector_table_names, (gpointer)output, (GCompareFunc)compare_dissector_key_name);
}
static void
fprint_all_protocols_for_layer_types(FILE *output, gchar *table_name)
{
prev_display_dissector_name = NULL;
dissector_table_foreach_handle(table_name,
display_dissector_names,
(gpointer)output);
}
static gboolean
add_decode_as(const gchar *cl_param)
{
gchar *table_name;
guint32 selector, selector2;
gchar *decoded_param;
gchar *remaining_param;
gchar *selector_str;
gchar *dissector_str;
dissector_handle_t dissector_matching;
dissector_table_t table_matching;
ftenum_t dissector_table_selector_type;
struct protocol_name_search user_protocol_name;
guint64 i;
char op;
g_assert(cl_param);
decoded_param = g_strdup(cl_param);
g_assert(decoded_param);
table_name = decoded_param;
remaining_param = strchr(table_name, '=');
if (remaining_param == NULL) {
cmdarg_err("Parameter \"%s\" doesn't follow the template \"%s\"", cl_param, decode_as_arg_template);
}
else {
*remaining_param = '\0';
}
while ( table_name[0] == ' ' )
table_name++;
while ( table_name[strlen(table_name) - 1] == ' ' )
table_name[strlen(table_name) - 1] = '\0';
table_matching = NULL;
if ( !(*(table_name)) ) {
cmdarg_err("No layer type specified");
}
else {
table_matching = find_dissector_table(table_name);
if (!table_matching) {
cmdarg_err("Unknown layer type -- %s", table_name);
}
}
if (!table_matching) {
cmdarg_err("Valid layer types are:");
fprint_all_layer_types(stderr);
}
if (remaining_param == NULL || !table_matching) {
g_free(decoded_param);
return FALSE;
}
if (*(remaining_param + 1) != '=') {
cmdarg_err("WARNING: -d requires \"==\" instead of \"=\". Option will be treated as \"%s==%s\"", table_name, remaining_param + 1);
}
else {
remaining_param++;
*remaining_param = '\0';
}
remaining_param++;
selector_str = remaining_param;
remaining_param = strchr(selector_str, ',');
if (remaining_param == NULL) {
cmdarg_err("Parameter \"%s\" doesn't follow the template \"%s\"", cl_param, decode_as_arg_template);
}
else {
*remaining_param = '\0';
}
dissector_table_selector_type = get_dissector_table_selector_type(table_name);
switch (dissector_table_selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
switch (sscanf(selector_str, "%u%c%u", &selector, &op, &selector2)) {
case 1:
op = '\0';
break;
case 3:
if (op != ':' && op != '-') {
cmdarg_err("Invalid selector numeric range \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
if (op == ':') {
if ((selector2 == 0) || ((guint64)selector + selector2 - 1) > G_MAXUINT32) {
cmdarg_err("Invalid selector numeric range \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
}
else if (selector2 < selector) {
cmdarg_err("Invalid selector numeric range \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
break;
default:
cmdarg_err("Invalid selector number \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
break;
default:
g_assert_not_reached();
}
if (remaining_param == NULL) {
cmdarg_err("Valid protocols for layer type \"%s\" are:", table_name);
fprint_all_protocols_for_layer_types(stderr, table_name);
g_free(decoded_param);
return FALSE;
}
remaining_param++;
dissector_str = remaining_param;
while ( dissector_str[0] == ' ' )
dissector_str++;
while ( dissector_str[strlen(dissector_str) - 1] == ' ' )
dissector_str[strlen(dissector_str) - 1] = '\0';
dissector_matching = NULL;
if ( ! (*dissector_str) ) {
cmdarg_err("No protocol name specified");
}
else {
user_protocol_name.nb_match = 0;
user_protocol_name.searched_name = dissector_str;
user_protocol_name.matched_handle = NULL;
dissector_table_foreach_handle(table_name, find_protocol_name_func, &user_protocol_name);
if (user_protocol_name.nb_match != 0) {
dissector_matching = user_protocol_name.matched_handle;
if (user_protocol_name.nb_match > 1) {
cmdarg_err("WARNING: Protocol \"%s\" matched %u dissectors, first one will be used", dissector_str, user_protocol_name.nb_match);
}
}
else {
if (proto_get_id_by_filter_name(dissector_str) == -1) {
cmdarg_err("Unknown protocol -- \"%s\"", dissector_str);
} else {
cmdarg_err("Protocol \"%s\" isn't valid for layer type \"%s\"",
dissector_str, table_name);
}
}
}
if (!dissector_matching) {
cmdarg_err("Valid protocols for layer type \"%s\" are:", table_name);
fprint_all_protocols_for_layer_types(stderr, table_name);
g_free(decoded_param);
return FALSE;
}
switch (dissector_table_selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
if (op == '\0') {
dissector_change_uint(table_name, selector, dissector_matching);
} else if (op == ':') {
for (i = selector; i < (guint64)selector + selector2; i++) {
dissector_change_uint(table_name, (guint32)i, dissector_matching);
}
} else {
for (i = selector; i <= selector2; i++) {
dissector_change_uint(table_name, (guint32)i, dissector_matching);
}
}
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
dissector_change_string(table_name, selector_str, dissector_matching);
break;
default:
g_assert_not_reached();
}
g_free(decoded_param);
return TRUE;
}
static void
tshark_log_handler (const gchar *log_domain, GLogLevelFlags log_level,
const gchar *message, gpointer user_data)
{
if ((log_level & G_LOG_LEVEL_MASK & prefs.console_log_level) == 0 &&
prefs.console_log_level != 0) {
return;
}
g_log_default_handler(log_domain, log_level, message, user_data);
}
static char *
output_file_description(const char *fname)
{
char *save_file_string;
if (strcmp(fname, "-") == 0) {
save_file_string = g_strdup("standard output");
} else {
save_file_string = g_strdup_printf("file \"%s\"", fname);
}
return save_file_string;
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
get_tshark_compiled_version_info(GString *str)
{
get_compiled_caplibs_version(str);
}
static void
get_tshark_runtime_version_info(GString *str)
{
#ifdef HAVE_LIBPCAP
g_string_append(str, ", ");
get_runtime_caplibs_version(str);
#endif
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
LONGOPT_CAPTURE_COMMON
{0, 0, 0, 0 }
};
gboolean arg_error = FALSE;
#ifdef _WIN32
WSADATA wsaData;
#endif
char *gpf_path, *pf_path;
char *gdp_path, *dp_path;
char *cf_path;
int gpf_open_errno, gpf_read_errno;
int pf_open_errno, pf_read_errno;
int gdp_open_errno, gdp_read_errno;
int dp_open_errno, dp_read_errno;
int cf_open_errno;
int err;
volatile int exit_status = 0;
#ifdef HAVE_LIBPCAP
gboolean list_link_layer_types = FALSE;
gboolean start_capture = FALSE;
int status;
GList *if_list;
gchar *err_str;
#else
gboolean capture_option_specified = FALSE;
#endif
gboolean quiet = FALSE;
#ifdef PCAP_NG_DEFAULT
volatile int out_file_type = WTAP_FILE_TYPE_SUBTYPE_PCAPNG;
#else
volatile int out_file_type = WTAP_FILE_TYPE_SUBTYPE_PCAP;
#endif
volatile gboolean out_file_name_res = FALSE;
volatile int in_file_type = WTAP_TYPE_AUTO;
gchar *volatile cf_name = NULL;
gchar *rfilter = NULL;
gchar *dfilter = NULL;
#ifdef HAVE_PCAP_OPEN_DEAD
struct bpf_program fcode;
#endif
dfilter_t *rfcode = NULL;
dfilter_t *dfcode = NULL;
gchar *err_msg;
e_prefs *prefs_p;
char badopt;
int log_flags;
gchar *output_only = NULL;
GSList *disable_protocol_slist = NULL;
GSList *enable_heur_slist = NULL;
GSList *disable_heur_slist = NULL;
gchar *volatile pdu_export_arg = NULL;
exp_pdu_t exp_pdu_tap_data;
#define OPTSTRING "+2" OPTSTRING_CAPTURE_COMMON "C:d:e:E:F:gG:hH:" "K:lnN:o:O:PqQr:R:S:t:T:u:U:vVw:W:xX:Y:z:"
static const char optstring[] = OPTSTRING;
tshark_debug("tshark started with %d args", argc);
setlocale(LC_ALL, "");
cmdarg_err_init(failure_message, failure_message_cont);
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
fprintf(stderr, "tshark: Can't get pathname of tshark program: %s.\n",
init_progfile_dir_error);
}
initialize_funnel_ops();
#ifdef _WIN32
load_wpcap();
if (!npf_sys_is_running() && get_windows_major_version() >= 6) {
fprintf(stderr, "The NPF driver isn't running. You may have trouble "
"capturing or\nlisting interfaces.\n");
}
#endif
comp_info_str = get_compiled_version_info(get_tshark_compiled_version_info,
epan_get_compiled_version_info);
runtime_info_str = get_runtime_version_info(get_tshark_runtime_version_info);
ws_add_crash_info("TShark (Wireshark) %s\n"
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
case 'P':
print_packet_info = TRUE;
print_summary = TRUE;
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
tshark_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_MAIN,
(GLogLevelFlags)log_flags,
tshark_log_handler, NULL );
#ifdef HAVE_LIBPCAP
g_log_set_handler(LOG_DOMAIN_CAPTURE,
(GLogLevelFlags)log_flags,
tshark_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_CAPTURE_CHILD,
(GLogLevelFlags)log_flags,
tshark_log_handler, NULL );
#endif
init_report_err(failure_message, open_failure_message, read_failure_message,
write_failure_message);
#ifdef HAVE_LIBPCAP
capture_opts_init(&global_capture_opts);
capture_session_init(&global_capture_session, &cfile);
#endif
timestamp_set_type(TS_RELATIVE);
timestamp_set_precision(TS_PREC_AUTO);
timestamp_set_seconds_type(TS_SECONDS_DEFAULT);
init_open_routines();
#ifdef HAVE_PLUGINS
epan_register_plugin_types();
wtap_register_plugin_types();
scan_plugins();
register_all_wiretap_modules();
#endif
if (!epan_init(register_all_protocols, register_all_protocol_handoffs, NULL,
NULL))
return 2;
#ifdef HAVE_PLUGINS
register_all_plugin_tap_listeners();
#endif
register_all_tap_listeners();
conversation_table_set_gui_info(init_iousers);
hostlist_table_set_gui_info(init_hostlists);
srt_table_iterate_tables(register_srt_tables, NULL);
rtd_table_iterate_tables(register_rtd_tables, NULL);
new_stat_tap_iterate_tables(register_simple_stat_tables, NULL);
if (argc >= 2 && strcmp(argv[1], "-G") == 0) {
proto_initialize_all_prefixes();
if (argc == 2)
proto_registrar_dump_fields();
else {
if (strcmp(argv[2], "column-formats") == 0)
column_dump_column_formats();
else if (strcmp(argv[2], "currentprefs") == 0) {
read_prefs(&gpf_open_errno, &gpf_read_errno, &gpf_path,
&pf_open_errno, &pf_read_errno, &pf_path);
write_prefs(NULL);
}
else if (strcmp(argv[2], "decodes") == 0)
dissector_dump_decodes();
else if (strcmp(argv[2], "defaultprefs") == 0)
write_prefs(NULL);
else if (strcmp(argv[2], "dissector-tables") == 0)
dissector_dump_dissector_tables();
else if (strcmp(argv[2], "fieldcount") == 0) {
return proto_registrar_dump_fieldcount();
} else if (strcmp(argv[2], "fields") == 0)
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
return 1;
}
}
return 0;
}
load_decode_as_entries();
tshark_debug("tshark reading preferences");
prefs_p = read_prefs(&gpf_open_errno, &gpf_read_errno, &gpf_path,
&pf_open_errno, &pf_read_errno, &pf_path);
if (gpf_path != NULL) {
if (gpf_open_errno != 0) {
cmdarg_err("Can't open global preferences file \"%s\": %s.",
pf_path, g_strerror(gpf_open_errno));
}
if (gpf_read_errno != 0) {
cmdarg_err("I/O error reading global preferences file \"%s\": %s.",
pf_path, g_strerror(gpf_read_errno));
}
}
if (pf_path != NULL) {
if (pf_open_errno != 0) {
cmdarg_err("Can't open your preferences file \"%s\": %s.", pf_path,
g_strerror(pf_open_errno));
}
if (pf_read_errno != 0) {
cmdarg_err("I/O error reading your preferences file \"%s\": %s.",
pf_path, g_strerror(pf_read_errno));
}
g_free(pf_path);
pf_path = NULL;
}
read_filter_list(CFILTER_LIST, &cf_path, &cf_open_errno);
if (cf_path != NULL) {
cmdarg_err("Could not open your capture filter file\n\"%s\": %s.",
cf_path, g_strerror(cf_open_errno));
g_free(cf_path);
}
read_disabled_protos_list(&gdp_path, &gdp_open_errno, &gdp_read_errno,
&dp_path, &dp_open_errno, &dp_read_errno);
read_disabled_heur_dissector_list(&gdp_path, &gdp_open_errno, &gdp_read_errno,
&dp_path, &dp_open_errno, &dp_read_errno);
if (gdp_path != NULL) {
if (gdp_open_errno != 0) {
cmdarg_err("Could not open global disabled protocols file\n\"%s\": %s.",
gdp_path, g_strerror(gdp_open_errno));
}
if (gdp_read_errno != 0) {
cmdarg_err("I/O error reading global disabled protocols file\n\"%s\": %s.",
gdp_path, g_strerror(gdp_read_errno));
}
g_free(gdp_path);
}
if (dp_path != NULL) {
if (dp_open_errno != 0) {
cmdarg_err(
"Could not open your disabled protocols file\n\"%s\": %s.", dp_path,
g_strerror(dp_open_errno));
}
if (dp_read_errno != 0) {
cmdarg_err(
"I/O error reading your disabled protocols file\n\"%s\": %s.", dp_path,
g_strerror(dp_read_errno));
}
g_free(dp_path);
}
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
case 'a':
case 'b':
case 'c':
case 'f':
case 'g':
case 'i':
case 'p':
#ifdef HAVE_PCAP_REMOTE
case 'A':
#endif
#ifdef HAVE_PCAP_CREATE
case 'I':
#endif
case 's':
case 'w':
case 'y':
case LONGOPT_NUM_CAP_COMMENT:
#ifdef CAN_SET_CAPTURE_BUFFER_SIZE
case 'B':
#endif
#ifdef HAVE_LIBPCAP
status = capture_opts_add_opt(&global_capture_opts, opt, optarg, &start_capture);
if (status != 0) {
return status;
}
#else
if (opt == 'w') {
output_file_name = optarg;
} else {
capture_option_specified = TRUE;
arg_error = TRUE;
}
#endif
break;
case 'C':
break;
case 'd':
if (!add_decode_as(optarg))
return 1;
break;
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
case 'K':
read_keytab_file(optarg);
break;
#endif
case 'D':
#ifdef HAVE_LIBPCAP
if_list = capture_interface_list(&err, &err_str,NULL);
if (if_list == NULL) {
if (err == 0)
cmdarg_err("There are no interfaces on which a capture can be done");
else {
cmdarg_err("%s", err_str);
g_free(err_str);
}
return 2;
}
capture_opts_print_interfaces(if_list);
free_interface_list(if_list);
return 0;
#else
capture_option_specified = TRUE;
arg_error = TRUE;
#endif
break;
case 'e':
output_fields_add(output_fields, optarg);
break;
case 'E':
if (!output_fields_set_option(output_fields, optarg)) {
cmdarg_err("\"%s\" is not a valid field output option=value pair.", optarg);
output_fields_list_options(stderr);
return 1;
}
break;
case 'F':
out_file_type = wtap_short_string_to_file_type_subtype(optarg);
if (out_file_type < 0) {
cmdarg_err("\"%s\" isn't a valid capture file type", optarg);
list_capture_types();
return 1;
}
break;
case 'W':
if (strchr(optarg, 'n')) {
out_file_name_res = TRUE;
} else {
cmdarg_err("Invalid -W argument \"%s\"; it must be one of:", optarg);
cmdarg_err_cont("\t'n' write network address resolution information (pcapng only)");
return 1;
}
break;
case 'H':
if (! add_hosts_file(optarg))
{
cmdarg_err("Can't read host entries from \"%s\"", optarg);
return 1;
}
out_file_name_res = TRUE;
break;
case 'h':
printf("TShark (Wireshark) %s\n"
"Dump and analyze network traffic.\n"
"See https://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
print_usage(stdout);
return 0;
break;
case 'l':
line_buffered = TRUE;
break;
case 'L':
#ifdef HAVE_LIBPCAP
list_link_layer_types = TRUE;
#else
capture_option_specified = TRUE;
arg_error = TRUE;
#endif
break;
case 'n':
disable_name_resolution();
break;
case 'N':
badopt = string_to_name_resolve(optarg, &gbl_resolv_flags);
if (badopt != '\0') {
cmdarg_err("-N specifies unknown resolving option '%c'; valid options are:",
badopt);
cmdarg_err_cont("\t'd' to enable address resolution from captured DNS packets\n"
"\t'm' to enable MAC address resolution\n"
"\t'n' to enable network address resolution\n"
"\t'N' to enable using external resolvers (e.g., DNS)\n"
"\t for network address resolution\n"
"\t't' to enable transport-layer port number resolution");
return 1;
}
break;
case 'o':
switch (prefs_set_pref(optarg)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
cmdarg_err("Invalid -o flag \"%s\"", optarg);
return 1;
break;
case PREFS_SET_NO_SUCH_PREF:
case PREFS_SET_OBSOLETE:
cmdarg_err("-o flag \"%s\" specifies unknown preference", optarg);
return 1;
break;
}
break;
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
case 'P':
break;
case 'S':
separator = optarg;
break;
case 't':
if (strcmp(optarg, "r") == 0)
timestamp_set_type(TS_RELATIVE);
else if (strcmp(optarg, "a") == 0)
timestamp_set_type(TS_ABSOLUTE);
else if (strcmp(optarg, "ad") == 0)
timestamp_set_type(TS_ABSOLUTE_WITH_YMD);
else if (strcmp(optarg, "adoy") == 0)
timestamp_set_type(TS_ABSOLUTE_WITH_YDOY);
else if (strcmp(optarg, "d") == 0)
timestamp_set_type(TS_DELTA);
else if (strcmp(optarg, "dd") == 0)
timestamp_set_type(TS_DELTA_DIS);
else if (strcmp(optarg, "e") == 0)
timestamp_set_type(TS_EPOCH);
else if (strcmp(optarg, "u") == 0)
timestamp_set_type(TS_UTC);
else if (strcmp(optarg, "ud") == 0)
timestamp_set_type(TS_UTC_WITH_YMD);
else if (strcmp(optarg, "udoy") == 0)
timestamp_set_type(TS_UTC_WITH_YDOY);
else {
cmdarg_err("Invalid time stamp type \"%s\"; it must be one of:", optarg);
cmdarg_err_cont("\t\"a\" for absolute\n"
"\t\"ad\" for absolute with YYYY-MM-DD date\n"
"\t\"adoy\" for absolute with YYYY/DOY date\n"
"\t\"d\" for delta\n"
"\t\"dd\" for delta displayed\n"
"\t\"e\" for epoch\n"
"\t\"r\" for relative\n"
"\t\"u\" for absolute UTC\n"
"\t\"ud\" for absolute UTC with YYYY-MM-DD date\n"
"\t\"udoy\" for absolute UTC with YYYY/DOY date");
return 1;
}
break;
case 'T':
print_packet_info = TRUE;
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
return 1;
}
break;
case 'u':
if (strcmp(optarg, "s") == 0)
timestamp_set_seconds_type(TS_SECONDS_DEFAULT);
else if (strcmp(optarg, "hms") == 0)
timestamp_set_seconds_type(TS_SECONDS_HOUR_MIN_SEC);
else {
cmdarg_err("Invalid seconds type \"%s\"; it must be one of:", optarg);
cmdarg_err_cont("\t\"s\" for seconds\n"
"\t\"hms\" for hours, minutes and seconds");
return 1;
}
break;
case 'U':
{
GSList *export_pdu_tap_name_list = NULL;
if (!*optarg) {
cmdarg_err("Tap name is required! Valid names are:");
for (export_pdu_tap_name_list = get_export_pdu_tap_list(); export_pdu_tap_name_list; export_pdu_tap_name_list = g_slist_next(export_pdu_tap_name_list)) {
cmdarg_err("%s\n", (const char*)(export_pdu_tap_name_list->data));
}
return 1;
}
pdu_export_arg = g_strdup(optarg);
break;
}
case 'v':
comp_info_str = get_compiled_version_info(get_tshark_compiled_version_info,
epan_get_compiled_version_info);
runtime_info_str = get_runtime_version_info(get_tshark_runtime_version_info);
show_version("TShark (Wireshark)", comp_info_str, runtime_info_str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
epan_cleanup();
return 0;
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
fprintf(stderr, "tshark: The available statistics for the \"-z\" option are:\n");
list_stat_cmd_args();
return 0;
}
if (!process_stat_cmd_arg(optarg)) {
cmdarg_err("Invalid -z argument \"%s\"; it must be one of:", optarg);
list_stat_cmd_args();
return 1;
}
break;
case LONGOPT_DISABLE_PROTOCOL:
disable_protocol_slist = g_slist_append(disable_protocol_slist, optarg);
break;
case LONGOPT_ENABLE_HEURISTIC:
enable_heur_slist = g_slist_append(enable_heur_slist, optarg);
break;
case LONGOPT_DISABLE_HEURISTIC:
disable_heur_slist = g_slist_append(disable_heur_slist, optarg);
break;
default:
case '?':
switch(optopt) {
case 'F':
list_capture_types();
break;
default:
print_usage(stderr);
}
return 1;
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
return 1;
}
if (optind < argc) {
if (cf_name != NULL) {
if (dfilter != NULL) {
cmdarg_err("Display filters were specified both with \"-d\" "
"and with additional command-line arguments.");
return 1;
}
dfilter = get_args_as_string(argc, argv, optind);
} else {
#ifdef HAVE_LIBPCAP
guint i;
if (global_capture_opts.default_options.cfilter) {
cmdarg_err("A default capture filter was specified both with \"-f\""
" and with additional command-line arguments.");
return 1;
}
for (i = 0; i < global_capture_opts.ifaces->len; i++) {
interface_options interface_opts;
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, i);
if (interface_opts.cfilter == NULL) {
interface_opts.cfilter = get_args_as_string(argc, argv, optind);
global_capture_opts.ifaces = g_array_remove_index(global_capture_opts.ifaces, i);
g_array_insert_val(global_capture_opts.ifaces, i, interface_opts);
} else {
cmdarg_err("A capture filter was specified both with \"-f\""
" and with additional command-line arguments.");
return 1;
}
}
global_capture_opts.default_options.cfilter = get_args_as_string(argc, argv, optind);
#else
capture_option_specified = TRUE;
#endif
}
}
#ifdef HAVE_LIBPCAP
if (!global_capture_opts.saving_to_file) {
if (!quiet)
print_packet_info = TRUE;
} else {
if (strcmp(global_capture_opts.save_file, "-") == 0 && print_packet_info) {
cmdarg_err("You can't write both raw packet data and dissected packets"
" to the standard output.");
return 1;
}
}
#else
if (!quiet)
print_packet_info = TRUE;
#endif
#ifndef HAVE_LIBPCAP
if (capture_option_specified)
cmdarg_err("This version of TShark was not built with support for capturing packets.");
#endif
if (arg_error) {
print_usage(stderr);
return 1;
}
if (print_hex) {
if (output_action != WRITE_TEXT) {
cmdarg_err("Raw packet hex data can only be printed as text or PostScript");
return 1;
}
}
if (output_only != NULL) {
char *ps;
if (!print_details) {
cmdarg_err("-O requires -V");
return 1;
}
output_only_tables = g_hash_table_new (g_str_hash, g_str_equal);
for (ps = strtok (output_only, ","); ps; ps = strtok (NULL, ",")) {
g_hash_table_insert(output_only_tables, (gpointer)ps, (gpointer)ps);
}
}
if (rfilter != NULL && !perform_two_pass_analysis) {
cmdarg_err("-R without -2 is deprecated. For single-pass filtering use -Y.");
return 1;
}
#ifdef HAVE_LIBPCAP
if (list_link_layer_types) {
if (cf_name) {
cmdarg_err("You can't specify -L and a capture file to be read.");
return 1;
}
if (global_capture_opts.multi_files_on) {
cmdarg_err("Ring buffer requested, but a capture isn't being done.");
return 1;
}
} else {
if (cf_name) {
if (global_capture_opts.default_options.cfilter) {
cmdarg_err("Only read filters, not capture filters, "
"can be specified when reading a capture file.");
return 1;
}
if (global_capture_opts.multi_files_on) {
cmdarg_err("Multiple capture files requested, but "
"a capture isn't being done.");
return 1;
}
if (global_capture_opts.has_file_duration) {
cmdarg_err("Switching capture files after a time interval was specified, but "
"a capture isn't being done.");
return 1;
}
if (global_capture_opts.has_ring_num_files) {
cmdarg_err("A ring buffer of capture files was specified, but "
"a capture isn't being done.");
return 1;
}
if (global_capture_opts.has_autostop_files) {
cmdarg_err("A maximum number of capture files was specified, but "
"a capture isn't being done.");
return 1;
}
if (global_capture_opts.capture_comment) {
cmdarg_err("A capture comment was specified, but "
"a capture isn't being done.\nThere's no support for adding "
"a capture comment to an existing capture file.");
return 1;
}
if (global_capture_opts.has_autostop_duration) {
cmdarg_err("A maximum capture time was specified, but "
"a capture isn't being done.");
return 1;
}
} else {
if (perform_two_pass_analysis) {
cmdarg_err("Live captures do not support two-pass analysis.");
return 1;
}
if (global_capture_opts.saving_to_file) {
if (out_file_type != WTAP_FILE_TYPE_SUBTYPE_PCAP &&
out_file_type != WTAP_FILE_TYPE_SUBTYPE_PCAPNG) {
cmdarg_err("Live captures can only be saved in pcap or pcapng format.");
return 1;
}
if (global_capture_opts.capture_comment &&
out_file_type != WTAP_FILE_TYPE_SUBTYPE_PCAPNG) {
cmdarg_err("A capture comment can only be written to a pcapng file.");
return 1;
}
if (global_capture_opts.multi_files_on) {
if (strcmp(global_capture_opts.save_file, "-") == 0) {
cmdarg_err("Multiple capture files requested, but "
"the capture is being written to the standard output.");
return 1;
}
if (global_capture_opts.output_to_pipe) {
cmdarg_err("Multiple capture files requested, but "
"the capture file is a pipe.");
return 1;
}
if (!global_capture_opts.has_autostop_filesize &&
!global_capture_opts.has_file_duration) {
cmdarg_err("Multiple capture files requested, but "
"no maximum capture file size or duration was specified.");
return 1;
}
}
if (rfilter != NULL) {
cmdarg_err("Read filters aren't supported when capturing and saving the captured packets.");
return 1;
}
if (dfilter != NULL) {
cmdarg_err("Display filters aren't supported when capturing and saving the captured packets.");
return 1;
}
global_capture_opts.use_pcapng = (out_file_type == WTAP_FILE_TYPE_SUBTYPE_PCAPNG) ? TRUE : FALSE;
} else {
if (global_capture_opts.has_autostop_filesize) {
cmdarg_err("Maximum capture file size specified, but "
"capture isn't being saved to a file.");
return 1;
}
if (global_capture_opts.multi_files_on) {
cmdarg_err("Multiple capture files requested, but "
"the capture isn't being saved to a file.");
return 1;
}
if (global_capture_opts.capture_comment) {
cmdarg_err("A capture comment was specified, but "
"the capture isn't being saved to a file.");
return 1;
}
}
}
}
#endif
#ifdef _WIN32
WSAStartup( MAKEWORD( 1, 1 ), &wsaData );
#endif
prefs_apply_all();
start_requested_stats();
{
GSList* it = NULL;
GSList *invalid_fields = output_fields_valid(output_fields);
if (invalid_fields != NULL) {
cmdarg_err("Some fields aren't valid:");
for (it=invalid_fields; it != NULL; it = g_slist_next(it)) {
cmdarg_err_cont("\t%s", (gchar *)it->data);
}
g_slist_free(invalid_fields);
return 1;
}
}
#ifdef HAVE_LIBPCAP
if (global_capture_opts.saving_to_file &&
global_capture_opts.output_to_pipe) {
if (tap_listeners_require_dissection()) {
cmdarg_err("Taps aren't supported when saving to a pipe.");
return 1;
}
if (print_packet_info) {
cmdarg_err("Printing dissected packets isn't supported when saving to a pipe.");
return 1;
}
}
#endif
if (ex_opt_count("read_format") > 0) {
const gchar* name = ex_opt_get_next("read_format");
in_file_type = open_info_name_to_type(name);
if (in_file_type == WTAP_TYPE_AUTO) {
cmdarg_err("\"%s\" isn't a valid read file format type", name? name : "");
list_read_capture_types();
return 1;
}
}
if (gdp_path == NULL && dp_path == NULL) {
set_disabled_protos_list();
set_disabled_heur_dissector_list();
}
if(disable_protocol_slist) {
GSList *proto_disable;
for (proto_disable = disable_protocol_slist; proto_disable != NULL; proto_disable = g_slist_next(proto_disable))
{
proto_disable_proto_by_name((char*)proto_disable->data);
}
}
if(enable_heur_slist) {
GSList *heur_enable;
for (heur_enable = enable_heur_slist; heur_enable != NULL; heur_enable = g_slist_next(heur_enable))
{
proto_enable_heuristic_by_name((char*)heur_enable->data, TRUE);
}
}
if(disable_heur_slist) {
GSList *heur_disable;
for (heur_disable = disable_heur_slist; heur_disable != NULL; heur_disable = g_slist_next(heur_disable))
{
proto_enable_heuristic_by_name((char*)heur_disable->data, FALSE);
}
}
build_column_format_array(&cfile.cinfo, prefs_p->num_cols, TRUE);
#ifdef HAVE_LIBPCAP
capture_opts_trim_snaplen(&global_capture_opts, MIN_PACKET_SIZE);
capture_opts_trim_ring_num_files(&global_capture_opts);
#endif
if (rfilter != NULL) {
tshark_debug("Compiling read filter: '%s'", rfilter);
if (!dfilter_compile(rfilter, &rfcode, &err_msg)) {
cmdarg_err("%s", err_msg);
g_free(err_msg);
epan_cleanup();
#ifdef HAVE_PCAP_OPEN_DEAD
{
pcap_t *pc;
pc = pcap_open_dead(DLT_EN10MB, MIN_PACKET_SIZE);
if (pc != NULL) {
if (pcap_compile(pc, &fcode, rfilter, 0, 0) != -1) {
cmdarg_err_cont(
" Note: That read filter code looks like a valid capture filter;\n"
" maybe you mixed them up?");
}
pcap_close(pc);
}
}
#endif
return 2;
}
}
cfile.rfcode = rfcode;
if (dfilter != NULL) {
tshark_debug("Compiling display filter: '%s'", dfilter);
if (!dfilter_compile(dfilter, &dfcode, &err_msg)) {
cmdarg_err("%s", err_msg);
g_free(err_msg);
epan_cleanup();
#ifdef HAVE_PCAP_OPEN_DEAD
{
pcap_t *pc;
pc = pcap_open_dead(DLT_EN10MB, MIN_PACKET_SIZE);
if (pc != NULL) {
if (pcap_compile(pc, &fcode, dfilter, 0, 0) != -1) {
cmdarg_err_cont(
" Note: That display filter code looks like a valid capture filter;\n"
" maybe you mixed them up?");
}
pcap_close(pc);
}
}
#endif
return 2;
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
if (pdu_export_arg) {
const char *exp_pdu_filename;
const char *exp_pdu_tap_name = pdu_export_arg;
const char *exp_pdu_filter = dfilter;
char *exp_pdu_error;
int exp_fd;
if (!cf_name) {
cmdarg_err("PDUs export requires a capture file (specify with -r).");
return 1;
}
#ifdef HAVE_LIBPCAP
exp_pdu_filename = global_capture_opts.save_file;
global_capture_opts.save_file = NULL;
#else
exp_pdu_filename = output_file_name;
output_file_name = NULL;
#endif
if (exp_pdu_filename == NULL) {
cmdarg_err("PDUs export requires an output file (-w).");
return 1;
}
exp_pdu_error = exp_pdu_pre_open(exp_pdu_tap_name, exp_pdu_filter,
&exp_pdu_tap_data);
if (exp_pdu_error) {
cmdarg_err("Cannot register tap: %s", exp_pdu_error);
g_free(exp_pdu_error);
return 2;
}
exp_fd = ws_open(exp_pdu_filename, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0644);
if (exp_fd == -1) {
cmdarg_err("%s: %s", exp_pdu_filename, file_open_error_message(errno, TRUE));
return 2;
}
err = exp_pdu_open(&exp_pdu_tap_data, exp_fd,
g_strdup_printf("Dump of PDUs from %s", cf_name));
if (err != 0) {
cmdarg_err("Failed to start the PDU export: %s", g_strerror(err));
return 2;
}
}
do_dissection = print_packet_info || rfcode || dfcode || pdu_export_arg ||
tap_listeners_require_dissection();
tshark_debug("tshark: do_dissection = %s", do_dissection ? "TRUE" : "FALSE");
if (cf_name) {
tshark_debug("tshark: Opening capture file: %s", cf_name);
if (cf_open(&cfile, cf_name, in_file_type, FALSE, &err) != CF_OK) {
epan_cleanup();
return 2;
}
tshark_debug("tshark: invoking load_cap_file() to process the packets");
TRY {
#ifdef HAVE_LIBPCAP
err = load_cap_file(&cfile, global_capture_opts.save_file, out_file_type, out_file_name_res,
global_capture_opts.has_autostop_packets ? global_capture_opts.autostop_packets : 0,
global_capture_opts.has_autostop_filesize ? global_capture_opts.autostop_filesize : 0);
#else
err = load_cap_file(&cfile, output_file_name, out_file_type, out_file_name_res, 0, 0);
#endif
}
CATCH(OutOfMemoryError) {
fprintf(stderr,
"Out Of Memory.\n"
"\n"
"Sorry, but TShark has to terminate now.\n"
"\n"
"More information and workarounds can be found at\n"
"https://wiki.wireshark.org/KnownBugs/OutOfMemory\n");
err = ENOMEM;
}
ENDTRY;
if (err != 0) {
exit_status = 2;
}
if (pdu_export_arg) {
err = exp_pdu_close(&exp_pdu_tap_data);
if (err) {
cmdarg_err("%s", wtap_strerror(err));
exit_status = 2;
}
g_free(pdu_export_arg);
}
} else {
tshark_debug("tshark: no capture file specified");
#ifdef HAVE_LIBPCAP
exit_status = capture_opts_default_iface_if_necessary(&global_capture_opts,
((prefs_p->capture_device) && (*prefs_p->capture_device != '\0')) ? get_if_name(prefs_p->capture_device) : NULL);
if (exit_status != 0)
return exit_status;
if (list_link_layer_types) {
guint i;
for (i = 0; i < global_capture_opts.ifaces->len; i++) {
interface_options interface_opts;
if_capabilities_t *caps;
char *auth_str = NULL;
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, i);
#ifdef HAVE_PCAP_REMOTE
if (interface_opts.auth_type == CAPTURE_AUTH_PWD) {
auth_str = g_strdup_printf("%s:%s", interface_opts.auth_username, interface_opts.auth_password);
}
#endif
caps = capture_get_if_capabilities(interface_opts.name, interface_opts.monitor_mode, auth_str, &err_str, NULL);
g_free(auth_str);
if (caps == NULL) {
cmdarg_err("%s", err_str);
g_free(err_str);
return 2;
}
if (caps->data_link_types == NULL) {
cmdarg_err("The capture device \"%s\" has no data link types.", interface_opts.name);
return 2;
}
capture_opts_print_if_capabilities(caps, interface_opts.name, interface_opts.monitor_mode);
free_if_capabilities(caps);
}
return 0;
}
if (!ws_isatty(ws_fileno(stderr)))
print_packet_counts = FALSE;
else if (print_packet_info && ws_isatty(ws_fileno(stdout)))
print_packet_counts = FALSE;
else if (quiet)
print_packet_counts = FALSE;
else
print_packet_counts = TRUE;
if (print_packet_info) {
if (!write_preamble(&cfile)) {
show_print_file_io_error(errno);
return 2;
}
}
tshark_debug("tshark: performing live capture");
capture();
exit_status = global_capture_session.fork_child_status;
if (print_packet_info) {
if (!write_finale()) {
err = errno;
show_print_file_io_error(err);
}
}
#else
cmdarg_err("This version of TShark was not built with support for capturing packets.");
return 2;
#endif
}
g_free(cf_name);
if (cfile.frames != NULL) {
free_frame_data_sequence(cfile.frames);
cfile.frames = NULL;
}
draw_tap_listeners(TRUE);
funnel_dump_all_text_windows();
epan_free(cfile.epan);
epan_cleanup();
output_fields_free(output_fields);
output_fields = NULL;
return exit_status;
}
static gint
pipe_timer_cb(gpointer data)
{
HANDLE handle;
DWORD avail = 0;
gboolean result;
DWORD childstatus;
pipe_input_t *pipe_input_p = data;
gint iterations = 0;
g_mutex_lock (pipe_input_p->callback_running);
while(iterations < 5) {
handle = (HANDLE) _get_osfhandle (pipe_input_p->source);
result = PeekNamedPipe(handle, NULL, 0, NULL, &avail, NULL);
GetExitCodeProcess((HANDLE)*(pipe_input_p->child_process),
&childstatus);
if (!result || avail > 0 || childstatus != STILL_ACTIVE) {
if (!pipe_input_p->input_cb(pipe_input_p->source, pipe_input_p->user_data)) {
g_log(NULL, G_LOG_LEVEL_DEBUG, "pipe_timer_cb: input pipe closed, iterations: %u", iterations);
g_mutex_unlock (pipe_input_p->callback_running);
return FALSE;
}
}
else {
break;
}
iterations++;
}
g_mutex_unlock (pipe_input_p->callback_running);
return TRUE;
}
void
pipe_input_set_handler(gint source, gpointer user_data, ws_process_id *child_process, pipe_input_cb_t input_cb)
{
pipe_input.source = source;
pipe_input.child_process = child_process;
pipe_input.user_data = user_data;
pipe_input.input_cb = input_cb;
#ifdef _WIN32
#if GLIB_CHECK_VERSION(2,31,0)
pipe_input.callback_running = g_malloc(sizeof(GMutex));
g_mutex_init(pipe_input.callback_running);
#else
pipe_input.callback_running = g_mutex_new();
#endif
pipe_input.pipe_input_id = g_timeout_add(200, pipe_timer_cb, &pipe_input);
#endif
}
static const nstime_t *
tshark_get_frame_ts(void *data, guint32 frame_num)
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
static epan_t *
tshark_epan_new(capture_file *cf)
{
epan_t *epan = epan_new();
epan->data = cf;
epan->get_frame_ts = tshark_get_frame_ts;
epan->get_interface_name = cap_file_get_interface_name;
epan->get_user_comment = NULL;
return epan;
}
static gboolean
capture(void)
{
gboolean ret;
guint i;
GString *str;
#ifdef USE_TSHARK_SELECT
fd_set readfds;
#endif
#ifndef _WIN32
struct sigaction action, oldaction;
#endif
epan_free(cfile.epan);
cfile.epan = tshark_epan_new(&cfile);
#ifdef _WIN32
SetConsoleCtrlHandler(capture_cleanup, TRUE);
#else
memset(&action, 0, sizeof(action));
action.sa_handler = capture_cleanup;
action.sa_flags = SA_RESTART;
sigemptyset(&action.sa_mask);
sigaction(SIGTERM, &action, NULL);
sigaction(SIGINT, &action, NULL);
sigaction(SIGHUP, NULL, &oldaction);
if (oldaction.sa_handler == SIG_DFL)
sigaction(SIGHUP, &action, NULL);
#ifdef SIGINFO
action.sa_handler = report_counts_siginfo;
action.sa_flags = SA_RESTART;
sigemptyset(&action.sa_mask);
sigaction(SIGINFO, &action, NULL);
#endif
#endif
global_capture_session.state = CAPTURE_PREPARING;
for (i = 0; i < global_capture_opts.ifaces->len; i++) {
interface_options interface_opts;
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, i);
interface_opts.descr = get_interface_descriptive_name(interface_opts.name);
global_capture_opts.ifaces = g_array_remove_index(global_capture_opts.ifaces, i);
g_array_insert_val(global_capture_opts.ifaces, i, interface_opts);
}
str = get_iface_list_string(&global_capture_opts, IFLIST_QUOTE_IF_DESCRIPTION);
if (really_quiet == FALSE)
fprintf(stderr, "Capturing on %s\n", str->str);
fflush(stderr);
g_string_free(str, TRUE);
ret = sync_pipe_start(&global_capture_opts, &global_capture_session, &global_info_data, NULL);
if (!ret)
return FALSE;
#ifdef USE_TSHARK_SELECT
FD_ZERO(&readfds);
FD_SET(pipe_input.source, &readfds);
#endif
loop_running = TRUE;
TRY
{
while (loop_running)
{
#ifdef USE_TSHARK_SELECT
ret = select(pipe_input.source+1, &readfds, NULL, NULL, NULL);
if (ret == -1)
{
fprintf(stderr, "%s: %s\n", "select()", g_strerror(errno));
return TRUE;
} else if (ret == 1) {
#endif
if (!pipe_input.input_cb(pipe_input.source, pipe_input.user_data)) {
g_log(NULL, G_LOG_LEVEL_DEBUG, "input pipe closed");
return FALSE;
}
#ifdef USE_TSHARK_SELECT
}
#endif
}
}
CATCH(OutOfMemoryError) {
fprintf(stderr,
"Out Of Memory.\n"
"\n"
"Sorry, but TShark has to terminate now.\n"
"\n"
"More information and workarounds can be found at\n"
"https://wiki.wireshark.org/KnownBugs/OutOfMemory\n");
exit(1);
}
ENDTRY;
return TRUE;
}
void
capture_input_error_message(capture_session *cap_session _U_, char *error_msg, char *secondary_error_msg)
{
cmdarg_err("%s", error_msg);
cmdarg_err_cont("%s", secondary_error_msg);
}
void
capture_input_cfilter_error_message(capture_session *cap_session, guint i, char *error_message)
{
capture_options *capture_opts = cap_session->capture_opts;
dfilter_t *rfcode = NULL;
interface_options interface_opts;
g_assert(i < capture_opts->ifaces->len);
interface_opts = g_array_index(capture_opts->ifaces, interface_options, i);
if (dfilter_compile(interface_opts.cfilter, &rfcode, NULL) && rfcode != NULL) {
cmdarg_err(
"Invalid capture filter \"%s\" for interface '%s'.\n"
"\n"
"That string looks like a valid display filter; however, it isn't a valid\n"
"capture filter (%s).\n"
"\n"
"Note that display filters and capture filters don't have the same syntax,\n"
"so you can't use most display filter expressions as capture filters.\n"
"\n"
"See the User's Guide for a description of the capture filter syntax.",
interface_opts.cfilter, interface_opts.descr, error_message);
dfilter_free(rfcode);
} else {
cmdarg_err(
"Invalid capture filter \"%s\" for interface '%s'.\n"
"\n"
"That string isn't a valid capture filter (%s).\n"
"See the User's Guide for a description of the capture filter syntax.",
interface_opts.cfilter, interface_opts.descr, error_message);
}
}
gboolean
capture_input_new_file(capture_session *cap_session, gchar *new_file)
{
capture_options *capture_opts = cap_session->capture_opts;
capture_file *cf = (capture_file *) cap_session->cf;
gboolean is_tempfile;
int err;
if (cap_session->state == CAPTURE_PREPARING) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture started.");
}
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "File: \"%s\"", new_file);
g_assert(cap_session->state == CAPTURE_PREPARING || cap_session->state == CAPTURE_RUNNING);
if (capture_opts->save_file != NULL) {
if (cf->state != FILE_CLOSED) {
if (cf->wth != NULL) {
wtap_close(cf->wth);
cf->wth = NULL;
}
cf->state = FILE_CLOSED;
}
g_free(capture_opts->save_file);
is_tempfile = FALSE;
epan_free(cf->epan);
cf->epan = tshark_epan_new(cf);
} else {
is_tempfile = TRUE;
}
capture_opts->save_file = g_strdup(new_file);
if (do_dissection) {
((capture_file *)cap_session->cf)->open_type = WTAP_TYPE_AUTO;
switch(cf_open((capture_file *)cap_session->cf, capture_opts->save_file, WTAP_TYPE_AUTO, is_tempfile, &err)) {
case CF_OK:
break;
case CF_ERROR:
g_free(capture_opts->save_file);
capture_opts->save_file = NULL;
return FALSE;
}
}
cap_session->state = CAPTURE_RUNNING;
return TRUE;
}
void
capture_input_new_packets(capture_session *cap_session, int to_read)
{
gboolean ret;
int err;
gchar *err_info;
gint64 data_offset;
capture_file *cf = (capture_file *)cap_session->cf;
gboolean filtering_tap_listeners;
guint tap_flags;
#ifdef SIGINFO
infodelay = TRUE;
#endif
filtering_tap_listeners = have_filtering_tap_listeners();
tap_flags = union_of_tap_listener_flags();
if (do_dissection) {
gboolean create_proto_tree;
epan_dissect_t *edt;
if (cf->rfcode || cf->dfcode || print_details || filtering_tap_listeners ||
(tap_flags & TL_REQUIRES_PROTO_TREE) || have_custom_cols(&cf->cinfo))
create_proto_tree = TRUE;
else
create_proto_tree = FALSE;
edt = epan_dissect_new(cf->epan, create_proto_tree, print_packet_info && print_details);
while (to_read-- && cf->wth) {
wtap_cleareof(cf->wth);
ret = wtap_read(cf->wth, &err, &err_info, &data_offset);
if (ret == FALSE) {
sync_pipe_stop(cap_session);
wtap_close(cf->wth);
cf->wth = NULL;
} else {
ret = process_packet(cf, edt, data_offset, wtap_phdr(cf->wth),
wtap_buf_ptr(cf->wth),
tap_flags);
}
if (ret != FALSE) {
packet_count++;
}
}
epan_dissect_free(edt);
} else {
packet_count += to_read;
}
if (print_packet_counts) {
if (packet_count != 0) {
fprintf(stderr, "\r%u ", packet_count);
fflush(stderr);
}
}
#ifdef SIGINFO
infodelay = FALSE;
if (infoprint)
report_counts();
#endif
}
static void
report_counts(void)
{
if ((print_packet_counts == FALSE) && (really_quiet == FALSE)) {
fprintf(stderr, "%u packet%s captured\n", packet_count,
plurality(packet_count, "", "s"));
}
#ifdef SIGINFO
infoprint = FALSE;
#endif
}
static void
report_counts_siginfo(int signum _U_)
{
int sav_errno = errno;
if (infodelay)
infoprint = TRUE;
else
report_counts();
errno = sav_errno;
}
void
capture_input_drops(capture_session *cap_session _U_, guint32 dropped)
{
if (print_packet_counts) {
fprintf(stderr, "\n");
}
if (dropped != 0) {
fprintf(stderr, "%u packet%s dropped\n", dropped, plurality(dropped, "", "s"));
}
}
void
capture_input_closed(capture_session *cap_session, gchar *msg)
{
capture_file *cf = (capture_file *) cap_session->cf;
if (msg != NULL)
fprintf(stderr, "tshark: %s\n", msg);
report_counts();
if (cf != NULL && cf->wth != NULL) {
wtap_close(cf->wth);
if (cf->is_tempfile) {
ws_unlink(cf->filename);
}
}
#ifdef USE_BROKEN_G_MAIN_LOOP
g_main_loop_quit(loop);
#else
loop_running = FALSE;
#endif
}
static BOOL WINAPI
capture_cleanup(DWORD ctrltype _U_)
{
sync_pipe_stop(&global_capture_session);
return TRUE;
}
static void
capture_cleanup(int signum _U_)
{
sync_pipe_stop(&global_capture_session);
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
if (gbl_resolv_flags.mac_name || gbl_resolv_flags.network_name ||
gbl_resolv_flags.transport_name)
host_name_lookup_process();
if (cf->rfcode)
epan_dissect_prime_dfilter(edt, cf->rfcode);
if (cf->dfcode)
epan_dissect_prime_dfilter(edt, cf->dfcode);
frame_data_set_before_dissect(&fdlocal, &cf->elapsed_time,
&ref, prev_dis);
if (ref == &fdlocal) {
ref_frame = fdlocal;
ref = &ref_frame;
}
epan_dissect_run(edt, cf->cd_t, whdr, frame_tvbuff_new(&fdlocal, pd), &fdlocal, NULL);
if (cf->rfcode)
passed = dfilter_apply_edt(cf->rfcode, edt);
}
if (passed) {
frame_data_set_after_dissect(&fdlocal, &cum_bytes);
prev_cap = prev_dis = frame_data_sequence_add(cf->frames, &fdlocal);
if (edt && cf->dfcode) {
if (dfilter_apply_edt(cf->dfcode, edt)) {
g_slist_foreach(edt->pi.dependent_frames, find_and_mark_frame_depended_upon, cf->frames);
}
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
process_packet_second_pass(capture_file *cf, epan_dissect_t *edt, frame_data *fdata,
struct wtap_pkthdr *phdr, Buffer *buf,
guint tap_flags)
{
column_info *cinfo;
gboolean passed;
passed = TRUE;
if (edt) {
if (gbl_resolv_flags.mac_name || gbl_resolv_flags.network_name ||
gbl_resolv_flags.transport_name)
host_name_lookup_process();
if (cf->dfcode)
epan_dissect_prime_dfilter(edt, cf->dfcode);
col_custom_prime_edt(edt, &cf->cinfo);
if ((tap_flags & TL_REQUIRES_COLUMNS) || (print_packet_info && print_summary) || output_fields_has_cols(output_fields))
cinfo = &cf->cinfo;
else
cinfo = NULL;
frame_data_set_before_dissect(fdata, &cf->elapsed_time,
&ref, prev_dis);
if (ref == fdata) {
ref_frame = *fdata;
ref = &ref_frame;
}
epan_dissect_run_with_taps(edt, cf->cd_t, phdr, frame_tvbuff_new_buffer(fdata, buf), fdata, cinfo);
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
exit(2);
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
static int
load_cap_file(capture_file *cf, char *save_file, int out_file_type,
gboolean out_file_name_res, int max_packet_count, gint64 max_byte_count)
{
gint linktype;
int snapshot_length;
wtap_dumper *pdh;
guint32 framenum;
int err;
gchar *err_info = NULL;
gint64 data_offset;
char *save_file_string = NULL;
gboolean filtering_tap_listeners;
guint tap_flags;
GArray *shb_hdrs = NULL;
wtapng_iface_descriptions_t *idb_inf = NULL;
GArray *nrb_hdrs = NULL;
struct wtap_pkthdr phdr;
Buffer buf;
epan_dissect_t *edt = NULL;
char *shb_user_appl;
wtap_phdr_init(&phdr);
idb_inf = wtap_file_get_idb_info(cf->wth);
#ifdef PCAP_NG_DEFAULT
if (idb_inf->interface_data->len > 1) {
linktype = WTAP_ENCAP_PER_PACKET;
} else {
linktype = wtap_file_encap(cf->wth);
}
#else
linktype = wtap_file_encap(cf->wth);
#endif
if (save_file != NULL) {
save_file_string = output_file_description(save_file);
snapshot_length = wtap_snapshot_length(cf->wth);
if (snapshot_length == 0) {
snapshot_length = WTAP_MAX_PACKET_SIZE;
}
tshark_debug("tshark: snapshot_length = %d", snapshot_length);
shb_hdrs = wtap_file_get_shb_for_new_file(cf->wth);
nrb_hdrs = wtap_file_get_nrb_for_new_file(cf->wth);
wtap_optionblock_get_option_string(g_array_index(shb_hdrs, wtap_optionblock_t, 0), OPT_SHB_USERAPPL, &shb_user_appl);
if (shb_user_appl == NULL) {
wtap_optionblock_set_option_string_format(g_array_index(shb_hdrs, wtap_optionblock_t, 0), OPT_SHB_USERAPPL, "TShark (Wireshark) %s", get_ws_vcs_version_info());
}
if (linktype != WTAP_ENCAP_PER_PACKET &&
out_file_type == WTAP_FILE_TYPE_SUBTYPE_PCAP) {
tshark_debug("tshark: writing PCAP format to %s", save_file);
if (strcmp(save_file, "-") == 0) {
pdh = wtap_dump_open_stdout(out_file_type, linktype,
snapshot_length, FALSE , &err);
} else {
pdh = wtap_dump_open(save_file, out_file_type, linktype,
snapshot_length, FALSE , &err);
}
}
else {
tshark_debug("tshark: writing format type %d, to %s", out_file_type, save_file);
if (strcmp(save_file, "-") == 0) {
pdh = wtap_dump_open_stdout_ng(out_file_type, linktype,
snapshot_length, FALSE , shb_hdrs, idb_inf, nrb_hdrs, &err);
} else {
pdh = wtap_dump_open_ng(save_file, out_file_type, linktype,
snapshot_length, FALSE , shb_hdrs, idb_inf, nrb_hdrs, &err);
}
}
g_free(idb_inf);
idb_inf = NULL;
if (pdh == NULL) {
switch (err) {
case WTAP_ERR_UNWRITABLE_FILE_TYPE:
cmdarg_err("Capture files can't be written in that format.");
break;
case WTAP_ERR_UNWRITABLE_ENCAP:
case WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED:
cmdarg_err("The capture file being read can't be written as a "
"\"%s\" file.", wtap_file_type_subtype_short_string(out_file_type));
break;
case WTAP_ERR_CANT_OPEN:
cmdarg_err("The %s couldn't be created for some "
"unknown reason.", save_file_string);
break;
case WTAP_ERR_SHORT_WRITE:
cmdarg_err("A full header couldn't be written to the %s.",
save_file_string);
break;
default:
cmdarg_err("The %s could not be created: %s.", save_file_string,
wtap_strerror(err));
break;
}
goto out;
}
} else {
if (print_packet_info) {
if (!write_preamble(cf)) {
err = errno;
show_print_file_io_error(err);
goto out;
}
}
g_free(idb_inf);
idb_inf = NULL;
pdh = NULL;
}
filtering_tap_listeners = have_filtering_tap_listeners();
tap_flags = union_of_tap_listener_flags();
if (perform_two_pass_analysis) {
frame_data *fdata;
tshark_debug("tshark: perform_two_pass_analysis, do_dissection=%s", do_dissection ? "TRUE" : "FALSE");
cf->frames = new_frame_data_sequence();
if (do_dissection) {
gboolean create_proto_tree = FALSE;
if (cf->rfcode || cf->dfcode)
create_proto_tree = TRUE;
tshark_debug("tshark: create_proto_tree = %s", create_proto_tree ? "TRUE" : "FALSE");
edt = epan_dissect_new(cf->epan, create_proto_tree, FALSE);
}
tshark_debug("tshark: reading records for first pass");
while (wtap_read(cf->wth, &err, &err_info, &data_offset)) {
if (process_packet_first_pass(cf, edt, data_offset, wtap_phdr(cf->wth),
wtap_buf_ptr(cf->wth))) {
if ( (--max_packet_count == 0) || (max_byte_count != 0 && data_offset >= max_byte_count)) {
tshark_debug("tshark: max_packet_count (%d) or max_byte_count (%" G_GINT64_MODIFIER "d/%" G_GINT64_MODIFIER "d) reached",
max_packet_count, data_offset, max_byte_count);
err = 0;
break;
}
}
}
if (edt) {
epan_dissect_free(edt);
edt = NULL;
}
wtap_sequential_close(cf->wth);
postseq_cleanup_all_protocols();
prev_dis = NULL;
prev_cap = NULL;
ws_buffer_init(&buf, 1500);
tshark_debug("tshark: done with first pass");
if (do_dissection) {
gboolean create_proto_tree;
if (cf->dfcode || print_details || filtering_tap_listeners ||
(tap_flags & TL_REQUIRES_PROTO_TREE) || have_custom_cols(&cf->cinfo))
create_proto_tree = TRUE;
else
create_proto_tree = FALSE;
tshark_debug("tshark: create_proto_tree = %s", create_proto_tree ? "TRUE" : "FALSE");
edt = epan_dissect_new(cf->epan, create_proto_tree, print_packet_info && print_details);
}
for (framenum = 1; err == 0 && framenum <= cf->count; framenum++) {
fdata = frame_data_sequence_find(cf->frames, framenum);
if (wtap_seek_read(cf->wth, fdata->file_off, &phdr, &buf, &err,
&err_info)) {
tshark_debug("tshark: invoking process_packet_second_pass() for frame #%d", framenum);
if (process_packet_second_pass(cf, edt, fdata, &phdr, &buf,
tap_flags)) {
if (pdh != NULL) {
tshark_debug("tshark: writing packet #%d to outfile", framenum);
if (!wtap_dump(pdh, &phdr, ws_buffer_start_ptr(&buf), &err, &err_info)) {
tshark_debug("tshark: error writing to a capture file (%d)", err);
switch (err) {
case WTAP_ERR_UNWRITABLE_ENCAP:
fprintf(stderr,
"Frame %u of \"%s\" has a network type that can't be saved in a \"%s\" file.\n",
framenum, cf->filename,
wtap_file_type_subtype_short_string(out_file_type));
break;
case WTAP_ERR_PACKET_TOO_LARGE:
fprintf(stderr,
"Frame %u of \"%s\" is too large for a \"%s\" file.\n",
framenum, cf->filename,
wtap_file_type_subtype_short_string(out_file_type));
break;
case WTAP_ERR_UNWRITABLE_REC_TYPE:
fprintf(stderr,
"Record %u of \"%s\" has a record type that can't be saved in a \"%s\" file.\n",
framenum, cf->filename,
wtap_file_type_subtype_short_string(out_file_type));
break;
case WTAP_ERR_UNWRITABLE_REC_DATA:
fprintf(stderr,
"Record %u of \"%s\" has data that can't be saved in a \"%s\" file.\n(%s)\n",
framenum, cf->filename,
wtap_file_type_subtype_short_string(out_file_type),
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
show_capture_file_io_error(save_file, err, FALSE);
break;
}
wtap_dump_close(pdh, &err);
wtap_optionblock_array_free(shb_hdrs);
wtap_optionblock_array_free(nrb_hdrs);
exit(2);
}
}
}
}
}
if (edt) {
epan_dissect_free(edt);
edt = NULL;
}
ws_buffer_free(&buf);
tshark_debug("tshark: done with second pass");
}
else {
framenum = 0;
tshark_debug("tshark: perform one pass analysis, do_dissection=%s", do_dissection ? "TRUE" : "FALSE");
if (do_dissection) {
gboolean create_proto_tree;
if (cf->rfcode || cf->dfcode || print_details || filtering_tap_listeners ||
(tap_flags & TL_REQUIRES_PROTO_TREE) || have_custom_cols(&cf->cinfo))
create_proto_tree = TRUE;
else
create_proto_tree = FALSE;
tshark_debug("tshark: create_proto_tree = %s", create_proto_tree ? "TRUE" : "FALSE");
edt = epan_dissect_new(cf->epan, create_proto_tree, print_packet_info && print_details);
}
while (wtap_read(cf->wth, &err, &err_info, &data_offset)) {
framenum++;
tshark_debug("tshark: processing packet #%d", framenum);
if (process_packet(cf, edt, data_offset, wtap_phdr(cf->wth),
wtap_buf_ptr(cf->wth),
tap_flags)) {
if (pdh != NULL) {
tshark_debug("tshark: writing packet #%d to outfile", framenum);
if (!wtap_dump(pdh, wtap_phdr(cf->wth), wtap_buf_ptr(cf->wth), &err, &err_info)) {
tshark_debug("tshark: error writing to a capture file (%d)", err);
switch (err) {
case WTAP_ERR_UNWRITABLE_ENCAP:
fprintf(stderr,
"Frame %u of \"%s\" has a network type that can't be saved in a \"%s\" file.\n",
framenum, cf->filename,
wtap_file_type_subtype_short_string(out_file_type));
break;
case WTAP_ERR_PACKET_TOO_LARGE:
fprintf(stderr,
"Frame %u of \"%s\" is too large for a \"%s\" file.\n",
framenum, cf->filename,
wtap_file_type_subtype_short_string(out_file_type));
break;
case WTAP_ERR_UNWRITABLE_REC_TYPE:
fprintf(stderr,
"Record %u of \"%s\" has a record type that can't be saved in a \"%s\" file.\n",
framenum, cf->filename,
wtap_file_type_subtype_short_string(out_file_type));
break;
case WTAP_ERR_UNWRITABLE_REC_DATA:
fprintf(stderr,
"Record %u of \"%s\" has data that can't be saved in a \"%s\" file.\n(%s)\n",
framenum, cf->filename,
wtap_file_type_subtype_short_string(out_file_type),
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
show_capture_file_io_error(save_file, err, FALSE);
break;
}
wtap_dump_close(pdh, &err);
wtap_optionblock_array_free(shb_hdrs);
wtap_optionblock_array_free(nrb_hdrs);
exit(2);
}
}
}
if ( (--max_packet_count == 0) || (max_byte_count != 0 && data_offset >= max_byte_count)) {
tshark_debug("tshark: max_packet_count (%d) or max_byte_count (%" G_GINT64_MODIFIER "d/%" G_GINT64_MODIFIER "d) reached",
max_packet_count, data_offset, max_byte_count);
err = 0;
break;
}
}
if (edt) {
epan_dissect_free(edt);
edt = NULL;
}
}
wtap_phdr_cleanup(&phdr);
if (err != 0) {
tshark_debug("tshark: something failed along the line (%d)", err);
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
switch (err) {
case WTAP_ERR_UNSUPPORTED:
cmdarg_err("The file \"%s\" contains record data that TShark doesn't support.\n(%s)",
cf->filename,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_SHORT_READ:
cmdarg_err("The file \"%s\" appears to have been cut short in the middle of a packet.",
cf->filename);
break;
case WTAP_ERR_BAD_FILE:
cmdarg_err("The file \"%s\" appears to be damaged or corrupt.\n(%s)",
cf->filename,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
case WTAP_ERR_DECOMPRESS:
cmdarg_err("The compressed file \"%s\" appears to be damaged or corrupt.\n"
"(%s)", cf->filename,
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
break;
default:
cmdarg_err("An error occurred while reading the file \"%s\": %s.",
cf->filename, wtap_strerror(err));
break;
}
if (save_file != NULL) {
if (!wtap_dump_close(pdh, &err))
show_capture_file_io_error(save_file, err, TRUE);
}
} else {
if (save_file != NULL) {
if (pdh && out_file_name_res) {
if (!wtap_dump_set_addrinfo_list(pdh, get_addrinfo_list())) {
cmdarg_err("The file format \"%s\" doesn't support name resolution information.",
wtap_file_type_subtype_short_string(out_file_type));
}
}
if (!wtap_dump_close(pdh, &err))
show_capture_file_io_error(save_file, err, TRUE);
} else {
if (print_packet_info) {
if (!write_finale()) {
err = errno;
show_print_file_io_error(err);
}
}
}
}
out:
wtap_close(cf->wth);
cf->wth = NULL;
g_free(save_file_string);
wtap_optionblock_array_free(shb_hdrs);
wtap_optionblock_array_free(nrb_hdrs);
return err;
}
static gboolean
process_packet(capture_file *cf, epan_dissect_t *edt, gint64 offset, struct wtap_pkthdr *whdr,
const guchar *pd, guint tap_flags)
{
frame_data fdata;
column_info *cinfo;
gboolean passed;
cf->count++;
passed = TRUE;
frame_data_init(&fdata, cf->count, whdr, offset, cum_bytes);
if (edt) {
if (print_packet_info && (gbl_resolv_flags.mac_name || gbl_resolv_flags.network_name ||
gbl_resolv_flags.transport_name))
host_name_lookup_process();
if (cf->dfcode)
epan_dissect_prime_dfilter(edt, cf->dfcode);
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
epan_dissect_run_with_taps(edt, cf->cd_t, whdr, frame_tvbuff_new(&fdata, pd), &fdata, cinfo);
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
exit(2);
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
line_bufp = get_line_buf(buf_offset + 5);
switch (col_item->col_fmt) {
case COL_DEF_SRC:
case COL_RES_SRC:
case COL_UNRES_SRC:
switch (cf->cinfo.columns[i+1].col_fmt) {
case COL_DEF_DST:
case COL_RES_DST:
case COL_UNRES_DST:
put_string(line_bufp + buf_offset, " " UTF8_RIGHTWARDS_ARROW " ", 5);
buf_offset += 5;
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
put_string(line_bufp + buf_offset, " " UTF8_RIGHTWARDS_ARROW " ", 5);
buf_offset += 5;
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
put_string(line_bufp + buf_offset, " " UTF8_RIGHTWARDS_ARROW " ", 5);
buf_offset += 5;
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
put_string(line_bufp + buf_offset, " " UTF8_LEFTWARDS_ARROW " ", 5);
buf_offset += 5;
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
put_string(line_bufp + buf_offset, " " UTF8_LEFTWARDS_ARROW " ", 5);
buf_offset += 5;
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
put_string(line_bufp + buf_offset, " " UTF8_LEFTWARDS_ARROW " ", 5);
buf_offset += 5;
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
print_args_t print_args;
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
print_args.print_hex = print_hex;
print_args.print_dissections = print_details ? print_dissections_expanded : print_dissections_none;
if (!proto_tree_print(&print_args, edt, output_only_tables, print_stream))
return FALSE;
if (!print_hex) {
if (!print_line(print_stream, 0, separator))
return FALSE;
}
break;
case WRITE_XML:
write_pdml_proto_tree(edt, stdout);
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
wtap *wth;
gchar *err_info;
char err_msg[2048+1];
wth = wtap_open_offline(fname, type, err, &err_info, perform_two_pass_analysis);
if (wth == NULL)
goto fail;
epan_free(cf->epan);
cf->epan = tshark_epan_new(cf);
cf->wth = wth;
cf->f_datalen = 0;
cf->filename = g_strdup(fname);
cf->is_tempfile = is_tempfile;
cf->unsaved_changes = FALSE;
cf->cd_t = wtap_file_type_subtype(cf->wth);
cf->open_type = type;
cf->count = 0;
cf->drops_known = FALSE;
cf->drops = 0;
cf->snap = wtap_snapshot_length(cf->wth);
if (cf->snap == 0) {
cf->has_snap = FALSE;
cf->snap = WTAP_MAX_PACKET_SIZE;
} else
cf->has_snap = TRUE;
nstime_set_zero(&cf->elapsed_time);
ref = NULL;
prev_dis = NULL;
prev_cap = NULL;
cf->state = FILE_READ_IN_PROGRESS;
wtap_set_cb_new_ipv4(cf->wth, add_ipv4_name);
wtap_set_cb_new_ipv6(cf->wth, (wtap_new_ipv6_callback_t) add_ipv6_name);
return CF_OK;
fail:
g_snprintf(err_msg, sizeof err_msg,
cf_open_error_message(*err, err_info, FALSE, cf->cd_t), fname);
cmdarg_err("%s", err_msg);
return CF_ERROR;
}
static void
show_capture_file_io_error(const char *fname, int err, gboolean is_close)
{
char *save_file_string;
save_file_string = output_file_description(fname);
switch (err) {
case ENOSPC:
cmdarg_err("Not all the packets could be written to the %s because there is "
"no space left on the file system.",
save_file_string);
break;
#ifdef EDQUOT
case EDQUOT:
cmdarg_err("Not all the packets could be written to the %s because you are "
"too close to, or over your disk quota.",
save_file_string);
break;
#endif
case WTAP_ERR_CANT_CLOSE:
cmdarg_err("The %s couldn't be closed for some unknown reason.",
save_file_string);
break;
case WTAP_ERR_SHORT_WRITE:
cmdarg_err("Not all the packets could be written to the %s.",
save_file_string);
break;
default:
if (is_close) {
cmdarg_err("The %s could not be closed: %s.", save_file_string,
wtap_strerror(err));
} else {
cmdarg_err("An error occurred while writing to the %s: %s.",
save_file_string, wtap_strerror(err));
}
break;
}
g_free(save_file_string);
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
cf_open_error_message(int err, gchar *err_info, gboolean for_writing,
int file_type)
{
const char *errmsg;
static char errmsg_errno[1024+1];
if (err < 0) {
switch (err) {
case WTAP_ERR_NOT_REGULAR_FILE:
errmsg = "The file \"%s\" is a \"special file\" or socket or other non-regular file.";
break;
case WTAP_ERR_RANDOM_OPEN_PIPE:
errmsg = "The file \"%s\" is a pipe or FIFO; TShark can't read pipe or FIFO files in two-pass mode.";
break;
case WTAP_ERR_FILE_UNKNOWN_FORMAT:
errmsg = "The file \"%s\" isn't a capture file in a format TShark understands.";
break;
case WTAP_ERR_UNSUPPORTED:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" contains record data that TShark doesn't support.\n"
"(%s)",
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
errmsg = errmsg_errno;
break;
case WTAP_ERR_CANT_WRITE_TO_PIPE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" is a pipe, and \"%s\" capture files can't be "
"written to a pipe.", wtap_file_type_subtype_short_string(file_type));
errmsg = errmsg_errno;
break;
case WTAP_ERR_UNWRITABLE_FILE_TYPE:
errmsg = "TShark doesn't support writing capture files in that format.";
break;
case WTAP_ERR_UNWRITABLE_ENCAP:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"TShark can't save this capture as a \"%s\" file.",
wtap_file_type_subtype_short_string(file_type));
errmsg = errmsg_errno;
break;
case WTAP_ERR_ENCAP_PER_PACKET_UNSUPPORTED:
if (for_writing) {
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"TShark can't save this capture as a \"%s\" file.",
wtap_file_type_subtype_short_string(file_type));
errmsg = errmsg_errno;
} else
errmsg = "The file \"%s\" is a capture for a network type that TShark doesn't support.";
break;
case WTAP_ERR_BAD_FILE:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)",
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
errmsg = errmsg_errno;
break;
case WTAP_ERR_CANT_OPEN:
if (for_writing)
errmsg = "The file \"%s\" could not be created for some unknown reason.";
else
errmsg = "The file \"%s\" could not be opened for some unknown reason.";
break;
case WTAP_ERR_SHORT_READ:
errmsg = "The file \"%s\" appears to have been cut short"
" in the middle of a packet or other data.";
break;
case WTAP_ERR_SHORT_WRITE:
errmsg = "A full header couldn't be written to the file \"%s\".";
break;
case WTAP_ERR_COMPRESSION_NOT_SUPPORTED:
errmsg = "This file type cannot be written as a compressed file.";
break;
case WTAP_ERR_DECOMPRESS:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The compressed file \"%%s\" appears to be damaged or corrupt.\n"
"(%s)",
err_info != NULL ? err_info : "no information supplied");
g_free(err_info);
errmsg = errmsg_errno;
break;
default:
g_snprintf(errmsg_errno, sizeof(errmsg_errno),
"The file \"%%s\" could not be %s: %s.",
for_writing ? "created" : "opened",
wtap_strerror(err));
errmsg = errmsg_errno;
break;
}
} else
errmsg = file_open_error_message(err, for_writing);
return errmsg;
}
static void
open_failure_message(const char *filename, int err, gboolean for_writing)
{
fprintf(stderr, "tshark: ");
fprintf(stderr, file_open_error_message(err, for_writing), filename);
fprintf(stderr, "\n");
}
static void
failure_message(const char *msg_format, va_list ap)
{
fprintf(stderr, "tshark: ");
vfprintf(stderr, msg_format, ap);
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
