void btrfs_node_key(struct extent_buffer *eb,
struct btrfs_disk_key *disk_key, int nr)
{
unsigned long ptr = btrfs_node_key_ptr_offset(nr);
if (eb->map_token && ptr >= eb->map_start &&
ptr + sizeof(*disk_key) <= eb->map_start + eb->map_len) {
memcpy(disk_key, eb->kaddr + ptr - eb->map_start,
sizeof(*disk_key));
return;
} else if (eb->map_token) {
unmap_extent_buffer(eb, eb->map_token, KM_USER1);
eb->map_token = NULL;
}
read_eb_member(eb, (struct btrfs_key_ptr *)ptr,
struct btrfs_key_ptr, key, disk_key);
}
