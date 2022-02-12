static inline int sgpio_bit_shift(struct ecx_plat_data *pdata, u32 port,
u32 shift)
{
return 1 << (3 * pdata->port_to_sgpio[port] + shift);
}
static void ecx_parse_sgpio(struct ecx_plat_data *pdata, u32 port, u32 state)
{
if (state & ECX_ACTIVITY_BITS)
pdata->sgpio_pattern |= sgpio_bit_shift(pdata, port,
ECX_ACTIVITY_SHIFT);
else
pdata->sgpio_pattern &= ~sgpio_bit_shift(pdata, port,
ECX_ACTIVITY_SHIFT);
if (state & ECX_LOCATE_BITS)
pdata->sgpio_pattern |= sgpio_bit_shift(pdata, port,
ECX_LOCATE_SHIFT);
else
pdata->sgpio_pattern &= ~sgpio_bit_shift(pdata, port,
ECX_LOCATE_SHIFT);
if (state & ECX_FAULT_BITS)
pdata->sgpio_pattern |= sgpio_bit_shift(pdata, port,
ECX_FAULT_SHIFT);
else
pdata->sgpio_pattern &= ~sgpio_bit_shift(pdata, port,
ECX_FAULT_SHIFT);
}
static void ecx_led_cycle_clock(struct ecx_plat_data *pdata)
{
gpio_set_value(pdata->sgpio_gpio[SCLOCK], 1);
udelay(50);
gpio_set_value(pdata->sgpio_gpio[SCLOCK], 0);
udelay(50);
}
static ssize_t ecx_transmit_led_message(struct ata_port *ap, u32 state,
ssize_t size)
{
struct ahci_host_priv *hpriv = ap->host->private_data;
struct ecx_plat_data *pdata = (struct ecx_plat_data *) hpriv->plat_data;
struct ahci_port_priv *pp = ap->private_data;
unsigned long flags;
int pmp, i;
struct ahci_em_priv *emp;
u32 sgpio_out;
pmp = (state & EM_MSG_LED_PMP_SLOT) >> 8;
if (pmp < EM_MAX_SLOTS)
emp = &pp->em_priv[pmp];
else
return -EINVAL;
if (!(hpriv->em_msg_type & EM_MSG_TYPE_LED))
return size;
spin_lock_irqsave(&sgpio_lock, flags);
ecx_parse_sgpio(pdata, ap->port_no, state);
sgpio_out = pdata->sgpio_pattern;
gpio_set_value(pdata->sgpio_gpio[SLOAD], 1);
ecx_led_cycle_clock(pdata);
gpio_set_value(pdata->sgpio_gpio[SLOAD], 0);
for (i = 0; i < (SGPIO_SIGNALS * pdata->n_ports); i++) {
gpio_set_value(pdata->sgpio_gpio[SDATA], sgpio_out & 1);
sgpio_out >>= 1;
ecx_led_cycle_clock(pdata);
}
emp->led_state = state;
spin_unlock_irqrestore(&sgpio_lock, flags);
return size;
}
static void highbank_set_em_messages(struct device *dev,
struct ahci_host_priv *hpriv,
struct ata_port_info *pi)
{
struct device_node *np = dev->of_node;
struct ecx_plat_data *pdata = hpriv->plat_data;
int i;
int err;
for (i = 0; i < SGPIO_PINS; i++) {
err = of_get_named_gpio(np, "calxeda,sgpio-gpio", i);
if (IS_ERR_VALUE(err))
return;
pdata->sgpio_gpio[i] = err;
err = gpio_request(pdata->sgpio_gpio[i], "CX SGPIO");
if (err) {
pr_err("sata_highbank gpio_request %d failed: %d\n",
i, err);
return;
}
gpio_direction_output(pdata->sgpio_gpio[i], 1);
}
of_property_read_u32_array(np, "calxeda,led-order",
pdata->port_to_sgpio,
pdata->n_ports);
hpriv->em_loc = 0;
hpriv->em_buf_sz = 4;
hpriv->em_msg_type = EM_MSG_TYPE_LED;
pi->flags |= ATA_FLAG_EM | ATA_FLAG_SW_ACTIVITY;
}
static u32 __combo_phy_reg_read(u8 sata_port, u32 addr)
{
u32 data;
u8 dev = port_data[sata_port].phy_devs;
spin_lock(&cphy_lock);
writel(CPHY_MAP(dev, addr), port_data[sata_port].phy_base + 0x800);
data = readl(port_data[sata_port].phy_base + CPHY_ADDR(addr));
spin_unlock(&cphy_lock);
return data;
}
static void __combo_phy_reg_write(u8 sata_port, u32 addr, u32 data)
{
u8 dev = port_data[sata_port].phy_devs;
spin_lock(&cphy_lock);
writel(CPHY_MAP(dev, addr), port_data[sata_port].phy_base + 0x800);
writel(data, port_data[sata_port].phy_base + CPHY_ADDR(addr));
spin_unlock(&cphy_lock);
}
static void combo_phy_wait_for_ready(u8 sata_port)
{
while (__combo_phy_reg_read(sata_port, SERDES_CR_CTL) & CR_BUSY)
udelay(5);
}
static u32 combo_phy_read(u8 sata_port, u32 addr)
{
combo_phy_wait_for_ready(sata_port);
__combo_phy_reg_write(sata_port, SERDES_CR_ADDR, addr);
__combo_phy_reg_write(sata_port, SERDES_CR_CTL, CR_START);
combo_phy_wait_for_ready(sata_port);
return __combo_phy_reg_read(sata_port, SERDES_CR_DATA);
}
static void combo_phy_write(u8 sata_port, u32 addr, u32 data)
{
combo_phy_wait_for_ready(sata_port);
__combo_phy_reg_write(sata_port, SERDES_CR_ADDR, addr);
__combo_phy_reg_write(sata_port, SERDES_CR_DATA, data);
__combo_phy_reg_write(sata_port, SERDES_CR_CTL, CR_WR_RDN | CR_START);
}
static void highbank_cphy_disable_overrides(u8 sata_port)
{
u8 lane = port_data[sata_port].lane_mapping;
u32 tmp;
if (unlikely(port_data[sata_port].phy_base == NULL))
return;
tmp = combo_phy_read(sata_port, CPHY_RX_INPUT_STS + lane * SPHY_LANE);
tmp &= ~CPHY_SATA_OVERRIDE;
combo_phy_write(sata_port, CPHY_OVERRIDE + lane * SPHY_LANE, tmp);
}
static void cphy_override_rx_mode(u8 sata_port, u32 val)
{
u8 lane = port_data[sata_port].lane_mapping;
u32 tmp;
tmp = combo_phy_read(sata_port, CPHY_RX_INPUT_STS + lane * SPHY_LANE);
tmp &= ~CPHY_SATA_OVERRIDE;
combo_phy_write(sata_port, CPHY_OVERRIDE + lane * SPHY_LANE, tmp);
tmp |= CPHY_SATA_OVERRIDE;
combo_phy_write(sata_port, CPHY_OVERRIDE + lane * SPHY_LANE, tmp);
tmp &= ~CPHY_SATA_DPLL_MODE;
tmp |= val << CPHY_SATA_DPLL_SHIFT;
combo_phy_write(sata_port, CPHY_OVERRIDE + lane * SPHY_LANE, tmp);
tmp |= CPHY_SATA_DPLL_RESET;
combo_phy_write(sata_port, CPHY_OVERRIDE + lane * SPHY_LANE, tmp);
tmp &= ~CPHY_SATA_DPLL_RESET;
combo_phy_write(sata_port, CPHY_OVERRIDE + lane * SPHY_LANE, tmp);
msleep(15);
}
static void highbank_cphy_override_lane(u8 sata_port)
{
u8 lane = port_data[sata_port].lane_mapping;
u32 tmp, k = 0;
if (unlikely(port_data[sata_port].phy_base == NULL))
return;
do {
tmp = combo_phy_read(sata_port, CPHY_RX_INPUT_STS +
lane * SPHY_LANE);
} while ((tmp & SPHY_HALF_RATE) && (k++ < 1000));
cphy_override_rx_mode(sata_port, 3);
}
static int highbank_initialize_phys(struct device *dev, void __iomem *addr)
{
struct device_node *sata_node = dev->of_node;
int phy_count = 0, phy, port = 0;
void __iomem *cphy_base[CPHY_PHY_COUNT];
struct device_node *phy_nodes[CPHY_PHY_COUNT];
memset(port_data, 0, sizeof(struct phy_lane_info) * CPHY_PORT_COUNT);
memset(phy_nodes, 0, sizeof(struct device_node*) * CPHY_PHY_COUNT);
do {
u32 tmp;
struct of_phandle_args phy_data;
if (of_parse_phandle_with_args(sata_node,
"calxeda,port-phys", "#phy-cells",
port, &phy_data))
break;
for (phy = 0; phy < phy_count; phy++) {
if (phy_nodes[phy] == phy_data.np)
break;
}
if (phy_nodes[phy] == NULL) {
phy_nodes[phy] = phy_data.np;
cphy_base[phy] = of_iomap(phy_nodes[phy], 0);
if (cphy_base[phy] == NULL) {
return 0;
}
phy_count += 1;
}
port_data[port].lane_mapping = phy_data.args[0];
of_property_read_u32(phy_nodes[phy], "phydev", &tmp);
port_data[port].phy_devs = tmp;
port_data[port].phy_base = cphy_base[phy];
of_node_put(phy_data.np);
port += 1;
} while (port < CPHY_PORT_COUNT);
return 0;
}
static int ahci_highbank_hardreset(struct ata_link *link, unsigned int *class,
unsigned long deadline)
{
static const unsigned long timing[] = { 5, 100, 500};
struct ata_port *ap = link->ap;
struct ahci_port_priv *pp = ap->private_data;
u8 *d2h_fis = pp->rx_fis + RX_FIS_D2H_REG;
struct ata_taskfile tf;
bool online;
u32 sstatus;
int rc;
int retry = 100;
ahci_stop_engine(ap);
ata_tf_init(link->device, &tf);
tf.command = ATA_BUSY;
ata_tf_to_fis(&tf, 0, 0, d2h_fis);
do {
highbank_cphy_disable_overrides(link->ap->port_no);
rc = sata_link_hardreset(link, timing, deadline, &online, NULL);
highbank_cphy_override_lane(link->ap->port_no);
if (sata_scr_read(link, SCR_STATUS, &sstatus))
break;
if (!(sstatus & 0x3))
break;
} while (!online && retry--);
ahci_start_engine(ap);
if (online)
*class = ahci_dev_classify(ap);
return rc;
}
static int ahci_highbank_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ahci_host_priv *hpriv;
struct ecx_plat_data *pdata;
struct ata_host *host;
struct resource *mem;
int irq;
int i;
int rc;
u32 n_ports;
struct ata_port_info pi = ahci_highbank_port_info;
const struct ata_port_info *ppi[] = { &pi, NULL };
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(dev, "no mmio space\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "no irq\n");
return -EINVAL;
}
hpriv = devm_kzalloc(dev, sizeof(*hpriv), GFP_KERNEL);
if (!hpriv) {
dev_err(dev, "can't alloc ahci_host_priv\n");
return -ENOMEM;
}
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(dev, "can't alloc ecx_plat_data\n");
return -ENOMEM;
}
hpriv->flags |= (unsigned long)pi.private_data;
hpriv->mmio = devm_ioremap(dev, mem->start, resource_size(mem));
if (!hpriv->mmio) {
dev_err(dev, "can't map %pR\n", mem);
return -ENOMEM;
}
rc = highbank_initialize_phys(dev, hpriv->mmio);
if (rc)
return rc;
ahci_save_initial_config(dev, hpriv, 0, 0);
if (hpriv->cap & HOST_CAP_NCQ)
pi.flags |= ATA_FLAG_NCQ;
if (hpriv->cap & HOST_CAP_PMP)
pi.flags |= ATA_FLAG_PMP;
n_ports = max(ahci_nr_ports(hpriv->cap), fls(hpriv->port_map));
pdata->n_ports = n_ports;
hpriv->plat_data = pdata;
highbank_set_em_messages(dev, hpriv, &pi);
host = ata_host_alloc_pinfo(dev, ppi, n_ports);
if (!host) {
rc = -ENOMEM;
goto err0;
}
host->private_data = hpriv;
if (!(hpriv->cap & HOST_CAP_SSS) || ahci_ignore_sss)
host->flags |= ATA_HOST_PARALLEL_SCAN;
for (i = 0; i < host->n_ports; i++) {
struct ata_port *ap = host->ports[i];
ata_port_desc(ap, "mmio %pR", mem);
ata_port_desc(ap, "port 0x%x", 0x100 + ap->port_no * 0x80);
if (ap->flags & ATA_FLAG_EM)
ap->em_message_type = hpriv->em_msg_type;
if (!(hpriv->port_map & (1 << i)))
ap->ops = &ata_dummy_port_ops;
}
rc = ahci_reset_controller(host);
if (rc)
goto err0;
ahci_init_controller(host);
ahci_print_info(host, "platform");
rc = ata_host_activate(host, irq, ahci_interrupt, 0,
&ahci_highbank_platform_sht);
if (rc)
goto err0;
return 0;
err0:
return rc;
}
static int ahci_highbank_suspend(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
struct ahci_host_priv *hpriv = host->private_data;
void __iomem *mmio = hpriv->mmio;
u32 ctl;
int rc;
if (hpriv->flags & AHCI_HFLAG_NO_SUSPEND) {
dev_err(dev, "firmware update required for suspend/resume\n");
return -EIO;
}
ctl = readl(mmio + HOST_CTL);
ctl &= ~HOST_IRQ_EN;
writel(ctl, mmio + HOST_CTL);
readl(mmio + HOST_CTL);
rc = ata_host_suspend(host, PMSG_SUSPEND);
if (rc)
return rc;
return 0;
}
static int ahci_highbank_resume(struct device *dev)
{
struct ata_host *host = dev_get_drvdata(dev);
int rc;
if (dev->power.power_state.event == PM_EVENT_SUSPEND) {
rc = ahci_reset_controller(host);
if (rc)
return rc;
ahci_init_controller(host);
}
ata_host_resume(host);
return 0;
}
