void __kprobes disasm_instr(unsigned long addr, struct disasm_state *state,
int userspace, struct pt_regs *regs, struct callee_regs *cregs)
{
int fieldA = 0;
int fieldC = 0, fieldCisReg = 0;
uint16_t word1 = 0, word0 = 0;
int subopcode, is_linked, op_format;
uint16_t *ins_ptr;
uint16_t ins_buf[4];
int bytes_not_copied = 0;
memset(state, 0, sizeof(struct disasm_state));
if (userspace) {
bytes_not_copied = copy_from_user(ins_buf,
(const void __user *) addr, 8);
if (bytes_not_copied > 6)
goto fault;
ins_ptr = ins_buf;
} else {
ins_ptr = (uint16_t *) addr;
}
word1 = *((uint16_t *)addr);
state->major_opcode = (word1 >> 11) & 0x1F;
if (state->major_opcode < 0x0B) {
if (bytes_not_copied > 4)
goto fault;
state->instr_len = 4;
word0 = *((uint16_t *)(addr+2));
state->words[0] = (word1 << 16) | word0;
} else {
state->instr_len = 2;
state->words[0] = word1;
}
word1 = *((uint16_t *)(addr + state->instr_len));
word0 = *((uint16_t *)(addr + state->instr_len + 2));
state->words[1] = (word1 << 16) | word0;
switch (state->major_opcode) {
case op_Bcc:
state->is_branch = 1;
fieldA = (IS_BIT(state->words[0], 16)) ?
FIELD_s25(state->words[0]) :
FIELD_s21(state->words[0]);
state->delay_slot = IS_BIT(state->words[0], 5);
state->target = fieldA + (addr & ~0x3);
state->flow = direct_jump;
break;
case op_BLcc:
if (IS_BIT(state->words[0], 16)) {
fieldA = (IS_BIT(state->words[0], 17)) ?
(FIELD_s25(state->words[0]) & ~0x3) :
FIELD_s21(state->words[0]);
state->flow = direct_call;
} else {
fieldA = FIELD_s9(state->words[0]) & ~0x3;
state->flow = direct_jump;
}
state->delay_slot = IS_BIT(state->words[0], 5);
state->target = fieldA + (addr & ~0x3);
state->is_branch = 1;
break;
case op_LD:
state->write = 0;
state->di = BITS(state->words[0], 11, 11);
if (state->di)
break;
state->x = BITS(state->words[0], 6, 6);
state->zz = BITS(state->words[0], 7, 8);
state->aa = BITS(state->words[0], 9, 10);
state->wb_reg = FIELD_B(state->words[0]);
if (state->wb_reg == REG_LIMM) {
state->instr_len += 4;
state->aa = 0;
state->src1 = state->words[1];
} else {
state->src1 = get_reg(state->wb_reg, regs, cregs);
}
state->src2 = FIELD_s9(state->words[0]);
state->dest = FIELD_A(state->words[0]);
state->pref = (state->dest == REG_LIMM);
break;
case op_ST:
state->write = 1;
state->di = BITS(state->words[0], 5, 5);
if (state->di)
break;
state->aa = BITS(state->words[0], 3, 4);
state->zz = BITS(state->words[0], 1, 2);
state->src1 = FIELD_C(state->words[0]);
if (state->src1 == REG_LIMM) {
state->instr_len += 4;
state->src1 = state->words[1];
} else {
state->src1 = get_reg(state->src1, regs, cregs);
}
state->wb_reg = FIELD_B(state->words[0]);
if (state->wb_reg == REG_LIMM) {
state->aa = 0;
state->instr_len += 4;
state->src2 = state->words[1];
} else {
state->src2 = get_reg(state->wb_reg, regs, cregs);
}
state->src3 = FIELD_s9(state->words[0]);
break;
case op_MAJOR_4:
subopcode = MINOR_OPCODE(state->words[0]);
switch (subopcode) {
case 32:
case 33:
case 34:
case 35:
is_linked = 0;
if (subopcode == 33 || subopcode == 35)
state->delay_slot = 1;
if (subopcode == 34 || subopcode == 35)
is_linked = 1;
fieldCisReg = 0;
op_format = BITS(state->words[0], 22, 23);
if (op_format == 0 || ((op_format == 3) &&
(!IS_BIT(state->words[0], 5)))) {
fieldC = FIELD_C(state->words[0]);
if (fieldC == REG_LIMM) {
fieldC = state->words[1];
state->instr_len += 4;
} else {
fieldCisReg = 1;
}
} else if (op_format == 1 || ((op_format == 3)
&& (IS_BIT(state->words[0], 5)))) {
fieldC = FIELD_C(state->words[0]);
} else {
fieldC = FIELD_s12(state->words[0]);
}
if (!fieldCisReg) {
state->target = fieldC;
state->flow = is_linked ?
direct_call : direct_jump;
} else {
state->target = get_reg(fieldC, regs, cregs);
state->flow = is_linked ?
indirect_call : indirect_jump;
}
state->is_branch = 1;
break;
case 40:
if (BITS(state->words[0], 22, 23) == 3) {
fieldC = FIELD_C(state->words[0]);
fieldC = fieldC << 1;
fieldC += (addr & ~0x03);
state->is_branch = 1;
state->flow = direct_jump;
state->target = fieldC;
}
break;
case 48 ... 55:
state->di = BITS(state->words[0], 15, 15);
if (state->di)
break;
state->x = BITS(state->words[0], 16, 16);
state->zz = BITS(state->words[0], 17, 18);
state->aa = BITS(state->words[0], 22, 23);
state->wb_reg = FIELD_B(state->words[0]);
if (state->wb_reg == REG_LIMM) {
state->instr_len += 4;
state->src1 = state->words[1];
} else {
state->src1 = get_reg(state->wb_reg, regs,
cregs);
}
state->src2 = FIELD_C(state->words[0]);
if (state->src2 == REG_LIMM) {
state->instr_len += 4;
state->src2 = state->words[1];
} else {
state->src2 = get_reg(state->src2, regs,
cregs);
}
state->dest = FIELD_A(state->words[0]);
if (state->dest == REG_LIMM)
state->pref = 1;
break;
case 10:
switch (BITS(state->words[0], 22, 23)) {
case 0:
if (FIELD_C(state->words[0]) == REG_LIMM)
state->instr_len += 4;
break;
case 1:
break;
case 2:
break;
case 3:
if ((!IS_BIT(state->words[0], 5)) &&
(FIELD_C(state->words[0]) == REG_LIMM))
state->instr_len += 4;
break;
}
break;
default:
switch (BITS(state->words[0], 22, 23)) {
case 0:
if ((FIELD_B(state->words[0]) == REG_LIMM) ||
(FIELD_C(state->words[0]) == REG_LIMM))
state->instr_len += 4;
break;
case 1:
break;
case 2:
break;
case 3:
if ((!IS_BIT(state->words[0], 5)) &&
((FIELD_B(state->words[0]) == REG_LIMM) ||
(FIELD_C(state->words[0]) == REG_LIMM)))
state->instr_len += 4;
break;
}
break;
}
break;
case op_LD_ADD:
state->zz = BITS(state->words[0], 3, 4);
state->src1 = get_reg(FIELD_S_B(state->words[0]), regs, cregs);
state->src2 = get_reg(FIELD_S_C(state->words[0]), regs, cregs);
state->dest = FIELD_S_A(state->words[0]);
break;
case op_ADD_MOV_CMP:
if ((BITS(state->words[0], 3, 4) < 3) &&
(FIELD_S_H(state->words[0]) == REG_LIMM))
state->instr_len += 4;
break;
case op_S:
subopcode = BITS(state->words[0], 5, 7);
switch (subopcode) {
case 0:
case 1:
case 2:
case 3:
state->target = get_reg(FIELD_S_B(state->words[0]),
regs, cregs);
state->delay_slot = subopcode & 1;
state->flow = (subopcode >= 2) ?
direct_call : indirect_jump;
break;
case 7:
switch (BITS(state->words[0], 8, 10)) {
case 4:
case 5:
case 6:
case 7:
state->delay_slot = (subopcode == 7);
state->flow = indirect_jump;
state->target = get_reg(31, regs, cregs);
default:
break;
}
default:
break;
}
break;
case op_LD_S:
state->src1 = get_reg(FIELD_S_B(state->words[0]), regs, cregs);
state->src2 = FIELD_S_u7(state->words[0]);
state->dest = FIELD_S_C(state->words[0]);
break;
case op_LDB_S:
case op_STB_S:
state->zz = 1;
break;
case op_LDWX_S:
state->x = 1;
case op_LDW_S:
state->zz = 2;
state->src1 = get_reg(FIELD_S_B(state->words[0]), regs, cregs);
state->src2 = FIELD_S_u6(state->words[0]);
state->dest = FIELD_S_C(state->words[0]);
break;
case op_ST_S:
state->write = 1;
state->src1 = get_reg(FIELD_S_C(state->words[0]), regs, cregs);
state->src2 = get_reg(FIELD_S_B(state->words[0]), regs, cregs);
state->src3 = FIELD_S_u7(state->words[0]);
break;
case op_STW_S:
state->write = 1;
state->zz = 2;
state->src1 = get_reg(FIELD_S_C(state->words[0]), regs, cregs);
state->src2 = get_reg(FIELD_S_B(state->words[0]), regs, cregs);
state->src3 = FIELD_S_u6(state->words[0]);
break;
case op_SP:
state->write = BITS(state->words[0], 6, 6);
state->zz = BITS(state->words[0], 5, 5);
if (state->zz)
break;
if (!state->write) {
state->src1 = get_reg(28, regs, cregs);
state->src2 = FIELD_S_u7(state->words[0]);
state->dest = FIELD_S_B(state->words[0]);
} else {
state->src1 = get_reg(FIELD_S_B(state->words[0]), regs,
cregs);
state->src2 = get_reg(28, regs, cregs);
state->src3 = FIELD_S_u7(state->words[0]);
}
break;
case op_GP:
state->zz = BITS(state->words[0], 9, 10);
state->src1 = get_reg(26, regs, cregs);
state->src2 = state->zz ? FIELD_S_s10(state->words[0]) :
FIELD_S_s11(state->words[0]);
state->dest = 0;
break;
case op_Pcl:
state->src1 = regs->ret & ~3;
state->src2 = FIELD_S_u10(state->words[0]);
state->dest = FIELD_S_B(state->words[0]);
break;
case op_BR_S:
state->target = FIELD_S_s8(state->words[0]) + (addr & ~0x03);
state->flow = direct_jump;
state->is_branch = 1;
break;
case op_B_S:
fieldA = (BITS(state->words[0], 9, 10) == 3) ?
FIELD_S_s7(state->words[0]) :
FIELD_S_s10(state->words[0]);
state->target = fieldA + (addr & ~0x03);
state->flow = direct_jump;
state->is_branch = 1;
break;
case op_BL_S:
state->target = FIELD_S_s13(state->words[0]) + (addr & ~0x03);
state->flow = direct_call;
state->is_branch = 1;
break;
default:
break;
}
if (bytes_not_copied <= (8 - state->instr_len))
return;
fault: state->fault = 1;
}
long __kprobes get_reg(int reg, struct pt_regs *regs,
struct callee_regs *cregs)
{
long *p;
if (reg <= 12) {
p = &regs->r0;
return p[-reg];
}
if (cregs && (reg <= 25)) {
p = &cregs->r13;
return p[13-reg];
}
if (reg == 26)
return regs->r26;
if (reg == 27)
return regs->fp;
if (reg == 28)
return regs->sp;
if (reg == 31)
return regs->blink;
return 0;
}
void __kprobes set_reg(int reg, long val, struct pt_regs *regs,
struct callee_regs *cregs)
{
long *p;
switch (reg) {
case 0 ... 12:
p = &regs->r0;
p[-reg] = val;
break;
case 13 ... 25:
if (cregs) {
p = &cregs->r13;
p[13-reg] = val;
}
break;
case 26:
regs->r26 = val;
break;
case 27:
regs->fp = val;
break;
case 28:
regs->sp = val;
break;
case 31:
regs->blink = val;
break;
default:
break;
}
}
int __kprobes disasm_next_pc(unsigned long pc, struct pt_regs *regs,
struct callee_regs *cregs,
unsigned long *next_pc, unsigned long *tgt_if_br)
{
struct disasm_state instr;
memset(&instr, 0, sizeof(struct disasm_state));
disasm_instr(pc, &instr, 0, regs, cregs);
*next_pc = pc + instr.instr_len;
if (instr.is_branch)
*tgt_if_br = instr.target;
if (instr.delay_slot) {
struct disasm_state instr_d;
disasm_instr(*next_pc, &instr_d, 0, regs, cregs);
*next_pc += instr_d.instr_len;
}
if (!(regs->status32 & STATUS32_L) && (*next_pc == regs->lp_end)
&& (regs->lp_count > 1)) {
*next_pc = regs->lp_start;
}
return instr.is_branch;
}
