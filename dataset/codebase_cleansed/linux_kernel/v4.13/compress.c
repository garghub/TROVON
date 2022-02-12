int allocate_compression_buffers(void)
{
BUG_ON(ntfs_compression_buffer);
ntfs_compression_buffer = vmalloc(NTFS_MAX_CB_SIZE);
if (!ntfs_compression_buffer)
return -ENOMEM;
return 0;
}
void free_compression_buffers(void)
{
BUG_ON(!ntfs_compression_buffer);
vfree(ntfs_compression_buffer);
ntfs_compression_buffer = NULL;
}
static void zero_partial_compressed_page(struct page *page,
const s64 initialized_size)
{
u8 *kp = page_address(page);
unsigned int kp_ofs;
ntfs_debug("Zeroing page region outside initialized size.");
if (((s64)page->index << PAGE_SHIFT) >= initialized_size) {
clear_page(kp);
return;
}
kp_ofs = initialized_size & ~PAGE_MASK;
memset(kp + kp_ofs, 0, PAGE_SIZE - kp_ofs);
return;
}
static inline void handle_bounds_compressed_page(struct page *page,
const loff_t i_size, const s64 initialized_size)
{
if ((page->index >= (initialized_size >> PAGE_SHIFT)) &&
(initialized_size < i_size))
zero_partial_compressed_page(page, initialized_size);
return;
}
static int ntfs_decompress(struct page *dest_pages[], int *dest_index,
int *dest_ofs, const int dest_max_index, const int dest_max_ofs,
const int xpage, char *xpage_done, u8 *const cb_start,
const u32 cb_size, const loff_t i_size,
const s64 initialized_size)
{
u8 *cb_end = cb_start + cb_size;
u8 *cb = cb_start;
u8 *cb_sb_start = cb;
u8 *cb_sb_end;
struct page *dp;
u8 *dp_addr;
u8 *dp_sb_start;
u8 *dp_sb_end;
u16 do_sb_start;
u16 do_sb_end;
u8 tag;
int token;
int completed_pages[dest_max_index - *dest_index + 1];
int nr_completed_pages = 0;
int err = -EOVERFLOW;
ntfs_debug("Entering, cb_size = 0x%x.", cb_size);
do_next_sb:
ntfs_debug("Beginning sub-block at offset = 0x%zx in the cb.",
cb - cb_start);
if (cb == cb_end || !le16_to_cpup((le16*)cb) ||
(*dest_index == dest_max_index &&
*dest_ofs == dest_max_ofs)) {
int i;
ntfs_debug("Completed. Returning success (0).");
err = 0;
return_error:
spin_unlock(&ntfs_cb_lock);
if (nr_completed_pages > 0) {
for (i = 0; i < nr_completed_pages; i++) {
int di = completed_pages[i];
dp = dest_pages[di];
handle_bounds_compressed_page(dp, i_size,
initialized_size);
flush_dcache_page(dp);
kunmap(dp);
SetPageUptodate(dp);
unlock_page(dp);
if (di == xpage)
*xpage_done = 1;
else
put_page(dp);
dest_pages[di] = NULL;
}
}
return err;
}
do_sb_start = *dest_ofs;
do_sb_end = do_sb_start + NTFS_SB_SIZE;
if (*dest_index == dest_max_index && do_sb_end > dest_max_ofs)
goto return_overflow;
if (cb + 6 > cb_end)
goto return_overflow;
cb_sb_start = cb;
cb_sb_end = cb_sb_start + (le16_to_cpup((le16*)cb) & NTFS_SB_SIZE_MASK)
+ 3;
if (cb_sb_end > cb_end)
goto return_overflow;
dp = dest_pages[*dest_index];
if (!dp) {
cb = cb_sb_end;
*dest_ofs = (*dest_ofs + NTFS_SB_SIZE) & ~PAGE_MASK;
if (!*dest_ofs && (++*dest_index > dest_max_index))
goto return_overflow;
goto do_next_sb;
}
dp_addr = (u8*)page_address(dp) + do_sb_start;
if (!(le16_to_cpup((le16*)cb) & NTFS_SB_IS_COMPRESSED)) {
ntfs_debug("Found uncompressed sub-block.");
cb += 2;
if (cb_sb_end - cb != NTFS_SB_SIZE)
goto return_overflow;
memcpy(dp_addr, cb, NTFS_SB_SIZE);
cb += NTFS_SB_SIZE;
*dest_ofs += NTFS_SB_SIZE;
if (!(*dest_ofs &= ~PAGE_MASK)) {
finalize_page:
completed_pages[nr_completed_pages++] = *dest_index;
if (++*dest_index > dest_max_index)
goto return_overflow;
}
goto do_next_sb;
}
ntfs_debug("Found compressed sub-block.");
dp_sb_start = dp_addr;
dp_sb_end = dp_sb_start + NTFS_SB_SIZE;
cb += 2;
do_next_tag:
if (cb == cb_sb_end) {
if (dp_addr < dp_sb_end) {
int nr_bytes = do_sb_end - *dest_ofs;
ntfs_debug("Filling incomplete sub-block with "
"zeroes.");
memset(dp_addr, 0, nr_bytes);
*dest_ofs += nr_bytes;
}
if (!(*dest_ofs &= ~PAGE_MASK))
goto finalize_page;
goto do_next_sb;
}
if (cb > cb_sb_end || dp_addr > dp_sb_end)
goto return_overflow;
tag = *cb++;
for (token = 0; token < 8; token++, tag >>= 1) {
u16 lg, pt, length, max_non_overlap;
register u16 i;
u8 *dp_back_addr;
if (cb >= cb_sb_end || dp_addr > dp_sb_end)
break;
if ((tag & NTFS_TOKEN_MASK) == NTFS_SYMBOL_TOKEN) {
*dp_addr++ = *cb++;
++*dest_ofs;
continue;
}
if (dp_addr == dp_sb_start)
goto return_overflow;
lg = 0;
for (i = *dest_ofs - do_sb_start - 1; i >= 0x10; i >>= 1)
lg++;
pt = le16_to_cpup((le16*)cb);
dp_back_addr = dp_addr - (pt >> (12 - lg)) - 1;
if (dp_back_addr < dp_sb_start)
goto return_overflow;
length = (pt & (0xfff >> lg)) + 3;
*dest_ofs += length;
if (*dest_ofs > do_sb_end)
goto return_overflow;
max_non_overlap = dp_addr - dp_back_addr;
if (length <= max_non_overlap) {
memcpy(dp_addr, dp_back_addr, length);
dp_addr += length;
} else {
memcpy(dp_addr, dp_back_addr, max_non_overlap);
dp_addr += max_non_overlap;
dp_back_addr += max_non_overlap;
length -= max_non_overlap;
while (length--)
*dp_addr++ = *dp_back_addr++;
}
cb += 2;
}
goto do_next_tag;
return_overflow:
ntfs_error(NULL, "Failed. Returning -EOVERFLOW.");
goto return_error;
}
int ntfs_read_compressed_block(struct page *page)
{
loff_t i_size;
s64 initialized_size;
struct address_space *mapping = page->mapping;
ntfs_inode *ni = NTFS_I(mapping->host);
ntfs_volume *vol = ni->vol;
struct super_block *sb = vol->sb;
runlist_element *rl;
unsigned long flags, block_size = sb->s_blocksize;
unsigned char block_size_bits = sb->s_blocksize_bits;
u8 *cb, *cb_pos, *cb_end;
struct buffer_head **bhs;
unsigned long offset, index = page->index;
u32 cb_size = ni->itype.compressed.block_size;
u64 cb_size_mask = cb_size - 1UL;
VCN vcn;
LCN lcn;
VCN start_vcn = (((s64)index << PAGE_SHIFT) & ~cb_size_mask) >>
vol->cluster_size_bits;
VCN end_vcn = ((((s64)(index + 1UL) << PAGE_SHIFT) + cb_size - 1)
& ~cb_size_mask) >> vol->cluster_size_bits;
unsigned int nr_cbs = (end_vcn - start_vcn) << vol->cluster_size_bits
>> ni->itype.compressed.block_size_bits;
unsigned int nr_pages = (end_vcn - start_vcn) <<
vol->cluster_size_bits >> PAGE_SHIFT;
unsigned int xpage, max_page, cur_page, cur_ofs, i;
unsigned int cb_clusters, cb_max_ofs;
int block, max_block, cb_max_page, bhs_size, nr_bhs, err = 0;
struct page **pages;
unsigned char xpage_done = 0;
ntfs_debug("Entering, page->index = 0x%lx, cb_size = 0x%x, nr_pages = "
"%i.", index, cb_size, nr_pages);
BUG_ON(ni->type != AT_DATA);
BUG_ON(ni->name_len);
pages = kmalloc(nr_pages * sizeof(struct page *), GFP_NOFS);
bhs_size = cb_size / block_size * sizeof(struct buffer_head *);
bhs = kmalloc(bhs_size, GFP_NOFS);
if (unlikely(!pages || !bhs)) {
kfree(bhs);
kfree(pages);
unlock_page(page);
ntfs_error(vol->sb, "Failed to allocate internal buffers.");
return -ENOMEM;
}
offset = start_vcn << vol->cluster_size_bits >> PAGE_SHIFT;
xpage = index - offset;
pages[xpage] = page;
read_lock_irqsave(&ni->size_lock, flags);
i_size = i_size_read(VFS_I(ni));
initialized_size = ni->initialized_size;
read_unlock_irqrestore(&ni->size_lock, flags);
max_page = ((i_size + PAGE_SIZE - 1) >> PAGE_SHIFT) -
offset;
if (xpage >= max_page) {
kfree(bhs);
kfree(pages);
zero_user(page, 0, PAGE_SIZE);
ntfs_debug("Compressed read outside i_size - truncated?");
SetPageUptodate(page);
unlock_page(page);
return 0;
}
if (nr_pages < max_page)
max_page = nr_pages;
for (i = 0; i < max_page; i++, offset++) {
if (i != xpage)
pages[i] = grab_cache_page_nowait(mapping, offset);
page = pages[i];
if (page) {
if (!PageDirty(page) && (!PageUptodate(page) ||
PageError(page))) {
ClearPageError(page);
kmap(page);
continue;
}
unlock_page(page);
put_page(page);
pages[i] = NULL;
}
}
cur_page = 0;
cur_ofs = 0;
cb_clusters = ni->itype.compressed.block_clusters;
do_next_cb:
nr_cbs--;
nr_bhs = 0;
rl = NULL;
for (vcn = start_vcn, start_vcn += cb_clusters; vcn < start_vcn;
vcn++) {
bool is_retry = false;
if (!rl) {
lock_retry_remap:
down_read(&ni->runlist.lock);
rl = ni->runlist.rl;
}
if (likely(rl != NULL)) {
while (rl->length && rl[1].vcn <= vcn)
rl++;
lcn = ntfs_rl_vcn_to_lcn(rl, vcn);
} else
lcn = LCN_RL_NOT_MAPPED;
ntfs_debug("Reading vcn = 0x%llx, lcn = 0x%llx.",
(unsigned long long)vcn,
(unsigned long long)lcn);
if (lcn < 0) {
if (lcn == LCN_HOLE)
break;
if (is_retry || lcn != LCN_RL_NOT_MAPPED)
goto rl_err;
is_retry = true;
up_read(&ni->runlist.lock);
if (!ntfs_map_runlist(ni, vcn))
goto lock_retry_remap;
goto map_rl_err;
}
block = lcn << vol->cluster_size_bits >> block_size_bits;
max_block = block + (vol->cluster_size >> block_size_bits);
do {
ntfs_debug("block = 0x%x.", block);
if (unlikely(!(bhs[nr_bhs] = sb_getblk(sb, block))))
goto getblk_err;
nr_bhs++;
} while (++block < max_block);
}
if (rl)
up_read(&ni->runlist.lock);
for (i = 0; i < nr_bhs; i++) {
struct buffer_head *tbh = bhs[i];
if (!trylock_buffer(tbh))
continue;
if (unlikely(buffer_uptodate(tbh))) {
unlock_buffer(tbh);
continue;
}
get_bh(tbh);
tbh->b_end_io = end_buffer_read_sync;
submit_bh(REQ_OP_READ, 0, tbh);
}
for (i = 0; i < nr_bhs; i++) {
struct buffer_head *tbh = bhs[i];
if (buffer_uptodate(tbh))
continue;
wait_on_buffer(tbh);
barrier();
if (unlikely(!buffer_uptodate(tbh))) {
ntfs_warning(vol->sb, "Buffer is unlocked but not "
"uptodate! Unplugging the disk queue "
"and rescheduling.");
get_bh(tbh);
io_schedule();
put_bh(tbh);
if (unlikely(!buffer_uptodate(tbh)))
goto read_err;
ntfs_warning(vol->sb, "Buffer is now uptodate. Good.");
}
}
spin_lock(&ntfs_cb_lock);
cb = ntfs_compression_buffer;
BUG_ON(!cb);
cb_pos = cb;
cb_end = cb + cb_size;
for (i = 0; i < nr_bhs; i++) {
memcpy(cb_pos, bhs[i]->b_data, block_size);
cb_pos += block_size;
}
if (cb_pos + 2 <= cb + cb_size)
*(u16*)cb_pos = 0;
cb_pos = cb;
ntfs_debug("Successfully read the compression block.");
cb_max_page = (cur_page << PAGE_SHIFT) + cur_ofs + cb_size;
cb_max_ofs = cb_max_page & ~PAGE_MASK;
cb_max_page >>= PAGE_SHIFT;
if (cb_max_page > max_page)
cb_max_page = max_page;
if (vcn == start_vcn - cb_clusters) {
ntfs_debug("Found sparse compression block.");
spin_unlock(&ntfs_cb_lock);
if (cb_max_ofs)
cb_max_page--;
for (; cur_page < cb_max_page; cur_page++) {
page = pages[cur_page];
if (page) {
if (likely(!cur_ofs))
clear_page(page_address(page));
else
memset(page_address(page) + cur_ofs, 0,
PAGE_SIZE -
cur_ofs);
flush_dcache_page(page);
kunmap(page);
SetPageUptodate(page);
unlock_page(page);
if (cur_page == xpage)
xpage_done = 1;
else
put_page(page);
pages[cur_page] = NULL;
}
cb_pos += PAGE_SIZE - cur_ofs;
cur_ofs = 0;
if (cb_pos >= cb_end)
break;
}
if (cb_max_ofs && cb_pos < cb_end) {
page = pages[cur_page];
if (page)
memset(page_address(page) + cur_ofs, 0,
cb_max_ofs - cur_ofs);
cur_ofs = cb_max_ofs;
}
} else if (vcn == start_vcn) {
unsigned int cur2_page = cur_page;
unsigned int cur_ofs2 = cur_ofs;
u8 *cb_pos2 = cb_pos;
ntfs_debug("Found uncompressed compression block.");
if (cb_max_ofs)
cb_max_page--;
for (; cur_page < cb_max_page; cur_page++) {
page = pages[cur_page];
if (page)
memcpy(page_address(page) + cur_ofs, cb_pos,
PAGE_SIZE - cur_ofs);
cb_pos += PAGE_SIZE - cur_ofs;
cur_ofs = 0;
if (cb_pos >= cb_end)
break;
}
if (cb_max_ofs && cb_pos < cb_end) {
page = pages[cur_page];
if (page)
memcpy(page_address(page) + cur_ofs, cb_pos,
cb_max_ofs - cur_ofs);
cb_pos += cb_max_ofs - cur_ofs;
cur_ofs = cb_max_ofs;
}
spin_unlock(&ntfs_cb_lock);
for (; cur2_page < cb_max_page; cur2_page++) {
page = pages[cur2_page];
if (page) {
handle_bounds_compressed_page(page, i_size,
initialized_size);
flush_dcache_page(page);
kunmap(page);
SetPageUptodate(page);
unlock_page(page);
if (cur2_page == xpage)
xpage_done = 1;
else
put_page(page);
pages[cur2_page] = NULL;
}
cb_pos2 += PAGE_SIZE - cur_ofs2;
cur_ofs2 = 0;
if (cb_pos2 >= cb_end)
break;
}
} else {
unsigned int prev_cur_page = cur_page;
ntfs_debug("Found compressed compression block.");
err = ntfs_decompress(pages, &cur_page, &cur_ofs,
cb_max_page, cb_max_ofs, xpage, &xpage_done,
cb_pos, cb_size - (cb_pos - cb), i_size,
initialized_size);
if (err) {
ntfs_error(vol->sb, "ntfs_decompress() failed in inode "
"0x%lx with error code %i. Skipping "
"this compression block.",
ni->mft_no, -err);
for (; prev_cur_page < cur_page; prev_cur_page++) {
page = pages[prev_cur_page];
if (page) {
flush_dcache_page(page);
kunmap(page);
unlock_page(page);
if (prev_cur_page != xpage)
put_page(page);
pages[prev_cur_page] = NULL;
}
}
}
}
for (i = 0; i < nr_bhs; i++)
brelse(bhs[i]);
if (nr_cbs)
goto do_next_cb;
kfree(bhs);
for (cur_page = 0; cur_page < max_page; cur_page++) {
page = pages[cur_page];
if (page) {
ntfs_error(vol->sb, "Still have pages left! "
"Terminating them with extreme "
"prejudice. Inode 0x%lx, page index "
"0x%lx.", ni->mft_no, page->index);
flush_dcache_page(page);
kunmap(page);
unlock_page(page);
if (cur_page != xpage)
put_page(page);
pages[cur_page] = NULL;
}
}
kfree(pages);
if (likely(xpage_done))
return 0;
ntfs_debug("Failed. Returning error code %s.", err == -EOVERFLOW ?
"EOVERFLOW" : (!err ? "EIO" : "unknown error"));
return err < 0 ? err : -EIO;
read_err:
ntfs_error(vol->sb, "IO error while reading compressed data.");
for (i = 0; i < nr_bhs; i++)
brelse(bhs[i]);
goto err_out;
map_rl_err:
ntfs_error(vol->sb, "ntfs_map_runlist() failed. Cannot read "
"compression block.");
goto err_out;
rl_err:
up_read(&ni->runlist.lock);
ntfs_error(vol->sb, "ntfs_rl_vcn_to_lcn() failed. Cannot read "
"compression block.");
goto err_out;
getblk_err:
up_read(&ni->runlist.lock);
ntfs_error(vol->sb, "getblk() failed. Cannot read compression block.");
err_out:
kfree(bhs);
for (i = cur_page; i < max_page; i++) {
page = pages[i];
if (page) {
flush_dcache_page(page);
kunmap(page);
unlock_page(page);
if (i != xpage)
put_page(page);
}
}
kfree(pages);
return -EIO;
}
