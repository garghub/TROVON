char *
get_args_as_string(int argc, char **argv, int optindex)
{
int len;
int i;
char *argstring;
len = 0;
for (i = optindex; i < argc; i++) {
len += (int) strlen(argv[i]);
len++;
}
argstring = (char *)g_malloc(len);
argstring[0] = '\0';
i = optindex;
for (;;) {
g_strlcat(argstring, argv[i], len);
i++;
if (i == argc)
break;
g_strlcat(argstring, " ", len);
}
return argstring;
}
void
compute_timestamp_diff(gint *diffsec, gint *diffusec,
guint32 sec1, guint32 usec1, guint32 sec2, guint32 usec2)
{
if (sec1 == sec2) {
*diffsec = sec1 - sec2;
*diffusec = usec1 - usec2;
} else if (sec1 <= sec2) {
*diffsec = sec1 - sec2;
if (usec2 >= usec1) {
*diffusec = usec1 - usec2;
} else {
*diffusec = (usec1 - 1000000) - usec2;
(*diffsec)++;
}
} else {
*diffsec = sec1 - sec2;
if (usec2 <= usec1) {
*diffusec = usec1 - usec2;
} else {
*diffusec = (usec1 + 1000000) - usec2;
(*diffsec)--;
}
}
}
static char *sanitize_filter_ip(char *hostname) {
gchar *end;
gchar *ret;
ret = g_strdup(hostname);
if (!ret)
return NULL;
end = strchr(ret, '%');
if (end)
*end = '\0';
return ret;
}
const gchar *get_conn_cfilter(void) {
static GString *filter_str = NULL;
gchar *env, **tokens;
char *lastp, *lastc, *p;
char *pprotocol = NULL;
char *phostname = NULL;
size_t hostlen;
char *remip, *locip;
if (filter_str == NULL) {
filter_str = g_string_new("");
}
if ((env = getenv("SSH_CONNECTION")) != NULL) {
tokens = g_strsplit(env, " ", 4);
if (g_strv_length(tokens) == 4) {
remip = sanitize_filter_ip(tokens[0]);
locip = sanitize_filter_ip(tokens[2]);
g_string_printf(filter_str, "not (tcp port %s and host %s "
"and tcp port %s and host %s)", tokens[1], remip,
tokens[3], locip);
g_free(remip);
g_free(locip);
}
g_strfreev(tokens);
} else if ((env = getenv("SSH_CLIENT")) != NULL) {
tokens = g_strsplit(env, " ", 3);
if (g_strv_length(tokens) == 3) {
remip = sanitize_filter_ip(tokens[2]);
g_string_printf(filter_str, "not (tcp port %s and host %s "
"and tcp port %s)", tokens[1], tokens[0], remip);
g_free(remip);
}
g_strfreev(tokens);
} else if ((env = getenv("REMOTEHOST")) != NULL) {
if (g_ascii_strcasecmp(env, "localhost") == 0 ||
strcmp(env, "127.0.0.1") == 0 ||
strcmp(env, "") == 0) {
return "";
}
remip = sanitize_filter_ip(env);
g_string_printf(filter_str, "not host %s", remip);
g_free(remip);
} else if ((env = getenv("DISPLAY")) != NULL) {
p = env;
for (lastp = p; *p != '\0' && *p != ':' && *p != '/'; p++)
;
if (*p == '\0')
return "";
if (p != lastp && *p != ':') {
pprotocol = p;
if (p - lastp != 3 || g_ascii_strncasecmp(lastp, "tcp", 3) != 0)
return "";
p++;
} else
p = env;
lastp = p;
lastc = NULL;
for (; *p != '\0'; p++)
if (*p == ':')
lastc = p;
if (lastc == NULL)
return "";
if ((lastp != lastc) && (*(lastc - 1) == ':')
&& (((lastc - 1) == lastp) || (*(lastc - 2) != ':'))) {
return "";
} else
hostlen = lastc - lastp;
if (hostlen == 0)
return "";
phostname = (char *)g_malloc(hostlen + 1);
memcpy(phostname, lastp, hostlen);
phostname[hostlen] = '\0';
if (pprotocol == NULL) {
if (g_ascii_strcasecmp(phostname, "localhost") == 0 ||
strcmp(phostname, "127.0.0.1") == 0) {
g_free(phostname);
return "";
}
if (strcmp(phostname, "unix") == 0) {
g_free(phostname);
return "";
}
if (phostname[0] == '/') {
g_free(phostname);
return "";
}
}
g_string_printf(filter_str, "not host %s", phostname);
g_free(phostname);
#ifdef _WIN32
} else if (GetSystemMetrics(SM_REMOTESESSION)) {
g_string_printf(filter_str, "not port 3389");
#endif
} else {
return "";
}
return filter_str->str;
}
gboolean display_is_remote(void)
{
static gboolean remote_display_checked;
static gboolean is_remote;
if (!remote_display_checked) {
is_remote = (strlen(get_conn_cfilter()) > 0);
}
return is_remote;
}
