int squashfs_frag_lookup(struct super_block *sb, unsigned int fragment,
u64 *fragment_block)
{
struct squashfs_sb_info *msblk = sb->s_fs_info;
int block = SQUASHFS_FRAGMENT_INDEX(fragment);
int offset = SQUASHFS_FRAGMENT_INDEX_OFFSET(fragment);
u64 start_block = le64_to_cpu(msblk->fragment_index[block]);
struct squashfs_fragment_entry fragment_entry;
int size;
size = squashfs_read_metadata(sb, &fragment_entry, &start_block,
&offset, sizeof(fragment_entry));
if (size < 0)
return size;
*fragment_block = le64_to_cpu(fragment_entry.start_block);
size = le32_to_cpu(fragment_entry.size);
return size;
}
__le64 *squashfs_read_fragment_index_table(struct super_block *sb,
u64 fragment_table_start, u64 next_table, unsigned int fragments)
{
unsigned int length = SQUASHFS_FRAGMENT_INDEX_BYTES(fragments);
__le64 *table;
if (fragment_table_start + length > next_table)
return ERR_PTR(-EINVAL);
table = squashfs_read_table(sb, fragment_table_start, length);
if (!IS_ERR(table) && le64_to_cpu(table[0]) >= fragment_table_start) {
kfree(table);
return ERR_PTR(-EINVAL);
}
return table;
}
