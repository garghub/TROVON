u_int
decode_fpu(unsigned int Fpu_register[], unsigned int trap_counts[])
{
unsigned int current_ir, excp;
int target, exception_index = 1;
boolean inexact;
unsigned int aflags;
unsigned int bflags;
unsigned int excptype;
bflags=(Fpu_register[0] & 0xf8000000);
Fpu_register[0] &= 0x07ffffff;
if (!Is_tbit_set()) {
update_trap_counts(Fpu_register, aflags, bflags, trap_counts);
return SIGNALCODE(SIGILL, ILL_COPROC);
}
for (exception_index=1; exception_index<=MAX_EXCP_REG; exception_index++) {
current_ir = Excp_instr(exception_index);
excptype = Excp_type(exception_index);
if (excptype & UNIMPLEMENTEDEXCEPTION) {
Clear_tbit();
Clear_excp_register(exception_index);
excp = fpudispatch(current_ir,excptype,0,Fpu_register);
if (excp) {
Set_tbit();
Set_exceptiontype_and_instr_field(excp,current_ir,
Fpu_register[exception_index]);
if (excp == UNIMPLEMENTEDEXCEPTION) {
excp = excptype;
update_trap_counts(Fpu_register, aflags, bflags,
trap_counts);
return SIGNALCODE(SIGILL, ILL_COPROC);
}
excptype = excp;
}
if (excp == NOEXCEPTION)
break;
}
if (excptype & UNDERFLOWEXCEPTION) {
if (Is_underflowtrap_enabled()) {
update_trap_counts(Fpu_register, aflags, bflags,
trap_counts);
return SIGNALCODE(SIGFPE, FPE_FLTUND);
} else {
target = current_ir & fivebits;
#ifndef lint
if (Ibit(Fpu_register[exception_index])) inexact = TRUE;
else inexact = FALSE;
#endif
switch (Excp_format()) {
case SGL:
if (Rabit(Fpu_register[exception_index]))
Sgl_decrement(Fpu_sgl(target));
sgl_denormalize(&Fpu_sgl(target),&inexact,Rounding_mode());
break;
case DBL:
if (Rabit(Fpu_register[exception_index]))
Dbl_decrement(Fpu_dblp1(target),Fpu_dblp2(target));
dbl_denormalize(&Fpu_dblp1(target),&Fpu_dblp2(target),
&inexact,Rounding_mode());
break;
}
if (inexact) Set_underflowflag();
if (inexact && Is_inexacttrap_enabled()) {
Set_exceptiontype(Fpu_register[exception_index],
INEXACTEXCEPTION);
Set_parmfield(Fpu_register[exception_index],0);
update_trap_counts(Fpu_register, aflags, bflags,
trap_counts);
return SIGNALCODE(SIGFPE, FPE_FLTRES);
}
else {
Clear_excp_register(exception_index);
if (inexact) Set_inexactflag();
}
}
continue;
}
switch(Excp_type(exception_index)) {
case OVERFLOWEXCEPTION:
case OVERFLOWEXCEPTION | INEXACTEXCEPTION:
update_trap_counts(Fpu_register, aflags, bflags,
trap_counts);
if (Is_overflowtrap_enabled()) {
update_trap_counts(Fpu_register, aflags, bflags,
trap_counts);
return SIGNALCODE(SIGFPE, FPE_FLTOVF);
} else {
target = current_ir & fivebits;
switch (Excp_format()) {
case SGL:
Sgl_setoverflow(Fpu_sgl(target));
break;
case DBL:
Dbl_setoverflow(Fpu_dblp1(target),Fpu_dblp2(target));
break;
}
Set_overflowflag();
if (Is_inexacttrap_enabled()) {
Set_exceptiontype(Fpu_register[exception_index],
INEXACTEXCEPTION);
update_trap_counts(Fpu_register, aflags, bflags,
trap_counts);
return SIGNALCODE(SIGFPE, FPE_FLTRES);
}
else {
Clear_excp_register(exception_index);
Set_inexactflag();
}
}
break;
case INVALIDEXCEPTION:
case OPC_2E_INVALIDEXCEPTION:
update_trap_counts(Fpu_register, aflags, bflags, trap_counts);
return SIGNALCODE(SIGFPE, FPE_FLTINV);
case DIVISIONBYZEROEXCEPTION:
update_trap_counts(Fpu_register, aflags, bflags, trap_counts);
Clear_excp_register(exception_index);
return SIGNALCODE(SIGFPE, FPE_FLTDIV);
case INEXACTEXCEPTION:
update_trap_counts(Fpu_register, aflags, bflags, trap_counts);
return SIGNALCODE(SIGFPE, FPE_FLTRES);
default:
update_trap_counts(Fpu_register, aflags, bflags, trap_counts);
printk("%s(%d) Unknown FPU exception 0x%x\n", __FILE__,
__LINE__, Excp_type(exception_index));
return SIGNALCODE(SIGILL, ILL_COPROC);
case NOEXCEPTION:
Clear_excp_register(exception_index);
break;
}
}
Clear_tbit();
update_trap_counts(Fpu_register, aflags, bflags, trap_counts);
return(NOTRAP);
}
