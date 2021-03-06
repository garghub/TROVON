static void append_remote_list(GList *iflist)
{
GSList *list;
GList *rlist;
if_addr_t *if_addr, *temp_addr;
if_info_t *if_info, *temp;
for (rlist = g_list_nth(remote_interface_list, 0); rlist != NULL; rlist = g_list_next(rlist)) {
if_info = (if_info_t *)rlist->data;
temp = g_malloc0(sizeof(if_info_t));
temp->name = g_strdup(if_info->name);
temp->friendly_name = g_strdup(if_info->friendly_name);
temp->vendor_description = g_strdup(if_info->vendor_description);
for (list = g_slist_nth(if_info->addrs, 0); list != NULL; list = g_slist_next(list)) {
temp_addr = g_malloc0(sizeof(if_addr_t));
if_addr = (if_addr_t *)list->data;
if (if_addr) {
temp_addr->ifat_type = if_addr->ifat_type;
if (temp_addr->ifat_type == IF_AT_IPv4) {
temp_addr->addr.ip4_addr = if_addr->addr.ip4_addr;
} else {
memcpy(temp_addr->addr.ip6_addr, if_addr->addr.ip6_addr, sizeof(if_addr->addr));
}
} else {
g_free(temp_addr);
temp_addr = NULL;
}
if (temp_addr) {
temp->addrs = g_slist_append(temp->addrs, temp_addr);
}
}
temp->loopback = if_info->loopback;
iflist = g_list_append(iflist, temp);
}
}
GList *
capture_interface_list(int *err, char **err_str, void (*update_cb)(void))
{
int ret;
GList *if_list = NULL;
int i, j;
gchar *data, *primary_msg, *secondary_msg;
gchar **raw_list, **if_parts, **addr_parts;
gchar *name;
if_info_t *if_info;
if_addr_t *if_addr;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture Interface List ...");
*err = 0;
#ifdef HAVE_EXTCAP
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Loading External Capture Interface List ...");
if_list = extcap_interface_list(err_str);
#endif
ret = sync_interface_list_open(&data, &primary_msg, &secondary_msg, update_cb);
if (ret != 0) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture Interface List failed, error %d, %s (%s)!",
*err, primary_msg ? primary_msg : "no message",
secondary_msg ? secondary_msg : "no secondary message");
if (err_str) {
*err_str = primary_msg;
} else {
g_free(primary_msg);
}
g_free(secondary_msg);
*err = CANT_GET_INTERFACE_LIST;
return if_list;
}
#ifdef _WIN32
raw_list = g_strsplit(data, "\r\n", 0);
#else
raw_list = g_strsplit(data, "\n", 0);
#endif
g_free(data);
for (i = 0; raw_list[i] != NULL; i++) {
#ifdef HAVE_EXTCAP
if_parts = g_strsplit(raw_list[i], "\t", 7);
if (if_parts[0] == NULL || if_parts[1] == NULL || if_parts[2] == NULL ||
if_parts[3] == NULL || if_parts[4] == NULL || if_parts[5] == NULL ||
if_parts[6] == NULL) {
g_strfreev(if_parts);
continue;
}
#else
if_parts = g_strsplit(raw_list[i], "\t", 6);
if (if_parts[0] == NULL || if_parts[1] == NULL || if_parts[2] == NULL ||
if_parts[3] == NULL || if_parts[4] == NULL || if_parts[5] == NULL) {
g_strfreev(if_parts);
continue;
}
#endif
name = strchr(if_parts[0], ' ');
if (name) {
name++;
} else {
g_strfreev(if_parts);
continue;
}
if_info = g_new0(if_info_t,1);
if_info->name = g_strdup(name);
if (strlen(if_parts[1]) > 0)
if_info->vendor_description = g_strdup(if_parts[1]);
if (strlen(if_parts[2]) > 0)
if_info->friendly_name = g_strdup(if_parts[2]);
if_info->type = (interface_type)(int)strtol(if_parts[3], NULL, 10);
addr_parts = g_strsplit(if_parts[4], ",", 0);
for (j = 0; addr_parts[j] != NULL; j++) {
if_addr = g_new0(if_addr_t,1);
if (inet_pton(AF_INET, addr_parts[j], &if_addr->addr.ip4_addr) > 0) {
if_addr->ifat_type = IF_AT_IPv4;
} else if (inet_pton(AF_INET6, addr_parts[j],
&if_addr->addr.ip6_addr) > 0) {
if_addr->ifat_type = IF_AT_IPv6;
} else {
g_free(if_addr);
if_addr = NULL;
}
if (if_addr) {
if_info->addrs = g_slist_append(if_info->addrs, if_addr);
}
}
if (strcmp(if_parts[5], "loopback") == 0)
if_info->loopback = TRUE;
#ifdef HAVE_EXTCAP
if_info->extcap = g_strdup(if_parts[6]);
#endif
g_strfreev(if_parts);
g_strfreev(addr_parts);
if_list = g_list_append(if_list, if_info);
}
g_strfreev(raw_list);
#ifdef HAVE_PCAP_REMOTE
if (remote_interface_list && g_list_length(remote_interface_list) > 0) {
append_remote_list(if_list);
}
#endif
return if_list;
}
if_capabilities_t *
capture_get_if_capabilities(const gchar *ifname, gboolean monitor_mode,
const gchar *auth_string,
char **err_str, void (*update_cb)(void))
{
if_capabilities_t *caps;
GList *linktype_list = NULL;
int err, i;
gchar *data, *primary_msg, *secondary_msg;
gchar **raw_list, **lt_parts;
data_link_info_t *data_link_info;
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture Interface Capabilities ...");
#ifdef HAVE_EXTCAP
caps = extcap_get_if_dlts(ifname, err_str);
if (caps != NULL)
return caps;
if (err_str != NULL && *err_str != NULL)
return NULL;
#endif
err = sync_if_capabilities_open(ifname, monitor_mode, auth_string, &data,
&primary_msg, &secondary_msg, update_cb);
if (err != 0) {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture Interface Capabilities failed, error %d, %s (%s)!",
err, primary_msg ? primary_msg : "no message",
secondary_msg ? secondary_msg : "no secondary message");
if (err_str) {
*err_str = primary_msg;
} else {
g_free(primary_msg);
}
g_free(secondary_msg);
return NULL;
}
#ifdef _WIN32
raw_list = g_strsplit(data, "\r\n", 0);
#else
raw_list = g_strsplit(data, "\n", 0);
#endif
g_free(data);
if (raw_list[0] == NULL || *raw_list[0] == '\0') {
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture Interface Capabilities returned no information!");
if (err_str) {
*err_str = g_strdup("Dumpcap returned no interface capability information");
}
return NULL;
}
caps = (if_capabilities_t *)g_malloc(sizeof *caps);
switch (*raw_list[0]) {
case '0':
caps->can_set_rfmon = FALSE;
break;
case '1':
caps->can_set_rfmon = TRUE;
break;
default:
g_log(LOG_DOMAIN_CAPTURE, G_LOG_LEVEL_MESSAGE, "Capture Interface Capabilities returned bad information!");
if (err_str) {
*err_str = g_strdup_printf("Dumpcap returned \"%s\" for monitor-mode capability",
raw_list[0]);
}
g_free(caps);
return NULL;
}
for (i = 1; raw_list[i] != NULL; i++) {
lt_parts = g_strsplit(raw_list[i], "\t", 3);
if (lt_parts[0] == NULL || lt_parts[1] == NULL || lt_parts[2] == NULL) {
g_strfreev(lt_parts);
continue;
}
data_link_info = g_new(data_link_info_t,1);
data_link_info->dlt = (int) strtol(lt_parts[0], NULL, 10);
data_link_info->name = g_strdup(lt_parts[1]);
if (strcmp(lt_parts[2], "(not supported)") != 0)
data_link_info->description = g_strdup(lt_parts[2]);
else
data_link_info->description = NULL;
g_strfreev(lt_parts);
linktype_list = g_list_append(linktype_list, data_link_info);
}
g_strfreev(raw_list);
if (linktype_list == NULL) {
if (err_str)
*err_str = g_strdup("Dumpcap returned no link-layer types");
g_free(caps);
return NULL;
}
caps->data_link_types = linktype_list;
return caps;
}
void add_interface_to_remote_list(if_info_t *if_info)
{
GSList *list;
if_addr_t *if_addr, *temp_addr;
if_info_t *temp = g_malloc0(sizeof(if_info_t));
temp->name = g_strdup(if_info->name);
temp->friendly_name = g_strdup(if_info->friendly_name);
temp->vendor_description = g_strdup(if_info->vendor_description);
for (list = g_slist_nth(if_info->addrs, 0); list != NULL; list = g_slist_next(list)) {
temp_addr = g_malloc0(sizeof(if_addr_t));
if_addr = (if_addr_t *)list->data;
if (if_addr) {
temp_addr->ifat_type = if_addr->ifat_type;
if (temp_addr->ifat_type == IF_AT_IPv4) {
temp_addr->addr.ip4_addr = if_addr->addr.ip4_addr;
} else {
memcpy(temp_addr->addr.ip6_addr, if_addr->addr.ip6_addr, sizeof(if_addr->addr));
}
} else {
g_free(temp_addr);
temp_addr = NULL;
}
if (temp_addr) {
temp->addrs = g_slist_append(temp->addrs, temp_addr);
}
}
temp->loopback = if_info->loopback;
remote_interface_list = g_list_append(remote_interface_list, temp);
}
