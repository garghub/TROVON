struct mtd_info *__mtd_next_device(int i)
{
return idr_get_next(&mtd_idr, &i);
}
static void mtd_release(struct device *dev)
{
struct mtd_info __maybe_unused *mtd = dev_get_drvdata(dev);
dev_t index = MTD_DEVT(mtd->index);
if (index)
device_destroy(&mtd_class, index + 1);
}
static int mtd_cls_suspend(struct device *dev, pm_message_t state)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return mtd ? mtd_suspend(mtd) : 0;
}
static int mtd_cls_resume(struct device *dev)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
if (mtd)
mtd_resume(mtd);
return 0;
}
static ssize_t mtd_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
char *type;
switch (mtd->type) {
case MTD_ABSENT:
type = "absent";
break;
case MTD_RAM:
type = "ram";
break;
case MTD_ROM:
type = "rom";
break;
case MTD_NORFLASH:
type = "nor";
break;
case MTD_NANDFLASH:
type = "nand";
break;
case MTD_DATAFLASH:
type = "dataflash";
break;
case MTD_UBIVOLUME:
type = "ubi";
break;
default:
type = "unknown";
}
return snprintf(buf, PAGE_SIZE, "%s\n", type);
}
static ssize_t mtd_flags_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "0x%lx\n", (unsigned long)mtd->flags);
}
static ssize_t mtd_size_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%llu\n",
(unsigned long long)mtd->size);
}
static ssize_t mtd_erasesize_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%lu\n", (unsigned long)mtd->erasesize);
}
static ssize_t mtd_writesize_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%lu\n", (unsigned long)mtd->writesize);
}
static ssize_t mtd_subpagesize_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
unsigned int subpagesize = mtd->writesize >> mtd->subpage_sft;
return snprintf(buf, PAGE_SIZE, "%u\n", subpagesize);
}
static ssize_t mtd_oobsize_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%lu\n", (unsigned long)mtd->oobsize);
}
static ssize_t mtd_numeraseregions_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%u\n", mtd->numeraseregions);
}
static ssize_t mtd_name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%s\n", mtd->name);
}
static ssize_t mtd_ecc_strength_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%u\n", mtd->ecc_strength);
}
static ssize_t mtd_bitflip_threshold_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%u\n", mtd->bitflip_threshold);
}
static ssize_t mtd_bitflip_threshold_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
unsigned int bitflip_threshold;
int retval;
retval = kstrtouint(buf, 0, &bitflip_threshold);
if (retval)
return retval;
mtd->bitflip_threshold = bitflip_threshold;
return count;
}
int add_mtd_device(struct mtd_info *mtd)
{
struct mtd_notifier *not;
int i, error;
if (!mtd->backing_dev_info) {
switch (mtd->type) {
case MTD_RAM:
mtd->backing_dev_info = &mtd_bdi_rw_mappable;
break;
case MTD_ROM:
mtd->backing_dev_info = &mtd_bdi_ro_mappable;
break;
default:
mtd->backing_dev_info = &mtd_bdi_unmappable;
break;
}
}
BUG_ON(mtd->writesize == 0);
mutex_lock(&mtd_table_mutex);
do {
if (!idr_pre_get(&mtd_idr, GFP_KERNEL))
goto fail_locked;
error = idr_get_new(&mtd_idr, mtd, &i);
} while (error == -EAGAIN);
if (error)
goto fail_locked;
mtd->index = i;
mtd->usecount = 0;
if (mtd->bitflip_threshold == 0)
mtd->bitflip_threshold = mtd->ecc_strength;
if (is_power_of_2(mtd->erasesize))
mtd->erasesize_shift = ffs(mtd->erasesize) - 1;
else
mtd->erasesize_shift = 0;
if (is_power_of_2(mtd->writesize))
mtd->writesize_shift = ffs(mtd->writesize) - 1;
else
mtd->writesize_shift = 0;
mtd->erasesize_mask = (1 << mtd->erasesize_shift) - 1;
mtd->writesize_mask = (1 << mtd->writesize_shift) - 1;
if ((mtd->flags & MTD_WRITEABLE) && (mtd->flags & MTD_POWERUP_LOCK)) {
error = mtd_unlock(mtd, 0, mtd->size);
if (error && error != -EOPNOTSUPP)
printk(KERN_WARNING
"%s: unlock failed, writes may not work\n",
mtd->name);
}
mtd->dev.type = &mtd_devtype;
mtd->dev.class = &mtd_class;
mtd->dev.devt = MTD_DEVT(i);
dev_set_name(&mtd->dev, "mtd%d", i);
dev_set_drvdata(&mtd->dev, mtd);
if (device_register(&mtd->dev) != 0)
goto fail_added;
if (MTD_DEVT(i))
device_create(&mtd_class, mtd->dev.parent,
MTD_DEVT(i) + 1,
NULL, "mtd%dro", i);
pr_debug("mtd: Giving out device %d to %s\n", i, mtd->name);
list_for_each_entry(not, &mtd_notifiers, list)
not->add(mtd);
mutex_unlock(&mtd_table_mutex);
__module_get(THIS_MODULE);
return 0;
fail_added:
idr_remove(&mtd_idr, i);
fail_locked:
mutex_unlock(&mtd_table_mutex);
return 1;
}
int del_mtd_device(struct mtd_info *mtd)
{
int ret;
struct mtd_notifier *not;
mutex_lock(&mtd_table_mutex);
if (idr_find(&mtd_idr, mtd->index) != mtd) {
ret = -ENODEV;
goto out_error;
}
list_for_each_entry(not, &mtd_notifiers, list)
not->remove(mtd);
if (mtd->usecount) {
printk(KERN_NOTICE "Removing MTD device #%d (%s) with use count %d\n",
mtd->index, mtd->name, mtd->usecount);
ret = -EBUSY;
} else {
device_unregister(&mtd->dev);
idr_remove(&mtd_idr, mtd->index);
module_put(THIS_MODULE);
ret = 0;
}
out_error:
mutex_unlock(&mtd_table_mutex);
return ret;
}
int mtd_device_parse_register(struct mtd_info *mtd, const char **types,
struct mtd_part_parser_data *parser_data,
const struct mtd_partition *parts,
int nr_parts)
{
int err;
struct mtd_partition *real_parts;
err = parse_mtd_partitions(mtd, types, &real_parts, parser_data);
if (err <= 0 && nr_parts && parts) {
real_parts = kmemdup(parts, sizeof(*parts) * nr_parts,
GFP_KERNEL);
if (!real_parts)
err = -ENOMEM;
else
err = nr_parts;
}
if (err > 0) {
err = add_mtd_partitions(mtd, real_parts, err);
kfree(real_parts);
} else if (err == 0) {
err = add_mtd_device(mtd);
if (err == 1)
err = -ENODEV;
}
return err;
}
int mtd_device_unregister(struct mtd_info *master)
{
int err;
err = del_mtd_partitions(master);
if (err)
return err;
if (!device_is_registered(&master->dev))
return 0;
return del_mtd_device(master);
}
void register_mtd_user (struct mtd_notifier *new)
{
struct mtd_info *mtd;
mutex_lock(&mtd_table_mutex);
list_add(&new->list, &mtd_notifiers);
__module_get(THIS_MODULE);
mtd_for_each_device(mtd)
new->add(mtd);
mutex_unlock(&mtd_table_mutex);
}
int unregister_mtd_user (struct mtd_notifier *old)
{
struct mtd_info *mtd;
mutex_lock(&mtd_table_mutex);
module_put(THIS_MODULE);
mtd_for_each_device(mtd)
old->remove(mtd);
list_del(&old->list);
mutex_unlock(&mtd_table_mutex);
return 0;
}
struct mtd_info *get_mtd_device(struct mtd_info *mtd, int num)
{
struct mtd_info *ret = NULL, *other;
int err = -ENODEV;
mutex_lock(&mtd_table_mutex);
if (num == -1) {
mtd_for_each_device(other) {
if (other == mtd) {
ret = mtd;
break;
}
}
} else if (num >= 0) {
ret = idr_find(&mtd_idr, num);
if (mtd && mtd != ret)
ret = NULL;
}
if (!ret) {
ret = ERR_PTR(err);
goto out;
}
err = __get_mtd_device(ret);
if (err)
ret = ERR_PTR(err);
out:
mutex_unlock(&mtd_table_mutex);
return ret;
}
int __get_mtd_device(struct mtd_info *mtd)
{
int err;
if (!try_module_get(mtd->owner))
return -ENODEV;
if (mtd->_get_device) {
err = mtd->_get_device(mtd);
if (err) {
module_put(mtd->owner);
return err;
}
}
mtd->usecount++;
return 0;
}
struct mtd_info *get_mtd_device_nm(const char *name)
{
int err = -ENODEV;
struct mtd_info *mtd = NULL, *other;
mutex_lock(&mtd_table_mutex);
mtd_for_each_device(other) {
if (!strcmp(name, other->name)) {
mtd = other;
break;
}
}
if (!mtd)
goto out_unlock;
err = __get_mtd_device(mtd);
if (err)
goto out_unlock;
mutex_unlock(&mtd_table_mutex);
return mtd;
out_unlock:
mutex_unlock(&mtd_table_mutex);
return ERR_PTR(err);
}
void put_mtd_device(struct mtd_info *mtd)
{
mutex_lock(&mtd_table_mutex);
__put_mtd_device(mtd);
mutex_unlock(&mtd_table_mutex);
}
void __put_mtd_device(struct mtd_info *mtd)
{
--mtd->usecount;
BUG_ON(mtd->usecount < 0);
if (mtd->_put_device)
mtd->_put_device(mtd);
module_put(mtd->owner);
}
int mtd_erase(struct mtd_info *mtd, struct erase_info *instr)
{
if (instr->addr > mtd->size || instr->len > mtd->size - instr->addr)
return -EINVAL;
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
instr->fail_addr = MTD_FAIL_ADDR_UNKNOWN;
if (!instr->len) {
instr->state = MTD_ERASE_DONE;
mtd_erase_callback(instr);
return 0;
}
return mtd->_erase(mtd, instr);
}
int mtd_point(struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen,
void **virt, resource_size_t *phys)
{
*retlen = 0;
*virt = NULL;
if (phys)
*phys = 0;
if (!mtd->_point)
return -EOPNOTSUPP;
if (from < 0 || from > mtd->size || len > mtd->size - from)
return -EINVAL;
if (!len)
return 0;
return mtd->_point(mtd, from, len, retlen, virt, phys);
}
int mtd_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
if (!mtd->_point)
return -EOPNOTSUPP;
if (from < 0 || from > mtd->size || len > mtd->size - from)
return -EINVAL;
if (!len)
return 0;
return mtd->_unpoint(mtd, from, len);
}
unsigned long mtd_get_unmapped_area(struct mtd_info *mtd, unsigned long len,
unsigned long offset, unsigned long flags)
{
if (!mtd->_get_unmapped_area)
return -EOPNOTSUPP;
if (offset > mtd->size || len > mtd->size - offset)
return -EINVAL;
return mtd->_get_unmapped_area(mtd, len, offset, flags);
}
int mtd_read(struct mtd_info *mtd, loff_t from, size_t len, size_t *retlen,
u_char *buf)
{
int ret_code;
*retlen = 0;
if (from < 0 || from > mtd->size || len > mtd->size - from)
return -EINVAL;
if (!len)
return 0;
ret_code = mtd->_read(mtd, from, len, retlen, buf);
if (unlikely(ret_code < 0))
return ret_code;
if (mtd->ecc_strength == 0)
return 0;
return ret_code >= mtd->bitflip_threshold ? -EUCLEAN : 0;
}
int mtd_write(struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen,
const u_char *buf)
{
*retlen = 0;
if (to < 0 || to > mtd->size || len > mtd->size - to)
return -EINVAL;
if (!mtd->_write || !(mtd->flags & MTD_WRITEABLE))
return -EROFS;
if (!len)
return 0;
return mtd->_write(mtd, to, len, retlen, buf);
}
int mtd_panic_write(struct mtd_info *mtd, loff_t to, size_t len, size_t *retlen,
const u_char *buf)
{
*retlen = 0;
if (!mtd->_panic_write)
return -EOPNOTSUPP;
if (to < 0 || to > mtd->size || len > mtd->size - to)
return -EINVAL;
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
if (!len)
return 0;
return mtd->_panic_write(mtd, to, len, retlen, buf);
}
int mtd_read_oob(struct mtd_info *mtd, loff_t from, struct mtd_oob_ops *ops)
{
int ret_code;
ops->retlen = ops->oobretlen = 0;
if (!mtd->_read_oob)
return -EOPNOTSUPP;
ret_code = mtd->_read_oob(mtd, from, ops);
if (unlikely(ret_code < 0))
return ret_code;
if (mtd->ecc_strength == 0)
return 0;
return ret_code >= mtd->bitflip_threshold ? -EUCLEAN : 0;
}
int mtd_get_fact_prot_info(struct mtd_info *mtd, struct otp_info *buf,
size_t len)
{
if (!mtd->_get_fact_prot_info)
return -EOPNOTSUPP;
if (!len)
return 0;
return mtd->_get_fact_prot_info(mtd, buf, len);
}
int mtd_read_fact_prot_reg(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
*retlen = 0;
if (!mtd->_read_fact_prot_reg)
return -EOPNOTSUPP;
if (!len)
return 0;
return mtd->_read_fact_prot_reg(mtd, from, len, retlen, buf);
}
int mtd_get_user_prot_info(struct mtd_info *mtd, struct otp_info *buf,
size_t len)
{
if (!mtd->_get_user_prot_info)
return -EOPNOTSUPP;
if (!len)
return 0;
return mtd->_get_user_prot_info(mtd, buf, len);
}
int mtd_read_user_prot_reg(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
*retlen = 0;
if (!mtd->_read_user_prot_reg)
return -EOPNOTSUPP;
if (!len)
return 0;
return mtd->_read_user_prot_reg(mtd, from, len, retlen, buf);
}
int mtd_write_user_prot_reg(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, u_char *buf)
{
*retlen = 0;
if (!mtd->_write_user_prot_reg)
return -EOPNOTSUPP;
if (!len)
return 0;
return mtd->_write_user_prot_reg(mtd, to, len, retlen, buf);
}
int mtd_lock_user_prot_reg(struct mtd_info *mtd, loff_t from, size_t len)
{
if (!mtd->_lock_user_prot_reg)
return -EOPNOTSUPP;
if (!len)
return 0;
return mtd->_lock_user_prot_reg(mtd, from, len);
}
int mtd_lock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
if (!mtd->_lock)
return -EOPNOTSUPP;
if (ofs < 0 || ofs > mtd->size || len > mtd->size - ofs)
return -EINVAL;
if (!len)
return 0;
return mtd->_lock(mtd, ofs, len);
}
int mtd_unlock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
if (!mtd->_unlock)
return -EOPNOTSUPP;
if (ofs < 0 || ofs > mtd->size || len > mtd->size - ofs)
return -EINVAL;
if (!len)
return 0;
return mtd->_unlock(mtd, ofs, len);
}
int mtd_is_locked(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
if (!mtd->_is_locked)
return -EOPNOTSUPP;
if (ofs < 0 || ofs > mtd->size || len > mtd->size - ofs)
return -EINVAL;
if (!len)
return 0;
return mtd->_is_locked(mtd, ofs, len);
}
int mtd_block_isbad(struct mtd_info *mtd, loff_t ofs)
{
if (!mtd->_block_isbad)
return 0;
if (ofs < 0 || ofs > mtd->size)
return -EINVAL;
return mtd->_block_isbad(mtd, ofs);
}
int mtd_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
if (!mtd->_block_markbad)
return -EOPNOTSUPP;
if (ofs < 0 || ofs > mtd->size)
return -EINVAL;
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
return mtd->_block_markbad(mtd, ofs);
}
static int default_mtd_writev(struct mtd_info *mtd, const struct kvec *vecs,
unsigned long count, loff_t to, size_t *retlen)
{
unsigned long i;
size_t totlen = 0, thislen;
int ret = 0;
for (i = 0; i < count; i++) {
if (!vecs[i].iov_len)
continue;
ret = mtd_write(mtd, to, vecs[i].iov_len, &thislen,
vecs[i].iov_base);
totlen += thislen;
if (ret || thislen != vecs[i].iov_len)
break;
to += vecs[i].iov_len;
}
*retlen = totlen;
return ret;
}
int mtd_writev(struct mtd_info *mtd, const struct kvec *vecs,
unsigned long count, loff_t to, size_t *retlen)
{
*retlen = 0;
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
if (!mtd->_writev)
return default_mtd_writev(mtd, vecs, count, to, retlen);
return mtd->_writev(mtd, vecs, count, to, retlen);
}
void *mtd_kmalloc_up_to(const struct mtd_info *mtd, size_t *size)
{
gfp_t flags = __GFP_NOWARN | __GFP_WAIT |
__GFP_NORETRY | __GFP_NO_KSWAPD;
size_t min_alloc = max_t(size_t, mtd->writesize, PAGE_SIZE);
void *kbuf;
*size = min_t(size_t, *size, KMALLOC_MAX_SIZE);
while (*size > min_alloc) {
kbuf = kmalloc(*size, flags);
if (kbuf)
return kbuf;
*size >>= 1;
*size = ALIGN(*size, mtd->writesize);
}
return kmalloc(*size, GFP_KERNEL);
}
static int mtd_proc_show(struct seq_file *m, void *v)
{
struct mtd_info *mtd;
seq_puts(m, "dev: size erasesize name\n");
mutex_lock(&mtd_table_mutex);
mtd_for_each_device(mtd) {
seq_printf(m, "mtd%d: %8.8llx %8.8x \"%s\"\n",
mtd->index, (unsigned long long)mtd->size,
mtd->erasesize, mtd->name);
}
mutex_unlock(&mtd_table_mutex);
return 0;
}
static int mtd_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, mtd_proc_show, NULL);
}
static int __init mtd_bdi_init(struct backing_dev_info *bdi, const char *name)
{
int ret;
ret = bdi_init(bdi);
if (!ret)
ret = bdi_register(bdi, NULL, name);
if (ret)
bdi_destroy(bdi);
return ret;
}
static int __init init_mtd(void)
{
int ret;
ret = class_register(&mtd_class);
if (ret)
goto err_reg;
ret = mtd_bdi_init(&mtd_bdi_unmappable, "mtd-unmap");
if (ret)
goto err_bdi1;
ret = mtd_bdi_init(&mtd_bdi_ro_mappable, "mtd-romap");
if (ret)
goto err_bdi2;
ret = mtd_bdi_init(&mtd_bdi_rw_mappable, "mtd-rwmap");
if (ret)
goto err_bdi3;
#ifdef CONFIG_PROC_FS
proc_mtd = proc_create("mtd", 0, NULL, &mtd_proc_ops);
#endif
return 0;
err_bdi3:
bdi_destroy(&mtd_bdi_ro_mappable);
err_bdi2:
bdi_destroy(&mtd_bdi_unmappable);
err_bdi1:
class_unregister(&mtd_class);
err_reg:
pr_err("Error registering mtd class or bdi: %d\n", ret);
return ret;
}
static void __exit cleanup_mtd(void)
{
#ifdef CONFIG_PROC_FS
if (proc_mtd)
remove_proc_entry( "mtd", NULL);
#endif
class_unregister(&mtd_class);
bdi_destroy(&mtd_bdi_unmappable);
bdi_destroy(&mtd_bdi_ro_mappable);
bdi_destroy(&mtd_bdi_rw_mappable);
}
