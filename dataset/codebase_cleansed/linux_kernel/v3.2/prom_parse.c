void of_parse_dma_window(struct device_node *dn, const void *dma_window_prop,
unsigned long *busno, unsigned long *phys, unsigned long *size)
{
const u32 *dma_window;
u32 cells;
const unsigned char *prop;
dma_window = dma_window_prop;
*busno = *(dma_window++);
prop = of_get_property(dn, "ibm,#dma-address-cells", NULL);
if (!prop)
prop = of_get_property(dn, "#address-cells", NULL);
cells = prop ? *(u32 *)prop : of_n_addr_cells(dn);
*phys = of_read_number(dma_window, cells);
dma_window += cells;
prop = of_get_property(dn, "ibm,#dma-size-cells", NULL);
cells = prop ? *(u32 *)prop : of_n_size_cells(dn);
*size = of_read_number(dma_window, cells);
}
