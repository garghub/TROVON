static int cpcap_check_revision(struct cpcap_ddata *cpcap)
{
u16 vendor, rev;
int ret;
ret = cpcap_get_vendor(&cpcap->spi->dev, cpcap->regmap, &vendor);
if (ret)
return ret;
ret = cpcap_get_revision(&cpcap->spi->dev, cpcap->regmap, &rev);
if (ret)
return ret;
dev_info(&cpcap->spi->dev, "CPCAP vendor: %s rev: %i.%i (%x)\n",
vendor == CPCAP_VENDOR_ST ? "ST" : "TI",
CPCAP_REVISION_MAJOR(rev), CPCAP_REVISION_MINOR(rev),
rev);
if (rev < CPCAP_REVISION_2_1) {
dev_info(&cpcap->spi->dev,
"Please add old CPCAP revision support as needed\n");
return -ENODEV;
}
return 0;
}
static void cpcap_init_one_regmap_irq(struct cpcap_ddata *cpcap,
struct regmap_irq *rirq,
int irq_base, int irq)
{
unsigned int reg_offset;
unsigned int bit, mask;
reg_offset = irq - irq_base;
reg_offset /= cpcap->regmap_conf->val_bits;
reg_offset *= cpcap->regmap_conf->reg_stride;
bit = irq % cpcap->regmap_conf->val_bits;
mask = (1 << bit);
rirq->reg_offset = reg_offset;
rirq->mask = mask;
}
static int cpcap_init_irq_chip(struct cpcap_ddata *cpcap, int irq_chip,
int irq_start, int nr_irqs)
{
struct regmap_irq_chip *chip = &cpcap_irq_chip[irq_chip];
int i, ret;
for (i = irq_start; i < irq_start + nr_irqs; i++) {
struct regmap_irq *rirq = &cpcap->irqs[i];
cpcap_init_one_regmap_irq(cpcap, rirq, irq_start, i);
}
chip->irqs = &cpcap->irqs[irq_start];
chip->num_irqs = nr_irqs;
chip->irq_drv_data = cpcap;
ret = devm_regmap_add_irq_chip(&cpcap->spi->dev, cpcap->regmap,
cpcap->spi->irq,
IRQF_TRIGGER_RISING |
IRQF_SHARED, -1,
chip, &cpcap->irqdata[irq_chip]);
if (ret) {
dev_err(&cpcap->spi->dev, "could not add irq chip %i: %i\n",
irq_chip, ret);
return ret;
}
return 0;
}
static int cpcap_init_irq(struct cpcap_ddata *cpcap)
{
int ret;
cpcap->irqs = devm_kzalloc(&cpcap->spi->dev,
sizeof(*cpcap->irqs) *
CPCAP_NR_IRQ_REG_BANKS *
cpcap->regmap_conf->val_bits,
GFP_KERNEL);
if (!cpcap->irqs)
return -ENOMEM;
ret = cpcap_init_irq_chip(cpcap, 0, 0, 16);
if (ret)
return ret;
ret = cpcap_init_irq_chip(cpcap, 1, 16, 16);
if (ret)
return ret;
ret = cpcap_init_irq_chip(cpcap, 2, 32, 64);
if (ret)
return ret;
enable_irq_wake(cpcap->spi->irq);
return 0;
}
static int cpcap_probe(struct spi_device *spi)
{
const struct of_device_id *match;
struct cpcap_ddata *cpcap;
int ret;
match = of_match_device(of_match_ptr(cpcap_of_match), &spi->dev);
if (!match)
return -ENODEV;
cpcap = devm_kzalloc(&spi->dev, sizeof(*cpcap), GFP_KERNEL);
if (!cpcap)
return -ENOMEM;
cpcap->spi = spi;
spi_set_drvdata(spi, cpcap);
spi->bits_per_word = 16;
spi->mode = SPI_MODE_0 | SPI_CS_HIGH;
ret = spi_setup(spi);
if (ret)
return ret;
cpcap->regmap_conf = &cpcap_regmap_config;
cpcap->regmap = devm_regmap_init_spi(spi, &cpcap_regmap_config);
if (IS_ERR(cpcap->regmap)) {
ret = PTR_ERR(cpcap->regmap);
dev_err(&cpcap->spi->dev, "Failed to initialize regmap: %d\n",
ret);
return ret;
}
ret = cpcap_check_revision(cpcap);
if (ret) {
dev_err(&cpcap->spi->dev, "Failed to detect CPCAP: %i\n", ret);
return ret;
}
ret = cpcap_init_irq(cpcap);
if (ret)
return ret;
return of_platform_populate(spi->dev.of_node, NULL, NULL,
&cpcap->spi->dev);
}
static int cpcap_remove(struct spi_device *pdev)
{
struct cpcap_ddata *cpcap = spi_get_drvdata(pdev);
of_platform_depopulate(&cpcap->spi->dev);
return 0;
}
