static int qib_ibsd_ucode_loaded(struct qib_pportdata *ppd,
const struct firmware *fw)
{
struct qib_devdata *dd = ppd->dd;
if (!dd->cspec->serdes_first_init_done &&
qib_sd7220_ib_vfy(dd, fw) > 0)
dd->cspec->serdes_first_init_done = 1;
return dd->cspec->serdes_first_init_done;
}
void qib_sd7220_clr_ibpar(struct qib_devdata *dd)
{
int ret;
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, IB_MPREG6,
UC_PAR_CLR_D, UC_PAR_CLR_M);
if (ret < 0) {
qib_dev_err(dd, "Failed clearing IBSerDes Parity err\n");
goto bail;
}
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, IB_MPREG6, 0,
UC_PAR_CLR_M);
qib_read_kreg32(dd, kr_scratch);
udelay(4);
qib_write_kreg(dd, kr_hwerrclear,
QLOGIC_IB_HWE_IB_UC_MEMORYPARITYERR);
qib_read_kreg32(dd, kr_scratch);
bail:
return;
}
static int qib_resync_ibepb(struct qib_devdata *dd)
{
int ret, pat, tries, chn;
u32 loc;
ret = -1;
chn = 0;
for (tries = 0; tries < (4 * IBSD_RESYNC_TRIES); ++tries) {
loc = IB_PGUDP(chn);
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, loc, 0, 0);
if (ret < 0) {
qib_dev_err(dd, "Failed read in resync\n");
continue;
}
if (ret != 0xF0 && ret != 0x55 && tries == 0)
qib_dev_err(dd, "unexpected pattern in resync\n");
pat = ret ^ 0xA5;
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, loc, pat, 0xFF);
if (ret < 0) {
qib_dev_err(dd, "Failed write in resync\n");
continue;
}
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, loc, 0, 0);
if (ret < 0) {
qib_dev_err(dd, "Failed re-read in resync\n");
continue;
}
if (ret != pat) {
qib_dev_err(dd, "Failed compare1 in resync\n");
continue;
}
loc = IB_CMUDONE(chn);
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, loc, 0, 0);
if (ret < 0) {
qib_dev_err(dd, "Failed CMUDONE rd in resync\n");
continue;
}
if ((ret & 0x70) != ((chn << 4) | 0x40)) {
qib_dev_err(dd, "Bad CMUDONE value %02X, chn %d\n",
ret, chn);
continue;
}
if (++chn == 4)
break;
}
return (ret > 0) ? 0 : ret;
}
static int qib_ibsd_reset(struct qib_devdata *dd, int assert_rst)
{
u64 rst_val;
int ret = 0;
unsigned long flags;
rst_val = qib_read_kreg64(dd, kr_ibserdesctrl);
if (assert_rst) {
spin_lock_irqsave(&dd->cspec->sdepb_lock, flags);
epb_access(dd, IB_7220_SERDES, 1);
rst_val |= 1ULL;
qib_write_kreg(dd, kr_hwerrmask,
dd->cspec->hwerrmask &
~QLOGIC_IB_HWE_IB_UC_MEMORYPARITYERR);
qib_write_kreg(dd, kr_ibserdesctrl, rst_val);
qib_read_kreg32(dd, kr_scratch);
udelay(2);
epb_access(dd, IB_7220_SERDES, -1);
spin_unlock_irqrestore(&dd->cspec->sdepb_lock, flags);
} else {
u64 val;
rst_val &= ~(1ULL);
qib_write_kreg(dd, kr_hwerrmask,
dd->cspec->hwerrmask &
~QLOGIC_IB_HWE_IB_UC_MEMORYPARITYERR);
ret = qib_resync_ibepb(dd);
if (ret < 0)
qib_dev_err(dd, "unable to re-sync IB EPB\n");
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, IB_MPREG5, 1, 1);
if (ret < 0)
goto bail;
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, IB_MPREG6, 0x80,
0x80);
if (ret < 0) {
qib_dev_err(dd, "Failed to set WDOG disable\n");
goto bail;
}
qib_write_kreg(dd, kr_ibserdesctrl, rst_val);
qib_read_kreg32(dd, kr_scratch);
udelay(1);
qib_sd7220_clr_ibpar(dd);
val = qib_read_kreg64(dd, kr_hwerrstatus);
if (val & QLOGIC_IB_HWE_IB_UC_MEMORYPARITYERR) {
qib_dev_err(dd, "IBUC Parity still set after RST\n");
dd->cspec->hwerrmask &=
~QLOGIC_IB_HWE_IB_UC_MEMORYPARITYERR;
}
qib_write_kreg(dd, kr_hwerrmask,
dd->cspec->hwerrmask);
}
bail:
return ret;
}
static void qib_sd_trimdone_monitor(struct qib_devdata *dd,
const char *where)
{
int ret, chn, baduns;
u64 val;
if (!where)
where = "?";
udelay(2);
ret = qib_resync_ibepb(dd);
if (ret < 0)
qib_dev_err(dd, "not able to re-sync IB EPB (%s)\n", where);
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, IB_CTRL2(0), 0, 0);
if (ret < 0)
qib_dev_err(dd, "Failed TRIMDONE 1st read, (%s)\n", where);
val = qib_read_kreg64(dd, kr_ibcstatus);
if (!(val & (1ULL << 11)))
qib_dev_err(dd, "IBCS TRIMDONE clear (%s)\n", where);
udelay(2);
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, IB_MPREG6, 0x80, 0x80);
if (ret < 0)
qib_dev_err(dd, "Failed Dummy RMW, (%s)\n", where);
udelay(10);
baduns = 0;
for (chn = 3; chn >= 0; --chn) {
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES,
IB_CTRL2(chn), 0, 0);
if (ret < 0)
qib_dev_err(dd,
"Failed checking TRIMDONE, chn %d (%s)\n",
chn, where);
if (!(ret & 0x10)) {
int probe;
baduns |= (1 << chn);
qib_dev_err(dd,
"TRIMDONE cleared on chn %d (%02X). (%s)\n",
chn, ret, where);
probe = qib_sd7220_reg_mod(dd, IB_7220_SERDES,
IB_PGUDP(0), 0, 0);
qib_dev_err(dd, "probe is %d (%02X)\n",
probe, probe);
probe = qib_sd7220_reg_mod(dd, IB_7220_SERDES,
IB_CTRL2(chn), 0, 0);
qib_dev_err(dd, "re-read: %d (%02X)\n",
probe, probe);
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES,
IB_CTRL2(chn), 0x10, 0x10);
if (ret < 0)
qib_dev_err(dd,
"Err on TRIMDONE rewrite1\n");
}
}
for (chn = 3; chn >= 0; --chn) {
if (baduns & (1 << chn)) {
qib_dev_err(dd,
"Resetting TRIMDONE on chn %d (%s)\n",
chn, where);
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES,
IB_CTRL2(chn), 0x10, 0x10);
if (ret < 0)
qib_dev_err(dd,
"Failed re-setting TRIMDONE, chn %d (%s)\n",
chn, where);
}
}
}
int qib_sd7220_init(struct qib_devdata *dd)
{
const struct firmware *fw;
int ret = 1;
int first_reset, was_reset;
was_reset = (qib_read_kreg64(dd, kr_ibserdesctrl) & 1);
if (!was_reset) {
qib_ibsd_reset(dd, 1);
qib_sd_trimdone_monitor(dd, "Driver-reload");
}
ret = request_firmware(&fw, SD7220_FW_NAME, &dd->pcidev->dev);
if (ret) {
qib_dev_err(dd, "Failed to load IB SERDES image\n");
goto done;
}
ret = qib_ibsd_ucode_loaded(dd->pport, fw);
if (ret < 0)
goto bail;
first_reset = !ret;
ret = qib_sd_early(dd);
if (ret < 0) {
qib_dev_err(dd, "Failed to set IB SERDES early defaults\n");
goto bail;
}
if (first_reset) {
ret = qib_sd_dactrim(dd);
if (ret < 0) {
qib_dev_err(dd, "Failed IB SERDES DAC trim\n");
goto bail;
}
}
ret = qib_internal_presets(dd);
if (ret < 0) {
qib_dev_err(dd, "Failed to set IB SERDES presets\n");
goto bail;
}
ret = qib_sd_trimself(dd, 0x80);
if (ret < 0) {
qib_dev_err(dd, "Failed to set IB SERDES TRIMSELF\n");
goto bail;
}
ret = 0;
if (first_reset) {
int vfy;
int trim_done;
ret = qib_sd7220_ib_load(dd, fw);
if (ret < 0) {
qib_dev_err(dd, "Failed to load IB SERDES image\n");
goto bail;
} else {
vfy = qib_sd7220_ib_vfy(dd, fw);
if (vfy != ret) {
qib_dev_err(dd, "SERDES PRAM VFY failed\n");
goto bail;
}
}
ret = 0;
ret = ibsd_mod_allchnls(dd, START_EQ1(0), 0, 0x38);
if (ret < 0) {
qib_dev_err(dd, "Failed clearing START_EQ1\n");
goto bail;
}
qib_ibsd_reset(dd, 0);
trim_done = qib_sd_trimdone_poll(dd);
qib_ibsd_reset(dd, 1);
if (!trim_done) {
qib_dev_err(dd, "No TRIMDONE seen\n");
goto bail;
}
qib_sd_trimdone_monitor(dd, "First-reset");
dd->cspec->serdes_first_init_done = 1;
}
ret = 0;
if (qib_sd_setvals(dd) >= 0)
goto done;
bail:
ret = 1;
done:
set_7220_relock_poll(dd, -1);
release_firmware(fw);
return ret;
}
static int epb_access(struct qib_devdata *dd, int sdnum, int claim)
{
u16 acc;
u64 accval;
int owned = 0;
u64 oct_sel = 0;
switch (sdnum) {
case IB_7220_SERDES:
acc = kr_ibsd_epb_access_ctrl;
break;
case PCIE_SERDES0:
case PCIE_SERDES1:
acc = kr_pciesd_epb_access_ctrl;
oct_sel = (2 << (sdnum - PCIE_SERDES0));
break;
default:
return 0;
}
qib_read_kreg32(dd, kr_scratch);
udelay(15);
accval = qib_read_kreg32(dd, acc);
owned = !!(accval & EPB_ACC_GNT);
if (claim < 0) {
u64 pollval;
u64 newval = 0;
qib_write_kreg(dd, acc, newval);
pollval = qib_read_kreg32(dd, acc);
udelay(5);
pollval = qib_read_kreg32(dd, acc);
if (pollval & EPB_ACC_GNT)
owned = -1;
} else if (claim > 0) {
u64 pollval;
u64 newval = EPB_ACC_REQ | oct_sel;
qib_write_kreg(dd, acc, newval);
pollval = qib_read_kreg32(dd, acc);
udelay(5);
pollval = qib_read_kreg32(dd, acc);
if (!(pollval & EPB_ACC_GNT))
owned = -1;
}
return owned;
}
static int epb_trans(struct qib_devdata *dd, u16 reg, u64 i_val, u64 *o_vp)
{
int tries;
u64 transval;
qib_write_kreg(dd, reg, i_val);
transval = qib_read_kreg64(dd, reg);
for (tries = EPB_TRANS_TRIES; tries; --tries) {
transval = qib_read_kreg32(dd, reg);
if (transval & EPB_TRANS_RDY)
break;
udelay(5);
}
if (transval & EPB_TRANS_ERR)
return -1;
if (tries > 0 && o_vp)
*o_vp = transval;
return tries;
}
static int qib_sd7220_reg_mod(struct qib_devdata *dd, int sdnum, u32 loc,
u32 wd, u32 mask)
{
u16 trans;
u64 transval;
int owned;
int tries, ret;
unsigned long flags;
switch (sdnum) {
case IB_7220_SERDES:
trans = kr_ibsd_epb_transaction_reg;
break;
case PCIE_SERDES0:
case PCIE_SERDES1:
trans = kr_pciesd_epb_transaction_reg;
break;
default:
return -1;
}
spin_lock_irqsave(&dd->cspec->sdepb_lock, flags);
owned = epb_access(dd, sdnum, 1);
if (owned < 0) {
spin_unlock_irqrestore(&dd->cspec->sdepb_lock, flags);
return -1;
}
ret = 0;
for (tries = EPB_TRANS_TRIES; tries; --tries) {
transval = qib_read_kreg32(dd, trans);
if (transval & EPB_TRANS_RDY)
break;
udelay(5);
}
if (tries > 0) {
tries = 1;
if (mask != 0xFF) {
transval = loc | EPB_RD;
tries = epb_trans(dd, trans, transval, &transval);
}
if (tries > 0 && mask != 0) {
wd = (wd & mask) | (transval & ~mask);
transval = loc | (wd & EPB_DATA_MASK);
tries = epb_trans(dd, trans, transval, &transval);
}
}
if (epb_access(dd, sdnum, -1) < 0)
ret = -1;
else
ret = transval & EPB_DATA_MASK;
spin_unlock_irqrestore(&dd->cspec->sdepb_lock, flags);
if (tries <= 0)
ret = -1;
return ret;
}
static int qib_sd7220_ram_xfer(struct qib_devdata *dd, int sdnum, u32 loc,
u8 *buf, int cnt, int rd_notwr)
{
u16 trans;
u64 transval;
u64 csbit;
int owned;
int tries;
int sofar;
int addr;
int ret;
unsigned long flags;
const char *op;
switch (sdnum) {
case IB_7220_SERDES:
csbit = 1ULL << EPB_IB_UC_CS_SHF;
trans = kr_ibsd_epb_transaction_reg;
break;
case PCIE_SERDES0:
case PCIE_SERDES1:
csbit = 1ULL << EPB_PCIE_UC_CS_SHF;
trans = kr_pciesd_epb_transaction_reg;
break;
default:
return -1;
}
op = rd_notwr ? "Rd" : "Wr";
spin_lock_irqsave(&dd->cspec->sdepb_lock, flags);
owned = epb_access(dd, sdnum, 1);
if (owned < 0) {
spin_unlock_irqrestore(&dd->cspec->sdepb_lock, flags);
return -1;
}
addr = loc & 0x1FFF;
for (tries = EPB_TRANS_TRIES; tries; --tries) {
transval = qib_read_kreg32(dd, trans);
if (transval & EPB_TRANS_RDY)
break;
udelay(5);
}
sofar = 0;
if (tries > 0) {
transval = csbit | EPB_UC_CTL |
(rd_notwr ? EPB_ROM_R : EPB_ROM_W);
tries = epb_trans(dd, trans, transval, &transval);
while (tries > 0 && sofar < cnt) {
if (!sofar) {
int addrbyte = (addr + sofar) >> 8;
transval = csbit | EPB_MADDRH | addrbyte;
tries = epb_trans(dd, trans, transval,
&transval);
if (tries <= 0)
break;
addrbyte = (addr + sofar) & 0xFF;
transval = csbit | EPB_MADDRL | addrbyte;
tries = epb_trans(dd, trans, transval,
&transval);
if (tries <= 0)
break;
}
if (rd_notwr)
transval = csbit | EPB_ROMDATA | EPB_RD;
else
transval = csbit | EPB_ROMDATA | buf[sofar];
tries = epb_trans(dd, trans, transval, &transval);
if (tries <= 0)
break;
if (rd_notwr)
buf[sofar] = transval & EPB_DATA_MASK;
++sofar;
}
transval = csbit | EPB_UC_CTL;
tries = epb_trans(dd, trans, transval, &transval);
}
ret = sofar;
if (epb_access(dd, sdnum, -1) < 0)
ret = -1;
spin_unlock_irqrestore(&dd->cspec->sdepb_lock, flags);
if (tries <= 0)
ret = -1;
return ret;
}
static int qib_sd7220_prog_ld(struct qib_devdata *dd, int sdnum,
const u8 *img, int len, int offset)
{
int cnt, sofar, req;
sofar = 0;
while (sofar < len) {
req = len - sofar;
if (req > PROG_CHUNK)
req = PROG_CHUNK;
cnt = qib_sd7220_ram_xfer(dd, sdnum, offset + sofar,
(u8 *)img + sofar, req, 0);
if (cnt < req) {
sofar = -1;
break;
}
sofar += req;
}
return sofar;
}
static int qib_sd7220_prog_vfy(struct qib_devdata *dd, int sdnum,
const u8 *img, int len, int offset)
{
int cnt, sofar, req, idx, errors;
unsigned char readback[VFY_CHUNK];
errors = 0;
sofar = 0;
while (sofar < len) {
req = len - sofar;
if (req > VFY_CHUNK)
req = VFY_CHUNK;
cnt = qib_sd7220_ram_xfer(dd, sdnum, sofar + offset,
readback, req, 1);
if (cnt < req) {
sofar = -1;
break;
}
for (idx = 0; idx < cnt; ++idx) {
if (readback[idx] != img[idx+sofar])
++errors;
}
sofar += cnt;
}
return errors ? -errors : sofar;
}
static int
qib_sd7220_ib_load(struct qib_devdata *dd, const struct firmware *fw)
{
return qib_sd7220_prog_ld(dd, IB_7220_SERDES, fw->data, fw->size, 0);
}
static int
qib_sd7220_ib_vfy(struct qib_devdata *dd, const struct firmware *fw)
{
return qib_sd7220_prog_vfy(dd, IB_7220_SERDES, fw->data, fw->size, 0);
}
static int qib_sd_trimdone_poll(struct qib_devdata *dd)
{
int trim_tmo, ret;
uint64_t val;
ret = 0;
for (trim_tmo = 0; trim_tmo < TRIM_TMO; ++trim_tmo) {
val = qib_read_kreg64(dd, kr_ibcstatus);
if (val & IB_SERDES_TRIM_DONE) {
ret = 1;
break;
}
msleep(10);
}
if (trim_tmo >= TRIM_TMO) {
qib_dev_err(dd, "No TRIMDONE in %d tries\n", trim_tmo);
ret = 0;
}
return ret;
}
static int qib_sd_setvals(struct qib_devdata *dd)
{
int idx, midx;
int min_idx;
uint32_t dds_reg_map;
u64 __iomem *taddr, *iaddr;
uint64_t data;
uint64_t sdctl;
taddr = dd->kregbase + kr_serdes_maptable;
iaddr = dd->kregbase + kr_serdes_ddsrxeq0;
sdctl = qib_read_kreg64(dd, kr_ibserdesctrl);
sdctl = (sdctl & ~(0x1f << 8)) | (NUM_DDS_REGS << 8);
sdctl = (sdctl & ~(0x1f << 13)) | (RXEQ_ROWS << 13);
qib_write_kreg(dd, kr_ibserdesctrl, sdctl);
dds_reg_map = DDS_REG_MAP;
for (idx = 0; idx < NUM_DDS_REGS; ++idx) {
data = ((dds_reg_map & 0xF) << 4) | TX_FAST_ELT;
writeq(data, iaddr + idx);
mmiowb();
qib_read_kreg32(dd, kr_scratch);
dds_reg_map >>= 4;
for (midx = 0; midx < DDS_ROWS; ++midx) {
u64 __iomem *daddr = taddr + ((midx << 4) + idx);
data = dds_init_vals[midx].reg_vals[idx];
writeq(data, daddr);
mmiowb();
qib_read_kreg32(dd, kr_scratch);
}
}
min_idx = idx;
taddr += 0x100;
for (idx = 0; idx < RXEQ_ROWS; ++idx) {
int didx;
int vidx;
didx = idx + min_idx;
writeq(rxeq_init_vals[idx].rdesc, iaddr + didx);
mmiowb();
qib_read_kreg32(dd, kr_scratch);
for (vidx = 0; vidx < 4; vidx++) {
data = rxeq_init_vals[idx].rdata[vidx];
writeq(data, taddr + (vidx << 6) + idx);
mmiowb();
qib_read_kreg32(dd, kr_scratch);
}
}
return 0;
}
static int ibsd_mod_allchnls(struct qib_devdata *dd, int loc, int val,
int mask)
{
int ret = -1;
int chnl;
if (loc & EPB_GLOBAL_WR) {
loc |= (1U << EPB_IB_QUAD0_CS_SHF);
chnl = (loc >> (4 + EPB_ADDR_SHF)) & 7;
if (mask != 0xFF) {
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES,
loc & ~EPB_GLOBAL_WR, 0, 0);
if (ret < 0) {
int sloc = loc >> EPB_ADDR_SHF;
qib_dev_err(dd,
"pre-read failed: elt %d, addr 0x%X, chnl %d\n",
(sloc & 0xF),
(sloc >> 9) & 0x3f, chnl);
return ret;
}
val = (ret & ~mask) | (val & mask);
}
loc &= ~(7 << (4+EPB_ADDR_SHF));
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, loc, val, 0xFF);
if (ret < 0) {
int sloc = loc >> EPB_ADDR_SHF;
qib_dev_err(dd,
"Global WR failed: elt %d, addr 0x%X, val %02X\n",
(sloc & 0xF), (sloc >> 9) & 0x3f, val);
}
return ret;
}
loc &= ~(7 << (4+EPB_ADDR_SHF));
loc |= (1U << EPB_IB_QUAD0_CS_SHF);
for (chnl = 0; chnl < 4; ++chnl) {
int cloc = loc | (chnl << (4+EPB_ADDR_SHF));
ret = qib_sd7220_reg_mod(dd, IB_7220_SERDES, cloc, val, mask);
if (ret < 0) {
int sloc = loc >> EPB_ADDR_SHF;
qib_dev_err(dd,
"Write failed: elt %d, addr 0x%X, chnl %d, val 0x%02X, mask 0x%02X\n",
(sloc & 0xF), (sloc >> 9) & 0x3f, chnl,
val & 0xFF, mask & 0xFF);
break;
}
}
return ret;
}
static int set_dds_vals(struct qib_devdata *dd, struct dds_init *ddi)
{
int ret;
int idx, reg, data;
uint32_t regmap;
regmap = DDS_REG_MAP;
for (idx = 0; idx < NUM_DDS_REGS; ++idx) {
reg = (regmap & 0xF);
regmap >>= 4;
data = ddi->reg_vals[idx];
ret = ibsd_mod_allchnls(dd, EPB_LOC(0, 9, reg), data, 0xFF);
if (ret < 0)
break;
}
return ret;
}
static int set_rxeq_vals(struct qib_devdata *dd, int vsel)
{
int ret;
int ridx;
int cnt = ARRAY_SIZE(rxeq_init_vals);
for (ridx = 0; ridx < cnt; ++ridx) {
int elt, reg, val, loc;
elt = rxeq_init_vals[ridx].rdesc & 0xF;
reg = rxeq_init_vals[ridx].rdesc >> 4;
loc = EPB_LOC(0, elt, reg);
val = rxeq_init_vals[ridx].rdata[vsel];
ret = ibsd_mod_allchnls(dd, loc, val, 0xFF);
if (ret < 0)
break;
}
return ret;
}
static int qib_internal_presets(struct qib_devdata *dd)
{
int ret = 0;
ret = set_dds_vals(dd, dds_init_vals + DDS_3M);
if (ret < 0)
qib_dev_err(dd, "Failed to set default DDS values\n");
ret = set_rxeq_vals(dd, qib_rxeq_set & 3);
if (ret < 0)
qib_dev_err(dd, "Failed to set default RXEQ values\n");
return ret;
}
int qib_sd7220_presets(struct qib_devdata *dd)
{
int ret = 0;
if (!dd->cspec->presets_needed)
return ret;
dd->cspec->presets_needed = 0;
qib_ibsd_reset(dd, 1);
udelay(2);
qib_sd_trimdone_monitor(dd, "link-down");
ret = qib_internal_presets(dd);
return ret;
}
static int qib_sd_trimself(struct qib_devdata *dd, int val)
{
int loc = CMUCTRL5 | (1U << EPB_IB_QUAD0_CS_SHF);
return qib_sd7220_reg_mod(dd, IB_7220_SERDES, loc, val, 0xFF);
}
static int qib_sd_early(struct qib_devdata *dd)
{
int ret;
ret = ibsd_mod_allchnls(dd, RXHSCTRL0(0) | EPB_GLOBAL_WR, 0xD4, 0xFF);
if (ret < 0)
goto bail;
ret = ibsd_mod_allchnls(dd, START_EQ1(0) | EPB_GLOBAL_WR, 0x10, 0xFF);
if (ret < 0)
goto bail;
ret = ibsd_mod_allchnls(dd, START_EQ2(0) | EPB_GLOBAL_WR, 0x30, 0xFF);
bail:
return ret;
}
static int qib_sd_dactrim(struct qib_devdata *dd)
{
int ret;
ret = ibsd_mod_allchnls(dd, VCDL_DAC2(0) | EPB_GLOBAL_WR, 0x2D, 0xFF);
if (ret < 0)
goto bail;
ret = ibsd_mod_allchnls(dd, VCDL_CTRL2(0), 3, 0xF);
if (ret < 0)
goto bail;
ret = ibsd_mod_allchnls(dd, BACTRL(0) | EPB_GLOBAL_WR, 0x40, 0xFF);
if (ret < 0)
goto bail;
ret = ibsd_mod_allchnls(dd, LDOUTCTRL1(0) | EPB_GLOBAL_WR, 0x04, 0xFF);
if (ret < 0)
goto bail;
ret = ibsd_mod_allchnls(dd, RXHSSTATUS(0) | EPB_GLOBAL_WR, 0x04, 0xFF);
if (ret < 0)
goto bail;
udelay(415);
ret = ibsd_mod_allchnls(dd, LDOUTCTRL1(0) | EPB_GLOBAL_WR, 0x00, 0xFF);
bail:
return ret;
}
void toggle_7220_rclkrls(struct qib_devdata *dd)
{
int loc = RXLSPPM(0) | EPB_GLOBAL_WR;
int ret;
ret = ibsd_mod_allchnls(dd, loc, 0, 0x80);
if (ret < 0)
qib_dev_err(dd, "RCLKRLS failed to clear D7\n");
else {
udelay(1);
ibsd_mod_allchnls(dd, loc, 0x80, 0x80);
}
udelay(1);
ret = ibsd_mod_allchnls(dd, loc, 0, 0x80);
if (ret < 0)
qib_dev_err(dd, "RCLKRLS failed to clear D7\n");
else {
udelay(1);
ibsd_mod_allchnls(dd, loc, 0x80, 0x80);
}
dd->f_xgxs_reset(dd->pport);
}
void shutdown_7220_relock_poll(struct qib_devdata *dd)
{
if (dd->cspec->relock_timer_active)
del_timer_sync(&dd->cspec->relock_timer);
}
static void qib_run_relock(unsigned long opaque)
{
struct qib_devdata *dd = (struct qib_devdata *)opaque;
struct qib_pportdata *ppd = dd->pport;
struct qib_chip_specific *cs = dd->cspec;
int timeoff;
if ((dd->flags & QIB_INITTED) && !(ppd->lflags &
(QIBL_IB_AUTONEG_INPROG | QIBL_LINKINIT | QIBL_LINKARMED |
QIBL_LINKACTIVE))) {
if (qib_relock_by_timer) {
if (!(ppd->lflags & QIBL_IB_LINK_DISABLED))
toggle_7220_rclkrls(dd);
}
timeoff = cs->relock_interval << 1;
if (timeoff > HZ)
timeoff = HZ;
cs->relock_interval = timeoff;
} else
timeoff = HZ;
mod_timer(&cs->relock_timer, jiffies + timeoff);
}
void set_7220_relock_poll(struct qib_devdata *dd, int ibup)
{
struct qib_chip_specific *cs = dd->cspec;
if (ibup) {
if (cs->relock_timer_active) {
cs->relock_interval = HZ;
mod_timer(&cs->relock_timer, jiffies + HZ);
}
} else {
unsigned int timeout;
timeout = msecs_to_jiffies(RELOCK_FIRST_MS);
if (timeout == 0)
timeout = 1;
if (!cs->relock_timer_active) {
cs->relock_timer_active = 1;
init_timer(&cs->relock_timer);
cs->relock_timer.function = qib_run_relock;
cs->relock_timer.data = (unsigned long) dd;
cs->relock_interval = timeout;
cs->relock_timer.expires = jiffies + timeout;
add_timer(&cs->relock_timer);
} else {
cs->relock_interval = timeout;
mod_timer(&cs->relock_timer, jiffies + timeout);
}
}
}
