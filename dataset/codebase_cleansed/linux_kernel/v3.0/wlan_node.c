bss_t *
wlan_node_alloc(struct ieee80211_node_table *nt, int wh_size)
{
bss_t *ni;
ni = A_MALLOC_NOWAIT(sizeof(bss_t));
if (ni != NULL) {
if (wh_size)
{
ni->ni_buf = A_MALLOC_NOWAIT(wh_size);
if (ni->ni_buf == NULL) {
kfree(ni);
ni = NULL;
return ni;
}
}
} else {
return ni;
}
ni->ni_list_next = NULL;
ni->ni_list_prev = NULL;
ni->ni_hash_next = NULL;
ni->ni_hash_prev = NULL;
ni->ni_scangen = 0;
#ifdef OS_ROAM_MANAGEMENT
ni->ni_si_gen = 0;
#endif
return ni;
}
void
wlan_node_free(bss_t *ni)
{
if (ni->ni_buf != NULL) {
kfree(ni->ni_buf);
}
kfree(ni);
}
void
wlan_setup_node(struct ieee80211_node_table *nt, bss_t *ni,
const u8 *macaddr)
{
int hash;
u32 timeoutValue = 0;
memcpy(ni->ni_macaddr, macaddr, IEEE80211_ADDR_LEN);
hash = IEEE80211_NODE_HASH (macaddr);
ieee80211_node_initref (ni);
timeoutValue = nt->nt_nodeAge;
ni->ni_tstamp = A_GET_MS (0);
ni->ni_actcnt = WLAN_NODE_INACT_CNT;
IEEE80211_NODE_LOCK_BH(nt);
ni->ni_list_next = NULL;
ni->ni_list_prev = nt->nt_node_last;
if(nt->nt_node_last != NULL)
{
nt->nt_node_last->ni_list_next = ni;
}
nt->nt_node_last = ni;
if(nt->nt_node_first == NULL)
{
nt->nt_node_first = ni;
}
if((ni->ni_hash_next = nt->nt_hash[hash]) != NULL)
{
nt->nt_hash[hash]->ni_hash_prev = ni;
}
ni->ni_hash_prev = NULL;
nt->nt_hash[hash] = ni;
#ifdef THREAD_X
if (!nt->isTimerArmed) {
A_TIMEOUT_MS(&nt->nt_inact_timer, timeoutValue, 0);
nt->isTimerArmed = true;
}
#endif
IEEE80211_NODE_UNLOCK_BH(nt);
}
static bss_t *
_ieee80211_find_node(struct ieee80211_node_table *nt,
const u8 *macaddr)
{
bss_t *ni;
int hash;
IEEE80211_NODE_LOCK_ASSERT(nt);
hash = IEEE80211_NODE_HASH(macaddr);
for(ni = nt->nt_hash[hash]; ni; ni = ni->ni_hash_next) {
if (IEEE80211_ADDR_EQ(ni->ni_macaddr, macaddr)) {
ieee80211_node_incref(ni);
return ni;
}
}
return NULL;
}
bss_t *
wlan_find_node(struct ieee80211_node_table *nt, const u8 *macaddr)
{
bss_t *ni;
IEEE80211_NODE_LOCK(nt);
ni = _ieee80211_find_node(nt, macaddr);
IEEE80211_NODE_UNLOCK(nt);
return ni;
}
void
wlan_node_reclaim(struct ieee80211_node_table *nt, bss_t *ni)
{
IEEE80211_NODE_LOCK(nt);
if(ni->ni_list_prev == NULL)
{
nt->nt_node_first = ni->ni_list_next;
}
else
{
ni->ni_list_prev->ni_list_next = ni->ni_list_next;
}
if(ni->ni_list_next == NULL)
{
nt->nt_node_last = ni->ni_list_prev;
}
else
{
ni->ni_list_next->ni_list_prev = ni->ni_list_prev;
}
if(ni->ni_hash_prev == NULL)
{
int hash;
hash = IEEE80211_NODE_HASH(ni->ni_macaddr);
nt->nt_hash[hash] = ni->ni_hash_next;
}
else
{
ni->ni_hash_prev->ni_hash_next = ni->ni_hash_next;
}
if(ni->ni_hash_next != NULL)
{
ni->ni_hash_next->ni_hash_prev = ni->ni_hash_prev;
}
wlan_node_free(ni);
IEEE80211_NODE_UNLOCK(nt);
}
static void
wlan_node_dec_free(bss_t *ni)
{
if (ieee80211_node_dectestref(ni)) {
wlan_node_free(ni);
}
}
void
wlan_free_allnodes(struct ieee80211_node_table *nt)
{
bss_t *ni;
while ((ni = nt->nt_node_first) != NULL) {
wlan_node_reclaim(nt, ni);
}
}
void
wlan_iterate_nodes(struct ieee80211_node_table *nt, wlan_node_iter_func *f,
void *arg)
{
bss_t *ni;
u32 gen;
gen = ++nt->nt_scangen;
IEEE80211_NODE_LOCK(nt);
for (ni = nt->nt_node_first; ni; ni = ni->ni_list_next) {
if (ni->ni_scangen != gen) {
ni->ni_scangen = gen;
(void) ieee80211_node_incref(ni);
(*f)(arg, ni);
wlan_node_dec_free(ni);
}
}
IEEE80211_NODE_UNLOCK(nt);
}
void
wlan_node_table_init(void *wmip, struct ieee80211_node_table *nt)
{
int i;
AR_DEBUG_PRINTF(ATH_DEBUG_WLAN, ("node table = 0x%lx\n", (unsigned long)nt));
IEEE80211_NODE_LOCK_INIT(nt);
A_REGISTER_MODULE_DEBUG_INFO(wlan);
nt->nt_node_first = nt->nt_node_last = NULL;
for(i = 0; i < IEEE80211_NODE_HASHSIZE; i++)
{
nt->nt_hash[i] = NULL;
}
#ifdef THREAD_X
A_INIT_TIMER(&nt->nt_inact_timer, wlan_node_timeout, nt);
nt->isTimerArmed = false;
#endif
nt->nt_wmip = wmip;
nt->nt_nodeAge = WLAN_NODE_INACT_TIMEOUT_MSEC;
nt->nt_scangen = 0;
#ifdef OS_ROAM_MANAGEMENT
nt->nt_si_gen = 0;
#endif
}
void
wlan_set_nodeage(struct ieee80211_node_table *nt, u32 nodeAge)
{
nt->nt_nodeAge = nodeAge;
return;
}
void
wlan_refresh_inactive_nodes (struct ieee80211_node_table *nt)
{
#ifdef THREAD_X
bss_t *bss, *nextBss;
u8 myBssid[IEEE80211_ADDR_LEN], reArmTimer = false;
wmi_get_current_bssid(nt->nt_wmip, myBssid);
bss = nt->nt_node_first;
while (bss != NULL)
{
nextBss = bss->ni_list_next;
if (memcmp(myBssid, bss->ni_macaddr, sizeof(myBssid)) != 0)
{
wlan_node_reclaim(nt, bss);
}
bss = nextBss;
}
#else
bss_t *bss, *nextBss;
u8 myBssid[IEEE80211_ADDR_LEN];
u32 timeoutValue = 0;
u32 now = A_GET_MS(0);
timeoutValue = nt->nt_nodeAge;
wmi_get_current_bssid(nt->nt_wmip, myBssid);
bss = nt->nt_node_first;
while (bss != NULL)
{
nextBss = bss->ni_list_next;
if (memcmp(myBssid, bss->ni_macaddr, sizeof(myBssid)) != 0)
{
if (((now - bss->ni_tstamp) > timeoutValue) || --bss->ni_actcnt == 0)
{
wlan_node_reclaim(nt, bss);
}
}
bss = nextBss;
}
#endif
}
static void
wlan_node_timeout (unsigned long arg)
{
struct ieee80211_node_table *nt = (struct ieee80211_node_table *)arg;
bss_t *bss, *nextBss;
u8 myBssid[IEEE80211_ADDR_LEN], reArmTimer = false;
u32 timeoutValue = 0;
u32 now = A_GET_MS(0);
timeoutValue = nt->nt_nodeAge;
wmi_get_current_bssid(nt->nt_wmip, myBssid);
bss = nt->nt_node_first;
while (bss != NULL)
{
nextBss = bss->ni_list_next;
if (memcmp(myBssid, bss->ni_macaddr, sizeof(myBssid)) != 0)
{
if ((now - bss->ni_tstamp) > timeoutValue)
{
wlan_node_reclaim(nt, bss);
}
else
{
reArmTimer = true;
}
}
bss = nextBss;
}
if (reArmTimer)
A_TIMEOUT_MS (&nt->nt_inact_timer, timeoutValue, 0);
nt->isTimerArmed = reArmTimer;
}
void
wlan_node_table_cleanup(struct ieee80211_node_table *nt)
{
#ifdef THREAD_X
A_UNTIMEOUT(&nt->nt_inact_timer);
A_DELETE_TIMER(&nt->nt_inact_timer);
#endif
wlan_free_allnodes(nt);
IEEE80211_NODE_LOCK_DESTROY(nt);
}
bss_t *
wlan_find_Ssidnode (struct ieee80211_node_table *nt, u8 *pSsid,
u32 ssidLength, bool bIsWPA2, bool bMatchSSID)
{
bss_t *ni = NULL;
u8 *pIESsid = NULL;
IEEE80211_NODE_LOCK (nt);
for (ni = nt->nt_node_first; ni; ni = ni->ni_list_next) {
pIESsid = ni->ni_cie.ie_ssid;
if (pIESsid[1] <= 32) {
if (0x00 == memcmp (pSsid, &pIESsid[2], ssidLength)) {
if (true == bMatchSSID) {
ieee80211_node_incref (ni);
IEEE80211_NODE_UNLOCK (nt);
return ni;
}
if (true == bIsWPA2 && NULL != ni->ni_cie.ie_rsn) {
ieee80211_node_incref (ni);
IEEE80211_NODE_UNLOCK (nt);
return ni;
}
if (false == bIsWPA2 && NULL != ni->ni_cie.ie_wpa) {
ieee80211_node_incref(ni);
IEEE80211_NODE_UNLOCK (nt);
return ni;
}
}
}
}
IEEE80211_NODE_UNLOCK (nt);
return NULL;
}
void
wlan_node_return (struct ieee80211_node_table *nt, bss_t *ni)
{
IEEE80211_NODE_LOCK (nt);
wlan_node_dec_free (ni);
IEEE80211_NODE_UNLOCK (nt);
}
void
wlan_node_remove_core (struct ieee80211_node_table *nt, bss_t *ni)
{
if(ni->ni_list_prev == NULL)
{
nt->nt_node_first = ni->ni_list_next;
}
else
{
ni->ni_list_prev->ni_list_next = ni->ni_list_next;
}
if(ni->ni_list_next == NULL)
{
nt->nt_node_last = ni->ni_list_prev;
}
else
{
ni->ni_list_next->ni_list_prev = ni->ni_list_prev;
}
if(ni->ni_hash_prev == NULL)
{
int hash;
hash = IEEE80211_NODE_HASH(ni->ni_macaddr);
nt->nt_hash[hash] = ni->ni_hash_next;
}
else
{
ni->ni_hash_prev->ni_hash_next = ni->ni_hash_next;
}
if(ni->ni_hash_next != NULL)
{
ni->ni_hash_next->ni_hash_prev = ni->ni_hash_prev;
}
}
bss_t *
wlan_node_remove(struct ieee80211_node_table *nt, u8 *bssid)
{
bss_t *bss, *nextBss;
IEEE80211_NODE_LOCK(nt);
bss = nt->nt_node_first;
while (bss != NULL)
{
nextBss = bss->ni_list_next;
if (memcmp(bssid, bss->ni_macaddr, 6) == 0)
{
wlan_node_remove_core (nt, bss);
IEEE80211_NODE_UNLOCK(nt);
return bss;
}
bss = nextBss;
}
IEEE80211_NODE_UNLOCK(nt);
return NULL;
}
bss_t *
wlan_find_matching_Ssidnode (struct ieee80211_node_table *nt, u8 *pSsid,
u32 ssidLength, u32 dot11AuthMode, u32 authMode,
u32 pairwiseCryptoType, u32 grpwiseCryptoTyp)
{
bss_t *ni = NULL;
bss_t *best_ni = NULL;
u8 *pIESsid = NULL;
IEEE80211_NODE_LOCK (nt);
for (ni = nt->nt_node_first; ni; ni = ni->ni_list_next) {
pIESsid = ni->ni_cie.ie_ssid;
if (pIESsid[1] <= 32) {
if (0x00 == memcmp (pSsid, &pIESsid[2], ssidLength)) {
if (ni->ni_cie.ie_capInfo & 0x10)
{
if ((NULL != ni->ni_cie.ie_rsn) && (WPA2_PSK_AUTH == authMode))
{
if (NULL == best_ni)
{
best_ni = ni;
}
else if (ni->ni_rssi > best_ni->ni_rssi)
{
best_ni = ni;
}
}
else if ((NULL != ni->ni_cie.ie_wpa) && (WPA_PSK_AUTH == authMode))
{
if (NULL == best_ni)
{
best_ni = ni;
}
else if (ni->ni_rssi > best_ni->ni_rssi)
{
best_ni = ni;
}
}
else if (WEP_CRYPT == pairwiseCryptoType)
{
if (NULL == best_ni)
{
best_ni = ni;
}
else if (ni->ni_rssi > best_ni->ni_rssi)
{
best_ni = ni;
}
}
}
else
{
if ((OPEN_AUTH == authMode) && (NONE_CRYPT == pairwiseCryptoType))
{
if (NULL == best_ni)
{
best_ni = ni;
}
else if (ni->ni_rssi > best_ni->ni_rssi)
{
best_ni = ni;
}
}
}
}
}
}
IEEE80211_NODE_UNLOCK (nt);
return best_ni;
}
