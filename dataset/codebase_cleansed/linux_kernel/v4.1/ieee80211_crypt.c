void ieee80211_crypt_deinit_entries(struct ieee80211_device *ieee,
int force)
{
struct list_head *ptr, *n;
struct ieee80211_crypt_data *entry;
for (ptr = ieee->crypt_deinit_list.next, n = ptr->next;
ptr != &ieee->crypt_deinit_list; ptr = n, n = ptr->next) {
entry = list_entry(ptr, struct ieee80211_crypt_data, list);
if (atomic_read(&entry->refcnt) != 0 && !force)
continue;
list_del(ptr);
if (entry->ops)
entry->ops->deinit(entry->priv);
kfree(entry);
}
}
void ieee80211_crypt_deinit_handler(unsigned long data)
{
struct ieee80211_device *ieee = (struct ieee80211_device *)data;
unsigned long flags;
spin_lock_irqsave(&ieee->lock, flags);
ieee80211_crypt_deinit_entries(ieee, 0);
if (!list_empty(&ieee->crypt_deinit_list)) {
netdev_dbg(ieee->dev, "%s: entries remaining in delayed crypt deletion list\n",
ieee->dev->name);
ieee->crypt_deinit_timer.expires = jiffies + HZ;
add_timer(&ieee->crypt_deinit_timer);
}
spin_unlock_irqrestore(&ieee->lock, flags);
}
void ieee80211_crypt_delayed_deinit(struct ieee80211_device *ieee,
struct ieee80211_crypt_data **crypt)
{
struct ieee80211_crypt_data *tmp;
unsigned long flags;
if (*crypt == NULL)
return;
tmp = *crypt;
*crypt = NULL;
spin_lock_irqsave(&ieee->lock, flags);
list_add(&tmp->list, &ieee->crypt_deinit_list);
if (!timer_pending(&ieee->crypt_deinit_timer)) {
ieee->crypt_deinit_timer.expires = jiffies + HZ;
add_timer(&ieee->crypt_deinit_timer);
}
spin_unlock_irqrestore(&ieee->lock, flags);
}
int ieee80211_register_crypto_ops(struct ieee80211_crypto_ops *ops)
{
unsigned long flags;
struct ieee80211_crypto_alg *alg;
if (hcrypt == NULL)
return -1;
alg = kzalloc(sizeof(*alg), GFP_KERNEL);
if (alg == NULL)
return -ENOMEM;
alg->ops = ops;
spin_lock_irqsave(&hcrypt->lock, flags);
list_add(&alg->list, &hcrypt->algs);
spin_unlock_irqrestore(&hcrypt->lock, flags);
pr_debug("ieee80211_crypt: registered algorithm '%s'\n",
ops->name);
return 0;
}
int ieee80211_unregister_crypto_ops(struct ieee80211_crypto_ops *ops)
{
unsigned long flags;
struct list_head *ptr;
struct ieee80211_crypto_alg *del_alg = NULL;
if (hcrypt == NULL)
return -1;
spin_lock_irqsave(&hcrypt->lock, flags);
for (ptr = hcrypt->algs.next; ptr != &hcrypt->algs; ptr = ptr->next) {
struct ieee80211_crypto_alg *alg =
(struct ieee80211_crypto_alg *) ptr;
if (alg->ops == ops) {
list_del(&alg->list);
del_alg = alg;
break;
}
}
spin_unlock_irqrestore(&hcrypt->lock, flags);
if (del_alg) {
pr_debug("ieee80211_crypt: unregistered algorithm '%s'\n",
ops->name);
kfree(del_alg);
}
return del_alg ? 0 : -1;
}
struct ieee80211_crypto_ops *ieee80211_get_crypto_ops(const char *name)
{
unsigned long flags;
struct list_head *ptr;
struct ieee80211_crypto_alg *found_alg = NULL;
if (hcrypt == NULL)
return NULL;
spin_lock_irqsave(&hcrypt->lock, flags);
for (ptr = hcrypt->algs.next; ptr != &hcrypt->algs; ptr = ptr->next) {
struct ieee80211_crypto_alg *alg =
(struct ieee80211_crypto_alg *) ptr;
if (strcmp(alg->ops->name, name) == 0) {
found_alg = alg;
break;
}
}
spin_unlock_irqrestore(&hcrypt->lock, flags);
if (found_alg)
return found_alg->ops;
else
return NULL;
}
static void *ieee80211_crypt_null_init(int keyidx) { return (void *) 1; }
static void ieee80211_crypt_null_deinit(void *priv) {}
int __init ieee80211_crypto_init(void)
{
int ret = -ENOMEM;
hcrypt = kzalloc(sizeof(*hcrypt), GFP_KERNEL);
if (!hcrypt)
goto out;
INIT_LIST_HEAD(&hcrypt->algs);
spin_lock_init(&hcrypt->lock);
ret = ieee80211_register_crypto_ops(&ieee80211_crypt_null);
if (ret < 0) {
kfree(hcrypt);
hcrypt = NULL;
}
out:
return ret;
}
void __exit ieee80211_crypto_deinit(void)
{
struct list_head *ptr, *n;
if (hcrypt == NULL)
return;
for (ptr = hcrypt->algs.next, n = ptr->next; ptr != &hcrypt->algs;
ptr = n, n = ptr->next) {
struct ieee80211_crypto_alg *alg =
(struct ieee80211_crypto_alg *) ptr;
list_del(ptr);
pr_debug("ieee80211_crypt: unregistered algorithm '%s' (deinit)\n",
alg->ops->name);
kfree(alg);
}
kfree(hcrypt);
}
