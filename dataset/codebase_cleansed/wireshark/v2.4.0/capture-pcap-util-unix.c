GList *
get_remote_interface_list(const char *hostname, const char *port,
int auth_type, const char *username,
const char *passwd, int *err, char **err_str)
{
struct pcap_rmtauth auth;
char source[PCAP_BUF_SIZE];
char errbuf[PCAP_ERRBUF_SIZE];
GList *result;
if (pcap_createsrcstr(source, PCAP_SRC_IFREMOTE, hostname, port,
NULL, errbuf) == -1) {
*err = CANT_GET_INTERFACE_LIST;
if (err_str != NULL)
*err_str = cant_get_if_list_error_message(errbuf);
return NULL;
}
auth.type = auth_type;
auth.username = g_strdup(username);
auth.password = g_strdup(passwd);
result = get_interface_list_findalldevs_ex(source, &auth, err, err_str);
g_free(auth.username);
g_free(auth.password);
return result;
}
GList *
get_interface_list(int *err, char **err_str)
{
return get_interface_list_findalldevs(err, err_str);
}
static void
search_for_if_cb(gpointer data, gpointer user_data)
{
struct search_user_data *search_user_data = (struct search_user_data*)user_data;
if_info_t *if_info = (if_info_t *)data;
if (strcmp(if_info->name, search_user_data->name) == 0)
search_user_data->if_info = if_info;
}
GList *
get_interface_list(int *err, char **err_str)
{
GList *il = NULL;
gint nonloopback_pos = 0;
struct ifreq *ifr, *last;
struct ifconf ifc;
struct ifreq ifrflags;
int sock = socket(AF_INET, SOCK_DGRAM, 0);
struct search_user_data user_data;
pcap_t *pch;
int len, lastlen;
char *buf;
if_info_t *if_info;
char errbuf[PCAP_ERRBUF_SIZE];
gboolean loopback;
if (sock < 0) {
*err = CANT_GET_INTERFACE_LIST;
if (err_str != NULL) {
*err_str = g_strdup_printf(
"Can't get list of interfaces: error opening socket: %s",
g_strerror(errno));
}
return NULL;
}
lastlen = 0;
len = 100 * sizeof(struct ifreq);
for ( ; ; ) {
buf = (char *)g_malloc0(len);
ifc.ifc_len = len;
ifc.ifc_buf = buf;
if (ioctl(sock, SIOCGIFCONF, &ifc) < 0) {
if (errno != EINVAL || lastlen != 0) {
if (err_str != NULL) {
*err_str = g_strdup_printf(
"Can't get list of interfaces: SIOCGIFCONF ioctl error: %s",
g_strerror(errno));
}
goto fail;
}
} else {
if ((unsigned int) ifc.ifc_len < sizeof(struct ifreq)) {
if (err_str != NULL) {
*err_str = g_strdup(
"Can't get list of interfaces: SIOCGIFCONF ioctl gave too small return buffer");
}
goto fail;
}
if (ifc.ifc_len == lastlen)
break;
lastlen = ifc.ifc_len;
}
len += 10 * sizeof(struct ifreq);
g_free(buf);
}
ifr = (struct ifreq *) ifc.ifc_req;
last = (struct ifreq *) ((char *) ifr + ifc.ifc_len);
while (ifr < last) {
if (strncmp(ifr->ifr_name, "dummy", 5) == 0 ||
strchr(ifr->ifr_name, ':') != NULL)
goto next;
user_data.name = ifr->ifr_name;
user_data.if_info = NULL;
g_list_foreach(il, search_for_if_cb, &user_data);
if (user_data.if_info != NULL) {
if_info_add_address(user_data.if_info, &ifr->ifr_addr);
if (user_data.if_info->addrs) {
g_slist_reverse(user_data.if_info->addrs);
}
goto next;
}
memset(&ifrflags, 0, sizeof ifrflags);
g_strlcpy(ifrflags.ifr_name, ifr->ifr_name,
sizeof ifrflags.ifr_name);
if (ioctl(sock, SIOCGIFFLAGS, (char *)&ifrflags) < 0) {
if (errno == ENXIO)
goto next;
if (err_str != NULL) {
*err_str = g_strdup_printf(
"Can't get list of interfaces: SIOCGIFFLAGS error getting flags for interface %s: %s",
ifr->ifr_name, g_strerror(errno));
}
goto fail;
}
if (!(ifrflags.ifr_flags & IFF_UP))
goto next;
pch = pcap_open_live(ifr->ifr_name, MIN_PACKET_SIZE, 0, 0,
errbuf);
if (pch == NULL)
goto next;
pcap_close(pch);
loopback = ((ifrflags.ifr_flags & IFF_LOOPBACK) ||
strncmp(ifr->ifr_name, "lo", 2) == 0);
if_info = if_info_new(ifr->ifr_name, NULL, loopback);
if_info_add_address(if_info, &ifr->ifr_addr);
if (if_info->addrs) {
g_slist_reverse(if_info->addrs);
}
if (loopback)
il = g_list_append(il, if_info);
else {
il = g_list_insert(il, if_info, nonloopback_pos);
nonloopback_pos++;
}
next:
#ifdef HAVE_STRUCT_SOCKADDR_SA_LEN
ifr = (struct ifreq *) ((char *) ifr +
(ifr->ifr_addr.sa_len > sizeof(ifr->ifr_addr) ?
ifr->ifr_addr.sa_len : sizeof(ifr->ifr_addr)) +
IFNAMSIZ);
#else
ifr = (struct ifreq *) ((char *) ifr + sizeof(struct ifreq));
#endif
}
#ifdef linux
pch = pcap_open_live("any", MIN_PACKET_SIZE, 0, 0, errbuf);
if (pch != NULL) {
if_info = if_info_new("any",
"Pseudo-device that captures on all interfaces", FALSE);
il = g_list_insert(il, if_info, -1);
pcap_close(pch);
}
#endif
g_free(ifc.ifc_buf);
close(sock);
if (il == NULL) {
*err = 0;
if (err_str != NULL)
*err_str = NULL;
}
return il;
fail:
if (il != NULL)
free_interface_list(il);
g_free(ifc.ifc_buf);
close(sock);
*err = CANT_GET_INTERFACE_LIST;
return NULL;
}
gchar *
cant_get_if_list_error_message(const char *err_str)
{
return g_strdup_printf("Can't get list of interfaces: %s", err_str);
}
void
request_high_resolution_timestamp(pcap_t *pcap_h)
{
#ifdef __APPLE__
static gboolean initialized = FALSE;
static int (*p_pcap_set_tstamp_precision)(pcap_t *, int);
if (!initialized) {
p_pcap_set_tstamp_precision =
(int (*)(pcap_t *, int))
dlsym(RTLD_NEXT, "pcap_set_tstamp_precision");
initialized = TRUE;
}
if (p_pcap_set_tstamp_precision != NULL)
(*p_pcap_set_tstamp_precision)(pcap_h, PCAP_TSTAMP_PRECISION_NANO);
#else
pcap_set_tstamp_precision(pcap_h, PCAP_TSTAMP_PRECISION_NANO);
#endif
}
gboolean
have_high_resolution_timestamp(pcap_t *pcap_h)
{
#ifdef __APPLE__
static gboolean initialized = FALSE;
static int (*p_pcap_get_tstamp_precision)(pcap_t *);
if (!initialized) {
p_pcap_get_tstamp_precision =
(int (*)(pcap_t *))
dlsym(RTLD_NEXT, "pcap_get_tstamp_precision");
initialized = TRUE;
}
if (p_pcap_get_tstamp_precision != NULL)
return (*p_pcap_get_tstamp_precision)(pcap_h) == PCAP_TSTAMP_PRECISION_NANO;
else
return FALSE;
#else
return pcap_get_tstamp_precision(pcap_h) == PCAP_TSTAMP_PRECISION_NANO;
#endif
}
if_capabilities_t *
get_if_capabilities_local(interface_options *interface_opts, char **err_str)
{
#ifdef HAVE_PCAP_CREATE
return get_if_capabilities_pcap_create(interface_opts, err_str);
#else
return get_if_capabilities_pcap_open_live(interface_opts, err_str);
#endif
}
void
get_compiled_caplibs_version(GString *str)
{
g_string_append(str, "with libpcap");
#ifdef HAVE_PCAP_REMOTE
g_string_append(str, " (including remote capture support)");
#endif
g_string_append(str, ", ");
#ifdef HAVE_LIBCAP
g_string_append(str, "with POSIX capabilities");
#ifdef _LINUX_CAPABILITY_VERSION
g_string_append(str, " (Linux)");
#endif
#else
g_string_append(str, "without POSIX capabilities");
#endif
#ifdef __linux__
g_string_append(str, ", ");
#if defined(HAVE_LIBNL1)
g_string_append(str, "with libnl 1");
#elif defined(HAVE_LIBNL2)
g_string_append(str, "with libnl 2");
#elif defined(HAVE_LIBNL3)
g_string_append(str, "with libnl 3");
#else
g_string_append(str, "without libnl");
#endif
#endif
}
void
get_runtime_caplibs_version(GString *str)
{
g_string_append_printf(str, "with ");
#ifdef HAVE_PCAP_LIB_VERSION
g_string_append(str, pcap_lib_version());
#else
g_string_append(str, "libpcap (version unknown)");
#endif
}
void
get_compiled_caplibs_version(GString *str)
{
g_string_append(str, "without libpcap");
}
void
get_runtime_caplibs_version(GString *str _U_)
{
}
