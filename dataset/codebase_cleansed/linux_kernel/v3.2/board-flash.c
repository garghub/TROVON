static void
__init board_nor_init(struct mtd_partition *nor_parts, u8 nr_parts, u8 cs)
{
int err;
board_nor_data.parts = nor_parts;
board_nor_data.nr_parts = nr_parts;
if (omap_rev() >= OMAP3430_REV_ES1_0) {
err = gpmc_cs_request(cs, FLASH_SIZE_SDPV2 - 1,
(unsigned long *)&board_nor_resource.start);
board_nor_resource.end = board_nor_resource.start
+ FLASH_SIZE_SDPV2 - 1;
} else {
err = gpmc_cs_request(cs, FLASH_SIZE_SDPV1 - 1,
(unsigned long *)&board_nor_resource.start);
board_nor_resource.end = board_nor_resource.start
+ FLASH_SIZE_SDPV1 - 1;
}
if (err < 0) {
pr_err("NOR: Can't request GPMC CS\n");
return;
}
if (platform_device_register(&board_nor_device) < 0)
pr_err("Unable to register NOR device\n");
}
static void
__init board_onenand_init(struct mtd_partition *onenand_parts,
u8 nr_parts, u8 cs)
{
board_onenand_data.cs = cs;
board_onenand_data.parts = onenand_parts;
board_onenand_data.nr_parts = nr_parts;
gpmc_onenand_init(&board_onenand_data);
}
static void
__init board_onenand_init(struct mtd_partition *nor_parts, u8 nr_parts, u8 cs)
{
}
void
__init board_nand_init(struct mtd_partition *nand_parts,
u8 nr_parts, u8 cs, int nand_type)
{
board_nand_data.cs = cs;
board_nand_data.parts = nand_parts;
board_nand_data.nr_parts = nr_parts;
board_nand_data.devsize = nand_type;
board_nand_data.ecc_opt = OMAP_ECC_HAMMING_CODE_DEFAULT;
board_nand_data.gpmc_irq = OMAP_GPMC_IRQ_BASE + cs;
gpmc_nand_init(&board_nand_data);
}
static u8 get_gpmc0_type(void)
{
u8 cs = 0;
void __iomem *fpga_map_addr;
fpga_map_addr = ioremap(DEBUG_BASE, 4096);
if (!fpga_map_addr)
return -ENOMEM;
if (!(__raw_readw(fpga_map_addr + REG_FPGA_REV)))
goto unmap;
cs = __raw_readw(fpga_map_addr + REG_FPGA_DIP_SWITCH_INPUT2) & 0xf;
if (omap_rev() >= OMAP3430_REV_ES1_0)
cs = ((cs & 8) >> 3) | ((cs & 4) >> 1) |
((cs & 2) << 1) | ((cs & 1) << 3);
else
cs = ((cs & 4) >> 2) | (cs & 2) | ((cs & 1) << 2);
unmap:
iounmap(fpga_map_addr);
return cs;
}
void board_flash_init(struct flash_partitions partition_info[],
char chip_sel_board[][GPMC_CS_NUM], int nand_type)
{
u8 cs = 0;
u8 norcs = GPMC_CS_NUM + 1;
u8 nandcs = GPMC_CS_NUM + 1;
u8 onenandcs = GPMC_CS_NUM + 1;
u8 idx;
unsigned char *config_sel = NULL;
idx = get_gpmc0_type();
if (idx >= MAX_SUPPORTED_GPMC_CONFIG) {
pr_err("%s: Invalid chip select: %d\n", __func__, cs);
return;
}
config_sel = (unsigned char *)(chip_sel_board[idx]);
while (cs < GPMC_CS_NUM) {
switch (config_sel[cs]) {
case PDC_NOR:
if (norcs > GPMC_CS_NUM)
norcs = cs;
break;
case PDC_NAND:
if (nandcs > GPMC_CS_NUM)
nandcs = cs;
break;
case PDC_ONENAND:
if (onenandcs > GPMC_CS_NUM)
onenandcs = cs;
break;
};
cs++;
}
if (norcs > GPMC_CS_NUM)
pr_err("NOR: Unable to find configuration in GPMC\n");
else
board_nor_init(partition_info[0].parts,
partition_info[0].nr_parts, norcs);
if (onenandcs > GPMC_CS_NUM)
pr_err("OneNAND: Unable to find configuration in GPMC\n");
else
board_onenand_init(partition_info[1].parts,
partition_info[1].nr_parts, onenandcs);
if (nandcs > GPMC_CS_NUM)
pr_err("NAND: Unable to find configuration in GPMC\n");
else
board_nand_init(partition_info[2].parts,
partition_info[2].nr_parts, nandcs, nand_type);
}
