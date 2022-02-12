static ssize_t zcrypt_queue_online_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct zcrypt_queue *zq = to_ap_queue(dev)->private;
return snprintf(buf, PAGE_SIZE, "%d\n", zq->online);
}
static ssize_t zcrypt_queue_online_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct zcrypt_queue *zq = to_ap_queue(dev)->private;
struct zcrypt_card *zc = zq->zcard;
int online;
if (sscanf(buf, "%d\n", &online) != 1 || online < 0 || online > 1)
return -EINVAL;
if (online && !zc->online)
return -EINVAL;
zq->online = online;
ZCRYPT_DBF(DBF_INFO, "queue=%02x.%04x online=%d\n",
AP_QID_CARD(zq->queue->qid),
AP_QID_QUEUE(zq->queue->qid),
online);
if (!online)
ap_flush_queue(zq->queue);
return count;
}
void zcrypt_queue_force_online(struct zcrypt_queue *zq, int online)
{
zq->online = online;
if (!online)
ap_flush_queue(zq->queue);
}
struct zcrypt_queue *zcrypt_queue_alloc(size_t max_response_size)
{
struct zcrypt_queue *zq;
zq = kzalloc(sizeof(struct zcrypt_queue), GFP_KERNEL);
if (!zq)
return NULL;
zq->reply.message = kmalloc(max_response_size, GFP_KERNEL);
if (!zq->reply.message)
goto out_free;
zq->reply.length = max_response_size;
INIT_LIST_HEAD(&zq->list);
kref_init(&zq->refcount);
return zq;
out_free:
kfree(zq);
return NULL;
}
void zcrypt_queue_free(struct zcrypt_queue *zq)
{
kfree(zq->reply.message);
kfree(zq);
}
static void zcrypt_queue_release(struct kref *kref)
{
struct zcrypt_queue *zq =
container_of(kref, struct zcrypt_queue, refcount);
zcrypt_queue_free(zq);
}
void zcrypt_queue_get(struct zcrypt_queue *zq)
{
kref_get(&zq->refcount);
}
int zcrypt_queue_put(struct zcrypt_queue *zq)
{
return kref_put(&zq->refcount, zcrypt_queue_release);
}
int zcrypt_queue_register(struct zcrypt_queue *zq)
{
struct zcrypt_card *zc;
int rc;
spin_lock(&zcrypt_list_lock);
zc = zq->queue->card->private;
zcrypt_card_get(zc);
zq->zcard = zc;
zq->online = 1;
ZCRYPT_DBF(DBF_INFO, "queue=%02x.%04x register online=1\n",
AP_QID_CARD(zq->queue->qid), AP_QID_QUEUE(zq->queue->qid));
list_add_tail(&zq->list, &zc->zqueues);
zcrypt_device_count++;
spin_unlock(&zcrypt_list_lock);
rc = sysfs_create_group(&zq->queue->ap_dev.device.kobj,
&zcrypt_queue_attr_group);
if (rc)
goto out;
get_device(&zq->queue->ap_dev.device);
if (zq->ops->rng) {
rc = zcrypt_rng_device_add();
if (rc)
goto out_unregister;
}
return 0;
out_unregister:
sysfs_remove_group(&zq->queue->ap_dev.device.kobj,
&zcrypt_queue_attr_group);
put_device(&zq->queue->ap_dev.device);
out:
spin_lock(&zcrypt_list_lock);
list_del_init(&zq->list);
spin_unlock(&zcrypt_list_lock);
zcrypt_card_put(zc);
return rc;
}
void zcrypt_queue_unregister(struct zcrypt_queue *zq)
{
struct zcrypt_card *zc;
ZCRYPT_DBF(DBF_INFO, "queue=%02x.%04x unregister\n",
AP_QID_CARD(zq->queue->qid), AP_QID_QUEUE(zq->queue->qid));
zc = zq->zcard;
spin_lock(&zcrypt_list_lock);
list_del_init(&zq->list);
zcrypt_device_count--;
spin_unlock(&zcrypt_list_lock);
zcrypt_card_put(zc);
if (zq->ops->rng)
zcrypt_rng_device_remove();
sysfs_remove_group(&zq->queue->ap_dev.device.kobj,
&zcrypt_queue_attr_group);
put_device(&zq->queue->ap_dev.device);
zcrypt_queue_put(zq);
}
