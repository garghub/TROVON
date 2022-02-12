asmlinkage void mmc_loader(unsigned char *buf, unsigned long len)
{
mmc_init_progress();
mmc_update_progress(MMC_PROGRESS_ENTER);
__raw_writeb(0x04, PORT84CR);
__raw_writeb(0x04, PORT85CR);
__raw_writeb(0x04, PORT86CR);
__raw_writeb(0x04, PORT87CR);
__raw_writeb(0x04, PORT88CR);
__raw_writeb(0x04, PORT89CR);
__raw_writeb(0x04, PORT90CR);
__raw_writeb(0x04, PORT91CR);
__raw_writeb(0x04, PORT92CR);
__raw_writeb(0x14, PORT99CR);
__raw_writel(__raw_readl(SMSTPCR3) & ~(1 << 12), SMSTPCR3);
mmc_update_progress(MMC_PROGRESS_INIT);
sh_mmcif_boot_init(MMCIF_BASE);
mmc_update_progress(MMC_PROGRESS_LOAD);
sh_mmcif_boot_do_read(MMCIF_BASE, 2,
(len + SH_MMCIF_BBS - 1) / SH_MMCIF_BBS, buf);
__raw_writel(__raw_readl(SMSTPCR3) | (1 << 12), SMSTPCR3);
mmc_update_progress(MMC_PROGRESS_DONE);
}
