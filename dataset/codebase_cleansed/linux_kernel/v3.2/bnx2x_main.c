static inline void __storm_memset_dma_mapping(struct bnx2x *bp,
u32 addr, dma_addr_t mapping)
{
REG_WR(bp, addr, U64_LO(mapping));
REG_WR(bp, addr + 4, U64_HI(mapping));
}
static inline void storm_memset_spq_addr(struct bnx2x *bp,
dma_addr_t mapping, u16 abs_fid)
{
u32 addr = XSEM_REG_FAST_MEMORY +
XSTORM_SPQ_PAGE_BASE_OFFSET(abs_fid);
__storm_memset_dma_mapping(bp, addr, mapping);
}
static inline void storm_memset_vf_to_pf(struct bnx2x *bp, u16 abs_fid,
u16 pf_id)
{
REG_WR8(bp, BAR_XSTRORM_INTMEM + XSTORM_VF_TO_PF_OFFSET(abs_fid),
pf_id);
REG_WR8(bp, BAR_CSTRORM_INTMEM + CSTORM_VF_TO_PF_OFFSET(abs_fid),
pf_id);
REG_WR8(bp, BAR_TSTRORM_INTMEM + TSTORM_VF_TO_PF_OFFSET(abs_fid),
pf_id);
REG_WR8(bp, BAR_USTRORM_INTMEM + USTORM_VF_TO_PF_OFFSET(abs_fid),
pf_id);
}
static inline void storm_memset_func_en(struct bnx2x *bp, u16 abs_fid,
u8 enable)
{
REG_WR8(bp, BAR_XSTRORM_INTMEM + XSTORM_FUNC_EN_OFFSET(abs_fid),
enable);
REG_WR8(bp, BAR_CSTRORM_INTMEM + CSTORM_FUNC_EN_OFFSET(abs_fid),
enable);
REG_WR8(bp, BAR_TSTRORM_INTMEM + TSTORM_FUNC_EN_OFFSET(abs_fid),
enable);
REG_WR8(bp, BAR_USTRORM_INTMEM + USTORM_FUNC_EN_OFFSET(abs_fid),
enable);
}
static inline void storm_memset_eq_data(struct bnx2x *bp,
struct event_ring_data *eq_data,
u16 pfid)
{
size_t size = sizeof(struct event_ring_data);
u32 addr = BAR_CSTRORM_INTMEM + CSTORM_EVENT_RING_DATA_OFFSET(pfid);
__storm_memset_struct(bp, addr, size, (u32 *)eq_data);
}
static inline void storm_memset_eq_prod(struct bnx2x *bp, u16 eq_prod,
u16 pfid)
{
u32 addr = BAR_CSTRORM_INTMEM + CSTORM_EVENT_RING_PROD_OFFSET(pfid);
REG_WR16(bp, addr, eq_prod);
}
static void bnx2x_reg_wr_ind(struct bnx2x *bp, u32 addr, u32 val)
{
pci_write_config_dword(bp->pdev, PCICFG_GRC_ADDRESS, addr);
pci_write_config_dword(bp->pdev, PCICFG_GRC_DATA, val);
pci_write_config_dword(bp->pdev, PCICFG_GRC_ADDRESS,
PCICFG_VENDOR_ID_OFFSET);
}
static u32 bnx2x_reg_rd_ind(struct bnx2x *bp, u32 addr)
{
u32 val;
pci_write_config_dword(bp->pdev, PCICFG_GRC_ADDRESS, addr);
pci_read_config_dword(bp->pdev, PCICFG_GRC_DATA, &val);
pci_write_config_dword(bp->pdev, PCICFG_GRC_ADDRESS,
PCICFG_VENDOR_ID_OFFSET);
return val;
}
static void bnx2x_dp_dmae(struct bnx2x *bp, struct dmae_command *dmae,
int msglvl)
{
u32 src_type = dmae->opcode & DMAE_COMMAND_SRC;
switch (dmae->opcode & DMAE_COMMAND_DST) {
case DMAE_CMD_DST_PCI:
if (src_type == DMAE_CMD_SRC_PCI)
DP(msglvl, "DMAE: opcode 0x%08x\n"
"src [%x:%08x], len [%d*4], dst [%x:%08x]\n"
"comp_addr [%x:%08x], comp_val 0x%08x\n",
dmae->opcode, dmae->src_addr_hi, dmae->src_addr_lo,
dmae->len, dmae->dst_addr_hi, dmae->dst_addr_lo,
dmae->comp_addr_hi, dmae->comp_addr_lo,
dmae->comp_val);
else
DP(msglvl, "DMAE: opcode 0x%08x\n"
"src [%08x], len [%d*4], dst [%x:%08x]\n"
"comp_addr [%x:%08x], comp_val 0x%08x\n",
dmae->opcode, dmae->src_addr_lo >> 2,
dmae->len, dmae->dst_addr_hi, dmae->dst_addr_lo,
dmae->comp_addr_hi, dmae->comp_addr_lo,
dmae->comp_val);
break;
case DMAE_CMD_DST_GRC:
if (src_type == DMAE_CMD_SRC_PCI)
DP(msglvl, "DMAE: opcode 0x%08x\n"
"src [%x:%08x], len [%d*4], dst_addr [%08x]\n"
"comp_addr [%x:%08x], comp_val 0x%08x\n",
dmae->opcode, dmae->src_addr_hi, dmae->src_addr_lo,
dmae->len, dmae->dst_addr_lo >> 2,
dmae->comp_addr_hi, dmae->comp_addr_lo,
dmae->comp_val);
else
DP(msglvl, "DMAE: opcode 0x%08x\n"
"src [%08x], len [%d*4], dst [%08x]\n"
"comp_addr [%x:%08x], comp_val 0x%08x\n",
dmae->opcode, dmae->src_addr_lo >> 2,
dmae->len, dmae->dst_addr_lo >> 2,
dmae->comp_addr_hi, dmae->comp_addr_lo,
dmae->comp_val);
break;
default:
if (src_type == DMAE_CMD_SRC_PCI)
DP(msglvl, "DMAE: opcode 0x%08x\n"
"src_addr [%x:%08x] len [%d * 4] dst_addr [none]\n"
"comp_addr [%x:%08x] comp_val 0x%08x\n",
dmae->opcode, dmae->src_addr_hi, dmae->src_addr_lo,
dmae->len, dmae->comp_addr_hi, dmae->comp_addr_lo,
dmae->comp_val);
else
DP(msglvl, "DMAE: opcode 0x%08x\n"
"src_addr [%08x] len [%d * 4] dst_addr [none]\n"
"comp_addr [%x:%08x] comp_val 0x%08x\n",
dmae->opcode, dmae->src_addr_lo >> 2,
dmae->len, dmae->comp_addr_hi, dmae->comp_addr_lo,
dmae->comp_val);
break;
}
}
void bnx2x_post_dmae(struct bnx2x *bp, struct dmae_command *dmae, int idx)
{
u32 cmd_offset;
int i;
cmd_offset = (DMAE_REG_CMD_MEM + sizeof(struct dmae_command) * idx);
for (i = 0; i < (sizeof(struct dmae_command)/4); i++) {
REG_WR(bp, cmd_offset + i*4, *(((u32 *)dmae) + i));
DP(BNX2X_MSG_OFF, "DMAE cmd[%d].%d (0x%08x) : 0x%08x\n",
idx, i, cmd_offset + i*4, *(((u32 *)dmae) + i));
}
REG_WR(bp, dmae_reg_go_c[idx], 1);
}
u32 bnx2x_dmae_opcode_add_comp(u32 opcode, u8 comp_type)
{
return opcode | ((comp_type << DMAE_COMMAND_C_DST_SHIFT) |
DMAE_CMD_C_ENABLE);
}
u32 bnx2x_dmae_opcode_clr_src_reset(u32 opcode)
{
return opcode & ~DMAE_CMD_SRC_RESET;
}
u32 bnx2x_dmae_opcode(struct bnx2x *bp, u8 src_type, u8 dst_type,
bool with_comp, u8 comp_type)
{
u32 opcode = 0;
opcode |= ((src_type << DMAE_COMMAND_SRC_SHIFT) |
(dst_type << DMAE_COMMAND_DST_SHIFT));
opcode |= (DMAE_CMD_SRC_RESET | DMAE_CMD_DST_RESET);
opcode |= (BP_PORT(bp) ? DMAE_CMD_PORT_1 : DMAE_CMD_PORT_0);
opcode |= ((BP_VN(bp) << DMAE_CMD_E1HVN_SHIFT) |
(BP_VN(bp) << DMAE_COMMAND_DST_VN_SHIFT));
opcode |= (DMAE_COM_SET_ERR << DMAE_COMMAND_ERR_POLICY_SHIFT);
#ifdef __BIG_ENDIAN
opcode |= DMAE_CMD_ENDIANITY_B_DW_SWAP;
#else
opcode |= DMAE_CMD_ENDIANITY_DW_SWAP;
#endif
if (with_comp)
opcode = bnx2x_dmae_opcode_add_comp(opcode, comp_type);
return opcode;
}
static void bnx2x_prep_dmae_with_comp(struct bnx2x *bp,
struct dmae_command *dmae,
u8 src_type, u8 dst_type)
{
memset(dmae, 0, sizeof(struct dmae_command));
dmae->opcode = bnx2x_dmae_opcode(bp, src_type, dst_type,
true, DMAE_COMP_PCI);
dmae->comp_addr_lo = U64_LO(bnx2x_sp_mapping(bp, wb_comp));
dmae->comp_addr_hi = U64_HI(bnx2x_sp_mapping(bp, wb_comp));
dmae->comp_val = DMAE_COMP_VAL;
}
static int bnx2x_issue_dmae_with_comp(struct bnx2x *bp,
struct dmae_command *dmae)
{
u32 *wb_comp = bnx2x_sp(bp, wb_comp);
int cnt = CHIP_REV_IS_SLOW(bp) ? (400000) : 4000;
int rc = 0;
DP(BNX2X_MSG_OFF, "data before [0x%08x 0x%08x 0x%08x 0x%08x]\n",
bp->slowpath->wb_data[0], bp->slowpath->wb_data[1],
bp->slowpath->wb_data[2], bp->slowpath->wb_data[3]);
spin_lock_bh(&bp->dmae_lock);
*wb_comp = 0;
bnx2x_post_dmae(bp, dmae, INIT_DMAE_C(bp));
udelay(5);
while ((*wb_comp & ~DMAE_PCI_ERR_FLAG) != DMAE_COMP_VAL) {
DP(BNX2X_MSG_OFF, "wb_comp 0x%08x\n", *wb_comp);
if (!cnt) {
BNX2X_ERR("DMAE timeout!\n");
rc = DMAE_TIMEOUT;
goto unlock;
}
cnt--;
udelay(50);
}
if (*wb_comp & DMAE_PCI_ERR_FLAG) {
BNX2X_ERR("DMAE PCI error!\n");
rc = DMAE_PCI_ERROR;
}
DP(BNX2X_MSG_OFF, "data after [0x%08x 0x%08x 0x%08x 0x%08x]\n",
bp->slowpath->wb_data[0], bp->slowpath->wb_data[1],
bp->slowpath->wb_data[2], bp->slowpath->wb_data[3]);
unlock:
spin_unlock_bh(&bp->dmae_lock);
return rc;
}
void bnx2x_write_dmae(struct bnx2x *bp, dma_addr_t dma_addr, u32 dst_addr,
u32 len32)
{
struct dmae_command dmae;
if (!bp->dmae_ready) {
u32 *data = bnx2x_sp(bp, wb_data[0]);
DP(BNX2X_MSG_OFF, "DMAE is not ready (dst_addr %08x len32 %d)"
" using indirect\n", dst_addr, len32);
bnx2x_init_ind_wr(bp, dst_addr, data, len32);
return;
}
bnx2x_prep_dmae_with_comp(bp, &dmae, DMAE_SRC_PCI, DMAE_DST_GRC);
dmae.src_addr_lo = U64_LO(dma_addr);
dmae.src_addr_hi = U64_HI(dma_addr);
dmae.dst_addr_lo = dst_addr >> 2;
dmae.dst_addr_hi = 0;
dmae.len = len32;
bnx2x_dp_dmae(bp, &dmae, BNX2X_MSG_OFF);
bnx2x_issue_dmae_with_comp(bp, &dmae);
}
void bnx2x_read_dmae(struct bnx2x *bp, u32 src_addr, u32 len32)
{
struct dmae_command dmae;
if (!bp->dmae_ready) {
u32 *data = bnx2x_sp(bp, wb_data[0]);
int i;
DP(BNX2X_MSG_OFF, "DMAE is not ready (src_addr %08x len32 %d)"
" using indirect\n", src_addr, len32);
for (i = 0; i < len32; i++)
data[i] = bnx2x_reg_rd_ind(bp, src_addr + i*4);
return;
}
bnx2x_prep_dmae_with_comp(bp, &dmae, DMAE_SRC_GRC, DMAE_DST_PCI);
dmae.src_addr_lo = src_addr >> 2;
dmae.src_addr_hi = 0;
dmae.dst_addr_lo = U64_LO(bnx2x_sp_mapping(bp, wb_data));
dmae.dst_addr_hi = U64_HI(bnx2x_sp_mapping(bp, wb_data));
dmae.len = len32;
bnx2x_dp_dmae(bp, &dmae, BNX2X_MSG_OFF);
bnx2x_issue_dmae_with_comp(bp, &dmae);
}
static void bnx2x_write_dmae_phys_len(struct bnx2x *bp, dma_addr_t phys_addr,
u32 addr, u32 len)
{
int dmae_wr_max = DMAE_LEN32_WR_MAX(bp);
int offset = 0;
while (len > dmae_wr_max) {
bnx2x_write_dmae(bp, phys_addr + offset,
addr + offset, dmae_wr_max);
offset += dmae_wr_max * 4;
len -= dmae_wr_max;
}
bnx2x_write_dmae(bp, phys_addr + offset, addr + offset, len);
}
static void bnx2x_wb_wr(struct bnx2x *bp, int reg, u32 val_hi, u32 val_lo)
{
u32 wb_write[2];
wb_write[0] = val_hi;
wb_write[1] = val_lo;
REG_WR_DMAE(bp, reg, wb_write, 2);
}
static u64 bnx2x_wb_rd(struct bnx2x *bp, int reg)
{
u32 wb_data[2];
REG_RD_DMAE(bp, reg, wb_data, 2);
return HILO_U64(wb_data[0], wb_data[1]);
}
static int bnx2x_mc_assert(struct bnx2x *bp)
{
char last_idx;
int i, rc = 0;
u32 row0, row1, row2, row3;
last_idx = REG_RD8(bp, BAR_XSTRORM_INTMEM +
XSTORM_ASSERT_LIST_INDEX_OFFSET);
if (last_idx)
BNX2X_ERR("XSTORM_ASSERT_LIST_INDEX 0x%x\n", last_idx);
for (i = 0; i < STROM_ASSERT_ARRAY_SIZE; i++) {
row0 = REG_RD(bp, BAR_XSTRORM_INTMEM +
XSTORM_ASSERT_LIST_OFFSET(i));
row1 = REG_RD(bp, BAR_XSTRORM_INTMEM +
XSTORM_ASSERT_LIST_OFFSET(i) + 4);
row2 = REG_RD(bp, BAR_XSTRORM_INTMEM +
XSTORM_ASSERT_LIST_OFFSET(i) + 8);
row3 = REG_RD(bp, BAR_XSTRORM_INTMEM +
XSTORM_ASSERT_LIST_OFFSET(i) + 12);
if (row0 != COMMON_ASM_INVALID_ASSERT_OPCODE) {
BNX2X_ERR("XSTORM_ASSERT_INDEX 0x%x = 0x%08x"
" 0x%08x 0x%08x 0x%08x\n",
i, row3, row2, row1, row0);
rc++;
} else {
break;
}
}
last_idx = REG_RD8(bp, BAR_TSTRORM_INTMEM +
TSTORM_ASSERT_LIST_INDEX_OFFSET);
if (last_idx)
BNX2X_ERR("TSTORM_ASSERT_LIST_INDEX 0x%x\n", last_idx);
for (i = 0; i < STROM_ASSERT_ARRAY_SIZE; i++) {
row0 = REG_RD(bp, BAR_TSTRORM_INTMEM +
TSTORM_ASSERT_LIST_OFFSET(i));
row1 = REG_RD(bp, BAR_TSTRORM_INTMEM +
TSTORM_ASSERT_LIST_OFFSET(i) + 4);
row2 = REG_RD(bp, BAR_TSTRORM_INTMEM +
TSTORM_ASSERT_LIST_OFFSET(i) + 8);
row3 = REG_RD(bp, BAR_TSTRORM_INTMEM +
TSTORM_ASSERT_LIST_OFFSET(i) + 12);
if (row0 != COMMON_ASM_INVALID_ASSERT_OPCODE) {
BNX2X_ERR("TSTORM_ASSERT_INDEX 0x%x = 0x%08x"
" 0x%08x 0x%08x 0x%08x\n",
i, row3, row2, row1, row0);
rc++;
} else {
break;
}
}
last_idx = REG_RD8(bp, BAR_CSTRORM_INTMEM +
CSTORM_ASSERT_LIST_INDEX_OFFSET);
if (last_idx)
BNX2X_ERR("CSTORM_ASSERT_LIST_INDEX 0x%x\n", last_idx);
for (i = 0; i < STROM_ASSERT_ARRAY_SIZE; i++) {
row0 = REG_RD(bp, BAR_CSTRORM_INTMEM +
CSTORM_ASSERT_LIST_OFFSET(i));
row1 = REG_RD(bp, BAR_CSTRORM_INTMEM +
CSTORM_ASSERT_LIST_OFFSET(i) + 4);
row2 = REG_RD(bp, BAR_CSTRORM_INTMEM +
CSTORM_ASSERT_LIST_OFFSET(i) + 8);
row3 = REG_RD(bp, BAR_CSTRORM_INTMEM +
CSTORM_ASSERT_LIST_OFFSET(i) + 12);
if (row0 != COMMON_ASM_INVALID_ASSERT_OPCODE) {
BNX2X_ERR("CSTORM_ASSERT_INDEX 0x%x = 0x%08x"
" 0x%08x 0x%08x 0x%08x\n",
i, row3, row2, row1, row0);
rc++;
} else {
break;
}
}
last_idx = REG_RD8(bp, BAR_USTRORM_INTMEM +
USTORM_ASSERT_LIST_INDEX_OFFSET);
if (last_idx)
BNX2X_ERR("USTORM_ASSERT_LIST_INDEX 0x%x\n", last_idx);
for (i = 0; i < STROM_ASSERT_ARRAY_SIZE; i++) {
row0 = REG_RD(bp, BAR_USTRORM_INTMEM +
USTORM_ASSERT_LIST_OFFSET(i));
row1 = REG_RD(bp, BAR_USTRORM_INTMEM +
USTORM_ASSERT_LIST_OFFSET(i) + 4);
row2 = REG_RD(bp, BAR_USTRORM_INTMEM +
USTORM_ASSERT_LIST_OFFSET(i) + 8);
row3 = REG_RD(bp, BAR_USTRORM_INTMEM +
USTORM_ASSERT_LIST_OFFSET(i) + 12);
if (row0 != COMMON_ASM_INVALID_ASSERT_OPCODE) {
BNX2X_ERR("USTORM_ASSERT_INDEX 0x%x = 0x%08x"
" 0x%08x 0x%08x 0x%08x\n",
i, row3, row2, row1, row0);
rc++;
} else {
break;
}
}
return rc;
}
void bnx2x_fw_dump_lvl(struct bnx2x *bp, const char *lvl)
{
u32 addr, val;
u32 mark, offset;
__be32 data[9];
int word;
u32 trace_shmem_base;
if (BP_NOMCP(bp)) {
BNX2X_ERR("NO MCP - can not dump\n");
return;
}
netdev_printk(lvl, bp->dev, "bc %d.%d.%d\n",
(bp->common.bc_ver & 0xff0000) >> 16,
(bp->common.bc_ver & 0xff00) >> 8,
(bp->common.bc_ver & 0xff));
val = REG_RD(bp, MCP_REG_MCPR_CPU_PROGRAM_COUNTER);
if (val == REG_RD(bp, MCP_REG_MCPR_CPU_PROGRAM_COUNTER))
printk("%s" "MCP PC at 0x%x\n", lvl, val);
if (BP_PATH(bp) == 0)
trace_shmem_base = bp->common.shmem_base;
else
trace_shmem_base = SHMEM2_RD(bp, other_shmem_base_addr);
addr = trace_shmem_base - 0x0800 + 4;
mark = REG_RD(bp, addr);
mark = (CHIP_IS_E1x(bp) ? MCP_REG_MCPR_SCRATCH : MCP_A_REG_MCPR_SCRATCH)
+ ((mark + 0x3) & ~0x3) - 0x08000000;
printk("%s" "begin fw dump (mark 0x%x)\n", lvl, mark);
printk("%s", lvl);
for (offset = mark; offset <= trace_shmem_base; offset += 0x8*4) {
for (word = 0; word < 8; word++)
data[word] = htonl(REG_RD(bp, offset + 4*word));
data[8] = 0x0;
pr_cont("%s", (char *)data);
}
for (offset = addr + 4; offset <= mark; offset += 0x8*4) {
for (word = 0; word < 8; word++)
data[word] = htonl(REG_RD(bp, offset + 4*word));
data[8] = 0x0;
pr_cont("%s", (char *)data);
}
printk("%s" "end of fw dump\n", lvl);
}
static inline void bnx2x_fw_dump(struct bnx2x *bp)
{
bnx2x_fw_dump_lvl(bp, KERN_ERR);
}
void bnx2x_panic_dump(struct bnx2x *bp)
{
int i;
u16 j;
struct hc_sp_status_block_data sp_sb_data;
int func = BP_FUNC(bp);
#ifdef BNX2X_STOP_ON_ERROR
u16 start = 0, end = 0;
u8 cos;
#endif
bp->stats_state = STATS_STATE_DISABLED;
DP(BNX2X_MSG_STATS, "stats_state - DISABLED\n");
BNX2X_ERR("begin crash dump -----------------\n");
BNX2X_ERR("def_idx(0x%x) def_att_idx(0x%x) attn_state(0x%x)"
" spq_prod_idx(0x%x) next_stats_cnt(0x%x)\n",
bp->def_idx, bp->def_att_idx, bp->attn_state,
bp->spq_prod_idx, bp->stats_counter);
BNX2X_ERR("DSB: attn bits(0x%x) ack(0x%x) id(0x%x) idx(0x%x)\n",
bp->def_status_blk->atten_status_block.attn_bits,
bp->def_status_blk->atten_status_block.attn_bits_ack,
bp->def_status_blk->atten_status_block.status_block_id,
bp->def_status_blk->atten_status_block.attn_bits_index);
BNX2X_ERR(" def (");
for (i = 0; i < HC_SP_SB_MAX_INDICES; i++)
pr_cont("0x%x%s",
bp->def_status_blk->sp_sb.index_values[i],
(i == HC_SP_SB_MAX_INDICES - 1) ? ") " : " ");
for (i = 0; i < sizeof(struct hc_sp_status_block_data)/sizeof(u32); i++)
*((u32 *)&sp_sb_data + i) = REG_RD(bp, BAR_CSTRORM_INTMEM +
CSTORM_SP_STATUS_BLOCK_DATA_OFFSET(func) +
i*sizeof(u32));
pr_cont("igu_sb_id(0x%x) igu_seg_id(0x%x) pf_id(0x%x) vnic_id(0x%x) vf_id(0x%x) vf_valid (0x%x) state(0x%x)\n",
sp_sb_data.igu_sb_id,
sp_sb_data.igu_seg_id,
sp_sb_data.p_func.pf_id,
sp_sb_data.p_func.vnic_id,
sp_sb_data.p_func.vf_id,
sp_sb_data.p_func.vf_valid,
sp_sb_data.state);
for_each_eth_queue(bp, i) {
struct bnx2x_fastpath *fp = &bp->fp[i];
int loop;
struct hc_status_block_data_e2 sb_data_e2;
struct hc_status_block_data_e1x sb_data_e1x;
struct hc_status_block_sm *hc_sm_p =
CHIP_IS_E1x(bp) ?
sb_data_e1x.common.state_machine :
sb_data_e2.common.state_machine;
struct hc_index_data *hc_index_p =
CHIP_IS_E1x(bp) ?
sb_data_e1x.index_data :
sb_data_e2.index_data;
u8 data_size, cos;
u32 *sb_data_p;
struct bnx2x_fp_txdata txdata;
BNX2X_ERR("fp%d: rx_bd_prod(0x%x) rx_bd_cons(0x%x)"
" rx_comp_prod(0x%x)"
" rx_comp_cons(0x%x) *rx_cons_sb(0x%x)\n",
i, fp->rx_bd_prod, fp->rx_bd_cons,
fp->rx_comp_prod,
fp->rx_comp_cons, le16_to_cpu(*fp->rx_cons_sb));
BNX2X_ERR(" rx_sge_prod(0x%x) last_max_sge(0x%x)"
" fp_hc_idx(0x%x)\n",
fp->rx_sge_prod, fp->last_max_sge,
le16_to_cpu(fp->fp_hc_idx));
for_each_cos_in_tx_queue(fp, cos)
{
txdata = fp->txdata[cos];
BNX2X_ERR("fp%d: tx_pkt_prod(0x%x) tx_pkt_cons(0x%x)"
" tx_bd_prod(0x%x) tx_bd_cons(0x%x)"
" *tx_cons_sb(0x%x)\n",
i, txdata.tx_pkt_prod,
txdata.tx_pkt_cons, txdata.tx_bd_prod,
txdata.tx_bd_cons,
le16_to_cpu(*txdata.tx_cons_sb));
}
loop = CHIP_IS_E1x(bp) ?
HC_SB_MAX_INDICES_E1X : HC_SB_MAX_INDICES_E2;
#ifdef BCM_CNIC
if (IS_FCOE_FP(fp))
continue;
#endif
BNX2X_ERR(" run indexes (");
for (j = 0; j < HC_SB_MAX_SM; j++)
pr_cont("0x%x%s",
fp->sb_running_index[j],
(j == HC_SB_MAX_SM - 1) ? ")" : " ");
BNX2X_ERR(" indexes (");
for (j = 0; j < loop; j++)
pr_cont("0x%x%s",
fp->sb_index_values[j],
(j == loop - 1) ? ")" : " ");
data_size = CHIP_IS_E1x(bp) ?
sizeof(struct hc_status_block_data_e1x) :
sizeof(struct hc_status_block_data_e2);
data_size /= sizeof(u32);
sb_data_p = CHIP_IS_E1x(bp) ?
(u32 *)&sb_data_e1x :
(u32 *)&sb_data_e2;
for (j = 0; j < data_size; j++)
*(sb_data_p + j) = REG_RD(bp, BAR_CSTRORM_INTMEM +
CSTORM_STATUS_BLOCK_DATA_OFFSET(fp->fw_sb_id) +
j * sizeof(u32));
if (!CHIP_IS_E1x(bp)) {
pr_cont("pf_id(0x%x) vf_id(0x%x) vf_valid(0x%x) "
"vnic_id(0x%x) same_igu_sb_1b(0x%x) "
"state(0x%x)\n",
sb_data_e2.common.p_func.pf_id,
sb_data_e2.common.p_func.vf_id,
sb_data_e2.common.p_func.vf_valid,
sb_data_e2.common.p_func.vnic_id,
sb_data_e2.common.same_igu_sb_1b,
sb_data_e2.common.state);
} else {
pr_cont("pf_id(0x%x) vf_id(0x%x) vf_valid(0x%x) "
"vnic_id(0x%x) same_igu_sb_1b(0x%x) "
"state(0x%x)\n",
sb_data_e1x.common.p_func.pf_id,
sb_data_e1x.common.p_func.vf_id,
sb_data_e1x.common.p_func.vf_valid,
sb_data_e1x.common.p_func.vnic_id,
sb_data_e1x.common.same_igu_sb_1b,
sb_data_e1x.common.state);
}
for (j = 0; j < HC_SB_MAX_SM; j++) {
pr_cont("SM[%d] __flags (0x%x) "
"igu_sb_id (0x%x) igu_seg_id(0x%x) "
"time_to_expire (0x%x) "
"timer_value(0x%x)\n", j,
hc_sm_p[j].__flags,
hc_sm_p[j].igu_sb_id,
hc_sm_p[j].igu_seg_id,
hc_sm_p[j].time_to_expire,
hc_sm_p[j].timer_value);
}
for (j = 0; j < loop; j++) {
pr_cont("INDEX[%d] flags (0x%x) "
"timeout (0x%x)\n", j,
hc_index_p[j].flags,
hc_index_p[j].timeout);
}
}
#ifdef BNX2X_STOP_ON_ERROR
for_each_rx_queue(bp, i) {
struct bnx2x_fastpath *fp = &bp->fp[i];
start = RX_BD(le16_to_cpu(*fp->rx_cons_sb) - 10);
end = RX_BD(le16_to_cpu(*fp->rx_cons_sb) + 503);
for (j = start; j != end; j = RX_BD(j + 1)) {
u32 *rx_bd = (u32 *)&fp->rx_desc_ring[j];
struct sw_rx_bd *sw_bd = &fp->rx_buf_ring[j];
BNX2X_ERR("fp%d: rx_bd[%x]=[%x:%x] sw_bd=[%p]\n",
i, j, rx_bd[1], rx_bd[0], sw_bd->skb);
}
start = RX_SGE(fp->rx_sge_prod);
end = RX_SGE(fp->last_max_sge);
for (j = start; j != end; j = RX_SGE(j + 1)) {
u32 *rx_sge = (u32 *)&fp->rx_sge_ring[j];
struct sw_rx_page *sw_page = &fp->rx_page_ring[j];
BNX2X_ERR("fp%d: rx_sge[%x]=[%x:%x] sw_page=[%p]\n",
i, j, rx_sge[1], rx_sge[0], sw_page->page);
}
start = RCQ_BD(fp->rx_comp_cons - 10);
end = RCQ_BD(fp->rx_comp_cons + 503);
for (j = start; j != end; j = RCQ_BD(j + 1)) {
u32 *cqe = (u32 *)&fp->rx_comp_ring[j];
BNX2X_ERR("fp%d: cqe[%x]=[%x:%x:%x:%x]\n",
i, j, cqe[0], cqe[1], cqe[2], cqe[3]);
}
}
for_each_tx_queue(bp, i) {
struct bnx2x_fastpath *fp = &bp->fp[i];
for_each_cos_in_tx_queue(fp, cos) {
struct bnx2x_fp_txdata *txdata = &fp->txdata[cos];
start = TX_BD(le16_to_cpu(*txdata->tx_cons_sb) - 10);
end = TX_BD(le16_to_cpu(*txdata->tx_cons_sb) + 245);
for (j = start; j != end; j = TX_BD(j + 1)) {
struct sw_tx_bd *sw_bd =
&txdata->tx_buf_ring[j];
BNX2X_ERR("fp%d: txdata %d, "
"packet[%x]=[%p,%x]\n",
i, cos, j, sw_bd->skb,
sw_bd->first_bd);
}
start = TX_BD(txdata->tx_bd_cons - 10);
end = TX_BD(txdata->tx_bd_cons + 254);
for (j = start; j != end; j = TX_BD(j + 1)) {
u32 *tx_bd = (u32 *)&txdata->tx_desc_ring[j];
BNX2X_ERR("fp%d: txdata %d, tx_bd[%x]="
"[%x:%x:%x:%x]\n",
i, cos, j, tx_bd[0], tx_bd[1],
tx_bd[2], tx_bd[3]);
}
}
}
#endif
bnx2x_fw_dump(bp);
bnx2x_mc_assert(bp);
BNX2X_ERR("end crash dump -----------------\n");
}
static void bnx2x_pbf_pN_buf_flushed(struct bnx2x *bp,
struct pbf_pN_buf_regs *regs,
u32 poll_count)
{
u32 init_crd, crd, crd_start, crd_freed, crd_freed_start;
u32 cur_cnt = poll_count;
crd_freed = crd_freed_start = REG_RD(bp, regs->crd_freed);
crd = crd_start = REG_RD(bp, regs->crd);
init_crd = REG_RD(bp, regs->init_crd);
DP(BNX2X_MSG_SP, "INIT CREDIT[%d] : %x\n", regs->pN, init_crd);
DP(BNX2X_MSG_SP, "CREDIT[%d] : s:%x\n", regs->pN, crd);
DP(BNX2X_MSG_SP, "CREDIT_FREED[%d]: s:%x\n", regs->pN, crd_freed);
while ((crd != init_crd) && ((u32)SUB_S32(crd_freed, crd_freed_start) <
(init_crd - crd_start))) {
if (cur_cnt--) {
udelay(FLR_WAIT_INTERAVAL);
crd = REG_RD(bp, regs->crd);
crd_freed = REG_RD(bp, regs->crd_freed);
} else {
DP(BNX2X_MSG_SP, "PBF tx buffer[%d] timed out\n",
regs->pN);
DP(BNX2X_MSG_SP, "CREDIT[%d] : c:%x\n",
regs->pN, crd);
DP(BNX2X_MSG_SP, "CREDIT_FREED[%d]: c:%x\n",
regs->pN, crd_freed);
break;
}
}
DP(BNX2X_MSG_SP, "Waited %d*%d usec for PBF tx buffer[%d]\n",
poll_count-cur_cnt, FLR_WAIT_INTERAVAL, regs->pN);
}
static void bnx2x_pbf_pN_cmd_flushed(struct bnx2x *bp,
struct pbf_pN_cmd_regs *regs,
u32 poll_count)
{
u32 occup, to_free, freed, freed_start;
u32 cur_cnt = poll_count;
occup = to_free = REG_RD(bp, regs->lines_occup);
freed = freed_start = REG_RD(bp, regs->lines_freed);
DP(BNX2X_MSG_SP, "OCCUPANCY[%d] : s:%x\n", regs->pN, occup);
DP(BNX2X_MSG_SP, "LINES_FREED[%d] : s:%x\n", regs->pN, freed);
while (occup && ((u32)SUB_S32(freed, freed_start) < to_free)) {
if (cur_cnt--) {
udelay(FLR_WAIT_INTERAVAL);
occup = REG_RD(bp, regs->lines_occup);
freed = REG_RD(bp, regs->lines_freed);
} else {
DP(BNX2X_MSG_SP, "PBF cmd queue[%d] timed out\n",
regs->pN);
DP(BNX2X_MSG_SP, "OCCUPANCY[%d] : s:%x\n",
regs->pN, occup);
DP(BNX2X_MSG_SP, "LINES_FREED[%d] : s:%x\n",
regs->pN, freed);
break;
}
}
DP(BNX2X_MSG_SP, "Waited %d*%d usec for PBF cmd queue[%d]\n",
poll_count-cur_cnt, FLR_WAIT_INTERAVAL, regs->pN);
}
static inline u32 bnx2x_flr_clnup_reg_poll(struct bnx2x *bp, u32 reg,
u32 expected, u32 poll_count)
{
u32 cur_cnt = poll_count;
u32 val;
while ((val = REG_RD(bp, reg)) != expected && cur_cnt--)
udelay(FLR_WAIT_INTERAVAL);
return val;
}
static inline int bnx2x_flr_clnup_poll_hw_counter(struct bnx2x *bp, u32 reg,
char *msg, u32 poll_cnt)
{
u32 val = bnx2x_flr_clnup_reg_poll(bp, reg, 0, poll_cnt);
if (val != 0) {
BNX2X_ERR("%s usage count=%d\n", msg, val);
return 1;
}
return 0;
}
static u32 bnx2x_flr_clnup_poll_count(struct bnx2x *bp)
{
if (CHIP_REV_IS_EMUL(bp))
return FLR_POLL_CNT * 2000;
if (CHIP_REV_IS_FPGA(bp))
return FLR_POLL_CNT * 120;
return FLR_POLL_CNT;
}
static void bnx2x_tx_hw_flushed(struct bnx2x *bp, u32 poll_count)
{
struct pbf_pN_cmd_regs cmd_regs[] = {
{0, (CHIP_IS_E3B0(bp)) ?
PBF_REG_TQ_OCCUPANCY_Q0 :
PBF_REG_P0_TQ_OCCUPANCY,
(CHIP_IS_E3B0(bp)) ?
PBF_REG_TQ_LINES_FREED_CNT_Q0 :
PBF_REG_P0_TQ_LINES_FREED_CNT},
{1, (CHIP_IS_E3B0(bp)) ?
PBF_REG_TQ_OCCUPANCY_Q1 :
PBF_REG_P1_TQ_OCCUPANCY,
(CHIP_IS_E3B0(bp)) ?
PBF_REG_TQ_LINES_FREED_CNT_Q1 :
PBF_REG_P1_TQ_LINES_FREED_CNT},
{4, (CHIP_IS_E3B0(bp)) ?
PBF_REG_TQ_OCCUPANCY_LB_Q :
PBF_REG_P4_TQ_OCCUPANCY,
(CHIP_IS_E3B0(bp)) ?
PBF_REG_TQ_LINES_FREED_CNT_LB_Q :
PBF_REG_P4_TQ_LINES_FREED_CNT}
};
struct pbf_pN_buf_regs buf_regs[] = {
{0, (CHIP_IS_E3B0(bp)) ?
PBF_REG_INIT_CRD_Q0 :
PBF_REG_P0_INIT_CRD ,
(CHIP_IS_E3B0(bp)) ?
PBF_REG_CREDIT_Q0 :
PBF_REG_P0_CREDIT,
(CHIP_IS_E3B0(bp)) ?
PBF_REG_INTERNAL_CRD_FREED_CNT_Q0 :
PBF_REG_P0_INTERNAL_CRD_FREED_CNT},
{1, (CHIP_IS_E3B0(bp)) ?
PBF_REG_INIT_CRD_Q1 :
PBF_REG_P1_INIT_CRD,
(CHIP_IS_E3B0(bp)) ?
PBF_REG_CREDIT_Q1 :
PBF_REG_P1_CREDIT,
(CHIP_IS_E3B0(bp)) ?
PBF_REG_INTERNAL_CRD_FREED_CNT_Q1 :
PBF_REG_P1_INTERNAL_CRD_FREED_CNT},
{4, (CHIP_IS_E3B0(bp)) ?
PBF_REG_INIT_CRD_LB_Q :
PBF_REG_P4_INIT_CRD,
(CHIP_IS_E3B0(bp)) ?
PBF_REG_CREDIT_LB_Q :
PBF_REG_P4_CREDIT,
(CHIP_IS_E3B0(bp)) ?
PBF_REG_INTERNAL_CRD_FREED_CNT_LB_Q :
PBF_REG_P4_INTERNAL_CRD_FREED_CNT},
};
int i;
for (i = 0; i < ARRAY_SIZE(cmd_regs); i++)
bnx2x_pbf_pN_cmd_flushed(bp, &cmd_regs[i], poll_count);
for (i = 0; i < ARRAY_SIZE(buf_regs); i++)
bnx2x_pbf_pN_buf_flushed(bp, &buf_regs[i], poll_count);
}
static inline int bnx2x_send_final_clnup(struct bnx2x *bp, u8 clnup_func,
u32 poll_cnt)
{
struct sdm_op_gen op_gen = {0};
u32 comp_addr = BAR_CSTRORM_INTMEM +
CSTORM_FINAL_CLEANUP_COMPLETE_OFFSET(clnup_func);
int ret = 0;
if (REG_RD(bp, comp_addr)) {
BNX2X_ERR("Cleanup complete is not 0\n");
return 1;
}
op_gen.command |= OP_GEN_PARAM(XSTORM_AGG_INT_FINAL_CLEANUP_INDEX);
op_gen.command |= OP_GEN_TYPE(XSTORM_AGG_INT_FINAL_CLEANUP_COMP_TYPE);
op_gen.command |= OP_GEN_AGG_VECT(clnup_func);
op_gen.command |= 1 << SDM_OP_GEN_AGG_VECT_IDX_VALID_SHIFT;
DP(BNX2X_MSG_SP, "FW Final cleanup\n");
REG_WR(bp, XSDM_REG_OPERATION_GEN, op_gen.command);
if (bnx2x_flr_clnup_reg_poll(bp, comp_addr, 1, poll_cnt) != 1) {
BNX2X_ERR("FW final cleanup did not succeed\n");
ret = 1;
}
REG_WR(bp, comp_addr, 0);
return ret;
}
static inline u8 bnx2x_is_pcie_pending(struct pci_dev *dev)
{
int pos;
u16 status;
pos = pci_pcie_cap(dev);
if (!pos)
return false;
pci_read_config_word(dev, pos + PCI_EXP_DEVSTA, &status);
return status & PCI_EXP_DEVSTA_TRPND;
}
static int bnx2x_poll_hw_usage_counters(struct bnx2x *bp, u32 poll_cnt)
{
if (bnx2x_flr_clnup_poll_hw_counter(bp,
CFC_REG_NUM_LCIDS_INSIDE_PF,
"CFC PF usage counter timed out",
poll_cnt))
return 1;
if (bnx2x_flr_clnup_poll_hw_counter(bp,
DORQ_REG_PF_USAGE_CNT,
"DQ PF usage counter timed out",
poll_cnt))
return 1;
if (bnx2x_flr_clnup_poll_hw_counter(bp,
QM_REG_PF_USG_CNT_0 + 4*BP_FUNC(bp),
"QM PF usage counter timed out",
poll_cnt))
return 1;
if (bnx2x_flr_clnup_poll_hw_counter(bp,
TM_REG_LIN0_VNIC_UC + 4*BP_PORT(bp),
"Timers VNIC usage counter timed out",
poll_cnt))
return 1;
if (bnx2x_flr_clnup_poll_hw_counter(bp,
TM_REG_LIN0_NUM_SCANS + 4*BP_PORT(bp),
"Timers NUM_SCANS usage counter timed out",
poll_cnt))
return 1;
if (bnx2x_flr_clnup_poll_hw_counter(bp,
dmae_reg_go_c[INIT_DMAE_C(bp)],
"DMAE dommand register timed out",
poll_cnt))
return 1;
return 0;
}
static void bnx2x_hw_enable_status(struct bnx2x *bp)
{
u32 val;
val = REG_RD(bp, CFC_REG_WEAK_ENABLE_PF);
DP(BNX2X_MSG_SP, "CFC_REG_WEAK_ENABLE_PF is 0x%x\n", val);
val = REG_RD(bp, PBF_REG_DISABLE_PF);
DP(BNX2X_MSG_SP, "PBF_REG_DISABLE_PF is 0x%x\n", val);
val = REG_RD(bp, IGU_REG_PCI_PF_MSI_EN);
DP(BNX2X_MSG_SP, "IGU_REG_PCI_PF_MSI_EN is 0x%x\n", val);
val = REG_RD(bp, IGU_REG_PCI_PF_MSIX_EN);
DP(BNX2X_MSG_SP, "IGU_REG_PCI_PF_MSIX_EN is 0x%x\n", val);
val = REG_RD(bp, IGU_REG_PCI_PF_MSIX_FUNC_MASK);
DP(BNX2X_MSG_SP, "IGU_REG_PCI_PF_MSIX_FUNC_MASK is 0x%x\n", val);
val = REG_RD(bp, PGLUE_B_REG_SHADOW_BME_PF_7_0_CLR);
DP(BNX2X_MSG_SP, "PGLUE_B_REG_SHADOW_BME_PF_7_0_CLR is 0x%x\n", val);
val = REG_RD(bp, PGLUE_B_REG_FLR_REQUEST_PF_7_0_CLR);
DP(BNX2X_MSG_SP, "PGLUE_B_REG_FLR_REQUEST_PF_7_0_CLR is 0x%x\n", val);
val = REG_RD(bp, PGLUE_B_REG_INTERNAL_PFID_ENABLE_MASTER);
DP(BNX2X_MSG_SP, "PGLUE_B_REG_INTERNAL_PFID_ENABLE_MASTER is 0x%x\n",
val);
}
static int bnx2x_pf_flr_clnup(struct bnx2x *bp)
{
u32 poll_cnt = bnx2x_flr_clnup_poll_count(bp);
DP(BNX2X_MSG_SP, "Cleanup after FLR PF[%d]\n", BP_ABS_FUNC(bp));
REG_WR(bp, PGLUE_B_REG_INTERNAL_PFID_ENABLE_TARGET_READ, 1);
if (bnx2x_poll_hw_usage_counters(bp, poll_cnt))
return -EBUSY;
if (bnx2x_send_final_clnup(bp, (u8)BP_FUNC(bp), poll_cnt))
return -EBUSY;
bnx2x_tx_hw_flushed(bp, poll_cnt);
msleep(100);
if (bnx2x_is_pcie_pending(bp->pdev))
BNX2X_ERR("PCIE Transactions still pending\n");
bnx2x_hw_enable_status(bp);
REG_WR(bp, PGLUE_B_REG_INTERNAL_PFID_ENABLE_MASTER, 1);
return 0;
}
static void bnx2x_hc_int_enable(struct bnx2x *bp)
{
int port = BP_PORT(bp);
u32 addr = port ? HC_REG_CONFIG_1 : HC_REG_CONFIG_0;
u32 val = REG_RD(bp, addr);
int msix = (bp->flags & USING_MSIX_FLAG) ? 1 : 0;
int msi = (bp->flags & USING_MSI_FLAG) ? 1 : 0;
if (msix) {
val &= ~(HC_CONFIG_0_REG_SINGLE_ISR_EN_0 |
HC_CONFIG_0_REG_INT_LINE_EN_0);
val |= (HC_CONFIG_0_REG_MSI_MSIX_INT_EN_0 |
HC_CONFIG_0_REG_ATTN_BIT_EN_0);
} else if (msi) {
val &= ~HC_CONFIG_0_REG_INT_LINE_EN_0;
val |= (HC_CONFIG_0_REG_SINGLE_ISR_EN_0 |
HC_CONFIG_0_REG_MSI_MSIX_INT_EN_0 |
HC_CONFIG_0_REG_ATTN_BIT_EN_0);
} else {
val |= (HC_CONFIG_0_REG_SINGLE_ISR_EN_0 |
HC_CONFIG_0_REG_MSI_MSIX_INT_EN_0 |
HC_CONFIG_0_REG_INT_LINE_EN_0 |
HC_CONFIG_0_REG_ATTN_BIT_EN_0);
if (!CHIP_IS_E1(bp)) {
DP(NETIF_MSG_INTR, "write %x to HC %d (addr 0x%x)\n",
val, port, addr);
REG_WR(bp, addr, val);
val &= ~HC_CONFIG_0_REG_MSI_MSIX_INT_EN_0;
}
}
if (CHIP_IS_E1(bp))
REG_WR(bp, HC_REG_INT_MASK + port*4, 0x1FFFF);
DP(NETIF_MSG_INTR, "write %x to HC %d (addr 0x%x) mode %s\n",
val, port, addr, (msix ? "MSI-X" : (msi ? "MSI" : "INTx")));
REG_WR(bp, addr, val);
mmiowb();
barrier();
if (!CHIP_IS_E1(bp)) {
if (IS_MF(bp)) {
val = (0xee0f | (1 << (BP_VN(bp) + 4)));
if (bp->port.pmf)
val |= 0x1100;
} else
val = 0xffff;
REG_WR(bp, HC_REG_TRAILING_EDGE_0 + port*8, val);
REG_WR(bp, HC_REG_LEADING_EDGE_0 + port*8, val);
}
mmiowb();
}
static void bnx2x_igu_int_enable(struct bnx2x *bp)
{
u32 val;
int msix = (bp->flags & USING_MSIX_FLAG) ? 1 : 0;
int msi = (bp->flags & USING_MSI_FLAG) ? 1 : 0;
val = REG_RD(bp, IGU_REG_PF_CONFIGURATION);
if (msix) {
val &= ~(IGU_PF_CONF_INT_LINE_EN |
IGU_PF_CONF_SINGLE_ISR_EN);
val |= (IGU_PF_CONF_FUNC_EN |
IGU_PF_CONF_MSI_MSIX_EN |
IGU_PF_CONF_ATTN_BIT_EN);
} else if (msi) {
val &= ~IGU_PF_CONF_INT_LINE_EN;
val |= (IGU_PF_CONF_FUNC_EN |
IGU_PF_CONF_MSI_MSIX_EN |
IGU_PF_CONF_ATTN_BIT_EN |
IGU_PF_CONF_SINGLE_ISR_EN);
} else {
val &= ~IGU_PF_CONF_MSI_MSIX_EN;
val |= (IGU_PF_CONF_FUNC_EN |
IGU_PF_CONF_INT_LINE_EN |
IGU_PF_CONF_ATTN_BIT_EN |
IGU_PF_CONF_SINGLE_ISR_EN);
}
DP(NETIF_MSG_INTR, "write 0x%x to IGU mode %s\n",
val, (msix ? "MSI-X" : (msi ? "MSI" : "INTx")));
REG_WR(bp, IGU_REG_PF_CONFIGURATION, val);
barrier();
if (IS_MF(bp)) {
val = (0xee0f | (1 << (BP_VN(bp) + 4)));
if (bp->port.pmf)
val |= 0x1100;
} else
val = 0xffff;
REG_WR(bp, IGU_REG_TRAILING_EDGE_LATCH, val);
REG_WR(bp, IGU_REG_LEADING_EDGE_LATCH, val);
mmiowb();
}
void bnx2x_int_enable(struct bnx2x *bp)
{
if (bp->common.int_block == INT_BLOCK_HC)
bnx2x_hc_int_enable(bp);
else
bnx2x_igu_int_enable(bp);
}
static void bnx2x_hc_int_disable(struct bnx2x *bp)
{
int port = BP_PORT(bp);
u32 addr = port ? HC_REG_CONFIG_1 : HC_REG_CONFIG_0;
u32 val = REG_RD(bp, addr);
if (CHIP_IS_E1(bp)) {
REG_WR(bp, HC_REG_INT_MASK + port*4, 0);
val &= ~(HC_CONFIG_0_REG_SINGLE_ISR_EN_0 |
HC_CONFIG_0_REG_INT_LINE_EN_0 |
HC_CONFIG_0_REG_ATTN_BIT_EN_0);
} else
val &= ~(HC_CONFIG_0_REG_SINGLE_ISR_EN_0 |
HC_CONFIG_0_REG_MSI_MSIX_INT_EN_0 |
HC_CONFIG_0_REG_INT_LINE_EN_0 |
HC_CONFIG_0_REG_ATTN_BIT_EN_0);
DP(NETIF_MSG_INTR, "write %x to HC %d (addr 0x%x)\n",
val, port, addr);
mmiowb();
REG_WR(bp, addr, val);
if (REG_RD(bp, addr) != val)
BNX2X_ERR("BUG! proper val not read from IGU!\n");
}
static void bnx2x_igu_int_disable(struct bnx2x *bp)
{
u32 val = REG_RD(bp, IGU_REG_PF_CONFIGURATION);
val &= ~(IGU_PF_CONF_MSI_MSIX_EN |
IGU_PF_CONF_INT_LINE_EN |
IGU_PF_CONF_ATTN_BIT_EN);
DP(NETIF_MSG_INTR, "write %x to IGU\n", val);
mmiowb();
REG_WR(bp, IGU_REG_PF_CONFIGURATION, val);
if (REG_RD(bp, IGU_REG_PF_CONFIGURATION) != val)
BNX2X_ERR("BUG! proper val not read from IGU!\n");
}
void bnx2x_int_disable(struct bnx2x *bp)
{
if (bp->common.int_block == INT_BLOCK_HC)
bnx2x_hc_int_disable(bp);
else
bnx2x_igu_int_disable(bp);
}
void bnx2x_int_disable_sync(struct bnx2x *bp, int disable_hw)
{
int msix = (bp->flags & USING_MSIX_FLAG) ? 1 : 0;
int i, offset;
if (disable_hw)
bnx2x_int_disable(bp);
if (msix) {
synchronize_irq(bp->msix_table[0].vector);
offset = 1;
#ifdef BCM_CNIC
offset++;
#endif
for_each_eth_queue(bp, i)
synchronize_irq(bp->msix_table[offset++].vector);
} else
synchronize_irq(bp->pdev->irq);
cancel_delayed_work(&bp->sp_task);
cancel_delayed_work(&bp->period_task);
flush_workqueue(bnx2x_wq);
}
static bool bnx2x_trylock_hw_lock(struct bnx2x *bp, u32 resource)
{
u32 lock_status;
u32 resource_bit = (1 << resource);
int func = BP_FUNC(bp);
u32 hw_lock_control_reg;
DP(NETIF_MSG_HW, "Trying to take a lock on resource %d\n", resource);
if (resource > HW_LOCK_MAX_RESOURCE_VALUE) {
DP(NETIF_MSG_HW,
"resource(0x%x) > HW_LOCK_MAX_RESOURCE_VALUE(0x%x)\n",
resource, HW_LOCK_MAX_RESOURCE_VALUE);
return false;
}
if (func <= 5)
hw_lock_control_reg = (MISC_REG_DRIVER_CONTROL_1 + func*8);
else
hw_lock_control_reg =
(MISC_REG_DRIVER_CONTROL_7 + (func - 6)*8);
REG_WR(bp, hw_lock_control_reg + 4, resource_bit);
lock_status = REG_RD(bp, hw_lock_control_reg);
if (lock_status & resource_bit)
return true;
DP(NETIF_MSG_HW, "Failed to get a lock on resource %d\n", resource);
return false;
}
static inline int bnx2x_get_leader_lock_resource(struct bnx2x *bp)
{
if (BP_PATH(bp))
return HW_LOCK_RESOURCE_RECOVERY_LEADER_1;
else
return HW_LOCK_RESOURCE_RECOVERY_LEADER_0;
}
static inline bool bnx2x_trylock_leader_lock(struct bnx2x *bp)
{
return bnx2x_trylock_hw_lock(bp, bnx2x_get_leader_lock_resource(bp));
}
void bnx2x_sp_event(struct bnx2x_fastpath *fp, union eth_rx_cqe *rr_cqe)
{
struct bnx2x *bp = fp->bp;
int cid = SW_CID(rr_cqe->ramrod_cqe.conn_and_cmd_data);
int command = CQE_CMD(rr_cqe->ramrod_cqe.conn_and_cmd_data);
enum bnx2x_queue_cmd drv_cmd = BNX2X_Q_CMD_MAX;
struct bnx2x_queue_sp_obj *q_obj = &fp->q_obj;
DP(BNX2X_MSG_SP,
"fp %d cid %d got ramrod #%d state is %x type is %d\n",
fp->index, cid, command, bp->state,
rr_cqe->ramrod_cqe.ramrod_type);
switch (command) {
case (RAMROD_CMD_ID_ETH_CLIENT_UPDATE):
DP(BNX2X_MSG_SP, "got UPDATE ramrod. CID %d\n", cid);
drv_cmd = BNX2X_Q_CMD_UPDATE;
break;
case (RAMROD_CMD_ID_ETH_CLIENT_SETUP):
DP(BNX2X_MSG_SP, "got MULTI[%d] setup ramrod\n", cid);
drv_cmd = BNX2X_Q_CMD_SETUP;
break;
case (RAMROD_CMD_ID_ETH_TX_QUEUE_SETUP):
DP(NETIF_MSG_IFUP, "got MULTI[%d] tx-only setup ramrod\n", cid);
drv_cmd = BNX2X_Q_CMD_SETUP_TX_ONLY;
break;
case (RAMROD_CMD_ID_ETH_HALT):
DP(BNX2X_MSG_SP, "got MULTI[%d] halt ramrod\n", cid);
drv_cmd = BNX2X_Q_CMD_HALT;
break;
case (RAMROD_CMD_ID_ETH_TERMINATE):
DP(BNX2X_MSG_SP, "got MULTI[%d] teminate ramrod\n", cid);
drv_cmd = BNX2X_Q_CMD_TERMINATE;
break;
case (RAMROD_CMD_ID_ETH_EMPTY):
DP(BNX2X_MSG_SP, "got MULTI[%d] empty ramrod\n", cid);
drv_cmd = BNX2X_Q_CMD_EMPTY;
break;
default:
BNX2X_ERR("unexpected MC reply (%d) on fp[%d]\n",
command, fp->index);
return;
}
if ((drv_cmd != BNX2X_Q_CMD_MAX) &&
q_obj->complete_cmd(bp, q_obj, drv_cmd))
#ifdef BNX2X_STOP_ON_ERROR
bnx2x_panic();
#else
return;
#endif
smp_mb__before_atomic_inc();
atomic_inc(&bp->cq_spq_left);
smp_mb__after_atomic_inc();
DP(BNX2X_MSG_SP, "bp->cq_spq_left %x\n", atomic_read(&bp->cq_spq_left));
return;
}
void bnx2x_update_rx_prod(struct bnx2x *bp, struct bnx2x_fastpath *fp,
u16 bd_prod, u16 rx_comp_prod, u16 rx_sge_prod)
{
u32 start = BAR_USTRORM_INTMEM + fp->ustorm_rx_prods_offset;
bnx2x_update_rx_prod_gen(bp, fp, bd_prod, rx_comp_prod, rx_sge_prod,
start);
}
irqreturn_t bnx2x_interrupt(int irq, void *dev_instance)
{
struct bnx2x *bp = netdev_priv(dev_instance);
u16 status = bnx2x_ack_int(bp);
u16 mask;
int i;
u8 cos;
if (unlikely(status == 0)) {
DP(NETIF_MSG_INTR, "not our interrupt!\n");
return IRQ_NONE;
}
DP(NETIF_MSG_INTR, "got an interrupt status 0x%x\n", status);
#ifdef BNX2X_STOP_ON_ERROR
if (unlikely(bp->panic))
return IRQ_HANDLED;
#endif
for_each_eth_queue(bp, i) {
struct bnx2x_fastpath *fp = &bp->fp[i];
mask = 0x2 << (fp->index + CNIC_PRESENT);
if (status & mask) {
prefetch(fp->rx_cons_sb);
for_each_cos_in_tx_queue(fp, cos)
prefetch(fp->txdata[cos].tx_cons_sb);
prefetch(&fp->sb_running_index[SM_RX_ID]);
napi_schedule(&bnx2x_fp(bp, fp->index, napi));
status &= ~mask;
}
}
#ifdef BCM_CNIC
mask = 0x2;
if (status & (mask | 0x1)) {
struct cnic_ops *c_ops = NULL;
if (likely(bp->state == BNX2X_STATE_OPEN)) {
rcu_read_lock();
c_ops = rcu_dereference(bp->cnic_ops);
if (c_ops)
c_ops->cnic_handler(bp->cnic_data, NULL);
rcu_read_unlock();
}
status &= ~mask;
}
#endif
if (unlikely(status & 0x1)) {
queue_delayed_work(bnx2x_wq, &bp->sp_task, 0);
status &= ~0x1;
if (!status)
return IRQ_HANDLED;
}
if (unlikely(status))
DP(NETIF_MSG_INTR, "got an unknown interrupt! (status 0x%x)\n",
status);
return IRQ_HANDLED;
}
int bnx2x_acquire_hw_lock(struct bnx2x *bp, u32 resource)
{
u32 lock_status;
u32 resource_bit = (1 << resource);
int func = BP_FUNC(bp);
u32 hw_lock_control_reg;
int cnt;
if (resource > HW_LOCK_MAX_RESOURCE_VALUE) {
DP(NETIF_MSG_HW,
"resource(0x%x) > HW_LOCK_MAX_RESOURCE_VALUE(0x%x)\n",
resource, HW_LOCK_MAX_RESOURCE_VALUE);
return -EINVAL;
}
if (func <= 5) {
hw_lock_control_reg = (MISC_REG_DRIVER_CONTROL_1 + func*8);
} else {
hw_lock_control_reg =
(MISC_REG_DRIVER_CONTROL_7 + (func - 6)*8);
}
lock_status = REG_RD(bp, hw_lock_control_reg);
if (lock_status & resource_bit) {
DP(NETIF_MSG_HW, "lock_status 0x%x resource_bit 0x%x\n",
lock_status, resource_bit);
return -EEXIST;
}
for (cnt = 0; cnt < 1000; cnt++) {
REG_WR(bp, hw_lock_control_reg + 4, resource_bit);
lock_status = REG_RD(bp, hw_lock_control_reg);
if (lock_status & resource_bit)
return 0;
msleep(5);
}
DP(NETIF_MSG_HW, "Timeout\n");
return -EAGAIN;
}
int bnx2x_release_leader_lock(struct bnx2x *bp)
{
return bnx2x_release_hw_lock(bp, bnx2x_get_leader_lock_resource(bp));
}
int bnx2x_release_hw_lock(struct bnx2x *bp, u32 resource)
{
u32 lock_status;
u32 resource_bit = (1 << resource);
int func = BP_FUNC(bp);
u32 hw_lock_control_reg;
DP(NETIF_MSG_HW, "Releasing a lock on resource %d\n", resource);
if (resource > HW_LOCK_MAX_RESOURCE_VALUE) {
DP(NETIF_MSG_HW,
"resource(0x%x) > HW_LOCK_MAX_RESOURCE_VALUE(0x%x)\n",
resource, HW_LOCK_MAX_RESOURCE_VALUE);
return -EINVAL;
}
if (func <= 5) {
hw_lock_control_reg = (MISC_REG_DRIVER_CONTROL_1 + func*8);
} else {
hw_lock_control_reg =
(MISC_REG_DRIVER_CONTROL_7 + (func - 6)*8);
}
lock_status = REG_RD(bp, hw_lock_control_reg);
if (!(lock_status & resource_bit)) {
DP(NETIF_MSG_HW, "lock_status 0x%x resource_bit 0x%x\n",
lock_status, resource_bit);
return -EFAULT;
}
REG_WR(bp, hw_lock_control_reg, resource_bit);
return 0;
}
int bnx2x_get_gpio(struct bnx2x *bp, int gpio_num, u8 port)
{
int gpio_port = (REG_RD(bp, NIG_REG_PORT_SWAP) &&
REG_RD(bp, NIG_REG_STRAP_OVERRIDE)) ^ port;
int gpio_shift = gpio_num +
(gpio_port ? MISC_REGISTERS_GPIO_PORT_SHIFT : 0);
u32 gpio_mask = (1 << gpio_shift);
u32 gpio_reg;
int value;
if (gpio_num > MISC_REGISTERS_GPIO_3) {
BNX2X_ERR("Invalid GPIO %d\n", gpio_num);
return -EINVAL;
}
gpio_reg = REG_RD(bp, MISC_REG_GPIO);
if ((gpio_reg & gpio_mask) == gpio_mask)
value = 1;
else
value = 0;
DP(NETIF_MSG_LINK, "pin %d value 0x%x\n", gpio_num, value);
return value;
}
int bnx2x_set_gpio(struct bnx2x *bp, int gpio_num, u32 mode, u8 port)
{
int gpio_port = (REG_RD(bp, NIG_REG_PORT_SWAP) &&
REG_RD(bp, NIG_REG_STRAP_OVERRIDE)) ^ port;
int gpio_shift = gpio_num +
(gpio_port ? MISC_REGISTERS_GPIO_PORT_SHIFT : 0);
u32 gpio_mask = (1 << gpio_shift);
u32 gpio_reg;
if (gpio_num > MISC_REGISTERS_GPIO_3) {
BNX2X_ERR("Invalid GPIO %d\n", gpio_num);
return -EINVAL;
}
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_GPIO);
gpio_reg = (REG_RD(bp, MISC_REG_GPIO) & MISC_REGISTERS_GPIO_FLOAT);
switch (mode) {
case MISC_REGISTERS_GPIO_OUTPUT_LOW:
DP(NETIF_MSG_LINK, "Set GPIO %d (shift %d) -> output low\n",
gpio_num, gpio_shift);
gpio_reg &= ~(gpio_mask << MISC_REGISTERS_GPIO_FLOAT_POS);
gpio_reg |= (gpio_mask << MISC_REGISTERS_GPIO_CLR_POS);
break;
case MISC_REGISTERS_GPIO_OUTPUT_HIGH:
DP(NETIF_MSG_LINK, "Set GPIO %d (shift %d) -> output high\n",
gpio_num, gpio_shift);
gpio_reg &= ~(gpio_mask << MISC_REGISTERS_GPIO_FLOAT_POS);
gpio_reg |= (gpio_mask << MISC_REGISTERS_GPIO_SET_POS);
break;
case MISC_REGISTERS_GPIO_INPUT_HI_Z:
DP(NETIF_MSG_LINK, "Set GPIO %d (shift %d) -> input\n",
gpio_num, gpio_shift);
gpio_reg |= (gpio_mask << MISC_REGISTERS_GPIO_FLOAT_POS);
break;
default:
break;
}
REG_WR(bp, MISC_REG_GPIO, gpio_reg);
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_GPIO);
return 0;
}
int bnx2x_set_mult_gpio(struct bnx2x *bp, u8 pins, u32 mode)
{
u32 gpio_reg = 0;
int rc = 0;
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_GPIO);
gpio_reg = REG_RD(bp, MISC_REG_GPIO);
gpio_reg &= ~(pins << MISC_REGISTERS_GPIO_FLOAT_POS);
gpio_reg &= ~(pins << MISC_REGISTERS_GPIO_CLR_POS);
gpio_reg &= ~(pins << MISC_REGISTERS_GPIO_SET_POS);
switch (mode) {
case MISC_REGISTERS_GPIO_OUTPUT_LOW:
DP(NETIF_MSG_LINK, "Set GPIO 0x%x -> output low\n", pins);
gpio_reg |= (pins << MISC_REGISTERS_GPIO_CLR_POS);
break;
case MISC_REGISTERS_GPIO_OUTPUT_HIGH:
DP(NETIF_MSG_LINK, "Set GPIO 0x%x -> output high\n", pins);
gpio_reg |= (pins << MISC_REGISTERS_GPIO_SET_POS);
break;
case MISC_REGISTERS_GPIO_INPUT_HI_Z:
DP(NETIF_MSG_LINK, "Set GPIO 0x%x -> input\n", pins);
gpio_reg |= (pins << MISC_REGISTERS_GPIO_FLOAT_POS);
break;
default:
BNX2X_ERR("Invalid GPIO mode assignment %d\n", mode);
rc = -EINVAL;
break;
}
if (rc == 0)
REG_WR(bp, MISC_REG_GPIO, gpio_reg);
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_GPIO);
return rc;
}
int bnx2x_set_gpio_int(struct bnx2x *bp, int gpio_num, u32 mode, u8 port)
{
int gpio_port = (REG_RD(bp, NIG_REG_PORT_SWAP) &&
REG_RD(bp, NIG_REG_STRAP_OVERRIDE)) ^ port;
int gpio_shift = gpio_num +
(gpio_port ? MISC_REGISTERS_GPIO_PORT_SHIFT : 0);
u32 gpio_mask = (1 << gpio_shift);
u32 gpio_reg;
if (gpio_num > MISC_REGISTERS_GPIO_3) {
BNX2X_ERR("Invalid GPIO %d\n", gpio_num);
return -EINVAL;
}
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_GPIO);
gpio_reg = REG_RD(bp, MISC_REG_GPIO_INT);
switch (mode) {
case MISC_REGISTERS_GPIO_INT_OUTPUT_CLR:
DP(NETIF_MSG_LINK, "Clear GPIO INT %d (shift %d) -> "
"output low\n", gpio_num, gpio_shift);
gpio_reg &= ~(gpio_mask << MISC_REGISTERS_GPIO_INT_SET_POS);
gpio_reg |= (gpio_mask << MISC_REGISTERS_GPIO_INT_CLR_POS);
break;
case MISC_REGISTERS_GPIO_INT_OUTPUT_SET:
DP(NETIF_MSG_LINK, "Set GPIO INT %d (shift %d) -> "
"output high\n", gpio_num, gpio_shift);
gpio_reg &= ~(gpio_mask << MISC_REGISTERS_GPIO_INT_CLR_POS);
gpio_reg |= (gpio_mask << MISC_REGISTERS_GPIO_INT_SET_POS);
break;
default:
break;
}
REG_WR(bp, MISC_REG_GPIO_INT, gpio_reg);
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_GPIO);
return 0;
}
static int bnx2x_set_spio(struct bnx2x *bp, int spio_num, u32 mode)
{
u32 spio_mask = (1 << spio_num);
u32 spio_reg;
if ((spio_num < MISC_REGISTERS_SPIO_4) ||
(spio_num > MISC_REGISTERS_SPIO_7)) {
BNX2X_ERR("Invalid SPIO %d\n", spio_num);
return -EINVAL;
}
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_SPIO);
spio_reg = (REG_RD(bp, MISC_REG_SPIO) & MISC_REGISTERS_SPIO_FLOAT);
switch (mode) {
case MISC_REGISTERS_SPIO_OUTPUT_LOW:
DP(NETIF_MSG_LINK, "Set SPIO %d -> output low\n", spio_num);
spio_reg &= ~(spio_mask << MISC_REGISTERS_SPIO_FLOAT_POS);
spio_reg |= (spio_mask << MISC_REGISTERS_SPIO_CLR_POS);
break;
case MISC_REGISTERS_SPIO_OUTPUT_HIGH:
DP(NETIF_MSG_LINK, "Set SPIO %d -> output high\n", spio_num);
spio_reg &= ~(spio_mask << MISC_REGISTERS_SPIO_FLOAT_POS);
spio_reg |= (spio_mask << MISC_REGISTERS_SPIO_SET_POS);
break;
case MISC_REGISTERS_SPIO_INPUT_HI_Z:
DP(NETIF_MSG_LINK, "Set SPIO %d -> input\n", spio_num);
spio_reg |= (spio_mask << MISC_REGISTERS_SPIO_FLOAT_POS);
break;
default:
break;
}
REG_WR(bp, MISC_REG_SPIO, spio_reg);
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_SPIO);
return 0;
}
void bnx2x_calc_fc_adv(struct bnx2x *bp)
{
u8 cfg_idx = bnx2x_get_link_cfg_idx(bp);
switch (bp->link_vars.ieee_fc &
MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_MASK) {
case MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_NONE:
bp->port.advertising[cfg_idx] &= ~(ADVERTISED_Asym_Pause |
ADVERTISED_Pause);
break;
case MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_BOTH:
bp->port.advertising[cfg_idx] |= (ADVERTISED_Asym_Pause |
ADVERTISED_Pause);
break;
case MDIO_COMBO_IEEE0_AUTO_NEG_ADV_PAUSE_ASYMMETRIC:
bp->port.advertising[cfg_idx] |= ADVERTISED_Asym_Pause;
break;
default:
bp->port.advertising[cfg_idx] &= ~(ADVERTISED_Asym_Pause |
ADVERTISED_Pause);
break;
}
}
u8 bnx2x_initial_phy_init(struct bnx2x *bp, int load_mode)
{
if (!BP_NOMCP(bp)) {
u8 rc;
int cfx_idx = bnx2x_get_link_cfg_idx(bp);
u16 req_line_speed = bp->link_params.req_line_speed[cfx_idx];
if (CHIP_IS_E1x(bp) && (bp->dev->mtu > 5000))
bp->link_params.req_fc_auto_adv = BNX2X_FLOW_CTRL_TX;
else
bp->link_params.req_fc_auto_adv = BNX2X_FLOW_CTRL_BOTH;
bnx2x_acquire_phy_lock(bp);
if (load_mode == LOAD_DIAG) {
struct link_params *lp = &bp->link_params;
lp->loopback_mode = LOOPBACK_XGXS;
if (lp->req_line_speed[cfx_idx] < SPEED_10000) {
if (lp->speed_cap_mask[cfx_idx] &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G)
lp->req_line_speed[cfx_idx] =
SPEED_10000;
else
lp->req_line_speed[cfx_idx] =
SPEED_1000;
}
}
rc = bnx2x_phy_init(&bp->link_params, &bp->link_vars);
bnx2x_release_phy_lock(bp);
bnx2x_calc_fc_adv(bp);
if (CHIP_REV_IS_SLOW(bp) && bp->link_vars.link_up) {
bnx2x_stats_handle(bp, STATS_EVENT_LINK_UP);
bnx2x_link_report(bp);
} else
queue_delayed_work(bnx2x_wq, &bp->period_task, 0);
bp->link_params.req_line_speed[cfx_idx] = req_line_speed;
return rc;
}
BNX2X_ERR("Bootcode is missing - can not initialize link\n");
return -EINVAL;
}
void bnx2x_link_set(struct bnx2x *bp)
{
if (!BP_NOMCP(bp)) {
bnx2x_acquire_phy_lock(bp);
bnx2x_link_reset(&bp->link_params, &bp->link_vars, 1);
bnx2x_phy_init(&bp->link_params, &bp->link_vars);
bnx2x_release_phy_lock(bp);
bnx2x_calc_fc_adv(bp);
} else
BNX2X_ERR("Bootcode is missing - can not set link\n");
}
static void bnx2x__link_reset(struct bnx2x *bp)
{
if (!BP_NOMCP(bp)) {
bnx2x_acquire_phy_lock(bp);
bnx2x_link_reset(&bp->link_params, &bp->link_vars, 1);
bnx2x_release_phy_lock(bp);
} else
BNX2X_ERR("Bootcode is missing - can not reset link\n");
}
u8 bnx2x_link_test(struct bnx2x *bp, u8 is_serdes)
{
u8 rc = 0;
if (!BP_NOMCP(bp)) {
bnx2x_acquire_phy_lock(bp);
rc = bnx2x_test_link(&bp->link_params, &bp->link_vars,
is_serdes);
bnx2x_release_phy_lock(bp);
} else
BNX2X_ERR("Bootcode is missing - can not test link\n");
return rc;
}
static void bnx2x_init_port_minmax(struct bnx2x *bp)
{
u32 r_param = bp->link_vars.line_speed / 8;
u32 fair_periodic_timeout_usec;
u32 t_fair;
memset(&(bp->cmng.rs_vars), 0,
sizeof(struct rate_shaping_vars_per_port));
memset(&(bp->cmng.fair_vars), 0, sizeof(struct fairness_vars_per_port));
bp->cmng.rs_vars.rs_periodic_timeout = RS_PERIODIC_TIMEOUT_USEC / 4;
bp->cmng.rs_vars.rs_threshold =
(RS_PERIODIC_TIMEOUT_USEC * r_param * 5) / 4;
fair_periodic_timeout_usec = QM_ARB_BYTES / r_param;
t_fair = T_FAIR_COEF / bp->link_vars.line_speed;
bp->cmng.fair_vars.fair_threshold = QM_ARB_BYTES;
bp->cmng.fair_vars.upper_bound = r_param * t_fair * FAIR_MEM;
bp->cmng.fair_vars.fairness_timeout = fair_periodic_timeout_usec / 4;
}
static void bnx2x_calc_vn_weight_sum(struct bnx2x *bp)
{
int all_zero = 1;
int vn;
bp->vn_weight_sum = 0;
for (vn = VN_0; vn < BP_MAX_VN_NUM(bp); vn++) {
u32 vn_cfg = bp->mf_config[vn];
u32 vn_min_rate = ((vn_cfg & FUNC_MF_CFG_MIN_BW_MASK) >>
FUNC_MF_CFG_MIN_BW_SHIFT) * 100;
if (vn_cfg & FUNC_MF_CFG_FUNC_HIDE)
continue;
if (!vn_min_rate)
vn_min_rate = DEF_MIN_RATE;
else
all_zero = 0;
bp->vn_weight_sum += vn_min_rate;
}
if (BNX2X_IS_ETS_ENABLED(bp)) {
bp->cmng.flags.cmng_enables &=
~CMNG_FLAGS_PER_PORT_FAIRNESS_VN;
DP(NETIF_MSG_IFUP, "Fairness will be disabled due to ETS\n");
} else if (all_zero) {
bp->cmng.flags.cmng_enables &=
~CMNG_FLAGS_PER_PORT_FAIRNESS_VN;
DP(NETIF_MSG_IFUP, "All MIN values are zeroes"
" fairness will be disabled\n");
} else
bp->cmng.flags.cmng_enables |=
CMNG_FLAGS_PER_PORT_FAIRNESS_VN;
}
static inline int func_by_vn(struct bnx2x *bp, int vn)
{
return 2 * vn + BP_PORT(bp);
}
static void bnx2x_init_vn_minmax(struct bnx2x *bp, int vn)
{
struct rate_shaping_vars_per_vn m_rs_vn;
struct fairness_vars_per_vn m_fair_vn;
u32 vn_cfg = bp->mf_config[vn];
int func = func_by_vn(bp, vn);
u16 vn_min_rate, vn_max_rate;
int i;
if (vn_cfg & FUNC_MF_CFG_FUNC_HIDE) {
vn_min_rate = 0;
vn_max_rate = 0;
} else {
u32 maxCfg = bnx2x_extract_max_cfg(bp, vn_cfg);
vn_min_rate = ((vn_cfg & FUNC_MF_CFG_MIN_BW_MASK) >>
FUNC_MF_CFG_MIN_BW_SHIFT) * 100;
if (bp->vn_weight_sum && (vn_min_rate == 0))
vn_min_rate = DEF_MIN_RATE;
if (IS_MF_SI(bp))
vn_max_rate = (bp->link_vars.line_speed * maxCfg) / 100;
else
vn_max_rate = maxCfg * 100;
}
DP(NETIF_MSG_IFUP,
"func %d: vn_min_rate %d vn_max_rate %d vn_weight_sum %d\n",
func, vn_min_rate, vn_max_rate, bp->vn_weight_sum);
memset(&m_rs_vn, 0, sizeof(struct rate_shaping_vars_per_vn));
memset(&m_fair_vn, 0, sizeof(struct fairness_vars_per_vn));
m_rs_vn.vn_counter.rate = vn_max_rate;
m_rs_vn.vn_counter.quota =
(vn_max_rate * RS_PERIODIC_TIMEOUT_USEC) / 8;
if (bp->vn_weight_sum) {
m_fair_vn.vn_credit_delta =
max_t(u32, (vn_min_rate * (T_FAIR_COEF /
(8 * bp->vn_weight_sum))),
(bp->cmng.fair_vars.fair_threshold +
MIN_ABOVE_THRESH));
DP(NETIF_MSG_IFUP, "m_fair_vn.vn_credit_delta %d\n",
m_fair_vn.vn_credit_delta);
}
for (i = 0; i < sizeof(struct rate_shaping_vars_per_vn)/4; i++)
REG_WR(bp, BAR_XSTRORM_INTMEM +
XSTORM_RATE_SHAPING_PER_VN_VARS_OFFSET(func) + i * 4,
((u32 *)(&m_rs_vn))[i]);
for (i = 0; i < sizeof(struct fairness_vars_per_vn)/4; i++)
REG_WR(bp, BAR_XSTRORM_INTMEM +
XSTORM_FAIRNESS_PER_VN_VARS_OFFSET(func) + i * 4,
((u32 *)(&m_fair_vn))[i]);
}
static int bnx2x_get_cmng_fns_mode(struct bnx2x *bp)
{
if (CHIP_REV_IS_SLOW(bp))
return CMNG_FNS_NONE;
if (IS_MF(bp))
return CMNG_FNS_MINMAX;
return CMNG_FNS_NONE;
}
void bnx2x_read_mf_cfg(struct bnx2x *bp)
{
int vn, n = (CHIP_MODE_IS_4_PORT(bp) ? 2 : 1);
if (BP_NOMCP(bp))
return;
for (vn = VN_0; vn < BP_MAX_VN_NUM(bp); vn++) {
int func = n * (2 * vn + BP_PORT(bp)) + BP_PATH(bp);
if (func >= E1H_FUNC_MAX)
break;
bp->mf_config[vn] =
MF_CFG_RD(bp, func_mf_config[func].config);
}
}
static void bnx2x_cmng_fns_init(struct bnx2x *bp, u8 read_cfg, u8 cmng_type)
{
if (cmng_type == CMNG_FNS_MINMAX) {
int vn;
bp->cmng.flags.cmng_enables = 0;
if (read_cfg)
bnx2x_read_mf_cfg(bp);
bnx2x_init_port_minmax(bp);
bnx2x_calc_vn_weight_sum(bp);
if (bp->port.pmf)
for (vn = VN_0; vn < BP_MAX_VN_NUM(bp); vn++)
bnx2x_init_vn_minmax(bp, vn);
bp->cmng.flags.cmng_enables |=
CMNG_FLAGS_PER_PORT_RATE_SHAPING_VN;
if (!bp->vn_weight_sum)
DP(NETIF_MSG_IFUP, "All MIN values are zeroes"
" fairness will be disabled\n");
return;
}
DP(NETIF_MSG_IFUP,
"rate shaping and fairness are disabled\n");
}
static inline void bnx2x_link_sync_notify(struct bnx2x *bp)
{
int func;
int vn;
for (vn = VN_0; vn < BP_MAX_VN_NUM(bp); vn++) {
if (vn == BP_VN(bp))
continue;
func = func_by_vn(bp, vn);
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_0 +
(LINK_SYNC_ATTENTION_BIT_FUNC_0 + func)*4, 1);
}
}
static void bnx2x_link_attn(struct bnx2x *bp)
{
bnx2x_stats_handle(bp, STATS_EVENT_STOP);
bnx2x_link_update(&bp->link_params, &bp->link_vars);
if (bp->link_vars.link_up) {
if (!CHIP_IS_E1(bp) && bp->dropless_fc) {
int port = BP_PORT(bp);
u32 pause_enabled = 0;
if (bp->link_vars.flow_ctrl & BNX2X_FLOW_CTRL_TX)
pause_enabled = 1;
REG_WR(bp, BAR_USTRORM_INTMEM +
USTORM_ETH_PAUSE_ENABLED_OFFSET(port),
pause_enabled);
}
if (bp->link_vars.mac_type != MAC_TYPE_EMAC) {
struct host_port_stats *pstats;
pstats = bnx2x_sp(bp, port_stats);
memset(&(pstats->mac_stx[0]), 0,
sizeof(struct mac_stx));
}
if (bp->state == BNX2X_STATE_OPEN)
bnx2x_stats_handle(bp, STATS_EVENT_LINK_UP);
}
if (bp->link_vars.link_up && bp->link_vars.line_speed) {
int cmng_fns = bnx2x_get_cmng_fns_mode(bp);
if (cmng_fns != CMNG_FNS_NONE) {
bnx2x_cmng_fns_init(bp, false, cmng_fns);
storm_memset_cmng(bp, &bp->cmng, BP_PORT(bp));
} else
DP(NETIF_MSG_IFUP,
"single function mode without fairness\n");
}
__bnx2x_link_report(bp);
if (IS_MF(bp))
bnx2x_link_sync_notify(bp);
}
void bnx2x__link_status_update(struct bnx2x *bp)
{
if (bp->state != BNX2X_STATE_OPEN)
return;
bnx2x_link_status_update(&bp->link_params, &bp->link_vars);
if (bp->link_vars.link_up)
bnx2x_stats_handle(bp, STATS_EVENT_LINK_UP);
else
bnx2x_stats_handle(bp, STATS_EVENT_STOP);
bnx2x_link_report(bp);
}
static void bnx2x_pmf_update(struct bnx2x *bp)
{
int port = BP_PORT(bp);
u32 val;
bp->port.pmf = 1;
DP(NETIF_MSG_LINK, "pmf %d\n", bp->port.pmf);
smp_mb();
queue_delayed_work(bnx2x_wq, &bp->period_task, 0);
bnx2x_dcbx_pmf_update(bp);
val = (0xff0f | (1 << (BP_VN(bp) + 4)));
if (bp->common.int_block == INT_BLOCK_HC) {
REG_WR(bp, HC_REG_TRAILING_EDGE_0 + port*8, val);
REG_WR(bp, HC_REG_LEADING_EDGE_0 + port*8, val);
} else if (!CHIP_IS_E1x(bp)) {
REG_WR(bp, IGU_REG_TRAILING_EDGE_LATCH, val);
REG_WR(bp, IGU_REG_LEADING_EDGE_LATCH, val);
}
bnx2x_stats_handle(bp, STATS_EVENT_PMF);
}
u32 bnx2x_fw_command(struct bnx2x *bp, u32 command, u32 param)
{
int mb_idx = BP_FW_MB_IDX(bp);
u32 seq;
u32 rc = 0;
u32 cnt = 1;
u8 delay = CHIP_REV_IS_SLOW(bp) ? 100 : 10;
mutex_lock(&bp->fw_mb_mutex);
seq = ++bp->fw_seq;
SHMEM_WR(bp, func_mb[mb_idx].drv_mb_param, param);
SHMEM_WR(bp, func_mb[mb_idx].drv_mb_header, (command | seq));
DP(BNX2X_MSG_MCP, "wrote command (%x) to FW MB param 0x%08x\n",
(command | seq), param);
do {
msleep(delay);
rc = SHMEM_RD(bp, func_mb[mb_idx].fw_mb_header);
} while ((seq != (rc & FW_MSG_SEQ_NUMBER_MASK)) && (cnt++ < 500));
DP(BNX2X_MSG_MCP, "[after %d ms] read (%x) seq is (%x) from FW MB\n",
cnt*delay, rc, seq);
if (seq == (rc & FW_MSG_SEQ_NUMBER_MASK))
rc &= FW_MSG_CODE_MASK;
else {
BNX2X_ERR("FW failed to respond!\n");
bnx2x_fw_dump(bp);
rc = 0;
}
mutex_unlock(&bp->fw_mb_mutex);
return rc;
}
static u8 stat_counter_valid(struct bnx2x *bp, struct bnx2x_fastpath *fp)
{
#ifdef BCM_CNIC
if (IS_FCOE_FP(fp))
return false;
#endif
return true;
}
void bnx2x_func_init(struct bnx2x *bp, struct bnx2x_func_init_params *p)
{
if (CHIP_IS_E1x(bp)) {
struct tstorm_eth_function_common_config tcfg = {0};
storm_memset_func_cfg(bp, &tcfg, p->func_id);
}
storm_memset_vf_to_pf(bp, p->func_id, p->pf_id);
storm_memset_func_en(bp, p->func_id, 1);
if (p->func_flgs & FUNC_FLG_SPQ) {
storm_memset_spq_addr(bp, p->spq_map, p->func_id);
REG_WR(bp, XSEM_REG_FAST_MEMORY +
XSTORM_SPQ_PROD_OFFSET(p->func_id), p->spq_prod);
}
}
static inline unsigned long bnx2x_get_common_flags(struct bnx2x *bp,
struct bnx2x_fastpath *fp,
bool zero_stats)
{
unsigned long flags = 0;
__set_bit(BNX2X_Q_FLG_ACTIVE, &flags);
if (stat_counter_valid(bp, fp)) {
__set_bit(BNX2X_Q_FLG_STATS, &flags);
if (zero_stats)
__set_bit(BNX2X_Q_FLG_ZERO_STATS, &flags);
}
return flags;
}
static inline unsigned long bnx2x_get_q_flags(struct bnx2x *bp,
struct bnx2x_fastpath *fp,
bool leading)
{
unsigned long flags = 0;
if (IS_MF_SD(bp))
__set_bit(BNX2X_Q_FLG_OV, &flags);
if (IS_FCOE_FP(fp))
__set_bit(BNX2X_Q_FLG_FCOE, &flags);
if (!fp->disable_tpa) {
__set_bit(BNX2X_Q_FLG_TPA, &flags);
__set_bit(BNX2X_Q_FLG_TPA_IPV6, &flags);
}
if (leading) {
__set_bit(BNX2X_Q_FLG_LEADING_RSS, &flags);
__set_bit(BNX2X_Q_FLG_MCAST, &flags);
}
__set_bit(BNX2X_Q_FLG_VLAN, &flags);
return flags | bnx2x_get_common_flags(bp, fp, true);
}
static void bnx2x_pf_q_prep_general(struct bnx2x *bp,
struct bnx2x_fastpath *fp, struct bnx2x_general_setup_params *gen_init,
u8 cos)
{
gen_init->stat_id = bnx2x_stats_id(fp);
gen_init->spcl_id = fp->cl_id;
if (IS_FCOE_FP(fp))
gen_init->mtu = BNX2X_FCOE_MINI_JUMBO_MTU;
else
gen_init->mtu = bp->dev->mtu;
gen_init->cos = cos;
}
static void bnx2x_pf_rx_q_prep(struct bnx2x *bp,
struct bnx2x_fastpath *fp, struct rxq_pause_params *pause,
struct bnx2x_rxq_setup_params *rxq_init)
{
u8 max_sge = 0;
u16 sge_sz = 0;
u16 tpa_agg_size = 0;
if (!fp->disable_tpa) {
pause->sge_th_lo = SGE_TH_LO(bp);
pause->sge_th_hi = SGE_TH_HI(bp);
WARN_ON(bp->dropless_fc &&
pause->sge_th_hi + FW_PREFETCH_CNT >
MAX_RX_SGE_CNT * NUM_RX_SGE_PAGES);
tpa_agg_size = min_t(u32,
(min_t(u32, 8, MAX_SKB_FRAGS) *
SGE_PAGE_SIZE * PAGES_PER_SGE), 0xffff);
max_sge = SGE_PAGE_ALIGN(bp->dev->mtu) >>
SGE_PAGE_SHIFT;
max_sge = ((max_sge + PAGES_PER_SGE - 1) &
(~(PAGES_PER_SGE-1))) >> PAGES_PER_SGE_SHIFT;
sge_sz = (u16)min_t(u32, SGE_PAGE_SIZE * PAGES_PER_SGE,
0xffff);
}
if (!CHIP_IS_E1(bp)) {
pause->bd_th_lo = BD_TH_LO(bp);
pause->bd_th_hi = BD_TH_HI(bp);
pause->rcq_th_lo = RCQ_TH_LO(bp);
pause->rcq_th_hi = RCQ_TH_HI(bp);
WARN_ON(bp->dropless_fc &&
pause->bd_th_hi + FW_PREFETCH_CNT >
bp->rx_ring_size);
WARN_ON(bp->dropless_fc &&
pause->rcq_th_hi + FW_PREFETCH_CNT >
NUM_RCQ_RINGS * MAX_RCQ_DESC_CNT);
pause->pri_map = 1;
}
rxq_init->dscr_map = fp->rx_desc_mapping;
rxq_init->sge_map = fp->rx_sge_mapping;
rxq_init->rcq_map = fp->rx_comp_mapping;
rxq_init->rcq_np_map = fp->rx_comp_mapping + BCM_PAGE_SIZE;
rxq_init->buf_sz = fp->rx_buf_size - BNX2X_FW_RX_ALIGN -
IP_HEADER_ALIGNMENT_PADDING;
rxq_init->cl_qzone_id = fp->cl_qzone_id;
rxq_init->tpa_agg_sz = tpa_agg_size;
rxq_init->sge_buf_sz = sge_sz;
rxq_init->max_sges_pkt = max_sge;
rxq_init->rss_engine_id = BP_FUNC(bp);
rxq_init->max_tpa_queues = MAX_AGG_QS(bp);
rxq_init->cache_line_log = BNX2X_RX_ALIGN_SHIFT;
rxq_init->fw_sb_id = fp->fw_sb_id;
if (IS_FCOE_FP(fp))
rxq_init->sb_cq_index = HC_SP_INDEX_ETH_FCOE_RX_CQ_CONS;
else
rxq_init->sb_cq_index = HC_INDEX_ETH_RX_CQ_CONS;
}
static void bnx2x_pf_tx_q_prep(struct bnx2x *bp,
struct bnx2x_fastpath *fp, struct bnx2x_txq_setup_params *txq_init,
u8 cos)
{
txq_init->dscr_map = fp->txdata[cos].tx_desc_mapping;
txq_init->sb_cq_index = HC_INDEX_ETH_FIRST_TX_CQ_CONS + cos;
txq_init->traffic_type = LLFC_TRAFFIC_TYPE_NW;
txq_init->fw_sb_id = fp->fw_sb_id;
txq_init->tss_leading_cl_id = bnx2x_fp(bp, 0, cl_id);
if (IS_FCOE_FP(fp)) {
txq_init->sb_cq_index = HC_SP_INDEX_ETH_FCOE_TX_CQ_CONS;
txq_init->traffic_type = LLFC_TRAFFIC_TYPE_FCOE;
}
}
static void bnx2x_pf_init(struct bnx2x *bp)
{
struct bnx2x_func_init_params func_init = {0};
struct event_ring_data eq_data = { {0} };
u16 flags;
if (!CHIP_IS_E1x(bp)) {
REG_WR(bp, IGU_REG_STATISTIC_NUM_MESSAGE_SENT +
BNX2X_IGU_STAS_MSG_VF_CNT*4 +
(CHIP_MODE_IS_4_PORT(bp) ?
BP_FUNC(bp) : BP_VN(bp))*4, 0);
REG_WR(bp, IGU_REG_STATISTIC_NUM_MESSAGE_SENT +
BNX2X_IGU_STAS_MSG_VF_CNT*4 +
BNX2X_IGU_STAS_MSG_PF_CNT*4 +
(CHIP_MODE_IS_4_PORT(bp) ?
BP_FUNC(bp) : BP_VN(bp))*4, 0);
}
flags = (FUNC_FLG_STATS | FUNC_FLG_LEADING | FUNC_FLG_SPQ);
flags |= (bp->flags & TPA_ENABLE_FLAG) ? FUNC_FLG_TPA : 0;
func_init.func_flgs = flags;
func_init.pf_id = BP_FUNC(bp);
func_init.func_id = BP_FUNC(bp);
func_init.spq_map = bp->spq_mapping;
func_init.spq_prod = bp->spq_prod_idx;
bnx2x_func_init(bp, &func_init);
memset(&(bp->cmng), 0, sizeof(struct cmng_struct_per_port));
bp->link_vars.line_speed = SPEED_10000;
bnx2x_cmng_fns_init(bp, true, bnx2x_get_cmng_fns_mode(bp));
if (bp->port.pmf)
storm_memset_cmng(bp, &bp->cmng, BP_PORT(bp));
eq_data.base_addr.hi = U64_HI(bp->eq_mapping);
eq_data.base_addr.lo = U64_LO(bp->eq_mapping);
eq_data.producer = bp->eq_prod;
eq_data.index_id = HC_SP_INDEX_EQ_CONS;
eq_data.sb_id = DEF_SB_ID;
storm_memset_eq_data(bp, &eq_data, BP_FUNC(bp));
}
static void bnx2x_e1h_disable(struct bnx2x *bp)
{
int port = BP_PORT(bp);
bnx2x_tx_disable(bp);
REG_WR(bp, NIG_REG_LLH0_FUNC_EN + port*8, 0);
}
static void bnx2x_e1h_enable(struct bnx2x *bp)
{
int port = BP_PORT(bp);
REG_WR(bp, NIG_REG_LLH0_FUNC_EN + port*8, 1);
netif_tx_wake_all_queues(bp->dev);
}
static inline void bnx2x_config_mf_bw(struct bnx2x *bp)
{
if (bp->link_vars.link_up) {
bnx2x_cmng_fns_init(bp, true, CMNG_FNS_MINMAX);
bnx2x_link_sync_notify(bp);
}
storm_memset_cmng(bp, &bp->cmng, BP_PORT(bp));
}
static inline void bnx2x_set_mf_bw(struct bnx2x *bp)
{
bnx2x_config_mf_bw(bp);
bnx2x_fw_command(bp, DRV_MSG_CODE_SET_MF_BW_ACK, 0);
}
static void bnx2x_dcc_event(struct bnx2x *bp, u32 dcc_event)
{
DP(BNX2X_MSG_MCP, "dcc_event 0x%x\n", dcc_event);
if (dcc_event & DRV_STATUS_DCC_DISABLE_ENABLE_PF) {
if (bp->mf_config[BP_VN(bp)] & FUNC_MF_CFG_FUNC_DISABLED) {
DP(NETIF_MSG_IFDOWN, "mf_cfg function disabled\n");
bp->flags |= MF_FUNC_DIS;
bnx2x_e1h_disable(bp);
} else {
DP(NETIF_MSG_IFUP, "mf_cfg function enabled\n");
bp->flags &= ~MF_FUNC_DIS;
bnx2x_e1h_enable(bp);
}
dcc_event &= ~DRV_STATUS_DCC_DISABLE_ENABLE_PF;
}
if (dcc_event & DRV_STATUS_DCC_BANDWIDTH_ALLOCATION) {
bnx2x_config_mf_bw(bp);
dcc_event &= ~DRV_STATUS_DCC_BANDWIDTH_ALLOCATION;
}
if (dcc_event)
bnx2x_fw_command(bp, DRV_MSG_CODE_DCC_FAILURE, 0);
else
bnx2x_fw_command(bp, DRV_MSG_CODE_DCC_OK, 0);
}
static inline struct eth_spe *bnx2x_sp_get_next(struct bnx2x *bp)
{
struct eth_spe *next_spe = bp->spq_prod_bd;
if (bp->spq_prod_bd == bp->spq_last_bd) {
bp->spq_prod_bd = bp->spq;
bp->spq_prod_idx = 0;
DP(NETIF_MSG_TIMER, "end of spq\n");
} else {
bp->spq_prod_bd++;
bp->spq_prod_idx++;
}
return next_spe;
}
static inline void bnx2x_sp_prod_update(struct bnx2x *bp)
{
int func = BP_FUNC(bp);
mb();
REG_WR16(bp, BAR_XSTRORM_INTMEM + XSTORM_SPQ_PROD_OFFSET(func),
bp->spq_prod_idx);
mmiowb();
}
static inline bool bnx2x_is_contextless_ramrod(int cmd, int cmd_type)
{
if ((cmd_type == NONE_CONNECTION_TYPE) ||
(cmd == RAMROD_CMD_ID_ETH_FORWARD_SETUP) ||
(cmd == RAMROD_CMD_ID_ETH_CLASSIFICATION_RULES) ||
(cmd == RAMROD_CMD_ID_ETH_FILTER_RULES) ||
(cmd == RAMROD_CMD_ID_ETH_MULTICAST_RULES) ||
(cmd == RAMROD_CMD_ID_ETH_SET_MAC) ||
(cmd == RAMROD_CMD_ID_ETH_RSS_UPDATE))
return true;
else
return false;
}
int bnx2x_sp_post(struct bnx2x *bp, int command, int cid,
u32 data_hi, u32 data_lo, int cmd_type)
{
struct eth_spe *spe;
u16 type;
bool common = bnx2x_is_contextless_ramrod(command, cmd_type);
#ifdef BNX2X_STOP_ON_ERROR
if (unlikely(bp->panic))
return -EIO;
#endif
spin_lock_bh(&bp->spq_lock);
if (common) {
if (!atomic_read(&bp->eq_spq_left)) {
BNX2X_ERR("BUG! EQ ring full!\n");
spin_unlock_bh(&bp->spq_lock);
bnx2x_panic();
return -EBUSY;
}
} else if (!atomic_read(&bp->cq_spq_left)) {
BNX2X_ERR("BUG! SPQ ring full!\n");
spin_unlock_bh(&bp->spq_lock);
bnx2x_panic();
return -EBUSY;
}
spe = bnx2x_sp_get_next(bp);
spe->hdr.conn_and_cmd_data =
cpu_to_le32((command << SPE_HDR_CMD_ID_SHIFT) |
HW_CID(bp, cid));
type = (cmd_type << SPE_HDR_CONN_TYPE_SHIFT) & SPE_HDR_CONN_TYPE;
type |= ((BP_FUNC(bp) << SPE_HDR_FUNCTION_ID_SHIFT) &
SPE_HDR_FUNCTION_ID);
spe->hdr.type = cpu_to_le16(type);
spe->data.update_data_addr.hi = cpu_to_le32(data_hi);
spe->data.update_data_addr.lo = cpu_to_le32(data_lo);
if (common)
atomic_dec(&bp->eq_spq_left);
else
atomic_dec(&bp->cq_spq_left);
DP(BNX2X_MSG_SP,
"SPQE[%x] (%x:%x) (cmd, common?) (%d,%d) hw_cid %x data (%x:%x) "
"type(0x%x) left (CQ, EQ) (%x,%x)\n",
bp->spq_prod_idx, (u32)U64_HI(bp->spq_mapping),
(u32)(U64_LO(bp->spq_mapping) +
(void *)bp->spq_prod_bd - (void *)bp->spq), command, common,
HW_CID(bp, cid), data_hi, data_lo, type,
atomic_read(&bp->cq_spq_left), atomic_read(&bp->eq_spq_left));
bnx2x_sp_prod_update(bp);
spin_unlock_bh(&bp->spq_lock);
return 0;
}
static int bnx2x_acquire_alr(struct bnx2x *bp)
{
u32 j, val;
int rc = 0;
might_sleep();
for (j = 0; j < 1000; j++) {
val = (1UL << 31);
REG_WR(bp, GRCBASE_MCP + 0x9c, val);
val = REG_RD(bp, GRCBASE_MCP + 0x9c);
if (val & (1L << 31))
break;
msleep(5);
}
if (!(val & (1L << 31))) {
BNX2X_ERR("Cannot acquire MCP access lock register\n");
rc = -EBUSY;
}
return rc;
}
static void bnx2x_release_alr(struct bnx2x *bp)
{
REG_WR(bp, GRCBASE_MCP + 0x9c, 0);
}
static inline u16 bnx2x_update_dsb_idx(struct bnx2x *bp)
{
struct host_sp_status_block *def_sb = bp->def_status_blk;
u16 rc = 0;
barrier();
if (bp->def_att_idx != def_sb->atten_status_block.attn_bits_index) {
bp->def_att_idx = def_sb->atten_status_block.attn_bits_index;
rc |= BNX2X_DEF_SB_ATT_IDX;
}
if (bp->def_idx != def_sb->sp_sb.running_index) {
bp->def_idx = def_sb->sp_sb.running_index;
rc |= BNX2X_DEF_SB_IDX;
}
barrier();
return rc;
}
static void bnx2x_attn_int_asserted(struct bnx2x *bp, u32 asserted)
{
int port = BP_PORT(bp);
u32 aeu_addr = port ? MISC_REG_AEU_MASK_ATTN_FUNC_1 :
MISC_REG_AEU_MASK_ATTN_FUNC_0;
u32 nig_int_mask_addr = port ? NIG_REG_MASK_INTERRUPT_PORT1 :
NIG_REG_MASK_INTERRUPT_PORT0;
u32 aeu_mask;
u32 nig_mask = 0;
u32 reg_addr;
if (bp->attn_state & asserted)
BNX2X_ERR("IGU ERROR\n");
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_PORT0_ATT_MASK + port);
aeu_mask = REG_RD(bp, aeu_addr);
DP(NETIF_MSG_HW, "aeu_mask %x newly asserted %x\n",
aeu_mask, asserted);
aeu_mask &= ~(asserted & 0x3ff);
DP(NETIF_MSG_HW, "new mask %x\n", aeu_mask);
REG_WR(bp, aeu_addr, aeu_mask);
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_PORT0_ATT_MASK + port);
DP(NETIF_MSG_HW, "attn_state %x\n", bp->attn_state);
bp->attn_state |= asserted;
DP(NETIF_MSG_HW, "new state %x\n", bp->attn_state);
if (asserted & ATTN_HARD_WIRED_MASK) {
if (asserted & ATTN_NIG_FOR_FUNC) {
bnx2x_acquire_phy_lock(bp);
nig_mask = REG_RD(bp, nig_int_mask_addr);
if (nig_mask) {
REG_WR(bp, nig_int_mask_addr, 0);
bnx2x_link_attn(bp);
}
}
if (asserted & ATTN_SW_TIMER_4_FUNC)
DP(NETIF_MSG_HW, "ATTN_SW_TIMER_4_FUNC!\n");
if (asserted & GPIO_2_FUNC)
DP(NETIF_MSG_HW, "GPIO_2_FUNC!\n");
if (asserted & GPIO_3_FUNC)
DP(NETIF_MSG_HW, "GPIO_3_FUNC!\n");
if (asserted & GPIO_4_FUNC)
DP(NETIF_MSG_HW, "GPIO_4_FUNC!\n");
if (port == 0) {
if (asserted & ATTN_GENERAL_ATTN_1) {
DP(NETIF_MSG_HW, "ATTN_GENERAL_ATTN_1!\n");
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_1, 0x0);
}
if (asserted & ATTN_GENERAL_ATTN_2) {
DP(NETIF_MSG_HW, "ATTN_GENERAL_ATTN_2!\n");
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_2, 0x0);
}
if (asserted & ATTN_GENERAL_ATTN_3) {
DP(NETIF_MSG_HW, "ATTN_GENERAL_ATTN_3!\n");
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_3, 0x0);
}
} else {
if (asserted & ATTN_GENERAL_ATTN_4) {
DP(NETIF_MSG_HW, "ATTN_GENERAL_ATTN_4!\n");
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_4, 0x0);
}
if (asserted & ATTN_GENERAL_ATTN_5) {
DP(NETIF_MSG_HW, "ATTN_GENERAL_ATTN_5!\n");
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_5, 0x0);
}
if (asserted & ATTN_GENERAL_ATTN_6) {
DP(NETIF_MSG_HW, "ATTN_GENERAL_ATTN_6!\n");
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_6, 0x0);
}
}
}
if (bp->common.int_block == INT_BLOCK_HC)
reg_addr = (HC_REG_COMMAND_REG + port*32 +
COMMAND_REG_ATTN_BITS_SET);
else
reg_addr = (BAR_IGU_INTMEM + IGU_CMD_ATTN_BIT_SET_UPPER*8);
DP(NETIF_MSG_HW, "about to mask 0x%08x at %s addr 0x%x\n", asserted,
(bp->common.int_block == INT_BLOCK_HC) ? "HC" : "IGU", reg_addr);
REG_WR(bp, reg_addr, asserted);
if (asserted & ATTN_NIG_FOR_FUNC) {
REG_WR(bp, nig_int_mask_addr, nig_mask);
bnx2x_release_phy_lock(bp);
}
}
static inline void bnx2x_fan_failure(struct bnx2x *bp)
{
int port = BP_PORT(bp);
u32 ext_phy_config;
ext_phy_config =
SHMEM_RD(bp,
dev_info.port_hw_config[port].external_phy_config);
ext_phy_config &= ~PORT_HW_CFG_XGXS_EXT_PHY_TYPE_MASK;
ext_phy_config |= PORT_HW_CFG_XGXS_EXT_PHY_TYPE_FAILURE;
SHMEM_WR(bp, dev_info.port_hw_config[port].external_phy_config,
ext_phy_config);
netdev_err(bp->dev, "Fan Failure on Network Controller has caused"
" the driver to shutdown the card to prevent permanent"
" damage. Please contact OEM Support for assistance\n");
}
static inline void bnx2x_attn_int_deasserted0(struct bnx2x *bp, u32 attn)
{
int port = BP_PORT(bp);
int reg_offset;
u32 val;
reg_offset = (port ? MISC_REG_AEU_ENABLE1_FUNC_1_OUT_0 :
MISC_REG_AEU_ENABLE1_FUNC_0_OUT_0);
if (attn & AEU_INPUTS_ATTN_BITS_SPIO5) {
val = REG_RD(bp, reg_offset);
val &= ~AEU_INPUTS_ATTN_BITS_SPIO5;
REG_WR(bp, reg_offset, val);
BNX2X_ERR("SPIO5 hw attention\n");
bnx2x_hw_reset_phy(&bp->link_params);
bnx2x_fan_failure(bp);
}
if ((attn & bp->link_vars.aeu_int_mask) && bp->port.pmf) {
bnx2x_acquire_phy_lock(bp);
bnx2x_handle_module_detect_int(&bp->link_params);
bnx2x_release_phy_lock(bp);
}
if (attn & HW_INTERRUT_ASSERT_SET_0) {
val = REG_RD(bp, reg_offset);
val &= ~(attn & HW_INTERRUT_ASSERT_SET_0);
REG_WR(bp, reg_offset, val);
BNX2X_ERR("FATAL HW block attention set0 0x%x\n",
(u32)(attn & HW_INTERRUT_ASSERT_SET_0));
bnx2x_panic();
}
}
static inline void bnx2x_attn_int_deasserted1(struct bnx2x *bp, u32 attn)
{
u32 val;
if (attn & AEU_INPUTS_ATTN_BITS_DOORBELLQ_HW_INTERRUPT) {
val = REG_RD(bp, DORQ_REG_DORQ_INT_STS_CLR);
BNX2X_ERR("DB hw attention 0x%x\n", val);
if (val & 0x2)
BNX2X_ERR("FATAL error from DORQ\n");
}
if (attn & HW_INTERRUT_ASSERT_SET_1) {
int port = BP_PORT(bp);
int reg_offset;
reg_offset = (port ? MISC_REG_AEU_ENABLE1_FUNC_1_OUT_1 :
MISC_REG_AEU_ENABLE1_FUNC_0_OUT_1);
val = REG_RD(bp, reg_offset);
val &= ~(attn & HW_INTERRUT_ASSERT_SET_1);
REG_WR(bp, reg_offset, val);
BNX2X_ERR("FATAL HW block attention set1 0x%x\n",
(u32)(attn & HW_INTERRUT_ASSERT_SET_1));
bnx2x_panic();
}
}
static inline void bnx2x_attn_int_deasserted2(struct bnx2x *bp, u32 attn)
{
u32 val;
if (attn & AEU_INPUTS_ATTN_BITS_CFC_HW_INTERRUPT) {
val = REG_RD(bp, CFC_REG_CFC_INT_STS_CLR);
BNX2X_ERR("CFC hw attention 0x%x\n", val);
if (val & 0x2)
BNX2X_ERR("FATAL error from CFC\n");
}
if (attn & AEU_INPUTS_ATTN_BITS_PXP_HW_INTERRUPT) {
val = REG_RD(bp, PXP_REG_PXP_INT_STS_CLR_0);
BNX2X_ERR("PXP hw attention-0 0x%x\n", val);
if (val & 0x18000)
BNX2X_ERR("FATAL error from PXP\n");
if (!CHIP_IS_E1x(bp)) {
val = REG_RD(bp, PXP_REG_PXP_INT_STS_CLR_1);
BNX2X_ERR("PXP hw attention-1 0x%x\n", val);
}
}
if (attn & HW_INTERRUT_ASSERT_SET_2) {
int port = BP_PORT(bp);
int reg_offset;
reg_offset = (port ? MISC_REG_AEU_ENABLE1_FUNC_1_OUT_2 :
MISC_REG_AEU_ENABLE1_FUNC_0_OUT_2);
val = REG_RD(bp, reg_offset);
val &= ~(attn & HW_INTERRUT_ASSERT_SET_2);
REG_WR(bp, reg_offset, val);
BNX2X_ERR("FATAL HW block attention set2 0x%x\n",
(u32)(attn & HW_INTERRUT_ASSERT_SET_2));
bnx2x_panic();
}
}
static inline void bnx2x_attn_int_deasserted3(struct bnx2x *bp, u32 attn)
{
u32 val;
if (attn & EVEREST_GEN_ATTN_IN_USE_MASK) {
if (attn & BNX2X_PMF_LINK_ASSERT) {
int func = BP_FUNC(bp);
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_12 + func*4, 0);
bp->mf_config[BP_VN(bp)] = MF_CFG_RD(bp,
func_mf_config[BP_ABS_FUNC(bp)].config);
val = SHMEM_RD(bp,
func_mb[BP_FW_MB_IDX(bp)].drv_status);
if (val & DRV_STATUS_DCC_EVENT_MASK)
bnx2x_dcc_event(bp,
(val & DRV_STATUS_DCC_EVENT_MASK));
if (val & DRV_STATUS_SET_MF_BW)
bnx2x_set_mf_bw(bp);
if ((bp->port.pmf == 0) && (val & DRV_STATUS_PMF))
bnx2x_pmf_update(bp);
if (bp->port.pmf &&
(val & DRV_STATUS_DCBX_NEGOTIATION_RESULTS) &&
bp->dcbx_enabled > 0)
bnx2x_dcbx_set_params(bp,
BNX2X_DCBX_STATE_NEG_RECEIVED);
if (bp->link_vars.periodic_flags &
PERIODIC_FLAGS_LINK_EVENT) {
bnx2x_acquire_phy_lock(bp);
bp->link_vars.periodic_flags &=
~PERIODIC_FLAGS_LINK_EVENT;
bnx2x_release_phy_lock(bp);
if (IS_MF(bp))
bnx2x_link_sync_notify(bp);
bnx2x_link_report(bp);
}
bnx2x__link_status_update(bp);
} else if (attn & BNX2X_MC_ASSERT_BITS) {
BNX2X_ERR("MC assert!\n");
bnx2x_mc_assert(bp);
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_10, 0);
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_9, 0);
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_8, 0);
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_7, 0);
bnx2x_panic();
} else if (attn & BNX2X_MCP_ASSERT) {
BNX2X_ERR("MCP assert!\n");
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_11, 0);
bnx2x_fw_dump(bp);
} else
BNX2X_ERR("Unknown HW assert! (attn 0x%x)\n", attn);
}
if (attn & EVEREST_LATCHED_ATTN_IN_USE_MASK) {
BNX2X_ERR("LATCHED attention 0x%08x (masked)\n", attn);
if (attn & BNX2X_GRC_TIMEOUT) {
val = CHIP_IS_E1(bp) ? 0 :
REG_RD(bp, MISC_REG_GRC_TIMEOUT_ATTN);
BNX2X_ERR("GRC time-out 0x%08x\n", val);
}
if (attn & BNX2X_GRC_RSV) {
val = CHIP_IS_E1(bp) ? 0 :
REG_RD(bp, MISC_REG_GRC_RSV_ATTN);
BNX2X_ERR("GRC reserved 0x%08x\n", val);
}
REG_WR(bp, MISC_REG_AEU_CLR_LATCH_SIGNAL, 0x7ff);
}
}
void bnx2x_set_reset_global(struct bnx2x *bp)
{
u32 val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
REG_WR(bp, BNX2X_RECOVERY_GLOB_REG, val | BNX2X_GLOBAL_RESET_BIT);
barrier();
mmiowb();
}
static inline void bnx2x_clear_reset_global(struct bnx2x *bp)
{
u32 val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
REG_WR(bp, BNX2X_RECOVERY_GLOB_REG, val & (~BNX2X_GLOBAL_RESET_BIT));
barrier();
mmiowb();
}
static inline bool bnx2x_reset_is_global(struct bnx2x *bp)
{
u32 val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
DP(NETIF_MSG_HW, "GEN_REG_VAL=0x%08x\n", val);
return (val & BNX2X_GLOBAL_RESET_BIT) ? true : false;
}
static inline void bnx2x_set_reset_done(struct bnx2x *bp)
{
u32 val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
u32 bit = BP_PATH(bp) ?
BNX2X_PATH1_RST_IN_PROG_BIT : BNX2X_PATH0_RST_IN_PROG_BIT;
val &= ~bit;
REG_WR(bp, BNX2X_RECOVERY_GLOB_REG, val);
barrier();
mmiowb();
}
void bnx2x_set_reset_in_progress(struct bnx2x *bp)
{
u32 val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
u32 bit = BP_PATH(bp) ?
BNX2X_PATH1_RST_IN_PROG_BIT : BNX2X_PATH0_RST_IN_PROG_BIT;
val |= bit;
REG_WR(bp, BNX2X_RECOVERY_GLOB_REG, val);
barrier();
mmiowb();
}
bool bnx2x_reset_is_done(struct bnx2x *bp, int engine)
{
u32 val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
u32 bit = engine ?
BNX2X_PATH1_RST_IN_PROG_BIT : BNX2X_PATH0_RST_IN_PROG_BIT;
return (val & bit) ? false : true;
}
void bnx2x_inc_load_cnt(struct bnx2x *bp)
{
u32 val1, val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
u32 mask = BP_PATH(bp) ? BNX2X_PATH1_LOAD_CNT_MASK :
BNX2X_PATH0_LOAD_CNT_MASK;
u32 shift = BP_PATH(bp) ? BNX2X_PATH1_LOAD_CNT_SHIFT :
BNX2X_PATH0_LOAD_CNT_SHIFT;
DP(NETIF_MSG_HW, "Old GEN_REG_VAL=0x%08x\n", val);
val1 = (val & mask) >> shift;
val1++;
val &= ~mask;
val |= ((val1 << shift) & mask);
REG_WR(bp, BNX2X_RECOVERY_GLOB_REG, val);
barrier();
mmiowb();
}
u32 bnx2x_dec_load_cnt(struct bnx2x *bp)
{
u32 val1, val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
u32 mask = BP_PATH(bp) ? BNX2X_PATH1_LOAD_CNT_MASK :
BNX2X_PATH0_LOAD_CNT_MASK;
u32 shift = BP_PATH(bp) ? BNX2X_PATH1_LOAD_CNT_SHIFT :
BNX2X_PATH0_LOAD_CNT_SHIFT;
DP(NETIF_MSG_HW, "Old GEN_REG_VAL=0x%08x\n", val);
val1 = (val & mask) >> shift;
val1--;
val &= ~mask;
val |= ((val1 << shift) & mask);
REG_WR(bp, BNX2X_RECOVERY_GLOB_REG, val);
barrier();
mmiowb();
return val1;
}
static inline u32 bnx2x_get_load_cnt(struct bnx2x *bp, int engine)
{
u32 mask = (engine ? BNX2X_PATH1_LOAD_CNT_MASK :
BNX2X_PATH0_LOAD_CNT_MASK);
u32 shift = (engine ? BNX2X_PATH1_LOAD_CNT_SHIFT :
BNX2X_PATH0_LOAD_CNT_SHIFT);
u32 val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
DP(NETIF_MSG_HW, "GLOB_REG=0x%08x\n", val);
val = (val & mask) >> shift;
DP(NETIF_MSG_HW, "load_cnt for engine %d = %d\n", engine, val);
return val;
}
static inline void bnx2x_clear_load_cnt(struct bnx2x *bp)
{
u32 val = REG_RD(bp, BNX2X_RECOVERY_GLOB_REG);
u32 mask = (BP_PATH(bp) ? BNX2X_PATH1_LOAD_CNT_MASK :
BNX2X_PATH0_LOAD_CNT_MASK);
REG_WR(bp, BNX2X_RECOVERY_GLOB_REG, val & (~mask));
}
static inline void _print_next_block(int idx, const char *blk)
{
pr_cont("%s%s", idx ? ", " : "", blk);
}
static inline int bnx2x_check_blocks_with_parity0(u32 sig, int par_num,
bool print)
{
int i = 0;
u32 cur_bit = 0;
for (i = 0; sig; i++) {
cur_bit = ((u32)0x1 << i);
if (sig & cur_bit) {
switch (cur_bit) {
case AEU_INPUTS_ATTN_BITS_BRB_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "BRB");
break;
case AEU_INPUTS_ATTN_BITS_PARSER_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "PARSER");
break;
case AEU_INPUTS_ATTN_BITS_TSDM_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "TSDM");
break;
case AEU_INPUTS_ATTN_BITS_SEARCHER_PARITY_ERROR:
if (print)
_print_next_block(par_num++,
"SEARCHER");
break;
case AEU_INPUTS_ATTN_BITS_TCM_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "TCM");
break;
case AEU_INPUTS_ATTN_BITS_TSEMI_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "TSEMI");
break;
case AEU_INPUTS_ATTN_BITS_PBCLIENT_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "XPB");
break;
}
sig &= ~cur_bit;
}
}
return par_num;
}
static inline int bnx2x_check_blocks_with_parity1(u32 sig, int par_num,
bool *global, bool print)
{
int i = 0;
u32 cur_bit = 0;
for (i = 0; sig; i++) {
cur_bit = ((u32)0x1 << i);
if (sig & cur_bit) {
switch (cur_bit) {
case AEU_INPUTS_ATTN_BITS_PBF_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "PBF");
break;
case AEU_INPUTS_ATTN_BITS_QM_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "QM");
break;
case AEU_INPUTS_ATTN_BITS_TIMERS_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "TM");
break;
case AEU_INPUTS_ATTN_BITS_XSDM_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "XSDM");
break;
case AEU_INPUTS_ATTN_BITS_XCM_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "XCM");
break;
case AEU_INPUTS_ATTN_BITS_XSEMI_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "XSEMI");
break;
case AEU_INPUTS_ATTN_BITS_DOORBELLQ_PARITY_ERROR:
if (print)
_print_next_block(par_num++,
"DOORBELLQ");
break;
case AEU_INPUTS_ATTN_BITS_NIG_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "NIG");
break;
case AEU_INPUTS_ATTN_BITS_VAUX_PCI_CORE_PARITY_ERROR:
if (print)
_print_next_block(par_num++,
"VAUX PCI CORE");
*global = true;
break;
case AEU_INPUTS_ATTN_BITS_DEBUG_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "DEBUG");
break;
case AEU_INPUTS_ATTN_BITS_USDM_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "USDM");
break;
case AEU_INPUTS_ATTN_BITS_UCM_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "UCM");
break;
case AEU_INPUTS_ATTN_BITS_USEMI_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "USEMI");
break;
case AEU_INPUTS_ATTN_BITS_UPB_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "UPB");
break;
case AEU_INPUTS_ATTN_BITS_CSDM_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "CSDM");
break;
case AEU_INPUTS_ATTN_BITS_CCM_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "CCM");
break;
}
sig &= ~cur_bit;
}
}
return par_num;
}
static inline int bnx2x_check_blocks_with_parity2(u32 sig, int par_num,
bool print)
{
int i = 0;
u32 cur_bit = 0;
for (i = 0; sig; i++) {
cur_bit = ((u32)0x1 << i);
if (sig & cur_bit) {
switch (cur_bit) {
case AEU_INPUTS_ATTN_BITS_CSEMI_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "CSEMI");
break;
case AEU_INPUTS_ATTN_BITS_PXP_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "PXP");
break;
case AEU_IN_ATTN_BITS_PXPPCICLOCKCLIENT_PARITY_ERROR:
if (print)
_print_next_block(par_num++,
"PXPPCICLOCKCLIENT");
break;
case AEU_INPUTS_ATTN_BITS_CFC_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "CFC");
break;
case AEU_INPUTS_ATTN_BITS_CDU_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "CDU");
break;
case AEU_INPUTS_ATTN_BITS_DMAE_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "DMAE");
break;
case AEU_INPUTS_ATTN_BITS_IGU_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "IGU");
break;
case AEU_INPUTS_ATTN_BITS_MISC_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "MISC");
break;
}
sig &= ~cur_bit;
}
}
return par_num;
}
static inline int bnx2x_check_blocks_with_parity3(u32 sig, int par_num,
bool *global, bool print)
{
int i = 0;
u32 cur_bit = 0;
for (i = 0; sig; i++) {
cur_bit = ((u32)0x1 << i);
if (sig & cur_bit) {
switch (cur_bit) {
case AEU_INPUTS_ATTN_BITS_MCP_LATCHED_ROM_PARITY:
if (print)
_print_next_block(par_num++, "MCP ROM");
*global = true;
break;
case AEU_INPUTS_ATTN_BITS_MCP_LATCHED_UMP_RX_PARITY:
if (print)
_print_next_block(par_num++,
"MCP UMP RX");
*global = true;
break;
case AEU_INPUTS_ATTN_BITS_MCP_LATCHED_UMP_TX_PARITY:
if (print)
_print_next_block(par_num++,
"MCP UMP TX");
*global = true;
break;
case AEU_INPUTS_ATTN_BITS_MCP_LATCHED_SCPAD_PARITY:
if (print)
_print_next_block(par_num++,
"MCP SCPAD");
*global = true;
break;
}
sig &= ~cur_bit;
}
}
return par_num;
}
static inline int bnx2x_check_blocks_with_parity4(u32 sig, int par_num,
bool print)
{
int i = 0;
u32 cur_bit = 0;
for (i = 0; sig; i++) {
cur_bit = ((u32)0x1 << i);
if (sig & cur_bit) {
switch (cur_bit) {
case AEU_INPUTS_ATTN_BITS_PGLUE_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "PGLUE_B");
break;
case AEU_INPUTS_ATTN_BITS_ATC_PARITY_ERROR:
if (print)
_print_next_block(par_num++, "ATC");
break;
}
sig &= ~cur_bit;
}
}
return par_num;
}
static inline bool bnx2x_parity_attn(struct bnx2x *bp, bool *global, bool print,
u32 *sig)
{
if ((sig[0] & HW_PRTY_ASSERT_SET_0) ||
(sig[1] & HW_PRTY_ASSERT_SET_1) ||
(sig[2] & HW_PRTY_ASSERT_SET_2) ||
(sig[3] & HW_PRTY_ASSERT_SET_3) ||
(sig[4] & HW_PRTY_ASSERT_SET_4)) {
int par_num = 0;
DP(NETIF_MSG_HW, "Was parity error: HW block parity attention: "
"[0]:0x%08x [1]:0x%08x [2]:0x%08x [3]:0x%08x "
"[4]:0x%08x\n",
sig[0] & HW_PRTY_ASSERT_SET_0,
sig[1] & HW_PRTY_ASSERT_SET_1,
sig[2] & HW_PRTY_ASSERT_SET_2,
sig[3] & HW_PRTY_ASSERT_SET_3,
sig[4] & HW_PRTY_ASSERT_SET_4);
if (print)
netdev_err(bp->dev,
"Parity errors detected in blocks: ");
par_num = bnx2x_check_blocks_with_parity0(
sig[0] & HW_PRTY_ASSERT_SET_0, par_num, print);
par_num = bnx2x_check_blocks_with_parity1(
sig[1] & HW_PRTY_ASSERT_SET_1, par_num, global, print);
par_num = bnx2x_check_blocks_with_parity2(
sig[2] & HW_PRTY_ASSERT_SET_2, par_num, print);
par_num = bnx2x_check_blocks_with_parity3(
sig[3] & HW_PRTY_ASSERT_SET_3, par_num, global, print);
par_num = bnx2x_check_blocks_with_parity4(
sig[4] & HW_PRTY_ASSERT_SET_4, par_num, print);
if (print)
pr_cont("\n");
return true;
} else
return false;
}
bool bnx2x_chk_parity_attn(struct bnx2x *bp, bool *global, bool print)
{
struct attn_route attn = { {0} };
int port = BP_PORT(bp);
attn.sig[0] = REG_RD(bp,
MISC_REG_AEU_AFTER_INVERT_1_FUNC_0 +
port*4);
attn.sig[1] = REG_RD(bp,
MISC_REG_AEU_AFTER_INVERT_2_FUNC_0 +
port*4);
attn.sig[2] = REG_RD(bp,
MISC_REG_AEU_AFTER_INVERT_3_FUNC_0 +
port*4);
attn.sig[3] = REG_RD(bp,
MISC_REG_AEU_AFTER_INVERT_4_FUNC_0 +
port*4);
if (!CHIP_IS_E1x(bp))
attn.sig[4] = REG_RD(bp,
MISC_REG_AEU_AFTER_INVERT_5_FUNC_0 +
port*4);
return bnx2x_parity_attn(bp, global, print, attn.sig);
}
static inline void bnx2x_attn_int_deasserted4(struct bnx2x *bp, u32 attn)
{
u32 val;
if (attn & AEU_INPUTS_ATTN_BITS_PGLUE_HW_INTERRUPT) {
val = REG_RD(bp, PGLUE_B_REG_PGLUE_B_INT_STS_CLR);
BNX2X_ERR("PGLUE hw attention 0x%x\n", val);
if (val & PGLUE_B_PGLUE_B_INT_STS_REG_ADDRESS_ERROR)
BNX2X_ERR("PGLUE_B_PGLUE_B_INT_STS_REG_"
"ADDRESS_ERROR\n");
if (val & PGLUE_B_PGLUE_B_INT_STS_REG_INCORRECT_RCV_BEHAVIOR)
BNX2X_ERR("PGLUE_B_PGLUE_B_INT_STS_REG_"
"INCORRECT_RCV_BEHAVIOR\n");
if (val & PGLUE_B_PGLUE_B_INT_STS_REG_WAS_ERROR_ATTN)
BNX2X_ERR("PGLUE_B_PGLUE_B_INT_STS_REG_"
"WAS_ERROR_ATTN\n");
if (val & PGLUE_B_PGLUE_B_INT_STS_REG_VF_LENGTH_VIOLATION_ATTN)
BNX2X_ERR("PGLUE_B_PGLUE_B_INT_STS_REG_"
"VF_LENGTH_VIOLATION_ATTN\n");
if (val &
PGLUE_B_PGLUE_B_INT_STS_REG_VF_GRC_SPACE_VIOLATION_ATTN)
BNX2X_ERR("PGLUE_B_PGLUE_B_INT_STS_REG_"
"VF_GRC_SPACE_VIOLATION_ATTN\n");
if (val &
PGLUE_B_PGLUE_B_INT_STS_REG_VF_MSIX_BAR_VIOLATION_ATTN)
BNX2X_ERR("PGLUE_B_PGLUE_B_INT_STS_REG_"
"VF_MSIX_BAR_VIOLATION_ATTN\n");
if (val & PGLUE_B_PGLUE_B_INT_STS_REG_TCPL_ERROR_ATTN)
BNX2X_ERR("PGLUE_B_PGLUE_B_INT_STS_REG_"
"TCPL_ERROR_ATTN\n");
if (val & PGLUE_B_PGLUE_B_INT_STS_REG_TCPL_IN_TWO_RCBS_ATTN)
BNX2X_ERR("PGLUE_B_PGLUE_B_INT_STS_REG_"
"TCPL_IN_TWO_RCBS_ATTN\n");
if (val & PGLUE_B_PGLUE_B_INT_STS_REG_CSSNOOP_FIFO_OVERFLOW)
BNX2X_ERR("PGLUE_B_PGLUE_B_INT_STS_REG_"
"CSSNOOP_FIFO_OVERFLOW\n");
}
if (attn & AEU_INPUTS_ATTN_BITS_ATC_HW_INTERRUPT) {
val = REG_RD(bp, ATC_REG_ATC_INT_STS_CLR);
BNX2X_ERR("ATC hw attention 0x%x\n", val);
if (val & ATC_ATC_INT_STS_REG_ADDRESS_ERROR)
BNX2X_ERR("ATC_ATC_INT_STS_REG_ADDRESS_ERROR\n");
if (val & ATC_ATC_INT_STS_REG_ATC_TCPL_TO_NOT_PEND)
BNX2X_ERR("ATC_ATC_INT_STS_REG"
"_ATC_TCPL_TO_NOT_PEND\n");
if (val & ATC_ATC_INT_STS_REG_ATC_GPA_MULTIPLE_HITS)
BNX2X_ERR("ATC_ATC_INT_STS_REG_"
"ATC_GPA_MULTIPLE_HITS\n");
if (val & ATC_ATC_INT_STS_REG_ATC_RCPL_TO_EMPTY_CNT)
BNX2X_ERR("ATC_ATC_INT_STS_REG_"
"ATC_RCPL_TO_EMPTY_CNT\n");
if (val & ATC_ATC_INT_STS_REG_ATC_TCPL_ERROR)
BNX2X_ERR("ATC_ATC_INT_STS_REG_ATC_TCPL_ERROR\n");
if (val & ATC_ATC_INT_STS_REG_ATC_IREQ_LESS_THAN_STU)
BNX2X_ERR("ATC_ATC_INT_STS_REG_"
"ATC_IREQ_LESS_THAN_STU\n");
}
if (attn & (AEU_INPUTS_ATTN_BITS_PGLUE_PARITY_ERROR |
AEU_INPUTS_ATTN_BITS_ATC_PARITY_ERROR)) {
BNX2X_ERR("FATAL parity attention set4 0x%x\n",
(u32)(attn & (AEU_INPUTS_ATTN_BITS_PGLUE_PARITY_ERROR |
AEU_INPUTS_ATTN_BITS_ATC_PARITY_ERROR)));
}
}
static void bnx2x_attn_int_deasserted(struct bnx2x *bp, u32 deasserted)
{
struct attn_route attn, *group_mask;
int port = BP_PORT(bp);
int index;
u32 reg_addr;
u32 val;
u32 aeu_mask;
bool global = false;
bnx2x_acquire_alr(bp);
if (bnx2x_chk_parity_attn(bp, &global, true)) {
#ifndef BNX2X_STOP_ON_ERROR
bp->recovery_state = BNX2X_RECOVERY_INIT;
schedule_delayed_work(&bp->sp_rtnl_task, 0);
bnx2x_int_disable(bp);
#else
bnx2x_panic();
#endif
bnx2x_release_alr(bp);
return;
}
attn.sig[0] = REG_RD(bp, MISC_REG_AEU_AFTER_INVERT_1_FUNC_0 + port*4);
attn.sig[1] = REG_RD(bp, MISC_REG_AEU_AFTER_INVERT_2_FUNC_0 + port*4);
attn.sig[2] = REG_RD(bp, MISC_REG_AEU_AFTER_INVERT_3_FUNC_0 + port*4);
attn.sig[3] = REG_RD(bp, MISC_REG_AEU_AFTER_INVERT_4_FUNC_0 + port*4);
if (!CHIP_IS_E1x(bp))
attn.sig[4] =
REG_RD(bp, MISC_REG_AEU_AFTER_INVERT_5_FUNC_0 + port*4);
else
attn.sig[4] = 0;
DP(NETIF_MSG_HW, "attn: %08x %08x %08x %08x %08x\n",
attn.sig[0], attn.sig[1], attn.sig[2], attn.sig[3], attn.sig[4]);
for (index = 0; index < MAX_DYNAMIC_ATTN_GRPS; index++) {
if (deasserted & (1 << index)) {
group_mask = &bp->attn_group[index];
DP(NETIF_MSG_HW, "group[%d]: %08x %08x "
"%08x %08x %08x\n",
index,
group_mask->sig[0], group_mask->sig[1],
group_mask->sig[2], group_mask->sig[3],
group_mask->sig[4]);
bnx2x_attn_int_deasserted4(bp,
attn.sig[4] & group_mask->sig[4]);
bnx2x_attn_int_deasserted3(bp,
attn.sig[3] & group_mask->sig[3]);
bnx2x_attn_int_deasserted1(bp,
attn.sig[1] & group_mask->sig[1]);
bnx2x_attn_int_deasserted2(bp,
attn.sig[2] & group_mask->sig[2]);
bnx2x_attn_int_deasserted0(bp,
attn.sig[0] & group_mask->sig[0]);
}
}
bnx2x_release_alr(bp);
if (bp->common.int_block == INT_BLOCK_HC)
reg_addr = (HC_REG_COMMAND_REG + port*32 +
COMMAND_REG_ATTN_BITS_CLR);
else
reg_addr = (BAR_IGU_INTMEM + IGU_CMD_ATTN_BIT_CLR_UPPER*8);
val = ~deasserted;
DP(NETIF_MSG_HW, "about to mask 0x%08x at %s addr 0x%x\n", val,
(bp->common.int_block == INT_BLOCK_HC) ? "HC" : "IGU", reg_addr);
REG_WR(bp, reg_addr, val);
if (~bp->attn_state & deasserted)
BNX2X_ERR("IGU ERROR\n");
reg_addr = port ? MISC_REG_AEU_MASK_ATTN_FUNC_1 :
MISC_REG_AEU_MASK_ATTN_FUNC_0;
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_PORT0_ATT_MASK + port);
aeu_mask = REG_RD(bp, reg_addr);
DP(NETIF_MSG_HW, "aeu_mask %x newly deasserted %x\n",
aeu_mask, deasserted);
aeu_mask |= (deasserted & 0x3ff);
DP(NETIF_MSG_HW, "new mask %x\n", aeu_mask);
REG_WR(bp, reg_addr, aeu_mask);
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_PORT0_ATT_MASK + port);
DP(NETIF_MSG_HW, "attn_state %x\n", bp->attn_state);
bp->attn_state &= ~deasserted;
DP(NETIF_MSG_HW, "new state %x\n", bp->attn_state);
}
static void bnx2x_attn_int(struct bnx2x *bp)
{
u32 attn_bits = le32_to_cpu(bp->def_status_blk->atten_status_block.
attn_bits);
u32 attn_ack = le32_to_cpu(bp->def_status_blk->atten_status_block.
attn_bits_ack);
u32 attn_state = bp->attn_state;
u32 asserted = attn_bits & ~attn_ack & ~attn_state;
u32 deasserted = ~attn_bits & attn_ack & attn_state;
DP(NETIF_MSG_HW,
"attn_bits %x attn_ack %x asserted %x deasserted %x\n",
attn_bits, attn_ack, asserted, deasserted);
if (~(attn_bits ^ attn_ack) & (attn_bits ^ attn_state))
BNX2X_ERR("BAD attention state\n");
if (asserted)
bnx2x_attn_int_asserted(bp, asserted);
if (deasserted)
bnx2x_attn_int_deasserted(bp, deasserted);
}
void bnx2x_igu_ack_sb(struct bnx2x *bp, u8 igu_sb_id, u8 segment,
u16 index, u8 op, u8 update)
{
u32 igu_addr = BAR_IGU_INTMEM + (IGU_CMD_INT_ACK_BASE + igu_sb_id)*8;
bnx2x_igu_ack_sb_gen(bp, igu_sb_id, segment, index, op, update,
igu_addr);
}
static inline void bnx2x_update_eq_prod(struct bnx2x *bp, u16 prod)
{
storm_memset_eq_prod(bp, prod, BP_FUNC(bp));
mmiowb();
}
static int bnx2x_cnic_handle_cfc_del(struct bnx2x *bp, u32 cid,
union event_ring_elem *elem)
{
u8 err = elem->message.error;
if (!bp->cnic_eth_dev.starting_cid ||
(cid < bp->cnic_eth_dev.starting_cid &&
cid != bp->cnic_eth_dev.iscsi_l2_cid))
return 1;
DP(BNX2X_MSG_SP, "got delete ramrod for CNIC CID %d\n", cid);
if (unlikely(err)) {
BNX2X_ERR("got delete ramrod for CNIC CID %d with error!\n",
cid);
bnx2x_panic_dump(bp);
}
bnx2x_cnic_cfc_comp(bp, cid, err);
return 0;
}
static inline void bnx2x_handle_mcast_eqe(struct bnx2x *bp)
{
struct bnx2x_mcast_ramrod_params rparam;
int rc;
memset(&rparam, 0, sizeof(rparam));
rparam.mcast_obj = &bp->mcast_obj;
netif_addr_lock_bh(bp->dev);
bp->mcast_obj.raw.clear_pending(&bp->mcast_obj.raw);
if (bp->mcast_obj.check_pending(&bp->mcast_obj)) {
rc = bnx2x_config_mcast(bp, &rparam, BNX2X_MCAST_CMD_CONT);
if (rc < 0)
BNX2X_ERR("Failed to send pending mcast commands: %d\n",
rc);
}
netif_addr_unlock_bh(bp->dev);
}
static inline void bnx2x_handle_classification_eqe(struct bnx2x *bp,
union event_ring_elem *elem)
{
unsigned long ramrod_flags = 0;
int rc = 0;
u32 cid = elem->message.data.eth_event.echo & BNX2X_SWCID_MASK;
struct bnx2x_vlan_mac_obj *vlan_mac_obj;
__set_bit(RAMROD_CONT, &ramrod_flags);
switch (elem->message.data.eth_event.echo >> BNX2X_SWCID_SHIFT) {
case BNX2X_FILTER_MAC_PENDING:
#ifdef BCM_CNIC
if (cid == BNX2X_ISCSI_ETH_CID)
vlan_mac_obj = &bp->iscsi_l2_mac_obj;
else
#endif
vlan_mac_obj = &bp->fp[cid].mac_obj;
break;
case BNX2X_FILTER_MCAST_PENDING:
bnx2x_handle_mcast_eqe(bp);
return;
default:
BNX2X_ERR("Unsupported classification command: %d\n",
elem->message.data.eth_event.echo);
return;
}
rc = vlan_mac_obj->complete(bp, vlan_mac_obj, elem, &ramrod_flags);
if (rc < 0)
BNX2X_ERR("Failed to schedule new commands: %d\n", rc);
else if (rc > 0)
DP(BNX2X_MSG_SP, "Scheduled next pending commands...\n");
}
static inline void bnx2x_handle_rx_mode_eqe(struct bnx2x *bp)
{
netif_addr_lock_bh(bp->dev);
clear_bit(BNX2X_FILTER_RX_MODE_PENDING, &bp->sp_state);
if (test_and_clear_bit(BNX2X_FILTER_RX_MODE_SCHED, &bp->sp_state))
bnx2x_set_storm_rx_mode(bp);
#ifdef BCM_CNIC
else if (test_and_clear_bit(BNX2X_FILTER_ISCSI_ETH_START_SCHED,
&bp->sp_state))
bnx2x_set_iscsi_eth_rx_mode(bp, true);
else if (test_and_clear_bit(BNX2X_FILTER_ISCSI_ETH_STOP_SCHED,
&bp->sp_state))
bnx2x_set_iscsi_eth_rx_mode(bp, false);
#endif
netif_addr_unlock_bh(bp->dev);
}
static inline struct bnx2x_queue_sp_obj *bnx2x_cid_to_q_obj(
struct bnx2x *bp, u32 cid)
{
DP(BNX2X_MSG_SP, "retrieving fp from cid %d\n", cid);
#ifdef BCM_CNIC
if (cid == BNX2X_FCOE_ETH_CID)
return &bnx2x_fcoe(bp, q_obj);
else
#endif
return &bnx2x_fp(bp, CID_TO_FP(cid), q_obj);
}
static void bnx2x_eq_int(struct bnx2x *bp)
{
u16 hw_cons, sw_cons, sw_prod;
union event_ring_elem *elem;
u32 cid;
u8 opcode;
int spqe_cnt = 0;
struct bnx2x_queue_sp_obj *q_obj;
struct bnx2x_func_sp_obj *f_obj = &bp->func_obj;
struct bnx2x_raw_obj *rss_raw = &bp->rss_conf_obj.raw;
hw_cons = le16_to_cpu(*bp->eq_cons_sb);
if ((hw_cons & EQ_DESC_MAX_PAGE) == EQ_DESC_MAX_PAGE)
hw_cons++;
sw_cons = bp->eq_cons;
sw_prod = bp->eq_prod;
DP(BNX2X_MSG_SP, "EQ: hw_cons %u sw_cons %u bp->eq_spq_left %x\n",
hw_cons, sw_cons, atomic_read(&bp->eq_spq_left));
for (; sw_cons != hw_cons;
sw_prod = NEXT_EQ_IDX(sw_prod), sw_cons = NEXT_EQ_IDX(sw_cons)) {
elem = &bp->eq_ring[EQ_DESC(sw_cons)];
cid = SW_CID(elem->message.data.cfc_del_event.cid);
opcode = elem->message.opcode;
switch (opcode) {
case EVENT_RING_OPCODE_STAT_QUERY:
DP(NETIF_MSG_TIMER, "got statistics comp event %d\n",
bp->stats_comp++);
goto next_spqe;
case EVENT_RING_OPCODE_CFC_DEL:
DP(BNX2X_MSG_SP,
"got delete ramrod for MULTI[%d]\n", cid);
#ifdef BCM_CNIC
if (!bnx2x_cnic_handle_cfc_del(bp, cid, elem))
goto next_spqe;
#endif
q_obj = bnx2x_cid_to_q_obj(bp, cid);
if (q_obj->complete_cmd(bp, q_obj, BNX2X_Q_CMD_CFC_DEL))
break;
goto next_spqe;
case EVENT_RING_OPCODE_STOP_TRAFFIC:
DP(BNX2X_MSG_SP, "got STOP TRAFFIC\n");
if (f_obj->complete_cmd(bp, f_obj,
BNX2X_F_CMD_TX_STOP))
break;
bnx2x_dcbx_set_params(bp, BNX2X_DCBX_STATE_TX_PAUSED);
goto next_spqe;
case EVENT_RING_OPCODE_START_TRAFFIC:
DP(BNX2X_MSG_SP, "got START TRAFFIC\n");
if (f_obj->complete_cmd(bp, f_obj,
BNX2X_F_CMD_TX_START))
break;
bnx2x_dcbx_set_params(bp, BNX2X_DCBX_STATE_TX_RELEASED);
goto next_spqe;
case EVENT_RING_OPCODE_FUNCTION_START:
DP(BNX2X_MSG_SP, "got FUNC_START ramrod\n");
if (f_obj->complete_cmd(bp, f_obj, BNX2X_F_CMD_START))
break;
goto next_spqe;
case EVENT_RING_OPCODE_FUNCTION_STOP:
DP(BNX2X_MSG_SP, "got FUNC_STOP ramrod\n");
if (f_obj->complete_cmd(bp, f_obj, BNX2X_F_CMD_STOP))
break;
goto next_spqe;
}
switch (opcode | bp->state) {
case (EVENT_RING_OPCODE_RSS_UPDATE_RULES |
BNX2X_STATE_OPEN):
case (EVENT_RING_OPCODE_RSS_UPDATE_RULES |
BNX2X_STATE_OPENING_WAIT4_PORT):
cid = elem->message.data.eth_event.echo &
BNX2X_SWCID_MASK;
DP(BNX2X_MSG_SP, "got RSS_UPDATE ramrod. CID %d\n",
cid);
rss_raw->clear_pending(rss_raw);
break;
case (EVENT_RING_OPCODE_SET_MAC | BNX2X_STATE_OPEN):
case (EVENT_RING_OPCODE_SET_MAC | BNX2X_STATE_DIAG):
case (EVENT_RING_OPCODE_SET_MAC |
BNX2X_STATE_CLOSING_WAIT4_HALT):
case (EVENT_RING_OPCODE_CLASSIFICATION_RULES |
BNX2X_STATE_OPEN):
case (EVENT_RING_OPCODE_CLASSIFICATION_RULES |
BNX2X_STATE_DIAG):
case (EVENT_RING_OPCODE_CLASSIFICATION_RULES |
BNX2X_STATE_CLOSING_WAIT4_HALT):
DP(BNX2X_MSG_SP, "got (un)set mac ramrod\n");
bnx2x_handle_classification_eqe(bp, elem);
break;
case (EVENT_RING_OPCODE_MULTICAST_RULES |
BNX2X_STATE_OPEN):
case (EVENT_RING_OPCODE_MULTICAST_RULES |
BNX2X_STATE_DIAG):
case (EVENT_RING_OPCODE_MULTICAST_RULES |
BNX2X_STATE_CLOSING_WAIT4_HALT):
DP(BNX2X_MSG_SP, "got mcast ramrod\n");
bnx2x_handle_mcast_eqe(bp);
break;
case (EVENT_RING_OPCODE_FILTERS_RULES |
BNX2X_STATE_OPEN):
case (EVENT_RING_OPCODE_FILTERS_RULES |
BNX2X_STATE_DIAG):
case (EVENT_RING_OPCODE_FILTERS_RULES |
BNX2X_STATE_CLOSING_WAIT4_HALT):
DP(BNX2X_MSG_SP, "got rx_mode ramrod\n");
bnx2x_handle_rx_mode_eqe(bp);
break;
default:
BNX2X_ERR("Unknown EQ event %d, bp->state 0x%x\n",
elem->message.opcode, bp->state);
}
next_spqe:
spqe_cnt++;
}
smp_mb__before_atomic_inc();
atomic_add(spqe_cnt, &bp->eq_spq_left);
bp->eq_cons = sw_cons;
bp->eq_prod = sw_prod;
smp_wmb();
bnx2x_update_eq_prod(bp, bp->eq_prod);
}
static void bnx2x_sp_task(struct work_struct *work)
{
struct bnx2x *bp = container_of(work, struct bnx2x, sp_task.work);
u16 status;
status = bnx2x_update_dsb_idx(bp);
DP(NETIF_MSG_INTR, "got a slowpath interrupt (status 0x%x)\n", status);
if (status & BNX2X_DEF_SB_ATT_IDX) {
bnx2x_attn_int(bp);
status &= ~BNX2X_DEF_SB_ATT_IDX;
}
if (status & BNX2X_DEF_SB_IDX) {
#ifdef BCM_CNIC
struct bnx2x_fastpath *fp = bnx2x_fcoe_fp(bp);
if ((!NO_FCOE(bp)) &&
(bnx2x_has_rx_work(fp) || bnx2x_has_tx_work(fp))) {
local_bh_disable();
napi_schedule(&bnx2x_fcoe(bp, napi));
local_bh_enable();
}
#endif
bnx2x_eq_int(bp);
bnx2x_ack_sb(bp, bp->igu_dsb_id, USTORM_ID,
le16_to_cpu(bp->def_idx), IGU_INT_NOP, 1);
status &= ~BNX2X_DEF_SB_IDX;
}
if (unlikely(status))
DP(NETIF_MSG_INTR, "got an unknown interrupt! (status 0x%x)\n",
status);
bnx2x_ack_sb(bp, bp->igu_dsb_id, ATTENTION_ID,
le16_to_cpu(bp->def_att_idx), IGU_INT_ENABLE, 1);
}
irqreturn_t bnx2x_msix_sp_int(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct bnx2x *bp = netdev_priv(dev);
bnx2x_ack_sb(bp, bp->igu_dsb_id, USTORM_ID, 0,
IGU_INT_DISABLE, 0);
#ifdef BNX2X_STOP_ON_ERROR
if (unlikely(bp->panic))
return IRQ_HANDLED;
#endif
#ifdef BCM_CNIC
{
struct cnic_ops *c_ops;
rcu_read_lock();
c_ops = rcu_dereference(bp->cnic_ops);
if (c_ops)
c_ops->cnic_handler(bp->cnic_data, NULL);
rcu_read_unlock();
}
#endif
queue_delayed_work(bnx2x_wq, &bp->sp_task, 0);
return IRQ_HANDLED;
}
void bnx2x_drv_pulse(struct bnx2x *bp)
{
SHMEM_WR(bp, func_mb[BP_FW_MB_IDX(bp)].drv_pulse_mb,
bp->fw_drv_pulse_wr_seq);
}
static void bnx2x_timer(unsigned long data)
{
u8 cos;
struct bnx2x *bp = (struct bnx2x *) data;
if (!netif_running(bp->dev))
return;
if (poll) {
struct bnx2x_fastpath *fp = &bp->fp[0];
for_each_cos_in_tx_queue(fp, cos)
bnx2x_tx_int(bp, &fp->txdata[cos]);
bnx2x_rx_int(fp, 1000);
}
if (!BP_NOMCP(bp)) {
int mb_idx = BP_FW_MB_IDX(bp);
u32 drv_pulse;
u32 mcp_pulse;
++bp->fw_drv_pulse_wr_seq;
bp->fw_drv_pulse_wr_seq &= DRV_PULSE_SEQ_MASK;
drv_pulse = bp->fw_drv_pulse_wr_seq;
bnx2x_drv_pulse(bp);
mcp_pulse = (SHMEM_RD(bp, func_mb[mb_idx].mcp_pulse_mb) &
MCP_PULSE_SEQ_MASK);
if ((drv_pulse != mcp_pulse) &&
(drv_pulse != ((mcp_pulse + 1) & MCP_PULSE_SEQ_MASK))) {
BNX2X_ERR("drv_pulse (0x%x) != mcp_pulse (0x%x)\n",
drv_pulse, mcp_pulse);
}
}
if (bp->state == BNX2X_STATE_OPEN)
bnx2x_stats_handle(bp, STATS_EVENT_UPDATE);
mod_timer(&bp->timer, jiffies + bp->current_interval);
}
static inline void bnx2x_fill(struct bnx2x *bp, u32 addr, int fill, u32 len)
{
u32 i;
if (!(len%4) && !(addr%4))
for (i = 0; i < len; i += 4)
REG_WR(bp, addr + i, fill);
else
for (i = 0; i < len; i++)
REG_WR8(bp, addr + i, fill);
}
static inline void bnx2x_wr_fp_sb_data(struct bnx2x *bp,
int fw_sb_id,
u32 *sb_data_p,
u32 data_size)
{
int index;
for (index = 0; index < data_size; index++)
REG_WR(bp, BAR_CSTRORM_INTMEM +
CSTORM_STATUS_BLOCK_DATA_OFFSET(fw_sb_id) +
sizeof(u32)*index,
*(sb_data_p + index));
}
static inline void bnx2x_zero_fp_sb(struct bnx2x *bp, int fw_sb_id)
{
u32 *sb_data_p;
u32 data_size = 0;
struct hc_status_block_data_e2 sb_data_e2;
struct hc_status_block_data_e1x sb_data_e1x;
if (!CHIP_IS_E1x(bp)) {
memset(&sb_data_e2, 0, sizeof(struct hc_status_block_data_e2));
sb_data_e2.common.state = SB_DISABLED;
sb_data_e2.common.p_func.vf_valid = false;
sb_data_p = (u32 *)&sb_data_e2;
data_size = sizeof(struct hc_status_block_data_e2)/sizeof(u32);
} else {
memset(&sb_data_e1x, 0,
sizeof(struct hc_status_block_data_e1x));
sb_data_e1x.common.state = SB_DISABLED;
sb_data_e1x.common.p_func.vf_valid = false;
sb_data_p = (u32 *)&sb_data_e1x;
data_size = sizeof(struct hc_status_block_data_e1x)/sizeof(u32);
}
bnx2x_wr_fp_sb_data(bp, fw_sb_id, sb_data_p, data_size);
bnx2x_fill(bp, BAR_CSTRORM_INTMEM +
CSTORM_STATUS_BLOCK_OFFSET(fw_sb_id), 0,
CSTORM_STATUS_BLOCK_SIZE);
bnx2x_fill(bp, BAR_CSTRORM_INTMEM +
CSTORM_SYNC_BLOCK_OFFSET(fw_sb_id), 0,
CSTORM_SYNC_BLOCK_SIZE);
}
static inline void bnx2x_wr_sp_sb_data(struct bnx2x *bp,
struct hc_sp_status_block_data *sp_sb_data)
{
int func = BP_FUNC(bp);
int i;
for (i = 0; i < sizeof(struct hc_sp_status_block_data)/sizeof(u32); i++)
REG_WR(bp, BAR_CSTRORM_INTMEM +
CSTORM_SP_STATUS_BLOCK_DATA_OFFSET(func) +
i*sizeof(u32),
*((u32 *)sp_sb_data + i));
}
static inline void bnx2x_zero_sp_sb(struct bnx2x *bp)
{
int func = BP_FUNC(bp);
struct hc_sp_status_block_data sp_sb_data;
memset(&sp_sb_data, 0, sizeof(struct hc_sp_status_block_data));
sp_sb_data.state = SB_DISABLED;
sp_sb_data.p_func.vf_valid = false;
bnx2x_wr_sp_sb_data(bp, &sp_sb_data);
bnx2x_fill(bp, BAR_CSTRORM_INTMEM +
CSTORM_SP_STATUS_BLOCK_OFFSET(func), 0,
CSTORM_SP_STATUS_BLOCK_SIZE);
bnx2x_fill(bp, BAR_CSTRORM_INTMEM +
CSTORM_SP_SYNC_BLOCK_OFFSET(func), 0,
CSTORM_SP_SYNC_BLOCK_SIZE);
}
static inline
void bnx2x_setup_ndsb_state_machine(struct hc_status_block_sm *hc_sm,
int igu_sb_id, int igu_seg_id)
{
hc_sm->igu_sb_id = igu_sb_id;
hc_sm->igu_seg_id = igu_seg_id;
hc_sm->timer_value = 0xFF;
hc_sm->time_to_expire = 0xFFFFFFFF;
}
static inline
void bnx2x_map_sb_state_machines(struct hc_index_data *index_data)
{
index_data[HC_INDEX_ETH_RX_CQ_CONS].flags &= ~HC_INDEX_DATA_SM_ID;
index_data[HC_INDEX_OOO_TX_CQ_CONS].flags &= ~HC_INDEX_DATA_SM_ID;
index_data[HC_INDEX_ETH_TX_CQ_CONS_COS0].flags &= ~HC_INDEX_DATA_SM_ID;
index_data[HC_INDEX_ETH_TX_CQ_CONS_COS1].flags &= ~HC_INDEX_DATA_SM_ID;
index_data[HC_INDEX_ETH_TX_CQ_CONS_COS2].flags &= ~HC_INDEX_DATA_SM_ID;
index_data[HC_INDEX_ETH_RX_CQ_CONS].flags |=
SM_RX_ID << HC_INDEX_DATA_SM_ID_SHIFT;
index_data[HC_INDEX_OOO_TX_CQ_CONS].flags |=
SM_TX_ID << HC_INDEX_DATA_SM_ID_SHIFT;
index_data[HC_INDEX_ETH_TX_CQ_CONS_COS0].flags |=
SM_TX_ID << HC_INDEX_DATA_SM_ID_SHIFT;
index_data[HC_INDEX_ETH_TX_CQ_CONS_COS1].flags |=
SM_TX_ID << HC_INDEX_DATA_SM_ID_SHIFT;
index_data[HC_INDEX_ETH_TX_CQ_CONS_COS2].flags |=
SM_TX_ID << HC_INDEX_DATA_SM_ID_SHIFT;
}
static void bnx2x_init_sb(struct bnx2x *bp, dma_addr_t mapping, int vfid,
u8 vf_valid, int fw_sb_id, int igu_sb_id)
{
int igu_seg_id;
struct hc_status_block_data_e2 sb_data_e2;
struct hc_status_block_data_e1x sb_data_e1x;
struct hc_status_block_sm *hc_sm_p;
int data_size;
u32 *sb_data_p;
if (CHIP_INT_MODE_IS_BC(bp))
igu_seg_id = HC_SEG_ACCESS_NORM;
else
igu_seg_id = IGU_SEG_ACCESS_NORM;
bnx2x_zero_fp_sb(bp, fw_sb_id);
if (!CHIP_IS_E1x(bp)) {
memset(&sb_data_e2, 0, sizeof(struct hc_status_block_data_e2));
sb_data_e2.common.state = SB_ENABLED;
sb_data_e2.common.p_func.pf_id = BP_FUNC(bp);
sb_data_e2.common.p_func.vf_id = vfid;
sb_data_e2.common.p_func.vf_valid = vf_valid;
sb_data_e2.common.p_func.vnic_id = BP_VN(bp);
sb_data_e2.common.same_igu_sb_1b = true;
sb_data_e2.common.host_sb_addr.hi = U64_HI(mapping);
sb_data_e2.common.host_sb_addr.lo = U64_LO(mapping);
hc_sm_p = sb_data_e2.common.state_machine;
sb_data_p = (u32 *)&sb_data_e2;
data_size = sizeof(struct hc_status_block_data_e2)/sizeof(u32);
bnx2x_map_sb_state_machines(sb_data_e2.index_data);
} else {
memset(&sb_data_e1x, 0,
sizeof(struct hc_status_block_data_e1x));
sb_data_e1x.common.state = SB_ENABLED;
sb_data_e1x.common.p_func.pf_id = BP_FUNC(bp);
sb_data_e1x.common.p_func.vf_id = 0xff;
sb_data_e1x.common.p_func.vf_valid = false;
sb_data_e1x.common.p_func.vnic_id = BP_VN(bp);
sb_data_e1x.common.same_igu_sb_1b = true;
sb_data_e1x.common.host_sb_addr.hi = U64_HI(mapping);
sb_data_e1x.common.host_sb_addr.lo = U64_LO(mapping);
hc_sm_p = sb_data_e1x.common.state_machine;
sb_data_p = (u32 *)&sb_data_e1x;
data_size = sizeof(struct hc_status_block_data_e1x)/sizeof(u32);
bnx2x_map_sb_state_machines(sb_data_e1x.index_data);
}
bnx2x_setup_ndsb_state_machine(&hc_sm_p[SM_RX_ID],
igu_sb_id, igu_seg_id);
bnx2x_setup_ndsb_state_machine(&hc_sm_p[SM_TX_ID],
igu_sb_id, igu_seg_id);
DP(NETIF_MSG_HW, "Init FW SB %d\n", fw_sb_id);
bnx2x_wr_fp_sb_data(bp, fw_sb_id, sb_data_p, data_size);
}
static void bnx2x_update_coalesce_sb(struct bnx2x *bp, u8 fw_sb_id,
u16 tx_usec, u16 rx_usec)
{
bnx2x_update_coalesce_sb_index(bp, fw_sb_id, HC_INDEX_ETH_RX_CQ_CONS,
false, rx_usec);
bnx2x_update_coalesce_sb_index(bp, fw_sb_id,
HC_INDEX_ETH_TX_CQ_CONS_COS0, false,
tx_usec);
bnx2x_update_coalesce_sb_index(bp, fw_sb_id,
HC_INDEX_ETH_TX_CQ_CONS_COS1, false,
tx_usec);
bnx2x_update_coalesce_sb_index(bp, fw_sb_id,
HC_INDEX_ETH_TX_CQ_CONS_COS2, false,
tx_usec);
}
static void bnx2x_init_def_sb(struct bnx2x *bp)
{
struct host_sp_status_block *def_sb = bp->def_status_blk;
dma_addr_t mapping = bp->def_status_blk_mapping;
int igu_sp_sb_index;
int igu_seg_id;
int port = BP_PORT(bp);
int func = BP_FUNC(bp);
int reg_offset, reg_offset_en5;
u64 section;
int index;
struct hc_sp_status_block_data sp_sb_data;
memset(&sp_sb_data, 0, sizeof(struct hc_sp_status_block_data));
if (CHIP_INT_MODE_IS_BC(bp)) {
igu_sp_sb_index = DEF_SB_IGU_ID;
igu_seg_id = HC_SEG_ACCESS_DEF;
} else {
igu_sp_sb_index = bp->igu_dsb_id;
igu_seg_id = IGU_SEG_ACCESS_DEF;
}
section = ((u64)mapping) + offsetof(struct host_sp_status_block,
atten_status_block);
def_sb->atten_status_block.status_block_id = igu_sp_sb_index;
bp->attn_state = 0;
reg_offset = (port ? MISC_REG_AEU_ENABLE1_FUNC_1_OUT_0 :
MISC_REG_AEU_ENABLE1_FUNC_0_OUT_0);
reg_offset_en5 = (port ? MISC_REG_AEU_ENABLE5_FUNC_1_OUT_0 :
MISC_REG_AEU_ENABLE5_FUNC_0_OUT_0);
for (index = 0; index < MAX_DYNAMIC_ATTN_GRPS; index++) {
int sindex;
for (sindex = 0; sindex < 4; sindex++)
bp->attn_group[index].sig[sindex] =
REG_RD(bp, reg_offset + sindex*0x4 + 0x10*index);
if (!CHIP_IS_E1x(bp))
bp->attn_group[index].sig[4] = REG_RD(bp,
reg_offset_en5 + 0x4*index);
else
bp->attn_group[index].sig[4] = 0;
}
if (bp->common.int_block == INT_BLOCK_HC) {
reg_offset = (port ? HC_REG_ATTN_MSG1_ADDR_L :
HC_REG_ATTN_MSG0_ADDR_L);
REG_WR(bp, reg_offset, U64_LO(section));
REG_WR(bp, reg_offset + 4, U64_HI(section));
} else if (!CHIP_IS_E1x(bp)) {
REG_WR(bp, IGU_REG_ATTN_MSG_ADDR_L, U64_LO(section));
REG_WR(bp, IGU_REG_ATTN_MSG_ADDR_H, U64_HI(section));
}
section = ((u64)mapping) + offsetof(struct host_sp_status_block,
sp_sb);
bnx2x_zero_sp_sb(bp);
sp_sb_data.state = SB_ENABLED;
sp_sb_data.host_sb_addr.lo = U64_LO(section);
sp_sb_data.host_sb_addr.hi = U64_HI(section);
sp_sb_data.igu_sb_id = igu_sp_sb_index;
sp_sb_data.igu_seg_id = igu_seg_id;
sp_sb_data.p_func.pf_id = func;
sp_sb_data.p_func.vnic_id = BP_VN(bp);
sp_sb_data.p_func.vf_id = 0xff;
bnx2x_wr_sp_sb_data(bp, &sp_sb_data);
bnx2x_ack_sb(bp, bp->igu_dsb_id, USTORM_ID, 0, IGU_INT_ENABLE, 0);
}
void bnx2x_update_coalesce(struct bnx2x *bp)
{
int i;
for_each_eth_queue(bp, i)
bnx2x_update_coalesce_sb(bp, bp->fp[i].fw_sb_id,
bp->tx_ticks, bp->rx_ticks);
}
static void bnx2x_init_sp_ring(struct bnx2x *bp)
{
spin_lock_init(&bp->spq_lock);
atomic_set(&bp->cq_spq_left, MAX_SPQ_PENDING);
bp->spq_prod_idx = 0;
bp->dsb_sp_prod = BNX2X_SP_DSB_INDEX;
bp->spq_prod_bd = bp->spq;
bp->spq_last_bd = bp->spq_prod_bd + MAX_SP_DESC_CNT;
}
static void bnx2x_init_eq_ring(struct bnx2x *bp)
{
int i;
for (i = 1; i <= NUM_EQ_PAGES; i++) {
union event_ring_elem *elem =
&bp->eq_ring[EQ_DESC_CNT_PAGE * i - 1];
elem->next_page.addr.hi =
cpu_to_le32(U64_HI(bp->eq_mapping +
BCM_PAGE_SIZE * (i % NUM_EQ_PAGES)));
elem->next_page.addr.lo =
cpu_to_le32(U64_LO(bp->eq_mapping +
BCM_PAGE_SIZE*(i % NUM_EQ_PAGES)));
}
bp->eq_cons = 0;
bp->eq_prod = NUM_EQ_DESC;
bp->eq_cons_sb = BNX2X_EQ_INDEX;
atomic_set(&bp->eq_spq_left,
min_t(int, MAX_SP_DESC_CNT - MAX_SPQ_PENDING, NUM_EQ_DESC) - 1);
}
void bnx2x_set_q_rx_mode(struct bnx2x *bp, u8 cl_id,
unsigned long rx_mode_flags,
unsigned long rx_accept_flags,
unsigned long tx_accept_flags,
unsigned long ramrod_flags)
{
struct bnx2x_rx_mode_ramrod_params ramrod_param;
int rc;
memset(&ramrod_param, 0, sizeof(ramrod_param));
ramrod_param.cid = 0;
ramrod_param.cl_id = cl_id;
ramrod_param.rx_mode_obj = &bp->rx_mode_obj;
ramrod_param.func_id = BP_FUNC(bp);
ramrod_param.pstate = &bp->sp_state;
ramrod_param.state = BNX2X_FILTER_RX_MODE_PENDING;
ramrod_param.rdata = bnx2x_sp(bp, rx_mode_rdata);
ramrod_param.rdata_mapping = bnx2x_sp_mapping(bp, rx_mode_rdata);
set_bit(BNX2X_FILTER_RX_MODE_PENDING, &bp->sp_state);
ramrod_param.ramrod_flags = ramrod_flags;
ramrod_param.rx_mode_flags = rx_mode_flags;
ramrod_param.rx_accept_flags = rx_accept_flags;
ramrod_param.tx_accept_flags = tx_accept_flags;
rc = bnx2x_config_rx_mode(bp, &ramrod_param);
if (rc < 0) {
BNX2X_ERR("Set rx_mode %d failed\n", bp->rx_mode);
return;
}
}
void bnx2x_set_storm_rx_mode(struct bnx2x *bp)
{
unsigned long rx_mode_flags = 0, ramrod_flags = 0;
unsigned long rx_accept_flags = 0, tx_accept_flags = 0;
#ifdef BCM_CNIC
if (!NO_FCOE(bp))
__set_bit(BNX2X_RX_MODE_FCOE_ETH, &rx_mode_flags);
#endif
switch (bp->rx_mode) {
case BNX2X_RX_MODE_NONE:
break;
case BNX2X_RX_MODE_NORMAL:
__set_bit(BNX2X_ACCEPT_UNICAST, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_MULTICAST, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_BROADCAST, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_UNICAST, &tx_accept_flags);
__set_bit(BNX2X_ACCEPT_MULTICAST, &tx_accept_flags);
__set_bit(BNX2X_ACCEPT_BROADCAST, &tx_accept_flags);
break;
case BNX2X_RX_MODE_ALLMULTI:
__set_bit(BNX2X_ACCEPT_UNICAST, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_ALL_MULTICAST, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_BROADCAST, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_UNICAST, &tx_accept_flags);
__set_bit(BNX2X_ACCEPT_ALL_MULTICAST, &tx_accept_flags);
__set_bit(BNX2X_ACCEPT_BROADCAST, &tx_accept_flags);
break;
case BNX2X_RX_MODE_PROMISC:
__set_bit(BNX2X_ACCEPT_UNMATCHED, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_UNICAST, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_ALL_MULTICAST, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_BROADCAST, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_ALL_MULTICAST, &tx_accept_flags);
__set_bit(BNX2X_ACCEPT_BROADCAST, &tx_accept_flags);
if (IS_MF_SI(bp))
__set_bit(BNX2X_ACCEPT_ALL_UNICAST, &tx_accept_flags);
else
__set_bit(BNX2X_ACCEPT_UNICAST, &tx_accept_flags);
break;
default:
BNX2X_ERR("Unknown rx_mode: %d\n", bp->rx_mode);
return;
}
if (bp->rx_mode != BNX2X_RX_MODE_NONE) {
__set_bit(BNX2X_ACCEPT_ANY_VLAN, &rx_accept_flags);
__set_bit(BNX2X_ACCEPT_ANY_VLAN, &tx_accept_flags);
}
__set_bit(RAMROD_RX, &ramrod_flags);
__set_bit(RAMROD_TX, &ramrod_flags);
bnx2x_set_q_rx_mode(bp, bp->fp->cl_id, rx_mode_flags, rx_accept_flags,
tx_accept_flags, ramrod_flags);
}
static void bnx2x_init_internal_common(struct bnx2x *bp)
{
int i;
if (IS_MF_SI(bp))
REG_WR8(bp, BAR_TSTRORM_INTMEM +
TSTORM_ACCEPT_CLASSIFY_FAILED_OFFSET, 2);
else if (!CHIP_IS_E1(bp))
REG_WR8(bp, BAR_TSTRORM_INTMEM +
TSTORM_ACCEPT_CLASSIFY_FAILED_OFFSET, 0);
for (i = 0; i < (USTORM_AGG_DATA_SIZE >> 2); i++)
REG_WR(bp, BAR_USTRORM_INTMEM +
USTORM_AGG_DATA_OFFSET + i * 4, 0);
if (!CHIP_IS_E1x(bp)) {
REG_WR8(bp, BAR_CSTRORM_INTMEM + CSTORM_IGU_MODE_OFFSET,
CHIP_INT_MODE_IS_BC(bp) ?
HC_IGU_BC_MODE : HC_IGU_NBC_MODE);
}
}
static void bnx2x_init_internal(struct bnx2x *bp, u32 load_code)
{
switch (load_code) {
case FW_MSG_CODE_DRV_LOAD_COMMON:
case FW_MSG_CODE_DRV_LOAD_COMMON_CHIP:
bnx2x_init_internal_common(bp);
case FW_MSG_CODE_DRV_LOAD_PORT:
case FW_MSG_CODE_DRV_LOAD_FUNCTION:
break;
default:
BNX2X_ERR("Unknown load_code (0x%x) from MCP\n", load_code);
break;
}
}
static inline u8 bnx2x_fp_igu_sb_id(struct bnx2x_fastpath *fp)
{
return fp->bp->igu_base_sb + fp->index + CNIC_PRESENT;
}
static inline u8 bnx2x_fp_fw_sb_id(struct bnx2x_fastpath *fp)
{
return fp->bp->base_fw_ndsb + fp->index + CNIC_PRESENT;
}
static inline u8 bnx2x_fp_cl_id(struct bnx2x_fastpath *fp)
{
if (CHIP_IS_E1x(fp->bp))
return BP_L_ID(fp->bp) + fp->index;
else
return bnx2x_fp_igu_sb_id(fp);
}
static void bnx2x_init_eth_fp(struct bnx2x *bp, int fp_idx)
{
struct bnx2x_fastpath *fp = &bp->fp[fp_idx];
u8 cos;
unsigned long q_type = 0;
u32 cids[BNX2X_MULTI_TX_COS] = { 0 };
fp->cid = fp_idx;
fp->cl_id = bnx2x_fp_cl_id(fp);
fp->fw_sb_id = bnx2x_fp_fw_sb_id(fp);
fp->igu_sb_id = bnx2x_fp_igu_sb_id(fp);
fp->cl_qzone_id = bnx2x_fp_qzone_id(fp);
fp->ustorm_rx_prods_offset = bnx2x_rx_ustorm_prods_offset(fp);
fp->rx_cons_sb = BNX2X_RX_SB_INDEX;
__set_bit(BNX2X_Q_TYPE_HAS_RX, &q_type);
__set_bit(BNX2X_Q_TYPE_HAS_TX, &q_type);
BUG_ON(fp->max_cos > BNX2X_MULTI_TX_COS);
for_each_cos_in_tx_queue(fp, cos) {
bnx2x_init_txdata(bp, &fp->txdata[cos],
CID_COS_TO_TX_ONLY_CID(fp->cid, cos),
FP_COS_TO_TXQ(fp, cos),
BNX2X_TX_SB_INDEX_BASE + cos);
cids[cos] = fp->txdata[cos].cid;
}
bnx2x_init_queue_obj(bp, &fp->q_obj, fp->cl_id, cids, fp->max_cos,
BP_FUNC(bp), bnx2x_sp(bp, q_rdata),
bnx2x_sp_mapping(bp, q_rdata), q_type);
bnx2x_init_vlan_mac_fp_objs(fp, BNX2X_OBJ_TYPE_RX_TX);
DP(NETIF_MSG_IFUP, "queue[%d]: bnx2x_init_sb(%p,%p) "
"cl_id %d fw_sb %d igu_sb %d\n",
fp_idx, bp, fp->status_blk.e2_sb, fp->cl_id, fp->fw_sb_id,
fp->igu_sb_id);
bnx2x_init_sb(bp, fp->status_blk_mapping, BNX2X_VF_ID_INVALID, false,
fp->fw_sb_id, fp->igu_sb_id);
bnx2x_update_fpsb_idx(fp);
}
void bnx2x_nic_init(struct bnx2x *bp, u32 load_code)
{
int i;
for_each_eth_queue(bp, i)
bnx2x_init_eth_fp(bp, i);
#ifdef BCM_CNIC
if (!NO_FCOE(bp))
bnx2x_init_fcoe_fp(bp);
bnx2x_init_sb(bp, bp->cnic_sb_mapping,
BNX2X_VF_ID_INVALID, false,
bnx2x_cnic_fw_sb_id(bp), bnx2x_cnic_igu_sb_id(bp));
#endif
bnx2x_init_mod_abs_int(bp, &bp->link_vars, bp->common.chip_id,
bp->common.shmem_base, bp->common.shmem2_base,
BP_PORT(bp));
rmb();
bnx2x_init_def_sb(bp);
bnx2x_update_dsb_idx(bp);
bnx2x_init_rx_rings(bp);
bnx2x_init_tx_rings(bp);
bnx2x_init_sp_ring(bp);
bnx2x_init_eq_ring(bp);
bnx2x_init_internal(bp, load_code);
bnx2x_pf_init(bp);
bnx2x_stats_init(bp);
mb();
mmiowb();
bnx2x_int_enable(bp);
bnx2x_attn_int_deasserted0(bp,
REG_RD(bp, MISC_REG_AEU_AFTER_INVERT_1_FUNC_0 + BP_PORT(bp)*4) &
AEU_INPUTS_ATTN_BITS_SPIO5);
}
static int bnx2x_gunzip_init(struct bnx2x *bp)
{
bp->gunzip_buf = dma_alloc_coherent(&bp->pdev->dev, FW_BUF_SIZE,
&bp->gunzip_mapping, GFP_KERNEL);
if (bp->gunzip_buf == NULL)
goto gunzip_nomem1;
bp->strm = kmalloc(sizeof(*bp->strm), GFP_KERNEL);
if (bp->strm == NULL)
goto gunzip_nomem2;
bp->strm->workspace = vmalloc(zlib_inflate_workspacesize());
if (bp->strm->workspace == NULL)
goto gunzip_nomem3;
return 0;
gunzip_nomem3:
kfree(bp->strm);
bp->strm = NULL;
gunzip_nomem2:
dma_free_coherent(&bp->pdev->dev, FW_BUF_SIZE, bp->gunzip_buf,
bp->gunzip_mapping);
bp->gunzip_buf = NULL;
gunzip_nomem1:
netdev_err(bp->dev, "Cannot allocate firmware buffer for"
" un-compression\n");
return -ENOMEM;
}
static void bnx2x_gunzip_end(struct bnx2x *bp)
{
if (bp->strm) {
vfree(bp->strm->workspace);
kfree(bp->strm);
bp->strm = NULL;
}
if (bp->gunzip_buf) {
dma_free_coherent(&bp->pdev->dev, FW_BUF_SIZE, bp->gunzip_buf,
bp->gunzip_mapping);
bp->gunzip_buf = NULL;
}
}
static int bnx2x_gunzip(struct bnx2x *bp, const u8 *zbuf, int len)
{
int n, rc;
if ((zbuf[0] != 0x1f) || (zbuf[1] != 0x8b) || (zbuf[2] != Z_DEFLATED)) {
BNX2X_ERR("Bad gzip header\n");
return -EINVAL;
}
n = 10;
#define FNAME 0x8
if (zbuf[3] & FNAME)
while ((zbuf[n++] != 0) && (n < len));
bp->strm->next_in = (typeof(bp->strm->next_in))zbuf + n;
bp->strm->avail_in = len - n;
bp->strm->next_out = bp->gunzip_buf;
bp->strm->avail_out = FW_BUF_SIZE;
rc = zlib_inflateInit2(bp->strm, -MAX_WBITS);
if (rc != Z_OK)
return rc;
rc = zlib_inflate(bp->strm, Z_FINISH);
if ((rc != Z_OK) && (rc != Z_STREAM_END))
netdev_err(bp->dev, "Firmware decompression error: %s\n",
bp->strm->msg);
bp->gunzip_outlen = (FW_BUF_SIZE - bp->strm->avail_out);
if (bp->gunzip_outlen & 0x3)
netdev_err(bp->dev, "Firmware decompression error:"
" gunzip_outlen (%d) not aligned\n",
bp->gunzip_outlen);
bp->gunzip_outlen >>= 2;
zlib_inflateEnd(bp->strm);
if (rc == Z_STREAM_END)
return 0;
return rc;
}
static void bnx2x_lb_pckt(struct bnx2x *bp)
{
u32 wb_write[3];
wb_write[0] = 0x55555555;
wb_write[1] = 0x55555555;
wb_write[2] = 0x20;
REG_WR_DMAE(bp, NIG_REG_DEBUG_PACKET_LB, wb_write, 3);
wb_write[0] = 0x09000000;
wb_write[1] = 0x55555555;
wb_write[2] = 0x10;
REG_WR_DMAE(bp, NIG_REG_DEBUG_PACKET_LB, wb_write, 3);
}
static int bnx2x_int_mem_test(struct bnx2x *bp)
{
int factor;
int count, i;
u32 val = 0;
if (CHIP_REV_IS_FPGA(bp))
factor = 120;
else if (CHIP_REV_IS_EMUL(bp))
factor = 200;
else
factor = 1;
REG_WR(bp, TSDM_REG_ENABLE_IN1, 0x0);
REG_WR(bp, TCM_REG_PRS_IFEN, 0x0);
REG_WR(bp, CFC_REG_DEBUG0, 0x1);
REG_WR(bp, NIG_REG_PRS_REQ_IN_EN, 0x0);
REG_WR(bp, PRS_REG_CFC_SEARCH_INITIAL_CREDIT, 0x0);
bnx2x_lb_pckt(bp);
count = 1000 * factor;
while (count) {
bnx2x_read_dmae(bp, NIG_REG_STAT2_BRB_OCTET, 2);
val = *bnx2x_sp(bp, wb_data[0]);
if (val == 0x10)
break;
msleep(10);
count--;
}
if (val != 0x10) {
BNX2X_ERR("NIG timeout val = 0x%x\n", val);
return -1;
}
count = 1000 * factor;
while (count) {
val = REG_RD(bp, PRS_REG_NUM_OF_PACKETS);
if (val == 1)
break;
msleep(10);
count--;
}
if (val != 0x1) {
BNX2X_ERR("PRS timeout val = 0x%x\n", val);
return -2;
}
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_CLEAR, 0x03);
msleep(50);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_SET, 0x03);
msleep(50);
bnx2x_init_block(bp, BLOCK_BRB1, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_PRS, PHASE_COMMON);
DP(NETIF_MSG_HW, "part2\n");
REG_WR(bp, TSDM_REG_ENABLE_IN1, 0x0);
REG_WR(bp, TCM_REG_PRS_IFEN, 0x0);
REG_WR(bp, CFC_REG_DEBUG0, 0x1);
REG_WR(bp, NIG_REG_PRS_REQ_IN_EN, 0x0);
REG_WR(bp, PRS_REG_CFC_SEARCH_INITIAL_CREDIT, 0x0);
for (i = 0; i < 10; i++)
bnx2x_lb_pckt(bp);
count = 1000 * factor;
while (count) {
bnx2x_read_dmae(bp, NIG_REG_STAT2_BRB_OCTET, 2);
val = *bnx2x_sp(bp, wb_data[0]);
if (val == 0xb0)
break;
msleep(10);
count--;
}
if (val != 0xb0) {
BNX2X_ERR("NIG timeout val = 0x%x\n", val);
return -3;
}
val = REG_RD(bp, PRS_REG_NUM_OF_PACKETS);
if (val != 2)
BNX2X_ERR("PRS timeout val = 0x%x\n", val);
REG_WR(bp, PRS_REG_CFC_SEARCH_INITIAL_CREDIT, 0x1);
msleep(10 * factor);
val = REG_RD(bp, PRS_REG_NUM_OF_PACKETS);
if (val != 3)
BNX2X_ERR("PRS timeout val = 0x%x\n", val);
for (i = 0; i < 11; i++)
REG_RD(bp, NIG_REG_INGRESS_EOP_LB_FIFO);
val = REG_RD(bp, NIG_REG_INGRESS_EOP_LB_EMPTY);
if (val != 1) {
BNX2X_ERR("clear of NIG failed\n");
return -4;
}
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_CLEAR, 0x03);
msleep(50);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_SET, 0x03);
msleep(50);
bnx2x_init_block(bp, BLOCK_BRB1, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_PRS, PHASE_COMMON);
#ifndef BCM_CNIC
REG_WR(bp, PRS_REG_NIC_MODE, 1);
#endif
REG_WR(bp, TSDM_REG_ENABLE_IN1, 0x7fffffff);
REG_WR(bp, TCM_REG_PRS_IFEN, 0x1);
REG_WR(bp, CFC_REG_DEBUG0, 0x0);
REG_WR(bp, NIG_REG_PRS_REQ_IN_EN, 0x1);
DP(NETIF_MSG_HW, "done\n");
return 0;
}
static void bnx2x_enable_blocks_attention(struct bnx2x *bp)
{
REG_WR(bp, PXP_REG_PXP_INT_MASK_0, 0);
if (!CHIP_IS_E1x(bp))
REG_WR(bp, PXP_REG_PXP_INT_MASK_1, 0x40);
else
REG_WR(bp, PXP_REG_PXP_INT_MASK_1, 0);
REG_WR(bp, DORQ_REG_DORQ_INT_MASK, 0);
REG_WR(bp, CFC_REG_CFC_INT_MASK, 0);
REG_WR(bp, BRB1_REG_BRB1_INT_MASK, 0xFC00);
REG_WR(bp, QM_REG_QM_INT_MASK, 0);
REG_WR(bp, TM_REG_TM_INT_MASK, 0);
REG_WR(bp, XSDM_REG_XSDM_INT_MASK_0, 0);
REG_WR(bp, XSDM_REG_XSDM_INT_MASK_1, 0);
REG_WR(bp, XCM_REG_XCM_INT_MASK, 0);
REG_WR(bp, USDM_REG_USDM_INT_MASK_0, 0);
REG_WR(bp, USDM_REG_USDM_INT_MASK_1, 0);
REG_WR(bp, UCM_REG_UCM_INT_MASK, 0);
REG_WR(bp, GRCBASE_UPB + PB_REG_PB_INT_MASK, 0);
REG_WR(bp, CSDM_REG_CSDM_INT_MASK_0, 0);
REG_WR(bp, CSDM_REG_CSDM_INT_MASK_1, 0);
REG_WR(bp, CCM_REG_CCM_INT_MASK, 0);
if (CHIP_REV_IS_FPGA(bp))
REG_WR(bp, PXP2_REG_PXP2_INT_MASK_0, 0x580000);
else if (!CHIP_IS_E1x(bp))
REG_WR(bp, PXP2_REG_PXP2_INT_MASK_0,
(PXP2_PXP2_INT_MASK_0_REG_PGL_CPL_OF
| PXP2_PXP2_INT_MASK_0_REG_PGL_CPL_AFT
| PXP2_PXP2_INT_MASK_0_REG_PGL_PCIE_ATTN
| PXP2_PXP2_INT_MASK_0_REG_PGL_READ_BLOCKED
| PXP2_PXP2_INT_MASK_0_REG_PGL_WRITE_BLOCKED));
else
REG_WR(bp, PXP2_REG_PXP2_INT_MASK_0, 0x480000);
REG_WR(bp, TSDM_REG_TSDM_INT_MASK_0, 0);
REG_WR(bp, TSDM_REG_TSDM_INT_MASK_1, 0);
REG_WR(bp, TCM_REG_TCM_INT_MASK, 0);
if (!CHIP_IS_E1x(bp))
REG_WR(bp, TSEM_REG_TSEM_INT_MASK_1, 0x07ff);
REG_WR(bp, CDU_REG_CDU_INT_MASK, 0);
REG_WR(bp, DMAE_REG_DMAE_INT_MASK, 0);
REG_WR(bp, PBF_REG_PBF_INT_MASK, 0x18);
}
static void bnx2x_reset_common(struct bnx2x *bp)
{
u32 val = 0x1400;
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_CLEAR,
0xd3ffff7f);
if (CHIP_IS_E3(bp)) {
val |= MISC_REGISTERS_RESET_REG_2_MSTAT0;
val |= MISC_REGISTERS_RESET_REG_2_MSTAT1;
}
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_CLEAR, val);
}
static void bnx2x_setup_dmae(struct bnx2x *bp)
{
bp->dmae_ready = 0;
spin_lock_init(&bp->dmae_lock);
}
static void bnx2x_init_pxp(struct bnx2x *bp)
{
u16 devctl;
int r_order, w_order;
pci_read_config_word(bp->pdev,
pci_pcie_cap(bp->pdev) + PCI_EXP_DEVCTL, &devctl);
DP(NETIF_MSG_HW, "read 0x%x from devctl\n", devctl);
w_order = ((devctl & PCI_EXP_DEVCTL_PAYLOAD) >> 5);
if (bp->mrrs == -1)
r_order = ((devctl & PCI_EXP_DEVCTL_READRQ) >> 12);
else {
DP(NETIF_MSG_HW, "force read order to %d\n", bp->mrrs);
r_order = bp->mrrs;
}
bnx2x_init_pxp_arb(bp, r_order, w_order);
}
static void bnx2x_setup_fan_failure_detection(struct bnx2x *bp)
{
int is_required;
u32 val;
int port;
if (BP_NOMCP(bp))
return;
is_required = 0;
val = SHMEM_RD(bp, dev_info.shared_hw_config.config2) &
SHARED_HW_CFG_FAN_FAILURE_MASK;
if (val == SHARED_HW_CFG_FAN_FAILURE_ENABLED)
is_required = 1;
else if (val == SHARED_HW_CFG_FAN_FAILURE_PHY_TYPE)
for (port = PORT_0; port < PORT_MAX; port++) {
is_required |=
bnx2x_fan_failure_det_req(
bp,
bp->common.shmem_base,
bp->common.shmem2_base,
port);
}
DP(NETIF_MSG_HW, "fan detection setting: %d\n", is_required);
if (is_required == 0)
return;
bnx2x_set_spio(bp, MISC_REGISTERS_SPIO_5,
MISC_REGISTERS_SPIO_INPUT_HI_Z);
val = REG_RD(bp, MISC_REG_SPIO_INT);
val |= ((1 << MISC_REGISTERS_SPIO_5) <<
MISC_REGISTERS_SPIO_INT_OLD_SET_POS);
REG_WR(bp, MISC_REG_SPIO_INT, val);
val = REG_RD(bp, MISC_REG_SPIO_EVENT_EN);
val |= (1 << MISC_REGISTERS_SPIO_5);
REG_WR(bp, MISC_REG_SPIO_EVENT_EN, val);
}
static void bnx2x_pretend_func(struct bnx2x *bp, u8 pretend_func_num)
{
u32 offset = 0;
if (CHIP_IS_E1(bp))
return;
if (CHIP_IS_E1H(bp) && (pretend_func_num >= E1H_FUNC_MAX))
return;
switch (BP_ABS_FUNC(bp)) {
case 0:
offset = PXP2_REG_PGL_PRETEND_FUNC_F0;
break;
case 1:
offset = PXP2_REG_PGL_PRETEND_FUNC_F1;
break;
case 2:
offset = PXP2_REG_PGL_PRETEND_FUNC_F2;
break;
case 3:
offset = PXP2_REG_PGL_PRETEND_FUNC_F3;
break;
case 4:
offset = PXP2_REG_PGL_PRETEND_FUNC_F4;
break;
case 5:
offset = PXP2_REG_PGL_PRETEND_FUNC_F5;
break;
case 6:
offset = PXP2_REG_PGL_PRETEND_FUNC_F6;
break;
case 7:
offset = PXP2_REG_PGL_PRETEND_FUNC_F7;
break;
default:
return;
}
REG_WR(bp, offset, pretend_func_num);
REG_RD(bp, offset);
DP(NETIF_MSG_HW, "Pretending to func %d\n", pretend_func_num);
}
void bnx2x_pf_disable(struct bnx2x *bp)
{
u32 val = REG_RD(bp, IGU_REG_PF_CONFIGURATION);
val &= ~IGU_PF_CONF_FUNC_EN;
REG_WR(bp, IGU_REG_PF_CONFIGURATION, val);
REG_WR(bp, PGLUE_B_REG_INTERNAL_PFID_ENABLE_MASTER, 0);
REG_WR(bp, CFC_REG_WEAK_ENABLE_PF, 0);
}
static inline void bnx2x__common_init_phy(struct bnx2x *bp)
{
u32 shmem_base[2], shmem2_base[2];
shmem_base[0] = bp->common.shmem_base;
shmem2_base[0] = bp->common.shmem2_base;
if (!CHIP_IS_E1x(bp)) {
shmem_base[1] =
SHMEM2_RD(bp, other_shmem_base_addr);
shmem2_base[1] =
SHMEM2_RD(bp, other_shmem2_base_addr);
}
bnx2x_acquire_phy_lock(bp);
bnx2x_common_init_phy(bp, shmem_base, shmem2_base,
bp->common.chip_id);
bnx2x_release_phy_lock(bp);
}
static int bnx2x_init_hw_common(struct bnx2x *bp)
{
u32 val;
DP(BNX2X_MSG_MCP, "starting common init func %d\n", BP_ABS_FUNC(bp));
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_RESET);
bnx2x_reset_common(bp);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_SET, 0xffffffff);
val = 0xfffc;
if (CHIP_IS_E3(bp)) {
val |= MISC_REGISTERS_RESET_REG_2_MSTAT0;
val |= MISC_REGISTERS_RESET_REG_2_MSTAT1;
}
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_SET, val);
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_RESET);
bnx2x_init_block(bp, BLOCK_MISC, PHASE_COMMON);
if (!CHIP_IS_E1x(bp)) {
u8 abs_func_id;
for (abs_func_id = BP_PATH(bp);
abs_func_id < E2_FUNC_MAX*2; abs_func_id += 2) {
if (abs_func_id == BP_ABS_FUNC(bp)) {
REG_WR(bp,
PGLUE_B_REG_INTERNAL_PFID_ENABLE_MASTER,
1);
continue;
}
bnx2x_pretend_func(bp, abs_func_id);
bnx2x_pf_disable(bp);
bnx2x_pretend_func(bp, BP_ABS_FUNC(bp));
}
}
bnx2x_init_block(bp, BLOCK_PXP, PHASE_COMMON);
if (CHIP_IS_E1(bp)) {
REG_WR(bp, PXP_REG_PXP_INT_MASK_0, 0);
}
bnx2x_init_block(bp, BLOCK_PXP2, PHASE_COMMON);
bnx2x_init_pxp(bp);
#ifdef __BIG_ENDIAN
REG_WR(bp, PXP2_REG_RQ_QM_ENDIAN_M, 1);
REG_WR(bp, PXP2_REG_RQ_TM_ENDIAN_M, 1);
REG_WR(bp, PXP2_REG_RQ_SRC_ENDIAN_M, 1);
REG_WR(bp, PXP2_REG_RQ_CDU_ENDIAN_M, 1);
REG_WR(bp, PXP2_REG_RQ_DBG_ENDIAN_M, 1);
REG_WR(bp, PXP2_REG_RQ_HC_ENDIAN_M, 0);
REG_WR(bp, PXP2_REG_RD_QM_SWAP_MODE, 1);
REG_WR(bp, PXP2_REG_RD_TM_SWAP_MODE, 1);
REG_WR(bp, PXP2_REG_RD_SRC_SWAP_MODE, 1);
REG_WR(bp, PXP2_REG_RD_CDURD_SWAP_MODE, 1);
#endif
bnx2x_ilt_init_page_size(bp, INITOP_SET);
if (CHIP_REV_IS_FPGA(bp) && CHIP_IS_E1H(bp))
REG_WR(bp, PXP2_REG_PGL_TAGS_LIMIT, 0x1);
msleep(100);
val = REG_RD(bp, PXP2_REG_RQ_CFG_DONE);
if (val != 1) {
BNX2X_ERR("PXP2 CFG failed\n");
return -EBUSY;
}
val = REG_RD(bp, PXP2_REG_RD_INIT_DONE);
if (val != 1) {
BNX2X_ERR("PXP2 RD_INIT failed\n");
return -EBUSY;
}
if (!CHIP_IS_E1x(bp)) {
struct ilt_client_info ilt_cli;
struct bnx2x_ilt ilt;
memset(&ilt_cli, 0, sizeof(struct ilt_client_info));
memset(&ilt, 0, sizeof(struct bnx2x_ilt));
ilt_cli.start = 0;
ilt_cli.end = ILT_NUM_PAGE_ENTRIES - 1;
ilt_cli.client_num = ILT_CLIENT_TM;
bnx2x_pretend_func(bp, (BP_PATH(bp) + 6));
bnx2x_ilt_client_init_op_ilt(bp, &ilt, &ilt_cli, INITOP_CLEAR);
bnx2x_pretend_func(bp, BP_ABS_FUNC(bp));
REG_WR(bp, PXP2_REG_RQ_DRAM_ALIGN, BNX2X_PXP_DRAM_ALIGN);
REG_WR(bp, PXP2_REG_RQ_DRAM_ALIGN_RD, BNX2X_PXP_DRAM_ALIGN);
REG_WR(bp, PXP2_REG_RQ_DRAM_ALIGN_SEL, 1);
}
REG_WR(bp, PXP2_REG_RQ_DISABLE_INPUTS, 0);
REG_WR(bp, PXP2_REG_RD_DISABLE_INPUTS, 0);
if (!CHIP_IS_E1x(bp)) {
int factor = CHIP_REV_IS_EMUL(bp) ? 1000 :
(CHIP_REV_IS_FPGA(bp) ? 400 : 0);
bnx2x_init_block(bp, BLOCK_PGLUE_B, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_ATC, PHASE_COMMON);
do {
msleep(200);
val = REG_RD(bp, ATC_REG_ATC_INIT_DONE);
} while (factor-- && (val != 1));
if (val != 1) {
BNX2X_ERR("ATC_INIT failed\n");
return -EBUSY;
}
}
bnx2x_init_block(bp, BLOCK_DMAE, PHASE_COMMON);
bp->dmae_ready = 1;
bnx2x_init_fill(bp, TSEM_REG_PRAM, 0, 8, 1);
bnx2x_init_block(bp, BLOCK_TCM, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_UCM, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_CCM, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_XCM, PHASE_COMMON);
bnx2x_read_dmae(bp, XSEM_REG_PASSIVE_BUFFER, 3);
bnx2x_read_dmae(bp, CSEM_REG_PASSIVE_BUFFER, 3);
bnx2x_read_dmae(bp, TSEM_REG_PASSIVE_BUFFER, 3);
bnx2x_read_dmae(bp, USEM_REG_PASSIVE_BUFFER, 3);
bnx2x_init_block(bp, BLOCK_QM, PHASE_COMMON);
bnx2x_qm_init_ptr_table(bp, bp->qm_cid_count, INITOP_SET);
REG_WR(bp, QM_REG_SOFT_RESET, 1);
REG_WR(bp, QM_REG_SOFT_RESET, 0);
#ifdef BCM_CNIC
bnx2x_init_block(bp, BLOCK_TM, PHASE_COMMON);
#endif
bnx2x_init_block(bp, BLOCK_DORQ, PHASE_COMMON);
REG_WR(bp, DORQ_REG_DPM_CID_OFST, BNX2X_DB_SHIFT);
if (!CHIP_REV_IS_SLOW(bp))
REG_WR(bp, DORQ_REG_DORQ_INT_MASK, 0);
bnx2x_init_block(bp, BLOCK_BRB1, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_PRS, PHASE_COMMON);
REG_WR(bp, PRS_REG_A_PRSU_20, 0xf);
if (!CHIP_IS_E1(bp))
REG_WR(bp, PRS_REG_E1HOV_MODE, bp->path_has_ovlan);
if (!CHIP_IS_E1x(bp) && !CHIP_IS_E3B0(bp))
REG_WR(bp, PRS_REG_HDRS_AFTER_BASIC,
bp->path_has_ovlan ? 7 : 6);
bnx2x_init_block(bp, BLOCK_TSDM, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_CSDM, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_USDM, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_XSDM, PHASE_COMMON);
if (!CHIP_IS_E1x(bp)) {
REG_WR(bp, TSEM_REG_FAST_MEMORY + VFC_REG_MEMORIES_RST,
VFC_MEMORIES_RST_REG_CAM_RST |
VFC_MEMORIES_RST_REG_RAM_RST);
REG_WR(bp, XSEM_REG_FAST_MEMORY + VFC_REG_MEMORIES_RST,
VFC_MEMORIES_RST_REG_CAM_RST |
VFC_MEMORIES_RST_REG_RAM_RST);
msleep(20);
}
bnx2x_init_block(bp, BLOCK_TSEM, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_USEM, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_CSEM, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_XSEM, PHASE_COMMON);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_CLEAR,
0x80000000);
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_SET,
0x80000000);
bnx2x_init_block(bp, BLOCK_UPB, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_XPB, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_PBF, PHASE_COMMON);
if (!CHIP_IS_E1x(bp))
REG_WR(bp, PBF_REG_HDRS_AFTER_BASIC,
bp->path_has_ovlan ? 7 : 6);
REG_WR(bp, SRC_REG_SOFT_RST, 1);
bnx2x_init_block(bp, BLOCK_SRC, PHASE_COMMON);
#ifdef BCM_CNIC
REG_WR(bp, SRC_REG_KEYSEARCH_0, 0x63285672);
REG_WR(bp, SRC_REG_KEYSEARCH_1, 0x24b8f2cc);
REG_WR(bp, SRC_REG_KEYSEARCH_2, 0x223aef9b);
REG_WR(bp, SRC_REG_KEYSEARCH_3, 0x26001e3a);
REG_WR(bp, SRC_REG_KEYSEARCH_4, 0x7ae91116);
REG_WR(bp, SRC_REG_KEYSEARCH_5, 0x5ce5230b);
REG_WR(bp, SRC_REG_KEYSEARCH_6, 0x298d8adf);
REG_WR(bp, SRC_REG_KEYSEARCH_7, 0x6eb0ff09);
REG_WR(bp, SRC_REG_KEYSEARCH_8, 0x1830f82f);
REG_WR(bp, SRC_REG_KEYSEARCH_9, 0x01e46be7);
#endif
REG_WR(bp, SRC_REG_SOFT_RST, 0);
if (sizeof(union cdu_context) != 1024)
dev_alert(&bp->pdev->dev, "please adjust the size "
"of cdu_context(%ld)\n",
(long)sizeof(union cdu_context));
bnx2x_init_block(bp, BLOCK_CDU, PHASE_COMMON);
val = (4 << 24) + (0 << 12) + 1024;
REG_WR(bp, CDU_REG_CDU_GLOBAL_PARAMS, val);
bnx2x_init_block(bp, BLOCK_CFC, PHASE_COMMON);
REG_WR(bp, CFC_REG_INIT_REG, 0x7FF);
REG_WR(bp, CFC_REG_CFC_INT_MASK, 0);
REG_WR(bp, CFC_REG_DEBUG0, 0x20020000);
bnx2x_init_block(bp, BLOCK_HC, PHASE_COMMON);
if (!CHIP_IS_E1x(bp) && BP_NOMCP(bp))
REG_WR(bp, IGU_REG_RESET_MEMORIES, 0x36);
bnx2x_init_block(bp, BLOCK_IGU, PHASE_COMMON);
bnx2x_init_block(bp, BLOCK_MISC_AEU, PHASE_COMMON);
REG_WR(bp, 0x2814, 0xffffffff);
REG_WR(bp, 0x3820, 0xffffffff);
if (!CHIP_IS_E1x(bp)) {
REG_WR(bp, PCICFG_OFFSET + PXPCS_TL_CONTROL_5,
(PXPCS_TL_CONTROL_5_ERR_UNSPPORT1 |
PXPCS_TL_CONTROL_5_ERR_UNSPPORT));
REG_WR(bp, PCICFG_OFFSET + PXPCS_TL_FUNC345_STAT,
(PXPCS_TL_FUNC345_STAT_ERR_UNSPPORT4 |
PXPCS_TL_FUNC345_STAT_ERR_UNSPPORT3 |
PXPCS_TL_FUNC345_STAT_ERR_UNSPPORT2));
REG_WR(bp, PCICFG_OFFSET + PXPCS_TL_FUNC678_STAT,
(PXPCS_TL_FUNC678_STAT_ERR_UNSPPORT7 |
PXPCS_TL_FUNC678_STAT_ERR_UNSPPORT6 |
PXPCS_TL_FUNC678_STAT_ERR_UNSPPORT5));
}
bnx2x_init_block(bp, BLOCK_NIG, PHASE_COMMON);
if (!CHIP_IS_E1(bp)) {
if (!CHIP_IS_E3(bp))
REG_WR(bp, NIG_REG_LLH_MF_MODE, IS_MF(bp));
}
if (CHIP_IS_E1H(bp))
REG_WR(bp, NIG_REG_LLH_E1HOV_MODE, IS_MF_SD(bp));
if (CHIP_REV_IS_SLOW(bp))
msleep(200);
val = reg_poll(bp, CFC_REG_LL_INIT_DONE, 1, 100, 10);
if (val != 1) {
BNX2X_ERR("CFC LL_INIT failed\n");
return -EBUSY;
}
val = reg_poll(bp, CFC_REG_AC_INIT_DONE, 1, 100, 10);
if (val != 1) {
BNX2X_ERR("CFC AC_INIT failed\n");
return -EBUSY;
}
val = reg_poll(bp, CFC_REG_CAM_INIT_DONE, 1, 100, 10);
if (val != 1) {
BNX2X_ERR("CFC CAM_INIT failed\n");
return -EBUSY;
}
REG_WR(bp, CFC_REG_DEBUG0, 0);
if (CHIP_IS_E1(bp)) {
bnx2x_read_dmae(bp, NIG_REG_STAT2_BRB_OCTET, 2);
val = *bnx2x_sp(bp, wb_data[0]);
if ((val == 0) && bnx2x_int_mem_test(bp)) {
BNX2X_ERR("internal mem self test failed\n");
return -EBUSY;
}
}
bnx2x_setup_fan_failure_detection(bp);
REG_RD(bp, PXP2_REG_PXP2_INT_STS_CLR_0);
bnx2x_enable_blocks_attention(bp);
bnx2x_enable_blocks_parity(bp);
if (!BP_NOMCP(bp)) {
if (CHIP_IS_E1x(bp))
bnx2x__common_init_phy(bp);
} else
BNX2X_ERR("Bootcode is missing - can not initialize link\n");
return 0;
}
static int bnx2x_init_hw_common_chip(struct bnx2x *bp)
{
int rc = bnx2x_init_hw_common(bp);
if (rc)
return rc;
if (!BP_NOMCP(bp))
bnx2x__common_init_phy(bp);
return 0;
}
static int bnx2x_init_hw_port(struct bnx2x *bp)
{
int port = BP_PORT(bp);
int init_phase = port ? PHASE_PORT1 : PHASE_PORT0;
u32 low, high;
u32 val;
bnx2x__link_reset(bp);
DP(BNX2X_MSG_MCP, "starting port init port %d\n", port);
REG_WR(bp, NIG_REG_MASK_INTERRUPT_PORT0 + port*4, 0);
bnx2x_init_block(bp, BLOCK_MISC, init_phase);
bnx2x_init_block(bp, BLOCK_PXP, init_phase);
bnx2x_init_block(bp, BLOCK_PXP2, init_phase);
if (!CHIP_IS_E1x(bp))
REG_WR(bp, PGLUE_B_REG_INTERNAL_PFID_ENABLE_MASTER, 1);
bnx2x_init_block(bp, BLOCK_ATC, init_phase);
bnx2x_init_block(bp, BLOCK_DMAE, init_phase);
bnx2x_init_block(bp, BLOCK_PGLUE_B, init_phase);
bnx2x_init_block(bp, BLOCK_QM, init_phase);
bnx2x_init_block(bp, BLOCK_TCM, init_phase);
bnx2x_init_block(bp, BLOCK_UCM, init_phase);
bnx2x_init_block(bp, BLOCK_CCM, init_phase);
bnx2x_init_block(bp, BLOCK_XCM, init_phase);
bnx2x_qm_init_cid_count(bp, bp->qm_cid_count, INITOP_SET);
#ifdef BCM_CNIC
bnx2x_init_block(bp, BLOCK_TM, init_phase);
REG_WR(bp, TM_REG_LIN0_SCAN_TIME + port*4, 20);
REG_WR(bp, TM_REG_LIN0_MAX_ACTIVE_CID + port*4, 31);
#endif
bnx2x_init_block(bp, BLOCK_DORQ, init_phase);
if (CHIP_IS_E1(bp) || CHIP_IS_E1H(bp)) {
bnx2x_init_block(bp, BLOCK_BRB1, init_phase);
if (IS_MF(bp))
low = ((bp->flags & ONE_PORT_FLAG) ? 160 : 246);
else if (bp->dev->mtu > 4096) {
if (bp->flags & ONE_PORT_FLAG)
low = 160;
else {
val = bp->dev->mtu;
low = 96 + (val/64) +
((val % 64) ? 1 : 0);
}
} else
low = ((bp->flags & ONE_PORT_FLAG) ? 80 : 160);
high = low + 56;
REG_WR(bp, BRB1_REG_PAUSE_LOW_THRESHOLD_0 + port*4, low);
REG_WR(bp, BRB1_REG_PAUSE_HIGH_THRESHOLD_0 + port*4, high);
}
if (CHIP_MODE_IS_4_PORT(bp))
REG_WR(bp, (BP_PORT(bp) ?
BRB1_REG_MAC_GUARANTIED_1 :
BRB1_REG_MAC_GUARANTIED_0), 40);
bnx2x_init_block(bp, BLOCK_PRS, init_phase);
if (CHIP_IS_E3B0(bp))
REG_WR(bp, BP_PORT(bp) ?
PRS_REG_HDRS_AFTER_BASIC_PORT_1 :
PRS_REG_HDRS_AFTER_BASIC_PORT_0,
(bp->path_has_ovlan ? 7 : 6));
bnx2x_init_block(bp, BLOCK_TSDM, init_phase);
bnx2x_init_block(bp, BLOCK_CSDM, init_phase);
bnx2x_init_block(bp, BLOCK_USDM, init_phase);
bnx2x_init_block(bp, BLOCK_XSDM, init_phase);
bnx2x_init_block(bp, BLOCK_TSEM, init_phase);
bnx2x_init_block(bp, BLOCK_USEM, init_phase);
bnx2x_init_block(bp, BLOCK_CSEM, init_phase);
bnx2x_init_block(bp, BLOCK_XSEM, init_phase);
bnx2x_init_block(bp, BLOCK_UPB, init_phase);
bnx2x_init_block(bp, BLOCK_XPB, init_phase);
bnx2x_init_block(bp, BLOCK_PBF, init_phase);
if (CHIP_IS_E1x(bp)) {
REG_WR(bp, PBF_REG_P0_PAUSE_ENABLE + port*4, 0);
REG_WR(bp, PBF_REG_P0_ARB_THRSH + port*4, (9040/16));
REG_WR(bp, PBF_REG_P0_INIT_CRD + port*4, (9040/16) + 553 - 22);
REG_WR(bp, PBF_REG_INIT_P0 + port*4, 1);
udelay(50);
REG_WR(bp, PBF_REG_INIT_P0 + port*4, 0);
}
#ifdef BCM_CNIC
bnx2x_init_block(bp, BLOCK_SRC, init_phase);
#endif
bnx2x_init_block(bp, BLOCK_CDU, init_phase);
bnx2x_init_block(bp, BLOCK_CFC, init_phase);
if (CHIP_IS_E1(bp)) {
REG_WR(bp, HC_REG_LEADING_EDGE_0 + port*8, 0);
REG_WR(bp, HC_REG_TRAILING_EDGE_0 + port*8, 0);
}
bnx2x_init_block(bp, BLOCK_HC, init_phase);
bnx2x_init_block(bp, BLOCK_IGU, init_phase);
bnx2x_init_block(bp, BLOCK_MISC_AEU, init_phase);
val = IS_MF(bp) ? 0xF7 : 0x7;
val |= CHIP_IS_E1(bp) ? 0 : 0x10;
REG_WR(bp, MISC_REG_AEU_MASK_ATTN_FUNC_0 + port*4, val);
bnx2x_init_block(bp, BLOCK_NIG, init_phase);
if (!CHIP_IS_E1x(bp)) {
REG_WR(bp, BP_PORT(bp) ?
NIG_REG_P1_HDRS_AFTER_BASIC :
NIG_REG_P0_HDRS_AFTER_BASIC,
IS_MF_SD(bp) ? 7 : 6);
if (CHIP_IS_E3(bp))
REG_WR(bp, BP_PORT(bp) ?
NIG_REG_LLH1_MF_MODE :
NIG_REG_LLH_MF_MODE, IS_MF(bp));
}
if (!CHIP_IS_E3(bp))
REG_WR(bp, NIG_REG_XGXS_SERDES0_MODE_SEL + port*4, 1);
if (!CHIP_IS_E1(bp)) {
REG_WR(bp, NIG_REG_LLH0_BRB1_DRV_MASK_MF + port*4,
(IS_MF_SD(bp) ? 0x1 : 0x2));
if (!CHIP_IS_E1x(bp)) {
val = 0;
switch (bp->mf_mode) {
case MULTI_FUNCTION_SD:
val = 1;
break;
case MULTI_FUNCTION_SI:
val = 2;
break;
}
REG_WR(bp, (BP_PORT(bp) ? NIG_REG_LLH1_CLS_TYPE :
NIG_REG_LLH0_CLS_TYPE), val);
}
{
REG_WR(bp, NIG_REG_LLFC_ENABLE_0 + port*4, 0);
REG_WR(bp, NIG_REG_LLFC_OUT_EN_0 + port*4, 0);
REG_WR(bp, NIG_REG_PAUSE_ENABLE_0 + port*4, 1);
}
}
val = REG_RD(bp, MISC_REG_SPIO_EVENT_EN);
if (val & (1 << MISC_REGISTERS_SPIO_5)) {
u32 reg_addr = (port ? MISC_REG_AEU_ENABLE1_FUNC_1_OUT_0 :
MISC_REG_AEU_ENABLE1_FUNC_0_OUT_0);
val = REG_RD(bp, reg_addr);
val |= AEU_INPUTS_ATTN_BITS_SPIO5;
REG_WR(bp, reg_addr, val);
}
return 0;
}
static void bnx2x_ilt_wr(struct bnx2x *bp, u32 index, dma_addr_t addr)
{
int reg;
if (CHIP_IS_E1(bp))
reg = PXP2_REG_RQ_ONCHIP_AT + index*8;
else
reg = PXP2_REG_RQ_ONCHIP_AT_B0 + index*8;
bnx2x_wb_wr(bp, reg, ONCHIP_ADDR1(addr), ONCHIP_ADDR2(addr));
}
static inline void bnx2x_igu_clear_sb(struct bnx2x *bp, u8 idu_sb_id)
{
bnx2x_igu_clear_sb_gen(bp, BP_FUNC(bp), idu_sb_id, true );
}
static inline void bnx2x_clear_func_ilt(struct bnx2x *bp, u32 func)
{
u32 i, base = FUNC_ILT_BASE(func);
for (i = base; i < base + ILT_PER_FUNC; i++)
bnx2x_ilt_wr(bp, i, 0);
}
static int bnx2x_init_hw_func(struct bnx2x *bp)
{
int port = BP_PORT(bp);
int func = BP_FUNC(bp);
int init_phase = PHASE_PF0 + func;
struct bnx2x_ilt *ilt = BP_ILT(bp);
u16 cdu_ilt_start;
u32 addr, val;
u32 main_mem_base, main_mem_size, main_mem_prty_clr;
int i, main_mem_width;
DP(BNX2X_MSG_MCP, "starting func init func %d\n", func);
if (!CHIP_IS_E1x(bp))
bnx2x_pf_flr_clnup(bp);
if (bp->common.int_block == INT_BLOCK_HC) {
addr = (port ? HC_REG_CONFIG_1 : HC_REG_CONFIG_0);
val = REG_RD(bp, addr);
val |= HC_CONFIG_0_REG_MSI_ATTN_EN_0;
REG_WR(bp, addr, val);
}
bnx2x_init_block(bp, BLOCK_PXP, init_phase);
bnx2x_init_block(bp, BLOCK_PXP2, init_phase);
ilt = BP_ILT(bp);
cdu_ilt_start = ilt->clients[ILT_CLIENT_CDU].start;
for (i = 0; i < L2_ILT_LINES(bp); i++) {
ilt->lines[cdu_ilt_start + i].page =
bp->context.vcxt + (ILT_PAGE_CIDS * i);
ilt->lines[cdu_ilt_start + i].page_mapping =
bp->context.cxt_mapping + (CDU_ILT_PAGE_SZ * i);
}
bnx2x_ilt_init_op(bp, INITOP_SET);
#ifdef BCM_CNIC
bnx2x_src_init_t2(bp, bp->t2, bp->t2_mapping, SRC_CONN_NUM);
REG_WR(bp, SRC_REG_NUMBER_HASH_BITS0 + port*4, SRC_HASH_BITS);
#endif
#ifndef BCM_CNIC
REG_WR(bp, PRS_REG_NIC_MODE, 1);
#endif
if (!CHIP_IS_E1x(bp)) {
u32 pf_conf = IGU_PF_CONF_FUNC_EN;
if (!(bp->flags & USING_MSIX_FLAG))
pf_conf |= IGU_PF_CONF_SINGLE_ISR_EN;
msleep(20);
REG_WR(bp, PGLUE_B_REG_INTERNAL_PFID_ENABLE_MASTER, 1);
REG_WR(bp, IGU_REG_PF_CONFIGURATION, pf_conf);
}
bp->dmae_ready = 1;
bnx2x_init_block(bp, BLOCK_PGLUE_B, init_phase);
if (!CHIP_IS_E1x(bp))
REG_WR(bp, PGLUE_B_REG_WAS_ERROR_PF_7_0_CLR, func);
bnx2x_init_block(bp, BLOCK_ATC, init_phase);
bnx2x_init_block(bp, BLOCK_DMAE, init_phase);
bnx2x_init_block(bp, BLOCK_NIG, init_phase);
bnx2x_init_block(bp, BLOCK_SRC, init_phase);
bnx2x_init_block(bp, BLOCK_MISC, init_phase);
bnx2x_init_block(bp, BLOCK_TCM, init_phase);
bnx2x_init_block(bp, BLOCK_UCM, init_phase);
bnx2x_init_block(bp, BLOCK_CCM, init_phase);
bnx2x_init_block(bp, BLOCK_XCM, init_phase);
bnx2x_init_block(bp, BLOCK_TSEM, init_phase);
bnx2x_init_block(bp, BLOCK_USEM, init_phase);
bnx2x_init_block(bp, BLOCK_CSEM, init_phase);
bnx2x_init_block(bp, BLOCK_XSEM, init_phase);
if (!CHIP_IS_E1x(bp))
REG_WR(bp, QM_REG_PF_EN, 1);
if (!CHIP_IS_E1x(bp)) {
REG_WR(bp, TSEM_REG_VFPF_ERR_NUM, BNX2X_MAX_NUM_OF_VFS + func);
REG_WR(bp, USEM_REG_VFPF_ERR_NUM, BNX2X_MAX_NUM_OF_VFS + func);
REG_WR(bp, CSEM_REG_VFPF_ERR_NUM, BNX2X_MAX_NUM_OF_VFS + func);
REG_WR(bp, XSEM_REG_VFPF_ERR_NUM, BNX2X_MAX_NUM_OF_VFS + func);
}
bnx2x_init_block(bp, BLOCK_QM, init_phase);
bnx2x_init_block(bp, BLOCK_TM, init_phase);
bnx2x_init_block(bp, BLOCK_DORQ, init_phase);
bnx2x_init_block(bp, BLOCK_BRB1, init_phase);
bnx2x_init_block(bp, BLOCK_PRS, init_phase);
bnx2x_init_block(bp, BLOCK_TSDM, init_phase);
bnx2x_init_block(bp, BLOCK_CSDM, init_phase);
bnx2x_init_block(bp, BLOCK_USDM, init_phase);
bnx2x_init_block(bp, BLOCK_XSDM, init_phase);
bnx2x_init_block(bp, BLOCK_UPB, init_phase);
bnx2x_init_block(bp, BLOCK_XPB, init_phase);
bnx2x_init_block(bp, BLOCK_PBF, init_phase);
if (!CHIP_IS_E1x(bp))
REG_WR(bp, PBF_REG_DISABLE_PF, 0);
bnx2x_init_block(bp, BLOCK_CDU, init_phase);
bnx2x_init_block(bp, BLOCK_CFC, init_phase);
if (!CHIP_IS_E1x(bp))
REG_WR(bp, CFC_REG_WEAK_ENABLE_PF, 1);
if (IS_MF(bp)) {
REG_WR(bp, NIG_REG_LLH0_FUNC_EN + port*8, 1);
REG_WR(bp, NIG_REG_LLH0_FUNC_VLAN_ID + port*8, bp->mf_ov);
}
bnx2x_init_block(bp, BLOCK_MISC_AEU, init_phase);
if (bp->common.int_block == INT_BLOCK_HC) {
if (CHIP_IS_E1H(bp)) {
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_12 + func*4, 0);
REG_WR(bp, HC_REG_LEADING_EDGE_0 + port*8, 0);
REG_WR(bp, HC_REG_TRAILING_EDGE_0 + port*8, 0);
}
bnx2x_init_block(bp, BLOCK_HC, init_phase);
} else {
int num_segs, sb_idx, prod_offset;
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_12 + func*4, 0);
if (!CHIP_IS_E1x(bp)) {
REG_WR(bp, IGU_REG_LEADING_EDGE_LATCH, 0);
REG_WR(bp, IGU_REG_TRAILING_EDGE_LATCH, 0);
}
bnx2x_init_block(bp, BLOCK_IGU, init_phase);
if (!CHIP_IS_E1x(bp)) {
int dsb_idx = 0;
num_segs = CHIP_INT_MODE_IS_BC(bp) ?
IGU_BC_NDSB_NUM_SEGS : IGU_NORM_NDSB_NUM_SEGS;
for (sb_idx = 0; sb_idx < bp->igu_sb_cnt; sb_idx++) {
prod_offset = (bp->igu_base_sb + sb_idx) *
num_segs;
for (i = 0; i < num_segs; i++) {
addr = IGU_REG_PROD_CONS_MEMORY +
(prod_offset + i) * 4;
REG_WR(bp, addr, 0);
}
bnx2x_ack_sb(bp, bp->igu_base_sb + sb_idx,
USTORM_ID, 0, IGU_INT_NOP, 1);
bnx2x_igu_clear_sb(bp,
bp->igu_base_sb + sb_idx);
}
num_segs = CHIP_INT_MODE_IS_BC(bp) ?
IGU_BC_DSB_NUM_SEGS : IGU_NORM_DSB_NUM_SEGS;
if (CHIP_MODE_IS_4_PORT(bp))
dsb_idx = BP_FUNC(bp);
else
dsb_idx = BP_VN(bp);
prod_offset = (CHIP_INT_MODE_IS_BC(bp) ?
IGU_BC_BASE_DSB_PROD + dsb_idx :
IGU_NORM_BASE_DSB_PROD + dsb_idx);
for (i = 0; i < (num_segs * E1HVN_MAX);
i += E1HVN_MAX) {
addr = IGU_REG_PROD_CONS_MEMORY +
(prod_offset + i)*4;
REG_WR(bp, addr, 0);
}
if (CHIP_INT_MODE_IS_BC(bp)) {
bnx2x_ack_sb(bp, bp->igu_dsb_id,
USTORM_ID, 0, IGU_INT_NOP, 1);
bnx2x_ack_sb(bp, bp->igu_dsb_id,
CSTORM_ID, 0, IGU_INT_NOP, 1);
bnx2x_ack_sb(bp, bp->igu_dsb_id,
XSTORM_ID, 0, IGU_INT_NOP, 1);
bnx2x_ack_sb(bp, bp->igu_dsb_id,
TSTORM_ID, 0, IGU_INT_NOP, 1);
bnx2x_ack_sb(bp, bp->igu_dsb_id,
ATTENTION_ID, 0, IGU_INT_NOP, 1);
} else {
bnx2x_ack_sb(bp, bp->igu_dsb_id,
USTORM_ID, 0, IGU_INT_NOP, 1);
bnx2x_ack_sb(bp, bp->igu_dsb_id,
ATTENTION_ID, 0, IGU_INT_NOP, 1);
}
bnx2x_igu_clear_sb(bp, bp->igu_dsb_id);
REG_WR(bp, IGU_REG_SB_INT_BEFORE_MASK_LSB, 0);
REG_WR(bp, IGU_REG_SB_INT_BEFORE_MASK_MSB, 0);
REG_WR(bp, IGU_REG_SB_MASK_LSB, 0);
REG_WR(bp, IGU_REG_SB_MASK_MSB, 0);
REG_WR(bp, IGU_REG_PBA_STATUS_LSB, 0);
REG_WR(bp, IGU_REG_PBA_STATUS_MSB, 0);
}
}
REG_WR(bp, 0x2114, 0xffffffff);
REG_WR(bp, 0x2120, 0xffffffff);
if (CHIP_IS_E1x(bp)) {
main_mem_size = HC_REG_MAIN_MEMORY_SIZE / 2;
main_mem_base = HC_REG_MAIN_MEMORY +
BP_PORT(bp) * (main_mem_size * 4);
main_mem_prty_clr = HC_REG_HC_PRTY_STS_CLR;
main_mem_width = 8;
val = REG_RD(bp, main_mem_prty_clr);
if (val)
DP(BNX2X_MSG_MCP, "Hmmm... Parity errors in HC "
"block during "
"function init (0x%x)!\n", val);
for (i = main_mem_base;
i < main_mem_base + main_mem_size * 4;
i += main_mem_width) {
bnx2x_read_dmae(bp, i, main_mem_width / 4);
bnx2x_write_dmae(bp, bnx2x_sp_mapping(bp, wb_data),
i, main_mem_width / 4);
}
REG_RD(bp, main_mem_prty_clr);
}
#ifdef BNX2X_STOP_ON_ERROR
REG_WR8(bp, BAR_USTRORM_INTMEM +
USTORM_RECORD_SLOW_PATH_OFFSET(BP_FUNC(bp)), 1);
REG_WR8(bp, BAR_TSTRORM_INTMEM +
TSTORM_RECORD_SLOW_PATH_OFFSET(BP_FUNC(bp)), 1);
REG_WR8(bp, BAR_CSTRORM_INTMEM +
CSTORM_RECORD_SLOW_PATH_OFFSET(BP_FUNC(bp)), 1);
REG_WR8(bp, BAR_XSTRORM_INTMEM +
XSTORM_RECORD_SLOW_PATH_OFFSET(BP_FUNC(bp)), 1);
#endif
bnx2x_phy_probe(&bp->link_params);
return 0;
}
void bnx2x_free_mem(struct bnx2x *bp)
{
bnx2x_free_fp_mem(bp);
BNX2X_PCI_FREE(bp->def_status_blk, bp->def_status_blk_mapping,
sizeof(struct host_sp_status_block));
BNX2X_PCI_FREE(bp->fw_stats, bp->fw_stats_mapping,
bp->fw_stats_data_sz + bp->fw_stats_req_sz);
BNX2X_PCI_FREE(bp->slowpath, bp->slowpath_mapping,
sizeof(struct bnx2x_slowpath));
BNX2X_PCI_FREE(bp->context.vcxt, bp->context.cxt_mapping,
bp->context.size);
bnx2x_ilt_mem_op(bp, ILT_MEMOP_FREE);
BNX2X_FREE(bp->ilt->lines);
#ifdef BCM_CNIC
if (!CHIP_IS_E1x(bp))
BNX2X_PCI_FREE(bp->cnic_sb.e2_sb, bp->cnic_sb_mapping,
sizeof(struct host_hc_status_block_e2));
else
BNX2X_PCI_FREE(bp->cnic_sb.e1x_sb, bp->cnic_sb_mapping,
sizeof(struct host_hc_status_block_e1x));
BNX2X_PCI_FREE(bp->t2, bp->t2_mapping, SRC_T2_SZ);
#endif
BNX2X_PCI_FREE(bp->spq, bp->spq_mapping, BCM_PAGE_SIZE);
BNX2X_PCI_FREE(bp->eq_ring, bp->eq_mapping,
BCM_PAGE_SIZE * NUM_EQ_PAGES);
}
static inline int bnx2x_alloc_fw_stats_mem(struct bnx2x *bp)
{
int num_groups;
u8 num_queue_stats = BNX2X_NUM_ETH_QUEUES(bp);
bp->fw_stats_num = 2 + num_queue_stats;
num_groups = (2 + num_queue_stats) / STATS_QUERY_CMD_COUNT +
(((2 + num_queue_stats) % STATS_QUERY_CMD_COUNT) ? 1 : 0);
bp->fw_stats_req_sz = sizeof(struct stats_query_header) +
num_groups * sizeof(struct stats_query_cmd_group);
bp->fw_stats_data_sz = sizeof(struct per_port_stats) +
sizeof(struct per_pf_stats) +
sizeof(struct per_queue_stats) * num_queue_stats +
sizeof(struct stats_counter);
BNX2X_PCI_ALLOC(bp->fw_stats, &bp->fw_stats_mapping,
bp->fw_stats_data_sz + bp->fw_stats_req_sz);
bp->fw_stats_req = (struct bnx2x_fw_stats_req *)bp->fw_stats;
bp->fw_stats_req_mapping = bp->fw_stats_mapping;
bp->fw_stats_data = (struct bnx2x_fw_stats_data *)
((u8 *)bp->fw_stats + bp->fw_stats_req_sz);
bp->fw_stats_data_mapping = bp->fw_stats_mapping +
bp->fw_stats_req_sz;
return 0;
alloc_mem_err:
BNX2X_PCI_FREE(bp->fw_stats, bp->fw_stats_mapping,
bp->fw_stats_data_sz + bp->fw_stats_req_sz);
return -ENOMEM;
}
int bnx2x_alloc_mem(struct bnx2x *bp)
{
#ifdef BCM_CNIC
if (!CHIP_IS_E1x(bp))
BNX2X_PCI_ALLOC(bp->cnic_sb.e2_sb, &bp->cnic_sb_mapping,
sizeof(struct host_hc_status_block_e2));
else
BNX2X_PCI_ALLOC(bp->cnic_sb.e1x_sb, &bp->cnic_sb_mapping,
sizeof(struct host_hc_status_block_e1x));
BNX2X_PCI_ALLOC(bp->t2, &bp->t2_mapping, SRC_T2_SZ);
#endif
BNX2X_PCI_ALLOC(bp->def_status_blk, &bp->def_status_blk_mapping,
sizeof(struct host_sp_status_block));
BNX2X_PCI_ALLOC(bp->slowpath, &bp->slowpath_mapping,
sizeof(struct bnx2x_slowpath));
if (bnx2x_alloc_fw_stats_mem(bp))
goto alloc_mem_err;
bp->context.size = sizeof(union cdu_context) * BNX2X_L2_CID_COUNT(bp);
BNX2X_PCI_ALLOC(bp->context.vcxt, &bp->context.cxt_mapping,
bp->context.size);
BNX2X_ALLOC(bp->ilt->lines, sizeof(struct ilt_line) * ILT_MAX_LINES);
if (bnx2x_ilt_mem_op(bp, ILT_MEMOP_ALLOC))
goto alloc_mem_err;
BNX2X_PCI_ALLOC(bp->spq, &bp->spq_mapping, BCM_PAGE_SIZE);
BNX2X_PCI_ALLOC(bp->eq_ring, &bp->eq_mapping,
BCM_PAGE_SIZE * NUM_EQ_PAGES);
if (bnx2x_alloc_fp_mem(bp))
goto alloc_mem_err;
return 0;
alloc_mem_err:
bnx2x_free_mem(bp);
return -ENOMEM;
}
int bnx2x_set_mac_one(struct bnx2x *bp, u8 *mac,
struct bnx2x_vlan_mac_obj *obj, bool set,
int mac_type, unsigned long *ramrod_flags)
{
int rc;
struct bnx2x_vlan_mac_ramrod_params ramrod_param;
memset(&ramrod_param, 0, sizeof(ramrod_param));
ramrod_param.vlan_mac_obj = obj;
ramrod_param.ramrod_flags = *ramrod_flags;
if (!test_bit(RAMROD_CONT, ramrod_flags)) {
memcpy(ramrod_param.user_req.u.mac.mac, mac, ETH_ALEN);
__set_bit(mac_type, &ramrod_param.user_req.vlan_mac_flags);
if (set)
ramrod_param.user_req.cmd = BNX2X_VLAN_MAC_ADD;
else
ramrod_param.user_req.cmd = BNX2X_VLAN_MAC_DEL;
}
rc = bnx2x_config_vlan_mac(bp, &ramrod_param);
if (rc < 0)
BNX2X_ERR("%s MAC failed\n", (set ? "Set" : "Del"));
return rc;
}
int bnx2x_del_all_macs(struct bnx2x *bp,
struct bnx2x_vlan_mac_obj *mac_obj,
int mac_type, bool wait_for_comp)
{
int rc;
unsigned long ramrod_flags = 0, vlan_mac_flags = 0;
if (wait_for_comp)
__set_bit(RAMROD_COMP_WAIT, &ramrod_flags);
__set_bit(mac_type, &vlan_mac_flags);
rc = mac_obj->delete_all(bp, mac_obj, &vlan_mac_flags, &ramrod_flags);
if (rc < 0)
BNX2X_ERR("Failed to delete MACs: %d\n", rc);
return rc;
}
int bnx2x_set_eth_mac(struct bnx2x *bp, bool set)
{
unsigned long ramrod_flags = 0;
DP(NETIF_MSG_IFUP, "Adding Eth MAC\n");
__set_bit(RAMROD_COMP_WAIT, &ramrod_flags);
return bnx2x_set_mac_one(bp, bp->dev->dev_addr, &bp->fp->mac_obj, set,
BNX2X_ETH_MAC, &ramrod_flags);
}
int bnx2x_setup_leading(struct bnx2x *bp)
{
return bnx2x_setup_queue(bp, &bp->fp[0], 1);
}
static void __devinit bnx2x_set_int_mode(struct bnx2x *bp)
{
switch (int_mode) {
case INT_MODE_MSI:
bnx2x_enable_msi(bp);
case INT_MODE_INTx:
bp->num_queues = 1 + NON_ETH_CONTEXT_USE;
DP(NETIF_MSG_IFUP, "set number of queues to 1\n");
break;
default:
bnx2x_set_num_queues(bp);
DP(NETIF_MSG_IFUP, "set number of queues to %d\n",
bp->num_queues);
if (bnx2x_enable_msix(bp)) {
if (bp->multi_mode)
DP(NETIF_MSG_IFUP,
"Multi requested but failed to "
"enable MSI-X (%d), "
"set number of queues to %d\n",
bp->num_queues,
1 + NON_ETH_CONTEXT_USE);
bp->num_queues = 1 + NON_ETH_CONTEXT_USE;
if (!(bp->flags & DISABLE_MSI_FLAG))
bnx2x_enable_msi(bp);
}
break;
}
}
static inline u16 bnx2x_cid_ilt_lines(struct bnx2x *bp)
{
return L2_ILT_LINES(bp);
}
void bnx2x_ilt_set_info(struct bnx2x *bp)
{
struct ilt_client_info *ilt_client;
struct bnx2x_ilt *ilt = BP_ILT(bp);
u16 line = 0;
ilt->start_line = FUNC_ILT_BASE(BP_FUNC(bp));
DP(BNX2X_MSG_SP, "ilt starts at line %d\n", ilt->start_line);
ilt_client = &ilt->clients[ILT_CLIENT_CDU];
ilt_client->client_num = ILT_CLIENT_CDU;
ilt_client->page_size = CDU_ILT_PAGE_SZ;
ilt_client->flags = ILT_CLIENT_SKIP_MEM;
ilt_client->start = line;
line += bnx2x_cid_ilt_lines(bp);
#ifdef BCM_CNIC
line += CNIC_ILT_LINES;
#endif
ilt_client->end = line - 1;
DP(BNX2X_MSG_SP, "ilt client[CDU]: start %d, end %d, psz 0x%x, "
"flags 0x%x, hw psz %d\n",
ilt_client->start,
ilt_client->end,
ilt_client->page_size,
ilt_client->flags,
ilog2(ilt_client->page_size >> 12));
if (QM_INIT(bp->qm_cid_count)) {
ilt_client = &ilt->clients[ILT_CLIENT_QM];
ilt_client->client_num = ILT_CLIENT_QM;
ilt_client->page_size = QM_ILT_PAGE_SZ;
ilt_client->flags = 0;
ilt_client->start = line;
line += DIV_ROUND_UP(bp->qm_cid_count * QM_QUEUES_PER_FUNC * 4,
QM_ILT_PAGE_SZ);
ilt_client->end = line - 1;
DP(BNX2X_MSG_SP, "ilt client[QM]: start %d, end %d, psz 0x%x, "
"flags 0x%x, hw psz %d\n",
ilt_client->start,
ilt_client->end,
ilt_client->page_size,
ilt_client->flags,
ilog2(ilt_client->page_size >> 12));
}
ilt_client = &ilt->clients[ILT_CLIENT_SRC];
#ifdef BCM_CNIC
ilt_client->client_num = ILT_CLIENT_SRC;
ilt_client->page_size = SRC_ILT_PAGE_SZ;
ilt_client->flags = 0;
ilt_client->start = line;
line += SRC_ILT_LINES;
ilt_client->end = line - 1;
DP(BNX2X_MSG_SP, "ilt client[SRC]: start %d, end %d, psz 0x%x, "
"flags 0x%x, hw psz %d\n",
ilt_client->start,
ilt_client->end,
ilt_client->page_size,
ilt_client->flags,
ilog2(ilt_client->page_size >> 12));
#else
ilt_client->flags = (ILT_CLIENT_SKIP_INIT | ILT_CLIENT_SKIP_MEM);
#endif
ilt_client = &ilt->clients[ILT_CLIENT_TM];
#ifdef BCM_CNIC
ilt_client->client_num = ILT_CLIENT_TM;
ilt_client->page_size = TM_ILT_PAGE_SZ;
ilt_client->flags = 0;
ilt_client->start = line;
line += TM_ILT_LINES;
ilt_client->end = line - 1;
DP(BNX2X_MSG_SP, "ilt client[TM]: start %d, end %d, psz 0x%x, "
"flags 0x%x, hw psz %d\n",
ilt_client->start,
ilt_client->end,
ilt_client->page_size,
ilt_client->flags,
ilog2(ilt_client->page_size >> 12));
#else
ilt_client->flags = (ILT_CLIENT_SKIP_INIT | ILT_CLIENT_SKIP_MEM);
#endif
BUG_ON(line > ILT_MAX_LINES);
}
static inline void bnx2x_pf_q_prep_init(struct bnx2x *bp,
struct bnx2x_fastpath *fp, struct bnx2x_queue_init_params *init_params)
{
u8 cos;
if (!IS_FCOE_FP(fp)) {
__set_bit(BNX2X_Q_FLG_HC, &init_params->rx.flags);
__set_bit(BNX2X_Q_FLG_HC, &init_params->tx.flags);
__set_bit(BNX2X_Q_FLG_HC_EN, &init_params->rx.flags);
__set_bit(BNX2X_Q_FLG_HC_EN, &init_params->tx.flags);
init_params->rx.hc_rate = bp->rx_ticks ?
(1000000 / bp->rx_ticks) : 0;
init_params->tx.hc_rate = bp->tx_ticks ?
(1000000 / bp->tx_ticks) : 0;
init_params->rx.fw_sb_id = init_params->tx.fw_sb_id =
fp->fw_sb_id;
init_params->rx.sb_cq_index = HC_INDEX_ETH_RX_CQ_CONS;
init_params->tx.sb_cq_index = HC_INDEX_ETH_FIRST_TX_CQ_CONS;
}
init_params->max_cos = fp->max_cos;
DP(BNX2X_MSG_SP, "fp: %d setting queue params max cos to: %d\n",
fp->index, init_params->max_cos);
for (cos = FIRST_TX_COS_INDEX; cos < init_params->max_cos; cos++)
init_params->cxts[cos] =
&bp->context.vcxt[fp->txdata[cos].cid].eth;
}
int bnx2x_setup_tx_only(struct bnx2x *bp, struct bnx2x_fastpath *fp,
struct bnx2x_queue_state_params *q_params,
struct bnx2x_queue_setup_tx_only_params *tx_only_params,
int tx_index, bool leading)
{
memset(tx_only_params, 0, sizeof(*tx_only_params));
q_params->cmd = BNX2X_Q_CMD_SETUP_TX_ONLY;
tx_only_params->flags = bnx2x_get_common_flags(bp, fp, false);
tx_only_params->cid_index = tx_index;
bnx2x_pf_q_prep_general(bp, fp, &tx_only_params->gen_params, tx_index);
bnx2x_pf_tx_q_prep(bp, fp, &tx_only_params->txq_params, tx_index);
DP(BNX2X_MSG_SP, "preparing to send tx-only ramrod for connection:"
"cos %d, primary cid %d, cid %d, "
"client id %d, sp-client id %d, flags %lx\n",
tx_index, q_params->q_obj->cids[FIRST_TX_COS_INDEX],
q_params->q_obj->cids[tx_index], q_params->q_obj->cl_id,
tx_only_params->gen_params.spcl_id, tx_only_params->flags);
return bnx2x_queue_state_change(bp, q_params);
}
int bnx2x_setup_queue(struct bnx2x *bp, struct bnx2x_fastpath *fp,
bool leading)
{
struct bnx2x_queue_state_params q_params = {0};
struct bnx2x_queue_setup_params *setup_params =
&q_params.params.setup;
struct bnx2x_queue_setup_tx_only_params *tx_only_params =
&q_params.params.tx_only;
int rc;
u8 tx_index;
DP(BNX2X_MSG_SP, "setting up queue %d\n", fp->index);
if (!IS_FCOE_FP(fp))
bnx2x_ack_sb(bp, fp->igu_sb_id, USTORM_ID, 0,
IGU_INT_ENABLE, 0);
q_params.q_obj = &fp->q_obj;
__set_bit(RAMROD_COMP_WAIT, &q_params.ramrod_flags);
bnx2x_pf_q_prep_init(bp, fp, &q_params.params.init);
q_params.cmd = BNX2X_Q_CMD_INIT;
rc = bnx2x_queue_state_change(bp, &q_params);
if (rc) {
BNX2X_ERR("Queue(%d) INIT failed\n", fp->index);
return rc;
}
DP(BNX2X_MSG_SP, "init complete\n");
memset(setup_params, 0, sizeof(*setup_params));
setup_params->flags = bnx2x_get_q_flags(bp, fp, leading);
bnx2x_pf_q_prep_general(bp, fp, &setup_params->gen_params,
FIRST_TX_COS_INDEX);
bnx2x_pf_rx_q_prep(bp, fp, &setup_params->pause_params,
&setup_params->rxq_params);
bnx2x_pf_tx_q_prep(bp, fp, &setup_params->txq_params,
FIRST_TX_COS_INDEX);
q_params.cmd = BNX2X_Q_CMD_SETUP;
rc = bnx2x_queue_state_change(bp, &q_params);
if (rc) {
BNX2X_ERR("Queue(%d) SETUP failed\n", fp->index);
return rc;
}
for (tx_index = FIRST_TX_ONLY_COS_INDEX;
tx_index < fp->max_cos;
tx_index++) {
rc = bnx2x_setup_tx_only(bp, fp, &q_params,
tx_only_params, tx_index, leading);
if (rc) {
BNX2X_ERR("Queue(%d.%d) TX_ONLY_SETUP failed\n",
fp->index, tx_index);
return rc;
}
}
return rc;
}
static int bnx2x_stop_queue(struct bnx2x *bp, int index)
{
struct bnx2x_fastpath *fp = &bp->fp[index];
struct bnx2x_fp_txdata *txdata;
struct bnx2x_queue_state_params q_params = {0};
int rc, tx_index;
DP(BNX2X_MSG_SP, "stopping queue %d cid %d\n", index, fp->cid);
q_params.q_obj = &fp->q_obj;
__set_bit(RAMROD_COMP_WAIT, &q_params.ramrod_flags);
for (tx_index = FIRST_TX_ONLY_COS_INDEX;
tx_index < fp->max_cos;
tx_index++){
txdata = &fp->txdata[tx_index];
DP(BNX2X_MSG_SP, "stopping tx-only queue %d\n",
txdata->txq_index);
q_params.cmd = BNX2X_Q_CMD_TERMINATE;
memset(&q_params.params.terminate, 0,
sizeof(q_params.params.terminate));
q_params.params.terminate.cid_index = tx_index;
rc = bnx2x_queue_state_change(bp, &q_params);
if (rc)
return rc;
q_params.cmd = BNX2X_Q_CMD_CFC_DEL;
memset(&q_params.params.cfc_del, 0,
sizeof(q_params.params.cfc_del));
q_params.params.cfc_del.cid_index = tx_index;
rc = bnx2x_queue_state_change(bp, &q_params);
if (rc)
return rc;
}
q_params.cmd = BNX2X_Q_CMD_HALT;
rc = bnx2x_queue_state_change(bp, &q_params);
if (rc)
return rc;
q_params.cmd = BNX2X_Q_CMD_TERMINATE;
memset(&q_params.params.terminate, 0,
sizeof(q_params.params.terminate));
q_params.params.terminate.cid_index = FIRST_TX_COS_INDEX;
rc = bnx2x_queue_state_change(bp, &q_params);
if (rc)
return rc;
q_params.cmd = BNX2X_Q_CMD_CFC_DEL;
memset(&q_params.params.cfc_del, 0,
sizeof(q_params.params.cfc_del));
q_params.params.cfc_del.cid_index = FIRST_TX_COS_INDEX;
return bnx2x_queue_state_change(bp, &q_params);
}
static void bnx2x_reset_func(struct bnx2x *bp)
{
int port = BP_PORT(bp);
int func = BP_FUNC(bp);
int i;
REG_WR8(bp, BAR_XSTRORM_INTMEM + XSTORM_FUNC_EN_OFFSET(func), 0);
REG_WR8(bp, BAR_CSTRORM_INTMEM + CSTORM_FUNC_EN_OFFSET(func), 0);
REG_WR8(bp, BAR_TSTRORM_INTMEM + TSTORM_FUNC_EN_OFFSET(func), 0);
REG_WR8(bp, BAR_USTRORM_INTMEM + USTORM_FUNC_EN_OFFSET(func), 0);
for_each_eth_queue(bp, i) {
struct bnx2x_fastpath *fp = &bp->fp[i];
REG_WR8(bp, BAR_CSTRORM_INTMEM +
CSTORM_STATUS_BLOCK_DATA_STATE_OFFSET(fp->fw_sb_id),
SB_DISABLED);
}
#ifdef BCM_CNIC
REG_WR8(bp, BAR_CSTRORM_INTMEM +
CSTORM_STATUS_BLOCK_DATA_STATE_OFFSET(bnx2x_cnic_fw_sb_id(bp)),
SB_DISABLED);
#endif
REG_WR8(bp, BAR_CSTRORM_INTMEM +
CSTORM_SP_STATUS_BLOCK_DATA_STATE_OFFSET(func),
SB_DISABLED);
for (i = 0; i < XSTORM_SPQ_DATA_SIZE / 4; i++)
REG_WR(bp, BAR_XSTRORM_INTMEM + XSTORM_SPQ_DATA_OFFSET(func),
0);
if (bp->common.int_block == INT_BLOCK_HC) {
REG_WR(bp, HC_REG_LEADING_EDGE_0 + port*8, 0);
REG_WR(bp, HC_REG_TRAILING_EDGE_0 + port*8, 0);
} else {
REG_WR(bp, IGU_REG_LEADING_EDGE_LATCH, 0);
REG_WR(bp, IGU_REG_TRAILING_EDGE_LATCH, 0);
}
#ifdef BCM_CNIC
REG_WR(bp, TM_REG_EN_LINEAR0_TIMER + port*4, 0);
for (i = 0; i < 200; i++) {
msleep(10);
if (!REG_RD(bp, TM_REG_LIN0_SCAN_ON + port*4))
break;
}
#endif
bnx2x_clear_func_ilt(bp, func);
if (!CHIP_IS_E1x(bp) && BP_VN(bp) == 3) {
struct ilt_client_info ilt_cli;
memset(&ilt_cli, 0, sizeof(struct ilt_client_info));
ilt_cli.start = 0;
ilt_cli.end = ILT_NUM_PAGE_ENTRIES - 1;
ilt_cli.client_num = ILT_CLIENT_TM;
bnx2x_ilt_boundry_init_op(bp, &ilt_cli, 0, INITOP_CLEAR);
}
if (!CHIP_IS_E1x(bp))
bnx2x_pf_disable(bp);
bp->dmae_ready = 0;
}
static void bnx2x_reset_port(struct bnx2x *bp)
{
int port = BP_PORT(bp);
u32 val;
bnx2x__link_reset(bp);
REG_WR(bp, NIG_REG_MASK_INTERRUPT_PORT0 + port*4, 0);
REG_WR(bp, NIG_REG_LLH0_BRB1_DRV_MASK + port*4, 0x0);
REG_WR(bp, (port ? NIG_REG_LLH1_BRB1_NOT_MCP :
NIG_REG_LLH0_BRB1_NOT_MCP), 0x0);
REG_WR(bp, MISC_REG_AEU_MASK_ATTN_FUNC_0 + port*4, 0);
msleep(100);
val = REG_RD(bp, BRB1_REG_PORT_NUM_OCC_BLOCKS_0 + port*4);
if (val)
DP(NETIF_MSG_IFDOWN,
"BRB1 is not empty %d blocks are occupied\n", val);
}
static inline int bnx2x_reset_hw(struct bnx2x *bp, u32 load_code)
{
struct bnx2x_func_state_params func_params = {0};
__set_bit(RAMROD_COMP_WAIT, &func_params.ramrod_flags);
func_params.f_obj = &bp->func_obj;
func_params.cmd = BNX2X_F_CMD_HW_RESET;
func_params.params.hw_init.load_phase = load_code;
return bnx2x_func_state_change(bp, &func_params);
}
static inline int bnx2x_func_stop(struct bnx2x *bp)
{
struct bnx2x_func_state_params func_params = {0};
int rc;
__set_bit(RAMROD_COMP_WAIT, &func_params.ramrod_flags);
func_params.f_obj = &bp->func_obj;
func_params.cmd = BNX2X_F_CMD_STOP;
rc = bnx2x_func_state_change(bp, &func_params);
if (rc) {
#ifdef BNX2X_STOP_ON_ERROR
return rc;
#else
BNX2X_ERR("FUNC_STOP ramrod failed. Running a dry "
"transaction\n");
__set_bit(RAMROD_DRV_CLR_ONLY, &func_params.ramrod_flags);
return bnx2x_func_state_change(bp, &func_params);
#endif
}
return 0;
}
u32 bnx2x_send_unload_req(struct bnx2x *bp, int unload_mode)
{
u32 reset_code = 0;
int port = BP_PORT(bp);
if (unload_mode == UNLOAD_NORMAL)
reset_code = DRV_MSG_CODE_UNLOAD_REQ_WOL_DIS;
else if (bp->flags & NO_WOL_FLAG)
reset_code = DRV_MSG_CODE_UNLOAD_REQ_WOL_MCP;
else if (bp->wol) {
u32 emac_base = port ? GRCBASE_EMAC1 : GRCBASE_EMAC0;
u8 *mac_addr = bp->dev->dev_addr;
u32 val;
u16 pmc;
u8 entry = (BP_VN(bp) + 1)*8;
val = (mac_addr[0] << 8) | mac_addr[1];
EMAC_WR(bp, EMAC_REG_EMAC_MAC_MATCH + entry, val);
val = (mac_addr[2] << 24) | (mac_addr[3] << 16) |
(mac_addr[4] << 8) | mac_addr[5];
EMAC_WR(bp, EMAC_REG_EMAC_MAC_MATCH + entry + 4, val);
pci_read_config_word(bp->pdev, bp->pm_cap + PCI_PM_CTRL, &pmc);
pmc |= PCI_PM_CTRL_PME_ENABLE | PCI_PM_CTRL_PME_STATUS;
pci_write_config_word(bp->pdev, bp->pm_cap + PCI_PM_CTRL, pmc);
reset_code = DRV_MSG_CODE_UNLOAD_REQ_WOL_EN;
} else
reset_code = DRV_MSG_CODE_UNLOAD_REQ_WOL_DIS;
if (!BP_NOMCP(bp))
reset_code = bnx2x_fw_command(bp, reset_code, 0);
else {
int path = BP_PATH(bp);
DP(NETIF_MSG_IFDOWN, "NO MCP - load counts[%d] "
"%d, %d, %d\n",
path, load_count[path][0], load_count[path][1],
load_count[path][2]);
load_count[path][0]--;
load_count[path][1 + port]--;
DP(NETIF_MSG_IFDOWN, "NO MCP - new load counts[%d] "
"%d, %d, %d\n",
path, load_count[path][0], load_count[path][1],
load_count[path][2]);
if (load_count[path][0] == 0)
reset_code = FW_MSG_CODE_DRV_UNLOAD_COMMON;
else if (load_count[path][1 + port] == 0)
reset_code = FW_MSG_CODE_DRV_UNLOAD_PORT;
else
reset_code = FW_MSG_CODE_DRV_UNLOAD_FUNCTION;
}
return reset_code;
}
void bnx2x_send_unload_done(struct bnx2x *bp)
{
if (!BP_NOMCP(bp))
bnx2x_fw_command(bp, DRV_MSG_CODE_UNLOAD_DONE, 0);
}
static inline int bnx2x_func_wait_started(struct bnx2x *bp)
{
int tout = 50;
int msix = (bp->flags & USING_MSIX_FLAG) ? 1 : 0;
if (!bp->port.pmf)
return 0;
if (msix)
synchronize_irq(bp->msix_table[0].vector);
else
synchronize_irq(bp->pdev->irq);
flush_workqueue(bnx2x_wq);
while (bnx2x_func_get_state(bp, &bp->func_obj) !=
BNX2X_F_STATE_STARTED && tout--)
msleep(20);
if (bnx2x_func_get_state(bp, &bp->func_obj) !=
BNX2X_F_STATE_STARTED) {
#ifdef BNX2X_STOP_ON_ERROR
return -EBUSY;
#else
struct bnx2x_func_state_params func_params = {0};
DP(BNX2X_MSG_SP, "Hmmm... unexpected function state! "
"Forcing STARTED-->TX_ST0PPED-->STARTED\n");
func_params.f_obj = &bp->func_obj;
__set_bit(RAMROD_DRV_CLR_ONLY,
&func_params.ramrod_flags);
func_params.cmd = BNX2X_F_CMD_TX_STOP;
bnx2x_func_state_change(bp, &func_params);
func_params.cmd = BNX2X_F_CMD_TX_START;
return bnx2x_func_state_change(bp, &func_params);
#endif
}
return 0;
}
void bnx2x_chip_cleanup(struct bnx2x *bp, int unload_mode)
{
int port = BP_PORT(bp);
int i, rc = 0;
u8 cos;
struct bnx2x_mcast_ramrod_params rparam = {0};
u32 reset_code;
for_each_tx_queue(bp, i) {
struct bnx2x_fastpath *fp = &bp->fp[i];
for_each_cos_in_tx_queue(fp, cos)
rc = bnx2x_clean_tx_queue(bp, &fp->txdata[cos]);
#ifdef BNX2X_STOP_ON_ERROR
if (rc)
return;
#endif
}
usleep_range(1000, 1000);
rc = bnx2x_del_all_macs(bp, &bp->fp[0].mac_obj, BNX2X_ETH_MAC, false);
if (rc < 0)
BNX2X_ERR("Failed to delete all ETH macs: %d\n", rc);
rc = bnx2x_del_all_macs(bp, &bp->fp[0].mac_obj, BNX2X_UC_LIST_MAC,
true);
if (rc < 0)
BNX2X_ERR("Failed to schedule DEL commands for UC MACs list: "
"%d\n", rc);
if (!CHIP_IS_E1(bp))
REG_WR(bp, NIG_REG_LLH0_FUNC_EN + port*8, 0);
netif_addr_lock_bh(bp->dev);
if (test_bit(BNX2X_FILTER_RX_MODE_PENDING, &bp->sp_state))
set_bit(BNX2X_FILTER_RX_MODE_SCHED, &bp->sp_state);
else
bnx2x_set_storm_rx_mode(bp);
rparam.mcast_obj = &bp->mcast_obj;
rc = bnx2x_config_mcast(bp, &rparam, BNX2X_MCAST_CMD_DEL);
if (rc < 0)
BNX2X_ERR("Failed to send DEL multicast command: %d\n", rc);
netif_addr_unlock_bh(bp->dev);
reset_code = bnx2x_send_unload_req(bp, unload_mode);
rc = bnx2x_func_wait_started(bp);
if (rc) {
BNX2X_ERR("bnx2x_func_wait_started failed\n");
#ifdef BNX2X_STOP_ON_ERROR
return;
#endif
}
for_each_queue(bp, i)
if (bnx2x_stop_queue(bp, i))
#ifdef BNX2X_STOP_ON_ERROR
return;
#else
goto unload_error;
#endif
if (!bnx2x_wait_sp_comp(bp, ~0x0UL))
BNX2X_ERR("Hmmm... Common slow path ramrods got stuck!\n");
#ifndef BNX2X_STOP_ON_ERROR
unload_error:
#endif
rc = bnx2x_func_stop(bp);
if (rc) {
BNX2X_ERR("Function stop failed!\n");
#ifdef BNX2X_STOP_ON_ERROR
return;
#endif
}
bnx2x_netif_stop(bp, 1);
bnx2x_free_irq(bp);
rc = bnx2x_reset_hw(bp, reset_code);
if (rc)
BNX2X_ERR("HW_RESET failed\n");
bnx2x_send_unload_done(bp);
}
void bnx2x_disable_close_the_gate(struct bnx2x *bp)
{
u32 val;
DP(NETIF_MSG_HW, "Disabling \"close the gates\"\n");
if (CHIP_IS_E1(bp)) {
int port = BP_PORT(bp);
u32 addr = port ? MISC_REG_AEU_MASK_ATTN_FUNC_1 :
MISC_REG_AEU_MASK_ATTN_FUNC_0;
val = REG_RD(bp, addr);
val &= ~(0x300);
REG_WR(bp, addr, val);
} else {
val = REG_RD(bp, MISC_REG_AEU_GENERAL_MASK);
val &= ~(MISC_AEU_GENERAL_MASK_REG_AEU_PXP_CLOSE_MASK |
MISC_AEU_GENERAL_MASK_REG_AEU_NIG_CLOSE_MASK);
REG_WR(bp, MISC_REG_AEU_GENERAL_MASK, val);
}
}
static void bnx2x_set_234_gates(struct bnx2x *bp, bool close)
{
u32 val;
if (!CHIP_IS_E1(bp)) {
REG_WR(bp, PXP_REG_HST_DISCARD_DOORBELLS, !!close);
REG_WR(bp, PXP_REG_HST_DISCARD_INTERNAL_WRITES, !!close);
}
if (CHIP_IS_E1x(bp)) {
val = REG_RD(bp, HC_REG_CONFIG_1);
REG_WR(bp, HC_REG_CONFIG_1,
(!close) ? (val | HC_CONFIG_1_REG_BLOCK_DISABLE_1) :
(val & ~(u32)HC_CONFIG_1_REG_BLOCK_DISABLE_1));
val = REG_RD(bp, HC_REG_CONFIG_0);
REG_WR(bp, HC_REG_CONFIG_0,
(!close) ? (val | HC_CONFIG_0_REG_BLOCK_DISABLE_0) :
(val & ~(u32)HC_CONFIG_0_REG_BLOCK_DISABLE_0));
} else {
val = REG_RD(bp, IGU_REG_BLOCK_CONFIGURATION);
REG_WR(bp, IGU_REG_BLOCK_CONFIGURATION,
(!close) ?
(val | IGU_BLOCK_CONFIGURATION_REG_BLOCK_ENABLE) :
(val & ~(u32)IGU_BLOCK_CONFIGURATION_REG_BLOCK_ENABLE));
}
DP(NETIF_MSG_HW, "%s gates #2, #3 and #4\n",
close ? "closing" : "opening");
mmiowb();
}
static void bnx2x_clp_reset_prep(struct bnx2x *bp, u32 *magic_val)
{
u32 val = MF_CFG_RD(bp, shared_mf_config.clp_mb);
*magic_val = val & SHARED_MF_CLP_MAGIC;
MF_CFG_WR(bp, shared_mf_config.clp_mb, val | SHARED_MF_CLP_MAGIC);
}
static void bnx2x_clp_reset_done(struct bnx2x *bp, u32 magic_val)
{
u32 val = MF_CFG_RD(bp, shared_mf_config.clp_mb);
MF_CFG_WR(bp, shared_mf_config.clp_mb,
(val & (~SHARED_MF_CLP_MAGIC)) | magic_val);
}
static void bnx2x_reset_mcp_prep(struct bnx2x *bp, u32 *magic_val)
{
u32 shmem;
u32 validity_offset;
DP(NETIF_MSG_HW, "Starting\n");
if (!CHIP_IS_E1(bp))
bnx2x_clp_reset_prep(bp, magic_val);
shmem = REG_RD(bp, MISC_REG_SHARED_MEM_ADDR);
validity_offset = offsetof(struct shmem_region, validity_map[0]);
if (shmem > 0)
REG_WR(bp, shmem + validity_offset, 0);
}
static inline void bnx2x_mcp_wait_one(struct bnx2x *bp)
{
if (CHIP_REV_IS_SLOW(bp))
msleep(MCP_ONE_TIMEOUT*10);
else
msleep(MCP_ONE_TIMEOUT);
}
static int bnx2x_init_shmem(struct bnx2x *bp)
{
int cnt = 0;
u32 val = 0;
do {
bp->common.shmem_base = REG_RD(bp, MISC_REG_SHARED_MEM_ADDR);
if (bp->common.shmem_base) {
val = SHMEM_RD(bp, validity_map[BP_PORT(bp)]);
if (val & SHR_MEM_VALIDITY_MB)
return 0;
}
bnx2x_mcp_wait_one(bp);
} while (cnt++ < (MCP_TIMEOUT / MCP_ONE_TIMEOUT));
BNX2X_ERR("BAD MCP validity signature\n");
return -ENODEV;
}
static int bnx2x_reset_mcp_comp(struct bnx2x *bp, u32 magic_val)
{
int rc = bnx2x_init_shmem(bp);
if (!CHIP_IS_E1(bp))
bnx2x_clp_reset_done(bp, magic_val);
return rc;
}
static void bnx2x_pxp_prep(struct bnx2x *bp)
{
if (!CHIP_IS_E1(bp)) {
REG_WR(bp, PXP2_REG_RD_START_INIT, 0);
REG_WR(bp, PXP2_REG_RQ_RBC_DONE, 0);
mmiowb();
}
}
static void bnx2x_process_kill_chip_reset(struct bnx2x *bp, bool global)
{
u32 not_reset_mask1, reset_mask1, not_reset_mask2, reset_mask2;
u32 global_bits2, stay_reset2;
global_bits2 =
MISC_REGISTERS_RESET_REG_2_RST_MCP_N_RESET_CMN_CPU |
MISC_REGISTERS_RESET_REG_2_RST_MCP_N_RESET_CMN_CORE;
not_reset_mask1 =
MISC_REGISTERS_RESET_REG_1_RST_HC |
MISC_REGISTERS_RESET_REG_1_RST_PXPV |
MISC_REGISTERS_RESET_REG_1_RST_PXP;
not_reset_mask2 =
MISC_REGISTERS_RESET_REG_2_RST_PCI_MDIO |
MISC_REGISTERS_RESET_REG_2_RST_EMAC0_HARD_CORE |
MISC_REGISTERS_RESET_REG_2_RST_EMAC1_HARD_CORE |
MISC_REGISTERS_RESET_REG_2_RST_MISC_CORE |
MISC_REGISTERS_RESET_REG_2_RST_RBCN |
MISC_REGISTERS_RESET_REG_2_RST_GRC |
MISC_REGISTERS_RESET_REG_2_RST_MCP_N_RESET_REG_HARD_CORE |
MISC_REGISTERS_RESET_REG_2_RST_MCP_N_HARD_CORE_RST_B |
MISC_REGISTERS_RESET_REG_2_RST_ATC |
MISC_REGISTERS_RESET_REG_2_PGLC;
stay_reset2 =
MISC_REGISTERS_RESET_REG_2_RST_BMAC0 |
MISC_REGISTERS_RESET_REG_2_RST_BMAC1 |
MISC_REGISTERS_RESET_REG_2_RST_EMAC0 |
MISC_REGISTERS_RESET_REG_2_RST_EMAC1 |
MISC_REGISTERS_RESET_REG_2_UMAC0 |
MISC_REGISTERS_RESET_REG_2_UMAC1 |
MISC_REGISTERS_RESET_REG_2_XMAC |
MISC_REGISTERS_RESET_REG_2_XMAC_SOFT;
reset_mask1 = 0xffffffff;
if (CHIP_IS_E1(bp))
reset_mask2 = 0xffff;
else if (CHIP_IS_E1H(bp))
reset_mask2 = 0x1ffff;
else if (CHIP_IS_E2(bp))
reset_mask2 = 0xfffff;
else
reset_mask2 = 0x3ffffff;
if (!global)
reset_mask2 &= ~global_bits2;
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_CLEAR,
reset_mask2 & (~not_reset_mask2));
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_CLEAR,
reset_mask1 & (~not_reset_mask1));
barrier();
mmiowb();
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_SET,
reset_mask2 & (~stay_reset2));
barrier();
mmiowb();
REG_WR(bp, GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_SET, reset_mask1);
mmiowb();
}
static int bnx2x_er_poll_igu_vq(struct bnx2x *bp)
{
u32 cnt = 1000;
u32 pend_bits = 0;
do {
pend_bits = REG_RD(bp, IGU_REG_PENDING_BITS_STATUS);
if (pend_bits == 0)
break;
usleep_range(1000, 1000);
} while (cnt-- > 0);
if (cnt <= 0) {
BNX2X_ERR("Still pending IGU requests pend_bits=%x!\n",
pend_bits);
return -EBUSY;
}
return 0;
}
static int bnx2x_process_kill(struct bnx2x *bp, bool global)
{
int cnt = 1000;
u32 val = 0;
u32 sr_cnt, blk_cnt, port_is_idle_0, port_is_idle_1, pgl_exp_rom2;
do {
sr_cnt = REG_RD(bp, PXP2_REG_RD_SR_CNT);
blk_cnt = REG_RD(bp, PXP2_REG_RD_BLK_CNT);
port_is_idle_0 = REG_RD(bp, PXP2_REG_RD_PORT_IS_IDLE_0);
port_is_idle_1 = REG_RD(bp, PXP2_REG_RD_PORT_IS_IDLE_1);
pgl_exp_rom2 = REG_RD(bp, PXP2_REG_PGL_EXP_ROM2);
if ((sr_cnt == 0x7e) && (blk_cnt == 0xa0) &&
((port_is_idle_0 & 0x1) == 0x1) &&
((port_is_idle_1 & 0x1) == 0x1) &&
(pgl_exp_rom2 == 0xffffffff))
break;
usleep_range(1000, 1000);
} while (cnt-- > 0);
if (cnt <= 0) {
DP(NETIF_MSG_HW, "Tetris buffer didn't get empty or there"
" are still"
" outstanding read requests after 1s!\n");
DP(NETIF_MSG_HW, "sr_cnt=0x%08x, blk_cnt=0x%08x,"
" port_is_idle_0=0x%08x,"
" port_is_idle_1=0x%08x, pgl_exp_rom2=0x%08x\n",
sr_cnt, blk_cnt, port_is_idle_0, port_is_idle_1,
pgl_exp_rom2);
return -EAGAIN;
}
barrier();
bnx2x_set_234_gates(bp, true);
if (!CHIP_IS_E1x(bp) && bnx2x_er_poll_igu_vq(bp))
return -EAGAIN;
REG_WR(bp, MISC_REG_UNPREPARED, 0);
barrier();
mmiowb();
usleep_range(1000, 1000);
if (global)
bnx2x_reset_mcp_prep(bp, &val);
bnx2x_pxp_prep(bp);
barrier();
bnx2x_process_kill_chip_reset(bp, global);
barrier();
if (global && bnx2x_reset_mcp_comp(bp, val))
return -EAGAIN;
bnx2x_pxp_prep(bp);
bnx2x_set_234_gates(bp, false);
return 0;
}
int bnx2x_leader_reset(struct bnx2x *bp)
{
int rc = 0;
bool global = bnx2x_reset_is_global(bp);
if (bnx2x_process_kill(bp, global)) {
netdev_err(bp->dev, "Something bad had happen on engine %d! "
"Aii!\n", BP_PATH(bp));
rc = -EAGAIN;
goto exit_leader_reset;
}
bnx2x_set_reset_done(bp);
if (global)
bnx2x_clear_reset_global(bp);
exit_leader_reset:
bp->is_leader = 0;
bnx2x_release_leader_lock(bp);
smp_mb();
return rc;
}
static inline void bnx2x_recovery_failed(struct bnx2x *bp)
{
netdev_err(bp->dev, "Recovery has failed. Power cycle is needed.\n");
netif_device_detach(bp->dev);
bnx2x_set_reset_in_progress(bp);
bnx2x_set_power_state(bp, PCI_D3hot);
bp->recovery_state = BNX2X_RECOVERY_FAILED;
smp_mb();
}
static void bnx2x_parity_recover(struct bnx2x *bp)
{
bool global = false;
DP(NETIF_MSG_HW, "Handling parity\n");
while (1) {
switch (bp->recovery_state) {
case BNX2X_RECOVERY_INIT:
DP(NETIF_MSG_HW, "State is BNX2X_RECOVERY_INIT\n");
bnx2x_chk_parity_attn(bp, &global, false);
if (bnx2x_trylock_leader_lock(bp)) {
bnx2x_set_reset_in_progress(bp);
if (global)
bnx2x_set_reset_global(bp);
bp->is_leader = 1;
}
if (bnx2x_nic_unload(bp, UNLOAD_RECOVERY))
return;
bp->recovery_state = BNX2X_RECOVERY_WAIT;
if (global) {
bp->fw_seq = 0;
bp->fw_drv_pulse_wr_seq = 0;
}
smp_mb();
break;
case BNX2X_RECOVERY_WAIT:
DP(NETIF_MSG_HW, "State is BNX2X_RECOVERY_WAIT\n");
if (bp->is_leader) {
int other_engine = BP_PATH(bp) ? 0 : 1;
u32 other_load_counter =
bnx2x_get_load_cnt(bp, other_engine);
u32 load_counter =
bnx2x_get_load_cnt(bp, BP_PATH(bp));
global = bnx2x_reset_is_global(bp);
if (load_counter ||
(global && other_load_counter)) {
schedule_delayed_work(&bp->sp_rtnl_task,
HZ/10);
return;
} else {
if (bnx2x_leader_reset(bp)) {
bnx2x_recovery_failed(bp);
return;
}
break;
}
} else {
if (!bnx2x_reset_is_done(bp, BP_PATH(bp))) {
if (bnx2x_trylock_leader_lock(bp)) {
bp->is_leader = 1;
break;
}
schedule_delayed_work(&bp->sp_rtnl_task,
HZ/10);
return;
} else {
if (bnx2x_reset_is_global(bp)) {
schedule_delayed_work(
&bp->sp_rtnl_task,
HZ/10);
return;
}
if (bnx2x_nic_load(bp, LOAD_NORMAL))
bnx2x_recovery_failed(bp);
else {
bp->recovery_state =
BNX2X_RECOVERY_DONE;
smp_mb();
}
return;
}
}
default:
return;
}
}
}
static void bnx2x_sp_rtnl_task(struct work_struct *work)
{
struct bnx2x *bp = container_of(work, struct bnx2x, sp_rtnl_task.work);
rtnl_lock();
if (!netif_running(bp->dev))
goto sp_rtnl_exit;
#ifdef BNX2X_STOP_ON_ERROR
BNX2X_ERR("recovery flow called but STOP_ON_ERROR defined "
"so reset not done to allow debug dump,\n"
"you will need to reboot when done\n");
goto sp_rtnl_not_reset;
#endif
if (unlikely(bp->recovery_state != BNX2X_RECOVERY_DONE)) {
bp->sp_rtnl_state = 0;
smp_mb();
bnx2x_parity_recover(bp);
goto sp_rtnl_exit;
}
if (test_and_clear_bit(BNX2X_SP_RTNL_TX_TIMEOUT, &bp->sp_rtnl_state)) {
bp->sp_rtnl_state = 0;
smp_mb();
bnx2x_nic_unload(bp, UNLOAD_NORMAL);
bnx2x_nic_load(bp, LOAD_NORMAL);
goto sp_rtnl_exit;
}
#ifdef BNX2X_STOP_ON_ERROR
sp_rtnl_not_reset:
#endif
if (test_and_clear_bit(BNX2X_SP_RTNL_SETUP_TC, &bp->sp_rtnl_state))
bnx2x_setup_tc(bp->dev, bp->dcbx_port_params.ets.num_of_cos);
sp_rtnl_exit:
rtnl_unlock();
}
static void bnx2x_period_task(struct work_struct *work)
{
struct bnx2x *bp = container_of(work, struct bnx2x, period_task.work);
if (!netif_running(bp->dev))
goto period_task_exit;
if (CHIP_REV_IS_SLOW(bp)) {
BNX2X_ERR("period task called on emulation, ignoring\n");
goto period_task_exit;
}
bnx2x_acquire_phy_lock(bp);
smp_mb();
if (bp->port.pmf) {
bnx2x_period_func(&bp->link_params, &bp->link_vars);
queue_delayed_work(bnx2x_wq, &bp->period_task, 1*HZ);
}
bnx2x_release_phy_lock(bp);
period_task_exit:
return;
}
static u32 bnx2x_get_pretend_reg(struct bnx2x *bp)
{
u32 base = PXP2_REG_PGL_PRETEND_FUNC_F0;
u32 stride = PXP2_REG_PGL_PRETEND_FUNC_F1 - base;
return base + (BP_ABS_FUNC(bp)) * stride;
}
static void bnx2x_undi_int_disable_e1h(struct bnx2x *bp)
{
u32 reg = bnx2x_get_pretend_reg(bp);
mmiowb();
REG_WR(bp, reg, 0);
REG_RD(bp, reg);
bnx2x_int_disable(bp);
mmiowb();
REG_WR(bp, reg, BP_ABS_FUNC(bp));
REG_RD(bp, reg);
}
static inline void bnx2x_undi_int_disable(struct bnx2x *bp)
{
if (CHIP_IS_E1(bp))
bnx2x_int_disable(bp);
else
bnx2x_undi_int_disable_e1h(bp);
}
static void __devinit bnx2x_undi_unload(struct bnx2x *bp)
{
u32 val;
val = REG_RD(bp, MISC_REG_UNPREPARED);
if (val == 0x1) {
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_RESET);
val = REG_RD(bp, DORQ_REG_NORM_CID_OFST);
if (val == 0x7) {
u32 reset_code = DRV_MSG_CODE_UNLOAD_REQ_WOL_DIS;
int orig_pf_num = bp->pf_num;
int port;
u32 swap_en, swap_val, value;
REG_WR(bp, DORQ_REG_NORM_CID_OFST, 0);
BNX2X_DEV_INFO("UNDI is active! reset device\n");
bp->pf_num = 0;
bp->fw_seq =
(SHMEM_RD(bp, func_mb[bp->pf_num].drv_mb_header) &
DRV_MSG_SEQ_NUMBER_MASK);
reset_code = bnx2x_fw_command(bp, reset_code, 0);
if (reset_code != FW_MSG_CODE_DRV_UNLOAD_COMMON) {
bnx2x_fw_command(bp,
DRV_MSG_CODE_UNLOAD_DONE, 0);
bp->pf_num = 1;
bp->fw_seq =
(SHMEM_RD(bp, func_mb[bp->pf_num].drv_mb_header) &
DRV_MSG_SEQ_NUMBER_MASK);
reset_code = DRV_MSG_CODE_UNLOAD_REQ_WOL_DIS;
bnx2x_fw_command(bp, reset_code, 0);
}
bnx2x_undi_int_disable(bp);
port = BP_PORT(bp);
REG_WR(bp, (port ? NIG_REG_LLH1_BRB1_DRV_MASK :
NIG_REG_LLH0_BRB1_DRV_MASK), 0x0);
REG_WR(bp, (port ? NIG_REG_LLH1_BRB1_NOT_MCP :
NIG_REG_LLH0_BRB1_NOT_MCP), 0x0);
REG_WR(bp, (port ? MISC_REG_AEU_MASK_ATTN_FUNC_1 :
MISC_REG_AEU_MASK_ATTN_FUNC_0), 0);
msleep(10);
swap_val = REG_RD(bp, NIG_REG_PORT_SWAP);
swap_en = REG_RD(bp, NIG_REG_STRAP_OVERRIDE);
REG_WR(bp,
GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_CLEAR,
0xd3ffffff);
value = 0x1400;
if (CHIP_IS_E3(bp)) {
value |= MISC_REGISTERS_RESET_REG_2_MSTAT0;
value |= MISC_REGISTERS_RESET_REG_2_MSTAT1;
}
REG_WR(bp,
GRCBASE_MISC + MISC_REGISTERS_RESET_REG_2_CLEAR,
value);
REG_WR(bp,
GRCBASE_MISC + MISC_REGISTERS_RESET_REG_1_SET,
MISC_REGISTERS_RESET_REG_1_RST_NIG);
REG_WR(bp, NIG_REG_PORT_SWAP, swap_val);
REG_WR(bp, NIG_REG_STRAP_OVERRIDE, swap_en);
bnx2x_fw_command(bp, DRV_MSG_CODE_UNLOAD_DONE, 0);
bp->pf_num = orig_pf_num;
bp->fw_seq =
(SHMEM_RD(bp, func_mb[bp->pf_num].drv_mb_header) &
DRV_MSG_SEQ_NUMBER_MASK);
}
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_RESET);
}
}
static void __devinit bnx2x_get_common_hwinfo(struct bnx2x *bp)
{
u32 val, val2, val3, val4, id;
u16 pmc;
val = REG_RD(bp, MISC_REG_CHIP_NUM);
id = ((val & 0xffff) << 16);
val = REG_RD(bp, MISC_REG_CHIP_REV);
id |= ((val & 0xf) << 12);
val = REG_RD(bp, MISC_REG_CHIP_METAL);
id |= ((val & 0xff) << 4);
val = REG_RD(bp, MISC_REG_BOND_ID);
id |= (val & 0xf);
bp->common.chip_id = id;
bp->db_size = (1 << BNX2X_DB_SHIFT);
if (!CHIP_IS_E1x(bp)) {
val = REG_RD(bp, MISC_REG_PORT4MODE_EN_OVWR);
if ((val & 1) == 0)
val = REG_RD(bp, MISC_REG_PORT4MODE_EN);
else
val = (val >> 1) & 1;
BNX2X_DEV_INFO("chip is in %s\n", val ? "4_PORT_MODE" :
"2_PORT_MODE");
bp->common.chip_port_mode = val ? CHIP_4_PORT_MODE :
CHIP_2_PORT_MODE;
if (CHIP_MODE_IS_4_PORT(bp))
bp->pfid = (bp->pf_num >> 1);
else
bp->pfid = (bp->pf_num & 0x6);
} else {
bp->common.chip_port_mode = CHIP_PORT_MODE_NONE;
bp->pfid = bp->pf_num;
}
bp->link_params.chip_id = bp->common.chip_id;
BNX2X_DEV_INFO("chip ID is 0x%x\n", id);
val = (REG_RD(bp, 0x2874) & 0x55);
if ((bp->common.chip_id & 0x1) ||
(CHIP_IS_E1(bp) && val) || (CHIP_IS_E1H(bp) && (val == 0x55))) {
bp->flags |= ONE_PORT_FLAG;
BNX2X_DEV_INFO("single port device\n");
}
val = REG_RD(bp, MCP_REG_MCPR_NVM_CFG4);
bp->common.flash_size = (BNX2X_NVRAM_1MB_SIZE <<
(val & MCPR_NVM_CFG4_FLASH_SIZE));
BNX2X_DEV_INFO("flash_size 0x%x (%d)\n",
bp->common.flash_size, bp->common.flash_size);
bnx2x_init_shmem(bp);
bp->common.shmem2_base = REG_RD(bp, (BP_PATH(bp) ?
MISC_REG_GENERIC_CR_1 :
MISC_REG_GENERIC_CR_0));
bp->link_params.shmem_base = bp->common.shmem_base;
bp->link_params.shmem2_base = bp->common.shmem2_base;
BNX2X_DEV_INFO("shmem offset 0x%x shmem2 offset 0x%x\n",
bp->common.shmem_base, bp->common.shmem2_base);
if (!bp->common.shmem_base) {
BNX2X_DEV_INFO("MCP not active\n");
bp->flags |= NO_MCP_FLAG;
return;
}
bp->common.hw_config = SHMEM_RD(bp, dev_info.shared_hw_config.config);
BNX2X_DEV_INFO("hw_config 0x%08x\n", bp->common.hw_config);
bp->link_params.hw_led_mode = ((bp->common.hw_config &
SHARED_HW_CFG_LED_MODE_MASK) >>
SHARED_HW_CFG_LED_MODE_SHIFT);
bp->link_params.feature_config_flags = 0;
val = SHMEM_RD(bp, dev_info.shared_feature_config.config);
if (val & SHARED_FEAT_CFG_OVERRIDE_PREEMPHASIS_CFG_ENABLED)
bp->link_params.feature_config_flags |=
FEATURE_CONFIG_OVERRIDE_PREEMPHASIS_ENABLED;
else
bp->link_params.feature_config_flags &=
~FEATURE_CONFIG_OVERRIDE_PREEMPHASIS_ENABLED;
val = SHMEM_RD(bp, dev_info.bc_rev) >> 8;
bp->common.bc_ver = val;
BNX2X_DEV_INFO("bc_ver %X\n", val);
if (val < BNX2X_BC_VER) {
BNX2X_ERR("This driver needs bc_ver %X but found %X, "
"please upgrade BC\n", BNX2X_BC_VER, val);
}
bp->link_params.feature_config_flags |=
(val >= REQ_BC_VER_4_VRFY_FIRST_PHY_OPT_MDL) ?
FEATURE_CONFIG_BC_SUPPORTS_OPT_MDL_VRFY : 0;
bp->link_params.feature_config_flags |=
(val >= REQ_BC_VER_4_VRFY_SPECIFIC_PHY_OPT_MDL) ?
FEATURE_CONFIG_BC_SUPPORTS_DUAL_PHY_OPT_MDL_VRFY : 0;
bp->link_params.feature_config_flags |=
(val >= REQ_BC_VER_4_SFP_TX_DISABLE_SUPPORTED) ?
FEATURE_CONFIG_BC_SUPPORTS_SFP_TX_DISABLED : 0;
pci_read_config_word(bp->pdev, bp->pm_cap + PCI_PM_PMC, &pmc);
bp->flags |= (pmc & PCI_PM_CAP_PME_D3cold) ? 0 : NO_WOL_FLAG;
BNX2X_DEV_INFO("%sWoL capable\n",
(bp->flags & NO_WOL_FLAG) ? "not " : "");
val = SHMEM_RD(bp, dev_info.shared_hw_config.part_num);
val2 = SHMEM_RD(bp, dev_info.shared_hw_config.part_num[4]);
val3 = SHMEM_RD(bp, dev_info.shared_hw_config.part_num[8]);
val4 = SHMEM_RD(bp, dev_info.shared_hw_config.part_num[12]);
dev_info(&bp->pdev->dev, "part number %X-%X-%X-%X\n",
val, val2, val3, val4);
}
static void __devinit bnx2x_get_igu_cam_info(struct bnx2x *bp)
{
int pfid = BP_FUNC(bp);
int igu_sb_id;
u32 val;
u8 fid, igu_sb_cnt = 0;
bp->igu_base_sb = 0xff;
if (CHIP_INT_MODE_IS_BC(bp)) {
int vn = BP_VN(bp);
igu_sb_cnt = bp->igu_sb_cnt;
bp->igu_base_sb = (CHIP_MODE_IS_4_PORT(bp) ? pfid : vn) *
FP_SB_MAX_E1x;
bp->igu_dsb_id = E1HVN_MAX * FP_SB_MAX_E1x +
(CHIP_MODE_IS_4_PORT(bp) ? pfid : vn);
return;
}
for (igu_sb_id = 0; igu_sb_id < IGU_REG_MAPPING_MEMORY_SIZE;
igu_sb_id++) {
val = REG_RD(bp, IGU_REG_MAPPING_MEMORY + igu_sb_id * 4);
if (!(val & IGU_REG_MAPPING_MEMORY_VALID))
continue;
fid = IGU_FID(val);
if ((fid & IGU_FID_ENCODE_IS_PF)) {
if ((fid & IGU_FID_PF_NUM_MASK) != pfid)
continue;
if (IGU_VEC(val) == 0)
bp->igu_dsb_id = igu_sb_id;
else {
if (bp->igu_base_sb == 0xff)
bp->igu_base_sb = igu_sb_id;
igu_sb_cnt++;
}
}
}
#ifdef CONFIG_PCI_MSI
WARN_ON(bp->igu_sb_cnt != igu_sb_cnt);
#endif
if (igu_sb_cnt == 0)
BNX2X_ERR("CAM configuration error\n");
}
static void __devinit bnx2x_link_settings_supported(struct bnx2x *bp,
u32 switch_cfg)
{
int cfg_size = 0, idx, port = BP_PORT(bp);
bp->port.supported[0] = 0;
bp->port.supported[1] = 0;
switch (bp->link_params.num_phys) {
case 1:
bp->port.supported[0] = bp->link_params.phy[INT_PHY].supported;
cfg_size = 1;
break;
case 2:
bp->port.supported[0] = bp->link_params.phy[EXT_PHY1].supported;
cfg_size = 1;
break;
case 3:
if (bp->link_params.multi_phy_config &
PORT_HW_CFG_PHY_SWAPPED_ENABLED) {
bp->port.supported[1] =
bp->link_params.phy[EXT_PHY1].supported;
bp->port.supported[0] =
bp->link_params.phy[EXT_PHY2].supported;
} else {
bp->port.supported[0] =
bp->link_params.phy[EXT_PHY1].supported;
bp->port.supported[1] =
bp->link_params.phy[EXT_PHY2].supported;
}
cfg_size = 2;
break;
}
if (!(bp->port.supported[0] || bp->port.supported[1])) {
BNX2X_ERR("NVRAM config error. BAD phy config."
"PHY1 config 0x%x, PHY2 config 0x%x\n",
SHMEM_RD(bp,
dev_info.port_hw_config[port].external_phy_config),
SHMEM_RD(bp,
dev_info.port_hw_config[port].external_phy_config2));
return;
}
if (CHIP_IS_E3(bp))
bp->port.phy_addr = REG_RD(bp, MISC_REG_WC0_CTRL_PHY_ADDR);
else {
switch (switch_cfg) {
case SWITCH_CFG_1G:
bp->port.phy_addr = REG_RD(
bp, NIG_REG_SERDES0_CTRL_PHY_ADDR + port*0x10);
break;
case SWITCH_CFG_10G:
bp->port.phy_addr = REG_RD(
bp, NIG_REG_XGXS0_CTRL_PHY_ADDR + port*0x18);
break;
default:
BNX2X_ERR("BAD switch_cfg link_config 0x%x\n",
bp->port.link_config[0]);
return;
}
}
BNX2X_DEV_INFO("phy_addr 0x%x\n", bp->port.phy_addr);
for (idx = 0; idx < cfg_size; idx++) {
if (!(bp->link_params.speed_cap_mask[idx] &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10M_HALF))
bp->port.supported[idx] &= ~SUPPORTED_10baseT_Half;
if (!(bp->link_params.speed_cap_mask[idx] &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10M_FULL))
bp->port.supported[idx] &= ~SUPPORTED_10baseT_Full;
if (!(bp->link_params.speed_cap_mask[idx] &
PORT_HW_CFG_SPEED_CAPABILITY_D0_100M_HALF))
bp->port.supported[idx] &= ~SUPPORTED_100baseT_Half;
if (!(bp->link_params.speed_cap_mask[idx] &
PORT_HW_CFG_SPEED_CAPABILITY_D0_100M_FULL))
bp->port.supported[idx] &= ~SUPPORTED_100baseT_Full;
if (!(bp->link_params.speed_cap_mask[idx] &
PORT_HW_CFG_SPEED_CAPABILITY_D0_1G))
bp->port.supported[idx] &= ~(SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full);
if (!(bp->link_params.speed_cap_mask[idx] &
PORT_HW_CFG_SPEED_CAPABILITY_D0_2_5G))
bp->port.supported[idx] &= ~SUPPORTED_2500baseX_Full;
if (!(bp->link_params.speed_cap_mask[idx] &
PORT_HW_CFG_SPEED_CAPABILITY_D0_10G))
bp->port.supported[idx] &= ~SUPPORTED_10000baseT_Full;
}
BNX2X_DEV_INFO("supported 0x%x 0x%x\n", bp->port.supported[0],
bp->port.supported[1]);
}
static void __devinit bnx2x_link_settings_requested(struct bnx2x *bp)
{
u32 link_config, idx, cfg_size = 0;
bp->port.advertising[0] = 0;
bp->port.advertising[1] = 0;
switch (bp->link_params.num_phys) {
case 1:
case 2:
cfg_size = 1;
break;
case 3:
cfg_size = 2;
break;
}
for (idx = 0; idx < cfg_size; idx++) {
bp->link_params.req_duplex[idx] = DUPLEX_FULL;
link_config = bp->port.link_config[idx];
switch (link_config & PORT_FEATURE_LINK_SPEED_MASK) {
case PORT_FEATURE_LINK_SPEED_AUTO:
if (bp->port.supported[idx] & SUPPORTED_Autoneg) {
bp->link_params.req_line_speed[idx] =
SPEED_AUTO_NEG;
bp->port.advertising[idx] |=
bp->port.supported[idx];
} else {
bp->link_params.req_line_speed[idx] =
SPEED_10000;
bp->port.advertising[idx] |=
(ADVERTISED_10000baseT_Full |
ADVERTISED_FIBRE);
continue;
}
break;
case PORT_FEATURE_LINK_SPEED_10M_FULL:
if (bp->port.supported[idx] & SUPPORTED_10baseT_Full) {
bp->link_params.req_line_speed[idx] =
SPEED_10;
bp->port.advertising[idx] |=
(ADVERTISED_10baseT_Full |
ADVERTISED_TP);
} else {
BNX2X_ERR("NVRAM config error. "
"Invalid link_config 0x%x"
" speed_cap_mask 0x%x\n",
link_config,
bp->link_params.speed_cap_mask[idx]);
return;
}
break;
case PORT_FEATURE_LINK_SPEED_10M_HALF:
if (bp->port.supported[idx] & SUPPORTED_10baseT_Half) {
bp->link_params.req_line_speed[idx] =
SPEED_10;
bp->link_params.req_duplex[idx] =
DUPLEX_HALF;
bp->port.advertising[idx] |=
(ADVERTISED_10baseT_Half |
ADVERTISED_TP);
} else {
BNX2X_ERR("NVRAM config error. "
"Invalid link_config 0x%x"
" speed_cap_mask 0x%x\n",
link_config,
bp->link_params.speed_cap_mask[idx]);
return;
}
break;
case PORT_FEATURE_LINK_SPEED_100M_FULL:
if (bp->port.supported[idx] &
SUPPORTED_100baseT_Full) {
bp->link_params.req_line_speed[idx] =
SPEED_100;
bp->port.advertising[idx] |=
(ADVERTISED_100baseT_Full |
ADVERTISED_TP);
} else {
BNX2X_ERR("NVRAM config error. "
"Invalid link_config 0x%x"
" speed_cap_mask 0x%x\n",
link_config,
bp->link_params.speed_cap_mask[idx]);
return;
}
break;
case PORT_FEATURE_LINK_SPEED_100M_HALF:
if (bp->port.supported[idx] &
SUPPORTED_100baseT_Half) {
bp->link_params.req_line_speed[idx] =
SPEED_100;
bp->link_params.req_duplex[idx] =
DUPLEX_HALF;
bp->port.advertising[idx] |=
(ADVERTISED_100baseT_Half |
ADVERTISED_TP);
} else {
BNX2X_ERR("NVRAM config error. "
"Invalid link_config 0x%x"
" speed_cap_mask 0x%x\n",
link_config,
bp->link_params.speed_cap_mask[idx]);
return;
}
break;
case PORT_FEATURE_LINK_SPEED_1G:
if (bp->port.supported[idx] &
SUPPORTED_1000baseT_Full) {
bp->link_params.req_line_speed[idx] =
SPEED_1000;
bp->port.advertising[idx] |=
(ADVERTISED_1000baseT_Full |
ADVERTISED_TP);
} else {
BNX2X_ERR("NVRAM config error. "
"Invalid link_config 0x%x"
" speed_cap_mask 0x%x\n",
link_config,
bp->link_params.speed_cap_mask[idx]);
return;
}
break;
case PORT_FEATURE_LINK_SPEED_2_5G:
if (bp->port.supported[idx] &
SUPPORTED_2500baseX_Full) {
bp->link_params.req_line_speed[idx] =
SPEED_2500;
bp->port.advertising[idx] |=
(ADVERTISED_2500baseX_Full |
ADVERTISED_TP);
} else {
BNX2X_ERR("NVRAM config error. "
"Invalid link_config 0x%x"
" speed_cap_mask 0x%x\n",
link_config,
bp->link_params.speed_cap_mask[idx]);
return;
}
break;
case PORT_FEATURE_LINK_SPEED_10G_CX4:
if (bp->port.supported[idx] &
SUPPORTED_10000baseT_Full) {
bp->link_params.req_line_speed[idx] =
SPEED_10000;
bp->port.advertising[idx] |=
(ADVERTISED_10000baseT_Full |
ADVERTISED_FIBRE);
} else {
BNX2X_ERR("NVRAM config error. "
"Invalid link_config 0x%x"
" speed_cap_mask 0x%x\n",
link_config,
bp->link_params.speed_cap_mask[idx]);
return;
}
break;
case PORT_FEATURE_LINK_SPEED_20G:
bp->link_params.req_line_speed[idx] = SPEED_20000;
break;
default:
BNX2X_ERR("NVRAM config error. "
"BAD link speed link_config 0x%x\n",
link_config);
bp->link_params.req_line_speed[idx] =
SPEED_AUTO_NEG;
bp->port.advertising[idx] =
bp->port.supported[idx];
break;
}
bp->link_params.req_flow_ctrl[idx] = (link_config &
PORT_FEATURE_FLOW_CONTROL_MASK);
if ((bp->link_params.req_flow_ctrl[idx] ==
BNX2X_FLOW_CTRL_AUTO) &&
!(bp->port.supported[idx] & SUPPORTED_Autoneg)) {
bp->link_params.req_flow_ctrl[idx] =
BNX2X_FLOW_CTRL_NONE;
}
BNX2X_DEV_INFO("req_line_speed %d req_duplex %d req_flow_ctrl"
" 0x%x advertising 0x%x\n",
bp->link_params.req_line_speed[idx],
bp->link_params.req_duplex[idx],
bp->link_params.req_flow_ctrl[idx],
bp->port.advertising[idx]);
}
}
static void __devinit bnx2x_set_mac_buf(u8 *mac_buf, u32 mac_lo, u16 mac_hi)
{
mac_hi = cpu_to_be16(mac_hi);
mac_lo = cpu_to_be32(mac_lo);
memcpy(mac_buf, &mac_hi, sizeof(mac_hi));
memcpy(mac_buf + sizeof(mac_hi), &mac_lo, sizeof(mac_lo));
}
static void __devinit bnx2x_get_port_hwinfo(struct bnx2x *bp)
{
int port = BP_PORT(bp);
u32 config;
u32 ext_phy_type, ext_phy_config;
bp->link_params.bp = bp;
bp->link_params.port = port;
bp->link_params.lane_config =
SHMEM_RD(bp, dev_info.port_hw_config[port].lane_config);
bp->link_params.speed_cap_mask[0] =
SHMEM_RD(bp,
dev_info.port_hw_config[port].speed_capability_mask);
bp->link_params.speed_cap_mask[1] =
SHMEM_RD(bp,
dev_info.port_hw_config[port].speed_capability_mask2);
bp->port.link_config[0] =
SHMEM_RD(bp, dev_info.port_feature_config[port].link_config);
bp->port.link_config[1] =
SHMEM_RD(bp, dev_info.port_feature_config[port].link_config2);
bp->link_params.multi_phy_config =
SHMEM_RD(bp, dev_info.port_hw_config[port].multi_phy_config);
config = SHMEM_RD(bp, dev_info.port_feature_config[port].config);
bp->wol = (!(bp->flags & NO_WOL_FLAG) &&
(config & PORT_FEATURE_WOL_ENABLED));
BNX2X_DEV_INFO("lane_config 0x%08x "
"speed_cap_mask0 0x%08x link_config0 0x%08x\n",
bp->link_params.lane_config,
bp->link_params.speed_cap_mask[0],
bp->port.link_config[0]);
bp->link_params.switch_cfg = (bp->port.link_config[0] &
PORT_FEATURE_CONNECTED_SWITCH_MASK);
bnx2x_phy_probe(&bp->link_params);
bnx2x_link_settings_supported(bp, bp->link_params.switch_cfg);
bnx2x_link_settings_requested(bp);
ext_phy_config =
SHMEM_RD(bp,
dev_info.port_hw_config[port].external_phy_config);
ext_phy_type = XGXS_EXT_PHY_TYPE(ext_phy_config);
if (ext_phy_type == PORT_HW_CFG_XGXS_EXT_PHY_TYPE_DIRECT)
bp->mdio.prtad = bp->port.phy_addr;
else if ((ext_phy_type != PORT_HW_CFG_XGXS_EXT_PHY_TYPE_FAILURE) &&
(ext_phy_type != PORT_HW_CFG_XGXS_EXT_PHY_TYPE_NOT_CONN))
bp->mdio.prtad =
XGXS_EXT_PHY_ADDR(ext_phy_config);
if (IS_MF(bp))
bp->port.need_hw_lock = 1;
else
bp->port.need_hw_lock = bnx2x_hw_lock_required(bp,
bp->common.shmem_base,
bp->common.shmem2_base);
}
static void __devinit bnx2x_get_cnic_info(struct bnx2x *bp)
{
int port = BP_PORT(bp);
int func = BP_ABS_FUNC(bp);
u32 max_iscsi_conn = FW_ENCODE_32BIT_PATTERN ^ SHMEM_RD(bp,
drv_lic_key[port].max_iscsi_conn);
u32 max_fcoe_conn = FW_ENCODE_32BIT_PATTERN ^ SHMEM_RD(bp,
drv_lic_key[port].max_fcoe_conn);
bp->cnic_eth_dev.max_iscsi_conn =
(max_iscsi_conn & BNX2X_MAX_ISCSI_INIT_CONN_MASK) >>
BNX2X_MAX_ISCSI_INIT_CONN_SHIFT;
bp->cnic_eth_dev.max_fcoe_conn =
(max_fcoe_conn & BNX2X_MAX_FCOE_INIT_CONN_MASK) >>
BNX2X_MAX_FCOE_INIT_CONN_SHIFT;
if (!IS_MF(bp)) {
bp->cnic_eth_dev.fcoe_wwn_port_name_hi =
SHMEM_RD(bp,
dev_info.port_hw_config[port].
fcoe_wwn_port_name_upper);
bp->cnic_eth_dev.fcoe_wwn_port_name_lo =
SHMEM_RD(bp,
dev_info.port_hw_config[port].
fcoe_wwn_port_name_lower);
bp->cnic_eth_dev.fcoe_wwn_node_name_hi =
SHMEM_RD(bp,
dev_info.port_hw_config[port].
fcoe_wwn_node_name_upper);
bp->cnic_eth_dev.fcoe_wwn_node_name_lo =
SHMEM_RD(bp,
dev_info.port_hw_config[port].
fcoe_wwn_node_name_lower);
} else if (!IS_MF_SD(bp)) {
u32 cfg = MF_CFG_RD(bp, func_ext_config[func].func_cfg);
if (cfg & MACP_FUNC_CFG_FLAGS_FCOE_OFFLOAD) {
bp->cnic_eth_dev.fcoe_wwn_port_name_hi =
MF_CFG_RD(bp, func_ext_config[func].
fcoe_wwn_port_name_upper);
bp->cnic_eth_dev.fcoe_wwn_port_name_lo =
MF_CFG_RD(bp, func_ext_config[func].
fcoe_wwn_port_name_lower);
bp->cnic_eth_dev.fcoe_wwn_node_name_hi =
MF_CFG_RD(bp, func_ext_config[func].
fcoe_wwn_node_name_upper);
bp->cnic_eth_dev.fcoe_wwn_node_name_lo =
MF_CFG_RD(bp, func_ext_config[func].
fcoe_wwn_node_name_lower);
}
}
BNX2X_DEV_INFO("max_iscsi_conn 0x%x max_fcoe_conn 0x%x\n",
bp->cnic_eth_dev.max_iscsi_conn,
bp->cnic_eth_dev.max_fcoe_conn);
if (!bp->cnic_eth_dev.max_iscsi_conn)
bp->flags |= NO_ISCSI_OOO_FLAG | NO_ISCSI_FLAG;
if (!bp->cnic_eth_dev.max_fcoe_conn)
bp->flags |= NO_FCOE_FLAG;
}
static void __devinit bnx2x_get_mac_hwinfo(struct bnx2x *bp)
{
u32 val, val2;
int func = BP_ABS_FUNC(bp);
int port = BP_PORT(bp);
#ifdef BCM_CNIC
u8 *iscsi_mac = bp->cnic_eth_dev.iscsi_mac;
u8 *fip_mac = bp->fip_mac;
#endif
memset(bp->dev->dev_addr, 0, ETH_ALEN);
if (BP_NOMCP(bp)) {
BNX2X_ERROR("warning: random MAC workaround active\n");
random_ether_addr(bp->dev->dev_addr);
} else if (IS_MF(bp)) {
val2 = MF_CFG_RD(bp, func_mf_config[func].mac_upper);
val = MF_CFG_RD(bp, func_mf_config[func].mac_lower);
if ((val2 != FUNC_MF_CFG_UPPERMAC_DEFAULT) &&
(val != FUNC_MF_CFG_LOWERMAC_DEFAULT))
bnx2x_set_mac_buf(bp->dev->dev_addr, val, val2);
#ifdef BCM_CNIC
if (IS_MF_SI(bp)) {
u32 cfg = MF_CFG_RD(bp, func_ext_config[func].func_cfg);
if (cfg & MACP_FUNC_CFG_FLAGS_ISCSI_OFFLOAD) {
val2 = MF_CFG_RD(bp, func_ext_config[func].
iscsi_mac_addr_upper);
val = MF_CFG_RD(bp, func_ext_config[func].
iscsi_mac_addr_lower);
bnx2x_set_mac_buf(iscsi_mac, val, val2);
BNX2X_DEV_INFO("Read iSCSI MAC: %pM\n",
iscsi_mac);
} else
bp->flags |= NO_ISCSI_OOO_FLAG | NO_ISCSI_FLAG;
if (cfg & MACP_FUNC_CFG_FLAGS_FCOE_OFFLOAD) {
val2 = MF_CFG_RD(bp, func_ext_config[func].
fcoe_mac_addr_upper);
val = MF_CFG_RD(bp, func_ext_config[func].
fcoe_mac_addr_lower);
bnx2x_set_mac_buf(fip_mac, val, val2);
BNX2X_DEV_INFO("Read FCoE L2 MAC to %pM\n",
fip_mac);
} else
bp->flags |= NO_FCOE_FLAG;
}
#endif
} else {
val2 = SHMEM_RD(bp, dev_info.port_hw_config[port].mac_upper);
val = SHMEM_RD(bp, dev_info.port_hw_config[port].mac_lower);
bnx2x_set_mac_buf(bp->dev->dev_addr, val, val2);
#ifdef BCM_CNIC
val2 = SHMEM_RD(bp, dev_info.port_hw_config[port].
iscsi_mac_upper);
val = SHMEM_RD(bp, dev_info.port_hw_config[port].
iscsi_mac_lower);
bnx2x_set_mac_buf(iscsi_mac, val, val2);
val2 = SHMEM_RD(bp, dev_info.port_hw_config[port].
fcoe_fip_mac_upper);
val = SHMEM_RD(bp, dev_info.port_hw_config[port].
fcoe_fip_mac_lower);
bnx2x_set_mac_buf(fip_mac, val, val2);
#endif
}
memcpy(bp->link_params.mac_addr, bp->dev->dev_addr, ETH_ALEN);
memcpy(bp->dev->perm_addr, bp->dev->dev_addr, ETH_ALEN);
#ifdef BCM_CNIC
if (!CHIP_IS_E1x(bp) && IS_MF_SD(bp))
memcpy(fip_mac, bp->dev->dev_addr, ETH_ALEN);
if (!is_valid_ether_addr(iscsi_mac)) {
bp->flags |= NO_ISCSI_FLAG;
memset(iscsi_mac, 0, ETH_ALEN);
}
if (!is_valid_ether_addr(fip_mac)) {
bp->flags |= NO_FCOE_FLAG;
memset(bp->fip_mac, 0, ETH_ALEN);
}
#endif
if (!is_valid_ether_addr(bp->dev->dev_addr))
dev_err(&bp->pdev->dev,
"bad Ethernet MAC address configuration: "
"%pM, change it manually before bringing up "
"the appropriate network interface\n",
bp->dev->dev_addr);
}
static int __devinit bnx2x_get_hwinfo(struct bnx2x *bp)
{
int func = BP_ABS_FUNC(bp);
int vn;
u32 val = 0;
int rc = 0;
bnx2x_get_common_hwinfo(bp);
if (CHIP_IS_E1x(bp)) {
bp->common.int_block = INT_BLOCK_HC;
bp->igu_dsb_id = DEF_SB_IGU_ID;
bp->igu_base_sb = 0;
} else {
bp->common.int_block = INT_BLOCK_IGU;
bnx2x_acquire_hw_lock(bp, HW_LOCK_RESOURCE_RESET);
val = REG_RD(bp, IGU_REG_BLOCK_CONFIGURATION);
if (val & IGU_BLOCK_CONFIGURATION_REG_BACKWARD_COMP_EN) {
int tout = 5000;
BNX2X_DEV_INFO("FORCING Normal Mode\n");
val &= ~(IGU_BLOCK_CONFIGURATION_REG_BACKWARD_COMP_EN);
REG_WR(bp, IGU_REG_BLOCK_CONFIGURATION, val);
REG_WR(bp, IGU_REG_RESET_MEMORIES, 0x7f);
while (tout && REG_RD(bp, IGU_REG_RESET_MEMORIES)) {
tout--;
usleep_range(1000, 1000);
}
if (REG_RD(bp, IGU_REG_RESET_MEMORIES)) {
dev_err(&bp->pdev->dev,
"FORCING Normal Mode failed!!!\n");
return -EPERM;
}
}
if (val & IGU_BLOCK_CONFIGURATION_REG_BACKWARD_COMP_EN) {
BNX2X_DEV_INFO("IGU Backward Compatible Mode\n");
bp->common.int_block |= INT_BLOCK_MODE_BW_COMP;
} else
BNX2X_DEV_INFO("IGU Normal Mode\n");
bnx2x_get_igu_cam_info(bp);
bnx2x_release_hw_lock(bp, HW_LOCK_RESOURCE_RESET);
}
if (CHIP_IS_E1x(bp))
bp->base_fw_ndsb = BP_PORT(bp) * FP_SB_MAX_E1x + BP_L_ID(bp);
else
bp->base_fw_ndsb = bp->igu_base_sb;
BNX2X_DEV_INFO("igu_dsb_id %d igu_base_sb %d igu_sb_cnt %d\n"
"base_fw_ndsb %d\n", bp->igu_dsb_id, bp->igu_base_sb,
bp->igu_sb_cnt, bp->base_fw_ndsb);
bp->mf_ov = 0;
bp->mf_mode = 0;
vn = BP_VN(bp);
if (!CHIP_IS_E1(bp) && !BP_NOMCP(bp)) {
BNX2X_DEV_INFO("shmem2base 0x%x, size %d, mfcfg offset %d\n",
bp->common.shmem2_base, SHMEM2_RD(bp, size),
(u32)offsetof(struct shmem2_region, mf_cfg_addr));
if (SHMEM2_HAS(bp, mf_cfg_addr))
bp->common.mf_cfg_base = SHMEM2_RD(bp, mf_cfg_addr);
else
bp->common.mf_cfg_base = bp->common.shmem_base +
offsetof(struct shmem_region, func_mb) +
E1H_FUNC_MAX * sizeof(struct drv_func_mb);
if (bp->common.mf_cfg_base != SHMEM_MF_CFG_ADDR_NONE) {
val = SHMEM_RD(bp,
dev_info.shared_feature_config.config);
val &= SHARED_FEAT_CFG_FORCE_SF_MODE_MASK;
switch (val) {
case SHARED_FEAT_CFG_FORCE_SF_MODE_SWITCH_INDEPT:
val = MF_CFG_RD(bp, func_mf_config[func].
mac_upper);
if (val != 0xffff) {
bp->mf_mode = MULTI_FUNCTION_SI;
bp->mf_config[vn] = MF_CFG_RD(bp,
func_mf_config[func].config);
} else
BNX2X_DEV_INFO("illegal MAC address "
"for SI\n");
break;
case SHARED_FEAT_CFG_FORCE_SF_MODE_MF_ALLOWED:
val = MF_CFG_RD(bp,
func_mf_config[FUNC_0].e1hov_tag);
val &= FUNC_MF_CFG_E1HOV_TAG_MASK;
if (val != FUNC_MF_CFG_E1HOV_TAG_DEFAULT) {
bp->mf_mode = MULTI_FUNCTION_SD;
bp->mf_config[vn] = MF_CFG_RD(bp,
func_mf_config[func].config);
} else
BNX2X_DEV_INFO("illegal OV for SD\n");
break;
default:
bp->mf_config[vn] = 0;
BNX2X_DEV_INFO("unkown MF mode 0x%x\n", val);
}
}
BNX2X_DEV_INFO("%s function mode\n",
IS_MF(bp) ? "multi" : "single");
switch (bp->mf_mode) {
case MULTI_FUNCTION_SD:
val = MF_CFG_RD(bp, func_mf_config[func].e1hov_tag) &
FUNC_MF_CFG_E1HOV_TAG_MASK;
if (val != FUNC_MF_CFG_E1HOV_TAG_DEFAULT) {
bp->mf_ov = val;
bp->path_has_ovlan = true;
BNX2X_DEV_INFO("MF OV for func %d is %d "
"(0x%04x)\n", func, bp->mf_ov,
bp->mf_ov);
} else {
dev_err(&bp->pdev->dev,
"No valid MF OV for func %d, "
"aborting\n", func);
return -EPERM;
}
break;
case MULTI_FUNCTION_SI:
BNX2X_DEV_INFO("func %d is in MF "
"switch-independent mode\n", func);
break;
default:
if (vn) {
dev_err(&bp->pdev->dev,
"VN %d is in a single function mode, "
"aborting\n", vn);
return -EPERM;
}
break;
}
if (CHIP_MODE_IS_4_PORT(bp) &&
!bp->path_has_ovlan &&
!IS_MF(bp) &&
bp->common.mf_cfg_base != SHMEM_MF_CFG_ADDR_NONE) {
u8 other_port = !BP_PORT(bp);
u8 other_func = BP_PATH(bp) + 2*other_port;
val = MF_CFG_RD(bp,
func_mf_config[other_func].e1hov_tag);
if (val != FUNC_MF_CFG_E1HOV_TAG_DEFAULT)
bp->path_has_ovlan = true;
}
}
if (CHIP_IS_E1x(bp) && IS_MF(bp))
bp->igu_sb_cnt /= E1HVN_MAX;
bnx2x_get_port_hwinfo(bp);
bnx2x_get_mac_hwinfo(bp);
#ifdef BCM_CNIC
bnx2x_get_cnic_info(bp);
#endif
if (!BP_NOMCP(bp)) {
int mb_idx = BP_FW_MB_IDX(bp);
bp->fw_drv_pulse_wr_seq =
(SHMEM_RD(bp, func_mb[mb_idx].drv_pulse_mb) &
DRV_PULSE_SEQ_MASK);
BNX2X_DEV_INFO("drv_pulse 0x%x\n", bp->fw_drv_pulse_wr_seq);
}
return rc;
}
static void __devinit bnx2x_read_fwinfo(struct bnx2x *bp)
{
int cnt, i, block_end, rodi;
char vpd_data[BNX2X_VPD_LEN+1];
char str_id_reg[VENDOR_ID_LEN+1];
char str_id_cap[VENDOR_ID_LEN+1];
u8 len;
cnt = pci_read_vpd(bp->pdev, 0, BNX2X_VPD_LEN, vpd_data);
memset(bp->fw_ver, 0, sizeof(bp->fw_ver));
if (cnt < BNX2X_VPD_LEN)
goto out_not_found;
i = pci_vpd_find_tag(vpd_data, 0, BNX2X_VPD_LEN,
PCI_VPD_LRDT_RO_DATA);
if (i < 0)
goto out_not_found;
block_end = i + PCI_VPD_LRDT_TAG_SIZE +
pci_vpd_lrdt_size(&vpd_data[i]);
i += PCI_VPD_LRDT_TAG_SIZE;
if (block_end > BNX2X_VPD_LEN)
goto out_not_found;
rodi = pci_vpd_find_info_keyword(vpd_data, i, block_end,
PCI_VPD_RO_KEYWORD_MFR_ID);
if (rodi < 0)
goto out_not_found;
len = pci_vpd_info_field_size(&vpd_data[rodi]);
if (len != VENDOR_ID_LEN)
goto out_not_found;
rodi += PCI_VPD_INFO_FLD_HDR_SIZE;
snprintf(str_id_reg, VENDOR_ID_LEN + 1, "%04x", PCI_VENDOR_ID_DELL);
snprintf(str_id_cap, VENDOR_ID_LEN + 1, "%04X", PCI_VENDOR_ID_DELL);
if (!strncmp(str_id_reg, &vpd_data[rodi], VENDOR_ID_LEN) ||
!strncmp(str_id_cap, &vpd_data[rodi], VENDOR_ID_LEN)) {
rodi = pci_vpd_find_info_keyword(vpd_data, i, block_end,
PCI_VPD_RO_KEYWORD_VENDOR0);
if (rodi >= 0) {
len = pci_vpd_info_field_size(&vpd_data[rodi]);
rodi += PCI_VPD_INFO_FLD_HDR_SIZE;
if (len < 32 && (len + rodi) <= BNX2X_VPD_LEN) {
memcpy(bp->fw_ver, &vpd_data[rodi], len);
bp->fw_ver[len] = ' ';
}
}
return;
}
out_not_found:
return;
}
static void __devinit bnx2x_set_modes_bitmap(struct bnx2x *bp)
{
u32 flags = 0;
if (CHIP_REV_IS_FPGA(bp))
SET_FLAGS(flags, MODE_FPGA);
else if (CHIP_REV_IS_EMUL(bp))
SET_FLAGS(flags, MODE_EMUL);
else
SET_FLAGS(flags, MODE_ASIC);
if (CHIP_MODE_IS_4_PORT(bp))
SET_FLAGS(flags, MODE_PORT4);
else
SET_FLAGS(flags, MODE_PORT2);
if (CHIP_IS_E2(bp))
SET_FLAGS(flags, MODE_E2);
else if (CHIP_IS_E3(bp)) {
SET_FLAGS(flags, MODE_E3);
if (CHIP_REV(bp) == CHIP_REV_Ax)
SET_FLAGS(flags, MODE_E3_A0);
else
SET_FLAGS(flags, MODE_E3_B0 | MODE_COS3);
}
if (IS_MF(bp)) {
SET_FLAGS(flags, MODE_MF);
switch (bp->mf_mode) {
case MULTI_FUNCTION_SD:
SET_FLAGS(flags, MODE_MF_SD);
break;
case MULTI_FUNCTION_SI:
SET_FLAGS(flags, MODE_MF_SI);
break;
}
} else
SET_FLAGS(flags, MODE_SF);
#if defined(__LITTLE_ENDIAN)
SET_FLAGS(flags, MODE_LITTLE_ENDIAN);
#else
SET_FLAGS(flags, MODE_BIG_ENDIAN);
#endif
INIT_MODE_FLAGS(bp) = flags;
}
static int __devinit bnx2x_init_bp(struct bnx2x *bp)
{
int func;
int timer_interval;
int rc;
mutex_init(&bp->port.phy_mutex);
mutex_init(&bp->fw_mb_mutex);
spin_lock_init(&bp->stats_lock);
#ifdef BCM_CNIC
mutex_init(&bp->cnic_mutex);
#endif
INIT_DELAYED_WORK(&bp->sp_task, bnx2x_sp_task);
INIT_DELAYED_WORK(&bp->sp_rtnl_task, bnx2x_sp_rtnl_task);
INIT_DELAYED_WORK(&bp->period_task, bnx2x_period_task);
rc = bnx2x_get_hwinfo(bp);
if (rc)
return rc;
bnx2x_set_modes_bitmap(bp);
rc = bnx2x_alloc_mem_bp(bp);
if (rc)
return rc;
bnx2x_read_fwinfo(bp);
func = BP_FUNC(bp);
if (!BP_NOMCP(bp))
bnx2x_undi_unload(bp);
if (!BP_NOMCP(bp)) {
bp->fw_seq =
(SHMEM_RD(bp, func_mb[BP_FW_MB_IDX(bp)].drv_mb_header) &
DRV_MSG_SEQ_NUMBER_MASK);
BNX2X_DEV_INFO("fw_seq 0x%08x\n", bp->fw_seq);
}
if (CHIP_REV_IS_FPGA(bp))
dev_err(&bp->pdev->dev, "FPGA detected\n");
if (BP_NOMCP(bp) && (func == 0))
dev_err(&bp->pdev->dev, "MCP disabled, "
"must load devices in order!\n");
bp->multi_mode = multi_mode;
if (disable_tpa) {
bp->flags &= ~TPA_ENABLE_FLAG;
bp->dev->features &= ~NETIF_F_LRO;
} else {
bp->flags |= TPA_ENABLE_FLAG;
bp->dev->features |= NETIF_F_LRO;
}
bp->disable_tpa = disable_tpa;
if (CHIP_IS_E1(bp))
bp->dropless_fc = 0;
else
bp->dropless_fc = dropless_fc;
bp->mrrs = mrrs;
bp->tx_ring_size = MAX_TX_AVAIL;
bp->tx_ticks = (50 / BNX2X_BTR) * BNX2X_BTR;
bp->rx_ticks = (25 / BNX2X_BTR) * BNX2X_BTR;
timer_interval = (CHIP_REV_IS_SLOW(bp) ? 5*HZ : HZ);
bp->current_interval = (poll ? poll : timer_interval);
init_timer(&bp->timer);
bp->timer.expires = jiffies + bp->current_interval;
bp->timer.data = (unsigned long) bp;
bp->timer.function = bnx2x_timer;
bnx2x_dcbx_set_state(bp, true, BNX2X_DCBX_ENABLED_ON_NEG_ON);
bnx2x_dcbx_init_params(bp);
#ifdef BCM_CNIC
if (CHIP_IS_E1x(bp))
bp->cnic_base_cl_id = FP_SB_MAX_E1x;
else
bp->cnic_base_cl_id = FP_SB_MAX_E2;
#endif
if (CHIP_IS_E1x(bp))
bp->max_cos = BNX2X_MULTI_TX_COS_E1X;
if (CHIP_IS_E2(bp) || CHIP_IS_E3A0(bp))
bp->max_cos = BNX2X_MULTI_TX_COS_E2_E3A0;
if (CHIP_IS_E3B0(bp))
bp->max_cos = BNX2X_MULTI_TX_COS_E3B0;
return rc;
}
static int bnx2x_open(struct net_device *dev)
{
struct bnx2x *bp = netdev_priv(dev);
bool global = false;
int other_engine = BP_PATH(bp) ? 0 : 1;
u32 other_load_counter, load_counter;
netif_carrier_off(dev);
bnx2x_set_power_state(bp, PCI_D0);
other_load_counter = bnx2x_get_load_cnt(bp, other_engine);
load_counter = bnx2x_get_load_cnt(bp, BP_PATH(bp));
if (!bnx2x_reset_is_done(bp, BP_PATH(bp)) ||
bnx2x_chk_parity_attn(bp, &global, true))
do {
if (global)
bnx2x_set_reset_global(bp);
if ((!load_counter &&
(!global || !other_load_counter)) &&
bnx2x_trylock_leader_lock(bp) &&
!bnx2x_leader_reset(bp)) {
netdev_info(bp->dev, "Recovered in open\n");
break;
}
bnx2x_set_power_state(bp, PCI_D3hot);
bp->recovery_state = BNX2X_RECOVERY_FAILED;
netdev_err(bp->dev, "Recovery flow hasn't been properly"
" completed yet. Try again later. If u still see this"
" message after a few retries then power cycle is"
" required.\n");
return -EAGAIN;
} while (0);
bp->recovery_state = BNX2X_RECOVERY_DONE;
return bnx2x_nic_load(bp, LOAD_OPEN);
}
static int bnx2x_close(struct net_device *dev)
{
struct bnx2x *bp = netdev_priv(dev);
bnx2x_nic_unload(bp, UNLOAD_CLOSE);
bnx2x_set_power_state(bp, PCI_D3hot);
return 0;
}
static inline int bnx2x_init_mcast_macs_list(struct bnx2x *bp,
struct bnx2x_mcast_ramrod_params *p)
{
int mc_count = netdev_mc_count(bp->dev);
struct bnx2x_mcast_list_elem *mc_mac =
kzalloc(sizeof(*mc_mac) * mc_count, GFP_ATOMIC);
struct netdev_hw_addr *ha;
if (!mc_mac)
return -ENOMEM;
INIT_LIST_HEAD(&p->mcast_list);
netdev_for_each_mc_addr(ha, bp->dev) {
mc_mac->mac = bnx2x_mc_addr(ha);
list_add_tail(&mc_mac->link, &p->mcast_list);
mc_mac++;
}
p->mcast_list_len = mc_count;
return 0;
}
static inline void bnx2x_free_mcast_macs_list(
struct bnx2x_mcast_ramrod_params *p)
{
struct bnx2x_mcast_list_elem *mc_mac =
list_first_entry(&p->mcast_list, struct bnx2x_mcast_list_elem,
link);
WARN_ON(!mc_mac);
kfree(mc_mac);
}
static inline int bnx2x_set_uc_list(struct bnx2x *bp)
{
int rc;
struct net_device *dev = bp->dev;
struct netdev_hw_addr *ha;
struct bnx2x_vlan_mac_obj *mac_obj = &bp->fp->mac_obj;
unsigned long ramrod_flags = 0;
rc = bnx2x_del_all_macs(bp, mac_obj, BNX2X_UC_LIST_MAC, false);
if (rc < 0) {
BNX2X_ERR("Failed to schedule DELETE operations: %d\n", rc);
return rc;
}
netdev_for_each_uc_addr(ha, dev) {
rc = bnx2x_set_mac_one(bp, bnx2x_uc_addr(ha), mac_obj, true,
BNX2X_UC_LIST_MAC, &ramrod_flags);
if (rc < 0) {
BNX2X_ERR("Failed to schedule ADD operations: %d\n",
rc);
return rc;
}
}
__set_bit(RAMROD_CONT, &ramrod_flags);
return bnx2x_set_mac_one(bp, NULL, mac_obj, false ,
BNX2X_UC_LIST_MAC, &ramrod_flags);
}
static inline int bnx2x_set_mc_list(struct bnx2x *bp)
{
struct net_device *dev = bp->dev;
struct bnx2x_mcast_ramrod_params rparam = {0};
int rc = 0;
rparam.mcast_obj = &bp->mcast_obj;
rc = bnx2x_config_mcast(bp, &rparam, BNX2X_MCAST_CMD_DEL);
if (rc < 0) {
BNX2X_ERR("Failed to clear multicast "
"configuration: %d\n", rc);
return rc;
}
if (netdev_mc_count(dev)) {
rc = bnx2x_init_mcast_macs_list(bp, &rparam);
if (rc) {
BNX2X_ERR("Failed to create multicast MACs "
"list: %d\n", rc);
return rc;
}
rc = bnx2x_config_mcast(bp, &rparam,
BNX2X_MCAST_CMD_ADD);
if (rc < 0)
BNX2X_ERR("Failed to set a new multicast "
"configuration: %d\n", rc);
bnx2x_free_mcast_macs_list(&rparam);
}
return rc;
}
void bnx2x_set_rx_mode(struct net_device *dev)
{
struct bnx2x *bp = netdev_priv(dev);
u32 rx_mode = BNX2X_RX_MODE_NORMAL;
if (bp->state != BNX2X_STATE_OPEN) {
DP(NETIF_MSG_IFUP, "state is %x, returning\n", bp->state);
return;
}
DP(NETIF_MSG_IFUP, "dev->flags = %x\n", bp->dev->flags);
if (dev->flags & IFF_PROMISC)
rx_mode = BNX2X_RX_MODE_PROMISC;
else if ((dev->flags & IFF_ALLMULTI) ||
((netdev_mc_count(dev) > BNX2X_MAX_MULTICAST) &&
CHIP_IS_E1(bp)))
rx_mode = BNX2X_RX_MODE_ALLMULTI;
else {
if (bnx2x_set_mc_list(bp) < 0)
rx_mode = BNX2X_RX_MODE_ALLMULTI;
if (bnx2x_set_uc_list(bp) < 0)
rx_mode = BNX2X_RX_MODE_PROMISC;
}
bp->rx_mode = rx_mode;
if (test_bit(BNX2X_FILTER_RX_MODE_PENDING, &bp->sp_state)) {
set_bit(BNX2X_FILTER_RX_MODE_SCHED, &bp->sp_state);
return;
}
bnx2x_set_storm_rx_mode(bp);
}
static int bnx2x_mdio_read(struct net_device *netdev, int prtad,
int devad, u16 addr)
{
struct bnx2x *bp = netdev_priv(netdev);
u16 value;
int rc;
DP(NETIF_MSG_LINK, "mdio_read: prtad 0x%x, devad 0x%x, addr 0x%x\n",
prtad, devad, addr);
devad = (devad == MDIO_DEVAD_NONE) ? DEFAULT_PHY_DEV_ADDR : devad;
bnx2x_acquire_phy_lock(bp);
rc = bnx2x_phy_read(&bp->link_params, prtad, devad, addr, &value);
bnx2x_release_phy_lock(bp);
DP(NETIF_MSG_LINK, "mdio_read_val 0x%x rc = 0x%x\n", value, rc);
if (!rc)
rc = value;
return rc;
}
static int bnx2x_mdio_write(struct net_device *netdev, int prtad, int devad,
u16 addr, u16 value)
{
struct bnx2x *bp = netdev_priv(netdev);
int rc;
DP(NETIF_MSG_LINK, "mdio_write: prtad 0x%x, devad 0x%x, addr 0x%x,"
" value 0x%x\n", prtad, devad, addr, value);
devad = (devad == MDIO_DEVAD_NONE) ? DEFAULT_PHY_DEV_ADDR : devad;
bnx2x_acquire_phy_lock(bp);
rc = bnx2x_phy_write(&bp->link_params, prtad, devad, addr, value);
bnx2x_release_phy_lock(bp);
return rc;
}
static int bnx2x_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct bnx2x *bp = netdev_priv(dev);
struct mii_ioctl_data *mdio = if_mii(ifr);
DP(NETIF_MSG_LINK, "ioctl: phy id 0x%x, reg 0x%x, val_in 0x%x\n",
mdio->phy_id, mdio->reg_num, mdio->val_in);
if (!netif_running(dev))
return -EAGAIN;
return mdio_mii_ioctl(&bp->mdio, mdio, cmd);
}
static void poll_bnx2x(struct net_device *dev)
{
struct bnx2x *bp = netdev_priv(dev);
disable_irq(bp->pdev->irq);
bnx2x_interrupt(bp->pdev->irq, dev);
enable_irq(bp->pdev->irq);
}
static inline int bnx2x_set_coherency_mask(struct bnx2x *bp)
{
struct device *dev = &bp->pdev->dev;
if (dma_set_mask(dev, DMA_BIT_MASK(64)) == 0) {
bp->flags |= USING_DAC_FLAG;
if (dma_set_coherent_mask(dev, DMA_BIT_MASK(64)) != 0) {
dev_err(dev, "dma_set_coherent_mask failed, "
"aborting\n");
return -EIO;
}
} else if (dma_set_mask(dev, DMA_BIT_MASK(32)) != 0) {
dev_err(dev, "System does not support DMA, aborting\n");
return -EIO;
}
return 0;
}
static int __devinit bnx2x_init_dev(struct pci_dev *pdev,
struct net_device *dev,
unsigned long board_type)
{
struct bnx2x *bp;
int rc;
SET_NETDEV_DEV(dev, &pdev->dev);
bp = netdev_priv(dev);
bp->dev = dev;
bp->pdev = pdev;
bp->flags = 0;
bp->pf_num = PCI_FUNC(pdev->devfn);
rc = pci_enable_device(pdev);
if (rc) {
dev_err(&bp->pdev->dev,
"Cannot enable PCI device, aborting\n");
goto err_out;
}
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
dev_err(&bp->pdev->dev,
"Cannot find PCI device base address, aborting\n");
rc = -ENODEV;
goto err_out_disable;
}
if (!(pci_resource_flags(pdev, 2) & IORESOURCE_MEM)) {
dev_err(&bp->pdev->dev, "Cannot find second PCI device"
" base address, aborting\n");
rc = -ENODEV;
goto err_out_disable;
}
if (atomic_read(&pdev->enable_cnt) == 1) {
rc = pci_request_regions(pdev, DRV_MODULE_NAME);
if (rc) {
dev_err(&bp->pdev->dev,
"Cannot obtain PCI resources, aborting\n");
goto err_out_disable;
}
pci_set_master(pdev);
pci_save_state(pdev);
}
bp->pm_cap = pci_find_capability(pdev, PCI_CAP_ID_PM);
if (bp->pm_cap == 0) {
dev_err(&bp->pdev->dev,
"Cannot find power management capability, aborting\n");
rc = -EIO;
goto err_out_release;
}
if (!pci_is_pcie(pdev)) {
dev_err(&bp->pdev->dev, "Not PCI Express, aborting\n");
rc = -EIO;
goto err_out_release;
}
rc = bnx2x_set_coherency_mask(bp);
if (rc)
goto err_out_release;
dev->mem_start = pci_resource_start(pdev, 0);
dev->base_addr = dev->mem_start;
dev->mem_end = pci_resource_end(pdev, 0);
dev->irq = pdev->irq;
bp->regview = pci_ioremap_bar(pdev, 0);
if (!bp->regview) {
dev_err(&bp->pdev->dev,
"Cannot map register space, aborting\n");
rc = -ENOMEM;
goto err_out_release;
}
bnx2x_set_power_state(bp, PCI_D0);
pci_write_config_dword(bp->pdev, PCICFG_GRC_ADDRESS,
PCICFG_VENDOR_ID_OFFSET);
REG_WR(bp, PXP2_REG_PGL_ADDR_88_F0, 0);
REG_WR(bp, PXP2_REG_PGL_ADDR_8C_F0, 0);
REG_WR(bp, PXP2_REG_PGL_ADDR_90_F0, 0);
REG_WR(bp, PXP2_REG_PGL_ADDR_94_F0, 0);
if (CHIP_IS_E1x(bp)) {
REG_WR(bp, PXP2_REG_PGL_ADDR_88_F1, 0);
REG_WR(bp, PXP2_REG_PGL_ADDR_8C_F1, 0);
REG_WR(bp, PXP2_REG_PGL_ADDR_90_F1, 0);
REG_WR(bp, PXP2_REG_PGL_ADDR_94_F1, 0);
}
if (board_type != BCM57710 &&
board_type != BCM57711 &&
board_type != BCM57711E)
REG_WR(bp, PGLUE_B_REG_INTERNAL_PFID_ENABLE_TARGET_READ, 1);
bnx2x_clear_load_cnt(bp);
dev->watchdog_timeo = TX_TIMEOUT;
dev->netdev_ops = &bnx2x_netdev_ops;
bnx2x_set_ethtool_ops(dev);
dev->priv_flags |= IFF_UNICAST_FLT;
dev->hw_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_TSO | NETIF_F_TSO_ECN | NETIF_F_TSO6 | NETIF_F_LRO |
NETIF_F_RXCSUM | NETIF_F_RXHASH | NETIF_F_HW_VLAN_TX;
dev->vlan_features = NETIF_F_SG | NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM |
NETIF_F_TSO | NETIF_F_TSO_ECN | NETIF_F_TSO6 | NETIF_F_HIGHDMA;
dev->features |= dev->hw_features | NETIF_F_HW_VLAN_RX;
if (bp->flags & USING_DAC_FLAG)
dev->features |= NETIF_F_HIGHDMA;
dev->hw_features |= NETIF_F_LOOPBACK;
#ifdef BCM_DCBNL
dev->dcbnl_ops = &bnx2x_dcbnl_ops;
#endif
bp->mdio.prtad = MDIO_PRTAD_NONE;
bp->mdio.mmds = 0;
bp->mdio.mode_support = MDIO_SUPPORTS_C45 | MDIO_EMULATE_C22;
bp->mdio.dev = dev;
bp->mdio.mdio_read = bnx2x_mdio_read;
bp->mdio.mdio_write = bnx2x_mdio_write;
return 0;
err_out_release:
if (atomic_read(&pdev->enable_cnt) == 1)
pci_release_regions(pdev);
err_out_disable:
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
err_out:
return rc;
}
static void __devinit bnx2x_get_pcie_width_speed(struct bnx2x *bp,
int *width, int *speed)
{
u32 val = REG_RD(bp, PCICFG_OFFSET + PCICFG_LINK_CONTROL);
*width = (val & PCICFG_LINK_WIDTH) >> PCICFG_LINK_WIDTH_SHIFT;
*speed = (val & PCICFG_LINK_SPEED) >> PCICFG_LINK_SPEED_SHIFT;
}
static int bnx2x_check_firmware(struct bnx2x *bp)
{
const struct firmware *firmware = bp->firmware;
struct bnx2x_fw_file_hdr *fw_hdr;
struct bnx2x_fw_file_section *sections;
u32 offset, len, num_ops;
u16 *ops_offsets;
int i;
const u8 *fw_ver;
if (firmware->size < sizeof(struct bnx2x_fw_file_hdr))
return -EINVAL;
fw_hdr = (struct bnx2x_fw_file_hdr *)firmware->data;
sections = (struct bnx2x_fw_file_section *)fw_hdr;
for (i = 0; i < sizeof(*fw_hdr) / sizeof(*sections); i++) {
offset = be32_to_cpu(sections[i].offset);
len = be32_to_cpu(sections[i].len);
if (offset + len > firmware->size) {
dev_err(&bp->pdev->dev,
"Section %d length is out of bounds\n", i);
return -EINVAL;
}
}
offset = be32_to_cpu(fw_hdr->init_ops_offsets.offset);
ops_offsets = (u16 *)(firmware->data + offset);
num_ops = be32_to_cpu(fw_hdr->init_ops.len) / sizeof(struct raw_op);
for (i = 0; i < be32_to_cpu(fw_hdr->init_ops_offsets.len) / 2; i++) {
if (be16_to_cpu(ops_offsets[i]) > num_ops) {
dev_err(&bp->pdev->dev,
"Section offset %d is out of bounds\n", i);
return -EINVAL;
}
}
offset = be32_to_cpu(fw_hdr->fw_version.offset);
fw_ver = firmware->data + offset;
if ((fw_ver[0] != BCM_5710_FW_MAJOR_VERSION) ||
(fw_ver[1] != BCM_5710_FW_MINOR_VERSION) ||
(fw_ver[2] != BCM_5710_FW_REVISION_VERSION) ||
(fw_ver[3] != BCM_5710_FW_ENGINEERING_VERSION)) {
dev_err(&bp->pdev->dev,
"Bad FW version:%d.%d.%d.%d. Should be %d.%d.%d.%d\n",
fw_ver[0], fw_ver[1], fw_ver[2],
fw_ver[3], BCM_5710_FW_MAJOR_VERSION,
BCM_5710_FW_MINOR_VERSION,
BCM_5710_FW_REVISION_VERSION,
BCM_5710_FW_ENGINEERING_VERSION);
return -EINVAL;
}
return 0;
}
static inline void be32_to_cpu_n(const u8 *_source, u8 *_target, u32 n)
{
const __be32 *source = (const __be32 *)_source;
u32 *target = (u32 *)_target;
u32 i;
for (i = 0; i < n/4; i++)
target[i] = be32_to_cpu(source[i]);
}
static inline void bnx2x_prep_ops(const u8 *_source, u8 *_target, u32 n)
{
const __be32 *source = (const __be32 *)_source;
struct raw_op *target = (struct raw_op *)_target;
u32 i, j, tmp;
for (i = 0, j = 0; i < n/8; i++, j += 2) {
tmp = be32_to_cpu(source[j]);
target[i].op = (tmp >> 24) & 0xff;
target[i].offset = tmp & 0xffffff;
target[i].raw_data = be32_to_cpu(source[j + 1]);
}
}
static inline void bnx2x_prep_iro(const u8 *_source, u8 *_target, u32 n)
{
const __be32 *source = (const __be32 *)_source;
struct iro *target = (struct iro *)_target;
u32 i, j, tmp;
for (i = 0, j = 0; i < n/sizeof(struct iro); i++) {
target[i].base = be32_to_cpu(source[j]);
j++;
tmp = be32_to_cpu(source[j]);
target[i].m1 = (tmp >> 16) & 0xffff;
target[i].m2 = tmp & 0xffff;
j++;
tmp = be32_to_cpu(source[j]);
target[i].m3 = (tmp >> 16) & 0xffff;
target[i].size = tmp & 0xffff;
j++;
}
}
static inline void be16_to_cpu_n(const u8 *_source, u8 *_target, u32 n)
{
const __be16 *source = (const __be16 *)_source;
u16 *target = (u16 *)_target;
u32 i;
for (i = 0; i < n/2; i++)
target[i] = be16_to_cpu(source[i]);
}
int bnx2x_init_firmware(struct bnx2x *bp)
{
struct bnx2x_fw_file_hdr *fw_hdr;
int rc;
if (!bp->firmware) {
const char *fw_file_name;
if (CHIP_IS_E1(bp))
fw_file_name = FW_FILE_NAME_E1;
else if (CHIP_IS_E1H(bp))
fw_file_name = FW_FILE_NAME_E1H;
else if (!CHIP_IS_E1x(bp))
fw_file_name = FW_FILE_NAME_E2;
else {
BNX2X_ERR("Unsupported chip revision\n");
return -EINVAL;
}
BNX2X_DEV_INFO("Loading %s\n", fw_file_name);
rc = request_firmware(&bp->firmware, fw_file_name,
&bp->pdev->dev);
if (rc) {
BNX2X_ERR("Can't load firmware file %s\n",
fw_file_name);
goto request_firmware_exit;
}
rc = bnx2x_check_firmware(bp);
if (rc) {
BNX2X_ERR("Corrupt firmware file %s\n", fw_file_name);
goto request_firmware_exit;
}
}
fw_hdr = (struct bnx2x_fw_file_hdr *)bp->firmware->data;
BNX2X_ALLOC_AND_SET(init_data, request_firmware_exit, be32_to_cpu_n);
BNX2X_ALLOC_AND_SET(init_ops, init_ops_alloc_err, bnx2x_prep_ops);
BNX2X_ALLOC_AND_SET(init_ops_offsets, init_offsets_alloc_err,
be16_to_cpu_n);
INIT_TSEM_INT_TABLE_DATA(bp) = bp->firmware->data +
be32_to_cpu(fw_hdr->tsem_int_table_data.offset);
INIT_TSEM_PRAM_DATA(bp) = bp->firmware->data +
be32_to_cpu(fw_hdr->tsem_pram_data.offset);
INIT_USEM_INT_TABLE_DATA(bp) = bp->firmware->data +
be32_to_cpu(fw_hdr->usem_int_table_data.offset);
INIT_USEM_PRAM_DATA(bp) = bp->firmware->data +
be32_to_cpu(fw_hdr->usem_pram_data.offset);
INIT_XSEM_INT_TABLE_DATA(bp) = bp->firmware->data +
be32_to_cpu(fw_hdr->xsem_int_table_data.offset);
INIT_XSEM_PRAM_DATA(bp) = bp->firmware->data +
be32_to_cpu(fw_hdr->xsem_pram_data.offset);
INIT_CSEM_INT_TABLE_DATA(bp) = bp->firmware->data +
be32_to_cpu(fw_hdr->csem_int_table_data.offset);
INIT_CSEM_PRAM_DATA(bp) = bp->firmware->data +
be32_to_cpu(fw_hdr->csem_pram_data.offset);
BNX2X_ALLOC_AND_SET(iro_arr, iro_alloc_err, bnx2x_prep_iro);
return 0;
iro_alloc_err:
kfree(bp->init_ops_offsets);
init_offsets_alloc_err:
kfree(bp->init_ops);
init_ops_alloc_err:
kfree(bp->init_data);
request_firmware_exit:
release_firmware(bp->firmware);
return rc;
}
static void bnx2x_release_firmware(struct bnx2x *bp)
{
kfree(bp->init_ops_offsets);
kfree(bp->init_ops);
kfree(bp->init_data);
release_firmware(bp->firmware);
bp->firmware = NULL;
}
void bnx2x__init_func_obj(struct bnx2x *bp)
{
bnx2x_setup_dmae(bp);
bnx2x_init_func_obj(bp, &bp->func_obj,
bnx2x_sp(bp, func_rdata),
bnx2x_sp_mapping(bp, func_rdata),
&bnx2x_func_sp_drv);
}
static inline int bnx2x_set_qm_cid_count(struct bnx2x *bp)
{
int cid_count = BNX2X_L2_CID_COUNT(bp);
#ifdef BCM_CNIC
cid_count += CNIC_CID_MAX;
#endif
return roundup(cid_count, QM_CID_ROUND);
}
static inline int bnx2x_get_num_non_def_sbs(struct pci_dev *pdev)
{
int pos;
u16 control;
pos = pci_find_capability(pdev, PCI_CAP_ID_MSIX);
if (!pos)
return 1 + CNIC_PRESENT;
pci_read_config_word(pdev, pos + PCI_MSI_FLAGS, &control);
return control & PCI_MSIX_FLAGS_QSIZE;
}
static int __devinit bnx2x_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *dev = NULL;
struct bnx2x *bp;
int pcie_width, pcie_speed;
int rc, max_non_def_sbs;
int rx_count, tx_count, rss_count;
u8 max_cos_est = 0;
switch (ent->driver_data) {
case BCM57710:
case BCM57711:
case BCM57711E:
max_cos_est = BNX2X_MULTI_TX_COS_E1X;
break;
case BCM57712:
case BCM57712_MF:
max_cos_est = BNX2X_MULTI_TX_COS_E2_E3A0;
break;
case BCM57800:
case BCM57800_MF:
case BCM57810:
case BCM57810_MF:
case BCM57840:
case BCM57840_MF:
max_cos_est = BNX2X_MULTI_TX_COS_E3B0;
break;
default:
pr_err("Unknown board_type (%ld), aborting\n",
ent->driver_data);
return -ENODEV;
}
max_non_def_sbs = bnx2x_get_num_non_def_sbs(pdev);
max_non_def_sbs = min_t(int, FP_SB_MAX_E1x, max_non_def_sbs);
WARN_ON(!max_non_def_sbs);
rss_count = max_non_def_sbs - CNIC_PRESENT;
rx_count = rss_count + FCOE_PRESENT;
tx_count = MAX_TXQS_PER_COS * max_cos_est + FCOE_PRESENT;
dev = alloc_etherdev_mqs(sizeof(*bp), tx_count, rx_count);
if (!dev) {
dev_err(&pdev->dev, "Cannot allocate net device\n");
return -ENOMEM;
}
bp = netdev_priv(dev);
DP(NETIF_MSG_DRV, "Allocated netdev with %d tx and %d rx queues\n",
tx_count, rx_count);
bp->igu_sb_cnt = max_non_def_sbs;
bp->msg_enable = debug;
pci_set_drvdata(pdev, dev);
rc = bnx2x_init_dev(pdev, dev, ent->driver_data);
if (rc < 0) {
free_netdev(dev);
return rc;
}
DP(NETIF_MSG_DRV, "max_non_def_sbs %d\n", max_non_def_sbs);
rc = bnx2x_init_bp(bp);
if (rc)
goto init_one_exit;
bp->doorbells = ioremap_nocache(pci_resource_start(pdev, 2),
min_t(u64, BNX2X_DB_SIZE(bp),
pci_resource_len(pdev, 2)));
if (!bp->doorbells) {
dev_err(&bp->pdev->dev,
"Cannot map doorbell space, aborting\n");
rc = -ENOMEM;
goto init_one_exit;
}
bp->qm_cid_count = bnx2x_set_qm_cid_count(bp);
#ifdef BCM_CNIC
if (CHIP_IS_E1x(bp) || CHIP_IS_E3(bp))
bp->flags |= NO_FCOE_FLAG;
#endif
bnx2x_set_int_mode(bp);
bnx2x_add_all_napi(bp);
rc = register_netdev(dev);
if (rc) {
dev_err(&pdev->dev, "Cannot register net device\n");
goto init_one_exit;
}
#ifdef BCM_CNIC
if (!NO_FCOE(bp)) {
rtnl_lock();
dev_addr_add(bp->dev, bp->fip_mac, NETDEV_HW_ADDR_T_SAN);
rtnl_unlock();
}
#endif
bnx2x_get_pcie_width_speed(bp, &pcie_width, &pcie_speed);
netdev_info(dev, "%s (%c%d) PCI-E x%d %s found at mem %lx, IRQ %d, node addr %pM\n",
board_info[ent->driver_data].name,
(CHIP_REV(bp) >> 12) + 'A', (CHIP_METAL(bp) >> 4),
pcie_width,
((!CHIP_IS_E2(bp) && pcie_speed == 2) ||
(CHIP_IS_E2(bp) && pcie_speed == 1)) ?
"5GHz (Gen2)" : "2.5GHz",
dev->base_addr, bp->pdev->irq, dev->dev_addr);
return 0;
init_one_exit:
if (bp->regview)
iounmap(bp->regview);
if (bp->doorbells)
iounmap(bp->doorbells);
free_netdev(dev);
if (atomic_read(&pdev->enable_cnt) == 1)
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
return rc;
}
static void __devexit bnx2x_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct bnx2x *bp;
if (!dev) {
dev_err(&pdev->dev, "BAD net device from bnx2x_init_one\n");
return;
}
bp = netdev_priv(dev);
#ifdef BCM_CNIC
if (!NO_FCOE(bp)) {
rtnl_lock();
dev_addr_del(bp->dev, bp->fip_mac, NETDEV_HW_ADDR_T_SAN);
rtnl_unlock();
}
#endif
#ifdef BCM_DCBNL
bnx2x_dcbnl_update_applist(bp, true);
#endif
unregister_netdev(dev);
bnx2x_del_all_napi(bp);
bnx2x_set_power_state(bp, PCI_D0);
bnx2x_disable_msi(bp);
bnx2x_set_power_state(bp, PCI_D3hot);
cancel_delayed_work_sync(&bp->sp_rtnl_task);
if (bp->regview)
iounmap(bp->regview);
if (bp->doorbells)
iounmap(bp->doorbells);
bnx2x_release_firmware(bp);
bnx2x_free_mem_bp(bp);
free_netdev(dev);
if (atomic_read(&pdev->enable_cnt) == 1)
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int bnx2x_eeh_nic_unload(struct bnx2x *bp)
{
int i;
bp->state = BNX2X_STATE_ERROR;
bp->rx_mode = BNX2X_RX_MODE_NONE;
#ifdef BCM_CNIC
bnx2x_cnic_notify(bp, CNIC_CTL_STOP_CMD);
#endif
bnx2x_tx_disable(bp);
bnx2x_netif_stop(bp, 0);
del_timer_sync(&bp->timer);
bnx2x_stats_handle(bp, STATS_EVENT_STOP);
bnx2x_free_irq(bp);
bnx2x_free_skbs(bp);
for_each_rx_queue(bp, i)
bnx2x_free_rx_sge_range(bp, bp->fp + i, NUM_RX_SGE);
bnx2x_free_mem(bp);
bp->state = BNX2X_STATE_CLOSED;
netif_carrier_off(bp->dev);
return 0;
}
static void bnx2x_eeh_recover(struct bnx2x *bp)
{
u32 val;
mutex_init(&bp->port.phy_mutex);
bp->common.shmem_base = REG_RD(bp, MISC_REG_SHARED_MEM_ADDR);
bp->link_params.shmem_base = bp->common.shmem_base;
BNX2X_DEV_INFO("shmem offset is 0x%x\n", bp->common.shmem_base);
if (!bp->common.shmem_base ||
(bp->common.shmem_base < 0xA0000) ||
(bp->common.shmem_base >= 0xC0000)) {
BNX2X_DEV_INFO("MCP not active\n");
bp->flags |= NO_MCP_FLAG;
return;
}
val = SHMEM_RD(bp, validity_map[BP_PORT(bp)]);
if ((val & (SHR_MEM_VALIDITY_DEV_INFO | SHR_MEM_VALIDITY_MB))
!= (SHR_MEM_VALIDITY_DEV_INFO | SHR_MEM_VALIDITY_MB))
BNX2X_ERR("BAD MCP validity signature\n");
if (!BP_NOMCP(bp)) {
bp->fw_seq =
(SHMEM_RD(bp, func_mb[BP_FW_MB_IDX(bp)].drv_mb_header) &
DRV_MSG_SEQ_NUMBER_MASK);
BNX2X_DEV_INFO("fw_seq 0x%08x\n", bp->fw_seq);
}
}
static pci_ers_result_t bnx2x_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct bnx2x *bp = netdev_priv(dev);
rtnl_lock();
netif_device_detach(dev);
if (state == pci_channel_io_perm_failure) {
rtnl_unlock();
return PCI_ERS_RESULT_DISCONNECT;
}
if (netif_running(dev))
bnx2x_eeh_nic_unload(bp);
pci_disable_device(pdev);
rtnl_unlock();
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t bnx2x_io_slot_reset(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct bnx2x *bp = netdev_priv(dev);
rtnl_lock();
if (pci_enable_device(pdev)) {
dev_err(&pdev->dev,
"Cannot re-enable PCI device after reset\n");
rtnl_unlock();
return PCI_ERS_RESULT_DISCONNECT;
}
pci_set_master(pdev);
pci_restore_state(pdev);
if (netif_running(dev))
bnx2x_set_power_state(bp, PCI_D0);
rtnl_unlock();
return PCI_ERS_RESULT_RECOVERED;
}
static void bnx2x_io_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct bnx2x *bp = netdev_priv(dev);
if (bp->recovery_state != BNX2X_RECOVERY_DONE) {
netdev_err(bp->dev, "Handling parity error recovery. "
"Try again later\n");
return;
}
rtnl_lock();
bnx2x_eeh_recover(bp);
if (netif_running(dev))
bnx2x_nic_load(bp, LOAD_NORMAL);
netif_device_attach(dev);
rtnl_unlock();
}
static int __init bnx2x_init(void)
{
int ret;
pr_info("%s", version);
bnx2x_wq = create_singlethread_workqueue("bnx2x");
if (bnx2x_wq == NULL) {
pr_err("Cannot create workqueue\n");
return -ENOMEM;
}
ret = pci_register_driver(&bnx2x_pci_driver);
if (ret) {
pr_err("Cannot register driver\n");
destroy_workqueue(bnx2x_wq);
}
return ret;
}
static void __exit bnx2x_cleanup(void)
{
pci_unregister_driver(&bnx2x_pci_driver);
destroy_workqueue(bnx2x_wq);
}
void bnx2x_notify_link_changed(struct bnx2x *bp)
{
REG_WR(bp, MISC_REG_AEU_GENERAL_ATTN_12 + BP_FUNC(bp)*sizeof(u32), 1);
}
static inline int bnx2x_set_iscsi_eth_mac_addr(struct bnx2x *bp)
{
unsigned long ramrod_flags = 0;
__set_bit(RAMROD_COMP_WAIT, &ramrod_flags);
return bnx2x_set_mac_one(bp, bp->cnic_eth_dev.iscsi_mac,
&bp->iscsi_l2_mac_obj, true,
BNX2X_ISCSI_ETH_MAC, &ramrod_flags);
}
static void bnx2x_cnic_sp_post(struct bnx2x *bp, int count)
{
struct eth_spe *spe;
#ifdef BNX2X_STOP_ON_ERROR
if (unlikely(bp->panic))
return;
#endif
spin_lock_bh(&bp->spq_lock);
BUG_ON(bp->cnic_spq_pending < count);
bp->cnic_spq_pending -= count;
for (; bp->cnic_kwq_pending; bp->cnic_kwq_pending--) {
u16 type = (le16_to_cpu(bp->cnic_kwq_cons->hdr.type)
& SPE_HDR_CONN_TYPE) >>
SPE_HDR_CONN_TYPE_SHIFT;
u8 cmd = (le32_to_cpu(bp->cnic_kwq_cons->hdr.conn_and_cmd_data)
>> SPE_HDR_CMD_ID_SHIFT) & 0xff;
if (type == ETH_CONNECTION_TYPE) {
if (cmd == RAMROD_CMD_ID_ETH_CLIENT_SETUP)
bnx2x_set_ctx_validation(bp, &bp->context.
vcxt[BNX2X_ISCSI_ETH_CID].eth,
BNX2X_ISCSI_ETH_CID);
}
if (type == ETH_CONNECTION_TYPE) {
if (!atomic_read(&bp->cq_spq_left))
break;
else
atomic_dec(&bp->cq_spq_left);
} else if (type == NONE_CONNECTION_TYPE) {
if (!atomic_read(&bp->eq_spq_left))
break;
else
atomic_dec(&bp->eq_spq_left);
} else if ((type == ISCSI_CONNECTION_TYPE) ||
(type == FCOE_CONNECTION_TYPE)) {
if (bp->cnic_spq_pending >=
bp->cnic_eth_dev.max_kwqe_pending)
break;
else
bp->cnic_spq_pending++;
} else {
BNX2X_ERR("Unknown SPE type: %d\n", type);
bnx2x_panic();
break;
}
spe = bnx2x_sp_get_next(bp);
*spe = *bp->cnic_kwq_cons;
DP(NETIF_MSG_TIMER, "pending on SPQ %d, on KWQ %d count %d\n",
bp->cnic_spq_pending, bp->cnic_kwq_pending, count);
if (bp->cnic_kwq_cons == bp->cnic_kwq_last)
bp->cnic_kwq_cons = bp->cnic_kwq;
else
bp->cnic_kwq_cons++;
}
bnx2x_sp_prod_update(bp);
spin_unlock_bh(&bp->spq_lock);
}
static int bnx2x_cnic_sp_queue(struct net_device *dev,
struct kwqe_16 *kwqes[], u32 count)
{
struct bnx2x *bp = netdev_priv(dev);
int i;
#ifdef BNX2X_STOP_ON_ERROR
if (unlikely(bp->panic))
return -EIO;
#endif
spin_lock_bh(&bp->spq_lock);
for (i = 0; i < count; i++) {
struct eth_spe *spe = (struct eth_spe *)kwqes[i];
if (bp->cnic_kwq_pending == MAX_SP_DESC_CNT)
break;
*bp->cnic_kwq_prod = *spe;
bp->cnic_kwq_pending++;
DP(NETIF_MSG_TIMER, "L5 SPQE %x %x %x:%x pos %d\n",
spe->hdr.conn_and_cmd_data, spe->hdr.type,
spe->data.update_data_addr.hi,
spe->data.update_data_addr.lo,
bp->cnic_kwq_pending);
if (bp->cnic_kwq_prod == bp->cnic_kwq_last)
bp->cnic_kwq_prod = bp->cnic_kwq;
else
bp->cnic_kwq_prod++;
}
spin_unlock_bh(&bp->spq_lock);
if (bp->cnic_spq_pending < bp->cnic_eth_dev.max_kwqe_pending)
bnx2x_cnic_sp_post(bp, 0);
return i;
}
static int bnx2x_cnic_ctl_send(struct bnx2x *bp, struct cnic_ctl_info *ctl)
{
struct cnic_ops *c_ops;
int rc = 0;
mutex_lock(&bp->cnic_mutex);
c_ops = rcu_dereference_protected(bp->cnic_ops,
lockdep_is_held(&bp->cnic_mutex));
if (c_ops)
rc = c_ops->cnic_ctl(bp->cnic_data, ctl);
mutex_unlock(&bp->cnic_mutex);
return rc;
}
static int bnx2x_cnic_ctl_send_bh(struct bnx2x *bp, struct cnic_ctl_info *ctl)
{
struct cnic_ops *c_ops;
int rc = 0;
rcu_read_lock();
c_ops = rcu_dereference(bp->cnic_ops);
if (c_ops)
rc = c_ops->cnic_ctl(bp->cnic_data, ctl);
rcu_read_unlock();
return rc;
}
int bnx2x_cnic_notify(struct bnx2x *bp, int cmd)
{
struct cnic_ctl_info ctl = {0};
ctl.cmd = cmd;
return bnx2x_cnic_ctl_send(bp, &ctl);
}
static void bnx2x_cnic_cfc_comp(struct bnx2x *bp, int cid, u8 err)
{
struct cnic_ctl_info ctl = {0};
ctl.cmd = CNIC_CTL_COMPLETION_CMD;
ctl.data.comp.cid = cid;
ctl.data.comp.error = err;
bnx2x_cnic_ctl_send_bh(bp, &ctl);
bnx2x_cnic_sp_post(bp, 0);
}
static void bnx2x_set_iscsi_eth_rx_mode(struct bnx2x *bp, bool start)
{
unsigned long accept_flags = 0, ramrod_flags = 0;
u8 cl_id = bnx2x_cnic_eth_cl_id(bp, BNX2X_ISCSI_ETH_CL_ID_IDX);
int sched_state = BNX2X_FILTER_ISCSI_ETH_STOP_SCHED;
if (start) {
__set_bit(BNX2X_ACCEPT_UNICAST, &accept_flags);
__set_bit(BNX2X_ACCEPT_ALL_MULTICAST, &accept_flags);
__set_bit(BNX2X_ACCEPT_BROADCAST, &accept_flags);
__set_bit(BNX2X_ACCEPT_ANY_VLAN, &accept_flags);
clear_bit(BNX2X_FILTER_ISCSI_ETH_STOP_SCHED, &bp->sp_state);
sched_state = BNX2X_FILTER_ISCSI_ETH_START_SCHED;
} else
clear_bit(BNX2X_FILTER_ISCSI_ETH_START_SCHED, &bp->sp_state);
if (test_bit(BNX2X_FILTER_RX_MODE_PENDING, &bp->sp_state))
set_bit(sched_state, &bp->sp_state);
else {
__set_bit(RAMROD_RX, &ramrod_flags);
bnx2x_set_q_rx_mode(bp, cl_id, 0, accept_flags, 0,
ramrod_flags);
}
}
static int bnx2x_drv_ctl(struct net_device *dev, struct drv_ctl_info *ctl)
{
struct bnx2x *bp = netdev_priv(dev);
int rc = 0;
switch (ctl->cmd) {
case DRV_CTL_CTXTBL_WR_CMD: {
u32 index = ctl->data.io.offset;
dma_addr_t addr = ctl->data.io.dma_addr;
bnx2x_ilt_wr(bp, index, addr);
break;
}
case DRV_CTL_RET_L5_SPQ_CREDIT_CMD: {
int count = ctl->data.credit.credit_count;
bnx2x_cnic_sp_post(bp, count);
break;
}
case DRV_CTL_START_L2_CMD: {
struct cnic_eth_dev *cp = &bp->cnic_eth_dev;
unsigned long sp_bits = 0;
bnx2x_init_mac_obj(bp, &bp->iscsi_l2_mac_obj,
cp->iscsi_l2_client_id,
cp->iscsi_l2_cid, BP_FUNC(bp),
bnx2x_sp(bp, mac_rdata),
bnx2x_sp_mapping(bp, mac_rdata),
BNX2X_FILTER_MAC_PENDING,
&bp->sp_state, BNX2X_OBJ_TYPE_RX,
&bp->macs_pool);
rc = bnx2x_set_iscsi_eth_mac_addr(bp);
if (rc)
break;
mmiowb();
barrier();
netif_addr_lock_bh(dev);
bnx2x_set_iscsi_eth_rx_mode(bp, true);
netif_addr_unlock_bh(dev);
__set_bit(BNX2X_FILTER_RX_MODE_PENDING, &sp_bits);
__set_bit(BNX2X_FILTER_ISCSI_ETH_START_SCHED, &sp_bits);
if (!bnx2x_wait_sp_comp(bp, sp_bits))
BNX2X_ERR("rx_mode completion timed out!\n");
break;
}
case DRV_CTL_STOP_L2_CMD: {
unsigned long sp_bits = 0;
netif_addr_lock_bh(dev);
bnx2x_set_iscsi_eth_rx_mode(bp, false);
netif_addr_unlock_bh(dev);
__set_bit(BNX2X_FILTER_RX_MODE_PENDING, &sp_bits);
__set_bit(BNX2X_FILTER_ISCSI_ETH_STOP_SCHED, &sp_bits);
if (!bnx2x_wait_sp_comp(bp, sp_bits))
BNX2X_ERR("rx_mode completion timed out!\n");
mmiowb();
barrier();
rc = bnx2x_del_all_macs(bp, &bp->iscsi_l2_mac_obj,
BNX2X_ISCSI_ETH_MAC, true);
break;
}
case DRV_CTL_RET_L2_SPQ_CREDIT_CMD: {
int count = ctl->data.credit.credit_count;
smp_mb__before_atomic_inc();
atomic_add(count, &bp->cq_spq_left);
smp_mb__after_atomic_inc();
break;
}
default:
BNX2X_ERR("unknown command %x\n", ctl->cmd);
rc = -EINVAL;
}
return rc;
}
void bnx2x_setup_cnic_irq_info(struct bnx2x *bp)
{
struct cnic_eth_dev *cp = &bp->cnic_eth_dev;
if (bp->flags & USING_MSIX_FLAG) {
cp->drv_state |= CNIC_DRV_STATE_USING_MSIX;
cp->irq_arr[0].irq_flags |= CNIC_IRQ_FL_MSIX;
cp->irq_arr[0].vector = bp->msix_table[1].vector;
} else {
cp->drv_state &= ~CNIC_DRV_STATE_USING_MSIX;
cp->irq_arr[0].irq_flags &= ~CNIC_IRQ_FL_MSIX;
}
if (!CHIP_IS_E1x(bp))
cp->irq_arr[0].status_blk = (void *)bp->cnic_sb.e2_sb;
else
cp->irq_arr[0].status_blk = (void *)bp->cnic_sb.e1x_sb;
cp->irq_arr[0].status_blk_num = bnx2x_cnic_fw_sb_id(bp);
cp->irq_arr[0].status_blk_num2 = bnx2x_cnic_igu_sb_id(bp);
cp->irq_arr[1].status_blk = bp->def_status_blk;
cp->irq_arr[1].status_blk_num = DEF_SB_ID;
cp->irq_arr[1].status_blk_num2 = DEF_SB_IGU_ID;
cp->num_irq = 2;
}
static int bnx2x_register_cnic(struct net_device *dev, struct cnic_ops *ops,
void *data)
{
struct bnx2x *bp = netdev_priv(dev);
struct cnic_eth_dev *cp = &bp->cnic_eth_dev;
if (ops == NULL)
return -EINVAL;
bp->cnic_kwq = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!bp->cnic_kwq)
return -ENOMEM;
bp->cnic_kwq_cons = bp->cnic_kwq;
bp->cnic_kwq_prod = bp->cnic_kwq;
bp->cnic_kwq_last = bp->cnic_kwq + MAX_SP_DESC_CNT;
bp->cnic_spq_pending = 0;
bp->cnic_kwq_pending = 0;
bp->cnic_data = data;
cp->num_irq = 0;
cp->drv_state |= CNIC_DRV_STATE_REGD;
cp->iro_arr = bp->iro_arr;
bnx2x_setup_cnic_irq_info(bp);
rcu_assign_pointer(bp->cnic_ops, ops);
return 0;
}
static int bnx2x_unregister_cnic(struct net_device *dev)
{
struct bnx2x *bp = netdev_priv(dev);
struct cnic_eth_dev *cp = &bp->cnic_eth_dev;
mutex_lock(&bp->cnic_mutex);
cp->drv_state = 0;
rcu_assign_pointer(bp->cnic_ops, NULL);
mutex_unlock(&bp->cnic_mutex);
synchronize_rcu();
kfree(bp->cnic_kwq);
bp->cnic_kwq = NULL;
return 0;
}
struct cnic_eth_dev *bnx2x_cnic_probe(struct net_device *dev)
{
struct bnx2x *bp = netdev_priv(dev);
struct cnic_eth_dev *cp = &bp->cnic_eth_dev;
if (NO_ISCSI(bp) && NO_FCOE(bp))
return NULL;
cp->drv_owner = THIS_MODULE;
cp->chip_id = CHIP_ID(bp);
cp->pdev = bp->pdev;
cp->io_base = bp->regview;
cp->io_base2 = bp->doorbells;
cp->max_kwqe_pending = 8;
cp->ctx_blk_size = CDU_ILT_PAGE_SZ;
cp->ctx_tbl_offset = FUNC_ILT_BASE(BP_FUNC(bp)) +
bnx2x_cid_ilt_lines(bp);
cp->ctx_tbl_len = CNIC_ILT_LINES;
cp->starting_cid = bnx2x_cid_ilt_lines(bp) * ILT_PAGE_CIDS;
cp->drv_submit_kwqes_16 = bnx2x_cnic_sp_queue;
cp->drv_ctl = bnx2x_drv_ctl;
cp->drv_register_cnic = bnx2x_register_cnic;
cp->drv_unregister_cnic = bnx2x_unregister_cnic;
cp->fcoe_init_cid = BNX2X_FCOE_ETH_CID;
cp->iscsi_l2_client_id =
bnx2x_cnic_eth_cl_id(bp, BNX2X_ISCSI_ETH_CL_ID_IDX);
cp->iscsi_l2_cid = BNX2X_ISCSI_ETH_CID;
if (NO_ISCSI_OOO(bp))
cp->drv_state |= CNIC_DRV_STATE_NO_ISCSI_OOO;
if (NO_ISCSI(bp))
cp->drv_state |= CNIC_DRV_STATE_NO_ISCSI;
if (NO_FCOE(bp))
cp->drv_state |= CNIC_DRV_STATE_NO_FCOE;
DP(BNX2X_MSG_SP, "page_size %d, tbl_offset %d, tbl_lines %d, "
"starting cid %d\n",
cp->ctx_blk_size,
cp->ctx_tbl_offset,
cp->ctx_tbl_len,
cp->starting_cid);
return cp;
}
