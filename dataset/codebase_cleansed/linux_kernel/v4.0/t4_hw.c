static int t4_wait_op_done_val(struct adapter *adapter, int reg, u32 mask,
int polarity, int attempts, int delay, u32 *valp)
{
while (1) {
u32 val = t4_read_reg(adapter, reg);
if (!!(val & mask) == polarity) {
if (valp)
*valp = val;
return 0;
}
if (--attempts == 0)
return -EAGAIN;
if (delay)
udelay(delay);
}
}
static inline int t4_wait_op_done(struct adapter *adapter, int reg, u32 mask,
int polarity, int attempts, int delay)
{
return t4_wait_op_done_val(adapter, reg, mask, polarity, attempts,
delay, NULL);
}
void t4_set_reg_field(struct adapter *adapter, unsigned int addr, u32 mask,
u32 val)
{
u32 v = t4_read_reg(adapter, addr) & ~mask;
t4_write_reg(adapter, addr, v | val);
(void) t4_read_reg(adapter, addr);
}
void t4_read_indirect(struct adapter *adap, unsigned int addr_reg,
unsigned int data_reg, u32 *vals,
unsigned int nregs, unsigned int start_idx)
{
while (nregs--) {
t4_write_reg(adap, addr_reg, start_idx);
*vals++ = t4_read_reg(adap, data_reg);
start_idx++;
}
}
void t4_write_indirect(struct adapter *adap, unsigned int addr_reg,
unsigned int data_reg, const u32 *vals,
unsigned int nregs, unsigned int start_idx)
{
while (nregs--) {
t4_write_reg(adap, addr_reg, start_idx++);
t4_write_reg(adap, data_reg, *vals++);
}
}
void t4_hw_pci_read_cfg4(struct adapter *adap, int reg, u32 *val)
{
u32 req = ENABLE_F | FUNCTION_V(adap->fn) | REGISTER_V(reg);
if (is_t4(adap->params.chip))
req |= LOCALCFG_F;
t4_write_reg(adap, PCIE_CFG_SPACE_REQ_A, req);
*val = t4_read_reg(adap, PCIE_CFG_SPACE_DATA_A);
t4_write_reg(adap, PCIE_CFG_SPACE_REQ_A, 0);
}
static void t4_report_fw_error(struct adapter *adap)
{
static const char *const reason[] = {
"Crash",
"During Device Preparation",
"During Device Configuration",
"During Device Initialization",
"Unexpected Event",
"Insufficient Airflow",
"Device Shutdown",
"Reserved",
};
u32 pcie_fw;
pcie_fw = t4_read_reg(adap, PCIE_FW_A);
if (pcie_fw & PCIE_FW_ERR_F)
dev_err(adap->pdev_dev, "Firmware reports adapter error: %s\n",
reason[PCIE_FW_EVAL_G(pcie_fw)]);
}
static void get_mbox_rpl(struct adapter *adap, __be64 *rpl, int nflit,
u32 mbox_addr)
{
for ( ; nflit; nflit--, mbox_addr += 8)
*rpl++ = cpu_to_be64(t4_read_reg64(adap, mbox_addr));
}
static void fw_asrt(struct adapter *adap, u32 mbox_addr)
{
struct fw_debug_cmd asrt;
get_mbox_rpl(adap, (__be64 *)&asrt, sizeof(asrt) / 8, mbox_addr);
dev_alert(adap->pdev_dev,
"FW assertion at %.16s:%u, val0 %#x, val1 %#x\n",
asrt.u.assert.filename_0_7, ntohl(asrt.u.assert.line),
ntohl(asrt.u.assert.x), ntohl(asrt.u.assert.y));
}
static void dump_mbox(struct adapter *adap, int mbox, u32 data_reg)
{
dev_err(adap->pdev_dev,
"mbox %d: %llx %llx %llx %llx %llx %llx %llx %llx\n", mbox,
(unsigned long long)t4_read_reg64(adap, data_reg),
(unsigned long long)t4_read_reg64(adap, data_reg + 8),
(unsigned long long)t4_read_reg64(adap, data_reg + 16),
(unsigned long long)t4_read_reg64(adap, data_reg + 24),
(unsigned long long)t4_read_reg64(adap, data_reg + 32),
(unsigned long long)t4_read_reg64(adap, data_reg + 40),
(unsigned long long)t4_read_reg64(adap, data_reg + 48),
(unsigned long long)t4_read_reg64(adap, data_reg + 56));
}
int t4_wr_mbox_meat(struct adapter *adap, int mbox, const void *cmd, int size,
void *rpl, bool sleep_ok)
{
static const int delay[] = {
1, 1, 3, 5, 10, 10, 20, 50, 100, 200
};
u32 v;
u64 res;
int i, ms, delay_idx;
const __be64 *p = cmd;
u32 data_reg = PF_REG(mbox, CIM_PF_MAILBOX_DATA_A);
u32 ctl_reg = PF_REG(mbox, CIM_PF_MAILBOX_CTRL_A);
if ((size & 15) || size > MBOX_LEN)
return -EINVAL;
if (adap->pdev->error_state != pci_channel_io_normal)
return -EIO;
v = MBOWNER_G(t4_read_reg(adap, ctl_reg));
for (i = 0; v == MBOX_OWNER_NONE && i < 3; i++)
v = MBOWNER_G(t4_read_reg(adap, ctl_reg));
if (v != MBOX_OWNER_DRV)
return v ? -EBUSY : -ETIMEDOUT;
for (i = 0; i < size; i += 8)
t4_write_reg64(adap, data_reg + i, be64_to_cpu(*p++));
t4_write_reg(adap, ctl_reg, MBMSGVALID_F | MBOWNER_V(MBOX_OWNER_FW));
t4_read_reg(adap, ctl_reg);
delay_idx = 0;
ms = delay[0];
for (i = 0; i < FW_CMD_MAX_TIMEOUT; i += ms) {
if (sleep_ok) {
ms = delay[delay_idx];
if (delay_idx < ARRAY_SIZE(delay) - 1)
delay_idx++;
msleep(ms);
} else
mdelay(ms);
v = t4_read_reg(adap, ctl_reg);
if (MBOWNER_G(v) == MBOX_OWNER_DRV) {
if (!(v & MBMSGVALID_F)) {
t4_write_reg(adap, ctl_reg, 0);
continue;
}
res = t4_read_reg64(adap, data_reg);
if (FW_CMD_OP_G(res >> 32) == FW_DEBUG_CMD) {
fw_asrt(adap, data_reg);
res = FW_CMD_RETVAL_V(EIO);
} else if (rpl) {
get_mbox_rpl(adap, rpl, size / 8, data_reg);
}
if (FW_CMD_RETVAL_G((int)res))
dump_mbox(adap, mbox, data_reg);
t4_write_reg(adap, ctl_reg, 0);
return -FW_CMD_RETVAL_G((int)res);
}
}
dump_mbox(adap, mbox, data_reg);
dev_err(adap->pdev_dev, "command %#x in mailbox %d timed out\n",
*(const u8 *)cmd, mbox);
t4_report_fw_error(adap);
return -ETIMEDOUT;
}
int t4_mc_read(struct adapter *adap, int idx, u32 addr, __be32 *data, u64 *ecc)
{
int i;
u32 mc_bist_cmd, mc_bist_cmd_addr, mc_bist_cmd_len;
u32 mc_bist_status_rdata, mc_bist_data_pattern;
if (is_t4(adap->params.chip)) {
mc_bist_cmd = MC_BIST_CMD_A;
mc_bist_cmd_addr = MC_BIST_CMD_ADDR_A;
mc_bist_cmd_len = MC_BIST_CMD_LEN_A;
mc_bist_status_rdata = MC_BIST_STATUS_RDATA_A;
mc_bist_data_pattern = MC_BIST_DATA_PATTERN_A;
} else {
mc_bist_cmd = MC_REG(MC_P_BIST_CMD_A, idx);
mc_bist_cmd_addr = MC_REG(MC_P_BIST_CMD_ADDR_A, idx);
mc_bist_cmd_len = MC_REG(MC_P_BIST_CMD_LEN_A, idx);
mc_bist_status_rdata = MC_REG(MC_P_BIST_STATUS_RDATA_A, idx);
mc_bist_data_pattern = MC_REG(MC_P_BIST_DATA_PATTERN_A, idx);
}
if (t4_read_reg(adap, mc_bist_cmd) & START_BIST_F)
return -EBUSY;
t4_write_reg(adap, mc_bist_cmd_addr, addr & ~0x3fU);
t4_write_reg(adap, mc_bist_cmd_len, 64);
t4_write_reg(adap, mc_bist_data_pattern, 0xc);
t4_write_reg(adap, mc_bist_cmd, BIST_OPCODE_V(1) | START_BIST_F |
BIST_CMD_GAP_V(1));
i = t4_wait_op_done(adap, mc_bist_cmd, START_BIST_F, 0, 10, 1);
if (i)
return i;
#define MC_DATA(i) MC_BIST_STATUS_REG(mc_bist_status_rdata, i)
for (i = 15; i >= 0; i--)
*data++ = htonl(t4_read_reg(adap, MC_DATA(i)));
if (ecc)
*ecc = t4_read_reg64(adap, MC_DATA(16));
#undef MC_DATA
return 0;
}
int t4_edc_read(struct adapter *adap, int idx, u32 addr, __be32 *data, u64 *ecc)
{
int i;
u32 edc_bist_cmd, edc_bist_cmd_addr, edc_bist_cmd_len;
u32 edc_bist_cmd_data_pattern, edc_bist_status_rdata;
if (is_t4(adap->params.chip)) {
edc_bist_cmd = EDC_REG(EDC_BIST_CMD_A, idx);
edc_bist_cmd_addr = EDC_REG(EDC_BIST_CMD_ADDR_A, idx);
edc_bist_cmd_len = EDC_REG(EDC_BIST_CMD_LEN_A, idx);
edc_bist_cmd_data_pattern = EDC_REG(EDC_BIST_DATA_PATTERN_A,
idx);
edc_bist_status_rdata = EDC_REG(EDC_BIST_STATUS_RDATA_A,
idx);
} else {
edc_bist_cmd = EDC_REG_T5(EDC_H_BIST_CMD_A, idx);
edc_bist_cmd_addr = EDC_REG_T5(EDC_H_BIST_CMD_ADDR_A, idx);
edc_bist_cmd_len = EDC_REG_T5(EDC_H_BIST_CMD_LEN_A, idx);
edc_bist_cmd_data_pattern =
EDC_REG_T5(EDC_H_BIST_DATA_PATTERN_A, idx);
edc_bist_status_rdata =
EDC_REG_T5(EDC_H_BIST_STATUS_RDATA_A, idx);
}
if (t4_read_reg(adap, edc_bist_cmd) & START_BIST_F)
return -EBUSY;
t4_write_reg(adap, edc_bist_cmd_addr, addr & ~0x3fU);
t4_write_reg(adap, edc_bist_cmd_len, 64);
t4_write_reg(adap, edc_bist_cmd_data_pattern, 0xc);
t4_write_reg(adap, edc_bist_cmd,
BIST_OPCODE_V(1) | BIST_CMD_GAP_V(1) | START_BIST_F);
i = t4_wait_op_done(adap, edc_bist_cmd, START_BIST_F, 0, 10, 1);
if (i)
return i;
#define EDC_DATA(i) (EDC_BIST_STATUS_REG(edc_bist_status_rdata, i))
for (i = 15; i >= 0; i--)
*data++ = htonl(t4_read_reg(adap, EDC_DATA(i)));
if (ecc)
*ecc = t4_read_reg64(adap, EDC_DATA(16));
#undef EDC_DATA
return 0;
}
int t4_memory_rw(struct adapter *adap, int win, int mtype, u32 addr,
u32 len, void *hbuf, int dir)
{
u32 pos, offset, resid, memoffset;
u32 edc_size, mc_size, win_pf, mem_reg, mem_aperture, mem_base;
u32 *buf;
if (addr & 0x3 || (uintptr_t)hbuf & 0x3)
return -EINVAL;
buf = (u32 *)hbuf;
resid = len & 0x3;
len -= resid;
edc_size = EDRAM0_SIZE_G(t4_read_reg(adap, MA_EDRAM0_BAR_A));
if (mtype != MEM_MC1)
memoffset = (mtype * (edc_size * 1024 * 1024));
else {
mc_size = EXT_MEM0_SIZE_G(t4_read_reg(adap,
MA_EXT_MEMORY1_BAR_A));
memoffset = (MEM_MC0 * edc_size + mc_size) * 1024 * 1024;
}
addr = addr + memoffset;
mem_reg = t4_read_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN_A,
win));
mem_aperture = 1 << (WINDOW_G(mem_reg) + WINDOW_SHIFT_X);
mem_base = PCIEOFST_G(mem_reg) << PCIEOFST_SHIFT_X;
if (is_t4(adap->params.chip))
mem_base -= adap->t4_bar0;
win_pf = is_t4(adap->params.chip) ? 0 : PFNUM_V(adap->fn);
pos = addr & ~(mem_aperture-1);
offset = addr - pos;
t4_write_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_OFFSET_A, win),
pos | win_pf);
t4_read_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_OFFSET_A, win));
while (len > 0) {
if (dir == T4_MEMORY_READ)
*buf++ = le32_to_cpu((__force __le32)t4_read_reg(adap,
mem_base + offset));
else
t4_write_reg(adap, mem_base + offset,
(__force u32)cpu_to_le32(*buf++));
offset += sizeof(__be32);
len -= sizeof(__be32);
if (offset == mem_aperture) {
pos += mem_aperture;
offset = 0;
t4_write_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_OFFSET_A,
win), pos | win_pf);
t4_read_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_OFFSET_A,
win));
}
}
if (resid) {
union {
u32 word;
char byte[4];
} last;
unsigned char *bp;
int i;
if (dir == T4_MEMORY_READ) {
last.word = le32_to_cpu(
(__force __le32)t4_read_reg(adap,
mem_base + offset));
for (bp = (unsigned char *)buf, i = resid; i < 4; i++)
bp[i] = last.byte[i];
} else {
last.word = *buf;
for (i = resid; i < 4; i++)
last.byte[i] = 0;
t4_write_reg(adap, mem_base + offset,
(__force u32)cpu_to_le32(last.word));
}
}
return 0;
}
int t4_seeprom_wp(struct adapter *adapter, bool enable)
{
unsigned int v = enable ? 0xc : 0;
int ret = pci_write_vpd(adapter->pdev, EEPROM_STAT_ADDR, 4, &v);
return ret < 0 ? ret : 0;
}
int get_vpd_params(struct adapter *adapter, struct vpd_params *p)
{
u32 cclk_param, cclk_val;
int i, ret, addr;
int ec, sn, pn;
u8 *vpd, csum;
unsigned int vpdr_len, kw_offset, id_len;
vpd = vmalloc(VPD_LEN);
if (!vpd)
return -ENOMEM;
ret = pci_read_vpd(adapter->pdev, VPD_BASE, sizeof(u32), vpd);
if (ret < 0)
goto out;
addr = *vpd == CHELSIO_VPD_UNIQUE_ID ? VPD_BASE : VPD_BASE_OLD;
ret = pci_read_vpd(adapter->pdev, addr, VPD_LEN, vpd);
if (ret < 0)
goto out;
if (vpd[0] != PCI_VPD_LRDT_ID_STRING) {
dev_err(adapter->pdev_dev, "missing VPD ID string\n");
ret = -EINVAL;
goto out;
}
id_len = pci_vpd_lrdt_size(vpd);
if (id_len > ID_LEN)
id_len = ID_LEN;
i = pci_vpd_find_tag(vpd, 0, VPD_LEN, PCI_VPD_LRDT_RO_DATA);
if (i < 0) {
dev_err(adapter->pdev_dev, "missing VPD-R section\n");
ret = -EINVAL;
goto out;
}
vpdr_len = pci_vpd_lrdt_size(&vpd[i]);
kw_offset = i + PCI_VPD_LRDT_TAG_SIZE;
if (vpdr_len + kw_offset > VPD_LEN) {
dev_err(adapter->pdev_dev, "bad VPD-R length %u\n", vpdr_len);
ret = -EINVAL;
goto out;
}
#define FIND_VPD_KW(var, name) do { \
var = pci_vpd_find_info_keyword(vpd, kw_offset, vpdr_len, name); \
if (var < 0) { \
dev_err(adapter->pdev_dev, "missing VPD keyword " name "\n"); \
ret = -EINVAL; \
goto out; \
} \
var += PCI_VPD_INFO_FLD_HDR_SIZE; \
} while (0)
FIND_VPD_KW(i, "RV");
for (csum = 0; i >= 0; i--)
csum += vpd[i];
if (csum) {
dev_err(adapter->pdev_dev,
"corrupted VPD EEPROM, actual csum %u\n", csum);
ret = -EINVAL;
goto out;
}
FIND_VPD_KW(ec, "EC");
FIND_VPD_KW(sn, "SN");
FIND_VPD_KW(pn, "PN");
#undef FIND_VPD_KW
memcpy(p->id, vpd + PCI_VPD_LRDT_TAG_SIZE, id_len);
strim(p->id);
memcpy(p->ec, vpd + ec, EC_LEN);
strim(p->ec);
i = pci_vpd_info_field_size(vpd + sn - PCI_VPD_INFO_FLD_HDR_SIZE);
memcpy(p->sn, vpd + sn, min(i, SERNUM_LEN));
strim(p->sn);
i = pci_vpd_info_field_size(vpd + pn - PCI_VPD_INFO_FLD_HDR_SIZE);
memcpy(p->pn, vpd + pn, min(i, PN_LEN));
strim(p->pn);
cclk_param = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_CCLK));
ret = t4_query_params(adapter, adapter->mbox, 0, 0,
1, &cclk_param, &cclk_val);
out:
vfree(vpd);
if (ret)
return ret;
p->cclk = cclk_val;
return 0;
}
static int sf1_read(struct adapter *adapter, unsigned int byte_cnt, int cont,
int lock, u32 *valp)
{
int ret;
if (!byte_cnt || byte_cnt > 4)
return -EINVAL;
if (t4_read_reg(adapter, SF_OP_A) & SF_BUSY_F)
return -EBUSY;
t4_write_reg(adapter, SF_OP_A, SF_LOCK_V(lock) |
SF_CONT_V(cont) | BYTECNT_V(byte_cnt - 1));
ret = t4_wait_op_done(adapter, SF_OP_A, SF_BUSY_F, 0, SF_ATTEMPTS, 5);
if (!ret)
*valp = t4_read_reg(adapter, SF_DATA_A);
return ret;
}
static int sf1_write(struct adapter *adapter, unsigned int byte_cnt, int cont,
int lock, u32 val)
{
if (!byte_cnt || byte_cnt > 4)
return -EINVAL;
if (t4_read_reg(adapter, SF_OP_A) & SF_BUSY_F)
return -EBUSY;
t4_write_reg(adapter, SF_DATA_A, val);
t4_write_reg(adapter, SF_OP_A, SF_LOCK_V(lock) |
SF_CONT_V(cont) | BYTECNT_V(byte_cnt - 1) | OP_V(1));
return t4_wait_op_done(adapter, SF_OP_A, SF_BUSY_F, 0, SF_ATTEMPTS, 5);
}
static int flash_wait_op(struct adapter *adapter, int attempts, int delay)
{
int ret;
u32 status;
while (1) {
if ((ret = sf1_write(adapter, 1, 1, 1, SF_RD_STATUS)) != 0 ||
(ret = sf1_read(adapter, 1, 0, 1, &status)) != 0)
return ret;
if (!(status & 1))
return 0;
if (--attempts == 0)
return -EAGAIN;
if (delay)
msleep(delay);
}
}
int t4_read_flash(struct adapter *adapter, unsigned int addr,
unsigned int nwords, u32 *data, int byte_oriented)
{
int ret;
if (addr + nwords * sizeof(u32) > adapter->params.sf_size || (addr & 3))
return -EINVAL;
addr = swab32(addr) | SF_RD_DATA_FAST;
if ((ret = sf1_write(adapter, 4, 1, 0, addr)) != 0 ||
(ret = sf1_read(adapter, 1, 1, 0, data)) != 0)
return ret;
for ( ; nwords; nwords--, data++) {
ret = sf1_read(adapter, 4, nwords > 1, nwords == 1, data);
if (nwords == 1)
t4_write_reg(adapter, SF_OP_A, 0);
if (ret)
return ret;
if (byte_oriented)
*data = (__force __u32) (htonl(*data));
}
return 0;
}
static int t4_write_flash(struct adapter *adapter, unsigned int addr,
unsigned int n, const u8 *data)
{
int ret;
u32 buf[64];
unsigned int i, c, left, val, offset = addr & 0xff;
if (addr >= adapter->params.sf_size || offset + n > SF_PAGE_SIZE)
return -EINVAL;
val = swab32(addr) | SF_PROG_PAGE;
if ((ret = sf1_write(adapter, 1, 0, 1, SF_WR_ENABLE)) != 0 ||
(ret = sf1_write(adapter, 4, 1, 1, val)) != 0)
goto unlock;
for (left = n; left; left -= c) {
c = min(left, 4U);
for (val = 0, i = 0; i < c; ++i)
val = (val << 8) + *data++;
ret = sf1_write(adapter, c, c != left, 1, val);
if (ret)
goto unlock;
}
ret = flash_wait_op(adapter, 8, 1);
if (ret)
goto unlock;
t4_write_reg(adapter, SF_OP_A, 0);
ret = t4_read_flash(adapter, addr & ~0xff, ARRAY_SIZE(buf), buf, 1);
if (ret)
return ret;
if (memcmp(data - n, (u8 *)buf + offset, n)) {
dev_err(adapter->pdev_dev,
"failed to correctly write the flash page at %#x\n",
addr);
return -EIO;
}
return 0;
unlock:
t4_write_reg(adapter, SF_OP_A, 0);
return ret;
}
int t4_get_fw_version(struct adapter *adapter, u32 *vers)
{
return t4_read_flash(adapter, FLASH_FW_START +
offsetof(struct fw_hdr, fw_ver), 1,
vers, 0);
}
int t4_get_tp_version(struct adapter *adapter, u32 *vers)
{
return t4_read_flash(adapter, FLASH_FW_START +
offsetof(struct fw_hdr, tp_microcode_ver),
1, vers, 0);
}
int t4_get_exprom_version(struct adapter *adap, u32 *vers)
{
struct exprom_header {
unsigned char hdr_arr[16];
unsigned char hdr_ver[4];
} *hdr;
u32 exprom_header_buf[DIV_ROUND_UP(sizeof(struct exprom_header),
sizeof(u32))];
int ret;
ret = t4_read_flash(adap, FLASH_EXP_ROM_START,
ARRAY_SIZE(exprom_header_buf), exprom_header_buf,
0);
if (ret)
return ret;
hdr = (struct exprom_header *)exprom_header_buf;
if (hdr->hdr_arr[0] != 0x55 || hdr->hdr_arr[1] != 0xaa)
return -ENOENT;
*vers = (FW_HDR_FW_VER_MAJOR_V(hdr->hdr_ver[0]) |
FW_HDR_FW_VER_MINOR_V(hdr->hdr_ver[1]) |
FW_HDR_FW_VER_MICRO_V(hdr->hdr_ver[2]) |
FW_HDR_FW_VER_BUILD_V(hdr->hdr_ver[3]));
return 0;
}
static int fw_compatible(const struct fw_hdr *hdr1, const struct fw_hdr *hdr2)
{
if (hdr1->chip == hdr2->chip && hdr1->fw_ver == hdr2->fw_ver)
return 1;
#define SAME_INTF(x) (hdr1->intfver_##x == hdr2->intfver_##x)
if (hdr1->chip == hdr2->chip && SAME_INTF(nic) && SAME_INTF(vnic) &&
SAME_INTF(ri) && SAME_INTF(iscsi) && SAME_INTF(fcoe))
return 1;
#undef SAME_INTF
return 0;
}
static int should_install_fs_fw(struct adapter *adap, int card_fw_usable,
int k, int c)
{
const char *reason;
if (!card_fw_usable) {
reason = "incompatible or unusable";
goto install;
}
if (k > c) {
reason = "older than the version supported with this driver";
goto install;
}
return 0;
install:
dev_err(adap->pdev_dev, "firmware on card (%u.%u.%u.%u) is %s, "
"installing firmware %u.%u.%u.%u on card.\n",
FW_HDR_FW_VER_MAJOR_G(c), FW_HDR_FW_VER_MINOR_G(c),
FW_HDR_FW_VER_MICRO_G(c), FW_HDR_FW_VER_BUILD_G(c), reason,
FW_HDR_FW_VER_MAJOR_G(k), FW_HDR_FW_VER_MINOR_G(k),
FW_HDR_FW_VER_MICRO_G(k), FW_HDR_FW_VER_BUILD_G(k));
return 1;
}
int t4_prep_fw(struct adapter *adap, struct fw_info *fw_info,
const u8 *fw_data, unsigned int fw_size,
struct fw_hdr *card_fw, enum dev_state state,
int *reset)
{
int ret, card_fw_usable, fs_fw_usable;
const struct fw_hdr *fs_fw;
const struct fw_hdr *drv_fw;
drv_fw = &fw_info->fw_hdr;
ret = -t4_read_flash(adap, FLASH_FW_START,
sizeof(*card_fw) / sizeof(uint32_t),
(uint32_t *)card_fw, 1);
if (ret == 0) {
card_fw_usable = fw_compatible(drv_fw, (const void *)card_fw);
} else {
dev_err(adap->pdev_dev,
"Unable to read card's firmware header: %d\n", ret);
card_fw_usable = 0;
}
if (fw_data != NULL) {
fs_fw = (const void *)fw_data;
fs_fw_usable = fw_compatible(drv_fw, fs_fw);
} else {
fs_fw = NULL;
fs_fw_usable = 0;
}
if (card_fw_usable && card_fw->fw_ver == drv_fw->fw_ver &&
(!fs_fw_usable || fs_fw->fw_ver == drv_fw->fw_ver)) {
} else if (fs_fw_usable && state == DEV_STATE_UNINIT &&
should_install_fs_fw(adap, card_fw_usable,
be32_to_cpu(fs_fw->fw_ver),
be32_to_cpu(card_fw->fw_ver))) {
ret = -t4_fw_upgrade(adap, adap->mbox, fw_data,
fw_size, 0);
if (ret != 0) {
dev_err(adap->pdev_dev,
"failed to install firmware: %d\n", ret);
goto bye;
}
*card_fw = *fs_fw;
card_fw_usable = 1;
*reset = 0;
}
if (!card_fw_usable) {
uint32_t d, c, k;
d = be32_to_cpu(drv_fw->fw_ver);
c = be32_to_cpu(card_fw->fw_ver);
k = fs_fw ? be32_to_cpu(fs_fw->fw_ver) : 0;
dev_err(adap->pdev_dev, "Cannot find a usable firmware: "
"chip state %d, "
"driver compiled with %d.%d.%d.%d, "
"card has %d.%d.%d.%d, filesystem has %d.%d.%d.%d\n",
state,
FW_HDR_FW_VER_MAJOR_G(d), FW_HDR_FW_VER_MINOR_G(d),
FW_HDR_FW_VER_MICRO_G(d), FW_HDR_FW_VER_BUILD_G(d),
FW_HDR_FW_VER_MAJOR_G(c), FW_HDR_FW_VER_MINOR_G(c),
FW_HDR_FW_VER_MICRO_G(c), FW_HDR_FW_VER_BUILD_G(c),
FW_HDR_FW_VER_MAJOR_G(k), FW_HDR_FW_VER_MINOR_G(k),
FW_HDR_FW_VER_MICRO_G(k), FW_HDR_FW_VER_BUILD_G(k));
ret = EINVAL;
goto bye;
}
adap->params.fw_vers = be32_to_cpu(card_fw->fw_ver);
adap->params.tp_vers = be32_to_cpu(card_fw->tp_microcode_ver);
bye:
return ret;
}
static int t4_flash_erase_sectors(struct adapter *adapter, int start, int end)
{
int ret = 0;
if (end >= adapter->params.sf_nsec)
return -EINVAL;
while (start <= end) {
if ((ret = sf1_write(adapter, 1, 0, 1, SF_WR_ENABLE)) != 0 ||
(ret = sf1_write(adapter, 4, 0, 1,
SF_ERASE_SECTOR | (start << 8))) != 0 ||
(ret = flash_wait_op(adapter, 14, 500)) != 0) {
dev_err(adapter->pdev_dev,
"erase of flash sector %d failed, error %d\n",
start, ret);
break;
}
start++;
}
t4_write_reg(adapter, SF_OP_A, 0);
return ret;
}
unsigned int t4_flash_cfg_addr(struct adapter *adapter)
{
if (adapter->params.sf_size == 0x100000)
return FLASH_FPGA_CFG_START;
else
return FLASH_CFG_START;
}
static bool t4_fw_matches_chip(const struct adapter *adap,
const struct fw_hdr *hdr)
{
if ((is_t4(adap->params.chip) && hdr->chip == FW_HDR_CHIP_T4) ||
(is_t5(adap->params.chip) && hdr->chip == FW_HDR_CHIP_T5))
return true;
dev_err(adap->pdev_dev,
"FW image (%d) is not suitable for this adapter (%d)\n",
hdr->chip, CHELSIO_CHIP_VERSION(adap->params.chip));
return false;
}
int t4_load_fw(struct adapter *adap, const u8 *fw_data, unsigned int size)
{
u32 csum;
int ret, addr;
unsigned int i;
u8 first_page[SF_PAGE_SIZE];
const __be32 *p = (const __be32 *)fw_data;
const struct fw_hdr *hdr = (const struct fw_hdr *)fw_data;
unsigned int sf_sec_size = adap->params.sf_size / adap->params.sf_nsec;
unsigned int fw_img_start = adap->params.sf_fw_start;
unsigned int fw_start_sec = fw_img_start / sf_sec_size;
if (!size) {
dev_err(adap->pdev_dev, "FW image has no data\n");
return -EINVAL;
}
if (size & 511) {
dev_err(adap->pdev_dev,
"FW image size not multiple of 512 bytes\n");
return -EINVAL;
}
if (ntohs(hdr->len512) * 512 != size) {
dev_err(adap->pdev_dev,
"FW image size differs from size in FW header\n");
return -EINVAL;
}
if (size > FW_MAX_SIZE) {
dev_err(adap->pdev_dev, "FW image too large, max is %u bytes\n",
FW_MAX_SIZE);
return -EFBIG;
}
if (!t4_fw_matches_chip(adap, hdr))
return -EINVAL;
for (csum = 0, i = 0; i < size / sizeof(csum); i++)
csum += ntohl(p[i]);
if (csum != 0xffffffff) {
dev_err(adap->pdev_dev,
"corrupted firmware image, checksum %#x\n", csum);
return -EINVAL;
}
i = DIV_ROUND_UP(size, sf_sec_size);
ret = t4_flash_erase_sectors(adap, fw_start_sec, fw_start_sec + i - 1);
if (ret)
goto out;
memcpy(first_page, fw_data, SF_PAGE_SIZE);
((struct fw_hdr *)first_page)->fw_ver = htonl(0xffffffff);
ret = t4_write_flash(adap, fw_img_start, SF_PAGE_SIZE, first_page);
if (ret)
goto out;
addr = fw_img_start;
for (size -= SF_PAGE_SIZE; size; size -= SF_PAGE_SIZE) {
addr += SF_PAGE_SIZE;
fw_data += SF_PAGE_SIZE;
ret = t4_write_flash(adap, addr, SF_PAGE_SIZE, fw_data);
if (ret)
goto out;
}
ret = t4_write_flash(adap,
fw_img_start + offsetof(struct fw_hdr, fw_ver),
sizeof(hdr->fw_ver), (const u8 *)&hdr->fw_ver);
out:
if (ret)
dev_err(adap->pdev_dev, "firmware download failed, error %d\n",
ret);
else
ret = t4_get_fw_version(adap, &adap->params.fw_vers);
return ret;
}
int t4_fwcache(struct adapter *adap, enum fw_params_param_dev_fwcache op)
{
struct fw_params_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn =
cpu_to_be32(FW_CMD_OP_V(FW_PARAMS_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
FW_PARAMS_CMD_PFN_V(adap->fn) |
FW_PARAMS_CMD_VFN_V(0));
c.retval_len16 = cpu_to_be32(FW_LEN16(c));
c.param[0].mnem =
cpu_to_be32(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_FWCACHE));
c.param[0].val = (__force __be32)op;
return t4_wr_mbox(adap, adap->mbox, &c, sizeof(c), NULL);
}
void t4_ulprx_read_la(struct adapter *adap, u32 *la_buf)
{
unsigned int i, j;
for (i = 0; i < 8; i++) {
u32 *p = la_buf + i;
t4_write_reg(adap, ULP_RX_LA_CTL_A, i);
j = t4_read_reg(adap, ULP_RX_LA_WRPTR_A);
t4_write_reg(adap, ULP_RX_LA_RDPTR_A, j);
for (j = 0; j < ULPRX_LA_SIZE; j++, p += 8)
*p = t4_read_reg(adap, ULP_RX_LA_RDDATA_A);
}
}
int t4_link_start(struct adapter *adap, unsigned int mbox, unsigned int port,
struct link_config *lc)
{
struct fw_port_cmd c;
unsigned int fc = 0, mdi = FW_PORT_CAP_MDI_V(FW_PORT_CAP_MDI_AUTO);
lc->link_ok = 0;
if (lc->requested_fc & PAUSE_RX)
fc |= FW_PORT_CAP_FC_RX;
if (lc->requested_fc & PAUSE_TX)
fc |= FW_PORT_CAP_FC_TX;
memset(&c, 0, sizeof(c));
c.op_to_portid = htonl(FW_CMD_OP_V(FW_PORT_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_PORT_CMD_PORTID_V(port));
c.action_to_len16 = htonl(FW_PORT_CMD_ACTION_V(FW_PORT_ACTION_L1_CFG) |
FW_LEN16(c));
if (!(lc->supported & FW_PORT_CAP_ANEG)) {
c.u.l1cfg.rcap = htonl((lc->supported & ADVERT_MASK) | fc);
lc->fc = lc->requested_fc & (PAUSE_RX | PAUSE_TX);
} else if (lc->autoneg == AUTONEG_DISABLE) {
c.u.l1cfg.rcap = htonl(lc->requested_speed | fc | mdi);
lc->fc = lc->requested_fc & (PAUSE_RX | PAUSE_TX);
} else
c.u.l1cfg.rcap = htonl(lc->advertising | fc | mdi);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_restart_aneg(struct adapter *adap, unsigned int mbox, unsigned int port)
{
struct fw_port_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_portid = htonl(FW_CMD_OP_V(FW_PORT_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_PORT_CMD_PORTID_V(port));
c.action_to_len16 = htonl(FW_PORT_CMD_ACTION_V(FW_PORT_ACTION_L1_CFG) |
FW_LEN16(c));
c.u.l1cfg.rcap = htonl(FW_PORT_CAP_ANEG);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
static int t4_handle_intr_status(struct adapter *adapter, unsigned int reg,
const struct intr_info *acts)
{
int fatal = 0;
unsigned int mask = 0;
unsigned int status = t4_read_reg(adapter, reg);
for ( ; acts->mask; ++acts) {
if (!(status & acts->mask))
continue;
if (acts->fatal) {
fatal++;
dev_alert(adapter->pdev_dev, "%s (0x%x)\n", acts->msg,
status & acts->mask);
} else if (acts->msg && printk_ratelimit())
dev_warn(adapter->pdev_dev, "%s (0x%x)\n", acts->msg,
status & acts->mask);
if (acts->int_handler)
acts->int_handler(adapter);
mask |= acts->mask;
}
status &= mask;
if (status)
t4_write_reg(adapter, reg, status);
return fatal;
}
static void pcie_intr_handler(struct adapter *adapter)
{
static const struct intr_info sysbus_intr_info[] = {
{ RNPP_F, "RXNP array parity error", -1, 1 },
{ RPCP_F, "RXPC array parity error", -1, 1 },
{ RCIP_F, "RXCIF array parity error", -1, 1 },
{ RCCP_F, "Rx completions control array parity error", -1, 1 },
{ RFTP_F, "RXFT array parity error", -1, 1 },
{ 0 }
};
static const struct intr_info pcie_port_intr_info[] = {
{ TPCP_F, "TXPC array parity error", -1, 1 },
{ TNPP_F, "TXNP array parity error", -1, 1 },
{ TFTP_F, "TXFT array parity error", -1, 1 },
{ TCAP_F, "TXCA array parity error", -1, 1 },
{ TCIP_F, "TXCIF array parity error", -1, 1 },
{ RCAP_F, "RXCA array parity error", -1, 1 },
{ OTDD_F, "outbound request TLP discarded", -1, 1 },
{ RDPE_F, "Rx data parity error", -1, 1 },
{ TDUE_F, "Tx uncorrectable data error", -1, 1 },
{ 0 }
};
static const struct intr_info pcie_intr_info[] = {
{ MSIADDRLPERR_F, "MSI AddrL parity error", -1, 1 },
{ MSIADDRHPERR_F, "MSI AddrH parity error", -1, 1 },
{ MSIDATAPERR_F, "MSI data parity error", -1, 1 },
{ MSIXADDRLPERR_F, "MSI-X AddrL parity error", -1, 1 },
{ MSIXADDRHPERR_F, "MSI-X AddrH parity error", -1, 1 },
{ MSIXDATAPERR_F, "MSI-X data parity error", -1, 1 },
{ MSIXDIPERR_F, "MSI-X DI parity error", -1, 1 },
{ PIOCPLPERR_F, "PCI PIO completion FIFO parity error", -1, 1 },
{ PIOREQPERR_F, "PCI PIO request FIFO parity error", -1, 1 },
{ TARTAGPERR_F, "PCI PCI target tag FIFO parity error", -1, 1 },
{ CCNTPERR_F, "PCI CMD channel count parity error", -1, 1 },
{ CREQPERR_F, "PCI CMD channel request parity error", -1, 1 },
{ CRSPPERR_F, "PCI CMD channel response parity error", -1, 1 },
{ DCNTPERR_F, "PCI DMA channel count parity error", -1, 1 },
{ DREQPERR_F, "PCI DMA channel request parity error", -1, 1 },
{ DRSPPERR_F, "PCI DMA channel response parity error", -1, 1 },
{ HCNTPERR_F, "PCI HMA channel count parity error", -1, 1 },
{ HREQPERR_F, "PCI HMA channel request parity error", -1, 1 },
{ HRSPPERR_F, "PCI HMA channel response parity error", -1, 1 },
{ CFGSNPPERR_F, "PCI config snoop FIFO parity error", -1, 1 },
{ FIDPERR_F, "PCI FID parity error", -1, 1 },
{ INTXCLRPERR_F, "PCI INTx clear parity error", -1, 1 },
{ MATAGPERR_F, "PCI MA tag parity error", -1, 1 },
{ PIOTAGPERR_F, "PCI PIO tag parity error", -1, 1 },
{ RXCPLPERR_F, "PCI Rx completion parity error", -1, 1 },
{ RXWRPERR_F, "PCI Rx write parity error", -1, 1 },
{ RPLPERR_F, "PCI replay buffer parity error", -1, 1 },
{ PCIESINT_F, "PCI core secondary fault", -1, 1 },
{ PCIEPINT_F, "PCI core primary fault", -1, 1 },
{ UNXSPLCPLERR_F, "PCI unexpected split completion error",
-1, 0 },
{ 0 }
};
static struct intr_info t5_pcie_intr_info[] = {
{ MSTGRPPERR_F, "Master Response Read Queue parity error",
-1, 1 },
{ MSTTIMEOUTPERR_F, "Master Timeout FIFO parity error", -1, 1 },
{ MSIXSTIPERR_F, "MSI-X STI SRAM parity error", -1, 1 },
{ MSIXADDRLPERR_F, "MSI-X AddrL parity error", -1, 1 },
{ MSIXADDRHPERR_F, "MSI-X AddrH parity error", -1, 1 },
{ MSIXDATAPERR_F, "MSI-X data parity error", -1, 1 },
{ MSIXDIPERR_F, "MSI-X DI parity error", -1, 1 },
{ PIOCPLGRPPERR_F, "PCI PIO completion Group FIFO parity error",
-1, 1 },
{ PIOREQGRPPERR_F, "PCI PIO request Group FIFO parity error",
-1, 1 },
{ TARTAGPERR_F, "PCI PCI target tag FIFO parity error", -1, 1 },
{ MSTTAGQPERR_F, "PCI master tag queue parity error", -1, 1 },
{ CREQPERR_F, "PCI CMD channel request parity error", -1, 1 },
{ CRSPPERR_F, "PCI CMD channel response parity error", -1, 1 },
{ DREQWRPERR_F, "PCI DMA channel write request parity error",
-1, 1 },
{ DREQPERR_F, "PCI DMA channel request parity error", -1, 1 },
{ DRSPPERR_F, "PCI DMA channel response parity error", -1, 1 },
{ HREQWRPERR_F, "PCI HMA channel count parity error", -1, 1 },
{ HREQPERR_F, "PCI HMA channel request parity error", -1, 1 },
{ HRSPPERR_F, "PCI HMA channel response parity error", -1, 1 },
{ CFGSNPPERR_F, "PCI config snoop FIFO parity error", -1, 1 },
{ FIDPERR_F, "PCI FID parity error", -1, 1 },
{ VFIDPERR_F, "PCI INTx clear parity error", -1, 1 },
{ MAGRPPERR_F, "PCI MA group FIFO parity error", -1, 1 },
{ PIOTAGPERR_F, "PCI PIO tag parity error", -1, 1 },
{ IPRXHDRGRPPERR_F, "PCI IP Rx header group parity error",
-1, 1 },
{ IPRXDATAGRPPERR_F, "PCI IP Rx data group parity error",
-1, 1 },
{ RPLPERR_F, "PCI IP replay buffer parity error", -1, 1 },
{ IPSOTPERR_F, "PCI IP SOT buffer parity error", -1, 1 },
{ TRGT1GRPPERR_F, "PCI TRGT1 group FIFOs parity error", -1, 1 },
{ READRSPERR_F, "Outbound read error", -1, 0 },
{ 0 }
};
int fat;
if (is_t4(adapter->params.chip))
fat = t4_handle_intr_status(adapter,
PCIE_CORE_UTL_SYSTEM_BUS_AGENT_STATUS_A,
sysbus_intr_info) +
t4_handle_intr_status(adapter,
PCIE_CORE_UTL_PCI_EXPRESS_PORT_STATUS_A,
pcie_port_intr_info) +
t4_handle_intr_status(adapter, PCIE_INT_CAUSE_A,
pcie_intr_info);
else
fat = t4_handle_intr_status(adapter, PCIE_INT_CAUSE_A,
t5_pcie_intr_info);
if (fat)
t4_fatal_err(adapter);
}
static void tp_intr_handler(struct adapter *adapter)
{
static const struct intr_info tp_intr_info[] = {
{ 0x3fffffff, "TP parity error", -1, 1 },
{ FLMTXFLSTEMPTY_F, "TP out of Tx pages", -1, 1 },
{ 0 }
};
if (t4_handle_intr_status(adapter, TP_INT_CAUSE_A, tp_intr_info))
t4_fatal_err(adapter);
}
static void sge_intr_handler(struct adapter *adapter)
{
u64 v;
static const struct intr_info sge_intr_info[] = {
{ ERR_CPL_EXCEED_IQE_SIZE_F,
"SGE received CPL exceeding IQE size", -1, 1 },
{ ERR_INVALID_CIDX_INC_F,
"SGE GTS CIDX increment too large", -1, 0 },
{ ERR_CPL_OPCODE_0_F, "SGE received 0-length CPL", -1, 0 },
{ DBFIFO_LP_INT_F, NULL, -1, 0, t4_db_full },
{ DBFIFO_HP_INT_F, NULL, -1, 0, t4_db_full },
{ ERR_DROPPED_DB_F, NULL, -1, 0, t4_db_dropped },
{ ERR_DATA_CPL_ON_HIGH_QID1_F | ERR_DATA_CPL_ON_HIGH_QID0_F,
"SGE IQID > 1023 received CPL for FL", -1, 0 },
{ ERR_BAD_DB_PIDX3_F, "SGE DBP 3 pidx increment too large", -1,
0 },
{ ERR_BAD_DB_PIDX2_F, "SGE DBP 2 pidx increment too large", -1,
0 },
{ ERR_BAD_DB_PIDX1_F, "SGE DBP 1 pidx increment too large", -1,
0 },
{ ERR_BAD_DB_PIDX0_F, "SGE DBP 0 pidx increment too large", -1,
0 },
{ ERR_ING_CTXT_PRIO_F,
"SGE too many priority ingress contexts", -1, 0 },
{ ERR_EGR_CTXT_PRIO_F,
"SGE too many priority egress contexts", -1, 0 },
{ INGRESS_SIZE_ERR_F, "SGE illegal ingress QID", -1, 0 },
{ EGRESS_SIZE_ERR_F, "SGE illegal egress QID", -1, 0 },
{ 0 }
};
v = (u64)t4_read_reg(adapter, SGE_INT_CAUSE1_A) |
((u64)t4_read_reg(adapter, SGE_INT_CAUSE2_A) << 32);
if (v) {
dev_alert(adapter->pdev_dev, "SGE parity error (%#llx)\n",
(unsigned long long)v);
t4_write_reg(adapter, SGE_INT_CAUSE1_A, v);
t4_write_reg(adapter, SGE_INT_CAUSE2_A, v >> 32);
}
if (t4_handle_intr_status(adapter, SGE_INT_CAUSE3_A, sge_intr_info) ||
v != 0)
t4_fatal_err(adapter);
}
static void cim_intr_handler(struct adapter *adapter)
{
static const struct intr_info cim_intr_info[] = {
{ PREFDROPINT_F, "CIM control register prefetch drop", -1, 1 },
{ CIM_OBQ_INTR, "CIM OBQ parity error", -1, 1 },
{ CIM_IBQ_INTR, "CIM IBQ parity error", -1, 1 },
{ MBUPPARERR_F, "CIM mailbox uP parity error", -1, 1 },
{ MBHOSTPARERR_F, "CIM mailbox host parity error", -1, 1 },
{ TIEQINPARERRINT_F, "CIM TIEQ outgoing parity error", -1, 1 },
{ TIEQOUTPARERRINT_F, "CIM TIEQ incoming parity error", -1, 1 },
{ 0 }
};
static const struct intr_info cim_upintr_info[] = {
{ RSVDSPACEINT_F, "CIM reserved space access", -1, 1 },
{ ILLTRANSINT_F, "CIM illegal transaction", -1, 1 },
{ ILLWRINT_F, "CIM illegal write", -1, 1 },
{ ILLRDINT_F, "CIM illegal read", -1, 1 },
{ ILLRDBEINT_F, "CIM illegal read BE", -1, 1 },
{ ILLWRBEINT_F, "CIM illegal write BE", -1, 1 },
{ SGLRDBOOTINT_F, "CIM single read from boot space", -1, 1 },
{ SGLWRBOOTINT_F, "CIM single write to boot space", -1, 1 },
{ BLKWRBOOTINT_F, "CIM block write to boot space", -1, 1 },
{ SGLRDFLASHINT_F, "CIM single read from flash space", -1, 1 },
{ SGLWRFLASHINT_F, "CIM single write to flash space", -1, 1 },
{ BLKWRFLASHINT_F, "CIM block write to flash space", -1, 1 },
{ SGLRDEEPROMINT_F, "CIM single EEPROM read", -1, 1 },
{ SGLWREEPROMINT_F, "CIM single EEPROM write", -1, 1 },
{ BLKRDEEPROMINT_F, "CIM block EEPROM read", -1, 1 },
{ BLKWREEPROMINT_F, "CIM block EEPROM write", -1, 1 },
{ SGLRDCTLINT_F, "CIM single read from CTL space", -1, 1 },
{ SGLWRCTLINT_F, "CIM single write to CTL space", -1, 1 },
{ BLKRDCTLINT_F, "CIM block read from CTL space", -1, 1 },
{ BLKWRCTLINT_F, "CIM block write to CTL space", -1, 1 },
{ SGLRDPLINT_F, "CIM single read from PL space", -1, 1 },
{ SGLWRPLINT_F, "CIM single write to PL space", -1, 1 },
{ BLKRDPLINT_F, "CIM block read from PL space", -1, 1 },
{ BLKWRPLINT_F, "CIM block write to PL space", -1, 1 },
{ REQOVRLOOKUPINT_F, "CIM request FIFO overwrite", -1, 1 },
{ RSPOVRLOOKUPINT_F, "CIM response FIFO overwrite", -1, 1 },
{ TIMEOUTINT_F, "CIM PIF timeout", -1, 1 },
{ TIMEOUTMAINT_F, "CIM PIF MA timeout", -1, 1 },
{ 0 }
};
int fat;
if (t4_read_reg(adapter, PCIE_FW_A) & PCIE_FW_ERR_F)
t4_report_fw_error(adapter);
fat = t4_handle_intr_status(adapter, CIM_HOST_INT_CAUSE_A,
cim_intr_info) +
t4_handle_intr_status(adapter, CIM_HOST_UPACC_INT_CAUSE_A,
cim_upintr_info);
if (fat)
t4_fatal_err(adapter);
}
static void ulprx_intr_handler(struct adapter *adapter)
{
static const struct intr_info ulprx_intr_info[] = {
{ 0x1800000, "ULPRX context error", -1, 1 },
{ 0x7fffff, "ULPRX parity error", -1, 1 },
{ 0 }
};
if (t4_handle_intr_status(adapter, ULP_RX_INT_CAUSE_A, ulprx_intr_info))
t4_fatal_err(adapter);
}
static void ulptx_intr_handler(struct adapter *adapter)
{
static const struct intr_info ulptx_intr_info[] = {
{ PBL_BOUND_ERR_CH3_F, "ULPTX channel 3 PBL out of bounds", -1,
0 },
{ PBL_BOUND_ERR_CH2_F, "ULPTX channel 2 PBL out of bounds", -1,
0 },
{ PBL_BOUND_ERR_CH1_F, "ULPTX channel 1 PBL out of bounds", -1,
0 },
{ PBL_BOUND_ERR_CH0_F, "ULPTX channel 0 PBL out of bounds", -1,
0 },
{ 0xfffffff, "ULPTX parity error", -1, 1 },
{ 0 }
};
if (t4_handle_intr_status(adapter, ULP_TX_INT_CAUSE_A, ulptx_intr_info))
t4_fatal_err(adapter);
}
static void pmtx_intr_handler(struct adapter *adapter)
{
static const struct intr_info pmtx_intr_info[] = {
{ PCMD_LEN_OVFL0_F, "PMTX channel 0 pcmd too large", -1, 1 },
{ PCMD_LEN_OVFL1_F, "PMTX channel 1 pcmd too large", -1, 1 },
{ PCMD_LEN_OVFL2_F, "PMTX channel 2 pcmd too large", -1, 1 },
{ ZERO_C_CMD_ERROR_F, "PMTX 0-length pcmd", -1, 1 },
{ PMTX_FRAMING_ERROR_F, "PMTX framing error", -1, 1 },
{ OESPI_PAR_ERROR_F, "PMTX oespi parity error", -1, 1 },
{ DB_OPTIONS_PAR_ERROR_F, "PMTX db_options parity error",
-1, 1 },
{ ICSPI_PAR_ERROR_F, "PMTX icspi parity error", -1, 1 },
{ PMTX_C_PCMD_PAR_ERROR_F, "PMTX c_pcmd parity error", -1, 1},
{ 0 }
};
if (t4_handle_intr_status(adapter, PM_TX_INT_CAUSE_A, pmtx_intr_info))
t4_fatal_err(adapter);
}
static void pmrx_intr_handler(struct adapter *adapter)
{
static const struct intr_info pmrx_intr_info[] = {
{ ZERO_E_CMD_ERROR_F, "PMRX 0-length pcmd", -1, 1 },
{ PMRX_FRAMING_ERROR_F, "PMRX framing error", -1, 1 },
{ OCSPI_PAR_ERROR_F, "PMRX ocspi parity error", -1, 1 },
{ DB_OPTIONS_PAR_ERROR_F, "PMRX db_options parity error",
-1, 1 },
{ IESPI_PAR_ERROR_F, "PMRX iespi parity error", -1, 1 },
{ PMRX_E_PCMD_PAR_ERROR_F, "PMRX e_pcmd parity error", -1, 1},
{ 0 }
};
if (t4_handle_intr_status(adapter, PM_RX_INT_CAUSE_A, pmrx_intr_info))
t4_fatal_err(adapter);
}
static void cplsw_intr_handler(struct adapter *adapter)
{
static const struct intr_info cplsw_intr_info[] = {
{ CIM_OP_MAP_PERR_F, "CPLSW CIM op_map parity error", -1, 1 },
{ CIM_OVFL_ERROR_F, "CPLSW CIM overflow", -1, 1 },
{ TP_FRAMING_ERROR_F, "CPLSW TP framing error", -1, 1 },
{ SGE_FRAMING_ERROR_F, "CPLSW SGE framing error", -1, 1 },
{ CIM_FRAMING_ERROR_F, "CPLSW CIM framing error", -1, 1 },
{ ZERO_SWITCH_ERROR_F, "CPLSW no-switch error", -1, 1 },
{ 0 }
};
if (t4_handle_intr_status(adapter, CPL_INTR_CAUSE_A, cplsw_intr_info))
t4_fatal_err(adapter);
}
static void le_intr_handler(struct adapter *adap)
{
static const struct intr_info le_intr_info[] = {
{ LIPMISS_F, "LE LIP miss", -1, 0 },
{ LIP0_F, "LE 0 LIP error", -1, 0 },
{ PARITYERR_F, "LE parity error", -1, 1 },
{ UNKNOWNCMD_F, "LE unknown command", -1, 1 },
{ REQQPARERR_F, "LE request queue parity error", -1, 1 },
{ 0 }
};
if (t4_handle_intr_status(adap, LE_DB_INT_CAUSE_A, le_intr_info))
t4_fatal_err(adap);
}
static void mps_intr_handler(struct adapter *adapter)
{
static const struct intr_info mps_rx_intr_info[] = {
{ 0xffffff, "MPS Rx parity error", -1, 1 },
{ 0 }
};
static const struct intr_info mps_tx_intr_info[] = {
{ TPFIFO_V(TPFIFO_M), "MPS Tx TP FIFO parity error", -1, 1 },
{ NCSIFIFO_F, "MPS Tx NC-SI FIFO parity error", -1, 1 },
{ TXDATAFIFO_V(TXDATAFIFO_M), "MPS Tx data FIFO parity error",
-1, 1 },
{ TXDESCFIFO_V(TXDESCFIFO_M), "MPS Tx desc FIFO parity error",
-1, 1 },
{ BUBBLE_F, "MPS Tx underflow", -1, 1 },
{ SECNTERR_F, "MPS Tx SOP/EOP error", -1, 1 },
{ FRMERR_F, "MPS Tx framing error", -1, 1 },
{ 0 }
};
static const struct intr_info mps_trc_intr_info[] = {
{ FILTMEM_V(FILTMEM_M), "MPS TRC filter parity error", -1, 1 },
{ PKTFIFO_V(PKTFIFO_M), "MPS TRC packet FIFO parity error",
-1, 1 },
{ MISCPERR_F, "MPS TRC misc parity error", -1, 1 },
{ 0 }
};
static const struct intr_info mps_stat_sram_intr_info[] = {
{ 0x1fffff, "MPS statistics SRAM parity error", -1, 1 },
{ 0 }
};
static const struct intr_info mps_stat_tx_intr_info[] = {
{ 0xfffff, "MPS statistics Tx FIFO parity error", -1, 1 },
{ 0 }
};
static const struct intr_info mps_stat_rx_intr_info[] = {
{ 0xffffff, "MPS statistics Rx FIFO parity error", -1, 1 },
{ 0 }
};
static const struct intr_info mps_cls_intr_info[] = {
{ MATCHSRAM_F, "MPS match SRAM parity error", -1, 1 },
{ MATCHTCAM_F, "MPS match TCAM parity error", -1, 1 },
{ HASHSRAM_F, "MPS hash SRAM parity error", -1, 1 },
{ 0 }
};
int fat;
fat = t4_handle_intr_status(adapter, MPS_RX_PERR_INT_CAUSE_A,
mps_rx_intr_info) +
t4_handle_intr_status(adapter, MPS_TX_INT_CAUSE_A,
mps_tx_intr_info) +
t4_handle_intr_status(adapter, MPS_TRC_INT_CAUSE_A,
mps_trc_intr_info) +
t4_handle_intr_status(adapter, MPS_STAT_PERR_INT_CAUSE_SRAM_A,
mps_stat_sram_intr_info) +
t4_handle_intr_status(adapter, MPS_STAT_PERR_INT_CAUSE_TX_FIFO_A,
mps_stat_tx_intr_info) +
t4_handle_intr_status(adapter, MPS_STAT_PERR_INT_CAUSE_RX_FIFO_A,
mps_stat_rx_intr_info) +
t4_handle_intr_status(adapter, MPS_CLS_INT_CAUSE_A,
mps_cls_intr_info);
t4_write_reg(adapter, MPS_INT_CAUSE_A, 0);
t4_read_reg(adapter, MPS_INT_CAUSE_A);
if (fat)
t4_fatal_err(adapter);
}
static void mem_intr_handler(struct adapter *adapter, int idx)
{
static const char name[4][7] = { "EDC0", "EDC1", "MC/MC0", "MC1" };
unsigned int addr, cnt_addr, v;
if (idx <= MEM_EDC1) {
addr = EDC_REG(EDC_INT_CAUSE_A, idx);
cnt_addr = EDC_REG(EDC_ECC_STATUS_A, idx);
} else if (idx == MEM_MC) {
if (is_t4(adapter->params.chip)) {
addr = MC_INT_CAUSE_A;
cnt_addr = MC_ECC_STATUS_A;
} else {
addr = MC_P_INT_CAUSE_A;
cnt_addr = MC_P_ECC_STATUS_A;
}
} else {
addr = MC_REG(MC_P_INT_CAUSE_A, 1);
cnt_addr = MC_REG(MC_P_ECC_STATUS_A, 1);
}
v = t4_read_reg(adapter, addr) & MEM_INT_MASK;
if (v & PERR_INT_CAUSE_F)
dev_alert(adapter->pdev_dev, "%s FIFO parity error\n",
name[idx]);
if (v & ECC_CE_INT_CAUSE_F) {
u32 cnt = ECC_CECNT_G(t4_read_reg(adapter, cnt_addr));
t4_write_reg(adapter, cnt_addr, ECC_CECNT_V(ECC_CECNT_M));
if (printk_ratelimit())
dev_warn(adapter->pdev_dev,
"%u %s correctable ECC data error%s\n",
cnt, name[idx], cnt > 1 ? "s" : "");
}
if (v & ECC_UE_INT_CAUSE_F)
dev_alert(adapter->pdev_dev,
"%s uncorrectable ECC data error\n", name[idx]);
t4_write_reg(adapter, addr, v);
if (v & (PERR_INT_CAUSE_F | ECC_UE_INT_CAUSE_F))
t4_fatal_err(adapter);
}
static void ma_intr_handler(struct adapter *adap)
{
u32 v, status = t4_read_reg(adap, MA_INT_CAUSE_A);
if (status & MEM_PERR_INT_CAUSE_F) {
dev_alert(adap->pdev_dev,
"MA parity error, parity status %#x\n",
t4_read_reg(adap, MA_PARITY_ERROR_STATUS1_A));
if (is_t5(adap->params.chip))
dev_alert(adap->pdev_dev,
"MA parity error, parity status %#x\n",
t4_read_reg(adap,
MA_PARITY_ERROR_STATUS2_A));
}
if (status & MEM_WRAP_INT_CAUSE_F) {
v = t4_read_reg(adap, MA_INT_WRAP_STATUS_A);
dev_alert(adap->pdev_dev, "MA address wrap-around error by "
"client %u to address %#x\n",
MEM_WRAP_CLIENT_NUM_G(v),
MEM_WRAP_ADDRESS_G(v) << 4);
}
t4_write_reg(adap, MA_INT_CAUSE_A, status);
t4_fatal_err(adap);
}
static void smb_intr_handler(struct adapter *adap)
{
static const struct intr_info smb_intr_info[] = {
{ MSTTXFIFOPARINT_F, "SMB master Tx FIFO parity error", -1, 1 },
{ MSTRXFIFOPARINT_F, "SMB master Rx FIFO parity error", -1, 1 },
{ SLVFIFOPARINT_F, "SMB slave FIFO parity error", -1, 1 },
{ 0 }
};
if (t4_handle_intr_status(adap, SMB_INT_CAUSE_A, smb_intr_info))
t4_fatal_err(adap);
}
static void ncsi_intr_handler(struct adapter *adap)
{
static const struct intr_info ncsi_intr_info[] = {
{ CIM_DM_PRTY_ERR_F, "NC-SI CIM parity error", -1, 1 },
{ MPS_DM_PRTY_ERR_F, "NC-SI MPS parity error", -1, 1 },
{ TXFIFO_PRTY_ERR_F, "NC-SI Tx FIFO parity error", -1, 1 },
{ RXFIFO_PRTY_ERR_F, "NC-SI Rx FIFO parity error", -1, 1 },
{ 0 }
};
if (t4_handle_intr_status(adap, NCSI_INT_CAUSE_A, ncsi_intr_info))
t4_fatal_err(adap);
}
static void xgmac_intr_handler(struct adapter *adap, int port)
{
u32 v, int_cause_reg;
if (is_t4(adap->params.chip))
int_cause_reg = PORT_REG(port, XGMAC_PORT_INT_CAUSE_A);
else
int_cause_reg = T5_PORT_REG(port, MAC_PORT_INT_CAUSE_A);
v = t4_read_reg(adap, int_cause_reg);
v &= TXFIFO_PRTY_ERR_F | RXFIFO_PRTY_ERR_F;
if (!v)
return;
if (v & TXFIFO_PRTY_ERR_F)
dev_alert(adap->pdev_dev, "XGMAC %d Tx FIFO parity error\n",
port);
if (v & RXFIFO_PRTY_ERR_F)
dev_alert(adap->pdev_dev, "XGMAC %d Rx FIFO parity error\n",
port);
t4_write_reg(adap, PORT_REG(port, XGMAC_PORT_INT_CAUSE_A), v);
t4_fatal_err(adap);
}
static void pl_intr_handler(struct adapter *adap)
{
static const struct intr_info pl_intr_info[] = {
{ FATALPERR_F, "T4 fatal parity error", -1, 1 },
{ PERRVFID_F, "PL VFID_MAP parity error", -1, 1 },
{ 0 }
};
if (t4_handle_intr_status(adap, PL_PL_INT_CAUSE_A, pl_intr_info))
t4_fatal_err(adap);
}
int t4_slow_intr_handler(struct adapter *adapter)
{
u32 cause = t4_read_reg(adapter, PL_INT_CAUSE_A);
if (!(cause & GLBL_INTR_MASK))
return 0;
if (cause & CIM_F)
cim_intr_handler(adapter);
if (cause & MPS_F)
mps_intr_handler(adapter);
if (cause & NCSI_F)
ncsi_intr_handler(adapter);
if (cause & PL_F)
pl_intr_handler(adapter);
if (cause & SMB_F)
smb_intr_handler(adapter);
if (cause & XGMAC0_F)
xgmac_intr_handler(adapter, 0);
if (cause & XGMAC1_F)
xgmac_intr_handler(adapter, 1);
if (cause & XGMAC_KR0_F)
xgmac_intr_handler(adapter, 2);
if (cause & XGMAC_KR1_F)
xgmac_intr_handler(adapter, 3);
if (cause & PCIE_F)
pcie_intr_handler(adapter);
if (cause & MC_F)
mem_intr_handler(adapter, MEM_MC);
if (!is_t4(adapter->params.chip) && (cause & MC1_S))
mem_intr_handler(adapter, MEM_MC1);
if (cause & EDC0_F)
mem_intr_handler(adapter, MEM_EDC0);
if (cause & EDC1_F)
mem_intr_handler(adapter, MEM_EDC1);
if (cause & LE_F)
le_intr_handler(adapter);
if (cause & TP_F)
tp_intr_handler(adapter);
if (cause & MA_F)
ma_intr_handler(adapter);
if (cause & PM_TX_F)
pmtx_intr_handler(adapter);
if (cause & PM_RX_F)
pmrx_intr_handler(adapter);
if (cause & ULP_RX_F)
ulprx_intr_handler(adapter);
if (cause & CPL_SWITCH_F)
cplsw_intr_handler(adapter);
if (cause & SGE_F)
sge_intr_handler(adapter);
if (cause & ULP_TX_F)
ulptx_intr_handler(adapter);
t4_write_reg(adapter, PL_INT_CAUSE_A, cause & GLBL_INTR_MASK);
(void)t4_read_reg(adapter, PL_INT_CAUSE_A);
return 1;
}
void t4_intr_enable(struct adapter *adapter)
{
u32 pf = SOURCEPF_G(t4_read_reg(adapter, PL_WHOAMI_A));
t4_write_reg(adapter, SGE_INT_ENABLE3_A, ERR_CPL_EXCEED_IQE_SIZE_F |
ERR_INVALID_CIDX_INC_F | ERR_CPL_OPCODE_0_F |
ERR_DROPPED_DB_F | ERR_DATA_CPL_ON_HIGH_QID1_F |
ERR_DATA_CPL_ON_HIGH_QID0_F | ERR_BAD_DB_PIDX3_F |
ERR_BAD_DB_PIDX2_F | ERR_BAD_DB_PIDX1_F |
ERR_BAD_DB_PIDX0_F | ERR_ING_CTXT_PRIO_F |
ERR_EGR_CTXT_PRIO_F | INGRESS_SIZE_ERR_F |
DBFIFO_HP_INT_F | DBFIFO_LP_INT_F |
EGRESS_SIZE_ERR_F);
t4_write_reg(adapter, MYPF_REG(PL_PF_INT_ENABLE_A), PF_INTR_MASK);
t4_set_reg_field(adapter, PL_INT_MAP0_A, 0, 1 << pf);
}
void t4_intr_disable(struct adapter *adapter)
{
u32 pf = SOURCEPF_G(t4_read_reg(adapter, PL_WHOAMI_A));
t4_write_reg(adapter, MYPF_REG(PL_PF_INT_ENABLE_A), 0);
t4_set_reg_field(adapter, PL_INT_MAP0_A, 1 << pf, 0);
}
static int hash_mac_addr(const u8 *addr)
{
u32 a = ((u32)addr[0] << 16) | ((u32)addr[1] << 8) | addr[2];
u32 b = ((u32)addr[3] << 16) | ((u32)addr[4] << 8) | addr[5];
a ^= b;
a ^= (a >> 12);
a ^= (a >> 6);
return a & 0x3f;
}
int t4_config_rss_range(struct adapter *adapter, int mbox, unsigned int viid,
int start, int n, const u16 *rspq, unsigned int nrspq)
{
int ret;
const u16 *rsp = rspq;
const u16 *rsp_end = rspq + nrspq;
struct fw_rss_ind_tbl_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = htonl(FW_CMD_OP_V(FW_RSS_IND_TBL_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
FW_RSS_IND_TBL_CMD_VIID_V(viid));
cmd.retval_len16 = htonl(FW_LEN16(cmd));
while (n > 0) {
int nq = min(n, 32);
__be32 *qp = &cmd.iq0_to_iq2;
cmd.niqid = htons(nq);
cmd.startidx = htons(start);
start += nq;
n -= nq;
while (nq > 0) {
unsigned int v;
v = FW_RSS_IND_TBL_CMD_IQ0_V(*rsp);
if (++rsp >= rsp_end)
rsp = rspq;
v |= FW_RSS_IND_TBL_CMD_IQ1_V(*rsp);
if (++rsp >= rsp_end)
rsp = rspq;
v |= FW_RSS_IND_TBL_CMD_IQ2_V(*rsp);
if (++rsp >= rsp_end)
rsp = rspq;
*qp++ = htonl(v);
nq -= 3;
}
ret = t4_wr_mbox(adapter, mbox, &cmd, sizeof(cmd), NULL);
if (ret)
return ret;
}
return 0;
}
int t4_config_glbl_rss(struct adapter *adapter, int mbox, unsigned int mode,
unsigned int flags)
{
struct fw_rss_glb_config_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_write = htonl(FW_CMD_OP_V(FW_RSS_GLB_CONFIG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F);
c.retval_len16 = htonl(FW_LEN16(c));
if (mode == FW_RSS_GLB_CONFIG_CMD_MODE_MANUAL) {
c.u.manual.mode_pkd = htonl(FW_RSS_GLB_CONFIG_CMD_MODE_V(mode));
} else if (mode == FW_RSS_GLB_CONFIG_CMD_MODE_BASICVIRTUAL) {
c.u.basicvirtual.mode_pkd =
htonl(FW_RSS_GLB_CONFIG_CMD_MODE_V(mode));
c.u.basicvirtual.synmapen_to_hashtoeplitz = htonl(flags);
} else
return -EINVAL;
return t4_wr_mbox(adapter, mbox, &c, sizeof(c), NULL);
}
static int rd_rss_row(struct adapter *adap, int row, u32 *val)
{
t4_write_reg(adap, TP_RSS_LKP_TABLE_A, 0xfff00000 | row);
return t4_wait_op_done_val(adap, TP_RSS_LKP_TABLE_A, LKPTBLROWVLD_F, 1,
5, 0, val);
}
int t4_read_rss(struct adapter *adapter, u16 *map)
{
u32 val;
int i, ret;
for (i = 0; i < RSS_NENTRIES / 2; ++i) {
ret = rd_rss_row(adapter, i, &val);
if (ret)
return ret;
*map++ = LKPTBLQUEUE0_G(val);
*map++ = LKPTBLQUEUE1_G(val);
}
return 0;
}
void t4_read_rss_key(struct adapter *adap, u32 *key)
{
t4_read_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A, key, 10,
TP_RSS_SECRET_KEY0_A);
}
void t4_write_rss_key(struct adapter *adap, const u32 *key, int idx)
{
t4_write_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A, key, 10,
TP_RSS_SECRET_KEY0_A);
if (idx >= 0 && idx < 16)
t4_write_reg(adap, TP_RSS_CONFIG_VRT_A,
KEYWRADDR_V(idx) | KEYWREN_F);
}
void t4_read_rss_pf_config(struct adapter *adapter, unsigned int index,
u32 *valp)
{
t4_read_indirect(adapter, TP_PIO_ADDR_A, TP_PIO_DATA_A,
valp, 1, TP_RSS_PF0_CONFIG_A + index);
}
void t4_read_rss_vf_config(struct adapter *adapter, unsigned int index,
u32 *vfl, u32 *vfh)
{
u32 vrt, mask, data;
mask = VFWRADDR_V(VFWRADDR_M);
data = VFWRADDR_V(index);
vrt = t4_read_reg(adapter, TP_RSS_CONFIG_VRT_A);
vrt &= ~(VFRDRG_F | VFWREN_F | KEYWREN_F | mask);
vrt |= data | VFRDEN_F;
t4_write_reg(adapter, TP_RSS_CONFIG_VRT_A, vrt);
t4_read_indirect(adapter, TP_PIO_ADDR_A, TP_PIO_DATA_A,
vfl, 1, TP_RSS_VFL_CONFIG_A);
t4_read_indirect(adapter, TP_PIO_ADDR_A, TP_PIO_DATA_A,
vfh, 1, TP_RSS_VFH_CONFIG_A);
}
u32 t4_read_rss_pf_map(struct adapter *adapter)
{
u32 pfmap;
t4_read_indirect(adapter, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&pfmap, 1, TP_RSS_PF_MAP_A);
return pfmap;
}
u32 t4_read_rss_pf_mask(struct adapter *adapter)
{
u32 pfmask;
t4_read_indirect(adapter, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&pfmask, 1, TP_RSS_PF_MSK_A);
return pfmask;
}
void t4_tp_get_tcp_stats(struct adapter *adap, struct tp_tcp_stats *v4,
struct tp_tcp_stats *v6)
{
u32 val[TP_MIB_TCP_RXT_SEG_LO_A - TP_MIB_TCP_OUT_RST_A + 1];
#define STAT_IDX(x) ((TP_MIB_TCP_##x##_A) - TP_MIB_TCP_OUT_RST_A)
#define STAT(x) val[STAT_IDX(x)]
#define STAT64(x) (((u64)STAT(x##_HI) << 32) | STAT(x##_LO))
if (v4) {
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, val,
ARRAY_SIZE(val), TP_MIB_TCP_OUT_RST_A);
v4->tcpOutRsts = STAT(OUT_RST);
v4->tcpInSegs = STAT64(IN_SEG);
v4->tcpOutSegs = STAT64(OUT_SEG);
v4->tcpRetransSegs = STAT64(RXT_SEG);
}
if (v6) {
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, val,
ARRAY_SIZE(val), TP_MIB_TCP_V6OUT_RST_A);
v6->tcpOutRsts = STAT(OUT_RST);
v6->tcpInSegs = STAT64(IN_SEG);
v6->tcpOutSegs = STAT64(OUT_SEG);
v6->tcpRetransSegs = STAT64(RXT_SEG);
}
#undef STAT64
#undef STAT
#undef STAT_IDX
}
void t4_read_mtu_tbl(struct adapter *adap, u16 *mtus, u8 *mtu_log)
{
u32 v;
int i;
for (i = 0; i < NMTUS; ++i) {
t4_write_reg(adap, TP_MTU_TABLE_A,
MTUINDEX_V(0xff) | MTUVALUE_V(i));
v = t4_read_reg(adap, TP_MTU_TABLE_A);
mtus[i] = MTUVALUE_G(v);
if (mtu_log)
mtu_log[i] = MTUWIDTH_G(v);
}
}
void t4_read_cong_tbl(struct adapter *adap, u16 incr[NMTUS][NCCTRL_WIN])
{
unsigned int mtu, w;
for (mtu = 0; mtu < NMTUS; ++mtu)
for (w = 0; w < NCCTRL_WIN; ++w) {
t4_write_reg(adap, TP_CCTRL_TABLE_A,
ROWINDEX_V(0xffff) | (mtu << 5) | w);
incr[mtu][w] = (u16)t4_read_reg(adap,
TP_CCTRL_TABLE_A) & 0x1fff;
}
}
void t4_tp_wr_bits_indirect(struct adapter *adap, unsigned int addr,
unsigned int mask, unsigned int val)
{
t4_write_reg(adap, TP_PIO_ADDR_A, addr);
val |= t4_read_reg(adap, TP_PIO_DATA_A) & ~mask;
t4_write_reg(adap, TP_PIO_DATA_A, val);
}
static void init_cong_ctrl(unsigned short *a, unsigned short *b)
{
a[0] = a[1] = a[2] = a[3] = a[4] = a[5] = a[6] = a[7] = a[8] = 1;
a[9] = 2;
a[10] = 3;
a[11] = 4;
a[12] = 5;
a[13] = 6;
a[14] = 7;
a[15] = 8;
a[16] = 9;
a[17] = 10;
a[18] = 14;
a[19] = 17;
a[20] = 21;
a[21] = 25;
a[22] = 30;
a[23] = 35;
a[24] = 45;
a[25] = 60;
a[26] = 80;
a[27] = 100;
a[28] = 200;
a[29] = 300;
a[30] = 400;
a[31] = 500;
b[0] = b[1] = b[2] = b[3] = b[4] = b[5] = b[6] = b[7] = b[8] = 0;
b[9] = b[10] = 1;
b[11] = b[12] = 2;
b[13] = b[14] = b[15] = b[16] = 3;
b[17] = b[18] = b[19] = b[20] = b[21] = 4;
b[22] = b[23] = b[24] = b[25] = b[26] = b[27] = 5;
b[28] = b[29] = 6;
b[30] = b[31] = 7;
}
void t4_load_mtus(struct adapter *adap, const unsigned short *mtus,
const unsigned short *alpha, const unsigned short *beta)
{
static const unsigned int avg_pkts[NCCTRL_WIN] = {
2, 6, 10, 14, 20, 28, 40, 56, 80, 112, 160, 224, 320, 448, 640,
896, 1281, 1792, 2560, 3584, 5120, 7168, 10240, 14336, 20480,
28672, 40960, 57344, 81920, 114688, 163840, 229376
};
unsigned int i, w;
for (i = 0; i < NMTUS; ++i) {
unsigned int mtu = mtus[i];
unsigned int log2 = fls(mtu);
if (!(mtu & ((1 << log2) >> 2)))
log2--;
t4_write_reg(adap, TP_MTU_TABLE_A, MTUINDEX_V(i) |
MTUWIDTH_V(log2) | MTUVALUE_V(mtu));
for (w = 0; w < NCCTRL_WIN; ++w) {
unsigned int inc;
inc = max(((mtu - 40) * alpha[w]) / avg_pkts[w],
CC_MIN_INCR);
t4_write_reg(adap, TP_CCTRL_TABLE_A, (i << 21) |
(w << 16) | (beta[w] << 13) | inc);
}
}
}
void t4_pmtx_get_stats(struct adapter *adap, u32 cnt[], u64 cycles[])
{
int i;
u32 data[2];
for (i = 0; i < PM_NSTATS; i++) {
t4_write_reg(adap, PM_TX_STAT_CONFIG_A, i + 1);
cnt[i] = t4_read_reg(adap, PM_TX_STAT_COUNT_A);
if (is_t4(adap->params.chip)) {
cycles[i] = t4_read_reg64(adap, PM_TX_STAT_LSB_A);
} else {
t4_read_indirect(adap, PM_TX_DBG_CTRL_A,
PM_TX_DBG_DATA_A, data, 2,
PM_TX_DBG_STAT_MSB_A);
cycles[i] = (((u64)data[0] << 32) | data[1]);
}
}
}
void t4_pmrx_get_stats(struct adapter *adap, u32 cnt[], u64 cycles[])
{
int i;
u32 data[2];
for (i = 0; i < PM_NSTATS; i++) {
t4_write_reg(adap, PM_RX_STAT_CONFIG_A, i + 1);
cnt[i] = t4_read_reg(adap, PM_RX_STAT_COUNT_A);
if (is_t4(adap->params.chip)) {
cycles[i] = t4_read_reg64(adap, PM_RX_STAT_LSB_A);
} else {
t4_read_indirect(adap, PM_RX_DBG_CTRL_A,
PM_RX_DBG_DATA_A, data, 2,
PM_RX_DBG_STAT_MSB_A);
cycles[i] = (((u64)data[0] << 32) | data[1]);
}
}
}
static unsigned int get_mps_bg_map(struct adapter *adap, int idx)
{
u32 n = NUMPORTS_G(t4_read_reg(adap, MPS_CMN_CTL_A));
if (n == 0)
return idx == 0 ? 0xf : 0;
if (n == 1)
return idx < 2 ? (3 << (2 * idx)) : 0;
return 1 << idx;
}
const char *t4_get_port_type_description(enum fw_port_type port_type)
{
static const char *const port_type_description[] = {
"R XFI",
"R XAUI",
"T SGMII",
"T XFI",
"T XAUI",
"KX4",
"CX4",
"KX",
"KR",
"R SFP+",
"KR/KX",
"KR/KX/KX4",
"R QSFP_10G",
"R QSA",
"R QSFP",
"R BP40_BA",
};
if (port_type < ARRAY_SIZE(port_type_description))
return port_type_description[port_type];
return "UNKNOWN";
}
void t4_get_port_stats(struct adapter *adap, int idx, struct port_stats *p)
{
u32 bgmap = get_mps_bg_map(adap, idx);
#define GET_STAT(name) \
t4_read_reg64(adap, \
(is_t4(adap->params.chip) ? PORT_REG(idx, MPS_PORT_STAT_##name##_L) : \
T5_PORT_REG(idx, MPS_PORT_STAT_##name##_L)))
#define GET_STAT_COM(name) t4_read_reg64(adap, MPS_STAT_##name##_L)
p->tx_octets = GET_STAT(TX_PORT_BYTES);
p->tx_frames = GET_STAT(TX_PORT_FRAMES);
p->tx_bcast_frames = GET_STAT(TX_PORT_BCAST);
p->tx_mcast_frames = GET_STAT(TX_PORT_MCAST);
p->tx_ucast_frames = GET_STAT(TX_PORT_UCAST);
p->tx_error_frames = GET_STAT(TX_PORT_ERROR);
p->tx_frames_64 = GET_STAT(TX_PORT_64B);
p->tx_frames_65_127 = GET_STAT(TX_PORT_65B_127B);
p->tx_frames_128_255 = GET_STAT(TX_PORT_128B_255B);
p->tx_frames_256_511 = GET_STAT(TX_PORT_256B_511B);
p->tx_frames_512_1023 = GET_STAT(TX_PORT_512B_1023B);
p->tx_frames_1024_1518 = GET_STAT(TX_PORT_1024B_1518B);
p->tx_frames_1519_max = GET_STAT(TX_PORT_1519B_MAX);
p->tx_drop = GET_STAT(TX_PORT_DROP);
p->tx_pause = GET_STAT(TX_PORT_PAUSE);
p->tx_ppp0 = GET_STAT(TX_PORT_PPP0);
p->tx_ppp1 = GET_STAT(TX_PORT_PPP1);
p->tx_ppp2 = GET_STAT(TX_PORT_PPP2);
p->tx_ppp3 = GET_STAT(TX_PORT_PPP3);
p->tx_ppp4 = GET_STAT(TX_PORT_PPP4);
p->tx_ppp5 = GET_STAT(TX_PORT_PPP5);
p->tx_ppp6 = GET_STAT(TX_PORT_PPP6);
p->tx_ppp7 = GET_STAT(TX_PORT_PPP7);
p->rx_octets = GET_STAT(RX_PORT_BYTES);
p->rx_frames = GET_STAT(RX_PORT_FRAMES);
p->rx_bcast_frames = GET_STAT(RX_PORT_BCAST);
p->rx_mcast_frames = GET_STAT(RX_PORT_MCAST);
p->rx_ucast_frames = GET_STAT(RX_PORT_UCAST);
p->rx_too_long = GET_STAT(RX_PORT_MTU_ERROR);
p->rx_jabber = GET_STAT(RX_PORT_MTU_CRC_ERROR);
p->rx_fcs_err = GET_STAT(RX_PORT_CRC_ERROR);
p->rx_len_err = GET_STAT(RX_PORT_LEN_ERROR);
p->rx_symbol_err = GET_STAT(RX_PORT_SYM_ERROR);
p->rx_runt = GET_STAT(RX_PORT_LESS_64B);
p->rx_frames_64 = GET_STAT(RX_PORT_64B);
p->rx_frames_65_127 = GET_STAT(RX_PORT_65B_127B);
p->rx_frames_128_255 = GET_STAT(RX_PORT_128B_255B);
p->rx_frames_256_511 = GET_STAT(RX_PORT_256B_511B);
p->rx_frames_512_1023 = GET_STAT(RX_PORT_512B_1023B);
p->rx_frames_1024_1518 = GET_STAT(RX_PORT_1024B_1518B);
p->rx_frames_1519_max = GET_STAT(RX_PORT_1519B_MAX);
p->rx_pause = GET_STAT(RX_PORT_PAUSE);
p->rx_ppp0 = GET_STAT(RX_PORT_PPP0);
p->rx_ppp1 = GET_STAT(RX_PORT_PPP1);
p->rx_ppp2 = GET_STAT(RX_PORT_PPP2);
p->rx_ppp3 = GET_STAT(RX_PORT_PPP3);
p->rx_ppp4 = GET_STAT(RX_PORT_PPP4);
p->rx_ppp5 = GET_STAT(RX_PORT_PPP5);
p->rx_ppp6 = GET_STAT(RX_PORT_PPP6);
p->rx_ppp7 = GET_STAT(RX_PORT_PPP7);
p->rx_ovflow0 = (bgmap & 1) ? GET_STAT_COM(RX_BG_0_MAC_DROP_FRAME) : 0;
p->rx_ovflow1 = (bgmap & 2) ? GET_STAT_COM(RX_BG_1_MAC_DROP_FRAME) : 0;
p->rx_ovflow2 = (bgmap & 4) ? GET_STAT_COM(RX_BG_2_MAC_DROP_FRAME) : 0;
p->rx_ovflow3 = (bgmap & 8) ? GET_STAT_COM(RX_BG_3_MAC_DROP_FRAME) : 0;
p->rx_trunc0 = (bgmap & 1) ? GET_STAT_COM(RX_BG_0_MAC_TRUNC_FRAME) : 0;
p->rx_trunc1 = (bgmap & 2) ? GET_STAT_COM(RX_BG_1_MAC_TRUNC_FRAME) : 0;
p->rx_trunc2 = (bgmap & 4) ? GET_STAT_COM(RX_BG_2_MAC_TRUNC_FRAME) : 0;
p->rx_trunc3 = (bgmap & 8) ? GET_STAT_COM(RX_BG_3_MAC_TRUNC_FRAME) : 0;
#undef GET_STAT
#undef GET_STAT_COM
}
void t4_wol_magic_enable(struct adapter *adap, unsigned int port,
const u8 *addr)
{
u32 mag_id_reg_l, mag_id_reg_h, port_cfg_reg;
if (is_t4(adap->params.chip)) {
mag_id_reg_l = PORT_REG(port, XGMAC_PORT_MAGIC_MACID_LO);
mag_id_reg_h = PORT_REG(port, XGMAC_PORT_MAGIC_MACID_HI);
port_cfg_reg = PORT_REG(port, XGMAC_PORT_CFG2_A);
} else {
mag_id_reg_l = T5_PORT_REG(port, MAC_PORT_MAGIC_MACID_LO);
mag_id_reg_h = T5_PORT_REG(port, MAC_PORT_MAGIC_MACID_HI);
port_cfg_reg = T5_PORT_REG(port, MAC_PORT_CFG2_A);
}
if (addr) {
t4_write_reg(adap, mag_id_reg_l,
(addr[2] << 24) | (addr[3] << 16) |
(addr[4] << 8) | addr[5]);
t4_write_reg(adap, mag_id_reg_h,
(addr[0] << 8) | addr[1]);
}
t4_set_reg_field(adap, port_cfg_reg, MAGICEN_F,
addr ? MAGICEN_F : 0);
}
int t4_wol_pat_enable(struct adapter *adap, unsigned int port, unsigned int map,
u64 mask0, u64 mask1, unsigned int crc, bool enable)
{
int i;
u32 port_cfg_reg;
if (is_t4(adap->params.chip))
port_cfg_reg = PORT_REG(port, XGMAC_PORT_CFG2_A);
else
port_cfg_reg = T5_PORT_REG(port, MAC_PORT_CFG2_A);
if (!enable) {
t4_set_reg_field(adap, port_cfg_reg, PATEN_F, 0);
return 0;
}
if (map > 0xff)
return -EINVAL;
#define EPIO_REG(name) \
(is_t4(adap->params.chip) ? \
PORT_REG(port, XGMAC_PORT_EPIO_##name##_A) : \
T5_PORT_REG(port, MAC_PORT_EPIO_##name##_A))
t4_write_reg(adap, EPIO_REG(DATA1), mask0 >> 32);
t4_write_reg(adap, EPIO_REG(DATA2), mask1);
t4_write_reg(adap, EPIO_REG(DATA3), mask1 >> 32);
for (i = 0; i < NWOL_PAT; i++, map >>= 1) {
if (!(map & 1))
continue;
t4_write_reg(adap, EPIO_REG(DATA0), mask0);
t4_write_reg(adap, EPIO_REG(OP), ADDRESS_V(i) | EPIOWR_F);
t4_read_reg(adap, EPIO_REG(OP));
if (t4_read_reg(adap, EPIO_REG(OP)) & SF_BUSY_F)
return -ETIMEDOUT;
t4_write_reg(adap, EPIO_REG(DATA0), crc);
t4_write_reg(adap, EPIO_REG(OP), ADDRESS_V(i + 32) | EPIOWR_F);
t4_read_reg(adap, EPIO_REG(OP));
if (t4_read_reg(adap, EPIO_REG(OP)) & SF_BUSY_F)
return -ETIMEDOUT;
}
#undef EPIO_REG
t4_set_reg_field(adap, PORT_REG(port, XGMAC_PORT_CFG2_A), 0, PATEN_F);
return 0;
}
void t4_mk_filtdelwr(unsigned int ftid, struct fw_filter_wr *wr, int qid)
{
memset(wr, 0, sizeof(*wr));
wr->op_pkd = htonl(FW_WR_OP_V(FW_FILTER_WR));
wr->len16_pkd = htonl(FW_WR_LEN16_V(sizeof(*wr) / 16));
wr->tid_to_iq = htonl(FW_FILTER_WR_TID_V(ftid) |
FW_FILTER_WR_NOREPLY_V(qid < 0));
wr->del_filter_to_l2tix = htonl(FW_FILTER_WR_DEL_FILTER_F);
if (qid >= 0)
wr->rx_chan_rx_rpl_iq = htons(FW_FILTER_WR_RX_RPL_IQ_V(qid));
}
int t4_fwaddrspace_write(struct adapter *adap, unsigned int mbox,
u32 addr, u32 val)
{
struct fw_ldst_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_addrspace = htonl(FW_CMD_OP_V(FW_LDST_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_LDST_CMD_ADDRSPACE_V(FW_LDST_ADDRSPC_FIRMWARE));
c.cycles_to_len16 = htonl(FW_LEN16(c));
c.u.addrval.addr = htonl(addr);
c.u.addrval.val = htonl(val);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_mdio_rd(struct adapter *adap, unsigned int mbox, unsigned int phy_addr,
unsigned int mmd, unsigned int reg, u16 *valp)
{
int ret;
struct fw_ldst_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_addrspace = htonl(FW_CMD_OP_V(FW_LDST_CMD) | FW_CMD_REQUEST_F |
FW_CMD_READ_F | FW_LDST_CMD_ADDRSPACE_V(FW_LDST_ADDRSPC_MDIO));
c.cycles_to_len16 = htonl(FW_LEN16(c));
c.u.mdio.paddr_mmd = htons(FW_LDST_CMD_PADDR_V(phy_addr) |
FW_LDST_CMD_MMD_V(mmd));
c.u.mdio.raddr = htons(reg);
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
if (ret == 0)
*valp = ntohs(c.u.mdio.rval);
return ret;
}
int t4_mdio_wr(struct adapter *adap, unsigned int mbox, unsigned int phy_addr,
unsigned int mmd, unsigned int reg, u16 val)
{
struct fw_ldst_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_addrspace = htonl(FW_CMD_OP_V(FW_LDST_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | FW_LDST_CMD_ADDRSPACE_V(FW_LDST_ADDRSPC_MDIO));
c.cycles_to_len16 = htonl(FW_LEN16(c));
c.u.mdio.paddr_mmd = htons(FW_LDST_CMD_PADDR_V(phy_addr) |
FW_LDST_CMD_MMD_V(mmd));
c.u.mdio.raddr = htons(reg);
c.u.mdio.rval = htons(val);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
void t4_sge_decode_idma_state(struct adapter *adapter, int state)
{
static const char * const t4_decode[] = {
"IDMA_IDLE",
"IDMA_PUSH_MORE_CPL_FIFO",
"IDMA_PUSH_CPL_MSG_HEADER_TO_FIFO",
"Not used",
"IDMA_PHYSADDR_SEND_PCIEHDR",
"IDMA_PHYSADDR_SEND_PAYLOAD_FIRST",
"IDMA_PHYSADDR_SEND_PAYLOAD",
"IDMA_SEND_FIFO_TO_IMSG",
"IDMA_FL_REQ_DATA_FL_PREP",
"IDMA_FL_REQ_DATA_FL",
"IDMA_FL_DROP",
"IDMA_FL_H_REQ_HEADER_FL",
"IDMA_FL_H_SEND_PCIEHDR",
"IDMA_FL_H_PUSH_CPL_FIFO",
"IDMA_FL_H_SEND_CPL",
"IDMA_FL_H_SEND_IP_HDR_FIRST",
"IDMA_FL_H_SEND_IP_HDR",
"IDMA_FL_H_REQ_NEXT_HEADER_FL",
"IDMA_FL_H_SEND_NEXT_PCIEHDR",
"IDMA_FL_H_SEND_IP_HDR_PADDING",
"IDMA_FL_D_SEND_PCIEHDR",
"IDMA_FL_D_SEND_CPL_AND_IP_HDR",
"IDMA_FL_D_REQ_NEXT_DATA_FL",
"IDMA_FL_SEND_PCIEHDR",
"IDMA_FL_PUSH_CPL_FIFO",
"IDMA_FL_SEND_CPL",
"IDMA_FL_SEND_PAYLOAD_FIRST",
"IDMA_FL_SEND_PAYLOAD",
"IDMA_FL_REQ_NEXT_DATA_FL",
"IDMA_FL_SEND_NEXT_PCIEHDR",
"IDMA_FL_SEND_PADDING",
"IDMA_FL_SEND_COMPLETION_TO_IMSG",
"IDMA_FL_SEND_FIFO_TO_IMSG",
"IDMA_FL_REQ_DATAFL_DONE",
"IDMA_FL_REQ_HEADERFL_DONE",
};
static const char * const t5_decode[] = {
"IDMA_IDLE",
"IDMA_ALMOST_IDLE",
"IDMA_PUSH_MORE_CPL_FIFO",
"IDMA_PUSH_CPL_MSG_HEADER_TO_FIFO",
"IDMA_SGEFLRFLUSH_SEND_PCIEHDR",
"IDMA_PHYSADDR_SEND_PCIEHDR",
"IDMA_PHYSADDR_SEND_PAYLOAD_FIRST",
"IDMA_PHYSADDR_SEND_PAYLOAD",
"IDMA_SEND_FIFO_TO_IMSG",
"IDMA_FL_REQ_DATA_FL",
"IDMA_FL_DROP",
"IDMA_FL_DROP_SEND_INC",
"IDMA_FL_H_REQ_HEADER_FL",
"IDMA_FL_H_SEND_PCIEHDR",
"IDMA_FL_H_PUSH_CPL_FIFO",
"IDMA_FL_H_SEND_CPL",
"IDMA_FL_H_SEND_IP_HDR_FIRST",
"IDMA_FL_H_SEND_IP_HDR",
"IDMA_FL_H_REQ_NEXT_HEADER_FL",
"IDMA_FL_H_SEND_NEXT_PCIEHDR",
"IDMA_FL_H_SEND_IP_HDR_PADDING",
"IDMA_FL_D_SEND_PCIEHDR",
"IDMA_FL_D_SEND_CPL_AND_IP_HDR",
"IDMA_FL_D_REQ_NEXT_DATA_FL",
"IDMA_FL_SEND_PCIEHDR",
"IDMA_FL_PUSH_CPL_FIFO",
"IDMA_FL_SEND_CPL",
"IDMA_FL_SEND_PAYLOAD_FIRST",
"IDMA_FL_SEND_PAYLOAD",
"IDMA_FL_REQ_NEXT_DATA_FL",
"IDMA_FL_SEND_NEXT_PCIEHDR",
"IDMA_FL_SEND_PADDING",
"IDMA_FL_SEND_COMPLETION_TO_IMSG",
};
static const u32 sge_regs[] = {
SGE_DEBUG_DATA_LOW_INDEX_2_A,
SGE_DEBUG_DATA_LOW_INDEX_3_A,
SGE_DEBUG_DATA_HIGH_INDEX_10_A,
};
const char **sge_idma_decode;
int sge_idma_decode_nstates;
int i;
if (is_t4(adapter->params.chip)) {
sge_idma_decode = (const char **)t4_decode;
sge_idma_decode_nstates = ARRAY_SIZE(t4_decode);
} else {
sge_idma_decode = (const char **)t5_decode;
sge_idma_decode_nstates = ARRAY_SIZE(t5_decode);
}
if (state < sge_idma_decode_nstates)
CH_WARN(adapter, "idma state %s\n", sge_idma_decode[state]);
else
CH_WARN(adapter, "idma state %d unknown\n", state);
for (i = 0; i < ARRAY_SIZE(sge_regs); i++)
CH_WARN(adapter, "SGE register %#x value %#x\n",
sge_regs[i], t4_read_reg(adapter, sge_regs[i]));
}
int t4_fw_hello(struct adapter *adap, unsigned int mbox, unsigned int evt_mbox,
enum dev_master master, enum dev_state *state)
{
int ret;
struct fw_hello_cmd c;
u32 v;
unsigned int master_mbox;
int retries = FW_CMD_HELLO_RETRIES;
retry:
memset(&c, 0, sizeof(c));
INIT_CMD(c, HELLO, WRITE);
c.err_to_clearinit = htonl(
FW_HELLO_CMD_MASTERDIS_V(master == MASTER_CANT) |
FW_HELLO_CMD_MASTERFORCE_V(master == MASTER_MUST) |
FW_HELLO_CMD_MBMASTER_V(master == MASTER_MUST ? mbox :
FW_HELLO_CMD_MBMASTER_M) |
FW_HELLO_CMD_MBASYNCNOT_V(evt_mbox) |
FW_HELLO_CMD_STAGE_V(fw_hello_cmd_stage_os) |
FW_HELLO_CMD_CLEARINIT_F);
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
if (ret < 0) {
if ((ret == -EBUSY || ret == -ETIMEDOUT) && retries-- > 0)
goto retry;
if (t4_read_reg(adap, PCIE_FW_A) & PCIE_FW_ERR_F)
t4_report_fw_error(adap);
return ret;
}
v = ntohl(c.err_to_clearinit);
master_mbox = FW_HELLO_CMD_MBMASTER_G(v);
if (state) {
if (v & FW_HELLO_CMD_ERR_F)
*state = DEV_STATE_ERR;
else if (v & FW_HELLO_CMD_INIT_F)
*state = DEV_STATE_INIT;
else
*state = DEV_STATE_UNINIT;
}
if ((v & (FW_HELLO_CMD_ERR_F|FW_HELLO_CMD_INIT_F)) == 0 &&
master_mbox != mbox) {
int waiting = FW_CMD_HELLO_TIMEOUT;
for (;;) {
u32 pcie_fw;
msleep(50);
waiting -= 50;
pcie_fw = t4_read_reg(adap, PCIE_FW_A);
if (!(pcie_fw & (PCIE_FW_ERR_F|PCIE_FW_INIT_F))) {
if (waiting <= 0) {
if (retries-- > 0)
goto retry;
return -ETIMEDOUT;
}
continue;
}
if (state) {
if (pcie_fw & PCIE_FW_ERR_F)
*state = DEV_STATE_ERR;
else if (pcie_fw & PCIE_FW_INIT_F)
*state = DEV_STATE_INIT;
}
if (master_mbox == PCIE_FW_MASTER_M &&
(pcie_fw & PCIE_FW_MASTER_VLD_F))
master_mbox = PCIE_FW_MASTER_G(pcie_fw);
break;
}
}
return master_mbox;
}
int t4_fw_bye(struct adapter *adap, unsigned int mbox)
{
struct fw_bye_cmd c;
memset(&c, 0, sizeof(c));
INIT_CMD(c, BYE, WRITE);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_early_init(struct adapter *adap, unsigned int mbox)
{
struct fw_initialize_cmd c;
memset(&c, 0, sizeof(c));
INIT_CMD(c, INITIALIZE, WRITE);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_fw_reset(struct adapter *adap, unsigned int mbox, int reset)
{
struct fw_reset_cmd c;
memset(&c, 0, sizeof(c));
INIT_CMD(c, RESET, WRITE);
c.val = htonl(reset);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
static int t4_fw_halt(struct adapter *adap, unsigned int mbox, int force)
{
int ret = 0;
if (mbox <= PCIE_FW_MASTER_M) {
struct fw_reset_cmd c;
memset(&c, 0, sizeof(c));
INIT_CMD(c, RESET, WRITE);
c.val = htonl(PIORST_F | PIORSTMODE_F);
c.halt_pkd = htonl(FW_RESET_CMD_HALT_F);
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
if (ret == 0 || force) {
t4_set_reg_field(adap, CIM_BOOT_CFG_A, UPCRST_F, UPCRST_F);
t4_set_reg_field(adap, PCIE_FW_A, PCIE_FW_HALT_F,
PCIE_FW_HALT_F);
}
return ret;
}
static int t4_fw_restart(struct adapter *adap, unsigned int mbox, int reset)
{
if (reset) {
t4_set_reg_field(adap, PCIE_FW_A, PCIE_FW_HALT_F, 0);
if (mbox <= PCIE_FW_MASTER_M) {
t4_set_reg_field(adap, CIM_BOOT_CFG_A, UPCRST_F, 0);
msleep(100);
if (t4_fw_reset(adap, mbox,
PIORST_F | PIORSTMODE_F) == 0)
return 0;
}
t4_write_reg(adap, PL_RST_A, PIORST_F | PIORSTMODE_F);
msleep(2000);
} else {
int ms;
t4_set_reg_field(adap, CIM_BOOT_CFG_A, UPCRST_F, 0);
for (ms = 0; ms < FW_CMD_MAX_TIMEOUT; ) {
if (!(t4_read_reg(adap, PCIE_FW_A) & PCIE_FW_HALT_F))
return 0;
msleep(100);
ms += 100;
}
return -ETIMEDOUT;
}
return 0;
}
int t4_fw_upgrade(struct adapter *adap, unsigned int mbox,
const u8 *fw_data, unsigned int size, int force)
{
const struct fw_hdr *fw_hdr = (const struct fw_hdr *)fw_data;
int reset, ret;
if (!t4_fw_matches_chip(adap, fw_hdr))
return -EINVAL;
ret = t4_fw_halt(adap, mbox, force);
if (ret < 0 && !force)
return ret;
ret = t4_load_fw(adap, fw_data, size);
if (ret < 0)
return ret;
reset = ((ntohl(fw_hdr->flags) & FW_HDR_FLAGS_RESET_HALT) == 0);
return t4_fw_restart(adap, mbox, reset);
}
int t4_fixup_host_params(struct adapter *adap, unsigned int page_size,
unsigned int cache_line_size)
{
unsigned int page_shift = fls(page_size) - 1;
unsigned int sge_hps = page_shift - 10;
unsigned int stat_len = cache_line_size > 64 ? 128 : 64;
unsigned int fl_align = cache_line_size < 32 ? 32 : cache_line_size;
unsigned int fl_align_log = fls(fl_align) - 1;
t4_write_reg(adap, SGE_HOST_PAGE_SIZE_A,
HOSTPAGESIZEPF0_V(sge_hps) |
HOSTPAGESIZEPF1_V(sge_hps) |
HOSTPAGESIZEPF2_V(sge_hps) |
HOSTPAGESIZEPF3_V(sge_hps) |
HOSTPAGESIZEPF4_V(sge_hps) |
HOSTPAGESIZEPF5_V(sge_hps) |
HOSTPAGESIZEPF6_V(sge_hps) |
HOSTPAGESIZEPF7_V(sge_hps));
if (is_t4(adap->params.chip)) {
t4_set_reg_field(adap, SGE_CONTROL_A,
INGPADBOUNDARY_V(INGPADBOUNDARY_M) |
EGRSTATUSPAGESIZE_F,
INGPADBOUNDARY_V(fl_align_log -
INGPADBOUNDARY_SHIFT_X) |
EGRSTATUSPAGESIZE_V(stat_len != 64));
} else {
if (fl_align <= 32) {
fl_align = 64;
fl_align_log = 6;
}
t4_set_reg_field(adap, SGE_CONTROL_A,
INGPADBOUNDARY_V(INGPADBOUNDARY_M) |
EGRSTATUSPAGESIZE_F,
INGPADBOUNDARY_V(INGPCIEBOUNDARY_32B_X) |
EGRSTATUSPAGESIZE_V(stat_len != 64));
t4_set_reg_field(adap, SGE_CONTROL2_A,
INGPACKBOUNDARY_V(INGPACKBOUNDARY_M),
INGPACKBOUNDARY_V(fl_align_log -
INGPACKBOUNDARY_SHIFT_X));
}
t4_write_reg(adap, SGE_FL_BUFFER_SIZE0_A, page_size);
t4_write_reg(adap, SGE_FL_BUFFER_SIZE2_A,
(t4_read_reg(adap, SGE_FL_BUFFER_SIZE2_A) + fl_align-1)
& ~(fl_align-1));
t4_write_reg(adap, SGE_FL_BUFFER_SIZE3_A,
(t4_read_reg(adap, SGE_FL_BUFFER_SIZE3_A) + fl_align-1)
& ~(fl_align-1));
t4_write_reg(adap, ULP_RX_TDDP_PSZ_A, HPZ0_V(page_shift - 12));
return 0;
}
int t4_fw_initialize(struct adapter *adap, unsigned int mbox)
{
struct fw_initialize_cmd c;
memset(&c, 0, sizeof(c));
INIT_CMD(c, INITIALIZE, WRITE);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_query_params(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int nparams, const u32 *params,
u32 *val)
{
int i, ret;
struct fw_params_cmd c;
__be32 *p = &c.param[0].mnem;
if (nparams > 7)
return -EINVAL;
memset(&c, 0, sizeof(c));
c.op_to_vfn = htonl(FW_CMD_OP_V(FW_PARAMS_CMD) | FW_CMD_REQUEST_F |
FW_CMD_READ_F | FW_PARAMS_CMD_PFN_V(pf) |
FW_PARAMS_CMD_VFN_V(vf));
c.retval_len16 = htonl(FW_LEN16(c));
for (i = 0; i < nparams; i++, p += 2)
*p = htonl(*params++);
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
if (ret == 0)
for (i = 0, p = &c.param[0].val; i < nparams; i++, p += 2)
*val++ = ntohl(*p);
return ret;
}
int t4_set_params_nosleep(struct adapter *adap, unsigned int mbox,
unsigned int pf, unsigned int vf,
unsigned int nparams, const u32 *params,
const u32 *val)
{
struct fw_params_cmd c;
__be32 *p = &c.param[0].mnem;
if (nparams > 7)
return -EINVAL;
memset(&c, 0, sizeof(c));
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_PARAMS_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
FW_PARAMS_CMD_PFN_V(pf) |
FW_PARAMS_CMD_VFN_V(vf));
c.retval_len16 = cpu_to_be32(FW_LEN16(c));
while (nparams--) {
*p++ = cpu_to_be32(*params++);
*p++ = cpu_to_be32(*val++);
}
return t4_wr_mbox_ns(adap, mbox, &c, sizeof(c), NULL);
}
int t4_set_params(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int nparams, const u32 *params,
const u32 *val)
{
struct fw_params_cmd c;
__be32 *p = &c.param[0].mnem;
if (nparams > 7)
return -EINVAL;
memset(&c, 0, sizeof(c));
c.op_to_vfn = htonl(FW_CMD_OP_V(FW_PARAMS_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | FW_PARAMS_CMD_PFN_V(pf) |
FW_PARAMS_CMD_VFN_V(vf));
c.retval_len16 = htonl(FW_LEN16(c));
while (nparams--) {
*p++ = htonl(*params++);
*p++ = htonl(*val++);
}
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_cfg_pfvf(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int txq, unsigned int txq_eth_ctrl,
unsigned int rxqi, unsigned int rxq, unsigned int tc,
unsigned int vi, unsigned int cmask, unsigned int pmask,
unsigned int nexact, unsigned int rcaps, unsigned int wxcaps)
{
struct fw_pfvf_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = htonl(FW_CMD_OP_V(FW_PFVF_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | FW_PFVF_CMD_PFN_V(pf) |
FW_PFVF_CMD_VFN_V(vf));
c.retval_len16 = htonl(FW_LEN16(c));
c.niqflint_niq = htonl(FW_PFVF_CMD_NIQFLINT_V(rxqi) |
FW_PFVF_CMD_NIQ_V(rxq));
c.type_to_neq = htonl(FW_PFVF_CMD_CMASK_V(cmask) |
FW_PFVF_CMD_PMASK_V(pmask) |
FW_PFVF_CMD_NEQ_V(txq));
c.tc_to_nexactf = htonl(FW_PFVF_CMD_TC_V(tc) | FW_PFVF_CMD_NVI_V(vi) |
FW_PFVF_CMD_NEXACTF_V(nexact));
c.r_caps_to_nethctrl = htonl(FW_PFVF_CMD_R_CAPS_V(rcaps) |
FW_PFVF_CMD_WX_CAPS_V(wxcaps) |
FW_PFVF_CMD_NETHCTRL_V(txq_eth_ctrl));
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_alloc_vi(struct adapter *adap, unsigned int mbox, unsigned int port,
unsigned int pf, unsigned int vf, unsigned int nmac, u8 *mac,
unsigned int *rss_size)
{
int ret;
struct fw_vi_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = htonl(FW_CMD_OP_V(FW_VI_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | FW_CMD_EXEC_F |
FW_VI_CMD_PFN_V(pf) | FW_VI_CMD_VFN_V(vf));
c.alloc_to_len16 = htonl(FW_VI_CMD_ALLOC_F | FW_LEN16(c));
c.portid_pkd = FW_VI_CMD_PORTID_V(port);
c.nmac = nmac - 1;
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
if (ret)
return ret;
if (mac) {
memcpy(mac, c.mac, sizeof(c.mac));
switch (nmac) {
case 5:
memcpy(mac + 24, c.nmac3, sizeof(c.nmac3));
case 4:
memcpy(mac + 18, c.nmac2, sizeof(c.nmac2));
case 3:
memcpy(mac + 12, c.nmac1, sizeof(c.nmac1));
case 2:
memcpy(mac + 6, c.nmac0, sizeof(c.nmac0));
}
}
if (rss_size)
*rss_size = FW_VI_CMD_RSSSIZE_G(ntohs(c.rsssize_pkd));
return FW_VI_CMD_VIID_G(ntohs(c.type_viid));
}
int t4_set_rxmode(struct adapter *adap, unsigned int mbox, unsigned int viid,
int mtu, int promisc, int all_multi, int bcast, int vlanex,
bool sleep_ok)
{
struct fw_vi_rxmode_cmd c;
if (mtu < 0)
mtu = FW_RXMODE_MTU_NO_CHG;
if (promisc < 0)
promisc = FW_VI_RXMODE_CMD_PROMISCEN_M;
if (all_multi < 0)
all_multi = FW_VI_RXMODE_CMD_ALLMULTIEN_M;
if (bcast < 0)
bcast = FW_VI_RXMODE_CMD_BROADCASTEN_M;
if (vlanex < 0)
vlanex = FW_VI_RXMODE_CMD_VLANEXEN_M;
memset(&c, 0, sizeof(c));
c.op_to_viid = htonl(FW_CMD_OP_V(FW_VI_RXMODE_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | FW_VI_RXMODE_CMD_VIID_V(viid));
c.retval_len16 = htonl(FW_LEN16(c));
c.mtu_to_vlanexen = htonl(FW_VI_RXMODE_CMD_MTU_V(mtu) |
FW_VI_RXMODE_CMD_PROMISCEN_V(promisc) |
FW_VI_RXMODE_CMD_ALLMULTIEN_V(all_multi) |
FW_VI_RXMODE_CMD_BROADCASTEN_V(bcast) |
FW_VI_RXMODE_CMD_VLANEXEN_V(vlanex));
return t4_wr_mbox_meat(adap, mbox, &c, sizeof(c), NULL, sleep_ok);
}
int t4_alloc_mac_filt(struct adapter *adap, unsigned int mbox,
unsigned int viid, bool free, unsigned int naddr,
const u8 **addr, u16 *idx, u64 *hash, bool sleep_ok)
{
int i, ret;
struct fw_vi_mac_cmd c;
struct fw_vi_mac_exact *p;
unsigned int max_naddr = is_t4(adap->params.chip) ?
NUM_MPS_CLS_SRAM_L_INSTANCES :
NUM_MPS_T5_CLS_SRAM_L_INSTANCES;
if (naddr > 7)
return -EINVAL;
memset(&c, 0, sizeof(c));
c.op_to_viid = htonl(FW_CMD_OP_V(FW_VI_MAC_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | (free ? FW_CMD_EXEC_F : 0) |
FW_VI_MAC_CMD_VIID_V(viid));
c.freemacs_to_len16 = htonl(FW_VI_MAC_CMD_FREEMACS_V(free) |
FW_CMD_LEN16_V((naddr + 2) / 2));
for (i = 0, p = c.u.exact; i < naddr; i++, p++) {
p->valid_to_idx = htons(FW_VI_MAC_CMD_VALID_F |
FW_VI_MAC_CMD_IDX_V(FW_VI_MAC_ADD_MAC));
memcpy(p->macaddr, addr[i], sizeof(p->macaddr));
}
ret = t4_wr_mbox_meat(adap, mbox, &c, sizeof(c), &c, sleep_ok);
if (ret)
return ret;
for (i = 0, p = c.u.exact; i < naddr; i++, p++) {
u16 index = FW_VI_MAC_CMD_IDX_G(ntohs(p->valid_to_idx));
if (idx)
idx[i] = index >= max_naddr ? 0xffff : index;
if (index < max_naddr)
ret++;
else if (hash)
*hash |= (1ULL << hash_mac_addr(addr[i]));
}
return ret;
}
int t4_change_mac(struct adapter *adap, unsigned int mbox, unsigned int viid,
int idx, const u8 *addr, bool persist, bool add_smt)
{
int ret, mode;
struct fw_vi_mac_cmd c;
struct fw_vi_mac_exact *p = c.u.exact;
unsigned int max_mac_addr = is_t4(adap->params.chip) ?
NUM_MPS_CLS_SRAM_L_INSTANCES :
NUM_MPS_T5_CLS_SRAM_L_INSTANCES;
if (idx < 0)
idx = persist ? FW_VI_MAC_ADD_PERSIST_MAC : FW_VI_MAC_ADD_MAC;
mode = add_smt ? FW_VI_MAC_SMT_AND_MPSTCAM : FW_VI_MAC_MPS_TCAM_ENTRY;
memset(&c, 0, sizeof(c));
c.op_to_viid = htonl(FW_CMD_OP_V(FW_VI_MAC_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | FW_VI_MAC_CMD_VIID_V(viid));
c.freemacs_to_len16 = htonl(FW_CMD_LEN16_V(1));
p->valid_to_idx = htons(FW_VI_MAC_CMD_VALID_F |
FW_VI_MAC_CMD_SMAC_RESULT_V(mode) |
FW_VI_MAC_CMD_IDX_V(idx));
memcpy(p->macaddr, addr, sizeof(p->macaddr));
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
if (ret == 0) {
ret = FW_VI_MAC_CMD_IDX_G(ntohs(p->valid_to_idx));
if (ret >= max_mac_addr)
ret = -ENOMEM;
}
return ret;
}
int t4_set_addr_hash(struct adapter *adap, unsigned int mbox, unsigned int viid,
bool ucast, u64 vec, bool sleep_ok)
{
struct fw_vi_mac_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_viid = htonl(FW_CMD_OP_V(FW_VI_MAC_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | FW_VI_ENABLE_CMD_VIID_V(viid));
c.freemacs_to_len16 = htonl(FW_VI_MAC_CMD_HASHVECEN_F |
FW_VI_MAC_CMD_HASHUNIEN_V(ucast) |
FW_CMD_LEN16_V(1));
c.u.hash.hashvec = cpu_to_be64(vec);
return t4_wr_mbox_meat(adap, mbox, &c, sizeof(c), NULL, sleep_ok);
}
int t4_enable_vi_params(struct adapter *adap, unsigned int mbox,
unsigned int viid, bool rx_en, bool tx_en, bool dcb_en)
{
struct fw_vi_enable_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_viid = htonl(FW_CMD_OP_V(FW_VI_ENABLE_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_VI_ENABLE_CMD_VIID_V(viid));
c.ien_to_len16 = htonl(FW_VI_ENABLE_CMD_IEN_V(rx_en) |
FW_VI_ENABLE_CMD_EEN_V(tx_en) | FW_LEN16(c) |
FW_VI_ENABLE_CMD_DCB_INFO_V(dcb_en));
return t4_wr_mbox_ns(adap, mbox, &c, sizeof(c), NULL);
}
int t4_enable_vi(struct adapter *adap, unsigned int mbox, unsigned int viid,
bool rx_en, bool tx_en)
{
return t4_enable_vi_params(adap, mbox, viid, rx_en, tx_en, 0);
}
int t4_identify_port(struct adapter *adap, unsigned int mbox, unsigned int viid,
unsigned int nblinks)
{
struct fw_vi_enable_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_viid = htonl(FW_CMD_OP_V(FW_VI_ENABLE_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_VI_ENABLE_CMD_VIID_V(viid));
c.ien_to_len16 = htonl(FW_VI_ENABLE_CMD_LED_F | FW_LEN16(c));
c.blinkdur = htons(nblinks);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_iq_free(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int iqtype, unsigned int iqid,
unsigned int fl0id, unsigned int fl1id)
{
struct fw_iq_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = htonl(FW_CMD_OP_V(FW_IQ_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_IQ_CMD_PFN_V(pf) |
FW_IQ_CMD_VFN_V(vf));
c.alloc_to_len16 = htonl(FW_IQ_CMD_FREE_F | FW_LEN16(c));
c.type_to_iqandstindex = htonl(FW_IQ_CMD_TYPE_V(iqtype));
c.iqid = htons(iqid);
c.fl0id = htons(fl0id);
c.fl1id = htons(fl1id);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_eth_eq_free(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int eqid)
{
struct fw_eq_eth_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = htonl(FW_CMD_OP_V(FW_EQ_ETH_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_EQ_ETH_CMD_PFN_V(pf) |
FW_EQ_ETH_CMD_VFN_V(vf));
c.alloc_to_len16 = htonl(FW_EQ_ETH_CMD_FREE_F | FW_LEN16(c));
c.eqid_pkd = htonl(FW_EQ_ETH_CMD_EQID_V(eqid));
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_ctrl_eq_free(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int eqid)
{
struct fw_eq_ctrl_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = htonl(FW_CMD_OP_V(FW_EQ_CTRL_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_EQ_CTRL_CMD_PFN_V(pf) |
FW_EQ_CTRL_CMD_VFN_V(vf));
c.alloc_to_len16 = htonl(FW_EQ_CTRL_CMD_FREE_F | FW_LEN16(c));
c.cmpliqid_eqid = htonl(FW_EQ_CTRL_CMD_EQID_V(eqid));
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_ofld_eq_free(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int eqid)
{
struct fw_eq_ofld_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = htonl(FW_CMD_OP_V(FW_EQ_OFLD_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_EQ_OFLD_CMD_PFN_V(pf) |
FW_EQ_OFLD_CMD_VFN_V(vf));
c.alloc_to_len16 = htonl(FW_EQ_OFLD_CMD_FREE_F | FW_LEN16(c));
c.eqid_pkd = htonl(FW_EQ_OFLD_CMD_EQID_V(eqid));
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_handle_fw_rpl(struct adapter *adap, const __be64 *rpl)
{
u8 opcode = *(const u8 *)rpl;
if (opcode == FW_PORT_CMD) {
int speed = 0, fc = 0;
const struct fw_port_cmd *p = (void *)rpl;
int chan = FW_PORT_CMD_PORTID_G(ntohl(p->op_to_portid));
int port = adap->chan_map[chan];
struct port_info *pi = adap2pinfo(adap, port);
struct link_config *lc = &pi->link_cfg;
u32 stat = ntohl(p->u.info.lstatus_to_modtype);
int link_ok = (stat & FW_PORT_CMD_LSTATUS_F) != 0;
u32 mod = FW_PORT_CMD_MODTYPE_G(stat);
if (stat & FW_PORT_CMD_RXPAUSE_F)
fc |= PAUSE_RX;
if (stat & FW_PORT_CMD_TXPAUSE_F)
fc |= PAUSE_TX;
if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_100M))
speed = 100;
else if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_1G))
speed = 1000;
else if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_10G))
speed = 10000;
else if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_40G))
speed = 40000;
if (link_ok != lc->link_ok || speed != lc->speed ||
fc != lc->fc) {
lc->link_ok = link_ok;
lc->speed = speed;
lc->fc = fc;
lc->supported = be16_to_cpu(p->u.info.pcap);
t4_os_link_changed(adap, port, link_ok);
}
if (mod != pi->mod_type) {
pi->mod_type = mod;
t4_os_portmod_changed(adap, port);
}
}
return 0;
}
static void get_pci_mode(struct adapter *adapter, struct pci_params *p)
{
u16 val;
if (pci_is_pcie(adapter->pdev)) {
pcie_capability_read_word(adapter->pdev, PCI_EXP_LNKSTA, &val);
p->speed = val & PCI_EXP_LNKSTA_CLS;
p->width = (val & PCI_EXP_LNKSTA_NLW) >> 4;
}
}
static void init_link_config(struct link_config *lc, unsigned int caps)
{
lc->supported = caps;
lc->requested_speed = 0;
lc->speed = 0;
lc->requested_fc = lc->fc = PAUSE_RX | PAUSE_TX;
if (lc->supported & FW_PORT_CAP_ANEG) {
lc->advertising = lc->supported & ADVERT_MASK;
lc->autoneg = AUTONEG_ENABLE;
lc->requested_fc |= PAUSE_AUTONEG;
} else {
lc->advertising = 0;
lc->autoneg = AUTONEG_DISABLE;
}
}
int t4_wait_dev_ready(void __iomem *regs)
{
u32 whoami;
whoami = readl(regs + PL_WHOAMI_A);
if (whoami != 0xffffffff && whoami != CIM_PF_NOACCESS)
return 0;
msleep(500);
whoami = readl(regs + PL_WHOAMI_A);
return (whoami != 0xffffffff && whoami != CIM_PF_NOACCESS ? 0 : -EIO);
}
static int get_flash_params(struct adapter *adap)
{
static struct flash_desc supported_flash[] = {
{ 0x150201, 4 << 20 },
};
int ret;
u32 info;
ret = sf1_write(adap, 1, 1, 0, SF_RD_ID);
if (!ret)
ret = sf1_read(adap, 3, 0, 1, &info);
t4_write_reg(adap, SF_OP_A, 0);
if (ret)
return ret;
for (ret = 0; ret < ARRAY_SIZE(supported_flash); ++ret)
if (supported_flash[ret].vendor_and_model_id == info) {
adap->params.sf_size = supported_flash[ret].size_mb;
adap->params.sf_nsec =
adap->params.sf_size / SF_SEC_SIZE;
return 0;
}
if ((info & 0xff) != 0x20)
return -EINVAL;
info >>= 16;
if (info >= 0x14 && info < 0x18)
adap->params.sf_nsec = 1 << (info - 16);
else if (info == 0x18)
adap->params.sf_nsec = 64;
else
return -EINVAL;
adap->params.sf_size = 1 << info;
adap->params.sf_fw_start =
t4_read_reg(adap, CIM_BOOT_CFG_A) & BOOTADDR_M;
if (adap->params.sf_size < FLASH_MIN_SIZE)
dev_warn(adap->pdev_dev, "WARNING!!! FLASH size %#x < %#x!!!\n",
adap->params.sf_size, FLASH_MIN_SIZE);
return 0;
}
int t4_prep_adapter(struct adapter *adapter)
{
int ret, ver;
uint16_t device_id;
u32 pl_rev;
get_pci_mode(adapter, &adapter->params.pci);
pl_rev = REV_G(t4_read_reg(adapter, PL_REV_A));
ret = get_flash_params(adapter);
if (ret < 0) {
dev_err(adapter->pdev_dev, "error %d identifying flash\n", ret);
return ret;
}
pci_read_config_word(adapter->pdev, PCI_DEVICE_ID, &device_id);
ver = device_id >> 12;
adapter->params.chip = 0;
switch (ver) {
case CHELSIO_T4:
adapter->params.chip |= CHELSIO_CHIP_CODE(CHELSIO_T4, pl_rev);
break;
case CHELSIO_T5:
adapter->params.chip |= CHELSIO_CHIP_CODE(CHELSIO_T5, pl_rev);
break;
default:
dev_err(adapter->pdev_dev, "Device %d is not supported\n",
device_id);
return -EINVAL;
}
adapter->params.cim_la_size = CIMLA_SIZE;
init_cong_ctrl(adapter->params.a_wnd, adapter->params.b_wnd);
adapter->params.nports = 1;
adapter->params.portvec = 1;
adapter->params.vpd.cclk = 50000;
return 0;
}
int cxgb4_t4_bar2_sge_qregs(struct adapter *adapter,
unsigned int qid,
enum t4_bar2_qtype qtype,
u64 *pbar2_qoffset,
unsigned int *pbar2_qid)
{
unsigned int page_shift, page_size, qpp_shift, qpp_mask;
u64 bar2_page_offset, bar2_qoffset;
unsigned int bar2_qid, bar2_qid_offset, bar2_qinferred;
if (is_t4(adapter->params.chip))
return -EINVAL;
page_shift = adapter->params.sge.hps + 10;
page_size = 1 << page_shift;
qpp_shift = (qtype == T4_BAR2_QTYPE_EGRESS
? adapter->params.sge.eq_qpp
: adapter->params.sge.iq_qpp);
qpp_mask = (1 << qpp_shift) - 1;
bar2_page_offset = ((qid >> qpp_shift) << page_shift);
bar2_qid = qid & qpp_mask;
bar2_qid_offset = bar2_qid * SGE_UDB_SIZE;
bar2_qoffset = bar2_page_offset;
bar2_qinferred = (bar2_qid_offset < page_size);
if (bar2_qinferred) {
bar2_qoffset += bar2_qid_offset;
bar2_qid = 0;
}
*pbar2_qoffset = bar2_qoffset;
*pbar2_qid = bar2_qid;
return 0;
}
int t4_init_devlog_params(struct adapter *adap)
{
struct devlog_params *dparams = &adap->params.devlog;
u32 pf_dparams;
unsigned int devlog_meminfo;
struct fw_devlog_cmd devlog_cmd;
int ret;
pf_dparams =
t4_read_reg(adap, PCIE_FW_REG(PCIE_FW_PF_A, PCIE_FW_PF_DEVLOG));
if (pf_dparams) {
unsigned int nentries, nentries128;
dparams->memtype = PCIE_FW_PF_DEVLOG_MEMTYPE_G(pf_dparams);
dparams->start = PCIE_FW_PF_DEVLOG_ADDR16_G(pf_dparams) << 4;
nentries128 = PCIE_FW_PF_DEVLOG_NENTRIES128_G(pf_dparams);
nentries = (nentries128 + 1) * 128;
dparams->size = nentries * sizeof(struct fw_devlog_e);
return 0;
}
memset(&devlog_cmd, 0, sizeof(devlog_cmd));
devlog_cmd.op_to_write = htonl(FW_CMD_OP_V(FW_DEVLOG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F);
devlog_cmd.retval_len16 = htonl(FW_LEN16(devlog_cmd));
ret = t4_wr_mbox(adap, adap->mbox, &devlog_cmd, sizeof(devlog_cmd),
&devlog_cmd);
if (ret)
return ret;
devlog_meminfo = ntohl(devlog_cmd.memtype_devlog_memaddr16_devlog);
dparams->memtype = FW_DEVLOG_CMD_MEMTYPE_DEVLOG_G(devlog_meminfo);
dparams->start = FW_DEVLOG_CMD_MEMADDR16_DEVLOG_G(devlog_meminfo) << 4;
dparams->size = ntohl(devlog_cmd.memsize_devlog);
return 0;
}
int t4_init_sge_params(struct adapter *adapter)
{
struct sge_params *sge_params = &adapter->params.sge;
u32 hps, qpp;
unsigned int s_hps, s_qpp;
hps = t4_read_reg(adapter, SGE_HOST_PAGE_SIZE_A);
s_hps = (HOSTPAGESIZEPF0_S +
(HOSTPAGESIZEPF1_S - HOSTPAGESIZEPF0_S) * adapter->fn);
sge_params->hps = ((hps >> s_hps) & HOSTPAGESIZEPF0_M);
s_qpp = (QUEUESPERPAGEPF0_S +
(QUEUESPERPAGEPF1_S - QUEUESPERPAGEPF0_S) * adapter->fn);
qpp = t4_read_reg(adapter, SGE_EGRESS_QUEUES_PER_PAGE_PF_A);
sge_params->eq_qpp = ((qpp >> s_qpp) & QUEUESPERPAGEPF0_M);
qpp = t4_read_reg(adapter, SGE_INGRESS_QUEUES_PER_PAGE_PF_A);
sge_params->iq_qpp = ((qpp >> s_qpp) & QUEUESPERPAGEPF0_M);
return 0;
}
int t4_init_tp_params(struct adapter *adap)
{
int chan;
u32 v;
v = t4_read_reg(adap, TP_TIMER_RESOLUTION_A);
adap->params.tp.tre = TIMERRESOLUTION_G(v);
adap->params.tp.dack_re = DELAYEDACKRESOLUTION_G(v);
for (chan = 0; chan < NCHAN; chan++)
adap->params.tp.tx_modq[chan] = chan;
t4_read_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&adap->params.tp.vlan_pri_map, 1,
TP_VLAN_PRI_MAP_A);
t4_read_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&adap->params.tp.ingress_config, 1,
TP_INGRESS_CONFIG_A);
adap->params.tp.vlan_shift = t4_filter_field_shift(adap, VLAN_F);
adap->params.tp.vnic_shift = t4_filter_field_shift(adap, VNIC_ID_F);
adap->params.tp.port_shift = t4_filter_field_shift(adap, PORT_F);
adap->params.tp.protocol_shift = t4_filter_field_shift(adap,
PROTOCOL_F);
if ((adap->params.tp.ingress_config & VNIC_F) == 0)
adap->params.tp.vnic_shift = -1;
return 0;
}
int t4_filter_field_shift(const struct adapter *adap, int filter_sel)
{
unsigned int filter_mode = adap->params.tp.vlan_pri_map;
unsigned int sel;
int field_shift;
if ((filter_mode & filter_sel) == 0)
return -1;
for (sel = 1, field_shift = 0; sel < filter_sel; sel <<= 1) {
switch (filter_mode & sel) {
case FCOE_F:
field_shift += FT_FCOE_W;
break;
case PORT_F:
field_shift += FT_PORT_W;
break;
case VNIC_ID_F:
field_shift += FT_VNIC_ID_W;
break;
case VLAN_F:
field_shift += FT_VLAN_W;
break;
case TOS_F:
field_shift += FT_TOS_W;
break;
case PROTOCOL_F:
field_shift += FT_PROTOCOL_W;
break;
case ETHERTYPE_F:
field_shift += FT_ETHERTYPE_W;
break;
case MACMATCH_F:
field_shift += FT_MACMATCH_W;
break;
case MPSHITTYPE_F:
field_shift += FT_MPSHITTYPE_W;
break;
case FRAGMENTATION_F:
field_shift += FT_FRAGMENTATION_W;
break;
}
}
return field_shift;
}
int t4_port_init(struct adapter *adap, int mbox, int pf, int vf)
{
u8 addr[6];
int ret, i, j = 0;
struct fw_port_cmd c;
struct fw_rss_vi_config_cmd rvc;
memset(&c, 0, sizeof(c));
memset(&rvc, 0, sizeof(rvc));
for_each_port(adap, i) {
unsigned int rss_size;
struct port_info *p = adap2pinfo(adap, i);
while ((adap->params.portvec & (1 << j)) == 0)
j++;
c.op_to_portid = htonl(FW_CMD_OP_V(FW_PORT_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F |
FW_PORT_CMD_PORTID_V(j));
c.action_to_len16 = htonl(
FW_PORT_CMD_ACTION_V(FW_PORT_ACTION_GET_PORT_INFO) |
FW_LEN16(c));
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
if (ret)
return ret;
ret = t4_alloc_vi(adap, mbox, j, pf, vf, 1, addr, &rss_size);
if (ret < 0)
return ret;
p->viid = ret;
p->tx_chan = j;
p->lport = j;
p->rss_size = rss_size;
memcpy(adap->port[i]->dev_addr, addr, ETH_ALEN);
adap->port[i]->dev_port = j;
ret = ntohl(c.u.info.lstatus_to_modtype);
p->mdio_addr = (ret & FW_PORT_CMD_MDIOCAP_F) ?
FW_PORT_CMD_MDIOADDR_G(ret) : -1;
p->port_type = FW_PORT_CMD_PTYPE_G(ret);
p->mod_type = FW_PORT_MOD_TYPE_NA;
rvc.op_to_viid = htonl(FW_CMD_OP_V(FW_RSS_VI_CONFIG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F |
FW_RSS_VI_CONFIG_CMD_VIID(p->viid));
rvc.retval_len16 = htonl(FW_LEN16(rvc));
ret = t4_wr_mbox(adap, mbox, &rvc, sizeof(rvc), &rvc);
if (ret)
return ret;
p->rss_mode = ntohl(rvc.u.basicvirtual.defaultq_to_udpen);
init_link_config(&p->link_cfg, ntohs(c.u.info.pcap));
j++;
}
return 0;
}
void t4_read_cimq_cfg(struct adapter *adap, u16 *base, u16 *size, u16 *thres)
{
unsigned int i, v;
int cim_num_obq = is_t4(adap->params.chip) ?
CIM_NUM_OBQ : CIM_NUM_OBQ_T5;
for (i = 0; i < CIM_NUM_IBQ; i++) {
t4_write_reg(adap, CIM_QUEUE_CONFIG_REF_A, IBQSELECT_F |
QUENUMSELECT_V(i));
v = t4_read_reg(adap, CIM_QUEUE_CONFIG_CTRL_A);
*base++ = CIMQBASE_G(v) * 256;
*size++ = CIMQSIZE_G(v) * 256;
*thres++ = QUEFULLTHRSH_G(v) * 8;
}
for (i = 0; i < cim_num_obq; i++) {
t4_write_reg(adap, CIM_QUEUE_CONFIG_REF_A, OBQSELECT_F |
QUENUMSELECT_V(i));
v = t4_read_reg(adap, CIM_QUEUE_CONFIG_CTRL_A);
*base++ = CIMQBASE_G(v) * 256;
*size++ = CIMQSIZE_G(v) * 256;
}
}
int t4_read_cim_ibq(struct adapter *adap, unsigned int qid, u32 *data, size_t n)
{
int i, err, attempts;
unsigned int addr;
const unsigned int nwords = CIM_IBQ_SIZE * 4;
if (qid > 5 || (n & 3))
return -EINVAL;
addr = qid * nwords;
if (n > nwords)
n = nwords;
attempts = 1000000;
for (i = 0; i < n; i++, addr++) {
t4_write_reg(adap, CIM_IBQ_DBG_CFG_A, IBQDBGADDR_V(addr) |
IBQDBGEN_F);
err = t4_wait_op_done(adap, CIM_IBQ_DBG_CFG_A, IBQDBGBUSY_F, 0,
attempts, 1);
if (err)
return err;
*data++ = t4_read_reg(adap, CIM_IBQ_DBG_DATA_A);
}
t4_write_reg(adap, CIM_IBQ_DBG_CFG_A, 0);
return i;
}
int t4_read_cim_obq(struct adapter *adap, unsigned int qid, u32 *data, size_t n)
{
int i, err;
unsigned int addr, v, nwords;
int cim_num_obq = is_t4(adap->params.chip) ?
CIM_NUM_OBQ : CIM_NUM_OBQ_T5;
if ((qid > (cim_num_obq - 1)) || (n & 3))
return -EINVAL;
t4_write_reg(adap, CIM_QUEUE_CONFIG_REF_A, OBQSELECT_F |
QUENUMSELECT_V(qid));
v = t4_read_reg(adap, CIM_QUEUE_CONFIG_CTRL_A);
addr = CIMQBASE_G(v) * 64;
nwords = CIMQSIZE_G(v) * 64;
if (n > nwords)
n = nwords;
for (i = 0; i < n; i++, addr++) {
t4_write_reg(adap, CIM_OBQ_DBG_CFG_A, OBQDBGADDR_V(addr) |
OBQDBGEN_F);
err = t4_wait_op_done(adap, CIM_OBQ_DBG_CFG_A, OBQDBGBUSY_F, 0,
2, 1);
if (err)
return err;
*data++ = t4_read_reg(adap, CIM_OBQ_DBG_DATA_A);
}
t4_write_reg(adap, CIM_OBQ_DBG_CFG_A, 0);
return i;
}
int t4_cim_read(struct adapter *adap, unsigned int addr, unsigned int n,
unsigned int *valp)
{
int ret = 0;
if (t4_read_reg(adap, CIM_HOST_ACC_CTRL_A) & HOSTBUSY_F)
return -EBUSY;
for ( ; !ret && n--; addr += 4) {
t4_write_reg(adap, CIM_HOST_ACC_CTRL_A, addr);
ret = t4_wait_op_done(adap, CIM_HOST_ACC_CTRL_A, HOSTBUSY_F,
0, 5, 2);
if (!ret)
*valp++ = t4_read_reg(adap, CIM_HOST_ACC_DATA_A);
}
return ret;
}
int t4_cim_write(struct adapter *adap, unsigned int addr, unsigned int n,
const unsigned int *valp)
{
int ret = 0;
if (t4_read_reg(adap, CIM_HOST_ACC_CTRL_A) & HOSTBUSY_F)
return -EBUSY;
for ( ; !ret && n--; addr += 4) {
t4_write_reg(adap, CIM_HOST_ACC_DATA_A, *valp++);
t4_write_reg(adap, CIM_HOST_ACC_CTRL_A, addr | HOSTWRITE_F);
ret = t4_wait_op_done(adap, CIM_HOST_ACC_CTRL_A, HOSTBUSY_F,
0, 5, 2);
}
return ret;
}
static int t4_cim_write1(struct adapter *adap, unsigned int addr,
unsigned int val)
{
return t4_cim_write(adap, addr, 1, &val);
}
int t4_cim_read_la(struct adapter *adap, u32 *la_buf, unsigned int *wrptr)
{
int i, ret;
unsigned int cfg, val, idx;
ret = t4_cim_read(adap, UP_UP_DBG_LA_CFG_A, 1, &cfg);
if (ret)
return ret;
if (cfg & UPDBGLAEN_F) {
ret = t4_cim_write1(adap, UP_UP_DBG_LA_CFG_A, 0);
if (ret)
return ret;
}
ret = t4_cim_read(adap, UP_UP_DBG_LA_CFG_A, 1, &val);
if (ret)
goto restart;
idx = UPDBGLAWRPTR_G(val);
if (wrptr)
*wrptr = idx;
for (i = 0; i < adap->params.cim_la_size; i++) {
ret = t4_cim_write1(adap, UP_UP_DBG_LA_CFG_A,
UPDBGLARDPTR_V(idx) | UPDBGLARDEN_F);
if (ret)
break;
ret = t4_cim_read(adap, UP_UP_DBG_LA_CFG_A, 1, &val);
if (ret)
break;
if (val & UPDBGLARDEN_F) {
ret = -ETIMEDOUT;
break;
}
ret = t4_cim_read(adap, UP_UP_DBG_LA_DATA_A, 1, &la_buf[i]);
if (ret)
break;
idx = (idx + 1) & UPDBGLARDPTR_M;
}
restart:
if (cfg & UPDBGLAEN_F) {
int r = t4_cim_write1(adap, UP_UP_DBG_LA_CFG_A,
cfg & ~UPDBGLARDEN_F);
if (!ret)
ret = r;
}
return ret;
}
void t4_tp_read_la(struct adapter *adap, u64 *la_buf, unsigned int *wrptr)
{
bool last_incomplete;
unsigned int i, cfg, val, idx;
cfg = t4_read_reg(adap, TP_DBG_LA_CONFIG_A) & 0xffff;
if (cfg & DBGLAENABLE_F)
t4_write_reg(adap, TP_DBG_LA_CONFIG_A,
adap->params.tp.la_mask | (cfg ^ DBGLAENABLE_F));
val = t4_read_reg(adap, TP_DBG_LA_CONFIG_A);
idx = DBGLAWPTR_G(val);
last_incomplete = DBGLAMODE_G(val) >= 2 && (val & DBGLAWHLF_F) == 0;
if (last_incomplete)
idx = (idx + 1) & DBGLARPTR_M;
if (wrptr)
*wrptr = idx;
val &= 0xffff;
val &= ~DBGLARPTR_V(DBGLARPTR_M);
val |= adap->params.tp.la_mask;
for (i = 0; i < TPLA_SIZE; i++) {
t4_write_reg(adap, TP_DBG_LA_CONFIG_A, DBGLARPTR_V(idx) | val);
la_buf[i] = t4_read_reg64(adap, TP_DBG_LA_DATAL_A);
idx = (idx + 1) & DBGLARPTR_M;
}
if (last_incomplete)
la_buf[TPLA_SIZE - 1] = ~0ULL;
if (cfg & DBGLAENABLE_F)
t4_write_reg(adap, TP_DBG_LA_CONFIG_A,
cfg | adap->params.tp.la_mask);
}
