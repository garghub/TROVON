static void
dcssblk_release_segment(struct device *dev)
{
struct dcssblk_dev_info *dev_info;
struct segment_info *entry, *temp;
dev_info = container_of(dev, struct dcssblk_dev_info, dev);
list_for_each_entry_safe(entry, temp, &dev_info->seg_list, lh) {
list_del(&entry->lh);
kfree(entry);
}
kfree(dev_info);
module_put(THIS_MODULE);
}
static int
dcssblk_assign_free_minor(struct dcssblk_dev_info *dev_info)
{
int minor, found;
struct dcssblk_dev_info *entry;
if (dev_info == NULL)
return -EINVAL;
for (minor = 0; minor < (1<<MINORBITS); minor++) {
found = 0;
list_for_each_entry(entry, &dcssblk_devices, lh)
if (minor == entry->gd->first_minor)
found++;
if (!found) break;
}
if (found)
return -EBUSY;
dev_info->gd->first_minor = minor;
return 0;
}
static struct dcssblk_dev_info *
dcssblk_get_device_by_name(char *name)
{
struct dcssblk_dev_info *entry;
list_for_each_entry(entry, &dcssblk_devices, lh) {
if (!strcmp(name, entry->segment_name)) {
return entry;
}
}
return NULL;
}
static struct segment_info *
dcssblk_get_segment_by_name(char *name)
{
struct dcssblk_dev_info *dev_info;
struct segment_info *entry;
list_for_each_entry(dev_info, &dcssblk_devices, lh) {
list_for_each_entry(entry, &dev_info->seg_list, lh) {
if (!strcmp(name, entry->segment_name))
return entry;
}
}
return NULL;
}
static unsigned long
dcssblk_find_highest_addr(struct dcssblk_dev_info *dev_info)
{
unsigned long highest_addr;
struct segment_info *entry;
highest_addr = 0;
list_for_each_entry(entry, &dev_info->seg_list, lh) {
if (highest_addr < entry->end)
highest_addr = entry->end;
}
return highest_addr;
}
static unsigned long
dcssblk_find_lowest_addr(struct dcssblk_dev_info *dev_info)
{
int set_first;
unsigned long lowest_addr;
struct segment_info *entry;
set_first = 0;
lowest_addr = 0;
list_for_each_entry(entry, &dev_info->seg_list, lh) {
if (set_first == 0) {
lowest_addr = entry->start;
set_first = 1;
} else {
if (lowest_addr > entry->start)
lowest_addr = entry->start;
}
}
return lowest_addr;
}
static int
dcssblk_is_continuous(struct dcssblk_dev_info *dev_info)
{
int i, j, rc;
struct segment_info *sort_list, *entry, temp;
if (dev_info->num_of_segments <= 1)
return 0;
sort_list = kzalloc(
sizeof(struct segment_info) * dev_info->num_of_segments,
GFP_KERNEL);
if (sort_list == NULL)
return -ENOMEM;
i = 0;
list_for_each_entry(entry, &dev_info->seg_list, lh) {
memcpy(&sort_list[i], entry, sizeof(struct segment_info));
i++;
}
for (i = 0; i < dev_info->num_of_segments; i++)
for (j = 0; j < dev_info->num_of_segments; j++)
if (sort_list[j].start > sort_list[i].start) {
memcpy(&temp, &sort_list[i],
sizeof(struct segment_info));
memcpy(&sort_list[i], &sort_list[j],
sizeof(struct segment_info));
memcpy(&sort_list[j], &temp,
sizeof(struct segment_info));
}
for (i = 0; i < dev_info->num_of_segments - 1; i++) {
if ((sort_list[i].end + 1) != sort_list[i+1].start) {
pr_err("Adjacent DCSSs %s and %s are not "
"contiguous\n", sort_list[i].segment_name,
sort_list[i+1].segment_name);
rc = -EINVAL;
goto out;
}
if (sort_list[i].segment_type != sort_list[i+1].segment_type) {
if (!(sort_list[i].segment_type & SEGMENT_EXCLUSIVE) ||
(sort_list[i].segment_type == SEG_TYPE_ER) ||
!(sort_list[i+1].segment_type &
SEGMENT_EXCLUSIVE) ||
(sort_list[i+1].segment_type == SEG_TYPE_ER)) {
pr_err("DCSS %s and DCSS %s have "
"incompatible types\n",
sort_list[i].segment_name,
sort_list[i+1].segment_name);
rc = -EINVAL;
goto out;
}
}
}
rc = 0;
out:
kfree(sort_list);
return rc;
}
static int
dcssblk_load_segment(char *name, struct segment_info **seg_info)
{
int rc;
down_read(&dcssblk_devices_sem);
*seg_info = dcssblk_get_segment_by_name(name);
up_read(&dcssblk_devices_sem);
if (*seg_info != NULL)
return -EEXIST;
*seg_info = kzalloc(sizeof(struct segment_info), GFP_KERNEL);
if (*seg_info == NULL)
return -ENOMEM;
strcpy((*seg_info)->segment_name, name);
rc = segment_load(name, SEGMENT_SHARED,
&(*seg_info)->start, &(*seg_info)->end);
if (rc < 0) {
segment_warning(rc, (*seg_info)->segment_name);
kfree(*seg_info);
} else {
INIT_LIST_HEAD(&(*seg_info)->lh);
(*seg_info)->segment_type = rc;
}
return rc;
}
static void dcssblk_unregister_callback(struct device *dev)
{
device_unregister(dev);
put_device(dev);
}
static ssize_t
dcssblk_shared_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dcssblk_dev_info *dev_info;
dev_info = container_of(dev, struct dcssblk_dev_info, dev);
return sprintf(buf, dev_info->is_shared ? "1\n" : "0\n");
}
static ssize_t
dcssblk_shared_store(struct device *dev, struct device_attribute *attr, const char *inbuf, size_t count)
{
struct dcssblk_dev_info *dev_info;
struct segment_info *entry, *temp;
int rc;
if ((count > 1) && (inbuf[1] != '\n') && (inbuf[1] != '\0'))
return -EINVAL;
down_write(&dcssblk_devices_sem);
dev_info = container_of(dev, struct dcssblk_dev_info, dev);
if (atomic_read(&dev_info->use_count)) {
rc = -EBUSY;
goto out;
}
if (inbuf[0] == '1') {
list_for_each_entry(entry, &dev_info->seg_list, lh) {
rc = segment_modify_shared(entry->segment_name,
SEGMENT_SHARED);
if (rc < 0) {
BUG_ON(rc == -EINVAL);
if (rc != -EAGAIN)
goto removeseg;
}
}
dev_info->is_shared = 1;
switch (dev_info->segment_type) {
case SEG_TYPE_SR:
case SEG_TYPE_ER:
case SEG_TYPE_SC:
set_disk_ro(dev_info->gd, 1);
}
} else if (inbuf[0] == '0') {
if (dev_info->segment_type == SEG_TYPE_SC) {
pr_err("DCSS %s is of type SC and cannot be "
"loaded as exclusive-writable\n",
dev_info->segment_name);
rc = -EINVAL;
goto out;
}
list_for_each_entry(entry, &dev_info->seg_list, lh) {
rc = segment_modify_shared(entry->segment_name,
SEGMENT_EXCLUSIVE);
if (rc < 0) {
BUG_ON(rc == -EINVAL);
if (rc != -EAGAIN)
goto removeseg;
}
}
dev_info->is_shared = 0;
set_disk_ro(dev_info->gd, 0);
} else {
rc = -EINVAL;
goto out;
}
rc = count;
goto out;
removeseg:
pr_err("DCSS device %s is removed after a failed access mode "
"change\n", dev_info->segment_name);
temp = entry;
list_for_each_entry(entry, &dev_info->seg_list, lh) {
if (entry != temp)
segment_unload(entry->segment_name);
}
list_del(&dev_info->lh);
del_gendisk(dev_info->gd);
blk_cleanup_queue(dev_info->dcssblk_queue);
dev_info->gd->queue = NULL;
put_disk(dev_info->gd);
rc = device_schedule_callback(dev, dcssblk_unregister_callback);
out:
up_write(&dcssblk_devices_sem);
return rc;
}
static ssize_t
dcssblk_save_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct dcssblk_dev_info *dev_info;
dev_info = container_of(dev, struct dcssblk_dev_info, dev);
return sprintf(buf, dev_info->save_pending ? "1\n" : "0\n");
}
static ssize_t
dcssblk_save_store(struct device *dev, struct device_attribute *attr, const char *inbuf, size_t count)
{
struct dcssblk_dev_info *dev_info;
struct segment_info *entry;
if ((count > 1) && (inbuf[1] != '\n') && (inbuf[1] != '\0'))
return -EINVAL;
dev_info = container_of(dev, struct dcssblk_dev_info, dev);
down_write(&dcssblk_devices_sem);
if (inbuf[0] == '1') {
if (atomic_read(&dev_info->use_count) == 0) {
pr_info("All DCSSs that map to device %s are "
"saved\n", dev_info->segment_name);
list_for_each_entry(entry, &dev_info->seg_list, lh) {
segment_save(entry->segment_name);
}
} else {
pr_info("Device %s is in use, its DCSSs will be "
"saved when it becomes idle\n",
dev_info->segment_name);
dev_info->save_pending = 1;
}
} else if (inbuf[0] == '0') {
if (dev_info->save_pending) {
dev_info->save_pending = 0;
pr_info("A pending save request for device %s "
"has been canceled\n",
dev_info->segment_name);
}
} else {
up_write(&dcssblk_devices_sem);
return -EINVAL;
}
up_write(&dcssblk_devices_sem);
return count;
}
static ssize_t
dcssblk_seglist_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int i;
struct dcssblk_dev_info *dev_info;
struct segment_info *entry;
down_read(&dcssblk_devices_sem);
dev_info = container_of(dev, struct dcssblk_dev_info, dev);
i = 0;
buf[0] = '\0';
list_for_each_entry(entry, &dev_info->seg_list, lh) {
strcpy(&buf[i], entry->segment_name);
i += strlen(entry->segment_name);
buf[i] = '\n';
i++;
}
up_read(&dcssblk_devices_sem);
return i;
}
static ssize_t
dcssblk_add_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
int rc, i, j, num_of_segments;
struct dcssblk_dev_info *dev_info;
struct segment_info *seg_info, *temp;
char *local_buf;
unsigned long seg_byte_size;
dev_info = NULL;
seg_info = NULL;
if (dev != dcssblk_root_dev) {
rc = -EINVAL;
goto out_nobuf;
}
if ((count < 1) || (buf[0] == '\0') || (buf[0] == '\n')) {
rc = -ENAMETOOLONG;
goto out_nobuf;
}
local_buf = kmalloc(count + 1, GFP_KERNEL);
if (local_buf == NULL) {
rc = -ENOMEM;
goto out_nobuf;
}
num_of_segments = 0;
for (i = 0; ((buf[i] != '\0') && (buf[i] != '\n') && i < count); i++) {
for (j = i; (buf[j] != ':') &&
(buf[j] != '\0') &&
(buf[j] != '\n') &&
j < count; j++) {
local_buf[j-i] = toupper(buf[j]);
}
local_buf[j-i] = '\0';
if (((j - i) == 0) || ((j - i) > 8)) {
rc = -ENAMETOOLONG;
goto seg_list_del;
}
rc = dcssblk_load_segment(local_buf, &seg_info);
if (rc < 0)
goto seg_list_del;
if (num_of_segments == 0) {
dev_info = kzalloc(sizeof(struct dcssblk_dev_info),
GFP_KERNEL);
if (dev_info == NULL) {
rc = -ENOMEM;
goto out;
}
strcpy(dev_info->segment_name, local_buf);
dev_info->segment_type = seg_info->segment_type;
INIT_LIST_HEAD(&dev_info->seg_list);
}
list_add_tail(&seg_info->lh, &dev_info->seg_list);
num_of_segments++;
i = j;
if ((buf[j] == '\0') || (buf[j] == '\n'))
break;
}
if ((i > 0) && (buf[i-1] == ':')) {
rc = -ENAMETOOLONG;
goto seg_list_del;
}
strlcpy(local_buf, buf, i + 1);
dev_info->num_of_segments = num_of_segments;
rc = dcssblk_is_continuous(dev_info);
if (rc < 0)
goto seg_list_del;
dev_info->start = dcssblk_find_lowest_addr(dev_info);
dev_info->end = dcssblk_find_highest_addr(dev_info);
dev_set_name(&dev_info->dev, dev_info->segment_name);
dev_info->dev.release = dcssblk_release_segment;
dev_info->dev.groups = dcssblk_dev_attr_groups;
INIT_LIST_HEAD(&dev_info->lh);
dev_info->gd = alloc_disk(DCSSBLK_MINORS_PER_DISK);
if (dev_info->gd == NULL) {
rc = -ENOMEM;
goto seg_list_del;
}
dev_info->gd->major = dcssblk_major;
dev_info->gd->fops = &dcssblk_devops;
dev_info->dcssblk_queue = blk_alloc_queue(GFP_KERNEL);
dev_info->gd->queue = dev_info->dcssblk_queue;
dev_info->gd->private_data = dev_info;
dev_info->gd->driverfs_dev = &dev_info->dev;
blk_queue_make_request(dev_info->dcssblk_queue, dcssblk_make_request);
blk_queue_logical_block_size(dev_info->dcssblk_queue, 4096);
seg_byte_size = (dev_info->end - dev_info->start + 1);
set_capacity(dev_info->gd, seg_byte_size >> 9);
pr_info("Loaded %s with total size %lu bytes and capacity %lu "
"sectors\n", local_buf, seg_byte_size, seg_byte_size >> 9);
dev_info->save_pending = 0;
dev_info->is_shared = 1;
dev_info->dev.parent = dcssblk_root_dev;
down_write(&dcssblk_devices_sem);
if (dcssblk_get_segment_by_name(local_buf)) {
rc = -EEXIST;
goto release_gd;
}
rc = dcssblk_assign_free_minor(dev_info);
if (rc)
goto release_gd;
sprintf(dev_info->gd->disk_name, "dcssblk%d",
dev_info->gd->first_minor);
list_add_tail(&dev_info->lh, &dcssblk_devices);
if (!try_module_get(THIS_MODULE)) {
rc = -ENODEV;
goto dev_list_del;
}
rc = device_register(&dev_info->dev);
if (rc)
goto put_dev;
get_device(&dev_info->dev);
add_disk(dev_info->gd);
switch (dev_info->segment_type) {
case SEG_TYPE_SR:
case SEG_TYPE_ER:
case SEG_TYPE_SC:
set_disk_ro(dev_info->gd,1);
break;
default:
set_disk_ro(dev_info->gd,0);
break;
}
up_write(&dcssblk_devices_sem);
rc = count;
goto out;
put_dev:
list_del(&dev_info->lh);
blk_cleanup_queue(dev_info->dcssblk_queue);
dev_info->gd->queue = NULL;
put_disk(dev_info->gd);
list_for_each_entry(seg_info, &dev_info->seg_list, lh) {
segment_unload(seg_info->segment_name);
}
put_device(&dev_info->dev);
up_write(&dcssblk_devices_sem);
goto out;
dev_list_del:
list_del(&dev_info->lh);
release_gd:
blk_cleanup_queue(dev_info->dcssblk_queue);
dev_info->gd->queue = NULL;
put_disk(dev_info->gd);
up_write(&dcssblk_devices_sem);
seg_list_del:
if (dev_info == NULL)
goto out;
list_for_each_entry_safe(seg_info, temp, &dev_info->seg_list, lh) {
list_del(&seg_info->lh);
segment_unload(seg_info->segment_name);
kfree(seg_info);
}
kfree(dev_info);
out:
kfree(local_buf);
out_nobuf:
return rc;
}
static ssize_t
dcssblk_remove_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
struct dcssblk_dev_info *dev_info;
struct segment_info *entry;
int rc, i;
char *local_buf;
if (dev != dcssblk_root_dev) {
return -EINVAL;
}
local_buf = kmalloc(count + 1, GFP_KERNEL);
if (local_buf == NULL) {
return -ENOMEM;
}
for (i = 0; ((*(buf+i)!='\0') && (*(buf+i)!='\n') && i < count); i++) {
local_buf[i] = toupper(buf[i]);
}
local_buf[i] = '\0';
if ((i == 0) || (i > 8)) {
rc = -ENAMETOOLONG;
goto out_buf;
}
down_write(&dcssblk_devices_sem);
dev_info = dcssblk_get_device_by_name(local_buf);
if (dev_info == NULL) {
up_write(&dcssblk_devices_sem);
pr_warning("Device %s cannot be removed because it is not a "
"known device\n", local_buf);
rc = -ENODEV;
goto out_buf;
}
if (atomic_read(&dev_info->use_count) != 0) {
up_write(&dcssblk_devices_sem);
pr_warning("Device %s cannot be removed while it is in "
"use\n", local_buf);
rc = -EBUSY;
goto out_buf;
}
list_del(&dev_info->lh);
del_gendisk(dev_info->gd);
blk_cleanup_queue(dev_info->dcssblk_queue);
dev_info->gd->queue = NULL;
put_disk(dev_info->gd);
device_unregister(&dev_info->dev);
list_for_each_entry(entry, &dev_info->seg_list, lh)
segment_unload(entry->segment_name);
put_device(&dev_info->dev);
up_write(&dcssblk_devices_sem);
rc = count;
out_buf:
kfree(local_buf);
return rc;
}
static int
dcssblk_open(struct block_device *bdev, fmode_t mode)
{
struct dcssblk_dev_info *dev_info;
int rc;
dev_info = bdev->bd_disk->private_data;
if (NULL == dev_info) {
rc = -ENODEV;
goto out;
}
atomic_inc(&dev_info->use_count);
bdev->bd_block_size = 4096;
rc = 0;
out:
return rc;
}
static void
dcssblk_release(struct gendisk *disk, fmode_t mode)
{
struct dcssblk_dev_info *dev_info = disk->private_data;
struct segment_info *entry;
if (!dev_info) {
WARN_ON(1);
return;
}
down_write(&dcssblk_devices_sem);
if (atomic_dec_and_test(&dev_info->use_count)
&& (dev_info->save_pending)) {
pr_info("Device %s has become idle and is being saved "
"now\n", dev_info->segment_name);
list_for_each_entry(entry, &dev_info->seg_list, lh) {
segment_save(entry->segment_name);
}
dev_info->save_pending = 0;
}
up_write(&dcssblk_devices_sem);
}
static void
dcssblk_make_request(struct request_queue *q, struct bio *bio)
{
struct dcssblk_dev_info *dev_info;
struct bio_vec *bvec;
unsigned long index;
unsigned long page_addr;
unsigned long source_addr;
unsigned long bytes_done;
int i;
bytes_done = 0;
dev_info = bio->bi_bdev->bd_disk->private_data;
if (dev_info == NULL)
goto fail;
if ((bio->bi_sector & 7) != 0 || (bio->bi_size & 4095) != 0)
goto fail;
if (bio_end_sector(bio) > get_capacity(bio->bi_bdev->bd_disk)) {
goto fail;
}
if (dev_info->is_shared) {
switch (dev_info->segment_type) {
case SEG_TYPE_SR:
case SEG_TYPE_ER:
case SEG_TYPE_SC:
if (bio_data_dir(bio) == WRITE) {
pr_warning("Writing to %s failed because it "
"is a read-only device\n",
dev_name(&dev_info->dev));
goto fail;
}
}
}
index = (bio->bi_sector >> 3);
bio_for_each_segment(bvec, bio, i) {
page_addr = (unsigned long)
page_address(bvec->bv_page) + bvec->bv_offset;
source_addr = dev_info->start + (index<<12) + bytes_done;
if (unlikely((page_addr & 4095) != 0) || (bvec->bv_len & 4095) != 0)
goto fail;
if (bio_data_dir(bio) == READ) {
memcpy((void*)page_addr, (void*)source_addr,
bvec->bv_len);
} else {
memcpy((void*)source_addr, (void*)page_addr,
bvec->bv_len);
}
bytes_done += bvec->bv_len;
}
bio_endio(bio, 0);
return;
fail:
bio_io_error(bio);
}
static int
dcssblk_direct_access (struct block_device *bdev, sector_t secnum,
void **kaddr, unsigned long *pfn)
{
struct dcssblk_dev_info *dev_info;
unsigned long pgoff;
dev_info = bdev->bd_disk->private_data;
if (!dev_info)
return -ENODEV;
if (secnum % (PAGE_SIZE/512))
return -EINVAL;
pgoff = secnum / (PAGE_SIZE / 512);
if ((pgoff+1)*PAGE_SIZE-1 > dev_info->end - dev_info->start)
return -ERANGE;
*kaddr = (void *) (dev_info->start+pgoff*PAGE_SIZE);
*pfn = virt_to_phys(*kaddr) >> PAGE_SHIFT;
return 0;
}
static void
dcssblk_check_params(void)
{
int rc, i, j, k;
char buf[DCSSBLK_PARM_LEN + 1];
struct dcssblk_dev_info *dev_info;
for (i = 0; (i < DCSSBLK_PARM_LEN) && (dcssblk_segments[i] != '\0');
i++) {
for (j = i; (dcssblk_segments[j] != ',') &&
(dcssblk_segments[j] != '\0') &&
(dcssblk_segments[j] != '(') &&
(j < DCSSBLK_PARM_LEN); j++)
{
buf[j-i] = dcssblk_segments[j];
}
buf[j-i] = '\0';
rc = dcssblk_add_store(dcssblk_root_dev, NULL, buf, j-i);
if ((rc >= 0) && (dcssblk_segments[j] == '(')) {
for (k = 0; (buf[k] != ':') && (buf[k] != '\0'); k++)
buf[k] = toupper(buf[k]);
buf[k] = '\0';
if (!strncmp(&dcssblk_segments[j], "(local)", 7)) {
down_read(&dcssblk_devices_sem);
dev_info = dcssblk_get_device_by_name(buf);
up_read(&dcssblk_devices_sem);
if (dev_info)
dcssblk_shared_store(&dev_info->dev,
NULL, "0\n", 2);
}
}
while ((dcssblk_segments[j] != ',') &&
(dcssblk_segments[j] != '\0'))
{
j++;
}
if (dcssblk_segments[j] == '\0')
break;
i = j;
}
}
static int dcssblk_freeze(struct device *dev)
{
struct dcssblk_dev_info *dev_info;
int rc = 0;
list_for_each_entry(dev_info, &dcssblk_devices, lh) {
switch (dev_info->segment_type) {
case SEG_TYPE_SR:
case SEG_TYPE_ER:
case SEG_TYPE_SC:
if (!dev_info->is_shared)
rc = -EINVAL;
break;
default:
rc = -EINVAL;
break;
}
if (rc)
break;
}
if (rc)
pr_err("Suspending the system failed because DCSS device %s "
"is writable\n",
dev_info->segment_name);
return rc;
}
static int dcssblk_restore(struct device *dev)
{
struct dcssblk_dev_info *dev_info;
struct segment_info *entry;
unsigned long start, end;
int rc = 0;
list_for_each_entry(dev_info, &dcssblk_devices, lh) {
list_for_each_entry(entry, &dev_info->seg_list, lh) {
segment_unload(entry->segment_name);
rc = segment_load(entry->segment_name, SEGMENT_SHARED,
&start, &end);
if (rc < 0) {
segment_warning(rc, entry->segment_name);
goto out_panic;
}
if (start != entry->start || end != entry->end) {
pr_err("The address range of DCSS %s changed "
"while the system was suspended\n",
entry->segment_name);
goto out_panic;
}
}
}
return 0;
out_panic:
panic("fatal dcssblk resume error\n");
}
static int dcssblk_thaw(struct device *dev)
{
return 0;
}
static void __exit
dcssblk_exit(void)
{
platform_device_unregister(dcssblk_pdev);
platform_driver_unregister(&dcssblk_pdrv);
root_device_unregister(dcssblk_root_dev);
unregister_blkdev(dcssblk_major, DCSSBLK_NAME);
}
static int __init
dcssblk_init(void)
{
int rc;
rc = platform_driver_register(&dcssblk_pdrv);
if (rc)
return rc;
dcssblk_pdev = platform_device_register_simple("dcssblk", -1, NULL,
0);
if (IS_ERR(dcssblk_pdev)) {
rc = PTR_ERR(dcssblk_pdev);
goto out_pdrv;
}
dcssblk_root_dev = root_device_register("dcssblk");
if (IS_ERR(dcssblk_root_dev)) {
rc = PTR_ERR(dcssblk_root_dev);
goto out_pdev;
}
rc = device_create_file(dcssblk_root_dev, &dev_attr_add);
if (rc)
goto out_root;
rc = device_create_file(dcssblk_root_dev, &dev_attr_remove);
if (rc)
goto out_root;
rc = register_blkdev(0, DCSSBLK_NAME);
if (rc < 0)
goto out_root;
dcssblk_major = rc;
init_rwsem(&dcssblk_devices_sem);
dcssblk_check_params();
return 0;
out_root:
root_device_unregister(dcssblk_root_dev);
out_pdev:
platform_device_unregister(dcssblk_pdev);
out_pdrv:
platform_driver_unregister(&dcssblk_pdrv);
return rc;
}
