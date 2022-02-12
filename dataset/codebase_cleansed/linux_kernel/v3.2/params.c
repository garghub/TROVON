static void *kmalloc_parameter(unsigned int size)
{
struct kmalloced_param *p;
p = kmalloc(sizeof(*p) + size, GFP_KERNEL);
if (!p)
return NULL;
list_add(&p->list, &kmalloced_params);
return p->val;
}
static void maybe_kfree_parameter(void *param)
{
struct kmalloced_param *p;
list_for_each_entry(p, &kmalloced_params, list) {
if (p->val == param) {
list_del(&p->list);
kfree(p);
break;
}
}
}
static char dash2underscore(char c)
{
if (c == '-')
return '_';
return c;
}
bool parameqn(const char *a, const char *b, size_t n)
{
size_t i;
for (i = 0; i < n; i++) {
if (dash2underscore(a[i]) != dash2underscore(b[i]))
return false;
}
return true;
}
bool parameq(const char *a, const char *b)
{
return parameqn(a, b, strlen(a)+1);
}
static int parse_one(char *param,
char *val,
const struct kernel_param *params,
unsigned num_params,
int (*handle_unknown)(char *param, char *val))
{
unsigned int i;
int err;
for (i = 0; i < num_params; i++) {
if (parameq(param, params[i].name)) {
if (!val && params[i].ops->set != param_set_bool)
return -EINVAL;
DEBUGP("They are equal! Calling %p\n",
params[i].ops->set);
mutex_lock(&param_lock);
err = params[i].ops->set(val, &params[i]);
mutex_unlock(&param_lock);
return err;
}
}
if (handle_unknown) {
DEBUGP("Unknown argument: calling %p\n", handle_unknown);
return handle_unknown(param, val);
}
DEBUGP("Unknown argument `%s'\n", param);
return -ENOENT;
}
static char *next_arg(char *args, char **param, char **val)
{
unsigned int i, equals = 0;
int in_quote = 0, quoted = 0;
char *next;
if (*args == '"') {
args++;
in_quote = 1;
quoted = 1;
}
for (i = 0; args[i]; i++) {
if (isspace(args[i]) && !in_quote)
break;
if (equals == 0) {
if (args[i] == '=')
equals = i;
}
if (args[i] == '"')
in_quote = !in_quote;
}
*param = args;
if (!equals)
*val = NULL;
else {
args[equals] = '\0';
*val = args + equals + 1;
if (**val == '"') {
(*val)++;
if (args[i-1] == '"')
args[i-1] = '\0';
}
if (quoted && args[i-1] == '"')
args[i-1] = '\0';
}
if (args[i]) {
args[i] = '\0';
next = args + i + 1;
} else
next = args + i;
return skip_spaces(next);
}
int parse_args(const char *name,
char *args,
const struct kernel_param *params,
unsigned num,
int (*unknown)(char *param, char *val))
{
char *param, *val;
DEBUGP("Parsing ARGS: %s\n", args);
args = skip_spaces(args);
while (*args) {
int ret;
int irq_was_disabled;
args = next_arg(args, &param, &val);
irq_was_disabled = irqs_disabled();
ret = parse_one(param, val, params, num, unknown);
if (irq_was_disabled && !irqs_disabled()) {
printk(KERN_WARNING "parse_args(): option '%s' enabled "
"irq's!\n", param);
}
switch (ret) {
case -ENOENT:
printk(KERN_ERR "%s: Unknown parameter `%s'\n",
name, param);
return ret;
case -ENOSPC:
printk(KERN_ERR
"%s: `%s' too large for parameter `%s'\n",
name, val ?: "", param);
return ret;
case 0:
break;
default:
printk(KERN_ERR
"%s: `%s' invalid for parameter `%s'\n",
name, val ?: "", param);
return ret;
}
}
return 0;
}
int param_set_charp(const char *val, const struct kernel_param *kp)
{
if (strlen(val) > 1024) {
printk(KERN_ERR "%s: string parameter too long\n",
kp->name);
return -ENOSPC;
}
maybe_kfree_parameter(*(char **)kp->arg);
if (slab_is_available()) {
*(char **)kp->arg = kmalloc_parameter(strlen(val)+1);
if (!*(char **)kp->arg)
return -ENOMEM;
strcpy(*(char **)kp->arg, val);
} else
*(const char **)kp->arg = val;
return 0;
}
int param_get_charp(char *buffer, const struct kernel_param *kp)
{
return sprintf(buffer, "%s", *((char **)kp->arg));
}
static void param_free_charp(void *arg)
{
maybe_kfree_parameter(*((char **)arg));
}
int param_set_bool(const char *val, const struct kernel_param *kp)
{
bool v;
int ret;
if (!val) val = "1";
ret = strtobool(val, &v);
if (ret)
return ret;
if (kp->flags & KPARAM_ISBOOL)
*(bool *)kp->arg = v;
else
*(int *)kp->arg = v;
return 0;
}
int param_get_bool(char *buffer, const struct kernel_param *kp)
{
bool val;
if (kp->flags & KPARAM_ISBOOL)
val = *(bool *)kp->arg;
else
val = *(int *)kp->arg;
return sprintf(buffer, "%c", val ? 'Y' : 'N');
}
int param_set_invbool(const char *val, const struct kernel_param *kp)
{
int ret;
bool boolval;
struct kernel_param dummy;
dummy.arg = &boolval;
dummy.flags = KPARAM_ISBOOL;
ret = param_set_bool(val, &dummy);
if (ret == 0)
*(bool *)kp->arg = !boolval;
return ret;
}
int param_get_invbool(char *buffer, const struct kernel_param *kp)
{
return sprintf(buffer, "%c", (*(bool *)kp->arg) ? 'N' : 'Y');
}
static int param_array(const char *name,
const char *val,
unsigned int min, unsigned int max,
void *elem, int elemsize,
int (*set)(const char *, const struct kernel_param *kp),
u16 flags,
unsigned int *num)
{
int ret;
struct kernel_param kp;
char save;
kp.name = name;
kp.arg = elem;
kp.flags = flags;
*num = 0;
do {
int len;
if (*num == max) {
printk(KERN_ERR "%s: can only take %i arguments\n",
name, max);
return -EINVAL;
}
len = strcspn(val, ",");
save = val[len];
((char *)val)[len] = '\0';
BUG_ON(!mutex_is_locked(&param_lock));
ret = set(val, &kp);
if (ret != 0)
return ret;
kp.arg += elemsize;
val += len+1;
(*num)++;
} while (save == ',');
if (*num < min) {
printk(KERN_ERR "%s: needs at least %i arguments\n",
name, min);
return -EINVAL;
}
return 0;
}
static int param_array_set(const char *val, const struct kernel_param *kp)
{
const struct kparam_array *arr = kp->arr;
unsigned int temp_num;
return param_array(kp->name, val, 1, arr->max, arr->elem,
arr->elemsize, arr->ops->set, kp->flags,
arr->num ?: &temp_num);
}
static int param_array_get(char *buffer, const struct kernel_param *kp)
{
int i, off, ret;
const struct kparam_array *arr = kp->arr;
struct kernel_param p;
p = *kp;
for (i = off = 0; i < (arr->num ? *arr->num : arr->max); i++) {
if (i)
buffer[off++] = ',';
p.arg = arr->elem + arr->elemsize * i;
BUG_ON(!mutex_is_locked(&param_lock));
ret = arr->ops->get(buffer + off, &p);
if (ret < 0)
return ret;
off += ret;
}
buffer[off] = '\0';
return off;
}
static void param_array_free(void *arg)
{
unsigned int i;
const struct kparam_array *arr = arg;
if (arr->ops->free)
for (i = 0; i < (arr->num ? *arr->num : arr->max); i++)
arr->ops->free(arr->elem + arr->elemsize * i);
}
int param_set_copystring(const char *val, const struct kernel_param *kp)
{
const struct kparam_string *kps = kp->str;
if (strlen(val)+1 > kps->maxlen) {
printk(KERN_ERR "%s: string doesn't fit in %u chars.\n",
kp->name, kps->maxlen-1);
return -ENOSPC;
}
strcpy(kps->string, val);
return 0;
}
int param_get_string(char *buffer, const struct kernel_param *kp)
{
const struct kparam_string *kps = kp->str;
return strlcpy(buffer, kps->string, kps->maxlen);
}
static ssize_t param_attr_show(struct module_attribute *mattr,
struct module_kobject *mk, char *buf)
{
int count;
struct param_attribute *attribute = to_param_attr(mattr);
if (!attribute->param->ops->get)
return -EPERM;
mutex_lock(&param_lock);
count = attribute->param->ops->get(buf, attribute->param);
mutex_unlock(&param_lock);
if (count > 0) {
strcat(buf, "\n");
++count;
}
return count;
}
static ssize_t param_attr_store(struct module_attribute *mattr,
struct module_kobject *km,
const char *buf, size_t len)
{
int err;
struct param_attribute *attribute = to_param_attr(mattr);
if (!attribute->param->ops->set)
return -EPERM;
mutex_lock(&param_lock);
err = attribute->param->ops->set(buf, attribute->param);
mutex_unlock(&param_lock);
if (!err)
return len;
return err;
}
void __kernel_param_lock(void)
{
mutex_lock(&param_lock);
}
void __kernel_param_unlock(void)
{
mutex_unlock(&param_lock);
}
static __modinit int add_sysfs_param(struct module_kobject *mk,
const struct kernel_param *kp,
const char *name)
{
struct module_param_attrs *new;
struct attribute **attrs;
int err, num;
BUG_ON(!kp->perm);
if (!mk->mp) {
num = 0;
attrs = NULL;
} else {
num = mk->mp->num;
attrs = mk->mp->grp.attrs;
}
new = krealloc(mk->mp,
sizeof(*mk->mp) + sizeof(mk->mp->attrs[0]) * (num+1),
GFP_KERNEL);
if (!new) {
kfree(mk->mp);
err = -ENOMEM;
goto fail;
}
attrs = krealloc(attrs, sizeof(new->grp.attrs[0])*(num+2), GFP_KERNEL);
if (!attrs) {
err = -ENOMEM;
goto fail_free_new;
}
memset(new, 0, sizeof(*new));
memset(&new->attrs[num], 0, sizeof(new->attrs[num]));
memset(&attrs[num], 0, sizeof(attrs[num]));
new->grp.name = "parameters";
new->grp.attrs = attrs;
sysfs_attr_init(&new->attrs[num].mattr.attr);
new->attrs[num].param = kp;
new->attrs[num].mattr.show = param_attr_show;
new->attrs[num].mattr.store = param_attr_store;
new->attrs[num].mattr.attr.name = (char *)name;
new->attrs[num].mattr.attr.mode = kp->perm;
new->num = num+1;
for (num = 0; num < new->num; num++)
new->grp.attrs[num] = &new->attrs[num].mattr.attr;
new->grp.attrs[num] = NULL;
mk->mp = new;
return 0;
fail_free_new:
kfree(new);
fail:
mk->mp = NULL;
return err;
}
static void free_module_param_attrs(struct module_kobject *mk)
{
kfree(mk->mp->grp.attrs);
kfree(mk->mp);
mk->mp = NULL;
}
int module_param_sysfs_setup(struct module *mod,
const struct kernel_param *kparam,
unsigned int num_params)
{
int i, err;
bool params = false;
for (i = 0; i < num_params; i++) {
if (kparam[i].perm == 0)
continue;
err = add_sysfs_param(&mod->mkobj, &kparam[i], kparam[i].name);
if (err)
return err;
params = true;
}
if (!params)
return 0;
err = sysfs_create_group(&mod->mkobj.kobj, &mod->mkobj.mp->grp);
if (err)
free_module_param_attrs(&mod->mkobj);
return err;
}
void module_param_sysfs_remove(struct module *mod)
{
if (mod->mkobj.mp) {
sysfs_remove_group(&mod->mkobj.kobj, &mod->mkobj.mp->grp);
free_module_param_attrs(&mod->mkobj);
}
}
void destroy_params(const struct kernel_param *params, unsigned num)
{
unsigned int i;
for (i = 0; i < num; i++)
if (params[i].ops->free)
params[i].ops->free(params[i].arg);
}
static struct module_kobject * __init locate_module_kobject(const char *name)
{
struct module_kobject *mk;
struct kobject *kobj;
int err;
kobj = kset_find_obj(module_kset, name);
if (kobj) {
mk = to_module_kobject(kobj);
} else {
mk = kzalloc(sizeof(struct module_kobject), GFP_KERNEL);
BUG_ON(!mk);
mk->mod = THIS_MODULE;
mk->kobj.kset = module_kset;
err = kobject_init_and_add(&mk->kobj, &module_ktype, NULL,
"%s", name);
#ifdef CONFIG_MODULES
if (!err)
err = sysfs_create_file(&mk->kobj, &module_uevent.attr);
#endif
if (err) {
kobject_put(&mk->kobj);
printk(KERN_ERR
"Module '%s' failed add to sysfs, error number %d\n",
name, err);
printk(KERN_ERR
"The system will be unstable now.\n");
return NULL;
}
kobject_get(&mk->kobj);
}
return mk;
}
static void __init kernel_add_sysfs_param(const char *name,
struct kernel_param *kparam,
unsigned int name_skip)
{
struct module_kobject *mk;
int err;
mk = locate_module_kobject(name);
if (!mk)
return;
if (mk->mp)
sysfs_remove_group(&mk->kobj, &mk->mp->grp);
err = add_sysfs_param(mk, kparam, kparam->name + name_skip);
BUG_ON(err);
err = sysfs_create_group(&mk->kobj, &mk->mp->grp);
BUG_ON(err);
kobject_uevent(&mk->kobj, KOBJ_ADD);
kobject_put(&mk->kobj);
}
static void __init param_sysfs_builtin(void)
{
struct kernel_param *kp;
unsigned int name_len;
char modname[MODULE_NAME_LEN];
for (kp = __start___param; kp < __stop___param; kp++) {
char *dot;
if (kp->perm == 0)
continue;
dot = strchr(kp->name, '.');
if (!dot) {
strcpy(modname, "kernel");
name_len = 0;
} else {
name_len = dot - kp->name + 1;
strlcpy(modname, kp->name, name_len);
}
kernel_add_sysfs_param(modname, kp, name_len);
}
}
ssize_t __modver_version_show(struct module_attribute *mattr,
struct module_kobject *mk, char *buf)
{
struct module_version_attribute *vattr =
container_of(mattr, struct module_version_attribute, mattr);
return sprintf(buf, "%s\n", vattr->version);
}
static void __init version_sysfs_builtin(void)
{
const struct module_version_attribute **p;
struct module_kobject *mk;
int err;
for (p = __start___modver; p < __stop___modver; p++) {
const struct module_version_attribute *vattr = *p;
mk = locate_module_kobject(vattr->module_name);
if (mk) {
err = sysfs_create_file(&mk->kobj, &vattr->mattr.attr);
kobject_uevent(&mk->kobj, KOBJ_ADD);
kobject_put(&mk->kobj);
}
}
}
static ssize_t module_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct module_attribute *attribute;
struct module_kobject *mk;
int ret;
attribute = to_module_attr(attr);
mk = to_module_kobject(kobj);
if (!attribute->show)
return -EIO;
ret = attribute->show(attribute, mk, buf);
return ret;
}
static ssize_t module_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t len)
{
struct module_attribute *attribute;
struct module_kobject *mk;
int ret;
attribute = to_module_attr(attr);
mk = to_module_kobject(kobj);
if (!attribute->store)
return -EIO;
ret = attribute->store(attribute, mk, buf, len);
return ret;
}
static int uevent_filter(struct kset *kset, struct kobject *kobj)
{
struct kobj_type *ktype = get_ktype(kobj);
if (ktype == &module_ktype)
return 1;
return 0;
}
static int __init param_sysfs_init(void)
{
module_kset = kset_create_and_add("module", &module_uevent_ops, NULL);
if (!module_kset) {
printk(KERN_WARNING "%s (%d): error creating kset\n",
__FILE__, __LINE__);
return -ENOMEM;
}
module_sysfs_initialized = 1;
version_sysfs_builtin();
param_sysfs_builtin();
return 0;
}
