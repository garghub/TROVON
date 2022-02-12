DWORD TerminateApp( DWORD dwPID, DWORD dwTimeout )
{
HANDLE hProc ;
DWORD dwRet ;
hProc = OpenProcess(SYNCHRONIZE|PROCESS_TERMINATE, FALSE, dwPID);
if(hProc == NULL){
return TA_FAILED;
}
if(dwTimeout) {
EnumWindows((WNDENUMPROC)TerminateAppEnum, (LPARAM) dwPID) ;
if(WaitForSingleObject(hProc, dwTimeout)!=WAIT_OBJECT_0)
dwRet=(TerminateProcess(hProc,0)?TA_SUCCESS_KILL:TA_FAILED);
else
dwRet = TA_SUCCESS_CLEAN ;
} else {
dwRet=(TerminateProcess(hProc,0)?TA_SUCCESS_KILL:TA_FAILED);
}
CloseHandle(hProc) ;
return dwRet ;
}
DWORD Terminate16App( DWORD dwPID, DWORD dwThread, WORD w16Task, DWORD dwTimeout )
{
HINSTANCE hInstLib ;
TERMINFO info ;
BOOL (WINAPI *lpfVDMTerminateTaskWOW)(DWORD dwProcessId, WORD htask) ;
hInstLib = LoadLibraryA( "VDMDBG.DLL" ) ;
if( hInstLib == NULL )
return TA_FAILED ;
lpfVDMTerminateTaskWOW = (BOOL (WINAPI *)(DWORD, WORD ))
GetProcAddress( hInstLib, "VDMTerminateTaskWOW" ) ;
if( lpfVDMTerminateTaskWOW == NULL )
{
FreeLibrary( hInstLib ) ;
return TA_FAILED ;
}
info.dwID = dwPID ;
info.dwThread = dwThread ;
EnumWindows((WNDENUMPROC)Terminate16AppEnum, (LPARAM) &info) ;
Sleep( dwTimeout ) ;
lpfVDMTerminateTaskWOW(dwPID, w16Task) ;
FreeLibrary( hInstLib ) ;
return TA_SUCCESS_16 ;
}
BOOL CALLBACK TerminateAppEnum( HWND hwnd, LPARAM lParam )
{
DWORD dwID ;
GetWindowThreadProcessId(hwnd, &dwID) ;
if(dwID == (DWORD)lParam)
{
PostMessage(hwnd, WM_CLOSE, 0, 0) ;
}
return TRUE ;
}
BOOL CALLBACK Terminate16AppEnum( HWND hwnd, LPARAM lParam )
{
DWORD dwID ;
DWORD dwThread ;
TERMINFO *termInfo ;
termInfo = (TERMINFO *)lParam ;
dwThread = GetWindowThreadProcessId(hwnd, &dwID) ;
if(dwID == termInfo->dwID && termInfo->dwThread == dwThread )
{
PostMessage(hwnd, WM_CLOSE, 0, 0) ;
}
return TRUE ;
}
void ExecuteAndWait(char *buffer)
{
STARTUPINFO si;
PROCESS_INFORMATION pi;
SecureZeroMemory(&si, sizeof(si));
si.cb = sizeof(si);
SecureZeroMemory(&pi, sizeof(pi));
if(CreateProcess(NULL, buffer, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
(void) WaitForSingleObject(pi.hProcess, INFINITE);
(void)CloseHandle(pi.hProcess);
(void)CloseHandle(pi.hThread);
}
}
void uninstall(char *regkey, char *u3installed, char *uninstall)
{
char buffer[BUFSIZ];
int buflen = BUFSIZ;
char *u3_device_serial;
char reg_key[BUFSIZ];
HKEY key;
buffer[0] = '\0';
if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, regkey, 0, (KEY_READ | KEY_WRITE), &key) == ERROR_SUCCESS) {
buflen = BUFSIZ;
if(RegQueryValueEx(key, u3installed, NULL, NULL, buffer, &buflen) == ERROR_SUCCESS) {
u3_device_serial = getenv("U3_DEVICE_SERIAL");
if(!strncmp(buffer, u3_device_serial, strlen(u3_device_serial) + 1)) {
buffer[0] = '"';
buflen = BUFSIZ-1;
(void) RegQueryValueEx(key, uninstall, NULL, NULL, &buffer[1], &buflen);
if(!strncmp(buffer, "\"MsiExec.exe", 12)) {
strncat(buffer, " /qn", 5);
}
strncat(buffer, "\"", 2);
RegDeleteValue(key, u3installed);
} else {
buffer[0] = '\0';
}
}
RegCloseKey(key);
}
if(*buffer) {
#if 0
MessageBox(NULL,
buffer,
"Uninstall",
MB_YESNO|MB_TOPMOST|MB_ICONQUESTION);
#endif
ExecuteAndWait(buffer);
}
}
void winpcap_auto_start()
{
HKEY key;
HKEY npfKey;
char buffer[BUFSIZ+1];
int buflen = 0;
DWORD startVal = NPF_START_VAL;
if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, WINDOWS_VERSION_KEY, 0, (KEY_READ), &key) == ERROR_SUCCESS) {
if(RegQueryValueEx(key, WINDOWS_VERSION, NULL, NULL, buffer, &buflen) == ERROR_SUCCESS) {
if(!strcmp(buffer, VISTA_VERSION)) {
if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, NPF_KEY, 0, (KEY_READ | KEY_WRITE), &npfKey) == ERROR_SUCCESS) {
(void)RegSetValueEx(npfKey, NPF_START, 0, REG_DWORD, (BYTE*)&startVal, sizeof(DWORD));
RegCloseKey(npfKey);
}
}
}
RegCloseKey(key);
}
}
void app_start(int argc, char *argv[])
{
char *u3hostexecpath;
char *envvar;
char *end;
char buffer[BUFSIZ+1];
char inBuffer[FILEBUFSIZ+1];
HANDLE *file;
DWORD numRead = 0;
int i;
buffer[0] = '\0';
strncat(buffer, argv[0], strlen(argv[0]) + 1);
if(end = strrchr(buffer, '\\'))
*end = '\0';
strncat(buffer, ENV_FILENAME, strlen(ENV_FILENAME) + 1);
if((file = CreateFile(buffer, FILE_READ_DATA, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL)) != INVALID_HANDLE_VALUE) {
if(ReadFile(file, &inBuffer, FILEBUFSIZ, &numRead, NULL) != 0) {
inBuffer[numRead] = '\0';
envvar = inBuffer;
while(end = strchr(envvar, '\n')) {
*end++ = '\0';
_putenv(envvar);
envvar = end;
}
}
CloseHandle(file);
}
if((u3hostexecpath = getenv("U3_HOST_EXEC_PATH")) != NULL) {
buffer[0] = '\0';
strncat(buffer, u3hostexecpath, strlen(u3hostexecpath) + 1);
strncat(buffer, WIRESHARK_EXE, strlen(WIRESHARK_EXE) + 1);
for(i = 2; i < argc; i++) {
strncat(buffer, " ", 2);
strncat(buffer, argv[i], strlen(argv[i]) + 1);
}
ExecuteAndWait(buffer);
}
}
void app_stop(DWORD timeOut)
{
DWORD pid = 0;
HANDLE hFind = INVALID_HANDLE_VALUE;
WIN32_FIND_DATA find_file_data;
DWORD dwError;
char *u3_host_exec_path;
char dir_spec[MAX_PATH+1];
char file_name[MAX_PATH+1];
u3_host_exec_path = getenv("U3_HOST_EXEC_PATH");
strncpy(dir_spec, u3_host_exec_path, strlen(u3_host_exec_path) + 1);
strncat(dir_spec, "\\*.pid", 7);
hFind = FindFirstFile(dir_spec, &find_file_data);
if(hFind != INVALID_HANDLE_VALUE) {
do {
pid = (DWORD)atoi(find_file_data.cFileName);
if(pid)
TerminateApp(pid, timeOut);
strncpy(file_name, u3_host_exec_path, strlen(u3_host_exec_path) + 1);
strncat(file_name, "\\", 2);
strncat(file_name, find_file_data.cFileName, strlen(find_file_data.cFileName) + 1);
DeleteFile(TEXT(file_name));
} while(FindNextFile(hFind, &find_file_data) != 0);
FindClose(hFind);
}
}
void associate(char *extension)
{
HKEY key;
DWORD disposition;
char buffer[BUFSIZ];
int buflen = BUFSIZ;
buffer[0] = '\0';
if(RegCreateKeyEx(HKEY_CLASSES_ROOT, extension, 0, NULL, 0, (KEY_READ | KEY_WRITE), NULL, &key, &disposition) == ERROR_SUCCESS) {
if((RegQueryValueEx(key, "", NULL, NULL, buffer, &buflen) != ERROR_SUCCESS) || (buffer[0] == '\0')) {
(void)RegSetValueEx(key, "", 0, REG_SZ, WIRESHARK_ASSOC, strlen(WIRESHARK_ASSOC) + 1);
}
RegCloseKey(key);
}
}
BOOL save_environment()
{
char **envptr;
char *envval;
HANDLE *file;
char buffer[BUFSIZ+1];
DWORD buflen;
DWORD numWritten;
BOOL retval = FALSE;
envval = getenv("U3_HOST_EXEC_PATH");
buffer[0] = '\0';
strncat(buffer, envval, strlen(envval) + 1);
strncat(buffer, ENV_FILENAME, strlen(ENV_FILENAME) + 1);
if((file = CreateFile(buffer, FILE_WRITE_DATA, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL)) != INVALID_HANDLE_VALUE) {
for(envptr = environmentvars; *envptr; envptr++) {
if(envval = getenv(*envptr)) {
buffer[0] = '\0';
strncat(buffer, *envptr, strlen(*envptr) + 1);
strncat(buffer, "=", 2);
strncat(buffer, envval, strlen(envval) + 1);
strncat(buffer, "\n", 2);
buflen = strlen(buffer);
WriteFile(file, buffer, buflen, &numWritten, NULL);
}
}
CloseHandle(file);
retval = TRUE;
}
return retval;
}
void disassociate(char *extension)
{
HKEY key;
DWORD disposition;
char buffer[BUFSIZ];
int buflen = BUFSIZ;
boolean delete_key = FALSE;
buffer[0] = '\0';
if(RegOpenKeyEx(HKEY_CLASSES_ROOT, extension, 0, (KEY_READ | KEY_WRITE), &key) == ERROR_SUCCESS) {
if(RegQueryValueEx(key, "", NULL, NULL, buffer, &buflen) == ERROR_SUCCESS) {
if(!strncmp(buffer, WIRESHARK_ASSOC, strlen(WIRESHARK_ASSOC) + 1))
delete_key = TRUE;
}
RegCloseKey(key);
}
if(delete_key)
RegDeleteKey(HKEY_CLASSES_ROOT, extension);
}
void host_configure(void)
{
char **pext;
HKEY key;
DWORD disposition;
char *u3_host_exec_path;
char *u3_device_exec_path;
char *u3_device_serial;
char *u3_device_document_path;
char wireshark_path[MAX_PATH+1];
char winpcap_path[MAX_PATH+1];
char vcredist_path[MAX_PATH+1];
char my_captures_path[MAX_PATH+1];
char reg_key[BUFSIZ];
char buffer[BUFSIZ];
int buflen = BUFSIZ;
boolean hasWinPcap = FALSE;
boolean hasRedist = FALSE;
if(RegCreateKeyEx(HKEY_CLASSES_ROOT, WIRESHARK_ASSOC, 0, NULL, 0,
(KEY_READ | KEY_WRITE), NULL, &key, &disposition) == ERROR_SUCCESS) {
(void)RegSetValueEx(key, "", 0, REG_SZ, WIRESHARK_DESC, strlen(WIRESHARK_DESC) + 1);
RegCloseKey(key);
}
u3_host_exec_path = getenv("U3_HOST_EXEC_PATH");
strncpy(wireshark_path, u3_host_exec_path, strlen(u3_host_exec_path) + 1);
strncat(wireshark_path, U3UTIL_APPSTART, strlen(U3UTIL_APPSTART) + 1);
strncpy(reg_key, WIRESHARK_ASSOC, strlen(WIRESHARK_ASSOC) + 1);
strncat(reg_key, SHELL_OPEN_COMMAND, strlen(SHELL_OPEN_COMMAND) + 1);
if(RegCreateKeyEx(HKEY_CLASSES_ROOT, reg_key, 0, NULL, 0,
(KEY_READ | KEY_WRITE), NULL, &key, &disposition) == ERROR_SUCCESS) {
(void)RegSetValueEx(key, "", 0, REG_SZ, wireshark_path, strlen(wireshark_path) + 1);
RegCloseKey(key);
}
strncpy(reg_key, WIRESHARK_ASSOC, strlen(WIRESHARK_ASSOC) + 1);
strncat(reg_key, DEFAULT_ICON, strlen(DEFAULT_ICON) + 1);
strncpy(wireshark_path, u3_host_exec_path, strlen(u3_host_exec_path) + 1);
strncat(wireshark_path, WIRESHARK_EXE, strlen(WIRESHARK_EXE) + 1);
strncat(wireshark_path, ",1", 3);
if(RegCreateKeyEx(HKEY_CLASSES_ROOT, reg_key, 0, NULL, 0,
(KEY_READ | KEY_WRITE), NULL, &key, &disposition) == ERROR_SUCCESS) {
(void)RegSetValueEx(key, "", 0, REG_SZ, wireshark_path, strlen(wireshark_path) + 1);
RegCloseKey(key);
}
for(pext = extensions; *pext; pext++)
associate(*pext);
SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, 0, 0);
if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, WINPCAP_KEY, 0, (KEY_READ), &key) == ERROR_SUCCESS) {
if(RegQueryValueEx(key, WINPCAP_UNINSTALL, NULL, NULL, buffer, &buflen) == ERROR_SUCCESS) {
if(buffer[0] != '\0')
hasWinPcap = TRUE;
}
RegCloseKey(key);
}
if(!hasWinPcap &&
(MessageBox(NULL,
TEXT("If you want to capture packets from the network you will need to install WinPcap.\nIt will be uninstalled when you remove your U3 device.\n\nDo you want to install WinPcap?"),
TEXT("U3 Wireshark: Install WinPcap?"),
MB_YESNO|MB_TOPMOST|MB_ICONQUESTION) == IDYES)) {
u3_device_exec_path = getenv("U3_DEVICE_EXEC_PATH");
strncpy(winpcap_path, "\"", 2);
strncat(winpcap_path, u3_device_exec_path, strlen(u3_device_exec_path) + 1);
strncat(winpcap_path, WINPCAP_PACKAGE, strlen(WINPCAP_PACKAGE) + 1);
strncat(winpcap_path, "\"", 2);
ExecuteAndWait(winpcap_path);
if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, WINPCAP_KEY, 0, (KEY_READ | KEY_WRITE), &key) == ERROR_SUCCESS) {
u3_device_serial = getenv("U3_DEVICE_SERIAL");
(void)RegSetValueEx(key, WINPCAP_U3INSTALLED, 0, REG_SZ, u3_device_serial, strlen(u3_device_serial) + 1);
winpcap_auto_start();
}
}
if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, VCREDIST_KEY, 0, (KEY_READ), &key) == ERROR_SUCCESS) {
buflen = BUFSIZ;
if(RegQueryValueEx(key, VCREDIST_UNINSTALL, NULL, NULL, buffer, &buflen) == ERROR_SUCCESS) {
if(buffer[0] != '\0')
hasRedist = TRUE;
}
RegCloseKey(key);
}
if(!hasRedist) {
u3_device_exec_path = getenv("U3_DEVICE_EXEC_PATH");
strncpy(vcredist_path, "\"", 2);
strncat(vcredist_path, u3_device_exec_path, strlen(u3_device_exec_path) + 1);
strncat(vcredist_path, VCREDIST_PACKAGE, strlen(VCREDIST_PACKAGE) + 1);
strncat(vcredist_path, "\" /q", 5);
ExecuteAndWait(vcredist_path);
if(RegOpenKeyEx(HKEY_LOCAL_MACHINE, VCREDIST_KEY, 0, (KEY_READ | KEY_WRITE), &key) == ERROR_SUCCESS) {
u3_device_serial = getenv("U3_DEVICE_SERIAL");
(void)RegSetValueEx(key, VCREDIST_U3INSTALLED, 0, REG_SZ, u3_device_serial, strlen(u3_device_serial) + 1);
}
}
u3_device_document_path = getenv("U3_DEVICE_DOCUMENT_PATH");
strncpy(my_captures_path, u3_device_document_path, strlen(u3_device_document_path) + 1);
strncat(my_captures_path, MY_CAPTURES, strlen(MY_CAPTURES) + 1);
(void) CreateDirectory(my_captures_path, NULL);
save_environment();
}
void host_clean_up(void)
{
DWORD disposition;
char **pext;
char *u3_device_serial;
char reg_key[BUFSIZ];
app_stop(0);
for(pext = extensions; *pext; pext++)
disassociate(*pext);
SHChangeNotify(SHCNE_ASSOCCHANGED, SHCNF_IDLIST, 0, 0);
strncpy(reg_key, WIRESHARK_ASSOC, strlen(WIRESHARK_ASSOC) + 1);
strncat(reg_key, SHELL_OPEN_COMMAND, strlen(SHELL_OPEN_COMMAND) + 1);
RegDeleteKey(HKEY_CLASSES_ROOT, reg_key);
strncpy(reg_key, WIRESHARK_ASSOC, strlen(WIRESHARK_ASSOC) + 1);
strncat(reg_key, SHELL_OPEN, strlen(SHELL_OPEN) + 1);
RegDeleteKey(HKEY_CLASSES_ROOT, reg_key);
strncpy(reg_key, WIRESHARK_ASSOC, strlen(WIRESHARK_ASSOC) + 1);
strncat(reg_key, SHELL, strlen(SHELL) + 1);
RegDeleteKey(HKEY_CLASSES_ROOT, reg_key);
strncpy(reg_key, WIRESHARK_ASSOC, strlen(WIRESHARK_ASSOC) + 1);
strncat(reg_key, DEFAULT_ICON, strlen(DEFAULT_ICON) + 1);
RegDeleteKey(HKEY_CLASSES_ROOT, reg_key);
RegDeleteKey(HKEY_CLASSES_ROOT, WIRESHARK_ASSOC);
uninstall(WINPCAP_KEY, WINPCAP_U3INSTALLED, WINPCAP_UNINSTALL);
uninstall(VCREDIST_KEY, VCREDIST_U3INSTALLED, VCREDIST_UNINSTALL);
}
main(int argc, char *argv[])
{
DWORD time_out = 0;
char *u3_is_device_available;
#if 0
char **envptr;
char *envval;
# endif
u3_is_device_available = getenv("U3_IS_DEVICE_AVAILABLE");
if(u3_is_device_available && !strncmp(u3_is_device_available, "true", 4))
time_out = INFINITE;
#if 0
for(envptr = environmentvars; *envptr; envptr++) {
envval = getenv(*envptr);
MessageBox(NULL,
envval ? envval : "NULL",
*envptr,
MB_YESNO|MB_TOPMOST|MB_ICONQUESTION);
}
#endif
if(argc > 1) {
if(!strncmp(argv[1], "hostConfigure", 13))
host_configure();
else if(!strncmp(argv[1], "appStart", 9))
app_start(argc, argv);
else if(!strncmp(argv[1], "appStop", 8))
app_stop(time_out);
else if(!strncmp(argv[1], "hostCleanUp", 11))
host_clean_up();
}
exit(0);
}
