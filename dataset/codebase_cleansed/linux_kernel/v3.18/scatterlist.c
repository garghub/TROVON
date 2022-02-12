struct scatterlist *sg_next(struct scatterlist *sg)
{
#ifdef CONFIG_DEBUG_SG
BUG_ON(sg->sg_magic != SG_MAGIC);
#endif
if (sg_is_last(sg))
return NULL;
sg++;
if (unlikely(sg_is_chain(sg)))
sg = sg_chain_ptr(sg);
return sg;
}
int sg_nents(struct scatterlist *sg)
{
int nents;
for (nents = 0; sg; sg = sg_next(sg))
nents++;
return nents;
}
struct scatterlist *sg_last(struct scatterlist *sgl, unsigned int nents)
{
#ifndef CONFIG_ARCH_HAS_SG_CHAIN
struct scatterlist *ret = &sgl[nents - 1];
#else
struct scatterlist *sg, *ret = NULL;
unsigned int i;
for_each_sg(sgl, sg, nents, i)
ret = sg;
#endif
#ifdef CONFIG_DEBUG_SG
BUG_ON(sgl[0].sg_magic != SG_MAGIC);
BUG_ON(!sg_is_last(ret));
#endif
return ret;
}
void sg_init_table(struct scatterlist *sgl, unsigned int nents)
{
memset(sgl, 0, sizeof(*sgl) * nents);
#ifdef CONFIG_DEBUG_SG
{
unsigned int i;
for (i = 0; i < nents; i++)
sgl[i].sg_magic = SG_MAGIC;
}
#endif
sg_mark_end(&sgl[nents - 1]);
}
void sg_init_one(struct scatterlist *sg, const void *buf, unsigned int buflen)
{
sg_init_table(sg, 1);
sg_set_buf(sg, buf, buflen);
}
static struct scatterlist *sg_kmalloc(unsigned int nents, gfp_t gfp_mask)
{
if (nents == SG_MAX_SINGLE_ALLOC) {
void *ptr = (void *) __get_free_page(gfp_mask);
kmemleak_alloc(ptr, PAGE_SIZE, 1, gfp_mask);
return ptr;
} else
return kmalloc(nents * sizeof(struct scatterlist), gfp_mask);
}
static void sg_kfree(struct scatterlist *sg, unsigned int nents)
{
if (nents == SG_MAX_SINGLE_ALLOC) {
kmemleak_free(sg);
free_page((unsigned long) sg);
} else
kfree(sg);
}
void __sg_free_table(struct sg_table *table, unsigned int max_ents,
bool skip_first_chunk, sg_free_fn *free_fn)
{
struct scatterlist *sgl, *next;
if (unlikely(!table->sgl))
return;
sgl = table->sgl;
while (table->orig_nents) {
unsigned int alloc_size = table->orig_nents;
unsigned int sg_size;
if (alloc_size > max_ents) {
next = sg_chain_ptr(&sgl[max_ents - 1]);
alloc_size = max_ents;
sg_size = alloc_size - 1;
} else {
sg_size = alloc_size;
next = NULL;
}
table->orig_nents -= sg_size;
if (skip_first_chunk)
skip_first_chunk = false;
else
free_fn(sgl, alloc_size);
sgl = next;
}
table->sgl = NULL;
}
void sg_free_table(struct sg_table *table)
{
__sg_free_table(table, SG_MAX_SINGLE_ALLOC, false, sg_kfree);
}
int __sg_alloc_table(struct sg_table *table, unsigned int nents,
unsigned int max_ents, struct scatterlist *first_chunk,
gfp_t gfp_mask, sg_alloc_fn *alloc_fn)
{
struct scatterlist *sg, *prv;
unsigned int left;
memset(table, 0, sizeof(*table));
if (nents == 0)
return -EINVAL;
#ifndef CONFIG_ARCH_HAS_SG_CHAIN
if (WARN_ON_ONCE(nents > max_ents))
return -EINVAL;
#endif
left = nents;
prv = NULL;
do {
unsigned int sg_size, alloc_size = left;
if (alloc_size > max_ents) {
alloc_size = max_ents;
sg_size = alloc_size - 1;
} else
sg_size = alloc_size;
left -= sg_size;
if (first_chunk) {
sg = first_chunk;
first_chunk = NULL;
} else {
sg = alloc_fn(alloc_size, gfp_mask);
}
if (unlikely(!sg)) {
if (prv)
table->nents = ++table->orig_nents;
return -ENOMEM;
}
sg_init_table(sg, alloc_size);
table->nents = table->orig_nents += sg_size;
if (prv)
sg_chain(prv, max_ents, sg);
else
table->sgl = sg;
if (!left)
sg_mark_end(&sg[sg_size - 1]);
prv = sg;
} while (left);
return 0;
}
int sg_alloc_table(struct sg_table *table, unsigned int nents, gfp_t gfp_mask)
{
int ret;
ret = __sg_alloc_table(table, nents, SG_MAX_SINGLE_ALLOC,
NULL, gfp_mask, sg_kmalloc);
if (unlikely(ret))
__sg_free_table(table, SG_MAX_SINGLE_ALLOC, false, sg_kfree);
return ret;
}
int sg_alloc_table_from_pages(struct sg_table *sgt,
struct page **pages, unsigned int n_pages,
unsigned long offset, unsigned long size,
gfp_t gfp_mask)
{
unsigned int chunks;
unsigned int i;
unsigned int cur_page;
int ret;
struct scatterlist *s;
chunks = 1;
for (i = 1; i < n_pages; ++i)
if (page_to_pfn(pages[i]) != page_to_pfn(pages[i - 1]) + 1)
++chunks;
ret = sg_alloc_table(sgt, chunks, gfp_mask);
if (unlikely(ret))
return ret;
cur_page = 0;
for_each_sg(sgt->sgl, s, sgt->orig_nents, i) {
unsigned long chunk_size;
unsigned int j;
for (j = cur_page + 1; j < n_pages; ++j)
if (page_to_pfn(pages[j]) !=
page_to_pfn(pages[j - 1]) + 1)
break;
chunk_size = ((j - cur_page) << PAGE_SHIFT) - offset;
sg_set_page(s, pages[cur_page], min(size, chunk_size), offset);
size -= chunk_size;
offset = 0;
cur_page = j;
}
return 0;
}
void __sg_page_iter_start(struct sg_page_iter *piter,
struct scatterlist *sglist, unsigned int nents,
unsigned long pgoffset)
{
piter->__pg_advance = 0;
piter->__nents = nents;
piter->sg = sglist;
piter->sg_pgoffset = pgoffset;
}
static int sg_page_count(struct scatterlist *sg)
{
return PAGE_ALIGN(sg->offset + sg->length) >> PAGE_SHIFT;
}
bool __sg_page_iter_next(struct sg_page_iter *piter)
{
if (!piter->__nents || !piter->sg)
return false;
piter->sg_pgoffset += piter->__pg_advance;
piter->__pg_advance = 1;
while (piter->sg_pgoffset >= sg_page_count(piter->sg)) {
piter->sg_pgoffset -= sg_page_count(piter->sg);
piter->sg = sg_next(piter->sg);
if (!--piter->__nents || !piter->sg)
return false;
}
return true;
}
void sg_miter_start(struct sg_mapping_iter *miter, struct scatterlist *sgl,
unsigned int nents, unsigned int flags)
{
memset(miter, 0, sizeof(struct sg_mapping_iter));
__sg_page_iter_start(&miter->piter, sgl, nents, 0);
WARN_ON(!(flags & (SG_MITER_TO_SG | SG_MITER_FROM_SG)));
miter->__flags = flags;
}
static bool sg_miter_get_next_page(struct sg_mapping_iter *miter)
{
if (!miter->__remaining) {
struct scatterlist *sg;
unsigned long pgoffset;
if (!__sg_page_iter_next(&miter->piter))
return false;
sg = miter->piter.sg;
pgoffset = miter->piter.sg_pgoffset;
miter->__offset = pgoffset ? 0 : sg->offset;
miter->__remaining = sg->offset + sg->length -
(pgoffset << PAGE_SHIFT) - miter->__offset;
miter->__remaining = min_t(unsigned long, miter->__remaining,
PAGE_SIZE - miter->__offset);
}
return true;
}
bool sg_miter_skip(struct sg_mapping_iter *miter, off_t offset)
{
sg_miter_stop(miter);
while (offset) {
off_t consumed;
if (!sg_miter_get_next_page(miter))
return false;
consumed = min_t(off_t, offset, miter->__remaining);
miter->__offset += consumed;
miter->__remaining -= consumed;
offset -= consumed;
}
return true;
}
bool sg_miter_next(struct sg_mapping_iter *miter)
{
sg_miter_stop(miter);
if (!sg_miter_get_next_page(miter))
return false;
miter->page = sg_page_iter_page(&miter->piter);
miter->consumed = miter->length = miter->__remaining;
if (miter->__flags & SG_MITER_ATOMIC)
miter->addr = kmap_atomic(miter->page) + miter->__offset;
else
miter->addr = kmap(miter->page) + miter->__offset;
return true;
}
void sg_miter_stop(struct sg_mapping_iter *miter)
{
WARN_ON(miter->consumed > miter->length);
if (miter->addr) {
miter->__offset += miter->consumed;
miter->__remaining -= miter->consumed;
if ((miter->__flags & SG_MITER_TO_SG) &&
!PageSlab(miter->page))
flush_kernel_dcache_page(miter->page);
if (miter->__flags & SG_MITER_ATOMIC) {
WARN_ON_ONCE(preemptible());
kunmap_atomic(miter->addr);
} else
kunmap(miter->page);
miter->page = NULL;
miter->addr = NULL;
miter->length = 0;
miter->consumed = 0;
}
}
static size_t sg_copy_buffer(struct scatterlist *sgl, unsigned int nents,
void *buf, size_t buflen, off_t skip,
bool to_buffer)
{
unsigned int offset = 0;
struct sg_mapping_iter miter;
unsigned long flags;
unsigned int sg_flags = SG_MITER_ATOMIC;
if (to_buffer)
sg_flags |= SG_MITER_FROM_SG;
else
sg_flags |= SG_MITER_TO_SG;
sg_miter_start(&miter, sgl, nents, sg_flags);
if (!sg_miter_skip(&miter, skip))
return false;
local_irq_save(flags);
while (sg_miter_next(&miter) && offset < buflen) {
unsigned int len;
len = min(miter.length, buflen - offset);
if (to_buffer)
memcpy(buf + offset, miter.addr, len);
else
memcpy(miter.addr, buf + offset, len);
offset += len;
}
sg_miter_stop(&miter);
local_irq_restore(flags);
return offset;
}
size_t sg_copy_from_buffer(struct scatterlist *sgl, unsigned int nents,
void *buf, size_t buflen)
{
return sg_copy_buffer(sgl, nents, buf, buflen, 0, false);
}
size_t sg_copy_to_buffer(struct scatterlist *sgl, unsigned int nents,
void *buf, size_t buflen)
{
return sg_copy_buffer(sgl, nents, buf, buflen, 0, true);
}
size_t sg_pcopy_from_buffer(struct scatterlist *sgl, unsigned int nents,
void *buf, size_t buflen, off_t skip)
{
return sg_copy_buffer(sgl, nents, buf, buflen, skip, false);
}
size_t sg_pcopy_to_buffer(struct scatterlist *sgl, unsigned int nents,
void *buf, size_t buflen, off_t skip)
{
return sg_copy_buffer(sgl, nents, buf, buflen, skip, true);
}
