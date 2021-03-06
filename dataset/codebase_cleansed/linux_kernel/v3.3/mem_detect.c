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
static void mem_chunk_move(struct mem_chunk chunk[], int to, int from)
{
int cnt = MEMORY_CHUNKS - to;
memmove(&chunk[to], &chunk[from], cnt * sizeof(struct mem_chunk));
}
static void mem_chunk_init(struct mem_chunk *chunk, unsigned long addr,
unsigned long size, int type)
{
chunk->type = type;
chunk->addr = addr;
chunk->size = size;
}
void create_mem_hole(struct mem_chunk chunk[], unsigned long addr,
unsigned long size, int type)
{
unsigned long lh_start, lh_end, lh_size, ch_start, ch_end, ch_size;
int i, ch_type;
for (i = 0; i < MEMORY_CHUNKS; i++) {
if (chunk[i].size == 0)
continue;
ch_start = chunk[i].addr;
ch_size = chunk[i].size;
ch_end = ch_start + ch_size - 1;
ch_type = chunk[i].type;
if (addr + size <= ch_start)
continue;
if (addr > ch_end)
continue;
lh_start = max(addr, chunk[i].addr);
lh_end = min(addr + size - 1, ch_end);
lh_size = lh_end - lh_start + 1;
if (lh_start == ch_start && lh_end == ch_end) {
mem_chunk_init(&chunk[i], lh_start, lh_size, type);
} else if (lh_end == ch_end) {
mem_chunk_move(chunk, i + 1, i);
mem_chunk_init(&chunk[i], ch_start, ch_size - lh_size,
ch_type);
mem_chunk_init(&chunk[i + 1], lh_start, lh_size, type);
i += 1;
} else if (lh_start == ch_start) {
mem_chunk_move(chunk, i + 1, i);
mem_chunk_init(&chunk[i], lh_start, lh_size, type);
mem_chunk_init(&chunk[i + 1], lh_end + 1,
ch_size - lh_size, ch_type);
break;
} else {
mem_chunk_move(chunk, i + 2, i);
mem_chunk_init(&chunk[i], ch_start,
lh_start - ch_start, ch_type);
mem_chunk_init(&chunk[i + 1], lh_start, lh_size, type);
mem_chunk_init(&chunk[i + 2], lh_end + 1,
ch_end - lh_end, ch_type);
break;
}
}
}
