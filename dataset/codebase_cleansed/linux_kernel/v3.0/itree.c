static inline void dirty_indirect(struct buffer_head *bh, struct inode *inode)
{
mark_buffer_dirty_inode(bh, inode);
if (IS_SYNC(inode))
sync_dirty_buffer(bh);
}
static int block_to_path(struct inode *inode, long block, int offsets[DEPTH])
{
struct super_block *sb = inode->i_sb;
struct sysv_sb_info *sbi = SYSV_SB(sb);
int ptrs_bits = sbi->s_ind_per_block_bits;
unsigned long indirect_blocks = sbi->s_ind_per_block,
double_blocks = sbi->s_ind_per_block_2;
int n = 0;
if (block < 0) {
printk("sysv_block_map: block < 0\n");
} else if (block < DIRECT) {
offsets[n++] = block;
} else if ( (block -= DIRECT) < indirect_blocks) {
offsets[n++] = DIRECT;
offsets[n++] = block;
} else if ((block -= indirect_blocks) < double_blocks) {
offsets[n++] = DIRECT+1;
offsets[n++] = block >> ptrs_bits;
offsets[n++] = block & (indirect_blocks - 1);
} else if (((block -= double_blocks) >> (ptrs_bits * 2)) < indirect_blocks) {
offsets[n++] = DIRECT+2;
offsets[n++] = block >> (ptrs_bits * 2);
offsets[n++] = (block >> ptrs_bits) & (indirect_blocks - 1);
offsets[n++] = block & (indirect_blocks - 1);
} else {
;
}
return n;
}
static inline int block_to_cpu(struct sysv_sb_info *sbi, sysv_zone_t nr)
{
return sbi->s_block_base + fs32_to_cpu(sbi, nr);
}
static inline void add_chain(Indirect *p, struct buffer_head *bh, sysv_zone_t *v)
{
p->key = *(p->p = v);
p->bh = bh;
}
static inline int verify_chain(Indirect *from, Indirect *to)
{
while (from <= to && from->key == *from->p)
from++;
return (from > to);
}
static inline sysv_zone_t *block_end(struct buffer_head *bh)
{
return (sysv_zone_t*)((char*)bh->b_data + bh->b_size);
}
static Indirect *get_branch(struct inode *inode,
int depth,
int offsets[],
Indirect chain[],
int *err)
{
struct super_block *sb = inode->i_sb;
Indirect *p = chain;
struct buffer_head *bh;
*err = 0;
add_chain(chain, NULL, SYSV_I(inode)->i_data + *offsets);
if (!p->key)
goto no_block;
while (--depth) {
int block = block_to_cpu(SYSV_SB(sb), p->key);
bh = sb_bread(sb, block);
if (!bh)
goto failure;
if (!verify_chain(chain, p))
goto changed;
add_chain(++p, bh, (sysv_zone_t*)bh->b_data + *++offsets);
if (!p->key)
goto no_block;
}
return NULL;
changed:
brelse(bh);
*err = -EAGAIN;
goto no_block;
failure:
*err = -EIO;
no_block:
return p;
}
static int alloc_branch(struct inode *inode,
int num,
int *offsets,
Indirect *branch)
{
int blocksize = inode->i_sb->s_blocksize;
int n = 0;
int i;
branch[0].key = sysv_new_block(inode->i_sb);
if (branch[0].key) for (n = 1; n < num; n++) {
struct buffer_head *bh;
int parent;
branch[n].key = sysv_new_block(inode->i_sb);
if (!branch[n].key)
break;
parent = block_to_cpu(SYSV_SB(inode->i_sb), branch[n-1].key);
bh = sb_getblk(inode->i_sb, parent);
lock_buffer(bh);
memset(bh->b_data, 0, blocksize);
branch[n].bh = bh;
branch[n].p = (sysv_zone_t*) bh->b_data + offsets[n];
*branch[n].p = branch[n].key;
set_buffer_uptodate(bh);
unlock_buffer(bh);
dirty_indirect(bh, inode);
}
if (n == num)
return 0;
for (i = 1; i < n; i++)
bforget(branch[i].bh);
for (i = 0; i < n; i++)
sysv_free_block(inode->i_sb, branch[i].key);
return -ENOSPC;
}
static inline int splice_branch(struct inode *inode,
Indirect chain[],
Indirect *where,
int num)
{
int i;
write_lock(&pointers_lock);
if (!verify_chain(chain, where-1) || *where->p)
goto changed;
*where->p = where->key;
write_unlock(&pointers_lock);
inode->i_ctime = CURRENT_TIME_SEC;
if (where->bh)
dirty_indirect(where->bh, inode);
if (IS_SYNC(inode))
sysv_sync_inode(inode);
else
mark_inode_dirty(inode);
return 0;
changed:
write_unlock(&pointers_lock);
for (i = 1; i < num; i++)
bforget(where[i].bh);
for (i = 0; i < num; i++)
sysv_free_block(inode->i_sb, where[i].key);
return -EAGAIN;
}
static int get_block(struct inode *inode, sector_t iblock, struct buffer_head *bh_result, int create)
{
int err = -EIO;
int offsets[DEPTH];
Indirect chain[DEPTH];
struct super_block *sb = inode->i_sb;
Indirect *partial;
int left;
int depth = block_to_path(inode, iblock, offsets);
if (depth == 0)
goto out;
reread:
read_lock(&pointers_lock);
partial = get_branch(inode, depth, offsets, chain, &err);
read_unlock(&pointers_lock);
if (!partial) {
got_it:
map_bh(bh_result, sb, block_to_cpu(SYSV_SB(sb),
chain[depth-1].key));
partial = chain+depth-1;
goto cleanup;
}
if (!create || err == -EIO) {
cleanup:
while (partial > chain) {
brelse(partial->bh);
partial--;
}
out:
return err;
}
if (err == -EAGAIN)
goto changed;
left = (chain + depth) - partial;
err = alloc_branch(inode, left, offsets+(partial-chain), partial);
if (err)
goto cleanup;
if (splice_branch(inode, chain, partial, left) < 0)
goto changed;
set_buffer_new(bh_result);
goto got_it;
changed:
while (partial > chain) {
brelse(partial->bh);
partial--;
}
goto reread;
}
static inline int all_zeroes(sysv_zone_t *p, sysv_zone_t *q)
{
while (p < q)
if (*p++)
return 0;
return 1;
}
static Indirect *find_shared(struct inode *inode,
int depth,
int offsets[],
Indirect chain[],
sysv_zone_t *top)
{
Indirect *partial, *p;
int k, err;
*top = 0;
for (k = depth; k > 1 && !offsets[k-1]; k--)
;
write_lock(&pointers_lock);
partial = get_branch(inode, k, offsets, chain, &err);
if (!partial)
partial = chain + k-1;
if (!partial->key && *partial->p) {
write_unlock(&pointers_lock);
goto no_top;
}
for (p=partial; p>chain && all_zeroes((sysv_zone_t*)p->bh->b_data,p->p); p--)
;
if (p == chain + k - 1 && p > chain) {
p->p--;
} else {
*top = *p->p;
*p->p = 0;
}
write_unlock(&pointers_lock);
while (partial > p) {
brelse(partial->bh);
partial--;
}
no_top:
return partial;
}
static inline void free_data(struct inode *inode, sysv_zone_t *p, sysv_zone_t *q)
{
for ( ; p < q ; p++) {
sysv_zone_t nr = *p;
if (nr) {
*p = 0;
sysv_free_block(inode->i_sb, nr);
mark_inode_dirty(inode);
}
}
}
static void free_branches(struct inode *inode, sysv_zone_t *p, sysv_zone_t *q, int depth)
{
struct buffer_head * bh;
struct super_block *sb = inode->i_sb;
if (depth--) {
for ( ; p < q ; p++) {
int block;
sysv_zone_t nr = *p;
if (!nr)
continue;
*p = 0;
block = block_to_cpu(SYSV_SB(sb), nr);
bh = sb_bread(sb, block);
if (!bh)
continue;
free_branches(inode, (sysv_zone_t*)bh->b_data,
block_end(bh), depth);
bforget(bh);
sysv_free_block(sb, nr);
mark_inode_dirty(inode);
}
} else
free_data(inode, p, q);
}
void sysv_truncate (struct inode * inode)
{
sysv_zone_t *i_data = SYSV_I(inode)->i_data;
int offsets[DEPTH];
Indirect chain[DEPTH];
Indirect *partial;
sysv_zone_t nr = 0;
int n;
long iblock;
unsigned blocksize;
if (!(S_ISREG(inode->i_mode) || S_ISDIR(inode->i_mode) ||
S_ISLNK(inode->i_mode)))
return;
blocksize = inode->i_sb->s_blocksize;
iblock = (inode->i_size + blocksize-1)
>> inode->i_sb->s_blocksize_bits;
block_truncate_page(inode->i_mapping, inode->i_size, get_block);
n = block_to_path(inode, iblock, offsets);
if (n == 0)
return;
if (n == 1) {
free_data(inode, i_data+offsets[0], i_data + DIRECT);
goto do_indirects;
}
partial = find_shared(inode, n, offsets, chain, &nr);
if (nr) {
if (partial == chain)
mark_inode_dirty(inode);
else
dirty_indirect(partial->bh, inode);
free_branches(inode, &nr, &nr+1, (chain+n-1) - partial);
}
while (partial > chain) {
free_branches(inode, partial->p + 1, block_end(partial->bh),
(chain+n-1) - partial);
dirty_indirect(partial->bh, inode);
brelse (partial->bh);
partial--;
}
do_indirects:
while (n < DEPTH) {
nr = i_data[DIRECT + n - 1];
if (nr) {
i_data[DIRECT + n - 1] = 0;
mark_inode_dirty(inode);
free_branches(inode, &nr, &nr+1, n);
}
n++;
}
inode->i_mtime = inode->i_ctime = CURRENT_TIME_SEC;
if (IS_SYNC(inode))
sysv_sync_inode (inode);
else
mark_inode_dirty(inode);
}
static unsigned sysv_nblocks(struct super_block *s, loff_t size)
{
struct sysv_sb_info *sbi = SYSV_SB(s);
int ptrs_bits = sbi->s_ind_per_block_bits;
unsigned blocks, res, direct = DIRECT, i = DEPTH;
blocks = (size + s->s_blocksize - 1) >> s->s_blocksize_bits;
res = blocks;
while (--i && blocks > direct) {
blocks = ((blocks - direct - 1) >> ptrs_bits) + 1;
res += blocks;
direct = 1;
}
return blocks;
}
int sysv_getattr(struct vfsmount *mnt, struct dentry *dentry, struct kstat *stat)
{
struct super_block *s = mnt->mnt_sb;
generic_fillattr(dentry->d_inode, stat);
stat->blocks = (s->s_blocksize / 512) * sysv_nblocks(s, stat->size);
stat->blksize = s->s_blocksize;
return 0;
}
static int sysv_writepage(struct page *page, struct writeback_control *wbc)
{
return block_write_full_page(page,get_block,wbc);
}
static int sysv_readpage(struct file *file, struct page *page)
{
return block_read_full_page(page,get_block);
}
int sysv_prepare_chunk(struct page *page, loff_t pos, unsigned len)
{
return __block_write_begin(page, pos, len, get_block);
}
static int sysv_write_begin(struct file *file, struct address_space *mapping,
loff_t pos, unsigned len, unsigned flags,
struct page **pagep, void **fsdata)
{
int ret;
ret = block_write_begin(mapping, pos, len, flags, pagep, get_block);
if (unlikely(ret)) {
loff_t isize = mapping->host->i_size;
if (pos + len > isize)
vmtruncate(mapping->host, isize);
}
return ret;
}
static sector_t sysv_bmap(struct address_space *mapping, sector_t block)
{
return generic_block_bmap(mapping,block,get_block);
}
