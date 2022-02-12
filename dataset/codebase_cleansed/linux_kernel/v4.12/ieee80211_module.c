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
int i, err;
IEEE80211_DEBUG_INFO("Initializing...\n");
dev = alloc_etherdev(sizeof(struct ieee80211_device) + sizeof_priv);
if (!dev) {
IEEE80211_ERROR("Unable to network device.\n");
goto failed;
}
ieee = netdev_priv(dev);
memset(ieee, 0, sizeof(struct ieee80211_device)+sizeof_priv);
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
setup_timer(&ieee->crypt_deinit_timer,
ieee80211_crypt_deinit_handler, (unsigned long)ieee);
spin_lock_init(&ieee->lock);
spin_lock_init(&ieee->wpax_suitlist_lock);
spin_lock_init(&ieee->bw_spinlock);
spin_lock_init(&ieee->reorder_spinlock);
atomic_set(&ieee->atm_chnlop, 0);
atomic_set(&ieee->atm_swbw, 0);
ieee->wpax_type_set = 0;
ieee->wpa_enabled = 0;
ieee->tkip_countermeasures = 0;
ieee->drop_unencrypted = 0;
ieee->privacy_invoked = 0;
ieee->ieee802_1x = 1;
ieee->raw_tx = 0;
ieee->hwsec_active = 0;
ieee80211_softmac_init(ieee);
ieee->pHTInfo = kzalloc(sizeof(RT_HIGH_THROUGHPUT), GFP_KERNEL);
if (ieee->pHTInfo == NULL)
{
IEEE80211_DEBUG(IEEE80211_DL_ERR, "can't alloc memory for HTInfo\n");
goto failed;
}
HTUpdateDefaultSetting(ieee);
HTInitializeHTInfo(ieee);
TSInitialize(ieee);
for (i = 0; i < IEEE_IBSS_MAC_HASH_SIZE; i++)
INIT_LIST_HEAD(&ieee->ibss_mac_hash[i]);
for (i = 0; i < 17; i++) {
ieee->last_rxseq_num[i] = -1;
ieee->last_rxfrag_num[i] = -1;
ieee->last_packet_time[i] = 0;
}
ieee80211_tkip_null();
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
kfree(ieee->pHTInfo);
ieee->pHTInfo = NULL;
RemoveAllTS(ieee);
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
free_netdev(dev);
}
static int show_debug_level(struct seq_file *m, void *v)
{
seq_printf(m, "0x%08X\n", ieee80211_debug_level);
return 0;
}
static ssize_t write_debug_level(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
unsigned long val;
int err = kstrtoul_from_user(buffer, count, 0, &val);
if (err)
return err;
ieee80211_debug_level = val;
return count;
}
static int open_debug_level(struct inode *inode, struct file *file)
{
return single_open(file, show_debug_level, NULL);
}
int __init ieee80211_debug_init(void)
{
struct proc_dir_entry *e;
ieee80211_debug_level = debug;
ieee80211_proc = proc_mkdir(DRV_NAME, init_net.proc_net);
if (ieee80211_proc == NULL) {
IEEE80211_ERROR("Unable to create " DRV_NAME
" proc directory\n");
return -EIO;
}
e = proc_create("debug_level", 0644, ieee80211_proc, &fops);
if (!e) {
remove_proc_entry(DRV_NAME, init_net.proc_net);
ieee80211_proc = NULL;
return -EIO;
}
return 0;
}
void __exit ieee80211_debug_exit(void)
{
if (ieee80211_proc) {
remove_proc_entry("debug_level", ieee80211_proc);
remove_proc_entry(DRV_NAME, init_net.proc_net);
ieee80211_proc = NULL;
}
}
