int csio_is_hw_ready(struct csio_hw *hw)
{
return csio_match_state(hw, csio_hws_ready);
}
int csio_is_hw_removing(struct csio_hw *hw)
{
return csio_match_state(hw, csio_hws_removing);
}
int
csio_hw_wait_op_done_val(struct csio_hw *hw, int reg, uint32_t mask,
int polarity, int attempts, int delay, uint32_t *valp)
{
uint32_t val;
while (1) {
val = csio_rd_reg32(hw, reg);
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
void
csio_hw_tp_wr_bits_indirect(struct csio_hw *hw, unsigned int addr,
unsigned int mask, unsigned int val)
{
csio_wr_reg32(hw, addr, TP_PIO_ADDR);
val |= csio_rd_reg32(hw, TP_PIO_DATA) & ~mask;
csio_wr_reg32(hw, val, TP_PIO_DATA);
}
void
csio_set_reg_field(struct csio_hw *hw, uint32_t reg, uint32_t mask,
uint32_t value)
{
uint32_t val = csio_rd_reg32(hw, reg) & ~mask;
csio_wr_reg32(hw, val | value, reg);
csio_rd_reg32(hw, reg);
}
static int
csio_memory_write(struct csio_hw *hw, int mtype, u32 addr, u32 len, u32 *buf)
{
return hw->chip_ops->chip_memory_rw(hw, MEMWIN_CSIOSTOR, mtype,
addr, len, buf, 0);
}
static int
csio_hw_seeprom_read(struct csio_hw *hw, uint32_t addr, uint32_t *data)
{
uint16_t val = 0;
int attempts = EEPROM_MAX_RD_POLL;
uint32_t base = hw->params.pci.vpd_cap_addr;
if (addr >= EEPROMVSIZE || (addr & 3))
return -EINVAL;
pci_write_config_word(hw->pdev, base + PCI_VPD_ADDR, (uint16_t)addr);
do {
udelay(10);
pci_read_config_word(hw->pdev, base + PCI_VPD_ADDR, &val);
} while (!(val & PCI_VPD_ADDR_F) && --attempts);
if (!(val & PCI_VPD_ADDR_F)) {
csio_err(hw, "reading EEPROM address 0x%x failed\n", addr);
return -EINVAL;
}
pci_read_config_dword(hw->pdev, base + PCI_VPD_DATA, data);
*data = le32_to_cpu(*data);
return 0;
}
static int
csio_hw_get_vpd_keyword_val(const struct t4_vpd_hdr *v, const char *kw)
{
int32_t i;
int32_t offset , len;
const uint8_t *buf = &v->id_tag;
const uint8_t *vpdr_len = &v->vpdr_tag;
offset = sizeof(struct t4_vpd_hdr);
len = (uint16_t)vpdr_len[1] + ((uint16_t)vpdr_len[2] << 8);
if (len + sizeof(struct t4_vpd_hdr) > VPD_LEN)
return -EINVAL;
for (i = offset; (i + VPD_INFO_FLD_HDR_SIZE) <= (offset + len);) {
if (memcmp(buf + i , kw, 2) == 0) {
i += VPD_INFO_FLD_HDR_SIZE;
return i;
}
i += VPD_INFO_FLD_HDR_SIZE + buf[i+2];
}
return -EINVAL;
}
static int
csio_pci_capability(struct pci_dev *pdev, int cap, int *pos)
{
*pos = pci_find_capability(pdev, cap);
if (*pos)
return 0;
return -1;
}
static int
csio_hw_get_vpd_params(struct csio_hw *hw, struct csio_vpd *p)
{
int i, ret, ec, sn, addr;
uint8_t *vpd, csum;
const struct t4_vpd_hdr *v;
char *s;
if (csio_is_valid_vpd(hw))
return 0;
ret = csio_pci_capability(hw->pdev, PCI_CAP_ID_VPD,
&hw->params.pci.vpd_cap_addr);
if (ret)
return -EINVAL;
vpd = kzalloc(VPD_LEN, GFP_ATOMIC);
if (vpd == NULL)
return -ENOMEM;
ret = csio_hw_seeprom_read(hw, VPD_BASE, (uint32_t *)(vpd));
addr = *vpd == 0x82 ? VPD_BASE : VPD_BASE_OLD;
for (i = 0; i < VPD_LEN; i += 4) {
ret = csio_hw_seeprom_read(hw, addr + i, (uint32_t *)(vpd + i));
if (ret) {
kfree(vpd);
return ret;
}
}
hw->flags &= (~CSIO_HWF_VPD_VALID);
v = (const struct t4_vpd_hdr *)vpd;
#define FIND_VPD_KW(var, name) do { \
var = csio_hw_get_vpd_keyword_val(v, name); \
if (var < 0) { \
csio_err(hw, "missing VPD keyword " name "\n"); \
kfree(vpd); \
return -EINVAL; \
} \
} while (0)
FIND_VPD_KW(i, "RV");
for (csum = 0; i >= 0; i--)
csum += vpd[i];
if (csum) {
csio_err(hw, "corrupted VPD EEPROM, actual csum %u\n", csum);
kfree(vpd);
return -EINVAL;
}
FIND_VPD_KW(ec, "EC");
FIND_VPD_KW(sn, "SN");
#undef FIND_VPD_KW
memcpy(p->id, v->id_data, ID_LEN);
s = strstrip(p->id);
memcpy(p->ec, vpd + ec, EC_LEN);
s = strstrip(p->ec);
i = vpd[sn - VPD_INFO_FLD_HDR_SIZE + 2];
memcpy(p->sn, vpd + sn, min(i, SERNUM_LEN));
s = strstrip(p->sn);
csio_valid_vpd_copied(hw);
kfree(vpd);
return 0;
}
static int
csio_hw_sf1_read(struct csio_hw *hw, uint32_t byte_cnt, int32_t cont,
int32_t lock, uint32_t *valp)
{
int ret;
if (!byte_cnt || byte_cnt > 4)
return -EINVAL;
if (csio_rd_reg32(hw, SF_OP) & SF_BUSY)
return -EBUSY;
cont = cont ? SF_CONT : 0;
lock = lock ? SF_LOCK : 0;
csio_wr_reg32(hw, lock | cont | BYTECNT(byte_cnt - 1), SF_OP);
ret = csio_hw_wait_op_done_val(hw, SF_OP, SF_BUSY, 0, SF_ATTEMPTS,
10, NULL);
if (!ret)
*valp = csio_rd_reg32(hw, SF_DATA);
return ret;
}
static int
csio_hw_sf1_write(struct csio_hw *hw, uint32_t byte_cnt, uint32_t cont,
int32_t lock, uint32_t val)
{
if (!byte_cnt || byte_cnt > 4)
return -EINVAL;
if (csio_rd_reg32(hw, SF_OP) & SF_BUSY)
return -EBUSY;
cont = cont ? SF_CONT : 0;
lock = lock ? SF_LOCK : 0;
csio_wr_reg32(hw, val, SF_DATA);
csio_wr_reg32(hw, cont | BYTECNT(byte_cnt - 1) | OP_WR | lock, SF_OP);
return csio_hw_wait_op_done_val(hw, SF_OP, SF_BUSY, 0, SF_ATTEMPTS,
10, NULL);
}
static int
csio_hw_flash_wait_op(struct csio_hw *hw, int32_t attempts, int32_t delay)
{
int ret;
uint32_t status;
while (1) {
ret = csio_hw_sf1_write(hw, 1, 1, 1, SF_RD_STATUS);
if (ret != 0)
return ret;
ret = csio_hw_sf1_read(hw, 1, 0, 1, &status);
if (ret != 0)
return ret;
if (!(status & 1))
return 0;
if (--attempts == 0)
return -EAGAIN;
if (delay)
msleep(delay);
}
}
static int
csio_hw_read_flash(struct csio_hw *hw, uint32_t addr, uint32_t nwords,
uint32_t *data, int32_t byte_oriented)
{
int ret;
if (addr + nwords * sizeof(uint32_t) > hw->params.sf_size || (addr & 3))
return -EINVAL;
addr = swab32(addr) | SF_RD_DATA_FAST;
ret = csio_hw_sf1_write(hw, 4, 1, 0, addr);
if (ret != 0)
return ret;
ret = csio_hw_sf1_read(hw, 1, 1, 0, data);
if (ret != 0)
return ret;
for ( ; nwords; nwords--, data++) {
ret = csio_hw_sf1_read(hw, 4, nwords > 1, nwords == 1, data);
if (nwords == 1)
csio_wr_reg32(hw, 0, SF_OP);
if (ret)
return ret;
if (byte_oriented)
*data = htonl(*data);
}
return 0;
}
static int
csio_hw_write_flash(struct csio_hw *hw, uint32_t addr,
uint32_t n, const uint8_t *data)
{
int ret = -EINVAL;
uint32_t buf[64];
uint32_t i, c, left, val, offset = addr & 0xff;
if (addr >= hw->params.sf_size || offset + n > SF_PAGE_SIZE)
return -EINVAL;
val = swab32(addr) | SF_PROG_PAGE;
ret = csio_hw_sf1_write(hw, 1, 0, 1, SF_WR_ENABLE);
if (ret != 0)
goto unlock;
ret = csio_hw_sf1_write(hw, 4, 1, 1, val);
if (ret != 0)
goto unlock;
for (left = n; left; left -= c) {
c = min(left, 4U);
for (val = 0, i = 0; i < c; ++i)
val = (val << 8) + *data++;
ret = csio_hw_sf1_write(hw, c, c != left, 1, val);
if (ret)
goto unlock;
}
ret = csio_hw_flash_wait_op(hw, 8, 1);
if (ret)
goto unlock;
csio_wr_reg32(hw, 0, SF_OP);
ret = csio_hw_read_flash(hw, addr & ~0xff, ARRAY_SIZE(buf), buf, 1);
if (ret)
return ret;
if (memcmp(data - n, (uint8_t *)buf + offset, n)) {
csio_err(hw,
"failed to correctly write the flash page at %#x\n",
addr);
return -EINVAL;
}
return 0;
unlock:
csio_wr_reg32(hw, 0, SF_OP);
return ret;
}
static int
csio_hw_flash_erase_sectors(struct csio_hw *hw, int32_t start, int32_t end)
{
int ret = 0;
while (start <= end) {
ret = csio_hw_sf1_write(hw, 1, 0, 1, SF_WR_ENABLE);
if (ret != 0)
goto out;
ret = csio_hw_sf1_write(hw, 4, 0, 1,
SF_ERASE_SECTOR | (start << 8));
if (ret != 0)
goto out;
ret = csio_hw_flash_wait_op(hw, 14, 500);
if (ret != 0)
goto out;
start++;
}
out:
if (ret)
csio_err(hw, "erase of flash sector %d failed, error %d\n",
start, ret);
csio_wr_reg32(hw, 0, SF_OP);
return 0;
}
static void
csio_hw_print_fw_version(struct csio_hw *hw, char *str)
{
csio_info(hw, "%s: %u.%u.%u.%u\n", str,
FW_HDR_FW_VER_MAJOR_G(hw->fwrev),
FW_HDR_FW_VER_MINOR_G(hw->fwrev),
FW_HDR_FW_VER_MICRO_G(hw->fwrev),
FW_HDR_FW_VER_BUILD_G(hw->fwrev));
}
static int
csio_hw_get_fw_version(struct csio_hw *hw, uint32_t *vers)
{
return csio_hw_read_flash(hw, FW_IMG_START +
offsetof(struct fw_hdr, fw_ver), 1,
vers, 0);
}
static int
csio_hw_get_tp_version(struct csio_hw *hw, u32 *vers)
{
return csio_hw_read_flash(hw, FLASH_FW_START +
offsetof(struct fw_hdr, tp_microcode_ver), 1,
vers, 0);
}
static int
csio_hw_check_fw_version(struct csio_hw *hw)
{
int ret, major, minor, micro;
ret = csio_hw_get_fw_version(hw, &hw->fwrev);
if (!ret)
ret = csio_hw_get_tp_version(hw, &hw->tp_vers);
if (ret)
return ret;
major = FW_HDR_FW_VER_MAJOR_G(hw->fwrev);
minor = FW_HDR_FW_VER_MINOR_G(hw->fwrev);
micro = FW_HDR_FW_VER_MICRO_G(hw->fwrev);
if (major != FW_VERSION_MAJOR(hw)) {
csio_err(hw, "card FW has major version %u, driver wants %u\n",
major, FW_VERSION_MAJOR(hw));
return -EINVAL;
}
if (minor == FW_VERSION_MINOR(hw) && micro == FW_VERSION_MICRO(hw))
return 0;
return -EINVAL;
}
static int
csio_hw_fw_dload(struct csio_hw *hw, uint8_t *fw_data, uint32_t size)
{
uint32_t csum;
int32_t addr;
int ret;
uint32_t i;
uint8_t first_page[SF_PAGE_SIZE];
const __be32 *p = (const __be32 *)fw_data;
struct fw_hdr *hdr = (struct fw_hdr *)fw_data;
uint32_t sf_sec_size;
if ((!hw->params.sf_size) || (!hw->params.sf_nsec)) {
csio_err(hw, "Serial Flash data invalid\n");
return -EINVAL;
}
if (!size) {
csio_err(hw, "FW image has no data\n");
return -EINVAL;
}
if (size & 511) {
csio_err(hw, "FW image size not multiple of 512 bytes\n");
return -EINVAL;
}
if (ntohs(hdr->len512) * 512 != size) {
csio_err(hw, "FW image size differs from size in FW header\n");
return -EINVAL;
}
if (size > FW_MAX_SIZE) {
csio_err(hw, "FW image too large, max is %u bytes\n",
FW_MAX_SIZE);
return -EINVAL;
}
for (csum = 0, i = 0; i < size / sizeof(csum); i++)
csum += ntohl(p[i]);
if (csum != 0xffffffff) {
csio_err(hw, "corrupted firmware image, checksum %#x\n", csum);
return -EINVAL;
}
sf_sec_size = hw->params.sf_size / hw->params.sf_nsec;
i = DIV_ROUND_UP(size, sf_sec_size);
csio_dbg(hw, "Erasing sectors... start:%d end:%d\n",
FW_START_SEC, FW_START_SEC + i - 1);
ret = csio_hw_flash_erase_sectors(hw, FW_START_SEC,
FW_START_SEC + i - 1);
if (ret) {
csio_err(hw, "Flash Erase failed\n");
goto out;
}
memcpy(first_page, fw_data, SF_PAGE_SIZE);
((struct fw_hdr *)first_page)->fw_ver = htonl(0xffffffff);
ret = csio_hw_write_flash(hw, FW_IMG_START, SF_PAGE_SIZE, first_page);
if (ret)
goto out;
csio_dbg(hw, "Writing Flash .. start:%d end:%d\n",
FW_IMG_START, FW_IMG_START + size);
addr = FW_IMG_START;
for (size -= SF_PAGE_SIZE; size; size -= SF_PAGE_SIZE) {
addr += SF_PAGE_SIZE;
fw_data += SF_PAGE_SIZE;
ret = csio_hw_write_flash(hw, addr, SF_PAGE_SIZE, fw_data);
if (ret)
goto out;
}
ret = csio_hw_write_flash(hw,
FW_IMG_START +
offsetof(struct fw_hdr, fw_ver),
sizeof(hdr->fw_ver),
(const uint8_t *)&hdr->fw_ver);
out:
if (ret)
csio_err(hw, "firmware download failed, error %d\n", ret);
return ret;
}
static int
csio_hw_get_flash_params(struct csio_hw *hw)
{
int ret;
uint32_t info = 0;
ret = csio_hw_sf1_write(hw, 1, 1, 0, SF_RD_ID);
if (!ret)
ret = csio_hw_sf1_read(hw, 3, 0, 1, &info);
csio_wr_reg32(hw, 0, SF_OP);
if (ret != 0)
return ret;
if ((info & 0xff) != 0x20)
return -EINVAL;
info >>= 16;
if (info >= 0x14 && info < 0x18)
hw->params.sf_nsec = 1 << (info - 16);
else if (info == 0x18)
hw->params.sf_nsec = 64;
else
return -EINVAL;
hw->params.sf_size = 1 << info;
return 0;
}
static int
csio_hw_dev_ready(struct csio_hw *hw)
{
uint32_t reg;
int cnt = 6;
while (((reg = csio_rd_reg32(hw, PL_WHOAMI)) == 0xFFFFFFFF) &&
(--cnt != 0))
mdelay(100);
if ((cnt == 0) && (((int32_t)(SOURCEPF_GET(reg)) < 0) ||
(SOURCEPF_GET(reg) >= CSIO_MAX_PFN))) {
csio_err(hw, "PL_WHOAMI returned 0x%x, cnt:%d\n", reg, cnt);
return -EIO;
}
hw->pfn = SOURCEPF_GET(reg);
return 0;
}
static int
csio_do_hello(struct csio_hw *hw, enum csio_dev_state *state)
{
struct csio_mb *mbp;
int rv = 0;
enum fw_retval retval;
uint8_t mpfn;
char state_str[16];
int retries = FW_CMD_HELLO_RETRIES;
memset(state_str, 0, sizeof(state_str));
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
rv = -ENOMEM;
CSIO_INC_STATS(hw, n_err_nomem);
goto out;
}
retry:
csio_mb_hello(hw, mbp, CSIO_MB_DEFAULT_TMO, hw->pfn,
hw->pfn, CSIO_MASTER_MAY, NULL);
rv = csio_mb_issue(hw, mbp);
if (rv) {
csio_err(hw, "failed to issue HELLO cmd. ret:%d.\n", rv);
goto out_free_mb;
}
csio_mb_process_hello_rsp(hw, mbp, &retval, state, &mpfn);
if (retval != FW_SUCCESS) {
csio_err(hw, "HELLO cmd failed with ret: %d\n", retval);
rv = -EINVAL;
goto out_free_mb;
}
if (hw->pfn == mpfn) {
hw->flags |= CSIO_HWF_MASTER;
} else if (*state == CSIO_DEV_STATE_UNINIT) {
int waiting = FW_CMD_HELLO_TIMEOUT;
for (;;) {
uint32_t pcie_fw;
spin_unlock_irq(&hw->lock);
msleep(50);
spin_lock_irq(&hw->lock);
waiting -= 50;
pcie_fw = csio_rd_reg32(hw, PCIE_FW);
if (!(pcie_fw & (PCIE_FW_ERR|PCIE_FW_INIT))) {
if (waiting <= 0) {
if (retries-- > 0)
goto retry;
rv = -ETIMEDOUT;
break;
}
continue;
}
if (state) {
if (pcie_fw & PCIE_FW_ERR) {
*state = CSIO_DEV_STATE_ERR;
rv = -ETIMEDOUT;
} else if (pcie_fw & PCIE_FW_INIT)
*state = CSIO_DEV_STATE_INIT;
}
if (mpfn == PCIE_FW_MASTER_MASK &&
(pcie_fw & PCIE_FW_MASTER_VLD))
mpfn = PCIE_FW_MASTER_GET(pcie_fw);
break;
}
hw->flags &= ~CSIO_HWF_MASTER;
}
switch (*state) {
case CSIO_DEV_STATE_UNINIT:
strcpy(state_str, "Initializing");
break;
case CSIO_DEV_STATE_INIT:
strcpy(state_str, "Initialized");
break;
case CSIO_DEV_STATE_ERR:
strcpy(state_str, "Error");
break;
default:
strcpy(state_str, "Unknown");
break;
}
if (hw->pfn == mpfn)
csio_info(hw, "PF: %d, Coming up as MASTER, HW state: %s\n",
hw->pfn, state_str);
else
csio_info(hw,
"PF: %d, Coming up as SLAVE, Master PF: %d, HW state: %s\n",
hw->pfn, mpfn, state_str);
out_free_mb:
mempool_free(mbp, hw->mb_mempool);
out:
return rv;
}
static int
csio_do_bye(struct csio_hw *hw)
{
struct csio_mb *mbp;
enum fw_retval retval;
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
return -ENOMEM;
}
csio_mb_bye(hw, mbp, CSIO_MB_DEFAULT_TMO, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of BYE command failed\n");
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
retval = csio_mb_fw_retval(mbp);
if (retval != FW_SUCCESS) {
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
mempool_free(mbp, hw->mb_mempool);
return 0;
}
static int
csio_do_reset(struct csio_hw *hw, bool fw_rst)
{
struct csio_mb *mbp;
enum fw_retval retval;
if (!fw_rst) {
csio_wr_reg32(hw, PIORSTMODE | PIORST, PL_RST);
mdelay(2000);
return 0;
}
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
return -ENOMEM;
}
csio_mb_reset(hw, mbp, CSIO_MB_DEFAULT_TMO,
PIORSTMODE | PIORST, 0, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of RESET command failed.n");
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
retval = csio_mb_fw_retval(mbp);
if (retval != FW_SUCCESS) {
csio_err(hw, "RESET cmd failed with ret:0x%x.\n", retval);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
mempool_free(mbp, hw->mb_mempool);
return 0;
}
static int
csio_hw_validate_caps(struct csio_hw *hw, struct csio_mb *mbp)
{
struct fw_caps_config_cmd *rsp = (struct fw_caps_config_cmd *)mbp->mb;
uint16_t caps;
caps = ntohs(rsp->fcoecaps);
if (!(caps & FW_CAPS_CONFIG_FCOE_INITIATOR)) {
csio_err(hw, "No FCoE Initiator capability in the firmware.\n");
return -EINVAL;
}
if (!(caps & FW_CAPS_CONFIG_FCOE_CTRL_OFLD)) {
csio_err(hw, "No FCoE Control Offload capability\n");
return -EINVAL;
}
return 0;
}
static int
csio_hw_fw_halt(struct csio_hw *hw, uint32_t mbox, int32_t force)
{
enum fw_retval retval = 0;
if (mbox <= PCIE_FW_MASTER_MASK) {
struct csio_mb *mbp;
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
return -ENOMEM;
}
csio_mb_reset(hw, mbp, CSIO_MB_DEFAULT_TMO,
PIORSTMODE | PIORST, FW_RESET_CMD_HALT_F,
NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of RESET command failed!\n");
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
retval = csio_mb_fw_retval(mbp);
mempool_free(mbp, hw->mb_mempool);
}
if (retval == 0 || force) {
csio_set_reg_field(hw, CIM_BOOT_CFG, UPCRST, UPCRST);
csio_set_reg_field(hw, PCIE_FW, PCIE_FW_HALT, PCIE_FW_HALT);
}
return retval ? -EINVAL : 0;
}
static int
csio_hw_fw_restart(struct csio_hw *hw, uint32_t mbox, int32_t reset)
{
if (reset) {
csio_set_reg_field(hw, PCIE_FW, PCIE_FW_HALT, 0);
if (mbox <= PCIE_FW_MASTER_MASK) {
csio_set_reg_field(hw, CIM_BOOT_CFG, UPCRST, 0);
msleep(100);
if (csio_do_reset(hw, true) == 0)
return 0;
}
csio_wr_reg32(hw, PIORSTMODE | PIORST, PL_RST);
msleep(2000);
} else {
int ms;
csio_set_reg_field(hw, CIM_BOOT_CFG, UPCRST, 0);
for (ms = 0; ms < FW_CMD_MAX_TIMEOUT; ) {
if (!(csio_rd_reg32(hw, PCIE_FW) & PCIE_FW_HALT))
return 0;
msleep(100);
ms += 100;
}
return -ETIMEDOUT;
}
return 0;
}
static int
csio_hw_fw_upgrade(struct csio_hw *hw, uint32_t mbox,
const u8 *fw_data, uint32_t size, int32_t force)
{
const struct fw_hdr *fw_hdr = (const struct fw_hdr *)fw_data;
int reset, ret;
ret = csio_hw_fw_halt(hw, mbox, force);
if (ret != 0 && !force)
return ret;
ret = csio_hw_fw_dload(hw, (uint8_t *) fw_data, size);
if (ret != 0)
return ret;
reset = ((ntohl(fw_hdr->flags) & FW_HDR_FLAGS_RESET_HALT) == 0);
return csio_hw_fw_restart(hw, mbox, reset);
}
static int
csio_hw_fw_config_file(struct csio_hw *hw,
unsigned int mtype, unsigned int maddr,
uint32_t *finiver, uint32_t *finicsum, uint32_t *cfcsum)
{
struct csio_mb *mbp;
struct fw_caps_config_cmd *caps_cmd;
int rv = -EINVAL;
enum fw_retval ret;
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
return -ENOMEM;
}
caps_cmd = (struct fw_caps_config_cmd *)(mbp->mb);
CSIO_INIT_MBP(mbp, caps_cmd, CSIO_MB_DEFAULT_TMO, hw, NULL, 1);
caps_cmd->op_to_write =
htonl(FW_CMD_OP_V(FW_CAPS_CONFIG_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_READ_F);
caps_cmd->cfvalid_to_len16 =
htonl(FW_CAPS_CONFIG_CMD_CFVALID_F |
FW_CAPS_CONFIG_CMD_MEMTYPE_CF_V(mtype) |
FW_CAPS_CONFIG_CMD_MEMADDR64K_CF_V(maddr >> 16) |
FW_LEN16(*caps_cmd));
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of FW_CAPS_CONFIG_CMD failed!\n");
goto out;
}
ret = csio_mb_fw_retval(mbp);
if (ret != FW_SUCCESS) {
csio_dbg(hw, "FW_CAPS_CONFIG_CMD returned %d!\n", rv);
goto out;
}
if (finiver)
*finiver = ntohl(caps_cmd->finiver);
if (finicsum)
*finicsum = ntohl(caps_cmd->finicsum);
if (cfcsum)
*cfcsum = ntohl(caps_cmd->cfcsum);
if (csio_hw_validate_caps(hw, mbp)) {
rv = -ENOENT;
goto out;
}
caps_cmd->op_to_write =
htonl(FW_CMD_OP_V(FW_CAPS_CONFIG_CMD) |
FW_CMD_REQUEST_F |
FW_CMD_WRITE_F);
caps_cmd->cfvalid_to_len16 = htonl(FW_LEN16(*caps_cmd));
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of FW_CAPS_CONFIG_CMD failed!\n");
goto out;
}
ret = csio_mb_fw_retval(mbp);
if (ret != FW_SUCCESS) {
csio_dbg(hw, "FW_CAPS_CONFIG_CMD returned %d!\n", rv);
goto out;
}
rv = 0;
out:
mempool_free(mbp, hw->mb_mempool);
return rv;
}
static int
csio_get_device_params(struct csio_hw *hw)
{
struct csio_wrm *wrm = csio_hw_to_wrm(hw);
struct csio_mb *mbp;
enum fw_retval retval;
u32 param[6];
int i, j = 0;
for (i = 0; i < CSIO_MAX_PPORTS; i++)
hw->pport[i].portid = -1;
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
return -ENOMEM;
}
param[0] = FW_PARAM_DEV(PORTVEC);
param[1] = FW_PARAM_DEV(CCLK);
param[2] = FW_PARAM_PFVF(EQ_START);
param[3] = FW_PARAM_PFVF(EQ_END);
param[4] = FW_PARAM_PFVF(IQFLINT_START);
param[5] = FW_PARAM_PFVF(IQFLINT_END);
csio_mb_params(hw, mbp, CSIO_MB_DEFAULT_TMO, hw->pfn, 0,
ARRAY_SIZE(param), param, NULL, false, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of FW_PARAMS_CMD(read) failed!\n");
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
csio_mb_process_read_params_rsp(hw, mbp, &retval,
ARRAY_SIZE(param), param);
if (retval != FW_SUCCESS) {
csio_err(hw, "FW_PARAMS_CMD(read) failed with ret:0x%x!\n",
retval);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
hw->port_vec = param[0];
hw->vpd.cclk = param[1];
wrm->fw_eq_start = param[2];
wrm->fw_iq_start = param[4];
if ((hw->flags & CSIO_HWF_USING_SOFT_PARAMS) ||
!csio_is_hw_master(hw)) {
hw->cfg_niq = param[5] - param[4] + 1;
hw->cfg_neq = param[3] - param[2] + 1;
csio_dbg(hw, "Using fwconfig max niqs %d neqs %d\n",
hw->cfg_niq, hw->cfg_neq);
}
hw->port_vec &= csio_port_mask;
hw->num_pports = hweight32(hw->port_vec);
csio_dbg(hw, "Port vector: 0x%x, #ports: %d\n",
hw->port_vec, hw->num_pports);
for (i = 0; i < hw->num_pports; i++) {
while ((hw->port_vec & (1 << j)) == 0)
j++;
hw->pport[i].portid = j++;
csio_dbg(hw, "Found Port:%d\n", hw->pport[i].portid);
}
mempool_free(mbp, hw->mb_mempool);
return 0;
}
static int
csio_config_device_caps(struct csio_hw *hw)
{
struct csio_mb *mbp;
enum fw_retval retval;
int rv = -EINVAL;
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
return -ENOMEM;
}
csio_mb_caps_config(hw, mbp, CSIO_MB_DEFAULT_TMO, 0, 0, 0, 0, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of FW_CAPS_CONFIG_CMD(r) failed!\n");
goto out;
}
retval = csio_mb_fw_retval(mbp);
if (retval != FW_SUCCESS) {
csio_err(hw, "FW_CAPS_CONFIG_CMD(r) returned %d!\n", retval);
goto out;
}
if (csio_hw_validate_caps(hw, mbp))
goto out;
if (hw->fw_state == CSIO_DEV_STATE_INIT) {
rv = 0;
goto out;
}
csio_mb_caps_config(hw, mbp, CSIO_MB_DEFAULT_TMO, true, true,
false, true, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of FW_CAPS_CONFIG_CMD(w) failed!\n");
goto out;
}
retval = csio_mb_fw_retval(mbp);
if (retval != FW_SUCCESS) {
csio_err(hw, "FW_CAPS_CONFIG_CMD(w) returned %d!\n", retval);
goto out;
}
rv = 0;
out:
mempool_free(mbp, hw->mb_mempool);
return rv;
}
static int
csio_enable_ports(struct csio_hw *hw)
{
struct csio_mb *mbp;
enum fw_retval retval;
uint8_t portid;
int i;
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
return -ENOMEM;
}
for (i = 0; i < hw->num_pports; i++) {
portid = hw->pport[i].portid;
csio_mb_port(hw, mbp, CSIO_MB_DEFAULT_TMO, portid,
false, 0, 0, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "failed to issue FW_PORT_CMD(r) port:%d\n",
portid);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
csio_mb_process_read_port_rsp(hw, mbp, &retval,
&hw->pport[i].pcap);
if (retval != FW_SUCCESS) {
csio_err(hw, "FW_PORT_CMD(r) port:%d failed: 0x%x\n",
portid, retval);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
csio_mb_port(hw, mbp, CSIO_MB_DEFAULT_TMO, portid, true,
(PAUSE_RX | PAUSE_TX), hw->pport[i].pcap, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "failed to issue FW_PORT_CMD(w) port:%d\n",
portid);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
retval = csio_mb_fw_retval(mbp);
if (retval != FW_SUCCESS) {
csio_err(hw, "FW_PORT_CMD(w) port:%d failed :0x%x\n",
portid, retval);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
}
mempool_free(mbp, hw->mb_mempool);
return 0;
}
static int
csio_get_fcoe_resinfo(struct csio_hw *hw)
{
struct csio_fcoe_res_info *res_info = &hw->fres_info;
struct fw_fcoe_res_info_cmd *rsp;
struct csio_mb *mbp;
enum fw_retval retval;
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
return -ENOMEM;
}
csio_fcoe_read_res_info_init_mb(hw, mbp, CSIO_MB_DEFAULT_TMO, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "failed to issue FW_FCOE_RES_INFO_CMD\n");
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
rsp = (struct fw_fcoe_res_info_cmd *)(mbp->mb);
retval = FW_CMD_RETVAL_G(ntohl(rsp->retval_len16));
if (retval != FW_SUCCESS) {
csio_err(hw, "FW_FCOE_RES_INFO_CMD failed with ret x%x\n",
retval);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
res_info->e_d_tov = ntohs(rsp->e_d_tov);
res_info->r_a_tov_seq = ntohs(rsp->r_a_tov_seq);
res_info->r_a_tov_els = ntohs(rsp->r_a_tov_els);
res_info->r_r_tov = ntohs(rsp->r_r_tov);
res_info->max_xchgs = ntohl(rsp->max_xchgs);
res_info->max_ssns = ntohl(rsp->max_ssns);
res_info->used_xchgs = ntohl(rsp->used_xchgs);
res_info->used_ssns = ntohl(rsp->used_ssns);
res_info->max_fcfs = ntohl(rsp->max_fcfs);
res_info->max_vnps = ntohl(rsp->max_vnps);
res_info->used_fcfs = ntohl(rsp->used_fcfs);
res_info->used_vnps = ntohl(rsp->used_vnps);
csio_dbg(hw, "max ssns:%d max xchgs:%d\n", res_info->max_ssns,
res_info->max_xchgs);
mempool_free(mbp, hw->mb_mempool);
return 0;
}
static int
csio_hw_check_fwconfig(struct csio_hw *hw, u32 *param)
{
struct csio_mb *mbp;
enum fw_retval retval;
u32 _param[1];
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
return -ENOMEM;
}
_param[0] = (FW_PARAMS_MNEM_V(FW_PARAMS_MNEM_DEV) |
FW_PARAMS_PARAM_X_V(FW_PARAMS_PARAM_DEV_CF));
csio_mb_params(hw, mbp, CSIO_MB_DEFAULT_TMO, hw->pfn, 0,
ARRAY_SIZE(_param), _param, NULL, false, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of FW_PARAMS_CMD(read) failed!\n");
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
csio_mb_process_read_params_rsp(hw, mbp, &retval,
ARRAY_SIZE(_param), _param);
if (retval != FW_SUCCESS) {
csio_err(hw, "FW_PARAMS_CMD(read) failed with ret:0x%x!\n",
retval);
mempool_free(mbp, hw->mb_mempool);
return -EINVAL;
}
mempool_free(mbp, hw->mb_mempool);
*param = _param[0];
return 0;
}
static int
csio_hw_flash_config(struct csio_hw *hw, u32 *fw_cfg_param, char *path)
{
int ret = 0;
const struct firmware *cf;
struct pci_dev *pci_dev = hw->pdev;
struct device *dev = &pci_dev->dev;
unsigned int mtype = 0, maddr = 0;
uint32_t *cfg_data;
int value_to_add = 0;
if (request_firmware(&cf, CSIO_CF_FNAME(hw), dev) < 0) {
csio_err(hw, "could not find config file %s, err: %d\n",
CSIO_CF_FNAME(hw), ret);
return -ENOENT;
}
if (cf->size%4 != 0)
value_to_add = 4 - (cf->size % 4);
cfg_data = kzalloc(cf->size+value_to_add, GFP_KERNEL);
if (cfg_data == NULL) {
ret = -ENOMEM;
goto leave;
}
memcpy((void *)cfg_data, (const void *)cf->data, cf->size);
if (csio_hw_check_fwconfig(hw, fw_cfg_param) != 0) {
ret = -EINVAL;
goto leave;
}
mtype = FW_PARAMS_PARAM_Y_G(*fw_cfg_param);
maddr = FW_PARAMS_PARAM_Z_G(*fw_cfg_param) << 16;
ret = csio_memory_write(hw, mtype, maddr,
cf->size + value_to_add, cfg_data);
if ((ret == 0) && (value_to_add != 0)) {
union {
u32 word;
char buf[4];
} last;
size_t size = cf->size & ~0x3;
int i;
last.word = cfg_data[size >> 2];
for (i = value_to_add; i < 4; i++)
last.buf[i] = 0;
ret = csio_memory_write(hw, mtype, maddr + size, 4, &last.word);
}
if (ret == 0) {
csio_info(hw, "config file upgraded to %s\n",
CSIO_CF_FNAME(hw));
snprintf(path, 64, "%s%s", "/lib/firmware/", CSIO_CF_FNAME(hw));
}
leave:
kfree(cfg_data);
release_firmware(cf);
return ret;
}
static int
csio_hw_use_fwconfig(struct csio_hw *hw, int reset, u32 *fw_cfg_param)
{
unsigned int mtype, maddr;
int rv;
uint32_t finiver = 0, finicsum = 0, cfcsum = 0;
int using_flash;
char path[64];
if (reset) {
rv = csio_do_reset(hw, true);
if (rv != 0)
goto bye;
}
spin_unlock_irq(&hw->lock);
rv = csio_hw_flash_config(hw, fw_cfg_param, path);
spin_lock_irq(&hw->lock);
if (rv != 0) {
if (rv == -ENOENT) {
mtype = FW_MEMTYPE_CF_FLASH;
maddr = hw->chip_ops->chip_flash_cfg_addr(hw);
using_flash = 1;
} else {
goto bye;
}
} else {
mtype = FW_PARAMS_PARAM_Y_G(*fw_cfg_param);
maddr = FW_PARAMS_PARAM_Z_G(*fw_cfg_param) << 16;
using_flash = 0;
}
hw->cfg_store = (uint8_t)mtype;
rv = csio_hw_fw_config_file(hw, mtype, maddr, &finiver,
&finicsum, &cfcsum);
if (rv != 0)
goto bye;
hw->cfg_finiver = finiver;
hw->cfg_finicsum = finicsum;
hw->cfg_cfcsum = cfcsum;
hw->cfg_csum_status = true;
if (finicsum != cfcsum) {
csio_warn(hw,
"Config File checksum mismatch: csum=%#x, computed=%#x\n",
finicsum, cfcsum);
hw->cfg_csum_status = false;
}
hw->flags |= CSIO_HWF_USING_SOFT_PARAMS;
rv = csio_get_device_params(hw);
if (rv != 0)
goto bye;
csio_wr_sge_init(hw);
csio_post_event(&hw->sm, CSIO_HWE_INIT);
csio_info(hw,
"Firmware Configuration File %s, version %#x, computed checksum %#x\n",
(using_flash ? "in device FLASH" : path), finiver, cfcsum);
return 0;
bye:
hw->flags &= ~CSIO_HWF_USING_SOFT_PARAMS;
csio_dbg(hw, "Configuration file error %d\n", rv);
return rv;
}
static int
csio_hw_no_fwconfig(struct csio_hw *hw, int reset)
{
int rv;
if (reset) {
rv = csio_do_reset(hw, true);
if (rv != 0)
goto out;
}
rv = csio_config_device_caps(hw);
if (rv != 0)
goto out;
rv = csio_get_device_params(hw);
if (rv != 0)
goto out;
csio_wr_sge_init(hw);
csio_post_event(&hw->sm, CSIO_HWE_INIT);
out:
return rv;
}
static int
csio_hw_flash_fw(struct csio_hw *hw)
{
int ret = -ECANCELED;
const struct firmware *fw;
const struct fw_hdr *hdr;
u32 fw_ver;
struct pci_dev *pci_dev = hw->pdev;
struct device *dev = &pci_dev->dev ;
if (request_firmware(&fw, CSIO_FW_FNAME(hw), dev) < 0) {
csio_err(hw, "could not find firmware image %s, err: %d\n",
CSIO_FW_FNAME(hw), ret);
return -EINVAL;
}
hdr = (const struct fw_hdr *)fw->data;
fw_ver = ntohl(hdr->fw_ver);
if (FW_HDR_FW_VER_MAJOR_G(fw_ver) != FW_VERSION_MAJOR(hw))
return -EINVAL;
if (FW_HDR_FW_VER_MAJOR_G(hw->fwrev) != FW_VERSION_MAJOR(hw) ||
fw_ver > hw->fwrev) {
ret = csio_hw_fw_upgrade(hw, hw->pfn, fw->data, fw->size,
false);
if (!ret)
csio_info(hw,
"firmware upgraded to version %pI4 from %s\n",
&hdr->fw_ver, CSIO_FW_FNAME(hw));
else
csio_err(hw, "firmware upgrade failed! err=%d\n", ret);
} else
ret = -EINVAL;
release_firmware(fw);
return ret;
}
static void
csio_hw_configure(struct csio_hw *hw)
{
int reset = 1;
int rv;
u32 param[1];
rv = csio_hw_dev_ready(hw);
if (rv != 0) {
CSIO_INC_STATS(hw, n_err_fatal);
csio_post_event(&hw->sm, CSIO_HWE_FATAL);
goto out;
}
hw->chip_ver = (char)csio_rd_reg32(hw, PL_REV);
rv = csio_hw_get_flash_params(hw);
if (rv != 0) {
csio_err(hw, "Failed to get serial flash params rv:%d\n", rv);
csio_post_event(&hw->sm, CSIO_HWE_FATAL);
goto out;
}
if (pci_is_pcie(hw->pdev))
pcie_capability_clear_and_set_word(hw->pdev, PCI_EXP_DEVCTL2,
PCI_EXP_DEVCTL2_COMP_TIMEOUT, 0xd);
hw->chip_ops->chip_set_mem_win(hw, MEMWIN_CSIOSTOR);
rv = csio_hw_get_fw_version(hw, &hw->fwrev);
if (rv != 0)
goto out;
csio_hw_print_fw_version(hw, "Firmware revision");
rv = csio_do_hello(hw, &hw->fw_state);
if (rv != 0) {
CSIO_INC_STATS(hw, n_err_fatal);
csio_post_event(&hw->sm, CSIO_HWE_FATAL);
goto out;
}
rv = csio_hw_get_vpd_params(hw, &hw->vpd);
if (rv != 0)
goto out;
if (csio_is_hw_master(hw) && hw->fw_state != CSIO_DEV_STATE_INIT) {
rv = csio_hw_check_fw_version(hw);
if (rv == -EINVAL) {
spin_unlock_irq(&hw->lock);
rv = csio_hw_flash_fw(hw);
spin_lock_irq(&hw->lock);
if (rv == 0) {
reset = 0;
rv = csio_hw_check_fw_version(hw);
}
}
if (csio_hw_check_fwconfig(hw, param) == 0) {
rv = csio_hw_use_fwconfig(hw, reset, param);
if (rv == -ENOENT)
goto out;
if (rv != 0) {
csio_info(hw,
"No Configuration File present "
"on adapter. Using hard-wired "
"configuration parameters.\n");
rv = csio_hw_no_fwconfig(hw, reset);
}
} else {
rv = csio_hw_no_fwconfig(hw, reset);
}
if (rv != 0)
goto out;
} else {
if (hw->fw_state == CSIO_DEV_STATE_INIT) {
hw->flags |= CSIO_HWF_USING_SOFT_PARAMS;
rv = csio_get_device_params(hw);
if (rv != 0)
goto out;
rv = csio_config_device_caps(hw);
if (rv != 0)
goto out;
csio_wr_sge_init(hw);
csio_post_event(&hw->sm, CSIO_HWE_INIT);
goto out;
}
}
out:
return;
}
static void
csio_hw_initialize(struct csio_hw *hw)
{
struct csio_mb *mbp;
enum fw_retval retval;
int rv;
int i;
if (csio_is_hw_master(hw) && hw->fw_state != CSIO_DEV_STATE_INIT) {
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp)
goto out;
csio_mb_initialize(hw, mbp, CSIO_MB_DEFAULT_TMO, NULL);
if (csio_mb_issue(hw, mbp)) {
csio_err(hw, "Issue of FW_INITIALIZE_CMD failed!\n");
goto free_and_out;
}
retval = csio_mb_fw_retval(mbp);
if (retval != FW_SUCCESS) {
csio_err(hw, "FW_INITIALIZE_CMD returned 0x%x!\n",
retval);
goto free_and_out;
}
mempool_free(mbp, hw->mb_mempool);
}
rv = csio_get_fcoe_resinfo(hw);
if (rv != 0) {
csio_err(hw, "Failed to read fcoe resource info: %d\n", rv);
goto out;
}
spin_unlock_irq(&hw->lock);
rv = csio_config_queues(hw);
spin_lock_irq(&hw->lock);
if (rv != 0) {
csio_err(hw, "Config of queues failed!: %d\n", rv);
goto out;
}
for (i = 0; i < hw->num_pports; i++)
hw->pport[i].mod_type = FW_PORT_MOD_TYPE_NA;
if (csio_is_hw_master(hw) && hw->fw_state != CSIO_DEV_STATE_INIT) {
rv = csio_enable_ports(hw);
if (rv != 0) {
csio_err(hw, "Failed to enable ports: %d\n", rv);
goto out;
}
}
csio_post_event(&hw->sm, CSIO_HWE_INIT_DONE);
return;
free_and_out:
mempool_free(mbp, hw->mb_mempool);
out:
return;
}
static void
csio_hw_intr_enable(struct csio_hw *hw)
{
uint16_t vec = (uint16_t)csio_get_mb_intr_idx(csio_hw_to_mbm(hw));
uint32_t pf = SOURCEPF_GET(csio_rd_reg32(hw, PL_WHOAMI));
uint32_t pl = csio_rd_reg32(hw, PL_INT_ENABLE);
if (hw->intr_mode == CSIO_IM_MSIX)
csio_set_reg_field(hw, MYPF_REG(PCIE_PF_CFG),
AIVEC(AIVEC_MASK), vec);
else if (hw->intr_mode == CSIO_IM_MSI)
csio_set_reg_field(hw, MYPF_REG(PCIE_PF_CFG),
AIVEC(AIVEC_MASK), 0);
csio_wr_reg32(hw, PF_INTR_MASK, MYPF_REG(PL_PF_INT_ENABLE));
csio_mb_intr_enable(hw);
if (csio_is_hw_master(hw)) {
pl &= (~SF);
csio_wr_reg32(hw, pl, PL_INT_ENABLE);
csio_wr_reg32(hw, ERR_CPL_EXCEED_IQE_SIZE |
EGRESS_SIZE_ERR | ERR_INVALID_CIDX_INC |
ERR_CPL_OPCODE_0 | ERR_DROPPED_DB |
ERR_DATA_CPL_ON_HIGH_QID1 |
ERR_DATA_CPL_ON_HIGH_QID0 | ERR_BAD_DB_PIDX3 |
ERR_BAD_DB_PIDX2 | ERR_BAD_DB_PIDX1 |
ERR_BAD_DB_PIDX0 | ERR_ING_CTXT_PRIO |
ERR_EGR_CTXT_PRIO | INGRESS_SIZE_ERR,
SGE_INT_ENABLE3);
csio_set_reg_field(hw, PL_INT_MAP0, 0, 1 << pf);
}
hw->flags |= CSIO_HWF_HW_INTR_ENABLED;
}
void
csio_hw_intr_disable(struct csio_hw *hw)
{
uint32_t pf = SOURCEPF_GET(csio_rd_reg32(hw, PL_WHOAMI));
if (!(hw->flags & CSIO_HWF_HW_INTR_ENABLED))
return;
hw->flags &= ~CSIO_HWF_HW_INTR_ENABLED;
csio_wr_reg32(hw, 0, MYPF_REG(PL_PF_INT_ENABLE));
if (csio_is_hw_master(hw))
csio_set_reg_field(hw, PL_INT_MAP0, 1 << pf, 0);
csio_mb_intr_disable(hw);
}
void
csio_hw_fatal_err(struct csio_hw *hw)
{
csio_set_reg_field(hw, SGE_CONTROL, GLOBALENABLE, 0);
csio_hw_intr_disable(hw);
csio_fatal(hw, "HW Fatal error encountered!\n");
}
static void
csio_hws_uninit(struct csio_hw *hw, enum csio_hw_ev evt)
{
hw->prev_evt = hw->cur_evt;
hw->cur_evt = evt;
CSIO_INC_STATS(hw, n_evt_sm[evt]);
switch (evt) {
case CSIO_HWE_CFG:
csio_set_state(&hw->sm, csio_hws_configuring);
csio_hw_configure(hw);
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
}
static void
csio_hws_configuring(struct csio_hw *hw, enum csio_hw_ev evt)
{
hw->prev_evt = hw->cur_evt;
hw->cur_evt = evt;
CSIO_INC_STATS(hw, n_evt_sm[evt]);
switch (evt) {
case CSIO_HWE_INIT:
csio_set_state(&hw->sm, csio_hws_initializing);
csio_hw_initialize(hw);
break;
case CSIO_HWE_INIT_DONE:
csio_set_state(&hw->sm, csio_hws_ready);
csio_notify_lnodes(hw, CSIO_LN_NOTIFY_HWREADY);
break;
case CSIO_HWE_FATAL:
csio_set_state(&hw->sm, csio_hws_uninit);
break;
case CSIO_HWE_PCI_REMOVE:
csio_do_bye(hw);
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
}
static void
csio_hws_initializing(struct csio_hw *hw, enum csio_hw_ev evt)
{
hw->prev_evt = hw->cur_evt;
hw->cur_evt = evt;
CSIO_INC_STATS(hw, n_evt_sm[evt]);
switch (evt) {
case CSIO_HWE_INIT_DONE:
csio_set_state(&hw->sm, csio_hws_ready);
csio_notify_lnodes(hw, CSIO_LN_NOTIFY_HWREADY);
csio_hw_intr_enable(hw);
break;
case CSIO_HWE_FATAL:
csio_set_state(&hw->sm, csio_hws_uninit);
break;
case CSIO_HWE_PCI_REMOVE:
csio_do_bye(hw);
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
}
static void
csio_hws_ready(struct csio_hw *hw, enum csio_hw_ev evt)
{
hw->evtflag = evt;
hw->prev_evt = hw->cur_evt;
hw->cur_evt = evt;
CSIO_INC_STATS(hw, n_evt_sm[evt]);
switch (evt) {
case CSIO_HWE_HBA_RESET:
case CSIO_HWE_FW_DLOAD:
case CSIO_HWE_SUSPEND:
case CSIO_HWE_PCI_REMOVE:
case CSIO_HWE_PCIERR_DETECTED:
csio_set_state(&hw->sm, csio_hws_quiescing);
if (evt == CSIO_HWE_HBA_RESET ||
evt == CSIO_HWE_PCIERR_DETECTED)
csio_scsim_cleanup_io(csio_hw_to_scsim(hw), false);
else
csio_scsim_cleanup_io(csio_hw_to_scsim(hw), true);
csio_hw_intr_disable(hw);
csio_hw_mbm_cleanup(hw);
csio_evtq_stop(hw);
csio_notify_lnodes(hw, CSIO_LN_NOTIFY_HWSTOP);
csio_evtq_flush(hw);
csio_mgmtm_cleanup(csio_hw_to_mgmtm(hw));
csio_post_event(&hw->sm, CSIO_HWE_QUIESCED);
break;
case CSIO_HWE_FATAL:
csio_set_state(&hw->sm, csio_hws_uninit);
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
}
static void
csio_hws_quiescing(struct csio_hw *hw, enum csio_hw_ev evt)
{
hw->prev_evt = hw->cur_evt;
hw->cur_evt = evt;
CSIO_INC_STATS(hw, n_evt_sm[evt]);
switch (evt) {
case CSIO_HWE_QUIESCED:
switch (hw->evtflag) {
case CSIO_HWE_FW_DLOAD:
csio_set_state(&hw->sm, csio_hws_resetting);
case CSIO_HWE_HBA_RESET:
csio_set_state(&hw->sm, csio_hws_resetting);
csio_notify_lnodes(hw, CSIO_LN_NOTIFY_HWRESET);
csio_wr_destroy_queues(hw, false);
csio_do_reset(hw, false);
csio_post_event(&hw->sm, CSIO_HWE_HBA_RESET_DONE);
break;
case CSIO_HWE_PCI_REMOVE:
csio_set_state(&hw->sm, csio_hws_removing);
csio_notify_lnodes(hw, CSIO_LN_NOTIFY_HWREMOVE);
csio_wr_destroy_queues(hw, true);
csio_do_bye(hw);
break;
case CSIO_HWE_SUSPEND:
csio_set_state(&hw->sm, csio_hws_quiesced);
break;
case CSIO_HWE_PCIERR_DETECTED:
csio_set_state(&hw->sm, csio_hws_pcierr);
csio_wr_destroy_queues(hw, false);
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
}
static void
csio_hws_quiesced(struct csio_hw *hw, enum csio_hw_ev evt)
{
hw->prev_evt = hw->cur_evt;
hw->cur_evt = evt;
CSIO_INC_STATS(hw, n_evt_sm[evt]);
switch (evt) {
case CSIO_HWE_RESUME:
csio_set_state(&hw->sm, csio_hws_configuring);
csio_hw_configure(hw);
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
}
static void
csio_hws_resetting(struct csio_hw *hw, enum csio_hw_ev evt)
{
hw->prev_evt = hw->cur_evt;
hw->cur_evt = evt;
CSIO_INC_STATS(hw, n_evt_sm[evt]);
switch (evt) {
case CSIO_HWE_HBA_RESET_DONE:
csio_evtq_start(hw);
csio_set_state(&hw->sm, csio_hws_configuring);
csio_hw_configure(hw);
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
}
static void
csio_hws_removing(struct csio_hw *hw, enum csio_hw_ev evt)
{
hw->prev_evt = hw->cur_evt;
hw->cur_evt = evt;
CSIO_INC_STATS(hw, n_evt_sm[evt]);
switch (evt) {
case CSIO_HWE_HBA_RESET:
if (!csio_is_hw_master(hw))
break;
csio_err(hw, "Resetting HW and waiting 2 seconds...\n");
csio_wr_reg32(hw, PIORSTMODE | PIORST, PL_RST);
mdelay(2000);
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
}
static void
csio_hws_pcierr(struct csio_hw *hw, enum csio_hw_ev evt)
{
hw->prev_evt = hw->cur_evt;
hw->cur_evt = evt;
CSIO_INC_STATS(hw, n_evt_sm[evt]);
switch (evt) {
case CSIO_HWE_PCIERR_SLOT_RESET:
csio_evtq_start(hw);
csio_set_state(&hw->sm, csio_hws_configuring);
csio_hw_configure(hw);
break;
default:
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
}
int
csio_handle_intr_status(struct csio_hw *hw, unsigned int reg,
const struct intr_info *acts)
{
int fatal = 0;
unsigned int mask = 0;
unsigned int status = csio_rd_reg32(hw, reg);
for ( ; acts->mask; ++acts) {
if (!(status & acts->mask))
continue;
if (acts->fatal) {
fatal++;
csio_fatal(hw, "Fatal %s (0x%x)\n",
acts->msg, status & acts->mask);
} else if (acts->msg)
csio_info(hw, "%s (0x%x)\n",
acts->msg, status & acts->mask);
mask |= acts->mask;
}
status &= mask;
if (status)
csio_wr_reg32(hw, status, reg);
return fatal;
}
static void csio_tp_intr_handler(struct csio_hw *hw)
{
static struct intr_info tp_intr_info[] = {
{ 0x3fffffff, "TP parity error", -1, 1 },
{ FLMTXFLSTEMPTY, "TP out of Tx pages", -1, 1 },
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, TP_INT_CAUSE, tp_intr_info))
csio_hw_fatal_err(hw);
}
static void csio_sge_intr_handler(struct csio_hw *hw)
{
uint64_t v;
static struct intr_info sge_intr_info[] = {
{ ERR_CPL_EXCEED_IQE_SIZE,
"SGE received CPL exceeding IQE size", -1, 1 },
{ ERR_INVALID_CIDX_INC,
"SGE GTS CIDX increment too large", -1, 0 },
{ ERR_CPL_OPCODE_0, "SGE received 0-length CPL", -1, 0 },
{ ERR_DROPPED_DB, "SGE doorbell dropped", -1, 0 },
{ ERR_DATA_CPL_ON_HIGH_QID1 | ERR_DATA_CPL_ON_HIGH_QID0,
"SGE IQID > 1023 received CPL for FL", -1, 0 },
{ ERR_BAD_DB_PIDX3, "SGE DBP 3 pidx increment too large", -1,
0 },
{ ERR_BAD_DB_PIDX2, "SGE DBP 2 pidx increment too large", -1,
0 },
{ ERR_BAD_DB_PIDX1, "SGE DBP 1 pidx increment too large", -1,
0 },
{ ERR_BAD_DB_PIDX0, "SGE DBP 0 pidx increment too large", -1,
0 },
{ ERR_ING_CTXT_PRIO,
"SGE too many priority ingress contexts", -1, 0 },
{ ERR_EGR_CTXT_PRIO,
"SGE too many priority egress contexts", -1, 0 },
{ INGRESS_SIZE_ERR, "SGE illegal ingress QID", -1, 0 },
{ EGRESS_SIZE_ERR, "SGE illegal egress QID", -1, 0 },
{ 0, NULL, 0, 0 }
};
v = (uint64_t)csio_rd_reg32(hw, SGE_INT_CAUSE1) |
((uint64_t)csio_rd_reg32(hw, SGE_INT_CAUSE2) << 32);
if (v) {
csio_fatal(hw, "SGE parity error (%#llx)\n",
(unsigned long long)v);
csio_wr_reg32(hw, (uint32_t)(v & 0xFFFFFFFF),
SGE_INT_CAUSE1);
csio_wr_reg32(hw, (uint32_t)(v >> 32), SGE_INT_CAUSE2);
}
v |= csio_handle_intr_status(hw, SGE_INT_CAUSE3, sge_intr_info);
if (csio_handle_intr_status(hw, SGE_INT_CAUSE3, sge_intr_info) ||
v != 0)
csio_hw_fatal_err(hw);
}
static void csio_cim_intr_handler(struct csio_hw *hw)
{
static struct intr_info cim_intr_info[] = {
{ PREFDROPINT, "CIM control register prefetch drop", -1, 1 },
{ CIM_OBQ_INTR, "CIM OBQ parity error", -1, 1 },
{ CIM_IBQ_INTR, "CIM IBQ parity error", -1, 1 },
{ MBUPPARERR, "CIM mailbox uP parity error", -1, 1 },
{ MBHOSTPARERR, "CIM mailbox host parity error", -1, 1 },
{ TIEQINPARERRINT, "CIM TIEQ outgoing parity error", -1, 1 },
{ TIEQOUTPARERRINT, "CIM TIEQ incoming parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
static struct intr_info cim_upintr_info[] = {
{ RSVDSPACEINT, "CIM reserved space access", -1, 1 },
{ ILLTRANSINT, "CIM illegal transaction", -1, 1 },
{ ILLWRINT, "CIM illegal write", -1, 1 },
{ ILLRDINT, "CIM illegal read", -1, 1 },
{ ILLRDBEINT, "CIM illegal read BE", -1, 1 },
{ ILLWRBEINT, "CIM illegal write BE", -1, 1 },
{ SGLRDBOOTINT, "CIM single read from boot space", -1, 1 },
{ SGLWRBOOTINT, "CIM single write to boot space", -1, 1 },
{ BLKWRBOOTINT, "CIM block write to boot space", -1, 1 },
{ SGLRDFLASHINT, "CIM single read from flash space", -1, 1 },
{ SGLWRFLASHINT, "CIM single write to flash space", -1, 1 },
{ BLKWRFLASHINT, "CIM block write to flash space", -1, 1 },
{ SGLRDEEPROMINT, "CIM single EEPROM read", -1, 1 },
{ SGLWREEPROMINT, "CIM single EEPROM write", -1, 1 },
{ BLKRDEEPROMINT, "CIM block EEPROM read", -1, 1 },
{ BLKWREEPROMINT, "CIM block EEPROM write", -1, 1 },
{ SGLRDCTLINT , "CIM single read from CTL space", -1, 1 },
{ SGLWRCTLINT , "CIM single write to CTL space", -1, 1 },
{ BLKRDCTLINT , "CIM block read from CTL space", -1, 1 },
{ BLKWRCTLINT , "CIM block write to CTL space", -1, 1 },
{ SGLRDPLINT , "CIM single read from PL space", -1, 1 },
{ SGLWRPLINT , "CIM single write to PL space", -1, 1 },
{ BLKRDPLINT , "CIM block read from PL space", -1, 1 },
{ BLKWRPLINT , "CIM block write to PL space", -1, 1 },
{ REQOVRLOOKUPINT , "CIM request FIFO overwrite", -1, 1 },
{ RSPOVRLOOKUPINT , "CIM response FIFO overwrite", -1, 1 },
{ TIMEOUTINT , "CIM PIF timeout", -1, 1 },
{ TIMEOUTMAINT , "CIM PIF MA timeout", -1, 1 },
{ 0, NULL, 0, 0 }
};
int fat;
fat = csio_handle_intr_status(hw, CIM_HOST_INT_CAUSE,
cim_intr_info) +
csio_handle_intr_status(hw, CIM_HOST_UPACC_INT_CAUSE,
cim_upintr_info);
if (fat)
csio_hw_fatal_err(hw);
}
static void csio_ulprx_intr_handler(struct csio_hw *hw)
{
static struct intr_info ulprx_intr_info[] = {
{ 0x1800000, "ULPRX context error", -1, 1 },
{ 0x7fffff, "ULPRX parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, ULP_RX_INT_CAUSE, ulprx_intr_info))
csio_hw_fatal_err(hw);
}
static void csio_ulptx_intr_handler(struct csio_hw *hw)
{
static struct intr_info ulptx_intr_info[] = {
{ PBL_BOUND_ERR_CH3, "ULPTX channel 3 PBL out of bounds", -1,
0 },
{ PBL_BOUND_ERR_CH2, "ULPTX channel 2 PBL out of bounds", -1,
0 },
{ PBL_BOUND_ERR_CH1, "ULPTX channel 1 PBL out of bounds", -1,
0 },
{ PBL_BOUND_ERR_CH0, "ULPTX channel 0 PBL out of bounds", -1,
0 },
{ 0xfffffff, "ULPTX parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, ULP_TX_INT_CAUSE, ulptx_intr_info))
csio_hw_fatal_err(hw);
}
static void csio_pmtx_intr_handler(struct csio_hw *hw)
{
static struct intr_info pmtx_intr_info[] = {
{ PCMD_LEN_OVFL0, "PMTX channel 0 pcmd too large", -1, 1 },
{ PCMD_LEN_OVFL1, "PMTX channel 1 pcmd too large", -1, 1 },
{ PCMD_LEN_OVFL2, "PMTX channel 2 pcmd too large", -1, 1 },
{ ZERO_C_CMD_ERROR, "PMTX 0-length pcmd", -1, 1 },
{ 0xffffff0, "PMTX framing error", -1, 1 },
{ OESPI_PAR_ERROR, "PMTX oespi parity error", -1, 1 },
{ DB_OPTIONS_PAR_ERROR, "PMTX db_options parity error", -1,
1 },
{ ICSPI_PAR_ERROR, "PMTX icspi parity error", -1, 1 },
{ C_PCMD_PAR_ERROR, "PMTX c_pcmd parity error", -1, 1},
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, PM_TX_INT_CAUSE, pmtx_intr_info))
csio_hw_fatal_err(hw);
}
static void csio_pmrx_intr_handler(struct csio_hw *hw)
{
static struct intr_info pmrx_intr_info[] = {
{ ZERO_E_CMD_ERROR, "PMRX 0-length pcmd", -1, 1 },
{ 0x3ffff0, "PMRX framing error", -1, 1 },
{ OCSPI_PAR_ERROR, "PMRX ocspi parity error", -1, 1 },
{ DB_OPTIONS_PAR_ERROR, "PMRX db_options parity error", -1,
1 },
{ IESPI_PAR_ERROR, "PMRX iespi parity error", -1, 1 },
{ E_PCMD_PAR_ERROR, "PMRX e_pcmd parity error", -1, 1},
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, PM_RX_INT_CAUSE, pmrx_intr_info))
csio_hw_fatal_err(hw);
}
static void csio_cplsw_intr_handler(struct csio_hw *hw)
{
static struct intr_info cplsw_intr_info[] = {
{ CIM_OP_MAP_PERR, "CPLSW CIM op_map parity error", -1, 1 },
{ CIM_OVFL_ERROR, "CPLSW CIM overflow", -1, 1 },
{ TP_FRAMING_ERROR, "CPLSW TP framing error", -1, 1 },
{ SGE_FRAMING_ERROR, "CPLSW SGE framing error", -1, 1 },
{ CIM_FRAMING_ERROR, "CPLSW CIM framing error", -1, 1 },
{ ZERO_SWITCH_ERROR, "CPLSW no-switch error", -1, 1 },
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, CPL_INTR_CAUSE, cplsw_intr_info))
csio_hw_fatal_err(hw);
}
static void csio_le_intr_handler(struct csio_hw *hw)
{
static struct intr_info le_intr_info[] = {
{ LIPMISS, "LE LIP miss", -1, 0 },
{ LIP0, "LE 0 LIP error", -1, 0 },
{ PARITYERR, "LE parity error", -1, 1 },
{ UNKNOWNCMD, "LE unknown command", -1, 1 },
{ REQQPARERR, "LE request queue parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, LE_DB_INT_CAUSE, le_intr_info))
csio_hw_fatal_err(hw);
}
static void csio_mps_intr_handler(struct csio_hw *hw)
{
static struct intr_info mps_rx_intr_info[] = {
{ 0xffffff, "MPS Rx parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
static struct intr_info mps_tx_intr_info[] = {
{ TPFIFO, "MPS Tx TP FIFO parity error", -1, 1 },
{ NCSIFIFO, "MPS Tx NC-SI FIFO parity error", -1, 1 },
{ TXDATAFIFO, "MPS Tx data FIFO parity error", -1, 1 },
{ TXDESCFIFO, "MPS Tx desc FIFO parity error", -1, 1 },
{ BUBBLE, "MPS Tx underflow", -1, 1 },
{ SECNTERR, "MPS Tx SOP/EOP error", -1, 1 },
{ FRMERR, "MPS Tx framing error", -1, 1 },
{ 0, NULL, 0, 0 }
};
static struct intr_info mps_trc_intr_info[] = {
{ FILTMEM, "MPS TRC filter parity error", -1, 1 },
{ PKTFIFO, "MPS TRC packet FIFO parity error", -1, 1 },
{ MISCPERR, "MPS TRC misc parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
static struct intr_info mps_stat_sram_intr_info[] = {
{ 0x1fffff, "MPS statistics SRAM parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
static struct intr_info mps_stat_tx_intr_info[] = {
{ 0xfffff, "MPS statistics Tx FIFO parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
static struct intr_info mps_stat_rx_intr_info[] = {
{ 0xffffff, "MPS statistics Rx FIFO parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
static struct intr_info mps_cls_intr_info[] = {
{ MATCHSRAM, "MPS match SRAM parity error", -1, 1 },
{ MATCHTCAM, "MPS match TCAM parity error", -1, 1 },
{ HASHSRAM, "MPS hash SRAM parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
int fat;
fat = csio_handle_intr_status(hw, MPS_RX_PERR_INT_CAUSE,
mps_rx_intr_info) +
csio_handle_intr_status(hw, MPS_TX_INT_CAUSE,
mps_tx_intr_info) +
csio_handle_intr_status(hw, MPS_TRC_INT_CAUSE,
mps_trc_intr_info) +
csio_handle_intr_status(hw, MPS_STAT_PERR_INT_CAUSE_SRAM,
mps_stat_sram_intr_info) +
csio_handle_intr_status(hw, MPS_STAT_PERR_INT_CAUSE_TX_FIFO,
mps_stat_tx_intr_info) +
csio_handle_intr_status(hw, MPS_STAT_PERR_INT_CAUSE_RX_FIFO,
mps_stat_rx_intr_info) +
csio_handle_intr_status(hw, MPS_CLS_INT_CAUSE,
mps_cls_intr_info);
csio_wr_reg32(hw, 0, MPS_INT_CAUSE);
csio_rd_reg32(hw, MPS_INT_CAUSE);
if (fat)
csio_hw_fatal_err(hw);
}
static void csio_mem_intr_handler(struct csio_hw *hw, int idx)
{
static const char name[3][5] = { "EDC0", "EDC1", "MC" };
unsigned int addr, cnt_addr, v;
if (idx <= MEM_EDC1) {
addr = EDC_REG(EDC_INT_CAUSE, idx);
cnt_addr = EDC_REG(EDC_ECC_STATUS, idx);
} else {
addr = MC_INT_CAUSE;
cnt_addr = MC_ECC_STATUS;
}
v = csio_rd_reg32(hw, addr) & MEM_INT_MASK;
if (v & PERR_INT_CAUSE)
csio_fatal(hw, "%s FIFO parity error\n", name[idx]);
if (v & ECC_CE_INT_CAUSE) {
uint32_t cnt = ECC_CECNT_GET(csio_rd_reg32(hw, cnt_addr));
csio_wr_reg32(hw, ECC_CECNT_MASK, cnt_addr);
csio_warn(hw, "%u %s correctable ECC data error%s\n",
cnt, name[idx], cnt > 1 ? "s" : "");
}
if (v & ECC_UE_INT_CAUSE)
csio_fatal(hw, "%s uncorrectable ECC data error\n", name[idx]);
csio_wr_reg32(hw, v, addr);
if (v & (PERR_INT_CAUSE | ECC_UE_INT_CAUSE))
csio_hw_fatal_err(hw);
}
static void csio_ma_intr_handler(struct csio_hw *hw)
{
uint32_t v, status = csio_rd_reg32(hw, MA_INT_CAUSE);
if (status & MEM_PERR_INT_CAUSE)
csio_fatal(hw, "MA parity error, parity status %#x\n",
csio_rd_reg32(hw, MA_PARITY_ERROR_STATUS));
if (status & MEM_WRAP_INT_CAUSE) {
v = csio_rd_reg32(hw, MA_INT_WRAP_STATUS);
csio_fatal(hw,
"MA address wrap-around error by client %u to address %#x\n",
MEM_WRAP_CLIENT_NUM_GET(v), MEM_WRAP_ADDRESS_GET(v) << 4);
}
csio_wr_reg32(hw, status, MA_INT_CAUSE);
csio_hw_fatal_err(hw);
}
static void csio_smb_intr_handler(struct csio_hw *hw)
{
static struct intr_info smb_intr_info[] = {
{ MSTTXFIFOPARINT, "SMB master Tx FIFO parity error", -1, 1 },
{ MSTRXFIFOPARINT, "SMB master Rx FIFO parity error", -1, 1 },
{ SLVFIFOPARINT, "SMB slave FIFO parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, SMB_INT_CAUSE, smb_intr_info))
csio_hw_fatal_err(hw);
}
static void csio_ncsi_intr_handler(struct csio_hw *hw)
{
static struct intr_info ncsi_intr_info[] = {
{ CIM_DM_PRTY_ERR, "NC-SI CIM parity error", -1, 1 },
{ MPS_DM_PRTY_ERR, "NC-SI MPS parity error", -1, 1 },
{ TXFIFO_PRTY_ERR, "NC-SI Tx FIFO parity error", -1, 1 },
{ RXFIFO_PRTY_ERR, "NC-SI Rx FIFO parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, NCSI_INT_CAUSE, ncsi_intr_info))
csio_hw_fatal_err(hw);
}
static void csio_xgmac_intr_handler(struct csio_hw *hw, int port)
{
uint32_t v = csio_rd_reg32(hw, CSIO_MAC_INT_CAUSE_REG(hw, port));
v &= TXFIFO_PRTY_ERR | RXFIFO_PRTY_ERR;
if (!v)
return;
if (v & TXFIFO_PRTY_ERR)
csio_fatal(hw, "XGMAC %d Tx FIFO parity error\n", port);
if (v & RXFIFO_PRTY_ERR)
csio_fatal(hw, "XGMAC %d Rx FIFO parity error\n", port);
csio_wr_reg32(hw, v, CSIO_MAC_INT_CAUSE_REG(hw, port));
csio_hw_fatal_err(hw);
}
static void csio_pl_intr_handler(struct csio_hw *hw)
{
static struct intr_info pl_intr_info[] = {
{ FATALPERR, "T4 fatal parity error", -1, 1 },
{ PERRVFID, "PL VFID_MAP parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
if (csio_handle_intr_status(hw, PL_PL_INT_CAUSE, pl_intr_info))
csio_hw_fatal_err(hw);
}
int
csio_hw_slow_intr_handler(struct csio_hw *hw)
{
uint32_t cause = csio_rd_reg32(hw, PL_INT_CAUSE);
if (!(cause & CSIO_GLBL_INTR_MASK)) {
CSIO_INC_STATS(hw, n_plint_unexp);
return 0;
}
csio_dbg(hw, "Slow interrupt! cause: 0x%x\n", cause);
CSIO_INC_STATS(hw, n_plint_cnt);
if (cause & CIM)
csio_cim_intr_handler(hw);
if (cause & MPS)
csio_mps_intr_handler(hw);
if (cause & NCSI)
csio_ncsi_intr_handler(hw);
if (cause & PL)
csio_pl_intr_handler(hw);
if (cause & SMB)
csio_smb_intr_handler(hw);
if (cause & XGMAC0)
csio_xgmac_intr_handler(hw, 0);
if (cause & XGMAC1)
csio_xgmac_intr_handler(hw, 1);
if (cause & XGMAC_KR0)
csio_xgmac_intr_handler(hw, 2);
if (cause & XGMAC_KR1)
csio_xgmac_intr_handler(hw, 3);
if (cause & PCIE)
hw->chip_ops->chip_pcie_intr_handler(hw);
if (cause & MC)
csio_mem_intr_handler(hw, MEM_MC);
if (cause & EDC0)
csio_mem_intr_handler(hw, MEM_EDC0);
if (cause & EDC1)
csio_mem_intr_handler(hw, MEM_EDC1);
if (cause & LE)
csio_le_intr_handler(hw);
if (cause & TP)
csio_tp_intr_handler(hw);
if (cause & MA)
csio_ma_intr_handler(hw);
if (cause & PM_TX)
csio_pmtx_intr_handler(hw);
if (cause & PM_RX)
csio_pmrx_intr_handler(hw);
if (cause & ULP_RX)
csio_ulprx_intr_handler(hw);
if (cause & CPL_SWITCH)
csio_cplsw_intr_handler(hw);
if (cause & SGE)
csio_sge_intr_handler(hw);
if (cause & ULP_TX)
csio_ulptx_intr_handler(hw);
csio_wr_reg32(hw, cause & CSIO_GLBL_INTR_MASK, PL_INT_CAUSE);
csio_rd_reg32(hw, PL_INT_CAUSE);
return 1;
}
static void
csio_mberr_worker(void *data)
{
struct csio_hw *hw = (struct csio_hw *)data;
struct csio_mbm *mbm = &hw->mbm;
LIST_HEAD(cbfn_q);
struct csio_mb *mbp_next;
int rv;
del_timer_sync(&mbm->timer);
spin_lock_irq(&hw->lock);
if (list_empty(&mbm->cbfn_q)) {
spin_unlock_irq(&hw->lock);
return;
}
list_splice_tail_init(&mbm->cbfn_q, &cbfn_q);
mbm->stats.n_cbfnq = 0;
if (!list_empty(&mbm->req_q)) {
mbp_next = list_first_entry(&mbm->req_q, struct csio_mb, list);
list_del_init(&mbp_next->list);
rv = csio_mb_issue(hw, mbp_next);
if (rv != 0)
list_add_tail(&mbp_next->list, &mbm->req_q);
else
CSIO_DEC_STATS(mbm, n_activeq);
}
spin_unlock_irq(&hw->lock);
csio_mb_completions(hw, &cbfn_q);
}
static void
csio_hw_mb_timer(uintptr_t data)
{
struct csio_hw *hw = (struct csio_hw *)data;
struct csio_mb *mbp = NULL;
spin_lock_irq(&hw->lock);
mbp = csio_mb_tmo_handler(hw);
spin_unlock_irq(&hw->lock);
if (mbp)
mbp->mb_cbfn(hw, mbp);
}
static void
csio_hw_mbm_cleanup(struct csio_hw *hw)
{
LIST_HEAD(cbfn_q);
csio_mb_cancel_all(hw, &cbfn_q);
spin_unlock_irq(&hw->lock);
csio_mb_completions(hw, &cbfn_q);
spin_lock_irq(&hw->lock);
}
int
csio_enqueue_evt(struct csio_hw *hw, enum csio_evt type, void *evt_msg,
uint16_t len)
{
struct csio_evt_msg *evt_entry = NULL;
if (type >= CSIO_EVT_MAX)
return -EINVAL;
if (len > CSIO_EVT_MSG_SIZE)
return -EINVAL;
if (hw->flags & CSIO_HWF_FWEVT_STOP)
return -EINVAL;
if (list_empty(&hw->evt_free_q)) {
csio_err(hw, "Failed to alloc evt entry, msg type %d len %d\n",
type, len);
return -ENOMEM;
}
evt_entry = list_first_entry(&hw->evt_free_q,
struct csio_evt_msg, list);
list_del_init(&evt_entry->list);
evt_entry->type = type;
memcpy((void *)evt_entry->data, evt_msg, len);
list_add_tail(&evt_entry->list, &hw->evt_active_q);
CSIO_DEC_STATS(hw, n_evt_freeq);
CSIO_INC_STATS(hw, n_evt_activeq);
return 0;
}
static int
csio_enqueue_evt_lock(struct csio_hw *hw, enum csio_evt type, void *evt_msg,
uint16_t len, bool msg_sg)
{
struct csio_evt_msg *evt_entry = NULL;
struct csio_fl_dma_buf *fl_sg;
uint32_t off = 0;
unsigned long flags;
int n, ret = 0;
if (type >= CSIO_EVT_MAX)
return -EINVAL;
if (len > CSIO_EVT_MSG_SIZE)
return -EINVAL;
spin_lock_irqsave(&hw->lock, flags);
if (hw->flags & CSIO_HWF_FWEVT_STOP) {
ret = -EINVAL;
goto out;
}
if (list_empty(&hw->evt_free_q)) {
csio_err(hw, "Failed to alloc evt entry, msg type %d len %d\n",
type, len);
ret = -ENOMEM;
goto out;
}
evt_entry = list_first_entry(&hw->evt_free_q,
struct csio_evt_msg, list);
list_del_init(&evt_entry->list);
evt_entry->type = type;
if (msg_sg) {
fl_sg = (struct csio_fl_dma_buf *) evt_msg;
for (n = 0; (n < CSIO_MAX_FLBUF_PER_IQWR && off < len); n++) {
memcpy((void *)((uintptr_t)evt_entry->data + off),
fl_sg->flbufs[n].vaddr,
fl_sg->flbufs[n].len);
off += fl_sg->flbufs[n].len;
}
} else
memcpy((void *)evt_entry->data, evt_msg, len);
list_add_tail(&evt_entry->list, &hw->evt_active_q);
CSIO_DEC_STATS(hw, n_evt_freeq);
CSIO_INC_STATS(hw, n_evt_activeq);
out:
spin_unlock_irqrestore(&hw->lock, flags);
return ret;
}
static void
csio_free_evt(struct csio_hw *hw, struct csio_evt_msg *evt_entry)
{
if (evt_entry) {
spin_lock_irq(&hw->lock);
list_del_init(&evt_entry->list);
list_add_tail(&evt_entry->list, &hw->evt_free_q);
CSIO_DEC_STATS(hw, n_evt_activeq);
CSIO_INC_STATS(hw, n_evt_freeq);
spin_unlock_irq(&hw->lock);
}
}
void
csio_evtq_flush(struct csio_hw *hw)
{
uint32_t count;
count = 30;
while (hw->flags & CSIO_HWF_FWEVT_PENDING && count--) {
spin_unlock_irq(&hw->lock);
msleep(2000);
spin_lock_irq(&hw->lock);
}
CSIO_DB_ASSERT(!(hw->flags & CSIO_HWF_FWEVT_PENDING));
}
static void
csio_evtq_stop(struct csio_hw *hw)
{
hw->flags |= CSIO_HWF_FWEVT_STOP;
}
static void
csio_evtq_start(struct csio_hw *hw)
{
hw->flags &= ~CSIO_HWF_FWEVT_STOP;
}
static void
csio_evtq_cleanup(struct csio_hw *hw)
{
struct list_head *evt_entry, *next_entry;
if (!list_empty(&hw->evt_active_q))
list_splice_tail_init(&hw->evt_active_q, &hw->evt_free_q);
hw->stats.n_evt_activeq = 0;
hw->flags &= ~CSIO_HWF_FWEVT_PENDING;
list_for_each_safe(evt_entry, next_entry, &hw->evt_free_q) {
kfree(evt_entry);
CSIO_DEC_STATS(hw, n_evt_freeq);
}
hw->stats.n_evt_freeq = 0;
}
static void
csio_process_fwevtq_entry(struct csio_hw *hw, void *wr, uint32_t len,
struct csio_fl_dma_buf *flb, void *priv)
{
__u8 op;
void *msg = NULL;
uint32_t msg_len = 0;
bool msg_sg = 0;
op = ((struct rss_header *) wr)->opcode;
if (op == CPL_FW6_PLD) {
CSIO_INC_STATS(hw, n_cpl_fw6_pld);
if (!flb || !flb->totlen) {
CSIO_INC_STATS(hw, n_cpl_unexp);
return;
}
msg = (void *) flb;
msg_len = flb->totlen;
msg_sg = 1;
} else if (op == CPL_FW6_MSG || op == CPL_FW4_MSG) {
CSIO_INC_STATS(hw, n_cpl_fw6_msg);
msg = (void *)((uintptr_t)wr + sizeof(__be64));
msg_len = (op == CPL_FW6_MSG) ? sizeof(struct cpl_fw6_msg) :
sizeof(struct cpl_fw4_msg);
} else {
csio_warn(hw, "unexpected CPL %#x on FW event queue\n", op);
CSIO_INC_STATS(hw, n_cpl_unexp);
return;
}
if (csio_enqueue_evt_lock(hw, CSIO_EVT_FW, msg,
(uint16_t)msg_len, msg_sg))
CSIO_INC_STATS(hw, n_evt_drop);
}
void
csio_evtq_worker(struct work_struct *work)
{
struct csio_hw *hw = container_of(work, struct csio_hw, evtq_work);
struct list_head *evt_entry, *next_entry;
LIST_HEAD(evt_q);
struct csio_evt_msg *evt_msg;
struct cpl_fw6_msg *msg;
struct csio_rnode *rn;
int rv = 0;
uint8_t evtq_stop = 0;
csio_dbg(hw, "event worker thread active evts#%d\n",
hw->stats.n_evt_activeq);
spin_lock_irq(&hw->lock);
while (!list_empty(&hw->evt_active_q)) {
list_splice_tail_init(&hw->evt_active_q, &evt_q);
spin_unlock_irq(&hw->lock);
list_for_each_safe(evt_entry, next_entry, &evt_q) {
evt_msg = (struct csio_evt_msg *) evt_entry;
spin_lock_irq(&hw->lock);
if (hw->flags & CSIO_HWF_FWEVT_STOP)
evtq_stop = 1;
spin_unlock_irq(&hw->lock);
if (evtq_stop) {
CSIO_INC_STATS(hw, n_evt_drop);
goto free_evt;
}
switch (evt_msg->type) {
case CSIO_EVT_FW:
msg = (struct cpl_fw6_msg *)(evt_msg->data);
if ((msg->opcode == CPL_FW6_MSG ||
msg->opcode == CPL_FW4_MSG) &&
!msg->type) {
rv = csio_mb_fwevt_handler(hw,
msg->data);
if (!rv)
break;
csio_fcoe_fwevt_handler(hw,
msg->opcode, msg->data);
} else if (msg->opcode == CPL_FW6_PLD) {
csio_fcoe_fwevt_handler(hw,
msg->opcode, msg->data);
} else {
csio_warn(hw,
"Unhandled FW msg op %x type %x\n",
msg->opcode, msg->type);
CSIO_INC_STATS(hw, n_evt_drop);
}
break;
case CSIO_EVT_MBX:
csio_mberr_worker(hw);
break;
case CSIO_EVT_DEV_LOSS:
memcpy(&rn, evt_msg->data, sizeof(rn));
csio_rnode_devloss_handler(rn);
break;
default:
csio_warn(hw, "Unhandled event %x on evtq\n",
evt_msg->type);
CSIO_INC_STATS(hw, n_evt_unexp);
break;
}
free_evt:
csio_free_evt(hw, evt_msg);
}
spin_lock_irq(&hw->lock);
}
hw->flags &= ~CSIO_HWF_FWEVT_PENDING;
spin_unlock_irq(&hw->lock);
}
int
csio_fwevtq_handler(struct csio_hw *hw)
{
int rv;
if (csio_q_iqid(hw, hw->fwevt_iq_idx) == CSIO_MAX_QID) {
CSIO_INC_STATS(hw, n_int_stray);
return -EINVAL;
}
rv = csio_wr_process_iq_idx(hw, hw->fwevt_iq_idx,
csio_process_fwevtq_entry, NULL);
return rv;
}
int
csio_mgmt_req_lookup(struct csio_mgmtm *mgmtm, struct csio_ioreq *io_req)
{
struct list_head *tmp;
list_for_each(tmp, &mgmtm->active_q) {
if (io_req == (struct csio_ioreq *)tmp)
return 0;
}
return -EINVAL;
}
static void
csio_mgmt_tmo_handler(uintptr_t data)
{
struct csio_mgmtm *mgmtm = (struct csio_mgmtm *) data;
struct list_head *tmp;
struct csio_ioreq *io_req;
csio_dbg(mgmtm->hw, "Mgmt timer invoked!\n");
spin_lock_irq(&mgmtm->hw->lock);
list_for_each(tmp, &mgmtm->active_q) {
io_req = (struct csio_ioreq *) tmp;
io_req->tmo -= min_t(uint32_t, io_req->tmo, ECM_MIN_TMO);
if (!io_req->tmo) {
tmp = csio_list_prev(tmp);
list_del_init(&io_req->sm.sm_list);
if (io_req->io_cbfn) {
io_req->wr_status = -ETIMEDOUT;
io_req->io_cbfn(mgmtm->hw, io_req);
} else {
CSIO_DB_ASSERT(0);
}
}
}
if (!list_empty(&mgmtm->active_q))
mod_timer(&mgmtm->mgmt_timer,
jiffies + msecs_to_jiffies(ECM_MIN_TMO));
spin_unlock_irq(&mgmtm->hw->lock);
}
static void
csio_mgmtm_cleanup(struct csio_mgmtm *mgmtm)
{
struct csio_hw *hw = mgmtm->hw;
struct csio_ioreq *io_req;
struct list_head *tmp;
uint32_t count;
count = 30;
while ((!list_empty(&mgmtm->active_q)) && count--) {
spin_unlock_irq(&hw->lock);
msleep(2000);
spin_lock_irq(&hw->lock);
}
list_for_each(tmp, &mgmtm->active_q) {
io_req = (struct csio_ioreq *) tmp;
tmp = csio_list_prev(tmp);
list_del_init(&io_req->sm.sm_list);
mgmtm->stats.n_active--;
if (io_req->io_cbfn) {
io_req->wr_status = -ETIMEDOUT;
io_req->io_cbfn(mgmtm->hw, io_req);
}
}
}
static int
csio_mgmtm_init(struct csio_mgmtm *mgmtm, struct csio_hw *hw)
{
struct timer_list *timer = &mgmtm->mgmt_timer;
init_timer(timer);
timer->function = csio_mgmt_tmo_handler;
timer->data = (unsigned long)mgmtm;
INIT_LIST_HEAD(&mgmtm->active_q);
INIT_LIST_HEAD(&mgmtm->cbfn_q);
mgmtm->hw = hw;
return 0;
}
static void
csio_mgmtm_exit(struct csio_mgmtm *mgmtm)
{
del_timer_sync(&mgmtm->mgmt_timer);
}
int
csio_hw_start(struct csio_hw *hw)
{
spin_lock_irq(&hw->lock);
csio_post_event(&hw->sm, CSIO_HWE_CFG);
spin_unlock_irq(&hw->lock);
if (csio_is_hw_ready(hw))
return 0;
else
return -EINVAL;
}
int
csio_hw_stop(struct csio_hw *hw)
{
csio_post_event(&hw->sm, CSIO_HWE_PCI_REMOVE);
if (csio_is_hw_removing(hw))
return 0;
else
return -EINVAL;
}
int
csio_hw_reset(struct csio_hw *hw)
{
if (!csio_is_hw_master(hw))
return -EPERM;
if (hw->rst_retries >= CSIO_MAX_RESET_RETRIES) {
csio_dbg(hw, "Max hw reset attempts reached..");
return -EINVAL;
}
hw->rst_retries++;
csio_post_event(&hw->sm, CSIO_HWE_HBA_RESET);
if (csio_is_hw_ready(hw)) {
hw->rst_retries = 0;
hw->stats.n_reset_start = jiffies_to_msecs(jiffies);
return 0;
} else
return -EINVAL;
}
static void
csio_hw_get_device_id(struct csio_hw *hw)
{
if (csio_is_dev_id_cached(hw))
return;
pci_read_config_word(hw->pdev, PCI_VENDOR_ID,
&hw->params.pci.vendor_id);
pci_read_config_word(hw->pdev, PCI_DEVICE_ID,
&hw->params.pci.device_id);
csio_dev_id_cached(hw);
hw->chip_id = (hw->params.pci.device_id & CSIO_HW_CHIP_MASK);
}
static void
csio_hw_set_description(struct csio_hw *hw, uint16_t ven_id, uint16_t dev_id)
{
uint32_t adap_type, prot_type;
if (ven_id == CSIO_VENDOR_ID) {
prot_type = (dev_id & CSIO_ASIC_DEVID_PROTO_MASK);
adap_type = (dev_id & CSIO_ASIC_DEVID_TYPE_MASK);
if (prot_type == CSIO_T4_FCOE_ASIC) {
memcpy(hw->hw_ver,
csio_t4_fcoe_adapters[adap_type].model_no, 16);
memcpy(hw->model_desc,
csio_t4_fcoe_adapters[adap_type].description,
32);
} else if (prot_type == CSIO_T5_FCOE_ASIC) {
memcpy(hw->hw_ver,
csio_t5_fcoe_adapters[adap_type].model_no, 16);
memcpy(hw->model_desc,
csio_t5_fcoe_adapters[adap_type].description,
32);
} else {
char tempName[32] = "Chelsio FCoE Controller";
memcpy(hw->model_desc, tempName, 32);
}
}
}
int
csio_hw_init(struct csio_hw *hw)
{
int rv = -EINVAL;
uint32_t i;
uint16_t ven_id, dev_id;
struct csio_evt_msg *evt_entry;
INIT_LIST_HEAD(&hw->sm.sm_list);
csio_init_state(&hw->sm, csio_hws_uninit);
spin_lock_init(&hw->lock);
INIT_LIST_HEAD(&hw->sln_head);
csio_hw_get_device_id(hw);
strcpy(hw->name, CSIO_HW_NAME);
hw->chip_ops = csio_is_t4(hw->chip_id) ? &t4_ops : &t5_ops;
ven_id = hw->params.pci.vendor_id;
dev_id = hw->params.pci.device_id;
csio_hw_set_description(hw, ven_id, dev_id);
hw->params.log_level = (uint32_t) csio_dbg_level;
csio_set_fwevt_intr_idx(hw, -1);
csio_set_nondata_intr_idx(hw, -1);
if (csio_mbm_init(csio_hw_to_mbm(hw), hw, csio_hw_mb_timer))
goto err;
rv = csio_wrm_init(csio_hw_to_wrm(hw), hw);
if (rv)
goto err_mbm_exit;
rv = csio_scsim_init(csio_hw_to_scsim(hw), hw);
if (rv)
goto err_wrm_exit;
rv = csio_mgmtm_init(csio_hw_to_mgmtm(hw), hw);
if (rv)
goto err_scsim_exit;
INIT_LIST_HEAD(&hw->evt_active_q);
INIT_LIST_HEAD(&hw->evt_free_q);
for (i = 0; i < csio_evtq_sz; i++) {
evt_entry = kzalloc(sizeof(struct csio_evt_msg), GFP_KERNEL);
if (!evt_entry) {
csio_err(hw, "Failed to initialize eventq");
goto err_evtq_cleanup;
}
list_add_tail(&evt_entry->list, &hw->evt_free_q);
CSIO_INC_STATS(hw, n_evt_freeq);
}
hw->dev_num = dev_num;
dev_num++;
return 0;
err_evtq_cleanup:
csio_evtq_cleanup(hw);
csio_mgmtm_exit(csio_hw_to_mgmtm(hw));
err_scsim_exit:
csio_scsim_exit(csio_hw_to_scsim(hw));
err_wrm_exit:
csio_wrm_exit(csio_hw_to_wrm(hw), hw);
err_mbm_exit:
csio_mbm_exit(csio_hw_to_mbm(hw));
err:
return rv;
}
void
csio_hw_exit(struct csio_hw *hw)
{
csio_evtq_cleanup(hw);
csio_mgmtm_exit(csio_hw_to_mgmtm(hw));
csio_scsim_exit(csio_hw_to_scsim(hw));
csio_wrm_exit(csio_hw_to_wrm(hw), hw);
csio_mbm_exit(csio_hw_to_mbm(hw));
}
