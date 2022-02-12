int post_read_mst_fixup(NTFS_RECORD *b, const u32 size)
{
u16 usa_ofs, usa_count, usn;
u16 *usa_pos, *data_pos;
usa_ofs = le16_to_cpu(b->usa_ofs);
usa_count = le16_to_cpu(b->usa_count) - 1;
if ( size & (NTFS_BLOCK_SIZE - 1) ||
usa_ofs & 1 ||
usa_ofs + (usa_count * 2) > size ||
(size >> NTFS_BLOCK_SIZE_BITS) != usa_count)
return 0;
usa_pos = (u16*)b + usa_ofs/sizeof(u16);
usn = *usa_pos;
data_pos = (u16*)b + NTFS_BLOCK_SIZE/sizeof(u16) - 1;
while (usa_count--) {
if (*data_pos != usn) {
b->magic = magic_BAAD;
return -EINVAL;
}
data_pos += NTFS_BLOCK_SIZE/sizeof(u16);
}
usa_count = le16_to_cpu(b->usa_count) - 1;
data_pos = (u16*)b + NTFS_BLOCK_SIZE/sizeof(u16) - 1;
while (usa_count--) {
*data_pos = *(++usa_pos);
data_pos += NTFS_BLOCK_SIZE/sizeof(u16);
}
return 0;
}
int pre_write_mst_fixup(NTFS_RECORD *b, const u32 size)
{
le16 *usa_pos, *data_pos;
u16 usa_ofs, usa_count, usn;
le16 le_usn;
if (!b || ntfs_is_baad_record(b->magic) ||
ntfs_is_hole_record(b->magic))
return -EINVAL;
usa_ofs = le16_to_cpu(b->usa_ofs);
usa_count = le16_to_cpu(b->usa_count) - 1;
if ( size & (NTFS_BLOCK_SIZE - 1) ||
usa_ofs & 1 ||
usa_ofs + (usa_count * 2) > size ||
(size >> NTFS_BLOCK_SIZE_BITS) != usa_count)
return -EINVAL;
usa_pos = (le16*)((u8*)b + usa_ofs);
usn = le16_to_cpup(usa_pos) + 1;
if (usn == 0xffff || !usn)
usn = 1;
le_usn = cpu_to_le16(usn);
*usa_pos = le_usn;
data_pos = (le16*)b + NTFS_BLOCK_SIZE/sizeof(le16) - 1;
while (usa_count--) {
*(++usa_pos) = *data_pos;
*data_pos = le_usn;
data_pos += NTFS_BLOCK_SIZE/sizeof(le16);
}
return 0;
}
void post_write_mst_fixup(NTFS_RECORD *b)
{
le16 *usa_pos, *data_pos;
u16 usa_ofs = le16_to_cpu(b->usa_ofs);
u16 usa_count = le16_to_cpu(b->usa_count) - 1;
usa_pos = (le16*)b + usa_ofs/sizeof(le16);
data_pos = (le16*)b + NTFS_BLOCK_SIZE/sizeof(le16) - 1;
while (usa_count--) {
*data_pos = *(++usa_pos);
data_pos += NTFS_BLOCK_SIZE/sizeof(le16);
}
}
