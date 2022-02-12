static int faraday_res_to_memcfg(resource_size_t mem_base,
resource_size_t mem_size, u32 *val)
{
u32 outval;
switch (mem_size) {
case SZ_1M:
outval = FARADAY_PCI_MEMSIZE_1MB;
break;
case SZ_2M:
outval = FARADAY_PCI_MEMSIZE_2MB;
break;
case SZ_4M:
outval = FARADAY_PCI_MEMSIZE_4MB;
break;
case SZ_8M:
outval = FARADAY_PCI_MEMSIZE_8MB;
break;
case SZ_16M:
outval = FARADAY_PCI_MEMSIZE_16MB;
break;
case SZ_32M:
outval = FARADAY_PCI_MEMSIZE_32MB;
break;
case SZ_64M:
outval = FARADAY_PCI_MEMSIZE_64MB;
break;
case SZ_128M:
outval = FARADAY_PCI_MEMSIZE_128MB;
break;
case SZ_256M:
outval = FARADAY_PCI_MEMSIZE_256MB;
break;
case SZ_512M:
outval = FARADAY_PCI_MEMSIZE_512MB;
break;
case SZ_1G:
outval = FARADAY_PCI_MEMSIZE_1GB;
break;
case SZ_2G:
outval = FARADAY_PCI_MEMSIZE_2GB;
break;
default:
return -EINVAL;
}
outval <<= FARADAY_PCI_MEMSIZE_SHIFT;
if (mem_base & ~(FARADAY_PCI_MEMBASE_MASK))
pr_warn("truncated PCI memory base\n");
outval |= (mem_base & FARADAY_PCI_MEMBASE_MASK);
pr_debug("Translated pci base @%pap, size %pap to config %08x\n",
&mem_base, &mem_size, outval);
*val = outval;
return 0;
}
static int faraday_raw_pci_read_config(struct faraday_pci *p, int bus_number,
unsigned int fn, int config, int size,
u32 *value)
{
writel(PCI_CONF_BUS(bus_number) |
PCI_CONF_DEVICE(PCI_SLOT(fn)) |
PCI_CONF_FUNCTION(PCI_FUNC(fn)) |
PCI_CONF_WHERE(config) |
PCI_CONF_ENABLE,
p->base + PCI_CONFIG);
*value = readl(p->base + PCI_DATA);
if (size == 1)
*value = (*value >> (8 * (config & 3))) & 0xFF;
else if (size == 2)
*value = (*value >> (8 * (config & 3))) & 0xFFFF;
return PCIBIOS_SUCCESSFUL;
}
static int faraday_pci_read_config(struct pci_bus *bus, unsigned int fn,
int config, int size, u32 *value)
{
struct faraday_pci *p = bus->sysdata;
dev_dbg(&bus->dev,
"[read] slt: %.2d, fnc: %d, cnf: 0x%.2X, val (%d bytes): 0x%.8X\n",
PCI_SLOT(fn), PCI_FUNC(fn), config, size, *value);
return faraday_raw_pci_read_config(p, bus->number, fn, config, size, value);
}
static int faraday_raw_pci_write_config(struct faraday_pci *p, int bus_number,
unsigned int fn, int config, int size,
u32 value)
{
int ret = PCIBIOS_SUCCESSFUL;
writel(PCI_CONF_BUS(bus_number) |
PCI_CONF_DEVICE(PCI_SLOT(fn)) |
PCI_CONF_FUNCTION(PCI_FUNC(fn)) |
PCI_CONF_WHERE(config) |
PCI_CONF_ENABLE,
p->base + PCI_CONFIG);
switch (size) {
case 4:
writel(value, p->base + PCI_DATA);
break;
case 2:
writew(value, p->base + PCI_DATA + (config & 3));
break;
case 1:
writeb(value, p->base + PCI_DATA + (config & 3));
break;
default:
ret = PCIBIOS_BAD_REGISTER_NUMBER;
}
return ret;
}
static int faraday_pci_write_config(struct pci_bus *bus, unsigned int fn,
int config, int size, u32 value)
{
struct faraday_pci *p = bus->sysdata;
dev_dbg(&bus->dev,
"[write] slt: %.2d, fnc: %d, cnf: 0x%.2X, val (%d bytes): 0x%.8X\n",
PCI_SLOT(fn), PCI_FUNC(fn), config, size, value);
return faraday_raw_pci_write_config(p, bus->number, fn, config, size,
value);
}
static void faraday_pci_ack_irq(struct irq_data *d)
{
struct faraday_pci *p = irq_data_get_irq_chip_data(d);
unsigned int reg;
faraday_raw_pci_read_config(p, 0, 0, FARADAY_PCI_CTRL2, 4, &reg);
reg &= ~(0xF << PCI_CTRL2_INTSTS_SHIFT);
reg |= BIT(irqd_to_hwirq(d) + PCI_CTRL2_INTSTS_SHIFT);
faraday_raw_pci_write_config(p, 0, 0, FARADAY_PCI_CTRL2, 4, reg);
}
static void faraday_pci_mask_irq(struct irq_data *d)
{
struct faraday_pci *p = irq_data_get_irq_chip_data(d);
unsigned int reg;
faraday_raw_pci_read_config(p, 0, 0, FARADAY_PCI_CTRL2, 4, &reg);
reg &= ~((0xF << PCI_CTRL2_INTSTS_SHIFT)
| BIT(irqd_to_hwirq(d) + PCI_CTRL2_INTMASK_SHIFT));
faraday_raw_pci_write_config(p, 0, 0, FARADAY_PCI_CTRL2, 4, reg);
}
static void faraday_pci_unmask_irq(struct irq_data *d)
{
struct faraday_pci *p = irq_data_get_irq_chip_data(d);
unsigned int reg;
faraday_raw_pci_read_config(p, 0, 0, FARADAY_PCI_CTRL2, 4, &reg);
reg &= ~(0xF << PCI_CTRL2_INTSTS_SHIFT);
reg |= BIT(irqd_to_hwirq(d) + PCI_CTRL2_INTMASK_SHIFT);
faraday_raw_pci_write_config(p, 0, 0, FARADAY_PCI_CTRL2, 4, reg);
}
static void faraday_pci_irq_handler(struct irq_desc *desc)
{
struct faraday_pci *p = irq_desc_get_handler_data(desc);
struct irq_chip *irqchip = irq_desc_get_chip(desc);
unsigned int irq_stat, reg, i;
faraday_raw_pci_read_config(p, 0, 0, FARADAY_PCI_CTRL2, 4, &reg);
irq_stat = reg >> PCI_CTRL2_INTSTS_SHIFT;
chained_irq_enter(irqchip, desc);
for (i = 0; i < 4; i++) {
if ((irq_stat & BIT(i)) == 0)
continue;
generic_handle_irq(irq_find_mapping(p->irqdomain, i));
}
chained_irq_exit(irqchip, desc);
}
static int faraday_pci_irq_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &faraday_pci_irq_chip, handle_level_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
static int faraday_pci_setup_cascaded_irq(struct faraday_pci *p)
{
struct device_node *intc = of_get_next_child(p->dev->of_node, NULL);
int irq;
int i;
if (!intc) {
dev_err(p->dev, "missing child interrupt-controller node\n");
return -EINVAL;
}
irq = of_irq_get(intc, 0);
if (irq <= 0) {
dev_err(p->dev, "failed to get parent IRQ\n");
return irq ?: -EINVAL;
}
p->irqdomain = irq_domain_add_linear(intc, PCI_NUM_INTX,
&faraday_pci_irqdomain_ops, p);
if (!p->irqdomain) {
dev_err(p->dev, "failed to create Gemini PCI IRQ domain\n");
return -EINVAL;
}
irq_set_chained_handler_and_data(irq, faraday_pci_irq_handler, p);
for (i = 0; i < 4; i++)
irq_create_mapping(p->irqdomain, i);
return 0;
}
static int pci_dma_range_parser_init(struct of_pci_range_parser *parser,
struct device_node *node)
{
const int na = 3, ns = 2;
int rlen;
parser->node = node;
parser->pna = of_n_addr_cells(node);
parser->np = parser->pna + na + ns;
parser->range = of_get_property(node, "dma-ranges", &rlen);
if (!parser->range)
return -ENOENT;
parser->end = parser->range + rlen / sizeof(__be32);
return 0;
}
static int faraday_pci_parse_map_dma_ranges(struct faraday_pci *p,
struct device_node *np)
{
struct of_pci_range range;
struct of_pci_range_parser parser;
struct device *dev = p->dev;
u32 confreg[3] = {
FARADAY_PCI_MEM1_BASE_SIZE,
FARADAY_PCI_MEM2_BASE_SIZE,
FARADAY_PCI_MEM3_BASE_SIZE,
};
int i = 0;
u32 val;
if (pci_dma_range_parser_init(&parser, np)) {
dev_err(dev, "missing dma-ranges property\n");
return -EINVAL;
}
for_each_of_pci_range(&parser, &range) {
u64 end = range.pci_addr + range.size - 1;
int ret;
ret = faraday_res_to_memcfg(range.pci_addr, range.size, &val);
if (ret) {
dev_err(dev,
"DMA range %d: illegal MEM resource size\n", i);
return -EINVAL;
}
dev_info(dev, "DMA MEM%d BASE: 0x%016llx -> 0x%016llx config %08x\n",
i + 1, range.pci_addr, end, val);
if (i <= 2) {
faraday_raw_pci_write_config(p, 0, 0, confreg[i],
4, val);
} else {
dev_err(dev, "ignore extraneous dma-range %d\n", i);
break;
}
i++;
}
return 0;
}
static int faraday_pci_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct faraday_pci_variant *variant =
of_device_get_match_data(dev);
struct resource *regs;
resource_size_t io_base;
struct resource_entry *win;
struct faraday_pci *p;
struct resource *mem;
struct resource *io;
struct pci_host_bridge *host;
struct clk *clk;
unsigned char max_bus_speed = PCI_SPEED_33MHz;
unsigned char cur_bus_speed = PCI_SPEED_33MHz;
int ret;
u32 val;
LIST_HEAD(res);
host = devm_pci_alloc_host_bridge(dev, sizeof(*p));
if (!host)
return -ENOMEM;
host->dev.parent = dev;
host->ops = &faraday_pci_ops;
host->busnr = 0;
host->msi = NULL;
host->map_irq = of_irq_parse_and_map_pci;
host->swizzle_irq = pci_common_swizzle;
p = pci_host_bridge_priv(host);
host->sysdata = p;
p->dev = dev;
clk = devm_clk_get(dev, "PCLK");
if (IS_ERR(clk))
return PTR_ERR(clk);
ret = clk_prepare_enable(clk);
if (ret) {
dev_err(dev, "could not prepare PCLK\n");
return ret;
}
p->bus_clk = devm_clk_get(dev, "PCICLK");
if (IS_ERR(p->bus_clk))
return PTR_ERR(clk);
ret = clk_prepare_enable(p->bus_clk);
if (ret) {
dev_err(dev, "could not prepare PCICLK\n");
return ret;
}
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
p->base = devm_ioremap_resource(dev, regs);
if (IS_ERR(p->base))
return PTR_ERR(p->base);
ret = of_pci_get_host_bridge_resources(dev->of_node, 0, 0xff,
&res, &io_base);
if (ret)
return ret;
ret = devm_request_pci_bus_resources(dev, &res);
if (ret)
return ret;
resource_list_for_each_entry(win, &res) {
switch (resource_type(win->res)) {
case IORESOURCE_IO:
io = win->res;
io->name = "Gemini PCI I/O";
if (!faraday_res_to_memcfg(io->start - win->offset,
resource_size(io), &val)) {
writel(val, p->base + PCI_IOSIZE);
} else {
dev_err(dev, "illegal IO mem size\n");
return -EINVAL;
}
ret = pci_remap_iospace(io, io_base);
if (ret) {
dev_warn(dev, "error %d: failed to map resource %pR\n",
ret, io);
continue;
}
break;
case IORESOURCE_MEM:
mem = win->res;
mem->name = "Gemini PCI MEM";
break;
case IORESOURCE_BUS:
break;
default:
break;
}
}
val = readl(p->base + PCI_CTRL);
val |= PCI_COMMAND_IO;
val |= PCI_COMMAND_MEMORY;
val |= PCI_COMMAND_MASTER;
writel(val, p->base + PCI_CTRL);
faraday_raw_pci_write_config(p, 0, 0, FARADAY_PCI_CTRL2 + 2, 2, 0xF000);
if (variant->cascaded_irq) {
ret = faraday_pci_setup_cascaded_irq(p);
if (ret) {
dev_err(dev, "failed to setup cascaded IRQ\n");
return ret;
}
}
if (!IS_ERR(p->bus_clk)) {
unsigned long rate;
u32 val;
faraday_raw_pci_read_config(p, 0, 0,
FARADAY_PCI_STATUS_CMD, 4, &val);
rate = clk_get_rate(p->bus_clk);
if ((rate == 33000000) && (val & PCI_STATUS_66MHZ_CAPABLE)) {
dev_info(dev, "33MHz bus is 66MHz capable\n");
max_bus_speed = PCI_SPEED_66MHz;
ret = clk_set_rate(p->bus_clk, 66000000);
if (ret)
dev_err(dev, "failed to set bus clock\n");
} else {
dev_info(dev, "33MHz only bus\n");
max_bus_speed = PCI_SPEED_33MHz;
}
rate = clk_get_rate(p->bus_clk);
if (rate == 33000000)
cur_bus_speed = PCI_SPEED_33MHz;
if (rate == 66000000)
cur_bus_speed = PCI_SPEED_66MHz;
}
ret = faraday_pci_parse_map_dma_ranges(p, dev->of_node);
if (ret)
return ret;
list_splice_init(&res, &host->windows);
ret = pci_scan_root_bus_bridge(host);
if (ret) {
dev_err(dev, "failed to scan host: %d\n", ret);
return ret;
}
p->bus = host->bus;
p->bus->max_bus_speed = max_bus_speed;
p->bus->cur_bus_speed = cur_bus_speed;
pci_bus_assign_resources(p->bus);
pci_bus_add_devices(p->bus);
pci_free_resource_list(&res);
return 0;
}
