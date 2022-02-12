static int mmc_set_power(struct device *dev, int slot, int power_on,
int vdd)
{
int err;
u8 dat = 0;
err = sx1_i2c_read_byte(SOFIA_I2C_ADDR, SOFIA_POWER1_REG, &dat);
if (err < 0)
return err;
if (power_on)
dat |= SOFIA_MMC_POWER;
else
dat &= ~SOFIA_MMC_POWER;
return sx1_i2c_write_byte(SOFIA_I2C_ADDR, SOFIA_POWER1_REG, dat);
}
void __init sx1_mmc_init(void)
{
mmc_data[0] = &mmc1_data;
omap1_init_mmc(mmc_data, OMAP15XX_NR_MMC);
}
void __init sx1_mmc_init(void)
{
}
