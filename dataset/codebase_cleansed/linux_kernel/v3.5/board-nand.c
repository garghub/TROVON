void omap1_nand_cmd_ctl(struct mtd_info *mtd, int cmd, unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
unsigned long mask;
if (cmd == NAND_CMD_NONE)
return;
mask = (ctrl & NAND_CLE) ? 0x02 : 0;
if (ctrl & NAND_ALE)
mask |= 0x04;
writeb(cmd, this->IO_ADDR_W + mask);
}
