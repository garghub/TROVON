static void __init init_ioports(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(adder875_pins); i++) {
const struct cpm_pin *pin = &adder875_pins[i];
cpm1_set_pin(pin->port, pin->pin, pin->flags);
}
cpm1_clk_setup(CPM_CLK_SMC1, CPM_BRG1, CPM_CLK_RTX);
clrbits32(&mpc8xx_immr->im_cpm.cp_cptr, 0x00000180);
}
static void __init adder875_setup(void)
{
cpm_reset();
init_ioports();
}
static int __init adder875_probe(void)
{
unsigned long root = of_get_flat_dt_root();
return of_flat_dt_is_compatible(root, "analogue-and-micro,adder875");
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
