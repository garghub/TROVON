static struct page *_raid_page_alloc(void)
{
return alloc_page(GFP_KERNEL);
}
static void _raid_page_free(struct page *p)
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
__a1pa = kcalloc(num_a1pa, sizeof__a1pa, GFP_KERNEL);
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
int p, c;
if (!sp2d->needed)
return;
for (c = data_devs - 1; c >= 0; --c)
for (p = sp2d->pages_in_unit - 1; p >= 0; --p) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
if (_1ps->page_is_read[c]) {
struct page *page = _1ps->pages[c];
r4w->put_page(priv, page);
_1ps->page_is_read[c] = false;
}
}
for (p = 0; p < sp2d->pages_in_unit; p++) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
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
int p;
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
unsigned tx_flags = ASYNC_TX_ACK;
if (sp2d->parity == 1)
tx_flags |= ASYNC_TX_XOR_ZERO_DST;
for (p = 0; p < sp2d->pages_in_unit; p++) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
if (!_1ps->write_count)
continue;
init_async_submit(&_1ps->submit, tx_flags,
NULL, NULL, NULL, (addr_conv_t *)_1ps->scribble);
if (sp2d->parity == 1)
_1ps->tx = async_xor(_1ps->pages[sp2d->data_devs],
_1ps->pages, 0, sp2d->data_devs,
PAGE_SIZE, &_1ps->submit);
else
_1ps->tx = async_gen_syndrome(_1ps->pages, 0,
sp2d->data_devs + sp2d->parity,
PAGE_SIZE, &_1ps->submit);
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
static int _add_to_r4w(struct ore_io_state *ios, struct ore_striping_info *si,
struct page *page, unsigned pg_len)
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
added_len = bio_add_pc_page(q, per_dev->bio, page, pg_len,
si->obj_offset % PAGE_SIZE);
if (unlikely(added_len != pg_len)) {
ORE_DBGMSG("Failed to bio_add_pc_page bi_vcnt=%d\n",
per_dev->bio->bi_vcnt);
return -ENOMEM;
}
per_dev->length += pg_len;
return 0;
}
static int _add_to_r4w_first_page(struct ore_io_state *ios, struct page *page)
{
struct ore_striping_info si;
unsigned pg_len;
ore_calc_stripe_info(ios->layout, ios->offset, 0, &si);
pg_len = si.obj_offset % PAGE_SIZE;
si.obj_offset -= pg_len;
ORE_DBGMSG("offset=0x%llx len=0x%x index=0x%lx dev=%x\n",
_LLU(si.obj_offset), pg_len, page->index, si.dev);
return _add_to_r4w(ios, &si, page, pg_len);
}
static int _add_to_r4w_last_page(struct ore_io_state *ios, u64 *offset)
{
struct ore_striping_info si;
struct page *page;
unsigned pg_len, p, c;
ore_calc_stripe_info(ios->layout, *offset, 0, &si);
p = si.cur_pg;
c = si.cur_comp;
page = ios->sp2d->_1p_stripes[p].pages[c];
pg_len = PAGE_SIZE - (si.unit_off % PAGE_SIZE);
*offset += pg_len;
ORE_DBGMSG("p=%d, c=%d next-offset=0x%llx len=0x%x dev=%x par_dev=%d\n",
p, c, _LLU(*offset), pg_len, si.dev, si.par_dev);
BUG_ON(!page);
return _add_to_r4w(ios, &si, page, pg_len);
}
static void _mark_read4write_pages_uptodate(struct ore_io_state *ios, int ret)
{
struct bio_vec *bv;
unsigned i, d;
for (d = 0; d < ios->numdevs; d++) {
struct bio *bio = ios->per_dev[d].bio;
if (!bio)
continue;
bio_for_each_segment_all(bv, bio, i) {
struct page *page = bv->bv_page;
SetPageUptodate(page);
if (PageError(page))
ClearPageError(page);
}
}
}
static int _read_4_write_first_stripe(struct ore_io_state *ios)
{
struct ore_striping_info read_si;
struct __stripe_pages_2d *sp2d = ios->sp2d;
u64 offset = ios->si.first_stripe_start;
unsigned c, p, min_p = sp2d->pages_in_unit, max_p = -1;
if (offset == ios->offset)
goto read_last_stripe;
min_p = _sp2d_min_pg(sp2d);
max_p = _sp2d_max_pg(sp2d);
ORE_DBGMSG("stripe_start=0x%llx ios->offset=0x%llx min_p=%d max_p=%d\n",
offset, ios->offset, min_p, max_p);
for (c = 0; ; c++) {
ore_calc_stripe_info(ios->layout, offset, 0, &read_si);
read_si.obj_offset += min_p * PAGE_SIZE;
offset += min_p * PAGE_SIZE;
for (p = min_p; p <= max_p; p++) {
struct __1_page_stripe *_1ps = &sp2d->_1p_stripes[p];
struct page **pp = &_1ps->pages[c];
bool uptodate;
if (*pp) {
if (ios->offset % PAGE_SIZE)
_add_to_r4w_first_page(ios, *pp);
goto read_last_stripe;
}
*pp = ios->r4w->get_page(ios->private, offset,
&uptodate);
if (unlikely(!*pp))
return -ENOMEM;
if (!uptodate)
_add_to_r4w(ios, &read_si, *pp, PAGE_SIZE);
_1ps->page_is_read[c] = true;
read_si.obj_offset += PAGE_SIZE;
offset += PAGE_SIZE;
}
offset += (sp2d->pages_in_unit - p) * PAGE_SIZE;
}
read_last_stripe:
return 0;
}
static int _read_4_write_last_stripe(struct ore_io_state *ios)
{
struct ore_striping_info read_si;
struct __stripe_pages_2d *sp2d = ios->sp2d;
u64 offset;
u64 last_stripe_end;
unsigned bytes_in_stripe = ios->si.bytes_in_stripe;
unsigned c, p, min_p = sp2d->pages_in_unit, max_p = -1;
offset = ios->offset + ios->length;
if (offset % PAGE_SIZE)
_add_to_r4w_last_page(ios, &offset);
last_stripe_end = div_u64(offset + bytes_in_stripe - 1, bytes_in_stripe)
* bytes_in_stripe;
if (offset == last_stripe_end)
goto read_it;
ore_calc_stripe_info(ios->layout, offset, 0, &read_si);
p = read_si.cur_pg;
c = read_si.cur_comp;
if (min_p == sp2d->pages_in_unit) {
min_p = _sp2d_min_pg(sp2d);
max_p = _sp2d_max_pg(sp2d);
}
ORE_DBGMSG("offset=0x%llx stripe_end=0x%llx min_p=%d max_p=%d\n",
offset, last_stripe_end, min_p, max_p);
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
_add_to_r4w(ios, &read_si, page, PAGE_SIZE);
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
return 0;
}
static int _read_4_write_execute(struct ore_io_state *ios)
{
struct ore_io_state *ios_read;
unsigned i;
int ret;
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
ore_put_io_state(ios_read);
ios->ios_read_4_write = NULL;
return 0;
}
int _ore_add_parity_unit(struct ore_io_state *ios,
struct ore_striping_info *si,
struct ore_per_dev_state *per_dev,
unsigned cur_len, bool do_xor)
{
if (ios->reading) {
if (per_dev->cur_sg >= ios->sgs_per_dev) {
ORE_DBGMSG("cur_sg(%d) >= sgs_per_dev(%d)\n" ,
per_dev->cur_sg, ios->sgs_per_dev);
return -ENOMEM;
}
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
if (!per_dev->length) {
per_dev->offset += si->cur_pg * PAGE_SIZE;
if (do_xor)
_read_4_write_first_stripe(ios);
}
if (!cur_len && do_xor)
_read_4_write_last_stripe(ios);
_read_4_write_execute(ios);
for (i = 0; i < num_pages; i++) {
pages[i] = _raid_page_alloc();
if (unlikely(!pages[i]))
return -ENOMEM;
++(ios->cur_par_page);
}
BUG_ON(si->cur_comp < sp2d->data_devs);
BUG_ON(si->cur_pg + num_pages > sp2d->pages_in_unit);
ret = _ore_add_stripe_unit(ios, &array_start, 0, pages,
per_dev, num_pages * PAGE_SIZE);
if (unlikely(ret))
return ret;
if (do_xor) {
_gen_xor_unit(sp2d);
_sp2d_reset(sp2d, ios->r4w, ios->private);
}
}
return 0;
}
int _ore_post_alloc_raid_stuff(struct ore_io_state *ios)
{
if (ios->parity_pages) {
struct ore_layout *layout = ios->layout;
unsigned pages_in_unit = layout->stripe_unit / PAGE_SIZE;
if (_sp2d_alloc(pages_in_unit, layout->group_width,
layout->parity, &ios->sp2d)) {
return -ENOMEM;
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
