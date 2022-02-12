static void dhdsdio_pktfree2(dhd_bus_t *bus, struct sk_buff *pkt)
{
dhd_os_sdlock_rxq(bus->dhd);
if ((bus->bus != SPI_BUS) || bus->usebufpool)
bcm_pkt_buf_free_skb(pkt);
dhd_os_sdunlock_rxq(bus->dhd);
}
static void dhd_dongle_setmemsize(struct dhd_bus *bus, int mem_size)
{
s32 min_size = DONGLE_MIN_MEMSIZE;
DHD_ERROR(("user: Restrict the dongle ram size to %d, min %d\n",
dhd_dongle_memsize, min_size));
if ((dhd_dongle_memsize > min_size) &&
(dhd_dongle_memsize < (s32) bus->orig_ramsize))
bus->ramsize = dhd_dongle_memsize;
}
static int dhdsdio_set_siaddr_window(dhd_bus_t *bus, u32 address)
{
int err = 0;
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_SBADDRLOW,
(address >> 8) & SBSDIO_SBADDRLOW_MASK, &err);
if (!err)
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_SBADDRMID,
(address >> 16) & SBSDIO_SBADDRMID_MASK, &err);
if (!err)
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_SBADDRHIGH,
(address >> 24) & SBSDIO_SBADDRHIGH_MASK,
&err);
return err;
}
static int dhdsdio_htclk(dhd_bus_t *bus, bool on, bool pendok)
{
int err;
u8 clkctl, clkreq, devctl;
bcmsdh_info_t *sdh;
DHD_TRACE(("%s: Enter\n", __func__));
#if defined(OOB_INTR_ONLY)
pendok = false;
#endif
clkctl = 0;
sdh = bus->sdh;
if (on) {
clkreq =
bus->alp_only ? SBSDIO_ALP_AVAIL_REQ : SBSDIO_HT_AVAIL_REQ;
if ((bus->ci->chip == BCM4329_CHIP_ID)
&& (bus->ci->chiprev == 0))
clkreq |= SBSDIO_FORCE_ALP;
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
clkreq, &err);
if (err) {
DHD_ERROR(("%s: HT Avail request error: %d\n",
__func__, err));
return -EBADE;
}
if (pendok && ((bus->ci->buscoretype == PCMCIA_CORE_ID)
&& (bus->ci->buscorerev == 9))) {
u32 dummy, retries;
R_SDREG(dummy, &bus->regs->clockctlstatus, retries);
}
clkctl =
bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
&err);
if (err) {
DHD_ERROR(("%s: HT Avail read error: %d\n",
__func__, err));
return -EBADE;
}
if (!SBSDIO_CLKAV(clkctl, bus->alp_only) && pendok) {
devctl =
bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL,
&err);
if (err) {
DHD_ERROR(("%s: Devctl error setting CA: %d\n",
__func__, err));
return -EBADE;
}
devctl |= SBSDIO_DEVCTL_CA_INT_ONLY;
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL,
devctl, &err);
DHD_INFO(("CLKCTL: set PENDING\n"));
bus->clkstate = CLK_PENDING;
return 0;
} else if (bus->clkstate == CLK_PENDING) {
devctl =
bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL,
&err);
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL,
devctl, &err);
}
if (!SBSDIO_CLKAV(clkctl, bus->alp_only)) {
SPINWAIT_SLEEP(sdioh_spinwait_sleep,
((clkctl =
bcmsdh_cfg_read(sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
&err)),
!SBSDIO_CLKAV(clkctl, bus->alp_only)),
PMU_MAX_TRANSITION_DLY);
}
if (err) {
DHD_ERROR(("%s: HT Avail request error: %d\n",
__func__, err));
return -EBADE;
}
if (!SBSDIO_CLKAV(clkctl, bus->alp_only)) {
DHD_ERROR(("%s: HT Avail timeout (%d): clkctl 0x%02x\n",
__func__, PMU_MAX_TRANSITION_DLY, clkctl));
return -EBADE;
}
bus->clkstate = CLK_AVAIL;
DHD_INFO(("CLKCTL: turned ON\n"));
#if defined(DHD_DEBUG)
if (bus->alp_only == true) {
#if !defined(BCMLXSDMMC)
if (!SBSDIO_ALPONLY(clkctl)) {
DHD_ERROR(("%s: HT Clock, when ALP Only\n",
__func__));
}
#endif
} else {
if (SBSDIO_ALPONLY(clkctl)) {
DHD_ERROR(("%s: HT Clock should be on.\n",
__func__));
}
}
#endif
bus->activity = true;
} else {
clkreq = 0;
if (bus->clkstate == CLK_PENDING) {
devctl =
bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL,
&err);
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL,
devctl, &err);
}
bus->clkstate = CLK_SDONLY;
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
clkreq, &err);
DHD_INFO(("CLKCTL: turned OFF\n"));
if (err) {
DHD_ERROR(("%s: Failed access turning clock off: %d\n",
__func__, err));
return -EBADE;
}
}
return 0;
}
static int dhdsdio_sdclk(dhd_bus_t *bus, bool on)
{
int err;
s32 iovalue;
DHD_TRACE(("%s: Enter\n", __func__));
if (on) {
if (bus->idleclock == DHD_IDLE_STOP) {
iovalue = 1;
err = bcmsdh_iovar_op(bus->sdh, "sd_clock", NULL, 0,
&iovalue, sizeof(iovalue), true);
if (err) {
DHD_ERROR(("%s: error enabling sd_clock: %d\n",
__func__, err));
return -EBADE;
}
iovalue = bus->sd_mode;
err = bcmsdh_iovar_op(bus->sdh, "sd_mode", NULL, 0,
&iovalue, sizeof(iovalue), true);
if (err) {
DHD_ERROR(("%s: error changing sd_mode: %d\n",
__func__, err));
return -EBADE;
}
} else if (bus->idleclock != DHD_IDLE_ACTIVE) {
iovalue = bus->sd_divisor;
err = bcmsdh_iovar_op(bus->sdh, "sd_divisor", NULL, 0,
&iovalue, sizeof(iovalue), true);
if (err) {
DHD_ERROR(("%s: error restoring sd_divisor: %d\n",
__func__, err));
return -EBADE;
}
}
bus->clkstate = CLK_SDONLY;
} else {
if ((bus->sd_divisor == -1) || (bus->sd_mode == -1)) {
DHD_TRACE(("%s: can't idle clock, divisor %d mode %d\n",
__func__, bus->sd_divisor, bus->sd_mode));
return -EBADE;
}
if (bus->idleclock == DHD_IDLE_STOP) {
if (sd1idle) {
iovalue = 1;
err =
bcmsdh_iovar_op(bus->sdh, "sd_mode", NULL,
0, &iovalue,
sizeof(iovalue), true);
if (err) {
DHD_ERROR(("%s: error changing sd_clock: %d\n",
__func__, err));
return -EBADE;
}
}
iovalue = 0;
err = bcmsdh_iovar_op(bus->sdh, "sd_clock", NULL, 0,
&iovalue, sizeof(iovalue), true);
if (err) {
DHD_ERROR(("%s: error disabling sd_clock: %d\n",
__func__, err));
return -EBADE;
}
} else if (bus->idleclock != DHD_IDLE_ACTIVE) {
iovalue = bus->idleclock;
err = bcmsdh_iovar_op(bus->sdh, "sd_divisor", NULL, 0,
&iovalue, sizeof(iovalue), true);
if (err) {
DHD_ERROR(("%s: error changing sd_divisor: %d\n",
__func__, err));
return -EBADE;
}
}
bus->clkstate = CLK_NONE;
}
return 0;
}
static int dhdsdio_clkctl(dhd_bus_t *bus, uint target, bool pendok)
{
#ifdef DHD_DEBUG
uint oldstate = bus->clkstate;
#endif
DHD_TRACE(("%s: Enter\n", __func__));
if (bus->clkstate == target) {
if (target == CLK_AVAIL) {
dhd_os_wd_timer(bus->dhd, dhd_watchdog_ms);
bus->activity = true;
}
return 0;
}
switch (target) {
case CLK_AVAIL:
if (bus->clkstate == CLK_NONE)
dhdsdio_sdclk(bus, true);
dhdsdio_htclk(bus, true, pendok);
dhd_os_wd_timer(bus->dhd, dhd_watchdog_ms);
bus->activity = true;
break;
case CLK_SDONLY:
if (bus->clkstate == CLK_NONE)
dhdsdio_sdclk(bus, true);
else if (bus->clkstate == CLK_AVAIL)
dhdsdio_htclk(bus, false, false);
else
DHD_ERROR(("dhdsdio_clkctl: request for %d -> %d\n",
bus->clkstate, target));
dhd_os_wd_timer(bus->dhd, dhd_watchdog_ms);
break;
case CLK_NONE:
if (bus->clkstate == CLK_AVAIL)
dhdsdio_htclk(bus, false, false);
dhdsdio_sdclk(bus, false);
dhd_os_wd_timer(bus->dhd, 0);
break;
}
#ifdef DHD_DEBUG
DHD_INFO(("dhdsdio_clkctl: %d -> %d\n", oldstate, bus->clkstate));
#endif
return 0;
}
int dhdsdio_bussleep(dhd_bus_t *bus, bool sleep)
{
bcmsdh_info_t *sdh = bus->sdh;
sdpcmd_regs_t *regs = bus->regs;
uint retries = 0;
DHD_INFO(("dhdsdio_bussleep: request %s (currently %s)\n",
(sleep ? "SLEEP" : "WAKE"),
(bus->sleeping ? "SLEEP" : "WAKE")));
if (sleep == bus->sleeping)
return 0;
if (sleep) {
if (bus->dpc_sched || bus->rxskip || pktq_len(&bus->txq))
return -EBUSY;
bcmsdh_intr_disable(bus->sdh);
dhdsdio_clkctl(bus, CLK_AVAIL, false);
W_SDREG(SMB_USE_OOB, &regs->tosbmailbox, retries);
if (retries > retry_limit)
DHD_ERROR(("CANNOT SIGNAL CHIP, WILL NOT WAKE UP!!\n"));
dhdsdio_clkctl(bus, CLK_SDONLY, false);
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
SBSDIO_FORCE_HW_CLKREQ_OFF, NULL);
if (bus->ci->chip != BCM4329_CHIP_ID
&& bus->ci->chip != BCM4319_CHIP_ID) {
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL,
SBSDIO_DEVCTL_PADS_ISO, NULL);
}
bus->sleeping = true;
} else {
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
0, NULL);
if ((bus->ci->buscoretype == PCMCIA_CORE_ID)
&& (bus->ci->buscorerev >= 10))
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL, 0,
NULL);
dhdsdio_clkctl(bus, CLK_AVAIL, false);
W_SDREG(0, &regs->tosbmailboxdata, retries);
if (retries <= retry_limit)
W_SDREG(SMB_DEV_INT, &regs->tosbmailbox, retries);
if (retries > retry_limit)
DHD_ERROR(("CANNOT SIGNAL CHIP TO CLEAR OOB!!\n"));
dhdsdio_clkctl(bus, CLK_SDONLY, false);
bus->sleeping = false;
if (bus->intr && (bus->dhd->busstate == DHD_BUS_DATA)) {
bus->intdis = false;
bcmsdh_intr_enable(bus->sdh);
}
}
return 0;
}
void dhd_enable_oob_intr(struct dhd_bus *bus, bool enable)
{
#if defined(HW_OOB)
bcmsdh_enable_hw_oob_intr(bus->sdh, enable);
#else
sdpcmd_regs_t *regs = bus->regs;
uint retries = 0;
dhdsdio_clkctl(bus, CLK_AVAIL, false);
if (enable == true) {
W_SDREG(SMB_USE_OOB, &regs->tosbmailbox, retries);
if (retries > retry_limit)
DHD_ERROR(("CANNOT SIGNAL CHIP, WILL NOT WAKE UP!!\n"));
} else {
W_SDREG(0, &regs->tosbmailboxdata, retries);
if (retries <= retry_limit)
W_SDREG(SMB_DEV_INT, &regs->tosbmailbox, retries);
}
dhdsdio_clkctl(bus, CLK_SDONLY, false);
#endif
}
static int dhdsdio_txpkt(dhd_bus_t *bus, struct sk_buff *pkt, uint chan,
bool free_pkt)
{
int ret;
u8 *frame;
u16 len, pad = 0;
u32 swheader;
uint retries = 0;
bcmsdh_info_t *sdh;
struct sk_buff *new;
int i;
DHD_TRACE(("%s: Enter\n", __func__));
sdh = bus->sdh;
if (bus->dhd->dongle_reset) {
ret = -EPERM;
goto done;
}
frame = (u8 *) (pkt->data);
pad = ((unsigned long)frame % DHD_SDALIGN);
if (pad) {
if (skb_headroom(pkt) < pad) {
DHD_INFO(("%s: insufficient headroom %d for %d pad\n",
__func__, skb_headroom(pkt), pad));
bus->dhd->tx_realloc++;
new = bcm_pkt_buf_get_skb(pkt->len + DHD_SDALIGN);
if (!new) {
DHD_ERROR(("%s: couldn't allocate new %d-byte "
"packet\n",
__func__, pkt->len + DHD_SDALIGN));
ret = -ENOMEM;
goto done;
}
PKTALIGN(new, pkt->len, DHD_SDALIGN);
memcpy(new->data, pkt->data, pkt->len);
if (free_pkt)
bcm_pkt_buf_free_skb(pkt);
free_pkt = true;
pkt = new;
frame = (u8 *) (pkt->data);
ASSERT(((unsigned long)frame % DHD_SDALIGN) == 0);
pad = 0;
} else {
skb_push(pkt, pad);
frame = (u8 *) (pkt->data);
ASSERT((pad + SDPCM_HDRLEN) <= (int)(pkt->len));
memset(frame, 0, pad + SDPCM_HDRLEN);
}
}
ASSERT(pad < DHD_SDALIGN);
len = (u16) (pkt->len);
*(u16 *) frame = cpu_to_le16(len);
*(((u16 *) frame) + 1) = cpu_to_le16(~len);
swheader =
((chan << SDPCM_CHANNEL_SHIFT) & SDPCM_CHANNEL_MASK) | bus->tx_seq |
(((pad +
SDPCM_HDRLEN) << SDPCM_DOFFSET_SHIFT) & SDPCM_DOFFSET_MASK);
put_unaligned_le32(swheader, frame + SDPCM_FRAMETAG_LEN);
put_unaligned_le32(0, frame + SDPCM_FRAMETAG_LEN + sizeof(swheader));
#ifdef DHD_DEBUG
tx_packets[pkt->priority]++;
if (DHD_BYTES_ON() &&
(((DHD_CTL_ON() && (chan == SDPCM_CONTROL_CHANNEL)) ||
(DHD_DATA_ON() && (chan != SDPCM_CONTROL_CHANNEL))))) {
printk(KERN_DEBUG "Tx Frame:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, frame, len);
} else if (DHD_HDRS_ON()) {
printk(KERN_DEBUG "TxHdr:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
frame, min_t(u16, len, 16));
}
#endif
if (bus->roundup && bus->blocksize && (len > bus->blocksize)) {
u16 pad = bus->blocksize - (len % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize))
#ifdef NOTUSED
if (pad <= skb_tailroom(pkt))
#endif
len += pad;
} else if (len % DHD_SDALIGN) {
len += DHD_SDALIGN - (len % DHD_SDALIGN);
}
if (forcealign && (len & (ALIGNMENT - 1))) {
#ifdef NOTUSED
if (skb_tailroom(pkt))
#endif
len = roundup(len, ALIGNMENT);
#ifdef NOTUSED
else
DHD_ERROR(("%s: sending unrounded %d-byte packet\n",
__func__, len));
#endif
}
do {
ret =
dhd_bcmsdh_send_buf(bus, bcmsdh_cur_sbwad(sdh), SDIO_FUNC_2,
F2SYNC, frame, len, pkt, NULL, NULL);
bus->f2txdata++;
ASSERT(ret != -BCME_PENDING);
if (ret < 0) {
DHD_INFO(("%s: sdio error %d, abort command and "
"terminate frame.\n", __func__, ret));
bus->tx_sderrs++;
bcmsdh_abort(sdh, SDIO_FUNC_2);
bcmsdh_cfg_write(sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_FRAMECTRL, SFC_WF_TERM,
NULL);
bus->f1regdata++;
for (i = 0; i < 3; i++) {
u8 hi, lo;
hi = bcmsdh_cfg_read(sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCHI,
NULL);
lo = bcmsdh_cfg_read(sdh, SDIO_FUNC_1,
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
dhd_os_sdunlock(bus->dhd);
dhd_txcomplete(bus->dhd, pkt, ret != 0);
dhd_os_sdlock(bus->dhd);
if (free_pkt)
bcm_pkt_buf_free_skb(pkt);
return ret;
}
int dhd_bus_txdata(struct dhd_bus *bus, struct sk_buff *pkt)
{
int ret = -EBADE;
uint datalen, prec;
DHD_TRACE(("%s: Enter\n", __func__));
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
ASSERT(IS_ALIGNED((unsigned long)(pkt->data), 2));
prec = PRIO2PREC((pkt->priority & PRIOMASK));
if (dhd_deferred_tx || bus->fcstate || pktq_len(&bus->txq)
|| bus->dpc_sched || (!DATAOK(bus))
|| (bus->flowcontrol & NBITVAL(prec))
|| (bus->clkstate != CLK_AVAIL)) {
DHD_TRACE(("%s: deferring pktq len %d\n", __func__,
pktq_len(&bus->txq)));
bus->fcqueued++;
dhd_os_sdlock_txq(bus->dhd);
if (dhd_prec_enq(bus->dhd, &bus->txq, pkt, prec) == false) {
skb_pull(pkt, SDPCM_HDRLEN);
dhd_txcomplete(bus->dhd, pkt, false);
bcm_pkt_buf_free_skb(pkt);
DHD_ERROR(("%s: out of bus->txq !!!\n", __func__));
ret = -ENOSR;
} else {
ret = 0;
}
dhd_os_sdunlock_txq(bus->dhd);
if (pktq_len(&bus->txq) >= TXHI)
dhd_txflowcontrol(bus->dhd, 0, ON);
#ifdef DHD_DEBUG
if (pktq_plen(&bus->txq, prec) > qcount[prec])
qcount[prec] = pktq_plen(&bus->txq, prec);
#endif
if (dhd_deferred_tx && !bus->dpc_sched) {
bus->dpc_sched = true;
dhd_sched_dpc(bus->dhd);
}
} else {
dhd_os_sdlock(bus->dhd);
BUS_WAKE(bus);
dhdsdio_clkctl(bus, CLK_AVAIL, true);
#ifndef SDTEST
DHD_TRACE(("%s: calling txpkt\n", __func__));
ret = dhdsdio_txpkt(bus, pkt, SDPCM_DATA_CHANNEL, true);
#else
ret = dhdsdio_txpkt(bus, pkt,
(bus->ext_loop ? SDPCM_TEST_CHANNEL :
SDPCM_DATA_CHANNEL), true);
#endif
if (ret)
bus->dhd->tx_errors++;
else
bus->dhd->dstats.tx_bytes += datalen;
if ((bus->idletime == DHD_IDLE_IMMEDIATE) && !bus->dpc_sched) {
bus->activity = false;
dhdsdio_clkctl(bus, CLK_NONE, true);
}
dhd_os_sdunlock(bus->dhd);
}
return ret;
}
static uint dhdsdio_sendfromq(dhd_bus_t *bus, uint maxframes)
{
struct sk_buff *pkt;
u32 intstatus = 0;
uint retries = 0;
int ret = 0, prec_out;
uint cnt = 0;
uint datalen;
u8 tx_prec_map;
dhd_pub_t *dhd = bus->dhd;
sdpcmd_regs_t *regs = bus->regs;
DHD_TRACE(("%s: Enter\n", __func__));
tx_prec_map = ~bus->flowcontrol;
for (cnt = 0; (cnt < maxframes) && DATAOK(bus); cnt++) {
dhd_os_sdlock_txq(bus->dhd);
pkt = bcm_pktq_mdeq(&bus->txq, tx_prec_map, &prec_out);
if (pkt == NULL) {
dhd_os_sdunlock_txq(bus->dhd);
break;
}
dhd_os_sdunlock_txq(bus->dhd);
datalen = pkt->len - SDPCM_HDRLEN;
#ifndef SDTEST
ret = dhdsdio_txpkt(bus, pkt, SDPCM_DATA_CHANNEL, true);
#else
ret = dhdsdio_txpkt(bus, pkt,
(bus->ext_loop ? SDPCM_TEST_CHANNEL :
SDPCM_DATA_CHANNEL), true);
#endif
if (ret)
bus->dhd->tx_errors++;
else
bus->dhd->dstats.tx_bytes += datalen;
if (!bus->intr && cnt) {
R_SDREG(intstatus, &regs->intstatus, retries);
bus->f2txdata++;
if (bcmsdh_regfail(bus->sdh))
break;
if (intstatus & bus->hostintmask)
bus->ipend = true;
}
}
if (dhd->up && (dhd->busstate == DHD_BUS_DATA) &&
dhd->txoff && (pktq_len(&bus->txq) < TXLOW))
dhd_txflowcontrol(dhd, 0, OFF);
return cnt;
}
int dhd_bus_txctl(struct dhd_bus *bus, unsigned char *msg, uint msglen)
{
u8 *frame;
u16 len;
u32 swheader;
uint retries = 0;
bcmsdh_info_t *sdh = bus->sdh;
u8 doff = 0;
int ret = -1;
int i;
DHD_TRACE(("%s: Enter\n", __func__));
if (bus->dhd->dongle_reset)
return -EIO;
frame = msg - SDPCM_HDRLEN;
len = (msglen += SDPCM_HDRLEN);
if (dhd_alignctl) {
doff = ((unsigned long)frame % DHD_SDALIGN);
if (doff) {
frame -= doff;
len += doff;
msglen += doff;
memset(frame, 0, doff + SDPCM_HDRLEN);
}
ASSERT(doff < DHD_SDALIGN);
}
doff += SDPCM_HDRLEN;
if (bus->roundup && bus->blocksize && (len > bus->blocksize)) {
u16 pad = bus->blocksize - (len % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize))
len += pad;
} else if (len % DHD_SDALIGN) {
len += DHD_SDALIGN - (len % DHD_SDALIGN);
}
if (forcealign && (len & (ALIGNMENT - 1)))
len = roundup(len, ALIGNMENT);
ASSERT(IS_ALIGNED((unsigned long)frame, 2));
dhd_os_sdlock(bus->dhd);
BUS_WAKE(bus);
dhdsdio_clkctl(bus, CLK_AVAIL, false);
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
DHD_INFO(("%s: No bus credit bus->tx_max %d, bus->tx_seq %d\n",
__func__, bus->tx_max, bus->tx_seq));
bus->ctrl_frame_stat = true;
bus->ctrl_frame_buf = frame;
bus->ctrl_frame_len = len;
dhd_wait_for_event(bus->dhd, &bus->ctrl_frame_stat);
if (bus->ctrl_frame_stat == false) {
DHD_INFO(("%s: ctrl_frame_stat == false\n", __func__));
ret = 0;
} else {
DHD_INFO(("%s: ctrl_frame_stat == true\n", __func__));
ret = -1;
}
}
if (ret == -1) {
#ifdef DHD_DEBUG
if (DHD_BYTES_ON() && DHD_CTL_ON()) {
printk(KERN_DEBUG "Tx Frame:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
frame, len);
} else if (DHD_HDRS_ON()) {
printk(KERN_DEBUG "TxHdr:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
frame, min_t(u16, len, 16));
}
#endif
do {
bus->ctrl_frame_stat = false;
ret =
dhd_bcmsdh_send_buf(bus, bcmsdh_cur_sbwad(sdh),
SDIO_FUNC_2, F2SYNC, frame, len,
NULL, NULL, NULL);
ASSERT(ret != -BCME_PENDING);
if (ret < 0) {
DHD_INFO(("%s: sdio error %d, abort command and terminate frame.\n",
__func__, ret));
bus->tx_sderrs++;
bcmsdh_abort(sdh, SDIO_FUNC_2);
bcmsdh_cfg_write(sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_FRAMECTRL,
SFC_WF_TERM, NULL);
bus->f1regdata++;
for (i = 0; i < 3; i++) {
u8 hi, lo;
hi = bcmsdh_cfg_read(sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCHI,
NULL);
lo = bcmsdh_cfg_read(sdh, SDIO_FUNC_1,
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
if ((bus->idletime == DHD_IDLE_IMMEDIATE) && !bus->dpc_sched) {
bus->activity = false;
dhdsdio_clkctl(bus, CLK_NONE, true);
}
dhd_os_sdunlock(bus->dhd);
if (ret)
bus->dhd->tx_ctlerrs++;
else
bus->dhd->tx_ctlpkts++;
return ret ? -EIO : 0;
}
int dhd_bus_rxctl(struct dhd_bus *bus, unsigned char *msg, uint msglen)
{
int timeleft;
uint rxlen = 0;
bool pending;
DHD_TRACE(("%s: Enter\n", __func__));
if (bus->dhd->dongle_reset)
return -EIO;
timeleft = dhd_os_ioctl_resp_wait(bus->dhd, &bus->rxlen, &pending);
dhd_os_sdlock(bus->dhd);
rxlen = bus->rxlen;
memcpy(msg, bus->rxctl, min(msglen, rxlen));
bus->rxlen = 0;
dhd_os_sdunlock(bus->dhd);
if (rxlen) {
DHD_CTL(("%s: resumed on rxctl frame, got %d expected %d\n",
__func__, rxlen, msglen));
} else if (timeleft == 0) {
DHD_ERROR(("%s: resumed on timeout\n", __func__));
#ifdef DHD_DEBUG
dhd_os_sdlock(bus->dhd);
dhdsdio_checkdied(bus, NULL, 0);
dhd_os_sdunlock(bus->dhd);
#endif
} else if (pending == true) {
DHD_CTL(("%s: cancelled\n", __func__));
return -ERESTARTSYS;
} else {
DHD_CTL(("%s: resumed for unknown reason?\n", __func__));
#ifdef DHD_DEBUG
dhd_os_sdlock(bus->dhd);
dhdsdio_checkdied(bus, NULL, 0);
dhd_os_sdunlock(bus->dhd);
#endif
}
if (rxlen)
bus->dhd->rx_ctlpkts++;
else
bus->dhd->rx_ctlerrs++;
return rxlen ? (int)rxlen : -ETIMEDOUT;
}
static void
dhd_dump_pct(struct bcmstrbuf *strbuf, char *desc, uint num, uint div)
{
uint q1, q2;
if (!div) {
bcm_bprintf(strbuf, "%s N/A", desc);
} else {
q1 = num / div;
q2 = (100 * (num - (q1 * div))) / div;
bcm_bprintf(strbuf, "%s %d.%02d", desc, q1, q2);
}
}
void dhd_bus_dump(dhd_pub_t *dhdp, struct bcmstrbuf *strbuf)
{
dhd_bus_t *bus = dhdp->bus;
bcm_bprintf(strbuf, "Bus SDIO structure:\n");
bcm_bprintf(strbuf,
"hostintmask 0x%08x intstatus 0x%08x sdpcm_ver %d\n",
bus->hostintmask, bus->intstatus, bus->sdpcm_ver);
bcm_bprintf(strbuf,
"fcstate %d qlen %d tx_seq %d, max %d, rxskip %d rxlen %d rx_seq %d\n",
bus->fcstate, pktq_len(&bus->txq), bus->tx_seq, bus->tx_max,
bus->rxskip, bus->rxlen, bus->rx_seq);
bcm_bprintf(strbuf, "intr %d intrcount %d lastintrs %d spurious %d\n",
bus->intr, bus->intrcount, bus->lastintrs, bus->spurious);
bcm_bprintf(strbuf, "pollrate %d pollcnt %d regfails %d\n",
bus->pollrate, bus->pollcnt, bus->regfails);
bcm_bprintf(strbuf, "\nAdditional counters:\n");
bcm_bprintf(strbuf,
"tx_sderrs %d fcqueued %d rxrtx %d rx_toolong %d rxc_errors %d\n",
bus->tx_sderrs, bus->fcqueued, bus->rxrtx, bus->rx_toolong,
bus->rxc_errors);
bcm_bprintf(strbuf, "rx_hdrfail %d badhdr %d badseq %d\n",
bus->rx_hdrfail, bus->rx_badhdr, bus->rx_badseq);
bcm_bprintf(strbuf, "fc_rcvd %d, fc_xoff %d, fc_xon %d\n", bus->fc_rcvd,
bus->fc_xoff, bus->fc_xon);
bcm_bprintf(strbuf, "rxglomfail %d, rxglomframes %d, rxglompkts %d\n",
bus->rxglomfail, bus->rxglomframes, bus->rxglompkts);
bcm_bprintf(strbuf, "f2rx (hdrs/data) %d (%d/%d), f2tx %d f1regs %d\n",
(bus->f2rxhdrs + bus->f2rxdata), bus->f2rxhdrs,
bus->f2rxdata, bus->f2txdata, bus->f1regdata);
{
dhd_dump_pct(strbuf, "\nRx: pkts/f2rd", bus->dhd->rx_packets,
(bus->f2rxhdrs + bus->f2rxdata));
dhd_dump_pct(strbuf, ", pkts/f1sd", bus->dhd->rx_packets,
bus->f1regdata);
dhd_dump_pct(strbuf, ", pkts/sd", bus->dhd->rx_packets,
(bus->f2rxhdrs + bus->f2rxdata + bus->f1regdata));
dhd_dump_pct(strbuf, ", pkts/int", bus->dhd->rx_packets,
bus->intrcount);
bcm_bprintf(strbuf, "\n");
dhd_dump_pct(strbuf, "Rx: glom pct", (100 * bus->rxglompkts),
bus->dhd->rx_packets);
dhd_dump_pct(strbuf, ", pkts/glom", bus->rxglompkts,
bus->rxglomframes);
bcm_bprintf(strbuf, "\n");
dhd_dump_pct(strbuf, "Tx: pkts/f2wr", bus->dhd->tx_packets,
bus->f2txdata);
dhd_dump_pct(strbuf, ", pkts/f1sd", bus->dhd->tx_packets,
bus->f1regdata);
dhd_dump_pct(strbuf, ", pkts/sd", bus->dhd->tx_packets,
(bus->f2txdata + bus->f1regdata));
dhd_dump_pct(strbuf, ", pkts/int", bus->dhd->tx_packets,
bus->intrcount);
bcm_bprintf(strbuf, "\n");
dhd_dump_pct(strbuf, "Total: pkts/f2rw",
(bus->dhd->tx_packets + bus->dhd->rx_packets),
(bus->f2txdata + bus->f2rxhdrs + bus->f2rxdata));
dhd_dump_pct(strbuf, ", pkts/f1sd",
(bus->dhd->tx_packets + bus->dhd->rx_packets),
bus->f1regdata);
dhd_dump_pct(strbuf, ", pkts/sd",
(bus->dhd->tx_packets + bus->dhd->rx_packets),
(bus->f2txdata + bus->f2rxhdrs + bus->f2rxdata +
bus->f1regdata));
dhd_dump_pct(strbuf, ", pkts/int",
(bus->dhd->tx_packets + bus->dhd->rx_packets),
bus->intrcount);
bcm_bprintf(strbuf, "\n\n");
}
#ifdef SDTEST
if (bus->pktgen_count) {
bcm_bprintf(strbuf, "pktgen config and count:\n");
bcm_bprintf(strbuf,
"freq %d count %d print %d total %d min %d len %d\n",
bus->pktgen_freq, bus->pktgen_count,
bus->pktgen_print, bus->pktgen_total,
bus->pktgen_minlen, bus->pktgen_maxlen);
bcm_bprintf(strbuf, "send attempts %d rcvd %d fail %d\n",
bus->pktgen_sent, bus->pktgen_rcvd,
bus->pktgen_fail);
}
#endif
#ifdef DHD_DEBUG
bcm_bprintf(strbuf, "dpc_sched %d host interrupt%spending\n",
bus->dpc_sched,
(bcmsdh_intr_pending(bus->sdh) ? " " : " not "));
bcm_bprintf(strbuf, "blocksize %d roundup %d\n", bus->blocksize,
bus->roundup);
#endif
bcm_bprintf(strbuf,
"clkstate %d activity %d idletime %d idlecount %d sleeping %d\n",
bus->clkstate, bus->activity, bus->idletime, bus->idlecount,
bus->sleeping);
}
void dhd_bus_clearcounts(dhd_pub_t *dhdp)
{
dhd_bus_t *bus = (dhd_bus_t *) dhdp->bus;
bus->intrcount = bus->lastintrs = bus->spurious = bus->regfails = 0;
bus->rxrtx = bus->rx_toolong = bus->rxc_errors = 0;
bus->rx_hdrfail = bus->rx_badhdr = bus->rx_badseq = 0;
bus->tx_sderrs = bus->fc_rcvd = bus->fc_xoff = bus->fc_xon = 0;
bus->rxglomfail = bus->rxglomframes = bus->rxglompkts = 0;
bus->f2rxhdrs = bus->f2rxdata = bus->f2txdata = bus->f1regdata = 0;
}
static int dhdsdio_pktgen_get(dhd_bus_t *bus, u8 *arg)
{
dhd_pktgen_t pktgen;
pktgen.version = DHD_PKTGEN_VERSION;
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
static int dhdsdio_pktgen_set(dhd_bus_t *bus, u8 *arg)
{
dhd_pktgen_t pktgen;
uint oldcnt, oldmode;
memcpy(&pktgen, arg, sizeof(pktgen));
if (pktgen.version != DHD_PKTGEN_VERSION)
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
dhdsdio_membytes(dhd_bus_t *bus, bool write, u32 address, u8 *data,
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
bcmerror = dhdsdio_set_siaddr_window(bus, address);
if (bcmerror) {
DHD_ERROR(("%s: window change failed\n", __func__));
goto xfer_done;
}
while (size) {
DHD_INFO(("%s: %s %d bytes at offset 0x%08x in window 0x%08x\n",
__func__, (write ? "write" : "read"), dsize,
sdaddr, (address & SBSDIO_SBWINDOW_MASK)));
bcmerror =
bcmsdh_rwdata(bus->sdh, write, sdaddr, data, dsize);
if (bcmerror) {
DHD_ERROR(("%s: membytes transfer failed\n", __func__));
break;
}
size -= dsize;
if (size) {
data += dsize;
address += dsize;
bcmerror = dhdsdio_set_siaddr_window(bus, address);
if (bcmerror) {
DHD_ERROR(("%s: window change failed\n",
__func__));
break;
}
sdaddr = 0;
dsize = min_t(uint, SBSDIO_SB_OFT_ADDR_LIMIT, size);
}
}
xfer_done:
if (dhdsdio_set_siaddr_window(bus, bcmsdh_cur_sbwad(bus->sdh))) {
DHD_ERROR(("%s: FAILED to set window back to 0x%x\n",
__func__, bcmsdh_cur_sbwad(bus->sdh)));
}
return bcmerror;
}
static int dhdsdio_readshared(dhd_bus_t *bus, sdpcm_shared_t *sh)
{
u32 addr;
int rv;
rv = dhdsdio_membytes(bus, false, bus->ramsize - 4, (u8 *)&addr, 4);
if (rv < 0)
return rv;
addr = le32_to_cpu(addr);
DHD_INFO(("sdpcm_shared address 0x%08X\n", addr));
if (addr == 0 || ((~addr >> 16) & 0xffff) == (addr & 0xffff)) {
DHD_ERROR(("%s: address (0x%08x) of sdpcm_shared invalid\n",
__func__, addr));
return -EBADE;
}
rv = dhdsdio_membytes(bus, false, addr, (u8 *) sh,
sizeof(sdpcm_shared_t));
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
DHD_ERROR(("%s: sdpcm_shared version %d in dhd "
"is different than sdpcm_shared version %d in dongle\n",
__func__, SDPCM_SHARED_VERSION,
sh->flags & SDPCM_SHARED_VERSION_MASK));
return -EBADE;
}
return 0;
}
static int dhdsdio_checkdied(dhd_bus_t *bus, u8 *data, uint size)
{
int bcmerror = 0;
uint msize = 512;
char *mbuffer = NULL;
uint maxstrlen = 256;
char *str = NULL;
trap_t tr;
sdpcm_shared_t sdpcm_shared;
struct bcmstrbuf strbuf;
DHD_TRACE(("%s: Enter\n", __func__));
if (data == NULL) {
size = msize;
mbuffer = data = kmalloc(msize, GFP_ATOMIC);
if (mbuffer == NULL) {
DHD_ERROR(("%s: kmalloc(%d) failed\n", __func__,
msize));
bcmerror = -ENOMEM;
goto done;
}
}
str = kmalloc(maxstrlen, GFP_ATOMIC);
if (str == NULL) {
DHD_ERROR(("%s: kmalloc(%d) failed\n", __func__, maxstrlen));
bcmerror = -ENOMEM;
goto done;
}
bcmerror = dhdsdio_readshared(bus, &sdpcm_shared);
if (bcmerror < 0)
goto done;
bcm_binit(&strbuf, data, size);
bcm_bprintf(&strbuf,
"msgtrace address : 0x%08X\nconsole address : 0x%08X\n",
sdpcm_shared.msgtrace_addr, sdpcm_shared.console_addr);
if ((sdpcm_shared.flags & SDPCM_SHARED_ASSERT_BUILT) == 0) {
bcm_bprintf(&strbuf, "Assrt not built in dongle\n");
}
if ((sdpcm_shared.flags & (SDPCM_SHARED_ASSERT | SDPCM_SHARED_TRAP)) ==
0) {
bcm_bprintf(&strbuf, "No trap%s in dongle",
(sdpcm_shared.flags & SDPCM_SHARED_ASSERT_BUILT)
? "/assrt" : "");
} else {
if (sdpcm_shared.flags & SDPCM_SHARED_ASSERT) {
bcm_bprintf(&strbuf, "Dongle assert");
if (sdpcm_shared.assert_exp_addr != 0) {
str[0] = '\0';
bcmerror = dhdsdio_membytes(bus, false,
sdpcm_shared.assert_exp_addr,
(u8 *) str, maxstrlen);
if (bcmerror < 0)
goto done;
str[maxstrlen - 1] = '\0';
bcm_bprintf(&strbuf, " expr \"%s\"", str);
}
if (sdpcm_shared.assert_file_addr != 0) {
str[0] = '\0';
bcmerror = dhdsdio_membytes(bus, false,
sdpcm_shared.assert_file_addr,
(u8 *) str, maxstrlen);
if (bcmerror < 0)
goto done;
str[maxstrlen - 1] = '\0';
bcm_bprintf(&strbuf, " file \"%s\"", str);
}
bcm_bprintf(&strbuf, " line %d ",
sdpcm_shared.assert_line);
}
if (sdpcm_shared.flags & SDPCM_SHARED_TRAP) {
bcmerror = dhdsdio_membytes(bus, false,
sdpcm_shared.trap_addr, (u8 *)&tr,
sizeof(trap_t));
if (bcmerror < 0)
goto done;
bcm_bprintf(&strbuf,
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
DHD_ERROR(("%s: %s\n", __func__, strbuf.origbuf));
#ifdef DHD_DEBUG
if (sdpcm_shared.flags & SDPCM_SHARED_TRAP) {
dhdsdio_mem_dump(bus);
}
#endif
done:
kfree(mbuffer);
kfree(str);
return bcmerror;
}
static int dhdsdio_mem_dump(dhd_bus_t *bus)
{
int ret = 0;
int size;
int start = 0;
int read_size = 0;
u8 *buf = NULL, *databuf = NULL;
size = bus->ramsize;
buf = kmalloc(size, GFP_ATOMIC);
if (!buf) {
DHD_ERROR(("%s: Out of memory (%d bytes)\n", __func__, size));
return -1;
}
printk(KERN_DEBUG "Dump dongle memory");
databuf = buf;
while (size) {
read_size = min(MEMBLOCK, size);
ret = dhdsdio_membytes(bus, false, start, databuf, read_size);
if (ret) {
DHD_ERROR(("%s: Error membytes %d\n", __func__, ret));
kfree(buf);
return -1;
}
printk(".");
size -= read_size;
start += read_size;
databuf += read_size;
}
printk(KERN_DEBUG "Done\n");
if (write_to_file(bus->dhd, buf, bus->ramsize)) {
DHD_ERROR(("%s: Error writing to files\n", __func__));
return -1;
}
return 0;
}
static int dhdsdio_readconsole(dhd_bus_t *bus)
{
dhd_console_t *c = &bus->console;
u8 line[CONSOLE_LINE_MAX], ch;
u32 n, idx, addr;
int rv;
if (bus->console_addr == 0)
return 0;
addr = bus->console_addr + offsetof(hndrte_cons_t, log);
rv = dhdsdio_membytes(bus, false, addr, (u8 *)&c->log,
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
rv = dhdsdio_membytes(bus, false, addr, c->buf, c->bufsize);
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
int dhdsdio_downloadvars(dhd_bus_t *bus, void *arg, int len)
{
int bcmerror = 0;
DHD_TRACE(("%s: Enter\n", __func__));
if (bus->dhd->up) {
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
dhdsdio_doiovar(dhd_bus_t *bus, const bcm_iovar_t *vi, u32 actionid,
const char *name, void *params, int plen, void *arg, int len,
int val_size)
{
int bcmerror = 0;
s32 int_val = 0;
bool bool_val = 0;
DHD_TRACE(("%s: Enter, action %d name %s params %p plen %d arg %p "
"len %d val_size %d\n",
__func__, actionid, name, params, plen, arg, len, val_size));
bcmerror = bcm_iovar_lencheck(vi, arg, len, IOV_ISSET(actionid));
if (bcmerror != 0)
goto exit;
if (plen >= (int)sizeof(int_val))
memcpy(&int_val, params, sizeof(int_val));
bool_val = (int_val != 0) ? true : false;
dhd_os_sdlock(bus->dhd);
if (bus->dhd->dongle_reset && !(actionid == IOV_SVAL(IOV_DEVRESET) ||
actionid == IOV_GVAL(IOV_DEVRESET))) {
bcmerror = -EPERM;
goto exit;
}
if (vi->varid == IOV_SLEEP) {
if (IOV_ISSET(actionid)) {
bcmerror = dhdsdio_bussleep(bus, bool_val);
} else {
int_val = (s32) bus->sleeping;
memcpy(arg, &int_val, val_size);
}
goto exit;
}
if (!bus->dhd->dongle_reset) {
BUS_WAKE(bus);
dhdsdio_clkctl(bus, CLK_AVAIL, false);
}
switch (actionid) {
case IOV_GVAL(IOV_INTR):
int_val = (s32) bus->intr;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_INTR):
bus->intr = bool_val;
bus->intdis = false;
if (bus->dhd->up) {
if (bus->intr) {
DHD_INTR(("%s: enable SDIO device interrupts\n",
__func__));
bcmsdh_intr_enable(bus->sdh);
} else {
DHD_INTR(("%s: disable SDIO interrupts\n",
__func__));
bcmsdh_intr_disable(bus->sdh);
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
if ((int_val < 0) && (int_val != DHD_IDLE_IMMEDIATE))
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
ASSERT(plen >= 2 * sizeof(int));
address = (u32) int_val;
memcpy(&int_val, (char *)params + sizeof(int_val),
sizeof(int_val));
size = (uint) int_val;
dsize = set ? plen - (2 * sizeof(int)) : len;
if (dsize < size) {
DHD_ERROR(("%s: error on %s membytes, addr "
"0x%08x size %d dsize %d\n",
__func__, (set ? "set" : "get"),
address, size, dsize));
bcmerror = -EINVAL;
break;
}
DHD_INFO(("%s: Request to %s %d bytes at address "
"0x%08x\n",
__func__, (set ? "write" : "read"), size, address));
if ((bus->orig_ramsize) &&
((address > bus->orig_ramsize)
|| (address + size > bus->orig_ramsize))) {
DHD_ERROR(("%s: ramsize 0x%08x doesn't have %d "
"bytes at 0x%08x\n",
__func__, bus->orig_ramsize, size, address));
bcmerror = -EINVAL;
break;
}
data =
set ? (u8 *) params +
2 * sizeof(int) : (u8 *) arg;
bcmerror =
dhdsdio_membytes(bus, set, address, data, size);
break;
}
case IOV_GVAL(IOV_MEMSIZE):
int_val = (s32) bus->ramsize;
memcpy(arg, &int_val, val_size);
break;
case IOV_GVAL(IOV_SDIOD_DRIVE):
int_val = (s32) dhd_sdiod_drive_strength;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_SDIOD_DRIVE):
dhd_sdiod_drive_strength = int_val;
dhdsdio_sdiod_drive_strength_init(bus,
dhd_sdiod_drive_strength);
break;
case IOV_SVAL(IOV_DOWNLOAD):
bcmerror = dhdsdio_download_state(bus, bool_val);
break;
case IOV_SVAL(IOV_VARS):
bcmerror = dhdsdio_downloadvars(bus, arg, len);
break;
case IOV_GVAL(IOV_READAHEAD):
int_val = (s32) dhd_readahead;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_READAHEAD):
if (bool_val && !dhd_readahead)
bus->nextlen = 0;
dhd_readahead = bool_val;
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
int_val = (s32) dhd_alignctl;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_ALIGNCTL):
dhd_alignctl = bool_val;
break;
case IOV_GVAL(IOV_SDALIGN):
int_val = DHD_SDALIGN;
memcpy(arg, &int_val, val_size);
break;
#ifdef DHD_DEBUG
case IOV_GVAL(IOV_VARS):
if (bus->varsz < (uint) len)
memcpy(arg, bus->vars, bus->varsz);
else
bcmerror = -EOVERFLOW;
break;
#endif
#ifdef DHD_DEBUG
case IOV_GVAL(IOV_SDREG):
{
sdreg_t *sd_ptr;
u32 addr, size;
sd_ptr = (sdreg_t *) params;
addr = (unsigned long)bus->regs + sd_ptr->offset;
size = sd_ptr->func;
int_val = (s32) bcmsdh_reg_read(bus->sdh, addr, size);
if (bcmsdh_regfail(bus->sdh))
bcmerror = -EIO;
memcpy(arg, &int_val, sizeof(s32));
break;
}
case IOV_SVAL(IOV_SDREG):
{
sdreg_t *sd_ptr;
u32 addr, size;
sd_ptr = (sdreg_t *) params;
addr = (unsigned long)bus->regs + sd_ptr->offset;
size = sd_ptr->func;
bcmsdh_reg_write(bus->sdh, addr, size, sd_ptr->value);
if (bcmsdh_regfail(bus->sdh))
bcmerror = -EIO;
break;
}
case IOV_GVAL(IOV_SBREG):
{
sdreg_t sdreg;
u32 addr, size;
memcpy(&sdreg, params, sizeof(sdreg));
addr = SI_ENUM_BASE + sdreg.offset;
size = sdreg.func;
int_val = (s32) bcmsdh_reg_read(bus->sdh, addr, size);
if (bcmsdh_regfail(bus->sdh))
bcmerror = -EIO;
memcpy(arg, &int_val, sizeof(s32));
break;
}
case IOV_SVAL(IOV_SBREG):
{
sdreg_t sdreg;
u32 addr, size;
memcpy(&sdreg, params, sizeof(sdreg));
addr = SI_ENUM_BASE + sdreg.offset;
size = sdreg.func;
bcmsdh_reg_write(bus->sdh, addr, size, sdreg.value);
if (bcmsdh_regfail(bus->sdh))
bcmerror = -EIO;
break;
}
case IOV_GVAL(IOV_SDCIS):
{
*(char *)arg = 0;
strcat(arg, "\nFunc 0\n");
bcmsdh_cis_read(bus->sdh, 0x10,
(u8 *) arg + strlen(arg),
SBSDIO_CIS_SIZE_LIMIT);
strcat(arg, "\nFunc 1\n");
bcmsdh_cis_read(bus->sdh, 0x11,
(u8 *) arg + strlen(arg),
SBSDIO_CIS_SIZE_LIMIT);
strcat(arg, "\nFunc 2\n");
bcmsdh_cis_read(bus->sdh, 0x12,
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
int_val = (s32) dhd_txbound;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_TXBOUND):
dhd_txbound = (uint) int_val;
break;
case IOV_GVAL(IOV_RXBOUND):
int_val = (s32) dhd_rxbound;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_RXBOUND):
dhd_rxbound = (uint) int_val;
break;
case IOV_GVAL(IOV_TXMINMAX):
int_val = (s32) dhd_txminmax;
memcpy(arg, &int_val, val_size);
break;
case IOV_SVAL(IOV_TXMINMAX):
dhd_txminmax = (uint) int_val;
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
bcmerror = dhdsdio_pktgen_get(bus, arg);
break;
case IOV_SVAL(IOV_PKTGEN):
bcmerror = dhdsdio_pktgen_set(bus, arg);
break;
#endif
case IOV_SVAL(IOV_DEVRESET):
DHD_TRACE(("%s: Called set IOV_DEVRESET=%d dongle_reset=%d "
"busstate=%d\n",
__func__, bool_val, bus->dhd->dongle_reset,
bus->dhd->busstate));
dhd_bus_devreset(bus->dhd, (u8) bool_val);
break;
case IOV_GVAL(IOV_DEVRESET):
DHD_TRACE(("%s: Called get IOV_DEVRESET\n", __func__));
int_val = (bool) bus->dhd->dongle_reset;
memcpy(arg, &int_val, val_size);
break;
default:
bcmerror = -ENOTSUPP;
break;
}
exit:
if ((bus->idletime == DHD_IDLE_IMMEDIATE) && !bus->dpc_sched) {
bus->activity = false;
dhdsdio_clkctl(bus, CLK_NONE, true);
}
dhd_os_sdunlock(bus->dhd);
if (actionid == IOV_SVAL(IOV_DEVRESET) && bool_val == false)
dhd_preinit_ioctls((dhd_pub_t *) bus->dhd);
return bcmerror;
}
static int dhdsdio_write_vars(dhd_bus_t *bus)
{
int bcmerror = 0;
u32 varsize;
u32 varaddr;
u8 *vbuffer;
u32 varsizew;
#ifdef DHD_DEBUG
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
dhdsdio_membytes(bus, true, varaddr, vbuffer, varsize);
#ifdef DHD_DEBUG
DHD_INFO(("Compare NVRAM dl & ul; varsize=%d\n", varsize));
nvram_ularray = kmalloc(varsize, GFP_ATOMIC);
if (!nvram_ularray)
return -ENOMEM;
memset(nvram_ularray, 0xaa, varsize);
bcmerror =
dhdsdio_membytes(bus, false, varaddr, nvram_ularray,
varsize);
if (bcmerror) {
DHD_ERROR(("%s: error %d on reading %d nvram bytes at "
"0x%08x\n", __func__, bcmerror, varsize, varaddr));
}
if (memcmp(vbuffer, nvram_ularray, varsize)) {
DHD_ERROR(("%s: Downloaded NVRAM image is corrupted.\n",
__func__));
} else
DHD_ERROR(("%s: Download/Upload/Compare of NVRAM ok.\n",
__func__));
kfree(nvram_ularray);
#endif
kfree(vbuffer);
}
DHD_INFO(("Physical memory size: %d, usable memory size: %d\n",
bus->orig_ramsize, bus->ramsize));
DHD_INFO(("Vars are at %d, orig varsize is %d\n", varaddr, varsize));
varsize = ((bus->orig_ramsize - 4) - varaddr);
if (bcmerror) {
varsizew = 0;
} else {
varsizew = varsize / 4;
varsizew = (~varsizew << 16) | (varsizew & 0x0000FFFF);
varsizew = cpu_to_le32(varsizew);
}
DHD_INFO(("New varsize is %d, length token=0x%08x\n", varsize,
varsizew));
bcmerror = dhdsdio_membytes(bus, true, (bus->orig_ramsize - 4),
(u8 *)&varsizew, 4);
return bcmerror;
}
static int dhdsdio_download_state(dhd_bus_t *bus, bool enter)
{
uint retries;
u32 regdata;
int bcmerror = 0;
if (enter) {
bus->alp_only = true;
dhdsdio_chip_disablecore(bus->sdh, bus->ci->armcorebase);
dhdsdio_chip_resetcore(bus->sdh, bus->ci->ramcorebase);
if (bus->ramsize) {
u32 zeros = 0;
dhdsdio_membytes(bus, true, bus->ramsize - 4,
(u8 *)&zeros, 4);
}
} else {
regdata = bcmsdh_reg_read(bus->sdh,
CORE_SB(bus->ci->ramcorebase, sbtmstatelow), 4);
regdata &= (SBTML_RESET | SBTML_REJ_MASK |
(SICF_CLOCK_EN << SBTML_SICF_SHIFT));
if ((SICF_CLOCK_EN << SBTML_SICF_SHIFT) != regdata) {
DHD_ERROR(("%s: SOCRAM core is down after reset?\n",
__func__));
bcmerror = -EBADE;
goto fail;
}
bcmerror = dhdsdio_write_vars(bus);
if (bcmerror) {
DHD_ERROR(("%s: no vars written to RAM\n", __func__));
bcmerror = 0;
}
W_SDREG(0xFFFFFFFF, &bus->regs->intstatus, retries);
dhdsdio_chip_resetcore(bus->sdh, bus->ci->armcorebase);
bus->alp_only = false;
bus->dhd->busstate = DHD_BUS_LOAD;
}
fail:
return bcmerror;
}
int
dhd_bus_iovar_op(dhd_pub_t *dhdp, const char *name,
void *params, int plen, void *arg, int len, bool set)
{
dhd_bus_t *bus = dhdp->bus;
const bcm_iovar_t *vi = NULL;
int bcmerror = 0;
int val_size;
u32 actionid;
DHD_TRACE(("%s: Enter\n", __func__));
ASSERT(name);
ASSERT(len >= 0);
ASSERT(set || (arg && len));
ASSERT(!set || (!params && !plen));
vi = bcm_iovar_lookup(dhdsdio_iovars, name);
if (vi == NULL) {
dhd_os_sdlock(bus->dhd);
BUS_WAKE(bus);
dhdsdio_clkctl(bus, CLK_AVAIL, false);
bcmerror =
bcmsdh_iovar_op(bus->sdh, name, params, plen, arg, len,
set);
if (set && strcmp(name, "sd_divisor") == 0) {
if (bcmsdh_iovar_op(bus->sdh, "sd_divisor", NULL, 0,
&bus->sd_divisor, sizeof(s32),
false) != 0) {
bus->sd_divisor = -1;
DHD_ERROR(("%s: fail on %s get\n", __func__,
name));
} else {
DHD_INFO(("%s: noted %s update, value now %d\n",
__func__, name, bus->sd_divisor));
}
}
if (set && strcmp(name, "sd_mode") == 0) {
if (bcmsdh_iovar_op(bus->sdh, "sd_mode", NULL, 0,
&bus->sd_mode, sizeof(s32),
false) != 0) {
bus->sd_mode = -1;
DHD_ERROR(("%s: fail on %s get\n", __func__,
name));
} else {
DHD_INFO(("%s: noted %s update, value now %d\n",
__func__, name, bus->sd_mode));
}
}
if (set && strcmp(name, "sd_blocksize") == 0) {
s32 fnum = 2;
if (bcmsdh_iovar_op
(bus->sdh, "sd_blocksize", &fnum, sizeof(s32),
&bus->blocksize, sizeof(s32),
false) != 0) {
bus->blocksize = 0;
DHD_ERROR(("%s: fail on %s get\n", __func__,
"sd_blocksize"));
} else {
DHD_INFO(("%s: noted %s update, value now %d\n",
__func__, "sd_blocksize",
bus->blocksize));
}
}
bus->roundup = min(max_roundup, bus->blocksize);
if ((bus->idletime == DHD_IDLE_IMMEDIATE) && !bus->dpc_sched) {
bus->activity = false;
dhdsdio_clkctl(bus, CLK_NONE, true);
}
dhd_os_sdunlock(bus->dhd);
goto exit;
}
DHD_CTL(("%s: %s %s, len %d plen %d\n", __func__,
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
bcmerror =
dhdsdio_doiovar(bus, vi, actionid, name, params, plen, arg, len,
val_size);
exit:
return bcmerror;
}
void dhd_bus_stop(struct dhd_bus *bus, bool enforce_mutex)
{
u32 local_hostintmask;
u8 saveclk;
uint retries;
int err;
DHD_TRACE(("%s: Enter\n", __func__));
if (enforce_mutex)
dhd_os_sdlock(bus->dhd);
BUS_WAKE(bus);
dhdsdio_clkctl(bus, CLK_AVAIL, false);
W_SDREG(0, &bus->regs->hostintmask, retries);
local_hostintmask = bus->hostintmask;
bus->hostintmask = 0;
bus->dhd->busstate = DHD_BUS_DOWN;
saveclk =
bcmsdh_cfg_read(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
&err);
if (!err) {
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
(saveclk | SBSDIO_FORCE_HT), &err);
}
if (err) {
DHD_ERROR(("%s: Failed to force clock for F2: err %d\n",
__func__, err));
}
DHD_INTR(("%s: disable SDIO interrupts\n", __func__));
bcmsdh_intr_disable(bus->sdh);
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_0, SDIOD_CCCR_IOEN,
SDIO_FUNC_ENABLE_1, NULL);
W_SDREG(local_hostintmask, &bus->regs->intstatus, retries);
dhdsdio_clkctl(bus, CLK_SDONLY, false);
bcm_pktq_flush(&bus->txq, true, NULL, NULL);
if (bus->glomd)
bcm_pkt_buf_free_skb(bus->glomd);
if (bus->glom)
bcm_pkt_buf_free_skb(bus->glom);
bus->glom = bus->glomd = NULL;
bus->rxlen = 0;
dhd_os_ioctl_resp_wake(bus->dhd);
bus->rxskip = false;
bus->tx_seq = bus->rx_seq = 0;
if (enforce_mutex)
dhd_os_sdunlock(bus->dhd);
}
int dhd_bus_init(dhd_pub_t *dhdp, bool enforce_mutex)
{
dhd_bus_t *bus = dhdp->bus;
dhd_timeout_t tmo;
uint retries = 0;
u8 ready, enable;
int err, ret = 0;
u8 saveclk;
DHD_TRACE(("%s: Enter\n", __func__));
ASSERT(bus->dhd);
if (!bus->dhd)
return 0;
if (enforce_mutex)
dhd_os_sdlock(bus->dhd);
dhdsdio_clkctl(bus, CLK_AVAIL, false);
if (bus->clkstate != CLK_AVAIL)
goto exit;
saveclk =
bcmsdh_cfg_read(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
&err);
if (!err) {
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
(saveclk | SBSDIO_FORCE_HT), &err);
}
if (err) {
DHD_ERROR(("%s: Failed to force clock for F2: err %d\n",
__func__, err));
goto exit;
}
W_SDREG((SDPCM_PROT_VERSION << SMB_DATA_VERSION_SHIFT),
&bus->regs->tosbmailboxdata, retries);
enable = (SDIO_FUNC_ENABLE_1 | SDIO_FUNC_ENABLE_2);
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_0, SDIOD_CCCR_IOEN, enable, NULL);
dhd_timeout_start(&tmo, DHD_WAIT_F2RDY * 1000);
ready = 0;
while (ready != enable && !dhd_timeout_expired(&tmo))
ready =
bcmsdh_cfg_read(bus->sdh, SDIO_FUNC_0, SDIOD_CCCR_IORDY,
NULL);
DHD_INFO(("%s: enable 0x%02x, ready 0x%02x (waited %uus)\n",
__func__, enable, ready, tmo.elapsed));
if (ready == enable) {
bus->hostintmask = HOSTINTMASK;
W_SDREG(bus->hostintmask,
(unsigned int *)CORE_BUS_REG(bus->ci->buscorebase,
hostintmask), retries);
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_WATERMARK,
(u8) watermark, &err);
dhdp->busstate = DHD_BUS_DATA;
bus->intdis = false;
if (bus->intr) {
DHD_INTR(("%s: enable SDIO device interrupts\n",
__func__));
bcmsdh_intr_enable(bus->sdh);
} else {
DHD_INTR(("%s: disable SDIO interrupts\n", __func__));
bcmsdh_intr_disable(bus->sdh);
}
}
else {
enable = SDIO_FUNC_ENABLE_1;
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_0, SDIOD_CCCR_IOEN, enable,
NULL);
}
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
saveclk, &err);
if (dhdp->busstate != DHD_BUS_DATA)
dhdsdio_clkctl(bus, CLK_NONE, false);
exit:
if (enforce_mutex)
dhd_os_sdunlock(bus->dhd);
return ret;
}
static void dhdsdio_rxfail(dhd_bus_t *bus, bool abort, bool rtx)
{
bcmsdh_info_t *sdh = bus->sdh;
sdpcmd_regs_t *regs = bus->regs;
uint retries = 0;
u16 lastrbc;
u8 hi, lo;
int err;
DHD_ERROR(("%s: %sterminate frame%s\n", __func__,
(abort ? "abort command, " : ""),
(rtx ? ", send NAK" : "")));
if (abort)
bcmsdh_abort(sdh, SDIO_FUNC_2);
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_FRAMECTRL, SFC_RF_TERM,
&err);
bus->f1regdata++;
for (lastrbc = retries = 0xffff; retries > 0; retries--) {
hi = bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_RFRAMEBCHI,
NULL);
lo = bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_RFRAMEBCLO,
NULL);
bus->f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
if ((hi > (lastrbc >> 8)) && (lo > (lastrbc & 0x00ff))) {
DHD_ERROR(("%s: count growing: last 0x%04x now "
"0x%04x\n",
__func__, lastrbc, ((hi << 8) + lo)));
}
lastrbc = (hi << 8) + lo;
}
if (!retries) {
DHD_ERROR(("%s: count never zeroed: last 0x%04x\n",
__func__, lastrbc));
} else {
DHD_INFO(("%s: flush took %d iterations\n", __func__,
(0xffff - retries)));
}
if (rtx) {
bus->rxrtx++;
W_SDREG(SMB_NAK, &regs->tosbmailbox, retries);
bus->f1regdata++;
if (retries <= retry_limit)
bus->rxskip = true;
}
bus->nextlen = 0;
if (err || bcmsdh_regfail(sdh))
bus->dhd->busstate = DHD_BUS_DOWN;
}
static void
dhdsdio_read_control(dhd_bus_t *bus, u8 *hdr, uint len, uint doff)
{
bcmsdh_info_t *sdh = bus->sdh;
uint rdlen, pad;
int sdret;
DHD_TRACE(("%s: Enter\n", __func__));
if ((bus->bus == SPI_BUS) && (!bus->usebufpool))
goto gotpkt;
ASSERT(bus->rxbuf);
bus->rxctl = bus->rxbuf;
if (dhd_alignctl) {
bus->rxctl += firstread;
pad = ((unsigned long)bus->rxctl % DHD_SDALIGN);
if (pad)
bus->rxctl += (DHD_SDALIGN - pad);
bus->rxctl -= firstread;
}
ASSERT(bus->rxctl >= bus->rxbuf);
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
((len + pad) < bus->dhd->maxctl))
rdlen += pad;
} else if (rdlen % DHD_SDALIGN) {
rdlen += DHD_SDALIGN - (rdlen % DHD_SDALIGN);
}
if (forcealign && (rdlen & (ALIGNMENT - 1)))
rdlen = roundup(rdlen, ALIGNMENT);
if ((rdlen + firstread) > bus->dhd->maxctl) {
DHD_ERROR(("%s: %d-byte control read exceeds %d-byte buffer\n",
__func__, rdlen, bus->dhd->maxctl));
bus->dhd->rx_errors++;
dhdsdio_rxfail(bus, false, false);
goto done;
}
if ((len - doff) > bus->dhd->maxctl) {
DHD_ERROR(("%s: %d-byte ctl frame (%d-byte ctl data) exceeds "
"%d-byte limit\n",
__func__, len, (len - doff), bus->dhd->maxctl));
bus->dhd->rx_errors++;
bus->rx_toolong++;
dhdsdio_rxfail(bus, false, false);
goto done;
}
sdret = bcmsdh_recv_buf(bus, bcmsdh_cur_sbwad(sdh), SDIO_FUNC_2,
F2SYNC, (bus->rxctl + firstread), rdlen,
NULL, NULL, NULL);
bus->f2rxdata++;
ASSERT(sdret != -BCME_PENDING);
if (sdret < 0) {
DHD_ERROR(("%s: read %d control bytes failed: %d\n",
__func__, rdlen, sdret));
bus->rxc_errors++;
dhdsdio_rxfail(bus, true, true);
goto done;
}
gotpkt:
#ifdef DHD_DEBUG
if (DHD_BYTES_ON() && DHD_CTL_ON()) {
printk(KERN_DEBUG "RxCtrl:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, bus->rxctl, len);
}
#endif
bus->rxctl += doff;
bus->rxlen = len - doff;
done:
dhd_os_ioctl_resp_wake(bus->dhd);
}
static u8 dhdsdio_rxglom(dhd_bus_t *bus, u8 rxseq)
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
DHD_TRACE(("dhdsdio_rxglom: start: glomd %p glom %p\n", bus->glomd,
bus->glom));
if (bus->glomd) {
dhd_os_sdlock_rxq(bus->dhd);
pfirst = plast = pnext = NULL;
dlen = (u16) (bus->glomd->len);
dptr = bus->glomd->data;
if (!dlen || (dlen & 1)) {
DHD_ERROR(("%s: bad glomd len(%d), ignore descriptor\n",
__func__, dlen));
dlen = 0;
}
for (totlen = num = 0; dlen; num++) {
sublen = get_unaligned_le16(dptr);
dlen -= sizeof(u16);
dptr += sizeof(u16);
if ((sublen < SDPCM_HDRLEN) ||
((num == 0) && (sublen < (2 * SDPCM_HDRLEN)))) {
DHD_ERROR(("%s: descriptor len %d bad: %d\n",
__func__, num, sublen));
pnext = NULL;
break;
}
if (sublen % DHD_SDALIGN) {
DHD_ERROR(("%s: sublen %d not multiple of %d\n",
__func__, sublen, DHD_SDALIGN));
usechain = false;
}
totlen += sublen;
if (!dlen) {
sublen +=
(roundup(totlen, bus->blocksize) - totlen);
totlen = roundup(totlen, bus->blocksize);
}
pnext = bcm_pkt_buf_get_skb(sublen + DHD_SDALIGN);
if (pnext == NULL) {
DHD_ERROR(("%s: bcm_pkt_buf_get_skb failed, "
"num %d len %d\n", __func__,
num, sublen));
break;
}
ASSERT(!(pnext->prev));
if (!pfirst) {
ASSERT(!plast);
pfirst = plast = pnext;
} else {
ASSERT(plast);
plast->next = pnext;
plast = pnext;
}
PKTALIGN(pnext, sublen, DHD_SDALIGN);
}
if (pnext) {
DHD_GLOM(("%s: allocated %d-byte packet chain for %d "
"subframes\n", __func__, totlen, num));
if (DHD_GLOM_ON() && bus->nextlen) {
if (totlen != bus->nextlen) {
DHD_GLOM(("%s: glomdesc mismatch: nextlen %d glomdesc %d " "rxseq %d\n",
__func__, bus->nextlen,
totlen, rxseq));
}
}
bus->glom = pfirst;
pfirst = pnext = NULL;
} else {
if (pfirst)
bcm_pkt_buf_free_skb(pfirst);
bus->glom = NULL;
num = 0;
}
bcm_pkt_buf_free_skb(bus->glomd);
bus->glomd = NULL;
bus->nextlen = 0;
dhd_os_sdunlock_rxq(bus->dhd);
}
if (bus->glom) {
if (DHD_GLOM_ON()) {
DHD_GLOM(("%s: try superframe read, packet chain:\n",
__func__));
for (pnext = bus->glom; pnext; pnext = pnext->next) {
DHD_GLOM((" %p: %p len 0x%04x (%d)\n",
pnext, (u8 *) (pnext->data),
pnext->len, pnext->len));
}
}
pfirst = bus->glom;
dlen = (u16) bcm_pkttotlen(pfirst);
if (usechain) {
errcode = bcmsdh_recv_buf(bus,
bcmsdh_cur_sbwad(bus->sdh), SDIO_FUNC_2,
F2SYNC, (u8 *) pfirst->data, dlen,
pfirst, NULL, NULL);
} else if (bus->dataptr) {
errcode = bcmsdh_recv_buf(bus,
bcmsdh_cur_sbwad(bus->sdh), SDIO_FUNC_2,
F2SYNC, bus->dataptr, dlen,
NULL, NULL, NULL);
sublen = (u16) bcm_pktfrombuf(pfirst, 0, dlen,
bus->dataptr);
if (sublen != dlen) {
DHD_ERROR(("%s: FAILED TO COPY, dlen %d sublen %d\n",
__func__, dlen, sublen));
errcode = -1;
}
pnext = NULL;
} else {
DHD_ERROR(("COULDN'T ALLOC %d-BYTE GLOM, FORCE FAILURE\n",
dlen));
errcode = -1;
}
bus->f2rxdata++;
ASSERT(errcode != -BCME_PENDING);
if (errcode < 0) {
DHD_ERROR(("%s: glom read of %d bytes failed: %d\n",
__func__, dlen, errcode));
bus->dhd->rx_errors++;
if (bus->glomerr++ < 3) {
dhdsdio_rxfail(bus, true, true);
} else {
bus->glomerr = 0;
dhdsdio_rxfail(bus, true, false);
dhd_os_sdlock_rxq(bus->dhd);
bcm_pkt_buf_free_skb(bus->glom);
dhd_os_sdunlock_rxq(bus->dhd);
bus->rxglomfail++;
bus->glom = NULL;
}
return 0;
}
#ifdef DHD_DEBUG
if (DHD_GLOM_ON()) {
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
DHD_INFO(("%s: nextlen too large (%d) seq %d\n",
__func__, bus->nextlen, seq));
bus->nextlen = 0;
}
doff = SDPCM_DOFFSET_VALUE(&dptr[SDPCM_FRAMETAG_LEN]);
txmax = SDPCM_WINDOW_VALUE(&dptr[SDPCM_FRAMETAG_LEN]);
errcode = 0;
if ((u16)~(sublen ^ check)) {
DHD_ERROR(("%s (superframe): HW hdr error: len/check "
"0x%04x/0x%04x\n", __func__, sublen, check));
errcode = -1;
} else if (roundup(sublen, bus->blocksize) != dlen) {
DHD_ERROR(("%s (superframe): len 0x%04x, rounded "
"0x%04x, expect 0x%04x\n",
__func__, sublen,
roundup(sublen, bus->blocksize), dlen));
errcode = -1;
} else if (SDPCM_PACKET_CHANNEL(&dptr[SDPCM_FRAMETAG_LEN]) !=
SDPCM_GLOM_CHANNEL) {
DHD_ERROR(("%s (superframe): bad channel %d\n",
__func__,
SDPCM_PACKET_CHANNEL(&dptr
[SDPCM_FRAMETAG_LEN])));
errcode = -1;
} else if (SDPCM_GLOMDESC(&dptr[SDPCM_FRAMETAG_LEN])) {
DHD_ERROR(("%s (superframe): got second descriptor?\n",
__func__));
errcode = -1;
} else if ((doff < SDPCM_HDRLEN) ||
(doff > (pfirst->len - SDPCM_HDRLEN))) {
DHD_ERROR(("%s (superframe): Bad data offset %d: HW %d "
"pkt %d min %d\n",
__func__, doff, sublen,
pfirst->len, SDPCM_HDRLEN));
errcode = -1;
}
if (rxseq != seq) {
DHD_INFO(("%s: (superframe) rx_seq %d, expected %d\n",
__func__, seq, rxseq));
bus->rx_badseq++;
rxseq = seq;
}
if ((u8) (txmax - bus->tx_seq) > 0x40) {
DHD_ERROR(("%s: unlikely tx max %d with tx_seq %d\n",
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
#ifdef DHD_DEBUG
if (DHD_GLOM_ON()) {
printk(KERN_DEBUG "subframe:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
dptr, 32);
}
#endif
if ((u16)~(sublen ^ check)) {
DHD_ERROR(("%s (subframe %d): HW hdr error: "
"len/check 0x%04x/0x%04x\n",
__func__, num, sublen, check));
errcode = -1;
} else if ((sublen > dlen) || (sublen < SDPCM_HDRLEN)) {
DHD_ERROR(("%s (subframe %d): length mismatch: "
"len 0x%04x, expect 0x%04x\n",
__func__, num, sublen, dlen));
errcode = -1;
} else if ((chan != SDPCM_DATA_CHANNEL) &&
(chan != SDPCM_EVENT_CHANNEL)) {
DHD_ERROR(("%s (subframe %d): bad channel %d\n",
__func__, num, chan));
errcode = -1;
} else if ((doff < SDPCM_HDRLEN) || (doff > sublen)) {
DHD_ERROR(("%s (subframe %d): Bad data offset %d: HW %d min %d\n",
__func__, num, doff, sublen,
SDPCM_HDRLEN));
errcode = -1;
}
}
if (errcode) {
if (bus->glomerr++ < 3) {
skb_push(pfirst, sfdoff);
dhdsdio_rxfail(bus, true, true);
} else {
bus->glomerr = 0;
dhdsdio_rxfail(bus, true, false);
dhd_os_sdlock_rxq(bus->dhd);
bcm_pkt_buf_free_skb(bus->glom);
dhd_os_sdunlock_rxq(bus->dhd);
bus->rxglomfail++;
bus->glom = NULL;
}
bus->nextlen = 0;
return 0;
}
save_pfirst = pfirst;
bus->glom = NULL;
plast = NULL;
dhd_os_sdlock_rxq(bus->dhd);
for (num = 0; pfirst; rxseq++, pfirst = pnext) {
pnext = pfirst->next;
pfirst->next = NULL;
dptr = (u8 *) (pfirst->data);
sublen = get_unaligned_le16(dptr);
chan = SDPCM_PACKET_CHANNEL(&dptr[SDPCM_FRAMETAG_LEN]);
seq = SDPCM_PACKET_SEQUENCE(&dptr[SDPCM_FRAMETAG_LEN]);
doff = SDPCM_DOFFSET_VALUE(&dptr[SDPCM_FRAMETAG_LEN]);
DHD_GLOM(("%s: Get subframe %d, %p(%p/%d), sublen %d "
"chan %d seq %d\n",
__func__, num, pfirst, pfirst->data,
pfirst->len, sublen, chan, seq));
ASSERT((chan == SDPCM_DATA_CHANNEL)
|| (chan == SDPCM_EVENT_CHANNEL));
if (rxseq != seq) {
DHD_GLOM(("%s: rx_seq %d, expected %d\n",
__func__, seq, rxseq));
bus->rx_badseq++;
rxseq = seq;
}
#ifdef DHD_DEBUG
if (DHD_BYTES_ON() && DHD_DATA_ON()) {
printk(KERN_DEBUG "Rx Subframe Data:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
dptr, dlen);
}
#endif
__skb_trim(pfirst, sublen);
skb_pull(pfirst, doff);
if (pfirst->len == 0) {
bcm_pkt_buf_free_skb(pfirst);
if (plast) {
plast->next = pnext;
} else {
ASSERT(save_pfirst == pfirst);
save_pfirst = pnext;
}
continue;
} else if (dhd_prot_hdrpull(bus->dhd, &ifidx, pfirst) !=
0) {
DHD_ERROR(("%s: rx protocol error\n",
__func__));
bus->dhd->rx_errors++;
bcm_pkt_buf_free_skb(pfirst);
if (plast) {
plast->next = pnext;
} else {
ASSERT(save_pfirst == pfirst);
save_pfirst = pnext;
}
continue;
}
pfirst->next = pnext;
plast = pfirst;
num++;
#ifdef DHD_DEBUG
if (DHD_GLOM_ON()) {
DHD_GLOM(("%s subframe %d to stack, %p(%p/%d) "
"nxt/lnk %p/%p\n",
__func__, num, pfirst, pfirst->data,
pfirst->len, pfirst->next,
pfirst->prev));
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
pfirst->data,
min_t(int, pfirst->len, 32));
}
#endif
}
dhd_os_sdunlock_rxq(bus->dhd);
if (num) {
dhd_os_sdunlock(bus->dhd);
dhd_rx_frame(bus->dhd, ifidx, save_pfirst, num);
dhd_os_sdlock(bus->dhd);
}
bus->rxglomframes++;
bus->rxglompkts += num;
}
return num;
}
static uint dhdsdio_readframes(dhd_bus_t *bus, uint maxframes, bool *finished)
{
bcmsdh_info_t *sdh = bus->sdh;
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
#if defined(DHD_DEBUG) || defined(SDTEST)
bool sdtest = false;
#endif
DHD_TRACE(("%s: Enter\n", __func__));
ASSERT(maxframes);
#ifdef SDTEST
if (bus->pktgen_count && (bus->pktgen_mode == DHD_PKTGEN_RECV)) {
maxframes = bus->pktgen_count;
sdtest = true;
}
#endif
*finished = false;
for (rxseq = bus->rx_seq, rxleft = maxframes;
!bus->rxskip && rxleft && bus->dhd->busstate != DHD_BUS_DOWN;
rxseq++, rxleft--) {
if (bus->glom || bus->glomd) {
u8 cnt;
DHD_GLOM(("%s: calling rxglom: glomd %p, glom %p\n",
__func__, bus->glomd, bus->glom));
cnt = dhdsdio_rxglom(bus, rxseq);
DHD_GLOM(("%s: rxglom returned %d\n", __func__, cnt));
rxseq += cnt - 1;
rxleft = (rxleft > cnt) ? (rxleft - cnt) : 1;
continue;
}
if (dhd_readahead && bus->nextlen) {
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
} else if (rdlen % DHD_SDALIGN) {
rdlen +=
DHD_SDALIGN - (rdlen % DHD_SDALIGN);
}
}
dhd_os_sdlock_rxq(bus->dhd);
pkt = bcm_pkt_buf_get_skb(rdlen + DHD_SDALIGN);
if (!pkt) {
if (bus->bus == SPI_BUS) {
bus->usebufpool = false;
bus->rxctl = bus->rxbuf;
if (dhd_alignctl) {
bus->rxctl += firstread;
pad = ((unsigned long)bus->rxctl %
DHD_SDALIGN);
if (pad)
bus->rxctl +=
(DHD_SDALIGN - pad);
bus->rxctl -= firstread;
}
ASSERT(bus->rxctl >= bus->rxbuf);
rxbuf = bus->rxctl;
sdret = bcmsdh_recv_buf(bus,
bcmsdh_cur_sbwad(sdh),
SDIO_FUNC_2, F2SYNC,
rxbuf, rdlen,
NULL, NULL, NULL);
bus->f2rxdata++;
ASSERT(sdret != -BCME_PENDING);
if (sdret < 0) {
DHD_ERROR(("%s: read %d control bytes failed: %d\n",
__func__,
rdlen, sdret));
bus->rxc_errors++;
dhd_os_sdunlock_rxq(bus->dhd);
dhdsdio_rxfail(bus, true,
(bus->bus ==
SPI_BUS) ? false
: true);
continue;
}
} else {
DHD_ERROR(("%s (nextlen): "
"bcm_pkt_buf_get_skb failed:"
" len %d rdlen %d expected"
" rxseq %d\n", __func__,
len, rdlen, rxseq));
dhd_os_sdunlock_rxq(bus->dhd);
continue;
}
} else {
if (bus->bus == SPI_BUS)
bus->usebufpool = true;
ASSERT(!(pkt->prev));
PKTALIGN(pkt, rdlen, DHD_SDALIGN);
rxbuf = (u8 *) (pkt->data);
sdret = bcmsdh_recv_buf(bus,
bcmsdh_cur_sbwad(sdh),
SDIO_FUNC_2, F2SYNC,
rxbuf, rdlen,
pkt, NULL, NULL);
bus->f2rxdata++;
ASSERT(sdret != -BCME_PENDING);
if (sdret < 0) {
DHD_ERROR(("%s (nextlen): read %d bytes failed: %d\n",
__func__, rdlen, sdret));
bcm_pkt_buf_free_skb(pkt);
bus->dhd->rx_errors++;
dhd_os_sdunlock_rxq(bus->dhd);
dhdsdio_rxfail(bus, true,
(bus->bus ==
SPI_BUS) ? false :
true);
continue;
}
}
dhd_os_sdunlock_rxq(bus->dhd);
memcpy(bus->rxhdr, rxbuf, SDPCM_HDRLEN);
len = get_unaligned_le16(bus->rxhdr);
check = get_unaligned_le16(bus->rxhdr + sizeof(u16));
if (!(len | check)) {
DHD_INFO(("%s (nextlen): read zeros in HW "
"header???\n", __func__));
dhdsdio_pktfree2(bus, pkt);
continue;
}
if ((u16)~(len ^ check)) {
DHD_ERROR(("%s (nextlen): HW hdr error:"
" nextlen/len/check"
" 0x%04x/0x%04x/0x%04x\n",
__func__, nextlen, len, check));
bus->rx_badhdr++;
dhdsdio_rxfail(bus, false, false);
dhdsdio_pktfree2(bus, pkt);
continue;
}
if (len < SDPCM_HDRLEN) {
DHD_ERROR(("%s (nextlen): HW hdr length "
"invalid: %d\n", __func__, len));
dhdsdio_pktfree2(bus, pkt);
continue;
}
len_consistent = (nextlen != (roundup(len, 16) >> 4));
if (len_consistent) {
DHD_ERROR(("%s (nextlen): mismatch, "
"nextlen %d len %d rnd %d; "
"expected rxseq %d\n",
__func__, nextlen,
len, roundup(len, 16), rxseq));
dhdsdio_rxfail(bus, true, (bus->bus != SPI_BUS));
dhdsdio_pktfree2(bus, pkt);
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
DHD_INFO(("%s (nextlen): got frame w/nextlen too large" " (%d), seq %d\n",
__func__, bus->nextlen, seq));
bus->nextlen = 0;
}
bus->dhd->rx_readahead_cnt++;
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
DHD_INFO(("%s (nextlen): rx_seq %d, expected "
"%d\n", __func__, seq, rxseq));
bus->rx_badseq++;
rxseq = seq;
}
if ((u8) (txmax - bus->tx_seq) > 0x40) {
DHD_ERROR(("%s: got unlikely tx max %d with "
"tx_seq %d\n",
__func__, txmax, bus->tx_seq));
txmax = bus->tx_seq + 2;
}
bus->tx_max = txmax;
#ifdef DHD_DEBUG
if (DHD_BYTES_ON() && DHD_DATA_ON()) {
printk(KERN_DEBUG "Rx Data:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
rxbuf, len);
} else if (DHD_HDRS_ON()) {
printk(KERN_DEBUG "RxHdr:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
bus->rxhdr, SDPCM_HDRLEN);
}
#endif
if (chan == SDPCM_CONTROL_CHANNEL) {
if (bus->bus == SPI_BUS) {
dhdsdio_read_control(bus, rxbuf, len,
doff);
} else {
DHD_ERROR(("%s (nextlen): readahead on control" " packet %d?\n",
__func__, seq));
bus->nextlen = 0;
dhdsdio_rxfail(bus, false, true);
}
dhdsdio_pktfree2(bus, pkt);
continue;
}
if ((bus->bus == SPI_BUS) && !bus->usebufpool) {
DHD_ERROR(("Received %d bytes on %d channel. Running out of " "rx pktbuf's or not yet malloced.\n",
len, chan));
continue;
}
if ((doff < SDPCM_HDRLEN) || (doff > len)) {
DHD_ERROR(("%s (nextlen): bad data offset %d: HW len %d min %d\n",
__func__, doff, len, SDPCM_HDRLEN));
dhdsdio_rxfail(bus, false, false);
dhdsdio_pktfree2(bus, pkt);
continue;
}
goto deliver;
}
if (bus->bus == SPI_BUS)
break;
sdret = bcmsdh_recv_buf(bus, bcmsdh_cur_sbwad(sdh),
SDIO_FUNC_2, F2SYNC, bus->rxhdr, firstread,
NULL, NULL, NULL);
bus->f2rxhdrs++;
ASSERT(sdret != -BCME_PENDING);
if (sdret < 0) {
DHD_ERROR(("%s: RXHEADER FAILED: %d\n", __func__,
sdret));
bus->rx_hdrfail++;
dhdsdio_rxfail(bus, true, true);
continue;
}
#ifdef DHD_DEBUG
if (DHD_BYTES_ON() || DHD_HDRS_ON()) {
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
DHD_ERROR(("%s: HW hdr err: len/check 0x%04x/0x%04x\n",
__func__, len, check));
bus->rx_badhdr++;
dhdsdio_rxfail(bus, false, false);
continue;
}
if (len < SDPCM_HDRLEN) {
DHD_ERROR(("%s: HW hdr length invalid: %d\n",
__func__, len));
continue;
}
chan = SDPCM_PACKET_CHANNEL(&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
seq = SDPCM_PACKET_SEQUENCE(&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
doff = SDPCM_DOFFSET_VALUE(&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
txmax = SDPCM_WINDOW_VALUE(&bus->rxhdr[SDPCM_FRAMETAG_LEN]);
if ((doff < SDPCM_HDRLEN) || (doff > len)) {
DHD_ERROR(("%s: Bad data offset %d: HW len %d, min %d "
"seq %d\n",
__func__, doff, len, SDPCM_HDRLEN, seq));
bus->rx_badhdr++;
ASSERT(0);
dhdsdio_rxfail(bus, false, false);
continue;
}
bus->nextlen =
bus->rxhdr[SDPCM_FRAMETAG_LEN + SDPCM_NEXTLEN_OFFSET];
if ((bus->nextlen << 4) > MAX_RX_DATASZ) {
DHD_INFO(("%s (nextlen): got frame w/nextlen too large "
"(%d), seq %d\n",
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
DHD_INFO(("%s: rx_seq %d, expected %d\n", __func__,
seq, rxseq));
bus->rx_badseq++;
rxseq = seq;
}
if ((u8) (txmax - bus->tx_seq) > 0x40) {
DHD_ERROR(("%s: unlikely tx max %d with tx_seq %d\n",
__func__, txmax, bus->tx_seq));
txmax = bus->tx_seq + 2;
}
bus->tx_max = txmax;
if (chan == SDPCM_CONTROL_CHANNEL) {
dhdsdio_read_control(bus, bus->rxhdr, len, doff);
continue;
}
ASSERT((chan == SDPCM_DATA_CHANNEL)
|| (chan == SDPCM_EVENT_CHANNEL)
|| (chan == SDPCM_TEST_CHANNEL)
|| (chan == SDPCM_GLOM_CHANNEL));
rdlen = (len > firstread) ? (len - firstread) : 0;
if (bus->roundup && bus->blocksize &&
(rdlen > bus->blocksize)) {
pad = bus->blocksize - (rdlen % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize) &&
((rdlen + pad + firstread) < MAX_RX_DATASZ))
rdlen += pad;
} else if (rdlen % DHD_SDALIGN) {
rdlen += DHD_SDALIGN - (rdlen % DHD_SDALIGN);
}
if (forcealign && (rdlen & (ALIGNMENT - 1)))
rdlen = roundup(rdlen, ALIGNMENT);
if ((rdlen + firstread) > MAX_RX_DATASZ) {
DHD_ERROR(("%s: too long: len %d rdlen %d\n",
__func__, len, rdlen));
bus->dhd->rx_errors++;
bus->rx_toolong++;
dhdsdio_rxfail(bus, false, false);
continue;
}
dhd_os_sdlock_rxq(bus->dhd);
pkt = bcm_pkt_buf_get_skb(rdlen + firstread + DHD_SDALIGN);
if (!pkt) {
DHD_ERROR(("%s: bcm_pkt_buf_get_skb failed: rdlen %d "
"chan %d\n", __func__, rdlen, chan));
bus->dhd->rx_dropped++;
dhd_os_sdunlock_rxq(bus->dhd);
dhdsdio_rxfail(bus, false, RETRYCHAN(chan));
continue;
}
dhd_os_sdunlock_rxq(bus->dhd);
ASSERT(!(pkt->prev));
ASSERT(firstread < pkt->len);
skb_pull(pkt, firstread);
PKTALIGN(pkt, rdlen, DHD_SDALIGN);
sdret = bcmsdh_recv_buf(bus, bcmsdh_cur_sbwad(sdh), SDIO_FUNC_2,
F2SYNC, ((u8 *) (pkt->data)), rdlen,
pkt, NULL, NULL);
bus->f2rxdata++;
ASSERT(sdret != -BCME_PENDING);
if (sdret < 0) {
DHD_ERROR(("%s: read %d %s bytes failed: %d\n",
__func__, rdlen,
((chan ==
SDPCM_EVENT_CHANNEL) ? "event" : ((chan ==
SDPCM_DATA_CHANNEL)
? "data" : "test")),
sdret));
dhd_os_sdlock_rxq(bus->dhd);
bcm_pkt_buf_free_skb(pkt);
dhd_os_sdunlock_rxq(bus->dhd);
bus->dhd->rx_errors++;
dhdsdio_rxfail(bus, true, RETRYCHAN(chan));
continue;
}
skb_push(pkt, firstread);
memcpy(pkt->data, bus->rxhdr, firstread);
#ifdef DHD_DEBUG
if (DHD_BYTES_ON() && DHD_DATA_ON()) {
printk(KERN_DEBUG "Rx Data:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET,
pkt->data, len);
}
#endif
deliver:
if (chan == SDPCM_GLOM_CHANNEL) {
if (SDPCM_GLOMDESC(&bus->rxhdr[SDPCM_FRAMETAG_LEN])) {
DHD_GLOM(("%s: glom descriptor, %d bytes:\n",
__func__, len));
#ifdef DHD_DEBUG
if (DHD_GLOM_ON()) {
printk(KERN_DEBUG "Glom Data:\n");
print_hex_dump_bytes("",
DUMP_PREFIX_OFFSET,
pkt->data, len);
}
#endif
__skb_trim(pkt, len);
ASSERT(doff == SDPCM_HDRLEN);
skb_pull(pkt, SDPCM_HDRLEN);
bus->glomd = pkt;
} else {
DHD_ERROR(("%s: glom superframe w/o "
"descriptor!\n", __func__));
dhdsdio_rxfail(bus, false, false);
}
continue;
}
__skb_trim(pkt, len);
skb_pull(pkt, doff);
#ifdef SDTEST
if (chan == SDPCM_TEST_CHANNEL) {
dhdsdio_testrcv(bus, pkt, seq);
continue;
}
#endif
if (pkt->len == 0) {
dhd_os_sdlock_rxq(bus->dhd);
bcm_pkt_buf_free_skb(pkt);
dhd_os_sdunlock_rxq(bus->dhd);
continue;
} else if (dhd_prot_hdrpull(bus->dhd, &ifidx, pkt) != 0) {
DHD_ERROR(("%s: rx protocol error\n", __func__));
dhd_os_sdlock_rxq(bus->dhd);
bcm_pkt_buf_free_skb(pkt);
dhd_os_sdunlock_rxq(bus->dhd);
bus->dhd->rx_errors++;
continue;
}
dhd_os_sdunlock(bus->dhd);
dhd_rx_frame(bus->dhd, ifidx, pkt, 1);
dhd_os_sdlock(bus->dhd);
}
rxcount = maxframes - rxleft;
#ifdef DHD_DEBUG
if (!rxleft && !sdtest)
DHD_DATA(("%s: hit rx limit of %d frames\n", __func__,
maxframes));
else
#endif
DHD_DATA(("%s: processed %d frames\n", __func__, rxcount));
if (bus->rxskip)
rxseq--;
bus->rx_seq = rxseq;
return rxcount;
}
static u32 dhdsdio_hostmail(dhd_bus_t *bus)
{
sdpcmd_regs_t *regs = bus->regs;
u32 intstatus = 0;
u32 hmb_data;
u8 fcbits;
uint retries = 0;
DHD_TRACE(("%s: Enter\n", __func__));
R_SDREG(hmb_data, &regs->tohostmailboxdata, retries);
if (retries <= retry_limit)
W_SDREG(SMB_INT_ACK, &regs->tosbmailbox, retries);
bus->f1regdata += 2;
if (hmb_data & HMB_DATA_NAKHANDLED) {
DHD_INFO(("Dongle reports NAK handled, expect rtx of %d\n",
bus->rx_seq));
if (!bus->rxskip)
DHD_ERROR(("%s: unexpected NAKHANDLED!\n", __func__));
bus->rxskip = false;
intstatus |= I_HMB_FRAME_IND;
}
if (hmb_data & (HMB_DATA_DEVREADY | HMB_DATA_FWREADY)) {
bus->sdpcm_ver =
(hmb_data & HMB_DATA_VERSION_MASK) >>
HMB_DATA_VERSION_SHIFT;
if (bus->sdpcm_ver != SDPCM_PROT_VERSION)
DHD_ERROR(("Version mismatch, dongle reports %d, "
"expecting %d\n",
bus->sdpcm_ver, SDPCM_PROT_VERSION));
else
DHD_INFO(("Dongle ready, protocol version %d\n",
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
DHD_ERROR(("Unknown mailbox data content: 0x%02x\n", hmb_data));
}
return intstatus;
}
bool dhdsdio_dpc(dhd_bus_t *bus)
{
bcmsdh_info_t *sdh = bus->sdh;
sdpcmd_regs_t *regs = bus->regs;
u32 intstatus, newstatus = 0;
uint retries = 0;
uint rxlimit = dhd_rxbound;
uint txlimit = dhd_txbound;
uint framecnt = 0;
bool rxdone = true;
bool resched = false;
DHD_TRACE(("%s: Enter\n", __func__));
intstatus = bus->intstatus;
dhd_os_sdlock(bus->dhd);
if (bus->clkstate == CLK_PENDING) {
int err;
u8 clkctl, devctl = 0;
#ifdef DHD_DEBUG
devctl =
bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL, &err);
if (err) {
DHD_ERROR(("%s: error reading DEVCTL: %d\n",
__func__, err));
bus->dhd->busstate = DHD_BUS_DOWN;
} else {
ASSERT(devctl & SBSDIO_DEVCTL_CA_INT_ONLY);
}
#endif
clkctl =
bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
&err);
if (err) {
DHD_ERROR(("%s: error reading CSR: %d\n", __func__,
err));
bus->dhd->busstate = DHD_BUS_DOWN;
}
DHD_INFO(("DPC: PENDING, devctl 0x%02x clkctl 0x%02x\n", devctl,
clkctl));
if (SBSDIO_HTAV(clkctl)) {
devctl =
bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL,
&err);
if (err) {
DHD_ERROR(("%s: error reading DEVCTL: %d\n",
__func__, err));
bus->dhd->busstate = DHD_BUS_DOWN;
}
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_DEVICE_CTL,
devctl, &err);
if (err) {
DHD_ERROR(("%s: error writing DEVCTL: %d\n",
__func__, err));
bus->dhd->busstate = DHD_BUS_DOWN;
}
bus->clkstate = CLK_AVAIL;
} else {
goto clkwait;
}
}
BUS_WAKE(bus);
dhdsdio_clkctl(bus, CLK_AVAIL, true);
if (bus->clkstate == CLK_PENDING)
goto clkwait;
if (bus->ipend) {
bus->ipend = false;
R_SDREG(newstatus, &regs->intstatus, retries);
bus->f1regdata++;
if (bcmsdh_regfail(bus->sdh))
newstatus = 0;
newstatus &= bus->hostintmask;
bus->fcstate = !!(newstatus & I_HMB_FC_STATE);
if (newstatus) {
W_SDREG(newstatus, &regs->intstatus, retries);
bus->f1regdata++;
}
}
intstatus |= newstatus;
bus->intstatus = 0;
if (intstatus & I_HMB_FC_CHANGE) {
intstatus &= ~I_HMB_FC_CHANGE;
W_SDREG(I_HMB_FC_CHANGE, &regs->intstatus, retries);
R_SDREG(newstatus, &regs->intstatus, retries);
bus->f1regdata += 2;
bus->fcstate =
!!(newstatus & (I_HMB_FC_STATE | I_HMB_FC_CHANGE));
intstatus |= (newstatus & bus->hostintmask);
}
if (intstatus & I_HMB_HOST_INT) {
intstatus &= ~I_HMB_HOST_INT;
intstatus |= dhdsdio_hostmail(bus);
}
if (intstatus & I_WR_OOSYNC) {
DHD_ERROR(("Dongle reports WR_OOSYNC\n"));
intstatus &= ~I_WR_OOSYNC;
}
if (intstatus & I_RD_OOSYNC) {
DHD_ERROR(("Dongle reports RD_OOSYNC\n"));
intstatus &= ~I_RD_OOSYNC;
}
if (intstatus & I_SBINT) {
DHD_ERROR(("Dongle reports SBINT\n"));
intstatus &= ~I_SBINT;
}
if (intstatus & I_CHIPACTIVE) {
DHD_INFO(("Dongle reports CHIPACTIVE\n"));
intstatus &= ~I_CHIPACTIVE;
}
if (bus->rxskip)
intstatus &= ~I_HMB_FRAME_IND;
if (PKT_AVAILABLE()) {
framecnt = dhdsdio_readframes(bus, rxlimit, &rxdone);
if (rxdone || bus->rxskip)
intstatus &= ~I_HMB_FRAME_IND;
rxlimit -= min(framecnt, rxlimit);
}
bus->intstatus = intstatus;
clkwait:
#if defined(OOB_INTR_ONLY)
bcmsdh_oob_intr_set(1);
#endif
if (bus->intr && bus->intdis && !bcmsdh_regfail(sdh)) {
DHD_INTR(("%s: enable SDIO interrupts, rxdone %d framecnt %d\n",
__func__, rxdone, framecnt));
bus->intdis = false;
bcmsdh_intr_enable(sdh);
}
if (DATAOK(bus) && bus->ctrl_frame_stat &&
(bus->clkstate == CLK_AVAIL)) {
int ret, i;
ret =
dhd_bcmsdh_send_buf(bus, bcmsdh_cur_sbwad(sdh), SDIO_FUNC_2,
F2SYNC, (u8 *) bus->ctrl_frame_buf,
(u32) bus->ctrl_frame_len, NULL,
NULL, NULL);
ASSERT(ret != -BCME_PENDING);
if (ret < 0) {
DHD_INFO(("%s: sdio error %d, abort command and "
"terminate frame.\n", __func__, ret));
bus->tx_sderrs++;
bcmsdh_abort(sdh, SDIO_FUNC_2);
bcmsdh_cfg_write(sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_FRAMECTRL, SFC_WF_TERM,
NULL);
bus->f1regdata++;
for (i = 0; i < 3; i++) {
u8 hi, lo;
hi = bcmsdh_cfg_read(sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCHI,
NULL);
lo = bcmsdh_cfg_read(sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_WFRAMEBCLO,
NULL);
bus->f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
}
}
if (ret == 0)
bus->tx_seq = (bus->tx_seq + 1) % SDPCM_SEQUENCE_WRAP;
DHD_INFO(("Return_dpc value is : %d\n", ret));
bus->ctrl_frame_stat = false;
dhd_wait_event_wakeup(bus->dhd);
}
else if ((bus->clkstate == CLK_AVAIL) && !bus->fcstate &&
bcm_pktq_mlen(&bus->txq, ~bus->flowcontrol) && txlimit
&& DATAOK(bus)) {
framecnt = rxdone ? txlimit : min(txlimit, dhd_txminmax);
framecnt = dhdsdio_sendfromq(bus, framecnt);
txlimit -= framecnt;
}
if ((bus->dhd->busstate == DHD_BUS_DOWN) || bcmsdh_regfail(sdh)) {
DHD_ERROR(("%s: failed backplane access over SDIO, halting "
"operation %d\n", __func__, bcmsdh_regfail(sdh)));
bus->dhd->busstate = DHD_BUS_DOWN;
bus->intstatus = 0;
} else if (bus->clkstate == CLK_PENDING) {
DHD_INFO(("%s: rescheduled due to CLK_PENDING awaiting "
"I_CHIPACTIVE interrupt\n", __func__));
resched = true;
} else if (bus->intstatus || bus->ipend ||
(!bus->fcstate && bcm_pktq_mlen(&bus->txq, ~bus->flowcontrol) &&
DATAOK(bus)) || PKT_AVAILABLE()) {
resched = true;
}
bus->dpc_sched = resched;
if ((bus->clkstate != CLK_PENDING)
&& bus->idletime == DHD_IDLE_IMMEDIATE) {
bus->activity = false;
dhdsdio_clkctl(bus, CLK_NONE, false);
}
dhd_os_sdunlock(bus->dhd);
return resched;
}
bool dhd_bus_dpc(struct dhd_bus *bus)
{
bool resched;
DHD_TRACE(("Calling dhdsdio_dpc() from %s\n", __func__));
resched = dhdsdio_dpc(bus);
return resched;
}
void dhdsdio_isr(void *arg)
{
dhd_bus_t *bus = (dhd_bus_t *) arg;
bcmsdh_info_t *sdh;
DHD_TRACE(("%s: Enter\n", __func__));
if (!bus) {
DHD_ERROR(("%s : bus is null pointer , exit\n", __func__));
return;
}
sdh = bus->sdh;
if (bus->dhd->busstate == DHD_BUS_DOWN) {
DHD_ERROR(("%s : bus is down. we have nothing to do\n",
__func__));
return;
}
bus->intrcount++;
bus->ipend = true;
if (bus->sleeping) {
DHD_ERROR(("INTERRUPT WHILE SLEEPING??\n"));
return;
}
if (bus->intr)
DHD_INTR(("%s: disable SDIO interrupts\n", __func__));
else
DHD_ERROR(("dhdsdio_isr() w/o interrupt configured!\n"));
bcmsdh_intr_disable(sdh);
bus->intdis = true;
#if defined(SDIO_ISR_THREAD)
DHD_TRACE(("Calling dhdsdio_dpc() from %s\n", __func__));
while (dhdsdio_dpc(bus))
;
#else
bus->dpc_sched = true;
dhd_sched_dpc(bus->dhd);
#endif
}
static void dhdsdio_pktgen_init(dhd_bus_t *bus)
{
if (dhd_pktgen_len) {
bus->pktgen_maxlen = min(dhd_pktgen_len, MAX_PKTGEN_LEN);
bus->pktgen_minlen = bus->pktgen_maxlen;
} else {
bus->pktgen_maxlen = MAX_PKTGEN_LEN;
bus->pktgen_minlen = 0;
}
bus->pktgen_len = (u16) bus->pktgen_minlen;
bus->pktgen_freq = 1;
bus->pktgen_print = 10000 / dhd_watchdog_ms;
bus->pktgen_count = (dhd_pktgen * dhd_watchdog_ms + 999) / 1000;
bus->pktgen_mode = DHD_PKTGEN_ECHO;
bus->pktgen_stop = 1;
}
static void dhdsdio_pktgen(dhd_bus_t *bus)
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
if (bus->pktgen_mode == DHD_PKTGEN_RECV) {
if (!bus->pktgen_rcvd)
dhdsdio_sdtest_set(bus, true);
return;
}
for (pktcount = 0; pktcount < bus->pktgen_count; pktcount++) {
if (bus->pktgen_total
&& (bus->pktgen_sent >= bus->pktgen_total)) {
bus->pktgen_count = 0;
break;
}
len = bus->pktgen_len;
pkt = bcm_pkt_buf_get_skb(
(len + SDPCM_HDRLEN + SDPCM_TEST_HDRLEN + DHD_SDALIGN),
true);
if (!pkt) {
DHD_ERROR(("%s: bcm_pkt_buf_get_skb failed!\n",
__func__));
break;
}
PKTALIGN(pkt, (len + SDPCM_HDRLEN + SDPCM_TEST_HDRLEN),
DHD_SDALIGN);
data = (u8 *) (pkt->data) + SDPCM_HDRLEN;
switch (bus->pktgen_mode) {
case DHD_PKTGEN_ECHO:
*data++ = SDPCM_TEST_ECHOREQ;
*data++ = (u8) bus->pktgen_sent;
break;
case DHD_PKTGEN_SEND:
*data++ = SDPCM_TEST_DISCARD;
*data++ = (u8) bus->pktgen_sent;
break;
case DHD_PKTGEN_RXBURST:
*data++ = SDPCM_TEST_BURST;
*data++ = (u8) bus->pktgen_count;
break;
default:
DHD_ERROR(("Unrecognized pktgen mode %d\n",
bus->pktgen_mode));
bcm_pkt_buf_free_skb(pkt, true);
bus->pktgen_count = 0;
return;
}
*data++ = (len >> 0);
*data++ = (len >> 8);
for (fillbyte = 0; fillbyte < len; fillbyte++)
*data++ =
SDPCM_TEST_FILL(fillbyte, (u8) bus->pktgen_sent);
#ifdef DHD_DEBUG
if (DHD_BYTES_ON() && DHD_DATA_ON()) {
data = (u8 *) (pkt->data) + SDPCM_HDRLEN;
printk(KERN_DEBUG "dhdsdio_pktgen: Tx Data:\n");
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, data,
pkt->len - SDPCM_HDRLEN);
}
#endif
if (dhdsdio_txpkt(bus, pkt, SDPCM_TEST_CHANNEL, true)) {
bus->pktgen_fail++;
if (bus->pktgen_stop
&& bus->pktgen_stop == bus->pktgen_fail)
bus->pktgen_count = 0;
}
bus->pktgen_sent++;
if (++bus->pktgen_len > bus->pktgen_maxlen)
bus->pktgen_len = (u16) bus->pktgen_minlen;
if (bus->pktgen_mode == DHD_PKTGEN_RXBURST)
break;
}
}
static void dhdsdio_sdtest_set(dhd_bus_t *bus, bool start)
{
struct sk_buff *pkt;
u8 *data;
pkt = bcm_pkt_buf_get_skb(SDPCM_HDRLEN + SDPCM_TEST_HDRLEN +
DHD_SDALIGN, true);
if (!pkt) {
DHD_ERROR(("%s: bcm_pkt_buf_get_skb failed!\n", __func__));
return;
}
PKTALIGN(pkt, (SDPCM_HDRLEN + SDPCM_TEST_HDRLEN), DHD_SDALIGN);
data = (u8 *) (pkt->data) + SDPCM_HDRLEN;
*data++ = SDPCM_TEST_SEND;
*data++ = start;
*data++ = (bus->pktgen_maxlen >> 0);
*data++ = (bus->pktgen_maxlen >> 8);
if (dhdsdio_txpkt(bus, pkt, SDPCM_TEST_CHANNEL, true))
bus->pktgen_fail++;
}
static void dhdsdio_testrcv(dhd_bus_t *bus, struct sk_buff *pkt, uint seq)
{
u8 *data;
uint pktlen;
u8 cmd;
u8 extra;
u16 len;
u16 offset;
pktlen = pkt->len;
if (pktlen < SDPCM_TEST_HDRLEN) {
DHD_ERROR(("dhdsdio_restrcv: toss runt frame, pktlen %d\n",
pktlen));
bcm_pkt_buf_free_skb(pkt, false);
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
DHD_ERROR(("dhdsdio_testrcv: frame length mismatch, "
"pktlen %d seq %d" " cmd %d extra %d len %d\n",
pktlen, seq, cmd, extra, len));
bcm_pkt_buf_free_skb(pkt, false);
return;
}
}
switch (cmd) {
case SDPCM_TEST_ECHOREQ:
*(u8 *) (pkt->data) = SDPCM_TEST_ECHORSP;
if (dhdsdio_txpkt(bus, pkt, SDPCM_TEST_CHANNEL, true) == 0) {
bus->pktgen_sent++;
} else {
bus->pktgen_fail++;
bcm_pkt_buf_free_skb(pkt, false);
}
bus->pktgen_rcvd++;
break;
case SDPCM_TEST_ECHORSP:
if (bus->ext_loop) {
bcm_pkt_buf_free_skb(pkt, false);
bus->pktgen_rcvd++;
break;
}
for (offset = 0; offset < len; offset++, data++) {
if (*data != SDPCM_TEST_FILL(offset, extra)) {
DHD_ERROR(("dhdsdio_testrcv: echo data mismatch: " "offset %d (len %d) expect 0x%02x rcvd 0x%02x\n",
offset, len,
SDPCM_TEST_FILL(offset, extra), *data));
break;
}
}
bcm_pkt_buf_free_skb(pkt, false);
bus->pktgen_rcvd++;
break;
case SDPCM_TEST_DISCARD:
bcm_pkt_buf_free_skb(pkt, false);
bus->pktgen_rcvd++;
break;
case SDPCM_TEST_BURST:
case SDPCM_TEST_SEND:
default:
DHD_INFO(("dhdsdio_testrcv: unsupported or unknown command, "
"pktlen %d seq %d" " cmd %d extra %d len %d\n",
pktlen, seq, cmd, extra, len));
bcm_pkt_buf_free_skb(pkt, false);
break;
}
if (bus->pktgen_mode == DHD_PKTGEN_RECV) {
if (bus->pktgen_total
&& (bus->pktgen_rcvd >= bus->pktgen_total)) {
bus->pktgen_count = 0;
dhdsdio_sdtest_set(bus, false);
}
}
}
extern bool dhd_bus_watchdog(dhd_pub_t *dhdp)
{
dhd_bus_t *bus;
DHD_TIMER(("%s: Enter\n", __func__));
bus = dhdp->bus;
if (bus->dhd->dongle_reset)
return false;
if (bus->sleeping)
return false;
dhd_os_sdlock(bus->dhd);
if (bus->poll && (++bus->polltick >= bus->pollrate)) {
u32 intstatus = 0;
bus->polltick = 0;
if (!bus->intr || (bus->intrcount == bus->lastintrs)) {
if (!bus->dpc_sched) {
u8 devpend;
devpend = bcmsdh_cfg_read(bus->sdh, SDIO_FUNC_0,
SDIOD_CCCR_INTPEND,
NULL);
intstatus =
devpend & (INTR_STATUS_FUNC1 |
INTR_STATUS_FUNC2);
}
if (intstatus) {
bus->pollcnt++;
bus->ipend = true;
if (bus->intr)
bcmsdh_intr_disable(bus->sdh);
bus->dpc_sched = true;
dhd_sched_dpc(bus->dhd);
}
}
bus->lastintrs = bus->intrcount;
}
#ifdef DHD_DEBUG
if (dhdp->busstate == DHD_BUS_DATA && dhd_console_ms != 0) {
bus->console.count += dhd_watchdog_ms;
if (bus->console.count >= dhd_console_ms) {
bus->console.count -= dhd_console_ms;
dhdsdio_clkctl(bus, CLK_AVAIL, false);
if (dhdsdio_readconsole(bus) < 0)
dhd_console_ms = 0;
}
}
#endif
#ifdef SDTEST
if (bus->pktgen_count && (++bus->pktgen_tick >= bus->pktgen_freq)) {
dhdsdio_clkctl(bus, CLK_AVAIL, false);
bus->pktgen_tick = 0;
dhdsdio_pktgen(bus);
}
#endif
if ((bus->idletime > 0) && (bus->clkstate == CLK_AVAIL)) {
if (++bus->idlecount >= bus->idletime) {
bus->idlecount = 0;
if (bus->activity) {
bus->activity = false;
dhd_os_wd_timer(bus->dhd, dhd_watchdog_ms);
} else {
dhdsdio_clkctl(bus, CLK_NONE, false);
}
}
}
dhd_os_sdunlock(bus->dhd);
return bus->ipend;
}
extern int dhd_bus_console_in(dhd_pub_t *dhdp, unsigned char *msg, uint msglen)
{
dhd_bus_t *bus = dhdp->bus;
u32 addr, val;
int rv;
struct sk_buff *pkt;
if (bus->console_addr == 0)
return -ENOTSUPP;
dhd_os_sdlock(bus->dhd);
if (bus->dhd->dongle_reset) {
dhd_os_sdunlock(bus->dhd);
return -EPERM;
}
BUS_WAKE(bus);
dhdsdio_clkctl(bus, CLK_AVAIL, false);
addr = bus->console_addr + offsetof(hndrte_cons_t, cbuf_idx);
val = cpu_to_le32(0);
rv = dhdsdio_membytes(bus, true, addr, (u8 *)&val, sizeof(val));
if (rv < 0)
goto done;
addr = bus->console_addr + offsetof(hndrte_cons_t, cbuf);
rv = dhdsdio_membytes(bus, true, addr, (u8 *)msg, msglen);
if (rv < 0)
goto done;
addr = bus->console_addr + offsetof(hndrte_cons_t, vcons_in);
val = cpu_to_le32(msglen);
rv = dhdsdio_membytes(bus, true, addr, (u8 *)&val, sizeof(val));
if (rv < 0)
goto done;
pkt = bcm_pkt_buf_get_skb(4 + SDPCM_RESERVE);
if ((pkt != NULL) && bus->clkstate == CLK_AVAIL)
dhdsdio_txpkt(bus, pkt, SDPCM_EVENT_CHANNEL, true);
done:
if ((bus->idletime == DHD_IDLE_IMMEDIATE) && !bus->dpc_sched) {
bus->activity = false;
dhdsdio_clkctl(bus, CLK_NONE, true);
}
dhd_os_sdunlock(bus->dhd);
return rv;
}
static void dhd_dump_cis(uint fn, u8 *cis)
{
uint byte, tag, tdata;
DHD_INFO(("Function %d CIS:\n", fn));
for (tdata = byte = 0; byte < SBSDIO_CIS_SIZE_LIMIT; byte++) {
if ((byte % 16) == 0)
DHD_INFO((" "));
DHD_INFO(("%02x ", cis[byte]));
if ((byte % 16) == 15)
DHD_INFO(("\n"));
if (!tdata--) {
tag = cis[byte];
if (tag == 0xff)
break;
else if (!tag)
tdata = 0;
else if ((byte + 1) < SBSDIO_CIS_SIZE_LIMIT)
tdata = cis[byte + 1] + 1;
else
DHD_INFO(("]"));
}
}
if ((byte % 16) != 15)
DHD_INFO(("\n"));
}
static bool dhdsdio_chipmatch(u16 chipid)
{
if (chipid == BCM4325_CHIP_ID)
return true;
if (chipid == BCM4329_CHIP_ID)
return true;
if (chipid == BCM4319_CHIP_ID)
return true;
return false;
}
static void *dhdsdio_probe(u16 venid, u16 devid, u16 bus_no,
u16 slot, u16 func, uint bustype, void *regsva,
void *sdh)
{
int ret;
dhd_bus_t *bus;
dhd_txbound = DHD_TXBOUND;
dhd_rxbound = DHD_RXBOUND;
dhd_alignctl = true;
sd1idle = true;
dhd_readahead = true;
retrydata = false;
dhd_dongle_memsize = 0;
dhd_txminmax = DHD_TXMINMAX;
forcealign = true;
dhd_common_init();
DHD_TRACE(("%s: Enter\n", __func__));
DHD_INFO(("%s: venid 0x%04x devid 0x%04x\n", __func__, venid, devid));
ASSERT((unsigned long)regsva == SI_ENUM_BASE);
switch (venid) {
case 0x0000:
case PCI_VENDOR_ID_BROADCOM:
break;
default:
DHD_ERROR(("%s: unknown vendor: 0x%04x\n", __func__, venid));
return NULL;
}
switch (devid) {
case BCM4325_D11DUAL_ID:
case BCM4325_D11G_ID:
case BCM4325_D11A_ID:
DHD_INFO(("%s: found 4325 Dongle\n", __func__));
break;
case BCM4329_D11NDUAL_ID:
case BCM4329_D11N2G_ID:
case BCM4329_D11N5G_ID:
case 0x4329:
DHD_INFO(("%s: found 4329 Dongle\n", __func__));
break;
case BCM4319_D11N_ID:
case BCM4319_D11N2G_ID:
case BCM4319_D11N5G_ID:
DHD_INFO(("%s: found 4319 Dongle\n", __func__));
break;
case 0:
DHD_INFO(("%s: allow device id 0, will check chip internals\n",
__func__));
break;
default:
DHD_ERROR(("%s: skipping 0x%04x/0x%04x, not a dongle\n",
__func__, venid, devid));
return NULL;
}
bus = kzalloc(sizeof(dhd_bus_t), GFP_ATOMIC);
if (!bus) {
DHD_ERROR(("%s: kmalloc of dhd_bus_t failed\n", __func__));
goto fail;
}
bus->sdh = sdh;
bus->cl_devid = (u16) devid;
bus->bus = DHD_BUS;
bus->tx_seq = SDPCM_SEQUENCE_WRAP - 1;
bus->usebufpool = false;
if (!(dhdsdio_probe_attach(bus, sdh, regsva, devid))) {
DHD_ERROR(("%s: dhdsdio_probe_attach failed\n", __func__));
goto fail;
}
bus->dhd = dhd_attach(bus, SDPCM_RESERVE);
if (!bus->dhd) {
DHD_ERROR(("%s: dhd_attach failed\n", __func__));
goto fail;
}
if (!(dhdsdio_probe_malloc(bus, sdh))) {
DHD_ERROR(("%s: dhdsdio_probe_malloc failed\n", __func__));
goto fail;
}
if (!(dhdsdio_probe_init(bus, sdh))) {
DHD_ERROR(("%s: dhdsdio_probe_init failed\n", __func__));
goto fail;
}
DHD_INTR(("%s: disable SDIO interrupts (not interested yet)\n",
__func__));
bcmsdh_intr_disable(sdh);
ret = bcmsdh_intr_reg(sdh, dhdsdio_isr, bus);
if (ret != 0) {
DHD_ERROR(("%s: FAILED: bcmsdh_intr_reg returned %d\n",
__func__, ret));
goto fail;
}
DHD_INTR(("%s: registered SDIO interrupt function ok\n", __func__));
DHD_INFO(("%s: completed!!\n", __func__));
ret = dhd_bus_start(bus->dhd);
if (ret != 0) {
if (ret == -ENOLINK) {
DHD_ERROR(("%s: dongle is not responding\n", __func__));
goto fail;
}
}
if (dhd_net_attach(bus->dhd, 0) != 0) {
DHD_ERROR(("%s: Net attach failed!!\n", __func__));
goto fail;
}
return bus;
fail:
dhdsdio_release(bus);
return NULL;
}
static bool
dhdsdio_probe_attach(struct dhd_bus *bus, void *sdh, void *regsva, u16 devid)
{
u8 clkctl = 0;
int err = 0;
bus->alp_only = true;
if (dhdsdio_set_siaddr_window(bus, SI_ENUM_BASE))
DHD_ERROR(("%s: FAILED to return to SI_ENUM_BASE\n", __func__));
#ifdef DHD_DEBUG
printk(KERN_DEBUG "F1 signature read @0x18000000=0x%4x\n",
bcmsdh_reg_read(bus->sdh, SI_ENUM_BASE, 4));
#endif
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
DHD_INIT_CLKCTL1, &err);
if (!err)
clkctl =
bcmsdh_cfg_read(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
&err);
if (err || ((clkctl & ~SBSDIO_AVBITS) != DHD_INIT_CLKCTL1)) {
DHD_ERROR(("dhdsdio_probe: ChipClkCSR access: err %d wrote "
"0x%02x read 0x%02x\n",
err, DHD_INIT_CLKCTL1, clkctl));
goto fail;
}
#ifdef DHD_DEBUG
if (DHD_INFO_ON()) {
uint fn, numfn;
u8 *cis[SDIOD_MAX_IOFUNCS];
int err = 0;
numfn = bcmsdh_query_iofnum(sdh);
ASSERT(numfn <= SDIOD_MAX_IOFUNCS);
SPINWAIT(((clkctl = bcmsdh_cfg_read(sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
NULL)),
!SBSDIO_ALPAV(clkctl)), PMU_MAX_TRANSITION_DLY);
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
DHD_INIT_CLKCTL2, &err);
udelay(65);
for (fn = 0; fn <= numfn; fn++) {
cis[fn] = kzalloc(SBSDIO_CIS_SIZE_LIMIT, GFP_ATOMIC);
if (!cis[fn]) {
DHD_INFO(("dhdsdio_probe: fn %d cis malloc "
"failed\n", fn));
break;
}
err = bcmsdh_cis_read(sdh, fn, cis[fn],
SBSDIO_CIS_SIZE_LIMIT);
if (err) {
DHD_INFO(("dhdsdio_probe: fn %d cis read "
"err %d\n", fn, err));
kfree(cis[fn]);
break;
}
dhd_dump_cis(fn, cis[fn]);
}
while (fn-- > 0) {
ASSERT(cis[fn]);
kfree(cis[fn]);
}
if (err) {
DHD_ERROR(("dhdsdio_probe: error read/parsing CIS\n"));
goto fail;
}
}
#endif
if (dhdsdio_chip_attach(bus, regsva)) {
DHD_ERROR(("%s: dhdsdio_chip_attach failed!\n", __func__));
goto fail;
}
bcmsdh_chipinfo(sdh, bus->ci->chip, bus->ci->chiprev);
if (!dhdsdio_chipmatch((u16) bus->ci->chip)) {
DHD_ERROR(("%s: unsupported chip: 0x%04x\n",
__func__, bus->ci->chip));
goto fail;
}
dhdsdio_sdiod_drive_strength_init(bus, dhd_sdiod_drive_strength);
if (!DHD_NOPMU(bus)) {
bus->armrev = SBCOREREV(bcmsdh_reg_read(bus->sdh,
CORE_SB(bus->ci->armcorebase, sbidhigh), 4));
bus->orig_ramsize = bus->ci->ramsize;
if (!(bus->orig_ramsize)) {
DHD_ERROR(("%s: failed to find SOCRAM memory!\n",
__func__));
goto fail;
}
bus->ramsize = bus->orig_ramsize;
if (dhd_dongle_memsize)
dhd_dongle_setmemsize(bus, dhd_dongle_memsize);
DHD_ERROR(("DHD: dongle ram size is set to %d(orig %d)\n",
bus->ramsize, bus->orig_ramsize));
}
bus->regs = (void *)bus->ci->buscorebase;
OR_REG(&bus->regs->corecontrol, CC_BPRESEN);
bcm_pktq_init(&bus->txq, (PRIOMASK + 1), TXQLEN);
bus->rxhdr = (u8 *) roundup((unsigned long)&bus->hdrbuf[0], DHD_SDALIGN);
bus->intr = (bool) dhd_intr;
bus->poll = (bool) dhd_poll;
if (bus->poll)
bus->pollrate = 1;
return true;
fail:
return false;
}
static bool dhdsdio_probe_malloc(dhd_bus_t *bus, void *sdh)
{
DHD_TRACE(("%s: Enter\n", __func__));
if (bus->dhd->maxctl) {
bus->rxblen =
roundup((bus->dhd->maxctl + SDPCM_HDRLEN),
ALIGNMENT) + DHD_SDALIGN;
bus->rxbuf = kmalloc(bus->rxblen, GFP_ATOMIC);
if (!(bus->rxbuf)) {
DHD_ERROR(("%s: kmalloc of %d-byte rxbuf failed\n",
__func__, bus->rxblen));
goto fail;
}
}
bus->databuf = kmalloc(MAX_DATA_BUF, GFP_ATOMIC);
if (!(bus->databuf)) {
DHD_ERROR(("%s: kmalloc of %d-byte databuf failed\n",
__func__, MAX_DATA_BUF));
if (!bus->rxblen)
kfree(bus->rxbuf);
goto fail;
}
if ((unsigned long)bus->databuf % DHD_SDALIGN)
bus->dataptr =
bus->databuf + (DHD_SDALIGN -
((unsigned long)bus->databuf % DHD_SDALIGN));
else
bus->dataptr = bus->databuf;
return true;
fail:
return false;
}
static bool dhdsdio_probe_init(dhd_bus_t *bus, void *sdh)
{
s32 fnum;
DHD_TRACE(("%s: Enter\n", __func__));
#ifdef SDTEST
dhdsdio_pktgen_init(bus);
#endif
bcmsdh_cfg_write(sdh, SDIO_FUNC_0, SDIOD_CCCR_IOEN, SDIO_FUNC_ENABLE_1,
NULL);
bus->dhd->busstate = DHD_BUS_DOWN;
bus->sleeping = false;
bus->rxflow = false;
bus->prev_rxlim_hit = 0;
bcmsdh_cfg_write(sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR, 0, NULL);
bus->clkstate = CLK_SDONLY;
bus->idletime = (s32) dhd_idletime;
bus->idleclock = DHD_IDLE_ACTIVE;
if (bcmsdh_iovar_op(sdh, "sd_divisor", NULL, 0,
&bus->sd_divisor, sizeof(s32),
false) != 0) {
DHD_ERROR(("%s: fail on %s get\n", __func__, "sd_divisor"));
bus->sd_divisor = -1;
} else {
DHD_INFO(("%s: Initial value for %s is %d\n",
__func__, "sd_divisor", bus->sd_divisor));
}
if (bcmsdh_iovar_op(sdh, "sd_mode", NULL, 0,
&bus->sd_mode, sizeof(s32), false) != 0) {
DHD_ERROR(("%s: fail on %s get\n", __func__, "sd_mode"));
bus->sd_mode = -1;
} else {
DHD_INFO(("%s: Initial value for %s is %d\n",
__func__, "sd_mode", bus->sd_mode));
}
fnum = 2;
if (bcmsdh_iovar_op(sdh, "sd_blocksize", &fnum, sizeof(s32),
&bus->blocksize, sizeof(s32), false) != 0) {
bus->blocksize = 0;
DHD_ERROR(("%s: fail on %s get\n", __func__, "sd_blocksize"));
} else {
DHD_INFO(("%s: Initial value for %s is %d\n",
__func__, "sd_blocksize", bus->blocksize));
}
bus->roundup = min(max_roundup, bus->blocksize);
if (bcmsdh_iovar_op(sdh, "sd_rxchain", NULL, 0,
&bus->sd_rxchain, sizeof(s32),
false) != 0) {
bus->sd_rxchain = false;
} else {
DHD_INFO(("%s: bus module (through bcmsdh API) %s chaining\n",
__func__,
(bus->sd_rxchain ? "supports" : "does not support")));
}
bus->use_rxchain = (bool) bus->sd_rxchain;
return true;
}
bool
dhd_bus_download_firmware(struct dhd_bus *bus, char *fw_path, char *nv_path)
{
bool ret;
bus->fw_path = fw_path;
bus->nv_path = nv_path;
ret = dhdsdio_download_firmware(bus, bus->sdh);
return ret;
}
static bool
dhdsdio_download_firmware(struct dhd_bus *bus, void *sdh)
{
bool ret;
dhdsdio_clkctl(bus, CLK_AVAIL, false);
ret = _dhdsdio_download_firmware(bus) == 0;
dhdsdio_clkctl(bus, CLK_SDONLY, false);
return ret;
}
static void dhdsdio_release(dhd_bus_t *bus)
{
DHD_TRACE(("%s: Enter\n", __func__));
if (bus) {
bcmsdh_intr_disable(bus->sdh);
bcmsdh_intr_dereg(bus->sdh);
if (bus->dhd) {
dhd_detach(bus->dhd);
dhdsdio_release_dongle(bus);
bus->dhd = NULL;
}
dhdsdio_release_malloc(bus);
kfree(bus);
}
DHD_TRACE(("%s: Disconnected\n", __func__));
}
static void dhdsdio_release_malloc(dhd_bus_t *bus)
{
DHD_TRACE(("%s: Enter\n", __func__));
if (bus->dhd && bus->dhd->dongle_reset)
return;
if (bus->rxbuf) {
kfree(bus->rxbuf);
bus->rxctl = bus->rxbuf = NULL;
bus->rxlen = 0;
}
kfree(bus->databuf);
bus->databuf = NULL;
}
static void dhdsdio_release_dongle(dhd_bus_t *bus)
{
DHD_TRACE(("%s: Enter\n", __func__));
if (bus->dhd && bus->dhd->dongle_reset)
return;
if (bus->ci) {
dhdsdio_clkctl(bus, CLK_AVAIL, false);
dhdsdio_clkctl(bus, CLK_NONE, false);
dhdsdio_chip_detach(bus);
if (bus->vars && bus->varsz)
kfree(bus->vars);
bus->vars = NULL;
}
DHD_TRACE(("%s: Disconnected\n", __func__));
}
static void dhdsdio_disconnect(void *ptr)
{
dhd_bus_t *bus = (dhd_bus_t *)ptr;
DHD_TRACE(("%s: Enter\n", __func__));
if (bus) {
ASSERT(bus->dhd);
dhdsdio_release(bus);
}
DHD_TRACE(("%s: Disconnected\n", __func__));
}
int dhd_bus_register(void)
{
DHD_TRACE(("%s: Enter\n", __func__));
return bcmsdh_register(&dhd_sdio);
}
void dhd_bus_unregister(void)
{
DHD_TRACE(("%s: Enter\n", __func__));
bcmsdh_unregister();
}
static int dhdsdio_download_code_array(struct dhd_bus *bus)
{
int bcmerror = -1;
int offset = 0;
DHD_INFO(("%s: download embedded firmware...\n", __func__));
while ((offset + MEMBLOCK) < sizeof(dlarray)) {
bcmerror =
dhdsdio_membytes(bus, true, offset, dlarray + offset,
MEMBLOCK);
if (bcmerror) {
DHD_ERROR(("%s: error %d on writing %d membytes at "
"0x%08x\n",
__func__, bcmerror, MEMBLOCK, offset));
goto err;
}
offset += MEMBLOCK;
}
if (offset < sizeof(dlarray)) {
bcmerror = dhdsdio_membytes(bus, true, offset,
dlarray + offset,
sizeof(dlarray) - offset);
if (bcmerror) {
DHD_ERROR(("%s: error %d on writing %d membytes at "
"0x%08x\n", __func__, bcmerror,
sizeof(dlarray) - offset, offset));
goto err;
}
}
#ifdef DHD_DEBUG
{
unsigned char *ularray;
ularray = kmalloc(bus->ramsize, GFP_ATOMIC);
if (!ularray) {
bcmerror = -ENOMEM;
goto err;
}
offset = 0;
memset(ularray, 0xaa, bus->ramsize);
while ((offset + MEMBLOCK) < sizeof(dlarray)) {
bcmerror =
dhdsdio_membytes(bus, false, offset,
ularray + offset, MEMBLOCK);
if (bcmerror) {
DHD_ERROR(("%s: error %d on reading %d membytes"
" at 0x%08x\n",
__func__, bcmerror, MEMBLOCK, offset));
goto free;
}
offset += MEMBLOCK;
}
if (offset < sizeof(dlarray)) {
bcmerror = dhdsdio_membytes(bus, false, offset,
ularray + offset,
sizeof(dlarray) - offset);
if (bcmerror) {
DHD_ERROR(("%s: error %d on reading %d membytes at 0x%08x\n",
__func__, bcmerror,
sizeof(dlarray) - offset, offset));
goto free;
}
}
if (memcmp(dlarray, ularray, sizeof(dlarray))) {
DHD_ERROR(("%s: Downloaded image is corrupted.\n",
__func__));
ASSERT(0);
goto free;
} else
DHD_ERROR(("%s: Download/Upload/Compare succeeded.\n",
__func__));
free:
kfree(ularray);
}
#endif
err:
return bcmerror;
}
static int dhdsdio_download_code_file(struct dhd_bus *bus, char *fw_path)
{
int bcmerror = -1;
int offset = 0;
uint len;
void *image = NULL;
u8 *memblock = NULL, *memptr;
DHD_INFO(("%s: download firmware %s\n", __func__, fw_path));
image = dhd_os_open_image(fw_path);
if (image == NULL)
goto err;
memptr = memblock = kmalloc(MEMBLOCK + DHD_SDALIGN, GFP_ATOMIC);
if (memblock == NULL) {
DHD_ERROR(("%s: Failed to allocate memory %d bytes\n",
__func__, MEMBLOCK));
goto err;
}
if ((u32)(unsigned long)memblock % DHD_SDALIGN)
memptr +=
(DHD_SDALIGN - ((u32)(unsigned long)memblock % DHD_SDALIGN));
while ((len =
dhd_os_get_image_block((char *)memptr, MEMBLOCK, image))) {
bcmerror = dhdsdio_membytes(bus, true, offset, memptr, len);
if (bcmerror) {
DHD_ERROR(("%s: error %d on writing %d membytes at "
"0x%08x\n", __func__, bcmerror, MEMBLOCK, offset));
goto err;
}
offset += MEMBLOCK;
}
err:
kfree(memblock);
if (image)
dhd_os_close_image(image);
return bcmerror;
}
static uint process_nvram_vars(char *varbuf, uint len)
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
void dhd_bus_set_nvram_params(struct dhd_bus *bus, const char *nvram_params)
{
bus->nvram_params = nvram_params;
}
static int dhdsdio_download_nvram(struct dhd_bus *bus)
{
int bcmerror = -1;
uint len;
void *image = NULL;
char *memblock = NULL;
char *bufp;
char *nv_path;
bool nvram_file_exists;
nv_path = bus->nv_path;
nvram_file_exists = ((nv_path != NULL) && (nv_path[0] != '\0'));
if (!nvram_file_exists && (bus->nvram_params == NULL))
return 0;
if (nvram_file_exists) {
image = dhd_os_open_image(nv_path);
if (image == NULL)
goto err;
}
memblock = kmalloc(MEMBLOCK, GFP_ATOMIC);
if (memblock == NULL) {
DHD_ERROR(("%s: Failed to allocate memory %d bytes\n",
__func__, MEMBLOCK));
goto err;
}
if (nvram_file_exists) {
len = dhd_os_get_image_block(memblock, MEMBLOCK, image);
} else {
len = strlen(bus->nvram_params);
ASSERT(len <= MEMBLOCK);
if (len > MEMBLOCK)
len = MEMBLOCK;
memcpy(memblock, bus->nvram_params, len);
}
if (len > 0 && len < MEMBLOCK) {
bufp = (char *)memblock;
bufp[len] = 0;
len = process_nvram_vars(bufp, len);
bufp += len;
*bufp++ = 0;
if (len)
bcmerror = dhdsdio_downloadvars(bus, memblock, len + 1);
if (bcmerror) {
DHD_ERROR(("%s: error downloading vars: %d\n",
__func__, bcmerror));
}
} else {
DHD_ERROR(("%s: error reading nvram file: %d\n",
__func__, len));
bcmerror = -EIO;
}
err:
kfree(memblock);
if (image)
dhd_os_close_image(image);
return bcmerror;
}
static int _dhdsdio_download_firmware(struct dhd_bus *bus)
{
int bcmerror = -1;
bool embed = false;
bool dlok = false;
if ((bus->fw_path == NULL) || (bus->fw_path[0] == '\0')) {
#ifdef BCMEMBEDIMAGE
embed = true;
#else
return bcmerror;
#endif
}
if (dhdsdio_download_state(bus, true)) {
DHD_ERROR(("%s: error placing ARM core in reset\n", __func__));
goto err;
}
if ((bus->fw_path != NULL) && (bus->fw_path[0] != '\0')) {
if (dhdsdio_download_code_file(bus, bus->fw_path)) {
DHD_ERROR(("%s: dongle image file download failed\n",
__func__));
#ifdef BCMEMBEDIMAGE
embed = true;
#else
goto err;
#endif
} else {
embed = false;
dlok = true;
}
}
#ifdef BCMEMBEDIMAGE
if (embed) {
if (dhdsdio_download_code_array(bus)) {
DHD_ERROR(("%s: dongle image array download failed\n",
__func__));
goto err;
} else {
dlok = true;
}
}
#endif
if (!dlok) {
DHD_ERROR(("%s: dongle image download failed\n", __func__));
goto err;
}
if (dhdsdio_download_nvram(bus)) {
DHD_ERROR(("%s: dongle nvram file download failed\n",
__func__));
}
if (dhdsdio_download_state(bus, false)) {
DHD_ERROR(("%s: error getting out of ARM core reset\n",
__func__));
goto err;
}
bcmerror = 0;
err:
return bcmerror;
}
static int
dhd_bcmsdh_send_buf(dhd_bus_t *bus, u32 addr, uint fn, uint flags,
u8 *buf, uint nbytes, struct sk_buff *pkt,
bcmsdh_cmplt_fn_t complete, void *handle)
{
return bcmsdh_send_buf
(bus->sdh, addr, fn, flags, buf, nbytes, pkt, complete,
handle);
}
uint dhd_bus_chip(struct dhd_bus *bus)
{
ASSERT(bus->ci != NULL);
return bus->ci->chip;
}
void *dhd_bus_pub(struct dhd_bus *bus)
{
return bus->dhd;
}
void *dhd_bus_txq(struct dhd_bus *bus)
{
return &bus->txq;
}
uint dhd_bus_hdrlen(struct dhd_bus *bus)
{
return SDPCM_HDRLEN;
}
int dhd_bus_devreset(dhd_pub_t *dhdp, u8 flag)
{
int bcmerror = 0;
dhd_bus_t *bus;
bus = dhdp->bus;
if (flag == true) {
if (!bus->dhd->dongle_reset) {
dhd_bus_stop(bus, false);
dhdsdio_release_dongle(bus);
bus->dhd->dongle_reset = true;
bus->dhd->up = false;
DHD_TRACE(("%s: WLAN OFF DONE\n", __func__));
} else
bcmerror = -EIO;
} else {
DHD_TRACE(("\n\n%s: == WLAN ON ==\n", __func__));
if (bus->dhd->dongle_reset) {
bcmsdh_reset(bus->sdh);
if (dhdsdio_probe_attach(bus, bus->sdh,
(u32 *) SI_ENUM_BASE,
bus->cl_devid)) {
if (dhdsdio_probe_init
(bus, bus->sdh)
&& dhdsdio_download_firmware(bus,
bus->sdh)) {
dhd_bus_init((dhd_pub_t *) bus->dhd,
false);
#if defined(OOB_INTR_ONLY)
dhd_enable_oob_intr(bus, true);
#endif
bus->dhd->dongle_reset = false;
bus->dhd->up = true;
DHD_TRACE(("%s: WLAN ON DONE\n",
__func__));
} else
bcmerror = -EIO;
} else
bcmerror = -EIO;
} else {
bcmerror = -EISCONN;
DHD_ERROR(("%s: Set DEVRESET=false invoked when device "
"is on\n", __func__));
bcmerror = -EIO;
}
}
return bcmerror;
}
static int
dhdsdio_chip_recognition(bcmsdh_info_t *sdh, struct chip_info *ci, void *regs)
{
u32 regdata;
ci->cccorebase = (u32)regs;
regdata = bcmsdh_reg_read(sdh, CORE_CC_REG(ci->cccorebase, chipid), 4);
ci->chip = regdata & CID_ID_MASK;
ci->chiprev = (regdata & CID_REV_MASK) >> CID_REV_SHIFT;
DHD_INFO(("%s: chipid=0x%x chiprev=%d\n",
__func__, ci->chip, ci->chiprev));
switch (ci->chip) {
case BCM4329_CHIP_ID:
ci->buscorebase = BCM4329_CORE_BUS_BASE;
ci->ramcorebase = BCM4329_CORE_SOCRAM_BASE;
ci->armcorebase = BCM4329_CORE_ARM_BASE;
ci->ramsize = BCM4329_RAMSIZE;
break;
default:
DHD_ERROR(("%s: chipid 0x%x is not supported\n",
__func__, ci->chip));
return -ENODEV;
}
regdata = bcmsdh_reg_read(sdh,
CORE_SB(ci->cccorebase, sbidhigh), 4);
ci->ccrev = SBCOREREV(regdata);
regdata = bcmsdh_reg_read(sdh,
CORE_CC_REG(ci->cccorebase, pmucapabilities), 4);
ci->pmurev = regdata & PCAP_REV_MASK;
regdata = bcmsdh_reg_read(sdh, CORE_SB(ci->buscorebase, sbidhigh), 4);
ci->buscorerev = SBCOREREV(regdata);
ci->buscoretype = (regdata & SBIDH_CC_MASK) >> SBIDH_CC_SHIFT;
DHD_INFO(("%s: ccrev=%d, pmurev=%d, buscore rev/type=%d/0x%x\n",
__func__, ci->ccrev, ci->pmurev,
ci->buscorerev, ci->buscoretype));
ci->cccaps = bcmsdh_reg_read(sdh,
CORE_CC_REG(ci->cccorebase, capabilities), 4);
return 0;
}
static void
dhdsdio_chip_disablecore(bcmsdh_info_t *sdh, u32 corebase)
{
u32 regdata;
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbtmstatelow), 4);
if (regdata & SBTML_RESET)
return;
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbtmstatelow), 4);
if ((regdata & (SICF_CLOCK_EN << SBTML_SICF_SHIFT)) != 0) {
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbtmstatelow), 4);
bcmsdh_reg_write(sdh, CORE_SB(corebase, sbtmstatelow), 4,
regdata | SBTML_REJ);
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbtmstatelow), 4);
udelay(1);
SPINWAIT((bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbtmstatehigh), 4) &
SBTMH_BUSY), 100000);
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbtmstatehigh), 4);
if (regdata & SBTMH_BUSY)
DHD_ERROR(("%s: ARM core still busy\n", __func__));
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbidlow), 4);
if (regdata & SBIDL_INIT) {
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbimstate), 4) |
SBIM_RJ;
bcmsdh_reg_write(sdh,
CORE_SB(corebase, sbimstate), 4,
regdata);
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbimstate), 4);
udelay(1);
SPINWAIT((bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbimstate), 4) &
SBIM_BY), 100000);
}
bcmsdh_reg_write(sdh,
CORE_SB(corebase, sbtmstatelow), 4,
(((SICF_FGC | SICF_CLOCK_EN) << SBTML_SICF_SHIFT) |
SBTML_REJ | SBTML_RESET));
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbtmstatelow), 4);
udelay(10);
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbidlow), 4);
if (regdata & SBIDL_INIT) {
regdata = bcmsdh_reg_read(sdh,
CORE_SB(corebase, sbimstate), 4) &
~SBIM_RJ;
bcmsdh_reg_write(sdh,
CORE_SB(corebase, sbimstate), 4,
regdata);
}
}
bcmsdh_reg_write(sdh, CORE_SB(corebase, sbtmstatelow), 4,
(SBTML_REJ | SBTML_RESET));
udelay(1);
}
static int
dhdsdio_chip_attach(struct dhd_bus *bus, void *regs)
{
struct chip_info *ci;
int err;
u8 clkval, clkset;
DHD_TRACE(("%s: Enter\n", __func__));
ci = kmalloc(sizeof(struct chip_info), GFP_ATOMIC);
if (NULL == ci) {
DHD_ERROR(("%s: malloc failed!\n", __func__));
return -ENOMEM;
}
memset((unsigned char *)ci, 0, sizeof(struct chip_info));
clkset = SBSDIO_FORCE_HW_CLKREQ_OFF | SBSDIO_ALP_AVAIL_REQ;
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR,
clkset, &err);
if (err) {
DHD_ERROR(("%s: error writing for HT off\n", __func__));
goto fail;
}
clkval = bcmsdh_cfg_read(bus->sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR, NULL);
if ((clkval & ~SBSDIO_AVBITS) == clkset) {
SPINWAIT(((clkval =
bcmsdh_cfg_read(bus->sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
NULL)),
!SBSDIO_ALPAV(clkval)),
PMU_MAX_TRANSITION_DLY);
if (!SBSDIO_ALPAV(clkval)) {
DHD_ERROR(("%s: timeout on ALPAV wait, clkval 0x%02x\n",
__func__, clkval));
err = -EBUSY;
goto fail;
}
clkset = SBSDIO_FORCE_HW_CLKREQ_OFF |
SBSDIO_FORCE_ALP;
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1,
SBSDIO_FUNC1_CHIPCLKCSR,
clkset, &err);
udelay(65);
} else {
DHD_ERROR(("%s: ChipClkCSR access: wrote 0x%02x read 0x%02x\n",
__func__, clkset, clkval));
err = -EACCES;
goto fail;
}
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_SDIOPULLUP, 0,
NULL);
err = dhdsdio_chip_recognition(bus->sdh, ci, regs);
if (err)
goto fail;
dhdsdio_chip_disablecore(bus->sdh, ci->armcorebase);
bcmsdh_reg_write(bus->sdh,
CORE_CC_REG(ci->cccorebase, gpiopullup), 4, 0);
bcmsdh_reg_write(bus->sdh,
CORE_CC_REG(ci->cccorebase, gpiopulldown), 4, 0);
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_0, SDIOD_CCCR_IOEN,
SDIO_FUNC_ENABLE_1, NULL);
clkval = bcmsdh_cfg_read(bus->sdh, SDIO_FUNC_1,
0, NULL);
bcmsdh_cfg_write(bus->sdh, SDIO_FUNC_1, SBSDIO_FUNC1_CHIPCLKCSR, 0,
NULL);
bus->ci = ci;
return 0;
fail:
bus->ci = NULL;
kfree(ci);
return err;
}
static void
dhdsdio_chip_resetcore(bcmsdh_info_t *sdh, u32 corebase)
{
u32 regdata;
dhdsdio_chip_disablecore(sdh, corebase);
bcmsdh_reg_write(sdh, CORE_SB(corebase, sbtmstatelow), 4,
((SICF_FGC | SICF_CLOCK_EN) << SBTML_SICF_SHIFT) |
SBTML_RESET);
udelay(1);
regdata = bcmsdh_reg_read(sdh, CORE_SB(corebase, sbtmstatehigh), 4);
if (regdata & SBTMH_SERR)
bcmsdh_reg_write(sdh, CORE_SB(corebase, sbtmstatehigh), 4, 0);
regdata = bcmsdh_reg_read(sdh, CORE_SB(corebase, sbimstate), 4);
if (regdata & (SBIM_IBE | SBIM_TO))
bcmsdh_reg_write(sdh, CORE_SB(corebase, sbimstate), 4,
regdata & ~(SBIM_IBE | SBIM_TO));
bcmsdh_reg_write(sdh, CORE_SB(corebase, sbtmstatelow), 4,
(SICF_FGC << SBTML_SICF_SHIFT) |
(SICF_CLOCK_EN << SBTML_SICF_SHIFT));
udelay(1);
bcmsdh_reg_write(sdh, CORE_SB(corebase, sbtmstatelow), 4,
(SICF_CLOCK_EN << SBTML_SICF_SHIFT));
udelay(1);
}
static void
dhdsdio_sdiod_drive_strength_init(struct dhd_bus *bus, u32 drivestrength) {
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
DHD_ERROR(("No SDIO Drive strength init"
"done for chip %s rev %d pmurev %d\n",
bcm_chipname(bus->ci->chip, chn, 8),
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
bcmsdh_reg_write(bus->sdh,
CORE_CC_REG(bus->ci->cccorebase, chipcontrol_addr),
4, 1);
cc_data_temp = bcmsdh_reg_read(bus->sdh,
CORE_CC_REG(bus->ci->cccorebase, chipcontrol_addr), 4);
cc_data_temp &= ~str_mask;
drivestrength_sel <<= str_shift;
cc_data_temp |= drivestrength_sel;
bcmsdh_reg_write(bus->sdh,
CORE_CC_REG(bus->ci->cccorebase, chipcontrol_addr),
4, cc_data_temp);
DHD_INFO(("SDIO: %dmA drive strength selected, set to 0x%08x\n",
drivestrength, cc_data_temp));
}
}
static void
dhdsdio_chip_detach(struct dhd_bus *bus)
{
DHD_TRACE(("%s: Enter\n", __func__));
kfree(bus->ci);
bus->ci = NULL;
}
