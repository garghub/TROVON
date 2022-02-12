static void __init i386_default_early_setup(void)
{
x86_init.resources.reserve_resources = i386_reserve_resources;
x86_init.mpparse.setup_ioapic_ids = setup_ioapic_ids_from_mpc;
}
asmlinkage __visible void __init i386_start_kernel(void)
{
cr4_init_shadow();
sanitize_boot_params(&boot_params);
x86_early_init_platform_quirks();
switch (boot_params.hdr.hardware_subarch) {
case X86_SUBARCH_INTEL_MID:
x86_intel_mid_early_setup();
break;
case X86_SUBARCH_CE4100:
x86_ce4100_early_setup();
break;
default:
i386_default_early_setup();
break;
}
start_kernel();
}
