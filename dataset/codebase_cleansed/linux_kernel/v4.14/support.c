int pnp_is_active(struct pnp_dev *dev)
{
if (!pnp_port_start(dev, 0) && pnp_port_len(dev, 0) <= 1 &&
!pnp_mem_start(dev, 0) && pnp_mem_len(dev, 0) <= 1 &&
pnp_irq(dev, 0) == -1 && pnp_dma(dev, 0) == -1)
return 0;
else
return 1;
}
void pnp_eisa_id_to_string(u32 id, char *str)
{
id = be32_to_cpu(id);
str[0] = 'A' + ((id >> 26) & 0x3f) - 1;
str[1] = 'A' + ((id >> 21) & 0x1f) - 1;
str[2] = 'A' + ((id >> 16) & 0x1f) - 1;
str[3] = hex_asc_hi(id >> 8);
str[4] = hex_asc_lo(id >> 8);
str[5] = hex_asc_hi(id);
str[6] = hex_asc_lo(id);
str[7] = '\0';
}
char *pnp_resource_type_name(struct resource *res)
{
switch (pnp_resource_type(res)) {
case IORESOURCE_IO:
return "io";
case IORESOURCE_MEM:
return "mem";
case IORESOURCE_IRQ:
return "irq";
case IORESOURCE_DMA:
return "dma";
case IORESOURCE_BUS:
return "bus";
}
return "unknown";
}
void dbg_pnp_show_resources(struct pnp_dev *dev, char *desc)
{
struct pnp_resource *pnp_res;
if (list_empty(&dev->resources))
pnp_dbg(&dev->dev, "%s: no current resources\n", desc);
else {
pnp_dbg(&dev->dev, "%s: current resources:\n", desc);
list_for_each_entry(pnp_res, &dev->resources, list)
pnp_dbg(&dev->dev, "%pr\n", &pnp_res->res);
}
}
char *pnp_option_priority_name(struct pnp_option *option)
{
switch (pnp_option_priority(option)) {
case PNP_RES_PRIORITY_PREFERRED:
return "preferred";
case PNP_RES_PRIORITY_ACCEPTABLE:
return "acceptable";
case PNP_RES_PRIORITY_FUNCTIONAL:
return "functional";
}
return "invalid";
}
void dbg_pnp_show_option(struct pnp_dev *dev, struct pnp_option *option)
{
char buf[128];
int len = 0, i;
struct pnp_port *port;
struct pnp_mem *mem;
struct pnp_irq *irq;
struct pnp_dma *dma;
if (pnp_option_is_dependent(option))
len += scnprintf(buf + len, sizeof(buf) - len,
" dependent set %d (%s) ",
pnp_option_set(option),
pnp_option_priority_name(option));
else
len += scnprintf(buf + len, sizeof(buf) - len,
" independent ");
switch (option->type) {
case IORESOURCE_IO:
port = &option->u.port;
len += scnprintf(buf + len, sizeof(buf) - len, "io min %#llx "
"max %#llx align %lld size %lld flags %#x",
(unsigned long long) port->min,
(unsigned long long) port->max,
(unsigned long long) port->align,
(unsigned long long) port->size, port->flags);
break;
case IORESOURCE_MEM:
mem = &option->u.mem;
len += scnprintf(buf + len, sizeof(buf) - len, "mem min %#llx "
"max %#llx align %lld size %lld flags %#x",
(unsigned long long) mem->min,
(unsigned long long) mem->max,
(unsigned long long) mem->align,
(unsigned long long) mem->size, mem->flags);
break;
case IORESOURCE_IRQ:
irq = &option->u.irq;
len += scnprintf(buf + len, sizeof(buf) - len, "irq");
if (bitmap_empty(irq->map.bits, PNP_IRQ_NR))
len += scnprintf(buf + len, sizeof(buf) - len,
" <none>");
else {
for (i = 0; i < PNP_IRQ_NR; i++)
if (test_bit(i, irq->map.bits))
len += scnprintf(buf + len,
sizeof(buf) - len,
" %d", i);
}
len += scnprintf(buf + len, sizeof(buf) - len, " flags %#x",
irq->flags);
if (irq->flags & IORESOURCE_IRQ_OPTIONAL)
len += scnprintf(buf + len, sizeof(buf) - len,
" (optional)");
break;
case IORESOURCE_DMA:
dma = &option->u.dma;
len += scnprintf(buf + len, sizeof(buf) - len, "dma");
if (!dma->map)
len += scnprintf(buf + len, sizeof(buf) - len,
" <none>");
else {
for (i = 0; i < 8; i++)
if (dma->map & (1 << i))
len += scnprintf(buf + len,
sizeof(buf) - len,
" %d", i);
}
len += scnprintf(buf + len, sizeof(buf) - len, " (bitmask %#x) "
"flags %#x", dma->map, dma->flags);
break;
}
pnp_dbg(&dev->dev, "%s\n", buf);
}
