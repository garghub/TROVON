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
#ifndef ARCH_HAS_SG_CHAIN
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
sg_free_fn *free_fn)
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
free_fn(sgl, alloc_size);
sgl = next;
}
table->sgl = NULL;
}
void sg_free_table(struct sg_table *table)
{
__sg_free_table(table, SG_MAX_SINGLE_ALLOC, sg_kfree);
}
int __sg_alloc_table(struct sg_table *table, unsigned int nents,
unsigned int max_ents, gfp_t gfp_mask,
sg_alloc_fn *alloc_fn)
{
struct scatterlist *sg, *prv;
unsigned int left;
#ifndef ARCH_HAS_SG_CHAIN
BUG_ON(nents > max_ents);
#endif
memset(table, 0, sizeof(*table));
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
sg = alloc_fn(alloc_size, gfp_mask);
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
gfp_mask, sg_kmalloc);
if (unlikely(ret))
__sg_free_table(table, SG_MAX_SINGLE_ALLOC, sg_kfree);
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
void sg_miter_start(struct sg_mapping_iter *miter, struct scatterlist *sgl,
unsigned int nents, unsigned int flags)
{
memset(miter, 0, sizeof(struct sg_mapping_iter));
miter->__sg = sgl;
miter->__nents = nents;
miter->__offset = 0;
WARN_ON(!(flags & (SG_MITER_TO_SG | SG_MITER_FROM_SG)));
miter->__flags = flags;
}
bool sg_miter_next(struct sg_mapping_iter *miter)
{
unsigned int off, len;
if (!miter->__nents)
return false;
sg_miter_stop(miter);
while (miter->__offset == miter->__sg->length) {
if (--miter->__nents) {
miter->__sg = sg_next(miter->__sg);
miter->__offset = 0;
} else
return false;
}
off = miter->__sg->offset + miter->__offset;
len = miter->__sg->length - miter->__offset;
miter->page = nth_page(sg_page(miter->__sg), off >> PAGE_SHIFT);
off &= ~PAGE_MASK;
miter->length = min_t(unsigned int, len, PAGE_SIZE - off);
miter->consumed = miter->length;
if (miter->__flags & SG_MITER_ATOMIC)
miter->addr = kmap_atomic(miter->page) + off;
else
miter->addr = kmap(miter->page) + off;
return true;
}
void sg_miter_stop(struct sg_mapping_iter *miter)
{
WARN_ON(miter->consumed > miter->length);
if (miter->addr) {
miter->__offset += miter->consumed;
if (miter->__flags & SG_MITER_TO_SG)
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
void *buf, size_t buflen, int to_buffer)
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
return sg_copy_buffer(sgl, nents, buf, buflen, 0);
}
size_t sg_copy_to_buffer(struct scatterlist *sgl, unsigned int nents,
void *buf, size_t buflen)
{
return sg_copy_buffer(sgl, nents, buf, buflen, 1);
}
