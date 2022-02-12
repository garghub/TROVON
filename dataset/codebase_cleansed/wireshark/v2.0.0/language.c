static prefs_set_pref_e
read_language_pref(gchar *key, const gchar *value,
void *private_data _U_, gboolean return_range_errors _U_)
{
if (strcmp(key, LANGUAGE_PREF_LANGUAGE) == 0) {
if (language)
g_free(language);
if (!value || (value && !*value))
language = g_strdup("auto");
else
language = g_strdup(value);
}
return PREFS_SET_OK;
}
void
read_language_prefs(void)
{
char *rf_path;
FILE *rf;
rf_path = get_persconffile_path(LANGUAGE_FILE_NAME, FALSE);
if ((rf = ws_fopen(rf_path, "r")) != NULL) {
read_prefs_file(rf_path, rf, read_language_pref, NULL);
fclose(rf);
}
g_free(rf_path);
}
gboolean
write_language_prefs(void)
{
char *pf_dir_path;
char *rf_path;
FILE *rf;
if (create_persconffile_dir(&pf_dir_path) == -1) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't create directory\n\"%s\"\nfor language file: %s.", pf_dir_path,
g_strerror(errno));
g_free(pf_dir_path);
return FALSE;
}
rf_path = get_persconffile_path(LANGUAGE_FILE_NAME, FALSE);
if ((rf = ws_fopen(rf_path, "w")) == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"Can't open recent file\n\"%s\": %s.", rf_path,
g_strerror(errno));
g_free(rf_path);
return FALSE;
}
g_free(rf_path);
fputs("# Language settings file for Wireshark " VERSION ".\n"
"#\n"
"# This file is regenerated each time Wireshark is quit.\n"
"# So be careful, if you want to make manual changes here.\n"
"\n", rf);
fprintf(rf, LANGUAGE_PREF_LANGUAGE ": %s\n", language);
fclose(rf);
return TRUE;
}
