void pic32_pps_input(int function, int pin)
{
void __iomem *pps_base = ioremap_nocache(PPS_BASE, 0xF4);
int i;
for (i = 0; i < ARRAY_SIZE(input_pin_reg); i++) {
if (input_pin_reg[i].function == function) {
__raw_writel(pin, pps_base + input_pin_reg[i].reg);
return;
}
}
iounmap(pps_base);
}
void pic32_pps_output(int function, int pin)
{
void __iomem *pps_base = ioremap_nocache(PPS_BASE, 0x170);
int i;
for (i = 0; i < ARRAY_SIZE(output_pin_reg); i++) {
if (output_pin_reg[i].pin == pin) {
__raw_writel(function,
pps_base + output_pin_reg[i].reg);
return;
}
}
iounmap(pps_base);
}
