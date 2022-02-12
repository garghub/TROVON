static GList *
add_filter_entry(GList *fl, const char *filt_name, const char *filt_expr)
{
filter_def *filt;
filt = (filter_def *) g_malloc(sizeof(filter_def));
filt->name = g_strdup(filt_name);
filt->strval = g_strdup(filt_expr);
return g_list_append(fl, filt);
}
static GList *
remove_filter_entry(GList *fl, GList *fl_entry)
{
filter_def *filt;
filt = (filter_def *) fl_entry->data;
g_free(filt->name);
g_free(filt->strval);
g_free(filt);
return g_list_remove_link(fl, fl_entry);
}
void
read_filter_list(filter_list_type_t list_type, char **pref_path_return,
int *errno_return)
{
const char *ff_name;
char *ff_path;
FILE *ff;
GList **flpp;
int c;
char *filt_name, *filt_expr;
int filt_name_len, filt_expr_len;
int filt_name_index, filt_expr_index;
int line = 1;
*pref_path_return = NULL;
switch (list_type) {
case CFILTER_LIST:
ff_name = CFILTER_FILE_NAME;
flpp = &capture_filters;
break;
case DFILTER_LIST:
ff_name = DFILTER_FILE_NAME;
flpp = &display_filters;
break;
default:
g_assert_not_reached();
return;
}
ff_path = get_persconffile_path(ff_name, TRUE);
if ((ff = ws_fopen(ff_path, "r")) == NULL) {
if (errno != ENOENT) {
*pref_path_return = ff_path;
*errno_return = errno;
return;
}
g_free(ff_path);
ff_path = get_persconffile_path(FILTER_FILE_NAME, FALSE);
if ((ff = ws_fopen(ff_path, "r")) == NULL) {
if (errno != ENOENT) {
*pref_path_return = ff_path;
*errno_return = errno;
return;
}
g_free(ff_path);
ff_path = get_datafile_path(ff_name);
if ((ff = ws_fopen(ff_path, "r")) == NULL) {
if (errno != ENOENT) {
*pref_path_return = ff_path;
*errno_return = errno;
} else {
g_free(ff_path);
}
return;
}
}
}
while(*flpp) {
*flpp = remove_filter_entry(*flpp, g_list_first(*flpp));
}
filt_name_len = INIT_BUF_SIZE;
filt_name = (char *)g_malloc(filt_name_len + 1);
filt_expr_len = INIT_BUF_SIZE;
filt_expr = (char *)g_malloc(filt_expr_len + 1);
for (line = 1; ; line++) {
while ((c = getc(ff)) != EOF && isspace(c)) {
if (c == '\n') {
continue;
}
}
if (c == EOF)
break;
if (c != '"') {
g_warning("'%s' line %d doesn't have a quoted filter name.", ff_path,
line);
while (c != '\n')
c = getc(ff);
continue;
}
filt_name_index = 0;
for (;;) {
c = getc(ff);
if (c == EOF || c == '\n')
break;
if (c == '"') {
if (filt_name_index >= filt_name_len) {
filt_name_len *= 2;
filt_name = (char *)g_realloc(filt_name, filt_name_len + 1);
}
filt_name[filt_name_index] = '\0';
break;
}
if (c == '\\') {
c = getc(ff);
if (c == EOF || c == '\n')
break;
}
if (filt_name_index >= filt_name_len) {
filt_name_len *= 2;
filt_name = (char *)g_realloc(filt_name, filt_name_len + 1);
}
filt_name[filt_name_index] = c;
filt_name_index++;
}
if (c == EOF) {
if (!ferror(ff)) {
g_warning("'%s' line %d doesn't have a newline.", ff_path,
line);
}
break;
}
if (c != '"') {
g_warning("'%s' line %d doesn't have a closing quote.", ff_path,
line);
continue;
}
while ((c = getc(ff)) != EOF && isspace(c)) {
if (c == '\n')
break;
}
if (c == EOF) {
if (!ferror(ff)) {
g_warning("'%s' line %d doesn't have a newline.", ff_path,
line);
}
break;
}
if (c == '\n') {
g_warning("'%s' line %d doesn't have a filter expression.", ff_path,
line);
continue;
}
filt_expr_index = 0;
for (;;) {
if (filt_expr_index >= filt_expr_len) {
filt_expr_len *= 2;
filt_expr = (char *)g_realloc(filt_expr, filt_expr_len + 1);
}
filt_expr[filt_expr_index] = c;
filt_expr_index++;
c = getc(ff);
if (c == EOF || c == '\n')
break;
}
if (c == EOF) {
if (!ferror(ff)) {
g_warning("'%s' line %d doesn't have a newline.", ff_path,
line);
}
break;
}
if (filt_expr_index >= filt_expr_len) {
filt_expr_len *= 2;
filt_expr = (char *)g_realloc(filt_expr, filt_expr_len + 1);
}
filt_expr[filt_expr_index] = '\0';
*flpp = add_filter_entry(*flpp, filt_name, filt_expr);
}
if (ferror(ff)) {
*pref_path_return = ff_path;
*errno_return = errno;
} else
g_free(ff_path);
fclose(ff);
g_free(filt_name);
g_free(filt_expr);
switch (list_type) {
case CFILTER_LIST:
copy_filter_list(CFILTER_EDITED_LIST, CFILTER_LIST);
break;
case DFILTER_LIST:
copy_filter_list(DFILTER_EDITED_LIST, DFILTER_LIST);
break;
default:
g_assert_not_reached();
return;
}
}
static GList **
get_filter_list(filter_list_type_t list_type)
{
GList **flpp;
switch (list_type) {
case CFILTER_LIST:
flpp = &capture_filters;
break;
case DFILTER_LIST:
flpp = &display_filters;
break;
case CFILTER_EDITED_LIST:
flpp = &capture_edited_filters;
break;
case DFILTER_EDITED_LIST:
flpp = &display_edited_filters;
break;
default:
g_assert_not_reached();
flpp = NULL;
}
return flpp;
}
GList *
get_filter_list_first(filter_list_type_t list_type)
{
GList **flpp;
flpp = get_filter_list(list_type);
return g_list_first(*flpp);
}
GList *
add_to_filter_list(filter_list_type_t list_type, const char *name,
const char *expression)
{
GList **flpp;
flpp = get_filter_list(list_type);
*flpp = add_filter_entry(*flpp, name, expression);
return g_list_last(*flpp);
}
void
remove_from_filter_list(filter_list_type_t list_type, GList *fl_entry)
{
GList **flpp;
flpp = get_filter_list(list_type);
*flpp = remove_filter_entry(*flpp, fl_entry);
}
void
save_filter_list(filter_list_type_t list_type, char **pref_path_return,
int *errno_return)
{
const gchar *ff_name;
gchar *ff_path, *ff_path_new;
GList *fl;
GList *flpp;
filter_def *filt;
FILE *ff;
guchar *p, c;
*pref_path_return = NULL;
switch (list_type) {
case CFILTER_LIST:
ff_name = CFILTER_FILE_NAME;
fl = capture_filters;
break;
case DFILTER_LIST:
ff_name = DFILTER_FILE_NAME;
fl = display_filters;
break;
default:
g_assert_not_reached();
return;
}
ff_path = get_persconffile_path(ff_name, TRUE);
ff_path_new = g_strdup_printf("%s.new", ff_path);
if ((ff = ws_fopen(ff_path_new, "w")) == NULL) {
*pref_path_return = ff_path;
*errno_return = errno;
g_free(ff_path_new);
return;
}
flpp = g_list_first(fl);
while (flpp) {
filt = (filter_def *) flpp->data;
putc('"', ff);
for (p = (guchar *)filt->name; (c = *p) != '\0'; p++) {
if (c == '"' || c == '\\')
putc('\\', ff);
putc(c, ff);
}
putc('"', ff);
putc(' ', ff);
fprintf(ff, "%s\n", filt->strval);
if (ferror(ff)) {
*pref_path_return = ff_path;
*errno_return = errno;
fclose(ff);
ws_unlink(ff_path_new);
g_free(ff_path_new);
return;
}
flpp = flpp->next;
}
if (fclose(ff) == EOF) {
*pref_path_return = ff_path;
*errno_return = errno;
ws_unlink(ff_path_new);
g_free(ff_path_new);
return;
}
#ifdef _WIN32
if (ws_remove(ff_path) < 0 && errno != ENOENT) {
*pref_path_return = ff_path;
*errno_return = errno;
ws_unlink(ff_path_new);
g_free(ff_path_new);
return;
}
#endif
if (ws_rename(ff_path_new, ff_path) < 0) {
*pref_path_return = ff_path;
*errno_return = errno;
ws_unlink(ff_path_new);
g_free(ff_path_new);
return;
}
g_free(ff_path_new);
g_free(ff_path);
}
void copy_filter_list(filter_list_type_t dest_type, filter_list_type_t src_type)
{
GList **flpp_dest;
GList **flpp_src;
GList *flp_src;
filter_def *filt;
g_assert(dest_type != src_type);
flpp_dest = get_filter_list(dest_type);
flpp_src = get_filter_list(src_type);
while(*flpp_dest) {
*flpp_dest = remove_filter_entry(*flpp_dest, g_list_first(*flpp_dest));
}
g_assert(g_list_length(*flpp_dest) == 0);
for(flp_src = g_list_first(*flpp_src); flp_src; flp_src = g_list_next(flp_src)) {
filt = (filter_def *)(flp_src->data);
*flpp_dest = add_filter_entry(*flpp_dest, filt->name, filt->strval);
}
}
