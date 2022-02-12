int virtcrypto_devmgr_add_dev(struct virtio_crypto *vcrypto_dev)
{
struct list_head *itr;
mutex_lock(&table_lock);
if (num_devices == VIRTIO_CRYPTO_MAX_DEVICES) {
pr_info("virtio_crypto: only support up to %d devices\n",
VIRTIO_CRYPTO_MAX_DEVICES);
mutex_unlock(&table_lock);
return -EFAULT;
}
list_for_each(itr, &virtio_crypto_table) {
struct virtio_crypto *ptr =
list_entry(itr, struct virtio_crypto, list);
if (ptr == vcrypto_dev) {
mutex_unlock(&table_lock);
return -EEXIST;
}
}
atomic_set(&vcrypto_dev->ref_count, 0);
list_add_tail(&vcrypto_dev->list, &virtio_crypto_table);
vcrypto_dev->dev_id = num_devices++;
mutex_unlock(&table_lock);
return 0;
}
struct list_head *virtcrypto_devmgr_get_head(void)
{
return &virtio_crypto_table;
}
void virtcrypto_devmgr_rm_dev(struct virtio_crypto *vcrypto_dev)
{
mutex_lock(&table_lock);
list_del(&vcrypto_dev->list);
num_devices--;
mutex_unlock(&table_lock);
}
struct virtio_crypto *virtcrypto_devmgr_get_first(void)
{
struct virtio_crypto *dev = NULL;
mutex_lock(&table_lock);
if (!list_empty(&virtio_crypto_table))
dev = list_first_entry(&virtio_crypto_table,
struct virtio_crypto,
list);
mutex_unlock(&table_lock);
return dev;
}
int virtcrypto_dev_in_use(struct virtio_crypto *vcrypto_dev)
{
return atomic_read(&vcrypto_dev->ref_count) != 0;
}
int virtcrypto_dev_get(struct virtio_crypto *vcrypto_dev)
{
if (atomic_add_return(1, &vcrypto_dev->ref_count) == 1)
if (!try_module_get(vcrypto_dev->owner))
return -EFAULT;
return 0;
}
void virtcrypto_dev_put(struct virtio_crypto *vcrypto_dev)
{
if (atomic_sub_return(1, &vcrypto_dev->ref_count) == 0)
module_put(vcrypto_dev->owner);
}
int virtcrypto_dev_started(struct virtio_crypto *vcrypto_dev)
{
return (vcrypto_dev->status & VIRTIO_CRYPTO_S_HW_READY);
}
struct virtio_crypto *virtcrypto_get_dev_node(int node)
{
struct virtio_crypto *vcrypto_dev = NULL, *tmp_dev;
unsigned long best = ~0;
unsigned long ctr;
mutex_lock(&table_lock);
list_for_each_entry(tmp_dev, virtcrypto_devmgr_get_head(), list) {
if ((node == dev_to_node(&tmp_dev->vdev->dev) ||
dev_to_node(&tmp_dev->vdev->dev) < 0) &&
virtcrypto_dev_started(tmp_dev)) {
ctr = atomic_read(&tmp_dev->ref_count);
if (best > ctr) {
vcrypto_dev = tmp_dev;
best = ctr;
}
}
}
if (!vcrypto_dev) {
pr_info("virtio_crypto: Could not find a device on node %d\n",
node);
list_for_each_entry(tmp_dev,
virtcrypto_devmgr_get_head(), list) {
if (virtcrypto_dev_started(tmp_dev)) {
vcrypto_dev = tmp_dev;
break;
}
}
}
mutex_unlock(&table_lock);
if (!vcrypto_dev)
return NULL;
virtcrypto_dev_get(vcrypto_dev);
return vcrypto_dev;
}
int virtcrypto_dev_start(struct virtio_crypto *vcrypto)
{
if (virtio_crypto_algs_register()) {
pr_err("virtio_crypto: Failed to register crypto algs\n");
return -EFAULT;
}
return 0;
}
void virtcrypto_dev_stop(struct virtio_crypto *vcrypto)
{
virtio_crypto_algs_unregister();
}
