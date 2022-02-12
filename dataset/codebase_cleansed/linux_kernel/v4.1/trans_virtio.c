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
p9_debug(P9_DEBUG_TRANS, ": request done\n");
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
p9_debug(P9_DEBUG_TRANS, ": rc %p\n", rc);
p9_debug(P9_DEBUG_TRANS, ": lookup tag %d\n", rc->tag);
req = p9_tag_lookup(chan->client, rc->tag);
p9_client_cb(chan->client, req, REQ_STATUS_RCVD);
}
}
static int pack_sg_list(struct scatterlist *sg, int start,
int limit, char *data, int count)
{
int s;
int index = start;
while (count) {
s = rest_of_page(data);
if (s > count)
s = count;
BUG_ON(index > limit);
sg_unmark_end(&sg[index]);
sg_set_buf(&sg[index++], data, s);
count -= s;
data += s;
}
if (index-start)
sg_mark_end(&sg[index - 1]);
return index-start;
}
static int p9_virtio_cancel(struct p9_client *client, struct p9_req_t *req)
{
return 1;
}
static int
pack_sg_list_p(struct scatterlist *sg, int start, int limit,
struct page **pdata, int nr_pages, size_t offs, int count)
{
int i = 0, s;
int data_off = offs;
int index = start;
BUG_ON(nr_pages > (limit - start));
while (nr_pages) {
s = PAGE_SIZE - data_off;
if (s > count)
s = count;
sg_unmark_end(&sg[index]);
sg_set_page(&sg[index++], pdata[i++], s, data_off);
data_off = 0;
count -= s;
nr_pages--;
}
if (index-start)
sg_mark_end(&sg[index - 1]);
return index - start;
}
static int
p9_virtio_request(struct p9_client *client, struct p9_req_t *req)
{
int err;
int in, out, out_sgs, in_sgs;
unsigned long flags;
struct virtio_chan *chan = client->trans;
struct scatterlist *sgs[2];
p9_debug(P9_DEBUG_TRANS, "9p debug: virtio request\n");
req->status = REQ_STATUS_SENT;
req_retry:
spin_lock_irqsave(&chan->lock, flags);
out_sgs = in_sgs = 0;
out = pack_sg_list(chan->sg, 0,
VIRTQUEUE_NUM, req->tc->sdata, req->tc->size);
if (out)
sgs[out_sgs++] = chan->sg;
in = pack_sg_list(chan->sg, out,
VIRTQUEUE_NUM, req->rc->sdata, req->rc->capacity);
if (in)
sgs[out_sgs + in_sgs++] = chan->sg + out;
err = virtqueue_add_sgs(chan->vq, sgs, out_sgs, in_sgs, req->tc,
GFP_ATOMIC);
if (err < 0) {
if (err == -ENOSPC) {
chan->ring_bufs_avail = 0;
spin_unlock_irqrestore(&chan->lock, flags);
err = wait_event_interruptible(*chan->vc_wq,
chan->ring_bufs_avail);
if (err == -ERESTARTSYS)
return err;
p9_debug(P9_DEBUG_TRANS, "Retry virtio request\n");
goto req_retry;
} else {
spin_unlock_irqrestore(&chan->lock, flags);
p9_debug(P9_DEBUG_TRANS,
"virtio rpc add_sgs returned failure\n");
return -EIO;
}
}
virtqueue_kick(chan->vq);
spin_unlock_irqrestore(&chan->lock, flags);
p9_debug(P9_DEBUG_TRANS, "virtio request kicked\n");
return 0;
}
static int p9_get_mapped_pages(struct virtio_chan *chan,
struct page ***pages,
struct iov_iter *data,
int count,
size_t *offs,
int *need_drop)
{
int nr_pages;
int err;
if (!iov_iter_count(data))
return 0;
if (!(data->type & ITER_KVEC)) {
int n;
if (atomic_read(&vp_pinned) >= chan->p9_max_pages) {
err = wait_event_interruptible(vp_wq,
(atomic_read(&vp_pinned) < chan->p9_max_pages));
if (err == -ERESTARTSYS)
return err;
}
n = iov_iter_get_pages_alloc(data, pages, count, offs);
if (n < 0)
return n;
*need_drop = 1;
nr_pages = DIV_ROUND_UP(n + *offs, PAGE_SIZE);
atomic_add(nr_pages, &vp_pinned);
return n;
} else {
int index;
size_t len;
void *p;
while (1) {
len = iov_iter_single_seg_count(data);
if (likely(len)) {
p = data->kvec->iov_base + data->iov_offset;
break;
}
iov_iter_advance(data, 0);
}
if (len > count)
len = count;
nr_pages = DIV_ROUND_UP((unsigned long)p + len, PAGE_SIZE) -
(unsigned long)p / PAGE_SIZE;
*pages = kmalloc(sizeof(struct page *) * nr_pages, GFP_NOFS);
if (!*pages)
return -ENOMEM;
*need_drop = 0;
p -= (*offs = (unsigned long)p % PAGE_SIZE);
for (index = 0; index < nr_pages; index++) {
if (is_vmalloc_addr(p))
(*pages)[index] = vmalloc_to_page(p);
else
(*pages)[index] = kmap_to_page(p);
p += PAGE_SIZE;
}
return len;
}
}
static int
p9_virtio_zc_request(struct p9_client *client, struct p9_req_t *req,
struct iov_iter *uidata, struct iov_iter *uodata,
int inlen, int outlen, int in_hdr_len)
{
int in, out, err, out_sgs, in_sgs;
unsigned long flags;
int in_nr_pages = 0, out_nr_pages = 0;
struct page **in_pages = NULL, **out_pages = NULL;
struct virtio_chan *chan = client->trans;
struct scatterlist *sgs[4];
size_t offs;
int need_drop = 0;
p9_debug(P9_DEBUG_TRANS, "virtio request\n");
if (uodata) {
int n = p9_get_mapped_pages(chan, &out_pages, uodata,
outlen, &offs, &need_drop);
if (n < 0)
return n;
out_nr_pages = DIV_ROUND_UP(n + offs, PAGE_SIZE);
if (n != outlen) {
__le32 v = cpu_to_le32(n);
memcpy(&req->tc->sdata[req->tc->size - 4], &v, 4);
outlen = n;
}
} else if (uidata) {
int n = p9_get_mapped_pages(chan, &in_pages, uidata,
inlen, &offs, &need_drop);
if (n < 0)
return n;
in_nr_pages = DIV_ROUND_UP(n + offs, PAGE_SIZE);
if (n != inlen) {
__le32 v = cpu_to_le32(n);
memcpy(&req->tc->sdata[req->tc->size - 4], &v, 4);
inlen = n;
}
}
req->status = REQ_STATUS_SENT;
req_retry_pinned:
spin_lock_irqsave(&chan->lock, flags);
out_sgs = in_sgs = 0;
out = pack_sg_list(chan->sg, 0,
VIRTQUEUE_NUM, req->tc->sdata, req->tc->size);
if (out)
sgs[out_sgs++] = chan->sg;
if (out_pages) {
sgs[out_sgs++] = chan->sg + out;
out += pack_sg_list_p(chan->sg, out, VIRTQUEUE_NUM,
out_pages, out_nr_pages, offs, outlen);
}
in = pack_sg_list(chan->sg, out,
VIRTQUEUE_NUM, req->rc->sdata, in_hdr_len);
if (in)
sgs[out_sgs + in_sgs++] = chan->sg + out;
if (in_pages) {
sgs[out_sgs + in_sgs++] = chan->sg + out + in;
in += pack_sg_list_p(chan->sg, out + in, VIRTQUEUE_NUM,
in_pages, in_nr_pages, offs, inlen);
}
BUG_ON(out_sgs + in_sgs > ARRAY_SIZE(sgs));
err = virtqueue_add_sgs(chan->vq, sgs, out_sgs, in_sgs, req->tc,
GFP_ATOMIC);
if (err < 0) {
if (err == -ENOSPC) {
chan->ring_bufs_avail = 0;
spin_unlock_irqrestore(&chan->lock, flags);
err = wait_event_interruptible(*chan->vc_wq,
chan->ring_bufs_avail);
if (err == -ERESTARTSYS)
goto err_out;
p9_debug(P9_DEBUG_TRANS, "Retry virtio request\n");
goto req_retry_pinned;
} else {
spin_unlock_irqrestore(&chan->lock, flags);
p9_debug(P9_DEBUG_TRANS,
"virtio rpc add_sgs returned failure\n");
err = -EIO;
goto err_out;
}
}
virtqueue_kick(chan->vq);
spin_unlock_irqrestore(&chan->lock, flags);
p9_debug(P9_DEBUG_TRANS, "virtio request kicked\n");
err = wait_event_interruptible(*req->wq,
req->status >= REQ_STATUS_RCVD);
err_out:
if (need_drop) {
if (in_pages) {
p9_release_pages(in_pages, in_nr_pages);
atomic_sub(in_nr_pages, &vp_pinned);
}
if (out_pages) {
p9_release_pages(out_pages, out_nr_pages);
atomic_sub(out_nr_pages, &vp_pinned);
}
wake_up(&vp_wq);
}
kfree(in_pages);
kfree(out_pages);
return err;
}
static ssize_t p9_mount_tag_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct virtio_chan *chan;
struct virtio_device *vdev;
vdev = dev_to_virtio(dev);
chan = vdev->priv;
memcpy(buf, chan->tag, chan->tag_len);
buf[chan->tag_len] = 0;
return chan->tag_len + 1;
}
static int p9_virtio_probe(struct virtio_device *vdev)
{
__u16 tag_len;
char *tag;
int err;
struct virtio_chan *chan;
if (!vdev->config->get) {
dev_err(&vdev->dev, "%s failure: config access disabled\n",
__func__);
return -EINVAL;
}
chan = kmalloc(sizeof(struct virtio_chan), GFP_KERNEL);
if (!chan) {
pr_err("Failed to allocate virtio 9P channel\n");
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
virtio_cread(vdev, struct virtio_9p_config, tag_len, &tag_len);
} else {
err = -EINVAL;
goto out_free_vq;
}
tag = kmalloc(tag_len, GFP_KERNEL);
if (!tag) {
err = -ENOMEM;
goto out_free_vq;
}
virtio_cread_bytes(vdev, offsetof(struct virtio_9p_config, tag),
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
virtio_device_ready(vdev);
mutex_lock(&virtio_9p_lock);
list_add_tail(&chan->chan_list, &virtio_chan_list);
mutex_unlock(&virtio_9p_lock);
kobject_uevent(&(vdev->dev.kobj), KOBJ_CHANGE);
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
pr_err("no channels available\n");
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
unsigned long warning_time;
mutex_lock(&virtio_9p_lock);
list_del(&chan->chan_list);
warning_time = jiffies;
while (chan->inuse) {
mutex_unlock(&virtio_9p_lock);
msleep(250);
if (time_after(jiffies, warning_time + 10 * HZ)) {
dev_emerg(&vdev->dev,
"p9_virtio_remove: waiting for device in use.\n");
warning_time = jiffies;
}
mutex_lock(&virtio_9p_lock);
}
mutex_unlock(&virtio_9p_lock);
vdev->config->del_vqs(vdev);
sysfs_remove_file(&(vdev->dev.kobj), &dev_attr_mount_tag.attr);
kobject_uevent(&(vdev->dev.kobj), KOBJ_CHANGE);
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
