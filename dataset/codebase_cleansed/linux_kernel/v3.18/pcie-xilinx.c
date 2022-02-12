static inline struct xilinx_pcie_port *sys_to_pcie(struct pci_sys_data *sys)
{
return sys->private_data;
}
static inline u32 pcie_read(struct xilinx_pcie_port *port, u32 reg)
{
return readl(port->reg_base + reg);
}
static inline void pcie_write(struct xilinx_pcie_port *port, u32 val, u32 reg)
{
writel(val, port->reg_base + reg);
}
static inline bool xilinx_pcie_link_is_up(struct xilinx_pcie_port *port)
{
return (pcie_read(port, XILINX_PCIE_REG_PSCR) &
XILINX_PCIE_REG_PSCR_LNKUP) ? 1 : 0;
}
static void xilinx_pcie_clear_err_interrupts(struct xilinx_pcie_port *port)
{
u32 val = pcie_read(port, XILINX_PCIE_REG_RPEFR);
if (val & XILINX_PCIE_RPEFR_ERR_VALID) {
dev_dbg(port->dev, "Requester ID %d\n",
val & XILINX_PCIE_RPEFR_REQ_ID);
pcie_write(port, XILINX_PCIE_RPEFR_ALL_MASK,
XILINX_PCIE_REG_RPEFR);
}
}
static bool xilinx_pcie_valid_device(struct pci_bus *bus, unsigned int devfn)
{
struct xilinx_pcie_port *port = sys_to_pcie(bus->sysdata);
if (bus->number != port->root_busno)
if (!xilinx_pcie_link_is_up(port))
return false;
if (bus->number == port->root_busno && devfn > 0)
return false;
if (bus->primary == port->root_busno && devfn > 0)
return false;
return true;
}
static void __iomem *xilinx_pcie_config_base(struct pci_bus *bus,
unsigned int devfn, int where)
{
struct xilinx_pcie_port *port = sys_to_pcie(bus->sysdata);
int relbus;
relbus = (bus->number << ECAM_BUS_NUM_SHIFT) |
(devfn << ECAM_DEV_NUM_SHIFT);
return port->reg_base + relbus + where;
}
static int xilinx_pcie_read_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
void __iomem *addr;
if (!xilinx_pcie_valid_device(bus, devfn)) {
*val = 0xFFFFFFFF;
return PCIBIOS_DEVICE_NOT_FOUND;
}
addr = xilinx_pcie_config_base(bus, devfn, where);
switch (size) {
case 1:
*val = readb(addr);
break;
case 2:
*val = readw(addr);
break;
default:
*val = readl(addr);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int xilinx_pcie_write_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
void __iomem *addr;
if (!xilinx_pcie_valid_device(bus, devfn))
return PCIBIOS_DEVICE_NOT_FOUND;
addr = xilinx_pcie_config_base(bus, devfn, where);
switch (size) {
case 1:
writeb(val, addr);
break;
case 2:
writew(val, addr);
break;
default:
writel(val, addr);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static void xilinx_pcie_destroy_msi(unsigned int irq)
{
struct irq_desc *desc;
struct msi_desc *msi;
struct xilinx_pcie_port *port;
desc = irq_to_desc(irq);
msi = irq_desc_get_msi_desc(desc);
port = sys_to_pcie(msi->dev->bus->sysdata);
if (!test_bit(irq, msi_irq_in_use))
dev_err(port->dev, "Trying to free unused MSI#%d\n", irq);
else
clear_bit(irq, msi_irq_in_use);
}
static int xilinx_pcie_assign_msi(struct xilinx_pcie_port *port)
{
int pos;
pos = find_first_zero_bit(msi_irq_in_use, XILINX_NUM_MSI_IRQS);
if (pos < XILINX_NUM_MSI_IRQS)
set_bit(pos, msi_irq_in_use);
else
return -ENOSPC;
return pos;
}
static void xilinx_msi_teardown_irq(struct msi_chip *chip, unsigned int irq)
{
xilinx_pcie_destroy_msi(irq);
}
static int xilinx_pcie_msi_setup_irq(struct msi_chip *chip,
struct pci_dev *pdev,
struct msi_desc *desc)
{
struct xilinx_pcie_port *port = sys_to_pcie(pdev->bus->sysdata);
unsigned int irq;
int hwirq;
struct msi_msg msg;
phys_addr_t msg_addr;
hwirq = xilinx_pcie_assign_msi(port);
if (hwirq < 0)
return hwirq;
irq = irq_create_mapping(port->irq_domain, hwirq);
if (!irq)
return -EINVAL;
irq_set_msi_desc(irq, desc);
msg_addr = virt_to_phys((void *)port->msi_pages);
msg.address_hi = 0;
msg.address_lo = msg_addr;
msg.data = irq;
write_msi_msg(irq, &msg);
return 0;
}
static int xilinx_pcie_msi_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &xilinx_msi_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
set_irq_flags(irq, IRQF_VALID);
return 0;
}
static void xilinx_pcie_enable_msi(struct xilinx_pcie_port *port)
{
phys_addr_t msg_addr;
port->msi_pages = __get_free_pages(GFP_KERNEL, 0);
msg_addr = virt_to_phys((void *)port->msi_pages);
pcie_write(port, 0x0, XILINX_PCIE_REG_MSIBASE1);
pcie_write(port, msg_addr, XILINX_PCIE_REG_MSIBASE2);
}
static void xilinx_pcie_add_bus(struct pci_bus *bus)
{
if (IS_ENABLED(CONFIG_PCI_MSI)) {
struct xilinx_pcie_port *port = sys_to_pcie(bus->sysdata);
xilinx_pcie_msi_chip.dev = port->dev;
bus->msi = &xilinx_pcie_msi_chip;
}
}
static int xilinx_pcie_intx_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &dummy_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
set_irq_flags(irq, IRQF_VALID);
return 0;
}
static irqreturn_t xilinx_pcie_intr_handler(int irq, void *data)
{
struct xilinx_pcie_port *port = (struct xilinx_pcie_port *)data;
u32 val, mask, status, msi_data;
val = pcie_read(port, XILINX_PCIE_REG_IDR);
mask = pcie_read(port, XILINX_PCIE_REG_IMR);
status = val & mask;
if (!status)
return IRQ_NONE;
if (status & XILINX_PCIE_INTR_LINK_DOWN)
dev_warn(port->dev, "Link Down\n");
if (status & XILINX_PCIE_INTR_ECRC_ERR)
dev_warn(port->dev, "ECRC failed\n");
if (status & XILINX_PCIE_INTR_STR_ERR)
dev_warn(port->dev, "Streaming error\n");
if (status & XILINX_PCIE_INTR_HOT_RESET)
dev_info(port->dev, "Hot reset\n");
if (status & XILINX_PCIE_INTR_CFG_TIMEOUT)
dev_warn(port->dev, "ECAM access timeout\n");
if (status & XILINX_PCIE_INTR_CORRECTABLE) {
dev_warn(port->dev, "Correctable error message\n");
xilinx_pcie_clear_err_interrupts(port);
}
if (status & XILINX_PCIE_INTR_NONFATAL) {
dev_warn(port->dev, "Non fatal error message\n");
xilinx_pcie_clear_err_interrupts(port);
}
if (status & XILINX_PCIE_INTR_FATAL) {
dev_warn(port->dev, "Fatal error message\n");
xilinx_pcie_clear_err_interrupts(port);
}
if (status & XILINX_PCIE_INTR_INTX) {
val = pcie_read(port, XILINX_PCIE_REG_RPIFR1);
if (!(val & XILINX_PCIE_RPIFR1_INTR_VALID)) {
dev_warn(port->dev, "RP Intr FIFO1 read error\n");
return IRQ_HANDLED;
}
pcie_write(port, XILINX_PCIE_RPIFR1_ALL_MASK,
XILINX_PCIE_REG_RPIFR1);
val = ((val & XILINX_PCIE_RPIFR1_INTR_MASK) >>
XILINX_PCIE_RPIFR1_INTR_SHIFT) + 1;
generic_handle_irq(irq_find_mapping(port->irq_domain, val));
}
if (status & XILINX_PCIE_INTR_MSI) {
val = pcie_read(port, XILINX_PCIE_REG_RPIFR1);
if (!(val & XILINX_PCIE_RPIFR1_INTR_VALID)) {
dev_warn(port->dev, "RP Intr FIFO1 read error\n");
return IRQ_HANDLED;
}
if (val & XILINX_PCIE_RPIFR1_MSI_INTR) {
msi_data = pcie_read(port, XILINX_PCIE_REG_RPIFR2) &
XILINX_PCIE_RPIFR2_MSG_DATA;
pcie_write(port, XILINX_PCIE_RPIFR1_ALL_MASK,
XILINX_PCIE_REG_RPIFR1);
if (IS_ENABLED(CONFIG_PCI_MSI)) {
generic_handle_irq(msi_data);
}
}
}
if (status & XILINX_PCIE_INTR_SLV_UNSUPP)
dev_warn(port->dev, "Slave unsupported request\n");
if (status & XILINX_PCIE_INTR_SLV_UNEXP)
dev_warn(port->dev, "Slave unexpected completion\n");
if (status & XILINX_PCIE_INTR_SLV_COMPL)
dev_warn(port->dev, "Slave completion timeout\n");
if (status & XILINX_PCIE_INTR_SLV_ERRP)
dev_warn(port->dev, "Slave Error Poison\n");
if (status & XILINX_PCIE_INTR_SLV_CMPABT)
dev_warn(port->dev, "Slave Completer Abort\n");
if (status & XILINX_PCIE_INTR_SLV_ILLBUR)
dev_warn(port->dev, "Slave Illegal Burst\n");
if (status & XILINX_PCIE_INTR_MST_DECERR)
dev_warn(port->dev, "Master decode error\n");
if (status & XILINX_PCIE_INTR_MST_SLVERR)
dev_warn(port->dev, "Master slave error\n");
if (status & XILINX_PCIE_INTR_MST_ERRP)
dev_warn(port->dev, "Master error poison\n");
pcie_write(port, status, XILINX_PCIE_REG_IDR);
return IRQ_HANDLED;
}
static void xilinx_pcie_free_irq_domain(struct xilinx_pcie_port *port)
{
int i;
u32 irq, num_irqs;
if (IS_ENABLED(CONFIG_PCI_MSI)) {
free_pages(port->msi_pages, 0);
num_irqs = XILINX_NUM_MSI_IRQS;
} else {
num_irqs = 4;
}
for (i = 0; i < num_irqs; i++) {
irq = irq_find_mapping(port->irq_domain, i);
if (irq > 0)
irq_dispose_mapping(irq);
}
irq_domain_remove(port->irq_domain);
}
static int xilinx_pcie_init_irq_domain(struct xilinx_pcie_port *port)
{
struct device *dev = port->dev;
struct device_node *node = dev->of_node;
struct device_node *pcie_intc_node;
pcie_intc_node = of_get_next_child(node, NULL);
if (!pcie_intc_node) {
dev_err(dev, "No PCIe Intc node found\n");
return PTR_ERR(pcie_intc_node);
}
port->irq_domain = irq_domain_add_linear(pcie_intc_node, 4,
&intx_domain_ops,
port);
if (!port->irq_domain) {
dev_err(dev, "Failed to get a INTx IRQ domain\n");
return PTR_ERR(port->irq_domain);
}
if (IS_ENABLED(CONFIG_PCI_MSI)) {
port->irq_domain = irq_domain_add_linear(node,
XILINX_NUM_MSI_IRQS,
&msi_domain_ops,
&xilinx_pcie_msi_chip);
if (!port->irq_domain) {
dev_err(dev, "Failed to get a MSI IRQ domain\n");
return PTR_ERR(port->irq_domain);
}
xilinx_pcie_enable_msi(port);
}
return 0;
}
static void xilinx_pcie_init_port(struct xilinx_pcie_port *port)
{
if (xilinx_pcie_link_is_up(port))
dev_info(port->dev, "PCIe Link is UP\n");
else
dev_info(port->dev, "PCIe Link is DOWN\n");
pcie_write(port, ~XILINX_PCIE_IDR_ALL_MASK,
XILINX_PCIE_REG_IMR);
pcie_write(port, pcie_read(port, XILINX_PCIE_REG_IDR) &
XILINX_PCIE_IMR_ALL_MASK,
XILINX_PCIE_REG_IDR);
pcie_write(port, XILINX_PCIE_IMR_ALL_MASK, XILINX_PCIE_REG_IMR);
pcie_write(port, pcie_read(port, XILINX_PCIE_REG_RPSC) |
XILINX_PCIE_REG_RPSC_BEN,
XILINX_PCIE_REG_RPSC);
}
static int xilinx_pcie_setup(int nr, struct pci_sys_data *sys)
{
struct xilinx_pcie_port *port = sys_to_pcie(sys);
list_splice_init(&port->resources, &sys->resources);
return 1;
}
static struct pci_bus *xilinx_pcie_scan_bus(int nr, struct pci_sys_data *sys)
{
struct xilinx_pcie_port *port = sys_to_pcie(sys);
struct pci_bus *bus;
port->root_busno = sys->busnr;
bus = pci_scan_root_bus(port->dev, sys->busnr, &xilinx_pcie_ops,
sys, &sys->resources);
return bus;
}
static int xilinx_pcie_parse_and_add_res(struct xilinx_pcie_port *port)
{
struct device *dev = port->dev;
struct device_node *node = dev->of_node;
struct resource *mem;
resource_size_t offset;
struct of_pci_range_parser parser;
struct of_pci_range range;
struct pci_host_bridge_window *win;
int err = 0, mem_resno = 0;
if (of_pci_range_parser_init(&parser, node)) {
dev_err(dev, "missing \"ranges\" property\n");
return -EINVAL;
}
for_each_of_pci_range(&parser, &range) {
if (mem_resno >= XILINX_MAX_NUM_RESOURCES) {
dev_err(dev, "Maximum memory resources exceeded\n");
return -EINVAL;
}
mem = devm_kmalloc(dev, sizeof(*mem), GFP_KERNEL);
if (!mem) {
err = -ENOMEM;
goto free_resources;
}
of_pci_range_to_resource(&range, node, mem);
switch (mem->flags & IORESOURCE_TYPE_BITS) {
case IORESOURCE_MEM:
offset = range.cpu_addr - range.pci_addr;
mem_resno++;
break;
default:
err = -EINVAL;
break;
}
if (err < 0) {
dev_warn(dev, "Invalid resource found %pR\n", mem);
continue;
}
err = request_resource(&iomem_resource, mem);
if (err)
goto free_resources;
pci_add_resource_offset(&port->resources, mem, offset);
}
if (of_pci_parse_bus_range(node, &port->bus_range)) {
u32 val = pcie_read(port, XILINX_PCIE_REG_BIR);
u8 last;
last = (val & XILINX_PCIE_BIR_ECAM_SZ_MASK) >>
XILINX_PCIE_BIR_ECAM_SZ_SHIFT;
port->bus_range = (struct resource) {
.name = node->name,
.start = 0,
.end = last,
.flags = IORESOURCE_BUS,
};
}
pci_add_resource(&port->resources, &port->bus_range);
return 0;
free_resources:
release_child_resources(&iomem_resource);
list_for_each_entry(win, &port->resources, list)
devm_kfree(dev, win->res);
pci_free_resource_list(&port->resources);
return err;
}
static int xilinx_pcie_parse_dt(struct xilinx_pcie_port *port)
{
struct device *dev = port->dev;
struct device_node *node = dev->of_node;
struct resource regs;
const char *type;
int err;
type = of_get_property(node, "device_type", NULL);
if (!type || strcmp(type, "pci")) {
dev_err(dev, "invalid \"device_type\" %s\n", type);
return -EINVAL;
}
err = of_address_to_resource(node, 0, &regs);
if (err) {
dev_err(dev, "missing \"reg\" property\n");
return err;
}
port->reg_base = devm_ioremap_resource(dev, &regs);
if (IS_ERR(port->reg_base))
return PTR_ERR(port->reg_base);
port->irq = irq_of_parse_and_map(node, 0);
err = devm_request_irq(dev, port->irq, xilinx_pcie_intr_handler,
IRQF_SHARED, "xilinx-pcie", port);
if (err) {
dev_err(dev, "unable to request irq %d\n", port->irq);
return err;
}
return 0;
}
static int xilinx_pcie_probe(struct platform_device *pdev)
{
struct xilinx_pcie_port *port;
struct hw_pci hw;
struct device *dev = &pdev->dev;
int err;
if (!dev->of_node)
return -ENODEV;
port = devm_kzalloc(dev, sizeof(*port), GFP_KERNEL);
if (!port)
return -ENOMEM;
port->dev = dev;
err = xilinx_pcie_parse_dt(port);
if (err) {
dev_err(dev, "Parsing DT failed\n");
return err;
}
xilinx_pcie_init_port(port);
err = xilinx_pcie_init_irq_domain(port);
if (err) {
dev_err(dev, "Failed creating IRQ Domain\n");
return err;
}
INIT_LIST_HEAD(&port->resources);
err = xilinx_pcie_parse_and_add_res(port);
if (err) {
dev_err(dev, "Failed adding resources\n");
return err;
}
platform_set_drvdata(pdev, port);
memset(&hw, 0, sizeof(hw));
hw = (struct hw_pci) {
.nr_controllers = 1,
.private_data = (void **)&port,
.setup = xilinx_pcie_setup,
.map_irq = of_irq_parse_and_map_pci,
.add_bus = xilinx_pcie_add_bus,
.scan = xilinx_pcie_scan_bus,
.ops = &xilinx_pcie_ops,
};
pci_common_init_dev(dev, &hw);
return 0;
}
static int xilinx_pcie_remove(struct platform_device *pdev)
{
struct xilinx_pcie_port *port = platform_get_drvdata(pdev);
xilinx_pcie_free_irq_domain(port);
return 0;
}
