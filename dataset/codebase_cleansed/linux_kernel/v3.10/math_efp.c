static unsigned long insn_type(unsigned long speinsn)
{
unsigned long ret = NOTYPE;
switch (speinsn & 0x7ff) {
case EFSABS: ret = XA; break;
case EFSADD: ret = AB; break;
case EFSCFD: ret = XB; break;
case EFSCMPEQ: ret = XCR; break;
case EFSCMPGT: ret = XCR; break;
case EFSCMPLT: ret = XCR; break;
case EFSCTSF: ret = XB; break;
case EFSCTSI: ret = XB; break;
case EFSCTSIZ: ret = XB; break;
case EFSCTUF: ret = XB; break;
case EFSCTUI: ret = XB; break;
case EFSCTUIZ: ret = XB; break;
case EFSDIV: ret = AB; break;
case EFSMUL: ret = AB; break;
case EFSNABS: ret = XA; break;
case EFSNEG: ret = XA; break;
case EFSSUB: ret = AB; break;
case EFSCFSI: ret = XB; break;
case EVFSABS: ret = XA; break;
case EVFSADD: ret = AB; break;
case EVFSCMPEQ: ret = XCR; break;
case EVFSCMPGT: ret = XCR; break;
case EVFSCMPLT: ret = XCR; break;
case EVFSCTSF: ret = XB; break;
case EVFSCTSI: ret = XB; break;
case EVFSCTSIZ: ret = XB; break;
case EVFSCTUF: ret = XB; break;
case EVFSCTUI: ret = XB; break;
case EVFSCTUIZ: ret = XB; break;
case EVFSDIV: ret = AB; break;
case EVFSMUL: ret = AB; break;
case EVFSNABS: ret = XA; break;
case EVFSNEG: ret = XA; break;
case EVFSSUB: ret = AB; break;
case EFDABS: ret = XA; break;
case EFDADD: ret = AB; break;
case EFDCFS: ret = XB; break;
case EFDCMPEQ: ret = XCR; break;
case EFDCMPGT: ret = XCR; break;
case EFDCMPLT: ret = XCR; break;
case EFDCTSF: ret = XB; break;
case EFDCTSI: ret = XB; break;
case EFDCTSIDZ: ret = XB; break;
case EFDCTSIZ: ret = XB; break;
case EFDCTUF: ret = XB; break;
case EFDCTUI: ret = XB; break;
case EFDCTUIDZ: ret = XB; break;
case EFDCTUIZ: ret = XB; break;
case EFDDIV: ret = AB; break;
case EFDMUL: ret = AB; break;
case EFDNABS: ret = XA; break;
case EFDNEG: ret = XA; break;
case EFDSUB: ret = AB; break;
}
return ret;
}
int do_spe_mathemu(struct pt_regs *regs)
{
FP_DECL_EX;
int IR, cmp;
unsigned long type, func, fc, fa, fb, src, speinsn;
union dw_union vc, va, vb;
if (get_user(speinsn, (unsigned int __user *) regs->nip))
return -EFAULT;
if ((speinsn >> 26) != EFAPU)
return -EINVAL;
type = insn_type(speinsn);
if (type == NOTYPE)
goto illegal;
func = speinsn & 0x7ff;
fc = (speinsn >> 21) & 0x1f;
fa = (speinsn >> 16) & 0x1f;
fb = (speinsn >> 11) & 0x1f;
src = (speinsn >> 5) & 0x7;
vc.wp[0] = current->thread.evr[fc];
vc.wp[1] = regs->gpr[fc];
va.wp[0] = current->thread.evr[fa];
va.wp[1] = regs->gpr[fa];
vb.wp[0] = current->thread.evr[fb];
vb.wp[1] = regs->gpr[fb];
__FPU_FPSCR = mfspr(SPRN_SPEFSCR);
pr_debug("speinsn:%08lx spefscr:%08lx\n", speinsn, __FPU_FPSCR);
pr_debug("vc: %08x %08x\n", vc.wp[0], vc.wp[1]);
pr_debug("va: %08x %08x\n", va.wp[0], va.wp[1]);
pr_debug("vb: %08x %08x\n", vb.wp[0], vb.wp[1]);
switch (src) {
case SPFP: {
FP_DECL_S(SA); FP_DECL_S(SB); FP_DECL_S(SR);
switch (type) {
case AB:
case XCR:
FP_UNPACK_SP(SA, va.wp + 1);
case XB:
FP_UNPACK_SP(SB, vb.wp + 1);
break;
case XA:
FP_UNPACK_SP(SA, va.wp + 1);
break;
}
pr_debug("SA: %ld %08lx %ld (%ld)\n", SA_s, SA_f, SA_e, SA_c);
pr_debug("SB: %ld %08lx %ld (%ld)\n", SB_s, SB_f, SB_e, SB_c);
switch (func) {
case EFSABS:
vc.wp[1] = va.wp[1] & ~SIGN_BIT_S;
goto update_regs;
case EFSNABS:
vc.wp[1] = va.wp[1] | SIGN_BIT_S;
goto update_regs;
case EFSNEG:
vc.wp[1] = va.wp[1] ^ SIGN_BIT_S;
goto update_regs;
case EFSADD:
FP_ADD_S(SR, SA, SB);
goto pack_s;
case EFSSUB:
FP_SUB_S(SR, SA, SB);
goto pack_s;
case EFSMUL:
FP_MUL_S(SR, SA, SB);
goto pack_s;
case EFSDIV:
FP_DIV_S(SR, SA, SB);
goto pack_s;
case EFSCMPEQ:
cmp = 0;
goto cmp_s;
case EFSCMPGT:
cmp = 1;
goto cmp_s;
case EFSCMPLT:
cmp = -1;
goto cmp_s;
case EFSCTSF:
case EFSCTUF:
if (!((vb.wp[1] >> 23) == 0xff && ((vb.wp[1] & 0x7fffff) > 0))) {
if (((vb.wp[1] >> 23) & 0xff) == 0) {
vc.wp[1] = 0x0;
} else if ((vb.wp[1] >> 31) == 0) {
vc.wp[1] = (func == EFSCTSF) ?
0x7fffffff : 0xffffffff;
} else {
vc.wp[1] = (func == EFSCTSF) ?
0x80000000 : 0x0;
}
} else {
vc.wp[1] = 0x0;
}
goto update_regs;
case EFSCFD: {
FP_DECL_D(DB);
FP_CLEAR_EXCEPTIONS;
FP_UNPACK_DP(DB, vb.dp);
pr_debug("DB: %ld %08lx %08lx %ld (%ld)\n",
DB_s, DB_f1, DB_f0, DB_e, DB_c);
FP_CONV(S, D, 1, 2, SR, DB);
goto pack_s;
}
case EFSCTSI:
case EFSCTSIZ:
case EFSCTUI:
case EFSCTUIZ:
if (func & 0x4) {
_FP_ROUND(1, SB);
} else {
_FP_ROUND_ZERO(1, SB);
}
FP_TO_INT_S(vc.wp[1], SB, 32,
(((func & 0x3) != 0) || SB_s));
goto update_regs;
default:
goto illegal;
}
break;
pack_s:
pr_debug("SR: %ld %08lx %ld (%ld)\n", SR_s, SR_f, SR_e, SR_c);
FP_PACK_SP(vc.wp + 1, SR);
goto update_regs;
cmp_s:
FP_CMP_S(IR, SA, SB, 3);
if (IR == 3 && (FP_ISSIGNAN_S(SA) || FP_ISSIGNAN_S(SB)))
FP_SET_EXCEPTION(FP_EX_INVALID);
if (IR == cmp) {
IR = 0x4;
} else {
IR = 0;
}
goto update_ccr;
}
case DPFP: {
FP_DECL_D(DA); FP_DECL_D(DB); FP_DECL_D(DR);
switch (type) {
case AB:
case XCR:
FP_UNPACK_DP(DA, va.dp);
case XB:
FP_UNPACK_DP(DB, vb.dp);
break;
case XA:
FP_UNPACK_DP(DA, va.dp);
break;
}
pr_debug("DA: %ld %08lx %08lx %ld (%ld)\n",
DA_s, DA_f1, DA_f0, DA_e, DA_c);
pr_debug("DB: %ld %08lx %08lx %ld (%ld)\n",
DB_s, DB_f1, DB_f0, DB_e, DB_c);
switch (func) {
case EFDABS:
vc.dp[0] = va.dp[0] & ~SIGN_BIT_D;
goto update_regs;
case EFDNABS:
vc.dp[0] = va.dp[0] | SIGN_BIT_D;
goto update_regs;
case EFDNEG:
vc.dp[0] = va.dp[0] ^ SIGN_BIT_D;
goto update_regs;
case EFDADD:
FP_ADD_D(DR, DA, DB);
goto pack_d;
case EFDSUB:
FP_SUB_D(DR, DA, DB);
goto pack_d;
case EFDMUL:
FP_MUL_D(DR, DA, DB);
goto pack_d;
case EFDDIV:
FP_DIV_D(DR, DA, DB);
goto pack_d;
case EFDCMPEQ:
cmp = 0;
goto cmp_d;
case EFDCMPGT:
cmp = 1;
goto cmp_d;
case EFDCMPLT:
cmp = -1;
goto cmp_d;
case EFDCTSF:
case EFDCTUF:
if (!((vb.wp[0] >> 20) == 0x7ff &&
((vb.wp[0] & 0xfffff) > 0 || (vb.wp[1] > 0)))) {
if (((vb.wp[0] >> 20) & 0x7ff) == 0) {
vc.wp[1] = 0x0;
} else if ((vb.wp[0] >> 31) == 0) {
vc.wp[1] = (func == EFDCTSF) ?
0x7fffffff : 0xffffffff;
} else {
vc.wp[1] = (func == EFDCTSF) ?
0x80000000 : 0x0;
}
} else {
vc.wp[1] = 0x0;
}
goto update_regs;
case EFDCFS: {
FP_DECL_S(SB);
FP_CLEAR_EXCEPTIONS;
FP_UNPACK_SP(SB, vb.wp + 1);
pr_debug("SB: %ld %08lx %ld (%ld)\n",
SB_s, SB_f, SB_e, SB_c);
FP_CONV(D, S, 2, 1, DR, SB);
goto pack_d;
}
case EFDCTUIDZ:
case EFDCTSIDZ:
_FP_ROUND_ZERO(2, DB);
FP_TO_INT_D(vc.dp[0], DB, 64, ((func & 0x1) == 0));
goto update_regs;
case EFDCTUI:
case EFDCTSI:
case EFDCTUIZ:
case EFDCTSIZ:
if (func & 0x4) {
_FP_ROUND(2, DB);
} else {
_FP_ROUND_ZERO(2, DB);
}
FP_TO_INT_D(vc.wp[1], DB, 32,
(((func & 0x3) != 0) || DB_s));
goto update_regs;
default:
goto illegal;
}
break;
pack_d:
pr_debug("DR: %ld %08lx %08lx %ld (%ld)\n",
DR_s, DR_f1, DR_f0, DR_e, DR_c);
FP_PACK_DP(vc.dp, DR);
goto update_regs;
cmp_d:
FP_CMP_D(IR, DA, DB, 3);
if (IR == 3 && (FP_ISSIGNAN_D(DA) || FP_ISSIGNAN_D(DB)))
FP_SET_EXCEPTION(FP_EX_INVALID);
if (IR == cmp) {
IR = 0x4;
} else {
IR = 0;
}
goto update_ccr;
}
case VCT: {
FP_DECL_S(SA0); FP_DECL_S(SB0); FP_DECL_S(SR0);
FP_DECL_S(SA1); FP_DECL_S(SB1); FP_DECL_S(SR1);
int IR0, IR1;
switch (type) {
case AB:
case XCR:
FP_UNPACK_SP(SA0, va.wp);
FP_UNPACK_SP(SA1, va.wp + 1);
case XB:
FP_UNPACK_SP(SB0, vb.wp);
FP_UNPACK_SP(SB1, vb.wp + 1);
break;
case XA:
FP_UNPACK_SP(SA0, va.wp);
FP_UNPACK_SP(SA1, va.wp + 1);
break;
}
pr_debug("SA0: %ld %08lx %ld (%ld)\n",
SA0_s, SA0_f, SA0_e, SA0_c);
pr_debug("SA1: %ld %08lx %ld (%ld)\n",
SA1_s, SA1_f, SA1_e, SA1_c);
pr_debug("SB0: %ld %08lx %ld (%ld)\n",
SB0_s, SB0_f, SB0_e, SB0_c);
pr_debug("SB1: %ld %08lx %ld (%ld)\n",
SB1_s, SB1_f, SB1_e, SB1_c);
switch (func) {
case EVFSABS:
vc.wp[0] = va.wp[0] & ~SIGN_BIT_S;
vc.wp[1] = va.wp[1] & ~SIGN_BIT_S;
goto update_regs;
case EVFSNABS:
vc.wp[0] = va.wp[0] | SIGN_BIT_S;
vc.wp[1] = va.wp[1] | SIGN_BIT_S;
goto update_regs;
case EVFSNEG:
vc.wp[0] = va.wp[0] ^ SIGN_BIT_S;
vc.wp[1] = va.wp[1] ^ SIGN_BIT_S;
goto update_regs;
case EVFSADD:
FP_ADD_S(SR0, SA0, SB0);
FP_ADD_S(SR1, SA1, SB1);
goto pack_vs;
case EVFSSUB:
FP_SUB_S(SR0, SA0, SB0);
FP_SUB_S(SR1, SA1, SB1);
goto pack_vs;
case EVFSMUL:
FP_MUL_S(SR0, SA0, SB0);
FP_MUL_S(SR1, SA1, SB1);
goto pack_vs;
case EVFSDIV:
FP_DIV_S(SR0, SA0, SB0);
FP_DIV_S(SR1, SA1, SB1);
goto pack_vs;
case EVFSCMPEQ:
cmp = 0;
goto cmp_vs;
case EVFSCMPGT:
cmp = 1;
goto cmp_vs;
case EVFSCMPLT:
cmp = -1;
goto cmp_vs;
case EVFSCTSF:
__asm__ __volatile__ ("mtspr 512, %4\n"
"efsctsf %0, %2\n"
"efsctsf %1, %3\n"
: "=r" (vc.wp[0]), "=r" (vc.wp[1])
: "r" (vb.wp[0]), "r" (vb.wp[1]), "r" (0));
goto update_regs;
case EVFSCTUF:
__asm__ __volatile__ ("mtspr 512, %4\n"
"efsctuf %0, %2\n"
"efsctuf %1, %3\n"
: "=r" (vc.wp[0]), "=r" (vc.wp[1])
: "r" (vb.wp[0]), "r" (vb.wp[1]), "r" (0));
goto update_regs;
case EVFSCTUI:
case EVFSCTSI:
case EVFSCTUIZ:
case EVFSCTSIZ:
if (func & 0x4) {
_FP_ROUND(1, SB0);
_FP_ROUND(1, SB1);
} else {
_FP_ROUND_ZERO(1, SB0);
_FP_ROUND_ZERO(1, SB1);
}
FP_TO_INT_S(vc.wp[0], SB0, 32,
(((func & 0x3) != 0) || SB0_s));
FP_TO_INT_S(vc.wp[1], SB1, 32,
(((func & 0x3) != 0) || SB1_s));
goto update_regs;
default:
goto illegal;
}
break;
pack_vs:
pr_debug("SR0: %ld %08lx %ld (%ld)\n",
SR0_s, SR0_f, SR0_e, SR0_c);
pr_debug("SR1: %ld %08lx %ld (%ld)\n",
SR1_s, SR1_f, SR1_e, SR1_c);
FP_PACK_SP(vc.wp, SR0);
FP_PACK_SP(vc.wp + 1, SR1);
goto update_regs;
cmp_vs:
{
int ch, cl;
FP_CMP_S(IR0, SA0, SB0, 3);
FP_CMP_S(IR1, SA1, SB1, 3);
if (IR0 == 3 && (FP_ISSIGNAN_S(SA0) || FP_ISSIGNAN_S(SB0)))
FP_SET_EXCEPTION(FP_EX_INVALID);
if (IR1 == 3 && (FP_ISSIGNAN_S(SA1) || FP_ISSIGNAN_S(SB1)))
FP_SET_EXCEPTION(FP_EX_INVALID);
ch = (IR0 == cmp) ? 1 : 0;
cl = (IR1 == cmp) ? 1 : 0;
IR = (ch << 3) | (cl << 2) | ((ch | cl) << 1) |
((ch & cl) << 0);
goto update_ccr;
}
}
default:
return -EINVAL;
}
update_ccr:
regs->ccr &= ~(15 << ((7 - ((speinsn >> 23) & 0x7)) << 2));
regs->ccr |= (IR << ((7 - ((speinsn >> 23) & 0x7)) << 2));
update_regs:
__FPU_FPSCR &= ~FP_EX_MASK;
__FPU_FPSCR |= (FP_CUR_EXCEPTIONS & FP_EX_MASK);
mtspr(SPRN_SPEFSCR, __FPU_FPSCR);
current->thread.evr[fc] = vc.wp[0];
regs->gpr[fc] = vc.wp[1];
pr_debug("ccr = %08lx\n", regs->ccr);
pr_debug("cur exceptions = %08x spefscr = %08lx\n",
FP_CUR_EXCEPTIONS, __FPU_FPSCR);
pr_debug("vc: %08x %08x\n", vc.wp[0], vc.wp[1]);
pr_debug("va: %08x %08x\n", va.wp[0], va.wp[1]);
pr_debug("vb: %08x %08x\n", vb.wp[0], vb.wp[1]);
return 0;
illegal:
if (have_e500_cpu_a005_erratum) {
regs->nip -= 4;
pr_debug("re-issue efp inst: %08lx\n", speinsn);
return 0;
}
printk(KERN_ERR "\nOoops! IEEE-754 compliance handler encountered un-supported instruction.\ninst code: %08lx\n", speinsn);
return -ENOSYS;
}
int speround_handler(struct pt_regs *regs)
{
union dw_union fgpr;
int s_lo, s_hi;
unsigned long speinsn, type, fc;
if (get_user(speinsn, (unsigned int __user *) regs->nip))
return -EFAULT;
if ((speinsn >> 26) != 4)
return -EINVAL;
type = insn_type(speinsn & 0x7ff);
if (type == XCR) return -ENOSYS;
__FPU_FPSCR = mfspr(SPRN_SPEFSCR);
pr_debug("speinsn:%08lx spefscr:%08lx\n", speinsn, __FPU_FPSCR);
if (!(__FPU_FPSCR & FP_EX_INEXACT))
return 0;
fc = (speinsn >> 21) & 0x1f;
s_lo = regs->gpr[fc] & SIGN_BIT_S;
s_hi = current->thread.evr[fc] & SIGN_BIT_S;
fgpr.wp[0] = current->thread.evr[fc];
fgpr.wp[1] = regs->gpr[fc];
pr_debug("round fgpr: %08x %08x\n", fgpr.wp[0], fgpr.wp[1]);
switch ((speinsn >> 5) & 0x7) {
case SPFP:
if ((FP_ROUNDMODE) == FP_RND_PINF) {
if (!s_lo) fgpr.wp[1]++;
} else {
if (s_lo) fgpr.wp[1]++;
}
break;
case DPFP:
if (FP_ROUNDMODE == FP_RND_PINF) {
if (!s_hi) fgpr.dp[0]++;
} else {
if (s_hi) fgpr.dp[0]++;
}
break;
case VCT:
if (FP_ROUNDMODE == FP_RND_PINF) {
if (!s_lo) fgpr.wp[1]++;
if (!s_hi) fgpr.wp[0]++;
} else {
if (s_lo) fgpr.wp[1]++;
if (s_hi) fgpr.wp[0]++;
}
break;
default:
return -EINVAL;
}
current->thread.evr[fc] = fgpr.wp[0];
regs->gpr[fc] = fgpr.wp[1];
pr_debug(" to fgpr: %08x %08x\n", fgpr.wp[0], fgpr.wp[1]);
return 0;
}
int __init spe_mathemu_init(void)
{
u32 pvr, maj, min;
pvr = mfspr(SPRN_PVR);
if ((PVR_VER(pvr) == PVR_VER_E500V1) ||
(PVR_VER(pvr) == PVR_VER_E500V2)) {
maj = PVR_MAJ(pvr);
min = PVR_MIN(pvr);
switch (maj) {
case 1:
if (min < 1)
have_e500_cpu_a005_erratum = 1;
break;
case 2:
if (min < 3)
have_e500_cpu_a005_erratum = 1;
break;
case 3:
case 4:
case 5:
if (min < 1)
have_e500_cpu_a005_erratum = 1;
break;
default:
break;
}
}
return 0;
}
