static u64 i40e_align_l2obj_base(u64 offset)
{
u64 aligned_offset = offset;
if ((offset % I40E_HMC_L2OBJ_BASE_ALIGNMENT) > 0)
aligned_offset += (I40E_HMC_L2OBJ_BASE_ALIGNMENT -
(offset % I40E_HMC_L2OBJ_BASE_ALIGNMENT));
return aligned_offset;
}
static u64 i40e_calculate_l2fpm_size(u32 txq_num, u32 rxq_num,
u32 fcoe_cntx_num, u32 fcoe_filt_num)
{
u64 fpm_size = 0;
fpm_size = txq_num * I40E_HMC_OBJ_SIZE_TXQ;
fpm_size = i40e_align_l2obj_base(fpm_size);
fpm_size += (rxq_num * I40E_HMC_OBJ_SIZE_RXQ);
fpm_size = i40e_align_l2obj_base(fpm_size);
fpm_size += (fcoe_cntx_num * I40E_HMC_OBJ_SIZE_FCOE_CNTX);
fpm_size = i40e_align_l2obj_base(fpm_size);
fpm_size += (fcoe_filt_num * I40E_HMC_OBJ_SIZE_FCOE_FILT);
fpm_size = i40e_align_l2obj_base(fpm_size);
return fpm_size;
}
i40e_status i40e_init_lan_hmc(struct i40e_hw *hw, u32 txq_num,
u32 rxq_num, u32 fcoe_cntx_num,
u32 fcoe_filt_num)
{
struct i40e_hmc_obj_info *obj, *full_obj;
i40e_status ret_code = 0;
u64 l2fpm_size;
u32 size_exp;
hw->hmc.signature = I40E_HMC_INFO_SIGNATURE;
hw->hmc.hmc_fn_id = hw->pf_id;
ret_code = i40e_allocate_virt_mem(hw, &hw->hmc.hmc_obj_virt_mem,
sizeof(struct i40e_hmc_obj_info) * I40E_HMC_LAN_MAX);
if (ret_code)
goto init_lan_hmc_out;
hw->hmc.hmc_obj = (struct i40e_hmc_obj_info *)
hw->hmc.hmc_obj_virt_mem.va;
full_obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_FULL];
full_obj->max_cnt = 0;
full_obj->cnt = 0;
full_obj->base = 0;
full_obj->size = 0;
obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_TX];
obj->max_cnt = rd32(hw, I40E_GLHMC_LANQMAX);
obj->cnt = txq_num;
obj->base = 0;
size_exp = rd32(hw, I40E_GLHMC_LANTXOBJSZ);
obj->size = (u64)1 << size_exp;
if (txq_num > obj->max_cnt) {
ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
hw_dbg(hw, "i40e_init_lan_hmc: Tx context: asks for 0x%x but max allowed is 0x%x, returns error %d\n",
txq_num, obj->max_cnt, ret_code);
goto init_lan_hmc_out;
}
full_obj->max_cnt += obj->max_cnt;
full_obj->cnt += obj->cnt;
obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_RX];
obj->max_cnt = rd32(hw, I40E_GLHMC_LANQMAX);
obj->cnt = rxq_num;
obj->base = hw->hmc.hmc_obj[I40E_HMC_LAN_TX].base +
(hw->hmc.hmc_obj[I40E_HMC_LAN_TX].cnt *
hw->hmc.hmc_obj[I40E_HMC_LAN_TX].size);
obj->base = i40e_align_l2obj_base(obj->base);
size_exp = rd32(hw, I40E_GLHMC_LANRXOBJSZ);
obj->size = (u64)1 << size_exp;
if (rxq_num > obj->max_cnt) {
ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
hw_dbg(hw, "i40e_init_lan_hmc: Rx context: asks for 0x%x but max allowed is 0x%x, returns error %d\n",
rxq_num, obj->max_cnt, ret_code);
goto init_lan_hmc_out;
}
full_obj->max_cnt += obj->max_cnt;
full_obj->cnt += obj->cnt;
obj = &hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX];
obj->max_cnt = rd32(hw, I40E_GLHMC_FCOEMAX);
obj->cnt = fcoe_cntx_num;
obj->base = hw->hmc.hmc_obj[I40E_HMC_LAN_RX].base +
(hw->hmc.hmc_obj[I40E_HMC_LAN_RX].cnt *
hw->hmc.hmc_obj[I40E_HMC_LAN_RX].size);
obj->base = i40e_align_l2obj_base(obj->base);
size_exp = rd32(hw, I40E_GLHMC_FCOEDDPOBJSZ);
obj->size = (u64)1 << size_exp;
if (fcoe_cntx_num > obj->max_cnt) {
ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
hw_dbg(hw, "i40e_init_lan_hmc: FCoE context: asks for 0x%x but max allowed is 0x%x, returns error %d\n",
fcoe_cntx_num, obj->max_cnt, ret_code);
goto init_lan_hmc_out;
}
full_obj->max_cnt += obj->max_cnt;
full_obj->cnt += obj->cnt;
obj = &hw->hmc.hmc_obj[I40E_HMC_FCOE_FILT];
obj->max_cnt = rd32(hw, I40E_GLHMC_FCOEFMAX);
obj->cnt = fcoe_filt_num;
obj->base = hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX].base +
(hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX].cnt *
hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX].size);
obj->base = i40e_align_l2obj_base(obj->base);
size_exp = rd32(hw, I40E_GLHMC_FCOEFOBJSZ);
obj->size = (u64)1 << size_exp;
if (fcoe_filt_num > obj->max_cnt) {
ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
hw_dbg(hw, "i40e_init_lan_hmc: FCoE filter: asks for 0x%x but max allowed is 0x%x, returns error %d\n",
fcoe_filt_num, obj->max_cnt, ret_code);
goto init_lan_hmc_out;
}
full_obj->max_cnt += obj->max_cnt;
full_obj->cnt += obj->cnt;
hw->hmc.first_sd_index = 0;
hw->hmc.sd_table.ref_cnt = 0;
l2fpm_size = i40e_calculate_l2fpm_size(txq_num, rxq_num, fcoe_cntx_num,
fcoe_filt_num);
if (NULL == hw->hmc.sd_table.sd_entry) {
hw->hmc.sd_table.sd_cnt = (u32)
(l2fpm_size + I40E_HMC_DIRECT_BP_SIZE - 1) /
I40E_HMC_DIRECT_BP_SIZE;
ret_code = i40e_allocate_virt_mem(hw, &hw->hmc.sd_table.addr,
(sizeof(struct i40e_hmc_sd_entry) *
hw->hmc.sd_table.sd_cnt));
if (ret_code)
goto init_lan_hmc_out;
hw->hmc.sd_table.sd_entry =
(struct i40e_hmc_sd_entry *)hw->hmc.sd_table.addr.va;
}
full_obj->size = l2fpm_size;
init_lan_hmc_out:
return ret_code;
}
static i40e_status i40e_remove_pd_page(struct i40e_hw *hw,
struct i40e_hmc_info *hmc_info,
u32 idx)
{
i40e_status ret_code = 0;
if (!i40e_prep_remove_pd_page(hmc_info, idx))
ret_code = i40e_remove_pd_page_new(hw, hmc_info, idx, true);
return ret_code;
}
static i40e_status i40e_remove_sd_bp(struct i40e_hw *hw,
struct i40e_hmc_info *hmc_info,
u32 idx)
{
i40e_status ret_code = 0;
if (!i40e_prep_remove_sd_bp(hmc_info, idx))
ret_code = i40e_remove_sd_bp_new(hw, hmc_info, idx, true);
return ret_code;
}
static i40e_status i40e_create_lan_hmc_object(struct i40e_hw *hw,
struct i40e_hmc_lan_create_obj_info *info)
{
i40e_status ret_code = 0;
struct i40e_hmc_sd_entry *sd_entry;
u32 pd_idx1 = 0, pd_lmt1 = 0;
u32 pd_idx = 0, pd_lmt = 0;
bool pd_error = false;
u32 sd_idx, sd_lmt;
u64 sd_size;
u32 i, j;
if (NULL == info) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_create_lan_hmc_object: bad info ptr\n");
goto exit;
}
if (NULL == info->hmc_info) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_create_lan_hmc_object: bad hmc_info ptr\n");
goto exit;
}
if (I40E_HMC_INFO_SIGNATURE != info->hmc_info->signature) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_create_lan_hmc_object: bad signature\n");
goto exit;
}
if (info->start_idx >= info->hmc_info->hmc_obj[info->rsrc_type].cnt) {
ret_code = I40E_ERR_INVALID_HMC_OBJ_INDEX;
hw_dbg(hw, "i40e_create_lan_hmc_object: returns error %d\n",
ret_code);
goto exit;
}
if ((info->start_idx + info->count) >
info->hmc_info->hmc_obj[info->rsrc_type].cnt) {
ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
hw_dbg(hw, "i40e_create_lan_hmc_object: returns error %d\n",
ret_code);
goto exit;
}
I40E_FIND_SD_INDEX_LIMIT(info->hmc_info, info->rsrc_type,
info->start_idx, info->count,
&sd_idx, &sd_lmt);
if (sd_idx >= info->hmc_info->sd_table.sd_cnt ||
sd_lmt > info->hmc_info->sd_table.sd_cnt) {
ret_code = I40E_ERR_INVALID_SD_INDEX;
goto exit;
}
I40E_FIND_PD_INDEX_LIMIT(info->hmc_info, info->rsrc_type,
info->start_idx, info->count, &pd_idx,
&pd_lmt);
if (info->direct_mode_sz == 0)
sd_size = I40E_HMC_DIRECT_BP_SIZE;
else
sd_size = info->direct_mode_sz;
for (j = sd_idx; j < sd_lmt; j++) {
ret_code = i40e_add_sd_table_entry(hw, info->hmc_info, j,
info->entry_type,
sd_size);
if (ret_code)
goto exit_sd_error;
sd_entry = &info->hmc_info->sd_table.sd_entry[j];
if (I40E_SD_TYPE_PAGED == sd_entry->entry_type) {
pd_idx1 = max(pd_idx, (j * I40E_HMC_MAX_BP_COUNT));
pd_lmt1 = min(pd_lmt,
((j + 1) * I40E_HMC_MAX_BP_COUNT));
for (i = pd_idx1; i < pd_lmt1; i++) {
ret_code = i40e_add_pd_table_entry(hw,
info->hmc_info,
i);
if (ret_code) {
pd_error = true;
break;
}
}
if (pd_error) {
while (i && (i > pd_idx1)) {
i40e_remove_pd_bp(hw, info->hmc_info,
(i - 1), true);
i--;
}
}
}
if (!sd_entry->valid) {
sd_entry->valid = true;
switch (sd_entry->entry_type) {
case I40E_SD_TYPE_PAGED:
I40E_SET_PF_SD_ENTRY(hw,
sd_entry->u.pd_table.pd_page_addr.pa,
j, sd_entry->entry_type);
break;
case I40E_SD_TYPE_DIRECT:
I40E_SET_PF_SD_ENTRY(hw, sd_entry->u.bp.addr.pa,
j, sd_entry->entry_type);
break;
default:
ret_code = I40E_ERR_INVALID_SD_TYPE;
goto exit;
break;
}
}
}
goto exit;
exit_sd_error:
while (j && (j > sd_idx)) {
sd_entry = &info->hmc_info->sd_table.sd_entry[j - 1];
switch (sd_entry->entry_type) {
case I40E_SD_TYPE_PAGED:
pd_idx1 = max(pd_idx,
((j - 1) * I40E_HMC_MAX_BP_COUNT));
pd_lmt1 = min(pd_lmt, (j * I40E_HMC_MAX_BP_COUNT));
for (i = pd_idx1; i < pd_lmt1; i++) {
i40e_remove_pd_bp(
hw,
info->hmc_info,
i,
true);
}
i40e_remove_pd_page(hw, info->hmc_info, (j - 1));
break;
case I40E_SD_TYPE_DIRECT:
i40e_remove_sd_bp(hw, info->hmc_info, (j - 1));
break;
default:
ret_code = I40E_ERR_INVALID_SD_TYPE;
break;
}
j--;
}
exit:
return ret_code;
}
i40e_status i40e_configure_lan_hmc(struct i40e_hw *hw,
enum i40e_hmc_model model)
{
struct i40e_hmc_lan_create_obj_info info;
i40e_status ret_code = 0;
u8 hmc_fn_id = hw->hmc.hmc_fn_id;
struct i40e_hmc_obj_info *obj;
info.hmc_info = &hw->hmc;
info.rsrc_type = I40E_HMC_LAN_FULL;
info.start_idx = 0;
info.direct_mode_sz = hw->hmc.hmc_obj[I40E_HMC_LAN_FULL].size;
switch (model) {
case I40E_HMC_MODEL_DIRECT_PREFERRED:
case I40E_HMC_MODEL_DIRECT_ONLY:
info.entry_type = I40E_SD_TYPE_DIRECT;
info.count = 1;
ret_code = i40e_create_lan_hmc_object(hw, &info);
if ((ret_code) &&
(model == I40E_HMC_MODEL_DIRECT_PREFERRED))
goto try_type_paged;
else if (ret_code)
goto configure_lan_hmc_out;
break;
case I40E_HMC_MODEL_PAGED_ONLY:
try_type_paged:
info.entry_type = I40E_SD_TYPE_PAGED;
info.count = 1;
ret_code = i40e_create_lan_hmc_object(hw, &info);
if (ret_code)
goto configure_lan_hmc_out;
break;
default:
ret_code = I40E_ERR_INVALID_SD_TYPE;
hw_dbg(hw, "i40e_configure_lan_hmc: Unknown SD type: %d\n",
ret_code);
goto configure_lan_hmc_out;
break;
}
obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_TX];
wr32(hw, I40E_GLHMC_LANTXBASE(hmc_fn_id),
(u32)((obj->base & I40E_GLHMC_LANTXBASE_FPMLANTXBASE_MASK) / 512));
wr32(hw, I40E_GLHMC_LANTXCNT(hmc_fn_id), obj->cnt);
obj = &hw->hmc.hmc_obj[I40E_HMC_LAN_RX];
wr32(hw, I40E_GLHMC_LANRXBASE(hmc_fn_id),
(u32)((obj->base & I40E_GLHMC_LANRXBASE_FPMLANRXBASE_MASK) / 512));
wr32(hw, I40E_GLHMC_LANRXCNT(hmc_fn_id), obj->cnt);
obj = &hw->hmc.hmc_obj[I40E_HMC_FCOE_CTX];
wr32(hw, I40E_GLHMC_FCOEDDPBASE(hmc_fn_id),
(u32)((obj->base & I40E_GLHMC_FCOEDDPBASE_FPMFCOEDDPBASE_MASK) / 512));
wr32(hw, I40E_GLHMC_FCOEDDPCNT(hmc_fn_id), obj->cnt);
obj = &hw->hmc.hmc_obj[I40E_HMC_FCOE_FILT];
wr32(hw, I40E_GLHMC_FCOEFBASE(hmc_fn_id),
(u32)((obj->base & I40E_GLHMC_FCOEFBASE_FPMFCOEFBASE_MASK) / 512));
wr32(hw, I40E_GLHMC_FCOEFCNT(hmc_fn_id), obj->cnt);
configure_lan_hmc_out:
return ret_code;
}
static i40e_status i40e_delete_lan_hmc_object(struct i40e_hw *hw,
struct i40e_hmc_lan_delete_obj_info *info)
{
i40e_status ret_code = 0;
struct i40e_hmc_pd_table *pd_table;
u32 pd_idx, pd_lmt, rel_pd_idx;
u32 sd_idx, sd_lmt;
u32 i, j;
if (NULL == info) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_delete_hmc_object: bad info ptr\n");
goto exit;
}
if (NULL == info->hmc_info) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_delete_hmc_object: bad info->hmc_info ptr\n");
goto exit;
}
if (I40E_HMC_INFO_SIGNATURE != info->hmc_info->signature) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_delete_hmc_object: bad hmc_info->signature\n");
goto exit;
}
if (NULL == info->hmc_info->sd_table.sd_entry) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_delete_hmc_object: bad sd_entry\n");
goto exit;
}
if (NULL == info->hmc_info->hmc_obj) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_delete_hmc_object: bad hmc_info->hmc_obj\n");
goto exit;
}
if (info->start_idx >= info->hmc_info->hmc_obj[info->rsrc_type].cnt) {
ret_code = I40E_ERR_INVALID_HMC_OBJ_INDEX;
hw_dbg(hw, "i40e_delete_hmc_object: returns error %d\n",
ret_code);
goto exit;
}
if ((info->start_idx + info->count) >
info->hmc_info->hmc_obj[info->rsrc_type].cnt) {
ret_code = I40E_ERR_INVALID_HMC_OBJ_COUNT;
hw_dbg(hw, "i40e_delete_hmc_object: returns error %d\n",
ret_code);
goto exit;
}
I40E_FIND_PD_INDEX_LIMIT(info->hmc_info, info->rsrc_type,
info->start_idx, info->count, &pd_idx,
&pd_lmt);
for (j = pd_idx; j < pd_lmt; j++) {
sd_idx = j / I40E_HMC_PD_CNT_IN_SD;
if (I40E_SD_TYPE_PAGED !=
info->hmc_info->sd_table.sd_entry[sd_idx].entry_type)
continue;
rel_pd_idx = j % I40E_HMC_PD_CNT_IN_SD;
pd_table =
&info->hmc_info->sd_table.sd_entry[sd_idx].u.pd_table;
if (pd_table->pd_entry[rel_pd_idx].valid) {
ret_code = i40e_remove_pd_bp(hw, info->hmc_info,
j, true);
if (ret_code)
goto exit;
}
}
I40E_FIND_SD_INDEX_LIMIT(info->hmc_info, info->rsrc_type,
info->start_idx, info->count,
&sd_idx, &sd_lmt);
if (sd_idx >= info->hmc_info->sd_table.sd_cnt ||
sd_lmt > info->hmc_info->sd_table.sd_cnt) {
ret_code = I40E_ERR_INVALID_SD_INDEX;
goto exit;
}
for (i = sd_idx; i < sd_lmt; i++) {
if (!info->hmc_info->sd_table.sd_entry[i].valid)
continue;
switch (info->hmc_info->sd_table.sd_entry[i].entry_type) {
case I40E_SD_TYPE_DIRECT:
ret_code = i40e_remove_sd_bp(hw, info->hmc_info, i);
if (ret_code)
goto exit;
break;
case I40E_SD_TYPE_PAGED:
ret_code = i40e_remove_pd_page(hw, info->hmc_info, i);
if (ret_code)
goto exit;
break;
default:
break;
}
}
exit:
return ret_code;
}
i40e_status i40e_shutdown_lan_hmc(struct i40e_hw *hw)
{
struct i40e_hmc_lan_delete_obj_info info;
i40e_status ret_code;
info.hmc_info = &hw->hmc;
info.rsrc_type = I40E_HMC_LAN_FULL;
info.start_idx = 0;
info.count = 1;
ret_code = i40e_delete_lan_hmc_object(hw, &info);
i40e_free_virt_mem(hw, &hw->hmc.sd_table.addr);
hw->hmc.sd_table.sd_cnt = 0;
hw->hmc.sd_table.sd_entry = NULL;
i40e_free_virt_mem(hw, &hw->hmc.hmc_obj_virt_mem);
hw->hmc.hmc_obj = NULL;
return ret_code;
}
static i40e_status i40e_clear_hmc_context(struct i40e_hw *hw,
u8 *context_bytes,
enum i40e_hmc_lan_rsrc_type hmc_type)
{
memset(context_bytes, 0, (u32)hw->hmc.hmc_obj[hmc_type].size);
return 0;
}
static i40e_status i40e_set_hmc_context(u8 *context_bytes,
struct i40e_context_ele *ce_info,
u8 *dest)
{
u16 shift_width;
u64 bitfield;
u8 hi_byte;
u8 hi_mask;
u64 t_bits;
u64 mask;
u8 *p;
int f;
for (f = 0; ce_info[f].width != 0; f++) {
bitfield = 0;
p = dest + ce_info[f].offset;
switch (ce_info[f].size_of) {
case 1:
bitfield = *p;
break;
case 2:
bitfield = cpu_to_le16(*(u16 *)p);
break;
case 4:
bitfield = cpu_to_le32(*(u32 *)p);
break;
case 8:
bitfield = cpu_to_le64(*(u64 *)p);
break;
}
shift_width = ce_info[f].lsb % 8;
mask = ((u64)1 << ce_info[f].width) - 1;
hi_mask = (u8)((mask >> 56) & 0xff);
hi_byte = (u8)((bitfield >> 56) & 0xff);
mask <<= shift_width;
bitfield <<= shift_width;
p = context_bytes + (ce_info[f].lsb / 8);
memcpy(&t_bits, p, sizeof(u64));
t_bits &= ~mask;
t_bits |= bitfield;
memcpy(p, &t_bits, sizeof(u64));
if ((shift_width + ce_info[f].width) > 64) {
u8 byte;
hi_mask >>= (8 - shift_width);
hi_byte >>= (8 - shift_width);
byte = p[8] & ~hi_mask;
byte |= hi_byte;
p[8] = byte;
}
}
return 0;
}
static
i40e_status i40e_hmc_get_object_va(struct i40e_hmc_info *hmc_info,
u8 **object_base,
enum i40e_hmc_lan_rsrc_type rsrc_type,
u32 obj_idx)
{
u32 obj_offset_in_sd, obj_offset_in_pd;
i40e_status ret_code = 0;
struct i40e_hmc_sd_entry *sd_entry;
struct i40e_hmc_pd_entry *pd_entry;
u32 pd_idx, pd_lmt, rel_pd_idx;
u64 obj_offset_in_fpm;
u32 sd_idx, sd_lmt;
if (NULL == hmc_info) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_hmc_get_object_va: bad hmc_info ptr\n");
goto exit;
}
if (NULL == hmc_info->hmc_obj) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_hmc_get_object_va: bad hmc_info->hmc_obj ptr\n");
goto exit;
}
if (NULL == object_base) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_hmc_get_object_va: bad object_base ptr\n");
goto exit;
}
if (I40E_HMC_INFO_SIGNATURE != hmc_info->signature) {
ret_code = I40E_ERR_BAD_PTR;
hw_dbg(hw, "i40e_hmc_get_object_va: bad hmc_info->signature\n");
goto exit;
}
if (obj_idx >= hmc_info->hmc_obj[rsrc_type].cnt) {
hw_dbg(hw, "i40e_hmc_get_object_va: returns error %d\n",
ret_code);
ret_code = I40E_ERR_INVALID_HMC_OBJ_INDEX;
goto exit;
}
I40E_FIND_SD_INDEX_LIMIT(hmc_info, rsrc_type, obj_idx, 1,
&sd_idx, &sd_lmt);
sd_entry = &hmc_info->sd_table.sd_entry[sd_idx];
obj_offset_in_fpm = hmc_info->hmc_obj[rsrc_type].base +
hmc_info->hmc_obj[rsrc_type].size * obj_idx;
if (I40E_SD_TYPE_PAGED == sd_entry->entry_type) {
I40E_FIND_PD_INDEX_LIMIT(hmc_info, rsrc_type, obj_idx, 1,
&pd_idx, &pd_lmt);
rel_pd_idx = pd_idx % I40E_HMC_PD_CNT_IN_SD;
pd_entry = &sd_entry->u.pd_table.pd_entry[rel_pd_idx];
obj_offset_in_pd = (u32)(obj_offset_in_fpm %
I40E_HMC_PAGED_BP_SIZE);
*object_base = (u8 *)pd_entry->bp.addr.va + obj_offset_in_pd;
} else {
obj_offset_in_sd = (u32)(obj_offset_in_fpm %
I40E_HMC_DIRECT_BP_SIZE);
*object_base = (u8 *)sd_entry->u.bp.addr.va + obj_offset_in_sd;
}
exit:
return ret_code;
}
i40e_status i40e_clear_lan_tx_queue_context(struct i40e_hw *hw,
u16 queue)
{
i40e_status err;
u8 *context_bytes;
err = i40e_hmc_get_object_va(&hw->hmc, &context_bytes,
I40E_HMC_LAN_TX, queue);
if (err < 0)
return err;
return i40e_clear_hmc_context(hw, context_bytes, I40E_HMC_LAN_TX);
}
i40e_status i40e_set_lan_tx_queue_context(struct i40e_hw *hw,
u16 queue,
struct i40e_hmc_obj_txq *s)
{
i40e_status err;
u8 *context_bytes;
err = i40e_hmc_get_object_va(&hw->hmc, &context_bytes,
I40E_HMC_LAN_TX, queue);
if (err < 0)
return err;
return i40e_set_hmc_context(context_bytes,
i40e_hmc_txq_ce_info, (u8 *)s);
}
i40e_status i40e_clear_lan_rx_queue_context(struct i40e_hw *hw,
u16 queue)
{
i40e_status err;
u8 *context_bytes;
err = i40e_hmc_get_object_va(&hw->hmc, &context_bytes,
I40E_HMC_LAN_RX, queue);
if (err < 0)
return err;
return i40e_clear_hmc_context(hw, context_bytes, I40E_HMC_LAN_RX);
}
i40e_status i40e_set_lan_rx_queue_context(struct i40e_hw *hw,
u16 queue,
struct i40e_hmc_obj_rxq *s)
{
i40e_status err;
u8 *context_bytes;
err = i40e_hmc_get_object_va(&hw->hmc, &context_bytes,
I40E_HMC_LAN_RX, queue);
if (err < 0)
return err;
return i40e_set_hmc_context(context_bytes,
i40e_hmc_rxq_ce_info, (u8 *)s);
}
