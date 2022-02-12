static inline void set_tlb_bus(struct snd_trident *trident, int page,
unsigned long ptr, dma_addr_t addr)
{
page <<= 1;
__set_tlb_bus(trident, page, ptr, addr);
__set_tlb_bus(trident, page+1, ptr + SNDRV_TRIDENT_PAGE_SIZE, addr + SNDRV_TRIDENT_PAGE_SIZE);
}
static inline void set_silent_tlb(struct snd_trident *trident, int page)
{
page <<= 1;
__set_tlb_bus(trident, page, (unsigned long)trident->tlb.silent_page.area, trident->tlb.silent_page.addr);
__set_tlb_bus(trident, page+1, (unsigned long)trident->tlb.silent_page.area, trident->tlb.silent_page.addr);
}
static inline void set_tlb_bus(struct snd_trident *trident, int page,
unsigned long ptr, dma_addr_t addr)
{
int i;
page *= UNIT_PAGES;
for (i = 0; i < UNIT_PAGES; i++, page++) {
__set_tlb_bus(trident, page, ptr, addr);
ptr += SNDRV_TRIDENT_PAGE_SIZE;
addr += SNDRV_TRIDENT_PAGE_SIZE;
}
}
static inline void set_silent_tlb(struct snd_trident *trident, int page)
{
int i;
page *= UNIT_PAGES;
for (i = 0; i < UNIT_PAGES; i++, page++)
__set_tlb_bus(trident, page, (unsigned long)trident->tlb.silent_page.area, trident->tlb.silent_page.addr);
}
static inline void *offset_ptr(struct snd_trident *trident, int offset)
{
char *ptr;
ptr = page_to_ptr(trident, get_aligned_page(offset));
ptr += offset % ALIGN_PAGE_SIZE;
return (void*)ptr;
}
static struct snd_util_memblk *
search_empty(struct snd_util_memhdr *hdr, int size)
{
struct snd_util_memblk *blk;
int page, psize;
struct list_head *p;
psize = get_aligned_page(size + ALIGN_PAGE_SIZE -1);
page = 0;
list_for_each(p, &hdr->block) {
blk = list_entry(p, struct snd_util_memblk, list);
if (page + psize <= firstpg(blk))
goto __found_pages;
page = lastpg(blk) + 1;
}
if (page + psize > MAX_ALIGN_PAGES)
return NULL;
__found_pages:
blk = __snd_util_memblk_new(hdr, psize * ALIGN_PAGE_SIZE, p->prev);
if (blk == NULL)
return NULL;
blk->offset = aligned_page_offset(page);
firstpg(blk) = page;
lastpg(blk) = page + psize - 1;
return blk;
}
static int is_valid_page(unsigned long ptr)
{
if (ptr & ~0x3fffffffUL) {
snd_printk(KERN_ERR "max memory size is 1GB!!\n");
return 0;
}
if (ptr & (SNDRV_TRIDENT_PAGE_SIZE-1)) {
snd_printk(KERN_ERR "page is not aligned\n");
return 0;
}
return 1;
}
static struct snd_util_memblk *
snd_trident_alloc_sg_pages(struct snd_trident *trident,
struct snd_pcm_substream *substream)
{
struct snd_util_memhdr *hdr;
struct snd_util_memblk *blk;
struct snd_pcm_runtime *runtime = substream->runtime;
int idx, page;
if (snd_BUG_ON(runtime->dma_bytes <= 0 ||
runtime->dma_bytes > SNDRV_TRIDENT_MAX_PAGES *
SNDRV_TRIDENT_PAGE_SIZE))
return NULL;
hdr = trident->tlb.memhdr;
if (snd_BUG_ON(!hdr))
return NULL;
mutex_lock(&hdr->block_mutex);
blk = search_empty(hdr, runtime->dma_bytes);
if (blk == NULL) {
mutex_unlock(&hdr->block_mutex);
return NULL;
}
idx = 0;
for (page = firstpg(blk); page <= lastpg(blk); page++, idx++) {
unsigned long ofs = idx << PAGE_SHIFT;
dma_addr_t addr = snd_pcm_sgbuf_get_addr(substream, ofs);
unsigned long ptr = (unsigned long)
snd_pcm_sgbuf_get_ptr(substream, ofs);
if (! is_valid_page(addr)) {
__snd_util_mem_free(hdr, blk);
mutex_unlock(&hdr->block_mutex);
return NULL;
}
set_tlb_bus(trident, page, ptr, addr);
}
mutex_unlock(&hdr->block_mutex);
return blk;
}
static struct snd_util_memblk *
snd_trident_alloc_cont_pages(struct snd_trident *trident,
struct snd_pcm_substream *substream)
{
struct snd_util_memhdr *hdr;
struct snd_util_memblk *blk;
int page;
struct snd_pcm_runtime *runtime = substream->runtime;
dma_addr_t addr;
unsigned long ptr;
if (snd_BUG_ON(runtime->dma_bytes <= 0 ||
runtime->dma_bytes > SNDRV_TRIDENT_MAX_PAGES *
SNDRV_TRIDENT_PAGE_SIZE))
return NULL;
hdr = trident->tlb.memhdr;
if (snd_BUG_ON(!hdr))
return NULL;
mutex_lock(&hdr->block_mutex);
blk = search_empty(hdr, runtime->dma_bytes);
if (blk == NULL) {
mutex_unlock(&hdr->block_mutex);
return NULL;
}
addr = runtime->dma_addr;
ptr = (unsigned long)runtime->dma_area;
for (page = firstpg(blk); page <= lastpg(blk); page++,
ptr += SNDRV_TRIDENT_PAGE_SIZE, addr += SNDRV_TRIDENT_PAGE_SIZE) {
if (! is_valid_page(addr)) {
__snd_util_mem_free(hdr, blk);
mutex_unlock(&hdr->block_mutex);
return NULL;
}
set_tlb_bus(trident, page, ptr, addr);
}
mutex_unlock(&hdr->block_mutex);
return blk;
}
struct snd_util_memblk *
snd_trident_alloc_pages(struct snd_trident *trident,
struct snd_pcm_substream *substream)
{
if (snd_BUG_ON(!trident || !substream))
return NULL;
if (substream->dma_buffer.dev.type == SNDRV_DMA_TYPE_DEV_SG)
return snd_trident_alloc_sg_pages(trident, substream);
else
return snd_trident_alloc_cont_pages(trident, substream);
}
int snd_trident_free_pages(struct snd_trident *trident,
struct snd_util_memblk *blk)
{
struct snd_util_memhdr *hdr;
int page;
if (snd_BUG_ON(!trident || !blk))
return -EINVAL;
hdr = trident->tlb.memhdr;
mutex_lock(&hdr->block_mutex);
for (page = firstpg(blk); page <= lastpg(blk); page++)
set_silent_tlb(trident, page);
__snd_util_mem_free(hdr, blk);
mutex_unlock(&hdr->block_mutex);
return 0;
}
