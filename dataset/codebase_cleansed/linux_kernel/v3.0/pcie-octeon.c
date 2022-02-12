static inline uint64_t cvmx_pcie_get_io_base_address(int pcie_port)
{
union cvmx_pcie_address pcie_addr;
pcie_addr.u64 = 0;
pcie_addr.io.upper = 0;
pcie_addr.io.io = 1;
pcie_addr.io.did = 3;
pcie_addr.io.subdid = 2;
pcie_addr.io.es = 1;
pcie_addr.io.port = pcie_port;
return pcie_addr.u64;
}
static inline uint64_t cvmx_pcie_get_io_size(int pcie_port)
{
return 1ull << 32;
}
static inline uint64_t cvmx_pcie_get_mem_base_address(int pcie_port)
{
union cvmx_pcie_address pcie_addr;
pcie_addr.u64 = 0;
pcie_addr.mem.upper = 0;
pcie_addr.mem.io = 1;
pcie_addr.mem.did = 3;
pcie_addr.mem.subdid = 3 + pcie_port;
return pcie_addr.u64;
}
static inline uint64_t cvmx_pcie_get_mem_size(int pcie_port)
{
return 1ull << 36;
}
static uint32_t cvmx_pcie_cfgx_read(int pcie_port, uint32_t cfg_offset)
{
union cvmx_pescx_cfg_rd pescx_cfg_rd;
pescx_cfg_rd.u64 = 0;
pescx_cfg_rd.s.addr = cfg_offset;
cvmx_write_csr(CVMX_PESCX_CFG_RD(pcie_port), pescx_cfg_rd.u64);
pescx_cfg_rd.u64 = cvmx_read_csr(CVMX_PESCX_CFG_RD(pcie_port));
return pescx_cfg_rd.s.data;
}
static void cvmx_pcie_cfgx_write(int pcie_port, uint32_t cfg_offset,
uint32_t val)
{
union cvmx_pescx_cfg_wr pescx_cfg_wr;
pescx_cfg_wr.u64 = 0;
pescx_cfg_wr.s.addr = cfg_offset;
pescx_cfg_wr.s.data = val;
cvmx_write_csr(CVMX_PESCX_CFG_WR(pcie_port), pescx_cfg_wr.u64);
}
static inline uint64_t __cvmx_pcie_build_config_addr(int pcie_port, int bus,
int dev, int fn, int reg)
{
union cvmx_pcie_address pcie_addr;
union cvmx_pciercx_cfg006 pciercx_cfg006;
pciercx_cfg006.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG006(pcie_port));
if ((bus <= pciercx_cfg006.s.pbnum) && (dev != 0))
return 0;
pcie_addr.u64 = 0;
pcie_addr.config.upper = 2;
pcie_addr.config.io = 1;
pcie_addr.config.did = 3;
pcie_addr.config.subdid = 1;
pcie_addr.config.es = 1;
pcie_addr.config.port = pcie_port;
pcie_addr.config.ty = (bus > pciercx_cfg006.s.pbnum);
pcie_addr.config.bus = bus;
pcie_addr.config.dev = dev;
pcie_addr.config.func = fn;
pcie_addr.config.reg = reg;
return pcie_addr.u64;
}
static uint8_t cvmx_pcie_config_read8(int pcie_port, int bus, int dev,
int fn, int reg)
{
uint64_t address =
__cvmx_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
if (address)
return cvmx_read64_uint8(address);
else
return 0xff;
}
static uint16_t cvmx_pcie_config_read16(int pcie_port, int bus, int dev,
int fn, int reg)
{
uint64_t address =
__cvmx_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
if (address)
return le16_to_cpu(cvmx_read64_uint16(address));
else
return 0xffff;
}
static uint32_t cvmx_pcie_config_read32(int pcie_port, int bus, int dev,
int fn, int reg)
{
uint64_t address =
__cvmx_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
if (address)
return le32_to_cpu(cvmx_read64_uint32(address));
else
return 0xffffffff;
}
static void cvmx_pcie_config_write8(int pcie_port, int bus, int dev, int fn,
int reg, uint8_t val)
{
uint64_t address =
__cvmx_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
if (address)
cvmx_write64_uint8(address, val);
}
static void cvmx_pcie_config_write16(int pcie_port, int bus, int dev, int fn,
int reg, uint16_t val)
{
uint64_t address =
__cvmx_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
if (address)
cvmx_write64_uint16(address, cpu_to_le16(val));
}
static void cvmx_pcie_config_write32(int pcie_port, int bus, int dev, int fn,
int reg, uint32_t val)
{
uint64_t address =
__cvmx_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
if (address)
cvmx_write64_uint32(address, cpu_to_le32(val));
}
static void __cvmx_pcie_rc_initialize_config_space(int pcie_port)
{
union cvmx_pciercx_cfg030 pciercx_cfg030;
union cvmx_npei_ctl_status2 npei_ctl_status2;
union cvmx_pciercx_cfg070 pciercx_cfg070;
union cvmx_pciercx_cfg001 pciercx_cfg001;
union cvmx_pciercx_cfg032 pciercx_cfg032;
union cvmx_pciercx_cfg006 pciercx_cfg006;
union cvmx_pciercx_cfg008 pciercx_cfg008;
union cvmx_pciercx_cfg009 pciercx_cfg009;
union cvmx_pciercx_cfg010 pciercx_cfg010;
union cvmx_pciercx_cfg011 pciercx_cfg011;
union cvmx_pciercx_cfg035 pciercx_cfg035;
union cvmx_pciercx_cfg075 pciercx_cfg075;
union cvmx_pciercx_cfg034 pciercx_cfg034;
pciercx_cfg030.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG030(pcie_port));
pciercx_cfg030.s.mps = 0;
pciercx_cfg030.s.mrrs = 0;
pciercx_cfg030.s.ro_en = 1;
pciercx_cfg030.s.ns_en = 1;
pciercx_cfg030.s.ce_en = 1;
pciercx_cfg030.s.nfe_en = 1;
pciercx_cfg030.s.fe_en = 1;
pciercx_cfg030.s.ur_en = 1;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG030(pcie_port),
pciercx_cfg030.u32);
npei_ctl_status2.u64 = cvmx_read_csr(CVMX_PEXP_NPEI_CTL_STATUS2);
npei_ctl_status2.s.mps = 0;
npei_ctl_status2.s.mrrs = 0;
if (pcie_port)
npei_ctl_status2.s.c1_b1_s = 3;
else
npei_ctl_status2.s.c0_b1_s = 3;
cvmx_write_csr(CVMX_PEXP_NPEI_CTL_STATUS2, npei_ctl_status2.u64);
pciercx_cfg070.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG070(pcie_port));
pciercx_cfg070.s.ge = 1;
pciercx_cfg070.s.ce = 1;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG070(pcie_port),
pciercx_cfg070.u32);
pciercx_cfg001.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG001(pcie_port));
pciercx_cfg001.s.msae = 1;
pciercx_cfg001.s.me = 1;
pciercx_cfg001.s.i_dis = 1;
pciercx_cfg001.s.see = 1;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG001(pcie_port),
pciercx_cfg001.u32);
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG066(pcie_port), 0);
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG069(pcie_port), 0);
pciercx_cfg032.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG032(pcie_port));
pciercx_cfg032.s.aslpc = 0;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG032(pcie_port),
pciercx_cfg032.u32);
pciercx_cfg006.u32 = 0;
pciercx_cfg006.s.pbnum = 1;
pciercx_cfg006.s.sbnum = 1;
pciercx_cfg006.s.subbnum = 1;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG006(pcie_port),
pciercx_cfg006.u32);
pciercx_cfg008.u32 = 0;
pciercx_cfg008.s.mb_addr = 0x100;
pciercx_cfg008.s.ml_addr = 0;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG008(pcie_port),
pciercx_cfg008.u32);
pciercx_cfg009.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG009(pcie_port));
pciercx_cfg010.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG010(pcie_port));
pciercx_cfg011.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG011(pcie_port));
pciercx_cfg009.s.lmem_base = 0x100;
pciercx_cfg009.s.lmem_limit = 0;
pciercx_cfg010.s.umem_base = 0x100;
pciercx_cfg011.s.umem_limit = 0;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG009(pcie_port),
pciercx_cfg009.u32);
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG010(pcie_port),
pciercx_cfg010.u32);
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG011(pcie_port),
pciercx_cfg011.u32);
pciercx_cfg035.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG035(pcie_port));
pciercx_cfg035.s.secee = 1;
pciercx_cfg035.s.sefee = 1;
pciercx_cfg035.s.senfee = 1;
pciercx_cfg035.s.pmeie = 1;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG035(pcie_port),
pciercx_cfg035.u32);
pciercx_cfg075.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG075(pcie_port));
pciercx_cfg075.s.cere = 1;
pciercx_cfg075.s.nfere = 1;
pciercx_cfg075.s.fere = 1;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG075(pcie_port),
pciercx_cfg075.u32);
pciercx_cfg034.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG034(pcie_port));
pciercx_cfg034.s.hpint_en = 1;
pciercx_cfg034.s.dlls_en = 1;
pciercx_cfg034.s.ccint_en = 1;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG034(pcie_port),
pciercx_cfg034.u32);
}
static int __cvmx_pcie_rc_initialize_link(int pcie_port)
{
uint64_t start_cycle;
union cvmx_pescx_ctl_status pescx_ctl_status;
union cvmx_pciercx_cfg452 pciercx_cfg452;
union cvmx_pciercx_cfg032 pciercx_cfg032;
union cvmx_pciercx_cfg448 pciercx_cfg448;
pciercx_cfg452.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG452(pcie_port));
pescx_ctl_status.u64 = cvmx_read_csr(CVMX_PESCX_CTL_STATUS(pcie_port));
if (pescx_ctl_status.s.qlm_cfg == 0) {
pciercx_cfg452.s.lme = 0xf;
} else {
pciercx_cfg452.s.lme = 0x7;
}
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG452(pcie_port),
pciercx_cfg452.u32);
if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X)) {
union cvmx_pciercx_cfg455 pciercx_cfg455;
pciercx_cfg455.u32 =
cvmx_pcie_cfgx_read(pcie_port,
CVMX_PCIERCX_CFG455(pcie_port));
pciercx_cfg455.s.m_cpl_len_err = 1;
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG455(pcie_port),
pciercx_cfg455.u32);
}
if (OCTEON_IS_MODEL(OCTEON_CN52XX) && (pcie_port == 1)) {
pescx_ctl_status.s.lane_swp = 1;
cvmx_write_csr(CVMX_PESCX_CTL_STATUS(pcie_port),
pescx_ctl_status.u64);
}
pescx_ctl_status.u64 = cvmx_read_csr(CVMX_PESCX_CTL_STATUS(pcie_port));
pescx_ctl_status.s.lnk_enb = 1;
cvmx_write_csr(CVMX_PESCX_CTL_STATUS(pcie_port), pescx_ctl_status.u64);
if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_0))
__cvmx_helper_errata_qlm_disable_2nd_order_cdr(0);
cvmx_dprintf("PCIe: Waiting for port %d link\n", pcie_port);
start_cycle = cvmx_get_cycle();
do {
if (cvmx_get_cycle() - start_cycle >
2 * cvmx_sysinfo_get()->cpu_clock_hz) {
cvmx_dprintf("PCIe: Port %d link timeout\n",
pcie_port);
return -1;
}
cvmx_wait(10000);
pciercx_cfg032.u32 =
cvmx_pcie_cfgx_read(pcie_port,
CVMX_PCIERCX_CFG032(pcie_port));
} while (pciercx_cfg032.s.dlla == 0);
cvmx_dprintf("PCIe: Port %d link active, %d lanes\n", pcie_port,
pciercx_cfg032.s.nlw);
pciercx_cfg448.u32 =
cvmx_pcie_cfgx_read(pcie_port, CVMX_PCIERCX_CFG448(pcie_port));
switch (pciercx_cfg032.s.nlw) {
case 1:
pciercx_cfg448.s.rtl = 1677;
break;
case 2:
pciercx_cfg448.s.rtl = 867;
break;
case 4:
pciercx_cfg448.s.rtl = 462;
break;
case 8:
pciercx_cfg448.s.rtl = 258;
break;
}
cvmx_pcie_cfgx_write(pcie_port, CVMX_PCIERCX_CFG448(pcie_port),
pciercx_cfg448.u32);
return 0;
}
static int cvmx_pcie_rc_initialize(int pcie_port)
{
int i;
int base;
u64 addr_swizzle;
union cvmx_ciu_soft_prst ciu_soft_prst;
union cvmx_pescx_bist_status pescx_bist_status;
union cvmx_pescx_bist_status2 pescx_bist_status2;
union cvmx_npei_ctl_status npei_ctl_status;
union cvmx_npei_mem_access_ctl npei_mem_access_ctl;
union cvmx_npei_mem_access_subidx mem_access_subid;
union cvmx_npei_dbg_data npei_dbg_data;
union cvmx_pescx_ctl_status2 pescx_ctl_status2;
union cvmx_npei_bar1_indexx bar1_index;
npei_ctl_status.u64 = cvmx_read_csr(CVMX_PEXP_NPEI_CTL_STATUS);
if ((pcie_port == 0) && !npei_ctl_status.s.host_mode) {
cvmx_dprintf("PCIe: ERROR: cvmx_pcie_rc_initialize() called "
"on port0, but port0 is not in host mode\n");
return -1;
}
if (OCTEON_IS_MODEL(OCTEON_CN52XX)) {
npei_dbg_data.u64 = cvmx_read_csr(CVMX_PEXP_NPEI_DBG_DATA);
if ((pcie_port == 1) && npei_dbg_data.cn52xx.qlm0_link_width) {
cvmx_dprintf("PCIe: ERROR: cvmx_pcie_rc_initialize() "
"called on port1, but port1 is "
"disabled\n");
return -1;
}
}
npei_ctl_status.s.arb = 1;
npei_ctl_status.s.cfg_rtry = 0x20;
if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X)) {
npei_ctl_status.s.p0_ntags = 0x20;
npei_ctl_status.s.p1_ntags = 0x20;
}
cvmx_write_csr(CVMX_PEXP_NPEI_CTL_STATUS, npei_ctl_status.u64);
if (cvmx_sysinfo_get()->board_type == CVMX_BOARD_TYPE_EBH5200) {
if (pcie_port == 0) {
ciu_soft_prst.u64 = cvmx_read_csr(CVMX_CIU_SOFT_PRST);
if (ciu_soft_prst.s.soft_prst == 0) {
ciu_soft_prst.s.soft_prst = 1;
cvmx_write_csr(CVMX_CIU_SOFT_PRST,
ciu_soft_prst.u64);
ciu_soft_prst.u64 =
cvmx_read_csr(CVMX_CIU_SOFT_PRST1);
ciu_soft_prst.s.soft_prst = 1;
cvmx_write_csr(CVMX_CIU_SOFT_PRST1,
ciu_soft_prst.u64);
udelay(2000);
}
ciu_soft_prst.u64 = cvmx_read_csr(CVMX_CIU_SOFT_PRST1);
ciu_soft_prst.s.soft_prst = 0;
cvmx_write_csr(CVMX_CIU_SOFT_PRST1, ciu_soft_prst.u64);
ciu_soft_prst.u64 = cvmx_read_csr(CVMX_CIU_SOFT_PRST);
ciu_soft_prst.s.soft_prst = 0;
cvmx_write_csr(CVMX_CIU_SOFT_PRST, ciu_soft_prst.u64);
}
} else {
if (pcie_port)
ciu_soft_prst.u64 = cvmx_read_csr(CVMX_CIU_SOFT_PRST1);
else
ciu_soft_prst.u64 = cvmx_read_csr(CVMX_CIU_SOFT_PRST);
if (ciu_soft_prst.s.soft_prst == 0) {
ciu_soft_prst.s.soft_prst = 1;
if (pcie_port)
cvmx_write_csr(CVMX_CIU_SOFT_PRST1,
ciu_soft_prst.u64);
else
cvmx_write_csr(CVMX_CIU_SOFT_PRST,
ciu_soft_prst.u64);
udelay(2000);
}
if (pcie_port) {
ciu_soft_prst.u64 = cvmx_read_csr(CVMX_CIU_SOFT_PRST1);
ciu_soft_prst.s.soft_prst = 0;
cvmx_write_csr(CVMX_CIU_SOFT_PRST1, ciu_soft_prst.u64);
} else {
ciu_soft_prst.u64 = cvmx_read_csr(CVMX_CIU_SOFT_PRST);
ciu_soft_prst.s.soft_prst = 0;
cvmx_write_csr(CVMX_CIU_SOFT_PRST, ciu_soft_prst.u64);
}
}
cvmx_wait(400000);
if (!OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X)
&& !OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X)) {
pescx_ctl_status2.u64 =
cvmx_read_csr(CVMX_PESCX_CTL_STATUS2(pcie_port));
pescx_ctl_status2.s.pclk_run = 1;
cvmx_write_csr(CVMX_PESCX_CTL_STATUS2(pcie_port),
pescx_ctl_status2.u64);
if (CVMX_WAIT_FOR_FIELD64(CVMX_PESCX_CTL_STATUS2(pcie_port),
union cvmx_pescx_ctl_status2,
pclk_run, ==, 1, 10000)) {
cvmx_dprintf("PCIe: Port %d isn't clocked, skipping.\n",
pcie_port);
return -1;
}
}
pescx_ctl_status2.u64 =
cvmx_read_csr(CVMX_PESCX_CTL_STATUS2(pcie_port));
if (pescx_ctl_status2.s.pcierst) {
cvmx_dprintf("PCIe: Port %d stuck in reset, skipping.\n",
pcie_port);
return -1;
}
pescx_bist_status2.u64 =
cvmx_read_csr(CVMX_PESCX_BIST_STATUS2(pcie_port));
if (pescx_bist_status2.u64) {
cvmx_dprintf("PCIe: Port %d BIST2 failed. Most likely this "
"port isn't hooked up, skipping.\n",
pcie_port);
return -1;
}
pescx_bist_status.u64 =
cvmx_read_csr(CVMX_PESCX_BIST_STATUS(pcie_port));
if (pescx_bist_status.u64)
cvmx_dprintf("PCIe: BIST FAILED for port %d (0x%016llx)\n",
pcie_port, CAST64(pescx_bist_status.u64));
__cvmx_pcie_rc_initialize_config_space(pcie_port);
if (__cvmx_pcie_rc_initialize_link(pcie_port)) {
cvmx_dprintf
("PCIe: ERROR: cvmx_pcie_rc_initialize_link() failed\n");
return -1;
}
npei_mem_access_ctl.u64 = cvmx_read_csr(CVMX_PEXP_NPEI_MEM_ACCESS_CTL);
npei_mem_access_ctl.s.max_word = 0;
npei_mem_access_ctl.s.timer = 127;
cvmx_write_csr(CVMX_PEXP_NPEI_MEM_ACCESS_CTL, npei_mem_access_ctl.u64);
mem_access_subid.u64 = 0;
mem_access_subid.s.port = pcie_port;
mem_access_subid.s.nmerge = 1;
mem_access_subid.s.esr = 1;
mem_access_subid.s.esw = 1;
mem_access_subid.s.nsr = 1;
mem_access_subid.s.nsw = 1;
mem_access_subid.s.ror = 0;
mem_access_subid.s.row = 0;
mem_access_subid.s.ba = 0;
for (i = 12 + pcie_port * 4; i < 16 + pcie_port * 4; i++) {
cvmx_write_csr(CVMX_PEXP_NPEI_MEM_ACCESS_SUBIDX(i),
mem_access_subid.u64);
mem_access_subid.s.ba += 1;
}
for (i = 0; i < 4; i++) {
cvmx_write_csr(CVMX_PESCX_P2P_BARX_START(i, pcie_port), -1);
cvmx_write_csr(CVMX_PESCX_P2P_BARX_END(i, pcie_port), -1);
}
cvmx_write_csr(CVMX_PESCX_P2N_BAR0_START(pcie_port), 0);
cvmx_write_csr(CVMX_PESCX_P2N_BAR1_START(pcie_port), CVMX_PCIE_BAR1_RC_BASE);
bar1_index.u32 = 0;
bar1_index.s.addr_idx = (CVMX_PCIE_BAR1_PHYS_BASE >> 22);
bar1_index.s.ca = 1;
bar1_index.s.end_swp = 1;
bar1_index.s.addr_v = 1;
base = pcie_port ? 16 : 0;
#ifdef __MIPSEB__
addr_swizzle = 4;
#else
addr_swizzle = 0;
#endif
for (i = 0; i < 16; i++) {
cvmx_write64_uint32((CVMX_PEXP_NPEI_BAR1_INDEXX(base) ^ addr_swizzle),
bar1_index.u32);
base++;
bar1_index.s.addr_idx += (((1ull << 28) / 16ull) >> 22);
}
cvmx_write_csr(CVMX_PESCX_P2N_BAR2_START(pcie_port), 0);
if (pcie_port) {
union cvmx_npei_ctl_port1 npei_ctl_port;
npei_ctl_port.u64 = cvmx_read_csr(CVMX_PEXP_NPEI_CTL_PORT1);
npei_ctl_port.s.bar2_enb = 1;
npei_ctl_port.s.bar2_esx = 1;
npei_ctl_port.s.bar2_cax = 0;
npei_ctl_port.s.ptlp_ro = 1;
npei_ctl_port.s.ctlp_ro = 1;
npei_ctl_port.s.wait_com = 0;
npei_ctl_port.s.waitl_com = 0;
cvmx_write_csr(CVMX_PEXP_NPEI_CTL_PORT1, npei_ctl_port.u64);
} else {
union cvmx_npei_ctl_port0 npei_ctl_port;
npei_ctl_port.u64 = cvmx_read_csr(CVMX_PEXP_NPEI_CTL_PORT0);
npei_ctl_port.s.bar2_enb = 1;
npei_ctl_port.s.bar2_esx = 1;
npei_ctl_port.s.bar2_cax = 0;
npei_ctl_port.s.ptlp_ro = 1;
npei_ctl_port.s.ctlp_ro = 1;
npei_ctl_port.s.wait_com = 0;
npei_ctl_port.s.waitl_com = 0;
cvmx_write_csr(CVMX_PEXP_NPEI_CTL_PORT0, npei_ctl_port.u64);
}
return 0;
}
int __init octeon_pcie_pcibios_map_irq(const struct pci_dev *dev,
u8 slot, u8 pin)
{
if (strstr(octeon_board_type_string(), "EBH5600") &&
dev->bus && dev->bus->parent) {
while (dev->bus && dev->bus->parent)
dev = to_pci_dev(dev->bus->bridge);
if ((dev->bus->number == 0) &&
(dev->vendor == 0x10b5) && (dev->device == 0x8114)) {
pin = ((pin - 3) & 3) + 1;
}
}
return pin - 1 + OCTEON_IRQ_PCI_INT0;
}
static inline int octeon_pcie_read_config(int pcie_port, struct pci_bus *bus,
unsigned int devfn, int reg, int size,
u32 *val)
{
union octeon_cvmemctl cvmmemctl;
union octeon_cvmemctl cvmmemctl_save;
int bus_number = bus->number;
if (bus->parent == NULL) {
union cvmx_pciercx_cfg006 pciercx_cfg006;
pciercx_cfg006.u32 = cvmx_pcie_cfgx_read(pcie_port,
CVMX_PCIERCX_CFG006(pcie_port));
if (pciercx_cfg006.s.pbnum != bus_number) {
pciercx_cfg006.s.pbnum = bus_number;
pciercx_cfg006.s.sbnum = bus_number;
pciercx_cfg006.s.subbnum = bus_number;
cvmx_pcie_cfgx_write(pcie_port,
CVMX_PCIERCX_CFG006(pcie_port),
pciercx_cfg006.u32);
}
}
if ((bus->parent == NULL) && (devfn >> 3 != 0))
return PCIBIOS_FUNC_NOT_SUPPORTED;
if (OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1) ||
OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_1)) {
if ((bus->parent == NULL) && (devfn >= 2))
return PCIBIOS_FUNC_NOT_SUPPORTED;
#if 1
if (bus_number == 1)
return PCIBIOS_FUNC_NOT_SUPPORTED;
#elif 0
if ((bus_number == 1) && (devfn >> 3 != 2))
return PCIBIOS_FUNC_NOT_SUPPORTED;
#elif 0
if ((bus_number == 1) && (devfn >> 3 != 3))
return PCIBIOS_FUNC_NOT_SUPPORTED;
#elif 0
if ((bus_number == 1) &&
!((devfn == (2 << 3)) || (devfn == (3 << 3))))
return PCIBIOS_FUNC_NOT_SUPPORTED;
#endif
cvmmemctl_save.u64 = __read_64bit_c0_register($11, 7);
cvmmemctl.u64 = cvmmemctl_save.u64;
cvmmemctl.s.didtto = 2;
__write_64bit_c0_register($11, 7, cvmmemctl.u64);
}
switch (size) {
case 4:
*val = cvmx_pcie_config_read32(pcie_port, bus_number,
devfn >> 3, devfn & 0x7, reg);
break;
case 2:
*val = cvmx_pcie_config_read16(pcie_port, bus_number,
devfn >> 3, devfn & 0x7, reg);
break;
case 1:
*val = cvmx_pcie_config_read8(pcie_port, bus_number, devfn >> 3,
devfn & 0x7, reg);
break;
default:
return PCIBIOS_FUNC_NOT_SUPPORTED;
}
if (OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1) ||
OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_1))
__write_64bit_c0_register($11, 7, cvmmemctl_save.u64);
return PCIBIOS_SUCCESSFUL;
}
static int octeon_pcie0_read_config(struct pci_bus *bus, unsigned int devfn,
int reg, int size, u32 *val)
{
return octeon_pcie_read_config(0, bus, devfn, reg, size, val);
}
static int octeon_pcie1_read_config(struct pci_bus *bus, unsigned int devfn,
int reg, int size, u32 *val)
{
return octeon_pcie_read_config(1, bus, devfn, reg, size, val);
}
static inline int octeon_pcie_write_config(int pcie_port, struct pci_bus *bus,
unsigned int devfn, int reg,
int size, u32 val)
{
int bus_number = bus->number;
switch (size) {
case 4:
cvmx_pcie_config_write32(pcie_port, bus_number, devfn >> 3,
devfn & 0x7, reg, val);
return PCIBIOS_SUCCESSFUL;
case 2:
cvmx_pcie_config_write16(pcie_port, bus_number, devfn >> 3,
devfn & 0x7, reg, val);
return PCIBIOS_SUCCESSFUL;
case 1:
cvmx_pcie_config_write8(pcie_port, bus_number, devfn >> 3,
devfn & 0x7, reg, val);
return PCIBIOS_SUCCESSFUL;
}
#if PCI_CONFIG_SPACE_DELAY
udelay(PCI_CONFIG_SPACE_DELAY);
#endif
return PCIBIOS_FUNC_NOT_SUPPORTED;
}
static int octeon_pcie0_write_config(struct pci_bus *bus, unsigned int devfn,
int reg, int size, u32 val)
{
return octeon_pcie_write_config(0, bus, devfn, reg, size, val);
}
static int octeon_pcie1_write_config(struct pci_bus *bus, unsigned int devfn,
int reg, int size, u32 val)
{
return octeon_pcie_write_config(1, bus, devfn, reg, size, val);
}
static int __init octeon_pcie_setup(void)
{
union cvmx_npei_ctl_status npei_ctl_status;
int result;
if (!octeon_has_feature(OCTEON_FEATURE_PCIE))
return 0;
octeon_pcibios_map_irq = octeon_pcie_pcibios_map_irq;
octeon_dma_bar_type = OCTEON_DMA_BAR_TYPE_PCIE;
set_io_port_base(CVMX_ADD_IO_SEG(cvmx_pcie_get_io_base_address(0)));
ioport_resource.start = 0;
ioport_resource.end =
cvmx_pcie_get_io_base_address(1) -
cvmx_pcie_get_io_base_address(0) + cvmx_pcie_get_io_size(1) - 1;
npei_ctl_status.u64 = cvmx_read_csr(CVMX_PEXP_NPEI_CTL_STATUS);
if (npei_ctl_status.s.host_mode) {
pr_notice("PCIe: Initializing port 0\n");
result = cvmx_pcie_rc_initialize(0);
if (result == 0) {
octeon_pcie0_controller.mem_offset =
cvmx_pcie_get_mem_base_address(0);
octeon_pcie0_controller.io_map_base =
CVMX_ADD_IO_SEG(cvmx_pcie_get_io_base_address
(0));
octeon_pcie0_controller.io_offset = 0;
octeon_pcie0_controller.mem_resource->start =
cvmx_pcie_get_mem_base_address(0) +
(4ul << 30) - (OCTEON_PCI_BAR1_HOLE_SIZE << 20);
octeon_pcie0_controller.mem_resource->end =
cvmx_pcie_get_mem_base_address(0) +
cvmx_pcie_get_mem_size(0) - 1;
octeon_pcie0_controller.io_resource->start = 4 << 10;
octeon_pcie0_controller.io_resource->end =
cvmx_pcie_get_io_size(0) - 1;
register_pci_controller(&octeon_pcie0_controller);
}
} else {
pr_notice("PCIe: Port 0 in endpoint mode, skipping.\n");
}
if (OCTEON_IS_MODEL(OCTEON_CN52XX)) {
union cvmx_npei_dbg_data npei_dbg_data;
npei_dbg_data.u64 = cvmx_read_csr(CVMX_PEXP_NPEI_DBG_DATA);
if (npei_dbg_data.cn52xx.qlm0_link_width)
return 0;
}
pr_notice("PCIe: Initializing port 1\n");
result = cvmx_pcie_rc_initialize(1);
if (result == 0) {
octeon_pcie1_controller.mem_offset =
cvmx_pcie_get_mem_base_address(1);
octeon_pcie1_controller.io_map_base =
CVMX_ADD_IO_SEG(cvmx_pcie_get_io_base_address(1));
octeon_pcie1_controller.io_offset =
cvmx_pcie_get_io_base_address(1) -
cvmx_pcie_get_io_base_address(0);
octeon_pcie1_controller.mem_resource->start =
cvmx_pcie_get_mem_base_address(1) + (4ul << 30) -
(OCTEON_PCI_BAR1_HOLE_SIZE << 20);
octeon_pcie1_controller.mem_resource->end =
cvmx_pcie_get_mem_base_address(1) +
cvmx_pcie_get_mem_size(1) - 1;
octeon_pcie1_controller.io_resource->start =
cvmx_pcie_get_io_base_address(1) -
cvmx_pcie_get_io_base_address(0);
octeon_pcie1_controller.io_resource->end =
octeon_pcie1_controller.io_resource->start +
cvmx_pcie_get_io_size(1) - 1;
register_pci_controller(&octeon_pcie1_controller);
}
octeon_pci_dma_init();
return 0;
}
