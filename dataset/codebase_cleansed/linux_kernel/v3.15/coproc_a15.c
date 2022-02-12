static int __init coproc_a15_init(void)
{
kvm_register_target_coproc_table(&a15_target_table);
return 0;
}
