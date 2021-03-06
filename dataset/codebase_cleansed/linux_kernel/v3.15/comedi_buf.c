static void comedi_buf_map_kref_release(struct kref *kref)
{
struct comedi_buf_map *bm =
container_of(kref, struct comedi_buf_map, refcount);
struct comedi_buf_page *buf;
unsigned int i;
if (bm->page_list) {
for (i = 0; i < bm->n_pages; i++) {
buf = &bm->page_list[i];
clear_bit(PG_reserved,
&(virt_to_page(buf->virt_addr)->flags));
if (bm->dma_dir != DMA_NONE) {
#ifdef CONFIG_HAS_DMA
dma_free_coherent(bm->dma_hw_dev,
PAGE_SIZE,
buf->virt_addr,
buf->dma_addr);
#endif
} else {
free_page((unsigned long)buf->virt_addr);
}
}
vfree(bm->page_list);
}
if (bm->dma_dir != DMA_NONE)
put_device(bm->dma_hw_dev);
kfree(bm);
}
static void __comedi_buf_free(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct comedi_async *async = s->async;
struct comedi_buf_map *bm;
unsigned long flags;
if (async->prealloc_buf) {
vunmap(async->prealloc_buf);
async->prealloc_buf = NULL;
async->prealloc_bufsz = 0;
}
spin_lock_irqsave(&s->spin_lock, flags);
bm = async->buf_map;
async->buf_map = NULL;
spin_unlock_irqrestore(&s->spin_lock, flags);
comedi_buf_map_put(bm);
}
static void __comedi_buf_alloc(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned n_pages)
{
struct comedi_async *async = s->async;
struct page **pages = NULL;
struct comedi_buf_map *bm;
struct comedi_buf_page *buf;
unsigned long flags;
unsigned i;
if (!IS_ENABLED(CONFIG_HAS_DMA) && s->async_dma_dir != DMA_NONE) {
dev_err(dev->class_dev,
"dma buffer allocation not supported\n");
return;
}
bm = kzalloc(sizeof(*async->buf_map), GFP_KERNEL);
if (!bm)
return;
kref_init(&bm->refcount);
spin_lock_irqsave(&s->spin_lock, flags);
async->buf_map = bm;
spin_unlock_irqrestore(&s->spin_lock, flags);
bm->dma_dir = s->async_dma_dir;
if (bm->dma_dir != DMA_NONE)
bm->dma_hw_dev = get_device(dev->hw_dev);
bm->page_list = vzalloc(sizeof(*buf) * n_pages);
if (bm->page_list)
pages = vmalloc(sizeof(struct page *) * n_pages);
if (!pages)
return;
for (i = 0; i < n_pages; i++) {
buf = &bm->page_list[i];
if (bm->dma_dir != DMA_NONE)
#ifdef CONFIG_HAS_DMA
buf->virt_addr = dma_alloc_coherent(bm->dma_hw_dev,
PAGE_SIZE,
&buf->dma_addr,
GFP_KERNEL |
__GFP_COMP);
#else
break;
#endif
else
buf->virt_addr = (void *)get_zeroed_page(GFP_KERNEL);
if (!buf->virt_addr)
break;
set_bit(PG_reserved, &(virt_to_page(buf->virt_addr)->flags));
pages[i] = virt_to_page(buf->virt_addr);
}
spin_lock_irqsave(&s->spin_lock, flags);
bm->n_pages = i;
spin_unlock_irqrestore(&s->spin_lock, flags);
if (i == n_pages)
async->prealloc_buf = vmap(pages, n_pages, VM_MAP,
COMEDI_PAGE_PROTECTION);
vfree(pages);
}
void comedi_buf_map_get(struct comedi_buf_map *bm)
{
if (bm)
kref_get(&bm->refcount);
}
int comedi_buf_map_put(struct comedi_buf_map *bm)
{
if (bm)
return kref_put(&bm->refcount, comedi_buf_map_kref_release);
return 1;
}
struct comedi_buf_map *
comedi_buf_map_from_subdev_get(struct comedi_subdevice *s)
{
struct comedi_async *async = s->async;
struct comedi_buf_map *bm = NULL;
unsigned long flags;
if (!async)
return NULL;
spin_lock_irqsave(&s->spin_lock, flags);
bm = async->buf_map;
if (bm && bm->n_pages)
comedi_buf_map_get(bm);
else
bm = NULL;
spin_unlock_irqrestore(&s->spin_lock, flags);
return bm;
}
bool comedi_buf_is_mmapped(struct comedi_async *async)
{
struct comedi_buf_map *bm = async->buf_map;
return bm && (atomic_read(&bm->refcount.refcount) > 1);
}
int comedi_buf_alloc(struct comedi_device *dev, struct comedi_subdevice *s,
unsigned long new_size)
{
struct comedi_async *async = s->async;
new_size = (new_size + PAGE_SIZE - 1) & PAGE_MASK;
if (async->prealloc_buf && async->prealloc_bufsz == new_size)
return 0;
__comedi_buf_free(dev, s);
if (new_size) {
unsigned n_pages = new_size >> PAGE_SHIFT;
__comedi_buf_alloc(dev, s, n_pages);
if (!async->prealloc_buf) {
__comedi_buf_free(dev, s);
return -ENOMEM;
}
}
async->prealloc_bufsz = new_size;
return 0;
}
void comedi_buf_reset(struct comedi_async *async)
{
async->buf_write_alloc_count = 0;
async->buf_write_count = 0;
async->buf_read_alloc_count = 0;
async->buf_read_count = 0;
async->buf_write_ptr = 0;
async->buf_read_ptr = 0;
async->cur_chan = 0;
async->scan_progress = 0;
async->munge_chan = 0;
async->munge_count = 0;
async->munge_ptr = 0;
async->events = 0;
}
static unsigned int comedi_buf_write_n_available(struct comedi_async *async)
{
unsigned int free_end = async->buf_read_count + async->prealloc_bufsz;
return free_end - async->buf_write_alloc_count;
}
static unsigned int __comedi_buf_write_alloc(struct comedi_async *async,
unsigned int nbytes,
int strict)
{
unsigned int available = comedi_buf_write_n_available(async);
if (nbytes > available)
nbytes = strict ? 0 : available;
async->buf_write_alloc_count += nbytes;
smp_mb();
return nbytes;
}
unsigned int comedi_buf_write_alloc(struct comedi_async *async,
unsigned int nbytes)
{
return __comedi_buf_write_alloc(async, nbytes, 0);
}
static unsigned int comedi_buf_munge(struct comedi_async *async,
unsigned int num_bytes)
{
struct comedi_subdevice *s = async->subdevice;
unsigned int count = 0;
const unsigned num_sample_bytes = bytes_per_sample(s);
if (!s->munge || (async->cmd.flags & CMDF_RAWDATA)) {
async->munge_count += num_bytes;
count = num_bytes;
} else {
num_bytes -= num_bytes % num_sample_bytes;
while (count < num_bytes) {
int block_size = num_bytes - count;
unsigned int buf_end;
buf_end = async->prealloc_bufsz - async->munge_ptr;
if (block_size > buf_end)
block_size = buf_end;
s->munge(s->device, s,
async->prealloc_buf + async->munge_ptr,
block_size, async->munge_chan);
smp_wmb();
async->munge_chan += block_size / num_sample_bytes;
async->munge_chan %= async->cmd.chanlist_len;
async->munge_count += block_size;
async->munge_ptr += block_size;
async->munge_ptr %= async->prealloc_bufsz;
count += block_size;
}
}
return count;
}
unsigned int comedi_buf_write_n_allocated(struct comedi_async *async)
{
return async->buf_write_alloc_count - async->buf_write_count;
}
unsigned int comedi_buf_write_free(struct comedi_async *async,
unsigned int nbytes)
{
unsigned int allocated = comedi_buf_write_n_allocated(async);
if (nbytes > allocated)
nbytes = allocated;
async->buf_write_count += nbytes;
async->buf_write_ptr += nbytes;
comedi_buf_munge(async, async->buf_write_count - async->munge_count);
if (async->buf_write_ptr >= async->prealloc_bufsz)
async->buf_write_ptr %= async->prealloc_bufsz;
return nbytes;
}
unsigned int comedi_buf_read_n_available(struct comedi_async *async)
{
unsigned num_bytes;
if (!async)
return 0;
num_bytes = async->munge_count - async->buf_read_count;
smp_rmb();
return num_bytes;
}
unsigned int comedi_buf_read_alloc(struct comedi_async *async,
unsigned int nbytes)
{
unsigned int available;
available = async->munge_count - async->buf_read_alloc_count;
if (nbytes > available)
nbytes = available;
async->buf_read_alloc_count += nbytes;
smp_rmb();
return nbytes;
}
static unsigned int comedi_buf_read_n_allocated(struct comedi_async *async)
{
return async->buf_read_alloc_count - async->buf_read_count;
}
unsigned int comedi_buf_read_free(struct comedi_async *async,
unsigned int nbytes)
{
unsigned int allocated;
smp_mb();
allocated = comedi_buf_read_n_allocated(async);
if (nbytes > allocated)
nbytes = allocated;
async->buf_read_count += nbytes;
async->buf_read_ptr += nbytes;
async->buf_read_ptr %= async->prealloc_bufsz;
return nbytes;
}
int comedi_buf_put(struct comedi_async *async, unsigned short x)
{
unsigned int n = __comedi_buf_write_alloc(async, sizeof(short), 1);
if (n < sizeof(short)) {
async->events |= COMEDI_CB_ERROR;
return 0;
}
*(unsigned short *)(async->prealloc_buf + async->buf_write_ptr) = x;
comedi_buf_write_free(async, sizeof(short));
return 1;
}
int comedi_buf_get(struct comedi_async *async, unsigned short *x)
{
unsigned int n = comedi_buf_read_n_available(async);
if (n < sizeof(short))
return 0;
comedi_buf_read_alloc(async, sizeof(short));
*x = *(unsigned short *)(async->prealloc_buf + async->buf_read_ptr);
comedi_buf_read_free(async, sizeof(short));
return 1;
}
void comedi_buf_memcpy_to(struct comedi_async *async, unsigned int offset,
const void *data, unsigned int num_bytes)
{
unsigned int write_ptr = async->buf_write_ptr + offset;
if (write_ptr >= async->prealloc_bufsz)
write_ptr %= async->prealloc_bufsz;
while (num_bytes) {
unsigned int block_size;
if (write_ptr + num_bytes > async->prealloc_bufsz)
block_size = async->prealloc_bufsz - write_ptr;
else
block_size = num_bytes;
memcpy(async->prealloc_buf + write_ptr, data, block_size);
data += block_size;
num_bytes -= block_size;
write_ptr = 0;
}
}
void comedi_buf_memcpy_from(struct comedi_async *async, unsigned int offset,
void *dest, unsigned int nbytes)
{
void *src;
unsigned int read_ptr = async->buf_read_ptr + offset;
if (read_ptr >= async->prealloc_bufsz)
read_ptr %= async->prealloc_bufsz;
while (nbytes) {
unsigned int block_size;
src = async->prealloc_buf + read_ptr;
if (nbytes >= async->prealloc_bufsz - read_ptr)
block_size = async->prealloc_bufsz - read_ptr;
else
block_size = nbytes;
memcpy(dest, src, block_size);
nbytes -= block_size;
dest += block_size;
read_ptr = 0;
}
}
