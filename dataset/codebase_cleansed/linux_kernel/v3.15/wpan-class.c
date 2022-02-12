static ssize_t channels_supported_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct wpan_phy *phy = container_of(dev, struct wpan_phy, dev);
int ret;
int i, len = 0;
mutex_lock(&phy->pib_lock);
for (i = 0; i < 32; i++) {
ret = snprintf(buf + len, PAGE_SIZE - len,
"%#09x\n", phy->channels_supported[i]);
if (ret < 0)
break;
len += ret;
}
mutex_unlock(&phy->pib_lock);
return len;
}
static void wpan_phy_release(struct device *d)
{
struct wpan_phy *phy = container_of(d, struct wpan_phy, dev);
kfree(phy);
}
static int wpan_phy_match(struct device *dev, const void *data)
{
return !strcmp(dev_name(dev), (const char *)data);
}
struct wpan_phy *wpan_phy_find(const char *str)
{
struct device *dev;
if (WARN_ON(!str))
return NULL;
dev = class_find_device(&wpan_phy_class, NULL, str, wpan_phy_match);
if (!dev)
return NULL;
return container_of(dev, struct wpan_phy, dev);
}
static int wpan_phy_iter(struct device *dev, void *_data)
{
struct wpan_phy_iter_data *wpid = _data;
struct wpan_phy *phy = container_of(dev, struct wpan_phy, dev);
return wpid->fn(phy, wpid->data);
}
int wpan_phy_for_each(int (*fn)(struct wpan_phy *phy, void *data),
void *data)
{
struct wpan_phy_iter_data wpid = {
.fn = fn,
.data = data,
};
return class_for_each_device(&wpan_phy_class, NULL,
&wpid, wpan_phy_iter);
}
static int wpan_phy_idx_valid(int idx)
{
return idx >= 0;
}
struct wpan_phy *wpan_phy_alloc(size_t priv_size)
{
struct wpan_phy *phy = kzalloc(sizeof(*phy) + priv_size,
GFP_KERNEL);
if (!phy)
goto out;
mutex_lock(&wpan_phy_mutex);
phy->idx = wpan_phy_idx++;
if (unlikely(!wpan_phy_idx_valid(phy->idx))) {
wpan_phy_idx--;
mutex_unlock(&wpan_phy_mutex);
kfree(phy);
goto out;
}
mutex_unlock(&wpan_phy_mutex);
mutex_init(&phy->pib_lock);
device_initialize(&phy->dev);
dev_set_name(&phy->dev, "wpan-phy%d", phy->idx);
phy->dev.class = &wpan_phy_class;
phy->current_channel = -1;
phy->current_page = 0;
return phy;
out:
return NULL;
}
int wpan_phy_register(struct wpan_phy *phy)
{
return device_add(&phy->dev);
}
void wpan_phy_unregister(struct wpan_phy *phy)
{
device_del(&phy->dev);
}
void wpan_phy_free(struct wpan_phy *phy)
{
put_device(&phy->dev);
}
static int __init wpan_phy_class_init(void)
{
int rc;
rc = class_register(&wpan_phy_class);
if (rc)
goto err;
rc = ieee802154_nl_init();
if (rc)
goto err_nl;
return 0;
err_nl:
class_unregister(&wpan_phy_class);
err:
return rc;
}
static void __exit wpan_phy_class_exit(void)
{
ieee802154_nl_exit();
class_unregister(&wpan_phy_class);
}
