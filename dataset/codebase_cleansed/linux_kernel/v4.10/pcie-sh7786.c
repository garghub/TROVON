static void sh7786_pci_fixup(struct pci_dev *dev)
{
if (pci_is_root_bus(dev->bus) && dev->devfn == 0) {
int i;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
dev->resource[i].start = 0;
dev->resource[i].end = 0;
dev->resource[i].flags = 0;
}
}
}
static int __init phy_wait_for_ack(struct pci_channel *chan)
{
unsigned int timeout = 100;
while (timeout--) {
if (pci_read_reg(chan, SH4A_PCIEPHYADRR) & (1 << BITS_ACK))
return 0;
udelay(100);
}
return -ETIMEDOUT;
}
static int __init pci_wait_for_irq(struct pci_channel *chan, unsigned int mask)
{
unsigned int timeout = 100;
while (timeout--) {
if ((pci_read_reg(chan, SH4A_PCIEINTR) & mask) == mask)
return 0;
udelay(100);
}
return -ETIMEDOUT;
}
static void __init phy_write_reg(struct pci_channel *chan, unsigned int addr,
unsigned int lane, unsigned int data)
{
unsigned long phyaddr;
phyaddr = (1 << BITS_CMD) + ((lane & 0xf) << BITS_LANE) +
((addr & 0xff) << BITS_ADR);
pci_write_reg(chan, data, SH4A_PCIEPHYDOUTR);
pci_write_reg(chan, phyaddr, SH4A_PCIEPHYADRR);
phy_wait_for_ack(chan);
pci_write_reg(chan, 0, SH4A_PCIEPHYDOUTR);
pci_write_reg(chan, 0, SH4A_PCIEPHYADRR);
phy_wait_for_ack(chan);
}
static int __init pcie_clk_init(struct sh7786_pcie_port *port)
{
struct pci_channel *chan = port->hose;
struct clk *clk;
char fclk_name[16];
int ret;
ret = clk_register(&fixed_pciexclkp);
if (unlikely(ret != 0))
return ret;
snprintf(fclk_name, sizeof(fclk_name), "pcie%d_fck", port->index);
port->fclk = clk_get(NULL, fclk_name);
if (IS_ERR(port->fclk)) {
ret = PTR_ERR(port->fclk);
goto err_fclk;
}
clk_enable(port->fclk);
clk = &port->phy_clk;
memset(clk, 0, sizeof(struct clk));
clk->parent = &fixed_pciexclkp;
clk->enable_reg = (void __iomem *)(chan->reg_base + SH4A_PCIEPHYCTLR);
clk->enable_bit = BITS_CKE;
ret = sh_clk_mstp_register(clk, 1);
if (unlikely(ret < 0))
goto err_phy;
return 0;
err_phy:
clk_disable(port->fclk);
clk_put(port->fclk);
err_fclk:
clk_unregister(&fixed_pciexclkp);
return ret;
}
static int __init phy_init(struct sh7786_pcie_port *port)
{
struct pci_channel *chan = port->hose;
unsigned int timeout = 100;
clk_enable(&port->phy_clk);
phy_write_reg(chan, 0x60, 0xf, 0x004b008b);
phy_write_reg(chan, 0x61, 0xf, 0x00007b41);
phy_write_reg(chan, 0x64, 0xf, 0x00ff4f00);
phy_write_reg(chan, 0x65, 0xf, 0x09070907);
phy_write_reg(chan, 0x66, 0xf, 0x00000010);
phy_write_reg(chan, 0x74, 0xf, 0x0007001c);
phy_write_reg(chan, 0x79, 0xf, 0x01fc000d);
phy_write_reg(chan, 0xb0, 0xf, 0x00000610);
phy_write_reg(chan, 0x67, 0x1, 0x00000400);
clk_disable(&port->phy_clk);
while (timeout--) {
if (pci_read_reg(chan, SH4A_PCIEPHYSR))
return 0;
udelay(100);
}
return -ETIMEDOUT;
}
static void __init pcie_reset(struct sh7786_pcie_port *port)
{
struct pci_channel *chan = port->hose;
pci_write_reg(chan, 1, SH4A_PCIESRSTR);
pci_write_reg(chan, 0, SH4A_PCIETCTLR);
pci_write_reg(chan, 0, SH4A_PCIESRSTR);
pci_write_reg(chan, 0, SH4A_PCIETXVC0SR);
}
static int __init pcie_init(struct sh7786_pcie_port *port)
{
struct pci_channel *chan = port->hose;
unsigned int data;
phys_addr_t memphys;
size_t memsize;
int ret, i, win;
pcie_reset(port);
pci_write_reg(chan, PCI_CLASS_BRIDGE_PCI << 16, SH4A_PCIEIDSETR1);
data = pci_read_reg(chan, SH4A_PCIEEXPCAP0);
data &= ~(PCI_EXP_FLAGS_TYPE << 16);
if (port->endpoint)
data |= PCI_EXP_TYPE_ENDPOINT << 20;
else
data |= PCI_EXP_TYPE_ROOT_PORT << 20;
data |= PCI_CAP_ID_EXP;
pci_write_reg(chan, data, SH4A_PCIEEXPCAP0);
pci_write_reg(chan, PCI_EXP_LNKCAP_DLLLARC, SH4A_PCIEEXPCAP3);
data = pci_read_reg(chan, SH4A_PCIEEXPCAP4);
data &= ~PCI_EXP_LNKCTL_ASPMC;
data |= PCI_EXP_LNKCTL_ES | 1;
pci_write_reg(chan, data, SH4A_PCIEEXPCAP4);
data = pci_read_reg(chan, SH4A_PCIEEXPCAP5);
data &= ~PCI_EXP_SLTCAP_PSN;
data |= (port->index + 1) << 19;
pci_write_reg(chan, data, SH4A_PCIEEXPCAP5);
data = pci_read_reg(chan, SH4A_PCIETLCTLR);
data &= ~0x3f00;
data |= 0x32 << 8;
pci_write_reg(chan, data, SH4A_PCIETLCTLR);
data = pci_read_reg(chan, SH4A_PCIEMACCTLR);
data &= ~PCIEMACCTLR_SCR_DIS;
data |= (0xff << 16);
pci_write_reg(chan, data, SH4A_PCIEMACCTLR);
memphys = __pa(memory_start);
memsize = roundup_pow_of_two(memory_end - memory_start);
if (memsize > SZ_512M) {
pci_write_reg(chan, memphys + SZ_512M, SH4A_PCIELAR1);
pci_write_reg(chan, ((memsize - SZ_512M) - SZ_256) | 1,
SH4A_PCIELAMR1);
memsize = SZ_512M;
} else {
pci_write_reg(chan, 0, SH4A_PCIELAR1);
pci_write_reg(chan, 0, SH4A_PCIELAMR1);
}
pci_write_reg(chan, memphys, SH4A_PCIELAR0);
pci_write_reg(chan, (memsize - SZ_256) | 1, SH4A_PCIELAMR0);
data = pci_read_reg(chan, SH4A_PCIETCTLR);
data |= 0x1;
pci_write_reg(chan, data, SH4A_PCIETCTLR);
mdelay(100);
data = pci_read_reg(chan, SH4A_PCIEDLINTENR);
data |= PCIEDLINTENR_DLL_ACT_ENABLE;
pci_write_reg(chan, data, SH4A_PCIEDLINTENR);
data = pci_read_reg(chan, SH4A_PCIEMACCTLR);
data |= PCIEMACCTLR_SCR_DIS | (0xff << 16);
pci_write_reg(chan, data, SH4A_PCIEMACCTLR);
ret = pci_wait_for_irq(chan, MASK_INT_TX_CTRL);
data = pci_read_reg(chan, SH4A_PCIEPCICONF1);
data &= ~(PCI_STATUS_DEVSEL_MASK << 16);
data |= PCI_COMMAND_IO | PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER |
(PCI_STATUS_CAP_LIST | PCI_STATUS_DEVSEL_FAST) << 16;
pci_write_reg(chan, data, SH4A_PCIEPCICONF1);
pci_write_reg(chan, 0x80888000, SH4A_PCIETXVC0DCTLR);
pci_write_reg(chan, 0x00222000, SH4A_PCIERXVC0DCTLR);
wmb();
if (ret == 0) {
data = pci_read_reg(chan, SH4A_PCIEMACSR);
printk(KERN_NOTICE "PCI: PCIe#%d x%d link detected\n",
port->index, (data >> 20) & 0x3f);
} else
printk(KERN_NOTICE "PCI: PCIe#%d link down\n",
port->index);
for (i = win = 0; i < chan->nr_resources; i++) {
struct resource *res = chan->resources + i;
resource_size_t size;
u32 mask;
if ((res->flags & IORESOURCE_MEM_32BIT) && __in_29bit_mode())
continue;
pci_write_reg(chan, 0x00000000, SH4A_PCIEPTCTLR(win));
size = resource_size(res);
mask = (roundup_pow_of_two(size) / SZ_256K) - 1;
pci_write_reg(chan, mask << 18, SH4A_PCIEPAMR(win));
pci_write_reg(chan, upper_32_bits(res->start),
SH4A_PCIEPARH(win));
pci_write_reg(chan, lower_32_bits(res->start),
SH4A_PCIEPARL(win));
mask = MASK_PARE;
if (res->flags & IORESOURCE_IO)
mask |= MASK_SPC;
pci_write_reg(chan, mask, SH4A_PCIEPTCTLR(win));
win++;
}
return 0;
}
int __init pcibios_map_platform_irq(const struct pci_dev *pdev, u8 slot, u8 pin)
{
return evt2irq(0xae0);
}
static int __init sh7786_pcie_core_init(void)
{
return test_mode_pin(MODE_PIN12) ? 3 : 2;
}
static void __init sh7786_pcie_init_hw(void *data, async_cookie_t cookie)
{
struct sh7786_pcie_port *port = data;
int ret;
port->endpoint = test_mode_pin(MODE_PIN11);
ret = pcie_clk_init(port);
if (unlikely(ret < 0)) {
pr_err("clock initialization failed for port#%d\n",
port->index);
return;
}
ret = phy_init(port);
if (unlikely(ret < 0)) {
pr_err("phy initialization failed for port#%d\n",
port->index);
return;
}
ret = pcie_init(port);
if (unlikely(ret < 0)) {
pr_err("core initialization failed for port#%d\n",
port->index);
return;
}
async_synchronize_cookie(cookie);
register_pci_controller(port->hose);
}
static int __init sh7786_pcie_init(void)
{
struct clk *platclk;
int i;
printk(KERN_NOTICE "PCI: Starting initialization.\n");
sh7786_pcie_hwops = &sh7786_65nm_pcie_hwops;
nr_ports = sh7786_pcie_hwops->core_init();
BUG_ON(nr_ports > ARRAY_SIZE(sh7786_pci_channels));
if (unlikely(nr_ports == 0))
return -ENODEV;
sh7786_pcie_ports = kzalloc(nr_ports * sizeof(struct sh7786_pcie_port),
GFP_KERNEL);
if (unlikely(!sh7786_pcie_ports))
return -ENOMEM;
platclk = clk_get(NULL, "pcie_plat_clk");
if (IS_ERR(platclk)) {
platclk = NULL;
}
clk_enable(platclk);
printk(KERN_NOTICE "PCI: probing %d ports.\n", nr_ports);
for (i = 0; i < nr_ports; i++) {
struct sh7786_pcie_port *port = sh7786_pcie_ports + i;
port->index = i;
port->hose = sh7786_pci_channels + i;
port->hose->io_map_base = port->hose->resources[0].start;
async_schedule(sh7786_pcie_hwops->port_init_hw, port);
}
async_synchronize_full();
return 0;
}
