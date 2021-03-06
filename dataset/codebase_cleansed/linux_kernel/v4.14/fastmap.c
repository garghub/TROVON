static inline unsigned long *init_seen(struct ubi_device *ubi)
{
unsigned long *ret;
if (!ubi_dbg_chk_fastmap(ubi))
return NULL;
ret = kcalloc(BITS_TO_LONGS(ubi->peb_count), sizeof(unsigned long),
GFP_KERNEL);
if (!ret)
return ERR_PTR(-ENOMEM);
return ret;
}
static inline void free_seen(unsigned long *seen)
{
kfree(seen);
}
static inline void set_seen(struct ubi_device *ubi, int pnum, unsigned long *seen)
{
if (!ubi_dbg_chk_fastmap(ubi) || !seen)
return;
set_bit(pnum, seen);
}
static int self_check_seen(struct ubi_device *ubi, unsigned long *seen)
{
int pnum, ret = 0;
if (!ubi_dbg_chk_fastmap(ubi) || !seen)
return 0;
for (pnum = 0; pnum < ubi->peb_count; pnum++) {
if (test_bit(pnum, seen) && ubi->lookuptbl[pnum]) {
ubi_err(ubi, "self-check failed for PEB %d, fastmap didn't see it", pnum);
ret = -EINVAL;
}
}
return ret;
}
size_t ubi_calc_fm_size(struct ubi_device *ubi)
{
size_t size;
size = sizeof(struct ubi_fm_sb) +
sizeof(struct ubi_fm_hdr) +
sizeof(struct ubi_fm_scan_pool) +
sizeof(struct ubi_fm_scan_pool) +
(ubi->peb_count * sizeof(struct ubi_fm_ec)) +
(sizeof(struct ubi_fm_eba) +
(ubi->peb_count * sizeof(__be32))) +
sizeof(struct ubi_fm_volhdr) * UBI_MAX_VOLUMES;
return roundup(size, ubi->leb_size);
}
static struct ubi_vid_io_buf *new_fm_vbuf(struct ubi_device *ubi, int vol_id)
{
struct ubi_vid_io_buf *new;
struct ubi_vid_hdr *vh;
new = ubi_alloc_vid_buf(ubi, GFP_KERNEL);
if (!new)
goto out;
vh = ubi_get_vid_hdr(new);
vh->vol_type = UBI_VID_DYNAMIC;
vh->vol_id = cpu_to_be32(vol_id);
vh->compat = UBI_COMPAT_DELETE;
out:
return new;
}
static int add_aeb(struct ubi_attach_info *ai, struct list_head *list,
int pnum, int ec, int scrub)
{
struct ubi_ainf_peb *aeb;
aeb = ubi_alloc_aeb(ai, pnum, ec);
if (!aeb)
return -ENOMEM;
aeb->lnum = -1;
aeb->scrub = scrub;
aeb->copy_flag = aeb->sqnum = 0;
ai->ec_sum += aeb->ec;
ai->ec_count++;
if (ai->max_ec < aeb->ec)
ai->max_ec = aeb->ec;
if (ai->min_ec > aeb->ec)
ai->min_ec = aeb->ec;
list_add_tail(&aeb->u.list, list);
return 0;
}
static struct ubi_ainf_volume *add_vol(struct ubi_attach_info *ai, int vol_id,
int used_ebs, int data_pad, u8 vol_type,
int last_eb_bytes)
{
struct ubi_ainf_volume *av;
av = ubi_add_av(ai, vol_id);
if (IS_ERR(av))
return av;
av->data_pad = data_pad;
av->last_data_size = last_eb_bytes;
av->compat = 0;
av->vol_type = vol_type;
if (av->vol_type == UBI_STATIC_VOLUME)
av->used_ebs = used_ebs;
dbg_bld("found volume (ID %i)", vol_id);
return av;
}
static void assign_aeb_to_av(struct ubi_attach_info *ai,
struct ubi_ainf_peb *aeb,
struct ubi_ainf_volume *av)
{
struct ubi_ainf_peb *tmp_aeb;
struct rb_node **p = &ai->volumes.rb_node, *parent = NULL;
p = &av->root.rb_node;
while (*p) {
parent = *p;
tmp_aeb = rb_entry(parent, struct ubi_ainf_peb, u.rb);
if (aeb->lnum != tmp_aeb->lnum) {
if (aeb->lnum < tmp_aeb->lnum)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
continue;
} else
break;
}
list_del(&aeb->u.list);
av->leb_count++;
rb_link_node(&aeb->u.rb, parent, p);
rb_insert_color(&aeb->u.rb, &av->root);
}
static int update_vol(struct ubi_device *ubi, struct ubi_attach_info *ai,
struct ubi_ainf_volume *av, struct ubi_vid_hdr *new_vh,
struct ubi_ainf_peb *new_aeb)
{
struct rb_node **p = &av->root.rb_node, *parent = NULL;
struct ubi_ainf_peb *aeb, *victim;
int cmp_res;
while (*p) {
parent = *p;
aeb = rb_entry(parent, struct ubi_ainf_peb, u.rb);
if (be32_to_cpu(new_vh->lnum) != aeb->lnum) {
if (be32_to_cpu(new_vh->lnum) < aeb->lnum)
p = &(*p)->rb_left;
else
p = &(*p)->rb_right;
continue;
}
if (aeb->pnum == new_aeb->pnum) {
ubi_assert(aeb->lnum == new_aeb->lnum);
ubi_free_aeb(ai, new_aeb);
return 0;
}
cmp_res = ubi_compare_lebs(ubi, aeb, new_aeb->pnum, new_vh);
if (cmp_res < 0)
return cmp_res;
if (cmp_res & 1) {
victim = ubi_alloc_aeb(ai, aeb->pnum, aeb->ec);
if (!victim)
return -ENOMEM;
list_add_tail(&victim->u.list, &ai->erase);
if (av->highest_lnum == be32_to_cpu(new_vh->lnum))
av->last_data_size =
be32_to_cpu(new_vh->data_size);
dbg_bld("vol %i: AEB %i's PEB %i is the newer",
av->vol_id, aeb->lnum, new_aeb->pnum);
aeb->ec = new_aeb->ec;
aeb->pnum = new_aeb->pnum;
aeb->copy_flag = new_vh->copy_flag;
aeb->scrub = new_aeb->scrub;
aeb->sqnum = new_aeb->sqnum;
ubi_free_aeb(ai, new_aeb);
} else {
dbg_bld("vol %i: AEB %i's PEB %i is old, dropping it",
av->vol_id, aeb->lnum, new_aeb->pnum);
list_add_tail(&new_aeb->u.list, &ai->erase);
}
return 0;
}
if (av->highest_lnum <= be32_to_cpu(new_vh->lnum)) {
av->highest_lnum = be32_to_cpu(new_vh->lnum);
av->last_data_size = be32_to_cpu(new_vh->data_size);
}
if (av->vol_type == UBI_STATIC_VOLUME)
av->used_ebs = be32_to_cpu(new_vh->used_ebs);
av->leb_count++;
rb_link_node(&new_aeb->u.rb, parent, p);
rb_insert_color(&new_aeb->u.rb, &av->root);
return 0;
}
static int process_pool_aeb(struct ubi_device *ubi, struct ubi_attach_info *ai,
struct ubi_vid_hdr *new_vh,
struct ubi_ainf_peb *new_aeb)
{
int vol_id = be32_to_cpu(new_vh->vol_id);
struct ubi_ainf_volume *av;
if (vol_id == UBI_FM_SB_VOLUME_ID || vol_id == UBI_FM_DATA_VOLUME_ID) {
ubi_free_aeb(ai, new_aeb);
return 0;
}
av = ubi_find_av(ai, vol_id);
if (!av) {
ubi_err(ubi, "orphaned volume in fastmap pool!");
ubi_free_aeb(ai, new_aeb);
return UBI_BAD_FASTMAP;
}
ubi_assert(vol_id == av->vol_id);
return update_vol(ubi, ai, av, new_vh, new_aeb);
}
static void unmap_peb(struct ubi_attach_info *ai, int pnum)
{
struct ubi_ainf_volume *av;
struct rb_node *node, *node2;
struct ubi_ainf_peb *aeb;
ubi_rb_for_each_entry(node, av, &ai->volumes, rb) {
ubi_rb_for_each_entry(node2, aeb, &av->root, u.rb) {
if (aeb->pnum == pnum) {
rb_erase(&aeb->u.rb, &av->root);
av->leb_count--;
ubi_free_aeb(ai, aeb);
return;
}
}
}
}
static int scan_pool(struct ubi_device *ubi, struct ubi_attach_info *ai,
__be32 *pebs, int pool_size, unsigned long long *max_sqnum,
struct list_head *free)
{
struct ubi_vid_io_buf *vb;
struct ubi_vid_hdr *vh;
struct ubi_ec_hdr *ech;
struct ubi_ainf_peb *new_aeb;
int i, pnum, err, ret = 0;
ech = kzalloc(ubi->ec_hdr_alsize, GFP_KERNEL);
if (!ech)
return -ENOMEM;
vb = ubi_alloc_vid_buf(ubi, GFP_KERNEL);
if (!vb) {
kfree(ech);
return -ENOMEM;
}
vh = ubi_get_vid_hdr(vb);
dbg_bld("scanning fastmap pool: size = %i", pool_size);
for (i = 0; i < pool_size; i++) {
int scrub = 0;
int image_seq;
pnum = be32_to_cpu(pebs[i]);
if (ubi_io_is_bad(ubi, pnum)) {
ubi_err(ubi, "bad PEB in fastmap pool!");
ret = UBI_BAD_FASTMAP;
goto out;
}
err = ubi_io_read_ec_hdr(ubi, pnum, ech, 0);
if (err && err != UBI_IO_BITFLIPS) {
ubi_err(ubi, "unable to read EC header! PEB:%i err:%i",
pnum, err);
ret = err > 0 ? UBI_BAD_FASTMAP : err;
goto out;
} else if (err == UBI_IO_BITFLIPS)
scrub = 1;
image_seq = be32_to_cpu(ech->image_seq);
if (image_seq && (image_seq != ubi->image_seq)) {
ubi_err(ubi, "bad image seq: 0x%x, expected: 0x%x",
be32_to_cpu(ech->image_seq), ubi->image_seq);
ret = UBI_BAD_FASTMAP;
goto out;
}
err = ubi_io_read_vid_hdr(ubi, pnum, vb, 0);
if (err == UBI_IO_FF || err == UBI_IO_FF_BITFLIPS) {
unsigned long long ec = be64_to_cpu(ech->ec);
unmap_peb(ai, pnum);
dbg_bld("Adding PEB to free: %i", pnum);
if (err == UBI_IO_FF_BITFLIPS)
scrub = 1;
add_aeb(ai, free, pnum, ec, scrub);
continue;
} else if (err == 0 || err == UBI_IO_BITFLIPS) {
dbg_bld("Found non empty PEB:%i in pool", pnum);
if (err == UBI_IO_BITFLIPS)
scrub = 1;
new_aeb = ubi_alloc_aeb(ai, pnum, be64_to_cpu(ech->ec));
if (!new_aeb) {
ret = -ENOMEM;
goto out;
}
new_aeb->lnum = be32_to_cpu(vh->lnum);
new_aeb->sqnum = be64_to_cpu(vh->sqnum);
new_aeb->copy_flag = vh->copy_flag;
new_aeb->scrub = scrub;
if (*max_sqnum < new_aeb->sqnum)
*max_sqnum = new_aeb->sqnum;
err = process_pool_aeb(ubi, ai, vh, new_aeb);
if (err) {
ret = err > 0 ? UBI_BAD_FASTMAP : err;
goto out;
}
} else {
ubi_err(ubi, "fastmap pool PEBs contains damaged PEBs!");
ret = err > 0 ? UBI_BAD_FASTMAP : err;
goto out;
}
}
out:
ubi_free_vid_buf(vb);
kfree(ech);
return ret;
}
static int count_fastmap_pebs(struct ubi_attach_info *ai)
{
struct ubi_ainf_peb *aeb;
struct ubi_ainf_volume *av;
struct rb_node *rb1, *rb2;
int n = 0;
list_for_each_entry(aeb, &ai->erase, u.list)
n++;
list_for_each_entry(aeb, &ai->free, u.list)
n++;
ubi_rb_for_each_entry(rb1, av, &ai->volumes, rb)
ubi_rb_for_each_entry(rb2, aeb, &av->root, u.rb)
n++;
return n;
}
static int ubi_attach_fastmap(struct ubi_device *ubi,
struct ubi_attach_info *ai,
struct ubi_fastmap_layout *fm)
{
struct list_head used, free;
struct ubi_ainf_volume *av;
struct ubi_ainf_peb *aeb, *tmp_aeb, *_tmp_aeb;
struct ubi_fm_sb *fmsb;
struct ubi_fm_hdr *fmhdr;
struct ubi_fm_scan_pool *fmpl, *fmpl_wl;
struct ubi_fm_ec *fmec;
struct ubi_fm_volhdr *fmvhdr;
struct ubi_fm_eba *fm_eba;
int ret, i, j, pool_size, wl_pool_size;
size_t fm_pos = 0, fm_size = ubi->fm_size;
unsigned long long max_sqnum = 0;
void *fm_raw = ubi->fm_buf;
INIT_LIST_HEAD(&used);
INIT_LIST_HEAD(&free);
ai->min_ec = UBI_MAX_ERASECOUNTER;
fmsb = (struct ubi_fm_sb *)(fm_raw);
ai->max_sqnum = fmsb->sqnum;
fm_pos += sizeof(struct ubi_fm_sb);
if (fm_pos >= fm_size)
goto fail_bad;
fmhdr = (struct ubi_fm_hdr *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmhdr);
if (fm_pos >= fm_size)
goto fail_bad;
if (be32_to_cpu(fmhdr->magic) != UBI_FM_HDR_MAGIC) {
ubi_err(ubi, "bad fastmap header magic: 0x%x, expected: 0x%x",
be32_to_cpu(fmhdr->magic), UBI_FM_HDR_MAGIC);
goto fail_bad;
}
fmpl = (struct ubi_fm_scan_pool *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmpl);
if (fm_pos >= fm_size)
goto fail_bad;
if (be32_to_cpu(fmpl->magic) != UBI_FM_POOL_MAGIC) {
ubi_err(ubi, "bad fastmap pool magic: 0x%x, expected: 0x%x",
be32_to_cpu(fmpl->magic), UBI_FM_POOL_MAGIC);
goto fail_bad;
}
fmpl_wl = (struct ubi_fm_scan_pool *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmpl_wl);
if (fm_pos >= fm_size)
goto fail_bad;
if (be32_to_cpu(fmpl_wl->magic) != UBI_FM_POOL_MAGIC) {
ubi_err(ubi, "bad fastmap WL pool magic: 0x%x, expected: 0x%x",
be32_to_cpu(fmpl_wl->magic), UBI_FM_POOL_MAGIC);
goto fail_bad;
}
pool_size = be16_to_cpu(fmpl->size);
wl_pool_size = be16_to_cpu(fmpl_wl->size);
fm->max_pool_size = be16_to_cpu(fmpl->max_size);
fm->max_wl_pool_size = be16_to_cpu(fmpl_wl->max_size);
if (pool_size > UBI_FM_MAX_POOL_SIZE || pool_size < 0) {
ubi_err(ubi, "bad pool size: %i", pool_size);
goto fail_bad;
}
if (wl_pool_size > UBI_FM_MAX_POOL_SIZE || wl_pool_size < 0) {
ubi_err(ubi, "bad WL pool size: %i", wl_pool_size);
goto fail_bad;
}
if (fm->max_pool_size > UBI_FM_MAX_POOL_SIZE ||
fm->max_pool_size < 0) {
ubi_err(ubi, "bad maximal pool size: %i", fm->max_pool_size);
goto fail_bad;
}
if (fm->max_wl_pool_size > UBI_FM_MAX_POOL_SIZE ||
fm->max_wl_pool_size < 0) {
ubi_err(ubi, "bad maximal WL pool size: %i",
fm->max_wl_pool_size);
goto fail_bad;
}
for (i = 0; i < be32_to_cpu(fmhdr->free_peb_count); i++) {
fmec = (struct ubi_fm_ec *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmec);
if (fm_pos >= fm_size)
goto fail_bad;
add_aeb(ai, &ai->free, be32_to_cpu(fmec->pnum),
be32_to_cpu(fmec->ec), 0);
}
for (i = 0; i < be32_to_cpu(fmhdr->used_peb_count); i++) {
fmec = (struct ubi_fm_ec *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmec);
if (fm_pos >= fm_size)
goto fail_bad;
add_aeb(ai, &used, be32_to_cpu(fmec->pnum),
be32_to_cpu(fmec->ec), 0);
}
for (i = 0; i < be32_to_cpu(fmhdr->scrub_peb_count); i++) {
fmec = (struct ubi_fm_ec *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmec);
if (fm_pos >= fm_size)
goto fail_bad;
add_aeb(ai, &used, be32_to_cpu(fmec->pnum),
be32_to_cpu(fmec->ec), 1);
}
for (i = 0; i < be32_to_cpu(fmhdr->erase_peb_count); i++) {
fmec = (struct ubi_fm_ec *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmec);
if (fm_pos >= fm_size)
goto fail_bad;
add_aeb(ai, &ai->erase, be32_to_cpu(fmec->pnum),
be32_to_cpu(fmec->ec), 1);
}
ai->mean_ec = div_u64(ai->ec_sum, ai->ec_count);
ai->bad_peb_count = be32_to_cpu(fmhdr->bad_peb_count);
for (i = 0; i < be32_to_cpu(fmhdr->vol_count); i++) {
fmvhdr = (struct ubi_fm_volhdr *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmvhdr);
if (fm_pos >= fm_size)
goto fail_bad;
if (be32_to_cpu(fmvhdr->magic) != UBI_FM_VHDR_MAGIC) {
ubi_err(ubi, "bad fastmap vol header magic: 0x%x, expected: 0x%x",
be32_to_cpu(fmvhdr->magic), UBI_FM_VHDR_MAGIC);
goto fail_bad;
}
av = add_vol(ai, be32_to_cpu(fmvhdr->vol_id),
be32_to_cpu(fmvhdr->used_ebs),
be32_to_cpu(fmvhdr->data_pad),
fmvhdr->vol_type,
be32_to_cpu(fmvhdr->last_eb_bytes));
if (IS_ERR(av)) {
if (PTR_ERR(av) == -EEXIST)
ubi_err(ubi, "volume (ID %i) already exists",
fmvhdr->vol_id);
goto fail_bad;
}
ai->vols_found++;
if (ai->highest_vol_id < be32_to_cpu(fmvhdr->vol_id))
ai->highest_vol_id = be32_to_cpu(fmvhdr->vol_id);
fm_eba = (struct ubi_fm_eba *)(fm_raw + fm_pos);
fm_pos += sizeof(*fm_eba);
fm_pos += (sizeof(__be32) * be32_to_cpu(fm_eba->reserved_pebs));
if (fm_pos >= fm_size)
goto fail_bad;
if (be32_to_cpu(fm_eba->magic) != UBI_FM_EBA_MAGIC) {
ubi_err(ubi, "bad fastmap EBA header magic: 0x%x, expected: 0x%x",
be32_to_cpu(fm_eba->magic), UBI_FM_EBA_MAGIC);
goto fail_bad;
}
for (j = 0; j < be32_to_cpu(fm_eba->reserved_pebs); j++) {
int pnum = be32_to_cpu(fm_eba->pnum[j]);
if (pnum < 0)
continue;
aeb = NULL;
list_for_each_entry(tmp_aeb, &used, u.list) {
if (tmp_aeb->pnum == pnum) {
aeb = tmp_aeb;
break;
}
}
if (!aeb) {
ubi_err(ubi, "PEB %i is in EBA but not in used list", pnum);
goto fail_bad;
}
aeb->lnum = j;
if (av->highest_lnum <= aeb->lnum)
av->highest_lnum = aeb->lnum;
assign_aeb_to_av(ai, aeb, av);
dbg_bld("inserting PEB:%i (LEB %i) to vol %i",
aeb->pnum, aeb->lnum, av->vol_id);
}
}
ret = scan_pool(ubi, ai, fmpl->pebs, pool_size, &max_sqnum, &free);
if (ret)
goto fail;
ret = scan_pool(ubi, ai, fmpl_wl->pebs, wl_pool_size, &max_sqnum, &free);
if (ret)
goto fail;
if (max_sqnum > ai->max_sqnum)
ai->max_sqnum = max_sqnum;
list_for_each_entry_safe(tmp_aeb, _tmp_aeb, &free, u.list)
list_move_tail(&tmp_aeb->u.list, &ai->free);
list_for_each_entry_safe(tmp_aeb, _tmp_aeb, &used, u.list)
list_move_tail(&tmp_aeb->u.list, &ai->erase);
ubi_assert(list_empty(&free));
if (WARN_ON(count_fastmap_pebs(ai) != ubi->peb_count -
ai->bad_peb_count - fm->used_blocks))
goto fail_bad;
return 0;
fail_bad:
ret = UBI_BAD_FASTMAP;
fail:
list_for_each_entry_safe(tmp_aeb, _tmp_aeb, &used, u.list) {
list_del(&tmp_aeb->u.list);
ubi_free_aeb(ai, tmp_aeb);
}
list_for_each_entry_safe(tmp_aeb, _tmp_aeb, &free, u.list) {
list_del(&tmp_aeb->u.list);
ubi_free_aeb(ai, tmp_aeb);
}
return ret;
}
static int find_fm_anchor(struct ubi_attach_info *ai)
{
int ret = -1;
struct ubi_ainf_peb *aeb;
unsigned long long max_sqnum = 0;
list_for_each_entry(aeb, &ai->fastmap, u.list) {
if (aeb->vol_id == UBI_FM_SB_VOLUME_ID && aeb->sqnum > max_sqnum) {
max_sqnum = aeb->sqnum;
ret = aeb->pnum;
}
}
return ret;
}
static struct ubi_ainf_peb *clone_aeb(struct ubi_attach_info *ai,
struct ubi_ainf_peb *old)
{
struct ubi_ainf_peb *new;
new = ubi_alloc_aeb(ai, old->pnum, old->ec);
if (!new)
return NULL;
new->vol_id = old->vol_id;
new->sqnum = old->sqnum;
new->lnum = old->lnum;
new->scrub = old->scrub;
new->copy_flag = old->copy_flag;
return new;
}
int ubi_scan_fastmap(struct ubi_device *ubi, struct ubi_attach_info *ai,
struct ubi_attach_info *scan_ai)
{
struct ubi_fm_sb *fmsb, *fmsb2;
struct ubi_vid_io_buf *vb;
struct ubi_vid_hdr *vh;
struct ubi_ec_hdr *ech;
struct ubi_fastmap_layout *fm;
struct ubi_ainf_peb *aeb;
int i, used_blocks, pnum, fm_anchor, ret = 0;
size_t fm_size;
__be32 crc, tmp_crc;
unsigned long long sqnum = 0;
fm_anchor = find_fm_anchor(scan_ai);
if (fm_anchor < 0)
return UBI_NO_FASTMAP;
list_for_each_entry(aeb, &scan_ai->fastmap, u.list) {
struct ubi_ainf_peb *new;
new = clone_aeb(ai, aeb);
if (!new)
return -ENOMEM;
list_add(&new->u.list, &ai->fastmap);
}
down_write(&ubi->fm_protect);
memset(ubi->fm_buf, 0, ubi->fm_size);
fmsb = kmalloc(sizeof(*fmsb), GFP_KERNEL);
if (!fmsb) {
ret = -ENOMEM;
goto out;
}
fm = kzalloc(sizeof(*fm), GFP_KERNEL);
if (!fm) {
ret = -ENOMEM;
kfree(fmsb);
goto out;
}
ret = ubi_io_read_data(ubi, fmsb, fm_anchor, 0, sizeof(*fmsb));
if (ret && ret != UBI_IO_BITFLIPS)
goto free_fm_sb;
else if (ret == UBI_IO_BITFLIPS)
fm->to_be_tortured[0] = 1;
if (be32_to_cpu(fmsb->magic) != UBI_FM_SB_MAGIC) {
ubi_err(ubi, "bad super block magic: 0x%x, expected: 0x%x",
be32_to_cpu(fmsb->magic), UBI_FM_SB_MAGIC);
ret = UBI_BAD_FASTMAP;
goto free_fm_sb;
}
if (fmsb->version != UBI_FM_FMT_VERSION) {
ubi_err(ubi, "bad fastmap version: %i, expected: %i",
fmsb->version, UBI_FM_FMT_VERSION);
ret = UBI_BAD_FASTMAP;
goto free_fm_sb;
}
used_blocks = be32_to_cpu(fmsb->used_blocks);
if (used_blocks > UBI_FM_MAX_BLOCKS || used_blocks < 1) {
ubi_err(ubi, "number of fastmap blocks is invalid: %i",
used_blocks);
ret = UBI_BAD_FASTMAP;
goto free_fm_sb;
}
fm_size = ubi->leb_size * used_blocks;
if (fm_size != ubi->fm_size) {
ubi_err(ubi, "bad fastmap size: %zi, expected: %zi",
fm_size, ubi->fm_size);
ret = UBI_BAD_FASTMAP;
goto free_fm_sb;
}
ech = kzalloc(ubi->ec_hdr_alsize, GFP_KERNEL);
if (!ech) {
ret = -ENOMEM;
goto free_fm_sb;
}
vb = ubi_alloc_vid_buf(ubi, GFP_KERNEL);
if (!vb) {
ret = -ENOMEM;
goto free_hdr;
}
vh = ubi_get_vid_hdr(vb);
for (i = 0; i < used_blocks; i++) {
int image_seq;
pnum = be32_to_cpu(fmsb->block_loc[i]);
if (ubi_io_is_bad(ubi, pnum)) {
ret = UBI_BAD_FASTMAP;
goto free_hdr;
}
if (i == 0 && pnum != fm_anchor) {
ubi_err(ubi, "Fastmap anchor PEB mismatch: PEB: %i vs. %i",
pnum, fm_anchor);
ret = UBI_BAD_FASTMAP;
goto free_hdr;
}
ret = ubi_io_read_ec_hdr(ubi, pnum, ech, 0);
if (ret && ret != UBI_IO_BITFLIPS) {
ubi_err(ubi, "unable to read fastmap block# %i EC (PEB: %i)",
i, pnum);
if (ret > 0)
ret = UBI_BAD_FASTMAP;
goto free_hdr;
} else if (ret == UBI_IO_BITFLIPS)
fm->to_be_tortured[i] = 1;
image_seq = be32_to_cpu(ech->image_seq);
if (!ubi->image_seq)
ubi->image_seq = image_seq;
if (image_seq && (image_seq != ubi->image_seq)) {
ubi_err(ubi, "wrong image seq:%d instead of %d",
be32_to_cpu(ech->image_seq), ubi->image_seq);
ret = UBI_BAD_FASTMAP;
goto free_hdr;
}
ret = ubi_io_read_vid_hdr(ubi, pnum, vb, 0);
if (ret && ret != UBI_IO_BITFLIPS) {
ubi_err(ubi, "unable to read fastmap block# %i (PEB: %i)",
i, pnum);
goto free_hdr;
}
if (i == 0) {
if (be32_to_cpu(vh->vol_id) != UBI_FM_SB_VOLUME_ID) {
ubi_err(ubi, "bad fastmap anchor vol_id: 0x%x, expected: 0x%x",
be32_to_cpu(vh->vol_id),
UBI_FM_SB_VOLUME_ID);
ret = UBI_BAD_FASTMAP;
goto free_hdr;
}
} else {
if (be32_to_cpu(vh->vol_id) != UBI_FM_DATA_VOLUME_ID) {
ubi_err(ubi, "bad fastmap data vol_id: 0x%x, expected: 0x%x",
be32_to_cpu(vh->vol_id),
UBI_FM_DATA_VOLUME_ID);
ret = UBI_BAD_FASTMAP;
goto free_hdr;
}
}
if (sqnum < be64_to_cpu(vh->sqnum))
sqnum = be64_to_cpu(vh->sqnum);
ret = ubi_io_read_data(ubi, ubi->fm_buf + (ubi->leb_size * i),
pnum, 0, ubi->leb_size);
if (ret && ret != UBI_IO_BITFLIPS) {
ubi_err(ubi, "unable to read fastmap block# %i (PEB: %i, "
"err: %i)", i, pnum, ret);
goto free_hdr;
}
}
kfree(fmsb);
fmsb = NULL;
fmsb2 = (struct ubi_fm_sb *)(ubi->fm_buf);
tmp_crc = be32_to_cpu(fmsb2->data_crc);
fmsb2->data_crc = 0;
crc = crc32(UBI_CRC32_INIT, ubi->fm_buf, fm_size);
if (crc != tmp_crc) {
ubi_err(ubi, "fastmap data CRC is invalid");
ubi_err(ubi, "CRC should be: 0x%x, calc: 0x%x",
tmp_crc, crc);
ret = UBI_BAD_FASTMAP;
goto free_hdr;
}
fmsb2->sqnum = sqnum;
fm->used_blocks = used_blocks;
ret = ubi_attach_fastmap(ubi, ai, fm);
if (ret) {
if (ret > 0)
ret = UBI_BAD_FASTMAP;
goto free_hdr;
}
for (i = 0; i < used_blocks; i++) {
struct ubi_wl_entry *e;
e = kmem_cache_alloc(ubi_wl_entry_slab, GFP_KERNEL);
if (!e) {
while (i--)
kfree(fm->e[i]);
ret = -ENOMEM;
goto free_hdr;
}
e->pnum = be32_to_cpu(fmsb2->block_loc[i]);
e->ec = be32_to_cpu(fmsb2->block_ec[i]);
fm->e[i] = e;
}
ubi->fm = fm;
ubi->fm_pool.max_size = ubi->fm->max_pool_size;
ubi->fm_wl_pool.max_size = ubi->fm->max_wl_pool_size;
ubi_msg(ubi, "attached by fastmap");
ubi_msg(ubi, "fastmap pool size: %d", ubi->fm_pool.max_size);
ubi_msg(ubi, "fastmap WL pool size: %d",
ubi->fm_wl_pool.max_size);
ubi->fm_disabled = 0;
ubi->fast_attach = 1;
ubi_free_vid_buf(vb);
kfree(ech);
out:
up_write(&ubi->fm_protect);
if (ret == UBI_BAD_FASTMAP)
ubi_err(ubi, "Attach by fastmap failed, doing a full scan!");
return ret;
free_hdr:
ubi_free_vid_buf(vb);
kfree(ech);
free_fm_sb:
kfree(fmsb);
kfree(fm);
goto out;
}
static int ubi_write_fastmap(struct ubi_device *ubi,
struct ubi_fastmap_layout *new_fm)
{
size_t fm_pos = 0;
void *fm_raw;
struct ubi_fm_sb *fmsb;
struct ubi_fm_hdr *fmh;
struct ubi_fm_scan_pool *fmpl, *fmpl_wl;
struct ubi_fm_ec *fec;
struct ubi_fm_volhdr *fvh;
struct ubi_fm_eba *feba;
struct ubi_wl_entry *wl_e;
struct ubi_volume *vol;
struct ubi_vid_io_buf *avbuf, *dvbuf;
struct ubi_vid_hdr *avhdr, *dvhdr;
struct ubi_work *ubi_wrk;
struct rb_node *tmp_rb;
int ret, i, j, free_peb_count, used_peb_count, vol_count;
int scrub_peb_count, erase_peb_count;
unsigned long *seen_pebs = NULL;
fm_raw = ubi->fm_buf;
memset(ubi->fm_buf, 0, ubi->fm_size);
avbuf = new_fm_vbuf(ubi, UBI_FM_SB_VOLUME_ID);
if (!avbuf) {
ret = -ENOMEM;
goto out;
}
dvbuf = new_fm_vbuf(ubi, UBI_FM_DATA_VOLUME_ID);
if (!dvbuf) {
ret = -ENOMEM;
goto out_kfree;
}
avhdr = ubi_get_vid_hdr(avbuf);
dvhdr = ubi_get_vid_hdr(dvbuf);
seen_pebs = init_seen(ubi);
if (IS_ERR(seen_pebs)) {
ret = PTR_ERR(seen_pebs);
goto out_kfree;
}
spin_lock(&ubi->volumes_lock);
spin_lock(&ubi->wl_lock);
fmsb = (struct ubi_fm_sb *)fm_raw;
fm_pos += sizeof(*fmsb);
ubi_assert(fm_pos <= ubi->fm_size);
fmh = (struct ubi_fm_hdr *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmh);
ubi_assert(fm_pos <= ubi->fm_size);
fmsb->magic = cpu_to_be32(UBI_FM_SB_MAGIC);
fmsb->version = UBI_FM_FMT_VERSION;
fmsb->used_blocks = cpu_to_be32(new_fm->used_blocks);
fmsb->sqnum = 0;
fmh->magic = cpu_to_be32(UBI_FM_HDR_MAGIC);
free_peb_count = 0;
used_peb_count = 0;
scrub_peb_count = 0;
erase_peb_count = 0;
vol_count = 0;
fmpl = (struct ubi_fm_scan_pool *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmpl);
fmpl->magic = cpu_to_be32(UBI_FM_POOL_MAGIC);
fmpl->size = cpu_to_be16(ubi->fm_pool.size);
fmpl->max_size = cpu_to_be16(ubi->fm_pool.max_size);
for (i = 0; i < ubi->fm_pool.size; i++) {
fmpl->pebs[i] = cpu_to_be32(ubi->fm_pool.pebs[i]);
set_seen(ubi, ubi->fm_pool.pebs[i], seen_pebs);
}
fmpl_wl = (struct ubi_fm_scan_pool *)(fm_raw + fm_pos);
fm_pos += sizeof(*fmpl_wl);
fmpl_wl->magic = cpu_to_be32(UBI_FM_POOL_MAGIC);
fmpl_wl->size = cpu_to_be16(ubi->fm_wl_pool.size);
fmpl_wl->max_size = cpu_to_be16(ubi->fm_wl_pool.max_size);
for (i = 0; i < ubi->fm_wl_pool.size; i++) {
fmpl_wl->pebs[i] = cpu_to_be32(ubi->fm_wl_pool.pebs[i]);
set_seen(ubi, ubi->fm_wl_pool.pebs[i], seen_pebs);
}
ubi_for_each_free_peb(ubi, wl_e, tmp_rb) {
fec = (struct ubi_fm_ec *)(fm_raw + fm_pos);
fec->pnum = cpu_to_be32(wl_e->pnum);
set_seen(ubi, wl_e->pnum, seen_pebs);
fec->ec = cpu_to_be32(wl_e->ec);
free_peb_count++;
fm_pos += sizeof(*fec);
ubi_assert(fm_pos <= ubi->fm_size);
}
fmh->free_peb_count = cpu_to_be32(free_peb_count);
ubi_for_each_used_peb(ubi, wl_e, tmp_rb) {
fec = (struct ubi_fm_ec *)(fm_raw + fm_pos);
fec->pnum = cpu_to_be32(wl_e->pnum);
set_seen(ubi, wl_e->pnum, seen_pebs);
fec->ec = cpu_to_be32(wl_e->ec);
used_peb_count++;
fm_pos += sizeof(*fec);
ubi_assert(fm_pos <= ubi->fm_size);
}
ubi_for_each_protected_peb(ubi, i, wl_e) {
fec = (struct ubi_fm_ec *)(fm_raw + fm_pos);
fec->pnum = cpu_to_be32(wl_e->pnum);
set_seen(ubi, wl_e->pnum, seen_pebs);
fec->ec = cpu_to_be32(wl_e->ec);
used_peb_count++;
fm_pos += sizeof(*fec);
ubi_assert(fm_pos <= ubi->fm_size);
}
fmh->used_peb_count = cpu_to_be32(used_peb_count);
ubi_for_each_scrub_peb(ubi, wl_e, tmp_rb) {
fec = (struct ubi_fm_ec *)(fm_raw + fm_pos);
fec->pnum = cpu_to_be32(wl_e->pnum);
set_seen(ubi, wl_e->pnum, seen_pebs);
fec->ec = cpu_to_be32(wl_e->ec);
scrub_peb_count++;
fm_pos += sizeof(*fec);
ubi_assert(fm_pos <= ubi->fm_size);
}
fmh->scrub_peb_count = cpu_to_be32(scrub_peb_count);
list_for_each_entry(ubi_wrk, &ubi->works, list) {
if (ubi_is_erase_work(ubi_wrk)) {
wl_e = ubi_wrk->e;
ubi_assert(wl_e);
fec = (struct ubi_fm_ec *)(fm_raw + fm_pos);
fec->pnum = cpu_to_be32(wl_e->pnum);
set_seen(ubi, wl_e->pnum, seen_pebs);
fec->ec = cpu_to_be32(wl_e->ec);
erase_peb_count++;
fm_pos += sizeof(*fec);
ubi_assert(fm_pos <= ubi->fm_size);
}
}
fmh->erase_peb_count = cpu_to_be32(erase_peb_count);
for (i = 0; i < UBI_MAX_VOLUMES + UBI_INT_VOL_COUNT; i++) {
vol = ubi->volumes[i];
if (!vol)
continue;
vol_count++;
fvh = (struct ubi_fm_volhdr *)(fm_raw + fm_pos);
fm_pos += sizeof(*fvh);
ubi_assert(fm_pos <= ubi->fm_size);
fvh->magic = cpu_to_be32(UBI_FM_VHDR_MAGIC);
fvh->vol_id = cpu_to_be32(vol->vol_id);
fvh->vol_type = vol->vol_type;
fvh->used_ebs = cpu_to_be32(vol->used_ebs);
fvh->data_pad = cpu_to_be32(vol->data_pad);
fvh->last_eb_bytes = cpu_to_be32(vol->last_eb_bytes);
ubi_assert(vol->vol_type == UBI_DYNAMIC_VOLUME ||
vol->vol_type == UBI_STATIC_VOLUME);
feba = (struct ubi_fm_eba *)(fm_raw + fm_pos);
fm_pos += sizeof(*feba) + (sizeof(__be32) * vol->reserved_pebs);
ubi_assert(fm_pos <= ubi->fm_size);
for (j = 0; j < vol->reserved_pebs; j++) {
struct ubi_eba_leb_desc ldesc;
ubi_eba_get_ldesc(vol, j, &ldesc);
feba->pnum[j] = cpu_to_be32(ldesc.pnum);
}
feba->reserved_pebs = cpu_to_be32(j);
feba->magic = cpu_to_be32(UBI_FM_EBA_MAGIC);
}
fmh->vol_count = cpu_to_be32(vol_count);
fmh->bad_peb_count = cpu_to_be32(ubi->bad_peb_count);
avhdr->sqnum = cpu_to_be64(ubi_next_sqnum(ubi));
avhdr->lnum = 0;
spin_unlock(&ubi->wl_lock);
spin_unlock(&ubi->volumes_lock);
dbg_bld("writing fastmap SB to PEB %i", new_fm->e[0]->pnum);
ret = ubi_io_write_vid_hdr(ubi, new_fm->e[0]->pnum, avbuf);
if (ret) {
ubi_err(ubi, "unable to write vid_hdr to fastmap SB!");
goto out_kfree;
}
for (i = 0; i < new_fm->used_blocks; i++) {
fmsb->block_loc[i] = cpu_to_be32(new_fm->e[i]->pnum);
set_seen(ubi, new_fm->e[i]->pnum, seen_pebs);
fmsb->block_ec[i] = cpu_to_be32(new_fm->e[i]->ec);
}
fmsb->data_crc = 0;
fmsb->data_crc = cpu_to_be32(crc32(UBI_CRC32_INIT, fm_raw,
ubi->fm_size));
for (i = 1; i < new_fm->used_blocks; i++) {
dvhdr->sqnum = cpu_to_be64(ubi_next_sqnum(ubi));
dvhdr->lnum = cpu_to_be32(i);
dbg_bld("writing fastmap data to PEB %i sqnum %llu",
new_fm->e[i]->pnum, be64_to_cpu(dvhdr->sqnum));
ret = ubi_io_write_vid_hdr(ubi, new_fm->e[i]->pnum, dvbuf);
if (ret) {
ubi_err(ubi, "unable to write vid_hdr to PEB %i!",
new_fm->e[i]->pnum);
goto out_kfree;
}
}
for (i = 0; i < new_fm->used_blocks; i++) {
ret = ubi_io_write_data(ubi, fm_raw + (i * ubi->leb_size),
new_fm->e[i]->pnum, 0, ubi->leb_size);
if (ret) {
ubi_err(ubi, "unable to write fastmap to PEB %i!",
new_fm->e[i]->pnum);
goto out_kfree;
}
}
ubi_assert(new_fm);
ubi->fm = new_fm;
ret = self_check_seen(ubi, seen_pebs);
dbg_bld("fastmap written!");
out_kfree:
ubi_free_vid_buf(avbuf);
ubi_free_vid_buf(dvbuf);
free_seen(seen_pebs);
out:
return ret;
}
static int erase_block(struct ubi_device *ubi, int pnum)
{
int ret;
struct ubi_ec_hdr *ec_hdr;
long long ec;
ec_hdr = kzalloc(ubi->ec_hdr_alsize, GFP_KERNEL);
if (!ec_hdr)
return -ENOMEM;
ret = ubi_io_read_ec_hdr(ubi, pnum, ec_hdr, 0);
if (ret < 0)
goto out;
else if (ret && ret != UBI_IO_BITFLIPS) {
ret = -EINVAL;
goto out;
}
ret = ubi_io_sync_erase(ubi, pnum, 0);
if (ret < 0)
goto out;
ec = be64_to_cpu(ec_hdr->ec);
ec += ret;
if (ec > UBI_MAX_ERASECOUNTER) {
ret = -EINVAL;
goto out;
}
ec_hdr->ec = cpu_to_be64(ec);
ret = ubi_io_write_ec_hdr(ubi, pnum, ec_hdr);
if (ret < 0)
goto out;
ret = ec;
out:
kfree(ec_hdr);
return ret;
}
static int invalidate_fastmap(struct ubi_device *ubi)
{
int ret;
struct ubi_fastmap_layout *fm;
struct ubi_wl_entry *e;
struct ubi_vid_io_buf *vb = NULL;
struct ubi_vid_hdr *vh;
if (!ubi->fm)
return 0;
ubi->fm = NULL;
ret = -ENOMEM;
fm = kzalloc(sizeof(*fm), GFP_KERNEL);
if (!fm)
goto out;
vb = new_fm_vbuf(ubi, UBI_FM_SB_VOLUME_ID);
if (!vb)
goto out_free_fm;
vh = ubi_get_vid_hdr(vb);
ret = -ENOSPC;
e = ubi_wl_get_fm_peb(ubi, 1);
if (!e)
goto out_free_fm;
vh->sqnum = cpu_to_be64(ubi_next_sqnum(ubi));
ret = ubi_io_write_vid_hdr(ubi, e->pnum, vb);
if (ret < 0) {
ubi_wl_put_fm_peb(ubi, e, 0, 0);
goto out_free_fm;
}
fm->used_blocks = 1;
fm->e[0] = e;
ubi->fm = fm;
out:
ubi_free_vid_buf(vb);
return ret;
out_free_fm:
kfree(fm);
goto out;
}
static void return_fm_pebs(struct ubi_device *ubi,
struct ubi_fastmap_layout *fm)
{
int i;
if (!fm)
return;
for (i = 0; i < fm->used_blocks; i++) {
if (fm->e[i]) {
ubi_wl_put_fm_peb(ubi, fm->e[i], i,
fm->to_be_tortured[i]);
fm->e[i] = NULL;
}
}
}
int ubi_update_fastmap(struct ubi_device *ubi)
{
int ret, i, j;
struct ubi_fastmap_layout *new_fm, *old_fm;
struct ubi_wl_entry *tmp_e;
down_write(&ubi->fm_protect);
down_write(&ubi->work_sem);
down_write(&ubi->fm_eba_sem);
ubi_refill_pools(ubi);
if (ubi->ro_mode || ubi->fm_disabled) {
up_write(&ubi->fm_eba_sem);
up_write(&ubi->work_sem);
up_write(&ubi->fm_protect);
return 0;
}
ret = ubi_ensure_anchor_pebs(ubi);
if (ret) {
up_write(&ubi->fm_eba_sem);
up_write(&ubi->work_sem);
up_write(&ubi->fm_protect);
return ret;
}
new_fm = kzalloc(sizeof(*new_fm), GFP_KERNEL);
if (!new_fm) {
up_write(&ubi->fm_eba_sem);
up_write(&ubi->work_sem);
up_write(&ubi->fm_protect);
return -ENOMEM;
}
new_fm->used_blocks = ubi->fm_size / ubi->leb_size;
old_fm = ubi->fm;
ubi->fm = NULL;
if (new_fm->used_blocks > UBI_FM_MAX_BLOCKS) {
ubi_err(ubi, "fastmap too large");
ret = -ENOSPC;
goto err;
}
for (i = 1; i < new_fm->used_blocks; i++) {
spin_lock(&ubi->wl_lock);
tmp_e = ubi_wl_get_fm_peb(ubi, 0);
spin_unlock(&ubi->wl_lock);
if (!tmp_e) {
if (old_fm && old_fm->e[i]) {
ret = erase_block(ubi, old_fm->e[i]->pnum);
if (ret < 0) {
ubi_err(ubi, "could not erase old fastmap PEB");
for (j = 1; j < i; j++) {
ubi_wl_put_fm_peb(ubi, new_fm->e[j],
j, 0);
new_fm->e[j] = NULL;
}
goto err;
}
new_fm->e[i] = old_fm->e[i];
old_fm->e[i] = NULL;
} else {
ubi_err(ubi, "could not get any free erase block");
for (j = 1; j < i; j++) {
ubi_wl_put_fm_peb(ubi, new_fm->e[j], j, 0);
new_fm->e[j] = NULL;
}
ret = -ENOSPC;
goto err;
}
} else {
new_fm->e[i] = tmp_e;
if (old_fm && old_fm->e[i]) {
ubi_wl_put_fm_peb(ubi, old_fm->e[i], i,
old_fm->to_be_tortured[i]);
old_fm->e[i] = NULL;
}
}
}
if (old_fm && new_fm->used_blocks < old_fm->used_blocks) {
for (i = new_fm->used_blocks; i < old_fm->used_blocks; i++) {
ubi_wl_put_fm_peb(ubi, old_fm->e[i], i,
old_fm->to_be_tortured[i]);
old_fm->e[i] = NULL;
}
}
spin_lock(&ubi->wl_lock);
tmp_e = ubi_wl_get_fm_peb(ubi, 1);
spin_unlock(&ubi->wl_lock);
if (old_fm) {
if (!tmp_e) {
ret = erase_block(ubi, old_fm->e[0]->pnum);
if (ret < 0) {
ubi_err(ubi, "could not erase old anchor PEB");
for (i = 1; i < new_fm->used_blocks; i++) {
ubi_wl_put_fm_peb(ubi, new_fm->e[i],
i, 0);
new_fm->e[i] = NULL;
}
goto err;
}
new_fm->e[0] = old_fm->e[0];
new_fm->e[0]->ec = ret;
old_fm->e[0] = NULL;
} else {
ubi_wl_put_fm_peb(ubi, old_fm->e[0], 0,
old_fm->to_be_tortured[0]);
new_fm->e[0] = tmp_e;
old_fm->e[0] = NULL;
}
} else {
if (!tmp_e) {
ubi_err(ubi, "could not find any anchor PEB");
for (i = 1; i < new_fm->used_blocks; i++) {
ubi_wl_put_fm_peb(ubi, new_fm->e[i], i, 0);
new_fm->e[i] = NULL;
}
ret = -ENOSPC;
goto err;
}
new_fm->e[0] = tmp_e;
}
ret = ubi_write_fastmap(ubi, new_fm);
if (ret)
goto err;
out_unlock:
up_write(&ubi->fm_eba_sem);
up_write(&ubi->work_sem);
up_write(&ubi->fm_protect);
kfree(old_fm);
return ret;
err:
ubi_warn(ubi, "Unable to write new fastmap, err=%i", ret);
ret = invalidate_fastmap(ubi);
if (ret < 0) {
ubi_err(ubi, "Unable to invalidate current fastmap!");
ubi_ro_mode(ubi);
} else {
return_fm_pebs(ubi, old_fm);
return_fm_pebs(ubi, new_fm);
ret = 0;
}
kfree(new_fm);
goto out_unlock;
}
