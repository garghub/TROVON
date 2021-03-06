static struct vfio_group *kvm_vfio_group_get_external_user(struct file *filep)
{
struct vfio_group *vfio_group;
struct vfio_group *(*fn)(struct file *);
fn = symbol_get(vfio_group_get_external_user);
if (!fn)
return ERR_PTR(-EINVAL);
vfio_group = fn(filep);
symbol_put(vfio_group_get_external_user);
return vfio_group;
}
static void kvm_vfio_group_put_external_user(struct vfio_group *vfio_group)
{
void (*fn)(struct vfio_group *);
fn = symbol_get(vfio_group_put_external_user);
if (!fn)
return;
fn(vfio_group);
symbol_put(vfio_group_put_external_user);
}
static bool kvm_vfio_group_is_coherent(struct vfio_group *vfio_group)
{
long (*fn)(struct vfio_group *, unsigned long);
long ret;
fn = symbol_get(vfio_external_check_extension);
if (!fn)
return false;
ret = fn(vfio_group, VFIO_DMA_CC_IOMMU);
symbol_put(vfio_external_check_extension);
return ret > 0;
}
static void kvm_vfio_update_coherency(struct kvm_device *dev)
{
struct kvm_vfio *kv = dev->private;
bool noncoherent = false;
struct kvm_vfio_group *kvg;
mutex_lock(&kv->lock);
list_for_each_entry(kvg, &kv->group_list, node) {
if (!kvm_vfio_group_is_coherent(kvg->vfio_group)) {
noncoherent = true;
break;
}
}
if (noncoherent != kv->noncoherent) {
kv->noncoherent = noncoherent;
if (kv->noncoherent)
kvm_arch_register_noncoherent_dma(dev->kvm);
else
kvm_arch_unregister_noncoherent_dma(dev->kvm);
}
mutex_unlock(&kv->lock);
}
static int kvm_vfio_set_group(struct kvm_device *dev, long attr, u64 arg)
{
struct kvm_vfio *kv = dev->private;
struct vfio_group *vfio_group;
struct kvm_vfio_group *kvg;
int32_t __user *argp = (int32_t __user *)(unsigned long)arg;
struct fd f;
int32_t fd;
int ret;
switch (attr) {
case KVM_DEV_VFIO_GROUP_ADD:
if (get_user(fd, argp))
return -EFAULT;
f = fdget(fd);
if (!f.file)
return -EBADF;
vfio_group = kvm_vfio_group_get_external_user(f.file);
fdput(f);
if (IS_ERR(vfio_group))
return PTR_ERR(vfio_group);
mutex_lock(&kv->lock);
list_for_each_entry(kvg, &kv->group_list, node) {
if (kvg->vfio_group == vfio_group) {
mutex_unlock(&kv->lock);
kvm_vfio_group_put_external_user(vfio_group);
return -EEXIST;
}
}
kvg = kzalloc(sizeof(*kvg), GFP_KERNEL);
if (!kvg) {
mutex_unlock(&kv->lock);
kvm_vfio_group_put_external_user(vfio_group);
return -ENOMEM;
}
list_add_tail(&kvg->node, &kv->group_list);
kvg->vfio_group = vfio_group;
mutex_unlock(&kv->lock);
kvm_vfio_update_coherency(dev);
return 0;
case KVM_DEV_VFIO_GROUP_DEL:
if (get_user(fd, argp))
return -EFAULT;
f = fdget(fd);
if (!f.file)
return -EBADF;
vfio_group = kvm_vfio_group_get_external_user(f.file);
fdput(f);
if (IS_ERR(vfio_group))
return PTR_ERR(vfio_group);
ret = -ENOENT;
mutex_lock(&kv->lock);
list_for_each_entry(kvg, &kv->group_list, node) {
if (kvg->vfio_group != vfio_group)
continue;
list_del(&kvg->node);
kvm_vfio_group_put_external_user(kvg->vfio_group);
kfree(kvg);
ret = 0;
break;
}
mutex_unlock(&kv->lock);
kvm_vfio_group_put_external_user(vfio_group);
kvm_vfio_update_coherency(dev);
return ret;
}
return -ENXIO;
}
static int kvm_vfio_set_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
switch (attr->group) {
case KVM_DEV_VFIO_GROUP:
return kvm_vfio_set_group(dev, attr->attr, attr->addr);
}
return -ENXIO;
}
static int kvm_vfio_has_attr(struct kvm_device *dev,
struct kvm_device_attr *attr)
{
switch (attr->group) {
case KVM_DEV_VFIO_GROUP:
switch (attr->attr) {
case KVM_DEV_VFIO_GROUP_ADD:
case KVM_DEV_VFIO_GROUP_DEL:
return 0;
}
break;
}
return -ENXIO;
}
static void kvm_vfio_destroy(struct kvm_device *dev)
{
struct kvm_vfio *kv = dev->private;
struct kvm_vfio_group *kvg, *tmp;
list_for_each_entry_safe(kvg, tmp, &kv->group_list, node) {
kvm_vfio_group_put_external_user(kvg->vfio_group);
list_del(&kvg->node);
kfree(kvg);
}
kvm_vfio_update_coherency(dev);
kfree(kv);
kfree(dev);
}
static int kvm_vfio_create(struct kvm_device *dev, u32 type)
{
struct kvm_device *tmp;
struct kvm_vfio *kv;
list_for_each_entry(tmp, &dev->kvm->devices, vm_node)
if (tmp->ops == &kvm_vfio_ops)
return -EBUSY;
kv = kzalloc(sizeof(*kv), GFP_KERNEL);
if (!kv)
return -ENOMEM;
INIT_LIST_HEAD(&kv->group_list);
mutex_init(&kv->lock);
dev->private = kv;
return 0;
}
