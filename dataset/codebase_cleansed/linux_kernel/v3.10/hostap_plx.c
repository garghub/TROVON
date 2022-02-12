static inline void hfa384x_outb_debug(struct net_device *dev, int a, u8 v)
{
struct hostap_interface *iface;
local_info_t *local;
unsigned long flags;
iface = netdev_priv(dev);
local = iface->local;
spin_lock_irqsave(&local->lock, flags);
prism2_io_debug_add(dev, PRISM2_IO_DEBUG_CMD_OUTB, a, v);
outb(v, dev->base_addr + a);
spin_unlock_irqrestore(&local->lock, flags);
}
static inline u8 hfa384x_inb_debug(struct net_device *dev, int a)
{
struct hostap_interface *iface;
local_info_t *local;
unsigned long flags;
u8 v;
iface = netdev_priv(dev);
local = iface->local;
spin_lock_irqsave(&local->lock, flags);
v = inb(dev->base_addr + a);
prism2_io_debug_add(dev, PRISM2_IO_DEBUG_CMD_INB, a, v);
spin_unlock_irqrestore(&local->lock, flags);
return v;
}
static inline void hfa384x_outw_debug(struct net_device *dev, int a, u16 v)
{
struct hostap_interface *iface;
local_info_t *local;
unsigned long flags;
iface = netdev_priv(dev);
local = iface->local;
spin_lock_irqsave(&local->lock, flags);
prism2_io_debug_add(dev, PRISM2_IO_DEBUG_CMD_OUTW, a, v);
outw(v, dev->base_addr + a);
spin_unlock_irqrestore(&local->lock, flags);
}
static inline u16 hfa384x_inw_debug(struct net_device *dev, int a)
{
struct hostap_interface *iface;
local_info_t *local;
unsigned long flags;
u16 v;
iface = netdev_priv(dev);
local = iface->local;
spin_lock_irqsave(&local->lock, flags);
v = inw(dev->base_addr + a);
prism2_io_debug_add(dev, PRISM2_IO_DEBUG_CMD_INW, a, v);
spin_unlock_irqrestore(&local->lock, flags);
return v;
}
static inline void hfa384x_outsw_debug(struct net_device *dev, int a,
u8 *buf, int wc)
{
struct hostap_interface *iface;
local_info_t *local;
unsigned long flags;
iface = netdev_priv(dev);
local = iface->local;
spin_lock_irqsave(&local->lock, flags);
prism2_io_debug_add(dev, PRISM2_IO_DEBUG_CMD_OUTSW, a, wc);
outsw(dev->base_addr + a, buf, wc);
spin_unlock_irqrestore(&local->lock, flags);
}
static inline void hfa384x_insw_debug(struct net_device *dev, int a,
u8 *buf, int wc)
{
struct hostap_interface *iface;
local_info_t *local;
unsigned long flags;
iface = netdev_priv(dev);
local = iface->local;
spin_lock_irqsave(&local->lock, flags);
prism2_io_debug_add(dev, PRISM2_IO_DEBUG_CMD_INSW, a, wc);
insw(dev->base_addr + a, buf, wc);
spin_unlock_irqrestore(&local->lock, flags);
}
static int hfa384x_from_bap(struct net_device *dev, u16 bap, void *buf,
int len)
{
u16 d_off;
u16 *pos;
d_off = (bap == 1) ? HFA384X_DATA1_OFF : HFA384X_DATA0_OFF;
pos = (u16 *) buf;
if (len / 2)
HFA384X_INSW(d_off, buf, len / 2);
pos += len / 2;
if (len & 1)
*((char *) pos) = HFA384X_INB(d_off);
return 0;
}
static int hfa384x_to_bap(struct net_device *dev, u16 bap, void *buf, int len)
{
u16 d_off;
u16 *pos;
d_off = (bap == 1) ? HFA384X_DATA1_OFF : HFA384X_DATA0_OFF;
pos = (u16 *) buf;
if (len / 2)
HFA384X_OUTSW(d_off, buf, len / 2);
pos += len / 2;
if (len & 1)
HFA384X_OUTB(*((char *) pos), d_off);
return 0;
}
static void prism2_plx_cor_sreset(local_info_t *local)
{
unsigned char corsave;
struct hostap_plx_priv *hw_priv = local->hw_priv;
printk(KERN_DEBUG "%s: Doing reset via direct COR access.\n",
dev_info);
if (hw_priv->attr_mem == NULL) {
corsave = inb(hw_priv->cor_offset);
outb(corsave | COR_SRESET, hw_priv->cor_offset);
mdelay(2);
outb(corsave & ~COR_SRESET, hw_priv->cor_offset);
mdelay(2);
} else {
corsave = readb(hw_priv->attr_mem + hw_priv->cor_offset);
writeb(corsave | COR_SRESET,
hw_priv->attr_mem + hw_priv->cor_offset);
mdelay(2);
writeb(corsave & ~COR_SRESET,
hw_priv->attr_mem + hw_priv->cor_offset);
mdelay(2);
}
}
static void prism2_plx_genesis_reset(local_info_t *local, int hcr)
{
unsigned char corsave;
struct hostap_plx_priv *hw_priv = local->hw_priv;
if (hw_priv->attr_mem == NULL) {
corsave = inb(hw_priv->cor_offset);
outb(corsave | COR_SRESET, hw_priv->cor_offset);
mdelay(10);
outb(hcr, hw_priv->cor_offset + 2);
mdelay(10);
outb(corsave & ~COR_SRESET, hw_priv->cor_offset);
mdelay(10);
} else {
corsave = readb(hw_priv->attr_mem + hw_priv->cor_offset);
writeb(corsave | COR_SRESET,
hw_priv->attr_mem + hw_priv->cor_offset);
mdelay(10);
writeb(hcr, hw_priv->attr_mem + hw_priv->cor_offset + 2);
mdelay(10);
writeb(corsave & ~COR_SRESET,
hw_priv->attr_mem + hw_priv->cor_offset);
mdelay(10);
}
}
static int prism2_plx_check_cis(void __iomem *attr_mem, int attr_len,
unsigned int *cor_offset,
unsigned int *cor_index)
{
#define CISTPL_CONFIG 0x1A
#define CISTPL_MANFID 0x20
#define CISTPL_END 0xFF
#define CIS_MAX_LEN 256
u8 *cis;
int i, pos;
unsigned int rmsz, rasz, manfid1, manfid2;
struct prism2_plx_manfid *manfid;
cis = kmalloc(CIS_MAX_LEN, GFP_KERNEL);
if (cis == NULL)
return -ENOMEM;
for (i = 0; i < CIS_MAX_LEN; i++)
cis[i] = readb(attr_mem + 2 * i);
printk(KERN_DEBUG "%s: CIS: %02x %02x %02x %02x %02x %02x ...\n",
dev_info, cis[0], cis[1], cis[2], cis[3], cis[4], cis[5]);
*cor_offset = 0x3e0;
*cor_index = 0x01;
manfid1 = manfid2 = 0;
pos = 0;
while (pos < CIS_MAX_LEN - 1 && cis[pos] != CISTPL_END) {
if (pos + 2 + cis[pos + 1] > CIS_MAX_LEN)
goto cis_error;
switch (cis[pos]) {
case CISTPL_CONFIG:
if (cis[pos + 1] < 2)
goto cis_error;
rmsz = (cis[pos + 2] & 0x3c) >> 2;
rasz = cis[pos + 2] & 0x03;
if (4 + rasz + rmsz > cis[pos + 1])
goto cis_error;
*cor_index = cis[pos + 3] & 0x3F;
*cor_offset = 0;
for (i = 0; i <= rasz; i++)
*cor_offset += cis[pos + 4 + i] << (8 * i);
printk(KERN_DEBUG "%s: cor_index=0x%x "
"cor_offset=0x%x\n", dev_info,
*cor_index, *cor_offset);
if (*cor_offset > attr_len) {
printk(KERN_ERR "%s: COR offset not within "
"attr_mem\n", dev_info);
kfree(cis);
return -1;
}
break;
case CISTPL_MANFID:
if (cis[pos + 1] < 4)
goto cis_error;
manfid1 = cis[pos + 2] + (cis[pos + 3] << 8);
manfid2 = cis[pos + 4] + (cis[pos + 5] << 8);
printk(KERN_DEBUG "%s: manfid=0x%04x, 0x%04x\n",
dev_info, manfid1, manfid2);
break;
}
pos += cis[pos + 1] + 2;
}
if (pos >= CIS_MAX_LEN || cis[pos] != CISTPL_END)
goto cis_error;
for (manfid = prism2_plx_known_manfids; manfid->manfid1 != 0; manfid++)
if (manfid1 == manfid->manfid1 && manfid2 == manfid->manfid2) {
kfree(cis);
return 0;
}
printk(KERN_INFO "%s: unknown manfid 0x%04x, 0x%04x - assuming this is"
" not supported card\n", dev_info, manfid1, manfid2);
goto fail;
cis_error:
printk(KERN_WARNING "%s: invalid CIS data\n", dev_info);
fail:
kfree(cis);
if (ignore_cis) {
printk(KERN_INFO "%s: ignore_cis parameter set - ignoring "
"errors during CIS verification\n", dev_info);
return 0;
}
return -1;
}
static int prism2_plx_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
unsigned int pccard_ioaddr, plx_ioaddr;
unsigned long pccard_attr_mem;
unsigned int pccard_attr_len;
void __iomem *attr_mem = NULL;
unsigned int cor_offset = 0, cor_index = 0;
u32 reg;
local_info_t *local = NULL;
struct net_device *dev = NULL;
struct hostap_interface *iface;
static int cards_found ;
int irq_registered = 0;
int tmd7160;
struct hostap_plx_priv *hw_priv;
hw_priv = kzalloc(sizeof(*hw_priv), GFP_KERNEL);
if (hw_priv == NULL)
return -ENOMEM;
if (pci_enable_device(pdev))
goto err_out_free;
tmd7160 = (pdev->vendor == 0x15e8) && (pdev->device == 0x0131);
plx_ioaddr = pci_resource_start(pdev, 1);
pccard_ioaddr = pci_resource_start(pdev, tmd7160 ? 2 : 3);
if (tmd7160) {
attr_mem = NULL;
printk(KERN_INFO "TMD7160 PCI/PCMCIA adapter: io=0x%x, "
"irq=%d, pccard_io=0x%x\n",
plx_ioaddr, pdev->irq, pccard_ioaddr);
cor_offset = plx_ioaddr;
cor_index = 0x04;
outb(cor_index | COR_LEVLREQ | COR_ENABLE_FUNC, plx_ioaddr);
mdelay(1);
reg = inb(plx_ioaddr);
if (reg != (cor_index | COR_LEVLREQ | COR_ENABLE_FUNC)) {
printk(KERN_ERR "%s: Error setting COR (expected="
"0x%02x, was=0x%02x)\n", dev_info,
cor_index | COR_LEVLREQ | COR_ENABLE_FUNC, reg);
goto fail;
}
} else {
pccard_attr_mem = pci_resource_start(pdev, 2);
pccard_attr_len = pci_resource_len(pdev, 2);
if (pccard_attr_len < PLX_MIN_ATTR_LEN)
goto fail;
attr_mem = ioremap(pccard_attr_mem, pccard_attr_len);
if (attr_mem == NULL) {
printk(KERN_ERR "%s: cannot remap attr_mem\n",
dev_info);
goto fail;
}
printk(KERN_INFO "PLX9052 PCI/PCMCIA adapter: "
"mem=0x%lx, plx_io=0x%x, irq=%d, pccard_io=0x%x\n",
pccard_attr_mem, plx_ioaddr, pdev->irq, pccard_ioaddr);
if (prism2_plx_check_cis(attr_mem, pccard_attr_len,
&cor_offset, &cor_index)) {
printk(KERN_INFO "Unknown PC Card CIS - not a "
"Prism2/2.5 card?\n");
goto fail;
}
printk(KERN_DEBUG "Prism2/2.5 PC Card detected in PLX9052 "
"adapter\n");
writeb(cor_index | COR_LEVLREQ | COR_ENABLE_FUNC,
attr_mem + cor_offset);
reg = inl(plx_ioaddr + PLX_INTCSR);
printk(KERN_DEBUG "PLX_INTCSR=0x%x\n", reg);
if (!(reg & PLX_INTCSR_PCI_INTEN)) {
outl(reg | PLX_INTCSR_PCI_INTEN,
plx_ioaddr + PLX_INTCSR);
if (!(inl(plx_ioaddr + PLX_INTCSR) &
PLX_INTCSR_PCI_INTEN)) {
printk(KERN_WARNING "%s: Could not enable "
"Local Interrupts\n", dev_info);
goto fail;
}
}
reg = inl(plx_ioaddr + PLX_CNTRL);
printk(KERN_DEBUG "PLX_CNTRL=0x%x (Serial EEPROM "
"present=%d)\n",
reg, (reg & PLX_CNTRL_SERIAL_EEPROM_PRESENT) != 0);
}
dev = prism2_init_local_data(&prism2_plx_funcs, cards_found,
&pdev->dev);
if (dev == NULL)
goto fail;
iface = netdev_priv(dev);
local = iface->local;
local->hw_priv = hw_priv;
cards_found++;
dev->irq = pdev->irq;
dev->base_addr = pccard_ioaddr;
hw_priv->attr_mem = attr_mem;
hw_priv->cor_offset = cor_offset;
pci_set_drvdata(pdev, dev);
if (request_irq(dev->irq, prism2_interrupt, IRQF_SHARED, dev->name,
dev)) {
printk(KERN_WARNING "%s: request_irq failed\n", dev->name);
goto fail;
} else
irq_registered = 1;
if (prism2_hw_config(dev, 1)) {
printk(KERN_DEBUG "%s: hardware initialization failed\n",
dev_info);
goto fail;
}
return hostap_hw_ready(dev);
fail:
if (irq_registered && dev)
free_irq(dev->irq, dev);
if (attr_mem)
iounmap(attr_mem);
pci_disable_device(pdev);
prism2_free_local_data(dev);
err_out_free:
kfree(hw_priv);
return -ENODEV;
}
static void prism2_plx_remove(struct pci_dev *pdev)
{
struct net_device *dev;
struct hostap_interface *iface;
struct hostap_plx_priv *hw_priv;
dev = pci_get_drvdata(pdev);
iface = netdev_priv(dev);
hw_priv = iface->local->hw_priv;
prism2_plx_cor_sreset(iface->local);
hfa384x_disable_interrupts(dev);
if (hw_priv->attr_mem)
iounmap(hw_priv->attr_mem);
if (dev->irq)
free_irq(dev->irq, dev);
prism2_free_local_data(dev);
kfree(hw_priv);
pci_disable_device(pdev);
}
