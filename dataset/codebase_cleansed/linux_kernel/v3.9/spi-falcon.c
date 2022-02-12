int falcon_sflash_xfer(struct spi_device *spi, struct spi_transfer *t,
unsigned long flags)
{
struct device *dev = &spi->dev;
struct falcon_sflash *priv = spi_master_get_devdata(spi->master);
const u8 *txp = t->tx_buf;
u8 *rxp = t->rx_buf;
unsigned int bytelen = ((8 * t->len + 7) / 8);
unsigned int len, alen, dumlen;
u32 val;
enum {
state_init,
state_command_prepare,
state_write,
state_read,
state_disable_cs,
state_end
} state = state_init;
do {
switch (state) {
case state_init:
{
if (flags & FALCON_SPI_XFER_BEGIN) {
if (!txp) {
dev_err(dev,
"BEGIN without tx data!\n");
return -ENODATA;
}
priv->sfcmd = ((spi->chip_select
<< SFCMD_CS_OFFSET)
& SFCMD_CS_MASK);
priv->sfcmd |= SFCMD_KEEP_CS_KEEP_SELECTED;
priv->sfcmd |= *txp;
txp++;
bytelen--;
if (bytelen) {
state = state_command_prepare;
break;
} else {
dev_dbg(dev, "write cmd %02X\n",
priv->sfcmd & SFCMD_OPC_MASK);
}
}
if (txp && bytelen) {
state = state_write;
break;
}
if (rxp && bytelen) {
state = state_read;
break;
}
if (flags & FALCON_SPI_XFER_END)
state = state_disable_cs;
else
state = state_end;
break;
}
case state_command_prepare:
{
val = 0;
alen = 0;
dumlen = 0;
while (bytelen > 0) {
if (alen < 3) {
val = (val << 8) | (*txp++);
alen++;
} else if ((dumlen < 15) && (*txp == 0)) {
dumlen++;
txp++;
} else {
break;
}
bytelen--;
}
priv->sfcmd &= ~(SFCMD_ALEN_MASK | SFCMD_DUMLEN_MASK);
priv->sfcmd |= (alen << SFCMD_ALEN_OFFSET) |
(dumlen << SFCMD_DUMLEN_OFFSET);
if (alen > 0)
ltq_ebu_w32(val, SFADDR);
dev_dbg(dev, "wr %02X, alen=%d (addr=%06X) dlen=%d\n",
priv->sfcmd & SFCMD_OPC_MASK,
alen, val, dumlen);
if (bytelen > 0) {
state = state_write;
} else if (flags & FALCON_SPI_XFER_END) {
state = state_disable_cs;
} else {
state = state_end;
}
break;
}
case state_write:
{
priv->sfcmd |= SFCMD_DIR_WRITE;
len = 0;
val = 0;
do {
if (bytelen--)
val |= (*txp++) << (8 * len++);
if ((flags & FALCON_SPI_XFER_END)
&& (bytelen == 0)) {
priv->sfcmd &=
~SFCMD_KEEP_CS_KEEP_SELECTED;
}
if ((len == 4) || (bytelen == 0)) {
ltq_ebu_w32(val, SFDATA);
ltq_ebu_w32(priv->sfcmd
| (len<<SFCMD_DLEN_OFFSET),
SFCMD);
len = 0;
val = 0;
priv->sfcmd &= ~(SFCMD_ALEN_MASK
| SFCMD_DUMLEN_MASK);
}
} while (bytelen);
state = state_end;
break;
}
case state_read:
{
priv->sfcmd &= ~SFCMD_DIR_WRITE;
do {
if ((flags & FALCON_SPI_XFER_END)
&& (bytelen <= 4)) {
priv->sfcmd &=
~SFCMD_KEEP_CS_KEEP_SELECTED;
}
len = (bytelen > 4) ? 4 : bytelen;
bytelen -= len;
ltq_ebu_w32(priv->sfcmd
| (len << SFCMD_DLEN_OFFSET), SFCMD);
priv->sfcmd &= ~(SFCMD_ALEN_MASK
| SFCMD_DUMLEN_MASK);
do {
val = ltq_ebu_r32(SFSTAT);
if (val & SFSTAT_CMD_ERR) {
dev_err(dev, "SFSTAT: CMD_ERR");
dev_err(dev, " (%x)\n", val);
ltq_ebu_w32(SFSTAT_CMD_ERR,
SFSTAT);
return -EBADE;
}
} while (val & SFSTAT_CMD_PEND);
val = ltq_ebu_r32(SFDATA);
do {
*rxp = (val & 0xFF);
rxp++;
val >>= 8;
len--;
} while (len);
} while (bytelen);
state = state_end;
break;
}
case state_disable_cs:
{
priv->sfcmd &= ~SFCMD_KEEP_CS_KEEP_SELECTED;
ltq_ebu_w32(priv->sfcmd | (0 << SFCMD_DLEN_OFFSET),
SFCMD);
val = ltq_ebu_r32(SFSTAT);
if (val & SFSTAT_CMD_ERR) {
dev_err(dev, "SFSTAT: CMD_ERR (%x)\n", val);
ltq_ebu_w32(SFSTAT_CMD_ERR, SFSTAT);
return -EBADE;
}
state = state_end;
break;
}
case state_end:
break;
}
} while (state != state_end);
return 0;
}
static int falcon_sflash_setup(struct spi_device *spi)
{
unsigned int i;
unsigned long flags;
if (spi->chip_select > 0)
return -ENODEV;
spin_lock_irqsave(&ebu_lock, flags);
if (spi->max_speed_hz >= CLOCK_100M) {
ltq_sys1_w32_mask(0, EBUCC_EBUDIV_SELF100, EBUCC);
i = 1;
} else {
ltq_sys1_w32_mask(EBUCC_EBUDIV_SELF100, 0, EBUCC);
for (i = 1; i < 7; i++) {
if (CLOCK_50M / i <= spi->max_speed_hz)
break;
}
}
ltq_ebu_w32_mask(SFTIME_SCKF_POS_MASK
| SFTIME_SCKR_POS_MASK
| SFTIME_SCK_PER_MASK,
(i << SFTIME_SCKR_POS_OFFSET)
| (i << (SFTIME_SCK_PER_OFFSET + 1)),
SFTIME);
ltq_ebu_w32((SFIO_UNUSED_WD_MASK & (0x8 | 0x4)), SFIO);
ltq_ebu_w32(BUSRCON0_AGEN_SERIAL_FLASH | BUSRCON0_PORTW_8_BIT_MUX,
BUSRCON0);
ltq_ebu_w32(BUSWCON0_AGEN_SERIAL_FLASH, BUSWCON0);
ltq_ebu_w32_mask(SFCON_DEV_SIZE_MASK, SFCON_DEV_SIZE_A23_0, SFCON);
spin_unlock_irqrestore(&ebu_lock, flags);
return 0;
}
static int falcon_sflash_prepare_xfer(struct spi_master *master)
{
return 0;
}
static int falcon_sflash_unprepare_xfer(struct spi_master *master)
{
return 0;
}
static int falcon_sflash_xfer_one(struct spi_master *master,
struct spi_message *m)
{
struct falcon_sflash *priv = spi_master_get_devdata(master);
struct spi_transfer *t;
unsigned long spi_flags;
unsigned long flags;
int ret = 0;
priv->sfcmd = 0;
m->actual_length = 0;
spi_flags = FALCON_SPI_XFER_BEGIN;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (list_is_last(&t->transfer_list, &m->transfers))
spi_flags |= FALCON_SPI_XFER_END;
spin_lock_irqsave(&ebu_lock, flags);
ret = falcon_sflash_xfer(m->spi, t, spi_flags);
spin_unlock_irqrestore(&ebu_lock, flags);
if (ret)
break;
m->actual_length += t->len;
WARN_ON(t->delay_usecs || t->cs_change);
spi_flags = 0;
}
m->status = ret;
spi_finalize_current_message(master);
return 0;
}
static int falcon_sflash_probe(struct platform_device *pdev)
{
struct falcon_sflash *priv;
struct spi_master *master;
int ret;
if (ltq_boot_select() != BS_SPI) {
dev_err(&pdev->dev, "invalid bootstrap options\n");
return -ENODEV;
}
master = spi_alloc_master(&pdev->dev, sizeof(*priv));
if (!master)
return -ENOMEM;
priv = spi_master_get_devdata(master);
priv->master = master;
master->mode_bits = SPI_MODE_3;
master->num_chipselect = 1;
master->flags = SPI_MASTER_HALF_DUPLEX;
master->bus_num = -1;
master->setup = falcon_sflash_setup;
master->prepare_transfer_hardware = falcon_sflash_prepare_xfer;
master->transfer_one_message = falcon_sflash_xfer_one;
master->unprepare_transfer_hardware = falcon_sflash_unprepare_xfer;
master->dev.of_node = pdev->dev.of_node;
platform_set_drvdata(pdev, priv);
ret = spi_register_master(master);
if (ret)
spi_master_put(master);
return ret;
}
static int falcon_sflash_remove(struct platform_device *pdev)
{
struct falcon_sflash *priv = platform_get_drvdata(pdev);
spi_unregister_master(priv->master);
return 0;
}
