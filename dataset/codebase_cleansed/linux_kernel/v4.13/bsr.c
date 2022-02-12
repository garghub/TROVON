static ssize_t
bsr_size_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct bsr_dev *bsr_dev = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", bsr_dev->bsr_bytes);
}
static ssize_t
bsr_stride_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct bsr_dev *bsr_dev = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", bsr_dev->bsr_stride);
}
static ssize_t
bsr_length_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct bsr_dev *bsr_dev = dev_get_drvdata(dev);
return sprintf(buf, "%llu\n", bsr_dev->bsr_len);
}
static int bsr_mmap(struct file *filp, struct vm_area_struct *vma)
{
unsigned long size = vma->vm_end - vma->vm_start;
struct bsr_dev *dev = filp->private_data;
int ret;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
if (dev->bsr_len < PAGE_SIZE && size == PAGE_SIZE)
ret = remap_4k_pfn(vma, vma->vm_start, dev->bsr_addr >> 12,
vma->vm_page_prot);
else if (size <= dev->bsr_len)
ret = io_remap_pfn_range(vma, vma->vm_start,
dev->bsr_addr >> PAGE_SHIFT,
size, vma->vm_page_prot);
else
return -EINVAL;
if (ret)
return -EAGAIN;
return 0;
}
static int bsr_open(struct inode * inode, struct file * filp)
{
struct cdev *cdev = inode->i_cdev;
struct bsr_dev *dev = container_of(cdev, struct bsr_dev, bsr_cdev);
filp->private_data = dev;
return 0;
}
static void bsr_cleanup_devs(void)
{
struct bsr_dev *cur, *n;
list_for_each_entry_safe(cur, n, &bsr_devs, bsr_list) {
if (cur->bsr_device) {
cdev_del(&cur->bsr_cdev);
device_del(cur->bsr_device);
}
list_del(&cur->bsr_list);
kfree(cur);
}
}
static int bsr_add_node(struct device_node *bn)
{
int bsr_stride_len, bsr_bytes_len, num_bsr_devs;
const u32 *bsr_stride;
const u32 *bsr_bytes;
unsigned i;
int ret = -ENODEV;
bsr_stride = of_get_property(bn, "ibm,lock-stride", &bsr_stride_len);
bsr_bytes = of_get_property(bn, "ibm,#lock-bytes", &bsr_bytes_len);
if (!bsr_stride || !bsr_bytes ||
(bsr_stride_len != bsr_bytes_len)) {
printk(KERN_ERR "bsr of-node has missing/incorrect property\n");
return ret;
}
num_bsr_devs = bsr_bytes_len / sizeof(u32);
for (i = 0 ; i < num_bsr_devs; i++) {
struct bsr_dev *cur = kzalloc(sizeof(struct bsr_dev),
GFP_KERNEL);
struct resource res;
int result;
if (!cur) {
printk(KERN_ERR "Unable to alloc bsr dev\n");
ret = -ENOMEM;
goto out_err;
}
result = of_address_to_resource(bn, i, &res);
if (result < 0) {
printk(KERN_ERR "bsr of-node has invalid reg property, skipping\n");
kfree(cur);
continue;
}
cur->bsr_minor = i + total_bsr_devs;
cur->bsr_addr = res.start;
cur->bsr_len = resource_size(&res);
cur->bsr_bytes = bsr_bytes[i];
cur->bsr_stride = bsr_stride[i];
cur->bsr_dev = MKDEV(bsr_major, i + total_bsr_devs);
if (cur->bsr_len > 4096 && cur->bsr_len < PAGE_SIZE)
cur->bsr_len = 4096;
switch(cur->bsr_bytes) {
case 8:
cur->bsr_type = BSR_8;
break;
case 16:
cur->bsr_type = BSR_16;
break;
case 64:
cur->bsr_type = BSR_64;
break;
case 128:
cur->bsr_type = BSR_128;
break;
case 4096:
cur->bsr_type = BSR_4096;
break;
default:
cur->bsr_type = BSR_UNKNOWN;
}
cur->bsr_num = bsr_types[cur->bsr_type];
snprintf(cur->bsr_name, 32, "bsr%d_%d",
cur->bsr_bytes, cur->bsr_num);
cdev_init(&cur->bsr_cdev, &bsr_fops);
result = cdev_add(&cur->bsr_cdev, cur->bsr_dev, 1);
if (result) {
kfree(cur);
goto out_err;
}
cur->bsr_device = device_create(bsr_class, NULL, cur->bsr_dev,
cur, "%s", cur->bsr_name);
if (IS_ERR(cur->bsr_device)) {
printk(KERN_ERR "device_create failed for %s\n",
cur->bsr_name);
cdev_del(&cur->bsr_cdev);
kfree(cur);
goto out_err;
}
bsr_types[cur->bsr_type] = cur->bsr_num + 1;
list_add_tail(&cur->bsr_list, &bsr_devs);
}
total_bsr_devs += num_bsr_devs;
return 0;
out_err:
bsr_cleanup_devs();
return ret;
}
static int bsr_create_devs(struct device_node *bn)
{
int ret;
while (bn) {
ret = bsr_add_node(bn);
if (ret) {
of_node_put(bn);
return ret;
}
bn = of_find_compatible_node(bn, NULL, "ibm,bsr");
}
return 0;
}
static int __init bsr_init(void)
{
struct device_node *np;
dev_t bsr_dev;
int ret = -ENODEV;
np = of_find_compatible_node(NULL, NULL, "ibm,bsr");
if (!np)
goto out_err;
bsr_class = class_create(THIS_MODULE, "bsr");
if (IS_ERR(bsr_class)) {
printk(KERN_ERR "class_create() failed for bsr_class\n");
ret = PTR_ERR(bsr_class);
goto out_err_1;
}
bsr_class->dev_groups = bsr_dev_groups;
ret = alloc_chrdev_region(&bsr_dev, 0, BSR_MAX_DEVS, "bsr");
bsr_major = MAJOR(bsr_dev);
if (ret < 0) {
printk(KERN_ERR "alloc_chrdev_region() failed for bsr\n");
goto out_err_2;
}
if ((ret = bsr_create_devs(np)) < 0) {
np = NULL;
goto out_err_3;
}
return 0;
out_err_3:
unregister_chrdev_region(bsr_dev, BSR_MAX_DEVS);
out_err_2:
class_destroy(bsr_class);
out_err_1:
of_node_put(np);
out_err:
return ret;
}
static void __exit bsr_exit(void)
{
bsr_cleanup_devs();
if (bsr_class)
class_destroy(bsr_class);
if (bsr_major)
unregister_chrdev_region(MKDEV(bsr_major, 0), BSR_MAX_DEVS);
}
