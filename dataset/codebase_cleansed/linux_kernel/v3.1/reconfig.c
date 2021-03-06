static void add_node_proc_entries(struct device_node *np)
{
struct proc_dir_entry *ent;
ent = proc_mkdir(strrchr(np->full_name, '/') + 1, np->parent->pde);
if (ent)
proc_device_tree_add_node(np, ent);
}
static void remove_node_proc_entries(struct device_node *np)
{
struct property *pp = np->properties;
struct device_node *parent = np->parent;
while (pp) {
remove_proc_entry(pp->name, np->pde);
pp = pp->next;
}
if (np->pde)
remove_proc_entry(np->pde->name, parent->pde);
}
static void add_node_proc_entries(struct device_node *np)
{
return;
}
static void remove_node_proc_entries(struct device_node *np)
{
return;
}
static struct device_node *derive_parent(const char *path)
{
struct device_node *parent = NULL;
char *parent_path = "/";
size_t parent_path_len = strrchr(path, '/') - path + 1;
if (!strcmp(path, "/"))
return ERR_PTR(-EINVAL);
if (strrchr(path, '/') != path) {
parent_path = kmalloc(parent_path_len, GFP_KERNEL);
if (!parent_path)
return ERR_PTR(-ENOMEM);
strlcpy(parent_path, path, parent_path_len);
}
parent = of_find_node_by_path(parent_path);
if (!parent)
return ERR_PTR(-EINVAL);
if (strcmp(parent_path, "/"))
kfree(parent_path);
return parent;
}
int pSeries_reconfig_notifier_register(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&pSeries_reconfig_chain, nb);
}
void pSeries_reconfig_notifier_unregister(struct notifier_block *nb)
{
blocking_notifier_chain_unregister(&pSeries_reconfig_chain, nb);
}
int pSeries_reconfig_notify(unsigned long action, void *p)
{
int err = blocking_notifier_call_chain(&pSeries_reconfig_chain,
action, p);
return notifier_to_errno(err);
}
static int pSeries_reconfig_add_node(const char *path, struct property *proplist)
{
struct device_node *np;
int err = -ENOMEM;
np = kzalloc(sizeof(*np), GFP_KERNEL);
if (!np)
goto out_err;
np->full_name = kstrdup(path, GFP_KERNEL);
if (!np->full_name)
goto out_err;
np->properties = proplist;
of_node_set_flag(np, OF_DYNAMIC);
kref_init(&np->kref);
np->parent = derive_parent(path);
if (IS_ERR(np->parent)) {
err = PTR_ERR(np->parent);
goto out_err;
}
err = pSeries_reconfig_notify(PSERIES_RECONFIG_ADD, np);
if (err) {
printk(KERN_ERR "Failed to add device node %s\n", path);
goto out_err;
}
of_attach_node(np);
add_node_proc_entries(np);
of_node_put(np->parent);
return 0;
out_err:
if (np) {
of_node_put(np->parent);
kfree(np->full_name);
kfree(np);
}
return err;
}
static int pSeries_reconfig_remove_node(struct device_node *np)
{
struct device_node *parent, *child;
parent = of_get_parent(np);
if (!parent)
return -EINVAL;
if ((child = of_get_next_child(np, NULL))) {
of_node_put(child);
of_node_put(parent);
return -EBUSY;
}
remove_node_proc_entries(np);
pSeries_reconfig_notify(PSERIES_RECONFIG_REMOVE, np);
of_detach_node(np);
of_node_put(parent);
of_node_put(np);
return 0;
}
static void release_prop_list(const struct property *prop)
{
struct property *next;
for (; prop; prop = next) {
next = prop->next;
kfree(prop->name);
kfree(prop->value);
kfree(prop);
}
}
static char * parse_next_property(char *buf, char *end, char **name, int *length,
unsigned char **value)
{
char *tmp;
*name = buf;
tmp = strchr(buf, ' ');
if (!tmp) {
printk(KERN_ERR "property parse failed in %s at line %d\n",
__func__, __LINE__);
return NULL;
}
*tmp = '\0';
if (++tmp >= end) {
printk(KERN_ERR "property parse failed in %s at line %d\n",
__func__, __LINE__);
return NULL;
}
*length = -1;
*length = simple_strtoul(tmp, &tmp, 10);
if (*length == -1) {
printk(KERN_ERR "property parse failed in %s at line %d\n",
__func__, __LINE__);
return NULL;
}
if (*tmp != ' ' || ++tmp >= end) {
printk(KERN_ERR "property parse failed in %s at line %d\n",
__func__, __LINE__);
return NULL;
}
*value = tmp;
tmp += *length;
if (tmp > end) {
printk(KERN_ERR "property parse failed in %s at line %d\n",
__func__, __LINE__);
return NULL;
}
else if (tmp < end && *tmp != ' ' && *tmp != '\0') {
printk(KERN_ERR "property parse failed in %s at line %d\n",
__func__, __LINE__);
return NULL;
}
tmp++;
return tmp;
}
static struct property *new_property(const char *name, const int length,
const unsigned char *value, struct property *last)
{
struct property *new = kzalloc(sizeof(*new), GFP_KERNEL);
if (!new)
return NULL;
if (!(new->name = kmalloc(strlen(name) + 1, GFP_KERNEL)))
goto cleanup;
if (!(new->value = kmalloc(length + 1, GFP_KERNEL)))
goto cleanup;
strcpy(new->name, name);
memcpy(new->value, value, length);
*(((char *)new->value) + length) = 0;
new->length = length;
new->next = last;
return new;
cleanup:
kfree(new->name);
kfree(new->value);
kfree(new);
return NULL;
}
static int do_add_node(char *buf, size_t bufsize)
{
char *path, *end, *name;
struct device_node *np;
struct property *prop = NULL;
unsigned char* value;
int length, rv = 0;
end = buf + bufsize;
path = buf;
buf = strchr(buf, ' ');
if (!buf)
return -EINVAL;
*buf = '\0';
buf++;
if ((np = of_find_node_by_path(path))) {
of_node_put(np);
return -EINVAL;
}
while (buf < end &&
(buf = parse_next_property(buf, end, &name, &length, &value))) {
struct property *last = prop;
prop = new_property(name, length, value, last);
if (!prop) {
rv = -ENOMEM;
prop = last;
goto out;
}
}
if (!buf) {
rv = -EINVAL;
goto out;
}
rv = pSeries_reconfig_add_node(path, prop);
out:
if (rv)
release_prop_list(prop);
return rv;
}
static int do_remove_node(char *buf)
{
struct device_node *node;
int rv = -ENODEV;
if ((node = of_find_node_by_path(buf)))
rv = pSeries_reconfig_remove_node(node);
of_node_put(node);
return rv;
}
static char *parse_node(char *buf, size_t bufsize, struct device_node **npp)
{
char *handle_str;
phandle handle;
*npp = NULL;
handle_str = buf;
buf = strchr(buf, ' ');
if (!buf)
return NULL;
*buf = '\0';
buf++;
handle = simple_strtoul(handle_str, NULL, 0);
*npp = of_find_node_by_phandle(handle);
return buf;
}
static int do_add_property(char *buf, size_t bufsize)
{
struct property *prop = NULL;
struct device_node *np;
unsigned char *value;
char *name, *end;
int length;
end = buf + bufsize;
buf = parse_node(buf, bufsize, &np);
if (!np)
return -ENODEV;
if (parse_next_property(buf, end, &name, &length, &value) == NULL)
return -EINVAL;
prop = new_property(name, length, value, NULL);
if (!prop)
return -ENOMEM;
prom_add_property(np, prop);
return 0;
}
static int do_remove_property(char *buf, size_t bufsize)
{
struct device_node *np;
char *tmp;
struct property *prop;
buf = parse_node(buf, bufsize, &np);
if (!np)
return -ENODEV;
tmp = strchr(buf,' ');
if (tmp)
*tmp = '\0';
if (strlen(buf) == 0)
return -EINVAL;
prop = of_find_property(np, buf, NULL);
return prom_remove_property(np, prop);
}
static int do_update_property(char *buf, size_t bufsize)
{
struct device_node *np;
unsigned char *value;
char *name, *end, *next_prop;
int rc, length;
struct property *newprop, *oldprop;
buf = parse_node(buf, bufsize, &np);
end = buf + bufsize;
if (!np)
return -ENODEV;
next_prop = parse_next_property(buf, end, &name, &length, &value);
if (!next_prop)
return -EINVAL;
newprop = new_property(name, length, value, NULL);
if (!newprop)
return -ENOMEM;
if (!strcmp(name, "slb-size") || !strcmp(name, "ibm,slb-size"))
slb_set_size(*(int *)value);
oldprop = of_find_property(np, name,NULL);
if (!oldprop) {
if (strlen(name))
return prom_add_property(np, newprop);
return -ENODEV;
}
rc = prom_update_property(np, newprop, oldprop);
if (rc)
return rc;
if (!strcmp(name, "ibm,dynamic-memory")) {
int action;
next_prop = parse_next_property(next_prop, end, &name,
&length, &value);
if (!next_prop)
return -EINVAL;
if (!strcmp(name, "add"))
action = PSERIES_DRCONF_MEM_ADD;
else
action = PSERIES_DRCONF_MEM_REMOVE;
rc = pSeries_reconfig_notify(action, value);
if (rc) {
prom_update_property(np, oldprop, newprop);
return rc;
}
}
return 0;
}
static ssize_t ofdt_write(struct file *file, const char __user *buf, size_t count,
loff_t *off)
{
int rv = 0;
char *kbuf;
char *tmp;
if (!(kbuf = kmalloc(count + 1, GFP_KERNEL))) {
rv = -ENOMEM;
goto out;
}
if (copy_from_user(kbuf, buf, count)) {
rv = -EFAULT;
goto out;
}
kbuf[count] = '\0';
tmp = strchr(kbuf, ' ');
if (!tmp) {
rv = -EINVAL;
goto out;
}
*tmp = '\0';
tmp++;
if (!strcmp(kbuf, "add_node"))
rv = do_add_node(tmp, count - (tmp - kbuf));
else if (!strcmp(kbuf, "remove_node"))
rv = do_remove_node(tmp);
else if (!strcmp(kbuf, "add_property"))
rv = do_add_property(tmp, count - (tmp - kbuf));
else if (!strcmp(kbuf, "remove_property"))
rv = do_remove_property(tmp, count - (tmp - kbuf));
else if (!strcmp(kbuf, "update_property"))
rv = do_update_property(tmp, count - (tmp - kbuf));
else
rv = -EINVAL;
out:
kfree(kbuf);
return rv ? rv : count;
}
static int proc_ppc64_create_ofdt(void)
{
struct proc_dir_entry *ent;
if (!machine_is(pseries))
return 0;
ent = proc_create("powerpc/ofdt", S_IWUSR, NULL, &ofdt_fops);
if (ent)
ent->size = 0;
return 0;
}
