void memcpy_toshmem(int card, void *dest, const void *src, size_t n)
{
unsigned long flags;
unsigned char ch;
unsigned long dest_rem = ((unsigned long) dest) % 0x4000;
if (!IS_VALID_CARD(card)) {
pr_debug("Invalid param: %d is not a valid card id\n", card);
return;
}
if (n > SRAM_PAGESIZE)
return;
ch = (unsigned long) dest / SRAM_PAGESIZE;
pr_debug("%s: loaded page %d\n", sc_adapter[card]->devicename,ch);
spin_lock_irqsave(&sc_adapter[card]->lock, flags);
outb(((sc_adapter[card]->shmem_magic + ch * SRAM_PAGESIZE) >> 14) | 0x80,
sc_adapter[card]->ioport[sc_adapter[card]->shmem_pgport]);
memcpy_toio((void __iomem *)(sc_adapter[card]->rambase + dest_rem), src, n);
spin_unlock_irqrestore(&sc_adapter[card]->lock, flags);
pr_debug("%s: set page to %#x\n",sc_adapter[card]->devicename,
((sc_adapter[card]->shmem_magic + ch * SRAM_PAGESIZE)>>14)|0x80);
pr_debug("%s: copying %zu bytes from %#lx to %#lx\n",
sc_adapter[card]->devicename, n,
(unsigned long) src,
sc_adapter[card]->rambase + ((unsigned long) dest %0x4000));
}
void memcpy_fromshmem(int card, void *dest, const void *src, size_t n)
{
unsigned long flags;
unsigned char ch;
if(!IS_VALID_CARD(card)) {
pr_debug("Invalid param: %d is not a valid card id\n", card);
return;
}
if(n > SRAM_PAGESIZE) {
return;
}
ch = (unsigned long) src / SRAM_PAGESIZE;
pr_debug("%s: loaded page %d\n", sc_adapter[card]->devicename,ch);
spin_lock_irqsave(&sc_adapter[card]->lock, flags);
outb(((sc_adapter[card]->shmem_magic + ch * SRAM_PAGESIZE) >> 14) | 0x80,
sc_adapter[card]->ioport[sc_adapter[card]->shmem_pgport]);
memcpy_fromio(dest,(void *)(sc_adapter[card]->rambase +
((unsigned long) src % 0x4000)), n);
spin_unlock_irqrestore(&sc_adapter[card]->lock, flags);
pr_debug("%s: set page to %#x\n",sc_adapter[card]->devicename,
((sc_adapter[card]->shmem_magic + ch * SRAM_PAGESIZE)>>14)|0x80);
}
