static inline int ieee80211_networks_allocate(struct ieee80211_device *ieee)
{
if (ieee->networks)
return 0;
ieee->networks = kcalloc(
MAX_NETWORK_COUNT, sizeof(struct ieee80211_network),
GFP_KERNEL);
if (!ieee->networks) {
printk(KERN_WARNING "%s: Out of memory allocating beacons\n",
ieee->dev->name);
return -ENOMEM;
}
return 0;
}
static inline void ieee80211_networks_free(struct ieee80211_device *ieee)
{
if (!ieee->networks)
return;
kfree(ieee->networks);
ieee->networks = NULL;
}
static inline void ieee80211_networks_initialize(struct ieee80211_device *ieee)
{
int i;
INIT_LIST_HEAD(&ieee->network_free_list);
INIT_LIST_HEAD(&ieee->network_list);
for (i = 0; i < MAX_NETWORK_COUNT; i++)
list_add_tail(&ieee->networks[i].list, &ieee->network_free_list);
}
struct net_device *alloc_ieee80211(int sizeof_priv)
{
struct ieee80211_device *ieee;
struct net_device *dev;
int i,err;
IEEE80211_DEBUG_INFO("Initializing...\n");
dev = alloc_etherdev(sizeof(struct ieee80211_device) + sizeof_priv);
if (!dev) {
IEEE80211_ERROR("Unable to network device.\n");
goto failed;
}
ieee = netdev_priv(dev);
ieee->dev = dev;
err = ieee80211_networks_allocate(ieee);
if (err) {
IEEE80211_ERROR("Unable to allocate beacon storage: %d\n",
err);
goto failed;
}
ieee80211_networks_initialize(ieee);
ieee->fts = DEFAULT_FTS;
ieee->scan_age = DEFAULT_MAX_SCAN_AGE;
ieee->open_wep = 1;
ieee->host_encrypt = 1;
ieee->host_decrypt = 1;
ieee->ieee802_1x = 1;
INIT_LIST_HEAD(&ieee->crypt_deinit_list);
init_timer(&ieee->crypt_deinit_timer);
ieee->crypt_deinit_timer.data = (unsigned long)ieee;
ieee->crypt_deinit_timer.function = ieee80211_crypt_deinit_handler;
spin_lock_init(&ieee->lock);
spin_lock_init(&ieee->wpax_suitlist_lock);
ieee->wpax_type_set = 0;
ieee->wpa_enabled = 0;
ieee->tkip_countermeasures = 0;
ieee->drop_unencrypted = 0;
ieee->privacy_invoked = 0;
ieee->ieee802_1x = 1;
ieee->raw_tx = 0;
ieee80211_softmac_init(ieee);
for (i = 0; i < IEEE_IBSS_MAC_HASH_SIZE; i++)
INIT_LIST_HEAD(&ieee->ibss_mac_hash[i]);
for (i = 0; i < 17; i++) {
ieee->last_rxseq_num[i] = -1;
ieee->last_rxfrag_num[i] = -1;
ieee->last_packet_time[i] = 0;
}
ieee80211_tkip_null();
ieee80211_wep_null();
ieee80211_ccmp_null();
return dev;
failed:
if (dev)
free_netdev(dev);
return NULL;
}
void free_ieee80211(struct net_device *dev)
{
struct ieee80211_device *ieee = netdev_priv(dev);
int i;
struct list_head *p, *q;
ieee80211_softmac_free(ieee);
del_timer_sync(&ieee->crypt_deinit_timer);
ieee80211_crypt_deinit_entries(ieee, 1);
for (i = 0; i < WEP_KEYS; i++) {
struct ieee80211_crypt_data *crypt = ieee->crypt[i];
if (crypt) {
if (crypt->ops)
crypt->ops->deinit(crypt->priv);
kfree(crypt);
ieee->crypt[i] = NULL;
}
}
ieee80211_networks_free(ieee);
for (i = 0; i < IEEE_IBSS_MAC_HASH_SIZE; i++) {
list_for_each_safe(p, q, &ieee->ibss_mac_hash[i]) {
kfree(list_entry(p, struct ieee_ibss_seq, list));
list_del(p);
}
}
free_netdev(dev);
}
