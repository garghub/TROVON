static uint prio2prec(u32 prio)
{
return (prio == PRIO_8021D_NONE || prio == PRIO_8021D_BE) ?
(prio^2) : prio;
}
static void pkt_align(struct sk_buff *p, int len, int align)
{
uint datalign;
datalign = (unsigned long)(p->data);
datalign = roundup(datalign, (align)) - datalign;
if (datalign)
skb_pull(p, datalign);
__skb_trim(p, len);
}
static bool data_ok(struct brcmf_sdio *bus)
{
return (u8)(bus->tx_max - bus->tx_seq) != 0 &&
((u8)(bus->tx_max - bus->tx_seq) & 0x80) == 0;
}
static int
r_sdreg32(struct brcmf_sdio *bus, u32 *regvar, u32 offset)
{
u8 idx = brcmf_sdio_chip_getinfidx(bus->ci, BCMA_CORE_SDIO_DEV);
int ret;
*regvar = brcmf_sdio_regrl(bus->sdiodev,
bus->ci->c_inf[idx].base + offset, &ret);
return ret;
}
static int
w_sdreg32(struct brcmf_sdio *bus, u32 regval, u32 reg_offset)
{
u8 idx = brcmf_sdio_chip_getinfidx(bus->ci, BCMA_CORE_SDIO_DEV);
int ret;
brcmf_sdio_regwl(bus->sdiodev,
bus->ci->c_inf[idx].base + reg_offset,
regval, &ret);
return ret;
}
static int
brcmf_sdbrcm_kso_control(struct brcmf_sdio *bus, bool on)
{
u8 wr_val = 0, rd_val, cmp_val, bmask;
int err = 0;
int try_cnt = 0;
brcmf_dbg(TRACE, "Enter\n");
wr_val = (on << SBSDIO_FUNC1_SLEEPCSR_KSO_SHIFT);
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR,
wr_val, &err);
if (err) {
brcmf_err("SDIO_AOS KSO write error: %d\n", err);
return err;
}
if (on) {
cmp_val = SBSDIO_FUNC1_SLEEPCSR_KSO_MASK |
SBSDIO_FUNC1_SLEEPCSR_DEVON_MASK;
bmask = cmp_val;
usleep_range(2000, 3000);
} else {
cmp_val = 0;
bmask = SBSDIO_FUNC1_SLEEPCSR_KSO_MASK;
}
do {
rd_val = brcmf_sdio_regrb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR,
&err);
if (((rd_val & bmask) == cmp_val) && !err)
break;
brcmf_dbg(SDIO, "KSO wr/rd retry:%d (max: %d) ERR:%x\n",
try_cnt, MAX_KSO_ATTEMPTS, err);
udelay(KSO_WAIT_US);
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR,
wr_val, &err);
} while (try_cnt++ < MAX_KSO_ATTEMPTS);
return err;
}
static int brcmf_sdbrcm_htclk(struct brcmf_sdio *bus, bool on, bool pendok)
{
int err;
u8 clkctl, clkreq, devctl;
unsigned long timeout;
brcmf_dbg(SDIO, "Enter\n");
clkctl = 0;
if (bus->sr_enabled) {
bus->clkstate = (on ? CLK_AVAIL : CLK_SDONLY);
return 0;
}
if (on) {
clkreq =
bus->alp_only ? SBSDIO_ALP_AVAIL_REQ : SBSDIO_HT_AVAIL_REQ;
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
clkreq, &err);
if (err) {
brcmf_err("HT Avail request error: %d\n", err);
return -EBADE;
}
clkctl = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (err) {
brcmf_err("HT Avail read error: %d\n", err);
return -EBADE;
}
if (!SBSDIO_CLKAV(clkctl, bus->alp_only) && pendok) {
devctl = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
if (err) {
brcmf_err("Devctl error setting CA: %d\n",
err);
return -EBADE;
}
devctl |= SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_DEVICE_CTL,
devctl, &err);
brcmf_dbg(SDIO, "CLKCTL: set PENDING\n");
bus->clkstate = CLK_PENDING;
return 0;
} else if (bus->clkstate == CLK_PENDING) {
devctl = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_DEVICE_CTL,
devctl, &err);
}
timeout = jiffies +
msecs_to_jiffies(PMU_MAX_TRANSITION_DLY/1000);
while (!SBSDIO_CLKAV(clkctl, bus->alp_only)) {
clkctl = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR,
&err);
if (time_after(jiffies, timeout))
break;
else
usleep_range(5000, 10000);
}
if (err) {
brcmf_err("HT Avail request error: %d\n", err);
return -EBADE;
}
if (!SBSDIO_CLKAV(clkctl, bus->alp_only)) {
brcmf_err("HT Avail timeout (%d): clkctl 0x%02x\n",
PMU_MAX_TRANSITION_DLY, clkctl);
return -EBADE;
}
bus->clkstate = CLK_AVAIL;
brcmf_dbg(SDIO, "CLKCTL: turned ON\n");
#if defined(DEBUG)
if (!bus->alp_only) {
if (SBSDIO_ALPONLY(clkctl))
brcmf_err("HT Clock should be on\n");
}
#endif
bus->activity = true;
} else {
clkreq = 0;
if (bus->clkstate == CLK_PENDING) {
devctl = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_DEVICE_CTL,
devctl, &err);
}
bus->clkstate = CLK_SDONLY;
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
clkreq, &err);
brcmf_dbg(SDIO, "CLKCTL: turned OFF\n");
if (err) {
brcmf_err("Failed access turning clock off: %d\n",
err);
return -EBADE;
}
}
return 0;
}
static int brcmf_sdbrcm_sdclk(struct brcmf_sdio *bus, bool on)
{
brcmf_dbg(SDIO, "Enter\n");
if (on)
bus->clkstate = CLK_SDONLY;
else
bus->clkstate = CLK_NONE;
return 0;
}
static int brcmf_sdbrcm_clkctl(struct brcmf_sdio *bus, uint target, bool pendok)
{
#ifdef DEBUG
uint oldstate = bus->clkstate;
#endif
brcmf_dbg(SDIO, "Enter\n");
if (bus->clkstate == target) {
if (target == CLK_AVAIL) {
brcmf_sdbrcm_wd_timer(bus, BRCMF_WD_POLL_MS);
bus->activity = true;
}
return 0;
}
switch (target) {
case CLK_AVAIL:
if (bus->clkstate == CLK_NONE)
brcmf_sdbrcm_sdclk(bus, true);
brcmf_sdbrcm_htclk(bus, true, pendok);
brcmf_sdbrcm_wd_timer(bus, BRCMF_WD_POLL_MS);
bus->activity = true;
break;
case CLK_SDONLY:
if (bus->clkstate == CLK_NONE)
brcmf_sdbrcm_sdclk(bus, true);
else if (bus->clkstate == CLK_AVAIL)
brcmf_sdbrcm_htclk(bus, false, false);
else
brcmf_err("request for %d -> %d\n",
bus->clkstate, target);
brcmf_sdbrcm_wd_timer(bus, BRCMF_WD_POLL_MS);
break;
case CLK_NONE:
if (bus->clkstate == CLK_AVAIL)
brcmf_sdbrcm_htclk(bus, false, false);
brcmf_sdbrcm_sdclk(bus, false);
brcmf_sdbrcm_wd_timer(bus, 0);
break;
}
#ifdef DEBUG
brcmf_dbg(SDIO, "%d -> %d\n", oldstate, bus->clkstate);
#endif
return 0;
}
static int
brcmf_sdbrcm_bus_sleep(struct brcmf_sdio *bus, bool sleep, bool pendok)
{
int err = 0;
brcmf_dbg(TRACE, "Enter\n");
brcmf_dbg(SDIO, "request %s currently %s\n",
(sleep ? "SLEEP" : "WAKE"),
(bus->sleeping ? "SLEEP" : "WAKE"));
if (bus->sr_enabled) {
if (sleep == bus->sleeping)
goto end;
if (sleep) {
if (atomic_read(&bus->intstatus) ||
atomic_read(&bus->ipend) > 0 ||
(!atomic_read(&bus->fcstate) &&
brcmu_pktq_mlen(&bus->txq, ~bus->flowcontrol) &&
data_ok(bus)))
return -EBUSY;
err = brcmf_sdbrcm_kso_control(bus, false);
if (!err)
brcmf_sdbrcm_wd_timer(bus, 0);
} else {
bus->idlecount = 0;
err = brcmf_sdbrcm_kso_control(bus, true);
}
if (!err) {
bus->sleeping = sleep;
brcmf_dbg(SDIO, "new state %s\n",
(sleep ? "SLEEP" : "WAKE"));
} else {
brcmf_err("error while changing bus sleep state %d\n",
err);
return err;
}
}
end:
if (sleep) {
if (!bus->sr_enabled)
brcmf_sdbrcm_clkctl(bus, CLK_NONE, pendok);
} else {
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, pendok);
}
return err;
}
static u32 brcmf_sdbrcm_hostmail(struct brcmf_sdio *bus)
{
u32 intstatus = 0;
u32 hmb_data;
u8 fcbits;
int ret;
brcmf_dbg(SDIO, "Enter\n");
ret = r_sdreg32(bus, &hmb_data,
offsetof(struct sdpcmd_regs, tohostmailboxdata));
if (ret == 0)
w_sdreg32(bus, SMB_INT_ACK,
offsetof(struct sdpcmd_regs, tosbmailbox));
bus->sdcnt.f1regdata += 2;
if (hmb_data & HMB_DATA_NAKHANDLED) {
brcmf_dbg(SDIO, "Dongle reports NAK handled, expect rtx of %d\n",
bus->rx_seq);
if (!bus->rxskip)
brcmf_err("unexpected NAKHANDLED!\n");
bus->rxskip = false;
intstatus |= I_HMB_FRAME_IND;
}
if (hmb_data & (HMB_DATA_DEVREADY | HMB_DATA_FWREADY)) {
bus->sdpcm_ver =
(hmb_data & HMB_DATA_VERSION_MASK) >>
HMB_DATA_VERSION_SHIFT;
if (bus->sdpcm_ver != SDPCM_PROT_VERSION)
brcmf_err("Version mismatch, dongle reports %d, "
"expecting %d\n",
bus->sdpcm_ver, SDPCM_PROT_VERSION);
else
brcmf_dbg(SDIO, "Dongle ready, protocol version %d\n",
bus->sdpcm_ver);
}
if (hmb_data & HMB_DATA_FC) {
fcbits = (hmb_data & HMB_DATA_FCDATA_MASK) >>
HMB_DATA_FCDATA_SHIFT;
if (fcbits & ~bus->flowcontrol)
bus->sdcnt.fc_xoff++;
if (bus->flowcontrol & ~fcbits)
bus->sdcnt.fc_xon++;
bus->sdcnt.fc_rcvd++;
bus->flowcontrol = fcbits;
}
if (hmb_data & ~(HMB_DATA_DEVREADY |
HMB_DATA_NAKHANDLED |
HMB_DATA_FC |
HMB_DATA_FWREADY |
HMB_DATA_FCDATA_MASK | HMB_DATA_VERSION_MASK))
brcmf_err("Unknown mailbox data content: 0x%02x\n",
hmb_data);
return intstatus;
}
static void brcmf_sdbrcm_rxfail(struct brcmf_sdio *bus, bool abort, bool rtx)
{
uint retries = 0;
u16 lastrbc;
u8 hi, lo;
int err;
brcmf_err("%sterminate frame%s\n",
abort ? "abort command, " : "",
rtx ? ", send NAK" : "");
if (abort)
brcmf_sdcard_abort(bus->sdiodev, SDIO_FUNC_2);
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_FRAMECTRL,
SFC_RF_TERM, &err);
bus->sdcnt.f1regdata++;
for (lastrbc = retries = 0xffff; retries > 0; retries--) {
hi = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_RFRAMEBCHI, &err);
lo = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_RFRAMEBCLO, &err);
bus->sdcnt.f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
if ((hi > (lastrbc >> 8)) && (lo > (lastrbc & 0x00ff))) {
brcmf_err("count growing: last 0x%04x now 0x%04x\n",
lastrbc, (hi << 8) + lo);
}
lastrbc = (hi << 8) + lo;
}
if (!retries)
brcmf_err("count never zeroed: last 0x%04x\n", lastrbc);
else
brcmf_dbg(SDIO, "flush took %d iterations\n", 0xffff - retries);
if (rtx) {
bus->sdcnt.rxrtx++;
err = w_sdreg32(bus, SMB_NAK,
offsetof(struct sdpcmd_regs, tosbmailbox));
bus->sdcnt.f1regdata++;
if (err == 0)
bus->rxskip = true;
}
bus->cur_read.len = 0;
if (err)
bus->sdiodev->bus_if->state = BRCMF_BUS_DOWN;
}
static uint brcmf_sdbrcm_glom_from_buf(struct brcmf_sdio *bus, uint len)
{
uint n, ret = 0;
struct sk_buff *p;
u8 *buf;
buf = bus->dataptr;
skb_queue_walk(&bus->glom, p) {
n = min_t(uint, p->len, len);
memcpy(p->data, buf, n);
buf += n;
len -= n;
ret += n;
if (!len)
break;
}
return ret;
}
static uint brcmf_sdbrcm_glom_len(struct brcmf_sdio *bus)
{
struct sk_buff *p;
uint total;
total = 0;
skb_queue_walk(&bus->glom, p)
total += p->len;
return total;
}
static void brcmf_sdbrcm_free_glom(struct brcmf_sdio *bus)
{
struct sk_buff *cur, *next;
skb_queue_walk_safe(&bus->glom, cur, next) {
skb_unlink(cur, &bus->glom);
brcmu_pkt_buf_free_skb(cur);
}
}
static int brcmf_sdio_hdparser(struct brcmf_sdio *bus, u8 *header,
struct brcmf_sdio_read *rd,
enum brcmf_sdio_frmtype type)
{
u16 len, checksum;
u8 rx_seq, fc, tx_seq_max;
len = get_unaligned_le16(header);
checksum = get_unaligned_le16(header + sizeof(u16));
if (!(len | checksum)) {
bus->rxpending = false;
return -ENODATA;
}
if ((u16)(~(len ^ checksum))) {
brcmf_err("HW header checksum error\n");
bus->sdcnt.rx_badhdr++;
brcmf_sdbrcm_rxfail(bus, false, false);
return -EIO;
}
if (len < SDPCM_HDRLEN) {
brcmf_err("HW header length error\n");
return -EPROTO;
}
if (type == BRCMF_SDIO_FT_SUPER &&
(roundup(len, bus->blocksize) != rd->len)) {
brcmf_err("HW superframe header length error\n");
return -EPROTO;
}
if (type == BRCMF_SDIO_FT_SUB && len > rd->len) {
brcmf_err("HW subframe header length error\n");
return -EPROTO;
}
rd->len = len;
if (type == BRCMF_SDIO_FT_SUPER &&
SDPCM_GLOMDESC(&header[SDPCM_FRAMETAG_LEN])) {
brcmf_err("Glom descriptor found in superframe head\n");
rd->len = 0;
return -EINVAL;
}
rx_seq = SDPCM_PACKET_SEQUENCE(&header[SDPCM_FRAMETAG_LEN]);
rd->channel = SDPCM_PACKET_CHANNEL(&header[SDPCM_FRAMETAG_LEN]);
if (len > MAX_RX_DATASZ && rd->channel != SDPCM_CONTROL_CHANNEL &&
type != BRCMF_SDIO_FT_SUPER) {
brcmf_err("HW header length too long\n");
bus->sdcnt.rx_toolong++;
brcmf_sdbrcm_rxfail(bus, false, false);
rd->len = 0;
return -EPROTO;
}
if (type == BRCMF_SDIO_FT_SUPER && rd->channel != SDPCM_GLOM_CHANNEL) {
brcmf_err("Wrong channel for superframe\n");
rd->len = 0;
return -EINVAL;
}
if (type == BRCMF_SDIO_FT_SUB && rd->channel != SDPCM_DATA_CHANNEL &&
rd->channel != SDPCM_EVENT_CHANNEL) {
brcmf_err("Wrong channel for subframe\n");
rd->len = 0;
return -EINVAL;
}
rd->dat_offset = SDPCM_DOFFSET_VALUE(&header[SDPCM_FRAMETAG_LEN]);
if (rd->dat_offset < SDPCM_HDRLEN || rd->dat_offset > rd->len) {
brcmf_err("seq %d: bad data offset\n", rx_seq);
bus->sdcnt.rx_badhdr++;
brcmf_sdbrcm_rxfail(bus, false, false);
rd->len = 0;
return -ENXIO;
}
if (rd->seq_num != rx_seq) {
brcmf_err("seq %d: sequence number error, expect %d\n",
rx_seq, rd->seq_num);
bus->sdcnt.rx_badseq++;
rd->seq_num = rx_seq;
}
if (type == BRCMF_SDIO_FT_SUB)
return 0;
rd->len_nxtfrm = header[SDPCM_FRAMETAG_LEN + SDPCM_NEXTLEN_OFFSET];
if (rd->len_nxtfrm << 4 > MAX_RX_DATASZ) {
if (rd->channel != SDPCM_GLOM_CHANNEL)
brcmf_err("seq %d: next length error\n", rx_seq);
rd->len_nxtfrm = 0;
}
fc = SDPCM_FCMASK_VALUE(&header[SDPCM_FRAMETAG_LEN]);
if (bus->flowcontrol != fc) {
if (~bus->flowcontrol & fc)
bus->sdcnt.fc_xoff++;
if (bus->flowcontrol & ~fc)
bus->sdcnt.fc_xon++;
bus->sdcnt.fc_rcvd++;
bus->flowcontrol = fc;
}
tx_seq_max = SDPCM_WINDOW_VALUE(&header[SDPCM_FRAMETAG_LEN]);
if ((u8)(tx_seq_max - bus->tx_seq) > 0x40) {
brcmf_err("seq %d: max tx seq number error\n", rx_seq);
tx_seq_max = bus->tx_seq + 2;
}
bus->tx_max = tx_seq_max;
return 0;
}
static u8 brcmf_sdbrcm_rxglom(struct brcmf_sdio *bus, u8 rxseq)
{
u16 dlen, totlen;
u8 *dptr, num = 0;
u16 sublen;
struct sk_buff *pfirst, *pnext;
int errcode;
u8 doff, sfdoff;
bool usechain = bus->use_rxchain;
struct brcmf_sdio_read rd_new;
brcmf_dbg(SDIO, "start: glomd %p glom %p\n",
bus->glomd, skb_peek(&bus->glom));
if (bus->glomd) {
pfirst = pnext = NULL;
dlen = (u16) (bus->glomd->len);
dptr = bus->glomd->data;
if (!dlen || (dlen & 1)) {
brcmf_err("bad glomd len(%d), ignore descriptor\n",
dlen);
dlen = 0;
}
for (totlen = num = 0; dlen; num++) {
sublen = get_unaligned_le16(dptr);
dlen -= sizeof(u16);
dptr += sizeof(u16);
if ((sublen < SDPCM_HDRLEN) ||
((num == 0) && (sublen < (2 * SDPCM_HDRLEN)))) {
brcmf_err("descriptor len %d bad: %d\n",
num, sublen);
pnext = NULL;
break;
}
if (sublen % BRCMF_SDALIGN) {
brcmf_err("sublen %d not multiple of %d\n",
sublen, BRCMF_SDALIGN);
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
brcmf_err("bcm_pkt_buf_get_skb failed, num %d len %d\n",
num, sublen);
break;
}
skb_queue_tail(&bus->glom, pnext);
pkt_align(pnext, sublen, BRCMF_SDALIGN);
}
if (pnext) {
brcmf_dbg(GLOM, "allocated %d-byte packet chain for %d subframes\n",
totlen, num);
if (BRCMF_GLOM_ON() && bus->cur_read.len &&
totlen != bus->cur_read.len) {
brcmf_dbg(GLOM, "glomdesc mismatch: nextlen %d glomdesc %d rxseq %d\n",
bus->cur_read.len, totlen, rxseq);
}
pfirst = pnext = NULL;
} else {
brcmf_sdbrcm_free_glom(bus);
num = 0;
}
brcmu_pkt_buf_free_skb(bus->glomd);
bus->glomd = NULL;
bus->cur_read.len = 0;
}
if (!skb_queue_empty(&bus->glom)) {
if (BRCMF_GLOM_ON()) {
brcmf_dbg(GLOM, "try superframe read, packet chain:\n");
skb_queue_walk(&bus->glom, pnext) {
brcmf_dbg(GLOM, " %p: %p len 0x%04x (%d)\n",
pnext, (u8 *) (pnext->data),
pnext->len, pnext->len);
}
}
pfirst = skb_peek(&bus->glom);
dlen = (u16) brcmf_sdbrcm_glom_len(bus);
sdio_claim_host(bus->sdiodev->func[1]);
if (usechain) {
errcode = brcmf_sdcard_recv_chain(bus->sdiodev,
bus->sdiodev->sbwad,
SDIO_FUNC_2, F2SYNC, &bus->glom);
} else if (bus->dataptr) {
errcode = brcmf_sdcard_recv_buf(bus->sdiodev,
bus->sdiodev->sbwad,
SDIO_FUNC_2, F2SYNC,
bus->dataptr, dlen);
sublen = (u16) brcmf_sdbrcm_glom_from_buf(bus, dlen);
if (sublen != dlen) {
brcmf_err("FAILED TO COPY, dlen %d sublen %d\n",
dlen, sublen);
errcode = -1;
}
pnext = NULL;
} else {
brcmf_err("COULDN'T ALLOC %d-BYTE GLOM, FORCE FAILURE\n",
dlen);
errcode = -1;
}
sdio_release_host(bus->sdiodev->func[1]);
bus->sdcnt.f2rxdata++;
if (errcode < 0) {
brcmf_err("glom read of %d bytes failed: %d\n",
dlen, errcode);
sdio_claim_host(bus->sdiodev->func[1]);
if (bus->glomerr++ < 3) {
brcmf_sdbrcm_rxfail(bus, true, true);
} else {
bus->glomerr = 0;
brcmf_sdbrcm_rxfail(bus, true, false);
bus->sdcnt.rxglomfail++;
brcmf_sdbrcm_free_glom(bus);
}
sdio_release_host(bus->sdiodev->func[1]);
return 0;
}
brcmf_dbg_hex_dump(BRCMF_GLOM_ON(),
pfirst->data, min_t(int, pfirst->len, 48),
"SUPERFRAME:\n");
rd_new.seq_num = rxseq;
rd_new.len = dlen;
sdio_claim_host(bus->sdiodev->func[1]);
errcode = brcmf_sdio_hdparser(bus, pfirst->data, &rd_new,
BRCMF_SDIO_FT_SUPER);
sdio_release_host(bus->sdiodev->func[1]);
bus->cur_read.len = rd_new.len_nxtfrm << 4;
skb_pull(pfirst, rd_new.dat_offset);
sfdoff = rd_new.dat_offset;
num = 0;
skb_queue_walk(&bus->glom, pnext) {
if (errcode)
break;
rd_new.len = pnext->len;
rd_new.seq_num = rxseq++;
sdio_claim_host(bus->sdiodev->func[1]);
errcode = brcmf_sdio_hdparser(bus, pnext->data, &rd_new,
BRCMF_SDIO_FT_SUB);
sdio_release_host(bus->sdiodev->func[1]);
brcmf_dbg_hex_dump(BRCMF_GLOM_ON(),
pnext->data, 32, "subframe:\n");
num++;
}
if (errcode) {
sdio_claim_host(bus->sdiodev->func[1]);
if (bus->glomerr++ < 3) {
skb_push(pfirst, sfdoff);
brcmf_sdbrcm_rxfail(bus, true, true);
} else {
bus->glomerr = 0;
brcmf_sdbrcm_rxfail(bus, true, false);
bus->sdcnt.rxglomfail++;
brcmf_sdbrcm_free_glom(bus);
}
sdio_release_host(bus->sdiodev->func[1]);
bus->cur_read.len = 0;
return 0;
}
skb_queue_walk_safe(&bus->glom, pfirst, pnext) {
dptr = (u8 *) (pfirst->data);
sublen = get_unaligned_le16(dptr);
doff = SDPCM_DOFFSET_VALUE(&dptr[SDPCM_FRAMETAG_LEN]);
brcmf_dbg_hex_dump(BRCMF_BYTES_ON() && BRCMF_DATA_ON(),
dptr, pfirst->len,
"Rx Subframe Data:\n");
__skb_trim(pfirst, sublen);
skb_pull(pfirst, doff);
if (pfirst->len == 0) {
skb_unlink(pfirst, &bus->glom);
brcmu_pkt_buf_free_skb(pfirst);
continue;
}
brcmf_dbg_hex_dump(BRCMF_GLOM_ON(),
pfirst->data,
min_t(int, pfirst->len, 32),
"subframe %d to stack, %p (%p/%d) nxt/lnk %p/%p\n",
bus->glom.qlen, pfirst, pfirst->data,
pfirst->len, pfirst->next,
pfirst->prev);
}
if (bus->glom.qlen)
brcmf_rx_frames(bus->sdiodev->dev, &bus->glom);
bus->sdcnt.rxglomframes++;
bus->sdcnt.rxglompkts += bus->glom.qlen;
}
return num;
}
static int brcmf_sdbrcm_dcmd_resp_wait(struct brcmf_sdio *bus, uint *condition,
bool *pending)
{
DECLARE_WAITQUEUE(wait, current);
int timeout = msecs_to_jiffies(DCMD_RESP_TIMEOUT);
add_wait_queue(&bus->dcmd_resp_wait, &wait);
set_current_state(TASK_INTERRUPTIBLE);
while (!(*condition) && (!signal_pending(current) && timeout))
timeout = schedule_timeout(timeout);
if (signal_pending(current))
*pending = true;
set_current_state(TASK_RUNNING);
remove_wait_queue(&bus->dcmd_resp_wait, &wait);
return timeout;
}
static int brcmf_sdbrcm_dcmd_resp_wake(struct brcmf_sdio *bus)
{
if (waitqueue_active(&bus->dcmd_resp_wait))
wake_up_interruptible(&bus->dcmd_resp_wait);
return 0;
}
static void
brcmf_sdbrcm_read_control(struct brcmf_sdio *bus, u8 *hdr, uint len, uint doff)
{
uint rdlen, pad;
u8 *buf = NULL, *rbuf;
int sdret;
brcmf_dbg(TRACE, "Enter\n");
if (bus->rxblen)
buf = vzalloc(bus->rxblen);
if (!buf)
goto done;
rbuf = bus->rxbuf;
pad = ((unsigned long)rbuf % BRCMF_SDALIGN);
if (pad)
rbuf += (BRCMF_SDALIGN - pad);
memcpy(buf, hdr, BRCMF_FIRSTREAD);
if (len <= BRCMF_FIRSTREAD)
goto gotpkt;
rdlen = len - BRCMF_FIRSTREAD;
if (bus->roundup && bus->blocksize && (rdlen > bus->blocksize)) {
pad = bus->blocksize - (rdlen % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize) &&
((len + pad) < bus->sdiodev->bus_if->maxctl))
rdlen += pad;
} else if (rdlen % BRCMF_SDALIGN) {
rdlen += BRCMF_SDALIGN - (rdlen % BRCMF_SDALIGN);
}
if (rdlen & (ALIGNMENT - 1))
rdlen = roundup(rdlen, ALIGNMENT);
if ((rdlen + BRCMF_FIRSTREAD) > bus->sdiodev->bus_if->maxctl) {
brcmf_err("%d-byte control read exceeds %d-byte buffer\n",
rdlen, bus->sdiodev->bus_if->maxctl);
brcmf_sdbrcm_rxfail(bus, false, false);
goto done;
}
if ((len - doff) > bus->sdiodev->bus_if->maxctl) {
brcmf_err("%d-byte ctl frame (%d-byte ctl data) exceeds %d-byte limit\n",
len, len - doff, bus->sdiodev->bus_if->maxctl);
bus->sdcnt.rx_toolong++;
brcmf_sdbrcm_rxfail(bus, false, false);
goto done;
}
sdret = brcmf_sdcard_recv_buf(bus->sdiodev,
bus->sdiodev->sbwad,
SDIO_FUNC_2,
F2SYNC, rbuf, rdlen);
bus->sdcnt.f2rxdata++;
if (sdret < 0) {
brcmf_err("read %d control bytes failed: %d\n",
rdlen, sdret);
bus->sdcnt.rxc_errors++;
brcmf_sdbrcm_rxfail(bus, true, true);
goto done;
} else
memcpy(buf + BRCMF_FIRSTREAD, rbuf, rdlen);
gotpkt:
brcmf_dbg_hex_dump(BRCMF_BYTES_ON() && BRCMF_CTL_ON(),
buf, len, "RxCtrl:\n");
spin_lock_bh(&bus->rxctl_lock);
if (bus->rxctl) {
brcmf_err("last control frame is being processed.\n");
spin_unlock_bh(&bus->rxctl_lock);
vfree(buf);
goto done;
}
bus->rxctl = buf + doff;
bus->rxctl_orig = buf;
bus->rxlen = len - doff;
spin_unlock_bh(&bus->rxctl_lock);
done:
brcmf_sdbrcm_dcmd_resp_wake(bus);
}
static void brcmf_pad(struct brcmf_sdio *bus, u16 *pad, u16 *rdlen)
{
if (bus->roundup && bus->blocksize && *rdlen > bus->blocksize) {
*pad = bus->blocksize - (*rdlen % bus->blocksize);
if (*pad <= bus->roundup && *pad < bus->blocksize &&
*rdlen + *pad + BRCMF_FIRSTREAD < MAX_RX_DATASZ)
*rdlen += *pad;
} else if (*rdlen % BRCMF_SDALIGN) {
*rdlen += BRCMF_SDALIGN - (*rdlen % BRCMF_SDALIGN);
}
}
static uint brcmf_sdio_readframes(struct brcmf_sdio *bus, uint maxframes)
{
struct sk_buff *pkt;
struct sk_buff_head pktlist;
u16 pad;
uint rxleft = 0;
int ret;
uint rxcount = 0;
struct brcmf_sdio_read *rd = &bus->cur_read, rd_new;
u8 head_read = 0;
brcmf_dbg(TRACE, "Enter\n");
bus->rxpending = true;
for (rd->seq_num = bus->rx_seq, rxleft = maxframes;
!bus->rxskip && rxleft &&
bus->sdiodev->bus_if->state != BRCMF_BUS_DOWN;
rd->seq_num++, rxleft--) {
if (bus->glomd || !skb_queue_empty(&bus->glom)) {
u8 cnt;
brcmf_dbg(GLOM, "calling rxglom: glomd %p, glom %p\n",
bus->glomd, skb_peek(&bus->glom));
cnt = brcmf_sdbrcm_rxglom(bus, rd->seq_num);
brcmf_dbg(GLOM, "rxglom returned %d\n", cnt);
rd->seq_num += cnt - 1;
rxleft = (rxleft > cnt) ? (rxleft - cnt) : 1;
continue;
}
rd->len_left = rd->len;
sdio_claim_host(bus->sdiodev->func[1]);
if (!rd->len) {
ret = brcmf_sdcard_recv_buf(bus->sdiodev,
bus->sdiodev->sbwad,
SDIO_FUNC_2, F2SYNC,
bus->rxhdr,
BRCMF_FIRSTREAD);
bus->sdcnt.f2rxhdrs++;
if (ret < 0) {
brcmf_err("RXHEADER FAILED: %d\n",
ret);
bus->sdcnt.rx_hdrfail++;
brcmf_sdbrcm_rxfail(bus, true, true);
sdio_release_host(bus->sdiodev->func[1]);
continue;
}
brcmf_dbg_hex_dump(BRCMF_BYTES_ON() || BRCMF_HDRS_ON(),
bus->rxhdr, SDPCM_HDRLEN,
"RxHdr:\n");
if (brcmf_sdio_hdparser(bus, bus->rxhdr, rd,
BRCMF_SDIO_FT_NORMAL)) {
sdio_release_host(bus->sdiodev->func[1]);
if (!bus->rxpending)
break;
else
continue;
}
if (rd->channel == SDPCM_CONTROL_CHANNEL) {
brcmf_sdbrcm_read_control(bus, bus->rxhdr,
rd->len,
rd->dat_offset);
rd->len = rd->len_nxtfrm << 4;
rd->len_nxtfrm = 0;
rd->channel = SDPCM_EVENT_CHANNEL;
sdio_release_host(bus->sdiodev->func[1]);
continue;
}
rd->len_left = rd->len > BRCMF_FIRSTREAD ?
rd->len - BRCMF_FIRSTREAD : 0;
head_read = BRCMF_FIRSTREAD;
}
brcmf_pad(bus, &pad, &rd->len_left);
pkt = brcmu_pkt_buf_get_skb(rd->len_left + head_read +
BRCMF_SDALIGN);
if (!pkt) {
brcmf_err("brcmu_pkt_buf_get_skb failed\n");
brcmf_sdbrcm_rxfail(bus, false,
RETRYCHAN(rd->channel));
sdio_release_host(bus->sdiodev->func[1]);
continue;
}
skb_pull(pkt, head_read);
pkt_align(pkt, rd->len_left, BRCMF_SDALIGN);
ret = brcmf_sdcard_recv_pkt(bus->sdiodev, bus->sdiodev->sbwad,
SDIO_FUNC_2, F2SYNC, pkt);
bus->sdcnt.f2rxdata++;
sdio_release_host(bus->sdiodev->func[1]);
if (ret < 0) {
brcmf_err("read %d bytes from channel %d failed: %d\n",
rd->len, rd->channel, ret);
brcmu_pkt_buf_free_skb(pkt);
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_rxfail(bus, true,
RETRYCHAN(rd->channel));
sdio_release_host(bus->sdiodev->func[1]);
continue;
}
if (head_read) {
skb_push(pkt, head_read);
memcpy(pkt->data, bus->rxhdr, head_read);
head_read = 0;
} else {
memcpy(bus->rxhdr, pkt->data, SDPCM_HDRLEN);
rd_new.seq_num = rd->seq_num;
sdio_claim_host(bus->sdiodev->func[1]);
if (brcmf_sdio_hdparser(bus, bus->rxhdr, &rd_new,
BRCMF_SDIO_FT_NORMAL)) {
rd->len = 0;
brcmu_pkt_buf_free_skb(pkt);
}
bus->sdcnt.rx_readahead_cnt++;
if (rd->len != roundup(rd_new.len, 16)) {
brcmf_err("frame length mismatch:read %d, should be %d\n",
rd->len,
roundup(rd_new.len, 16) >> 4);
rd->len = 0;
brcmf_sdbrcm_rxfail(bus, true, true);
sdio_release_host(bus->sdiodev->func[1]);
brcmu_pkt_buf_free_skb(pkt);
continue;
}
sdio_release_host(bus->sdiodev->func[1]);
rd->len_nxtfrm = rd_new.len_nxtfrm;
rd->channel = rd_new.channel;
rd->dat_offset = rd_new.dat_offset;
brcmf_dbg_hex_dump(!(BRCMF_BYTES_ON() &&
BRCMF_DATA_ON()) &&
BRCMF_HDRS_ON(),
bus->rxhdr, SDPCM_HDRLEN,
"RxHdr:\n");
if (rd_new.channel == SDPCM_CONTROL_CHANNEL) {
brcmf_err("readahead on control packet %d?\n",
rd_new.seq_num);
rd->len = 0;
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_rxfail(bus, false, true);
sdio_release_host(bus->sdiodev->func[1]);
brcmu_pkt_buf_free_skb(pkt);
continue;
}
}
brcmf_dbg_hex_dump(BRCMF_BYTES_ON() && BRCMF_DATA_ON(),
pkt->data, rd->len, "Rx Data:\n");
if (rd->channel == SDPCM_GLOM_CHANNEL) {
if (SDPCM_GLOMDESC(&bus->rxhdr[SDPCM_FRAMETAG_LEN])) {
brcmf_dbg(GLOM, "glom descriptor, %d bytes:\n",
rd->len);
brcmf_dbg_hex_dump(BRCMF_GLOM_ON(),
pkt->data, rd->len,
"Glom Data:\n");
__skb_trim(pkt, rd->len);
skb_pull(pkt, SDPCM_HDRLEN);
bus->glomd = pkt;
} else {
brcmf_err("%s: glom superframe w/o "
"descriptor!\n", __func__);
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_rxfail(bus, false, false);
sdio_release_host(bus->sdiodev->func[1]);
}
rd->len = rd->len_nxtfrm << 4;
rd->len_nxtfrm = 0;
rd->channel = SDPCM_EVENT_CHANNEL;
continue;
}
__skb_trim(pkt, rd->len);
skb_pull(pkt, rd->dat_offset);
rd->len = rd->len_nxtfrm << 4;
rd->len_nxtfrm = 0;
rd->channel = SDPCM_EVENT_CHANNEL;
if (pkt->len == 0) {
brcmu_pkt_buf_free_skb(pkt);
continue;
}
skb_queue_head_init(&pktlist);
skb_queue_tail(&pktlist, pkt);
brcmf_rx_frames(bus->sdiodev->dev, &pktlist);
}
rxcount = maxframes - rxleft;
if (!rxleft)
brcmf_dbg(DATA, "hit rx limit of %d frames\n", maxframes);
else
brcmf_dbg(DATA, "processed %d frames\n", rxcount);
if (bus->rxskip)
rd->seq_num--;
bus->rx_seq = rd->seq_num;
return rxcount;
}
static void
brcmf_sdbrcm_wait_event_wakeup(struct brcmf_sdio *bus)
{
if (waitqueue_active(&bus->ctrl_wait))
wake_up_interruptible(&bus->ctrl_wait);
return;
}
static int brcmf_sdbrcm_txpkt(struct brcmf_sdio *bus, struct sk_buff *pkt,
uint chan)
{
int ret;
u8 *frame;
u16 len, pad = 0;
u32 swheader;
int i;
brcmf_dbg(TRACE, "Enter\n");
frame = (u8 *) (pkt->data);
pad = ((unsigned long)frame % BRCMF_SDALIGN);
if (pad) {
if (skb_headroom(pkt) < pad) {
brcmf_dbg(INFO, "insufficient headroom %d for %d pad\n",
skb_headroom(pkt), pad);
bus->sdiodev->bus_if->tx_realloc++;
ret = skb_cow(pkt, BRCMF_SDALIGN);
if (ret)
goto done;
pad = ((unsigned long)frame % BRCMF_SDALIGN);
}
skb_push(pkt, pad);
frame = (u8 *) (pkt->data);
memset(frame, 0, pad + SDPCM_HDRLEN);
}
len = (u16) (pkt->len);
*(__le16 *) frame = cpu_to_le16(len);
*(((__le16 *) frame) + 1) = cpu_to_le16(~len);
swheader =
((chan << SDPCM_CHANNEL_SHIFT) & SDPCM_CHANNEL_MASK) | bus->tx_seq |
(((pad +
SDPCM_HDRLEN) << SDPCM_DOFFSET_SHIFT) & SDPCM_DOFFSET_MASK);
*(((__le32 *) frame) + 1) = cpu_to_le32(swheader);
*(((__le32 *) frame) + 2) = 0;
#ifdef DEBUG
tx_packets[pkt->priority]++;
#endif
brcmf_dbg_hex_dump(BRCMF_BYTES_ON() &&
((BRCMF_CTL_ON() && chan == SDPCM_CONTROL_CHANNEL) ||
(BRCMF_DATA_ON() && chan != SDPCM_CONTROL_CHANNEL)),
frame, len, "Tx Frame:\n");
brcmf_dbg_hex_dump(!(BRCMF_BYTES_ON() &&
((BRCMF_CTL_ON() &&
chan == SDPCM_CONTROL_CHANNEL) ||
(BRCMF_DATA_ON() &&
chan != SDPCM_CONTROL_CHANNEL))) &&
BRCMF_HDRS_ON(),
frame, min_t(u16, len, 16), "TxHdr:\n");
if (bus->roundup && bus->blocksize && (len > bus->blocksize)) {
u16 pad = bus->blocksize - (len % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize))
len += pad;
} else if (len % BRCMF_SDALIGN) {
len += BRCMF_SDALIGN - (len % BRCMF_SDALIGN);
}
if (len & (ALIGNMENT - 1))
len = roundup(len, ALIGNMENT);
sdio_claim_host(bus->sdiodev->func[1]);
ret = brcmf_sdcard_send_pkt(bus->sdiodev, bus->sdiodev->sbwad,
SDIO_FUNC_2, F2SYNC, pkt);
bus->sdcnt.f2txdata++;
if (ret < 0) {
brcmf_dbg(INFO, "sdio error %d, abort command and terminate frame\n",
ret);
bus->sdcnt.tx_sderrs++;
brcmf_sdcard_abort(bus->sdiodev, SDIO_FUNC_2);
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_FRAMECTRL,
SFC_WF_TERM, NULL);
bus->sdcnt.f1regdata++;
for (i = 0; i < 3; i++) {
u8 hi, lo;
hi = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_WFRAMEBCHI, NULL);
lo = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_WFRAMEBCLO, NULL);
bus->sdcnt.f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
}
}
sdio_release_host(bus->sdiodev->func[1]);
if (ret == 0)
bus->tx_seq = (bus->tx_seq + 1) % SDPCM_SEQUENCE_WRAP;
done:
skb_pull(pkt, SDPCM_HDRLEN + pad);
brcmf_txcomplete(bus->sdiodev->dev, pkt, ret == 0);
return ret;
}
static uint brcmf_sdbrcm_sendfromq(struct brcmf_sdio *bus, uint maxframes)
{
struct sk_buff *pkt;
u32 intstatus = 0;
int ret = 0, prec_out;
uint cnt = 0;
uint datalen;
u8 tx_prec_map;
brcmf_dbg(TRACE, "Enter\n");
tx_prec_map = ~bus->flowcontrol;
for (cnt = 0; (cnt < maxframes) && data_ok(bus); cnt++) {
spin_lock_bh(&bus->txqlock);
pkt = brcmu_pktq_mdeq(&bus->txq, tx_prec_map, &prec_out);
if (pkt == NULL) {
spin_unlock_bh(&bus->txqlock);
break;
}
spin_unlock_bh(&bus->txqlock);
datalen = pkt->len - SDPCM_HDRLEN;
ret = brcmf_sdbrcm_txpkt(bus, pkt, SDPCM_DATA_CHANNEL);
if (!bus->intr && cnt) {
sdio_claim_host(bus->sdiodev->func[1]);
ret = r_sdreg32(bus, &intstatus,
offsetof(struct sdpcmd_regs,
intstatus));
sdio_release_host(bus->sdiodev->func[1]);
bus->sdcnt.f2txdata++;
if (ret != 0)
break;
if (intstatus & bus->hostintmask)
atomic_set(&bus->ipend, 1);
}
}
if ((bus->sdiodev->bus_if->state == BRCMF_BUS_DATA) &&
bus->txoff && (pktq_len(&bus->txq) < TXLOW)) {
bus->txoff = false;
brcmf_txflowblock(bus->sdiodev->dev, false);
}
return cnt;
}
static void brcmf_sdbrcm_bus_stop(struct device *dev)
{
u32 local_hostintmask;
u8 saveclk;
int err;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
brcmf_dbg(TRACE, "Enter\n");
if (bus->watchdog_tsk) {
send_sig(SIGTERM, bus->watchdog_tsk, 1);
kthread_stop(bus->watchdog_tsk);
bus->watchdog_tsk = NULL;
}
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_bus_sleep(bus, false, false);
w_sdreg32(bus, 0, offsetof(struct sdpcmd_regs, hostintmask));
local_hostintmask = bus->hostintmask;
bus->hostintmask = 0;
bus->sdiodev->bus_if->state = BRCMF_BUS_DOWN;
saveclk = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (!err) {
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
(saveclk | SBSDIO_FORCE_HT), &err);
}
if (err)
brcmf_err("Failed to force clock for F2: err %d\n", err);
brcmf_dbg(INTR, "disable SDIO interrupts\n");
brcmf_sdio_regwb(bus->sdiodev, SDIO_CCCR_IOEx, SDIO_FUNC_ENABLE_1,
NULL);
w_sdreg32(bus, local_hostintmask,
offsetof(struct sdpcmd_regs, intstatus));
brcmf_sdbrcm_clkctl(bus, CLK_SDONLY, false);
sdio_release_host(bus->sdiodev->func[1]);
brcmu_pktq_flush(&bus->txq, true, NULL, NULL);
if (bus->glomd)
brcmu_pkt_buf_free_skb(bus->glomd);
brcmf_sdbrcm_free_glom(bus);
spin_lock_bh(&bus->rxctl_lock);
bus->rxlen = 0;
spin_unlock_bh(&bus->rxctl_lock);
brcmf_sdbrcm_dcmd_resp_wake(bus);
bus->rxskip = false;
bus->tx_seq = bus->rx_seq = 0;
}
static inline void brcmf_sdbrcm_clrintr(struct brcmf_sdio *bus)
{
unsigned long flags;
if (bus->sdiodev->oob_irq_requested) {
spin_lock_irqsave(&bus->sdiodev->irq_en_lock, flags);
if (!bus->sdiodev->irq_en && !atomic_read(&bus->ipend)) {
enable_irq(bus->sdiodev->pdata->oob_irq_nr);
bus->sdiodev->irq_en = true;
}
spin_unlock_irqrestore(&bus->sdiodev->irq_en_lock, flags);
}
}
static inline void brcmf_sdbrcm_adddpctsk(struct brcmf_sdio *bus)
{
struct list_head *new_hd;
unsigned long flags;
if (in_interrupt())
new_hd = kzalloc(sizeof(struct list_head), GFP_ATOMIC);
else
new_hd = kzalloc(sizeof(struct list_head), GFP_KERNEL);
if (new_hd == NULL)
return;
spin_lock_irqsave(&bus->dpc_tl_lock, flags);
list_add_tail(new_hd, &bus->dpc_tsklst);
spin_unlock_irqrestore(&bus->dpc_tl_lock, flags);
}
static int brcmf_sdio_intr_rstatus(struct brcmf_sdio *bus)
{
u8 idx;
u32 addr;
unsigned long val;
int n, ret;
idx = brcmf_sdio_chip_getinfidx(bus->ci, BCMA_CORE_SDIO_DEV);
addr = bus->ci->c_inf[idx].base +
offsetof(struct sdpcmd_regs, intstatus);
ret = brcmf_sdio_regrw_helper(bus->sdiodev, addr, &val, false);
bus->sdcnt.f1regdata++;
if (ret != 0)
val = 0;
val &= bus->hostintmask;
atomic_set(&bus->fcstate, !!(val & I_HMB_FC_STATE));
if (val) {
ret = brcmf_sdio_regrw_helper(bus->sdiodev, addr, &val, true);
bus->sdcnt.f1regdata++;
}
if (ret) {
atomic_set(&bus->intstatus, 0);
} else if (val) {
for_each_set_bit(n, &val, 32)
set_bit(n, (unsigned long *)&bus->intstatus.counter);
}
return ret;
}
static void brcmf_sdbrcm_dpc(struct brcmf_sdio *bus)
{
u32 newstatus = 0;
unsigned long intstatus;
uint rxlimit = bus->rxbound;
uint txlimit = bus->txbound;
uint framecnt = 0;
int err = 0, n;
brcmf_dbg(TRACE, "Enter\n");
sdio_claim_host(bus->sdiodev->func[1]);
if (!bus->sr_enabled && bus->clkstate == CLK_PENDING) {
u8 clkctl, devctl = 0;
#ifdef DEBUG
devctl = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
if (err) {
brcmf_err("error reading DEVCTL: %d\n", err);
bus->sdiodev->bus_if->state = BRCMF_BUS_DOWN;
}
#endif
clkctl = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (err) {
brcmf_err("error reading CSR: %d\n",
err);
bus->sdiodev->bus_if->state = BRCMF_BUS_DOWN;
}
brcmf_dbg(SDIO, "DPC: PENDING, devctl 0x%02x clkctl 0x%02x\n",
devctl, clkctl);
if (SBSDIO_HTAV(clkctl)) {
devctl = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
if (err) {
brcmf_err("error reading DEVCTL: %d\n",
err);
bus->sdiodev->bus_if->state = BRCMF_BUS_DOWN;
}
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_DEVICE_CTL,
devctl, &err);
if (err) {
brcmf_err("error writing DEVCTL: %d\n",
err);
bus->sdiodev->bus_if->state = BRCMF_BUS_DOWN;
}
bus->clkstate = CLK_AVAIL;
}
}
brcmf_sdbrcm_bus_sleep(bus, false, true);
if (atomic_read(&bus->ipend) > 0) {
atomic_set(&bus->ipend, 0);
err = brcmf_sdio_intr_rstatus(bus);
}
intstatus = atomic_xchg(&bus->intstatus, 0);
if (intstatus & I_HMB_FC_CHANGE) {
intstatus &= ~I_HMB_FC_CHANGE;
err = w_sdreg32(bus, I_HMB_FC_CHANGE,
offsetof(struct sdpcmd_regs, intstatus));
err = r_sdreg32(bus, &newstatus,
offsetof(struct sdpcmd_regs, intstatus));
bus->sdcnt.f1regdata += 2;
atomic_set(&bus->fcstate,
!!(newstatus & (I_HMB_FC_STATE | I_HMB_FC_CHANGE)));
intstatus |= (newstatus & bus->hostintmask);
}
if (intstatus & I_HMB_HOST_INT) {
intstatus &= ~I_HMB_HOST_INT;
intstatus |= brcmf_sdbrcm_hostmail(bus);
}
sdio_release_host(bus->sdiodev->func[1]);
if (intstatus & I_WR_OOSYNC) {
brcmf_err("Dongle reports WR_OOSYNC\n");
intstatus &= ~I_WR_OOSYNC;
}
if (intstatus & I_RD_OOSYNC) {
brcmf_err("Dongle reports RD_OOSYNC\n");
intstatus &= ~I_RD_OOSYNC;
}
if (intstatus & I_SBINT) {
brcmf_err("Dongle reports SBINT\n");
intstatus &= ~I_SBINT;
}
if (intstatus & I_CHIPACTIVE) {
brcmf_dbg(INFO, "Dongle reports CHIPACTIVE\n");
intstatus &= ~I_CHIPACTIVE;
}
if (bus->rxskip)
intstatus &= ~I_HMB_FRAME_IND;
if (PKT_AVAILABLE() && bus->clkstate == CLK_AVAIL) {
framecnt = brcmf_sdio_readframes(bus, rxlimit);
if (!bus->rxpending)
intstatus &= ~I_HMB_FRAME_IND;
rxlimit -= min(framecnt, rxlimit);
}
if (intstatus) {
for_each_set_bit(n, &intstatus, 32)
set_bit(n, (unsigned long *)&bus->intstatus.counter);
}
brcmf_sdbrcm_clrintr(bus);
if (data_ok(bus) && bus->ctrl_frame_stat &&
(bus->clkstate == CLK_AVAIL)) {
int i;
sdio_claim_host(bus->sdiodev->func[1]);
err = brcmf_sdcard_send_buf(bus->sdiodev, bus->sdiodev->sbwad,
SDIO_FUNC_2, F2SYNC, bus->ctrl_frame_buf,
(u32) bus->ctrl_frame_len);
if (err < 0) {
brcmf_dbg(INFO, "sdio error %d, abort command and terminate frame\n",
err);
bus->sdcnt.tx_sderrs++;
brcmf_sdcard_abort(bus->sdiodev, SDIO_FUNC_2);
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_FRAMECTRL,
SFC_WF_TERM, &err);
bus->sdcnt.f1regdata++;
for (i = 0; i < 3; i++) {
u8 hi, lo;
hi = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_WFRAMEBCHI,
&err);
lo = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_WFRAMEBCLO,
&err);
bus->sdcnt.f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
}
} else {
bus->tx_seq = (bus->tx_seq + 1) % SDPCM_SEQUENCE_WRAP;
}
sdio_release_host(bus->sdiodev->func[1]);
bus->ctrl_frame_stat = false;
brcmf_sdbrcm_wait_event_wakeup(bus);
}
else if ((bus->clkstate == CLK_AVAIL) && !atomic_read(&bus->fcstate) &&
brcmu_pktq_mlen(&bus->txq, ~bus->flowcontrol) && txlimit
&& data_ok(bus)) {
framecnt = bus->rxpending ? min(txlimit, bus->txminmax) :
txlimit;
framecnt = brcmf_sdbrcm_sendfromq(bus, framecnt);
txlimit -= framecnt;
}
if ((bus->sdiodev->bus_if->state == BRCMF_BUS_DOWN) || (err != 0)) {
brcmf_err("failed backplane access over SDIO, halting operation\n");
bus->sdiodev->bus_if->state = BRCMF_BUS_DOWN;
atomic_set(&bus->intstatus, 0);
} else if (atomic_read(&bus->intstatus) ||
atomic_read(&bus->ipend) > 0 ||
(!atomic_read(&bus->fcstate) &&
brcmu_pktq_mlen(&bus->txq, ~bus->flowcontrol) &&
data_ok(bus)) || PKT_AVAILABLE()) {
brcmf_sdbrcm_adddpctsk(bus);
}
if ((bus->clkstate != CLK_PENDING)
&& bus->idletime == BRCMF_IDLE_IMMEDIATE) {
bus->activity = false;
brcmf_dbg(SDIO, "idle state\n");
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_bus_sleep(bus, true, false);
sdio_release_host(bus->sdiodev->func[1]);
}
}
static struct pktq *brcmf_sdbrcm_bus_gettxq(struct device *dev)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
return &bus->txq;
}
static int brcmf_sdbrcm_bus_txdata(struct device *dev, struct sk_buff *pkt)
{
int ret = -EBADE;
uint datalen, prec;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
unsigned long flags;
brcmf_dbg(TRACE, "Enter\n");
datalen = pkt->len;
skb_push(pkt, SDPCM_HDRLEN);
prec = prio2prec((pkt->priority & PRIOMASK));
brcmf_dbg(TRACE, "deferring pktq len %d\n", pktq_len(&bus->txq));
bus->sdcnt.fcqueued++;
spin_lock_bh(&bus->txqlock);
if (!brcmf_c_prec_enq(bus->sdiodev->dev, &bus->txq, pkt, prec)) {
skb_pull(pkt, SDPCM_HDRLEN);
brcmf_txcomplete(bus->sdiodev->dev, pkt, false);
brcmf_err("out of bus->txq !!!\n");
ret = -ENOSR;
} else {
ret = 0;
}
spin_unlock_bh(&bus->txqlock);
if (pktq_len(&bus->txq) >= TXHI) {
bus->txoff = true;
brcmf_txflowblock(bus->sdiodev->dev, true);
}
#ifdef DEBUG
if (pktq_plen(&bus->txq, prec) > qcount[prec])
qcount[prec] = pktq_plen(&bus->txq, prec);
#endif
spin_lock_irqsave(&bus->dpc_tl_lock, flags);
if (list_empty(&bus->dpc_tsklst)) {
spin_unlock_irqrestore(&bus->dpc_tl_lock, flags);
brcmf_sdbrcm_adddpctsk(bus);
queue_work(bus->brcmf_wq, &bus->datawork);
} else {
spin_unlock_irqrestore(&bus->dpc_tl_lock, flags);
}
return ret;
}
static int brcmf_sdbrcm_readconsole(struct brcmf_sdio *bus)
{
struct brcmf_console *c = &bus->console;
u8 line[CONSOLE_LINE_MAX], ch;
u32 n, idx, addr;
int rv;
if (bus->console_addr == 0)
return 0;
addr = bus->console_addr + offsetof(struct rte_console, log_le);
rv = brcmf_sdio_ramrw(bus->sdiodev, false, addr, (u8 *)&c->log_le,
sizeof(c->log_le));
if (rv < 0)
return rv;
if (c->buf == NULL) {
c->bufsize = le32_to_cpu(c->log_le.buf_size);
c->buf = kmalloc(c->bufsize, GFP_ATOMIC);
if (c->buf == NULL)
return -ENOMEM;
}
idx = le32_to_cpu(c->log_le.idx);
if (idx > c->bufsize)
return -EBADE;
if (idx == c->last)
return 0;
addr = le32_to_cpu(c->log_le.buf);
rv = brcmf_sdio_ramrw(bus->sdiodev, false, addr, c->buf, c->bufsize);
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
pr_debug("CONSOLE: %s\n", line);
}
}
break2:
return 0;
}
static int brcmf_tx_frame(struct brcmf_sdio *bus, u8 *frame, u16 len)
{
int i;
int ret;
bus->ctrl_frame_stat = false;
ret = brcmf_sdcard_send_buf(bus->sdiodev, bus->sdiodev->sbwad,
SDIO_FUNC_2, F2SYNC, frame, len);
if (ret < 0) {
brcmf_dbg(INFO, "sdio error %d, abort command and terminate frame\n",
ret);
bus->sdcnt.tx_sderrs++;
brcmf_sdcard_abort(bus->sdiodev, SDIO_FUNC_2);
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_FRAMECTRL,
SFC_WF_TERM, NULL);
bus->sdcnt.f1regdata++;
for (i = 0; i < 3; i++) {
u8 hi, lo;
hi = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_WFRAMEBCHI, NULL);
lo = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_WFRAMEBCLO, NULL);
bus->sdcnt.f1regdata += 2;
if (hi == 0 && lo == 0)
break;
}
return ret;
}
bus->tx_seq = (bus->tx_seq + 1) % SDPCM_SEQUENCE_WRAP;
return ret;
}
static int
brcmf_sdbrcm_bus_txctl(struct device *dev, unsigned char *msg, uint msglen)
{
u8 *frame;
u16 len;
u32 swheader;
uint retries = 0;
u8 doff = 0;
int ret = -1;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
unsigned long flags;
brcmf_dbg(TRACE, "Enter\n");
frame = msg - SDPCM_HDRLEN;
len = (msglen += SDPCM_HDRLEN);
doff = ((unsigned long)frame % BRCMF_SDALIGN);
if (doff) {
frame -= doff;
len += doff;
msglen += doff;
memset(frame, 0, doff + SDPCM_HDRLEN);
}
doff += SDPCM_HDRLEN;
if (bus->roundup && bus->blocksize && (len > bus->blocksize)) {
u16 pad = bus->blocksize - (len % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize))
len += pad;
} else if (len % BRCMF_SDALIGN) {
len += BRCMF_SDALIGN - (len % BRCMF_SDALIGN);
}
if (len & (ALIGNMENT - 1))
len = roundup(len, ALIGNMENT);
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_bus_sleep(bus, false, false);
sdio_release_host(bus->sdiodev->func[1]);
*(__le16 *) frame = cpu_to_le16((u16) msglen);
*(((__le16 *) frame) + 1) = cpu_to_le16(~msglen);
swheader =
((SDPCM_CONTROL_CHANNEL << SDPCM_CHANNEL_SHIFT) &
SDPCM_CHANNEL_MASK)
| bus->tx_seq | ((doff << SDPCM_DOFFSET_SHIFT) &
SDPCM_DOFFSET_MASK);
put_unaligned_le32(swheader, frame + SDPCM_FRAMETAG_LEN);
put_unaligned_le32(0, frame + SDPCM_FRAMETAG_LEN + sizeof(swheader));
if (!data_ok(bus)) {
brcmf_dbg(INFO, "No bus credit bus->tx_max %d, bus->tx_seq %d\n",
bus->tx_max, bus->tx_seq);
bus->ctrl_frame_stat = true;
bus->ctrl_frame_buf = frame;
bus->ctrl_frame_len = len;
wait_event_interruptible_timeout(bus->ctrl_wait,
!bus->ctrl_frame_stat,
msecs_to_jiffies(2000));
if (!bus->ctrl_frame_stat) {
brcmf_dbg(SDIO, "ctrl_frame_stat == false\n");
ret = 0;
} else {
brcmf_dbg(SDIO, "ctrl_frame_stat == true\n");
ret = -1;
}
}
if (ret == -1) {
brcmf_dbg_hex_dump(BRCMF_BYTES_ON() && BRCMF_CTL_ON(),
frame, len, "Tx Frame:\n");
brcmf_dbg_hex_dump(!(BRCMF_BYTES_ON() && BRCMF_CTL_ON()) &&
BRCMF_HDRS_ON(),
frame, min_t(u16, len, 16), "TxHdr:\n");
do {
sdio_claim_host(bus->sdiodev->func[1]);
ret = brcmf_tx_frame(bus, frame, len);
sdio_release_host(bus->sdiodev->func[1]);
} while (ret < 0 && retries++ < TXRETRIES);
}
spin_lock_irqsave(&bus->dpc_tl_lock, flags);
if ((bus->idletime == BRCMF_IDLE_IMMEDIATE) &&
list_empty(&bus->dpc_tsklst)) {
spin_unlock_irqrestore(&bus->dpc_tl_lock, flags);
bus->activity = false;
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_dbg(INFO, "idle\n");
brcmf_sdbrcm_clkctl(bus, CLK_NONE, true);
sdio_release_host(bus->sdiodev->func[1]);
} else {
spin_unlock_irqrestore(&bus->dpc_tl_lock, flags);
}
if (ret)
bus->sdcnt.tx_ctlerrs++;
else
bus->sdcnt.tx_ctlpkts++;
return ret ? -EIO : 0;
}
static inline bool brcmf_sdio_valid_shared_address(u32 addr)
{
return !(addr == 0 || ((~addr >> 16) & 0xffff) == (addr & 0xffff));
}
static int brcmf_sdio_readshared(struct brcmf_sdio *bus,
struct sdpcm_shared *sh)
{
u32 addr;
int rv;
u32 shaddr = 0;
struct sdpcm_shared_le sh_le;
__le32 addr_le;
shaddr = bus->ci->rambase + bus->ramsize - 4;
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_bus_sleep(bus, false, false);
rv = brcmf_sdio_ramrw(bus->sdiodev, false, shaddr, (u8 *)&addr_le, 4);
sdio_release_host(bus->sdiodev->func[1]);
if (rv < 0)
return rv;
addr = le32_to_cpu(addr_le);
brcmf_dbg(SDIO, "sdpcm_shared address 0x%08X\n", addr);
if (!brcmf_sdio_valid_shared_address(addr)) {
brcmf_err("invalid sdpcm_shared address 0x%08X\n",
addr);
return -EINVAL;
}
rv = brcmf_sdio_ramrw(bus->sdiodev, false, addr, (u8 *)&sh_le,
sizeof(struct sdpcm_shared_le));
if (rv < 0)
return rv;
sh->flags = le32_to_cpu(sh_le.flags);
sh->trap_addr = le32_to_cpu(sh_le.trap_addr);
sh->assert_exp_addr = le32_to_cpu(sh_le.assert_exp_addr);
sh->assert_file_addr = le32_to_cpu(sh_le.assert_file_addr);
sh->assert_line = le32_to_cpu(sh_le.assert_line);
sh->console_addr = le32_to_cpu(sh_le.console_addr);
sh->msgtrace_addr = le32_to_cpu(sh_le.msgtrace_addr);
if ((sh->flags & SDPCM_SHARED_VERSION_MASK) > SDPCM_SHARED_VERSION) {
brcmf_err("sdpcm shared version unsupported: dhd %d dongle %d\n",
SDPCM_SHARED_VERSION,
sh->flags & SDPCM_SHARED_VERSION_MASK);
return -EPROTO;
}
return 0;
}
static int brcmf_sdio_dump_console(struct brcmf_sdio *bus,
struct sdpcm_shared *sh, char __user *data,
size_t count)
{
u32 addr, console_ptr, console_size, console_index;
char *conbuf = NULL;
__le32 sh_val;
int rv;
loff_t pos = 0;
int nbytes = 0;
addr = sh->console_addr + offsetof(struct rte_console, log_le);
rv = brcmf_sdio_ramrw(bus->sdiodev, false, addr,
(u8 *)&sh_val, sizeof(u32));
if (rv < 0)
return rv;
console_ptr = le32_to_cpu(sh_val);
addr = sh->console_addr + offsetof(struct rte_console, log_le.buf_size);
rv = brcmf_sdio_ramrw(bus->sdiodev, false, addr,
(u8 *)&sh_val, sizeof(u32));
if (rv < 0)
return rv;
console_size = le32_to_cpu(sh_val);
addr = sh->console_addr + offsetof(struct rte_console, log_le.idx);
rv = brcmf_sdio_ramrw(bus->sdiodev, false, addr,
(u8 *)&sh_val, sizeof(u32));
if (rv < 0)
return rv;
console_index = le32_to_cpu(sh_val);
if (console_size <= CONSOLE_BUFFER_MAX)
conbuf = vzalloc(console_size+1);
if (!conbuf)
return -ENOMEM;
conbuf[console_size] = '\0';
rv = brcmf_sdio_ramrw(bus->sdiodev, false, console_ptr, (u8 *)conbuf,
console_size);
if (rv < 0)
goto done;
rv = simple_read_from_buffer(data, count, &pos,
conbuf + console_index,
console_size - console_index);
if (rv < 0)
goto done;
nbytes = rv;
if (console_index > 0) {
pos = 0;
rv = simple_read_from_buffer(data+nbytes, count, &pos,
conbuf, console_index - 1);
if (rv < 0)
goto done;
rv += nbytes;
}
done:
vfree(conbuf);
return rv;
}
static int brcmf_sdio_trap_info(struct brcmf_sdio *bus, struct sdpcm_shared *sh,
char __user *data, size_t count)
{
int error, res;
char buf[350];
struct brcmf_trap_info tr;
loff_t pos = 0;
if ((sh->flags & SDPCM_SHARED_TRAP) == 0) {
brcmf_dbg(INFO, "no trap in firmware\n");
return 0;
}
error = brcmf_sdio_ramrw(bus->sdiodev, false, sh->trap_addr, (u8 *)&tr,
sizeof(struct brcmf_trap_info));
if (error < 0)
return error;
res = scnprintf(buf, sizeof(buf),
"dongle trap info: type 0x%x @ epc 0x%08x\n"
" cpsr 0x%08x spsr 0x%08x sp 0x%08x\n"
" lr 0x%08x pc 0x%08x offset 0x%x\n"
" r0 0x%08x r1 0x%08x r2 0x%08x r3 0x%08x\n"
" r4 0x%08x r5 0x%08x r6 0x%08x r7 0x%08x\n",
le32_to_cpu(tr.type), le32_to_cpu(tr.epc),
le32_to_cpu(tr.cpsr), le32_to_cpu(tr.spsr),
le32_to_cpu(tr.r13), le32_to_cpu(tr.r14),
le32_to_cpu(tr.pc), sh->trap_addr,
le32_to_cpu(tr.r0), le32_to_cpu(tr.r1),
le32_to_cpu(tr.r2), le32_to_cpu(tr.r3),
le32_to_cpu(tr.r4), le32_to_cpu(tr.r5),
le32_to_cpu(tr.r6), le32_to_cpu(tr.r7));
return simple_read_from_buffer(data, count, &pos, buf, res);
}
static int brcmf_sdio_assert_info(struct brcmf_sdio *bus,
struct sdpcm_shared *sh, char __user *data,
size_t count)
{
int error = 0;
char buf[200];
char file[80] = "?";
char expr[80] = "<???>";
int res;
loff_t pos = 0;
if ((sh->flags & SDPCM_SHARED_ASSERT_BUILT) == 0) {
brcmf_dbg(INFO, "firmware not built with -assert\n");
return 0;
} else if ((sh->flags & SDPCM_SHARED_ASSERT) == 0) {
brcmf_dbg(INFO, "no assert in dongle\n");
return 0;
}
sdio_claim_host(bus->sdiodev->func[1]);
if (sh->assert_file_addr != 0) {
error = brcmf_sdio_ramrw(bus->sdiodev, false,
sh->assert_file_addr, (u8 *)file, 80);
if (error < 0)
return error;
}
if (sh->assert_exp_addr != 0) {
error = brcmf_sdio_ramrw(bus->sdiodev, false,
sh->assert_exp_addr, (u8 *)expr, 80);
if (error < 0)
return error;
}
sdio_release_host(bus->sdiodev->func[1]);
res = scnprintf(buf, sizeof(buf),
"dongle assert: %s:%d: assert(%s)\n",
file, sh->assert_line, expr);
return simple_read_from_buffer(data, count, &pos, buf, res);
}
static int brcmf_sdbrcm_checkdied(struct brcmf_sdio *bus)
{
int error;
struct sdpcm_shared sh;
error = brcmf_sdio_readshared(bus, &sh);
if (error < 0)
return error;
if ((sh.flags & SDPCM_SHARED_ASSERT_BUILT) == 0)
brcmf_dbg(INFO, "firmware not built with -assert\n");
else if (sh.flags & SDPCM_SHARED_ASSERT)
brcmf_err("assertion in dongle\n");
if (sh.flags & SDPCM_SHARED_TRAP)
brcmf_err("firmware trap in dongle\n");
return 0;
}
static int brcmf_sdbrcm_died_dump(struct brcmf_sdio *bus, char __user *data,
size_t count, loff_t *ppos)
{
int error = 0;
struct sdpcm_shared sh;
int nbytes = 0;
loff_t pos = *ppos;
if (pos != 0)
return 0;
error = brcmf_sdio_readshared(bus, &sh);
if (error < 0)
goto done;
error = brcmf_sdio_assert_info(bus, &sh, data, count);
if (error < 0)
goto done;
nbytes = error;
error = brcmf_sdio_trap_info(bus, &sh, data+nbytes, count);
if (error < 0)
goto done;
nbytes += error;
error = brcmf_sdio_dump_console(bus, &sh, data+nbytes, count);
if (error < 0)
goto done;
nbytes += error;
error = nbytes;
*ppos += nbytes;
done:
return error;
}
static ssize_t brcmf_sdio_forensic_read(struct file *f, char __user *data,
size_t count, loff_t *ppos)
{
struct brcmf_sdio *bus = f->private_data;
int res;
res = brcmf_sdbrcm_died_dump(bus, data, count, ppos);
if (res > 0)
*ppos += res;
return (ssize_t)res;
}
static void brcmf_sdio_debugfs_create(struct brcmf_sdio *bus)
{
struct brcmf_pub *drvr = bus->sdiodev->bus_if->drvr;
struct dentry *dentry = brcmf_debugfs_get_devdir(drvr);
if (IS_ERR_OR_NULL(dentry))
return;
debugfs_create_file("forensics", S_IRUGO, dentry, bus,
&brcmf_sdio_forensic_ops);
brcmf_debugfs_create_sdio_count(drvr, &bus->sdcnt);
}
static int brcmf_sdbrcm_checkdied(struct brcmf_sdio *bus)
{
return 0;
}
static void brcmf_sdio_debugfs_create(struct brcmf_sdio *bus)
{
}
static int
brcmf_sdbrcm_bus_rxctl(struct device *dev, unsigned char *msg, uint msglen)
{
int timeleft;
uint rxlen = 0;
bool pending;
u8 *buf;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
brcmf_dbg(TRACE, "Enter\n");
timeleft = brcmf_sdbrcm_dcmd_resp_wait(bus, &bus->rxlen, &pending);
spin_lock_bh(&bus->rxctl_lock);
rxlen = bus->rxlen;
memcpy(msg, bus->rxctl, min(msglen, rxlen));
bus->rxctl = NULL;
buf = bus->rxctl_orig;
bus->rxctl_orig = NULL;
bus->rxlen = 0;
spin_unlock_bh(&bus->rxctl_lock);
vfree(buf);
if (rxlen) {
brcmf_dbg(CTL, "resumed on rxctl frame, got %d expected %d\n",
rxlen, msglen);
} else if (timeleft == 0) {
brcmf_err("resumed on timeout\n");
brcmf_sdbrcm_checkdied(bus);
} else if (pending) {
brcmf_dbg(CTL, "cancelled\n");
return -ERESTARTSYS;
} else {
brcmf_dbg(CTL, "resumed for unknown reason?\n");
brcmf_sdbrcm_checkdied(bus);
}
if (rxlen)
bus->sdcnt.rx_ctlpkts++;
else
bus->sdcnt.rx_ctlerrs++;
return rxlen ? (int)rxlen : -ETIMEDOUT;
}
static bool brcmf_sdbrcm_download_state(struct brcmf_sdio *bus, bool enter)
{
struct chip_info *ci = bus->ci;
if (enter) {
bus->alp_only = true;
brcmf_sdio_chip_enter_download(bus->sdiodev, ci);
} else {
if (!brcmf_sdio_chip_exit_download(bus->sdiodev, ci, bus->vars,
bus->varsz))
return false;
bus->alp_only = false;
bus->sdiodev->bus_if->state = BRCMF_BUS_LOAD;
}
return true;
}
static int brcmf_sdbrcm_get_image(char *buf, int len, struct brcmf_sdio *bus)
{
if (bus->firmware->size < bus->fw_ptr + len)
len = bus->firmware->size - bus->fw_ptr;
memcpy(buf, &bus->firmware->data[bus->fw_ptr], len);
bus->fw_ptr += len;
return len;
}
static int brcmf_sdbrcm_download_code_file(struct brcmf_sdio *bus)
{
int offset;
uint len;
u8 *memblock = NULL, *memptr;
int ret;
u8 idx;
brcmf_dbg(INFO, "Enter\n");
ret = request_firmware(&bus->firmware, BRCMF_SDIO_FW_NAME,
&bus->sdiodev->func[2]->dev);
if (ret) {
brcmf_err("Fail to request firmware %d\n", ret);
return ret;
}
bus->fw_ptr = 0;
memptr = memblock = kmalloc(MEMBLOCK + BRCMF_SDALIGN, GFP_ATOMIC);
if (memblock == NULL) {
ret = -ENOMEM;
goto err;
}
if ((u32)(unsigned long)memblock % BRCMF_SDALIGN)
memptr += (BRCMF_SDALIGN -
((u32)(unsigned long)memblock % BRCMF_SDALIGN));
offset = bus->ci->rambase;
len = brcmf_sdbrcm_get_image((char *)memptr, MEMBLOCK, bus);
idx = brcmf_sdio_chip_getinfidx(bus->ci, BCMA_CORE_ARM_CR4);
if (BRCMF_MAX_CORENUM != idx)
memcpy(&bus->ci->rst_vec, memptr, sizeof(bus->ci->rst_vec));
while (len) {
ret = brcmf_sdio_ramrw(bus->sdiodev, true, offset, memptr, len);
if (ret) {
brcmf_err("error %d on writing %d membytes at 0x%08x\n",
ret, MEMBLOCK, offset);
goto err;
}
offset += MEMBLOCK;
len = brcmf_sdbrcm_get_image((char *)memptr, MEMBLOCK, bus);
}
err:
kfree(memblock);
release_firmware(bus->firmware);
bus->fw_ptr = 0;
return ret;
}
static int brcmf_process_nvram_vars(struct brcmf_sdio *bus)
{
char *varbuf;
char *dp;
bool findNewline;
int column;
int ret = 0;
uint buf_len, n, len;
len = bus->firmware->size;
varbuf = vmalloc(len);
if (!varbuf)
return -ENOMEM;
memcpy(varbuf, bus->firmware->data, len);
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
kfree(bus->vars);
bus->varsz = roundup(buf_len + 1, 4);
bus->vars = kmalloc(bus->varsz, GFP_KERNEL);
if (bus->vars == NULL) {
bus->varsz = 0;
ret = -ENOMEM;
goto err;
}
memcpy(bus->vars, varbuf, buf_len);
bus->vars[buf_len] = 0;
err:
vfree(varbuf);
return ret;
}
static int brcmf_sdbrcm_download_nvram(struct brcmf_sdio *bus)
{
int ret;
ret = request_firmware(&bus->firmware, BRCMF_SDIO_NV_NAME,
&bus->sdiodev->func[2]->dev);
if (ret) {
brcmf_err("Fail to request nvram %d\n", ret);
return ret;
}
ret = brcmf_process_nvram_vars(bus);
release_firmware(bus->firmware);
return ret;
}
static int _brcmf_sdbrcm_download_firmware(struct brcmf_sdio *bus)
{
int bcmerror = -1;
if (!brcmf_sdbrcm_download_state(bus, true)) {
brcmf_err("error placing ARM core in reset\n");
goto err;
}
if (brcmf_sdbrcm_download_code_file(bus)) {
brcmf_err("dongle image file download failed\n");
goto err;
}
if (brcmf_sdbrcm_download_nvram(bus)) {
brcmf_err("dongle nvram file download failed\n");
goto err;
}
if (!brcmf_sdbrcm_download_state(bus, false)) {
brcmf_err("error getting out of ARM core reset\n");
goto err;
}
bcmerror = 0;
err:
return bcmerror;
}
static bool brcmf_sdbrcm_sr_capable(struct brcmf_sdio *bus)
{
u32 addr, reg;
brcmf_dbg(TRACE, "Enter\n");
if (bus->ci->pmurev < 17)
return false;
addr = CORE_CC_REG(bus->ci->c_inf[0].base, chipcontrol_addr);
brcmf_sdio_regwl(bus->sdiodev, addr, 3, NULL);
addr = CORE_CC_REG(bus->ci->c_inf[0].base, chipcontrol_data);
reg = brcmf_sdio_regrl(bus->sdiodev, addr, NULL);
return (bool)reg;
}
static void brcmf_sdbrcm_sr_init(struct brcmf_sdio *bus)
{
int err = 0;
u8 val;
brcmf_dbg(TRACE, "Enter\n");
val = brcmf_sdio_regrb(bus->sdiodev, SBSDIO_FUNC1_WAKEUPCTRL,
&err);
if (err) {
brcmf_err("error reading SBSDIO_FUNC1_WAKEUPCTRL\n");
return;
}
val |= 1 << SBSDIO_FUNC1_WCTRL_HTWAIT_SHIFT;
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_WAKEUPCTRL,
val, &err);
if (err) {
brcmf_err("error writing SBSDIO_FUNC1_WAKEUPCTRL\n");
return;
}
brcmf_sdio_regwb(bus->sdiodev, SDIO_CCCR_BRCM_CARDCAP,
(SDIO_CCCR_BRCM_CARDCAP_CMD14_SUPPORT |
SDIO_CCCR_BRCM_CARDCAP_CMD14_EXT),
&err);
if (err) {
brcmf_err("error writing SDIO_CCCR_BRCM_CARDCAP\n");
return;
}
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
SBSDIO_FORCE_HT, &err);
if (err) {
brcmf_err("error writing SBSDIO_FUNC1_CHIPCLKCSR\n");
return;
}
bus->sr_enabled = true;
brcmf_dbg(INFO, "SR enabled\n");
}
static int brcmf_sdbrcm_kso_init(struct brcmf_sdio *bus)
{
u8 val;
int err = 0;
brcmf_dbg(TRACE, "Enter\n");
if (bus->ci->c_inf[1].rev < 12)
return 0;
val = brcmf_sdio_regrb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR,
&err);
if (err) {
brcmf_err("error reading SBSDIO_FUNC1_SLEEPCSR\n");
return err;
}
if (!(val & SBSDIO_FUNC1_SLEEPCSR_KSO_MASK)) {
val |= (SBSDIO_FUNC1_SLEEPCSR_KSO_EN <<
SBSDIO_FUNC1_SLEEPCSR_KSO_SHIFT);
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR,
val, &err);
if (err) {
brcmf_err("error writing SBSDIO_FUNC1_SLEEPCSR\n");
return err;
}
}
return 0;
}
static bool
brcmf_sdbrcm_download_firmware(struct brcmf_sdio *bus)
{
bool ret;
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
ret = _brcmf_sdbrcm_download_firmware(bus) == 0;
brcmf_sdbrcm_clkctl(bus, CLK_SDONLY, false);
sdio_release_host(bus->sdiodev->func[1]);
return ret;
}
static int brcmf_sdbrcm_bus_init(struct device *dev)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
unsigned long timeout;
u8 ready, enable;
int err, ret = 0;
u8 saveclk;
brcmf_dbg(TRACE, "Enter\n");
if (bus_if->state == BRCMF_BUS_DOWN) {
if (!(brcmf_sdbrcm_download_firmware(bus)))
return -1;
}
if (!bus->sdiodev->bus_if->drvr)
return 0;
bus->sdcnt.tickcnt = 0;
brcmf_sdbrcm_wd_timer(bus, BRCMF_WD_POLL_MS);
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
if (bus->clkstate != CLK_AVAIL)
goto exit;
saveclk = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (!err) {
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
(saveclk | SBSDIO_FORCE_HT), &err);
}
if (err) {
brcmf_err("Failed to force clock for F2: err %d\n", err);
goto exit;
}
w_sdreg32(bus, SDPCM_PROT_VERSION << SMB_DATA_VERSION_SHIFT,
offsetof(struct sdpcmd_regs, tosbmailboxdata));
enable = (SDIO_FUNC_ENABLE_1 | SDIO_FUNC_ENABLE_2);
brcmf_sdio_regwb(bus->sdiodev, SDIO_CCCR_IOEx, enable, NULL);
timeout = jiffies + msecs_to_jiffies(BRCMF_WAIT_F2RDY);
ready = 0;
while (enable != ready) {
ready = brcmf_sdio_regrb(bus->sdiodev,
SDIO_CCCR_IORx, NULL);
if (time_after(jiffies, timeout))
break;
else if (time_after(jiffies, timeout - BRCMF_WAIT_F2RDY + 50))
msleep_interruptible(20);
}
brcmf_dbg(INFO, "enable 0x%02x, ready 0x%02x\n", enable, ready);
if (ready == enable) {
bus->hostintmask = HOSTINTMASK;
w_sdreg32(bus, bus->hostintmask,
offsetof(struct sdpcmd_regs, hostintmask));
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_WATERMARK, 8, &err);
} else {
enable = SDIO_FUNC_ENABLE_1;
brcmf_sdio_regwb(bus->sdiodev, SDIO_CCCR_IOEx, enable, NULL);
ret = -ENODEV;
}
if (brcmf_sdbrcm_sr_capable(bus)) {
brcmf_sdbrcm_sr_init(bus);
} else {
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
saveclk, &err);
}
if (ret == 0) {
ret = brcmf_sdio_intr_register(bus->sdiodev);
if (ret != 0)
brcmf_err("intr register failed:%d\n", ret);
}
if (bus_if->state != BRCMF_BUS_DATA)
brcmf_sdbrcm_clkctl(bus, CLK_NONE, false);
exit:
sdio_release_host(bus->sdiodev->func[1]);
return ret;
}
void brcmf_sdbrcm_isr(void *arg)
{
struct brcmf_sdio *bus = (struct brcmf_sdio *) arg;
brcmf_dbg(TRACE, "Enter\n");
if (!bus) {
brcmf_err("bus is null pointer, exiting\n");
return;
}
if (bus->sdiodev->bus_if->state == BRCMF_BUS_DOWN) {
brcmf_err("bus is down. we have nothing to do\n");
return;
}
bus->sdcnt.intrcount++;
if (in_interrupt())
atomic_set(&bus->ipend, 1);
else
if (brcmf_sdio_intr_rstatus(bus)) {
brcmf_err("failed backplane access\n");
bus->sdiodev->bus_if->state = BRCMF_BUS_DOWN;
}
if (!bus->intr)
brcmf_err("isr w/o interrupt configured!\n");
brcmf_sdbrcm_adddpctsk(bus);
queue_work(bus->brcmf_wq, &bus->datawork);
}
static bool brcmf_sdbrcm_bus_watchdog(struct brcmf_sdio *bus)
{
#ifdef DEBUG
struct brcmf_bus *bus_if = dev_get_drvdata(bus->sdiodev->dev);
#endif
unsigned long flags;
brcmf_dbg(TIMER, "Enter\n");
if (!bus->sr_enabled &&
bus->poll && (++bus->polltick >= bus->pollrate)) {
u32 intstatus = 0;
bus->polltick = 0;
if (!bus->intr ||
(bus->sdcnt.intrcount == bus->sdcnt.lastintrs)) {
spin_lock_irqsave(&bus->dpc_tl_lock, flags);
if (list_empty(&bus->dpc_tsklst)) {
u8 devpend;
spin_unlock_irqrestore(&bus->dpc_tl_lock,
flags);
sdio_claim_host(bus->sdiodev->func[1]);
devpend = brcmf_sdio_regrb(bus->sdiodev,
SDIO_CCCR_INTx,
NULL);
sdio_release_host(bus->sdiodev->func[1]);
intstatus =
devpend & (INTR_STATUS_FUNC1 |
INTR_STATUS_FUNC2);
} else {
spin_unlock_irqrestore(&bus->dpc_tl_lock,
flags);
}
if (intstatus) {
bus->sdcnt.pollcnt++;
atomic_set(&bus->ipend, 1);
brcmf_sdbrcm_adddpctsk(bus);
queue_work(bus->brcmf_wq, &bus->datawork);
}
}
bus->sdcnt.lastintrs = bus->sdcnt.intrcount;
}
#ifdef DEBUG
if (bus_if && bus_if->state == BRCMF_BUS_DATA &&
bus->console_interval != 0) {
bus->console.count += BRCMF_WD_POLL_MS;
if (bus->console.count >= bus->console_interval) {
bus->console.count -= bus->console_interval;
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_bus_sleep(bus, false, false);
if (brcmf_sdbrcm_readconsole(bus) < 0)
bus->console_interval = 0;
sdio_release_host(bus->sdiodev->func[1]);
}
}
#endif
if ((bus->idletime > 0) && (bus->clkstate == CLK_AVAIL)) {
if (++bus->idlecount >= bus->idletime) {
bus->idlecount = 0;
if (bus->activity) {
bus->activity = false;
brcmf_sdbrcm_wd_timer(bus, BRCMF_WD_POLL_MS);
} else {
brcmf_dbg(SDIO, "idle\n");
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_bus_sleep(bus, true, false);
sdio_release_host(bus->sdiodev->func[1]);
}
}
}
return (atomic_read(&bus->ipend) > 0);
}
static bool brcmf_sdbrcm_chipmatch(u16 chipid)
{
if (chipid == BCM43143_CHIP_ID)
return true;
if (chipid == BCM43241_CHIP_ID)
return true;
if (chipid == BCM4329_CHIP_ID)
return true;
if (chipid == BCM4330_CHIP_ID)
return true;
if (chipid == BCM4334_CHIP_ID)
return true;
if (chipid == BCM4335_CHIP_ID)
return true;
return false;
}
static void brcmf_sdio_dataworker(struct work_struct *work)
{
struct brcmf_sdio *bus = container_of(work, struct brcmf_sdio,
datawork);
struct list_head *cur_hd, *tmp_hd;
unsigned long flags;
spin_lock_irqsave(&bus->dpc_tl_lock, flags);
list_for_each_safe(cur_hd, tmp_hd, &bus->dpc_tsklst) {
spin_unlock_irqrestore(&bus->dpc_tl_lock, flags);
brcmf_sdbrcm_dpc(bus);
spin_lock_irqsave(&bus->dpc_tl_lock, flags);
list_del(cur_hd);
kfree(cur_hd);
}
spin_unlock_irqrestore(&bus->dpc_tl_lock, flags);
}
static void brcmf_sdbrcm_release_malloc(struct brcmf_sdio *bus)
{
brcmf_dbg(TRACE, "Enter\n");
kfree(bus->rxbuf);
bus->rxctl = bus->rxbuf = NULL;
bus->rxlen = 0;
kfree(bus->databuf);
bus->databuf = NULL;
}
static bool brcmf_sdbrcm_probe_malloc(struct brcmf_sdio *bus)
{
brcmf_dbg(TRACE, "Enter\n");
if (bus->sdiodev->bus_if->maxctl) {
bus->rxblen =
roundup((bus->sdiodev->bus_if->maxctl + SDPCM_HDRLEN),
ALIGNMENT) + BRCMF_SDALIGN;
bus->rxbuf = kmalloc(bus->rxblen, GFP_ATOMIC);
if (!(bus->rxbuf))
goto fail;
}
bus->databuf = kmalloc(MAX_DATA_BUF, GFP_ATOMIC);
if (!(bus->databuf)) {
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
static bool
brcmf_sdbrcm_probe_attach(struct brcmf_sdio *bus, u32 regsva)
{
u8 clkctl = 0;
int err = 0;
int reg_addr;
u32 reg_val;
u32 drivestrength;
bus->alp_only = true;
sdio_claim_host(bus->sdiodev->func[1]);
pr_debug("F1 signature read @0x18000000=0x%4x\n",
brcmf_sdio_regrl(bus->sdiodev, SI_ENUM_BASE, NULL));
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
BRCMF_INIT_CLKCTL1, &err);
if (!err)
clkctl = brcmf_sdio_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (err || ((clkctl & ~SBSDIO_AVBITS) != BRCMF_INIT_CLKCTL1)) {
brcmf_err("ChipClkCSR access: err %d wrote 0x%02x read 0x%02x\n",
err, BRCMF_INIT_CLKCTL1, clkctl);
goto fail;
}
if (brcmf_sdio_chip_attach(bus->sdiodev, &bus->ci, regsva)) {
brcmf_err("brcmf_sdio_chip_attach failed!\n");
goto fail;
}
if (!brcmf_sdbrcm_chipmatch((u16) bus->ci->chip)) {
brcmf_err("unsupported chip: 0x%04x\n", bus->ci->chip);
goto fail;
}
if (brcmf_sdbrcm_kso_init(bus)) {
brcmf_err("error enabling KSO\n");
goto fail;
}
if ((bus->sdiodev->pdata) && (bus->sdiodev->pdata->drive_strength))
drivestrength = bus->sdiodev->pdata->drive_strength;
else
drivestrength = DEFAULT_SDIO_DRIVE_STRENGTH;
brcmf_sdio_chip_drivestrengthinit(bus->sdiodev, bus->ci, drivestrength);
bus->ramsize = bus->ci->ramsize;
if (!(bus->ramsize)) {
brcmf_err("failed to find SOCRAM memory!\n");
goto fail;
}
reg_val = brcmf_sdio_regrb(bus->sdiodev,
SDIO_CCCR_BRCM_CARDCTRL, &err);
if (err)
goto fail;
reg_val |= SDIO_CCCR_BRCM_CARDCTRL_WLANRESET;
brcmf_sdio_regwb(bus->sdiodev,
SDIO_CCCR_BRCM_CARDCTRL, reg_val, &err);
if (err)
goto fail;
reg_addr = CORE_CC_REG(bus->ci->c_inf[0].base,
pmucontrol);
reg_val = brcmf_sdio_regrl(bus->sdiodev,
reg_addr,
&err);
if (err)
goto fail;
reg_val |= (BCMA_CC_PMU_CTL_RES_RELOAD << BCMA_CC_PMU_CTL_RES_SHIFT);
brcmf_sdio_regwl(bus->sdiodev,
reg_addr,
reg_val,
&err);
if (err)
goto fail;
sdio_release_host(bus->sdiodev->func[1]);
brcmu_pktq_init(&bus->txq, (PRIOMASK + 1), TXQLEN);
bus->rxhdr = (u8 *) roundup((unsigned long)&bus->hdrbuf[0],
BRCMF_SDALIGN);
bus->intr = true;
bus->poll = false;
if (bus->poll)
bus->pollrate = 1;
return true;
fail:
sdio_release_host(bus->sdiodev->func[1]);
return false;
}
static bool brcmf_sdbrcm_probe_init(struct brcmf_sdio *bus)
{
brcmf_dbg(TRACE, "Enter\n");
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdio_regwb(bus->sdiodev, SDIO_CCCR_IOEx,
SDIO_FUNC_ENABLE_1, NULL);
bus->sdiodev->bus_if->state = BRCMF_BUS_DOWN;
bus->rxflow = false;
brcmf_sdio_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR, 0, NULL);
sdio_release_host(bus->sdiodev->func[1]);
bus->clkstate = CLK_SDONLY;
bus->idletime = BRCMF_IDLE_INTERVAL;
bus->idleclock = BRCMF_IDLE_ACTIVE;
bus->blocksize = bus->sdiodev->func[2]->cur_blksize;
bus->roundup = min(max_roundup, bus->blocksize);
bus->use_rxchain = false;
bus->sd_rxchain = false;
bus->sleeping = false;
bus->sr_enabled = false;
return true;
}
static int
brcmf_sdbrcm_watchdog_thread(void *data)
{
struct brcmf_sdio *bus = (struct brcmf_sdio *)data;
allow_signal(SIGTERM);
while (1) {
if (kthread_should_stop())
break;
if (!wait_for_completion_interruptible(&bus->watchdog_wait)) {
brcmf_sdbrcm_bus_watchdog(bus);
bus->sdcnt.tickcnt++;
} else
break;
}
return 0;
}
static void
brcmf_sdbrcm_watchdog(unsigned long data)
{
struct brcmf_sdio *bus = (struct brcmf_sdio *)data;
if (bus->watchdog_tsk) {
complete(&bus->watchdog_wait);
if (bus->wd_timer_valid)
mod_timer(&bus->timer,
jiffies + BRCMF_WD_POLL_MS * HZ / 1000);
}
}
static void brcmf_sdbrcm_release_dongle(struct brcmf_sdio *bus)
{
brcmf_dbg(TRACE, "Enter\n");
if (bus->ci) {
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdbrcm_clkctl(bus, CLK_AVAIL, false);
brcmf_sdbrcm_clkctl(bus, CLK_NONE, false);
sdio_release_host(bus->sdiodev->func[1]);
brcmf_sdio_chip_detach(&bus->ci);
if (bus->vars && bus->varsz)
kfree(bus->vars);
bus->vars = NULL;
}
brcmf_dbg(TRACE, "Disconnected\n");
}
static void brcmf_sdbrcm_release(struct brcmf_sdio *bus)
{
brcmf_dbg(TRACE, "Enter\n");
if (bus) {
brcmf_sdio_intr_unregister(bus->sdiodev);
cancel_work_sync(&bus->datawork);
if (bus->brcmf_wq)
destroy_workqueue(bus->brcmf_wq);
if (bus->sdiodev->bus_if->drvr) {
brcmf_detach(bus->sdiodev->dev);
brcmf_sdbrcm_release_dongle(bus);
}
brcmf_sdbrcm_release_malloc(bus);
kfree(bus);
}
brcmf_dbg(TRACE, "Disconnected\n");
}
void *brcmf_sdbrcm_probe(u32 regsva, struct brcmf_sdio_dev *sdiodev)
{
int ret;
struct brcmf_sdio *bus;
struct brcmf_bus_dcmd *dlst;
u32 dngl_txglom;
u32 dngl_txglomalign;
u8 idx;
brcmf_dbg(TRACE, "Enter\n");
bus = kzalloc(sizeof(struct brcmf_sdio), GFP_ATOMIC);
if (!bus)
goto fail;
bus->sdiodev = sdiodev;
sdiodev->bus = bus;
skb_queue_head_init(&bus->glom);
bus->txbound = BRCMF_TXBOUND;
bus->rxbound = BRCMF_RXBOUND;
bus->txminmax = BRCMF_TXMINMAX;
bus->tx_seq = SDPCM_SEQUENCE_WRAP - 1;
INIT_WORK(&bus->datawork, brcmf_sdio_dataworker);
bus->brcmf_wq = create_singlethread_workqueue("brcmf_wq");
if (bus->brcmf_wq == NULL) {
brcmf_err("insufficient memory to create txworkqueue\n");
goto fail;
}
if (!(brcmf_sdbrcm_probe_attach(bus, regsva))) {
brcmf_err("brcmf_sdbrcm_probe_attach failed\n");
goto fail;
}
spin_lock_init(&bus->rxctl_lock);
spin_lock_init(&bus->txqlock);
init_waitqueue_head(&bus->ctrl_wait);
init_waitqueue_head(&bus->dcmd_resp_wait);
init_timer(&bus->timer);
bus->timer.data = (unsigned long)bus;
bus->timer.function = brcmf_sdbrcm_watchdog;
init_completion(&bus->watchdog_wait);
bus->watchdog_tsk = kthread_run(brcmf_sdbrcm_watchdog_thread,
bus, "brcmf_watchdog");
if (IS_ERR(bus->watchdog_tsk)) {
pr_warn("brcmf_watchdog thread failed to start\n");
bus->watchdog_tsk = NULL;
}
INIT_LIST_HEAD(&bus->dpc_tsklst);
spin_lock_init(&bus->dpc_tl_lock);
bus->sdiodev->bus_if->dev = bus->sdiodev->dev;
bus->sdiodev->bus_if->ops = &brcmf_sdio_bus_ops;
bus->sdiodev->bus_if->chip = bus->ci->chip;
bus->sdiodev->bus_if->chiprev = bus->ci->chiprev;
ret = brcmf_attach(SDPCM_RESERVE, bus->sdiodev->dev);
if (ret != 0) {
brcmf_err("brcmf_attach failed\n");
goto fail;
}
if (!(brcmf_sdbrcm_probe_malloc(bus))) {
brcmf_err("brcmf_sdbrcm_probe_malloc failed\n");
goto fail;
}
if (!(brcmf_sdbrcm_probe_init(bus))) {
brcmf_err("brcmf_sdbrcm_probe_init failed\n");
goto fail;
}
brcmf_sdio_debugfs_create(bus);
brcmf_dbg(INFO, "completed!!\n");
idx = brcmf_sdio_chip_getinfidx(bus->ci, BCMA_CORE_SDIO_DEV);
dlst = kzalloc(sizeof(struct brcmf_bus_dcmd), GFP_KERNEL);
if (dlst) {
if (bus->ci->c_inf[idx].rev < 12) {
dngl_txglom = 0;
dlst->name = "bus:txglom";
dlst->param = (char *)&dngl_txglom;
dlst->param_len = sizeof(u32);
} else {
dngl_txglomalign = bus->sdiodev->bus_if->align;
dlst->name = "bus:txglomalign";
dlst->param = (char *)&dngl_txglomalign;
dlst->param_len = sizeof(u32);
}
list_add(&dlst->list, &bus->sdiodev->bus_if->dcmd_list);
}
ret = brcmf_bus_start(bus->sdiodev->dev);
if (ret != 0) {
brcmf_err("dongle is not responding\n");
goto fail;
}
return bus;
fail:
brcmf_sdbrcm_release(bus);
return NULL;
}
void brcmf_sdbrcm_disconnect(void *ptr)
{
struct brcmf_sdio *bus = (struct brcmf_sdio *)ptr;
brcmf_dbg(TRACE, "Enter\n");
if (bus)
brcmf_sdbrcm_release(bus);
brcmf_dbg(TRACE, "Disconnected\n");
}
void
brcmf_sdbrcm_wd_timer(struct brcmf_sdio *bus, uint wdtick)
{
if (!wdtick && bus->wd_timer_valid) {
del_timer_sync(&bus->timer);
bus->wd_timer_valid = false;
bus->save_ms = wdtick;
return;
}
if (bus->sdiodev->bus_if->state == BRCMF_BUS_DOWN)
return;
if (wdtick) {
if (bus->save_ms != BRCMF_WD_POLL_MS) {
if (bus->wd_timer_valid)
del_timer_sync(&bus->timer);
bus->timer.expires =
jiffies + BRCMF_WD_POLL_MS * HZ / 1000;
add_timer(&bus->timer);
} else {
mod_timer(&bus->timer,
jiffies + BRCMF_WD_POLL_MS * HZ / 1000);
}
bus->wd_timer_valid = true;
bus->save_ms = wdtick;
}
}
