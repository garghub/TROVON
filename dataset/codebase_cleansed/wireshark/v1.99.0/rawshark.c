static void
print_usage(FILE *output)
{
fprintf(output, "\n");
fprintf(output, "Usage: rawshark [options] ...\n");
fprintf(output, "\n");
fprintf(output, "Input file:\n");
fprintf(output, " -r <infile> set the pipe or file name to read from\n");
fprintf(output, "\n");
fprintf(output, "Processing:\n");
fprintf(output, " -d <encap:linktype>|<proto:protoname>\n");
fprintf(output, " packet encapsulation or protocol\n");
fprintf(output, " -F <field> field to display\n");
fprintf(output, " -n disable all name resolution (def: all enabled)\n");
fprintf(output, " -N <name resolve flags> enable specific name resolution(s): \"mntC\"\n");
fprintf(output, " -p use the system's packet header format\n");
fprintf(output, " (which may have 64-bit timestamps)\n");
fprintf(output, " -R <read filter> packet filter in Wireshark display filter syntax\n");
fprintf(output, " -s skip PCAP header on input\n");
fprintf(output, "\n");
fprintf(output, "Output:\n");
fprintf(output, " -l flush output after each packet\n");
fprintf(output, " -S format string for fields\n");
fprintf(output, " (%%D - name, %%S - stringval, %%N numval)\n");
fprintf(output, " -t ad|a|r|d|dd|e output format of time stamps (def: r: rel. to first)\n");
fprintf(output, "\n");
fprintf(output, "Miscellaneous:\n");
fprintf(output, " -h display this help and exit\n");
fprintf(output, " -o <name>:<value> ... override preference setting\n");
fprintf(output, " -v display version info and exit\n");
}
static void
log_func_ignore (const gchar *log_domain _U_, GLogLevelFlags log_level _U_,
const gchar *message _U_, gpointer user_data _U_)
{
}
static int
raw_pipe_open(const char *pipe_name)
{
#ifndef _WIN32
ws_statb64 pipe_stat;
#else
char *pncopy, *pos = NULL;
DWORD err;
wchar_t *err_str;
HANDLE hPipe = NULL;
#endif
int rfd;
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "open_raw_pipe: %s", pipe_name);
if (strcmp(pipe_name, "-") == 0) {
rfd = 0;
#ifdef _WIN32
_setmode(0, _O_BINARY);
#endif
} else {
#ifndef _WIN32
if (ws_stat64(pipe_name, &pipe_stat) < 0) {
fprintf(stderr, "rawshark: The pipe %s could not be checked: %s\n",
pipe_name, g_strerror(errno));
return -1;
}
if (! S_ISFIFO(pipe_stat.st_mode)) {
if (S_ISCHR(pipe_stat.st_mode)) {
} else
{
fprintf(stderr, "rawshark: \"%s\" is neither an interface nor a pipe\n",
pipe_name);
}
return -1;
}
rfd = ws_open(pipe_name, O_RDONLY | O_NONBLOCK, 0000 );
if (rfd == -1) {
fprintf(stderr, "rawshark: \"%s\" could not be opened: %s\n",
pipe_name, g_strerror(errno));
return -1;
}
#else
#define PIPE_STR "\\pipe\\"
pncopy = g_strdup(pipe_name);
if (strstr(pncopy, "\\\\") == pncopy) {
pos = strchr(pncopy + 3, '\\');
if (pos && g_ascii_strncasecmp(pos, PIPE_STR, strlen(PIPE_STR)) != 0)
pos = NULL;
}
g_free(pncopy);
if (!pos) {
fprintf(stderr, "rawshark: \"%s\" is neither an interface nor a pipe\n",
pipe_name);
return -1;
}
while (1) {
hPipe = CreateFile(utf_8to16(pipe_name), GENERIC_READ, 0, NULL,
OPEN_EXISTING, 0, NULL);
if (hPipe != INVALID_HANDLE_VALUE)
break;
err = GetLastError();
if (err != ERROR_PIPE_BUSY) {
FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
NULL, err, 0, (LPTSTR) &err_str, 0, NULL);
fprintf(stderr, "rawshark: \"%s\" could not be opened: %s (error %d)\n",
pipe_name, utf_16to8(err_str), err);
LocalFree(err_str);
return -1;
}
if (!WaitNamedPipe(utf_8to16(pipe_name), 30 * 1000)) {
err = GetLastError();
FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
NULL, err, 0, (LPTSTR) &err_str, 0, NULL);
fprintf(stderr, "rawshark: \"%s\" could not be waited for: %s (error %d)\n",
pipe_name, utf_16to8(err_str), err);
LocalFree(err_str);
return -1;
}
}
rfd = _open_osfhandle((long) hPipe, _O_RDONLY);
if (rfd == -1) {
fprintf(stderr, "rawshark: \"%s\" could not be opened: %s\n",
pipe_name, g_strerror(errno));
return -1;
}
#endif
}
return rfd;
}
static gboolean
set_link_type(const char *lt_arg) {
char *spec_ptr = strchr(lt_arg, ':');
char *p;
int dlt_val;
long val;
dissector_handle_t dhandle;
GString *pref_str;
if (!spec_ptr)
return FALSE;
spec_ptr++;
if (strncmp(lt_arg, "encap:", strlen("encap:")) == 0) {
dlt_val = linktype_name_to_val(spec_ptr);
if (dlt_val == -1) {
errno = 0;
val = strtol(spec_ptr, &p, 10);
if (p == spec_ptr || *p != '\0' || errno != 0 || val > INT_MAX) {
return FALSE;
}
dlt_val = (int)val;
}
encap = wtap_pcap_encap_to_wtap_encap(dlt_val);
if (encap == WTAP_ENCAP_UNKNOWN) {
return FALSE;
}
return TRUE;
} else if (strncmp(lt_arg, "proto:", strlen("proto:")) == 0) {
dhandle = find_dissector(spec_ptr);
if (dhandle) {
encap = WTAP_ENCAP_USER0;
pref_str = g_string_new("uat:user_dlts:");
g_string_append_printf(pref_str,
"\"User 0 (DLT=147)\",\"%s\",\"0\",\"\",\"0\",\"\"",
spec_ptr);
if (prefs_set_pref(pref_str->str) != PREFS_SET_OK) {
g_string_free(pref_str, TRUE);
return FALSE;
}
g_string_free(pref_str, TRUE);
return TRUE;
}
}
return FALSE;
}
static void
show_version(GString *comp_info_str, GString *runtime_info_str)
{
printf("Rawshark (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), get_copyright_info(), comp_info_str->str,
runtime_info_str->str);
}
int
main(int argc, char *argv[])
{
GString *comp_info_str;
GString *runtime_info_str;
char *init_progfile_dir_error;
int opt, i;
gboolean arg_error = FALSE;
#ifdef _WIN32
WSADATA wsaData;
#endif
char *gpf_path, *pf_path;
char *gdp_path, *dp_path;
int gpf_open_errno, gpf_read_errno;
int pf_open_errno, pf_read_errno;
int gdp_open_errno, gdp_read_errno;
int dp_open_errno, dp_read_errno;
gchar *pipe_name = NULL;
gchar *rfilters[64];
e_prefs *prefs_p;
char badopt;
int log_flags;
GPtrArray *disp_fields = g_ptr_array_new();
guint fc;
gboolean skip_pcap_header = FALSE;
static const struct option long_options[] = {
{(char *)"help", no_argument, NULL, 'h'},
{(char *)"version", no_argument, NULL, 'v'},
{0, 0, 0, 0 }
};
#define OPTSTRING_INIT "d:F:hlnN:o:pr:R:sS:t:v"
static const char optstring[] = OPTSTRING_INIT;
cmdarg_err_init(rawshark_cmdarg_err, rawshark_cmdarg_err_cont);
comp_info_str = g_string_new("Compiled ");
get_compiled_version_info(comp_info_str, NULL, epan_get_compiled_version_info);
runtime_info_str = g_string_new("Running ");
get_runtime_version_info(runtime_info_str, NULL);
ws_add_crash_info("Rawshark (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), comp_info_str->str, runtime_info_str->str);
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#endif
init_process_policies();
memset(rfilters, 0, sizeof(rfilters));
memset(rfcodes, 0, sizeof(rfcodes));
n_rfilters = 0;
n_rfcodes = 0;
string_fmts = g_ptr_array_new();
init_progfile_dir_error = init_progfile_dir(argv[0], main);
if (init_progfile_dir_error != NULL) {
fprintf(stderr, "rawshark: Can't get pathname of rawshark program: %s.\n",
init_progfile_dir_error);
}
init_process_policies();
log_flags =
G_LOG_LEVEL_WARNING |
G_LOG_LEVEL_MESSAGE |
G_LOG_LEVEL_INFO |
G_LOG_LEVEL_DEBUG;
g_log_set_handler(NULL,
(GLogLevelFlags)log_flags,
log_func_ignore, NULL );
g_log_set_handler(LOG_DOMAIN_CAPTURE_CHILD,
(GLogLevelFlags)log_flags,
log_func_ignore, NULL );
init_report_err(failure_message, open_failure_message, read_failure_message,
write_failure_message);
timestamp_set_type(TS_RELATIVE);
timestamp_set_precision(TS_PREC_AUTO);
timestamp_set_seconds_type(TS_SECONDS_DEFAULT);
epan_init(register_all_protocols, register_all_protocol_handoffs, NULL, NULL);
setlocale(LC_ALL, "");
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
read_disabled_protos_list(&gdp_path, &gdp_open_errno, &gdp_read_errno,
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
#ifdef _WIN32
load_wpcap();
#endif
cap_file_init(&cfile);
print_format = PR_FMT_TEXT;
encap = WTAP_ENCAP_UNKNOWN;
while ((opt = getopt_long(argc, argv, optstring, long_options, NULL)) != -1) {
switch (opt) {
case 'd':
if (!set_link_type(optarg)) {
cmdarg_err("Invalid link type or protocol \"%s\"", optarg);
exit(1);
}
break;
case 'F':
g_ptr_array_add(disp_fields, g_strdup(optarg));
break;
case 'h':
printf("Rawshark (Wireshark) %s\n"
"Dump and analyze network traffic.\n"
"See http://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
print_usage(stdout);
exit(0);
break;
case 'l':
line_buffered = TRUE;
break;
case 'n':
gbl_resolv_flags.mac_name = FALSE;
gbl_resolv_flags.network_name = FALSE;
gbl_resolv_flags.transport_name = FALSE;
gbl_resolv_flags.concurrent_dns = FALSE;
break;
case 'N':
badopt = string_to_name_resolve(optarg, &gbl_resolv_flags);
if (badopt != '\0') {
cmdarg_err("-N specifies unknown resolving option '%c'; valid options are 'm', 'n', and 't'",
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
case PREFS_SET_OBSOLETE:
cmdarg_err("-o flag \"%s\" specifies unknown preference", optarg);
exit(1);
break;
}
break;
case 'p':
want_pcap_pkthdr = TRUE;
break;
case 'r':
pipe_name = g_strdup(optarg);
break;
case 'R':
if(n_rfilters < (int) sizeof(rfilters) / (int) sizeof(rfilters[0])) {
rfilters[n_rfilters++] = optarg;
}
else {
cmdarg_err("Too many display filters");
exit(1);
}
break;
case 's':
skip_pcap_header = TRUE;
break;
case 'S':
if (!parse_field_string_format(optarg)) {
cmdarg_err("Invalid field string format");
exit(1);
}
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
cmdarg_err("Invalid time stamp type \"%s\"",
optarg);
cmdarg_err_cont(
"It must be \"a\" for absolute, \"ad\" for absolute with YYYY-MM-DD date,");
cmdarg_err_cont(
"\"adoy\" for absolute with YYYY/DOY date, \"d\" for delta,");
cmdarg_err_cont(
"\"dd\" for delta displayed, \"e\" for epoch, \"r\" for relative,");
cmdarg_err_cont(
"\"u\" for absolute UTC, \"ud\" for absolute UTC with YYYY-MM-DD date,");
cmdarg_err_cont(
"or \"udoy\" for absolute UTC with YYYY/DOY date.");
exit(1);
}
break;
case 'v':
{
show_version(comp_info_str, runtime_info_str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
exit(0);
break;
}
default:
case '?':
print_usage(stderr);
exit(1);
break;
}
}
prefs_apply_all();
for (fc = 0; fc < disp_fields->len; fc++) {
protocolinfo_init((char *)g_ptr_array_index(disp_fields, fc));
}
g_ptr_array_free(disp_fields, TRUE);
printf("\n");
fflush(stdout);
if (optind < argc) {
if (pipe_name != NULL) {
if (n_rfilters != 0) {
cmdarg_err("Read filters were specified both with \"-R\" "
"and with additional command-line arguments");
exit(1);
}
rfilters[n_rfilters] = get_args_as_string(argc, argv, optind);
}
}
if (encap == WTAP_ENCAP_UNKNOWN) {
cmdarg_err("No valid payload dissector specified.");
exit(1);
}
if (arg_error) {
print_usage(stderr);
exit(1);
}
#ifdef _WIN32
WSAStartup( MAKEWORD( 1, 1 ), &wsaData );
#endif
start_requested_stats();
if (gdp_path == NULL && dp_path == NULL) {
set_disabled_protos_list();
}
build_column_format_array(&cfile.cinfo, prefs_p->num_cols, TRUE);
if (n_rfilters != 0) {
for (i = 0; i < n_rfilters; i++) {
if (!dfilter_compile(rfilters[i], &rfcodes[n_rfcodes])) {
cmdarg_err("%s", dfilter_error_msg);
epan_free(cfile.epan);
epan_cleanup();
exit(2);
}
n_rfcodes++;
}
}
if (pipe_name) {
relinquish_special_privs_perm();
if (raw_cf_open(&cfile, pipe_name) != CF_OK) {
epan_free(cfile.epan);
epan_cleanup();
exit(2);
}
if (skip_pcap_header) {
size_t bytes_left = sizeof(struct pcap_hdr) + sizeof(guint32);
gchar buf[sizeof(struct pcap_hdr) + sizeof(guint32)];
while (bytes_left != 0) {
ssize_t bytes = read(fd, buf, (int)bytes_left);
if (bytes <= 0) {
cmdarg_err("Not enough bytes for pcap header.");
exit(2);
}
bytes_left -= bytes;
}
}
if (!load_cap_file(&cfile)) {
epan_free(cfile.epan);
epan_cleanup();
exit(2);
}
} else {
cmdarg_err("Input file or pipe name not specified.");
exit(2);
}
epan_free(cfile.epan);
epan_cleanup();
return 0;
}
static gboolean
raw_pipe_read(struct wtap_pkthdr *phdr, guchar * pd, int *err, const gchar **err_info, gint64 *data_offset) {
struct pcap_pkthdr mem_hdr;
struct pcaprec_hdr disk_hdr;
ssize_t bytes_read = 0;
size_t bytes_needed = sizeof(disk_hdr);
guchar *ptr = (guchar*) &disk_hdr;
static gchar err_str[100];
if (want_pcap_pkthdr) {
bytes_needed = sizeof(mem_hdr);
ptr = (guchar*) &mem_hdr;
}
while (bytes_needed > 0) {
bytes_read = read(fd, ptr, (int)bytes_needed);
if (bytes_read == 0) {
*err = 0;
return FALSE;
} else if (bytes_read < 0) {
*err = WTAP_ERR_CANT_READ;
*err_info = "Error reading header from pipe";
return FALSE;
}
bytes_needed -= bytes_read;
*data_offset += bytes_read;
ptr += bytes_read;
}
if (want_pcap_pkthdr) {
phdr->ts.secs = mem_hdr.ts.tv_sec;
phdr->ts.nsecs = (gint32)mem_hdr.ts.tv_usec * 1000;
phdr->caplen = mem_hdr.caplen;
phdr->len = mem_hdr.len;
} else {
phdr->ts.secs = disk_hdr.ts_sec;
phdr->ts.nsecs = disk_hdr.ts_usec * 1000;
phdr->caplen = disk_hdr.incl_len;
phdr->len = disk_hdr.orig_len;
}
bytes_needed = phdr->caplen;
phdr->pkt_encap = encap;
#if 0
printf("mem_hdr: %lu disk_hdr: %lu\n", sizeof(mem_hdr), sizeof(disk_hdr));
printf("tv_sec: %u (%04x)\n", (unsigned int) phdr->ts.secs, (unsigned int) phdr->ts.secs);
printf("tv_nsec: %d (%04x)\n", phdr->ts.nsecs, phdr->ts.nsecs);
printf("caplen: %d (%04x)\n", phdr->caplen, phdr->caplen);
printf("len: %d (%04x)\n", phdr->len, phdr->len);
#endif
if (bytes_needed > WTAP_MAX_PACKET_SIZE) {
*err = WTAP_ERR_BAD_FILE;
g_snprintf(err_str, 100, "Bad packet length: %lu\n",
(unsigned long) bytes_needed);
*err_info = err_str;
return FALSE;
}
ptr = pd;
while (bytes_needed > 0) {
bytes_read = read(fd, ptr, (int)bytes_needed);
if (bytes_read == 0) {
*err = WTAP_ERR_SHORT_READ;
*err_info = "Got zero bytes reading data from pipe";
return FALSE;
} else if (bytes_read < 0) {
*err = WTAP_ERR_CANT_READ;
*err_info = "Error reading data from pipe";
return FALSE;
}
bytes_needed -= bytes_read;
*data_offset += bytes_read;
ptr += bytes_read;
}
return TRUE;
}
static gboolean
load_cap_file(capture_file *cf)
{
int err;
const gchar *err_info;
gint64 data_offset = 0;
guchar pd[WTAP_MAX_PACKET_SIZE];
struct wtap_pkthdr phdr;
epan_dissect_t edt;
memset(&phdr, 0, sizeof(phdr));
epan_dissect_init(&edt, cf->epan, TRUE, FALSE);
while (raw_pipe_read(&phdr, pd, &err, &err_info, &data_offset)) {
process_packet(cf, &edt, data_offset, &phdr, pd);
}
epan_dissect_cleanup(&edt);
if (err != 0) {
switch (err) {
case WTAP_ERR_UNSUPPORTED_ENCAP:
cmdarg_err("The file \"%s\" has a packet with a network type that Rawshark doesn't support.\n(%s)",
cf->filename, err_info);
break;
case WTAP_ERR_CANT_READ:
cmdarg_err("An attempt to read from the file \"%s\" failed for some unknown reason.",
cf->filename);
break;
case WTAP_ERR_SHORT_READ:
cmdarg_err("The file \"%s\" appears to have been cut short in the middle of a packet.",
cf->filename);
break;
case WTAP_ERR_BAD_FILE:
cmdarg_err("The file \"%s\" appears to be damaged or corrupt.\n(%s)",
cf->filename, err_info);
break;
case WTAP_ERR_DECOMPRESS:
cmdarg_err("The compressed file \"%s\" appears to be damaged or corrupt.\n(%s)",
cf->filename, err_info);
break;
default:
cmdarg_err("An error occurred while reading the file \"%s\": %s.",
cf->filename, wtap_strerror(err));
break;
}
return FALSE;
}
return TRUE;
}
static gboolean
process_packet(capture_file *cf, epan_dissect_t *edt, gint64 offset,
struct wtap_pkthdr *whdr, const guchar *pd)
{
frame_data fdata;
gboolean passed;
int i;
if(whdr->len == 0)
{
printf("%lu %lu %lu void -\n", (unsigned long int)cf->count,
(unsigned long int)whdr->ts.secs,
(unsigned long int)whdr->ts.nsecs);
fflush(stdout);
return FALSE;
}
cf->count++;
frame_data_init(&fdata, cf->count, whdr, offset, cum_bytes);
passed = TRUE;
if (n_rfilters > 0) {
for(i = 0; i < n_rfcodes; i++) {
epan_dissect_prime_dfilter(edt, rfcodes[i]);
}
}
printf("%lu", (unsigned long int) cf->count);
frame_data_set_before_dissect(&fdata, &cf->elapsed_time,
&ref, prev_dis);
if (ref == &fdata) {
ref_frame = fdata;
ref = &ref_frame;
}
epan_dissect_run_with_taps(edt, cf->cd_t, whdr, frame_tvbuff_new(&fdata, pd), &fdata, &cf->cinfo);
frame_data_set_after_dissect(&fdata, &cum_bytes);
prev_dis_frame = fdata;
prev_dis = &prev_dis_frame;
prev_cap_frame = fdata;
prev_cap = &prev_cap_frame;
for(i = 0; i < n_rfilters; i++) {
if (rfcodes[i])
passed = dfilter_apply_edt(rfcodes[i], edt);
else
passed = TRUE;
printf(" %u", passed ? 1 : 0);
}
printf(" -\n");
if (line_buffered)
fflush(stdout);
if (ferror(stdout)) {
show_print_file_io_error(errno);
exit(2);
}
epan_dissect_reset(edt);
frame_data_destroy(&fdata);
return passed;
}
static const char* ftenum_to_string(header_field_info *hfi)
{
if (!hfi) {
return "n.a.";
}
if (string_fmts->len > 0 && hfi->strings) {
return "FT_STRING";
}
switch(hfi->type) {
case FT_NONE:
return "FT_NONE";
case FT_PROTOCOL:
return "FT_PROTOCOL";
case FT_BOOLEAN:
return "FT_BOOLEAN";
case FT_UINT8:
return "FT_UINT8";
case FT_UINT16:
return "FT_UINT16";
case FT_UINT24:
return "FT_UINT24";
case FT_UINT32:
return "FT_UINT32";
case FT_UINT64:
return "FT_UINT64";
case FT_INT8:
return "FT_INT8";
case FT_INT16:
return "FT_INT16";
case FT_INT24:
return "FT_INT24";
case FT_INT32:
return "FT_INT32";
case FT_INT64:
return "FT_INT64";
case FT_FLOAT:
return "FT_FLOAT";
case FT_DOUBLE:
return "FT_DOUBLE";
case FT_ABSOLUTE_TIME:
return "FT_ABSOLUTE_TIME";
case FT_RELATIVE_TIME:
return "FT_RELATIVE_TIME";
case FT_STRING:
return "FT_STRING";
case FT_STRINGZ:
return "FT_STRINGZ";
case FT_UINT_STRING:
return "FT_UINT_STRING";
case FT_ETHER:
return "FT_ETHER";
case FT_BYTES:
return "FT_BYTES";
case FT_UINT_BYTES:
return "FT_UINT_BYTES";
case FT_IPv4:
return "FT_IPv4";
case FT_IPv6:
return "FT_IPv6";
case FT_IPXNET:
return "FT_IPXNET";
case FT_FRAMENUM:
return "FT_FRAMENUM";
case FT_PCRE:
return "FT_PCRE";
case FT_GUID:
return "FT_GUID";
case FT_OID:
return "FT_OID";
case FT_REL_OID:
return "FT_REL_OID";
case FT_SYSTEM_ID:
return "FT_SYSTEM_ID";
case FT_STRINGZPAD:
return "FT_STRIGZPAD";
case FT_NUM_TYPES:
return "FT_NUM_TYPES";
default:
return "n.a.";
};
}
static const char* absolute_time_display_e_to_string(absolute_time_display_e atd)
{
switch(atd) {
case ABSOLUTE_TIME_LOCAL:
return "ABSOLUTE_TIME_LOCAL";
case ABSOLUTE_TIME_UTC:
return "ABSOLUTE_TIME_UTC";
default:
return "n.a.";
}
}
static const char* field_display_e_to_string(field_display_e bd)
{
switch(bd) {
case BASE_NONE:
return "BASE_NONE";
case BASE_DEC:
return "BASE_DEC";
case BASE_HEX:
return "BASE_HEX";
case BASE_OCT:
return "BASE_OCT";
case BASE_DEC_HEX:
return "BASE_DEC_HEX";
case BASE_HEX_DEC:
return "BASE_HEX_DEC";
default:
return "n.a.";
}
}
static gboolean print_field_value(field_info *finfo, int cmd_line_index)
{
header_field_info *hfinfo;
static char *fs_buf = NULL;
char *fs_ptr = fs_buf;
static GString *label_s = NULL;
int fs_buf_len = FIELD_STR_INIT_LEN, fs_len;
guint i;
string_fmt_t *sf;
guint32 uvalue;
gint32 svalue;
guint64 uvalue64;
gint64 svalue64;
const true_false_string *tfstring = &tfs_true_false;
hfinfo = finfo->hfinfo;
if (!fs_buf) {
fs_buf = (char *)g_malloc(fs_buf_len + 1);
fs_ptr = fs_buf;
}
if (!label_s) {
label_s = g_string_new("");
}
if(finfo->value.ftype->val_to_string_repr)
{
fs_len = fvalue_string_repr_len(&finfo->value, FTREPR_DFILTER);
while (fs_buf_len < fs_len) {
fs_buf_len *= 2;
fs_buf = (char *)g_realloc(fs_buf, fs_buf_len + 1);
fs_ptr = fs_buf;
}
fvalue_to_string_repr(&finfo->value,
FTREPR_DFILTER,
fs_buf);
if (IS_FT_STRING(finfo->value.ftype->ftype) && fs_len > 2) {
fs_buf[fs_len - 1] = '\0';
fs_ptr++;
}
}
if (string_fmts->len > 0 && finfo->hfinfo->strings) {
g_string_truncate(label_s, 0);
for (i = 0; i < string_fmts->len; i++) {
sf = (string_fmt_t *)g_ptr_array_index(string_fmts, i);
if (sf->plain) {
g_string_append(label_s, sf->plain);
} else {
switch (sf->format) {
case SF_NAME:
g_string_append(label_s, hfinfo->name);
break;
case SF_NUMVAL:
g_string_append(label_s, fs_ptr);
break;
case SF_STRVAL:
switch(hfinfo->type) {
case FT_BOOLEAN:
uvalue = fvalue_get_uinteger(&finfo->value);
tfstring = (const struct true_false_string*) hfinfo->strings;
g_string_append(label_s, uvalue ? tfstring->true_string : tfstring->false_string);
break;
case FT_INT8:
case FT_INT16:
case FT_INT24:
case FT_INT32:
DISSECTOR_ASSERT(!hfinfo->bitmask);
svalue = fvalue_get_sinteger(&finfo->value);
if (hfinfo->display & BASE_RANGE_STRING) {
g_string_append(label_s, rval_to_str_const(svalue, RVALS(hfinfo->strings), "Unknown"));
} else if (hfinfo->display & BASE_EXT_STRING) {
g_string_append(label_s, val_to_str_ext_const(svalue, (value_string_ext *) hfinfo->strings, "Unknown"));
} else {
g_string_append(label_s, val_to_str_const(svalue, cVALS(hfinfo->strings), "Unknown"));
}
break;
case FT_INT64:
DISSECTOR_ASSERT(!hfinfo->bitmask);
svalue64 = (gint64)fvalue_get_integer64(&finfo->value);
if (hfinfo->display & BASE_VAL64_STRING) {
g_string_append(label_s, val64_to_str_const(svalue64, (const val64_string *)(hfinfo->strings), "Unknown"));
}
break;
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
uvalue = fvalue_get_uinteger(&finfo->value);
if (!hfinfo->bitmask && hfinfo->display & BASE_RANGE_STRING) {
g_string_append(label_s, rval_to_str_const(uvalue, RVALS(hfinfo->strings), "Unknown"));
} else if (hfinfo->display & BASE_EXT_STRING) {
g_string_append(label_s, val_to_str_ext_const(uvalue, (value_string_ext *) hfinfo->strings, "Unknown"));
} else {
g_string_append(label_s, val_to_str_const(uvalue, cVALS(hfinfo->strings), "Unknown"));
}
break;
case FT_UINT64:
DISSECTOR_ASSERT(!hfinfo->bitmask);
uvalue64 = fvalue_get_integer64(&finfo->value);
if (hfinfo->display & BASE_VAL64_STRING) {
g_string_append(label_s, val64_to_str_const(uvalue64, (const val64_string *)(hfinfo->strings), "Unknown"));
}
break;
default:
break;
}
break;
default:
break;
}
}
}
printf(" %u=\"%s\"", cmd_line_index, label_s->str);
return TRUE;
}
if(finfo->value.ftype->val_to_string_repr)
{
printf(" %u=\"%s\"", cmd_line_index, fs_ptr);
return TRUE;
}
printf(" %u=\"n.a.\"", cmd_line_index);
return TRUE;
}
static int
protocolinfo_packet(void *prs, packet_info *pinfo _U_, epan_dissect_t *edt, const void *dummy _U_)
{
pci_t *rs=(pci_t *)prs;
GPtrArray *gp;
guint i;
gp=proto_get_finfo_ptr_array(edt->tree, rs->hf_index);
if(!gp){
printf(" n.a.");
return 0;
}
for (i = 0; i < gp->len; i++) {
print_field_value((field_info *)gp->pdata[i], rs->cmd_line_index);
}
return 0;
}
static void
protocolinfo_init(char *field)
{
pci_t *rs;
header_field_info *hfi;
GString *error_string;
hfi=proto_registrar_get_byname(field);
if(!hfi){
fprintf(stderr, "rawshark: Field \"%s\" doesn't exist.\n", field);
exit(1);
}
switch (hfi->type) {
case FT_ABSOLUTE_TIME:
printf("%u %s %s - ",
g_cmd_line_index,
ftenum_to_string(hfi),
absolute_time_display_e_to_string((absolute_time_display_e)hfi->display));
break;
default:
printf("%u %s %s - ",
g_cmd_line_index,
ftenum_to_string(hfi),
field_display_e_to_string((field_display_e)hfi->display));
break;
}
rs=(pci_t *)g_malloc(sizeof(pci_t));
rs->hf_index=hfi->id;
rs->filter=field;
rs->cmd_line_index = g_cmd_line_index++;
error_string=register_tap_listener("frame", rs, rs->filter, TL_REQUIRES_PROTO_TREE, NULL, protocolinfo_packet, NULL);
if(error_string){
fprintf(stderr, "rawshark: Couldn't register field extraction tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
if(rs->filter){
g_free(rs->filter);
}
g_free(rs);
exit(1);
}
}
static void
add_string_fmt(string_fmt_e format, gchar *plain) {
string_fmt_t *sf = (string_fmt_t *)g_malloc(sizeof(string_fmt_t));
sf->format = format;
sf->plain = g_strdup(plain);
g_ptr_array_add(string_fmts, sf);
}
static gboolean
parse_field_string_format(gchar *format) {
GString *plain_s = g_string_new("");
size_t len;
size_t pos = 0;
if (!format) {
return FALSE;
}
len = strlen(format);
g_ptr_array_set_size(string_fmts, 0);
while (pos < len) {
if (format[pos] == '%') {
if (pos >= len) {
return FALSE;
}
pos++;
if (plain_s->len > 0) {
add_string_fmt(SF_NONE, plain_s->str);
g_string_truncate(plain_s, 0);
}
switch (format[pos]) {
case 'D':
add_string_fmt(SF_NAME, NULL);
break;
case 'N':
add_string_fmt(SF_NUMVAL, NULL);
break;
case 'S':
add_string_fmt(SF_STRVAL, NULL);
break;
case '%':
g_string_append_c(plain_s, '%');
break;
default:
return FALSE;
}
} else {
g_string_append_c(plain_s, format[pos]);
}
pos++;
}
if (plain_s->len > 0) {
add_string_fmt(SF_NONE, plain_s->str);
}
g_string_free(plain_s, TRUE);
return TRUE;
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
static void
open_failure_message(const char *filename, int err, gboolean for_writing)
{
fprintf(stderr, "rawshark: ");
fprintf(stderr, file_open_error_message(err, for_writing), filename);
fprintf(stderr, "\n");
}
static const nstime_t *
raw_get_frame_ts(void *data _U_, guint32 frame_num)
{
if (ref && ref->num == frame_num)
return &ref->abs_ts;
if (prev_dis && prev_dis->num == frame_num)
return &prev_dis->abs_ts;
if (prev_cap && prev_cap->num == frame_num)
return &prev_cap->abs_ts;
return NULL;
}
static epan_t *
raw_epan_new(capture_file *cf)
{
epan_t *epan = epan_new();
epan->data = cf;
epan->get_frame_ts = raw_get_frame_ts;
epan->get_interface_name = cap_file_get_interface_name;
epan->get_user_comment = NULL;
return epan;
}
cf_status_t
raw_cf_open(capture_file *cf, const char *fname)
{
if ((fd = raw_pipe_open(fname)) < 0)
return CF_ERROR;
epan_free(cf->epan);
cf->epan = raw_epan_new(cf);
cf->wth = NULL;
cf->f_datalen = 0;
cf->filename = g_strdup(fname);
cf->is_tempfile = FALSE;
cf->unsaved_changes = FALSE;
cf->cd_t = WTAP_FILE_TYPE_SUBTYPE_UNKNOWN;
cf->open_type = WTAP_TYPE_AUTO;
cf->count = 0;
cf->drops_known = FALSE;
cf->drops = 0;
cf->has_snap = FALSE;
cf->snap = WTAP_MAX_PACKET_SIZE;
nstime_set_zero(&cf->elapsed_time);
ref = NULL;
prev_dis = NULL;
prev_cap = NULL;
return CF_OK;
}
static void
failure_message(const char *msg_format, va_list ap)
{
fprintf(stderr, "rawshark: ");
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
rawshark_cmdarg_err(const char *fmt, va_list ap)
{
fprintf(stderr, "rawshark: ");
vfprintf(stderr, fmt, ap);
fprintf(stderr, "\n");
}
static void
rawshark_cmdarg_err_cont(const char *fmt, va_list ap)
{
vfprintf(stderr, fmt, ap);
fprintf(stderr, "\n");
}
