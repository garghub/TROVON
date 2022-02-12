static unsigned int rest_of_page(void *data)
{
return PAGE_SIZE - ((unsigned long)data % PAGE_SIZE);
}
static void p9_virtio_close(struct p9_client *client)
{
struct virtio_chan *chan = client->trans;
mutex_lock(&virtio_9p_lock);
if (chan)
chan->inuse = false;
mutex_unlock(&virtio_9p_lock);
}
static void req_done(struct virtqueue *vq)
{
struct virtio_chan *chan = vq->vdev->priv;
struct p9_fcall *rc;
unsigned int len;
struct p9_req_t *req;
unsigned long flags;
P9_DPRINTK(P9_DEBUG_TRANS, ": request done\n");
while (1) {
spin_lock_irqsave(&chan->lock, flags);
rc = virtqueue_get_buf(chan->vq, &len);
if (rc == NULL) {
spin_unlock_irqrestore(&chan->lock, flags);
break;
}
chan->ring_bufs_avail = 1;
spin_unlock_irqrestore(&chan->lock, flags);
wake_up(chan->vc_wq);
P9_DPRINTK(P9_DEBUG_TRANS, ": rc %p\n", rc);
P9_DPRINTK(P9_DEBUG_TRANS, ": lookup tag %d\n", rc->tag);
req = p9_tag_lookup(chan->client, rc->tag);
if (req->tc->private) {
struct trans_rpage_info *rp = req->tc->private;
int p = rp->rp_nr_pages;
p9_release_req_pages(rp);
atomic_sub(p, &vp_pinned);
wake_up(&vp_wq);
if (rp->rp_alloc)
kfree(rp);
req->tc->private = NULL;
}
req->status = REQ_STATUS_RCVD;
p9_client_cb(chan->client, req);
}
}
static int
pack_sg_list(struct scatterlist *sg, int start, int limit, char *data,
int count)
{
int s;
int index = start;
while (count) {
s = rest_of_page(data);
if (s > count)
s = count;
sg_set_buf(&sg[index++], data, s);
count -= s;
data += s;
BUG_ON(index > limit);
}
return index-start;
}
static int p9_virtio_cancel(struct p9_client *client, struct p9_req_t *req)
{
return 1;
}
static int
pack_sg_list_p(struct scatterlist *sg, int start, int limit, size_t pdata_off,
struct page **pdata, int count)
{
int s;
int i = 0;
int index = start;
if (pdata_off) {
s = min((int)(PAGE_SIZE - pdata_off), count);
sg_set_page(&sg[index++], pdata[i++], s, pdata_off);
count -= s;
}
while (count) {
BUG_ON(index > limit);
s = min((int)PAGE_SIZE, count);
sg_set_page(&sg[index++], pdata[i++], s, 0);
count -= s;
}
return index-start;
}
static int
p9_virtio_request(struct p9_client *client, struct p9_req_t *req)
{
int in, out, inp, outp;
struct virtio_chan *chan = client->trans;
unsigned long flags;
size_t pdata_off = 0;
struct trans_rpage_info *rpinfo = NULL;
int err, pdata_len = 0;
P9_DPRINTK(P9_DEBUG_TRANS, "9p debug: virtio request\n");
req->status = REQ_STATUS_SENT;
if (req->tc->pbuf_size && (req->tc->pubuf && P9_IS_USER_CONTEXT)) {
int nr_pages = p9_nr_pages(req);
int rpinfo_size = sizeof(struct trans_rpage_info) +
sizeof(struct page *) * nr_pages;
if (atomic_read(&vp_pinned) >= chan->p9_max_pages) {
err = wait_event_interruptible(vp_wq,
atomic_read(&vp_pinned) < chan->p9_max_pages);
if (err == -ERESTARTSYS)
return err;
P9_DPRINTK(P9_DEBUG_TRANS, "9p: May gup pages now.\n");
}
if (rpinfo_size <= (req->tc->capacity - req->tc->size)) {
req->tc->private = req->tc->sdata + req->tc->size;
rpinfo = (struct trans_rpage_info *)req->tc->private;
rpinfo->rp_alloc = 0;
} else {
req->tc->private = kmalloc(rpinfo_size, GFP_NOFS);
if (!req->tc->private) {
P9_DPRINTK(P9_DEBUG_TRANS, "9p debug: "
"private kmalloc returned NULL");
return -ENOMEM;
}
rpinfo = (struct trans_rpage_info *)req->tc->private;
rpinfo->rp_alloc = 1;
}
err = p9_payload_gup(req, &pdata_off, &pdata_len, nr_pages,
req->tc->id == P9_TREAD ? 1 : 0);
if (err < 0) {
if (rpinfo->rp_alloc)
kfree(rpinfo);
return err;
} else {
atomic_add(rpinfo->rp_nr_pages, &vp_pinned);
}
}
req_retry_pinned:
spin_lock_irqsave(&chan->lock, flags);
out = pack_sg_list(chan->sg, 0, VIRTQUEUE_NUM, req->tc->sdata,
req->tc->size);
if (req->tc->pbuf_size && (req->tc->id == P9_TWRITE)) {
if (req->tc->pubuf && P9_IS_USER_CONTEXT) {
outp = pack_sg_list_p(chan->sg, out, VIRTQUEUE_NUM,
pdata_off, rpinfo->rp_data, pdata_len);
} else {
char *pbuf;
if (req->tc->pubuf)
pbuf = (__force char *) req->tc->pubuf;
else
pbuf = req->tc->pkbuf;
outp = pack_sg_list(chan->sg, out, VIRTQUEUE_NUM, pbuf,
req->tc->pbuf_size);
}
out += outp;
}
if (req->tc->pbuf_size &&
((req->tc->id == P9_TREAD) || (req->tc->id == P9_TREADDIR))) {
inp = pack_sg_list(chan->sg, out,
VIRTQUEUE_NUM, req->rc->sdata, 11);
if (req->tc->pubuf && P9_IS_USER_CONTEXT) {
in = pack_sg_list_p(chan->sg, out+inp, VIRTQUEUE_NUM,
pdata_off, rpinfo->rp_data, pdata_len);
} else {
char *pbuf;
if (req->tc->pubuf)
pbuf = (__force char *) req->tc->pubuf;
else
pbuf = req->tc->pkbuf;
in = pack_sg_list(chan->sg, out+inp, VIRTQUEUE_NUM,
pbuf, req->tc->pbuf_size);
}
in += inp;
} else {
in = pack_sg_list(chan->sg, out, VIRTQUEUE_NUM,
req->rc->sdata, req->rc->capacity);
}
err = virtqueue_add_buf(chan->vq, chan->sg, out, in, req->tc);
if (err < 0) {
if (err == -ENOSPC) {
chan->ring_bufs_avail = 0;
spin_unlock_irqrestore(&chan->lock, flags);
err = wait_event_interruptible(*chan->vc_wq,
chan->ring_bufs_avail);
if (err == -ERESTARTSYS)
return err;
P9_DPRINTK(P9_DEBUG_TRANS, "9p:Retry virtio request\n");
goto req_retry_pinned;
} else {
spin_unlock_irqrestore(&chan->lock, flags);
P9_DPRINTK(P9_DEBUG_TRANS,
"9p debug: "
"virtio rpc add_buf returned failure");
if (rpinfo && rpinfo->rp_alloc)
kfree(rpinfo);
return -EIO;
}
}
virtqueue_kick(chan->vq);
spin_unlock_irqrestore(&chan->lock, flags);
P9_DPRINTK(P9_DEBUG_TRANS, "9p debug: virtio request kicked\n");
return 0;
}
static ssize_t p9_mount_tag_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct virtio_chan *chan;
struct virtio_device *vdev;
vdev = dev_to_virtio(dev);
chan = vdev->priv;
return snprintf(buf, chan->tag_len + 1, "%s", chan->tag);
}
static int p9_virtio_probe(struct virtio_device *vdev)
{
__u16 tag_len;
char *tag;
int err;
struct virtio_chan *chan;
chan = kmalloc(sizeof(struct virtio_chan), GFP_KERNEL);
if (!chan) {
printk(KERN_ERR "9p: Failed to allocate virtio 9P channel\n");
err = -ENOMEM;
goto fail;
}
chan->vdev = vdev;
chan->vq = virtio_find_single_vq(vdev, req_done, "requests");
if (IS_ERR(chan->vq)) {
err = PTR_ERR(chan->vq);
goto out_free_vq;
}
chan->vq->vdev->priv = chan;
spin_lock_init(&chan->lock);
sg_init_table(chan->sg, VIRTQUEUE_NUM);
chan->inuse = false;
if (virtio_has_feature(vdev, VIRTIO_9P_MOUNT_TAG)) {
vdev->config->get(vdev,
offsetof(struct virtio_9p_config, tag_len),
&tag_len, sizeof(tag_len));
} else {
err = -EINVAL;
goto out_free_vq;
}
tag = kmalloc(tag_len, GFP_KERNEL);
if (!tag) {
err = -ENOMEM;
goto out_free_vq;
}
vdev->config->get(vdev, offsetof(struct virtio_9p_config, tag),
tag, tag_len);
chan->tag = tag;
chan->tag_len = tag_len;
err = sysfs_create_file(&(vdev->dev.kobj), &dev_attr_mount_tag.attr);
if (err) {
goto out_free_tag;
}
chan->vc_wq = kmalloc(sizeof(wait_queue_head_t), GFP_KERNEL);
if (!chan->vc_wq) {
err = -ENOMEM;
goto out_free_tag;
}
init_waitqueue_head(chan->vc_wq);
chan->ring_bufs_avail = 1;
chan->p9_max_pages = nr_free_buffer_pages()/4;
mutex_lock(&virtio_9p_lock);
list_add_tail(&chan->chan_list, &virtio_chan_list);
mutex_unlock(&virtio_9p_lock);
return 0;
out_free_tag:
kfree(tag);
out_free_vq:
vdev->config->del_vqs(vdev);
kfree(chan);
fail:
return err;
}
static int
p9_virtio_create(struct p9_client *client, const char *devname, char *args)
{
struct virtio_chan *chan;
int ret = -ENOENT;
int found = 0;
mutex_lock(&virtio_9p_lock);
list_for_each_entry(chan, &virtio_chan_list, chan_list) {
if (!strncmp(devname, chan->tag, chan->tag_len) &&
strlen(devname) == chan->tag_len) {
if (!chan->inuse) {
chan->inuse = true;
found = 1;
break;
}
ret = -EBUSY;
}
}
mutex_unlock(&virtio_9p_lock);
if (!found) {
printk(KERN_ERR "9p: no channels available\n");
return ret;
}
client->trans = (void *)chan;
client->status = Connected;
chan->client = client;
return 0;
}
static void p9_virtio_remove(struct virtio_device *vdev)
{
struct virtio_chan *chan = vdev->priv;
BUG_ON(chan->inuse);
vdev->config->del_vqs(vdev);
mutex_lock(&virtio_9p_lock);
list_del(&chan->chan_list);
mutex_unlock(&virtio_9p_lock);
sysfs_remove_file(&(vdev->dev.kobj), &dev_attr_mount_tag.attr);
kfree(chan->tag);
kfree(chan->vc_wq);
kfree(chan);
}
static int __init p9_virtio_init(void)
{
INIT_LIST_HEAD(&virtio_chan_list);
v9fs_register_trans(&p9_virtio_trans);
return register_virtio_driver(&p9_virtio_drv);
}
static void __exit p9_virtio_cleanup(void)
{
unregister_virtio_driver(&p9_virtio_drv);
v9fs_unregister_trans(&p9_virtio_trans);
}
