static int fsl_spi_get_type(struct device *dev)
{
const struct of_device_id *match;
if (dev->of_node) {
match = of_match_node(of_fsl_spi_match, dev->of_node);
if (match && match->data)
return ((struct fsl_spi_match_data *)match->data)->type;
}
return TYPE_FSL;
}
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
fsl_spi_cpm_reinit_txrx(mspi);
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
static void fsl_spi_qe_cpu_set_shifts(u32 *rx_shift, u32 *tx_shift,
int bits_per_word, int msb_first)
{
*rx_shift = 0;
*tx_shift = 0;
if (msb_first) {
if (bits_per_word <= 8) {
*rx_shift = 16;
*tx_shift = 24;
} else if (bits_per_word <= 16) {
*rx_shift = 16;
*tx_shift = 16;
}
} else {
if (bits_per_word <= 8)
*rx_shift = 8;
}
}
static void fsl_spi_grlib_set_shifts(u32 *rx_shift, u32 *tx_shift,
int bits_per_word, int msb_first)
{
*rx_shift = 0;
*tx_shift = 0;
if (bits_per_word <= 16) {
if (msb_first) {
*rx_shift = 16;
*tx_shift = 32 - bits_per_word;
} else {
*rx_shift = 16 - bits_per_word;
}
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
} else if (bits_per_word <= 16) {
cs->get_rx = mpc8xxx_spi_rx_buf_u16;
cs->get_tx = mpc8xxx_spi_tx_buf_u16;
} else if (bits_per_word <= 32) {
cs->get_rx = mpc8xxx_spi_rx_buf_u32;
cs->get_tx = mpc8xxx_spi_tx_buf_u32;
} else
return -EINVAL;
if (mpc8xxx_spi->set_shifts)
mpc8xxx_spi->set_shifts(&cs->rx_shift, &cs->tx_shift,
bits_per_word,
!(spi->mode & SPI_LSB_FIRST));
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
reinit_completion(&mpc8xxx_spi->done);
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
struct spi_transfer *t, *first;
unsigned int cs_change;
const int nsecs = 50;
int status;
first = list_first_entry(&m->transfers, struct spi_transfer,
transfer_list);
list_for_each_entry(t, &m->transfers, transfer_list) {
if ((first->bits_per_word != t->bits_per_word) ||
(first->speed_hz != t->speed_hz)) {
status = -EINVAL;
dev_err(&spi->dev,
"bits_per_word/speed_hz should be same for the same SPI transfer\n");
return;
}
}
cs_change = 1;
status = -EINVAL;
list_for_each_entry(t, &m->transfers, transfer_list) {
if (t->bits_per_word || t->speed_hz) {
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
if (m->complete)
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
cs = devm_kzalloc(&spi->dev, sizeof(*cs), GFP_KERNEL);
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
if (mpc8xxx_spi->type == TYPE_GRLIB) {
if (gpio_is_valid(spi->cs_gpio)) {
int desel;
retval = gpio_request(spi->cs_gpio,
dev_name(&spi->dev));
if (retval)
return retval;
desel = !(spi->mode & SPI_CS_HIGH);
retval = gpio_direction_output(spi->cs_gpio, desel);
if (retval) {
gpio_free(spi->cs_gpio);
return retval;
}
} else if (spi->cs_gpio != -ENOENT) {
if (spi->cs_gpio < 0)
return spi->cs_gpio;
return -EINVAL;
}
}
fsl_spi_chipselect(spi, BITBANG_CS_INACTIVE);
return 0;
}
static void fsl_spi_cleanup(struct spi_device *spi)
{
struct mpc8xxx_spi *mpc8xxx_spi = spi_master_get_devdata(spi->master);
if (mpc8xxx_spi->type == TYPE_GRLIB && gpio_is_valid(spi->cs_gpio))
gpio_free(spi->cs_gpio);
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
static void fsl_spi_remove(struct mpc8xxx_spi *mspi)
{
iounmap(mspi->reg_base);
fsl_spi_cpm_free(mspi);
}
static void fsl_spi_grlib_cs_control(struct spi_device *spi, bool on)
{
struct mpc8xxx_spi *mpc8xxx_spi = spi_master_get_devdata(spi->master);
struct fsl_spi_reg *reg_base = mpc8xxx_spi->reg_base;
u32 slvsel;
u16 cs = spi->chip_select;
if (gpio_is_valid(spi->cs_gpio)) {
gpio_set_value(spi->cs_gpio, on);
} else if (cs < mpc8xxx_spi->native_chipselects) {
slvsel = mpc8xxx_spi_read_reg(&reg_base->slvsel);
slvsel = on ? (slvsel | (1 << cs)) : (slvsel & ~(1 << cs));
mpc8xxx_spi_write_reg(&reg_base->slvsel, slvsel);
}
}
static void fsl_spi_grlib_probe(struct device *dev)
{
struct fsl_spi_platform_data *pdata = dev_get_platdata(dev);
struct spi_master *master = dev_get_drvdata(dev);
struct mpc8xxx_spi *mpc8xxx_spi = spi_master_get_devdata(master);
struct fsl_spi_reg *reg_base = mpc8xxx_spi->reg_base;
int mbits;
u32 capabilities;
capabilities = mpc8xxx_spi_read_reg(&reg_base->cap);
mpc8xxx_spi->set_shifts = fsl_spi_grlib_set_shifts;
mbits = SPCAP_MAXWLEN(capabilities);
if (mbits)
mpc8xxx_spi->max_bits_per_word = mbits + 1;
mpc8xxx_spi->native_chipselects = 0;
if (SPCAP_SSEN(capabilities)) {
mpc8xxx_spi->native_chipselects = SPCAP_SSSZ(capabilities);
mpc8xxx_spi_write_reg(&reg_base->slvsel, 0xffffffff);
}
master->num_chipselect = mpc8xxx_spi->native_chipselects;
pdata->cs_control = fsl_spi_grlib_cs_control;
}
static struct spi_master * fsl_spi_probe(struct device *dev,
struct resource *mem, unsigned int irq)
{
struct fsl_spi_platform_data *pdata = dev_get_platdata(dev);
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
master->cleanup = fsl_spi_cleanup;
mpc8xxx_spi = spi_master_get_devdata(master);
mpc8xxx_spi->spi_do_one_msg = fsl_spi_do_one_msg;
mpc8xxx_spi->spi_remove = fsl_spi_remove;
mpc8xxx_spi->max_bits_per_word = 32;
mpc8xxx_spi->type = fsl_spi_get_type(dev);
ret = fsl_spi_cpm_init(mpc8xxx_spi);
if (ret)
goto err_cpm_init;
mpc8xxx_spi->reg_base = ioremap(mem->start, resource_size(mem));
if (mpc8xxx_spi->reg_base == NULL) {
ret = -ENOMEM;
goto err_ioremap;
}
if (mpc8xxx_spi->type == TYPE_GRLIB)
fsl_spi_grlib_probe(dev);
master->bits_per_word_mask =
(SPI_BPW_RANGE_MASK(4, 16) | SPI_BPW_MASK(32)) &
SPI_BPW_RANGE_MASK(1, mpc8xxx_spi->max_bits_per_word);
if (mpc8xxx_spi->flags & SPI_QE_CPU_MODE)
mpc8xxx_spi->set_shifts = fsl_spi_qe_cpu_set_shifts;
if (mpc8xxx_spi->set_shifts)
mpc8xxx_spi->set_shifts(&mpc8xxx_spi->rx_shift,
&mpc8xxx_spi->tx_shift, 8, 1);
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
if (mpc8xxx_spi->max_bits_per_word < 8) {
regval &= ~SPMODE_LEN(0xF);
regval |= SPMODE_LEN(mpc8xxx_spi->max_bits_per_word - 1);
}
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
struct fsl_spi_platform_data *pdata = dev_get_platdata(dev);
struct mpc8xxx_spi_probe_info *pinfo = to_of_pinfo(pdata);
u16 cs = spi->chip_select;
int gpio = pinfo->gpios[cs];
bool alow = pinfo->alow_flags[cs];
gpio_set_value(gpio, on ^ alow);
}
static int of_fsl_spi_get_chipselects(struct device *dev)
{
struct device_node *np = dev->of_node;
struct fsl_spi_platform_data *pdata = dev_get_platdata(dev);
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
struct fsl_spi_platform_data *pdata = dev_get_platdata(dev);
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
int irq, type;
int ret = -ENOMEM;
ret = of_mpc8xxx_spi_probe(ofdev);
if (ret)
return ret;
type = fsl_spi_get_type(&ofdev->dev);
if (type == TYPE_FSL) {
ret = of_fsl_spi_get_chipselects(dev);
if (ret)
goto err;
}
ret = of_address_to_resource(np, 0, &mem);
if (ret)
goto err;
irq = irq_of_parse_and_map(np, 0);
if (!irq) {
ret = -EINVAL;
goto err;
}
master = fsl_spi_probe(dev, &mem, irq);
if (IS_ERR(master)) {
ret = PTR_ERR(master);
goto err;
}
return 0;
err:
if (type == TYPE_FSL)
of_fsl_spi_free_chipselects(dev);
return ret;
}
static int of_fsl_spi_remove(struct platform_device *ofdev)
{
struct spi_master *master = platform_get_drvdata(ofdev);
struct mpc8xxx_spi *mpc8xxx_spi = spi_master_get_devdata(master);
int ret;
ret = mpc8xxx_spi_remove(&ofdev->dev);
if (ret)
return ret;
if (mpc8xxx_spi->type == TYPE_FSL)
of_fsl_spi_free_chipselects(&ofdev->dev);
return 0;
}
static int plat_mpc8xxx_spi_probe(struct platform_device *pdev)
{
struct resource *mem;
int irq;
struct spi_master *master;
if (!dev_get_platdata(&pdev->dev))
return -EINVAL;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return -EINVAL;
master = fsl_spi_probe(&pdev->dev, mem, irq);
return PTR_ERR_OR_ZERO(master);
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
