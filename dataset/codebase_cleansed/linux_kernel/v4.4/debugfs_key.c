static ssize_t key_algorithm_read(struct file *file,
char __user *userbuf,
size_t count, loff_t *ppos)
{
char buf[15];
struct ieee80211_key *key = file->private_data;
u32 c = key->conf.cipher;
sprintf(buf, "%.2x-%.2x-%.2x:%d\n",
c >> 24, (c >> 16) & 0xff, (c >> 8) & 0xff, c & 0xff);
return simple_read_from_buffer(userbuf, count, ppos, buf, strlen(buf));
}
static ssize_t key_tx_spec_write(struct file *file, const char __user *userbuf,
size_t count, loff_t *ppos)
{
struct ieee80211_key *key = file->private_data;
u64 pn;
int ret;
switch (key->conf.cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
return -EINVAL;
case WLAN_CIPHER_SUITE_TKIP:
return -EOPNOTSUPP;
case WLAN_CIPHER_SUITE_CCMP:
case WLAN_CIPHER_SUITE_CCMP_256:
case WLAN_CIPHER_SUITE_AES_CMAC:
case WLAN_CIPHER_SUITE_BIP_CMAC_256:
case WLAN_CIPHER_SUITE_BIP_GMAC_128:
case WLAN_CIPHER_SUITE_BIP_GMAC_256:
case WLAN_CIPHER_SUITE_GCMP:
case WLAN_CIPHER_SUITE_GCMP_256:
ret = kstrtou64_from_user(userbuf, count, 16, &pn);
if (ret)
return ret;
if (pn >= (1ULL << 48))
return -ERANGE;
atomic64_set(&key->conf.tx_pn, pn);
return count;
default:
return 0;
}
}
static ssize_t key_tx_spec_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
u64 pn;
char buf[20];
int len;
struct ieee80211_key *key = file->private_data;
switch (key->conf.cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
len = scnprintf(buf, sizeof(buf), "\n");
break;
case WLAN_CIPHER_SUITE_TKIP:
len = scnprintf(buf, sizeof(buf), "%08x %04x\n",
key->u.tkip.tx.iv32,
key->u.tkip.tx.iv16);
break;
case WLAN_CIPHER_SUITE_CCMP:
case WLAN_CIPHER_SUITE_CCMP_256:
case WLAN_CIPHER_SUITE_AES_CMAC:
case WLAN_CIPHER_SUITE_BIP_CMAC_256:
case WLAN_CIPHER_SUITE_BIP_GMAC_128:
case WLAN_CIPHER_SUITE_BIP_GMAC_256:
case WLAN_CIPHER_SUITE_GCMP:
case WLAN_CIPHER_SUITE_GCMP_256:
pn = atomic64_read(&key->conf.tx_pn);
len = scnprintf(buf, sizeof(buf), "%02x%02x%02x%02x%02x%02x\n",
(u8)(pn >> 40), (u8)(pn >> 32), (u8)(pn >> 24),
(u8)(pn >> 16), (u8)(pn >> 8), (u8)pn);
break;
default:
return 0;
}
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static ssize_t key_rx_spec_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct ieee80211_key *key = file->private_data;
char buf[14*IEEE80211_NUM_TIDS+1], *p = buf;
int i, len;
const u8 *rpn;
switch (key->conf.cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
len = scnprintf(buf, sizeof(buf), "\n");
break;
case WLAN_CIPHER_SUITE_TKIP:
for (i = 0; i < IEEE80211_NUM_TIDS; i++)
p += scnprintf(p, sizeof(buf)+buf-p,
"%08x %04x\n",
key->u.tkip.rx[i].iv32,
key->u.tkip.rx[i].iv16);
len = p - buf;
break;
case WLAN_CIPHER_SUITE_CCMP:
case WLAN_CIPHER_SUITE_CCMP_256:
for (i = 0; i < IEEE80211_NUM_TIDS + 1; i++) {
rpn = key->u.ccmp.rx_pn[i];
p += scnprintf(p, sizeof(buf)+buf-p,
"%02x%02x%02x%02x%02x%02x\n",
rpn[0], rpn[1], rpn[2],
rpn[3], rpn[4], rpn[5]);
}
len = p - buf;
break;
case WLAN_CIPHER_SUITE_AES_CMAC:
case WLAN_CIPHER_SUITE_BIP_CMAC_256:
rpn = key->u.aes_cmac.rx_pn;
p += scnprintf(p, sizeof(buf)+buf-p,
"%02x%02x%02x%02x%02x%02x\n",
rpn[0], rpn[1], rpn[2],
rpn[3], rpn[4], rpn[5]);
len = p - buf;
break;
case WLAN_CIPHER_SUITE_BIP_GMAC_128:
case WLAN_CIPHER_SUITE_BIP_GMAC_256:
rpn = key->u.aes_gmac.rx_pn;
p += scnprintf(p, sizeof(buf)+buf-p,
"%02x%02x%02x%02x%02x%02x\n",
rpn[0], rpn[1], rpn[2],
rpn[3], rpn[4], rpn[5]);
len = p - buf;
break;
case WLAN_CIPHER_SUITE_GCMP:
case WLAN_CIPHER_SUITE_GCMP_256:
for (i = 0; i < IEEE80211_NUM_TIDS + 1; i++) {
rpn = key->u.gcmp.rx_pn[i];
p += scnprintf(p, sizeof(buf)+buf-p,
"%02x%02x%02x%02x%02x%02x\n",
rpn[0], rpn[1], rpn[2],
rpn[3], rpn[4], rpn[5]);
}
len = p - buf;
break;
default:
return 0;
}
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static ssize_t key_replays_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct ieee80211_key *key = file->private_data;
char buf[20];
int len;
switch (key->conf.cipher) {
case WLAN_CIPHER_SUITE_CCMP:
case WLAN_CIPHER_SUITE_CCMP_256:
len = scnprintf(buf, sizeof(buf), "%u\n", key->u.ccmp.replays);
break;
case WLAN_CIPHER_SUITE_AES_CMAC:
case WLAN_CIPHER_SUITE_BIP_CMAC_256:
len = scnprintf(buf, sizeof(buf), "%u\n",
key->u.aes_cmac.replays);
break;
case WLAN_CIPHER_SUITE_BIP_GMAC_128:
case WLAN_CIPHER_SUITE_BIP_GMAC_256:
len = scnprintf(buf, sizeof(buf), "%u\n",
key->u.aes_gmac.replays);
break;
case WLAN_CIPHER_SUITE_GCMP:
case WLAN_CIPHER_SUITE_GCMP_256:
len = scnprintf(buf, sizeof(buf), "%u\n", key->u.gcmp.replays);
break;
default:
return 0;
}
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static ssize_t key_icverrors_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct ieee80211_key *key = file->private_data;
char buf[20];
int len;
switch (key->conf.cipher) {
case WLAN_CIPHER_SUITE_AES_CMAC:
case WLAN_CIPHER_SUITE_BIP_CMAC_256:
len = scnprintf(buf, sizeof(buf), "%u\n",
key->u.aes_cmac.icverrors);
break;
case WLAN_CIPHER_SUITE_BIP_GMAC_128:
case WLAN_CIPHER_SUITE_BIP_GMAC_256:
len = scnprintf(buf, sizeof(buf), "%u\n",
key->u.aes_gmac.icverrors);
break;
default:
return 0;
}
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static ssize_t key_mic_failures_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct ieee80211_key *key = file->private_data;
char buf[20];
int len;
if (key->conf.cipher != WLAN_CIPHER_SUITE_TKIP)
return -EINVAL;
len = scnprintf(buf, sizeof(buf), "%u\n", key->u.tkip.mic_failures);
return simple_read_from_buffer(userbuf, count, ppos, buf, len);
}
static ssize_t key_key_read(struct file *file, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct ieee80211_key *key = file->private_data;
int i, bufsize = 2 * key->conf.keylen + 2;
char *buf = kmalloc(bufsize, GFP_KERNEL);
char *p = buf;
ssize_t res;
if (!buf)
return -ENOMEM;
for (i = 0; i < key->conf.keylen; i++)
p += scnprintf(p, bufsize + buf - p, "%02x", key->conf.key[i]);
p += scnprintf(p, bufsize+buf-p, "\n");
res = simple_read_from_buffer(userbuf, count, ppos, buf, p - buf);
kfree(buf);
return res;
}
void ieee80211_debugfs_key_add(struct ieee80211_key *key)
{
static int keycount;
char buf[100];
struct sta_info *sta;
if (!key->local->debugfs.keys)
return;
sprintf(buf, "%d", keycount);
key->debugfs.cnt = keycount;
keycount++;
key->debugfs.dir = debugfs_create_dir(buf,
key->local->debugfs.keys);
if (!key->debugfs.dir)
return;
sta = key->sta;
if (sta) {
sprintf(buf, "../../netdev:%s/stations/%pM",
sta->sdata->name, sta->sta.addr);
key->debugfs.stalink =
debugfs_create_symlink("station", key->debugfs.dir, buf);
}
DEBUGFS_ADD(keylen);
DEBUGFS_ADD(flags);
DEBUGFS_ADD(keyidx);
DEBUGFS_ADD(hw_key_idx);
DEBUGFS_ADD(algorithm);
DEBUGFS_ADD_W(tx_spec);
DEBUGFS_ADD(rx_spec);
DEBUGFS_ADD(replays);
DEBUGFS_ADD(icverrors);
DEBUGFS_ADD(mic_failures);
DEBUGFS_ADD(key);
DEBUGFS_ADD(ifindex);
}
void ieee80211_debugfs_key_remove(struct ieee80211_key *key)
{
if (!key)
return;
debugfs_remove_recursive(key->debugfs.dir);
key->debugfs.dir = NULL;
}
void ieee80211_debugfs_key_update_default(struct ieee80211_sub_if_data *sdata)
{
char buf[50];
struct ieee80211_key *key;
if (!sdata->vif.debugfs_dir)
return;
lockdep_assert_held(&sdata->local->key_mtx);
debugfs_remove(sdata->debugfs.default_unicast_key);
sdata->debugfs.default_unicast_key = NULL;
if (sdata->default_unicast_key) {
key = key_mtx_dereference(sdata->local,
sdata->default_unicast_key);
sprintf(buf, "../keys/%d", key->debugfs.cnt);
sdata->debugfs.default_unicast_key =
debugfs_create_symlink("default_unicast_key",
sdata->vif.debugfs_dir, buf);
}
debugfs_remove(sdata->debugfs.default_multicast_key);
sdata->debugfs.default_multicast_key = NULL;
if (sdata->default_multicast_key) {
key = key_mtx_dereference(sdata->local,
sdata->default_multicast_key);
sprintf(buf, "../keys/%d", key->debugfs.cnt);
sdata->debugfs.default_multicast_key =
debugfs_create_symlink("default_multicast_key",
sdata->vif.debugfs_dir, buf);
}
}
void ieee80211_debugfs_key_add_mgmt_default(struct ieee80211_sub_if_data *sdata)
{
char buf[50];
struct ieee80211_key *key;
if (!sdata->vif.debugfs_dir)
return;
key = key_mtx_dereference(sdata->local,
sdata->default_mgmt_key);
if (key) {
sprintf(buf, "../keys/%d", key->debugfs.cnt);
sdata->debugfs.default_mgmt_key =
debugfs_create_symlink("default_mgmt_key",
sdata->vif.debugfs_dir, buf);
} else
ieee80211_debugfs_key_remove_mgmt_default(sdata);
}
void ieee80211_debugfs_key_remove_mgmt_default(struct ieee80211_sub_if_data *sdata)
{
if (!sdata)
return;
debugfs_remove(sdata->debugfs.default_mgmt_key);
sdata->debugfs.default_mgmt_key = NULL;
}
void ieee80211_debugfs_key_sta_del(struct ieee80211_key *key,
struct sta_info *sta)
{
debugfs_remove(key->debugfs.stalink);
key->debugfs.stalink = NULL;
}
