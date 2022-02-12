void __init usb_init_pool_max(void)
{
if (ARCH_KMALLOC_MINALIGN <= 32)
;
else if (ARCH_KMALLOC_MINALIGN <= 64)
pool_max[0] = 64;
else if (ARCH_KMALLOC_MINALIGN <= 128)
pool_max[0] = 0;
else
BUILD_BUG();
}
int hcd_buffer_create(struct usb_hcd *hcd)
{
char name[16];
int i, size;
if (!hcd->self.controller->dma_mask &&
!(hcd->driver->flags & HCD_LOCAL_MEM))
return 0;
for (i = 0; i < HCD_BUFFER_POOLS; i++) {
size = pool_max[i];
if (!size)
continue;
snprintf(name, sizeof name, "buffer-%d", size);
hcd->pool[i] = dma_pool_create(name, hcd->self.controller,
size, size, 0);
if (!hcd->pool[i]) {
hcd_buffer_destroy(hcd);
return -ENOMEM;
}
}
return 0;
}
void hcd_buffer_destroy(struct usb_hcd *hcd)
{
int i;
for (i = 0; i < HCD_BUFFER_POOLS; i++) {
struct dma_pool *pool = hcd->pool[i];
if (pool) {
dma_pool_destroy(pool);
hcd->pool[i] = NULL;
}
}
}
void *hcd_buffer_alloc(
struct usb_bus *bus,
size_t size,
gfp_t mem_flags,
dma_addr_t *dma
)
{
struct usb_hcd *hcd = bus_to_hcd(bus);
int i;
if (!bus->controller->dma_mask &&
!(hcd->driver->flags & HCD_LOCAL_MEM)) {
*dma = ~(dma_addr_t) 0;
return kmalloc(size, mem_flags);
}
for (i = 0; i < HCD_BUFFER_POOLS; i++) {
if (size <= pool_max[i])
return dma_pool_alloc(hcd->pool[i], mem_flags, dma);
}
return dma_alloc_coherent(hcd->self.controller, size, dma, mem_flags);
}
void hcd_buffer_free(
struct usb_bus *bus,
size_t size,
void *addr,
dma_addr_t dma
)
{
struct usb_hcd *hcd = bus_to_hcd(bus);
int i;
if (!addr)
return;
if (!bus->controller->dma_mask &&
!(hcd->driver->flags & HCD_LOCAL_MEM)) {
kfree(addr);
return;
}
for (i = 0; i < HCD_BUFFER_POOLS; i++) {
if (size <= pool_max[i]) {
dma_pool_free(hcd->pool[i], addr, dma);
return;
}
}
dma_free_coherent(hcd->self.controller, size, addr, dma);
}
