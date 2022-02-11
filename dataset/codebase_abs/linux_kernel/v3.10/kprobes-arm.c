static void T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
long V_7 = ( long ) V_2 -> V_8 ;
int V_9 = F_2 ( V_5 ) ;
if ( V_5 & ( 1 << 24 ) )
V_4 -> V_10 = V_7 + 4 ;
V_4 -> V_11 = V_7 + 8 + V_9 ;
}
static void T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
long V_7 = ( long ) V_2 -> V_8 ;
int V_9 = F_2 ( V_5 ) ;
V_4 -> V_10 = V_7 + 4 ;
V_4 -> V_11 = V_7 + 8 + V_9 + ( ( V_5 >> 23 ) & 0x2 ) ;
V_4 -> V_12 |= V_13 ;
}
static void T_1 F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
int V_14 = V_5 & 0xf ;
long V_15 = V_4 -> V_16 [ V_14 ] ;
if ( V_5 & ( 1 << 5 ) )
V_4 -> V_10 = ( long ) V_2 -> V_8 + 4 ;
V_4 -> V_11 = V_15 & ~ 0x1 ;
V_4 -> V_12 &= ~ V_13 ;
if ( V_15 & 0x1 )
V_4 -> V_12 |= V_13 ;
}
static void T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
int V_17 = ( V_5 >> 12 ) & 0xf ;
unsigned long V_18 = 0xf8ff03df ;
V_4 -> V_16 [ V_17 ] = V_4 -> V_12 & V_18 ;
}
static void T_1 F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_16 [ 12 ] = V_4 -> V_16 [ 13 ] ;
}
static void T_1
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
unsigned long V_19 = ( unsigned long ) V_2 -> V_8 + 8 ;
int V_20 = ( V_5 >> 12 ) & 0xf ;
int V_21 = ( V_5 >> 16 ) & 0xf ;
int V_14 = V_5 & 0xf ;
register unsigned long T_3 V_22 ( L_1 ) = V_4 -> V_16 [ V_20 ] ;
register unsigned long T_4 V_22 ( L_2 ) = V_4 -> V_16 [ V_20 + 1 ] ;
register unsigned long T_5 V_22 ( L_3 ) = ( V_21 == 15 ) ? V_19
: V_4 -> V_16 [ V_21 ] ;
register unsigned long V_15 V_22 ( L_4 ) = V_4 -> V_16 [ V_14 ] ;
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rtv), "=r" (rt2v), "=r" (rnv)
: "0" (rtv), "1" (rt2v), "2" (rnv), "r" (rmv),
[fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_4 -> V_16 [ V_20 ] = T_3 ;
V_4 -> V_16 [ V_20 + 1 ] = T_4 ;
if ( F_8 ( V_5 ) )
V_4 -> V_16 [ V_21 ] = T_5 ;
}
static void T_1
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
unsigned long V_19 = ( unsigned long ) V_2 -> V_8 + 8 ;
int V_20 = ( V_5 >> 12 ) & 0xf ;
int V_21 = ( V_5 >> 16 ) & 0xf ;
int V_14 = V_5 & 0xf ;
register unsigned long T_3 V_22 ( L_1 ) ;
register unsigned long T_5 V_22 ( L_3 ) = ( V_21 == 15 ) ? V_19
: V_4 -> V_16 [ V_21 ] ;
register unsigned long V_15 V_22 ( L_4 ) = V_4 -> V_16 [ V_14 ] ;
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rtv), "=r" (rnv)
: "1" (rnv), "r" (rmv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if ( V_20 == 15 )
F_10 ( T_3 , V_4 ) ;
else
V_4 -> V_16 [ V_20 ] = T_3 ;
if ( F_8 ( V_5 ) )
V_4 -> V_16 [ V_21 ] = T_5 ;
}
static void T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
unsigned long V_23 = ( unsigned long ) V_2 -> V_8 + V_24 ;
unsigned long V_25 = ( unsigned long ) V_2 -> V_8 + 8 ;
int V_20 = ( V_5 >> 12 ) & 0xf ;
int V_21 = ( V_5 >> 16 ) & 0xf ;
int V_14 = V_5 & 0xf ;
register unsigned long T_3 V_22 ( L_1 ) = ( V_20 == 15 ) ? V_23
: V_4 -> V_16 [ V_20 ] ;
register unsigned long T_5 V_22 ( L_3 ) = ( V_21 == 15 ) ? V_25
: V_4 -> V_16 [ V_21 ] ;
register unsigned long V_15 V_22 ( L_4 ) = V_4 -> V_16 [ V_14 ] ;
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rnv)
: "r" (rtv), "0" (rnv), "r" (rmv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if ( F_8 ( V_5 ) )
V_4 -> V_16 [ V_21 ] = T_5 ;
}
static void T_1
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
unsigned long V_19 = ( unsigned long ) V_2 -> V_8 + 8 ;
int V_17 = ( V_5 >> 12 ) & 0xf ;
int V_21 = ( V_5 >> 16 ) & 0xf ;
int V_14 = V_5 & 0xf ;
int V_26 = ( V_5 >> 8 ) & 0xf ;
register unsigned long T_6 V_22 ( L_1 ) = V_4 -> V_16 [ V_17 ] ;
register unsigned long T_5 V_22 ( L_3 ) = ( V_21 == 15 ) ? V_19
: V_4 -> V_16 [ V_21 ] ;
register unsigned long V_15 V_22 ( L_4 ) = ( V_14 == 15 ) ? V_19
: V_4 -> V_16 [ V_14 ] ;
register unsigned long T_7 V_22 ( L_2 ) = V_4 -> V_16 [ V_26 ] ;
unsigned long V_27 = V_4 -> V_12 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv), "r" (rsv),
"1" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
if ( V_17 == 15 )
F_13 ( T_6 , V_4 ) ;
else
V_4 -> V_16 [ V_17 ] = T_6 ;
V_4 -> V_12 = ( V_4 -> V_12 & ~ V_28 ) | ( V_27 & V_28 ) ;
}
static void T_1
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
int V_17 = ( V_5 >> 12 ) & 0xf ;
int V_21 = ( V_5 >> 16 ) & 0xf ;
int V_14 = V_5 & 0xf ;
register unsigned long T_6 V_22 ( L_1 ) = V_4 -> V_16 [ V_17 ] ;
register unsigned long T_5 V_22 ( L_3 ) = V_4 -> V_16 [ V_21 ] ;
register unsigned long V_15 V_22 ( L_4 ) = V_4 -> V_16 [ V_14 ] ;
unsigned long V_27 = V_4 -> V_12 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv),
"1" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_4 -> V_16 [ V_17 ] = T_6 ;
V_4 -> V_12 = ( V_4 -> V_12 & ~ V_28 ) | ( V_27 & V_28 ) ;
}
static void T_1
F_15 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
int V_17 = ( V_5 >> 16 ) & 0xf ;
int V_21 = ( V_5 >> 12 ) & 0xf ;
int V_14 = V_5 & 0xf ;
int V_26 = ( V_5 >> 8 ) & 0xf ;
register unsigned long T_6 V_22 ( L_3 ) = V_4 -> V_16 [ V_17 ] ;
register unsigned long T_5 V_22 ( L_1 ) = V_4 -> V_16 [ V_21 ] ;
register unsigned long V_15 V_22 ( L_4 ) = V_4 -> V_16 [ V_14 ] ;
register unsigned long T_7 V_22 ( L_2 ) = V_4 -> V_16 [ V_26 ] ;
unsigned long V_27 = V_4 -> V_12 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv), "r" (rsv),
"1" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_4 -> V_16 [ V_17 ] = T_6 ;
V_4 -> V_12 = ( V_4 -> V_12 & ~ V_28 ) | ( V_27 & V_28 ) ;
}
static void T_1
F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
int V_17 = ( V_5 >> 12 ) & 0xf ;
int V_14 = V_5 & 0xf ;
register unsigned long T_6 V_22 ( L_1 ) = V_4 -> V_16 [ V_17 ] ;
register unsigned long V_15 V_22 ( L_4 ) = V_4 -> V_16 [ V_14 ] ;
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rdv)
: "0" (rdv), "r" (rmv), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_4 -> V_16 [ V_17 ] = T_6 ;
}
static void T_1
F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_5 = V_2 -> V_6 ;
int V_29 = ( V_5 >> 12 ) & 0xf ;
int V_30 = ( V_5 >> 16 ) & 0xf ;
int V_21 = V_5 & 0xf ;
int V_14 = ( V_5 >> 8 ) & 0xf ;
register unsigned long T_8 V_22 ( L_1 ) = V_4 -> V_16 [ V_29 ] ;
register unsigned long T_9 V_22 ( L_3 ) = V_4 -> V_16 [ V_30 ] ;
register unsigned long T_5 V_22 ( L_4 ) = V_4 -> V_16 [ V_21 ] ;
register unsigned long V_15 V_22 ( L_2 ) = V_4 -> V_16 [ V_14 ] ;
unsigned long V_27 = V_4 -> V_12 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdlov), "=r" (rdhiv), [cpsr] "=r" (cpsr)
: "0" (rdlov), "1" (rdhiv), "r" (rnv), "r" (rmv),
"2" (cpsr), [fn] "r" (p->ainsn.insn_fn)
: "lr", "memory", "cc"
);
V_4 -> V_16 [ V_29 ] = T_8 ;
V_4 -> V_16 [ V_30 ] = T_9 ;
V_4 -> V_12 = ( V_4 -> V_12 & ~ V_28 ) | ( V_27 & V_28 ) ;
}
static void T_1 F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_11 += 4 ;
V_2 -> V_31 . V_32 ( V_2 , V_4 ) ;
}
enum V_33 T_1
F_19 ( T_2 V_5 , struct V_34 * V_35 )
{
V_35 -> V_36 = F_18 ;
V_35 -> V_37 = V_38 [ V_5 >> 28 ] ;
return F_20 ( V_5 , V_35 , V_39 , false ) ;
}
