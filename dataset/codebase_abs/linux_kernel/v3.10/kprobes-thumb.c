static inline unsigned long T_1 F_1 ( struct V_1 * V_2 )
{
return ( unsigned long ) V_2 -> V_3 - 1 + 4 ;
}
static void T_1
F_2 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_1 ( V_2 ) ;
int V_9 = ( V_6 >> 16 ) & 0xf ;
int V_10 = V_6 & 0xf ;
unsigned long V_11 = ( V_9 == 15 ) ? V_8 : V_5 -> V_12 [ V_9 ] ;
unsigned long V_13 = V_5 -> V_12 [ V_10 ] ;
unsigned int V_14 ;
if ( V_6 & 0x10 )
V_14 = ( ( V_15 * ) V_11 ) [ V_13 ] ;
else
V_14 = ( ( V_16 * ) V_11 ) [ V_13 ] ;
V_5 -> V_17 = V_8 + 2 * V_14 ;
}
static void T_1
F_3 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
int V_18 = ( V_6 >> 8 ) & 0xf ;
unsigned long V_19 = 0xf8ff03df ;
V_5 -> V_12 [ V_18 ] = V_5 -> V_20 & V_19 ;
}
static void T_1
F_4 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_1 ( V_2 ) ;
long V_21 = V_6 & 0x7ff ;
V_21 += ( V_6 & 0x003f0000 ) >> 5 ;
V_21 += ( V_6 & 0x00002000 ) << 4 ;
V_21 += ( V_6 & 0x00000800 ) << 7 ;
V_21 -= ( V_6 & 0x04000000 ) >> 7 ;
V_5 -> V_17 = V_8 + ( V_21 * 2 ) ;
}
static enum V_22 T_1
F_5 ( T_2 V_6 , struct V_23 * V_24 )
{
int V_25 = ( V_6 >> 22 ) & 0xf ;
V_24 -> V_26 = V_27 [ V_25 ] ;
V_24 -> V_28 = F_4 ;
return V_29 ;
}
static void T_1
F_6 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_1 ( V_2 ) ;
long V_21 = V_6 & 0x7ff ;
V_21 += ( V_6 & 0x03ff0000 ) >> 5 ;
V_21 += ( V_6 & 0x00002000 ) << 9 ;
V_21 += ( V_6 & 0x00000800 ) << 10 ;
if ( V_6 & 0x04000000 )
V_21 -= 0x00800000 ;
else
V_21 ^= 0x00600000 ;
if ( V_6 & ( 1 << 14 ) ) {
V_5 -> V_30 = ( unsigned long ) V_2 -> V_3 + 4 ;
if ( ! ( V_6 & ( 1 << 12 ) ) ) {
V_5 -> V_20 &= ~ V_31 ;
V_8 &= ~ 3 ;
}
}
V_5 -> V_17 = V_8 + ( V_21 * 2 ) ;
}
static void T_1
F_7 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_3 = F_1 ( V_2 ) & ~ 3 ;
int V_32 = ( V_6 >> 12 ) & 0xf ;
unsigned long V_33 ;
long V_21 = V_6 & 0xfff ;
if ( V_6 & 0x00800000 )
V_3 += V_21 ;
else
V_3 -= V_21 ;
if ( V_6 & 0x00400000 ) {
V_33 = * ( unsigned long * ) V_3 ;
if ( V_32 == 15 ) {
F_8 ( V_33 , V_5 ) ;
return;
}
} else if ( V_6 & 0x00200000 ) {
if ( V_6 & 0x01000000 )
V_33 = * ( V_34 * ) V_3 ;
else
V_33 = * ( V_15 * ) V_3 ;
} else {
if ( V_6 & 0x01000000 )
V_33 = * ( V_35 * ) V_3 ;
else
V_33 = * ( V_16 * ) V_3 ;
}
V_5 -> V_12 [ V_32 ] = V_33 ;
}
static enum V_22 T_1
F_9 ( T_2 V_6 , struct V_23 * V_24 )
{
enum V_22 V_36 = F_10 ( V_6 , V_24 ) ;
V_6 = V_24 -> V_6 [ 0 ] ;
( ( V_15 * ) V_24 -> V_6 ) [ 0 ] = V_6 >> 16 ;
( ( V_15 * ) V_24 -> V_6 ) [ 1 ] = V_6 & 0xffff ;
return V_36 ;
}
static void T_1
F_11 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_1 ( V_2 ) & ~ 3 ;
int V_37 = ( V_6 >> 12 ) & 0xf ;
int V_38 = ( V_6 >> 8 ) & 0xf ;
int V_9 = ( V_6 >> 16 ) & 0xf ;
register unsigned long T_3 V_39 ( L_1 ) = V_5 -> V_12 [ V_37 ] ;
register unsigned long T_4 V_39 ( L_2 ) = V_5 -> V_12 [ V_38 ] ;
register unsigned long V_11 V_39 ( L_3 ) = ( V_9 == 15 ) ? V_8
: V_5 -> V_12 [ V_9 ] ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rt1v), "=r" (rt2v), "=r" (rnv)
: "0" (rt1v), "1" (rt2v), "2" (rnv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if ( V_9 != 15 )
V_5 -> V_12 [ V_9 ] = V_11 ;
V_5 -> V_12 [ V_37 ] = T_3 ;
V_5 -> V_12 [ V_38 ] = T_4 ;
}
static void T_1
F_12 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
int V_32 = ( V_6 >> 12 ) & 0xf ;
int V_9 = ( V_6 >> 16 ) & 0xf ;
int V_10 = V_6 & 0xf ;
register unsigned long V_33 V_39 ( L_1 ) = V_5 -> V_12 [ V_32 ] ;
register unsigned long V_11 V_39 ( L_3 ) = V_5 -> V_12 [ V_9 ] ;
register unsigned long V_13 V_39 ( L_4 ) = V_5 -> V_12 [ V_10 ] ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rtv), "=r" (rnv)
: "0" (rtv), "1" (rnv), "r" (rmv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_9 ] = V_11 ;
if ( V_32 == 15 )
F_8 ( V_33 , V_5 ) ;
else
V_5 -> V_12 [ V_32 ] = V_33 ;
}
static void T_1
F_13 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
int V_18 = ( V_6 >> 8 ) & 0xf ;
int V_9 = ( V_6 >> 16 ) & 0xf ;
int V_10 = V_6 & 0xf ;
register unsigned long T_5 V_39 ( L_2 ) = V_5 -> V_12 [ V_18 ] ;
register unsigned long V_11 V_39 ( L_3 ) = V_5 -> V_12 [ V_9 ] ;
register unsigned long V_13 V_39 ( L_4 ) = V_5 -> V_12 [ V_10 ] ;
unsigned long V_40 = V_5 -> V_20 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"blx %[fn] \n\t"
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv),
"1" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_18 ] = T_5 ;
V_5 -> V_20 = ( V_5 -> V_20 & ~ V_41 ) | ( V_40 & V_41 ) ;
}
static void T_1
F_14 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_1 ( V_2 ) ;
int V_18 = ( V_6 >> 8 ) & 0xf ;
register unsigned long T_5 V_39 ( L_2 ) = V_5 -> V_12 [ V_18 ] ;
register unsigned long V_11 V_39 ( L_3 ) = V_8 & ~ 3 ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rdv)
: "0" (rdv), "r" (rnv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_18 ] = T_5 ;
}
static void T_1
F_15 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
int V_18 = ( V_6 >> 8 ) & 0xf ;
int V_9 = ( V_6 >> 16 ) & 0xf ;
register unsigned long T_5 V_39 ( L_2 ) = V_5 -> V_12 [ V_18 ] ;
register unsigned long V_11 V_39 ( L_3 ) = V_5 -> V_12 [ V_9 ] ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rdv)
: "0" (rdv), "r" (rnv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_18 ] = T_5 ;
}
static void T_1
F_16 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
int V_42 = ( V_6 >> 12 ) & 0xf ;
int V_43 = ( V_6 >> 8 ) & 0xf ;
int V_9 = ( V_6 >> 16 ) & 0xf ;
int V_10 = V_6 & 0xf ;
register unsigned long T_6 V_39 ( L_1 ) = V_5 -> V_12 [ V_42 ] ;
register unsigned long T_7 V_39 ( L_2 ) = V_5 -> V_12 [ V_43 ] ;
register unsigned long V_11 V_39 ( L_3 ) = V_5 -> V_12 [ V_9 ] ;
register unsigned long V_13 V_39 ( L_4 ) = V_5 -> V_12 [ V_10 ] ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rdlov), "=r" (rdhiv)
: "0" (rdlov), "1" (rdhiv), "r" (rnv), "r" (rmv),
[fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_42 ] = T_6 ;
V_5 -> V_12 [ V_43 ] = T_7 ;
}
static void T_1
F_17 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_1 ( V_2 ) ;
int V_10 = ( V_6 >> 3 ) & 0xf ;
unsigned long V_13 = ( V_10 == 15 ) ? V_8 : V_5 -> V_12 [ V_10 ] ;
if ( V_6 & ( 1 << 7 ) )
V_5 -> V_30 = ( unsigned long ) V_2 -> V_3 + 2 ;
F_8 ( V_13 , V_5 ) ;
}
static void T_1
F_18 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long * V_44 = ( unsigned long * ) ( F_1 ( V_2 ) & ~ 3 ) ;
long V_45 = V_6 & 0xff ;
int V_32 = ( V_6 >> 8 ) & 0x7 ;
V_5 -> V_12 [ V_32 ] = V_44 [ V_45 ] ;
}
static void T_1
F_19 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long * V_44 = ( unsigned long * ) V_5 -> V_46 ;
long V_45 = V_6 & 0xff ;
int V_32 = ( V_6 >> 8 ) & 0x7 ;
if ( V_6 & 0x800 )
V_5 -> V_12 [ V_32 ] = V_44 [ V_45 ] ;
else
V_44 [ V_45 ] = V_5 -> V_12 [ V_32 ] ;
}
static void T_1
F_20 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_44 = ( V_6 & 0x800 ) ? V_5 -> V_46
: ( F_1 ( V_2 ) & ~ 3 ) ;
long V_21 = V_6 & 0xff ;
int V_32 = ( V_6 >> 8 ) & 0x7 ;
V_5 -> V_12 [ V_32 ] = V_44 + V_21 * 4 ;
}
static void T_1
F_21 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
long V_47 = V_6 & 0x7f ;
if ( V_6 & 0x80 )
V_5 -> V_46 -= V_47 * 4 ;
else
V_5 -> V_46 += V_47 * 4 ;
}
static void T_1
F_22 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
int V_9 = V_6 & 0x7 ;
T_2 V_48 = V_5 -> V_12 [ V_9 ] ? V_6 : ~ V_6 ;
if ( V_48 & 0x800 ) {
long V_49 = V_6 & 0x200 ;
long V_50 = V_6 & 0xf8 ;
unsigned long V_8 = F_1 ( V_2 ) ;
V_5 -> V_17 = V_8 + ( V_49 >> 3 ) + ( V_50 >> 2 ) ;
}
}
static void T_1
F_23 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_40 = V_5 -> V_20 ;
V_40 &= ~ V_51 ;
V_40 |= ( V_6 & 0xfc ) << 8 ;
V_40 |= ( V_6 & 0x03 ) << 25 ;
V_5 -> V_20 = V_40 ;
}
static void T_1
F_24 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
V_5 -> V_17 += 2 ;
F_23 ( V_2 , V_5 ) ;
}
static enum V_22 T_1
F_25 ( T_2 V_6 , struct V_23 * V_24 )
{
V_24 -> V_52 = F_24 ;
return V_29 ;
}
static void T_1
F_26 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_1 ( V_2 ) ;
long V_21 = V_6 & 0x7f ;
V_21 -= V_6 & 0x80 ;
V_5 -> V_17 = V_8 + ( V_21 * 2 ) ;
}
static enum V_22 T_1
F_27 ( T_2 V_6 , struct V_23 * V_24 )
{
int V_25 = ( V_6 >> 8 ) & 0xf ;
V_24 -> V_26 = V_27 [ V_25 ] ;
V_24 -> V_28 = F_26 ;
return V_29 ;
}
static void T_1
F_28 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_1 ( V_2 ) ;
long V_21 = V_6 & 0x3ff ;
V_21 -= V_6 & 0x400 ;
V_5 -> V_17 = V_8 + ( V_21 * 2 ) ;
}
static unsigned long T_1
F_29 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
unsigned long V_53 = V_5 -> V_20 ;
unsigned long V_54 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[oldcpsr] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"stmia %[regs], {r0-r7} \n\t"
"mrs %[newcpsr], cpsr \n\t"
: [newcpsr] "=r" (newcpsr)
: [oldcpsr] "r" (oldcpsr), [regs] "r" (regs),
[fn] "r" (p->ainsn.insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
"lr", "memory", "cc"
);
return ( V_53 & ~ V_41 ) | ( V_54 & V_41 ) ;
}
static void T_1
F_30 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
V_5 -> V_20 = F_29 ( V_2 , V_5 ) ;
}
static void T_1
F_31 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
unsigned long V_40 = F_29 ( V_2 , V_5 ) ;
if ( ! F_32 ( V_40 ) )
V_5 -> V_20 = V_40 ;
}
static void T_1
F_33 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
T_2 V_6 = V_2 -> V_7 ;
unsigned long V_8 = F_1 ( V_2 ) ;
int V_55 = ( V_6 & 0x7 ) | ( ( V_6 & 0x80 ) >> 4 ) ;
int V_10 = ( V_6 >> 3 ) & 0xf ;
register unsigned long T_8 V_39 ( L_2 ) ;
register unsigned long V_13 V_39 ( L_1 ) ;
unsigned long V_40 = V_5 -> V_20 ;
T_8 = ( V_55 == 15 ) ? V_8 : V_5 -> V_12 [ V_55 ] ;
V_13 = ( V_10 == 15 ) ? V_8 : V_5 -> V_12 [ V_10 ] ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"blx %[fn] \n\t"
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdnv), [cpsr] "=r" (cpsr)
: "0" (rdnv), "r" (rmv), "1" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if ( V_55 == 15 )
T_8 &= ~ 1 ;
V_5 -> V_12 [ V_55 ] = T_8 ;
V_5 -> V_20 = ( V_5 -> V_20 & ~ V_41 ) | ( V_40 & V_41 ) ;
}
static enum V_22 T_1
F_34 ( T_2 V_6 , struct V_23 * V_24 )
{
V_6 &= ~ 0x00ff ;
V_6 |= 0x001 ;
( ( V_15 * ) V_24 -> V_6 ) [ 0 ] = V_6 ;
V_24 -> V_28 = F_33 ;
return V_56 ;
}
static void T_1
F_35 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
__asm__ __volatile__ (
"ldr r9, [%[regs], #13*4] \n\t"
"ldr r8, [%[regs], #14*4] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"str r9, [%[regs], #13*4] \n\t"
:
: [regs] "r" (regs), [fn] "r" (p->ainsn.insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9",
"lr", "memory", "cc"
);
}
static enum V_22 T_1
F_36 ( T_2 V_6 , struct V_23 * V_24 )
{
( ( V_15 * ) V_24 -> V_6 ) [ 0 ] = 0xe929 ;
( ( V_15 * ) V_24 -> V_6 ) [ 1 ] = V_6 & 0x1ff ;
V_24 -> V_28 = F_35 ;
return V_56 ;
}
static void T_1
F_37 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
__asm__ __volatile__ (
"ldr r9, [%[regs], #13*4] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"stmia %[regs], {r0-r7} \n\t"
"str r9, [%[regs], #13*4] \n\t"
:
: [regs] "r" (regs), [fn] "r" (p->ainsn.insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r9",
"lr", "memory", "cc"
);
}
static void T_1
F_38 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
register unsigned long V_8 V_39 ( L_5 ) ;
__asm__ __volatile__ (
"ldr r9, [%[regs], #13*4] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"stmia %[regs], {r0-r7} \n\t"
"str r9, [%[regs], #13*4] \n\t"
: "=r" (pc)
: [regs] "r" (regs), [fn] "r" (p->ainsn.insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r9",
"lr", "memory", "cc"
);
F_8 ( V_8 , V_5 ) ;
}
static enum V_22 T_1
F_39 ( T_2 V_6 , struct V_23 * V_24 )
{
( ( V_15 * ) V_24 -> V_6 ) [ 0 ] = 0xe8b9 ;
( ( V_15 * ) V_24 -> V_6 ) [ 1 ] = V_6 & 0x1ff ;
V_24 -> V_28 = V_6 & 0x100 ? F_38
: F_37 ;
return V_56 ;
}
static unsigned long T_1 F_40 ( unsigned long V_40 )
{
if ( F_41 ( F_32 ( V_40 ) ) )
return V_27 [ F_42 ( V_40 ) ] ( V_40 ) ;
return true ;
}
static void T_1 F_43 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
V_5 -> V_17 += 2 ;
V_2 -> V_57 . V_28 ( V_2 , V_5 ) ;
V_5 -> V_20 = F_44 ( V_5 -> V_20 ) ;
}
static void T_1 F_45 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
V_5 -> V_17 += 4 ;
V_2 -> V_57 . V_28 ( V_2 , V_5 ) ;
V_5 -> V_20 = F_44 ( V_5 -> V_20 ) ;
}
enum V_22 T_1
F_46 ( T_2 V_6 , struct V_23 * V_24 )
{
V_24 -> V_52 = F_43 ;
V_24 -> V_26 = F_40 ;
return F_47 ( V_6 , V_24 , V_58 , true ) ;
}
enum V_22 T_1
F_48 ( T_2 V_6 , struct V_23 * V_24 )
{
V_24 -> V_52 = F_45 ;
V_24 -> V_26 = F_40 ;
return F_47 ( V_6 , V_24 , V_59 , true ) ;
}
