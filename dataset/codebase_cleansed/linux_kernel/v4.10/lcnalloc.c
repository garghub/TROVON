int ntfs_cluster_free_from_rl_nolock(ntfs_volume *vol,
const runlist_element *rl)
{
struct inode *lcnbmp_vi = vol->lcnbmp_ino;
int ret = 0;
ntfs_debug("Entering.");
if (!rl)
return 0;
for (; rl->length; rl++) {
int err;
if (rl->lcn < 0)
continue;
err = ntfs_bitmap_clear_run(lcnbmp_vi, rl->lcn, rl->length);
if (unlikely(err && (!ret || ret == -ENOMEM) && ret != err))
ret = err;
}
ntfs_debug("Done.");
return ret;
}
runlist_element *ntfs_cluster_alloc(ntfs_volume *vol, const VCN start_vcn,
const s64 count, const LCN start_lcn,
const NTFS_CLUSTER_ALLOCATION_ZONES zone,
const bool is_extension)
{
LCN zone_start, zone_end, bmp_pos, bmp_initial_pos, last_read_pos, lcn;
LCN prev_lcn = 0, prev_run_len = 0, mft_zone_size;
s64 clusters;
loff_t i_size;
struct inode *lcnbmp_vi;
runlist_element *rl = NULL;
struct address_space *mapping;
struct page *page = NULL;
u8 *buf, *byte;
int err = 0, rlpos, rlsize, buf_size;
u8 pass, done_zones, search_zone, need_writeback = 0, bit;
ntfs_debug("Entering for start_vcn 0x%llx, count 0x%llx, start_lcn "
"0x%llx, zone %s_ZONE.", (unsigned long long)start_vcn,
(unsigned long long)count,
(unsigned long long)start_lcn,
zone == MFT_ZONE ? "MFT" : "DATA");
BUG_ON(!vol);
lcnbmp_vi = vol->lcnbmp_ino;
BUG_ON(!lcnbmp_vi);
BUG_ON(start_vcn < 0);
BUG_ON(count < 0);
BUG_ON(start_lcn < -1);
BUG_ON(zone < FIRST_ZONE);
BUG_ON(zone > LAST_ZONE);
if (!count)
return NULL;
down_write(&vol->lcnbmp_lock);
done_zones = 0;
pass = 1;
zone_start = start_lcn;
if (zone_start < 0) {
if (zone == DATA_ZONE)
zone_start = vol->data1_zone_pos;
else
zone_start = vol->mft_zone_pos;
if (!zone_start) {
pass = 2;
}
} else if (zone == DATA_ZONE && zone_start >= vol->mft_zone_start &&
zone_start < vol->mft_zone_end) {
zone_start = vol->mft_zone_end;
pass = 2;
} else if (zone == MFT_ZONE && (zone_start < vol->mft_zone_start ||
zone_start >= vol->mft_zone_end)) {
zone_start = vol->mft_lcn;
if (!vol->mft_zone_end)
zone_start = 0;
pass = 2;
}
if (zone == MFT_ZONE) {
zone_end = vol->mft_zone_end;
search_zone = 1;
} else {
done_zones |= 1;
if (zone_start >= vol->mft_zone_end) {
zone_end = vol->nr_clusters;
search_zone = 2;
} else {
zone_end = vol->mft_zone_start;
search_zone = 4;
}
}
bmp_pos = bmp_initial_pos = zone_start;
clusters = count;
rlpos = rlsize = 0;
mapping = lcnbmp_vi->i_mapping;
i_size = i_size_read(lcnbmp_vi);
while (1) {
ntfs_debug("Start of outer while loop: done_zones 0x%x, "
"search_zone %i, pass %i, zone_start 0x%llx, "
"zone_end 0x%llx, bmp_initial_pos 0x%llx, "
"bmp_pos 0x%llx, rlpos %i, rlsize %i.",
done_zones, search_zone, pass,
(unsigned long long)zone_start,
(unsigned long long)zone_end,
(unsigned long long)bmp_initial_pos,
(unsigned long long)bmp_pos, rlpos, rlsize);
last_read_pos = bmp_pos >> 3;
ntfs_debug("last_read_pos 0x%llx.",
(unsigned long long)last_read_pos);
if (last_read_pos > i_size) {
ntfs_debug("End of attribute reached. "
"Skipping to zone_pass_done.");
goto zone_pass_done;
}
if (likely(page)) {
if (need_writeback) {
ntfs_debug("Marking page dirty.");
flush_dcache_page(page);
set_page_dirty(page);
need_writeback = 0;
}
ntfs_unmap_page(page);
}
page = ntfs_map_page(mapping, last_read_pos >>
PAGE_SHIFT);
if (IS_ERR(page)) {
err = PTR_ERR(page);
ntfs_error(vol->sb, "Failed to map page.");
goto out;
}
buf_size = last_read_pos & ~PAGE_MASK;
buf = page_address(page) + buf_size;
buf_size = PAGE_SIZE - buf_size;
if (unlikely(last_read_pos + buf_size > i_size))
buf_size = i_size - last_read_pos;
buf_size <<= 3;
lcn = bmp_pos & 7;
bmp_pos &= ~(LCN)7;
ntfs_debug("Before inner while loop: buf_size %i, lcn 0x%llx, "
"bmp_pos 0x%llx, need_writeback %i.", buf_size,
(unsigned long long)lcn,
(unsigned long long)bmp_pos, need_writeback);
while (lcn < buf_size && lcn + bmp_pos < zone_end) {
byte = buf + (lcn >> 3);
ntfs_debug("In inner while loop: buf_size %i, "
"lcn 0x%llx, bmp_pos 0x%llx, "
"need_writeback %i, byte ofs 0x%x, "
"*byte 0x%x.", buf_size,
(unsigned long long)lcn,
(unsigned long long)bmp_pos,
need_writeback,
(unsigned int)(lcn >> 3),
(unsigned int)*byte);
if (*byte == 0xff) {
lcn = (lcn + 8) & ~(LCN)7;
ntfs_debug("Continuing while loop 1.");
continue;
}
bit = 1 << (lcn & 7);
ntfs_debug("bit 0x%x.", bit);
if (*byte & bit) {
lcn++;
ntfs_debug("Continuing while loop 2.");
continue;
}
if ((rlpos + 2) * sizeof(*rl) > rlsize) {
runlist_element *rl2;
ntfs_debug("Reallocating memory.");
if (!rl)
ntfs_debug("First free bit is at LCN "
"0x%llx.",
(unsigned long long)
(lcn + bmp_pos));
rl2 = ntfs_malloc_nofs(rlsize + (int)PAGE_SIZE);
if (unlikely(!rl2)) {
err = -ENOMEM;
ntfs_error(vol->sb, "Failed to "
"allocate memory.");
goto out;
}
memcpy(rl2, rl, rlsize);
ntfs_free(rl);
rl = rl2;
rlsize += PAGE_SIZE;
ntfs_debug("Reallocated memory, rlsize 0x%x.",
rlsize);
}
*byte |= bit;
need_writeback = 1;
ntfs_debug("*byte 0x%x, need_writeback is set.",
(unsigned int)*byte);
ntfs_debug("Adding run (lcn 0x%llx, len 0x%llx), "
"prev_lcn 0x%llx, lcn 0x%llx, "
"bmp_pos 0x%llx, prev_run_len 0x%llx, "
"rlpos %i.",
(unsigned long long)(lcn + bmp_pos),
1ULL, (unsigned long long)prev_lcn,
(unsigned long long)lcn,
(unsigned long long)bmp_pos,
(unsigned long long)prev_run_len,
rlpos);
if (prev_lcn == lcn + bmp_pos - prev_run_len && rlpos) {
ntfs_debug("Coalescing to run (lcn 0x%llx, "
"len 0x%llx).",
(unsigned long long)
rl[rlpos - 1].lcn,
(unsigned long long)
rl[rlpos - 1].length);
rl[rlpos - 1].length = ++prev_run_len;
ntfs_debug("Run now (lcn 0x%llx, len 0x%llx), "
"prev_run_len 0x%llx.",
(unsigned long long)
rl[rlpos - 1].lcn,
(unsigned long long)
rl[rlpos - 1].length,
(unsigned long long)
prev_run_len);
} else {
if (likely(rlpos)) {
ntfs_debug("Adding new run, (previous "
"run lcn 0x%llx, "
"len 0x%llx).",
(unsigned long long)
rl[rlpos - 1].lcn,
(unsigned long long)
rl[rlpos - 1].length);
rl[rlpos].vcn = rl[rlpos - 1].vcn +
prev_run_len;
} else {
ntfs_debug("Adding new run, is first "
"run.");
rl[rlpos].vcn = start_vcn;
}
rl[rlpos].lcn = prev_lcn = lcn + bmp_pos;
rl[rlpos].length = prev_run_len = 1;
rlpos++;
}
if (!--clusters) {
LCN tc;
tc = lcn + bmp_pos + 1;
ntfs_debug("Done. Updating current zone "
"position, tc 0x%llx, "
"search_zone %i.",
(unsigned long long)tc,
search_zone);
switch (search_zone) {
case 1:
ntfs_debug("Before checks, "
"vol->mft_zone_pos "
"0x%llx.",
(unsigned long long)
vol->mft_zone_pos);
if (tc >= vol->mft_zone_end) {
vol->mft_zone_pos =
vol->mft_lcn;
if (!vol->mft_zone_end)
vol->mft_zone_pos = 0;
} else if ((bmp_initial_pos >=
vol->mft_zone_pos ||
tc > vol->mft_zone_pos)
&& tc >= vol->mft_lcn)
vol->mft_zone_pos = tc;
ntfs_debug("After checks, "
"vol->mft_zone_pos "
"0x%llx.",
(unsigned long long)
vol->mft_zone_pos);
break;
case 2:
ntfs_debug("Before checks, "
"vol->data1_zone_pos "
"0x%llx.",
(unsigned long long)
vol->data1_zone_pos);
if (tc >= vol->nr_clusters)
vol->data1_zone_pos =
vol->mft_zone_end;
else if ((bmp_initial_pos >=
vol->data1_zone_pos ||
tc > vol->data1_zone_pos)
&& tc >= vol->mft_zone_end)
vol->data1_zone_pos = tc;
ntfs_debug("After checks, "
"vol->data1_zone_pos "
"0x%llx.",
(unsigned long long)
vol->data1_zone_pos);
break;
case 4:
ntfs_debug("Before checks, "
"vol->data2_zone_pos "
"0x%llx.",
(unsigned long long)
vol->data2_zone_pos);
if (tc >= vol->mft_zone_start)
vol->data2_zone_pos = 0;
else if (bmp_initial_pos >=
vol->data2_zone_pos ||
tc > vol->data2_zone_pos)
vol->data2_zone_pos = tc;
ntfs_debug("After checks, "
"vol->data2_zone_pos "
"0x%llx.",
(unsigned long long)
vol->data2_zone_pos);
break;
default:
BUG();
}
ntfs_debug("Finished. Going to out.");
goto out;
}
lcn++;
}
bmp_pos += buf_size;
ntfs_debug("After inner while loop: buf_size 0x%x, lcn "
"0x%llx, bmp_pos 0x%llx, need_writeback %i.",
buf_size, (unsigned long long)lcn,
(unsigned long long)bmp_pos, need_writeback);
if (bmp_pos < zone_end) {
ntfs_debug("Continuing outer while loop, "
"bmp_pos 0x%llx, zone_end 0x%llx.",
(unsigned long long)bmp_pos,
(unsigned long long)zone_end);
continue;
}
zone_pass_done:
ntfs_debug("At zone_pass_done, pass %i.", pass);
if (pass == 1) {
pass = 2;
zone_end = zone_start;
switch (search_zone) {
case 1:
zone_start = vol->mft_zone_start;
break;
case 2:
zone_start = vol->mft_zone_end;
break;
case 4:
zone_start = 0;
break;
default:
BUG();
}
if (zone_end < zone_start)
zone_end = zone_start;
bmp_pos = zone_start;
ntfs_debug("Continuing outer while loop, pass 2, "
"zone_start 0x%llx, zone_end 0x%llx, "
"bmp_pos 0x%llx.",
(unsigned long long)zone_start,
(unsigned long long)zone_end,
(unsigned long long)bmp_pos);
continue;
}
done_zones_check:
ntfs_debug("At done_zones_check, search_zone %i, done_zones "
"before 0x%x, done_zones after 0x%x.",
search_zone, done_zones,
done_zones | search_zone);
done_zones |= search_zone;
if (done_zones < 7) {
ntfs_debug("Switching zone.");
pass = 1;
switch (search_zone) {
case 1:
ntfs_debug("Switching from mft zone to data1 "
"zone.");
if (rlpos) {
LCN tc;
ntfs_debug("Before checks, "
"vol->mft_zone_pos "
"0x%llx.",
(unsigned long long)
vol->mft_zone_pos);
tc = rl[rlpos - 1].lcn +
rl[rlpos - 1].length;
if (tc >= vol->mft_zone_end) {
vol->mft_zone_pos =
vol->mft_lcn;
if (!vol->mft_zone_end)
vol->mft_zone_pos = 0;
} else if ((bmp_initial_pos >=
vol->mft_zone_pos ||
tc > vol->mft_zone_pos)
&& tc >= vol->mft_lcn)
vol->mft_zone_pos = tc;
ntfs_debug("After checks, "
"vol->mft_zone_pos "
"0x%llx.",
(unsigned long long)
vol->mft_zone_pos);
}
switch_to_data1_zone: search_zone = 2;
zone_start = bmp_initial_pos =
vol->data1_zone_pos;
zone_end = vol->nr_clusters;
if (zone_start == vol->mft_zone_end)
pass = 2;
if (zone_start >= zone_end) {
vol->data1_zone_pos = zone_start =
vol->mft_zone_end;
pass = 2;
}
break;
case 2:
ntfs_debug("Switching from data1 zone to "
"data2 zone.");
if (rlpos) {
LCN tc;
ntfs_debug("Before checks, "
"vol->data1_zone_pos "
"0x%llx.",
(unsigned long long)
vol->data1_zone_pos);
tc = rl[rlpos - 1].lcn +
rl[rlpos - 1].length;
if (tc >= vol->nr_clusters)
vol->data1_zone_pos =
vol->mft_zone_end;
else if ((bmp_initial_pos >=
vol->data1_zone_pos ||
tc > vol->data1_zone_pos)
&& tc >= vol->mft_zone_end)
vol->data1_zone_pos = tc;
ntfs_debug("After checks, "
"vol->data1_zone_pos "
"0x%llx.",
(unsigned long long)
vol->data1_zone_pos);
}
search_zone = 4;
zone_start = bmp_initial_pos =
vol->data2_zone_pos;
zone_end = vol->mft_zone_start;
if (!zone_start)
pass = 2;
if (zone_start >= zone_end) {
vol->data2_zone_pos = zone_start =
bmp_initial_pos = 0;
pass = 2;
}
break;
case 4:
ntfs_debug("Switching from data2 zone to "
"data1 zone.");
if (rlpos) {
LCN tc;
ntfs_debug("Before checks, "
"vol->data2_zone_pos "
"0x%llx.",
(unsigned long long)
vol->data2_zone_pos);
tc = rl[rlpos - 1].lcn +
rl[rlpos - 1].length;
if (tc >= vol->mft_zone_start)
vol->data2_zone_pos = 0;
else if (bmp_initial_pos >=
vol->data2_zone_pos ||
tc > vol->data2_zone_pos)
vol->data2_zone_pos = tc;
ntfs_debug("After checks, "
"vol->data2_zone_pos "
"0x%llx.",
(unsigned long long)
vol->data2_zone_pos);
}
goto switch_to_data1_zone;
default:
BUG();
}
ntfs_debug("After zone switch, search_zone %i, "
"pass %i, bmp_initial_pos 0x%llx, "
"zone_start 0x%llx, zone_end 0x%llx.",
search_zone, pass,
(unsigned long long)bmp_initial_pos,
(unsigned long long)zone_start,
(unsigned long long)zone_end);
bmp_pos = zone_start;
if (zone_start == zone_end) {
ntfs_debug("Empty zone, going to "
"done_zones_check.");
goto done_zones_check;
}
ntfs_debug("Continuing outer while loop.");
continue;
}
ntfs_debug("All zones are finished.");
mft_zone_size = vol->mft_zone_end - vol->mft_zone_start;
ntfs_debug("vol->mft_zone_start 0x%llx, vol->mft_zone_end "
"0x%llx, mft_zone_size 0x%llx.",
(unsigned long long)vol->mft_zone_start,
(unsigned long long)vol->mft_zone_end,
(unsigned long long)mft_zone_size);
if (zone == MFT_ZONE || mft_zone_size <= 0) {
ntfs_debug("No free clusters left, going to out.");
err = -ENOSPC;
goto out;
}
ntfs_debug("Shrinking mft zone.");
zone_end = vol->mft_zone_end;
mft_zone_size >>= 1;
if (mft_zone_size > 0)
vol->mft_zone_end = vol->mft_zone_start + mft_zone_size;
else
vol->data2_zone_pos = vol->mft_zone_start =
vol->mft_zone_end = 0;
if (vol->mft_zone_pos >= vol->mft_zone_end) {
vol->mft_zone_pos = vol->mft_lcn;
if (!vol->mft_zone_end)
vol->mft_zone_pos = 0;
}
bmp_pos = zone_start = bmp_initial_pos =
vol->data1_zone_pos = vol->mft_zone_end;
search_zone = 2;
pass = 2;
done_zones &= ~2;
ntfs_debug("After shrinking mft zone, mft_zone_size 0x%llx, "
"vol->mft_zone_start 0x%llx, "
"vol->mft_zone_end 0x%llx, "
"vol->mft_zone_pos 0x%llx, search_zone 2, "
"pass 2, dones_zones 0x%x, zone_start 0x%llx, "
"zone_end 0x%llx, vol->data1_zone_pos 0x%llx, "
"continuing outer while loop.",
(unsigned long long)mft_zone_size,
(unsigned long long)vol->mft_zone_start,
(unsigned long long)vol->mft_zone_end,
(unsigned long long)vol->mft_zone_pos,
done_zones, (unsigned long long)zone_start,
(unsigned long long)zone_end,
(unsigned long long)vol->data1_zone_pos);
}
ntfs_debug("After outer while loop.");
out:
ntfs_debug("At out.");
if (likely(rl)) {
rl[rlpos].vcn = rl[rlpos - 1].vcn + rl[rlpos - 1].length;
rl[rlpos].lcn = is_extension ? LCN_ENOENT : LCN_RL_NOT_MAPPED;
rl[rlpos].length = 0;
}
if (likely(page && !IS_ERR(page))) {
if (need_writeback) {
ntfs_debug("Marking page dirty.");
flush_dcache_page(page);
set_page_dirty(page);
need_writeback = 0;
}
ntfs_unmap_page(page);
}
if (likely(!err)) {
up_write(&vol->lcnbmp_lock);
ntfs_debug("Done.");
return rl;
}
ntfs_error(vol->sb, "Failed to allocate clusters, aborting "
"(error %i).", err);
if (rl) {
int err2;
if (err == -ENOSPC)
ntfs_debug("Not enough space to complete allocation, "
"err -ENOSPC, first free lcn 0x%llx, "
"could allocate up to 0x%llx "
"clusters.",
(unsigned long long)rl[0].lcn,
(unsigned long long)(count - clusters));
ntfs_debug("Attempting rollback...");
err2 = ntfs_cluster_free_from_rl_nolock(vol, rl);
if (err2) {
ntfs_error(vol->sb, "Failed to rollback (error %i). "
"Leaving inconsistent metadata! "
"Unmount and run chkdsk.", err2);
NVolSetErrors(vol);
}
ntfs_free(rl);
} else if (err == -ENOSPC)
ntfs_debug("No space left at all, err = -ENOSPC, first free "
"lcn = 0x%llx.",
(long long)vol->data1_zone_pos);
up_write(&vol->lcnbmp_lock);
return ERR_PTR(err);
}
s64 __ntfs_cluster_free(ntfs_inode *ni, const VCN start_vcn, s64 count,
ntfs_attr_search_ctx *ctx, const bool is_rollback)
{
s64 delta, to_free, total_freed, real_freed;
ntfs_volume *vol;
struct inode *lcnbmp_vi;
runlist_element *rl;
int err;
BUG_ON(!ni);
ntfs_debug("Entering for i_ino 0x%lx, start_vcn 0x%llx, count "
"0x%llx.%s", ni->mft_no, (unsigned long long)start_vcn,
(unsigned long long)count,
is_rollback ? " (rollback)" : "");
vol = ni->vol;
lcnbmp_vi = vol->lcnbmp_ino;
BUG_ON(!lcnbmp_vi);
BUG_ON(start_vcn < 0);
BUG_ON(count < -1);
if (likely(!is_rollback))
down_write(&vol->lcnbmp_lock);
total_freed = real_freed = 0;
rl = ntfs_attr_find_vcn_nolock(ni, start_vcn, ctx);
if (IS_ERR(rl)) {
if (!is_rollback)
ntfs_error(vol->sb, "Failed to find first runlist "
"element (error %li), aborting.",
PTR_ERR(rl));
err = PTR_ERR(rl);
goto err_out;
}
if (unlikely(rl->lcn < LCN_HOLE)) {
if (!is_rollback)
ntfs_error(vol->sb, "First runlist element has "
"invalid lcn, aborting.");
err = -EIO;
goto err_out;
}
delta = start_vcn - rl->vcn;
to_free = rl->length - delta;
if (count >= 0 && to_free > count)
to_free = count;
if (likely(rl->lcn >= 0)) {
err = ntfs_bitmap_set_bits_in_run(lcnbmp_vi, rl->lcn + delta,
to_free, likely(!is_rollback) ? 0 : 1);
if (unlikely(err)) {
if (!is_rollback)
ntfs_error(vol->sb, "Failed to clear first run "
"(error %i), aborting.", err);
goto err_out;
}
real_freed = to_free;
};
++rl;
if (count >= 0)
count -= to_free;
total_freed = to_free;
for (; rl->length && count != 0; ++rl) {
if (unlikely(rl->lcn < LCN_HOLE)) {
VCN vcn;
vcn = rl->vcn;
rl = ntfs_attr_find_vcn_nolock(ni, vcn, ctx);
if (IS_ERR(rl)) {
err = PTR_ERR(rl);
if (!is_rollback)
ntfs_error(vol->sb, "Failed to map "
"runlist fragment or "
"failed to find "
"subsequent runlist "
"element.");
goto err_out;
}
if (unlikely(rl->lcn < LCN_HOLE)) {
if (!is_rollback)
ntfs_error(vol->sb, "Runlist element "
"has invalid lcn "
"(0x%llx).",
(unsigned long long)
rl->lcn);
err = -EIO;
goto err_out;
}
}
to_free = rl->length;
if (count >= 0 && to_free > count)
to_free = count;
if (likely(rl->lcn >= 0)) {
err = ntfs_bitmap_set_bits_in_run(lcnbmp_vi, rl->lcn,
to_free, likely(!is_rollback) ? 0 : 1);
if (unlikely(err)) {
if (!is_rollback)
ntfs_error(vol->sb, "Failed to clear "
"subsequent run.");
goto err_out;
}
real_freed += to_free;
}
if (count >= 0)
count -= to_free;
total_freed += to_free;
}
if (likely(!is_rollback))
up_write(&vol->lcnbmp_lock);
BUG_ON(count > 0);
ntfs_debug("Done.");
return real_freed;
err_out:
if (is_rollback)
return err;
if (!real_freed) {
up_write(&vol->lcnbmp_lock);
return err;
}
delta = __ntfs_cluster_free(ni, start_vcn, total_freed, ctx, true);
if (delta < 0) {
ntfs_error(vol->sb, "Failed to rollback (error %i). Leaving "
"inconsistent metadata! Unmount and run "
"chkdsk.", (int)delta);
NVolSetErrors(vol);
}
up_write(&vol->lcnbmp_lock);
ntfs_error(vol->sb, "Aborting (error %i).", err);
return err;
}
