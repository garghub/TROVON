void
capture_session_init(capture_session *cap_session, struct _capture_file *cf)
{
cap_session->cf = cf;
cap_session->fork_child = WS_INVALID_PID;
#ifdef _WIN32
cap_session->signal_pipe_write_fd = -1;
#endif
cap_session->state = CAPTURE_STOPPED;
#ifndef _WIN32
cap_session->owner = getuid();
cap_session->group = getgid();
#endif
cap_session->count = 0;
cap_session->session_started = FALSE;
}
static char **
sync_pipe_add_arg(char **args, int *argc, const char *arg)
{
args = (char **)g_realloc( (gpointer) args, (*argc + 2) * sizeof (char *));
args[*argc] = g_strdup(arg);
(*argc)++;
args[*argc] = NULL;
return args;
}
static char **
init_pipe_args(int *argc) {
char **argv;
const char *progfile_dir;
char *exename;
progfile_dir = get_progfile_dir();
if (progfile_dir == NULL) {
return NULL;
}
*argc = 0;
argv = (char **)g_malloc(sizeof (char *));
*argv = NULL;
#ifdef _WIN32
exename = g_strdup_printf("%s\\dumpcap.exe", progfile_dir);
#else
exename = g_strdup_printf("%s/dumpcap", progfile_dir);
#endif
argv = sync_pipe_add_arg(argv, argc, exename);
g_free(exename);
return argv;
}
gboolean
sync_pipe_start(capture_options *capture_opts, capture_session *cap_session, info_data_t* cap_data, void (*update_cb)(void))
{
char ssnap[ARGV_NUMBER_LEN];
char scount[ARGV_NUMBER_LEN];
char sfilesize[ARGV_NUMBER_LEN];
char sfile_duration[ARGV_NUMBER_LEN];
char sring_num_files[ARGV_NUMBER_LEN];
char sautostop_files[ARGV_NUMBER_LEN];
char sautostop_filesize[ARGV_NUMBER_LEN];
char sautostop_duration[ARGV_NUMBER_LEN];
#ifdef HAVE_PCAP_REMOTE
char sauth[256];
#endif
#ifdef HAVE_PCAP_SETSAMPLING
char ssampling[ARGV_NUMBER_LEN];
#endif
#ifdef CAN_SET_CAPTURE_BUFFER_SIZE
char buffer_size[ARGV_NUMBER_LEN];
#endif
#ifdef _WIN32
HANDLE sync_pipe_read;
HANDLE sync_pipe_write;
int signal_pipe_write_fd;
HANDLE signal_pipe;
GString *args = g_string_sized_new(200);
gchar *quoted_arg;
gunichar2 *wcommandline;
SECURITY_ATTRIBUTES sa;
STARTUPINFO si;
PROCESS_INFORMATION pi;
char control_id[ARGV_NUMBER_LEN];
gchar *signal_pipe_name;
#else
char errmsg[1024+1];
int sync_pipe[2];
enum PIPES { PIPE_READ, PIPE_WRITE };
#endif
int sync_pipe_read_fd;
int argc;
char **argv;
int i;
guint j;
interface_options interface_opts;
if (capture_opts->ifaces->len > 1)
capture_opts->use_pcapng = TRUE;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_pipe_start");
capture_opts_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, capture_opts);
cap_session->fork_child = WS_INVALID_PID;
#ifdef HAVE_EXTCAP
if (!extcap_init_interfaces(capture_opts)) {
report_failure("Unable to init extcaps. (tmp fifo already exists?)");
return FALSE;
}
#endif
argv = init_pipe_args(&argc);
if (!argv) {
report_failure("We don't know where to find dumpcap.");
return FALSE;
}
if (capture_opts->ifaces->len > 1)
argv = sync_pipe_add_arg(argv, &argc, "-t");
if (capture_opts->use_pcapng)
argv = sync_pipe_add_arg(argv, &argc, "-n");
else
argv = sync_pipe_add_arg(argv, &argc, "-P");
if (capture_opts->capture_comment) {
argv = sync_pipe_add_arg(argv, &argc, "--capture-comment");
argv = sync_pipe_add_arg(argv, &argc, capture_opts->capture_comment);
}
if (capture_opts->multi_files_on) {
if (capture_opts->has_autostop_filesize) {
argv = sync_pipe_add_arg(argv, &argc, "-b");
g_snprintf(sfilesize, ARGV_NUMBER_LEN, "filesize:%u",capture_opts->autostop_filesize);
argv = sync_pipe_add_arg(argv, &argc, sfilesize);
}
if (capture_opts->has_file_duration) {
argv = sync_pipe_add_arg(argv, &argc, "-b");
g_snprintf(sfile_duration, ARGV_NUMBER_LEN, "duration:%d",capture_opts->file_duration);
argv = sync_pipe_add_arg(argv, &argc, sfile_duration);
}
if (capture_opts->has_ring_num_files) {
argv = sync_pipe_add_arg(argv, &argc, "-b");
g_snprintf(sring_num_files, ARGV_NUMBER_LEN, "files:%d",capture_opts->ring_num_files);
argv = sync_pipe_add_arg(argv, &argc, sring_num_files);
}
if (capture_opts->has_autostop_files) {
argv = sync_pipe_add_arg(argv, &argc, "-a");
g_snprintf(sautostop_files, ARGV_NUMBER_LEN, "files:%d",capture_opts->autostop_files);
argv = sync_pipe_add_arg(argv, &argc, sautostop_files);
}
} else {
if (capture_opts->has_autostop_filesize) {
argv = sync_pipe_add_arg(argv, &argc, "-a");
g_snprintf(sautostop_filesize, ARGV_NUMBER_LEN, "filesize:%u",capture_opts->autostop_filesize);
argv = sync_pipe_add_arg(argv, &argc, sautostop_filesize);
}
}
if (capture_opts->has_autostop_packets) {
argv = sync_pipe_add_arg(argv, &argc, "-c");
g_snprintf(scount, ARGV_NUMBER_LEN, "%d",capture_opts->autostop_packets);
argv = sync_pipe_add_arg(argv, &argc, scount);
}
if (capture_opts->has_autostop_duration) {
argv = sync_pipe_add_arg(argv, &argc, "-a");
g_snprintf(sautostop_duration, ARGV_NUMBER_LEN, "duration:%d",capture_opts->autostop_duration);
argv = sync_pipe_add_arg(argv, &argc, sautostop_duration);
}
if (capture_opts->group_read_access) {
argv = sync_pipe_add_arg(argv, &argc, "-g");
}
for (j = 0; j < capture_opts->ifaces->len; j++) {
interface_opts = g_array_index(capture_opts->ifaces, interface_options, j);
argv = sync_pipe_add_arg(argv, &argc, "-i");
#ifdef HAVE_EXTCAP
if (interface_opts.extcap_fifo != NULL)
argv = sync_pipe_add_arg(argv, &argc, interface_opts.extcap_fifo);
else
#endif
argv = sync_pipe_add_arg(argv, &argc, interface_opts.name);
if (interface_opts.cfilter != NULL && strlen(interface_opts.cfilter) != 0) {
argv = sync_pipe_add_arg(argv, &argc, "-f");
argv = sync_pipe_add_arg(argv, &argc, interface_opts.cfilter);
}
if (interface_opts.snaplen != WTAP_MAX_PACKET_SIZE) {
argv = sync_pipe_add_arg(argv, &argc, "-s");
g_snprintf(ssnap, ARGV_NUMBER_LEN, "%d", interface_opts.snaplen);
argv = sync_pipe_add_arg(argv, &argc, ssnap);
}
if (interface_opts.linktype != -1) {
const char *linktype = linktype_val_to_name(interface_opts.linktype);
if ( linktype != NULL )
{
argv = sync_pipe_add_arg(argv, &argc, "-y");
argv = sync_pipe_add_arg(argv, &argc, linktype);
}
}
if (!interface_opts.promisc_mode) {
argv = sync_pipe_add_arg(argv, &argc, "-p");
}
#ifdef CAN_SET_CAPTURE_BUFFER_SIZE
if (interface_opts.buffer_size != DEFAULT_CAPTURE_BUFFER_SIZE) {
argv = sync_pipe_add_arg(argv, &argc, "-B");
if(interface_opts.buffer_size == 0x00)
interface_opts.buffer_size = DEFAULT_CAPTURE_BUFFER_SIZE;
g_snprintf(buffer_size, ARGV_NUMBER_LEN, "%d", interface_opts.buffer_size);
argv = sync_pipe_add_arg(argv, &argc, buffer_size);
}
#endif
#ifdef HAVE_PCAP_CREATE
if (interface_opts.monitor_mode) {
argv = sync_pipe_add_arg(argv, &argc, "-I");
}
#endif
#ifdef HAVE_PCAP_REMOTE
if (interface_opts.datatx_udp)
argv = sync_pipe_add_arg(argv, &argc, "-u");
if (!interface_opts.nocap_rpcap)
argv = sync_pipe_add_arg(argv, &argc, "-r");
if (interface_opts.auth_type == CAPTURE_AUTH_PWD) {
argv = sync_pipe_add_arg(argv, &argc, "-A");
g_snprintf(sauth, sizeof(sauth), "%s:%s",
interface_opts.auth_username,
interface_opts.auth_password);
argv = sync_pipe_add_arg(argv, &argc, sauth);
}
#endif
#ifdef HAVE_PCAP_SETSAMPLING
if (interface_opts.sampling_method != CAPTURE_SAMP_NONE) {
argv = sync_pipe_add_arg(argv, &argc, "-m");
g_snprintf(ssampling, ARGV_NUMBER_LEN, "%s:%d",
interface_opts.sampling_method == CAPTURE_SAMP_BY_COUNT ? "count" :
interface_opts.sampling_method == CAPTURE_SAMP_BY_TIMER ? "timer" :
"undef",
interface_opts.sampling_param);
argv = sync_pipe_add_arg(argv, &argc, ssampling);
}
#endif
}
#ifndef DEBUG_CHILD
argv = sync_pipe_add_arg(argv, &argc, "-Z");
#ifdef _WIN32
g_snprintf(control_id, ARGV_NUMBER_LEN, "%d", GetCurrentProcessId());
argv = sync_pipe_add_arg(argv, &argc, control_id);
#else
argv = sync_pipe_add_arg(argv, &argc, SIGNAL_PIPE_CTRL_ID_NONE);
#endif
#endif
if (capture_opts->save_file) {
argv = sync_pipe_add_arg(argv, &argc, "-w");
argv = sync_pipe_add_arg(argv, &argc, capture_opts->save_file);
}
for (i = 0; i < argc; i++) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "argv[%d]: %s", i, argv[i]);
}
#ifdef _WIN32
sa.nLength = sizeof(SECURITY_ATTRIBUTES);
sa.bInheritHandle = TRUE;
sa.lpSecurityDescriptor = NULL;
if (! CreatePipe(&sync_pipe_read, &sync_pipe_write, &sa, 5120)) {
report_failure("Couldn't create sync pipe: %s",
win32strerror(GetLastError()));
for (i = 0; i < argc; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
return FALSE;
}
sync_pipe_read_fd = _open_osfhandle( (intptr_t) sync_pipe_read, _O_BINARY);
if (sync_pipe_read_fd == -1) {
report_failure("Couldn't get C file handle for sync pipe: %s", g_strerror(errno));
CloseHandle(sync_pipe_read);
CloseHandle(sync_pipe_write);
for (i = 0; i < argc; i++) {
g_free( (gpointer) argv[i]);
}
g_free(argv);
return FALSE;
}
signal_pipe_name = g_strdup_printf(SIGNAL_PIPE_FORMAT, control_id);
signal_pipe = CreateNamedPipe(utf_8to16(signal_pipe_name),
PIPE_ACCESS_OUTBOUND, PIPE_TYPE_BYTE, 1, 65535, 65535, 0, NULL);
g_free(signal_pipe_name);
if (signal_pipe == INVALID_HANDLE_VALUE) {
report_failure("Couldn't create signal pipe: %s",
win32strerror(GetLastError()));
ws_close(sync_pipe_read_fd);
CloseHandle(sync_pipe_write);
for (i = 0; i < argc; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
return FALSE;
}
signal_pipe_write_fd = _open_osfhandle( (intptr_t) signal_pipe, _O_BINARY);
if (sync_pipe_read_fd == -1) {
report_failure("Couldn't get C file handle for sync pipe: %s", g_strerror(errno));
ws_close(sync_pipe_read_fd);
CloseHandle(sync_pipe_write);
CloseHandle(signal_pipe);
for (i = 0; i < argc; i++) {
g_free( (gpointer) argv[i]);
}
g_free(argv);
return FALSE;
}
memset(&si, 0, sizeof(si));
si.cb = sizeof(si);
memset(&pi, 0, sizeof(pi));
#ifdef DEBUG_CHILD
si.dwFlags = STARTF_USESHOWWINDOW;
si.wShowWindow = SW_SHOW;
#else
si.dwFlags = STARTF_USESTDHANDLES|STARTF_USESHOWWINDOW;
si.wShowWindow = SW_HIDE;
#if defined(_WIN32)
if(interface_opts.extcap_fifo != NULL)
{
if(strncmp(interface_opts.extcap_fifo,"\\\\.\\pipe\\",9)== 0)
{
si.hStdInput = extcap_get_win32_handle();
}
}
else
#endif
si.hStdInput = GetStdHandle(STD_INPUT_HANDLE);
si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
si.hStdError = sync_pipe_write;
#endif
for(i=0; argv[i] != 0; i++) {
if(i != 0) g_string_append_c(args, ' ');
quoted_arg = protect_arg(argv[i]);
g_string_append(args, quoted_arg);
g_free(quoted_arg);
}
wcommandline = g_utf8_to_utf16(args->str, (glong)args->len, NULL, NULL, NULL);
if(!CreateProcess(utf_8to16(argv[0]), wcommandline, NULL, NULL, TRUE,
CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
report_failure("Couldn't run %s in child process: %s",
args->str, win32strerror(GetLastError()));
ws_close(sync_pipe_read_fd);
CloseHandle(sync_pipe_write);
CloseHandle(signal_pipe);
for (i = 0; i < argc; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
g_string_free(args, TRUE);
g_free(wcommandline);
return FALSE;
}
cap_session->fork_child = pi.hProcess;
CloseHandle(pi.hThread);
g_string_free(args, TRUE);
g_free(wcommandline);
cap_session->signal_pipe_write_fd = signal_pipe_write_fd;
#else
if (pipe(sync_pipe) < 0) {
report_failure("Couldn't create sync pipe: %s", g_strerror(errno));
for (i = 0; i < argc; i++) {
g_free( (gpointer) argv[i]);
}
g_free(argv);
return FALSE;
}
if ((cap_session->fork_child = fork()) == 0) {
dup2(sync_pipe[PIPE_WRITE], 2);
ws_close(sync_pipe[PIPE_READ]);
execv(argv[0], argv);
g_snprintf(errmsg, sizeof errmsg, "Couldn't run %s in child process: %s",
argv[0], g_strerror(errno));
sync_pipe_errmsg_to_parent(2, errmsg, "");
_exit(1);
}
if (fetch_dumpcap_pid && cap_session->fork_child > 0)
fetch_dumpcap_pid(cap_session->fork_child);
sync_pipe_read_fd = sync_pipe[PIPE_READ];
#endif
for (i = 0; i < argc; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
#ifdef _WIN32
CloseHandle(sync_pipe_write);
#else
ws_close(sync_pipe[PIPE_WRITE]);
#endif
if (cap_session->fork_child == WS_INVALID_PID) {
report_failure("Couldn't create child process: %s", g_strerror(errno));
ws_close(sync_pipe_read_fd);
#ifdef _WIN32
ws_close(cap_session->signal_pipe_write_fd);
#endif
return FALSE;
}
cap_session->fork_child_status = 0;
cap_session->capture_opts = capture_opts;
cap_session->cap_data_info = cap_data;
if (update_cb) update_cb();
pipe_input_set_handler(sync_pipe_read_fd, (gpointer) cap_session,
&cap_session->fork_child, sync_pipe_input_cb);
return TRUE;
}
static int
sync_pipe_open_command(char** argv, int *data_read_fd,
int *message_read_fd, ws_process_id *fork_child, gchar **msg, void(*update_cb)(void))
{
enum PIPES { PIPE_READ, PIPE_WRITE };
#ifdef _WIN32
HANDLE sync_pipe[2];
HANDLE data_pipe[2];
GString *args = g_string_sized_new(200);
gchar *quoted_arg;
gunichar2 *wcommandline;
SECURITY_ATTRIBUTES sa;
STARTUPINFO si;
PROCESS_INFORMATION pi;
#else
char errmsg[1024+1];
int sync_pipe[2];
int data_pipe[2];
#endif
int i;
*fork_child = WS_INVALID_PID;
*data_read_fd = -1;
*message_read_fd = -1;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_pipe_open_command");
if (!msg) {
#ifdef _WIN32
g_string_free(args, TRUE);
#endif
return -1;
}
#ifdef _WIN32
sa.nLength = sizeof(SECURITY_ATTRIBUTES);
sa.bInheritHandle = TRUE;
sa.lpSecurityDescriptor = NULL;
if (! CreatePipe(&sync_pipe[PIPE_READ], &sync_pipe[PIPE_WRITE], &sa, 5120)) {
*msg = g_strdup_printf("Couldn't create sync pipe: %s",
win32strerror(GetLastError()));
for (i = 0; argv[i] != NULL; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
return -1;
}
*message_read_fd = _open_osfhandle( (intptr_t) sync_pipe[PIPE_READ], _O_BINARY);
if (*message_read_fd == -1) {
*msg = g_strdup_printf("Couldn't get C file handle for message read pipe: %s", g_strerror(errno));
CloseHandle(sync_pipe[PIPE_READ]);
CloseHandle(sync_pipe[PIPE_WRITE]);
for (i = 0; argv[i] != NULL; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
return -1;
}
if (! CreatePipe(&data_pipe[PIPE_READ], &data_pipe[PIPE_WRITE], &sa, 5120)) {
*msg = g_strdup_printf("Couldn't create data pipe: %s",
win32strerror(GetLastError()));
ws_close(*message_read_fd);
CloseHandle(sync_pipe[PIPE_WRITE]);
for (i = 0; argv[i] != NULL; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
return -1;
}
*data_read_fd = _open_osfhandle( (intptr_t) data_pipe[PIPE_READ], _O_BINARY);
if (*data_read_fd == -1) {
*msg = g_strdup_printf("Couldn't get C file handle for data read pipe: %s", g_strerror(errno));
CloseHandle(data_pipe[PIPE_READ]);
CloseHandle(data_pipe[PIPE_WRITE]);
ws_close(*message_read_fd);
CloseHandle(sync_pipe[PIPE_WRITE]);
for (i = 0; argv[i] != NULL; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
return -1;
}
memset(&si, 0, sizeof(si));
si.cb = sizeof(si);
memset(&pi, 0, sizeof(pi));
#ifdef DEBUG_CHILD
si.dwFlags = STARTF_USESHOWWINDOW;
si.wShowWindow = SW_SHOW;
#else
si.dwFlags = STARTF_USESTDHANDLES|STARTF_USESHOWWINDOW;
si.wShowWindow = SW_HIDE;
si.hStdInput = NULL;
si.hStdOutput = data_pipe[PIPE_WRITE];
si.hStdError = sync_pipe[PIPE_WRITE];
#endif
for(i=0; argv[i] != 0; i++) {
if(i != 0) g_string_append_c(args, ' ');
quoted_arg = protect_arg(argv[i]);
g_string_append(args, quoted_arg);
g_free(quoted_arg);
}
wcommandline = g_utf8_to_utf16(args->str, (glong)args->len, NULL, NULL, NULL);
if(!CreateProcess(utf_8to16(argv[0]), wcommandline, NULL, NULL, TRUE,
CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
*msg = g_strdup_printf("Couldn't run %s in child process: %s",
args->str, win32strerror(GetLastError()));
ws_close(*data_read_fd);
CloseHandle(data_pipe[PIPE_WRITE]);
ws_close(*message_read_fd);
CloseHandle(sync_pipe[PIPE_WRITE]);
for (i = 0; argv[i] != NULL; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
g_string_free(args, TRUE);
g_free(wcommandline);
return -1;
}
*fork_child = pi.hProcess;
CloseHandle(pi.hThread);
g_string_free(args, TRUE);
g_free(wcommandline);
#else
if (pipe(sync_pipe) < 0) {
*msg = g_strdup_printf("Couldn't create sync pipe: %s", g_strerror(errno));
for (i = 0; argv[i] != NULL; i++) {
g_free( (gpointer) argv[i]);
}
g_free(argv);
return -1;
}
if (pipe(data_pipe) < 0) {
*msg = g_strdup_printf("Couldn't create data pipe: %s", g_strerror(errno));
ws_close(sync_pipe[PIPE_READ]);
ws_close(sync_pipe[PIPE_WRITE]);
for (i = 0; argv[i] != NULL; i++) {
g_free( (gpointer) argv[i]);
}
g_free(argv);
return -1;
}
if ((*fork_child = fork()) == 0) {
dup2(data_pipe[PIPE_WRITE], 1);
ws_close(data_pipe[PIPE_READ]);
ws_close(data_pipe[PIPE_WRITE]);
dup2(sync_pipe[PIPE_WRITE], 2);
ws_close(sync_pipe[PIPE_READ]);
ws_close(sync_pipe[PIPE_WRITE]);
execv(argv[0], argv);
g_snprintf(errmsg, sizeof errmsg, "Couldn't run %s in child process: %s",
argv[0], g_strerror(errno));
sync_pipe_errmsg_to_parent(2, errmsg, "");
_exit(1);
}
if (fetch_dumpcap_pid && *fork_child > 0)
fetch_dumpcap_pid(*fork_child);
*data_read_fd = data_pipe[PIPE_READ];
*message_read_fd = sync_pipe[PIPE_READ];
#endif
for (i = 0; argv[i] != NULL; i++) {
g_free( (gpointer) argv[i]);
}
g_free( (gpointer) argv);
#ifdef _WIN32
CloseHandle(data_pipe[PIPE_WRITE]);
CloseHandle(sync_pipe[PIPE_WRITE]);
#else
ws_close(data_pipe[PIPE_WRITE]);
ws_close(sync_pipe[PIPE_WRITE]);
#endif
if (*fork_child == WS_INVALID_PID) {
*msg = g_strdup_printf("Couldn't create child process: %s", g_strerror(errno));
ws_close(*data_read_fd);
ws_close(*message_read_fd);
return -1;
}
if (update_cb) update_cb();
return 0;
}
static int
sync_pipe_close_command(int *data_read_fd, int *message_read_fd,
ws_process_id *fork_child, gchar **msgp)
{
ws_close(*data_read_fd);
if (message_read_fd != NULL)
ws_close(*message_read_fd);
#ifdef _WIN32
sync_pipe_kill(*fork_child);
#endif
return sync_pipe_wait_for_child(*fork_child, msgp);
}
static int
sync_pipe_run_command_actual(char** argv, gchar **data, gchar **primary_msg,
gchar **secondary_msg, void(*update_cb)(void))
{
gchar *msg;
int data_pipe_read_fd, sync_pipe_read_fd, ret;
ws_process_id fork_child;
char *wait_msg;
gchar buffer[PIPE_BUF_SIZE+1] = {0};
ssize_t nread;
char indicator;
int primary_msg_len;
char *primary_msg_text;
int secondary_msg_len;
char *secondary_msg_text;
char *combined_msg;
GString *data_buf = NULL;
ssize_t count;
ret = sync_pipe_open_command(argv, &data_pipe_read_fd, &sync_pipe_read_fd,
&fork_child, &msg, update_cb);
if (ret == -1) {
*primary_msg = msg;
*secondary_msg = NULL;
*data = NULL;
return -1;
}
nread = pipe_read_block(sync_pipe_read_fd, &indicator, SP_MAX_MSG_LEN,
buffer, primary_msg);
if(nread <= 0) {
ret = sync_pipe_wait_for_child(fork_child, &wait_msg);
if(nread == 0) {
if (ret == -1)
*primary_msg = wait_msg;
else
*primary_msg = g_strdup("Child dumpcap closed sync pipe prematurely");
} else {
if (ret == -1) {
combined_msg = g_strdup_printf("%s\n\n%s", *primary_msg, wait_msg);
g_free(*primary_msg);
g_free(wait_msg);
*primary_msg = combined_msg;
}
}
*secondary_msg = NULL;
*data = NULL;
return -1;
}
switch(indicator) {
case SP_ERROR_MSG:
pipe_convert_header((guchar*)buffer, 4, &indicator, &primary_msg_len);
primary_msg_text = buffer+4;
pipe_convert_header((guchar*)primary_msg_text + primary_msg_len, 4, &indicator,
&secondary_msg_len);
secondary_msg_text = primary_msg_text + primary_msg_len + 4;
ret = sync_pipe_close_command(&data_pipe_read_fd, &sync_pipe_read_fd,
&fork_child, &msg);
if (ret == -1) {
*primary_msg = msg;
*secondary_msg = NULL;
} else {
*primary_msg = g_strdup(primary_msg_text);
*secondary_msg = g_strdup(secondary_msg_text);
ret = -1;
}
*data = NULL;
break;
case SP_SUCCESS:
data_buf = g_string_new("");
while ((count = ws_read(data_pipe_read_fd, buffer, PIPE_BUF_SIZE)) > 0) {
buffer[count] = '\0';
g_string_append(data_buf, buffer);
}
ret = sync_pipe_close_command(&data_pipe_read_fd, &sync_pipe_read_fd,
&fork_child, &msg);
if (ret == -1) {
*primary_msg = msg;
*secondary_msg = NULL;
g_string_free(data_buf, TRUE);
*data = NULL;
} else {
*primary_msg = NULL;
*secondary_msg = NULL;
*data = g_string_free(data_buf, FALSE);
}
break;
default:
ret = sync_pipe_close_command(&data_pipe_read_fd, &sync_pipe_read_fd,
&fork_child, &msg);
if (ret == -1) {
*primary_msg = msg;
*secondary_msg = NULL;
} else {
*primary_msg = g_strdup_printf("dumpcap process gave an unexpected message type: 0x%02x",
indicator);
*secondary_msg = NULL;
ret = -1;
}
*data = NULL;
break;
}
return ret;
}
static int
sync_pipe_run_command(char** argv, gchar **data, gchar **primary_msg,
gchar **secondary_msg, void (*update_cb)(void))
{
int ret, i;
GTimeVal start_time;
GTimeVal end_time;
float elapsed;
int logging_enabled;
logging_enabled=( (G_LOG_LEVEL_DEBUG | G_LOG_LEVEL_INFO) & G_LOG_LEVEL_MASK & prefs.console_log_level);
if(logging_enabled){
g_get_current_time(&start_time);
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_INFO, "sync_pipe_run_command() starts");
for(i=0; argv[i] != 0; i++) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, " argv[%d]: %s", i, argv[i]);
}
}
ret=sync_pipe_run_command_actual(argv, data, primary_msg, secondary_msg, update_cb);
if(logging_enabled){
g_get_current_time(&end_time);
elapsed = (float) ((end_time.tv_sec - start_time.tv_sec) +
((end_time.tv_usec - start_time.tv_usec) / 1e6));
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_INFO, "sync_pipe_run_command() ends, taking %.3fs, result=%d", elapsed, ret);
}
return ret;
}
int
sync_interface_set_80211_chan(const gchar *iface, const char *freq, const gchar *type,
const gchar *center_freq1, const gchar *center_freq2,
gchar **data, gchar **primary_msg,
gchar **secondary_msg, void (*update_cb)(void))
{
int argc, ret;
char **argv;
gchar *opt;
argv = init_pipe_args(&argc);
if (!argv) {
*primary_msg = g_strdup("We don't know where to find dumpcap.");
*secondary_msg = NULL;
*data = NULL;
return -1;
}
argv = sync_pipe_add_arg(argv, &argc, "-i");
argv = sync_pipe_add_arg(argv, &argc, iface);
if (type)
opt = g_strdup_printf("%s,%s,%s,%s", freq, type, center_freq1, center_freq2);
else
opt = g_strdup(freq);
if (!opt) {
*primary_msg = g_strdup("Out of mem.");
*secondary_msg = NULL;
*data = NULL;
return -1;
}
argv = sync_pipe_add_arg(argv, &argc, "-k");
argv = sync_pipe_add_arg(argv, &argc, opt);
#ifndef DEBUG_CHILD
argv = sync_pipe_add_arg(argv, &argc, "-Z");
argv = sync_pipe_add_arg(argv, &argc, SIGNAL_PIPE_CTRL_ID_NONE);
#endif
ret = sync_pipe_run_command(argv, data, primary_msg, secondary_msg, update_cb);
g_free(opt);
return ret;
}
int
sync_interface_list_open(gchar **data, gchar **primary_msg,
gchar **secondary_msg, void (*update_cb)(void))
{
int argc;
char **argv;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_interface_list_open");
argv = init_pipe_args(&argc);
if (!argv) {
*primary_msg = g_strdup("We don't know where to find dumpcap..");
*secondary_msg = NULL;
*data = NULL;
return -1;
}
argv = sync_pipe_add_arg(argv, &argc, "-D");
#ifndef DEBUG_CHILD
argv = sync_pipe_add_arg(argv, &argc, "-Z");
argv = sync_pipe_add_arg(argv, &argc, SIGNAL_PIPE_CTRL_ID_NONE);
#endif
return sync_pipe_run_command(argv, data, primary_msg, secondary_msg, update_cb);
}
int
sync_if_capabilities_open(const gchar *ifname, gboolean monitor_mode, const gchar* auth,
gchar **data, gchar **primary_msg,
gchar **secondary_msg, void (*update_cb)(void))
{
int argc;
char **argv;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_if_capabilities_open");
argv = init_pipe_args(&argc);
if (!argv) {
*primary_msg = g_strdup("We don't know where to find dumpcap.");
*secondary_msg = NULL;
*data = NULL;
return -1;
}
argv = sync_pipe_add_arg(argv, &argc, "-i");
argv = sync_pipe_add_arg(argv, &argc, ifname);
argv = sync_pipe_add_arg(argv, &argc, "-L");
if (monitor_mode)
argv = sync_pipe_add_arg(argv, &argc, "-I");
if (auth) {
argv = sync_pipe_add_arg(argv, &argc, "-A");
argv = sync_pipe_add_arg(argv, &argc, auth);
}
#ifndef DEBUG_CHILD
argv = sync_pipe_add_arg(argv, &argc, "-Z");
argv = sync_pipe_add_arg(argv, &argc, SIGNAL_PIPE_CTRL_ID_NONE);
#endif
return sync_pipe_run_command(argv, data, primary_msg, secondary_msg, update_cb);
}
int
sync_interface_stats_open(int *data_read_fd, ws_process_id *fork_child, gchar **msg, void (*update_cb)(void))
{
int argc;
char **argv;
int message_read_fd, ret;
char *wait_msg;
gchar buffer[PIPE_BUF_SIZE+1] = {0};
ssize_t nread;
char indicator;
int primary_msg_len;
char *primary_msg_text;
int secondary_msg_len;
char *combined_msg;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_interface_stats_open");
argv = init_pipe_args(&argc);
if (!argv) {
*msg = g_strdup("We don't know where to find dumpcap.");
return -1;
}
argv = sync_pipe_add_arg(argv, &argc, "-S");
#ifndef DEBUG_CHILD
argv = sync_pipe_add_arg(argv, &argc, "-Z");
#ifdef _WIN32
create_dummy_signal_pipe();
argv = sync_pipe_add_arg(argv, &argc, dummy_control_id);
#else
argv = sync_pipe_add_arg(argv, &argc, SIGNAL_PIPE_CTRL_ID_NONE);
#endif
#endif
ret = sync_pipe_open_command(argv, data_read_fd, &message_read_fd,
fork_child, msg, update_cb);
if (ret == -1)
return -1;
nread = pipe_read_block(message_read_fd, &indicator, SP_MAX_MSG_LEN,
buffer, msg);
if(nread <= 0) {
ret = sync_pipe_wait_for_child(*fork_child, &wait_msg);
ws_close(message_read_fd);
ws_close(*data_read_fd);
if(nread == 0) {
if (ret == -1)
*msg = wait_msg;
else
*msg = g_strdup("Child dumpcap closed sync pipe prematurely");
} else {
if (ret == -1) {
combined_msg = g_strdup_printf("%s\n\n%s", *msg, wait_msg);
g_free(*msg);
g_free(wait_msg);
*msg = combined_msg;
}
}
return -1;
}
switch(indicator) {
case SP_ERROR_MSG:
pipe_convert_header((guchar*)buffer, 4, &indicator, &primary_msg_len);
primary_msg_text = buffer+4;
pipe_convert_header((guchar*)primary_msg_text + primary_msg_len, 4, &indicator,
&secondary_msg_len);
ret = sync_pipe_close_command(data_read_fd, &message_read_fd,
fork_child, msg);
if (ret == -1) {
} else {
*msg = g_strdup(primary_msg_text);
ret = -1;
}
break;
case SP_SUCCESS:
ws_close(message_read_fd);
break;
default:
ret = sync_pipe_close_command(data_read_fd, &message_read_fd,
fork_child, msg);
if (ret == -1) {
} else {
*msg = g_strdup_printf("dumpcap process gave an unexpected message type: 0x%02x",
indicator);
ret = -1;
}
break;
}
return ret;
}
int
sync_interface_stats_close(int *read_fd, ws_process_id *fork_child, gchar **msg)
{
#ifndef _WIN32
sync_pipe_kill(*fork_child);
#endif
return sync_pipe_close_command(read_fd, NULL, fork_child, msg);
}
static ssize_t
pipe_read_bytes(int pipe_fd, char *bytes, int required, char **msg)
{
ssize_t newly;
ssize_t offset = 0;
int error;
while(required) {
newly = ws_read(pipe_fd, &bytes[offset], required);
if (newly == 0) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG,
"read from pipe %d: EOF (capture closed?)", pipe_fd);
*msg = 0;
return offset;
}
if (newly < 0) {
error = errno;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG,
"read from pipe %d: error(%u): %s", pipe_fd, error,
g_strerror(error));
*msg = g_strdup_printf("Error reading from sync pipe: %s",
g_strerror(error));
return newly;
}
required -= (int)newly;
offset += newly;
}
*msg = NULL;
return offset;
}
static gboolean pipe_data_available(int pipe_fd) {
#ifdef _WIN32
HANDLE hPipe = (HANDLE) _get_osfhandle(pipe_fd);
DWORD bytes_avail;
if (hPipe == INVALID_HANDLE_VALUE)
return FALSE;
if (! PeekNamedPipe(hPipe, NULL, 0, NULL, &bytes_avail, NULL))
return FALSE;
if (bytes_avail > 0)
return TRUE;
return FALSE;
#else
fd_set rfds;
struct timeval timeout;
FD_ZERO(&rfds);
FD_SET(pipe_fd, &rfds);
timeout.tv_sec = 0;
timeout.tv_usec = 0;
if (select(pipe_fd+1, &rfds, NULL, NULL, &timeout) > 0)
return TRUE;
return FALSE;
#endif
}
int
sync_pipe_gets_nonblock(int pipe_fd, char *bytes, int max) {
ssize_t newly;
int offset = -1;
while(offset < max - 1) {
offset++;
if (! pipe_data_available(pipe_fd))
break;
newly = ws_read(pipe_fd, &bytes[offset], 1);
if (newly == 0) {
break;
} else if (newly == -1) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG,
"read from pipe %d: error(%u): %s", pipe_fd, errno, g_strerror(errno));
return -1;
} else if (bytes[offset] == '\n') {
break;
}
}
if (offset >= 0)
bytes[offset] = '\0';
return offset;
}
static void
pipe_convert_header(const guchar *header, int header_len, char *indicator, int *block_len) {
g_assert(header_len == 4);
*indicator = header[0];
*block_len = (header[1]&0xFF)<<16 | (header[2]&0xFF)<<8 | (header[3]&0xFF);
}
static ssize_t
pipe_read_block(int pipe_fd, char *indicator, int len, char *msg,
char **err_msg)
{
int required;
ssize_t newly;
gchar header[4];
newly = pipe_read_bytes(pipe_fd, header, 4, err_msg);
if(newly != 4) {
if (newly == 0) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG,
"read %d got an EOF", pipe_fd);
return 0;
}
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG,
"read %d failed to read header: %lu", pipe_fd, (long)newly);
if (newly != -1) {
*err_msg = g_strdup_printf("Premature EOF reading from sync pipe: got only %ld bytes",
(long)newly);
}
return -1;
}
pipe_convert_header((guchar*)header, 4, indicator, &required);
if(required == 0) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG,
"read %d indicator: %c empty value", pipe_fd, *indicator);
return 4;
}
if(required > len) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG,
"read %d length error, required %d > len %d, header: 0x%02x 0x%02x 0x%02x 0x%02x",
pipe_fd, required, len,
header[0], header[1], header[2], header[3]);
memcpy(msg, header, sizeof(header));
newly = ws_read(pipe_fd, &msg[sizeof(header)], len-sizeof(header));
if (newly < 0) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG,
"read from pipe %d: error(%u): %s", pipe_fd, errno, g_strerror(errno));
}
*err_msg = g_strdup_printf("Unknown message from dumpcap, try to show it as a string: %s",
msg);
return -1;
}
len = required;
newly = pipe_read_bytes(pipe_fd, msg, required, err_msg);
if(newly != required) {
if (newly != -1) {
*err_msg = g_strdup_printf("Unknown message from dumpcap, try to show it as a string: %s",
msg);
}
return -1;
}
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG,
"read %d ok indicator: %c len: %u msg: %s", pipe_fd, *indicator,
len, msg);
*err_msg = NULL;
return newly + 4;
}
static gboolean
sync_pipe_input_cb(gint source, gpointer user_data)
{
capture_session *cap_session = (capture_session *)user_data;
int ret;
char buffer[SP_MAX_MSG_LEN+1] = {0};
ssize_t nread;
char indicator;
int primary_len;
char *primary_msg;
int secondary_len;
char *secondary_msg;
char *wait_msg, *combined_msg;
int npackets;
nread = pipe_read_block(source, &indicator, SP_MAX_MSG_LEN, buffer,
&primary_msg);
if(nread <= 0) {
ret = sync_pipe_wait_for_child(cap_session->fork_child, &wait_msg);
if(nread == 0) {
if (ret == -1)
primary_msg = wait_msg;
} else {
if (ret == -1) {
combined_msg = g_strdup_printf("%s\n\n%s", primary_msg, wait_msg);
g_free(primary_msg);
g_free(wait_msg);
primary_msg = combined_msg;
}
}
cap_session->fork_child = WS_INVALID_PID;
cap_session->fork_child_status = ret;
#ifdef _WIN32
ws_close(cap_session->signal_pipe_write_fd);
#endif
#ifdef HAVE_EXTCAP
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_pipe_input_cb: cleaning extcap pipe");
extcap_if_cleanup(cap_session->capture_opts, &primary_msg);
#endif
capture_input_closed(cap_session, primary_msg);
g_free(primary_msg);
return FALSE;
}
switch(indicator) {
case SP_FILE:
if(!capture_input_new_file(cap_session, buffer)) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_pipe_input_cb: file failed, closing capture");
ws_close(source);
sync_pipe_stop(cap_session);
capture_input_closed(cap_session, NULL);
return FALSE;
}
break;
case SP_PACKET_COUNT:
npackets = atoi(buffer);
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_pipe_input_cb: new packets %u", npackets);
cap_session->count += npackets;
capture_input_new_packets(cap_session, npackets);
break;
case SP_ERROR_MSG:
pipe_convert_header((guchar*)buffer, 4, &indicator, &primary_len);
primary_msg = buffer+4;
pipe_convert_header((guchar*)primary_msg + primary_len, 4, &indicator, &secondary_len);
secondary_msg = primary_msg + primary_len + 4;
capture_input_error_message(cap_session, primary_msg, secondary_msg);
break;
case SP_BAD_FILTER: {
char *ch=NULL;
int indx=0;
ch = strtok(buffer, ":");
if (ch) {
indx = (int)strtol(ch, NULL, 10);
ch = strtok(NULL, ":");
}
capture_input_cfilter_error_message(cap_session, indx, ch);
break;
}
case SP_DROPS:
capture_input_drops(cap_session, (guint32)strtoul(buffer, NULL, 10));
break;
default:
g_assert_not_reached();
}
return TRUE;
}
static int
sync_pipe_wait_for_child(ws_process_id fork_child, gchar **msgp)
{
int fork_child_status;
#ifndef _WIN32
int retry_waitpid = 3;
#endif
int ret = -1;
GTimeVal start_time;
GTimeVal end_time;
float elapsed;
g_get_current_time(&start_time);
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_pipe_wait_for_child: wait till child closed");
g_assert(fork_child != WS_INVALID_PID);
*msgp = NULL;
#ifdef _WIN32
if (_cwait(&fork_child_status, (intptr_t) fork_child, _WAIT_CHILD) == -1) {
*msgp = g_strdup_printf("Error from cwait(): %s", g_strerror(errno));
ret = -1;
} else {
ret = fork_child_status;
if ((fork_child_status & 0xC0000000) == ERROR_SEVERITY_ERROR) {
*msgp = g_strdup_printf("Child dumpcap process died: %s",
win32strexception(fork_child_status));
ret = -1;
}
}
#else
while (--retry_waitpid >= 0) {
if (waitpid(fork_child, &fork_child_status, 0) != -1) {
if (WIFEXITED(fork_child_status)) {
ret = WEXITSTATUS(fork_child_status);
} else if (WIFSTOPPED(fork_child_status)) {
*msgp = g_strdup_printf("Child dumpcap process stopped: %s",
sync_pipe_signame(WSTOPSIG(fork_child_status)));
ret = -1;
} else if (WIFSIGNALED(fork_child_status)) {
*msgp = g_strdup_printf("Child dumpcap process died: %s%s",
sync_pipe_signame(WTERMSIG(fork_child_status)),
WCOREDUMP(fork_child_status) ? " - core dumped" : "");
ret = -1;
} else {
*msgp = g_strdup_printf("Bad status from waitpid(): %#o",
fork_child_status);
ret = -1;
}
} else {
if (errno == EINTR) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_WARNING, "sync_pipe_wait_for_child: waitpid returned EINTR. retrying.");
continue;
} else if (errno == ECHILD) {
ret = fetch_dumpcap_pid ? 0 : -1;
} else {
*msgp = g_strdup_printf("Error from waitpid(): %s", g_strerror(errno));
ret = -1;
}
}
break;
}
#endif
g_get_current_time(&end_time);
elapsed = (float) ((end_time.tv_sec - start_time.tv_sec) +
((end_time.tv_usec - start_time.tv_usec) / 1e6));
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "sync_pipe_wait_for_child: capture child closed after %.3fs", elapsed);
return ret;
}
static const char *
sync_pipe_signame(int sig)
{
const char *sigmsg;
static char sigmsg_buf[6+1+3+1];
switch (sig) {
case SIGHUP:
sigmsg = "Hangup";
break;
case SIGINT:
sigmsg = "Interrupted";
break;
case SIGQUIT:
sigmsg = "Quit";
break;
case SIGILL:
sigmsg = "Illegal instruction";
break;
case SIGTRAP:
sigmsg = "Trace trap";
break;
case SIGABRT:
sigmsg = "Abort";
break;
case SIGFPE:
sigmsg = "Arithmetic exception";
break;
case SIGKILL:
sigmsg = "Killed";
break;
case SIGBUS:
sigmsg = "Bus error";
break;
case SIGSEGV:
sigmsg = "Segmentation violation";
break;
#ifdef SIGSYS
case SIGSYS:
sigmsg = "Bad system call";
break;
#endif
case SIGPIPE:
sigmsg = "Broken pipe";
break;
case SIGALRM:
sigmsg = "Alarm clock";
break;
case SIGTERM:
sigmsg = "Terminated";
break;
default:
g_snprintf(sigmsg_buf, sizeof sigmsg_buf, "Signal %d", sig);
sigmsg = sigmsg_buf;
break;
}
return sigmsg;
}
static void create_dummy_signal_pipe() {
gchar *dummy_signal_pipe_name;
if (dummy_signal_pipe != NULL) return;
if (!dummy_control_id) {
dummy_control_id = g_strdup_printf("%d.dummy", GetCurrentProcessId());
}
dummy_signal_pipe_name = g_strdup_printf(SIGNAL_PIPE_FORMAT, dummy_control_id);
dummy_signal_pipe = CreateNamedPipe(utf_8to16(dummy_signal_pipe_name),
PIPE_ACCESS_OUTBOUND, PIPE_TYPE_BYTE, 1, 65535, 65535, 0, NULL);
g_free(dummy_signal_pipe_name);
}
static void
signal_pipe_capquit_to_child(capture_session *cap_session)
{
const char quit_msg[] = "QUIT";
int ret;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_DEBUG, "signal_pipe_capquit_to_child");
ret = ws_write(cap_session->signal_pipe_write_fd, quit_msg, sizeof quit_msg);
if(ret == -1) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_WARNING,
"signal_pipe_capquit_to_child: %d header: error %s", cap_session->signal_pipe_write_fd, g_strerror(errno));
}
}
void
sync_pipe_stop(capture_session *cap_session)
{
#ifdef _WIN32
int count;
DWORD childstatus;
gboolean terminate = TRUE;
#endif
if (cap_session->fork_child != WS_INVALID_PID) {
#ifndef _WIN32
int sts = kill(cap_session->fork_child, SIGINT);
if (sts != 0) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_WARNING,
"Sending SIGINT to child failed: %s\n", g_strerror(errno));
}
#else
#define STOP_SLEEP_TIME 500
#define STOP_CHECK_TIME 50
signal_pipe_capquit_to_child(cap_session);
for (count = 0; count < STOP_SLEEP_TIME / STOP_CHECK_TIME; count++) {
if (GetExitCodeProcess((HANDLE) cap_session->fork_child, &childstatus) &&
childstatus != STILL_ACTIVE) {
terminate = FALSE;
break;
}
Sleep(STOP_CHECK_TIME);
}
if (terminate) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_WARNING,
"sync_pipe_stop: forcing child to exit");
sync_pipe_kill(cap_session->fork_child);
}
#endif
}
}
void
sync_pipe_kill(ws_process_id fork_child)
{
if (fork_child != WS_INVALID_PID) {
#ifndef _WIN32
int sts = kill(fork_child, SIGTERM);
if (sts != 0) {
g_log(LOG_DOMAIN_CAPTURE_CHILD, G_LOG_LEVEL_WARNING,
"Sending SIGTERM to child failed: %s\n", g_strerror(errno));
}
#else
TerminateProcess((HANDLE) (fork_child), 0);
#endif
}
}
void capture_sync_set_fetch_dumpcap_pid_cb(void(*cb)(ws_process_id pid)) {
fetch_dumpcap_pid = cb;
}
