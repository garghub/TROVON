static inline u8 get_unaligned_le8(const void *p)
{
return *(u8 *)p;
}
static inline void put_unaligned_le8(u8 val, void *p)
{
*(u8 *)p = val;
}
void btrfs_node_key(const struct extent_buffer *eb,
struct btrfs_disk_key *disk_key, int nr)
{
unsigned long ptr = btrfs_node_key_ptr_offset(nr);
read_eb_member(eb, (struct btrfs_key_ptr *)ptr,
struct btrfs_key_ptr, key, disk_key);
}
