static void fsl_spi_change_mode(struct spi_device *spi)
{
struct mpc8xxx_spi *mspi = spi_master_get_devdata(spi->master);
struct spi_mpc8xxx_cs *cs = spi->controller_state;
struct fsl_spi_reg *reg_base = mspi->reg_base;
__be32 __iomem *mode = &reg_base->mode;
unsigned long flags;
if (cs->hw_mode == mpc8xxx_spi_read_reg(mode))
return;
local_irq_save(flags);
mpc8xxx_spi_write_reg(mode, cs->hw_mode & ~SPMODE_ENABLE);
if (mspi->flags & SPI_CPM_MODE) {
if (mspi->flags & SPI_QE) {
qe_issue_cmd(QE_INIT_TX_RX, mspi->subblock,
QE_CR_PROTOCOL_UNSPECIFIED, 0);
} else {
cpm_command(CPM_SPI_CMD, CPM_CR_INIT_TRX);
if (mspi->flags & SPI_CPM1) {
out_be16(&mspi->pram->rbptr,
in_be16(&mspi->pram->rbase));
out_be16(&mspi->pram->tbptr,
in_be16(&mspi->pram->tbase));
}
}
}
mpc8xxx_spi_write_reg(mode, cs->hw_mode);
local_irq_restore(flags);
}
static void fsl_spi_chipselect(struct spi_device *spi, int value)
{
struct mpc8xxx_spi *mpc8xxx_spi = spi_master_get_devdata(spi->master);
struct fsl_spi_platform_data *pdata;
bool pol = spi->mode & SPI_CS_HIGH;
struct spi_mpc8xxx_cs *cs = spi->controller_state;
pdata = spi->dev.parent->parent->platform_data;
if (value == BITBANG_CS_INACTIVE) {
if (pdata->cs_control)
pdata->cs_control(spi, !pol);
}
if (value == BITBANG_CS_ACTIVE) {
mpc8xxx_spi->rx_shift = cs->rx_shift;
mpc8xxx_spi->tx_shift = cs->tx_shift;
mpc8xxx_spi->get_rx = cs->get_rx;
mpc8xxx_spi->get_tx = cs->get_tx;
fsl_spi_change_mode(spi);
if (pdata->cs_control)
pdata->cs_control(spi, pol);
}
}
static int mspi_apply_cpu_mode_quirks(struct spi_mpc8xxx_cs *cs,
struct spi_device *spi,
struct mpc8xxx_spi *mpc8xxx_spi,
int bits_per_word)
{
cs->rx_shift = 0;
cs->tx_shift = 0;
if (bits_per_word <= 8) {
cs->get_rx = mpc8xxx_spi_rx_buf_u8;
cs->get_tx = mpc8xxx_spi_tx_buf_u8;
if (mpc8xxx_spi->flags & SPI_QE_CPU_MODE) {
cs->rx_shift = 16;
cs->tx_shift = 24;
}
} else if (bits_per_word <= 16) {
cs->get_rx = mpc8xxx_spi_rx_buf_u16;
cs->get_tx = mpc8xxx_spi_tx_buf_u16;
if (mpc8xxx_spi->flags & SPI_QE_CPU_MODE) {
cs->rx_shift = 16;
cs->tx_shift = 16;
}
} else if (bits_per_word <= 32) {
cs->get_rx = mpc8xxx_spi_rx_buf_u32;
cs->get_tx = mpc8xxx_spi_tx_buf_u32;
} else
return -EINVAL;
if (mpc8xxx_spi->flags & SPI_QE_CPU_MODE &&
spi->mode & SPI_LSB_FIRST) {
cs->tx_shift = 0;
if (bits_per_word <= 8)
cs->rx_shift = 8;
else
cs->rx_shift = 0;
}
mpc8xxx_spi->rx_shift = cs->rx_shift;
mpc8xxx_spi->tx_shift = cs->tx_shift;
mpc8xxx_spi->get_rx = cs->get_rx;
mpc8xxx_spi->get_tx = cs->get_tx;
return bits_per_word;
}
static int mspi_apply_qe_mode_quirks(struct spi_mpc8xxx_cs *cs,
struct spi_device *spi,
int bits_per_word)
{
if (spi->mode & SPI_LSB_FIRST &&
bits_per_word > 8)
return -EINVAL;
if (bits_per_word > 8)
return 8;
return bits_per_word;
}
static int fsl_spi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct mpc8xxx_spi *mpc8xxx_spi;
int bits_per_word = 0;
u8 pm;
u32 hz = 0;
struct spi_mpc8xxx_cs *cs = spi->controller_state;
mpc8xxx_spi = spi_master_get_devdata(spi->master);
if (t) {
bits_per_word = t->bits_per_word;
hz = t->speed_hz;
}
if (!bits_per_word)
bits_per_word = spi->bits_per_word;
if ((bits_per_word < 4)
|| ((bits_per_word > 16) && (bits_per_word != 32)))
return -EINVAL;
if (!hz)
hz = spi->max_speed_hz;
if (!(mpc8xxx_spi->flags & SPI_CPM_MODE))
bits_per_word = mspi_apply_cpu_mode_quirks(cs, spi,
mpc8xxx_spi,
bits_per_word);
else if (mpc8xxx_spi->flags & SPI_QE)
bits_per_word = mspi_apply_qe_mode_quirks(cs, spi,
bits_per_word);
if (bits_per_word < 0)
return bits_per_word;
if (bits_per_word == 32)
bits_per_word = 0;
else
bits_per_word = bits_per_word - 1;
cs->hw_mode &= ~(SPMODE_LEN(0xF) | SPMODE_DIV16
| SPMODE_PM(0xF));
cs->hw_mode |= SPMODE_LEN(bits_per_word);
if ((mpc8xxx_spi->spibrg / hz) > 64) {
cs->hw_mode |= SPMODE_DIV16;
pm = (mpc8xxx_spi->spibrg - 1) / (hz * 64) + 1;
WARN_ONCE(pm > 16, "%s: Requested speed is too low: %d Hz. "
"Will use %d Hz instead.\n", dev_name(&spi->dev),
hz, mpc8xxx_spi->spibrg / 1024);
if (pm > 16)
pm = 16;
} else {
pm = (mpc8xxx_spi->spibrg - 1) / (hz * 4) + 1;
}
if (pm)
pm--;
cs->hw_mode |= SPMODE_PM(pm);
fsl_spi_change_mode(spi);
return 0;
}
static void fsl_spi_cpm_bufs_start(struct mpc8xxx_spi *mspi)
{
struct cpm_buf_desc __iomem *tx_bd = mspi->tx_bd;
struct cpm_buf_desc __iomem *rx_bd = mspi->rx_bd;
unsigned int xfer_len = min(mspi->count, SPI_MRBLR);
unsigned int xfer_ofs;
struct fsl_spi_reg *reg_base = mspi->reg_base;
xfer_ofs = mspi->xfer_in_progress->len - mspi->count;
if (mspi->rx_dma == mspi->dma_dummy_rx)
out_be32(&rx_bd->cbd_bufaddr, mspi->rx_dma);
else
out_be32(&rx_bd->cbd_bufaddr, mspi->rx_dma + xfer_ofs);
out_be16(&rx_bd->cbd_datlen, 0);
out_be16(&rx_bd->cbd_sc, BD_SC_EMPTY | BD_SC_INTRPT | BD_SC_WRAP);
if (mspi->tx_dma == mspi->dma_dummy_tx)
out_be32(&tx_bd->cbd_bufaddr, mspi->tx_dma);
else
out_be32(&tx_bd->cbd_bufaddr, mspi->tx_dma + xfer_ofs);
out_be16(&tx_bd->cbd_datlen, xfer_len);
out_be16(&tx_bd->cbd_sc, BD_SC_READY | BD_SC_INTRPT | BD_SC_WRAP |
BD_SC_LAST);
mpc8xxx_spi_write_reg(&reg_base->command, SPCOM_STR);
}
static int fsl_spi_cpm_bufs(struct mpc8xxx_spi *mspi,
struct spi_transfer *t, bool is_dma_mapped)
{
struct device *dev = mspi->dev;
struct fsl_spi_reg *reg_base = mspi->reg_base;
if (is_dma_mapped) {
mspi->map_tx_dma = 0;
mspi->map_rx_dma = 0;
} else {
mspi->map_tx_dma = 1;
mspi->map_rx_dma = 1;
}
if (!t->tx_buf) {
mspi->tx_dma = mspi->dma_dummy_tx;
mspi->map_tx_dma = 0;
}
if (!t->rx_buf) {
mspi->rx_dma = mspi->dma_dummy_rx;
mspi->map_rx_dma = 0;
}
if (mspi->map_tx_dma) {
void *nonconst_tx = (void *)mspi->tx;
mspi->tx_dma = dma_map_single(dev, nonconst_tx, t->len,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, mspi->tx_dma)) {
dev_err(dev, "unable to map tx dma\n");
return -ENOMEM;
}
} else if (t->tx_buf) {
mspi->tx_dma = t->tx_dma;
}
if (mspi->map_rx_dma) {
mspi->rx_dma = dma_map_single(dev, mspi->rx, t->len,
DMA_FROM_DEVICE);
if (dma_mapping_error(dev, mspi->rx_dma)) {
dev_err(dev, "unable to map rx dma\n");
goto err_rx_dma;
}
} else if (t->rx_buf) {
mspi->rx_dma = t->rx_dma;
}
mpc8xxx_spi_write_reg(&reg_base->mask, SPIE_RXB);
mspi->xfer_in_progress = t;
mspi->count = t->len;
fsl_spi_cpm_bufs_start(mspi);
return 0;
err_rx_dma:
if (mspi->map_tx_dma)
dma_unmap_single(dev, mspi->tx_dma, t->len, DMA_TO_DEVICE);
return -ENOMEM;
}
static void fsl_spi_cpm_bufs_complete(struct mpc8xxx_spi *mspi)
{
struct device *dev = mspi->dev;
struct spi_transfer *t = mspi->xfer_in_progress;
if (mspi->map_tx_dma)
dma_unmap_single(dev, mspi->tx_dma, t->len, DMA_TO_DEVICE);
if (mspi->map_rx_dma)
dma_unmap_single(dev, mspi->rx_dma, t->len, DMA_FROM_DEVICE);
mspi->xfer_in_progress = NULL;
}
static int fsl_spi_cpu_bufs(struct mpc8xxx_spi *mspi,
struct spi_transfer *t, unsigned int len)
{
u32 word;
struct fsl_spi_reg *reg_base = mspi->reg_base;
mspi->count = len;
mpc8xxx_spi_write_reg(&reg_base->mask, SPIM_NE);
word = mspi->get_tx(mspi);
mpc8xxx_spi_write_reg(&reg_base->transmit, word);
return 0;
}
static int fsl_spi_bufs(struct spi_device *spi, struct spi_transfer *t,
bool is_dma_mapped)
{
struct mpc8xxx_spi *mpc8xxx_spi = spi_master_get_devdata(spi->master);
struct fsl_spi_reg *reg_base;
unsigned int len = t->len;
u8 bits_per_word;
int ret;
reg_base = mpc8xxx_spi->reg_base;
bits_per_word = spi->bits_per_word;
if (t->bits_per_word)
bits_per_word = t->bits_per_word;
if (bits_per_word > 8) {
if (len & 1)
return -EINVAL;
len /= 2;
}
if (bits_per_word > 16) {
if (len & 1)
return -EINVAL;
len /= 2;
}
mpc8xxx_spi->tx = t->tx_buf;
mpc8xxx_spi->rx = t->rx_buf;
INIT_COMPLETION(mpc8xxx_spi->done);
if (mpc8xxx_spi->flags & SPI_CPM_MODE)
ret = fsl_spi_cpm_bufs(mpc8xxx_spi, t, is_dma_mapped);
else
ret = fsl_spi_cpu_bufs(mpc8xxx_spi, t, len);
if (ret)
return ret;
wait_for_completion(&mpc8xxx_spi->done);
mpc8xxx_spi_write_reg(&reg_base->mask, 0);
if (mpc8xxx_spi->flags & SPI_CPM_MODE)
fsl_spi_cpm_bufs_complete(mpc8xxx_spi);
return mpc8xxx_spi->count;
}
static void fsl_spi_do_one_msg(struct spi_message *m)
{
struct spi_device *spi = m->spi;
struct spi_transfer *t;
unsigned int cs_change;
const int nsecs = 50;
int status;
cs_change = 1;
status = 0;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (t->bits_per_word || t->speed_hz) {
status = -EINVAL;
if (cs_change)
status = fsl_spi_setup_transfer(spi, t);
if (status < 0)
break;
}
if (cs_change) {
fsl_spi_chipselect(spi, BITBANG_CS_ACTIVE);
ndelay(nsecs);
}
cs_change = t->cs_change;
if (t->len)
status = fsl_spi_bufs(spi, t, m->is_dma_mapped);
if (status) {
status = -EMSGSIZE;
break;
}
m->actual_length += t->len;
if (t->delay_usecs)
udelay(t->delay_usecs);
if (cs_change) {
ndelay(nsecs);
fsl_spi_chipselect(spi, BITBANG_CS_INACTIVE);
ndelay(nsecs);
}
}
m->status = status;
m->complete(m->context);
if (status || !cs_change) {
ndelay(nsecs);
fsl_spi_chipselect(spi, BITBANG_CS_INACTIVE);
}
fsl_spi_setup_transfer(spi, NULL);
}
static int fsl_spi_setup(struct spi_device *spi)
{
struct mpc8xxx_spi *mpc8xxx_spi;
struct fsl_spi_reg *reg_base;
int retval;
u32 hw_mode;
struct spi_mpc8xxx_cs *cs = spi->controller_state;
if (!spi->max_speed_hz)
return -EINVAL;
if (!cs) {
cs = kzalloc(sizeof *cs, GFP_KERNEL);
if (!cs)
return -ENOMEM;
spi->controller_state = cs;
}
mpc8xxx_spi = spi_master_get_devdata(spi->master);
reg_base = mpc8xxx_spi->reg_base;
hw_mode = cs->hw_mode;
cs->hw_mode = mpc8xxx_spi_read_reg(&reg_base->mode);
cs->hw_mode &= ~(SPMODE_CP_BEGIN_EDGECLK | SPMODE_CI_INACTIVEHIGH
| SPMODE_REV | SPMODE_LOOP);
if (spi->mode & SPI_CPHA)
cs->hw_mode |= SPMODE_CP_BEGIN_EDGECLK;
if (spi->mode & SPI_CPOL)
cs->hw_mode |= SPMODE_CI_INACTIVEHIGH;
if (!(spi->mode & SPI_LSB_FIRST))
cs->hw_mode |= SPMODE_REV;
if (spi->mode & SPI_LOOP)
cs->hw_mode |= SPMODE_LOOP;
retval = fsl_spi_setup_transfer(spi, NULL);
if (retval < 0) {
cs->hw_mode = hw_mode;
return retval;
}
return 0;
}
static void fsl_spi_cpm_irq(struct mpc8xxx_spi *mspi, u32 events)
{
u16 len;
struct fsl_spi_reg *reg_base = mspi->reg_base;
dev_dbg(mspi->dev, "%s: bd datlen %d, count %d\n", __func__,
in_be16(&mspi->rx_bd->cbd_datlen), mspi->count);
len = in_be16(&mspi->rx_bd->cbd_datlen);
if (len > mspi->count) {
WARN_ON(1);
len = mspi->count;
}
mpc8xxx_spi_write_reg(&reg_base->event, events);
mspi->count -= len;
if (mspi->count)
fsl_spi_cpm_bufs_start(mspi);
else
complete(&mspi->done);
}
static void fsl_spi_cpu_irq(struct mpc8xxx_spi *mspi, u32 events)
{
struct fsl_spi_reg *reg_base = mspi->reg_base;
if (events & SPIE_NE) {
u32 rx_data = mpc8xxx_spi_read_reg(&reg_base->receive);
if (mspi->rx)
mspi->get_rx(rx_data, mspi);
}
if ((events & SPIE_NF) == 0)
while (((events =
mpc8xxx_spi_read_reg(&reg_base->event)) &
SPIE_NF) == 0)
cpu_relax();
mpc8xxx_spi_write_reg(&reg_base->event, events);
mspi->count -= 1;
if (mspi->count) {
u32 word = mspi->get_tx(mspi);
mpc8xxx_spi_write_reg(&reg_base->transmit, word);
} else {
complete(&mspi->done);
}
}
static irqreturn_t fsl_spi_irq(s32 irq, void *context_data)
{
struct mpc8xxx_spi *mspi = context_data;
irqreturn_t ret = IRQ_NONE;
u32 events;
struct fsl_spi_reg *reg_base = mspi->reg_base;
events = mpc8xxx_spi_read_reg(&reg_base->event);
if (events)
ret = IRQ_HANDLED;
dev_dbg(mspi->dev, "%s: events %x\n", __func__, events);
if (mspi->flags & SPI_CPM_MODE)
fsl_spi_cpm_irq(mspi, events);
else
fsl_spi_cpu_irq(mspi, events);
return ret;
}
static void *fsl_spi_alloc_dummy_rx(void)
{
mutex_lock(&fsl_dummy_rx_lock);
if (!fsl_dummy_rx)
fsl_dummy_rx = kmalloc(SPI_MRBLR, GFP_KERNEL);
if (fsl_dummy_rx)
fsl_dummy_rx_refcnt++;
mutex_unlock(&fsl_dummy_rx_lock);
return fsl_dummy_rx;
}
static void fsl_spi_free_dummy_rx(void)
{
mutex_lock(&fsl_dummy_rx_lock);
switch (fsl_dummy_rx_refcnt) {
case 0:
WARN_ON(1);
break;
case 1:
kfree(fsl_dummy_rx);
fsl_dummy_rx = NULL;
default:
fsl_dummy_rx_refcnt--;
break;
}
mutex_unlock(&fsl_dummy_rx_lock);
}
static unsigned long fsl_spi_cpm_get_pram(struct mpc8xxx_spi *mspi)
{
struct device *dev = mspi->dev;
struct device_node *np = dev->of_node;
const u32 *iprop;
int size;
void __iomem *spi_base;
unsigned long pram_ofs = -ENOMEM;
iprop = of_get_property(np, "reg", &size);
if (mspi->flags & SPI_QE && iprop && size == sizeof(*iprop) * 4)
return cpm_muram_alloc_fixed(iprop[2], SPI_PRAM_SIZE);
if (mspi->flags & SPI_QE) {
pram_ofs = cpm_muram_alloc(SPI_PRAM_SIZE, 64);
qe_issue_cmd(QE_ASSIGN_PAGE_TO_DEVICE, mspi->subblock,
QE_CR_PROTOCOL_UNSPECIFIED, pram_ofs);
return pram_ofs;
}
spi_base = of_iomap(np, 1);
if (spi_base == NULL)
return -EINVAL;
if (mspi->flags & SPI_CPM2) {
pram_ofs = cpm_muram_alloc(SPI_PRAM_SIZE, 64);
out_be16(spi_base, pram_ofs);
} else {
struct spi_pram __iomem *pram = spi_base;
u16 rpbase = in_be16(&pram->rpbase);
if (rpbase)
pram_ofs = rpbase;
else {
pram_ofs = cpm_muram_alloc(SPI_PRAM_SIZE, 64);
out_be16(spi_base, pram_ofs);
}
}
iounmap(spi_base);
return pram_ofs;
}
static int fsl_spi_cpm_init(struct mpc8xxx_spi *mspi)
{
struct device *dev = mspi->dev;
struct device_node *np = dev->of_node;
const u32 *iprop;
int size;
unsigned long pram_ofs;
unsigned long bds_ofs;
if (!(mspi->flags & SPI_CPM_MODE))
return 0;
if (!fsl_spi_alloc_dummy_rx())
return -ENOMEM;
if (mspi->flags & SPI_QE) {
iprop = of_get_property(np, "cell-index", &size);
if (iprop && size == sizeof(*iprop))
mspi->subblock = *iprop;
switch (mspi->subblock) {
default:
dev_warn(dev, "cell-index unspecified, assuming SPI1");
case 0:
mspi->subblock = QE_CR_SUBBLOCK_SPI1;
break;
case 1:
mspi->subblock = QE_CR_SUBBLOCK_SPI2;
break;
}
}
pram_ofs = fsl_spi_cpm_get_pram(mspi);
if (IS_ERR_VALUE(pram_ofs)) {
dev_err(dev, "can't allocate spi parameter ram\n");
goto err_pram;
}
bds_ofs = cpm_muram_alloc(sizeof(*mspi->tx_bd) +
sizeof(*mspi->rx_bd), 8);
if (IS_ERR_VALUE(bds_ofs)) {
dev_err(dev, "can't allocate bds\n");
goto err_bds;
}
mspi->dma_dummy_tx = dma_map_single(dev, empty_zero_page, PAGE_SIZE,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, mspi->dma_dummy_tx)) {
dev_err(dev, "unable to map dummy tx buffer\n");
goto err_dummy_tx;
}
mspi->dma_dummy_rx = dma_map_single(dev, fsl_dummy_rx, SPI_MRBLR,
DMA_FROM_DEVICE);
if (dma_mapping_error(dev, mspi->dma_dummy_rx)) {
dev_err(dev, "unable to map dummy rx buffer\n");
goto err_dummy_rx;
}
mspi->pram = cpm_muram_addr(pram_ofs);
mspi->tx_bd = cpm_muram_addr(bds_ofs);
mspi->rx_bd = cpm_muram_addr(bds_ofs + sizeof(*mspi->tx_bd));
out_be16(&mspi->pram->tbase, cpm_muram_offset(mspi->tx_bd));
out_be16(&mspi->pram->rbase, cpm_muram_offset(mspi->rx_bd));
out_8(&mspi->pram->tfcr, CPMFCR_EB | CPMFCR_GBL);
out_8(&mspi->pram->rfcr, CPMFCR_EB | CPMFCR_GBL);
out_be16(&mspi->pram->mrblr, SPI_MRBLR);
out_be32(&mspi->pram->rstate, 0);
out_be32(&mspi->pram->rdp, 0);
out_be16(&mspi->pram->rbptr, 0);
out_be16(&mspi->pram->rbc, 0);
out_be32(&mspi->pram->rxtmp, 0);
out_be32(&mspi->pram->tstate, 0);
out_be32(&mspi->pram->tdp, 0);
out_be16(&mspi->pram->tbptr, 0);
out_be16(&mspi->pram->tbc, 0);
out_be32(&mspi->pram->txtmp, 0);
return 0;
err_dummy_rx:
dma_unmap_single(dev, mspi->dma_dummy_tx, PAGE_SIZE, DMA_TO_DEVICE);
err_dummy_tx:
cpm_muram_free(bds_ofs);
err_bds:
cpm_muram_free(pram_ofs);
err_pram:
fsl_spi_free_dummy_rx();
return -ENOMEM;
}
static void fsl_spi_cpm_free(struct mpc8xxx_spi *mspi)
{
struct device *dev = mspi->dev;
if (!(mspi->flags & SPI_CPM_MODE))
return;
dma_unmap_single(dev, mspi->dma_dummy_rx, SPI_MRBLR, DMA_FROM_DEVICE);
dma_unmap_single(dev, mspi->dma_dummy_tx, PAGE_SIZE, DMA_TO_DEVICE);
cpm_muram_free(cpm_muram_offset(mspi->tx_bd));
cpm_muram_free(cpm_muram_offset(mspi->pram));
fsl_spi_free_dummy_rx();
}
static void fsl_spi_remove(struct mpc8xxx_spi *mspi)
{
iounmap(mspi->reg_base);
fsl_spi_cpm_free(mspi);
}
static struct spi_master * fsl_spi_probe(struct device *dev,
struct resource *mem, unsigned int irq)
{
struct fsl_spi_platform_data *pdata = dev->platform_data;
struct spi_master *master;
struct mpc8xxx_spi *mpc8xxx_spi;
struct fsl_spi_reg *reg_base;
u32 regval;
int ret = 0;
master = spi_alloc_master(dev, sizeof(struct mpc8xxx_spi));
if (master == NULL) {
ret = -ENOMEM;
goto err;
}
dev_set_drvdata(dev, master);
ret = mpc8xxx_spi_probe(dev, mem, irq);
if (ret)
goto err_probe;
master->setup = fsl_spi_setup;
mpc8xxx_spi = spi_master_get_devdata(master);
mpc8xxx_spi->spi_do_one_msg = fsl_spi_do_one_msg;
mpc8xxx_spi->spi_remove = fsl_spi_remove;
ret = fsl_spi_cpm_init(mpc8xxx_spi);
if (ret)
goto err_cpm_init;
if (mpc8xxx_spi->flags & SPI_QE_CPU_MODE) {
mpc8xxx_spi->rx_shift = 16;
mpc8xxx_spi->tx_shift = 24;
}
mpc8xxx_spi->reg_base = ioremap(mem->start, resource_size(mem));
if (mpc8xxx_spi->reg_base == NULL) {
ret = -ENOMEM;
goto err_ioremap;
}
ret = request_irq(mpc8xxx_spi->irq, fsl_spi_irq,
0, "fsl_spi", mpc8xxx_spi);
if (ret != 0)
goto free_irq;
reg_base = mpc8xxx_spi->reg_base;
mpc8xxx_spi_write_reg(&reg_base->mode, 0);
mpc8xxx_spi_write_reg(&reg_base->mask, 0);
mpc8xxx_spi_write_reg(&reg_base->command, 0);
mpc8xxx_spi_write_reg(&reg_base->event, 0xffffffff);
regval = pdata->initial_spmode | SPMODE_INIT_VAL | SPMODE_ENABLE;
if (mpc8xxx_spi->flags & SPI_QE_CPU_MODE)
regval |= SPMODE_OP;
mpc8xxx_spi_write_reg(&reg_base->mode, regval);
ret = spi_register_master(master);
if (ret < 0)
goto unreg_master;
dev_info(dev, "at 0x%p (irq = %d), %s mode\n", reg_base,
mpc8xxx_spi->irq, mpc8xxx_spi_strmode(mpc8xxx_spi->flags));
return master;
unreg_master:
free_irq(mpc8xxx_spi->irq, mpc8xxx_spi);
free_irq:
iounmap(mpc8xxx_spi->reg_base);
err_ioremap:
fsl_spi_cpm_free(mpc8xxx_spi);
err_cpm_init:
err_probe:
spi_master_put(master);
err:
return ERR_PTR(ret);
}
static void fsl_spi_cs_control(struct spi_device *spi, bool on)
{
struct device *dev = spi->dev.parent->parent;
struct mpc8xxx_spi_probe_info *pinfo = to_of_pinfo(dev->platform_data);
u16 cs = spi->chip_select;
int gpio = pinfo->gpios[cs];
bool alow = pinfo->alow_flags[cs];
gpio_set_value(gpio, on ^ alow);
}
static int of_fsl_spi_get_chipselects(struct device *dev)
{
struct device_node *np = dev->of_node;
struct fsl_spi_platform_data *pdata = dev->platform_data;
struct mpc8xxx_spi_probe_info *pinfo = to_of_pinfo(pdata);
int ngpios;
int i = 0;
int ret;
ngpios = of_gpio_count(np);
if (ngpios <= 0) {
pdata->max_chipselect = 1;
return 0;
}
pinfo->gpios = kmalloc(ngpios * sizeof(*pinfo->gpios), GFP_KERNEL);
if (!pinfo->gpios)
return -ENOMEM;
memset(pinfo->gpios, -1, ngpios * sizeof(*pinfo->gpios));
pinfo->alow_flags = kzalloc(ngpios * sizeof(*pinfo->alow_flags),
GFP_KERNEL);
if (!pinfo->alow_flags) {
ret = -ENOMEM;
goto err_alloc_flags;
}
for (; i < ngpios; i++) {
int gpio;
enum of_gpio_flags flags;
gpio = of_get_gpio_flags(np, i, &flags);
if (!gpio_is_valid(gpio)) {
dev_err(dev, "invalid gpio #%d: %d\n", i, gpio);
ret = gpio;
goto err_loop;
}
ret = gpio_request(gpio, dev_name(dev));
if (ret) {
dev_err(dev, "can't request gpio #%d: %d\n", i, ret);
goto err_loop;
}
pinfo->gpios[i] = gpio;
pinfo->alow_flags[i] = flags & OF_GPIO_ACTIVE_LOW;
ret = gpio_direction_output(pinfo->gpios[i],
pinfo->alow_flags[i]);
if (ret) {
dev_err(dev, "can't set output direction for gpio "
"#%d: %d\n", i, ret);
goto err_loop;
}
}
pdata->max_chipselect = ngpios;
pdata->cs_control = fsl_spi_cs_control;
return 0;
err_loop:
while (i >= 0) {
if (gpio_is_valid(pinfo->gpios[i]))
gpio_free(pinfo->gpios[i]);
i--;
}
kfree(pinfo->alow_flags);
pinfo->alow_flags = NULL;
err_alloc_flags:
kfree(pinfo->gpios);
pinfo->gpios = NULL;
return ret;
}
static int of_fsl_spi_free_chipselects(struct device *dev)
{
struct fsl_spi_platform_data *pdata = dev->platform_data;
struct mpc8xxx_spi_probe_info *pinfo = to_of_pinfo(pdata);
int i;
if (!pinfo->gpios)
return 0;
for (i = 0; i < pdata->max_chipselect; i++) {
if (gpio_is_valid(pinfo->gpios[i]))
gpio_free(pinfo->gpios[i]);
}
kfree(pinfo->gpios);
kfree(pinfo->alow_flags);
return 0;
}
static int of_fsl_spi_probe(struct platform_device *ofdev)
{
struct device *dev = &ofdev->dev;
struct device_node *np = ofdev->dev.of_node;
struct spi_master *master;
struct resource mem;
struct resource irq;
int ret = -ENOMEM;
ret = of_mpc8xxx_spi_probe(ofdev);
if (ret)
return ret;
ret = of_fsl_spi_get_chipselects(dev);
if (ret)
goto err;
ret = of_address_to_resource(np, 0, &mem);
if (ret)
goto err;
ret = of_irq_to_resource(np, 0, &irq);
if (!ret) {
ret = -EINVAL;
goto err;
}
master = fsl_spi_probe(dev, &mem, irq.start);
if (IS_ERR(master)) {
ret = PTR_ERR(master);
goto err;
}
return 0;
err:
of_fsl_spi_free_chipselects(dev);
return ret;
}
static int of_fsl_spi_remove(struct platform_device *ofdev)
{
int ret;
ret = mpc8xxx_spi_remove(&ofdev->dev);
if (ret)
return ret;
of_fsl_spi_free_chipselects(&ofdev->dev);
return 0;
}
static int plat_mpc8xxx_spi_probe(struct platform_device *pdev)
{
struct resource *mem;
int irq;
struct spi_master *master;
if (!pdev->dev.platform_data)
return -EINVAL;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return -EINVAL;
master = fsl_spi_probe(&pdev->dev, mem, irq);
if (IS_ERR(master))
return PTR_ERR(master);
return 0;
}
static int plat_mpc8xxx_spi_remove(struct platform_device *pdev)
{
return mpc8xxx_spi_remove(&pdev->dev);
}
static void __init legacy_driver_register(void)
{
legacy_driver_failed = platform_driver_register(&mpc8xxx_spi_driver);
}
static void __exit legacy_driver_unregister(void)
{
if (legacy_driver_failed)
return;
platform_driver_unregister(&mpc8xxx_spi_driver);
}
static void __init legacy_driver_register(void) {}
static void __exit legacy_driver_unregister(void) {}
static int __init fsl_spi_init(void)
{
legacy_driver_register();
return platform_driver_register(&of_fsl_spi_driver);
}
static void __exit fsl_spi_exit(void)
{
platform_driver_unregister(&of_fsl_spi_driver);
legacy_driver_unregister();
}
