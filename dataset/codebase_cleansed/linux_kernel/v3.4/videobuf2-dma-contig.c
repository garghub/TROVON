static void *vb2_dma_contig_alloc(void *alloc_ctx, unsigned long size)
{
struct vb2_dc_conf *conf = alloc_ctx;
struct vb2_dc_buf *buf;
buf = kzalloc(sizeof *buf, GFP_KERNEL);
if (!buf)
return ERR_PTR(-ENOMEM);
buf->vaddr = dma_alloc_coherent(conf->dev, size, &buf->dma_addr,
GFP_KERNEL);
if (!buf->vaddr) {
dev_err(conf->dev, "dma_alloc_coherent of size %ld failed\n",
size);
kfree(buf);
return ERR_PTR(-ENOMEM);
}
buf->conf = conf;
buf->size = size;
buf->handler.refcount = &buf->refcount;
buf->handler.put = vb2_dma_contig_put;
buf->handler.arg = buf;
atomic_inc(&buf->refcount);
return buf;
}
static void vb2_dma_contig_put(void *buf_priv)
{
struct vb2_dc_buf *buf = buf_priv;
if (atomic_dec_and_test(&buf->refcount)) {
dma_free_coherent(buf->conf->dev, buf->size, buf->vaddr,
buf->dma_addr);
kfree(buf);
}
}
static void *vb2_dma_contig_cookie(void *buf_priv)
{
struct vb2_dc_buf *buf = buf_priv;
return &buf->dma_addr;
}
static void *vb2_dma_contig_vaddr(void *buf_priv)
{
struct vb2_dc_buf *buf = buf_priv;
if (!buf)
return NULL;
return buf->vaddr;
}
static unsigned int vb2_dma_contig_num_users(void *buf_priv)
{
struct vb2_dc_buf *buf = buf_priv;
return atomic_read(&buf->refcount);
}
static int vb2_dma_contig_mmap(void *buf_priv, struct vm_area_struct *vma)
{
struct vb2_dc_buf *buf = buf_priv;
if (!buf) {
printk(KERN_ERR "No buffer to map\n");
return -EINVAL;
}
return vb2_mmap_pfn_range(vma, buf->dma_addr, buf->size,
&vb2_common_vm_ops, &buf->handler);
}
static void *vb2_dma_contig_get_userptr(void *alloc_ctx, unsigned long vaddr,
unsigned long size, int write)
{
struct vb2_dc_buf *buf;
struct vm_area_struct *vma;
dma_addr_t dma_addr = 0;
int ret;
buf = kzalloc(sizeof *buf, GFP_KERNEL);
if (!buf)
return ERR_PTR(-ENOMEM);
ret = vb2_get_contig_userptr(vaddr, size, &vma, &dma_addr);
if (ret) {
printk(KERN_ERR "Failed acquiring VMA for vaddr 0x%08lx\n",
vaddr);
kfree(buf);
return ERR_PTR(ret);
}
buf->size = size;
buf->dma_addr = dma_addr;
buf->vma = vma;
return buf;
}
static void vb2_dma_contig_put_userptr(void *mem_priv)
{
struct vb2_dc_buf *buf = mem_priv;
if (!buf)
return;
vb2_put_vma(buf->vma);
kfree(buf);
}
void *vb2_dma_contig_init_ctx(struct device *dev)
{
struct vb2_dc_conf *conf;
conf = kzalloc(sizeof *conf, GFP_KERNEL);
if (!conf)
return ERR_PTR(-ENOMEM);
conf->dev = dev;
return conf;
}
void vb2_dma_contig_cleanup_ctx(void *alloc_ctx)
{
kfree(alloc_ctx);
}
