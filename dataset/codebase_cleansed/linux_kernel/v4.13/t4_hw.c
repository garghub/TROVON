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
u32 req = FUNCTION_V(adap->pf) | REGISTER_V(reg);
if (CHELSIO_CHIP_VERSION(adap->params.chip) <= CHELSIO_T5)
req |= ENABLE_F;
else
req |= T6_ENABLE_F;
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
asrt.u.assert.filename_0_7, be32_to_cpu(asrt.u.assert.line),
be32_to_cpu(asrt.u.assert.x), be32_to_cpu(asrt.u.assert.y));
}
static void t4_record_mbox(struct adapter *adapter,
const __be64 *cmd, unsigned int size,
int access, int execute)
{
struct mbox_cmd_log *log = adapter->mbox_log;
struct mbox_cmd *entry;
int i;
entry = mbox_cmd_log_entry(log, log->cursor++);
if (log->cursor == log->size)
log->cursor = 0;
for (i = 0; i < size / 8; i++)
entry->cmd[i] = be64_to_cpu(cmd[i]);
while (i < MBOX_LEN / 8)
entry->cmd[i++] = 0;
entry->timestamp = jiffies;
entry->seqno = log->seqno++;
entry->access = access;
entry->execute = execute;
}
int t4_wr_mbox_meat_timeout(struct adapter *adap, int mbox, const void *cmd,
int size, void *rpl, bool sleep_ok, int timeout)
{
static const int delay[] = {
1, 1, 3, 5, 10, 10, 20, 50, 100, 200
};
struct mbox_list entry;
u16 access = 0;
u16 execute = 0;
u32 v;
u64 res;
int i, ms, delay_idx, ret;
const __be64 *p = cmd;
u32 data_reg = PF_REG(mbox, CIM_PF_MAILBOX_DATA_A);
u32 ctl_reg = PF_REG(mbox, CIM_PF_MAILBOX_CTRL_A);
__be64 cmd_rpl[MBOX_LEN / 8];
u32 pcie_fw;
if ((size & 15) || size > MBOX_LEN)
return -EINVAL;
if (adap->pdev->error_state != pci_channel_io_normal)
return -EIO;
if (timeout < 0) {
sleep_ok = false;
timeout = -timeout;
}
spin_lock(&adap->mbox_lock);
list_add_tail(&entry.list, &adap->mlist.list);
spin_unlock(&adap->mbox_lock);
delay_idx = 0;
ms = delay[0];
for (i = 0; ; i += ms) {
pcie_fw = t4_read_reg(adap, PCIE_FW_A);
if (i > FW_CMD_MAX_TIMEOUT || (pcie_fw & PCIE_FW_ERR_F)) {
spin_lock(&adap->mbox_lock);
list_del(&entry.list);
spin_unlock(&adap->mbox_lock);
ret = (pcie_fw & PCIE_FW_ERR_F) ? -ENXIO : -EBUSY;
t4_record_mbox(adap, cmd, size, access, ret);
return ret;
}
if (list_first_entry(&adap->mlist.list, struct mbox_list,
list) == &entry)
break;
if (sleep_ok) {
ms = delay[delay_idx];
if (delay_idx < ARRAY_SIZE(delay) - 1)
delay_idx++;
msleep(ms);
} else {
mdelay(ms);
}
}
v = MBOWNER_G(t4_read_reg(adap, ctl_reg));
for (i = 0; v == MBOX_OWNER_NONE && i < 3; i++)
v = MBOWNER_G(t4_read_reg(adap, ctl_reg));
if (v != MBOX_OWNER_DRV) {
spin_lock(&adap->mbox_lock);
list_del(&entry.list);
spin_unlock(&adap->mbox_lock);
ret = (v == MBOX_OWNER_FW) ? -EBUSY : -ETIMEDOUT;
t4_record_mbox(adap, cmd, size, access, ret);
return ret;
}
t4_record_mbox(adap, cmd, size, access, 0);
for (i = 0; i < size; i += 8)
t4_write_reg64(adap, data_reg + i, be64_to_cpu(*p++));
t4_write_reg(adap, ctl_reg, MBMSGVALID_F | MBOWNER_V(MBOX_OWNER_FW));
t4_read_reg(adap, ctl_reg);
delay_idx = 0;
ms = delay[0];
for (i = 0;
!((pcie_fw = t4_read_reg(adap, PCIE_FW_A)) & PCIE_FW_ERR_F) &&
i < timeout;
i += ms) {
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
get_mbox_rpl(adap, cmd_rpl, MBOX_LEN / 8, data_reg);
res = be64_to_cpu(cmd_rpl[0]);
if (FW_CMD_OP_G(res >> 32) == FW_DEBUG_CMD) {
fw_asrt(adap, data_reg);
res = FW_CMD_RETVAL_V(EIO);
} else if (rpl) {
memcpy(rpl, cmd_rpl, size);
}
t4_write_reg(adap, ctl_reg, 0);
execute = i + ms;
t4_record_mbox(adap, cmd_rpl,
MBOX_LEN, access, execute);
spin_lock(&adap->mbox_lock);
list_del(&entry.list);
spin_unlock(&adap->mbox_lock);
return -FW_CMD_RETVAL_G((int)res);
}
}
ret = (pcie_fw & PCIE_FW_ERR_F) ? -ENXIO : -ETIMEDOUT;
t4_record_mbox(adap, cmd, size, access, ret);
dev_err(adap->pdev_dev, "command %#x in mailbox %d timed out\n",
*(const u8 *)cmd, mbox);
t4_report_fw_error(adap);
spin_lock(&adap->mbox_lock);
list_del(&entry.list);
spin_unlock(&adap->mbox_lock);
t4_fatal_err(adap);
return ret;
}
int t4_wr_mbox_meat(struct adapter *adap, int mbox, const void *cmd, int size,
void *rpl, bool sleep_ok)
{
return t4_wr_mbox_meat_timeout(adap, mbox, cmd, size, rpl, sleep_ok,
FW_CMD_MAX_TIMEOUT);
}
static int t4_edc_err_read(struct adapter *adap, int idx)
{
u32 edc_ecc_err_addr_reg;
u32 rdata_reg;
if (is_t4(adap->params.chip)) {
CH_WARN(adap, "%s: T4 NOT supported.\n", __func__);
return 0;
}
if (idx != 0 && idx != 1) {
CH_WARN(adap, "%s: idx %d NOT supported.\n", __func__, idx);
return 0;
}
edc_ecc_err_addr_reg = EDC_T5_REG(EDC_H_ECC_ERR_ADDR_A, idx);
rdata_reg = EDC_T5_REG(EDC_H_BIST_STATUS_RDATA_A, idx);
CH_WARN(adap,
"edc%d err addr 0x%x: 0x%x.\n",
idx, edc_ecc_err_addr_reg,
t4_read_reg(adap, edc_ecc_err_addr_reg));
CH_WARN(adap,
"bist: 0x%x, status %llx %llx %llx %llx %llx %llx %llx %llx %llx.\n",
rdata_reg,
(unsigned long long)t4_read_reg64(adap, rdata_reg),
(unsigned long long)t4_read_reg64(adap, rdata_reg + 8),
(unsigned long long)t4_read_reg64(adap, rdata_reg + 16),
(unsigned long long)t4_read_reg64(adap, rdata_reg + 24),
(unsigned long long)t4_read_reg64(adap, rdata_reg + 32),
(unsigned long long)t4_read_reg64(adap, rdata_reg + 40),
(unsigned long long)t4_read_reg64(adap, rdata_reg + 48),
(unsigned long long)t4_read_reg64(adap, rdata_reg + 56),
(unsigned long long)t4_read_reg64(adap, rdata_reg + 64));
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
MA_EXT_MEMORY0_BAR_A));
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
win_pf = is_t4(adap->params.chip) ? 0 : PFNUM_V(adap->pf);
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
u32 t4_read_pcie_cfg4(struct adapter *adap, int reg)
{
u32 val, ldst_addrspace;
struct fw_ldst_cmd ldst_cmd;
int ret;
memset(&ldst_cmd, 0, sizeof(ldst_cmd));
ldst_addrspace = FW_LDST_CMD_ADDRSPACE_V(FW_LDST_ADDRSPC_FUNC_PCIE);
ldst_cmd.op_to_addrspace = cpu_to_be32(FW_CMD_OP_V(FW_LDST_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F |
ldst_addrspace);
ldst_cmd.cycles_to_len16 = cpu_to_be32(FW_LEN16(ldst_cmd));
ldst_cmd.u.pcie.select_naccess = FW_LDST_CMD_NACCESS_V(1);
ldst_cmd.u.pcie.ctrl_to_fn =
(FW_LDST_CMD_LC_F | FW_LDST_CMD_FN_V(adap->pf));
ldst_cmd.u.pcie.r = reg;
ret = t4_wr_mbox(adap, adap->mbox, &ldst_cmd, sizeof(ldst_cmd),
&ldst_cmd);
if (ret == 0)
val = be32_to_cpu(ldst_cmd.u.pcie.data[0]);
else
t4_hw_pci_read_cfg4(adap, reg, &val);
return val;
}
static u32 t4_get_window(struct adapter *adap, u32 pci_base, u64 pci_mask,
u32 memwin_base)
{
u32 ret;
if (is_t4(adap->params.chip)) {
u32 bar0;
bar0 = t4_read_pcie_cfg4(adap, pci_base);
bar0 &= pci_mask;
adap->t4_bar0 = bar0;
ret = bar0 + memwin_base;
} else {
ret = memwin_base;
}
return ret;
}
u32 t4_get_util_window(struct adapter *adap)
{
return t4_get_window(adap, PCI_BASE_ADDRESS_0,
PCI_BASE_ADDRESS_MEM_MASK, MEMWIN0_BASE);
}
void t4_setup_memwin(struct adapter *adap, u32 memwin_base, u32 window)
{
t4_write_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN_A, window),
memwin_base | BIR_V(0) |
WINDOW_V(ilog2(MEMWIN0_APERTURE) - WINDOW_SHIFT_X));
t4_read_reg(adap,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN_A, window));
}
unsigned int t4_get_regs_len(struct adapter *adapter)
{
unsigned int chip_version = CHELSIO_CHIP_VERSION(adapter->params.chip);
switch (chip_version) {
case CHELSIO_T4:
return T4_REGMAP_SIZE;
case CHELSIO_T5:
case CHELSIO_T6:
return T5_REGMAP_SIZE;
}
dev_err(adapter->pdev_dev,
"Unsupported chip version %d\n", chip_version);
return 0;
}
void t4_get_regs(struct adapter *adap, void *buf, size_t buf_size)
{
static const unsigned int t4_reg_ranges[] = {
0x1008, 0x1108,
0x1180, 0x1184,
0x1190, 0x1194,
0x11a0, 0x11a4,
0x11b0, 0x11b4,
0x11fc, 0x123c,
0x1300, 0x173c,
0x1800, 0x18fc,
0x3000, 0x30d8,
0x30e0, 0x30e4,
0x30ec, 0x5910,
0x5920, 0x5924,
0x5960, 0x5960,
0x5968, 0x5968,
0x5970, 0x5970,
0x5978, 0x5978,
0x5980, 0x5980,
0x5988, 0x5988,
0x5990, 0x5990,
0x5998, 0x5998,
0x59a0, 0x59d4,
0x5a00, 0x5ae0,
0x5ae8, 0x5ae8,
0x5af0, 0x5af0,
0x5af8, 0x5af8,
0x6000, 0x6098,
0x6100, 0x6150,
0x6200, 0x6208,
0x6240, 0x6248,
0x6280, 0x62b0,
0x62c0, 0x6338,
0x6370, 0x638c,
0x6400, 0x643c,
0x6500, 0x6524,
0x6a00, 0x6a04,
0x6a14, 0x6a38,
0x6a60, 0x6a70,
0x6a78, 0x6a78,
0x6b00, 0x6b0c,
0x6b1c, 0x6b84,
0x6bf0, 0x6bf8,
0x6c00, 0x6c0c,
0x6c1c, 0x6c84,
0x6cf0, 0x6cf8,
0x6d00, 0x6d0c,
0x6d1c, 0x6d84,
0x6df0, 0x6df8,
0x6e00, 0x6e0c,
0x6e1c, 0x6e84,
0x6ef0, 0x6ef8,
0x6f00, 0x6f0c,
0x6f1c, 0x6f84,
0x6ff0, 0x6ff8,
0x7000, 0x700c,
0x701c, 0x7084,
0x70f0, 0x70f8,
0x7100, 0x710c,
0x711c, 0x7184,
0x71f0, 0x71f8,
0x7200, 0x720c,
0x721c, 0x7284,
0x72f0, 0x72f8,
0x7300, 0x730c,
0x731c, 0x7384,
0x73f0, 0x73f8,
0x7400, 0x7450,
0x7500, 0x7530,
0x7600, 0x760c,
0x7614, 0x761c,
0x7680, 0x76cc,
0x7700, 0x7798,
0x77c0, 0x77fc,
0x7900, 0x79fc,
0x7b00, 0x7b58,
0x7b60, 0x7b84,
0x7b8c, 0x7c38,
0x7d00, 0x7d38,
0x7d40, 0x7d80,
0x7d8c, 0x7ddc,
0x7de4, 0x7e04,
0x7e10, 0x7e1c,
0x7e24, 0x7e38,
0x7e40, 0x7e44,
0x7e4c, 0x7e78,
0x7e80, 0x7ea4,
0x7eac, 0x7edc,
0x7ee8, 0x7efc,
0x8dc0, 0x8e04,
0x8e10, 0x8e1c,
0x8e30, 0x8e78,
0x8ea0, 0x8eb8,
0x8ec0, 0x8f6c,
0x8fc0, 0x9008,
0x9010, 0x9058,
0x9060, 0x9060,
0x9068, 0x9074,
0x90fc, 0x90fc,
0x9400, 0x9408,
0x9410, 0x9458,
0x9600, 0x9600,
0x9608, 0x9638,
0x9640, 0x96bc,
0x9800, 0x9808,
0x9820, 0x983c,
0x9850, 0x9864,
0x9c00, 0x9c6c,
0x9c80, 0x9cec,
0x9d00, 0x9d6c,
0x9d80, 0x9dec,
0x9e00, 0x9e6c,
0x9e80, 0x9eec,
0x9f00, 0x9f6c,
0x9f80, 0x9fec,
0xd004, 0xd004,
0xd010, 0xd03c,
0xdfc0, 0xdfe0,
0xe000, 0xea7c,
0xf000, 0x11190,
0x19040, 0x1906c,
0x19078, 0x19080,
0x1908c, 0x190e4,
0x190f0, 0x190f8,
0x19100, 0x19110,
0x19120, 0x19124,
0x19150, 0x19194,
0x1919c, 0x191b0,
0x191d0, 0x191e8,
0x19238, 0x1924c,
0x193f8, 0x1943c,
0x1944c, 0x19474,
0x19490, 0x194e0,
0x194f0, 0x194f8,
0x19800, 0x19c08,
0x19c10, 0x19c90,
0x19ca0, 0x19ce4,
0x19cf0, 0x19d40,
0x19d50, 0x19d94,
0x19da0, 0x19de8,
0x19df0, 0x19e40,
0x19e50, 0x19e90,
0x19ea0, 0x19f4c,
0x1a000, 0x1a004,
0x1a010, 0x1a06c,
0x1a0b0, 0x1a0e4,
0x1a0ec, 0x1a0f4,
0x1a100, 0x1a108,
0x1a114, 0x1a120,
0x1a128, 0x1a130,
0x1a138, 0x1a138,
0x1a190, 0x1a1c4,
0x1a1fc, 0x1a1fc,
0x1e040, 0x1e04c,
0x1e284, 0x1e28c,
0x1e2c0, 0x1e2c0,
0x1e2e0, 0x1e2e0,
0x1e300, 0x1e384,
0x1e3c0, 0x1e3c8,
0x1e440, 0x1e44c,
0x1e684, 0x1e68c,
0x1e6c0, 0x1e6c0,
0x1e6e0, 0x1e6e0,
0x1e700, 0x1e784,
0x1e7c0, 0x1e7c8,
0x1e840, 0x1e84c,
0x1ea84, 0x1ea8c,
0x1eac0, 0x1eac0,
0x1eae0, 0x1eae0,
0x1eb00, 0x1eb84,
0x1ebc0, 0x1ebc8,
0x1ec40, 0x1ec4c,
0x1ee84, 0x1ee8c,
0x1eec0, 0x1eec0,
0x1eee0, 0x1eee0,
0x1ef00, 0x1ef84,
0x1efc0, 0x1efc8,
0x1f040, 0x1f04c,
0x1f284, 0x1f28c,
0x1f2c0, 0x1f2c0,
0x1f2e0, 0x1f2e0,
0x1f300, 0x1f384,
0x1f3c0, 0x1f3c8,
0x1f440, 0x1f44c,
0x1f684, 0x1f68c,
0x1f6c0, 0x1f6c0,
0x1f6e0, 0x1f6e0,
0x1f700, 0x1f784,
0x1f7c0, 0x1f7c8,
0x1f840, 0x1f84c,
0x1fa84, 0x1fa8c,
0x1fac0, 0x1fac0,
0x1fae0, 0x1fae0,
0x1fb00, 0x1fb84,
0x1fbc0, 0x1fbc8,
0x1fc40, 0x1fc4c,
0x1fe84, 0x1fe8c,
0x1fec0, 0x1fec0,
0x1fee0, 0x1fee0,
0x1ff00, 0x1ff84,
0x1ffc0, 0x1ffc8,
0x20000, 0x2002c,
0x20100, 0x2013c,
0x20190, 0x201a0,
0x201a8, 0x201b8,
0x201c4, 0x201c8,
0x20200, 0x20318,
0x20400, 0x204b4,
0x204c0, 0x20528,
0x20540, 0x20614,
0x21000, 0x21040,
0x2104c, 0x21060,
0x210c0, 0x210ec,
0x21200, 0x21268,
0x21270, 0x21284,
0x212fc, 0x21388,
0x21400, 0x21404,
0x21500, 0x21500,
0x21510, 0x21518,
0x2152c, 0x21530,
0x2153c, 0x2153c,
0x21550, 0x21554,
0x21600, 0x21600,
0x21608, 0x2161c,
0x21624, 0x21628,
0x21630, 0x21634,
0x2163c, 0x2163c,
0x21700, 0x2171c,
0x21780, 0x2178c,
0x21800, 0x21818,
0x21820, 0x21828,
0x21830, 0x21848,
0x21850, 0x21854,
0x21860, 0x21868,
0x21870, 0x21870,
0x21878, 0x21898,
0x218a0, 0x218a8,
0x218b0, 0x218c8,
0x218d0, 0x218d4,
0x218e0, 0x218e8,
0x218f0, 0x218f0,
0x218f8, 0x21a18,
0x21a20, 0x21a28,
0x21a30, 0x21a48,
0x21a50, 0x21a54,
0x21a60, 0x21a68,
0x21a70, 0x21a70,
0x21a78, 0x21a98,
0x21aa0, 0x21aa8,
0x21ab0, 0x21ac8,
0x21ad0, 0x21ad4,
0x21ae0, 0x21ae8,
0x21af0, 0x21af0,
0x21af8, 0x21c18,
0x21c20, 0x21c20,
0x21c28, 0x21c30,
0x21c38, 0x21c38,
0x21c80, 0x21c98,
0x21ca0, 0x21ca8,
0x21cb0, 0x21cc8,
0x21cd0, 0x21cd4,
0x21ce0, 0x21ce8,
0x21cf0, 0x21cf0,
0x21cf8, 0x21d7c,
0x21e00, 0x21e04,
0x22000, 0x2202c,
0x22100, 0x2213c,
0x22190, 0x221a0,
0x221a8, 0x221b8,
0x221c4, 0x221c8,
0x22200, 0x22318,
0x22400, 0x224b4,
0x224c0, 0x22528,
0x22540, 0x22614,
0x23000, 0x23040,
0x2304c, 0x23060,
0x230c0, 0x230ec,
0x23200, 0x23268,
0x23270, 0x23284,
0x232fc, 0x23388,
0x23400, 0x23404,
0x23500, 0x23500,
0x23510, 0x23518,
0x2352c, 0x23530,
0x2353c, 0x2353c,
0x23550, 0x23554,
0x23600, 0x23600,
0x23608, 0x2361c,
0x23624, 0x23628,
0x23630, 0x23634,
0x2363c, 0x2363c,
0x23700, 0x2371c,
0x23780, 0x2378c,
0x23800, 0x23818,
0x23820, 0x23828,
0x23830, 0x23848,
0x23850, 0x23854,
0x23860, 0x23868,
0x23870, 0x23870,
0x23878, 0x23898,
0x238a0, 0x238a8,
0x238b0, 0x238c8,
0x238d0, 0x238d4,
0x238e0, 0x238e8,
0x238f0, 0x238f0,
0x238f8, 0x23a18,
0x23a20, 0x23a28,
0x23a30, 0x23a48,
0x23a50, 0x23a54,
0x23a60, 0x23a68,
0x23a70, 0x23a70,
0x23a78, 0x23a98,
0x23aa0, 0x23aa8,
0x23ab0, 0x23ac8,
0x23ad0, 0x23ad4,
0x23ae0, 0x23ae8,
0x23af0, 0x23af0,
0x23af8, 0x23c18,
0x23c20, 0x23c20,
0x23c28, 0x23c30,
0x23c38, 0x23c38,
0x23c80, 0x23c98,
0x23ca0, 0x23ca8,
0x23cb0, 0x23cc8,
0x23cd0, 0x23cd4,
0x23ce0, 0x23ce8,
0x23cf0, 0x23cf0,
0x23cf8, 0x23d7c,
0x23e00, 0x23e04,
0x24000, 0x2402c,
0x24100, 0x2413c,
0x24190, 0x241a0,
0x241a8, 0x241b8,
0x241c4, 0x241c8,
0x24200, 0x24318,
0x24400, 0x244b4,
0x244c0, 0x24528,
0x24540, 0x24614,
0x25000, 0x25040,
0x2504c, 0x25060,
0x250c0, 0x250ec,
0x25200, 0x25268,
0x25270, 0x25284,
0x252fc, 0x25388,
0x25400, 0x25404,
0x25500, 0x25500,
0x25510, 0x25518,
0x2552c, 0x25530,
0x2553c, 0x2553c,
0x25550, 0x25554,
0x25600, 0x25600,
0x25608, 0x2561c,
0x25624, 0x25628,
0x25630, 0x25634,
0x2563c, 0x2563c,
0x25700, 0x2571c,
0x25780, 0x2578c,
0x25800, 0x25818,
0x25820, 0x25828,
0x25830, 0x25848,
0x25850, 0x25854,
0x25860, 0x25868,
0x25870, 0x25870,
0x25878, 0x25898,
0x258a0, 0x258a8,
0x258b0, 0x258c8,
0x258d0, 0x258d4,
0x258e0, 0x258e8,
0x258f0, 0x258f0,
0x258f8, 0x25a18,
0x25a20, 0x25a28,
0x25a30, 0x25a48,
0x25a50, 0x25a54,
0x25a60, 0x25a68,
0x25a70, 0x25a70,
0x25a78, 0x25a98,
0x25aa0, 0x25aa8,
0x25ab0, 0x25ac8,
0x25ad0, 0x25ad4,
0x25ae0, 0x25ae8,
0x25af0, 0x25af0,
0x25af8, 0x25c18,
0x25c20, 0x25c20,
0x25c28, 0x25c30,
0x25c38, 0x25c38,
0x25c80, 0x25c98,
0x25ca0, 0x25ca8,
0x25cb0, 0x25cc8,
0x25cd0, 0x25cd4,
0x25ce0, 0x25ce8,
0x25cf0, 0x25cf0,
0x25cf8, 0x25d7c,
0x25e00, 0x25e04,
0x26000, 0x2602c,
0x26100, 0x2613c,
0x26190, 0x261a0,
0x261a8, 0x261b8,
0x261c4, 0x261c8,
0x26200, 0x26318,
0x26400, 0x264b4,
0x264c0, 0x26528,
0x26540, 0x26614,
0x27000, 0x27040,
0x2704c, 0x27060,
0x270c0, 0x270ec,
0x27200, 0x27268,
0x27270, 0x27284,
0x272fc, 0x27388,
0x27400, 0x27404,
0x27500, 0x27500,
0x27510, 0x27518,
0x2752c, 0x27530,
0x2753c, 0x2753c,
0x27550, 0x27554,
0x27600, 0x27600,
0x27608, 0x2761c,
0x27624, 0x27628,
0x27630, 0x27634,
0x2763c, 0x2763c,
0x27700, 0x2771c,
0x27780, 0x2778c,
0x27800, 0x27818,
0x27820, 0x27828,
0x27830, 0x27848,
0x27850, 0x27854,
0x27860, 0x27868,
0x27870, 0x27870,
0x27878, 0x27898,
0x278a0, 0x278a8,
0x278b0, 0x278c8,
0x278d0, 0x278d4,
0x278e0, 0x278e8,
0x278f0, 0x278f0,
0x278f8, 0x27a18,
0x27a20, 0x27a28,
0x27a30, 0x27a48,
0x27a50, 0x27a54,
0x27a60, 0x27a68,
0x27a70, 0x27a70,
0x27a78, 0x27a98,
0x27aa0, 0x27aa8,
0x27ab0, 0x27ac8,
0x27ad0, 0x27ad4,
0x27ae0, 0x27ae8,
0x27af0, 0x27af0,
0x27af8, 0x27c18,
0x27c20, 0x27c20,
0x27c28, 0x27c30,
0x27c38, 0x27c38,
0x27c80, 0x27c98,
0x27ca0, 0x27ca8,
0x27cb0, 0x27cc8,
0x27cd0, 0x27cd4,
0x27ce0, 0x27ce8,
0x27cf0, 0x27cf0,
0x27cf8, 0x27d7c,
0x27e00, 0x27e04,
};
static const unsigned int t5_reg_ranges[] = {
0x1008, 0x10c0,
0x10cc, 0x10f8,
0x1100, 0x1100,
0x110c, 0x1148,
0x1180, 0x1184,
0x1190, 0x1194,
0x11a0, 0x11a4,
0x11b0, 0x11b4,
0x11fc, 0x123c,
0x1280, 0x173c,
0x1800, 0x18fc,
0x3000, 0x3028,
0x3060, 0x30b0,
0x30b8, 0x30d8,
0x30e0, 0x30fc,
0x3140, 0x357c,
0x35a8, 0x35cc,
0x35ec, 0x35ec,
0x3600, 0x5624,
0x56cc, 0x56ec,
0x56f4, 0x5720,
0x5728, 0x575c,
0x580c, 0x5814,
0x5890, 0x589c,
0x58a4, 0x58ac,
0x58b8, 0x58bc,
0x5940, 0x59c8,
0x59d0, 0x59dc,
0x59fc, 0x5a18,
0x5a60, 0x5a70,
0x5a80, 0x5a9c,
0x5b94, 0x5bfc,
0x6000, 0x6020,
0x6028, 0x6040,
0x6058, 0x609c,
0x60a8, 0x614c,
0x7700, 0x7798,
0x77c0, 0x78fc,
0x7b00, 0x7b58,
0x7b60, 0x7b84,
0x7b8c, 0x7c54,
0x7d00, 0x7d38,
0x7d40, 0x7d80,
0x7d8c, 0x7ddc,
0x7de4, 0x7e04,
0x7e10, 0x7e1c,
0x7e24, 0x7e38,
0x7e40, 0x7e44,
0x7e4c, 0x7e78,
0x7e80, 0x7edc,
0x7ee8, 0x7efc,
0x8dc0, 0x8de0,
0x8df8, 0x8e04,
0x8e10, 0x8e84,
0x8ea0, 0x8f84,
0x8fc0, 0x9058,
0x9060, 0x9060,
0x9068, 0x90f8,
0x9400, 0x9408,
0x9410, 0x9470,
0x9600, 0x9600,
0x9608, 0x9638,
0x9640, 0x96f4,
0x9800, 0x9808,
0x9820, 0x983c,
0x9850, 0x9864,
0x9c00, 0x9c6c,
0x9c80, 0x9cec,
0x9d00, 0x9d6c,
0x9d80, 0x9dec,
0x9e00, 0x9e6c,
0x9e80, 0x9eec,
0x9f00, 0x9f6c,
0x9f80, 0xa020,
0xd004, 0xd004,
0xd010, 0xd03c,
0xdfc0, 0xdfe0,
0xe000, 0x1106c,
0x11074, 0x11088,
0x1109c, 0x1117c,
0x11190, 0x11204,
0x19040, 0x1906c,
0x19078, 0x19080,
0x1908c, 0x190e8,
0x190f0, 0x190f8,
0x19100, 0x19110,
0x19120, 0x19124,
0x19150, 0x19194,
0x1919c, 0x191b0,
0x191d0, 0x191e8,
0x19238, 0x19290,
0x193f8, 0x19428,
0x19430, 0x19444,
0x1944c, 0x1946c,
0x19474, 0x19474,
0x19490, 0x194cc,
0x194f0, 0x194f8,
0x19c00, 0x19c08,
0x19c10, 0x19c60,
0x19c94, 0x19ce4,
0x19cf0, 0x19d40,
0x19d50, 0x19d94,
0x19da0, 0x19de8,
0x19df0, 0x19e10,
0x19e50, 0x19e90,
0x19ea0, 0x19f24,
0x19f34, 0x19f34,
0x19f40, 0x19f50,
0x19f90, 0x19fb4,
0x19fc4, 0x19fe4,
0x1a000, 0x1a004,
0x1a010, 0x1a06c,
0x1a0b0, 0x1a0e4,
0x1a0ec, 0x1a0f8,
0x1a100, 0x1a108,
0x1a114, 0x1a120,
0x1a128, 0x1a130,
0x1a138, 0x1a138,
0x1a190, 0x1a1c4,
0x1a1fc, 0x1a1fc,
0x1e008, 0x1e00c,
0x1e040, 0x1e044,
0x1e04c, 0x1e04c,
0x1e284, 0x1e290,
0x1e2c0, 0x1e2c0,
0x1e2e0, 0x1e2e0,
0x1e300, 0x1e384,
0x1e3c0, 0x1e3c8,
0x1e408, 0x1e40c,
0x1e440, 0x1e444,
0x1e44c, 0x1e44c,
0x1e684, 0x1e690,
0x1e6c0, 0x1e6c0,
0x1e6e0, 0x1e6e0,
0x1e700, 0x1e784,
0x1e7c0, 0x1e7c8,
0x1e808, 0x1e80c,
0x1e840, 0x1e844,
0x1e84c, 0x1e84c,
0x1ea84, 0x1ea90,
0x1eac0, 0x1eac0,
0x1eae0, 0x1eae0,
0x1eb00, 0x1eb84,
0x1ebc0, 0x1ebc8,
0x1ec08, 0x1ec0c,
0x1ec40, 0x1ec44,
0x1ec4c, 0x1ec4c,
0x1ee84, 0x1ee90,
0x1eec0, 0x1eec0,
0x1eee0, 0x1eee0,
0x1ef00, 0x1ef84,
0x1efc0, 0x1efc8,
0x1f008, 0x1f00c,
0x1f040, 0x1f044,
0x1f04c, 0x1f04c,
0x1f284, 0x1f290,
0x1f2c0, 0x1f2c0,
0x1f2e0, 0x1f2e0,
0x1f300, 0x1f384,
0x1f3c0, 0x1f3c8,
0x1f408, 0x1f40c,
0x1f440, 0x1f444,
0x1f44c, 0x1f44c,
0x1f684, 0x1f690,
0x1f6c0, 0x1f6c0,
0x1f6e0, 0x1f6e0,
0x1f700, 0x1f784,
0x1f7c0, 0x1f7c8,
0x1f808, 0x1f80c,
0x1f840, 0x1f844,
0x1f84c, 0x1f84c,
0x1fa84, 0x1fa90,
0x1fac0, 0x1fac0,
0x1fae0, 0x1fae0,
0x1fb00, 0x1fb84,
0x1fbc0, 0x1fbc8,
0x1fc08, 0x1fc0c,
0x1fc40, 0x1fc44,
0x1fc4c, 0x1fc4c,
0x1fe84, 0x1fe90,
0x1fec0, 0x1fec0,
0x1fee0, 0x1fee0,
0x1ff00, 0x1ff84,
0x1ffc0, 0x1ffc8,
0x30000, 0x30030,
0x30038, 0x30038,
0x30040, 0x30040,
0x30100, 0x30144,
0x30190, 0x301a0,
0x301a8, 0x301b8,
0x301c4, 0x301c8,
0x301d0, 0x301d0,
0x30200, 0x30318,
0x30400, 0x304b4,
0x304c0, 0x3052c,
0x30540, 0x3061c,
0x30800, 0x30828,
0x30834, 0x30834,
0x308c0, 0x30908,
0x30910, 0x309ac,
0x30a00, 0x30a14,
0x30a1c, 0x30a2c,
0x30a44, 0x30a50,
0x30a74, 0x30a74,
0x30a7c, 0x30afc,
0x30b08, 0x30c24,
0x30d00, 0x30d00,
0x30d08, 0x30d14,
0x30d1c, 0x30d20,
0x30d3c, 0x30d3c,
0x30d48, 0x30d50,
0x31200, 0x3120c,
0x31220, 0x31220,
0x31240, 0x31240,
0x31600, 0x3160c,
0x31a00, 0x31a1c,
0x31e00, 0x31e20,
0x31e38, 0x31e3c,
0x31e80, 0x31e80,
0x31e88, 0x31ea8,
0x31eb0, 0x31eb4,
0x31ec8, 0x31ed4,
0x31fb8, 0x32004,
0x32200, 0x32200,
0x32208, 0x32240,
0x32248, 0x32280,
0x32288, 0x322c0,
0x322c8, 0x322fc,
0x32600, 0x32630,
0x32a00, 0x32abc,
0x32b00, 0x32b10,
0x32b20, 0x32b30,
0x32b40, 0x32b50,
0x32b60, 0x32b70,
0x33000, 0x33028,
0x33030, 0x33048,
0x33060, 0x33068,
0x33070, 0x3309c,
0x330f0, 0x33128,
0x33130, 0x33148,
0x33160, 0x33168,
0x33170, 0x3319c,
0x331f0, 0x33238,
0x33240, 0x33240,
0x33248, 0x33250,
0x3325c, 0x33264,
0x33270, 0x332b8,
0x332c0, 0x332e4,
0x332f8, 0x33338,
0x33340, 0x33340,
0x33348, 0x33350,
0x3335c, 0x33364,
0x33370, 0x333b8,
0x333c0, 0x333e4,
0x333f8, 0x33428,
0x33430, 0x33448,
0x33460, 0x33468,
0x33470, 0x3349c,
0x334f0, 0x33528,
0x33530, 0x33548,
0x33560, 0x33568,
0x33570, 0x3359c,
0x335f0, 0x33638,
0x33640, 0x33640,
0x33648, 0x33650,
0x3365c, 0x33664,
0x33670, 0x336b8,
0x336c0, 0x336e4,
0x336f8, 0x33738,
0x33740, 0x33740,
0x33748, 0x33750,
0x3375c, 0x33764,
0x33770, 0x337b8,
0x337c0, 0x337e4,
0x337f8, 0x337fc,
0x33814, 0x33814,
0x3382c, 0x3382c,
0x33880, 0x3388c,
0x338e8, 0x338ec,
0x33900, 0x33928,
0x33930, 0x33948,
0x33960, 0x33968,
0x33970, 0x3399c,
0x339f0, 0x33a38,
0x33a40, 0x33a40,
0x33a48, 0x33a50,
0x33a5c, 0x33a64,
0x33a70, 0x33ab8,
0x33ac0, 0x33ae4,
0x33af8, 0x33b10,
0x33b28, 0x33b28,
0x33b3c, 0x33b50,
0x33bf0, 0x33c10,
0x33c28, 0x33c28,
0x33c3c, 0x33c50,
0x33cf0, 0x33cfc,
0x34000, 0x34030,
0x34038, 0x34038,
0x34040, 0x34040,
0x34100, 0x34144,
0x34190, 0x341a0,
0x341a8, 0x341b8,
0x341c4, 0x341c8,
0x341d0, 0x341d0,
0x34200, 0x34318,
0x34400, 0x344b4,
0x344c0, 0x3452c,
0x34540, 0x3461c,
0x34800, 0x34828,
0x34834, 0x34834,
0x348c0, 0x34908,
0x34910, 0x349ac,
0x34a00, 0x34a14,
0x34a1c, 0x34a2c,
0x34a44, 0x34a50,
0x34a74, 0x34a74,
0x34a7c, 0x34afc,
0x34b08, 0x34c24,
0x34d00, 0x34d00,
0x34d08, 0x34d14,
0x34d1c, 0x34d20,
0x34d3c, 0x34d3c,
0x34d48, 0x34d50,
0x35200, 0x3520c,
0x35220, 0x35220,
0x35240, 0x35240,
0x35600, 0x3560c,
0x35a00, 0x35a1c,
0x35e00, 0x35e20,
0x35e38, 0x35e3c,
0x35e80, 0x35e80,
0x35e88, 0x35ea8,
0x35eb0, 0x35eb4,
0x35ec8, 0x35ed4,
0x35fb8, 0x36004,
0x36200, 0x36200,
0x36208, 0x36240,
0x36248, 0x36280,
0x36288, 0x362c0,
0x362c8, 0x362fc,
0x36600, 0x36630,
0x36a00, 0x36abc,
0x36b00, 0x36b10,
0x36b20, 0x36b30,
0x36b40, 0x36b50,
0x36b60, 0x36b70,
0x37000, 0x37028,
0x37030, 0x37048,
0x37060, 0x37068,
0x37070, 0x3709c,
0x370f0, 0x37128,
0x37130, 0x37148,
0x37160, 0x37168,
0x37170, 0x3719c,
0x371f0, 0x37238,
0x37240, 0x37240,
0x37248, 0x37250,
0x3725c, 0x37264,
0x37270, 0x372b8,
0x372c0, 0x372e4,
0x372f8, 0x37338,
0x37340, 0x37340,
0x37348, 0x37350,
0x3735c, 0x37364,
0x37370, 0x373b8,
0x373c0, 0x373e4,
0x373f8, 0x37428,
0x37430, 0x37448,
0x37460, 0x37468,
0x37470, 0x3749c,
0x374f0, 0x37528,
0x37530, 0x37548,
0x37560, 0x37568,
0x37570, 0x3759c,
0x375f0, 0x37638,
0x37640, 0x37640,
0x37648, 0x37650,
0x3765c, 0x37664,
0x37670, 0x376b8,
0x376c0, 0x376e4,
0x376f8, 0x37738,
0x37740, 0x37740,
0x37748, 0x37750,
0x3775c, 0x37764,
0x37770, 0x377b8,
0x377c0, 0x377e4,
0x377f8, 0x377fc,
0x37814, 0x37814,
0x3782c, 0x3782c,
0x37880, 0x3788c,
0x378e8, 0x378ec,
0x37900, 0x37928,
0x37930, 0x37948,
0x37960, 0x37968,
0x37970, 0x3799c,
0x379f0, 0x37a38,
0x37a40, 0x37a40,
0x37a48, 0x37a50,
0x37a5c, 0x37a64,
0x37a70, 0x37ab8,
0x37ac0, 0x37ae4,
0x37af8, 0x37b10,
0x37b28, 0x37b28,
0x37b3c, 0x37b50,
0x37bf0, 0x37c10,
0x37c28, 0x37c28,
0x37c3c, 0x37c50,
0x37cf0, 0x37cfc,
0x38000, 0x38030,
0x38038, 0x38038,
0x38040, 0x38040,
0x38100, 0x38144,
0x38190, 0x381a0,
0x381a8, 0x381b8,
0x381c4, 0x381c8,
0x381d0, 0x381d0,
0x38200, 0x38318,
0x38400, 0x384b4,
0x384c0, 0x3852c,
0x38540, 0x3861c,
0x38800, 0x38828,
0x38834, 0x38834,
0x388c0, 0x38908,
0x38910, 0x389ac,
0x38a00, 0x38a14,
0x38a1c, 0x38a2c,
0x38a44, 0x38a50,
0x38a74, 0x38a74,
0x38a7c, 0x38afc,
0x38b08, 0x38c24,
0x38d00, 0x38d00,
0x38d08, 0x38d14,
0x38d1c, 0x38d20,
0x38d3c, 0x38d3c,
0x38d48, 0x38d50,
0x39200, 0x3920c,
0x39220, 0x39220,
0x39240, 0x39240,
0x39600, 0x3960c,
0x39a00, 0x39a1c,
0x39e00, 0x39e20,
0x39e38, 0x39e3c,
0x39e80, 0x39e80,
0x39e88, 0x39ea8,
0x39eb0, 0x39eb4,
0x39ec8, 0x39ed4,
0x39fb8, 0x3a004,
0x3a200, 0x3a200,
0x3a208, 0x3a240,
0x3a248, 0x3a280,
0x3a288, 0x3a2c0,
0x3a2c8, 0x3a2fc,
0x3a600, 0x3a630,
0x3aa00, 0x3aabc,
0x3ab00, 0x3ab10,
0x3ab20, 0x3ab30,
0x3ab40, 0x3ab50,
0x3ab60, 0x3ab70,
0x3b000, 0x3b028,
0x3b030, 0x3b048,
0x3b060, 0x3b068,
0x3b070, 0x3b09c,
0x3b0f0, 0x3b128,
0x3b130, 0x3b148,
0x3b160, 0x3b168,
0x3b170, 0x3b19c,
0x3b1f0, 0x3b238,
0x3b240, 0x3b240,
0x3b248, 0x3b250,
0x3b25c, 0x3b264,
0x3b270, 0x3b2b8,
0x3b2c0, 0x3b2e4,
0x3b2f8, 0x3b338,
0x3b340, 0x3b340,
0x3b348, 0x3b350,
0x3b35c, 0x3b364,
0x3b370, 0x3b3b8,
0x3b3c0, 0x3b3e4,
0x3b3f8, 0x3b428,
0x3b430, 0x3b448,
0x3b460, 0x3b468,
0x3b470, 0x3b49c,
0x3b4f0, 0x3b528,
0x3b530, 0x3b548,
0x3b560, 0x3b568,
0x3b570, 0x3b59c,
0x3b5f0, 0x3b638,
0x3b640, 0x3b640,
0x3b648, 0x3b650,
0x3b65c, 0x3b664,
0x3b670, 0x3b6b8,
0x3b6c0, 0x3b6e4,
0x3b6f8, 0x3b738,
0x3b740, 0x3b740,
0x3b748, 0x3b750,
0x3b75c, 0x3b764,
0x3b770, 0x3b7b8,
0x3b7c0, 0x3b7e4,
0x3b7f8, 0x3b7fc,
0x3b814, 0x3b814,
0x3b82c, 0x3b82c,
0x3b880, 0x3b88c,
0x3b8e8, 0x3b8ec,
0x3b900, 0x3b928,
0x3b930, 0x3b948,
0x3b960, 0x3b968,
0x3b970, 0x3b99c,
0x3b9f0, 0x3ba38,
0x3ba40, 0x3ba40,
0x3ba48, 0x3ba50,
0x3ba5c, 0x3ba64,
0x3ba70, 0x3bab8,
0x3bac0, 0x3bae4,
0x3baf8, 0x3bb10,
0x3bb28, 0x3bb28,
0x3bb3c, 0x3bb50,
0x3bbf0, 0x3bc10,
0x3bc28, 0x3bc28,
0x3bc3c, 0x3bc50,
0x3bcf0, 0x3bcfc,
0x3c000, 0x3c030,
0x3c038, 0x3c038,
0x3c040, 0x3c040,
0x3c100, 0x3c144,
0x3c190, 0x3c1a0,
0x3c1a8, 0x3c1b8,
0x3c1c4, 0x3c1c8,
0x3c1d0, 0x3c1d0,
0x3c200, 0x3c318,
0x3c400, 0x3c4b4,
0x3c4c0, 0x3c52c,
0x3c540, 0x3c61c,
0x3c800, 0x3c828,
0x3c834, 0x3c834,
0x3c8c0, 0x3c908,
0x3c910, 0x3c9ac,
0x3ca00, 0x3ca14,
0x3ca1c, 0x3ca2c,
0x3ca44, 0x3ca50,
0x3ca74, 0x3ca74,
0x3ca7c, 0x3cafc,
0x3cb08, 0x3cc24,
0x3cd00, 0x3cd00,
0x3cd08, 0x3cd14,
0x3cd1c, 0x3cd20,
0x3cd3c, 0x3cd3c,
0x3cd48, 0x3cd50,
0x3d200, 0x3d20c,
0x3d220, 0x3d220,
0x3d240, 0x3d240,
0x3d600, 0x3d60c,
0x3da00, 0x3da1c,
0x3de00, 0x3de20,
0x3de38, 0x3de3c,
0x3de80, 0x3de80,
0x3de88, 0x3dea8,
0x3deb0, 0x3deb4,
0x3dec8, 0x3ded4,
0x3dfb8, 0x3e004,
0x3e200, 0x3e200,
0x3e208, 0x3e240,
0x3e248, 0x3e280,
0x3e288, 0x3e2c0,
0x3e2c8, 0x3e2fc,
0x3e600, 0x3e630,
0x3ea00, 0x3eabc,
0x3eb00, 0x3eb10,
0x3eb20, 0x3eb30,
0x3eb40, 0x3eb50,
0x3eb60, 0x3eb70,
0x3f000, 0x3f028,
0x3f030, 0x3f048,
0x3f060, 0x3f068,
0x3f070, 0x3f09c,
0x3f0f0, 0x3f128,
0x3f130, 0x3f148,
0x3f160, 0x3f168,
0x3f170, 0x3f19c,
0x3f1f0, 0x3f238,
0x3f240, 0x3f240,
0x3f248, 0x3f250,
0x3f25c, 0x3f264,
0x3f270, 0x3f2b8,
0x3f2c0, 0x3f2e4,
0x3f2f8, 0x3f338,
0x3f340, 0x3f340,
0x3f348, 0x3f350,
0x3f35c, 0x3f364,
0x3f370, 0x3f3b8,
0x3f3c0, 0x3f3e4,
0x3f3f8, 0x3f428,
0x3f430, 0x3f448,
0x3f460, 0x3f468,
0x3f470, 0x3f49c,
0x3f4f0, 0x3f528,
0x3f530, 0x3f548,
0x3f560, 0x3f568,
0x3f570, 0x3f59c,
0x3f5f0, 0x3f638,
0x3f640, 0x3f640,
0x3f648, 0x3f650,
0x3f65c, 0x3f664,
0x3f670, 0x3f6b8,
0x3f6c0, 0x3f6e4,
0x3f6f8, 0x3f738,
0x3f740, 0x3f740,
0x3f748, 0x3f750,
0x3f75c, 0x3f764,
0x3f770, 0x3f7b8,
0x3f7c0, 0x3f7e4,
0x3f7f8, 0x3f7fc,
0x3f814, 0x3f814,
0x3f82c, 0x3f82c,
0x3f880, 0x3f88c,
0x3f8e8, 0x3f8ec,
0x3f900, 0x3f928,
0x3f930, 0x3f948,
0x3f960, 0x3f968,
0x3f970, 0x3f99c,
0x3f9f0, 0x3fa38,
0x3fa40, 0x3fa40,
0x3fa48, 0x3fa50,
0x3fa5c, 0x3fa64,
0x3fa70, 0x3fab8,
0x3fac0, 0x3fae4,
0x3faf8, 0x3fb10,
0x3fb28, 0x3fb28,
0x3fb3c, 0x3fb50,
0x3fbf0, 0x3fc10,
0x3fc28, 0x3fc28,
0x3fc3c, 0x3fc50,
0x3fcf0, 0x3fcfc,
0x40000, 0x4000c,
0x40040, 0x40050,
0x40060, 0x40068,
0x4007c, 0x4008c,
0x40094, 0x400b0,
0x400c0, 0x40144,
0x40180, 0x4018c,
0x40200, 0x40254,
0x40260, 0x40264,
0x40270, 0x40288,
0x40290, 0x40298,
0x402ac, 0x402c8,
0x402d0, 0x402e0,
0x402f0, 0x402f0,
0x40300, 0x4033c,
0x403f8, 0x403fc,
0x41304, 0x413c4,
0x41400, 0x4140c,
0x41414, 0x4141c,
0x41480, 0x414d0,
0x44000, 0x44054,
0x4405c, 0x44078,
0x440c0, 0x44174,
0x44180, 0x441ac,
0x441b4, 0x441b8,
0x441c0, 0x44254,
0x4425c, 0x44278,
0x442c0, 0x44374,
0x44380, 0x443ac,
0x443b4, 0x443b8,
0x443c0, 0x44454,
0x4445c, 0x44478,
0x444c0, 0x44574,
0x44580, 0x445ac,
0x445b4, 0x445b8,
0x445c0, 0x44654,
0x4465c, 0x44678,
0x446c0, 0x44774,
0x44780, 0x447ac,
0x447b4, 0x447b8,
0x447c0, 0x44854,
0x4485c, 0x44878,
0x448c0, 0x44974,
0x44980, 0x449ac,
0x449b4, 0x449b8,
0x449c0, 0x449fc,
0x45000, 0x45004,
0x45010, 0x45030,
0x45040, 0x45060,
0x45068, 0x45068,
0x45080, 0x45084,
0x450a0, 0x450b0,
0x45200, 0x45204,
0x45210, 0x45230,
0x45240, 0x45260,
0x45268, 0x45268,
0x45280, 0x45284,
0x452a0, 0x452b0,
0x460c0, 0x460e4,
0x47000, 0x4703c,
0x47044, 0x4708c,
0x47200, 0x47250,
0x47400, 0x47408,
0x47414, 0x47420,
0x47600, 0x47618,
0x47800, 0x47814,
0x48000, 0x4800c,
0x48040, 0x48050,
0x48060, 0x48068,
0x4807c, 0x4808c,
0x48094, 0x480b0,
0x480c0, 0x48144,
0x48180, 0x4818c,
0x48200, 0x48254,
0x48260, 0x48264,
0x48270, 0x48288,
0x48290, 0x48298,
0x482ac, 0x482c8,
0x482d0, 0x482e0,
0x482f0, 0x482f0,
0x48300, 0x4833c,
0x483f8, 0x483fc,
0x49304, 0x493c4,
0x49400, 0x4940c,
0x49414, 0x4941c,
0x49480, 0x494d0,
0x4c000, 0x4c054,
0x4c05c, 0x4c078,
0x4c0c0, 0x4c174,
0x4c180, 0x4c1ac,
0x4c1b4, 0x4c1b8,
0x4c1c0, 0x4c254,
0x4c25c, 0x4c278,
0x4c2c0, 0x4c374,
0x4c380, 0x4c3ac,
0x4c3b4, 0x4c3b8,
0x4c3c0, 0x4c454,
0x4c45c, 0x4c478,
0x4c4c0, 0x4c574,
0x4c580, 0x4c5ac,
0x4c5b4, 0x4c5b8,
0x4c5c0, 0x4c654,
0x4c65c, 0x4c678,
0x4c6c0, 0x4c774,
0x4c780, 0x4c7ac,
0x4c7b4, 0x4c7b8,
0x4c7c0, 0x4c854,
0x4c85c, 0x4c878,
0x4c8c0, 0x4c974,
0x4c980, 0x4c9ac,
0x4c9b4, 0x4c9b8,
0x4c9c0, 0x4c9fc,
0x4d000, 0x4d004,
0x4d010, 0x4d030,
0x4d040, 0x4d060,
0x4d068, 0x4d068,
0x4d080, 0x4d084,
0x4d0a0, 0x4d0b0,
0x4d200, 0x4d204,
0x4d210, 0x4d230,
0x4d240, 0x4d260,
0x4d268, 0x4d268,
0x4d280, 0x4d284,
0x4d2a0, 0x4d2b0,
0x4e0c0, 0x4e0e4,
0x4f000, 0x4f03c,
0x4f044, 0x4f08c,
0x4f200, 0x4f250,
0x4f400, 0x4f408,
0x4f414, 0x4f420,
0x4f600, 0x4f618,
0x4f800, 0x4f814,
0x50000, 0x50084,
0x50090, 0x500cc,
0x50400, 0x50400,
0x50800, 0x50884,
0x50890, 0x508cc,
0x50c00, 0x50c00,
0x51000, 0x5101c,
0x51300, 0x51308,
};
static const unsigned int t6_reg_ranges[] = {
0x1008, 0x101c,
0x1024, 0x10a8,
0x10b4, 0x10f8,
0x1100, 0x1114,
0x111c, 0x112c,
0x1138, 0x113c,
0x1144, 0x114c,
0x1180, 0x1184,
0x1190, 0x1194,
0x11a0, 0x11a4,
0x11b0, 0x11b4,
0x11fc, 0x1258,
0x1280, 0x12d4,
0x12d9, 0x12d9,
0x12de, 0x12de,
0x12e3, 0x12e3,
0x12e8, 0x133c,
0x1800, 0x18fc,
0x3000, 0x302c,
0x3060, 0x30b0,
0x30b8, 0x30d8,
0x30e0, 0x30fc,
0x3140, 0x357c,
0x35a8, 0x35cc,
0x35ec, 0x35ec,
0x3600, 0x5624,
0x56cc, 0x56ec,
0x56f4, 0x5720,
0x5728, 0x575c,
0x580c, 0x5814,
0x5890, 0x589c,
0x58a4, 0x58ac,
0x58b8, 0x58bc,
0x5940, 0x595c,
0x5980, 0x598c,
0x59b0, 0x59c8,
0x59d0, 0x59dc,
0x59fc, 0x5a18,
0x5a60, 0x5a6c,
0x5a80, 0x5a8c,
0x5a94, 0x5a9c,
0x5b94, 0x5bfc,
0x5c10, 0x5e48,
0x5e50, 0x5e94,
0x5ea0, 0x5eb0,
0x5ec0, 0x5ec0,
0x5ec8, 0x5ed0,
0x6000, 0x6020,
0x6028, 0x6040,
0x6058, 0x609c,
0x60a8, 0x619c,
0x7700, 0x7798,
0x77c0, 0x7880,
0x78cc, 0x78fc,
0x7b00, 0x7b58,
0x7b60, 0x7b84,
0x7b8c, 0x7c54,
0x7d00, 0x7d38,
0x7d40, 0x7d84,
0x7d8c, 0x7ddc,
0x7de4, 0x7e04,
0x7e10, 0x7e1c,
0x7e24, 0x7e38,
0x7e40, 0x7e44,
0x7e4c, 0x7e78,
0x7e80, 0x7edc,
0x7ee8, 0x7efc,
0x8dc0, 0x8de4,
0x8df8, 0x8e04,
0x8e10, 0x8e84,
0x8ea0, 0x8f88,
0x8fb8, 0x9058,
0x9060, 0x9060,
0x9068, 0x90f8,
0x9100, 0x9124,
0x9400, 0x9470,
0x9600, 0x9600,
0x9608, 0x9638,
0x9640, 0x9704,
0x9710, 0x971c,
0x9800, 0x9808,
0x9820, 0x983c,
0x9850, 0x9864,
0x9c00, 0x9c6c,
0x9c80, 0x9cec,
0x9d00, 0x9d6c,
0x9d80, 0x9dec,
0x9e00, 0x9e6c,
0x9e80, 0x9eec,
0x9f00, 0x9f6c,
0x9f80, 0xa020,
0xd004, 0xd03c,
0xd100, 0xd118,
0xd200, 0xd214,
0xd220, 0xd234,
0xd240, 0xd254,
0xd260, 0xd274,
0xd280, 0xd294,
0xd2a0, 0xd2b4,
0xd2c0, 0xd2d4,
0xd2e0, 0xd2f4,
0xd300, 0xd31c,
0xdfc0, 0xdfe0,
0xe000, 0xf008,
0x11000, 0x11014,
0x11048, 0x1106c,
0x11074, 0x11088,
0x11098, 0x11120,
0x1112c, 0x1117c,
0x11190, 0x112e0,
0x11300, 0x1130c,
0x12000, 0x1206c,
0x19040, 0x1906c,
0x19078, 0x19080,
0x1908c, 0x190e8,
0x190f0, 0x190f8,
0x19100, 0x19110,
0x19120, 0x19124,
0x19150, 0x19194,
0x1919c, 0x191b0,
0x191d0, 0x191e8,
0x19238, 0x19290,
0x192a4, 0x192b0,
0x192bc, 0x192bc,
0x19348, 0x1934c,
0x193f8, 0x19418,
0x19420, 0x19428,
0x19430, 0x19444,
0x1944c, 0x1946c,
0x19474, 0x19474,
0x19490, 0x194cc,
0x194f0, 0x194f8,
0x19c00, 0x19c48,
0x19c50, 0x19c80,
0x19c94, 0x19c98,
0x19ca0, 0x19cbc,
0x19ce4, 0x19ce4,
0x19cf0, 0x19cf8,
0x19d00, 0x19d28,
0x19d50, 0x19d78,
0x19d94, 0x19d98,
0x19da0, 0x19dc8,
0x19df0, 0x19e10,
0x19e50, 0x19e6c,
0x19ea0, 0x19ebc,
0x19ec4, 0x19ef4,
0x19f04, 0x19f2c,
0x19f34, 0x19f34,
0x19f40, 0x19f50,
0x19f90, 0x19fac,
0x19fc4, 0x19fc8,
0x19fd0, 0x19fe4,
0x1a000, 0x1a004,
0x1a010, 0x1a06c,
0x1a0b0, 0x1a0e4,
0x1a0ec, 0x1a0f8,
0x1a100, 0x1a108,
0x1a114, 0x1a120,
0x1a128, 0x1a130,
0x1a138, 0x1a138,
0x1a190, 0x1a1c4,
0x1a1fc, 0x1a1fc,
0x1e008, 0x1e00c,
0x1e040, 0x1e044,
0x1e04c, 0x1e04c,
0x1e284, 0x1e290,
0x1e2c0, 0x1e2c0,
0x1e2e0, 0x1e2e0,
0x1e300, 0x1e384,
0x1e3c0, 0x1e3c8,
0x1e408, 0x1e40c,
0x1e440, 0x1e444,
0x1e44c, 0x1e44c,
0x1e684, 0x1e690,
0x1e6c0, 0x1e6c0,
0x1e6e0, 0x1e6e0,
0x1e700, 0x1e784,
0x1e7c0, 0x1e7c8,
0x1e808, 0x1e80c,
0x1e840, 0x1e844,
0x1e84c, 0x1e84c,
0x1ea84, 0x1ea90,
0x1eac0, 0x1eac0,
0x1eae0, 0x1eae0,
0x1eb00, 0x1eb84,
0x1ebc0, 0x1ebc8,
0x1ec08, 0x1ec0c,
0x1ec40, 0x1ec44,
0x1ec4c, 0x1ec4c,
0x1ee84, 0x1ee90,
0x1eec0, 0x1eec0,
0x1eee0, 0x1eee0,
0x1ef00, 0x1ef84,
0x1efc0, 0x1efc8,
0x1f008, 0x1f00c,
0x1f040, 0x1f044,
0x1f04c, 0x1f04c,
0x1f284, 0x1f290,
0x1f2c0, 0x1f2c0,
0x1f2e0, 0x1f2e0,
0x1f300, 0x1f384,
0x1f3c0, 0x1f3c8,
0x1f408, 0x1f40c,
0x1f440, 0x1f444,
0x1f44c, 0x1f44c,
0x1f684, 0x1f690,
0x1f6c0, 0x1f6c0,
0x1f6e0, 0x1f6e0,
0x1f700, 0x1f784,
0x1f7c0, 0x1f7c8,
0x1f808, 0x1f80c,
0x1f840, 0x1f844,
0x1f84c, 0x1f84c,
0x1fa84, 0x1fa90,
0x1fac0, 0x1fac0,
0x1fae0, 0x1fae0,
0x1fb00, 0x1fb84,
0x1fbc0, 0x1fbc8,
0x1fc08, 0x1fc0c,
0x1fc40, 0x1fc44,
0x1fc4c, 0x1fc4c,
0x1fe84, 0x1fe90,
0x1fec0, 0x1fec0,
0x1fee0, 0x1fee0,
0x1ff00, 0x1ff84,
0x1ffc0, 0x1ffc8,
0x30000, 0x30030,
0x30038, 0x30038,
0x30040, 0x30040,
0x30048, 0x30048,
0x30050, 0x30050,
0x3005c, 0x30060,
0x30068, 0x30068,
0x30070, 0x30070,
0x30100, 0x30168,
0x30190, 0x301a0,
0x301a8, 0x301b8,
0x301c4, 0x301c8,
0x301d0, 0x301d0,
0x30200, 0x30320,
0x30400, 0x304b4,
0x304c0, 0x3052c,
0x30540, 0x3061c,
0x30800, 0x308a0,
0x308c0, 0x30908,
0x30910, 0x309b8,
0x30a00, 0x30a04,
0x30a0c, 0x30a14,
0x30a1c, 0x30a2c,
0x30a44, 0x30a50,
0x30a74, 0x30a74,
0x30a7c, 0x30afc,
0x30b08, 0x30c24,
0x30d00, 0x30d14,
0x30d1c, 0x30d3c,
0x30d44, 0x30d4c,
0x30d54, 0x30d74,
0x30d7c, 0x30d7c,
0x30de0, 0x30de0,
0x30e00, 0x30ed4,
0x30f00, 0x30fa4,
0x30fc0, 0x30fc4,
0x31000, 0x31004,
0x31080, 0x310fc,
0x31208, 0x31220,
0x3123c, 0x31254,
0x31300, 0x31300,
0x31308, 0x3131c,
0x31338, 0x3133c,
0x31380, 0x31380,
0x31388, 0x313a8,
0x313b4, 0x313b4,
0x31400, 0x31420,
0x31438, 0x3143c,
0x31480, 0x31480,
0x314a8, 0x314a8,
0x314b0, 0x314b4,
0x314c8, 0x314d4,
0x31a40, 0x31a4c,
0x31af0, 0x31b20,
0x31b38, 0x31b3c,
0x31b80, 0x31b80,
0x31ba8, 0x31ba8,
0x31bb0, 0x31bb4,
0x31bc8, 0x31bd4,
0x32140, 0x3218c,
0x321f0, 0x321f4,
0x32200, 0x32200,
0x32218, 0x32218,
0x32400, 0x32400,
0x32408, 0x3241c,
0x32618, 0x32620,
0x32664, 0x32664,
0x326a8, 0x326a8,
0x326ec, 0x326ec,
0x32a00, 0x32abc,
0x32b00, 0x32b38,
0x32b40, 0x32b58,
0x32b60, 0x32b78,
0x32c00, 0x32c00,
0x32c08, 0x32c3c,
0x32e00, 0x32e2c,
0x32f00, 0x32f2c,
0x33000, 0x3302c,
0x33034, 0x33050,
0x33058, 0x33058,
0x33060, 0x3308c,
0x3309c, 0x330ac,
0x330c0, 0x330c0,
0x330c8, 0x330d0,
0x330d8, 0x330e0,
0x330ec, 0x3312c,
0x33134, 0x33150,
0x33158, 0x33158,
0x33160, 0x3318c,
0x3319c, 0x331ac,
0x331c0, 0x331c0,
0x331c8, 0x331d0,
0x331d8, 0x331e0,
0x331ec, 0x33290,
0x33298, 0x332c4,
0x332e4, 0x33390,
0x33398, 0x333c4,
0x333e4, 0x3342c,
0x33434, 0x33450,
0x33458, 0x33458,
0x33460, 0x3348c,
0x3349c, 0x334ac,
0x334c0, 0x334c0,
0x334c8, 0x334d0,
0x334d8, 0x334e0,
0x334ec, 0x3352c,
0x33534, 0x33550,
0x33558, 0x33558,
0x33560, 0x3358c,
0x3359c, 0x335ac,
0x335c0, 0x335c0,
0x335c8, 0x335d0,
0x335d8, 0x335e0,
0x335ec, 0x33690,
0x33698, 0x336c4,
0x336e4, 0x33790,
0x33798, 0x337c4,
0x337e4, 0x337fc,
0x33814, 0x33814,
0x33854, 0x33868,
0x33880, 0x3388c,
0x338c0, 0x338d0,
0x338e8, 0x338ec,
0x33900, 0x3392c,
0x33934, 0x33950,
0x33958, 0x33958,
0x33960, 0x3398c,
0x3399c, 0x339ac,
0x339c0, 0x339c0,
0x339c8, 0x339d0,
0x339d8, 0x339e0,
0x339ec, 0x33a90,
0x33a98, 0x33ac4,
0x33ae4, 0x33b10,
0x33b24, 0x33b28,
0x33b38, 0x33b50,
0x33bf0, 0x33c10,
0x33c24, 0x33c28,
0x33c38, 0x33c50,
0x33cf0, 0x33cfc,
0x34000, 0x34030,
0x34038, 0x34038,
0x34040, 0x34040,
0x34048, 0x34048,
0x34050, 0x34050,
0x3405c, 0x34060,
0x34068, 0x34068,
0x34070, 0x34070,
0x34100, 0x34168,
0x34190, 0x341a0,
0x341a8, 0x341b8,
0x341c4, 0x341c8,
0x341d0, 0x341d0,
0x34200, 0x34320,
0x34400, 0x344b4,
0x344c0, 0x3452c,
0x34540, 0x3461c,
0x34800, 0x348a0,
0x348c0, 0x34908,
0x34910, 0x349b8,
0x34a00, 0x34a04,
0x34a0c, 0x34a14,
0x34a1c, 0x34a2c,
0x34a44, 0x34a50,
0x34a74, 0x34a74,
0x34a7c, 0x34afc,
0x34b08, 0x34c24,
0x34d00, 0x34d14,
0x34d1c, 0x34d3c,
0x34d44, 0x34d4c,
0x34d54, 0x34d74,
0x34d7c, 0x34d7c,
0x34de0, 0x34de0,
0x34e00, 0x34ed4,
0x34f00, 0x34fa4,
0x34fc0, 0x34fc4,
0x35000, 0x35004,
0x35080, 0x350fc,
0x35208, 0x35220,
0x3523c, 0x35254,
0x35300, 0x35300,
0x35308, 0x3531c,
0x35338, 0x3533c,
0x35380, 0x35380,
0x35388, 0x353a8,
0x353b4, 0x353b4,
0x35400, 0x35420,
0x35438, 0x3543c,
0x35480, 0x35480,
0x354a8, 0x354a8,
0x354b0, 0x354b4,
0x354c8, 0x354d4,
0x35a40, 0x35a4c,
0x35af0, 0x35b20,
0x35b38, 0x35b3c,
0x35b80, 0x35b80,
0x35ba8, 0x35ba8,
0x35bb0, 0x35bb4,
0x35bc8, 0x35bd4,
0x36140, 0x3618c,
0x361f0, 0x361f4,
0x36200, 0x36200,
0x36218, 0x36218,
0x36400, 0x36400,
0x36408, 0x3641c,
0x36618, 0x36620,
0x36664, 0x36664,
0x366a8, 0x366a8,
0x366ec, 0x366ec,
0x36a00, 0x36abc,
0x36b00, 0x36b38,
0x36b40, 0x36b58,
0x36b60, 0x36b78,
0x36c00, 0x36c00,
0x36c08, 0x36c3c,
0x36e00, 0x36e2c,
0x36f00, 0x36f2c,
0x37000, 0x3702c,
0x37034, 0x37050,
0x37058, 0x37058,
0x37060, 0x3708c,
0x3709c, 0x370ac,
0x370c0, 0x370c0,
0x370c8, 0x370d0,
0x370d8, 0x370e0,
0x370ec, 0x3712c,
0x37134, 0x37150,
0x37158, 0x37158,
0x37160, 0x3718c,
0x3719c, 0x371ac,
0x371c0, 0x371c0,
0x371c8, 0x371d0,
0x371d8, 0x371e0,
0x371ec, 0x37290,
0x37298, 0x372c4,
0x372e4, 0x37390,
0x37398, 0x373c4,
0x373e4, 0x3742c,
0x37434, 0x37450,
0x37458, 0x37458,
0x37460, 0x3748c,
0x3749c, 0x374ac,
0x374c0, 0x374c0,
0x374c8, 0x374d0,
0x374d8, 0x374e0,
0x374ec, 0x3752c,
0x37534, 0x37550,
0x37558, 0x37558,
0x37560, 0x3758c,
0x3759c, 0x375ac,
0x375c0, 0x375c0,
0x375c8, 0x375d0,
0x375d8, 0x375e0,
0x375ec, 0x37690,
0x37698, 0x376c4,
0x376e4, 0x37790,
0x37798, 0x377c4,
0x377e4, 0x377fc,
0x37814, 0x37814,
0x37854, 0x37868,
0x37880, 0x3788c,
0x378c0, 0x378d0,
0x378e8, 0x378ec,
0x37900, 0x3792c,
0x37934, 0x37950,
0x37958, 0x37958,
0x37960, 0x3798c,
0x3799c, 0x379ac,
0x379c0, 0x379c0,
0x379c8, 0x379d0,
0x379d8, 0x379e0,
0x379ec, 0x37a90,
0x37a98, 0x37ac4,
0x37ae4, 0x37b10,
0x37b24, 0x37b28,
0x37b38, 0x37b50,
0x37bf0, 0x37c10,
0x37c24, 0x37c28,
0x37c38, 0x37c50,
0x37cf0, 0x37cfc,
0x40040, 0x40040,
0x40080, 0x40084,
0x40100, 0x40100,
0x40140, 0x401bc,
0x40200, 0x40214,
0x40228, 0x40228,
0x40240, 0x40258,
0x40280, 0x40280,
0x40304, 0x40304,
0x40330, 0x4033c,
0x41304, 0x413b8,
0x413c0, 0x413c8,
0x413d0, 0x413dc,
0x413f0, 0x413f0,
0x41400, 0x4140c,
0x41414, 0x4141c,
0x41480, 0x414d0,
0x44000, 0x4407c,
0x440c0, 0x441ac,
0x441b4, 0x4427c,
0x442c0, 0x443ac,
0x443b4, 0x4447c,
0x444c0, 0x445ac,
0x445b4, 0x4467c,
0x446c0, 0x447ac,
0x447b4, 0x4487c,
0x448c0, 0x449ac,
0x449b4, 0x44a7c,
0x44ac0, 0x44bac,
0x44bb4, 0x44c7c,
0x44cc0, 0x44dac,
0x44db4, 0x44e7c,
0x44ec0, 0x44fac,
0x44fb4, 0x4507c,
0x450c0, 0x451ac,
0x451b4, 0x451fc,
0x45800, 0x45804,
0x45810, 0x45830,
0x45840, 0x45860,
0x45868, 0x45868,
0x45880, 0x45884,
0x458a0, 0x458b0,
0x45a00, 0x45a04,
0x45a10, 0x45a30,
0x45a40, 0x45a60,
0x45a68, 0x45a68,
0x45a80, 0x45a84,
0x45aa0, 0x45ab0,
0x460c0, 0x460e4,
0x47000, 0x4703c,
0x47044, 0x4708c,
0x47200, 0x47250,
0x47400, 0x47408,
0x47414, 0x47420,
0x47600, 0x47618,
0x47800, 0x47814,
0x47820, 0x4782c,
0x50000, 0x50084,
0x50090, 0x500cc,
0x50300, 0x50384,
0x50400, 0x50400,
0x50800, 0x50884,
0x50890, 0x508cc,
0x50b00, 0x50b84,
0x50c00, 0x50c00,
0x51000, 0x51020,
0x51028, 0x510b0,
0x51300, 0x51324,
};
u32 *buf_end = (u32 *)((char *)buf + buf_size);
const unsigned int *reg_ranges;
int reg_ranges_size, range;
unsigned int chip_version = CHELSIO_CHIP_VERSION(adap->params.chip);
switch (chip_version) {
case CHELSIO_T4:
reg_ranges = t4_reg_ranges;
reg_ranges_size = ARRAY_SIZE(t4_reg_ranges);
break;
case CHELSIO_T5:
reg_ranges = t5_reg_ranges;
reg_ranges_size = ARRAY_SIZE(t5_reg_ranges);
break;
case CHELSIO_T6:
reg_ranges = t6_reg_ranges;
reg_ranges_size = ARRAY_SIZE(t6_reg_ranges);
break;
default:
dev_err(adap->pdev_dev,
"Unsupported chip version %d\n", chip_version);
return;
}
memset(buf, 0, buf_size);
for (range = 0; range < reg_ranges_size; range += 2) {
unsigned int reg = reg_ranges[range];
unsigned int last_reg = reg_ranges[range + 1];
u32 *bufp = (u32 *)((char *)buf + reg);
while (reg <= last_reg && bufp < buf_end) {
*bufp++ = t4_read_reg(adap, reg);
reg += sizeof(u32);
}
}
}
int t4_seeprom_wp(struct adapter *adapter, bool enable)
{
unsigned int v = enable ? 0xc : 0;
int ret = pci_write_vpd(adapter->pdev, EEPROM_STAT_ADDR, 4, &v);
return ret < 0 ? ret : 0;
}
int t4_get_raw_vpd_params(struct adapter *adapter, struct vpd_params *p)
{
int i, ret = 0, addr;
int ec, sn, pn, na;
u8 *vpd, csum;
unsigned int vpdr_len, kw_offset, id_len;
vpd = vmalloc(VPD_LEN);
if (!vpd)
return -ENOMEM;
ret = pci_set_vpd_size(adapter->pdev, VPD_SIZE);
if (ret < 0)
goto out;
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
FIND_VPD_KW(na, "NA");
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
memcpy(p->na, vpd + na, min(i, MACADDR_LEN));
strim((char *)p->na);
out:
vfree(vpd);
return ret < 0 ? ret : 0;
}
int t4_get_vpd_params(struct adapter *adapter, struct vpd_params *p)
{
u32 cclk_param, cclk_val;
int ret;
ret = t4_get_raw_vpd_params(adapter, p);
if (ret)
return ret;
cclk_param = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_CCLK));
ret = t4_query_params(adapter, adapter->mbox, adapter->pf, 0,
1, &cclk_param, &cclk_val);
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
*data = (__force __u32)(cpu_to_be32(*data));
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
int t4_get_bs_version(struct adapter *adapter, u32 *vers)
{
return t4_read_flash(adapter, FLASH_FWBOOTSTRAP_START +
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
int t4_check_fw_version(struct adapter *adap)
{
int i, ret, major, minor, micro;
int exp_major, exp_minor, exp_micro;
unsigned int chip_version = CHELSIO_CHIP_VERSION(adap->params.chip);
ret = t4_get_fw_version(adap, &adap->params.fw_vers);
for (i = 0; (ret == -EBUSY || ret == -EAGAIN) && i < 3; i++)
ret = t4_get_fw_version(adap, &adap->params.fw_vers);
if (ret)
return ret;
major = FW_HDR_FW_VER_MAJOR_G(adap->params.fw_vers);
minor = FW_HDR_FW_VER_MINOR_G(adap->params.fw_vers);
micro = FW_HDR_FW_VER_MICRO_G(adap->params.fw_vers);
switch (chip_version) {
case CHELSIO_T4:
exp_major = T4FW_MIN_VERSION_MAJOR;
exp_minor = T4FW_MIN_VERSION_MINOR;
exp_micro = T4FW_MIN_VERSION_MICRO;
break;
case CHELSIO_T5:
exp_major = T5FW_MIN_VERSION_MAJOR;
exp_minor = T5FW_MIN_VERSION_MINOR;
exp_micro = T5FW_MIN_VERSION_MICRO;
break;
case CHELSIO_T6:
exp_major = T6FW_MIN_VERSION_MAJOR;
exp_minor = T6FW_MIN_VERSION_MINOR;
exp_micro = T6FW_MIN_VERSION_MICRO;
break;
default:
dev_err(adap->pdev_dev, "Unsupported chip type, %x\n",
adap->chip);
return -EINVAL;
}
if (major < exp_major || (major == exp_major && minor < exp_minor) ||
(major == exp_major && minor == exp_minor && micro < exp_micro)) {
dev_err(adap->pdev_dev,
"Card has firmware version %u.%u.%u, minimum "
"supported firmware is %u.%u.%u.\n", major, minor,
micro, exp_major, exp_minor, exp_micro);
return -EFAULT;
}
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
(is_t5(adap->params.chip) && hdr->chip == FW_HDR_CHIP_T5) ||
(is_t6(adap->params.chip) && hdr->chip == FW_HDR_CHIP_T6))
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
if ((unsigned int)be16_to_cpu(hdr->len512) * 512 != size) {
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
csum += be32_to_cpu(p[i]);
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
((struct fw_hdr *)first_page)->fw_ver = cpu_to_be32(0xffffffff);
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
int t4_phy_fw_ver(struct adapter *adap, int *phy_fw_ver)
{
u32 param, val;
int ret;
param = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_PHYFW) |
FW_PARAMS_PARAM_Y_V(adap->params.portvec) |
FW_PARAMS_PARAM_Z_V(FW_PARAMS_PARAM_DEV_PHYFW_VERSION));
ret = t4_query_params(adap, adap->mbox, adap->pf, 0, 1,
&param, &val);
if (ret < 0)
return ret;
*phy_fw_ver = val;
return 0;
}
int t4_load_phy_fw(struct adapter *adap,
int win, spinlock_t *win_lock,
int (*phy_fw_version)(const u8 *, size_t),
const u8 *phy_fw_data, size_t phy_fw_size)
{
unsigned long mtype = 0, maddr = 0;
u32 param, val;
int cur_phy_fw_ver = 0, new_phy_fw_vers = 0;
int ret;
if (phy_fw_version) {
new_phy_fw_vers = phy_fw_version(phy_fw_data, phy_fw_size);
ret = t4_phy_fw_ver(adap, &cur_phy_fw_ver);
if (ret < 0)
return ret;
if (cur_phy_fw_ver >= new_phy_fw_vers) {
CH_WARN(adap, "PHY Firmware already up-to-date, "
"version %#x\n", cur_phy_fw_ver);
return 0;
}
}
param = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_PHYFW) |
FW_PARAMS_PARAM_Y_V(adap->params.portvec) |
FW_PARAMS_PARAM_Z_V(FW_PARAMS_PARAM_DEV_PHYFW_DOWNLOAD));
val = phy_fw_size;
ret = t4_query_params_rw(adap, adap->mbox, adap->pf, 0, 1,
&param, &val, 1, true);
if (ret < 0)
return ret;
mtype = val >> 8;
maddr = (val & 0xff) << 16;
if (win_lock)
spin_lock_bh(win_lock);
ret = t4_memory_rw(adap, win, mtype, maddr,
phy_fw_size, (__be32 *)phy_fw_data,
T4_MEMORY_WRITE);
if (win_lock)
spin_unlock_bh(win_lock);
if (ret)
return ret;
param = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_PHYFW) |
FW_PARAMS_PARAM_Y_V(adap->params.portvec) |
FW_PARAMS_PARAM_Z_V(FW_PARAMS_PARAM_DEV_PHYFW_DOWNLOAD));
ret = t4_set_params_timeout(adap, adap->mbox, adap->pf, 0, 1,
&param, &val, 30000);
if (phy_fw_version) {
ret = t4_phy_fw_ver(adap, &cur_phy_fw_ver);
if (ret < 0)
return ret;
if (cur_phy_fw_ver != new_phy_fw_vers) {
CH_WARN(adap, "PHY Firmware did not update: "
"version on adapter %#x, "
"version flashed %#x\n",
cur_phy_fw_ver, new_phy_fw_vers);
return -ENXIO;
}
}
return 1;
}
int t4_fwcache(struct adapter *adap, enum fw_params_param_dev_fwcache op)
{
struct fw_params_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn =
cpu_to_be32(FW_CMD_OP_V(FW_PARAMS_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
FW_PARAMS_CMD_PFN_V(adap->pf) |
FW_PARAMS_CMD_VFN_V(0));
c.retval_len16 = cpu_to_be32(FW_LEN16(c));
c.param[0].mnem =
cpu_to_be32(FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_FWCACHE));
c.param[0].val = (__force __be32)op;
return t4_wr_mbox(adap, adap->mbox, &c, sizeof(c), NULL);
}
void t4_cim_read_pif_la(struct adapter *adap, u32 *pif_req, u32 *pif_rsp,
unsigned int *pif_req_wrptr,
unsigned int *pif_rsp_wrptr)
{
int i, j;
u32 cfg, val, req, rsp;
cfg = t4_read_reg(adap, CIM_DEBUGCFG_A);
if (cfg & LADBGEN_F)
t4_write_reg(adap, CIM_DEBUGCFG_A, cfg ^ LADBGEN_F);
val = t4_read_reg(adap, CIM_DEBUGSTS_A);
req = POLADBGWRPTR_G(val);
rsp = PILADBGWRPTR_G(val);
if (pif_req_wrptr)
*pif_req_wrptr = req;
if (pif_rsp_wrptr)
*pif_rsp_wrptr = rsp;
for (i = 0; i < CIM_PIFLA_SIZE; i++) {
for (j = 0; j < 6; j++) {
t4_write_reg(adap, CIM_DEBUGCFG_A, POLADBGRDPTR_V(req) |
PILADBGRDPTR_V(rsp));
*pif_req++ = t4_read_reg(adap, CIM_PO_LA_DEBUGDATA_A);
*pif_rsp++ = t4_read_reg(adap, CIM_PI_LA_DEBUGDATA_A);
req++;
rsp++;
}
req = (req + 2) & POLADBGRDPTR_M;
rsp = (rsp + 2) & PILADBGRDPTR_M;
}
t4_write_reg(adap, CIM_DEBUGCFG_A, cfg);
}
void t4_cim_read_ma_la(struct adapter *adap, u32 *ma_req, u32 *ma_rsp)
{
u32 cfg;
int i, j, idx;
cfg = t4_read_reg(adap, CIM_DEBUGCFG_A);
if (cfg & LADBGEN_F)
t4_write_reg(adap, CIM_DEBUGCFG_A, cfg ^ LADBGEN_F);
for (i = 0; i < CIM_MALA_SIZE; i++) {
for (j = 0; j < 5; j++) {
idx = 8 * i + j;
t4_write_reg(adap, CIM_DEBUGCFG_A, POLADBGRDPTR_V(idx) |
PILADBGRDPTR_V(idx));
*ma_req++ = t4_read_reg(adap, CIM_PO_LA_MADEBUGDATA_A);
*ma_rsp++ = t4_read_reg(adap, CIM_PI_LA_MADEBUGDATA_A);
}
}
t4_write_reg(adap, CIM_DEBUGCFG_A, cfg);
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
int t4_link_l1cfg(struct adapter *adap, unsigned int mbox, unsigned int port,
struct link_config *lc)
{
struct fw_port_cmd c;
unsigned int mdi = FW_PORT_CAP_MDI_V(FW_PORT_CAP_MDI_AUTO);
unsigned int fc = 0, fec = 0, fw_fec = 0;
lc->link_ok = 0;
if (lc->requested_fc & PAUSE_RX)
fc |= FW_PORT_CAP_FC_RX;
if (lc->requested_fc & PAUSE_TX)
fc |= FW_PORT_CAP_FC_TX;
fec = lc->requested_fec & FEC_AUTO ? lc->auto_fec : lc->requested_fec;
if (fec & FEC_RS)
fw_fec |= FW_PORT_CAP_FEC_RS;
if (fec & FEC_BASER_RS)
fw_fec |= FW_PORT_CAP_FEC_BASER_RS;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PORT_CMD) |
FW_CMD_REQUEST_F | FW_CMD_EXEC_F |
FW_PORT_CMD_PORTID_V(port));
c.action_to_len16 =
cpu_to_be32(FW_PORT_CMD_ACTION_V(FW_PORT_ACTION_L1_CFG) |
FW_LEN16(c));
if (!(lc->supported & FW_PORT_CAP_ANEG)) {
c.u.l1cfg.rcap = cpu_to_be32((lc->supported & ADVERT_MASK) |
fc | fw_fec);
lc->fc = lc->requested_fc & (PAUSE_RX | PAUSE_TX);
} else if (lc->autoneg == AUTONEG_DISABLE) {
c.u.l1cfg.rcap = cpu_to_be32(lc->requested_speed | fc |
fw_fec | mdi);
lc->fc = lc->requested_fc & (PAUSE_RX | PAUSE_TX);
} else
c.u.l1cfg.rcap = cpu_to_be32(lc->advertising | fc |
fw_fec | mdi);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_restart_aneg(struct adapter *adap, unsigned int mbox, unsigned int port)
{
struct fw_port_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PORT_CMD) |
FW_CMD_REQUEST_F | FW_CMD_EXEC_F |
FW_PORT_CMD_PORTID_V(port));
c.action_to_len16 =
cpu_to_be32(FW_PORT_CMD_ACTION_V(FW_PORT_ACTION_L1_CFG) |
FW_LEN16(c));
c.u.l1cfg.rcap = cpu_to_be32(FW_PORT_CAP_ANEG);
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
u32 err;
static const struct intr_info sge_intr_info[] = {
{ ERR_CPL_EXCEED_IQE_SIZE_F,
"SGE received CPL exceeding IQE size", -1, 1 },
{ ERR_INVALID_CIDX_INC_F,
"SGE GTS CIDX increment too large", -1, 0 },
{ ERR_CPL_OPCODE_0_F, "SGE received 0-length CPL", -1, 0 },
{ DBFIFO_LP_INT_F, NULL, -1, 0, t4_db_full },
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
{ INGRESS_SIZE_ERR_F, "SGE illegal ingress QID", -1, 0 },
{ EGRESS_SIZE_ERR_F, "SGE illegal egress QID", -1, 0 },
{ 0 }
};
static struct intr_info t4t5_sge_intr_info[] = {
{ ERR_DROPPED_DB_F, NULL, -1, 0, t4_db_dropped },
{ DBFIFO_HP_INT_F, NULL, -1, 0, t4_db_full },
{ ERR_EGR_CTXT_PRIO_F,
"SGE too many priority egress contexts", -1, 0 },
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
v |= t4_handle_intr_status(adapter, SGE_INT_CAUSE3_A, sge_intr_info);
if (CHELSIO_CHIP_VERSION(adapter->params.chip) <= CHELSIO_T5)
v |= t4_handle_intr_status(adapter, SGE_INT_CAUSE3_A,
t4t5_sge_intr_info);
err = t4_read_reg(adapter, SGE_ERROR_STATS_A);
if (err & ERROR_QID_VALID_F) {
dev_err(adapter->pdev_dev, "SGE error for queue %u\n",
ERROR_QID_G(err));
if (err & UNCAPTURED_ERROR_F)
dev_err(adapter->pdev_dev,
"SGE UNCAPTURED_ERROR set (clearing)\n");
t4_write_reg(adapter, SGE_ERROR_STATS_A, ERROR_QID_VALID_F |
UNCAPTURED_ERROR_F);
}
if (v != 0)
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
{ TIMER0INT_F, "CIM TIMER0 interrupt", -1, 1 },
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
u32 val, fw_err;
int fat;
fw_err = t4_read_reg(adapter, PCIE_FW_A);
if (fw_err & PCIE_FW_ERR_F)
t4_report_fw_error(adapter);
val = t4_read_reg(adapter, CIM_HOST_INT_CAUSE_A);
if (val & TIMER0INT_F)
if (!(fw_err & PCIE_FW_ERR_F) ||
(PCIE_FW_EVAL_G(fw_err) != PCIE_FW_EVAL_CRASH))
t4_write_reg(adapter, CIM_HOST_INT_CAUSE_A,
TIMER0INT_F);
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
enum chip_type chip = CHELSIO_CHIP_VERSION(adap->params.chip);
static const struct intr_info le_intr_info[] = {
{ LIPMISS_F, "LE LIP miss", -1, 0 },
{ LIP0_F, "LE 0 LIP error", -1, 0 },
{ PARITYERR_F, "LE parity error", -1, 1 },
{ UNKNOWNCMD_F, "LE unknown command", -1, 1 },
{ REQQPARERR_F, "LE request queue parity error", -1, 1 },
{ 0 }
};
static struct intr_info t6_le_intr_info[] = {
{ T6_LIPMISS_F, "LE LIP miss", -1, 0 },
{ T6_LIP0_F, "LE 0 LIP error", -1, 0 },
{ TCAMINTPERR_F, "LE parity error", -1, 1 },
{ T6_UNKNOWNCMD_F, "LE unknown command", -1, 1 },
{ SSRAMINTPERR_F, "LE request queue parity error", -1, 1 },
{ 0 }
};
if (t4_handle_intr_status(adap, LE_DB_INT_CAUSE_A,
(chip <= CHELSIO_T5) ?
le_intr_info : t6_le_intr_info))
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
t4_edc_err_read(adapter, idx);
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
if (is_t5(adapter->params.chip) && (cause & MC1_F))
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
u32 val = 0;
u32 whoami = t4_read_reg(adapter, PL_WHOAMI_A);
u32 pf = CHELSIO_CHIP_VERSION(adapter->params.chip) <= CHELSIO_T5 ?
SOURCEPF_G(whoami) : T6_SOURCEPF_G(whoami);
if (CHELSIO_CHIP_VERSION(adapter->params.chip) <= CHELSIO_T5)
val = ERR_DROPPED_DB_F | ERR_EGR_CTXT_PRIO_F | DBFIFO_HP_INT_F;
t4_write_reg(adapter, SGE_INT_ENABLE3_A, ERR_CPL_EXCEED_IQE_SIZE_F |
ERR_INVALID_CIDX_INC_F | ERR_CPL_OPCODE_0_F |
ERR_DATA_CPL_ON_HIGH_QID1_F | INGRESS_SIZE_ERR_F |
ERR_DATA_CPL_ON_HIGH_QID0_F | ERR_BAD_DB_PIDX3_F |
ERR_BAD_DB_PIDX2_F | ERR_BAD_DB_PIDX1_F |
ERR_BAD_DB_PIDX0_F | ERR_ING_CTXT_PRIO_F |
DBFIFO_LP_INT_F | EGRESS_SIZE_ERR_F | val);
t4_write_reg(adapter, MYPF_REG(PL_PF_INT_ENABLE_A), PF_INTR_MASK);
t4_set_reg_field(adapter, PL_INT_MAP0_A, 0, 1 << pf);
}
void t4_intr_disable(struct adapter *adapter)
{
u32 whoami, pf;
if (pci_channel_offline(adapter->pdev))
return;
whoami = t4_read_reg(adapter, PL_WHOAMI_A);
pf = CHELSIO_CHIP_VERSION(adapter->params.chip) <= CHELSIO_T5 ?
SOURCEPF_G(whoami) : T6_SOURCEPF_G(whoami);
t4_write_reg(adapter, MYPF_REG(PL_PF_INT_ENABLE_A), 0);
t4_set_reg_field(adapter, PL_INT_MAP0_A, 1 << pf, 0);
}
int t4_config_rss_range(struct adapter *adapter, int mbox, unsigned int viid,
int start, int n, const u16 *rspq, unsigned int nrspq)
{
int ret;
const u16 *rsp = rspq;
const u16 *rsp_end = rspq + nrspq;
struct fw_rss_ind_tbl_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_RSS_IND_TBL_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
FW_RSS_IND_TBL_CMD_VIID_V(viid));
cmd.retval_len16 = cpu_to_be32(FW_LEN16(cmd));
while (n > 0) {
int nq = min(n, 32);
__be32 *qp = &cmd.iq0_to_iq2;
cmd.niqid = cpu_to_be16(nq);
cmd.startidx = cpu_to_be16(start);
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
*qp++ = cpu_to_be32(v);
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
c.op_to_write = cpu_to_be32(FW_CMD_OP_V(FW_RSS_GLB_CONFIG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F);
c.retval_len16 = cpu_to_be32(FW_LEN16(c));
if (mode == FW_RSS_GLB_CONFIG_CMD_MODE_MANUAL) {
c.u.manual.mode_pkd =
cpu_to_be32(FW_RSS_GLB_CONFIG_CMD_MODE_V(mode));
} else if (mode == FW_RSS_GLB_CONFIG_CMD_MODE_BASICVIRTUAL) {
c.u.basicvirtual.mode_pkd =
cpu_to_be32(FW_RSS_GLB_CONFIG_CMD_MODE_V(mode));
c.u.basicvirtual.synmapen_to_hashtoeplitz = cpu_to_be32(flags);
} else
return -EINVAL;
return t4_wr_mbox(adapter, mbox, &c, sizeof(c), NULL);
}
int t4_config_vi_rss(struct adapter *adapter, int mbox, unsigned int viid,
unsigned int flags, unsigned int defq)
{
struct fw_rss_vi_config_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_RSS_VI_CONFIG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
FW_RSS_VI_CONFIG_CMD_VIID_V(viid));
c.retval_len16 = cpu_to_be32(FW_LEN16(c));
c.u.basicvirtual.defaultq_to_udpen = cpu_to_be32(flags |
FW_RSS_VI_CONFIG_CMD_DEFAULTQ_V(defq));
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
static unsigned int t4_use_ldst(struct adapter *adap)
{
return (adap->flags & FW_OK) || !adap->use_bd;
}
static void t4_fw_tp_pio_rw(struct adapter *adap, u32 *vals, unsigned int nregs,
unsigned int start_index, unsigned int rw)
{
int ret, i;
int cmd = FW_LDST_ADDRSPC_TP_PIO;
struct fw_ldst_cmd c;
for (i = 0 ; i < nregs; i++) {
memset(&c, 0, sizeof(c));
c.op_to_addrspace = cpu_to_be32(FW_CMD_OP_V(FW_LDST_CMD) |
FW_CMD_REQUEST_F |
(rw ? FW_CMD_READ_F :
FW_CMD_WRITE_F) |
FW_LDST_CMD_ADDRSPACE_V(cmd));
c.cycles_to_len16 = cpu_to_be32(FW_LEN16(c));
c.u.addrval.addr = cpu_to_be32(start_index + i);
c.u.addrval.val = rw ? 0 : cpu_to_be32(vals[i]);
ret = t4_wr_mbox(adap, adap->mbox, &c, sizeof(c), &c);
if (!ret && rw)
vals[i] = be32_to_cpu(c.u.addrval.val);
}
}
void t4_read_rss_key(struct adapter *adap, u32 *key)
{
if (t4_use_ldst(adap))
t4_fw_tp_pio_rw(adap, key, 10, TP_RSS_SECRET_KEY0_A, 1);
else
t4_read_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A, key, 10,
TP_RSS_SECRET_KEY0_A);
}
void t4_write_rss_key(struct adapter *adap, const u32 *key, int idx)
{
u8 rss_key_addr_cnt = 16;
u32 vrt = t4_read_reg(adap, TP_RSS_CONFIG_VRT_A);
if ((CHELSIO_CHIP_VERSION(adap->params.chip) > CHELSIO_T5) &&
(vrt & KEYEXTEND_F) && (KEYMODE_G(vrt) == 3))
rss_key_addr_cnt = 32;
if (t4_use_ldst(adap))
t4_fw_tp_pio_rw(adap, (void *)key, 10, TP_RSS_SECRET_KEY0_A, 0);
else
t4_write_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A, key, 10,
TP_RSS_SECRET_KEY0_A);
if (idx >= 0 && idx < rss_key_addr_cnt) {
if (rss_key_addr_cnt > 16)
t4_write_reg(adap, TP_RSS_CONFIG_VRT_A,
KEYWRADDRX_V(idx >> 4) |
T6_VFWRADDR_V(idx) | KEYWREN_F);
else
t4_write_reg(adap, TP_RSS_CONFIG_VRT_A,
KEYWRADDR_V(idx) | KEYWREN_F);
}
}
void t4_read_rss_pf_config(struct adapter *adapter, unsigned int index,
u32 *valp)
{
if (t4_use_ldst(adapter))
t4_fw_tp_pio_rw(adapter, valp, 1,
TP_RSS_PF0_CONFIG_A + index, 1);
else
t4_read_indirect(adapter, TP_PIO_ADDR_A, TP_PIO_DATA_A,
valp, 1, TP_RSS_PF0_CONFIG_A + index);
}
void t4_read_rss_vf_config(struct adapter *adapter, unsigned int index,
u32 *vfl, u32 *vfh)
{
u32 vrt, mask, data;
if (CHELSIO_CHIP_VERSION(adapter->params.chip) <= CHELSIO_T5) {
mask = VFWRADDR_V(VFWRADDR_M);
data = VFWRADDR_V(index);
} else {
mask = T6_VFWRADDR_V(T6_VFWRADDR_M);
data = T6_VFWRADDR_V(index);
}
vrt = t4_read_reg(adapter, TP_RSS_CONFIG_VRT_A);
vrt &= ~(VFRDRG_F | VFWREN_F | KEYWREN_F | mask);
vrt |= data | VFRDEN_F;
t4_write_reg(adapter, TP_RSS_CONFIG_VRT_A, vrt);
if (t4_use_ldst(adapter)) {
t4_fw_tp_pio_rw(adapter, vfl, 1, TP_RSS_VFL_CONFIG_A, 1);
t4_fw_tp_pio_rw(adapter, vfh, 1, TP_RSS_VFH_CONFIG_A, 1);
} else {
t4_read_indirect(adapter, TP_PIO_ADDR_A, TP_PIO_DATA_A,
vfl, 1, TP_RSS_VFL_CONFIG_A);
t4_read_indirect(adapter, TP_PIO_ADDR_A, TP_PIO_DATA_A,
vfh, 1, TP_RSS_VFH_CONFIG_A);
}
}
u32 t4_read_rss_pf_map(struct adapter *adapter)
{
u32 pfmap;
if (t4_use_ldst(adapter))
t4_fw_tp_pio_rw(adapter, &pfmap, 1, TP_RSS_PF_MAP_A, 1);
else
t4_read_indirect(adapter, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&pfmap, 1, TP_RSS_PF_MAP_A);
return pfmap;
}
u32 t4_read_rss_pf_mask(struct adapter *adapter)
{
u32 pfmask;
if (t4_use_ldst(adapter))
t4_fw_tp_pio_rw(adapter, &pfmask, 1, TP_RSS_PF_MSK_A, 1);
else
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
v4->tcp_out_rsts = STAT(OUT_RST);
v4->tcp_in_segs = STAT64(IN_SEG);
v4->tcp_out_segs = STAT64(OUT_SEG);
v4->tcp_retrans_segs = STAT64(RXT_SEG);
}
if (v6) {
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, val,
ARRAY_SIZE(val), TP_MIB_TCP_V6OUT_RST_A);
v6->tcp_out_rsts = STAT(OUT_RST);
v6->tcp_in_segs = STAT64(IN_SEG);
v6->tcp_out_segs = STAT64(OUT_SEG);
v6->tcp_retrans_segs = STAT64(RXT_SEG);
}
#undef STAT64
#undef STAT
#undef STAT_IDX
}
void t4_tp_get_err_stats(struct adapter *adap, struct tp_err_stats *st)
{
int nchan = adap->params.arch.nchan;
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A,
st->mac_in_errs, nchan, TP_MIB_MAC_IN_ERR_0_A);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A,
st->hdr_in_errs, nchan, TP_MIB_HDR_IN_ERR_0_A);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A,
st->tcp_in_errs, nchan, TP_MIB_TCP_IN_ERR_0_A);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A,
st->tnl_cong_drops, nchan, TP_MIB_TNL_CNG_DROP_0_A);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A,
st->ofld_chan_drops, nchan, TP_MIB_OFD_CHN_DROP_0_A);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A,
st->tnl_tx_drops, nchan, TP_MIB_TNL_DROP_0_A);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A,
st->ofld_vlan_drops, nchan, TP_MIB_OFD_VLN_DROP_0_A);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A,
st->tcp6_in_errs, nchan, TP_MIB_TCP_V6IN_ERR_0_A);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A,
&st->ofld_no_neigh, 2, TP_MIB_OFD_ARP_DROP_A);
}
void t4_tp_get_cpl_stats(struct adapter *adap, struct tp_cpl_stats *st)
{
int nchan = adap->params.arch.nchan;
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, st->req,
nchan, TP_MIB_CPL_IN_REQ_0_A);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, st->rsp,
nchan, TP_MIB_CPL_OUT_RSP_0_A);
}
void t4_tp_get_rdma_stats(struct adapter *adap, struct tp_rdma_stats *st)
{
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, &st->rqe_dfr_pkt,
2, TP_MIB_RQE_DFR_PKT_A);
}
void t4_get_fcoe_stats(struct adapter *adap, unsigned int idx,
struct tp_fcoe_stats *st)
{
u32 val[2];
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, &st->frames_ddp,
1, TP_MIB_FCOE_DDP_0_A + idx);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, &st->frames_drop,
1, TP_MIB_FCOE_DROP_0_A + idx);
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, val,
2, TP_MIB_FCOE_BYTE_0_HI_A + 2 * idx);
st->octets_ddp = ((u64)val[0] << 32) | val[1];
}
void t4_get_usm_stats(struct adapter *adap, struct tp_usm_stats *st)
{
u32 val[4];
t4_read_indirect(adap, TP_MIB_INDEX_A, TP_MIB_DATA_A, val, 4,
TP_MIB_USM_PKTS_A);
st->frames = val[0];
st->drops = val[1];
st->octets = ((u64)val[2] << 32) | val[3];
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
static u64 chan_rate(struct adapter *adap, unsigned int bytes256)
{
u64 v = bytes256 * adap->params.vpd.cclk;
return v * 62 + v / 2;
}
void t4_get_chan_txrate(struct adapter *adap, u64 *nic_rate, u64 *ofld_rate)
{
u32 v;
v = t4_read_reg(adap, TP_TX_TRATE_A);
nic_rate[0] = chan_rate(adap, TNLRATE0_G(v));
nic_rate[1] = chan_rate(adap, TNLRATE1_G(v));
if (adap->params.arch.nchan == NCHAN) {
nic_rate[2] = chan_rate(adap, TNLRATE2_G(v));
nic_rate[3] = chan_rate(adap, TNLRATE3_G(v));
}
v = t4_read_reg(adap, TP_TX_ORATE_A);
ofld_rate[0] = chan_rate(adap, OFDRATE0_G(v));
ofld_rate[1] = chan_rate(adap, OFDRATE1_G(v));
if (adap->params.arch.nchan == NCHAN) {
ofld_rate[2] = chan_rate(adap, OFDRATE2_G(v));
ofld_rate[3] = chan_rate(adap, OFDRATE3_G(v));
}
}
int t4_set_trace_filter(struct adapter *adap, const struct trace_params *tp,
int idx, int enable)
{
int i, ofst = idx * 4;
u32 data_reg, mask_reg, cfg;
u32 multitrc = TRCMULTIFILTER_F;
if (!enable) {
t4_write_reg(adap, MPS_TRC_FILTER_MATCH_CTL_A_A + ofst, 0);
return 0;
}
cfg = t4_read_reg(adap, MPS_TRC_CFG_A);
if (cfg & TRCMULTIFILTER_F) {
if (tp->snap_len > ((10 * 1024 / 4) - (2 * 8)))
return -EINVAL;
} else {
multitrc = 0;
if (tp->snap_len > 9600 || idx)
return -EINVAL;
}
if (tp->port > (is_t4(adap->params.chip) ? 11 : 19) || tp->invert > 1 ||
tp->skip_len > TFLENGTH_M || tp->skip_ofst > TFOFFSET_M ||
tp->min_len > TFMINPKTSIZE_M)
return -EINVAL;
t4_write_reg(adap, MPS_TRC_FILTER_MATCH_CTL_A_A + ofst, 0);
idx *= (MPS_TRC_FILTER1_MATCH_A - MPS_TRC_FILTER0_MATCH_A);
data_reg = MPS_TRC_FILTER0_MATCH_A + idx;
mask_reg = MPS_TRC_FILTER0_DONT_CARE_A + idx;
for (i = 0; i < TRACE_LEN / 4; i++, data_reg += 4, mask_reg += 4) {
t4_write_reg(adap, data_reg, tp->data[i]);
t4_write_reg(adap, mask_reg, ~tp->mask[i]);
}
t4_write_reg(adap, MPS_TRC_FILTER_MATCH_CTL_B_A + ofst,
TFCAPTUREMAX_V(tp->snap_len) |
TFMINPKTSIZE_V(tp->min_len));
t4_write_reg(adap, MPS_TRC_FILTER_MATCH_CTL_A_A + ofst,
TFOFFSET_V(tp->skip_ofst) | TFLENGTH_V(tp->skip_len) |
(is_t4(adap->params.chip) ?
TFPORT_V(tp->port) | TFEN_F | TFINVERTMATCH_V(tp->invert) :
T5_TFPORT_V(tp->port) | T5_TFEN_F |
T5_TFINVERTMATCH_V(tp->invert)));
return 0;
}
void t4_get_trace_filter(struct adapter *adap, struct trace_params *tp, int idx,
int *enabled)
{
u32 ctla, ctlb;
int i, ofst = idx * 4;
u32 data_reg, mask_reg;
ctla = t4_read_reg(adap, MPS_TRC_FILTER_MATCH_CTL_A_A + ofst);
ctlb = t4_read_reg(adap, MPS_TRC_FILTER_MATCH_CTL_B_A + ofst);
if (is_t4(adap->params.chip)) {
*enabled = !!(ctla & TFEN_F);
tp->port = TFPORT_G(ctla);
tp->invert = !!(ctla & TFINVERTMATCH_F);
} else {
*enabled = !!(ctla & T5_TFEN_F);
tp->port = T5_TFPORT_G(ctla);
tp->invert = !!(ctla & T5_TFINVERTMATCH_F);
}
tp->snap_len = TFCAPTUREMAX_G(ctlb);
tp->min_len = TFMINPKTSIZE_G(ctlb);
tp->skip_ofst = TFOFFSET_G(ctla);
tp->skip_len = TFLENGTH_G(ctla);
ofst = (MPS_TRC_FILTER1_MATCH_A - MPS_TRC_FILTER0_MATCH_A) * idx;
data_reg = MPS_TRC_FILTER0_MATCH_A + ofst;
mask_reg = MPS_TRC_FILTER0_DONT_CARE_A + ofst;
for (i = 0; i < TRACE_LEN / 4; i++, data_reg += 4, mask_reg += 4) {
tp->mask[i] = ~t4_read_reg(adap, mask_reg);
tp->data[i] = t4_read_reg(adap, data_reg) & tp->mask[i];
}
}
void t4_pmtx_get_stats(struct adapter *adap, u32 cnt[], u64 cycles[])
{
int i;
u32 data[2];
for (i = 0; i < adap->params.arch.pm_stats_cnt; i++) {
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
for (i = 0; i < adap->params.arch.pm_stats_cnt; i++) {
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
static inline unsigned int compute_mps_bg_map(struct adapter *adapter,
int pidx)
{
unsigned int chip_version, nports;
chip_version = CHELSIO_CHIP_VERSION(adapter->params.chip);
nports = 1 << NUMPORTS_G(t4_read_reg(adapter, MPS_CMN_CTL_A));
switch (chip_version) {
case CHELSIO_T4:
case CHELSIO_T5:
switch (nports) {
case 1: return 0xf;
case 2: return 3 << (2 * pidx);
case 4: return 1 << pidx;
}
break;
case CHELSIO_T6:
switch (nports) {
case 2: return 1 << (2 * pidx);
}
break;
}
dev_err(adapter->pdev_dev, "Need MPS Buffer Group Map for Chip %0x, Nports %d\n",
chip_version, nports);
return 0;
}
unsigned int t4_get_mps_bg_map(struct adapter *adapter, int pidx)
{
u8 *mps_bg_map;
unsigned int nports;
nports = 1 << NUMPORTS_G(t4_read_reg(adapter, MPS_CMN_CTL_A));
if (pidx >= nports) {
CH_WARN(adapter, "MPS Port Index %d >= Nports %d\n",
pidx, nports);
return 0;
}
mps_bg_map = adapter->params.mps_bg_map;
if (mps_bg_map[pidx])
return mps_bg_map[pidx];
if (adapter->flags & FW_OK) {
u32 param, val;
int ret;
param = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_MPSBGMAP));
ret = t4_query_params_ns(adapter, adapter->mbox, adapter->pf,
0, 1, &param, &val);
if (!ret) {
int p;
for (p = 0; p < MAX_NPORTS; p++, val >>= 8)
mps_bg_map[p] = val & 0xff;
return mps_bg_map[pidx];
}
}
mps_bg_map[pidx] = compute_mps_bg_map(adapter, pidx);
return mps_bg_map[pidx];
}
unsigned int t4_get_tp_ch_map(struct adapter *adap, int pidx)
{
unsigned int chip_version = CHELSIO_CHIP_VERSION(adap->params.chip);
unsigned int nports = 1 << NUMPORTS_G(t4_read_reg(adap, MPS_CMN_CTL_A));
if (pidx >= nports) {
dev_warn(adap->pdev_dev, "TP Port Index %d >= Nports %d\n",
pidx, nports);
return 0;
}
switch (chip_version) {
case CHELSIO_T4:
case CHELSIO_T5:
switch (nports) {
case 1: return 0xf;
case 2: return 3 << (2 * pidx);
case 4: return 1 << pidx;
}
break;
case CHELSIO_T6:
switch (nports) {
case 2: return 1 << pidx;
}
break;
}
dev_err(adap->pdev_dev, "Need TP Channel Map for Chip %0x, Nports %d\n",
chip_version, nports);
return 0;
}
const char *t4_get_port_type_description(enum fw_port_type port_type)
{
static const char *const port_type_description[] = {
"Fiber_XFI",
"Fiber_XAUI",
"BT_SGMII",
"BT_XFI",
"BT_XAUI",
"KX4",
"CX4",
"KX",
"KR",
"SFP",
"BP_AP",
"BP4_AP",
"QSFP_10G",
"QSA",
"QSFP",
"BP40_BA",
"KR4_100G",
"CR4_QSFP",
"CR_QSFP",
"CR2_QSFP",
"SFP28",
"KR_SFP28",
};
if (port_type < ARRAY_SIZE(port_type_description))
return port_type_description[port_type];
return "UNKNOWN";
}
void t4_get_port_stats_offset(struct adapter *adap, int idx,
struct port_stats *stats,
struct port_stats *offset)
{
u64 *s, *o;
int i;
t4_get_port_stats(adap, idx, stats);
for (i = 0, s = (u64 *)stats, o = (u64 *)offset;
i < (sizeof(struct port_stats) / sizeof(u64));
i++, s++, o++)
*s -= *o;
}
void t4_get_port_stats(struct adapter *adap, int idx, struct port_stats *p)
{
u32 bgmap = t4_get_mps_bg_map(adap, idx);
u32 stat_ctl = t4_read_reg(adap, MPS_STAT_CTL_A);
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
if (CHELSIO_CHIP_VERSION(adap->params.chip) >= CHELSIO_T5) {
if (stat_ctl & COUNTPAUSESTATTX_F) {
p->tx_frames -= p->tx_pause;
p->tx_octets -= p->tx_pause * 64;
}
if (stat_ctl & COUNTPAUSEMCTX_F)
p->tx_mcast_frames -= p->tx_pause;
}
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
if (CHELSIO_CHIP_VERSION(adap->params.chip) >= CHELSIO_T5) {
if (stat_ctl & COUNTPAUSESTATRX_F) {
p->rx_frames -= p->rx_pause;
p->rx_octets -= p->rx_pause * 64;
}
if (stat_ctl & COUNTPAUSEMCRX_F)
p->rx_mcast_frames -= p->rx_pause;
}
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
void t4_get_lb_stats(struct adapter *adap, int idx, struct lb_port_stats *p)
{
u32 bgmap = t4_get_mps_bg_map(adap, idx);
#define GET_STAT(name) \
t4_read_reg64(adap, \
(is_t4(adap->params.chip) ? \
PORT_REG(idx, MPS_PORT_STAT_LB_PORT_##name##_L) : \
T5_PORT_REG(idx, MPS_PORT_STAT_LB_PORT_##name##_L)))
#define GET_STAT_COM(name) t4_read_reg64(adap, MPS_STAT_##name##_L)
p->octets = GET_STAT(BYTES);
p->frames = GET_STAT(FRAMES);
p->bcast_frames = GET_STAT(BCAST);
p->mcast_frames = GET_STAT(MCAST);
p->ucast_frames = GET_STAT(UCAST);
p->error_frames = GET_STAT(ERROR);
p->frames_64 = GET_STAT(64B);
p->frames_65_127 = GET_STAT(65B_127B);
p->frames_128_255 = GET_STAT(128B_255B);
p->frames_256_511 = GET_STAT(256B_511B);
p->frames_512_1023 = GET_STAT(512B_1023B);
p->frames_1024_1518 = GET_STAT(1024B_1518B);
p->frames_1519_max = GET_STAT(1519B_MAX);
p->drop = GET_STAT(DROP_FRAMES);
p->ovflow0 = (bgmap & 1) ? GET_STAT_COM(RX_BG_0_LB_DROP_FRAME) : 0;
p->ovflow1 = (bgmap & 2) ? GET_STAT_COM(RX_BG_1_LB_DROP_FRAME) : 0;
p->ovflow2 = (bgmap & 4) ? GET_STAT_COM(RX_BG_2_LB_DROP_FRAME) : 0;
p->ovflow3 = (bgmap & 8) ? GET_STAT_COM(RX_BG_3_LB_DROP_FRAME) : 0;
p->trunc0 = (bgmap & 1) ? GET_STAT_COM(RX_BG_0_LB_TRUNC_FRAME) : 0;
p->trunc1 = (bgmap & 2) ? GET_STAT_COM(RX_BG_1_LB_TRUNC_FRAME) : 0;
p->trunc2 = (bgmap & 4) ? GET_STAT_COM(RX_BG_2_LB_TRUNC_FRAME) : 0;
p->trunc3 = (bgmap & 8) ? GET_STAT_COM(RX_BG_3_LB_TRUNC_FRAME) : 0;
#undef GET_STAT
#undef GET_STAT_COM
}
void t4_mk_filtdelwr(unsigned int ftid, struct fw_filter_wr *wr, int qid)
{
memset(wr, 0, sizeof(*wr));
wr->op_pkd = cpu_to_be32(FW_WR_OP_V(FW_FILTER_WR));
wr->len16_pkd = cpu_to_be32(FW_WR_LEN16_V(sizeof(*wr) / 16));
wr->tid_to_iq = cpu_to_be32(FW_FILTER_WR_TID_V(ftid) |
FW_FILTER_WR_NOREPLY_V(qid < 0));
wr->del_filter_to_l2tix = cpu_to_be32(FW_FILTER_WR_DEL_FILTER_F);
if (qid >= 0)
wr->rx_chan_rx_rpl_iq =
cpu_to_be16(FW_FILTER_WR_RX_RPL_IQ_V(qid));
}
int t4_fwaddrspace_write(struct adapter *adap, unsigned int mbox,
u32 addr, u32 val)
{
u32 ldst_addrspace;
struct fw_ldst_cmd c;
memset(&c, 0, sizeof(c));
ldst_addrspace = FW_LDST_CMD_ADDRSPACE_V(FW_LDST_ADDRSPC_FIRMWARE);
c.op_to_addrspace = cpu_to_be32(FW_CMD_OP_V(FW_LDST_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
ldst_addrspace);
c.cycles_to_len16 = cpu_to_be32(FW_LEN16(c));
c.u.addrval.addr = cpu_to_be32(addr);
c.u.addrval.val = cpu_to_be32(val);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_mdio_rd(struct adapter *adap, unsigned int mbox, unsigned int phy_addr,
unsigned int mmd, unsigned int reg, u16 *valp)
{
int ret;
u32 ldst_addrspace;
struct fw_ldst_cmd c;
memset(&c, 0, sizeof(c));
ldst_addrspace = FW_LDST_CMD_ADDRSPACE_V(FW_LDST_ADDRSPC_MDIO);
c.op_to_addrspace = cpu_to_be32(FW_CMD_OP_V(FW_LDST_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F |
ldst_addrspace);
c.cycles_to_len16 = cpu_to_be32(FW_LEN16(c));
c.u.mdio.paddr_mmd = cpu_to_be16(FW_LDST_CMD_PADDR_V(phy_addr) |
FW_LDST_CMD_MMD_V(mmd));
c.u.mdio.raddr = cpu_to_be16(reg);
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
if (ret == 0)
*valp = be16_to_cpu(c.u.mdio.rval);
return ret;
}
int t4_mdio_wr(struct adapter *adap, unsigned int mbox, unsigned int phy_addr,
unsigned int mmd, unsigned int reg, u16 val)
{
u32 ldst_addrspace;
struct fw_ldst_cmd c;
memset(&c, 0, sizeof(c));
ldst_addrspace = FW_LDST_CMD_ADDRSPACE_V(FW_LDST_ADDRSPC_MDIO);
c.op_to_addrspace = cpu_to_be32(FW_CMD_OP_V(FW_LDST_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
ldst_addrspace);
c.cycles_to_len16 = cpu_to_be32(FW_LEN16(c));
c.u.mdio.paddr_mmd = cpu_to_be16(FW_LDST_CMD_PADDR_V(phy_addr) |
FW_LDST_CMD_MMD_V(mmd));
c.u.mdio.raddr = cpu_to_be16(reg);
c.u.mdio.rval = cpu_to_be16(val);
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
static const char * const t6_decode[] = {
"IDMA_IDLE",
"IDMA_PUSH_MORE_CPL_FIFO",
"IDMA_PUSH_CPL_MSG_HEADER_TO_FIFO",
"IDMA_SGEFLRFLUSH_SEND_PCIEHDR",
"IDMA_PHYSADDR_SEND_PCIEHDR",
"IDMA_PHYSADDR_SEND_PAYLOAD_FIRST",
"IDMA_PHYSADDR_SEND_PAYLOAD",
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
unsigned int chip_version = CHELSIO_CHIP_VERSION(adapter->params.chip);
switch (chip_version) {
case CHELSIO_T4:
sge_idma_decode = (const char **)t4_decode;
sge_idma_decode_nstates = ARRAY_SIZE(t4_decode);
break;
case CHELSIO_T5:
sge_idma_decode = (const char **)t5_decode;
sge_idma_decode_nstates = ARRAY_SIZE(t5_decode);
break;
case CHELSIO_T6:
sge_idma_decode = (const char **)t6_decode;
sge_idma_decode_nstates = ARRAY_SIZE(t6_decode);
break;
default:
dev_err(adapter->pdev_dev,
"Unsupported chip version %d\n", chip_version);
return;
}
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
int t4_sge_ctxt_flush(struct adapter *adap, unsigned int mbox)
{
int ret;
u32 ldst_addrspace;
struct fw_ldst_cmd c;
memset(&c, 0, sizeof(c));
ldst_addrspace = FW_LDST_CMD_ADDRSPACE_V(FW_LDST_ADDRSPC_SGE_EGRC);
c.op_to_addrspace = cpu_to_be32(FW_CMD_OP_V(FW_LDST_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F |
ldst_addrspace);
c.cycles_to_len16 = cpu_to_be32(FW_LEN16(c));
c.u.idctxt.msg_ctxtflush = cpu_to_be32(FW_LDST_CMD_CTXTFLUSH_F);
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
return ret;
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
c.err_to_clearinit = cpu_to_be32(
FW_HELLO_CMD_MASTERDIS_V(master == MASTER_CANT) |
FW_HELLO_CMD_MASTERFORCE_V(master == MASTER_MUST) |
FW_HELLO_CMD_MBMASTER_V(master == MASTER_MUST ?
mbox : FW_HELLO_CMD_MBMASTER_M) |
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
v = be32_to_cpu(c.err_to_clearinit);
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
c.val = cpu_to_be32(reset);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
static int t4_fw_halt(struct adapter *adap, unsigned int mbox, int force)
{
int ret = 0;
if (mbox <= PCIE_FW_MASTER_M) {
struct fw_reset_cmd c;
memset(&c, 0, sizeof(c));
INIT_CMD(c, RESET, WRITE);
c.val = cpu_to_be32(PIORST_F | PIORSTMODE_F);
c.halt_pkd = cpu_to_be32(FW_RESET_CMD_HALT_F);
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
adap->flags &= ~FW_OK;
ret = t4_fw_halt(adap, mbox, force);
if (ret < 0 && !force)
goto out;
ret = t4_load_fw(adap, fw_data, size);
if (ret < 0)
goto out;
reset = ((be32_to_cpu(fw_hdr->flags) & FW_HDR_FLAGS_RESET_HALT) == 0);
ret = t4_fw_restart(adap, mbox, reset);
(void)t4_init_devlog_params(adap);
out:
adap->flags |= FW_OK;
return ret;
}
int t4_fl_pkt_align(struct adapter *adap)
{
u32 sge_control, sge_control2;
unsigned int ingpadboundary, ingpackboundary, fl_align, ingpad_shift;
sge_control = t4_read_reg(adap, SGE_CONTROL_A);
if (CHELSIO_CHIP_VERSION(adap->params.chip) <= CHELSIO_T5)
ingpad_shift = INGPADBOUNDARY_SHIFT_X;
else
ingpad_shift = T6_INGPADBOUNDARY_SHIFT_X;
ingpadboundary = 1 << (INGPADBOUNDARY_G(sge_control) + ingpad_shift);
fl_align = ingpadboundary;
if (!is_t4(adap->params.chip)) {
sge_control2 = t4_read_reg(adap, SGE_CONTROL2_A);
ingpackboundary = INGPACKBOUNDARY_G(sge_control2);
if (ingpackboundary == INGPACKBOUNDARY_16B_X)
ingpackboundary = 16;
else
ingpackboundary = 1 << (ingpackboundary +
INGPACKBOUNDARY_SHIFT_X);
fl_align = max(ingpadboundary, ingpackboundary);
}
return fl_align;
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
unsigned int pack_align;
unsigned int ingpad, ingpack;
unsigned int pcie_cap;
pack_align = fl_align;
pcie_cap = pci_find_capability(adap->pdev, PCI_CAP_ID_EXP);
if (pcie_cap) {
unsigned int mps, mps_log;
u16 devctl;
pci_read_config_word(adap->pdev,
pcie_cap + PCI_EXP_DEVCTL,
&devctl);
mps_log = ((devctl & PCI_EXP_DEVCTL_PAYLOAD) >> 5) + 7;
mps = 1 << mps_log;
if (mps > pack_align)
pack_align = mps;
}
if (pack_align <= 16) {
ingpack = INGPACKBOUNDARY_16B_X;
fl_align = 16;
} else if (pack_align == 32) {
ingpack = INGPACKBOUNDARY_64B_X;
fl_align = 64;
} else {
unsigned int pack_align_log = fls(pack_align) - 1;
ingpack = pack_align_log - INGPACKBOUNDARY_SHIFT_X;
fl_align = pack_align;
}
if (is_t5(adap->params.chip))
ingpad = INGPADBOUNDARY_32B_X;
else
ingpad = T6_INGPADBOUNDARY_8B_X;
t4_set_reg_field(adap, SGE_CONTROL_A,
INGPADBOUNDARY_V(INGPADBOUNDARY_M) |
EGRSTATUSPAGESIZE_F,
INGPADBOUNDARY_V(ingpad) |
EGRSTATUSPAGESIZE_V(stat_len != 64));
t4_set_reg_field(adap, SGE_CONTROL2_A,
INGPACKBOUNDARY_V(INGPACKBOUNDARY_M),
INGPACKBOUNDARY_V(ingpack));
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
int t4_query_params_rw(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int nparams, const u32 *params,
u32 *val, int rw, bool sleep_ok)
{
int i, ret;
struct fw_params_cmd c;
__be32 *p = &c.param[0].mnem;
if (nparams > 7)
return -EINVAL;
memset(&c, 0, sizeof(c));
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_PARAMS_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F |
FW_PARAMS_CMD_PFN_V(pf) |
FW_PARAMS_CMD_VFN_V(vf));
c.retval_len16 = cpu_to_be32(FW_LEN16(c));
for (i = 0; i < nparams; i++) {
*p++ = cpu_to_be32(*params++);
if (rw)
*p = cpu_to_be32(*(val + i));
p++;
}
ret = t4_wr_mbox_meat(adap, mbox, &c, sizeof(c), &c, sleep_ok);
if (ret == 0)
for (i = 0, p = &c.param[0].val; i < nparams; i++, p += 2)
*val++ = be32_to_cpu(*p);
return ret;
}
int t4_query_params(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int nparams, const u32 *params,
u32 *val)
{
return t4_query_params_rw(adap, mbox, pf, vf, nparams, params, val, 0,
true);
}
int t4_query_params_ns(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int nparams, const u32 *params,
u32 *val)
{
return t4_query_params_rw(adap, mbox, pf, vf, nparams, params, val, 0,
false);
}
int t4_set_params_timeout(struct adapter *adap, unsigned int mbox,
unsigned int pf, unsigned int vf,
unsigned int nparams, const u32 *params,
const u32 *val, int timeout)
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
return t4_wr_mbox_timeout(adap, mbox, &c, sizeof(c), NULL, timeout);
}
int t4_set_params(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int nparams, const u32 *params,
const u32 *val)
{
return t4_set_params_timeout(adap, mbox, pf, vf, nparams, params, val,
FW_CMD_MAX_TIMEOUT);
}
int t4_cfg_pfvf(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int txq, unsigned int txq_eth_ctrl,
unsigned int rxqi, unsigned int rxq, unsigned int tc,
unsigned int vi, unsigned int cmask, unsigned int pmask,
unsigned int nexact, unsigned int rcaps, unsigned int wxcaps)
{
struct fw_pfvf_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_PFVF_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | FW_PFVF_CMD_PFN_V(pf) |
FW_PFVF_CMD_VFN_V(vf));
c.retval_len16 = cpu_to_be32(FW_LEN16(c));
c.niqflint_niq = cpu_to_be32(FW_PFVF_CMD_NIQFLINT_V(rxqi) |
FW_PFVF_CMD_NIQ_V(rxq));
c.type_to_neq = cpu_to_be32(FW_PFVF_CMD_CMASK_V(cmask) |
FW_PFVF_CMD_PMASK_V(pmask) |
FW_PFVF_CMD_NEQ_V(txq));
c.tc_to_nexactf = cpu_to_be32(FW_PFVF_CMD_TC_V(tc) |
FW_PFVF_CMD_NVI_V(vi) |
FW_PFVF_CMD_NEXACTF_V(nexact));
c.r_caps_to_nethctrl = cpu_to_be32(FW_PFVF_CMD_R_CAPS_V(rcaps) |
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
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_VI_CMD) | FW_CMD_REQUEST_F |
FW_CMD_WRITE_F | FW_CMD_EXEC_F |
FW_VI_CMD_PFN_V(pf) | FW_VI_CMD_VFN_V(vf));
c.alloc_to_len16 = cpu_to_be32(FW_VI_CMD_ALLOC_F | FW_LEN16(c));
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
*rss_size = FW_VI_CMD_RSSSIZE_G(be16_to_cpu(c.rsssize_pkd));
return FW_VI_CMD_VIID_G(be16_to_cpu(c.type_viid));
}
int t4_free_vi(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int viid)
{
struct fw_vi_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_VI_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_EXEC_F |
FW_VI_CMD_PFN_V(pf) |
FW_VI_CMD_VFN_V(vf));
c.alloc_to_len16 = cpu_to_be32(FW_VI_CMD_FREE_F | FW_LEN16(c));
c.type_viid = cpu_to_be16(FW_VI_CMD_VIID_V(viid));
return t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
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
c.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_RXMODE_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
FW_VI_RXMODE_CMD_VIID_V(viid));
c.retval_len16 = cpu_to_be32(FW_LEN16(c));
c.mtu_to_vlanexen =
cpu_to_be32(FW_VI_RXMODE_CMD_MTU_V(mtu) |
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
int offset, ret = 0;
struct fw_vi_mac_cmd c;
unsigned int nfilters = 0;
unsigned int max_naddr = adap->params.arch.mps_tcam_size;
unsigned int rem = naddr;
if (naddr > max_naddr)
return -EINVAL;
for (offset = 0; offset < naddr ; ) {
unsigned int fw_naddr = (rem < ARRAY_SIZE(c.u.exact) ?
rem : ARRAY_SIZE(c.u.exact));
size_t len16 = DIV_ROUND_UP(offsetof(struct fw_vi_mac_cmd,
u.exact[fw_naddr]), 16);
struct fw_vi_mac_exact *p;
int i;
memset(&c, 0, sizeof(c));
c.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_MAC_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_CMD_EXEC_V(free) |
FW_VI_MAC_CMD_VIID_V(viid));
c.freemacs_to_len16 =
cpu_to_be32(FW_VI_MAC_CMD_FREEMACS_V(free) |
FW_CMD_LEN16_V(len16));
for (i = 0, p = c.u.exact; i < fw_naddr; i++, p++) {
p->valid_to_idx =
cpu_to_be16(FW_VI_MAC_CMD_VALID_F |
FW_VI_MAC_CMD_IDX_V(
FW_VI_MAC_ADD_MAC));
memcpy(p->macaddr, addr[offset + i],
sizeof(p->macaddr));
}
ret = t4_wr_mbox_meat(adap, mbox, &c, sizeof(c), &c, sleep_ok);
if (ret && ret != -FW_ENOMEM)
break;
for (i = 0, p = c.u.exact; i < fw_naddr; i++, p++) {
u16 index = FW_VI_MAC_CMD_IDX_G(
be16_to_cpu(p->valid_to_idx));
if (idx)
idx[offset + i] = (index >= max_naddr ?
0xffff : index);
if (index < max_naddr)
nfilters++;
else if (hash)
*hash |= (1ULL <<
hash_mac_addr(addr[offset + i]));
}
free = false;
offset += fw_naddr;
rem -= fw_naddr;
}
if (ret == 0 || ret == -FW_ENOMEM)
ret = nfilters;
return ret;
}
int t4_free_mac_filt(struct adapter *adap, unsigned int mbox,
unsigned int viid, unsigned int naddr,
const u8 **addr, bool sleep_ok)
{
int offset, ret = 0;
struct fw_vi_mac_cmd c;
unsigned int nfilters = 0;
unsigned int max_naddr = is_t4(adap->params.chip) ?
NUM_MPS_CLS_SRAM_L_INSTANCES :
NUM_MPS_T5_CLS_SRAM_L_INSTANCES;
unsigned int rem = naddr;
if (naddr > max_naddr)
return -EINVAL;
for (offset = 0; offset < (int)naddr ; ) {
unsigned int fw_naddr = (rem < ARRAY_SIZE(c.u.exact)
? rem
: ARRAY_SIZE(c.u.exact));
size_t len16 = DIV_ROUND_UP(offsetof(struct fw_vi_mac_cmd,
u.exact[fw_naddr]), 16);
struct fw_vi_mac_exact *p;
int i;
memset(&c, 0, sizeof(c));
c.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_MAC_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_CMD_EXEC_V(0) |
FW_VI_MAC_CMD_VIID_V(viid));
c.freemacs_to_len16 =
cpu_to_be32(FW_VI_MAC_CMD_FREEMACS_V(0) |
FW_CMD_LEN16_V(len16));
for (i = 0, p = c.u.exact; i < (int)fw_naddr; i++, p++) {
p->valid_to_idx = cpu_to_be16(
FW_VI_MAC_CMD_VALID_F |
FW_VI_MAC_CMD_IDX_V(FW_VI_MAC_MAC_BASED_FREE));
memcpy(p->macaddr, addr[offset+i], sizeof(p->macaddr));
}
ret = t4_wr_mbox_meat(adap, mbox, &c, sizeof(c), &c, sleep_ok);
if (ret)
break;
for (i = 0, p = c.u.exact; i < fw_naddr; i++, p++) {
u16 index = FW_VI_MAC_CMD_IDX_G(
be16_to_cpu(p->valid_to_idx));
if (index < max_naddr)
nfilters++;
}
offset += fw_naddr;
rem -= fw_naddr;
}
if (ret == 0)
ret = nfilters;
return ret;
}
int t4_change_mac(struct adapter *adap, unsigned int mbox, unsigned int viid,
int idx, const u8 *addr, bool persist, bool add_smt)
{
int ret, mode;
struct fw_vi_mac_cmd c;
struct fw_vi_mac_exact *p = c.u.exact;
unsigned int max_mac_addr = adap->params.arch.mps_tcam_size;
if (idx < 0)
idx = persist ? FW_VI_MAC_ADD_PERSIST_MAC : FW_VI_MAC_ADD_MAC;
mode = add_smt ? FW_VI_MAC_SMT_AND_MPSTCAM : FW_VI_MAC_MPS_TCAM_ENTRY;
memset(&c, 0, sizeof(c));
c.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_MAC_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
FW_VI_MAC_CMD_VIID_V(viid));
c.freemacs_to_len16 = cpu_to_be32(FW_CMD_LEN16_V(1));
p->valid_to_idx = cpu_to_be16(FW_VI_MAC_CMD_VALID_F |
FW_VI_MAC_CMD_SMAC_RESULT_V(mode) |
FW_VI_MAC_CMD_IDX_V(idx));
memcpy(p->macaddr, addr, sizeof(p->macaddr));
ret = t4_wr_mbox(adap, mbox, &c, sizeof(c), &c);
if (ret == 0) {
ret = FW_VI_MAC_CMD_IDX_G(be16_to_cpu(p->valid_to_idx));
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
c.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_MAC_CMD) |
FW_CMD_REQUEST_F | FW_CMD_WRITE_F |
FW_VI_ENABLE_CMD_VIID_V(viid));
c.freemacs_to_len16 = cpu_to_be32(FW_VI_MAC_CMD_HASHVECEN_F |
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
c.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_ENABLE_CMD) |
FW_CMD_REQUEST_F | FW_CMD_EXEC_F |
FW_VI_ENABLE_CMD_VIID_V(viid));
c.ien_to_len16 = cpu_to_be32(FW_VI_ENABLE_CMD_IEN_V(rx_en) |
FW_VI_ENABLE_CMD_EEN_V(tx_en) |
FW_VI_ENABLE_CMD_DCB_INFO_V(dcb_en) |
FW_LEN16(c));
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
c.op_to_viid = cpu_to_be32(FW_CMD_OP_V(FW_VI_ENABLE_CMD) |
FW_CMD_REQUEST_F | FW_CMD_EXEC_F |
FW_VI_ENABLE_CMD_VIID_V(viid));
c.ien_to_len16 = cpu_to_be32(FW_VI_ENABLE_CMD_LED_F | FW_LEN16(c));
c.blinkdur = cpu_to_be16(nblinks);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_iq_stop(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int iqtype, unsigned int iqid,
unsigned int fl0id, unsigned int fl1id)
{
struct fw_iq_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_IQ_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_IQ_CMD_PFN_V(pf) |
FW_IQ_CMD_VFN_V(vf));
c.alloc_to_len16 = cpu_to_be32(FW_IQ_CMD_IQSTOP_F | FW_LEN16(c));
c.type_to_iqandstindex = cpu_to_be32(FW_IQ_CMD_TYPE_V(iqtype));
c.iqid = cpu_to_be16(iqid);
c.fl0id = cpu_to_be16(fl0id);
c.fl1id = cpu_to_be16(fl1id);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_iq_free(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int iqtype, unsigned int iqid,
unsigned int fl0id, unsigned int fl1id)
{
struct fw_iq_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_IQ_CMD) | FW_CMD_REQUEST_F |
FW_CMD_EXEC_F | FW_IQ_CMD_PFN_V(pf) |
FW_IQ_CMD_VFN_V(vf));
c.alloc_to_len16 = cpu_to_be32(FW_IQ_CMD_FREE_F | FW_LEN16(c));
c.type_to_iqandstindex = cpu_to_be32(FW_IQ_CMD_TYPE_V(iqtype));
c.iqid = cpu_to_be16(iqid);
c.fl0id = cpu_to_be16(fl0id);
c.fl1id = cpu_to_be16(fl1id);
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_eth_eq_free(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int eqid)
{
struct fw_eq_eth_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_EQ_ETH_CMD) |
FW_CMD_REQUEST_F | FW_CMD_EXEC_F |
FW_EQ_ETH_CMD_PFN_V(pf) |
FW_EQ_ETH_CMD_VFN_V(vf));
c.alloc_to_len16 = cpu_to_be32(FW_EQ_ETH_CMD_FREE_F | FW_LEN16(c));
c.eqid_pkd = cpu_to_be32(FW_EQ_ETH_CMD_EQID_V(eqid));
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_ctrl_eq_free(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int eqid)
{
struct fw_eq_ctrl_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_EQ_CTRL_CMD) |
FW_CMD_REQUEST_F | FW_CMD_EXEC_F |
FW_EQ_CTRL_CMD_PFN_V(pf) |
FW_EQ_CTRL_CMD_VFN_V(vf));
c.alloc_to_len16 = cpu_to_be32(FW_EQ_CTRL_CMD_FREE_F | FW_LEN16(c));
c.cmpliqid_eqid = cpu_to_be32(FW_EQ_CTRL_CMD_EQID_V(eqid));
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
int t4_ofld_eq_free(struct adapter *adap, unsigned int mbox, unsigned int pf,
unsigned int vf, unsigned int eqid)
{
struct fw_eq_ofld_cmd c;
memset(&c, 0, sizeof(c));
c.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_EQ_OFLD_CMD) |
FW_CMD_REQUEST_F | FW_CMD_EXEC_F |
FW_EQ_OFLD_CMD_PFN_V(pf) |
FW_EQ_OFLD_CMD_VFN_V(vf));
c.alloc_to_len16 = cpu_to_be32(FW_EQ_OFLD_CMD_FREE_F | FW_LEN16(c));
c.eqid_pkd = cpu_to_be32(FW_EQ_OFLD_CMD_EQID_V(eqid));
return t4_wr_mbox(adap, mbox, &c, sizeof(c), NULL);
}
static const char *t4_link_down_rc_str(unsigned char link_down_rc)
{
static const char * const reason[] = {
"Link Down",
"Remote Fault",
"Auto-negotiation Failure",
"Reserved",
"Insufficient Airflow",
"Unable To Determine Reason",
"No RX Signal Detected",
"Reserved",
};
if (link_down_rc >= ARRAY_SIZE(reason))
return "Bad Reason Code";
return reason[link_down_rc];
}
void t4_handle_get_port_info(struct port_info *pi, const __be64 *rpl)
{
const struct fw_port_cmd *p = (const void *)rpl;
struct adapter *adap = pi->adapter;
int speed = 0, fc = 0;
struct link_config *lc;
u32 stat = be32_to_cpu(p->u.info.lstatus_to_modtype);
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
else if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_25G))
speed = 25000;
else if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_40G))
speed = 40000;
else if (stat & FW_PORT_CMD_LSPEED_V(FW_PORT_CAP_SPEED_100G))
speed = 100000;
lc = &pi->link_cfg;
if (mod != pi->mod_type) {
pi->mod_type = mod;
t4_os_portmod_changed(adap, pi->port_id);
}
if (link_ok != lc->link_ok || speed != lc->speed ||
fc != lc->fc) {
if (!link_ok && lc->link_ok) {
unsigned char rc = FW_PORT_CMD_LINKDNRC_G(stat);
lc->link_down_rc = rc;
dev_warn(adap->pdev_dev,
"Port %d link down, reason: %s\n",
pi->port_id, t4_link_down_rc_str(rc));
}
lc->link_ok = link_ok;
lc->speed = speed;
lc->fc = fc;
lc->supported = be16_to_cpu(p->u.info.pcap);
lc->lp_advertising = be16_to_cpu(p->u.info.lpacap);
t4_os_link_changed(adap, pi->port_id, link_ok);
}
}
int t4_update_port_info(struct port_info *pi)
{
struct fw_port_cmd port_cmd;
int ret;
memset(&port_cmd, 0, sizeof(port_cmd));
port_cmd.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PORT_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F |
FW_PORT_CMD_PORTID_V(pi->port_id));
port_cmd.action_to_len16 = cpu_to_be32(
FW_PORT_CMD_ACTION_V(FW_PORT_ACTION_GET_PORT_INFO) |
FW_LEN16(port_cmd));
ret = t4_wr_mbox(pi->adapter, pi->adapter->mbox,
&port_cmd, sizeof(port_cmd), &port_cmd);
if (ret)
return ret;
t4_handle_get_port_info(pi, (__be64 *)&port_cmd);
return 0;
}
int t4_handle_fw_rpl(struct adapter *adap, const __be64 *rpl)
{
u8 opcode = *(const u8 *)rpl;
const struct fw_port_cmd *p = (const void *)rpl;
unsigned int action =
FW_PORT_CMD_ACTION_G(be32_to_cpu(p->action_to_len16));
if (opcode == FW_PORT_CMD && action == FW_PORT_ACTION_GET_PORT_INFO) {
int i;
int chan = FW_PORT_CMD_PORTID_G(be32_to_cpu(p->op_to_portid));
struct port_info *pi = NULL;
for_each_port(adap, i) {
pi = adap2pinfo(adap, i);
if (pi->tx_chan == chan)
break;
}
t4_handle_get_port_info(pi, rpl);
} else {
dev_warn(adap->pdev_dev, "Unknown firmware reply %d\n", opcode);
return -EINVAL;
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
static void init_link_config(struct link_config *lc, unsigned int pcaps,
unsigned int acaps)
{
lc->supported = pcaps;
lc->lp_advertising = 0;
lc->requested_speed = 0;
lc->speed = 0;
lc->requested_fc = lc->fc = PAUSE_RX | PAUSE_TX;
lc->auto_fec = 0;
if (acaps & FW_PORT_CAP_FEC_RS)
lc->auto_fec |= FEC_RS;
if (acaps & FW_PORT_CAP_FEC_BASER_RS)
lc->auto_fec |= FEC_BASER_RS;
lc->requested_fec = FEC_AUTO;
lc->fec = lc->auto_fec;
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
static void set_pcie_completion_timeout(struct adapter *adapter, u8 range)
{
u16 val;
u32 pcie_cap;
pcie_cap = pci_find_capability(adapter->pdev, PCI_CAP_ID_EXP);
if (pcie_cap) {
pci_read_config_word(adapter->pdev,
pcie_cap + PCI_EXP_DEVCTL2, &val);
val &= ~PCI_EXP_DEVCTL2_COMP_TIMEOUT;
val |= range;
pci_write_config_word(adapter->pdev,
pcie_cap + PCI_EXP_DEVCTL2, val);
}
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
adapter->params.arch.sge_fl_db = DBPRIO_F;
adapter->params.arch.mps_tcam_size =
NUM_MPS_CLS_SRAM_L_INSTANCES;
adapter->params.arch.mps_rplc_size = 128;
adapter->params.arch.nchan = NCHAN;
adapter->params.arch.pm_stats_cnt = PM_NSTATS;
adapter->params.arch.vfcount = 128;
adapter->params.arch.cng_ch_bits_log = 2;
break;
case CHELSIO_T5:
adapter->params.chip |= CHELSIO_CHIP_CODE(CHELSIO_T5, pl_rev);
adapter->params.arch.sge_fl_db = DBPRIO_F | DBTYPE_F;
adapter->params.arch.mps_tcam_size =
NUM_MPS_T5_CLS_SRAM_L_INSTANCES;
adapter->params.arch.mps_rplc_size = 128;
adapter->params.arch.nchan = NCHAN;
adapter->params.arch.pm_stats_cnt = PM_NSTATS;
adapter->params.arch.vfcount = 128;
adapter->params.arch.cng_ch_bits_log = 2;
break;
case CHELSIO_T6:
adapter->params.chip |= CHELSIO_CHIP_CODE(CHELSIO_T6, pl_rev);
adapter->params.arch.sge_fl_db = 0;
adapter->params.arch.mps_tcam_size =
NUM_MPS_T5_CLS_SRAM_L_INSTANCES;
adapter->params.arch.mps_rplc_size = 256;
adapter->params.arch.nchan = 2;
adapter->params.arch.pm_stats_cnt = T6_PM_NSTATS;
adapter->params.arch.vfcount = 256;
adapter->params.arch.cng_ch_bits_log = 3;
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
set_pcie_completion_timeout(adapter, 0xd);
return 0;
}
int t4_shutdown_adapter(struct adapter *adapter)
{
int port;
t4_intr_disable(adapter);
t4_write_reg(adapter, DBG_GPIO_EN_A, 0);
for_each_port(adapter, port) {
u32 a_port_cfg = is_t4(adapter->params.chip) ?
PORT_REG(port, XGMAC_PORT_CFG_A) :
T5_PORT_REG(port, MAC_PORT_CFG_A);
t4_write_reg(adapter, a_port_cfg,
t4_read_reg(adapter, a_port_cfg)
& ~SIGNAL_DET_V(1));
}
t4_set_reg_field(adapter, SGE_CONTROL_A, GLOBALENABLE_F, 0);
return 0;
}
int t4_bar2_sge_qregs(struct adapter *adapter,
unsigned int qid,
enum t4_bar2_qtype qtype,
int user,
u64 *pbar2_qoffset,
unsigned int *pbar2_qid)
{
unsigned int page_shift, page_size, qpp_shift, qpp_mask;
u64 bar2_page_offset, bar2_qoffset;
unsigned int bar2_qid, bar2_qid_offset, bar2_qinferred;
if (!user && is_t4(adapter->params.chip))
return -EINVAL;
page_shift = adapter->params.sge.hps + 10;
page_size = 1 << page_shift;
qpp_shift = (qtype == T4_BAR2_QTYPE_EGRESS
? adapter->params.sge.eq_qpp
: adapter->params.sge.iq_qpp);
qpp_mask = (1 << qpp_shift) - 1;
bar2_page_offset = ((u64)(qid >> qpp_shift) << page_shift);
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
devlog_cmd.op_to_write = cpu_to_be32(FW_CMD_OP_V(FW_DEVLOG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F);
devlog_cmd.retval_len16 = cpu_to_be32(FW_LEN16(devlog_cmd));
ret = t4_wr_mbox(adap, adap->mbox, &devlog_cmd, sizeof(devlog_cmd),
&devlog_cmd);
if (ret)
return ret;
devlog_meminfo =
be32_to_cpu(devlog_cmd.memtype_devlog_memaddr16_devlog);
dparams->memtype = FW_DEVLOG_CMD_MEMTYPE_DEVLOG_G(devlog_meminfo);
dparams->start = FW_DEVLOG_CMD_MEMADDR16_DEVLOG_G(devlog_meminfo) << 4;
dparams->size = be32_to_cpu(devlog_cmd.memsize_devlog);
return 0;
}
int t4_init_sge_params(struct adapter *adapter)
{
struct sge_params *sge_params = &adapter->params.sge;
u32 hps, qpp;
unsigned int s_hps, s_qpp;
hps = t4_read_reg(adapter, SGE_HOST_PAGE_SIZE_A);
s_hps = (HOSTPAGESIZEPF0_S +
(HOSTPAGESIZEPF1_S - HOSTPAGESIZEPF0_S) * adapter->pf);
sge_params->hps = ((hps >> s_hps) & HOSTPAGESIZEPF0_M);
s_qpp = (QUEUESPERPAGEPF0_S +
(QUEUESPERPAGEPF1_S - QUEUESPERPAGEPF0_S) * adapter->pf);
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
if (t4_use_ldst(adap)) {
t4_fw_tp_pio_rw(adap, &adap->params.tp.vlan_pri_map, 1,
TP_VLAN_PRI_MAP_A, 1);
t4_fw_tp_pio_rw(adap, &adap->params.tp.ingress_config, 1,
TP_INGRESS_CONFIG_A, 1);
} else {
t4_read_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&adap->params.tp.vlan_pri_map, 1,
TP_VLAN_PRI_MAP_A);
t4_read_indirect(adap, TP_PIO_ADDR_A, TP_PIO_DATA_A,
&adap->params.tp.ingress_config, 1,
TP_INGRESS_CONFIG_A);
}
if (CHELSIO_CHIP_VERSION(adap->params.chip) > CHELSIO_T5) {
v = t4_read_reg(adap, TP_OUT_CONFIG_A);
adap->params.tp.rx_pkt_encap = (v & CRXPKTENC_F) ? 1 : 0;
}
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
int t4_init_rss_mode(struct adapter *adap, int mbox)
{
int i, ret;
struct fw_rss_vi_config_cmd rvc;
memset(&rvc, 0, sizeof(rvc));
for_each_port(adap, i) {
struct port_info *p = adap2pinfo(adap, i);
rvc.op_to_viid =
cpu_to_be32(FW_CMD_OP_V(FW_RSS_VI_CONFIG_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F |
FW_RSS_VI_CONFIG_CMD_VIID_V(p->viid));
rvc.retval_len16 = cpu_to_be32(FW_LEN16(rvc));
ret = t4_wr_mbox(adap, mbox, &rvc, sizeof(rvc), &rvc);
if (ret)
return ret;
p->rss_mode = be32_to_cpu(rvc.u.basicvirtual.defaultq_to_udpen);
}
return 0;
}
int t4_init_portinfo(struct port_info *pi, int mbox,
int port, int pf, int vf, u8 mac[])
{
int ret;
struct fw_port_cmd c;
unsigned int rss_size;
memset(&c, 0, sizeof(c));
c.op_to_portid = cpu_to_be32(FW_CMD_OP_V(FW_PORT_CMD) |
FW_CMD_REQUEST_F | FW_CMD_READ_F |
FW_PORT_CMD_PORTID_V(port));
c.action_to_len16 = cpu_to_be32(
FW_PORT_CMD_ACTION_V(FW_PORT_ACTION_GET_PORT_INFO) |
FW_LEN16(c));
ret = t4_wr_mbox(pi->adapter, mbox, &c, sizeof(c), &c);
if (ret)
return ret;
ret = t4_alloc_vi(pi->adapter, mbox, port, pf, vf, 1, mac, &rss_size);
if (ret < 0)
return ret;
pi->viid = ret;
pi->tx_chan = port;
pi->lport = port;
pi->rss_size = rss_size;
ret = be32_to_cpu(c.u.info.lstatus_to_modtype);
pi->mdio_addr = (ret & FW_PORT_CMD_MDIOCAP_F) ?
FW_PORT_CMD_MDIOADDR_G(ret) : -1;
pi->port_type = FW_PORT_CMD_PTYPE_G(ret);
pi->mod_type = FW_PORT_MOD_TYPE_NA;
init_link_config(&pi->link_cfg, be16_to_cpu(c.u.info.pcap),
be16_to_cpu(c.u.info.acap));
return 0;
}
int t4_port_init(struct adapter *adap, int mbox, int pf, int vf)
{
u8 addr[6];
int ret, i, j = 0;
for_each_port(adap, i) {
struct port_info *pi = adap2pinfo(adap, i);
while ((adap->params.portvec & (1 << j)) == 0)
j++;
ret = t4_init_portinfo(pi, mbox, j, pf, vf, addr);
if (ret)
return ret;
memcpy(adap->port[i]->dev_addr, addr, ETH_ALEN);
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
if (is_t6(adap->params.chip) && (idx & 0xf) >= 9)
idx = (idx & 0xff0) + 0x10;
else
idx++;
idx &= UPDBGLARDPTR_M;
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
void t4_idma_monitor_init(struct adapter *adapter,
struct sge_idma_monitor_state *idma)
{
idma->idma_1s_thresh = core_ticks_per_usec(adapter) * 1000000;
idma->idma_stalled[0] = 0;
idma->idma_stalled[1] = 0;
}
void t4_idma_monitor(struct adapter *adapter,
struct sge_idma_monitor_state *idma,
int hz, int ticks)
{
int i, idma_same_state_cnt[2];
t4_write_reg(adapter, SGE_DEBUG_INDEX_A, 13);
idma_same_state_cnt[0] = t4_read_reg(adapter, SGE_DEBUG_DATA_HIGH_A);
idma_same_state_cnt[1] = t4_read_reg(adapter, SGE_DEBUG_DATA_LOW_A);
for (i = 0; i < 2; i++) {
u32 debug0, debug11;
if (idma_same_state_cnt[i] < idma->idma_1s_thresh) {
if (idma->idma_stalled[i] >= SGE_IDMA_WARN_THRESH * hz)
dev_warn(adapter->pdev_dev, "SGE idma%d, queue %u, "
"resumed after %d seconds\n",
i, idma->idma_qid[i],
idma->idma_stalled[i] / hz);
idma->idma_stalled[i] = 0;
continue;
}
if (idma->idma_stalled[i] == 0) {
idma->idma_stalled[i] = hz;
idma->idma_warn[i] = 0;
} else {
idma->idma_stalled[i] += ticks;
idma->idma_warn[i] -= ticks;
}
if (idma->idma_stalled[i] < SGE_IDMA_WARN_THRESH * hz)
continue;
if (idma->idma_warn[i] > 0)
continue;
idma->idma_warn[i] = SGE_IDMA_WARN_REPEAT * hz;
t4_write_reg(adapter, SGE_DEBUG_INDEX_A, 0);
debug0 = t4_read_reg(adapter, SGE_DEBUG_DATA_LOW_A);
idma->idma_state[i] = (debug0 >> (i * 9)) & 0x3f;
t4_write_reg(adapter, SGE_DEBUG_INDEX_A, 11);
debug11 = t4_read_reg(adapter, SGE_DEBUG_DATA_LOW_A);
idma->idma_qid[i] = (debug11 >> (i * 16)) & 0xffff;
dev_warn(adapter->pdev_dev, "SGE idma%u, queue %u, potentially stuck in "
"state %u for %d seconds (debug0=%#x, debug11=%#x)\n",
i, idma->idma_qid[i], idma->idma_state[i],
idma->idma_stalled[i] / hz,
debug0, debug11);
t4_sge_decode_idma_state(adapter, idma->idma_state[i]);
}
}
int t4_set_vf_mac_acl(struct adapter *adapter, unsigned int vf,
unsigned int naddr, u8 *addr)
{
struct fw_acl_mac_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_vfn = cpu_to_be32(FW_CMD_OP_V(FW_ACL_MAC_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F |
FW_ACL_MAC_CMD_PFN_V(adapter->pf) |
FW_ACL_MAC_CMD_VFN_V(vf));
cmd.en_to_len16 = cpu_to_be32((unsigned int)FW_LEN16(cmd));
cmd.nmac = naddr;
switch (adapter->pf) {
case 3:
memcpy(cmd.macaddr3, addr, sizeof(cmd.macaddr3));
break;
case 2:
memcpy(cmd.macaddr2, addr, sizeof(cmd.macaddr2));
break;
case 1:
memcpy(cmd.macaddr1, addr, sizeof(cmd.macaddr1));
break;
case 0:
memcpy(cmd.macaddr0, addr, sizeof(cmd.macaddr0));
break;
}
return t4_wr_mbox(adapter, adapter->mbox, &cmd, sizeof(cmd), &cmd);
}
int t4_sched_params(struct adapter *adapter, int type, int level, int mode,
int rateunit, int ratemode, int channel, int class,
int minrate, int maxrate, int weight, int pktsize)
{
struct fw_sched_cmd cmd;
memset(&cmd, 0, sizeof(cmd));
cmd.op_to_write = cpu_to_be32(FW_CMD_OP_V(FW_SCHED_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F);
cmd.retval_len16 = cpu_to_be32(FW_LEN16(cmd));
cmd.u.params.sc = FW_SCHED_SC_PARAMS;
cmd.u.params.type = type;
cmd.u.params.level = level;
cmd.u.params.mode = mode;
cmd.u.params.ch = channel;
cmd.u.params.cl = class;
cmd.u.params.unit = rateunit;
cmd.u.params.rate = ratemode;
cmd.u.params.min = cpu_to_be32(minrate);
cmd.u.params.max = cpu_to_be32(maxrate);
cmd.u.params.weight = cpu_to_be16(weight);
cmd.u.params.pktsize = cpu_to_be16(pktsize);
return t4_wr_mbox_meat(adapter, adapter->mbox, &cmd, sizeof(cmd),
NULL, 1);
}
