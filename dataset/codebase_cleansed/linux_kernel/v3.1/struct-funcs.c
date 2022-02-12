void btrfs_node_key(struct extent_buffer *eb,
struct btrfs_disk_key *disk_key, int nr)
{
unsigned long ptr = btrfs_node_key_ptr_offset(nr);
read_eb_member(eb, (struct btrfs_key_ptr *)ptr,
struct btrfs_key_ptr, key, disk_key);
}
