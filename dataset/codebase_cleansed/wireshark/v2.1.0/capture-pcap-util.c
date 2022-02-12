static void
add_unix_interface_ifinfo(if_info_t *if_info, const char *name,
const char *description _U_)
{
CFStringRef name_CFString;
CFArrayRef interfaces;
CFIndex num_interfaces;
CFIndex i;
SCNetworkInterfaceRef interface;
CFStringRef bsdname_CFString;
CFStringRef friendly_name_CFString;
CFStringRef interface_type_CFString;
interfaces = SCNetworkInterfaceCopyAll();
if (interfaces == NULL) {
return;
}
name_CFString = CFStringCreateWithCString(kCFAllocatorDefault,
name, kCFStringEncodingUTF8);
if (name_CFString == NULL) {
CFRelease(interfaces);
return;
}
num_interfaces = CFArrayGetCount(interfaces);
for (i = 0; i < num_interfaces; i++) {
interface = (SCNetworkInterfaceRef)CFArrayGetValueAtIndex(interfaces, i);
bsdname_CFString = SCNetworkInterfaceGetBSDName(interface);
if (bsdname_CFString == NULL) {
continue;
}
if (CFStringCompare(name_CFString, bsdname_CFString, 0) == 0) {
friendly_name_CFString = SCNetworkInterfaceGetLocalizedDisplayName(interface);
if (friendly_name_CFString != NULL)
if_info->friendly_name = CFString_to_C_string(friendly_name_CFString);
interface_type_CFString = SCNetworkInterfaceGetInterfaceType(interface);
if (CFStringCompare(interface_type_CFString,
kSCNetworkInterfaceTypeIEEE80211, 0) == kCFCompareEqualTo)
if_info->type = IF_WIRELESS;
else if (CFStringCompare(interface_type_CFString,
kSCNetworkInterfaceTypeBluetooth, 0) == kCFCompareEqualTo)
if_info->type = IF_BLUETOOTH;
else if (CFStringCompare(interface_type_CFString,
kSCNetworkInterfaceTypeModem, 0) == kCFCompareEqualTo)
if_info->type = IF_DIALUP;
else if (CFStringCompare(interface_type_CFString,
kSCNetworkInterfaceTypePPP, 0) == kCFCompareEqualTo)
if_info->type = IF_DIALUP;
else if (CFStringCompare(interface_type_CFString,
kSCNetworkInterfaceTypeWWAN, 0) == kCFCompareEqualTo)
if_info->type = IF_DIALUP;
else
if_info->type = IF_WIRED;
break;
}
}
CFRelease(interfaces);
CFRelease(name_CFString);
}
static void
add_unix_interface_ifinfo(if_info_t *if_info, const char *name,
const char *description _U_)
{
char *wireless_path;
ws_statb64 statb;
wireless_path = g_strdup_printf("/sys/class/net/%s/wireless", name);
if (wireless_path != NULL) {
if (ws_stat64(wireless_path, &statb) == 0)
if_info->type = IF_WIRELESS;
g_free(wireless_path);
}
if (if_info->type == IF_WIRED) {
if (strstr(name, "bluetooth") != NULL) {
if_info->type = IF_BLUETOOTH;
} else if (strstr(name, "usbmon") != NULL)
if_info->type = IF_USB;
}
}
void
add_unix_interface_ifinfo(if_info_t *if_info, const char *name _U_,
const char *description)
{
if_info->friendly_name = g_strdup(description);
}
if_info_t *
if_info_new(const char *name, const char *description, gboolean loopback)
{
if_info_t *if_info;
#ifdef _WIN32
const char *guid_text;
GUID guid;
#endif
if_info = (if_info_t *)g_malloc(sizeof (if_info_t));
if_info->name = g_strdup(name);
if_info->friendly_name = NULL;
if_info->vendor_description = NULL;
if_info->type = IF_WIRED;
#ifdef HAVE_EXTCAP
if_info->extcap = g_strdup("");
#endif
#ifdef _WIN32
if (description && (strstr(description, "generic dialup") != NULL ||
strstr(description, "PPP/SLIP") != NULL)) {
if_info->type = IF_DIALUP;
} else if (description && (strstr(description, "Wireless") != NULL ||
strstr(description,"802.11") != NULL)) {
if_info->type = IF_WIRELESS;
} else if (description && strstr(description, "AirPcap") != NULL ||
strstr(name, "airpcap") != NULL) {
if_info->type = IF_AIRPCAP;
} else if (description && strstr(description, "Bluetooth") != NULL ) {
if_info->type = IF_BLUETOOTH;
} else if (description && strstr(description, "VMware") != NULL) {
if_info->type = IF_VIRTUAL;
}
if (strncmp("\\Device\\NPF_", name, 12) == 0)
guid_text = name + 12;
else
guid_text = name;
if (parse_as_guid(guid_text, &guid)) {
if_info->friendly_name = get_interface_friendly_name_from_device_guid(&guid);
if_info->vendor_description = g_strdup(description);
} else {
if_info->friendly_name = g_strdup(description);
if_info->vendor_description = NULL;
}
#else
add_unix_interface_ifinfo(if_info, name, description);
if (if_info->type == IF_WIRED) {
if (g_ascii_strncasecmp(name, "vmnet", 5) == 0)
if_info->type = IF_VIRTUAL;
else if (g_ascii_strncasecmp(name, "vmxnet", 6) == 0)
if_info->type = IF_VIRTUAL;
}
if (if_info->friendly_name == NULL) {
if (loopback)
if_info->friendly_name = g_strdup("Loopback");
}
if_info->vendor_description = NULL;
#endif
if_info->loopback = loopback;
if_info->addrs = NULL;
return if_info;
}
void
if_info_add_address(if_info_t *if_info, struct sockaddr *addr)
{
if_addr_t *if_addr;
struct sockaddr_in *ai;
struct sockaddr_in6 *ai6;
switch (addr->sa_family) {
case AF_INET:
ai = (struct sockaddr_in *)(void *)addr;
if_addr = (if_addr_t *)g_malloc(sizeof(*if_addr));
if_addr->ifat_type = IF_AT_IPv4;
if_addr->addr.ip4_addr =
*((guint32 *)&(ai->sin_addr.s_addr));
if_info->addrs = g_slist_append(if_info->addrs, if_addr);
break;
case AF_INET6:
ai6 = (struct sockaddr_in6 *)(void *)addr;
if_addr = (if_addr_t *)g_malloc(sizeof(*if_addr));
if_addr->ifat_type = IF_AT_IPv6;
memcpy((void *)&if_addr->addr.ip6_addr,
(void *)&ai6->sin6_addr.s6_addr,
sizeof if_addr->addr.ip6_addr);
if_info->addrs = g_slist_append(if_info->addrs, if_addr);
break;
}
}
static void
if_info_ip(if_info_t *if_info, pcap_if_t *d)
{
pcap_addr_t *a;
for (a = d->addresses; a != NULL; a = a->next) {
if (a->addr != NULL)
if_info_add_address(if_info, a->addr);
}
}
GList *
get_interface_list_findalldevs_ex(const char *source,
struct pcap_rmtauth *auth,
int *err, char **err_str)
{
GList *il = NULL;
pcap_if_t *alldevs, *dev;
if_info_t *if_info;
char errbuf[PCAP_ERRBUF_SIZE*4];
if (pcap_findalldevs_ex((char *)source, auth, &alldevs, errbuf) == -1) {
*err = CANT_GET_INTERFACE_LIST;
if (err_str != NULL)
*err_str = cant_get_if_list_error_message(errbuf);
return NULL;
}
if (alldevs == NULL) {
*err = 0;
if (err_str != NULL)
*err_str = NULL;
return NULL;
}
for (dev = alldevs; dev != NULL; dev = dev->next) {
if_info = if_info_new(dev->name, dev->description,
(dev->flags & PCAP_IF_LOOPBACK) ? TRUE : FALSE);
il = g_list_append(il, if_info);
if_info_ip(if_info, dev);
}
pcap_freealldevs(alldevs);
return il;
}
GList *
get_interface_list_findalldevs(int *err, char **err_str)
{
GList *il = NULL;
pcap_if_t *alldevs, *dev;
if_info_t *if_info;
char errbuf[PCAP_ERRBUF_SIZE];
if (pcap_findalldevs(&alldevs, errbuf) == -1) {
*err = CANT_GET_INTERFACE_LIST;
if (err_str != NULL)
*err_str = cant_get_if_list_error_message(errbuf);
return NULL;
}
if (alldevs == NULL) {
*err = 0;
if (err_str != NULL)
*err_str = NULL;
return NULL;
}
for (dev = alldevs; dev != NULL; dev = dev->next) {
if_info = if_info_new(dev->name, dev->description,
(dev->flags & PCAP_IF_LOOPBACK) ? TRUE : FALSE);
il = g_list_append(il, if_info);
if_info_ip(if_info, dev);
}
pcap_freealldevs(alldevs);
return il;
}
static void
free_if_info_addr_cb(gpointer addr, gpointer user_data _U_)
{
g_free(addr);
}
static void
free_if_cb(gpointer data, gpointer user_data _U_)
{
if_info_t *if_info = (if_info_t *)data;
g_free(if_info->name);
g_free(if_info->friendly_name);
g_free(if_info->vendor_description);
#ifdef HAVE_EXTCAP
g_free(if_info->extcap);
#endif
g_slist_foreach(if_info->addrs, free_if_info_addr_cb, NULL);
g_slist_free(if_info->addrs);
g_free(if_info);
}
void
free_interface_list(GList *if_list)
{
g_list_foreach(if_list, free_if_cb, NULL);
g_list_free(if_list);
}
static int
pcap_datalink_name_to_val(const char *name)
{
int i;
for (i = 0; dlt_choices[i].name != NULL; i++) {
if (g_ascii_strcasecmp(dlt_choices[i].name + sizeof("DLT_") - 1,
name) == 0)
return (dlt_choices[i].dlt);
}
return (-1);
}
static const char *
pcap_datalink_val_to_name(int dlt)
{
int i;
for (i = 0; dlt_choices[i].name != NULL; i++) {
if (dlt_choices[i].dlt == dlt)
return (dlt_choices[i].name + sizeof("DLT_") - 1);
}
return (NULL);
}
const char *
pcap_datalink_val_to_description(int dlt)
{
int i;
for (i = 0; dlt_choices[i].name != NULL; i++) {
if (dlt_choices[i].dlt == dlt)
return (dlt_choices[i].description);
}
return (NULL);
}
static void
free_linktype_cb(gpointer data, gpointer user_data _U_)
{
data_link_info_t *linktype_info = (data_link_info_t *)data;
g_free(linktype_info->name);
g_free(linktype_info->description);
g_free(linktype_info);
}
void
free_if_capabilities(if_capabilities_t *caps)
{
g_list_foreach(caps->data_link_types, free_linktype_cb, NULL);
g_list_free(caps->data_link_types);
g_free(caps);
}
const char *
linktype_val_to_name(int dlt)
{
return pcap_datalink_val_to_name(dlt);
}
int
linktype_name_to_val(const char *linktype)
{
return pcap_datalink_name_to_val(linktype);
}
int
get_pcap_datalink(pcap_t *pch, const char *devicename
#ifndef _AIX
_U_)
gboolean
set_pcap_datalink(pcap_t *pcap_h, int datalink, char *name,
char *errmsg, size_t errmsg_len,
char *secondary_errmsg, size_t secondary_errmsg_len)
{
char *set_datalink_err_str;
if (datalink == -1)
return TRUE;
#ifdef HAVE_PCAP_SET_DATALINK
if (pcap_set_datalink(pcap_h, datalink) == 0)
return TRUE;
set_datalink_err_str = pcap_geterr(pcap_h);
#else
if (get_pcap_datalink(pcap_h, name) == datalink)
return TRUE;
set_datalink_err_str =
"That DLT isn't one of the DLTs supported by this device";
#endif
g_snprintf(errmsg, (gulong) errmsg_len, "Unable to set data link type on interface '%s' (%s).",
name, set_datalink_err_str);
if (strstr(set_datalink_err_str, "is not one of the DLTs supported by this device") == NULL)
g_snprintf(secondary_errmsg, (gulong) secondary_errmsg_len, please_report);
else
secondary_errmsg[0] = '\0';
return FALSE;
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
static GList *
get_data_link_types(pcap_t *pch, interface_options *interface_opts,
char **err_str)
{
GList *data_link_types;
int deflt;
#ifdef HAVE_PCAP_LIST_DATALINKS
int *linktypes;
int i, nlt;
#endif
data_link_info_t *data_link_info;
deflt = get_pcap_datalink(pch, interface_opts->name);
#ifdef HAVE_PCAP_LIST_DATALINKS
nlt = pcap_list_datalinks(pch, &linktypes);
if (nlt < 0) {
pcap_close(pch);
if (err_str != NULL) {
if (nlt == PCAP_ERROR)
*err_str = g_strdup_printf("pcap_list_datalinks() failed: %s",
pcap_geterr(pch));
else
*err_str = g_strdup(pcap_statustostr(nlt));
}
return NULL;
}
data_link_types = NULL;
for (i = 0; i < nlt; i++) {
data_link_info = create_data_link_info(linktypes[i]);
if (linktypes[i] == deflt)
data_link_types = g_list_prepend(data_link_types,
data_link_info);
else
data_link_types = g_list_append(data_link_types,
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
data_link_types = g_list_append(data_link_types, data_link_info);
#endif
if (err_str != NULL)
*err_str = NULL;
return data_link_types;
}
static gboolean
is_linux_bonding_device(const char *ifname)
{
int fd;
struct ifreq ifr;
ifbond ifb;
fd = socket(PF_INET, SOCK_DGRAM, 0);
if (fd == -1)
return FALSE;
memset(&ifr, 0, sizeof ifr);
g_strlcpy(ifr.ifr_name, ifname, sizeof ifr.ifr_name);
memset(&ifb, 0, sizeof ifb);
ifr.ifr_data = (caddr_t)&ifb;
#if defined(SIOCBONDINFOQUERY)
if (ioctl(fd, SIOCBONDINFOQUERY, &ifr) == 0) {
close(fd);
return TRUE;
}
#else
if (ioctl(fd, BOND_INFO_QUERY_OLD, &ifr) == 0) {
close(fd);
return TRUE;
}
#endif
close(fd);
return FALSE;
}
static gboolean
is_linux_bonding_device(const char *ifname _U_)
{
return FALSE;
}
if_capabilities_t *
get_if_capabilities_pcap_create(interface_options *interface_opts,
char **err_str)
{
if_capabilities_t *caps;
char errbuf[PCAP_ERRBUF_SIZE];
pcap_t *pch;
int status;
caps = (if_capabilities_t *)g_malloc(sizeof *caps);
pch = pcap_create(interface_opts->name, errbuf);
if (pch == NULL) {
if (err_str != NULL)
*err_str = g_strdup(errbuf);
g_free(caps);
return NULL;
}
if (is_linux_bonding_device(interface_opts->name)) {
status = 0;
} else {
status = pcap_can_set_rfmon(pch);
}
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
if (interface_opts->monitor_mode)
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
caps->data_link_types = get_data_link_types(pch, interface_opts,
err_str);
if (caps->data_link_types == NULL) {
pcap_close(pch);
g_free(caps);
return NULL;
}
pcap_close(pch);
if (err_str != NULL)
*err_str = NULL;
return caps;
}
if_capabilities_t *
get_if_capabilities_pcap_open_live(interface_options *interface_opts,
char **err_str)
{
if_capabilities_t *caps;
char errbuf[PCAP_ERRBUF_SIZE];
pcap_t *pch;
caps = (if_capabilities_t *)g_malloc(sizeof *caps);
pch = pcap_open_live(interface_opts->name, MIN_PACKET_SIZE, 0, 0,
errbuf);
caps->can_set_rfmon = FALSE;
if (pch == NULL) {
if (err_str != NULL)
*err_str = g_strdup(errbuf[0] == '\0' ? "Unknown error (pcap bug; actual error cause not reported)" : errbuf);
g_free(caps);
return NULL;
}
caps->data_link_types = get_data_link_types(pch, interface_opts,
err_str);
if (caps->data_link_types == NULL) {
pcap_close(pch);
g_free(caps);
return NULL;
}
pcap_close(pch);
if (err_str != NULL)
*err_str = NULL;
return caps;
}
if_capabilities_t *
get_if_capabilities(interface_options *interface_opts, char **err_str)
{
#if defined(HAVE_PCAP_OPEN) && defined(HAVE_PCAP_REMOTE)
if_capabilities_t *caps;
char errbuf[PCAP_ERRBUF_SIZE];
pcap_t *pch;
int deflt;
data_link_info_t *data_link_info;
if (strncmp (interface_opts->name, "rpcap://", 8) == 0) {
struct pcap_rmtauth auth;
caps = (if_capabilities_t *)g_malloc(sizeof *caps);
auth.type = interface_opts->auth_type == CAPTURE_AUTH_PWD ?
RPCAP_RMTAUTH_PWD : RPCAP_RMTAUTH_NULL;
auth.username = interface_opts->auth_username;
auth.password = interface_opts->auth_password;
errbuf[0] = '\0';
pch = pcap_open(interface_opts->name, MIN_PACKET_SIZE, 0, 0, &auth,
errbuf);
if (pch == NULL) {
if (err_str != NULL)
*err_str = g_strdup(errbuf[0] == '\0' ? "Unknown error (pcap bug; actual error cause not reported)" : errbuf);
g_free(caps);
return NULL;
}
deflt = get_pcap_datalink(pch, interface_opts->name);
data_link_info = create_data_link_info(deflt);
caps->data_link_types = g_list_append(caps->data_link_types,
data_link_info);
pcap_close(pch);
if (err_str != NULL)
*err_str = NULL;
return caps;
}
#endif
return get_if_capabilities_local(interface_opts, err_str);
}
