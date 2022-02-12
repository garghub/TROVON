struct _diva_dma_map_entry* diva_alloc_dma_map (void* os_context, int nentries) {
diva_dma_map_entry_t* pmap = diva_os_malloc(0, sizeof(*pmap)*(nentries+1));
if (pmap)
memset (pmap, 0, sizeof(*pmap)*(nentries+1));
return pmap;
}
void diva_free_dma_mapping (struct _diva_dma_map_entry* pmap) {
if (pmap) {
diva_os_free (0, pmap);
}
}
void diva_init_dma_map_entry (struct _diva_dma_map_entry* pmap,
int nr, void* virt, dword phys,
void* addr_handle) {
pmap[nr].phys_bus_addr = phys;
pmap[nr].local_ram_addr = virt;
pmap[nr].addr_handle = addr_handle;
}
int diva_alloc_dma_map_entry (struct _diva_dma_map_entry* pmap) {
int i;
for (i = 0; (pmap && pmap[i].local_ram_addr); i++) {
if (!pmap[i].busy) {
pmap[i].busy = 1;
return (i);
}
}
return (-1);
}
void diva_free_dma_map_entry (struct _diva_dma_map_entry* pmap, int nr) {
pmap[nr].busy = 0;
}
void diva_get_dma_map_entry (struct _diva_dma_map_entry* pmap, int nr,
void** pvirt, dword* pphys) {
*pphys = pmap[nr].phys_bus_addr;
*pvirt = pmap[nr].local_ram_addr;
}
void* diva_get_entry_handle (struct _diva_dma_map_entry* pmap, int nr) {
return (pmap[nr].addr_handle);
}
