static socket_handle_t
socket_init(char *path)
{
socket_handle_t fd = INVALID_SOCKET;
#ifdef _WIN32
WSADATA wsaData;
int result;
result = WSAStartup(MAKEWORD(1, 1), &wsaData);
if (result != 0) {
g_warning("ERROR: WSAStartup failed with error: %d", result);
return INVALID_SOCKET;
}
#endif
#ifdef SHARKD_UNIX_SUPPORT
if (!strncmp(path, "unix:", 5))
{
struct sockaddr_un s_un;
socklen_t s_un_len;
path += 5;
if (strlen(path) + 1 > sizeof(s_un.sun_path))
return INVALID_SOCKET;
fd = socket(AF_UNIX, SOCK_STREAM, 0);
if (fd == INVALID_SOCKET)
return INVALID_SOCKET;
memset(&s_un, 0, sizeof(s_un));
s_un.sun_family = AF_UNIX;
g_strlcpy(s_un.sun_path, path, sizeof(s_un.sun_path));
s_un_len = (socklen_t)(offsetof(struct sockaddr_un, sun_path) + strlen(s_un.sun_path));
if (s_un.sun_path[0] == '@')
s_un.sun_path[0] = '\0';
if (bind(fd, (struct sockaddr *) &s_un, s_un_len))
{
closesocket(fd);
return INVALID_SOCKET;
}
}
else
#endif
#ifdef SHARKD_TCP_SUPPORT
if (!strncmp(path, "tcp:", 4))
{
struct sockaddr_in s_in;
int one = 1;
char *port_sep;
guint16 port;
path += 4;
port_sep = strchr(path, ':');
if (!port_sep)
return INVALID_SOCKET;
*port_sep = '\0';
if (ws_strtou16(port_sep + 1, NULL, &port) == FALSE)
return INVALID_SOCKET;
#ifdef _WIN32
fd = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, 0);
#else
fd = socket(AF_INET, SOCK_STREAM, 0);
#endif
if (fd == INVALID_SOCKET)
return INVALID_SOCKET;
s_in.sin_family = AF_INET;
s_in.sin_addr.s_addr = inet_addr(path);
s_in.sin_port = g_htons(port);
*port_sep = ':';
setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (void *) &one, sizeof(one));
if (bind(fd, (struct sockaddr *) &s_in, sizeof(struct sockaddr_in)))
{
closesocket(fd);
return INVALID_SOCKET;
}
}
else
#endif
{
return INVALID_SOCKET;
}
if (listen(fd, SOMAXCONN))
{
closesocket(fd);
return INVALID_SOCKET;
}
return fd;
}
int
sharkd_init(int argc, char **argv)
{
#ifndef _WIN32
pid_t pid;
#endif
socket_handle_t fd;
if (argc != 2)
{
fprintf(stderr, "Usage: %s <socket>\n", argv[0]);
fprintf(stderr, "\n");
fprintf(stderr, "<socket> examples:\n");
#ifdef SHARKD_UNIX_SUPPORT
fprintf(stderr, " - unix:/tmp/sharkd.sock - listen on unix file /tmp/sharkd.sock\n");
#endif
#ifdef SHARKD_TCP_SUPPORT
fprintf(stderr, " - tcp:127.0.0.1:4446 - listen on TCP port 4446\n");
#endif
fprintf(stderr, "\n");
return -1;
}
#ifndef _WIN32
signal(SIGCHLD, SIG_IGN);
#endif
if (!strcmp(argv[1], "-"))
{
_use_stdinout = 1;
}
else
{
fd = socket_init(argv[1]);
if (fd == INVALID_SOCKET)
return -1;
_server_fd = fd;
}
#ifndef _WIN32
pid = fork();
if (pid == -1)
fprintf(stderr, "cannot go to background fork() failed: %s\n", g_strerror(errno));
if (pid != 0)
{
exit(0);
}
#endif
return 0;
}
int
sharkd_loop(void)
{
if (_use_stdinout)
{
return sharkd_session_main();
}
while (1)
{
#ifndef _WIN32
pid_t pid;
#else
PROCESS_INFORMATION pi;
STARTUPINFO si;
char *exename;
gunichar2 *commandline;
#endif
socket_handle_t fd;
fd = accept(_server_fd, NULL, NULL);
if (fd == INVALID_SOCKET)
{
fprintf(stderr, "cannot accept(): %s\n", g_strerror(errno));
continue;
}
#ifndef _WIN32
pid = fork();
if (pid == 0)
{
dup2(fd, 0);
dup2(fd, 1);
close(fd);
exit(sharkd_session_main());
}
if (pid == -1)
{
fprintf(stderr, "cannot fork(): %s\n", g_strerror(errno));
}
#else
memset(&pi, 0, sizeof(pi));
memset(&si, 0, sizeof(si));
si.cb = sizeof(si);
si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
si.hStdInput = (HANDLE) fd;
si.hStdOutput = (HANDLE) fd;
si.hStdError = GetStdHandle(STD_ERROR_HANDLE);
exename = g_strdup_printf("%s\\%s", get_progfile_dir(), "sharkd.exe");
commandline = g_utf8_to_utf16("sharkd.exe -", -1, NULL, NULL, NULL);
if (!CreateProcess(utf_8to16(exename), commandline, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
{
fprintf(stderr, "CreateProcess(%s) failed\n", exename);
}
else
{
CloseHandle(pi.hThread);
}
g_free(exename);
g_free(commandline);
#endif
closesocket(fd);
}
return 0;
}
