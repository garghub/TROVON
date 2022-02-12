void
commandline_print_usage(gboolean for_help_option) {
FILE *output;
#ifdef _WIN32
create_console();
#endif
if (for_help_option) {
output = stdout;
fprintf(output, "Wireshark %s\n"
"Interactively dump and analyze network traffic.\n"
"See https://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
} else {
output = stderr;
}
fprintf(output, "\n");
fprintf(output, "Usage: wireshark [options] ... [ <infile> ]\n");
fprintf(output, "\n");
#ifdef HAVE_LIBPCAP
fprintf(output, "Capture interface:\n");
fprintf(output, " -i <interface> name or idx of interface (def: first non-loopback)\n");
fprintf(output, " -f <capture filter> packet filter in libpcap filter syntax\n");
fprintf(output, " -s <snaplen> packet snapshot length (def: 65535)\n");
fprintf(output, " -p don't capture in promiscuous mode\n");
fprintf(output, " -k start capturing immediately (def: do nothing)\n");
fprintf(output, " -S update packet display when new packets are captured\n");
fprintf(output, " -l turn on automatic scrolling while -S is in use\n");
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
fprintf(output, " -r <infile> set the filename to read from (no pipes or stdin!)\n");
fprintf(output, "\n");
fprintf(output, "Processing:\n");
fprintf(output, " -R <read filter> packet filter in Wireshark display filter syntax\n");
fprintf(output, " -n disable all name resolutions (def: all enabled)\n");
fprintf(output, " -N <name resolve flags> enable specific name resolution(s): \"mnNtd\"\n");
fprintf(output, " -d %s ...\n", DECODE_AS_ARG_TEMPLATE);
fprintf(output, " \"Decode As\", see the man page for details\n");
fprintf(output, " Example: tcp.port==8888,http\n");
fprintf(output, " --disable-protocol <proto_name>\n");
fprintf(output, " disable dissection of proto_name\n");
fprintf(output, " --enable-heuristic <short_name>\n");
fprintf(output, " enable dissection of heuristic protocol\n");
fprintf(output, " --disable-heuristic <short_name>\n");
fprintf(output, " disable dissection of heuristic protocol\n");
fprintf(output, "\n");
fprintf(output, "User interface:\n");
fprintf(output, " -C <config profile> start with specified configuration profile\n");
fprintf(output, " -Y <display filter> start with the given display filter\n");
fprintf(output, " -g <packet number> go to specified packet number after \"-r\"\n");
fprintf(output, " -J <jump filter> jump to the first packet matching the (display)\n");
fprintf(output, " filter\n");
fprintf(output, " -j search backwards for a matching packet after \"-J\"\n");
fprintf(output, " -m <font> set the font name used for most text\n");
fprintf(output, " -t a|ad|d|dd|e|r|u|ud output format of time stamps (def: r: rel. to first)\n");
fprintf(output, " -u s|hms output format of seconds (def: s: seconds)\n");
fprintf(output, " -X <key>:<value> eXtension options, see man page for details\n");
fprintf(output, " -z <statistics> show various statistics, see man page for details\n");
fprintf(output, "\n");
fprintf(output, "Output:\n");
fprintf(output, " -w <outfile|-> set the output filename (or '-' for stdout)\n");
fprintf(output, "\n");
fprintf(output, "Miscellaneous:\n");
fprintf(output, " -h display this help and exit\n");
fprintf(output, " -v display version info and exit\n");
fprintf(output, " -P <key>:<path> persconf:path - personal configuration files\n");
fprintf(output, " persdata:path - personal data files\n");
fprintf(output, " -o <name>:<value> ... override preference or recent setting\n");
fprintf(output, " -K <keytab> keytab file to use for kerberos decryption\n");
#ifndef _WIN32
fprintf(output, " --display=DISPLAY X display to use\n");
#endif
#ifdef _WIN32
destroy_console();
#endif
}
static void print_no_capture_support_error(void)
{
cmdarg_err("This version of Wireshark was not built with support for capturing packets.");
}
void commandline_early_options(int argc, char *argv[],
GString *comp_info_str, GString *runtime_info_str)
{
int opt;
#ifdef HAVE_LIBPCAP
int err;
GList *if_list;
gchar *err_str;
#else
gboolean capture_option_specified;
#endif
opterr = 0;
#ifndef HAVE_LIBPCAP
capture_option_specified = FALSE;
#endif
while ((opt = getopt_long(argc, argv, optstring, long_options, NULL)) != -1) {
switch (opt) {
case 'C':
if (profile_exists (optarg, FALSE)) {
set_profile_name (optarg);
} else {
cmdarg_err("Configuration Profile \"%s\" does not exist", optarg);
exit(1);
}
break;
case 'D':
#ifdef HAVE_LIBPCAP
if_list = capture_interface_list(&err, &err_str, NULL);
if (if_list == NULL) {
if (err == 0)
cmdarg_err("There are no interfaces on which a capture can be done");
else {
cmdarg_err("%s", err_str);
g_free(err_str);
}
exit(2);
}
#ifdef _WIN32
create_console();
#endif
capture_opts_print_interfaces(if_list);
free_interface_list(if_list);
#ifdef _WIN32
destroy_console();
#endif
exit(0);
#else
capture_option_specified = TRUE;
#endif
break;
case 'h':
commandline_print_usage(TRUE);
exit(0);
break;
#ifdef _WIN32
case 'i':
if (strcmp(optarg, "-") == 0)
set_stdin_capture(TRUE);
break;
#endif
case 'P':
if (!persfilepath_opt(opt, optarg)) {
cmdarg_err("-P flag \"%s\" failed (hint: is it quoted and existing?)", optarg);
exit(2);
}
break;
case 'v':
#ifdef _WIN32
create_console();
#endif
show_version("Wireshark", comp_info_str, runtime_info_str);
#ifdef _WIN32
destroy_console();
#endif
exit(0);
break;
case 'X':
ex_opt_add(optarg);
break;
case '?':
break;
}
}
#ifndef HAVE_LIBPCAP
if (capture_option_specified) {
print_no_capture_support_error();
commandline_print_usage(FALSE);
exit(1);
}
#endif
}
void commandline_other_options(int argc, char *argv[], gboolean opt_reset)
{
int opt;
gboolean arg_error = FALSE;
#ifdef HAVE_LIBPCAP
int status;
#else
gboolean capture_option_specified;
#endif
char badopt;
if (opt_reset) {
#ifdef HAVE_OPTRESET
optreset = 1;
optind = 1;
#else
optind = 0;
#endif
opterr = 1;
}
global_commandline_info.jump_backwards = SD_FORWARD;
global_commandline_info.go_to_packet = 0;
global_commandline_info.jfilter = NULL;
global_commandline_info.cf_name = NULL;
global_commandline_info.rfilter = NULL;
global_commandline_info.dfilter = NULL;
global_commandline_info.time_format = TS_NOT_SET;
#ifdef HAVE_LIBPCAP
global_commandline_info.start_capture = FALSE;
global_commandline_info.list_link_layer_types = FALSE;
global_commandline_info.quit_after_cap = getenv("WIRESHARK_QUIT_AFTER_CAPTURE") ? TRUE : FALSE;
#endif
global_commandline_info.disable_protocol_slist = NULL;
global_commandline_info.enable_heur_slist = NULL;
global_commandline_info.disable_heur_slist = NULL;
while ((opt = getopt_long(argc, argv, optstring, long_options, NULL)) != -1) {
switch (opt) {
case 'a':
case 'b':
case 'c':
case 'f':
case 'k':
case 'H':
case 'p':
case 'i':
#ifdef HAVE_PCAP_CREATE
case 'I':
#endif
#ifdef HAVE_PCAP_REMOTE
case 'A':
#endif
case 's':
case 'S':
case 'w':
case 'y':
#ifdef CAN_SET_CAPTURE_BUFFER_SIZE
case 'B':
#endif
#ifdef HAVE_LIBPCAP
status = capture_opts_add_opt(&global_capture_opts, opt, optarg,
&global_commandline_info.start_capture);
if(status != 0) {
exit(status);
}
#else
capture_option_specified = TRUE;
arg_error = TRUE;
#endif
break;
#if defined(HAVE_HEIMDAL_KERBEROS) || defined(HAVE_MIT_KERBEROS)
case 'K':
read_keytab_file(optarg);
break;
#endif
case 'C':
break;
case 'd':
if (!decode_as_command_option(optarg))
exit(1);
break;
case 'j':
global_commandline_info.jump_backwards = SD_BACKWARD;
break;
case 'g':
global_commandline_info.go_to_packet = get_positive_int(optarg, "go to packet");
break;
case 'J':
global_commandline_info.jfilter = optarg;
break;
case 'l':
#ifdef HAVE_LIBPCAP
auto_scroll_live = TRUE;
#else
capture_option_specified = TRUE;
arg_error = TRUE;
#endif
break;
case 'L':
#ifdef HAVE_LIBPCAP
global_commandline_info.list_link_layer_types = TRUE;
#else
capture_option_specified = TRUE;
arg_error = TRUE;
#endif
break;
case 'm':
g_free(global_commandline_info.prefs_p->gui_gtk2_font_name);
global_commandline_info.prefs_p->gui_gtk2_font_name = g_strdup(optarg);
break;
case 'n':
disable_name_resolution();
break;
case 'N':
badopt = string_to_name_resolve(optarg, &gbl_resolv_flags);
if (badopt != '\0') {
cmdarg_err("-N specifies unknown resolving option '%c'; valid options are 'd', m', 'n', 'N', and 't'",
badopt);
exit(1);
}
break;
case 'o':
switch (prefs_set_pref(optarg)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
cmdarg_err("Invalid -o flag \"%s\"", optarg);
exit(1);
break;
case PREFS_SET_NO_SUCH_PREF:
switch (recent_set_arg(optarg)) {
case PREFS_SET_OK:
break;
case PREFS_SET_SYNTAX_ERR:
cmdarg_err("Invalid -o flag \"%s\"", optarg);
exit(1);
break;
case PREFS_SET_NO_SUCH_PREF:
case PREFS_SET_OBSOLETE:
cmdarg_err("-o flag \"%s\" specifies unknown preference/recent value",
optarg);
exit(1);
break;
default:
g_assert_not_reached();
}
break;
case PREFS_SET_OBSOLETE:
cmdarg_err("-o flag \"%s\" specifies obsolete preference",
optarg);
exit(1);
break;
default:
g_assert_not_reached();
}
break;
case 'P':
break;
case 'r':
global_commandline_info.cf_name = g_strdup(optarg);
break;
case 'R':
global_commandline_info.rfilter = optarg;
break;
case 't':
if (strcmp(optarg, "r") == 0)
global_commandline_info.time_format = TS_RELATIVE;
else if (strcmp(optarg, "a") == 0)
global_commandline_info.time_format = TS_ABSOLUTE;
else if (strcmp(optarg, "ad") == 0)
global_commandline_info.time_format = TS_ABSOLUTE_WITH_YMD;
else if (strcmp(optarg, "adoy") == 0)
global_commandline_info.time_format = TS_ABSOLUTE_WITH_YDOY;
else if (strcmp(optarg, "d") == 0)
global_commandline_info.time_format = TS_DELTA;
else if (strcmp(optarg, "dd") == 0)
global_commandline_info.time_format = TS_DELTA_DIS;
else if (strcmp(optarg, "e") == 0)
global_commandline_info.time_format = TS_EPOCH;
else if (strcmp(optarg, "u") == 0)
global_commandline_info.time_format = TS_UTC;
else if (strcmp(optarg, "ud") == 0)
global_commandline_info.time_format = TS_UTC_WITH_YMD;
else if (strcmp(optarg, "udoy") == 0)
global_commandline_info.time_format = TS_UTC_WITH_YDOY;
else {
cmdarg_err("Invalid time stamp type \"%s\"", optarg);
cmdarg_err_cont("It must be \"a\" for absolute, \"ad\" for absolute with YYYY-MM-DD date,");
cmdarg_err_cont("\"adoy\" for absolute with YYYY/DOY date, \"d\" for delta,");
cmdarg_err_cont("\"dd\" for delta displayed, \"e\" for epoch, \"r\" for relative,");
cmdarg_err_cont("\"u\" for absolute UTC, \"ud\" for absolute UTC with YYYY-MM-DD date,");
cmdarg_err_cont("or \"udoy\" for absolute UTC with YYYY/DOY date.");
exit(1);
}
break;
case 'u':
if (strcmp(optarg, "s") == 0)
timestamp_set_seconds_type(TS_SECONDS_DEFAULT);
else if (strcmp(optarg, "hms") == 0)
timestamp_set_seconds_type(TS_SECONDS_HOUR_MIN_SEC);
else {
cmdarg_err("Invalid seconds type \"%s\"", optarg);
cmdarg_err_cont("It must be \"s\" for seconds or \"hms\" for hours, minutes and seconds.");
exit(1);
}
break;
case 'X':
break;
case 'Y':
global_commandline_info.dfilter = optarg;
break;
case 'z':
if (strcmp("help", optarg) == 0) {
fprintf(stderr, "wireshark: The available statistics for the \"-z\" option are:\n");
list_stat_cmd_args();
exit(0);
}
if (!process_stat_cmd_arg(optarg)) {
cmdarg_err("Invalid -z argument.");
cmdarg_err_cont(" -z argument must be one of :");
list_stat_cmd_args();
exit(1);
}
break;
case LONGOPT_DISABLE_PROTOCOL:
global_commandline_info.disable_protocol_slist = g_slist_append(global_commandline_info.disable_protocol_slist, optarg);
break;
case LONGOPT_ENABLE_HEURISTIC:
global_commandline_info.enable_heur_slist = g_slist_append(global_commandline_info.enable_heur_slist, optarg);
break;
case LONGOPT_DISABLE_HEURISTIC:
global_commandline_info.disable_heur_slist = g_slist_append(global_commandline_info.disable_heur_slist, optarg);
break;
default:
case '?':
arg_error = TRUE;
break;
}
}
if (!arg_error) {
argc -= optind;
argv += optind;
if (argc >= 1) {
if (global_commandline_info.cf_name != NULL) {
cmdarg_err("File name specified both with -r and regular argument");
arg_error = TRUE;
} else {
#ifndef HAVE_GTKOSXAPPLICATION
global_commandline_info.cf_name = g_strdup(argv[0]);
#endif
}
argc--;
argv++;
}
if (argc != 0) {
cmdarg_err("Invalid argument: %s", argv[0]);
arg_error = TRUE;
}
}
if (arg_error) {
#ifndef HAVE_LIBPCAP
if (capture_option_specified) {
print_no_capture_support_error();
}
#endif
commandline_print_usage(FALSE);
exit(1);
}
#ifdef HAVE_LIBPCAP
if (global_commandline_info.start_capture && global_commandline_info.list_link_layer_types) {
cmdarg_err("You can't specify both -L and a live capture.");
exit(1);
}
if (global_commandline_info.list_link_layer_types) {
if (global_commandline_info.cf_name) {
cmdarg_err("You can't specify -L and a capture file to be read.");
exit(1);
}
if (global_capture_opts.multi_files_on) {
cmdarg_err("Ring buffer requested, but a capture isn't being done.");
exit(1);
}
} else {
if (global_commandline_info.start_capture && global_commandline_info.cf_name) {
cmdarg_err("You can't specify both a live capture and a capture file to be read.");
exit(1);
}
if (global_capture_opts.multi_files_on) {
if (global_capture_opts.save_file == NULL) {
cmdarg_err("Ring buffer requested, but capture isn't being saved to a permanent file.");
global_capture_opts.multi_files_on = FALSE;
}
if (!global_capture_opts.has_autostop_filesize && !global_capture_opts.has_file_duration) {
cmdarg_err("Ring buffer requested, but no maximum capture file size or duration were specified.");
}
}
}
#endif
}
