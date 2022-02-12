int of_get_dma_window(struct device_node *dn, const char *prefix, int index,
unsigned long *busno, dma_addr_t *addr, size_t *size)
{
const __be32 *dma_window, *end;
int bytes, cur_index = 0;
char propname[NAME_MAX], addrname[NAME_MAX], sizename[NAME_MAX];
if (!dn || !addr || !size)
return -EINVAL;
if (!prefix)
prefix = "";
snprintf(propname, sizeof(propname), "%sdma-window", prefix);
snprintf(addrname, sizeof(addrname), "%s#dma-address-cells", prefix);
snprintf(sizename, sizeof(sizename), "%s#dma-size-cells", prefix);
dma_window = of_get_property(dn, propname, &bytes);
if (!dma_window)
return -ENODEV;
end = dma_window + bytes / sizeof(*dma_window);
while (dma_window < end) {
u32 cells;
const void *prop;
if (busno)
*busno = be32_to_cpup(dma_window++);
prop = of_get_property(dn, addrname, NULL);
if (!prop)
prop = of_get_property(dn, "#address-cells", NULL);
cells = prop ? be32_to_cpup(prop) : of_n_addr_cells(dn);
if (!cells)
return -EINVAL;
*addr = of_read_number(dma_window, cells);
dma_window += cells;
prop = of_get_property(dn, sizename, NULL);
cells = prop ? be32_to_cpup(prop) : of_n_size_cells(dn);
if (!cells)
return -EINVAL;
*size = of_read_number(dma_window, cells);
dma_window += cells;
if (cur_index++ == index)
break;
}
return 0;
}
