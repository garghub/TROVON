char *
capture_dev_user_descr_find(const gchar *if_name)
{
gchar **if_tokens;
gchar *descr = NULL;
int i;
if (if_name == NULL || strlen(if_name) < 1) {
return NULL;
}
if (prefs.capture_devices_descr == NULL ||
strlen(prefs.capture_devices_descr) < 1) {
return NULL;
}
if_tokens = g_strsplit(prefs.capture_devices_descr, ",", -1);
for (i = 0; if_tokens[i] != NULL; i++) {
gchar **descr_tokens;
descr_tokens = g_strsplit_set(if_tokens[i], "()", -1);
if (g_strv_length(descr_tokens) == 3) {
if (strcmp(descr_tokens[0], if_name) == 0 && strlen(descr_tokens[1]) > 0) {
descr = g_strdup(descr_tokens[1]);
g_strfreev(descr_tokens);
break;
}
}
g_strfreev(descr_tokens);
}
g_strfreev(if_tokens);
return descr;
}
gint
capture_dev_user_linktype_find(const gchar *if_name)
{
gchar *p, *next, *tmpname;
long linktype;
if ((prefs.capture_devices_linktypes == NULL) ||
(*prefs.capture_devices_linktypes == '\0')) {
return -1;
}
tmpname = g_strdup_printf(",%s(", if_name);
if ((p = strstr(prefs.capture_devices_linktypes, tmpname)) == NULL) {
return -1;
}
p += strlen(if_name) + 2;
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
gchar *p, *next, *tmpname;
gint buffersize;
if ((prefs.capture_devices_buffersize == NULL) ||
(*prefs.capture_devices_buffersize == '\0')) {
return -1;
}
tmpname = g_strdup_printf(",%s(", if_name);
if ((p = strstr(prefs.capture_devices_buffersize, tmpname)) == NULL) {
return -1;
}
p += strlen(if_name) + 2;
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
gchar *p, *next, *tmpname;
gint snaplen;
if ((prefs.capture_devices_snaplen == NULL) ||
(*prefs.capture_devices_snaplen == '\0')) {
return -1;
}
tmpname = g_strdup_printf(",%s:", if_name);
if ((p = strstr(prefs.capture_devices_snaplen, tmpname)) == NULL) {
return -1;
}
p += strlen(if_name) + 4;
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
gchar *p, *next, *tmpname;
gboolean hassnap;
if ((prefs.capture_devices_snaplen == NULL) ||
(*prefs.capture_devices_snaplen == '\0')) {
return -1;
}
tmpname = g_strdup_printf(",%s:", if_name);
if ((p = strstr(prefs.capture_devices_snaplen, tmpname)) == NULL) {
return -1;
}
p += strlen(if_name) + 2;
hassnap = (gboolean)strtol(p, &next, 10);
if (next == p || *next != '(') {
return -1;
}
return (gboolean)hassnap;
}
gboolean
capture_dev_user_pmode_find(const gchar *if_name)
{
gchar *p, *next, *tmpname;
gboolean pmode;
if ((prefs.capture_devices_pmode == NULL) ||
(*prefs.capture_devices_pmode == '\0')) {
return -1;
}
tmpname = g_strdup_printf(",%s(", if_name);
if ((p = strstr(prefs.capture_devices_pmode, tmpname)) == NULL) {
return -1;
}
p += strlen(if_name) + 2;
pmode = (gboolean)strtol(p, &next, 10);
if (next == p || *next != ')') {
return -1;
}
return (gboolean)pmode;
}
gchar*
capture_dev_user_cfilter_find(const gchar *if_name)
{
gchar *p, q[MAX_VAL_LEN], *tmpname;
int i = 0;
if ((prefs.capture_devices_filter == NULL) ||
(*prefs.capture_devices_filter == '\0')) {
return NULL;
}
tmpname = g_strdup_printf(",%s(", if_name);
if ((p = strstr(prefs.capture_devices_filter, tmpname)) == NULL) {
return NULL;
}
p += strlen(if_name) + 2;
while (p[i+1] != ',' && p[i+1] != '\0') {
q[i] = p[i];
i++;
}
q[i] = '\0';
return g_strdup(q);
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
