bool ntfs_stamp_usnjrnl(ntfs_volume *vol)
{
ntfs_debug("Entering.");
if (likely(!NVolUsnJrnlStamped(vol))) {
sle64 stamp;
struct page *page;
USN_HEADER *uh;
page = ntfs_map_page(vol->usnjrnl_max_ino->i_mapping, 0);
if (IS_ERR(page)) {
ntfs_error(vol->sb, "Failed to read from "
"$UsnJrnl/$DATA/$Max attribute.");
return false;
}
uh = (USN_HEADER*)page_address(page);
stamp = get_current_ntfs_time();
ntfs_debug("Stamping transaction log ($UsnJrnl): old "
"journal_id 0x%llx, old lowest_valid_usn "
"0x%llx, new journal_id 0x%llx, new "
"lowest_valid_usn 0x%llx.",
(long long)sle64_to_cpu(uh->journal_id),
(long long)sle64_to_cpu(uh->lowest_valid_usn),
(long long)sle64_to_cpu(stamp),
i_size_read(vol->usnjrnl_j_ino));
uh->lowest_valid_usn =
cpu_to_sle64(i_size_read(vol->usnjrnl_j_ino));
uh->journal_id = stamp;
flush_dcache_page(page);
set_page_dirty(page);
ntfs_unmap_page(page);
NVolSetUsnJrnlStamped(vol);
}
ntfs_debug("Done.");
return true;
}
