void iwl_free_fw_paging(struct iwl_fw_runtime *fwrt)
{
int i;
if (!fwrt->fw_paging_db[0].fw_paging_block)
return;
for (i = 0; i < NUM_OF_FW_PAGING_BLOCKS; i++) {
struct iwl_fw_paging *paging = &fwrt->fw_paging_db[i];
if (!paging->fw_paging_block) {
IWL_DEBUG_FW(fwrt,
"Paging: block %d already freed, continue to next page\n",
i);
continue;
}
dma_unmap_page(fwrt->trans->dev, paging->fw_paging_phys,
paging->fw_paging_size, DMA_BIDIRECTIONAL);
__free_pages(paging->fw_paging_block,
get_order(paging->fw_paging_size));
paging->fw_paging_block = NULL;
}
kfree(fwrt->trans->paging_download_buf);
fwrt->trans->paging_download_buf = NULL;
fwrt->trans->paging_db = NULL;
memset(fwrt->fw_paging_db, 0, sizeof(fwrt->fw_paging_db));
}
static int iwl_alloc_fw_paging_mem(struct iwl_fw_runtime *fwrt,
const struct fw_img *image)
{
struct page *block;
dma_addr_t phys = 0;
int blk_idx, order, num_of_pages, size, dma_enabled;
if (fwrt->fw_paging_db[0].fw_paging_block)
return 0;
dma_enabled = is_device_dma_capable(fwrt->trans->dev);
BUILD_BUG_ON(BIT(BLOCK_2_EXP_SIZE) != PAGING_BLOCK_SIZE);
num_of_pages = image->paging_mem_size / FW_PAGING_SIZE;
fwrt->num_of_paging_blk =
DIV_ROUND_UP(num_of_pages, NUM_OF_PAGE_PER_GROUP);
fwrt->num_of_pages_in_last_blk =
num_of_pages -
NUM_OF_PAGE_PER_GROUP * (fwrt->num_of_paging_blk - 1);
IWL_DEBUG_FW(fwrt,
"Paging: allocating mem for %d paging blocks, each block holds 8 pages, last block holds %d pages\n",
fwrt->num_of_paging_blk,
fwrt->num_of_pages_in_last_blk);
for (blk_idx = 0; blk_idx < fwrt->num_of_paging_blk + 1; blk_idx++) {
size = blk_idx ? PAGING_BLOCK_SIZE : FW_PAGING_SIZE;
order = get_order(size);
block = alloc_pages(GFP_KERNEL, order);
if (!block) {
iwl_free_fw_paging(fwrt);
return -ENOMEM;
}
fwrt->fw_paging_db[blk_idx].fw_paging_block = block;
fwrt->fw_paging_db[blk_idx].fw_paging_size = size;
if (dma_enabled) {
phys = dma_map_page(fwrt->trans->dev, block, 0,
PAGE_SIZE << order,
DMA_BIDIRECTIONAL);
if (dma_mapping_error(fwrt->trans->dev, phys)) {
iwl_free_fw_paging(fwrt);
return -ENOMEM;
}
fwrt->fw_paging_db[blk_idx].fw_paging_phys = phys;
} else {
fwrt->fw_paging_db[blk_idx].fw_paging_phys =
PAGING_ADDR_SIG |
blk_idx << BLOCK_2_EXP_SIZE;
}
if (!blk_idx)
IWL_DEBUG_FW(fwrt,
"Paging: allocated 4K(CSS) bytes (order %d) for firmware paging.\n",
order);
else
IWL_DEBUG_FW(fwrt,
"Paging: allocated 32K bytes (order %d) for firmware paging.\n",
order);
}
return 0;
}
static int iwl_fill_paging_mem(struct iwl_fw_runtime *fwrt,
const struct fw_img *image)
{
int sec_idx, idx;
u32 offset = 0;
for (sec_idx = 0; sec_idx < image->num_sec; sec_idx++) {
if (image->sec[sec_idx].offset == PAGING_SEPARATOR_SECTION) {
sec_idx++;
break;
}
}
if (sec_idx >= image->num_sec - 1) {
IWL_ERR(fwrt, "Paging: Missing CSS and/or paging sections\n");
iwl_free_fw_paging(fwrt);
return -EINVAL;
}
IWL_DEBUG_FW(fwrt, "Paging: load paging CSS to FW, sec = %d\n",
sec_idx);
memcpy(page_address(fwrt->fw_paging_db[0].fw_paging_block),
image->sec[sec_idx].data,
fwrt->fw_paging_db[0].fw_paging_size);
dma_sync_single_for_device(fwrt->trans->dev,
fwrt->fw_paging_db[0].fw_paging_phys,
fwrt->fw_paging_db[0].fw_paging_size,
DMA_BIDIRECTIONAL);
IWL_DEBUG_FW(fwrt,
"Paging: copied %d CSS bytes to first block\n",
fwrt->fw_paging_db[0].fw_paging_size);
sec_idx++;
for (idx = 1; idx < fwrt->num_of_paging_blk; idx++) {
struct iwl_fw_paging *block = &fwrt->fw_paging_db[idx];
memcpy(page_address(block->fw_paging_block),
image->sec[sec_idx].data + offset,
block->fw_paging_size);
dma_sync_single_for_device(fwrt->trans->dev,
block->fw_paging_phys,
block->fw_paging_size,
DMA_BIDIRECTIONAL);
IWL_DEBUG_FW(fwrt,
"Paging: copied %d paging bytes to block %d\n",
fwrt->fw_paging_db[idx].fw_paging_size,
idx);
offset += fwrt->fw_paging_db[idx].fw_paging_size;
}
if (fwrt->num_of_pages_in_last_blk > 0) {
struct iwl_fw_paging *block = &fwrt->fw_paging_db[idx];
memcpy(page_address(block->fw_paging_block),
image->sec[sec_idx].data + offset,
FW_PAGING_SIZE * fwrt->num_of_pages_in_last_blk);
dma_sync_single_for_device(fwrt->trans->dev,
block->fw_paging_phys,
block->fw_paging_size,
DMA_BIDIRECTIONAL);
IWL_DEBUG_FW(fwrt,
"Paging: copied %d pages in the last block %d\n",
fwrt->num_of_pages_in_last_blk, idx);
}
return 0;
}
static int iwl_save_fw_paging(struct iwl_fw_runtime *fwrt,
const struct fw_img *fw)
{
int ret;
ret = iwl_alloc_fw_paging_mem(fwrt, fw);
if (ret)
return ret;
return iwl_fill_paging_mem(fwrt, fw);
}
static int iwl_send_paging_cmd(struct iwl_fw_runtime *fwrt,
const struct fw_img *fw)
{
struct iwl_fw_paging_cmd paging_cmd = {
.flags = cpu_to_le32(PAGING_CMD_IS_SECURED |
PAGING_CMD_IS_ENABLED |
(fwrt->num_of_pages_in_last_blk <<
PAGING_CMD_NUM_OF_PAGES_IN_LAST_GRP_POS)),
.block_size = cpu_to_le32(BLOCK_2_EXP_SIZE),
.block_num = cpu_to_le32(fwrt->num_of_paging_blk),
};
struct iwl_host_cmd hcmd = {
.id = iwl_cmd_id(FW_PAGING_BLOCK_CMD, IWL_ALWAYS_LONG_GROUP, 0),
.len = { sizeof(paging_cmd), },
.data = { &paging_cmd, },
};
int blk_idx;
for (blk_idx = 0; blk_idx < fwrt->num_of_paging_blk + 1; blk_idx++) {
dma_addr_t addr = fwrt->fw_paging_db[blk_idx].fw_paging_phys;
__le32 phy_addr;
addr = addr >> PAGE_2_EXP_SIZE;
phy_addr = cpu_to_le32(addr);
paging_cmd.device_phy_addr[blk_idx] = phy_addr;
}
return iwl_trans_send_cmd(fwrt->trans, &hcmd);
}
static int iwl_trans_get_paging_item(struct iwl_fw_runtime *fwrt)
{
int ret;
struct iwl_fw_get_item_cmd fw_get_item_cmd = {
.item_id = cpu_to_le32(IWL_FW_ITEM_ID_PAGING),
};
struct iwl_fw_get_item_resp *item_resp;
struct iwl_host_cmd cmd = {
.id = iwl_cmd_id(FW_GET_ITEM_CMD, IWL_ALWAYS_LONG_GROUP, 0),
.flags = CMD_WANT_SKB | CMD_SEND_IN_RFKILL,
.data = { &fw_get_item_cmd, },
.len = { sizeof(fw_get_item_cmd), },
};
ret = iwl_trans_send_cmd(fwrt->trans, &cmd);
if (ret) {
IWL_ERR(fwrt,
"Paging: Failed to send FW_GET_ITEM_CMD cmd (err = %d)\n",
ret);
return ret;
}
item_resp = (void *)((struct iwl_rx_packet *)cmd.resp_pkt)->data;
if (item_resp->item_id != cpu_to_le32(IWL_FW_ITEM_ID_PAGING)) {
IWL_ERR(fwrt,
"Paging: got wrong item in FW_GET_ITEM_CMD resp (item_id = %u)\n",
le32_to_cpu(item_resp->item_id));
ret = -EIO;
goto exit;
}
fwrt->trans->paging_download_buf = kzalloc(PAGING_BLOCK_SIZE +
FW_PAGING_SIZE,
GFP_KERNEL);
if (!fwrt->trans->paging_download_buf) {
ret = -ENOMEM;
goto exit;
}
fwrt->trans->paging_req_addr = le32_to_cpu(item_resp->item_val);
fwrt->trans->paging_db = fwrt->fw_paging_db;
IWL_DEBUG_FW(fwrt,
"Paging: got paging request address (paging_req_addr 0x%08x)\n",
fwrt->trans->paging_req_addr);
exit:
iwl_free_resp(&cmd);
return ret;
}
int iwl_init_paging(struct iwl_fw_runtime *fwrt, enum iwl_ucode_type type)
{
const struct fw_img *fw = &fwrt->fw->img[type];
int ret;
if (fwrt->trans->cfg->gen2)
return 0;
if (!fw->paging_mem_size)
return 0;
if (!is_device_dma_capable(fwrt->trans->dev)) {
ret = iwl_trans_get_paging_item(fwrt);
if (ret) {
IWL_ERR(fwrt, "failed to get FW paging item\n");
return ret;
}
}
ret = iwl_save_fw_paging(fwrt, fw);
if (ret) {
IWL_ERR(fwrt, "failed to save the FW paging image\n");
return ret;
}
ret = iwl_send_paging_cmd(fwrt, fw);
if (ret) {
IWL_ERR(fwrt, "failed to send the paging cmd\n");
iwl_free_fw_paging(fwrt);
return ret;
}
return 0;
}
