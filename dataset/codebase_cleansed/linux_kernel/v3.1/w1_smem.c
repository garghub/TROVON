static int __init w1_smem_init(void)
{
int err;
err = w1_register_family(&w1_smem_family_01);
if (err)
return err;
err = w1_register_family(&w1_smem_family_81);
if (err) {
w1_unregister_family(&w1_smem_family_01);
return err;
}
return 0;
}
static void __exit w1_smem_fini(void)
{
w1_unregister_family(&w1_smem_family_01);
w1_unregister_family(&w1_smem_family_81);
}
