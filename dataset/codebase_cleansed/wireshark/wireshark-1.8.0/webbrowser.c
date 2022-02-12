gboolean
browser_needs_pref(void)
{
#ifdef MUST_LAUNCH_BROWSER_OURSELVES
return TRUE;
#else
return FALSE;
#endif
}
gboolean
browser_open_url (const gchar *url)
{
#if defined(G_OS_WIN32)
return ((gint) ShellExecute (HWND_DESKTOP, _T("open"), utf_8to16(url), NULL, NULL, SW_SHOWNORMAL) > 32);
#elif defined(HAVE_OS_X_FRAMEWORKS)
CFStringRef url_CFString;
CFURLRef url_CFURL;
OSStatus status;
url_CFString = CFStringCreateWithCString(NULL, url, kCFStringEncodingASCII);
if (url_CFString == NULL)
return (FALSE);
url_CFURL = CFURLCreateWithString(NULL, url_CFString, NULL);
CFRelease(url_CFString);
if (url_CFURL == NULL) {
return (FALSE);
}
status = LSOpenCFURLRef(url_CFURL, NULL);
CFRelease(url_CFURL);
return (status == 0);
#elif defined(HAVE_XDG_OPEN)
GError *error = NULL;
gchar *argv[3];
gboolean retval;
g_return_val_if_fail (url != NULL, FALSE);
argv[0] = "xdg-open";
argv[1] = (char *)url;
argv[2] = NULL;
retval = g_spawn_async (NULL, argv, NULL,
G_SPAWN_SEARCH_PATH,
NULL, NULL,
NULL, &error);
if (! retval)
{
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"%sCould not execute xdg-open: %s\n\n\"%s\"",
simple_dialog_primary_start(), simple_dialog_primary_end(),
error->message);
g_error_free (error);
}
return retval;
#elif defined(MUST_LAUNCH_BROWSER_OURSELVES)
GError *error = NULL;
gchar *browser;
gchar *argument;
gchar *cmd;
gchar **argv;
gboolean retval;
g_return_val_if_fail (url != NULL, FALSE);
browser = g_strdup(prefs.gui_webbrowser);
if (browser == NULL || ! strlen (browser))
{
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Web browser not specified.\n"
"Please correct the web browser setting in the Preferences dialog.");
g_free (browser);
return FALSE;
}
argument = g_shell_quote (url);
if (strstr (browser, "%s"))
cmd = strreplace (browser, "%s", argument);
else
cmd = g_strconcat (browser, " ", argument, NULL);
g_free (argument);
if (! g_shell_parse_argv (cmd, NULL, &argv, &error))
{
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"%sCould not parse web browser command: \"%s\"%s\n\n\"%s\"\n\n%s",
simple_dialog_primary_start(), browser, simple_dialog_primary_end(),
error->message,
"Please correct the web browser setting in the Preferences dialog.");
g_error_free (error);
return FALSE;
}
retval = g_spawn_async (NULL, argv, NULL,
G_SPAWN_SEARCH_PATH,
NULL, NULL,
NULL, &error);
if (! retval)
{
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"%sCould not execute web browser: \"%s\"%s\n\n\"%s\"\n\n%s",
simple_dialog_primary_start(), browser, simple_dialog_primary_end(),
error->message,
"Please correct the web browser setting in the Preferences dialog.");
g_error_free (error);
}
g_free (browser);
g_free (cmd);
g_strfreev (argv);
return retval;
#endif
}
gchar *
filename2uri(const gchar *filename)
{
int i = 0;
gchar *file_tmp;
GString *filestr;
filestr = g_string_sized_new(200);
for(i=0; filename[i]; i++) {
switch(filename[i]) {
case(' '):
g_string_append(filestr, "%20");
break;
case('%'):
g_string_append(filestr, "%%");
break;
case('\\'):
g_string_append_c(filestr, '/');
break;
default:
g_string_append_c(filestr, filename[i]);
}
}
#ifdef G_OS_WIN32
g_string_prepend(filestr, "file:///");
#else
g_string_prepend(filestr, "file://");
#endif
file_tmp = filestr->str;
g_string_free(filestr, FALSE );
return file_tmp;
}
gboolean
filemanager_open_directory (const gchar *path)
{
#if defined(G_OS_WIN32)
gint ret;
gchar *xpath;
xpath = g_strconcat(path,
g_str_has_suffix(path, "\\") ? "" : "\\",
NULL);
ret = (gint) ShellExecute (HWND_DESKTOP, _T("explore"), utf_8to16(xpath), NULL, NULL, SW_SHOWNORMAL);
g_free(xpath);
return (ret > 32);
#elif defined(HAVE_OS_X_FRAMEWORKS)
CFStringRef path_CFString;
CFURLRef path_CFURL;
OSStatus status;
path_CFString = CFStringCreateWithCString(NULL, path, kCFStringEncodingUTF8);
if (path_CFString == NULL)
return (FALSE);
path_CFURL = CFURLCreateWithFileSystemPath(NULL, path_CFString,
kCFURLPOSIXPathStyle, true);
CFRelease(path_CFString);
if (path_CFURL == NULL) {
return (FALSE);
}
status = LSOpenCFURLRef(path_CFURL, NULL);
CFRelease(path_CFURL);
return (status == 0);
#elif defined(HAVE_XDG_OPEN)
GError *error = NULL;
gchar *argv[3];
gboolean retval;
g_return_val_if_fail (path != NULL, FALSE);
argv[0] = "xdg-open";
argv[1] = (char *)path;
argv[2] = NULL;
retval = g_spawn_async (NULL, argv, NULL,
G_SPAWN_SEARCH_PATH,
NULL, NULL,
NULL, &error);
if (! retval)
{
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"%sCould not execute xdg-open: %s\n\n\"%s\"",
simple_dialog_primary_start(), simple_dialog_primary_end(),
error->message);
g_error_free (error);
}
return retval;
#elif defined(MUST_LAUNCH_BROWSER_OURSELVES)
GError *error = NULL;
gchar *browser;
gchar *argument;
gchar *cmd;
gchar **argv;
gboolean retval;
g_return_val_if_fail (path != NULL, FALSE);
browser = g_strdup(prefs.gui_webbrowser);
if (browser == NULL || ! strlen (browser))
{
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"Web browser not specified.\n"
"Please correct the web browser setting in the Preferences dialog.");
g_free (browser);
return FALSE;
}
argument = filename2uri (path);
if (strstr (browser, "%s"))
cmd = strreplace (browser, "%s", argument);
else
cmd = g_strconcat (browser, " ", argument, NULL);
g_free (argument);
if (! g_shell_parse_argv (cmd, NULL, &argv, &error))
{
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"%sCould not parse web browser command: \"%s\"%s\n\n\"%s\"\n\n%s",
simple_dialog_primary_start(), browser, simple_dialog_primary_end(),
error->message,
"Please correct the web browser setting in the Preferences dialog.");
g_error_free (error);
return FALSE;
}
retval = g_spawn_async (NULL, argv, NULL,
G_SPAWN_SEARCH_PATH,
NULL, NULL,
NULL, &error);
if (! retval)
{
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"%sCould not execute web browser: \"%s\"%s\n\n\"%s\"\n\n%s",
simple_dialog_primary_start(), browser, simple_dialog_primary_end(),
error->message,
"Please correct the web browser setting in the Preferences dialog.");
g_error_free (error);
}
g_free (browser);
g_free (cmd);
g_strfreev (argv);
return retval;
#endif
}
static gchar*
strreplace (const gchar *string,
const gchar *delimiter,
const gchar *replacement)
{
gchar *ret;
gchar **tmp;
g_return_val_if_fail (string != NULL, NULL);
g_return_val_if_fail (delimiter != NULL, NULL);
g_return_val_if_fail (replacement != NULL, NULL);
tmp = g_strsplit (string, delimiter, 0);
ret = g_strjoinv (replacement, tmp);
g_strfreev (tmp);
return ret;
}
void
browser_open_data_file(const gchar *filename)
{
gchar *file_path;
gchar *uri;
#ifdef G_OS_WIN32
if((strlen(filename) > 2) && (filename[1] == ':'))
file_path = g_strdup(filename);
#else
if((strlen(filename) > 1) && (filename[0] == '/'))
file_path = g_strdup(filename);
#endif
else
file_path = g_strdup_printf("%s/%s", get_datafile_dir(), filename);
uri = filename2uri(file_path);
browser_open_url (uri);
g_free(file_path);
g_free(uri);
}
