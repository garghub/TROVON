static int emulate_spe(struct pt_regs *regs, unsigned int reg,
unsigned int instr)
{
int ret;
union {
u64 ll;
u32 w[2];
u16 h[4];
u8 v[8];
} data, temp;
unsigned char __user *p, *addr;
unsigned long *evr = &current->thread.evr[reg];
unsigned int nb, flags;
instr = (instr >> 1) & 0x1f;
addr = (unsigned char __user *)regs->dar;
nb = spe_aligninfo[instr].len;
flags = spe_aligninfo[instr].flags;
if (unlikely(user_mode(regs) &&
!access_ok((flags & ST ? VERIFY_WRITE : VERIFY_READ),
addr, nb)))
return -EFAULT;
if (unlikely(!user_mode(regs)))
return 0;
flush_spe_to_thread(current);
if (flags & ST) {
data.ll = 0;
switch (instr) {
case EVSTDD:
case EVSTDW:
case EVSTDH:
data.w[0] = *evr;
data.w[1] = regs->gpr[reg];
break;
case EVSTWHE:
data.h[2] = *evr >> 16;
data.h[3] = regs->gpr[reg] >> 16;
break;
case EVSTWHO:
data.h[2] = *evr & 0xffff;
data.h[3] = regs->gpr[reg] & 0xffff;
break;
case EVSTWWE:
data.w[1] = *evr;
break;
case EVSTWWO:
data.w[1] = regs->gpr[reg];
break;
default:
return -EINVAL;
}
} else {
temp.ll = data.ll = 0;
ret = 0;
p = addr;
switch (nb) {
case 8:
ret |= __get_user_inatomic(temp.v[0], p++);
ret |= __get_user_inatomic(temp.v[1], p++);
ret |= __get_user_inatomic(temp.v[2], p++);
ret |= __get_user_inatomic(temp.v[3], p++);
case 4:
ret |= __get_user_inatomic(temp.v[4], p++);
ret |= __get_user_inatomic(temp.v[5], p++);
case 2:
ret |= __get_user_inatomic(temp.v[6], p++);
ret |= __get_user_inatomic(temp.v[7], p++);
if (unlikely(ret))
return -EFAULT;
}
switch (instr) {
case EVLDD:
case EVLDW:
case EVLDH:
data.ll = temp.ll;
break;
case EVLHHESPLAT:
data.h[0] = temp.h[3];
data.h[2] = temp.h[3];
break;
case EVLHHOUSPLAT:
case EVLHHOSSPLAT:
data.h[1] = temp.h[3];
data.h[3] = temp.h[3];
break;
case EVLWHE:
data.h[0] = temp.h[2];
data.h[2] = temp.h[3];
break;
case EVLWHOU:
case EVLWHOS:
data.h[1] = temp.h[2];
data.h[3] = temp.h[3];
break;
case EVLWWSPLAT:
data.w[0] = temp.w[1];
data.w[1] = temp.w[1];
break;
case EVLWHSPLAT:
data.h[0] = temp.h[2];
data.h[1] = temp.h[2];
data.h[2] = temp.h[3];
data.h[3] = temp.h[3];
break;
default:
return -EINVAL;
}
}
if (flags & SW) {
switch (flags & 0xf0) {
case E8:
data.ll = swab64(data.ll);
break;
case E4:
data.w[0] = swab32(data.w[0]);
data.w[1] = swab32(data.w[1]);
break;
default:
data.h[0] = swab16(data.h[0]);
data.h[1] = swab16(data.h[1]);
data.h[2] = swab16(data.h[2]);
data.h[3] = swab16(data.h[3]);
break;
}
}
if (flags & SE) {
data.w[0] = (s16)data.h[1];
data.w[1] = (s16)data.h[3];
}
if (flags & ST) {
ret = 0;
p = addr;
switch (nb) {
case 8:
ret |= __put_user_inatomic(data.v[0], p++);
ret |= __put_user_inatomic(data.v[1], p++);
ret |= __put_user_inatomic(data.v[2], p++);
ret |= __put_user_inatomic(data.v[3], p++);
case 4:
ret |= __put_user_inatomic(data.v[4], p++);
ret |= __put_user_inatomic(data.v[5], p++);
case 2:
ret |= __put_user_inatomic(data.v[6], p++);
ret |= __put_user_inatomic(data.v[7], p++);
}
if (unlikely(ret))
return -EFAULT;
} else {
*evr = data.w[0];
regs->gpr[reg] = data.w[1];
}
return 1;
}
int fix_alignment(struct pt_regs *regs)
{
unsigned int instr;
struct instruction_op op;
int r, type;
CHECK_FULL_REGS(regs);
if (unlikely(__get_user(instr, (unsigned int __user *)regs->nip)))
return -EFAULT;
if ((regs->msr & MSR_LE) != (MSR_KERNEL & MSR_LE)) {
if (cpu_has_feature(CPU_FTR_PPC_LE))
return -EIO;
instr = swab32(instr);
}
#ifdef CONFIG_SPE
if ((instr >> 26) == 0x4) {
int reg = (instr >> 21) & 0x1f;
PPC_WARN_ALIGNMENT(spe, regs);
return emulate_spe(regs, reg, instr);
}
#endif
if ((instr & 0xfc0006fe) == (PPC_INST_COPY & 0xfc0006fe))
return -EIO;
r = analyse_instr(&op, regs, instr);
if (r < 0)
return -EINVAL;
type = op.type & INSTR_TYPE_MASK;
if (!OP_IS_LOAD_STORE(type)) {
if (op.type != CACHEOP + DCBZ)
return -EINVAL;
PPC_WARN_ALIGNMENT(dcbz, regs);
r = emulate_dcbz(op.ea, regs);
} else {
if (type == LARX || type == STCX)
return -EIO;
PPC_WARN_ALIGNMENT(unaligned, regs);
r = emulate_loadstore(regs, &op);
}
if (!r)
return 1;
return r;
}
