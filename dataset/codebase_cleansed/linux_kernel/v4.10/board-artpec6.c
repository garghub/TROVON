static void __init artpec6_init_machine(void)
{
struct regmap *regmap;
regmap = syscon_regmap_lookup_by_compatible("axis,artpec6-syscon");
if (!IS_ERR(regmap)) {
regmap_write(regmap, ARTPEC6_DMACFG_REGNUM,
ARTPEC6_DMACFG_UARTS_BURST);
};
}
static void artpec6_l2c310_write_sec(unsigned long val, unsigned reg)
{
struct arm_smccc_res res;
arm_smccc_smc(SECURE_OP_L2C_WRITEREG, reg, val, 0,
0, 0, 0, 0, &res);
WARN_ON(res.a0);
}
