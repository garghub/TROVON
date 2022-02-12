static char *
capture_dev_get_if_property(const gchar *pref, const gchar *if_name)
{
gchar **if_tokens;
gchar *property = NULL;
int i;
if (if_name == NULL || strlen(if_name) < 1) {
return NULL;
}
if (pref == NULL || strlen(pref) < 1) {
return NULL;
}
if_tokens = g_strsplit(pref, ",", -1);
for (i = 0; if_tokens[i] != NULL; i++) {
gchar *opening_parenp, *closing_parenp;
opening_parenp = strchr(if_tokens[i], '(');
if (opening_parenp == NULL) {
break;
}
closing_parenp = strrchr(if_tokens[i], ')');
if (closing_parenp == NULL || closing_parenp <= opening_parenp) {
break;
}
*opening_parenp = '\0';
*closing_parenp = '\0';
if (strcmp(if_tokens[i], if_name) == 0) {
if (strlen(opening_parenp + 1) > 0) {
property = g_strdup(opening_parenp + 1);
}
break;
}
}
g_strfreev(if_tokens);
return property;
}
static gint
capture_dev_get_if_int_property(const gchar *pref, const gchar *if_name)
{
gchar *property_string, *next;
long property;
property_string = capture_dev_get_if_property(pref, if_name);
if (property_string == NULL) {
return -1;
}
property = strtol(property_string, &next, 10);
if (next == property_string || *next != '\0' || property < 0) {
g_free(property_string);
return -1;
}
if (property > G_MAXINT) {
g_free(property_string);
return -1;
}
g_free(property_string);
return (gint)property;
}
char *
capture_dev_user_descr_find(const gchar *if_name)
{
return capture_dev_get_if_property(prefs.capture_devices_descr, if_name);
}
gint
capture_dev_user_linktype_find(const gchar *if_name)
{
return capture_dev_get_if_int_property(prefs.capture_devices_linktypes, if_name);
}
gint
capture_dev_user_buffersize_find(const gchar *if_name)
{
return capture_dev_get_if_int_property(prefs.capture_devices_buffersize, if_name);
}
gboolean
capture_dev_user_snaplen_find(const gchar *if_name, gboolean *hassnap, int *snaplen)
{
gboolean found = FALSE;
gchar **if_tokens;
int i;
if (if_name == NULL || strlen(if_name) < 1) {
return FALSE;
}
if ((prefs.capture_devices_snaplen == NULL) ||
(*prefs.capture_devices_snaplen == '\0')) {
return FALSE;
}
if_tokens = g_strsplit(prefs.capture_devices_snaplen, ",", -1);
for (i = 0; if_tokens[i] != NULL; i++) {
gchar *colonp, *next;
long value;
colonp = strrchr(if_tokens[i], ':');
if (colonp == NULL) {
break;
}
*colonp = '\0';
if (strcmp(if_tokens[i], if_name) == 0) {
if (*(colonp + 1) == '0') {
found = TRUE;
*hassnap = FALSE;
*snaplen = WTAP_MAX_PACKET_SIZE_STANDARD;
} else if (*(colonp + 1) == '1') {
if (*(colonp + 2) != '(') {
break;
}
value = strtol(colonp + 3, &next, 10);
if (next == colonp + 3 || *next != ')' || value < 0) {
break;
}
if (value > G_MAXINT) {
break;
}
found = TRUE;
*hassnap = TRUE;
*snaplen = (gint)value;
} else {
break;
}
break;
}
}
g_strfreev(if_tokens);
return found;
}
gboolean
capture_dev_user_pmode_find(const gchar *if_name, gboolean *pmode)
{
int value;
value = capture_dev_get_if_int_property(prefs.capture_devices_pmode, if_name);
if (value == -1) {
return FALSE;
}
*pmode = (value != 0);
return TRUE;
}
gchar*
capture_dev_user_cfilter_find(const gchar *if_name)
{
return capture_dev_get_if_property(prefs.capture_devices_filter, if_name);
}
char *
get_interface_descriptive_name(const char *if_name)
{
char *descr;
GList *if_list;
GList *if_entry;
if_info_t *if_info;
int err;
descr = capture_dev_user_descr_find(if_name);
if (descr == NULL) {
if (strcmp(if_name, "-") == 0) {
descr = g_strdup(ex_opt_get_nth("stdin_descr", 0));
if (!descr) {
descr = g_strdup("Standard input");
}
} else {
descr = NULL;
if_list = capture_interface_list(&err, NULL, NULL);
if (if_list != NULL) {
if_entry = if_list;
do {
if_info = (if_info_t *)if_entry->data;
if (strcmp(if_info->name, if_name) == 0) {
if (if_info->friendly_name != NULL) {
descr = g_strdup(if_info->friendly_name);
} else if (if_info->vendor_description != NULL) {
descr = g_strdup(if_info->vendor_description);
}
break;
}
} while ((if_entry = g_list_next(if_entry)) != NULL);
}
free_interface_list(if_list);
if (descr == NULL) {
descr = g_strdup(if_name);
}
}
}
return descr;
}
GList *
build_capture_combo_list(GList *if_list, gboolean do_hide)
{
GList *combo_list;
GList *if_entry;
if_info_t *if_info;
char *if_string;
gchar *descr;
combo_list = NULL;
if (if_list != NULL) {
for (if_entry = if_list; if_entry != NULL;
if_entry = g_list_next(if_entry)) {
if_info = (if_info_t *)if_entry->data;
if (!prefs_is_capture_device_hidden(if_info->name) || !do_hide) {
descr = capture_dev_user_descr_find(if_info->name);
if (descr != NULL) {
if_string = g_strdup_printf("%s: %s", descr, if_info->name);
g_free(descr);
} else {
if (if_info->vendor_description != NULL) {
if_string = g_strdup_printf("%s: %s",
if_info->vendor_description,
if_info->name);
} else {
if_string = g_strdup(if_info->name);
}
}
combo_list = g_list_append(combo_list, if_string);
}
}
}
return combo_list;
}
static void
free_if_string(gpointer data, gpointer user_data _U_)
{
g_free(data);
}
void
free_capture_combo_list(GList *combo_list)
{
if (combo_list != NULL) {
g_list_foreach(combo_list, free_if_string, NULL);
g_list_free(combo_list);
}
}
const char *
get_if_name(const char *if_text)
{
const char *if_name;
#ifdef _WIN32
if_name = if_text + strlen(if_text);
for (;;) {
if (if_name == if_text) {
break;
}
if_name--;
if (*if_name == ':') {
if ((strncmp(if_name, "://", 3) != 0) && !g_ascii_isdigit(if_name[1])) {
if_name++;
while (*if_name == ' ')
if_name++;
break;
}
}
}
#else
if_name = strrchr(if_text, ' ');
if (if_name == NULL) {
if_name = if_text;
} else {
if_name++;
}
#endif
return if_name;
}
const char *
get_iface_description_for_interface(capture_options *capture_opts, guint i)
{
interface_options interface_opts;
if (i < capture_opts->ifaces->len) {
interface_opts = g_array_index(capture_opts->ifaces, interface_options, i);
if (!interface_opts.descr && interface_opts.name) {
interface_opts.descr = get_interface_descriptive_name(interface_opts.name);
capture_opts->ifaces = g_array_remove_index(capture_opts->ifaces, i);
g_array_insert_val(capture_opts->ifaces, i, interface_opts);
}
return (interface_opts.descr);
} else {
return (NULL);
}
}
void
set_active_dlt(interface_t *device, int global_default_dlt)
{
GList *list;
gboolean found_active_dlt;
link_row *link;
if ((device->active_dlt = capture_dev_user_linktype_find(device->name)) == -1) {
device->active_dlt = global_default_dlt;
}
found_active_dlt = FALSE;
for (list = device->links; list != NULL; list = g_list_next(list)) {
link = (link_row *)(list->data);
if (link->dlt != -1 && link->dlt == device->active_dlt) {
found_active_dlt = TRUE;
break;
}
}
if (!found_active_dlt) {
device->active_dlt = -1;
}
if (device->active_dlt == -1) {
for (list = device->links; list != NULL; list = g_list_next(list)) {
link = (link_row *)(list->data);
if (link->dlt != -1) {
device->active_dlt = link->dlt;
break;
}
}
}
}
gchar *
get_iface_display_name(const gchar *description, const if_info_t *if_info)
{
if (description && description[0]) {
#ifdef _WIN32
gchar *if_string = if_info->friendly_name ? if_info->friendly_name : if_info->name;
return g_strdup_printf("%s: %s", description, if_string);
#else
return g_strdup_printf("%s: %s", description, if_info->name);
#endif
}
if (if_info->friendly_name) {
#ifdef _WIN32
return g_strdup_printf("%s", if_info->friendly_name);
#else
return g_strdup_printf("%s: %s", if_info->friendly_name, if_info->name);
#endif
}
if (if_info->vendor_description) {
return g_strdup_printf("%s: %s", if_info->vendor_description, if_info->name);
}
return g_strdup(if_info->name);
}
