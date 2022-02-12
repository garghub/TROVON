u16 GLOB_LLD_Flash_Reset(void)
{
return emu_Flash_Reset();
}
u16 GLOB_LLD_Read_Device_ID(void)
{
return emu_Read_Device_ID();
}
int GLOB_LLD_Flash_Release(void)
{
return emu_Flash_Release();
}
u16 GLOB_LLD_Flash_Init(void)
{
return emu_Flash_Init();
}
u16 GLOB_LLD_Erase_Block(u32 block_add)
{
return emu_Erase_Block(block_add);
}
u16 GLOB_LLD_Write_Page_Main(u8 *write_data, u32 block, u16 Page,
u16 PageCount)
{
return emu_Write_Page_Main(write_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Main(u8 *read_data, u32 block, u16 Page,
u16 PageCount)
{
return emu_Read_Page_Main(read_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Main_Polling(u8 *read_data,
u32 block, u16 page, u16 page_count)
{
return emu_Read_Page_Main(read_data, block, page, page_count);
}
u16 GLOB_LLD_Write_Page_Main_Spare(u8 *write_data, u32 block,
u16 Page, u16 PageCount)
{
return emu_Write_Page_Main_Spare(write_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Main_Spare(u8 *read_data, u32 block,
u16 Page, u16 PageCount)
{
return emu_Read_Page_Main_Spare(read_data, block, Page, PageCount);
}
u16 GLOB_LLD_Write_Page_Spare(u8 *write_data, u32 block, u16 Page,
u16 PageCount)
{
return emu_Write_Page_Spare(write_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Spare(u8 *read_data, u32 block, u16 Page,
u16 PageCount)
{
return emu_Read_Page_Spare(read_data, block, Page, PageCount);
}
u16 GLOB_LLD_Get_Bad_Block(u32 block)
{
return emu_Get_Bad_Block(block);
}
u16 GLOB_LLD_Flash_Reset(void)
{
return mtd_Flash_Reset();
}
u16 GLOB_LLD_Read_Device_ID(void)
{
return mtd_Read_Device_ID();
}
int GLOB_LLD_Flash_Release(void)
{
return mtd_Flash_Release();
}
u16 GLOB_LLD_Flash_Init(void)
{
return mtd_Flash_Init();
}
u16 GLOB_LLD_Erase_Block(u32 block_add)
{
return mtd_Erase_Block(block_add);
}
u16 GLOB_LLD_Write_Page_Main(u8 *write_data, u32 block, u16 Page,
u16 PageCount)
{
return mtd_Write_Page_Main(write_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Main(u8 *read_data, u32 block, u16 Page,
u16 PageCount)
{
return mtd_Read_Page_Main(read_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Main_Polling(u8 *read_data,
u32 block, u16 page, u16 page_count)
{
return mtd_Read_Page_Main(read_data, block, page, page_count);
}
u16 GLOB_LLD_Write_Page_Main_Spare(u8 *write_data, u32 block,
u16 Page, u16 PageCount)
{
return mtd_Write_Page_Main_Spare(write_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Main_Spare(u8 *read_data, u32 block,
u16 Page, u16 PageCount)
{
return mtd_Read_Page_Main_Spare(read_data, block, Page, PageCount);
}
u16 GLOB_LLD_Write_Page_Spare(u8 *write_data, u32 block, u16 Page,
u16 PageCount)
{
return mtd_Write_Page_Spare(write_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Spare(u8 *read_data, u32 block, u16 Page,
u16 PageCount)
{
return mtd_Read_Page_Spare(read_data, block, Page, PageCount);
}
u16 GLOB_LLD_Get_Bad_Block(u32 block)
{
return mtd_Get_Bad_Block(block);
}
void GLOB_LLD_ECC_Control(int enable)
{
NAND_ECC_Ctrl(enable);
}
u16 GLOB_LLD_Flash_Reset(void)
{
return NAND_Flash_Reset();
}
u16 GLOB_LLD_Read_Device_ID(void)
{
return NAND_Read_Device_ID();
}
u16 GLOB_LLD_UnlockArrayAll(void)
{
return NAND_UnlockArrayAll();
}
u16 GLOB_LLD_Flash_Init(void)
{
return NAND_Flash_Init();
}
int GLOB_LLD_Flash_Release(void)
{
return nand_release_spectra();
}
u16 GLOB_LLD_Erase_Block(u32 block_add)
{
return NAND_Erase_Block(block_add);
}
u16 GLOB_LLD_Write_Page_Main(u8 *write_data, u32 block, u16 Page,
u16 PageCount)
{
return NAND_Write_Page_Main(write_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Main(u8 *read_data, u32 block, u16 page,
u16 page_count)
{
if (page_count == 1)
return NAND_Read_Page_Main_Polling(read_data, block, page, 1);
else
return NAND_Read_Page_Main(read_data, block, page, page_count);
}
u16 GLOB_LLD_Read_Page_Main_Polling(u8 *read_data,
u32 block, u16 page, u16 page_count)
{
return NAND_Read_Page_Main_Polling(read_data,
block, page, page_count);
}
u16 GLOB_LLD_Write_Page_Main_Spare(u8 *write_data, u32 block,
u16 Page, u16 PageCount)
{
return NAND_Write_Page_Main_Spare(write_data, block, Page, PageCount);
}
u16 GLOB_LLD_Write_Page_Spare(u8 *write_data, u32 block, u16 Page,
u16 PageCount)
{
return NAND_Write_Page_Spare(write_data, block, Page, PageCount);
}
u16 GLOB_LLD_Read_Page_Main_Spare(u8 *read_data, u32 block,
u16 page, u16 page_count)
{
return NAND_Read_Page_Main_Spare(read_data, block, page, page_count);
}
u16 GLOB_LLD_Read_Page_Spare(u8 *read_data, u32 block, u16 Page,
u16 PageCount)
{
return NAND_Read_Page_Spare(read_data, block, Page, PageCount);
}
u16 GLOB_LLD_Get_Bad_Block(u32 block)
{
return NAND_Get_Bad_Block(block);
}
u16 GLOB_LLD_Event_Status(void)
{
return CDMA_Event_Status();
}
u16 glob_lld_execute_cmds(void)
{
return CDMA_Execute_CMDs();
}
u16 GLOB_LLD_MemCopy_CMD(u8 *dest, u8 *src,
u32 ByteCount, u16 flag)
{
if (CDMA_Execute_CMDs())
return FAIL;
memcpy(dest, src, ByteCount);
return PASS;
}
u16 GLOB_LLD_Erase_Block_cdma(u32 block, u16 flags)
{
return CDMA_Data_CMD(ERASE_CMD, 0, block, 0, 0, flags);
}
u16 GLOB_LLD_Write_Page_Main_cdma(u8 *data, u32 block, u16 page, u16 count)
{
return CDMA_Data_CMD(WRITE_MAIN_CMD, data, block, page, count, 0);
}
u16 GLOB_LLD_Read_Page_Main_cdma(u8 *data, u32 block, u16 page,
u16 count, u16 flags)
{
return CDMA_Data_CMD(READ_MAIN_CMD, data, block, page, count, flags);
}
u16 GLOB_LLD_Write_Page_Main_Spare_cdma(u8 *data, u32 block, u16 page,
u16 count, u16 flags)
{
return CDMA_Data_CMD(WRITE_MAIN_SPARE_CMD,
data, block, page, count, flags);
}
u16 GLOB_LLD_Read_Page_Main_Spare_cdma(u8 *data,
u32 block, u16 page, u16 count)
{
return CDMA_Data_CMD(READ_MAIN_SPARE_CMD, data, block, page, count,
LLD_CMD_FLAG_MODE_CDMA);
}
