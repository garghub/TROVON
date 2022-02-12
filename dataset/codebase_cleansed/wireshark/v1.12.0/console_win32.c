static gboolean
needs_redirection(int std_handle)
{
HANDLE fd;
DWORD handle_type;
DWORD error;
fd = GetStdHandle(std_handle);
if (fd == NULL) {
return TRUE;
}
if (fd == INVALID_HANDLE_VALUE) {
return FALSE;
}
handle_type = GetFileType(fd);
if (handle_type == FILE_TYPE_UNKNOWN) {
error = GetLastError();
if (error == ERROR_INVALID_HANDLE) {
return TRUE;
}
}
return FALSE;
}
void
create_console(void)
{
gboolean must_redirect_stdin;
gboolean must_redirect_stdout;
gboolean must_redirect_stderr;
if (stdin_capture) {
return;
}
if (!has_console) {
must_redirect_stdin = needs_redirection(STD_INPUT_HANDLE);
must_redirect_stdout = needs_redirection(STD_OUTPUT_HANDLE);
must_redirect_stderr = needs_redirection(STD_ERROR_HANDLE);
if (!must_redirect_stdin && !must_redirect_stdout && !must_redirect_stderr)
return;
if (!AttachConsole(ATTACH_PARENT_PROCESS)) {
FreeConsole();
if (AllocConsole()) {
console_wait = TRUE;
SetConsoleTitle(_T("Wireshark Debug Console"));
} else {
return;
}
}
if (must_redirect_stdin)
ws_freopen("CONIN$", "r", stdin);
if (must_redirect_stdout) {
ws_freopen("CONOUT$", "w", stdout);
fprintf(stdout, "\n");
}
if (must_redirect_stderr) {
ws_freopen("CONOUT$", "w", stderr);
fprintf(stderr, "\n");
}
atexit(destroy_console);
has_console = TRUE;
}
}
void
destroy_console(void)
{
if (console_wait) {
printf("\n\nPress any key to exit\n");
_getch();
}
FreeConsole();
}
void
set_console_wait(gboolean set_console_wait)
{
console_wait = set_console_wait;
}
gboolean
get_console_wait(void)
{
return console_wait;
}
void
set_has_console(gboolean set_has_console)
{
has_console = has_console;
}
gboolean
get_has_console(void)
{
return has_console;
}
void
set_stdin_capture(gboolean set_stdin_capture)
{
stdin_capture = set_stdin_capture;
}
gboolean
get_stdin_capture(void)
{
return stdin_capture;
}
