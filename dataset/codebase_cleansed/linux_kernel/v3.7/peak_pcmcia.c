static void pcan_start_led_timer(struct pcan_pccard *card)
{
if (!timer_pending(&card->led_timer))
mod_timer(&card->led_timer, jiffies + HZ);
}
static void pcan_stop_led_timer(struct pcan_pccard *card)
{
del_timer_sync(&card->led_timer);
}
static u8 pcan_read_canreg(const struct sja1000_priv *priv, int port)
{
return ioread8(priv->reg_base + port);
}
static void pcan_write_canreg(const struct sja1000_priv *priv, int port, u8 v)
{
struct pcan_pccard *card = priv->priv;
int c = (priv->reg_base - card->ioport_addr) / PCC_CHAN_SIZE;
if (port == REG_MOD)
switch (v) {
case MOD_RM:
pcan_set_leds(card, PCC_LED(c), PCC_LED_ON);
break;
case 0x00:
pcan_set_leds(card, PCC_LED(c), PCC_LED_SLOW);
pcan_start_led_timer(card);
break;
default:
break;
}
iowrite8(v, priv->reg_base + port);
}
static u8 pcan_read_reg(struct pcan_pccard *card, int port)
{
return ioread8(card->ioport_addr + PCC_COMN_OFF + port);
}
static void pcan_write_reg(struct pcan_pccard *card, int port, u8 v)
{
if (port == PCC_CCR) {
if (card->ccr == v)
return;
card->ccr = v;
}
iowrite8(v, card->ioport_addr + PCC_COMN_OFF + port);
}
static inline int pcan_pccard_present(struct pcan_pccard *card)
{
return ((pcan_read_reg(card, PCC_FW_MAJOR) == card->fw_major) &&
(pcan_read_reg(card, PCC_FW_MINOR) == card->fw_minor));
}
static int pcan_wait_spi_busy(struct pcan_pccard *card)
{
unsigned long timeout = jiffies +
msecs_to_jiffies(PCC_SPI_MAX_BUSY_WAIT_MS) + 1;
while (pcan_read_reg(card, PCC_CSR) & PCC_CSR_SPI_BUSY) {
if (time_after(jiffies, timeout))
return -EBUSY;
schedule();
}
return 0;
}
static int pcan_write_eeprom(struct pcan_pccard *card, u16 addr, u8 v)
{
u8 status;
int err, i;
pcan_write_reg(card, PCC_SPI_IR, PCC_EEP_WREN);
err = pcan_wait_spi_busy(card);
if (err)
goto we_spi_err;
for (i = 0; i < PCC_WRITE_MAX_LOOP; i++) {
pcan_write_reg(card, PCC_SPI_IR, PCC_EEP_RDSR);
err = pcan_wait_spi_busy(card);
if (err)
goto we_spi_err;
status = pcan_read_reg(card, PCC_SPI_DIR);
if (status & PCC_EEP_SR_WEN)
break;
}
if (i >= PCC_WRITE_MAX_LOOP) {
dev_err(&card->pdev->dev,
"stop waiting to be allowed to write in eeprom\n");
return -EIO;
}
pcan_write_reg(card, PCC_SPI_ADR, addr & 0xff);
pcan_write_reg(card, PCC_SPI_DOR, v);
pcan_write_reg(card, PCC_SPI_IR, PCC_EEP_WRITE(addr));
err = pcan_wait_spi_busy(card);
if (err)
goto we_spi_err;
for (i = 0; i < PCC_WRITE_MAX_LOOP; i++) {
pcan_write_reg(card, PCC_SPI_IR, PCC_EEP_RDSR);
err = pcan_wait_spi_busy(card);
if (err)
goto we_spi_err;
status = pcan_read_reg(card, PCC_SPI_DIR);
if (!(status & PCC_EEP_SR_WIP))
break;
}
if (i >= PCC_WRITE_MAX_LOOP) {
dev_err(&card->pdev->dev,
"stop waiting for write in eeprom to complete\n");
return -EIO;
}
pcan_write_reg(card, PCC_SPI_IR, PCC_EEP_WRDI);
err = pcan_wait_spi_busy(card);
if (err)
goto we_spi_err;
return 0;
we_spi_err:
dev_err(&card->pdev->dev,
"stop waiting (spi engine always busy) err %d\n", err);
return err;
}
static void pcan_set_leds(struct pcan_pccard *card, u8 led_mask, u8 state)
{
u8 ccr = card->ccr;
int i;
for (i = 0; i < card->chan_count; i++)
if (led_mask & PCC_LED(i)) {
ccr &= ~PCC_CCR_LED_MASK_CHAN(i);
ccr |= PCC_CCR_LED_CHAN(state, i);
}
pcan_write_reg(card, PCC_CCR, ccr);
}
static inline void pcan_set_can_power(struct pcan_pccard *card, int onoff)
{
int err;
err = pcan_write_eeprom(card, 0, !!onoff);
if (err)
dev_err(&card->pdev->dev,
"failed setting power %s to can connectors (err %d)\n",
(onoff) ? "on" : "off", err);
}
static void pcan_led_timer(unsigned long arg)
{
struct pcan_pccard *card = (struct pcan_pccard *)arg;
struct net_device *netdev;
int i, up_count = 0;
u8 ccr;
ccr = card->ccr;
for (i = 0; i < card->chan_count; i++) {
ccr &= ~PCC_CCR_LED_MASK_CHAN(i);
ccr |= PCC_CCR_LED_ON_CHAN(i);
netdev = card->channel[i].netdev;
if (!netdev || !(netdev->flags & IFF_UP))
continue;
up_count++;
ccr &= ~PCC_CCR_LED_MASK_CHAN(i);
ccr |= PCC_CCR_LED_SLOW_CHAN(i);
if (netdev->stats.rx_bytes != card->channel[i].prev_rx_bytes) {
card->channel[i].prev_rx_bytes = netdev->stats.rx_bytes;
ccr &= ~PCC_CCR_LED_MASK_CHAN(i);
ccr |= PCC_CCR_LED_FAST_CHAN(i);
}
if (netdev->stats.tx_bytes != card->channel[i].prev_tx_bytes) {
card->channel[i].prev_tx_bytes = netdev->stats.tx_bytes;
ccr &= ~PCC_CCR_LED_MASK_CHAN(i);
ccr |= PCC_CCR_LED_FAST_CHAN(i);
}
}
pcan_write_reg(card, PCC_CCR, ccr);
if (up_count)
mod_timer(&card->led_timer, jiffies + HZ);
}
static irqreturn_t pcan_isr(int irq, void *dev_id)
{
struct pcan_pccard *card = dev_id;
int irq_handled;
for (irq_handled = 0; irq_handled < PCC_ISR_MAX_LOOP; irq_handled++) {
int nothing_to_handle = 1;
int i;
for (i = 0; i < card->chan_count; i++) {
struct net_device *netdev;
if (!pcan_pccard_present(card)) {
return IRQ_NONE;
}
netdev = card->channel[i].netdev;
if (netdev &&
sja1000_interrupt(irq, netdev) == IRQ_HANDLED)
nothing_to_handle = 0;
}
if (nothing_to_handle)
break;
}
return (irq_handled) ? IRQ_HANDLED : IRQ_NONE;
}
static void pcan_free_channels(struct pcan_pccard *card)
{
int i;
u8 led_mask = 0;
for (i = 0; i < card->chan_count; i++) {
struct net_device *netdev;
char name[IFNAMSIZ];
led_mask |= PCC_LED(i);
netdev = card->channel[i].netdev;
if (!netdev)
continue;
strncpy(name, netdev->name, IFNAMSIZ);
unregister_sja1000dev(netdev);
free_sja1000dev(netdev);
dev_info(&card->pdev->dev, "%s removed\n", name);
}
if (pcan_pccard_present(card)) {
pcan_set_leds(card, led_mask, PCC_LED_OFF);
pcan_set_can_power(card, 0);
}
}
static inline int pcan_channel_present(struct sja1000_priv *priv)
{
pcan_write_canreg(priv, REG_MOD, 1);
pcan_write_canreg(priv, REG_CDR, CDR_PELICAN);
if (pcan_read_canreg(priv, REG_CDR) == CDR_PELICAN)
return 1;
return 0;
}
static int pcan_add_channels(struct pcan_pccard *card)
{
struct pcmcia_device *pdev = card->pdev;
int i, err = 0;
u8 ccr = PCC_CCR_INIT;
card->ccr = ~ccr;
pcan_write_reg(card, PCC_CCR, ccr);
mdelay(2);
ccr &= ~PCC_CCR_RST_ALL;
pcan_write_reg(card, PCC_CCR, ccr);
for (i = 0; i < ARRAY_SIZE(card->channel); i++) {
struct net_device *netdev;
struct sja1000_priv *priv;
netdev = alloc_sja1000dev(0);
if (!netdev) {
err = -ENOMEM;
break;
}
priv = netdev_priv(netdev);
priv->priv = card;
SET_NETDEV_DEV(netdev, &pdev->dev);
priv->irq_flags = IRQF_SHARED;
netdev->irq = pdev->irq;
priv->reg_base = card->ioport_addr + PCC_CHAN_OFF(i);
if (!pcan_channel_present(priv)) {
dev_err(&pdev->dev, "channel %d not present\n", i);
free_sja1000dev(netdev);
continue;
}
priv->read_reg = pcan_read_canreg;
priv->write_reg = pcan_write_canreg;
priv->can.clock.freq = PCC_CAN_CLOCK;
priv->ocr = PCC_OCR;
priv->cdr = PCC_CDR;
if (i > 0)
priv->cdr |= CDR_CLK_OFF;
priv->flags |= SJA1000_CUSTOM_IRQ_HANDLER;
err = register_sja1000dev(netdev);
if (err) {
free_sja1000dev(netdev);
continue;
}
card->channel[i].netdev = netdev;
card->chan_count++;
ccr &= ~PCC_CCR_LED_OFF_CHAN(i);
dev_info(&pdev->dev,
"%s on channel %d at 0x%p irq %d\n",
netdev->name, i, priv->reg_base, pdev->irq);
}
pcan_write_reg(card, PCC_CCR, ccr);
return err;
}
static int pcan_conf_check(struct pcmcia_device *pdev, void *priv_data)
{
pdev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
pdev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
pdev->io_lines = 10;
return pcmcia_request_io(pdev);
}
static void pcan_free(struct pcmcia_device *pdev)
{
struct pcan_pccard *card = pdev->priv;
if (!card)
return;
free_irq(pdev->irq, card);
pcan_stop_led_timer(card);
pcan_free_channels(card);
ioport_unmap(card->ioport_addr);
kfree(card);
pdev->priv = NULL;
}
static int __devinit pcan_probe(struct pcmcia_device *pdev)
{
struct pcan_pccard *card;
int err;
pdev->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
err = pcmcia_loop_config(pdev, pcan_conf_check, NULL);
if (err) {
dev_err(&pdev->dev, "pcmcia_loop_config() error %d\n", err);
goto probe_err_1;
}
if (!pdev->irq) {
dev_err(&pdev->dev, "no irq assigned\n");
err = -ENODEV;
goto probe_err_1;
}
err = pcmcia_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "pcmcia_enable_device failed err=%d\n",
err);
goto probe_err_1;
}
card = kzalloc(sizeof(struct pcan_pccard), GFP_KERNEL);
if (!card) {
dev_err(&pdev->dev, "couldn't allocate card memory\n");
err = -ENOMEM;
goto probe_err_2;
}
card->pdev = pdev;
pdev->priv = card;
card->ioport_addr = ioport_map(pdev->resource[0]->start,
resource_size(pdev->resource[0]));
if (!card->ioport_addr) {
dev_err(&pdev->dev, "couldn't map io port into io memory\n");
err = -ENOMEM;
goto probe_err_3;
}
card->fw_major = pcan_read_reg(card, PCC_FW_MAJOR);
card->fw_minor = pcan_read_reg(card, PCC_FW_MINOR);
dev_info(&pdev->dev, "PEAK-System pcmcia card %s fw %d.%d\n",
pdev->prod_id[1] ? pdev->prod_id[1] : "PCAN-PC Card",
card->fw_major, card->fw_minor);
pcan_add_channels(card);
if (!card->chan_count) {
err = -ENOMEM;
goto probe_err_4;
}
init_timer(&card->led_timer);
card->led_timer.function = pcan_led_timer;
card->led_timer.data = (unsigned long)card;
err = request_irq(pdev->irq, &pcan_isr, IRQF_SHARED, PCC_NAME, card);
if (err) {
dev_err(&pdev->dev, "couldn't request irq%d\n", pdev->irq);
goto probe_err_5;
}
pcan_set_can_power(card, 1);
return 0;
probe_err_5:
pcan_free_channels(card);
probe_err_4:
ioport_unmap(card->ioport_addr);
probe_err_3:
kfree(card);
pdev->priv = NULL;
probe_err_2:
pcmcia_disable_device(pdev);
probe_err_1:
return err;
}
static void pcan_remove(struct pcmcia_device *pdev)
{
pcan_free(pdev);
pcmcia_disable_device(pdev);
}
static int __init pcan_init(void)
{
return pcmcia_register_driver(&pcan_driver);
}
static void __exit pcan_exit(void)
{
pcmcia_unregister_driver(&pcan_driver);
}
