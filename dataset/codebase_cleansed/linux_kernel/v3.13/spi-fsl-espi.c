static void fsl_espi_change_mode(struct spi_device *spi)
{
struct mpc8xxx_spi *mspi = spi_master_get_devdata(spi->master);
struct spi_mpc8xxx_cs *cs = spi->controller_state;
struct fsl_espi_reg *reg_base = mspi->reg_base;
__be32 __iomem *mode = &reg_base->csmode[spi->chip_select];
__be32 __iomem *espi_mode = &reg_base->mode;
u32 tmp;
unsigned long flags;
local_irq_save(flags);
tmp = mpc8xxx_spi_read_reg(espi_mode);
mpc8xxx_spi_write_reg(espi_mode, tmp & ~SPMODE_ENABLE);
mpc8xxx_spi_write_reg(mode, cs->hw_mode);
mpc8xxx_spi_write_reg(espi_mode, tmp);
local_irq_restore(flags);
}
static u32 fsl_espi_tx_buf_lsb(struct mpc8xxx_spi *mpc8xxx_spi)
{
u32 data;
u16 data_h;
u16 data_l;
const u32 *tx = mpc8xxx_spi->tx;
if (!tx)
return 0;
data = *tx++ << mpc8xxx_spi->tx_shift;
data_l = data & 0xffff;
data_h = (data >> 16) & 0xffff;
swab16s(&data_l);
swab16s(&data_h);
data = data_h | data_l;
mpc8xxx_spi->tx = tx;
return data;
}
static int fsl_espi_setup_transfer(struct spi_device *spi,
struct spi_transfer *t)
{
struct mpc8xxx_spi *mpc8xxx_spi = spi_master_get_devdata(spi->master);
int bits_per_word = 0;
u8 pm;
u32 hz = 0;
struct spi_mpc8xxx_cs *cs = spi->controller_state;
if (t) {
bits_per_word = t->bits_per_word;
hz = t->speed_hz;
}
if (!bits_per_word)
bits_per_word = spi->bits_per_word;
if (!hz)
hz = spi->max_speed_hz;
cs->rx_shift = 0;
cs->tx_shift = 0;
cs->get_rx = mpc8xxx_spi_rx_buf_u32;
cs->get_tx = mpc8xxx_spi_tx_buf_u32;
if (bits_per_word <= 8) {
cs->rx_shift = 8 - bits_per_word;
} else {
cs->rx_shift = 16 - bits_per_word;
if (spi->mode & SPI_LSB_FIRST)
cs->get_tx = fsl_espi_tx_buf_lsb;
}
mpc8xxx_spi->rx_shift = cs->rx_shift;
mpc8xxx_spi->tx_shift = cs->tx_shift;
mpc8xxx_spi->get_rx = cs->get_rx;
mpc8xxx_spi->get_tx = cs->get_tx;
bits_per_word = bits_per_word - 1;
cs->hw_mode &= ~(CSMODE_LEN(0xF) | CSMODE_DIV16 | CSMODE_PM(0xF));
cs->hw_mode |= CSMODE_LEN(bits_per_word);
if ((mpc8xxx_spi->spibrg / hz) > 64) {
cs->hw_mode |= CSMODE_DIV16;
pm = DIV_ROUND_UP(mpc8xxx_spi->spibrg, hz * 16 * 4);
WARN_ONCE(pm > 33, "%s: Requested speed is too low: %d Hz. "
"Will use %d Hz instead.\n", dev_name(&spi->dev),
hz, mpc8xxx_spi->spibrg / (4 * 16 * (32 + 1)));
if (pm > 33)
pm = 33;
} else {
pm = DIV_ROUND_UP(mpc8xxx_spi->spibrg, hz * 4);
}
if (pm)
pm--;
if (pm < 2)
pm = 2;
cs->hw_mode |= CSMODE_PM(pm);
fsl_espi_change_mode(spi);
return 0;
}
static int fsl_espi_cpu_bufs(struct mpc8xxx_spi *mspi, struct spi_transfer *t,
unsigned int len)
{
u32 word;
struct fsl_espi_reg *reg_base = mspi->reg_base;
mspi->count = len;
mpc8xxx_spi_write_reg(&reg_base->mask, SPIM_NE);
word = mspi->get_tx(mspi);
mpc8xxx_spi_write_reg(&reg_base->transmit, word);
return 0;
}
static int fsl_espi_bufs(struct spi_device *spi, struct spi_transfer *t)
{
struct mpc8xxx_spi *mpc8xxx_spi = spi_master_get_devdata(spi->master);
struct fsl_espi_reg *reg_base = mpc8xxx_spi->reg_base;
unsigned int len = t->len;
u8 bits_per_word;
int ret;
bits_per_word = spi->bits_per_word;
if (t->bits_per_word)
bits_per_word = t->bits_per_word;
mpc8xxx_spi->len = t->len;
len = roundup(len, 4) / 4;
mpc8xxx_spi->tx = t->tx_buf;
mpc8xxx_spi->rx = t->rx_buf;
reinit_completion(&mpc8xxx_spi->done);
if ((t->len - 1) > SPCOM_TRANLEN_MAX) {
dev_err(mpc8xxx_spi->dev, "Transaction length (%d)"
" beyond the SPCOM[TRANLEN] field\n", t->len);
return -EINVAL;
}
mpc8xxx_spi_write_reg(&reg_base->command,
(SPCOM_CS(spi->chip_select) | SPCOM_TRANLEN(t->len - 1)));
ret = fsl_espi_cpu_bufs(mpc8xxx_spi, t, len);
if (ret)
return ret;
wait_for_completion(&mpc8xxx_spi->done);
mpc8xxx_spi_write_reg(&reg_base->mask, 0);
return mpc8xxx_spi->count;
}
static inline void fsl_espi_addr2cmd(unsigned int addr, u8 *cmd)
{
if (cmd) {
cmd[1] = (u8)(addr >> 16);
cmd[2] = (u8)(addr >> 8);
cmd[3] = (u8)(addr >> 0);
}
}
static inline unsigned int fsl_espi_cmd2addr(u8 *cmd)
{
if (cmd)
return cmd[1] << 16 | cmd[2] << 8 | cmd[3] << 0;
return 0;
}
static void fsl_espi_do_trans(struct spi_message *m,
struct fsl_espi_transfer *tr)
{
struct spi_device *spi = m->spi;
struct mpc8xxx_spi *mspi = spi_master_get_devdata(spi->master);
struct fsl_espi_transfer *espi_trans = tr;
struct spi_message message;
struct spi_transfer *t, *first, trans;
int status = 0;
spi_message_init(&message);
memset(&trans, 0, sizeof(trans));
first = list_first_entry(&m->transfers, struct spi_transfer,
transfer_list);
list_for_each_entry(t, &m->transfers, transfer_list) {
if ((first->bits_per_word != t->bits_per_word) ||
(first->speed_hz != t->speed_hz)) {
espi_trans->status = -EINVAL;
dev_err(mspi->dev,
"bits_per_word/speed_hz should be same for the same SPI transfer\n");
return;
}
trans.speed_hz = t->speed_hz;
trans.bits_per_word = t->bits_per_word;
trans.delay_usecs = max(first->delay_usecs, t->delay_usecs);
}
trans.len = espi_trans->len;
trans.tx_buf = espi_trans->tx_buf;
trans.rx_buf = espi_trans->rx_buf;
spi_message_add_tail(&trans, &message);
list_for_each_entry(t, &message.transfers, transfer_list) {
if (t->bits_per_word || t->speed_hz) {
status = -EINVAL;
status = fsl_espi_setup_transfer(spi, t);
if (status < 0)
break;
}
if (t->len)
status = fsl_espi_bufs(spi, t);
if (status) {
status = -EMSGSIZE;
break;
}
if (t->delay_usecs)
udelay(t->delay_usecs);
}
espi_trans->status = status;
fsl_espi_setup_transfer(spi, NULL);
}
static void fsl_espi_cmd_trans(struct spi_message *m,
struct fsl_espi_transfer *trans, u8 *rx_buff)
{
struct spi_transfer *t;
u8 *local_buf;
int i = 0;
struct fsl_espi_transfer *espi_trans = trans;
local_buf = kzalloc(SPCOM_TRANLEN_MAX, GFP_KERNEL);
if (!local_buf) {
espi_trans->status = -ENOMEM;
return;
}
list_for_each_entry(t, &m->transfers, transfer_list) {
if (t->tx_buf) {
memcpy(local_buf + i, t->tx_buf, t->len);
i += t->len;
}
}
espi_trans->tx_buf = local_buf;
espi_trans->rx_buf = local_buf + espi_trans->n_tx;
fsl_espi_do_trans(m, espi_trans);
espi_trans->actual_length = espi_trans->len;
kfree(local_buf);
}
static void fsl_espi_rw_trans(struct spi_message *m,
struct fsl_espi_transfer *trans, u8 *rx_buff)
{
struct fsl_espi_transfer *espi_trans = trans;
unsigned int n_tx = espi_trans->n_tx;
unsigned int n_rx = espi_trans->n_rx;
struct spi_transfer *t;
u8 *local_buf;
u8 *rx_buf = rx_buff;
unsigned int trans_len;
unsigned int addr;
int i, pos, loop;
local_buf = kzalloc(SPCOM_TRANLEN_MAX, GFP_KERNEL);
if (!local_buf) {
espi_trans->status = -ENOMEM;
return;
}
for (pos = 0, loop = 0; pos < n_rx; pos += trans_len, loop++) {
trans_len = n_rx - pos;
if (trans_len > SPCOM_TRANLEN_MAX - n_tx)
trans_len = SPCOM_TRANLEN_MAX - n_tx;
i = 0;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (t->tx_buf) {
memcpy(local_buf + i, t->tx_buf, t->len);
i += t->len;
}
}
if (pos > 0) {
addr = fsl_espi_cmd2addr(local_buf);
addr += pos;
fsl_espi_addr2cmd(addr, local_buf);
}
espi_trans->n_tx = n_tx;
espi_trans->n_rx = trans_len;
espi_trans->len = trans_len + n_tx;
espi_trans->tx_buf = local_buf;
espi_trans->rx_buf = local_buf + n_tx;
fsl_espi_do_trans(m, espi_trans);
memcpy(rx_buf + pos, espi_trans->rx_buf + n_tx, trans_len);
if (loop > 0)
espi_trans->actual_length += espi_trans->len - n_tx;
else
espi_trans->actual_length += espi_trans->len;
}
kfree(local_buf);
}
static void fsl_espi_do_one_msg(struct spi_message *m)
{
struct spi_transfer *t;
u8 *rx_buf = NULL;
unsigned int n_tx = 0;
unsigned int n_rx = 0;
struct fsl_espi_transfer espi_trans;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (t->tx_buf)
n_tx += t->len;
if (t->rx_buf) {
n_rx += t->len;
rx_buf = t->rx_buf;
}
}
espi_trans.n_tx = n_tx;
espi_trans.n_rx = n_rx;
espi_trans.len = n_tx + n_rx;
espi_trans.actual_length = 0;
espi_trans.status = 0;
if (!rx_buf)
fsl_espi_cmd_trans(m, &espi_trans, NULL);
else
fsl_espi_rw_trans(m, &espi_trans, rx_buf);
m->actual_length = espi_trans.actual_length;
m->status = espi_trans.status;
m->complete(m->context);
}
static int fsl_espi_setup(struct spi_device *spi)
{
struct mpc8xxx_spi *mpc8xxx_spi;
struct fsl_espi_reg *reg_base;
int retval;
u32 hw_mode;
u32 loop_mode;
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
cs->hw_mode = mpc8xxx_spi_read_reg(
&reg_base->csmode[spi->chip_select]);
cs->hw_mode &= ~(CSMODE_CP_BEGIN_EDGECLK | CSMODE_CI_INACTIVEHIGH
| CSMODE_REV);
if (spi->mode & SPI_CPHA)
cs->hw_mode |= CSMODE_CP_BEGIN_EDGECLK;
if (spi->mode & SPI_CPOL)
cs->hw_mode |= CSMODE_CI_INACTIVEHIGH;
if (!(spi->mode & SPI_LSB_FIRST))
cs->hw_mode |= CSMODE_REV;
loop_mode = mpc8xxx_spi_read_reg(&reg_base->mode);
loop_mode &= ~SPMODE_LOOP;
if (spi->mode & SPI_LOOP)
loop_mode |= SPMODE_LOOP;
mpc8xxx_spi_write_reg(&reg_base->mode, loop_mode);
retval = fsl_espi_setup_transfer(spi, NULL);
if (retval < 0) {
cs->hw_mode = hw_mode;
return retval;
}
return 0;
}
void fsl_espi_cpu_irq(struct mpc8xxx_spi *mspi, u32 events)
{
struct fsl_espi_reg *reg_base = mspi->reg_base;
if (events & SPIE_NE) {
u32 rx_data, tmp;
u8 rx_data_8;
while (SPIE_RXCNT(events) < min(4, mspi->len)) {
cpu_relax();
events = mpc8xxx_spi_read_reg(&reg_base->event);
}
if (mspi->len >= 4) {
rx_data = mpc8xxx_spi_read_reg(&reg_base->receive);
} else {
tmp = mspi->len;
rx_data = 0;
while (tmp--) {
rx_data_8 = in_8((u8 *)&reg_base->receive);
rx_data |= (rx_data_8 << (tmp * 8));
}
rx_data <<= (4 - mspi->len) * 8;
}
mspi->len -= 4;
if (mspi->rx)
mspi->get_rx(rx_data, mspi);
}
if (!(events & SPIE_NF)) {
int ret;
ret = spin_event_timeout(((events = mpc8xxx_spi_read_reg(
&reg_base->event)) & SPIE_NF) == 0, 1000, 0);
if (!ret) {
dev_err(mspi->dev, "tired waiting for SPIE_NF\n");
return;
}
}
mpc8xxx_spi_write_reg(&reg_base->event, events);
mspi->count -= 1;
if (mspi->count) {
u32 word = mspi->get_tx(mspi);
mpc8xxx_spi_write_reg(&reg_base->transmit, word);
} else {
complete(&mspi->done);
}
}
static irqreturn_t fsl_espi_irq(s32 irq, void *context_data)
{
struct mpc8xxx_spi *mspi = context_data;
struct fsl_espi_reg *reg_base = mspi->reg_base;
irqreturn_t ret = IRQ_NONE;
u32 events;
events = mpc8xxx_spi_read_reg(&reg_base->event);
if (events)
ret = IRQ_HANDLED;
dev_vdbg(mspi->dev, "%s: events %x\n", __func__, events);
fsl_espi_cpu_irq(mspi, events);
return ret;
}
static void fsl_espi_remove(struct mpc8xxx_spi *mspi)
{
iounmap(mspi->reg_base);
}
static struct spi_master * fsl_espi_probe(struct device *dev,
struct resource *mem, unsigned int irq)
{
struct fsl_spi_platform_data *pdata = dev_get_platdata(dev);
struct spi_master *master;
struct mpc8xxx_spi *mpc8xxx_spi;
struct fsl_espi_reg *reg_base;
u32 regval;
int i, ret = 0;
master = spi_alloc_master(dev, sizeof(struct mpc8xxx_spi));
if (!master) {
ret = -ENOMEM;
goto err;
}
dev_set_drvdata(dev, master);
ret = mpc8xxx_spi_probe(dev, mem, irq);
if (ret)
goto err_probe;
master->bits_per_word_mask = SPI_BPW_RANGE_MASK(4, 16);
master->setup = fsl_espi_setup;
mpc8xxx_spi = spi_master_get_devdata(master);
mpc8xxx_spi->spi_do_one_msg = fsl_espi_do_one_msg;
mpc8xxx_spi->spi_remove = fsl_espi_remove;
mpc8xxx_spi->reg_base = ioremap(mem->start, resource_size(mem));
if (!mpc8xxx_spi->reg_base) {
ret = -ENOMEM;
goto err_probe;
}
reg_base = mpc8xxx_spi->reg_base;
ret = request_irq(mpc8xxx_spi->irq, fsl_espi_irq,
0, "fsl_espi", mpc8xxx_spi);
if (ret)
goto free_irq;
if (mpc8xxx_spi->flags & SPI_QE_CPU_MODE) {
mpc8xxx_spi->rx_shift = 16;
mpc8xxx_spi->tx_shift = 24;
}
mpc8xxx_spi_write_reg(&reg_base->mode, 0);
mpc8xxx_spi_write_reg(&reg_base->mask, 0);
mpc8xxx_spi_write_reg(&reg_base->command, 0);
mpc8xxx_spi_write_reg(&reg_base->event, 0xffffffff);
for (i = 0; i < pdata->max_chipselect; i++)
mpc8xxx_spi_write_reg(&reg_base->csmode[i], CSMODE_INIT_VAL);
regval = pdata->initial_spmode | SPMODE_INIT_VAL | SPMODE_ENABLE;
mpc8xxx_spi_write_reg(&reg_base->mode, regval);
ret = spi_register_master(master);
if (ret < 0)
goto unreg_master;
dev_info(dev, "at 0x%p (irq = %d)\n", reg_base, mpc8xxx_spi->irq);
return master;
unreg_master:
free_irq(mpc8xxx_spi->irq, mpc8xxx_spi);
free_irq:
iounmap(mpc8xxx_spi->reg_base);
err_probe:
spi_master_put(master);
err:
return ERR_PTR(ret);
}
static int of_fsl_espi_get_chipselects(struct device *dev)
{
struct device_node *np = dev->of_node;
struct fsl_spi_platform_data *pdata = dev_get_platdata(dev);
const u32 *prop;
int len;
prop = of_get_property(np, "fsl,espi-num-chipselects", &len);
if (!prop || len < sizeof(*prop)) {
dev_err(dev, "No 'fsl,espi-num-chipselects' property\n");
return -EINVAL;
}
pdata->max_chipselect = *prop;
pdata->cs_control = NULL;
return 0;
}
static int of_fsl_espi_probe(struct platform_device *ofdev)
{
struct device *dev = &ofdev->dev;
struct device_node *np = ofdev->dev.of_node;
struct spi_master *master;
struct resource mem;
unsigned int irq;
int ret = -ENOMEM;
ret = of_mpc8xxx_spi_probe(ofdev);
if (ret)
return ret;
ret = of_fsl_espi_get_chipselects(dev);
if (ret)
goto err;
ret = of_address_to_resource(np, 0, &mem);
if (ret)
goto err;
irq = irq_of_parse_and_map(np, 0);
if (!ret) {
ret = -EINVAL;
goto err;
}
master = fsl_espi_probe(dev, &mem, irq);
if (IS_ERR(master)) {
ret = PTR_ERR(master);
goto err;
}
return 0;
err:
return ret;
}
static int of_fsl_espi_remove(struct platform_device *dev)
{
return mpc8xxx_spi_remove(&dev->dev);
}
