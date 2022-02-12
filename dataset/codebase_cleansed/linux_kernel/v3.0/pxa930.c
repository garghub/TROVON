static int __init pxa930_init(void)
{
if (cpu_is_pxa93x()) {
mfp_init_base(io_p2v(MFPR_BASE));
mfp_init_addr(pxa930_mfp_addr_map);
}
if (cpu_is_pxa935())
mfp_init_addr(pxa935_mfp_addr_map);
return 0;
}
