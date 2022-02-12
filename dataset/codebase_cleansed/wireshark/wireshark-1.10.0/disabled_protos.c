static void
discard_existing_list (GList **flp)
{
GList *fl_ent;
protocol_def *prot;
if (*flp != NULL) {
fl_ent = g_list_first(*flp);
while (fl_ent != NULL) {
prot = (protocol_def *) fl_ent->data;
g_free(prot->name);
g_free(prot);
fl_ent = fl_ent->next;
}
g_list_free(*flp);
*flp = NULL;
}
}
void
read_disabled_protos_list(char **gpath_return, int *gopen_errno_return,
int *gread_errno_return,
char **path_return, int *open_errno_return,
int *read_errno_return)
{
int err;
char *gff_path, *ff_path;
FILE *ff;
gff_path = get_datafile_path(GLOBAL_PROTOCOLS_FILE_NAME);
discard_existing_list (&global_disabled_protos);
*gpath_return = NULL;
if ((ff = ws_fopen(gff_path, "r")) != NULL) {
err = read_disabled_protos_list_file(gff_path, ff,
&global_disabled_protos);
if (err != 0) {
*gopen_errno_return = 0;
*gread_errno_return = err;
*gpath_return = gff_path;
} else
g_free(gff_path);
fclose(ff);
} else {
if (errno != ENOENT) {
*gopen_errno_return = errno;
*gread_errno_return = 0;
*gpath_return = gff_path;
} else
g_free(gff_path);
}
ff_path = get_persconffile_path(PROTOCOLS_FILE_NAME, TRUE);
discard_existing_list (&disabled_protos);
*path_return = NULL;
if ((ff = ws_fopen(ff_path, "r")) != NULL) {
err = read_disabled_protos_list_file(ff_path, ff, &disabled_protos);
if (err != 0) {
*open_errno_return = 0;
*read_errno_return = err;
*path_return = ff_path;
} else
g_free(ff_path);
fclose(ff);
} else {
if (errno != ENOENT) {
*open_errno_return = errno;
*read_errno_return = 0;
*path_return = ff_path;
} else
g_free(ff_path);
}
}
static int
read_disabled_protos_list_file(const char *ff_path, FILE *ff,
GList **flp)
{
protocol_def *prot;
int c;
char *prot_name;
int prot_name_len;
int prot_name_index;
int line = 1;
prot_name_len = INIT_BUF_SIZE;
prot_name = (char *)g_malloc(prot_name_len + 1);
for (line = 1; ; line++) {
while ((c = getc(ff)) != EOF && isspace(c)) {
if (c == '\n') {
continue;
}
}
if (c == EOF) {
if (ferror(ff))
goto error;
else
break;
}
ungetc(c, ff);
prot_name_index = 0;
for (;;) {
c = getc(ff);
if (c == EOF)
break;
if (isspace(c))
break;
if (c == '#')
break;
if (prot_name_index >= prot_name_len) {
prot_name_len *= 2;
prot_name = (char *)g_realloc(prot_name, prot_name_len + 1);
}
prot_name[prot_name_index] = c;
prot_name_index++;
}
if (isspace(c) && c != '\n') {
while ((c = getc(ff)) != EOF && c != '\n' && isspace(c))
;
if (c != EOF && c != '\n' && c != '#') {
g_warning("'%s' line %d has extra stuff after the protocol name.",
ff_path, line);
}
}
if (c != EOF && c != '\n') {
while ((c = getc(ff)) != EOF && c != '\n')
;
}
if (c == EOF) {
if (ferror(ff))
goto error;
else {
g_warning("'%s' line %d doesn't have a newline.", ff_path,
line);
}
break;
}
if (prot_name_index >= prot_name_len) {
prot_name_len *= 2;
prot_name = (char *)g_realloc(prot_name, prot_name_len + 1);
}
prot_name[prot_name_index] = '\0';
prot = (protocol_def *) g_malloc(sizeof(protocol_def));
prot->name = g_strdup(prot_name);
*flp = g_list_append(*flp, prot);
}
g_free(prot_name);
return 0;
error:
return errno;
}
void
set_disabled_protos_list(void)
{
gint i;
GList *fl_ent;
protocol_def *prot;
if (disabled_protos == NULL)
goto skip;
fl_ent = g_list_first(disabled_protos);
while (fl_ent != NULL) {
prot = (protocol_def *) fl_ent->data;
i = proto_get_id_by_filter_name(prot->name);
if (i == -1) {
} else {
if (proto_can_toggle_protocol(i))
proto_set_decoding(i, FALSE);
}
fl_ent = fl_ent->next;
}
skip:
if (global_disabled_protos == NULL)
return;
fl_ent = g_list_first(global_disabled_protos);
while (fl_ent != NULL) {
prot = (protocol_def *) fl_ent->data;
i = proto_get_id_by_filter_name(prot->name);
if (i == -1) {
} else {
if (proto_can_toggle_protocol(i)) {
proto_set_decoding(i, FALSE);
proto_set_cant_toggle(i);
}
}
fl_ent = fl_ent->next;
}
}
void
save_disabled_protos_list(char **pref_path_return, int *errno_return)
{
gchar *ff_path, *ff_path_new;
FILE *ff;
gint i;
protocol_t *protocol;
void *cookie;
*pref_path_return = NULL;
ff_path = get_persconffile_path(PROTOCOLS_FILE_NAME, TRUE);
ff_path_new = g_strdup_printf("%s.new", ff_path);
if ((ff = ws_fopen(ff_path_new, "w")) == NULL) {
*pref_path_return = ff_path;
*errno_return = errno;
g_free(ff_path_new);
return;
}
for (i = proto_get_first_protocol(&cookie); i != -1;
i = proto_get_next_protocol(&cookie)) {
if (!proto_can_toggle_protocol(i)) {
continue;
}
protocol = find_protocol_by_id(i);
if (proto_is_protocol_enabled(protocol)) {
continue;
}
fprintf(ff, "%s\n", proto_get_protocol_filter_name(i));
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
