static int __init coproc_a7_init(void)
{
kvm_register_target_coproc_table(&a7_target_table);
return 0;
}
