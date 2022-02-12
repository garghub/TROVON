void selfmod_function(const int *arr_fce, const unsigned int base)
{
unsigned int flags, i, j, *addr = NULL;
local_irq_save(flags);
__disable_icache();
for (j = 0; arr_fce[j] != 0; j++) {
addr = (unsigned int *) arr_fce[j];
pr_debug("%s: func(%d) at 0x%x\n",
__func__, j, (unsigned int) addr);
for (i = 0; ; i++) {
pr_debug("%s: instruction code at %d: 0x%x\n",
__func__, i, addr[i]);
if (addr[i] == IMM_BASE) {
if ((addr[i + 1] & LWI_BASE_MASK) == LWI_BASE) {
MODIFY_INSTR;
} else
if ((addr[i + 1] & ADDIK_BASE_MASK) ==
ADDIK_BASE) {
MODIFY_INSTR;
}
} else if (addr[i] == OPCODE_RTSD) {
pr_debug("%s: end of array %d\n", __func__, i);
break;
}
}
}
local_irq_restore(flags);
}
