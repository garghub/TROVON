static u32 cond4(const u32 *r, const u32 *imm)
{
return ((r[0] & imm[0]) != imm[1]) && ((r[1] & imm[2]) != imm[3]);
}
static u32 cond6(const u32 *r, const u32 *imm)
{
return ((r[0] >> imm[0]) & imm[1]) != imm[2];
}
static u32 cond5(const u32 *r, const u32 *imm)
{
return (r[0] & imm[0]) != imm[1];
}
static u32 cond8(const u32 *r, const u32 *imm)
{
return ((r[0] & imm[0]) >> imm[1]) !=
(((r[0] & imm[2]) >> imm[3]) | ((r[1] & imm[4]) << imm[5]));
}
static u32 cond9(const u32 *r, const u32 *imm)
{
return ((r[0] & imm[0]) >> imm[1]) != (r[0] & imm[2]);
}
static u32 cond1(const u32 *r, const u32 *imm)
{
return (r[0] & ~imm[0]) != imm[1];
}
static u32 cond0(const u32 *r, const u32 *imm)
{
return r[0] != imm[0];
}
static u32 cond10(const u32 *r, const u32 *imm)
{
return r[0] != r[1] && r[2] == imm[0];
}
static u32 cond11(const u32 *r, const u32 *imm)
{
return r[0] != r[1] && r[2] > imm[0];
}
static u32 cond3(const u32 *r, const u32 *imm)
{
return r[0] != r[1];
}
static u32 cond12(const u32 *r, const u32 *imm)
{
return r[0] & imm[0];
}
static u32 cond7(const u32 *r, const u32 *imm)
{
return r[0] < (r[1] - imm[0]);
}
static u32 cond2(const u32 *r, const u32 *imm)
{
return r[0] > imm[0];
}
static u32 qed_read_unaligned_dword(u8 *buf)
{
u32 dword;
memcpy((u8 *)&dword, buf, sizeof(dword));
return dword;
}
static u32 qed_grc_get_param(struct qed_hwfn *p_hwfn,
enum dbg_grc_params grc_param)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
return dev_data->grc.param_val[grc_param];
}
static void qed_dbg_grc_init_params(struct qed_hwfn *p_hwfn)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
if (!dev_data->grc.params_initialized) {
qed_dbg_grc_set_params_default(p_hwfn);
dev_data->grc.params_initialized = 1;
}
}
static enum dbg_status qed_dbg_dev_init(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
if (dev_data->initialized)
return DBG_STATUS_OK;
if (QED_IS_K2(p_hwfn->cdev)) {
dev_data->chip_id = CHIP_K2;
dev_data->mode_enable[MODE_K2] = 1;
} else if (QED_IS_BB_B0(p_hwfn->cdev)) {
dev_data->chip_id = CHIP_BB_B0;
dev_data->mode_enable[MODE_BB] = 1;
} else {
return DBG_STATUS_UNKNOWN_CHIP;
}
dev_data->platform_id = PLATFORM_ASIC;
dev_data->mode_enable[MODE_ASIC] = 1;
qed_dbg_grc_init_params(p_hwfn);
dev_data->initialized = true;
return DBG_STATUS_OK;
}
static void qed_read_fw_info(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u8 storm_id, struct fw_info *fw_info)
{
u32 addr = s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_INT_RAM +
DWORDS_TO_BYTES(SEM_FAST_REG_INT_RAM_SIZE) -
sizeof(struct fw_info_location);
struct fw_info_location fw_info_location;
u32 *dest = (u32 *)&fw_info_location;
u32 i;
memset(&fw_info_location, 0, sizeof(fw_info_location));
memset(fw_info, 0, sizeof(*fw_info));
for (i = 0; i < BYTES_TO_DWORDS(sizeof(fw_info_location));
i++, addr += BYTES_IN_DWORD)
dest[i] = qed_rd(p_hwfn, p_ptt, addr);
if (fw_info_location.size > 0 && fw_info_location.size <=
sizeof(*fw_info)) {
addr = fw_info_location.grc_addr;
dest = (u32 *)fw_info;
for (i = 0; i < BYTES_TO_DWORDS(fw_info_location.size);
i++, addr += BYTES_IN_DWORD)
dest[i] = qed_rd(p_hwfn, p_ptt, addr);
}
}
static u32 qed_dump_str(char *dump_buf, bool dump, const char *str)
{
if (dump)
strcpy(dump_buf, str);
return (u32)strlen(str) + 1;
}
static u32 qed_dump_align(char *dump_buf, bool dump, u32 byte_offset)
{
u8 offset_in_dword = (u8)(byte_offset & 0x3), align_size;
align_size = offset_in_dword ? BYTES_IN_DWORD - offset_in_dword : 0;
if (dump && align_size)
memset(dump_buf, 0, align_size);
return align_size;
}
static u32 qed_dump_str_param(u32 *dump_buf,
bool dump,
const char *param_name, const char *param_val)
{
char *char_buf = (char *)dump_buf;
u32 offset = 0;
offset += qed_dump_str(char_buf + offset, dump, param_name);
if (dump)
*(char_buf + offset) = 1;
offset++;
offset += qed_dump_str(char_buf + offset, dump, param_val);
offset += qed_dump_align(char_buf + offset, dump, offset);
return BYTES_TO_DWORDS(offset);
}
static u32 qed_dump_num_param(u32 *dump_buf,
bool dump, const char *param_name, u32 param_val)
{
char *char_buf = (char *)dump_buf;
u32 offset = 0;
offset += qed_dump_str(char_buf + offset, dump, param_name);
if (dump)
*(char_buf + offset) = 0;
offset++;
offset += qed_dump_align(char_buf + offset, dump, offset);
offset = BYTES_TO_DWORDS(offset);
if (dump)
*(dump_buf + offset) = param_val;
offset++;
return offset;
}
static u32 qed_dump_fw_ver_param(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
char fw_ver_str[16] = EMPTY_FW_VERSION_STR;
char fw_img_str[16] = EMPTY_FW_IMAGE_STR;
struct fw_info fw_info = { {0}, {0} };
int printed_chars;
u32 offset = 0;
if (dump && !qed_grc_get_param(p_hwfn, DBG_GRC_PARAM_NO_FW_VER)) {
bool found = false;
u8 storm_id;
for (storm_id = 0; storm_id < MAX_DBG_STORMS && !found;
storm_id++) {
if (!dev_data->block_in_reset
[s_storm_defs[storm_id].block_id]) {
qed_read_fw_info(p_hwfn,
p_ptt, storm_id, &fw_info);
printed_chars =
snprintf(fw_ver_str,
sizeof(fw_ver_str),
"%d_%d_%d_%d",
fw_info.ver.num.major,
fw_info.ver.num.minor,
fw_info.ver.num.rev,
fw_info.ver.num.eng);
if (printed_chars < 0 || printed_chars >=
sizeof(fw_ver_str))
DP_NOTICE(p_hwfn,
"Unexpected debug error: invalid FW version string\n");
switch (fw_info.ver.image_id) {
case FW_IMG_MAIN:
strcpy(fw_img_str, "main");
break;
default:
strcpy(fw_img_str, "unknown");
break;
}
found = true;
}
}
}
offset += qed_dump_str_param(dump_buf + offset,
dump, "fw-version", fw_ver_str);
offset += qed_dump_str_param(dump_buf + offset,
dump, "fw-image", fw_img_str);
offset += qed_dump_num_param(dump_buf + offset,
dump,
"fw-timestamp", fw_info.ver.timestamp);
return offset;
}
static u32 qed_dump_mfw_ver_param(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump)
{
char mfw_ver_str[16] = EMPTY_FW_VERSION_STR;
if (dump && !qed_grc_get_param(p_hwfn, DBG_GRC_PARAM_NO_FW_VER)) {
u32 global_section_offsize, global_section_addr, mfw_ver;
u32 public_data_addr, global_section_offsize_addr;
int printed_chars;
public_data_addr = qed_rd(p_hwfn, p_ptt,
MISC_REG_SHARED_MEM_ADDR) |
MCP_REG_SCRATCH;
global_section_offsize_addr = public_data_addr +
offsetof(struct mcp_public_data,
sections) +
sizeof(offsize_t) * PUBLIC_GLOBAL;
global_section_offsize = qed_rd(p_hwfn, p_ptt,
global_section_offsize_addr);
global_section_addr = MCP_REG_SCRATCH +
(global_section_offsize &
OFFSIZE_OFFSET_MASK) * 4;
mfw_ver = qed_rd(p_hwfn, p_ptt,
global_section_addr +
offsetof(struct public_global, mfw_ver));
printed_chars = snprintf(mfw_ver_str, sizeof(mfw_ver_str),
"%d_%d_%d_%d",
(u8) (mfw_ver >> 24),
(u8) (mfw_ver >> 16),
(u8) (mfw_ver >> 8),
(u8) mfw_ver);
if (printed_chars < 0 || printed_chars >= sizeof(mfw_ver_str))
DP_NOTICE(p_hwfn,
"Unexpected debug error: invalid MFW version string\n");
}
return qed_dump_str_param(dump_buf, dump, "mfw-version", mfw_ver_str);
}
static u32 qed_dump_section_hdr(u32 *dump_buf,
bool dump, const char *name, u32 num_params)
{
return qed_dump_num_param(dump_buf, dump, name, num_params);
}
static u32 qed_dump_common_global_params(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump,
u8 num_specific_global_params)
{
u8 num_params = NUM_COMMON_GLOBAL_PARAMS + num_specific_global_params;
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 offset = 0;
offset += qed_dump_section_hdr(dump_buf + offset,
dump, "global_params", num_params);
offset += qed_dump_fw_ver_param(p_hwfn, p_ptt, dump_buf + offset, dump);
offset += qed_dump_mfw_ver_param(p_hwfn,
p_ptt, dump_buf + offset, dump);
offset += qed_dump_num_param(dump_buf + offset,
dump, "tools-version", TOOLS_VERSION);
offset += qed_dump_str_param(dump_buf + offset,
dump,
"chip",
s_chip_defs[dev_data->chip_id].name);
offset += qed_dump_str_param(dump_buf + offset,
dump,
"platform",
s_platform_defs[dev_data->platform_id].
name);
offset +=
qed_dump_num_param(dump_buf + offset, dump, "pci-func",
p_hwfn->abs_pf_id);
return offset;
}
static u32 qed_dump_last_section(u32 *dump_buf, u32 offset, bool dump)
{
u32 start_offset = offset, crc = ~0;
offset += qed_dump_section_hdr(dump_buf + offset, dump, "last", 0);
if (dump)
*(dump_buf + offset) = ~crc32(crc, (u8 *)dump_buf,
DWORDS_TO_BYTES(offset));
offset++;
return offset - start_offset;
}
static void qed_update_blocks_reset_state(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 reg_val[MAX_DBG_RESET_REGS] = { 0 };
u32 i;
for (i = 0; i < MAX_DBG_RESET_REGS; i++)
if (s_reset_regs_defs[i].exists[dev_data->chip_id])
reg_val[i] = qed_rd(p_hwfn,
p_ptt, s_reset_regs_defs[i].addr);
for (i = 0; i < MAX_BLOCK_ID; i++)
dev_data->block_in_reset[i] =
s_block_defs[i]->has_reset_bit &&
!(reg_val[s_block_defs[i]->reset_reg] &
BIT(s_block_defs[i]->reset_bit_offset));
}
static void qed_bus_enable_dbg_block(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, bool enable)
{
qed_wr(p_hwfn, p_ptt, DBG_REG_DBG_BLOCK_ON, enable ? 1 : 0);
}
static void qed_bus_reset_dbg_block(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
u32 dbg_reset_reg_addr, old_reset_reg_val, new_reset_reg_val;
dbg_reset_reg_addr =
s_reset_regs_defs[s_block_defs[BLOCK_DBG]->reset_reg].addr;
old_reset_reg_val = qed_rd(p_hwfn, p_ptt, dbg_reset_reg_addr);
new_reset_reg_val = old_reset_reg_val &
~BIT(s_block_defs[BLOCK_DBG]->reset_bit_offset);
qed_wr(p_hwfn, p_ptt, dbg_reset_reg_addr, new_reset_reg_val);
qed_wr(p_hwfn, p_ptt, dbg_reset_reg_addr, old_reset_reg_val);
}
static void qed_bus_set_framing_mode(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
enum dbg_bus_frame_modes mode)
{
qed_wr(p_hwfn, p_ptt, DBG_REG_FRAMING_MODE, (u8)mode);
}
static void qed_bus_enable_clients(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 client_mask)
{
qed_wr(p_hwfn, p_ptt, DBG_REG_CLIENT_ENABLE, client_mask);
}
static bool qed_is_mode_match(struct qed_hwfn *p_hwfn, u16 *modes_buf_offset)
{
const u32 *ptr = s_dbg_arrays[BIN_BUF_DBG_MODE_TREE].ptr;
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u8 tree_val = ((u8 *)ptr)[(*modes_buf_offset)++];
bool arg1, arg2;
switch (tree_val) {
case INIT_MODE_OP_NOT:
return !qed_is_mode_match(p_hwfn, modes_buf_offset);
case INIT_MODE_OP_OR:
case INIT_MODE_OP_AND:
arg1 = qed_is_mode_match(p_hwfn, modes_buf_offset);
arg2 = qed_is_mode_match(p_hwfn, modes_buf_offset);
return (tree_val == INIT_MODE_OP_OR) ? (arg1 ||
arg2) : (arg1 && arg2);
default:
return dev_data->mode_enable[tree_val - MAX_INIT_MODE_OPS] > 0;
}
}
static bool qed_grc_is_included(struct qed_hwfn *p_hwfn,
enum dbg_grc_params grc_param)
{
return qed_grc_get_param(p_hwfn, grc_param) > 0;
}
static bool qed_grc_is_storm_included(struct qed_hwfn *p_hwfn,
enum dbg_storms storm)
{
return qed_grc_get_param(p_hwfn, (enum dbg_grc_params)storm) > 0;
}
static bool qed_grc_is_mem_included(struct qed_hwfn *p_hwfn,
enum block_id block_id, u8 mem_group_id)
{
u8 i;
if (s_block_defs[block_id]->associated_to_storm &&
!qed_grc_is_storm_included(p_hwfn,
(enum dbg_storms)s_block_defs[block_id]->storm_id))
return false;
for (i = 0; i < NUM_BIG_RAM_TYPES; i++)
if (mem_group_id == s_big_ram_defs[i].mem_group_id ||
mem_group_id == s_big_ram_defs[i].ram_mem_group_id)
return qed_grc_is_included(p_hwfn,
s_big_ram_defs[i].grc_param);
if (mem_group_id == MEM_GROUP_PXP_ILT || mem_group_id ==
MEM_GROUP_PXP_MEM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_PXP);
if (mem_group_id == MEM_GROUP_RAM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_RAM);
if (mem_group_id == MEM_GROUP_PBUF)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_PBUF);
if (mem_group_id == MEM_GROUP_CAU_MEM ||
mem_group_id == MEM_GROUP_CAU_SB ||
mem_group_id == MEM_GROUP_CAU_PI)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_CAU);
if (mem_group_id == MEM_GROUP_QM_MEM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_QM);
if (mem_group_id == MEM_GROUP_CONN_CFC_MEM ||
mem_group_id == MEM_GROUP_TASK_CFC_MEM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_CFC);
if (mem_group_id == MEM_GROUP_IGU_MEM || mem_group_id ==
MEM_GROUP_IGU_MSIX)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_IGU);
if (mem_group_id == MEM_GROUP_MULD_MEM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_MULD);
if (mem_group_id == MEM_GROUP_PRS_MEM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_PRS);
if (mem_group_id == MEM_GROUP_DMAE_MEM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_DMAE);
if (mem_group_id == MEM_GROUP_TM_MEM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_TM);
if (mem_group_id == MEM_GROUP_SDM_MEM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_SDM);
if (mem_group_id == MEM_GROUP_TDIF_CTX || mem_group_id ==
MEM_GROUP_RDIF_CTX)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_DIF);
if (mem_group_id == MEM_GROUP_CM_MEM)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_CM);
if (mem_group_id == MEM_GROUP_IOR)
return qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_IOR);
return true;
}
static void qed_grc_stall_storms(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, bool stall)
{
u8 reg_val = stall ? 1 : 0;
u8 storm_id;
for (storm_id = 0; storm_id < MAX_DBG_STORMS; storm_id++) {
if (qed_grc_is_storm_included(p_hwfn,
(enum dbg_storms)storm_id)) {
u32 reg_addr =
s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_STALL_0;
qed_wr(p_hwfn, p_ptt, reg_addr, reg_val);
}
}
msleep(STALL_DELAY_MS);
}
static void qed_grc_unreset_blocks(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 reg_val[MAX_DBG_RESET_REGS] = { 0 };
u32 i;
for (i = 0; i < MAX_BLOCK_ID; i++)
if (s_block_defs[i]->has_reset_bit && s_block_defs[i]->unreset)
reg_val[s_block_defs[i]->reset_reg] |=
BIT(s_block_defs[i]->reset_bit_offset);
for (i = 0; i < MAX_DBG_RESET_REGS; i++) {
if (s_reset_regs_defs[i].exists[dev_data->chip_id]) {
reg_val[i] |= s_reset_regs_defs[i].unreset_val;
if (reg_val[i])
qed_wr(p_hwfn,
p_ptt,
s_reset_regs_defs[i].addr +
RESET_REG_UNRESET_OFFSET, reg_val[i]);
}
}
}
static const struct dbg_attn_block_type_data *
qed_get_block_attn_data(enum block_id block_id, enum dbg_attn_type attn_type)
{
const struct dbg_attn_block *base_attn_block_arr =
(const struct dbg_attn_block *)
s_dbg_arrays[BIN_BUF_DBG_ATTN_BLOCKS].ptr;
return &base_attn_block_arr[block_id].per_type_data[attn_type];
}
static const struct dbg_attn_reg *
qed_get_block_attn_regs(enum block_id block_id, enum dbg_attn_type attn_type,
u8 *num_attn_regs)
{
const struct dbg_attn_block_type_data *block_type_data =
qed_get_block_attn_data(block_id, attn_type);
*num_attn_regs = block_type_data->num_regs;
return &((const struct dbg_attn_reg *)
s_dbg_arrays[BIN_BUF_DBG_ATTN_REGS].ptr)[block_type_data->
regs_offset];
}
static void qed_grc_clear_all_prty(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u8 reg_idx, num_attn_regs;
u32 block_id;
for (block_id = 0; block_id < MAX_BLOCK_ID; block_id++) {
const struct dbg_attn_reg *attn_reg_arr;
if (dev_data->block_in_reset[block_id])
continue;
attn_reg_arr = qed_get_block_attn_regs((enum block_id)block_id,
ATTN_TYPE_PARITY,
&num_attn_regs);
for (reg_idx = 0; reg_idx < num_attn_regs; reg_idx++) {
const struct dbg_attn_reg *reg_data =
&attn_reg_arr[reg_idx];
bool eval_mode = GET_FIELD(reg_data->mode.data,
DBG_MODE_HDR_EVAL_MODE) > 0;
u16 modes_buf_offset =
GET_FIELD(reg_data->mode.data,
DBG_MODE_HDR_MODES_BUF_OFFSET);
if (!eval_mode ||
qed_is_mode_match(p_hwfn, &modes_buf_offset))
qed_rd(p_hwfn, p_ptt,
DWORDS_TO_BYTES(reg_data->
sts_clr_address));
}
}
}
static u32 qed_grc_dump_regs_hdr(u32 *dump_buf,
bool dump,
u32 num_reg_entries,
const char *split_type,
int split_id,
const char *param_name, const char *param_val)
{
u8 num_params = 2 + (split_id >= 0 ? 1 : 0) + (param_name ? 1 : 0);
u32 offset = 0;
offset += qed_dump_section_hdr(dump_buf + offset,
dump, "grc_regs", num_params);
offset += qed_dump_num_param(dump_buf + offset,
dump, "count", num_reg_entries);
offset += qed_dump_str_param(dump_buf + offset,
dump, "split", split_type);
if (split_id >= 0)
offset += qed_dump_num_param(dump_buf + offset,
dump, "id", split_id);
if (param_name && param_val)
offset += qed_dump_str_param(dump_buf + offset,
dump, param_name, param_val);
return offset;
}
static u32 qed_grc_dump_addr_range(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf,
bool dump, u32 addr, u32 len)
{
u32 byte_addr = DWORDS_TO_BYTES(addr), offset = 0, i;
if (dump)
for (i = 0; i < len; i++, byte_addr += BYTES_IN_DWORD, offset++)
*(dump_buf + offset) = qed_rd(p_hwfn, p_ptt, byte_addr);
else
offset += len;
return offset;
}
static u32 qed_grc_dump_reg_entry_hdr(u32 *dump_buf, bool dump, u32 addr,
u32 len)
{
if (dump)
*dump_buf = addr | (len << REG_DUMP_LEN_SHIFT);
return 1;
}
static u32 qed_grc_dump_reg_entry(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf,
bool dump, u32 addr, u32 len)
{
u32 offset = 0;
offset += qed_grc_dump_reg_entry_hdr(dump_buf, dump, addr, len);
offset += qed_grc_dump_addr_range(p_hwfn,
p_ptt,
dump_buf + offset, dump, addr, len);
return offset;
}
static u32 qed_grc_dump_reg_entry_skip(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf,
bool dump, u32 addr, u32 total_len,
u32 read_len, u32 skip_len)
{
u32 offset = 0, reg_offset = 0;
offset += qed_grc_dump_reg_entry_hdr(dump_buf, dump, addr, total_len);
if (dump) {
while (reg_offset < total_len) {
u32 curr_len = min_t(u32,
read_len,
total_len - reg_offset);
offset += qed_grc_dump_addr_range(p_hwfn,
p_ptt,
dump_buf + offset,
dump, addr, curr_len);
reg_offset += curr_len;
addr += curr_len;
if (reg_offset < total_len) {
curr_len = min_t(u32,
skip_len,
total_len - skip_len);
memset(dump_buf + offset, 0,
DWORDS_TO_BYTES(curr_len));
offset += curr_len;
reg_offset += curr_len;
addr += curr_len;
}
}
} else {
offset += total_len;
}
return offset;
}
static u32 qed_grc_dump_regs_entries(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct dbg_array input_regs_arr,
u32 *dump_buf,
bool dump,
bool block_enable[MAX_BLOCK_ID],
u32 *num_dumped_reg_entries)
{
u32 i, offset = 0, input_offset = 0;
bool mode_match = true;
*num_dumped_reg_entries = 0;
while (input_offset < input_regs_arr.size_in_dwords) {
const struct dbg_dump_cond_hdr *cond_hdr =
(const struct dbg_dump_cond_hdr *)
&input_regs_arr.ptr[input_offset++];
bool eval_mode = GET_FIELD(cond_hdr->mode.data,
DBG_MODE_HDR_EVAL_MODE) > 0;
if (eval_mode) {
u16 modes_buf_offset =
GET_FIELD(cond_hdr->mode.data,
DBG_MODE_HDR_MODES_BUF_OFFSET);
mode_match = qed_is_mode_match(p_hwfn,
&modes_buf_offset);
}
if (mode_match && block_enable[cond_hdr->block_id]) {
for (i = 0; i < cond_hdr->data_size;
i++, input_offset++) {
const struct dbg_dump_reg *reg =
(const struct dbg_dump_reg *)
&input_regs_arr.ptr[input_offset];
u32 addr, len;
addr = GET_FIELD(reg->data,
DBG_DUMP_REG_ADDRESS);
len = GET_FIELD(reg->data, DBG_DUMP_REG_LENGTH);
offset +=
qed_grc_dump_reg_entry(p_hwfn, p_ptt,
dump_buf + offset,
dump,
addr,
len);
(*num_dumped_reg_entries)++;
}
} else {
input_offset += cond_hdr->data_size;
}
}
return offset;
}
static u32 qed_grc_dump_split_data(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct dbg_array input_regs_arr,
u32 *dump_buf,
bool dump,
bool block_enable[MAX_BLOCK_ID],
const char *split_type_name,
u32 split_id,
const char *param_name,
const char *param_val)
{
u32 num_dumped_reg_entries, offset;
offset = qed_grc_dump_regs_hdr(dump_buf,
false,
0,
split_type_name,
split_id, param_name, param_val);
offset += qed_grc_dump_regs_entries(p_hwfn,
p_ptt,
input_regs_arr,
dump_buf + offset,
dump,
block_enable,
&num_dumped_reg_entries);
if (dump && num_dumped_reg_entries > 0)
qed_grc_dump_regs_hdr(dump_buf,
dump,
num_dumped_reg_entries,
split_type_name,
split_id, param_name, param_val);
return num_dumped_reg_entries > 0 ? offset : 0;
}
static u32 qed_grc_dump_registers(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump,
bool block_enable[MAX_BLOCK_ID],
const char *param_name, const char *param_val)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
struct chip_platform_defs *p_platform_defs;
u32 offset = 0, input_offset = 0;
struct chip_defs *p_chip_defs;
u8 port_id, pf_id, vf_id;
u16 fid;
p_chip_defs = &s_chip_defs[dev_data->chip_id];
p_platform_defs = &p_chip_defs->per_platform[dev_data->platform_id];
if (dump)
DP_VERBOSE(p_hwfn, QED_MSG_DEBUG, "Dumping registers...\n");
while (input_offset <
s_dbg_arrays[BIN_BUF_DBG_DUMP_REG].size_in_dwords) {
const struct dbg_dump_split_hdr *split_hdr =
(const struct dbg_dump_split_hdr *)
&s_dbg_arrays[BIN_BUF_DBG_DUMP_REG].ptr[input_offset++];
u8 split_type_id = GET_FIELD(split_hdr->hdr,
DBG_DUMP_SPLIT_HDR_SPLIT_TYPE_ID);
u32 split_data_size = GET_FIELD(split_hdr->hdr,
DBG_DUMP_SPLIT_HDR_DATA_SIZE);
struct dbg_array curr_input_regs_arr = {
&s_dbg_arrays[BIN_BUF_DBG_DUMP_REG].ptr[input_offset],
split_data_size};
switch (split_type_id) {
case SPLIT_TYPE_NONE:
offset += qed_grc_dump_split_data(p_hwfn,
p_ptt,
curr_input_regs_arr,
dump_buf + offset,
dump,
block_enable,
"eng",
(u32)(-1),
param_name,
param_val);
break;
case SPLIT_TYPE_PORT:
for (port_id = 0; port_id < p_platform_defs->num_ports;
port_id++) {
if (dump)
qed_port_pretend(p_hwfn, p_ptt,
port_id);
offset +=
qed_grc_dump_split_data(p_hwfn, p_ptt,
curr_input_regs_arr,
dump_buf + offset,
dump, block_enable,
"port", port_id,
param_name,
param_val);
}
break;
case SPLIT_TYPE_PF:
case SPLIT_TYPE_PORT_PF:
for (pf_id = 0; pf_id < p_platform_defs->num_pfs;
pf_id++) {
u8 pfid_shift =
PXP_PRETEND_CONCRETE_FID_PFID_SHIFT;
if (dump) {
fid = pf_id << pfid_shift;
qed_fid_pretend(p_hwfn, p_ptt, fid);
}
offset +=
qed_grc_dump_split_data(p_hwfn, p_ptt,
curr_input_regs_arr,
dump_buf + offset,
dump, block_enable,
"pf", pf_id,
param_name,
param_val);
}
break;
case SPLIT_TYPE_VF:
for (vf_id = 0; vf_id < p_platform_defs->num_vfs;
vf_id++) {
u8 vfvalid_shift =
PXP_PRETEND_CONCRETE_FID_VFVALID_SHIFT;
u8 vfid_shift =
PXP_PRETEND_CONCRETE_FID_VFID_SHIFT;
if (dump) {
fid = BIT(vfvalid_shift) |
(vf_id << vfid_shift);
qed_fid_pretend(p_hwfn, p_ptt, fid);
}
offset +=
qed_grc_dump_split_data(p_hwfn, p_ptt,
curr_input_regs_arr,
dump_buf + offset,
dump, block_enable,
"vf", vf_id,
param_name,
param_val);
}
break;
default:
break;
}
input_offset += split_data_size;
}
if (dump) {
fid = p_hwfn->rel_pf_id << PXP_PRETEND_CONCRETE_FID_PFID_SHIFT;
qed_fid_pretend(p_hwfn, p_ptt, fid);
}
return offset;
}
static u32 qed_grc_dump_reset_regs(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 i, offset = 0, num_regs = 0;
offset += qed_grc_dump_regs_hdr(dump_buf,
false, 0, "eng", -1, NULL, NULL);
for (i = 0; i < MAX_DBG_RESET_REGS; i++) {
if (s_reset_regs_defs[i].exists[dev_data->chip_id]) {
u32 addr = BYTES_TO_DWORDS(s_reset_regs_defs[i].addr);
offset += qed_grc_dump_reg_entry(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
1);
num_regs++;
}
}
if (dump)
qed_grc_dump_regs_hdr(dump_buf,
true, num_regs, "eng", -1, NULL, NULL);
return offset;
}
static u32 qed_grc_dump_modified_regs(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 offset = 0, num_reg_entries = 0, block_id;
u8 storm_id, reg_idx, num_attn_regs;
offset += qed_grc_dump_regs_hdr(dump_buf,
false, 0, "eng", -1, NULL, NULL);
for (block_id = 0; block_id < MAX_BLOCK_ID; block_id++) {
const struct dbg_attn_reg *attn_reg_arr;
if (dev_data->block_in_reset[block_id] && dump)
continue;
attn_reg_arr = qed_get_block_attn_regs((enum block_id)block_id,
ATTN_TYPE_PARITY,
&num_attn_regs);
for (reg_idx = 0; reg_idx < num_attn_regs; reg_idx++) {
const struct dbg_attn_reg *reg_data =
&attn_reg_arr[reg_idx];
u16 modes_buf_offset;
bool eval_mode;
u32 addr;
eval_mode = GET_FIELD(reg_data->mode.data,
DBG_MODE_HDR_EVAL_MODE) > 0;
modes_buf_offset =
GET_FIELD(reg_data->mode.data,
DBG_MODE_HDR_MODES_BUF_OFFSET);
if (!eval_mode ||
qed_is_mode_match(p_hwfn, &modes_buf_offset)) {
addr = reg_data->mask_address;
offset +=
qed_grc_dump_reg_entry(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
1);
addr = GET_FIELD(reg_data->data,
DBG_ATTN_REG_STS_ADDRESS);
offset +=
qed_grc_dump_reg_entry(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
1);
num_reg_entries += 2;
}
}
}
for (storm_id = 0; storm_id < MAX_DBG_STORMS; storm_id++) {
u32 addr;
if (dev_data->block_in_reset[s_storm_defs[storm_id].block_id] &&
dump)
continue;
addr =
BYTES_TO_DWORDS(s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_STALLED);
offset += qed_grc_dump_reg_entry(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
1);
num_reg_entries++;
}
if (dump)
qed_grc_dump_regs_hdr(dump_buf,
true,
num_reg_entries, "eng", -1, NULL, NULL);
return offset;
}
static u32 qed_grc_dump_special_regs(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump)
{
u32 offset = 0, addr;
offset += qed_grc_dump_regs_hdr(dump_buf,
dump, 2, "eng", -1, NULL, NULL);
addr = BYTES_TO_DWORDS(RDIF_REG_DEBUG_ERROR_INFO);
offset += qed_grc_dump_reg_entry_skip(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
RDIF_REG_DEBUG_ERROR_INFO_SIZE,
7,
1);
addr = BYTES_TO_DWORDS(TDIF_REG_DEBUG_ERROR_INFO);
offset +=
qed_grc_dump_reg_entry_skip(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
TDIF_REG_DEBUG_ERROR_INFO_SIZE,
7,
1);
return offset;
}
static u32 qed_grc_dump_mem_hdr(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
bool dump,
const char *name,
u32 addr,
u32 len,
u32 bit_width,
bool packed,
const char *mem_group,
bool is_storm, char storm_letter)
{
u8 num_params = 3;
u32 offset = 0;
char buf[64];
if (!len)
DP_NOTICE(p_hwfn,
"Unexpected GRC Dump error: dumped memory size must be non-zero\n");
if (bit_width)
num_params++;
if (packed)
num_params++;
offset += qed_dump_section_hdr(dump_buf + offset,
dump, "grc_mem", num_params);
if (name) {
if (is_storm) {
strcpy(buf, "?STORM_");
buf[0] = storm_letter;
strcpy(buf + strlen(buf), name);
} else {
strcpy(buf, name);
}
offset += qed_dump_str_param(dump_buf + offset,
dump, "name", buf);
if (dump)
DP_VERBOSE(p_hwfn,
QED_MSG_DEBUG,
"Dumping %d registers from %s...\n",
len, buf);
} else {
offset += qed_dump_num_param(dump_buf + offset,
dump, "addr",
DWORDS_TO_BYTES(addr));
if (dump && len > 64)
DP_VERBOSE(p_hwfn,
QED_MSG_DEBUG,
"Dumping %d registers from address 0x%x...\n",
len, (u32)DWORDS_TO_BYTES(addr));
}
offset += qed_dump_num_param(dump_buf + offset, dump, "len", len);
if (bit_width)
offset += qed_dump_num_param(dump_buf + offset,
dump, "width", bit_width);
if (packed)
offset += qed_dump_num_param(dump_buf + offset,
dump, "packed", 1);
if (is_storm) {
strcpy(buf, "?STORM_");
buf[0] = storm_letter;
strcpy(buf + strlen(buf), mem_group);
} else {
strcpy(buf, mem_group);
}
offset += qed_dump_str_param(dump_buf + offset, dump, "type", buf);
return offset;
}
static u32 qed_grc_dump_mem(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump,
const char *name,
u32 addr,
u32 len,
u32 bit_width,
bool packed,
const char *mem_group,
bool is_storm, char storm_letter)
{
u32 offset = 0;
offset += qed_grc_dump_mem_hdr(p_hwfn,
dump_buf + offset,
dump,
name,
addr,
len,
bit_width,
packed,
mem_group, is_storm, storm_letter);
offset += qed_grc_dump_addr_range(p_hwfn,
p_ptt,
dump_buf + offset, dump, addr, len);
return offset;
}
static u32 qed_grc_dump_mem_entries(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
struct dbg_array input_mems_arr,
u32 *dump_buf, bool dump)
{
u32 i, offset = 0, input_offset = 0;
bool mode_match = true;
while (input_offset < input_mems_arr.size_in_dwords) {
const struct dbg_dump_cond_hdr *cond_hdr;
u32 num_entries;
bool eval_mode;
cond_hdr = (const struct dbg_dump_cond_hdr *)
&input_mems_arr.ptr[input_offset++];
eval_mode = GET_FIELD(cond_hdr->mode.data,
DBG_MODE_HDR_EVAL_MODE) > 0;
if (eval_mode) {
u16 modes_buf_offset =
GET_FIELD(cond_hdr->mode.data,
DBG_MODE_HDR_MODES_BUF_OFFSET);
mode_match = qed_is_mode_match(p_hwfn,
&modes_buf_offset);
}
if (!mode_match) {
input_offset += cond_hdr->data_size;
continue;
}
num_entries = cond_hdr->data_size / MEM_DUMP_ENTRY_SIZE_DWORDS;
for (i = 0; i < num_entries;
i++, input_offset += MEM_DUMP_ENTRY_SIZE_DWORDS) {
const struct dbg_dump_mem *mem =
(const struct dbg_dump_mem *)
&input_mems_arr.ptr[input_offset];
u8 mem_group_id;
mem_group_id = GET_FIELD(mem->dword0,
DBG_DUMP_MEM_MEM_GROUP_ID);
if (mem_group_id >= MEM_GROUPS_NUM) {
DP_NOTICE(p_hwfn, "Invalid mem_group_id\n");
return 0;
}
if (qed_grc_is_mem_included(p_hwfn,
(enum block_id)cond_hdr->block_id,
mem_group_id)) {
u32 mem_addr = GET_FIELD(mem->dword0,
DBG_DUMP_MEM_ADDRESS);
u32 mem_len = GET_FIELD(mem->dword1,
DBG_DUMP_MEM_LENGTH);
enum dbg_grc_params grc_param;
char storm_letter = 'a';
bool is_storm = false;
if (mem_group_id == MEM_GROUP_CONN_CFC_MEM) {
if (mem_len % MAX_LCIDS != 0) {
DP_NOTICE(p_hwfn,
"Invalid CCFC connection memory size\n");
return 0;
}
grc_param = DBG_GRC_PARAM_NUM_LCIDS;
mem_len = qed_grc_get_param(p_hwfn,
grc_param) *
(mem_len / MAX_LCIDS);
} else if (mem_group_id ==
MEM_GROUP_TASK_CFC_MEM) {
if (mem_len % MAX_LTIDS != 0) {
DP_NOTICE(p_hwfn,
"Invalid TCFC task memory size\n");
return 0;
}
grc_param = DBG_GRC_PARAM_NUM_LTIDS;
mem_len = qed_grc_get_param(p_hwfn,
grc_param) *
(mem_len / MAX_LTIDS);
}
if (s_block_defs[cond_hdr->block_id]->
associated_to_storm) {
is_storm = true;
storm_letter =
s_storm_defs[s_block_defs[
cond_hdr->block_id]->
storm_id].letter;
}
offset += qed_grc_dump_mem(p_hwfn, p_ptt,
dump_buf + offset, dump, NULL,
mem_addr, mem_len, 0,
false,
s_mem_group_names[mem_group_id],
is_storm, storm_letter);
}
}
}
return offset;
}
static u32 qed_grc_dump_memories(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump)
{
u32 offset = 0, input_offset = 0;
while (input_offset <
s_dbg_arrays[BIN_BUF_DBG_DUMP_MEM].size_in_dwords) {
const struct dbg_dump_split_hdr *split_hdr =
(const struct dbg_dump_split_hdr *)
&s_dbg_arrays[BIN_BUF_DBG_DUMP_MEM].ptr[input_offset++];
u8 split_type_id = GET_FIELD(split_hdr->hdr,
DBG_DUMP_SPLIT_HDR_SPLIT_TYPE_ID);
u32 split_data_size = GET_FIELD(split_hdr->hdr,
DBG_DUMP_SPLIT_HDR_DATA_SIZE);
struct dbg_array curr_input_mems_arr = {
&s_dbg_arrays[BIN_BUF_DBG_DUMP_MEM].ptr[input_offset],
split_data_size};
switch (split_type_id) {
case SPLIT_TYPE_NONE:
offset += qed_grc_dump_mem_entries(p_hwfn,
p_ptt,
curr_input_mems_arr,
dump_buf + offset,
dump);
break;
default:
DP_NOTICE(p_hwfn,
"Dumping split memories is currently not supported\n");
break;
}
input_offset += split_data_size;
}
return offset;
}
static u32 qed_grc_dump_ctx_data(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump,
const char *name,
u32 num_lids,
u32 lid_size,
u32 rd_reg_addr,
u8 storm_id)
{
u32 i, lid, total_size;
u32 offset = 0;
if (!lid_size)
return 0;
lid_size *= BYTES_IN_DWORD;
total_size = num_lids * lid_size;
offset += qed_grc_dump_mem_hdr(p_hwfn,
dump_buf + offset,
dump,
name,
0,
total_size,
lid_size * 32,
false,
name,
true, s_storm_defs[storm_id].letter);
if (dump) {
for (lid = 0; lid < num_lids; lid++) {
for (i = 0; i < lid_size; i++, offset++) {
qed_wr(p_hwfn,
p_ptt,
s_storm_defs[storm_id].cm_ctx_wr_addr,
(i << 9) | lid);
*(dump_buf + offset) = qed_rd(p_hwfn,
p_ptt,
rd_reg_addr);
}
}
} else {
offset += total_size;
}
return offset;
}
static u32 qed_grc_dump_ctx(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf, bool dump)
{
u32 offset = 0;
u8 storm_id;
for (storm_id = 0; storm_id < MAX_DBG_STORMS; storm_id++) {
if (!qed_grc_is_storm_included(p_hwfn,
(enum dbg_storms)storm_id))
continue;
offset +=
qed_grc_dump_ctx_data(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
"CONN_AG_CTX",
qed_grc_get_param(p_hwfn,
DBG_GRC_PARAM_NUM_LCIDS),
s_storm_defs[storm_id].
cm_conn_ag_ctx_lid_size,
s_storm_defs[storm_id].
cm_conn_ag_ctx_rd_addr,
storm_id);
offset +=
qed_grc_dump_ctx_data(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
"CONN_ST_CTX",
qed_grc_get_param(p_hwfn,
DBG_GRC_PARAM_NUM_LCIDS),
s_storm_defs[storm_id].
cm_conn_st_ctx_lid_size,
s_storm_defs[storm_id].
cm_conn_st_ctx_rd_addr,
storm_id);
offset +=
qed_grc_dump_ctx_data(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
"TASK_AG_CTX",
qed_grc_get_param(p_hwfn,
DBG_GRC_PARAM_NUM_LTIDS),
s_storm_defs[storm_id].
cm_task_ag_ctx_lid_size,
s_storm_defs[storm_id].
cm_task_ag_ctx_rd_addr,
storm_id);
offset +=
qed_grc_dump_ctx_data(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
"TASK_ST_CTX",
qed_grc_get_param(p_hwfn,
DBG_GRC_PARAM_NUM_LTIDS),
s_storm_defs[storm_id].
cm_task_st_ctx_lid_size,
s_storm_defs[storm_id].
cm_task_st_ctx_rd_addr,
storm_id);
}
return offset;
}
static u32 qed_grc_dump_iors(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf, bool dump)
{
char buf[10] = "IOR_SET_?";
u8 storm_id, set_id;
u32 offset = 0;
for (storm_id = 0; storm_id < MAX_DBG_STORMS; storm_id++) {
struct storm_defs *storm = &s_storm_defs[storm_id];
if (!qed_grc_is_storm_included(p_hwfn,
(enum dbg_storms)storm_id))
continue;
for (set_id = 0; set_id < NUM_IOR_SETS; set_id++) {
u32 dwords, addr;
dwords = storm->sem_fast_mem_addr +
SEM_FAST_REG_STORM_REG_FILE;
addr = BYTES_TO_DWORDS(dwords) + IOR_SET_OFFSET(set_id);
buf[strlen(buf) - 1] = '0' + set_id;
offset += qed_grc_dump_mem(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
buf,
addr,
IORS_PER_SET,
32,
false,
"ior",
true,
storm->letter);
}
}
return offset;
}
static u32 qed_grc_dump_vfc_cam(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump, u8 storm_id)
{
u32 total_size = VFC_CAM_NUM_ROWS * VFC_CAM_RESP_DWORDS;
u32 cam_addr[VFC_CAM_ADDR_DWORDS] = { 0 };
u32 cam_cmd[VFC_CAM_CMD_DWORDS] = { 0 };
u32 offset = 0;
u32 row, i;
offset += qed_grc_dump_mem_hdr(p_hwfn,
dump_buf + offset,
dump,
"vfc_cam",
0,
total_size,
256,
false,
"vfc_cam",
true, s_storm_defs[storm_id].letter);
if (dump) {
SET_VAR_FIELD(cam_addr, VFC_CAM_ADDR, OP, VFC_OPCODE_CAM_RD);
for (row = 0; row < VFC_CAM_NUM_ROWS;
row++, offset += VFC_CAM_RESP_DWORDS) {
SET_VAR_FIELD(cam_cmd, VFC_CAM_CMD, ROW, row);
ARR_REG_WR(p_hwfn,
p_ptt,
s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_VFC_DATA_WR,
cam_cmd, VFC_CAM_CMD_DWORDS);
ARR_REG_WR(p_hwfn,
p_ptt,
s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_VFC_ADDR,
cam_addr, VFC_CAM_ADDR_DWORDS);
ARR_REG_RD(p_hwfn,
p_ptt,
s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_VFC_DATA_RD,
dump_buf + offset, VFC_CAM_RESP_DWORDS);
}
} else {
offset += total_size;
}
return offset;
}
static u32 qed_grc_dump_vfc_ram(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump,
u8 storm_id, struct vfc_ram_defs *ram_defs)
{
u32 total_size = ram_defs->num_rows * VFC_RAM_RESP_DWORDS;
u32 ram_addr[VFC_RAM_ADDR_DWORDS] = { 0 };
u32 ram_cmd[VFC_RAM_CMD_DWORDS] = { 0 };
u32 offset = 0;
u32 row, i;
offset += qed_grc_dump_mem_hdr(p_hwfn,
dump_buf + offset,
dump,
ram_defs->mem_name,
0,
total_size,
256,
false,
ram_defs->type_name,
true, s_storm_defs[storm_id].letter);
SET_VAR_FIELD(ram_addr, VFC_RAM_ADDR, OP, VFC_OPCODE_RAM_RD);
if (!dump)
return offset + total_size;
for (row = ram_defs->base_row;
row < ram_defs->base_row + ram_defs->num_rows;
row++, offset += VFC_RAM_RESP_DWORDS) {
ARR_REG_WR(p_hwfn,
p_ptt,
s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_VFC_DATA_WR,
ram_cmd, VFC_RAM_CMD_DWORDS);
SET_VAR_FIELD(ram_addr, VFC_RAM_ADDR, ROW, row);
ARR_REG_WR(p_hwfn,
p_ptt,
s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_VFC_ADDR,
ram_addr, VFC_RAM_ADDR_DWORDS);
ARR_REG_RD(p_hwfn,
p_ptt,
s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_VFC_DATA_RD,
dump_buf + offset, VFC_RAM_RESP_DWORDS);
}
return offset;
}
static u32 qed_grc_dump_vfc(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf, bool dump)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u8 storm_id, i;
u32 offset = 0;
for (storm_id = 0; storm_id < MAX_DBG_STORMS; storm_id++) {
if (qed_grc_is_storm_included(p_hwfn,
(enum dbg_storms)storm_id) &&
s_storm_defs[storm_id].has_vfc &&
(storm_id != DBG_PSTORM_ID ||
dev_data->platform_id == PLATFORM_ASIC)) {
offset += qed_grc_dump_vfc_cam(p_hwfn,
p_ptt,
dump_buf + offset,
dump, storm_id);
for (i = 0; i < NUM_VFC_RAM_TYPES; i++)
offset += qed_grc_dump_vfc_ram(p_hwfn,
p_ptt,
dump_buf +
offset,
dump,
storm_id,
&s_vfc_ram_defs
[i]);
}
}
return offset;
}
static u32 qed_grc_dump_rss(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf, bool dump)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 offset = 0;
u8 rss_mem_id;
for (rss_mem_id = 0; rss_mem_id < NUM_RSS_MEM_TYPES; rss_mem_id++) {
struct rss_mem_defs *rss_defs = &s_rss_mem_defs[rss_mem_id];
u32 num_entries = rss_defs->num_entries[dev_data->chip_id];
u32 entry_width = rss_defs->entry_width[dev_data->chip_id];
u32 total_dwords = (num_entries * entry_width) / 32;
u32 size = RSS_REG_RSS_RAM_DATA_SIZE;
bool packed = (entry_width == 16);
u32 rss_addr = rss_defs->addr;
u32 i, addr;
offset += qed_grc_dump_mem_hdr(p_hwfn,
dump_buf + offset,
dump,
rss_defs->mem_name,
0,
total_dwords,
entry_width,
packed,
rss_defs->type_name, false, 0);
if (!dump) {
offset += total_dwords;
continue;
}
for (i = 0; i < total_dwords;
i += RSS_REG_RSS_RAM_DATA_SIZE, rss_addr++) {
addr = BYTES_TO_DWORDS(RSS_REG_RSS_RAM_DATA);
qed_wr(p_hwfn, p_ptt, RSS_REG_RSS_RAM_ADDR, rss_addr);
offset += qed_grc_dump_addr_range(p_hwfn,
p_ptt,
dump_buf +
offset,
dump,
addr,
size);
}
}
return offset;
}
static u32 qed_grc_dump_big_ram(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump, u8 big_ram_id)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 total_blocks, ram_size, offset = 0, i;
char mem_name[12] = "???_BIG_RAM";
char type_name[8] = "???_RAM";
struct big_ram_defs *big_ram;
big_ram = &s_big_ram_defs[big_ram_id];
total_blocks = big_ram->num_of_blocks[dev_data->chip_id];
ram_size = total_blocks * BIG_RAM_BLOCK_SIZE_DWORDS;
strncpy(type_name, big_ram->instance_name,
strlen(big_ram->instance_name));
strncpy(mem_name, big_ram->instance_name,
strlen(big_ram->instance_name));
offset += qed_grc_dump_mem_hdr(p_hwfn,
dump_buf + offset,
dump,
mem_name,
0,
ram_size,
BIG_RAM_BLOCK_SIZE_BYTES * 8,
false, type_name, false, 0);
if (!dump)
return offset + ram_size;
for (i = 0; i < total_blocks / 2; i++) {
u32 addr, len;
qed_wr(p_hwfn, p_ptt, big_ram->addr_reg_addr, i);
addr = BYTES_TO_DWORDS(big_ram->data_reg_addr);
len = 2 * BIG_RAM_BLOCK_SIZE_DWORDS;
offset += qed_grc_dump_addr_range(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
len);
}
return offset;
}
static u32 qed_grc_dump_mcp(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf, bool dump)
{
bool block_enable[MAX_BLOCK_ID] = { 0 };
u32 offset = 0, addr;
bool halted = false;
if (dump && !qed_grc_get_param(p_hwfn, DBG_GRC_PARAM_NO_MCP)) {
halted = !qed_mcp_halt(p_hwfn, p_ptt);
if (!halted)
DP_NOTICE(p_hwfn, "MCP halt failed!\n");
}
offset += qed_grc_dump_mem(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
NULL,
BYTES_TO_DWORDS(MCP_REG_SCRATCH),
MCP_REG_SCRATCH_SIZE,
0, false, "MCP", false, 0);
offset += qed_grc_dump_mem(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
NULL,
BYTES_TO_DWORDS(MCP_REG_CPU_REG_FILE),
MCP_REG_CPU_REG_FILE_SIZE,
0, false, "MCP", false, 0);
block_enable[BLOCK_MCP] = true;
offset += qed_grc_dump_registers(p_hwfn,
p_ptt,
dump_buf + offset,
dump, block_enable, "block", "MCP");
offset += qed_grc_dump_regs_hdr(dump_buf + offset,
dump, 1, "eng", -1, "block", "MCP");
addr = BYTES_TO_DWORDS(MISC_REG_SHARED_MEM_ADDR);
offset += qed_grc_dump_reg_entry(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
1);
if (halted && qed_mcp_resume(p_hwfn, p_ptt))
DP_NOTICE(p_hwfn, "Failed to resume MCP after halt!\n");
return offset;
}
static u32 qed_grc_dump_phy(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf, bool dump)
{
u32 offset = 0, tbus_lo_offset, tbus_hi_offset;
char mem_name[32];
u8 phy_id;
for (phy_id = 0; phy_id < ARRAY_SIZE(s_phy_defs); phy_id++) {
struct phy_defs *phy_defs = &s_phy_defs[phy_id];
int printed_chars;
printed_chars = snprintf(mem_name, sizeof(mem_name), "tbus_%s",
phy_defs->phy_name);
if (printed_chars < 0 || printed_chars >= sizeof(mem_name))
DP_NOTICE(p_hwfn,
"Unexpected debug error: invalid PHY memory name\n");
offset += qed_grc_dump_mem_hdr(p_hwfn,
dump_buf + offset,
dump,
mem_name,
0,
PHY_DUMP_SIZE_DWORDS,
16, true, mem_name, false, 0);
if (dump) {
u32 addr_lo_addr = phy_defs->base_addr +
phy_defs->tbus_addr_lo_addr;
u32 addr_hi_addr = phy_defs->base_addr +
phy_defs->tbus_addr_hi_addr;
u32 data_lo_addr = phy_defs->base_addr +
phy_defs->tbus_data_lo_addr;
u32 data_hi_addr = phy_defs->base_addr +
phy_defs->tbus_data_hi_addr;
u8 *bytes_buf = (u8 *)(dump_buf + offset);
for (tbus_hi_offset = 0;
tbus_hi_offset < (NUM_PHY_TBUS_ADDRESSES >> 8);
tbus_hi_offset++) {
qed_wr(p_hwfn,
p_ptt, addr_hi_addr, tbus_hi_offset);
for (tbus_lo_offset = 0; tbus_lo_offset < 256;
tbus_lo_offset++) {
qed_wr(p_hwfn,
p_ptt,
addr_lo_addr, tbus_lo_offset);
*(bytes_buf++) =
(u8)qed_rd(p_hwfn, p_ptt,
data_lo_addr);
*(bytes_buf++) =
(u8)qed_rd(p_hwfn, p_ptt,
data_hi_addr);
}
}
}
offset += PHY_DUMP_SIZE_DWORDS;
}
return offset;
}
static void qed_config_dbg_line(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
enum block_id block_id,
u8 line_id,
u8 cycle_en,
u8 right_shift, u8 force_valid, u8 force_frame)
{
struct block_defs *p_block_defs = s_block_defs[block_id];
qed_wr(p_hwfn, p_ptt, p_block_defs->dbg_select_addr, line_id);
qed_wr(p_hwfn, p_ptt, p_block_defs->dbg_cycle_enable_addr, cycle_en);
qed_wr(p_hwfn, p_ptt, p_block_defs->dbg_shift_addr, right_shift);
qed_wr(p_hwfn, p_ptt, p_block_defs->dbg_force_valid_addr, force_valid);
qed_wr(p_hwfn, p_ptt, p_block_defs->dbg_force_frame_addr, force_frame);
}
static u32 qed_grc_dump_static_debug(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump)
{
u32 block_dwords = NUM_DBG_BUS_LINES * STATIC_DEBUG_LINE_DWORDS;
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 offset = 0, block_id, line_id;
struct block_defs *p_block_defs;
if (dump) {
DP_VERBOSE(p_hwfn,
QED_MSG_DEBUG, "Dumping static debug data...\n");
for (block_id = 0; block_id < MAX_BLOCK_ID; block_id++) {
p_block_defs = s_block_defs[block_id];
if (p_block_defs->has_dbg_bus[dev_data->chip_id])
qed_wr(p_hwfn, p_ptt,
p_block_defs->dbg_cycle_enable_addr, 0);
}
qed_bus_reset_dbg_block(p_hwfn, p_ptt);
qed_bus_set_framing_mode(p_hwfn,
p_ptt, DBG_BUS_FRAME_MODE_8HW_0ST);
qed_wr(p_hwfn,
p_ptt, DBG_REG_DEBUG_TARGET, DBG_BUS_TARGET_ID_INT_BUF);
qed_wr(p_hwfn, p_ptt, DBG_REG_FULL_MODE, 1);
qed_bus_enable_dbg_block(p_hwfn, p_ptt, true);
}
for (block_id = 0; block_id < MAX_BLOCK_ID; block_id++) {
p_block_defs = s_block_defs[block_id];
if (!p_block_defs->has_dbg_bus[dev_data->chip_id])
continue;
offset += qed_grc_dump_mem_hdr(p_hwfn,
dump_buf + offset,
dump,
p_block_defs->name, 0,
block_dwords, 32, false,
"STATIC", false, 0);
if (dump && !dev_data->block_in_reset[block_id]) {
u8 dbg_client_id =
p_block_defs->dbg_client_id[dev_data->chip_id];
u32 addr = BYTES_TO_DWORDS(DBG_REG_CALENDAR_OUT_DATA);
u32 len = STATIC_DEBUG_LINE_DWORDS;
qed_bus_enable_clients(p_hwfn, p_ptt,
BIT(dbg_client_id));
for (line_id = 0; line_id < NUM_DBG_BUS_LINES;
line_id++) {
qed_config_dbg_line(p_hwfn,
p_ptt,
(enum block_id)block_id,
(u8)line_id,
0xf, 0, 0, 0);
offset +=
qed_grc_dump_addr_range(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
len);
}
qed_bus_enable_clients(p_hwfn, p_ptt, 0);
qed_wr(p_hwfn, p_ptt,
p_block_defs->dbg_cycle_enable_addr, 0);
} else {
if (dump)
memset(dump_buf + offset, 0,
DWORDS_TO_BYTES(block_dwords));
offset += block_dwords;
}
}
if (dump) {
qed_bus_enable_dbg_block(p_hwfn, p_ptt, false);
qed_bus_enable_clients(p_hwfn, p_ptt, 0);
}
return offset;
}
static enum dbg_status qed_grc_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump, u32 *num_dumped_dwords)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
bool parities_masked = false;
u8 i, port_mode = 0;
u32 offset = 0;
*num_dumped_dwords = 0;
if (dump) {
switch (qed_rd(p_hwfn, p_ptt, MISC_REG_PORT_MODE)) {
case 0:
port_mode = 1;
break;
case 1:
port_mode = 2;
break;
case 2:
port_mode = 4;
break;
}
}
if (dump)
qed_update_blocks_reset_state(p_hwfn, p_ptt);
offset += qed_dump_common_global_params(p_hwfn,
p_ptt,
dump_buf + offset, dump, 4);
offset += qed_dump_str_param(dump_buf + offset,
dump, "dump-type", "grc-dump");
offset += qed_dump_num_param(dump_buf + offset,
dump,
"num-lcids",
qed_grc_get_param(p_hwfn,
DBG_GRC_PARAM_NUM_LCIDS));
offset += qed_dump_num_param(dump_buf + offset,
dump,
"num-ltids",
qed_grc_get_param(p_hwfn,
DBG_GRC_PARAM_NUM_LTIDS));
offset += qed_dump_num_param(dump_buf + offset,
dump, "num-ports", port_mode);
if (qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_REGS))
offset += qed_grc_dump_reset_regs(p_hwfn,
p_ptt,
dump_buf + offset, dump);
if (dump) {
qed_grc_unreset_blocks(p_hwfn, p_ptt);
qed_update_blocks_reset_state(p_hwfn, p_ptt);
}
if (dump && !qed_grc_get_param(p_hwfn, DBG_GRC_PARAM_NO_MCP)) {
parities_masked = !qed_mcp_mask_parities(p_hwfn, p_ptt, 1);
if (!parities_masked) {
DP_NOTICE(p_hwfn,
"Failed to mask parities using MFW\n");
if (qed_grc_get_param
(p_hwfn, DBG_GRC_PARAM_PARITY_SAFE))
return DBG_STATUS_MCP_COULD_NOT_MASK_PRTY;
}
}
if (qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_REGS))
offset += qed_grc_dump_modified_regs(p_hwfn,
p_ptt,
dump_buf + offset, dump);
if (dump &&
(qed_grc_is_included(p_hwfn,
DBG_GRC_PARAM_DUMP_IOR) ||
qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_VFC)))
qed_grc_stall_storms(p_hwfn, p_ptt, true);
if (qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_REGS)) {
bool block_enable[MAX_BLOCK_ID];
for (i = 0; i < MAX_BLOCK_ID; i++)
block_enable[i] = true;
block_enable[BLOCK_MCP] = false;
offset += qed_grc_dump_registers(p_hwfn,
p_ptt,
dump_buf +
offset,
dump,
block_enable, NULL, NULL);
offset += qed_grc_dump_special_regs(p_hwfn,
p_ptt,
dump_buf + offset, dump);
}
offset += qed_grc_dump_memories(p_hwfn, p_ptt, dump_buf + offset, dump);
if (qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_MCP))
offset += qed_grc_dump_mcp(p_hwfn,
p_ptt, dump_buf + offset, dump);
if (qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_CM_CTX))
offset += qed_grc_dump_ctx(p_hwfn,
p_ptt, dump_buf + offset, dump);
if (qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_RSS))
offset += qed_grc_dump_rss(p_hwfn,
p_ptt, dump_buf + offset, dump);
for (i = 0; i < NUM_BIG_RAM_TYPES; i++)
if (qed_grc_is_included(p_hwfn, s_big_ram_defs[i].grc_param))
offset += qed_grc_dump_big_ram(p_hwfn,
p_ptt,
dump_buf + offset,
dump, i);
if (qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_IOR))
offset += qed_grc_dump_iors(p_hwfn,
p_ptt, dump_buf + offset, dump);
if (qed_grc_is_included(p_hwfn, DBG_GRC_PARAM_DUMP_VFC))
offset += qed_grc_dump_vfc(p_hwfn,
p_ptt, dump_buf + offset, dump);
if (qed_grc_is_included(p_hwfn,
DBG_GRC_PARAM_DUMP_PHY) && dev_data->chip_id ==
CHIP_K2 && dev_data->platform_id == PLATFORM_ASIC)
offset += qed_grc_dump_phy(p_hwfn,
p_ptt, dump_buf + offset, dump);
if (qed_grc_is_included(p_hwfn,
DBG_GRC_PARAM_DUMP_STATIC) &&
dev_data->bus.state == DBG_BUS_STATE_IDLE)
offset += qed_grc_dump_static_debug(p_hwfn,
p_ptt,
dump_buf + offset, dump);
offset += qed_dump_last_section(dump_buf, offset, dump);
if (dump) {
if (qed_grc_get_param(p_hwfn, DBG_GRC_PARAM_UNSTALL))
qed_grc_stall_storms(p_hwfn, p_ptt, false);
qed_grc_clear_all_prty(p_hwfn, p_ptt);
if (parities_masked)
qed_mcp_mask_parities(p_hwfn, p_ptt, 0);
}
*num_dumped_dwords = offset;
return DBG_STATUS_OK;
}
static u32 qed_idle_chk_dump_failure(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *
dump_buf,
bool dump,
u16 rule_id,
const struct dbg_idle_chk_rule *rule,
u16 fail_entry_id, u32 *cond_reg_values)
{
const union dbg_idle_chk_reg *regs = &((const union dbg_idle_chk_reg *)
s_dbg_arrays
[BIN_BUF_DBG_IDLE_CHK_REGS].
ptr)[rule->reg_offset];
const struct dbg_idle_chk_cond_reg *cond_regs = &regs[0].cond_reg;
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
struct dbg_idle_chk_result_hdr *hdr =
(struct dbg_idle_chk_result_hdr *)dump_buf;
const struct dbg_idle_chk_info_reg *info_regs =
&regs[rule->num_cond_regs].info_reg;
u32 next_reg_offset = 0, i, offset = 0;
u8 reg_id;
if (dump) {
memset(hdr, 0, sizeof(*hdr));
hdr->rule_id = rule_id;
hdr->mem_entry_id = fail_entry_id;
hdr->severity = rule->severity;
hdr->num_dumped_cond_regs = rule->num_cond_regs;
}
offset += IDLE_CHK_RESULT_HDR_DWORDS;
for (reg_id = 0; reg_id < rule->num_cond_regs; reg_id++) {
const struct dbg_idle_chk_cond_reg *reg = &cond_regs[reg_id];
if (dump) {
struct dbg_idle_chk_result_reg_hdr *reg_hdr =
(struct dbg_idle_chk_result_reg_hdr *)(dump_buf
+ offset);
offset += IDLE_CHK_RESULT_REG_HDR_DWORDS;
memset(reg_hdr, 0,
sizeof(struct dbg_idle_chk_result_reg_hdr));
reg_hdr->start_entry = reg->start_entry;
reg_hdr->size = reg->entry_size;
SET_FIELD(reg_hdr->data,
DBG_IDLE_CHK_RESULT_REG_HDR_IS_MEM,
reg->num_entries > 1 || reg->start_entry > 0
? 1 : 0);
SET_FIELD(reg_hdr->data,
DBG_IDLE_CHK_RESULT_REG_HDR_REG_ID, reg_id);
for (i = 0; i < reg_hdr->size;
i++, next_reg_offset++, offset++)
dump_buf[offset] =
cond_reg_values[next_reg_offset];
} else {
offset += IDLE_CHK_RESULT_REG_HDR_DWORDS +
reg->entry_size;
}
}
for (reg_id = 0; reg_id < rule->num_info_regs; reg_id++) {
const struct dbg_idle_chk_info_reg *reg = &info_regs[reg_id];
u32 block_id;
if (!dump) {
offset += IDLE_CHK_RESULT_REG_HDR_DWORDS + reg->size;
continue;
}
block_id = GET_FIELD(reg->data, DBG_IDLE_CHK_INFO_REG_BLOCK_ID);
if (block_id >= MAX_BLOCK_ID) {
DP_NOTICE(p_hwfn, "Invalid block_id\n");
return 0;
}
if (!dev_data->block_in_reset[block_id]) {
bool eval_mode = GET_FIELD(reg->mode.data,
DBG_MODE_HDR_EVAL_MODE) > 0;
bool mode_match = true;
if (eval_mode) {
u16 modes_buf_offset =
GET_FIELD(reg->mode.data,
DBG_MODE_HDR_MODES_BUF_OFFSET);
mode_match =
qed_is_mode_match(p_hwfn,
&modes_buf_offset);
}
if (mode_match) {
u32 addr =
GET_FIELD(reg->data,
DBG_IDLE_CHK_INFO_REG_ADDRESS);
struct dbg_idle_chk_result_reg_hdr *reg_hdr =
(struct dbg_idle_chk_result_reg_hdr *)
(dump_buf + offset);
offset += IDLE_CHK_RESULT_REG_HDR_DWORDS;
hdr->num_dumped_info_regs++;
memset(reg_hdr, 0, sizeof(*reg_hdr));
reg_hdr->size = reg->size;
SET_FIELD(reg_hdr->data,
DBG_IDLE_CHK_RESULT_REG_HDR_REG_ID,
rule->num_cond_regs + reg_id);
offset +=
qed_grc_dump_addr_range(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
addr,
reg->size);
}
}
}
return offset;
}
static u32
qed_idle_chk_dump_rule_entries(struct qed_hwfn *p_hwfn, struct qed_ptt *p_ptt,
u32 *dump_buf, bool dump,
const struct dbg_idle_chk_rule *input_rules,
u32 num_input_rules, u32 *num_failing_rules)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 cond_reg_values[IDLE_CHK_MAX_ENTRIES_SIZE];
u32 i, offset = 0;
u16 entry_id;
u8 reg_id;
*num_failing_rules = 0;
for (i = 0; i < num_input_rules; i++) {
const struct dbg_idle_chk_cond_reg *cond_regs;
const struct dbg_idle_chk_rule *rule;
const union dbg_idle_chk_reg *regs;
u16 num_reg_entries = 1;
bool check_rule = true;
const u32 *imm_values;
rule = &input_rules[i];
regs = &((const union dbg_idle_chk_reg *)
s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_REGS].ptr)
[rule->reg_offset];
cond_regs = &regs[0].cond_reg;
imm_values = &s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_IMMS].ptr
[rule->imm_offset];
for (reg_id = 0; reg_id < rule->num_cond_regs && check_rule;
reg_id++) {
u32 block_id = GET_FIELD(cond_regs[reg_id].data,
DBG_IDLE_CHK_COND_REG_BLOCK_ID);
if (block_id >= MAX_BLOCK_ID) {
DP_NOTICE(p_hwfn, "Invalid block_id\n");
return 0;
}
check_rule = !dev_data->block_in_reset[block_id];
if (cond_regs[reg_id].num_entries > num_reg_entries)
num_reg_entries = cond_regs[reg_id].num_entries;
}
if (!check_rule && dump)
continue;
if (!dump) {
u32 entry_dump_size =
qed_idle_chk_dump_failure(p_hwfn,
p_ptt,
dump_buf + offset,
false,
rule->rule_id,
rule,
0,
NULL);
offset += num_reg_entries * entry_dump_size;
(*num_failing_rules) += num_reg_entries;
continue;
}
for (entry_id = 0; entry_id < num_reg_entries; entry_id++) {
u32 next_reg_offset = 0;
for (reg_id = 0; reg_id < rule->num_cond_regs;
reg_id++) {
const struct dbg_idle_chk_cond_reg *reg =
&cond_regs[reg_id];
u32 addr =
GET_FIELD(reg->data,
DBG_IDLE_CHK_COND_REG_ADDRESS);
if (reg->num_entries > 1 ||
reg->start_entry > 0) {
u32 padded_entry_size =
reg->entry_size > 1 ?
roundup_pow_of_two(reg->entry_size) :
1;
addr += (reg->start_entry + entry_id) *
padded_entry_size;
}
if (next_reg_offset + reg->entry_size >=
IDLE_CHK_MAX_ENTRIES_SIZE) {
DP_NOTICE(p_hwfn,
"idle check registers entry is too large\n");
return 0;
}
next_reg_offset +=
qed_grc_dump_addr_range(p_hwfn,
p_ptt,
cond_reg_values +
next_reg_offset,
dump, addr,
reg->entry_size);
}
if ((*cond_arr[rule->cond_id])(cond_reg_values,
imm_values)) {
offset +=
qed_idle_chk_dump_failure(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
rule->rule_id,
rule,
entry_id,
cond_reg_values);
(*num_failing_rules)++;
break;
}
}
}
return offset;
}
static u32 qed_idle_chk_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf, bool dump)
{
u32 offset = 0, input_offset = 0, num_failing_rules = 0;
u32 num_failing_rules_offset;
offset += qed_dump_common_global_params(p_hwfn,
p_ptt,
dump_buf + offset, dump, 1);
offset += qed_dump_str_param(dump_buf + offset,
dump, "dump-type", "idle-chk");
offset += qed_dump_section_hdr(dump_buf + offset, dump, "idle_chk", 1);
num_failing_rules_offset = offset;
offset += qed_dump_num_param(dump_buf + offset, dump, "num_rules", 0);
while (input_offset <
s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_RULES].size_in_dwords) {
const struct dbg_idle_chk_cond_hdr *cond_hdr =
(const struct dbg_idle_chk_cond_hdr *)
&s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_RULES].ptr
[input_offset++];
bool eval_mode = GET_FIELD(cond_hdr->mode.data,
DBG_MODE_HDR_EVAL_MODE) > 0;
bool mode_match = true;
if (eval_mode) {
u16 modes_buf_offset =
GET_FIELD(cond_hdr->mode.data,
DBG_MODE_HDR_MODES_BUF_OFFSET);
mode_match = qed_is_mode_match(p_hwfn,
&modes_buf_offset);
}
if (mode_match) {
u32 curr_failing_rules;
offset +=
qed_idle_chk_dump_rule_entries(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
(const struct dbg_idle_chk_rule *)
&s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_RULES].
ptr[input_offset],
cond_hdr->data_size / IDLE_CHK_RULE_SIZE_DWORDS,
&curr_failing_rules);
num_failing_rules += curr_failing_rules;
}
input_offset += cond_hdr->data_size;
}
if (dump)
qed_dump_num_param(dump_buf + num_failing_rules_offset,
dump, "num_rules", num_failing_rules);
return offset;
}
static enum dbg_status qed_find_nvram_image(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 image_type,
u32 *nvram_offset_bytes,
u32 *nvram_size_bytes)
{
u32 ret_mcp_resp, ret_mcp_param, ret_txn_size;
struct mcp_file_att file_att;
int nvm_result = qed_mcp_nvm_rd_cmd(p_hwfn,
p_ptt,
DRV_MSG_CODE_NVM_GET_FILE_ATT,
image_type,
&ret_mcp_resp,
&ret_mcp_param,
&ret_txn_size,
(u32 *)&file_att);
if (nvm_result ||
(ret_mcp_resp & FW_MSG_CODE_MASK) != FW_MSG_CODE_NVM_OK)
return DBG_STATUS_NVRAM_GET_IMAGE_FAILED;
*nvram_offset_bytes = file_att.nvm_start_addr;
*nvram_size_bytes = file_att.len;
DP_VERBOSE(p_hwfn,
QED_MSG_DEBUG,
"find_nvram_image: found NVRAM image of type %d in NVRAM offset %d bytes with size %d bytes\n",
image_type, *nvram_offset_bytes, *nvram_size_bytes);
if (*nvram_size_bytes & 0x3)
return DBG_STATUS_NON_ALIGNED_NVRAM_IMAGE;
return DBG_STATUS_OK;
}
static enum dbg_status qed_nvram_read(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 nvram_offset_bytes,
u32 nvram_size_bytes, u32 *ret_buf)
{
u32 ret_mcp_resp, ret_mcp_param, ret_read_size;
u32 bytes_to_copy, read_offset = 0;
s32 bytes_left = nvram_size_bytes;
DP_VERBOSE(p_hwfn,
QED_MSG_DEBUG,
"nvram_read: reading image of size %d bytes from NVRAM\n",
nvram_size_bytes);
do {
bytes_to_copy =
(bytes_left >
MCP_DRV_NVM_BUF_LEN) ? MCP_DRV_NVM_BUF_LEN : bytes_left;
if (qed_mcp_nvm_rd_cmd(p_hwfn, p_ptt,
DRV_MSG_CODE_NVM_READ_NVRAM,
(nvram_offset_bytes +
read_offset) |
(bytes_to_copy <<
DRV_MB_PARAM_NVM_LEN_SHIFT),
&ret_mcp_resp, &ret_mcp_param,
&ret_read_size,
(u32 *)((u8 *)ret_buf +
read_offset)) != 0)
return DBG_STATUS_NVRAM_READ_FAILED;
if ((ret_mcp_resp & FW_MSG_CODE_MASK) != FW_MSG_CODE_NVM_OK)
return DBG_STATUS_NVRAM_READ_FAILED;
read_offset += ret_read_size;
bytes_left -= ret_read_size;
} while (bytes_left > 0);
return DBG_STATUS_OK;
}
static enum dbg_status qed_mcp_trace_get_data_info(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *trace_data_grc_addr,
u32 *trace_data_size_bytes)
{
u32 spad_trace_offsize = qed_rd(p_hwfn,
p_ptt,
MCP_SPAD_TRACE_OFFSIZE_ADDR);
u32 signature;
*trace_data_grc_addr =
MCP_REG_SCRATCH + SECTION_OFFSET(spad_trace_offsize);
signature = qed_rd(p_hwfn, p_ptt,
*trace_data_grc_addr +
offsetof(struct mcp_trace, signature));
if (signature != MFW_TRACE_SIGNATURE)
return DBG_STATUS_INVALID_TRACE_SIGNATURE;
*trace_data_size_bytes = qed_rd(p_hwfn,
p_ptt,
*trace_data_grc_addr +
offsetof(struct mcp_trace, size));
return DBG_STATUS_OK;
}
static enum dbg_status qed_mcp_trace_get_meta_info(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 trace_data_size_bytes,
u32 *running_bundle_id,
u32 *trace_meta_offset_bytes,
u32 *trace_meta_size_bytes)
{
u32 spad_trace_offsize = qed_rd(p_hwfn,
p_ptt,
MCP_SPAD_TRACE_OFFSIZE_ADDR);
u32 running_mfw_addr =
MCP_REG_SCRATCH + SECTION_OFFSET(spad_trace_offsize) +
QED_SECTION_SIZE(spad_trace_offsize) + trace_data_size_bytes;
u32 nvram_image_type;
*running_bundle_id = qed_rd(p_hwfn, p_ptt, running_mfw_addr);
if (*running_bundle_id > 1)
return DBG_STATUS_INVALID_NVRAM_BUNDLE;
nvram_image_type =
(*running_bundle_id ==
DIR_ID_1) ? NVM_TYPE_MFW_TRACE1 : NVM_TYPE_MFW_TRACE2;
return qed_find_nvram_image(p_hwfn,
p_ptt,
nvram_image_type,
trace_meta_offset_bytes,
trace_meta_size_bytes);
}
static enum dbg_status qed_mcp_trace_read_meta(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 nvram_offset_in_bytes,
u32 size_in_bytes, u32 *buf)
{
u8 *byte_buf = (u8 *)buf;
u8 modules_num, i;
u32 signature;
enum dbg_status status = qed_nvram_read(p_hwfn,
p_ptt,
nvram_offset_in_bytes,
size_in_bytes,
buf);
if (status != DBG_STATUS_OK)
return status;
signature = qed_read_unaligned_dword(byte_buf);
byte_buf += sizeof(u32);
if (signature != MCP_TRACE_META_IMAGE_SIGNATURE)
return DBG_STATUS_INVALID_TRACE_SIGNATURE;
modules_num = *(byte_buf++);
for (i = 0; i < modules_num; i++) {
u8 module_len = *(byte_buf++);
byte_buf += module_len;
}
signature = qed_read_unaligned_dword(byte_buf);
byte_buf += sizeof(u32);
if (signature != MCP_TRACE_META_IMAGE_SIGNATURE)
return DBG_STATUS_INVALID_TRACE_SIGNATURE;
return DBG_STATUS_OK;
}
static enum dbg_status qed_mcp_trace_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump, u32 *num_dumped_dwords)
{
u32 trace_data_grc_addr, trace_data_size_bytes, trace_data_size_dwords;
u32 trace_meta_size_dwords = 0, running_bundle_id, offset = 0;
u32 trace_meta_offset_bytes = 0, trace_meta_size_bytes = 0;
enum dbg_status status;
bool mcp_access;
int halted = 0;
mcp_access = !qed_grc_get_param(p_hwfn, DBG_GRC_PARAM_NO_MCP);
*num_dumped_dwords = 0;
status = qed_mcp_trace_get_data_info(p_hwfn,
p_ptt,
&trace_data_grc_addr,
&trace_data_size_bytes);
if (status != DBG_STATUS_OK)
return status;
offset += qed_dump_common_global_params(p_hwfn,
p_ptt,
dump_buf + offset, dump, 1);
offset += qed_dump_str_param(dump_buf + offset,
dump, "dump-type", "mcp-trace");
if (dump && mcp_access) {
halted = !qed_mcp_halt(p_hwfn, p_ptt);
if (!halted)
DP_NOTICE(p_hwfn, "MCP halt failed!\n");
}
trace_data_size_dwords =
DIV_ROUND_UP(trace_data_size_bytes + sizeof(struct mcp_trace),
BYTES_IN_DWORD);
offset += qed_dump_section_hdr(dump_buf + offset,
dump, "mcp_trace_data", 1);
offset += qed_dump_num_param(dump_buf + offset,
dump, "size", trace_data_size_dwords);
offset += qed_grc_dump_addr_range(p_hwfn,
p_ptt,
dump_buf + offset,
dump,
BYTES_TO_DWORDS(trace_data_grc_addr),
trace_data_size_dwords);
if (halted && qed_mcp_resume(p_hwfn, p_ptt) != 0)
DP_NOTICE(p_hwfn, "Failed to resume MCP after halt!\n");
offset += qed_dump_section_hdr(dump_buf + offset,
dump, "mcp_trace_meta", 1);
if (mcp_access) {
status = qed_mcp_trace_get_meta_info(p_hwfn,
p_ptt,
trace_data_size_bytes,
&running_bundle_id,
&trace_meta_offset_bytes,
&trace_meta_size_bytes);
if (status == DBG_STATUS_OK)
trace_meta_size_dwords =
BYTES_TO_DWORDS(trace_meta_size_bytes);
}
offset += qed_dump_num_param(dump_buf + offset,
dump, "size", trace_meta_size_dwords);
if (dump && trace_meta_size_dwords)
status = qed_mcp_trace_read_meta(p_hwfn,
p_ptt,
trace_meta_offset_bytes,
trace_meta_size_bytes,
dump_buf + offset);
if (status == DBG_STATUS_OK)
offset += trace_meta_size_dwords;
*num_dumped_dwords = offset;
return mcp_access ? status : DBG_STATUS_NVRAM_GET_IMAGE_FAILED;
}
static enum dbg_status qed_reg_fifo_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump, u32 *num_dumped_dwords)
{
u32 offset = 0, dwords_read, size_param_offset;
bool fifo_has_data;
*num_dumped_dwords = 0;
offset += qed_dump_common_global_params(p_hwfn,
p_ptt,
dump_buf + offset, dump, 1);
offset += qed_dump_str_param(dump_buf + offset,
dump, "dump-type", "reg-fifo");
offset += qed_dump_section_hdr(dump_buf + offset,
dump, "reg_fifo_data", 1);
size_param_offset = offset;
offset += qed_dump_num_param(dump_buf + offset, dump, "size", 0);
if (!dump) {
offset += REG_FIFO_DEPTH_DWORDS;
*num_dumped_dwords = offset;
return DBG_STATUS_OK;
}
fifo_has_data = qed_rd(p_hwfn, p_ptt,
GRC_REG_TRACE_FIFO_VALID_DATA) > 0;
for (dwords_read = 0;
fifo_has_data && dwords_read < REG_FIFO_DEPTH_DWORDS;
dwords_read += REG_FIFO_ELEMENT_DWORDS, offset +=
REG_FIFO_ELEMENT_DWORDS) {
if (qed_dmae_grc2host(p_hwfn, p_ptt, GRC_REG_TRACE_FIFO,
(u64)(uintptr_t)(&dump_buf[offset]),
REG_FIFO_ELEMENT_DWORDS, 0))
return DBG_STATUS_DMAE_FAILED;
fifo_has_data = qed_rd(p_hwfn, p_ptt,
GRC_REG_TRACE_FIFO_VALID_DATA) > 0;
}
qed_dump_num_param(dump_buf + size_param_offset, dump, "size",
dwords_read);
*num_dumped_dwords = offset;
return DBG_STATUS_OK;
}
static enum dbg_status qed_igu_fifo_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump, u32 *num_dumped_dwords)
{
u32 offset = 0, dwords_read, size_param_offset;
bool fifo_has_data;
*num_dumped_dwords = 0;
offset += qed_dump_common_global_params(p_hwfn,
p_ptt,
dump_buf + offset, dump, 1);
offset += qed_dump_str_param(dump_buf + offset,
dump, "dump-type", "igu-fifo");
offset += qed_dump_section_hdr(dump_buf + offset,
dump, "igu_fifo_data", 1);
size_param_offset = offset;
offset += qed_dump_num_param(dump_buf + offset, dump, "size", 0);
if (!dump) {
offset += IGU_FIFO_DEPTH_DWORDS;
*num_dumped_dwords = offset;
return DBG_STATUS_OK;
}
fifo_has_data = qed_rd(p_hwfn, p_ptt,
IGU_REG_ERROR_HANDLING_DATA_VALID) > 0;
for (dwords_read = 0;
fifo_has_data && dwords_read < IGU_FIFO_DEPTH_DWORDS;
dwords_read += IGU_FIFO_ELEMENT_DWORDS, offset +=
IGU_FIFO_ELEMENT_DWORDS) {
if (qed_dmae_grc2host(p_hwfn, p_ptt,
IGU_REG_ERROR_HANDLING_MEMORY,
(u64)(uintptr_t)(&dump_buf[offset]),
IGU_FIFO_ELEMENT_DWORDS, 0))
return DBG_STATUS_DMAE_FAILED;
fifo_has_data = qed_rd(p_hwfn, p_ptt,
IGU_REG_ERROR_HANDLING_DATA_VALID) > 0;
}
qed_dump_num_param(dump_buf + size_param_offset, dump, "size",
dwords_read);
*num_dumped_dwords = offset;
return DBG_STATUS_OK;
}
static enum dbg_status qed_protection_override_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
bool dump,
u32 *num_dumped_dwords)
{
u32 offset = 0, size_param_offset, override_window_dwords;
*num_dumped_dwords = 0;
offset += qed_dump_common_global_params(p_hwfn,
p_ptt,
dump_buf + offset, dump, 1);
offset += qed_dump_str_param(dump_buf + offset,
dump, "dump-type", "protection-override");
offset += qed_dump_section_hdr(dump_buf + offset,
dump, "protection_override_data", 1);
size_param_offset = offset;
offset += qed_dump_num_param(dump_buf + offset, dump, "size", 0);
if (!dump) {
offset += PROTECTION_OVERRIDE_DEPTH_DWORDS;
*num_dumped_dwords = offset;
return DBG_STATUS_OK;
}
override_window_dwords =
qed_rd(p_hwfn, p_ptt,
GRC_REG_NUMBER_VALID_OVERRIDE_WINDOW) *
PROTECTION_OVERRIDE_ELEMENT_DWORDS;
if (qed_dmae_grc2host(p_hwfn, p_ptt,
GRC_REG_PROTECTION_OVERRIDE_WINDOW,
(u64)(uintptr_t)(dump_buf + offset),
override_window_dwords, 0))
return DBG_STATUS_DMAE_FAILED;
offset += override_window_dwords;
qed_dump_num_param(dump_buf + size_param_offset, dump, "size",
override_window_dwords);
*num_dumped_dwords = offset;
return DBG_STATUS_OK;
}
static u32 qed_fw_asserts_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt, u32 *dump_buf, bool dump)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
struct fw_asserts_ram_section *asserts;
char storm_letter_str[2] = "?";
struct fw_info fw_info;
u32 offset = 0;
u8 storm_id;
offset += qed_dump_common_global_params(p_hwfn,
p_ptt,
dump_buf + offset, dump, 1);
offset += qed_dump_str_param(dump_buf + offset,
dump, "dump-type", "fw-asserts");
for (storm_id = 0; storm_id < MAX_DBG_STORMS; storm_id++) {
u32 fw_asserts_section_addr, next_list_idx_addr, next_list_idx;
u32 last_list_idx, addr;
if (dev_data->block_in_reset[s_storm_defs[storm_id].block_id])
continue;
qed_read_fw_info(p_hwfn, p_ptt, storm_id, &fw_info);
asserts = &fw_info.fw_asserts_section;
storm_letter_str[0] = s_storm_defs[storm_id].letter;
offset += qed_dump_section_hdr(dump_buf + offset, dump,
"fw_asserts", 2);
offset += qed_dump_str_param(dump_buf + offset, dump, "storm",
storm_letter_str);
offset += qed_dump_num_param(dump_buf + offset, dump, "size",
asserts->list_element_dword_size);
if (!dump) {
offset += asserts->list_element_dword_size;
continue;
}
fw_asserts_section_addr =
s_storm_defs[storm_id].sem_fast_mem_addr +
SEM_FAST_REG_INT_RAM +
RAM_LINES_TO_BYTES(asserts->section_ram_line_offset);
next_list_idx_addr =
fw_asserts_section_addr +
DWORDS_TO_BYTES(asserts->list_next_index_dword_offset);
next_list_idx = qed_rd(p_hwfn, p_ptt, next_list_idx_addr);
last_list_idx = (next_list_idx > 0
? next_list_idx
: asserts->list_num_elements) - 1;
addr = BYTES_TO_DWORDS(fw_asserts_section_addr) +
asserts->list_dword_offset +
last_list_idx * asserts->list_element_dword_size;
offset +=
qed_grc_dump_addr_range(p_hwfn, p_ptt,
dump_buf + offset,
dump, addr,
asserts->list_element_dword_size);
}
offset += qed_dump_section_hdr(dump_buf + offset, dump, "last", 0);
return offset;
}
enum dbg_status qed_dbg_set_bin_ptr(const u8 * const bin_ptr)
{
struct bin_buffer_hdr *buf_array = (struct bin_buffer_hdr *)bin_ptr;
u8 buf_id;
for (buf_id = 0; buf_id < MAX_BIN_DBG_BUFFER_TYPE; buf_id++) {
s_dbg_arrays[buf_id].ptr =
(u32 *)(bin_ptr + buf_array[buf_id].offset);
s_dbg_arrays[buf_id].size_in_dwords =
BYTES_TO_DWORDS(buf_array[buf_id].length);
}
return DBG_STATUS_OK;
}
void qed_dbg_grc_set_params_default(struct qed_hwfn *p_hwfn)
{
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
u32 i;
for (i = 0; i < MAX_DBG_GRC_PARAMS; i++)
dev_data->grc.param_val[i] =
s_grc_param_defs[i].default_val[dev_data->chip_id];
}
enum dbg_status qed_dbg_grc_get_dump_buf_size(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *buf_size)
{
enum dbg_status status = qed_dbg_dev_init(p_hwfn, p_ptt);
*buf_size = 0;
if (status != DBG_STATUS_OK)
return status;
if (!s_dbg_arrays[BIN_BUF_DBG_MODE_TREE].ptr ||
!s_dbg_arrays[BIN_BUF_DBG_DUMP_REG].ptr ||
!s_dbg_arrays[BIN_BUF_DBG_DUMP_MEM].ptr ||
!s_dbg_arrays[BIN_BUF_DBG_ATTN_BLOCKS].ptr ||
!s_dbg_arrays[BIN_BUF_DBG_ATTN_REGS].ptr)
return DBG_STATUS_DBG_ARRAY_NOT_SET;
return qed_grc_dump(p_hwfn, p_ptt, NULL, false, buf_size);
}
enum dbg_status qed_dbg_grc_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
u32 buf_size_in_dwords,
u32 *num_dumped_dwords)
{
u32 needed_buf_size_in_dwords;
enum dbg_status status;
status = qed_dbg_grc_get_dump_buf_size(p_hwfn, p_ptt,
&needed_buf_size_in_dwords);
*num_dumped_dwords = 0;
if (status != DBG_STATUS_OK)
return status;
if (buf_size_in_dwords < needed_buf_size_in_dwords)
return DBG_STATUS_DUMP_BUF_TOO_SMALL;
status = qed_grc_dump(p_hwfn, p_ptt, dump_buf, true, num_dumped_dwords);
qed_dbg_grc_set_params_default(p_hwfn);
return status;
}
enum dbg_status qed_dbg_idle_chk_get_dump_buf_size(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *buf_size)
{
enum dbg_status status = qed_dbg_dev_init(p_hwfn, p_ptt);
struct dbg_tools_data *dev_data = &p_hwfn->dbg_info;
*buf_size = 0;
if (status != DBG_STATUS_OK)
return status;
if (!s_dbg_arrays[BIN_BUF_DBG_MODE_TREE].ptr ||
!s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_REGS].ptr ||
!s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_IMMS].ptr ||
!s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_RULES].ptr)
return DBG_STATUS_DBG_ARRAY_NOT_SET;
if (!dev_data->idle_chk.buf_size_set) {
dev_data->idle_chk.buf_size = qed_idle_chk_dump(p_hwfn,
p_ptt,
NULL, false);
dev_data->idle_chk.buf_size_set = true;
}
*buf_size = dev_data->idle_chk.buf_size;
return DBG_STATUS_OK;
}
enum dbg_status qed_dbg_idle_chk_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
u32 buf_size_in_dwords,
u32 *num_dumped_dwords)
{
u32 needed_buf_size_in_dwords;
enum dbg_status status;
status = qed_dbg_idle_chk_get_dump_buf_size(p_hwfn, p_ptt,
&needed_buf_size_in_dwords);
*num_dumped_dwords = 0;
if (status != DBG_STATUS_OK)
return status;
if (buf_size_in_dwords < needed_buf_size_in_dwords)
return DBG_STATUS_DUMP_BUF_TOO_SMALL;
qed_update_blocks_reset_state(p_hwfn, p_ptt);
*num_dumped_dwords = qed_idle_chk_dump(p_hwfn, p_ptt, dump_buf, true);
qed_dbg_grc_set_params_default(p_hwfn);
return DBG_STATUS_OK;
}
enum dbg_status qed_dbg_mcp_trace_get_dump_buf_size(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *buf_size)
{
enum dbg_status status = qed_dbg_dev_init(p_hwfn, p_ptt);
*buf_size = 0;
if (status != DBG_STATUS_OK)
return status;
return qed_mcp_trace_dump(p_hwfn, p_ptt, NULL, false, buf_size);
}
enum dbg_status qed_dbg_mcp_trace_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
u32 buf_size_in_dwords,
u32 *num_dumped_dwords)
{
u32 needed_buf_size_in_dwords;
enum dbg_status status;
status =
qed_dbg_mcp_trace_get_dump_buf_size(p_hwfn, p_ptt,
&needed_buf_size_in_dwords);
if (status != DBG_STATUS_OK &&
status != DBG_STATUS_NVRAM_GET_IMAGE_FAILED)
return status;
if (buf_size_in_dwords < needed_buf_size_in_dwords)
return DBG_STATUS_DUMP_BUF_TOO_SMALL;
qed_update_blocks_reset_state(p_hwfn, p_ptt);
status = qed_mcp_trace_dump(p_hwfn,
p_ptt, dump_buf, true, num_dumped_dwords);
qed_dbg_grc_set_params_default(p_hwfn);
return status;
}
enum dbg_status qed_dbg_reg_fifo_get_dump_buf_size(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *buf_size)
{
enum dbg_status status = qed_dbg_dev_init(p_hwfn, p_ptt);
*buf_size = 0;
if (status != DBG_STATUS_OK)
return status;
return qed_reg_fifo_dump(p_hwfn, p_ptt, NULL, false, buf_size);
}
enum dbg_status qed_dbg_reg_fifo_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
u32 buf_size_in_dwords,
u32 *num_dumped_dwords)
{
u32 needed_buf_size_in_dwords;
enum dbg_status status;
status = qed_dbg_reg_fifo_get_dump_buf_size(p_hwfn, p_ptt,
&needed_buf_size_in_dwords);
*num_dumped_dwords = 0;
if (status != DBG_STATUS_OK)
return status;
if (buf_size_in_dwords < needed_buf_size_in_dwords)
return DBG_STATUS_DUMP_BUF_TOO_SMALL;
qed_update_blocks_reset_state(p_hwfn, p_ptt);
status = qed_reg_fifo_dump(p_hwfn,
p_ptt, dump_buf, true, num_dumped_dwords);
qed_dbg_grc_set_params_default(p_hwfn);
return status;
}
enum dbg_status qed_dbg_igu_fifo_get_dump_buf_size(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *buf_size)
{
enum dbg_status status = qed_dbg_dev_init(p_hwfn, p_ptt);
*buf_size = 0;
if (status != DBG_STATUS_OK)
return status;
return qed_igu_fifo_dump(p_hwfn, p_ptt, NULL, false, buf_size);
}
enum dbg_status qed_dbg_igu_fifo_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
u32 buf_size_in_dwords,
u32 *num_dumped_dwords)
{
u32 needed_buf_size_in_dwords;
enum dbg_status status;
status = qed_dbg_igu_fifo_get_dump_buf_size(p_hwfn, p_ptt,
&needed_buf_size_in_dwords);
*num_dumped_dwords = 0;
if (status != DBG_STATUS_OK)
return status;
if (buf_size_in_dwords < needed_buf_size_in_dwords)
return DBG_STATUS_DUMP_BUF_TOO_SMALL;
qed_update_blocks_reset_state(p_hwfn, p_ptt);
status = qed_igu_fifo_dump(p_hwfn,
p_ptt, dump_buf, true, num_dumped_dwords);
qed_dbg_grc_set_params_default(p_hwfn);
return status;
}
enum dbg_status
qed_dbg_protection_override_get_dump_buf_size(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *buf_size)
{
enum dbg_status status = qed_dbg_dev_init(p_hwfn, p_ptt);
*buf_size = 0;
if (status != DBG_STATUS_OK)
return status;
return qed_protection_override_dump(p_hwfn,
p_ptt, NULL, false, buf_size);
}
enum dbg_status qed_dbg_protection_override_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
u32 buf_size_in_dwords,
u32 *num_dumped_dwords)
{
u32 needed_buf_size_in_dwords;
enum dbg_status status;
status = qed_dbg_protection_override_get_dump_buf_size(p_hwfn, p_ptt,
&needed_buf_size_in_dwords);
*num_dumped_dwords = 0;
if (status != DBG_STATUS_OK)
return status;
if (buf_size_in_dwords < needed_buf_size_in_dwords)
return DBG_STATUS_DUMP_BUF_TOO_SMALL;
qed_update_blocks_reset_state(p_hwfn, p_ptt);
status = qed_protection_override_dump(p_hwfn,
p_ptt,
dump_buf,
true, num_dumped_dwords);
qed_dbg_grc_set_params_default(p_hwfn);
return status;
}
enum dbg_status qed_dbg_fw_asserts_get_dump_buf_size(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *buf_size)
{
enum dbg_status status = qed_dbg_dev_init(p_hwfn, p_ptt);
*buf_size = 0;
if (status != DBG_STATUS_OK)
return status;
qed_update_blocks_reset_state(p_hwfn, p_ptt);
*buf_size = qed_fw_asserts_dump(p_hwfn, p_ptt, NULL, false);
return DBG_STATUS_OK;
}
enum dbg_status qed_dbg_fw_asserts_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
u32 *dump_buf,
u32 buf_size_in_dwords,
u32 *num_dumped_dwords)
{
u32 needed_buf_size_in_dwords;
enum dbg_status status;
status = qed_dbg_fw_asserts_get_dump_buf_size(p_hwfn, p_ptt,
&needed_buf_size_in_dwords);
*num_dumped_dwords = 0;
if (status != DBG_STATUS_OK)
return status;
if (buf_size_in_dwords < needed_buf_size_in_dwords)
return DBG_STATUS_DUMP_BUF_TOO_SMALL;
*num_dumped_dwords = qed_fw_asserts_dump(p_hwfn, p_ptt, dump_buf, true);
return DBG_STATUS_OK;
}
enum dbg_status qed_dbg_user_set_bin_ptr(const u8 * const bin_ptr)
{
struct bin_buffer_hdr *buf_array = (struct bin_buffer_hdr *)bin_ptr;
u8 buf_id;
for (buf_id = 0; buf_id < MAX_BIN_DBG_BUFFER_TYPE; buf_id++) {
s_dbg_arrays[buf_id].ptr =
(u32 *)(bin_ptr + buf_array[buf_id].offset);
s_dbg_arrays[buf_id].size_in_dwords =
BYTES_TO_DWORDS(buf_array[buf_id].length);
}
return DBG_STATUS_OK;
}
static u32 qed_cyclic_add(u32 a, u32 b, u32 size)
{
return (a + b) % size;
}
static u32 qed_cyclic_sub(u32 a, u32 b, u32 size)
{
return (size + a - b) % size;
}
static u32 qed_read_from_cyclic_buf(void *buf,
u32 *offset,
u32 buf_size, u8 num_bytes_to_read)
{
u8 *bytes_buf = (u8 *)buf;
u8 *val_ptr;
u32 val = 0;
u8 i;
val_ptr = (u8 *)&val;
for (i = 0; i < num_bytes_to_read; i++) {
val_ptr[i] = bytes_buf[*offset];
*offset = qed_cyclic_add(*offset, 1, buf_size);
}
return val;
}
static u8 qed_read_byte_from_buf(void *buf, u32 *offset)
{
return ((u8 *)buf)[(*offset)++];
}
static u32 qed_read_dword_from_buf(void *buf, u32 *offset)
{
u32 dword_val = *(u32 *)&((u8 *)buf)[*offset];
*offset += 4;
return dword_val;
}
static void qed_read_str_from_buf(void *buf, u32 *offset, u32 size, char *dest)
{
const char *source_str = &((const char *)buf)[*offset];
strncpy(dest, source_str, size);
dest[size - 1] = '\0';
*offset += size;
}
static char *qed_get_buf_ptr(void *buf, u32 offset)
{
return buf ? (char *)buf + offset : s_temp_buf;
}
static u32 qed_read_param(u32 *dump_buf,
const char **param_name,
const char **param_str_val, u32 *param_num_val)
{
char *char_buf = (char *)dump_buf;
u32 offset = 0;
*param_name = char_buf;
offset += strlen(*param_name) + 1;
if (*(char_buf + offset++)) {
*param_str_val = char_buf + offset;
offset += strlen(*param_str_val) + 1;
if (offset & 0x3)
offset += (4 - (offset & 0x3));
} else {
*param_str_val = NULL;
if (offset & 0x3)
offset += (4 - (offset & 0x3));
*param_num_val = *(u32 *)(char_buf + offset);
offset += 4;
}
return offset / 4;
}
static u32 qed_read_section_hdr(u32 *dump_buf,
const char **section_name,
u32 *num_section_params)
{
const char *param_str_val;
return qed_read_param(dump_buf,
section_name, &param_str_val, num_section_params);
}
static u32 qed_print_section_params(u32 *dump_buf,
u32 num_section_params,
char *results_buf, u32 *num_chars_printed)
{
u32 i, dump_offset = 0, results_offset = 0;
for (i = 0; i < num_section_params; i++) {
const char *param_name;
const char *param_str_val;
u32 param_num_val = 0;
dump_offset += qed_read_param(dump_buf + dump_offset,
&param_name,
&param_str_val, &param_num_val);
if (param_str_val)
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"%s: %s\n", param_name, param_str_val);
else if (strcmp(param_name, "fw-timestamp"))
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"%s: %d\n", param_name, param_num_val);
}
results_offset +=
sprintf(qed_get_buf_ptr(results_buf, results_offset), "\n");
*num_chars_printed = results_offset;
return dump_offset;
}
const char *qed_dbg_get_status_str(enum dbg_status status)
{
return (status <
MAX_DBG_STATUS) ? s_status_str[status] : "Invalid debug status";
}
static u32 qed_parse_idle_chk_dump_rules(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 *dump_buf_end,
u32 num_rules,
bool print_fw_idle_chk,
char *results_buf,
u32 *num_errors, u32 *num_warnings)
{
u32 rule_idx, results_offset = 0;
u16 i, j;
*num_errors = 0;
*num_warnings = 0;
for (rule_idx = 0; rule_idx < num_rules && dump_buf < dump_buf_end;
rule_idx++) {
const struct dbg_idle_chk_rule_parsing_data *rule_parsing_data;
struct dbg_idle_chk_result_hdr *hdr;
const char *parsing_str;
u32 parsing_str_offset;
const char *lsi_msg;
u8 curr_reg_id = 0;
bool has_fw_msg;
hdr = (struct dbg_idle_chk_result_hdr *)dump_buf;
rule_parsing_data =
(const struct dbg_idle_chk_rule_parsing_data *)
&s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_PARSING_DATA].
ptr[hdr->rule_id];
parsing_str_offset =
GET_FIELD(rule_parsing_data->data,
DBG_IDLE_CHK_RULE_PARSING_DATA_STR_OFFSET);
has_fw_msg =
GET_FIELD(rule_parsing_data->data,
DBG_IDLE_CHK_RULE_PARSING_DATA_HAS_FW_MSG) > 0;
parsing_str = &((const char *)
s_dbg_arrays[BIN_BUF_DBG_PARSING_STRINGS].ptr)
[parsing_str_offset];
lsi_msg = parsing_str;
if (hdr->severity >= MAX_DBG_IDLE_CHK_SEVERITY_TYPES)
return 0;
dump_buf += (sizeof(struct dbg_idle_chk_result_hdr) / 4);
if (hdr->severity == IDLE_CHK_SEVERITY_ERROR ||
hdr->severity == IDLE_CHK_SEVERITY_ERROR_NO_TRAFFIC)
(*num_errors)++;
else
(*num_warnings)++;
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset), "%s: ",
s_idle_chk_severity_str[hdr->severity]);
if (has_fw_msg)
parsing_str += strlen(parsing_str) + 1;
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset), "%s.",
has_fw_msg &&
print_fw_idle_chk ? parsing_str : lsi_msg);
parsing_str += strlen(parsing_str) + 1;
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset), " Registers:");
for (i = 0;
i < hdr->num_dumped_cond_regs + hdr->num_dumped_info_regs;
i++) {
struct dbg_idle_chk_result_reg_hdr *reg_hdr
= (struct dbg_idle_chk_result_reg_hdr *)
dump_buf;
bool is_mem =
GET_FIELD(reg_hdr->data,
DBG_IDLE_CHK_RESULT_REG_HDR_IS_MEM);
u8 reg_id =
GET_FIELD(reg_hdr->data,
DBG_IDLE_CHK_RESULT_REG_HDR_REG_ID);
dump_buf +=
(sizeof(struct dbg_idle_chk_result_reg_hdr) / 4);
for (; reg_id > curr_reg_id;
curr_reg_id++,
parsing_str += strlen(parsing_str) + 1);
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset), " %s",
parsing_str);
if (i < hdr->num_dumped_cond_regs && is_mem)
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"[%d]", hdr->mem_entry_id +
reg_hdr->start_entry);
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset), "=");
for (j = 0; j < reg_hdr->size; j++, dump_buf++) {
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"0x%x", *dump_buf);
if (j < reg_hdr->size - 1)
results_offset +=
sprintf(qed_get_buf_ptr
(results_buf,
results_offset), ",");
}
}
results_offset +=
sprintf(qed_get_buf_ptr(results_buf, results_offset), "\n");
}
if (dump_buf > dump_buf_end)
return 0;
return results_offset;
}
static enum dbg_status qed_parse_idle_chk_dump(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf,
u32 *parsed_results_bytes,
u32 *num_errors,
u32 *num_warnings)
{
const char *section_name, *param_name, *param_str_val;
u32 *dump_buf_end = dump_buf + num_dumped_dwords;
u32 num_section_params = 0, num_rules;
u32 results_offset = 0;
*parsed_results_bytes = 0;
*num_errors = 0;
*num_warnings = 0;
if (!s_dbg_arrays[BIN_BUF_DBG_PARSING_STRINGS].ptr ||
!s_dbg_arrays[BIN_BUF_DBG_IDLE_CHK_PARSING_DATA].ptr)
return DBG_STATUS_DBG_ARRAY_NOT_SET;
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "global_params"))
return DBG_STATUS_IDLE_CHK_PARSE_FAILED;
dump_buf += qed_print_section_params(dump_buf,
num_section_params,
results_buf, &results_offset);
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "idle_chk") || num_section_params != 1)
return DBG_STATUS_IDLE_CHK_PARSE_FAILED;
dump_buf += qed_read_param(dump_buf,
&param_name, &param_str_val, &num_rules);
if (strcmp(param_name, "num_rules") != 0)
return DBG_STATUS_IDLE_CHK_PARSE_FAILED;
if (num_rules) {
u32 rules_print_size;
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"FW_IDLE_CHECK:\n");
rules_print_size =
qed_parse_idle_chk_dump_rules(p_hwfn, dump_buf,
dump_buf_end, num_rules,
true,
results_buf ?
results_buf +
results_offset : NULL,
num_errors, num_warnings);
results_offset += rules_print_size;
if (rules_print_size == 0)
return DBG_STATUS_IDLE_CHK_PARSE_FAILED;
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"\nLSI_IDLE_CHECK:\n");
rules_print_size =
qed_parse_idle_chk_dump_rules(p_hwfn, dump_buf,
dump_buf_end, num_rules,
false,
results_buf ?
results_buf +
results_offset : NULL,
num_errors, num_warnings);
results_offset += rules_print_size;
if (rules_print_size == 0)
return DBG_STATUS_IDLE_CHK_PARSE_FAILED;
}
if (*num_errors) {
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"\nIdle Check failed!!! (with %d errors and %d warnings)\n",
*num_errors, *num_warnings);
} else if (*num_warnings) {
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"\nIdle Check completed successfuly (with %d warnings)\n",
*num_warnings);
} else {
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"\nIdle Check completed successfuly\n");
}
*parsed_results_bytes = results_offset + 1;
return DBG_STATUS_OK;
}
enum dbg_status qed_get_idle_chk_results_buf_size(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
u32 *results_buf_size)
{
u32 num_errors, num_warnings;
return qed_parse_idle_chk_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
NULL,
results_buf_size,
&num_errors, &num_warnings);
}
enum dbg_status qed_print_idle_chk_results(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf,
u32 *num_errors, u32 *num_warnings)
{
u32 parsed_buf_size;
return qed_parse_idle_chk_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
results_buf,
&parsed_buf_size,
num_errors, num_warnings);
}
static void qed_mcp_trace_free_meta(struct qed_hwfn *p_hwfn,
struct mcp_trace_meta *meta)
{
u32 i;
if (meta->modules) {
for (i = 0; i < meta->modules_num; i++)
kfree(meta->modules[i]);
kfree(meta->modules);
}
if (meta->formats) {
for (i = 0; i < meta->formats_num; i++)
kfree(meta->formats[i].format_str);
kfree(meta->formats);
}
}
static enum dbg_status qed_mcp_trace_alloc_meta(struct qed_hwfn *p_hwfn,
const u32 *meta_buf,
struct mcp_trace_meta *meta)
{
u8 *meta_buf_bytes = (u8 *)meta_buf;
u32 offset = 0, signature, i;
memset(meta, 0, sizeof(*meta));
signature = qed_read_dword_from_buf(meta_buf_bytes, &offset);
if (signature != MCP_TRACE_META_IMAGE_SIGNATURE)
return DBG_STATUS_INVALID_TRACE_SIGNATURE;
meta->modules_num = qed_read_byte_from_buf(meta_buf_bytes, &offset);
meta->modules = kzalloc(meta->modules_num * sizeof(char *), GFP_KERNEL);
if (!meta->modules)
return DBG_STATUS_VIRT_MEM_ALLOC_FAILED;
for (i = 0; i < meta->modules_num; i++) {
u8 module_len = qed_read_byte_from_buf(meta_buf_bytes, &offset);
*(meta->modules + i) = kzalloc(module_len, GFP_KERNEL);
if (!(*(meta->modules + i))) {
meta->modules_num = i ? i - 1 : 0;
return DBG_STATUS_VIRT_MEM_ALLOC_FAILED;
}
qed_read_str_from_buf(meta_buf_bytes, &offset, module_len,
*(meta->modules + i));
if (module_len > MCP_TRACE_MAX_MODULE_LEN)
(*(meta->modules + i))[MCP_TRACE_MAX_MODULE_LEN] = '\0';
}
signature = qed_read_dword_from_buf(meta_buf_bytes, &offset);
if (signature != MCP_TRACE_META_IMAGE_SIGNATURE)
return DBG_STATUS_INVALID_TRACE_SIGNATURE;
meta->formats_num = qed_read_dword_from_buf(meta_buf_bytes, &offset);
meta->formats = kzalloc(meta->formats_num *
sizeof(struct mcp_trace_format),
GFP_KERNEL);
if (!meta->formats)
return DBG_STATUS_VIRT_MEM_ALLOC_FAILED;
for (i = 0; i < meta->formats_num; i++) {
struct mcp_trace_format *format_ptr = &meta->formats[i];
u8 format_len;
format_ptr->data = qed_read_dword_from_buf(meta_buf_bytes,
&offset);
format_len =
(format_ptr->data &
MCP_TRACE_FORMAT_LEN_MASK) >> MCP_TRACE_FORMAT_LEN_SHIFT;
format_ptr->format_str = kzalloc(format_len, GFP_KERNEL);
if (!format_ptr->format_str) {
meta->formats_num = i ? i - 1 : 0;
return DBG_STATUS_VIRT_MEM_ALLOC_FAILED;
}
qed_read_str_from_buf(meta_buf_bytes,
&offset,
format_len, format_ptr->format_str);
}
return DBG_STATUS_OK;
}
static enum dbg_status qed_parse_mcp_trace_dump(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf,
u32 *parsed_results_bytes)
{
u32 results_offset = 0, param_mask, param_shift, param_num_val;
u32 num_section_params, offset, end_offset, bytes_left;
const char *section_name, *param_name, *param_str_val;
u32 trace_data_dwords, trace_meta_dwords;
struct mcp_trace_meta meta;
struct mcp_trace *trace;
enum dbg_status status;
const u32 *meta_buf;
u8 *trace_buf;
*parsed_results_bytes = 0;
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "global_params"))
return DBG_STATUS_MCP_TRACE_BAD_DATA;
dump_buf += qed_print_section_params(dump_buf,
num_section_params,
results_buf, &results_offset);
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "mcp_trace_data") || num_section_params != 1)
return DBG_STATUS_MCP_TRACE_BAD_DATA;
dump_buf += qed_read_param(dump_buf,
&param_name, &param_str_val, &param_num_val);
if (strcmp(param_name, "size"))
return DBG_STATUS_MCP_TRACE_BAD_DATA;
trace_data_dwords = param_num_val;
trace = (struct mcp_trace *)dump_buf;
trace_buf = (u8 *)dump_buf + sizeof(struct mcp_trace);
offset = trace->trace_oldest;
end_offset = trace->trace_prod;
bytes_left = qed_cyclic_sub(end_offset, offset, trace->size);
dump_buf += trace_data_dwords;
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "mcp_trace_meta"))
return DBG_STATUS_MCP_TRACE_BAD_DATA;
dump_buf += qed_read_param(dump_buf,
&param_name, &param_str_val, &param_num_val);
if (strcmp(param_name, "size") != 0)
return DBG_STATUS_MCP_TRACE_BAD_DATA;
trace_meta_dwords = param_num_val;
if (!trace_meta_dwords) {
if (!s_mcp_trace_meta.ptr)
return DBG_STATUS_MCP_TRACE_NO_META;
meta_buf = s_mcp_trace_meta.ptr;
} else {
meta_buf = dump_buf;
}
status = qed_mcp_trace_alloc_meta(p_hwfn, meta_buf, &meta);
if (status != DBG_STATUS_OK)
goto free_mem;
while (bytes_left) {
struct mcp_trace_format *format_ptr;
u8 format_level, format_module;
u32 params[3] = { 0, 0, 0 };
u32 header, format_idx, i;
if (bytes_left < MFW_TRACE_ENTRY_SIZE) {
status = DBG_STATUS_MCP_TRACE_BAD_DATA;
goto free_mem;
}
header = qed_read_from_cyclic_buf(trace_buf,
&offset,
trace->size,
MFW_TRACE_ENTRY_SIZE);
bytes_left -= MFW_TRACE_ENTRY_SIZE;
format_idx = header & MFW_TRACE_EVENTID_MASK;
if (format_idx > meta.formats_num) {
u8 format_size =
(u8)((header &
MFW_TRACE_PRM_SIZE_MASK) >>
MFW_TRACE_PRM_SIZE_SHIFT);
if (bytes_left < format_size) {
status = DBG_STATUS_MCP_TRACE_BAD_DATA;
goto free_mem;
}
offset = qed_cyclic_add(offset,
format_size, trace->size);
bytes_left -= format_size;
continue;
}
format_ptr = &meta.formats[format_idx];
for (i = 0,
param_mask = MCP_TRACE_FORMAT_P1_SIZE_MASK, param_shift =
MCP_TRACE_FORMAT_P1_SIZE_SHIFT;
i < MCP_TRACE_FORMAT_MAX_PARAMS;
i++, param_mask <<= MCP_TRACE_FORMAT_PARAM_WIDTH,
param_shift += MCP_TRACE_FORMAT_PARAM_WIDTH) {
u8 param_size =
(u8)((format_ptr->data &
param_mask) >> param_shift);
if (!param_size)
break;
if (param_size == 3)
param_size = 4;
if (bytes_left < param_size) {
status = DBG_STATUS_MCP_TRACE_BAD_DATA;
goto free_mem;
}
params[i] = qed_read_from_cyclic_buf(trace_buf,
&offset,
trace->size,
param_size);
bytes_left -= param_size;
}
format_level =
(u8)((format_ptr->data &
MCP_TRACE_FORMAT_LEVEL_MASK) >>
MCP_TRACE_FORMAT_LEVEL_SHIFT);
format_module =
(u8)((format_ptr->data &
MCP_TRACE_FORMAT_MODULE_MASK) >>
MCP_TRACE_FORMAT_MODULE_SHIFT);
if (format_level >= ARRAY_SIZE(s_mcp_trace_level_str)) {
status = DBG_STATUS_MCP_TRACE_BAD_DATA;
goto free_mem;
}
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset), "%s %-8s: ",
s_mcp_trace_level_str[format_level],
meta.modules[format_module]);
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
format_ptr->format_str, params[0], params[1],
params[2]);
}
free_mem:
*parsed_results_bytes = results_offset + 1;
qed_mcp_trace_free_meta(p_hwfn, &meta);
return status;
}
enum dbg_status qed_get_mcp_trace_results_buf_size(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
u32 *results_buf_size)
{
return qed_parse_mcp_trace_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
NULL, results_buf_size);
}
enum dbg_status qed_print_mcp_trace_results(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf)
{
u32 parsed_buf_size;
return qed_parse_mcp_trace_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
results_buf, &parsed_buf_size);
}
static enum dbg_status qed_parse_reg_fifo_dump(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf,
u32 *parsed_results_bytes)
{
u32 results_offset = 0, param_num_val, num_section_params, num_elements;
const char *section_name, *param_name, *param_str_val;
struct reg_fifo_element *elements;
u8 i, j, err_val, vf_val;
char vf_str[4];
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "global_params"))
return DBG_STATUS_REG_FIFO_BAD_DATA;
dump_buf += qed_print_section_params(dump_buf,
num_section_params,
results_buf, &results_offset);
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "reg_fifo_data"))
return DBG_STATUS_REG_FIFO_BAD_DATA;
dump_buf += qed_read_param(dump_buf,
&param_name, &param_str_val, &param_num_val);
if (strcmp(param_name, "size"))
return DBG_STATUS_REG_FIFO_BAD_DATA;
if (param_num_val % REG_FIFO_ELEMENT_DWORDS)
return DBG_STATUS_REG_FIFO_BAD_DATA;
num_elements = param_num_val / REG_FIFO_ELEMENT_DWORDS;
elements = (struct reg_fifo_element *)dump_buf;
for (i = 0; i < num_elements; i++) {
bool err_printed = false;
vf_val = GET_FIELD(elements[i].data, REG_FIFO_ELEMENT_VF);
if (vf_val == REG_FIFO_ELEMENT_IS_PF_VF_VAL)
sprintf(vf_str, "%s", "N/A");
else
sprintf(vf_str, "%d", vf_val);
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"raw: 0x%016llx, address: 0x%07x, access: %-5s, pf: %2d, vf: %s, port: %d, privilege: %-3s, protection: %-12s, master: %-4s, errors: ",
elements[i].data,
(u32)GET_FIELD(elements[i].data,
REG_FIFO_ELEMENT_ADDRESS) *
REG_FIFO_ELEMENT_ADDR_FACTOR,
s_access_strs[GET_FIELD(elements[i].data,
REG_FIFO_ELEMENT_ACCESS)],
(u32)GET_FIELD(elements[i].data,
REG_FIFO_ELEMENT_PF), vf_str,
(u32)GET_FIELD(elements[i].data,
REG_FIFO_ELEMENT_PORT),
s_privilege_strs[GET_FIELD(elements[i].
data,
REG_FIFO_ELEMENT_PRIVILEGE)],
s_protection_strs[GET_FIELD(elements[i].data,
REG_FIFO_ELEMENT_PROTECTION)],
s_master_strs[GET_FIELD(elements[i].data,
REG_FIFO_ELEMENT_MASTER)]);
for (j = 0,
err_val = GET_FIELD(elements[i].data,
REG_FIFO_ELEMENT_ERROR);
j < ARRAY_SIZE(s_reg_fifo_error_strs);
j++, err_val >>= 1) {
if (!(err_val & 0x1))
continue;
if (err_printed)
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
", ");
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset), "%s",
s_reg_fifo_error_strs[j]);
err_printed = true;
}
results_offset +=
sprintf(qed_get_buf_ptr(results_buf, results_offset), "\n");
}
results_offset += sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"fifo contained %d elements", num_elements);
*parsed_results_bytes = results_offset + 1;
return DBG_STATUS_OK;
}
enum dbg_status qed_get_reg_fifo_results_buf_size(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
u32 *results_buf_size)
{
return qed_parse_reg_fifo_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
NULL, results_buf_size);
}
enum dbg_status qed_print_reg_fifo_results(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf)
{
u32 parsed_buf_size;
return qed_parse_reg_fifo_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
results_buf, &parsed_buf_size);
}
static enum dbg_status qed_parse_igu_fifo_dump(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf,
u32 *parsed_results_bytes)
{
u32 results_offset = 0, param_num_val, num_section_params, num_elements;
const char *section_name, *param_name, *param_str_val;
struct igu_fifo_element *elements;
char parsed_addr_data[32];
char parsed_wr_data[256];
u8 i, j;
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "global_params"))
return DBG_STATUS_IGU_FIFO_BAD_DATA;
dump_buf += qed_print_section_params(dump_buf,
num_section_params,
results_buf, &results_offset);
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "igu_fifo_data"))
return DBG_STATUS_IGU_FIFO_BAD_DATA;
dump_buf += qed_read_param(dump_buf,
&param_name, &param_str_val, &param_num_val);
if (strcmp(param_name, "size"))
return DBG_STATUS_IGU_FIFO_BAD_DATA;
if (param_num_val % IGU_FIFO_ELEMENT_DWORDS)
return DBG_STATUS_IGU_FIFO_BAD_DATA;
num_elements = param_num_val / IGU_FIFO_ELEMENT_DWORDS;
elements = (struct igu_fifo_element *)dump_buf;
for (i = 0; i < num_elements; i++) {
u64 dword12 =
((u64)elements[i].dword2 << 32) | elements[i].dword1;
bool is_wr_cmd = GET_FIELD(dword12,
IGU_FIFO_ELEMENT_DWORD12_IS_WR_CMD);
bool is_pf = GET_FIELD(elements[i].dword0,
IGU_FIFO_ELEMENT_DWORD0_IS_PF);
u16 cmd_addr = GET_FIELD(elements[i].dword0,
IGU_FIFO_ELEMENT_DWORD0_CMD_ADDR);
u8 source = GET_FIELD(elements[i].dword0,
IGU_FIFO_ELEMENT_DWORD0_SOURCE);
u8 err_type = GET_FIELD(elements[i].dword0,
IGU_FIFO_ELEMENT_DWORD0_ERR_TYPE);
const struct igu_fifo_addr_data *addr_data = NULL;
if (source >= ARRAY_SIZE(s_igu_fifo_source_strs))
return DBG_STATUS_IGU_FIFO_BAD_DATA;
if (err_type >= ARRAY_SIZE(s_igu_fifo_error_strs))
return DBG_STATUS_IGU_FIFO_BAD_DATA;
for (j = 0; j < ARRAY_SIZE(s_igu_fifo_addr_data) && !addr_data;
j++)
if (cmd_addr >= s_igu_fifo_addr_data[j].start_addr &&
cmd_addr <= s_igu_fifo_addr_data[j].end_addr)
addr_data = &s_igu_fifo_addr_data[j];
if (!addr_data)
return DBG_STATUS_IGU_FIFO_BAD_DATA;
switch (addr_data->type) {
case IGU_ADDR_TYPE_MSIX_MEM:
sprintf(parsed_addr_data,
" vector_num=0x%x", cmd_addr / 2);
break;
case IGU_ADDR_TYPE_WRITE_INT_ACK:
case IGU_ADDR_TYPE_WRITE_PROD_UPDATE:
sprintf(parsed_addr_data,
" SB=0x%x", cmd_addr - addr_data->start_addr);
break;
default:
parsed_addr_data[0] = '\0';
}
if (is_wr_cmd) {
u32 wr_data = GET_FIELD(dword12,
IGU_FIFO_ELEMENT_DWORD12_WR_DATA);
u32 prod_cons = GET_FIELD(wr_data,
IGU_FIFO_WR_DATA_PROD_CONS);
u8 is_cleanup = GET_FIELD(wr_data,
IGU_FIFO_WR_DATA_CMD_TYPE);
if (source == IGU_SRC_ATTN) {
sprintf(parsed_wr_data,
"prod: 0x%x, ", prod_cons);
} else {
if (is_cleanup) {
u8 cleanup_val = GET_FIELD(wr_data,
IGU_FIFO_CLEANUP_WR_DATA_CLEANUP_VAL);
u8 cleanup_type = GET_FIELD(wr_data,
IGU_FIFO_CLEANUP_WR_DATA_CLEANUP_TYPE);
sprintf(parsed_wr_data,
"cmd_type: cleanup, cleanup_val: %s, cleanup_type: %d, ",
cleanup_val ? "set" : "clear",
cleanup_type);
} else {
u8 update_flag = GET_FIELD(wr_data,
IGU_FIFO_WR_DATA_UPDATE_FLAG);
u8 en_dis_int_for_sb =
GET_FIELD(wr_data,
IGU_FIFO_WR_DATA_EN_DIS_INT_FOR_SB);
u8 segment = GET_FIELD(wr_data,
IGU_FIFO_WR_DATA_SEGMENT);
u8 timer_mask = GET_FIELD(wr_data,
IGU_FIFO_WR_DATA_TIMER_MASK);
sprintf(parsed_wr_data,
"cmd_type: prod/cons update, prod/cons: 0x%x, update_flag: %s, en_dis_int_for_sb: %s, segment: %s, timer_mask=%d, ",
prod_cons,
update_flag ? "update" : "nop",
en_dis_int_for_sb
? (en_dis_int_for_sb ==
1 ? "disable" : "nop") :
"enable",
segment ? "attn" : "regular",
timer_mask);
}
}
} else {
parsed_wr_data[0] = '\0';
}
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"raw: 0x%01x%08x%08x, %s: %d, source: %s, type: %s, cmd_addr: 0x%x (%s%s), %serror: %s\n",
elements[i].dword2, elements[i].dword1,
elements[i].dword0,
is_pf ? "pf" : "vf",
GET_FIELD(elements[i].dword0,
IGU_FIFO_ELEMENT_DWORD0_FID),
s_igu_fifo_source_strs[source],
is_wr_cmd ? "wr" : "rd", cmd_addr,
(!is_pf && addr_data->vf_desc)
? addr_data->vf_desc : addr_data->desc,
parsed_addr_data, parsed_wr_data,
s_igu_fifo_error_strs[err_type]);
}
results_offset += sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"fifo contained %d elements", num_elements);
*parsed_results_bytes = results_offset + 1;
return DBG_STATUS_OK;
}
enum dbg_status qed_get_igu_fifo_results_buf_size(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
u32 *results_buf_size)
{
return qed_parse_igu_fifo_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
NULL, results_buf_size);
}
enum dbg_status qed_print_igu_fifo_results(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf)
{
u32 parsed_buf_size;
return qed_parse_igu_fifo_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
results_buf, &parsed_buf_size);
}
static enum dbg_status
qed_parse_protection_override_dump(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf,
u32 *parsed_results_bytes)
{
u32 results_offset = 0, param_num_val, num_section_params, num_elements;
const char *section_name, *param_name, *param_str_val;
struct protection_override_element *elements;
u8 i;
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "global_params"))
return DBG_STATUS_PROTECTION_OVERRIDE_BAD_DATA;
dump_buf += qed_print_section_params(dump_buf,
num_section_params,
results_buf, &results_offset);
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "protection_override_data"))
return DBG_STATUS_PROTECTION_OVERRIDE_BAD_DATA;
dump_buf += qed_read_param(dump_buf,
&param_name, &param_str_val, &param_num_val);
if (strcmp(param_name, "size"))
return DBG_STATUS_PROTECTION_OVERRIDE_BAD_DATA;
if (param_num_val % PROTECTION_OVERRIDE_ELEMENT_DWORDS != 0)
return DBG_STATUS_PROTECTION_OVERRIDE_BAD_DATA;
num_elements = param_num_val / PROTECTION_OVERRIDE_ELEMENT_DWORDS;
elements = (struct protection_override_element *)dump_buf;
for (i = 0; i < num_elements; i++) {
u32 address = GET_FIELD(elements[i].data,
PROTECTION_OVERRIDE_ELEMENT_ADDRESS) *
PROTECTION_OVERRIDE_ELEMENT_ADDR_FACTOR;
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"window %2d, address: 0x%07x, size: %7d regs, read: %d, write: %d, read protection: %-12s, write protection: %-12s\n",
i, address,
(u32)GET_FIELD(elements[i].data,
PROTECTION_OVERRIDE_ELEMENT_WINDOW_SIZE),
(u32)GET_FIELD(elements[i].data,
PROTECTION_OVERRIDE_ELEMENT_READ),
(u32)GET_FIELD(elements[i].data,
PROTECTION_OVERRIDE_ELEMENT_WRITE),
s_protection_strs[GET_FIELD(elements[i].data,
PROTECTION_OVERRIDE_ELEMENT_READ_PROTECTION)],
s_protection_strs[GET_FIELD(elements[i].data,
PROTECTION_OVERRIDE_ELEMENT_WRITE_PROTECTION)]);
}
results_offset += sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"protection override contained %d elements",
num_elements);
*parsed_results_bytes = results_offset + 1;
return DBG_STATUS_OK;
}
enum dbg_status
qed_get_protection_override_results_buf_size(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
u32 *results_buf_size)
{
return qed_parse_protection_override_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
NULL, results_buf_size);
}
enum dbg_status qed_print_protection_override_results(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf)
{
u32 parsed_buf_size;
return qed_parse_protection_override_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
results_buf,
&parsed_buf_size);
}
static enum dbg_status qed_parse_fw_asserts_dump(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf,
u32 *parsed_results_bytes)
{
u32 results_offset = 0, num_section_params, param_num_val, i;
const char *param_name, *param_str_val, *section_name;
bool last_section_found = false;
*parsed_results_bytes = 0;
dump_buf += qed_read_section_hdr(dump_buf,
&section_name, &num_section_params);
if (strcmp(section_name, "global_params"))
return DBG_STATUS_FW_ASSERTS_PARSE_FAILED;
dump_buf += qed_print_section_params(dump_buf,
num_section_params,
results_buf, &results_offset);
while (!last_section_found) {
const char *storm_letter = NULL;
u32 storm_dump_size = 0;
dump_buf += qed_read_section_hdr(dump_buf,
&section_name,
&num_section_params);
if (!strcmp(section_name, "last")) {
last_section_found = true;
continue;
} else if (strcmp(section_name, "fw_asserts")) {
return DBG_STATUS_FW_ASSERTS_PARSE_FAILED;
}
for (i = 0; i < num_section_params; i++) {
dump_buf += qed_read_param(dump_buf,
&param_name,
&param_str_val,
&param_num_val);
if (!strcmp(param_name, "storm"))
storm_letter = param_str_val;
else if (!strcmp(param_name, "size"))
storm_dump_size = param_num_val;
else
return DBG_STATUS_FW_ASSERTS_PARSE_FAILED;
}
if (!storm_letter || !storm_dump_size)
return DBG_STATUS_FW_ASSERTS_PARSE_FAILED;
results_offset += sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"\n%sSTORM_ASSERT: size=%d\n",
storm_letter, storm_dump_size);
for (i = 0; i < storm_dump_size; i++, dump_buf++)
results_offset +=
sprintf(qed_get_buf_ptr(results_buf,
results_offset),
"%08x\n", *dump_buf);
}
*parsed_results_bytes = results_offset + 1;
return DBG_STATUS_OK;
}
enum dbg_status qed_get_fw_asserts_results_buf_size(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
u32 *results_buf_size)
{
return qed_parse_fw_asserts_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
NULL, results_buf_size);
}
enum dbg_status qed_print_fw_asserts_results(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf)
{
u32 parsed_buf_size;
return qed_parse_fw_asserts_dump(p_hwfn,
dump_buf,
num_dumped_dwords,
results_buf, &parsed_buf_size);
}
static enum dbg_status
qed_print_idle_chk_results_wrapper(struct qed_hwfn *p_hwfn,
u32 *dump_buf,
u32 num_dumped_dwords,
char *results_buf)
{
u32 num_errors, num_warnnings;
return qed_print_idle_chk_results(p_hwfn, dump_buf, num_dumped_dwords,
results_buf, &num_errors,
&num_warnnings);
}
static void qed_dbg_print_feature(u8 *p_text_buf, u32 text_size)
{
u32 i, precision = 80;
if (!p_text_buf)
return;
pr_notice("\n%.*s", precision, p_text_buf);
for (i = precision; i < text_size; i += precision)
pr_cont("%.*s", precision, p_text_buf + i);
pr_cont("\n");
}
static enum dbg_status format_feature(struct qed_hwfn *p_hwfn,
enum qed_dbg_features feature_idx)
{
struct qed_dbg_feature *feature =
&p_hwfn->cdev->dbg_params.features[feature_idx];
u32 text_size_bytes, null_char_pos, i;
enum dbg_status rc;
char *text_buf;
if (!qed_features_lookup[feature_idx].results_buf_size)
return DBG_STATUS_OK;
rc = qed_features_lookup[feature_idx].
results_buf_size(p_hwfn, (u32 *)feature->dump_buf,
feature->dumped_dwords, &text_size_bytes);
if (rc != DBG_STATUS_OK)
return rc;
null_char_pos = text_size_bytes - 1;
text_size_bytes = (text_size_bytes + 3) & ~0x3;
if (text_size_bytes < QED_RESULTS_BUF_MIN_SIZE) {
DP_NOTICE(p_hwfn->cdev,
"formatted size of feature was too small %d. Aborting\n",
text_size_bytes);
return DBG_STATUS_INVALID_ARGS;
}
text_buf = vzalloc(text_size_bytes);
if (!text_buf)
return DBG_STATUS_VIRT_MEM_ALLOC_FAILED;
rc = qed_features_lookup[feature_idx].
print_results(p_hwfn, (u32 *)feature->dump_buf,
feature->dumped_dwords, text_buf);
if (rc != DBG_STATUS_OK) {
vfree(text_buf);
return rc;
}
for (i = null_char_pos; i < text_size_bytes; i++)
text_buf[i] = '\n';
if (p_hwfn->cdev->dbg_params.print_data)
qed_dbg_print_feature(text_buf, text_size_bytes);
vfree(feature->dump_buf);
feature->dump_buf = text_buf;
feature->buf_size = text_size_bytes;
feature->dumped_dwords = text_size_bytes / 4;
return rc;
}
static enum dbg_status qed_dbg_dump(struct qed_hwfn *p_hwfn,
struct qed_ptt *p_ptt,
enum qed_dbg_features feature_idx)
{
struct qed_dbg_feature *feature =
&p_hwfn->cdev->dbg_params.features[feature_idx];
u32 buf_size_dwords;
enum dbg_status rc;
DP_NOTICE(p_hwfn->cdev, "Collecting a debug feature [\"%s\"]\n",
qed_features_lookup[feature_idx].name);
if (feature->dump_buf) {
vfree(feature->dump_buf);
feature->dump_buf = NULL;
}
rc = qed_features_lookup[feature_idx].get_size(p_hwfn, p_ptt,
&buf_size_dwords);
if (rc != DBG_STATUS_OK && rc != DBG_STATUS_NVRAM_GET_IMAGE_FAILED)
return rc;
feature->buf_size = buf_size_dwords * sizeof(u32);
feature->dump_buf = vmalloc(feature->buf_size);
if (!feature->dump_buf)
return DBG_STATUS_VIRT_MEM_ALLOC_FAILED;
rc = qed_features_lookup[feature_idx].
perform_dump(p_hwfn, p_ptt, (u32 *)feature->dump_buf,
feature->buf_size / sizeof(u32),
&feature->dumped_dwords);
if (rc == DBG_STATUS_NVRAM_GET_IMAGE_FAILED)
return DBG_STATUS_OK;
if (rc != DBG_STATUS_OK)
return rc;
rc = format_feature(p_hwfn, feature_idx);
return rc;
}
int qed_dbg_grc(struct qed_dev *cdev, void *buffer, u32 *num_dumped_bytes)
{
return qed_dbg_feature(cdev, buffer, DBG_FEATURE_GRC, num_dumped_bytes);
}
int qed_dbg_grc_size(struct qed_dev *cdev)
{
return qed_dbg_feature_size(cdev, DBG_FEATURE_GRC);
}
int qed_dbg_idle_chk(struct qed_dev *cdev, void *buffer, u32 *num_dumped_bytes)
{
return qed_dbg_feature(cdev, buffer, DBG_FEATURE_IDLE_CHK,
num_dumped_bytes);
}
int qed_dbg_idle_chk_size(struct qed_dev *cdev)
{
return qed_dbg_feature_size(cdev, DBG_FEATURE_IDLE_CHK);
}
int qed_dbg_reg_fifo(struct qed_dev *cdev, void *buffer, u32 *num_dumped_bytes)
{
return qed_dbg_feature(cdev, buffer, DBG_FEATURE_REG_FIFO,
num_dumped_bytes);
}
int qed_dbg_reg_fifo_size(struct qed_dev *cdev)
{
return qed_dbg_feature_size(cdev, DBG_FEATURE_REG_FIFO);
}
int qed_dbg_igu_fifo(struct qed_dev *cdev, void *buffer, u32 *num_dumped_bytes)
{
return qed_dbg_feature(cdev, buffer, DBG_FEATURE_IGU_FIFO,
num_dumped_bytes);
}
int qed_dbg_igu_fifo_size(struct qed_dev *cdev)
{
return qed_dbg_feature_size(cdev, DBG_FEATURE_IGU_FIFO);
}
int qed_dbg_protection_override(struct qed_dev *cdev, void *buffer,
u32 *num_dumped_bytes)
{
return qed_dbg_feature(cdev, buffer, DBG_FEATURE_PROTECTION_OVERRIDE,
num_dumped_bytes);
}
int qed_dbg_protection_override_size(struct qed_dev *cdev)
{
return qed_dbg_feature_size(cdev, DBG_FEATURE_PROTECTION_OVERRIDE);
}
int qed_dbg_fw_asserts(struct qed_dev *cdev, void *buffer,
u32 *num_dumped_bytes)
{
return qed_dbg_feature(cdev, buffer, DBG_FEATURE_FW_ASSERTS,
num_dumped_bytes);
}
int qed_dbg_fw_asserts_size(struct qed_dev *cdev)
{
return qed_dbg_feature_size(cdev, DBG_FEATURE_FW_ASSERTS);
}
int qed_dbg_mcp_trace(struct qed_dev *cdev, void *buffer,
u32 *num_dumped_bytes)
{
return qed_dbg_feature(cdev, buffer, DBG_FEATURE_MCP_TRACE,
num_dumped_bytes);
}
int qed_dbg_mcp_trace_size(struct qed_dev *cdev)
{
return qed_dbg_feature_size(cdev, DBG_FEATURE_MCP_TRACE);
}
static u32 qed_calc_regdump_header(enum debug_print_features feature,
int engine, u32 feature_size, u8 omit_engine)
{
return feature_size | (feature << REGDUMP_HEADER_FEATURE_SHIFT) |
(omit_engine << REGDUMP_HEADER_OMIT_ENGINE_SHIFT) |
(engine << REGDUMP_HEADER_ENGINE_SHIFT);
}
int qed_dbg_all_data(struct qed_dev *cdev, void *buffer)
{
u8 cur_engine, omit_engine = 0, org_engine;
u32 offset = 0, feature_size;
int rc;
if (cdev->num_hwfns == 1)
omit_engine = 1;
org_engine = qed_get_debug_engine(cdev);
for (cur_engine = 0; cur_engine < cdev->num_hwfns; cur_engine++) {
DP_VERBOSE(cdev, QED_MSG_DEBUG,
"obtaining idle_chk and grcdump for current engine\n");
qed_set_debug_engine(cdev, cur_engine);
rc = qed_dbg_idle_chk(cdev, (u8 *)buffer + offset +
REGDUMP_HEADER_SIZE, &feature_size);
if (!rc) {
*(u32 *)((u8 *)buffer + offset) =
qed_calc_regdump_header(IDLE_CHK, cur_engine,
feature_size, omit_engine);
offset += (feature_size + REGDUMP_HEADER_SIZE);
} else {
DP_ERR(cdev, "qed_dbg_idle_chk failed. rc = %d\n", rc);
}
rc = qed_dbg_idle_chk(cdev, (u8 *)buffer + offset +
REGDUMP_HEADER_SIZE, &feature_size);
if (!rc) {
*(u32 *)((u8 *)buffer + offset) =
qed_calc_regdump_header(IDLE_CHK, cur_engine,
feature_size, omit_engine);
offset += (feature_size + REGDUMP_HEADER_SIZE);
} else {
DP_ERR(cdev, "qed_dbg_idle_chk failed. rc = %d\n", rc);
}
rc = qed_dbg_reg_fifo(cdev, (u8 *)buffer + offset +
REGDUMP_HEADER_SIZE, &feature_size);
if (!rc) {
*(u32 *)((u8 *)buffer + offset) =
qed_calc_regdump_header(REG_FIFO, cur_engine,
feature_size, omit_engine);
offset += (feature_size + REGDUMP_HEADER_SIZE);
} else {
DP_ERR(cdev, "qed_dbg_reg_fifo failed. rc = %d\n", rc);
}
rc = qed_dbg_igu_fifo(cdev, (u8 *)buffer + offset +
REGDUMP_HEADER_SIZE, &feature_size);
if (!rc) {
*(u32 *)((u8 *)buffer + offset) =
qed_calc_regdump_header(IGU_FIFO, cur_engine,
feature_size, omit_engine);
offset += (feature_size + REGDUMP_HEADER_SIZE);
} else {
DP_ERR(cdev, "qed_dbg_igu_fifo failed. rc = %d", rc);
}
rc = qed_dbg_protection_override(cdev, (u8 *)buffer + offset +
REGDUMP_HEADER_SIZE,
&feature_size);
if (!rc) {
*(u32 *)((u8 *)buffer + offset) =
qed_calc_regdump_header(PROTECTION_OVERRIDE,
cur_engine,
feature_size, omit_engine);
offset += (feature_size + REGDUMP_HEADER_SIZE);
} else {
DP_ERR(cdev,
"qed_dbg_protection_override failed. rc = %d\n",
rc);
}
rc = qed_dbg_fw_asserts(cdev, (u8 *)buffer + offset +
REGDUMP_HEADER_SIZE, &feature_size);
if (!rc) {
*(u32 *)((u8 *)buffer + offset) =
qed_calc_regdump_header(FW_ASSERTS, cur_engine,
feature_size, omit_engine);
offset += (feature_size + REGDUMP_HEADER_SIZE);
} else {
DP_ERR(cdev, "qed_dbg_fw_asserts failed. rc = %d\n",
rc);
}
rc = qed_dbg_grc(cdev, (u8 *)buffer + offset +
REGDUMP_HEADER_SIZE, &feature_size);
if (!rc) {
*(u32 *)((u8 *)buffer + offset) =
qed_calc_regdump_header(GRC_DUMP, cur_engine,
feature_size, omit_engine);
offset += (feature_size + REGDUMP_HEADER_SIZE);
} else {
DP_ERR(cdev, "qed_dbg_grc failed. rc = %d", rc);
}
}
rc = qed_dbg_mcp_trace(cdev, (u8 *)buffer + offset +
REGDUMP_HEADER_SIZE, &feature_size);
if (!rc) {
*(u32 *)((u8 *)buffer + offset) =
qed_calc_regdump_header(MCP_TRACE, cur_engine,
feature_size, omit_engine);
offset += (feature_size + REGDUMP_HEADER_SIZE);
} else {
DP_ERR(cdev, "qed_dbg_mcp_trace failed. rc = %d\n", rc);
}
qed_set_debug_engine(cdev, org_engine);
return 0;
}
int qed_dbg_all_data_size(struct qed_dev *cdev)
{
u8 cur_engine, org_engine;
u32 regs_len = 0;
org_engine = qed_get_debug_engine(cdev);
for (cur_engine = 0; cur_engine < cdev->num_hwfns; cur_engine++) {
DP_VERBOSE(cdev, QED_MSG_DEBUG,
"calculating idle_chk and grcdump register length for current engine\n");
qed_set_debug_engine(cdev, cur_engine);
regs_len += REGDUMP_HEADER_SIZE + qed_dbg_idle_chk_size(cdev) +
REGDUMP_HEADER_SIZE + qed_dbg_idle_chk_size(cdev) +
REGDUMP_HEADER_SIZE + qed_dbg_grc_size(cdev) +
REGDUMP_HEADER_SIZE + qed_dbg_reg_fifo_size(cdev) +
REGDUMP_HEADER_SIZE + qed_dbg_igu_fifo_size(cdev) +
REGDUMP_HEADER_SIZE +
qed_dbg_protection_override_size(cdev) +
REGDUMP_HEADER_SIZE + qed_dbg_fw_asserts_size(cdev);
}
regs_len += REGDUMP_HEADER_SIZE + qed_dbg_mcp_trace_size(cdev);
qed_set_debug_engine(cdev, org_engine);
return regs_len;
}
int qed_dbg_feature(struct qed_dev *cdev, void *buffer,
enum qed_dbg_features feature, u32 *num_dumped_bytes)
{
struct qed_hwfn *p_hwfn =
&cdev->hwfns[cdev->dbg_params.engine_for_debug];
struct qed_dbg_feature *qed_feature =
&cdev->dbg_params.features[feature];
enum dbg_status dbg_rc;
struct qed_ptt *p_ptt;
int rc = 0;
p_ptt = qed_ptt_acquire(p_hwfn);
if (!p_ptt)
return -EINVAL;
dbg_rc = qed_dbg_dump(p_hwfn, p_ptt, feature);
if (dbg_rc != DBG_STATUS_OK) {
DP_VERBOSE(cdev, QED_MSG_DEBUG, "%s\n",
qed_dbg_get_status_str(dbg_rc));
*num_dumped_bytes = 0;
rc = -EINVAL;
goto out;
}
DP_VERBOSE(cdev, QED_MSG_DEBUG,
"copying debugfs feature to external buffer\n");
memcpy(buffer, qed_feature->dump_buf, qed_feature->buf_size);
*num_dumped_bytes = cdev->dbg_params.features[feature].dumped_dwords *
4;
out:
qed_ptt_release(p_hwfn, p_ptt);
return rc;
}
int qed_dbg_feature_size(struct qed_dev *cdev, enum qed_dbg_features feature)
{
struct qed_hwfn *p_hwfn =
&cdev->hwfns[cdev->dbg_params.engine_for_debug];
struct qed_ptt *p_ptt = qed_ptt_acquire(p_hwfn);
struct qed_dbg_feature *qed_feature =
&cdev->dbg_params.features[feature];
u32 buf_size_dwords;
enum dbg_status rc;
if (!p_ptt)
return -EINVAL;
rc = qed_features_lookup[feature].get_size(p_hwfn, p_ptt,
&buf_size_dwords);
if (rc != DBG_STATUS_OK)
buf_size_dwords = 0;
qed_ptt_release(p_hwfn, p_ptt);
qed_feature->buf_size = buf_size_dwords * sizeof(u32);
return qed_feature->buf_size;
}
u8 qed_get_debug_engine(struct qed_dev *cdev)
{
return cdev->dbg_params.engine_for_debug;
}
void qed_set_debug_engine(struct qed_dev *cdev, int engine_number)
{
DP_VERBOSE(cdev, QED_MSG_DEBUG, "set debug engine to %d\n",
engine_number);
cdev->dbg_params.engine_for_debug = engine_number;
}
void qed_dbg_pf_init(struct qed_dev *cdev)
{
const u8 *dbg_values;
dbg_values = cdev->firmware->data + *(u32 *)cdev->firmware->data;
qed_dbg_set_bin_ptr((u8 *)dbg_values);
qed_dbg_user_set_bin_ptr((u8 *)dbg_values);
}
void qed_dbg_pf_exit(struct qed_dev *cdev)
{
struct qed_dbg_feature *feature = NULL;
enum qed_dbg_features feature_idx;
for (feature_idx = 0; feature_idx < DBG_FEATURE_NUM; feature_idx++) {
feature = &cdev->dbg_params.features[feature_idx];
if (feature->dump_buf) {
vfree(feature->dump_buf);
feature->dump_buf = NULL;
}
}
}
