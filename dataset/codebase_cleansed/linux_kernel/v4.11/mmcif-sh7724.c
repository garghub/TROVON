asmlinkage void mmcif_loader(unsigned char *buf, unsigned long no_bytes)
{
mmcif_update_progress(MMCIF_PROGRESS_ENTER);
__raw_writel(__raw_readl(MSTPCR2) & ~0x20000000, MSTPCR2);
__raw_writew(0x0000, PTWCR);
__raw_writew(__raw_readw(PTXCR) & ~0x000f, PTXCR);
__raw_writew(__raw_readw(PSELA) & ~0x2000, PSELA);
__raw_writew(__raw_readw(PSELE) & ~0x3000, PSELE);
__raw_writew(__raw_readw(HIZCRC) & ~0x0620, HIZCRC);
__raw_writew(__raw_readw(DRVCRA) | 0x3000, DRVCRA);
mmcif_update_progress(MMCIF_PROGRESS_INIT);
sh_mmcif_boot_init(MMCIF_BASE);
mmcif_update_progress(MMCIF_PROGRESS_LOAD);
sh_mmcif_boot_do_read(MMCIF_BASE, 512,
(no_bytes + SH_MMCIF_BBS - 1) / SH_MMCIF_BBS,
buf);
__raw_writel(__raw_readl(MSTPCR2) | 0x20000000, MSTPCR2);
mmcif_update_progress(MMCIF_PROGRESS_DONE);
}
