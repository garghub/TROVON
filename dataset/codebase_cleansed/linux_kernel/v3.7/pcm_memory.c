static int preallocate_pcm_pages(struct snd_pcm_substream *substream, size_t size)
{
struct snd_dma_buffer *dmab = &substream->dma_buffer;
int err;
if (snd_dma_get_reserved_buf(dmab, substream->dma_buf_id) > 0) {
if (dmab->bytes >= size)
return 0;
snd_dma_free_pages(dmab);
dmab->bytes = 0;
}
do {
if ((err = snd_dma_alloc_pages(dmab->dev.type, dmab->dev.dev,
size, dmab)) < 0) {
if (err != -ENOMEM)
return err;
} else
return 0;
size >>= 1;
} while (size >= snd_minimum_buffer);
dmab->bytes = 0;
return 0;
}
static void snd_pcm_lib_preallocate_dma_free(struct snd_pcm_substream *substream)
{
if (substream->dma_buffer.area == NULL)
return;
if (substream->dma_buf_id)
snd_dma_reserve_buf(&substream->dma_buffer, substream->dma_buf_id);
else
snd_dma_free_pages(&substream->dma_buffer);
substream->dma_buffer.area = NULL;
}
int snd_pcm_lib_preallocate_free(struct snd_pcm_substream *substream)
{
snd_pcm_lib_preallocate_dma_free(substream);
#ifdef CONFIG_SND_VERBOSE_PROCFS
snd_info_free_entry(substream->proc_prealloc_max_entry);
substream->proc_prealloc_max_entry = NULL;
snd_info_free_entry(substream->proc_prealloc_entry);
substream->proc_prealloc_entry = NULL;
#endif
return 0;
}
int snd_pcm_lib_preallocate_free_for_all(struct snd_pcm *pcm)
{
struct snd_pcm_substream *substream;
int stream;
for (stream = 0; stream < 2; stream++)
for (substream = pcm->streams[stream].substream; substream; substream = substream->next)
snd_pcm_lib_preallocate_free(substream);
return 0;
}
static void snd_pcm_lib_preallocate_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_pcm_substream *substream = entry->private_data;
snd_iprintf(buffer, "%lu\n", (unsigned long) substream->dma_buffer.bytes / 1024);
}
static void snd_pcm_lib_preallocate_max_proc_read(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_pcm_substream *substream = entry->private_data;
snd_iprintf(buffer, "%lu\n", (unsigned long) substream->dma_max / 1024);
}
static void snd_pcm_lib_preallocate_proc_write(struct snd_info_entry *entry,
struct snd_info_buffer *buffer)
{
struct snd_pcm_substream *substream = entry->private_data;
char line[64], str[64];
size_t size;
struct snd_dma_buffer new_dmab;
if (substream->runtime) {
buffer->error = -EBUSY;
return;
}
if (!snd_info_get_line(buffer, line, sizeof(line))) {
snd_info_get_str(str, line, sizeof(str));
size = simple_strtoul(str, NULL, 10) * 1024;
if ((size != 0 && size < 8192) || size > substream->dma_max) {
buffer->error = -EINVAL;
return;
}
if (substream->dma_buffer.bytes == size)
return;
memset(&new_dmab, 0, sizeof(new_dmab));
new_dmab.dev = substream->dma_buffer.dev;
if (size > 0) {
if (snd_dma_alloc_pages(substream->dma_buffer.dev.type,
substream->dma_buffer.dev.dev,
size, &new_dmab) < 0) {
buffer->error = -ENOMEM;
return;
}
substream->buffer_bytes_max = size;
} else {
substream->buffer_bytes_max = UINT_MAX;
}
if (substream->dma_buffer.area)
snd_dma_free_pages(&substream->dma_buffer);
substream->dma_buffer = new_dmab;
} else {
buffer->error = -EINVAL;
}
}
static inline void preallocate_info_init(struct snd_pcm_substream *substream)
{
struct snd_info_entry *entry;
if ((entry = snd_info_create_card_entry(substream->pcm->card, "prealloc", substream->proc_root)) != NULL) {
entry->c.text.read = snd_pcm_lib_preallocate_proc_read;
entry->c.text.write = snd_pcm_lib_preallocate_proc_write;
entry->mode |= S_IWUSR;
entry->private_data = substream;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
entry = NULL;
}
}
substream->proc_prealloc_entry = entry;
if ((entry = snd_info_create_card_entry(substream->pcm->card, "prealloc_max", substream->proc_root)) != NULL) {
entry->c.text.read = snd_pcm_lib_preallocate_max_proc_read;
entry->private_data = substream;
if (snd_info_register(entry) < 0) {
snd_info_free_entry(entry);
entry = NULL;
}
}
substream->proc_prealloc_max_entry = entry;
}
static int snd_pcm_lib_preallocate_pages1(struct snd_pcm_substream *substream,
size_t size, size_t max)
{
if (size > 0 && preallocate_dma && substream->number < maximum_substreams)
preallocate_pcm_pages(substream, size);
if (substream->dma_buffer.bytes > 0)
substream->buffer_bytes_max = substream->dma_buffer.bytes;
substream->dma_max = max;
preallocate_info_init(substream);
return 0;
}
int snd_pcm_lib_preallocate_pages(struct snd_pcm_substream *substream,
int type, struct device *data,
size_t size, size_t max)
{
substream->dma_buffer.dev.type = type;
substream->dma_buffer.dev.dev = data;
return snd_pcm_lib_preallocate_pages1(substream, size, max);
}
int snd_pcm_lib_preallocate_pages_for_all(struct snd_pcm *pcm,
int type, void *data,
size_t size, size_t max)
{
struct snd_pcm_substream *substream;
int stream, err;
for (stream = 0; stream < 2; stream++)
for (substream = pcm->streams[stream].substream; substream; substream = substream->next)
if ((err = snd_pcm_lib_preallocate_pages(substream, type, data, size, max)) < 0)
return err;
return 0;
}
struct page *snd_pcm_sgbuf_ops_page(struct snd_pcm_substream *substream, unsigned long offset)
{
struct snd_sg_buf *sgbuf = snd_pcm_substream_sgbuf(substream);
unsigned int idx = offset >> PAGE_SHIFT;
if (idx >= (unsigned int)sgbuf->pages)
return NULL;
return sgbuf->page_table[idx];
}
int snd_pcm_lib_malloc_pages(struct snd_pcm_substream *substream, size_t size)
{
struct snd_pcm_runtime *runtime;
struct snd_dma_buffer *dmab = NULL;
if (PCM_RUNTIME_CHECK(substream))
return -EINVAL;
if (snd_BUG_ON(substream->dma_buffer.dev.type ==
SNDRV_DMA_TYPE_UNKNOWN))
return -EINVAL;
runtime = substream->runtime;
if (runtime->dma_buffer_p) {
if (runtime->dma_buffer_p->bytes >= size) {
runtime->dma_bytes = size;
return 0;
}
snd_pcm_lib_free_pages(substream);
}
if (substream->dma_buffer.area != NULL &&
substream->dma_buffer.bytes >= size) {
dmab = &substream->dma_buffer;
} else {
dmab = kzalloc(sizeof(*dmab), GFP_KERNEL);
if (! dmab)
return -ENOMEM;
dmab->dev = substream->dma_buffer.dev;
if (snd_dma_alloc_pages(substream->dma_buffer.dev.type,
substream->dma_buffer.dev.dev,
size, dmab) < 0) {
kfree(dmab);
return -ENOMEM;
}
}
snd_pcm_set_runtime_buffer(substream, dmab);
runtime->dma_bytes = size;
return 1;
}
int snd_pcm_lib_free_pages(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime;
if (PCM_RUNTIME_CHECK(substream))
return -EINVAL;
runtime = substream->runtime;
if (runtime->dma_area == NULL)
return 0;
if (runtime->dma_buffer_p != &substream->dma_buffer) {
snd_dma_free_pages(runtime->dma_buffer_p);
kfree(runtime->dma_buffer_p);
}
snd_pcm_set_runtime_buffer(substream, NULL);
return 0;
}
int _snd_pcm_lib_alloc_vmalloc_buffer(struct snd_pcm_substream *substream,
size_t size, gfp_t gfp_flags)
{
struct snd_pcm_runtime *runtime;
if (PCM_RUNTIME_CHECK(substream))
return -EINVAL;
runtime = substream->runtime;
if (runtime->dma_area) {
if (runtime->dma_bytes >= size)
return 0;
vfree(runtime->dma_area);
}
runtime->dma_area = __vmalloc(size, gfp_flags, PAGE_KERNEL);
if (!runtime->dma_area)
return -ENOMEM;
runtime->dma_bytes = size;
return 1;
}
int snd_pcm_lib_free_vmalloc_buffer(struct snd_pcm_substream *substream)
{
struct snd_pcm_runtime *runtime;
if (PCM_RUNTIME_CHECK(substream))
return -EINVAL;
runtime = substream->runtime;
vfree(runtime->dma_area);
runtime->dma_area = NULL;
return 0;
}
struct page *snd_pcm_lib_get_vmalloc_page(struct snd_pcm_substream *substream,
unsigned long offset)
{
return vmalloc_to_page(substream->runtime->dma_area + offset);
}
