int ore_verify_layout(unsigned total_comps, struct ore_layout *layout)
{
u64 stripe_length;
switch (layout->raid_algorithm) {
case PNFS_OSD_RAID_0:
layout->parity = 0;
break;
case PNFS_OSD_RAID_5:
layout->parity = 1;
break;
case PNFS_OSD_RAID_PQ:
layout->parity = 2;
break;
case PNFS_OSD_RAID_4:
default:
ORE_ERR("Only RAID_0/5/6 for now received-enum=%d\n",
layout->raid_algorithm);
return -EINVAL;
}
if (0 != (layout->stripe_unit & ~PAGE_MASK)) {
ORE_ERR("Stripe Unit(0x%llx)"
" must be Multples of PAGE_SIZE(0x%lx)\n",
_LLU(layout->stripe_unit), PAGE_SIZE);
return -EINVAL;
}
if (layout->group_width) {
if (!layout->group_depth) {
ORE_ERR("group_depth == 0 && group_width != 0\n");
return -EINVAL;
}
if (total_comps < (layout->group_width * layout->mirrors_p1)) {
ORE_ERR("Data Map wrong, "
"numdevs=%d < group_width=%d * mirrors=%d\n",
total_comps, layout->group_width,
layout->mirrors_p1);
return -EINVAL;
}
layout->group_count = total_comps / layout->mirrors_p1 /
layout->group_width;
} else {
if (layout->group_depth) {
printk(KERN_NOTICE "Warning: group_depth ignored "
"group_width == 0 && group_depth == %lld\n",
_LLU(layout->group_depth));
}
layout->group_width = total_comps / layout->mirrors_p1;
layout->group_depth = -1;
layout->group_count = 1;
}
stripe_length = (u64)layout->group_width * layout->stripe_unit;
if (stripe_length >= (1ULL << 32)) {
ORE_ERR("Stripe_length(0x%llx) >= 32bit is not supported\n",
_LLU(stripe_length));
return -EINVAL;
}
layout->max_io_length =
(BIO_MAX_PAGES_KMALLOC * PAGE_SIZE - layout->stripe_unit) *
(layout->group_width - layout->parity);
if (layout->parity) {
unsigned stripe_length =
(layout->group_width - layout->parity) *
layout->stripe_unit;
layout->max_io_length /= stripe_length;
layout->max_io_length *= stripe_length;
}
ORE_DBGMSG("max_io_length=0x%lx\n", layout->max_io_length);
return 0;
}
static u8 *_ios_cred(struct ore_io_state *ios, unsigned index)
{
return ios->oc->comps[index & ios->oc->single_comp].cred;
}
static struct osd_obj_id *_ios_obj(struct ore_io_state *ios, unsigned index)
{
return &ios->oc->comps[index & ios->oc->single_comp].obj;
}
static struct osd_dev *_ios_od(struct ore_io_state *ios, unsigned index)
{
ORE_DBGMSG2("oc->first_dev=%d oc->numdevs=%d i=%d oc->ods=%p\n",
ios->oc->first_dev, ios->oc->numdevs, index,
ios->oc->ods);
return ore_comp_dev(ios->oc, index);
}
int _ore_get_io_state(struct ore_layout *layout,
struct ore_components *oc, unsigned numdevs,
unsigned sgs_per_dev, unsigned num_par_pages,
struct ore_io_state **pios)
{
struct ore_io_state *ios;
struct page **pages;
struct osd_sg_entry *sgilist;
struct __alloc_all_io_state {
struct ore_io_state ios;
struct ore_per_dev_state per_dev[numdevs];
union {
struct osd_sg_entry sglist[sgs_per_dev * numdevs];
struct page *pages[num_par_pages];
};
} *_aios;
if (likely(sizeof(*_aios) <= PAGE_SIZE)) {
_aios = kzalloc(sizeof(*_aios), GFP_KERNEL);
if (unlikely(!_aios)) {
ORE_DBGMSG("Failed kzalloc bytes=%zd\n",
sizeof(*_aios));
*pios = NULL;
return -ENOMEM;
}
pages = num_par_pages ? _aios->pages : NULL;
sgilist = sgs_per_dev ? _aios->sglist : NULL;
ios = &_aios->ios;
} else {
struct __alloc_small_io_state {
struct ore_io_state ios;
struct ore_per_dev_state per_dev[numdevs];
} *_aio_small;
union __extra_part {
struct osd_sg_entry sglist[sgs_per_dev * numdevs];
struct page *pages[num_par_pages];
} *extra_part;
_aio_small = kzalloc(sizeof(*_aio_small), GFP_KERNEL);
if (unlikely(!_aio_small)) {
ORE_DBGMSG("Failed alloc first part bytes=%zd\n",
sizeof(*_aio_small));
*pios = NULL;
return -ENOMEM;
}
extra_part = kzalloc(sizeof(*extra_part), GFP_KERNEL);
if (unlikely(!extra_part)) {
ORE_DBGMSG("Failed alloc second part bytes=%zd\n",
sizeof(*extra_part));
kfree(_aio_small);
*pios = NULL;
return -ENOMEM;
}
pages = num_par_pages ? extra_part->pages : NULL;
sgilist = sgs_per_dev ? extra_part->sglist : NULL;
ios = &_aio_small->ios;
ios->extra_part_alloc = true;
}
if (pages) {
ios->parity_pages = pages;
ios->max_par_pages = num_par_pages;
}
if (sgilist) {
unsigned d;
for (d = 0; d < numdevs; ++d) {
ios->per_dev[d].sglist = sgilist;
sgilist += sgs_per_dev;
}
ios->sgs_per_dev = sgs_per_dev;
}
ios->layout = layout;
ios->oc = oc;
*pios = ios;
return 0;
}
int ore_get_rw_state(struct ore_layout *layout, struct ore_components *oc,
bool is_reading, u64 offset, u64 length,
struct ore_io_state **pios)
{
struct ore_io_state *ios;
unsigned numdevs = layout->group_width * layout->mirrors_p1;
unsigned sgs_per_dev = 0, max_par_pages = 0;
int ret;
if (layout->parity && length) {
unsigned data_devs = layout->group_width - layout->parity;
unsigned stripe_size = layout->stripe_unit * data_devs;
unsigned pages_in_unit = layout->stripe_unit / PAGE_SIZE;
u32 remainder;
u64 num_stripes;
u64 num_raid_units;
num_stripes = div_u64_rem(length, stripe_size, &remainder);
if (remainder)
++num_stripes;
num_raid_units = num_stripes * layout->parity;
if (is_reading) {
num_raid_units += layout->group_width;
sgs_per_dev = div_u64(num_raid_units, data_devs) + 2;
} else {
max_par_pages = num_raid_units * pages_in_unit *
sizeof(struct page *);
}
}
ret = _ore_get_io_state(layout, oc, numdevs, sgs_per_dev, max_par_pages,
pios);
if (unlikely(ret))
return ret;
ios = *pios;
ios->reading = is_reading;
ios->offset = offset;
if (length) {
ore_calc_stripe_info(layout, offset, length, &ios->si);
ios->length = ios->si.length;
ios->nr_pages = ((ios->offset & (PAGE_SIZE - 1)) +
ios->length + PAGE_SIZE - 1) / PAGE_SIZE;
if (layout->parity)
_ore_post_alloc_raid_stuff(ios);
}
return 0;
}
int ore_get_io_state(struct ore_layout *layout, struct ore_components *oc,
struct ore_io_state **pios)
{
return _ore_get_io_state(layout, oc, oc->numdevs, 0, 0, pios);
}
void ore_put_io_state(struct ore_io_state *ios)
{
if (ios) {
unsigned i;
for (i = 0; i < ios->numdevs; i++) {
struct ore_per_dev_state *per_dev = &ios->per_dev[i];
if (per_dev->or)
osd_end_request(per_dev->or);
if (per_dev->bio)
bio_put(per_dev->bio);
}
_ore_free_raid_stuff(ios);
kfree(ios);
}
}
static void _sync_done(struct ore_io_state *ios, void *p)
{
struct completion *waiting = p;
complete(waiting);
}
static void _last_io(struct kref *kref)
{
struct ore_io_state *ios = container_of(
kref, struct ore_io_state, kref);
ios->done(ios, ios->private);
}
static void _done_io(struct osd_request *or, void *p)
{
struct ore_io_state *ios = p;
kref_put(&ios->kref, _last_io);
}
int ore_io_execute(struct ore_io_state *ios)
{
DECLARE_COMPLETION_ONSTACK(wait);
bool sync = (ios->done == NULL);
int i, ret;
if (sync) {
ios->done = _sync_done;
ios->private = &wait;
}
for (i = 0; i < ios->numdevs; i++) {
struct osd_request *or = ios->per_dev[i].or;
if (unlikely(!or))
continue;
ret = osd_finalize_request(or, 0, _ios_cred(ios, i), NULL);
if (unlikely(ret)) {
ORE_DBGMSG("Failed to osd_finalize_request() => %d\n",
ret);
return ret;
}
}
kref_init(&ios->kref);
for (i = 0; i < ios->numdevs; i++) {
struct osd_request *or = ios->per_dev[i].or;
if (unlikely(!or))
continue;
kref_get(&ios->kref);
osd_execute_request_async(or, _done_io, ios);
}
kref_put(&ios->kref, _last_io);
ret = 0;
if (sync) {
wait_for_completion(&wait);
ret = ore_check_io(ios, NULL);
}
return ret;
}
static void _clear_bio(struct bio *bio)
{
struct bio_vec *bv;
unsigned i;
bio_for_each_segment_all(bv, bio, i) {
unsigned this_count = bv->bv_len;
if (likely(PAGE_SIZE == this_count))
clear_highpage(bv->bv_page);
else
zero_user(bv->bv_page, bv->bv_offset, this_count);
}
}
int ore_check_io(struct ore_io_state *ios, ore_on_dev_error on_dev_error)
{
enum osd_err_priority acumulated_osd_err = 0;
int acumulated_lin_err = 0;
int i;
for (i = 0; i < ios->numdevs; i++) {
struct osd_sense_info osi;
struct ore_per_dev_state *per_dev = &ios->per_dev[i];
struct osd_request *or = per_dev->or;
int ret;
if (unlikely(!or))
continue;
ret = osd_req_decode_sense(or, &osi);
if (likely(!ret))
continue;
if ((OSD_ERR_PRI_CLEAR_PAGES == osi.osd_err_pri) &&
per_dev->bio) {
_clear_bio(per_dev->bio);
ORE_DBGMSG("start read offset passed end of file "
"offset=0x%llx, length=0x%llx\n",
_LLU(per_dev->offset),
_LLU(per_dev->length));
continue;
}
if (on_dev_error) {
u64 residual = ios->reading ?
or->in.residual : or->out.residual;
u64 offset = (ios->offset + ios->length) - residual;
unsigned dev = per_dev->dev - ios->oc->first_dev;
struct ore_dev *od = ios->oc->ods[dev];
on_dev_error(ios, od, dev, osi.osd_err_pri,
offset, residual);
}
if (osi.osd_err_pri >= acumulated_osd_err) {
acumulated_osd_err = osi.osd_err_pri;
acumulated_lin_err = ret;
}
}
return acumulated_lin_err;
}
void ore_calc_stripe_info(struct ore_layout *layout, u64 file_offset,
u64 length, struct ore_striping_info *si)
{
u32 stripe_unit = layout->stripe_unit;
u32 group_width = layout->group_width;
u64 group_depth = layout->group_depth;
u32 parity = layout->parity;
u32 D = group_width - parity;
u32 U = D * stripe_unit;
u64 T = U * group_depth;
u64 S = T * layout->group_count;
u64 M = div64_u64(file_offset, S);
u64 LmodS = file_offset - M * S;
u32 G = div64_u64(LmodS, T);
u64 H = LmodS - G * T;
u32 N = div_u64(H, U);
u32 Nlast;
u32 C = (u32)(H - (N * U)) / stripe_unit + G * group_width;
u32 first_dev = C - C % group_width;
div_u64_rem(file_offset, stripe_unit, &si->unit_off);
si->obj_offset = si->unit_off + (N * stripe_unit) +
(M * group_depth * stripe_unit);
si->cur_comp = C - first_dev;
si->cur_pg = si->unit_off / PAGE_SIZE;
if (parity) {
u32 LCMdP = lcm(group_width, parity) / parity;
u32 RxP = (N % LCMdP) * parity;
si->par_dev = (group_width + group_width - parity - RxP) %
group_width + first_dev;
si->dev = (group_width + group_width + C - RxP) %
group_width + first_dev;
si->bytes_in_stripe = U;
si->first_stripe_start = M * S + G * T + N * U;
} else {
si->par_dev = group_width;
si->dev = C;
}
si->dev *= layout->mirrors_p1;
si->par_dev *= layout->mirrors_p1;
si->offset = file_offset;
si->length = T - H;
if (si->length > length)
si->length = length;
Nlast = div_u64(H + si->length + U - 1, U);
si->maxdevUnits = Nlast - N;
si->M = M;
}
int _ore_add_stripe_unit(struct ore_io_state *ios, unsigned *cur_pg,
unsigned pgbase, struct page **pages,
struct ore_per_dev_state *per_dev, int cur_len)
{
unsigned pg = *cur_pg;
struct request_queue *q =
osd_request_queue(_ios_od(ios, per_dev->dev));
unsigned len = cur_len;
int ret;
if (per_dev->bio == NULL) {
unsigned bio_size;
if (!ios->reading) {
bio_size = ios->si.maxdevUnits;
} else {
bio_size = (ios->si.maxdevUnits + 1) *
(ios->layout->group_width - ios->layout->parity) /
ios->layout->group_width;
}
bio_size *= (ios->layout->stripe_unit / PAGE_SIZE);
per_dev->bio = bio_kmalloc(GFP_KERNEL, bio_size);
if (unlikely(!per_dev->bio)) {
ORE_DBGMSG("Failed to allocate BIO size=%u\n",
bio_size);
ret = -ENOMEM;
goto out;
}
}
while (cur_len > 0) {
unsigned pglen = min_t(unsigned, PAGE_SIZE - pgbase, cur_len);
unsigned added_len;
cur_len -= pglen;
added_len = bio_add_pc_page(q, per_dev->bio, pages[pg],
pglen, pgbase);
if (unlikely(pglen != added_len)) {
ORE_DBGMSG("Failed bio_add_pc_page bi_vcnt=0x%x "
"bi_max=0x%x BIO_MAX=0x%x cur_len=0x%x\n",
per_dev->bio->bi_vcnt,
per_dev->bio->bi_max_vecs,
BIO_MAX_PAGES_KMALLOC, cur_len);
ret = -ENOMEM;
goto out;
}
_add_stripe_page(ios->sp2d, &ios->si, pages[pg]);
pgbase = 0;
++pg;
}
BUG_ON(cur_len);
per_dev->length += len;
*cur_pg = pg;
ret = 0;
out:
return ret;
}
static int _add_parity_units(struct ore_io_state *ios,
struct ore_striping_info *si,
unsigned dev, unsigned first_dev,
unsigned mirrors_p1, unsigned devs_in_group,
unsigned cur_len)
{
unsigned do_parity;
int ret = 0;
for (do_parity = ios->layout->parity; do_parity; --do_parity) {
struct ore_per_dev_state *per_dev;
per_dev = &ios->per_dev[dev - first_dev];
if (!per_dev->length && !per_dev->offset) {
per_dev->dev = dev;
per_dev->offset = si->obj_offset - si->unit_off;
}
ret = _ore_add_parity_unit(ios, si, per_dev, cur_len,
do_parity == 1);
if (unlikely(ret))
break;
if (do_parity != 1) {
dev = ((dev + mirrors_p1) % devs_in_group) + first_dev;
si->cur_comp = (si->cur_comp + 1) %
ios->layout->group_width;
}
}
return ret;
}
static int _prepare_for_striping(struct ore_io_state *ios)
{
struct ore_striping_info *si = &ios->si;
unsigned stripe_unit = ios->layout->stripe_unit;
unsigned mirrors_p1 = ios->layout->mirrors_p1;
unsigned group_width = ios->layout->group_width;
unsigned devs_in_group = group_width * mirrors_p1;
unsigned dev = si->dev;
unsigned first_dev = dev - (dev % devs_in_group);
unsigned cur_pg = ios->pages_consumed;
u64 length = ios->length;
int ret = 0;
if (!ios->pages) {
ios->numdevs = ios->layout->mirrors_p1;
return 0;
}
BUG_ON(length > si->length);
while (length) {
struct ore_per_dev_state *per_dev =
&ios->per_dev[dev - first_dev];
unsigned cur_len, page_off = 0;
if (!per_dev->length && !per_dev->offset) {
per_dev->dev = dev;
if (dev == si->dev) {
WARN_ON(dev == si->par_dev);
per_dev->offset = si->obj_offset;
cur_len = stripe_unit - si->unit_off;
page_off = si->unit_off & ~PAGE_MASK;
BUG_ON(page_off && (page_off != ios->pgbase));
} else {
per_dev->offset = si->obj_offset - si->unit_off;
cur_len = stripe_unit;
}
} else {
cur_len = stripe_unit;
}
if (cur_len >= length)
cur_len = length;
ret = _ore_add_stripe_unit(ios, &cur_pg, page_off, ios->pages,
per_dev, cur_len);
if (unlikely(ret))
goto out;
length -= cur_len;
dev = ((dev + mirrors_p1) % devs_in_group) + first_dev;
si->cur_comp = (si->cur_comp + 1) % group_width;
if (unlikely((dev == si->par_dev) || (!length && ios->sp2d))) {
if (!length && ios->sp2d) {
dev = si->par_dev;
si->cur_comp = group_width - ios->layout->parity;
}
ret = _add_parity_units(ios, si, dev, first_dev,
mirrors_p1, devs_in_group,
ios->sp2d ? length : cur_len);
if (unlikely(ret))
goto out;
si->par_dev = (devs_in_group + si->par_dev -
ios->layout->parity * mirrors_p1) %
devs_in_group + first_dev;
si->cur_comp = 0;
si->cur_pg = 0;
si->obj_offset += cur_len;
si->unit_off = 0;
}
}
out:
ios->numdevs = devs_in_group;
ios->pages_consumed = cur_pg;
return ret;
}
int ore_create(struct ore_io_state *ios)
{
int i, ret;
for (i = 0; i < ios->oc->numdevs; i++) {
struct osd_request *or;
or = osd_start_request(_ios_od(ios, i), GFP_KERNEL);
if (unlikely(!or)) {
ORE_ERR("%s: osd_start_request failed\n", __func__);
ret = -ENOMEM;
goto out;
}
ios->per_dev[i].or = or;
ios->numdevs++;
osd_req_create_object(or, _ios_obj(ios, i));
}
ret = ore_io_execute(ios);
out:
return ret;
}
int ore_remove(struct ore_io_state *ios)
{
int i, ret;
for (i = 0; i < ios->oc->numdevs; i++) {
struct osd_request *or;
or = osd_start_request(_ios_od(ios, i), GFP_KERNEL);
if (unlikely(!or)) {
ORE_ERR("%s: osd_start_request failed\n", __func__);
ret = -ENOMEM;
goto out;
}
ios->per_dev[i].or = or;
ios->numdevs++;
osd_req_remove_object(or, _ios_obj(ios, i));
}
ret = ore_io_execute(ios);
out:
return ret;
}
static int _write_mirror(struct ore_io_state *ios, int cur_comp)
{
struct ore_per_dev_state *master_dev = &ios->per_dev[cur_comp];
unsigned dev = ios->per_dev[cur_comp].dev;
unsigned last_comp = cur_comp + ios->layout->mirrors_p1;
int ret = 0;
if (ios->pages && !master_dev->length)
return 0;
for (; cur_comp < last_comp; ++cur_comp, ++dev) {
struct ore_per_dev_state *per_dev = &ios->per_dev[cur_comp];
struct osd_request *or;
or = osd_start_request(_ios_od(ios, dev), GFP_KERNEL);
if (unlikely(!or)) {
ORE_ERR("%s: osd_start_request failed\n", __func__);
ret = -ENOMEM;
goto out;
}
per_dev->or = or;
if (ios->pages) {
struct bio *bio;
if (per_dev != master_dev) {
bio = bio_clone_kmalloc(master_dev->bio,
GFP_KERNEL);
if (unlikely(!bio)) {
ORE_DBGMSG(
"Failed to allocate BIO size=%u\n",
master_dev->bio->bi_max_vecs);
ret = -ENOMEM;
goto out;
}
bio->bi_bdev = NULL;
bio->bi_next = NULL;
per_dev->offset = master_dev->offset;
per_dev->length = master_dev->length;
per_dev->bio = bio;
per_dev->dev = dev;
} else {
bio = master_dev->bio;
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
}
osd_req_write(or, _ios_obj(ios, cur_comp),
per_dev->offset, bio, per_dev->length);
ORE_DBGMSG("write(0x%llx) offset=0x%llx "
"length=0x%llx dev=%d\n",
_LLU(_ios_obj(ios, cur_comp)->id),
_LLU(per_dev->offset),
_LLU(per_dev->length), dev);
} else if (ios->kern_buff) {
per_dev->offset = ios->si.obj_offset;
per_dev->dev = ios->si.dev + dev;
BUG_ON((ios->layout->group_width > 1) &&
(ios->si.unit_off + ios->length >
ios->layout->stripe_unit));
ret = osd_req_write_kern(or, _ios_obj(ios, cur_comp),
per_dev->offset,
ios->kern_buff, ios->length);
if (unlikely(ret))
goto out;
ORE_DBGMSG2("write_kern(0x%llx) offset=0x%llx "
"length=0x%llx dev=%d\n",
_LLU(_ios_obj(ios, cur_comp)->id),
_LLU(per_dev->offset),
_LLU(ios->length), per_dev->dev);
} else {
osd_req_set_attributes(or, _ios_obj(ios, cur_comp));
ORE_DBGMSG2("obj(0x%llx) set_attributes=%d dev=%d\n",
_LLU(_ios_obj(ios, cur_comp)->id),
ios->out_attr_len, dev);
}
if (ios->out_attr)
osd_req_add_set_attr_list(or, ios->out_attr,
ios->out_attr_len);
if (ios->in_attr)
osd_req_add_get_attr_list(or, ios->in_attr,
ios->in_attr_len);
}
out:
return ret;
}
int ore_write(struct ore_io_state *ios)
{
int i;
int ret;
if (unlikely(ios->sp2d && !ios->r4w)) {
WARN_ON_ONCE(1);
return -ENOTSUPP;
}
ret = _prepare_for_striping(ios);
if (unlikely(ret))
return ret;
for (i = 0; i < ios->numdevs; i += ios->layout->mirrors_p1) {
ret = _write_mirror(ios, i);
if (unlikely(ret))
return ret;
}
ret = ore_io_execute(ios);
return ret;
}
int _ore_read_mirror(struct ore_io_state *ios, unsigned cur_comp)
{
struct osd_request *or;
struct ore_per_dev_state *per_dev = &ios->per_dev[cur_comp];
struct osd_obj_id *obj = _ios_obj(ios, cur_comp);
unsigned first_dev = (unsigned)obj->id;
if (ios->pages && !per_dev->length)
return 0;
first_dev = per_dev->dev + first_dev % ios->layout->mirrors_p1;
or = osd_start_request(_ios_od(ios, first_dev), GFP_KERNEL);
if (unlikely(!or)) {
ORE_ERR("%s: osd_start_request failed\n", __func__);
return -ENOMEM;
}
per_dev->or = or;
if (ios->pages) {
if (per_dev->cur_sg) {
_ore_add_sg_seg(per_dev, 0, false);
if (unlikely(!per_dev->cur_sg))
return 0;
osd_req_read_sg(or, obj, per_dev->bio,
per_dev->sglist, per_dev->cur_sg);
} else {
osd_req_read(or, obj, per_dev->offset,
per_dev->bio, per_dev->length);
}
ORE_DBGMSG("read(0x%llx) offset=0x%llx length=0x%llx"
" dev=%d sg_len=%d\n", _LLU(obj->id),
_LLU(per_dev->offset), _LLU(per_dev->length),
first_dev, per_dev->cur_sg);
} else {
BUG_ON(ios->kern_buff);
osd_req_get_attributes(or, obj);
ORE_DBGMSG2("obj(0x%llx) get_attributes=%d dev=%d\n",
_LLU(obj->id),
ios->in_attr_len, first_dev);
}
if (ios->out_attr)
osd_req_add_set_attr_list(or, ios->out_attr, ios->out_attr_len);
if (ios->in_attr)
osd_req_add_get_attr_list(or, ios->in_attr, ios->in_attr_len);
return 0;
}
int ore_read(struct ore_io_state *ios)
{
int i;
int ret;
ret = _prepare_for_striping(ios);
if (unlikely(ret))
return ret;
for (i = 0; i < ios->numdevs; i += ios->layout->mirrors_p1) {
ret = _ore_read_mirror(ios, i);
if (unlikely(ret))
return ret;
}
ret = ore_io_execute(ios);
return ret;
}
int extract_attr_from_ios(struct ore_io_state *ios, struct osd_attr *attr)
{
struct osd_attr cur_attr = {.attr_page = 0};
void *iter = NULL;
int nelem;
do {
nelem = 1;
osd_req_decode_get_attr_list(ios->per_dev[0].or,
&cur_attr, &nelem, &iter);
if ((cur_attr.attr_page == attr->attr_page) &&
(cur_attr.attr_id == attr->attr_id)) {
attr->len = cur_attr.len;
attr->val_ptr = cur_attr.val_ptr;
return 0;
}
} while (iter);
return -EIO;
}
static int _truncate_mirrors(struct ore_io_state *ios, unsigned cur_comp,
struct osd_attr *attr)
{
int last_comp = cur_comp + ios->layout->mirrors_p1;
for (; cur_comp < last_comp; ++cur_comp) {
struct ore_per_dev_state *per_dev = &ios->per_dev[cur_comp];
struct osd_request *or;
or = osd_start_request(_ios_od(ios, cur_comp), GFP_KERNEL);
if (unlikely(!or)) {
ORE_ERR("%s: osd_start_request failed\n", __func__);
return -ENOMEM;
}
per_dev->or = or;
osd_req_set_attributes(or, _ios_obj(ios, cur_comp));
osd_req_add_set_attr_list(or, attr, 1);
}
return 0;
}
static void _calc_trunk_info(struct ore_layout *layout, u64 file_offset,
struct _trunc_info *ti)
{
unsigned stripe_unit = layout->stripe_unit;
ore_calc_stripe_info(layout, file_offset, 0, &ti->si);
ti->prev_group_obj_off = ti->si.M * stripe_unit;
ti->next_group_obj_off = ti->si.M ? (ti->si.M - 1) * stripe_unit : 0;
ti->first_group_dev = ti->si.dev - (ti->si.dev % layout->group_width);
ti->nex_group_dev = ti->first_group_dev + layout->group_width;
}
int ore_truncate(struct ore_layout *layout, struct ore_components *oc,
u64 size)
{
struct ore_io_state *ios;
struct exofs_trunc_attr {
struct osd_attr attr;
__be64 newsize;
} *size_attrs;
struct _trunc_info ti;
int i, ret;
ret = ore_get_io_state(layout, oc, &ios);
if (unlikely(ret))
return ret;
_calc_trunk_info(ios->layout, size, &ti);
size_attrs = kcalloc(ios->oc->numdevs, sizeof(*size_attrs),
GFP_KERNEL);
if (unlikely(!size_attrs)) {
ret = -ENOMEM;
goto out;
}
ios->numdevs = ios->oc->numdevs;
for (i = 0; i < ios->numdevs; ++i) {
struct exofs_trunc_attr *size_attr = &size_attrs[i];
u64 obj_size;
if (i < ti.first_group_dev)
obj_size = ti.prev_group_obj_off;
else if (i >= ti.nex_group_dev)
obj_size = ti.next_group_obj_off;
else if (i < ti.si.dev)
obj_size = ti.si.obj_offset +
ios->layout->stripe_unit - ti.si.unit_off;
else if (i == ti.si.dev)
obj_size = ti.si.obj_offset;
else
obj_size = ti.si.obj_offset - ti.si.unit_off;
size_attr->newsize = cpu_to_be64(obj_size);
size_attr->attr = g_attr_logical_length;
size_attr->attr.val_ptr = &size_attr->newsize;
ORE_DBGMSG2("trunc(0x%llx) obj_offset=0x%llx dev=%d\n",
_LLU(oc->comps->obj.id), _LLU(obj_size), i);
ret = _truncate_mirrors(ios, i * ios->layout->mirrors_p1,
&size_attr->attr);
if (unlikely(ret))
goto out;
}
ret = ore_io_execute(ios);
out:
kfree(size_attrs);
ore_put_io_state(ios);
return ret;
}
