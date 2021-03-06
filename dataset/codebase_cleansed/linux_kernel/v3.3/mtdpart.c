static int part_read(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, u_char *buf)
{
struct mtd_part *part = PART(mtd);
struct mtd_ecc_stats stats;
int res;
stats = part->master->ecc_stats;
if (from >= mtd->size)
len = 0;
else if (from + len > mtd->size)
len = mtd->size - from;
res = mtd_read(part->master, from + part->offset, len, retlen, buf);
if (unlikely(res)) {
if (mtd_is_bitflip(res))
mtd->ecc_stats.corrected += part->master->ecc_stats.corrected - stats.corrected;
if (mtd_is_eccerr(res))
mtd->ecc_stats.failed += part->master->ecc_stats.failed - stats.failed;
}
return res;
}
static int part_point(struct mtd_info *mtd, loff_t from, size_t len,
size_t *retlen, void **virt, resource_size_t *phys)
{
struct mtd_part *part = PART(mtd);
if (from >= mtd->size)
len = 0;
else if (from + len > mtd->size)
len = mtd->size - from;
return mtd_point(part->master, from + part->offset, len, retlen,
virt, phys);
}
static void part_unpoint(struct mtd_info *mtd, loff_t from, size_t len)
{
struct mtd_part *part = PART(mtd);
mtd_unpoint(part->master, from + part->offset, len);
}
static unsigned long part_get_unmapped_area(struct mtd_info *mtd,
unsigned long len,
unsigned long offset,
unsigned long flags)
{
struct mtd_part *part = PART(mtd);
offset += part->offset;
return mtd_get_unmapped_area(part->master, len, offset, flags);
}
static int part_read_oob(struct mtd_info *mtd, loff_t from,
struct mtd_oob_ops *ops)
{
struct mtd_part *part = PART(mtd);
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
res = mtd_read_oob(part->master, from + part->offset, ops);
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
struct mtd_part *part = PART(mtd);
return mtd_read_user_prot_reg(part->master, from, len, retlen, buf);
}
static int part_get_user_prot_info(struct mtd_info *mtd,
struct otp_info *buf, size_t len)
{
struct mtd_part *part = PART(mtd);
return mtd_get_user_prot_info(part->master, buf, len);
}
static int part_read_fact_prot_reg(struct mtd_info *mtd, loff_t from,
size_t len, size_t *retlen, u_char *buf)
{
struct mtd_part *part = PART(mtd);
return mtd_read_fact_prot_reg(part->master, from, len, retlen, buf);
}
static int part_get_fact_prot_info(struct mtd_info *mtd, struct otp_info *buf,
size_t len)
{
struct mtd_part *part = PART(mtd);
return mtd_get_fact_prot_info(part->master, buf, len);
}
static int part_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct mtd_part *part = PART(mtd);
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
if (to >= mtd->size)
len = 0;
else if (to + len > mtd->size)
len = mtd->size - to;
return mtd_write(part->master, to + part->offset, len, retlen, buf);
}
static int part_panic_write(struct mtd_info *mtd, loff_t to, size_t len,
size_t *retlen, const u_char *buf)
{
struct mtd_part *part = PART(mtd);
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
if (to >= mtd->size)
len = 0;
else if (to + len > mtd->size)
len = mtd->size - to;
return mtd_panic_write(part->master, to + part->offset, len, retlen,
buf);
}
static int part_write_oob(struct mtd_info *mtd, loff_t to,
struct mtd_oob_ops *ops)
{
struct mtd_part *part = PART(mtd);
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
if (to >= mtd->size)
return -EINVAL;
if (ops->datbuf && to + ops->len > mtd->size)
return -EINVAL;
return mtd_write_oob(part->master, to + part->offset, ops);
}
static int part_write_user_prot_reg(struct mtd_info *mtd, loff_t from,
size_t len, size_t *retlen, u_char *buf)
{
struct mtd_part *part = PART(mtd);
return mtd_write_user_prot_reg(part->master, from, len, retlen, buf);
}
static int part_lock_user_prot_reg(struct mtd_info *mtd, loff_t from,
size_t len)
{
struct mtd_part *part = PART(mtd);
return mtd_lock_user_prot_reg(part->master, from, len);
}
static int part_writev(struct mtd_info *mtd, const struct kvec *vecs,
unsigned long count, loff_t to, size_t *retlen)
{
struct mtd_part *part = PART(mtd);
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
return mtd_writev(part->master, vecs, count, to + part->offset,
retlen);
}
static int part_erase(struct mtd_info *mtd, struct erase_info *instr)
{
struct mtd_part *part = PART(mtd);
int ret;
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
if (instr->addr >= mtd->size)
return -EINVAL;
instr->addr += part->offset;
ret = mtd_erase(part->master, instr);
if (ret) {
if (instr->fail_addr != MTD_FAIL_ADDR_UNKNOWN)
instr->fail_addr -= part->offset;
instr->addr -= part->offset;
}
return ret;
}
void mtd_erase_callback(struct erase_info *instr)
{
if (instr->mtd->erase == part_erase) {
struct mtd_part *part = PART(instr->mtd);
if (instr->fail_addr != MTD_FAIL_ADDR_UNKNOWN)
instr->fail_addr -= part->offset;
instr->addr -= part->offset;
}
if (instr->callback)
instr->callback(instr);
}
static int part_lock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct mtd_part *part = PART(mtd);
if ((len + ofs) > mtd->size)
return -EINVAL;
return mtd_lock(part->master, ofs + part->offset, len);
}
static int part_unlock(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct mtd_part *part = PART(mtd);
if ((len + ofs) > mtd->size)
return -EINVAL;
return mtd_unlock(part->master, ofs + part->offset, len);
}
static int part_is_locked(struct mtd_info *mtd, loff_t ofs, uint64_t len)
{
struct mtd_part *part = PART(mtd);
if ((len + ofs) > mtd->size)
return -EINVAL;
return mtd_is_locked(part->master, ofs + part->offset, len);
}
static void part_sync(struct mtd_info *mtd)
{
struct mtd_part *part = PART(mtd);
mtd_sync(part->master);
}
static int part_suspend(struct mtd_info *mtd)
{
struct mtd_part *part = PART(mtd);
return mtd_suspend(part->master);
}
static void part_resume(struct mtd_info *mtd)
{
struct mtd_part *part = PART(mtd);
mtd_resume(part->master);
}
static int part_block_isbad(struct mtd_info *mtd, loff_t ofs)
{
struct mtd_part *part = PART(mtd);
if (ofs >= mtd->size)
return -EINVAL;
ofs += part->offset;
return mtd_block_isbad(part->master, ofs);
}
static int part_block_markbad(struct mtd_info *mtd, loff_t ofs)
{
struct mtd_part *part = PART(mtd);
int res;
if (!(mtd->flags & MTD_WRITEABLE))
return -EROFS;
if (ofs >= mtd->size)
return -EINVAL;
ofs += part->offset;
res = mtd_block_markbad(part->master, ofs);
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
slave->mtd.backing_dev_info = master->backing_dev_info;
slave->mtd.dev.parent = master->dev.parent;
slave->mtd.read = part_read;
slave->mtd.write = part_write;
if (master->panic_write)
slave->mtd.panic_write = part_panic_write;
if (master->point && master->unpoint) {
slave->mtd.point = part_point;
slave->mtd.unpoint = part_unpoint;
}
if (master->get_unmapped_area)
slave->mtd.get_unmapped_area = part_get_unmapped_area;
if (master->read_oob)
slave->mtd.read_oob = part_read_oob;
if (master->write_oob)
slave->mtd.write_oob = part_write_oob;
if (master->read_user_prot_reg)
slave->mtd.read_user_prot_reg = part_read_user_prot_reg;
if (master->read_fact_prot_reg)
slave->mtd.read_fact_prot_reg = part_read_fact_prot_reg;
if (master->write_user_prot_reg)
slave->mtd.write_user_prot_reg = part_write_user_prot_reg;
if (master->lock_user_prot_reg)
slave->mtd.lock_user_prot_reg = part_lock_user_prot_reg;
if (master->get_user_prot_info)
slave->mtd.get_user_prot_info = part_get_user_prot_info;
if (master->get_fact_prot_info)
slave->mtd.get_fact_prot_info = part_get_fact_prot_info;
if (master->sync)
slave->mtd.sync = part_sync;
if (!partno && !master->dev.class && master->suspend && master->resume) {
slave->mtd.suspend = part_suspend;
slave->mtd.resume = part_resume;
}
if (master->writev)
slave->mtd.writev = part_writev;
if (master->lock)
slave->mtd.lock = part_lock;
if (master->unlock)
slave->mtd.unlock = part_unlock;
if (master->is_locked)
slave->mtd.is_locked = part_is_locked;
if (master->block_isbad)
slave->mtd.block_isbad = part_block_isbad;
if (master->block_markbad)
slave->mtd.block_markbad = part_block_markbad;
slave->mtd.erase = part_erase;
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
if (master->block_isbad) {
uint64_t offs = 0;
while (offs < slave->mtd.size) {
if (mtd_block_isbad(master, offs + slave->offset))
slave->mtd.ecc_stats.badblocks++;
offs += slave->mtd.erasesize;
}
}
out_register:
return slave;
}
int mtd_add_partition(struct mtd_info *master, char *name,
long long offset, long long length)
{
struct mtd_partition part;
struct mtd_part *p, *new;
uint64_t start, end;
int ret = 0;
if (offset == MTDPART_OFS_APPEND ||
offset == MTDPART_OFS_NXTBLK)
return -EINVAL;
if (length == MTDPART_SIZ_FULL)
length = master->size - offset;
if (length <= 0)
return -EINVAL;
part.name = name;
part.size = length;
part.offset = offset;
part.mask_flags = 0;
part.ecclayout = NULL;
new = allocate_partition(master, &part, -1, offset);
if (IS_ERR(new))
return PTR_ERR(new);
start = offset;
end = offset + length;
mutex_lock(&mtd_partitions_mutex);
list_for_each_entry(p, &mtd_partitions, list)
if (p->master == master) {
if ((start >= p->offset) &&
(start < (p->offset + p->mtd.size)))
goto err_inv;
if ((end >= p->offset) &&
(end < (p->offset + p->mtd.size)))
goto err_inv;
}
list_add(&new->list, &mtd_partitions);
mutex_unlock(&mtd_partitions_mutex);
add_mtd_device(&new->mtd);
return ret;
err_inv:
mutex_unlock(&mtd_partitions_mutex);
free_partition(new);
return -EINVAL;
}
int mtd_del_partition(struct mtd_info *master, int partno)
{
struct mtd_part *slave, *next;
int ret = -EINVAL;
mutex_lock(&mtd_partitions_mutex);
list_for_each_entry_safe(slave, next, &mtd_partitions, list)
if ((slave->master == master) &&
(slave->mtd.index == partno)) {
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
if (IS_ERR(slave))
return PTR_ERR(slave);
mutex_lock(&mtd_partitions_mutex);
list_add(&slave->list, &mtd_partitions);
mutex_unlock(&mtd_partitions_mutex);
add_mtd_device(&slave->mtd);
cur_offset = slave->offset + slave->mtd.size;
}
return 0;
}
static struct mtd_part_parser *get_partition_parser(const char *name)
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
int register_mtd_parser(struct mtd_part_parser *p)
{
spin_lock(&part_parser_lock);
list_add(&p->list, &part_parsers);
spin_unlock(&part_parser_lock);
return 0;
}
int deregister_mtd_parser(struct mtd_part_parser *p)
{
spin_lock(&part_parser_lock);
list_del(&p->list);
spin_unlock(&part_parser_lock);
return 0;
}
int parse_mtd_partitions(struct mtd_info *master, const char **types,
struct mtd_partition **pparts,
struct mtd_part_parser_data *data)
{
struct mtd_part_parser *parser;
int ret = 0;
if (!types)
types = default_mtd_part_types;
for ( ; ret <= 0 && *types; types++) {
parser = get_partition_parser(*types);
if (!parser && !request_module("%s", *types))
parser = get_partition_parser(*types);
if (!parser)
continue;
ret = (*parser->parse_fn)(master, pparts, data);
if (ret > 0) {
printk(KERN_NOTICE "%d %s partitions found on MTD device %s\n",
ret, parser->name, master->name);
}
put_partition_parser(parser);
}
return ret;
}
int mtd_is_partition(struct mtd_info *mtd)
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
