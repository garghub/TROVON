static inline void pita_set_scl_highz(struct peak_pciec_card *card)
{
u8 gp_outen = readb(card->cfg_base + PITA_GPOEN) & ~PITA_GPIN_SCL;
writeb(gp_outen, card->cfg_base + PITA_GPOEN);
}
static inline void pita_set_sda_highz(struct peak_pciec_card *card)
{
u8 gp_outen = readb(card->cfg_base + PITA_GPOEN) & ~PITA_GPIN_SDA;
writeb(gp_outen, card->cfg_base + PITA_GPOEN);
}
static void peak_pciec_init_pita_gpio(struct peak_pciec_card *card)
{
pita_set_scl_highz(card);
pita_set_sda_highz(card);
}
static void pita_setsda(void *data, int state)
{
struct peak_pciec_card *card = (struct peak_pciec_card *)data;
u8 gp_out, gp_outen;
gp_out = readb(card->cfg_base + PITA_GPOUT) & ~PITA_GPIN_SDA;
writeb(gp_out, card->cfg_base + PITA_GPOUT);
gp_outen = readb(card->cfg_base + PITA_GPOEN);
if (state)
gp_outen &= ~PITA_GPIN_SDA;
else
gp_outen |= PITA_GPIN_SDA;
writeb(gp_outen, card->cfg_base + PITA_GPOEN);
}
static void pita_setscl(void *data, int state)
{
struct peak_pciec_card *card = (struct peak_pciec_card *)data;
u8 gp_out, gp_outen;
gp_out = readb(card->cfg_base + PITA_GPOUT) & ~PITA_GPIN_SCL;
writeb(gp_out, card->cfg_base + PITA_GPOUT);
gp_outen = readb(card->cfg_base + PITA_GPOEN);
if (state)
gp_outen &= ~PITA_GPIN_SCL;
else
gp_outen |= PITA_GPIN_SCL;
writeb(gp_outen, card->cfg_base + PITA_GPOEN);
}
static int pita_getsda(void *data)
{
struct peak_pciec_card *card = (struct peak_pciec_card *)data;
pita_set_sda_highz(card);
return (readb(card->cfg_base + PITA_GPIN) & PITA_GPIN_SDA) ? 1 : 0;
}
static int pita_getscl(void *data)
{
struct peak_pciec_card *card = (struct peak_pciec_card *)data;
pita_set_scl_highz(card);
return (readb(card->cfg_base + PITA_GPIN) & PITA_GPIN_SCL) ? 1 : 0;
}
static int peak_pciec_write_pca9553(struct peak_pciec_card *card,
u8 offset, u8 data)
{
u8 buffer[2] = {
offset,
data
};
struct i2c_msg msg = {
.addr = PCA9553_1_SLAVEADDR,
.len = 2,
.buf = buffer,
};
int ret;
if ((offset == 5) && (data == card->led_cache))
return 0;
ret = i2c_transfer(&card->led_chip, &msg, 1);
if (ret < 0)
return ret;
if (offset == 5)
card->led_cache = data;
return 0;
}
static void peak_pciec_led_work(struct work_struct *work)
{
struct peak_pciec_card *card =
container_of(work, struct peak_pciec_card, led_work.work);
struct net_device *netdev;
u8 new_led = card->led_cache;
int i, up_count = 0;
for (i = 0; i < card->chan_count; i++) {
new_led &= ~PCA9553_LED_MASK(i);
new_led |= PCA9553_LED_ON(i);
netdev = card->channel[i].netdev;
if (!netdev || !(netdev->flags & IFF_UP))
continue;
up_count++;
new_led &= ~PCA9553_LED_MASK(i);
new_led |= PCA9553_LED_SLOW(i);
if (netdev->stats.rx_bytes != card->channel[i].prev_rx_bytes) {
card->channel[i].prev_rx_bytes = netdev->stats.rx_bytes;
new_led &= ~PCA9553_LED_MASK(i);
new_led |= PCA9553_LED_FAST(i);
}
if (netdev->stats.tx_bytes != card->channel[i].prev_tx_bytes) {
card->channel[i].prev_tx_bytes = netdev->stats.tx_bytes;
new_led &= ~PCA9553_LED_MASK(i);
new_led |= PCA9553_LED_FAST(i);
}
}
peak_pciec_write_pca9553(card, 5, new_led);
if (up_count)
schedule_delayed_work(&card->led_work, HZ);
}
static void peak_pciec_set_leds(struct peak_pciec_card *card, u8 led_mask, u8 s)
{
u8 new_led = card->led_cache;
int i;
for (i = 0; i < card->chan_count; i++)
if (led_mask & PCA9553_LED(i)) {
new_led &= ~PCA9553_LED_MASK(i);
new_led |= PCA9553_LED_STATE(s, i);
}
peak_pciec_write_pca9553(card, 5, new_led);
}
static void peak_pciec_start_led_work(struct peak_pciec_card *card)
{
if (!delayed_work_pending(&card->led_work))
schedule_delayed_work(&card->led_work, HZ);
}
static void peak_pciec_stop_led_work(struct peak_pciec_card *card)
{
cancel_delayed_work_sync(&card->led_work);
}
static int peak_pciec_init_leds(struct peak_pciec_card *card)
{
int err;
err = peak_pciec_write_pca9553(card, 1, 44 / 1);
if (err)
return err;
err = peak_pciec_write_pca9553(card, 2, 0x80);
if (err)
return err;
err = peak_pciec_write_pca9553(card, 3, 44 / 5);
if (err)
return err;
err = peak_pciec_write_pca9553(card, 4, 0x80);
if (err)
return err;
return peak_pciec_write_pca9553(card, 5, PCA9553_LS0_INIT);
}
static void peak_pciec_leds_exit(struct peak_pciec_card *card)
{
peak_pciec_write_pca9553(card, 5, PCA9553_LED_OFF_ALL);
}
static void peak_pciec_write_reg(const struct sja1000_priv *priv,
int port, u8 val)
{
struct peak_pci_chan *chan = priv->priv;
struct peak_pciec_card *card = chan->pciec_card;
int c = (priv->reg_base - card->reg_base) / PEAK_PCI_CHAN_SIZE;
if (port == REG_MOD)
switch (val) {
case MOD_RM:
peak_pciec_set_leds(card, PCA9553_LED(c), PCA9553_ON);
break;
case 0x00:
peak_pciec_set_leds(card, PCA9553_LED(c), PCA9553_SLOW);
peak_pciec_start_led_work(card);
break;
default:
break;
}
peak_pci_write_reg(priv, port, val);
}
static int peak_pciec_probe(struct pci_dev *pdev, struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
struct peak_pci_chan *chan = priv->priv;
struct peak_pciec_card *card;
int err;
if (chan->prev_dev) {
struct sja1000_priv *prev_priv = netdev_priv(chan->prev_dev);
struct peak_pci_chan *prev_chan = prev_priv->priv;
card = prev_chan->pciec_card;
if (!card)
return -ENODEV;
} else {
card = kzalloc(sizeof(struct peak_pciec_card), GFP_KERNEL);
if (!card) {
dev_err(&pdev->dev,
"failed allocating memory for i2c chip\n");
return -ENOMEM;
}
card->cfg_base = chan->cfg_base;
card->reg_base = priv->reg_base;
card->led_chip.owner = THIS_MODULE;
card->led_chip.dev.parent = &pdev->dev;
card->led_chip.algo_data = &card->i2c_bit;
strncpy(card->led_chip.name, "peak_i2c",
sizeof(card->led_chip.name));
card->i2c_bit = peak_pciec_i2c_bit_ops;
card->i2c_bit.udelay = 10;
card->i2c_bit.timeout = HZ;
card->i2c_bit.data = card;
peak_pciec_init_pita_gpio(card);
err = i2c_bit_add_bus(&card->led_chip);
if (err) {
dev_err(&pdev->dev, "i2c init failed\n");
goto pciec_init_err_1;
}
err = peak_pciec_init_leds(card);
if (err) {
dev_err(&pdev->dev, "leds hardware init failed\n");
goto pciec_init_err_2;
}
INIT_DELAYED_WORK(&card->led_work, peak_pciec_led_work);
priv->write_reg = peak_pciec_write_reg;
}
chan->pciec_card = card;
card->channel[card->chan_count++].netdev = dev;
return 0;
pciec_init_err_2:
i2c_del_adapter(&card->led_chip);
pciec_init_err_1:
peak_pciec_init_pita_gpio(card);
kfree(card);
return err;
}
static void peak_pciec_remove(struct peak_pciec_card *card)
{
peak_pciec_stop_led_work(card);
peak_pciec_leds_exit(card);
i2c_del_adapter(&card->led_chip);
peak_pciec_init_pita_gpio(card);
kfree(card);
}
static inline int peak_pciec_probe(struct pci_dev *pdev, struct net_device *dev)
{
return -ENODEV;
}
static inline void peak_pciec_remove(struct peak_pciec_card *card)
{
}
static u8 peak_pci_read_reg(const struct sja1000_priv *priv, int port)
{
return readb(priv->reg_base + (port << 2));
}
static void peak_pci_write_reg(const struct sja1000_priv *priv,
int port, u8 val)
{
writeb(val, priv->reg_base + (port << 2));
}
static void peak_pci_post_irq(const struct sja1000_priv *priv)
{
struct peak_pci_chan *chan = priv->priv;
u16 icr;
icr = readw(chan->cfg_base + PITA_ICR);
if (icr & chan->icr_mask)
writew(chan->icr_mask, chan->cfg_base + PITA_ICR);
}
static int __devinit peak_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct sja1000_priv *priv;
struct peak_pci_chan *chan;
struct net_device *dev;
void __iomem *cfg_base, *reg_base;
u16 sub_sys_id, icr;
int i, err, channels;
err = pci_enable_device(pdev);
if (err)
return err;
err = pci_request_regions(pdev, DRV_NAME);
if (err)
goto failure_disable_pci;
err = pci_read_config_word(pdev, 0x2e, &sub_sys_id);
if (err)
goto failure_release_regions;
dev_dbg(&pdev->dev, "probing device %04x:%04x:%04x\n",
pdev->vendor, pdev->device, sub_sys_id);
err = pci_write_config_word(pdev, 0x44, 0);
if (err)
goto failure_release_regions;
if (sub_sys_id >= 12)
channels = 4;
else if (sub_sys_id >= 10)
channels = 3;
else if (sub_sys_id >= 4)
channels = 2;
else
channels = 1;
cfg_base = pci_iomap(pdev, 0, PEAK_PCI_CFG_SIZE);
if (!cfg_base) {
dev_err(&pdev->dev, "failed to map PCI resource #0\n");
goto failure_release_regions;
}
reg_base = pci_iomap(pdev, 1, PEAK_PCI_CHAN_SIZE * channels);
if (!reg_base) {
dev_err(&pdev->dev, "failed to map PCI resource #1\n");
goto failure_unmap_cfg_base;
}
writew(0x0005, cfg_base + PITA_GPIOICR + 2);
writeb(0x00, cfg_base + PITA_GPIOICR);
writeb(0x05, cfg_base + PITA_MISC + 3);
mdelay(5);
writeb(0x04, cfg_base + PITA_MISC + 3);
icr = readw(cfg_base + PITA_ICR + 2);
for (i = 0; i < channels; i++) {
dev = alloc_sja1000dev(sizeof(struct peak_pci_chan));
if (!dev) {
err = -ENOMEM;
goto failure_remove_channels;
}
priv = netdev_priv(dev);
chan = priv->priv;
chan->cfg_base = cfg_base;
priv->reg_base = reg_base + i * PEAK_PCI_CHAN_SIZE;
priv->read_reg = peak_pci_read_reg;
priv->write_reg = peak_pci_write_reg;
priv->post_irq = peak_pci_post_irq;
priv->can.clock.freq = PEAK_PCI_CAN_CLOCK;
priv->ocr = PEAK_PCI_OCR;
priv->cdr = PEAK_PCI_CDR;
if (channels == 1 || i > 0)
priv->cdr |= CDR_CLK_OFF;
priv->irq_flags = IRQF_SHARED;
dev->irq = pdev->irq;
chan->icr_mask = peak_pci_icr_masks[i];
icr |= chan->icr_mask;
SET_NETDEV_DEV(dev, &pdev->dev);
chan->prev_dev = pci_get_drvdata(pdev);
pci_set_drvdata(pdev, dev);
if (pdev->device == PEAK_PCIEC_DEVICE_ID) {
err = peak_pciec_probe(pdev, dev);
if (err) {
dev_err(&pdev->dev,
"failed to probe device (err %d)\n",
err);
goto failure_free_dev;
}
}
err = register_sja1000dev(dev);
if (err) {
dev_err(&pdev->dev, "failed to register device\n");
goto failure_free_dev;
}
dev_info(&pdev->dev,
"%s at reg_base=0x%p cfg_base=0x%p irq=%d\n",
dev->name, priv->reg_base, chan->cfg_base, dev->irq);
}
writew(icr, cfg_base + PITA_ICR + 2);
return 0;
failure_free_dev:
pci_set_drvdata(pdev, chan->prev_dev);
free_sja1000dev(dev);
failure_remove_channels:
writew(0x0, cfg_base + PITA_ICR + 2);
chan = NULL;
for (dev = pci_get_drvdata(pdev); dev; dev = chan->prev_dev) {
unregister_sja1000dev(dev);
free_sja1000dev(dev);
priv = netdev_priv(dev);
chan = priv->priv;
}
if (chan && chan->pciec_card)
peak_pciec_remove(chan->pciec_card);
pci_iounmap(pdev, reg_base);
failure_unmap_cfg_base:
pci_iounmap(pdev, cfg_base);
failure_release_regions:
pci_release_regions(pdev);
failure_disable_pci:
pci_disable_device(pdev);
return err;
}
static void __devexit peak_pci_remove(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct sja1000_priv *priv = netdev_priv(dev);
struct peak_pci_chan *chan = priv->priv;
void __iomem *cfg_base = chan->cfg_base;
void __iomem *reg_base = priv->reg_base;
writew(0x0, cfg_base + PITA_ICR + 2);
while (1) {
dev_info(&pdev->dev, "removing device %s\n", dev->name);
unregister_sja1000dev(dev);
free_sja1000dev(dev);
dev = chan->prev_dev;
if (!dev) {
if (chan->pciec_card)
peak_pciec_remove(chan->pciec_card);
break;
}
priv = netdev_priv(dev);
chan = priv->priv;
}
pci_iounmap(pdev, reg_base);
pci_iounmap(pdev, cfg_base);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int __init peak_pci_init(void)
{
return pci_register_driver(&peak_pci_driver);
}
static void __exit peak_pci_exit(void)
{
pci_unregister_driver(&peak_pci_driver);
}
