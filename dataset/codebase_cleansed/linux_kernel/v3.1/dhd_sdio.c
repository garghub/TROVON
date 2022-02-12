static void
r_sdreg32(struct brcmf_bus *bus, u32 *regvar, u32 reg_offset, u32 *retryvar)
{
*retryvar = 0;
do {
*regvar = R_REG(bus->ci->buscorebase + reg_offset, u32);
} while (brcmf_sdcard_regfail(bus->card) &&
(++(*retryvar) <= retry_limit));
if (*retryvar) {
bus->regfails += (*retryvar-1);
if (*retryvar > retry_limit) {
BRCMF_ERROR(("FAILED READ %Xh\n", reg_offset));
*regvar = 0;
}
}
}
static void
w_sdreg32(struct brcmf_bus *bus, u32 regval, u32 reg_offset, u32 *retryvar)
{
*retryvar = 0;
do {
brcmf_sdcard_reg_write(NULL, bus->ci->buscorebase + reg_offset,
sizeof(u32), regval);
} while (brcmf_sdcard_regfail(bus->card) &&
(++(*retryvar) <= retry_limit));
if (*retryvar) {
bus->regfails += (*retryvar-1);
if (*retryvar > retry_limit)
BRCMF_ERROR(("FAILED REGISTER WRITE"
" %Xh\n", reg_offset));
}
}
static void brcmf_sdbrcm_pktfree2(struct brcmf_bus *bus, struct sk_buff *pkt)
{
if ((bus->bus != SPI_BUS) || bus->usebufpool)
brcmu_pkt_buf_free_skb(pkt);
}
static void brcmf_sdbrcm_setmemsize(struct brcmf_bus *bus, int mem_size)
{
s32 min_size = DONGLE_MIN_MEMSIZE;
BRCMF_ERROR(("user: Restrict the dongle ram size to %d, min %d\n",
brcmf_dongle_memsize, min_size));
if ((brcmf_dongle_memsize > min_size) &&
(brcmf_dongle_memsize < (s32) bus->orig_ramsize))
bus->ramsize = brcmf_dongle_memsize;
}
static int brcmf_sdbrcm_set_siaddr_window(struct brcmf_bus *bus, u32 address)
{
int err = 0;
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1, SBSDIO_FUNC1_SBADDRLOW,
(address >> 8) & SBSDIO_SBADDRLOW_MASK, &err);
if (!err)
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1,
SBSDIO_FUNC1_SBADDRMID,
(address >> 16) & SBSDIO_SBADDRMID_MASK, &err);
if (!err)
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1,
SBSDIO_FUNC1_SBADDRHIGH,
(address >> 24) & SBSDIO_SBADDRHIGH_MASK,
&err);
return err;
}
static int brcmf_sdbrcm_htclk(struct brcmf_bus *bus, bool on, bool pendok)
{
int err;
u8 clkctl, clkreq, devctl;
struct brcmf_sdio_card *card;
BRCMF_TRACE(("%s: Enter\n", __func__));
clkctl = 0;
card = bus->card;
if (on) {
clkreq =
bus->alp_only ? SBSDIO_ALP_AVAIL_REQ : SBSDIO_HT_AVAIL_REQ;
if ((bus->ci->chip == BCM4329_CHIP_ID)
&& (bus->ci->chiprev == 0))
clkreq |= SBSDIO_FORCE_ALP;
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, clkreq, &err);
if (err) {
BRCMF_ERROR(("%s: HT Avail request error: %d\n",
__func__, err));
return -EBADE;
}
if (pendok && ((bus->ci->buscoretype == PCMCIA_CORE_ID)
&& (bus->ci->buscorerev == 9))) {
u32 dummy, retries;
r_sdreg32(bus, &dummy,
offsetof(struct sdpcmd_regs, clockctlstatus),
&retries);
}
clkctl = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (err) {
BRCMF_ERROR(("%s: HT Avail read error: %d\n",
__func__, err));
return -EBADE;
}
if (!SBSDIO_CLKAV(clkctl, bus->alp_only) && pendok) {
devctl = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, &err);
if (err) {
BRCMF_ERROR(("%s: Devctl error setting CA:"
" %d\n", __func__, err));
return -EBADE;
}
devctl |= SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, devctl, &err);
BRCMF_INFO(("CLKCTL: set PENDING\n"));
bus->clkstate = CLK_PENDING;
return 0;
} else if (bus->clkstate == CLK_PENDING) {
devctl =
brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, &err);
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, devctl, &err);
}
if (!SBSDIO_CLKAV(clkctl, bus->alp_only)) {
BRCMF_SPINWAIT_SLEEP(sdioh_spinwait_sleep,
((clkctl =
brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
&err)),
!SBSDIO_CLKAV(clkctl, bus->alp_only)),
PMU_MAX_TRANSITION_DLY);
}
if (err) {
BRCMF_ERROR(("%s: HT Avail request error: %d\n",
__func__, err));
return -EBADE;
}
if (!SBSDIO_CLKAV(clkctl, bus->alp_only)) {
BRCMF_ERROR(("%s: HT Avail timeout (%d): "
"clkctl 0x%02x\n", __func__,
PMU_MAX_TRANSITION_DLY, clkctl));
return -EBADE;
}
bus->clkstate = CLK_AVAIL;
BRCMF_INFO(("CLKCTL: turned ON\n"));
#if defined(BCMDBG)
if (bus->alp_only != true) {
if (SBSDIO_ALPONLY(clkctl)) {
BRCMF_ERROR(("%s: HT Clock should be on.\n",
__func__));
}
}
#endif
bus->activity = true;
} else {
clkreq = 0;
if (bus->clkstate == CLK_PENDING) {
devctl = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, &err);
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, devctl, &err);
}
bus->clkstate = CLK_SDONLY;
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, clkreq, &err);
BRCMF_INFO(("CLKCTL: turned OFF\n"));
if (err) {
BRCMF_ERROR(("%s: Failed access turning clock off:"
" %d\n", __func__, err));
return -EBADE;
}
}
return 0;
}
static int brcmf_sdbrcm_sdclk(struct brcmf_bus *bus, bool on)
{
BRCMF_TRACE(("%s: Enter\n", __func__));
if (on)
bus->clkstate = CLK_SDONLY;
else
bus->clkstate = CLK_NONE;
return 0;
}
static int brcmf_sdbrcm_clkctl(struct brcmf_bus *bus, uint target, bool pendok)
{
#ifdef BCMDBG
uint oldstate = bus->clkstate;
#endif
BRCMF_TRACE(("%s: Enter\n", __func__));
if (bus->clkstate == target) {
if (target == CLK_AVAIL) {
brcmf_sdbrcm_wd_timer(bus, brcmf_watchdog_ms);
bus->activity = true;
}
return 0;
}
switch (target) {
case CLK_AVAIL:
if (bus->clkstate == CLK_NONE)
brcmf_sdbrcm_sdclk(bus, true);
brcmf_sdbrcm_htclk(bus, true, pendok);
brcmf_sdbrcm_wd_timer(bus, brcmf_watchdog_ms);
bus->activity = true;
break;
case CLK_SDONLY:
if (bus->clkstate == CLK_NONE)
brcmf_sdbrcm_sdclk(bus, true);
else if (bus->clkstate == CLK_AVAIL)
brcmf_sdbrcm_htclk(bus, false, false);
else
BRCMF_ERROR(("brcmf_sdbrcm_clkctl: request for %d -> %d"
"\n", bus->clkstate, target));
brcmf_sdbrcm_wd_timer(bus, brcmf_watchdog_ms);
break;
case CLK_NONE:
if (bus->clkstate == CLK_AVAIL)
brcmf_sdbrcm_htclk(bus, false, false);
brcmf_sdbrcm_sdclk(bus, false);
brcmf_sdbrcm_wd_timer(bus, 0);
break;
}
#ifdef BCMDBG
BRCMF_INFO(("brcmf_sdbrcm_clkctl: %d -> %d\n",
oldstate, bus->clkstate));
#endif
return 0;
}
int brcmf_sdbrcm_bussleep(struct brcmf_bus *bus, bool sleep)
{
struct brcmf_sdio_card *card = bus->card;
uint retries = 0;
BRCMF_INFO(("brcmf_sdbrcm_bussleep: request %s (currently %s)\n",
(sleep ? "SLEEP" : "WAKE"),
(bus->sleeping ? "SLEEP" : "WAKE")));
if (sleep == bus->sleeping)
return 0;
if (sleep) {
if (bus->dpc_sched || bus->rxskip || pktq_len(&bus->txq))
return -EBUSY;
brcmf_sdcard_intr_disable(bus->card);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
w_sdreg32(bus, SMB_USE_OOB,
offsetof(struct sdpcmd_regs, tosbmailbox), &retries);
if (retries > retry_limit)
BRCMF_ERROR(("CANNOT SIGNAL CHIP, "
"WILL NOT WAKE UP!!\n"));
brcmf_sdbrcm_clkctl(bus, CLK_SDONLY, false);
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
SBSDIO_FORCE_HW_CLKREQ_OFF, NULL);
if (bus->ci->chip != BCM4329_CHIP_ID
&& bus->ci->chip != BCM4319_CHIP_ID) {
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL,
SBSDIO_DEVCTL_PADS_ISO, NULL);
}
bus->sleeping = true;
} else {
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, 0, NULL);
if ((bus->ci->buscoretype == PCMCIA_CORE_ID)
&& (bus->ci->buscorerev >= 10))
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, 0, NULL);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
w_sdreg32(bus, 0, offsetof(struct sdpcmd_regs, tosbmailboxdata),
&retries);
if (retries <= retry_limit)
w_sdreg32(bus, SMB_DEV_INT,
offsetof(struct sdpcmd_regs, tosbmailbox),
&retries);
if (retries > retry_limit)
BRCMF_ERROR(("CANNOT SIGNAL CHIP TO CLEAR OOB!!\n"));
brcmf_sdbrcm_clkctl(bus, CLK_SDONLY, false);
bus->sleeping = false;
if (bus->intr && (bus->drvr->busstate == BRCMF_BUS_DATA)) {
bus->intdis = false;
brcmf_sdcard_intr_enable(bus->card);
}
}
return 0;
}
static int brcmf_sdbrcm_txpkt(struct brcmf_bus *bus, struct sk_buff *pkt, uint chan,
bool free_pkt)
{
int ret;
u8 *frame;
u16 len, pad = 0;
u32 swheader;
uint retries = 0;
struct brcmf_sdio_card *card;
struct sk_buff *new;
int i;
BRCMF_TRACE(("%s: Enter\n", __func__));
card = bus->card;
if (bus->drvr->dongle_reset) {
ret = -EPERM;
goto done;
}
frame = (u8 *) (pkt->data);
pad = ((unsigned long)frame % BRCMF_SDALIGN);
if (pad) {
if (skb_headroom(pkt) < pad) {
BRCMF_INFO(("%s: insufficient headroom %d for %d pad\n",
__func__, skb_headroom(pkt), pad));
bus->drvr->tx_realloc++;
new = brcmu_pkt_buf_get_skb(pkt->len + BRCMF_SDALIGN);
if (!new) {
BRCMF_ERROR(("%s: couldn't allocate new "
"%d-byte packet\n", __func__,
pkt->len + BRCMF_SDALIGN));
ret = -ENOMEM;
goto done;
}
PKTALIGN(new, pkt->len, BRCMF_SDALIGN);
memcpy(new->data, pkt->data, pkt->len);
if (free_pkt)
brcmu_pkt_buf_free_skb(pkt);
free_pkt = true;
pkt = new;
frame = (u8 *) (pkt->data);
pad = 0;
} else {
skb_push(pkt, pad);
frame = (u8 *) (pkt->data);
memset(frame, 0, pad + SDPCM_HDRLEN);
}
}
len = (u16) (pkt->len);
*(u16 *) frame = cpu_to_le16(len);
*(((u16 *) frame) + 1) = cpu_to_le16(~len);
swheader =
((chan << SDPCM_CHANNEL_SHIFT) & SDPCM_CHANNEL_MASK) | bus->tx_seq |
(((pad +
SDPCM_HDRLEN) << SDPCM_DOFFSET_SHIFT) & SDPCM_DOFFSET_MASK);
put_unaligned_le32(swheader, frame + SDPCM_FRAMETAG_LEN);
put_unaligned_le32(0, frame + SDPCM_FRAMETAG_LEN + sizeof(swheader));
#ifdef BCMDBG
tx_packets[pkt->priority]++;
if (BRCMF_BYTES_ON() &&
(((BRCMF_CTL_ON() && (chan == SDPCM_CONTROL_CHANNEL)) ||
(BRCMF_DATA_ON() && (chan != SDPCM_CONTROL_CHANNEL))))) {
printk(KERN_DEBUG "Tx Frame:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, frame, len);
} else if (BRCMF_HDRS_ON()) {
printk(KERN_DEBUG "TxHdr:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
frame, min_t(u16, len, 16));
}
#endif
if (bus->roundup && bus->blocksize && (len > bus->blocksize)) {
u16 pad = bus->blocksize - (len % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize))
len += pad;
} else if (len % BRCMF_SDALIGN) {
len += BRCMF_SDALIGN - (len % BRCMF_SDALIGN);
}
if (forcealign && (len & (ALIGNMENT - 1))) {
len = roundup(len, ALIGNMENT);
}
do {
ret = brcmf_sdbrcm_send_buf(bus, brcmf_sdcard_cur_sbwad(card),
SDIO_FUNC_2, F2SYNC, frame, len, pkt, NULL, NULL);
bus->f2txdata++;
if (ret < 0) {
BRCMF_INFO(("%s: sdio error %d, abort command and "
"terminate frame.\n", __func__, ret));
bus->tx_sderrs++;
brcmf_sdcard_abort(card, SDIO_FUNC_2);
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_FUNC1_FRAMECTRL, SFC_WF_TERM,
NULL);
bus->f1regdata++;
for (i = 0; i < 3; i++) {
u8 hi, lo;
hi = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCHI,
NULL);
lo = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCLO,
NULL);
bus->f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
}
}
if (ret == 0)
bus->tx_seq = (bus->tx_seq + 1) % SDPCM_SEQUENCE_WRAP;
} while ((ret < 0) && retrydata && retries++ < TXRETRIES);
done:
skb_pull(pkt, SDPCM_HDRLEN + pad);
brcmf_sdbrcm_sdunlock(bus);
brcmf_txcomplete(bus->drvr, pkt, ret != 0);
brcmf_sdbrcm_sdlock(bus);
if (free_pkt)
brcmu_pkt_buf_free_skb(pkt);
return ret;
}
int brcmf_sdbrcm_bus_txdata(struct brcmf_bus *bus, struct sk_buff *pkt)
{
int ret = -EBADE;
uint datalen, prec;
BRCMF_TRACE(("%s: Enter\n", __func__));
datalen = pkt->len;
#ifdef SDTEST
if (bus->ext_loop) {
u8 *data;
skb_push(pkt, SDPCM_TEST_HDRLEN);
data = pkt->data;
*data++ = SDPCM_TEST_ECHOREQ;
*data++ = (u8) bus->loopid++;
*data++ = (datalen >> 0);
*data++ = (datalen >> 8);
datalen += SDPCM_TEST_HDRLEN;
}
#endif
skb_push(pkt, SDPCM_HDRLEN);
prec = PRIO2PREC((pkt->priority & PRIOMASK));
if (brcmf_deferred_tx || bus->fcstate || pktq_len(&bus->txq)
|| bus->dpc_sched || (!DATAOK(bus))
|| (bus->flowcontrol & NBITVAL(prec))
|| (bus->clkstate != CLK_AVAIL)) {
BRCMF_TRACE(("%s: deferring pktq len %d\n", __func__,
pktq_len(&bus->txq)));
bus->fcqueued++;
spin_lock_bh(&bus->txqlock);
if (brcmf_c_prec_enq(bus->drvr, &bus->txq, pkt, prec) == false) {
skb_pull(pkt, SDPCM_HDRLEN);
brcmf_txcomplete(bus->drvr, pkt, false);
brcmu_pkt_buf_free_skb(pkt);
BRCMF_ERROR(("%s: out of bus->txq !!!\n", __func__));
ret = -ENOSR;
} else {
ret = 0;
}
spin_unlock_bh(&bus->txqlock);
if (pktq_len(&bus->txq) >= TXHI)
brcmf_txflowcontrol(bus->drvr, 0, ON);
#ifdef BCMDBG
if (pktq_plen(&bus->txq, prec) > qcount[prec])
qcount[prec] = pktq_plen(&bus->txq, prec);
#endif
if (brcmf_deferred_tx && !bus->dpc_sched) {
bus->dpc_sched = true;
brcmf_sdbrcm_sched_dpc(bus);
}
} else {
brcmf_sdbrcm_sdlock(bus);
BUS_WAKE(bus);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, true);
#ifndef SDTEST
BRCMF_TRACE(("%s: calling txpkt\n", __func__));
ret = brcmf_sdbrcm_txpkt(bus, pkt, SDPCM_DATA_CHANNEL, true);
#else
ret = brcmf_sdbrcm_txpkt(bus, pkt,
(bus->ext_loop ? SDPCM_TEST_CHANNEL :
SDPCM_DATA_CHANNEL), true);
#endif
if (ret)
bus->drvr->tx_errors++;
else
bus->drvr->dstats.tx_bytes += datalen;
if (bus->idletime == BRCMF_IDLE_IMMEDIATE &&
!bus->dpc_sched) {
bus->activity = false;
brcmf_sdbrcm_clkctl(bus, CLK_NONE, true);
}
brcmf_sdbrcm_sdunlock(bus);
}
return ret;
}
static uint brcmf_sdbrcm_sendfromq(struct brcmf_bus *bus, uint maxframes)
{
struct sk_buff *pkt;
u32 intstatus = 0;
uint retries = 0;
int ret = 0, prec_out;
uint cnt = 0;
uint datalen;
u8 tx_prec_map;
struct brcmf_pub *drvr = bus->drvr;
BRCMF_TRACE(("%s: Enter\n", __func__));
tx_prec_map = ~bus->flowcontrol;
for (cnt = 0; (cnt < maxframes) && DATAOK(bus); cnt++) {
spin_lock_bh(&bus->txqlock);
pkt = brcmu_pktq_mdeq(&bus->txq, tx_prec_map, &prec_out);
if (pkt == NULL) {
spin_unlock_bh(&bus->txqlock);
break;
}
spin_unlock_bh(&bus->txqlock);
datalen = pkt->len - SDPCM_HDRLEN;
#ifndef SDTEST
ret = brcmf_sdbrcm_txpkt(bus, pkt, SDPCM_DATA_CHANNEL, true);
#else
ret = brcmf_sdbrcm_txpkt(bus, pkt,
(bus->ext_loop ? SDPCM_TEST_CHANNEL :
SDPCM_DATA_CHANNEL), true);
#endif
if (ret)
bus->drvr->tx_errors++;
else
bus->drvr->dstats.tx_bytes += datalen;
if (!bus->intr && cnt) {
r_sdreg32(bus, &intstatus,
offsetof(struct sdpcmd_regs, intstatus),
&retries);
bus->f2txdata++;
if (brcmf_sdcard_regfail(bus->card))
break;
if (intstatus & bus->hostintmask)
bus->ipend = true;
}
}
if (drvr->up && (drvr->busstate == BRCMF_BUS_DATA) &&
drvr->txoff && (pktq_len(&bus->txq) < TXLOW))
brcmf_txflowcontrol(drvr, 0, OFF);
return cnt;
}
int
brcmf_sdbrcm_bus_txctl(struct brcmf_bus *bus, unsigned char *msg, uint msglen)
{
u8 *frame;
u16 len;
u32 swheader;
uint retries = 0;
struct brcmf_sdio_card *card = bus->card;
u8 doff = 0;
int ret = -1;
int i;
BRCMF_TRACE(("%s: Enter\n", __func__));
if (bus->drvr->dongle_reset)
return -EIO;
frame = msg - SDPCM_HDRLEN;
len = (msglen += SDPCM_HDRLEN);
if (brcmf_alignctl) {
doff = ((unsigned long)frame % BRCMF_SDALIGN);
if (doff) {
frame -= doff;
len += doff;
msglen += doff;
memset(frame, 0, doff + SDPCM_HDRLEN);
}
}
doff += SDPCM_HDRLEN;
if (bus->roundup && bus->blocksize && (len > bus->blocksize)) {
u16 pad = bus->blocksize - (len % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize))
len += pad;
} else if (len % BRCMF_SDALIGN) {
len += BRCMF_SDALIGN - (len % BRCMF_SDALIGN);
}
if (forcealign && (len & (ALIGNMENT - 1)))
len = roundup(len, ALIGNMENT);
brcmf_sdbrcm_sdlock(bus);
BUS_WAKE(bus);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
*(u16 *) frame = cpu_to_le16((u16) msglen);
*(((u16 *) frame) + 1) = cpu_to_le16(~msglen);
swheader =
((SDPCM_CONTROL_CHANNEL << SDPCM_CHANNEL_SHIFT) &
SDPCM_CHANNEL_MASK)
| bus->tx_seq | ((doff << SDPCM_DOFFSET_SHIFT) &
SDPCM_DOFFSET_MASK);
put_unaligned_le32(swheader, frame + SDPCM_FRAMETAG_LEN);
put_unaligned_le32(0, frame + SDPCM_FRAMETAG_LEN + sizeof(swheader));
if (!DATAOK(bus)) {
BRCMF_INFO(("%s: No bus credit bus->tx_max %d,"
" bus->tx_seq %d\n", __func__,
bus->tx_max, bus->tx_seq));
bus->ctrl_frame_stat = true;
bus->ctrl_frame_buf = frame;
bus->ctrl_frame_len = len;
brcmf_sdbrcm_wait_for_event(bus, &bus->ctrl_frame_stat);
if (bus->ctrl_frame_stat == false) {
BRCMF_INFO(("%s: ctrl_frame_stat == false\n",
__func__));
ret = 0;
} else {
BRCMF_INFO(("%s: ctrl_frame_stat == true\n", __func__));
ret = -1;
}
}
if (ret == -1) {
#ifdef BCMDBG
if (BRCMF_BYTES_ON() && BRCMF_CTL_ON()) {
printk(KERN_DEBUG "Tx Frame:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
frame, len);
} else if (BRCMF_HDRS_ON()) {
printk(KERN_DEBUG "TxHdr:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
frame, min_t(u16, len, 16));
}
#endif
do {
bus->ctrl_frame_stat = false;
ret = brcmf_sdbrcm_send_buf(bus,
brcmf_sdcard_cur_sbwad(card), SDIO_FUNC_2,
F2SYNC, frame, len, NULL, NULL, NULL);
if (ret < 0) {
BRCMF_INFO(("%s: sdio error %d, abort command "
"and terminate frame.\n",
__func__, ret));
bus->tx_sderrs++;
brcmf_sdcard_abort(card, SDIO_FUNC_2);
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_FUNC1_FRAMECTRL,
SFC_WF_TERM, NULL);
bus->f1regdata++;
for (i = 0; i < 3; i++) {
u8 hi, lo;
hi = brcmf_sdcard_cfg_read(card,
SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCHI,
NULL);
lo = brcmf_sdcard_cfg_read(card,
SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCLO,
NULL);
bus->f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
}
}
if (ret == 0) {
bus->tx_seq =
(bus->tx_seq + 1) % SDPCM_SEQUENCE_WRAP;
}
} while ((ret < 0) && retries++ < TXRETRIES);
}
if ((bus->idletime == BRCMF_IDLE_IMMEDIATE) && !bus->dpc_sched) {
bus->activity = false;
brcmf_sdbrcm_clkctl(bus, CLK_NONE, true);
}
brcmf_sdbrcm_sdunlock(bus);
if (ret)
bus->drvr->tx_ctlerrs++;
else
bus->drvr->tx_ctlpkts++;
return ret ? -EIO : 0;
}
int brcmf_sdbrcm_bus_rxctl(struct brcmf_bus *bus, unsigned char *msg, uint msglen)
{
int timeleft;
uint rxlen = 0;
bool pending;
BRCMF_TRACE(("%s: Enter\n", __func__));
if (bus->drvr->dongle_reset)
return -EIO;
timeleft = brcmf_os_ioctl_resp_wait(bus->drvr, &bus->rxlen, &pending);
brcmf_sdbrcm_sdlock(bus);
rxlen = bus->rxlen;
memcpy(msg, bus->rxctl, min(msglen, rxlen));
bus->rxlen = 0;
brcmf_sdbrcm_sdunlock(bus);
if (rxlen) {
BRCMF_CTL(("%s: resumed on rxctl frame, got %d expected %d\n",
__func__, rxlen, msglen));
} else if (timeleft == 0) {
BRCMF_ERROR(("%s: resumed on timeout\n", __func__));
#ifdef BCMDBG
brcmf_sdbrcm_sdlock(bus);
brcmf_sdbrcm_checkdied(bus, NULL, 0);
brcmf_sdbrcm_sdunlock(bus);
#endif
} else if (pending == true) {
BRCMF_CTL(("%s: cancelled\n", __func__));
return -ERESTARTSYS;
} else {
BRCMF_CTL(("%s: resumed for unknown reason?\n", __func__));
#ifdef BCMDBG
brcmf_sdbrcm_sdlock(bus);
brcmf_sdbrcm_checkdied(bus, NULL, 0);
brcmf_sdbrcm_sdunlock(bus);
#endif
}
if (rxlen)
bus->drvr->rx_ctlpkts++;
else
bus->drvr->rx_ctlerrs++;
return rxlen ? (int)rxlen : -ETIMEDOUT;
}
static void
brcmf_dump_pct(struct brcmu_strbuf *strbuf, char *desc, uint num, uint div)
{
uint q1, q2;
if (!div) {
brcmu_bprintf(strbuf, "%s N/A", desc);
} else {
q1 = num / div;
q2 = (100 * (num - (q1 * div))) / div;
brcmu_bprintf(strbuf, "%s %d.%02d", desc, q1, q2);
}
}
void brcmf_sdbrcm_bus_dump(struct brcmf_pub *drvr, struct brcmu_strbuf *strbuf)
{
struct brcmf_bus *bus = drvr->bus;
brcmu_bprintf(strbuf, "Bus SDIO structure:\n");
brcmu_bprintf(strbuf,
"hostintmask 0x%08x intstatus 0x%08x sdpcm_ver %d\n",
bus->hostintmask, bus->intstatus, bus->sdpcm_ver);
brcmu_bprintf(strbuf,
"fcstate %d qlen %d tx_seq %d, max %d, rxskip %d rxlen %d rx_seq %d\n",
bus->fcstate, pktq_len(&bus->txq), bus->tx_seq, bus->tx_max,
bus->rxskip, bus->rxlen, bus->rx_seq);
brcmu_bprintf(strbuf, "intr %d intrcount %d lastintrs %d spurious %d\n",
bus->intr, bus->intrcount, bus->lastintrs, bus->spurious);
brcmu_bprintf(strbuf, "pollrate %d pollcnt %d regfails %d\n",
bus->pollrate, bus->pollcnt, bus->regfails);
brcmu_bprintf(strbuf, "\nAdditional counters:\n");
brcmu_bprintf(strbuf,
"tx_sderrs %d fcqueued %d rxrtx %d rx_toolong %d rxc_errors %d\n",
bus->tx_sderrs, bus->fcqueued, bus->rxrtx, bus->rx_toolong,
bus->rxc_errors);
brcmu_bprintf(strbuf, "rx_hdrfail %d badhdr %d badseq %d\n",
bus->rx_hdrfail, bus->rx_badhdr, bus->rx_badseq);
brcmu_bprintf(strbuf, "fc_rcvd %d, fc_xoff %d, fc_xon %d\n",
bus->fc_rcvd, bus->fc_xoff, bus->fc_xon);
brcmu_bprintf(strbuf, "rxglomfail %d, rxglomframes %d, rxglompkts %d\n",
bus->rxglomfail, bus->rxglomframes, bus->rxglompkts);
brcmu_bprintf(strbuf, "f2rx (hdrs/data) %d (%d/%d), f2tx %d f1regs"
" %d\n",
(bus->f2rxhdrs + bus->f2rxdata), bus->f2rxhdrs,
bus->f2rxdata, bus->f2txdata, bus->f1regdata);
{
brcmf_dump_pct(strbuf, "\nRx: pkts/f2rd", bus->drvr->rx_packets,
(bus->f2rxhdrs + bus->f2rxdata));
brcmf_dump_pct(strbuf, ", pkts/f1sd", bus->drvr->rx_packets,
bus->f1regdata);
brcmf_dump_pct(strbuf, ", pkts/sd", bus->drvr->rx_packets,
(bus->f2rxhdrs + bus->f2rxdata + bus->f1regdata));
brcmf_dump_pct(strbuf, ", pkts/int", bus->drvr->rx_packets,
bus->intrcount);
brcmu_bprintf(strbuf, "\n");
brcmf_dump_pct(strbuf, "Rx: glom pct", (100 * bus->rxglompkts),
bus->drvr->rx_packets);
brcmf_dump_pct(strbuf, ", pkts/glom", bus->rxglompkts,
bus->rxglomframes);
brcmu_bprintf(strbuf, "\n");
brcmf_dump_pct(strbuf, "Tx: pkts/f2wr", bus->drvr->tx_packets,
bus->f2txdata);
brcmf_dump_pct(strbuf, ", pkts/f1sd", bus->drvr->tx_packets,
bus->f1regdata);
brcmf_dump_pct(strbuf, ", pkts/sd", bus->drvr->tx_packets,
(bus->f2txdata + bus->f1regdata));
brcmf_dump_pct(strbuf, ", pkts/int", bus->drvr->tx_packets,
bus->intrcount);
brcmu_bprintf(strbuf, "\n");
brcmf_dump_pct(strbuf, "Total: pkts/f2rw",
(bus->drvr->tx_packets + bus->drvr->rx_packets),
(bus->f2txdata + bus->f2rxhdrs + bus->f2rxdata));
brcmf_dump_pct(strbuf, ", pkts/f1sd",
(bus->drvr->tx_packets + bus->drvr->rx_packets),
bus->f1regdata);
brcmf_dump_pct(strbuf, ", pkts/sd",
(bus->drvr->tx_packets + bus->drvr->rx_packets),
(bus->f2txdata + bus->f2rxhdrs + bus->f2rxdata +
bus->f1regdata));
brcmf_dump_pct(strbuf, ", pkts/int",
(bus->drvr->tx_packets + bus->drvr->rx_packets),
bus->intrcount);
brcmu_bprintf(strbuf, "\n\n");
}
#ifdef SDTEST
if (bus->pktgen_count) {
brcmu_bprintf(strbuf, "pktgen config and count:\n");
brcmu_bprintf(strbuf,
"freq %d count %d print %d total %d min %d len %d\n",
bus->pktgen_freq, bus->pktgen_count,
bus->pktgen_print, bus->pktgen_total,
bus->pktgen_minlen, bus->pktgen_maxlen);
brcmu_bprintf(strbuf, "send attempts %d rcvd %d fail %d\n",
bus->pktgen_sent, bus->pktgen_rcvd,
bus->pktgen_fail);
}
#endif
#ifdef BCMDBG
brcmu_bprintf(strbuf, "dpc_sched %d host interrupt%spending\n",
bus->dpc_sched, " not ");
brcmu_bprintf(strbuf, "blocksize %d roundup %d\n", bus->blocksize,
bus->roundup);
#endif
brcmu_bprintf(strbuf,
"clkstate %d activity %d idletime %d idlecount %d sleeping %d\n",
bus->clkstate, bus->activity, bus->idletime, bus->idlecount,
bus->sleeping);
}
void brcmf_bus_clearcounts(struct brcmf_pub *drvr)
{
struct brcmf_bus *bus = (struct brcmf_bus *) drvr->bus;
bus->intrcount = bus->lastintrs = bus->spurious = bus->regfails = 0;
bus->rxrtx = bus->rx_toolong = bus->rxc_errors = 0;
bus->rx_hdrfail = bus->rx_badhdr = bus->rx_badseq = 0;
bus->tx_sderrs = bus->fc_rcvd = bus->fc_xoff = bus->fc_xon = 0;
bus->rxglomfail = bus->rxglomframes = bus->rxglompkts = 0;
bus->f2rxhdrs = bus->f2rxdata = bus->f2txdata = bus->f1regdata = 0;
}
static int brcmf_sdbrcm_pktgen_get(struct brcmf_bus *bus, u8 *arg)
{
struct brcmf_pktgen pktgen;
pktgen.version = BRCMF_PKTGEN_VERSION;
pktgen.freq = bus->pktgen_freq;
pktgen.count = bus->pktgen_count;
pktgen.print = bus->pktgen_print;
pktgen.total = bus->pktgen_total;
pktgen.minlen = bus->pktgen_minlen;
pktgen.maxlen = bus->pktgen_maxlen;
pktgen.numsent = bus->pktgen_sent;
pktgen.numrcvd = bus->pktgen_rcvd;
pktgen.numfail = bus->pktgen_fail;
pktgen.mode = bus->pktgen_mode;
pktgen.stop = bus->pktgen_stop;
memcpy(arg, &pktgen, sizeof(pktgen));
return 0;
}
static int brcmf_sdbrcm_pktgen_set(struct brcmf_bus *bus, u8 *arg)
{
struct brcmf_pktgen pktgen;
uint oldcnt, oldmode;
memcpy(&pktgen, arg, sizeof(pktgen));
if (pktgen.version != BRCMF_PKTGEN_VERSION)
return -EINVAL;
oldcnt = bus->pktgen_count;
oldmode = bus->pktgen_mode;
bus->pktgen_freq = pktgen.freq;
bus->pktgen_count = pktgen.count;
bus->pktgen_print = pktgen.print;
bus->pktgen_total = pktgen.total;
bus->pktgen_minlen = pktgen.minlen;
bus->pktgen_maxlen = pktgen.maxlen;
bus->pktgen_mode = pktgen.mode;
bus->pktgen_stop = pktgen.stop;
bus->pktgen_tick = bus->pktgen_ptick = 0;
bus->pktgen_len = max(bus->pktgen_len, bus->pktgen_minlen);
bus->pktgen_len = min(bus->pktgen_len, bus->pktgen_maxlen);
if (bus->pktgen_count && (!oldcnt || oldmode != bus->pktgen_mode))
bus->pktgen_sent = bus->pktgen_rcvd = bus->pktgen_fail = 0;
return 0;
}
static int
brcmf_sdbrcm_membytes(struct brcmf_bus *bus, bool write, u32 address, u8 *data,
uint size)
{
int bcmerror = 0;
u32 sdaddr;
uint dsize;
sdaddr = address & SBSDIO_SB_OFT_ADDR_MASK;
if ((sdaddr + size) & SBSDIO_SBWINDOW_MASK)
dsize = (SBSDIO_SB_OFT_ADDR_LIMIT - sdaddr);
else
dsize = size;
bcmerror = brcmf_sdbrcm_set_siaddr_window(bus, address);
if (bcmerror) {
BRCMF_ERROR(("%s: window change failed\n", __func__));
goto xfer_done;
}
while (size) {
BRCMF_INFO(("%s: %s %d bytes at offset 0x%08x in window"
" 0x%08x\n", __func__, (write ? "write" : "read"),
dsize, sdaddr, (address & SBSDIO_SBWINDOW_MASK)));
bcmerror =
brcmf_sdcard_rwdata(bus->card, write, sdaddr, data, dsize);
if (bcmerror) {
BRCMF_ERROR(("%s: membytes transfer failed\n",
__func__));
break;
}
size -= dsize;
if (size) {
data += dsize;
address += dsize;
bcmerror = brcmf_sdbrcm_set_siaddr_window(bus, address);
if (bcmerror) {
BRCMF_ERROR(("%s: window change failed\n",
__func__));
break;
}
sdaddr = 0;
dsize = min_t(uint, SBSDIO_SB_OFT_ADDR_LIMIT, size);
}
}
xfer_done:
if (brcmf_sdbrcm_set_siaddr_window(bus,
brcmf_sdcard_cur_sbwad(bus->card))) {
BRCMF_ERROR(("%s: FAILED to set window back to 0x%x\n",
__func__, brcmf_sdcard_cur_sbwad(bus->card)));
}
return bcmerror;
}
static int brcmf_sdbrcm_readshared(struct brcmf_bus *bus, struct sdpcm_shared *sh)
{
u32 addr;
int rv;
rv = brcmf_sdbrcm_membytes(bus, false, bus->ramsize - 4, (u8 *)&addr,
4);
if (rv < 0)
return rv;
addr = le32_to_cpu(addr);
BRCMF_INFO(("sdpcm_shared address 0x%08X\n", addr));
if (addr == 0 || ((~addr >> 16) & 0xffff) == (addr & 0xffff)) {
BRCMF_ERROR(("%s: address (0x%08x) of sdpcm_shared invalid\n",
__func__, addr));
return -EBADE;
}
rv = brcmf_sdbrcm_membytes(bus, false, addr, (u8 *) sh,
sizeof(struct sdpcm_shared));
if (rv < 0)
return rv;
sh->flags = le32_to_cpu(sh->flags);
sh->trap_addr = le32_to_cpu(sh->trap_addr);
sh->assert_exp_addr = le32_to_cpu(sh->assert_exp_addr);
sh->assert_file_addr = le32_to_cpu(sh->assert_file_addr);
sh->assert_line = le32_to_cpu(sh->assert_line);
sh->console_addr = le32_to_cpu(sh->console_addr);
sh->msgtrace_addr = le32_to_cpu(sh->msgtrace_addr);
if ((sh->flags & SDPCM_SHARED_VERSION_MASK) != SDPCM_SHARED_VERSION) {
BRCMF_ERROR(("%s: sdpcm_shared version %d in brcmf "
"is different than sdpcm_shared version %d in dongle\n",
__func__, SDPCM_SHARED_VERSION,
sh->flags & SDPCM_SHARED_VERSION_MASK));
return -EBADE;
}
return 0;
}
static int brcmf_sdbrcm_checkdied(struct brcmf_bus *bus, u8 *data, uint size)
{
int bcmerror = 0;
uint msize = 512;
char *mbuffer = NULL;
uint maxstrlen = 256;
char *str = NULL;
struct brcmf_trap tr;
struct sdpcm_shared sdpcm_shared;
struct brcmu_strbuf strbuf;
BRCMF_TRACE(("%s: Enter\n", __func__));
if (data == NULL) {
size = msize;
mbuffer = data = kmalloc(msize, GFP_ATOMIC);
if (mbuffer == NULL) {
BRCMF_ERROR(("%s: kmalloc(%d) failed\n", __func__,
msize));
bcmerror = -ENOMEM;
goto done;
}
}
str = kmalloc(maxstrlen, GFP_ATOMIC);
if (str == NULL) {
BRCMF_ERROR(("%s: kmalloc(%d) failed\n", __func__, maxstrlen));
bcmerror = -ENOMEM;
goto done;
}
bcmerror = brcmf_sdbrcm_readshared(bus, &sdpcm_shared);
if (bcmerror < 0)
goto done;
brcmu_binit(&strbuf, data, size);
brcmu_bprintf(&strbuf,
"msgtrace address : 0x%08X\nconsole address : 0x%08X\n",
sdpcm_shared.msgtrace_addr, sdpcm_shared.console_addr);
if ((sdpcm_shared.flags & SDPCM_SHARED_ASSERT_BUILT) == 0) {
brcmu_bprintf(&strbuf, "Assrt not built in dongle\n");
}
if ((sdpcm_shared.flags & (SDPCM_SHARED_ASSERT | SDPCM_SHARED_TRAP)) ==
0) {
brcmu_bprintf(&strbuf, "No trap%s in dongle",
(sdpcm_shared.flags & SDPCM_SHARED_ASSERT_BUILT)
? "/assrt" : "");
} else {
if (sdpcm_shared.flags & SDPCM_SHARED_ASSERT) {
brcmu_bprintf(&strbuf, "Dongle assert");
if (sdpcm_shared.assert_exp_addr != 0) {
str[0] = '\0';
bcmerror = brcmf_sdbrcm_membytes(bus, false,
sdpcm_shared.assert_exp_addr,
(u8 *) str, maxstrlen);
if (bcmerror < 0)
goto done;
str[maxstrlen - 1] = '\0';
brcmu_bprintf(&strbuf, " expr \"%s\"", str);
}
if (sdpcm_shared.assert_file_addr != 0) {
str[0] = '\0';
bcmerror = brcmf_sdbrcm_membytes(bus, false,
sdpcm_shared.assert_file_addr,
(u8 *) str, maxstrlen);
if (bcmerror < 0)
goto done;
str[maxstrlen - 1] = '\0';
brcmu_bprintf(&strbuf, " file \"%s\"", str);
}
brcmu_bprintf(&strbuf, " line %d ",
sdpcm_shared.assert_line);
}
if (sdpcm_shared.flags & SDPCM_SHARED_TRAP) {
bcmerror = brcmf_sdbrcm_membytes(bus, false,
sdpcm_shared.trap_addr, (u8 *)&tr,
sizeof(struct brcmf_trap));
if (bcmerror < 0)
goto done;
brcmu_bprintf(&strbuf,
"Dongle trap type 0x%x @ epc 0x%x, cpsr 0x%x, spsr 0x%x, sp 0x%x,"
"lp 0x%x, rpc 0x%x Trap offset 0x%x, "
"r0 0x%x, r1 0x%x, r2 0x%x, r3 0x%x, r4 0x%x, r5 0x%x, r6 0x%x, r7 0x%x\n",
tr.type, tr.epc, tr.cpsr, tr.spsr, tr.r13,
tr.r14, tr.pc, sdpcm_shared.trap_addr,
tr.r0, tr.r1, tr.r2, tr.r3, tr.r4, tr.r5,
tr.r6, tr.r7);
}
}
if (sdpcm_shared.flags & (SDPCM_SHARED_ASSERT | SDPCM_SHARED_TRAP))
BRCMF_ERROR(("%s: %s\n", __func__, strbuf.origbuf));
#ifdef BCMDBG
if (sdpcm_shared.flags & SDPCM_SHARED_TRAP) {
brcmf_sdbrcm_mem_dump(bus);
}
#endif
done:
kfree(mbuffer);
kfree(str);
return bcmerror;
}
static int brcmf_sdbrcm_mem_dump(struct brcmf_bus *bus)
{
int ret = 0;
int size;
int start = 0;
int read_size = 0;
u8 *buf = NULL, *databuf = NULL;
size = bus->ramsize;
buf = kmalloc(size, GFP_ATOMIC);
if (!buf) {
BRCMF_ERROR(("%s: Out of memory (%d bytes)\n", __func__, size));
return -1;
}
printk(KERN_DEBUG "Dump dongle memory");
databuf = buf;
while (size) {
read_size = min(MEMBLOCK, size);
ret = brcmf_sdbrcm_membytes(bus, false, start, databuf,
read_size);
if (ret) {
BRCMF_ERROR(("%s: Error membytes %d\n", __func__, ret));
kfree(buf);
return -1;
}
printk(".");
size -= read_size;
start += read_size;
databuf += read_size;
}
printk(KERN_DEBUG "Done\n");
if (brcmf_write_to_file(bus->drvr, buf, bus->ramsize)) {
BRCMF_ERROR(("%s: Error writing to files\n", __func__));
return -1;
}
return 0;
}
static int brcmf_sdbrcm_readconsole(struct brcmf_bus *bus)
{
struct brcmf_console *c = &bus->console;
u8 line[CONSOLE_LINE_MAX], ch;
u32 n, idx, addr;
int rv;
if (bus->console_addr == 0)
return 0;
addr = bus->console_addr + offsetof(struct rte_console, log);
rv = brcmf_sdbrcm_membytes(bus, false, addr, (u8 *)&c->log,
sizeof(c->log));
if (rv < 0)
return rv;
if (c->buf == NULL) {
c->bufsize = le32_to_cpu(c->log.buf_size);
c->buf = kmalloc(c->bufsize, GFP_ATOMIC);
if (c->buf == NULL)
return -ENOMEM;
}
idx = le32_to_cpu(c->log.idx);
if (idx > c->bufsize)
return -EBADE;
if (idx == c->last)
return 0;
addr = le32_to_cpu(c->log.buf);
rv = brcmf_sdbrcm_membytes(bus, false, addr, c->buf, c->bufsize);
if (rv < 0)
return rv;
while (c->last != idx) {
for (n = 0; n < CONSOLE_LINE_MAX - 2; n++) {
if (c->last == idx) {
if (c->last >= n)
c->last -= n;
else
c->last = c->bufsize - n;
goto break2;
}
ch = c->buf[c->last];
c->last = (c->last + 1) % c->bufsize;
if (ch == '\n')
break;
line[n] = ch;
}
if (n > 0) {
if (line[n - 1] == '\r')
n--;
line[n] = 0;
printk(KERN_DEBUG "CONSOLE: %s\n", line);
}
}
break2:
return 0;
}
int brcmf_sdbrcm_downloadvars(struct brcmf_bus *bus, void *arg, int len)
{
int bcmerror = 0;
BRCMF_TRACE(("%s: Enter\n", __func__));
if (bus->drvr->up) {
bcmerror = -EISCONN;
goto err;
}
if (!len) {
bcmerror = -EOVERFLOW;
goto err;
}
kfree(bus->vars);
bus->vars = kmalloc(len, GFP_ATOMIC);
bus->varsz = bus->vars ? len : 0;
if (bus->vars == NULL) {
bcmerror = -ENOMEM;
goto err;
}
memcpy(bus->vars, arg, bus->varsz);
err:
return bcmerror;
}
static int
brcmf_sdbrcm_doiovar(struct brcmf_bus *bus, const struct brcmu_iovar *vi, u32 actionid,
const char *name, void *params, int plen, void *arg, int len,
int val_size)
{
int bcmerror = 0;
s32 int_val = 0;
bool bool_val = 0;
BRCMF_TRACE(("%s: Enter, action %d name %s params %p plen %d arg %p "
"len %d val_size %d\n", __func__, actionid, name, params,
plen, arg, len, val_size));
bcmerror = brcmu_iovar_lencheck(vi, arg, len, IOV_ISSET(actionid));
if (bcmerror != 0)
goto exit;
if (plen >= (int)sizeof(int_val))
memcpy(&int_val, params, sizeof(int_val));
bool_val = (int_val != 0) ? true : false;
brcmf_sdbrcm_sdlock(bus);
if (bus->drvr->dongle_reset && !(actionid == IOV_SVAL(IOV_DEVRESET) ||
actionid == IOV_GVAL(IOV_DEVRESET))) {
bcmerror = -EPERM;
goto exit;
}
if (vi->varid == IOV_SLEEP) {
if (IOV_ISSET(actionid)) {
bcmerror = brcmf_sdbrcm_bussleep(bus, bool_val);
} else {
int_val = (s32) bus->sleeping;
memcpy(arg, &int_val, val_size);
}
goto exit;
}
if (!bus->drvr->dongle_reset) {
BUS_WAKE(bus);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
}
switch (actionid) {
case IOV_GVAL(IOV_INTR):
int_val = (s32) bus->intr;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_INTR):
bus->intr = bool_val;
bus->intdis = false;
if (bus->drvr->up) {
BRCMF_INTR(("%s: %s SDIO interrupts\n", __func__,
bus->intr ? "enable" : "disable"));
if (bus->intr) {
brcmf_sdcard_intr_enable(bus->card);
} else {
brcmf_sdcard_intr_disable(bus->card);
}
}
break;
case IOV_GVAL(IOV_POLLRATE):
int_val = (s32) bus->pollrate;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_POLLRATE):
bus->pollrate = (uint) int_val;
bus->poll = (bus->pollrate != 0);
break;
case IOV_GVAL(IOV_IDLETIME):
int_val = bus->idletime;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_IDLETIME):
if ((int_val < 0) && (int_val != BRCMF_IDLE_IMMEDIATE))
bcmerror = -EINVAL;
else
bus->idletime = int_val;
break;
case IOV_GVAL(IOV_IDLECLOCK):
int_val = (s32) bus->idleclock;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_IDLECLOCK):
bus->idleclock = int_val;
break;
case IOV_GVAL(IOV_SD1IDLE):
int_val = (s32) sd1idle;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_SD1IDLE):
sd1idle = bool_val;
break;
case IOV_SVAL(IOV_MEMBYTES):
case IOV_GVAL(IOV_MEMBYTES):
{
u32 address;
uint size, dsize;
u8 *data;
bool set = (actionid == IOV_SVAL(IOV_MEMBYTES));
address = (u32) int_val;
memcpy(&int_val, (char *)params + sizeof(int_val),
sizeof(int_val));
size = (uint) int_val;
dsize = set ? plen - (2 * sizeof(int)) : len;
if (dsize < size) {
BRCMF_ERROR(("%s: error on %s membytes, addr "
"0x%08x size %d dsize %d\n",
__func__, (set ? "set" : "get"),
address, size, dsize));
bcmerror = -EINVAL;
break;
}
BRCMF_INFO(("%s: Request to %s %d bytes at address "
"0x%08x\n", __func__,
(set ? "write" : "read"), size, address));
if ((bus->orig_ramsize) &&
((address > bus->orig_ramsize)
|| (address + size > bus->orig_ramsize))) {
BRCMF_ERROR(("%s: ramsize 0x%08x doesn't have"
" %d bytes at 0x%08x\n", __func__,
bus->orig_ramsize, size, address));
bcmerror = -EINVAL;
break;
}
data =
set ? (u8 *) params +
2 * sizeof(int) : (u8 *) arg;
bcmerror = brcmf_sdbrcm_membytes(bus, set, address,
data, size);
break;
}
case IOV_GVAL(IOV_MEMSIZE):
int_val = (s32) bus->ramsize;
memcpy(arg, &int_val, val_size);
break;
case IOV_GVAL(IOV_SDIOD_DRIVE):
int_val = (s32) brcmf_sdiod_drive_strength;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_SDIOD_DRIVE):
brcmf_sdiod_drive_strength = int_val;
brcmf_sdbrcm_sdiod_drive_strength_init(bus,
brcmf_sdiod_drive_strength);
break;
case IOV_SVAL(IOV_DOWNLOAD):
bcmerror = brcmf_sdbrcm_download_state(bus, bool_val);
break;
case IOV_SVAL(IOV_VARS):
bcmerror = brcmf_sdbrcm_downloadvars(bus, arg, len);
break;
case IOV_GVAL(IOV_READAHEAD):
int_val = (s32) brcmf_readahead;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_READAHEAD):
if (bool_val && !brcmf_readahead)
bus->nextlen = 0;
brcmf_readahead = bool_val;
break;
case IOV_GVAL(IOV_SDRXCHAIN):
int_val = (s32) bus->use_rxchain;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_SDRXCHAIN):
if (bool_val && !bus->sd_rxchain)
bcmerror = -ENOTSUPP;
else
bus->use_rxchain = bool_val;
break;
case IOV_GVAL(IOV_ALIGNCTL):
int_val = (s32) brcmf_alignctl;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_ALIGNCTL):
brcmf_alignctl = bool_val;
break;
case IOV_GVAL(IOV_SDALIGN):
int_val = BRCMF_SDALIGN;
memcpy(arg, &int_val, val_size);
break;
#ifdef BCMDBG
case IOV_GVAL(IOV_VARS):
if (bus->varsz < (uint) len)
memcpy(arg, bus->vars, bus->varsz);
else
bcmerror = -EOVERFLOW;
break;
#endif
#ifdef BCMDBG
case IOV_GVAL(IOV_DCONSOLE_POLL):
int_val = (s32) brcmf_console_ms;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_DCONSOLE_POLL):
brcmf_console_ms = (uint) int_val;
break;
case IOV_SVAL(IOV_CONS):
if (len > 0)
bcmerror = brcmf_sdbrcm_bus_console_in(bus->drvr,
arg, len - 1);
break;
case IOV_GVAL(IOV_SDREG):
{
struct brcmf_sdreg *sd_ptr;
u32 addr, size;
sd_ptr = (struct brcmf_sdreg *) params;
addr = bus->ci->buscorebase + sd_ptr->offset;
size = sd_ptr->func;
int_val = (s32) brcmf_sdcard_reg_read(bus->card, addr,
size);
if (brcmf_sdcard_regfail(bus->card))
bcmerror = -EIO;
memcpy(arg, &int_val, sizeof(s32));
break;
}
case IOV_SVAL(IOV_SDREG):
{
struct brcmf_sdreg *sd_ptr;
u32 addr, size;
sd_ptr = (struct brcmf_sdreg *) params;
addr = bus->ci->buscorebase + sd_ptr->offset;
size = sd_ptr->func;
brcmf_sdcard_reg_write(bus->card, addr, size,
sd_ptr->value);
if (brcmf_sdcard_regfail(bus->card))
bcmerror = -EIO;
break;
}
case IOV_GVAL(IOV_SBREG):
{
struct brcmf_sdreg sdreg;
u32 addr, size;
memcpy(&sdreg, params, sizeof(sdreg));
addr = SI_ENUM_BASE + sdreg.offset;
size = sdreg.func;
int_val = (s32) brcmf_sdcard_reg_read(bus->card, addr,
size);
if (brcmf_sdcard_regfail(bus->card))
bcmerror = -EIO;
memcpy(arg, &int_val, sizeof(s32));
break;
}
case IOV_SVAL(IOV_SBREG):
{
struct brcmf_sdreg sdreg;
u32 addr, size;
memcpy(&sdreg, params, sizeof(sdreg));
addr = SI_ENUM_BASE + sdreg.offset;
size = sdreg.func;
brcmf_sdcard_reg_write(bus->card, addr, size,
sdreg.value);
if (brcmf_sdcard_regfail(bus->card))
bcmerror = -EIO;
break;
}
case IOV_GVAL(IOV_SDCIS):
{
*(char *)arg = 0;
strcat(arg, "\nFunc 0\n");
brcmf_sdcard_cis_read(bus->card, 0x10,
(u8 *) arg + strlen(arg),
SBSDIO_CIS_SIZE_LIMIT);
strcat(arg, "\nFunc 1\n");
brcmf_sdcard_cis_read(bus->card, 0x11,
(u8 *) arg + strlen(arg),
SBSDIO_CIS_SIZE_LIMIT);
strcat(arg, "\nFunc 2\n");
brcmf_sdcard_cis_read(bus->card, 0x12,
(u8 *) arg + strlen(arg),
SBSDIO_CIS_SIZE_LIMIT);
break;
}
case IOV_GVAL(IOV_FORCEEVEN):
int_val = (s32) forcealign;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_FORCEEVEN):
forcealign = bool_val;
break;
case IOV_GVAL(IOV_TXBOUND):
int_val = (s32) brcmf_txbound;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_TXBOUND):
brcmf_txbound = (uint) int_val;
break;
case IOV_GVAL(IOV_RXBOUND):
int_val = (s32) brcmf_rxbound;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_RXBOUND):
brcmf_rxbound = (uint) int_val;
break;
case IOV_GVAL(IOV_TXMINMAX):
int_val = (s32) brcmf_txminmax;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_TXMINMAX):
brcmf_txminmax = (uint) int_val;
break;
#endif
#ifdef SDTEST
case IOV_GVAL(IOV_EXTLOOP):
int_val = (s32) bus->ext_loop;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_EXTLOOP):
bus->ext_loop = bool_val;
break;
case IOV_GVAL(IOV_PKTGEN):
bcmerror = brcmf_sdbrcm_pktgen_get(bus, arg);
break;
case IOV_SVAL(IOV_PKTGEN):
bcmerror = brcmf_sdbrcm_pktgen_set(bus, arg);
break;
#endif
case IOV_SVAL(IOV_DEVRESET):
BRCMF_TRACE(("%s: Called set IOV_DEVRESET=%d dongle_reset=%d "
"busstate=%d\n",
__func__, bool_val, bus->drvr->dongle_reset,
bus->drvr->busstate));
brcmf_bus_devreset(bus->drvr, (u8) bool_val);
break;
case IOV_GVAL(IOV_DEVRESET):
BRCMF_TRACE(("%s: Called get IOV_DEVRESET\n", __func__));
int_val = (bool) bus->drvr->dongle_reset;
memcpy(arg, &int_val, val_size);
break;
case IOV_GVAL(IOV_WDTICK):
int_val = (s32) brcmf_watchdog_ms;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_WDTICK):
if (!bus->drvr->up) {
bcmerror = -ENOLINK;
break;
}
brcmf_sdbrcm_wd_timer(bus, (uint) int_val);
break;
default:
bcmerror = -ENOTSUPP;
break;
}
exit:
if ((bus->idletime == BRCMF_IDLE_IMMEDIATE) && !bus->dpc_sched) {
bus->activity = false;
brcmf_sdbrcm_clkctl(bus, CLK_NONE, true);
}
brcmf_sdbrcm_sdunlock(bus);
if (actionid == IOV_SVAL(IOV_DEVRESET) && bool_val == false)
brcmf_c_preinit_ioctls(bus->drvr);
return bcmerror;
}
static int brcmf_sdbrcm_write_vars(struct brcmf_bus *bus)
{
int bcmerror = 0;
u32 varsize;
u32 varaddr;
u8 *vbuffer;
u32 varsizew;
#ifdef BCMDBG
char *nvram_ularray;
#endif
varsize = bus->varsz ? roundup(bus->varsz, 4) : 0;
varaddr = (bus->ramsize - 4) - varsize;
if (bus->vars) {
vbuffer = kzalloc(varsize, GFP_ATOMIC);
if (!vbuffer)
return -ENOMEM;
memcpy(vbuffer, bus->vars, bus->varsz);
bcmerror =
brcmf_sdbrcm_membytes(bus, true, varaddr, vbuffer, varsize);
#ifdef BCMDBG
BRCMF_INFO(("Compare NVRAM dl & ul; varsize=%d\n", varsize));
nvram_ularray = kmalloc(varsize, GFP_ATOMIC);
if (!nvram_ularray)
return -ENOMEM;
memset(nvram_ularray, 0xaa, varsize);
bcmerror =
brcmf_sdbrcm_membytes(bus, false, varaddr, nvram_ularray,
varsize);
if (bcmerror) {
BRCMF_ERROR(("%s: error %d on reading %d nvram bytes"
" at 0x%08x\n", __func__, bcmerror,
varsize, varaddr));
}
if (memcmp(vbuffer, nvram_ularray, varsize)) {
BRCMF_ERROR(("%s: Downloaded NVRAM image is "
"corrupted.\n", __func__));
} else
BRCMF_ERROR(("%s: Download/Upload/Compare of"
" NVRAM ok.\n", __func__));
kfree(nvram_ularray);
#endif
kfree(vbuffer);
}
BRCMF_INFO(("Physical memory size: %d, usable memory size: %d\n",
bus->orig_ramsize, bus->ramsize));
BRCMF_INFO(("Vars are at %d, orig varsize is %d\n", varaddr, varsize));
varsize = ((bus->orig_ramsize - 4) - varaddr);
if (bcmerror) {
varsizew = 0;
} else {
varsizew = varsize / 4;
varsizew = (~varsizew << 16) | (varsizew & 0x0000FFFF);
varsizew = cpu_to_le32(varsizew);
}
BRCMF_INFO(("New varsize is %d, length token=0x%08x\n", varsize,
varsizew));
bcmerror = brcmf_sdbrcm_membytes(bus, true, (bus->orig_ramsize - 4),
(u8 *)&varsizew, 4);
return bcmerror;
}
static int brcmf_sdbrcm_download_state(struct brcmf_bus *bus, bool enter)
{
uint retries;
u32 regdata;
int bcmerror = 0;
if (enter) {
bus->alp_only = true;
brcmf_sdbrcm_chip_disablecore(bus->card, bus->ci->armcorebase);
brcmf_sdbrcm_chip_resetcore(bus->card, bus->ci->ramcorebase);
if (bus->ramsize) {
u32 zeros = 0;
brcmf_sdbrcm_membytes(bus, true, bus->ramsize - 4,
(u8 *)&zeros, 4);
}
} else {
regdata = brcmf_sdcard_reg_read(bus->card,
CORE_SB(bus->ci->ramcorebase, sbtmstatelow), 4);
regdata &= (SBTML_RESET | SBTML_REJ_MASK |
(SICF_CLOCK_EN << SBTML_SICF_SHIFT));
if ((SICF_CLOCK_EN << SBTML_SICF_SHIFT) != regdata) {
BRCMF_ERROR(("%s: SOCRAM core is down after reset?\n",
__func__));
bcmerror = -EBADE;
goto fail;
}
bcmerror = brcmf_sdbrcm_write_vars(bus);
if (bcmerror) {
BRCMF_ERROR(("%s: no vars written to RAM\n", __func__));
bcmerror = 0;
}
w_sdreg32(bus, 0xFFFFFFFF,
offsetof(struct sdpcmd_regs, intstatus), &retries);
brcmf_sdbrcm_chip_resetcore(bus->card, bus->ci->armcorebase);
bus->alp_only = false;
bus->drvr->busstate = BRCMF_BUS_LOAD;
}
fail:
return bcmerror;
}
int
brcmf_sdbrcm_bus_iovar_op(struct brcmf_pub *drvr, const char *name,
void *params, int plen, void *arg, int len, bool set)
{
struct brcmf_bus *bus = drvr->bus;
const struct brcmu_iovar *vi = NULL;
int bcmerror = 0;
int val_size;
u32 actionid;
BRCMF_TRACE(("%s: Enter\n", __func__));
if (name == NULL || len <= 0)
return -EINVAL;
if (set && (params || plen))
return -EINVAL;
if (!set && !(arg && len))
return -EINVAL;
vi = brcmu_iovar_lookup(brcmf_sdio_iovars, name);
if (vi == NULL) {
brcmf_sdbrcm_sdlock(bus);
BUS_WAKE(bus);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
bcmerror = brcmf_sdcard_iovar_op(bus->card, name, params, plen,
arg, len, set);
if (set && strcmp(name, "sd_blocksize") == 0) {
s32 fnum = 2;
if (brcmf_sdcard_iovar_op
(bus->card, "sd_blocksize", &fnum, sizeof(s32),
&bus->blocksize, sizeof(s32),
false) != 0) {
bus->blocksize = 0;
BRCMF_ERROR(("%s: fail on %s get\n", __func__,
"sd_blocksize"));
} else {
BRCMF_INFO(("%s: noted sd_blocksize update,"
" value now %d\n", __func__,
bus->blocksize));
}
}
bus->roundup = min(max_roundup, bus->blocksize);
if (bus->idletime == BRCMF_IDLE_IMMEDIATE &&
!bus->dpc_sched) {
bus->activity = false;
brcmf_sdbrcm_clkctl(bus, CLK_NONE, true);
}
brcmf_sdbrcm_sdunlock(bus);
goto exit;
}
BRCMF_CTL(("%s: %s %s, len %d plen %d\n", __func__,
name, (set ? "set" : "get"), len, plen));
if (params == NULL) {
params = arg;
plen = len;
}
if (vi->type == IOVT_VOID)
val_size = 0;
else if (vi->type == IOVT_BUFFER)
val_size = len;
else
val_size = sizeof(int);
actionid = set ? IOV_SVAL(vi->varid) : IOV_GVAL(vi->varid);
bcmerror = brcmf_sdbrcm_doiovar(bus, vi, actionid, name, params, plen,
arg, len, val_size);
exit:
return bcmerror;
}
void brcmf_sdbrcm_bus_stop(struct brcmf_bus *bus, bool enforce_mutex)
{
u32 local_hostintmask;
u8 saveclk;
uint retries;
int err;
BRCMF_TRACE(("%s: Enter\n", __func__));
if (enforce_mutex)
brcmf_sdbrcm_sdlock(bus);
BUS_WAKE(bus);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
if (bus->watchdog_tsk) {
send_sig(SIGTERM, bus->watchdog_tsk, 1);
kthread_stop(bus->watchdog_tsk);
bus->watchdog_tsk = NULL;
}
if (bus->dpc_tsk) {
send_sig(SIGTERM, bus->dpc_tsk, 1);
kthread_stop(bus->dpc_tsk);
bus->dpc_tsk = NULL;
} else
tasklet_kill(&bus->tasklet);
w_sdreg32(bus, 0, offsetof(struct sdpcmd_regs, hostintmask), &retries);
local_hostintmask = bus->hostintmask;
bus->hostintmask = 0;
bus->drvr->busstate = BRCMF_BUS_DOWN;
saveclk = brcmf_sdcard_cfg_read(bus->card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (!err) {
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
(saveclk | SBSDIO_FORCE_HT), &err);
}
if (err) {
BRCMF_ERROR(("%s: Failed to force clock for F2: err %d\n",
__func__, err));
}
BRCMF_INTR(("%s: disable SDIO interrupts\n", __func__));
brcmf_sdcard_intr_disable(bus->card);
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_0, SDIO_CCCR_IOEx,
SDIO_FUNC_ENABLE_1, NULL);
w_sdreg32(bus, local_hostintmask,
offsetof(struct sdpcmd_regs, intstatus), &retries);
brcmf_sdbrcm_clkctl(bus, CLK_SDONLY, false);
brcmu_pktq_flush(&bus->txq, true, NULL, NULL);
if (bus->glomd)
brcmu_pkt_buf_free_skb(bus->glomd);
if (bus->glom)
brcmu_pkt_buf_free_skb(bus->glom);
bus->glom = bus->glomd = NULL;
bus->rxlen = 0;
brcmf_os_ioctl_resp_wake(bus->drvr);
bus->rxskip = false;
bus->tx_seq = bus->rx_seq = 0;
if (enforce_mutex)
brcmf_sdbrcm_sdunlock(bus);
}
int brcmf_sdbrcm_bus_init(struct brcmf_pub *drvr, bool enforce_mutex)
{
struct brcmf_bus *bus = drvr->bus;
struct brcmf_timeout tmo;
uint retries = 0;
u8 ready, enable;
int err, ret = 0;
u8 saveclk;
BRCMF_TRACE(("%s: Enter\n", __func__));
if (drvr->busstate == BRCMF_BUS_DOWN) {
if (!(brcmf_sdbrcm_download_firmware(bus, bus->card)))
return -1;
}
if (!bus->drvr)
return 0;
bus->drvr->tickcnt = 0;
brcmf_sdbrcm_wd_timer(bus, brcmf_watchdog_ms);
if (enforce_mutex)
brcmf_sdbrcm_sdlock(bus);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
if (bus->clkstate != CLK_AVAIL)
goto exit;
saveclk =
brcmf_sdcard_cfg_read(bus->card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (!err) {
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
(saveclk | SBSDIO_FORCE_HT), &err);
}
if (err) {
BRCMF_ERROR(("%s: Failed to force clock for F2: err %d\n",
__func__, err));
goto exit;
}
w_sdreg32(bus, SDPCM_PROT_VERSION << SMB_DATA_VERSION_SHIFT,
offsetof(struct sdpcmd_regs, tosbmailboxdata), &retries);
enable = (SDIO_FUNC_ENABLE_1 | SDIO_FUNC_ENABLE_2);
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_0, SDIO_CCCR_IOEx, enable,
NULL);
brcmf_timeout_start(&tmo, BRCMF_WAIT_F2RDY * 1000);
ready = 0;
while (ready != enable && !brcmf_timeout_expired(&tmo))
ready = brcmf_sdcard_cfg_read(bus->card, SDIO_FUNC_0,
SDIO_CCCR_IORx, NULL);
BRCMF_INFO(("%s: enable 0x%02x, ready 0x%02x (waited %uus)\n",
__func__, enable, ready, tmo.elapsed));
if (ready == enable) {
bus->hostintmask = HOSTINTMASK;
w_sdreg32(bus, bus->hostintmask,
offsetof(struct sdpcmd_regs, hostintmask), &retries);
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1, SBSDIO_WATERMARK,
(u8) watermark, &err);
drvr->busstate = BRCMF_BUS_DATA;
bus->intdis = false;
if (bus->intr) {
BRCMF_INTR(("%s: enable SDIO device interrupts\n",
__func__));
brcmf_sdcard_intr_enable(bus->card);
} else {
BRCMF_INTR(("%s: disable SDIO interrupts\n", __func__));
brcmf_sdcard_intr_disable(bus->card);
}
}
else {
enable = SDIO_FUNC_ENABLE_1;
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_0, SDIO_CCCR_IOEx,
enable, NULL);
}
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
saveclk, &err);
#if defined(OOB_INTR_ONLY)
if (brcmf_sdio_register_oob_intr(bus->dhd)) {
brcmf_sdbrcm_wd_timer(bus, 0);
BRCMF_ERROR(("%s Host failed to resgister for OOB\n",
__func__));
ret = -ENODEV;
goto exit;
}
brcmf_sdbrcm_enable_oob_intr(bus, true);
#endif
if (drvr->busstate != BRCMF_BUS_DATA)
brcmf_sdbrcm_clkctl(bus, CLK_NONE, false);
exit:
if (enforce_mutex)
brcmf_sdbrcm_sdunlock(bus);
return ret;
}
static void brcmf_sdbrcm_rxfail(struct brcmf_bus *bus, bool abort, bool rtx)
{
struct brcmf_sdio_card *card = bus->card;
uint retries = 0;
u16 lastrbc;
u8 hi, lo;
int err;
BRCMF_ERROR(("%s: %sterminate frame%s\n", __func__,
(abort ? "abort command, " : ""),
(rtx ? ", send NAK" : "")));
if (abort)
brcmf_sdcard_abort(card, SDIO_FUNC_2);
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1, SBSDIO_FUNC1_FRAMECTRL,
SFC_RF_TERM, &err);
bus->f1regdata++;
for (lastrbc = retries = 0xffff; retries > 0; retries--) {
hi = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_RFRAMEBCHI, NULL);
lo = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_RFRAMEBCLO, NULL);
bus->f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
if ((hi > (lastrbc >> 8)) && (lo > (lastrbc & 0x00ff))) {
BRCMF_ERROR(("%s: count growing: last 0x%04x now "
"0x%04x\n",
__func__, lastrbc, ((hi << 8) + lo)));
}
lastrbc = (hi << 8) + lo;
}
if (!retries) {
BRCMF_ERROR(("%s: count never zeroed: last 0x%04x\n",
__func__, lastrbc));
} else {
BRCMF_INFO(("%s: flush took %d iterations\n", __func__,
(0xffff - retries)));
}
if (rtx) {
bus->rxrtx++;
w_sdreg32(bus, SMB_NAK,
offsetof(struct sdpcmd_regs, tosbmailbox), &retries);
bus->f1regdata++;
if (retries <= retry_limit)
bus->rxskip = true;
}
bus->nextlen = 0;
if (err || brcmf_sdcard_regfail(card))
bus->drvr->busstate = BRCMF_BUS_DOWN;
}
static void
brcmf_sdbrcm_read_control(struct brcmf_bus *bus, u8 *hdr, uint len, uint doff)
{
struct brcmf_sdio_card *card = bus->card;
uint rdlen, pad;
int sdret;
BRCMF_TRACE(("%s: Enter\n", __func__));
if ((bus->bus == SPI_BUS) && (!bus->usebufpool))
goto gotpkt;
bus->rxctl = bus->rxbuf;
if (brcmf_alignctl) {
bus->rxctl += firstread;
pad = ((unsigned long)bus->rxctl % BRCMF_SDALIGN);
if (pad)
bus->rxctl += (BRCMF_SDALIGN - pad);
bus->rxctl -= firstread;
}
memcpy(bus->rxctl, hdr, firstread);
if (len <= firstread)
goto gotpkt;
if (bus->bus == SPI_BUS) {
memcpy(bus->rxctl, hdr, len);
goto gotpkt;
}
rdlen = len - firstread;
if (bus->roundup && bus->blocksize && (rdlen > bus->blocksize)) {
pad = bus->blocksize - (rdlen % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize) &&
((len + pad) < bus->drvr->maxctl))
rdlen += pad;
} else if (rdlen % BRCMF_SDALIGN) {
rdlen += BRCMF_SDALIGN - (rdlen % BRCMF_SDALIGN);
}
if (forcealign && (rdlen & (ALIGNMENT - 1)))
rdlen = roundup(rdlen, ALIGNMENT);
if ((rdlen + firstread) > bus->drvr->maxctl) {
BRCMF_ERROR(("%s: %d-byte control read exceeds %d-byte"
" buffer\n", __func__, rdlen, bus->drvr->maxctl));
bus->drvr->rx_errors++;
brcmf_sdbrcm_rxfail(bus, false, false);
goto done;
}
if ((len - doff) > bus->drvr->maxctl) {
BRCMF_ERROR(("%s: %d-byte ctl frame (%d-byte ctl data) exceeds "
"%d-byte limit\n",
__func__, len, (len - doff), bus->drvr->maxctl));
bus->drvr->rx_errors++;
bus->rx_toolong++;
brcmf_sdbrcm_rxfail(bus, false, false);
goto done;
}
sdret = brcmf_sdcard_recv_buf(card, brcmf_sdcard_cur_sbwad(card),
SDIO_FUNC_2,
F2SYNC, (bus->rxctl + firstread), rdlen,
NULL, NULL, NULL);
bus->f2rxdata++;
if (sdret < 0) {
BRCMF_ERROR(("%s: read %d control bytes failed: %d\n",
__func__, rdlen, sdret));
bus->rxc_errors++;
brcmf_sdbrcm_rxfail(bus, true, true);
goto done;
}
gotpkt:
#ifdef BCMDBG
if (BRCMF_BYTES_ON() && BRCMF_CTL_ON()) {
printk(KERN_DEBUG "RxCtrl:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, bus->rxctl, len);
}
#endif
bus->rxctl += doff;
bus->rxlen = len - doff;
done:
brcmf_os_ioctl_resp_wake(bus->drvr);
}
static u8 brcmf_sdbrcm_rxglom(struct brcmf_bus *bus, u8 rxseq)
{
u16 dlen, totlen;
u8 *dptr, num = 0;
u16 sublen, check;
struct sk_buff *pfirst, *plast, *pnext, *save_pfirst;
int errcode;
u8 chan, seq, doff, sfdoff;
u8 txmax;
int ifidx = 0;
bool usechain = bus->use_rxchain;
BRCMF_TRACE(("brcmf_sdbrcm_rxglom: start: glomd %p glom %p\n",
bus->glomd, bus->glom));
if (bus->glomd) {
pfirst = plast = pnext = NULL;
dlen = (u16) (bus->glomd->len);
dptr = bus->glomd->data;
if (!dlen || (dlen & 1)) {
BRCMF_ERROR(("%s: bad glomd len(%d),"
" ignore descriptor\n",
__func__, dlen));
dlen = 0;
}
for (totlen = num = 0; dlen; num++) {
sublen = get_unaligned_le16(dptr);
dlen -= sizeof(u16);
dptr += sizeof(u16);
if ((sublen < SDPCM_HDRLEN) ||
((num == 0) && (sublen < (2 * SDPCM_HDRLEN)))) {
BRCMF_ERROR(("%s: descriptor len %d bad: %d\n",
__func__, num, sublen));
pnext = NULL;
break;
}
if (sublen % BRCMF_SDALIGN) {
BRCMF_ERROR(("%s: sublen %d not multiple of"
" %d\n", __func__, sublen,
BRCMF_SDALIGN));
usechain = false;
}
totlen += sublen;
if (!dlen) {
sublen +=
(roundup(totlen, bus->blocksize) - totlen);
totlen = roundup(totlen, bus->blocksize);
}
pnext = brcmu_pkt_buf_get_skb(sublen + BRCMF_SDALIGN);
if (pnext == NULL) {
BRCMF_ERROR(("%s: bcm_pkt_buf_get_skb failed, "
"num %d len %d\n", __func__,
num, sublen));
break;
}
if (!pfirst) {
pfirst = plast = pnext;
} else {
plast->next = pnext;
plast = pnext;
}
PKTALIGN(pnext, sublen, BRCMF_SDALIGN);
}
if (pnext) {
BRCMF_GLOM(("%s: allocated %d-byte packet chain for %d "
"subframes\n", __func__, totlen, num));
if (BRCMF_GLOM_ON() && bus->nextlen) {
if (totlen != bus->nextlen) {
BRCMF_GLOM(("%s: glomdesc mismatch: "
"nextlen %d glomdesc %d "
"rxseq %d\n", __func__,
bus->nextlen,
totlen, rxseq));
}
}
bus->glom = pfirst;
pfirst = pnext = NULL;
} else {
if (pfirst)
brcmu_pkt_buf_free_skb(pfirst);
bus->glom = NULL;
num = 0;
}
brcmu_pkt_buf_free_skb(bus->glomd);
bus->glomd = NULL;
bus->nextlen = 0;
}
if (bus->glom) {
if (BRCMF_GLOM_ON()) {
BRCMF_GLOM(("%s: try superframe read, packet chain:\n",
__func__));
for (pnext = bus->glom; pnext; pnext = pnext->next) {
BRCMF_GLOM((" %p: %p len 0x%04x (%d)\n",
pnext, (u8 *) (pnext->data),
pnext->len, pnext->len));
}
}
pfirst = bus->glom;
dlen = (u16) brcmu_pkttotlen(pfirst);
if (usechain) {
errcode = brcmf_sdcard_recv_buf(bus->card,
brcmf_sdcard_cur_sbwad(bus->card),
SDIO_FUNC_2,
F2SYNC, (u8 *) pfirst->data, dlen,
pfirst, NULL, NULL);
} else if (bus->dataptr) {
errcode = brcmf_sdcard_recv_buf(bus->card,
brcmf_sdcard_cur_sbwad(bus->card),
SDIO_FUNC_2,
F2SYNC, bus->dataptr, dlen,
NULL, NULL, NULL);
sublen = (u16) brcmu_pktfrombuf(pfirst, 0, dlen,
bus->dataptr);
if (sublen != dlen) {
BRCMF_ERROR(("%s: FAILED TO COPY, dlen %d "
"sublen %d\n",
__func__, dlen, sublen));
errcode = -1;
}
pnext = NULL;
} else {
BRCMF_ERROR(("COULDN'T ALLOC %d-BYTE GLOM, "
"FORCE FAILURE\n", dlen));
errcode = -1;
}
bus->f2rxdata++;
if (errcode < 0) {
BRCMF_ERROR(("%s: glom read of %d bytes failed: %d\n",
__func__, dlen, errcode));
bus->drvr->rx_errors++;
if (bus->glomerr++ < 3) {
brcmf_sdbrcm_rxfail(bus, true, true);
} else {
bus->glomerr = 0;
brcmf_sdbrcm_rxfail(bus, true, false);
brcmu_pkt_buf_free_skb(bus->glom);
bus->rxglomfail++;
bus->glom = NULL;
}
return 0;
}
#ifdef BCMDBG
if (BRCMF_GLOM_ON()) {
printk(KERN_DEBUG "SUPERFRAME:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
pfirst->data, min_t(int, pfirst->len, 48));
}
#endif
dptr = (u8 *) (pfirst->data);
sublen = get_unaligned_le16(dptr);
check = get_unaligned_le16(dptr + sizeof(u16));
chan = SDPCM_PACKET_CHANNEL(&dptr[SDPCM_FRAMETAG_LEN]);
seq = SDPCM_PACKET_SEQUENCE(&dptr[SDPCM_FRAMETAG_LEN]);
bus->nextlen = dptr[SDPCM_FRAMETAG_LEN + SDPCM_NEXTLEN_OFFSET];
if ((bus->nextlen << 4) > MAX_RX_DATASZ) {
BRCMF_INFO(("%s: nextlen too large (%d) seq %d\n",
__func__, bus->nextlen, seq));
bus->nextlen = 0;
}
doff = SDPCM_DOFFSET_VALUE(&dptr[SDPCM_FRAMETAG_LEN]);
txmax = SDPCM_WINDOW_VALUE(&dptr[SDPCM_FRAMETAG_LEN]);
errcode = 0;
if ((u16)~(sublen ^ check)) {
BRCMF_ERROR(("%s (superframe): HW hdr error: len/check "
"0x%04x/0x%04x\n", __func__, sublen,
check));
errcode = -1;
} else if (roundup(sublen, bus->blocksize) != dlen) {
BRCMF_ERROR(("%s (superframe): len 0x%04x, rounded "
"0x%04x, expect 0x%04x\n",
__func__, sublen,
roundup(sublen, bus->blocksize), dlen));
errcode = -1;
} else if (SDPCM_PACKET_CHANNEL(&dptr[SDPCM_FRAMETAG_LEN]) !=
SDPCM_GLOM_CHANNEL) {
BRCMF_ERROR(("%s (superframe): bad channel %d\n",
__func__,
SDPCM_PACKET_CHANNEL(&dptr
[SDPCM_FRAMETAG_LEN])));
errcode = -1;
} else if (SDPCM_GLOMDESC(&dptr[SDPCM_FRAMETAG_LEN])) {
BRCMF_ERROR(("%s (superframe): got 2nd descriptor?\n",
__func__));
errcode = -1;
} else if ((doff < SDPCM_HDRLEN) ||
(doff > (pfirst->len - SDPCM_HDRLEN))) {
BRCMF_ERROR(("%s (superframe): Bad data offset %d: "
"HW %d pkt %d min %d\n",
__func__, doff, sublen,
pfirst->len, SDPCM_HDRLEN));
errcode = -1;
}
if (rxseq != seq) {
BRCMF_INFO(("%s: (superframe) rx_seq %d, expected %d\n",
__func__, seq, rxseq));
bus->rx_badseq++;
rxseq = seq;
}
if ((u8) (txmax - bus->tx_seq) > 0x40) {
BRCMF_ERROR(("%s: unlikely tx max %d with tx_seq %d\n",
__func__, txmax, bus->tx_seq));
txmax = bus->tx_seq + 2;
}
bus->tx_max = txmax;
skb_pull(pfirst, doff);
sfdoff = doff;
for (num = 0, pnext = pfirst; pnext && !errcode;
num++, pnext = pnext->next) {
dptr = (u8 *) (pnext->data);
dlen = (u16) (pnext->len);
sublen = get_unaligned_le16(dptr);
check = get_unaligned_le16(dptr + sizeof(u16));
chan = SDPCM_PACKET_CHANNEL(&dptr[SDPCM_FRAMETAG_LEN]);
doff = SDPCM_DOFFSET_VALUE(&dptr[SDPCM_FRAMETAG_LEN]);
#ifdef BCMDBG
if (BRCMF_GLOM_ON()) {
printk(KERN_DEBUG "subframe:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
dptr, 32);
}
#endif
if ((u16)~(sublen ^ check)) {
BRCMF_ERROR(("%s (subframe %d): HW hdr error: "
"len/check 0x%04x/0x%04x\n",
__func__, num, sublen, check));
errcode = -1;
} else if ((sublen > dlen) || (sublen < SDPCM_HDRLEN)) {
BRCMF_ERROR(("%s (subframe %d): length mismatch"
": len 0x%04x, expect 0x%04x\n",
__func__, num, sublen, dlen));
errcode = -1;
} else if ((chan != SDPCM_DATA_CHANNEL) &&
(chan != SDPCM_EVENT_CHANNEL)) {
BRCMF_ERROR(("%s (subframe %d): bad channel"
" %d\n", __func__, num, chan));
errcode = -1;
} else if ((doff < SDPCM_HDRLEN) || (doff > sublen)) {
BRCMF_ERROR(("%s (subframe %d): Bad data offset"
" %d: HW %d min %d\n",
__func__, num, doff, sublen,
SDPCM_HDRLEN));
errcode = -1;
}
}
if (errcode) {
if (bus->glomerr++ < 3) {
skb_push(pfirst, sfdoff);
brcmf_sdbrcm_rxfail(bus, true, true);
} else {
bus->glomerr = 0;
brcmf_sdbrcm_rxfail(bus, true, false);
brcmu_pkt_buf_free_skb(bus->glom);
bus->rxglomfail++;
bus->glom = NULL;
}
bus->nextlen = 0;
return 0;
}
save_pfirst = pfirst;
bus->glom = NULL;
plast = NULL;
for (num = 0; pfirst; rxseq++, pfirst = pnext) {
pnext = pfirst->next;
pfirst->next = NULL;
dptr = (u8 *) (pfirst->data);
sublen = get_unaligned_le16(dptr);
chan = SDPCM_PACKET_CHANNEL(&dptr[SDPCM_FRAMETAG_LEN]);
seq = SDPCM_PACKET_SEQUENCE(&dptr[SDPCM_FRAMETAG_LEN]);
doff = SDPCM_DOFFSET_VALUE(&dptr[SDPCM_FRAMETAG_LEN]);
BRCMF_GLOM(("%s: Get subframe %d, %p(%p/%d), sublen %d "
"chan %d seq %d\n",
__func__, num, pfirst, pfirst->data,
pfirst->len, sublen, chan, seq));
if (rxseq != seq) {
BRCMF_GLOM(("%s: rx_seq %d, expected %d\n",
__func__, seq, rxseq));
bus->rx_badseq++;
rxseq = seq;
}
#ifdef BCMDBG
if (BRCMF_BYTES_ON() && BRCMF_DATA_ON()) {
printk(KERN_DEBUG "Rx Subframe Data:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
dptr, dlen);
}
#endif
__skb_trim(pfirst, sublen);
skb_pull(pfirst, doff);
if (pfirst->len == 0) {
brcmu_pkt_buf_free_skb(pfirst);
if (plast) {
plast->next = pnext;
} else {
save_pfirst = pnext;
}
continue;
} else if (brcmf_proto_hdrpull(bus->drvr, &ifidx, pfirst)
!= 0) {
BRCMF_ERROR(("%s: rx protocol error\n",
__func__));
bus->drvr->rx_errors++;
brcmu_pkt_buf_free_skb(pfirst);
if (plast) {
plast->next = pnext;
} else {
save_pfirst = pnext;
}
continue;
}
pfirst->next = pnext;
plast = pfirst;
num++;
#ifdef BCMDBG
if (BRCMF_GLOM_ON()) {
BRCMF_GLOM(("%s subframe %d to stack, %p"
"(%p/%d) nxt/lnk %p/%p\n",
__func__, num, pfirst, pfirst->data,
pfirst->len, pfirst->next,
pfirst->prev));
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
pfirst->data,
min_t(int, pfirst->len, 32));
}
#endif
}
if (num) {
brcmf_sdbrcm_sdunlock(bus);
brcmf_rx_frame(bus->drvr, ifidx, save_pfirst, num);
brcmf_sdbrcm_sdlock(bus);
}
bus->rxglomframes++;
bus->rxglompkts += num;
}
return num;
}
static uint
brcmf_sdbrcm_readframes(struct brcmf_bus *bus, uint maxframes, bool *finished)
{
struct brcmf_sdio_card *card = bus->card;
u16 len, check;
u8 chan, seq, doff;
u8 fcbits;
struct sk_buff *pkt;
u16 pad;
u16 rdlen;
u8 rxseq;
uint rxleft = 0;
int sdret;
u8 txmax;
bool len_consistent;
u8 *rxbuf;
int ifidx = 0;
uint rxcount = 0;
#if defined(BCMDBG) || defined(SDTEST)
bool sdtest = false;
#endif
BRCMF_TRACE(("%s: Enter\n", __func__));
#ifdef SDTEST
if (bus->pktgen_count && (bus->pktgen_mode == BRCMF_PKTGEN_RECV)) {
maxframes = bus->pktgen_count;
sdtest = true;
}
#endif
*finished = false;
for (rxseq = bus->rx_seq, rxleft = maxframes;
!bus->rxskip && rxleft && bus->drvr->busstate != BRCMF_BUS_DOWN;
rxseq++, rxleft--) {
if (bus->glom || bus->glomd) {
u8 cnt;
BRCMF_GLOM(("%s: calling rxglom: glomd %p, glom %p\n",
__func__, bus->glomd, bus->glom));
cnt = brcmf_sdbrcm_rxglom(bus, rxseq);
BRCMF_GLOM(("%s: rxglom returned %d\n", __func__, cnt));
rxseq += cnt - 1;
rxleft = (rxleft > cnt) ? (rxleft - cnt) : 1;
continue;
}
if (brcmf_readahead && bus->nextlen) {
u16 nextlen = bus->nextlen;
bus->nextlen = 0;
if (bus->bus == SPI_BUS) {
rdlen = len = nextlen;
} else {
rdlen = len = nextlen << 4;
if (bus->roundup && bus->blocksize
&& (rdlen > bus->blocksize)) {
pad =
bus->blocksize -
(rdlen % bus->blocksize);
if ((pad <= bus->roundup)
&& (pad < bus->blocksize)
&& ((rdlen + pad + firstread) <
MAX_RX_DATASZ))
rdlen += pad;
} else if (rdlen % BRCMF_SDALIGN) {
rdlen +=
BRCMF_SDALIGN - (rdlen % BRCMF_SDALIGN);
}
}
pkt = brcmu_pkt_buf_get_skb(rdlen + BRCMF_SDALIGN);
if (!pkt) {
if (bus->bus == SPI_BUS) {
bus->usebufpool = false;
bus->rxctl = bus->rxbuf;
if (brcmf_alignctl) {
bus->rxctl += firstread;
pad = ((unsigned long)bus->rxctl %
BRCMF_SDALIGN);
if (pad)
bus->rxctl +=
(BRCMF_SDALIGN - pad);
bus->rxctl -= firstread;
}
rxbuf = bus->rxctl;
sdret = brcmf_sdcard_recv_buf(card,
brcmf_sdcard_cur_sbwad(card),
SDIO_FUNC_2, F2SYNC,
rxbuf, rdlen,
NULL, NULL, NULL);
bus->f2rxdata++;
if (sdret < 0) {
BRCMF_ERROR(("%s: read %d "
"control bytes "
"failed: %d\n",
__func__,
rdlen, sdret));
bus->rxc_errors++;
brcmf_sdbrcm_rxfail(bus, true,
(bus->bus ==
SPI_BUS) ? false
: true);
continue;
}
} else {
BRCMF_ERROR(("%s (nextlen): "
"brcmu_pkt_buf_get_skb "
"failed:"
" len %d rdlen %d expected"
" rxseq %d\n", __func__,
len, rdlen, rxseq));
continue;
}
} else {
if (bus->bus == SPI_BUS)
bus->usebufpool = true;
PKTALIGN(pkt, rdlen, BRCMF_SDALIGN);
rxbuf = (u8 *) (pkt->data);
sdret = brcmf_sdcard_recv_buf(card,
brcmf_sdcard_cur_sbwad(card),
SDIO_FUNC_2, F2SYNC,
rxbuf, rdlen,
pkt, NULL, NULL);
bus->f2rxdata++;
if (sdret < 0) {
BRCMF_ERROR(("%s (nextlen): read %d"
" bytes failed: %d\n",
__func__, rdlen, sdret));
brcmu_pkt_buf_free_skb(pkt);
bus->drvr->rx_errors++;
brcmf_sdbrcm_rxfail(bus, true,
(bus->bus ==
SPI_BUS) ? false :
true);
continue;
}
}
memcpy(bus->rxhdr, rxbuf, SDPCM_HDRLEN);
len = get_unaligned_le16(bus->rxhdr);
check = get_unaligned_le16(bus->rxhdr + sizeof(u16));
if (!(len | check)) {
BRCMF_INFO(("%s (nextlen): read zeros in HW "
"header???\n", __func__));
brcmf_sdbrcm_pktfree2(bus, pkt);
continue;
}
if ((u16)~(len ^ check)) {
BRCMF_ERROR(("%s (nextlen): HW hdr error:"
" nextlen/len/check"
" 0x%04x/0x%04x/0x%04x\n",
__func__, nextlen, len, check));
bus->rx_badhdr++;
brcmf_sdbrcm_rxfail(bus, false, false);
brcmf_sdbrcm_pktfree2(bus, pkt);
continue;
}
if (len < SDPCM_HDRLEN) {
BRCMF_ERROR(("%s (nextlen): HW hdr length "
"invalid: %d\n", __func__, len));
brcmf_sdbrcm_pktfree2(bus, pkt);
continue;
}
len_consistent = (nextlen != (roundup(len, 16) >> 4));
if (len_consistent) {
BRCMF_ERROR(("%s (nextlen): mismatch, "
"nextlen %d len %d rnd %d; "
"expected rxseq %d\n",
__func__, nextlen,
len, roundup(len, 16), rxseq));
brcmf_sdbrcm_rxfail(bus, true,
bus->bus != SPI_BUS);
brcmf_sdbrcm_pktfree2(bus, pkt);
continue;
}
chan = SDPCM_PACKET_CHANNEL(
&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
seq = SDPCM_PACKET_SEQUENCE(
&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
doff = SDPCM_DOFFSET_VALUE(
&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
txmax = SDPCM_WINDOW_VALUE(
&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
bus->nextlen =
bus->rxhdr[SDPCM_FRAMETAG_LEN +
SDPCM_NEXTLEN_OFFSET];
if ((bus->nextlen << 4) > MAX_RX_DATASZ) {
BRCMF_INFO(("%s (nextlen): got frame w/nextlen"
" too large (%d), seq %d\n",
__func__, bus->nextlen, seq));
bus->nextlen = 0;
}
bus->drvr->rx_readahead_cnt++;
fcbits = SDPCM_FCMASK_VALUE(
&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
if (bus->flowcontrol != fcbits) {
if (~bus->flowcontrol & fcbits)
bus->fc_xoff++;
if (bus->flowcontrol & ~fcbits)
bus->fc_xon++;
bus->fc_rcvd++;
bus->flowcontrol = fcbits;
}
if (rxseq != seq) {
BRCMF_INFO(("%s (nextlen): rx_seq %d, expected "
"%d\n", __func__, seq, rxseq));
bus->rx_badseq++;
rxseq = seq;
}
if ((u8) (txmax - bus->tx_seq) > 0x40) {
BRCMF_ERROR(("%s: got unlikely tx max %d with "
"tx_seq %d\n",
__func__, txmax, bus->tx_seq));
txmax = bus->tx_seq + 2;
}
bus->tx_max = txmax;
#ifdef BCMDBG
if (BRCMF_BYTES_ON() && BRCMF_DATA_ON()) {
printk(KERN_DEBUG "Rx Data:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
rxbuf, len);
} else if (BRCMF_HDRS_ON()) {
printk(KERN_DEBUG "RxHdr:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
bus->rxhdr, SDPCM_HDRLEN);
}
#endif
if (chan == SDPCM_CONTROL_CHANNEL) {
if (bus->bus == SPI_BUS) {
brcmf_sdbrcm_read_control(bus, rxbuf,
len, doff);
} else {
BRCMF_ERROR(("%s (nextlen): readahead"
" on control packet %d?\n",
__func__, seq));
bus->nextlen = 0;
brcmf_sdbrcm_rxfail(bus, false, true);
}
brcmf_sdbrcm_pktfree2(bus, pkt);
continue;
}
if ((bus->bus == SPI_BUS) && !bus->usebufpool) {
BRCMF_ERROR(("Received %d bytes on %d channel."
" Running out of " "rx pktbuf's or"
" not yet malloced.\n",
len, chan));
continue;
}
if ((doff < SDPCM_HDRLEN) || (doff > len)) {
BRCMF_ERROR(("%s (nextlen): bad data offset %d:"
" HW len %d min %d\n", __func__,
doff, len, SDPCM_HDRLEN));
brcmf_sdbrcm_rxfail(bus, false, false);
brcmf_sdbrcm_pktfree2(bus, pkt);
continue;
}
goto deliver;
}
if (bus->bus == SPI_BUS)
break;
sdret = brcmf_sdcard_recv_buf(card,
brcmf_sdcard_cur_sbwad(card),
SDIO_FUNC_2, F2SYNC, bus->rxhdr, firstread,
NULL, NULL, NULL);
bus->f2rxhdrs++;
if (sdret < 0) {
BRCMF_ERROR(("%s: RXHEADER FAILED: %d\n", __func__,
sdret));
bus->rx_hdrfail++;
brcmf_sdbrcm_rxfail(bus, true, true);
continue;
}
#ifdef BCMDBG
if (BRCMF_BYTES_ON() || BRCMF_HDRS_ON()) {
printk(KERN_DEBUG "RxHdr:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
bus->rxhdr, SDPCM_HDRLEN);
}
#endif
len = get_unaligned_le16(bus->rxhdr);
check = get_unaligned_le16(bus->rxhdr + sizeof(u16));
if (!(len | check)) {
*finished = true;
break;
}
if ((u16) ~(len ^ check)) {
BRCMF_ERROR(("%s: HW hdr err: len/check "
"0x%04x/0x%04x\n", __func__, len, check));
bus->rx_badhdr++;
brcmf_sdbrcm_rxfail(bus, false, false);
continue;
}
if (len < SDPCM_HDRLEN) {
BRCMF_ERROR(("%s: HW hdr length invalid: %d\n",
__func__, len));
continue;
}
chan = SDPCM_PACKET_CHANNEL(&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
seq = SDPCM_PACKET_SEQUENCE(&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
doff = SDPCM_DOFFSET_VALUE(&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
txmax = SDPCM_WINDOW_VALUE(&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
if ((doff < SDPCM_HDRLEN) || (doff > len)) {
BRCMF_ERROR(("%s: Bad data offset %d: HW len %d,"
" min %d seq %d\n", __func__, doff,
len, SDPCM_HDRLEN, seq));
bus->rx_badhdr++;
brcmf_sdbrcm_rxfail(bus, false, false);
continue;
}
bus->nextlen =
bus->rxhdr[SDPCM_FRAMETAG_LEN + SDPCM_NEXTLEN_OFFSET];
if ((bus->nextlen << 4) > MAX_RX_DATASZ) {
BRCMF_INFO(("%s (nextlen): got frame w/nextlen too"
" large (%d), seq %d\n",
__func__, bus->nextlen, seq));
bus->nextlen = 0;
}
fcbits = SDPCM_FCMASK_VALUE(&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
if (bus->flowcontrol != fcbits) {
if (~bus->flowcontrol & fcbits)
bus->fc_xoff++;
if (bus->flowcontrol & ~fcbits)
bus->fc_xon++;
bus->fc_rcvd++;
bus->flowcontrol = fcbits;
}
if (rxseq != seq) {
BRCMF_INFO(("%s: rx_seq %d, expected %d\n", __func__,
seq, rxseq));
bus->rx_badseq++;
rxseq = seq;
}
if ((u8) (txmax - bus->tx_seq) > 0x40) {
BRCMF_ERROR(("%s: unlikely tx max %d with tx_seq %d\n",
__func__, txmax, bus->tx_seq));
txmax = bus->tx_seq + 2;
}
bus->tx_max = txmax;
if (chan == SDPCM_CONTROL_CHANNEL) {
brcmf_sdbrcm_read_control(bus, bus->rxhdr, len, doff);
continue;
}
rdlen = (len > firstread) ? (len - firstread) : 0;
if (bus->roundup && bus->blocksize &&
(rdlen > bus->blocksize)) {
pad = bus->blocksize - (rdlen % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize) &&
((rdlen + pad + firstread) < MAX_RX_DATASZ))
rdlen += pad;
} else if (rdlen % BRCMF_SDALIGN) {
rdlen += BRCMF_SDALIGN - (rdlen % BRCMF_SDALIGN);
}
if (forcealign && (rdlen & (ALIGNMENT - 1)))
rdlen = roundup(rdlen, ALIGNMENT);
if ((rdlen + firstread) > MAX_RX_DATASZ) {
BRCMF_ERROR(("%s: too long: len %d rdlen %d\n",
__func__, len, rdlen));
bus->drvr->rx_errors++;
bus->rx_toolong++;
brcmf_sdbrcm_rxfail(bus, false, false);
continue;
}
pkt = brcmu_pkt_buf_get_skb(rdlen + firstread + BRCMF_SDALIGN);
if (!pkt) {
BRCMF_ERROR(("%s: brcmu_pkt_buf_get_skb failed:"
" rdlen %d chan %d\n", __func__, rdlen,
chan));
bus->drvr->rx_dropped++;
brcmf_sdbrcm_rxfail(bus, false, RETRYCHAN(chan));
continue;
}
skb_pull(pkt, firstread);
PKTALIGN(pkt, rdlen, BRCMF_SDALIGN);
sdret = brcmf_sdcard_recv_buf(card,
brcmf_sdcard_cur_sbwad(card),
SDIO_FUNC_2, F2SYNC, ((u8 *) (pkt->data)),
rdlen, pkt, NULL, NULL);
bus->f2rxdata++;
if (sdret < 0) {
BRCMF_ERROR(("%s: read %d %s bytes failed: %d\n",
__func__, rdlen,
((chan == SDPCM_EVENT_CHANNEL) ? "event"
: ((chan == SDPCM_DATA_CHANNEL) ? "data"
: "test")), sdret));
brcmu_pkt_buf_free_skb(pkt);
bus->drvr->rx_errors++;
brcmf_sdbrcm_rxfail(bus, true, RETRYCHAN(chan));
continue;
}
skb_push(pkt, firstread);
memcpy(pkt->data, bus->rxhdr, firstread);
#ifdef BCMDBG
if (BRCMF_BYTES_ON() && BRCMF_DATA_ON()) {
printk(KERN_DEBUG "Rx Data:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
pkt->data, len);
}
#endif
deliver:
if (chan == SDPCM_GLOM_CHANNEL) {
if (SDPCM_GLOMDESC(&bus->rxhdr[SDPCM_FRAMETAG_LEN])) {
BRCMF_GLOM(("%s: glom descriptor, %d bytes:\n",
__func__, len));
#ifdef BCMDBG
if (BRCMF_GLOM_ON()) {
printk(KERN_DEBUG "Glom Data:\n");
print_hex_dump_bytes("",
DUMP_PREFIX_OFFSET,
pkt->data, len);
}
#endif
__skb_trim(pkt, len);
skb_pull(pkt, SDPCM_HDRLEN);
bus->glomd = pkt;
} else {
BRCMF_ERROR(("%s: glom superframe w/o "
"descriptor!\n", __func__));
brcmf_sdbrcm_rxfail(bus, false, false);
}
continue;
}
__skb_trim(pkt, len);
skb_pull(pkt, doff);
#ifdef SDTEST
if (chan == SDPCM_TEST_CHANNEL) {
brcmf_sdbrcm_checkdied(bus, pkt, seq);
continue;
}
#endif
if (pkt->len == 0) {
brcmu_pkt_buf_free_skb(pkt);
continue;
} else if (brcmf_proto_hdrpull(bus->drvr, &ifidx, pkt) != 0) {
BRCMF_ERROR(("%s: rx protocol error\n", __func__));
brcmu_pkt_buf_free_skb(pkt);
bus->drvr->rx_errors++;
continue;
}
brcmf_sdbrcm_sdunlock(bus);
brcmf_rx_frame(bus->drvr, ifidx, pkt, 1);
brcmf_sdbrcm_sdlock(bus);
}
rxcount = maxframes - rxleft;
#ifdef BCMDBG
if (!rxleft && !sdtest)
BRCMF_DATA(("%s: hit rx limit of %d frames\n", __func__,
maxframes));
else
#endif
BRCMF_DATA(("%s: processed %d frames\n", __func__, rxcount));
if (bus->rxskip)
rxseq--;
bus->rx_seq = rxseq;
return rxcount;
}
static u32 brcmf_sdbrcm_hostmail(struct brcmf_bus *bus)
{
u32 intstatus = 0;
u32 hmb_data;
u8 fcbits;
uint retries = 0;
BRCMF_TRACE(("%s: Enter\n", __func__));
r_sdreg32(bus, &hmb_data,
offsetof(struct sdpcmd_regs, tohostmailboxdata), &retries);
if (retries <= retry_limit)
w_sdreg32(bus, SMB_INT_ACK,
offsetof(struct sdpcmd_regs, tosbmailbox), &retries);
bus->f1regdata += 2;
if (hmb_data & HMB_DATA_NAKHANDLED) {
BRCMF_INFO(("Dongle reports NAK handled, expect rtx of %d\n",
bus->rx_seq));
if (!bus->rxskip)
BRCMF_ERROR(("%s: unexpected NAKHANDLED!\n", __func__));
bus->rxskip = false;
intstatus |= I_HMB_FRAME_IND;
}
if (hmb_data & (HMB_DATA_DEVREADY | HMB_DATA_FWREADY)) {
bus->sdpcm_ver =
(hmb_data & HMB_DATA_VERSION_MASK) >>
HMB_DATA_VERSION_SHIFT;
if (bus->sdpcm_ver != SDPCM_PROT_VERSION)
BRCMF_ERROR(("Version mismatch, dongle reports %d, "
"expecting %d\n",
bus->sdpcm_ver, SDPCM_PROT_VERSION));
else
BRCMF_INFO(("Dongle ready, protocol version %d\n",
bus->sdpcm_ver));
}
if (hmb_data & HMB_DATA_FC) {
fcbits = (hmb_data & HMB_DATA_FCDATA_MASK) >>
HMB_DATA_FCDATA_SHIFT;
if (fcbits & ~bus->flowcontrol)
bus->fc_xoff++;
if (bus->flowcontrol & ~fcbits)
bus->fc_xon++;
bus->fc_rcvd++;
bus->flowcontrol = fcbits;
}
if (hmb_data & ~(HMB_DATA_DEVREADY |
HMB_DATA_NAKHANDLED |
HMB_DATA_FC |
HMB_DATA_FWREADY |
HMB_DATA_FCDATA_MASK | HMB_DATA_VERSION_MASK)) {
BRCMF_ERROR(("Unknown mailbox data content: 0x%02x\n",
hmb_data));
}
return intstatus;
}
static bool brcmf_sdbrcm_dpc(struct brcmf_bus *bus)
{
struct brcmf_sdio_card *card = bus->card;
u32 intstatus, newstatus = 0;
uint retries = 0;
uint rxlimit = brcmf_rxbound;
uint txlimit = brcmf_txbound;
uint framecnt = 0;
bool rxdone = true;
bool resched = false;
BRCMF_TRACE(("%s: Enter\n", __func__));
intstatus = bus->intstatus;
brcmf_sdbrcm_sdlock(bus);
if (bus->clkstate == CLK_PENDING) {
int err;
u8 clkctl, devctl = 0;
#ifdef BCMDBG
devctl = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, &err);
if (err) {
BRCMF_ERROR(("%s: error reading DEVCTL: %d\n",
__func__, err));
bus->drvr->busstate = BRCMF_BUS_DOWN;
}
#endif
clkctl = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (err) {
BRCMF_ERROR(("%s: error reading CSR: %d\n", __func__,
err));
bus->drvr->busstate = BRCMF_BUS_DOWN;
}
BRCMF_INFO(("DPC: PENDING, devctl 0x%02x clkctl 0x%02x\n",
devctl, clkctl));
if (SBSDIO_HTAV(clkctl)) {
devctl = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, &err);
if (err) {
BRCMF_ERROR(("%s: error reading DEVCTL: %d\n",
__func__, err));
bus->drvr->busstate = BRCMF_BUS_DOWN;
}
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_DEVICE_CTL, devctl, &err);
if (err) {
BRCMF_ERROR(("%s: error writing DEVCTL: %d\n",
__func__, err));
bus->drvr->busstate = BRCMF_BUS_DOWN;
}
bus->clkstate = CLK_AVAIL;
} else {
goto clkwait;
}
}
BUS_WAKE(bus);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, true);
if (bus->clkstate == CLK_PENDING)
goto clkwait;
if (bus->ipend) {
bus->ipend = false;
r_sdreg32(bus, &newstatus,
offsetof(struct sdpcmd_regs, intstatus), &retries);
bus->f1regdata++;
if (brcmf_sdcard_regfail(bus->card))
newstatus = 0;
newstatus &= bus->hostintmask;
bus->fcstate = !!(newstatus & I_HMB_FC_STATE);
if (newstatus) {
w_sdreg32(bus, newstatus,
offsetof(struct sdpcmd_regs, intstatus),
&retries);
bus->f1regdata++;
}
}
intstatus |= newstatus;
bus->intstatus = 0;
if (intstatus & I_HMB_FC_CHANGE) {
intstatus &= ~I_HMB_FC_CHANGE;
w_sdreg32(bus, I_HMB_FC_CHANGE,
offsetof(struct sdpcmd_regs, intstatus), &retries);
r_sdreg32(bus, &newstatus,
offsetof(struct sdpcmd_regs, intstatus), &retries);
bus->f1regdata += 2;
bus->fcstate =
!!(newstatus & (I_HMB_FC_STATE | I_HMB_FC_CHANGE));
intstatus |= (newstatus & bus->hostintmask);
}
if (intstatus & I_HMB_HOST_INT) {
intstatus &= ~I_HMB_HOST_INT;
intstatus |= brcmf_sdbrcm_hostmail(bus);
}
if (intstatus & I_WR_OOSYNC) {
BRCMF_ERROR(("Dongle reports WR_OOSYNC\n"));
intstatus &= ~I_WR_OOSYNC;
}
if (intstatus & I_RD_OOSYNC) {
BRCMF_ERROR(("Dongle reports RD_OOSYNC\n"));
intstatus &= ~I_RD_OOSYNC;
}
if (intstatus & I_SBINT) {
BRCMF_ERROR(("Dongle reports SBINT\n"));
intstatus &= ~I_SBINT;
}
if (intstatus & I_CHIPACTIVE) {
BRCMF_INFO(("Dongle reports CHIPACTIVE\n"));
intstatus &= ~I_CHIPACTIVE;
}
if (bus->rxskip)
intstatus &= ~I_HMB_FRAME_IND;
if (PKT_AVAILABLE()) {
framecnt = brcmf_sdbrcm_readframes(bus, rxlimit, &rxdone);
if (rxdone || bus->rxskip)
intstatus &= ~I_HMB_FRAME_IND;
rxlimit -= min(framecnt, rxlimit);
}
bus->intstatus = intstatus;
clkwait:
if (bus->intr && bus->intdis && !brcmf_sdcard_regfail(card)) {
BRCMF_INTR(("%s: enable SDIO interrupts, rxdone %d"
" framecnt %d\n", __func__, rxdone, framecnt));
bus->intdis = false;
brcmf_sdcard_intr_enable(card);
}
if (DATAOK(bus) && bus->ctrl_frame_stat &&
(bus->clkstate == CLK_AVAIL)) {
int ret, i;
ret = brcmf_sdbrcm_send_buf(bus, brcmf_sdcard_cur_sbwad(card),
SDIO_FUNC_2, F2SYNC, (u8 *) bus->ctrl_frame_buf,
(u32) bus->ctrl_frame_len, NULL, NULL, NULL);
if (ret < 0) {
BRCMF_INFO(("%s: sdio error %d, abort command and "
"terminate frame.\n", __func__, ret));
bus->tx_sderrs++;
brcmf_sdcard_abort(card, SDIO_FUNC_2);
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1,
SBSDIO_FUNC1_FRAMECTRL, SFC_WF_TERM,
NULL);
bus->f1regdata++;
for (i = 0; i < 3; i++) {
u8 hi, lo;
hi = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCHI,
NULL);
lo = brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCLO,
NULL);
bus->f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
}
}
if (ret == 0)
bus->tx_seq = (bus->tx_seq + 1) % SDPCM_SEQUENCE_WRAP;
BRCMF_INFO(("Return_dpc value is : %d\n", ret));
bus->ctrl_frame_stat = false;
brcmf_sdbrcm_wait_event_wakeup(bus);
}
else if ((bus->clkstate == CLK_AVAIL) && !bus->fcstate &&
brcmu_pktq_mlen(&bus->txq, ~bus->flowcontrol) && txlimit
&& DATAOK(bus)) {
framecnt = rxdone ? txlimit : min(txlimit, brcmf_txminmax);
framecnt = brcmf_sdbrcm_sendfromq(bus, framecnt);
txlimit -= framecnt;
}
if ((bus->drvr->busstate == BRCMF_BUS_DOWN) ||
brcmf_sdcard_regfail(card)) {
BRCMF_ERROR(("%s: failed backplane access over SDIO, halting "
"operation %d\n", __func__,
brcmf_sdcard_regfail(card)));
bus->drvr->busstate = BRCMF_BUS_DOWN;
bus->intstatus = 0;
} else if (bus->clkstate == CLK_PENDING) {
BRCMF_INFO(("%s: rescheduled due to CLK_PENDING awaiting "
"I_CHIPACTIVE interrupt\n", __func__));
resched = true;
} else if (bus->intstatus || bus->ipend ||
(!bus->fcstate && brcmu_pktq_mlen(&bus->txq, ~bus->flowcontrol)
&& DATAOK(bus)) || PKT_AVAILABLE()) {
resched = true;
}
bus->dpc_sched = resched;
if ((bus->clkstate != CLK_PENDING)
&& bus->idletime == BRCMF_IDLE_IMMEDIATE) {
bus->activity = false;
brcmf_sdbrcm_clkctl(bus, CLK_NONE, false);
}
brcmf_sdbrcm_sdunlock(bus);
return resched;
}
void brcmf_sdbrcm_isr(void *arg)
{
struct brcmf_bus *bus = (struct brcmf_bus *) arg;
struct brcmf_sdio_card *card;
BRCMF_TRACE(("%s: Enter\n", __func__));
if (!bus) {
BRCMF_ERROR(("%s : bus is null pointer , exit\n", __func__));
return;
}
card = bus->card;
if (bus->drvr->busstate == BRCMF_BUS_DOWN) {
BRCMF_ERROR(("%s : bus is down. we have nothing to do\n",
__func__));
return;
}
bus->intrcount++;
bus->ipend = true;
if (bus->sleeping) {
BRCMF_ERROR(("INTERRUPT WHILE SLEEPING??\n"));
return;
}
if (bus->intr)
BRCMF_INTR(("%s: disable SDIO interrupts\n", __func__));
else
BRCMF_ERROR(("brcmf_sdbrcm_isr() w/o interrupt configured!\n"));
brcmf_sdcard_intr_disable(card);
bus->intdis = true;
#if defined(SDIO_ISR_THREAD)
BRCMF_TRACE(("Calling brcmf_sdbrcm_dpc() from %s\n", __func__));
while (brcmf_sdbrcm_dpc(bus))
;
#else
bus->dpc_sched = true;
brcmf_sdbrcm_sched_dpc(bus);
#endif
}
static void brcmf_sdbrcm_pktgen_init(struct brcmf_bus *bus)
{
if (brcmf_pktgen_len) {
bus->pktgen_maxlen = min(brcmf_pktgen_len,
BRCMF_MAX_PKTGEN_LEN);
bus->pktgen_minlen = bus->pktgen_maxlen;
} else {
bus->pktgen_maxlen = BRCMF_MAX_PKTGEN_LEN;
bus->pktgen_minlen = 0;
}
bus->pktgen_len = (u16) bus->pktgen_minlen;
bus->pktgen_freq = 1;
bus->pktgen_print = 10000 / brcmf_watchdog_ms;
bus->pktgen_count = (brcmf_pktgen * brcmf_watchdog_ms + 999) / 1000;
bus->pktgen_mode = BRCMF_PKTGEN_ECHO;
bus->pktgen_stop = 1;
}
static void brcmf_sdbrcm_pktgen(struct brcmf_bus *bus)
{
struct sk_buff *pkt;
u8 *data;
uint pktcount;
uint fillbyte;
u16 len;
if (bus->pktgen_print && (++bus->pktgen_ptick >= bus->pktgen_print)) {
bus->pktgen_ptick = 0;
printk(KERN_DEBUG "%s: send attempts %d rcvd %d\n",
__func__, bus->pktgen_sent, bus->pktgen_rcvd);
}
if (bus->pktgen_mode == BRCMF_PKTGEN_RECV) {
if (!bus->pktgen_rcvd)
brcmf_sdbrcm_sdtest_set(bus, true);
return;
}
for (pktcount = 0; pktcount < bus->pktgen_count; pktcount++) {
if (bus->pktgen_total
&& (bus->pktgen_sent >= bus->pktgen_total)) {
bus->pktgen_count = 0;
break;
}
len = bus->pktgen_len;
pkt = brcmu_pkt_buf_get_skb(
len + SDPCM_HDRLEN + SDPCM_TEST_HDRLEN + BRCMF_SDALIGN,
true);
if (!pkt) {
BRCMF_ERROR(("%s: brcmu_pkt_buf_get_skb failed!\n",
__func__));
break;
}
PKTALIGN(pkt, (len + SDPCM_HDRLEN + SDPCM_TEST_HDRLEN),
BRCMF_SDALIGN);
data = (u8 *) (pkt->data) + SDPCM_HDRLEN;
switch (bus->pktgen_mode) {
case BRCMF_PKTGEN_ECHO:
*data++ = SDPCM_TEST_ECHOREQ;
*data++ = (u8) bus->pktgen_sent;
break;
case BRCMF_PKTGEN_SEND:
*data++ = SDPCM_TEST_DISCARD;
*data++ = (u8) bus->pktgen_sent;
break;
case BRCMF_PKTGEN_RXBURST:
*data++ = SDPCM_TEST_BURST;
*data++ = (u8) bus->pktgen_count;
break;
default:
BRCMF_ERROR(("Unrecognized pktgen mode %d\n",
bus->pktgen_mode));
brcmu_pkt_buf_free_skb(pkt, true);
bus->pktgen_count = 0;
return;
}
*data++ = (len >> 0);
*data++ = (len >> 8);
for (fillbyte = 0; fillbyte < len; fillbyte++)
*data++ =
SDPCM_TEST_FILL(fillbyte, (u8) bus->pktgen_sent);
#ifdef BCMDBG
if (BRCMF_BYTES_ON() && BRCMF_DATA_ON()) {
data = (u8 *) (pkt->data) + SDPCM_HDRLEN;
printk(KERN_DEBUG "brcmf_sdbrcm_pktgen: Tx Data:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, data,
pkt->len - SDPCM_HDRLEN);
}
#endif
if (brcmf_sdbrcm_txpkt(bus, pkt, SDPCM_TEST_CHANNEL, true)) {
bus->pktgen_fail++;
if (bus->pktgen_stop
&& bus->pktgen_stop == bus->pktgen_fail)
bus->pktgen_count = 0;
}
bus->pktgen_sent++;
if (++bus->pktgen_len > bus->pktgen_maxlen)
bus->pktgen_len = (u16) bus->pktgen_minlen;
if (bus->pktgen_mode == BRCMF_PKTGEN_RXBURST)
break;
}
}
static void brcmf_sdbrcm_sdtest_set(struct brcmf_bus *bus, bool start)
{
struct sk_buff *pkt;
u8 *data;
pkt = brcmu_pkt_buf_get_skb(SDPCM_HDRLEN + SDPCM_TEST_HDRLEN +
BRCMF_SDALIGN, true);
if (!pkt) {
BRCMF_ERROR(("%s: brcmu_pkt_buf_get_skb failed!\n", __func__));
return;
}
PKTALIGN(pkt, (SDPCM_HDRLEN + SDPCM_TEST_HDRLEN), BRCMF_SDALIGN);
data = (u8 *) (pkt->data) + SDPCM_HDRLEN;
*data++ = SDPCM_TEST_SEND;
*data++ = start;
*data++ = (bus->pktgen_maxlen >> 0);
*data++ = (bus->pktgen_maxlen >> 8);
if (brcmf_sdbrcm_txpkt(bus, pkt, SDPCM_TEST_CHANNEL, true))
bus->pktgen_fail++;
}
static void
brcmf_sdbrcm_checkdied(struct brcmf_bus *bus, struct sk_buff *pkt, uint seq)
{
u8 *data;
uint pktlen;
u8 cmd;
u8 extra;
u16 len;
u16 offset;
pktlen = pkt->len;
if (pktlen < SDPCM_TEST_HDRLEN) {
BRCMF_ERROR(("brcmf_sdbrcm_checkdied: toss runt frame, pktlen "
"%d\n", pktlen));
brcmu_pkt_buf_free_skb(pkt, false);
return;
}
data = pkt->data;
cmd = *data++;
extra = *data++;
len = *data++;
len += *data++ << 8;
if (cmd == SDPCM_TEST_DISCARD || cmd == SDPCM_TEST_ECHOREQ
|| cmd == SDPCM_TEST_ECHORSP) {
if (pktlen != len + SDPCM_TEST_HDRLEN) {
BRCMF_ERROR(("brcmf_sdbrcm_checkdied: frame length "
"mismatch, pktlen %d seq %d"
" cmd %d extra %d len %d\n",
pktlen, seq, cmd, extra, len));
brcmu_pkt_buf_free_skb(pkt, false);
return;
}
}
switch (cmd) {
case SDPCM_TEST_ECHOREQ:
*(u8 *) (pkt->data) = SDPCM_TEST_ECHORSP;
if (brcmf_sdbrcm_txpkt(bus, pkt, SDPCM_TEST_CHANNEL, true) == 0)
bus->pktgen_sent++;
else {
bus->pktgen_fail++;
brcmu_pkt_buf_free_skb(pkt, false);
}
bus->pktgen_rcvd++;
break;
case SDPCM_TEST_ECHORSP:
if (bus->ext_loop) {
brcmu_pkt_buf_free_skb(pkt, false);
bus->pktgen_rcvd++;
break;
}
for (offset = 0; offset < len; offset++, data++) {
if (*data != SDPCM_TEST_FILL(offset, extra)) {
BRCMF_ERROR(("brcmf_sdbrcm_checkdied: echo"
" data mismatch: "
"offset %d (len %d) "
"expect 0x%02x rcvd 0x%02x\n",
offset, len,
SDPCM_TEST_FILL(offset, extra),
*data));
break;
}
}
brcmu_pkt_buf_free_skb(pkt, false);
bus->pktgen_rcvd++;
break;
case SDPCM_TEST_DISCARD:
brcmu_pkt_buf_free_skb(pkt, false);
bus->pktgen_rcvd++;
break;
case SDPCM_TEST_BURST:
case SDPCM_TEST_SEND:
default:
BRCMF_INFO(("brcmf_sdbrcm_checkdied: unsupported or unknown "
"command, pktlen %d seq %d" " cmd %d extra %d"
" len %d\n", pktlen, seq, cmd, extra, len));
brcmu_pkt_buf_free_skb(pkt, false);
break;
}
if (bus->pktgen_mode == BRCMF_PKTGEN_RECV) {
if (bus->pktgen_total
&& (bus->pktgen_rcvd >= bus->pktgen_total)) {
bus->pktgen_count = 0;
brcmf_sdbrcm_sdtest_set(bus, false);
}
}
}
extern bool brcmf_sdbrcm_bus_watchdog(struct brcmf_pub *drvr)
{
struct brcmf_bus *bus;
BRCMF_TIMER(("%s: Enter\n", __func__));
bus = drvr->bus;
if (bus->drvr->dongle_reset)
return false;
if (bus->sleeping)
return false;
brcmf_sdbrcm_sdlock(bus);
if (bus->poll && (++bus->polltick >= bus->pollrate)) {
u32 intstatus = 0;
bus->polltick = 0;
if (!bus->intr || (bus->intrcount == bus->lastintrs)) {
if (!bus->dpc_sched) {
u8 devpend;
devpend = brcmf_sdcard_cfg_read(bus->card,
SDIO_FUNC_0, SDIO_CCCR_INTx,
NULL);
intstatus =
devpend & (INTR_STATUS_FUNC1 |
INTR_STATUS_FUNC2);
}
if (intstatus) {
bus->pollcnt++;
bus->ipend = true;
if (bus->intr)
brcmf_sdcard_intr_disable(bus->card);
bus->dpc_sched = true;
brcmf_sdbrcm_sched_dpc(bus);
}
}
bus->lastintrs = bus->intrcount;
}
#ifdef BCMDBG
if (drvr->busstate == BRCMF_BUS_DATA && brcmf_console_ms != 0) {
bus->console.count += brcmf_watchdog_ms;
if (bus->console.count >= brcmf_console_ms) {
bus->console.count -= brcmf_console_ms;
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
if (brcmf_sdbrcm_readconsole(bus) < 0)
brcmf_console_ms = 0;
}
}
#endif
#ifdef SDTEST
if (bus->pktgen_count && (++bus->pktgen_tick >= bus->pktgen_freq)) {
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
bus->pktgen_tick = 0;
brcmf_sdbrcm_pktgen(bus);
}
#endif
if ((bus->idletime > 0) && (bus->clkstate == CLK_AVAIL)) {
if (++bus->idlecount >= bus->idletime) {
bus->idlecount = 0;
if (bus->activity) {
bus->activity = false;
brcmf_sdbrcm_wd_timer(bus, brcmf_watchdog_ms);
} else {
brcmf_sdbrcm_clkctl(bus, CLK_NONE, false);
}
}
}
brcmf_sdbrcm_sdunlock(bus);
return bus->ipend;
}
static int brcmf_sdbrcm_bus_console_in(struct brcmf_pub *drvr,
unsigned char *msg, uint msglen)
{
struct brcmf_bus *bus = drvr->bus;
u32 addr, val;
int rv;
struct sk_buff *pkt;
if (bus->console_addr == 0)
return -ENOTSUPP;
brcmf_sdbrcm_sdlock(bus);
if (bus->drvr->dongle_reset) {
brcmf_sdbrcm_sdunlock(bus);
return -EPERM;
}
BUS_WAKE(bus);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
addr = bus->console_addr + offsetof(struct rte_console, cbuf_idx);
val = cpu_to_le32(0);
rv = brcmf_sdbrcm_membytes(bus, true, addr, (u8 *)&val, sizeof(val));
if (rv < 0)
goto done;
addr = bus->console_addr + offsetof(struct rte_console, cbuf);
rv = brcmf_sdbrcm_membytes(bus, true, addr, (u8 *)msg, msglen);
if (rv < 0)
goto done;
addr = bus->console_addr + offsetof(struct rte_console, vcons_in);
val = cpu_to_le32(msglen);
rv = brcmf_sdbrcm_membytes(bus, true, addr, (u8 *)&val, sizeof(val));
if (rv < 0)
goto done;
pkt = brcmu_pkt_buf_get_skb(4 + SDPCM_RESERVE);
if ((pkt != NULL) && bus->clkstate == CLK_AVAIL)
brcmf_sdbrcm_txpkt(bus, pkt, SDPCM_EVENT_CHANNEL, true);
done:
if ((bus->idletime == BRCMF_IDLE_IMMEDIATE) && !bus->dpc_sched) {
bus->activity = false;
brcmf_sdbrcm_clkctl(bus, CLK_NONE, true);
}
brcmf_sdbrcm_sdunlock(bus);
return rv;
}
static bool brcmf_sdbrcm_chipmatch(u16 chipid)
{
if (chipid == BCM4325_CHIP_ID)
return true;
if (chipid == BCM4329_CHIP_ID)
return true;
if (chipid == BCM4319_CHIP_ID)
return true;
return false;
}
static void *brcmf_sdbrcm_probe(u16 venid, u16 devid, u16 bus_no,
u16 slot, u16 func, uint bustype, u32 regsva,
void *card)
{
int ret;
struct brcmf_bus *bus;
brcmf_txbound = BRCMF_TXBOUND;
brcmf_rxbound = BRCMF_RXBOUND;
brcmf_alignctl = true;
sd1idle = true;
brcmf_readahead = true;
retrydata = false;
brcmf_dongle_memsize = 0;
brcmf_txminmax = BRCMF_TXMINMAX;
forcealign = true;
brcmf_c_init();
BRCMF_TRACE(("%s: Enter\n", __func__));
BRCMF_INFO(("%s: venid 0x%04x devid 0x%04x\n", __func__, venid, devid));
switch (venid) {
case 0x0000:
case PCI_VENDOR_ID_BROADCOM:
break;
default:
BRCMF_ERROR(("%s: unknown vendor: 0x%04x\n", __func__, venid));
return NULL;
}
switch (devid) {
case BCM4325_D11DUAL_ID:
case BCM4325_D11G_ID:
case BCM4325_D11A_ID:
BRCMF_INFO(("%s: found 4325 Dongle\n", __func__));
break;
case BCM4329_D11NDUAL_ID:
case BCM4329_D11N2G_ID:
case BCM4329_D11N5G_ID:
case 0x4329:
BRCMF_INFO(("%s: found 4329 Dongle\n", __func__));
break;
case BCM4319_D11N_ID:
case BCM4319_D11N2G_ID:
case BCM4319_D11N5G_ID:
BRCMF_INFO(("%s: found 4319 Dongle\n", __func__));
break;
case 0:
BRCMF_INFO(("%s: allow device id 0, will check chip"
" internals\n", __func__));
break;
default:
BRCMF_ERROR(("%s: skipping 0x%04x/0x%04x, not a dongle\n",
__func__, venid, devid));
return NULL;
}
bus = kzalloc(sizeof(struct brcmf_bus), GFP_ATOMIC);
if (!bus) {
BRCMF_ERROR(("%s: kmalloc of struct dhd_bus failed\n",
__func__));
goto fail;
}
bus->card = card;
bus->cl_devid = (u16) devid;
bus->bus = BRCMF_BUS;
bus->tx_seq = SDPCM_SEQUENCE_WRAP - 1;
bus->usebufpool = false;
if (!(brcmf_sdbrcm_probe_attach(bus, card, regsva, devid))) {
BRCMF_ERROR(("%s: brcmf_sdbrcm_probe_attach failed\n",
__func__));
goto fail;
}
spin_lock_init(&bus->txqlock);
init_waitqueue_head(&bus->ctrl_wait);
init_timer(&bus->timer);
bus->timer.data = (unsigned long)bus;
bus->timer.function = brcmf_sdbrcm_watchdog;
if ((brcmf_watchdog_prio >= 0) && (brcmf_dpc_prio >= 0)) {
bus->threads_only = true;
sema_init(&bus->sdsem, 1);
} else {
bus->threads_only = false;
spin_lock_init(&bus->sdlock);
}
if (brcmf_dpc_prio >= 0) {
init_completion(&bus->watchdog_wait);
bus->watchdog_tsk = kthread_run(brcmf_sdbrcm_watchdog_thread,
bus, "brcmf_watchdog");
if (IS_ERR(bus->watchdog_tsk)) {
printk(KERN_WARNING
"brcmf_watchdog thread failed to start\n");
bus->watchdog_tsk = NULL;
}
} else
bus->watchdog_tsk = NULL;
if (brcmf_dpc_prio >= 0) {
init_completion(&bus->dpc_wait);
bus->dpc_tsk = kthread_run(brcmf_sdbrcm_dpc_thread,
bus, "brcmf_dpc");
if (IS_ERR(bus->dpc_tsk)) {
printk(KERN_WARNING
"brcmf_dpc thread failed to start\n");
bus->dpc_tsk = NULL;
}
} else {
tasklet_init(&bus->tasklet, brcmf_sdbrcm_dpc_tasklet,
(unsigned long)bus);
bus->dpc_tsk = NULL;
}
bus->drvr = brcmf_attach(bus, SDPCM_RESERVE);
if (!bus->drvr) {
BRCMF_ERROR(("%s: brcmf_attach failed\n", __func__));
goto fail;
}
if (!(brcmf_sdbrcm_probe_malloc(bus, card))) {
BRCMF_ERROR(("%s: brcmf_sdbrcm_probe_malloc failed\n",
__func__));
goto fail;
}
if (!(brcmf_sdbrcm_probe_init(bus, card))) {
BRCMF_ERROR(("%s: brcmf_sdbrcm_probe_init failed\n", __func__));
goto fail;
}
BRCMF_INTR(("%s: disable SDIO interrupts (not interested yet)\n",
__func__));
brcmf_sdcard_intr_disable(card);
ret = brcmf_sdcard_intr_reg(card, brcmf_sdbrcm_isr, bus);
if (ret != 0) {
BRCMF_ERROR(("%s: FAILED: sdcard_intr_reg returned %d\n",
__func__, ret));
goto fail;
}
BRCMF_INTR(("%s: registered SDIO interrupt function ok\n", __func__));
BRCMF_INFO(("%s: completed!!\n", __func__));
ret = brcmf_bus_start(bus->drvr);
if (ret != 0) {
if (ret == -ENOLINK) {
BRCMF_ERROR(("%s: dongle is not responding\n",
__func__));
goto fail;
}
}
if (brcmf_net_attach(bus->drvr, 0) != 0) {
BRCMF_ERROR(("%s: Net attach failed!!\n", __func__));
goto fail;
}
return bus;
fail:
brcmf_sdbrcm_release(bus);
return NULL;
}
static bool
brcmf_sdbrcm_probe_attach(struct brcmf_bus *bus, void *card, u32 regsva,
u16 devid)
{
u8 clkctl = 0;
int err = 0;
bus->alp_only = true;
if (brcmf_sdbrcm_set_siaddr_window(bus, SI_ENUM_BASE))
BRCMF_ERROR(("%s: FAILED to return to SI_ENUM_BASE\n",
__func__));
#ifdef BCMDBG
printk(KERN_DEBUG "F1 signature read @0x18000000=0x%4x\n",
brcmf_sdcard_reg_read(bus->card, SI_ENUM_BASE, 4));
#endif
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
BRCMF_INIT_CLKCTL1, &err);
if (!err)
clkctl =
brcmf_sdcard_cfg_read(card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (err || ((clkctl & ~SBSDIO_AVBITS) != BRCMF_INIT_CLKCTL1)) {
BRCMF_ERROR(("brcmf_sdbrcm_probe: ChipClkCSR access: err %d"
" wrote 0x%02x read 0x%02x\n",
err, BRCMF_INIT_CLKCTL1, clkctl));
goto fail;
}
if (brcmf_sdbrcm_chip_attach(bus, regsva)) {
BRCMF_ERROR(("%s: brcmf_sdbrcm_chip_attach failed!\n",
__func__));
goto fail;
}
if (!brcmf_sdbrcm_chipmatch((u16) bus->ci->chip)) {
BRCMF_ERROR(("%s: unsupported chip: 0x%04x\n",
__func__, bus->ci->chip));
goto fail;
}
brcmf_sdbrcm_sdiod_drive_strength_init(bus, brcmf_sdiod_drive_strength);
if (!BRCMF_NOPMU(bus)) {
brcmf_sdcard_reg_read(bus->card,
CORE_SB(bus->ci->armcorebase, sbidhigh), 4);
bus->orig_ramsize = bus->ci->ramsize;
if (!(bus->orig_ramsize)) {
BRCMF_ERROR(("%s: failed to find SOCRAM memory!\n",
__func__));
goto fail;
}
bus->ramsize = bus->orig_ramsize;
if (brcmf_dongle_memsize)
brcmf_sdbrcm_setmemsize(bus, brcmf_dongle_memsize);
BRCMF_ERROR(("DHD: dongle ram size is set to %d(orig %d)\n",
bus->ramsize, bus->orig_ramsize));
}
OR_REG(bus->ci->buscorebase + offsetof(struct sdpcmd_regs,
corecontrol),
CC_BPRESEN, u32);
brcmu_pktq_init(&bus->txq, (PRIOMASK + 1), TXQLEN);
bus->rxhdr = (u8 *) roundup((unsigned long)&bus->hdrbuf[0],
BRCMF_SDALIGN);
bus->intr = (bool) brcmf_intr;
bus->poll = (bool) brcmf_poll;
if (bus->poll)
bus->pollrate = 1;
return true;
fail:
return false;
}
static bool brcmf_sdbrcm_probe_malloc(struct brcmf_bus *bus, void *card)
{
BRCMF_TRACE(("%s: Enter\n", __func__));
if (bus->drvr->maxctl) {
bus->rxblen =
roundup((bus->drvr->maxctl + SDPCM_HDRLEN),
ALIGNMENT) + BRCMF_SDALIGN;
bus->rxbuf = kmalloc(bus->rxblen, GFP_ATOMIC);
if (!(bus->rxbuf)) {
BRCMF_ERROR(("%s: kmalloc of %d-byte rxbuf failed\n",
__func__, bus->rxblen));
goto fail;
}
}
bus->databuf = kmalloc(MAX_DATA_BUF, GFP_ATOMIC);
if (!(bus->databuf)) {
BRCMF_ERROR(("%s: kmalloc of %d-byte databuf failed\n",
__func__, MAX_DATA_BUF));
if (!bus->rxblen)
kfree(bus->rxbuf);
goto fail;
}
if ((unsigned long)bus->databuf % BRCMF_SDALIGN)
bus->dataptr = bus->databuf + (BRCMF_SDALIGN -
((unsigned long)bus->databuf % BRCMF_SDALIGN));
else
bus->dataptr = bus->databuf;
return true;
fail:
return false;
}
static bool brcmf_sdbrcm_probe_init(struct brcmf_bus *bus, void *card)
{
s32 fnum;
BRCMF_TRACE(("%s: Enter\n", __func__));
#ifdef SDTEST
brcmf_sdbrcm_pktgen_init(bus);
#endif
brcmf_sdcard_cfg_write(card, SDIO_FUNC_0, SDIO_CCCR_IOEx,
SDIO_FUNC_ENABLE_1, NULL);
bus->drvr->busstate = BRCMF_BUS_DOWN;
bus->sleeping = false;
bus->rxflow = false;
brcmf_sdcard_cfg_write(card, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR, 0,
NULL);
bus->clkstate = CLK_SDONLY;
bus->idletime = (s32) brcmf_idletime;
bus->idleclock = BRCMF_IDLE_ACTIVE;
fnum = 2;
if (brcmf_sdcard_iovar_op(card, "sd_blocksize", &fnum, sizeof(s32),
&bus->blocksize, sizeof(s32), false) != 0) {
bus->blocksize = 0;
BRCMF_ERROR(("%s: fail on %s get\n", __func__, "sd_blocksize"));
} else {
BRCMF_INFO(("%s: Initial value for %s is %d\n",
__func__, "sd_blocksize", bus->blocksize));
}
bus->roundup = min(max_roundup, bus->blocksize);
if (brcmf_sdcard_iovar_op(card, "sd_rxchain", NULL, 0,
&bus->sd_rxchain, sizeof(s32),
false) != 0) {
bus->sd_rxchain = false;
} else {
BRCMF_INFO(("%s: bus module (through sdiocard API) %s"
" chaining\n", __func__, bus->sd_rxchain
? "supports" : "does not support"));
}
bus->use_rxchain = (bool) bus->sd_rxchain;
return true;
}
static bool
brcmf_sdbrcm_download_firmware(struct brcmf_bus *bus, void *card)
{
bool ret;
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
ret = _brcmf_sdbrcm_download_firmware(bus) == 0;
brcmf_sdbrcm_clkctl(bus, CLK_SDONLY, false);
return ret;
}
static void brcmf_sdbrcm_release(struct brcmf_bus *bus)
{
BRCMF_TRACE(("%s: Enter\n", __func__));
if (bus) {
brcmf_sdcard_intr_disable(bus->card);
brcmf_sdcard_intr_dereg(bus->card);
if (bus->drvr) {
brcmf_detach(bus->drvr);
brcmf_sdbrcm_release_dongle(bus);
bus->drvr = NULL;
}
brcmf_sdbrcm_release_malloc(bus);
kfree(bus);
}
BRCMF_TRACE(("%s: Disconnected\n", __func__));
}
static void brcmf_sdbrcm_release_malloc(struct brcmf_bus *bus)
{
BRCMF_TRACE(("%s: Enter\n", __func__));
if (bus->drvr && bus->drvr->dongle_reset)
return;
kfree(bus->rxbuf);
bus->rxctl = bus->rxbuf = NULL;
bus->rxlen = 0;
kfree(bus->databuf);
bus->databuf = NULL;
}
static void brcmf_sdbrcm_release_dongle(struct brcmf_bus *bus)
{
BRCMF_TRACE(("%s: Enter\n", __func__));
if (bus->drvr && bus->drvr->dongle_reset)
return;
if (bus->ci) {
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
brcmf_sdbrcm_clkctl(bus, CLK_NONE, false);
brcmf_sdbrcm_chip_detach(bus);
if (bus->vars && bus->varsz)
kfree(bus->vars);
bus->vars = NULL;
}
BRCMF_TRACE(("%s: Disconnected\n", __func__));
}
static void brcmf_sdbrcm_disconnect(void *ptr)
{
struct brcmf_bus *bus = (struct brcmf_bus *)ptr;
BRCMF_TRACE(("%s: Enter\n", __func__));
if (bus) {
brcmf_sdbrcm_release(bus);
}
BRCMF_TRACE(("%s: Disconnected\n", __func__));
}
int brcmf_bus_register(void)
{
BRCMF_TRACE(("%s: Enter\n", __func__));
do {
if ((brcmf_watchdog_prio < 0) && (brcmf_dpc_prio < 0))
break;
if ((brcmf_watchdog_prio >= 0) && (brcmf_dpc_prio >= 0)
&& brcmf_deferred_tx)
break;
BRCMF_ERROR(("Invalid module parameters.\n"));
return -EINVAL;
} while (0);
return brcmf_sdio_register(&brcmf_sdio);
}
void brcmf_bus_unregister(void)
{
BRCMF_TRACE(("%s: Enter\n", __func__));
brcmf_sdio_unregister();
}
static int brcmf_sdbrcm_download_code_file(struct brcmf_bus *bus)
{
int offset = 0;
uint len;
u8 *memblock = NULL, *memptr;
int ret;
BRCMF_INFO(("%s: Enter\n", __func__));
bus->fw_name = BCM4329_FW_NAME;
ret = request_firmware(&bus->firmware, bus->fw_name,
&gInstance->func[2]->dev);
if (ret) {
BRCMF_ERROR(("%s: Fail to request firmware %d\n",
__func__, ret));
return ret;
}
bus->fw_ptr = 0;
memptr = memblock = kmalloc(MEMBLOCK + BRCMF_SDALIGN, GFP_ATOMIC);
if (memblock == NULL) {
BRCMF_ERROR(("%s: Failed to allocate memory %d bytes\n",
__func__, MEMBLOCK));
ret = -ENOMEM;
goto err;
}
if ((u32)(unsigned long)memblock % BRCMF_SDALIGN)
memptr += (BRCMF_SDALIGN -
((u32)(unsigned long)memblock % BRCMF_SDALIGN));
while ((len =
brcmf_sdbrcm_get_image((char *)memptr, MEMBLOCK, bus))) {
ret = brcmf_sdbrcm_membytes(bus, true, offset, memptr, len);
if (ret) {
BRCMF_ERROR(("%s: error %d on writing %d membytes at "
"0x%08x\n", __func__, ret, MEMBLOCK,
offset));
goto err;
}
offset += MEMBLOCK;
}
err:
kfree(memblock);
release_firmware(bus->firmware);
bus->fw_ptr = 0;
return ret;
}
static uint brcmf_process_nvram_vars(char *varbuf, uint len)
{
char *dp;
bool findNewline;
int column;
uint buf_len, n;
dp = varbuf;
findNewline = false;
column = 0;
for (n = 0; n < len; n++) {
if (varbuf[n] == 0)
break;
if (varbuf[n] == '\r')
continue;
if (findNewline && varbuf[n] != '\n')
continue;
findNewline = false;
if (varbuf[n] == '#') {
findNewline = true;
continue;
}
if (varbuf[n] == '\n') {
if (column == 0)
continue;
*dp++ = 0;
column = 0;
continue;
}
*dp++ = varbuf[n];
column++;
}
buf_len = dp - varbuf;
while (dp < varbuf + n)
*dp++ = 0;
return buf_len;
}
static int brcmf_sdbrcm_download_nvram(struct brcmf_bus *bus)
{
uint len;
char *memblock = NULL;
char *bufp;
int ret;
bus->nv_name = BCM4329_NV_NAME;
ret = request_firmware(&bus->firmware, bus->nv_name,
&gInstance->func[2]->dev);
if (ret) {
BRCMF_ERROR(("%s: Fail to request nvram %d\n", __func__, ret));
return ret;
}
bus->fw_ptr = 0;
memblock = kmalloc(MEMBLOCK, GFP_ATOMIC);
if (memblock == NULL) {
BRCMF_ERROR(("%s: Failed to allocate memory %d bytes\n",
__func__, MEMBLOCK));
ret = -ENOMEM;
goto err;
}
len = brcmf_sdbrcm_get_image(memblock, MEMBLOCK, bus);
if (len > 0 && len < MEMBLOCK) {
bufp = (char *)memblock;
bufp[len] = 0;
len = brcmf_process_nvram_vars(bufp, len);
bufp += len;
*bufp++ = 0;
if (len)
ret = brcmf_sdbrcm_downloadvars(bus, memblock, len + 1);
if (ret)
BRCMF_ERROR(("%s: error downloading vars: %d\n",
__func__, ret));
} else {
BRCMF_ERROR(("%s: error reading nvram file: %d\n",
__func__, len));
ret = -EIO;
}
err:
kfree(memblock);
release_firmware(bus->firmware);
bus->fw_ptr = 0;
return ret;
}
static int _brcmf_sdbrcm_download_firmware(struct brcmf_bus *bus)
{
int bcmerror = -1;
if (brcmf_sdbrcm_download_state(bus, true)) {
BRCMF_ERROR(("%s: error placing ARM core in reset\n",
__func__));
goto err;
}
if (brcmf_sdbrcm_download_code_file(bus)) {
BRCMF_ERROR(("%s: dongle image file download failed\n",
__func__));
goto err;
}
if (brcmf_sdbrcm_download_nvram(bus)) {
BRCMF_ERROR(("%s: dongle nvram file download failed\n",
__func__));
}
if (brcmf_sdbrcm_download_state(bus, false)) {
BRCMF_ERROR(("%s: error getting out of ARM core reset\n",
__func__));
goto err;
}
bcmerror = 0;
err:
return bcmerror;
}
static int
brcmf_sdbrcm_send_buf(struct brcmf_bus *bus, u32 addr, uint fn, uint flags,
u8 *buf, uint nbytes, struct sk_buff *pkt,
void (*complete)(void *handle, int status,
bool sync_waiting),
void *handle)
{
return brcmf_sdcard_send_buf
(bus->card, addr, fn, flags, buf, nbytes, pkt, complete,
handle);
}
int brcmf_bus_devreset(struct brcmf_pub *drvr, u8 flag)
{
int bcmerror = 0;
struct brcmf_bus *bus;
bus = drvr->bus;
if (flag == true) {
brcmf_sdbrcm_wd_timer(bus, 0);
if (!bus->drvr->dongle_reset) {
brcmf_sdbrcm_bus_stop(bus, false);
brcmf_sdbrcm_release_dongle(bus);
bus->drvr->dongle_reset = true;
bus->drvr->up = false;
BRCMF_TRACE(("%s: WLAN OFF DONE\n", __func__));
} else
bcmerror = -EIO;
} else {
BRCMF_TRACE(("\n\n%s: == WLAN ON ==\n", __func__));
if (bus->drvr->dongle_reset) {
if (brcmf_sdbrcm_probe_attach(bus, bus->card,
SI_ENUM_BASE,
bus->cl_devid)) {
if (brcmf_sdbrcm_probe_init(bus, bus->card)) {
brcmf_sdbrcm_bus_init(bus->drvr, false);
bus->drvr->dongle_reset = false;
bus->drvr->up = true;
BRCMF_TRACE(("%s: WLAN ON DONE\n",
__func__));
} else
bcmerror = -EIO;
} else
bcmerror = -EIO;
} else {
bcmerror = -EISCONN;
BRCMF_ERROR(("%s: Set DEVRESET=false invoked when"
" device is on\n", __func__));
bcmerror = -EIO;
}
brcmf_sdbrcm_wd_timer(bus, brcmf_watchdog_ms);
}
return bcmerror;
}
static int
brcmf_sdbrcm_chip_recognition(struct brcmf_sdio_card *card,
struct chip_info *ci, u32 regs)
{
u32 regdata;
ci->cccorebase = regs;
regdata = brcmf_sdcard_reg_read(card,
CORE_CC_REG(ci->cccorebase, chipid), 4);
ci->chip = regdata & CID_ID_MASK;
ci->chiprev = (regdata & CID_REV_MASK) >> CID_REV_SHIFT;
BRCMF_INFO(("%s: chipid=0x%x chiprev=%d\n",
__func__, ci->chip, ci->chiprev));
switch (ci->chip) {
case BCM4329_CHIP_ID:
ci->buscorebase = BCM4329_CORE_BUS_BASE;
ci->ramcorebase = BCM4329_CORE_SOCRAM_BASE;
ci->armcorebase = BCM4329_CORE_ARM_BASE;
ci->ramsize = BCM4329_RAMSIZE;
break;
default:
BRCMF_ERROR(("%s: chipid 0x%x is not supported\n",
__func__, ci->chip));
return -ENODEV;
}
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(ci->cccorebase, sbidhigh), 4);
ci->ccrev = SBCOREREV(regdata);
regdata = brcmf_sdcard_reg_read(card,
CORE_CC_REG(ci->cccorebase, pmucapabilities), 4);
ci->pmurev = regdata & PCAP_REV_MASK;
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(ci->buscorebase, sbidhigh), 4);
ci->buscorerev = SBCOREREV(regdata);
ci->buscoretype = (regdata & SBIDH_CC_MASK) >> SBIDH_CC_SHIFT;
BRCMF_INFO(("%s: ccrev=%d, pmurev=%d, buscore rev/type=%d/0x%x\n",
__func__, ci->ccrev, ci->pmurev,
ci->buscorerev, ci->buscoretype));
ci->cccaps = brcmf_sdcard_reg_read(card,
CORE_CC_REG(ci->cccorebase, capabilities), 4);
return 0;
}
static void
brcmf_sdbrcm_chip_disablecore(struct brcmf_sdio_card *card, u32 corebase)
{
u32 regdata;
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbtmstatelow), 4);
if (regdata & SBTML_RESET)
return;
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbtmstatelow), 4);
if ((regdata & (SICF_CLOCK_EN << SBTML_SICF_SHIFT)) != 0) {
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbtmstatelow), 4);
brcmf_sdcard_reg_write(card, CORE_SB(corebase, sbtmstatelow), 4,
regdata | SBTML_REJ);
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbtmstatelow), 4);
udelay(1);
SPINWAIT((brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbtmstatehigh), 4) &
SBTMH_BUSY), 100000);
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbtmstatehigh), 4);
if (regdata & SBTMH_BUSY)
BRCMF_ERROR(("%s: ARM core still busy\n", __func__));
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbidlow), 4);
if (regdata & SBIDL_INIT) {
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbimstate), 4) |
SBIM_RJ;
brcmf_sdcard_reg_write(card,
CORE_SB(corebase, sbimstate), 4,
regdata);
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbimstate), 4);
udelay(1);
SPINWAIT((brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbimstate), 4) &
SBIM_BY), 100000);
}
brcmf_sdcard_reg_write(card,
CORE_SB(corebase, sbtmstatelow), 4,
(((SICF_FGC | SICF_CLOCK_EN) << SBTML_SICF_SHIFT) |
SBTML_REJ | SBTML_RESET));
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbtmstatelow), 4);
udelay(10);
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbidlow), 4);
if (regdata & SBIDL_INIT) {
regdata = brcmf_sdcard_reg_read(card,
CORE_SB(corebase, sbimstate), 4) &
~SBIM_RJ;
brcmf_sdcard_reg_write(card,
CORE_SB(corebase, sbimstate), 4,
regdata);
}
}
brcmf_sdcard_reg_write(card, CORE_SB(corebase, sbtmstatelow), 4,
(SBTML_REJ | SBTML_RESET));
udelay(1);
}
static int
brcmf_sdbrcm_chip_attach(struct brcmf_bus *bus, u32 regs)
{
struct chip_info *ci;
int err;
u8 clkval, clkset;
BRCMF_TRACE(("%s: Enter\n", __func__));
ci = kmalloc(sizeof(struct chip_info), GFP_ATOMIC);
if (NULL == ci) {
BRCMF_ERROR(("%s: malloc failed!\n", __func__));
return -ENOMEM;
}
memset((unsigned char *)ci, 0, sizeof(struct chip_info));
clkset = SBSDIO_FORCE_HW_CLKREQ_OFF | SBSDIO_ALP_AVAIL_REQ;
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
clkset, &err);
if (err) {
BRCMF_ERROR(("%s: error writing for HT off\n", __func__));
goto fail;
}
clkval = brcmf_sdcard_cfg_read(bus->card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, NULL);
if ((clkval & ~SBSDIO_AVBITS) == clkset) {
SPINWAIT(((clkval =
brcmf_sdcard_cfg_read(bus->card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
NULL)),
!SBSDIO_ALPAV(clkval)),
PMU_MAX_TRANSITION_DLY);
if (!SBSDIO_ALPAV(clkval)) {
BRCMF_ERROR(("%s: timeout on ALPAV wait,"
" clkval 0x%02x\n", __func__, clkval));
err = -EBUSY;
goto fail;
}
clkset = SBSDIO_FORCE_HW_CLKREQ_OFF |
SBSDIO_FORCE_ALP;
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
clkset, &err);
udelay(65);
} else {
BRCMF_ERROR(("%s: ChipClkCSR access: wrote 0x%02x"
" read 0x%02x\n", __func__, clkset, clkval));
err = -EACCES;
goto fail;
}
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1, SBSDIO_FUNC1_SDIOPULLUP,
0, NULL);
err = brcmf_sdbrcm_chip_recognition(bus->card, ci, regs);
if (err)
goto fail;
brcmf_sdbrcm_chip_disablecore(bus->card, ci->armcorebase);
brcmf_sdcard_reg_write(bus->card,
CORE_CC_REG(ci->cccorebase, gpiopullup), 4, 0);
brcmf_sdcard_reg_write(bus->card,
CORE_CC_REG(ci->cccorebase, gpiopulldown), 4, 0);
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_0, SDIO_CCCR_IOEx,
SDIO_FUNC_ENABLE_1, NULL);
clkval = brcmf_sdcard_cfg_read(bus->card, SDIO_FUNC_1,
0, NULL);
brcmf_sdcard_cfg_write(bus->card, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
0, NULL);
bus->ci = ci;
return 0;
fail:
bus->ci = NULL;
kfree(ci);
return err;
}
static void
brcmf_sdbrcm_chip_resetcore(struct brcmf_sdio_card *card, u32 corebase)
{
u32 regdata;
brcmf_sdbrcm_chip_disablecore(card, corebase);
brcmf_sdcard_reg_write(card, CORE_SB(corebase, sbtmstatelow), 4,
((SICF_FGC | SICF_CLOCK_EN) << SBTML_SICF_SHIFT) |
SBTML_RESET);
udelay(1);
regdata = brcmf_sdcard_reg_read(card, CORE_SB(corebase, sbtmstatehigh),
4);
if (regdata & SBTMH_SERR)
brcmf_sdcard_reg_write(card, CORE_SB(corebase, sbtmstatehigh),
4, 0);
regdata = brcmf_sdcard_reg_read(card, CORE_SB(corebase, sbimstate), 4);
if (regdata & (SBIM_IBE | SBIM_TO))
brcmf_sdcard_reg_write(card, CORE_SB(corebase, sbimstate), 4,
regdata & ~(SBIM_IBE | SBIM_TO));
brcmf_sdcard_reg_write(card, CORE_SB(corebase, sbtmstatelow), 4,
(SICF_FGC << SBTML_SICF_SHIFT) |
(SICF_CLOCK_EN << SBTML_SICF_SHIFT));
udelay(1);
brcmf_sdcard_reg_write(card, CORE_SB(corebase, sbtmstatelow), 4,
(SICF_CLOCK_EN << SBTML_SICF_SHIFT));
udelay(1);
}
static void
brcmf_sdbrcm_sdiod_drive_strength_init(struct brcmf_bus *bus, u32 drivestrength) {
struct sdiod_drive_str *str_tab = NULL;
u32 str_mask = 0;
u32 str_shift = 0;
char chn[8];
if (!(bus->ci->cccaps & CC_CAP_PMU))
return;
switch (SDIOD_DRVSTR_KEY(bus->ci->chip, bus->ci->pmurev)) {
case SDIOD_DRVSTR_KEY(BCM4325_CHIP_ID, 1):
str_tab = (struct sdiod_drive_str *)&sdiod_drive_strength_tab1;
str_mask = 0x30000000;
str_shift = 28;
break;
case SDIOD_DRVSTR_KEY(BCM4325_CHIP_ID, 2):
case SDIOD_DRVSTR_KEY(BCM4325_CHIP_ID, 3):
str_tab = (struct sdiod_drive_str *)&sdiod_drive_strength_tab2;
str_mask = 0x00003800;
str_shift = 11;
break;
case SDIOD_DRVSTR_KEY(BCM4336_CHIP_ID, 8):
str_tab = (struct sdiod_drive_str *)&sdiod_drive_strength_tab3;
str_mask = 0x00003800;
str_shift = 11;
break;
default:
BRCMF_ERROR(("No SDIO Drive strength init"
"done for chip %s rev %d pmurev %d\n",
brcmu_chipname(bus->ci->chip, chn, 8),
bus->ci->chiprev, bus->ci->pmurev));
break;
}
if (str_tab != NULL) {
u32 drivestrength_sel = 0;
u32 cc_data_temp;
int i;
for (i = 0; str_tab[i].strength != 0; i++) {
if (drivestrength >= str_tab[i].strength) {
drivestrength_sel = str_tab[i].sel;
break;
}
}
brcmf_sdcard_reg_write(bus->card,
CORE_CC_REG(bus->ci->cccorebase, chipcontrol_addr),
4, 1);
cc_data_temp = brcmf_sdcard_reg_read(bus->card,
CORE_CC_REG(bus->ci->cccorebase, chipcontrol_addr), 4);
cc_data_temp &= ~str_mask;
drivestrength_sel <<= str_shift;
cc_data_temp |= drivestrength_sel;
brcmf_sdcard_reg_write(bus->card,
CORE_CC_REG(bus->ci->cccorebase, chipcontrol_addr),
4, cc_data_temp);
BRCMF_INFO(("SDIO: %dmA drive strength selected, "
"set to 0x%08x\n", drivestrength, cc_data_temp));
}
}
static void
brcmf_sdbrcm_chip_detach(struct brcmf_bus *bus)
{
BRCMF_TRACE(("%s: Enter\n", __func__));
kfree(bus->ci);
bus->ci = NULL;
}
static void
brcmf_sdbrcm_wait_for_event(struct brcmf_bus *bus, bool *lockvar)
{
brcmf_sdbrcm_sdunlock(bus);
wait_event_interruptible_timeout(bus->ctrl_wait,
(*lockvar == false), HZ * 2);
brcmf_sdbrcm_sdlock(bus);
return;
}
static void
brcmf_sdbrcm_wait_event_wakeup(struct brcmf_bus *bus)
{
if (waitqueue_active(&bus->ctrl_wait))
wake_up_interruptible(&bus->ctrl_wait);
return;
}
static int
brcmf_sdbrcm_watchdog_thread(void *data)
{
struct brcmf_bus *bus = (struct brcmf_bus *)data;
if (brcmf_watchdog_prio > 0) {
struct sched_param param;
param.sched_priority = (brcmf_watchdog_prio < MAX_RT_PRIO) ?
brcmf_watchdog_prio : (MAX_RT_PRIO - 1);
sched_setscheduler(current, SCHED_FIFO, &param);
}
allow_signal(SIGTERM);
while (1) {
if (kthread_should_stop())
break;
if (!wait_for_completion_interruptible(&bus->watchdog_wait)) {
if (bus->drvr->dongle_reset == false)
brcmf_sdbrcm_bus_watchdog(bus->drvr);
bus->drvr->tickcnt++;
} else
break;
}
return 0;
}
static void
brcmf_sdbrcm_watchdog(unsigned long data)
{
struct brcmf_bus *bus = (struct brcmf_bus *)data;
if (brcmf_watchdog_prio >= 0) {
if (bus->watchdog_tsk)
complete(&bus->watchdog_wait);
else
return;
} else {
brcmf_sdbrcm_bus_watchdog(bus->drvr);
bus->drvr->tickcnt++;
}
if (bus->wd_timer_valid)
mod_timer(&bus->timer, jiffies + brcmf_watchdog_ms * HZ / 1000);
}
void
brcmf_sdbrcm_wd_timer(struct brcmf_bus *bus, uint wdtick)
{
static uint save_ms;
if (bus->drvr->busstate == BRCMF_BUS_DOWN)
return;
if (!wdtick && bus->wd_timer_valid == true) {
del_timer_sync(&bus->timer);
bus->wd_timer_valid = false;
save_ms = wdtick;
return;
}
if (wdtick) {
brcmf_watchdog_ms = (uint) wdtick;
if (save_ms != brcmf_watchdog_ms) {
if (bus->wd_timer_valid == true)
del_timer_sync(&bus->timer);
bus->timer.expires =
jiffies + brcmf_watchdog_ms * HZ / 1000;
add_timer(&bus->timer);
} else {
mod_timer(&bus->timer,
jiffies + brcmf_watchdog_ms * HZ / 1000);
}
bus->wd_timer_valid = true;
save_ms = wdtick;
}
}
static int brcmf_sdbrcm_dpc_thread(void *data)
{
struct brcmf_bus *bus = (struct brcmf_bus *) data;
if (brcmf_dpc_prio > 0) {
struct sched_param param;
param.sched_priority = (brcmf_dpc_prio < MAX_RT_PRIO) ?
brcmf_dpc_prio : (MAX_RT_PRIO - 1);
sched_setscheduler(current, SCHED_FIFO, &param);
}
allow_signal(SIGTERM);
while (1) {
if (kthread_should_stop())
break;
if (!wait_for_completion_interruptible(&bus->dpc_wait)) {
if (bus->drvr->busstate != BRCMF_BUS_DOWN) {
if (brcmf_sdbrcm_dpc(bus))
complete(&bus->dpc_wait);
} else {
brcmf_sdbrcm_bus_stop(bus, true);
}
} else
break;
}
return 0;
}
static void brcmf_sdbrcm_dpc_tasklet(unsigned long data)
{
struct brcmf_bus *bus = (struct brcmf_bus *) data;
if (bus->drvr->busstate != BRCMF_BUS_DOWN) {
if (brcmf_sdbrcm_dpc(bus))
tasklet_schedule(&bus->tasklet);
} else
brcmf_sdbrcm_bus_stop(bus, true);
}
static void brcmf_sdbrcm_sched_dpc(struct brcmf_bus *bus)
{
if (bus->dpc_tsk) {
complete(&bus->dpc_wait);
return;
}
tasklet_schedule(&bus->tasklet);
}
static void brcmf_sdbrcm_sdlock(struct brcmf_bus *bus)
{
if (bus->threads_only)
down(&bus->sdsem);
else
spin_lock_bh(&bus->sdlock);
}
static void brcmf_sdbrcm_sdunlock(struct brcmf_bus *bus)
{
if (bus->threads_only)
up(&bus->sdsem);
else
spin_unlock_bh(&bus->sdlock);
}
static int brcmf_sdbrcm_get_image(char *buf, int len, struct brcmf_bus *bus)
{
if (bus->firmware->size < bus->fw_ptr + len)
len = bus->firmware->size - bus->fw_ptr;
memcpy(buf, &bus->firmware->data[bus->fw_ptr], len);
bus->fw_ptr += len;
return len;
}
