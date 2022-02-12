char *
capture_dev_user_descr_find(const gchar *if_name)
{
char *p;
char *p2 = NULL;
char *descr = NULL;
int lp = 0;
int ct = 0;
if ((prefs.capture_devices_descr == NULL) ||
(*prefs.capture_devices_descr == '\0')) {
return NULL;
}
if ((p = strstr(prefs.capture_devices_descr, if_name)) == NULL) {
return NULL;
}
while (*p != '\0') {
if (*p == ',')
return NULL;
else if (*p == '(') {
ct = 0;
lp++;
p++;
p2 = p;
continue;
}
else if (*p == ')') {
break;
}
else {
p++;
ct++;
}
}
if ((lp == 1) && (ct > 0) && (p2 != NULL)) {
descr = (char *)g_malloc(p - p2 + 1);
memcpy(descr, p2, p - p2);
descr[p - p2] = '\0';
return descr;
}
else
return NULL;
}
gint
capture_dev_user_linktype_find(const gchar *if_name)
{
gchar *p, *next;
long linktype;
if ((prefs.capture_devices_linktypes == NULL) ||
(*prefs.capture_devices_linktypes == '\0')) {
return -1;
}
if ((p = strstr(prefs.capture_devices_linktypes, if_name)) == NULL) {
return -1;
}
p += strlen(if_name) + 1;
linktype = strtol(p, &next, 10);
if (next == p || *next != ')' || linktype < 0) {
return -1;
}
if (linktype > G_MAXINT) {
return -1;
}
return (gint)linktype;
}
gint
capture_dev_user_buffersize_find(const gchar *if_name)
{
gchar *p, *next;
gint buffersize;
if ((prefs.capture_devices_buffersize == NULL) ||
(*prefs.capture_devices_buffersize == '\0')) {
return -1;
}
if ((p = strstr(prefs.capture_devices_buffersize, if_name)) == NULL) {
return -1;
}
p += strlen(if_name) + 1;
buffersize = (gint)strtol(p, &next, 10);
if (next == p || *next != ')' || buffersize < 0) {
return -1;
}
if (buffersize > G_MAXINT) {
return -1;
}
return (gint)buffersize;
}
gint
capture_dev_user_snaplen_find(const gchar *if_name)
{
gchar *p, *next;
gint snaplen;
if ((prefs.capture_devices_snaplen == NULL) ||
(*prefs.capture_devices_snaplen == '\0')) {
return -1;
}
if ((p = strstr(prefs.capture_devices_snaplen, if_name)) == NULL) {
return -1;
}
p += strlen(if_name) + 3;
snaplen = (gint)strtol(p, &next, 10);
if (next == p || *next != ')' || snaplen < 0) {
return -1;
}
if (snaplen > WTAP_MAX_PACKET_SIZE) {
return -1;
}
return (gint)snaplen;
}
gboolean
capture_dev_user_hassnap_find(const gchar *if_name)
{
gchar *p, *next;
gboolean hassnap;
if ((prefs.capture_devices_snaplen == NULL) ||
(*prefs.capture_devices_snaplen == '\0')) {
return -1;
}
if ((p = strstr(prefs.capture_devices_snaplen, if_name)) == NULL) {
return -1;
}
p += strlen(if_name) + 1;
hassnap = (gboolean)strtol(p, &next, 10);
if (next == p || *next != '(') {
return -1;
}
return (gboolean)hassnap;
}
gboolean
capture_dev_user_pmode_find(const gchar *if_name)
{
gchar *p, *next;
gboolean pmode;
if ((prefs.capture_devices_pmode == NULL) ||
(*prefs.capture_devices_pmode == '\0')) {
return -1;
}
if ((p = strstr(prefs.capture_devices_pmode, if_name)) == NULL) {
return -1;
}
p += strlen(if_name) + 1;
pmode = (gboolean)strtol(p, &next, 10);
if (next == p || *next != ')') {
return -1;
}
return (gboolean)pmode;
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
if (descr != NULL) {
descr = g_strdup(descr);
} else if (strcmp(if_name, "-") == 0) {
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
return descr;
}
static if_info_t *
search_info(GList *if_list, gchar *if_name)
{
GList *if_entry;
if_info_t *if_info;
for (if_entry = if_list; if_entry != NULL; if_entry = g_list_next(if_entry)) {
if_info = (if_info_t *)if_entry->data;
if(strcmp(if_name, if_info->name) == 0) {
return if_info;
}
}
return NULL;
}
char *
build_capture_combo_name(GList *if_list, gchar *if_name)
{
gchar *descr;
char *if_string;
if_info_t *if_info;
descr = capture_dev_user_descr_find(if_name);
if (descr != NULL) {
if_string = g_strdup_printf("%s: %s", descr, if_name);
g_free(descr);
} else {
if_info = search_info(if_list, if_name);
if (if_info != NULL && if_info->vendor_description != NULL) {
if_string = g_strdup_printf("%s: %s", if_info->vendor_description,
if_info->name);
} else {
if_string = g_strdup(if_name);
}
}
return if_string;
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
if ((strncmp(if_name, "://", 3) != 0) && !isdigit(if_name[1])) {
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
