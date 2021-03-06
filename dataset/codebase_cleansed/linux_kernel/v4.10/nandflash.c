static void crisv32_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
unsigned long flags;
reg_pio_rw_dout dout;
struct nand_chip *this = mtd_to_nand(mtd);
local_irq_save(flags);
if (ctrl & NAND_CTRL_CHANGE) {
dout = REG_RD(pio, regi_pio, rw_dout);
dout.regf_NCE = (ctrl & NAND_NCE) ? 0 : 1;
#if !MANUAL_ALE_CLE_CONTROL
if (ctrl & NAND_ALE) {
this->IO_ADDR_W = (void __iomem *)REG_ADDR(pio,
regi_pio, rw_io_access1);
} else if (ctrl & NAND_CLE) {
this->IO_ADDR_W = (void __iomem *)REG_ADDR(pio,
regi_pio, rw_io_access2);
} else {
this->IO_ADDR_W = (void __iomem *)REG_ADDR(pio,
regi_pio, rw_io_access0);
}
#else
dout.regf_CLE = (ctrl & NAND_CLE) ? 1 : 0;
dout.regf_ALE = (ctrl & NAND_ALE) ? 1 : 0;
#endif
REG_WR(pio, regi_pio, rw_dout, dout);
}
if (cmd != NAND_CMD_NONE)
writeb(cmd, this->IO_ADDR_W);
local_irq_restore(flags);
}
static int crisv32_device_ready(struct mtd_info *mtd)
{
reg_pio_r_din din = REG_RD(pio, regi_pio, r_din);
return din.rdy;
}
struct mtd_info *__init crisv32_nand_flash_probe(void)
{
void __iomem *read_cs;
void __iomem *write_cs;
struct mtd_info_wrapper *wrapper;
struct nand_chip *this;
int err = 0;
reg_pio_rw_man_ctrl man_ctrl = {
.regf_NCE = regk_pio_yes,
#if MANUAL_ALE_CLE_CONTROL
.regf_ALE = regk_pio_yes,
.regf_CLE = regk_pio_yes
#endif
};
reg_pio_rw_oe oe = {
.regf_NCE = regk_pio_yes,
#if MANUAL_ALE_CLE_CONTROL
.regf_ALE = regk_pio_yes,
.regf_CLE = regk_pio_yes
#endif
};
reg_pio_rw_dout dout = { .regf_NCE = 1 };
crisv32_pinmux_alloc_fixed(pinmux_pio);
REG_WR(pio, regi_pio, rw_man_ctrl, man_ctrl);
REG_WR(pio, regi_pio, rw_dout, dout);
REG_WR(pio, regi_pio, rw_oe, oe);
wrapper = kzalloc(sizeof(struct mtd_info_wrapper), GFP_KERNEL);
if (!wrapper) {
printk(KERN_ERR "Unable to allocate CRISv32 NAND MTD "
"device structure.\n");
err = -ENOMEM;
return NULL;
}
read_cs = write_cs = (void __iomem *)REG_ADDR(pio, regi_pio,
rw_io_access0);
this = &wrapper->chip;
crisv32_mtd = nand_to_mtd(this);
this->IO_ADDR_R = read_cs;
this->IO_ADDR_W = write_cs;
this->cmd_ctrl = crisv32_hwcontrol;
this->dev_ready = crisv32_device_ready;
this->chip_delay = 20;
this->ecc.mode = NAND_ECC_SOFT;
this->ecc.algo = NAND_ECC_HAMMING;
if (nand_scan(crisv32_mtd, 1)) {
err = -ENXIO;
goto out_mtd;
}
return crisv32_mtd;
out_mtd:
kfree(wrapper);
return NULL;
}
