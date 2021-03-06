static int logfs_mtd_read(struct super_block *sb, loff_t ofs, size_t len,
void *buf)
{
struct mtd_info *mtd = logfs_super(sb)->s_mtd;
size_t retlen;
int ret;
ret = mtd_read(mtd, ofs, len, &retlen, buf);
BUG_ON(ret == -EINVAL);
if (ret)
return ret;
if (retlen != len)
return -EIO;
return 0;
}
static int loffs_mtd_write(struct super_block *sb, loff_t ofs, size_t len,
void *buf)
{
struct logfs_super *super = logfs_super(sb);
struct mtd_info *mtd = super->s_mtd;
size_t retlen;
loff_t page_start, page_end;
int ret;
if (super->s_flags & LOGFS_SB_FLAG_RO)
return -EROFS;
BUG_ON((ofs >= mtd->size) || (len > mtd->size - ofs));
BUG_ON(ofs != (ofs >> super->s_writeshift) << super->s_writeshift);
BUG_ON(len > PAGE_SIZE);
page_start = ofs & PAGE_MASK;
page_end = PAGE_ALIGN(ofs + len) - 1;
ret = mtd_write(mtd, ofs, len, &retlen, buf);
if (ret || (retlen != len))
return -EIO;
return 0;
}
static void logfs_erase_callback(struct erase_info *ei)
{
complete((struct completion *)ei->priv);
}
static int logfs_mtd_erase_mapping(struct super_block *sb, loff_t ofs,
size_t len)
{
struct logfs_super *super = logfs_super(sb);
struct address_space *mapping = super->s_mapping_inode->i_mapping;
struct page *page;
pgoff_t index = ofs >> PAGE_SHIFT;
for (index = ofs >> PAGE_SHIFT; index < (ofs + len) >> PAGE_SHIFT; index++) {
page = find_get_page(mapping, index);
if (!page)
continue;
memset(page_address(page), 0xFF, PAGE_SIZE);
put_page(page);
}
return 0;
}
static int logfs_mtd_erase(struct super_block *sb, loff_t ofs, size_t len,
int ensure_write)
{
struct mtd_info *mtd = logfs_super(sb)->s_mtd;
struct erase_info ei;
DECLARE_COMPLETION_ONSTACK(complete);
int ret;
BUG_ON(len % mtd->erasesize);
if (logfs_super(sb)->s_flags & LOGFS_SB_FLAG_RO)
return -EROFS;
memset(&ei, 0, sizeof(ei));
ei.mtd = mtd;
ei.addr = ofs;
ei.len = len;
ei.callback = logfs_erase_callback;
ei.priv = (long)&complete;
ret = mtd_erase(mtd, &ei);
if (ret)
return -EIO;
wait_for_completion(&complete);
if (ei.state != MTD_ERASE_DONE)
return -EIO;
return logfs_mtd_erase_mapping(sb, ofs, len);
}
static void logfs_mtd_sync(struct super_block *sb)
{
struct mtd_info *mtd = logfs_super(sb)->s_mtd;
mtd_sync(mtd);
}
static int logfs_mtd_readpage(void *_sb, struct page *page)
{
struct super_block *sb = _sb;
int err;
err = logfs_mtd_read(sb, page->index << PAGE_SHIFT, PAGE_SIZE,
page_address(page));
if (err == -EUCLEAN || err == -EBADMSG) {
err = 0;
}
if (err) {
ClearPageUptodate(page);
SetPageError(page);
} else {
SetPageUptodate(page);
ClearPageError(page);
}
unlock_page(page);
return err;
}
static struct page *logfs_mtd_find_first_sb(struct super_block *sb, u64 *ofs)
{
struct logfs_super *super = logfs_super(sb);
struct address_space *mapping = super->s_mapping_inode->i_mapping;
filler_t *filler = logfs_mtd_readpage;
struct mtd_info *mtd = super->s_mtd;
*ofs = 0;
while (mtd_block_isbad(mtd, *ofs)) {
*ofs += mtd->erasesize;
if (*ofs >= mtd->size)
return NULL;
}
BUG_ON(*ofs & ~PAGE_MASK);
return read_cache_page(mapping, *ofs >> PAGE_SHIFT, filler, sb);
}
static struct page *logfs_mtd_find_last_sb(struct super_block *sb, u64 *ofs)
{
struct logfs_super *super = logfs_super(sb);
struct address_space *mapping = super->s_mapping_inode->i_mapping;
filler_t *filler = logfs_mtd_readpage;
struct mtd_info *mtd = super->s_mtd;
*ofs = mtd->size - mtd->erasesize;
while (mtd_block_isbad(mtd, *ofs)) {
*ofs -= mtd->erasesize;
if (*ofs <= 0)
return NULL;
}
*ofs = *ofs + mtd->erasesize - 0x1000;
BUG_ON(*ofs & ~PAGE_MASK);
return read_cache_page(mapping, *ofs >> PAGE_SHIFT, filler, sb);
}
static int __logfs_mtd_writeseg(struct super_block *sb, u64 ofs, pgoff_t index,
size_t nr_pages)
{
struct logfs_super *super = logfs_super(sb);
struct address_space *mapping = super->s_mapping_inode->i_mapping;
struct page *page;
int i, err;
for (i = 0; i < nr_pages; i++) {
page = find_lock_page(mapping, index + i);
BUG_ON(!page);
err = loffs_mtd_write(sb, page->index << PAGE_SHIFT, PAGE_SIZE,
page_address(page));
unlock_page(page);
put_page(page);
if (err)
return err;
}
return 0;
}
static void logfs_mtd_writeseg(struct super_block *sb, u64 ofs, size_t len)
{
struct logfs_super *super = logfs_super(sb);
int head;
if (super->s_flags & LOGFS_SB_FLAG_RO)
return;
if (len == 0) {
return;
}
head = ofs & (PAGE_SIZE - 1);
if (head) {
ofs -= head;
len += head;
}
len = PAGE_ALIGN(len);
__logfs_mtd_writeseg(sb, ofs, ofs >> PAGE_SHIFT, len >> PAGE_SHIFT);
}
static void logfs_mtd_put_device(struct logfs_super *s)
{
put_mtd_device(s->s_mtd);
}
static int logfs_mtd_can_write_buf(struct super_block *sb, u64 ofs)
{
struct logfs_super *super = logfs_super(sb);
void *buf;
int err;
buf = kmalloc(super->s_writesize, GFP_KERNEL);
if (!buf)
return -ENOMEM;
err = logfs_mtd_read(sb, ofs, super->s_writesize, buf);
if (err)
goto out;
if (memchr_inv(buf, 0xff, super->s_writesize))
err = -EIO;
kfree(buf);
out:
return err;
}
int logfs_get_sb_mtd(struct logfs_super *s, int mtdnr)
{
struct mtd_info *mtd = get_mtd_device(NULL, mtdnr);
if (IS_ERR(mtd))
return PTR_ERR(mtd);
s->s_bdev = NULL;
s->s_mtd = mtd;
s->s_devops = &mtd_devops;
return 0;
}
