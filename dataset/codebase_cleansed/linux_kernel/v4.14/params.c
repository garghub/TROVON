static inline void check_kparam_locked(struct module *mod)
{
BUG_ON(!mutex_is_locked(KPARAM_MUTEX(mod)));
}
static inline void check_kparam_locked(struct module *mod)
{
}
static void *kmalloc_parameter(unsigned int size)
{
struct kmalloced_param *p;
p = kmalloc(sizeof(*p) + size, GFP_KERNEL);
if (!p)
return NULL;
spin_lock(&kmalloced_params_lock);
list_add(&p->list, &kmalloced_params);
spin_unlock(&kmalloced_params_lock);
return p->val;
}
static void maybe_kfree_parameter(void *param)
{
struct kmalloced_param *p;
spin_lock(&kmalloced_params_lock);
list_for_each_entry(p, &kmalloced_params, list) {
if (p->val == param) {
list_del(&p->list);
kfree(p);
break;
}
}
spin_unlock(&kmalloced_params_lock);
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
static void param_check_unsafe(const struct kernel_param *kp)
{
if (kp->flags & KERNEL_PARAM_FL_UNSAFE) {
pr_warn("Setting dangerous option %s - tainting kernel\n",
kp->name);
add_taint(TAINT_USER, LOCKDEP_STILL_OK);
}
}
static int parse_one(char *param,
char *val,
const char *doing,
const struct kernel_param *params,
unsigned num_params,
s16 min_level,
s16 max_level,
void *arg,
int (*handle_unknown)(char *param, char *val,
const char *doing, void *arg))
{
unsigned int i;
int err;
for (i = 0; i < num_params; i++) {
if (parameq(param, params[i].name)) {
if (params[i].level < min_level
|| params[i].level > max_level)
return 0;
if (!val &&
!(params[i].ops->flags & KERNEL_PARAM_OPS_FL_NOARG))
return -EINVAL;
pr_debug("handling %s with %p\n", param,
params[i].ops->set);
kernel_param_lock(params[i].mod);
param_check_unsafe(&params[i]);
err = params[i].ops->set(val, &params[i]);
kernel_param_unlock(params[i].mod);
return err;
}
}
if (handle_unknown) {
pr_debug("doing %s: %s='%s'\n", doing, param, val);
return handle_unknown(param, val, doing, arg);
}
pr_debug("Unknown argument '%s'\n", param);
return -ENOENT;
}
char *parse_args(const char *doing,
char *args,
const struct kernel_param *params,
unsigned num,
s16 min_level,
s16 max_level,
void *arg,
int (*unknown)(char *param, char *val,
const char *doing, void *arg))
{
char *param, *val, *err = NULL;
args = skip_spaces(args);
if (*args)
pr_debug("doing %s, parsing ARGS: '%s'\n", doing, args);
while (*args) {
int ret;
int irq_was_disabled;
args = next_arg(args, &param, &val);
if (!val && strcmp(param, "--") == 0)
return err ?: args;
irq_was_disabled = irqs_disabled();
ret = parse_one(param, val, doing, params, num,
min_level, max_level, arg, unknown);
if (irq_was_disabled && !irqs_disabled())
pr_warn("%s: option '%s' enabled irq's!\n",
doing, param);
switch (ret) {
case 0:
continue;
case -ENOENT:
pr_err("%s: Unknown parameter `%s'\n", doing, param);
break;
case -ENOSPC:
pr_err("%s: `%s' too large for parameter `%s'\n",
doing, val ?: "", param);
break;
default:
pr_err("%s: `%s' invalid for parameter `%s'\n",
doing, val ?: "", param);
break;
}
err = ERR_PTR(ret);
}
return err;
}
int param_set_charp(const char *val, const struct kernel_param *kp)
{
if (strlen(val) > 1024) {
pr_err("%s: string parameter too long\n", kp->name);
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
return scnprintf(buffer, PAGE_SIZE, "%s\n", *((char **)kp->arg));
}
void param_free_charp(void *arg)
{
maybe_kfree_parameter(*((char **)arg));
}
int param_set_bool(const char *val, const struct kernel_param *kp)
{
if (!val) val = "1";
return strtobool(val, kp->arg);
}
int param_get_bool(char *buffer, const struct kernel_param *kp)
{
return sprintf(buffer, "%c\n", *(bool *)kp->arg ? 'Y' : 'N');
}
int param_set_bool_enable_only(const char *val, const struct kernel_param *kp)
{
int err = 0;
bool new_value;
bool orig_value = *(bool *)kp->arg;
struct kernel_param dummy_kp = *kp;
dummy_kp.arg = &new_value;
err = param_set_bool(val, &dummy_kp);
if (err)
return err;
if (!new_value && orig_value)
return -EROFS;
if (new_value)
err = param_set_bool(val, kp);
return err;
}
int param_set_invbool(const char *val, const struct kernel_param *kp)
{
int ret;
bool boolval;
struct kernel_param dummy;
dummy.arg = &boolval;
ret = param_set_bool(val, &dummy);
if (ret == 0)
*(bool *)kp->arg = !boolval;
return ret;
}
int param_get_invbool(char *buffer, const struct kernel_param *kp)
{
return sprintf(buffer, "%c\n", (*(bool *)kp->arg) ? 'N' : 'Y');
}
int param_set_bint(const char *val, const struct kernel_param *kp)
{
struct kernel_param boolkp = *kp;
bool v;
int ret;
boolkp.arg = &v;
ret = param_set_bool(val, &boolkp);
if (ret == 0)
*(int *)kp->arg = v;
return ret;
}
static int param_array(struct module *mod,
const char *name,
const char *val,
unsigned int min, unsigned int max,
void *elem, int elemsize,
int (*set)(const char *, const struct kernel_param *kp),
s16 level,
unsigned int *num)
{
int ret;
struct kernel_param kp;
char save;
kp.name = name;
kp.arg = elem;
kp.level = level;
*num = 0;
do {
int len;
if (*num == max) {
pr_err("%s: can only take %i arguments\n", name, max);
return -EINVAL;
}
len = strcspn(val, ",");
save = val[len];
((char *)val)[len] = '\0';
check_kparam_locked(mod);
ret = set(val, &kp);
if (ret != 0)
return ret;
kp.arg += elemsize;
val += len+1;
(*num)++;
} while (save == ',');
if (*num < min) {
pr_err("%s: needs at least %i arguments\n", name, min);
return -EINVAL;
}
return 0;
}
static int param_array_set(const char *val, const struct kernel_param *kp)
{
const struct kparam_array *arr = kp->arr;
unsigned int temp_num;
return param_array(kp->mod, kp->name, val, 1, arr->max, arr->elem,
arr->elemsize, arr->ops->set, kp->level,
arr->num ?: &temp_num);
}
static int param_array_get(char *buffer, const struct kernel_param *kp)
{
int i, off, ret;
const struct kparam_array *arr = kp->arr;
struct kernel_param p = *kp;
for (i = off = 0; i < (arr->num ? *arr->num : arr->max); i++) {
if (i)
buffer[off - 1] = ',';
p.arg = arr->elem + arr->elemsize * i;
check_kparam_locked(p.mod);
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
pr_err("%s: string doesn't fit in %u chars.\n",
kp->name, kps->maxlen-1);
return -ENOSPC;
}
strcpy(kps->string, val);
return 0;
}
int param_get_string(char *buffer, const struct kernel_param *kp)
{
const struct kparam_string *kps = kp->str;
return scnprintf(buffer, PAGE_SIZE, "%s\n", kps->string);
}
static ssize_t param_attr_show(struct module_attribute *mattr,
struct module_kobject *mk, char *buf)
{
int count;
struct param_attribute *attribute = to_param_attr(mattr);
if (!attribute->param->ops->get)
return -EPERM;
kernel_param_lock(mk->mod);
count = attribute->param->ops->get(buf, attribute->param);
kernel_param_unlock(mk->mod);
return count;
}
static ssize_t param_attr_store(struct module_attribute *mattr,
struct module_kobject *mk,
const char *buf, size_t len)
{
int err;
struct param_attribute *attribute = to_param_attr(mattr);
if (!attribute->param->ops->set)
return -EPERM;
kernel_param_lock(mk->mod);
param_check_unsafe(attribute->param);
err = attribute->param->ops->set(buf, attribute->param);
kernel_param_unlock(mk->mod);
if (!err)
return len;
return err;
}
void kernel_param_lock(struct module *mod)
{
mutex_lock(KPARAM_MUTEX(mod));
}
void kernel_param_unlock(struct module *mod)
{
mutex_unlock(KPARAM_MUTEX(mod));
}
static __modinit int add_sysfs_param(struct module_kobject *mk,
const struct kernel_param *kp,
const char *name)
{
struct module_param_attrs *new_mp;
struct attribute **new_attrs;
unsigned int i;
BUG_ON(!kp->perm);
if (!mk->mp) {
mk->mp = kzalloc(sizeof(*mk->mp), GFP_KERNEL);
if (!mk->mp)
return -ENOMEM;
mk->mp->grp.name = "parameters";
mk->mp->grp.attrs = kzalloc(sizeof(mk->mp->grp.attrs[0]),
GFP_KERNEL);
if (!mk->mp->grp.attrs)
return -ENOMEM;
}
new_mp = krealloc(mk->mp,
sizeof(*mk->mp) +
sizeof(mk->mp->attrs[0]) * (mk->mp->num + 1),
GFP_KERNEL);
if (!new_mp)
return -ENOMEM;
mk->mp = new_mp;
new_attrs = krealloc(mk->mp->grp.attrs,
sizeof(mk->mp->grp.attrs[0]) * (mk->mp->num + 2),
GFP_KERNEL);
if (!new_attrs)
return -ENOMEM;
mk->mp->grp.attrs = new_attrs;
memset(&mk->mp->attrs[mk->mp->num], 0, sizeof(mk->mp->attrs[0]));
sysfs_attr_init(&mk->mp->attrs[mk->mp->num].mattr.attr);
mk->mp->attrs[mk->mp->num].param = kp;
mk->mp->attrs[mk->mp->num].mattr.show = param_attr_show;
if ((kp->perm & (S_IWUSR | S_IWGRP | S_IWOTH)) != 0)
mk->mp->attrs[mk->mp->num].mattr.store = param_attr_store;
else
mk->mp->attrs[mk->mp->num].mattr.store = NULL;
mk->mp->attrs[mk->mp->num].mattr.attr.name = (char *)name;
mk->mp->attrs[mk->mp->num].mattr.attr.mode = kp->perm;
mk->mp->num++;
for (i = 0; i < mk->mp->num; i++)
mk->mp->grp.attrs[i] = &mk->mp->attrs[i].mattr.attr;
mk->mp->grp.attrs[mk->mp->num] = NULL;
return 0;
}
static void free_module_param_attrs(struct module_kobject *mk)
{
if (mk->mp)
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
if (err) {
free_module_param_attrs(&mod->mkobj);
return err;
}
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
pr_crit("Adding module '%s' to sysfs failed (%d), the system may be unstable.\n",
name, err);
return NULL;
}
kobject_get(&mk->kobj);
}
return mk;
}
static void __init kernel_add_sysfs_param(const char *name,
const struct kernel_param *kparam,
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
const struct kernel_param *kp;
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
return scnprintf(buf, PAGE_SIZE, "%s\n", vattr->version);
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
WARN_ON_ONCE(err);
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
static void module_kobj_release(struct kobject *kobj)
{
struct module_kobject *mk = to_module_kobject(kobj);
complete(mk->kobj_completion);
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
