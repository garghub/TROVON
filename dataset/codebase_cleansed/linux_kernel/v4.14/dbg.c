static void iwl_read_radio_regs(struct iwl_fw_runtime *fwrt,
struct iwl_fw_error_dump_data **dump_data)
{
u8 *pos = (void *)(*dump_data)->data;
unsigned long flags;
int i;
if (!iwl_trans_grab_nic_access(fwrt->trans, &flags))
return;
(*dump_data)->type = cpu_to_le32(IWL_FW_ERROR_DUMP_RADIO_REG);
(*dump_data)->len = cpu_to_le32(RADIO_REG_MAX_READ);
for (i = 0; i < RADIO_REG_MAX_READ; i++) {
u32 rd_cmd = RADIO_RSP_RD_CMD;
rd_cmd |= i << RADIO_RSP_ADDR_POS;
iwl_write_prph_no_grab(fwrt->trans, RSP_RADIO_CMD, rd_cmd);
*pos = (u8)iwl_read_prph_no_grab(fwrt->trans, RSP_RADIO_RDDAT);
pos++;
}
*dump_data = iwl_fw_error_next_data(*dump_data);
iwl_trans_release_nic_access(fwrt->trans, &flags);
}
static void iwl_fwrt_dump_rxf(struct iwl_fw_runtime *fwrt,
struct iwl_fw_error_dump_data **dump_data,
int size, u32 offset, int fifo_num)
{
struct iwl_fw_error_dump_fifo *fifo_hdr;
u32 *fifo_data;
u32 fifo_len;
int i;
fifo_hdr = (void *)(*dump_data)->data;
fifo_data = (void *)fifo_hdr->data;
fifo_len = size;
if (fifo_len == 0)
return;
(*dump_data)->type = cpu_to_le32(IWL_FW_ERROR_DUMP_RXF);
(*dump_data)->len = cpu_to_le32(fifo_len + sizeof(*fifo_hdr));
fifo_hdr->fifo_num = cpu_to_le32(fifo_num);
fifo_hdr->available_bytes =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
RXF_RD_D_SPACE + offset));
fifo_hdr->wr_ptr =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
RXF_RD_WR_PTR + offset));
fifo_hdr->rd_ptr =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
RXF_RD_RD_PTR + offset));
fifo_hdr->fence_ptr =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
RXF_RD_FENCE_PTR + offset));
fifo_hdr->fence_mode =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
RXF_SET_FENCE_MODE + offset));
iwl_trans_write_prph(fwrt->trans, RXF_SET_FENCE_MODE + offset, 0x1);
iwl_trans_write_prph(fwrt->trans, RXF_LD_WR2FENCE + offset, 0x1);
iwl_trans_write_prph(fwrt->trans,
RXF_LD_FENCE_OFFSET_ADDR + offset, 0x0);
fifo_len /= sizeof(u32);
for (i = 0; i < fifo_len; i++)
fifo_data[i] = iwl_trans_read_prph(fwrt->trans,
RXF_FIFO_RD_FENCE_INC +
offset);
*dump_data = iwl_fw_error_next_data(*dump_data);
}
static void iwl_fwrt_dump_txf(struct iwl_fw_runtime *fwrt,
struct iwl_fw_error_dump_data **dump_data,
int size, u32 offset, int fifo_num)
{
struct iwl_fw_error_dump_fifo *fifo_hdr;
u32 *fifo_data;
u32 fifo_len;
int i;
fifo_hdr = (void *)(*dump_data)->data;
fifo_data = (void *)fifo_hdr->data;
fifo_len = size;
if (fifo_len == 0)
return;
(*dump_data)->type = cpu_to_le32(IWL_FW_ERROR_DUMP_TXF);
(*dump_data)->len = cpu_to_le32(fifo_len + sizeof(*fifo_hdr));
fifo_hdr->fifo_num = cpu_to_le32(fifo_num);
fifo_hdr->available_bytes =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_FIFO_ITEM_CNT + offset));
fifo_hdr->wr_ptr =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_WR_PTR + offset));
fifo_hdr->rd_ptr =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_RD_PTR + offset));
fifo_hdr->fence_ptr =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_FENCE_PTR + offset));
fifo_hdr->fence_mode =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_LOCK_FENCE + offset));
iwl_trans_write_prph(fwrt->trans, TXF_READ_MODIFY_ADDR + offset,
TXF_WR_PTR + offset);
iwl_trans_read_prph(fwrt->trans, TXF_READ_MODIFY_DATA + offset);
fifo_len /= sizeof(u32);
for (i = 0; i < fifo_len; i++)
fifo_data[i] = iwl_trans_read_prph(fwrt->trans,
TXF_READ_MODIFY_DATA +
offset);
*dump_data = iwl_fw_error_next_data(*dump_data);
}
static void iwl_fw_dump_fifos(struct iwl_fw_runtime *fwrt,
struct iwl_fw_error_dump_data **dump_data)
{
struct iwl_fw_error_dump_fifo *fifo_hdr;
struct iwl_fwrt_shared_mem_cfg *cfg = &fwrt->smem_cfg;
u32 *fifo_data;
u32 fifo_len;
unsigned long flags;
int i, j;
if (!iwl_trans_grab_nic_access(fwrt->trans, &flags))
return;
iwl_fwrt_dump_rxf(fwrt, dump_data, cfg->lmac[0].rxfifo1_size, 0, 0);
iwl_fwrt_dump_rxf(fwrt, dump_data, cfg->rxfifo2_size,
RXF_DIFF_FROM_PREV, 1);
if (fwrt->smem_cfg.num_lmacs > 1)
iwl_fwrt_dump_rxf(fwrt, dump_data, cfg->lmac[1].rxfifo1_size,
LMAC2_PRPH_OFFSET, 2);
for (i = 0; i < fwrt->smem_cfg.num_txfifo_entries; i++) {
iwl_trans_write_prph(fwrt->trans, TXF_LARC_NUM, i);
iwl_fwrt_dump_txf(fwrt, dump_data, cfg->lmac[0].txfifo_size[i],
0, i);
}
if (fwrt->smem_cfg.num_lmacs > 1) {
for (i = 0; i < fwrt->smem_cfg.num_txfifo_entries; i++) {
iwl_trans_write_prph(fwrt->trans,
TXF_LARC_NUM + LMAC2_PRPH_OFFSET,
i);
iwl_fwrt_dump_txf(fwrt, dump_data,
cfg->lmac[1].txfifo_size[i],
LMAC2_PRPH_OFFSET,
i + cfg->num_txfifo_entries);
}
}
if (fw_has_capa(&fwrt->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_EXTEND_SHARED_MEM_CFG)) {
for (i = 0;
i < ARRAY_SIZE(fwrt->smem_cfg.internal_txfifo_size);
i++) {
fifo_hdr = (void *)(*dump_data)->data;
fifo_data = (void *)fifo_hdr->data;
fifo_len = fwrt->smem_cfg.internal_txfifo_size[i];
if (fifo_len == 0)
continue;
(*dump_data)->type =
cpu_to_le32(IWL_FW_ERROR_DUMP_INTERNAL_TXF);
(*dump_data)->len =
cpu_to_le32(fifo_len + sizeof(*fifo_hdr));
fifo_hdr->fifo_num = cpu_to_le32(i);
iwl_trans_write_prph(fwrt->trans, TXF_CPU2_NUM, i +
fwrt->smem_cfg.num_txfifo_entries);
fifo_hdr->available_bytes =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_CPU2_FIFO_ITEM_CNT));
fifo_hdr->wr_ptr =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_CPU2_WR_PTR));
fifo_hdr->rd_ptr =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_CPU2_RD_PTR));
fifo_hdr->fence_ptr =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_CPU2_FENCE_PTR));
fifo_hdr->fence_mode =
cpu_to_le32(iwl_trans_read_prph(fwrt->trans,
TXF_CPU2_LOCK_FENCE));
iwl_trans_write_prph(fwrt->trans,
TXF_CPU2_READ_MODIFY_ADDR,
TXF_CPU2_WR_PTR);
iwl_trans_read_prph(fwrt->trans,
TXF_CPU2_READ_MODIFY_DATA);
fifo_len /= sizeof(u32);
for (j = 0; j < fifo_len; j++)
fifo_data[j] =
iwl_trans_read_prph(fwrt->trans,
TXF_CPU2_READ_MODIFY_DATA);
*dump_data = iwl_fw_error_next_data(*dump_data);
}
}
iwl_trans_release_nic_access(fwrt->trans, &flags);
}
static void _iwl_read_prph_block(struct iwl_trans *trans, u32 start,
u32 len_bytes, __le32 *data)
{
u32 i;
for (i = 0; i < len_bytes; i += 4)
*data++ = cpu_to_le32(iwl_read_prph_no_grab(trans, start + i));
}
static bool iwl_read_prph_block(struct iwl_trans *trans, u32 start,
u32 len_bytes, __le32 *data)
{
unsigned long flags;
bool success = false;
if (iwl_trans_grab_nic_access(trans, &flags)) {
success = true;
_iwl_read_prph_block(trans, start, len_bytes, data);
iwl_trans_release_nic_access(trans, &flags);
}
return success;
}
static void iwl_dump_prph(struct iwl_trans *trans,
struct iwl_fw_error_dump_data **data,
const struct iwl_prph_range *iwl_prph_dump_addr,
u32 range_len)
{
struct iwl_fw_error_dump_prph *prph;
unsigned long flags;
u32 i;
if (!iwl_trans_grab_nic_access(trans, &flags))
return;
for (i = 0; i < range_len; i++) {
int num_bytes_in_chunk = iwl_prph_dump_addr[i].end -
iwl_prph_dump_addr[i].start + 4;
(*data)->type = cpu_to_le32(IWL_FW_ERROR_DUMP_PRPH);
(*data)->len = cpu_to_le32(sizeof(*prph) +
num_bytes_in_chunk);
prph = (void *)(*data)->data;
prph->prph_start = cpu_to_le32(iwl_prph_dump_addr[i].start);
_iwl_read_prph_block(trans, iwl_prph_dump_addr[i].start,
iwl_prph_dump_addr[i].end -
iwl_prph_dump_addr[i].start + 4,
(void *)prph->data);
*data = iwl_fw_error_next_data(*data);
}
iwl_trans_release_nic_access(trans, &flags);
}
static struct scatterlist *alloc_sgtable(int size)
{
int alloc_size, nents, i;
struct page *new_page;
struct scatterlist *iter;
struct scatterlist *table;
nents = DIV_ROUND_UP(size, PAGE_SIZE);
table = kcalloc(nents, sizeof(*table), GFP_KERNEL);
if (!table)
return NULL;
sg_init_table(table, nents);
iter = table;
for_each_sg(table, iter, sg_nents(table), i) {
new_page = alloc_page(GFP_KERNEL);
if (!new_page) {
iter = table;
for_each_sg(table, iter, sg_nents(table), i) {
new_page = sg_page(iter);
if (new_page)
__free_page(new_page);
}
return NULL;
}
alloc_size = min_t(int, size, PAGE_SIZE);
size -= PAGE_SIZE;
sg_set_page(iter, new_page, alloc_size, 0);
}
return table;
}
void iwl_fw_error_dump(struct iwl_fw_runtime *fwrt)
{
struct iwl_fw_error_dump_file *dump_file;
struct iwl_fw_error_dump_data *dump_data;
struct iwl_fw_error_dump_info *dump_info;
struct iwl_fw_error_dump_mem *dump_mem;
struct iwl_fw_error_dump_smem_cfg *dump_smem_cfg;
struct iwl_fw_error_dump_trigger_desc *dump_trig;
struct iwl_fw_dump_ptrs *fw_error_dump;
struct scatterlist *sg_dump_data;
u32 sram_len, sram_ofs;
const struct iwl_fw_dbg_mem_seg_tlv *fw_dbg_mem = fwrt->fw->dbg_mem_tlv;
struct iwl_fwrt_shared_mem_cfg *mem_cfg = &fwrt->smem_cfg;
u32 file_len, fifo_data_len = 0, prph_len = 0, radio_len = 0;
u32 smem_len = fwrt->fw->n_dbg_mem_tlv ? 0 : fwrt->trans->cfg->smem_len;
u32 sram2_len = fwrt->fw->n_dbg_mem_tlv ?
0 : fwrt->trans->cfg->dccm2_len;
bool monitor_dump_only = false;
int i;
if (test_bit(STATUS_TRANS_DEAD, &fwrt->trans->status)) {
IWL_ERR(fwrt, "Skip fw error dump since bus is dead\n");
goto out;
}
if (fwrt->dump.trig &&
fwrt->dump.trig->mode & IWL_FW_DBG_TRIGGER_MONITOR_ONLY)
monitor_dump_only = true;
fw_error_dump = kzalloc(sizeof(*fw_error_dump), GFP_KERNEL);
if (!fw_error_dump)
goto out;
if (!fwrt->trans->cfg->dccm_offset || !fwrt->trans->cfg->dccm_len) {
const struct fw_img *img;
img = &fwrt->fw->img[fwrt->cur_fw_img];
sram_ofs = img->sec[IWL_UCODE_SECTION_DATA].offset;
sram_len = img->sec[IWL_UCODE_SECTION_DATA].len;
} else {
sram_ofs = fwrt->trans->cfg->dccm_offset;
sram_len = fwrt->trans->cfg->dccm_len;
}
if (test_bit(STATUS_FW_ERROR, &fwrt->trans->status)) {
fifo_data_len = 0;
if (mem_cfg->rxfifo2_size) {
fifo_data_len += mem_cfg->rxfifo2_size +
sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_fifo);
}
for (i = 0; i < mem_cfg->num_lmacs; i++) {
if (!mem_cfg->lmac[i].rxfifo1_size)
continue;
fifo_data_len += mem_cfg->lmac[i].rxfifo1_size +
sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_fifo);
}
for (i = 0; i < mem_cfg->num_lmacs; i++) {
int j;
for (j = 0; j < mem_cfg->num_txfifo_entries; j++) {
if (!mem_cfg->lmac[i].txfifo_size[j])
continue;
fifo_data_len +=
mem_cfg->lmac[i].txfifo_size[j] +
sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_fifo);
}
}
if (fw_has_capa(&fwrt->fw->ucode_capa,
IWL_UCODE_TLV_CAPA_EXTEND_SHARED_MEM_CFG)) {
for (i = 0;
i < ARRAY_SIZE(mem_cfg->internal_txfifo_size);
i++) {
if (!mem_cfg->internal_txfifo_size[i])
continue;
fifo_data_len +=
mem_cfg->internal_txfifo_size[i] +
sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_fifo);
}
}
if (!fwrt->trans->cfg->gen2) {
for (i = 0; i < ARRAY_SIZE(iwl_prph_dump_addr_comm);
i++) {
int num_bytes_in_chunk =
iwl_prph_dump_addr_comm[i].end -
iwl_prph_dump_addr_comm[i].start + 4;
prph_len += sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_prph) +
num_bytes_in_chunk;
}
}
if (!fwrt->trans->cfg->gen2 &&
fwrt->trans->cfg->mq_rx_supported) {
for (i = 0; i <
ARRAY_SIZE(iwl_prph_dump_addr_9000); i++) {
int num_bytes_in_chunk =
iwl_prph_dump_addr_9000[i].end -
iwl_prph_dump_addr_9000[i].start + 4;
prph_len += sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_prph) +
num_bytes_in_chunk;
}
}
if (fwrt->trans->cfg->device_family == IWL_DEVICE_FAMILY_7000)
radio_len = sizeof(*dump_data) + RADIO_REG_MAX_READ;
}
file_len = sizeof(*dump_file) +
sizeof(*dump_data) * 3 +
sizeof(*dump_smem_cfg) +
fifo_data_len +
prph_len +
radio_len +
sizeof(*dump_info);
if (smem_len)
file_len += sizeof(*dump_data) + sizeof(*dump_mem) + smem_len;
if (sram2_len)
file_len += sizeof(*dump_data) + sizeof(*dump_mem) + sram2_len;
for (i = 0; i < fwrt->fw->n_dbg_mem_tlv; i++) {
file_len += sizeof(*dump_data) + sizeof(*dump_mem) +
le32_to_cpu(fw_dbg_mem[i].len);
}
if (!fwrt->trans->cfg->gen2 &&
fwrt->fw->img[fwrt->cur_fw_img].paging_mem_size &&
fwrt->fw_paging_db[0].fw_paging_block)
file_len += fwrt->num_of_paging_blk *
(sizeof(*dump_data) +
sizeof(struct iwl_fw_error_dump_paging) +
PAGING_BLOCK_SIZE);
if (monitor_dump_only) {
file_len = sizeof(*dump_file) + sizeof(*dump_data) * 2 +
sizeof(*dump_info) + sizeof(*dump_smem_cfg);
}
if (fwrt->dump.desc)
file_len += sizeof(*dump_data) + sizeof(*dump_trig) +
fwrt->dump.desc->len;
if (!fwrt->fw->n_dbg_mem_tlv)
file_len += sram_len + sizeof(*dump_mem);
dump_file = vzalloc(file_len);
if (!dump_file) {
kfree(fw_error_dump);
goto out;
}
fw_error_dump->fwrt_ptr = dump_file;
dump_file->barker = cpu_to_le32(IWL_FW_ERROR_DUMP_BARKER);
dump_data = (void *)dump_file->data;
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_DEV_FW_INFO);
dump_data->len = cpu_to_le32(sizeof(*dump_info));
dump_info = (void *)dump_data->data;
dump_info->device_family =
fwrt->trans->cfg->device_family == IWL_DEVICE_FAMILY_7000 ?
cpu_to_le32(IWL_FW_ERROR_DUMP_FAMILY_7) :
cpu_to_le32(IWL_FW_ERROR_DUMP_FAMILY_8);
dump_info->hw_step = cpu_to_le32(CSR_HW_REV_STEP(fwrt->trans->hw_rev));
memcpy(dump_info->fw_human_readable, fwrt->fw->human_readable,
sizeof(dump_info->fw_human_readable));
strncpy(dump_info->dev_human_readable, fwrt->trans->cfg->name,
sizeof(dump_info->dev_human_readable));
strncpy(dump_info->bus_human_readable, fwrt->dev->bus->name,
sizeof(dump_info->bus_human_readable));
dump_data = iwl_fw_error_next_data(dump_data);
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM_CFG);
dump_data->len = cpu_to_le32(sizeof(*dump_smem_cfg));
dump_smem_cfg = (void *)dump_data->data;
dump_smem_cfg->num_lmacs = cpu_to_le32(mem_cfg->num_lmacs);
dump_smem_cfg->num_txfifo_entries =
cpu_to_le32(mem_cfg->num_txfifo_entries);
for (i = 0; i < MAX_NUM_LMAC; i++) {
int j;
for (j = 0; j < TX_FIFO_MAX_NUM; j++)
dump_smem_cfg->lmac[i].txfifo_size[j] =
cpu_to_le32(mem_cfg->lmac[i].txfifo_size[j]);
dump_smem_cfg->lmac[i].rxfifo1_size =
cpu_to_le32(mem_cfg->lmac[i].rxfifo1_size);
}
dump_smem_cfg->rxfifo2_size = cpu_to_le32(mem_cfg->rxfifo2_size);
dump_smem_cfg->internal_txfifo_addr =
cpu_to_le32(mem_cfg->internal_txfifo_addr);
for (i = 0; i < TX_FIFO_INTERNAL_MAX_NUM; i++) {
dump_smem_cfg->internal_txfifo_size[i] =
cpu_to_le32(mem_cfg->internal_txfifo_size[i]);
}
dump_data = iwl_fw_error_next_data(dump_data);
if (test_bit(STATUS_FW_ERROR, &fwrt->trans->status)) {
iwl_fw_dump_fifos(fwrt, &dump_data);
if (radio_len)
iwl_read_radio_regs(fwrt, &dump_data);
}
if (fwrt->dump.desc) {
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_ERROR_INFO);
dump_data->len = cpu_to_le32(sizeof(*dump_trig) +
fwrt->dump.desc->len);
dump_trig = (void *)dump_data->data;
memcpy(dump_trig, &fwrt->dump.desc->trig_desc,
sizeof(*dump_trig) + fwrt->dump.desc->len);
dump_data = iwl_fw_error_next_data(dump_data);
}
if (monitor_dump_only)
goto dump_trans_data;
if (!fwrt->fw->n_dbg_mem_tlv) {
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM);
dump_data->len = cpu_to_le32(sram_len + sizeof(*dump_mem));
dump_mem = (void *)dump_data->data;
dump_mem->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM_SRAM);
dump_mem->offset = cpu_to_le32(sram_ofs);
iwl_trans_read_mem_bytes(fwrt->trans, sram_ofs, dump_mem->data,
sram_len);
dump_data = iwl_fw_error_next_data(dump_data);
}
for (i = 0; i < fwrt->fw->n_dbg_mem_tlv; i++) {
u32 len = le32_to_cpu(fw_dbg_mem[i].len);
u32 ofs = le32_to_cpu(fw_dbg_mem[i].ofs);
bool success;
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM);
dump_data->len = cpu_to_le32(len + sizeof(*dump_mem));
dump_mem = (void *)dump_data->data;
dump_mem->type = fw_dbg_mem[i].data_type;
dump_mem->offset = cpu_to_le32(ofs);
switch (dump_mem->type & cpu_to_le32(FW_DBG_MEM_TYPE_MASK)) {
case cpu_to_le32(FW_DBG_MEM_TYPE_REGULAR):
iwl_trans_read_mem_bytes(fwrt->trans, ofs,
dump_mem->data,
len);
success = true;
break;
case cpu_to_le32(FW_DBG_MEM_TYPE_PRPH):
success = iwl_read_prph_block(fwrt->trans, ofs, len,
(void *)dump_mem->data);
break;
default:
WARN_ON(1);
success = false;
}
if (success)
dump_data = iwl_fw_error_next_data(dump_data);
}
if (smem_len) {
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM);
dump_data->len = cpu_to_le32(smem_len + sizeof(*dump_mem));
dump_mem = (void *)dump_data->data;
dump_mem->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM_SMEM);
dump_mem->offset = cpu_to_le32(fwrt->trans->cfg->smem_offset);
iwl_trans_read_mem_bytes(fwrt->trans,
fwrt->trans->cfg->smem_offset,
dump_mem->data, smem_len);
dump_data = iwl_fw_error_next_data(dump_data);
}
if (sram2_len) {
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM);
dump_data->len = cpu_to_le32(sram2_len + sizeof(*dump_mem));
dump_mem = (void *)dump_data->data;
dump_mem->type = cpu_to_le32(IWL_FW_ERROR_DUMP_MEM_SRAM);
dump_mem->offset = cpu_to_le32(fwrt->trans->cfg->dccm2_offset);
iwl_trans_read_mem_bytes(fwrt->trans,
fwrt->trans->cfg->dccm2_offset,
dump_mem->data, sram2_len);
dump_data = iwl_fw_error_next_data(dump_data);
}
if (!fwrt->trans->cfg->gen2 &&
fwrt->fw->img[fwrt->cur_fw_img].paging_mem_size &&
fwrt->fw_paging_db[0].fw_paging_block) {
for (i = 1; i < fwrt->num_of_paging_blk + 1; i++) {
struct iwl_fw_error_dump_paging *paging;
struct page *pages =
fwrt->fw_paging_db[i].fw_paging_block;
dma_addr_t addr = fwrt->fw_paging_db[i].fw_paging_phys;
dump_data->type = cpu_to_le32(IWL_FW_ERROR_DUMP_PAGING);
dump_data->len = cpu_to_le32(sizeof(*paging) +
PAGING_BLOCK_SIZE);
paging = (void *)dump_data->data;
paging->index = cpu_to_le32(i);
dma_sync_single_for_cpu(fwrt->trans->dev, addr,
PAGING_BLOCK_SIZE,
DMA_BIDIRECTIONAL);
memcpy(paging->data, page_address(pages),
PAGING_BLOCK_SIZE);
dump_data = iwl_fw_error_next_data(dump_data);
}
}
if (prph_len) {
iwl_dump_prph(fwrt->trans, &dump_data,
iwl_prph_dump_addr_comm,
ARRAY_SIZE(iwl_prph_dump_addr_comm));
if (fwrt->trans->cfg->mq_rx_supported)
iwl_dump_prph(fwrt->trans, &dump_data,
iwl_prph_dump_addr_9000,
ARRAY_SIZE(iwl_prph_dump_addr_9000));
}
dump_trans_data:
fw_error_dump->trans_ptr = iwl_trans_dump_data(fwrt->trans,
fwrt->dump.trig);
fw_error_dump->fwrt_len = file_len;
if (fw_error_dump->trans_ptr)
file_len += fw_error_dump->trans_ptr->len;
dump_file->file_len = cpu_to_le32(file_len);
sg_dump_data = alloc_sgtable(file_len);
if (sg_dump_data) {
sg_pcopy_from_buffer(sg_dump_data,
sg_nents(sg_dump_data),
fw_error_dump->fwrt_ptr,
fw_error_dump->fwrt_len, 0);
if (fw_error_dump->trans_ptr)
sg_pcopy_from_buffer(sg_dump_data,
sg_nents(sg_dump_data),
fw_error_dump->trans_ptr->data,
fw_error_dump->trans_ptr->len,
fw_error_dump->fwrt_len);
dev_coredumpsg(fwrt->trans->dev, sg_dump_data, file_len,
GFP_KERNEL);
}
vfree(fw_error_dump->fwrt_ptr);
vfree(fw_error_dump->trans_ptr);
kfree(fw_error_dump);
out:
iwl_fw_free_dump_desc(fwrt);
fwrt->dump.trig = NULL;
clear_bit(IWL_FWRT_STATUS_DUMPING, &fwrt->status);
}
int iwl_fw_dbg_collect_desc(struct iwl_fw_runtime *fwrt,
const struct iwl_fw_dump_desc *desc,
const struct iwl_fw_dbg_trigger_tlv *trigger)
{
unsigned int delay = 0;
if (trigger)
delay = msecs_to_jiffies(le32_to_cpu(trigger->stop_delay));
if (WARN(fwrt->trans->state == IWL_TRANS_NO_FW,
"Can't collect dbg data when FW isn't alive\n"))
return -EIO;
if (test_and_set_bit(IWL_FWRT_STATUS_DUMPING, &fwrt->status))
return -EBUSY;
if (WARN_ON(fwrt->dump.desc))
iwl_fw_free_dump_desc(fwrt);
IWL_WARN(fwrt, "Collecting data: trigger %d fired.\n",
le32_to_cpu(desc->trig_desc.type));
fwrt->dump.desc = desc;
fwrt->dump.trig = trigger;
schedule_delayed_work(&fwrt->dump.wk, delay);
return 0;
}
int iwl_fw_dbg_collect(struct iwl_fw_runtime *fwrt,
enum iwl_fw_dbg_trigger trig,
const char *str, size_t len,
const struct iwl_fw_dbg_trigger_tlv *trigger)
{
struct iwl_fw_dump_desc *desc;
desc = kzalloc(sizeof(*desc) + len, GFP_ATOMIC);
if (!desc)
return -ENOMEM;
desc->len = len;
desc->trig_desc.type = cpu_to_le32(trig);
memcpy(desc->trig_desc.data, str, len);
return iwl_fw_dbg_collect_desc(fwrt, desc, trigger);
}
int iwl_fw_dbg_collect_trig(struct iwl_fw_runtime *fwrt,
struct iwl_fw_dbg_trigger_tlv *trigger,
const char *fmt, ...)
{
u16 occurrences = le16_to_cpu(trigger->occurrences);
int ret, len = 0;
char buf[64];
if (!occurrences)
return 0;
if (fmt) {
va_list ap;
buf[sizeof(buf) - 1] = '\0';
va_start(ap, fmt);
vsnprintf(buf, sizeof(buf), fmt, ap);
va_end(ap);
if (WARN_ON_ONCE(buf[sizeof(buf) - 1]))
buf[sizeof(buf) - 1] = '\0';
len = strlen(buf) + 1;
}
ret = iwl_fw_dbg_collect(fwrt, le32_to_cpu(trigger->id), buf, len,
trigger);
if (ret)
return ret;
trigger->occurrences = cpu_to_le16(occurrences - 1);
return 0;
}
int iwl_fw_start_dbg_conf(struct iwl_fw_runtime *fwrt, u8 conf_id)
{
u8 *ptr;
int ret;
int i;
if (WARN_ONCE(conf_id >= ARRAY_SIZE(fwrt->fw->dbg_conf_tlv),
"Invalid configuration %d\n", conf_id))
return -EINVAL;
if ((!fwrt->fw->dbg_conf_tlv[conf_id] ||
!fwrt->fw->dbg_conf_tlv[conf_id]->num_of_hcmds) &&
conf_id == FW_DBG_START_FROM_ALIVE)
return 0;
if (!fwrt->fw->dbg_conf_tlv[conf_id])
return -EINVAL;
if (fwrt->dump.conf != FW_DBG_INVALID)
IWL_WARN(fwrt, "FW already configured (%d) - re-configuring\n",
fwrt->dump.conf);
ptr = (void *)&fwrt->fw->dbg_conf_tlv[conf_id]->hcmd;
for (i = 0; i < fwrt->fw->dbg_conf_tlv[conf_id]->num_of_hcmds; i++) {
struct iwl_fw_dbg_conf_hcmd *cmd = (void *)ptr;
struct iwl_host_cmd hcmd = {
.id = cmd->id,
.len = { le16_to_cpu(cmd->len), },
.data = { cmd->data, },
};
ret = iwl_trans_send_cmd(fwrt->trans, &hcmd);
if (ret)
return ret;
ptr += sizeof(*cmd);
ptr += le16_to_cpu(cmd->len);
}
fwrt->dump.conf = conf_id;
return 0;
}
void iwl_fw_error_dump_wk(struct work_struct *work)
{
struct iwl_fw_runtime *fwrt =
container_of(work, struct iwl_fw_runtime, dump.wk.work);
if (fwrt->ops && fwrt->ops->dump_start &&
fwrt->ops->dump_start(fwrt->ops_ctx))
return;
if (fwrt->trans->cfg->device_family == IWL_DEVICE_FAMILY_7000) {
iwl_fw_dbg_stop_recording(fwrt);
iwl_fw_error_dump(fwrt);
if (!test_bit(STATUS_FW_ERROR, &fwrt->trans->status) &&
fwrt->fw->dbg_dest_tlv) {
iwl_clear_bits_prph(fwrt->trans,
MON_BUFF_SAMPLE_CTL, 0x100);
iwl_clear_bits_prph(fwrt->trans,
MON_BUFF_SAMPLE_CTL, 0x1);
iwl_set_bits_prph(fwrt->trans,
MON_BUFF_SAMPLE_CTL, 0x1);
}
} else {
u32 in_sample = iwl_read_prph(fwrt->trans, DBGC_IN_SAMPLE);
u32 out_ctrl = iwl_read_prph(fwrt->trans, DBGC_OUT_CTRL);
iwl_fw_dbg_stop_recording(fwrt);
udelay(500);
iwl_fw_error_dump(fwrt);
if (!test_bit(STATUS_FW_ERROR, &fwrt->trans->status) &&
fwrt->fw->dbg_dest_tlv) {
iwl_write_prph(fwrt->trans, DBGC_IN_SAMPLE, in_sample);
iwl_write_prph(fwrt->trans, DBGC_OUT_CTRL, out_ctrl);
}
}
if (fwrt->ops && fwrt->ops->dump_end)
fwrt->ops->dump_end(fwrt->ops_ctx);
}
