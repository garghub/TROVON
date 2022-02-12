static struct drm_file *drm_find_file(struct drm_master *master, drm_magic_t magic)
{
struct drm_file *retval = NULL;
struct drm_magic_entry *pt;
struct drm_hash_item *hash;
struct drm_device *dev = master->minor->dev;
mutex_lock(&dev->struct_mutex);
if (!drm_ht_find_item(&master->magiclist, (unsigned long)magic, &hash)) {
pt = drm_hash_entry(hash, struct drm_magic_entry, hash_item);
retval = pt->priv;
}
mutex_unlock(&dev->struct_mutex);
return retval;
}
static int drm_add_magic(struct drm_master *master, struct drm_file *priv,
drm_magic_t magic)
{
struct drm_magic_entry *entry;
struct drm_device *dev = master->minor->dev;
DRM_DEBUG("%d\n", magic);
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry)
return -ENOMEM;
entry->priv = priv;
entry->hash_item.key = (unsigned long)magic;
mutex_lock(&dev->struct_mutex);
drm_ht_insert_item(&master->magiclist, &entry->hash_item);
list_add_tail(&entry->head, &master->magicfree);
mutex_unlock(&dev->struct_mutex);
return 0;
}
int drm_remove_magic(struct drm_master *master, drm_magic_t magic)
{
struct drm_magic_entry *pt;
struct drm_hash_item *hash;
struct drm_device *dev = master->minor->dev;
DRM_DEBUG("%d\n", magic);
mutex_lock(&dev->struct_mutex);
if (drm_ht_find_item(&master->magiclist, (unsigned long)magic, &hash)) {
mutex_unlock(&dev->struct_mutex);
return -EINVAL;
}
pt = drm_hash_entry(hash, struct drm_magic_entry, hash_item);
drm_ht_remove_item(&master->magiclist, hash);
list_del(&pt->head);
mutex_unlock(&dev->struct_mutex);
kfree(pt);
return 0;
}
int drm_getmagic(struct drm_device *dev, void *data, struct drm_file *file_priv)
{
static drm_magic_t sequence = 0;
static DEFINE_SPINLOCK(lock);
struct drm_auth *auth = data;
if (file_priv->magic) {
auth->magic = file_priv->magic;
} else {
do {
spin_lock(&lock);
if (!sequence)
++sequence;
auth->magic = sequence++;
spin_unlock(&lock);
} while (drm_find_file(file_priv->master, auth->magic));
file_priv->magic = auth->magic;
drm_add_magic(file_priv->master, file_priv, auth->magic);
}
DRM_DEBUG("%u\n", auth->magic);
return 0;
}
int drm_authmagic(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_auth *auth = data;
struct drm_file *file;
DRM_DEBUG("%u\n", auth->magic);
if ((file = drm_find_file(file_priv->master, auth->magic))) {
file->authenticated = 1;
drm_remove_magic(file_priv->master, auth->magic);
return 0;
}
return -EINVAL;
}
