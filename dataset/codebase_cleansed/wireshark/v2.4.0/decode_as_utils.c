static void
display_dissector_table_names(const char *table_name, const char *ui_name,
gpointer output)
{
if ((prev_display_dissector_name == NULL) ||
(strcmp(prev_display_dissector_name, table_name) != 0)) {
fprintf((FILE *)output, "\t%s (%s)\n", table_name, ui_name);
prev_display_dissector_name = table_name;
}
}
static void
display_dissector_names(const gchar *table _U_, gpointer handle, gpointer output)
{
int proto_id;
const gchar *proto_filter_name;
const gchar *proto_ui_name;
proto_id = dissector_handle_get_protocol_index((dissector_handle_t)handle);
if (proto_id != -1) {
proto_filter_name = proto_get_protocol_filter_name(proto_id);
proto_ui_name = proto_get_protocol_name(proto_id);
g_assert(proto_filter_name != NULL);
g_assert(proto_ui_name != NULL);
if ((prev_display_dissector_name == NULL) ||
(strcmp(prev_display_dissector_name, proto_filter_name) != 0)) {
fprintf((FILE *)output, "\t%s (%s)\n",
proto_filter_name,
proto_ui_name);
prev_display_dissector_name = proto_filter_name;
}
}
}
static gint
compare_dissector_key_name(gconstpointer dissector_a, gconstpointer dissector_b)
{
return strcmp((const char*)dissector_a, (const char*)dissector_b);
}
static void
fprint_all_layer_types(FILE *output)
{
prev_display_dissector_name = NULL;
dissector_all_tables_foreach_table(display_dissector_table_names, (gpointer)output, (GCompareFunc)compare_dissector_key_name);
}
static void
fprint_all_protocols_for_layer_types(FILE *output, gchar *table_name)
{
prev_display_dissector_name = NULL;
dissector_table_foreach_handle(table_name,
display_dissector_names,
(gpointer)output);
}
static void
find_protocol_name_func(const gchar *table _U_, gpointer handle, gpointer user_data)
{
int proto_id;
const gchar *protocol_filter_name;
protocol_name_search_t search_info;
g_assert(handle);
search_info = (protocol_name_search_t)user_data;
proto_id = dissector_handle_get_protocol_index((dissector_handle_t)handle);
if (proto_id != -1) {
protocol_filter_name = proto_get_protocol_filter_name(proto_id);
g_assert(protocol_filter_name != NULL);
if (strcmp(protocol_filter_name, search_info->searched_name) == 0) {
if (search_info->nb_match == 0) {
search_info->matched_handle = (dissector_handle_t)handle;
}
search_info->nb_match++;
}
}
}
gboolean decode_as_command_option(const gchar *cl_param)
{
gchar *table_name;
guint32 selector, selector2;
gchar *decoded_param;
gchar *remaining_param;
gchar *selector_str;
gchar *dissector_str;
dissector_handle_t dissector_matching;
dissector_table_t table_matching;
ftenum_t dissector_table_selector_type;
struct protocol_name_search user_protocol_name;
guint64 i;
char op;
g_assert(cl_param);
decoded_param = g_strdup(cl_param);
g_assert(decoded_param);
table_name = decoded_param;
remaining_param = strchr(table_name, '=');
if (remaining_param == NULL) {
cmdarg_err("Parameter \"%s\" doesn't follow the template \"%s\"", cl_param, DECODE_AS_ARG_TEMPLATE);
}
else {
*remaining_param = '\0';
}
while (table_name[0] == ' ')
table_name++;
while (table_name[strlen(table_name) - 1] == ' ')
table_name[strlen(table_name) - 1] = '\0';
table_matching = NULL;
if (!(*(table_name))) {
cmdarg_err("No layer type specified");
}
else {
table_matching = find_dissector_table(table_name);
if (!table_matching) {
cmdarg_err("Unknown layer type -- %s", table_name);
}
}
if (!table_matching) {
cmdarg_err("Valid layer types are:");
fprint_all_layer_types(stderr);
}
if (remaining_param == NULL || !table_matching) {
g_free(decoded_param);
return FALSE;
}
if (*(remaining_param + 1) != '=') {
cmdarg_err("WARNING: -d requires \"==\" instead of \"=\". Option will be treated as \"%s==%s\"", table_name, remaining_param + 1);
}
else {
remaining_param++;
*remaining_param = '\0';
}
remaining_param++;
selector_str = remaining_param;
remaining_param = strchr(selector_str, ',');
if (remaining_param == NULL) {
cmdarg_err("Parameter \"%s\" doesn't follow the template \"%s\"", cl_param, DECODE_AS_ARG_TEMPLATE);
}
else {
*remaining_param = '\0';
}
dissector_table_selector_type = get_dissector_table_selector_type(table_name);
switch (dissector_table_selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
switch (sscanf(selector_str, "%u%c%u", &selector, &op, &selector2)) {
case 1:
op = '\0';
break;
case 3:
if (op != ':' && op != '-') {
cmdarg_err("Invalid selector numeric range \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
if (op == ':') {
if ((selector2 == 0) || ((guint64)selector + selector2 - 1) > G_MAXUINT32) {
cmdarg_err("Invalid selector numeric range \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
}
else if (selector2 < selector) {
cmdarg_err("Invalid selector numeric range \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
break;
default:
cmdarg_err("Invalid selector number \"%s\"", selector_str);
g_free(decoded_param);
return FALSE;
}
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
break;
default:
g_assert_not_reached();
}
if (remaining_param == NULL) {
cmdarg_err("Valid protocols for layer type \"%s\" are:", table_name);
fprint_all_protocols_for_layer_types(stderr, table_name);
g_free(decoded_param);
return FALSE;
}
remaining_param++;
dissector_str = remaining_param;
while (dissector_str[0] == ' ')
dissector_str++;
while (dissector_str[strlen(dissector_str) - 1] == ' ')
dissector_str[strlen(dissector_str) - 1] = '\0';
dissector_matching = NULL;
if (!(*dissector_str)) {
cmdarg_err("No protocol name specified");
}
else {
user_protocol_name.nb_match = 0;
user_protocol_name.searched_name = dissector_str;
user_protocol_name.matched_handle = NULL;
dissector_table_foreach_handle(table_name, find_protocol_name_func, &user_protocol_name);
if (user_protocol_name.nb_match != 0) {
dissector_matching = user_protocol_name.matched_handle;
if (user_protocol_name.nb_match > 1) {
cmdarg_err("WARNING: Protocol \"%s\" matched %u dissectors, first one will be used", dissector_str, user_protocol_name.nb_match);
}
}
else {
if (proto_get_id_by_filter_name(dissector_str) == -1) {
cmdarg_err("Unknown protocol -- \"%s\"", dissector_str);
}
else {
cmdarg_err("Protocol \"%s\" isn't valid for layer type \"%s\"",
dissector_str, table_name);
}
}
}
if (!dissector_matching) {
cmdarg_err("Valid protocols for layer type \"%s\" are:", table_name);
fprint_all_protocols_for_layer_types(stderr, table_name);
g_free(decoded_param);
return FALSE;
}
switch (dissector_table_selector_type) {
case FT_UINT8:
case FT_UINT16:
case FT_UINT24:
case FT_UINT32:
if (op == '\0') {
dissector_change_uint(table_name, selector, dissector_matching);
}
else if (op == ':') {
for (i = selector; i < (guint64)selector + selector2; i++) {
dissector_change_uint(table_name, (guint32)i, dissector_matching);
}
}
else {
for (i = selector; i <= selector2; i++) {
dissector_change_uint(table_name, (guint32)i, dissector_matching);
}
}
break;
case FT_STRING:
case FT_STRINGZ:
case FT_UINT_STRING:
case FT_STRINGZPAD:
dissector_change_string(table_name, selector_str, dissector_matching);
break;
default:
g_assert_not_reached();
}
g_free(decoded_param);
return TRUE;
}
