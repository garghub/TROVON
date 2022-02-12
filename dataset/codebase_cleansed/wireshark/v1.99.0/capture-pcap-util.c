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
#ifdef INET6
struct sockaddr_in6 *ai6;
#endif
switch (addr->sa_family) {
case AF_INET:
ai = (struct sockaddr_in *)(void *)addr;
if_addr = (if_addr_t *)g_malloc(sizeof(*if_addr));
if_addr->ifat_type = IF_AT_IPv4;
if_addr->addr.ip4_addr =
*((guint32 *)&(ai->sin_addr.s_addr));
if_info->addrs = g_slist_append(if_info->addrs, if_addr);
break;
#ifdef INET6
case AF_INET6:
ai6 = (struct sockaddr_in6 *)(void *)addr;
if_addr = (if_addr_t *)g_malloc(sizeof(*if_addr));
if_addr->ifat_type = IF_AT_IPv6;
memcpy((void *)&if_addr->addr.ip6_addr,
(void *)&ai6->sin6_addr.s6_addr,
sizeof if_addr->addr.ip6_addr);
if_info->addrs = g_slist_append(if_info->addrs, if_addr);
break;
#endif
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
int linktype_name_to_val(const char *linktype)
{
return pcap_datalink_name_to_val(linktype);
}
