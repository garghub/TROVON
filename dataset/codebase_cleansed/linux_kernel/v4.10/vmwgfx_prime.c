static int vmw_prime_map_attach(struct dma_buf *dma_buf,
struct device *target_dev,
struct dma_buf_attachment *attach)
{
return -ENOSYS;
}
static void vmw_prime_map_detach(struct dma_buf *dma_buf,
struct dma_buf_attachment *attach)
{
}
static struct sg_table *vmw_prime_map_dma_buf(struct dma_buf_attachment *attach,
enum dma_data_direction dir)
{
return ERR_PTR(-ENOSYS);
}
static void vmw_prime_unmap_dma_buf(struct dma_buf_attachment *attach,
struct sg_table *sgb,
enum dma_data_direction dir)
{
}
static void *vmw_prime_dmabuf_vmap(struct dma_buf *dma_buf)
{
return NULL;
}
static void vmw_prime_dmabuf_vunmap(struct dma_buf *dma_buf, void *vaddr)
{
}
static void *vmw_prime_dmabuf_kmap_atomic(struct dma_buf *dma_buf,
unsigned long page_num)
{
return NULL;
}
static void vmw_prime_dmabuf_kunmap_atomic(struct dma_buf *dma_buf,
unsigned long page_num, void *addr)
{
}
static void *vmw_prime_dmabuf_kmap(struct dma_buf *dma_buf,
unsigned long page_num)
{
return NULL;
}
static void vmw_prime_dmabuf_kunmap(struct dma_buf *dma_buf,
unsigned long page_num, void *addr)
{
}
static int vmw_prime_dmabuf_mmap(struct dma_buf *dma_buf,
struct vm_area_struct *vma)
{
WARN_ONCE(true, "Attempted use of dmabuf mmap. Bad.\n");
return -ENOSYS;
}
int vmw_prime_fd_to_handle(struct drm_device *dev,
struct drm_file *file_priv,
int fd, u32 *handle)
{
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
return ttm_prime_fd_to_handle(tfile, fd, handle);
}
int vmw_prime_handle_to_fd(struct drm_device *dev,
struct drm_file *file_priv,
uint32_t handle, uint32_t flags,
int *prime_fd)
{
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
return ttm_prime_handle_to_fd(tfile, handle, flags, prime_fd);
}
