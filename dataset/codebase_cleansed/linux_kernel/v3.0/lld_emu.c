int emu_load_file_to_mem(void)
{
mm_segment_t fs;
struct file *nef_filp = NULL;
struct inode *inode = NULL;
loff_t nef_size = 0;
loff_t tmp_file_offset, file_offset;
ssize_t nread;
int i, rc = -EINVAL;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
fs = get_fs();
set_fs(get_ds());
nef_filp = filp_open("/root/nand_emu_file", O_RDWR | O_LARGEFILE, 0);
if (IS_ERR(nef_filp)) {
printk(KERN_ERR "filp_open error: "
"Unable to open nand emu file!\n");
return PTR_ERR(nef_filp);
}
if (nef_filp->f_path.dentry) {
inode = nef_filp->f_path.dentry->d_inode;
} else {
printk(KERN_ERR "Can not get valid inode!\n");
goto out;
}
nef_size = i_size_read(inode->i_mapping->host);
if (nef_size <= 0) {
printk(KERN_ERR "Invalid nand emu file size: "
"0x%llx\n", nef_size);
goto out;
} else {
nand_dbg_print(NAND_DBG_DEBUG, "nand emu file size: %lld\n",
nef_size);
}
file_offset = 0;
for (i = 0; i < GLOB_LLD_BLOCKS * GLOB_LLD_PAGES; i++) {
tmp_file_offset = file_offset;
nread = vfs_read(nef_filp,
(char __user *)flash_memory[i],
GLOB_LLD_PAGE_SIZE, &tmp_file_offset);
if (nread < GLOB_LLD_PAGE_SIZE) {
printk(KERN_ERR "%s, Line %d - "
"nand emu file partial read: "
"%d bytes\n", __FILE__, __LINE__, (int)nread);
goto out;
}
file_offset += GLOB_LLD_PAGE_SIZE;
}
rc = 0;
out:
filp_close(nef_filp, current->files);
set_fs(fs);
return rc;
}
int emu_write_mem_to_file(void)
{
mm_segment_t fs;
struct file *nef_filp = NULL;
struct inode *inode = NULL;
loff_t nef_size = 0;
loff_t tmp_file_offset, file_offset;
ssize_t nwritten;
int i, rc = -EINVAL;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
fs = get_fs();
set_fs(get_ds());
nef_filp = filp_open("/root/nand_emu_file", O_RDWR | O_LARGEFILE, 0);
if (IS_ERR(nef_filp)) {
printk(KERN_ERR "filp_open error: "
"Unable to open nand emu file!\n");
return PTR_ERR(nef_filp);
}
if (nef_filp->f_path.dentry) {
inode = nef_filp->f_path.dentry->d_inode;
} else {
printk(KERN_ERR "Invalid " "nef_filp->f_path.dentry value!\n");
goto out;
}
nef_size = i_size_read(inode->i_mapping->host);
if (nef_size <= 0) {
printk(KERN_ERR "Invalid "
"nand emu file size: 0x%llx\n", nef_size);
goto out;
} else {
nand_dbg_print(NAND_DBG_DEBUG, "nand emu file size: "
"%lld\n", nef_size);
}
file_offset = 0;
for (i = 0; i < GLOB_LLD_BLOCKS * GLOB_LLD_PAGES; i++) {
tmp_file_offset = file_offset;
nwritten = vfs_write(nef_filp,
(char __user *)flash_memory[i],
GLOB_LLD_PAGE_SIZE, &tmp_file_offset);
if (nwritten < GLOB_LLD_PAGE_SIZE) {
printk(KERN_ERR "%s, Line %d - "
"nand emu file partial write: "
"%d bytes\n", __FILE__, __LINE__, (int)nwritten);
goto out;
}
file_offset += GLOB_LLD_PAGE_SIZE;
}
rc = 0;
out:
filp_close(nef_filp, current->files);
set_fs(fs);
return rc;
}
u16 emu_Flash_Init(void)
{
int i;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
flash_memory[0] = vmalloc(GLOB_LLD_PAGE_SIZE * GLOB_LLD_BLOCKS *
GLOB_LLD_PAGES * sizeof(u8));
if (!flash_memory[0]) {
printk(KERN_ERR "Fail to allocate memory "
"for nand emulator!\n");
return ERR;
}
memset((char *)(flash_memory[0]), 0xFF,
GLOB_LLD_PAGE_SIZE * GLOB_LLD_BLOCKS * GLOB_LLD_PAGES *
sizeof(u8));
for (i = 1; i < GLOB_LLD_BLOCKS * GLOB_LLD_PAGES; i++)
flash_memory[i] = flash_memory[i - 1] + GLOB_LLD_PAGE_SIZE;
emu_load_file_to_mem();
return PASS;
}
int emu_Flash_Release(void)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
emu_write_mem_to_file();
vfree(flash_memory[0]);
return PASS;
}
u16 emu_Read_Device_ID(void)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
DeviceInfo.wDeviceMaker = 0;
DeviceInfo.wDeviceType = 8;
DeviceInfo.wSpectraStartBlock = 36;
DeviceInfo.wSpectraEndBlock = GLOB_LLD_BLOCKS - 1;
DeviceInfo.wTotalBlocks = GLOB_LLD_BLOCKS;
DeviceInfo.wPagesPerBlock = GLOB_LLD_PAGES;
DeviceInfo.wPageSize = GLOB_LLD_PAGE_SIZE;
DeviceInfo.wPageDataSize = GLOB_LLD_PAGE_DATA_SIZE;
DeviceInfo.wPageSpareSize = GLOB_LLD_PAGE_SIZE -
GLOB_LLD_PAGE_DATA_SIZE;
DeviceInfo.wBlockSize = DeviceInfo.wPageSize * GLOB_LLD_PAGES;
DeviceInfo.wBlockDataSize = DeviceInfo.wPageDataSize * GLOB_LLD_PAGES;
DeviceInfo.wDataBlockNum = (u32) (DeviceInfo.wSpectraEndBlock -
DeviceInfo.wSpectraStartBlock
+ 1);
DeviceInfo.MLCDevice = 1;
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
u16 emu_Flash_Reset(void)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
return PASS;
}
u16 emu_Erase_Block(u32 block_add)
{
int i;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (block_add >= DeviceInfo.wTotalBlocks) {
printk(KERN_ERR "emu_Erase_Block error! "
"Too big block address: %d\n", block_add);
return FAIL;
}
nand_dbg_print(NAND_DBG_DEBUG, "Erasing block %d\n",
(int)block_add);
for (i = block_add * GLOB_LLD_PAGES;
i < ((block_add + 1) * GLOB_LLD_PAGES); i++) {
if (flash_memory[i]) {
memset((u8 *)(flash_memory[i]), 0xFF,
DeviceInfo.wPageSize * sizeof(u8));
}
}
return PASS;
}
u16 emu_Write_Page_Main(u8 *write_data, u32 Block,
u16 Page, u16 PageCount)
{
int i;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (Block >= DeviceInfo.wTotalBlocks)
return FAIL;
if (Page + PageCount > DeviceInfo.wPagesPerBlock)
return FAIL;
nand_dbg_print(NAND_DBG_DEBUG, "emu_Write_Page_Main: "
"lba %u Page %u PageCount %u\n",
(unsigned int)Block,
(unsigned int)Page, (unsigned int)PageCount);
for (i = 0; i < PageCount; i++) {
if (NULL == flash_memory[Block * GLOB_LLD_PAGES + Page]) {
printk(KERN_ERR "Run out of memory\n");
return FAIL;
}
memcpy((u8 *) (flash_memory[Block * GLOB_LLD_PAGES + Page]),
write_data, DeviceInfo.wPageDataSize);
write_data += DeviceInfo.wPageDataSize;
Page++;
}
return PASS;
}
u16 emu_Read_Page_Main(u8 *read_data, u32 Block,
u16 Page, u16 PageCount)
{
int i;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (Block >= DeviceInfo.wTotalBlocks)
return FAIL;
if (Page + PageCount > DeviceInfo.wPagesPerBlock)
return FAIL;
nand_dbg_print(NAND_DBG_DEBUG, "emu_Read_Page_Main: "
"lba %u Page %u PageCount %u\n",
(unsigned int)Block,
(unsigned int)Page, (unsigned int)PageCount);
for (i = 0; i < PageCount; i++) {
if (NULL == flash_memory[Block * GLOB_LLD_PAGES + Page]) {
memset(read_data, 0xFF, DeviceInfo.wPageDataSize);
} else {
memcpy(read_data,
(u8 *) (flash_memory[Block * GLOB_LLD_PAGES
+ Page]),
DeviceInfo.wPageDataSize);
}
read_data += DeviceInfo.wPageDataSize;
Page++;
}
return PASS;
}
u16 emu_Read_Page_Main_Spare(u8 *read_data, u32 Block,
u16 Page, u16 PageCount)
{
int i;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (Block >= DeviceInfo.wTotalBlocks) {
printk(KERN_ERR "Read Page Main+Spare "
"Error: Block Address too big\n");
return FAIL;
}
if (Page + PageCount > DeviceInfo.wPagesPerBlock) {
printk(KERN_ERR "Read Page Main+Spare "
"Error: Page number too big\n");
return FAIL;
}
nand_dbg_print(NAND_DBG_DEBUG, "Read Page Main + Spare - "
"No. of pages %u block %u start page %u\n",
(unsigned int)PageCount,
(unsigned int)Block, (unsigned int)Page);
for (i = 0; i < PageCount; i++) {
if (NULL == flash_memory[Block * GLOB_LLD_PAGES + Page]) {
memset(read_data, 0xFF, DeviceInfo.wPageSize);
} else {
memcpy(read_data, (u8 *) (flash_memory[Block *
GLOB_LLD_PAGES
+ Page]),
DeviceInfo.wPageSize);
}
read_data += DeviceInfo.wPageSize;
Page++;
}
return PASS;
}
u16 emu_Write_Page_Main_Spare(u8 *write_data, u32 Block,
u16 Page, u16 page_count)
{
u16 i;
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (Block >= DeviceInfo.wTotalBlocks) {
printk(KERN_ERR "Write Page Main + Spare "
"Error: Block Address too big\n");
return FAIL;
}
if (Page + page_count > DeviceInfo.wPagesPerBlock) {
printk(KERN_ERR "Write Page Main + Spare "
"Error: Page number too big\n");
return FAIL;
}
nand_dbg_print(NAND_DBG_DEBUG, "Write Page Main+Spare - "
"No. of pages %u block %u start page %u\n",
(unsigned int)page_count,
(unsigned int)Block, (unsigned int)Page);
for (i = 0; i < page_count; i++) {
if (NULL == flash_memory[Block * GLOB_LLD_PAGES + Page]) {
printk(KERN_ERR "Run out of memory!\n");
return FAIL;
}
memcpy((u8 *) (flash_memory[Block * GLOB_LLD_PAGES + Page]),
write_data, DeviceInfo.wPageSize);
write_data += DeviceInfo.wPageSize;
Page++;
}
return PASS;
}
u16 emu_Write_Page_Spare(u8 *write_data, u32 Block,
u16 Page, u16 PageCount)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
if (Block >= DeviceInfo.wTotalBlocks) {
printk(KERN_ERR "Read Page Spare Error: "
"Block Address too big\n");
return FAIL;
}
if (Page + PageCount > DeviceInfo.wPagesPerBlock) {
printk(KERN_ERR "Read Page Spare Error: "
"Page number too big\n");
return FAIL;
}
nand_dbg_print(NAND_DBG_DEBUG, "Write Page Spare- "
"block %u page %u\n",
(unsigned int)Block, (unsigned int)Page);
if (NULL == flash_memory[Block * GLOB_LLD_PAGES + Page]) {
printk(KERN_ERR "Run out of memory!\n");
return FAIL;
}
memcpy((u8 *) (flash_memory[Block * GLOB_LLD_PAGES + Page] +
DeviceInfo.wPageDataSize), write_data,
(DeviceInfo.wPageSize - DeviceInfo.wPageDataSize));
return PASS;
}
u16 emu_Read_Page_Spare(u8 *write_data, u32 Block,
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
"block %u page %u\n",
(unsigned int)Block, (unsigned int)Page);
if (NULL == flash_memory[Block * GLOB_LLD_PAGES + Page]) {
memset(write_data, 0xFF,
(DeviceInfo.wPageSize - DeviceInfo.wPageDataSize));
} else {
memcpy(write_data,
(u8 *) (flash_memory[Block * GLOB_LLD_PAGES + Page]
+ DeviceInfo.wPageDataSize),
(DeviceInfo.wPageSize - DeviceInfo.wPageDataSize));
}
return PASS;
}
void emu_Enable_Disable_Interrupts(u16 INT_ENABLE)
{
nand_dbg_print(NAND_DBG_TRACE, "%s, Line %d, Function: %s\n",
__FILE__, __LINE__, __func__);
}
u16 emu_Get_Bad_Block(u32 block)
{
return 0;
}
u16 emu_CDMA_Flash_Init(void)
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
static void emu_isr(int irq, void *dev_id)
{
}
u16 emu_CDMA_Execute_CMDs(u16 tag_count)
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
print_pending_cmds(tag_count);
#if DEBUG_SYNC
}
