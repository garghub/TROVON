static void
enable_kernel_bpf_jit_compiler(void)
{
int fd;
ssize_t written _U_;
static const char file[] = "/proc/sys/net/core/bpf_jit_enable";
fd = ws_open(file, O_WRONLY);
if (fd < 0)
return;
written = write(fd, "1", strlen("1"));
close(fd);
}
static guint64
create_timestamp(void) {
guint64 timestamp;
#ifdef _WIN32
FILETIME now;
#else
struct timeval now;
#endif
#ifdef _WIN32
GetSystemTimeAsFileTime(&now);
timestamp = (((guint64)(guint32)now.dwHighDateTime) << 32) +
(guint32)now.dwLowDateTime;
timestamp /= 10;
timestamp -= G_GUINT64_CONSTANT(11644473600000000);
#else
gettimeofday(&now, NULL);
timestamp = (guint64)(now.tv_sec) * 1000000 +
(guint64)(now.tv_usec);
#endif
return timestamp;
}
static void
print_usage(FILE *output)
{
fprintf(output, "\nUsage: dumpcap [options] ...\n");
fprintf(output, "\n");
fprintf(output, "Capture interface:\n");
fprintf(output, " -i <interface> name or idx of interface (def: first non-loopback),\n"
" or for remote capturing, use one of these formats:\n"
" rpcap://<host>/<interface>\n"
" TCP@<host>:<port>\n");
fprintf(output, " -f <capture filter> packet filter in libpcap filter syntax\n");
fprintf(output, " -s <snaplen> packet snapshot length (def: 65535)\n");
fprintf(output, " -p don't capture in promiscuous mode\n");
#ifdef HAVE_PCAP_CREATE
fprintf(output, " -I capture in monitor mode, if available\n");
#endif
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
fprintf(output, " -B <buffer size> size of kernel buffer in MiB (def: %dMiB)\n", DEFAULT_CAPTURE_BUFFER_SIZE);
#endif
fprintf(output, " -y <link type> link layer type (def: first appropriate)\n");
fprintf(output, " -D print list of interfaces and exit\n");
fprintf(output, " -L print list of link-layer types of iface and exit\n");
#ifdef HAVE_BPF_IMAGE
fprintf(output, " -d print generated BPF code for capture filter\n");
#endif
fprintf(output, " -k set channel on wifi interface <freq>,[<type>]\n");
fprintf(output, " -S print statistics for each interface once per second\n");
fprintf(output, " -M for -D, -L, and -S, produce machine-readable output\n");
fprintf(output, "\n");
#ifdef HAVE_PCAP_REMOTE
fprintf(output, "RPCAP options:\n");
fprintf(output, " -r don't ignore own RPCAP traffic in capture\n");
fprintf(output, " -u use UDP for RPCAP data transfer\n");
fprintf(output, " -A <user>:<password> use RPCAP password authentication\n");
#ifdef HAVE_PCAP_SETSAMPLING
fprintf(output, " -m <sampling type> use packet sampling\n");
fprintf(output, " count:NUM - capture one packet of every NUM\n");
fprintf(output, " timer:NUM - capture no more than 1 packet in NUM ms\n");
#endif
#endif
fprintf(output, "Stop conditions:\n");
fprintf(output, " -c <packet count> stop after n packets (def: infinite)\n");
fprintf(output, " -a <autostop cond.> ... duration:NUM - stop after NUM seconds\n");
fprintf(output, " filesize:NUM - stop this file after NUM KB\n");
fprintf(output, " files:NUM - stop after NUM files\n");
fprintf(output, "Output (files):\n");
fprintf(output, " -w <filename> name of file to save (def: tempfile)\n");
fprintf(output, " -g enable group read access on the output file(s)\n");
fprintf(output, " -b <ringbuffer opt.> ... duration:NUM - switch to next file after NUM secs\n");
fprintf(output, " filesize:NUM - switch to next file after NUM KB\n");
fprintf(output, " files:NUM - ringbuffer: replace after NUM files\n");
fprintf(output, " -n use pcapng format instead of pcap (default)\n");
fprintf(output, " -P use libpcap format instead of pcapng\n");
fprintf(output, " --capture-comment <comment>\n");
fprintf(output, " add a capture comment to the output file\n");
fprintf(output, " (only for pcapng)\n");
fprintf(output, "\n");
fprintf(output, "Miscellaneous:\n");
fprintf(output, " -N <packet_limit> maximum number of packets buffered within dumpcap\n");
fprintf(output, " -C <byte_limit> maximum number of bytes used for buffering packets\n");
fprintf(output, " within dumpcap\n");
fprintf(output, " -t use a separate thread per interface\n");
fprintf(output, " -q don't report packet capture counts\n");
fprintf(output, " -v print version information and exit\n");
fprintf(output, " -h display this help and exit\n");
fprintf(output, "\n");
#ifdef __linux__
fprintf(output, "WARNING: dumpcap will enable kernel BPF JIT compiler if available.\n");
fprintf(output, "You might want to reset it\n");
fprintf(output, "By doing \"echo 0 > /proc/sys/net/core/bpf_jit_enable\"\n");
fprintf(output, "\n");
#endif
fprintf(output, "Example: dumpcap -i eth0 -a duration:60 -w output.pcapng\n");
fprintf(output, "\"Capture packets from interface eth0 until 60s passed into output.pcapng\"\n");
fprintf(output, "\n");
fprintf(output, "Use Ctrl-C to stop capturing at any time.\n");
}
static void
show_version(GString *comp_info_str, GString *runtime_info_str)
{
printf("Dumpcap (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), get_copyright_info(), comp_info_str->str, runtime_info_str->str);
}
static void
dumpcap_cmdarg_err(const char *fmt, va_list ap)
{
if (capture_child) {
gchar *msg;
msg = g_strdup_vprintf(fmt, ap);
sync_pipe_errmsg_to_parent(2, msg, "");
g_free(msg);
} else {
fprintf(stderr, "dumpcap: ");
vfprintf(stderr, fmt, ap);
fprintf(stderr, "\n");
}
}
static void
dumpcap_cmdarg_err_cont(const char *fmt, va_list ap)
{
if (capture_child) {
gchar *msg;
msg = g_strdup_vprintf(fmt, ap);
sync_pipe_errmsg_to_parent(2, msg, "");
g_free(msg);
} else {
vfprintf(stderr, fmt, ap);
fprintf(stderr, "\n");
}
}
static void
#if 0
print_caps(const char *pfx) {
cap_t caps = cap_get_proc();
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG,
"%s: EUID: %d Capabilities: %s", pfx,
geteuid(), cap_to_text(caps, NULL));
cap_free(caps);
#else
print_caps(const char *pfx _U_) {
#endif
}
static void
relinquish_all_capabilities(void)
{
cap_t caps = cap_init();
print_caps("Pre-clear");
if (cap_set_proc(caps)) {
cmdarg_err("cap_set_proc() fail return: %s", g_strerror(errno));
}
print_caps("Post-clear");
cap_free(caps);
}
static void
get_capture_device_open_failure_messages(const char *open_err_str,
const char *iface,
char *errmsg, size_t errmsg_len,
char *secondary_errmsg,
size_t secondary_errmsg_len)
{
#ifndef _WIN32
const char *libpcap_warn;
static const char ppamsg[] = "can't find PPA for ";
#endif
g_snprintf(errmsg, (gulong) errmsg_len,
"The capture session could not be initiated on interface '%s' (%s).",
iface, open_err_str);
#ifdef _WIN32
if (!has_wpcap) {
g_snprintf(secondary_errmsg, (gulong) secondary_errmsg_len,
"\n"
"In order to capture packets, WinPcap must be installed; see\n"
"\n"
" http://www.winpcap.org/\n"
"\n"
"or the mirror at\n"
"\n"
" http://www.mirrors.wiretapped.net/security/packet-capture/winpcap/\n"
"\n"
"or the mirror at\n"
"\n"
" http://winpcap.cs.pu.edu.tw/\n"
"\n"
"for a downloadable version of WinPcap and for instructions on how to install\n"
"WinPcap.");
} else {
g_snprintf(secondary_errmsg, (gulong) secondary_errmsg_len,
"\n"
"Please check that \"%s\" is the proper interface.\n"
"\n"
"\n"
"Help can be found at:\n"
"\n"
" http://wiki.wireshark.org/WinPcap\n"
" http://wiki.wireshark.org/CaptureSetup\n",
iface);
}
#else
if (strncmp(open_err_str, ppamsg, sizeof ppamsg - 1) == 0)
libpcap_warn =
"\n\n"
"You are running (T)Wireshark with a version of the libpcap library\n"
"that doesn't handle HP-UX network devices well; this means that\n"
"(T)Wireshark may not be able to capture packets.\n"
"\n"
"To fix this, you should install libpcap 0.6.2, or a later version\n"
"of libpcap, rather than libpcap 0.4 or 0.5.x. It is available in\n"
"packaged binary form from the Software Porting And Archive Centre\n"
"for HP-UX; the Centre is at http://hpux.connect.org.uk/ - the page\n"
"at the URL lists a number of mirror sites.";
else
libpcap_warn = "";
g_snprintf(secondary_errmsg, (gulong) secondary_errmsg_len,
"Please check to make sure you have sufficient permissions, and that you have "
"the proper interface or pipe specified.%s", libpcap_warn);
#endif
}
static gboolean
set_pcap_linktype(pcap_t *pcap_h, int linktype, char *name,
char *errmsg, size_t errmsg_len,
char *secondary_errmsg, size_t secondary_errmsg_len)
{
char *set_linktype_err_str;
if (linktype == -1)
return TRUE;
#ifdef HAVE_PCAP_SET_DATALINK
if (pcap_set_datalink(pcap_h, linktype) == 0)
return TRUE;
set_linktype_err_str = pcap_geterr(pcap_h);
#else
if (get_pcap_linktype(pcap_h, name) == linktype)
return TRUE;
set_linktype_err_str =
"That DLT isn't one of the DLTs supported by this device";
#endif
g_snprintf(errmsg, (gulong) errmsg_len, "Unable to set data link type on interface '%s' (%s).",
name, set_linktype_err_str);
if (strstr(set_linktype_err_str, "is not one of the DLTs supported by this device") == NULL)
g_snprintf(secondary_errmsg, (gulong) secondary_errmsg_len, please_report);
else
secondary_errmsg[0] = '\0';
return FALSE;
}
static gboolean
compile_capture_filter(const char *iface, pcap_t *pcap_h,
struct bpf_program *fcode, const char *cfilter)
{
bpf_u_int32 netnum, netmask;
gchar lookup_net_err_str[PCAP_ERRBUF_SIZE];
if (pcap_lookupnet(iface, &netnum, &netmask, lookup_net_err_str) < 0) {
netmask = 0;
}
if (pcap_compile(pcap_h, fcode, (char *)cfilter, 1, netmask) < 0)
return FALSE;
return TRUE;
}
static gboolean
show_filter_code(capture_options *capture_opts)
{
interface_options interface_opts;
pcap_t *pcap_h;
gchar open_err_str[PCAP_ERRBUF_SIZE];
char errmsg[MSG_MAX_LENGTH+1];
char secondary_errmsg[MSG_MAX_LENGTH+1];
struct bpf_program fcode;
struct bpf_insn *insn;
u_int i;
guint j;
for (j = 0; j < capture_opts->ifaces->len; j++) {
interface_opts = g_array_index(capture_opts->ifaces, interface_options, j);
pcap_h = open_capture_device(capture_opts, &interface_opts, &open_err_str);
if (pcap_h == NULL) {
get_capture_device_open_failure_messages(open_err_str,
interface_opts.name,
errmsg, sizeof errmsg,
secondary_errmsg,
sizeof secondary_errmsg);
report_capture_error(errmsg, secondary_errmsg);
return FALSE;
}
if (!set_pcap_linktype(pcap_h, interface_opts.linktype, interface_opts.name,
errmsg, sizeof errmsg,
secondary_errmsg, sizeof secondary_errmsg)) {
pcap_close(pcap_h);
report_capture_error(errmsg, secondary_errmsg);
return FALSE;
}
if (!compile_capture_filter(interface_opts.name, pcap_h, &fcode,
interface_opts.cfilter)) {
pcap_close(pcap_h);
report_cfilter_error(capture_opts, j, errmsg);
return FALSE;
}
pcap_close(pcap_h);
insn = fcode.bf_insns;
for (i = 0; i < fcode.bf_len; insn++, i++)
printf("%s\n", bpf_image(insn, i));
}
#ifndef HAVE_LIBCAP
relinquish_special_privs_perm();
#else
relinquish_all_capabilities();
#endif
if (capture_child) {
pipe_write_block(2, SP_SUCCESS, NULL);
}
return TRUE;
}
static int
get_pcap_linktype(pcap_t *pch, const char *devicename
#ifndef _AIX
_U_
#endif
)
{
int linktype;
#ifdef _AIX
const char *ifacename;
#endif
linktype = pcap_datalink(pch);
#ifdef _AIX
ifacename = strchr(devicename, '/');
if (ifacename == NULL)
ifacename = devicename;
if (strncmp(ifacename, "en", 2) == 0) {
if (linktype == 6) {
linktype = 1;
}
} else if (strncmp(ifacename, "et", 2) == 0) {
if (linktype == 7) {
linktype = 1;
}
} else if (strncmp(ifacename, "tr", 2) == 0) {
if (linktype == 9) {
linktype = 6;
}
} else if (strncmp(ifacename, "fi", 2) == 0) {
if (linktype == 15) {
linktype = 10;
}
} else if (strncmp(ifacename, "lo", 2) == 0) {
if (linktype == 24) {
linktype = 0;
}
}
#endif
return linktype;
}
static data_link_info_t *
create_data_link_info(int dlt)
{
data_link_info_t *data_link_info;
const char *text;
data_link_info = (data_link_info_t *)g_malloc(sizeof (data_link_info_t));
data_link_info->dlt = dlt;
text = pcap_datalink_val_to_name(dlt);
if (text != NULL)
data_link_info->name = g_strdup(text);
else
data_link_info->name = g_strdup_printf("DLT %d", dlt);
text = pcap_datalink_val_to_description(dlt);
if (text != NULL)
data_link_info->description = g_strdup(text);
else
data_link_info->description = NULL;
return data_link_info;
}
static if_capabilities_t *
get_if_capabilities(const char *devicename, gboolean monitor_mode
#ifndef HAVE_PCAP_CREATE
_U_
#endif
, char **err_str)
{
if_capabilities_t *caps;
char errbuf[PCAP_ERRBUF_SIZE];
pcap_t *pch;
#ifdef HAVE_PCAP_CREATE
int status;
#endif
int deflt;
#ifdef HAVE_PCAP_LIST_DATALINKS
int *linktypes;
int i, nlt;
#endif
data_link_info_t *data_link_info;
caps = (if_capabilities_t *)g_malloc(sizeof *caps);
errbuf[0] = '\0';
#ifdef HAVE_PCAP_OPEN
pch = pcap_open(devicename, MIN_PACKET_SIZE, 0, 0, NULL, errbuf);
caps->can_set_rfmon = FALSE;
if (pch == NULL) {
if (err_str != NULL)
*err_str = g_strdup(errbuf[0] == '\0' ? "Unknown error (pcap bug; actual error cause not reported)" : errbuf);
g_free(caps);
return NULL;
}
#elif defined(HAVE_PCAP_CREATE)
pch = pcap_create(devicename, errbuf);
if (pch == NULL) {
if (err_str != NULL)
*err_str = g_strdup(errbuf);
g_free(caps);
return NULL;
}
status = pcap_can_set_rfmon(pch);
if (status < 0) {
if (status == PCAP_ERROR)
*err_str = g_strdup_printf("pcap_can_set_rfmon() failed: %s",
pcap_geterr(pch));
else
*err_str = g_strdup(pcap_statustostr(status));
pcap_close(pch);
g_free(caps);
return NULL;
}
if (status == 0)
caps->can_set_rfmon = FALSE;
else if (status == 1) {
caps->can_set_rfmon = TRUE;
if (monitor_mode)
pcap_set_rfmon(pch, 1);
} else {
if (err_str != NULL) {
*err_str = g_strdup_printf("pcap_can_set_rfmon() returned %d",
status);
}
pcap_close(pch);
g_free(caps);
return NULL;
}
status = pcap_activate(pch);
if (status < 0) {
if (err_str != NULL) {
if (status == PCAP_ERROR)
*err_str = g_strdup_printf("pcap_activate() failed: %s",
pcap_geterr(pch));
else
*err_str = g_strdup(pcap_statustostr(status));
}
pcap_close(pch);
g_free(caps);
return NULL;
}
#else
pch = pcap_open_live(devicename, MIN_PACKET_SIZE, 0, 0, errbuf);
caps->can_set_rfmon = FALSE;
if (pch == NULL) {
if (err_str != NULL)
*err_str = g_strdup(errbuf[0] == '\0' ? "Unknown error (pcap bug; actual error cause not reported)" : errbuf);
g_free(caps);
return NULL;
}
#endif
deflt = get_pcap_linktype(pch, devicename);
#ifdef HAVE_PCAP_LIST_DATALINKS
nlt = pcap_list_datalinks(pch, &linktypes);
if (nlt == 0 || linktypes == NULL) {
pcap_close(pch);
if (err_str != NULL)
*err_str = NULL;
g_free(caps);
return NULL;
}
caps->data_link_types = NULL;
for (i = 0; i < nlt; i++) {
data_link_info = create_data_link_info(linktypes[i]);
if (linktypes[i] == deflt)
caps->data_link_types = g_list_prepend(caps->data_link_types,
data_link_info);
else
caps->data_link_types = g_list_append(caps->data_link_types,
data_link_info);
}
#ifdef HAVE_PCAP_FREE_DATALINKS
pcap_free_datalinks(linktypes);
#else
#ifndef _WIN32
#define xx_free free
xx_free(linktypes);
#endif
#endif
#else
data_link_info = create_data_link_info(deflt);
caps->data_link_types = g_list_append(caps->data_link_types,
data_link_info);
#endif
pcap_close(pch);
if (err_str != NULL)
*err_str = NULL;
return caps;
}
static void
print_machine_readable_interfaces(GList *if_list)
{
int i;
GList *if_entry;
if_info_t *if_info;
GSList *addr;
if_addr_t *if_addr;
char addr_str[ADDRSTRLEN];
if (capture_child) {
pipe_write_block(2, SP_SUCCESS, NULL);
}
i = 1;
for (if_entry = g_list_first(if_list); if_entry != NULL;
if_entry = g_list_next(if_entry)) {
if_info = (if_info_t *)if_entry->data;
printf("%d. %s\t", i++, if_info->name);
if (if_info->vendor_description != NULL)
printf("%s\t", if_info->vendor_description);
else
printf("\t");
if (if_info->friendly_name != NULL)
printf("%s\t", if_info->friendly_name);
else
printf("\t");
printf("%i\t", if_info->type);
for (addr = g_slist_nth(if_info->addrs, 0); addr != NULL;
addr = g_slist_next(addr)) {
if (addr != g_slist_nth(if_info->addrs, 0))
printf(",");
if_addr = (if_addr_t *)addr->data;
switch(if_addr->ifat_type) {
case IF_AT_IPv4:
if (inet_ntop(AF_INET, &if_addr->addr.ip4_addr, addr_str,
ADDRSTRLEN)) {
printf("%s", addr_str);
} else {
printf("<unknown IPv4>");
}
break;
case IF_AT_IPv6:
if (inet_ntop(AF_INET6, &if_addr->addr.ip6_addr,
addr_str, ADDRSTRLEN)) {
printf("%s", addr_str);
} else {
printf("<unknown IPv6>");
}
break;
default:
printf("<type unknown %i>", if_addr->ifat_type);
}
}
if (if_info->loopback)
printf("\tloopback");
else
printf("\tnetwork");
#ifdef HAVE_EXTCAP
printf("\t%s", if_info->extcap);
#endif
printf("\n");
}
}
static void
print_machine_readable_if_capabilities(if_capabilities_t *caps)
{
GList *lt_entry;
data_link_info_t *data_link_info;
const gchar *desc_str;
if (capture_child) {
pipe_write_block(2, SP_SUCCESS, NULL);
}
if (caps->can_set_rfmon)
printf("1\n");
else
printf("0\n");
for (lt_entry = caps->data_link_types; lt_entry != NULL;
lt_entry = g_list_next(lt_entry)) {
data_link_info = (data_link_info_t *)lt_entry->data;
if (data_link_info->description != NULL)
desc_str = data_link_info->description;
else
desc_str = "(not supported)";
printf("%d\t%s\t%s\n", data_link_info->dlt, data_link_info->name,
desc_str);
}
}
static int
print_statistics_loop(gboolean machine_readable)
{
GList *if_list, *if_entry, *stat_list = NULL, *stat_entry;
if_info_t *if_info;
if_stat_t *if_stat;
int err;
gchar *err_str;
pcap_t *pch;
char errbuf[PCAP_ERRBUF_SIZE];
struct pcap_stat ps;
if_list = get_interface_list(&err, &err_str);
if (if_list == NULL) {
if (err == 0)
cmdarg_err("There are no interfaces on which a capture can be done");
else {
cmdarg_err("%s", err_str);
g_free(err_str);
}
return err;
}
for (if_entry = g_list_first(if_list); if_entry != NULL; if_entry = g_list_next(if_entry)) {
if_info = (if_info_t *)if_entry->data;
#ifdef HAVE_PCAP_OPEN
pch = pcap_open(if_info->name, MIN_PACKET_SIZE, 0, 0, NULL, errbuf);
#else
pch = pcap_open_live(if_info->name, MIN_PACKET_SIZE, 0, 0, errbuf);
#endif
if (pch) {
if_stat = (if_stat_t *)g_malloc(sizeof(if_stat_t));
if_stat->name = g_strdup(if_info->name);
if_stat->pch = pch;
stat_list = g_list_append(stat_list, if_stat);
}
}
if (!stat_list) {
cmdarg_err("There are no interfaces on which a capture can be done");
return 2;
}
if (capture_child) {
pipe_write_block(2, SP_SUCCESS, NULL);
}
if (!machine_readable) {
printf("%-15s %10s %10s\n", "Interface", "Received",
"Dropped");
}
global_ld.go = TRUE;
while (global_ld.go) {
for (stat_entry = g_list_first(stat_list); stat_entry != NULL; stat_entry = g_list_next(stat_entry)) {
if_stat = (if_stat_t *)stat_entry->data;
pcap_stats(if_stat->pch, &ps);
if (!machine_readable) {
printf("%-15s %10u %10u\n", if_stat->name,
ps.ps_recv, ps.ps_drop);
} else {
printf("%s\t%u\t%u\n", if_stat->name,
ps.ps_recv, ps.ps_drop);
fflush(stdout);
}
}
#ifdef _WIN32
if (!signal_pipe_check_running()) {
global_ld.go = FALSE;
}
Sleep(1 * 1000);
#else
sleep(1);
#endif
}
for (stat_entry = g_list_first(stat_list); stat_entry != NULL; stat_entry = g_list_next(stat_entry)) {
if_stat = (if_stat_t *)stat_entry->data;
pcap_close(if_stat->pch);
g_free(if_stat->name);
g_free(if_stat);
}
g_list_free(stat_list);
free_interface_list(if_list);
return 0;
}
static BOOL WINAPI
capture_cleanup_handler(DWORD dwCtrlType)
{
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO,
"Console: Control signal");
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG,
"Console: Control signal, CtrlType: %u", dwCtrlType);
if (capture_child || (dwCtrlType != CTRL_LOGOFF_EVENT)) {
capture_loop_stop();
return TRUE;
} else {
return FALSE;
}
}
static void
capture_cleanup_handler(int signum _U_)
{
capture_loop_stop();
}
static void
report_capture_count(gboolean reportit)
{
if (!capture_child && reportit) {
fprintf(stderr, "\rPackets captured: %u\n", global_ld.packet_count);
fflush(stderr);
}
}
static void
report_counts_for_siginfo(void)
{
report_capture_count(quiet);
infoprint = FALSE;
}
static void
report_counts_siginfo(int signum _U_)
{
int sav_errno = errno;
if (infodelay)
infoprint = TRUE;
else
report_counts_for_siginfo();
errno = sav_errno;
}
static void
exit_main(int status)
{
#ifdef _WIN32
WSACleanup();
#ifdef DEBUG_DUMPCAP
printf("Press any key\n");
_getch();
#endif
#endif
exit(status);
}
static void
relinquish_privs_except_capture(void)
{
if (started_with_special_privs()) {
cap_value_t cap_list[2] = { CAP_NET_ADMIN, CAP_NET_RAW };
int cl_len = sizeof(cap_list) / sizeof(cap_value_t);
cap_t caps = cap_init();
print_caps("Pre drop, pre set");
if (prctl(PR_SET_KEEPCAPS, 1, 0, 0, 0) == -1) {
cmdarg_err("prctl() fail return: %s", g_strerror(errno));
}
cap_set_flag(caps, CAP_PERMITTED, cl_len, cap_list, CAP_SET);
cap_set_flag(caps, CAP_INHERITABLE, cl_len, cap_list, CAP_SET);
if (cap_set_proc(caps)) {
cmdarg_err("cap_set_proc() fail return: %s", g_strerror(errno));
}
print_caps("Pre drop, post set");
relinquish_special_privs_perm();
print_caps("Post drop, pre set");
cap_set_flag(caps, CAP_EFFECTIVE, cl_len, cap_list, CAP_SET);
if (cap_set_proc(caps)) {
cmdarg_err("cap_set_proc() fail return: %s", g_strerror(errno));
}
print_caps("Post drop, post set");
cap_free(caps);
}
}
static void
cap_pipe_adjust_header(gboolean byte_swapped, struct pcap_hdr *hdr, struct pcaprec_hdr *rechdr)
{
if (byte_swapped) {
rechdr->ts_sec = GUINT32_SWAP_LE_BE(rechdr->ts_sec);
rechdr->ts_usec = GUINT32_SWAP_LE_BE(rechdr->ts_usec);
rechdr->incl_len = GUINT32_SWAP_LE_BE(rechdr->incl_len);
rechdr->orig_len = GUINT32_SWAP_LE_BE(rechdr->orig_len);
}
if (hdr->version_major == 2 &&
(hdr->version_minor < 3 ||
(hdr->version_minor == 3 && rechdr->incl_len > rechdr->orig_len))) {
guint32 temp;
temp = rechdr->orig_len;
rechdr->orig_len = rechdr->incl_len;
rechdr->incl_len = temp;
}
}
static ssize_t
cap_pipe_read(int pipe_fd, char *buf, size_t sz, gboolean from_socket _U_)
{
#ifdef _WIN32
if (from_socket) {
return recv(pipe_fd, buf, (int)sz, 0);
} else {
return -1;
}
#else
return ws_read(pipe_fd, buf, sz);
#endif
}
static void *cap_thread_read(void *arg)
{
pcap_options *pcap_opts;
#ifdef _WIN32
BOOL res;
DWORD b, last_err, bytes_read;
#else
size_t bytes_read;
int b;
#endif
pcap_opts = (pcap_options *)arg;
while (pcap_opts->cap_pipe_err == PIPOK) {
g_async_queue_pop(pcap_opts->cap_pipe_pending_q);
g_mutex_lock(pcap_opts->cap_pipe_read_mtx);
bytes_read = 0;
while (bytes_read < pcap_opts->cap_pipe_bytes_to_read) {
if ((pcap_opts->from_cap_socket)
#ifndef _WIN32
|| 1
#endif
)
{
b = cap_pipe_read(pcap_opts->cap_pipe_fd, pcap_opts->cap_pipe_buf+bytes_read,
pcap_opts->cap_pipe_bytes_to_read - bytes_read, pcap_opts->from_cap_socket);
if (b <= 0) {
if (b == 0) {
pcap_opts->cap_pipe_err = PIPEOF;
bytes_read = 0;
break;
} else {
pcap_opts->cap_pipe_err = PIPERR;
bytes_read = -1;
break;
}
} else {
bytes_read += b;
}
}
#ifdef _WIN32
else
{
res = ReadFile(pcap_opts->cap_pipe_h, pcap_opts->cap_pipe_buf+bytes_read,
pcap_opts->cap_pipe_bytes_to_read - bytes_read,
&b, NULL);
bytes_read += b;
if (!res) {
last_err = GetLastError();
if (last_err == ERROR_MORE_DATA) {
continue;
} else if (last_err == ERROR_HANDLE_EOF || last_err == ERROR_BROKEN_PIPE || last_err == ERROR_PIPE_NOT_CONNECTED) {
pcap_opts->cap_pipe_err = PIPEOF;
bytes_read = 0;
break;
}
pcap_opts->cap_pipe_err = PIPERR;
bytes_read = -1;
break;
} else if (b == 0 && pcap_opts->cap_pipe_bytes_to_read > 0) {
pcap_opts->cap_pipe_err = PIPEOF;
bytes_read = 0;
break;
}
}
#endif
}
pcap_opts->cap_pipe_bytes_read = bytes_read;
if (pcap_opts->cap_pipe_bytes_read >= pcap_opts->cap_pipe_bytes_to_read) {
g_async_queue_push(pcap_opts->cap_pipe_done_q, pcap_opts->cap_pipe_buf);
}
g_mutex_unlock(pcap_opts->cap_pipe_read_mtx);
}
return NULL;
}
static int
cap_pipe_select(int pipe_fd)
{
fd_set rfds;
struct timeval timeout;
FD_ZERO(&rfds);
FD_SET(pipe_fd, &rfds);
timeout.tv_sec = PIPE_READ_TIMEOUT / 1000000;
timeout.tv_usec = PIPE_READ_TIMEOUT % 1000000;
return select(pipe_fd+1, &rfds, NULL, NULL, &timeout);
}
static int
cap_open_socket(char *pipename, pcap_options *pcap_opts, char *errmsg, int errmsgl)
{
char *sockname = pipename + 4;
struct sockaddr_in sa;
char buf[16];
char *p;
unsigned long port;
size_t len;
int fd;
memset(&sa, 0, sizeof(sa));
p = strchr(sockname, ':');
if (p == NULL) {
len = strlen(sockname);
port = DEF_TCP_PORT;
}
else {
len = p - sockname;
port = strtoul(p + 1, &p, 10);
if (*p || port > 65535) {
goto fail_invalid;
}
}
if (len > 15) {
goto fail_invalid;
}
g_snprintf ( buf,(gulong)len + 1, "%s", sockname );
buf[len] = '\0';
if (inet_pton(AF_INET, buf, &sa.sin_addr) <= 0) {
goto fail_invalid;
}
sa.sin_family = AF_INET;
sa.sin_port = g_htons((u_short)port);
if (((fd = (int)socket(AF_INET, SOCK_STREAM, 0)) < 0) ||
(connect(fd, (struct sockaddr *)&sa, sizeof(sa)) < 0)) {
#ifdef _WIN32
LPTSTR errorText = NULL;
int lastError;
lastError = WSAGetLastError();
FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM |
FORMAT_MESSAGE_ALLOCATE_BUFFER |
FORMAT_MESSAGE_IGNORE_INSERTS,
NULL, lastError, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
(LPTSTR)&errorText, 0, NULL);
#endif
g_snprintf(errmsg, errmsgl,
"The capture session could not be initiated due to the socket error: \n"
#ifdef _WIN32
" %d: %S", lastError, errorText ? (char *)errorText : "Unknown");
if (errorText)
LocalFree(errorText);
#else
" %d: %s", errno, g_strerror(errno));
#endif
pcap_opts->cap_pipe_err = PIPERR;
if (fd >= 0)
cap_pipe_close(fd, TRUE);
return -1;
}
void
cap_pipe_close(int pipe_fd, gboolean from_socket _U_)
{
#ifdef _WIN32
if (from_socket) {
closesocket(pipe_fd);
}
#else
ws_close(pipe_fd);
#endif
}
static void
cap_pipe_open_live(char *pipename,
pcap_options *pcap_opts,
struct pcap_hdr *hdr,
char *errmsg, int errmsgl)
{
#ifndef _WIN32
ws_statb64 pipe_stat;
struct sockaddr_un sa;
#else
char *pncopy, *pos;
wchar_t *err_str;
interface_options interface_opts;
#endif
ssize_t b;
int fd = -1, sel_ret;
size_t bytes_read;
guint32 magic = 0;
pcap_opts->cap_pipe_fd = -1;
#ifdef _WIN32
pcap_opts->cap_pipe_h = INVALID_HANDLE_VALUE;
#endif
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "cap_pipe_open_live: %s", pipename);
if (strcmp(pipename, "-") == 0) {
#ifndef _WIN32
fd = 0;
#else
pcap_opts->cap_pipe_h = GetStdHandle(STD_INPUT_HANDLE);
#endif
} else if (!strncmp(pipename, "TCP@", 4)) {
if ((fd = cap_open_socket(pipename, pcap_opts, errmsg, errmsgl)) < 0) {
return;
}
} else {
#ifndef _WIN32
if (ws_stat64(pipename, &pipe_stat) < 0) {
if (errno == ENOENT || errno == ENOTDIR)
pcap_opts->cap_pipe_err = PIPNEXIST;
else {
g_snprintf(errmsg, errmsgl,
"The capture session could not be initiated "
"due to error getting information on pipe/socket: %s", g_strerror(errno));
pcap_opts->cap_pipe_err = PIPERR;
}
return;
}
if (S_ISFIFO(pipe_stat.st_mode)) {
fd = ws_open(pipename, O_RDONLY | O_NONBLOCK, 0000 );
if (fd == -1) {
g_snprintf(errmsg, errmsgl,
"The capture session could not be initiated "
"due to error on pipe open: %s", g_strerror(errno));
pcap_opts->cap_pipe_err = PIPERR;
return;
}
} else if (S_ISSOCK(pipe_stat.st_mode)) {
fd = socket(AF_UNIX, SOCK_STREAM, 0);
if (fd == -1) {
g_snprintf(errmsg, errmsgl,
"The capture session could not be initiated "
"due to error on socket create: %s", g_strerror(errno));
pcap_opts->cap_pipe_err = PIPERR;
return;
}
sa.sun_family = AF_UNIX;
if (g_strlcpy(sa.sun_path, pipename, sizeof sa.sun_path) > sizeof sa.sun_path) {
g_snprintf(errmsg, errmsgl,
"The capture session coud not be initiated "
"due to error on socket connect: Path name too long");
pcap_opts->cap_pipe_err = PIPERR;
ws_close(fd);
return;
}
b = connect(fd, (struct sockaddr *)&sa, sizeof sa);
if (b == -1) {
g_snprintf(errmsg, errmsgl,
"The capture session coud not be initiated "
"due to error on socket connect: %s", g_strerror(errno));
pcap_opts->cap_pipe_err = PIPERR;
ws_close(fd);
return;
}
} else {
if (S_ISCHR(pipe_stat.st_mode)) {
pcap_opts->cap_pipe_err = PIPNEXIST;
} else {
g_snprintf(errmsg, errmsgl,
"The capture session could not be initiated because\n"
"\"%s\" is neither an interface nor a socket nor a pipe", pipename);
pcap_opts->cap_pipe_err = PIPERR;
}
return;
}
#else
#define PIPE_STR "\\pipe\\"
pncopy = g_strdup(pipename);
if ( (pos=strstr(pncopy, "\\\\")) == pncopy) {
pos = strchr(pncopy + 3, '\\');
if (pos && g_ascii_strncasecmp(pos, PIPE_STR, strlen(PIPE_STR)) != 0)
pos = NULL;
}
g_free(pncopy);
if (!pos) {
g_snprintf(errmsg, errmsgl,
"The capture session could not be initiated because\n"
"\"%s\" is neither an interface nor a pipe", pipename);
pcap_opts->cap_pipe_err = PIPNEXIST;
return;
}
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, 0);
while (1) {
if(strncmp(interface_opts.name,"\\\\.\\pipe\\",9)== 0)
pcap_opts->cap_pipe_h = GetStdHandle(STD_INPUT_HANDLE);
else
pcap_opts->cap_pipe_h = CreateFile(utf_8to16(pipename), GENERIC_READ, 0, NULL,
OPEN_EXISTING, 0, NULL);
if (pcap_opts->cap_pipe_h != INVALID_HANDLE_VALUE)
break;
if (GetLastError() != ERROR_PIPE_BUSY) {
FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
NULL, GetLastError(), 0, (LPTSTR) &err_str, 0, NULL);
g_snprintf(errmsg, errmsgl,
"The capture session on \"%s\" could not be started "
"due to error on pipe open: %s (error %d)",
pipename, utf_16to8(err_str), GetLastError());
LocalFree(err_str);
pcap_opts->cap_pipe_err = PIPERR;
return;
}
if (!WaitNamedPipe(utf_8to16(pipename), 30 * 1000)) {
FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
NULL, GetLastError(), 0, (LPTSTR) &err_str, 0, NULL);
g_snprintf(errmsg, errmsgl,
"The capture session on \"%s\" timed out during "
"pipe open: %s (error %d)",
pipename, utf_16to8(err_str), GetLastError());
LocalFree(err_str);
pcap_opts->cap_pipe_err = PIPERR;
return;
}
}
#endif
}
pcap_opts->from_cap_pipe = TRUE;
#ifdef _WIN32
if (pcap_opts->from_cap_socket)
#endif
{
bytes_read = 0;
while (bytes_read < sizeof magic) {
if (fd == -1) {
g_snprintf(errmsg, errmsgl, "Invalid file descriptor");
goto error;
}
sel_ret = cap_pipe_select(fd);
if (sel_ret < 0) {
g_snprintf(errmsg, errmsgl,
"Unexpected error from select: %s", g_strerror(errno));
goto error;
} else if (sel_ret > 0) {
b = cap_pipe_read(fd, ((char *)&magic)+bytes_read,
sizeof magic-bytes_read,
pcap_opts->from_cap_socket);
if (b <= 0) {
if (b == 0)
g_snprintf(errmsg, errmsgl, "End of file on pipe magic during open");
else
g_snprintf(errmsg, errmsgl, "Error on pipe magic during open: %s",
g_strerror(errno));
goto error;
}
bytes_read += b;
}
}
}
#ifdef _WIN32
else {
#if GLIB_CHECK_VERSION(2,31,0)
g_thread_new("cap_pipe_open_live", &cap_thread_read, pcap_opts);
#else
g_thread_create(&cap_thread_read, pcap_opts, FALSE, NULL);
#endif
pcap_opts->cap_pipe_buf = (char *) &magic;
pcap_opts->cap_pipe_bytes_read = 0;
pcap_opts->cap_pipe_bytes_to_read = sizeof(magic);
g_async_queue_push(pcap_opts->cap_pipe_pending_q, pcap_opts->cap_pipe_buf);
g_async_queue_pop(pcap_opts->cap_pipe_done_q);
if (pcap_opts->cap_pipe_bytes_read <= 0) {
if (pcap_opts->cap_pipe_bytes_read == 0)
g_snprintf(errmsg, errmsgl, "End of file on pipe magic during open");
else
g_snprintf(errmsg, errmsgl, "Error on pipe magic during open: %s",
g_strerror(errno));
goto error;
}
}
#endif
switch (magic) {
case PCAP_MAGIC:
case PCAP_NSEC_MAGIC:
pcap_opts->cap_pipe_byte_swapped = FALSE;
pcap_opts->cap_pipe_modified = FALSE;
pcap_opts->ts_nsec = magic == PCAP_NSEC_MAGIC;
break;
case PCAP_MODIFIED_MAGIC:
pcap_opts->cap_pipe_byte_swapped = FALSE;
pcap_opts->cap_pipe_modified = TRUE;
break;
case PCAP_SWAPPED_MAGIC:
case PCAP_SWAPPED_NSEC_MAGIC:
pcap_opts->cap_pipe_byte_swapped = TRUE;
pcap_opts->cap_pipe_modified = FALSE;
pcap_opts->ts_nsec = magic == PCAP_SWAPPED_NSEC_MAGIC;
break;
case PCAP_SWAPPED_MODIFIED_MAGIC:
pcap_opts->cap_pipe_byte_swapped = TRUE;
pcap_opts->cap_pipe_modified = TRUE;
break;
default:
g_snprintf(errmsg, errmsgl, "Unrecognized libpcap format");
goto error;
}
#ifdef _WIN32
if (pcap_opts->from_cap_socket)
#endif
{
bytes_read = 0;
while (bytes_read < sizeof(struct pcap_hdr)) {
sel_ret = cap_pipe_select(fd);
if (sel_ret < 0) {
g_snprintf(errmsg, errmsgl,
"Unexpected error from select: %s", g_strerror(errno));
goto error;
} else if (sel_ret > 0) {
b = cap_pipe_read(fd, ((char *)hdr)+bytes_read,
sizeof(struct pcap_hdr) - bytes_read,
pcap_opts->from_cap_socket);
if (b <= 0) {
if (b == 0)
g_snprintf(errmsg, errmsgl, "End of file on pipe header during open");
else
g_snprintf(errmsg, errmsgl, "Error on pipe header during open: %s",
g_strerror(errno));
goto error;
}
bytes_read += b;
}
}
}
#ifdef _WIN32
else {
pcap_opts->cap_pipe_buf = (char *) hdr;
pcap_opts->cap_pipe_bytes_read = 0;
pcap_opts->cap_pipe_bytes_to_read = sizeof(struct pcap_hdr);
g_async_queue_push(pcap_opts->cap_pipe_pending_q, pcap_opts->cap_pipe_buf);
g_async_queue_pop(pcap_opts->cap_pipe_done_q);
if (pcap_opts->cap_pipe_bytes_read <= 0) {
if (pcap_opts->cap_pipe_bytes_read == 0)
g_snprintf(errmsg, errmsgl, "End of file on pipe header during open");
else
g_snprintf(errmsg, errmsgl, "Error on pipe header header during open: %s",
g_strerror(errno));
goto error;
}
}
#endif
if (pcap_opts->cap_pipe_byte_swapped) {
hdr->version_major = GUINT16_SWAP_LE_BE(hdr->version_major);
hdr->version_minor = GUINT16_SWAP_LE_BE(hdr->version_minor);
hdr->snaplen = GUINT32_SWAP_LE_BE(hdr->snaplen);
hdr->network = GUINT32_SWAP_LE_BE(hdr->network);
}
pcap_opts->linktype = hdr->network;
if (hdr->version_major < 2) {
g_snprintf(errmsg, errmsgl, "Unable to read old libpcap format");
goto error;
}
pcap_opts->cap_pipe_state = STATE_EXPECT_REC_HDR;
pcap_opts->cap_pipe_err = PIPOK;
pcap_opts->cap_pipe_fd = fd;
return;
error:
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "cap_pipe_open_live: error %s", errmsg);
pcap_opts->cap_pipe_err = PIPERR;
cap_pipe_close(fd, pcap_opts->from_cap_socket);
pcap_opts->cap_pipe_fd = -1;
}
static int
cap_pipe_dispatch(loop_data *ld, pcap_options *pcap_opts, guchar *data, char *errmsg, int errmsgl)
{
struct pcap_pkthdr phdr;
enum { PD_REC_HDR_READ, PD_DATA_READ, PD_PIPE_EOF, PD_PIPE_ERR,
PD_ERR } result;
#ifdef _WIN32
#if !GLIB_CHECK_VERSION(2,31,18)
GTimeVal wait_time;
#endif
gpointer q_status;
wchar_t *err_str;
#endif
ssize_t b;
#ifdef LOG_CAPTURE_VERBOSE
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "cap_pipe_dispatch");
#endif
switch (pcap_opts->cap_pipe_state) {
case STATE_EXPECT_REC_HDR:
#ifdef _WIN32
if (g_mutex_trylock(pcap_opts->cap_pipe_read_mtx)) {
#endif
pcap_opts->cap_pipe_state = STATE_READ_REC_HDR;
pcap_opts->cap_pipe_bytes_to_read = pcap_opts->cap_pipe_modified ?
sizeof(struct pcaprec_modified_hdr) : sizeof(struct pcaprec_hdr);
pcap_opts->cap_pipe_bytes_read = 0;
#ifdef _WIN32
pcap_opts->cap_pipe_buf = (char *) &pcap_opts->cap_pipe_rechdr;
g_async_queue_push(pcap_opts->cap_pipe_pending_q, pcap_opts->cap_pipe_buf);
g_mutex_unlock(pcap_opts->cap_pipe_read_mtx);
}
#endif
case STATE_READ_REC_HDR:
#ifdef _WIN32
if (pcap_opts->from_cap_socket)
#endif
{
b = cap_pipe_read(pcap_opts->cap_pipe_fd, ((char *)&pcap_opts->cap_pipe_rechdr)+pcap_opts->cap_pipe_bytes_read,
pcap_opts->cap_pipe_bytes_to_read - pcap_opts->cap_pipe_bytes_read, pcap_opts->from_cap_socket);
if (b <= 0) {
if (b == 0)
result = PD_PIPE_EOF;
else
result = PD_PIPE_ERR;
break;
}
pcap_opts->cap_pipe_bytes_read += b;
}
#ifdef _WIN32
else {
#if GLIB_CHECK_VERSION(2,31,18)
q_status = g_async_queue_timeout_pop(pcap_opts->cap_pipe_done_q, PIPE_READ_TIMEOUT);
#else
g_get_current_time(&wait_time);
g_time_val_add(&wait_time, PIPE_READ_TIMEOUT);
q_status = g_async_queue_timed_pop(pcap_opts->cap_pipe_done_q, &wait_time);
#endif
if (pcap_opts->cap_pipe_err == PIPEOF) {
result = PD_PIPE_EOF;
break;
} else if (pcap_opts->cap_pipe_err == PIPERR) {
result = PD_PIPE_ERR;
break;
}
if (!q_status) {
return 0;
}
}
#endif
if (pcap_opts->cap_pipe_bytes_read < pcap_opts->cap_pipe_bytes_to_read)
return 0;
result = PD_REC_HDR_READ;
break;
case STATE_EXPECT_DATA:
#ifdef _WIN32
if (g_mutex_trylock(pcap_opts->cap_pipe_read_mtx)) {
#endif
pcap_opts->cap_pipe_state = STATE_READ_DATA;
pcap_opts->cap_pipe_bytes_to_read = pcap_opts->cap_pipe_rechdr.hdr.incl_len;
pcap_opts->cap_pipe_bytes_read = 0;
#ifdef _WIN32
pcap_opts->cap_pipe_buf = (char *) data;
g_async_queue_push(pcap_opts->cap_pipe_pending_q, pcap_opts->cap_pipe_buf);
g_mutex_unlock(pcap_opts->cap_pipe_read_mtx);
}
#endif
case STATE_READ_DATA:
#ifdef _WIN32
if (pcap_opts->from_cap_socket)
#endif
{
b = cap_pipe_read(pcap_opts->cap_pipe_fd,
data+pcap_opts->cap_pipe_bytes_read,
pcap_opts->cap_pipe_bytes_to_read - pcap_opts->cap_pipe_bytes_read,
pcap_opts->from_cap_socket);
if (b <= 0) {
if (b == 0)
result = PD_PIPE_EOF;
else
result = PD_PIPE_ERR;
break;
}
pcap_opts->cap_pipe_bytes_read += b;
}
#ifdef _WIN32
else {
#if GLIB_CHECK_VERSION(2,31,18)
q_status = g_async_queue_timeout_pop(pcap_opts->cap_pipe_done_q, PIPE_READ_TIMEOUT);
#else
g_get_current_time(&wait_time);
g_time_val_add(&wait_time, PIPE_READ_TIMEOUT);
q_status = g_async_queue_timed_pop(pcap_opts->cap_pipe_done_q, &wait_time);
#endif
if (pcap_opts->cap_pipe_err == PIPEOF) {
result = PD_PIPE_EOF;
break;
} else if (pcap_opts->cap_pipe_err == PIPERR) {
result = PD_PIPE_ERR;
break;
}
if (!q_status) {
return 0;
}
}
#endif
if (pcap_opts->cap_pipe_bytes_read < pcap_opts->cap_pipe_bytes_to_read)
return 0;
result = PD_DATA_READ;
break;
default:
g_snprintf(errmsg, errmsgl, "cap_pipe_dispatch: invalid state");
result = PD_ERR;
}
switch (result) {
case PD_REC_HDR_READ:
cap_pipe_adjust_header(pcap_opts->cap_pipe_byte_swapped, &pcap_opts->cap_pipe_hdr,
&pcap_opts->cap_pipe_rechdr.hdr);
if (pcap_opts->cap_pipe_rechdr.hdr.incl_len > WTAP_MAX_PACKET_SIZE) {
g_snprintf(errmsg, errmsgl, "Frame %u too long (%d bytes)",
ld->packet_count+1, pcap_opts->cap_pipe_rechdr.hdr.incl_len);
break;
}
if (pcap_opts->cap_pipe_rechdr.hdr.incl_len) {
pcap_opts->cap_pipe_state = STATE_EXPECT_DATA;
return 0;
}
case PD_DATA_READ:
phdr.ts.tv_sec = pcap_opts->cap_pipe_rechdr.hdr.ts_sec;
phdr.ts.tv_usec = pcap_opts->cap_pipe_rechdr.hdr.ts_usec;
phdr.caplen = pcap_opts->cap_pipe_rechdr.hdr.incl_len;
phdr.len = pcap_opts->cap_pipe_rechdr.hdr.orig_len;
if (use_threads) {
capture_loop_queue_packet_cb((u_char *)pcap_opts, &phdr, data);
} else {
capture_loop_write_packet_cb((u_char *)pcap_opts, &phdr, data);
}
pcap_opts->cap_pipe_state = STATE_EXPECT_REC_HDR;
return 1;
case PD_PIPE_EOF:
pcap_opts->cap_pipe_err = PIPEOF;
return -1;
case PD_PIPE_ERR:
#ifdef _WIN32
FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
NULL, GetLastError(), 0, (LPTSTR) &err_str, 0, NULL);
g_snprintf(errmsg, errmsgl,
"Error reading from pipe: %s (error %d)",
utf_16to8(err_str), GetLastError());
LocalFree(err_str);
#else
g_snprintf(errmsg, errmsgl, "Error reading from pipe: %s",
g_strerror(errno));
#endif
case PD_ERR:
break;
}
pcap_opts->cap_pipe_err = PIPERR;
return -1;
}
static void capture_loop_close_input(loop_data *ld)
{
guint i;
pcap_options *pcap_opts;
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_close_input");
for (i = 0; i < ld->pcaps->len; i++) {
pcap_opts = g_array_index(ld->pcaps, pcap_options *, i);
if (pcap_opts->cap_pipe_fd >= 0) {
g_assert(pcap_opts->from_cap_pipe);
cap_pipe_close(pcap_opts->cap_pipe_fd, pcap_opts->from_cap_socket);
pcap_opts->cap_pipe_fd = -1;
}
#ifdef _WIN32
if (pcap_opts->cap_pipe_h != INVALID_HANDLE_VALUE) {
CloseHandle(pcap_opts->cap_pipe_h);
pcap_opts->cap_pipe_h = INVALID_HANDLE_VALUE;
}
#endif
if (pcap_opts->pcap_h != NULL) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_close_input: closing %p", (void *)pcap_opts->pcap_h);
pcap_close(pcap_opts->pcap_h);
pcap_opts->pcap_h = NULL;
}
}
ld->go = FALSE;
#ifdef _WIN32
WSACleanup();
#endif
}
static initfilter_status_t
capture_loop_init_filter(pcap_t *pcap_h, gboolean from_cap_pipe,
const gchar * name, const gchar * cfilter)
{
struct bpf_program fcode;
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_init_filter: %s", cfilter);
if (cfilter && !from_cap_pipe) {
if (!compile_capture_filter(name, pcap_h, &fcode, cfilter)) {
return INITFILTER_BAD_FILTER;
}
if (pcap_setfilter(pcap_h, &fcode) < 0) {
#ifdef HAVE_PCAP_FREECODE
pcap_freecode(&fcode);
#endif
return INITFILTER_OTHER_ERROR;
}
#ifdef HAVE_PCAP_FREECODE
pcap_freecode(&fcode);
#endif
}
return INITFILTER_NO_ERROR;
}
static gboolean
capture_loop_init_output(capture_options *capture_opts, loop_data *ld, char *errmsg, int errmsg_len)
{
int err;
guint i;
pcap_options *pcap_opts;
interface_options interface_opts;
gboolean successful;
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_init_output");
if ((capture_opts->use_pcapng == FALSE) &&
(capture_opts->ifaces->len > 1)) {
g_snprintf(errmsg, errmsg_len,
"Using PCAPNG is required for capturing on multiple interfaces. Use the -n option.");
return FALSE;
}
if (capture_opts->multi_files_on) {
ld->pdh = ringbuf_init_libpcap_fdopen(&err);
} else {
ld->pdh = ws_fdopen(ld->save_file_fd, "wb");
if (ld->pdh == NULL) {
err = errno;
}
}
if (ld->pdh) {
if (capture_opts->use_pcapng) {
char appname[100];
GString *os_info_str;
os_info_str = g_string_new("");
get_os_version_info(os_info_str);
g_snprintf(appname, sizeof(appname), "Dumpcap (Wireshark) %s", get_ws_vcs_version_info());
successful = pcapng_write_session_header_block(ld->pdh,
(const char *)capture_opts->capture_comment,
NULL,
os_info_str->str,
appname,
-1,
&ld->bytes_written,
&err);
for (i = 0; successful && (i < capture_opts->ifaces->len); i++) {
interface_opts = g_array_index(capture_opts->ifaces, interface_options, i);
pcap_opts = g_array_index(ld->pcaps, pcap_options *, i);
if (pcap_opts->from_cap_pipe) {
pcap_opts->snaplen = pcap_opts->cap_pipe_hdr.snaplen;
} else {
pcap_opts->snaplen = pcap_snapshot(pcap_opts->pcap_h);
}
successful = pcapng_write_interface_description_block(global_ld.pdh,
NULL,
interface_opts.name,
interface_opts.descr,
interface_opts.cfilter,
os_info_str->str,
pcap_opts->linktype,
pcap_opts->snaplen,
&(global_ld.bytes_written),
0,
pcap_opts->ts_nsec ? 9 : 6,
&global_ld.err);
}
g_string_free(os_info_str, TRUE);
} else {
pcap_opts = g_array_index(ld->pcaps, pcap_options *, 0);
if (pcap_opts->from_cap_pipe) {
pcap_opts->snaplen = pcap_opts->cap_pipe_hdr.snaplen;
} else {
pcap_opts->snaplen = pcap_snapshot(pcap_opts->pcap_h);
}
successful = libpcap_write_file_header(ld->pdh, pcap_opts->linktype, pcap_opts->snaplen,
pcap_opts->ts_nsec, &ld->bytes_written, &err);
}
if (!successful) {
fclose(ld->pdh);
ld->pdh = NULL;
}
}
if (ld->pdh == NULL) {
switch (err) {
default:
if (err < 0) {
g_snprintf(errmsg, errmsg_len,
"The file to which the capture would be"
" saved (\"%s\") could not be opened: Error %d.",
capture_opts->save_file, err);
} else {
g_snprintf(errmsg, errmsg_len,
"The file to which the capture would be"
" saved (\"%s\") could not be opened: %s.",
capture_opts->save_file, g_strerror(err));
}
break;
}
return FALSE;
}
return TRUE;
}
static gboolean
capture_loop_close_output(capture_options *capture_opts, loop_data *ld, int *err_close)
{
unsigned int i;
pcap_options *pcap_opts;
guint64 end_time = create_timestamp();
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_close_output");
if (capture_opts->multi_files_on) {
return ringbuf_libpcap_dump_close(&capture_opts->save_file, err_close);
} else {
if (capture_opts->use_pcapng) {
for (i = 0; i < global_ld.pcaps->len; i++) {
pcap_opts = g_array_index(global_ld.pcaps, pcap_options *, i);
if (!pcap_opts->from_cap_pipe) {
guint64 isb_ifrecv, isb_ifdrop;
struct pcap_stat stats;
if (pcap_stats(pcap_opts->pcap_h, &stats) >= 0) {
isb_ifrecv = pcap_opts->received;
isb_ifdrop = stats.ps_drop + pcap_opts->dropped + pcap_opts->flushed;
} else {
isb_ifrecv = G_MAXUINT64;
isb_ifdrop = G_MAXUINT64;
}
pcapng_write_interface_statistics_block(ld->pdh,
i,
&ld->bytes_written,
"Counters provided by dumpcap",
start_time,
end_time,
isb_ifrecv,
isb_ifdrop,
err_close);
}
}
}
if (fclose(ld->pdh) == EOF) {
if (err_close != NULL) {
*err_close = errno;
}
return (FALSE);
} else {
return (TRUE);
}
}
}
static int
capture_loop_dispatch(loop_data *ld,
char *errmsg, int errmsg_len, pcap_options *pcap_opts)
{
int inpkts;
gint packet_count_before;
guchar pcap_data[WTAP_MAX_PACKET_SIZE];
#ifndef _WIN32
int sel_ret;
#endif
packet_count_before = ld->packet_count;
if (pcap_opts->from_cap_pipe) {
#ifdef LOG_CAPTURE_VERBOSE
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_dispatch: from capture pipe");
#endif
#ifndef _WIN32
sel_ret = cap_pipe_select(pcap_opts->cap_pipe_fd);
if (sel_ret <= 0) {
if (sel_ret < 0 && errno != EINTR) {
g_snprintf(errmsg, errmsg_len,
"Unexpected error from select: %s", g_strerror(errno));
report_capture_error(errmsg, please_report);
ld->go = FALSE;
}
} else {
#endif
inpkts = cap_pipe_dispatch(ld, pcap_opts, pcap_data, errmsg, errmsg_len);
if (inpkts < 0) {
ld->go = FALSE;
}
#ifndef _WIN32
}
#endif
}
else
{
#ifdef MUST_DO_SELECT
#ifdef LOG_CAPTURE_VERBOSE
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_dispatch: from pcap_dispatch with select");
#endif
if (pcap_opts->pcap_fd != -1) {
sel_ret = cap_pipe_select(pcap_opts->pcap_fd);
if (sel_ret > 0) {
if (use_threads) {
inpkts = pcap_dispatch(pcap_opts->pcap_h, 1, capture_loop_queue_packet_cb, (u_char *)pcap_opts);
} else {
inpkts = pcap_dispatch(pcap_opts->pcap_h, 1, capture_loop_write_packet_cb, (u_char *)pcap_opts);
}
if (inpkts < 0) {
if (inpkts == -1) {
pcap_opts->pcap_err = TRUE;
}
ld->go = FALSE;
}
} else {
if (sel_ret < 0 && errno != EINTR) {
g_snprintf(errmsg, errmsg_len,
"Unexpected error from select: %s", g_strerror(errno));
report_capture_error(errmsg, please_report);
ld->go = FALSE;
}
}
}
else
#endif
{
#if 1
#ifdef LOG_CAPTURE_VERBOSE
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_dispatch: from pcap_dispatch");
#endif
#ifdef _WIN32
if (use_threads) {
inpkts = pcap_dispatch(pcap_opts->pcap_h, 1, capture_loop_queue_packet_cb, (u_char *)pcap_opts);
} else {
inpkts = pcap_dispatch(pcap_opts->pcap_h, 1, capture_loop_write_packet_cb, (u_char *)pcap_opts);
}
#else
if (use_threads) {
inpkts = pcap_dispatch(pcap_opts->pcap_h, -1, capture_loop_queue_packet_cb, (u_char *)pcap_opts);
} else {
inpkts = pcap_dispatch(pcap_opts->pcap_h, -1, capture_loop_write_packet_cb, (u_char *)pcap_opts);
}
#endif
if (inpkts < 0) {
if (inpkts == -1) {
pcap_opts->pcap_err = TRUE;
}
ld->go = FALSE;
}
#else
#ifdef LOG_CAPTURE_VERBOSE
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_dispatch: from pcap_next_ex");
#endif
{
int in;
struct pcap_pkthdr *pkt_header;
u_char *pkt_data;
in = 0;
while(ld->go &&
(in = pcap_next_ex(pcap_opts->pcap_h, &pkt_header, &pkt_data)) == 1) {
if (use_threads) {
capture_loop_queue_packet_cb((u_char *)pcap_opts, pkt_header, pkt_data);
} else {
capture_loop_write_packet_cb((u_char *)pcap_opts, pkt_header, pkt_data);
}
}
if (in < 0) {
pcap_opts->pcap_err = TRUE;
ld->go = FALSE;
}
}
#endif
}
}
#ifdef LOG_CAPTURE_VERBOSE
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_dispatch: %d new packet%s", inpkts, plurality(inpkts, "", "s"));
#endif
return ld->packet_count - packet_count_before;
}
static GString *
isolate_uuid(const char *iface)
{
gchar *ptr;
GString *gstr;
ptr = strchr(iface, '{');
if (ptr == NULL)
return g_string_new(iface);
gstr = g_string_new(ptr + 1);
ptr = strchr(gstr->str, '}');
if (ptr == NULL)
return gstr;
gstr = g_string_truncate(gstr, ptr - gstr->str);
return gstr;
}
static gboolean
capture_loop_open_output(capture_options *capture_opts, int *save_file_fd,
char *errmsg, int errmsg_len)
{
char *tmpname;
gchar *capfile_name;
gchar *prefix;
gboolean is_tempfile;
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "capture_loop_open_output: %s",
(capture_opts->save_file) ? capture_opts->save_file : "(not specified)");
if (capture_opts->save_file != NULL) {
capfile_name = g_strdup(capture_opts->save_file);
if (capture_opts->output_to_pipe == TRUE) {
if (capture_opts->multi_files_on) {
g_snprintf(errmsg, errmsg_len,
"Ring buffer requested, but capture is being written to standard output or to a named pipe.");
g_free(capfile_name);
return FALSE;
}
if (strcmp(capfile_name, "-") == 0) {
*save_file_fd = 1;
#ifdef _WIN32
_setmode(1, O_BINARY);
#endif
}
}
else {
if (capture_opts->multi_files_on) {
*save_file_fd = ringbuf_init(capfile_name,
(capture_opts->has_ring_num_files) ? capture_opts->ring_num_files : 0,
capture_opts->group_read_access);
if (*save_file_fd != -1) {
g_free(capfile_name);
capfile_name = g_strdup(ringbuf_current_filename());
}
} else {
*save_file_fd = ws_open(capfile_name, O_RDWR|O_BINARY|O_TRUNC|O_CREAT,
(capture_opts->group_read_access) ? 0640 : 0600);
}
}
is_tempfile = FALSE;
} else {
if (global_capture_opts.ifaces->len > 1) {
prefix = g_strdup_printf("wireshark_%d_interfaces", global_capture_opts.ifaces->len);
} else {
gchar *basename;
basename = g_path_get_basename(g_array_index(global_capture_opts.ifaces, interface_options, 0).console_display_name);
#ifdef _WIN32
if (strncmp("NPF_{", basename, 5)==0)
{
GString *iface;
iface = isolate_uuid(basename);
g_free(basename);
basename = g_strdup(iface->str);
g_string_free(iface, TRUE);
}
#endif
if (capture_opts->use_pcapng) {
prefix = g_strconcat("wireshark_pcapng_", basename, NULL);
}else{
prefix = g_strconcat("wireshark_pcap_", basename, NULL);
}
g_free(basename);
}
*save_file_fd = create_tempfile(&tmpname, prefix);
g_free(prefix);
capfile_name = g_strdup(tmpname);
is_tempfile = TRUE;
}
if (*save_file_fd == -1) {
if (is_tempfile) {
g_snprintf(errmsg, errmsg_len,
"The temporary file to which the capture would be saved (\"%s\") "
"could not be opened: %s.", capfile_name, g_strerror(errno));
} else {
if (capture_opts->multi_files_on) {
ringbuf_error_cleanup();
}
g_snprintf(errmsg, errmsg_len,
"The file to which the capture would be saved (\"%s\") "
"could not be opened: %s.", capfile_name,
g_strerror(errno));
}
g_free(capfile_name);
return FALSE;
}
if (capture_opts->save_file != NULL) {
g_free(capture_opts->save_file);
}
capture_opts->save_file = capfile_name;
return TRUE;
}
static gboolean
do_file_switch_or_stop(capture_options *capture_opts,
condition *cnd_autostop_files,
condition *cnd_autostop_size,
condition *cnd_file_duration)
{
guint i;
pcap_options *pcap_opts;
interface_options interface_opts;
gboolean successful;
if (capture_opts->multi_files_on) {
if (cnd_autostop_files != NULL &&
cnd_eval(cnd_autostop_files, ++global_ld.autostop_files)) {
global_ld.go = FALSE;
return FALSE;
}
if (ringbuf_switch_file(&global_ld.pdh, &capture_opts->save_file,
&global_ld.save_file_fd, &global_ld.err)) {
global_ld.bytes_written = 0;
if (capture_opts->use_pcapng) {
char appname[100];
GString *os_info_str;
os_info_str = g_string_new("");
get_os_version_info(os_info_str);
g_snprintf(appname, sizeof(appname), "Dumpcap (Wireshark) %s", get_ws_vcs_version_info());
successful = pcapng_write_session_header_block(global_ld.pdh,
NULL,
NULL,
os_info_str->str,
appname,
-1,
&(global_ld.bytes_written),
&global_ld.err);
for (i = 0; successful && (i < capture_opts->ifaces->len); i++) {
interface_opts = g_array_index(capture_opts->ifaces, interface_options, i);
pcap_opts = g_array_index(global_ld.pcaps, pcap_options *, i);
successful = pcapng_write_interface_description_block(global_ld.pdh,
NULL,
interface_opts.name,
interface_opts.descr,
interface_opts.cfilter,
os_info_str->str,
pcap_opts->linktype,
pcap_opts->snaplen,
&(global_ld.bytes_written),
0,
pcap_opts->ts_nsec ? 9 : 6,
&global_ld.err);
}
g_string_free(os_info_str, TRUE);
} else {
pcap_opts = g_array_index(global_ld.pcaps, pcap_options *, 0);
successful = libpcap_write_file_header(global_ld.pdh, pcap_opts->linktype, pcap_opts->snaplen,
pcap_opts->ts_nsec, &global_ld.bytes_written, &global_ld.err);
}
if (!successful) {
fclose(global_ld.pdh);
global_ld.pdh = NULL;
global_ld.go = FALSE;
return FALSE;
}
if (cnd_autostop_size)
cnd_reset(cnd_autostop_size);
if (cnd_file_duration)
cnd_reset(cnd_file_duration);
fflush(global_ld.pdh);
if (!quiet)
report_packet_count(global_ld.inpkts_to_sync_pipe);
global_ld.inpkts_to_sync_pipe = 0;
report_new_capture_file(capture_opts->save_file);
} else {
global_ld.go = FALSE;
return FALSE;
}
} else {
global_ld.go = FALSE;
return FALSE;
}
return TRUE;
}
static void *
pcap_read_handler(void* arg)
{
pcap_options *pcap_opts;
char errmsg[MSG_MAX_LENGTH+1];
pcap_opts = (pcap_options *)arg;
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, "Started thread for interface %d.",
pcap_opts->interface_id);
while (global_ld.go) {
capture_loop_dispatch(&global_ld, errmsg, sizeof(errmsg), pcap_opts);
}
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO, "Stopped thread for interface %d.",
pcap_opts->interface_id);
g_thread_exit(NULL);
return (NULL);
}
static void
capture_loop_stop(void)
{
#ifdef HAVE_PCAP_BREAKLOOP
guint i;
pcap_options *pcap_opts;
for (i = 0; i < global_ld.pcaps->len; i++) {
pcap_opts = g_array_index(global_ld.pcaps, pcap_options *, i);
if (pcap_opts->pcap_h != NULL)
pcap_breakloop(pcap_opts->pcap_h);
}
#endif
global_ld.go = FALSE;
}
static void
capture_loop_get_errmsg(char *errmsg, int errmsglen, const char *fname,
int err, gboolean is_close)
{
switch (err) {
case ENOSPC:
g_snprintf(errmsg, errmsglen,
"Not all the packets could be written to the file"
" to which the capture was being saved\n"
"(\"%s\") because there is no space left on the file system\n"
"on which that file resides.",
fname);
break;
#ifdef EDQUOT
case EDQUOT:
g_snprintf(errmsg, errmsglen,
"Not all the packets could be written to the file"
" to which the capture was being saved\n"
"(\"%s\") because you are too close to, or over,"
" your disk quota\n"
"on the file system on which that file resides.",
fname);
break;
#endif
default:
if (is_close) {
g_snprintf(errmsg, errmsglen,
"The file to which the capture was being saved\n"
"(\"%s\") could not be closed: %s.",
fname, g_strerror(err));
} else {
g_snprintf(errmsg, errmsglen,
"An error occurred while writing to the file"
" to which the capture was being saved\n"
"(\"%s\"): %s.",
fname, g_strerror(err));
}
break;
}
}
static void
capture_loop_write_packet_cb(u_char *pcap_opts_p, const struct pcap_pkthdr *phdr,
const u_char *pd)
{
pcap_options *pcap_opts = (pcap_options *) (void *) pcap_opts_p;
int err;
guint ts_mul = pcap_opts->ts_nsec ? 1000000000 : 1000000;
if (!global_ld.go) {
pcap_opts->flushed++;
return;
}
if (global_ld.pdh) {
gboolean successful;
if (global_capture_opts.use_pcapng) {
successful = pcapng_write_enhanced_packet_block(global_ld.pdh,
NULL,
phdr->ts.tv_sec, (gint32)phdr->ts.tv_usec,
phdr->caplen, phdr->len,
pcap_opts->interface_id,
ts_mul,
pd, 0,
&global_ld.bytes_written, &err);
} else {
successful = libpcap_write_packet(global_ld.pdh,
phdr->ts.tv_sec, (gint32)phdr->ts.tv_usec,
phdr->caplen, phdr->len,
pd,
&global_ld.bytes_written, &err);
}
if (!successful) {
global_ld.go = FALSE;
global_ld.err = err;
pcap_opts->dropped++;
} else {
#if defined(DEBUG_DUMPCAP) || defined(DEBUG_CHILD_DUMPCAP)
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO,
"Wrote a packet of length %d captured on interface %u.",
phdr->caplen, pcap_opts->interface_id);
#endif
global_ld.packet_count++;
pcap_opts->received++;
if ((global_ld.packet_max > 0) && (global_ld.packet_count >= global_ld.packet_max)) {
global_ld.go = FALSE;
}
}
}
}
static void
capture_loop_queue_packet_cb(u_char *pcap_opts_p, const struct pcap_pkthdr *phdr,
const u_char *pd)
{
pcap_options *pcap_opts = (pcap_options *) (void *) pcap_opts_p;
pcap_queue_element *queue_element;
gboolean limit_reached;
if (!global_ld.go) {
pcap_opts->flushed++;
return;
}
queue_element = (pcap_queue_element *)g_malloc(sizeof(pcap_queue_element));
if (queue_element == NULL) {
pcap_opts->dropped++;
return;
}
queue_element->pcap_opts = pcap_opts;
queue_element->phdr = *phdr;
queue_element->pd = (u_char *)g_malloc(phdr->caplen);
if (queue_element->pd == NULL) {
pcap_opts->dropped++;
g_free(queue_element);
return;
}
memcpy(queue_element->pd, pd, phdr->caplen);
g_async_queue_lock(pcap_queue);
if (((pcap_queue_byte_limit == 0) || (pcap_queue_bytes < pcap_queue_byte_limit)) &&
((pcap_queue_packet_limit == 0) || (pcap_queue_packets < pcap_queue_packet_limit))) {
limit_reached = FALSE;
g_async_queue_push_unlocked(pcap_queue, queue_element);
pcap_queue_bytes += phdr->caplen;
pcap_queue_packets += 1;
} else {
limit_reached = TRUE;
}
g_async_queue_unlock(pcap_queue);
if (limit_reached) {
pcap_opts->dropped++;
g_free(queue_element->pd);
g_free(queue_element);
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO,
"Dropped a packet of length %d captured on interface %u.",
phdr->caplen, pcap_opts->interface_id);
} else {
pcap_opts->received++;
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO,
"Queued a packet of length %d captured on interface %u.",
phdr->caplen, pcap_opts->interface_id);
}
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO,
"Queue size is now %" G_GINT64_MODIFIER "d bytes (%" G_GINT64_MODIFIER "d packets)",
pcap_queue_bytes, pcap_queue_packets);
}
static int
set_80211_channel(const char *iface, const char *opt)
{
int freq = 0, type, ret;
gchar **options = NULL;
options = g_strsplit_set(opt, ",", 2);
if (options[0])
freq = atoi(options[0]);
if (options[1]) {
type = ws80211_str_to_chan_type(options[1]);
if (type == -1) {
ret = EINVAL;
goto out;
}
}
else
type = -1;
ret = ws80211_init();
if (ret) {
cmdarg_err("%d: Failed to init ws80211: %s\n", abs(ret), g_strerror(abs(ret)));
ret = 2;
goto out;
}
ret = ws80211_set_freq(iface, freq, type);
if (ret) {
cmdarg_err("%d: Failed to set channel: %s\n", abs(ret), g_strerror(abs(ret)));
ret = 2;
goto out;
}
if (capture_child)
pipe_write_block(2, SP_SUCCESS, NULL);
ret = 0;
out:
g_strfreev(options);
return ret;
}
static void
get_dumpcap_compiled_info(GString *str)
{
g_string_append(str, ", ");
get_compiled_caplibs_version(str);
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
get_dumpcap_runtime_info(GString *str)
{
g_string_append(str, ", ");
get_runtime_caplibs_version(str);
#if defined(HAVE_LIBZ) && !defined(_WIN32)
g_string_append_printf(str, ", with libz %s", zlibVersion());
#endif
}
int
main(int argc, char *argv[])
{
GString *comp_info_str;
GString *runtime_info_str;
int opt;
static const struct option long_options[] = {
{(char *)"help", no_argument, NULL, 'h'},
{(char *)"version", no_argument, NULL, 'v'},
LONGOPT_CAPTURE_COMMON
{0, 0, 0, 0 }
};
gboolean arg_error = FALSE;
#ifdef _WIN32
WSADATA wsaData;
#else
struct sigaction action, oldaction;
#endif
gboolean start_capture = TRUE;
gboolean stats_known;
struct pcap_stat stats;
GLogLevelFlags log_flags;
gboolean list_interfaces = FALSE;
gboolean list_link_layer_types = FALSE;
#ifdef HAVE_BPF_IMAGE
gboolean print_bpf_code = FALSE;
#endif
gboolean set_chan = FALSE;
gchar *set_chan_arg = NULL;
gboolean machine_readable = FALSE;
gboolean print_statistics = FALSE;
int status, run_once_args = 0;
gint i;
guint j;
#if defined(__APPLE__) && defined(__LP64__)
struct utsname osinfo;
#endif
GString *str;
cmdarg_err_init(dumpcap_cmdarg_err, dumpcap_cmdarg_err_cont);
comp_info_str = g_string_new("Compiled ");
get_compiled_version_info(comp_info_str, NULL, get_dumpcap_compiled_info);
runtime_info_str = g_string_new("Running ");
get_runtime_version_info(runtime_info_str, get_dumpcap_runtime_info);
ws_add_crash_info("Dumpcap (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), comp_info_str->str, runtime_info_str->str);
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
ws_init_dll_search_path();
#endif
#ifdef HAVE_BPF_IMAGE
#define OPTSTRING_d "d"
#else
#define OPTSTRING_d ""
#endif
#ifdef HAVE_PCAP_REMOTE
#define OPTSTRING_r "r"
#define OPTSTRING_u "u"
#else
#define OPTSTRING_r ""
#define OPTSTRING_u ""
#endif
#ifdef HAVE_PCAP_SETSAMPLING
#define OPTSTRING_m "m:"
#else
#define OPTSTRING_m ""
#endif
#define OPTSTRING OPTSTRING_CAPTURE_COMMON "C:" OPTSTRING_d "gh" "k:" OPTSTRING_m "MN:nPq" OPTSTRING_r "St" OPTSTRING_u "vw:Z:"
#ifdef DEBUG_CHILD_DUMPCAP
if ((debug_log = ws_fopen("dumpcap_debug_log.tmp","w")) == NULL) {
fprintf (stderr, "Unable to open debug log file .\n");
exit (1);
}
#endif
#if defined(__APPLE__) && defined(__LP64__)
if (uname(&osinfo) == 0) {
if (strcmp(osinfo.release, "10.0.0") == 0 ||
strcmp(osinfo.release, "10.3.0") == 0 ||
strcmp(osinfo.release, "10.4.0") == 0)
need_timeout_workaround = TRUE;
}
#endif
for (i=1; i<argc; i++) {
if (strcmp("-Z", argv[i]) == 0) {
capture_child = TRUE;
machine_readable = TRUE;
#ifdef _WIN32
_setmode(2, O_BINARY);
#endif
}
}
log_flags =
(GLogLevelFlags)(
G_LOG_LEVEL_ERROR|
G_LOG_LEVEL_CRITICAL|
G_LOG_LEVEL_WARNING|
G_LOG_LEVEL_MESSAGE|
G_LOG_LEVEL_INFO|
G_LOG_LEVEL_DEBUG|
G_LOG_FLAG_FATAL|
G_LOG_FLAG_RECURSION);
g_log_set_handler(NULL,
log_flags,
console_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_MAIN,
log_flags,
console_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_CAPTURE,
log_flags,
console_log_handler, NULL );
g_log_set_handler(LOG_DOMAIN_CAPTURE_CHILD,
log_flags,
console_log_handler, NULL );
global_ld.pcaps = g_array_new(FALSE, FALSE, sizeof(pcap_options *));
#if !GLIB_CHECK_VERSION(2,31,0)
g_thread_init(NULL);
#endif
#ifdef _WIN32
load_wpcap();
WSAStartup( MAKEWORD( 1, 1 ), &wsaData );
SetConsoleCtrlHandler(capture_cleanup_handler, TRUE);
#else
memset(&action, 0, sizeof(action));
action.sa_handler = capture_cleanup_handler;
action.sa_flags = 0;
sigemptyset(&action.sa_mask);
sigaction(SIGTERM, &action, NULL);
sigaction(SIGINT, &action, NULL);
sigaction(SIGPIPE, &action, NULL);
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
#ifdef __linux__
enable_kernel_bpf_jit_compiler();
#endif
init_process_policies();
#ifdef HAVE_LIBCAP
relinquish_privs_except_capture();
#endif
capture_opts_init(&global_capture_opts);
global_capture_opts.saving_to_file = TRUE;
global_capture_opts.has_ring_num_files = TRUE;
global_capture_opts.capture_child = capture_child;
while ((opt = getopt_long(argc, argv, OPTSTRING, long_options, NULL)) != -1) {
switch (opt) {
case 'h':
printf("Dumpcap (Wireshark) %s\n"
"Capture network packets and dump them into a pcapng or pcap file.\n"
"See http://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
print_usage(stdout);
exit_main(0);
break;
case 'v':
{
show_version(comp_info_str, runtime_info_str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
exit_main(0);
break;
}
case 'a':
case 'b':
case 'c':
case 'f':
case 'g':
case 'i':
case 'n':
case 'p':
case 'P':
case 's':
case 'w':
case 'y':
case LONGOPT_NUM_CAP_COMMENT:
#ifdef HAVE_PCAP_REMOTE
case 'u':
case 'r':
case 'A':
#endif
#ifdef HAVE_PCAP_SETSAMPLING
case 'm':
#endif
#if defined(_WIN32) || defined(HAVE_PCAP_CREATE)
case 'B':
#endif
#ifdef HAVE_PCAP_CREATE
case 'I':
#endif
status = capture_opts_add_opt(&global_capture_opts, opt, optarg, &start_capture);
if (status != 0) {
exit_main(status);
}
break;
case 'Z':
capture_child = TRUE;
#ifdef _WIN32
_setmode(2, O_BINARY);
if (strcmp(optarg, SIGNAL_PIPE_CTRL_ID_NONE) != 0) {
sig_pipe_name = g_strdup_printf(SIGNAL_PIPE_FORMAT, optarg);
sig_pipe_handle = CreateFile(utf_8to16(sig_pipe_name),
GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
if (sig_pipe_handle == INVALID_HANDLE_VALUE) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO,
"Signal pipe: Unable to open %s. Dead parent?",
sig_pipe_name);
exit_main(1);
}
}
#endif
break;
case 'q':
quiet = TRUE;
break;
case 't':
use_threads = TRUE;
break;
case 'D':
list_interfaces = TRUE;
run_once_args++;
break;
case 'L':
list_link_layer_types = TRUE;
run_once_args++;
break;
#ifdef HAVE_BPF_IMAGE
case 'd':
print_bpf_code = TRUE;
run_once_args++;
break;
#endif
case 'S':
print_statistics = TRUE;
run_once_args++;
break;
case 'k':
set_chan = TRUE;
set_chan_arg = optarg;
run_once_args++;
break;
case 'M':
machine_readable = TRUE;
break;
case 'C':
pcap_queue_byte_limit = get_positive_int(optarg, "byte_limit");
break;
case 'N':
pcap_queue_packet_limit = get_positive_int(optarg, "packet_limit");
break;
default:
cmdarg_err("Invalid Option: %s", argv[optind-1]);
case '?':
arg_error = TRUE;
break;
}
}
if (!arg_error) {
argc -= optind;
argv += optind;
if (argc >= 1) {
argc--;
argv++;
}
if (argc != 0) {
cmdarg_err("Invalid argument: %s", argv[0]);
arg_error = TRUE;
}
}
if ((pcap_queue_byte_limit > 0) || (pcap_queue_packet_limit > 0)) {
use_threads = TRUE;
}
if ((pcap_queue_byte_limit == 0) && (pcap_queue_packet_limit == 0)) {
pcap_queue_byte_limit = 1000 * 1000;
pcap_queue_packet_limit = 1000;
}
if (arg_error) {
print_usage(stderr);
exit_main(1);
}
if (run_once_args > 1) {
cmdarg_err("Only one of -D, -L, or -S may be supplied.");
exit_main(1);
} else if (run_once_args == 1) {
if (global_capture_opts.multi_files_on) {
cmdarg_err("Ring buffer requested, but a capture isn't being done.");
exit_main(1);
}
} else {
if (global_capture_opts.ifaces->len > 1) {
use_threads = TRUE;
global_capture_opts.use_pcapng = TRUE;
}
if (global_capture_opts.capture_comment &&
(!global_capture_opts.use_pcapng || global_capture_opts.multi_files_on)) {
cmdarg_err("A capture comment can only be set if we capture into a single pcapng file.");
exit_main(1);
}
if (global_capture_opts.multi_files_on) {
if (global_capture_opts.save_file == NULL) {
cmdarg_err("Ring buffer requested, but capture isn't being saved to a permanent file.");
global_capture_opts.multi_files_on = FALSE;
}
if (!global_capture_opts.has_autostop_filesize && !global_capture_opts.has_file_duration) {
cmdarg_err("Ring buffer requested, but no maximum capture file size or duration were specified.");
#if 0
global_capture_opts.multi_files_on = FALSE;
#endif
}
}
}
if (list_interfaces) {
GList *if_list;
int err;
gchar *err_str;
if_list = capture_interface_list(&err, &err_str,NULL);
if (if_list == NULL) {
if (err == 0) {
if (!machine_readable) {
cmdarg_err("There are no interfaces on which a capture can be done");
exit_main(2);
}
} else {
cmdarg_err("%s", err_str);
g_free(err_str);
exit_main(2);
}
}
if (machine_readable)
print_machine_readable_interfaces(if_list);
else
capture_opts_print_interfaces(if_list);
free_interface_list(if_list);
exit_main(0);
}
if (print_statistics) {
status = print_statistics_loop(machine_readable);
exit_main(status);
}
if (set_chan) {
interface_options interface_opts;
if (global_capture_opts.ifaces->len != 1) {
cmdarg_err("Need one interface");
exit_main(2);
}
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, 0);
status = set_80211_channel(interface_opts.name, set_chan_arg);
exit_main(status);
}
status = capture_opts_default_iface_if_necessary(&global_capture_opts, NULL);
if (status != 0) {
exit_main(status);
}
if (capture_child) {
for (j = 0; j < global_capture_opts.ifaces->len; j++) {
interface_options interface_opts;
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, j);
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "Interface: %s\n",
interface_opts.name);
}
} else {
str = g_string_new("");
#ifdef _WIN32
if (global_capture_opts.ifaces->len < 2)
#else
if (global_capture_opts.ifaces->len < 4)
#endif
{
for (j = 0; j < global_capture_opts.ifaces->len; j++) {
interface_options interface_opts;
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, j);
if (j > 0) {
if (global_capture_opts.ifaces->len > 2) {
g_string_append_printf(str, ",");
}
g_string_append_printf(str, " ");
if (j == global_capture_opts.ifaces->len - 1) {
g_string_append_printf(str, "and ");
}
}
g_string_append_printf(str, "'%s'", interface_opts.console_display_name);
}
} else {
g_string_append_printf(str, "%u interfaces", global_capture_opts.ifaces->len);
}
fprintf(stderr, "Capturing on %s\n", str->str);
g_string_free(str, TRUE);
}
if (list_link_layer_types) {
if_capabilities_t *caps;
gchar *err_str;
guint ii;
for (ii = 0; ii < global_capture_opts.ifaces->len; ii++) {
interface_options interface_opts;
interface_opts = g_array_index(global_capture_opts.ifaces, interface_options, ii);
caps = get_if_capabilities(interface_opts.name,
interface_opts.monitor_mode, &err_str);
if (caps == NULL) {
cmdarg_err("The capabilities of the capture device \"%s\" could not be obtained (%s).\n"
"Please check to make sure you have sufficient permissions, and that\n"
"you have the proper interface or pipe specified.", interface_opts.name, err_str);
g_free(err_str);
exit_main(2);
}
if (caps->data_link_types == NULL) {
cmdarg_err("The capture device \"%s\" has no data link types.", interface_opts.name);
exit_main(2);
}
if (machine_readable)
print_machine_readable_if_capabilities(caps);
else
capture_opts_print_if_capabilities(caps, interface_opts.name,
interface_opts.monitor_mode);
free_if_capabilities(caps);
}
exit_main(0);
}
capture_opts_trim_snaplen(&global_capture_opts, MIN_PACKET_SIZE);
#ifdef HAVE_BPF_IMAGE
if (print_bpf_code) {
show_filter_code(&global_capture_opts);
exit_main(0);
}
#endif
capture_opts_trim_ring_num_files(&global_capture_opts);
fflush(stderr);
if (capture_loop_start(&global_capture_opts, &stats_known, &stats) == TRUE) {
exit_main(0);
} else {
exit_main(1);
}
return 0;
}
static void
console_log_handler(const char *log_domain, GLogLevelFlags log_level,
const char *message, gpointer user_data _U_)
{
time_t curr;
struct tm *today;
const char *level;
gchar *msg;
if ( !(log_level & G_LOG_LEVEL_MASK & ~(G_LOG_LEVEL_DEBUG|G_LOG_LEVEL_INFO))) {
#if !defined(DEBUG_DUMPCAP) && !defined(DEBUG_CHILD_DUMPCAP)
return;
#endif
}
time(&curr);
today = localtime(&curr);
switch(log_level & G_LOG_LEVEL_MASK) {
case G_LOG_LEVEL_ERROR:
level = "Err ";
break;
case G_LOG_LEVEL_CRITICAL:
level = "Crit";
break;
case G_LOG_LEVEL_WARNING:
level = "Warn";
break;
case G_LOG_LEVEL_MESSAGE:
level = "Msg ";
break;
case G_LOG_LEVEL_INFO:
level = "Info";
break;
case G_LOG_LEVEL_DEBUG:
level = "Dbg ";
break;
default:
fprintf(stderr, "unknown log_level %u\n", log_level);
level = NULL;
g_assert_not_reached();
}
if (log_level & G_LOG_LEVEL_MESSAGE) {
msg = g_strdup_printf("%s\n", message);
} else {
msg = g_strdup_printf("%02u:%02u:%02u %8s %s %s\n",
today->tm_hour, today->tm_min, today->tm_sec,
log_domain != NULL ? log_domain : "",
level, message);
}
#if defined(DEBUG_DUMPCAP) || defined(DEBUG_CHILD_DUMPCAP)
if ( !(log_level & G_LOG_LEVEL_MASK & ~(G_LOG_LEVEL_DEBUG|G_LOG_LEVEL_INFO))) {
#ifdef DEBUG_DUMPCAP
fprintf(stderr, "%s", msg);
fflush(stderr);
#endif
#ifdef DEBUG_CHILD_DUMPCAP
fprintf(debug_log, "%s", msg);
fflush(debug_log);
#endif
g_free(msg);
return;
}
#endif
if (capture_child) {
sync_pipe_errmsg_to_parent(2, msg, "");
} else {
fprintf(stderr, "%s", msg);
fflush(stderr);
}
g_free(msg);
}
static void
report_packet_count(unsigned int packet_count)
{
char tmp[SP_DECISIZE+1+1];
static unsigned int count = 0;
if (capture_child) {
g_snprintf(tmp, sizeof(tmp), "%u", packet_count);
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "Packets: %s", tmp);
pipe_write_block(2, SP_PACKET_COUNT, tmp);
} else {
count += packet_count;
fprintf(stderr, "\rPackets: %u ", count);
fflush(stderr);
}
}
static void
report_new_capture_file(const char *filename)
{
if (capture_child) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "File: %s", filename);
pipe_write_block(2, SP_FILE, filename);
} else {
#ifdef SIGINFO
infodelay = TRUE;
#endif
fprintf(stderr, "File: %s\n", filename);
fflush(stderr);
#ifdef SIGINFO
infodelay = FALSE;
if (infoprint)
report_counts_for_siginfo();
#endif
}
}
static void
report_cfilter_error(capture_options *capture_opts, guint i, const char *errmsg)
{
interface_options interface_opts;
char tmp[MSG_MAX_LENGTH+1+6];
if (i < capture_opts->ifaces->len) {
if (capture_child) {
g_snprintf(tmp, sizeof(tmp), "%u:%s", i, errmsg);
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG, "Capture filter error: %s", errmsg);
pipe_write_block(2, SP_BAD_FILTER, tmp);
} else {
interface_opts = g_array_index(capture_opts->ifaces, interface_options, i);
cmdarg_err(
"Invalid capture filter \"%s\" for interface '%s'.\n"
"\n"
"That string isn't a valid capture filter (%s).\n"
"See the User's Guide for a description of the capture filter syntax.",
interface_opts.cfilter, interface_opts.name, errmsg);
}
}
}
static void
report_capture_error(const char *error_msg, const char *secondary_error_msg)
{
if (capture_child) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG,
"Primary Error: %s", error_msg);
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG,
"Secondary Error: %s", secondary_error_msg);
sync_pipe_errmsg_to_parent(2, error_msg, secondary_error_msg);
} else {
cmdarg_err("%s", error_msg);
if (secondary_error_msg[0] != '\0')
cmdarg_err_cont("%s", secondary_error_msg);
}
}
static void
report_packet_drops(guint32 received, guint32 pcap_drops, guint32 drops, guint32 flushed, guint32 ps_ifdrop, gchar *name)
{
char tmp[SP_DECISIZE+1+1];
guint32 total_drops = pcap_drops + drops + flushed;
g_snprintf(tmp, sizeof(tmp), "%u", total_drops);
if (capture_child) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG,
"Packets received/dropped on interface '%s': %u/%u (pcap:%u/dumpcap:%u/flushed:%u/ps_ifdrop:%u)",
name, received, total_drops, pcap_drops, drops, flushed, ps_ifdrop);
pipe_write_block(2, SP_DROPS, tmp);
} else {
fprintf(stderr,
"Packets received/dropped on interface '%s': %u/%u (pcap:%u/dumpcap:%u/flushed:%u/ps_ifdrop:%u) (%.1f%%)\n",
name, received, total_drops, pcap_drops, drops, flushed, ps_ifdrop,
received ? 100.0 * received / (received + total_drops) : 0.0);
fflush(stderr);
}
}
static gboolean
signal_pipe_check_running(void)
{
DWORD avail = 0;
gboolean result;
if (!capture_child) {
return TRUE;
}
if (!sig_pipe_name || !sig_pipe_handle) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO,
"Signal pipe: No name or handle");
return FALSE;
}
result = PeekNamedPipe(sig_pipe_handle, NULL, 0, NULL, &avail, NULL);
if (!result || avail > 0) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_INFO,
"Signal pipe: Stop capture: %s", sig_pipe_name);
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_DEBUG,
"Signal pipe: %s (%p) result: %u avail: %u", sig_pipe_name,
sig_pipe_handle, result, avail);
return FALSE;
} else {
return TRUE;
}
}
