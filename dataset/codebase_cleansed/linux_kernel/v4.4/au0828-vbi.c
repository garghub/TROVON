static int vbi_queue_setup(struct vb2_queue *vq, const void *parg,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
const struct v4l2_format *fmt = parg;
struct au0828_dev *dev = vb2_get_drv_priv(vq);
unsigned long img_size = dev->vbi_width * dev->vbi_height * 2;
unsigned long size;
size = fmt ? (fmt->fmt.vbi.samples_per_line *
(fmt->fmt.vbi.count[0] + fmt->fmt.vbi.count[1])) : img_size;
if (size < img_size)
return -EINVAL;
*nplanes = 1;
sizes[0] = size;
return 0;
}
static int vbi_buffer_prepare(struct vb2_buffer *vb)
{
struct au0828_dev *dev = vb2_get_drv_priv(vb->vb2_queue);
unsigned long size;
size = dev->vbi_width * dev->vbi_height * 2;
if (vb2_plane_size(vb, 0) < size) {
pr_err("%s data will not fit into plane (%lu < %lu)\n",
__func__, vb2_plane_size(vb, 0), size);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, size);
return 0;
}
static void
vbi_buffer_queue(struct vb2_buffer *vb)
{
struct au0828_dev *dev = vb2_get_drv_priv(vb->vb2_queue);
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct au0828_buffer *buf =
container_of(vbuf, struct au0828_buffer, vb);
struct au0828_dmaqueue *vbiq = &dev->vbiq;
unsigned long flags = 0;
buf->mem = vb2_plane_vaddr(vb, 0);
buf->length = vb2_plane_size(vb, 0);
spin_lock_irqsave(&dev->slock, flags);
list_add_tail(&buf->list, &vbiq->active);
spin_unlock_irqrestore(&dev->slock, flags);
}
