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
static int prism2_pccard_card_present(local_info_t *local)
{
struct hostap_cs_priv *hw_priv = local->hw_priv;
if (hw_priv != NULL && hw_priv->link != NULL && pcmcia_dev_present(hw_priv->link))
return 1;
return 0;
}
static void sandisk_set_iobase(local_info_t *local)
{
int res;
struct hostap_cs_priv *hw_priv = local->hw_priv;
res = pcmcia_write_config_byte(hw_priv->link, 0x10,
hw_priv->link->resource[0]->start & 0x00ff);
if (res != 0) {
printk(KERN_DEBUG "Prism3 SanDisk - failed to set I/O base 0 -"
" res=%d\n", res);
}
udelay(10);
res = pcmcia_write_config_byte(hw_priv->link, 0x12,
(hw_priv->link->resource[0]->start >> 8) & 0x00ff);
if (res != 0) {
printk(KERN_DEBUG "Prism3 SanDisk - failed to set I/O base 1 -"
" res=%d\n", res);
}
}
static void sandisk_write_hcr(local_info_t *local, int hcr)
{
struct net_device *dev = local->dev;
int i;
HFA384X_OUTB(0x80, SANDISK_WLAN_ACTIVATION_OFF);
udelay(50);
for (i = 0; i < 10; i++) {
HFA384X_OUTB(hcr, SANDISK_HCR_OFF);
}
udelay(55);
HFA384X_OUTB(0x45, SANDISK_WLAN_ACTIVATION_OFF);
}
static int sandisk_enable_wireless(struct net_device *dev)
{
int res, ret = 0;
struct hostap_interface *iface = netdev_priv(dev);
local_info_t *local = iface->local;
struct hostap_cs_priv *hw_priv = local->hw_priv;
if (resource_size(hw_priv->link->resource[0]) < 0x42) {
ret = -ENODEV;
goto done;
}
if (hw_priv->link->manf_id != 0xd601 || hw_priv->link->card_id != 0x0101) {
ret = -ENODEV;
goto done;
}
if (hw_priv->link->socket->functions < 2) {
ret = -ENODEV;
goto done;
}
printk(KERN_DEBUG "%s: Multi-function SanDisk ConnectPlus detected"
" - using vendor-specific initialization\n", dev->name);
hw_priv->sandisk_connectplus = 1;
res = pcmcia_write_config_byte(hw_priv->link, CISREG_COR,
COR_SOFT_RESET);
if (res != 0) {
printk(KERN_DEBUG "%s: SanDisk - COR sreset failed (%d)\n",
dev->name, res);
goto done;
}
mdelay(5);
res = pcmcia_write_config_byte(hw_priv->link, CISREG_COR,
(COR_LEVEL_REQ | 0x8 | COR_ADDR_DECODE |
COR_FUNC_ENA));
if (res != 0) {
printk(KERN_DEBUG "%s: SanDisk - COR sreset failed (%d)\n",
dev->name, res);
goto done;
}
mdelay(5);
sandisk_set_iobase(local);
HFA384X_OUTB(0xc5, SANDISK_WLAN_ACTIVATION_OFF);
udelay(10);
HFA384X_OUTB(0x4b, SANDISK_WLAN_ACTIVATION_OFF);
udelay(10);
done:
return ret;
}
static void prism2_pccard_cor_sreset(local_info_t *local)
{
int res;
u8 val;
struct hostap_cs_priv *hw_priv = local->hw_priv;
if (!prism2_pccard_card_present(local))
return;
res = pcmcia_read_config_byte(hw_priv->link, CISREG_COR, &val);
if (res != 0) {
printk(KERN_DEBUG "prism2_pccard_cor_sreset failed 1 (%d)\n",
res);
return;
}
printk(KERN_DEBUG "prism2_pccard_cor_sreset: original COR %02x\n",
val);
val |= COR_SOFT_RESET;
res = pcmcia_write_config_byte(hw_priv->link, CISREG_COR, val);
if (res != 0) {
printk(KERN_DEBUG "prism2_pccard_cor_sreset failed 2 (%d)\n",
res);
return;
}
mdelay(hw_priv->sandisk_connectplus ? 5 : 2);
val &= ~COR_SOFT_RESET;
if (hw_priv->sandisk_connectplus)
val |= COR_IREQ_ENA;
res = pcmcia_write_config_byte(hw_priv->link, CISREG_COR, val);
if (res != 0) {
printk(KERN_DEBUG "prism2_pccard_cor_sreset failed 3 (%d)\n",
res);
return;
}
mdelay(hw_priv->sandisk_connectplus ? 5 : 2);
if (hw_priv->sandisk_connectplus)
sandisk_set_iobase(local);
}
static void prism2_pccard_genesis_reset(local_info_t *local, int hcr)
{
int res;
u8 old_cor;
struct hostap_cs_priv *hw_priv = local->hw_priv;
if (!prism2_pccard_card_present(local))
return;
if (hw_priv->sandisk_connectplus) {
sandisk_write_hcr(local, hcr);
return;
}
res = pcmcia_read_config_byte(hw_priv->link, CISREG_COR, &old_cor);
if (res != 0) {
printk(KERN_DEBUG "%s failed 1 (%d)\n", __func__, res);
return;
}
printk(KERN_DEBUG "%s: original COR %02x\n", __func__, old_cor);
res = pcmcia_write_config_byte(hw_priv->link, CISREG_COR,
old_cor | COR_SOFT_RESET);
if (res != 0) {
printk(KERN_DEBUG "%s failed 2 (%d)\n", __func__, res);
return;
}
mdelay(10);
res = pcmcia_write_config_byte(hw_priv->link, CISREG_CCSR, hcr);
if (res != 0) {
printk(KERN_DEBUG "%s failed 3 (%d)\n", __func__, res);
return;
}
mdelay(10);
res = pcmcia_write_config_byte(hw_priv->link, CISREG_COR,
old_cor & ~COR_SOFT_RESET);
if (res != 0) {
printk(KERN_DEBUG "%s failed 4 (%d)\n", __func__, res);
return;
}
mdelay(10);
}
static int hostap_cs_probe(struct pcmcia_device *p_dev)
{
int ret;
PDEBUG(DEBUG_HW, "%s: setting Vcc=33 (constant)\n", dev_info);
ret = prism2_config(p_dev);
if (ret) {
PDEBUG(DEBUG_EXTRA, "prism2_config() failed\n");
}
return ret;
}
static void prism2_detach(struct pcmcia_device *link)
{
PDEBUG(DEBUG_FLOW, "prism2_detach\n");
prism2_release((u_long)link);
if (link->priv) {
struct hostap_cs_priv *hw_priv;
struct net_device *dev;
struct hostap_interface *iface;
dev = link->priv;
iface = netdev_priv(dev);
hw_priv = iface->local->hw_priv;
prism2_free_local_data(dev);
kfree(hw_priv);
}
}
static int prism2_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
if (p_dev->config_index == 0)
return -EINVAL;
return pcmcia_request_io(p_dev);
}
static int prism2_config(struct pcmcia_device *link)
{
struct net_device *dev;
struct hostap_interface *iface;
local_info_t *local;
int ret;
struct hostap_cs_priv *hw_priv;
unsigned long flags;
PDEBUG(DEBUG_FLOW, "prism2_config()\n");
hw_priv = kzalloc(sizeof(*hw_priv), GFP_KERNEL);
if (hw_priv == NULL) {
ret = -ENOMEM;
goto failed;
}
link->config_flags |= CONF_AUTO_SET_VPP | CONF_AUTO_AUDIO |
CONF_AUTO_CHECK_VCC | CONF_AUTO_SET_IO | CONF_ENABLE_IRQ;
if (ignore_cis_vcc)
link->config_flags &= ~CONF_AUTO_CHECK_VCC;
ret = pcmcia_loop_config(link, prism2_config_check, NULL);
if (ret) {
if (!ignore_cis_vcc)
printk(KERN_ERR "GetNextTuple(): No matching "
"CIS configuration. Maybe you need the "
"ignore_cis_vcc=1 parameter.\n");
goto failed;
}
dev = prism2_init_local_data(&prism2_pccard_funcs, 0,
&link->dev);
if (!dev) {
ret = -ENOMEM;
goto failed;
}
link->priv = dev;
iface = netdev_priv(dev);
local = iface->local;
local->hw_priv = hw_priv;
hw_priv->link = link;
ret = pcmcia_request_irq(link, prism2_interrupt);
if (ret)
goto failed;
ret = pcmcia_enable_device(link);
if (ret)
goto failed;
spin_lock_irqsave(&local->irq_init_lock, flags);
dev->irq = link->irq;
dev->base_addr = link->resource[0]->start;
spin_unlock_irqrestore(&local->irq_init_lock, flags);
local->shutdown = 0;
sandisk_enable_wireless(dev);
ret = prism2_hw_config(dev, 1);
if (!ret)
ret = hostap_hw_ready(dev);
return ret;
failed:
kfree(hw_priv);
prism2_release((u_long)link);
return ret;
}
static void prism2_release(u_long arg)
{
struct pcmcia_device *link = (struct pcmcia_device *)arg;
PDEBUG(DEBUG_FLOW, "prism2_release\n");
if (link->priv) {
struct net_device *dev = link->priv;
struct hostap_interface *iface;
iface = netdev_priv(dev);
prism2_hw_shutdown(dev, 0);
iface->local->shutdown = 1;
}
pcmcia_disable_device(link);
PDEBUG(DEBUG_FLOW, "release - done\n");
}
static int hostap_cs_suspend(struct pcmcia_device *link)
{
struct net_device *dev = (struct net_device *) link->priv;
int dev_open = 0;
struct hostap_interface *iface = NULL;
if (!dev)
return -ENODEV;
iface = netdev_priv(dev);
PDEBUG(DEBUG_EXTRA, "%s: CS_EVENT_PM_SUSPEND\n", dev_info);
if (iface && iface->local)
dev_open = iface->local->num_dev_open > 0;
if (dev_open) {
netif_stop_queue(dev);
netif_device_detach(dev);
}
prism2_suspend(dev);
return 0;
}
static int hostap_cs_resume(struct pcmcia_device *link)
{
struct net_device *dev = (struct net_device *) link->priv;
int dev_open = 0;
struct hostap_interface *iface = NULL;
if (!dev)
return -ENODEV;
iface = netdev_priv(dev);
PDEBUG(DEBUG_EXTRA, "%s: CS_EVENT_PM_RESUME\n", dev_info);
if (iface && iface->local)
dev_open = iface->local->num_dev_open > 0;
prism2_hw_shutdown(dev, 1);
prism2_hw_config(dev, dev_open ? 0 : 1);
if (dev_open) {
netif_device_attach(dev);
netif_start_queue(dev);
}
return 0;
}
