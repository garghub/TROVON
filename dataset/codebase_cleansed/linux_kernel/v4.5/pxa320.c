static int __init pxa320_init(void)
{
if (cpu_is_pxa320()) {
mfp_init_base(io_p2v(MFPR_BASE));
mfp_init_addr(pxa320_mfp_addr_map);
}
return 0;
}
