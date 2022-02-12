static int vbi_queue_setup(struct vb2_queue *vq, const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct em28xx *dev = vb2_get_drv_priv(vq);
unsigned long size;
if (fmt)
size = fmt->fmt.pix.sizeimage;
else
size = dev->vbi_width * dev->vbi_height * 2;
if (0 == *nbuffers)
*nbuffers = 32;
if (*nbuffers < 2)
*nbuffers = 2;
if (*nbuffers > 32)
*nbuffers = 32;
*nplanes = 1;
sizes[0] = size;
return 0;
}
static int vbi_buffer_prepare(struct vb2_buffer *vb)
{
struct em28xx *dev = vb2_get_drv_priv(vb->vb2_queue);
struct em28xx_buffer *buf = container_of(vb, struct em28xx_buffer, vb);
unsigned long size;
size = dev->vbi_width * dev->vbi_height * 2;
if (vb2_plane_size(vb, 0) < size) {
printk(KERN_INFO "%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(&buf->vb, 0, size);
return 0;
}
static void
vbi_buffer_queue(struct vb2_buffer *vb)
{
struct em28xx *dev = vb2_get_drv_priv(vb->vb2_queue);
struct em28xx_buffer *buf = container_of(vb, struct em28xx_buffer, vb);
struct em28xx_dmaqueue *vbiq = &dev->vbiq;
unsigned long flags = 0;
buf->mem = vb2_plane_vaddr(vb, 0);
buf->length = vb2_plane_size(vb, 0);
spin_lock_irqsave(&dev->slock, flags);
list_add_tail(&buf->list, &vbiq->active);
spin_unlock_irqrestore(&dev->slock, flags);
}
