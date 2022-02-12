u16 mtd_Flash_Init(void)
{
if (mtddev == -1) {
printk(KERN_ERR "No MTD device specified. Give mtddev parameter\n");
return FAIL;
}
spectra_mtd = get_mtd_device(NULL, mtddev);
if (!spectra_mtd) {
printk(KERN_ERR "Failed to obtain MTD device #%d\n", mtddev);
return FAIL;
}
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
return PASS;
}
int mtd_Flash_Release(void)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (!spectra_mtd)
return PASS;
put_mtd_device(spectra_mtd);
spectra_mtd = NULL;
return PASS;
}
u16 mtd_Read_Device_ID(void)
{
uint64_t tmp;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (!spectra_mtd)
return FAIL;
DeviceInfo.wDeviceMaker = 0;
DeviceInfo.wDeviceType = 8;
DeviceInfo.wSpectraStartBlock = SPECTRA_START_BLOCK;
tmp = spectra_mtd->size;
do_div(tmp, spectra_mtd->erasesize);
DeviceInfo.wTotalBlocks = tmp;
DeviceInfo.wSpectraEndBlock = DeviceInfo.wTotalBlocks - 1;
DeviceInfo.wPagesPerBlock = spectra_mtd->erasesize / spectra_mtd->writesize;
DeviceInfo.wPageSize = spectra_mtd->writesize + spectra_mtd->oobsize;
DeviceInfo.wPageDataSize = spectra_mtd->writesize;
DeviceInfo.wPageSpareSize = spectra_mtd->oobsize;
DeviceInfo.wBlockSize = DeviceInfo.wPageSize * DeviceInfo.wPagesPerBlock;
DeviceInfo.wBlockDataSize = DeviceInfo.wPageDataSize * DeviceInfo.wPagesPerBlock;
DeviceInfo.wDataBlockNum = (u32) (DeviceInfo.wSpectraEndBlock -
DeviceInfo.wSpectraStartBlock
+ 1);
DeviceInfo.MLCDevice = 0;
DeviceInfo.nBitsInPageNumber =
(u8)GLOB_Calc_Used_Bits(DeviceInfo.wPagesPerBlock);
DeviceInfo.nBitsInPageDataSize =
(u8)GLOB_Calc_Used_Bits(DeviceInfo.wPageDataSize);
DeviceInfo.nBitsInBlockDataSize =
(u8)GLOB_Calc_Used_Bits(DeviceInfo.wBlockDataSize);
#if CMD_DMA
totalUsedBanks = 4;
valid_banks[0] = 1;
valid_banks[1] = 1;
valid_banks[2] = 1;
valid_banks[3] = 1;
#endif
return PASS;
}
u16 mtd_Flash_Reset(void)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
return PASS;
}
void erase_callback(struct erase_info *e)
{
complete((void *)e->priv);
}
u16 mtd_Erase_Block(u32 block_add)
{
struct erase_info erase;
DECLARE_COMPLETION_ONSTACK(comp);
int ret;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (block_add >= DeviceInfo.wTotalBlocks) {
printk(KERN_ERR "mtd_Erase_Block error! "
"Too big block address: %d\n", block_add);
return FAIL;
}
nand_dbg_print(NAND_DBG_DEBUG, "Erasing block %d\n",
(int)block_add);
erase.mtd = spectra_mtd;
erase.callback = erase_callback;
erase.addr = block_add * spectra_mtd->erasesize;
erase.len = spectra_mtd->erasesize;
erase.priv = (unsigned long)&comp;
ret = spectra_mtd->erase(spectra_mtd, &erase);
if (!ret) {
wait_for_completion(&comp);
if (erase.state != MTD_ERASE_DONE)
ret = -EIO;
}
if (ret) {
printk(KERN_WARNING "mtd_Erase_Block error! "
"erase of region [0x%llx, 0x%llx] failed\n",
erase.addr, erase.len);
return FAIL;
}
return PASS;
}
u16 mtd_Write_Page_Main(u8 *write_data, u32 Block,
u16 Page, u16 PageCount)
{
size_t retlen;
int ret = 0;
if (Block >= DeviceInfo.wTotalBlocks)
return FAIL;
if (Page + PageCount > DeviceInfo.wPagesPerBlock)
return FAIL;
nand_dbg_print(NAND_DBG_DEBUG, "mtd_Write_Page_Main: "
"lba %u Page %u PageCount %u\n",
(unsigned int)Block,
(unsigned int)Page, (unsigned int)PageCount);
while (PageCount) {
ret = spectra_mtd->write(spectra_mtd,
(Block * spectra_mtd->erasesize) + (Page * spectra_mtd->writesize),
DeviceInfo.wPageDataSize, &retlen, write_data);
if (ret) {
printk(KERN_ERR "%s failed %d\n", __func__, ret);
return FAIL;
}
write_data += DeviceInfo.wPageDataSize;
Page++;
PageCount--;
}
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
return PASS;
}
u16 mtd_Read_Page_Main(u8 *read_data, u32 Block,
u16 Page, u16 PageCount)
{
size_t retlen;
int ret = 0;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (Block >= DeviceInfo.wTotalBlocks)
return FAIL;
if (Page + PageCount > DeviceInfo.wPagesPerBlock)
return FAIL;
nand_dbg_print(NAND_DBG_DEBUG, "mtd_Read_Page_Main: "
"lba %u Page %u PageCount %u\n",
(unsigned int)Block,
(unsigned int)Page, (unsigned int)PageCount);
while (PageCount) {
ret = spectra_mtd->read(spectra_mtd,
(Block * spectra_mtd->erasesize) + (Page * spectra_mtd->writesize),
DeviceInfo.wPageDataSize, &retlen, read_data);
if (ret) {
printk(KERN_ERR "%s failed %d\n", __func__, ret);
return FAIL;
}
read_data += DeviceInfo.wPageDataSize;
Page++;
PageCount--;
}
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
return PASS;
}
u16 mtd_Read_Page_Main_Spare(u8 *read_data, u32 Block,
u16 Page, u16 PageCount)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (Block >= DeviceInfo.wTotalBlocks) {
printk(KERN_ERR "Read Page Main+Spare "
"Error: Block Address too big\n");
return FAIL;
}
if (Page + PageCount > DeviceInfo.wPagesPerBlock) {
printk(KERN_ERR "Read Page Main+Spare "
"Error: Page number %d+%d too big in block %d\n",
Page, PageCount, Block);
return FAIL;
}
nand_dbg_print(NAND_DBG_DEBUG, "Read Page Main + Spare - "
"No. of pages %u block %u start page %u\n",
(unsigned int)PageCount,
(unsigned int)Block, (unsigned int)Page);
while (PageCount) {
struct mtd_oob_ops ops;
int ret;
ops.mode = MTD_OPS_AUTO_OOB;
ops.datbuf = read_data;
ops.len = DeviceInfo.wPageDataSize;
ops.oobbuf = read_data + DeviceInfo.wPageDataSize + BTSIG_OFFSET;
ops.ooblen = BTSIG_BYTES;
ops.ooboffs = 0;
ret = spectra_mtd->read_oob(spectra_mtd,
(Block * spectra_mtd->erasesize) + (Page * spectra_mtd->writesize),
&ops);
if (ret) {
printk(KERN_ERR "%s failed %d\n", __func__, ret);
return FAIL;
}
read_data += DeviceInfo.wPageSize;
Page++;
PageCount--;
}
return PASS;
}
u16 mtd_Write_Page_Main_Spare(u8 *write_data, u32 Block,
u16 Page, u16 page_count)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (Block >= DeviceInfo.wTotalBlocks) {
printk(KERN_ERR "Write Page Main + Spare "
"Error: Block Address too big\n");
return FAIL;
}
if (Page + page_count > DeviceInfo.wPagesPerBlock) {
printk(KERN_ERR "Write Page Main + Spare "
"Error: Page number %d+%d too big in block %d\n",
Page, page_count, Block);
WARN_ON(1);
return FAIL;
}
nand_dbg_print(NAND_DBG_DEBUG, "Write Page Main+Spare - "
"No. of pages %u block %u start page %u\n",
(unsigned int)page_count,
(unsigned int)Block, (unsigned int)Page);
while (page_count) {
struct mtd_oob_ops ops;
int ret;
ops.mode = MTD_OPS_AUTO_OOB;
ops.datbuf = write_data;
ops.len = DeviceInfo.wPageDataSize;
ops.oobbuf = write_data + DeviceInfo.wPageDataSize + BTSIG_OFFSET;
ops.ooblen = BTSIG_BYTES;
ops.ooboffs = 0;
ret = spectra_mtd->write_oob(spectra_mtd,
(Block * spectra_mtd->erasesize) + (Page * spectra_mtd->writesize),
&ops);
if (ret) {
printk(KERN_ERR "%s failed %d\n", __func__, ret);
return FAIL;
}
write_data += DeviceInfo.wPageSize;
Page++;
page_count--;
}
return PASS;
}
u16 mtd_Write_Page_Spare(u8 *write_data, u32 Block,
u16 Page, u16 PageCount)
{
WARN_ON(1);
return FAIL;
}
u16 mtd_Read_Page_Spare(u8 *read_data, u32 Block,
u16 Page, u16 PageCount)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (Block >= DeviceInfo.wTotalBlocks) {
printk(KERN_ERR "Read Page Spare "
"Error: Block Address too big\n");
return FAIL;
}
if (Page + PageCount > DeviceInfo.wPagesPerBlock) {
printk(KERN_ERR "Read Page Spare "
"Error: Page number too big\n");
return FAIL;
}
nand_dbg_print(NAND_DBG_DEBUG, "Read Page Spare- "
"block %u page %u (%u pages)\n",
(unsigned int)Block, (unsigned int)Page, PageCount);
while (PageCount) {
struct mtd_oob_ops ops;
int ret;
ops.mode = MTD_OPS_AUTO_OOB;
ops.datbuf = NULL;
ops.len = 0;
ops.oobbuf = read_data;
ops.ooblen = BTSIG_BYTES;
ops.ooboffs = 0;
ret = spectra_mtd->read_oob(spectra_mtd,
(Block * spectra_mtd->erasesize) + (Page * spectra_mtd->writesize),
&ops);
if (ret) {
printk(KERN_ERR "%s failed %d\n", __func__, ret);
return FAIL;
}
read_data += DeviceInfo.wPageSize;
Page++;
PageCount--;
}
return PASS;
}
void mtd_Enable_Disable_Interrupts(u16 INT_ENABLE)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
}
u16 mtd_Get_Bad_Block(u32 block)
{
return 0;
}
u16 mtd_CDMA_Flash_Init(void)
{
u16 i;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
for (i = 0; i < MAX_DESCS + MAX_CHANS; i++) {
PendingCMD[i].CMD = 0;
PendingCMD[i].Tag = 0;
PendingCMD[i].DataAddr = 0;
PendingCMD[i].Block = 0;
PendingCMD[i].Page = 0;
PendingCMD[i].PageCount = 0;
PendingCMD[i].DataDestAddr = 0;
PendingCMD[i].DataSrcAddr = 0;
PendingCMD[i].MemCopyByteCnt = 0;
PendingCMD[i].ChanSync[0] = 0;
PendingCMD[i].ChanSync[1] = 0;
PendingCMD[i].ChanSync[2] = 0;
PendingCMD[i].ChanSync[3] = 0;
PendingCMD[i].ChanSync[4] = 0;
PendingCMD[i].Status = 3;
}
return PASS;
}
static void mtd_isr(int irq, void *dev_id)
{
}
u16 mtd_CDMA_Execute_CMDs(u16 tag_count)
{
u16 i, j;
u8 CMD;
u8 *data;
u32 block;
u16 page;
u16 count;
u16 status = PASS;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
nand_dbg_print(NAND_DBG_TRACE, "At start of Execute CMDs: "
"Tag Count %u\n", tag_count);
for (i = 0; i < totalUsedBanks; i++) {
PendingCMD[i].CMD = DUMMY_CMD;
PendingCMD[i].Tag = 0xFF;
PendingCMD[i].Block =
(DeviceInfo.wTotalBlocks / totalUsedBanks) * i;
for (j = 0; j <= MAX_CHANS; j++)
PendingCMD[i].ChanSync[j] = 0;
}
CDMA_Execute_CMDs(tag_count);
#ifdef VERBOSE
print_pending_cmds(tag_count);
#endif
#if DEBUG_SYNC
}
