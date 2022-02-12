static inline struct mtd_part *mtd_to_part(const struct mtd_info *mtd)
{
return container_of(mtd, struct mtd_part, mtd);
}
static int part_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
struct mtd_part *part = mtd_to_part(mtd);
struct mtd_ecc_stats stats;
int res;
stats = part->master->ecc_stats;
res = part->master->_read(part->master, from + part->offset, len,
retlen, buf);
if (unlikely(mtd_is_eccerr(res)))
mtd->ecc_stats.failed +=
part->master->ecc_stats.failed - stats.failed;
else
mtd->ecc_stats.corrected +=
part->master->ecc_stats.corrected - stats.corrected;
return res;
}
static int part_point(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, void **virt, resource_size_t *phys)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_point(part->master, from + part->offset, len,
retlen, virt, phys);
}
static int part_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_unpoint(part->master, from + part->offset, len);
}
static unsigned long part_get_unmapped_area(struct mtd_info *mtd,
unsigned long len,
unsigned long offset,
unsigned long flags)
{
struct mtd_part *part = mtd_to_part(mtd);
offset += part->offset;
return part->master->_get_unmapped_area(part->master, len, offset,
flags);
}
static int part_read_oob(struct mtd_info *mtd, loff_t from,
struct mtd_oob_ops *ops)
{
struct mtd_part *part = mtd_to_part(mtd);
int res;
if (from >= mtd->size)
return -EINVAL;
if (ops->datbuf && from + ops->len > mtd->size)
return -EINVAL;
if (ops->oobbuf) {
size_t len, pages;
if (ops->mode == MTD_OPS_AUTO_OOB)
len = mtd->oobavail;
else
len = mtd->oobsize;
pages = mtd_div_by_ws(mtd->size, mtd);
pages -= mtd_div_by_ws(from, mtd);
if (ops->ooboffs + ops->ooblen > pages * len)
return -EINVAL;
}
res = part->master->_read_oob(part->master, from + part->offset, ops);
if (unlikely(res)) {
if (mtd_is_bitflip(res))
mtd->ecc_stats.corrected++;
if (mtd_is_eccerr(res))
mtd->ecc_stats.failed++;
}
return res;
}
static int part_read_user_prot_reg(struct mtd_info *mtd, loff_t from,
size_t len, size_t *retlen, u_char *buf)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_read_user_prot_reg(part->master, from, len,
retlen, buf);
}
static int part_get_user_prot_info(struct mtd_info *mtd, size_t len,
size_t *retlen, struct otp_info *buf)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_get_user_prot_info(part->master, len, retlen,
buf);
}
static int part_read_fact_prot_reg(struct mtd_info *mtd, loff_t from,
size_t len, size_t *retlen, u_char *buf)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_read_fact_prot_reg(part->master, from, len,
retlen, buf);
}
static int part_get_fact_prot_info(struct mtd_info *mtd, size_t len,
size_t *retlen, struct otp_info *buf)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_get_fact_prot_info(part->master, len, retlen,
buf);
}
static int part_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_write(part->master, to + part->offset, len,
retlen, buf);
}
static int part_panic_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_panic_write(part->master, to + part->offset, len,
retlen, buf);
}
static int part_write_oob(struct mtd_info *mtd, loff_t to,
struct mtd_oob_ops *ops)
{
struct mtd_part *part = mtd_to_part(mtd);
if (to >= mtd->size)
return -EINVAL;
if (ops->datbuf && to + ops->len > mtd->size)
return -EINVAL;
return part->master->_write_oob(part->master, to + part->offset, ops);
}
static int part_write_user_prot_reg(struct mtd_info *mtd, loff_t from,
size_t len, size_t *retlen, u_char *buf)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_write_user_prot_reg(part->master, from, len,
retlen, buf);
}
static int part_lock_user_prot_reg(struct mtd_info *mtd, loff_t from,
size_t len)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_lock_user_prot_reg(part->master, from, len);
}
static int part_writev(struct mtd_info *mtd, const struct kvec *vecs,
unsigned long count, loff_t to, size_t *retlen)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_writev(part->master, vecs, count,
to + part->offset, retlen);
}
static int part_erase(struct mtd_info *mtd, struct erase_info *instr)
{
struct mtd_part *part = mtd_to_part(mtd);
int ret;
instr->addr += part->offset;
ret = part->master->_erase(part->master, instr);
if (ret) {
if (instr->fail_addr != MTD_FAIL_ADDR_UNKNOWN)
instr->fail_addr -= part->offset;
instr->addr -= part->offset;
}
return ret;
}
void mtd_erase_callback(struct erase_info *instr)
{
if (instr->mtd->_erase == part_erase) {
struct mtd_part *part = mtd_to_part(instr->mtd);
if (instr->fail_addr != MTD_FAIL_ADDR_UNKNOWN)
instr->fail_addr -= part->offset;
instr->addr -= part->offset;
}
if (instr->callback)
instr->callback(instr);
}
static int part_lock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_lock(part->master, ofs + part->offset, len);
}
static int part_unlock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_unlock(part->master, ofs + part->offset, len);
}
static int part_is_locked(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_is_locked(part->master, ofs + part->offset, len);
}
static void part_sync(struct mtd_info *mtd)
{
struct mtd_part *part = mtd_to_part(mtd);
part->master->_sync(part->master);
}
static int part_suspend(struct mtd_info *mtd)
{
struct mtd_part *part = mtd_to_part(mtd);
return part->master->_suspend(part->master);
}
static void part_resume(struct mtd_info *mtd)
{
struct mtd_part *part = mtd_to_part(mtd);
part->master->_resume(part->master);
}
static int part_block_isreserved(struct mtd_info *mtd, loff_t ofs)
{
struct mtd_part *part = mtd_to_part(mtd);
ofs += part->offset;
return part->master->_block_isreserved(part->master, ofs);
}
static int part_block_isbad(struct mtd_info *mtd, loff_t ofs)
{
struct mtd_part *part = mtd_to_part(mtd);
ofs += part->offset;
return part->master->_block_isbad(part->master, ofs);
}
static int part_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
struct mtd_part *part = mtd_to_part(mtd);
int res;
ofs += part->offset;
res = part->master->_block_markbad(part->master, ofs);
if (!res)
mtd->ecc_stats.badblocks++;
return res;
}
static inline void free_partition(struct mtd_part *p)
{
kfree(p->mtd.name);
kfree(p);
}
int del_mtd_partitions(struct mtd_info *master)
{
struct mtd_part *slave, *next;
int ret, err = 0;
mutex_lock(&mtd_partitions_mutex);
list_for_each_entry_safe(slave, next, &mtd_partitions, list)
if (slave->master == master) {
ret = del_mtd_device(&slave->mtd);
if (ret < 0) {
err = ret;
continue;
}
list_del(&slave->list);
free_partition(slave);
}
mutex_unlock(&mtd_partitions_mutex);
return err;
}
static struct mtd_part *allocate_partition(struct mtd_info *master,
const struct mtd_partition *part, int partno,
uint64_t cur_offset)
{
struct mtd_part *slave;
char *name;
slave = kzalloc(sizeof(*slave), GFP_KERNEL);
name = kstrdup(part->name, GFP_KERNEL);
if (!name || !slave) {
printk(KERN_ERR"memory allocation error while creating partitions for \"%s\"\n",
master->name);
kfree(name);
kfree(slave);
return ERR_PTR(-ENOMEM);
}
slave->mtd.type = master->type;
slave->mtd.flags = master->flags & ~part->mask_flags;
slave->mtd.size = part->size;
slave->mtd.writesize = master->writesize;
slave->mtd.writebufsize = master->writebufsize;
slave->mtd.oobsize = master->oobsize;
slave->mtd.oobavail = master->oobavail;
slave->mtd.subpage_sft = master->subpage_sft;
slave->mtd.name = name;
slave->mtd.owner = master->owner;
slave->mtd.dev.parent = IS_ENABLED(CONFIG_MTD_PARTITIONED_MASTER) ?
&master->dev :
master->dev.parent;
slave->mtd._read = part_read;
slave->mtd._write = part_write;
if (master->_panic_write)
slave->mtd._panic_write = part_panic_write;
if (master->_point && master->_unpoint) {
slave->mtd._point = part_point;
slave->mtd._unpoint = part_unpoint;
}
if (master->_get_unmapped_area)
slave->mtd._get_unmapped_area = part_get_unmapped_area;
if (master->_read_oob)
slave->mtd._read_oob = part_read_oob;
if (master->_write_oob)
slave->mtd._write_oob = part_write_oob;
if (master->_read_user_prot_reg)
slave->mtd._read_user_prot_reg = part_read_user_prot_reg;
if (master->_read_fact_prot_reg)
slave->mtd._read_fact_prot_reg = part_read_fact_prot_reg;
if (master->_write_user_prot_reg)
slave->mtd._write_user_prot_reg = part_write_user_prot_reg;
if (master->_lock_user_prot_reg)
slave->mtd._lock_user_prot_reg = part_lock_user_prot_reg;
if (master->_get_user_prot_info)
slave->mtd._get_user_prot_info = part_get_user_prot_info;
if (master->_get_fact_prot_info)
slave->mtd._get_fact_prot_info = part_get_fact_prot_info;
if (master->_sync)
slave->mtd._sync = part_sync;
if (!partno && !master->dev.class && master->_suspend &&
master->_resume) {
slave->mtd._suspend = part_suspend;
slave->mtd._resume = part_resume;
}
if (master->_writev)
slave->mtd._writev = part_writev;
if (master->_lock)
slave->mtd._lock = part_lock;
if (master->_unlock)
slave->mtd._unlock = part_unlock;
if (master->_is_locked)
slave->mtd._is_locked = part_is_locked;
if (master->_block_isreserved)
slave->mtd._block_isreserved = part_block_isreserved;
if (master->_block_isbad)
slave->mtd._block_isbad = part_block_isbad;
if (master->_block_markbad)
slave->mtd._block_markbad = part_block_markbad;
slave->mtd._erase = part_erase;
slave->master = master;
slave->offset = part->offset;
if (slave->offset == MTDPART_OFS_APPEND)
slave->offset = cur_offset;
if (slave->offset == MTDPART_OFS_NXTBLK) {
slave->offset = cur_offset;
if (mtd_mod_by_eb(cur_offset, master) != 0) {
slave->offset = (mtd_div_by_eb(cur_offset, master) + 1) * master->erasesize;
printk(KERN_NOTICE "Moving partition %d: "
"0x%012llx -> 0x%012llx\n", partno,
(unsigned long long)cur_offset, (unsigned long long)slave->offset);
}
}
if (slave->offset == MTDPART_OFS_RETAIN) {
slave->offset = cur_offset;
if (master->size - slave->offset >= slave->mtd.size) {
slave->mtd.size = master->size - slave->offset
- slave->mtd.size;
} else {
printk(KERN_ERR "mtd partition \"%s\" doesn't have enough space: %#llx < %#llx, disabled\n",
part->name, master->size - slave->offset,
slave->mtd.size);
goto out_register;
}
}
if (slave->mtd.size == MTDPART_SIZ_FULL)
slave->mtd.size = master->size - slave->offset;
printk(KERN_NOTICE "0x%012llx-0x%012llx : \"%s\"\n", (unsigned long long)slave->offset,
(unsigned long long)(slave->offset + slave->mtd.size), slave->mtd.name);
if (slave->offset >= master->size) {
slave->offset = 0;
slave->mtd.size = 0;
printk(KERN_ERR"mtd: partition \"%s\" is out of reach -- disabled\n",
part->name);
goto out_register;
}
if (slave->offset + slave->mtd.size > master->size) {
slave->mtd.size = master->size - slave->offset;
printk(KERN_WARNING"mtd: partition \"%s\" extends beyond the end of device \"%s\" -- size truncated to %#llx\n",
part->name, master->name, (unsigned long long)slave->mtd.size);
}
if (master->numeraseregions > 1) {
int i, max = master->numeraseregions;
u64 end = slave->offset + slave->mtd.size;
struct mtd_erase_region_info *regions = master->eraseregions;
for (i = 0; i < max && regions[i].offset <= slave->offset; i++)
;
if (i > 0)
i--;
for (; i < max && regions[i].offset < end; i++) {
if (slave->mtd.erasesize < regions[i].erasesize) {
slave->mtd.erasesize = regions[i].erasesize;
}
}
BUG_ON(slave->mtd.erasesize == 0);
} else {
slave->mtd.erasesize = master->erasesize;
}
if ((slave->mtd.flags & MTD_WRITEABLE) &&
mtd_mod_by_eb(slave->offset, &slave->mtd)) {
slave->mtd.flags &= ~MTD_WRITEABLE;
printk(KERN_WARNING"mtd: partition \"%s\" doesn't start on an erase block boundary -- force read-only\n",
part->name);
}
if ((slave->mtd.flags & MTD_WRITEABLE) &&
mtd_mod_by_eb(slave->mtd.size, &slave->mtd)) {
slave->mtd.flags &= ~MTD_WRITEABLE;
printk(KERN_WARNING"mtd: partition \"%s\" doesn't end on an erase block -- force read-only\n",
part->name);
}
slave->mtd.ecclayout = master->ecclayout;
slave->mtd.ecc_step_size = master->ecc_step_size;
slave->mtd.ecc_strength = master->ecc_strength;
slave->mtd.bitflip_threshold = master->bitflip_threshold;
if (master->_block_isbad) {
uint64_t offs = 0;
while (offs < slave->mtd.size) {
if (mtd_block_isreserved(master, offs + slave->offset))
slave->mtd.ecc_stats.bbtblocks++;
else if (mtd_block_isbad(master, offs + slave->offset))
slave->mtd.ecc_stats.badblocks++;
offs += slave->mtd.erasesize;
}
}
out_register:
return slave;
}
static ssize_t mtd_partition_offset_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = dev_get_drvdata(dev);
struct mtd_part *part = mtd_to_part(mtd);
return snprintf(buf, PAGE_SIZE, "%lld\n", part->offset);
}
static int mtd_add_partition_attrs(struct mtd_part *new)
{
int ret = sysfs_create_files(&new->mtd.dev.kobj, mtd_partition_attrs);
if (ret)
printk(KERN_WARNING
"mtd: failed to create partition attrs, err=%d\n", ret);
return ret;
}
int mtd_add_partition(struct mtd_info *master, const char *name,
long long offset, long long length)
{
struct mtd_partition part;
struct mtd_part *new;
int ret = 0;
if (offset == MTDPART_OFS_APPEND ||
offset == MTDPART_OFS_NXTBLK)
return -EINVAL;
if (length == MTDPART_SIZ_FULL)
length = master->size - offset;
if (length <= 0)
return -EINVAL;
memset(&part, 0, sizeof(part));
part.name = name;
part.size = length;
part.offset = offset;
new = allocate_partition(master, &part, -1, offset);
if (IS_ERR(new))
return PTR_ERR(new);
mutex_lock(&mtd_partitions_mutex);
list_add(&new->list, &mtd_partitions);
mutex_unlock(&mtd_partitions_mutex);
add_mtd_device(&new->mtd);
mtd_add_partition_attrs(new);
return ret;
}
int mtd_del_partition(struct mtd_info *master, int partno)
{
struct mtd_part *slave, *next;
int ret = -EINVAL;
mutex_lock(&mtd_partitions_mutex);
list_for_each_entry_safe(slave, next, &mtd_partitions, list)
if ((slave->master == master) &&
(slave->mtd.index == partno)) {
sysfs_remove_files(&slave->mtd.dev.kobj,
mtd_partition_attrs);
ret = del_mtd_device(&slave->mtd);
if (ret < 0)
break;
list_del(&slave->list);
free_partition(slave);
break;
}
mutex_unlock(&mtd_partitions_mutex);
return ret;
}
int add_mtd_partitions(struct mtd_info *master,
const struct mtd_partition *parts,
int nbparts)
{
struct mtd_part *slave;
uint64_t cur_offset = 0;
int i;
printk(KERN_NOTICE "Creating %d MTD partitions on \"%s\":\n", nbparts, master->name);
for (i = 0; i < nbparts; i++) {
slave = allocate_partition(master, parts + i, i, cur_offset);
if (IS_ERR(slave)) {
del_mtd_partitions(master);
return PTR_ERR(slave);
}
mutex_lock(&mtd_partitions_mutex);
list_add(&slave->list, &mtd_partitions);
mutex_unlock(&mtd_partitions_mutex);
add_mtd_device(&slave->mtd);
mtd_add_partition_attrs(slave);
cur_offset = slave->offset + slave->mtd.size;
}
return 0;
}
static struct mtd_part_parser *mtd_part_parser_get(const char *name)
{
struct mtd_part_parser *p, *ret = NULL;
spin_lock(&part_parser_lock);
list_for_each_entry(p, &part_parsers, list)
if (!strcmp(p->name, name) && try_module_get(p->owner)) {
ret = p;
break;
}
spin_unlock(&part_parser_lock);
return ret;
}
static inline void mtd_part_parser_put(const struct mtd_part_parser *p)
{
module_put(p->owner);
}
static void mtd_part_parser_cleanup_default(const struct mtd_partition *pparts,
int nr_parts)
{
kfree(pparts);
}
int __register_mtd_parser(struct mtd_part_parser *p, struct module *owner)
{
p->owner = owner;
if (!p->cleanup)
p->cleanup = &mtd_part_parser_cleanup_default;
spin_lock(&part_parser_lock);
list_add(&p->list, &part_parsers);
spin_unlock(&part_parser_lock);
return 0;
}
void deregister_mtd_parser(struct mtd_part_parser *p)
{
spin_lock(&part_parser_lock);
list_del(&p->list);
spin_unlock(&part_parser_lock);
}
int parse_mtd_partitions(struct mtd_info *master, const char *const *types,
struct mtd_partitions *pparts,
struct mtd_part_parser_data *data)
{
struct mtd_part_parser *parser;
int ret, err = 0;
if (!types)
types = default_mtd_part_types;
for ( ; *types; types++) {
pr_debug("%s: parsing partitions %s\n", master->name, *types);
parser = mtd_part_parser_get(*types);
if (!parser && !request_module("%s", *types))
parser = mtd_part_parser_get(*types);
pr_debug("%s: got parser %s\n", master->name,
parser ? parser->name : NULL);
if (!parser)
continue;
ret = (*parser->parse_fn)(master, &pparts->parts, data);
pr_debug("%s: parser %s: %i\n",
master->name, parser->name, ret);
if (ret > 0) {
printk(KERN_NOTICE "%d %s partitions found on MTD device %s\n",
ret, parser->name, master->name);
pparts->nr_parts = ret;
pparts->parser = parser;
return 0;
}
mtd_part_parser_put(parser);
if (ret < 0 && !err)
err = ret;
}
return err;
}
void mtd_part_parser_cleanup(struct mtd_partitions *parts)
{
const struct mtd_part_parser *parser;
if (!parts)
return;
parser = parts->parser;
if (parser) {
if (parser->cleanup)
parser->cleanup(parts->parts, parts->nr_parts);
mtd_part_parser_put(parser);
}
}
int mtd_is_partition(const struct mtd_info *mtd)
{
struct mtd_part *part;
int ispart = 0;
mutex_lock(&mtd_partitions_mutex);
list_for_each_entry(part, &mtd_partitions, list)
if (&part->mtd == mtd) {
ispart = 1;
break;
}
mutex_unlock(&mtd_partitions_mutex);
return ispart;
}
uint64_t mtd_get_device_size(const struct mtd_info *mtd)
{
if (!mtd_is_partition(mtd))
return mtd->size;
return mtd_to_part(mtd)->master->size;
}
