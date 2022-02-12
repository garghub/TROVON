asmlinkage void mmc_loader(unsigned short *buf, unsigned long len)
{
int high_capacity;
mmc_init_progress();
mmc_update_progress(MMC_PROGRESS_ENTER);
__raw_writeb(CR_FUNCTION1, PORT184CR);
__raw_writeb(CR_INPUT_ENABLE|CR_FUNCTION1, PORT179CR);
__raw_writeb(CR_FUNCTION1, PORT183CR);
__raw_writeb(CR_FUNCTION1, PORT182CR);
__raw_writeb(CR_FUNCTION1, PORT181CR);
__raw_writeb(CR_FUNCTION1, PORT180CR);
__raw_writel(__raw_readl(SMSTPCR3) & ~(1 << 13), SMSTPCR3);
mmc_update_progress(MMC_PROGRESS_INIT);
high_capacity = sdhi_boot_init(SDHI_BASE);
if (high_capacity < 0)
goto err;
mmc_update_progress(MMC_PROGRESS_LOAD);
if (sdhi_boot_do_read(SDHI_BASE, high_capacity,
0,
(len + TMIO_BBS - 1) / TMIO_BBS, buf))
goto err;
__raw_writel(__raw_readl(SMSTPCR3) | (1 << 13), SMSTPCR3);
mmc_update_progress(MMC_PROGRESS_DONE);
return;
err:
for(;;);
}
