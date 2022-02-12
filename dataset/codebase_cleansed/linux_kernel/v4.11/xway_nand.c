static u8 xway_readb(struct mtd_info *mtd, int op)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct xway_nand_data *data = nand_get_controller_data(chip);
return readb(data->nandaddr + op);
}
static void xway_writeb(struct mtd_info *mtd, int op, u8 value)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct xway_nand_data *data = nand_get_controller_data(chip);
writeb(value, data->nandaddr + op);
}
static void xway_select_chip(struct mtd_info *mtd, int select)
{
struct nand_chip *chip = mtd_to_nand(mtd);
struct xway_nand_data *data = nand_get_controller_data(chip);
switch (select) {
case -1:
ltq_ebu_w32_mask(NAND_CON_CE, 0, EBU_NAND_CON);
ltq_ebu_w32_mask(NAND_CON_NANDM, 0, EBU_NAND_CON);
spin_unlock_irqrestore(&ebu_lock, data->csflags);
break;
case 0:
spin_lock_irqsave(&ebu_lock, data->csflags);
ltq_ebu_w32_mask(0, NAND_CON_NANDM, EBU_NAND_CON);
ltq_ebu_w32_mask(0, NAND_CON_CE, EBU_NAND_CON);
break;
default:
BUG();
}
}
static void xway_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
if (cmd == NAND_CMD_NONE)
return;
if (ctrl & NAND_CLE)
xway_writeb(mtd, NAND_WRITE_CMD, cmd);
else if (ctrl & NAND_ALE)
xway_writeb(mtd, NAND_WRITE_ADDR, cmd);
while ((ltq_ebu_r32(EBU_NAND_WAIT) & NAND_WAIT_WR_C) == 0)
;
}
static int xway_dev_ready(struct mtd_info *mtd)
{
return ltq_ebu_r32(EBU_NAND_WAIT) & NAND_WAIT_RD;
}
static unsigned char xway_read_byte(struct mtd_info *mtd)
{
return xway_readb(mtd, NAND_READ_DATA);
}
static void xway_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
int i;
for (i = 0; i < len; i++)
buf[i] = xway_readb(mtd, NAND_WRITE_DATA);
}
static void xway_write_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
int i;
for (i = 0; i < len; i++)
xway_writeb(mtd, NAND_WRITE_DATA, buf[i]);
}
static int xway_nand_probe(struct platform_device *pdev)
{
struct xway_nand_data *data;
struct mtd_info *mtd;
struct resource *res;
int err;
u32 cs;
u32 cs_flag = 0;
data = devm_kzalloc(&pdev->dev, sizeof(struct xway_nand_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->nandaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->nandaddr))
return PTR_ERR(data->nandaddr);
nand_set_flash_node(&data->chip, pdev->dev.of_node);
mtd = nand_to_mtd(&data->chip);
mtd->dev.parent = &pdev->dev;
data->chip.cmd_ctrl = xway_cmd_ctrl;
data->chip.dev_ready = xway_dev_ready;
data->chip.select_chip = xway_select_chip;
data->chip.write_buf = xway_write_buf;
data->chip.read_buf = xway_read_buf;
data->chip.read_byte = xway_read_byte;
data->chip.chip_delay = 30;
data->chip.ecc.mode = NAND_ECC_SOFT;
data->chip.ecc.algo = NAND_ECC_HAMMING;
platform_set_drvdata(pdev, data);
nand_set_controller_data(&data->chip, data);
err = of_property_read_u32(pdev->dev.of_node, "lantiq,cs", &cs);
if (!err && cs == 1)
cs_flag = NAND_CON_IN_CS1 | NAND_CON_OUT_CS1;
ltq_ebu_w32(CPHYSADDR(data->nandaddr)
| ADDSEL1_MASK(3) | ADDSEL1_REGEN, EBU_ADDSEL1);
ltq_ebu_w32(BUSCON1_SETUP | BUSCON1_BCGEN_RES | BUSCON1_WAITWRC2
| BUSCON1_WAITRDC2 | BUSCON1_HOLDC1 | BUSCON1_RECOVC1
| BUSCON1_CMULT4, LTQ_EBU_BUSCON1);
ltq_ebu_w32(NAND_CON_NANDM | NAND_CON_CSMUX | NAND_CON_CS_P
| NAND_CON_SE_P | NAND_CON_WP_P | NAND_CON_PRE_P
| cs_flag, EBU_NAND_CON);
err = nand_scan(mtd, 1);
if (err)
return err;
err = mtd_device_register(mtd, NULL, 0);
if (err)
nand_release(mtd);
return err;
}
static int xway_nand_remove(struct platform_device *pdev)
{
struct xway_nand_data *data = platform_get_drvdata(pdev);
nand_release(nand_to_mtd(&data->chip));
return 0;
}
