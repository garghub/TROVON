static uint32_t
csio_t4_read_pcie_cfg4(struct csio_hw *hw, int reg)
{
u32 val = 0;
struct csio_mb *mbp;
int rv;
struct fw_ldst_cmd *ldst_cmd;
mbp = mempool_alloc(hw->mb_mempool, GFP_ATOMIC);
if (!mbp) {
CSIO_INC_STATS(hw, n_err_nomem);
pci_read_config_dword(hw->pdev, reg, &val);
return val;
}
csio_mb_ldst(hw, mbp, CSIO_MB_DEFAULT_TMO, reg);
rv = csio_mb_issue(hw, mbp);
if (rv == 0) {
ldst_cmd = (struct fw_ldst_cmd *)(mbp->mb);
val = ntohl(ldst_cmd->u.pcie.data[0]);
} else
pci_read_config_dword(hw->pdev, reg, &val);
mempool_free(mbp, hw->mb_mempool);
return val;
}
static int
csio_t4_set_mem_win(struct csio_hw *hw, uint32_t win)
{
u32 bar0;
u32 mem_win_base;
bar0 = csio_t4_read_pcie_cfg4(hw, PCI_BASE_ADDRESS_0);
bar0 &= PCI_BASE_ADDRESS_MEM_MASK;
mem_win_base = bar0 + MEMWIN_BASE;
csio_wr_reg32(hw, mem_win_base | BIR(0) |
WINDOW(ilog2(MEMWIN_APERTURE) - 10),
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN, win));
csio_rd_reg32(hw,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN, win));
return 0;
}
static void
csio_t4_pcie_intr_handler(struct csio_hw *hw)
{
static struct intr_info sysbus_intr_info[] = {
{ RNPP, "RXNP array parity error", -1, 1 },
{ RPCP, "RXPC array parity error", -1, 1 },
{ RCIP, "RXCIF array parity error", -1, 1 },
{ RCCP, "Rx completions control array parity error", -1, 1 },
{ RFTP, "RXFT array parity error", -1, 1 },
{ 0, NULL, 0, 0 }
};
static struct intr_info pcie_port_intr_info[] = {
{ TPCP, "TXPC array parity error", -1, 1 },
{ TNPP, "TXNP array parity error", -1, 1 },
{ TFTP, "TXFT array parity error", -1, 1 },
{ TCAP, "TXCA array parity error", -1, 1 },
{ TCIP, "TXCIF array parity error", -1, 1 },
{ RCAP, "RXCA array parity error", -1, 1 },
{ OTDD, "outbound request TLP discarded", -1, 1 },
{ RDPE, "Rx data parity error", -1, 1 },
{ TDUE, "Tx uncorrectable data error", -1, 1 },
{ 0, NULL, 0, 0 }
};
static struct intr_info pcie_intr_info[] = {
{ MSIADDRLPERR, "MSI AddrL parity error", -1, 1 },
{ MSIADDRHPERR, "MSI AddrH parity error", -1, 1 },
{ MSIDATAPERR, "MSI data parity error", -1, 1 },
{ MSIXADDRLPERR, "MSI-X AddrL parity error", -1, 1 },
{ MSIXADDRHPERR, "MSI-X AddrH parity error", -1, 1 },
{ MSIXDATAPERR, "MSI-X data parity error", -1, 1 },
{ MSIXDIPERR, "MSI-X DI parity error", -1, 1 },
{ PIOCPLPERR, "PCI PIO completion FIFO parity error", -1, 1 },
{ PIOREQPERR, "PCI PIO request FIFO parity error", -1, 1 },
{ TARTAGPERR, "PCI PCI target tag FIFO parity error", -1, 1 },
{ CCNTPERR, "PCI CMD channel count parity error", -1, 1 },
{ CREQPERR, "PCI CMD channel request parity error", -1, 1 },
{ CRSPPERR, "PCI CMD channel response parity error", -1, 1 },
{ DCNTPERR, "PCI DMA channel count parity error", -1, 1 },
{ DREQPERR, "PCI DMA channel request parity error", -1, 1 },
{ DRSPPERR, "PCI DMA channel response parity error", -1, 1 },
{ HCNTPERR, "PCI HMA channel count parity error", -1, 1 },
{ HREQPERR, "PCI HMA channel request parity error", -1, 1 },
{ HRSPPERR, "PCI HMA channel response parity error", -1, 1 },
{ CFGSNPPERR, "PCI config snoop FIFO parity error", -1, 1 },
{ FIDPERR, "PCI FID parity error", -1, 1 },
{ INTXCLRPERR, "PCI INTx clear parity error", -1, 1 },
{ MATAGPERR, "PCI MA tag parity error", -1, 1 },
{ PIOTAGPERR, "PCI PIO tag parity error", -1, 1 },
{ RXCPLPERR, "PCI Rx completion parity error", -1, 1 },
{ RXWRPERR, "PCI Rx write parity error", -1, 1 },
{ RPLPERR, "PCI replay buffer parity error", -1, 1 },
{ PCIESINT, "PCI core secondary fault", -1, 1 },
{ PCIEPINT, "PCI core primary fault", -1, 1 },
{ UNXSPLCPLERR, "PCI unexpected split completion error", -1,
0 },
{ 0, NULL, 0, 0 }
};
int fat;
fat = csio_handle_intr_status(hw,
PCIE_CORE_UTL_SYSTEM_BUS_AGENT_STATUS,
sysbus_intr_info) +
csio_handle_intr_status(hw,
PCIE_CORE_UTL_PCI_EXPRESS_PORT_STATUS,
pcie_port_intr_info) +
csio_handle_intr_status(hw, PCIE_INT_CAUSE, pcie_intr_info);
if (fat)
csio_hw_fatal_err(hw);
}
static unsigned int
csio_t4_flash_cfg_addr(struct csio_hw *hw)
{
return FLASH_CFG_OFFSET;
}
static int
csio_t4_mc_read(struct csio_hw *hw, int idx, uint32_t addr, __be32 *data,
uint64_t *ecc)
{
int i;
if (csio_rd_reg32(hw, MC_BIST_CMD) & START_BIST)
return -EBUSY;
csio_wr_reg32(hw, addr & ~0x3fU, MC_BIST_CMD_ADDR);
csio_wr_reg32(hw, 64, MC_BIST_CMD_LEN);
csio_wr_reg32(hw, 0xc, MC_BIST_DATA_PATTERN);
csio_wr_reg32(hw, BIST_OPCODE(1) | START_BIST | BIST_CMD_GAP(1),
MC_BIST_CMD);
i = csio_hw_wait_op_done_val(hw, MC_BIST_CMD, START_BIST,
0, 10, 1, NULL);
if (i)
return i;
#define MC_DATA(i) MC_BIST_STATUS_REG(MC_BIST_STATUS_RDATA, i)
for (i = 15; i >= 0; i--)
*data++ = htonl(csio_rd_reg32(hw, MC_DATA(i)));
if (ecc)
*ecc = csio_rd_reg64(hw, MC_DATA(16));
#undef MC_DATA
return 0;
}
static int
csio_t4_edc_read(struct csio_hw *hw, int idx, uint32_t addr, __be32 *data,
uint64_t *ecc)
{
int i;
idx *= EDC_STRIDE;
if (csio_rd_reg32(hw, EDC_BIST_CMD + idx) & START_BIST)
return -EBUSY;
csio_wr_reg32(hw, addr & ~0x3fU, EDC_BIST_CMD_ADDR + idx);
csio_wr_reg32(hw, 64, EDC_BIST_CMD_LEN + idx);
csio_wr_reg32(hw, 0xc, EDC_BIST_DATA_PATTERN + idx);
csio_wr_reg32(hw, BIST_OPCODE(1) | BIST_CMD_GAP(1) | START_BIST,
EDC_BIST_CMD + idx);
i = csio_hw_wait_op_done_val(hw, EDC_BIST_CMD + idx, START_BIST,
0, 10, 1, NULL);
if (i)
return i;
#define EDC_DATA(i) (EDC_BIST_STATUS_REG(EDC_BIST_STATUS_RDATA, i) + idx)
for (i = 15; i >= 0; i--)
*data++ = htonl(csio_rd_reg32(hw, EDC_DATA(i)));
if (ecc)
*ecc = csio_rd_reg64(hw, EDC_DATA(16));
#undef EDC_DATA
return 0;
}
static int
csio_t4_memory_rw(struct csio_hw *hw, u32 win, int mtype, u32 addr,
u32 len, uint32_t *buf, int dir)
{
u32 pos, start, offset, memoffset, bar0;
u32 edc_size, mc_size, mem_reg, mem_aperture, mem_base;
if ((addr & 0x3) || (len & 0x3))
return -EINVAL;
edc_size = EDRAM0_SIZE_G(csio_rd_reg32(hw, MA_EDRAM0_BAR_A));
if (mtype != MEM_MC1)
memoffset = (mtype * (edc_size * 1024 * 1024));
else {
mc_size = EXT_MEM_SIZE_G(csio_rd_reg32(hw,
MA_EXT_MEMORY_BAR_A));
memoffset = (MEM_MC0 * edc_size + mc_size) * 1024 * 1024;
}
addr = addr + memoffset;
mem_reg = csio_rd_reg32(hw,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_BASE_WIN, win));
mem_aperture = 1 << (WINDOW(mem_reg) + 10);
mem_base = GET_PCIEOFST(mem_reg) << 10;
bar0 = csio_t4_read_pcie_cfg4(hw, PCI_BASE_ADDRESS_0);
bar0 &= PCI_BASE_ADDRESS_MEM_MASK;
mem_base -= bar0;
start = addr & ~(mem_aperture-1);
offset = addr - start;
csio_dbg(hw, "csio_t4_memory_rw: mem_reg: 0x%x, mem_aperture: 0x%x\n",
mem_reg, mem_aperture);
csio_dbg(hw, "csio_t4_memory_rw: mem_base: 0x%x, mem_offset: 0x%x\n",
mem_base, memoffset);
csio_dbg(hw, "csio_t4_memory_rw: bar0: 0x%x, start:0x%x, offset:0x%x\n",
bar0, start, offset);
csio_dbg(hw, "csio_t4_memory_rw: mtype: %d, addr: 0x%x, len: %d\n",
mtype, addr, len);
for (pos = start; len > 0; pos += mem_aperture, offset = 0) {
csio_wr_reg32(hw, pos,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_OFFSET, win));
csio_rd_reg32(hw,
PCIE_MEM_ACCESS_REG(PCIE_MEM_ACCESS_OFFSET, win));
while (offset < mem_aperture && len > 0) {
if (dir)
*buf++ = csio_rd_reg32(hw, mem_base + offset);
else
csio_wr_reg32(hw, *buf++, mem_base + offset);
offset += sizeof(__be32);
len -= sizeof(__be32);
}
}
return 0;
}
static void
csio_t4_dfs_create_ext_mem(struct csio_hw *hw)
{
u32 size;
int i = csio_rd_reg32(hw, MA_TARGET_MEM_ENABLE_A);
if (i & EXT_MEM_ENABLE_F) {
size = csio_rd_reg32(hw, MA_EXT_MEMORY_BAR_A);
csio_add_debugfs_mem(hw, "mc", MEM_MC,
EXT_MEM_SIZE_G(size));
}
}
