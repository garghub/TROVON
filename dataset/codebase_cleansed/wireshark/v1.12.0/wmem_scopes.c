wmem_allocator_t *
wmem_packet_scope(void)
{
g_assert(packet_scope);
return packet_scope;
}
void
wmem_enter_packet_scope(void)
{
g_assert(packet_scope);
g_assert(file_scope->in_scope);
g_assert(!packet_scope->in_scope);
packet_scope->in_scope = TRUE;
}
void
wmem_leave_packet_scope(void)
{
g_assert(packet_scope);
g_assert(packet_scope->in_scope);
wmem_free_all(packet_scope);
packet_scope->in_scope = FALSE;
}
wmem_allocator_t *
wmem_file_scope(void)
{
g_assert(file_scope);
return file_scope;
}
void
wmem_enter_file_scope(void)
{
g_assert(file_scope);
g_assert(!file_scope->in_scope);
file_scope->in_scope = TRUE;
}
void
wmem_leave_file_scope(void)
{
g_assert(file_scope);
g_assert(file_scope->in_scope);
g_assert(!packet_scope->in_scope);
wmem_free_all(file_scope);
file_scope->in_scope = FALSE;
wmem_gc(file_scope);
wmem_gc(packet_scope);
}
wmem_allocator_t *
wmem_epan_scope(void)
{
g_assert(epan_scope);
return epan_scope;
}
void
wmem_init_scopes(void)
{
g_assert(packet_scope == NULL);
g_assert(file_scope == NULL);
g_assert(epan_scope == NULL);
packet_scope = wmem_allocator_new(WMEM_ALLOCATOR_BLOCK_FAST);
file_scope = wmem_allocator_new(WMEM_ALLOCATOR_BLOCK);
epan_scope = wmem_allocator_new(WMEM_ALLOCATOR_SIMPLE);
packet_scope->in_scope = FALSE;
file_scope->in_scope = FALSE;
}
void
wmem_cleanup_scopes(void)
{
g_assert(packet_scope);
g_assert(file_scope);
g_assert(epan_scope);
g_assert(packet_scope->in_scope == FALSE);
g_assert(file_scope->in_scope == FALSE);
wmem_destroy_allocator(packet_scope);
wmem_destroy_allocator(file_scope);
wmem_destroy_allocator(epan_scope);
packet_scope = NULL;
file_scope = NULL;
epan_scope = NULL;
}
