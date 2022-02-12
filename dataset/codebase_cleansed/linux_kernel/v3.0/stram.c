void __init atari_stram_init(void)
{
int i;
for( i = 0; i < N_STATIC_BLOCKS; ++i )
static_blocks[i].flags = BLOCK_FREE;
stram_start = phys_to_virt(0);
kernel_in_stram = (stram_start == 0);
for( i = 0; i < m68k_num_memory; ++i ) {
if (m68k_memory[i].addr == 0) {
stram_end = stram_start + m68k_memory[i].size;
return;
}
}
panic( "atari_stram_init: no ST-RAM found!" );
}
void __init atari_stram_reserve_pages(void *start_mem)
{
if (!kernel_in_stram)
reserve_bootmem(0, PAGE_SIZE, BOOTMEM_DEFAULT);
}
void atari_stram_mem_init_hook (void)
{
mem_init_done = 1;
}
void *atari_stram_alloc(long size, const char *owner)
{
void *addr = NULL;
BLOCK *block;
int flags;
DPRINTK("atari_stram_alloc(size=%08lx,owner=%s)\n", size, owner);
if (!mem_init_done)
return alloc_bootmem_low(size);
else {
addr = (void *)__get_dma_pages(GFP_KERNEL, get_order(size));
flags = BLOCK_GFP;
DPRINTK( "atari_stram_alloc: after mem_init, "
"get_pages=%p\n", addr );
}
if (addr) {
if (!(block = add_region( addr, size ))) {
DPRINTK( "atari_stram_alloc: out of mem for BLOCK -- "
"freeing again\n" );
free_pages((unsigned long)addr, get_order(size));
return( NULL );
}
block->owner = owner;
block->flags |= flags;
}
return( addr );
}
void atari_stram_free( void *addr )
{
BLOCK *block;
DPRINTK( "atari_stram_free(addr=%p)\n", addr );
if (!(block = find_region( addr ))) {
printk( KERN_ERR "Attempt to free non-allocated ST-RAM block at %p "
"from %p\n", addr, __builtin_return_address(0) );
return;
}
DPRINTK( "atari_stram_free: found block (%p): size=%08lx, owner=%s, "
"flags=%02x\n", block, block->size, block->owner, block->flags );
if (!(block->flags & BLOCK_GFP))
goto fail;
DPRINTK("atari_stram_free: is kmalloced, order_size=%d\n",
get_order(block->size));
free_pages((unsigned long)addr, get_order(block->size));
remove_region( block );
return;
fail:
printk( KERN_ERR "atari_stram_free: cannot free block at %p "
"(called from %p)\n", addr, __builtin_return_address(0) );
}
static BLOCK *add_region( void *addr, unsigned long size )
{
BLOCK **p, *n = NULL;
int i;
for( i = 0; i < N_STATIC_BLOCKS; ++i ) {
if (static_blocks[i].flags & BLOCK_FREE) {
n = &static_blocks[i];
n->flags = 0;
break;
}
}
if (!n && mem_init_done) {
n = kmalloc( sizeof(BLOCK), GFP_KERNEL );
if (n)
n->flags = BLOCK_KMALLOCED;
}
if (!n) {
printk( KERN_ERR "Out of memory for ST-RAM descriptor blocks\n" );
return( NULL );
}
n->start = addr;
n->size = size;
for( p = &alloc_list; *p; p = &((*p)->next) )
if ((*p)->start > addr) break;
n->next = *p;
*p = n;
return( n );
}
static BLOCK *find_region( void *addr )
{
BLOCK *p;
for( p = alloc_list; p; p = p->next ) {
if (p->start == addr)
return( p );
if (p->start > addr)
break;
}
return( NULL );
}
static int remove_region( BLOCK *block )
{
BLOCK **p;
for( p = &alloc_list; *p; p = &((*p)->next) )
if (*p == block) break;
if (!*p)
return( 0 );
*p = block->next;
if (block->flags & BLOCK_KMALLOCED)
kfree( block );
else
block->flags |= BLOCK_FREE;
return( 1 );
}
static int stram_proc_show(struct seq_file *m, void *v)
{
BLOCK *p;
PRINT_PROC("Total ST-RAM: %8u kB\n",
(stram_end - stram_start) >> 10);
PRINT_PROC( "Allocated regions:\n" );
for( p = alloc_list; p; p = p->next ) {
PRINT_PROC("0x%08lx-0x%08lx: %s (",
virt_to_phys(p->start),
virt_to_phys(p->start+p->size-1),
p->owner);
if (p->flags & BLOCK_GFP)
PRINT_PROC( "page-alloced)\n" );
else
PRINT_PROC( "??)\n" );
}
return 0;
}
static int stram_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, stram_proc_show, NULL);
}
static int __init proc_stram_init(void)
{
proc_create("stram", 0, NULL, &stram_proc_fops);
return 0;
}
