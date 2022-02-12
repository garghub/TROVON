static int cvm_oct_fill_hw_skbuff(int pool, int size, int elements)
{
int freed = elements;
while (freed) {
struct sk_buff *skb = dev_alloc_skb(size + 256);
if (unlikely(skb == NULL))
break;
skb_reserve(skb, 256 - (((unsigned long)skb->data) & 0x7f));
*(struct sk_buff **)(skb->data - sizeof(void *)) = skb;
cvmx_fpa_free(skb->data, pool, size / 128);
freed--;
}
return elements - freed;
}
static void cvm_oct_free_hw_skbuff(int pool, int size, int elements)
{
char *memory;
do {
memory = cvmx_fpa_alloc(pool);
if (memory) {
struct sk_buff *skb =
*(struct sk_buff **)(memory - sizeof(void *));
elements--;
dev_kfree_skb(skb);
}
} while (memory);
if (elements < 0)
pr_warn("Freeing of pool %u had too many skbuffs (%d)\n",
pool, elements);
else if (elements > 0)
pr_warn("Freeing of pool %u is missing %d skbuffs\n",
pool, elements);
}
static int cvm_oct_fill_hw_memory(int pool, int size, int elements)
{
char *memory;
char *fpa;
int freed = elements;
while (freed) {
memory = kmalloc(size + 256, GFP_ATOMIC);
if (unlikely(memory == NULL)) {
pr_warn("Unable to allocate %u bytes for FPA pool %d\n",
elements * size, pool);
break;
}
fpa = (char *)(((unsigned long)memory + 256) & ~0x7fUL);
*((char **)fpa - 1) = memory;
cvmx_fpa_free(fpa, pool, 0);
freed--;
}
return elements - freed;
}
static void cvm_oct_free_hw_memory(int pool, int size, int elements)
{
char *memory;
char *fpa;
do {
fpa = cvmx_fpa_alloc(pool);
if (fpa) {
elements--;
fpa = (char *)phys_to_virt(cvmx_ptr_to_phys(fpa));
memory = *((char **)fpa - 1);
kfree(memory);
}
} while (fpa);
if (elements < 0)
pr_warn("Freeing of pool %u had too many buffers (%d)\n",
pool, elements);
else if (elements > 0)
pr_warn("Warning: Freeing of pool %u is missing %d buffers\n",
pool, elements);
}
int cvm_oct_mem_fill_fpa(int pool, int size, int elements)
{
int freed;
if (pool == CVMX_FPA_PACKET_POOL)
freed = cvm_oct_fill_hw_skbuff(pool, size, elements);
else
freed = cvm_oct_fill_hw_memory(pool, size, elements);
return freed;
}
void cvm_oct_mem_empty_fpa(int pool, int size, int elements)
{
if (pool == CVMX_FPA_PACKET_POOL)
cvm_oct_free_hw_skbuff(pool, size, elements);
else
cvm_oct_free_hw_memory(pool, size, elements);
}
