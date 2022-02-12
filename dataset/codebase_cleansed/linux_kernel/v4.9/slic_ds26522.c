static void slic_write(struct spi_device *spi, u16 addr,
u8 data)
{
u8 temp[3];
addr = bitrev16(addr) >> 1;
data = bitrev8(data);
temp[0] = (u8)((addr >> 8) & 0x7f);
temp[1] = (u8)(addr & 0xfe);
temp[2] = data;
spi_write(spi, &temp[0], SLIC_THREE_LEN);
}
static u8 slic_read(struct spi_device *spi, u16 addr)
{
u8 temp[2];
u8 data;
addr = bitrev16(addr) >> 1;
temp[0] = (u8)(((addr >> 8) & 0x7f) | 0x80);
temp[1] = (u8)(addr & 0xfe);
spi_write_then_read(spi, &temp[0], SLIC_TWO_LEN, &data,
SLIC_TRANS_LEN);
data = bitrev8(data);
return data;
}
static bool get_slic_product_code(struct spi_device *spi)
{
u8 device_id;
device_id = slic_read(spi, DS26522_IDR_ADDR);
if ((device_id & 0xf8) == 0x68)
return true;
else
return false;
}
static void ds26522_e1_spec_config(struct spi_device *spi)
{
slic_write(spi, DS26522_RMMR_ADDR, DS26522_RMMR_E1);
slic_write(spi, DS26522_TMMR_ADDR, DS26522_TMMR_E1);
slic_write(spi, DS26522_RMMR_ADDR,
slic_read(spi, DS26522_RMMR_ADDR) | DS26522_RMMR_FRM_EN);
slic_write(spi, DS26522_TMMR_ADDR,
slic_read(spi, DS26522_TMMR_ADDR) | DS26522_TMMR_FRM_EN);
slic_write(spi, DS26522_RCR1_ADDR,
DS26522_RCR1_E1_HDB3 | DS26522_RCR1_E1_CCS);
slic_write(spi, DS26522_RIOCR_ADDR,
DS26522_RIOCR_2048KHZ | DS26522_RIOCR_RSIO_OUT);
slic_write(spi, DS26522_TCR1_ADDR, DS26522_TCR1_TB8ZS);
slic_write(spi, DS26522_TIOCR_ADDR,
DS26522_TIOCR_2048KHZ | DS26522_TIOCR_TSIO_OUT);
slic_write(spi, DS26522_E1TAF_ADDR, DS26522_E1TAF_DEFAULT);
slic_write(spi, DS26522_E1TNAF_ADDR, DS26522_E1TNAF_DEFAULT);
slic_write(spi, DS26522_RMMR_ADDR, slic_read(spi, DS26522_RMMR_ADDR) |
DS26522_RMMR_INIT_DONE);
slic_write(spi, DS26522_TMMR_ADDR, slic_read(spi, DS26522_TMMR_ADDR) |
DS26522_TMMR_INIT_DONE);
slic_write(spi, DS26522_LTRCR_ADDR, DS26522_LTRCR_E1);
slic_write(spi, DS26522_LTITSR_ADDR,
DS26522_LTITSR_TLIS_75OHM | DS26522_LTITSR_LBOS_75OHM);
slic_write(spi, DS26522_LRISMR_ADDR,
DS26522_LRISMR_75OHM | DS26522_LRISMR_MAX);
slic_write(spi, DS26522_LMCR_ADDR, DS26522_LMCR_TE);
}
static int slic_ds26522_init_configure(struct spi_device *spi)
{
u16 addr;
slic_write(spi, DS26522_GTCCR_ADDR, DS26522_GTCCR_BPREFSEL_REFCLKIN |
DS26522_GTCCR_BFREQSEL_2048KHZ |
DS26522_GTCCR_FREQSEL_2048KHZ);
slic_write(spi, DS26522_GTCR2_ADDR, DS26522_GTCR2_TSSYNCOUT);
slic_write(spi, DS26522_GFCR_ADDR, DS26522_GFCR_BPCLK_2048KHZ);
slic_write(spi, DS26522_GTCR1_ADDR, DS26522_GTCR1);
slic_write(spi, DS26522_GLSRR_ADDR, DS26522_GLSRR_RESET);
slic_write(spi, DS26522_GFSRR_ADDR, DS26522_GFSRR_RESET);
usleep_range(100, 120);
slic_write(spi, DS26522_GLSRR_ADDR, DS26522_GLSRR_NORMAL);
slic_write(spi, DS26522_GFSRR_ADDR, DS26522_GFSRR_NORMAL);
slic_write(spi, DS26522_RMMR_ADDR, DS26522_RMMR_SFTRST);
slic_write(spi, DS26522_TMMR_ADDR, DS26522_TMMR_SFTRST);
usleep_range(100, 120);
for (addr = DS26522_RF_ADDR_START; addr <= DS26522_RF_ADDR_END;
addr++)
slic_write(spi, addr, 0);
for (addr = DS26522_TF_ADDR_START; addr <= DS26522_TF_ADDR_END;
addr++)
slic_write(spi, addr, 0);
for (addr = DS26522_LIU_ADDR_START; addr <= DS26522_LIU_ADDR_END;
addr++)
slic_write(spi, addr, 0);
for (addr = DS26522_BERT_ADDR_START; addr <= DS26522_BERT_ADDR_END;
addr++)
slic_write(spi, addr, 0);
ds26522_e1_spec_config(spi);
slic_write(spi, DS26522_GTCR1_ADDR, 0x00);
return 0;
}
static int slic_ds26522_remove(struct spi_device *spi)
{
pr_info("DS26522 module uninstalled\n");
return 0;
}
static int slic_ds26522_probe(struct spi_device *spi)
{
int ret = 0;
g_spi = spi;
spi->bits_per_word = 8;
if (!get_slic_product_code(spi))
return ret;
ret = slic_ds26522_init_configure(spi);
if (ret == 0)
pr_info("DS26522 cs%d configurated\n", spi->chip_select);
return ret;
}
static int __init slic_ds26522_init(void)
{
return spi_register_driver(&slic_ds26522_driver);
}
static void __exit slic_ds26522_exit(void)
{
spi_unregister_driver(&slic_ds26522_driver);
}
