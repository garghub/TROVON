GList * current_profile_list(void) {
return g_list_first(current_profiles);
}
GList * edited_profile_list(void) {
return g_list_first(edited_profiles);
}
static GList *
add_profile_entry(GList *fl, const char *profilename, const char *reference, int status,
gboolean is_global, gboolean from_global)
{
profile_def *profile;
profile = (profile_def *) g_malloc0(sizeof(profile_def));
profile->name = g_strdup(profilename);
profile->reference = g_strdup(reference);
profile->status = status;
profile->is_global = is_global;
profile->from_global = from_global;
return g_list_append(fl, profile);
}
static GList *
remove_profile_entry(GList *fl, GList *fl_entry)
{
profile_def *profile;
profile = (profile_def *) fl_entry->data;
g_free(profile->name);
g_free(profile->reference);
g_free(profile);
return g_list_remove_link(fl, fl_entry);
}
const gchar *
get_profile_parent (const gchar *profilename)
{
GList *fl_entry = g_list_first(edited_profiles);
guint no_edited = g_list_length(edited_profiles);
profile_def *profile;
guint i;
if (fl_entry) {
for (i = 0; i < no_edited; i++) {
while (fl_entry) {
profile = (profile_def *) fl_entry->data;
if (strcmp (profile->name, profilename) == 0) {
if ((profile->status == PROF_STAT_NEW) ||
(profile->reference == NULL)) {
return NULL;
} else {
profilename = profile->reference;
}
}
fl_entry = g_list_next(fl_entry);
}
fl_entry = g_list_first(edited_profiles);
}
}
return profilename;
}
const gchar *apply_profile_changes(void) {
char *pf_dir_path, *pf_dir_path2, *pf_filename;
GList *fl1, *fl2;
profile_def *profile1, *profile2;
gboolean found;
emem_strbuf_t *message = ep_strbuf_new(NULL);
const gchar *err_msg;
fl1 = edited_profile_list();
while (fl1) {
profile1 = (profile_def *) fl1->data;
g_strstrip(profile1->name);
if ((err_msg = profile_name_is_valid(profile1->name)) != NULL) {
ep_strbuf_printf(message, "%s", err_msg);
return message->str;
}
fl1 = g_list_next(fl1);
}
fl1 = edited_profile_list();
while (fl1) {
profile1 = (profile_def *) fl1->data;
g_strstrip(profile1->name);
if (profile1->status == PROF_STAT_COPY) {
if (create_persconffile_profile(profile1->name, &pf_dir_path) == -1) {
ep_strbuf_printf(message,
"Can't create directory\n\"%s\":\n%s.",
pf_dir_path, g_strerror(errno));
g_free(pf_dir_path);
}
profile1->status = PROF_STAT_EXISTS;
if (profile1->reference) {
if (copy_persconffile_profile(profile1->name, profile1->reference, profile1->from_global,
&pf_filename, &pf_dir_path, &pf_dir_path2) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't copy file \"%s\" in directory\n\"%s\" to\n\"%s\":\n%s.",
pf_filename, pf_dir_path2, pf_dir_path, g_strerror(errno));
g_free(pf_filename);
g_free(pf_dir_path);
g_free(pf_dir_path2);
}
}
g_free (profile1->reference);
profile1->reference = g_strdup(profile1->name);
}
fl1 = g_list_next(fl1);
}
fl1 = edited_profile_list();
while (fl1) {
profile1 = (profile_def *) fl1->data;
g_strstrip(profile1->name);
if (profile1->status == PROF_STAT_NEW) {
if (strcmp(profile1->name, DEFAULT_PROFILE)!=0) {
if (create_persconffile_profile(profile1->name, &pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create directory\n\"%s\":\n%s.",
pf_dir_path, g_strerror(errno));
g_free(pf_dir_path);
}
profile1->status = PROF_STAT_EXISTS;
g_free (profile1->reference);
profile1->reference = g_strdup(profile1->name);
}
} else if (profile1->status == PROF_STAT_CHANGED) {
if (strcmp(profile1->reference, profile1->name)!=0) {
if (rename_persconffile_profile(profile1->reference, profile1->name,
&pf_dir_path, &pf_dir_path2) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't rename directory\n\"%s\" to\n\"%s\":\n%s.",
pf_dir_path, pf_dir_path2, g_strerror(errno));
g_free(pf_dir_path);
g_free(pf_dir_path2);
}
profile1->status = PROF_STAT_EXISTS;
g_free (profile1->reference);
profile1->reference = g_strdup(profile1->name);
}
}
fl1 = g_list_next(fl1);
}
fl1 = current_profile_list();
while (fl1) {
found = FALSE;
profile1 = (profile_def *) fl1->data;
fl2 = edited_profile_list();
while (fl2) {
profile2 = (profile_def *) fl2->data;
if (!profile2->is_global) {
if (strcmp(profile1->name, profile2->name)==0) {
found = TRUE;
} else if (strcmp(profile1->name, profile2->reference)==0) {
found = TRUE;
}
}
fl2 = g_list_next(fl2);
}
if (!found) {
if (delete_persconffile_profile(profile1->name, &pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't delete profile directory\n\"%s\":\n%s.",
pf_dir_path, g_strerror(errno));
g_free(pf_dir_path);
}
}
fl1 = g_list_next(fl1);
}
copy_profile_list();
return NULL;
}
GList *
add_to_profile_list(const char *name, const char *expression, int status,
gboolean is_global, gboolean from_global)
{
edited_profiles = add_profile_entry(edited_profiles, name, expression, status,
is_global, from_global);
return g_list_last(edited_profiles);
}
void
remove_from_profile_list(GList *fl_entry)
{
edited_profiles = remove_profile_entry(edited_profiles, fl_entry);
}
void
empty_profile_list(gboolean edit_list)
{
GList **flpp;
if (edit_list) {
flpp = &edited_profiles;
while(*flpp) {
*flpp = remove_profile_entry(*flpp, g_list_first(*flpp));
}
g_assert(g_list_length(*flpp) == 0);
}
flpp = &current_profiles;
while(*flpp) {
*flpp = remove_profile_entry(*flpp, g_list_first(*flpp));
}
g_assert(g_list_length(*flpp) == 0);
}
void
copy_profile_list(void)
{
GList *flp_src;
profile_def *profile;
flp_src = edited_profiles;
empty_profile_list(FALSE);
while(flp_src) {
profile = (profile_def *)(flp_src)->data;
current_profiles = add_profile_entry(current_profiles, profile->name,
profile->reference, profile->status,
profile->is_global, profile->from_global);
flp_src = g_list_next(flp_src);
}
}
void
init_profile_list(void)
{
WS_DIR *dir;
WS_DIRENT *file;
const gchar *profiles_dir, *name;
gchar *filename;
empty_profile_list(TRUE);
add_to_profile_list(DEFAULT_PROFILE, DEFAULT_PROFILE, PROF_STAT_DEFAULT, FALSE, FALSE);
profiles_dir = get_profiles_dir();
if ((dir = ws_dir_open(profiles_dir, 0, NULL)) != NULL) {
while ((file = ws_dir_read_name(dir)) != NULL) {
name = ws_dir_get_name(file);
filename = g_strdup_printf ("%s%s%s", profiles_dir, G_DIR_SEPARATOR_S, name);
if (test_for_directory(filename) == EISDIR) {
add_to_profile_list(name, name, PROF_STAT_EXISTS, FALSE, FALSE);
}
g_free (filename);
}
ws_dir_close (dir);
}
profiles_dir = get_global_profiles_dir();
if ((dir = ws_dir_open(profiles_dir, 0, NULL)) != NULL) {
while ((file = ws_dir_read_name(dir)) != NULL) {
name = ws_dir_get_name(file);
filename = g_strdup_printf ("%s%s%s", profiles_dir, G_DIR_SEPARATOR_S, name);
if (test_for_directory(filename) == EISDIR) {
add_to_profile_list(name, name, PROF_STAT_EXISTS, TRUE, TRUE);
}
g_free (filename);
}
ws_dir_close (dir);
}
copy_profile_list ();
}
const gchar *
profile_name_is_valid(const gchar *name)
{
gchar *reason = NULL;
emem_strbuf_t *message = ep_strbuf_new(NULL);
#ifdef _WIN32
char *invalid_dir_char = "\\/:*?\"<>|";
gboolean invalid = FALSE;
int i;
for (i = 0; i < 9; i++) {
if (strchr(name, invalid_dir_char[i])) {
invalid = TRUE;
}
}
if (name[0] == '.' || name[strlen(name)-1] == '.') {
invalid = TRUE;
}
if (invalid) {
reason = g_strdup_printf("start or end with period (.), or contain any of the following characters:\n"
" \\ / : * ? \" &lt; &gt; |");
}
#else
if (strchr(name, '/')) {
reason = g_strdup_printf("contain the '/' character.");
}
#endif
if (reason) {
ep_strbuf_printf(message, "A profile name cannot %s\nProfiles unchanged.", reason);
g_free(reason);
return message->str;
}
return NULL;
}
gboolean delete_current_profile(void) {
const gchar *name = get_profile_name();
char *pf_dir_path;
if (profile_exists(name, FALSE) && strcmp (name, DEFAULT_PROFILE) != 0) {
if (delete_persconffile_profile(name, &pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't delete profile directory\n\"%s\":\n%s.",
pf_dir_path, g_strerror(errno));
g_free(pf_dir_path);
} else {
return TRUE;
}
}
return FALSE;
}
