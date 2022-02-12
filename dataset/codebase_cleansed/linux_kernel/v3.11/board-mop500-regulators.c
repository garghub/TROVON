static void ab8500_modify_reg_init(int id, u8 mask, u8 value)
{
int i;
if (cpu_is_u8520()) {
for (i = ARRAY_SIZE(ab8505_reg_init) - 1; i >= 0; i--) {
if (ab8505_reg_init[i].id == id) {
u8 initval = ab8505_reg_init[i].value;
initval = (initval & ~mask) | (value & mask);
ab8505_reg_init[i].value = initval;
BUG_ON(mask & ~ab8505_reg_init[i].mask);
return;
}
}
} else {
for (i = ARRAY_SIZE(ab8500_reg_init) - 1; i >= 0; i--) {
if (ab8500_reg_init[i].id == id) {
u8 initval = ab8500_reg_init[i].value;
initval = (initval & ~mask) | (value & mask);
ab8500_reg_init[i].value = initval;
BUG_ON(mask & ~ab8500_reg_init[i].mask);
return;
}
}
}
BUG_ON(1);
}
void mop500_regulator_init(void)
{
struct regulator_init_data *regulator;
if (cpu_is_u8520()) {
ab8500_modify_reg_init(AB8505_VAUX12REGU, 0x0f, 0x05);
}
if (cpu_is_u8500v20()) {
ab8500_modify_reg_init(AB8500_REGUREQUESTCTRL3, 0x01, 0x01);
ab8500_modify_reg_init(AB8500_REGUSYSCLKREQ1HPVALID2,
0x20, 0x20);
ab8500_modify_reg_init(AB8500_EXTSUPPLYREGU, 0x0c, 0x04);
regulator = &ab8500_ext_regulators[AB8500_EXT_SUPPLY2];
regulator->constraints.always_on = 1;
regulator = &ab8500_ext_regulators[AB8500_EXT_SUPPLY2];
regulator->constraints.state_mem.disabled = 1;
regulator->constraints.state_standby.disabled = 1;
regulator->driver_data = (void *)&ab8500_ext_supply2;
}
}
