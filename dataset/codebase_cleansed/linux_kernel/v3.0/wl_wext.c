static int wireless_commit(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *rqu, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
DBG_FUNC( "wireless_commit" );
DBG_ENTER(DbgInfo);
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
wl_apply(lp);
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_protocol(struct net_device *dev, struct iw_request_info *info, char *name, char *extra)
{
DBG_FUNC( "wireless_get_protocol" );
DBG_ENTER( DbgInfo );
strcpy(name, "IEEE 802.11b");
DBG_LEAVE(DbgInfo);
return 0;
}
static int wireless_set_frequency(struct net_device *dev, struct iw_request_info *info, struct iw_freq *freq, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int channel = 0;
int ret = 0;
DBG_FUNC( "wireless_set_frequency" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
if( !capable( CAP_NET_ADMIN )) {
ret = -EPERM;
DBG_LEAVE( DbgInfo );
return ret;
}
if( freq->e == 1 ) {
int f = freq->m / 100000;
channel = wl_get_chan_from_freq( f );
}
if( freq->e == 0 ) {
channel = freq->m;
}
if( channel > 14 ) {
channel = channel | 0x100;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
lp->Channel = channel;
wl_apply( lp );
wl_wext_event_freq( lp->dev );
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_frequency(struct net_device *dev, struct iw_request_info *info, struct iw_freq *freq, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = -1;
DBG_FUNC( "wireless_get_frequency" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
lp->ltvRecord.len = 2;
lp->ltvRecord.typ = CFG_CUR_CHANNEL;
ret = hcf_get_info( &(lp->hcfCtx), (LTVP)&( lp->ltvRecord ));
if( ret == HCF_SUCCESS ) {
hcf_16 channel = CNV_LITTLE_TO_INT( lp->ltvRecord.u.u16[0] );
#ifdef USE_FREQUENCY
freq->m = wl_get_freq_from_chan( channel ) * 100000;
freq->e = 1;
#else
freq->m = channel;
freq->e = 0;
#endif
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
ret = (ret == HCF_SUCCESS ? 0 : -EFAULT);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_range(struct net_device *dev, struct iw_request_info *info, struct iw_point *data, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
struct iw_range *range = (struct iw_range *) extra;
int ret = 0;
int status = -1;
int count;
__u16 *pTxRate;
int retries = 0;
DBG_FUNC( "wireless_get_range" );
DBG_ENTER( DbgInfo );
data->length = sizeof(struct iw_range);
memset(range, 0, sizeof(struct iw_range));
wl_lock( lp, &flags );
wl_act_int_off( lp );
memset( range, 0, sizeof( struct iw_range ));
retry:
lp->ltvRecord.len = 1 + (sizeof(*pTxRate) / sizeof(hcf_16));
lp->ltvRecord.typ = CFG_CUR_TX_RATE;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status != HCF_SUCCESS ) {
DBG_TRACE( DbgInfo, "Get CFG_CUR_TX_RATE failed: 0x%x\n", status );
if (retries < 10) {
retries++;
wl_unlock(lp, &flags);
wl_lock( lp, &flags );
status = wl_reset( dev );
if ( status != HCF_SUCCESS ) {
DBG_TRACE( DbgInfo, "reset failed: 0x%x\n", status );
ret = -EFAULT;
goto out_unlock;
}
wl_unlock(lp, &flags);
wl_lock( lp, &flags );
goto retry;
} else {
DBG_TRACE( DbgInfo, "Get CFG_CUR_TX_RATE failed: %d retries\n", retries );
ret = -EFAULT;
goto out_unlock;
}
}
wl_unlock(lp, &flags);
wl_lock( lp, &flags );
pTxRate = (__u16 *)&( lp->ltvRecord.u.u32 );
range->throughput = CNV_LITTLE_TO_INT( *pTxRate ) * MEGABIT;
if (retries > 0) {
DBG_TRACE( DbgInfo, "Get CFG_CUR_TX_RATE succes: %d retries\n", retries );
}
range->num_channels = RADIO_CHANNELS;
range->sensitivity = RADIO_SENSITIVITY_LEVELS;
#ifdef USE_DBM
range->max_qual.qual = (u_char)HCF_MAX_COMM_QUALITY;
range->max_qual.level = (u_char)( dbm( HCF_MIN_SIGNAL_LEVEL ) - 1 );
range->max_qual.noise = (u_char)( dbm( HCF_MIN_NOISE_LEVEL ) - 1 );
#else
range->max_qual.qual = 100;
range->max_qual.level = 100;
range->max_qual.noise = 100;
#endif
range->num_bitrates = 0;
lp->ltvRecord.len = 6;
lp->ltvRecord.typ = CFG_SUPPORTED_DATA_RATES;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
for( count = 0; count < MAX_RATES; count++ )
if( lp->ltvRecord.u.u8[count+2] != 0 ) {
range->bitrate[count] = lp->ltvRecord.u.u8[count+2] * MEGABIT / 2;
range->num_bitrates++;
}
} else {
DBG_TRACE( DbgInfo, "CFG_SUPPORTED_DATA_RATES: 0x%x\n", status );
ret = -EFAULT;
goto out_unlock;
}
range->min_rts = MIN_RTS_BYTES;
range->max_rts = MAX_RTS_BYTES;
#if WIRELESS_EXT > 8
wl_unlock(lp, &flags);
wl_lock( lp, &flags );
if( wl_has_wep( &( lp->hcfCtx ))) {
range->encoding_size[0] = MIN_KEY_SIZE;
range->encoding_size[1] = MAX_KEY_SIZE;
range->num_encoding_sizes = 2;
range->max_encoding_tokens = MAX_KEYS;
}
#endif
range->txpower_capa = IW_TXPOW_MWATT;
range->num_txpower = 1;
range->txpower[0] = RADIO_TX_POWER_MWATT;
#if WIRELESS_EXT > 10
range->we_version_compiled = WIRELESS_EXT;
range->we_version_source = WIRELESS_SUPPORT;
#endif
#if WIRELESS_EXT > 11
wl_unlock(lp, &flags);
wl_lock( lp, &flags );
DBG_TRACE( DbgInfo, "calling wl_wireless_stats\n" );
wl_wireless_stats( lp->dev );
range->avg_qual = lp->wstats.qual;
DBG_TRACE( DbgInfo, "wl_wireless_stats done\n" );
#endif
range->event_capa[0] = (IW_EVENT_CAPA_K_0 |
IW_EVENT_CAPA_MASK(SIOCGIWAP) |
IW_EVENT_CAPA_MASK(SIOCGIWSCAN));
range->event_capa[1] = IW_EVENT_CAPA_K_1;
range->event_capa[4] = (IW_EVENT_CAPA_MASK(IWEVREGISTERED) |
IW_EVENT_CAPA_MASK(IWEVCUSTOM) |
IW_EVENT_CAPA_MASK(IWEVEXPIRED));
range->enc_capa = IW_ENC_CAPA_WPA | IW_ENC_CAPA_CIPHER_TKIP;
out_unlock:
wl_act_int_on( lp );
wl_unlock(lp, &flags);
DBG_LEAVE(DbgInfo);
return ret;
}
static int wireless_get_bssid(struct net_device *dev, struct iw_request_info *info, struct sockaddr *ap_addr, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
#if 1
int status = -1;
#endif
DBG_FUNC( "wireless_get_bssid" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
memset( &ap_addr->sa_data, 0, ETH_ALEN );
ap_addr->sa_family = ARPHRD_ETHER;
memcpy(&ap_addr->sa_data, lp->dev->dev_addr, ETH_ALEN);
#if 1
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_STA ) {
lp->ltvRecord.typ = CFG_CUR_BSSID;
lp->ltvRecord.len = 4;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
memcpy(&ap_addr->sa_data, lp->ltvRecord.u.u8, ETH_ALEN);
} else {
ret = -EFAULT;
}
}
#endif
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE(DbgInfo);
return ret;
}
static int wireless_get_ap_list (struct net_device *dev, struct iw_request_info *info, struct iw_point *data, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret;
int num_aps = -1;
int sec_count = 0;
hcf_32 count;
struct sockaddr *hwa = NULL;
struct iw_quality *qual = NULL;
#ifdef WARP
ScanResult *p = &lp->scan_results;
#else
ProbeResult *p = &lp->probe_results;
#endif
DBG_FUNC( "wireless_get_ap_list" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
lp->scan_results.scan_complete = FALSE;
lp->probe_results.scan_complete = FALSE;
lp->ltvRecord.len = 2;
lp->ltvRecord.typ = CFG_SCAN_CHANNELS_2GHZ;
lp->ltvRecord.u.u16[0] = CNV_INT_TO_LITTLE( 0x7FFF );
ret = hcf_put_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
DBG_TRACE( DbgInfo, "CFG_SCAN_CHANNELS_2GHZ result: 0x%x\n", ret );
lp->ltvRecord.len = 2;
lp->ltvRecord.typ = CFG_SCAN_SSID;
lp->ltvRecord.u.u16[0] = CNV_INT_TO_LITTLE( 0 );
ret = hcf_put_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
DBG_TRACE( DbgInfo, "CFG_SCAN_SSID to 'any' ret: 0x%x\n", ret );
#ifdef WARP
ret = hcf_action( &( lp->hcfCtx ), MDD_ACT_SCAN );
#else
ret = hcf_action( &( lp->hcfCtx ), HCF_ACT_ACS_SCAN );
#endif
wl_act_int_on( lp );
wl_unlock(lp, &flags);
if( ret == HCF_SUCCESS ) {
DBG_TRACE( DbgInfo, "SUCCESSFULLY INITIATED SCAN...\n" );
while( (*p).scan_complete == FALSE && ret == HCF_SUCCESS ) {
DBG_TRACE( DbgInfo, "Waiting for scan results...\n" );
if( sec_count++ > MAX_SCAN_TIME_SEC ) {
ret = -EIO;
} else {
for( count = 0; count < 100; count ++ ) {
mdelay( 10 );
schedule( );
}
}
}
rmb();
if ( ret != HCF_SUCCESS ) {
DBG_ERROR( DbgInfo, "timeout waiting for scan results\n" );
} else {
num_aps = (*p).num_aps;
if (num_aps > IW_MAX_AP) {
num_aps = IW_MAX_AP;
}
data->length = num_aps;
hwa = (struct sockaddr *)extra;
qual = (struct iw_quality *) extra +
( sizeof( struct sockaddr ) * num_aps );
data->flags = 0;
for( count = 0; count < num_aps; count++ ) {
#ifdef WARP
memcpy( hwa[count].sa_data,
(*p).APTable[count].bssid, ETH_ALEN );
#else
DBG_PRINT("BSSID: %pM\n",
(*p).ProbeTable[count].BSSID);
memcpy( hwa[count].sa_data,
(*p).ProbeTable[count].BSSID, ETH_ALEN );
#endif
}
(*p).scan_complete = FALSE;
wl_wext_event_scan_complete( lp->dev );
}
}
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_sensitivity(struct net_device *dev, struct iw_request_info *info, struct iw_param *sens, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
int dens = sens->value;
DBG_FUNC( "wireless_set_sensitivity" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
if(( dens < 1 ) || ( dens > 3 )) {
ret = -EINVAL;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
lp->DistanceBetweenAPs = dens;
wl_apply( lp );
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_sensitivity(struct net_device *dev, struct iw_request_info *info, struct iw_param *sens, char *extra)
{
struct wl_private *lp = wl_priv(dev);
int ret = 0;
DBG_FUNC( "wireless_get_sensitivity" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
sens->value = lp->DistanceBetweenAPs;
sens->fixed = 0;
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_essid(struct net_device *dev, struct iw_request_info *info, struct iw_point *data, char *ssid)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
DBG_FUNC( "wireless_set_essid" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
if (data->flags != 0 && data->length > HCF_MAX_NAME_LEN + 1) {
ret = -EINVAL;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
memset( lp->NetworkName, 0, sizeof( lp->NetworkName ));
if( data->flags == 0 ) {
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_STA ) {
strcpy( lp->NetworkName, "ANY" );
} else {
strcpy( lp->NetworkName, PARM_DEFAULT_SSID );
}
} else {
memcpy( lp->NetworkName, ssid, data->length );
}
DBG_NOTICE( DbgInfo, "set NetworkName: %s\n", ssid );
wl_apply( lp );
wl_wext_event_essid( lp->dev );
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_essid(struct net_device *dev, struct iw_request_info *info, struct iw_point *data, char *essid)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
int status = -1;
wvName_t *pName;
DBG_FUNC( "wireless_get_essid" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
lp->ltvRecord.len = 1 + ( sizeof( *pName ) / sizeof( hcf_16 ));
#if 1
lp->ltvRecord.typ = CFG_DESIRED_SSID;
#endif
#if 1
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ) {
lp->ltvRecord.typ = CFG_CNF_OWN_SSID;
}
#endif
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
pName = (wvName_t *)&( lp->ltvRecord.u.u32 );
pName->length = CNV_LITTLE_TO_INT( pName->length );
data->length = pName->length;
data->length = pName->length + 1;
if( pName->length < HCF_MAX_NAME_LEN ) {
pName->name[pName->length] = '\0';
}
data->flags = 1;
#if 1
#ifdef RETURN_CURRENT_NETWORKNAME
if( pName->name[0] == '\0' ) {
lp->ltvRecord.len = 1 + ( sizeof(*pName ) / sizeof( hcf_16 ));
lp->ltvRecord.typ = CFG_CUR_SSID;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
pName = (wvName_t *)&( lp->ltvRecord.u.u32 );
pName->length = CNV_LITTLE_TO_INT( pName->length );
data->length = pName->length + 1;
if( pName->length < HCF_MAX_NAME_LEN ) {
pName->name[pName->length] = '\0';
}
data->flags = 1;
} else {
ret = -EFAULT;
goto out_unlock;
}
}
#endif
#endif
data->length--;
if (pName->length > IW_ESSID_MAX_SIZE) {
ret = -EFAULT;
goto out_unlock;
}
memcpy(essid, pName->name, pName->length);
} else {
ret = -EFAULT;
goto out_unlock;
}
out_unlock:
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_encode(struct net_device *dev, struct iw_request_info *info, struct iw_point *erq, char *keybuf)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
#if 1
hcf_8 encryption_state;
#endif
DBG_FUNC( "wireless_set_encode" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
if( !wl_has_wep( &( lp->hcfCtx ))) {
DBG_WARNING( DbgInfo, "WEP not supported on this device\n" );
ret = -EOPNOTSUPP;
goto out_unlock;
}
DBG_NOTICE( DbgInfo, "pointer: %p, length: %d, flags: %#x\n",
keybuf, erq->length,
erq->flags);
encryption_state = lp->EnableEncryption;
if((erq->length) != 0) {
int index = ( erq->flags & IW_ENCODE_INDEX ) - 1;
int tk = lp->TransmitKeyID - 1;
switch(erq->length) {
case 0:
break;
case MIN_KEY_SIZE:
case MAX_KEY_SIZE:
if(( index < 0 ) || ( index >= MAX_KEYS )) {
index = tk;
}
memset( lp->DefaultKeys.key[index].key, 0, MAX_KEY_SIZE );
memcpy( lp->DefaultKeys.key[index].key, keybuf, erq->length);
lp->DefaultKeys.key[index].len = erq->length;
DBG_NOTICE( DbgInfo, "encoding.length: %d\n", erq->length );
DBG_NOTICE( DbgInfo, "set key: %s(%d) [%d]\n", lp->DefaultKeys.key[index].key,
lp->DefaultKeys.key[index].len, index );
if(( index == tk ) && ( lp->DefaultKeys.key[tk].len > 0 )) {
lp->EnableEncryption = 1;
}
break;
default:
DBG_WARNING( DbgInfo, "Invalid Key length\n" );
ret = -EINVAL;
goto out_unlock;
}
} else {
int index = ( erq->flags & IW_ENCODE_INDEX ) - 1;
if(( index >= 0 ) && ( index < MAX_KEYS )) {
DBG_NOTICE( DbgInfo, "index: %d; len: %d\n", index,
lp->DefaultKeys.key[index].len );
if( lp->DefaultKeys.key[index].len > 0 ) {
lp->TransmitKeyID = index + 1;
lp->EnableEncryption = 1;
} else {
DBG_WARNING( DbgInfo, "Problem setting the current TxKey\n" );
DBG_LEAVE( DbgInfo );
ret = -EINVAL;
}
}
}
if( erq->flags & IW_ENCODE_DISABLED ) {
lp->EnableEncryption = 0;
} else {
lp->EnableEncryption = 1;
}
if( erq->flags & IW_ENCODE_RESTRICTED ) {
DBG_WARNING( DbgInfo, "IW_ENCODE_RESTRICTED invalid\n" );
ret = -EINVAL;
}
DBG_TRACE( DbgInfo, "encryption_state : %d\n", encryption_state );
DBG_TRACE( DbgInfo, "lp->EnableEncryption : %d\n", lp->EnableEncryption );
DBG_TRACE( DbgInfo, "erq->length : %d\n",
erq->length);
DBG_TRACE( DbgInfo, "erq->flags : 0x%x\n",
erq->flags);
if( ret == 0 ) {
DBG_NOTICE( DbgInfo, "encrypt: %d, ID: %d\n", lp->EnableEncryption,
lp->TransmitKeyID );
if( lp->EnableEncryption == encryption_state ) {
if( erq->length != 0 ) {
wl_set_wep_keys( lp );
}
} else {
wl_apply( lp );
}
}
wl_wext_event_encode( dev );
out_unlock:
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_encode(struct net_device *dev, struct iw_request_info *info, struct iw_point *erq, char *key)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
int index;
DBG_FUNC( "wireless_get_encode" );
DBG_ENTER( DbgInfo );
DBG_NOTICE(DbgInfo, "GIWENCODE: encrypt: %d, ID: %d\n", lp->EnableEncryption, lp->TransmitKeyID);
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
if( !capable( CAP_NET_ADMIN )) {
ret = -EPERM;
DBG_LEAVE( DbgInfo );
return ret;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
if( !wl_has_wep( &( lp->hcfCtx ))) {
ret = -EOPNOTSUPP;
goto out_unlock;
}
index = (erq->flags & IW_ENCODE_INDEX ) - 1;
erq->flags = 0;
if( lp->EnableEncryption == 0 ) {
erq->flags |= IW_ENCODE_DISABLED;
}
if(( index < 0 ) || ( index >= MAX_KEYS )) {
index = lp->TransmitKeyID - 1;
}
erq->flags |= index + 1;
erq->length = lp->DefaultKeys.key[index].len;
memcpy(key, lp->DefaultKeys.key[index].key, erq->length);
out_unlock:
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_nickname(struct net_device *dev, struct iw_request_info *info, struct iw_point *data, char *nickname)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
DBG_FUNC( "wireless_set_nickname" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
#if 0
if( !capable(CAP_NET_ADMIN )) {
ret = -EPERM;
DBG_LEAVE( DbgInfo );
return ret;
}
#endif
if(data->length > HCF_MAX_NAME_LEN) {
ret = -EINVAL;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
memset( lp->StationName, 0, sizeof( lp->StationName ));
memcpy( lp->StationName, nickname, data->length );
wl_apply( lp );
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_nickname(struct net_device *dev, struct iw_request_info *info, struct iw_point *data, char *nickname)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
int status = -1;
wvName_t *pName;
DBG_FUNC( "wireless_get_nickname" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
lp->ltvRecord.len = 1 + ( sizeof( *pName ) / sizeof( hcf_16 ));
lp->ltvRecord.typ = CFG_CNF_OWN_NAME;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
pName = (wvName_t *)&( lp->ltvRecord.u.u32 );
pName->length = CNV_LITTLE_TO_INT( pName->length );
if ( pName->length > IW_ESSID_MAX_SIZE ) {
ret = -EFAULT;
} else {
data->length = pName->length;
memcpy(nickname, pName->name, pName->length);
}
} else {
ret = -EFAULT;
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE(DbgInfo);
return ret;
}
static int wireless_set_porttype(struct net_device *dev, struct iw_request_info *info, __u32 *mode, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
hcf_16 portType;
hcf_16 createIBSS;
DBG_FUNC( "wireless_set_porttype" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
switch( *mode ) {
case IW_MODE_ADHOC:
portType = 1;
createIBSS = 1;
lp->DownloadFirmware = WVLAN_DRV_MODE_STA;
break;
case IW_MODE_AUTO:
case IW_MODE_INFRA:
portType = 1;
createIBSS = 0;
lp->DownloadFirmware = WVLAN_DRV_MODE_STA;
break;
#if 0
case IW_MODE_MASTER:
portType = 1;
lp->CreateIBSS = 0;
lp->DownloadFirmware = WVLAN_DRV_MODE_AP;
break;
#endif
default:
portType = 0;
createIBSS = 0;
ret = -EINVAL;
}
if( portType != 0 ) {
if( ( lp->PortType != portType ) || (lp->CreateIBSS != createIBSS)) {
lp->PortType = portType;
lp->CreateIBSS = createIBSS;
wl_go( lp );
wl_wext_event_mode( lp->dev );
}
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_porttype(struct net_device *dev, struct iw_request_info *info, __u32 *mode, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
int status = -1;
hcf_16 *pPortType;
DBG_FUNC( "wireless_get_porttype" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
lp->ltvRecord.len = 1 + ( sizeof( *pPortType ) / sizeof( hcf_16 ));
lp->ltvRecord.typ = CFG_CNF_PORT_TYPE;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
pPortType = (hcf_16 *)&( lp->ltvRecord.u.u32 );
*pPortType = CNV_LITTLE_TO_INT( *pPortType );
switch( *pPortType ) {
case 1:
#if 0
#if (HCF_TYPE) & HCF_TYPE_AP
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ) {
*mode = IW_MODE_MASTER;
} else {
*mode = IW_MODE_INFRA;
}
#else
*mode = IW_MODE_INFRA;
#endif
#endif
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ) {
*mode = IW_MODE_MASTER;
} else {
if( lp->CreateIBSS ) {
*mode = IW_MODE_ADHOC;
} else {
*mode = IW_MODE_INFRA;
}
}
break;
case 3:
*mode = IW_MODE_ADHOC;
break;
default:
ret = -EFAULT;
break;
}
} else {
ret = -EFAULT;
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_power(struct net_device *dev, struct iw_request_info *info, struct iw_param *wrq, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
DBG_FUNC( "wireless_set_power" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
DBG_PRINT( "THIS CORRUPTS PMEnabled ;?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" );
#if 0
if( !capable( CAP_NET_ADMIN )) {
ret = -EPERM;
DBG_LEAVE( DbgInfo );
return ret;
}
#endif
wl_lock( lp, &flags );
wl_act_int_off( lp );
if( wrq->disabled ) {
lp->PMEnabled = 0;
} else {
lp->PMEnabled = 1;
}
wl_apply( lp );
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_power(struct net_device *dev, struct iw_request_info *info, struct iw_param *rrq, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
DBG_FUNC( "wireless_get_power" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
DBG_PRINT( "THIS IS PROBABLY AN OVER-SIMPLIFICATION ;?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n" );
wl_lock( lp, &flags );
wl_act_int_off( lp );
rrq->flags = 0;
rrq->value = 0;
if( lp->PMEnabled ) {
rrq->disabled = 0;
} else {
rrq->disabled = 1;
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_tx_power(struct net_device *dev, struct iw_request_info *info, struct iw_param *rrq, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
DBG_FUNC( "wireless_get_tx_power" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
#ifdef USE_POWER_DBM
rrq->value = RADIO_TX_POWER_DBM;
rrq->flags = IW_TXPOW_DBM;
#else
rrq->value = RADIO_TX_POWER_MWATT;
rrq->flags = IW_TXPOW_MWATT;
#endif
rrq->fixed = 1;
rrq->disabled = 0;
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_rts_threshold (struct net_device *dev, struct iw_request_info *info, struct iw_param *rts, char *extra)
{
int ret = 0;
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int rthr = rts->value;
DBG_FUNC( "wireless_set_rts_threshold" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
if(rts->fixed == 0) {
ret = -EINVAL;
goto out;
}
#if WIRELESS_EXT > 8
if( rts->disabled ) {
rthr = 2347;
}
#endif
if(( rthr < 256 ) || ( rthr > 2347 )) {
ret = -EINVAL;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
lp->RTSThreshold = rthr;
wl_apply( lp );
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_rts_threshold (struct net_device *dev, struct iw_request_info *info, struct iw_param *rts, char *extra)
{
int ret = 0;
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
DBG_FUNC( "wireless_get_rts_threshold" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
rts->value = lp->RTSThreshold;
#if WIRELESS_EXT > 8
rts->disabled = ( rts->value == 2347 );
#endif
rts->fixed = 1;
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_rate(struct net_device *dev, struct iw_request_info *info, struct iw_param *rrq, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
#ifdef WARP
int status = -1;
int index = 0;
#endif
DBG_FUNC( "wireless_set_rate" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
#ifdef WARP
lp->ltvRecord.len = 2;
lp->ltvRecord.typ = CFG_CUR_CHANNEL;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
index = ( CNV_LITTLE_TO_INT( lp->ltvRecord.u.u16[0] ) & 0x100 ) ? 1 : 0;
DBG_PRINT( "Index: %d\n", index );
} else {
DBG_ERROR( DbgInfo, "Could not determine radio frequency\n" );
DBG_LEAVE( DbgInfo );
ret = -EINVAL;
goto out_unlock;
}
if( rrq->value > 0 &&
rrq->value <= 1 * MEGABIT ) {
lp->TxRateControl[index] = 0x0001;
}
else if( rrq->value > 1 * MEGABIT &&
rrq->value <= 2 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0002;
} else {
lp->TxRateControl[index] = 0x0003;
}
}
else if( rrq->value > 2 * MEGABIT &&
rrq->value <= 5 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0004;
} else {
lp->TxRateControl[index] = 0x0007;
}
}
else if( rrq->value > 5 * MEGABIT &&
rrq->value <= 6 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0010;
} else {
lp->TxRateControl[index] = 0x0017;
}
}
else if( rrq->value > 6 * MEGABIT &&
rrq->value <= 9 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0020;
} else {
lp->TxRateControl[index] = 0x0037;
}
}
else if( rrq->value > 9 * MEGABIT &&
rrq->value <= 11 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0008;
} else {
lp->TxRateControl[index] = 0x003F;
}
}
else if( rrq->value > 11 * MEGABIT &&
rrq->value <= 12 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0040;
} else {
lp->TxRateControl[index] = 0x007F;
}
}
else if( rrq->value > 12 * MEGABIT &&
rrq->value <= 18 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0080;
} else {
lp->TxRateControl[index] = 0x00FF;
}
}
else if( rrq->value > 18 * MEGABIT &&
rrq->value <= 24 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0100;
} else {
lp->TxRateControl[index] = 0x01FF;
}
}
else if( rrq->value > 24 * MEGABIT &&
rrq->value <= 36 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0200;
} else {
lp->TxRateControl[index] = 0x03FF;
}
}
else if( rrq->value > 36 * MEGABIT &&
rrq->value <= 48 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0400;
} else {
lp->TxRateControl[index] = 0x07FF;
}
}
else if( rrq->value > 48 * MEGABIT &&
rrq->value <= 54 * MEGABIT ) {
if( rrq->fixed == 1 ) {
lp->TxRateControl[index] = 0x0800;
} else {
lp->TxRateControl[index] = 0x0FFF;
}
}
else if( rrq->fixed == 0 ) {
lp->TxRateControl[index] = PARM_MAX_TX_RATE;
} else {
rrq->value = 0;
ret = -EINVAL;
goto out_unlock;
}
#else
if( rrq->value > 0 &&
rrq->value <= 1 * MEGABIT ) {
lp->TxRateControl[0] = 1;
}
else if( rrq->value > 1 * MEGABIT &&
rrq->value <= 2 * MEGABIT ) {
if( rrq->fixed ) {
lp->TxRateControl[0] = 2;
} else {
lp->TxRateControl[0] = 6;
}
}
else if( rrq->value > 2 * MEGABIT &&
rrq->value <= 5 * MEGABIT ) {
if( rrq->fixed ) {
lp->TxRateControl[0] = 4;
} else {
lp->TxRateControl[0] = 7;
}
}
else if( rrq->value > 5 * MEGABIT &&
rrq->value <= 11 * MEGABIT ) {
if( rrq->fixed) {
lp->TxRateControl[0] = 5;
} else {
lp->TxRateControl[0] = 3;
}
}
else if( rrq->fixed == 0 ) {
lp->TxRateControl[0] = 3;
} else {
rrq->value = 0;
ret = -EINVAL;
goto out_unlock;
}
#endif
wl_apply( lp );
out_unlock:
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_rate(struct net_device *dev, struct iw_request_info *info, struct iw_param *rrq, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
int status = -1;
hcf_16 txRate;
DBG_FUNC( "wireless_get_rate" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
lp->ltvRecord.len = 1 + ( sizeof(txRate)/sizeof(hcf_16));
lp->ltvRecord.typ = CFG_CUR_TX_RATE;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
#ifdef WARP
txRate = CNV_LITTLE_TO_INT( lp->ltvRecord.u.u16[0] );
if( txRate & 0x0001 ) {
txRate = 1;
}
else if( txRate & 0x0002 ) {
txRate = 2;
}
else if( txRate & 0x0004 ) {
txRate = 5;
}
else if( txRate & 0x0008 ) {
txRate = 11;
}
else if( txRate & 0x00010 ) {
txRate = 6;
}
else if( txRate & 0x00020 ) {
txRate = 9;
}
else if( txRate & 0x00040 ) {
txRate = 12;
}
else if( txRate & 0x00080 ) {
txRate = 18;
}
else if( txRate & 0x00100 ) {
txRate = 24;
}
else if( txRate & 0x00200 ) {
txRate = 36;
}
else if( txRate & 0x00400 ) {
txRate = 48;
}
else if( txRate & 0x00800 ) {
txRate = 54;
}
#else
txRate = (hcf_16)CNV_LITTLE_TO_LONG( lp->ltvRecord.u.u32[0] );
#endif
rrq->value = txRate * MEGABIT;
} else {
rrq->value = 0;
ret = -EFAULT;
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_scan(struct net_device *dev, struct iw_request_info *info, struct iw_point *data, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
int status = -1;
int retries = 0;
DBG_FUNC( "wireless_set_scan" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
if((lp->hcfCtx.IFB_CardStat & CARD_STAT_DEFUNCT) != 0)
{
DBG_TRACE( DbgInfo, "CARD is in DEFUNCT mode, reset it to bring it back to life\n" );
wl_reset( dev );
}
retry:
lp->probe_results.scan_complete = FALSE;
#ifdef WARP
lp->ltvRecord.len = 5;
lp->ltvRecord.typ = CFG_SCAN_CHANNEL;
lp->ltvRecord.u.u16[0] = CNV_INT_TO_LITTLE( 0x3FFF );
lp->ltvRecord.u.u16[1] = CNV_INT_TO_LITTLE( 0xFFFF );
lp->ltvRecord.u.u16[2] = CNV_INT_TO_LITTLE( 0xFFFF );
lp->ltvRecord.u.u16[3] = CNV_INT_TO_LITTLE( 0x0007 );
#else
lp->ltvRecord.len = 2;
lp->ltvRecord.typ = CFG_SCAN_CHANNEL;
lp->ltvRecord.u.u16[0] = CNV_INT_TO_LITTLE( 0x7FFF );
#endif
status = hcf_put_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
DBG_TRACE( DbgInfo, "CFG_SCAN_CHANNEL result : 0x%x\n", status );
wl_unlock(lp, &flags);
wl_lock( lp, &flags );
if( status != HCF_SUCCESS ) {
retries++;
if(retries <= 10) {
DBG_TRACE( DbgInfo, "Reset card to recover, attempt: %d\n", retries );
wl_reset( dev );
wl_unlock(lp, &flags);
wl_lock( lp, &flags );
goto retry;
}
}
lp->ltvRecord.len = 18;
lp->ltvRecord.typ = CFG_SCAN_SSID;
lp->ltvRecord.u.u16[0] = CNV_INT_TO_LITTLE( 0 );
lp->ltvRecord.u.u16[1] = CNV_INT_TO_LITTLE( 0 );
status = hcf_put_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
wl_unlock(lp, &flags);
wl_lock( lp, &flags );
DBG_TRACE( DbgInfo, "CFG_SCAN_SSID to 'any' status: 0x%x\n", status );
status = hcf_action( &( lp->hcfCtx ), HCF_ACT_ACS_SCAN );
if( status == HCF_SUCCESS ) {
DBG_TRACE( DbgInfo, "SUCCESSFULLY INITIATED SCAN...\n" );
} else {
DBG_TRACE( DbgInfo, "INITIATE SCAN FAILED...\n" );
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE(DbgInfo);
return ret;
}
static int wireless_get_scan(struct net_device *dev, struct iw_request_info *info, struct iw_point *data, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
int count;
char *buf;
char *buf_end;
struct iw_event iwe;
PROBE_RESP *probe_resp;
hcf_8 msg[512];
hcf_8 *wpa_ie;
hcf_16 wpa_ie_len;
DBG_FUNC( "wireless_get_scan" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
if( !lp->probe_results.scan_complete ) {
ret = -EAGAIN;
goto out_unlock;
}
DBG_TRACE( DbgInfo, "SCAN COMPLETE, Num of APs: %d\n",
lp->probe_results.num_aps );
buf = extra;
buf_end = extra + IW_SCAN_MAX_DATA;
for( count = 0; count < lp->probe_results.num_aps; count++ ) {
probe_resp = (PROBE_RESP *)&lp->probe_results.ProbeTable[count];
memset( &iwe, 0, sizeof( iwe ));
iwe.cmd = SIOCGIWAP;
iwe.u.ap_addr.sa_family = ARPHRD_ETHER;
memcpy( iwe.u.ap_addr.sa_data, probe_resp->BSSID, ETH_ALEN);
iwe.len = IW_EV_ADDR_LEN;
buf = IWE_STREAM_ADD_EVENT(info, buf, buf_end, &iwe, IW_EV_ADDR_LEN);
memset( &iwe, 0, sizeof( iwe ));
iwe.cmd = SIOCGIWMODE;
if( probe_resp->capability & CAPABILITY_IBSS ) {
iwe.u.mode = IW_MODE_INFRA;
} else {
iwe.u.mode = IW_MODE_MASTER;
}
iwe.len = IW_EV_UINT_LEN;
buf = IWE_STREAM_ADD_EVENT(info, buf, buf_end, &iwe, IW_EV_UINT_LEN);
memset(&iwe, 0, sizeof(iwe));
iwe.cmd = IWEVQUAL;
iwe.u.qual.level = dbm(probe_resp->signal);
iwe.u.qual.noise = dbm(probe_resp->silence);
iwe.u.qual.qual = iwe.u.qual.level - iwe.u.qual.noise;
iwe.u.qual.updated = lp->probe_results.scan_complete | IW_QUAL_DBM;
iwe.len = IW_EV_QUAL_LEN;
buf = IWE_STREAM_ADD_EVENT(info, buf, buf_end, &iwe, IW_EV_QUAL_LEN);
if( probe_resp->rawData[1] > 0 ) {
memset( &iwe, 0, sizeof( iwe ));
iwe.cmd = SIOCGIWESSID;
iwe.u.data.length = probe_resp->rawData[1];
iwe.u.data.flags = 1;
buf = IWE_STREAM_ADD_POINT(info, buf, buf_end, &iwe, &probe_resp->rawData[2]);
}
memset( &iwe, 0, sizeof( iwe ));
iwe.cmd = SIOCGIWENCODE;
iwe.u.data.length = 0;
if( probe_resp->capability & CAPABILITY_PRIVACY ) {
iwe.u.data.flags |= IW_ENCODE_ENABLED;
} else {
iwe.u.data.flags |= IW_ENCODE_DISABLED;
}
buf = IWE_STREAM_ADD_POINT(info, buf, buf_end, &iwe, NULL);
memset( &iwe, 0, sizeof( iwe ));
iwe.cmd = SIOCGIWFREQ;
iwe.len = IW_EV_FREQ_LEN;
iwe.u.freq.m = wl_parse_ds_ie( probe_resp );
iwe.u.freq.e = 0;
buf = IWE_STREAM_ADD_EVENT(info, buf, buf_end, &iwe, IW_EV_FREQ_LEN);
#if WIRELESS_EXT > 14
memset( &iwe, 0, sizeof( iwe ));
memset( msg, 0, sizeof( msg ));
iwe.cmd = IWEVCUSTOM;
sprintf( msg, "beacon_interval=%d", probe_resp->beaconInterval );
iwe.u.data.length = strlen( msg );
buf = IWE_STREAM_ADD_POINT(info, buf, buf_end, &iwe, msg);
wpa_ie = NULL;
wpa_ie_len = 0;
wpa_ie = wl_parse_wpa_ie( probe_resp, &wpa_ie_len );
if( wpa_ie != NULL ) {
memset( &iwe, 0, sizeof( iwe ));
memset( msg, 0, sizeof( msg ));
iwe.cmd = IWEVCUSTOM;
sprintf( msg, "wpa_ie=%s", wl_print_wpa_ie( wpa_ie, wpa_ie_len ));
iwe.u.data.length = strlen( msg );
buf = IWE_STREAM_ADD_POINT(info, buf, buf_end, &iwe, msg);
}
#endif
}
data->length = buf - extra;
out_unlock:
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_auth(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *data, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret;
int iwa_idx = data->flags & IW_AUTH_INDEX;
int iwa_val = data->value;
DBG_FUNC( "wireless_set_auth" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
switch (iwa_idx) {
case IW_AUTH_WPA_VERSION:
DBG_TRACE( DbgInfo, "IW_AUTH_WPA_VERSION\n");
if (iwa_val == IW_AUTH_WPA_VERSION_WPA)
ret = 0;
else
ret = -EINVAL;
break;
case IW_AUTH_WPA_ENABLED:
DBG_TRACE( DbgInfo, "IW_AUTH_WPA_ENABLED: val = %d\n", iwa_val);
if (iwa_val)
lp->EnableEncryption = 2;
else
lp->EnableEncryption = 0;
ret = 0;
break;
case IW_AUTH_TKIP_COUNTERMEASURES:
DBG_TRACE( DbgInfo, "IW_AUTH_TKIP_COUNTERMEASURES\n");
lp->driverEnable = !iwa_val;
if(lp->driverEnable)
hcf_cntl(&(lp->hcfCtx), HCF_CNTL_ENABLE | HCF_PORT_0);
else
hcf_cntl(&(lp->hcfCtx), HCF_CNTL_DISABLE | HCF_PORT_0);
ret = 0;
break;
case IW_AUTH_DROP_UNENCRYPTED:
DBG_TRACE( DbgInfo, "IW_AUTH_DROP_UNENCRYPTED\n");
ret = 0;
break;
case IW_AUTH_CIPHER_PAIRWISE:
DBG_TRACE( DbgInfo, "IW_AUTH_CIPHER_PAIRWISE\n");
ret = -EINVAL;
break;
case IW_AUTH_CIPHER_GROUP:
DBG_TRACE( DbgInfo, "IW_AUTH_CIPHER_GROUP\n");
ret = -EINVAL;
break;
case IW_AUTH_KEY_MGMT:
DBG_TRACE( DbgInfo, "IW_AUTH_KEY_MGMT\n");
ret = -EINVAL;
break;
case IW_AUTH_80211_AUTH_ALG:
DBG_TRACE( DbgInfo, "IW_AUTH_80211_AUTH_ALG\n");
ret = -EINVAL;
break;
case IW_AUTH_RX_UNENCRYPTED_EAPOL:
DBG_TRACE( DbgInfo, "IW_AUTH_RX_UNENCRYPTED_EAPOL\n");
ret = -EINVAL;
break;
case IW_AUTH_ROAMING_CONTROL:
DBG_TRACE( DbgInfo, "IW_AUTH_ROAMING_CONTROL\n");
ret = -EINVAL;
break;
case IW_AUTH_PRIVACY_INVOKED:
DBG_TRACE( DbgInfo, "IW_AUTH_PRIVACY_INVOKED\n");
ret = -EINVAL;
break;
default:
DBG_TRACE( DbgInfo, "IW_AUTH_?? (%d) unknown\n", iwa_idx);
ret = -EINVAL;
break;
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int hermes_set_key(ltv_t *ltv, int alg, int key_idx, u8 *addr,
int set_tx, u8 *seq, u8 *key, size_t key_len)
{
int ret = -EINVAL;
int buf_idx = 0;
hcf_8 tsc[IW_ENCODE_SEQ_MAX_SIZE] =
{ 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00 };
DBG_FUNC( "hermes_set_key" );
DBG_ENTER( DbgInfo );
switch (alg)
{
case IW_ENCODE_ALG_TKIP:
DBG_TRACE( DbgInfo, "IW_ENCODE_ALG_TKIP: key(%d)\n", key_idx);
#if 0
for( count = 0; count < 100; count++ )
{
usleep( 1000 );
ltv.len = 2;
ltv.typ = 0xFD91;
ltv.u.u16[0] = 0;
wl_get_info( sock, &ltv, ifname );
if( ltv.u.u16[0] == 0 )
{
break;
}
}
if( count == 100 )
{
wpa_printf( MSG_DEBUG, "Timed out waiting for TxQ!" );
}
#endif
switch (key_idx) {
case 0:
ltv->len = 28;
ltv->typ = CFG_ADD_TKIP_MAPPED_KEY;
memcpy(&ltv->u.u8[buf_idx], addr, ETH_ALEN);
buf_idx += ETH_ALEN;
memcpy(&ltv->u.u8[buf_idx], &key[0], 16);
buf_idx += 16;
memcpy(&ltv->u.u8[buf_idx], tsc, IW_ENCODE_SEQ_MAX_SIZE);
buf_idx += IW_ENCODE_SEQ_MAX_SIZE;
memcpy(&ltv->u.u8[buf_idx], seq, IW_ENCODE_SEQ_MAX_SIZE);
buf_idx += IW_ENCODE_SEQ_MAX_SIZE;
memcpy(&ltv->u.u8[buf_idx], &key[16], 8);
buf_idx += 8;
memcpy(&ltv->u.u8[buf_idx], &key[24], 8);
ret = 0;
break;
case 1:
case 2:
case 3:
ltv->len = 26;
ltv->typ = CFG_ADD_TKIP_DEFAULT_KEY;
ltv->u.u16[buf_idx] = key_idx;
if(set_tx)
ltv->u.u16[buf_idx] |= 0x8000;
buf_idx += 2;
memcpy(&ltv->u.u8[buf_idx], seq, IW_ENCODE_SEQ_MAX_SIZE);
buf_idx += IW_ENCODE_SEQ_MAX_SIZE;
memcpy(&ltv->u.u8[buf_idx], key, key_len);
buf_idx += key_len;
memcpy(&ltv->u.u8[buf_idx], tsc, IW_ENCODE_SEQ_MAX_SIZE);
ltv->u.u16[0] = CNV_INT_TO_LITTLE(ltv->u.u16[0]);
ret = 0;
break;
default:
break;
}
break;
case IW_ENCODE_ALG_WEP:
DBG_TRACE( DbgInfo, "IW_ENCODE_ALG_WEP: key(%d)\n", key_idx);
break;
case IW_ENCODE_ALG_CCMP:
DBG_TRACE( DbgInfo, "IW_ENCODE_ALG_CCMP: key(%d)\n", key_idx);
break;
case IW_ENCODE_ALG_NONE:
DBG_TRACE( DbgInfo, "IW_ENCODE_ALG_NONE: key(%d)\n", key_idx);
switch (key_idx) {
case 0:
if (memcmp(addr, "\xff\xff\xff\xff\xff\xff", ETH_ALEN) != 0) {
ltv->len = 7;
ltv->typ = CFG_REMOVE_TKIP_MAPPED_KEY;
memcpy(&ltv->u.u8[0], addr, ETH_ALEN);
ret = 0;
}
break;
case 1:
case 2:
case 3:
ltv->len = 2;
ltv->typ = CFG_REMOVE_TKIP_DEFAULT_KEY;
ltv->u.u16[0] = key_idx;
ret = 0;
break;
default:
break;
}
break;
default:
DBG_TRACE( DbgInfo, "IW_ENCODE_??: key(%d)\n", key_idx);
break;
}
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_set_encodeext (struct net_device *dev,
struct iw_request_info *info,
struct iw_point *erq, char *keybuf)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret;
int key_idx = (erq->flags&IW_ENCODE_INDEX) - 1;
ltv_t ltv;
struct iw_encode_ext *ext = (struct iw_encode_ext *)keybuf;
DBG_FUNC( "wireless_set_encodeext" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
if (sizeof(ext->rx_seq) != 8) {
DBG_TRACE(DbgInfo, "rz_seq size mismatch\n");
DBG_LEAVE(DbgInfo);
return -EINVAL;
}
if(ext->alg == IW_ENCODE_ALG_WEP) {
struct iw_point wep_erq;
char *wep_keybuf;
wep_erq.flags = erq->flags;
wep_erq.length = ext->key_len;
wep_keybuf = ext->key;
ret = wireless_set_encode(dev, info, &wep_erq, wep_keybuf);
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
memset(&ltv, 0, sizeof(ltv));
ret = hermes_set_key(&ltv, ext->alg, key_idx, ext->addr.sa_data,
ext->ext_flags & IW_ENCODE_EXT_SET_TX_KEY,
ext->rx_seq, ext->key, ext->key_len);
if (ret != 0) {
DBG_TRACE( DbgInfo, "hermes_set_key returned != 0, key not set\n");
goto out_unlock;
}
ret = hcf_put_info(&(lp->hcfCtx), (LTVP)&ltv);
out_unlock:
if(ret == HCF_SUCCESS) {
DBG_TRACE( DbgInfo, "Put key info succes\n");
} else {
DBG_TRACE( DbgInfo, "Put key info failed, key not set\n");
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
static int wireless_get_genie(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *data, char *extra)
{
struct wl_private *lp = wl_priv(dev);
unsigned long flags;
int ret = 0;
ltv_t ltv;
DBG_FUNC( "wireless_get_genie" );
DBG_ENTER( DbgInfo );
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
ret = -EBUSY;
goto out;
}
wl_lock( lp, &flags );
wl_act_int_off( lp );
memset(&ltv, 0, sizeof(ltv));
ltv.len = 2;
ltv.typ = CFG_SET_WPA_AUTH_KEY_MGMT_SUITE;
lp->AuthKeyMgmtSuite = ltv.u.u16[0] = 4;
ltv.u.u16[0] = CNV_INT_TO_LITTLE(ltv.u.u16[0]);
ret = hcf_put_info(&(lp->hcfCtx), (LTVP)&ltv);
wl_act_int_on( lp );
wl_unlock(lp, &flags);
out:
DBG_LEAVE( DbgInfo );
return ret;
}
struct iw_statistics * wl_wireless_stats( struct net_device *dev )
{
struct iw_statistics *pStats;
struct wl_private *lp = wl_priv(dev);
DBG_FUNC( "wl_wireless_stats" );
DBG_ENTER(DbgInfo);
DBG_PARAM(DbgInfo, "dev", "%s (0x%p)", dev->name, dev);
pStats = NULL;
pStats = &( lp->wstats );
pStats->qual.updated = 0x00;
if( !( lp->flags & WVLAN2_UIL_BUSY ))
{
CFG_COMMS_QUALITY_STRCT *pQual;
CFG_HERMES_TALLIES_STRCT tallies;
int status;
pStats->status = 0;
lp->ltvRecord.len = 1 + ( sizeof( *pQual ) / sizeof( hcf_16 ));
lp->ltvRecord.typ = CFG_COMMS_QUALITY;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
pQual = (CFG_COMMS_QUALITY_STRCT *)&( lp->ltvRecord );
#ifdef USE_DBM
pStats->qual.qual = (u_char) CNV_LITTLE_TO_INT( pQual->coms_qual );
pStats->qual.level = (u_char) dbm( CNV_LITTLE_TO_INT( pQual->signal_lvl ));
pStats->qual.noise = (u_char) dbm( CNV_LITTLE_TO_INT( pQual->noise_lvl ));
pStats->qual.updated |= (IW_QUAL_QUAL_UPDATED |
IW_QUAL_LEVEL_UPDATED |
IW_QUAL_NOISE_UPDATED |
IW_QUAL_DBM);
#else
pStats->qual.qual = percent( CNV_LITTLE_TO_INT( pQual->coms_qual ),
HCF_MIN_COMM_QUALITY,
HCF_MAX_COMM_QUALITY );
pStats->qual.level = percent( CNV_LITTLE_TO_INT( pQual->signal_lvl ),
HCF_MIN_SIGNAL_LEVEL,
HCF_MAX_SIGNAL_LEVEL );
pStats->qual.noise = percent( CNV_LITTLE_TO_INT( pQual->noise_lvl ),
HCF_MIN_NOISE_LEVEL,
HCF_MAX_NOISE_LEVEL );
pStats->qual.updated |= (IW_QUAL_QUAL_UPDATED |
IW_QUAL_LEVEL_UPDATED |
IW_QUAL_NOISE_UPDATED);
#endif
} else {
memset( &( pStats->qual ), 0, sizeof( pStats->qual ));
}
if(lp->portState == WVLAN_PORT_STATE_DISABLED) {
if( wl_get_tallies( lp, &tallies ) == 0 ) {
pStats->discard.nwid = 0L;
pStats->discard.code = tallies.RxWEPUndecryptable;
pStats->discard.misc = tallies.TxDiscards +
tallies.RxFCSErrors +
tallies.TxDiscardsWrongSA;
pStats->discard.retries = tallies.TxRetryLimitExceeded;
pStats->discard.fragment = tallies.RxMsgInBadMsgFragments;
} else {
memset( &( pStats->discard ), 0, sizeof( pStats->discard ));
}
} else {
memset( &( pStats->discard ), 0, sizeof( pStats->discard ));
}
}
DBG_LEAVE( DbgInfo );
return pStats;
}
struct iw_statistics * wl_get_wireless_stats( struct net_device *dev )
{
unsigned long flags;
struct wl_private *lp = wl_priv(dev);
struct iw_statistics *pStats = NULL;
DBG_FUNC( "wl_get_wireless_stats" );
DBG_ENTER(DbgInfo);
wl_lock( lp, &flags );
wl_act_int_off( lp );
#ifdef USE_RTS
if( lp->useRTS == 1 ) {
DBG_TRACE( DbgInfo, "Skipping wireless stats, in RTS mode\n" );
} else
#endif
{
pStats = wl_wireless_stats( dev );
}
wl_act_int_on( lp );
wl_unlock(lp, &flags);
DBG_LEAVE( DbgInfo );
return pStats;
}
inline void wl_spy_gather( struct net_device *dev, u_char *mac )
{
struct iw_quality wstats;
int status;
u_char stats[2];
DESC_STRCT desc[1];
struct wl_private *lp = wl_priv(dev);
if (!lp->spy_data.spy_number) {
return;
}
memset( stats, 0, sizeof(stats));
memset( desc, 0, sizeof(DESC_STRCT));
desc[0].buf_addr = stats;
desc[0].BUF_SIZE = sizeof(stats);
desc[0].next_desc_addr = 0;
status = hcf_rcv_msg( &( lp->hcfCtx ), &desc[0], 0 );
if( status == HCF_SUCCESS ) {
wstats.level = (u_char) dbm(stats[1]);
wstats.noise = (u_char) dbm(stats[0]);
wstats.qual = wstats.level > wstats.noise ? wstats.level - wstats.noise : 0;
wstats.updated = (IW_QUAL_QUAL_UPDATED |
IW_QUAL_LEVEL_UPDATED |
IW_QUAL_NOISE_UPDATED |
IW_QUAL_DBM);
wireless_spy_update( dev, mac, &wstats );
}
}
void wl_wext_event_freq( struct net_device *dev )
{
#if WIRELESS_EXT > 13
union iwreq_data wrqu;
struct wl_private *lp = wl_priv(dev);
memset( &wrqu, 0, sizeof( wrqu ));
wrqu.freq.m = lp->Channel;
wrqu.freq.e = 0;
wireless_send_event( dev, SIOCSIWFREQ, &wrqu, NULL );
#endif
return;
}
void wl_wext_event_mode( struct net_device *dev )
{
#if WIRELESS_EXT > 13
union iwreq_data wrqu;
struct wl_private *lp = wl_priv(dev);
memset( &wrqu, 0, sizeof( wrqu ));
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_STA ) {
wrqu.mode = IW_MODE_INFRA;
} else {
wrqu.mode = IW_MODE_MASTER;
}
wireless_send_event( dev, SIOCSIWMODE, &wrqu, NULL );
#endif
return;
}
void wl_wext_event_essid( struct net_device *dev )
{
#if WIRELESS_EXT > 13
union iwreq_data wrqu;
struct wl_private *lp = wl_priv(dev);
memset( &wrqu, 0, sizeof( wrqu ));
wrqu.essid.length = strlen( lp->NetworkName );
wrqu.essid.pointer = (caddr_t)lp->NetworkName;
wrqu.essid.flags = 1;
wireless_send_event( dev, SIOCSIWESSID, &wrqu, lp->NetworkName );
#endif
return;
}
void wl_wext_event_encode( struct net_device *dev )
{
#if WIRELESS_EXT > 13
union iwreq_data wrqu;
struct wl_private *lp = wl_priv(dev);
int index = 0;
memset( &wrqu, 0, sizeof( wrqu ));
if( lp->EnableEncryption == 0 ) {
wrqu.encoding.flags = IW_ENCODE_DISABLED;
} else {
wrqu.encoding.flags |= lp->TransmitKeyID;
index = lp->TransmitKeyID - 1;
#if 1
if ( CNV_INT_TO_LITTLE( lp->hcfCtx.IFB_FWIdentity.comp_id ) == COMP_ID_FW_AP ) {
if( lp->ExcludeUnencrypted ) {
wrqu.encoding.flags |= IW_ENCODE_RESTRICTED;
} else {
wrqu.encoding.flags |= IW_ENCODE_OPEN;
}
}
#endif
if( capable( CAP_NET_ADMIN )) {
wrqu.encoding.pointer = (caddr_t)lp->DefaultKeys.key[index].key;
wrqu.encoding.length = lp->DefaultKeys.key[index].len;
} else {
wrqu.encoding.flags |= IW_ENCODE_NOKEY;
}
}
wireless_send_event( dev, SIOCSIWENCODE, &wrqu,
lp->DefaultKeys.key[index].key );
#endif
return;
}
void wl_wext_event_ap( struct net_device *dev )
{
#if WIRELESS_EXT > 13
union iwreq_data wrqu;
struct wl_private *lp = wl_priv(dev);
int status;
wl_wext_event_assoc_ie( dev );
lp->ltvRecord.typ = CFG_CUR_BSSID;
lp->ltvRecord.len = 4;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS ) {
memset( &wrqu, 0, sizeof( wrqu ));
memcpy( wrqu.addr.sa_data, lp->ltvRecord.u.u8, ETH_ALEN );
wrqu.addr.sa_family = ARPHRD_ETHER;
wireless_send_event( dev, SIOCGIWAP, &wrqu, NULL );
}
#endif
return;
}
void wl_wext_event_scan_complete( struct net_device *dev )
{
#if WIRELESS_EXT > 13
union iwreq_data wrqu;
memset( &wrqu, 0, sizeof( wrqu ));
wrqu.addr.sa_family = ARPHRD_ETHER;
wireless_send_event( dev, SIOCGIWSCAN, &wrqu, NULL );
#endif
return;
}
void wl_wext_event_new_sta( struct net_device *dev )
{
#if WIRELESS_EXT > 14
union iwreq_data wrqu;
memset( &wrqu, 0, sizeof( wrqu ));
memcpy( wrqu.addr.sa_data, dev->dev_addr, ETH_ALEN );
wrqu.addr.sa_family = ARPHRD_ETHER;
wireless_send_event( dev, IWEVREGISTERED, &wrqu, NULL );
#endif
return;
}
void wl_wext_event_expired_sta( struct net_device *dev )
{
#if WIRELESS_EXT > 14
union iwreq_data wrqu;
memset( &wrqu, 0, sizeof( wrqu ));
memcpy( wrqu.addr.sa_data, dev->dev_addr, ETH_ALEN );
wrqu.addr.sa_family = ARPHRD_ETHER;
wireless_send_event( dev, IWEVEXPIRED, &wrqu, NULL );
#endif
return;
}
void wl_wext_event_mic_failed( struct net_device *dev )
{
#if WIRELESS_EXT > 14
char msg[512];
union iwreq_data wrqu;
struct wl_private *lp = wl_priv(dev);
int key_idx;
char *addr1;
char *addr2;
WVLAN_RX_WMP_HDR *hdr;
key_idx = lp->lookAheadBuf[HFS_STAT+1] >> 3;
key_idx &= 0x03;
hdr = (WVLAN_RX_WMP_HDR *)&lp->lookAheadBuf[HFS_STAT];
addr1 = (char *)hdr->address1;
addr2 = (char *)hdr->address2;
DBG_PRINT( "MIC FAIL - KEY USED : %d, STATUS : 0x%04x\n", key_idx,
hdr->status );
memset( &wrqu, 0, sizeof( wrqu ));
memset( msg, 0, sizeof( msg ));
#if DBG
sprintf(msg, "MLME-MICHAELMICFAILURE.indication(keyid=%d %scast "
"addr=%pM)", key_idx, addr1[0] & 0x01 ? "broad" : "uni",
addr2);
#endif
wrqu.data.length = strlen( msg );
wireless_send_event( dev, IWEVCUSTOM, &wrqu, msg );
#endif
return;
}
void wl_wext_event_assoc_ie( struct net_device *dev )
{
#if WIRELESS_EXT > 14
char msg[512];
union iwreq_data wrqu;
struct wl_private *lp = wl_priv(dev);
int status;
PROBE_RESP data;
hcf_16 length;
hcf_8 *wpa_ie;
memset( &wrqu, 0, sizeof( wrqu ));
memset( msg, 0, sizeof( msg ));
lp->ltvRecord.len = 45;
lp->ltvRecord.typ = CFG_CUR_ASSOC_REQ_INFO;
status = hcf_get_info( &( lp->hcfCtx ), (LTVP)&( lp->ltvRecord ));
if( status == HCF_SUCCESS )
{
length = 0;
memcpy( &data.rawData, &( lp->ltvRecord.u.u8[1] ), 88 );
wpa_ie = wl_parse_wpa_ie( &data, &length );
if( length != 0 )
{
sprintf( msg, "ASSOCINFO(ReqIEs=%s)", wl_print_wpa_ie( wpa_ie, length ));
wrqu.data.length = strlen( msg );
wireless_send_event( dev, IWEVCUSTOM, &wrqu, msg );
}
}
#endif
return;
}
