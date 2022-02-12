color_filter_t *
color_filter_new(const gchar *name,
const gchar *filter_string,
color_t *bg_color,
color_t *fg_color,
gboolean disabled)
{
color_filter_t *colorf;
colorf = (color_filter_t *)g_malloc(sizeof (color_filter_t));
colorf->filter_name = g_strdup(name);
colorf->filter_text = g_strdup(filter_string);
colorf->bg_color = *bg_color;
colorf->fg_color = *fg_color;
colorf->disabled = disabled;
colorf->c_colorfilter = NULL;
colorf->color_edit_dlg_info = NULL;
colorf->selected = FALSE;
return colorf;
}
static void
color_filters_add_tmp(GSList **cfl)
{
gchar *name = NULL;
guint32 i;
gchar** bg_colors;
gchar** fg_colors;
gulong cval;
color_t bg_color, fg_color;
color_filter_t *colorf;
g_assert(strlen(prefs.gui_colorized_fg)==69);
g_assert(strlen(prefs.gui_colorized_bg)==69);
fg_colors = g_strsplit(prefs.gui_colorized_fg, ",", -1);
bg_colors = g_strsplit(prefs.gui_colorized_bg, ",", -1);
for ( i=1 ; i<=10 ; i++ ) {
name = g_strdup_printf("%s%02d",CONVERSATION_COLOR_PREFIX,i);
cval = strtoul(fg_colors[i-1], NULL, 16);
initialize_color(&fg_color, RED_COMPONENT(cval),
GREEN_COMPONENT(cval),
BLUE_COMPONENT(cval) );
cval = strtoul(bg_colors[i-1], NULL, 16);
initialize_color(&bg_color, RED_COMPONENT(cval),
GREEN_COMPONENT(cval),
BLUE_COMPONENT(cval) );
colorf = color_filter_new(name, NULL, &bg_color, &fg_color, TRUE);
colorf->filter_text = g_strdup("frame");
colorf->c_colorfilter = NULL;
*cfl = g_slist_append(*cfl, colorf);
g_free(name);
}
g_strfreev(fg_colors);
g_strfreev(bg_colors);
return;
}
static gint
color_filters_find_by_name_cb(gconstpointer arg1, gconstpointer arg2)
{
const color_filter_t *colorf = (const color_filter_t *)arg1;
const gchar *name = (const gchar *)arg2;
return (strstr(colorf->filter_name, name)==NULL) ? -1 : 0 ;
}
void
color_filters_set_tmp(guint8 filt_nr, gchar *filter, gboolean disabled)
{
gchar *name = NULL;
const gchar *tmpfilter = NULL;
GSList *cfl;
color_filter_t *colorf;
dfilter_t *compiled_filter;
guint8 i;
for ( i=1 ; i<=10 ; i++ ) {
if( i!=filt_nr && filter==NULL )
continue;
name = g_strdup_printf("%s%02d",CONVERSATION_COLOR_PREFIX,i);
cfl = g_slist_find_custom(color_filter_list, name, color_filters_find_by_name_cb);
colorf = (color_filter_t *)cfl->data;
if(colorf && ( (i==filt_nr) || (strstr(filter,colorf->filter_text)!=NULL) ) ) {
tmpfilter = ( (filter==NULL) || (i!=filt_nr) ) ? "frame" : filter;
if (!dfilter_compile(tmpfilter, &compiled_filter)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not compile color filter name: \"%s\""
" text: \"%s\".\n%s", name, filter, dfilter_error_msg);
} else {
if (colorf->filter_text != NULL)
g_free(colorf->filter_text);
if (colorf->c_colorfilter != NULL)
dfilter_free(colorf->c_colorfilter);
colorf->filter_text = g_strdup(tmpfilter);
colorf->c_colorfilter = compiled_filter;
colorf->disabled = ((i!=filt_nr) ? TRUE : disabled);
if( filter )
tmp_colors_set = TRUE;
}
}
g_free(name);
}
return;
}
void
color_filters_reset_tmp(void)
{
guint8 i;
for ( i=1 ; i<=10 ; i++ ) {
color_filters_set_tmp(i, NULL, TRUE);
}
tmp_colors_set = FALSE;
return;
}
void
color_filter_delete(color_filter_t *colorf)
{
if (colorf->filter_name != NULL)
g_free(colorf->filter_name);
if (colorf->filter_text != NULL)
g_free(colorf->filter_text);
if (colorf->c_colorfilter != NULL)
dfilter_free(colorf->c_colorfilter);
g_free(colorf);
}
static void
color_filter_delete_cb(gpointer filter_arg, gpointer unused _U_)
{
color_filter_t *colorf = (color_filter_t *)filter_arg;
color_filter_delete(colorf);
}
void
color_filter_list_delete(GSList **cfl)
{
g_slist_foreach(*cfl, color_filter_delete_cb, NULL);
g_slist_free(*cfl);
*cfl = NULL;
}
static color_filter_t *
color_filter_clone(color_filter_t *colorf)
{
color_filter_t *new_colorf;
new_colorf = (color_filter_t *)g_malloc(sizeof (color_filter_t));
new_colorf->filter_name = g_strdup(colorf->filter_name);
new_colorf->filter_text = g_strdup(colorf->filter_text);
new_colorf->bg_color = colorf->bg_color;
new_colorf->fg_color = colorf->fg_color;
new_colorf->disabled = colorf->disabled;
new_colorf->c_colorfilter = NULL;
new_colorf->color_edit_dlg_info = NULL;
new_colorf->selected = FALSE;
return new_colorf;
}
static void
color_filter_list_clone_cb(gpointer filter_arg, gpointer cfl_arg)
{
GSList **cfl = (GSList **)cfl_arg;
color_filter_t *new_colorf;
new_colorf = color_filter_clone((color_filter_t *)filter_arg);
*cfl = g_slist_append(*cfl, new_colorf);
}
static GSList *
color_filter_list_clone(GSList *cfl)
{
GSList *new_list = NULL;
g_slist_foreach(cfl, color_filter_list_clone_cb, &new_list);
return new_list;
}
void
color_filters_init(void)
{
color_filter_list_delete(&color_filter_list);
color_filters_add_tmp(&color_filter_list);
if (!read_users_filters(&color_filter_list))
color_filters_read_globals(&color_filter_list);
}
void
color_filters_reload(void)
{
color_filter_deleted_list = g_slist_concat(color_filter_deleted_list, color_filter_list);
color_filter_list = NULL;
color_filters_add_tmp(&color_filter_list);
if (!read_users_filters(&color_filter_list))
color_filters_read_globals(&color_filter_list);
}
void
color_filters_cleanup(void)
{
color_filter_list_delete(&color_filter_deleted_list);
}
static void
color_filters_clone_cb(gpointer filter_arg, gpointer user_data)
{
color_filter_t * new_colorf = color_filter_clone((color_filter_t *)filter_arg);
color_filter_add_cb (new_colorf, user_data);
}
void
color_filters_clone(gpointer user_data)
{
g_slist_foreach(color_filter_list, color_filters_clone_cb, user_data);
}
static void
color_filter_compile_cb(gpointer filter_arg, gpointer unused _U_)
{
color_filter_t *colorf = (color_filter_t *)filter_arg;
g_assert(colorf->c_colorfilter == NULL);
if (!dfilter_compile(colorf->filter_text, &colorf->c_colorfilter)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not compile color filter name: \"%s\" text: \"%s\".\n%s",
colorf->filter_name, colorf->filter_text, dfilter_error_msg);
}
}
static void
color_filter_validate_cb(gpointer filter_arg, gpointer unused _U_)
{
color_filter_t *colorf = (color_filter_t *)filter_arg;
g_assert(colorf->c_colorfilter == NULL);
if (!dfilter_compile(colorf->filter_text, &colorf->c_colorfilter)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Removing color filter name: \"%s\" text: \"%s\".\n%s",
colorf->filter_name, colorf->filter_text, dfilter_error_msg);
color_filter_valid_list = g_slist_remove(color_filter_valid_list, colorf);
color_filter_delete(colorf);
}
}
void
color_filters_apply(GSList *tmp_cfl, GSList *edit_cfl)
{
color_filter_deleted_list = g_slist_concat(color_filter_deleted_list, color_filter_list);
color_filter_list = NULL;
color_filter_valid_list = NULL;
color_filter_valid_list = color_filter_list_clone(tmp_cfl);
color_filter_valid_list = g_slist_concat(color_filter_valid_list,
color_filter_list_clone(edit_cfl) );
g_slist_foreach(color_filter_valid_list, color_filter_validate_cb, NULL);
color_filter_list = color_filter_list_clone(color_filter_valid_list);
g_slist_foreach(color_filter_list, color_filter_compile_cb, NULL);
}
gboolean
color_filters_used(void)
{
return color_filter_list != NULL && filters_enabled;
}
gboolean
tmp_color_filters_used(void)
{
return tmp_colors_set;
}
void
color_filters_enable(gboolean enable)
{
packet_list_enable_color(enable);
}
static void
prime_edt(gpointer data, gpointer user_data)
{
color_filter_t *colorf = (color_filter_t *)data;
epan_dissect_t *edt = (epan_dissect_t *)user_data;
if (colorf->c_colorfilter != NULL)
epan_dissect_prime_dfilter(edt, colorf->c_colorfilter);
}
void
color_filters_prime_edt(epan_dissect_t *edt)
{
if (color_filters_used())
g_slist_foreach(color_filter_list, prime_edt, edt);
}
const color_filter_t *
color_filters_colorize_packet(epan_dissect_t *edt)
{
GSList *curr;
color_filter_t *colorf;
if (color_filters_used()) {
curr = color_filter_list;
while(curr != NULL) {
colorf = (color_filter_t *)curr->data;
if ( (!colorf->disabled) &&
(colorf->c_colorfilter != NULL) &&
dfilter_apply_edt(colorf->c_colorfilter, edt)) {
return colorf;
}
curr = g_slist_next(curr);
}
}
return NULL;
}
static gboolean
read_filters_file(FILE *f, gpointer user_data)
{
#define INIT_BUF_SIZE 128
gchar *name = NULL;
gchar *filter_exp = NULL;
guint32 name_len = INIT_BUF_SIZE;
guint32 filter_exp_len = INIT_BUF_SIZE;
guint32 i = 0;
gint32 c;
guint16 fg_r, fg_g, fg_b, bg_r, bg_g, bg_b;
gboolean disabled = FALSE;
gboolean skip_end_of_line = FALSE;
name = (gchar *)g_malloc(name_len + 1);
filter_exp = (gchar *)g_malloc(filter_exp_len + 1);
while (1) {
if (skip_end_of_line) {
do {
c = getc(f);
} while (c != EOF && c != '\n');
if (c == EOF)
break;
disabled = FALSE;
skip_end_of_line = FALSE;
}
while ((c = getc(f)) != EOF && isspace(c)) {
if (c == '\n') {
continue;
}
}
if (c == EOF)
break;
if (c == '!') {
disabled = TRUE;
continue;
}
if (c != '@') {
skip_end_of_line = TRUE;
continue;
}
i = 0;
while (1) {
c = getc(f);
if (c == EOF || c == '@')
break;
if (i >= name_len) {
name_len *= 2;
name = (gchar *)g_realloc(name, name_len + 1);
}
name[i++] = c;
}
name[i] = '\0';
if (c == EOF) {
break;
} else if (i == 0) {
skip_end_of_line = TRUE;
continue;
}
i = 0;
while (1) {
c = getc(f);
if (c == EOF || c == '@')
break;
if (i >= filter_exp_len) {
filter_exp_len *= 2;
filter_exp = (gchar *)g_realloc(filter_exp, filter_exp_len + 1);
}
filter_exp[i++] = c;
}
filter_exp[i] = '\0';
if (c == EOF) {
break;
} else if (i == 0) {
skip_end_of_line = TRUE;
continue;
}
if (fscanf(f,"[%hu,%hu,%hu][%hu,%hu,%hu]",
&bg_r, &bg_g, &bg_b, &fg_r, &fg_g, &fg_b) == 6) {
color_t bg_color, fg_color;
color_filter_t *colorf;
dfilter_t *temp_dfilter;
if (!dfilter_compile(filter_exp, &temp_dfilter)) {
g_warning("Could not compile color filter \"%s\" from saved filters: %s",
name, dfilter_error_msg);
skip_end_of_line = TRUE;
continue;
}
if (!initialize_color(&fg_color, fg_r, fg_g, fg_b)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not allocate foreground color "
"specified in input file for %s.", name);
dfilter_free(temp_dfilter);
skip_end_of_line = TRUE;
continue;
}
if (!initialize_color(&bg_color, bg_r, bg_g, bg_b)) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not allocate background color "
"specified in input file for %s.", name);
dfilter_free(temp_dfilter);
skip_end_of_line = TRUE;
continue;
}
colorf = color_filter_new(name, filter_exp, &bg_color,
&fg_color, disabled);
if(user_data == &color_filter_list) {
GSList **cfl = (GSList **)user_data;
colorf->c_colorfilter = temp_dfilter;
*cfl = g_slist_append(*cfl, colorf);
} else {
dfilter_free(temp_dfilter);
color_filter_add_cb (colorf, user_data);
}
}
skip_end_of_line = TRUE;
}
g_free(name);
g_free(filter_exp);
return TRUE;
}
static gboolean
read_users_filters(GSList **cfl)
{
gchar *path;
FILE *f;
gboolean ret;
path = get_persconffile_path("colorfilters", TRUE);
if ((f = ws_fopen(path, "r")) == NULL) {
if (errno != ENOENT) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not open filter file\n\"%s\": %s.", path,
g_strerror(errno));
}
g_free(path);
return FALSE;
}
g_free(path);
path = NULL;
ret = read_filters_file(f, cfl);
fclose(f);
return ret;
}
gboolean
color_filters_read_globals(gpointer user_data)
{
gchar *path;
FILE *f;
gboolean ret;
path = get_datafile_path("colorfilters");
if ((f = ws_fopen(path, "r")) == NULL) {
if (errno != ENOENT) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not open global filter file\n\"%s\": %s.", path,
g_strerror(errno));
}
g_free(path);
return FALSE;
}
g_free(path);
path = NULL;
ret = read_filters_file(f, user_data);
fclose(f);
return ret;
}
gboolean
color_filters_import(gchar *path, gpointer user_data)
{
FILE *f;
gboolean ret;
if ((f = ws_fopen(path, "r")) == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not open\n%s\nfor reading: %s.",
path, g_strerror(errno));
return FALSE;
}
ret = read_filters_file(f, user_data);
fclose(f);
return ret;
}
static void
write_filter(gpointer filter_arg, gpointer data_arg)
{
struct write_filter_data *data = (struct write_filter_data *)data_arg;
color_filter_t *colorf = (color_filter_t *)filter_arg;
FILE *f = data->f;
if ( (colorf->selected || !data->only_selected) &&
(strstr(colorf->filter_name,CONVERSATION_COLOR_PREFIX)==NULL) ) {
fprintf(f,"%s@%s@%s@[%d,%d,%d][%d,%d,%d]\n",
colorf->disabled ? "!" : "",
colorf->filter_name,
colorf->filter_text,
colorf->bg_color.red,
colorf->bg_color.green,
colorf->bg_color.blue,
colorf->fg_color.red,
colorf->fg_color.green,
colorf->fg_color.blue);
}
}
static gboolean
write_filters_file(GSList *cfl, FILE *f, gboolean only_selected)
{
struct write_filter_data data;
data.f = f;
data.only_selected = only_selected;
fprintf(f,"# DO NOT EDIT THIS FILE! It was created by Wireshark\n");
g_slist_foreach(cfl, write_filter, &data);
return TRUE;
}
gboolean
color_filters_write(GSList *cfl)
{
gchar *pf_dir_path;
gchar *path;
FILE *f;
if (create_persconffile_dir(&pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create directory\n\"%s\"\nfor color files: %s.",
pf_dir_path, g_strerror(errno));
g_free(pf_dir_path);
return FALSE;
}
path = get_persconffile_path("colorfilters", TRUE);
if ((f = ws_fopen(path, "w+")) == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not open\n%s\nfor writing: %s.",
path, g_strerror(errno));
g_free(path);
return FALSE;
}
g_free(path);
write_filters_file(cfl, f, FALSE);
fclose(f);
return TRUE;
}
gboolean
color_filters_export(gchar *path, GSList *cfl, gboolean only_marked)
{
FILE *f;
if ((f = ws_fopen(path, "w+")) == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Could not open\n%s\nfor writing: %s.",
path, g_strerror(errno));
return FALSE;
}
write_filters_file(cfl, f, only_marked);
fclose(f);
return TRUE;
}
