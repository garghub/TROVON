static int
add_plugin(void *handle, gchar *name, gchar *version,
void (*register_protoinfo)(void),
void (*reg_handoff)(void),
void (*register_tap_listener)(void),
void (*register_wtap_module)(void),
void (*register_codec_module)(void))
{
plugin *new_plug, *pt_plug;
pt_plug = plugin_list;
if (!pt_plug)
{
new_plug = (plugin *)g_malloc(sizeof(plugin));
if (new_plug == NULL)
return ENOMEM;
plugin_list = new_plug;
}
else
{
while (1)
{
if (!strcmp(pt_plug->name, name) &&
!strcmp(pt_plug->version, version))
{
return EEXIST;
}
if (pt_plug->next == NULL)
break;
pt_plug = pt_plug->next;
}
new_plug = (plugin *)g_malloc(sizeof(plugin));
if (new_plug == NULL)
return ENOMEM;
pt_plug->next = new_plug;
}
new_plug->handle = handle;
new_plug->name = name;
new_plug->version = version;
new_plug->register_protoinfo = register_protoinfo;
new_plug->reg_handoff = reg_handoff;
new_plug->register_tap_listener = register_tap_listener;
new_plug->register_wtap_module = register_wtap_module;
new_plug->register_codec_module = register_codec_module;
new_plug->next = NULL;
return 0;
}
static void
plugins_scan_dir(const char *dirname)
{
#define FILENAME_LEN 1024
WS_DIR *dir;
WS_DIRENT *file;
const char *name;
gchar filename[FILENAME_LEN];
GModule *handle;
gchar *version;
gpointer gp;
void (*register_protoinfo)(void);
void (*reg_handoff)(void);
void (*register_tap_listener)(void);
void (*register_wtap_module)(void);
void (*register_codec_module)(void);
gchar *dot;
int cr;
if ((dir = ws_dir_open(dirname, 0, NULL)) != NULL)
{
while ((file = ws_dir_read_name(dir)) != NULL)
{
name = ws_dir_get_name(file);
dot = strrchr(name, '.');
if (dot == NULL || strcmp(dot+1, G_MODULE_SUFFIX) != 0)
continue;
g_snprintf(filename, FILENAME_LEN, "%s" G_DIR_SEPARATOR_S "%s",
dirname, name);
if ((handle = g_module_open(filename, 0)) == NULL)
{
report_failure("Couldn't load module %s: %s", filename,
g_module_error());
continue;
}
if (!g_module_symbol(handle, "version", &gp))
{
report_failure("The plugin %s has no version symbol", name);
g_module_close(handle);
continue;
}
version = gp;
if (g_module_symbol(handle, "plugin_register", &gp))
{
register_protoinfo = gp;
}
else
{
register_protoinfo = NULL;
}
if (g_module_symbol(handle, "plugin_reg_handoff", &gp))
{
reg_handoff = gp;
}
else
{
reg_handoff = NULL;
}
if (g_module_symbol(handle, "plugin_register_tap_listener", &gp))
{
register_tap_listener = gp;
}
else
{
register_tap_listener = NULL;
}
if (g_module_symbol(handle, "plugin_init", &gp))
{
if (register_protoinfo != NULL || register_tap_listener != NULL)
{
report_failure("The plugin '%s' has an old plugin init routine\nand a new register or register_tap_listener routine.",
name);
g_module_close(handle);
continue;
}
report_failure("The plugin '%s' has an old plugin init routine. Support has been dropped.\n Information on how to update your plugin is available at \nhttp://anonsvn.wireshark.org/wireshark/trunk/doc/README.plugins",
name);
g_module_close(handle);
continue;
}
if (g_module_symbol(handle, "register_wtap_module", &gp))
{
register_wtap_module = gp;
}
else
{
register_wtap_module = NULL;
}
if (g_module_symbol(handle, "register_codec_module", &gp))
{
register_codec_module = gp;
}
else
{
register_codec_module = NULL;
}
if (register_protoinfo == NULL &&
register_tap_listener == NULL &&
register_wtap_module == NULL &&
register_codec_module == NULL )
{
report_failure("The plugin '%s' has neither a register routine, "
"a register_tap_listener or a register_wtap_module or a register_codec_module routine",
name);
g_module_close(handle);
continue;
}
if ((cr = add_plugin(handle, g_strdup(name), version,
register_protoinfo, reg_handoff,
register_tap_listener,register_wtap_module,register_codec_module)))
{
if (cr == EEXIST)
fprintf(stderr, "The plugin %s, version %s\n"
"was found in multiple directories\n", name, version);
else
fprintf(stderr, "Memory allocation problem\n"
"when processing plugin %s, version %s\n",
name, version);
g_module_close(handle);
continue;
}
}
ws_dir_close(dir);
}
}
void
init_plugins(void)
{
const char *plugin_dir;
const char *name;
char *plugin_dir_path;
char *plugins_pers_dir;
WS_DIR *dir;
WS_DIRENT *file;
if (plugin_list == NULL)
{
plugin_dir = get_plugin_dir();
if (running_in_build_directory())
{
if ((dir = ws_dir_open(plugin_dir, 0, NULL)) != NULL)
{
while ((file = ws_dir_read_name(dir)) != NULL)
{
name = ws_dir_get_name(file);
if (strcmp(name, ".") == 0 || strcmp(name, "..") == 0)
continue;
plugin_dir_path = g_strdup_printf(
"%s" G_DIR_SEPARATOR_S "%s" G_DIR_SEPARATOR_S ".libs",
plugin_dir, name);
if (test_for_directory(plugin_dir_path) != EISDIR) {
g_free(plugin_dir_path);
plugin_dir_path = g_strdup_printf("%s" G_DIR_SEPARATOR_S "%s",
plugin_dir, name);
}
plugins_scan_dir(plugin_dir_path);
g_free(plugin_dir_path);
}
ws_dir_close(dir);
}
}
else
plugins_scan_dir(plugin_dir);
if (!started_with_special_privs())
{
plugins_pers_dir = get_plugins_pers_dir();
plugins_scan_dir(plugins_pers_dir);
g_free(plugins_pers_dir);
}
}
register_all_wiretap_modules();
register_all_codecs();
}
void
register_all_plugin_registrations(void)
{
plugin *pt_plug;
for (pt_plug = plugin_list; pt_plug != NULL; pt_plug = pt_plug->next)
{
if (pt_plug->register_protoinfo)
(pt_plug->register_protoinfo)();
}
}
void
register_all_plugin_handoffs(void)
{
plugin *pt_plug;
for (pt_plug = plugin_list; pt_plug != NULL; pt_plug = pt_plug->next)
{
if (pt_plug->reg_handoff)
(pt_plug->reg_handoff)();
}
}
void
register_all_plugin_tap_listeners(void)
{
plugin *pt_plug;
for (pt_plug = plugin_list; pt_plug != NULL; pt_plug = pt_plug->next)
{
if (pt_plug->register_tap_listener)
(pt_plug->register_tap_listener)();
}
}
void
register_all_wiretap_modules(void)
{
plugin *pt_plug;
for (pt_plug = plugin_list; pt_plug != NULL; pt_plug = pt_plug->next)
{
if (pt_plug->register_wtap_module)
(pt_plug->register_wtap_module)();
}
}
void
register_all_codecs(void)
{
plugin *pt_plug;
for (pt_plug = plugin_list; pt_plug != NULL; pt_plug = pt_plug->next)
{
if (pt_plug->register_codec_module)
(pt_plug->register_codec_module)();
}
}
void
plugins_dump_all(void)
{
#ifdef HAVE_PLUGINS
plugin *pt_plug;
const char *sep;
#endif
#ifdef HAVE_LUA_5_1
wslua_plugin *lua_plug;
#endif
#ifdef HAVE_PLUGINS
for (pt_plug = plugin_list; pt_plug != NULL; pt_plug = pt_plug->next)
{
sep = "";
printf("%s\t%s\t", pt_plug->name, pt_plug->version);
if (pt_plug->register_protoinfo)
{
printf("dissector");
sep = ", ";
}
if (pt_plug->register_tap_listener)
{
printf("%stap", sep);
sep = ", ";
}
if (pt_plug->register_wtap_module)
{
printf("%sfile format", sep);
sep = ", ";
}
if (pt_plug->register_codec_module)
{
printf("%scodec", sep);
}
printf("\t%s\n", g_module_name(pt_plug->handle));
}
#endif
#ifdef HAVE_LUA_5_1
for (lua_plug = wslua_plugin_list; lua_plug != NULL; lua_plug = lua_plug->next)
{
printf("%s\t%s\tlua script\t%s\n", lua_plug->name, lua_plug->version, lua_plug->filename);
}
#endif
}
