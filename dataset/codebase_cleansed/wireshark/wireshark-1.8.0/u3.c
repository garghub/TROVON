gboolean u3_active(void)
{
return (
#ifdef _WIN32
getenv_utf8
#else
getenv
#endif
("U3_HOST_EXEC_PATH") != NULL);
}
void u3_runtime_info(GString *str)
{
char *u3devicepath_lcl = NULL;
char *u3deviceproduct = NULL;
if((u3deviceproduct =
#ifdef _WIN32
getenv_utf8
#else
getenv
#endif
("U3_DEVICE_PRODUCT")) != NULL) {
g_string_append(str, " from the ");
g_string_append(str, u3deviceproduct);
} else {
g_string_append(str, " from a ");
}
g_string_append(str, " U3 device");
if((u3devicepath_lcl =
#ifdef _WIN32
getenv_utf8
#else
getenv
#endif
("U3_DEVICE_PATH")) != NULL) {
g_string_append(str, " in drive ");
g_string_append(str, u3devicepath_lcl);
}
}
void u3_register_pid(void)
{
int pid;
int pid_fd;
char *u3hostexecpath;
int pf_size;
if((u3hostexecpath =
#ifdef _WIN32
getenv_utf8
#else
getenv
#endif
("U3_HOST_EXEC_PATH")) != NULL) {
pid = getpid();
pf_size = (int) strlen(u3hostexecpath) + 32;
pid_file = g_malloc(pf_size);
g_snprintf(pid_file, pf_size, "%s\\%d.pid", u3hostexecpath, pid);
pid_fd = ws_open(pid_file, O_WRONLY | O_CREAT | O_TRUNC | O_BINARY, 0644);
if(pid_fd != -1)
ws_close(pid_fd);
else {
g_free(pid_file);
pid_file = NULL;
}
}
}
void u3_deregister_pid(void)
{
if(pid_file) {
ws_unlink(pid_file);
g_free(pid_file);
pid_file = NULL;
}
}
char *u3_expand_device_path(char *path)
{
return u3_change_path(path, U3_DEVICE_PATH_VAR, NULL);
}
char *u3_contract_device_path(char *path)
{
return u3_change_path(path, NULL, U3_DEVICE_PATH_VAR);
}
static char *u3_change_path(char *path, const char *old, const char *new)
{
if(u3devicepath == (char*)-1) {
u3devicepath =
#ifdef _WIN32
getenv_utf8
#else
getenv
#endif
("U3_DEVICE_PATH");
}
if(new == NULL)
new = u3devicepath;
if(old == NULL)
old = u3devicepath;
if(newpath != NULL) {
g_free(newpath);
newpath = NULL;
}
if((path != NULL) && (u3devicepath != NULL) && (strncmp(path, old, strlen(old)) == 0)) {
newpath = g_strconcat(new, path + strlen(old), NULL);
return newpath;
}
return path;
}
