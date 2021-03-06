struct page *_raid_page_alloc(void)
{
return alloc_page(GFP_KERNEL);
}
void _raid_page_free(struct page *p)
{
__free_page(p);
}
static int _sp2d_alloc(unsigned pages_in_unit, unsigned group_width,
unsigned parity, struct __stripe_pages_2d **psp2d)
{
struct __stripe_pages_2d *sp2d;
unsigned data_devs = group_width - parity;
struct _alloc_all_bytes {
struct __alloc_stripe_pages_2d {
struct __stripe_pages_2d sp2d;
struct __1_page_stripe _1p_stripes[pages_in_unit];
} __asp2d;
struct __alloc_1p_arrays {
struct page *pages[group_width];
struct page *scribble[group_width];
char page_is_read[data_devs];
} __a1pa[pages_in_unit];
} *_aab;
struct __alloc_1p_arrays *__a1pa;
struct __alloc_1p_arrays *__a1pa_end;
const unsigned sizeof__a1pa = sizeof(_aab->__a1pa[0]);
unsigned num_a1pa, alloc_size, i;
BUG_ON(sizeof(_aab->__asp2d) > PAGE_SIZE);
BUG_ON(sizeof__a1pa > PAGE_SIZE);
if (sizeof(*_aab) > PAGE_SIZE) {
num_a1pa = (PAGE_SIZE - sizeof(_aab->__asp2d)) / sizeof__a1pa;
alloc_size = sizeof(_aab->__asp2d) + sizeof__a1pa * num_a1pa;
} else {
num_a1pa = pages_in_unit;
alloc_size = sizeof(*_aab);
}
_aab = kzalloc(alloc_size, GFP_KERNEL);
if (unlikely(!_aab)) {
ORE_DBGMSG("!! Failed to alloc sp2d size=%d\n", alloc_size);
return -ENOMEM;
}
sp2d = &_aab->__asp2d.sp2d;
*psp2d = sp2d;
__a1pa = _aab->__a1pa;
__a1pa_end = __a1pa + num_a1pa;
for (i = 0; i < pages_in_unit; ++i) {
if (unlikely(__a1pa >= __a1pa_end)) {
num_a1pa = min_t(unsigned, PAGE_SIZE / sizeof__a1pa,
pages_in_unit - i);
__a1pa = kzalloc(num_a1pa * sizeof__a1pa, GFP_KERNEL);
if (unlikely(!__a1pa)) {
ORE_DBGMSG("!! Failed to _alloc_1p_arrays=%d\n",
num_a1pa);
return -ENOMEM;
}
__a1pa_end = __a1pa + num_a1pa;
sp2d->_1p_stripes[i].alloc = true;
}
sp2d->_1p_stripes[i].pages = __a1pa->pages;
sp2d->_1p_stripes[i].scribble = __a1pa->scribble ;
sp2d->_1p_stripes[i].page_is_read = __a1pa->page_is_read;
++__a1pa;
}
sp2d->parity = parity;
sp2d->data_devs = data_devs;
sp2d->pages_in_unit = pages_in_unit;
return 0;
}
static void _sp2d_reset(struct __stripe_pages_2d *sp2d,
const struct _ore_r4w_op *r4w, void *priv)
{
unsigned data_devs = sp2d->data_devs;
unsigned group_width = data_devs + sp2d->parity;
unsigned p;
if (!sp2d->needed)
return;
for (p = 0; p < sp2d->pages_in_unit; p++) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
if (_1ps->write_count < group_width) {
unsigned c;
for (c = 0; c < data_devs; c++)
if (_1ps->page_is_read[c]) {
struct page *page = _1ps->pages[c];
r4w->put_page(priv, page);
_1ps->page_is_read[c] = false;
}
}
memset(_1ps->pages, 0, group_width * sizeof(*_1ps->pages));
_1ps->write_count = 0;
_1ps->tx = NULL;
}
sp2d->needed = false;
}
static void _sp2d_free(struct __stripe_pages_2d *sp2d)
{
unsigned i;
if (!sp2d)
return;
for (i = 0; i < sp2d->pages_in_unit; ++i) {
if (sp2d->_1p_stripes[i].alloc)
kfree(sp2d->_1p_stripes[i].pages);
}
kfree(sp2d);
}
static unsigned _sp2d_min_pg(struct __stripe_pages_2d *sp2d)
{
unsigned p;
for (p = 0; p < sp2d->pages_in_unit; p++) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
if (_1ps->write_count)
return p;
}
return ~0;
}
static unsigned _sp2d_max_pg(struct __stripe_pages_2d *sp2d)
{
unsigned p;
for (p = sp2d->pages_in_unit - 1; p >= 0; --p) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
if (_1ps->write_count)
return p;
}
return ~0;
}
static void _gen_xor_unit(struct __stripe_pages_2d *sp2d)
{
unsigned p;
for (p = 0; p < sp2d->pages_in_unit; p++) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
if (!_1ps->write_count)
continue;
init_async_submit(&_1ps->submit,
ASYNC_TX_XOR_ZERO_DST | ASYNC_TX_ACK,
NULL,
NULL, NULL,
(addr_conv_t *)_1ps->scribble);
_1ps->tx = async_xor(_1ps->pages[sp2d->data_devs], _1ps->pages,
0, sp2d->data_devs, PAGE_SIZE,
&_1ps->submit);
}
for (p = 0; p < sp2d->pages_in_unit; p++) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
async_tx_issue_pending(_1ps->tx);
}
}
void _ore_add_stripe_page(struct __stripe_pages_2d *sp2d,
struct ore_striping_info *si, struct page *page)
{
struct __1_page_stripe *_1ps;
sp2d->needed = true;
_1ps = &sp2d->_1p_stripes[si->cur_pg];
_1ps->pages[si->cur_comp] = page;
++_1ps->write_count;
si->cur_pg = (si->cur_pg + 1) % sp2d->pages_in_unit;
}
void _ore_add_sg_seg(struct ore_per_dev_state *per_dev, unsigned cur_len,
bool not_last)
{
struct osd_sg_entry *sge;
ORE_DBGMSG("dev=%d cur_len=0x%x not_last=%d cur_sg=%d "
"offset=0x%llx length=0x%x last_sgs_total=0x%x\n",
per_dev->dev, cur_len, not_last, per_dev->cur_sg,
_LLU(per_dev->offset), per_dev->length,
per_dev->last_sgs_total);
if (!per_dev->cur_sg) {
sge = per_dev->sglist;
if (per_dev->length) {
++per_dev->cur_sg;
sge->offset = per_dev->offset;
sge->len = per_dev->length;
} else {
per_dev->offset += cur_len;
return;
}
} else {
sge = &per_dev->sglist[per_dev->cur_sg - 1];
sge->len = per_dev->length - per_dev->last_sgs_total;
}
if (not_last) {
struct osd_sg_entry *next_sge = sge + 1;
++per_dev->cur_sg;
next_sge->offset = sge->offset + sge->len + cur_len;
per_dev->last_sgs_total = per_dev->length;
next_sge->len = 0;
} else if (!sge->len) {
--per_dev->cur_sg;
}
}
static int _alloc_read_4_write(struct ore_io_state *ios)
{
struct ore_layout *layout = ios->layout;
int ret;
unsigned sgs_per_dev = ios->sp2d->pages_in_unit + 2;
ret = _ore_get_io_state(layout, ios->oc,
layout->group_width * layout->mirrors_p1,
sgs_per_dev, 0, &ios->ios_read_4_write);
return ret;
}
static int _add_to_read_4_write(struct ore_io_state *ios,
struct ore_striping_info *si, struct page *page)
{
struct request_queue *q;
struct ore_per_dev_state *per_dev;
struct ore_io_state *read_ios;
unsigned first_dev = si->dev - (si->dev %
(ios->layout->group_width * ios->layout->mirrors_p1));
unsigned comp = si->dev - first_dev;
unsigned added_len;
if (!ios->ios_read_4_write) {
int ret = _alloc_read_4_write(ios);
if (unlikely(ret))
return ret;
}
read_ios = ios->ios_read_4_write;
read_ios->numdevs = ios->layout->group_width * ios->layout->mirrors_p1;
per_dev = &read_ios->per_dev[comp];
if (!per_dev->length) {
per_dev->bio = bio_kmalloc(GFP_KERNEL,
ios->sp2d->pages_in_unit);
if (unlikely(!per_dev->bio)) {
ORE_DBGMSG("Failed to allocate BIO size=%u\n",
ios->sp2d->pages_in_unit);
return -ENOMEM;
}
per_dev->offset = si->obj_offset;
per_dev->dev = si->dev;
} else if (si->obj_offset != (per_dev->offset + per_dev->length)) {
u64 gap = si->obj_offset - (per_dev->offset + per_dev->length);
_ore_add_sg_seg(per_dev, gap, true);
}
q = osd_request_queue(ore_comp_dev(read_ios->oc, per_dev->dev));
added_len = bio_add_pc_page(q, per_dev->bio, page, PAGE_SIZE, 0);
if (unlikely(added_len != PAGE_SIZE)) {
ORE_DBGMSG("Failed to bio_add_pc_page bi_vcnt=%d\n",
per_dev->bio->bi_vcnt);
return -ENOMEM;
}
per_dev->length += PAGE_SIZE;
return 0;
}
static void _mark_read4write_pages_uptodate(struct ore_io_state *ios, int ret)
{
struct bio_vec *bv;
unsigned i, d;
for (d = 0; d < ios->numdevs; d++) {
struct bio *bio = ios->per_dev[d].bio;
if (!bio)
continue;
__bio_for_each_segment(bv, bio, i, 0) {
struct page *page = bv->bv_page;
SetPageUptodate(page);
if (PageError(page))
ClearPageError(page);
}
}
}
static int _read_4_write(struct ore_io_state *ios)
{
struct ore_io_state *ios_read;
struct ore_striping_info read_si;
struct __stripe_pages_2d *sp2d = ios->sp2d;
u64 offset = ios->si.first_stripe_start;
u64 last_stripe_end;
unsigned bytes_in_stripe = ios->si.bytes_in_stripe;
unsigned i, c, p, min_p = sp2d->pages_in_unit, max_p = -1;
int ret;
if (offset == ios->offset)
goto read_last_stripe;
min_p = _sp2d_min_pg(sp2d);
max_p = _sp2d_max_pg(sp2d);
for (c = 0; ; c++) {
ore_calc_stripe_info(ios->layout, offset, 0, &read_si);
read_si.obj_offset += min_p * PAGE_SIZE;
offset += min_p * PAGE_SIZE;
for (p = min_p; p <= max_p; p++) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
struct page **pp = &_1ps->pages[c];
bool uptodate;
if (*pp)
goto read_last_stripe;
*pp = ios->r4w->get_page(ios->private, offset,
&uptodate);
if (unlikely(!*pp))
return -ENOMEM;
if (!uptodate)
_add_to_read_4_write(ios, &read_si, *pp);
_1ps->page_is_read[c] = true;
read_si.obj_offset += PAGE_SIZE;
offset += PAGE_SIZE;
}
offset += (sp2d->pages_in_unit - p) * PAGE_SIZE;
}
read_last_stripe:
offset = ios->offset + (ios->length + PAGE_SIZE - 1) /
PAGE_SIZE * PAGE_SIZE;
last_stripe_end = div_u64(offset + bytes_in_stripe - 1, bytes_in_stripe)
* bytes_in_stripe;
if (offset == last_stripe_end)
goto read_it;
ore_calc_stripe_info(ios->layout, offset, 0, &read_si);
p = read_si.unit_off / PAGE_SIZE;
c = _dev_order(ios->layout->group_width * ios->layout->mirrors_p1,
ios->layout->mirrors_p1, read_si.par_dev, read_si.dev);
BUG_ON(ios->si.first_stripe_start + bytes_in_stripe != last_stripe_end);
if (min_p == sp2d->pages_in_unit) {
min_p = _sp2d_min_pg(sp2d);
max_p = _sp2d_max_pg(sp2d);
}
while (offset < last_stripe_end) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
if ((min_p <= p) && (p <= max_p)) {
struct page *page;
bool uptodate;
BUG_ON(_1ps->pages[c]);
page = ios->r4w->get_page(ios->private, offset,
&uptodate);
if (unlikely(!page))
return -ENOMEM;
_1ps->pages[c] = page;
_1ps->page_is_read[c] = true;
if (!uptodate)
_add_to_read_4_write(ios, &read_si, page);
}
offset += PAGE_SIZE;
if (p == (sp2d->pages_in_unit - 1)) {
++c;
p = 0;
ore_calc_stripe_info(ios->layout, offset, 0, &read_si);
} else {
read_si.obj_offset += PAGE_SIZE;
++p;
}
}
read_it:
ios_read = ios->ios_read_4_write;
if (!ios_read)
return 0;
ios_read->pages = ios->pages;
for (i = 0; i < ios_read->numdevs; i += ios_read->layout->mirrors_p1) {
ret = _ore_read_mirror(ios_read, i);
if (unlikely(ret))
return ret;
}
ret = ore_io_execute(ios_read);
if (unlikely(ret)) {
ORE_DBGMSG("!! ore_io_execute => %d\n", ret);
return ret;
}
_mark_read4write_pages_uptodate(ios_read, ret);
return 0;
}
int _ore_add_parity_unit(struct ore_io_state *ios,
struct ore_striping_info *si,
struct ore_per_dev_state *per_dev,
unsigned cur_len)
{
if (ios->reading) {
BUG_ON(per_dev->cur_sg >= ios->sgs_per_dev);
_ore_add_sg_seg(per_dev, cur_len, true);
} else {
struct __stripe_pages_2d *sp2d = ios->sp2d;
struct page **pages = ios->parity_pages + ios->cur_par_page;
unsigned num_pages;
unsigned array_start = 0;
unsigned i;
int ret;
si->cur_pg = _sp2d_min_pg(sp2d);
num_pages = _sp2d_max_pg(sp2d) + 1 - si->cur_pg;
if (!cur_len)
si->cur_comp = sp2d->data_devs;
if (!per_dev->length) {
per_dev->offset += si->cur_pg * PAGE_SIZE;
_read_4_write(ios);
}
for (i = 0; i < num_pages; i++) {
pages[i] = _raid_page_alloc();
if (unlikely(!pages[i]))
return -ENOMEM;
++(ios->cur_par_page);
}
BUG_ON(si->cur_comp != sp2d->data_devs);
BUG_ON(si->cur_pg + num_pages > sp2d->pages_in_unit);
ret = _ore_add_stripe_unit(ios, &array_start, 0, pages,
per_dev, num_pages * PAGE_SIZE);
if (unlikely(ret))
return ret;
_gen_xor_unit(sp2d);
_sp2d_reset(sp2d, ios->r4w, ios->private);
}
return 0;
}
int _ore_post_alloc_raid_stuff(struct ore_io_state *ios)
{
struct ore_layout *layout = ios->layout;
if (ios->parity_pages) {
unsigned pages_in_unit = layout->stripe_unit / PAGE_SIZE;
unsigned stripe_size = ios->si.bytes_in_stripe;
u64 last_stripe, first_stripe;
if (_sp2d_alloc(pages_in_unit, layout->group_width,
layout->parity, &ios->sp2d)) {
return -ENOMEM;
}
BUG_ON(ios->offset % PAGE_SIZE);
first_stripe = div_u64(ios->offset, stripe_size);
last_stripe = div_u64(ios->offset + ios->length, stripe_size);
if (last_stripe != first_stripe) {
ios->length = last_stripe * stripe_size - ios->offset;
BUG_ON(!ios->length);
ios->nr_pages = (ios->length + PAGE_SIZE - 1) /
PAGE_SIZE;
ios->si.length = ios->length;
}
}
return 0;
}
void _ore_free_raid_stuff(struct ore_io_state *ios)
{
if (ios->sp2d) {
unsigned i;
for (i = 0; i < ios->cur_par_page; i++) {
struct page *page = ios->parity_pages[i];
if (page)
_raid_page_free(page);
}
if (ios->extra_part_alloc)
kfree(ios->parity_pages);
_sp2d_reset(ios->sp2d, ios->r4w, ios->private);
_sp2d_free(ios->sp2d);
} else {
if (ios->extra_part_alloc)
kfree(ios->per_dev[0].sglist);
}
if (ios->ios_read_4_write)
ore_put_io_state(ios->ios_read_4_write);
}
