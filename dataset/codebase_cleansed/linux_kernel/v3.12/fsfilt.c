static struct fsfilt_operations *fsfilt_search_type(const char *type)
{
struct fsfilt_operations *found;
struct list_head *p;
list_for_each(p, &fsfilt_types) {
found = list_entry(p, struct fsfilt_operations, fs_list);
if (!strcmp(found->fs_type, type)) {
return found;
}
}
return NULL;
}
int fsfilt_register_ops(struct fsfilt_operations *fs_ops)
{
struct fsfilt_operations *found;
if ((found = fsfilt_search_type(fs_ops->fs_type))) {
if (found != fs_ops) {
CERROR("different operations for type %s\n",
fs_ops->fs_type);
return -EEXIST;
}
} else {
try_module_get(THIS_MODULE);
list_add(&fs_ops->fs_list, &fsfilt_types);
}
return 0;
}
void fsfilt_unregister_ops(struct fsfilt_operations *fs_ops)
{
struct list_head *p;
list_for_each(p, &fsfilt_types) {
struct fsfilt_operations *found;
found = list_entry(p, typeof(*found), fs_list);
if (found == fs_ops) {
list_del(p);
module_put(THIS_MODULE);
break;
}
}
}
struct fsfilt_operations *fsfilt_get_ops(const char *type)
{
struct fsfilt_operations *fs_ops;
if (!(fs_ops = fsfilt_search_type(type))) {
char name[32];
int rc;
snprintf(name, sizeof(name) - 1, "fsfilt_%s", type);
name[sizeof(name) - 1] = '\0';
if (!(rc = request_module("%s", name))) {
fs_ops = fsfilt_search_type(type);
CDEBUG(D_INFO, "Loaded module '%s'\n", name);
if (!fs_ops)
rc = -ENOENT;
}
if (rc) {
CERROR("Can't find %s interface\n", name);
return ERR_PTR(rc < 0 ? rc : -rc);
}
}
try_module_get(fs_ops->fs_owner);
return fs_ops;
}
void fsfilt_put_ops(struct fsfilt_operations *fs_ops)
{
module_put(fs_ops->fs_owner);
}
