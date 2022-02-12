static char *skipWhiteSpace(char *source, int *accumulated_offset)
{
int offset = 0;
while (source[offset] != '\0' && source[offset] == ' ') {
offset++;
}
*accumulated_offset += offset;
return source + offset;
}
static char* read_token(char* source, char delimeter, int *length, int *accumulated_length, gboolean copy)
{
static char static_buffer[1024];
int offset = 0;
char *source_proper = skipWhiteSpace(source, accumulated_length);
while (source_proper[offset] != '\0' && source_proper[offset] != delimeter) {
offset++;
}
*length = offset;
*accumulated_length += offset;
if (copy) {
char *new_string = g_strndup(source_proper, offset+1);
new_string[offset] = '\0';
return new_string;
}
else {
memcpy(&static_buffer, source_proper, offset);
static_buffer[offset] = '\0';
return static_buffer;
}
}
static gboolean rule_add_content(Rule_t *rule, const char *content_string, gboolean negated)
{
if (rule->number_contents < MAX_CONTENT_ENTRIES) {
content_t *new_content = &(rule->contents[rule->number_contents++]);
new_content->str = g_strdup(content_string);
new_content->negation = negated;
rule->last_added_content = new_content;
return TRUE;
}
return FALSE;
}
static void rule_set_content_nocase(Rule_t *rule)
{
if (rule->last_added_content) {
rule->last_added_content->nocase = TRUE;
}
}
static void rule_set_content_offset(Rule_t *rule, gint value)
{
if (rule->last_added_content) {
rule->last_added_content->offset = value;
rule->last_added_content->offset_set = TRUE;
}
}
static void rule_set_content_depth(Rule_t *rule, guint value)
{
if (rule->last_added_content) {
rule->last_added_content->depth = value;
}
}
static void rule_set_content_distance(Rule_t *rule, gint value)
{
if (rule->last_added_content) {
rule->last_added_content->distance = value;
rule->last_added_content->distance_set = TRUE;
}
}
static void rule_set_content_within(Rule_t *rule, guint value)
{
if (rule->last_added_content) {
rule->last_added_content->within = value;
}
}
static void rule_set_content_fast_pattern(Rule_t *rule)
{
if (rule->last_added_content) {
rule->last_added_content->fastpattern = TRUE;
}
}
static void rule_set_content_rawbytes(Rule_t *rule)
{
if (rule->last_added_content) {
rule->last_added_content->rawbytes = TRUE;
}
}
static void rule_set_content_http_method(Rule_t *rule)
{
if (rule->last_added_content) {
rule->last_added_content->http_method = TRUE;
}
}
static void rule_set_content_http_client_body(Rule_t *rule)
{
if (rule->last_added_content) {
rule->last_added_content->http_client_body = TRUE;
}
}
static void rule_set_content_http_cookie(Rule_t *rule)
{
if (rule->last_added_content) {
rule->last_added_content->http_cookie = TRUE;
}
}
static void rule_set_content_http_user_agent(Rule_t *rule)
{
if (rule->last_added_content) {
rule->last_added_content->http_user_agent = TRUE;
}
}
static gboolean rule_add_uricontent(Rule_t *rule, const char *uricontent_string, gboolean negated)
{
if (rule_add_content(rule, uricontent_string, negated)) {
rule->last_added_content->content_type = UriContent;
return TRUE;
}
return FALSE;
}
static void rule_set_http_uri(Rule_t *rule)
{
if (rule->last_added_content != NULL) {
rule->last_added_content->content_type = UriContent;
}
}
static gboolean rule_add_pcre(Rule_t *rule, const char *pcre_string)
{
if (rule_add_content(rule, pcre_string, FALSE)) {
rule->last_added_content->content_type = Pcre;
return TRUE;
}
return FALSE;
}
static gboolean rule_set_classtype(Rule_t *rule, const char *classtype)
{
rule->classtype = g_strdup(classtype);
return TRUE;
}
static void rule_add_reference(Rule_t *rule, const char *reference_string)
{
if (rule->number_references < MAX_REFERENCE_ENTRIES) {
rule->references[rule->number_references++] = g_strdup(reference_string);
}
}
static void rule_check_ip_vars(SnortConfig_t *snort_config, Rule_t *rule, char *field)
{
gpointer original_key = NULL;
gpointer value = NULL;
if (strlen(field) < 2) {
return;
}
if (rule->relevant_vars.num_ip_vars >= MAX_RULE_IP_VARS) {
return;
}
if (g_hash_table_lookup_extended(snort_config->ipvars, field+1, &original_key, &value)) {
rule->relevant_vars.ip_vars[rule->relevant_vars.num_ip_vars].name = (char*)original_key;
rule->relevant_vars.ip_vars[rule->relevant_vars.num_ip_vars].value = (char*)value;
rule->relevant_vars.num_ip_vars++;
}
}
static void rule_check_port_vars(SnortConfig_t *snort_config, Rule_t *rule, char *field)
{
gpointer original_key = NULL;
gpointer value = NULL;
if (strlen(field) < 2) {
return;
}
if (rule->relevant_vars.num_port_vars >= MAX_RULE_PORT_VARS) {
return;
}
if (g_hash_table_lookup_extended(snort_config->portvars, field+1, &original_key, &value)) {
rule->relevant_vars.port_vars[rule->relevant_vars.num_port_vars].name = (char*)original_key;
rule->relevant_vars.port_vars[rule->relevant_vars.num_port_vars].value = (char*)value;
rule->relevant_vars.num_port_vars++;
}
}
void rule_set_relevant_vars(SnortConfig_t *snort_config, Rule_t *rule)
{
int length;
int accumulated_length = 0;
char *field;
if (rule->relevant_vars.relevant_vars_set) {
return;
}
read_token(rule->rule_string+accumulated_length, ' ', &length, &accumulated_length, FALSE);
read_token(rule->rule_string+accumulated_length, ' ', &length, &accumulated_length, FALSE);
field = read_token(rule->rule_string+accumulated_length, ' ', &length, &accumulated_length, FALSE);
snort_debug_printf("source address is (%s)\n", field);
rule_check_ip_vars(snort_config, rule, field);
field = read_token(rule->rule_string+accumulated_length, ' ', &length, &accumulated_length, FALSE);
snort_debug_printf("source port is (%s)\n", field);
rule_check_port_vars(snort_config, rule, field);
read_token(rule->rule_string+accumulated_length, ' ', &length, &accumulated_length, FALSE);
field = read_token(rule->rule_string+accumulated_length, ' ', &length, &accumulated_length, FALSE);
snort_debug_printf("dest address is (%s)\n", field);
rule_check_ip_vars(snort_config, rule, field);
field = read_token(rule->rule_string+accumulated_length, ' ', &length, &accumulated_length, FALSE);
snort_debug_printf("dest port is (%s)\n", field);
rule_check_port_vars(snort_config, rule, field);
rule->relevant_vars.relevant_vars_set = TRUE;
}
static gboolean parse_variables_line(SnortConfig_t *snort_config, char *line)
{
vartype_e var_type = unknownvar;
char * variable_type;
char * variable_name;
char * value;
int length;
int accumulated_length = 0;
variable_type = read_token(line, ' ', &length, &accumulated_length, FALSE);
if (variable_type == NULL) {
return FALSE;
}
if (strncmp(variable_type, "var", 3) == 0) {
var_type = var;
}
else if (strncmp(variable_type, "ipvar", 5) == 0) {
var_type = ipvar;
}
else if (strncmp(variable_type, "portvar", 7) == 0) {
var_type = portvar;
}
else {
return FALSE;
}
variable_name = read_token(line+ accumulated_length, ' ', &length, &accumulated_length, TRUE);
if (variable_name == NULL) {
return FALSE;
}
value = read_token(line + accumulated_length, ' ', &length, &accumulated_length, TRUE);
if (value == NULL) {
return FALSE;
}
switch (var_type) {
case var:
if (strcmp(variable_name, "RULE_PATH") == 0) {
snort_config->rule_path = value;
snort_config->rule_path_is_absolute = g_path_is_absolute(value);
snort_debug_printf("rule_path set to %s (is_absolute=%d)\n",
snort_config->rule_path, snort_config->rule_path_is_absolute);
}
g_hash_table_insert(snort_config->vars, variable_name, value);
break;
case ipvar:
g_hash_table_insert(snort_config->ipvars, variable_name, value);
break;
case portvar:
g_hash_table_insert(snort_config->portvars, variable_name, value);
break;
default:
return FALSE;
}
return FALSE;
}
static guint string_hash(gconstpointer key)
{
guint total=0, n=0;
const char *key_string = (const char *)key;
char c = key_string[n];
while (c != '\0') {
total += (int)c;
c = key_string[++n];
}
return total;
}
static gboolean string_equal(gconstpointer a, gconstpointer b)
{
const char *stringa = (const char*)a;
const char *stringb = (const char*)b;
return (strcmp(stringa, stringb) == 0);
}
static gboolean parse_references_prefix_file_line(SnortConfig_t *snort_config, char *line)
{
char *source;
char *prefix_name, *prefix_value;
int length=0, accumulated_length=0;
int n;
if (strncmp(line, "config reference: ", 18) != 0) {
return FALSE;
}
source = line+18;
prefix_name = read_token(source, ' ', &length, &accumulated_length, TRUE);
for (n=0; prefix_name[n] != '\0'; n++) {
prefix_name[n] = g_ascii_tolower(prefix_name[n]);
}
prefix_value = read_token(source+accumulated_length, ' ', &length, &accumulated_length, TRUE);
g_hash_table_insert(snort_config->references_prefixes, prefix_name, prefix_value);
return FALSE;
}
char *expand_reference(SnortConfig_t *snort_config, char *reference)
{
static char expanded_reference[512];
int length = (int)strlen(reference);
int accumulated_length = 0;
snort_debug_printf("expand_reference(%s)\n", reference);
char *prefix = read_token(reference, ',', &length, &accumulated_length, FALSE);
if (*prefix != '\0') {
guint n;
for (n=0; prefix[n] != '\0'; n++) {
prefix[n] = g_ascii_tolower(prefix[n]);
}
char *prefix_replacement;
prefix_replacement = (char*)g_hash_table_lookup(snort_config->references_prefixes, prefix);
g_snprintf(expanded_reference, 512, "%s%s", prefix_replacement, reference+length+1);
return expanded_reference;
}
return "ERROR: Reference didn't contain prefix and ','!";
}
void rule_set_alert(SnortConfig_t *snort_config, Rule_t *rule,
guint *global_match_number,
guint *rule_match_number)
{
snort_config->stat_alerts_detected++;
*global_match_number = snort_config->stat_alerts_detected;
if (rule != NULL) {
*rule_match_number = ++rule->matches_seen;
}
}
static gboolean delete_string_entry(gpointer key,
gpointer value,
gpointer user_data _U_)
{
char *key_string = (char*)key;
char *value_string = (char*)value;
g_free(key_string);
g_free(value_string);
return TRUE;
}
static gboolean parse_include_file(SnortConfig_t *snort_config, char *line, const char *config_directory, int recursion_level)
{
int length;
int accumulated_length = 0;
char *include_filename;
char *include_token = read_token(line, ' ', &length, &accumulated_length, FALSE);
if (strlen(include_token) == 0) {
return FALSE;
}
if (strncmp(include_token, "include", 7) != 0) {
return FALSE;
}
include_filename = read_token(line+accumulated_length, ' ', &length, &accumulated_length, FALSE);
if (*include_filename != '\0') {
FILE *new_config_fd;
char substituted_filename[512];
gboolean is_rule_file = FALSE;
if (strncmp(include_filename, "$RULE_PATH", 10) == 0) {
if (snort_config->rule_path_is_absolute) {
g_snprintf(substituted_filename, 512, "%s%s%s",
snort_config->rule_path,
g_file_separator,
include_filename + 10);
}
else {
g_snprintf(substituted_filename, 512, "%s%s%s%s%s",
config_directory,
g_file_separator,
snort_config->rule_path,
g_file_separator,
include_filename + 10);
}
is_rule_file = TRUE;
}
else {
if (!g_path_is_absolute(include_filename)) {
g_snprintf(substituted_filename, 512, "%s/%s", config_directory, include_filename);
}
else {
g_strlcpy(substituted_filename, include_filename, 512);
}
}
snort_debug_printf("Trying to open: %s\n", substituted_filename);
new_config_fd = ws_fopen(substituted_filename, "r");
if (new_config_fd == NULL) {
snort_debug_printf("Failed to open config file %s\n", substituted_filename);
return FALSE;
}
if (is_rule_file) {
snort_config->stat_rules_files++;
}
parse_config_file(snort_config, new_config_fd, substituted_filename, config_directory, recursion_level + 1);
fclose(new_config_fd);
return TRUE;
}
return FALSE;
}
static void process_rule_option(Rule_t *rule, char *options, int option_start_offset, int options_end_offset, int colon_offset)
{
static char name[1024], value[1024];
name[0] = '\0';
value[0] = '\0';
gint value_length = 0;
guint32 value32 = 0;
gint spaces_after_colon = 0;
if (colon_offset != 0) {
g_snprintf(name, colon_offset-option_start_offset, "%s", options+option_start_offset);
if (options[colon_offset] == ' ') {
spaces_after_colon = 1;
}
g_snprintf(value, options_end_offset-spaces_after_colon-colon_offset, "%s",
options+colon_offset+spaces_after_colon);
value_length = (gint)strlen(value);
}
else {
g_snprintf(name, options_end_offset-option_start_offset, "%s", options+option_start_offset);
}
ws_strtoi32(value, (const gchar**)&value[value_length], &value32);
if (name[0] == '\0') {
return;
}
if (strcmp(name, "msg") == 0) {
rule->msg = g_strdup(value);
}
else if (strcmp(name, "sid") == 0) {
rule->sid = value32;
}
else if (strcmp(name, "rev") == 0) {
value32 = rule->rev;
}
else if (strcmp(name, "content") == 0) {
int value_start = 0;
if (value_length < 3) {
return;
}
if (value[0] == '!') {
value_start = 1;
if (value_length < 4) {
return;
}
}
value[options_end_offset-colon_offset-spaces_after_colon-2] = '\0';
rule_add_content(rule, value+value_start+1, value_start == 1);
}
else if (strcmp(name, "uricontent") == 0) {
int value_start = 0;
if (value_length < 3) {
return;
}
if (value[0] == '!') {
value_start = 1;
if (value_length < 4) {
return;
}
}
value[options_end_offset-colon_offset-spaces_after_colon-2] = '\0';
rule_add_uricontent(rule, value+value_start+1, value_start == 1);
}
else if (strcmp(name, "http_uri") == 0) {
rule_set_http_uri(rule);
}
else if (strcmp(name, "pcre") == 0) {
int value_start = 0;
if (value_length < 3) {
return;
}
value[options_end_offset-colon_offset-spaces_after_colon-2] = '\0';
rule_add_pcre(rule, value+value_start+1);
}
else if (strcmp(name, "nocase") == 0) {
rule_set_content_nocase(rule);
}
else if (strcmp(name, "offset") == 0) {
rule_set_content_offset(rule, value32);
}
else if (strcmp(name, "depth") == 0) {
rule_set_content_depth(rule, value32);
}
else if (strcmp(name, "within") == 0) {
rule_set_content_within(rule, value32);
}
else if (strcmp(name, "distance") == 0) {
rule_set_content_distance(rule, value32);
}
else if (strcmp(name, "fast_pattern") == 0) {
rule_set_content_fast_pattern(rule);
}
else if (strcmp(name, "http_method") == 0) {
rule_set_content_http_method(rule);
}
else if (strcmp(name, "http_client_body") == 0) {
rule_set_content_http_client_body(rule);
}
else if (strcmp(name, "http_cookie") == 0) {
rule_set_content_http_cookie(rule);
}
else if (strcmp(name, "http_user_agent") == 0) {
rule_set_content_http_user_agent(rule);
}
else if (strcmp(name, "rawbytes") == 0) {
rule_set_content_rawbytes(rule);
}
else if (strcmp(name, "classtype") == 0) {
rule_set_classtype(rule, value);
}
else if (strcmp(name, "reference") == 0) {
rule_add_reference(rule, value);
}
else {
}
}
static gboolean parse_rule(SnortConfig_t *snort_config, char *line, const char *filename, int line_number, int line_length)
{
char *options_start;
char *options;
gboolean in_quotes = FALSE;
int options_start_index = 0, options_index = 0, colon_offset = 0;
char c;
int length = 0;
Rule_t *rule = NULL;
if (strncmp(line, "alert ", 6) != 0) {
return FALSE;
}
rule = (Rule_t*)g_malloc(sizeof(Rule_t));
snort_debug_printf("looks like a rule: %s\n", line);
memset(rule, 0, sizeof(Rule_t));
rule->rule_string = g_strdup(line);
rule->file = g_strdup(filename);
rule->line_number = line_number;
rule->protocol = read_token(line+6, ' ', &length, &length, TRUE);
options_start = strstr(line, "(");
if (options_start == NULL) {
snort_debug_printf("start of options not found\n");
return FALSE;
}
options_index = (int)(options_start-line) + 1;
if (line[line_length-1] != ')') {
g_free(rule);
return FALSE;
}
else {
line[line_length-1] = ';';
}
while (line[options_index] == ' ') options_index++;
options = &line[options_index];
options_index = 0;
while ((c = options[options_index++])) {
if (c == '"') {
in_quotes = !in_quotes;
}
if (!in_quotes) {
if (c == ':') {
colon_offset = options_index;
}
if (c == ';') {
process_rule_option(rule, options, options_start_index, options_index, colon_offset);
while (options[options_index] == ' ') options_index++;
options_start_index = options_index;
colon_offset = 0;
in_quotes = FALSE;
}
}
}
g_hash_table_insert(snort_config->rules, GUINT_TO_POINTER((guint)rule->sid), rule);
return TRUE;
}
static gboolean delete_rule(gpointer key _U_,
gpointer value,
gpointer user_data _U_)
{
Rule_t *rule = (Rule_t*)value;
unsigned int n;
snort_debug_printf("delete_rule(value=%p)\n", value);
g_free(rule->rule_string);
g_free(rule->file);
g_free(rule->msg);
g_free(rule->classtype);
g_free(rule->protocol);
for (n=0; n < rule->number_contents; n++) {
g_free(rule->contents[n].str);
g_free(rule->contents[n].translated_str);
}
for (n=0; n < rule->number_references; n++) {
g_free(rule->references[n]);
}
snort_debug_printf("Freeing rule at :%p\n", rule);
g_free(rule);
return TRUE;
}
static void parse_config_file(SnortConfig_t *snort_config, FILE *config_file_fd,
const char *filename, const char *dirname, int recursion_level)
{
#define MAX_LINE_LENGTH 4096
char line[MAX_LINE_LENGTH];
int line_number = 0;
snort_debug_printf("parse_config_file(filename=%s, recursion_level=%d)\n", filename, recursion_level);
if (recursion_level > MAX_CONFIG_FILE_RECURSE_DEPTH) {
return;
}
while (fgets(line, MAX_LINE_LENGTH, config_file_fd)) {
int line_length;
++line_number;
if ((line[0] == '\0') || (line[0] == '#')) {
continue;
}
line_length = (int)strlen(line);
while (line_length && ((line[line_length - 1] == '\n') || (line[line_length - 1] == '\r'))) {
--line_length;
}
line[line_length] = '\0';
if (line_length == 0) {
continue;
}
if (parse_variables_line(snort_config, line)) {
continue;
}
if (parse_references_prefix_file_line(snort_config, line)) {
continue;
}
if (parse_include_file(snort_config, line, dirname, recursion_level)) {
continue;
}
if (parse_rule(snort_config, line, filename, line_number, line_length)) {
snort_config->stat_rules++;
continue;
}
}
}
void create_config(SnortConfig_t **snort_config, const char *snort_config_file)
{
gchar* dirname;
gchar* basename;
FILE *config_file_fd;
snort_debug_printf("create_config (%s)\n", snort_config_file);
*snort_config = (SnortConfig_t*)g_malloc(sizeof(SnortConfig_t));
memset(*snort_config, 0, sizeof(SnortConfig_t));
(*snort_config)->rules = g_hash_table_new(g_direct_hash, g_direct_equal);
(*snort_config)->references_prefixes = g_hash_table_new(string_hash, string_equal);
(*snort_config)->vars = g_hash_table_new(string_hash, string_equal);
(*snort_config)->ipvars = g_hash_table_new(string_hash, string_equal);
(*snort_config)->portvars = g_hash_table_new(string_hash, string_equal);
dirname = g_path_get_dirname(snort_config_file);
basename = g_path_get_basename(snort_config_file);
config_file_fd = ws_fopen(snort_config_file, "r");
if (config_file_fd == NULL) {
snort_debug_printf("Failed to open config file %s\n", snort_config_file);
return;
}
parse_config_file(*snort_config, config_file_fd, snort_config_file, dirname, 1 );
g_free(dirname);
g_free(basename);
fclose(config_file_fd);
}
void delete_config(SnortConfig_t **snort_config)
{
snort_debug_printf("delete_config()\n");
g_hash_table_foreach_remove((*snort_config)->rules, delete_rule, NULL);
g_hash_table_destroy((*snort_config)->rules);
g_hash_table_foreach_remove((*snort_config)->references_prefixes, delete_string_entry, NULL);
g_hash_table_destroy((*snort_config)->references_prefixes);
g_hash_table_foreach_remove((*snort_config)->vars, delete_string_entry, NULL);
g_hash_table_destroy((*snort_config)->vars);
g_hash_table_foreach_remove((*snort_config)->ipvars, delete_string_entry, NULL);
g_hash_table_destroy((*snort_config)->ipvars);
g_hash_table_foreach_remove((*snort_config)->portvars, delete_string_entry, NULL);
g_hash_table_destroy((*snort_config)->portvars);
g_free(*snort_config);
*snort_config = NULL;
}
Rule_t *get_rule(SnortConfig_t *snort_config, guint32 sid)
{
if ((snort_config == NULL) || (snort_config->rules == NULL)) {
return NULL;
}
else {
return (Rule_t*)g_hash_table_lookup(snort_config->rules, GUINT_TO_POINTER(sid));
}
}
void get_global_rule_stats(SnortConfig_t *snort_config, unsigned int sid,
unsigned int *number_rules_files, unsigned int *number_rules,
unsigned int *alerts_detected, unsigned int *this_rule_alerts_detected)
{
*number_rules_files = snort_config->stat_rules_files;
*number_rules = snort_config->stat_rules;
*alerts_detected = snort_config->stat_alerts_detected;
Rule_t *rule;
rule = get_rule(snort_config, sid);
if (rule) {
*this_rule_alerts_detected = rule->matches_seen;
}
else {
*this_rule_alerts_detected = 0;
}
}
static void reset_rule_stats(gpointer key _U_,
gpointer value,
gpointer user_data _U_)
{
Rule_t *rule = (Rule_t*)value;
rule->matches_seen = 0;
}
void reset_global_rule_stats(SnortConfig_t *snort_config)
{
if (snort_config == NULL) {
return;
}
snort_config->stat_alerts_detected = 0;
g_hash_table_foreach(snort_config->rules, reset_rule_stats, NULL);
}
static unsigned char content_get_nibble_value(char c)
{
static unsigned char values[256];
static gboolean values_set = FALSE;
if (!values_set) {
unsigned char ch;
for (ch='a'; ch <= 'f'; ch++) {
values[ch] = 0xa + (ch-'a');
}
for (ch='A'; ch <= 'F'; ch++) {
values[ch] = 0xa + (ch-'A');
}
for (ch='0'; ch <= '9'; ch++) {
values[ch] = (ch-'0');
}
values_set = TRUE;
}
return values[(unsigned char)c];
}
guint content_convert_to_binary(content_t *content)
{
int output_idx = 0;
gboolean in_binary_mode = FALSE;
gboolean have_one_nibble = FALSE;
unsigned char one_nibble = 0;
char c;
int n;
gboolean have_backslash = FALSE;
static gchar binary_str[1024];
if (content->translated) {
return content->translated_length;
}
for (n=0; content->str[n] != '\0'; n++) {
c = content->str[n];
if (c == '|') {
in_binary_mode = !in_binary_mode;
continue;
}
if (!in_binary_mode) {
if (!have_backslash) {
if (c == '\\') {
have_backslash = TRUE;
continue;
}
else {
binary_str[output_idx++] = (unsigned char)c;
}
}
else {
have_backslash = 0;
binary_str[output_idx++] = (unsigned char)c;
}
}
else {
if (c == ' ') {
continue;
}
else {
unsigned char nibble = content_get_nibble_value(c);
if (!have_one_nibble) {
one_nibble = nibble;
have_one_nibble = TRUE;
}
else {
binary_str[output_idx++] = (one_nibble << 4) + nibble;
have_one_nibble = FALSE;
}
}
}
}
content->translated_str = (guchar*)g_malloc(output_idx+1);
memcpy(content->translated_str, binary_str, output_idx+1);
content->translated = TRUE;
content->translated_length = output_idx;
return output_idx;
}
gboolean content_convert_pcre_for_regex(content_t *content)
{
guint pcre_length, i, end_delimiter_offset = 0;
if (content->translated_str) {
return TRUE;
}
pcre_length = (guint)strlen(content->str);
if (pcre_length < 3) {
return FALSE;
}
if (pcre_length >= 512) {
return FALSE;
}
if (content->str[0] != '/') {
return FALSE;
}
for (i=pcre_length-1; i > 2; i--) {
if (content->str[i] == '/') {
end_delimiter_offset = i;
break;
}
else {
switch (content->str[i]) {
case 'i':
content->pcre_case_insensitive = TRUE;
break;
case 's':
content->pcre_dot_includes_newline = TRUE;
break;
case 'B':
content->pcre_raw = TRUE;
break;
case 'm':
content->pcre_multiline = TRUE;
break;
default:
snort_debug_printf("Unhandled pcre modifier '%c'\n", content->str[i]);
break;
}
}
}
if (end_delimiter_offset == 0) {
return FALSE;
}
content->translated_str = (guchar*)g_malloc(end_delimiter_offset);
memcpy(content->translated_str, content->str+1, end_delimiter_offset - 1);
content->translated_str[end_delimiter_offset-1] = '\0';
content->translated = TRUE;
content->translated_length = end_delimiter_offset - 1;
return TRUE;
}
