static void crisv32_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
unsigned long flags;
reg_gio_rw_pa_dout dout;
struct nand_chip *this = mtd_to_nand(mtd);
local_irq_save(flags);
if (ctrl & NAND_CTRL_CHANGE) {
dout = REG_RD(gio, regi_gio, rw_pa_dout);
dout.data &= ~PIN_BITMASK;
#if (CE_BIT == 4 && NAND_NCE == 1 && \
CLE_BIT == 5 && NAND_CLE == 2 && \
ALE_BIT == 6 && NAND_ALE == 4)
dout.data |= ((ctrl & CTRL_BITMASK) ^ NAND_NCE) << CE_BIT;
#else
if (!(ctrl & NAND_NCE))
dout.data |= (1 << CE_BIT);
if (ctrl & NAND_CLE)
dout.data |= (1 << CLE_BIT);
if (ctrl & NAND_ALE)
dout.data |= (1 << ALE_BIT);
#endif
REG_WR(gio, regi_gio, rw_pa_dout, dout);
}
if (cmd != NAND_CMD_NONE)
writeb(cmd, this->IO_ADDR_W);
local_irq_restore(flags);
}
static int crisv32_device_ready(struct mtd_info *mtd)
{
reg_gio_r_pa_din din = REG_RD(gio, regi_gio, r_pa_din);
return ((din.data & (1 << BY_BIT)) >> BY_BIT);
}
struct mtd_info *__init crisv32_nand_flash_probe(void)
{
void __iomem *read_cs;
void __iomem *write_cs;
reg_bif_core_rw_grp3_cfg bif_cfg = REG_RD(bif_core, regi_bif_core,
rw_grp3_cfg);
reg_gio_rw_pa_oe pa_oe = REG_RD(gio, regi_gio, rw_pa_oe);
struct mtd_info_wrapper *wrapper;
struct nand_chip *this;
int err = 0;
wrapper = kzalloc(sizeof(struct mtd_info_wrapper), GFP_KERNEL);
if (!wrapper) {
printk(KERN_ERR "Unable to allocate CRISv32 NAND MTD "
"device structure.\n");
err = -ENOMEM;
return NULL;
}
read_cs = ioremap(MEM_CSP0_START | MEM_NON_CACHEABLE, 8192);
write_cs = ioremap(MEM_CSP1_START | MEM_NON_CACHEABLE, 8192);
if (!read_cs || !write_cs) {
printk(KERN_ERR "CRISv32 NAND ioremap failed\n");
err = -EIO;
goto out_mtd;
}
this = &wrapper->chip;
crisv32_mtd = nand_to_mtd(this);
pa_oe.oe |= 1 << CE_BIT;
pa_oe.oe |= 1 << ALE_BIT;
pa_oe.oe |= 1 << CLE_BIT;
pa_oe.oe &= ~(1 << BY_BIT);
REG_WR(gio, regi_gio, rw_pa_oe, pa_oe);
bif_cfg.gated_csp0 = regk_bif_core_rd;
bif_cfg.gated_csp1 = regk_bif_core_wr;
REG_WR(bif_core, regi_bif_core, rw_grp3_cfg, bif_cfg);
this->IO_ADDR_R = read_cs;
this->IO_ADDR_W = write_cs;
this->cmd_ctrl = crisv32_hwcontrol;
this->dev_ready = crisv32_device_ready;
this->chip_delay = 20;
this->ecc.mode = NAND_ECC_SOFT;
this->ecc.algo = NAND_ECC_HAMMING;
if (nand_scan(crisv32_mtd, 1)) {
err = -ENXIO;
goto out_ior;
}
return crisv32_mtd;
out_ior:
iounmap((void *)read_cs);
iounmap((void *)write_cs);
out_mtd:
kfree(wrapper);
return NULL;
}
