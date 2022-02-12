int ubi_change_vtbl_record(struct ubi_device *ubi, int idx,
struct ubi_vtbl_record *vtbl_rec)
{
int i, err;
uint32_t crc;
struct ubi_volume *layout_vol;
ubi_assert(idx >= 0 && idx < ubi->vtbl_slots);
layout_vol = ubi->volumes[vol_id2idx(ubi, UBI_LAYOUT_VOLUME_ID)];
if (!vtbl_rec)
vtbl_rec = &empty_vtbl_record;
else {
crc = crc32(UBI_CRC32_INIT, vtbl_rec, UBI_VTBL_RECORD_SIZE_CRC);
vtbl_rec->crc = cpu_to_be32(crc);
}
memcpy(&ubi->vtbl[idx], vtbl_rec, sizeof(struct ubi_vtbl_record));
for (i = 0; i < UBI_LAYOUT_VOLUME_EBS; i++) {
err = ubi_eba_unmap_leb(ubi, layout_vol, i);
if (err)
return err;
err = ubi_eba_write_leb(ubi, layout_vol, i, ubi->vtbl, 0,
ubi->vtbl_size);
if (err)
return err;
}
self_vtbl_check(ubi);
return 0;
}
int ubi_vtbl_rename_volumes(struct ubi_device *ubi,
struct list_head *rename_list)
{
int i, err;
struct ubi_rename_entry *re;
struct ubi_volume *layout_vol;
list_for_each_entry(re, rename_list, list) {
uint32_t crc;
struct ubi_volume *vol = re->desc->vol;
struct ubi_vtbl_record *vtbl_rec = &ubi->vtbl[vol->vol_id];
if (re->remove) {
memcpy(vtbl_rec, &empty_vtbl_record,
sizeof(struct ubi_vtbl_record));
continue;
}
vtbl_rec->name_len = cpu_to_be16(re->new_name_len);
memcpy(vtbl_rec->name, re->new_name, re->new_name_len);
memset(vtbl_rec->name + re->new_name_len, 0,
UBI_VOL_NAME_MAX + 1 - re->new_name_len);
crc = crc32(UBI_CRC32_INIT, vtbl_rec,
UBI_VTBL_RECORD_SIZE_CRC);
vtbl_rec->crc = cpu_to_be32(crc);
}
layout_vol = ubi->volumes[vol_id2idx(ubi, UBI_LAYOUT_VOLUME_ID)];
for (i = 0; i < UBI_LAYOUT_VOLUME_EBS; i++) {
err = ubi_eba_unmap_leb(ubi, layout_vol, i);
if (err)
return err;
err = ubi_eba_write_leb(ubi, layout_vol, i, ubi->vtbl, 0,
ubi->vtbl_size);
if (err)
return err;
}
return 0;
}
static int vtbl_check(const struct ubi_device *ubi,
const struct ubi_vtbl_record *vtbl)
{
int i, n, reserved_pebs, alignment, data_pad, vol_type, name_len;
int upd_marker, err;
uint32_t crc;
const char *name;
for (i = 0; i < ubi->vtbl_slots; i++) {
cond_resched();
reserved_pebs = be32_to_cpu(vtbl[i].reserved_pebs);
alignment = be32_to_cpu(vtbl[i].alignment);
data_pad = be32_to_cpu(vtbl[i].data_pad);
upd_marker = vtbl[i].upd_marker;
vol_type = vtbl[i].vol_type;
name_len = be16_to_cpu(vtbl[i].name_len);
name = &vtbl[i].name[0];
crc = crc32(UBI_CRC32_INIT, &vtbl[i], UBI_VTBL_RECORD_SIZE_CRC);
if (be32_to_cpu(vtbl[i].crc) != crc) {
ubi_err("bad CRC at record %u: %#08x, not %#08x",
i, crc, be32_to_cpu(vtbl[i].crc));
ubi_dump_vtbl_record(&vtbl[i], i);
return 1;
}
if (reserved_pebs == 0) {
if (memcmp(&vtbl[i], &empty_vtbl_record,
UBI_VTBL_RECORD_SIZE)) {
err = 2;
goto bad;
}
continue;
}
if (reserved_pebs < 0 || alignment < 0 || data_pad < 0 ||
name_len < 0) {
err = 3;
goto bad;
}
if (alignment > ubi->leb_size || alignment == 0) {
err = 4;
goto bad;
}
n = alignment & (ubi->min_io_size - 1);
if (alignment != 1 && n) {
err = 5;
goto bad;
}
n = ubi->leb_size % alignment;
if (data_pad != n) {
ubi_err("bad data_pad, has to be %d", n);
err = 6;
goto bad;
}
if (vol_type != UBI_VID_DYNAMIC && vol_type != UBI_VID_STATIC) {
err = 7;
goto bad;
}
if (upd_marker != 0 && upd_marker != 1) {
err = 8;
goto bad;
}
if (reserved_pebs > ubi->good_peb_count) {
ubi_err("too large reserved_pebs %d, good PEBs %d",
reserved_pebs, ubi->good_peb_count);
err = 9;
goto bad;
}
if (name_len > UBI_VOL_NAME_MAX) {
err = 10;
goto bad;
}
if (name[0] == '\0') {
err = 11;
goto bad;
}
if (name_len != strnlen(name, name_len + 1)) {
err = 12;
goto bad;
}
}
for (i = 0; i < ubi->vtbl_slots - 1; i++) {
for (n = i + 1; n < ubi->vtbl_slots; n++) {
int len1 = be16_to_cpu(vtbl[i].name_len);
int len2 = be16_to_cpu(vtbl[n].name_len);
if (len1 > 0 && len1 == len2 &&
!strncmp(vtbl[i].name, vtbl[n].name, len1)) {
ubi_err("volumes %d and %d have the same name \"%s\"",
i, n, vtbl[i].name);
ubi_dump_vtbl_record(&vtbl[i], i);
ubi_dump_vtbl_record(&vtbl[n], n);
return -EINVAL;
}
}
}
return 0;
bad:
ubi_err("volume table check failed: record %d, error %d", i, err);
ubi_dump_vtbl_record(&vtbl[i], i);
return -EINVAL;
}
static int create_vtbl(struct ubi_device *ubi, struct ubi_attach_info *ai,
int copy, void *vtbl)
{
int err, tries = 0;
struct ubi_vid_hdr *vid_hdr;
struct ubi_ainf_peb *new_aeb;
dbg_gen("create volume table (copy #%d)", copy + 1);
vid_hdr = ubi_zalloc_vid_hdr(ubi, GFP_KERNEL);
if (!vid_hdr)
return -ENOMEM;
retry:
new_aeb = ubi_early_get_peb(ubi, ai);
if (IS_ERR(new_aeb)) {
err = PTR_ERR(new_aeb);
goto out_free;
}
vid_hdr->vol_type = UBI_LAYOUT_VOLUME_TYPE;
vid_hdr->vol_id = cpu_to_be32(UBI_LAYOUT_VOLUME_ID);
vid_hdr->compat = UBI_LAYOUT_VOLUME_COMPAT;
vid_hdr->data_size = vid_hdr->used_ebs =
vid_hdr->data_pad = cpu_to_be32(0);
vid_hdr->lnum = cpu_to_be32(copy);
vid_hdr->sqnum = cpu_to_be64(++ai->max_sqnum);
err = ubi_io_write_vid_hdr(ubi, new_aeb->pnum, vid_hdr);
if (err)
goto write_error;
err = ubi_io_write_data(ubi, vtbl, new_aeb->pnum, 0, ubi->vtbl_size);
if (err)
goto write_error;
err = ubi_add_to_av(ubi, ai, new_aeb->pnum, new_aeb->ec, vid_hdr, 0);
kmem_cache_free(ai->aeb_slab_cache, new_aeb);
ubi_free_vid_hdr(ubi, vid_hdr);
return err;
write_error:
if (err == -EIO && ++tries <= 5) {
list_add(&new_aeb->u.list, &ai->erase);
goto retry;
}
kmem_cache_free(ai->aeb_slab_cache, new_aeb);
out_free:
ubi_free_vid_hdr(ubi, vid_hdr);
return err;
}
static struct ubi_vtbl_record *process_lvol(struct ubi_device *ubi,
struct ubi_attach_info *ai,
struct ubi_ainf_volume *av)
{
int err;
struct rb_node *rb;
struct ubi_ainf_peb *aeb;
struct ubi_vtbl_record *leb[UBI_LAYOUT_VOLUME_EBS] = { NULL, NULL };
int leb_corrupted[UBI_LAYOUT_VOLUME_EBS] = {1, 1};
dbg_gen("check layout volume");
ubi_rb_for_each_entry(rb, aeb, &av->root, u.rb) {
leb[aeb->lnum] = vzalloc(ubi->vtbl_size);
if (!leb[aeb->lnum]) {
err = -ENOMEM;
goto out_free;
}
err = ubi_io_read_data(ubi, leb[aeb->lnum], aeb->pnum, 0,
ubi->vtbl_size);
if (err == UBI_IO_BITFLIPS || mtd_is_eccerr(err))
aeb->scrub = 1;
else if (err)
goto out_free;
}
err = -EINVAL;
if (leb[0]) {
leb_corrupted[0] = vtbl_check(ubi, leb[0]);
if (leb_corrupted[0] < 0)
goto out_free;
}
if (!leb_corrupted[0]) {
if (leb[1])
leb_corrupted[1] = memcmp(leb[0], leb[1],
ubi->vtbl_size);
if (leb_corrupted[1]) {
ubi_warn("volume table copy #2 is corrupted");
err = create_vtbl(ubi, ai, 1, leb[0]);
if (err)
goto out_free;
ubi_msg("volume table was restored");
}
vfree(leb[1]);
return leb[0];
} else {
if (leb[1]) {
leb_corrupted[1] = vtbl_check(ubi, leb[1]);
if (leb_corrupted[1] < 0)
goto out_free;
}
if (leb_corrupted[1]) {
ubi_err("both volume tables are corrupted");
goto out_free;
}
ubi_warn("volume table copy #1 is corrupted");
err = create_vtbl(ubi, ai, 0, leb[1]);
if (err)
goto out_free;
ubi_msg("volume table was restored");
vfree(leb[0]);
return leb[1];
}
out_free:
vfree(leb[0]);
vfree(leb[1]);
return ERR_PTR(err);
}
static struct ubi_vtbl_record *create_empty_lvol(struct ubi_device *ubi,
struct ubi_attach_info *ai)
{
int i;
struct ubi_vtbl_record *vtbl;
vtbl = vzalloc(ubi->vtbl_size);
if (!vtbl)
return ERR_PTR(-ENOMEM);
for (i = 0; i < ubi->vtbl_slots; i++)
memcpy(&vtbl[i], &empty_vtbl_record, UBI_VTBL_RECORD_SIZE);
for (i = 0; i < UBI_LAYOUT_VOLUME_EBS; i++) {
int err;
err = create_vtbl(ubi, ai, i, vtbl);
if (err) {
vfree(vtbl);
return ERR_PTR(err);
}
}
return vtbl;
}
static int init_volumes(struct ubi_device *ubi,
const struct ubi_attach_info *ai,
const struct ubi_vtbl_record *vtbl)
{
int i, reserved_pebs = 0;
struct ubi_ainf_volume *av;
struct ubi_volume *vol;
for (i = 0; i < ubi->vtbl_slots; i++) {
cond_resched();
if (be32_to_cpu(vtbl[i].reserved_pebs) == 0)
continue;
vol = kzalloc(sizeof(struct ubi_volume), GFP_KERNEL);
if (!vol)
return -ENOMEM;
vol->reserved_pebs = be32_to_cpu(vtbl[i].reserved_pebs);
vol->alignment = be32_to_cpu(vtbl[i].alignment);
vol->data_pad = be32_to_cpu(vtbl[i].data_pad);
vol->upd_marker = vtbl[i].upd_marker;
vol->vol_type = vtbl[i].vol_type == UBI_VID_DYNAMIC ?
UBI_DYNAMIC_VOLUME : UBI_STATIC_VOLUME;
vol->name_len = be16_to_cpu(vtbl[i].name_len);
vol->usable_leb_size = ubi->leb_size - vol->data_pad;
memcpy(vol->name, vtbl[i].name, vol->name_len);
vol->name[vol->name_len] = '\0';
vol->vol_id = i;
if (vtbl[i].flags & UBI_VTBL_AUTORESIZE_FLG) {
if (ubi->autoresize_vol_id != -1) {
ubi_err("more than one auto-resize volume (%d and %d)",
ubi->autoresize_vol_id, i);
kfree(vol);
return -EINVAL;
}
ubi->autoresize_vol_id = i;
}
ubi_assert(!ubi->volumes[i]);
ubi->volumes[i] = vol;
ubi->vol_count += 1;
vol->ubi = ubi;
reserved_pebs += vol->reserved_pebs;
if (vol->vol_type == UBI_DYNAMIC_VOLUME) {
vol->used_ebs = vol->reserved_pebs;
vol->last_eb_bytes = vol->usable_leb_size;
vol->used_bytes =
(long long)vol->used_ebs * vol->usable_leb_size;
continue;
}
av = ubi_find_av(ai, i);
if (!av) {
continue;
}
if (av->leb_count != av->used_ebs) {
ubi_warn("static volume %d misses %d LEBs - corrupted",
av->vol_id, av->used_ebs - av->leb_count);
vol->corrupted = 1;
continue;
}
vol->used_ebs = av->used_ebs;
vol->used_bytes =
(long long)(vol->used_ebs - 1) * vol->usable_leb_size;
vol->used_bytes += av->last_data_size;
vol->last_eb_bytes = av->last_data_size;
}
vol = kzalloc(sizeof(struct ubi_volume), GFP_KERNEL);
if (!vol)
return -ENOMEM;
vol->reserved_pebs = UBI_LAYOUT_VOLUME_EBS;
vol->alignment = UBI_LAYOUT_VOLUME_ALIGN;
vol->vol_type = UBI_DYNAMIC_VOLUME;
vol->name_len = sizeof(UBI_LAYOUT_VOLUME_NAME) - 1;
memcpy(vol->name, UBI_LAYOUT_VOLUME_NAME, vol->name_len + 1);
vol->usable_leb_size = ubi->leb_size;
vol->used_ebs = vol->reserved_pebs;
vol->last_eb_bytes = vol->reserved_pebs;
vol->used_bytes =
(long long)vol->used_ebs * (ubi->leb_size - vol->data_pad);
vol->vol_id = UBI_LAYOUT_VOLUME_ID;
vol->ref_count = 1;
ubi_assert(!ubi->volumes[i]);
ubi->volumes[vol_id2idx(ubi, vol->vol_id)] = vol;
reserved_pebs += vol->reserved_pebs;
ubi->vol_count += 1;
vol->ubi = ubi;
if (reserved_pebs > ubi->avail_pebs) {
ubi_err("not enough PEBs, required %d, available %d",
reserved_pebs, ubi->avail_pebs);
if (ubi->corr_peb_count)
ubi_err("%d PEBs are corrupted and not used",
ubi->corr_peb_count);
}
ubi->rsvd_pebs += reserved_pebs;
ubi->avail_pebs -= reserved_pebs;
return 0;
}
static int check_av(const struct ubi_volume *vol,
const struct ubi_ainf_volume *av)
{
int err;
if (av->highest_lnum >= vol->reserved_pebs) {
err = 1;
goto bad;
}
if (av->leb_count > vol->reserved_pebs) {
err = 2;
goto bad;
}
if (av->vol_type != vol->vol_type) {
err = 3;
goto bad;
}
if (av->used_ebs > vol->reserved_pebs) {
err = 4;
goto bad;
}
if (av->data_pad != vol->data_pad) {
err = 5;
goto bad;
}
return 0;
bad:
ubi_err("bad attaching information, error %d", err);
ubi_dump_av(av);
ubi_dump_vol_info(vol);
return -EINVAL;
}
static int check_attaching_info(const struct ubi_device *ubi,
struct ubi_attach_info *ai)
{
int err, i;
struct ubi_ainf_volume *av;
struct ubi_volume *vol;
if (ai->vols_found > UBI_INT_VOL_COUNT + ubi->vtbl_slots) {
ubi_err("found %d volumes while attaching, maximum is %d + %d",
ai->vols_found, UBI_INT_VOL_COUNT, ubi->vtbl_slots);
return -EINVAL;
}
if (ai->highest_vol_id >= ubi->vtbl_slots + UBI_INT_VOL_COUNT &&
ai->highest_vol_id < UBI_INTERNAL_VOL_START) {
ubi_err("too large volume ID %d found", ai->highest_vol_id);
return -EINVAL;
}
for (i = 0; i < ubi->vtbl_slots + UBI_INT_VOL_COUNT; i++) {
cond_resched();
av = ubi_find_av(ai, i);
vol = ubi->volumes[i];
if (!vol) {
if (av)
ubi_remove_av(ai, av);
continue;
}
if (vol->reserved_pebs == 0) {
ubi_assert(i < ubi->vtbl_slots);
if (!av)
continue;
ubi_msg("finish volume %d removal", av->vol_id);
ubi_remove_av(ai, av);
} else if (av) {
err = check_av(vol, av);
if (err)
return err;
}
}
return 0;
}
int ubi_read_volume_table(struct ubi_device *ubi, struct ubi_attach_info *ai)
{
int i, err;
struct ubi_ainf_volume *av;
empty_vtbl_record.crc = cpu_to_be32(0xf116c36b);
ubi->vtbl_slots = ubi->leb_size / UBI_VTBL_RECORD_SIZE;
if (ubi->vtbl_slots > UBI_MAX_VOLUMES)
ubi->vtbl_slots = UBI_MAX_VOLUMES;
ubi->vtbl_size = ubi->vtbl_slots * UBI_VTBL_RECORD_SIZE;
ubi->vtbl_size = ALIGN(ubi->vtbl_size, ubi->min_io_size);
av = ubi_find_av(ai, UBI_LAYOUT_VOLUME_ID);
if (!av) {
if (ai->is_empty) {
ubi->vtbl = create_empty_lvol(ubi, ai);
if (IS_ERR(ubi->vtbl))
return PTR_ERR(ubi->vtbl);
} else {
ubi_err("the layout volume was not found");
return -EINVAL;
}
} else {
if (av->leb_count > UBI_LAYOUT_VOLUME_EBS) {
ubi_err("too many LEBs (%d) in layout volume",
av->leb_count);
return -EINVAL;
}
ubi->vtbl = process_lvol(ubi, ai, av);
if (IS_ERR(ubi->vtbl))
return PTR_ERR(ubi->vtbl);
}
ubi->avail_pebs = ubi->good_peb_count - ubi->corr_peb_count;
err = init_volumes(ubi, ai, ubi->vtbl);
if (err)
goto out_free;
err = check_attaching_info(ubi, ai);
if (err)
goto out_free;
return 0;
out_free:
vfree(ubi->vtbl);
for (i = 0; i < ubi->vtbl_slots + UBI_INT_VOL_COUNT; i++) {
kfree(ubi->volumes[i]);
ubi->volumes[i] = NULL;
}
return err;
}
static void self_vtbl_check(const struct ubi_device *ubi)
{
if (!ubi->dbg->chk_gen)
return;
if (vtbl_check(ubi, ubi->vtbl)) {
ubi_err("self-check failed");
BUG();
}
}
