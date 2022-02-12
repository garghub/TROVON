asmlinkage unsigned int arm_check_condition(u32 opcode, u32 psr)
{
u32 cc_bits = opcode >> 28;
u32 psr_cond = psr >> 28;
unsigned int ret;
if (cc_bits != ARM_OPCODE_CONDITION_UNCOND) {
if ((cc_map[cc_bits] >> (psr_cond)) & 1)
ret = ARM_OPCODE_CONDTEST_PASS;
else
ret = ARM_OPCODE_CONDTEST_FAIL;
} else {
ret = ARM_OPCODE_CONDTEST_UNCOND;
}
return ret;
}
