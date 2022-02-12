static void mpc837x_rdb_sd_cfg(void)
{
void __iomem *im;
im = ioremap(get_immrbase(), 0x1000);
if (!im) {
WARN_ON(1);
return;
}
clrsetbits_be32(im + MPC83XX_SICRL_OFFS, MPC837X_SICRL_USBB_MASK,
MPC837X_SICRL_SD);
clrsetbits_be32(im + MPC83XX_SICRH_OFFS, MPC837X_SICRH_SPI_MASK,
MPC837X_SICRH_SD);
iounmap(im);
}
static void __init mpc837x_rdb_setup_arch(void)
{
mpc83xx_setup_arch();
mpc837x_usb_cfg();
mpc837x_rdb_sd_cfg();
}
static int __init mpc837x_rdb_probe(void)
{
return of_device_compatible_match(of_root, board);
}
