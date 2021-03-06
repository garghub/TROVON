void ext4_fsmap_from_internal(struct super_block *sb, struct fsmap *dest,
struct ext4_fsmap *src)
{
dest->fmr_device = src->fmr_device;
dest->fmr_flags = src->fmr_flags;
dest->fmr_physical = src->fmr_physical << sb->s_blocksize_bits;
dest->fmr_owner = src->fmr_owner;
dest->fmr_offset = 0;
dest->fmr_length = src->fmr_length << sb->s_blocksize_bits;
dest->fmr_reserved[0] = 0;
dest->fmr_reserved[1] = 0;
dest->fmr_reserved[2] = 0;
}
void ext4_fsmap_to_internal(struct super_block *sb, struct ext4_fsmap *dest,
struct fsmap *src)
{
dest->fmr_device = src->fmr_device;
dest->fmr_flags = src->fmr_flags;
dest->fmr_physical = src->fmr_physical >> sb->s_blocksize_bits;
dest->fmr_owner = src->fmr_owner;
dest->fmr_length = src->fmr_length >> sb->s_blocksize_bits;
}
static int ext4_getfsmap_dev_compare(const void *p1, const void *p2)
{
const struct ext4_getfsmap_dev *d1 = p1;
const struct ext4_getfsmap_dev *d2 = p2;
return d1->gfd_dev - d2->gfd_dev;
}
static bool ext4_getfsmap_rec_before_low_key(struct ext4_getfsmap_info *info,
struct ext4_fsmap *rec)
{
return rec->fmr_physical < info->gfi_low.fmr_physical;
}
static int ext4_getfsmap_helper(struct super_block *sb,
struct ext4_getfsmap_info *info,
struct ext4_fsmap *rec)
{
struct ext4_fsmap fmr;
struct ext4_sb_info *sbi = EXT4_SB(sb);
ext4_fsblk_t rec_fsblk = rec->fmr_physical;
ext4_group_t agno;
ext4_grpblk_t cno;
int error;
if (fatal_signal_pending(current))
return -EINTR;
if (ext4_getfsmap_rec_before_low_key(info, rec)) {
rec_fsblk += rec->fmr_length;
if (info->gfi_next_fsblk < rec_fsblk)
info->gfi_next_fsblk = rec_fsblk;
return EXT4_QUERY_RANGE_CONTINUE;
}
if (info->gfi_head->fmh_count == 0) {
if (rec_fsblk > info->gfi_next_fsblk)
info->gfi_head->fmh_entries++;
if (info->gfi_last)
return EXT4_QUERY_RANGE_CONTINUE;
info->gfi_head->fmh_entries++;
rec_fsblk += rec->fmr_length;
if (info->gfi_next_fsblk < rec_fsblk)
info->gfi_next_fsblk = rec_fsblk;
return EXT4_QUERY_RANGE_CONTINUE;
}
if (rec_fsblk > info->gfi_next_fsblk) {
if (info->gfi_head->fmh_entries >= info->gfi_head->fmh_count)
return EXT4_QUERY_RANGE_ABORT;
ext4_get_group_no_and_offset(sb, info->gfi_next_fsblk,
&agno, &cno);
trace_ext4_fsmap_mapping(sb, info->gfi_dev, agno,
EXT4_C2B(sbi, cno),
rec_fsblk - info->gfi_next_fsblk,
EXT4_FMR_OWN_UNKNOWN);
fmr.fmr_device = info->gfi_dev;
fmr.fmr_physical = info->gfi_next_fsblk;
fmr.fmr_owner = EXT4_FMR_OWN_UNKNOWN;
fmr.fmr_length = rec_fsblk - info->gfi_next_fsblk;
fmr.fmr_flags = FMR_OF_SPECIAL_OWNER;
error = info->gfi_formatter(&fmr, info->gfi_format_arg);
if (error)
return error;
info->gfi_head->fmh_entries++;
}
if (info->gfi_last)
goto out;
if (info->gfi_head->fmh_entries >= info->gfi_head->fmh_count)
return EXT4_QUERY_RANGE_ABORT;
ext4_get_group_no_and_offset(sb, rec_fsblk, &agno, &cno);
trace_ext4_fsmap_mapping(sb, info->gfi_dev, agno, EXT4_C2B(sbi, cno),
rec->fmr_length, rec->fmr_owner);
fmr.fmr_device = info->gfi_dev;
fmr.fmr_physical = rec_fsblk;
fmr.fmr_owner = rec->fmr_owner;
fmr.fmr_flags = FMR_OF_SPECIAL_OWNER;
fmr.fmr_length = rec->fmr_length;
error = info->gfi_formatter(&fmr, info->gfi_format_arg);
if (error)
return error;
info->gfi_head->fmh_entries++;
out:
rec_fsblk += rec->fmr_length;
if (info->gfi_next_fsblk < rec_fsblk)
info->gfi_next_fsblk = rec_fsblk;
return EXT4_QUERY_RANGE_CONTINUE;
}
static inline ext4_fsblk_t ext4_fsmap_next_pblk(struct ext4_fsmap *fmr)
{
return fmr->fmr_physical + fmr->fmr_length;
}
static int ext4_getfsmap_datadev_helper(struct super_block *sb,
ext4_group_t agno, ext4_grpblk_t start,
ext4_grpblk_t len, void *priv)
{
struct ext4_fsmap irec;
struct ext4_getfsmap_info *info = priv;
struct ext4_fsmap *p;
struct ext4_fsmap *tmp;
struct ext4_sb_info *sbi = EXT4_SB(sb);
ext4_fsblk_t fsb;
ext4_fsblk_t fslen;
int error;
fsb = (EXT4_C2B(sbi, start) + ext4_group_first_block_no(sb, agno));
fslen = EXT4_C2B(sbi, len);
if (info->gfi_lastfree.fmr_owner) {
if (ext4_fsmap_next_pblk(&info->gfi_lastfree) == fsb) {
info->gfi_lastfree.fmr_length += fslen;
return 0;
}
error = ext4_getfsmap_helper(sb, info, &info->gfi_lastfree);
if (error)
return error;
info->gfi_lastfree.fmr_owner = 0;
}
list_for_each_entry_safe(p, tmp, &info->gfi_meta_list, fmr_list) {
if (p->fmr_physical + p->fmr_length <= info->gfi_next_fsblk) {
list_del(&p->fmr_list);
kfree(p);
} else if (p->fmr_physical < fsb) {
error = ext4_getfsmap_helper(sb, info, p);
if (error)
return error;
list_del(&p->fmr_list);
kfree(p);
}
}
irec.fmr_device = 0;
irec.fmr_physical = fsb;
irec.fmr_length = fslen;
irec.fmr_owner = EXT4_FMR_OWN_FREE;
irec.fmr_flags = 0;
if (ext4_fsmap_next_pblk(&irec) ==
ext4_group_first_block_no(sb, agno + 1)) {
info->gfi_lastfree = irec;
return 0;
}
return ext4_getfsmap_helper(sb, info, &irec);
}
static int ext4_getfsmap_logdev(struct super_block *sb, struct ext4_fsmap *keys,
struct ext4_getfsmap_info *info)
{
journal_t *journal = EXT4_SB(sb)->s_journal;
struct ext4_fsmap irec;
info->gfi_low = keys[0];
info->gfi_low.fmr_length = 0;
memset(&info->gfi_high, 0xFF, sizeof(info->gfi_high));
trace_ext4_fsmap_low_key(sb, info->gfi_dev, 0,
info->gfi_low.fmr_physical,
info->gfi_low.fmr_length,
info->gfi_low.fmr_owner);
trace_ext4_fsmap_high_key(sb, info->gfi_dev, 0,
info->gfi_high.fmr_physical,
info->gfi_high.fmr_length,
info->gfi_high.fmr_owner);
if (keys[0].fmr_physical > 0)
return 0;
irec.fmr_physical = journal->j_blk_offset;
irec.fmr_length = journal->j_maxlen;
irec.fmr_owner = EXT4_FMR_OWN_LOG;
irec.fmr_flags = 0;
return ext4_getfsmap_helper(sb, info, &irec);
}
static inline int ext4_getfsmap_fill(struct list_head *meta_list,
ext4_fsblk_t fsb, ext4_fsblk_t len,
uint64_t owner)
{
struct ext4_fsmap *fsm;
fsm = kmalloc(sizeof(*fsm), GFP_NOFS);
if (!fsm)
return -ENOMEM;
fsm->fmr_device = 0;
fsm->fmr_flags = 0;
fsm->fmr_physical = fsb;
fsm->fmr_owner = owner;
fsm->fmr_length = len;
list_add_tail(&fsm->fmr_list, meta_list);
return 0;
}
static unsigned int ext4_getfsmap_find_sb(struct super_block *sb,
ext4_group_t agno,
struct list_head *meta_list)
{
struct ext4_sb_info *sbi = EXT4_SB(sb);
ext4_fsblk_t fsb = ext4_group_first_block_no(sb, agno);
ext4_fsblk_t len;
unsigned long first_meta_bg = le32_to_cpu(sbi->s_es->s_first_meta_bg);
unsigned long metagroup = agno / EXT4_DESC_PER_BLOCK(sb);
int error;
if (ext4_bg_has_super(sb, agno)) {
error = ext4_getfsmap_fill(meta_list, fsb, 1, EXT4_FMR_OWN_FS);
if (error)
return error;
fsb++;
}
len = ext4_bg_num_gdb(sb, agno);
if (!len)
return 0;
error = ext4_getfsmap_fill(meta_list, fsb, len,
EXT4_FMR_OWN_GDT);
if (error)
return error;
fsb += len;
if (!ext4_has_feature_meta_bg(sb) || metagroup < first_meta_bg) {
len = le16_to_cpu(sbi->s_es->s_reserved_gdt_blocks);
error = ext4_getfsmap_fill(meta_list, fsb, len,
EXT4_FMR_OWN_RESV_GDT);
if (error)
return error;
}
return 0;
}
static int ext4_getfsmap_compare(void *priv,
struct list_head *a,
struct list_head *b)
{
struct ext4_fsmap *fa;
struct ext4_fsmap *fb;
fa = container_of(a, struct ext4_fsmap, fmr_list);
fb = container_of(b, struct ext4_fsmap, fmr_list);
if (fa->fmr_physical < fb->fmr_physical)
return -1;
else if (fa->fmr_physical > fb->fmr_physical)
return 1;
return 0;
}
static void ext4_getfsmap_merge_fixed_metadata(struct list_head *meta_list)
{
struct ext4_fsmap *p;
struct ext4_fsmap *prev = NULL;
struct ext4_fsmap *tmp;
list_for_each_entry_safe(p, tmp, meta_list, fmr_list) {
if (!prev) {
prev = p;
continue;
}
if (prev->fmr_owner == p->fmr_owner &&
prev->fmr_physical + prev->fmr_length == p->fmr_physical) {
prev->fmr_length += p->fmr_length;
list_del(&p->fmr_list);
kfree(p);
} else
prev = p;
}
}
static void ext4_getfsmap_free_fixed_metadata(struct list_head *meta_list)
{
struct ext4_fsmap *p;
struct ext4_fsmap *tmp;
list_for_each_entry_safe(p, tmp, meta_list, fmr_list) {
list_del(&p->fmr_list);
kfree(p);
}
}
int ext4_getfsmap_find_fixed_metadata(struct super_block *sb,
struct list_head *meta_list)
{
struct ext4_group_desc *gdp;
ext4_group_t agno;
int error;
INIT_LIST_HEAD(meta_list);
for (agno = 0; agno < EXT4_SB(sb)->s_groups_count; agno++) {
gdp = ext4_get_group_desc(sb, agno, NULL);
if (!gdp) {
error = -EFSCORRUPTED;
goto err;
}
error = ext4_getfsmap_find_sb(sb, agno, meta_list);
if (error)
goto err;
error = ext4_getfsmap_fill(meta_list,
ext4_block_bitmap(sb, gdp), 1,
EXT4_FMR_OWN_BLKBM);
if (error)
goto err;
error = ext4_getfsmap_fill(meta_list,
ext4_inode_bitmap(sb, gdp), 1,
EXT4_FMR_OWN_INOBM);
if (error)
goto err;
error = ext4_getfsmap_fill(meta_list,
ext4_inode_table(sb, gdp),
EXT4_SB(sb)->s_itb_per_group,
EXT4_FMR_OWN_INODES);
if (error)
goto err;
}
list_sort(NULL, meta_list, ext4_getfsmap_compare);
ext4_getfsmap_merge_fixed_metadata(meta_list);
return 0;
err:
ext4_getfsmap_free_fixed_metadata(meta_list);
return error;
}
static int ext4_getfsmap_datadev(struct super_block *sb,
struct ext4_fsmap *keys,
struct ext4_getfsmap_info *info)
{
struct ext4_sb_info *sbi = EXT4_SB(sb);
ext4_fsblk_t start_fsb;
ext4_fsblk_t end_fsb;
ext4_fsblk_t bofs;
ext4_fsblk_t eofs;
ext4_group_t start_ag;
ext4_group_t end_ag;
ext4_grpblk_t first_cluster;
ext4_grpblk_t last_cluster;
int error = 0;
bofs = le32_to_cpu(sbi->s_es->s_first_data_block);
eofs = ext4_blocks_count(sbi->s_es);
if (keys[0].fmr_physical >= eofs)
return 0;
else if (keys[0].fmr_physical < bofs)
keys[0].fmr_physical = bofs;
if (keys[1].fmr_physical >= eofs)
keys[1].fmr_physical = eofs - 1;
start_fsb = keys[0].fmr_physical;
end_fsb = keys[1].fmr_physical;
ext4_get_group_no_and_offset(sb, start_fsb, &start_ag, &first_cluster);
ext4_get_group_no_and_offset(sb, end_fsb, &end_ag, &last_cluster);
info->gfi_low = keys[0];
info->gfi_low.fmr_physical = EXT4_C2B(sbi, first_cluster);
info->gfi_low.fmr_length = 0;
memset(&info->gfi_high, 0xFF, sizeof(info->gfi_high));
error = ext4_getfsmap_find_fixed_metadata(sb, &info->gfi_meta_list);
if (error)
goto err;
for (info->gfi_agno = start_ag;
info->gfi_agno <= end_ag;
info->gfi_agno++) {
if (info->gfi_agno == end_ag) {
info->gfi_high = keys[1];
info->gfi_high.fmr_physical = EXT4_C2B(sbi,
last_cluster);
info->gfi_high.fmr_length = 0;
}
trace_ext4_fsmap_low_key(sb, info->gfi_dev, info->gfi_agno,
info->gfi_low.fmr_physical,
info->gfi_low.fmr_length,
info->gfi_low.fmr_owner);
trace_ext4_fsmap_high_key(sb, info->gfi_dev, info->gfi_agno,
info->gfi_high.fmr_physical,
info->gfi_high.fmr_length,
info->gfi_high.fmr_owner);
error = ext4_mballoc_query_range(sb, info->gfi_agno,
EXT4_B2C(sbi, info->gfi_low.fmr_physical),
EXT4_B2C(sbi, info->gfi_high.fmr_physical),
ext4_getfsmap_datadev_helper, info);
if (error)
goto err;
if (info->gfi_agno == start_ag)
memset(&info->gfi_low, 0, sizeof(info->gfi_low));
}
if (info->gfi_lastfree.fmr_owner) {
error = ext4_getfsmap_helper(sb, info, &info->gfi_lastfree);
if (error)
goto err;
}
info->gfi_last = true;
error = ext4_getfsmap_datadev_helper(sb, end_ag, last_cluster, 0, info);
if (error)
goto err;
err:
ext4_getfsmap_free_fixed_metadata(&info->gfi_meta_list);
return error;
}
static bool ext4_getfsmap_is_valid_device(struct super_block *sb,
struct ext4_fsmap *fm)
{
if (fm->fmr_device == 0 || fm->fmr_device == UINT_MAX ||
fm->fmr_device == new_encode_dev(sb->s_bdev->bd_dev))
return true;
if (EXT4_SB(sb)->journal_bdev &&
fm->fmr_device == new_encode_dev(EXT4_SB(sb)->journal_bdev->bd_dev))
return true;
return false;
}
static bool ext4_getfsmap_check_keys(struct ext4_fsmap *low_key,
struct ext4_fsmap *high_key)
{
if (low_key->fmr_device > high_key->fmr_device)
return false;
if (low_key->fmr_device < high_key->fmr_device)
return true;
if (low_key->fmr_physical > high_key->fmr_physical)
return false;
if (low_key->fmr_physical < high_key->fmr_physical)
return true;
if (low_key->fmr_owner > high_key->fmr_owner)
return false;
if (low_key->fmr_owner < high_key->fmr_owner)
return true;
return false;
}
int ext4_getfsmap(struct super_block *sb, struct ext4_fsmap_head *head,
ext4_fsmap_format_t formatter, void *arg)
{
struct ext4_fsmap dkeys[2];
struct ext4_getfsmap_dev handlers[EXT4_GETFSMAP_DEVS];
struct ext4_getfsmap_info info = {0};
int i;
int error = 0;
if (head->fmh_iflags & ~FMH_IF_VALID)
return -EINVAL;
if (!ext4_getfsmap_is_valid_device(sb, &head->fmh_keys[0]) ||
!ext4_getfsmap_is_valid_device(sb, &head->fmh_keys[1]))
return -EINVAL;
head->fmh_entries = 0;
memset(handlers, 0, sizeof(handlers));
handlers[0].gfd_dev = new_encode_dev(sb->s_bdev->bd_dev);
handlers[0].gfd_fn = ext4_getfsmap_datadev;
if (EXT4_SB(sb)->journal_bdev) {
handlers[1].gfd_dev = new_encode_dev(
EXT4_SB(sb)->journal_bdev->bd_dev);
handlers[1].gfd_fn = ext4_getfsmap_logdev;
}
sort(handlers, EXT4_GETFSMAP_DEVS, sizeof(struct ext4_getfsmap_dev),
ext4_getfsmap_dev_compare, NULL);
dkeys[0] = head->fmh_keys[0];
dkeys[0].fmr_physical += dkeys[0].fmr_length;
dkeys[0].fmr_owner = 0;
dkeys[0].fmr_length = 0;
memset(&dkeys[1], 0xFF, sizeof(struct ext4_fsmap));
if (!ext4_getfsmap_check_keys(dkeys, &head->fmh_keys[1]))
return -EINVAL;
info.gfi_next_fsblk = head->fmh_keys[0].fmr_physical +
head->fmh_keys[0].fmr_length;
info.gfi_formatter = formatter;
info.gfi_format_arg = arg;
info.gfi_head = head;
for (i = 0; i < EXT4_GETFSMAP_DEVS; i++) {
if (!handlers[i].gfd_fn)
continue;
if (head->fmh_keys[0].fmr_device > handlers[i].gfd_dev)
continue;
if (head->fmh_keys[1].fmr_device < handlers[i].gfd_dev)
break;
if (handlers[i].gfd_dev == head->fmh_keys[1].fmr_device)
dkeys[1] = head->fmh_keys[1];
if (handlers[i].gfd_dev > head->fmh_keys[0].fmr_device)
memset(&dkeys[0], 0, sizeof(struct ext4_fsmap));
info.gfi_dev = handlers[i].gfd_dev;
info.gfi_last = false;
info.gfi_agno = -1;
error = handlers[i].gfd_fn(sb, dkeys, &info);
if (error)
break;
info.gfi_next_fsblk = 0;
}
head->fmh_oflags = FMH_OF_DEV_T;
return error;
}
