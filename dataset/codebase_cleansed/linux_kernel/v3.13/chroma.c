void __init chroma_setup_arch(void)
{
wsp_setup_arch();
wsp_setup_h8();
}
static int __init chroma_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "ibm,wsp-chroma"))
return 0;
return 1;
}
