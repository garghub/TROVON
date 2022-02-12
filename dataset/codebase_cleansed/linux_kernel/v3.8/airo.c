static inline int bap_read(struct airo_info *ai, __le16 *pu16Dst, int bytelen,
int whichbap)
{
return ai->bap_read(ai, pu16Dst, bytelen, whichbap);
}
static void age_mic_context(miccntx *cur, miccntx *old, u8 *key, int key_len,
struct crypto_cipher *tfm)
{
if (cur->valid && (memcmp(cur->key, key, key_len) == 0))
return;
memcpy(old, cur, sizeof(*cur));
memcpy(cur->key, key, key_len);
cur->window = 33;
cur->rx = 0;
cur->tx = 0;
cur->valid = 1;
emmh32_setseed(&cur->seed, key, key_len, tfm);
}
static void micinit(struct airo_info *ai)
{
MICRid mic_rid;
clear_bit(JOB_MIC, &ai->jobs);
PC4500_readrid(ai, RID_MIC, &mic_rid, sizeof(mic_rid), 0);
up(&ai->sem);
ai->micstats.enabled = (le16_to_cpu(mic_rid.state) & 0x00FF) ? 1 : 0;
if (!ai->micstats.enabled) {
ai->mod[0].uCtx.valid = 0;
ai->mod[0].mCtx.valid = 0;
return;
}
if (mic_rid.multicastValid) {
age_mic_context(&ai->mod[0].mCtx, &ai->mod[1].mCtx,
mic_rid.multicast, sizeof(mic_rid.multicast),
ai->tfm);
}
if (mic_rid.unicastValid) {
age_mic_context(&ai->mod[0].uCtx, &ai->mod[1].uCtx,
mic_rid.unicast, sizeof(mic_rid.unicast),
ai->tfm);
}
}
static int micsetup(struct airo_info *ai) {
int i;
if (ai->tfm == NULL)
ai->tfm = crypto_alloc_cipher("aes", 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(ai->tfm)) {
airo_print_err(ai->dev->name, "failed to load transform for AES");
ai->tfm = NULL;
return ERROR;
}
for (i=0; i < NUM_MODULES; i++) {
memset(&ai->mod[i].mCtx,0,sizeof(miccntx));
memset(&ai->mod[i].uCtx,0,sizeof(miccntx));
}
return SUCCESS;
}
static int encapsulate(struct airo_info *ai ,etherHead *frame, MICBuffer *mic, int payLen)
{
miccntx *context;
if (test_bit(FLAG_ADHOC, &ai->flags) && (frame->da[0] & 0x1))
context = &ai->mod[0].mCtx;
else
context = &ai->mod[0].uCtx;
if (!context->valid)
return ERROR;
mic->typelen = htons(payLen + 16);
memcpy(&mic->u.snap, micsnap, sizeof(micsnap));
mic->seq = htonl(context->tx);
context->tx += 2;
emmh32_init(&context->seed);
emmh32_update(&context->seed,frame->da,ETH_ALEN * 2);
emmh32_update(&context->seed,(u8*)&mic->typelen,10);
emmh32_update(&context->seed,(u8*)&mic->seq,sizeof(mic->seq));
emmh32_update(&context->seed,(u8*)(frame + 1),payLen);
emmh32_final(&context->seed, (u8*)&mic->mic);
mic->typelen = 0;
return SUCCESS;
}
static int decapsulate(struct airo_info *ai, MICBuffer *mic, etherHead *eth, u16 payLen)
{
int i;
u32 micSEQ;
miccntx *context;
u8 digest[4];
mic_error micError = NONE;
if (!ai->micstats.enabled) {
if (memcmp ((u8*)eth + 14, micsnap, sizeof(micsnap)) == 0) {
ai->micstats.rxMICPlummed++;
return ERROR;
}
return SUCCESS;
}
if (ntohs(mic->typelen) == 0x888E)
return SUCCESS;
if (memcmp (mic->u.snap, micsnap, sizeof(micsnap)) != 0) {
ai->micstats.rxMICPlummed++;
return ERROR;
}
micSEQ = ntohl(mic->seq);
if ( (micSEQ & 1) == 0 ) {
ai->micstats.rxWrongSequence++;
return ERROR;
}
for (i = 0; i < NUM_MODULES; i++) {
int mcast = eth->da[0] & 1;
context = mcast ? &ai->mod[i].mCtx : &ai->mod[i].uCtx;
if (!context->valid) {
if (i == 0)
micError = NOMICPLUMMED;
continue;
}
if (!mic->typelen)
mic->typelen = htons(payLen + sizeof(MICBuffer) - 2);
emmh32_init(&context->seed);
emmh32_update(&context->seed, eth->da, ETH_ALEN*2);
emmh32_update(&context->seed, (u8 *)&mic->typelen, sizeof(mic->typelen)+sizeof(mic->u.snap));
emmh32_update(&context->seed, (u8 *)&mic->seq,sizeof(mic->seq));
emmh32_update(&context->seed, (u8 *)(eth + 1),payLen);
emmh32_final(&context->seed, digest);
if (memcmp(digest, &mic->mic, 4)) {
if (i == 0)
micError = INCORRECTMIC;
continue;
}
if (RxSeqValid(ai, context, mcast, micSEQ) == SUCCESS) {
ai->micstats.rxSuccess++;
return SUCCESS;
}
if (i == 0)
micError = SEQUENCE;
}
switch (micError) {
case NOMICPLUMMED: ai->micstats.rxMICPlummed++; break;
case SEQUENCE: ai->micstats.rxWrongSequence++; break;
case INCORRECTMIC: ai->micstats.rxIncorrectMIC++; break;
case NONE: break;
case NOMIC: break;
}
return ERROR;
}
static int RxSeqValid (struct airo_info *ai,miccntx *context,int mcast,u32 micSeq)
{
u32 seq,index;
if (mcast) {
if (test_bit(FLAG_UPDATE_MULTI, &ai->flags)) {
clear_bit (FLAG_UPDATE_MULTI, &ai->flags);
context->window = (micSeq > 33) ? micSeq : 33;
context->rx = 0;
}
} else if (test_bit(FLAG_UPDATE_UNI, &ai->flags)) {
clear_bit (FLAG_UPDATE_UNI, &ai->flags);
context->window = (micSeq > 33) ? micSeq : 33;
context->rx = 0;
}
seq = micSeq - (context->window - 33);
if ((s32)seq < 0)
return ERROR;
if ( seq > 64 ) {
MoveWindow(context,micSeq);
return SUCCESS;
}
seq >>= 1;
index = 1 << seq;
if (!(context->rx & index)) {
context->rx |= index;
MoveWindow(context,micSeq);
return SUCCESS;
}
return ERROR;
}
static void MoveWindow(miccntx *context, u32 micSeq)
{
u32 shift;
if (micSeq > context->window) {
shift = (micSeq - context->window) >> 1;
if (shift < 32)
context->rx >>= shift;
else
context->rx = 0;
context->window = micSeq;
}
}
static void emmh32_setseed(emmh32_context *context, u8 *pkey, int keylen,
struct crypto_cipher *tfm)
{
int i,j;
u32 counter;
u8 *cipher, plain[16];
crypto_cipher_setkey(tfm, pkey, 16);
counter = 0;
for (i = 0; i < ARRAY_SIZE(context->coeff); ) {
aes_counter[15] = (u8)(counter >> 0);
aes_counter[14] = (u8)(counter >> 8);
aes_counter[13] = (u8)(counter >> 16);
aes_counter[12] = (u8)(counter >> 24);
counter++;
memcpy (plain, aes_counter, 16);
crypto_cipher_encrypt_one(tfm, plain, plain);
cipher = plain;
for (j = 0; (j < 16) && (i < ARRAY_SIZE(context->coeff)); ) {
context->coeff[i++] = ntohl(*(__be32 *)&cipher[j]);
j += 4;
}
}
}
static void emmh32_init(emmh32_context *context)
{
context->accum = 0;
context->position = 0;
}
static void emmh32_update(emmh32_context *context, u8 *pOctets, int len)
{
int coeff_position, byte_position;
if (len == 0) return;
coeff_position = context->position >> 2;
byte_position = context->position & 3;
if (byte_position) {
do {
if (len == 0) return;
context->part.d8[byte_position++] = *pOctets++;
context->position++;
len--;
} while (byte_position < 4);
MIC_ACCUM(ntohl(context->part.d32));
}
while (len >= 4) {
MIC_ACCUM(ntohl(*(__be32 *)pOctets));
context->position += 4;
pOctets += 4;
len -= 4;
}
byte_position = 0;
while (len > 0) {
context->part.d8[byte_position++] = *pOctets++;
context->position++;
len--;
}
}
static void emmh32_final(emmh32_context *context, u8 digest[4])
{
int coeff_position, byte_position;
u32 val;
u64 sum, utmp;
s64 stmp;
coeff_position = context->position >> 2;
byte_position = context->position & 3;
if (byte_position) {
val = ntohl(context->part.d32);
MIC_ACCUM(val & mask32[byte_position]);
}
sum = context->accum;
stmp = (sum & 0xffffffffLL) - ((sum >> 32) * 15);
utmp = (stmp & 0xffffffffLL) - ((stmp >> 32) * 15);
sum = utmp & 0xffffffffLL;
if (utmp > 0x10000000fLL)
sum -= 15;
val = (u32)sum;
digest[0] = (val>>24) & 0xFF;
digest[1] = (val>>16) & 0xFF;
digest[2] = (val>>8) & 0xFF;
digest[3] = val & 0xFF;
}
static int readBSSListRid(struct airo_info *ai, int first,
BSSListRid *list)
{
Cmd cmd;
Resp rsp;
if (first == 1) {
if (ai->flags & FLAG_RADIO_MASK) return -ENETDOWN;
memset(&cmd, 0, sizeof(cmd));
cmd.cmd=CMD_LISTBSS;
if (down_interruptible(&ai->sem))
return -ERESTARTSYS;
ai->list_bss_task = current;
issuecommand(ai, &cmd, &rsp);
up(&ai->sem);
schedule_timeout_uninterruptible(3 * HZ);
ai->list_bss_task = NULL;
}
return PC4500_readrid(ai, first ? ai->bssListFirst : ai->bssListNext,
list, ai->bssListRidLen, 1);
}
static int readWepKeyRid(struct airo_info *ai, WepKeyRid *wkr, int temp, int lock)
{
return PC4500_readrid(ai, temp ? RID_WEP_TEMP : RID_WEP_PERM,
wkr, sizeof(*wkr), lock);
}
static int writeWepKeyRid(struct airo_info *ai, WepKeyRid *wkr, int perm, int lock)
{
int rc;
rc = PC4500_writerid(ai, RID_WEP_TEMP, wkr, sizeof(*wkr), lock);
if (rc!=SUCCESS)
airo_print_err(ai->dev->name, "WEP_TEMP set %x", rc);
if (perm) {
rc = PC4500_writerid(ai, RID_WEP_PERM, wkr, sizeof(*wkr), lock);
if (rc!=SUCCESS)
airo_print_err(ai->dev->name, "WEP_PERM set %x", rc);
}
return rc;
}
static int readSsidRid(struct airo_info*ai, SsidRid *ssidr)
{
return PC4500_readrid(ai, RID_SSID, ssidr, sizeof(*ssidr), 1);
}
static int writeSsidRid(struct airo_info*ai, SsidRid *pssidr, int lock)
{
return PC4500_writerid(ai, RID_SSID, pssidr, sizeof(*pssidr), lock);
}
static int readConfigRid(struct airo_info *ai, int lock)
{
int rc;
ConfigRid cfg;
if (ai->config.len)
return SUCCESS;
rc = PC4500_readrid(ai, RID_ACTUALCONFIG, &cfg, sizeof(cfg), lock);
if (rc != SUCCESS)
return rc;
ai->config = cfg;
return SUCCESS;
}
static inline void checkThrottle(struct airo_info *ai)
{
int i;
if (ai->config.authType != AUTH_OPEN && maxencrypt) {
for(i=0; i<8; i++) {
if (ai->config.rates[i] > maxencrypt) {
ai->config.rates[i] = 0;
}
}
}
}
static int writeConfigRid(struct airo_info *ai, int lock)
{
ConfigRid cfgr;
if (!test_bit (FLAG_COMMIT, &ai->flags))
return SUCCESS;
clear_bit (FLAG_COMMIT, &ai->flags);
clear_bit (FLAG_RESET, &ai->flags);
checkThrottle(ai);
cfgr = ai->config;
if ((cfgr.opmode & MODE_CFG_MASK) == MODE_STA_IBSS)
set_bit(FLAG_ADHOC, &ai->flags);
else
clear_bit(FLAG_ADHOC, &ai->flags);
return PC4500_writerid( ai, RID_CONFIG, &cfgr, sizeof(cfgr), lock);
}
static int readStatusRid(struct airo_info *ai, StatusRid *statr, int lock)
{
return PC4500_readrid(ai, RID_STATUS, statr, sizeof(*statr), lock);
}
static int readAPListRid(struct airo_info *ai, APListRid *aplr)
{
return PC4500_readrid(ai, RID_APLIST, aplr, sizeof(*aplr), 1);
}
static int writeAPListRid(struct airo_info *ai, APListRid *aplr, int lock)
{
return PC4500_writerid(ai, RID_APLIST, aplr, sizeof(*aplr), lock);
}
static int readCapabilityRid(struct airo_info *ai, CapabilityRid *capr, int lock)
{
return PC4500_readrid(ai, RID_CAPABILITIES, capr, sizeof(*capr), lock);
}
static int readStatsRid(struct airo_info*ai, StatsRid *sr, int rid, int lock)
{
return PC4500_readrid(ai, rid, sr, sizeof(*sr), lock);
}
static void try_auto_wep(struct airo_info *ai)
{
if (auto_wep && !test_bit(FLAG_RADIO_DOWN, &ai->flags)) {
ai->expires = RUN_AT(3*HZ);
wake_up_interruptible(&ai->thr_wait);
}
}
static int airo_open(struct net_device *dev) {
struct airo_info *ai = dev->ml_priv;
int rc = 0;
if (test_bit(FLAG_FLASHING, &ai->flags))
return -EIO;
if (test_bit(FLAG_COMMIT, &ai->flags)) {
disable_MAC(ai, 1);
writeConfigRid(ai, 1);
}
if (ai->wifidev != dev) {
clear_bit(JOB_DIE, &ai->jobs);
ai->airo_thread_task = kthread_run(airo_thread, dev, dev->name);
if (IS_ERR(ai->airo_thread_task))
return (int)PTR_ERR(ai->airo_thread_task);
rc = request_irq(dev->irq, airo_interrupt, IRQF_SHARED,
dev->name, dev);
if (rc) {
airo_print_err(dev->name,
"register interrupt %d failed, rc %d",
dev->irq, rc);
set_bit(JOB_DIE, &ai->jobs);
kthread_stop(ai->airo_thread_task);
return rc;
}
clear_bit(FLAG_RADIO_DOWN, &ai->flags);
enable_interrupts(ai);
try_auto_wep(ai);
}
enable_MAC(ai, 1);
netif_start_queue(dev);
return 0;
}
static netdev_tx_t mpi_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
int npacks, pending;
unsigned long flags;
struct airo_info *ai = dev->ml_priv;
if (!skb) {
airo_print_err(dev->name, "%s: skb == NULL!",__func__);
return NETDEV_TX_OK;
}
npacks = skb_queue_len (&ai->txq);
if (npacks >= MAXTXQ - 1) {
netif_stop_queue (dev);
if (npacks > MAXTXQ) {
dev->stats.tx_fifo_errors++;
return NETDEV_TX_BUSY;
}
skb_queue_tail (&ai->txq, skb);
return NETDEV_TX_OK;
}
spin_lock_irqsave(&ai->aux_lock, flags);
skb_queue_tail (&ai->txq, skb);
pending = test_bit(FLAG_PENDING_XMIT, &ai->flags);
spin_unlock_irqrestore(&ai->aux_lock,flags);
netif_wake_queue (dev);
if (pending == 0) {
set_bit(FLAG_PENDING_XMIT, &ai->flags);
mpi_send_packet (dev);
}
return NETDEV_TX_OK;
}
static int mpi_send_packet (struct net_device *dev)
{
struct sk_buff *skb;
unsigned char *buffer;
s16 len;
__le16 *payloadLen;
struct airo_info *ai = dev->ml_priv;
u8 *sendbuf;
if ((skb = skb_dequeue(&ai->txq)) == NULL) {
airo_print_err(dev->name,
"%s: Dequeue'd zero in send_packet()",
__func__);
return 0;
}
len = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN;
buffer = skb->data;
ai->txfids[0].tx_desc.offset = 0;
ai->txfids[0].tx_desc.valid = 1;
ai->txfids[0].tx_desc.eoc = 1;
ai->txfids[0].tx_desc.len =len+sizeof(WifiHdr);
memcpy(ai->txfids[0].virtual_host_addr,
(char *)&wifictlhdr8023, sizeof(wifictlhdr8023));
payloadLen = (__le16 *)(ai->txfids[0].virtual_host_addr +
sizeof(wifictlhdr8023));
sendbuf = ai->txfids[0].virtual_host_addr +
sizeof(wifictlhdr8023) + 2 ;
if (test_bit(FLAG_MIC_CAPABLE, &ai->flags) && ai->micstats.enabled &&
(ntohs(((__be16 *)buffer)[6]) != 0x888E)) {
MICBuffer pMic;
if (encapsulate(ai, (etherHead *)buffer, &pMic, len - sizeof(etherHead)) != SUCCESS)
return ERROR;
*payloadLen = cpu_to_le16(len-sizeof(etherHead)+sizeof(pMic));
ai->txfids[0].tx_desc.len += sizeof(pMic);
memcpy (sendbuf, buffer, sizeof(etherHead));
buffer += sizeof(etherHead);
sendbuf += sizeof(etherHead);
memcpy (sendbuf, &pMic, sizeof(pMic));
sendbuf += sizeof(pMic);
memcpy (sendbuf, buffer, len - sizeof(etherHead));
} else {
*payloadLen = cpu_to_le16(len - sizeof(etherHead));
dev->trans_start = jiffies;
memcpy(sendbuf, buffer, len);
}
memcpy_toio(ai->txfids[0].card_ram_off,
&ai->txfids[0].tx_desc, sizeof(TxFid));
OUT4500(ai, EVACK, 8);
dev_kfree_skb_any(skb);
return 1;
}
static void get_tx_error(struct airo_info *ai, s32 fid)
{
__le16 status;
if (fid < 0)
status = ((WifiCtlHdr *)ai->txfids[0].virtual_host_addr)->ctlhdr.status;
else {
if (bap_setup(ai, ai->fids[fid] & 0xffff, 4, BAP0) != SUCCESS)
return;
bap_read(ai, &status, 2, BAP0);
}
if (le16_to_cpu(status) & 2)
ai->dev->stats.tx_aborted_errors++;
if (le16_to_cpu(status) & 4)
ai->dev->stats.tx_heartbeat_errors++;
if (le16_to_cpu(status) & 8)
{ }
if (le16_to_cpu(status) & 0x10)
ai->dev->stats.tx_carrier_errors++;
if (le16_to_cpu(status) & 0x20)
{ }
if ((le16_to_cpu(status) & 2) ||
(le16_to_cpu(status) & 4)) {
union iwreq_data wrqu;
char junk[0x18];
bap_read(ai, (__le16 *) junk, 0x18, BAP0);
memcpy(wrqu.addr.sa_data, junk + 0x12, ETH_ALEN);
wrqu.addr.sa_family = ARPHRD_ETHER;
wireless_send_event(ai->dev, IWEVTXDROP, &wrqu, NULL);
}
}
static void airo_end_xmit(struct net_device *dev) {
u16 status;
int i;
struct airo_info *priv = dev->ml_priv;
struct sk_buff *skb = priv->xmit.skb;
int fid = priv->xmit.fid;
u32 *fids = priv->fids;
clear_bit(JOB_XMIT, &priv->jobs);
clear_bit(FLAG_PENDING_XMIT, &priv->flags);
status = transmit_802_3_packet (priv, fids[fid], skb->data);
up(&priv->sem);
i = 0;
if ( status == SUCCESS ) {
dev->trans_start = jiffies;
for (; i < MAX_FIDS / 2 && (priv->fids[i] & 0xffff0000); i++);
} else {
priv->fids[fid] &= 0xffff;
dev->stats.tx_window_errors++;
}
if (i < MAX_FIDS / 2)
netif_wake_queue(dev);
dev_kfree_skb(skb);
}
static netdev_tx_t airo_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
s16 len;
int i, j;
struct airo_info *priv = dev->ml_priv;
u32 *fids = priv->fids;
if ( skb == NULL ) {
airo_print_err(dev->name, "%s: skb == NULL!", __func__);
return NETDEV_TX_OK;
}
for( i = 0; i < MAX_FIDS / 2 && (fids[i] & 0xffff0000); i++ );
for( j = i + 1; j < MAX_FIDS / 2 && (fids[j] & 0xffff0000); j++ );
if ( j >= MAX_FIDS / 2 ) {
netif_stop_queue(dev);
if (i == MAX_FIDS / 2) {
dev->stats.tx_fifo_errors++;
return NETDEV_TX_BUSY;
}
}
len = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN;
fids[i] |= (len << 16);
priv->xmit.skb = skb;
priv->xmit.fid = i;
if (down_trylock(&priv->sem) != 0) {
set_bit(FLAG_PENDING_XMIT, &priv->flags);
netif_stop_queue(dev);
set_bit(JOB_XMIT, &priv->jobs);
wake_up_interruptible(&priv->thr_wait);
} else
airo_end_xmit(dev);
return NETDEV_TX_OK;
}
static void airo_end_xmit11(struct net_device *dev) {
u16 status;
int i;
struct airo_info *priv = dev->ml_priv;
struct sk_buff *skb = priv->xmit11.skb;
int fid = priv->xmit11.fid;
u32 *fids = priv->fids;
clear_bit(JOB_XMIT11, &priv->jobs);
clear_bit(FLAG_PENDING_XMIT11, &priv->flags);
status = transmit_802_11_packet (priv, fids[fid], skb->data);
up(&priv->sem);
i = MAX_FIDS / 2;
if ( status == SUCCESS ) {
dev->trans_start = jiffies;
for (; i < MAX_FIDS && (priv->fids[i] & 0xffff0000); i++);
} else {
priv->fids[fid] &= 0xffff;
dev->stats.tx_window_errors++;
}
if (i < MAX_FIDS)
netif_wake_queue(dev);
dev_kfree_skb(skb);
}
static netdev_tx_t airo_start_xmit11(struct sk_buff *skb,
struct net_device *dev)
{
s16 len;
int i, j;
struct airo_info *priv = dev->ml_priv;
u32 *fids = priv->fids;
if (test_bit(FLAG_MPI, &priv->flags)) {
netif_stop_queue(dev);
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
if ( skb == NULL ) {
airo_print_err(dev->name, "%s: skb == NULL!", __func__);
return NETDEV_TX_OK;
}
for( i = MAX_FIDS / 2; i < MAX_FIDS && (fids[i] & 0xffff0000); i++ );
for( j = i + 1; j < MAX_FIDS && (fids[j] & 0xffff0000); j++ );
if ( j >= MAX_FIDS ) {
netif_stop_queue(dev);
if (i == MAX_FIDS) {
dev->stats.tx_fifo_errors++;
return NETDEV_TX_BUSY;
}
}
len = ETH_ZLEN < skb->len ? skb->len : ETH_ZLEN;
fids[i] |= (len << 16);
priv->xmit11.skb = skb;
priv->xmit11.fid = i;
if (down_trylock(&priv->sem) != 0) {
set_bit(FLAG_PENDING_XMIT11, &priv->flags);
netif_stop_queue(dev);
set_bit(JOB_XMIT11, &priv->jobs);
wake_up_interruptible(&priv->thr_wait);
} else
airo_end_xmit11(dev);
return NETDEV_TX_OK;
}
static void airo_read_stats(struct net_device *dev)
{
struct airo_info *ai = dev->ml_priv;
StatsRid stats_rid;
__le32 *vals = stats_rid.vals;
clear_bit(JOB_STATS, &ai->jobs);
if (ai->power.event) {
up(&ai->sem);
return;
}
readStatsRid(ai, &stats_rid, RID_STATS, 0);
up(&ai->sem);
dev->stats.rx_packets = le32_to_cpu(vals[43]) + le32_to_cpu(vals[44]) +
le32_to_cpu(vals[45]);
dev->stats.tx_packets = le32_to_cpu(vals[39]) + le32_to_cpu(vals[40]) +
le32_to_cpu(vals[41]);
dev->stats.rx_bytes = le32_to_cpu(vals[92]);
dev->stats.tx_bytes = le32_to_cpu(vals[91]);
dev->stats.rx_errors = le32_to_cpu(vals[0]) + le32_to_cpu(vals[2]) +
le32_to_cpu(vals[3]) + le32_to_cpu(vals[4]);
dev->stats.tx_errors = le32_to_cpu(vals[42]) +
dev->stats.tx_fifo_errors;
dev->stats.multicast = le32_to_cpu(vals[43]);
dev->stats.collisions = le32_to_cpu(vals[89]);
dev->stats.rx_length_errors = le32_to_cpu(vals[3]);
dev->stats.rx_crc_errors = le32_to_cpu(vals[4]);
dev->stats.rx_frame_errors = le32_to_cpu(vals[2]);
dev->stats.rx_fifo_errors = le32_to_cpu(vals[0]);
}
static struct net_device_stats *airo_get_stats(struct net_device *dev)
{
struct airo_info *local = dev->ml_priv;
if (!test_bit(JOB_STATS, &local->jobs)) {
if (down_trylock(&local->sem) != 0) {
set_bit(JOB_STATS, &local->jobs);
wake_up_interruptible(&local->thr_wait);
} else
airo_read_stats(dev);
}
return &dev->stats;
}
static void airo_set_promisc(struct airo_info *ai) {
Cmd cmd;
Resp rsp;
memset(&cmd, 0, sizeof(cmd));
cmd.cmd=CMD_SETMODE;
clear_bit(JOB_PROMISC, &ai->jobs);
cmd.parm0=(ai->flags&IFF_PROMISC) ? PROMISC : NOPROMISC;
issuecommand(ai, &cmd, &rsp);
up(&ai->sem);
}
static void airo_set_multicast_list(struct net_device *dev) {
struct airo_info *ai = dev->ml_priv;
if ((dev->flags ^ ai->flags) & IFF_PROMISC) {
change_bit(FLAG_PROMISC, &ai->flags);
if (down_trylock(&ai->sem) != 0) {
set_bit(JOB_PROMISC, &ai->jobs);
wake_up_interruptible(&ai->thr_wait);
} else
airo_set_promisc(ai);
}
if ((dev->flags&IFF_ALLMULTI) || !netdev_mc_empty(dev)) {
}
}
static int airo_set_mac_address(struct net_device *dev, void *p)
{
struct airo_info *ai = dev->ml_priv;
struct sockaddr *addr = p;
readConfigRid(ai, 1);
memcpy (ai->config.macAddr, addr->sa_data, dev->addr_len);
set_bit (FLAG_COMMIT, &ai->flags);
disable_MAC(ai, 1);
writeConfigRid (ai, 1);
enable_MAC(ai, 1);
memcpy (ai->dev->dev_addr, addr->sa_data, dev->addr_len);
if (ai->wifidev)
memcpy (ai->wifidev->dev_addr, addr->sa_data, dev->addr_len);
return 0;
}
static int airo_change_mtu(struct net_device *dev, int new_mtu)
{
if ((new_mtu < 68) || (new_mtu > 2400))
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static void add_airo_dev(struct airo_info *ai)
{
if (!ai->pci)
list_add_tail(&ai->dev_list, &airo_devices);
}
static void del_airo_dev(struct airo_info *ai)
{
if (!ai->pci)
list_del(&ai->dev_list);
}
static int airo_close(struct net_device *dev) {
struct airo_info *ai = dev->ml_priv;
netif_stop_queue(dev);
if (ai->wifidev != dev) {
#ifdef POWER_ON_DOWN
set_bit(FLAG_RADIO_DOWN, &ai->flags);
disable_MAC(ai, 1);
#endif
disable_interrupts( ai );
free_irq(dev->irq, dev);
set_bit(JOB_DIE, &ai->jobs);
kthread_stop(ai->airo_thread_task);
}
return 0;
}
void stop_airo_card( struct net_device *dev, int freeres )
{
struct airo_info *ai = dev->ml_priv;
set_bit(FLAG_RADIO_DOWN, &ai->flags);
disable_MAC(ai, 1);
disable_interrupts(ai);
takedown_proc_entry( dev, ai );
if (test_bit(FLAG_REGISTERED, &ai->flags)) {
unregister_netdev( dev );
if (ai->wifidev) {
unregister_netdev(ai->wifidev);
free_netdev(ai->wifidev);
ai->wifidev = NULL;
}
clear_bit(FLAG_REGISTERED, &ai->flags);
}
if (test_bit(FLAG_MPI, &ai->flags) && !skb_queue_empty(&ai->txq)) {
struct sk_buff *skb = NULL;
for (;(skb = skb_dequeue(&ai->txq));)
dev_kfree_skb(skb);
}
airo_networks_free (ai);
kfree(ai->flash);
kfree(ai->rssi);
kfree(ai->APList);
kfree(ai->SSID);
if (freeres) {
release_region( dev->base_addr, 64 );
if (test_bit(FLAG_MPI, &ai->flags)) {
if (ai->pci)
mpi_unmap_card(ai->pci);
if (ai->pcimem)
iounmap(ai->pcimem);
if (ai->pciaux)
iounmap(ai->pciaux);
pci_free_consistent(ai->pci, PCI_SHARED_LEN,
ai->shared, ai->shared_dma);
}
}
crypto_free_cipher(ai->tfm);
del_airo_dev(ai);
free_netdev( dev );
}
static int wll_header_parse(const struct sk_buff *skb, unsigned char *haddr)
{
memcpy(haddr, skb_mac_header(skb) + 10, ETH_ALEN);
return ETH_ALEN;
}
static void mpi_unmap_card(struct pci_dev *pci)
{
unsigned long mem_start = pci_resource_start(pci, 1);
unsigned long mem_len = pci_resource_len(pci, 1);
unsigned long aux_start = pci_resource_start(pci, 2);
unsigned long aux_len = AUXMEMSIZE;
release_mem_region(aux_start, aux_len);
release_mem_region(mem_start, mem_len);
}
static int mpi_init_descriptors (struct airo_info *ai)
{
Cmd cmd;
Resp rsp;
int i;
int rc = SUCCESS;
netif_stop_queue(ai->dev);
memset(&rsp,0,sizeof(rsp));
memset(&cmd,0,sizeof(cmd));
cmd.cmd = CMD_ALLOCATEAUX;
cmd.parm0 = FID_RX;
cmd.parm1 = (ai->rxfids[0].card_ram_off - ai->pciaux);
cmd.parm2 = MPI_MAX_FIDS;
rc=issuecommand(ai, &cmd, &rsp);
if (rc != SUCCESS) {
airo_print_err(ai->dev->name, "Couldn't allocate RX FID");
return rc;
}
for (i=0; i<MPI_MAX_FIDS; i++) {
memcpy_toio(ai->rxfids[i].card_ram_off,
&ai->rxfids[i].rx_desc, sizeof(RxFid));
}
memset(&rsp,0,sizeof(rsp));
memset(&cmd,0,sizeof(cmd));
cmd.cmd = CMD_ALLOCATEAUX;
cmd.parm0 = FID_TX;
cmd.parm1 = (ai->txfids[0].card_ram_off - ai->pciaux);
cmd.parm2 = MPI_MAX_FIDS;
for (i=0; i<MPI_MAX_FIDS; i++) {
ai->txfids[i].tx_desc.valid = 1;
memcpy_toio(ai->txfids[i].card_ram_off,
&ai->txfids[i].tx_desc, sizeof(TxFid));
}
ai->txfids[i-1].tx_desc.eoc = 1;
rc=issuecommand(ai, &cmd, &rsp);
if (rc != SUCCESS) {
airo_print_err(ai->dev->name, "Couldn't allocate TX FID");
return rc;
}
memset(&rsp,0,sizeof(rsp));
memset(&cmd,0,sizeof(cmd));
cmd.cmd = CMD_ALLOCATEAUX;
cmd.parm0 = RID_RW;
cmd.parm1 = (ai->config_desc.card_ram_off - ai->pciaux);
cmd.parm2 = 1;
rc=issuecommand(ai, &cmd, &rsp);
if (rc != SUCCESS) {
airo_print_err(ai->dev->name, "Couldn't allocate RID");
return rc;
}
memcpy_toio(ai->config_desc.card_ram_off,
&ai->config_desc.rid_desc, sizeof(Rid));
return rc;
}
static int mpi_map_card(struct airo_info *ai, struct pci_dev *pci)
{
unsigned long mem_start, mem_len, aux_start, aux_len;
int rc = -1;
int i;
dma_addr_t busaddroff;
unsigned char *vpackoff;
unsigned char __iomem *pciaddroff;
mem_start = pci_resource_start(pci, 1);
mem_len = pci_resource_len(pci, 1);
aux_start = pci_resource_start(pci, 2);
aux_len = AUXMEMSIZE;
if (!request_mem_region(mem_start, mem_len, DRV_NAME)) {
airo_print_err("", "Couldn't get region %x[%x]",
(int)mem_start, (int)mem_len);
goto out;
}
if (!request_mem_region(aux_start, aux_len, DRV_NAME)) {
airo_print_err("", "Couldn't get region %x[%x]",
(int)aux_start, (int)aux_len);
goto free_region1;
}
ai->pcimem = ioremap(mem_start, mem_len);
if (!ai->pcimem) {
airo_print_err("", "Couldn't map region %x[%x]",
(int)mem_start, (int)mem_len);
goto free_region2;
}
ai->pciaux = ioremap(aux_start, aux_len);
if (!ai->pciaux) {
airo_print_err("", "Couldn't map region %x[%x]",
(int)aux_start, (int)aux_len);
goto free_memmap;
}
ai->shared = pci_alloc_consistent(pci, PCI_SHARED_LEN, &ai->shared_dma);
if (!ai->shared) {
airo_print_err("", "Couldn't alloc_consistent %d",
PCI_SHARED_LEN);
goto free_auxmap;
}
busaddroff = ai->shared_dma;
pciaddroff = ai->pciaux + AUX_OFFSET;
vpackoff = ai->shared;
for(i = 0; i < MPI_MAX_FIDS; i++) {
ai->rxfids[i].pending = 0;
ai->rxfids[i].card_ram_off = pciaddroff;
ai->rxfids[i].virtual_host_addr = vpackoff;
ai->rxfids[i].rx_desc.host_addr = busaddroff;
ai->rxfids[i].rx_desc.valid = 1;
ai->rxfids[i].rx_desc.len = PKTSIZE;
ai->rxfids[i].rx_desc.rdy = 0;
pciaddroff += sizeof(RxFid);
busaddroff += PKTSIZE;
vpackoff += PKTSIZE;
}
for(i = 0; i < MPI_MAX_FIDS; i++) {
ai->txfids[i].card_ram_off = pciaddroff;
ai->txfids[i].virtual_host_addr = vpackoff;
ai->txfids[i].tx_desc.valid = 1;
ai->txfids[i].tx_desc.host_addr = busaddroff;
memcpy(ai->txfids[i].virtual_host_addr,
&wifictlhdr8023, sizeof(wifictlhdr8023));
pciaddroff += sizeof(TxFid);
busaddroff += PKTSIZE;
vpackoff += PKTSIZE;
}
ai->txfids[i-1].tx_desc.eoc = 1;
ai->config_desc.card_ram_off = pciaddroff;
ai->config_desc.virtual_host_addr = vpackoff;
ai->config_desc.rid_desc.host_addr = busaddroff;
ai->ridbus = busaddroff;
ai->config_desc.rid_desc.rid = 0;
ai->config_desc.rid_desc.len = RIDSIZE;
ai->config_desc.rid_desc.valid = 1;
pciaddroff += sizeof(Rid);
busaddroff += RIDSIZE;
vpackoff += RIDSIZE;
if (mpi_init_descriptors (ai) != SUCCESS)
goto free_shared;
return 0;
free_shared:
pci_free_consistent(pci, PCI_SHARED_LEN, ai->shared, ai->shared_dma);
free_auxmap:
iounmap(ai->pciaux);
free_memmap:
iounmap(ai->pcimem);
free_region2:
release_mem_region(aux_start, aux_len);
free_region1:
release_mem_region(mem_start, mem_len);
out:
return rc;
}
static void wifi_setup(struct net_device *dev)
{
dev->netdev_ops = &airo11_netdev_ops;
dev->header_ops = &airo_header_ops;
dev->wireless_handlers = &airo_handler_def;
dev->type = ARPHRD_IEEE80211;
dev->hard_header_len = ETH_HLEN;
dev->mtu = AIRO_DEF_MTU;
dev->addr_len = ETH_ALEN;
dev->tx_queue_len = 100;
memset(dev->broadcast,0xFF, ETH_ALEN);
dev->flags = IFF_BROADCAST|IFF_MULTICAST;
}
static struct net_device *init_wifidev(struct airo_info *ai,
struct net_device *ethdev)
{
int err;
struct net_device *dev = alloc_netdev(0, "wifi%d", wifi_setup);
if (!dev)
return NULL;
dev->ml_priv = ethdev->ml_priv;
dev->irq = ethdev->irq;
dev->base_addr = ethdev->base_addr;
dev->wireless_data = ethdev->wireless_data;
SET_NETDEV_DEV(dev, ethdev->dev.parent);
memcpy(dev->dev_addr, ethdev->dev_addr, dev->addr_len);
err = register_netdev(dev);
if (err<0) {
free_netdev(dev);
return NULL;
}
return dev;
}
static int reset_card( struct net_device *dev , int lock) {
struct airo_info *ai = dev->ml_priv;
if (lock && down_interruptible(&ai->sem))
return -1;
waitbusy (ai);
OUT4500(ai,COMMAND,CMD_SOFTRESET);
msleep(200);
waitbusy (ai);
msleep(200);
if (lock)
up(&ai->sem);
return 0;
}
static int airo_networks_allocate(struct airo_info *ai)
{
if (ai->networks)
return 0;
ai->networks = kcalloc(AIRO_MAX_NETWORK_COUNT, sizeof(BSSListElement),
GFP_KERNEL);
if (!ai->networks) {
airo_print_warn("", "Out of memory allocating beacons");
return -ENOMEM;
}
return 0;
}
static void airo_networks_free(struct airo_info *ai)
{
kfree(ai->networks);
ai->networks = NULL;
}
static void airo_networks_initialize(struct airo_info *ai)
{
int i;
INIT_LIST_HEAD(&ai->network_free_list);
INIT_LIST_HEAD(&ai->network_list);
for (i = 0; i < AIRO_MAX_NETWORK_COUNT; i++)
list_add_tail(&ai->networks[i].list,
&ai->network_free_list);
}
static struct net_device *_init_airo_card( unsigned short irq, int port,
int is_pcmcia, struct pci_dev *pci,
struct device *dmdev )
{
struct net_device *dev;
struct airo_info *ai;
int i, rc;
CapabilityRid cap_rid;
dev = alloc_netdev(sizeof(*ai), "", ether_setup);
if (!dev) {
airo_print_err("", "Couldn't alloc_etherdev");
return NULL;
}
ai = dev->ml_priv = netdev_priv(dev);
ai->wifidev = NULL;
ai->flags = 1 << FLAG_RADIO_DOWN;
ai->jobs = 0;
ai->dev = dev;
if (pci && (pci->device == 0x5000 || pci->device == 0xa504)) {
airo_print_dbg("", "Found an MPI350 card");
set_bit(FLAG_MPI, &ai->flags);
}
spin_lock_init(&ai->aux_lock);
sema_init(&ai->sem, 1);
ai->config.len = 0;
ai->pci = pci;
init_waitqueue_head (&ai->thr_wait);
ai->tfm = NULL;
add_airo_dev(ai);
if (airo_networks_allocate (ai))
goto err_out_free;
airo_networks_initialize (ai);
skb_queue_head_init (&ai->txq);
if (test_bit(FLAG_MPI,&ai->flags))
dev->netdev_ops = &mpi_netdev_ops;
else
dev->netdev_ops = &airo_netdev_ops;
dev->wireless_handlers = &airo_handler_def;
ai->wireless_data.spy_data = &ai->spy_data;
dev->wireless_data = &ai->wireless_data;
dev->irq = irq;
dev->base_addr = port;
dev->priv_flags &= ~IFF_TX_SKB_SHARING;
SET_NETDEV_DEV(dev, dmdev);
reset_card (dev, 1);
msleep(400);
if (!is_pcmcia) {
if (!request_region(dev->base_addr, 64, DRV_NAME)) {
rc = -EBUSY;
airo_print_err(dev->name, "Couldn't request region");
goto err_out_nets;
}
}
if (test_bit(FLAG_MPI,&ai->flags)) {
if (mpi_map_card(ai, pci)) {
airo_print_err("", "Could not map memory");
goto err_out_res;
}
}
if (probe) {
if (setup_card(ai, dev->dev_addr, 1) != SUCCESS) {
airo_print_err(dev->name, "MAC could not be enabled" );
rc = -EIO;
goto err_out_map;
}
} else if (!test_bit(FLAG_MPI,&ai->flags)) {
ai->bap_read = fast_bap_read;
set_bit(FLAG_FLASHING, &ai->flags);
}
strcpy(dev->name, "eth%d");
rc = register_netdev(dev);
if (rc) {
airo_print_err(dev->name, "Couldn't register_netdev");
goto err_out_map;
}
ai->wifidev = init_wifidev(ai, dev);
if (!ai->wifidev)
goto err_out_reg;
rc = readCapabilityRid(ai, &cap_rid, 1);
if (rc != SUCCESS) {
rc = -EIO;
goto err_out_wifi;
}
ai->wep_capable = (cap_rid.softCap & cpu_to_le16(0x02)) ? 1 : 0;
ai->max_wep_idx = (cap_rid.softCap & cpu_to_le16(0x80)) ? 3 : 0;
airo_print_info(dev->name, "Firmware version %x.%x.%02d",
((le16_to_cpu(cap_rid.softVer) >> 8) & 0xF),
(le16_to_cpu(cap_rid.softVer) & 0xFF),
le16_to_cpu(cap_rid.softSubVer));
if (le16_to_cpu(cap_rid.softVer) > 0x530
|| (le16_to_cpu(cap_rid.softVer) == 0x530
&& le16_to_cpu(cap_rid.softSubVer) >= 17)) {
airo_print_info(ai->dev->name, "WPA supported.");
set_bit(FLAG_WPA_CAPABLE, &ai->flags);
ai->bssListFirst = RID_WPA_BSSLISTFIRST;
ai->bssListNext = RID_WPA_BSSLISTNEXT;
ai->bssListRidLen = sizeof(BSSListRid);
} else {
airo_print_info(ai->dev->name, "WPA unsupported with firmware "
"versions older than 5.30.17.");
ai->bssListFirst = RID_BSSLISTFIRST;
ai->bssListNext = RID_BSSLISTNEXT;
ai->bssListRidLen = sizeof(BSSListRid) - sizeof(BSSListRidExtra);
}
set_bit(FLAG_REGISTERED,&ai->flags);
airo_print_info(dev->name, "MAC enabled %pM", dev->dev_addr);
if (probe && !test_bit(FLAG_MPI,&ai->flags))
for( i = 0; i < MAX_FIDS; i++ )
ai->fids[i] = transmit_allocate(ai,AIRO_DEF_MTU,i>=MAX_FIDS/2);
if (setup_proc_entry(dev, dev->ml_priv) < 0)
goto err_out_wifi;
return dev;
err_out_wifi:
unregister_netdev(ai->wifidev);
free_netdev(ai->wifidev);
err_out_reg:
unregister_netdev(dev);
err_out_map:
if (test_bit(FLAG_MPI,&ai->flags) && pci) {
pci_free_consistent(pci, PCI_SHARED_LEN, ai->shared, ai->shared_dma);
iounmap(ai->pciaux);
iounmap(ai->pcimem);
mpi_unmap_card(ai->pci);
}
err_out_res:
if (!is_pcmcia)
release_region( dev->base_addr, 64 );
err_out_nets:
airo_networks_free(ai);
err_out_free:
del_airo_dev(ai);
free_netdev(dev);
return NULL;
}
struct net_device *init_airo_card( unsigned short irq, int port, int is_pcmcia,
struct device *dmdev)
{
return _init_airo_card ( irq, port, is_pcmcia, NULL, dmdev);
}
static int waitbusy (struct airo_info *ai) {
int delay = 0;
while ((IN4500(ai, COMMAND) & COMMAND_BUSY) && (delay < 10000)) {
udelay (10);
if ((++delay % 20) == 0)
OUT4500(ai, EVACK, EV_CLEARCOMMANDBUSY);
}
return delay < 10000;
}
int reset_airo_card( struct net_device *dev )
{
int i;
struct airo_info *ai = dev->ml_priv;
if (reset_card (dev, 1))
return -1;
if ( setup_card(ai, dev->dev_addr, 1 ) != SUCCESS ) {
airo_print_err(dev->name, "MAC could not be enabled");
return -1;
}
airo_print_info(dev->name, "MAC enabled %pM", dev->dev_addr);
if (!test_bit(FLAG_MPI,&ai->flags))
for( i = 0; i < MAX_FIDS; i++ )
ai->fids[i] = transmit_allocate (ai,AIRO_DEF_MTU,i>=MAX_FIDS/2);
enable_interrupts( ai );
netif_wake_queue(dev);
return 0;
}
static void airo_send_event(struct net_device *dev) {
struct airo_info *ai = dev->ml_priv;
union iwreq_data wrqu;
StatusRid status_rid;
clear_bit(JOB_EVENT, &ai->jobs);
PC4500_readrid(ai, RID_STATUS, &status_rid, sizeof(status_rid), 0);
up(&ai->sem);
wrqu.data.length = 0;
wrqu.data.flags = 0;
memcpy(wrqu.ap_addr.sa_data, status_rid.bssid[0], ETH_ALEN);
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
wireless_send_event(dev, SIOCGIWAP, &wrqu, NULL);
}
static void airo_process_scan_results (struct airo_info *ai) {
union iwreq_data wrqu;
BSSListRid bss;
int rc;
BSSListElement * loop_net;
BSSListElement * tmp_net;
list_for_each_entry_safe (loop_net, tmp_net, &ai->network_list, list) {
list_move_tail (&loop_net->list, &ai->network_free_list);
memset (loop_net, 0, sizeof (loop_net->bss));
}
rc = PC4500_readrid(ai, ai->bssListFirst, &bss, ai->bssListRidLen, 0);
if((rc) || (bss.index == cpu_to_le16(0xffff))) {
goto out;
}
tmp_net = NULL;
while((!rc) && (bss.index != cpu_to_le16(0xffff))) {
if (!list_empty(&ai->network_free_list)) {
tmp_net = list_entry(ai->network_free_list.next,
BSSListElement, list);
list_del(ai->network_free_list.next);
}
if (tmp_net != NULL) {
memcpy(tmp_net, &bss, sizeof(tmp_net->bss));
list_add_tail(&tmp_net->list, &ai->network_list);
tmp_net = NULL;
}
rc = PC4500_readrid(ai, ai->bssListNext,
&bss, ai->bssListRidLen, 0);
}
out:
ai->scan_timeout = 0;
clear_bit(JOB_SCAN_RESULTS, &ai->jobs);
up(&ai->sem);
wrqu.data.length = 0;
wrqu.data.flags = 0;
wireless_send_event(ai->dev, SIOCGIWSCAN, &wrqu, NULL);
}
static int airo_thread(void *data) {
struct net_device *dev = data;
struct airo_info *ai = dev->ml_priv;
int locked;
set_freezable();
while(1) {
try_to_freeze();
if (test_bit(JOB_DIE, &ai->jobs))
break;
if (ai->jobs) {
locked = down_interruptible(&ai->sem);
} else {
wait_queue_t wait;
init_waitqueue_entry(&wait, current);
add_wait_queue(&ai->thr_wait, &wait);
for (;;) {
set_current_state(TASK_INTERRUPTIBLE);
if (ai->jobs)
break;
if (ai->expires || ai->scan_timeout) {
if (ai->scan_timeout &&
time_after_eq(jiffies,ai->scan_timeout)){
set_bit(JOB_SCAN_RESULTS, &ai->jobs);
break;
} else if (ai->expires &&
time_after_eq(jiffies,ai->expires)){
set_bit(JOB_AUTOWEP, &ai->jobs);
break;
}
if (!kthread_should_stop() &&
!freezing(current)) {
unsigned long wake_at;
if (!ai->expires || !ai->scan_timeout) {
wake_at = max(ai->expires,
ai->scan_timeout);
} else {
wake_at = min(ai->expires,
ai->scan_timeout);
}
schedule_timeout(wake_at - jiffies);
continue;
}
} else if (!kthread_should_stop() &&
!freezing(current)) {
schedule();
continue;
}
break;
}
current->state = TASK_RUNNING;
remove_wait_queue(&ai->thr_wait, &wait);
locked = 1;
}
if (locked)
continue;
if (test_bit(JOB_DIE, &ai->jobs)) {
up(&ai->sem);
break;
}
if (ai->power.event || test_bit(FLAG_FLASHING, &ai->flags)) {
up(&ai->sem);
continue;
}
if (test_bit(JOB_XMIT, &ai->jobs))
airo_end_xmit(dev);
else if (test_bit(JOB_XMIT11, &ai->jobs))
airo_end_xmit11(dev);
else if (test_bit(JOB_STATS, &ai->jobs))
airo_read_stats(dev);
else if (test_bit(JOB_WSTATS, &ai->jobs))
airo_read_wireless_stats(ai);
else if (test_bit(JOB_PROMISC, &ai->jobs))
airo_set_promisc(ai);
else if (test_bit(JOB_MIC, &ai->jobs))
micinit(ai);
else if (test_bit(JOB_EVENT, &ai->jobs))
airo_send_event(dev);
else if (test_bit(JOB_AUTOWEP, &ai->jobs))
timer_func(dev);
else if (test_bit(JOB_SCAN_RESULTS, &ai->jobs))
airo_process_scan_results(ai);
else
up(&ai->sem);
}
return 0;
}
static int header_len(__le16 ctl)
{
u16 fc = le16_to_cpu(ctl);
switch (fc & 0xc) {
case 4:
if ((fc & 0xe0) == 0xc0)
return 10;
return 16;
case 8:
if ((fc & 0x300) == 0x300)
return 30;
}
return 24;
}
static void airo_handle_cisco_mic(struct airo_info *ai)
{
if (test_bit(FLAG_MIC_CAPABLE, &ai->flags)) {
set_bit(JOB_MIC, &ai->jobs);
wake_up_interruptible(&ai->thr_wait);
}
}
static void airo_print_status(const char *devname, u16 status)
{
u8 reason = status & 0xFF;
switch (status & 0xFF00) {
case STAT_NOBEACON:
switch (status) {
case STAT_NOBEACON:
airo_print_dbg(devname, "link lost (missed beacons)");
break;
case STAT_MAXRETRIES:
case STAT_MAXARL:
airo_print_dbg(devname, "link lost (max retries)");
break;
case STAT_FORCELOSS:
airo_print_dbg(devname, "link lost (local choice)");
break;
case STAT_TSFSYNC:
airo_print_dbg(devname, "link lost (TSF sync lost)");
break;
default:
airo_print_dbg(devname, "unknow status %x\n", status);
break;
}
break;
case STAT_DEAUTH:
airo_print_dbg(devname, "deauthenticated (reason: %d)", reason);
break;
case STAT_DISASSOC:
airo_print_dbg(devname, "disassociated (reason: %d)", reason);
break;
case STAT_ASSOC_FAIL:
airo_print_dbg(devname, "association failed (reason: %d)",
reason);
break;
case STAT_AUTH_FAIL:
airo_print_dbg(devname, "authentication failed (reason: %d)",
reason);
break;
case STAT_ASSOC:
case STAT_REASSOC:
break;
default:
airo_print_dbg(devname, "unknow status %x\n", status);
break;
}
}
static void airo_handle_link(struct airo_info *ai)
{
union iwreq_data wrqu;
int scan_forceloss = 0;
u16 status;
status = le16_to_cpu(IN4500(ai, LINKSTAT));
OUT4500(ai, EVACK, EV_LINK);
if ((status == STAT_FORCELOSS) && (ai->scan_timeout > 0))
scan_forceloss = 1;
airo_print_status(ai->dev->name, status);
if ((status == STAT_ASSOC) || (status == STAT_REASSOC)) {
if (auto_wep)
ai->expires = 0;
if (ai->list_bss_task)
wake_up_process(ai->list_bss_task);
set_bit(FLAG_UPDATE_UNI, &ai->flags);
set_bit(FLAG_UPDATE_MULTI, &ai->flags);
if (down_trylock(&ai->sem) != 0) {
set_bit(JOB_EVENT, &ai->jobs);
wake_up_interruptible(&ai->thr_wait);
} else
airo_send_event(ai->dev);
} else if (!scan_forceloss) {
if (auto_wep && !ai->expires) {
ai->expires = RUN_AT(3*HZ);
wake_up_interruptible(&ai->thr_wait);
}
memset(wrqu.ap_addr.sa_data, '\0', ETH_ALEN);
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
wireless_send_event(ai->dev, SIOCGIWAP, &wrqu, NULL);
}
}
static void airo_handle_rx(struct airo_info *ai)
{
struct sk_buff *skb = NULL;
__le16 fc, v, *buffer, tmpbuf[4];
u16 len, hdrlen = 0, gap, fid;
struct rx_hdr hdr;
int success = 0;
if (test_bit(FLAG_MPI, &ai->flags)) {
if (test_bit(FLAG_802_11, &ai->flags))
mpi_receive_802_11(ai);
else
mpi_receive_802_3(ai);
OUT4500(ai, EVACK, EV_RX);
return;
}
fid = IN4500(ai, RXFID);
if (test_bit(FLAG_802_11, &ai->flags)) {
bap_setup (ai, fid, 4, BAP0);
bap_read (ai, (__le16*)&hdr, sizeof(hdr), BAP0);
if (le16_to_cpu(hdr.status) & 2)
hdr.len = 0;
if (ai->wifidev == NULL)
hdr.len = 0;
} else {
bap_setup(ai, fid, 0x36, BAP0);
bap_read(ai, &hdr.len, 2, BAP0);
}
len = le16_to_cpu(hdr.len);
if (len > AIRO_DEF_MTU) {
airo_print_err(ai->dev->name, "Bad size %d", len);
goto done;
}
if (len == 0)
goto done;
if (test_bit(FLAG_802_11, &ai->flags)) {
bap_read(ai, &fc, sizeof (fc), BAP0);
hdrlen = header_len(fc);
} else
hdrlen = ETH_ALEN * 2;
skb = dev_alloc_skb(len + hdrlen + 2 + 2);
if (!skb) {
ai->dev->stats.rx_dropped++;
goto done;
}
skb_reserve(skb, 2);
buffer = (__le16 *) skb_put(skb, len + hdrlen);
if (test_bit(FLAG_802_11, &ai->flags)) {
buffer[0] = fc;
bap_read(ai, buffer + 1, hdrlen - 2, BAP0);
if (hdrlen == 24)
bap_read(ai, tmpbuf, 6, BAP0);
bap_read(ai, &v, sizeof(v), BAP0);
gap = le16_to_cpu(v);
if (gap) {
if (gap <= 8) {
bap_read(ai, tmpbuf, gap, BAP0);
} else {
airo_print_err(ai->dev->name, "gaplen too "
"big. Problems will follow...");
}
}
bap_read(ai, buffer + hdrlen/2, len, BAP0);
} else {
MICBuffer micbuf;
bap_read(ai, buffer, ETH_ALEN * 2, BAP0);
if (ai->micstats.enabled) {
bap_read(ai, (__le16 *) &micbuf, sizeof (micbuf), BAP0);
if (ntohs(micbuf.typelen) > 0x05DC)
bap_setup(ai, fid, 0x44, BAP0);
else {
if (len <= sizeof (micbuf)) {
dev_kfree_skb_irq(skb);
goto done;
}
len -= sizeof(micbuf);
skb_trim(skb, len + hdrlen);
}
}
bap_read(ai, buffer + ETH_ALEN, len, BAP0);
if (decapsulate(ai, &micbuf, (etherHead*) buffer, len))
dev_kfree_skb_irq (skb);
else
success = 1;
}
#ifdef WIRELESS_SPY
if (success && (ai->spy_data.spy_number > 0)) {
char *sa;
struct iw_quality wstats;
if (!test_bit(FLAG_802_11, &ai->flags)) {
sa = (char *) buffer + 6;
bap_setup(ai, fid, 8, BAP0);
bap_read(ai, (__le16 *) hdr.rssi, 2, BAP0);
} else
sa = (char *) buffer + 10;
wstats.qual = hdr.rssi[0];
if (ai->rssi)
wstats.level = 0x100 - ai->rssi[hdr.rssi[1]].rssidBm;
else
wstats.level = (hdr.rssi[1] + 321) / 2;
wstats.noise = ai->wstats.qual.noise;
wstats.updated = IW_QUAL_LEVEL_UPDATED
| IW_QUAL_QUAL_UPDATED
| IW_QUAL_DBM;
wireless_spy_update(ai->dev, sa, &wstats);
}
#endif
done:
OUT4500(ai, EVACK, EV_RX);
if (success) {
if (test_bit(FLAG_802_11, &ai->flags)) {
skb_reset_mac_header(skb);
skb->pkt_type = PACKET_OTHERHOST;
skb->dev = ai->wifidev;
skb->protocol = htons(ETH_P_802_2);
} else
skb->protocol = eth_type_trans(skb, ai->dev);
skb->ip_summed = CHECKSUM_NONE;
netif_rx(skb);
}
}
static void airo_handle_tx(struct airo_info *ai, u16 status)
{
int i, len = 0, index = -1;
u16 fid;
if (test_bit(FLAG_MPI, &ai->flags)) {
unsigned long flags;
if (status & EV_TXEXC)
get_tx_error(ai, -1);
spin_lock_irqsave(&ai->aux_lock, flags);
if (!skb_queue_empty(&ai->txq)) {
spin_unlock_irqrestore(&ai->aux_lock,flags);
mpi_send_packet(ai->dev);
} else {
clear_bit(FLAG_PENDING_XMIT, &ai->flags);
spin_unlock_irqrestore(&ai->aux_lock,flags);
netif_wake_queue(ai->dev);
}
OUT4500(ai, EVACK, status & (EV_TX | EV_TXCPY | EV_TXEXC));
return;
}
fid = IN4500(ai, TXCOMPLFID);
for(i = 0; i < MAX_FIDS; i++) {
if ((ai->fids[i] & 0xffff) == fid) {
len = ai->fids[i] >> 16;
index = i;
}
}
if (index != -1) {
if (status & EV_TXEXC)
get_tx_error(ai, index);
OUT4500(ai, EVACK, status & (EV_TX | EV_TXEXC));
ai->fids[index] &= 0xffff;
if (index < MAX_FIDS / 2) {
if (!test_bit(FLAG_PENDING_XMIT, &ai->flags))
netif_wake_queue(ai->dev);
} else {
if (!test_bit(FLAG_PENDING_XMIT11, &ai->flags))
netif_wake_queue(ai->wifidev);
}
} else {
OUT4500(ai, EVACK, status & (EV_TX | EV_TXCPY | EV_TXEXC));
airo_print_err(ai->dev->name, "Unallocated FID was used to xmit");
}
}
static irqreturn_t airo_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
u16 status, savedInterrupts = 0;
struct airo_info *ai = dev->ml_priv;
int handled = 0;
if (!netif_device_present(dev))
return IRQ_NONE;
for (;;) {
status = IN4500(ai, EVSTAT);
if (!(status & STATUS_INTS) || (status == 0xffff))
break;
handled = 1;
if (status & EV_AWAKE) {
OUT4500(ai, EVACK, EV_AWAKE);
OUT4500(ai, EVACK, EV_AWAKE);
}
if (!savedInterrupts) {
savedInterrupts = IN4500(ai, EVINTEN);
OUT4500(ai, EVINTEN, 0);
}
if (status & EV_MIC) {
OUT4500(ai, EVACK, EV_MIC);
airo_handle_cisco_mic(ai);
}
if (status & EV_LINK) {
airo_handle_link(ai);
}
if (status & EV_RX)
airo_handle_rx(ai);
if (status & (EV_TX | EV_TXCPY | EV_TXEXC))
airo_handle_tx(ai, status);
if ( status & ~STATUS_INTS & ~IGNORE_INTS ) {
airo_print_warn(ai->dev->name, "Got weird status %x",
status & ~STATUS_INTS & ~IGNORE_INTS );
}
}
if (savedInterrupts)
OUT4500(ai, EVINTEN, savedInterrupts);
return IRQ_RETVAL(handled);
}
static void OUT4500( struct airo_info *ai, u16 reg, u16 val ) {
if (test_bit(FLAG_MPI,&ai->flags))
reg <<= 1;
if ( !do8bitIO )
outw( val, ai->dev->base_addr + reg );
else {
outb( val & 0xff, ai->dev->base_addr + reg );
outb( val >> 8, ai->dev->base_addr + reg + 1 );
}
}
static u16 IN4500( struct airo_info *ai, u16 reg ) {
unsigned short rc;
if (test_bit(FLAG_MPI,&ai->flags))
reg <<= 1;
if ( !do8bitIO )
rc = inw( ai->dev->base_addr + reg );
else {
rc = inb( ai->dev->base_addr + reg );
rc += ((int)inb( ai->dev->base_addr + reg + 1 )) << 8;
}
return rc;
}
static int enable_MAC(struct airo_info *ai, int lock)
{
int rc;
Cmd cmd;
Resp rsp;
if (ai->flags & FLAG_RADIO_MASK) return SUCCESS;
if (lock && down_interruptible(&ai->sem))
return -ERESTARTSYS;
if (!test_bit(FLAG_ENABLED, &ai->flags)) {
memset(&cmd, 0, sizeof(cmd));
cmd.cmd = MAC_ENABLE;
rc = issuecommand(ai, &cmd, &rsp);
if (rc == SUCCESS)
set_bit(FLAG_ENABLED, &ai->flags);
} else
rc = SUCCESS;
if (lock)
up(&ai->sem);
if (rc)
airo_print_err(ai->dev->name, "Cannot enable MAC");
else if ((rsp.status & 0xFF00) != 0) {
airo_print_err(ai->dev->name, "Bad MAC enable reason=%x, "
"rid=%x, offset=%d", rsp.rsp0, rsp.rsp1, rsp.rsp2);
rc = ERROR;
}
return rc;
}
static void disable_MAC( struct airo_info *ai, int lock ) {
Cmd cmd;
Resp rsp;
if (lock && down_interruptible(&ai->sem))
return;
if (test_bit(FLAG_ENABLED, &ai->flags)) {
memset(&cmd, 0, sizeof(cmd));
cmd.cmd = MAC_DISABLE;
issuecommand(ai, &cmd, &rsp);
clear_bit(FLAG_ENABLED, &ai->flags);
}
if (lock)
up(&ai->sem);
}
static void enable_interrupts( struct airo_info *ai ) {
OUT4500( ai, EVINTEN, STATUS_INTS );
}
static void disable_interrupts( struct airo_info *ai ) {
OUT4500( ai, EVINTEN, 0 );
}
static void mpi_receive_802_3(struct airo_info *ai)
{
RxFid rxd;
int len = 0;
struct sk_buff *skb;
char *buffer;
int off = 0;
MICBuffer micbuf;
memcpy_fromio(&rxd, ai->rxfids[0].card_ram_off, sizeof(rxd));
if (rxd.rdy && rxd.valid == 0) {
len = rxd.len + 12;
if (len < 12 || len > 2048)
goto badrx;
skb = dev_alloc_skb(len);
if (!skb) {
ai->dev->stats.rx_dropped++;
goto badrx;
}
buffer = skb_put(skb,len);
memcpy(buffer, ai->rxfids[0].virtual_host_addr, ETH_ALEN * 2);
if (ai->micstats.enabled) {
memcpy(&micbuf,
ai->rxfids[0].virtual_host_addr + ETH_ALEN * 2,
sizeof(micbuf));
if (ntohs(micbuf.typelen) <= 0x05DC) {
if (len <= sizeof(micbuf) + ETH_ALEN * 2)
goto badmic;
off = sizeof(micbuf);
skb_trim (skb, len - off);
}
}
memcpy(buffer + ETH_ALEN * 2,
ai->rxfids[0].virtual_host_addr + ETH_ALEN * 2 + off,
len - ETH_ALEN * 2 - off);
if (decapsulate (ai, &micbuf, (etherHead*)buffer, len - off - ETH_ALEN * 2)) {
badmic:
dev_kfree_skb_irq (skb);
goto badrx;
}
#ifdef WIRELESS_SPY
if (ai->spy_data.spy_number > 0) {
char *sa;
struct iw_quality wstats;
sa = buffer + ETH_ALEN;
wstats.qual = 0;
wstats.level = 0;
wstats.updated = 0;
wireless_spy_update(ai->dev, sa, &wstats);
}
#endif
skb->ip_summed = CHECKSUM_NONE;
skb->protocol = eth_type_trans(skb, ai->dev);
netif_rx(skb);
}
badrx:
if (rxd.valid == 0) {
rxd.valid = 1;
rxd.rdy = 0;
rxd.len = PKTSIZE;
memcpy_toio(ai->rxfids[0].card_ram_off, &rxd, sizeof(rxd));
}
}
static void mpi_receive_802_11(struct airo_info *ai)
{
RxFid rxd;
struct sk_buff *skb = NULL;
u16 len, hdrlen = 0;
__le16 fc;
struct rx_hdr hdr;
u16 gap;
u16 *buffer;
char *ptr = ai->rxfids[0].virtual_host_addr + 4;
memcpy_fromio(&rxd, ai->rxfids[0].card_ram_off, sizeof(rxd));
memcpy ((char *)&hdr, ptr, sizeof(hdr));
ptr += sizeof(hdr);
if (le16_to_cpu(hdr.status) & 2)
hdr.len = 0;
if (ai->wifidev == NULL)
hdr.len = 0;
len = le16_to_cpu(hdr.len);
if (len > AIRO_DEF_MTU) {
airo_print_err(ai->dev->name, "Bad size %d", len);
goto badrx;
}
if (len == 0)
goto badrx;
fc = get_unaligned((__le16 *)ptr);
hdrlen = header_len(fc);
skb = dev_alloc_skb( len + hdrlen + 2 );
if ( !skb ) {
ai->dev->stats.rx_dropped++;
goto badrx;
}
buffer = (u16*)skb_put (skb, len + hdrlen);
memcpy ((char *)buffer, ptr, hdrlen);
ptr += hdrlen;
if (hdrlen == 24)
ptr += 6;
gap = get_unaligned_le16(ptr);
ptr += sizeof(__le16);
if (gap) {
if (gap <= 8)
ptr += gap;
else
airo_print_err(ai->dev->name,
"gaplen too big. Problems will follow...");
}
memcpy ((char *)buffer + hdrlen, ptr, len);
ptr += len;
#ifdef IW_WIRELESS_SPY
if (ai->spy_data.spy_number > 0) {
char *sa;
struct iw_quality wstats;
sa = (char*)buffer + 10;
wstats.qual = hdr.rssi[0];
if (ai->rssi)
wstats.level = 0x100 - ai->rssi[hdr.rssi[1]].rssidBm;
else
wstats.level = (hdr.rssi[1] + 321) / 2;
wstats.noise = ai->wstats.qual.noise;
wstats.updated = IW_QUAL_QUAL_UPDATED
| IW_QUAL_LEVEL_UPDATED
| IW_QUAL_DBM;
wireless_spy_update(ai->dev, sa, &wstats);
}
#endif
skb_reset_mac_header(skb);
skb->pkt_type = PACKET_OTHERHOST;
skb->dev = ai->wifidev;
skb->protocol = htons(ETH_P_802_2);
skb->ip_summed = CHECKSUM_NONE;
netif_rx( skb );
badrx:
if (rxd.valid == 0) {
rxd.valid = 1;
rxd.rdy = 0;
rxd.len = PKTSIZE;
memcpy_toio(ai->rxfids[0].card_ram_off, &rxd, sizeof(rxd));
}
}
static u16 setup_card(struct airo_info *ai, u8 *mac, int lock)
{
Cmd cmd;
Resp rsp;
int status;
SsidRid mySsid;
__le16 lastindex;
WepKeyRid wkr;
int rc;
memset( &mySsid, 0, sizeof( mySsid ) );
kfree (ai->flash);
ai->flash = NULL;
cmd.cmd = NOP;
cmd.parm0 = cmd.parm1 = cmd.parm2 = 0;
if (lock && down_interruptible(&ai->sem))
return ERROR;
if ( issuecommand( ai, &cmd, &rsp ) != SUCCESS ) {
if (lock)
up(&ai->sem);
return ERROR;
}
disable_MAC( ai, 0);
if (!test_bit(FLAG_MPI,&ai->flags)) {
cmd.cmd = CMD_ENABLEAUX;
if (issuecommand(ai, &cmd, &rsp) != SUCCESS) {
if (lock)
up(&ai->sem);
airo_print_err(ai->dev->name, "Error checking for AUX port");
return ERROR;
}
if (!aux_bap || rsp.status & 0xff00) {
ai->bap_read = fast_bap_read;
airo_print_dbg(ai->dev->name, "Doing fast bap_reads");
} else {
ai->bap_read = aux_bap_read;
airo_print_dbg(ai->dev->name, "Doing AUX bap_reads");
}
}
if (lock)
up(&ai->sem);
if (ai->config.len == 0) {
int i;
tdsRssiRid rssi_rid;
CapabilityRid cap_rid;
kfree(ai->APList);
ai->APList = NULL;
kfree(ai->SSID);
ai->SSID = NULL;
status = readConfigRid(ai, lock);
if ( status != SUCCESS ) return ERROR;
status = readCapabilityRid(ai, &cap_rid, lock);
if ( status != SUCCESS ) return ERROR;
status = PC4500_readrid(ai,RID_RSSI,&rssi_rid,sizeof(rssi_rid),lock);
if ( status == SUCCESS ) {
if (ai->rssi || (ai->rssi = kmalloc(512, GFP_KERNEL)) != NULL)
memcpy(ai->rssi, (u8*)&rssi_rid + 2, 512);
}
else {
kfree(ai->rssi);
ai->rssi = NULL;
if (cap_rid.softCap & cpu_to_le16(8))
ai->config.rmode |= RXMODE_NORMALIZED_RSSI;
else
airo_print_warn(ai->dev->name, "unknown received signal "
"level scale");
}
ai->config.opmode = adhoc ? MODE_STA_IBSS : MODE_STA_ESS;
ai->config.authType = AUTH_OPEN;
ai->config.modulation = MOD_CCK;
if (le16_to_cpu(cap_rid.len) >= sizeof(cap_rid) &&
(cap_rid.extSoftCap & cpu_to_le16(1)) &&
micsetup(ai) == SUCCESS) {
ai->config.opmode |= MODE_MIC;
set_bit(FLAG_MIC_CAPABLE, &ai->flags);
}
for( i = 0; i < ETH_ALEN; i++ ) {
mac[i] = ai->config.macAddr[i];
}
if ( rates[0] ) {
memset(ai->config.rates,0,sizeof(ai->config.rates));
for( i = 0; i < 8 && rates[i]; i++ ) {
ai->config.rates[i] = rates[i];
}
}
set_bit (FLAG_COMMIT, &ai->flags);
}
if ( ssids[0] ) {
int i;
for( i = 0; i < 3 && ssids[i]; i++ ) {
size_t len = strlen(ssids[i]);
if (len > 32)
len = 32;
mySsid.ssids[i].len = cpu_to_le16(len);
memcpy(mySsid.ssids[i].ssid, ssids[i], len);
}
mySsid.len = cpu_to_le16(sizeof(mySsid));
}
status = writeConfigRid(ai, lock);
if ( status != SUCCESS ) return ERROR;
if ( ssids[0] ) {
status = writeSsidRid(ai, &mySsid, lock);
if ( status != SUCCESS ) return ERROR;
}
status = enable_MAC(ai, lock);
if (status != SUCCESS)
return ERROR;
rc = readWepKeyRid(ai, &wkr, 1, lock);
if (rc == SUCCESS) do {
lastindex = wkr.kindex;
if (wkr.kindex == cpu_to_le16(0xffff)) {
ai->defindex = wkr.mac[0];
}
rc = readWepKeyRid(ai, &wkr, 0, lock);
} while(lastindex != wkr.kindex);
try_auto_wep(ai);
return SUCCESS;
}
static u16 issuecommand(struct airo_info *ai, Cmd *pCmd, Resp *pRsp) {
int max_tries = 600000;
if (IN4500(ai, EVSTAT) & EV_CMD)
OUT4500(ai, EVACK, EV_CMD);
OUT4500(ai, PARAM0, pCmd->parm0);
OUT4500(ai, PARAM1, pCmd->parm1);
OUT4500(ai, PARAM2, pCmd->parm2);
OUT4500(ai, COMMAND, pCmd->cmd);
while (max_tries-- && (IN4500(ai, EVSTAT) & EV_CMD) == 0) {
if ((IN4500(ai, COMMAND)) == pCmd->cmd)
OUT4500(ai, COMMAND, pCmd->cmd);
if (!in_atomic() && (max_tries & 255) == 0)
schedule();
}
if ( max_tries == -1 ) {
airo_print_err(ai->dev->name,
"Max tries exceeded when issuing command");
if (IN4500(ai, COMMAND) & COMMAND_BUSY)
OUT4500(ai, EVACK, EV_CLEARCOMMANDBUSY);
return ERROR;
}
pRsp->status = IN4500(ai, STATUS);
pRsp->rsp0 = IN4500(ai, RESP0);
pRsp->rsp1 = IN4500(ai, RESP1);
pRsp->rsp2 = IN4500(ai, RESP2);
if ((pRsp->status & 0xff00)!=0 && pCmd->cmd != CMD_SOFTRESET)
airo_print_err(ai->dev->name,
"cmd:%x status:%x rsp0:%x rsp1:%x rsp2:%x",
pCmd->cmd, pRsp->status, pRsp->rsp0, pRsp->rsp1,
pRsp->rsp2);
if (IN4500(ai, COMMAND) & COMMAND_BUSY) {
OUT4500(ai, EVACK, EV_CLEARCOMMANDBUSY);
}
OUT4500(ai, EVACK, EV_CMD);
return SUCCESS;
}
static int bap_setup(struct airo_info *ai, u16 rid, u16 offset, int whichbap )
{
int timeout = 50;
int max_tries = 3;
OUT4500(ai, SELECT0+whichbap, rid);
OUT4500(ai, OFFSET0+whichbap, offset);
while (1) {
int status = IN4500(ai, OFFSET0+whichbap);
if (status & BAP_BUSY) {
if (timeout--) {
continue;
}
} else if ( status & BAP_ERR ) {
airo_print_err(ai->dev->name, "BAP error %x %d",
status, whichbap );
return ERROR;
} else if (status & BAP_DONE) {
return SUCCESS;
}
if ( !(max_tries--) ) {
airo_print_err(ai->dev->name,
"BAP setup error too many retries\n");
return ERROR;
}
OUT4500(ai, SELECT0+whichbap, rid);
OUT4500(ai, OFFSET0+whichbap, offset);
timeout = 50;
}
}
static u16 aux_setup(struct airo_info *ai, u16 page,
u16 offset, u16 *len)
{
u16 next;
OUT4500(ai, AUXPAGE, page);
OUT4500(ai, AUXOFF, 0);
next = IN4500(ai, AUXDATA);
*len = IN4500(ai, AUXDATA)&0xff;
if (offset != 4) OUT4500(ai, AUXOFF, offset);
return next;
}
static int aux_bap_read(struct airo_info *ai, __le16 *pu16Dst,
int bytelen, int whichbap)
{
u16 len;
u16 page;
u16 offset;
u16 next;
int words;
int i;
unsigned long flags;
spin_lock_irqsave(&ai->aux_lock, flags);
page = IN4500(ai, SWS0+whichbap);
offset = IN4500(ai, SWS2+whichbap);
next = aux_setup(ai, page, offset, &len);
words = (bytelen+1)>>1;
for (i=0; i<words;) {
int count;
count = (len>>1) < (words-i) ? (len>>1) : (words-i);
if ( !do8bitIO )
insw( ai->dev->base_addr+DATA0+whichbap,
pu16Dst+i,count );
else
insb( ai->dev->base_addr+DATA0+whichbap,
pu16Dst+i, count << 1 );
i += count;
if (i<words) {
next = aux_setup(ai, next, 4, &len);
}
}
spin_unlock_irqrestore(&ai->aux_lock, flags);
return SUCCESS;
}
static int fast_bap_read(struct airo_info *ai, __le16 *pu16Dst,
int bytelen, int whichbap)
{
bytelen = (bytelen + 1) & (~1);
if ( !do8bitIO )
insw( ai->dev->base_addr+DATA0+whichbap, pu16Dst, bytelen>>1 );
else
insb( ai->dev->base_addr+DATA0+whichbap, pu16Dst, bytelen );
return SUCCESS;
}
static int bap_write(struct airo_info *ai, const __le16 *pu16Src,
int bytelen, int whichbap)
{
bytelen = (bytelen + 1) & (~1);
if ( !do8bitIO )
outsw( ai->dev->base_addr+DATA0+whichbap,
pu16Src, bytelen>>1 );
else
outsb( ai->dev->base_addr+DATA0+whichbap, pu16Src, bytelen );
return SUCCESS;
}
static int PC4500_accessrid(struct airo_info *ai, u16 rid, u16 accmd)
{
Cmd cmd;
Resp rsp;
u16 status;
memset(&cmd, 0, sizeof(cmd));
cmd.cmd = accmd;
cmd.parm0 = rid;
status = issuecommand(ai, &cmd, &rsp);
if (status != 0) return status;
if ( (rsp.status & 0x7F00) != 0) {
return (accmd << 8) + (rsp.rsp0 & 0xFF);
}
return 0;
}
static int PC4500_readrid(struct airo_info *ai, u16 rid, void *pBuf, int len, int lock)
{
u16 status;
int rc = SUCCESS;
if (lock) {
if (down_interruptible(&ai->sem))
return ERROR;
}
if (test_bit(FLAG_MPI,&ai->flags)) {
Cmd cmd;
Resp rsp;
memset(&cmd, 0, sizeof(cmd));
memset(&rsp, 0, sizeof(rsp));
ai->config_desc.rid_desc.valid = 1;
ai->config_desc.rid_desc.len = RIDSIZE;
ai->config_desc.rid_desc.rid = 0;
ai->config_desc.rid_desc.host_addr = ai->ridbus;
cmd.cmd = CMD_ACCESS;
cmd.parm0 = rid;
memcpy_toio(ai->config_desc.card_ram_off,
&ai->config_desc.rid_desc, sizeof(Rid));
rc = issuecommand(ai, &cmd, &rsp);
if (rsp.status & 0x7f00)
rc = rsp.rsp0;
if (!rc)
memcpy(pBuf, ai->config_desc.virtual_host_addr, len);
goto done;
} else {
if ((status = PC4500_accessrid(ai, rid, CMD_ACCESS))!=SUCCESS) {
rc = status;
goto done;
}
if (bap_setup(ai, rid, 0, BAP1) != SUCCESS) {
rc = ERROR;
goto done;
}
bap_read(ai, pBuf, 2, BAP1);
len = min(len, (int)le16_to_cpu(*(__le16*)pBuf)) - 2;
if ( len <= 2 ) {
airo_print_err(ai->dev->name,
"Rid %x has a length of %d which is too short",
(int)rid, (int)len );
rc = ERROR;
goto done;
}
rc = bap_read(ai, ((__le16*)pBuf)+1, len, BAP1);
}
done:
if (lock)
up(&ai->sem);
return rc;
}
static int PC4500_writerid(struct airo_info *ai, u16 rid,
const void *pBuf, int len, int lock)
{
u16 status;
int rc = SUCCESS;
*(__le16*)pBuf = cpu_to_le16((u16)len);
if (lock) {
if (down_interruptible(&ai->sem))
return ERROR;
}
if (test_bit(FLAG_MPI,&ai->flags)) {
Cmd cmd;
Resp rsp;
if (test_bit(FLAG_ENABLED, &ai->flags) && (RID_WEP_TEMP != rid))
airo_print_err(ai->dev->name,
"%s: MAC should be disabled (rid=%04x)",
__func__, rid);
memset(&cmd, 0, sizeof(cmd));
memset(&rsp, 0, sizeof(rsp));
ai->config_desc.rid_desc.valid = 1;
ai->config_desc.rid_desc.len = *((u16 *)pBuf);
ai->config_desc.rid_desc.rid = 0;
cmd.cmd = CMD_WRITERID;
cmd.parm0 = rid;
memcpy_toio(ai->config_desc.card_ram_off,
&ai->config_desc.rid_desc, sizeof(Rid));
if (len < 4 || len > 2047) {
airo_print_err(ai->dev->name, "%s: len=%d", __func__, len);
rc = -1;
} else {
memcpy(ai->config_desc.virtual_host_addr,
pBuf, len);
rc = issuecommand(ai, &cmd, &rsp);
if ((rc & 0xff00) != 0) {
airo_print_err(ai->dev->name, "%s: Write rid Error %d",
__func__, rc);
airo_print_err(ai->dev->name, "%s: Cmd=%04x",
__func__, cmd.cmd);
}
if ((rsp.status & 0x7f00))
rc = rsp.rsp0;
}
} else {
if ( (status = PC4500_accessrid(ai, rid, CMD_ACCESS)) != 0) {
rc = status;
goto done;
}
if (bap_setup(ai, rid, 0, BAP1) != SUCCESS) {
rc = ERROR;
goto done;
}
bap_write(ai, pBuf, len, BAP1);
rc = PC4500_accessrid(ai, rid, 0x100|CMD_ACCESS);
}
done:
if (lock)
up(&ai->sem);
return rc;
}
static u16 transmit_allocate(struct airo_info *ai, int lenPayload, int raw)
{
unsigned int loop = 3000;
Cmd cmd;
Resp rsp;
u16 txFid;
__le16 txControl;
cmd.cmd = CMD_ALLOCATETX;
cmd.parm0 = lenPayload;
if (down_interruptible(&ai->sem))
return ERROR;
if (issuecommand(ai, &cmd, &rsp) != SUCCESS) {
txFid = ERROR;
goto done;
}
if ( (rsp.status & 0xFF00) != 0) {
txFid = ERROR;
goto done;
}
while (((IN4500(ai, EVSTAT) & EV_ALLOC) == 0) && --loop);
if (!loop) {
txFid = ERROR;
goto done;
}
txFid = IN4500(ai, TXALLOCFID);
OUT4500(ai, EVACK, EV_ALLOC);
if (raw)
txControl = cpu_to_le16(TXCTL_TXOK | TXCTL_TXEX | TXCTL_802_11
| TXCTL_ETHERNET | TXCTL_NORELEASE);
else
txControl = cpu_to_le16(TXCTL_TXOK | TXCTL_TXEX | TXCTL_802_3
| TXCTL_ETHERNET | TXCTL_NORELEASE);
if (bap_setup(ai, txFid, 0x0008, BAP1) != SUCCESS)
txFid = ERROR;
else
bap_write(ai, &txControl, sizeof(txControl), BAP1);
done:
up(&ai->sem);
return txFid;
}
static int transmit_802_3_packet(struct airo_info *ai, int len, char *pPacket)
{
__le16 payloadLen;
Cmd cmd;
Resp rsp;
int miclen = 0;
u16 txFid = len;
MICBuffer pMic;
len >>= 16;
if (len <= ETH_ALEN * 2) {
airo_print_warn(ai->dev->name, "Short packet %d", len);
return ERROR;
}
len -= ETH_ALEN * 2;
if (test_bit(FLAG_MIC_CAPABLE, &ai->flags) && ai->micstats.enabled &&
(ntohs(((__be16 *)pPacket)[6]) != 0x888E)) {
if (encapsulate(ai,(etherHead *)pPacket,&pMic,len) != SUCCESS)
return ERROR;
miclen = sizeof(pMic);
}
if (bap_setup(ai, txFid, 0x0036, BAP1) != SUCCESS) return ERROR;
payloadLen = cpu_to_le16(len + miclen);
bap_write(ai, &payloadLen, sizeof(payloadLen),BAP1);
bap_write(ai, (__le16*)pPacket, sizeof(etherHead), BAP1);
if (miclen)
bap_write(ai, (__le16*)&pMic, miclen, BAP1);
bap_write(ai, (__le16*)(pPacket + sizeof(etherHead)), len, BAP1);
memset( &cmd, 0, sizeof( cmd ) );
cmd.cmd = CMD_TRANSMIT;
cmd.parm0 = txFid;
if (issuecommand(ai, &cmd, &rsp) != SUCCESS) return ERROR;
if ( (rsp.status & 0xFF00) != 0) return ERROR;
return SUCCESS;
}
static int transmit_802_11_packet(struct airo_info *ai, int len, char *pPacket)
{
__le16 fc, payloadLen;
Cmd cmd;
Resp rsp;
int hdrlen;
static u8 tail[(30-10) + 2 + 6] = {[30-10] = 6};
u16 txFid = len;
len >>= 16;
fc = *(__le16*)pPacket;
hdrlen = header_len(fc);
if (len < hdrlen) {
airo_print_warn(ai->dev->name, "Short packet %d", len);
return ERROR;
}
if (bap_setup(ai, txFid, 6, BAP1) != SUCCESS) return ERROR;
payloadLen = cpu_to_le16(len-hdrlen);
bap_write(ai, &payloadLen, sizeof(payloadLen),BAP1);
if (bap_setup(ai, txFid, 0x0014, BAP1) != SUCCESS) return ERROR;
bap_write(ai, (__le16 *)pPacket, hdrlen, BAP1);
bap_write(ai, (__le16 *)(tail + (hdrlen - 10)), 38 - hdrlen, BAP1);
bap_write(ai, (__le16 *)(pPacket + hdrlen), len - hdrlen, BAP1);
memset( &cmd, 0, sizeof( cmd ) );
cmd.cmd = CMD_TRANSMIT;
cmd.parm0 = txFid;
if (issuecommand(ai, &cmd, &rsp) != SUCCESS) return ERROR;
if ( (rsp.status & 0xFF00) != 0) return ERROR;
return SUCCESS;
}
static int setup_proc_entry( struct net_device *dev,
struct airo_info *apriv ) {
struct proc_dir_entry *entry;
strcpy(apriv->proc_name,dev->name);
apriv->proc_entry = proc_mkdir_mode(apriv->proc_name, airo_perm,
airo_entry);
if (!apriv->proc_entry)
goto fail;
apriv->proc_entry->uid = proc_kuid;
apriv->proc_entry->gid = proc_kgid;
entry = proc_create_data("StatsDelta", S_IRUGO & proc_perm,
apriv->proc_entry, &proc_statsdelta_ops, dev);
if (!entry)
goto fail_stats_delta;
entry->uid = proc_kuid;
entry->gid = proc_kgid;
entry = proc_create_data("Stats", S_IRUGO & proc_perm,
apriv->proc_entry, &proc_stats_ops, dev);
if (!entry)
goto fail_stats;
entry->uid = proc_kuid;
entry->gid = proc_kgid;
entry = proc_create_data("Status", S_IRUGO & proc_perm,
apriv->proc_entry, &proc_status_ops, dev);
if (!entry)
goto fail_status;
entry->uid = proc_kuid;
entry->gid = proc_kgid;
entry = proc_create_data("Config", proc_perm,
apriv->proc_entry, &proc_config_ops, dev);
if (!entry)
goto fail_config;
entry->uid = proc_kuid;
entry->gid = proc_kgid;
entry = proc_create_data("SSID", proc_perm,
apriv->proc_entry, &proc_SSID_ops, dev);
if (!entry)
goto fail_ssid;
entry->uid = proc_kuid;
entry->gid = proc_kgid;
entry = proc_create_data("APList", proc_perm,
apriv->proc_entry, &proc_APList_ops, dev);
if (!entry)
goto fail_aplist;
entry->uid = proc_kuid;
entry->gid = proc_kgid;
entry = proc_create_data("BSSList", proc_perm,
apriv->proc_entry, &proc_BSSList_ops, dev);
if (!entry)
goto fail_bsslist;
entry->uid = proc_kuid;
entry->gid = proc_kgid;
entry = proc_create_data("WepKey", proc_perm,
apriv->proc_entry, &proc_wepkey_ops, dev);
if (!entry)
goto fail_wepkey;
entry->uid = proc_kuid;
entry->gid = proc_kgid;
return 0;
fail_wepkey:
remove_proc_entry("BSSList", apriv->proc_entry);
fail_bsslist:
remove_proc_entry("APList", apriv->proc_entry);
fail_aplist:
remove_proc_entry("SSID", apriv->proc_entry);
fail_ssid:
remove_proc_entry("Config", apriv->proc_entry);
fail_config:
remove_proc_entry("Status", apriv->proc_entry);
fail_status:
remove_proc_entry("Stats", apriv->proc_entry);
fail_stats:
remove_proc_entry("StatsDelta", apriv->proc_entry);
fail_stats_delta:
remove_proc_entry(apriv->proc_name, airo_entry);
fail:
return -ENOMEM;
}
static int takedown_proc_entry( struct net_device *dev,
struct airo_info *apriv ) {
if ( !apriv->proc_entry->namelen ) return 0;
remove_proc_entry("Stats",apriv->proc_entry);
remove_proc_entry("StatsDelta",apriv->proc_entry);
remove_proc_entry("Status",apriv->proc_entry);
remove_proc_entry("Config",apriv->proc_entry);
remove_proc_entry("SSID",apriv->proc_entry);
remove_proc_entry("APList",apriv->proc_entry);
remove_proc_entry("BSSList",apriv->proc_entry);
remove_proc_entry("WepKey",apriv->proc_entry);
remove_proc_entry(apriv->proc_name,airo_entry);
return 0;
}
static ssize_t proc_read( struct file *file,
char __user *buffer,
size_t len,
loff_t *offset )
{
struct proc_data *priv = file->private_data;
if (!priv->rbuffer)
return -EINVAL;
return simple_read_from_buffer(buffer, len, offset, priv->rbuffer,
priv->readlen);
}
static ssize_t proc_write( struct file *file,
const char __user *buffer,
size_t len,
loff_t *offset )
{
ssize_t ret;
struct proc_data *priv = file->private_data;
if (!priv->wbuffer)
return -EINVAL;
ret = simple_write_to_buffer(priv->wbuffer, priv->maxwritelen, offset,
buffer, len);
if (ret > 0)
priv->writelen = max_t(int, priv->writelen, *offset);
return ret;
}
static int proc_status_open(struct inode *inode, struct file *file)
{
struct proc_data *data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *apriv = dev->ml_priv;
CapabilityRid cap_rid;
StatusRid status_rid;
u16 mode;
int i;
if ((file->private_data = kzalloc(sizeof(struct proc_data ), GFP_KERNEL)) == NULL)
return -ENOMEM;
data = file->private_data;
if ((data->rbuffer = kmalloc( 2048, GFP_KERNEL )) == NULL) {
kfree (file->private_data);
return -ENOMEM;
}
readStatusRid(apriv, &status_rid, 1);
readCapabilityRid(apriv, &cap_rid, 1);
mode = le16_to_cpu(status_rid.mode);
i = sprintf(data->rbuffer, "Status: %s%s%s%s%s%s%s%s%s\n",
mode & 1 ? "CFG ": "",
mode & 2 ? "ACT ": "",
mode & 0x10 ? "SYN ": "",
mode & 0x20 ? "LNK ": "",
mode & 0x40 ? "LEAP ": "",
mode & 0x80 ? "PRIV ": "",
mode & 0x100 ? "KEY ": "",
mode & 0x200 ? "WEP ": "",
mode & 0x8000 ? "ERR ": "");
sprintf( data->rbuffer+i, "Mode: %x\n"
"Signal Strength: %d\n"
"Signal Quality: %d\n"
"SSID: %-.*s\n"
"AP: %-.16s\n"
"Freq: %d\n"
"BitRate: %dmbs\n"
"Driver Version: %s\n"
"Device: %s\nManufacturer: %s\nFirmware Version: %s\n"
"Radio type: %x\nCountry: %x\nHardware Version: %x\n"
"Software Version: %x\nSoftware Subversion: %x\n"
"Boot block version: %x\n",
le16_to_cpu(status_rid.mode),
le16_to_cpu(status_rid.normalizedSignalStrength),
le16_to_cpu(status_rid.signalQuality),
le16_to_cpu(status_rid.SSIDlen),
status_rid.SSID,
status_rid.apName,
le16_to_cpu(status_rid.channel),
le16_to_cpu(status_rid.currentXmitRate) / 2,
version,
cap_rid.prodName,
cap_rid.manName,
cap_rid.prodVer,
le16_to_cpu(cap_rid.radioType),
le16_to_cpu(cap_rid.country),
le16_to_cpu(cap_rid.hardVer),
le16_to_cpu(cap_rid.softVer),
le16_to_cpu(cap_rid.softSubVer),
le16_to_cpu(cap_rid.bootBlockVer));
data->readlen = strlen( data->rbuffer );
return 0;
}
static int proc_statsdelta_open( struct inode *inode,
struct file *file ) {
if (file->f_mode&FMODE_WRITE) {
return proc_stats_rid_open(inode, file, RID_STATSDELTACLEAR);
}
return proc_stats_rid_open(inode, file, RID_STATSDELTA);
}
static int proc_stats_open( struct inode *inode, struct file *file ) {
return proc_stats_rid_open(inode, file, RID_STATS);
}
static int proc_stats_rid_open( struct inode *inode,
struct file *file,
u16 rid )
{
struct proc_data *data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *apriv = dev->ml_priv;
StatsRid stats;
int i, j;
__le32 *vals = stats.vals;
int len;
if ((file->private_data = kzalloc(sizeof(struct proc_data ), GFP_KERNEL)) == NULL)
return -ENOMEM;
data = file->private_data;
if ((data->rbuffer = kmalloc( 4096, GFP_KERNEL )) == NULL) {
kfree (file->private_data);
return -ENOMEM;
}
readStatsRid(apriv, &stats, rid, 1);
len = le16_to_cpu(stats.len);
j = 0;
for(i=0; statsLabels[i]!=(char *)-1 && i*4<len; i++) {
if (!statsLabels[i]) continue;
if (j+strlen(statsLabels[i])+16>4096) {
airo_print_warn(apriv->dev->name,
"Potentially disastrous buffer overflow averted!");
break;
}
j+=sprintf(data->rbuffer+j, "%s: %u\n", statsLabels[i],
le32_to_cpu(vals[i]));
}
if (i*4 >= len) {
airo_print_warn(apriv->dev->name, "Got a short rid");
}
data->readlen = j;
return 0;
}
static int get_dec_u16( char *buffer, int *start, int limit ) {
u16 value;
int valid = 0;
for (value = 0; *start < limit && buffer[*start] >= '0' &&
buffer[*start] <= '9'; (*start)++) {
valid = 1;
value *= 10;
value += buffer[*start] - '0';
}
if ( !valid ) return -1;
return value;
}
static inline int sniffing_mode(struct airo_info *ai)
{
return (le16_to_cpu(ai->config.rmode) & le16_to_cpu(RXMODE_MASK)) >=
le16_to_cpu(RXMODE_RFMON);
}
static void proc_config_on_close(struct inode *inode, struct file *file)
{
struct proc_data *data = file->private_data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *ai = dev->ml_priv;
char *line;
if ( !data->writelen ) return;
readConfigRid(ai, 1);
set_bit (FLAG_COMMIT, &ai->flags);
line = data->wbuffer;
while( line[0] ) {
if ( !strncmp( line, "Mode: ", 6 ) ) {
line += 6;
if (sniffing_mode(ai))
set_bit (FLAG_RESET, &ai->flags);
ai->config.rmode &= ~RXMODE_FULL_MASK;
clear_bit (FLAG_802_11, &ai->flags);
ai->config.opmode &= ~MODE_CFG_MASK;
ai->config.scanMode = SCANMODE_ACTIVE;
if ( line[0] == 'a' ) {
ai->config.opmode |= MODE_STA_IBSS;
} else {
ai->config.opmode |= MODE_STA_ESS;
if ( line[0] == 'r' ) {
ai->config.rmode |= RXMODE_RFMON | RXMODE_DISABLE_802_3_HEADER;
ai->config.scanMode = SCANMODE_PASSIVE;
set_bit (FLAG_802_11, &ai->flags);
} else if ( line[0] == 'y' ) {
ai->config.rmode |= RXMODE_RFMON_ANYBSS | RXMODE_DISABLE_802_3_HEADER;
ai->config.scanMode = SCANMODE_PASSIVE;
set_bit (FLAG_802_11, &ai->flags);
} else if ( line[0] == 'l' )
ai->config.rmode |= RXMODE_LANMON;
}
set_bit (FLAG_COMMIT, &ai->flags);
}
else if (!strncmp(line,"Radio: ", 7)) {
line += 7;
if (!strncmp(line,"off",3)) {
set_bit (FLAG_RADIO_OFF, &ai->flags);
} else {
clear_bit (FLAG_RADIO_OFF, &ai->flags);
}
}
else if ( !strncmp( line, "NodeName: ", 10 ) ) {
int j;
line += 10;
memset( ai->config.nodeName, 0, 16 );
for( j = 0; j < 16 && line[j] != '\n'; j++ ) {
ai->config.nodeName[j] = line[j];
}
set_bit (FLAG_COMMIT, &ai->flags);
}
else if ( !strncmp( line, "PowerMode: ", 11 ) ) {
line += 11;
if ( !strncmp( line, "PSPCAM", 6 ) ) {
ai->config.powerSaveMode = POWERSAVE_PSPCAM;
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "PSP", 3 ) ) {
ai->config.powerSaveMode = POWERSAVE_PSP;
set_bit (FLAG_COMMIT, &ai->flags);
} else {
ai->config.powerSaveMode = POWERSAVE_CAM;
set_bit (FLAG_COMMIT, &ai->flags);
}
} else if ( !strncmp( line, "DataRates: ", 11 ) ) {
int v, i = 0, k = 0;
line += 11;
while((v = get_dec_u16(line, &i, 3))!=-1) {
ai->config.rates[k++] = (u8)v;
line += i + 1;
i = 0;
}
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "Channel: ", 9 ) ) {
int v, i = 0;
line += 9;
v = get_dec_u16(line, &i, i+3);
if ( v != -1 ) {
ai->config.channelSet = cpu_to_le16(v);
set_bit (FLAG_COMMIT, &ai->flags);
}
} else if ( !strncmp( line, "XmitPower: ", 11 ) ) {
int v, i = 0;
line += 11;
v = get_dec_u16(line, &i, i+3);
if ( v != -1 ) {
ai->config.txPower = cpu_to_le16(v);
set_bit (FLAG_COMMIT, &ai->flags);
}
} else if ( !strncmp( line, "WEP: ", 5 ) ) {
line += 5;
switch( line[0] ) {
case 's':
ai->config.authType = AUTH_SHAREDKEY;
break;
case 'e':
ai->config.authType = AUTH_ENCRYPT;
break;
default:
ai->config.authType = AUTH_OPEN;
break;
}
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "LongRetryLimit: ", 16 ) ) {
int v, i = 0;
line += 16;
v = get_dec_u16(line, &i, 3);
v = (v<0) ? 0 : ((v>255) ? 255 : v);
ai->config.longRetryLimit = cpu_to_le16(v);
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "ShortRetryLimit: ", 17 ) ) {
int v, i = 0;
line += 17;
v = get_dec_u16(line, &i, 3);
v = (v<0) ? 0 : ((v>255) ? 255 : v);
ai->config.shortRetryLimit = cpu_to_le16(v);
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "RTSThreshold: ", 14 ) ) {
int v, i = 0;
line += 14;
v = get_dec_u16(line, &i, 4);
v = (v<0) ? 0 : ((v>AIRO_DEF_MTU) ? AIRO_DEF_MTU : v);
ai->config.rtsThres = cpu_to_le16(v);
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "TXMSDULifetime: ", 16 ) ) {
int v, i = 0;
line += 16;
v = get_dec_u16(line, &i, 5);
v = (v<0) ? 0 : v;
ai->config.txLifetime = cpu_to_le16(v);
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "RXMSDULifetime: ", 16 ) ) {
int v, i = 0;
line += 16;
v = get_dec_u16(line, &i, 5);
v = (v<0) ? 0 : v;
ai->config.rxLifetime = cpu_to_le16(v);
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "TXDiversity: ", 13 ) ) {
ai->config.txDiversity =
(line[13]=='l') ? 1 :
((line[13]=='r')? 2: 3);
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "RXDiversity: ", 13 ) ) {
ai->config.rxDiversity =
(line[13]=='l') ? 1 :
((line[13]=='r')? 2: 3);
set_bit (FLAG_COMMIT, &ai->flags);
} else if ( !strncmp( line, "FragThreshold: ", 15 ) ) {
int v, i = 0;
line += 15;
v = get_dec_u16(line, &i, 4);
v = (v<256) ? 256 : ((v>AIRO_DEF_MTU) ? AIRO_DEF_MTU : v);
v = v & 0xfffe;
ai->config.fragThresh = cpu_to_le16(v);
set_bit (FLAG_COMMIT, &ai->flags);
} else if (!strncmp(line, "Modulation: ", 12)) {
line += 12;
switch(*line) {
case 'd': ai->config.modulation=MOD_DEFAULT; set_bit(FLAG_COMMIT, &ai->flags); break;
case 'c': ai->config.modulation=MOD_CCK; set_bit(FLAG_COMMIT, &ai->flags); break;
case 'm': ai->config.modulation=MOD_MOK; set_bit(FLAG_COMMIT, &ai->flags); break;
default: airo_print_warn(ai->dev->name, "Unknown modulation");
}
} else if (!strncmp(line, "Preamble: ", 10)) {
line += 10;
switch(*line) {
case 'a': ai->config.preamble=PREAMBLE_AUTO; set_bit(FLAG_COMMIT, &ai->flags); break;
case 'l': ai->config.preamble=PREAMBLE_LONG; set_bit(FLAG_COMMIT, &ai->flags); break;
case 's': ai->config.preamble=PREAMBLE_SHORT; set_bit(FLAG_COMMIT, &ai->flags); break;
default: airo_print_warn(ai->dev->name, "Unknown preamble");
}
} else {
airo_print_warn(ai->dev->name, "Couldn't figure out %s", line);
}
while( line[0] && line[0] != '\n' ) line++;
if ( line[0] ) line++;
}
airo_config_commit(dev, NULL, NULL, NULL);
}
static const char *get_rmode(__le16 mode)
{
switch(mode & RXMODE_MASK) {
case RXMODE_RFMON: return "rfmon";
case RXMODE_RFMON_ANYBSS: return "yna (any) bss rfmon";
case RXMODE_LANMON: return "lanmon";
}
return "ESS";
}
static int proc_config_open(struct inode *inode, struct file *file)
{
struct proc_data *data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *ai = dev->ml_priv;
int i;
__le16 mode;
if ((file->private_data = kzalloc(sizeof(struct proc_data ), GFP_KERNEL)) == NULL)
return -ENOMEM;
data = file->private_data;
if ((data->rbuffer = kmalloc( 2048, GFP_KERNEL )) == NULL) {
kfree (file->private_data);
return -ENOMEM;
}
if ((data->wbuffer = kzalloc( 2048, GFP_KERNEL )) == NULL) {
kfree (data->rbuffer);
kfree (file->private_data);
return -ENOMEM;
}
data->maxwritelen = 2048;
data->on_close = proc_config_on_close;
readConfigRid(ai, 1);
mode = ai->config.opmode & MODE_CFG_MASK;
i = sprintf( data->rbuffer,
"Mode: %s\n"
"Radio: %s\n"
"NodeName: %-16s\n"
"PowerMode: %s\n"
"DataRates: %d %d %d %d %d %d %d %d\n"
"Channel: %d\n"
"XmitPower: %d\n",
mode == MODE_STA_IBSS ? "adhoc" :
mode == MODE_STA_ESS ? get_rmode(ai->config.rmode):
mode == MODE_AP ? "AP" :
mode == MODE_AP_RPTR ? "AP RPTR" : "Error",
test_bit(FLAG_RADIO_OFF, &ai->flags) ? "off" : "on",
ai->config.nodeName,
ai->config.powerSaveMode == POWERSAVE_CAM ? "CAM" :
ai->config.powerSaveMode == POWERSAVE_PSP ? "PSP" :
ai->config.powerSaveMode == POWERSAVE_PSPCAM ? "PSPCAM" :
"Error",
(int)ai->config.rates[0],
(int)ai->config.rates[1],
(int)ai->config.rates[2],
(int)ai->config.rates[3],
(int)ai->config.rates[4],
(int)ai->config.rates[5],
(int)ai->config.rates[6],
(int)ai->config.rates[7],
le16_to_cpu(ai->config.channelSet),
le16_to_cpu(ai->config.txPower)
);
sprintf( data->rbuffer + i,
"LongRetryLimit: %d\n"
"ShortRetryLimit: %d\n"
"RTSThreshold: %d\n"
"TXMSDULifetime: %d\n"
"RXMSDULifetime: %d\n"
"TXDiversity: %s\n"
"RXDiversity: %s\n"
"FragThreshold: %d\n"
"WEP: %s\n"
"Modulation: %s\n"
"Preamble: %s\n",
le16_to_cpu(ai->config.longRetryLimit),
le16_to_cpu(ai->config.shortRetryLimit),
le16_to_cpu(ai->config.rtsThres),
le16_to_cpu(ai->config.txLifetime),
le16_to_cpu(ai->config.rxLifetime),
ai->config.txDiversity == 1 ? "left" :
ai->config.txDiversity == 2 ? "right" : "both",
ai->config.rxDiversity == 1 ? "left" :
ai->config.rxDiversity == 2 ? "right" : "both",
le16_to_cpu(ai->config.fragThresh),
ai->config.authType == AUTH_ENCRYPT ? "encrypt" :
ai->config.authType == AUTH_SHAREDKEY ? "shared" : "open",
ai->config.modulation == MOD_DEFAULT ? "default" :
ai->config.modulation == MOD_CCK ? "cck" :
ai->config.modulation == MOD_MOK ? "mok" : "error",
ai->config.preamble == PREAMBLE_AUTO ? "auto" :
ai->config.preamble == PREAMBLE_LONG ? "long" :
ai->config.preamble == PREAMBLE_SHORT ? "short" : "error"
);
data->readlen = strlen( data->rbuffer );
return 0;
}
static void proc_SSID_on_close(struct inode *inode, struct file *file)
{
struct proc_data *data = file->private_data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *ai = dev->ml_priv;
SsidRid SSID_rid;
int i;
char *p = data->wbuffer;
char *end = p + data->writelen;
if (!data->writelen)
return;
*end = '\n';
memset(&SSID_rid, 0, sizeof(SSID_rid));
for (i = 0; i < 3 && p < end; i++) {
int j = 0;
while (*p != '\n' && j < 32)
SSID_rid.ssids[i].ssid[j++] = *p++;
if (j == 0)
break;
SSID_rid.ssids[i].len = cpu_to_le16(j);
while (*p++ != '\n')
;
}
if (i)
SSID_rid.len = cpu_to_le16(sizeof(SSID_rid));
disable_MAC(ai, 1);
writeSsidRid(ai, &SSID_rid, 1);
enable_MAC(ai, 1);
}
static void proc_APList_on_close( struct inode *inode, struct file *file ) {
struct proc_data *data = file->private_data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *ai = dev->ml_priv;
APListRid APList_rid;
int i;
if ( !data->writelen ) return;
memset( &APList_rid, 0, sizeof(APList_rid) );
APList_rid.len = cpu_to_le16(sizeof(APList_rid));
for( i = 0; i < 4 && data->writelen >= (i+1)*6*3; i++ ) {
int j;
for( j = 0; j < 6*3 && data->wbuffer[j+i*6*3]; j++ ) {
switch(j%3) {
case 0:
APList_rid.ap[i][j/3]=
hex_to_bin(data->wbuffer[j+i*6*3])<<4;
break;
case 1:
APList_rid.ap[i][j/3]|=
hex_to_bin(data->wbuffer[j+i*6*3]);
break;
}
}
}
disable_MAC(ai, 1);
writeAPListRid(ai, &APList_rid, 1);
enable_MAC(ai, 1);
}
static int do_writerid( struct airo_info *ai, u16 rid, const void *rid_data,
int len, int dummy ) {
int rc;
disable_MAC(ai, 1);
rc = PC4500_writerid(ai, rid, rid_data, len, 1);
enable_MAC(ai, 1);
return rc;
}
static int get_wep_key(struct airo_info *ai, u16 index, char *buf, u16 buflen)
{
WepKeyRid wkr;
int rc;
__le16 lastindex;
rc = readWepKeyRid(ai, &wkr, 1, 1);
if (rc != SUCCESS)
return -1;
do {
lastindex = wkr.kindex;
if (le16_to_cpu(wkr.kindex) == index) {
int klen = min_t(int, buflen, le16_to_cpu(wkr.klen));
memcpy(buf, wkr.key, klen);
return klen;
}
rc = readWepKeyRid(ai, &wkr, 0, 1);
if (rc != SUCCESS)
return -1;
} while (lastindex != wkr.kindex);
return -1;
}
static int get_wep_tx_idx(struct airo_info *ai)
{
WepKeyRid wkr;
int rc;
__le16 lastindex;
rc = readWepKeyRid(ai, &wkr, 1, 1);
if (rc != SUCCESS)
return -1;
do {
lastindex = wkr.kindex;
if (wkr.kindex == cpu_to_le16(0xffff))
return wkr.mac[0];
rc = readWepKeyRid(ai, &wkr, 0, 1);
if (rc != SUCCESS)
return -1;
} while (lastindex != wkr.kindex);
return -1;
}
static int set_wep_key(struct airo_info *ai, u16 index, const char *key,
u16 keylen, int perm, int lock)
{
static const unsigned char macaddr[ETH_ALEN] = { 0x01, 0, 0, 0, 0, 0 };
WepKeyRid wkr;
int rc;
if (WARN_ON(keylen == 0))
return -1;
memset(&wkr, 0, sizeof(wkr));
wkr.len = cpu_to_le16(sizeof(wkr));
wkr.kindex = cpu_to_le16(index);
wkr.klen = cpu_to_le16(keylen);
memcpy(wkr.key, key, keylen);
memcpy(wkr.mac, macaddr, ETH_ALEN);
if (perm) disable_MAC(ai, lock);
rc = writeWepKeyRid(ai, &wkr, perm, lock);
if (perm) enable_MAC(ai, lock);
return rc;
}
static int set_wep_tx_idx(struct airo_info *ai, u16 index, int perm, int lock)
{
WepKeyRid wkr;
int rc;
memset(&wkr, 0, sizeof(wkr));
wkr.len = cpu_to_le16(sizeof(wkr));
wkr.kindex = cpu_to_le16(0xffff);
wkr.mac[0] = (char)index;
if (perm) {
ai->defindex = (char)index;
disable_MAC(ai, lock);
}
rc = writeWepKeyRid(ai, &wkr, perm, lock);
if (perm)
enable_MAC(ai, lock);
return rc;
}
static void proc_wepkey_on_close( struct inode *inode, struct file *file ) {
struct proc_data *data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *ai = dev->ml_priv;
int i, rc;
char key[16];
u16 index = 0;
int j = 0;
memset(key, 0, sizeof(key));
data = file->private_data;
if ( !data->writelen ) return;
if (data->wbuffer[0] >= '0' && data->wbuffer[0] <= '3' &&
(data->wbuffer[1] == ' ' || data->wbuffer[1] == '\n')) {
index = data->wbuffer[0] - '0';
if (data->wbuffer[1] == '\n') {
rc = set_wep_tx_idx(ai, index, 1, 1);
if (rc < 0) {
airo_print_err(ai->dev->name, "failed to set "
"WEP transmit index to %d: %d.",
index, rc);
}
return;
}
j = 2;
} else {
airo_print_err(ai->dev->name, "WepKey passed invalid key index");
return;
}
for( i = 0; i < 16*3 && data->wbuffer[i+j]; i++ ) {
switch(i%3) {
case 0:
key[i/3] = hex_to_bin(data->wbuffer[i+j])<<4;
break;
case 1:
key[i/3] |= hex_to_bin(data->wbuffer[i+j]);
break;
}
}
rc = set_wep_key(ai, index, key, i/3, 1, 1);
if (rc < 0) {
airo_print_err(ai->dev->name, "failed to set WEP key at index "
"%d: %d.", index, rc);
}
}
static int proc_wepkey_open( struct inode *inode, struct file *file )
{
struct proc_data *data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *ai = dev->ml_priv;
char *ptr;
WepKeyRid wkr;
__le16 lastindex;
int j=0;
int rc;
if ((file->private_data = kzalloc(sizeof(struct proc_data ), GFP_KERNEL)) == NULL)
return -ENOMEM;
memset(&wkr, 0, sizeof(wkr));
data = file->private_data;
if ((data->rbuffer = kzalloc( 180, GFP_KERNEL )) == NULL) {
kfree (file->private_data);
return -ENOMEM;
}
data->writelen = 0;
data->maxwritelen = 80;
if ((data->wbuffer = kzalloc( 80, GFP_KERNEL )) == NULL) {
kfree (data->rbuffer);
kfree (file->private_data);
return -ENOMEM;
}
data->on_close = proc_wepkey_on_close;
ptr = data->rbuffer;
strcpy(ptr, "No wep keys\n");
rc = readWepKeyRid(ai, &wkr, 1, 1);
if (rc == SUCCESS) do {
lastindex = wkr.kindex;
if (wkr.kindex == cpu_to_le16(0xffff)) {
j += sprintf(ptr+j, "Tx key = %d\n",
(int)wkr.mac[0]);
} else {
j += sprintf(ptr+j, "Key %d set with length = %d\n",
le16_to_cpu(wkr.kindex),
le16_to_cpu(wkr.klen));
}
readWepKeyRid(ai, &wkr, 0, 1);
} while((lastindex != wkr.kindex) && (j < 180-30));
data->readlen = strlen( data->rbuffer );
return 0;
}
static int proc_SSID_open(struct inode *inode, struct file *file)
{
struct proc_data *data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *ai = dev->ml_priv;
int i;
char *ptr;
SsidRid SSID_rid;
if ((file->private_data = kzalloc(sizeof(struct proc_data ), GFP_KERNEL)) == NULL)
return -ENOMEM;
data = file->private_data;
if ((data->rbuffer = kmalloc( 104, GFP_KERNEL )) == NULL) {
kfree (file->private_data);
return -ENOMEM;
}
data->writelen = 0;
data->maxwritelen = 33*3;
if ((data->wbuffer = kzalloc(33*3 + 1, GFP_KERNEL)) == NULL) {
kfree (data->rbuffer);
kfree (file->private_data);
return -ENOMEM;
}
data->on_close = proc_SSID_on_close;
readSsidRid(ai, &SSID_rid);
ptr = data->rbuffer;
for (i = 0; i < 3; i++) {
int j;
size_t len = le16_to_cpu(SSID_rid.ssids[i].len);
if (!len)
break;
if (len > 32)
len = 32;
for (j = 0; j < len && SSID_rid.ssids[i].ssid[j]; j++)
*ptr++ = SSID_rid.ssids[i].ssid[j];
*ptr++ = '\n';
}
*ptr = '\0';
data->readlen = strlen( data->rbuffer );
return 0;
}
static int proc_APList_open( struct inode *inode, struct file *file ) {
struct proc_data *data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *ai = dev->ml_priv;
int i;
char *ptr;
APListRid APList_rid;
if ((file->private_data = kzalloc(sizeof(struct proc_data ), GFP_KERNEL)) == NULL)
return -ENOMEM;
data = file->private_data;
if ((data->rbuffer = kmalloc( 104, GFP_KERNEL )) == NULL) {
kfree (file->private_data);
return -ENOMEM;
}
data->writelen = 0;
data->maxwritelen = 4*6*3;
if ((data->wbuffer = kzalloc( data->maxwritelen, GFP_KERNEL )) == NULL) {
kfree (data->rbuffer);
kfree (file->private_data);
return -ENOMEM;
}
data->on_close = proc_APList_on_close;
readAPListRid(ai, &APList_rid);
ptr = data->rbuffer;
for( i = 0; i < 4; i++ ) {
if ( !*(int*)APList_rid.ap[i] &&
!*(int*)&APList_rid.ap[i][2]) break;
ptr += sprintf(ptr, "%pM\n", APList_rid.ap[i]);
}
if (i==0) ptr += sprintf(ptr, "Not using specific APs\n");
*ptr = '\0';
data->readlen = strlen( data->rbuffer );
return 0;
}
static int proc_BSSList_open( struct inode *inode, struct file *file ) {
struct proc_data *data;
struct proc_dir_entry *dp = PDE(inode);
struct net_device *dev = dp->data;
struct airo_info *ai = dev->ml_priv;
char *ptr;
BSSListRid BSSList_rid;
int rc;
int doLoseSync = -1;
if ((file->private_data = kzalloc(sizeof(struct proc_data ), GFP_KERNEL)) == NULL)
return -ENOMEM;
data = file->private_data;
if ((data->rbuffer = kmalloc( 1024, GFP_KERNEL )) == NULL) {
kfree (file->private_data);
return -ENOMEM;
}
data->writelen = 0;
data->maxwritelen = 0;
data->wbuffer = NULL;
data->on_close = NULL;
if (file->f_mode & FMODE_WRITE) {
if (!(file->f_mode & FMODE_READ)) {
Cmd cmd;
Resp rsp;
if (ai->flags & FLAG_RADIO_MASK) return -ENETDOWN;
memset(&cmd, 0, sizeof(cmd));
cmd.cmd=CMD_LISTBSS;
if (down_interruptible(&ai->sem))
return -ERESTARTSYS;
issuecommand(ai, &cmd, &rsp);
up(&ai->sem);
data->readlen = 0;
return 0;
}
doLoseSync = 1;
}
ptr = data->rbuffer;
rc = readBSSListRid(ai, doLoseSync, &BSSList_rid);
while(rc == 0 && BSSList_rid.index != cpu_to_le16(0xffff)) {
ptr += sprintf(ptr, "%pM %*s rssi = %d",
BSSList_rid.bssid,
(int)BSSList_rid.ssidLen,
BSSList_rid.ssid,
le16_to_cpu(BSSList_rid.dBm));
ptr += sprintf(ptr, " channel = %d %s %s %s %s\n",
le16_to_cpu(BSSList_rid.dsChannel),
BSSList_rid.cap & CAP_ESS ? "ESS" : "",
BSSList_rid.cap & CAP_IBSS ? "adhoc" : "",
BSSList_rid.cap & CAP_PRIVACY ? "wep" : "",
BSSList_rid.cap & CAP_SHORTHDR ? "shorthdr" : "");
rc = readBSSListRid(ai, 0, &BSSList_rid);
}
*ptr = '\0';
data->readlen = strlen( data->rbuffer );
return 0;
}
static int proc_close( struct inode *inode, struct file *file )
{
struct proc_data *data = file->private_data;
if (data->on_close != NULL)
data->on_close(inode, file);
kfree(data->rbuffer);
kfree(data->wbuffer);
kfree(data);
return 0;
}
static void timer_func( struct net_device *dev ) {
struct airo_info *apriv = dev->ml_priv;
readConfigRid(apriv, 0);
disable_MAC(apriv, 0);
switch(apriv->config.authType) {
case AUTH_ENCRYPT:
apriv->config.authType = AUTH_OPEN;
break;
case AUTH_SHAREDKEY:
if (apriv->keyindex < auto_wep) {
set_wep_tx_idx(apriv, apriv->keyindex, 0, 0);
apriv->config.authType = AUTH_SHAREDKEY;
apriv->keyindex++;
} else {
apriv->keyindex = 0;
set_wep_tx_idx(apriv, apriv->defindex, 0, 0);
apriv->config.authType = AUTH_ENCRYPT;
}
break;
default:
apriv->config.authType = AUTH_SHAREDKEY;
}
set_bit (FLAG_COMMIT, &apriv->flags);
writeConfigRid(apriv, 0);
enable_MAC(apriv, 0);
up(&apriv->sem);
clear_bit(JOB_AUTOWEP, &apriv->jobs);
apriv->expires = RUN_AT(HZ*3);
}
static int airo_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *pent)
{
struct net_device *dev;
if (pci_enable_device(pdev))
return -ENODEV;
pci_set_master(pdev);
if (pdev->device == 0x5000 || pdev->device == 0xa504)
dev = _init_airo_card(pdev->irq, pdev->resource[0].start, 0, pdev, &pdev->dev);
else
dev = _init_airo_card(pdev->irq, pdev->resource[2].start, 0, pdev, &pdev->dev);
if (!dev) {
pci_disable_device(pdev);
return -ENODEV;
}
pci_set_drvdata(pdev, dev);
return 0;
}
static void airo_pci_remove(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
airo_print_info(dev->name, "Unregistering...");
stop_airo_card(dev, 1);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int airo_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct airo_info *ai = dev->ml_priv;
Cmd cmd;
Resp rsp;
if (!ai->APList)
ai->APList = kmalloc(sizeof(APListRid), GFP_KERNEL);
if (!ai->APList)
return -ENOMEM;
if (!ai->SSID)
ai->SSID = kmalloc(sizeof(SsidRid), GFP_KERNEL);
if (!ai->SSID)
return -ENOMEM;
readAPListRid(ai, ai->APList);
readSsidRid(ai, ai->SSID);
memset(&cmd, 0, sizeof(cmd));
if (down_interruptible(&ai->sem))
return -EAGAIN;
disable_MAC(ai, 0);
netif_device_detach(dev);
ai->power = state;
cmd.cmd = HOSTSLEEP;
issuecommand(ai, &cmd, &rsp);
pci_enable_wake(pdev, pci_choose_state(pdev, state), 1);
pci_save_state(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int airo_pci_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct airo_info *ai = dev->ml_priv;
pci_power_t prev_state = pdev->current_state;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
pci_enable_wake(pdev, PCI_D0, 0);
if (prev_state != PCI_D1) {
reset_card(dev, 0);
mpi_init_descriptors(ai);
setup_card(ai, dev->dev_addr, 0);
clear_bit(FLAG_RADIO_OFF, &ai->flags);
clear_bit(FLAG_PENDING_XMIT, &ai->flags);
} else {
OUT4500(ai, EVACK, EV_AWAKEN);
OUT4500(ai, EVACK, EV_AWAKEN);
msleep(100);
}
set_bit(FLAG_COMMIT, &ai->flags);
disable_MAC(ai, 0);
msleep(200);
if (ai->SSID) {
writeSsidRid(ai, ai->SSID, 0);
kfree(ai->SSID);
ai->SSID = NULL;
}
if (ai->APList) {
writeAPListRid(ai, ai->APList, 0);
kfree(ai->APList);
ai->APList = NULL;
}
writeConfigRid(ai, 0);
enable_MAC(ai, 0);
ai->power = PMSG_ON;
netif_device_attach(dev);
netif_wake_queue(dev);
enable_interrupts(ai);
up(&ai->sem);
return 0;
}
static int __init airo_init_module( void )
{
int i;
proc_kuid = make_kuid(&init_user_ns, proc_uid);
proc_kgid = make_kgid(&init_user_ns, proc_gid);
if (!uid_valid(proc_kuid) || !gid_valid(proc_kgid))
return -EINVAL;
airo_entry = proc_mkdir_mode("driver/aironet", airo_perm, NULL);
if (airo_entry) {
airo_entry->uid = proc_kuid;
airo_entry->gid = proc_kgid;
}
for (i = 0; i < 4 && io[i] && irq[i]; i++) {
airo_print_info("", "Trying to configure ISA adapter at irq=%d "
"io=0x%x", irq[i], io[i] );
if (init_airo_card( irq[i], io[i], 0, NULL ))
;
}
#ifdef CONFIG_PCI
airo_print_info("", "Probing for PCI adapters");
i = pci_register_driver(&airo_driver);
airo_print_info("", "Finished probing for PCI adapters");
if (i) {
remove_proc_entry("driver/aironet", NULL);
return i;
}
#endif
return 0;
}
static void __exit airo_cleanup_module( void )
{
struct airo_info *ai;
while(!list_empty(&airo_devices)) {
ai = list_entry(airo_devices.next, struct airo_info, dev_list);
airo_print_info(ai->dev->name, "Unregistering...");
stop_airo_card(ai->dev, 1);
}
#ifdef CONFIG_PCI
pci_unregister_driver(&airo_driver);
#endif
remove_proc_entry("driver/aironet", NULL);
}
static u8 airo_rssi_to_dbm (tdsRssiEntry *rssi_rid, u8 rssi)
{
if (!rssi_rid)
return 0;
return (0x100 - rssi_rid[rssi].rssidBm);
}
static u8 airo_dbm_to_pct (tdsRssiEntry *rssi_rid, u8 dbm)
{
int i;
if (!rssi_rid)
return 0;
for (i = 0; i < 256; i++)
if (rssi_rid[i].rssidBm == dbm)
return rssi_rid[i].rssipct;
return 0;
}
static int airo_get_quality (StatusRid *status_rid, CapabilityRid *cap_rid)
{
int quality = 0;
u16 sq;
if ((status_rid->mode & cpu_to_le16(0x3f)) != cpu_to_le16(0x3f))
return 0;
if (!(cap_rid->hardCap & cpu_to_le16(8)))
return 0;
sq = le16_to_cpu(status_rid->signalQuality);
if (memcmp(cap_rid->prodName, "350", 3))
if (sq > 0x20)
quality = 0;
else
quality = 0x20 - sq;
else
if (sq > 0xb0)
quality = 0;
else if (sq < 0x10)
quality = 0xa0;
else
quality = 0xb0 - sq;
return quality;
}
static int airo_get_name(struct net_device *dev,
struct iw_request_info *info,
char *cwrq,
char *extra)
{
strcpy(cwrq, "IEEE 802.11-DS");
return 0;
}
static int airo_set_freq(struct net_device *dev,
struct iw_request_info *info,
struct iw_freq *fwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
int rc = -EINPROGRESS;
if(fwrq->e == 1) {
int f = fwrq->m / 100000;
fwrq->e = 0;
fwrq->m = ieee80211_freq_to_dsss_chan(f);
}
if((fwrq->m > 1000) || (fwrq->e > 0))
rc = -EOPNOTSUPP;
else {
int channel = fwrq->m;
if((channel < 1) || (channel > 14)) {
airo_print_dbg(dev->name, "New channel value of %d is invalid!",
fwrq->m);
rc = -EINVAL;
} else {
readConfigRid(local, 1);
local->config.channelSet = cpu_to_le16(channel);
set_bit (FLAG_COMMIT, &local->flags);
}
}
return rc;
}
static int airo_get_freq(struct net_device *dev,
struct iw_request_info *info,
struct iw_freq *fwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
StatusRid status_rid;
int ch;
readConfigRid(local, 1);
if ((local->config.opmode & MODE_CFG_MASK) == MODE_STA_ESS)
status_rid.channel = local->config.channelSet;
else
readStatusRid(local, &status_rid, 1);
ch = le16_to_cpu(status_rid.channel);
if((ch > 0) && (ch < 15)) {
fwrq->m = ieee80211_dsss_chan_to_freq(ch) * 100000;
fwrq->e = 1;
} else {
fwrq->m = ch;
fwrq->e = 0;
}
return 0;
}
static int airo_set_essid(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
SsidRid SSID_rid;
readSsidRid(local, &SSID_rid);
if (dwrq->flags == 0) {
memset(&SSID_rid, 0, sizeof(SSID_rid));
} else {
unsigned index = (dwrq->flags & IW_ENCODE_INDEX) - 1;
if (dwrq->length > IW_ESSID_MAX_SIZE)
return -E2BIG ;
if (index >= ARRAY_SIZE(SSID_rid.ssids))
return -EINVAL;
memset(SSID_rid.ssids[index].ssid, 0,
sizeof(SSID_rid.ssids[index].ssid));
memcpy(SSID_rid.ssids[index].ssid, extra, dwrq->length);
SSID_rid.ssids[index].len = cpu_to_le16(dwrq->length);
}
SSID_rid.len = cpu_to_le16(sizeof(SSID_rid));
disable_MAC(local, 1);
writeSsidRid(local, &SSID_rid, 1);
enable_MAC(local, 1);
return 0;
}
static int airo_get_essid(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
StatusRid status_rid;
readStatusRid(local, &status_rid, 1);
memcpy(extra, status_rid.SSID, le16_to_cpu(status_rid.SSIDlen));
dwrq->length = le16_to_cpu(status_rid.SSIDlen);
dwrq->flags = 1;
return 0;
}
static int airo_set_wap(struct net_device *dev,
struct iw_request_info *info,
struct sockaddr *awrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
Cmd cmd;
Resp rsp;
APListRid APList_rid;
if (awrq->sa_family != ARPHRD_ETHER)
return -EINVAL;
else if (is_broadcast_ether_addr(awrq->sa_data) ||
is_zero_ether_addr(awrq->sa_data)) {
memset(&cmd, 0, sizeof(cmd));
cmd.cmd=CMD_LOSE_SYNC;
if (down_interruptible(&local->sem))
return -ERESTARTSYS;
issuecommand(local, &cmd, &rsp);
up(&local->sem);
} else {
memset(&APList_rid, 0, sizeof(APList_rid));
APList_rid.len = cpu_to_le16(sizeof(APList_rid));
memcpy(APList_rid.ap[0], awrq->sa_data, ETH_ALEN);
disable_MAC(local, 1);
writeAPListRid(local, &APList_rid, 1);
enable_MAC(local, 1);
}
return 0;
}
static int airo_get_wap(struct net_device *dev,
struct iw_request_info *info,
struct sockaddr *awrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
StatusRid status_rid;
readStatusRid(local, &status_rid, 1);
memcpy(awrq->sa_data, status_rid.bssid[0], ETH_ALEN);
awrq->sa_family = ARPHRD_ETHER;
return 0;
}
static int airo_set_nick(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
if(dwrq->length > 16) {
return -E2BIG;
}
readConfigRid(local, 1);
memset(local->config.nodeName, 0, sizeof(local->config.nodeName));
memcpy(local->config.nodeName, extra, dwrq->length);
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
static int airo_get_nick(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
readConfigRid(local, 1);
strncpy(extra, local->config.nodeName, 16);
extra[16] = '\0';
dwrq->length = strlen(extra);
return 0;
}
static int airo_set_rate(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
CapabilityRid cap_rid;
u8 brate = 0;
int i;
readCapabilityRid(local, &cap_rid, 1);
if((vwrq->value < 8) && (vwrq->value >= 0)) {
brate = cap_rid.supportedRates[vwrq->value];
} else {
u8 normvalue = (u8) (vwrq->value/500000);
for(i = 0 ; i < 8 ; i++) {
if(normvalue == cap_rid.supportedRates[i]) {
brate = normvalue;
break;
}
}
}
if(vwrq->value == -1) {
for(i = 0 ; i < 8 ; i++) {
if(cap_rid.supportedRates[i] == 0)
break;
}
if(i != 0)
brate = cap_rid.supportedRates[i - 1];
}
if(brate == 0) {
return -EINVAL;
}
readConfigRid(local, 1);
if(vwrq->fixed == 0) {
memset(local->config.rates, 0, 8);
for(i = 0 ; i < 8 ; i++) {
local->config.rates[i] = cap_rid.supportedRates[i];
if(local->config.rates[i] == brate)
break;
}
} else {
memset(local->config.rates, 0, 8);
local->config.rates[0] = brate;
}
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
static int airo_get_rate(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
StatusRid status_rid;
readStatusRid(local, &status_rid, 1);
vwrq->value = le16_to_cpu(status_rid.currentXmitRate) * 500000;
readConfigRid(local, 1);
vwrq->fixed = (local->config.rates[1] == 0);
return 0;
}
static int airo_set_rts(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
int rthr = vwrq->value;
if(vwrq->disabled)
rthr = AIRO_DEF_MTU;
if((rthr < 0) || (rthr > AIRO_DEF_MTU)) {
return -EINVAL;
}
readConfigRid(local, 1);
local->config.rtsThres = cpu_to_le16(rthr);
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
static int airo_get_rts(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
readConfigRid(local, 1);
vwrq->value = le16_to_cpu(local->config.rtsThres);
vwrq->disabled = (vwrq->value >= AIRO_DEF_MTU);
vwrq->fixed = 1;
return 0;
}
static int airo_set_frag(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
int fthr = vwrq->value;
if(vwrq->disabled)
fthr = AIRO_DEF_MTU;
if((fthr < 256) || (fthr > AIRO_DEF_MTU)) {
return -EINVAL;
}
fthr &= ~0x1;
readConfigRid(local, 1);
local->config.fragThresh = cpu_to_le16(fthr);
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
static int airo_get_frag(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
readConfigRid(local, 1);
vwrq->value = le16_to_cpu(local->config.fragThresh);
vwrq->disabled = (vwrq->value >= AIRO_DEF_MTU);
vwrq->fixed = 1;
return 0;
}
static int airo_set_mode(struct net_device *dev,
struct iw_request_info *info,
__u32 *uwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
int reset = 0;
readConfigRid(local, 1);
if (sniffing_mode(local))
reset = 1;
switch(*uwrq) {
case IW_MODE_ADHOC:
local->config.opmode &= ~MODE_CFG_MASK;
local->config.opmode |= MODE_STA_IBSS;
local->config.rmode &= ~RXMODE_FULL_MASK;
local->config.scanMode = SCANMODE_ACTIVE;
clear_bit (FLAG_802_11, &local->flags);
break;
case IW_MODE_INFRA:
local->config.opmode &= ~MODE_CFG_MASK;
local->config.opmode |= MODE_STA_ESS;
local->config.rmode &= ~RXMODE_FULL_MASK;
local->config.scanMode = SCANMODE_ACTIVE;
clear_bit (FLAG_802_11, &local->flags);
break;
case IW_MODE_MASTER:
local->config.opmode &= ~MODE_CFG_MASK;
local->config.opmode |= MODE_AP;
local->config.rmode &= ~RXMODE_FULL_MASK;
local->config.scanMode = SCANMODE_ACTIVE;
clear_bit (FLAG_802_11, &local->flags);
break;
case IW_MODE_REPEAT:
local->config.opmode &= ~MODE_CFG_MASK;
local->config.opmode |= MODE_AP_RPTR;
local->config.rmode &= ~RXMODE_FULL_MASK;
local->config.scanMode = SCANMODE_ACTIVE;
clear_bit (FLAG_802_11, &local->flags);
break;
case IW_MODE_MONITOR:
local->config.opmode &= ~MODE_CFG_MASK;
local->config.opmode |= MODE_STA_ESS;
local->config.rmode &= ~RXMODE_FULL_MASK;
local->config.rmode |= RXMODE_RFMON | RXMODE_DISABLE_802_3_HEADER;
local->config.scanMode = SCANMODE_PASSIVE;
set_bit (FLAG_802_11, &local->flags);
break;
default:
return -EINVAL;
}
if (reset)
set_bit (FLAG_RESET, &local->flags);
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
static int airo_get_mode(struct net_device *dev,
struct iw_request_info *info,
__u32 *uwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
readConfigRid(local, 1);
switch (local->config.opmode & MODE_CFG_MASK) {
case MODE_STA_ESS:
*uwrq = IW_MODE_INFRA;
break;
case MODE_AP:
*uwrq = IW_MODE_MASTER;
break;
case MODE_AP_RPTR:
*uwrq = IW_MODE_REPEAT;
break;
default:
*uwrq = IW_MODE_ADHOC;
}
return 0;
}
static inline int valid_index(struct airo_info *ai, int index)
{
return (index >= 0) && (index <= ai->max_wep_idx);
}
static int airo_set_encode(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
int perm = (dwrq->flags & IW_ENCODE_TEMP ? 0 : 1);
__le16 currentAuthType = local->config.authType;
int rc = 0;
if (!local->wep_capable)
return -EOPNOTSUPP;
readConfigRid(local, 1);
if (dwrq->length > 0) {
wep_key_t key;
int index = (dwrq->flags & IW_ENCODE_INDEX) - 1;
int current_index;
if (dwrq->length > MAX_KEY_SIZE) {
return -EINVAL;
}
current_index = get_wep_tx_idx(local);
if (current_index < 0)
current_index = 0;
if (!valid_index(local, index))
index = current_index;
if (dwrq->length > MIN_KEY_SIZE)
key.len = MAX_KEY_SIZE;
else
key.len = MIN_KEY_SIZE;
if(!(dwrq->flags & IW_ENCODE_NOKEY)) {
memset(key.key, 0, MAX_KEY_SIZE);
memcpy(key.key, extra, dwrq->length);
rc = set_wep_key(local, index, key.key, key.len, perm, 1);
if (rc < 0) {
airo_print_err(local->dev->name, "failed to set"
" WEP key at index %d: %d.",
index, rc);
return rc;
}
}
if((index == current_index) && (key.len > 0) &&
(local->config.authType == AUTH_OPEN)) {
local->config.authType = AUTH_ENCRYPT;
}
} else {
int index = (dwrq->flags & IW_ENCODE_INDEX) - 1;
if (valid_index(local, index)) {
rc = set_wep_tx_idx(local, index, perm, 1);
if (rc < 0) {
airo_print_err(local->dev->name, "failed to set"
" WEP transmit index to %d: %d.",
index, rc);
return rc;
}
} else {
if (!(dwrq->flags & IW_ENCODE_MODE))
return -EINVAL;
}
}
if(dwrq->flags & IW_ENCODE_DISABLED)
local->config.authType = AUTH_OPEN;
if(dwrq->flags & IW_ENCODE_RESTRICTED)
local->config.authType = AUTH_SHAREDKEY;
if(dwrq->flags & IW_ENCODE_OPEN)
local->config.authType = AUTH_ENCRYPT;
if (local->config.authType != currentAuthType)
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
static int airo_get_encode(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
int index = (dwrq->flags & IW_ENCODE_INDEX) - 1;
int wep_key_len;
u8 buf[16];
if (!local->wep_capable)
return -EOPNOTSUPP;
readConfigRid(local, 1);
switch(local->config.authType) {
case AUTH_ENCRYPT:
dwrq->flags = IW_ENCODE_OPEN;
break;
case AUTH_SHAREDKEY:
dwrq->flags = IW_ENCODE_RESTRICTED;
break;
default:
case AUTH_OPEN:
dwrq->flags = IW_ENCODE_DISABLED;
break;
}
dwrq->flags |= IW_ENCODE_NOKEY;
memset(extra, 0, 16);
if (!valid_index(local, index)) {
index = get_wep_tx_idx(local);
if (index < 0)
index = 0;
}
dwrq->flags |= index + 1;
wep_key_len = get_wep_key(local, index, &buf[0], sizeof(buf));
if (wep_key_len < 0) {
dwrq->length = 0;
} else {
dwrq->length = wep_key_len;
memcpy(extra, buf, dwrq->length);
}
return 0;
}
static int airo_set_encodeext(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu,
char *extra)
{
struct airo_info *local = dev->ml_priv;
struct iw_point *encoding = &wrqu->encoding;
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
int perm = ( encoding->flags & IW_ENCODE_TEMP ? 0 : 1 );
__le16 currentAuthType = local->config.authType;
int idx, key_len, alg = ext->alg, set_key = 1, rc;
wep_key_t key;
if (!local->wep_capable)
return -EOPNOTSUPP;
readConfigRid(local, 1);
idx = encoding->flags & IW_ENCODE_INDEX;
if (idx) {
if (!valid_index(local, idx - 1))
return -EINVAL;
idx--;
} else {
idx = get_wep_tx_idx(local);
if (idx < 0)
idx = 0;
}
if (encoding->flags & IW_ENCODE_DISABLED)
alg = IW_ENCODE_ALG_NONE;
if (ext->ext_flags & IW_ENCODE_EXT_SET_TX_KEY) {
rc = set_wep_tx_idx(local, idx, perm, 1);
if (rc < 0) {
airo_print_err(local->dev->name, "failed to set "
"WEP transmit index to %d: %d.",
idx, rc);
return rc;
}
set_key = ext->key_len > 0 ? 1 : 0;
}
if (set_key) {
memset(key.key, 0, MAX_KEY_SIZE);
switch (alg) {
case IW_ENCODE_ALG_NONE:
key.len = 0;
break;
case IW_ENCODE_ALG_WEP:
if (ext->key_len > MIN_KEY_SIZE) {
key.len = MAX_KEY_SIZE;
} else if (ext->key_len > 0) {
key.len = MIN_KEY_SIZE;
} else {
return -EINVAL;
}
key_len = min (ext->key_len, key.len);
memcpy(key.key, ext->key, key_len);
break;
default:
return -EINVAL;
}
if (key.len == 0) {
rc = set_wep_tx_idx(local, idx, perm, 1);
if (rc < 0) {
airo_print_err(local->dev->name,
"failed to set WEP transmit index to %d: %d.",
idx, rc);
return rc;
}
} else {
rc = set_wep_key(local, idx, key.key, key.len, perm, 1);
if (rc < 0) {
airo_print_err(local->dev->name,
"failed to set WEP key at index %d: %d.",
idx, rc);
return rc;
}
}
}
if(encoding->flags & IW_ENCODE_DISABLED)
local->config.authType = AUTH_OPEN;
if(encoding->flags & IW_ENCODE_RESTRICTED)
local->config.authType = AUTH_SHAREDKEY;
if(encoding->flags & IW_ENCODE_OPEN)
local->config.authType = AUTH_ENCRYPT;
if (local->config.authType != currentAuthType)
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
static int airo_get_encodeext(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu,
char *extra)
{
struct airo_info *local = dev->ml_priv;
struct iw_point *encoding = &wrqu->encoding;
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
int idx, max_key_len, wep_key_len;
u8 buf[16];
if (!local->wep_capable)
return -EOPNOTSUPP;
readConfigRid(local, 1);
max_key_len = encoding->length - sizeof(*ext);
if (max_key_len < 0)
return -EINVAL;
idx = encoding->flags & IW_ENCODE_INDEX;
if (idx) {
if (!valid_index(local, idx - 1))
return -EINVAL;
idx--;
} else {
idx = get_wep_tx_idx(local);
if (idx < 0)
idx = 0;
}
encoding->flags = idx + 1;
memset(ext, 0, sizeof(*ext));
switch(local->config.authType) {
case AUTH_ENCRYPT:
encoding->flags = IW_ENCODE_ALG_WEP | IW_ENCODE_ENABLED;
break;
case AUTH_SHAREDKEY:
encoding->flags = IW_ENCODE_ALG_WEP | IW_ENCODE_ENABLED;
break;
default:
case AUTH_OPEN:
encoding->flags = IW_ENCODE_ALG_NONE | IW_ENCODE_DISABLED;
break;
}
encoding->flags |= IW_ENCODE_NOKEY;
memset(extra, 0, 16);
wep_key_len = get_wep_key(local, idx, &buf[0], sizeof(buf));
if (wep_key_len < 0) {
ext->key_len = 0;
} else {
ext->key_len = wep_key_len;
memcpy(extra, buf, ext->key_len);
}
return 0;
}
static int airo_set_auth(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct airo_info *local = dev->ml_priv;
struct iw_param *param = &wrqu->param;
__le16 currentAuthType = local->config.authType;
switch (param->flags & IW_AUTH_INDEX) {
case IW_AUTH_WPA_VERSION:
case IW_AUTH_CIPHER_PAIRWISE:
case IW_AUTH_CIPHER_GROUP:
case IW_AUTH_KEY_MGMT:
case IW_AUTH_RX_UNENCRYPTED_EAPOL:
case IW_AUTH_PRIVACY_INVOKED:
break;
case IW_AUTH_DROP_UNENCRYPTED:
if (param->value) {
if (currentAuthType == AUTH_OPEN)
local->config.authType = AUTH_ENCRYPT;
} else {
local->config.authType = AUTH_OPEN;
}
if (local->config.authType != currentAuthType)
set_bit (FLAG_COMMIT, &local->flags);
break;
case IW_AUTH_80211_AUTH_ALG: {
if (param->value & IW_AUTH_ALG_SHARED_KEY) {
local->config.authType = AUTH_SHAREDKEY;
} else if (param->value & IW_AUTH_ALG_OPEN_SYSTEM) {
local->config.authType = AUTH_ENCRYPT;
} else
return -EINVAL;
if (local->config.authType != currentAuthType)
set_bit (FLAG_COMMIT, &local->flags);
break;
}
case IW_AUTH_WPA_ENABLED:
if (param->value > 0)
return -EOPNOTSUPP;
break;
default:
return -EOPNOTSUPP;
}
return -EINPROGRESS;
}
static int airo_get_auth(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct airo_info *local = dev->ml_priv;
struct iw_param *param = &wrqu->param;
__le16 currentAuthType = local->config.authType;
switch (param->flags & IW_AUTH_INDEX) {
case IW_AUTH_DROP_UNENCRYPTED:
switch (currentAuthType) {
case AUTH_SHAREDKEY:
case AUTH_ENCRYPT:
param->value = 1;
break;
default:
param->value = 0;
break;
}
break;
case IW_AUTH_80211_AUTH_ALG:
switch (currentAuthType) {
case AUTH_SHAREDKEY:
param->value = IW_AUTH_ALG_SHARED_KEY;
break;
case AUTH_ENCRYPT:
default:
param->value = IW_AUTH_ALG_OPEN_SYSTEM;
break;
}
break;
case IW_AUTH_WPA_ENABLED:
param->value = 0;
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int airo_set_txpow(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
CapabilityRid cap_rid;
int i;
int rc = -EINVAL;
__le16 v = cpu_to_le16(vwrq->value);
readCapabilityRid(local, &cap_rid, 1);
if (vwrq->disabled) {
set_bit (FLAG_RADIO_OFF, &local->flags);
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
if (vwrq->flags != IW_TXPOW_MWATT) {
return -EINVAL;
}
clear_bit (FLAG_RADIO_OFF, &local->flags);
for (i = 0; i < 8 && cap_rid.txPowerLevels[i]; i++)
if (v == cap_rid.txPowerLevels[i]) {
readConfigRid(local, 1);
local->config.txPower = v;
set_bit (FLAG_COMMIT, &local->flags);
rc = -EINPROGRESS;
break;
}
return rc;
}
static int airo_get_txpow(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
readConfigRid(local, 1);
vwrq->value = le16_to_cpu(local->config.txPower);
vwrq->fixed = 1;
vwrq->disabled = test_bit(FLAG_RADIO_OFF, &local->flags);
vwrq->flags = IW_TXPOW_MWATT;
return 0;
}
static int airo_set_retry(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
int rc = -EINVAL;
if(vwrq->disabled) {
return -EINVAL;
}
readConfigRid(local, 1);
if(vwrq->flags & IW_RETRY_LIMIT) {
__le16 v = cpu_to_le16(vwrq->value);
if(vwrq->flags & IW_RETRY_LONG)
local->config.longRetryLimit = v;
else if (vwrq->flags & IW_RETRY_SHORT)
local->config.shortRetryLimit = v;
else {
local->config.longRetryLimit = v;
local->config.shortRetryLimit = v;
}
set_bit (FLAG_COMMIT, &local->flags);
rc = -EINPROGRESS;
}
if(vwrq->flags & IW_RETRY_LIFETIME) {
local->config.txLifetime = cpu_to_le16(vwrq->value / 1024);
set_bit (FLAG_COMMIT, &local->flags);
rc = -EINPROGRESS;
}
return rc;
}
static int airo_get_retry(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
vwrq->disabled = 0;
readConfigRid(local, 1);
if((vwrq->flags & IW_RETRY_TYPE) == IW_RETRY_LIFETIME) {
vwrq->flags = IW_RETRY_LIFETIME;
vwrq->value = le16_to_cpu(local->config.txLifetime) * 1024;
} else if((vwrq->flags & IW_RETRY_LONG)) {
vwrq->flags = IW_RETRY_LIMIT | IW_RETRY_LONG;
vwrq->value = le16_to_cpu(local->config.longRetryLimit);
} else {
vwrq->flags = IW_RETRY_LIMIT;
vwrq->value = le16_to_cpu(local->config.shortRetryLimit);
if(local->config.shortRetryLimit != local->config.longRetryLimit)
vwrq->flags |= IW_RETRY_SHORT;
}
return 0;
}
static int airo_get_range(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
struct iw_range *range = (struct iw_range *) extra;
CapabilityRid cap_rid;
int i;
int k;
readCapabilityRid(local, &cap_rid, 1);
dwrq->length = sizeof(struct iw_range);
memset(range, 0, sizeof(*range));
range->min_nwid = 0x0000;
range->max_nwid = 0x0000;
range->num_channels = 14;
k = 0;
for(i = 0; i < 14; i++) {
range->freq[k].i = i + 1;
range->freq[k].m = ieee80211_dsss_chan_to_freq(i + 1) * 100000;
range->freq[k++].e = 1;
}
range->num_frequency = k;
range->sensitivity = 65535;
if (local->rssi)
range->max_qual.qual = 100;
else
range->max_qual.qual = airo_get_max_quality(&cap_rid);
range->max_qual.level = 0x100 - 120;
range->max_qual.noise = 0x100 - 120;
if (local->rssi) {
range->avg_qual.qual = 50;
range->avg_qual.level = 0x100 - 70;
} else {
range->avg_qual.qual = airo_get_avg_quality(&cap_rid);
range->avg_qual.level = 0x100 - 80;
}
range->avg_qual.noise = 0x100 - 85;
for(i = 0 ; i < 8 ; i++) {
range->bitrate[i] = cap_rid.supportedRates[i] * 500000;
if(range->bitrate[i] == 0)
break;
}
range->num_bitrates = i;
if(i > 2)
range->throughput = 5000 * 1000;
else
range->throughput = 1500 * 1000;
range->min_rts = 0;
range->max_rts = AIRO_DEF_MTU;
range->min_frag = 256;
range->max_frag = AIRO_DEF_MTU;
if(cap_rid.softCap & cpu_to_le16(2)) {
range->encoding_size[0] = 5;
if (cap_rid.softCap & cpu_to_le16(0x100)) {
range->encoding_size[1] = 13;
range->num_encoding_sizes = 2;
} else
range->num_encoding_sizes = 1;
range->max_encoding_tokens =
cap_rid.softCap & cpu_to_le16(0x80) ? 4 : 1;
} else {
range->num_encoding_sizes = 0;
range->max_encoding_tokens = 0;
}
range->min_pmp = 0;
range->max_pmp = 5000000;
range->min_pmt = 0;
range->max_pmt = 65535 * 1024;
range->pmp_flags = IW_POWER_PERIOD;
range->pmt_flags = IW_POWER_TIMEOUT;
range->pm_capa = IW_POWER_PERIOD | IW_POWER_TIMEOUT | IW_POWER_ALL_R;
for(i = 0 ; i < 8 ; i++) {
range->txpower[i] = le16_to_cpu(cap_rid.txPowerLevels[i]);
if(range->txpower[i] == 0)
break;
}
range->num_txpower = i;
range->txpower_capa = IW_TXPOW_MWATT;
range->we_version_source = 19;
range->we_version_compiled = WIRELESS_EXT;
range->retry_capa = IW_RETRY_LIMIT | IW_RETRY_LIFETIME;
range->retry_flags = IW_RETRY_LIMIT;
range->r_time_flags = IW_RETRY_LIFETIME;
range->min_retry = 1;
range->max_retry = 65535;
range->min_r_time = 1024;
range->max_r_time = 65535 * 1024;
range->event_capa[0] = (IW_EVENT_CAPA_K_0 |
IW_EVENT_CAPA_MASK(SIOCGIWTHRSPY) |
IW_EVENT_CAPA_MASK(SIOCGIWAP) |
IW_EVENT_CAPA_MASK(SIOCGIWSCAN));
range->event_capa[1] = IW_EVENT_CAPA_K_1;
range->event_capa[4] = IW_EVENT_CAPA_MASK(IWEVTXDROP);
return 0;
}
static int airo_set_power(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
readConfigRid(local, 1);
if (vwrq->disabled) {
if (sniffing_mode(local))
return -EINVAL;
local->config.powerSaveMode = POWERSAVE_CAM;
local->config.rmode &= ~RXMODE_MASK;
local->config.rmode |= RXMODE_BC_MC_ADDR;
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
if ((vwrq->flags & IW_POWER_TYPE) == IW_POWER_TIMEOUT) {
local->config.fastListenDelay = cpu_to_le16((vwrq->value + 500) / 1024);
local->config.powerSaveMode = POWERSAVE_PSPCAM;
set_bit (FLAG_COMMIT, &local->flags);
} else if ((vwrq->flags & IW_POWER_TYPE) == IW_POWER_PERIOD) {
local->config.fastListenInterval =
local->config.listenInterval =
cpu_to_le16((vwrq->value + 500) / 1024);
local->config.powerSaveMode = POWERSAVE_PSPCAM;
set_bit (FLAG_COMMIT, &local->flags);
}
switch (vwrq->flags & IW_POWER_MODE) {
case IW_POWER_UNICAST_R:
if (sniffing_mode(local))
return -EINVAL;
local->config.rmode &= ~RXMODE_MASK;
local->config.rmode |= RXMODE_ADDR;
set_bit (FLAG_COMMIT, &local->flags);
break;
case IW_POWER_ALL_R:
if (sniffing_mode(local))
return -EINVAL;
local->config.rmode &= ~RXMODE_MASK;
local->config.rmode |= RXMODE_BC_MC_ADDR;
set_bit (FLAG_COMMIT, &local->flags);
case IW_POWER_ON:
break;
default:
return -EINVAL;
}
return -EINPROGRESS;
}
static int airo_get_power(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
__le16 mode;
readConfigRid(local, 1);
mode = local->config.powerSaveMode;
if ((vwrq->disabled = (mode == POWERSAVE_CAM)))
return 0;
if ((vwrq->flags & IW_POWER_TYPE) == IW_POWER_TIMEOUT) {
vwrq->value = le16_to_cpu(local->config.fastListenDelay) * 1024;
vwrq->flags = IW_POWER_TIMEOUT;
} else {
vwrq->value = le16_to_cpu(local->config.fastListenInterval) * 1024;
vwrq->flags = IW_POWER_PERIOD;
}
if ((local->config.rmode & RXMODE_MASK) == RXMODE_ADDR)
vwrq->flags |= IW_POWER_UNICAST_R;
else
vwrq->flags |= IW_POWER_ALL_R;
return 0;
}
static int airo_set_sens(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
readConfigRid(local, 1);
local->config.rssiThreshold =
cpu_to_le16(vwrq->disabled ? RSSI_DEFAULT : vwrq->value);
set_bit (FLAG_COMMIT, &local->flags);
return -EINPROGRESS;
}
static int airo_get_sens(struct net_device *dev,
struct iw_request_info *info,
struct iw_param *vwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
readConfigRid(local, 1);
vwrq->value = le16_to_cpu(local->config.rssiThreshold);
vwrq->disabled = (vwrq->value == 0);
vwrq->fixed = 1;
return 0;
}
static int airo_get_aplist(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
struct sockaddr *address = (struct sockaddr *) extra;
struct iw_quality *qual;
BSSListRid BSSList;
int i;
int loseSync = capable(CAP_NET_ADMIN) ? 1: -1;
qual = kmalloc(IW_MAX_AP * sizeof(*qual), GFP_KERNEL);
if (!qual)
return -ENOMEM;
for (i = 0; i < IW_MAX_AP; i++) {
u16 dBm;
if (readBSSListRid(local, loseSync, &BSSList))
break;
loseSync = 0;
memcpy(address[i].sa_data, BSSList.bssid, ETH_ALEN);
address[i].sa_family = ARPHRD_ETHER;
dBm = le16_to_cpu(BSSList.dBm);
if (local->rssi) {
qual[i].level = 0x100 - dBm;
qual[i].qual = airo_dbm_to_pct(local->rssi, dBm);
qual[i].updated = IW_QUAL_QUAL_UPDATED
| IW_QUAL_LEVEL_UPDATED
| IW_QUAL_DBM;
} else {
qual[i].level = (dBm + 321) / 2;
qual[i].qual = 0;
qual[i].updated = IW_QUAL_QUAL_INVALID
| IW_QUAL_LEVEL_UPDATED
| IW_QUAL_DBM;
}
qual[i].noise = local->wstats.qual.noise;
if (BSSList.index == cpu_to_le16(0xffff))
break;
}
if (!i) {
StatusRid status_rid;
readStatusRid(local, &status_rid, 1);
for (i = 0;
i < min(IW_MAX_AP, 4) &&
(status_rid.bssid[i][0]
& status_rid.bssid[i][1]
& status_rid.bssid[i][2]
& status_rid.bssid[i][3]
& status_rid.bssid[i][4]
& status_rid.bssid[i][5])!=0xff &&
(status_rid.bssid[i][0]
| status_rid.bssid[i][1]
| status_rid.bssid[i][2]
| status_rid.bssid[i][3]
| status_rid.bssid[i][4]
| status_rid.bssid[i][5]);
i++) {
memcpy(address[i].sa_data,
status_rid.bssid[i], ETH_ALEN);
address[i].sa_family = ARPHRD_ETHER;
}
} else {
dwrq->flags = 1;
memcpy(extra + sizeof(struct sockaddr) * i, qual,
sizeof(struct iw_quality) * i);
}
dwrq->length = i;
kfree(qual);
return 0;
}
static int airo_set_scan(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *ai = dev->ml_priv;
Cmd cmd;
Resp rsp;
int wake = 0;
if (ai->flags & FLAG_RADIO_MASK) return -ENETDOWN;
if (down_interruptible(&ai->sem))
return -ERESTARTSYS;
if (ai->scan_timeout > 0)
goto out;
ai->scan_timeout = RUN_AT(3*HZ);
memset(&cmd, 0, sizeof(cmd));
cmd.cmd=CMD_LISTBSS;
issuecommand(ai, &cmd, &rsp);
wake = 1;
out:
up(&ai->sem);
if (wake)
wake_up_interruptible(&ai->thr_wait);
return 0;
}
static inline char *airo_translate_scan(struct net_device *dev,
struct iw_request_info *info,
char *current_ev,
char *end_buf,
BSSListRid *bss)
{
struct airo_info *ai = dev->ml_priv;
struct iw_event iwe;
__le16 capabilities;
char * current_val;
int i;
char * buf;
u16 dBm;
iwe.cmd = SIOCGIWAP;
iwe.u.ap_addr.sa_family = ARPHRD_ETHER;
memcpy(iwe.u.ap_addr.sa_data, bss->bssid, ETH_ALEN);
current_ev = iwe_stream_add_event(info, current_ev, end_buf,
&iwe, IW_EV_ADDR_LEN);
iwe.u.data.length = bss->ssidLen;
if(iwe.u.data.length > 32)
iwe.u.data.length = 32;
iwe.cmd = SIOCGIWESSID;
iwe.u.data.flags = 1;
current_ev = iwe_stream_add_point(info, current_ev, end_buf,
&iwe, bss->ssid);
iwe.cmd = SIOCGIWMODE;
capabilities = bss->cap;
if(capabilities & (CAP_ESS | CAP_IBSS)) {
if(capabilities & CAP_ESS)
iwe.u.mode = IW_MODE_MASTER;
else
iwe.u.mode = IW_MODE_ADHOC;
current_ev = iwe_stream_add_event(info, current_ev, end_buf,
&iwe, IW_EV_UINT_LEN);
}
iwe.cmd = SIOCGIWFREQ;
iwe.u.freq.m = le16_to_cpu(bss->dsChannel);
iwe.u.freq.m = ieee80211_dsss_chan_to_freq(iwe.u.freq.m) * 100000;
iwe.u.freq.e = 1;
current_ev = iwe_stream_add_event(info, current_ev, end_buf,
&iwe, IW_EV_FREQ_LEN);
dBm = le16_to_cpu(bss->dBm);
iwe.cmd = IWEVQUAL;
if (ai->rssi) {
iwe.u.qual.level = 0x100 - dBm;
iwe.u.qual.qual = airo_dbm_to_pct(ai->rssi, dBm);
iwe.u.qual.updated = IW_QUAL_QUAL_UPDATED
| IW_QUAL_LEVEL_UPDATED
| IW_QUAL_DBM;
} else {
iwe.u.qual.level = (dBm + 321) / 2;
iwe.u.qual.qual = 0;
iwe.u.qual.updated = IW_QUAL_QUAL_INVALID
| IW_QUAL_LEVEL_UPDATED
| IW_QUAL_DBM;
}
iwe.u.qual.noise = ai->wstats.qual.noise;
current_ev = iwe_stream_add_event(info, current_ev, end_buf,
&iwe, IW_EV_QUAL_LEN);
iwe.cmd = SIOCGIWENCODE;
if(capabilities & CAP_PRIVACY)
iwe.u.data.flags = IW_ENCODE_ENABLED | IW_ENCODE_NOKEY;
else
iwe.u.data.flags = IW_ENCODE_DISABLED;
iwe.u.data.length = 0;
current_ev = iwe_stream_add_point(info, current_ev, end_buf,
&iwe, bss->ssid);
current_val = current_ev + iwe_stream_lcp_len(info);
iwe.cmd = SIOCGIWRATE;
iwe.u.bitrate.fixed = iwe.u.bitrate.disabled = 0;
for(i = 0 ; i < 8 ; i++) {
if(bss->rates[i] == 0)
break;
iwe.u.bitrate.value = ((bss->rates[i] & 0x7f) * 500000);
current_val = iwe_stream_add_value(info, current_ev,
current_val, end_buf,
&iwe, IW_EV_PARAM_LEN);
}
if ((current_val - current_ev) > iwe_stream_lcp_len(info))
current_ev = current_val;
buf = kmalloc(30, GFP_KERNEL);
if (buf) {
iwe.cmd = IWEVCUSTOM;
sprintf(buf, "bcn_int=%d", bss->beaconInterval);
iwe.u.data.length = strlen(buf);
current_ev = iwe_stream_add_point(info, current_ev, end_buf,
&iwe, buf);
kfree(buf);
}
if (test_bit(FLAG_WPA_CAPABLE, &ai->flags)) {
unsigned int num_null_ies = 0;
u16 length = sizeof (bss->extra.iep);
u8 *ie = (void *)&bss->extra.iep;
while ((length >= 2) && (num_null_ies < 2)) {
if (2 + ie[1] > length) {
break;
}
switch (ie[0]) {
case WLAN_EID_SSID:
if (!ie[1])
num_null_ies++;
break;
case WLAN_EID_VENDOR_SPECIFIC:
if (ie[1] >= 4 &&
ie[2] == 0x00 &&
ie[3] == 0x50 &&
ie[4] == 0xf2 &&
ie[5] == 0x01) {
iwe.cmd = IWEVGENIE;
iwe.u.data.length = min(ie[1] + 2,
64);
current_ev = iwe_stream_add_point(
info, current_ev,
end_buf, &iwe, ie);
}
break;
case WLAN_EID_RSN:
iwe.cmd = IWEVGENIE;
iwe.u.data.length = min(ie[1] + 2, 64);
current_ev = iwe_stream_add_point(
info, current_ev, end_buf,
&iwe, ie);
break;
default:
break;
}
length -= 2 + ie[1];
ie += 2 + ie[1];
}
}
return current_ev;
}
static int airo_get_scan(struct net_device *dev,
struct iw_request_info *info,
struct iw_point *dwrq,
char *extra)
{
struct airo_info *ai = dev->ml_priv;
BSSListElement *net;
int err = 0;
char *current_ev = extra;
if (ai->scan_timeout > 0)
return -EAGAIN;
if (down_interruptible(&ai->sem))
return -EAGAIN;
list_for_each_entry (net, &ai->network_list, list) {
current_ev = airo_translate_scan(dev, info, current_ev,
extra + dwrq->length,
&net->bss);
if((extra + dwrq->length - current_ev) <= IW_EV_ADDR_LEN) {
err = -E2BIG;
goto out;
}
}
dwrq->length = (current_ev - extra);
dwrq->flags = 0;
out:
up(&ai->sem);
return err;
}
static int airo_config_commit(struct net_device *dev,
struct iw_request_info *info,
void *zwrq,
char *extra)
{
struct airo_info *local = dev->ml_priv;
if (!test_bit (FLAG_COMMIT, &local->flags))
return 0;
disable_MAC(local, 1);
if (test_bit (FLAG_RESET, &local->flags)) {
APListRid APList_rid;
SsidRid SSID_rid;
readAPListRid(local, &APList_rid);
readSsidRid(local, &SSID_rid);
if (test_bit(FLAG_MPI,&local->flags))
setup_card(local, dev->dev_addr, 1 );
else
reset_airo_card(dev);
disable_MAC(local, 1);
writeSsidRid(local, &SSID_rid, 1);
writeAPListRid(local, &APList_rid, 1);
}
if (down_interruptible(&local->sem))
return -ERESTARTSYS;
writeConfigRid(local, 0);
enable_MAC(local, 0);
if (test_bit (FLAG_RESET, &local->flags))
airo_set_promisc(local);
else
up(&local->sem);
return 0;
}
static int airo_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
int rc = 0;
struct airo_info *ai = dev->ml_priv;
if (ai->power.event)
return 0;
switch (cmd) {
#ifdef CISCO_EXT
case AIROIDIFC:
#ifdef AIROOLDIDIFC
case AIROOLDIDIFC:
#endif
{
int val = AIROMAGIC;
aironet_ioctl com;
if (copy_from_user(&com,rq->ifr_data,sizeof(com)))
rc = -EFAULT;
else if (copy_to_user(com.data,(char *)&val,sizeof(val)))
rc = -EFAULT;
}
break;
case AIROIOCTL:
#ifdef AIROOLDIOCTL
case AIROOLDIOCTL:
#endif
{
aironet_ioctl com;
if (copy_from_user(&com,rq->ifr_data,sizeof(com))) {
rc = -EFAULT;
break;
}
if ( com.command == AIRORSWVERSION ) {
if (copy_to_user(com.data, swversion, sizeof(swversion)))
rc = -EFAULT;
else
rc = 0;
}
else if ( com.command <= AIRORRID)
rc = readrids(dev,&com);
else if ( com.command >= AIROPCAP && com.command <= (AIROPLEAPUSR+2) )
rc = writerids(dev,&com);
else if ( com.command >= AIROFLSHRST && com.command <= AIRORESTART )
rc = flashcard(dev,&com);
else
rc = -EINVAL;
}
break;
#endif
default:
rc = -EOPNOTSUPP;
}
return rc;
}
static void airo_read_wireless_stats(struct airo_info *local)
{
StatusRid status_rid;
StatsRid stats_rid;
CapabilityRid cap_rid;
__le32 *vals = stats_rid.vals;
clear_bit(JOB_WSTATS, &local->jobs);
if (local->power.event) {
up(&local->sem);
return;
}
readCapabilityRid(local, &cap_rid, 0);
readStatusRid(local, &status_rid, 0);
readStatsRid(local, &stats_rid, RID_STATS, 0);
up(&local->sem);
local->wstats.status = le16_to_cpu(status_rid.mode);
if (local->rssi) {
local->wstats.qual.level =
airo_rssi_to_dbm(local->rssi,
le16_to_cpu(status_rid.sigQuality));
local->wstats.qual.qual =
le16_to_cpu(status_rid.normalizedSignalStrength);
} else {
local->wstats.qual.level =
(le16_to_cpu(status_rid.normalizedSignalStrength) + 321) / 2;
local->wstats.qual.qual = airo_get_quality(&status_rid, &cap_rid);
}
if (le16_to_cpu(status_rid.len) >= 124) {
local->wstats.qual.noise = 0x100 - status_rid.noisedBm;
local->wstats.qual.updated = IW_QUAL_ALL_UPDATED | IW_QUAL_DBM;
} else {
local->wstats.qual.noise = 0;
local->wstats.qual.updated = IW_QUAL_QUAL_UPDATED | IW_QUAL_LEVEL_UPDATED | IW_QUAL_NOISE_INVALID | IW_QUAL_DBM;
}
local->wstats.discard.nwid = le32_to_cpu(vals[56]) +
le32_to_cpu(vals[57]) +
le32_to_cpu(vals[58]);
local->wstats.discard.code = le32_to_cpu(vals[6]);
local->wstats.discard.fragment = le32_to_cpu(vals[30]);
local->wstats.discard.retries = le32_to_cpu(vals[10]);
local->wstats.discard.misc = le32_to_cpu(vals[1]) +
le32_to_cpu(vals[32]);
local->wstats.miss.beacon = le32_to_cpu(vals[34]);
}
static struct iw_statistics *airo_get_wireless_stats(struct net_device *dev)
{
struct airo_info *local = dev->ml_priv;
if (!test_bit(JOB_WSTATS, &local->jobs)) {
if (down_trylock(&local->sem) != 0) {
set_bit(JOB_WSTATS, &local->jobs);
wake_up_interruptible(&local->thr_wait);
} else
airo_read_wireless_stats(local);
}
return &local->wstats;
}
static int readrids(struct net_device *dev, aironet_ioctl *comp) {
unsigned short ridcode;
unsigned char *iobuf;
int len;
struct airo_info *ai = dev->ml_priv;
if (test_bit(FLAG_FLASHING, &ai->flags))
return -EIO;
switch(comp->command)
{
case AIROGCAP: ridcode = RID_CAPABILITIES; break;
case AIROGCFG: ridcode = RID_CONFIG;
if (test_bit(FLAG_COMMIT, &ai->flags)) {
disable_MAC (ai, 1);
writeConfigRid (ai, 1);
enable_MAC(ai, 1);
}
break;
case AIROGSLIST: ridcode = RID_SSID; break;
case AIROGVLIST: ridcode = RID_APLIST; break;
case AIROGDRVNAM: ridcode = RID_DRVNAME; break;
case AIROGEHTENC: ridcode = RID_ETHERENCAP; break;
case AIROGWEPKTMP: ridcode = RID_WEP_TEMP;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
break;
case AIROGWEPKNV: ridcode = RID_WEP_PERM;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
break;
case AIROGSTAT: ridcode = RID_STATUS; break;
case AIROGSTATSD32: ridcode = RID_STATSDELTA; break;
case AIROGSTATSC32: ridcode = RID_STATS; break;
case AIROGMICSTATS:
if (copy_to_user(comp->data, &ai->micstats,
min((int)comp->len,(int)sizeof(ai->micstats))))
return -EFAULT;
return 0;
case AIRORRID: ridcode = comp->ridnum; break;
default:
return -EINVAL;
break;
}
if ((iobuf = kmalloc(RIDSIZE, GFP_KERNEL)) == NULL)
return -ENOMEM;
PC4500_readrid(ai,ridcode,iobuf,RIDSIZE, 1);
len = comp->len;
if (copy_to_user(comp->data, iobuf, min(len, (int)RIDSIZE))) {
kfree (iobuf);
return -EFAULT;
}
kfree (iobuf);
return 0;
}
static int writerids(struct net_device *dev, aironet_ioctl *comp) {
struct airo_info *ai = dev->ml_priv;
int ridcode;
int enabled;
static int (* writer)(struct airo_info *, u16 rid, const void *, int, int);
unsigned char *iobuf;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
if (test_bit(FLAG_FLASHING, &ai->flags))
return -EIO;
ridcode = 0;
writer = do_writerid;
switch(comp->command)
{
case AIROPSIDS: ridcode = RID_SSID; break;
case AIROPCAP: ridcode = RID_CAPABILITIES; break;
case AIROPAPLIST: ridcode = RID_APLIST; break;
case AIROPCFG: ai->config.len = 0;
clear_bit(FLAG_COMMIT, &ai->flags);
ridcode = RID_CONFIG; break;
case AIROPWEPKEYNV: ridcode = RID_WEP_PERM; break;
case AIROPLEAPUSR: ridcode = RID_LEAPUSERNAME; break;
case AIROPLEAPPWD: ridcode = RID_LEAPPASSWORD; break;
case AIROPWEPKEY: ridcode = RID_WEP_TEMP; writer = PC4500_writerid;
break;
case AIROPLEAPUSR+1: ridcode = 0xFF2A; break;
case AIROPLEAPUSR+2: ridcode = 0xFF2B; break;
case AIROPMACON:
if (enable_MAC(ai, 1) != 0)
return -EIO;
return 0;
case AIROPMACOFF:
disable_MAC(ai, 1);
return 0;
case AIROPSTCLR:
if ((iobuf = kmalloc(RIDSIZE, GFP_KERNEL)) == NULL)
return -ENOMEM;
PC4500_readrid(ai,RID_STATSDELTACLEAR,iobuf,RIDSIZE, 1);
enabled = ai->micstats.enabled;
memset(&ai->micstats,0,sizeof(ai->micstats));
ai->micstats.enabled = enabled;
if (copy_to_user(comp->data, iobuf,
min((int)comp->len, (int)RIDSIZE))) {
kfree (iobuf);
return -EFAULT;
}
kfree (iobuf);
return 0;
default:
return -EOPNOTSUPP;
}
if(comp->len > RIDSIZE)
return -EINVAL;
if ((iobuf = kmalloc(RIDSIZE, GFP_KERNEL)) == NULL)
return -ENOMEM;
if (copy_from_user(iobuf,comp->data,comp->len)) {
kfree (iobuf);
return -EFAULT;
}
if (comp->command == AIROPCFG) {
ConfigRid *cfg = (ConfigRid *)iobuf;
if (test_bit(FLAG_MIC_CAPABLE, &ai->flags))
cfg->opmode |= MODE_MIC;
if ((cfg->opmode & MODE_CFG_MASK) == MODE_STA_IBSS)
set_bit (FLAG_ADHOC, &ai->flags);
else
clear_bit (FLAG_ADHOC, &ai->flags);
}
if((*writer)(ai, ridcode, iobuf,comp->len,1)) {
kfree (iobuf);
return -EIO;
}
kfree (iobuf);
return 0;
}
static int flashcard(struct net_device *dev, aironet_ioctl *comp) {
int z;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
switch(comp->command)
{
case AIROFLSHRST:
return cmdreset((struct airo_info *)dev->ml_priv);
case AIROFLSHSTFL:
if (!AIRO_FLASH(dev) &&
(AIRO_FLASH(dev) = kmalloc(FLASHSIZE, GFP_KERNEL)) == NULL)
return -ENOMEM;
return setflashmode((struct airo_info *)dev->ml_priv);
case AIROFLSHGCHR:
if(comp->len != sizeof(int))
return -EINVAL;
if (copy_from_user(&z,comp->data,comp->len))
return -EFAULT;
return flashgchar((struct airo_info *)dev->ml_priv, z, 8000);
case AIROFLSHPCHR:
if(comp->len != sizeof(int))
return -EINVAL;
if (copy_from_user(&z,comp->data,comp->len))
return -EFAULT;
return flashpchar((struct airo_info *)dev->ml_priv, z, 8000);
case AIROFLPUTBUF:
if (!AIRO_FLASH(dev))
return -ENOMEM;
if(comp->len > FLASHSIZE)
return -EINVAL;
if (copy_from_user(AIRO_FLASH(dev), comp->data, comp->len))
return -EFAULT;
flashputbuf((struct airo_info *)dev->ml_priv);
return 0;
case AIRORESTART:
if (flashrestart((struct airo_info *)dev->ml_priv, dev))
return -EIO;
return 0;
}
return -EINVAL;
}
static int cmdreset(struct airo_info *ai) {
disable_MAC(ai, 1);
if(!waitbusy (ai)){
airo_print_info(ai->dev->name, "Waitbusy hang before RESET");
return -EBUSY;
}
OUT4500(ai,COMMAND,CMD_SOFTRESET);
ssleep(1);
if(!waitbusy (ai)){
airo_print_info(ai->dev->name, "Waitbusy hang AFTER RESET");
return -EBUSY;
}
return 0;
}
static int setflashmode (struct airo_info *ai) {
set_bit (FLAG_FLASHING, &ai->flags);
OUT4500(ai, SWS0, FLASH_COMMAND);
OUT4500(ai, SWS1, FLASH_COMMAND);
if (probe) {
OUT4500(ai, SWS0, FLASH_COMMAND);
OUT4500(ai, COMMAND,0x10);
} else {
OUT4500(ai, SWS2, FLASH_COMMAND);
OUT4500(ai, SWS3, FLASH_COMMAND);
OUT4500(ai, COMMAND,0);
}
msleep(500);
if(!waitbusy(ai)) {
clear_bit (FLAG_FLASHING, &ai->flags);
airo_print_info(ai->dev->name, "Waitbusy hang after setflash mode");
return -EIO;
}
return 0;
}
static int flashpchar(struct airo_info *ai,int byte,int dwelltime) {
int echo;
int waittime;
byte |= 0x8000;
if(dwelltime == 0 )
dwelltime = 200;
waittime=dwelltime;
while ((IN4500 (ai, SWS0) & 0x8000) && waittime > 0) {
udelay (50);
waittime -= 50;
}
if(waittime <= 0 ){
airo_print_info(ai->dev->name, "flash putchar busywait timeout!");
return -EBUSY;
}
do {
OUT4500(ai,SWS0,byte);
udelay(50);
dwelltime -= 50;
echo = IN4500(ai,SWS1);
} while (dwelltime >= 0 && echo != byte);
OUT4500(ai,SWS1,0);
return (echo == byte) ? 0 : -EIO;
}
static int flashgchar(struct airo_info *ai,int matchbyte,int dwelltime){
int rchar;
unsigned char rbyte=0;
do {
rchar = IN4500(ai,SWS1);
if(dwelltime && !(0x8000 & rchar)){
dwelltime -= 10;
mdelay(10);
continue;
}
rbyte = 0xff & rchar;
if( (rbyte == matchbyte) && (0x8000 & rchar) ){
OUT4500(ai,SWS1,0);
return 0;
}
if( rbyte == 0x81 || rbyte == 0x82 || rbyte == 0x83 || rbyte == 0x1a || 0xffff == rchar)
break;
OUT4500(ai,SWS1,0);
}while(dwelltime > 0);
return -EIO;
}
static int flashputbuf(struct airo_info *ai){
int nwords;
if (test_bit(FLAG_MPI,&ai->flags))
memcpy_toio(ai->pciaux + 0x8000, ai->flash, FLASHSIZE);
else {
OUT4500(ai,AUXPAGE,0x100);
OUT4500(ai,AUXOFF,0);
for(nwords=0;nwords != FLASHSIZE / 2;nwords++){
OUT4500(ai,AUXDATA,ai->flash[nwords] & 0xffff);
}
}
OUT4500(ai,SWS0,0x8000);
return 0;
}
static int flashrestart(struct airo_info *ai,struct net_device *dev){
int i,status;
ssleep(1);
clear_bit (FLAG_FLASHING, &ai->flags);
if (test_bit(FLAG_MPI, &ai->flags)) {
status = mpi_init_descriptors(ai);
if (status != SUCCESS)
return status;
}
status = setup_card(ai, dev->dev_addr, 1);
if (!test_bit(FLAG_MPI,&ai->flags))
for( i = 0; i < MAX_FIDS; i++ ) {
ai->fids[i] = transmit_allocate
( ai, AIRO_DEF_MTU, i >= MAX_FIDS / 2 );
}
ssleep(1);
return status;
}
