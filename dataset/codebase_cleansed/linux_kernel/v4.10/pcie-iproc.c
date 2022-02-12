static inline struct iproc_pcie *iproc_data(struct pci_bus *bus)
{
struct iproc_pcie *pcie;
#ifdef CONFIG_ARM
struct pci_sys_data *sys = bus->sysdata;
pcie = sys->private_data;
#else
pcie = bus->sysdata;
#endif
return pcie;
}
static inline bool iproc_pcie_reg_is_invalid(u16 reg_offset)
{
return !!(reg_offset == IPROC_PCIE_REG_INVALID);
}
static inline u16 iproc_pcie_reg_offset(struct iproc_pcie *pcie,
enum iproc_pcie_reg reg)
{
return pcie->reg_offsets[reg];
}
static inline u32 iproc_pcie_read_reg(struct iproc_pcie *pcie,
enum iproc_pcie_reg reg)
{
u16 offset = iproc_pcie_reg_offset(pcie, reg);
if (iproc_pcie_reg_is_invalid(offset))
return 0;
return readl(pcie->base + offset);
}
static inline void iproc_pcie_write_reg(struct iproc_pcie *pcie,
enum iproc_pcie_reg reg, u32 val)
{
u16 offset = iproc_pcie_reg_offset(pcie, reg);
if (iproc_pcie_reg_is_invalid(offset))
return;
writel(val, pcie->base + offset);
}
static inline void iproc_pcie_apb_err_disable(struct pci_bus *bus,
bool disable)
{
struct iproc_pcie *pcie = iproc_data(bus);
u32 val;
if (bus->number && pcie->has_apb_err_disable) {
val = iproc_pcie_read_reg(pcie, IPROC_PCIE_APB_ERR_EN);
if (disable)
val &= ~APB_ERR_EN;
else
val |= APB_ERR_EN;
iproc_pcie_write_reg(pcie, IPROC_PCIE_APB_ERR_EN, val);
}
}
static void __iomem *iproc_pcie_map_cfg_bus(struct pci_bus *bus,
unsigned int devfn,
int where)
{
struct iproc_pcie *pcie = iproc_data(bus);
unsigned slot = PCI_SLOT(devfn);
unsigned fn = PCI_FUNC(devfn);
unsigned busno = bus->number;
u32 val;
u16 offset;
if (busno == 0) {
if (slot > 0 || fn > 0)
return NULL;
iproc_pcie_write_reg(pcie, IPROC_PCIE_CFG_IND_ADDR,
where & CFG_IND_ADDR_MASK);
offset = iproc_pcie_reg_offset(pcie, IPROC_PCIE_CFG_IND_DATA);
if (iproc_pcie_reg_is_invalid(offset))
return NULL;
else
return (pcie->base + offset);
}
if (pcie->ep_is_internal)
if (slot > 0)
return NULL;
val = (busno << CFG_ADDR_BUS_NUM_SHIFT) |
(slot << CFG_ADDR_DEV_NUM_SHIFT) |
(fn << CFG_ADDR_FUNC_NUM_SHIFT) |
(where & CFG_ADDR_REG_NUM_MASK) |
(1 & CFG_ADDR_CFG_TYPE_MASK);
iproc_pcie_write_reg(pcie, IPROC_PCIE_CFG_ADDR, val);
offset = iproc_pcie_reg_offset(pcie, IPROC_PCIE_CFG_DATA);
if (iproc_pcie_reg_is_invalid(offset))
return NULL;
else
return (pcie->base + offset);
}
static int iproc_pcie_config_read32(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
int ret;
iproc_pcie_apb_err_disable(bus, true);
ret = pci_generic_config_read32(bus, devfn, where, size, val);
iproc_pcie_apb_err_disable(bus, false);
return ret;
}
static int iproc_pcie_config_write32(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
int ret;
iproc_pcie_apb_err_disable(bus, true);
ret = pci_generic_config_write32(bus, devfn, where, size, val);
iproc_pcie_apb_err_disable(bus, false);
return ret;
}
static void iproc_pcie_reset(struct iproc_pcie *pcie)
{
u32 val;
if (pcie->ep_is_internal)
return;
val = iproc_pcie_read_reg(pcie, IPROC_PCIE_CLK_CTRL);
val &= ~EP_PERST_SOURCE_SELECT & ~EP_MODE_SURVIVE_PERST &
~RC_PCIE_RST_OUTPUT;
iproc_pcie_write_reg(pcie, IPROC_PCIE_CLK_CTRL, val);
udelay(250);
val |= RC_PCIE_RST_OUTPUT;
iproc_pcie_write_reg(pcie, IPROC_PCIE_CLK_CTRL, val);
msleep(100);
}
static int iproc_pcie_check_link(struct iproc_pcie *pcie, struct pci_bus *bus)
{
struct device *dev = pcie->dev;
u8 hdr_type;
u32 link_ctrl, class, val;
u16 pos = PCI_EXP_CAP, link_status;
bool link_is_active = false;
if (pcie->ep_is_internal)
return 0;
val = iproc_pcie_read_reg(pcie, IPROC_PCIE_LINK_STATUS);
if (!(val & PCIE_PHYLINKUP) || !(val & PCIE_DL_ACTIVE)) {
dev_err(dev, "PHY or data link is INACTIVE!\n");
return -ENODEV;
}
pci_bus_read_config_byte(bus, 0, PCI_HEADER_TYPE, &hdr_type);
if ((hdr_type & 0x7f) != PCI_HEADER_TYPE_BRIDGE) {
dev_err(dev, "in EP mode, hdr=%#02x\n", hdr_type);
return -EFAULT;
}
#define PCI_BRIDGE_CTRL_REG_OFFSET 0x43c
#define PCI_CLASS_BRIDGE_MASK 0xffff00
#define PCI_CLASS_BRIDGE_SHIFT 8
pci_bus_read_config_dword(bus, 0, PCI_BRIDGE_CTRL_REG_OFFSET, &class);
class &= ~PCI_CLASS_BRIDGE_MASK;
class |= (PCI_CLASS_BRIDGE_PCI << PCI_CLASS_BRIDGE_SHIFT);
pci_bus_write_config_dword(bus, 0, PCI_BRIDGE_CTRL_REG_OFFSET, class);
pci_bus_read_config_word(bus, 0, pos + PCI_EXP_LNKSTA, &link_status);
if (link_status & PCI_EXP_LNKSTA_NLW)
link_is_active = true;
if (!link_is_active) {
#define PCI_TARGET_LINK_SPEED_MASK 0xf
#define PCI_TARGET_LINK_SPEED_GEN2 0x2
#define PCI_TARGET_LINK_SPEED_GEN1 0x1
pci_bus_read_config_dword(bus, 0,
pos + PCI_EXP_LNKCTL2,
&link_ctrl);
if ((link_ctrl & PCI_TARGET_LINK_SPEED_MASK) ==
PCI_TARGET_LINK_SPEED_GEN2) {
link_ctrl &= ~PCI_TARGET_LINK_SPEED_MASK;
link_ctrl |= PCI_TARGET_LINK_SPEED_GEN1;
pci_bus_write_config_dword(bus, 0,
pos + PCI_EXP_LNKCTL2,
link_ctrl);
msleep(100);
pci_bus_read_config_word(bus, 0, pos + PCI_EXP_LNKSTA,
&link_status);
if (link_status & PCI_EXP_LNKSTA_NLW)
link_is_active = true;
}
}
dev_info(dev, "link: %s\n", link_is_active ? "UP" : "DOWN");
return link_is_active ? 0 : -ENODEV;
}
static void iproc_pcie_enable(struct iproc_pcie *pcie)
{
iproc_pcie_write_reg(pcie, IPROC_PCIE_INTX_EN, SYS_RC_INTX_MASK);
}
static inline bool iproc_pcie_ob_is_valid(struct iproc_pcie *pcie,
int window_idx)
{
u32 val;
val = iproc_pcie_read_reg(pcie, MAP_REG(IPROC_PCIE_OARR0, window_idx));
return !!(val & OARR_VALID);
}
static inline int iproc_pcie_ob_write(struct iproc_pcie *pcie, int window_idx,
int size_idx, u64 axi_addr, u64 pci_addr)
{
struct device *dev = pcie->dev;
u16 oarr_offset, omap_offset;
oarr_offset = iproc_pcie_reg_offset(pcie, MAP_REG(IPROC_PCIE_OARR0,
window_idx));
omap_offset = iproc_pcie_reg_offset(pcie, MAP_REG(IPROC_PCIE_OMAP0,
window_idx));
if (iproc_pcie_reg_is_invalid(oarr_offset) ||
iproc_pcie_reg_is_invalid(omap_offset))
return -EINVAL;
writel(lower_32_bits(axi_addr) | (size_idx << OARR_SIZE_CFG_SHIFT) |
OARR_VALID, pcie->base + oarr_offset);
writel(upper_32_bits(axi_addr), pcie->base + oarr_offset + 4);
writel(lower_32_bits(pci_addr), pcie->base + omap_offset);
writel(upper_32_bits(pci_addr), pcie->base + omap_offset + 4);
dev_info(dev, "ob window [%d]: offset 0x%x axi %pap pci %pap\n",
window_idx, oarr_offset, &axi_addr, &pci_addr);
dev_info(dev, "oarr lo 0x%x oarr hi 0x%x\n",
readl(pcie->base + oarr_offset),
readl(pcie->base + oarr_offset + 4));
dev_info(dev, "omap lo 0x%x omap hi 0x%x\n",
readl(pcie->base + omap_offset),
readl(pcie->base + omap_offset + 4));
return 0;
}
static int iproc_pcie_setup_ob(struct iproc_pcie *pcie, u64 axi_addr,
u64 pci_addr, resource_size_t size)
{
struct iproc_pcie_ob *ob = &pcie->ob;
struct device *dev = pcie->dev;
int ret = -EINVAL, window_idx, size_idx;
if (axi_addr < ob->axi_offset) {
dev_err(dev, "axi address %pap less than offset %pap\n",
&axi_addr, &ob->axi_offset);
return -EINVAL;
}
axi_addr -= ob->axi_offset;
for (window_idx = ob->nr_windows - 1; window_idx >= 0; window_idx--) {
const struct iproc_pcie_ob_map *ob_map =
&pcie->ob_map[window_idx];
if (iproc_pcie_ob_is_valid(pcie, window_idx))
continue;
for (size_idx = ob_map->nr_sizes - 1; size_idx >= 0;
size_idx--) {
resource_size_t window_size =
ob_map->window_sizes[size_idx] * SZ_1M;
if (size < window_size)
continue;
if (!IS_ALIGNED(axi_addr, window_size) ||
!IS_ALIGNED(pci_addr, window_size)) {
dev_err(dev,
"axi %pap or pci %pap not aligned\n",
&axi_addr, &pci_addr);
return -EINVAL;
}
ret = iproc_pcie_ob_write(pcie, window_idx, size_idx,
axi_addr, pci_addr);
if (ret)
goto err_ob;
size -= window_size;
if (size == 0)
return 0;
axi_addr += window_size;
pci_addr += window_size;
break;
}
}
err_ob:
dev_err(dev, "unable to configure outbound mapping\n");
dev_err(dev,
"axi %pap, axi offset %pap, pci %pap, res size %pap\n",
&axi_addr, &ob->axi_offset, &pci_addr, &size);
return ret;
}
static int iproc_pcie_map_ranges(struct iproc_pcie *pcie,
struct list_head *resources)
{
struct device *dev = pcie->dev;
struct resource_entry *window;
int ret;
resource_list_for_each_entry(window, resources) {
struct resource *res = window->res;
u64 res_type = resource_type(res);
switch (res_type) {
case IORESOURCE_IO:
case IORESOURCE_BUS:
break;
case IORESOURCE_MEM:
ret = iproc_pcie_setup_ob(pcie, res->start,
res->start - window->offset,
resource_size(res));
if (ret)
return ret;
break;
default:
dev_err(dev, "invalid resource %pR\n", res);
return -EINVAL;
}
}
return 0;
}
static inline bool iproc_pcie_ib_is_in_use(struct iproc_pcie *pcie,
int region_idx)
{
const struct iproc_pcie_ib_map *ib_map = &pcie->ib_map[region_idx];
u32 val;
val = iproc_pcie_read_reg(pcie, MAP_REG(IPROC_PCIE_IARR0, region_idx));
return !!(val & (BIT(ib_map->nr_sizes) - 1));
}
static inline bool iproc_pcie_ib_check_type(const struct iproc_pcie_ib_map *ib_map,
enum iproc_pcie_ib_map_type type)
{
return !!(ib_map->type == type);
}
static int iproc_pcie_ib_write(struct iproc_pcie *pcie, int region_idx,
int size_idx, int nr_windows, u64 axi_addr,
u64 pci_addr, resource_size_t size)
{
struct device *dev = pcie->dev;
const struct iproc_pcie_ib_map *ib_map = &pcie->ib_map[region_idx];
u16 iarr_offset, imap_offset;
u32 val;
int window_idx;
iarr_offset = iproc_pcie_reg_offset(pcie,
MAP_REG(IPROC_PCIE_IARR0, region_idx));
imap_offset = iproc_pcie_reg_offset(pcie,
MAP_REG(IPROC_PCIE_IMAP0, region_idx));
if (iproc_pcie_reg_is_invalid(iarr_offset) ||
iproc_pcie_reg_is_invalid(imap_offset))
return -EINVAL;
dev_info(dev, "ib region [%d]: offset 0x%x axi %pap pci %pap\n",
region_idx, iarr_offset, &axi_addr, &pci_addr);
writel(lower_32_bits(pci_addr) | BIT(size_idx),
pcie->base + iarr_offset);
writel(upper_32_bits(pci_addr), pcie->base + iarr_offset + 4);
dev_info(dev, "iarr lo 0x%x iarr hi 0x%x\n",
readl(pcie->base + iarr_offset),
readl(pcie->base + iarr_offset + 4));
size >>= ilog2(nr_windows);
for (window_idx = 0; window_idx < nr_windows; window_idx++) {
val = readl(pcie->base + imap_offset);
val |= lower_32_bits(axi_addr) | IMAP_VALID;
writel(val, pcie->base + imap_offset);
writel(upper_32_bits(axi_addr),
pcie->base + imap_offset + ib_map->imap_addr_offset);
dev_info(dev, "imap window [%d] lo 0x%x hi 0x%x\n",
window_idx, readl(pcie->base + imap_offset),
readl(pcie->base + imap_offset +
ib_map->imap_addr_offset));
imap_offset += ib_map->imap_window_offset;
axi_addr += size;
}
return 0;
}
static int iproc_pcie_setup_ib(struct iproc_pcie *pcie,
struct of_pci_range *range,
enum iproc_pcie_ib_map_type type)
{
struct device *dev = pcie->dev;
struct iproc_pcie_ib *ib = &pcie->ib;
int ret;
unsigned int region_idx, size_idx;
u64 axi_addr = range->cpu_addr, pci_addr = range->pci_addr;
resource_size_t size = range->size;
for (region_idx = 0; region_idx < ib->nr_regions; region_idx++) {
const struct iproc_pcie_ib_map *ib_map =
&pcie->ib_map[region_idx];
if (iproc_pcie_ib_is_in_use(pcie, region_idx) ||
!iproc_pcie_ib_check_type(ib_map, type))
continue;
for (size_idx = 0; size_idx < ib_map->nr_sizes; size_idx++) {
resource_size_t region_size =
ib_map->region_sizes[size_idx] * ib_map->size_unit;
if (size != region_size)
continue;
if (!IS_ALIGNED(axi_addr, region_size) ||
!IS_ALIGNED(pci_addr, region_size)) {
dev_err(dev,
"axi %pap or pci %pap not aligned\n",
&axi_addr, &pci_addr);
return -EINVAL;
}
ret = iproc_pcie_ib_write(pcie, region_idx, size_idx,
ib_map->nr_windows, axi_addr,
pci_addr, size);
if (ret)
goto err_ib;
else
return 0;
}
}
ret = -EINVAL;
err_ib:
dev_err(dev, "unable to configure inbound mapping\n");
dev_err(dev, "axi %pap, pci %pap, res size %pap\n",
&axi_addr, &pci_addr, &size);
return ret;
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
static int iproc_pcie_map_dma_ranges(struct iproc_pcie *pcie)
{
struct of_pci_range range;
struct of_pci_range_parser parser;
int ret;
ret = pci_dma_range_parser_init(&parser, pcie->dev->of_node);
if (ret)
return ret;
for_each_of_pci_range(&parser, &range) {
ret = iproc_pcie_setup_ib(pcie, &range, IPROC_PCIE_IB_MAP_MEM);
if (ret)
return ret;
}
return 0;
}
static int iproce_pcie_get_msi(struct iproc_pcie *pcie,
struct device_node *msi_node,
u64 *msi_addr)
{
struct device *dev = pcie->dev;
int ret;
struct resource res;
if (!of_device_is_compatible(msi_node, "arm,gic-v3-its")) {
dev_err(dev, "unable to find compatible MSI controller\n");
return -ENODEV;
}
ret = of_address_to_resource(msi_node, 0, &res);
if (ret < 0) {
dev_err(dev, "unable to obtain MSI controller resources\n");
return ret;
}
*msi_addr = res.start + GITS_TRANSLATER;
return 0;
}
static int iproc_pcie_paxb_v2_msi_steer(struct iproc_pcie *pcie, u64 msi_addr)
{
int ret;
struct of_pci_range range;
memset(&range, 0, sizeof(range));
range.size = SZ_32K;
range.pci_addr = range.cpu_addr = msi_addr & ~(range.size - 1);
ret = iproc_pcie_setup_ib(pcie, &range, IPROC_PCIE_IB_MAP_IO);
return ret;
}
static void iproc_pcie_paxc_v2_msi_steer(struct iproc_pcie *pcie, u64 msi_addr)
{
u32 val;
iproc_pcie_write_reg(pcie, IPROC_PCIE_MSI_BASE_ADDR,
(u32)(msi_addr >> 13));
iproc_pcie_write_reg(pcie, IPROC_PCIE_MSI_WINDOW_SIZE, 0);
val = iproc_pcie_read_reg(pcie, IPROC_PCIE_MSI_GIC_MODE);
val |= GIC_V3_CFG;
iproc_pcie_write_reg(pcie, IPROC_PCIE_MSI_GIC_MODE, val);
msi_addr >>= 2;
iproc_pcie_write_reg(pcie, IPROC_PCIE_MSI_ADDR_HI,
upper_32_bits(msi_addr));
iproc_pcie_write_reg(pcie, IPROC_PCIE_MSI_ADDR_LO,
lower_32_bits(msi_addr));
val = iproc_pcie_read_reg(pcie, IPROC_PCIE_MSI_EN_CFG);
val |= MSI_ENABLE_CFG;
iproc_pcie_write_reg(pcie, IPROC_PCIE_MSI_EN_CFG, val);
}
static int iproc_pcie_msi_steer(struct iproc_pcie *pcie,
struct device_node *msi_node)
{
struct device *dev = pcie->dev;
int ret;
u64 msi_addr;
ret = iproce_pcie_get_msi(pcie, msi_node, &msi_addr);
if (ret < 0) {
dev_err(dev, "msi steering failed\n");
return ret;
}
switch (pcie->type) {
case IPROC_PCIE_PAXB_V2:
ret = iproc_pcie_paxb_v2_msi_steer(pcie, msi_addr);
if (ret)
return ret;
break;
case IPROC_PCIE_PAXC_V2:
iproc_pcie_paxc_v2_msi_steer(pcie, msi_addr);
break;
default:
return -EINVAL;
}
return 0;
}
static int iproc_pcie_msi_enable(struct iproc_pcie *pcie)
{
struct device_node *msi_node;
int ret;
msi_node = of_parse_phandle(pcie->dev->of_node, "msi-parent", 0);
if (!msi_node) {
const __be32 *msi_map = NULL;
int len;
u32 phandle;
msi_map = of_get_property(pcie->dev->of_node, "msi-map", &len);
if (!msi_map)
return -ENODEV;
phandle = be32_to_cpup(msi_map + 1);
msi_node = of_find_node_by_phandle(phandle);
if (!msi_node)
return -ENODEV;
}
if (pcie->need_msi_steer) {
ret = iproc_pcie_msi_steer(pcie, msi_node);
if (ret)
return ret;
}
return iproc_msi_init(pcie, msi_node);
}
static void iproc_pcie_msi_disable(struct iproc_pcie *pcie)
{
iproc_msi_exit(pcie);
}
static int iproc_pcie_rev_init(struct iproc_pcie *pcie)
{
struct device *dev = pcie->dev;
unsigned int reg_idx;
const u16 *regs;
switch (pcie->type) {
case IPROC_PCIE_PAXB_BCMA:
regs = iproc_pcie_reg_paxb_bcma;
break;
case IPROC_PCIE_PAXB:
regs = iproc_pcie_reg_paxb;
pcie->has_apb_err_disable = true;
if (pcie->need_ob_cfg) {
pcie->ob_map = paxb_ob_map;
pcie->ob.nr_windows = ARRAY_SIZE(paxb_ob_map);
}
break;
case IPROC_PCIE_PAXB_V2:
regs = iproc_pcie_reg_paxb_v2;
pcie->has_apb_err_disable = true;
if (pcie->need_ob_cfg) {
pcie->ob_map = paxb_v2_ob_map;
pcie->ob.nr_windows = ARRAY_SIZE(paxb_v2_ob_map);
}
pcie->ib.nr_regions = ARRAY_SIZE(paxb_v2_ib_map);
pcie->ib_map = paxb_v2_ib_map;
pcie->need_msi_steer = true;
break;
case IPROC_PCIE_PAXC:
regs = iproc_pcie_reg_paxc;
pcie->ep_is_internal = true;
break;
case IPROC_PCIE_PAXC_V2:
regs = iproc_pcie_reg_paxc_v2;
pcie->ep_is_internal = true;
pcie->need_msi_steer = true;
break;
default:
dev_err(dev, "incompatible iProc PCIe interface\n");
return -EINVAL;
}
pcie->reg_offsets = devm_kcalloc(dev, IPROC_PCIE_MAX_NUM_REG,
sizeof(*pcie->reg_offsets),
GFP_KERNEL);
if (!pcie->reg_offsets)
return -ENOMEM;
pcie->reg_offsets[0] = (pcie->type == IPROC_PCIE_PAXC_V2) ?
IPROC_PCIE_REG_INVALID : regs[0];
for (reg_idx = 1; reg_idx < IPROC_PCIE_MAX_NUM_REG; reg_idx++)
pcie->reg_offsets[reg_idx] = regs[reg_idx] ?
regs[reg_idx] : IPROC_PCIE_REG_INVALID;
return 0;
}
int iproc_pcie_setup(struct iproc_pcie *pcie, struct list_head *res)
{
struct device *dev;
int ret;
void *sysdata;
struct pci_bus *bus;
dev = pcie->dev;
ret = iproc_pcie_rev_init(pcie);
if (ret) {
dev_err(dev, "unable to initialize controller parameters\n");
return ret;
}
ret = devm_request_pci_bus_resources(dev, res);
if (ret)
return ret;
ret = phy_init(pcie->phy);
if (ret) {
dev_err(dev, "unable to initialize PCIe PHY\n");
return ret;
}
ret = phy_power_on(pcie->phy);
if (ret) {
dev_err(dev, "unable to power on PCIe PHY\n");
goto err_exit_phy;
}
iproc_pcie_reset(pcie);
if (pcie->need_ob_cfg) {
ret = iproc_pcie_map_ranges(pcie, res);
if (ret) {
dev_err(dev, "map failed\n");
goto err_power_off_phy;
}
}
ret = iproc_pcie_map_dma_ranges(pcie);
if (ret && ret != -ENOENT)
goto err_power_off_phy;
#ifdef CONFIG_ARM
pcie->sysdata.private_data = pcie;
sysdata = &pcie->sysdata;
#else
sysdata = pcie;
#endif
bus = pci_create_root_bus(dev, 0, &iproc_pcie_ops, sysdata, res);
if (!bus) {
dev_err(dev, "unable to create PCI root bus\n");
ret = -ENOMEM;
goto err_power_off_phy;
}
pcie->root_bus = bus;
ret = iproc_pcie_check_link(pcie, bus);
if (ret) {
dev_err(dev, "no PCIe EP device detected\n");
goto err_rm_root_bus;
}
iproc_pcie_enable(pcie);
if (IS_ENABLED(CONFIG_PCI_MSI))
if (iproc_pcie_msi_enable(pcie))
dev_info(dev, "not using iProc MSI\n");
pci_scan_child_bus(bus);
pci_assign_unassigned_bus_resources(bus);
if (pcie->map_irq)
pci_fixup_irqs(pci_common_swizzle, pcie->map_irq);
pci_bus_add_devices(bus);
return 0;
err_rm_root_bus:
pci_stop_root_bus(bus);
pci_remove_root_bus(bus);
err_power_off_phy:
phy_power_off(pcie->phy);
err_exit_phy:
phy_exit(pcie->phy);
return ret;
}
int iproc_pcie_remove(struct iproc_pcie *pcie)
{
pci_stop_root_bus(pcie->root_bus);
pci_remove_root_bus(pcie->root_bus);
iproc_pcie_msi_disable(pcie);
phy_power_off(pcie->phy);
phy_exit(pcie->phy);
return 0;
}
