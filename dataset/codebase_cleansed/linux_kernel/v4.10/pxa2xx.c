void pxa2xx_clear_reset_status(unsigned int mask)
{
RCSR = mask;
}
void pxa2xx_transceiver_mode(struct device *dev, int mode)
{
if (mode & IR_OFF) {
pxa2xx_mfp_config(pxa2xx_mfp_off, ARRAY_SIZE(pxa2xx_mfp_off));
} else if (mode & IR_SIRMODE) {
pxa2xx_mfp_config(pxa2xx_mfp_sir, ARRAY_SIZE(pxa2xx_mfp_sir));
} else if (mode & IR_FIRMODE) {
pxa2xx_mfp_config(pxa2xx_mfp_fir, ARRAY_SIZE(pxa2xx_mfp_fir));
} else
BUG();
}
