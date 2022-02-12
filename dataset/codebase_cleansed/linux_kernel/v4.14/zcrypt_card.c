static ssize_t zcrypt_card_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zcrypt_card *zc = to_ap_card(dev)->private;
return snprintf(buf, PAGE_SIZE, "%s\n", zc->type_string);
}
static ssize_t zcrypt_card_online_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct zcrypt_card *zc = to_ap_card(dev)->private;
return snprintf(buf, PAGE_SIZE, "%d\n", zc->online);
}
static ssize_t zcrypt_card_online_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct zcrypt_card *zc = to_ap_card(dev)->private;
struct zcrypt_queue *zq;
int online, id;
if (sscanf(buf, "%d\n", &online) != 1 || online < 0 || online > 1)
return -EINVAL;
zc->online = online;
id = zc->card->id;
ZCRYPT_DBF(DBF_INFO, "card=%02x online=%d\n", id, online);
spin_lock(&zcrypt_list_lock);
list_for_each_entry(zq, &zc->zqueues, list)
zcrypt_queue_force_online(zq, online);
spin_unlock(&zcrypt_list_lock);
return count;
}
struct zcrypt_card *zcrypt_card_alloc(void)
{
struct zcrypt_card *zc;
zc = kzalloc(sizeof(struct zcrypt_card), GFP_KERNEL);
if (!zc)
return NULL;
INIT_LIST_HEAD(&zc->list);
INIT_LIST_HEAD(&zc->zqueues);
kref_init(&zc->refcount);
return zc;
}
void zcrypt_card_free(struct zcrypt_card *zc)
{
kfree(zc);
}
static void zcrypt_card_release(struct kref *kref)
{
struct zcrypt_card *zdev =
container_of(kref, struct zcrypt_card, refcount);
zcrypt_card_free(zdev);
}
void zcrypt_card_get(struct zcrypt_card *zc)
{
kref_get(&zc->refcount);
}
int zcrypt_card_put(struct zcrypt_card *zc)
{
return kref_put(&zc->refcount, zcrypt_card_release);
}
int zcrypt_card_register(struct zcrypt_card *zc)
{
int rc;
rc = sysfs_create_group(&zc->card->ap_dev.device.kobj,
&zcrypt_card_attr_group);
if (rc)
return rc;
spin_lock(&zcrypt_list_lock);
list_add_tail(&zc->list, &zcrypt_card_list);
spin_unlock(&zcrypt_list_lock);
zc->online = 1;
ZCRYPT_DBF(DBF_INFO, "card=%02x register online=1\n", zc->card->id);
return rc;
}
void zcrypt_card_unregister(struct zcrypt_card *zc)
{
ZCRYPT_DBF(DBF_INFO, "card=%02x unregister\n", zc->card->id);
spin_lock(&zcrypt_list_lock);
list_del_init(&zc->list);
spin_unlock(&zcrypt_list_lock);
sysfs_remove_group(&zc->card->ap_dev.device.kobj,
&zcrypt_card_attr_group);
}
