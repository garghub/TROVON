static void find_memory_chunks(struct mem_chunk chunk[])
{
unsigned long long memsize, rnmax, rzm;
unsigned long addr = 0, size;
int i = 0, type;
rzm = sclp_get_rzm();
rnmax = sclp_get_rnmax();
memsize = rzm * rnmax;
if (!rzm)
rzm = 1ULL << 17;
if (sizeof(long) == 4) {
rzm = min(ADDR2G, rzm);
memsize = memsize ? min(ADDR2G, memsize) : ADDR2G;
}
do {
size = 0;
type = tprot(addr);
do {
size += rzm;
if (memsize && addr + size >= memsize)
break;
} while (type == tprot(addr + size));
if (type == CHUNK_READ_WRITE || type == CHUNK_READ_ONLY) {
chunk[i].addr = addr;
chunk[i].size = size;
chunk[i].type = type;
i++;
}
addr += size;
} while (addr < memsize && i < MEMORY_CHUNKS);
}
void detect_memory_layout(struct mem_chunk chunk[])
{
unsigned long flags, cr0;
memset(chunk, 0, MEMORY_CHUNKS * sizeof(struct mem_chunk));
flags = __arch_local_irq_stnsm(0xf8);
__ctl_store(cr0, 0, 0);
__ctl_clear_bit(0, 28);
find_memory_chunks(chunk);
__ctl_load(cr0, 0, 0);
arch_local_irq_restore(flags);
}
