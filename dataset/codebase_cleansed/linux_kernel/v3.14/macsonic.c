static inline void bit_reverse_addr(unsigned char addr[6])
{
int i;
for(i = 0; i < 6; i++)
addr[i] = bitrev8(addr[i]);
}
static irqreturn_t macsonic_interrupt(int irq, void *dev_id)
{
irqreturn_t result;
unsigned long flags;
local_irq_save(flags);
result = sonic_interrupt(irq, dev_id);
local_irq_restore(flags);
return result;
}
static int macsonic_open(struct net_device* dev)
{
int retval;
retval = request_irq(dev->irq, sonic_interrupt, 0, "sonic", dev);
if (retval) {
printk(KERN_ERR "%s: unable to get IRQ %d.\n",
dev->name, dev->irq);
goto err;
}
if (dev->irq == IRQ_AUTO_3) {
retval = request_irq(IRQ_NUBUS_9, macsonic_interrupt, 0,
"sonic", dev);
if (retval) {
printk(KERN_ERR "%s: unable to get IRQ %d.\n",
dev->name, IRQ_NUBUS_9);
goto err_irq;
}
}
retval = sonic_open(dev);
if (retval)
goto err_irq_nubus;
return 0;
err_irq_nubus:
if (dev->irq == IRQ_AUTO_3)
free_irq(IRQ_NUBUS_9, dev);
err_irq:
free_irq(dev->irq, dev);
err:
return retval;
}
static int macsonic_close(struct net_device* dev)
{
int err;
err = sonic_close(dev);
free_irq(dev->irq, dev);
if (dev->irq == IRQ_AUTO_3)
free_irq(IRQ_NUBUS_9, dev);
return err;
}
static int macsonic_init(struct net_device *dev)
{
struct sonic_local* lp = netdev_priv(dev);
lp->descriptors = dma_alloc_coherent(lp->device,
SIZEOF_SONIC_DESC *
SONIC_BUS_SCALE(lp->dma_bitmode),
&lp->descriptors_laddr,
GFP_KERNEL);
if (lp->descriptors == NULL)
return -ENOMEM;
lp->cda = lp->descriptors;
lp->tda = lp->cda + (SIZEOF_SONIC_CDA
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->rda = lp->tda + (SIZEOF_SONIC_TD * SONIC_NUM_TDS
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->rra = lp->rda + (SIZEOF_SONIC_RD * SONIC_NUM_RDS
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->cda_laddr = lp->descriptors_laddr;
lp->tda_laddr = lp->cda_laddr + (SIZEOF_SONIC_CDA
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->rda_laddr = lp->tda_laddr + (SIZEOF_SONIC_TD * SONIC_NUM_TDS
* SONIC_BUS_SCALE(lp->dma_bitmode));
lp->rra_laddr = lp->rda_laddr + (SIZEOF_SONIC_RD * SONIC_NUM_RDS
* SONIC_BUS_SCALE(lp->dma_bitmode));
dev->netdev_ops = &macsonic_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
SONIC_WRITE(SONIC_CRCT, 0xffff);
SONIC_WRITE(SONIC_FAET, 0xffff);
SONIC_WRITE(SONIC_MPT, 0xffff);
return 0;
}
static void mac_onboard_sonic_ethernet_addr(struct net_device *dev)
{
struct sonic_local *lp = netdev_priv(dev);
const int prom_addr = ONBOARD_SONIC_PROM_BASE;
unsigned short val;
if (hwreg_present((void *)prom_addr)) {
int i;
for (i = 0; i < 6; i++)
dev->dev_addr[i] = SONIC_READ_PROM(i);
if (!INVALID_MAC(dev->dev_addr))
return;
bit_reverse_addr(dev->dev_addr);
if (!INVALID_MAC(dev->dev_addr))
return;
printk(KERN_WARNING "macsonic: MAC address in PROM seems "
"to be invalid, trying CAM\n");
} else {
printk(KERN_WARNING "macsonic: cannot read MAC address from "
"PROM, trying CAM\n");
}
SONIC_WRITE(SONIC_CMD, SONIC_CR_RST);
SONIC_WRITE(SONIC_CEP, 15);
val = SONIC_READ(SONIC_CAP2);
dev->dev_addr[5] = val >> 8;
dev->dev_addr[4] = val & 0xff;
val = SONIC_READ(SONIC_CAP1);
dev->dev_addr[3] = val >> 8;
dev->dev_addr[2] = val & 0xff;
val = SONIC_READ(SONIC_CAP0);
dev->dev_addr[1] = val >> 8;
dev->dev_addr[0] = val & 0xff;
if (!INVALID_MAC(dev->dev_addr))
return;
printk(KERN_WARNING "macsonic: MAC address in CAM entry 15 "
"seems invalid, will use a random MAC\n");
eth_hw_addr_random(dev);
}
static int mac_onboard_sonic_probe(struct net_device *dev)
{
struct sonic_local* lp = netdev_priv(dev);
int sr;
int commslot = 0;
if (!MACH_IS_MAC)
return -ENODEV;
printk(KERN_INFO "Checking for internal Macintosh ethernet (SONIC).. ");
if (macintosh_config->ident == MAC_MODEL_Q630 ||
macintosh_config->ident == MAC_MODEL_P588 ||
macintosh_config->ident == MAC_MODEL_P575 ||
macintosh_config->ident == MAC_MODEL_C610) {
unsigned long flags;
int card_present;
local_irq_save(flags);
card_present = hwreg_present((void*)ONBOARD_SONIC_REGISTERS);
local_irq_restore(flags);
if (!card_present) {
printk("none.\n");
return -ENODEV;
}
commslot = 1;
}
printk("yes\n");
dev->base_addr = ONBOARD_SONIC_REGISTERS;
if (via_alt_mapping)
dev->irq = IRQ_AUTO_3;
else
dev->irq = IRQ_NUBUS_9;
if (!sonic_version_printed) {
printk(KERN_INFO "%s", version);
sonic_version_printed = 1;
}
printk(KERN_INFO "%s: onboard / comm-slot SONIC at 0x%08lx\n",
dev_name(lp->device), dev->base_addr);
if (macintosh_config->ident == MAC_MODEL_PB520) {
lp->reg_offset = 0;
lp->dma_bitmode = SONIC_BITMODE16;
sr = SONIC_READ(SONIC_SR);
} else if (commslot) {
lp->reg_offset = 2;
lp->dma_bitmode = SONIC_BITMODE16;
sr = SONIC_READ(SONIC_SR);
if (sr == 0x0004 || sr == 0x0006 || sr == 0x0100 || sr == 0x0101)
lp->dma_bitmode = SONIC_BITMODE32;
else {
lp->dma_bitmode = SONIC_BITMODE16;
lp->reg_offset = 0;
sr = SONIC_READ(SONIC_SR);
}
} else {
lp->reg_offset = 2;
lp->dma_bitmode = SONIC_BITMODE32;
sr = SONIC_READ(SONIC_SR);
}
printk(KERN_INFO
"%s: revision 0x%04x, using %d bit DMA and register offset %d\n",
dev_name(lp->device), sr, lp->dma_bitmode?32:16, lp->reg_offset);
#if 0
printk(KERN_INFO "%s: DCR: 0x%04x, DCR2: 0x%04x\n", dev_name(lp->device),
SONIC_READ(SONIC_DCR) & 0xffff, SONIC_READ(SONIC_DCR2) & 0xffff);
#endif
SONIC_WRITE(SONIC_CMD, SONIC_CR_RST);
SONIC_WRITE(SONIC_DCR, SONIC_DCR_EXBUS | SONIC_DCR_BMS |
SONIC_DCR_RFT1 | SONIC_DCR_TFT0 |
(lp->dma_bitmode ? SONIC_DCR_DW : 0));
SONIC_WRITE(SONIC_DCR2, 0);
SONIC_WRITE(SONIC_IMR, 0);
SONIC_WRITE(SONIC_ISR, 0x7fff);
mac_onboard_sonic_ethernet_addr(dev);
return macsonic_init(dev);
}
static int mac_nubus_sonic_ethernet_addr(struct net_device *dev,
unsigned long prom_addr, int id)
{
int i;
for(i = 0; i < 6; i++)
dev->dev_addr[i] = SONIC_READ_PROM(i);
if (id != MACSONIC_DAYNA)
bit_reverse_addr(dev->dev_addr);
return 0;
}
static int macsonic_ident(struct nubus_dev *ndev)
{
if (ndev->dr_hw == NUBUS_DRHW_ASANTE_LC &&
ndev->dr_sw == NUBUS_DRSW_SONIC_LC)
return MACSONIC_DAYNALINK;
if (ndev->dr_hw == NUBUS_DRHW_SONIC &&
ndev->dr_sw == NUBUS_DRSW_APPLE) {
if (strstr(ndev->board->name, "DuoDock"))
return MACSONIC_DUODOCK;
else
return MACSONIC_APPLE;
}
if (ndev->dr_hw == NUBUS_DRHW_SMC9194 &&
ndev->dr_sw == NUBUS_DRSW_DAYNA)
return MACSONIC_DAYNA;
if (ndev->dr_hw == NUBUS_DRHW_APPLE_SONIC_LC &&
ndev->dr_sw == 0) {
return MACSONIC_APPLE16;
}
return -1;
}
static int mac_nubus_sonic_probe(struct net_device *dev)
{
static int slots;
struct nubus_dev* ndev = NULL;
struct sonic_local* lp = netdev_priv(dev);
unsigned long base_addr, prom_addr;
u16 sonic_dcr;
int id = -1;
int reg_offset, dma_bitmode;
while ((ndev = nubus_find_type(NUBUS_CAT_NETWORK,
NUBUS_TYPE_ETHERNET, ndev)) != NULL)
{
if (slots & (1<<ndev->board->slot))
continue;
slots |= 1<<ndev->board->slot;
if ((id = macsonic_ident(ndev)) != -1)
break;
}
if (ndev == NULL)
return -ENODEV;
switch (id) {
case MACSONIC_DUODOCK:
base_addr = ndev->board->slot_addr + DUODOCK_SONIC_REGISTERS;
prom_addr = ndev->board->slot_addr + DUODOCK_SONIC_PROM_BASE;
sonic_dcr = SONIC_DCR_EXBUS | SONIC_DCR_RFT0 | SONIC_DCR_RFT1 |
SONIC_DCR_TFT0;
reg_offset = 2;
dma_bitmode = SONIC_BITMODE32;
break;
case MACSONIC_APPLE:
base_addr = ndev->board->slot_addr + APPLE_SONIC_REGISTERS;
prom_addr = ndev->board->slot_addr + APPLE_SONIC_PROM_BASE;
sonic_dcr = SONIC_DCR_BMS | SONIC_DCR_RFT1 | SONIC_DCR_TFT0;
reg_offset = 0;
dma_bitmode = SONIC_BITMODE32;
break;
case MACSONIC_APPLE16:
base_addr = ndev->board->slot_addr + APPLE_SONIC_REGISTERS;
prom_addr = ndev->board->slot_addr + APPLE_SONIC_PROM_BASE;
sonic_dcr = SONIC_DCR_EXBUS | SONIC_DCR_RFT1 | SONIC_DCR_TFT0 |
SONIC_DCR_PO1 | SONIC_DCR_BMS;
reg_offset = 0;
dma_bitmode = SONIC_BITMODE16;
break;
case MACSONIC_DAYNALINK:
base_addr = ndev->board->slot_addr + APPLE_SONIC_REGISTERS;
prom_addr = ndev->board->slot_addr + DAYNALINK_PROM_BASE;
sonic_dcr = SONIC_DCR_RFT1 | SONIC_DCR_TFT0 |
SONIC_DCR_PO1 | SONIC_DCR_BMS;
reg_offset = 0;
dma_bitmode = SONIC_BITMODE16;
break;
case MACSONIC_DAYNA:
base_addr = ndev->board->slot_addr + DAYNA_SONIC_REGISTERS;
prom_addr = ndev->board->slot_addr + DAYNA_SONIC_MAC_ADDR;
sonic_dcr = SONIC_DCR_BMS |
SONIC_DCR_RFT1 | SONIC_DCR_TFT0 | SONIC_DCR_PO1;
reg_offset = 0;
dma_bitmode = SONIC_BITMODE16;
break;
default:
printk(KERN_ERR "macsonic: WTF, id is %d\n", id);
return -ENODEV;
}
dev->base_addr = base_addr;
lp->reg_offset = reg_offset;
lp->dma_bitmode = dma_bitmode;
dev->irq = SLOT2IRQ(ndev->board->slot);
if (!sonic_version_printed) {
printk(KERN_INFO "%s", version);
sonic_version_printed = 1;
}
printk(KERN_INFO "%s: %s in slot %X\n",
dev_name(lp->device), ndev->board->name, ndev->board->slot);
printk(KERN_INFO "%s: revision 0x%04x, using %d bit DMA and register offset %d\n",
dev_name(lp->device), SONIC_READ(SONIC_SR), dma_bitmode?32:16, reg_offset);
#if 0
printk(KERN_INFO "%s: DCR: 0x%04x, DCR2: 0x%04x\n", dev_name(lp->device),
SONIC_READ(SONIC_DCR) & 0xffff, SONIC_READ(SONIC_DCR2) & 0xffff);
#endif
SONIC_WRITE(SONIC_CMD, SONIC_CR_RST);
SONIC_WRITE(SONIC_DCR, sonic_dcr | (dma_bitmode ? SONIC_DCR_DW : 0));
SONIC_WRITE(SONIC_DCR2, 0);
SONIC_WRITE(SONIC_IMR, 0);
SONIC_WRITE(SONIC_ISR, 0x7fff);
if (mac_nubus_sonic_ethernet_addr(dev, prom_addr, id) != 0)
return -ENODEV;
return macsonic_init(dev);
}
static int mac_sonic_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct sonic_local *lp;
int err;
dev = alloc_etherdev(sizeof(struct sonic_local));
if (!dev)
return -ENOMEM;
lp = netdev_priv(dev);
lp->device = &pdev->dev;
SET_NETDEV_DEV(dev, &pdev->dev);
platform_set_drvdata(pdev, dev);
err = mac_onboard_sonic_probe(dev);
if (err == 0)
goto found;
if (err != -ENODEV)
goto out;
err = mac_nubus_sonic_probe(dev);
if (err)
goto out;
found:
err = register_netdev(dev);
if (err)
goto out;
printk("%s: MAC %pM IRQ %d\n", dev->name, dev->dev_addr, dev->irq);
return 0;
out:
free_netdev(dev);
return err;
}
static int mac_sonic_device_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct sonic_local* lp = netdev_priv(dev);
unregister_netdev(dev);
dma_free_coherent(lp->device, SIZEOF_SONIC_DESC * SONIC_BUS_SCALE(lp->dma_bitmode),
lp->descriptors, lp->descriptors_laddr);
free_netdev(dev);
return 0;
}
