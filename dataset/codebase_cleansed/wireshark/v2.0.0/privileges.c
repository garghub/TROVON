void
init_process_policies(void)
{
HMODULE kernel32Handle;
typedef BOOL (WINAPI *SetProcessDEPPolicyHandler)(DWORD);
SetProcessDEPPolicyHandler PSetProcessDEPPolicy;
#ifndef PROCESS_DEP_ENABLE
#define PROCESS_DEP_ENABLE 1
#endif
kernel32Handle = GetModuleHandle(_T("kernel32.dll"));
if (kernel32Handle != NULL) {
PSetProcessDEPPolicy = (SetProcessDEPPolicyHandler) GetProcAddress(kernel32Handle, "SetProcessDEPPolicy");
if (PSetProcessDEPPolicy) {
PSetProcessDEPPolicy(PROCESS_DEP_ENABLE);
}
}
npf_sys_is_running();
}
gboolean
started_with_special_privs(void)
{
return FALSE;
}
gboolean
running_with_special_privs(void)
{
return FALSE;
}
void
relinquish_special_privs_perm(void)
{
}
gchar *
get_cur_username(void) {
gchar *username;
username = g_strdup("UNKNOWN");
return username;
}
gchar *
get_cur_groupname(void) {
gchar *groupname;
groupname = g_strdup("UNKNOWN");
return groupname;
}
gboolean
npf_sys_is_running() {
SC_HANDLE h_scm, h_serv;
SERVICE_STATUS ss;
h_scm = OpenSCManager(NULL, NULL, 0);
if (!h_scm)
return FALSE;
h_serv = OpenService(h_scm, _T("npf"), SC_MANAGER_CONNECT|SERVICE_QUERY_STATUS);
if (!h_serv)
return FALSE;
if (QueryServiceStatus(h_serv, &ss)) {
if (ss.dwCurrentState & SERVICE_RUNNING)
return TRUE;
}
return FALSE;
}
void
init_process_policies(void)
{
ruid = getuid();
euid = geteuid();
rgid = getgid();
egid = getegid();
init_process_policies_called = TRUE;
}
gboolean
started_with_special_privs(void)
{
g_assert(init_process_policies_called);
#ifdef HAVE_ISSETUGID
return issetugid();
#else
return (ruid != euid || rgid != egid || ruid == 0 || rgid == 0);
#endif
}
gboolean
running_with_special_privs(void)
{
#ifdef HAVE_SETRESUID
uid_t ru, eu, su;
#endif
#ifdef HAVE_SETRESGID
gid_t rg, eg, sg;
#endif
#ifdef HAVE_SETRESUID
getresuid(&ru, &eu, &su);
if (ru == 0 || eu == 0 || su == 0)
return TRUE;
#else
if (getuid() == 0 || geteuid() == 0)
return TRUE;
#endif
#ifdef HAVE_SETRESGID
getresgid(&rg, &eg, &sg);
if (rg == 0 || eg == 0 || sg == 0)
return TRUE;
#else
if (getgid() == 0 || getegid() == 0)
return TRUE;
#endif
return FALSE;
}
static void
setxid_fail(const gchar *str)
{
g_error("Attempt to relinguish privileges failed [%s()] - aborting: %s\n",
str, g_strerror(errno));
}
void
relinquish_special_privs_perm(void)
{
if (started_with_special_privs()) {
#ifdef HAVE_SETRESGID
if (setresgid(rgid, rgid, rgid) == -1) {setxid_fail("setresgid");}
#else
if (setgid(rgid) == -1) {setxid_fail("setgid"); }
if (setegid(rgid) == -1) {setxid_fail("setegid");}
#endif
#ifdef HAVE_SETRESUID
if (setresuid(ruid, ruid, ruid) == -1) {setxid_fail("setresuid");}
#else
if (setuid(ruid) == -1) {setxid_fail("setuid"); }
if (seteuid(ruid) == -1) {setxid_fail("seteuid");}
#endif
}
}
gchar *
get_cur_username(void) {
gchar *username;
struct passwd *pw = getpwuid(getuid());
if (pw) {
username = g_strdup(pw->pw_name);
} else {
username = g_strdup("UNKNOWN");
}
endpwent();
return username;
}
gchar *
get_cur_groupname(void) {
gchar *groupname;
struct group *gr = getgrgid(getgid());
if (gr) {
groupname = g_strdup(gr->gr_name);
} else {
groupname = g_strdup("UNKNOWN");
}
endgrent();
return groupname;
}
