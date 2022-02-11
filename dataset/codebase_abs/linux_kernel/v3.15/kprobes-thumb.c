static void T_1
F_1 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 ;
int V_8 = ( V_1 >> 16 ) & 0xf ;
int V_9 = V_1 & 0xf ;
unsigned long V_10 = ( V_8 == 15 ) ? V_6 : V_5 -> V_11 [ V_8 ] ;
unsigned long V_12 = V_5 -> V_11 [ V_9 ] ;
unsigned int V_13 ;
if ( V_1 & 0x10 )
V_13 = ( ( V_14 * ) V_10 ) [ V_12 ] ;
else
V_13 = ( ( V_15 * ) V_10 ) [ V_12 ] ;
V_5 -> V_7 = V_6 + 2 * V_13 ;
}
static void T_1
F_2 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_16 = ( V_1 >> 8 ) & 0xf ;
unsigned long V_17 = 0xf8ff03df ;
V_5 -> V_11 [ V_16 ] = V_5 -> V_18 & V_17 ;
}
static void T_1
F_3 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 ;
long V_19 = V_1 & 0x7ff ;
V_19 += ( V_1 & 0x003f0000 ) >> 5 ;
V_19 += ( V_1 & 0x00002000 ) << 4 ;
V_19 += ( V_1 & 0x00000800 ) << 7 ;
V_19 -= ( V_1 & 0x04000000 ) >> 7 ;
V_5 -> V_7 = V_6 + ( V_19 * 2 ) ;
}
static enum V_20 T_1
F_4 ( T_2 V_1 , struct V_2 * V_3 ,
const struct V_21 * V_22 )
{
int V_23 = ( V_1 >> 22 ) & 0xf ;
V_3 -> V_24 = V_25 [ V_23 ] ;
V_3 -> V_26 = F_3 ;
return V_27 ;
}
static void T_1
F_5 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 ;
long V_19 = V_1 & 0x7ff ;
V_19 += ( V_1 & 0x03ff0000 ) >> 5 ;
V_19 += ( V_1 & 0x00002000 ) << 9 ;
V_19 += ( V_1 & 0x00000800 ) << 10 ;
if ( V_1 & 0x04000000 )
V_19 -= 0x00800000 ;
else
V_19 ^= 0x00600000 ;
if ( V_1 & ( 1 << 14 ) ) {
V_5 -> V_28 = V_5 -> V_7 | 1 ;
if ( ! ( V_1 & ( 1 << 12 ) ) ) {
V_5 -> V_18 &= ~ V_29 ;
V_6 &= ~ 3 ;
}
}
V_5 -> V_7 = V_6 + ( V_19 * 2 ) ;
}
static void T_1
F_6 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_30 = V_5 -> V_7 & ~ 3 ;
int V_31 = ( V_1 >> 12 ) & 0xf ;
unsigned long V_32 ;
long V_19 = V_1 & 0xfff ;
if ( V_1 & 0x00800000 )
V_30 += V_19 ;
else
V_30 -= V_19 ;
if ( V_1 & 0x00400000 ) {
V_32 = * ( unsigned long * ) V_30 ;
if ( V_31 == 15 ) {
F_7 ( V_32 , V_5 ) ;
return;
}
} else if ( V_1 & 0x00200000 ) {
if ( V_1 & 0x01000000 )
V_32 = * ( V_33 * ) V_30 ;
else
V_32 = * ( V_14 * ) V_30 ;
} else {
if ( V_1 & 0x01000000 )
V_32 = * ( V_34 * ) V_30 ;
else
V_32 = * ( V_15 * ) V_30 ;
}
V_5 -> V_11 [ V_31 ] = V_32 ;
}
static enum V_20 T_1
F_8 ( T_2 V_1 , struct V_2 * V_3 ,
const struct V_21 * V_22 )
{
enum V_20 V_35 = F_9 ( V_1 , V_3 , V_22 ) ;
V_1 = F_10 ( V_3 -> V_1 [ 0 ] ) ;
( ( V_14 * ) V_3 -> V_1 ) [ 0 ] = F_11 ( V_1 >> 16 ) ;
( ( V_14 * ) V_3 -> V_1 ) [ 1 ] = F_11 ( V_1 & 0xffff ) ;
return V_35 ;
}
static void T_1
F_12 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 & ~ 3 ;
int V_36 = ( V_1 >> 12 ) & 0xf ;
int V_37 = ( V_1 >> 8 ) & 0xf ;
int V_8 = ( V_1 >> 16 ) & 0xf ;
register unsigned long T_3 V_38 ( L_1 ) = V_5 -> V_11 [ V_36 ] ;
register unsigned long T_4 V_38 ( L_2 ) = V_5 -> V_11 [ V_37 ] ;
register unsigned long V_10 V_38 ( L_3 ) = ( V_8 == 15 ) ? V_6
: V_5 -> V_11 [ V_8 ] ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rt1v), "=r" (rt2v), "=r" (rnv)
: "0" (rt1v), "1" (rt2v), "2" (rnv), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
if ( V_8 != 15 )
V_5 -> V_11 [ V_8 ] = V_10 ;
V_5 -> V_11 [ V_36 ] = T_3 ;
V_5 -> V_11 [ V_37 ] = T_4 ;
}
static void T_1
F_13 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_31 = ( V_1 >> 12 ) & 0xf ;
int V_8 = ( V_1 >> 16 ) & 0xf ;
int V_9 = V_1 & 0xf ;
register unsigned long V_32 V_38 ( L_1 ) = V_5 -> V_11 [ V_31 ] ;
register unsigned long V_10 V_38 ( L_3 ) = V_5 -> V_11 [ V_8 ] ;
register unsigned long V_12 V_38 ( L_4 ) = V_5 -> V_11 [ V_9 ] ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rtv), "=r" (rnv)
: "0" (rtv), "1" (rnv), "r" (rmv), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_11 [ V_8 ] = V_10 ;
if ( V_31 == 15 )
F_7 ( V_32 , V_5 ) ;
else
V_5 -> V_11 [ V_31 ] = V_32 ;
}
static void T_1
F_14 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_16 = ( V_1 >> 8 ) & 0xf ;
int V_8 = ( V_1 >> 16 ) & 0xf ;
int V_9 = V_1 & 0xf ;
register unsigned long T_5 V_38 ( L_2 ) = V_5 -> V_11 [ V_16 ] ;
register unsigned long V_10 V_38 ( L_3 ) = V_5 -> V_11 [ V_8 ] ;
register unsigned long V_12 V_38 ( L_4 ) = V_5 -> V_11 [ V_9 ] ;
unsigned long V_39 = V_5 -> V_18 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"blx %[fn] \n\t"
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv),
"1" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_11 [ V_16 ] = T_5 ;
V_5 -> V_18 = ( V_5 -> V_18 & ~ V_40 ) | ( V_39 & V_40 ) ;
}
static void T_1
F_15 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 ;
int V_16 = ( V_1 >> 8 ) & 0xf ;
register unsigned long T_5 V_38 ( L_2 ) = V_5 -> V_11 [ V_16 ] ;
register unsigned long V_10 V_38 ( L_3 ) = V_6 & ~ 3 ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rdv)
: "0" (rdv), "r" (rnv), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_11 [ V_16 ] = T_5 ;
}
static void T_1
F_16 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_16 = ( V_1 >> 8 ) & 0xf ;
int V_8 = ( V_1 >> 16 ) & 0xf ;
register unsigned long T_5 V_38 ( L_2 ) = V_5 -> V_11 [ V_16 ] ;
register unsigned long V_10 V_38 ( L_3 ) = V_5 -> V_11 [ V_8 ] ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rdv)
: "0" (rdv), "r" (rnv), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_11 [ V_16 ] = T_5 ;
}
static void T_1
F_17 ( T_2 V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_41 = ( V_1 >> 12 ) & 0xf ;
int V_42 = ( V_1 >> 8 ) & 0xf ;
int V_8 = ( V_1 >> 16 ) & 0xf ;
int V_9 = V_1 & 0xf ;
register unsigned long T_6 V_38 ( L_1 ) = V_5 -> V_11 [ V_41 ] ;
register unsigned long T_7 V_38 ( L_2 ) = V_5 -> V_11 [ V_42 ] ;
register unsigned long V_10 V_38 ( L_3 ) = V_5 -> V_11 [ V_8 ] ;
register unsigned long V_12 V_38 ( L_4 ) = V_5 -> V_11 [ V_9 ] ;
__asm__ __volatile__ (
"blx %[fn]"
: "=r" (rdlov), "=r" (rdhiv)
: "0" (rdlov), "1" (rdhiv), "r" (rnv), "r" (rmv),
[fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_11 [ V_41 ] = T_6 ;
V_5 -> V_11 [ V_42 ] = T_7 ;
}
static void T_1
F_18 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 + 2 ;
int V_9 = ( V_1 >> 3 ) & 0xf ;
unsigned long V_12 = ( V_9 == 15 ) ? V_6 : V_5 -> V_11 [ V_9 ] ;
if ( V_1 & ( 1 << 7 ) )
V_5 -> V_28 = V_5 -> V_7 | 1 ;
F_7 ( V_12 , V_5 ) ;
}
static void T_1
F_19 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long * V_43 = ( unsigned long * ) ( ( V_5 -> V_7 + 2 ) & ~ 3 ) ;
long V_44 = V_1 & 0xff ;
int V_31 = ( V_1 >> 8 ) & 0x7 ;
V_5 -> V_11 [ V_31 ] = V_43 [ V_44 ] ;
}
static void T_1
F_20 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long * V_43 = ( unsigned long * ) V_5 -> V_45 ;
long V_44 = V_1 & 0xff ;
int V_31 = ( V_1 >> 8 ) & 0x7 ;
if ( V_1 & 0x800 )
V_5 -> V_11 [ V_31 ] = V_43 [ V_44 ] ;
else
V_43 [ V_44 ] = V_5 -> V_11 [ V_31 ] ;
}
static void T_1
F_21 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_43 = ( V_1 & 0x800 ) ? V_5 -> V_45
: ( ( V_5 -> V_7 + 2 ) & ~ 3 ) ;
long V_19 = V_1 & 0xff ;
int V_31 = ( V_1 >> 8 ) & 0x7 ;
V_5 -> V_11 [ V_31 ] = V_43 + V_19 * 4 ;
}
static void T_1
F_22 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
long V_46 = V_1 & 0x7f ;
if ( V_1 & 0x80 )
V_5 -> V_45 -= V_46 * 4 ;
else
V_5 -> V_45 += V_46 * 4 ;
}
static void T_1
F_23 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_8 = V_1 & 0x7 ;
T_2 V_47 = V_5 -> V_11 [ V_8 ] ? V_1 : ~ V_1 ;
if ( V_47 & 0x800 ) {
long V_48 = V_1 & 0x200 ;
long V_49 = V_1 & 0xf8 ;
unsigned long V_6 = V_5 -> V_7 + 2 ;
V_5 -> V_7 = V_6 + ( V_48 >> 3 ) + ( V_49 >> 2 ) ;
}
}
static void T_1
F_24 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_39 = V_5 -> V_18 ;
V_39 &= ~ V_50 ;
V_39 |= ( V_1 & 0xfc ) << 8 ;
V_39 |= ( V_1 & 0x03 ) << 25 ;
V_5 -> V_18 = V_39 ;
}
static void T_1
F_25 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
V_5 -> V_7 += 2 ;
F_24 ( V_1 , V_3 , V_5 ) ;
}
static enum V_20 T_1
F_26 ( T_2 V_1 , struct V_2 * V_3 ,
const struct V_21 * V_22 )
{
V_3 -> V_51 = F_25 ;
return V_27 ;
}
static void T_1
F_27 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 + 2 ;
long V_19 = V_1 & 0x7f ;
V_19 -= V_1 & 0x80 ;
V_5 -> V_7 = V_6 + ( V_19 * 2 ) ;
}
static enum V_20 T_1
F_28 ( T_2 V_1 , struct V_2 * V_3 ,
const struct V_21 * V_22 )
{
int V_23 = ( V_1 >> 8 ) & 0xf ;
V_3 -> V_24 = V_25 [ V_23 ] ;
V_3 -> V_26 = F_27 ;
return V_27 ;
}
static void T_1
F_29 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 + 2 ;
long V_19 = V_1 & 0x3ff ;
V_19 -= V_1 & 0x400 ;
V_5 -> V_7 = V_6 + ( V_19 * 2 ) ;
}
static unsigned long T_1
F_30 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_52 = V_5 -> V_18 ;
unsigned long V_53 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[oldcpsr] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"stmia %[regs], {r0-r7} \n\t"
"mrs %[newcpsr], cpsr \n\t"
: [newcpsr] "=r" (newcpsr)
: [oldcpsr] "r" (oldcpsr), [regs] "r" (regs),
[fn] "r" (asi->insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",
"lr", "memory", "cc"
);
return ( V_52 & ~ V_40 ) | ( V_53 & V_40 ) ;
}
static void T_1
F_31 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
V_5 -> V_18 = F_30 ( V_1 , V_3 , V_5 ) ;
}
static void T_1
F_32 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_39 = F_30 ( V_1 , V_3 , V_5 ) ;
if ( ! F_33 ( V_39 ) )
V_5 -> V_18 = V_39 ;
}
static void T_1
F_34 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 + 2 ;
int V_54 = ( V_1 & 0x7 ) | ( ( V_1 & 0x80 ) >> 4 ) ;
int V_9 = ( V_1 >> 3 ) & 0xf ;
register unsigned long T_8 V_38 ( L_2 ) ;
register unsigned long V_12 V_38 ( L_1 ) ;
unsigned long V_39 = V_5 -> V_18 ;
T_8 = ( V_54 == 15 ) ? V_6 : V_5 -> V_11 [ V_54 ] ;
V_12 = ( V_9 == 15 ) ? V_6 : V_5 -> V_11 [ V_9 ] ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"blx %[fn] \n\t"
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdnv), [cpsr] "=r" (cpsr)
: "0" (rdnv), "r" (rmv), "1" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
if ( V_54 == 15 )
T_8 &= ~ 1 ;
V_5 -> V_11 [ V_54 ] = T_8 ;
V_5 -> V_18 = ( V_5 -> V_18 & ~ V_40 ) | ( V_39 & V_40 ) ;
}
static enum V_20 T_1
F_35 ( T_2 V_1 , struct V_2 * V_3 ,
const struct V_21 * V_22 )
{
V_1 &= ~ 0x00ff ;
V_1 |= 0x001 ;
( ( V_14 * ) V_3 -> V_1 ) [ 0 ] = F_11 ( V_1 ) ;
V_3 -> V_26 = F_34 ;
return V_55 ;
}
static void T_1
F_36 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
__asm__ __volatile__ (
"ldr r9, [%[regs], #13*4] \n\t"
"ldr r8, [%[regs], #14*4] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"str r9, [%[regs], #13*4] \n\t"
:
: [regs] "r" (regs), [fn] "r" (asi->insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9",
"lr", "memory", "cc"
);
}
static enum V_20 T_1
F_37 ( T_2 V_1 , struct V_2 * V_3 ,
const struct V_21 * V_22 )
{
( ( V_14 * ) V_3 -> V_1 ) [ 0 ] = F_11 ( 0xe929 ) ;
( ( V_14 * ) V_3 -> V_1 ) [ 1 ] = F_11 ( V_1 & 0x1ff ) ;
V_3 -> V_26 = F_36 ;
return V_55 ;
}
static void T_1
F_38 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
__asm__ __volatile__ (
"ldr r9, [%[regs], #13*4] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"stmia %[regs], {r0-r7} \n\t"
"str r9, [%[regs], #13*4] \n\t"
:
: [regs] "r" (regs), [fn] "r" (asi->insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r9",
"lr", "memory", "cc"
);
}
static void T_1
F_39 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
register unsigned long V_6 V_38 ( L_5 ) ;
__asm__ __volatile__ (
"ldr r9, [%[regs], #13*4] \n\t"
"ldmia %[regs], {r0-r7} \n\t"
"blx %[fn] \n\t"
"stmia %[regs], {r0-r7} \n\t"
"str r9, [%[regs], #13*4] \n\t"
: "=r" (pc)
: [regs] "r" (regs), [fn] "r" (asi->insn_fn)
: "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r9",
"lr", "memory", "cc"
);
F_7 ( V_6 , V_5 ) ;
}
static enum V_20 T_1
F_40 ( T_2 V_1 , struct V_2 * V_3 ,
const struct V_21 * V_22 )
{
( ( V_14 * ) V_3 -> V_1 ) [ 0 ] = F_11 ( 0xe8b9 ) ;
( ( V_14 * ) V_3 -> V_1 ) [ 1 ] = F_11 ( V_1 & 0x1ff ) ;
V_3 -> V_26 = V_1 & 0x100 ? F_39
: F_38 ;
return V_55 ;
}
