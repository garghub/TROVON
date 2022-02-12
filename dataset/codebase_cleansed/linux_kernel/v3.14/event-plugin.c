static void
load_plugin(struct pevent *pevent, const char *path,
const char *file, void *data)
{
struct plugin_list **plugin_list = data;
pevent_plugin_load_func func;
struct plugin_list *list;
const char *alias;
char *plugin;
void *handle;
plugin = malloc(strlen(path) + strlen(file) + 2);
if (!plugin) {
warning("could not allocate plugin memory\n");
return;
}
strcpy(plugin, path);
strcat(plugin, "/");
strcat(plugin, file);
handle = dlopen(plugin, RTLD_NOW | RTLD_GLOBAL);
if (!handle) {
warning("could not load plugin '%s'\n%s\n",
plugin, dlerror());
goto out_free;
}
alias = dlsym(handle, PEVENT_PLUGIN_ALIAS_NAME);
if (!alias)
alias = file;
func = dlsym(handle, PEVENT_PLUGIN_LOADER_NAME);
if (!func) {
warning("could not find func '%s' in plugin '%s'\n%s\n",
PEVENT_PLUGIN_LOADER_NAME, plugin, dlerror());
goto out_free;
}
list = malloc(sizeof(*list));
if (!list) {
warning("could not allocate plugin memory\n");
goto out_free;
}
list->next = *plugin_list;
list->handle = handle;
list->name = plugin;
*plugin_list = list;
pr_stat("registering plugin: %s", plugin);
func(pevent);
return;
out_free:
free(plugin);
}
static void
load_plugins_dir(struct pevent *pevent, const char *suffix,
const char *path,
void (*load_plugin)(struct pevent *pevent,
const char *path,
const char *name,
void *data),
void *data)
{
struct dirent *dent;
struct stat st;
DIR *dir;
int ret;
ret = stat(path, &st);
if (ret < 0)
return;
if (!S_ISDIR(st.st_mode))
return;
dir = opendir(path);
if (!dir)
return;
while ((dent = readdir(dir))) {
const char *name = dent->d_name;
if (strcmp(name, ".") == 0 ||
strcmp(name, "..") == 0)
continue;
if (strcmp(name + (strlen(name) - strlen(suffix)), suffix) != 0)
continue;
load_plugin(pevent, path, name, data);
}
closedir(dir);
}
static void
load_plugins(struct pevent *pevent, const char *suffix,
void (*load_plugin)(struct pevent *pevent,
const char *path,
const char *name,
void *data),
void *data)
{
char *home;
char *path;
char *envdir;
#ifdef PLUGIN_DIR
load_plugins_dir(pevent, suffix, PLUGIN_DIR, load_plugin, data);
#endif
envdir = getenv("TRACEEVENT_PLUGIN_DIR");
if (envdir)
load_plugins_dir(pevent, suffix, envdir, load_plugin, data);
home = getenv("HOME");
if (!home)
return;
path = malloc(strlen(home) + strlen(LOCAL_PLUGIN_DIR) + 2);
if (!path) {
warning("could not allocate plugin memory\n");
return;
}
strcpy(path, home);
strcat(path, "/");
strcat(path, LOCAL_PLUGIN_DIR);
load_plugins_dir(pevent, suffix, path, load_plugin, data);
free(path);
}
struct plugin_list*
traceevent_load_plugins(struct pevent *pevent)
{
struct plugin_list *list = NULL;
load_plugins(pevent, ".so", load_plugin, &list);
return list;
}
void
traceevent_unload_plugins(struct plugin_list *plugin_list, struct pevent *pevent)
{
pevent_plugin_unload_func func;
struct plugin_list *list;
while (plugin_list) {
list = plugin_list;
plugin_list = list->next;
func = dlsym(list->handle, PEVENT_PLUGIN_UNLOADER_NAME);
if (func)
func(pevent);
dlclose(list->handle);
free(list->name);
free(list);
}
}
