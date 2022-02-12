static void print_sh_insn(u32 memaddr, u16 insn)
{
int relmask = ~0;
int nibs[4] = { (insn >> 12) & 0xf, (insn >> 8) & 0xf, (insn >> 4) & 0xf, insn & 0xf};
int lastsp;
struct sh_opcode_info *op = sh_table;
for (; op->name; op++) {
int n;
int imm = 0;
int rn = 0;
int rm = 0;
int rb = 0;
int disp_pc;
int disp_pc_addr = 0;
for (n = 0; n < 4; n++) {
int i = op->nibbles[n];
if (i < 16) {
if (nibs[n] == i)
continue;
goto fail;
}
switch (i) {
case BRANCH_8:
imm = (nibs[2] << 4) | (nibs[3]);
if (imm & 0x80)
imm |= ~0xff;
imm = ((char)imm) * 2 + 4 ;
goto ok;
case BRANCH_12:
imm = ((nibs[1]) << 8) | (nibs[2] << 4) | (nibs[3]);
if (imm & 0x800)
imm |= ~0xfff;
imm = imm * 2 + 4;
goto ok;
case IMM_4:
imm = nibs[3];
goto ok;
case IMM_4BY2:
imm = nibs[3] <<1;
goto ok;
case IMM_4BY4:
imm = nibs[3] <<2;
goto ok;
case IMM_8:
imm = (nibs[2] << 4) | nibs[3];
goto ok;
case PCRELIMM_8BY2:
imm = ((nibs[2] << 4) | nibs[3]) <<1;
relmask = ~1;
goto ok;
case PCRELIMM_8BY4:
imm = ((nibs[2] << 4) | nibs[3]) <<2;
relmask = ~3;
goto ok;
case IMM_8BY2:
imm = ((nibs[2] << 4) | nibs[3]) <<1;
goto ok;
case IMM_8BY4:
imm = ((nibs[2] << 4) | nibs[3]) <<2;
goto ok;
case DISP_8:
imm = (nibs[2] << 4) | (nibs[3]);
goto ok;
case DISP_4:
imm = nibs[3];
goto ok;
case REG_N:
rn = nibs[n];
break;
case REG_M:
rm = nibs[n];
break;
case REG_NM:
rn = (nibs[n] & 0xc) >> 2;
rm = (nibs[n] & 0x3);
break;
case REG_B:
rb = nibs[n] & 0x07;
break;
default:
return;
}
}
ok:
printk("%-8s ", op->name);
lastsp = (op->arg[0] == A_END);
disp_pc = 0;
for (n = 0; n < 6 && op->arg[n] != A_END; n++) {
if (n && op->arg[1] != A_END)
printk(", ");
switch (op->arg[n]) {
case A_IMM:
printk("#%d", (char)(imm));
break;
case A_R0:
printk("r0");
break;
case A_REG_N:
printk("r%d", rn);
break;
case A_INC_N:
printk("@r%d+", rn);
break;
case A_DEC_N:
printk("@-r%d", rn);
break;
case A_IND_N:
printk("@r%d", rn);
break;
case A_DISP_REG_N:
printk("@(%d,r%d)", imm, rn);
break;
case A_REG_M:
printk("r%d", rm);
break;
case A_INC_M:
printk("@r%d+", rm);
break;
case A_DEC_M:
printk("@-r%d", rm);
break;
case A_IND_M:
printk("@r%d", rm);
break;
case A_DISP_REG_M:
printk("@(%d,r%d)", imm, rm);
break;
case A_REG_B:
printk("r%d_bank", rb);
break;
case A_DISP_PC:
disp_pc = 1;
disp_pc_addr = imm + 4 + (memaddr & relmask);
printk("%08x <%pS>", disp_pc_addr,
(void *)disp_pc_addr);
break;
case A_IND_R0_REG_N:
printk("@(r0,r%d)", rn);
break;
case A_IND_R0_REG_M:
printk("@(r0,r%d)", rm);
break;
case A_DISP_GBR:
printk("@(%d,gbr)",imm);
break;
case A_R0_GBR:
printk("@(r0,gbr)");
break;
case A_BDISP12:
case A_BDISP8:
printk("%08x", imm + memaddr);
break;
case A_SR:
printk("sr");
break;
case A_GBR:
printk("gbr");
break;
case A_VBR:
printk("vbr");
break;
case A_SSR:
printk("ssr");
break;
case A_SPC:
printk("spc");
break;
case A_MACH:
printk("mach");
break;
case A_MACL:
printk("macl");
break;
case A_PR:
printk("pr");
break;
case A_SGR:
printk("sgr");
break;
case A_DBR:
printk("dbr");
break;
case FD_REG_N:
if (0)
goto d_reg_n;
case F_REG_N:
printk("fr%d", rn);
break;
case F_REG_M:
printk("fr%d", rm);
break;
case DX_REG_N:
if (rn & 1) {
printk("xd%d", rn & ~1);
break;
}
d_reg_n:
case D_REG_N:
printk("dr%d", rn);
break;
case DX_REG_M:
if (rm & 1) {
printk("xd%d", rm & ~1);
break;
}
case D_REG_M:
printk("dr%d", rm);
break;
case FPSCR_M:
case FPSCR_N:
printk("fpscr");
break;
case FPUL_M:
case FPUL_N:
printk("fpul");
break;
case F_FR0:
printk("fr0");
break;
case V_REG_N:
printk("fv%d", rn*4);
break;
case V_REG_M:
printk("fv%d", rm*4);
break;
case XMTRX_M4:
printk("xmtrx");
break;
default:
return;
}
}
if (disp_pc && strcmp(op->name, "mova") != 0) {
u32 val;
if (relmask == ~1)
__get_user(val, (u16 *)disp_pc_addr);
else
__get_user(val, (u32 *)disp_pc_addr);
printk(" ! %08x <%pS>", val, (void *)val);
}
return;
fail:
;
}
printk(".word 0x%x%x%x%x", nibs[0], nibs[1], nibs[2], nibs[3]);
}
void show_code(struct pt_regs *regs)
{
unsigned short *pc = (unsigned short *)regs->pc;
long i;
if (regs->pc & 0x1)
return;
printk("Code:\n");
for (i = -3 ; i < 6 ; i++) {
unsigned short insn;
if (__get_user(insn, pc + i)) {
printk(" (Bad address in pc)\n");
break;
}
printk("%s%08lx: ", (i ? " ": "->"), (unsigned long)(pc + i));
print_sh_insn((unsigned long)(pc + i), insn);
printk("\n");
}
printk("\n");
}
