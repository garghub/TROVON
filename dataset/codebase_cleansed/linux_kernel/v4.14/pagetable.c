static void *alloc_pgt_page(void *context)
{
struct alloc_pgt_data *pages = (struct alloc_pgt_data *)context;
unsigned char *entry;
if (pages->pgt_buf_offset >= pages->pgt_buf_size) {
debug_putstr("out of pgt_buf in " __FILE__ "!?\n");
debug_putaddr(pages->pgt_buf_offset);
debug_putaddr(pages->pgt_buf_size);
return NULL;
}
entry = pages->pgt_buf + pages->pgt_buf_offset;
pages->pgt_buf_offset += PAGE_SIZE;
return entry;
}
void initialize_identity_maps(void)
{
mapping_info.alloc_pgt_page = alloc_pgt_page;
mapping_info.context = &pgt_data;
pgt_data.pgt_buf_offset = 0;
top_level_pgt = read_cr3_pa();
if (p4d_offset((pgd_t *)top_level_pgt, 0) == (p4d_t *)_pgtable) {
debug_putstr("booted via startup_32()\n");
pgt_data.pgt_buf = _pgtable + BOOT_INIT_PGT_SIZE;
pgt_data.pgt_buf_size = BOOT_PGT_SIZE - BOOT_INIT_PGT_SIZE;
memset(pgt_data.pgt_buf, 0, pgt_data.pgt_buf_size);
} else {
debug_putstr("booted via startup_64()\n");
pgt_data.pgt_buf = _pgtable;
pgt_data.pgt_buf_size = BOOT_PGT_SIZE;
memset(pgt_data.pgt_buf, 0, pgt_data.pgt_buf_size);
top_level_pgt = (unsigned long)alloc_pgt_page(&pgt_data);
}
}
void add_identity_map(unsigned long start, unsigned long size)
{
unsigned long end = start + size;
start = round_down(start, PMD_SIZE);
end = round_up(end, PMD_SIZE);
if (start >= end)
return;
kernel_ident_mapping_init(&mapping_info, (pgd_t *)top_level_pgt,
start, end);
}
void finalize_identity_maps(void)
{
write_cr3(top_level_pgt);
}
