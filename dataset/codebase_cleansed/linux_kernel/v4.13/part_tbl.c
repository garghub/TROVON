static int hfs_parse_old_pmap(struct super_block *sb, struct old_pmap *pm,
sector_t *part_start, sector_t *part_size)
{
struct hfsplus_sb_info *sbi = HFSPLUS_SB(sb);
int i;
for (i = 0; i < 42; i++) {
struct old_pmap_entry *p = &pm->pdEntry[i];
if (p->pdStart && p->pdSize &&
p->pdFSID == cpu_to_be32(0x54465331) &&
(sbi->part < 0 || sbi->part == i)) {
*part_start += be32_to_cpu(p->pdStart);
*part_size = be32_to_cpu(p->pdSize);
return 0;
}
}
return -ENOENT;
}
static int hfs_parse_new_pmap(struct super_block *sb, void *buf,
struct new_pmap *pm, sector_t *part_start, sector_t *part_size)
{
struct hfsplus_sb_info *sbi = HFSPLUS_SB(sb);
int size = be32_to_cpu(pm->pmMapBlkCnt);
int buf_size = hfsplus_min_io_size(sb);
int res;
int i = 0;
do {
if (!memcmp(pm->pmPartType, "Apple_HFS", 9) &&
(sbi->part < 0 || sbi->part == i)) {
*part_start += be32_to_cpu(pm->pmPyPartStart);
*part_size = be32_to_cpu(pm->pmPartBlkCnt);
return 0;
}
if (++i >= size)
return -ENOENT;
pm = (struct new_pmap *)((u8 *)pm + HFSPLUS_SECTOR_SIZE);
if ((u8 *)pm - (u8 *)buf >= buf_size) {
res = hfsplus_submit_bio(sb,
*part_start + HFS_PMAP_BLK + i,
buf, (void **)&pm, REQ_OP_READ,
0);
if (res)
return res;
}
} while (pm->pmSig == cpu_to_be16(HFS_NEW_PMAP_MAGIC));
return -ENOENT;
}
int hfs_part_find(struct super_block *sb,
sector_t *part_start, sector_t *part_size)
{
void *buf, *data;
int res;
buf = kmalloc(hfsplus_min_io_size(sb), GFP_KERNEL);
if (!buf)
return -ENOMEM;
res = hfsplus_submit_bio(sb, *part_start + HFS_PMAP_BLK,
buf, &data, REQ_OP_READ, 0);
if (res)
goto out;
switch (be16_to_cpu(*((__be16 *)data))) {
case HFS_OLD_PMAP_MAGIC:
res = hfs_parse_old_pmap(sb, data, part_start, part_size);
break;
case HFS_NEW_PMAP_MAGIC:
res = hfs_parse_new_pmap(sb, buf, data, part_start, part_size);
break;
default:
res = -ENOENT;
break;
}
out:
kfree(buf);
return res;
}
