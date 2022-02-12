static void xway_reset_chip(struct nand_chip *chip)
{
unsigned long nandaddr = (unsigned long) chip->IO_ADDR_W;
unsigned long flags;
nandaddr &= ~NAND_WRITE_ADDR;
nandaddr |= NAND_WRITE_CMD;
spin_lock_irqsave(&ebu_lock, flags);
writeb(NAND_WRITE_CMD_RESET, (void __iomem *) nandaddr);
while ((ltq_ebu_r32(EBU_NAND_WAIT) & NAND_WAIT_WR_C) == 0)
;
spin_unlock_irqrestore(&ebu_lock, flags);
}
static void xway_select_chip(struct mtd_info *mtd, int chip)
{
switch (chip) {
case -1:
ltq_ebu_w32_mask(NAND_CON_CE, 0, EBU_NAND_CON);
ltq_ebu_w32_mask(NAND_CON_NANDM, 0, EBU_NAND_CON);
break;
case 0:
ltq_ebu_w32_mask(0, NAND_CON_NANDM, EBU_NAND_CON);
ltq_ebu_w32_mask(0, NAND_CON_CE, EBU_NAND_CON);
break;
default:
BUG();
}
}
static void xway_cmd_ctrl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *this = mtd_to_nand(mtd);
unsigned long nandaddr = (unsigned long) this->IO_ADDR_W;
unsigned long flags;
if (ctrl & NAND_CTRL_CHANGE) {
nandaddr &= ~(NAND_WRITE_CMD | NAND_WRITE_ADDR);
if (ctrl & NAND_CLE)
nandaddr |= NAND_WRITE_CMD;
else
nandaddr |= NAND_WRITE_ADDR;
this->IO_ADDR_W = (void __iomem *) nandaddr;
}
if (cmd != NAND_CMD_NONE) {
spin_lock_irqsave(&ebu_lock, flags);
writeb(cmd, this->IO_ADDR_W);
while ((ltq_ebu_r32(EBU_NAND_WAIT) & NAND_WAIT_WR_C) == 0)
;
spin_unlock_irqrestore(&ebu_lock, flags);
}
}
static int xway_dev_ready(struct mtd_info *mtd)
{
return ltq_ebu_r32(EBU_NAND_WAIT) & NAND_WAIT_RD;
}
static unsigned char xway_read_byte(struct mtd_info *mtd)
{
struct nand_chip *this = mtd_to_nand(mtd);
unsigned long nandaddr = (unsigned long) this->IO_ADDR_R;
unsigned long flags;
int ret;
spin_lock_irqsave(&ebu_lock, flags);
ret = ltq_r8((void __iomem *)(nandaddr + NAND_READ_DATA));
spin_unlock_irqrestore(&ebu_lock, flags);
return ret;
}
static int xway_nand_probe(struct platform_device *pdev)
{
struct nand_chip *this = platform_get_drvdata(pdev);
unsigned long nandaddr = (unsigned long) this->IO_ADDR_W;
const __be32 *cs = of_get_property(pdev->dev.of_node,
"lantiq,cs", NULL);
u32 cs_flag = 0;
if (cs && (*cs == 1))
cs_flag = NAND_CON_IN_CS1 | NAND_CON_OUT_CS1;
ltq_ebu_w32(CPHYSADDR(nandaddr)
| ADDSEL1_MASK(3) | ADDSEL1_REGEN, EBU_ADDSEL1);
ltq_ebu_w32(BUSCON1_SETUP | BUSCON1_BCGEN_RES | BUSCON1_WAITWRC2
| BUSCON1_WAITRDC2 | BUSCON1_HOLDC1 | BUSCON1_RECOVC1
| BUSCON1_CMULT4, LTQ_EBU_BUSCON1);
ltq_ebu_w32(NAND_CON_NANDM | NAND_CON_CSMUX | NAND_CON_CS_P
| NAND_CON_SE_P | NAND_CON_WP_P | NAND_CON_PRE_P
| cs_flag, EBU_NAND_CON);
xway_reset_chip(this);
return 0;
}
static int __init xway_register_nand(void)
{
struct device_node *node;
struct platform_device *pdev;
node = of_find_compatible_node(NULL, NULL, "lantiq,nand-xway");
if (!node)
return -ENOENT;
pdev = of_find_device_by_node(node);
if (!pdev)
return -EINVAL;
pdev->dev.platform_data = &xway_nand_data;
of_node_put(node);
return 0;
}
