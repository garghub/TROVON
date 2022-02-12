int mic_open(struct inode *inode, struct file *f)
{
struct mic_vdev *mvdev;
struct mic_device *mdev = container_of(inode->i_cdev,
struct mic_device, cdev);
mvdev = kzalloc(sizeof(*mvdev), GFP_KERNEL);
if (!mvdev)
return -ENOMEM;
init_waitqueue_head(&mvdev->waitq);
INIT_LIST_HEAD(&mvdev->list);
mvdev->mdev = mdev;
mvdev->virtio_id = -1;
f->private_data = mvdev;
return 0;
}
int mic_release(struct inode *inode, struct file *f)
{
struct mic_vdev *mvdev = (struct mic_vdev *)f->private_data;
if (-1 != mvdev->virtio_id)
mic_virtio_del_device(mvdev);
f->private_data = NULL;
kfree(mvdev);
return 0;
}
long mic_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
{
struct mic_vdev *mvdev = (struct mic_vdev *)f->private_data;
void __user *argp = (void __user *)arg;
int ret;
switch (cmd) {
case MIC_VIRTIO_ADD_DEVICE:
{
ret = mic_virtio_add_device(mvdev, argp);
if (ret < 0) {
dev_err(mic_dev(mvdev),
"%s %d errno ret %d\n",
__func__, __LINE__, ret);
return ret;
}
break;
}
case MIC_VIRTIO_COPY_DESC:
{
struct mic_copy_desc copy;
ret = mic_vdev_inited(mvdev);
if (ret)
return ret;
if (copy_from_user(&copy, argp, sizeof(copy)))
return -EFAULT;
dev_dbg(mic_dev(mvdev),
"%s %d === iovcnt 0x%x vr_idx 0x%x update_used %d\n",
__func__, __LINE__, copy.iovcnt, copy.vr_idx,
copy.update_used);
ret = mic_virtio_copy_desc(mvdev, &copy);
if (ret < 0) {
dev_err(mic_dev(mvdev),
"%s %d errno ret %d\n",
__func__, __LINE__, ret);
return ret;
}
if (copy_to_user(
&((struct mic_copy_desc __user *)argp)->out_len,
&copy.out_len, sizeof(copy.out_len))) {
dev_err(mic_dev(mvdev), "%s %d errno ret %d\n",
__func__, __LINE__, -EFAULT);
return -EFAULT;
}
break;
}
case MIC_VIRTIO_CONFIG_CHANGE:
{
ret = mic_vdev_inited(mvdev);
if (ret)
return ret;
ret = mic_virtio_config_change(mvdev, argp);
if (ret < 0) {
dev_err(mic_dev(mvdev),
"%s %d errno ret %d\n",
__func__, __LINE__, ret);
return ret;
}
break;
}
default:
return -ENOIOCTLCMD;
};
return 0;
}
unsigned int mic_poll(struct file *f, poll_table *wait)
{
struct mic_vdev *mvdev = (struct mic_vdev *)f->private_data;
int mask = 0;
poll_wait(f, &mvdev->waitq, wait);
if (mic_vdev_inited(mvdev)) {
mask = POLLERR;
} else if (mvdev->poll_wake) {
mvdev->poll_wake = 0;
mask = POLLIN | POLLOUT;
}
return mask;
}
static inline int
mic_query_offset(struct mic_vdev *mvdev, unsigned long offset,
unsigned long *size, unsigned long *pa)
{
struct mic_device *mdev = mvdev->mdev;
unsigned long start = MIC_DP_SIZE;
int i;
if (!offset) {
*pa = virt_to_phys(mdev->dp);
*size = MIC_DP_SIZE;
return 0;
}
for (i = 0; i < mvdev->dd->num_vq; i++) {
struct mic_vringh *mvr = &mvdev->mvr[i];
if (offset == start) {
*pa = virt_to_phys(mvr->vring.va);
*size = mvr->vring.len;
return 0;
}
start += mvr->vring.len;
}
return -1;
}
int
mic_mmap(struct file *f, struct vm_area_struct *vma)
{
struct mic_vdev *mvdev = (struct mic_vdev *)f->private_data;
unsigned long offset = vma->vm_pgoff << PAGE_SHIFT;
unsigned long pa, size = vma->vm_end - vma->vm_start, size_rem = size;
int i, err;
err = mic_vdev_inited(mvdev);
if (err)
return err;
if (vma->vm_flags & VM_WRITE)
return -EACCES;
while (size_rem) {
i = mic_query_offset(mvdev, offset, &size, &pa);
if (i < 0)
return -EINVAL;
err = remap_pfn_range(vma, vma->vm_start + offset,
pa >> PAGE_SHIFT, size, vma->vm_page_prot);
if (err)
return err;
dev_dbg(mic_dev(mvdev),
"%s %d type %d size 0x%lx off 0x%lx pa 0x%lx vma 0x%lx\n",
__func__, __LINE__, mvdev->virtio_id, size, offset,
pa, vma->vm_start + offset);
size_rem -= size;
offset += size;
}
return 0;
}
