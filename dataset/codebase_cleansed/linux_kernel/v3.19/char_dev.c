static inline int major_to_index(unsigned major)
{
return major % CHRDEV_MAJOR_HASH_SIZE;
}
void chrdev_show(struct seq_file *f, off_t offset)
{
struct char_device_struct *cd;
if (offset < CHRDEV_MAJOR_HASH_SIZE) {
mutex_lock(&chrdevs_lock);
for (cd = chrdevs[offset]; cd; cd = cd->next)
seq_printf(f, "%3d %s\n", cd->major, cd->name);
mutex_unlock(&chrdevs_lock);
}
}
static struct char_device_struct *
__register_chrdev_region(unsigned int major, unsigned int baseminor,
int minorct, const char *name)
{
struct char_device_struct *cd, **cp;
int ret = 0;
int i;
cd = kzalloc(sizeof(struct char_device_struct), GFP_KERNEL);
if (cd == NULL)
return ERR_PTR(-ENOMEM);
mutex_lock(&chrdevs_lock);
if (major == 0) {
for (i = ARRAY_SIZE(chrdevs)-1; i > 0; i--) {
if (chrdevs[i] == NULL)
break;
}
if (i == 0) {
ret = -EBUSY;
goto out;
}
major = i;
}
cd->major = major;
cd->baseminor = baseminor;
cd->minorct = minorct;
strlcpy(cd->name, name, sizeof(cd->name));
i = major_to_index(major);
for (cp = &chrdevs[i]; *cp; cp = &(*cp)->next)
if ((*cp)->major > major ||
((*cp)->major == major &&
(((*cp)->baseminor >= baseminor) ||
((*cp)->baseminor + (*cp)->minorct > baseminor))))
break;
if (*cp && (*cp)->major == major) {
int old_min = (*cp)->baseminor;
int old_max = (*cp)->baseminor + (*cp)->minorct - 1;
int new_min = baseminor;
int new_max = baseminor + minorct - 1;
if (new_max >= old_min && new_max <= old_max) {
ret = -EBUSY;
goto out;
}
if (new_min <= old_max && new_min >= old_min) {
ret = -EBUSY;
goto out;
}
}
cd->next = *cp;
*cp = cd;
mutex_unlock(&chrdevs_lock);
return cd;
out:
mutex_unlock(&chrdevs_lock);
kfree(cd);
return ERR_PTR(ret);
}
static struct char_device_struct *
__unregister_chrdev_region(unsigned major, unsigned baseminor, int minorct)
{
struct char_device_struct *cd = NULL, **cp;
int i = major_to_index(major);
mutex_lock(&chrdevs_lock);
for (cp = &chrdevs[i]; *cp; cp = &(*cp)->next)
if ((*cp)->major == major &&
(*cp)->baseminor == baseminor &&
(*cp)->minorct == minorct)
break;
if (*cp) {
cd = *cp;
*cp = cd->next;
}
mutex_unlock(&chrdevs_lock);
return cd;
}
int register_chrdev_region(dev_t from, unsigned count, const char *name)
{
struct char_device_struct *cd;
dev_t to = from + count;
dev_t n, next;
for (n = from; n < to; n = next) {
next = MKDEV(MAJOR(n)+1, 0);
if (next > to)
next = to;
cd = __register_chrdev_region(MAJOR(n), MINOR(n),
next - n, name);
if (IS_ERR(cd))
goto fail;
}
return 0;
fail:
to = n;
for (n = from; n < to; n = next) {
next = MKDEV(MAJOR(n)+1, 0);
kfree(__unregister_chrdev_region(MAJOR(n), MINOR(n), next - n));
}
return PTR_ERR(cd);
}
int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count,
const char *name)
{
struct char_device_struct *cd;
cd = __register_chrdev_region(0, baseminor, count, name);
if (IS_ERR(cd))
return PTR_ERR(cd);
*dev = MKDEV(cd->major, cd->baseminor);
return 0;
}
int __register_chrdev(unsigned int major, unsigned int baseminor,
unsigned int count, const char *name,
const struct file_operations *fops)
{
struct char_device_struct *cd;
struct cdev *cdev;
int err = -ENOMEM;
cd = __register_chrdev_region(major, baseminor, count, name);
if (IS_ERR(cd))
return PTR_ERR(cd);
cdev = cdev_alloc();
if (!cdev)
goto out2;
cdev->owner = fops->owner;
cdev->ops = fops;
kobject_set_name(&cdev->kobj, "%s", name);
err = cdev_add(cdev, MKDEV(cd->major, baseminor), count);
if (err)
goto out;
cd->cdev = cdev;
return major ? 0 : cd->major;
out:
kobject_put(&cdev->kobj);
out2:
kfree(__unregister_chrdev_region(cd->major, baseminor, count));
return err;
}
void unregister_chrdev_region(dev_t from, unsigned count)
{
dev_t to = from + count;
dev_t n, next;
for (n = from; n < to; n = next) {
next = MKDEV(MAJOR(n)+1, 0);
if (next > to)
next = to;
kfree(__unregister_chrdev_region(MAJOR(n), MINOR(n), next - n));
}
}
void __unregister_chrdev(unsigned int major, unsigned int baseminor,
unsigned int count, const char *name)
{
struct char_device_struct *cd;
cd = __unregister_chrdev_region(major, baseminor, count);
if (cd && cd->cdev)
cdev_del(cd->cdev);
kfree(cd);
}
static struct kobject *cdev_get(struct cdev *p)
{
struct module *owner = p->owner;
struct kobject *kobj;
if (owner && !try_module_get(owner))
return NULL;
kobj = kobject_get(&p->kobj);
if (!kobj)
module_put(owner);
return kobj;
}
void cdev_put(struct cdev *p)
{
if (p) {
struct module *owner = p->owner;
kobject_put(&p->kobj);
module_put(owner);
}
}
static int chrdev_open(struct inode *inode, struct file *filp)
{
const struct file_operations *fops;
struct cdev *p;
struct cdev *new = NULL;
int ret = 0;
spin_lock(&cdev_lock);
p = inode->i_cdev;
if (!p) {
struct kobject *kobj;
int idx;
spin_unlock(&cdev_lock);
kobj = kobj_lookup(cdev_map, inode->i_rdev, &idx);
if (!kobj)
return -ENXIO;
new = container_of(kobj, struct cdev, kobj);
spin_lock(&cdev_lock);
p = inode->i_cdev;
if (!p) {
inode->i_cdev = p = new;
list_add(&inode->i_devices, &p->list);
new = NULL;
} else if (!cdev_get(p))
ret = -ENXIO;
} else if (!cdev_get(p))
ret = -ENXIO;
spin_unlock(&cdev_lock);
cdev_put(new);
if (ret)
return ret;
ret = -ENXIO;
fops = fops_get(p->ops);
if (!fops)
goto out_cdev_put;
replace_fops(filp, fops);
if (filp->f_op->open) {
ret = filp->f_op->open(inode, filp);
if (ret)
goto out_cdev_put;
}
return 0;
out_cdev_put:
cdev_put(p);
return ret;
}
void cd_forget(struct inode *inode)
{
spin_lock(&cdev_lock);
list_del_init(&inode->i_devices);
inode->i_cdev = NULL;
spin_unlock(&cdev_lock);
}
static void cdev_purge(struct cdev *cdev)
{
spin_lock(&cdev_lock);
while (!list_empty(&cdev->list)) {
struct inode *inode;
inode = container_of(cdev->list.next, struct inode, i_devices);
list_del_init(&inode->i_devices);
inode->i_cdev = NULL;
}
spin_unlock(&cdev_lock);
}
static struct kobject *exact_match(dev_t dev, int *part, void *data)
{
struct cdev *p = data;
return &p->kobj;
}
static int exact_lock(dev_t dev, void *data)
{
struct cdev *p = data;
return cdev_get(p) ? 0 : -1;
}
int cdev_add(struct cdev *p, dev_t dev, unsigned count)
{
int error;
p->dev = dev;
p->count = count;
error = kobj_map(cdev_map, dev, count, NULL,
exact_match, exact_lock, p);
if (error)
return error;
kobject_get(p->kobj.parent);
return 0;
}
static void cdev_unmap(dev_t dev, unsigned count)
{
kobj_unmap(cdev_map, dev, count);
}
void cdev_del(struct cdev *p)
{
cdev_unmap(p->dev, p->count);
kobject_put(&p->kobj);
}
static void cdev_default_release(struct kobject *kobj)
{
struct cdev *p = container_of(kobj, struct cdev, kobj);
struct kobject *parent = kobj->parent;
cdev_purge(p);
kobject_put(parent);
}
static void cdev_dynamic_release(struct kobject *kobj)
{
struct cdev *p = container_of(kobj, struct cdev, kobj);
struct kobject *parent = kobj->parent;
cdev_purge(p);
kfree(p);
kobject_put(parent);
}
struct cdev *cdev_alloc(void)
{
struct cdev *p = kzalloc(sizeof(struct cdev), GFP_KERNEL);
if (p) {
INIT_LIST_HEAD(&p->list);
kobject_init(&p->kobj, &ktype_cdev_dynamic);
}
return p;
}
void cdev_init(struct cdev *cdev, const struct file_operations *fops)
{
memset(cdev, 0, sizeof *cdev);
INIT_LIST_HEAD(&cdev->list);
kobject_init(&cdev->kobj, &ktype_cdev_default);
cdev->ops = fops;
}
static struct kobject *base_probe(dev_t dev, int *part, void *data)
{
if (request_module("char-major-%d-%d", MAJOR(dev), MINOR(dev)) > 0)
request_module("char-major-%d", MAJOR(dev));
return NULL;
}
void __init chrdev_init(void)
{
cdev_map = kobj_map_init(base_probe, &chrdevs_lock);
if (bdi_init(&directly_mappable_cdev_bdi))
panic("Failed to init directly mappable cdev bdi");
}
