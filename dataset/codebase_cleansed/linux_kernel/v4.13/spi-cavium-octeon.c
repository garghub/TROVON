static int octeon_spi_probe(struct platform_device *pdev)
{
struct resource *res_mem;
void __iomem *reg_base;
struct spi_master *master;
struct octeon_spi *p;
int err = -ENOENT;
master = spi_alloc_master(&pdev->dev, sizeof(struct octeon_spi));
if (!master)
return -ENOMEM;
p = spi_master_get_devdata(master);
platform_set_drvdata(pdev, master);
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg_base = devm_ioremap_resource(&pdev->dev, res_mem);
if (IS_ERR(reg_base)) {
err = PTR_ERR(reg_base);
goto fail;
}
p->register_base = reg_base;
p->sys_freq = octeon_get_io_clock_rate();
p->regs.config = 0;
p->regs.status = 0x08;
p->regs.tx = 0x10;
p->regs.data = 0x80;
master->num_chipselect = 4;
master->mode_bits = SPI_CPHA |
SPI_CPOL |
SPI_CS_HIGH |
SPI_LSB_FIRST |
SPI_3WIRE;
master->transfer_one_message = octeon_spi_transfer_one_message;
master->bits_per_word_mask = SPI_BPW_MASK(8);
master->max_speed_hz = OCTEON_SPI_MAX_CLOCK_HZ;
master->dev.of_node = pdev->dev.of_node;
err = devm_spi_register_master(&pdev->dev, master);
if (err) {
dev_err(&pdev->dev, "register master failed: %d\n", err);
goto fail;
}
dev_info(&pdev->dev, "OCTEON SPI bus driver\n");
return 0;
fail:
spi_master_put(master);
return err;
}
static int octeon_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = platform_get_drvdata(pdev);
struct octeon_spi *p = spi_master_get_devdata(master);
writeq(0, p->register_base + OCTEON_SPI_CFG(p));
return 0;
}
