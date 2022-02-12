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
struct device *dev = port->dev;
unsigned long val = pcie_read(port, XILINX_PCIE_REG_RPEFR);
if (val & XILINX_PCIE_RPEFR_ERR_VALID) {
dev_dbg(dev, "Requester ID %lu\n",
val & XILINX_PCIE_RPEFR_REQ_ID);
pcie_write(port, XILINX_PCIE_RPEFR_ALL_MASK,
XILINX_PCIE_REG_RPEFR);
}
}
static bool xilinx_pcie_valid_device(struct pci_bus *bus, unsigned int devfn)
{
struct xilinx_pcie_port *port = bus->sysdata;
if (bus->number != port->root_busno)
if (!xilinx_pcie_link_is_up(port))
return false;
if (bus->number == port->root_busno && devfn > 0)
return false;
return true;
}
static void __iomem *xilinx_pcie_map_bus(struct pci_bus *bus,
unsigned int devfn, int where)
{
struct xilinx_pcie_port *port = bus->sysdata;
int relbus;
if (!xilinx_pcie_valid_device(bus, devfn))
return NULL;
relbus = (bus->number << ECAM_BUS_NUM_SHIFT) |
(devfn << ECAM_DEV_NUM_SHIFT);
return port->reg_base + relbus + where;
}
static void xilinx_pcie_destroy_msi(unsigned int irq)
{
struct msi_desc *msi;
struct xilinx_pcie_port *port;
struct irq_data *d = irq_get_irq_data(irq);
irq_hw_number_t hwirq = irqd_to_hwirq(d);
if (!test_bit(hwirq, msi_irq_in_use)) {
msi = irq_get_msi_desc(irq);
port = msi_desc_to_pci_sysdata(msi);
dev_err(port->dev, "Trying to free unused MSI#%d\n", irq);
} else {
clear_bit(hwirq, msi_irq_in_use);
}
}
static int xilinx_pcie_assign_msi(void)
{
int pos;
pos = find_first_zero_bit(msi_irq_in_use, XILINX_NUM_MSI_IRQS);
if (pos < XILINX_NUM_MSI_IRQS)
set_bit(pos, msi_irq_in_use);
else
return -ENOSPC;
return pos;
}
static void xilinx_msi_teardown_irq(struct msi_controller *chip,
unsigned int irq)
{
xilinx_pcie_destroy_msi(irq);
irq_dispose_mapping(irq);
}
static int xilinx_pcie_msi_setup_irq(struct msi_controller *chip,
struct pci_dev *pdev,
struct msi_desc *desc)
{
struct xilinx_pcie_port *port = pdev->bus->sysdata;
unsigned int irq;
int hwirq;
struct msi_msg msg;
phys_addr_t msg_addr;
hwirq = xilinx_pcie_assign_msi();
if (hwirq < 0)
return hwirq;
irq = irq_create_mapping(port->msi_domain, hwirq);
if (!irq)
return -EINVAL;
irq_set_msi_desc(irq, desc);
msg_addr = virt_to_phys((void *)port->msi_pages);
msg.address_hi = 0;
msg.address_lo = msg_addr;
msg.data = irq;
pci_write_msi_msg(irq, &msg);
return 0;
}
static int xilinx_pcie_msi_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &xilinx_msi_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
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
static int xilinx_pcie_intx_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hwirq)
{
irq_set_chip_and_handler(irq, &dummy_irq_chip, handle_simple_irq);
irq_set_chip_data(irq, domain->host_data);
return 0;
}
static irqreturn_t xilinx_pcie_intr_handler(int irq, void *data)
{
struct xilinx_pcie_port *port = (struct xilinx_pcie_port *)data;
struct device *dev = port->dev;
u32 val, mask, status, msi_data;
val = pcie_read(port, XILINX_PCIE_REG_IDR);
mask = pcie_read(port, XILINX_PCIE_REG_IMR);
status = val & mask;
if (!status)
return IRQ_NONE;
if (status & XILINX_PCIE_INTR_LINK_DOWN)
dev_warn(dev, "Link Down\n");
if (status & XILINX_PCIE_INTR_ECRC_ERR)
dev_warn(dev, "ECRC failed\n");
if (status & XILINX_PCIE_INTR_STR_ERR)
dev_warn(dev, "Streaming error\n");
if (status & XILINX_PCIE_INTR_HOT_RESET)
dev_info(dev, "Hot reset\n");
if (status & XILINX_PCIE_INTR_CFG_TIMEOUT)
dev_warn(dev, "ECAM access timeout\n");
if (status & XILINX_PCIE_INTR_CORRECTABLE) {
dev_warn(dev, "Correctable error message\n");
xilinx_pcie_clear_err_interrupts(port);
}
if (status & XILINX_PCIE_INTR_NONFATAL) {
dev_warn(dev, "Non fatal error message\n");
xilinx_pcie_clear_err_interrupts(port);
}
if (status & XILINX_PCIE_INTR_FATAL) {
dev_warn(dev, "Fatal error message\n");
xilinx_pcie_clear_err_interrupts(port);
}
if (status & XILINX_PCIE_INTR_INTX) {
val = pcie_read(port, XILINX_PCIE_REG_RPIFR1);
if (!(val & XILINX_PCIE_RPIFR1_INTR_VALID)) {
dev_warn(dev, "RP Intr FIFO1 read error\n");
goto error;
}
if (!(val & XILINX_PCIE_RPIFR1_MSI_INTR)) {
pcie_write(port, XILINX_PCIE_RPIFR1_ALL_MASK,
XILINX_PCIE_REG_RPIFR1);
val = ((val & XILINX_PCIE_RPIFR1_INTR_MASK) >>
XILINX_PCIE_RPIFR1_INTR_SHIFT) + 1;
generic_handle_irq(irq_find_mapping(port->leg_domain,
val));
}
}
if (status & XILINX_PCIE_INTR_MSI) {
val = pcie_read(port, XILINX_PCIE_REG_RPIFR1);
if (!(val & XILINX_PCIE_RPIFR1_INTR_VALID)) {
dev_warn(dev, "RP Intr FIFO1 read error\n");
goto error;
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
dev_warn(dev, "Slave unsupported request\n");
if (status & XILINX_PCIE_INTR_SLV_UNEXP)
dev_warn(dev, "Slave unexpected completion\n");
if (status & XILINX_PCIE_INTR_SLV_COMPL)
dev_warn(dev, "Slave completion timeout\n");
if (status & XILINX_PCIE_INTR_SLV_ERRP)
dev_warn(dev, "Slave Error Poison\n");
if (status & XILINX_PCIE_INTR_SLV_CMPABT)
dev_warn(dev, "Slave Completer Abort\n");
if (status & XILINX_PCIE_INTR_SLV_ILLBUR)
dev_warn(dev, "Slave Illegal Burst\n");
if (status & XILINX_PCIE_INTR_MST_DECERR)
dev_warn(dev, "Master decode error\n");
if (status & XILINX_PCIE_INTR_MST_SLVERR)
dev_warn(dev, "Master slave error\n");
if (status & XILINX_PCIE_INTR_MST_ERRP)
dev_warn(dev, "Master error poison\n");
error:
pcie_write(port, status, XILINX_PCIE_REG_IDR);
return IRQ_HANDLED;
}
static int xilinx_pcie_init_irq_domain(struct xilinx_pcie_port *port)
{
struct device *dev = port->dev;
struct device_node *node = dev->of_node;
struct device_node *pcie_intc_node;
pcie_intc_node = of_get_next_child(node, NULL);
if (!pcie_intc_node) {
dev_err(dev, "No PCIe Intc node found\n");
return -ENODEV;
}
port->leg_domain = irq_domain_add_linear(pcie_intc_node, 4,
&intx_domain_ops,
port);
if (!port->leg_domain) {
dev_err(dev, "Failed to get a INTx IRQ domain\n");
return -ENODEV;
}
if (IS_ENABLED(CONFIG_PCI_MSI)) {
port->msi_domain = irq_domain_add_linear(node,
XILINX_NUM_MSI_IRQS,
&msi_domain_ops,
&xilinx_pcie_msi_chip);
if (!port->msi_domain) {
dev_err(dev, "Failed to get a MSI IRQ domain\n");
return -ENODEV;
}
xilinx_pcie_enable_msi(port);
}
return 0;
}
static void xilinx_pcie_init_port(struct xilinx_pcie_port *port)
{
struct device *dev = port->dev;
if (xilinx_pcie_link_is_up(port))
dev_info(dev, "PCIe Link is UP\n");
else
dev_info(dev, "PCIe Link is DOWN\n");
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
IRQF_SHARED | IRQF_NO_THREAD,
"xilinx-pcie", port);
if (err) {
dev_err(dev, "unable to request irq %d\n", port->irq);
return err;
}
return 0;
}
static int xilinx_pcie_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct xilinx_pcie_port *port;
struct pci_bus *bus, *child;
int err;
resource_size_t iobase = 0;
LIST_HEAD(res);
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
err = of_pci_get_host_bridge_resources(dev->of_node, 0, 0xff, &res,
&iobase);
if (err) {
dev_err(dev, "Getting bridge resources failed\n");
return err;
}
err = devm_request_pci_bus_resources(dev, &res);
if (err)
goto error;
bus = pci_create_root_bus(dev, 0, &xilinx_pcie_ops, port, &res);
if (!bus) {
err = -ENOMEM;
goto error;
}
#ifdef CONFIG_PCI_MSI
xilinx_pcie_msi_chip.dev = dev;
bus->msi = &xilinx_pcie_msi_chip;
#endif
pci_scan_child_bus(bus);
pci_assign_unassigned_bus_resources(bus);
#ifndef CONFIG_MICROBLAZE
pci_fixup_irqs(pci_common_swizzle, of_irq_parse_and_map_pci);
#endif
list_for_each_entry(child, &bus->children, node)
pcie_bus_configure_settings(child);
pci_bus_add_devices(bus);
return 0;
error:
pci_free_resource_list(&res);
return err;
}
