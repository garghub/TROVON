static inline void memcpy_dir(void *buf, void *sgdata, size_t nbytes, int out)
{
void *src = out ? buf : sgdata;
void *dst = out ? sgdata : buf;
memcpy(dst, src, nbytes);
}
void scatterwalk_start(struct scatter_walk *walk, struct scatterlist *sg)
{
walk->sg = sg;
BUG_ON(!sg->length);
walk->offset = sg->offset;
}
void *scatterwalk_map(struct scatter_walk *walk)
{
return kmap_atomic(scatterwalk_page(walk)) +
offset_in_page(walk->offset);
}
static void scatterwalk_pagedone(struct scatter_walk *walk, int out,
unsigned int more)
{
if (out) {
struct page *page;
page = sg_page(walk->sg) + ((walk->offset - 1) >> PAGE_SHIFT);
if (!PageSlab(page))
flush_dcache_page(page);
}
if (more) {
walk->offset += PAGE_SIZE - 1;
walk->offset &= PAGE_MASK;
if (walk->offset >= walk->sg->offset + walk->sg->length)
scatterwalk_start(walk, scatterwalk_sg_next(walk->sg));
}
}
void scatterwalk_done(struct scatter_walk *walk, int out, int more)
{
if (!(scatterwalk_pagelen(walk) & (PAGE_SIZE - 1)) || !more)
scatterwalk_pagedone(walk, out, more);
}
void scatterwalk_copychunks(void *buf, struct scatter_walk *walk,
size_t nbytes, int out)
{
for (;;) {
unsigned int len_this_page = scatterwalk_pagelen(walk);
u8 *vaddr;
if (len_this_page > nbytes)
len_this_page = nbytes;
vaddr = scatterwalk_map(walk);
memcpy_dir(buf, vaddr, len_this_page, out);
scatterwalk_unmap(vaddr);
scatterwalk_advance(walk, len_this_page);
if (nbytes == len_this_page)
break;
buf += len_this_page;
nbytes -= len_this_page;
scatterwalk_pagedone(walk, out, 1);
}
}
void scatterwalk_map_and_copy(void *buf, struct scatterlist *sg,
unsigned int start, unsigned int nbytes, int out)
{
struct scatter_walk walk;
unsigned int offset = 0;
if (!nbytes)
return;
for (;;) {
scatterwalk_start(&walk, sg);
if (start < offset + sg->length)
break;
offset += sg->length;
sg = scatterwalk_sg_next(sg);
}
scatterwalk_advance(&walk, start - offset);
scatterwalk_copychunks(buf, &walk, nbytes, out);
scatterwalk_done(&walk, out, 0);
}
int scatterwalk_bytes_sglen(struct scatterlist *sg, int num_bytes)
{
int offset = 0, n = 0;
if (num_bytes < sg->length)
return -1;
do {
offset += sg->length;
n++;
sg = scatterwalk_sg_next(sg);
if (unlikely(!sg && (num_bytes < offset)))
return -1;
} while (sg && (num_bytes > offset));
return n;
}
