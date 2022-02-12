void snd_dma_program(unsigned long dma,
unsigned long addr, unsigned int size,
unsigned short mode)
{
unsigned long flags;
flags = claim_dma_lock();
disable_dma(dma);
clear_dma_ff(dma);
set_dma_mode(dma, mode);
set_dma_addr(dma, addr);
set_dma_count(dma, size);
if (!(mode & DMA_MODE_NO_ENABLE))
enable_dma(dma);
release_dma_lock(flags);
}
void snd_dma_disable(unsigned long dma)
{
unsigned long flags;
flags = claim_dma_lock();
clear_dma_ff(dma);
disable_dma(dma);
release_dma_lock(flags);
}
unsigned int snd_dma_pointer(unsigned long dma, unsigned int size)
{
unsigned long flags;
unsigned int result, result1;
flags = claim_dma_lock();
clear_dma_ff(dma);
if (!isa_dma_bridge_buggy)
disable_dma(dma);
result = get_dma_residue(dma);
result1 = get_dma_residue(dma);
if (!isa_dma_bridge_buggy)
enable_dma(dma);
release_dma_lock(flags);
if (unlikely(result < result1))
result = result1;
#ifdef CONFIG_SND_DEBUG
if (result > size)
snd_printk(KERN_ERR "pointer (0x%x) for DMA #%ld is greater than transfer size (0x%x)\n", result, dma, size);
#endif
if (result >= size || result == 0)
return 0;
else
return size - result;
}
