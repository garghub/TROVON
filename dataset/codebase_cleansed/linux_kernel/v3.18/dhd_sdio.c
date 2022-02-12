static uint prio2prec(u32 prio)
{
return (prio == PRIO_8021D_NONE || prio == PRIO_8021D_BE) ?
(prio^2) : prio;
}
static int brcmf_sdio_get_fwnames(struct brcmf_chip *ci,
struct brcmf_sdio_dev *sdiodev)
{
int i;
char end;
for (i = 0; i < ARRAY_SIZE(brcmf_fwname_data); i++) {
if (brcmf_fwname_data[i].chipid == ci->chip &&
brcmf_fwname_data[i].revmsk & BIT(ci->chiprev))
break;
}
if (i == ARRAY_SIZE(brcmf_fwname_data)) {
brcmf_err("Unknown chipid %d [%d]\n", ci->chip, ci->chiprev);
return -ENODEV;
}
if (brcmf_firmware_path[0] != '\0') {
strlcpy(sdiodev->fw_name, brcmf_firmware_path,
sizeof(sdiodev->fw_name));
strlcpy(sdiodev->nvram_name, brcmf_firmware_path,
sizeof(sdiodev->nvram_name));
end = brcmf_firmware_path[strlen(brcmf_firmware_path) - 1];
if (end != '/') {
strlcat(sdiodev->fw_name, "/",
sizeof(sdiodev->fw_name));
strlcat(sdiodev->nvram_name, "/",
sizeof(sdiodev->nvram_name));
}
}
strlcat(sdiodev->fw_name, brcmf_fwname_data[i].bin,
sizeof(sdiodev->fw_name));
strlcat(sdiodev->nvram_name, brcmf_fwname_data[i].nv,
sizeof(sdiodev->nvram_name));
return 0;
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
static int r_sdreg32(struct brcmf_sdio *bus, u32 *regvar, u32 offset)
{
struct brcmf_core *core;
int ret;
core = brcmf_chip_get_core(bus->ci, BCMA_CORE_SDIO_DEV);
*regvar = brcmf_sdiod_regrl(bus->sdiodev, core->base + offset, &ret);
return ret;
}
static int w_sdreg32(struct brcmf_sdio *bus, u32 regval, u32 reg_offset)
{
struct brcmf_core *core;
int ret;
core = brcmf_chip_get_core(bus->ci, BCMA_CORE_SDIO_DEV);
brcmf_sdiod_regwl(bus->sdiodev, core->base + reg_offset, regval, &ret);
return ret;
}
static int
brcmf_sdio_kso_control(struct brcmf_sdio *bus, bool on)
{
u8 wr_val = 0, rd_val, cmp_val, bmask;
int err = 0;
int try_cnt = 0;
brcmf_dbg(TRACE, "Enter: on=%d\n", on);
wr_val = (on << SBSDIO_FUNC1_SLEEPCSR_KSO_SHIFT);
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR,
wr_val, &err);
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
rd_val = brcmf_sdiod_regrb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR,
&err);
if (((rd_val & bmask) == cmp_val) && !err)
break;
udelay(KSO_WAIT_US);
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR,
wr_val, &err);
} while (try_cnt++ < MAX_KSO_ATTEMPTS);
if (try_cnt > 2)
brcmf_dbg(SDIO, "try_cnt=%d rd_val=0x%x err=%d\n", try_cnt,
rd_val, err);
if (try_cnt > MAX_KSO_ATTEMPTS)
brcmf_err("max tries: rd_val=0x%x err=%d\n", rd_val, err);
return err;
}
static int brcmf_sdio_htclk(struct brcmf_sdio *bus, bool on, bool pendok)
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
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
clkreq, &err);
if (err) {
brcmf_err("HT Avail request error: %d\n", err);
return -EBADE;
}
clkctl = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (err) {
brcmf_err("HT Avail read error: %d\n", err);
return -EBADE;
}
if (!SBSDIO_CLKAV(clkctl, bus->alp_only) && pendok) {
devctl = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
if (err) {
brcmf_err("Devctl error setting CA: %d\n",
err);
return -EBADE;
}
devctl |= SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_DEVICE_CTL,
devctl, &err);
brcmf_dbg(SDIO, "CLKCTL: set PENDING\n");
bus->clkstate = CLK_PENDING;
return 0;
} else if (bus->clkstate == CLK_PENDING) {
devctl = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_DEVICE_CTL,
devctl, &err);
}
timeout = jiffies +
msecs_to_jiffies(PMU_MAX_TRANSITION_DLY/1000);
while (!SBSDIO_CLKAV(clkctl, bus->alp_only)) {
clkctl = brcmf_sdiod_regrb(bus->sdiodev,
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
} else {
clkreq = 0;
if (bus->clkstate == CLK_PENDING) {
devctl = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_DEVICE_CTL,
devctl, &err);
}
bus->clkstate = CLK_SDONLY;
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
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
static int brcmf_sdio_sdclk(struct brcmf_sdio *bus, bool on)
{
brcmf_dbg(SDIO, "Enter\n");
if (on)
bus->clkstate = CLK_SDONLY;
else
bus->clkstate = CLK_NONE;
return 0;
}
static int brcmf_sdio_clkctl(struct brcmf_sdio *bus, uint target, bool pendok)
{
#ifdef DEBUG
uint oldstate = bus->clkstate;
#endif
brcmf_dbg(SDIO, "Enter\n");
if (bus->clkstate == target) {
if (target == CLK_AVAIL) {
brcmf_sdio_wd_timer(bus, BRCMF_WD_POLL_MS);
bus->activity = true;
}
return 0;
}
switch (target) {
case CLK_AVAIL:
if (bus->clkstate == CLK_NONE)
brcmf_sdio_sdclk(bus, true);
brcmf_sdio_htclk(bus, true, pendok);
brcmf_sdio_wd_timer(bus, BRCMF_WD_POLL_MS);
bus->activity = true;
break;
case CLK_SDONLY:
if (bus->clkstate == CLK_NONE)
brcmf_sdio_sdclk(bus, true);
else if (bus->clkstate == CLK_AVAIL)
brcmf_sdio_htclk(bus, false, false);
else
brcmf_err("request for %d -> %d\n",
bus->clkstate, target);
brcmf_sdio_wd_timer(bus, BRCMF_WD_POLL_MS);
break;
case CLK_NONE:
if (bus->clkstate == CLK_AVAIL)
brcmf_sdio_htclk(bus, false, false);
brcmf_sdio_sdclk(bus, false);
brcmf_sdio_wd_timer(bus, 0);
break;
}
#ifdef DEBUG
brcmf_dbg(SDIO, "%d -> %d\n", oldstate, bus->clkstate);
#endif
return 0;
}
static int
brcmf_sdio_bus_sleep(struct brcmf_sdio *bus, bool sleep, bool pendok)
{
int err = 0;
u8 clkcsr;
brcmf_dbg(SDIO, "Enter: request %s currently %s\n",
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
data_ok(bus))) {
err = -EBUSY;
goto done;
}
clkcsr = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR,
&err);
if ((clkcsr & SBSDIO_CSR_MASK) == 0) {
brcmf_dbg(SDIO, "no clock, set ALP\n");
brcmf_sdiod_regwb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR,
SBSDIO_ALP_AVAIL_REQ, &err);
}
err = brcmf_sdio_kso_control(bus, false);
if (!err)
brcmf_sdio_wd_timer(bus, 0);
} else {
bus->idlecount = 0;
err = brcmf_sdio_kso_control(bus, true);
}
if (!err) {
bus->sleeping = sleep;
brcmf_dbg(SDIO, "new state %s\n",
(sleep ? "SLEEP" : "WAKE"));
} else {
brcmf_err("error while changing bus sleep state %d\n",
err);
goto done;
}
}
end:
if (sleep) {
if (!bus->sr_enabled)
brcmf_sdio_clkctl(bus, CLK_NONE, pendok);
} else {
brcmf_sdio_clkctl(bus, CLK_AVAIL, pendok);
}
done:
brcmf_dbg(SDIO, "Exit: err=%d\n", err);
return err;
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
brcmf_sdio_bus_sleep(bus, false, false);
rv = brcmf_sdiod_ramrw(bus->sdiodev, false, shaddr, (u8 *)&addr_le, 4);
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
rv = brcmf_sdiod_ramrw(bus->sdiodev, false, addr, (u8 *)&sh_le,
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
static void brcmf_sdio_get_console_addr(struct brcmf_sdio *bus)
{
struct sdpcm_shared sh;
if (brcmf_sdio_readshared(bus, &sh) == 0)
bus->console_addr = sh.console_addr;
}
static void brcmf_sdio_get_console_addr(struct brcmf_sdio *bus)
{
}
static u32 brcmf_sdio_hostmail(struct brcmf_sdio *bus)
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
brcmf_sdio_get_console_addr(bus);
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
static void brcmf_sdio_rxfail(struct brcmf_sdio *bus, bool abort, bool rtx)
{
uint retries = 0;
u16 lastrbc;
u8 hi, lo;
int err;
brcmf_err("%sterminate frame%s\n",
abort ? "abort command, " : "",
rtx ? ", send NAK" : "");
if (abort)
brcmf_sdiod_abort(bus->sdiodev, SDIO_FUNC_2);
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_FRAMECTRL,
SFC_RF_TERM, &err);
bus->sdcnt.f1regdata++;
for (lastrbc = retries = 0xffff; retries > 0; retries--) {
hi = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_FUNC1_RFRAMEBCHI, &err);
lo = brcmf_sdiod_regrb(bus->sdiodev,
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
}
static void brcmf_sdio_txfail(struct brcmf_sdio *bus)
{
struct brcmf_sdio_dev *sdiodev = bus->sdiodev;
u8 i, hi, lo;
brcmf_err("sdio error, abort command and terminate frame\n");
bus->sdcnt.tx_sderrs++;
brcmf_sdiod_abort(sdiodev, SDIO_FUNC_2);
brcmf_sdiod_regwb(sdiodev, SBSDIO_FUNC1_FRAMECTRL, SFC_WF_TERM, NULL);
bus->sdcnt.f1regdata++;
for (i = 0; i < 3; i++) {
hi = brcmf_sdiod_regrb(sdiodev, SBSDIO_FUNC1_WFRAMEBCHI, NULL);
lo = brcmf_sdiod_regrb(sdiodev, SBSDIO_FUNC1_WFRAMEBCLO, NULL);
bus->sdcnt.f1regdata += 2;
if ((hi == 0) && (lo == 0))
break;
}
}
static uint brcmf_sdio_glom_len(struct brcmf_sdio *bus)
{
struct sk_buff *p;
uint total;
total = 0;
skb_queue_walk(&bus->glom, p)
total += p->len;
return total;
}
static void brcmf_sdio_free_glom(struct brcmf_sdio *bus)
{
struct sk_buff *cur, *next;
skb_queue_walk_safe(&bus->glom, cur, next) {
skb_unlink(cur, &bus->glom);
brcmu_pkt_buf_free_skb(cur);
}
}
static inline u8 brcmf_sdio_getdatoffset(u8 *swheader)
{
u32 hdrvalue;
hdrvalue = *(u32 *)swheader;
return (u8)((hdrvalue & SDPCM_DOFFSET_MASK) >> SDPCM_DOFFSET_SHIFT);
}
static int brcmf_sdio_hdparse(struct brcmf_sdio *bus, u8 *header,
struct brcmf_sdio_hdrinfo *rd,
enum brcmf_sdio_frmtype type)
{
u16 len, checksum;
u8 rx_seq, fc, tx_seq_max;
u32 swheader;
trace_brcmf_sdpcm_hdr(SDPCM_RX, header);
len = get_unaligned_le16(header);
checksum = get_unaligned_le16(header + sizeof(u16));
if (!(len | checksum)) {
bus->rxpending = false;
return -ENODATA;
}
if ((u16)(~(len ^ checksum))) {
brcmf_err("HW header checksum error\n");
bus->sdcnt.rx_badhdr++;
brcmf_sdio_rxfail(bus, false, false);
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
header += SDPCM_HWHDR_LEN;
swheader = le32_to_cpu(*(__le32 *)header);
if (type == BRCMF_SDIO_FT_SUPER && SDPCM_GLOMDESC(header)) {
brcmf_err("Glom descriptor found in superframe head\n");
rd->len = 0;
return -EINVAL;
}
rx_seq = (u8)(swheader & SDPCM_SEQ_MASK);
rd->channel = (swheader & SDPCM_CHANNEL_MASK) >> SDPCM_CHANNEL_SHIFT;
if (len > MAX_RX_DATASZ && rd->channel != SDPCM_CONTROL_CHANNEL &&
type != BRCMF_SDIO_FT_SUPER) {
brcmf_err("HW header length too long\n");
bus->sdcnt.rx_toolong++;
brcmf_sdio_rxfail(bus, false, false);
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
rd->dat_offset = brcmf_sdio_getdatoffset(header);
if (rd->dat_offset < SDPCM_HDRLEN || rd->dat_offset > rd->len) {
brcmf_err("seq %d: bad data offset\n", rx_seq);
bus->sdcnt.rx_badhdr++;
brcmf_sdio_rxfail(bus, false, false);
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
rd->len_nxtfrm = (swheader & SDPCM_NEXTLEN_MASK) >> SDPCM_NEXTLEN_SHIFT;
if (rd->len_nxtfrm << 4 > MAX_RX_DATASZ) {
if (rd->channel != SDPCM_GLOM_CHANNEL)
brcmf_err("seq %d: next length error\n", rx_seq);
rd->len_nxtfrm = 0;
}
swheader = le32_to_cpu(*(__le32 *)(header + 4));
fc = swheader & SDPCM_FCMASK_MASK;
if (bus->flowcontrol != fc) {
if (~bus->flowcontrol & fc)
bus->sdcnt.fc_xoff++;
if (bus->flowcontrol & ~fc)
bus->sdcnt.fc_xon++;
bus->sdcnt.fc_rcvd++;
bus->flowcontrol = fc;
}
tx_seq_max = (swheader & SDPCM_WINDOW_MASK) >> SDPCM_WINDOW_SHIFT;
if ((u8)(tx_seq_max - bus->tx_seq) > 0x40) {
brcmf_err("seq %d: max tx seq number error\n", rx_seq);
tx_seq_max = bus->tx_seq + 2;
}
bus->tx_max = tx_seq_max;
return 0;
}
static inline void brcmf_sdio_update_hwhdr(u8 *header, u16 frm_length)
{
*(__le16 *)header = cpu_to_le16(frm_length);
*(((__le16 *)header) + 1) = cpu_to_le16(~frm_length);
}
static void brcmf_sdio_hdpack(struct brcmf_sdio *bus, u8 *header,
struct brcmf_sdio_hdrinfo *hd_info)
{
u32 hdrval;
u8 hdr_offset;
brcmf_sdio_update_hwhdr(header, hd_info->len);
hdr_offset = SDPCM_HWHDR_LEN;
if (bus->txglom) {
hdrval = (hd_info->len - hdr_offset) | (hd_info->lastfrm << 24);
*((__le32 *)(header + hdr_offset)) = cpu_to_le32(hdrval);
hdrval = (u16)hd_info->tail_pad << 16;
*(((__le32 *)(header + hdr_offset)) + 1) = cpu_to_le32(hdrval);
hdr_offset += SDPCM_HWEXT_LEN;
}
hdrval = hd_info->seq_num;
hdrval |= (hd_info->channel << SDPCM_CHANNEL_SHIFT) &
SDPCM_CHANNEL_MASK;
hdrval |= (hd_info->dat_offset << SDPCM_DOFFSET_SHIFT) &
SDPCM_DOFFSET_MASK;
*((__le32 *)(header + hdr_offset)) = cpu_to_le32(hdrval);
*(((__le32 *)(header + hdr_offset)) + 1) = 0;
trace_brcmf_sdpcm_hdr(SDPCM_TX + !!(bus->txglom), header);
}
static u8 brcmf_sdio_rxglom(struct brcmf_sdio *bus, u8 rxseq)
{
u16 dlen, totlen;
u8 *dptr, num = 0;
u16 sublen;
struct sk_buff *pfirst, *pnext;
int errcode;
u8 doff, sfdoff;
struct brcmf_sdio_hdrinfo rd_new;
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
if (sublen % bus->sgentry_align) {
brcmf_err("sublen %d not multiple of %d\n",
sublen, bus->sgentry_align);
}
totlen += sublen;
if (!dlen) {
sublen +=
(roundup(totlen, bus->blocksize) - totlen);
totlen = roundup(totlen, bus->blocksize);
}
pnext = brcmu_pkt_buf_get_skb(sublen + bus->sgentry_align);
if (pnext == NULL) {
brcmf_err("bcm_pkt_buf_get_skb failed, num %d len %d\n",
num, sublen);
break;
}
skb_queue_tail(&bus->glom, pnext);
pkt_align(pnext, sublen, bus->sgentry_align);
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
brcmf_sdio_free_glom(bus);
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
dlen = (u16) brcmf_sdio_glom_len(bus);
sdio_claim_host(bus->sdiodev->func[1]);
errcode = brcmf_sdiod_recv_chain(bus->sdiodev,
&bus->glom, dlen);
sdio_release_host(bus->sdiodev->func[1]);
bus->sdcnt.f2rxdata++;
if (errcode < 0) {
brcmf_err("glom read of %d bytes failed: %d\n",
dlen, errcode);
sdio_claim_host(bus->sdiodev->func[1]);
if (bus->glomerr++ < 3) {
brcmf_sdio_rxfail(bus, true, true);
} else {
bus->glomerr = 0;
brcmf_sdio_rxfail(bus, true, false);
bus->sdcnt.rxglomfail++;
brcmf_sdio_free_glom(bus);
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
errcode = brcmf_sdio_hdparse(bus, pfirst->data, &rd_new,
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
errcode = brcmf_sdio_hdparse(bus, pnext->data, &rd_new,
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
brcmf_sdio_rxfail(bus, true, true);
} else {
bus->glomerr = 0;
brcmf_sdio_rxfail(bus, true, false);
bus->sdcnt.rxglomfail++;
brcmf_sdio_free_glom(bus);
}
sdio_release_host(bus->sdiodev->func[1]);
bus->cur_read.len = 0;
return 0;
}
skb_queue_walk_safe(&bus->glom, pfirst, pnext) {
dptr = (u8 *) (pfirst->data);
sublen = get_unaligned_le16(dptr);
doff = brcmf_sdio_getdatoffset(&dptr[SDPCM_HWHDR_LEN]);
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
skb_unlink(pfirst, &bus->glom);
brcmf_rx_frame(bus->sdiodev->dev, pfirst);
bus->sdcnt.rxglompkts++;
}
bus->sdcnt.rxglomframes++;
}
return num;
}
static int brcmf_sdio_dcmd_resp_wait(struct brcmf_sdio *bus, uint *condition,
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
static int brcmf_sdio_dcmd_resp_wake(struct brcmf_sdio *bus)
{
if (waitqueue_active(&bus->dcmd_resp_wait))
wake_up_interruptible(&bus->dcmd_resp_wait);
return 0;
}
static void
brcmf_sdio_read_control(struct brcmf_sdio *bus, u8 *hdr, uint len, uint doff)
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
pad = ((unsigned long)rbuf % bus->head_align);
if (pad)
rbuf += (bus->head_align - pad);
memcpy(buf, hdr, BRCMF_FIRSTREAD);
if (len <= BRCMF_FIRSTREAD)
goto gotpkt;
rdlen = len - BRCMF_FIRSTREAD;
if (bus->roundup && bus->blocksize && (rdlen > bus->blocksize)) {
pad = bus->blocksize - (rdlen % bus->blocksize);
if ((pad <= bus->roundup) && (pad < bus->blocksize) &&
((len + pad) < bus->sdiodev->bus_if->maxctl))
rdlen += pad;
} else if (rdlen % bus->head_align) {
rdlen += bus->head_align - (rdlen % bus->head_align);
}
if ((rdlen + BRCMF_FIRSTREAD) > bus->sdiodev->bus_if->maxctl) {
brcmf_err("%d-byte control read exceeds %d-byte buffer\n",
rdlen, bus->sdiodev->bus_if->maxctl);
brcmf_sdio_rxfail(bus, false, false);
goto done;
}
if ((len - doff) > bus->sdiodev->bus_if->maxctl) {
brcmf_err("%d-byte ctl frame (%d-byte ctl data) exceeds %d-byte limit\n",
len, len - doff, bus->sdiodev->bus_if->maxctl);
bus->sdcnt.rx_toolong++;
brcmf_sdio_rxfail(bus, false, false);
goto done;
}
sdret = brcmf_sdiod_recv_buf(bus->sdiodev, rbuf, rdlen);
bus->sdcnt.f2rxdata++;
if (sdret < 0) {
brcmf_err("read %d control bytes failed: %d\n",
rdlen, sdret);
bus->sdcnt.rxc_errors++;
brcmf_sdio_rxfail(bus, true, true);
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
brcmf_sdio_dcmd_resp_wake(bus);
}
static void brcmf_sdio_pad(struct brcmf_sdio *bus, u16 *pad, u16 *rdlen)
{
if (bus->roundup && bus->blocksize && *rdlen > bus->blocksize) {
*pad = bus->blocksize - (*rdlen % bus->blocksize);
if (*pad <= bus->roundup && *pad < bus->blocksize &&
*rdlen + *pad + BRCMF_FIRSTREAD < MAX_RX_DATASZ)
*rdlen += *pad;
} else if (*rdlen % bus->head_align) {
*rdlen += bus->head_align - (*rdlen % bus->head_align);
}
}
static uint brcmf_sdio_readframes(struct brcmf_sdio *bus, uint maxframes)
{
struct sk_buff *pkt;
u16 pad;
uint rxleft = 0;
int ret;
uint rxcount = 0;
struct brcmf_sdio_hdrinfo *rd = &bus->cur_read, rd_new;
u8 head_read = 0;
brcmf_dbg(TRACE, "Enter\n");
bus->rxpending = true;
for (rd->seq_num = bus->rx_seq, rxleft = maxframes;
!bus->rxskip && rxleft && brcmf_bus_ready(bus->sdiodev->bus_if);
rd->seq_num++, rxleft--) {
if (bus->glomd || !skb_queue_empty(&bus->glom)) {
u8 cnt;
brcmf_dbg(GLOM, "calling rxglom: glomd %p, glom %p\n",
bus->glomd, skb_peek(&bus->glom));
cnt = brcmf_sdio_rxglom(bus, rd->seq_num);
brcmf_dbg(GLOM, "rxglom returned %d\n", cnt);
rd->seq_num += cnt - 1;
rxleft = (rxleft > cnt) ? (rxleft - cnt) : 1;
continue;
}
rd->len_left = rd->len;
sdio_claim_host(bus->sdiodev->func[1]);
if (!rd->len) {
ret = brcmf_sdiod_recv_buf(bus->sdiodev,
bus->rxhdr, BRCMF_FIRSTREAD);
bus->sdcnt.f2rxhdrs++;
if (ret < 0) {
brcmf_err("RXHEADER FAILED: %d\n",
ret);
bus->sdcnt.rx_hdrfail++;
brcmf_sdio_rxfail(bus, true, true);
sdio_release_host(bus->sdiodev->func[1]);
continue;
}
brcmf_dbg_hex_dump(BRCMF_BYTES_ON() || BRCMF_HDRS_ON(),
bus->rxhdr, SDPCM_HDRLEN,
"RxHdr:\n");
if (brcmf_sdio_hdparse(bus, bus->rxhdr, rd,
BRCMF_SDIO_FT_NORMAL)) {
sdio_release_host(bus->sdiodev->func[1]);
if (!bus->rxpending)
break;
else
continue;
}
if (rd->channel == SDPCM_CONTROL_CHANNEL) {
brcmf_sdio_read_control(bus, bus->rxhdr,
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
brcmf_sdio_pad(bus, &pad, &rd->len_left);
pkt = brcmu_pkt_buf_get_skb(rd->len_left + head_read +
bus->head_align);
if (!pkt) {
brcmf_err("brcmu_pkt_buf_get_skb failed\n");
brcmf_sdio_rxfail(bus, false,
RETRYCHAN(rd->channel));
sdio_release_host(bus->sdiodev->func[1]);
continue;
}
skb_pull(pkt, head_read);
pkt_align(pkt, rd->len_left, bus->head_align);
ret = brcmf_sdiod_recv_pkt(bus->sdiodev, pkt);
bus->sdcnt.f2rxdata++;
sdio_release_host(bus->sdiodev->func[1]);
if (ret < 0) {
brcmf_err("read %d bytes from channel %d failed: %d\n",
rd->len, rd->channel, ret);
brcmu_pkt_buf_free_skb(pkt);
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdio_rxfail(bus, true,
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
if (brcmf_sdio_hdparse(bus, bus->rxhdr, &rd_new,
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
brcmf_sdio_rxfail(bus, true, true);
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
brcmf_sdio_rxfail(bus, false, true);
sdio_release_host(bus->sdiodev->func[1]);
brcmu_pkt_buf_free_skb(pkt);
continue;
}
}
brcmf_dbg_hex_dump(BRCMF_BYTES_ON() && BRCMF_DATA_ON(),
pkt->data, rd->len, "Rx Data:\n");
if (rd->channel == SDPCM_GLOM_CHANNEL) {
if (SDPCM_GLOMDESC(&bus->rxhdr[SDPCM_HWHDR_LEN])) {
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
brcmf_sdio_rxfail(bus, false, false);
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
brcmf_rx_frame(bus->sdiodev->dev, pkt);
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
brcmf_sdio_wait_event_wakeup(struct brcmf_sdio *bus)
{
if (waitqueue_active(&bus->ctrl_wait))
wake_up_interruptible(&bus->ctrl_wait);
return;
}
static int brcmf_sdio_txpkt_hdalign(struct brcmf_sdio *bus, struct sk_buff *pkt)
{
u16 head_pad;
u8 *dat_buf;
dat_buf = (u8 *)(pkt->data);
head_pad = ((unsigned long)dat_buf % bus->head_align);
if (head_pad) {
if (skb_headroom(pkt) < head_pad) {
bus->sdiodev->bus_if->tx_realloc++;
head_pad = 0;
if (skb_cow(pkt, head_pad))
return -ENOMEM;
}
skb_push(pkt, head_pad);
dat_buf = (u8 *)(pkt->data);
memset(dat_buf, 0, head_pad + bus->tx_hdrlen);
}
return head_pad;
}
static int brcmf_sdio_txpkt_prep_sg(struct brcmf_sdio *bus,
struct sk_buff_head *pktq,
struct sk_buff *pkt, u16 total_len)
{
struct brcmf_sdio_dev *sdiodev;
struct sk_buff *pkt_pad;
u16 tail_pad, tail_chop, chain_pad;
unsigned int blksize;
bool lastfrm;
int ntail, ret;
sdiodev = bus->sdiodev;
blksize = sdiodev->func[SDIO_FUNC_2]->cur_blksize;
WARN_ON(blksize % bus->sgentry_align);
lastfrm = skb_queue_is_last(pktq, pkt);
tail_pad = 0;
tail_chop = pkt->len % bus->sgentry_align;
if (tail_chop)
tail_pad = bus->sgentry_align - tail_chop;
chain_pad = (total_len + tail_pad) % blksize;
if (lastfrm && chain_pad)
tail_pad += blksize - chain_pad;
if (skb_tailroom(pkt) < tail_pad && pkt->len > blksize) {
pkt_pad = brcmu_pkt_buf_get_skb(tail_pad + tail_chop +
bus->head_align);
if (pkt_pad == NULL)
return -ENOMEM;
ret = brcmf_sdio_txpkt_hdalign(bus, pkt_pad);
if (unlikely(ret < 0)) {
kfree_skb(pkt_pad);
return ret;
}
memcpy(pkt_pad->data,
pkt->data + pkt->len - tail_chop,
tail_chop);
*(u16 *)(pkt_pad->cb) = ALIGN_SKB_FLAG + tail_chop;
skb_trim(pkt, pkt->len - tail_chop);
skb_trim(pkt_pad, tail_pad + tail_chop);
__skb_queue_after(pktq, pkt, pkt_pad);
} else {
ntail = pkt->data_len + tail_pad -
(pkt->end - pkt->tail);
if (skb_cloned(pkt) || ntail > 0)
if (pskb_expand_head(pkt, 0, ntail, GFP_ATOMIC))
return -ENOMEM;
if (skb_linearize(pkt))
return -ENOMEM;
__skb_put(pkt, tail_pad);
}
return tail_pad;
}
static int
brcmf_sdio_txpkt_prep(struct brcmf_sdio *bus, struct sk_buff_head *pktq,
uint chan)
{
u16 head_pad, total_len;
struct sk_buff *pkt_next;
u8 txseq;
int ret;
struct brcmf_sdio_hdrinfo hd_info = {0};
txseq = bus->tx_seq;
total_len = 0;
skb_queue_walk(pktq, pkt_next) {
if (*(u16 *)(pkt_next->cb) & ALIGN_SKB_FLAG)
continue;
ret = brcmf_sdio_txpkt_hdalign(bus, pkt_next);
if (ret < 0)
return ret;
head_pad = (u16)ret;
if (head_pad)
memset(pkt_next->data + bus->tx_hdrlen, 0, head_pad);
total_len += pkt_next->len;
hd_info.len = pkt_next->len;
hd_info.lastfrm = skb_queue_is_last(pktq, pkt_next);
if (bus->txglom && pktq->qlen > 1) {
ret = brcmf_sdio_txpkt_prep_sg(bus, pktq,
pkt_next, total_len);
if (ret < 0)
return ret;
hd_info.tail_pad = (u16)ret;
total_len += (u16)ret;
}
hd_info.channel = chan;
hd_info.dat_offset = head_pad + bus->tx_hdrlen;
hd_info.seq_num = txseq++;
brcmf_sdio_hdpack(bus, pkt_next->data, &hd_info);
if (BRCMF_BYTES_ON() &&
((BRCMF_CTL_ON() && chan == SDPCM_CONTROL_CHANNEL) ||
(BRCMF_DATA_ON() && chan != SDPCM_CONTROL_CHANNEL)))
brcmf_dbg_hex_dump(true, pkt_next->data, hd_info.len,
"Tx Frame:\n");
else if (BRCMF_HDRS_ON())
brcmf_dbg_hex_dump(true, pkt_next->data,
head_pad + bus->tx_hdrlen,
"Tx Header:\n");
}
if (bus->txglom)
brcmf_sdio_update_hwhdr(pktq->next->data, total_len);
return 0;
}
static void
brcmf_sdio_txpkt_postp(struct brcmf_sdio *bus, struct sk_buff_head *pktq)
{
u8 *hdr;
u32 dat_offset;
u16 tail_pad;
u16 dummy_flags, chop_len;
struct sk_buff *pkt_next, *tmp, *pkt_prev;
skb_queue_walk_safe(pktq, pkt_next, tmp) {
dummy_flags = *(u16 *)(pkt_next->cb);
if (dummy_flags & ALIGN_SKB_FLAG) {
chop_len = dummy_flags & ALIGN_SKB_CHOP_LEN_MASK;
if (chop_len) {
pkt_prev = pkt_next->prev;
skb_put(pkt_prev, chop_len);
}
__skb_unlink(pkt_next, pktq);
brcmu_pkt_buf_free_skb(pkt_next);
} else {
hdr = pkt_next->data + bus->tx_hdrlen - SDPCM_SWHDR_LEN;
dat_offset = le32_to_cpu(*(__le32 *)hdr);
dat_offset = (dat_offset & SDPCM_DOFFSET_MASK) >>
SDPCM_DOFFSET_SHIFT;
skb_pull(pkt_next, dat_offset);
if (bus->txglom) {
tail_pad = le16_to_cpu(*(__le16 *)(hdr - 2));
skb_trim(pkt_next, pkt_next->len - tail_pad);
}
}
}
}
static int brcmf_sdio_txpkt(struct brcmf_sdio *bus, struct sk_buff_head *pktq,
uint chan)
{
int ret;
struct sk_buff *pkt_next, *tmp;
brcmf_dbg(TRACE, "Enter\n");
ret = brcmf_sdio_txpkt_prep(bus, pktq, chan);
if (ret)
goto done;
sdio_claim_host(bus->sdiodev->func[1]);
ret = brcmf_sdiod_send_pkt(bus->sdiodev, pktq);
bus->sdcnt.f2txdata++;
if (ret < 0)
brcmf_sdio_txfail(bus);
sdio_release_host(bus->sdiodev->func[1]);
done:
brcmf_sdio_txpkt_postp(bus, pktq);
if (ret == 0)
bus->tx_seq = (bus->tx_seq + pktq->qlen) % SDPCM_SEQ_WRAP;
skb_queue_walk_safe(pktq, pkt_next, tmp) {
__skb_unlink(pkt_next, pktq);
brcmf_txcomplete(bus->sdiodev->dev, pkt_next, ret == 0);
}
return ret;
}
static uint brcmf_sdio_sendfromq(struct brcmf_sdio *bus, uint maxframes)
{
struct sk_buff *pkt;
struct sk_buff_head pktq;
u32 intstatus = 0;
int ret = 0, prec_out, i;
uint cnt = 0;
u8 tx_prec_map, pkt_num;
brcmf_dbg(TRACE, "Enter\n");
tx_prec_map = ~bus->flowcontrol;
for (cnt = 0; (cnt < maxframes) && data_ok(bus);) {
pkt_num = 1;
if (down_interruptible(&bus->tx_seq_lock))
return cnt;
if (bus->txglom)
pkt_num = min_t(u8, bus->tx_max - bus->tx_seq,
bus->sdiodev->txglomsz);
pkt_num = min_t(u32, pkt_num,
brcmu_pktq_mlen(&bus->txq, ~bus->flowcontrol));
__skb_queue_head_init(&pktq);
spin_lock_bh(&bus->txq_lock);
for (i = 0; i < pkt_num; i++) {
pkt = brcmu_pktq_mdeq(&bus->txq, tx_prec_map,
&prec_out);
if (pkt == NULL)
break;
__skb_queue_tail(&pktq, pkt);
}
spin_unlock_bh(&bus->txq_lock);
if (i == 0) {
up(&bus->tx_seq_lock);
break;
}
ret = brcmf_sdio_txpkt(bus, &pktq, SDPCM_DATA_CHANNEL);
up(&bus->tx_seq_lock);
cnt += i;
if (!bus->intr) {
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
static int brcmf_sdio_tx_ctrlframe(struct brcmf_sdio *bus, u8 *frame, u16 len)
{
u8 doff;
u16 pad;
uint retries = 0;
struct brcmf_sdio_hdrinfo hd_info = {0};
int ret;
brcmf_dbg(TRACE, "Enter\n");
frame -= bus->tx_hdrlen;
len += bus->tx_hdrlen;
doff = ((unsigned long)frame % bus->head_align);
if (doff) {
frame -= doff;
len += doff;
memset(frame + bus->tx_hdrlen, 0, doff);
}
pad = 0;
if (bus->roundup && bus->blocksize && (len > bus->blocksize)) {
pad = bus->blocksize - (len % bus->blocksize);
if ((pad > bus->roundup) || (pad >= bus->blocksize))
pad = 0;
} else if (len % bus->head_align) {
pad = bus->head_align - (len % bus->head_align);
}
len += pad;
hd_info.len = len - pad;
hd_info.channel = SDPCM_CONTROL_CHANNEL;
hd_info.dat_offset = doff + bus->tx_hdrlen;
hd_info.seq_num = bus->tx_seq;
hd_info.lastfrm = true;
hd_info.tail_pad = pad;
brcmf_sdio_hdpack(bus, frame, &hd_info);
if (bus->txglom)
brcmf_sdio_update_hwhdr(frame, len);
brcmf_dbg_hex_dump(BRCMF_BYTES_ON() && BRCMF_CTL_ON(),
frame, len, "Tx Frame:\n");
brcmf_dbg_hex_dump(!(BRCMF_BYTES_ON() && BRCMF_CTL_ON()) &&
BRCMF_HDRS_ON(),
frame, min_t(u16, len, 16), "TxHdr:\n");
do {
ret = brcmf_sdiod_send_buf(bus->sdiodev, frame, len);
if (ret < 0)
brcmf_sdio_txfail(bus);
else
bus->tx_seq = (bus->tx_seq + 1) % SDPCM_SEQ_WRAP;
} while (ret < 0 && retries++ < TXRETRIES);
return ret;
}
static void brcmf_sdio_bus_stop(struct device *dev)
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
if (bus_if->state == BRCMF_BUS_DOWN) {
sdio_claim_host(sdiodev->func[1]);
brcmf_sdio_bus_sleep(bus, false, false);
w_sdreg32(bus, 0, offsetof(struct sdpcmd_regs, hostintmask));
local_hostintmask = bus->hostintmask;
bus->hostintmask = 0;
saveclk = brcmf_sdiod_regrb(sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
&err);
if (!err)
brcmf_sdiod_regwb(sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
(saveclk | SBSDIO_FORCE_HT), &err);
if (err)
brcmf_err("Failed to force clock for F2: err %d\n",
err);
brcmf_dbg(INTR, "disable SDIO interrupts\n");
sdio_disable_func(sdiodev->func[SDIO_FUNC_2]);
w_sdreg32(bus, local_hostintmask,
offsetof(struct sdpcmd_regs, intstatus));
sdio_release_host(sdiodev->func[1]);
}
brcmu_pktq_flush(&bus->txq, true, NULL, NULL);
if (bus->glomd)
brcmu_pkt_buf_free_skb(bus->glomd);
brcmf_sdio_free_glom(bus);
spin_lock_bh(&bus->rxctl_lock);
bus->rxlen = 0;
spin_unlock_bh(&bus->rxctl_lock);
brcmf_sdio_dcmd_resp_wake(bus);
bus->rxskip = false;
bus->tx_seq = bus->rx_seq = 0;
}
static inline void brcmf_sdio_clrintr(struct brcmf_sdio *bus)
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
static void atomic_orr(int val, atomic_t *v)
{
int old_val;
old_val = atomic_read(v);
while (atomic_cmpxchg(v, old_val, val | old_val) != old_val)
old_val = atomic_read(v);
}
static int brcmf_sdio_intr_rstatus(struct brcmf_sdio *bus)
{
struct brcmf_core *buscore;
u32 addr;
unsigned long val;
int ret;
buscore = brcmf_chip_get_core(bus->ci, BCMA_CORE_SDIO_DEV);
addr = buscore->base + offsetof(struct sdpcmd_regs, intstatus);
val = brcmf_sdiod_regrl(bus->sdiodev, addr, &ret);
bus->sdcnt.f1regdata++;
if (ret != 0)
return ret;
val &= bus->hostintmask;
atomic_set(&bus->fcstate, !!(val & I_HMB_FC_STATE));
if (val) {
brcmf_sdiod_regwl(bus->sdiodev, addr, val, &ret);
bus->sdcnt.f1regdata++;
atomic_orr(val, &bus->intstatus);
}
return ret;
}
static void brcmf_sdio_dpc(struct brcmf_sdio *bus)
{
u32 newstatus = 0;
unsigned long intstatus;
uint txlimit = bus->txbound;
uint framecnt;
int err = 0;
brcmf_dbg(TRACE, "Enter\n");
sdio_claim_host(bus->sdiodev->func[1]);
if (!bus->sr_enabled && bus->clkstate == CLK_PENDING) {
u8 clkctl, devctl = 0;
#ifdef DEBUG
devctl = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
#endif
clkctl = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
brcmf_dbg(SDIO, "DPC: PENDING, devctl 0x%02x clkctl 0x%02x\n",
devctl, clkctl);
if (SBSDIO_HTAV(clkctl)) {
devctl = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_DEVICE_CTL, &err);
devctl &= ~SBSDIO_DEVCTL_CA_INT_ONLY;
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_DEVICE_CTL,
devctl, &err);
bus->clkstate = CLK_AVAIL;
}
}
brcmf_sdio_bus_sleep(bus, false, true);
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
intstatus |= brcmf_sdio_hostmail(bus);
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
if ((intstatus & I_HMB_FRAME_IND) && (bus->clkstate == CLK_AVAIL)) {
brcmf_sdio_readframes(bus, bus->rxbound);
if (!bus->rxpending)
intstatus &= ~I_HMB_FRAME_IND;
}
if (intstatus)
atomic_orr(intstatus, &bus->intstatus);
brcmf_sdio_clrintr(bus);
if (bus->ctrl_frame_stat && (bus->clkstate == CLK_AVAIL) &&
(down_interruptible(&bus->tx_seq_lock) == 0)) {
if (data_ok(bus)) {
sdio_claim_host(bus->sdiodev->func[1]);
err = brcmf_sdio_tx_ctrlframe(bus, bus->ctrl_frame_buf,
bus->ctrl_frame_len);
sdio_release_host(bus->sdiodev->func[1]);
bus->ctrl_frame_stat = false;
brcmf_sdio_wait_event_wakeup(bus);
}
up(&bus->tx_seq_lock);
}
if ((bus->clkstate == CLK_AVAIL) && !atomic_read(&bus->fcstate) &&
brcmu_pktq_mlen(&bus->txq, ~bus->flowcontrol) && txlimit &&
data_ok(bus)) {
framecnt = bus->rxpending ? min(txlimit, bus->txminmax) :
txlimit;
brcmf_sdio_sendfromq(bus, framecnt);
}
if (!brcmf_bus_ready(bus->sdiodev->bus_if) || (err != 0)) {
brcmf_err("failed backplane access over SDIO, halting operation\n");
atomic_set(&bus->intstatus, 0);
} else if (atomic_read(&bus->intstatus) ||
atomic_read(&bus->ipend) > 0 ||
(!atomic_read(&bus->fcstate) &&
brcmu_pktq_mlen(&bus->txq, ~bus->flowcontrol) &&
data_ok(bus))) {
atomic_inc(&bus->dpc_tskcnt);
}
}
static struct pktq *brcmf_sdio_bus_gettxq(struct device *dev)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
return &bus->txq;
}
static int brcmf_sdio_bus_txdata(struct device *dev, struct sk_buff *pkt)
{
int ret = -EBADE;
uint prec;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
brcmf_dbg(TRACE, "Enter: pkt: data %p len %d\n", pkt->data, pkt->len);
skb_push(pkt, bus->tx_hdrlen);
prec = prio2prec((pkt->priority & PRIOMASK));
brcmf_dbg(TRACE, "deferring pktq len %d\n", pktq_len(&bus->txq));
bus->sdcnt.fcqueued++;
spin_lock_bh(&bus->txq_lock);
*(u16 *)(pkt->cb) = 0;
if (!brcmf_c_prec_enq(bus->sdiodev->dev, &bus->txq, pkt, prec)) {
skb_pull(pkt, bus->tx_hdrlen);
brcmf_err("out of bus->txq !!!\n");
ret = -ENOSR;
} else {
ret = 0;
}
if (pktq_len(&bus->txq) >= TXHI) {
bus->txoff = true;
brcmf_txflowblock(bus->sdiodev->dev, true);
}
spin_unlock_bh(&bus->txq_lock);
#ifdef DEBUG
if (pktq_plen(&bus->txq, prec) > qcount[prec])
qcount[prec] = pktq_plen(&bus->txq, prec);
#endif
if (atomic_read(&bus->dpc_tskcnt) == 0) {
atomic_inc(&bus->dpc_tskcnt);
queue_work(bus->brcmf_wq, &bus->datawork);
}
return ret;
}
static int brcmf_sdio_readconsole(struct brcmf_sdio *bus)
{
struct brcmf_console *c = &bus->console;
u8 line[CONSOLE_LINE_MAX], ch;
u32 n, idx, addr;
int rv;
if (bus->console_addr == 0)
return 0;
addr = bus->console_addr + offsetof(struct rte_console, log_le);
rv = brcmf_sdiod_ramrw(bus->sdiodev, false, addr, (u8 *)&c->log_le,
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
rv = brcmf_sdiod_ramrw(bus->sdiodev, false, addr, c->buf, c->bufsize);
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
static int
brcmf_sdio_bus_txctl(struct device *dev, unsigned char *msg, uint msglen)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
int ret = -1;
brcmf_dbg(TRACE, "Enter\n");
if (down_interruptible(&bus->tx_seq_lock))
return -EINTR;
if (!data_ok(bus)) {
brcmf_dbg(INFO, "No bus credit bus->tx_max %d, bus->tx_seq %d\n",
bus->tx_max, bus->tx_seq);
up(&bus->tx_seq_lock);
bus->ctrl_frame_buf = msg;
bus->ctrl_frame_len = msglen;
bus->ctrl_frame_stat = true;
wait_event_interruptible_timeout(bus->ctrl_wait,
!bus->ctrl_frame_stat,
msecs_to_jiffies(2000));
if (!bus->ctrl_frame_stat) {
brcmf_dbg(SDIO, "ctrl_frame_stat == false\n");
ret = 0;
} else {
brcmf_dbg(SDIO, "ctrl_frame_stat == true\n");
bus->ctrl_frame_stat = false;
if (down_interruptible(&bus->tx_seq_lock))
return -EINTR;
ret = -1;
}
}
if (ret == -1) {
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdio_bus_sleep(bus, false, false);
ret = brcmf_sdio_tx_ctrlframe(bus, msg, msglen);
sdio_release_host(bus->sdiodev->func[1]);
up(&bus->tx_seq_lock);
}
if (ret)
bus->sdcnt.tx_ctlerrs++;
else
bus->sdcnt.tx_ctlpkts++;
return ret ? -EIO : 0;
}
static int brcmf_sdio_dump_console(struct seq_file *seq, struct brcmf_sdio *bus,
struct sdpcm_shared *sh)
{
u32 addr, console_ptr, console_size, console_index;
char *conbuf = NULL;
__le32 sh_val;
int rv;
addr = sh->console_addr + offsetof(struct rte_console, log_le);
rv = brcmf_sdiod_ramrw(bus->sdiodev, false, addr,
(u8 *)&sh_val, sizeof(u32));
if (rv < 0)
return rv;
console_ptr = le32_to_cpu(sh_val);
addr = sh->console_addr + offsetof(struct rte_console, log_le.buf_size);
rv = brcmf_sdiod_ramrw(bus->sdiodev, false, addr,
(u8 *)&sh_val, sizeof(u32));
if (rv < 0)
return rv;
console_size = le32_to_cpu(sh_val);
addr = sh->console_addr + offsetof(struct rte_console, log_le.idx);
rv = brcmf_sdiod_ramrw(bus->sdiodev, false, addr,
(u8 *)&sh_val, sizeof(u32));
if (rv < 0)
return rv;
console_index = le32_to_cpu(sh_val);
if (console_size <= CONSOLE_BUFFER_MAX)
conbuf = vzalloc(console_size+1);
if (!conbuf)
return -ENOMEM;
conbuf[console_size] = '\0';
rv = brcmf_sdiod_ramrw(bus->sdiodev, false, console_ptr, (u8 *)conbuf,
console_size);
if (rv < 0)
goto done;
rv = seq_write(seq, conbuf + console_index,
console_size - console_index);
if (rv < 0)
goto done;
if (console_index > 0)
rv = seq_write(seq, conbuf, console_index - 1);
done:
vfree(conbuf);
return rv;
}
static int brcmf_sdio_trap_info(struct seq_file *seq, struct brcmf_sdio *bus,
struct sdpcm_shared *sh)
{
int error;
struct brcmf_trap_info tr;
if ((sh->flags & SDPCM_SHARED_TRAP) == 0) {
brcmf_dbg(INFO, "no trap in firmware\n");
return 0;
}
error = brcmf_sdiod_ramrw(bus->sdiodev, false, sh->trap_addr, (u8 *)&tr,
sizeof(struct brcmf_trap_info));
if (error < 0)
return error;
seq_printf(seq,
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
return 0;
}
static int brcmf_sdio_assert_info(struct seq_file *seq, struct brcmf_sdio *bus,
struct sdpcm_shared *sh)
{
int error = 0;
char file[80] = "?";
char expr[80] = "<???>";
if ((sh->flags & SDPCM_SHARED_ASSERT_BUILT) == 0) {
brcmf_dbg(INFO, "firmware not built with -assert\n");
return 0;
} else if ((sh->flags & SDPCM_SHARED_ASSERT) == 0) {
brcmf_dbg(INFO, "no assert in dongle\n");
return 0;
}
sdio_claim_host(bus->sdiodev->func[1]);
if (sh->assert_file_addr != 0) {
error = brcmf_sdiod_ramrw(bus->sdiodev, false,
sh->assert_file_addr, (u8 *)file, 80);
if (error < 0)
return error;
}
if (sh->assert_exp_addr != 0) {
error = brcmf_sdiod_ramrw(bus->sdiodev, false,
sh->assert_exp_addr, (u8 *)expr, 80);
if (error < 0)
return error;
}
sdio_release_host(bus->sdiodev->func[1]);
seq_printf(seq, "dongle assert: %s:%d: assert(%s)\n",
file, sh->assert_line, expr);
return 0;
}
static int brcmf_sdio_checkdied(struct brcmf_sdio *bus)
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
static int brcmf_sdio_died_dump(struct seq_file *seq, struct brcmf_sdio *bus)
{
int error = 0;
struct sdpcm_shared sh;
error = brcmf_sdio_readshared(bus, &sh);
if (error < 0)
goto done;
error = brcmf_sdio_assert_info(seq, bus, &sh);
if (error < 0)
goto done;
error = brcmf_sdio_trap_info(seq, bus, &sh);
if (error < 0)
goto done;
error = brcmf_sdio_dump_console(seq, bus, &sh);
done:
return error;
}
static int brcmf_sdio_forensic_read(struct seq_file *seq, void *data)
{
struct brcmf_bus *bus_if = dev_get_drvdata(seq->private);
struct brcmf_sdio *bus = bus_if->bus_priv.sdio->bus;
return brcmf_sdio_died_dump(seq, bus);
}
static int brcmf_debugfs_sdio_count_read(struct seq_file *seq, void *data)
{
struct brcmf_bus *bus_if = dev_get_drvdata(seq->private);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio_count *sdcnt = &sdiodev->bus->sdcnt;
seq_printf(seq,
"intrcount: %u\nlastintrs: %u\n"
"pollcnt: %u\nregfails: %u\n"
"tx_sderrs: %u\nfcqueued: %u\n"
"rxrtx: %u\nrx_toolong: %u\n"
"rxc_errors: %u\nrx_hdrfail: %u\n"
"rx_badhdr: %u\nrx_badseq: %u\n"
"fc_rcvd: %u\nfc_xoff: %u\n"
"fc_xon: %u\nrxglomfail: %u\n"
"rxglomframes: %u\nrxglompkts: %u\n"
"f2rxhdrs: %u\nf2rxdata: %u\n"
"f2txdata: %u\nf1regdata: %u\n"
"tickcnt: %u\ntx_ctlerrs: %lu\n"
"tx_ctlpkts: %lu\nrx_ctlerrs: %lu\n"
"rx_ctlpkts: %lu\nrx_readahead: %lu\n",
sdcnt->intrcount, sdcnt->lastintrs,
sdcnt->pollcnt, sdcnt->regfails,
sdcnt->tx_sderrs, sdcnt->fcqueued,
sdcnt->rxrtx, sdcnt->rx_toolong,
sdcnt->rxc_errors, sdcnt->rx_hdrfail,
sdcnt->rx_badhdr, sdcnt->rx_badseq,
sdcnt->fc_rcvd, sdcnt->fc_xoff,
sdcnt->fc_xon, sdcnt->rxglomfail,
sdcnt->rxglomframes, sdcnt->rxglompkts,
sdcnt->f2rxhdrs, sdcnt->f2rxdata,
sdcnt->f2txdata, sdcnt->f1regdata,
sdcnt->tickcnt, sdcnt->tx_ctlerrs,
sdcnt->tx_ctlpkts, sdcnt->rx_ctlerrs,
sdcnt->rx_ctlpkts, sdcnt->rx_readahead_cnt);
return 0;
}
static void brcmf_sdio_debugfs_create(struct brcmf_sdio *bus)
{
struct brcmf_pub *drvr = bus->sdiodev->bus_if->drvr;
struct dentry *dentry = brcmf_debugfs_get_devdir(drvr);
if (IS_ERR_OR_NULL(dentry))
return;
brcmf_debugfs_add_entry(drvr, "forensics", brcmf_sdio_forensic_read);
brcmf_debugfs_add_entry(drvr, "counters",
brcmf_debugfs_sdio_count_read);
debugfs_create_u32("console_interval", 0644, dentry,
&bus->console_interval);
}
static int brcmf_sdio_checkdied(struct brcmf_sdio *bus)
{
return 0;
}
static void brcmf_sdio_debugfs_create(struct brcmf_sdio *bus)
{
}
static int
brcmf_sdio_bus_rxctl(struct device *dev, unsigned char *msg, uint msglen)
{
int timeleft;
uint rxlen = 0;
bool pending;
u8 *buf;
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
brcmf_dbg(TRACE, "Enter\n");
timeleft = brcmf_sdio_dcmd_resp_wait(bus, &bus->rxlen, &pending);
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
brcmf_sdio_checkdied(bus);
} else if (pending) {
brcmf_dbg(CTL, "cancelled\n");
return -ERESTARTSYS;
} else {
brcmf_dbg(CTL, "resumed for unknown reason?\n");
brcmf_sdio_checkdied(bus);
}
if (rxlen)
bus->sdcnt.rx_ctlpkts++;
else
bus->sdcnt.rx_ctlerrs++;
return rxlen ? (int)rxlen : -ETIMEDOUT;
}
static bool
brcmf_sdio_verifymemory(struct brcmf_sdio_dev *sdiodev, u32 ram_addr,
u8 *ram_data, uint ram_sz)
{
char *ram_cmp;
int err;
bool ret = true;
int address;
int offset;
int len;
brcmf_dbg(INFO, "Compare RAM dl & ul at 0x%08x; size=%d\n", ram_addr,
ram_sz);
ram_cmp = kmalloc(MEMBLOCK, GFP_KERNEL);
if (!ram_cmp)
return true;
address = ram_addr;
offset = 0;
while (offset < ram_sz) {
len = ((offset + MEMBLOCK) < ram_sz) ? MEMBLOCK :
ram_sz - offset;
err = brcmf_sdiod_ramrw(sdiodev, false, address, ram_cmp, len);
if (err) {
brcmf_err("error %d on reading %d membytes at 0x%08x\n",
err, len, address);
ret = false;
break;
} else if (memcmp(ram_cmp, &ram_data[offset], len)) {
brcmf_err("Downloaded RAM image is corrupted, block offset is %d, len is %d\n",
offset, len);
ret = false;
break;
}
offset += len;
address += len;
}
kfree(ram_cmp);
return ret;
}
static bool
brcmf_sdio_verifymemory(struct brcmf_sdio_dev *sdiodev, u32 ram_addr,
u8 *ram_data, uint ram_sz)
{
return true;
}
static int brcmf_sdio_download_code_file(struct brcmf_sdio *bus,
const struct firmware *fw)
{
int err;
brcmf_dbg(TRACE, "Enter\n");
err = brcmf_sdiod_ramrw(bus->sdiodev, true, bus->ci->rambase,
(u8 *)fw->data, fw->size);
if (err)
brcmf_err("error %d on writing %d membytes at 0x%08x\n",
err, (int)fw->size, bus->ci->rambase);
else if (!brcmf_sdio_verifymemory(bus->sdiodev, bus->ci->rambase,
(u8 *)fw->data, fw->size))
err = -EIO;
return err;
}
static int brcmf_sdio_download_nvram(struct brcmf_sdio *bus,
void *vars, u32 varsz)
{
int address;
int err;
brcmf_dbg(TRACE, "Enter\n");
address = bus->ci->ramsize - varsz + bus->ci->rambase;
err = brcmf_sdiod_ramrw(bus->sdiodev, true, address, vars, varsz);
if (err)
brcmf_err("error %d on writing %d nvram bytes at 0x%08x\n",
err, varsz, address);
else if (!brcmf_sdio_verifymemory(bus->sdiodev, address, vars, varsz))
err = -EIO;
return err;
}
static int brcmf_sdio_download_firmware(struct brcmf_sdio *bus,
const struct firmware *fw,
void *nvram, u32 nvlen)
{
int bcmerror = -EFAULT;
u32 rstvec;
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdio_clkctl(bus, CLK_AVAIL, false);
brcmf_chip_enter_download(bus->ci);
rstvec = get_unaligned_le32(fw->data);
brcmf_dbg(SDIO, "firmware rstvec: %x\n", rstvec);
bcmerror = brcmf_sdio_download_code_file(bus, fw);
release_firmware(fw);
if (bcmerror) {
brcmf_err("dongle image file download failed\n");
brcmf_fw_nvram_free(nvram);
goto err;
}
bcmerror = brcmf_sdio_download_nvram(bus, nvram, nvlen);
brcmf_fw_nvram_free(nvram);
if (bcmerror) {
brcmf_err("dongle nvram file download failed\n");
goto err;
}
if (!brcmf_chip_exit_download(bus->ci, rstvec)) {
brcmf_err("error getting out of ARM core reset\n");
goto err;
}
brcmf_bus_change_state(bus->sdiodev->bus_if, BRCMF_BUS_LOAD);
bcmerror = 0;
err:
brcmf_sdio_clkctl(bus, CLK_SDONLY, false);
sdio_release_host(bus->sdiodev->func[1]);
return bcmerror;
}
static void brcmf_sdio_sr_init(struct brcmf_sdio *bus)
{
int err = 0;
u8 val;
brcmf_dbg(TRACE, "Enter\n");
val = brcmf_sdiod_regrb(bus->sdiodev, SBSDIO_FUNC1_WAKEUPCTRL, &err);
if (err) {
brcmf_err("error reading SBSDIO_FUNC1_WAKEUPCTRL\n");
return;
}
val |= 1 << SBSDIO_FUNC1_WCTRL_HTWAIT_SHIFT;
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_WAKEUPCTRL, val, &err);
if (err) {
brcmf_err("error writing SBSDIO_FUNC1_WAKEUPCTRL\n");
return;
}
brcmf_sdiod_regwb(bus->sdiodev, SDIO_CCCR_BRCM_CARDCAP,
(SDIO_CCCR_BRCM_CARDCAP_CMD14_SUPPORT |
SDIO_CCCR_BRCM_CARDCAP_CMD14_EXT),
&err);
if (err) {
brcmf_err("error writing SDIO_CCCR_BRCM_CARDCAP\n");
return;
}
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
SBSDIO_FORCE_HT, &err);
if (err) {
brcmf_err("error writing SBSDIO_FUNC1_CHIPCLKCSR\n");
return;
}
bus->sr_enabled = true;
brcmf_dbg(INFO, "SR enabled\n");
}
static int brcmf_sdio_kso_init(struct brcmf_sdio *bus)
{
u8 val;
int err = 0;
brcmf_dbg(TRACE, "Enter\n");
if (brcmf_chip_get_core(bus->ci, BCMA_CORE_SDIO_DEV)->rev < 12)
return 0;
val = brcmf_sdiod_regrb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR, &err);
if (err) {
brcmf_err("error reading SBSDIO_FUNC1_SLEEPCSR\n");
return err;
}
if (!(val & SBSDIO_FUNC1_SLEEPCSR_KSO_MASK)) {
val |= (SBSDIO_FUNC1_SLEEPCSR_KSO_EN <<
SBSDIO_FUNC1_SLEEPCSR_KSO_SHIFT);
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_SLEEPCSR,
val, &err);
if (err) {
brcmf_err("error writing SBSDIO_FUNC1_SLEEPCSR\n");
return err;
}
}
return 0;
}
static int brcmf_sdio_bus_preinit(struct device *dev)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
uint pad_size;
u32 value;
int err;
if (brcmf_chip_get_core(bus->ci, BCMA_CORE_SDIO_DEV)->rev < 12) {
value = 0;
err = brcmf_iovar_data_set(dev, "bus:txglom", &value,
sizeof(u32));
} else {
value = 4;
if (sdiodev->pdata)
value = sdiodev->pdata->sd_sgentry_align;
value = max_t(u32, value, 4);
err = brcmf_iovar_data_set(dev, "bus:txglomalign", &value,
sizeof(u32));
}
if (err < 0)
goto done;
bus->tx_hdrlen = SDPCM_HWHDR_LEN + SDPCM_SWHDR_LEN;
if (sdiodev->sg_support) {
bus->txglom = false;
value = 1;
pad_size = bus->sdiodev->func[2]->cur_blksize << 1;
err = brcmf_iovar_data_set(bus->sdiodev->dev, "bus:rxglom",
&value, sizeof(u32));
if (err < 0) {
err = 0;
} else {
bus->txglom = true;
bus->tx_hdrlen += SDPCM_HWEXT_LEN;
}
}
brcmf_bus_add_txhdrlen(bus->sdiodev->dev, bus->tx_hdrlen);
done:
return err;
}
void brcmf_sdio_isr(struct brcmf_sdio *bus)
{
brcmf_dbg(TRACE, "Enter\n");
if (!bus) {
brcmf_err("bus is null pointer, exiting\n");
return;
}
if (!brcmf_bus_ready(bus->sdiodev->bus_if)) {
brcmf_err("bus is down. we have nothing to do\n");
return;
}
bus->sdcnt.intrcount++;
if (in_interrupt())
atomic_set(&bus->ipend, 1);
else
if (brcmf_sdio_intr_rstatus(bus)) {
brcmf_err("failed backplane access\n");
}
if (!bus->intr)
brcmf_err("isr w/o interrupt configured!\n");
atomic_inc(&bus->dpc_tskcnt);
queue_work(bus->brcmf_wq, &bus->datawork);
}
static bool brcmf_sdio_bus_watchdog(struct brcmf_sdio *bus)
{
#ifdef DEBUG
struct brcmf_bus *bus_if = dev_get_drvdata(bus->sdiodev->dev);
#endif
brcmf_dbg(TIMER, "Enter\n");
if (!bus->sr_enabled &&
bus->poll && (++bus->polltick >= bus->pollrate)) {
u32 intstatus = 0;
bus->polltick = 0;
if (!bus->intr ||
(bus->sdcnt.intrcount == bus->sdcnt.lastintrs)) {
if (atomic_read(&bus->dpc_tskcnt) == 0) {
u8 devpend;
sdio_claim_host(bus->sdiodev->func[1]);
devpend = brcmf_sdiod_regrb(bus->sdiodev,
SDIO_CCCR_INTx,
NULL);
sdio_release_host(bus->sdiodev->func[1]);
intstatus =
devpend & (INTR_STATUS_FUNC1 |
INTR_STATUS_FUNC2);
}
if (intstatus) {
bus->sdcnt.pollcnt++;
atomic_set(&bus->ipend, 1);
atomic_inc(&bus->dpc_tskcnt);
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
brcmf_sdio_bus_sleep(bus, false, false);
if (brcmf_sdio_readconsole(bus) < 0)
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
brcmf_sdio_wd_timer(bus, BRCMF_WD_POLL_MS);
} else {
brcmf_dbg(SDIO, "idle\n");
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdio_bus_sleep(bus, true, false);
sdio_release_host(bus->sdiodev->func[1]);
}
}
}
return (atomic_read(&bus->ipend) > 0);
}
static void brcmf_sdio_dataworker(struct work_struct *work)
{
struct brcmf_sdio *bus = container_of(work, struct brcmf_sdio,
datawork);
while (atomic_read(&bus->dpc_tskcnt)) {
atomic_set(&bus->dpc_tskcnt, 0);
brcmf_sdio_dpc(bus);
}
}
static void
brcmf_sdio_drivestrengthinit(struct brcmf_sdio_dev *sdiodev,
struct brcmf_chip *ci, u32 drivestrength)
{
const struct sdiod_drive_str *str_tab = NULL;
u32 str_mask;
u32 str_shift;
u32 base;
u32 i;
u32 drivestrength_sel = 0;
u32 cc_data_temp;
u32 addr;
if (!(ci->cc_caps & CC_CAP_PMU))
return;
switch (SDIOD_DRVSTR_KEY(ci->chip, ci->pmurev)) {
case SDIOD_DRVSTR_KEY(BRCM_CC_4330_CHIP_ID, 12):
str_tab = sdiod_drvstr_tab1_1v8;
str_mask = 0x00003800;
str_shift = 11;
break;
case SDIOD_DRVSTR_KEY(BRCM_CC_4334_CHIP_ID, 17):
str_tab = sdiod_drvstr_tab6_1v8;
str_mask = 0x00001800;
str_shift = 11;
break;
case SDIOD_DRVSTR_KEY(BRCM_CC_43143_CHIP_ID, 17):
i = ARRAY_SIZE(sdiod_drvstr_tab2_3v3) - 1;
if (drivestrength >= sdiod_drvstr_tab2_3v3[i].strength) {
str_tab = sdiod_drvstr_tab2_3v3;
str_mask = 0x00000007;
str_shift = 0;
} else
brcmf_err("Invalid SDIO Drive strength for chip %s, strength=%d\n",
ci->name, drivestrength);
break;
case SDIOD_DRVSTR_KEY(BRCM_CC_43362_CHIP_ID, 13):
str_tab = sdiod_drive_strength_tab5_1v8;
str_mask = 0x00003800;
str_shift = 11;
break;
default:
brcmf_err("No SDIO Drive strength init done for chip %s rev %d pmurev %d\n",
ci->name, ci->chiprev, ci->pmurev);
break;
}
if (str_tab != NULL) {
for (i = 0; str_tab[i].strength != 0; i++) {
if (drivestrength >= str_tab[i].strength) {
drivestrength_sel = str_tab[i].sel;
break;
}
}
base = brcmf_chip_get_chipcommon(ci)->base;
addr = CORE_CC_REG(base, chipcontrol_addr);
brcmf_sdiod_regwl(sdiodev, addr, 1, NULL);
cc_data_temp = brcmf_sdiod_regrl(sdiodev, addr, NULL);
cc_data_temp &= ~str_mask;
drivestrength_sel <<= str_shift;
cc_data_temp |= drivestrength_sel;
brcmf_sdiod_regwl(sdiodev, addr, cc_data_temp, NULL);
brcmf_dbg(INFO, "SDIO: %d mA (req=%d mA) drive strength selected, set to 0x%08x\n",
str_tab[i].strength, drivestrength, cc_data_temp);
}
}
static int brcmf_sdio_buscoreprep(void *ctx)
{
struct brcmf_sdio_dev *sdiodev = ctx;
int err = 0;
u8 clkval, clkset;
clkset = SBSDIO_FORCE_HW_CLKREQ_OFF | SBSDIO_ALP_AVAIL_REQ;
brcmf_sdiod_regwb(sdiodev, SBSDIO_FUNC1_CHIPCLKCSR, clkset, &err);
if (err) {
brcmf_err("error writing for HT off\n");
return err;
}
clkval = brcmf_sdiod_regrb(sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, NULL);
if ((clkval & ~SBSDIO_AVBITS) != clkset) {
brcmf_err("ChipClkCSR access: wrote 0x%02x read 0x%02x\n",
clkset, clkval);
return -EACCES;
}
SPINWAIT(((clkval = brcmf_sdiod_regrb(sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, NULL)),
!SBSDIO_ALPAV(clkval)),
PMU_MAX_TRANSITION_DLY);
if (!SBSDIO_ALPAV(clkval)) {
brcmf_err("timeout on ALPAV wait, clkval 0x%02x\n",
clkval);
return -EBUSY;
}
clkset = SBSDIO_FORCE_HW_CLKREQ_OFF | SBSDIO_FORCE_ALP;
brcmf_sdiod_regwb(sdiodev, SBSDIO_FUNC1_CHIPCLKCSR, clkset, &err);
udelay(65);
brcmf_sdiod_regwb(sdiodev, SBSDIO_FUNC1_SDIOPULLUP, 0, NULL);
return 0;
}
static void brcmf_sdio_buscore_exitdl(void *ctx, struct brcmf_chip *chip,
u32 rstvec)
{
struct brcmf_sdio_dev *sdiodev = ctx;
struct brcmf_core *core;
u32 reg_addr;
core = brcmf_chip_get_core(chip, BCMA_CORE_SDIO_DEV);
reg_addr = core->base + offsetof(struct sdpcmd_regs, intstatus);
brcmf_sdiod_regwl(sdiodev, reg_addr, 0xFFFFFFFF, NULL);
if (rstvec)
brcmf_sdiod_ramrw(sdiodev, true, 0, (void *)&rstvec,
sizeof(rstvec));
}
static u32 brcmf_sdio_buscore_read32(void *ctx, u32 addr)
{
struct brcmf_sdio_dev *sdiodev = ctx;
u32 val, rev;
val = brcmf_sdiod_regrl(sdiodev, addr, NULL);
if (sdiodev->func[0]->device == BRCM_SDIO_4335_4339_DEVICE_ID &&
addr == CORE_CC_REG(SI_ENUM_BASE, chipid)) {
rev = (val & CID_REV_MASK) >> CID_REV_SHIFT;
if (rev >= 2) {
val &= ~CID_ID_MASK;
val |= BRCM_CC_4339_CHIP_ID;
}
}
return val;
}
static void brcmf_sdio_buscore_write32(void *ctx, u32 addr, u32 val)
{
struct brcmf_sdio_dev *sdiodev = ctx;
brcmf_sdiod_regwl(sdiodev, addr, val, NULL);
}
static bool
brcmf_sdio_probe_attach(struct brcmf_sdio *bus)
{
u8 clkctl = 0;
int err = 0;
int reg_addr;
u32 reg_val;
u32 drivestrength;
sdio_claim_host(bus->sdiodev->func[1]);
pr_debug("F1 signature read @0x18000000=0x%4x\n",
brcmf_sdiod_regrl(bus->sdiodev, SI_ENUM_BASE, NULL));
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
BRCMF_INIT_CLKCTL1, &err);
if (!err)
clkctl = brcmf_sdiod_regrb(bus->sdiodev,
SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (err || ((clkctl & ~SBSDIO_AVBITS) != BRCMF_INIT_CLKCTL1)) {
brcmf_err("ChipClkCSR access: err %d wrote 0x%02x read 0x%02x\n",
err, BRCMF_INIT_CLKCTL1, clkctl);
goto fail;
}
brcmf_bus_change_state(bus->sdiodev->bus_if, BRCMF_BUS_DOWN);
bus->ci = brcmf_chip_attach(bus->sdiodev, &brcmf_sdio_buscore_ops);
if (IS_ERR(bus->ci)) {
brcmf_err("brcmf_chip_attach failed!\n");
bus->ci = NULL;
goto fail;
}
if (brcmf_sdio_kso_init(bus)) {
brcmf_err("error enabling KSO\n");
goto fail;
}
if ((bus->sdiodev->pdata) && (bus->sdiodev->pdata->drive_strength))
drivestrength = bus->sdiodev->pdata->drive_strength;
else
drivestrength = DEFAULT_SDIO_DRIVE_STRENGTH;
brcmf_sdio_drivestrengthinit(bus->sdiodev, bus->ci, drivestrength);
bus->ramsize = bus->ci->ramsize;
if (!(bus->ramsize)) {
brcmf_err("failed to find SOCRAM memory!\n");
goto fail;
}
reg_val = brcmf_sdiod_regrb(bus->sdiodev,
SDIO_CCCR_BRCM_CARDCTRL, &err);
if (err)
goto fail;
reg_val |= SDIO_CCCR_BRCM_CARDCTRL_WLANRESET;
brcmf_sdiod_regwb(bus->sdiodev,
SDIO_CCCR_BRCM_CARDCTRL, reg_val, &err);
if (err)
goto fail;
reg_addr = CORE_CC_REG(brcmf_chip_get_chipcommon(bus->ci)->base,
pmucontrol);
reg_val = brcmf_sdiod_regrl(bus->sdiodev, reg_addr, &err);
if (err)
goto fail;
reg_val |= (BCMA_CC_PMU_CTL_RES_RELOAD << BCMA_CC_PMU_CTL_RES_SHIFT);
brcmf_sdiod_regwl(bus->sdiodev, reg_addr, reg_val, &err);
if (err)
goto fail;
sdio_release_host(bus->sdiodev->func[1]);
brcmu_pktq_init(&bus->txq, (PRIOMASK + 1), TXQLEN);
bus->hdrbuf = kzalloc(MAX_HDR_READ + bus->head_align, GFP_KERNEL);
if (!bus->hdrbuf)
return false;
bus->rxhdr = (u8 *) roundup((unsigned long)&bus->hdrbuf[0],
bus->head_align);
bus->intr = true;
bus->poll = false;
if (bus->poll)
bus->pollrate = 1;
return true;
fail:
sdio_release_host(bus->sdiodev->func[1]);
return false;
}
static int
brcmf_sdio_watchdog_thread(void *data)
{
struct brcmf_sdio *bus = (struct brcmf_sdio *)data;
allow_signal(SIGTERM);
while (1) {
if (kthread_should_stop())
break;
if (!wait_for_completion_interruptible(&bus->watchdog_wait)) {
brcmf_sdio_bus_watchdog(bus);
bus->sdcnt.tickcnt++;
reinit_completion(&bus->watchdog_wait);
} else
break;
}
return 0;
}
static void
brcmf_sdio_watchdog(unsigned long data)
{
struct brcmf_sdio *bus = (struct brcmf_sdio *)data;
if (bus->watchdog_tsk) {
complete(&bus->watchdog_wait);
if (bus->wd_timer_valid)
mod_timer(&bus->timer,
jiffies + BRCMF_WD_POLL_MS * HZ / 1000);
}
}
static void brcmf_sdio_firmware_callback(struct device *dev,
const struct firmware *code,
void *nvram, u32 nvram_len)
{
struct brcmf_bus *bus_if = dev_get_drvdata(dev);
struct brcmf_sdio_dev *sdiodev = bus_if->bus_priv.sdio;
struct brcmf_sdio *bus = sdiodev->bus;
int err = 0;
u8 saveclk;
brcmf_dbg(TRACE, "Enter: dev=%s\n", dev_name(dev));
if (bus_if->state == BRCMF_BUS_DOWN) {
bus->alp_only = true;
err = brcmf_sdio_download_firmware(bus, code, nvram, nvram_len);
if (err)
goto fail;
bus->alp_only = false;
}
if (!bus_if->drvr)
return;
bus->sdcnt.tickcnt = 0;
brcmf_sdio_wd_timer(bus, BRCMF_WD_POLL_MS);
sdio_claim_host(sdiodev->func[1]);
brcmf_sdio_clkctl(bus, CLK_AVAIL, false);
if (bus->clkstate != CLK_AVAIL)
goto release;
saveclk = brcmf_sdiod_regrb(sdiodev, SBSDIO_FUNC1_CHIPCLKCSR, &err);
if (!err) {
brcmf_sdiod_regwb(sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
(saveclk | SBSDIO_FORCE_HT), &err);
}
if (err) {
brcmf_err("Failed to force clock for F2: err %d\n", err);
goto release;
}
w_sdreg32(bus, SDPCM_PROT_VERSION << SMB_DATA_VERSION_SHIFT,
offsetof(struct sdpcmd_regs, tosbmailboxdata));
err = sdio_enable_func(sdiodev->func[SDIO_FUNC_2]);
brcmf_dbg(INFO, "enable F2: err=%d\n", err);
if (!err) {
bus->hostintmask = HOSTINTMASK;
w_sdreg32(bus, bus->hostintmask,
offsetof(struct sdpcmd_regs, hostintmask));
brcmf_sdiod_regwb(sdiodev, SBSDIO_WATERMARK, 8, &err);
} else {
sdio_disable_func(sdiodev->func[SDIO_FUNC_2]);
goto release;
}
if (brcmf_chip_sr_capable(bus->ci)) {
brcmf_sdio_sr_init(bus);
} else {
brcmf_sdiod_regwb(sdiodev, SBSDIO_FUNC1_CHIPCLKCSR,
saveclk, &err);
}
if (err == 0) {
err = brcmf_sdiod_intr_register(sdiodev);
if (err != 0)
brcmf_err("intr register failed:%d\n", err);
}
if (err != 0)
brcmf_sdio_clkctl(bus, CLK_NONE, false);
sdio_release_host(sdiodev->func[1]);
err = brcmf_bus_start(dev);
if (err != 0) {
brcmf_err("dongle is not responding\n");
goto fail;
}
return;
release:
sdio_release_host(sdiodev->func[1]);
fail:
brcmf_dbg(TRACE, "failed: dev=%s, err=%d\n", dev_name(dev), err);
device_release_driver(dev);
}
struct brcmf_sdio *brcmf_sdio_probe(struct brcmf_sdio_dev *sdiodev)
{
int ret;
struct brcmf_sdio *bus;
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
bus->tx_seq = SDPCM_SEQ_WRAP - 1;
bus->head_align = ALIGNMENT;
bus->sgentry_align = ALIGNMENT;
if (sdiodev->pdata) {
if (sdiodev->pdata->sd_head_align > ALIGNMENT)
bus->head_align = sdiodev->pdata->sd_head_align;
if (sdiodev->pdata->sd_sgentry_align > ALIGNMENT)
bus->sgentry_align = sdiodev->pdata->sd_sgentry_align;
}
INIT_WORK(&bus->datawork, brcmf_sdio_dataworker);
bus->brcmf_wq = create_singlethread_workqueue("brcmf_wq");
if (bus->brcmf_wq == NULL) {
brcmf_err("insufficient memory to create txworkqueue\n");
goto fail;
}
if (!(brcmf_sdio_probe_attach(bus))) {
brcmf_err("brcmf_sdio_probe_attach failed\n");
goto fail;
}
spin_lock_init(&bus->rxctl_lock);
spin_lock_init(&bus->txq_lock);
sema_init(&bus->tx_seq_lock, 1);
init_waitqueue_head(&bus->ctrl_wait);
init_waitqueue_head(&bus->dcmd_resp_wait);
init_timer(&bus->timer);
bus->timer.data = (unsigned long)bus;
bus->timer.function = brcmf_sdio_watchdog;
init_completion(&bus->watchdog_wait);
bus->watchdog_tsk = kthread_run(brcmf_sdio_watchdog_thread,
bus, "brcmf_watchdog");
if (IS_ERR(bus->watchdog_tsk)) {
pr_warn("brcmf_watchdog thread failed to start\n");
bus->watchdog_tsk = NULL;
}
atomic_set(&bus->dpc_tskcnt, 0);
bus->sdiodev->bus_if->dev = bus->sdiodev->dev;
bus->sdiodev->bus_if->ops = &brcmf_sdio_bus_ops;
bus->sdiodev->bus_if->chip = bus->ci->chip;
bus->sdiodev->bus_if->chiprev = bus->ci->chiprev;
bus->tx_hdrlen = SDPCM_HWHDR_LEN + SDPCM_SWHDR_LEN;
ret = brcmf_attach(bus->sdiodev->dev);
if (ret != 0) {
brcmf_err("brcmf_attach failed\n");
goto fail;
}
bus->blocksize = bus->sdiodev->func[2]->cur_blksize;
bus->roundup = min(max_roundup, bus->blocksize);
if (bus->sdiodev->bus_if->maxctl) {
bus->sdiodev->bus_if->maxctl += bus->roundup;
bus->rxblen =
roundup((bus->sdiodev->bus_if->maxctl + SDPCM_HDRLEN),
ALIGNMENT) + bus->head_align;
bus->rxbuf = kmalloc(bus->rxblen, GFP_ATOMIC);
if (!(bus->rxbuf)) {
brcmf_err("rxbuf allocation failed\n");
goto fail;
}
}
sdio_claim_host(bus->sdiodev->func[1]);
sdio_disable_func(bus->sdiodev->func[SDIO_FUNC_2]);
bus->rxflow = false;
brcmf_sdiod_regwb(bus->sdiodev, SBSDIO_FUNC1_CHIPCLKCSR, 0, NULL);
sdio_release_host(bus->sdiodev->func[1]);
bus->clkstate = CLK_SDONLY;
bus->idletime = BRCMF_IDLE_INTERVAL;
bus->idleclock = BRCMF_IDLE_ACTIVE;
bus->sleeping = false;
bus->sr_enabled = false;
brcmf_sdio_debugfs_create(bus);
brcmf_dbg(INFO, "completed!!\n");
ret = brcmf_sdio_get_fwnames(bus->ci, sdiodev);
if (ret)
goto fail;
ret = brcmf_fw_get_firmwares(sdiodev->dev, BRCMF_FW_REQUEST_NVRAM,
sdiodev->fw_name, sdiodev->nvram_name,
brcmf_sdio_firmware_callback);
if (ret != 0) {
brcmf_err("async firmware request failed: %d\n", ret);
goto fail;
}
return bus;
fail:
brcmf_sdio_remove(bus);
return NULL;
}
void brcmf_sdio_remove(struct brcmf_sdio *bus)
{
brcmf_dbg(TRACE, "Enter\n");
if (bus) {
brcmf_sdiod_intr_unregister(bus->sdiodev);
brcmf_detach(bus->sdiodev->dev);
cancel_work_sync(&bus->datawork);
if (bus->brcmf_wq)
destroy_workqueue(bus->brcmf_wq);
if (bus->ci) {
if (bus->sdiodev->bus_if->state == BRCMF_BUS_DOWN) {
sdio_claim_host(bus->sdiodev->func[1]);
brcmf_sdio_clkctl(bus, CLK_AVAIL, false);
msleep(20);
brcmf_chip_enter_download(bus->ci);
brcmf_sdio_clkctl(bus, CLK_NONE, false);
sdio_release_host(bus->sdiodev->func[1]);
}
brcmf_chip_detach(bus->ci);
}
kfree(bus->rxbuf);
kfree(bus->hdrbuf);
kfree(bus);
}
brcmf_dbg(TRACE, "Disconnected\n");
}
void brcmf_sdio_wd_timer(struct brcmf_sdio *bus, uint wdtick)
{
if (!wdtick && bus->wd_timer_valid) {
del_timer_sync(&bus->timer);
bus->wd_timer_valid = false;
bus->save_ms = wdtick;
return;
}
if (bus->sdiodev->bus_if->state != BRCMF_BUS_DATA)
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
