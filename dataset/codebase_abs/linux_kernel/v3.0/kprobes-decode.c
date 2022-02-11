static void T_1 F_1 ( void )
{
int V_1 , V_2 , V_3 ;
__asm__ (
"sub %[ret], pc, #4 \n\t"
"str pc, %[addr] \n\t"
"ldr %[scr], %[addr] \n\t"
"sub %[ret], %[scr], %[ret] \n\t"
: [ret] "=r" (ret), [scr] "=r" (scratch), [addr] "+m" (addr));
V_4 = V_3 ;
}
static inline long T_2
F_2 ( long V_5 , T_3 * V_6 )
{
register long V_3 V_7 ( L_1 ) ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
: "=r" (ret)
: [cpsr] "r" (cpsr), [fn] "r" (fn)
: "lr", "cc"
);
return V_3 ;
}
static inline long long T_2
F_3 ( long V_5 , T_4 * V_6 )
{
register long T_5 V_7 ( L_1 ) ;
register long T_6 V_7 ( L_2 ) ;
union V_8 V_9 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
: "=r" (ret0), "=r" (ret1)
: [cpsr] "r" (cpsr), [fn] "r" (fn)
: "lr", "cc"
);
V_9 . V_10 = T_5 ;
V_9 . V_11 = T_6 ;
return V_9 . V_12 ;
}
static inline long T_2
F_4 ( long V_10 , long V_5 , T_7 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long V_3 V_7 ( L_1 ) ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
: "=r" (ret)
: "0" (rr0), [cpsr] "r" (cpsr), [fn] "r" (fn)
: "lr", "cc"
);
return V_3 ;
}
static inline long T_2
F_5 ( long V_10 , long V_11 , long V_5 , T_9 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long T_10 V_7 ( L_2 ) = V_11 ;
register long V_3 V_7 ( L_1 ) ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
: "=r" (ret)
: "0" (rr0), "r" (rr1),
[cpsr] "r" (cpsr), [fn] "r" (fn)
: "lr", "cc"
);
return V_3 ;
}
static inline long T_2
F_6 ( long V_10 , long V_11 , long V_13 , long V_5 , T_11 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long T_10 V_7 ( L_2 ) = V_11 ;
register long T_12 V_7 ( L_3 ) = V_13 ;
register long V_3 V_7 ( L_1 ) ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
: "=r" (ret)
: "0" (rr0), "r" (rr1), "r" (rr2),
[cpsr] "r" (cpsr), [fn] "r" (fn)
: "lr", "cc"
);
return V_3 ;
}
static inline long long T_2
F_7 ( long V_10 , long V_11 , long V_13 , long V_5 ,
T_13 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long T_10 V_7 ( L_2 ) = V_11 ;
register long T_12 V_7 ( L_3 ) = V_13 ;
register long T_5 V_7 ( L_1 ) ;
register long T_6 V_7 ( L_2 ) ;
union V_8 V_9 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
: "=r" (ret0), "=r" (ret1)
: "0" (rr0), "r" (rr1), "r" (rr2),
[cpsr] "r" (cpsr), [fn] "r" (fn)
: "lr", "cc"
);
V_9 . V_10 = T_5 ;
V_9 . V_11 = T_6 ;
return V_9 . V_12 ;
}
static inline long T_2
F_8 ( long V_10 , long V_11 , long V_13 , long V_14 , long V_5 ,
T_14 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long T_10 V_7 ( L_2 ) = V_11 ;
register long T_12 V_7 ( L_3 ) = V_13 ;
register long T_15 V_7 ( L_4 ) = V_14 ;
register long V_3 V_7 ( L_1 ) ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
: "=r" (ret)
: "0" (rr0), "r" (rr1), "r" (rr2), "r" (rr3),
[cpsr] "r" (cpsr), [fn] "r" (fn)
: "lr", "cc"
);
return V_3 ;
}
static inline long T_2
F_9 ( long V_10 , long * V_5 , T_7 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long V_3 V_7 ( L_1 ) ;
long V_15 = * V_5 ;
long V_16 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[oldcpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
"mrs %[newcpsr], cpsr \n\t"
: "=r" (ret), [newcpsr] "=r" (newcpsr)
: "0" (rr0), [oldcpsr] "r" (oldcpsr), [fn] "r" (fn)
: "lr", "cc"
);
* V_5 = ( V_15 & ~ V_17 ) | ( V_16 & V_17 ) ;
return V_3 ;
}
static inline long T_2
F_10 ( long V_10 , long V_11 , long * V_5 , T_9 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long T_10 V_7 ( L_2 ) = V_11 ;
register long V_3 V_7 ( L_1 ) ;
long V_15 = * V_5 ;
long V_16 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[oldcpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
"mrs %[newcpsr], cpsr \n\t"
: "=r" (ret), [newcpsr] "=r" (newcpsr)
: "0" (rr0), "r" (rr1), [oldcpsr] "r" (oldcpsr), [fn] "r" (fn)
: "lr", "cc"
);
* V_5 = ( V_15 & ~ V_17 ) | ( V_16 & V_17 ) ;
return V_3 ;
}
static inline long T_2
F_11 ( long V_10 , long V_11 , long V_13 , long * V_5 ,
T_11 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long T_10 V_7 ( L_2 ) = V_11 ;
register long T_12 V_7 ( L_3 ) = V_13 ;
register long V_3 V_7 ( L_1 ) ;
long V_15 = * V_5 ;
long V_16 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[oldcpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
"mrs %[newcpsr], cpsr \n\t"
: "=r" (ret), [newcpsr] "=r" (newcpsr)
: "0" (rr0), "r" (rr1), "r" (rr2),
[oldcpsr] "r" (oldcpsr), [fn] "r" (fn)
: "lr", "cc"
);
* V_5 = ( V_15 & ~ V_17 ) | ( V_16 & V_17 ) ;
return V_3 ;
}
static inline long T_2
F_12 ( long V_10 , long V_11 , long V_13 , long V_14 , long * V_5 ,
T_14 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long T_10 V_7 ( L_2 ) = V_11 ;
register long T_12 V_7 ( L_3 ) = V_13 ;
register long T_15 V_7 ( L_4 ) = V_14 ;
register long V_3 V_7 ( L_1 ) ;
long V_15 = * V_5 ;
long V_16 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[oldcpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
"mrs %[newcpsr], cpsr \n\t"
: "=r" (ret), [newcpsr] "=r" (newcpsr)
: "0" (rr0), "r" (rr1), "r" (rr2), "r" (rr3),
[oldcpsr] "r" (oldcpsr), [fn] "r" (fn)
: "lr", "cc"
);
* V_5 = ( V_15 & ~ V_17 ) | ( V_16 & V_17 ) ;
return V_3 ;
}
static inline long long T_2
F_13 ( long V_10 , long V_11 , long V_13 , long V_14 , long * V_5 ,
T_16 * V_6 )
{
register long T_8 V_7 ( L_1 ) = V_10 ;
register long T_10 V_7 ( L_2 ) = V_11 ;
register long T_12 V_7 ( L_3 ) = V_13 ;
register long T_15 V_7 ( L_4 ) = V_14 ;
register long T_5 V_7 ( L_1 ) ;
register long T_6 V_7 ( L_2 ) ;
long V_15 = * V_5 ;
long V_16 ;
union V_8 V_9 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[oldcpsr] \n\t"
"mov lr, pc \n\t"
"mov pc, %[fn] \n\t"
"mrs %[newcpsr], cpsr \n\t"
: "=r" (ret0), "=r" (ret1), [newcpsr] "=r" (newcpsr)
: "0" (rr0), "r" (rr1), "r" (rr2), "r" (rr3),
[oldcpsr] "r" (oldcpsr), [fn] "r" (fn)
: "lr", "cc"
);
* V_5 = ( V_15 & ~ V_17 ) | ( V_16 & V_17 ) ;
V_9 . V_10 = T_5 ;
V_9 . V_11 = T_6 ;
return V_9 . V_12 ;
}
static void T_2 F_14 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_17 V_22 = V_19 -> V_23 ;
long V_24 = ( long ) V_19 -> V_1 ;
int V_25 = F_15 ( V_22 ) ;
if ( V_22 & ( 1 << 24 ) )
V_21 -> V_26 = V_24 + 4 ;
V_21 -> V_27 = V_24 + 8 + V_25 ;
}
static void T_2 F_16 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_17 V_22 = V_19 -> V_23 ;
long V_24 = ( long ) V_19 -> V_1 ;
int V_25 = F_15 ( V_22 ) ;
V_21 -> V_26 = V_24 + 4 ;
V_21 -> V_27 = V_24 + 8 + V_25 + ( ( V_22 >> 23 ) & 0x2 ) ;
V_21 -> V_28 |= V_29 ;
}
static void T_2 F_17 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_17 V_22 = V_19 -> V_23 ;
int V_30 = V_22 & 0xf ;
long V_31 = V_21 -> V_32 [ V_30 ] ;
if ( V_22 & ( 1 << 5 ) )
V_21 -> V_26 = ( long ) V_19 -> V_1 + 4 ;
V_21 -> V_27 = V_31 & ~ 0x1 ;
V_21 -> V_28 &= ~ V_29 ;
if ( V_31 & 0x1 )
V_21 -> V_28 |= V_29 ;
}
static void T_2 F_18 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
unsigned long V_34 = 0xf8ff03df ;
V_21 -> V_32 [ V_33 ] = V_21 -> V_28 & V_34 ;
}
static void T_2 F_19 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_17 V_22 = V_19 -> V_23 ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_36 = V_22 & ( 1 << 20 ) ;
int V_37 = V_22 & ( 1 << 21 ) ;
int V_38 = V_22 & ( 1 << 23 ) ;
int V_39 = V_22 & ( 1 << 24 ) ;
long * V_1 = ( long * ) V_21 -> V_32 [ V_35 ] ;
int V_40 ;
int V_41 ;
V_41 = 0 ;
V_40 = V_22 & 0xffff ;
while ( V_40 ) {
V_40 &= ( V_40 - 1 ) ;
++ V_41 ;
}
if ( ! V_38 )
V_1 -= V_41 ;
V_1 += ( ! V_39 == ! V_38 ) ;
V_40 = V_22 & 0xffff ;
while ( V_40 ) {
int V_42 = F_20 ( V_40 ) ;
V_40 &= ( V_40 - 1 ) ;
if ( V_36 )
V_21 -> V_32 [ V_42 ] = * V_1 ++ ;
else
* V_1 ++ = V_21 -> V_32 [ V_42 ] ;
}
if ( V_37 ) {
if ( ! V_38 )
V_1 -= V_41 ;
V_1 -= ( ! V_39 == ! V_38 ) ;
V_21 -> V_32 [ V_35 ] = ( long ) V_1 ;
}
}
static void T_2 F_21 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
V_21 -> V_27 = ( long ) V_19 -> V_1 + V_4 ;
F_19 ( V_19 , V_21 ) ;
V_21 -> V_27 = ( long ) V_19 -> V_1 + 4 ;
}
static void T_2 F_22 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
V_21 -> V_32 [ 12 ] = V_21 -> V_32 [ 13 ] ;
}
static void T_2 F_23 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_9 * V_43 = ( T_9 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
long V_45 = ( long ) V_19 -> V_1 + 8 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_31 = ( V_30 == 15 ) ? V_45 : V_21 -> V_32 [ V_30 ] ;
long V_46 = ( V_35 == 15 ) ? V_45 : V_21 -> V_32 [ V_35 ] ;
__asm__ __volatile__ (
"ldr r0, %[rn] \n\t"
"ldr r1, %[rm] \n\t"
"msr cpsr_fs, %[cpsr]\n\t"
"mov lr, pc \n\t"
"mov pc, %[i_fn] \n\t"
"str r0, %[rn] \n\t"
"str r2, %[rd0] \n\t"
"str r3, %[rd1] \n\t"
: [rn] "+m" (rnv),
[rd0] "=m" (regs->uregs[rd]),
[rd1] "=m" (regs->uregs[rd+1])
: [rm] "m" (rmv),
[cpsr] "r" (regs->ARM_cpsr),
[i_fn] "r" (i_fn)
: "r0", "r1", "r2", "r3", "lr", "cc"
);
if ( F_24 ( V_22 ) )
V_21 -> V_32 [ V_35 ] = V_46 ;
}
static void T_2 F_25 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_14 * V_43 = ( T_14 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
long V_45 = ( long ) V_19 -> V_1 + 8 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_46 = ( V_35 == 15 ) ? V_45 : V_21 -> V_32 [ V_35 ] ;
long V_31 = ( V_30 == 15 ) ? V_45 : V_21 -> V_32 [ V_30 ] ;
long V_47 ;
V_47 = F_8 ( V_46 , V_31 , V_21 -> V_32 [ V_33 ] ,
V_21 -> V_32 [ V_33 + 1 ] ,
V_21 -> V_28 , V_43 ) ;
if ( F_24 ( V_22 ) )
V_21 -> V_32 [ V_35 ] = V_47 ;
}
static void T_2 F_26 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_13 * V_43 = ( T_13 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
long V_45 = ( long ) V_19 -> V_1 + 8 ;
union V_8 V_9 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_48 ;
long V_46 = ( V_35 == 15 ) ? V_45 : V_21 -> V_32 [ V_35 ] ;
long V_31 = ( V_30 == 15 ) ? V_45 : V_21 -> V_32 [ V_30 ] ;
long V_5 = V_21 -> V_28 ;
V_9 . V_12 = F_7 ( V_46 , 0 , V_31 , V_5 , V_43 ) ;
if ( V_35 != 15 )
V_21 -> V_32 [ V_35 ] = V_9 . V_10 ;
V_48 = V_9 . V_11 ;
if ( V_33 == 15 ) {
#if V_49 >= 5
V_5 &= ~ V_29 ;
if ( V_48 & 0x1 )
V_5 |= V_29 ;
V_21 -> V_28 = V_5 ;
V_48 &= ~ 0x1 ;
#else
V_48 &= ~ 0x2 ;
#endif
}
V_21 -> V_32 [ V_33 ] = V_48 ;
}
static void T_2 F_27 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_11 * V_43 = ( T_11 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
long V_24 = ( long ) V_19 -> V_1 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_48 = ( V_33 == 15 ) ? V_24 + V_4 : V_21 -> V_32 [ V_33 ] ;
long V_46 = ( V_35 == 15 ) ? V_24 + 8 : V_21 -> V_32 [ V_35 ] ;
long V_31 = V_21 -> V_32 [ V_30 ] ;
long V_47 ;
V_47 = F_6 ( V_46 , V_48 , V_31 , V_21 -> V_28 , V_43 ) ;
if ( V_35 != 15 )
V_21 -> V_32 [ V_35 ] = V_47 ;
}
static void T_2 F_28 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_7 * V_43 = ( T_7 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_31 = V_21 -> V_32 [ V_30 ] ;
V_21 -> V_32 [ V_33 ] = F_9 ( V_31 , & V_21 -> V_28 , V_43 ) ;
}
static void T_2 F_29 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_9 * V_43 = ( T_9 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_46 = V_21 -> V_32 [ V_35 ] ;
long V_31 = V_21 -> V_32 [ V_30 ] ;
V_21 -> V_32 [ V_33 ] = F_5 ( V_46 , V_31 , V_21 -> V_28 , V_43 ) ;
}
static void T_2 F_30 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_3 * V_43 = ( T_3 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
F_2 ( V_21 -> V_28 , V_43 ) ;
}
static void T_2 F_31 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
}
static void T_2
F_32 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_7 * V_43 = ( T_7 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
long V_48 = V_21 -> V_32 [ V_33 ] ;
V_21 -> V_32 [ V_33 ] = F_4 ( V_48 , V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_33 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_9 * V_43 = ( T_9 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = V_22 & 0xf ;
long V_48 = V_21 -> V_32 [ V_33 ] ;
long V_46 = V_21 -> V_32 [ V_35 ] ;
V_21 -> V_32 [ V_33 ] = F_5 ( V_48 , V_46 , V_21 -> V_28 , V_43 ) ;
}
static void T_2 F_34 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_7 * V_43 = ( T_7 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_31 = V_21 -> V_32 [ V_30 ] ;
V_21 -> V_32 [ V_33 ] = F_4 ( V_31 , V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_35 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_9 * V_43 = ( T_9 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_46 = V_21 -> V_32 [ V_35 ] ;
long V_31 = V_21 -> V_32 [ V_30 ] ;
V_21 -> V_32 [ V_33 ] =
F_10 ( V_46 , V_31 , & V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_36 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_11 * V_43 = ( T_11 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 16 ) & 0xf ;
int V_35 = ( V_22 >> 12 ) & 0xf ;
int V_50 = ( V_22 >> 8 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_46 = V_21 -> V_32 [ V_35 ] ;
long V_51 = V_21 -> V_32 [ V_50 ] ;
long V_31 = V_21 -> V_32 [ V_30 ] ;
V_21 -> V_32 [ V_33 ] =
F_11 ( V_46 , V_51 , V_31 , & V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_37 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_9 * V_43 = ( T_9 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 16 ) & 0xf ;
int V_50 = ( V_22 >> 8 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_51 = V_21 -> V_32 [ V_50 ] ;
long V_31 = V_21 -> V_32 [ V_30 ] ;
V_21 -> V_32 [ V_33 ] =
F_10 ( V_51 , V_31 , & V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_38 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_16 * V_43 = ( T_16 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
union V_8 V_9 ;
int V_52 = ( V_22 >> 16 ) & 0xf ;
int V_53 = ( V_22 >> 12 ) & 0xf ;
int V_50 = ( V_22 >> 8 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_51 = V_21 -> V_32 [ V_50 ] ;
long V_31 = V_21 -> V_32 [ V_30 ] ;
V_9 . V_12 = F_13 ( V_21 -> V_32 [ V_52 ] ,
V_21 -> V_32 [ V_53 ] , V_51 , V_31 ,
& V_21 -> V_28 , V_43 ) ;
V_21 -> V_32 [ V_52 ] = V_9 . V_10 ;
V_21 -> V_32 [ V_53 ] = V_9 . V_11 ;
}
static void T_2
F_39 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_7 * V_43 = ( T_7 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
long V_46 = ( V_35 == 15 ) ? ( long ) V_19 -> V_1 + 8 : V_21 -> V_32 [ V_35 ] ;
V_21 -> V_32 [ V_33 ] = F_4 ( V_46 , V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_40 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_7 * V_43 = ( T_7 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
long V_46 = ( V_35 == 15 ) ? ( long ) V_19 -> V_1 + 8 : V_21 -> V_32 [ V_35 ] ;
V_21 -> V_32 [ V_33 ] = F_9 ( V_46 , & V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_41 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_7 * V_43 = ( T_7 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
long V_46 = ( V_35 == 15 ) ? ( long ) V_19 -> V_1 + 8 : V_21 -> V_32 [ V_35 ] ;
F_9 ( V_46 , & V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_42 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_11 * V_43 = ( T_11 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
long V_45 = ( long ) V_19 -> V_1 + 8 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_50 = ( V_22 >> 8 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_46 = ( V_35 == 15 ) ? V_45 : V_21 -> V_32 [ V_35 ] ;
long V_31 = ( V_30 == 15 ) ? V_45 : V_21 -> V_32 [ V_30 ] ;
long V_51 = V_21 -> V_32 [ V_50 ] ;
V_21 -> V_32 [ V_33 ] =
F_6 ( V_46 , V_31 , V_51 , V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_43 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_11 * V_43 = ( T_11 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
long V_45 = ( long ) V_19 -> V_1 + 8 ;
int V_33 = ( V_22 >> 12 ) & 0xf ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_50 = ( V_22 >> 8 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_46 = ( V_35 == 15 ) ? V_45 : V_21 -> V_32 [ V_35 ] ;
long V_31 = ( V_30 == 15 ) ? V_45 : V_21 -> V_32 [ V_30 ] ;
long V_51 = V_21 -> V_32 [ V_50 ] ;
V_21 -> V_32 [ V_33 ] =
F_11 ( V_46 , V_31 , V_51 , & V_21 -> V_28 , V_43 ) ;
}
static void T_2
F_44 ( struct V_18 * V_19 , struct V_20 * V_21 )
{
T_11 * V_43 = ( T_11 * ) & V_19 -> V_44 . V_22 [ 0 ] ;
T_17 V_22 = V_19 -> V_23 ;
long V_45 = ( long ) V_19 -> V_1 + 8 ;
int V_35 = ( V_22 >> 16 ) & 0xf ;
int V_50 = ( V_22 >> 8 ) & 0xf ;
int V_30 = V_22 & 0xf ;
long V_46 = ( V_35 == 15 ) ? V_45 : V_21 -> V_32 [ V_35 ] ;
long V_31 = ( V_30 == 15 ) ? V_45 : V_21 -> V_32 [ V_30 ] ;
long V_51 = V_21 -> V_32 [ V_50 ] ;
F_11 ( V_46 , V_31 , V_51 , & V_21 -> V_28 , V_43 ) ;
}
static enum V_54 T_2
F_45 ( T_17 V_22 , struct V_55 * V_56 )
{
int V_57 = ( V_22 & ( 1 << 26 ) ) ? ( V_22 & ( 1 << 25 ) )
: ( ~ V_22 & ( 1 << 22 ) ) ;
if ( F_24 ( V_22 ) && F_46 ( V_22 , 16 ) )
return V_58 ;
V_22 &= 0xfff00fff ;
V_22 |= 0x00001000 ;
if ( V_57 ) {
V_22 &= ~ 0xf ;
V_22 |= 2 ;
}
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = ( V_22 & ( 1 << 20 ) ) ? F_26 : F_27 ;
return V_60 ;
}
static enum V_54 T_2
F_47 ( T_17 V_22 , struct V_55 * V_56 )
{
if ( F_46 ( V_22 , 12 ) )
return V_58 ;
V_22 &= 0xffff0fff ;
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_32 ;
return V_60 ;
}
static enum V_54 T_2
F_48 ( T_17 V_22 ,
struct V_55 * V_56 )
{
if ( F_46 ( V_22 , 12 ) )
return V_58 ;
V_22 &= 0xffff0ff0 ;
V_22 |= 0x00000001 ;
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_33 ;
return V_60 ;
}
static enum V_54 T_2
F_49 ( T_17 V_22 , struct V_55 * V_56 )
{
if ( F_46 ( V_22 , 12 ) )
return V_58 ;
V_22 &= 0xffff0ff0 ;
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_34 ;
return V_60 ;
}
static enum V_54 T_2
F_50 ( T_17 V_22 ,
struct V_55 * V_56 )
{
if ( F_46 ( V_22 , 12 ) )
return V_58 ;
V_22 &= 0xfff00ff0 ;
V_22 |= 0x00000001 ;
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_35 ;
return V_60 ;
}
static enum V_54 T_2
F_51 ( T_17 V_22 ,
struct V_55 * V_56 )
{
if ( F_46 ( V_22 , 16 ) )
return V_58 ;
V_22 &= 0xfff0f0f0 ;
V_22 |= 0x00000001 ;
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_37 ;
return V_60 ;
}
static enum V_54 T_2
F_52 ( T_17 V_22 ,
struct V_55 * V_56 )
{
if ( F_46 ( V_22 , 16 ) )
return V_58 ;
V_22 &= 0xfff000f0 ;
V_22 |= 0x00000102 ;
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_36 ;
return V_60 ;
}
static enum V_54 T_2
F_53 ( T_17 V_22 ,
struct V_55 * V_56 )
{
if ( F_46 ( V_22 , 16 ) || F_46 ( V_22 , 12 ) )
return V_58 ;
V_22 &= 0xfff000f0 ;
V_22 |= 0x00001203 ;
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_38 ;
return V_60 ;
}
static enum V_54 T_2
F_54 ( T_17 V_22 , struct V_55 * V_56 )
{
if ( ( V_22 & 0xfe300000 ) == 0xf4100000 ) {
V_56 -> V_59 = F_31 ;
return V_61 ;
}
if ( ( V_22 & 0xfe000000 ) == 0xfa000000 ) {
V_56 -> V_59 = F_16 ;
return V_61 ;
}
return V_58 ;
}
static enum V_54 T_2
F_55 ( T_17 V_22 , struct V_55 * V_56 )
{
if ( ( V_22 & 0x0f900010 ) == 0x01000000 ) {
if ( ( V_22 & 0x0ff000f0 ) == 0x01000000 ) {
if ( F_46 ( V_22 , 12 ) )
return V_58 ;
V_56 -> V_59 = F_18 ;
return V_61 ;
}
if ( ( V_22 & 0x0ff00090 ) == 0x01400080 )
return F_53 ( V_22 ,
V_56 ) ;
if ( ( V_22 & 0x0ff000b0 ) == 0x012000a0 ||
( V_22 & 0x0ff00090 ) == 0x01600080 )
return F_51 ( V_22 , V_56 ) ;
if ( ( V_22 & 0x0ff00090 ) == 0x01000080 ||
( V_22 & 0x0ff000b0 ) == 0x01200080 )
return F_52 ( V_22 , V_56 ) ;
return V_58 ;
}
else if ( ( V_22 & 0x0f900090 ) == 0x01000010 ) {
if ( ( V_22 & 0x0ff000d0 ) == 0x01200010 ) {
if ( ( V_22 & 0x0ff000ff ) == 0x0120003f )
return V_58 ;
V_56 -> V_59 = F_17 ;
return V_61 ;
}
if ( ( V_22 & 0x0ff000f0 ) == 0x01600010 )
return F_49 ( V_22 , V_56 ) ;
if ( ( V_22 & 0x0f9000f0 ) == 0x01000050 )
return F_50 ( V_22 , V_56 ) ;
return V_58 ;
}
else if ( ( V_22 & 0x0f0000f0 ) == 0x00000090 ) {
if ( ( V_22 & 0x00d00000 ) == 0x00500000 )
return V_58 ;
else if ( ( V_22 & 0x00e00000 ) == 0x00000000 )
return F_51 ( V_22 , V_56 ) ;
else if ( ( V_22 & 0x00a00000 ) == 0x00200000 )
return F_52 ( V_22 , V_56 ) ;
else
return F_53 ( V_22 ,
V_56 ) ;
}
else if ( ( V_22 & 0x0e000090 ) == 0x00000090 ) {
if ( ( V_22 & 0x0f0000f0 ) == 0x01000090 ) {
if ( ( V_22 & 0x0fb000f0 ) == 0x01000090 ) {
return F_50 ( V_22 ,
V_56 ) ;
} else {
return V_58 ;
}
} else if ( ( V_22 & 0x0e1000d0 ) == 0x00000d0 ) {
if ( ( V_22 & 0x0000e000 ) == 0x0000e000 )
return V_58 ;
if ( F_24 ( V_22 ) && F_46 ( V_22 , 16 ) )
return V_58 ;
V_22 &= 0xfff00fff ;
V_22 |= 0x00002000 ;
if ( ! ( V_22 & ( 1 << 22 ) ) ) {
V_22 &= ~ 0xf ;
V_22 |= 1 ;
}
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 =
( V_22 & ( 1 << 5 ) ) ? F_25 : F_23 ;
return V_60 ;
}
if ( F_46 ( V_22 , 12 ) )
return V_58 ;
return F_45 ( V_22 , V_56 ) ;
}
if ( ( V_22 & 0x0e10f000 ) == 0x0010f000 )
return V_58 ;
if ( V_22 == 0xe1a0c00d ) {
V_56 -> V_59 = F_22 ;
return V_61 ;
}
V_22 &= 0xfff00ff0 ;
V_22 |= 0x00000001 ;
if ( V_22 & 0x010 ) {
V_22 &= 0xfffff0ff ;
V_22 |= 0x00000200 ;
}
V_56 -> V_22 [ 0 ] = V_22 ;
if ( ( V_22 & 0x0f900000 ) == 0x01100000 ) {
V_56 -> V_59 = F_44 ;
} else {
V_56 -> V_59 = ( V_22 & ( 1 << 20 ) ) ?
F_43 : F_42 ;
}
return V_60 ;
}
static enum V_54 T_2
F_56 ( T_17 V_22 , struct V_55 * V_56 )
{
if ( ( V_22 & 0x0fb00000 ) == 0x03000000 )
return F_47 ( V_22 , V_56 ) ;
if ( ( V_22 & 0x0fff0000 ) == 0x03200000 ) {
unsigned V_62 = V_22 & 0x000000ff ;
if ( V_62 == 0x01 || V_62 == 0x04 ) {
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_30 ;
return V_60 ;
} else if ( V_62 <= 0x03 ) {
V_56 -> V_59 = F_31 ;
return V_61 ;
}
return V_58 ;
}
if ( ( V_22 & 0x0fb00000 ) == 0x03200000 ||
( V_22 & 0x0e10f000 ) == 0x0210f000 )
return V_58 ;
V_22 &= 0xfff00fff ;
V_56 -> V_22 [ 0 ] = V_22 ;
if ( ( V_22 & 0x0f900000 ) == 0x03100000 ) {
V_56 -> V_59 = F_41 ;
} else {
V_56 -> V_59 = ( V_22 & ( 1 << 20 ) ) ?
F_40 : F_39 ;
}
return V_60 ;
}
static enum V_54 T_2
F_57 ( T_17 V_22 , struct V_55 * V_56 )
{
if ( ( V_22 & 0x0ff000f0 ) == 0x068000b0 ) {
if ( F_46 ( V_22 , 12 ) )
return V_58 ;
V_22 &= 0xfff00ff0 ;
V_22 |= 0x00000001 ;
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_29 ;
return V_60 ;
}
if ( ( V_22 & 0x0fa00030 ) == 0x06a00010 ||
( V_22 & 0x0fb000f0 ) == 0x06a00030 ) {
if ( F_46 ( V_22 , 12 ) )
return V_58 ;
V_22 &= 0xffff0ff0 ;
V_56 -> V_22 [ 0 ] = V_22 ;
V_56 -> V_59 = F_28 ;
return V_60 ;
}
if ( ( V_22 & 0x0ff00070 ) == 0x06b00030 ||
( V_22 & 0x0ff00070 ) == 0x06f00030 )
return F_49 ( V_22 , V_56 ) ;
if ( ( V_22 & 0x0f800010 ) == 0x06000010 ) {
if ( ( V_22 & 0x00300000 ) == 0x00000000 ||
( V_22 & 0x000000e0 ) == 0x000000a0 ||
( V_22 & 0x000000e0 ) == 0x000000c0 )
return V_58 ;
return F_50 ( V_22 , V_56 ) ;
}
if ( ( V_22 & 0x0ff00030 ) == 0x06800010 )
return F_50 ( V_22 , V_56 ) ;
if ( ( V_22 & 0x0f8000f0 ) == 0x06800070 ) {
if ( ( V_22 & 0x00300000 ) == 0x00100000 )
return V_58 ;
if ( ( V_22 & 0x000f0000 ) == 0x000f0000 )
return F_49 ( V_22 , V_56 ) ;
else
return F_50 ( V_22 , V_56 ) ;
}
return V_58 ;
}
static enum V_54 T_2
F_58 ( T_17 V_22 , struct V_55 * V_56 )
{
if ( ( V_22 & 0x0ff000f0 ) == 0x03f000f0 )
return V_58 ;
if ( ( V_22 & 0x0ff00090 ) == 0x07400010 )
return F_53 ( V_22 , V_56 ) ;
if ( ( V_22 & 0x0ff00090 ) == 0x07000010 ||
( V_22 & 0x0ff000d0 ) == 0x07500010 ||
( V_22 & 0x0ff000f0 ) == 0x07800010 ) {
if ( ( V_22 & 0x0000f000 ) == 0x0000f000 )
return F_51 ( V_22 , V_56 ) ;
else
return F_52 ( V_22 , V_56 ) ;
}
if ( ( V_22 & 0x0ff000d0 ) == 0x075000d0 )
return F_52 ( V_22 , V_56 ) ;
if ( ( V_22 & 0x0fa00070 ) == 0x07a00050 )
return F_49 ( V_22 , V_56 ) ;
if ( ( V_22 & 0x0fe00070 ) == 0x07c00010 ) {
if ( ( V_22 & 0x0000000f ) == 0x0000000f )
return F_47 ( V_22 , V_56 ) ;
else
return F_48 ( V_22 , V_56 ) ;
}
return V_58 ;
}
static enum V_54 T_2
F_59 ( T_17 V_22 , struct V_55 * V_56 )
{
if ( ( V_22 & 0x00500000 ) == 0x00500000 && F_46 ( V_22 , 12 ) )
return V_58 ;
return F_45 ( V_22 , V_56 ) ;
}
static enum V_54 T_2
F_60 ( T_17 V_22 , struct V_55 * V_56 )
{
if ( ( V_22 & 0x0e708000 ) == 0x85000000 ||
( V_22 & 0x0e508000 ) == 0x85010000 )
return V_58 ;
V_56 -> V_59 = ( ( V_22 & 0x108000 ) == 0x008000 ) ?
F_21 : F_19 ;
return V_61 ;
}
static enum V_54 T_2
F_61 ( T_17 V_22 , struct V_55 * V_56 )
{
V_56 -> V_59 = F_14 ;
return V_61 ;
}
static enum V_54 T_2
F_62 ( T_17 V_22 , struct V_55 * V_56 )
{
return V_58 ;
}
static unsigned long T_2 F_63 ( unsigned long V_5 )
{
return V_5 & V_63 ;
}
static unsigned long T_2 F_64 ( unsigned long V_5 )
{
return ( ~ V_5 ) & V_63 ;
}
static unsigned long T_2 F_65 ( unsigned long V_5 )
{
return V_5 & V_64 ;
}
static unsigned long T_2 F_66 ( unsigned long V_5 )
{
return ( ~ V_5 ) & V_64 ;
}
static unsigned long T_2 F_67 ( unsigned long V_5 )
{
return V_5 & V_65 ;
}
static unsigned long T_2 F_68 ( unsigned long V_5 )
{
return ( ~ V_5 ) & V_65 ;
}
static unsigned long T_2 F_69 ( unsigned long V_5 )
{
return V_5 & V_66 ;
}
static unsigned long T_2 F_70 ( unsigned long V_5 )
{
return ( ~ V_5 ) & V_66 ;
}
static unsigned long T_2 F_71 ( unsigned long V_5 )
{
V_5 &= ~ ( V_5 >> 1 ) ;
return V_5 & V_64 ;
}
static unsigned long T_2 F_72 ( unsigned long V_5 )
{
V_5 &= ~ ( V_5 >> 1 ) ;
return ( ~ V_5 ) & V_64 ;
}
static unsigned long T_2 F_73 ( unsigned long V_5 )
{
V_5 ^= ( V_5 << 3 ) ;
return ( ~ V_5 ) & V_65 ;
}
static unsigned long T_2 F_74 ( unsigned long V_5 )
{
V_5 ^= ( V_5 << 3 ) ;
return V_5 & V_65 ;
}
static unsigned long T_2 F_75 ( unsigned long V_5 )
{
unsigned long V_67 = V_5 ^ ( V_5 << 3 ) ;
V_67 |= ( V_5 << 1 ) ;
return ( ~ V_67 ) & V_65 ;
}
static unsigned long T_2 F_76 ( unsigned long V_5 )
{
unsigned long V_67 = V_5 ^ ( V_5 << 3 ) ;
V_67 |= ( V_5 << 1 ) ;
return V_67 & V_65 ;
}
static unsigned long T_2 F_77 ( unsigned long V_5 )
{
return true ;
}
enum V_54 T_2
F_78 ( T_17 V_22 , struct V_55 * V_56 )
{
V_56 -> V_68 = V_69 [ V_22 >> 28 ] ;
V_56 -> V_22 [ 1 ] = V_70 ;
if ( ( V_22 & 0xf0000000 ) == 0xf0000000 )
return F_54 ( V_22 , V_56 ) ;
else if ( ( V_22 & 0x0e000000 ) == 0x00000000 )
return F_55 ( V_22 , V_56 ) ;
else if ( ( V_22 & 0x0e000000 ) == 0x02000000 )
return F_56 ( V_22 , V_56 ) ;
else if ( ( V_22 & 0x0f000010 ) == 0x06000010 )
return F_57 ( V_22 , V_56 ) ;
else if ( ( V_22 & 0x0f000010 ) == 0x07000010 )
return F_58 ( V_22 , V_56 ) ;
else if ( ( V_22 & 0x0c000000 ) == 0x04000000 )
return F_59 ( V_22 , V_56 ) ;
else if ( ( V_22 & 0x0e000000 ) == 0x08000000 )
return F_60 ( V_22 , V_56 ) ;
else if ( ( V_22 & 0x0e000000 ) == 0x0a000000 )
return F_61 ( V_22 , V_56 ) ;
return F_62 ( V_22 , V_56 ) ;
}
void T_1 F_79 ( void )
{
F_1 () ;
}
