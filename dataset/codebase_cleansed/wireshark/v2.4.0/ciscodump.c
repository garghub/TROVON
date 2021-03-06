static char* interfaces_list_to_filter(GSList* interfaces, unsigned int remote_port)
{
GString* filter = g_string_new(NULL);
GSList* cur;
if (interfaces) {
g_string_append_printf(filter, "deny tcp host %s any eq %u, deny tcp any eq %u host %s",
(char*)interfaces->data, remote_port, remote_port, (char*)interfaces->data);
cur = g_slist_next(interfaces);
while (cur) {
g_string_append_printf(filter, ", deny tcp host %s any eq %u, deny tcp any eq %u host %s",
(char*)cur->data, remote_port, remote_port, (char*)cur->data);
cur = g_slist_next(cur);
}
g_string_append_printf(filter, ", permit ip any any");
}
return g_string_free(filter, FALSE);
}
static char* local_interfaces_to_filter(const unsigned int remote_port)
{
GSList* interfaces = local_interfaces_to_list();
char* filter = interfaces_list_to_filter(interfaces, remote_port);
g_slist_free_full(interfaces, g_free);
return filter;
}
static int read_output_bytes(ssh_channel channel, int bytes, char* outbuf)
{
char chr;
int total;
int bytes_read;
total = (bytes > 0 ? bytes : G_MAXINT);
bytes_read = 0;
while(ssh_channel_read_timeout(channel, &chr, 1, 0, 2000) > 0 && bytes_read < total) {
g_debug("%c", chr);
if (chr == '^')
return EXIT_FAILURE;
if (outbuf)
outbuf[bytes_read] = chr;
bytes_read++;
}
return EXIT_SUCCESS;
}
static void ciscodump_cleanup(ssh_session sshs, ssh_channel channel, const char* iface, const char* cfilter)
{
if (channel) {
if (read_output_bytes(channel, -1, NULL) == EXIT_SUCCESS) {
ssh_channel_printf(channel, "monitor capture point stop %s\n", WIRESHARK_CAPTURE_POINT);
ssh_channel_printf(channel, "no monitor capture point ip cef %s %s\n", WIRESHARK_CAPTURE_POINT, iface);
ssh_channel_printf(channel, "no monitor capture buffer %s\n", WIRESHARK_CAPTURE_BUFFER);
if (cfilter) {
ssh_channel_printf(channel, "configure terminal\n");
ssh_channel_printf(channel, "no ip access-list ex %s\n", WIRESHARK_CAPTURE_ACCESSLIST);
}
read_output_bytes(channel, -1, NULL);
}
}
ssh_cleanup(&sshs, &channel);
}
static int wait_until_data(ssh_channel channel, const guint32 count)
{
long unsigned got = 0;
char output[SSH_READ_BLOCK_SIZE];
char* output_ptr;
guint rounds = 100;
while (got < count && rounds--) {
if (ssh_channel_printf(channel, "show monitor capture buffer %s parameters\n", WIRESHARK_CAPTURE_BUFFER) == EXIT_FAILURE) {
g_warning("Can't write to channel");
return EXIT_FAILURE;
}
if (read_output_bytes(channel, SSH_READ_BLOCK_SIZE, output) == EXIT_FAILURE)
return EXIT_FAILURE;
output_ptr = g_strstr_len(output, strlen(output), "Packets");
if (!output_ptr) {
g_warning("Error in sscanf()");
return EXIT_FAILURE;
} else {
if (sscanf(output_ptr, "Packets : %lu", &got) != 1)
return EXIT_FAILURE;
}
}
g_debug("All packets got: dumping");
return EXIT_SUCCESS;
}
static int parse_line(char* packet _U_, unsigned* offset, char* line, int status)
{
char** parts;
char** part;
guint32 value;
size_t size;
if (strlen(line) <= 1) {
if (status == CISCODUMP_PARSER_IN_PACKET)
return CISCODUMP_PARSER_END_PACKET;
else
return status;
}
if (g_regex_match_simple("^\\d{2}:\\d{2}:\\d{2}.\\d+ .*", line, G_REGEX_CASELESS, G_REGEX_MATCH_ANCHORED)) {
return CISCODUMP_PARSER_IN_HEADER;
}
parts = g_regex_split_simple(
"^[\\dA-F]{8,8}:\\s+([\\dA-F]{2,8})\\s+([\\dA-F]{2,8}){0,1}\\s+([\\dA-F]{2,8}){0,1}\\s+([\\dA-F]{2,8}){0,1}.*",
line, G_REGEX_CASELESS, G_REGEX_MATCH_ANCHORED);
part = parts;
while(*part) {
if (strlen(*part) > 1) {
value = (guint32)strtoul(*part, NULL, 16);
value = ntohl(value);
size = strlen(*part) / 2;
memcpy(packet + *offset, &value, size);
*offset += (guint32)size;
}
part++;
}
g_strfreev(parts);
return CISCODUMP_PARSER_IN_PACKET;
}
static void ssh_loop_read(ssh_channel channel, FILE* fp, const guint32 count)
{
char line[SSH_READ_BLOCK_SIZE];
char chr;
unsigned offset = 0;
unsigned packet_size = 0;
char* packet;
time_t curtime = time(NULL);
int err;
guint64 bytes_written;
long unsigned packets = 0;
int status = CISCODUMP_PARSER_STARTING;
packet = (char*)g_malloc(PACKET_MAX_SIZE);
do {
if (ssh_channel_read_timeout(channel, &chr, 1, FALSE, SSH_READ_TIMEOUT) == SSH_ERROR) {
g_warning("Error reading from channel");
g_free(packet);
return;
}
if (chr != '\n') {
line[offset] = chr;
offset++;
} else {
line[offset] = '\0';
status = parse_line(packet, &packet_size, line, status);
if (status == CISCODUMP_PARSER_END_PACKET) {
libpcap_write_packet(fp, curtime, (guint32)(curtime / 1000), packet_size, packet_size, packet, &bytes_written, &err);
g_debug("Dumped packet %lu size: %u", packets, packet_size);
packet_size = 0;
status = CISCODUMP_PARSER_STARTING;
packets++;
}
offset = 0;
}
} while(packets < count);
g_free(packet);
}
static int check_ios_version(ssh_channel channel)
{
gchar* cmdline = "show version | include Cisco IOS\n";
gchar version[255];
guint major = 0;
guint minor = 0;
gchar* cur;
memset(version, 0x0, 255);
if (ssh_channel_write(channel, cmdline, (guint32)strlen(cmdline)) == SSH_ERROR)
return FALSE;
if (read_output_bytes(channel, (int)strlen(cmdline), NULL) == EXIT_FAILURE)
return FALSE;
if (read_output_bytes(channel, 255, version) == EXIT_FAILURE)
return FALSE;
cur = g_strstr_len(version, strlen(version), "Version");
if (cur) {
cur += strlen("Version ");
if (sscanf(cur, "%u.%u", &major, &minor) != 2)
return FALSE;
if ((major > MINIMUM_IOS_MAJOR) || (major == MINIMUM_IOS_MAJOR && minor >= MINIMUM_IOS_MINOR)) {
g_debug("Current IOS Version: %u.%u", major, minor);
if (read_output_bytes(channel, -1, NULL) == EXIT_FAILURE)
return FALSE;
return TRUE;
}
}
g_warning("Invalid IOS version. Minimum version: 12.4, current: %u.%u", major, minor);
return FALSE;
}
static ssh_channel run_capture(ssh_session sshs, const char* iface, const char* cfilter, const guint32 count)
{
char* cmdline = NULL;
ssh_channel channel;
int ret = 0;
channel = ssh_channel_new(sshs);
if (!channel)
return NULL;
if (ssh_channel_open_session(channel) != SSH_OK)
goto error;
if (ssh_channel_request_pty(channel) != SSH_OK)
goto error;
if (ssh_channel_change_pty_size(channel, 80, 24) != SSH_OK)
goto error;
if (ssh_channel_request_shell(channel) != SSH_OK)
goto error;
if (!check_ios_version(channel))
goto error;
if (ssh_channel_printf(channel, "terminal length 0\n") == EXIT_FAILURE)
goto error;
if (ssh_channel_printf(channel, "monitor capture buffer %s max-size 9500\n", WIRESHARK_CAPTURE_BUFFER) == EXIT_FAILURE)
goto error;
if (ssh_channel_printf(channel, "monitor capture buffer %s limit packet-count %u\n", WIRESHARK_CAPTURE_BUFFER, count) == EXIT_FAILURE)
goto error;
if (cfilter) {
gchar* multiline_filter;
gchar* chr;
if (ssh_channel_printf(channel, "configure terminal\n") == EXIT_FAILURE)
goto error;
if (ssh_channel_printf(channel, "ip access-list ex %s\n", WIRESHARK_CAPTURE_ACCESSLIST) == EXIT_FAILURE)
goto error;
multiline_filter = g_strdup(cfilter);
chr = multiline_filter;
while((chr = g_strstr_len(chr, strlen(chr), ",")) != NULL) {
chr[0] = '\n';
g_debug("Splitting filter into multiline");
}
ret = ssh_channel_write(channel, multiline_filter, (uint32_t)strlen(multiline_filter));
g_free(multiline_filter);
if (ret == SSH_ERROR)
goto error;
if (ssh_channel_printf(channel, "\nend\n") == EXIT_FAILURE)
goto error;
if (ssh_channel_printf(channel, "monitor capture buffer %s filter access-list %s\n",
WIRESHARK_CAPTURE_BUFFER, WIRESHARK_CAPTURE_ACCESSLIST) == EXIT_FAILURE)
goto error;
}
if (ssh_channel_printf(channel, "monitor capture point ip cef %s %s both\n", WIRESHARK_CAPTURE_POINT,
iface) == EXIT_FAILURE)
goto error;
if (ssh_channel_printf(channel, "monitor capture point associate %s %s \n", WIRESHARK_CAPTURE_POINT,
WIRESHARK_CAPTURE_BUFFER) == EXIT_FAILURE)
goto error;
if (ssh_channel_printf(channel, "monitor capture point start %s\n", WIRESHARK_CAPTURE_POINT) == EXIT_FAILURE)
goto error;
if (read_output_bytes(channel, -1, NULL) == EXIT_FAILURE)
goto error;
if (wait_until_data(channel, count) == EXIT_FAILURE)
goto error;
if (read_output_bytes(channel, -1, NULL) == EXIT_FAILURE)
goto error;
cmdline = g_strdup_printf("show monitor capture buffer %s dump\n", WIRESHARK_CAPTURE_BUFFER);
if (ssh_channel_printf(channel, cmdline) == EXIT_FAILURE)
goto error;
if (read_output_bytes(channel, (int)strlen(cmdline), NULL) == EXIT_FAILURE)
goto error;
g_free(cmdline);
return channel;
error:
g_free(cmdline);
g_warning("Error running ssh remote command");
read_output_bytes(channel, -1, NULL);
ssh_channel_close(channel);
ssh_channel_free(channel);
return NULL;
}
static int ssh_open_remote_connection(const char* hostname, const unsigned int port, const char* username, const char* password,
const char* sshkey, const char* sshkey_passphrase, const char* iface, const char* cfilter,
const guint32 count, const char* fifo)
{
ssh_session sshs;
ssh_channel channel;
FILE* fp = stdout;
guint64 bytes_written = 0;
int err;
int ret = EXIT_FAILURE;
char* err_info = NULL;
if (g_strcmp0(fifo, "-")) {
fp = fopen(fifo, "w");
if (!fp) {
g_warning("Error creating output file: %s", g_strerror(errno));
return EXIT_FAILURE;
}
}
sshs = create_ssh_connection(hostname, port, username, password, sshkey, sshkey_passphrase, &err_info);
if (!sshs) {
g_warning("Error creating connection: %s", err_info);
goto cleanup;
}
if (!libpcap_write_file_header(fp, 1, PCAP_SNAPLEN, FALSE, &bytes_written, &err)) {
g_warning("Can't write pcap file header");
goto cleanup;
}
channel = run_capture(sshs, iface, cfilter, count);
if (!channel) {
ret = EXIT_FAILURE;
goto cleanup;
}
ssh_loop_read(channel, fp, count);
ciscodump_cleanup(sshs, channel, iface, cfilter);
ret = EXIT_SUCCESS;
cleanup:
if (fp != stdout)
fclose(fp);
return ret;
}
static int list_config(char *interface, unsigned int remote_port)
{
unsigned inc = 0;
char* ipfilter;
if (!interface) {
g_warning("No interface specified.");
return EXIT_FAILURE;
}
if (g_strcmp0(interface, CISCODUMP_EXTCAP_INTERFACE)) {
g_warning("interface must be %s", CISCODUMP_EXTCAP_INTERFACE);
return EXIT_FAILURE;
}
ipfilter = local_interfaces_to_filter(remote_port);
printf("arg {number=%u}{call=--remote-host}{display=Remote SSH server address}"
"{type=string}{tooltip=The remote SSH host. It can be both "
"an IP address or a hostname}{required=true}\n", inc++);
printf("arg {number=%u}{call=--remote-port}{display=Remote SSH server port}"
"{type=unsigned}{default=22}{tooltip=The remote SSH host port (1-65535)}"
"{range=1,65535}\n", inc++);
printf("arg {number=%u}{call=--remote-username}{display=Remote SSH server username}"
"{type=string}{default=%s}{tooltip=The remote SSH username. If not provided, "
"the current user will be used}\n", inc++, g_get_user_name());
printf("arg {number=%u}{call=--remote-password}{display=Remote SSH server password}"
"{type=password}{tooltip=The SSH password, used when other methods (SSH agent "
"or key files) are unavailable.}\n", inc++);
printf("arg {number=%u}{call=--sshkey}{display=Path to SSH private key}"
"{type=fileselect}{tooltip=The path on the local filesystem of the private ssh key}\n",
inc++);
printf("arg {number=%u}{call--sshkey-passphrase}{display=SSH key passphrase}"
"{type=password}{tooltip=Passphrase to unlock the SSH private key}\n",
inc++);
printf("arg {number=%u}{call=--remote-interface}{display=Remote interface}"
"{type=string}{required=true}{tooltip=The remote network interface used for capture"
"}\n", inc++);
printf("arg {number=%u}{call=--remote-filter}{display=Remote capture filter}"
"{type=string}{tooltip=The remote capture filter}", inc++);
if (ipfilter)
printf("{default=%s}", ipfilter);
printf("\n");
printf("arg {number=%u}{call=--remote-count}{display=Packets to capture}"
"{type=unsigned}{required=true}{tooltip=The number of remote packets to capture.}\n",
inc++);
g_free(ipfilter);
return EXIT_SUCCESS;
}
int main(int argc, char **argv)
{
int result;
int option_idx = 0;
int i;
char* remote_host = NULL;
guint16 remote_port = 22;
char* remote_username = NULL;
char* remote_password = NULL;
char* remote_interface = NULL;
char* sshkey = NULL;
char* sshkey_passphrase = NULL;
char* remote_filter = NULL;
guint32 count = 0;
int ret = EXIT_FAILURE;
extcap_parameters * extcap_conf = g_new0(extcap_parameters, 1);
char* help_url;
char* help_header = NULL;
#ifdef _WIN32
WSADATA wsaData;
attach_parent_console();
#endif
help_url = data_file_url("ciscodump.html");
extcap_base_set_util_info(extcap_conf, argv[0], CISCODUMP_VERSION_MAJOR, CISCODUMP_VERSION_MINOR,
CISCODUMP_VERSION_RELEASE, help_url);
g_free(help_url);
extcap_base_register_interface(extcap_conf, CISCODUMP_EXTCAP_INTERFACE, "Cisco remote capture", 147, "Remote capture dependent DLT");
help_header = g_strdup_printf(
" %s --extcap-interfaces\n"
" %s --extcap-interface=%s --extcap-dlts\n"
" %s --extcap-interface=%s --extcap-config\n"
" %s --extcap-interface=%s --remote-host myhost --remote-port 22222 "
"--remote-username myuser --remote-interface gigabit0/0 "
"--fifo=FILENAME --capture\n", argv[0], argv[0], CISCODUMP_EXTCAP_INTERFACE, argv[0],
CISCODUMP_EXTCAP_INTERFACE, argv[0], CISCODUMP_EXTCAP_INTERFACE);
extcap_help_add_header(extcap_conf, help_header);
g_free(help_header);
extcap_help_add_option(extcap_conf, "--help", "print this help");
extcap_help_add_option(extcap_conf, "--version", "print the version");
extcap_help_add_option(extcap_conf, "--remote-host <host>", "the remote SSH host");
extcap_help_add_option(extcap_conf, "--remote-port <port>", "the remote SSH port (default: 22)");
extcap_help_add_option(extcap_conf, "--remote-username <username>", "the remote SSH username (default: the current user)");
extcap_help_add_option(extcap_conf, "--remote-password <password>", "the remote SSH password. "
"If not specified, ssh-agent and ssh-key are used");
extcap_help_add_option(extcap_conf, "--sshkey <public key path>", "the path of the ssh key");
extcap_help_add_option(extcap_conf, "--sshkey-passphrase <public key passphrase>", "the passphrase to unlock public ssh");
extcap_help_add_option(extcap_conf, "--remote-interface <iface>", "the remote capture interface");
extcap_help_add_option(extcap_conf, "--remote-filter <filter>", "a filter for remote capture "
"(default: don't capture data for lal interfaces IPs)");
opterr = 0;
optind = 0;
if (argc == 1) {
extcap_help_print(extcap_conf);
goto end;
}
for (i = 0; i < argc; i++)
g_debug("%s ", argv[i]);
while ((result = getopt_long(argc, argv, ":", longopts, &option_idx)) != -1) {
switch (result) {
case OPT_HELP:
extcap_help_print(extcap_conf);
ret = EXIT_SUCCESS;
goto end;
case OPT_VERSION:
printf("%s\n", extcap_conf->version);
goto end;
case OPT_REMOTE_HOST:
g_free(remote_host);
remote_host = g_strdup(optarg);
break;
case OPT_REMOTE_PORT:
if (!ws_strtou16(optarg, NULL, &remote_port) || remote_port == 0) {
g_warning("Invalid port: %s", optarg);
goto end;
}
break;
case OPT_REMOTE_USERNAME:
g_free(remote_username);
remote_username = g_strdup(optarg);
break;
case OPT_REMOTE_PASSWORD:
g_free(remote_password);
remote_password = g_strdup(optarg);
memset(optarg, 'X', strlen(optarg));
break;
case OPT_SSHKEY:
g_free(sshkey);
sshkey = g_strdup(optarg);
break;
case OPT_SSHKEY_PASSPHRASE:
g_free(sshkey_passphrase);
sshkey_passphrase = g_strdup(optarg);
memset(optarg, 'X', strlen(optarg));
break;
case OPT_REMOTE_INTERFACE:
g_free(remote_interface);
remote_interface = g_strdup(optarg);
break;
case OPT_REMOTE_FILTER:
g_free(remote_filter);
remote_filter = g_strdup(optarg);
break;
case OPT_REMOTE_COUNT:
if (!ws_strtou32(optarg, NULL, &count)) {
g_warning("Invalid packet count: %s", optarg);
goto end;
}
break;
case ':':
g_warning("Option '%s' requires an argument", argv[optind - 1]);
break;
default:
if (!extcap_base_parse_options(extcap_conf, result - EXTCAP_OPT_LIST_INTERFACES, optarg)) {
g_warning("Invalid option: %s", argv[optind - 1]);
goto end;
}
}
}
if (optind != argc) {
g_warning("Unexpected extra option: %s", argv[optind]);
goto end;
}
if (extcap_base_handle_interface(extcap_conf)) {
ret = EXIT_SUCCESS;
goto end;
}
if (extcap_conf->show_config) {
ret = list_config(extcap_conf->interface, remote_port);
goto end;
}
#ifdef _WIN32
result = WSAStartup(MAKEWORD(1,1), &wsaData);
if (result != 0) {
g_warning("ERROR: WSAStartup failed with error: %d", result);
goto end;
}
#endif
if (extcap_conf->capture) {
if (!remote_host) {
g_warning("Missing parameter: --remote-host");
goto end;
}
if (!remote_interface) {
g_warning("ERROR: No interface specified (--remote-interface)");
goto end;
}
if (count == 0) {
g_warning("ERROR: count of packets must be specified (--remote-count)");
goto end;
}
ret = ssh_open_remote_connection(remote_host, remote_port, remote_username,
remote_password, sshkey, sshkey_passphrase, remote_interface,
remote_filter, count, extcap_conf->fifo);
} else {
g_debug("You should not come here... maybe some parameter missing?");
ret = EXIT_FAILURE;
}
end:
g_free(remote_host);
g_free(remote_username);
g_free(remote_password);
g_free(remote_interface);
g_free(sshkey);
g_free(sshkey_passphrase);
g_free(remote_filter);
extcap_base_cleanup(&extcap_conf);
return ret;
}
int _stdcall
WinMain (struct HINSTANCE__ *hInstance,
struct HINSTANCE__ *hPrevInstance,
char *lpszCmdLine,
int nCmdShow)
{
return main(__argc, __argv);
}
