struct buffer_head *
befs_read_datastream(struct super_block *sb, const befs_data_stream *ds,
befs_off_t pos, uint *off)
{
struct buffer_head *bh;
befs_block_run run;
befs_blocknr_t block;
befs_debug(sb, "---> %s %llu", __func__, pos);
block = pos >> BEFS_SB(sb)->block_shift;
if (off)
*off = pos - (block << BEFS_SB(sb)->block_shift);
if (befs_fblock2brun(sb, ds, block, &run) != BEFS_OK) {
befs_error(sb, "BeFS: Error finding disk addr of block %lu",
(unsigned long)block);
befs_debug(sb, "<--- %s ERROR", __func__);
return NULL;
}
bh = befs_bread_iaddr(sb, run);
if (!bh) {
befs_error(sb, "BeFS: Error reading block %lu from datastream",
(unsigned long)block);
return NULL;
}
befs_debug(sb, "<--- %s read data, starting at %llu", __func__, pos);
return bh;
}
int
befs_fblock2brun(struct super_block *sb, const befs_data_stream *data,
befs_blocknr_t fblock, befs_block_run *run)
{
int err;
befs_off_t pos = fblock << BEFS_SB(sb)->block_shift;
if (pos < data->max_direct_range) {
err = befs_find_brun_direct(sb, data, fblock, run);
} else if (pos < data->max_indirect_range) {
err = befs_find_brun_indirect(sb, data, fblock, run);
} else if (pos < data->max_double_indirect_range) {
err = befs_find_brun_dblindirect(sb, data, fblock, run);
} else {
befs_error(sb,
"befs_fblock2brun() was asked to find block %lu, "
"which is not mapped by the datastream\n",
(unsigned long)fblock);
err = BEFS_ERR;
}
return err;
}
size_t
befs_read_lsymlink(struct super_block *sb, const befs_data_stream *ds,
void *buff, befs_off_t len)
{
befs_off_t bytes_read = 0;
u16 plen;
struct buffer_head *bh;
befs_debug(sb, "---> %s length: %llu", __func__, len);
while (bytes_read < len) {
bh = befs_read_datastream(sb, ds, bytes_read, NULL);
if (!bh) {
befs_error(sb, "BeFS: Error reading datastream block "
"starting from %llu", bytes_read);
befs_debug(sb, "<--- %s ERROR", __func__);
return bytes_read;
}
plen = ((bytes_read + BEFS_SB(sb)->block_size) < len) ?
BEFS_SB(sb)->block_size : len - bytes_read;
memcpy(buff + bytes_read, bh->b_data, plen);
brelse(bh);
bytes_read += plen;
}
befs_debug(sb, "<--- %s read %u bytes", __func__, (unsigned int)
bytes_read);
return bytes_read;
}
befs_blocknr_t
befs_count_blocks(struct super_block *sb, const befs_data_stream *ds)
{
befs_blocknr_t blocks;
befs_blocknr_t datablocks;
befs_blocknr_t metablocks;
struct befs_sb_info *befs_sb = BEFS_SB(sb);
befs_debug(sb, "---> %s", __func__);
datablocks = ds->size >> befs_sb->block_shift;
if (ds->size & (befs_sb->block_size - 1))
datablocks += 1;
metablocks = 1;
if (ds->size > ds->max_direct_range)
metablocks += ds->indirect.len;
if (ds->size > ds->max_indirect_range && ds->max_indirect_range != 0) {
uint dbl_bytes;
uint dbl_bruns;
uint indirblocks;
dbl_bytes =
ds->max_double_indirect_range - ds->max_indirect_range;
dbl_bruns =
dbl_bytes / (befs_sb->block_size * BEFS_DBLINDIR_BRUN_LEN);
indirblocks = dbl_bruns / befs_iaddrs_per_block(sb);
metablocks += ds->double_indirect.len;
metablocks += indirblocks;
}
blocks = datablocks + metablocks;
befs_debug(sb, "<--- %s %u blocks", __func__, (unsigned int)blocks);
return blocks;
}
static int
befs_find_brun_direct(struct super_block *sb, const befs_data_stream *data,
befs_blocknr_t blockno, befs_block_run *run)
{
int i;
const befs_block_run *array = data->direct;
befs_blocknr_t sum;
befs_debug(sb, "---> %s, find %lu", __func__, (unsigned long)blockno);
for (i = 0, sum = 0; i < BEFS_NUM_DIRECT_BLOCKS;
sum += array[i].len, i++) {
if (blockno >= sum && blockno < sum + (array[i].len)) {
int offset = blockno - sum;
run->allocation_group = array[i].allocation_group;
run->start = array[i].start + offset;
run->len = array[i].len - offset;
befs_debug(sb, "---> %s, "
"found %lu at direct[%d]", __func__,
(unsigned long)blockno, i);
return BEFS_OK;
}
}
befs_error(sb, "%s failed to find file block %lu", __func__,
(unsigned long)blockno);
befs_debug(sb, "---> %s ERROR", __func__);
return BEFS_ERR;
}
static int
befs_find_brun_indirect(struct super_block *sb,
const befs_data_stream *data,
befs_blocknr_t blockno,
befs_block_run *run)
{
int i, j;
befs_blocknr_t sum = 0;
befs_blocknr_t indir_start_blk;
befs_blocknr_t search_blk;
struct buffer_head *indirblock;
befs_disk_block_run *array;
befs_block_run indirect = data->indirect;
befs_blocknr_t indirblockno = iaddr2blockno(sb, &indirect);
int arraylen = befs_iaddrs_per_block(sb);
befs_debug(sb, "---> %s, find %lu", __func__, (unsigned long)blockno);
indir_start_blk = data->max_direct_range >> BEFS_SB(sb)->block_shift;
search_blk = blockno - indir_start_blk;
for (i = 0; i < indirect.len; i++) {
indirblock = sb_bread(sb, indirblockno + i);
if (indirblock == NULL) {
befs_error(sb, "---> %s failed to read "
"disk block %lu from the indirect brun",
__func__, (unsigned long)indirblockno + i);
befs_debug(sb, "<--- %s ERROR", __func__);
return BEFS_ERR;
}
array = (befs_disk_block_run *) indirblock->b_data;
for (j = 0; j < arraylen; ++j) {
int len = fs16_to_cpu(sb, array[j].len);
if (search_blk >= sum && search_blk < sum + len) {
int offset = search_blk - sum;
run->allocation_group =
fs32_to_cpu(sb, array[j].allocation_group);
run->start =
fs16_to_cpu(sb, array[j].start) + offset;
run->len =
fs16_to_cpu(sb, array[j].len) - offset;
brelse(indirblock);
befs_debug(sb,
"<--- %s found file block "
"%lu at indirect[%d]", __func__,
(unsigned long)blockno,
j + (i * arraylen));
return BEFS_OK;
}
sum += len;
}
brelse(indirblock);
}
befs_error(sb, "BeFS: %s failed to find "
"file block %lu", __func__, (unsigned long)blockno);
befs_debug(sb, "<--- %s ERROR", __func__);
return BEFS_ERR;
}
static int
befs_find_brun_dblindirect(struct super_block *sb,
const befs_data_stream *data,
befs_blocknr_t blockno,
befs_block_run *run)
{
int dblindir_indx;
int indir_indx;
int offset;
int dbl_which_block;
int which_block;
int dbl_block_indx;
int block_indx;
off_t dblindir_leftover;
befs_blocknr_t blockno_at_run_start;
struct buffer_head *dbl_indir_block;
struct buffer_head *indir_block;
befs_block_run indir_run;
befs_disk_inode_addr *iaddr_array;
befs_blocknr_t indir_start_blk =
data->max_indirect_range >> BEFS_SB(sb)->block_shift;
off_t dbl_indir_off = blockno - indir_start_blk;
size_t iblklen = BEFS_DBLINDIR_BRUN_LEN;
size_t diblklen = iblklen * befs_iaddrs_per_block(sb)
* BEFS_DBLINDIR_BRUN_LEN;
befs_debug(sb, "---> %s find %lu", __func__, (unsigned long)blockno);
dblindir_indx = dbl_indir_off / diblklen;
dblindir_leftover = dbl_indir_off % diblklen;
indir_indx = dblindir_leftover / diblklen;
dbl_which_block = dblindir_indx / befs_iaddrs_per_block(sb);
if (dbl_which_block > data->double_indirect.len) {
befs_error(sb, "The double-indirect index calculated by "
"%s, %d, is outside the range "
"of the double-indirect block", __func__,
dblindir_indx);
return BEFS_ERR;
}
dbl_indir_block =
sb_bread(sb, iaddr2blockno(sb, &data->double_indirect) +
dbl_which_block);
if (dbl_indir_block == NULL) {
befs_error(sb, "%s couldn't read the "
"double-indirect block at blockno %lu", __func__,
(unsigned long)
iaddr2blockno(sb, &data->double_indirect) +
dbl_which_block);
return BEFS_ERR;
}
dbl_block_indx =
dblindir_indx - (dbl_which_block * befs_iaddrs_per_block(sb));
iaddr_array = (befs_disk_inode_addr *) dbl_indir_block->b_data;
indir_run = fsrun_to_cpu(sb, iaddr_array[dbl_block_indx]);
brelse(dbl_indir_block);
which_block = indir_indx / befs_iaddrs_per_block(sb);
if (which_block > indir_run.len) {
befs_error(sb, "The indirect index calculated by "
"%s, %d, is outside the range "
"of the indirect block", __func__, indir_indx);
return BEFS_ERR;
}
indir_block =
sb_bread(sb, iaddr2blockno(sb, &indir_run) + which_block);
if (indir_block == NULL) {
befs_error(sb, "%s couldn't read the indirect block "
"at blockno %lu", __func__, (unsigned long)
iaddr2blockno(sb, &indir_run) + which_block);
return BEFS_ERR;
}
block_indx = indir_indx - (which_block * befs_iaddrs_per_block(sb));
iaddr_array = (befs_disk_inode_addr *) indir_block->b_data;
*run = fsrun_to_cpu(sb, iaddr_array[block_indx]);
brelse(indir_block);
blockno_at_run_start = indir_start_blk;
blockno_at_run_start += diblklen * dblindir_indx;
blockno_at_run_start += iblklen * indir_indx;
offset = blockno - blockno_at_run_start;
run->start += offset;
run->len -= offset;
befs_debug(sb, "Found file block %lu in double_indirect[%d][%d],"
" double_indirect_leftover = %lu", (unsigned long)
blockno, dblindir_indx, indir_indx, dblindir_leftover);
return BEFS_OK;
}
