static int __init gcov_persist_setup(char *str)
{
unsigned long val;
if (kstrtoul(str, 0, &val)) {
pr_warn("invalid gcov_persist parameter '%s'\n", str);
return 0;
}
gcov_persist = val;
pr_info("setting gcov_persist to %d\n", gcov_persist);
return 1;
}
static void *gcov_seq_start(struct seq_file *seq, loff_t *pos)
{
loff_t i;
gcov_iter_start(seq->private);
for (i = 0; i < *pos; i++) {
if (gcov_iter_next(seq->private))
return NULL;
}
return seq->private;
}
static void *gcov_seq_next(struct seq_file *seq, void *data, loff_t *pos)
{
struct gcov_iterator *iter = data;
if (gcov_iter_next(iter))
return NULL;
(*pos)++;
return iter;
}
static int gcov_seq_show(struct seq_file *seq, void *data)
{
struct gcov_iterator *iter = data;
if (gcov_iter_write(iter, seq))
return -EINVAL;
return 0;
}
static void gcov_seq_stop(struct seq_file *seq, void *data)
{
}
static struct gcov_info *get_node_info(struct gcov_node *node)
{
if (node->num_loaded > 0)
return node->loaded_info[0];
return node->unloaded_info;
}
static struct gcov_info *get_accumulated_info(struct gcov_node *node)
{
struct gcov_info *info;
int i = 0;
if (node->unloaded_info)
info = gcov_info_dup(node->unloaded_info);
else
info = gcov_info_dup(node->loaded_info[i++]);
if (!info)
return NULL;
for (; i < node->num_loaded; i++)
gcov_info_add(info, node->loaded_info[i]);
return info;
}
static int gcov_seq_open(struct inode *inode, struct file *file)
{
struct gcov_node *node = inode->i_private;
struct gcov_iterator *iter;
struct seq_file *seq;
struct gcov_info *info;
int rc = -ENOMEM;
mutex_lock(&node_lock);
info = get_accumulated_info(node);
if (!info)
goto out_unlock;
iter = gcov_iter_new(info);
if (!iter)
goto err_free_info;
rc = seq_open(file, &gcov_seq_ops);
if (rc)
goto err_free_iter_info;
seq = file->private_data;
seq->private = iter;
out_unlock:
mutex_unlock(&node_lock);
return rc;
err_free_iter_info:
gcov_iter_free(iter);
err_free_info:
gcov_info_free(info);
goto out_unlock;
}
static int gcov_seq_release(struct inode *inode, struct file *file)
{
struct gcov_iterator *iter;
struct gcov_info *info;
struct seq_file *seq;
seq = file->private_data;
iter = seq->private;
info = gcov_iter_get_info(iter);
gcov_iter_free(iter);
gcov_info_free(info);
seq_release(inode, file);
return 0;
}
static struct gcov_node *get_node_by_name(const char *name)
{
struct gcov_node *node;
struct gcov_info *info;
list_for_each_entry(node, &all_head, all) {
info = get_node_info(node);
if (info && (strcmp(gcov_info_filename(info), name) == 0))
return node;
}
return NULL;
}
static void reset_node(struct gcov_node *node)
{
int i;
if (node->unloaded_info)
gcov_info_reset(node->unloaded_info);
for (i = 0; i < node->num_loaded; i++)
gcov_info_reset(node->loaded_info[i]);
}
static ssize_t gcov_seq_write(struct file *file, const char __user *addr,
size_t len, loff_t *pos)
{
struct seq_file *seq;
struct gcov_info *info;
struct gcov_node *node;
seq = file->private_data;
info = gcov_iter_get_info(seq->private);
mutex_lock(&node_lock);
node = get_node_by_name(gcov_info_filename(info));
if (node) {
if (node->num_loaded == 0)
remove_node(node);
else
reset_node(node);
}
gcov_info_reset(info);
mutex_unlock(&node_lock);
return len;
}
static char *link_target(const char *dir, const char *path, const char *ext)
{
char *target;
char *old_ext;
char *copy;
copy = kstrdup(path, GFP_KERNEL);
if (!copy)
return NULL;
old_ext = strrchr(copy, '.');
if (old_ext)
*old_ext = '\0';
if (dir)
target = kasprintf(GFP_KERNEL, "%s/%s.%s", dir, copy, ext);
else
target = kasprintf(GFP_KERNEL, "%s.%s", copy, ext);
kfree(copy);
return target;
}
static char *get_link_target(const char *filename, const struct gcov_link *ext)
{
const char *rel;
char *result;
if (strncmp(filename, objtree, strlen(objtree)) == 0) {
rel = filename + strlen(objtree) + 1;
if (ext->dir == SRC_TREE)
result = link_target(srctree, rel, ext->ext);
else
result = link_target(objtree, rel, ext->ext);
} else {
result = link_target(NULL, filename, ext->ext);
}
return result;
}
static const char *deskew(const char *basename)
{
if (strncmp(basename, SKEW_PREFIX, sizeof(SKEW_PREFIX) - 1) == 0)
return basename + sizeof(SKEW_PREFIX) - 1;
return basename;
}
static void add_links(struct gcov_node *node, struct dentry *parent)
{
const char *basename;
char *target;
int num;
int i;
for (num = 0; gcov_link[num].ext; num++)
;
node->links = kcalloc(num, sizeof(struct dentry *), GFP_KERNEL);
if (!node->links)
return;
for (i = 0; i < num; i++) {
target = get_link_target(
gcov_info_filename(get_node_info(node)),
&gcov_link[i]);
if (!target)
goto out_err;
basename = kbasename(target);
if (basename == target)
goto out_err;
node->links[i] = debugfs_create_symlink(deskew(basename),
parent, target);
if (!node->links[i])
goto out_err;
kfree(target);
}
return;
out_err:
kfree(target);
while (i-- > 0)
debugfs_remove(node->links[i]);
kfree(node->links);
node->links = NULL;
}
static void init_node(struct gcov_node *node, struct gcov_info *info,
const char *name, struct gcov_node *parent)
{
INIT_LIST_HEAD(&node->list);
INIT_LIST_HEAD(&node->children);
INIT_LIST_HEAD(&node->all);
if (node->loaded_info) {
node->loaded_info[0] = info;
node->num_loaded = 1;
}
node->parent = parent;
if (name)
strcpy(node->name, name);
}
static struct gcov_node *new_node(struct gcov_node *parent,
struct gcov_info *info, const char *name)
{
struct gcov_node *node;
node = kzalloc(sizeof(struct gcov_node) + strlen(name) + 1, GFP_KERNEL);
if (!node)
goto err_nomem;
if (info) {
node->loaded_info = kcalloc(1, sizeof(struct gcov_info *),
GFP_KERNEL);
if (!node->loaded_info)
goto err_nomem;
}
init_node(node, info, name, parent);
if (info) {
node->dentry = debugfs_create_file(deskew(node->name), 0600,
parent->dentry, node, &gcov_data_fops);
} else
node->dentry = debugfs_create_dir(node->name, parent->dentry);
if (!node->dentry) {
pr_warn("could not create file\n");
kfree(node);
return NULL;
}
if (info)
add_links(node, parent->dentry);
list_add(&node->list, &parent->children);
list_add(&node->all, &all_head);
return node;
err_nomem:
kfree(node);
pr_warn("out of memory\n");
return NULL;
}
static void remove_links(struct gcov_node *node)
{
int i;
if (!node->links)
return;
for (i = 0; gcov_link[i].ext; i++)
debugfs_remove(node->links[i]);
kfree(node->links);
node->links = NULL;
}
static void release_node(struct gcov_node *node)
{
list_del(&node->list);
list_del(&node->all);
debugfs_remove(node->dentry);
remove_links(node);
kfree(node->loaded_info);
if (node->unloaded_info)
gcov_info_free(node->unloaded_info);
kfree(node);
}
static void remove_node(struct gcov_node *node)
{
struct gcov_node *parent;
while ((node != &root_node) && list_empty(&node->children)) {
parent = node->parent;
release_node(node);
node = parent;
}
}
static struct gcov_node *get_child_by_name(struct gcov_node *parent,
const char *name)
{
struct gcov_node *node;
list_for_each_entry(node, &parent->children, list) {
if (strcmp(node->name, name) == 0)
return node;
}
return NULL;
}
static ssize_t reset_write(struct file *file, const char __user *addr,
size_t len, loff_t *pos)
{
struct gcov_node *node;
mutex_lock(&node_lock);
restart:
list_for_each_entry(node, &all_head, all) {
if (node->num_loaded > 0)
reset_node(node);
else if (list_empty(&node->children)) {
remove_node(node);
goto restart;
}
}
mutex_unlock(&node_lock);
return len;
}
static ssize_t reset_read(struct file *file, char __user *addr, size_t len,
loff_t *pos)
{
return 0;
}
static void add_node(struct gcov_info *info)
{
char *filename;
char *curr;
char *next;
struct gcov_node *parent;
struct gcov_node *node;
filename = kstrdup(gcov_info_filename(info), GFP_KERNEL);
if (!filename)
return;
parent = &root_node;
for (curr = filename; (next = strchr(curr, '/')); curr = next + 1) {
if (curr == next)
continue;
*next = 0;
if (strcmp(curr, ".") == 0)
continue;
if (strcmp(curr, "..") == 0) {
if (!parent->parent)
goto err_remove;
parent = parent->parent;
continue;
}
node = get_child_by_name(parent, curr);
if (!node) {
node = new_node(parent, NULL, curr);
if (!node)
goto err_remove;
}
parent = node;
}
node = new_node(parent, info, curr);
if (!node)
goto err_remove;
out:
kfree(filename);
return;
err_remove:
remove_node(parent);
goto out;
}
static void add_info(struct gcov_node *node, struct gcov_info *info)
{
struct gcov_info **loaded_info;
int num = node->num_loaded;
loaded_info = kcalloc(num + 1, sizeof(struct gcov_info *), GFP_KERNEL);
if (!loaded_info) {
pr_warn("could not add '%s' (out of memory)\n",
gcov_info_filename(info));
return;
}
memcpy(loaded_info, node->loaded_info,
num * sizeof(struct gcov_info *));
loaded_info[num] = info;
if (num == 0) {
if (!gcov_info_is_compatible(node->unloaded_info, info)) {
pr_warn("discarding saved data for %s "
"(incompatible version)\n",
gcov_info_filename(info));
gcov_info_free(node->unloaded_info);
node->unloaded_info = NULL;
}
} else {
if (!gcov_info_is_compatible(node->loaded_info[0], info)) {
pr_warn("could not add '%s' (incompatible "
"version)\n", gcov_info_filename(info));
kfree(loaded_info);
return;
}
}
kfree(node->loaded_info);
node->loaded_info = loaded_info;
node->num_loaded = num + 1;
}
static int get_info_index(struct gcov_node *node, struct gcov_info *info)
{
int i;
for (i = 0; i < node->num_loaded; i++) {
if (node->loaded_info[i] == info)
return i;
}
return -ENOENT;
}
static void save_info(struct gcov_node *node, struct gcov_info *info)
{
if (node->unloaded_info)
gcov_info_add(node->unloaded_info, info);
else {
node->unloaded_info = gcov_info_dup(info);
if (!node->unloaded_info) {
pr_warn("could not save data for '%s' "
"(out of memory)\n",
gcov_info_filename(info));
}
}
}
static void remove_info(struct gcov_node *node, struct gcov_info *info)
{
int i;
i = get_info_index(node, info);
if (i < 0) {
pr_warn("could not remove '%s' (not found)\n",
gcov_info_filename(info));
return;
}
if (gcov_persist)
save_info(node, info);
node->loaded_info[i] = node->loaded_info[node->num_loaded - 1];
node->num_loaded--;
if (node->num_loaded > 0)
return;
kfree(node->loaded_info);
node->loaded_info = NULL;
node->num_loaded = 0;
if (!node->unloaded_info)
remove_node(node);
}
void gcov_event(enum gcov_action action, struct gcov_info *info)
{
struct gcov_node *node;
mutex_lock(&node_lock);
node = get_node_by_name(gcov_info_filename(info));
switch (action) {
case GCOV_ADD:
if (node)
add_info(node, info);
else
add_node(info);
break;
case GCOV_REMOVE:
if (node)
remove_info(node, info);
else {
pr_warn("could not remove '%s' (not found)\n",
gcov_info_filename(info));
}
break;
}
mutex_unlock(&node_lock);
}
static __init int gcov_fs_init(void)
{
int rc = -EIO;
init_node(&root_node, NULL, NULL, NULL);
root_node.dentry = debugfs_create_dir("gcov", NULL);
if (!root_node.dentry)
goto err_remove;
reset_dentry = debugfs_create_file("reset", 0600, root_node.dentry,
NULL, &gcov_reset_fops);
if (!reset_dentry)
goto err_remove;
gcov_enable_events();
return 0;
err_remove:
pr_err("init failed\n");
debugfs_remove(root_node.dentry);
return rc;
}
