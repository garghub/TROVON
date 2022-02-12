static void i8237A_resume(void)
{
unsigned long flags;
int i;
flags = claim_dma_lock();
dma_outb(0, DMA1_RESET_REG);
dma_outb(0, DMA2_RESET_REG);
for (i = 0; i < 8; i++) {
set_dma_addr(i, 0x000000);
set_dma_count(i, 1);
}
enable_dma(4);
release_dma_lock(flags);
}
static int __init i8237A_init_ops(void)
{
register_syscore_ops(&i8237_syscore_ops);
return 0;
}
