void _setup_timer(struct timer_list *ptimer, void *fun, unsigned long data)
{
ptimer->function = fun;
ptimer->data = data;
init_timer(ptimer);
}
static inline int rtllib_networks_allocate(struct rtllib_device *ieee)
{
if (ieee->networks)
return 0;
ieee->networks = kzalloc(
MAX_NETWORK_COUNT * sizeof(struct rtllib_network),
GFP_KERNEL);
if (!ieee->networks)
return -ENOMEM;
return 0;
}
static inline void rtllib_networks_free(struct rtllib_device *ieee)
{
if (!ieee->networks)
return;
kfree(ieee->networks);
ieee->networks = NULL;
}
static inline void rtllib_networks_initialize(struct rtllib_device *ieee)
{
int i;
INIT_LIST_HEAD(&ieee->network_free_list);
INIT_LIST_HEAD(&ieee->network_list);
for (i = 0; i < MAX_NETWORK_COUNT; i++)
list_add_tail(&ieee->networks[i].list,
&ieee->network_free_list);
}
struct net_device *alloc_rtllib(int sizeof_priv)
{
struct rtllib_device *ieee = NULL;
struct net_device *dev;
int i, err;
RTLLIB_DEBUG_INFO("Initializing...\n");
dev = alloc_etherdev(sizeof(struct rtllib_device) + sizeof_priv);
if (!dev) {
RTLLIB_ERROR("Unable to network device.\n");
return NULL;
}
ieee = (struct rtllib_device *)netdev_priv_rsl(dev);
memset(ieee, 0, sizeof(struct rtllib_device)+sizeof_priv);
ieee->dev = dev;
err = rtllib_networks_allocate(ieee);
if (err) {
RTLLIB_ERROR("Unable to allocate beacon storage: %d\n",
err);
goto failed;
}
rtllib_networks_initialize(ieee);
ieee->fts = DEFAULT_FTS;
ieee->scan_age = DEFAULT_MAX_SCAN_AGE;
ieee->open_wep = 1;
ieee->host_encrypt = 1;
ieee->host_decrypt = 1;
ieee->ieee802_1x = 1;
ieee->rtllib_ap_sec_type = rtllib_ap_sec_type;
spin_lock_init(&ieee->lock);
spin_lock_init(&ieee->wpax_suitlist_lock);
spin_lock_init(&ieee->bw_spinlock);
spin_lock_init(&ieee->reorder_spinlock);
atomic_set(&(ieee->atm_chnlop), 0);
atomic_set(&(ieee->atm_swbw), 0);
lib80211_crypt_info_init(&ieee->crypt_info, "RTLLIB", &ieee->lock);
ieee->bHalfNMode = false;
ieee->wpa_enabled = 0;
ieee->tkip_countermeasures = 0;
ieee->drop_unencrypted = 0;
ieee->privacy_invoked = 0;
ieee->ieee802_1x = 1;
ieee->raw_tx = 0;
ieee->hwsec_active = 0;
memset(ieee->swcamtable, 0, sizeof(struct sw_cam_table) * 32);
rtllib_softmac_init(ieee);
ieee->pHTInfo = kzalloc(sizeof(struct rt_hi_throughput), GFP_KERNEL);
if (ieee->pHTInfo == NULL)
return NULL;
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
return dev;
failed:
free_netdev(dev);
return NULL;
}
void free_rtllib(struct net_device *dev)
{
struct rtllib_device *ieee = (struct rtllib_device *)
netdev_priv_rsl(dev);
kfree(ieee->pHTInfo);
ieee->pHTInfo = NULL;
rtllib_softmac_free(ieee);
lib80211_crypt_info_free(&ieee->crypt_info);
rtllib_networks_free(ieee);
free_netdev(dev);
}
static int show_debug_level(struct seq_file *m, void *v)
{
seq_printf(m, "0x%08X\n", rtllib_debug_level);
return 0;
}
static ssize_t write_debug_level(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
unsigned long val;
int err = kstrtoul_from_user(buffer, count, 0, &val);
if (err)
return err;
rtllib_debug_level = val;
return count;
}
static int open_debug_level(struct inode *inode, struct file *file)
{
return single_open(file, show_debug_level, NULL);
}
static int __init rtllib_init(void)
{
struct proc_dir_entry *e;
rtllib_debug_level = debug;
rtllib_proc = proc_mkdir(DRV_NAME, init_net.proc_net);
if (rtllib_proc == NULL) {
RTLLIB_ERROR("Unable to create " DRV_NAME
" proc directory\n");
return -EIO;
}
e = proc_create("debug_level", S_IRUGO | S_IWUSR, rtllib_proc, &fops);
if (!e) {
remove_proc_entry(DRV_NAME, init_net.proc_net);
rtllib_proc = NULL;
return -EIO;
}
return 0;
}
static void __exit rtllib_exit(void)
{
if (rtllib_proc) {
remove_proc_entry("debug_level", rtllib_proc);
remove_proc_entry(DRV_NAME, init_net.proc_net);
rtllib_proc = NULL;
}
}
