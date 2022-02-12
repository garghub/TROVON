static int pxa3xx_mfp_suspend(void)
{
mfp_config_lpm();
return 0;
}
static void pxa3xx_mfp_resume(void)
{
mfp_config_run();
ASCR &= ~(ASCR_RDH | ASCR_D1S | ASCR_D2S | ASCR_D3S);
}
