static void T_1
F_1 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 + 4 ;
int V_8 = ( V_1 >> 12 ) & 0xf ;
int V_9 = ( V_1 >> 16 ) & 0xf ;
int V_10 = V_1 & 0xf ;
register unsigned long T_3 V_11 ( L_1 ) = V_5 -> V_12 [ V_8 ] ;
register unsigned long T_4 V_11 ( L_2 ) = V_5 -> V_12 [ V_8 + 1 ] ;
register unsigned long T_5 V_11 ( L_3 ) = ( V_9 == 15 ) ? V_6
: V_5 -> V_12 [ V_9 ] ;
register unsigned long T_6 V_11 ( L_4 ) = V_5 -> V_12 [ V_10 ] ;
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rtv), "=r" (rt2v), "=r" (rnv)
: "0" (rtv), "1" (rt2v), "2" (rnv), "r" (rmv),
[fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_8 ] = T_3 ;
V_5 -> V_12 [ V_8 + 1 ] = T_4 ;
if ( F_2 ( V_1 ) )
V_5 -> V_12 [ V_9 ] = T_5 ;
}
static void T_1
F_3 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 + 4 ;
int V_8 = ( V_1 >> 12 ) & 0xf ;
int V_9 = ( V_1 >> 16 ) & 0xf ;
int V_10 = V_1 & 0xf ;
register unsigned long T_3 V_11 ( L_1 ) ;
register unsigned long T_5 V_11 ( L_3 ) = ( V_9 == 15 ) ? V_6
: V_5 -> V_12 [ V_9 ] ;
register unsigned long T_6 V_11 ( L_4 ) = V_5 -> V_12 [ V_10 ] ;
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rtv), "=r" (rnv)
: "1" (rnv), "r" (rmv), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
if ( V_8 == 15 )
F_4 ( T_3 , V_5 ) ;
else
V_5 -> V_12 [ V_8 ] = T_3 ;
if ( F_2 ( V_1 ) )
V_5 -> V_12 [ V_9 ] = T_5 ;
}
static void T_1
F_5 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_13 = V_5 -> V_7 - 4 + V_14 ;
unsigned long V_15 = V_5 -> V_7 + 4 ;
int V_8 = ( V_1 >> 12 ) & 0xf ;
int V_9 = ( V_1 >> 16 ) & 0xf ;
int V_10 = V_1 & 0xf ;
register unsigned long T_3 V_11 ( L_1 ) = ( V_8 == 15 ) ? V_13
: V_5 -> V_12 [ V_8 ] ;
register unsigned long T_5 V_11 ( L_3 ) = ( V_9 == 15 ) ? V_15
: V_5 -> V_12 [ V_9 ] ;
register unsigned long T_6 V_11 ( L_4 ) = V_5 -> V_12 [ V_10 ] ;
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rnv)
: "r" (rtv), "0" (rnv), "r" (rmv), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
if ( F_2 ( V_1 ) )
V_5 -> V_12 [ V_9 ] = T_5 ;
}
static void T_1
F_6 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned long V_6 = V_5 -> V_7 + 4 ;
int V_16 = ( V_1 >> 12 ) & 0xf ;
int V_9 = ( V_1 >> 16 ) & 0xf ;
int V_10 = V_1 & 0xf ;
int V_17 = ( V_1 >> 8 ) & 0xf ;
register unsigned long T_7 V_11 ( L_1 ) = V_5 -> V_12 [ V_16 ] ;
register unsigned long T_5 V_11 ( L_3 ) = ( V_9 == 15 ) ? V_6
: V_5 -> V_12 [ V_9 ] ;
register unsigned long T_6 V_11 ( L_4 ) = ( V_10 == 15 ) ? V_6
: V_5 -> V_12 [ V_10 ] ;
register unsigned long T_8 V_11 ( L_2 ) = V_5 -> V_12 [ V_17 ] ;
unsigned long V_18 = V_5 -> V_19 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv), "r" (rsv),
"1" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
if ( V_16 == 15 )
F_7 ( T_7 , V_5 ) ;
else
V_5 -> V_12 [ V_16 ] = T_7 ;
V_5 -> V_19 = ( V_5 -> V_19 & ~ V_20 ) | ( V_18 & V_20 ) ;
}
static void T_1
F_8 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_16 = ( V_1 >> 12 ) & 0xf ;
int V_9 = ( V_1 >> 16 ) & 0xf ;
int V_10 = V_1 & 0xf ;
register unsigned long T_7 V_11 ( L_1 ) = V_5 -> V_12 [ V_16 ] ;
register unsigned long T_5 V_11 ( L_3 ) = V_5 -> V_12 [ V_9 ] ;
register unsigned long T_6 V_11 ( L_4 ) = V_5 -> V_12 [ V_10 ] ;
unsigned long V_18 = V_5 -> V_19 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv),
"1" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_16 ] = T_7 ;
V_5 -> V_19 = ( V_5 -> V_19 & ~ V_20 ) | ( V_18 & V_20 ) ;
}
static void T_1
F_9 ( T_2 V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_16 = ( V_1 >> 16 ) & 0xf ;
int V_9 = ( V_1 >> 12 ) & 0xf ;
int V_10 = V_1 & 0xf ;
int V_17 = ( V_1 >> 8 ) & 0xf ;
register unsigned long T_7 V_11 ( L_3 ) = V_5 -> V_12 [ V_16 ] ;
register unsigned long T_5 V_11 ( L_1 ) = V_5 -> V_12 [ V_9 ] ;
register unsigned long T_6 V_11 ( L_4 ) = V_5 -> V_12 [ V_10 ] ;
register unsigned long T_8 V_11 ( L_2 ) = V_5 -> V_12 [ V_17 ] ;
unsigned long V_18 = V_5 -> V_19 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdv), [cpsr] "=r" (cpsr)
: "0" (rdv), "r" (rnv), "r" (rmv), "r" (rsv),
"1" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_16 ] = T_7 ;
V_5 -> V_19 = ( V_5 -> V_19 & ~ V_20 ) | ( V_18 & V_20 ) ;
}
static void T_1
F_10 ( T_2 V_1 ,
struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_16 = ( V_1 >> 12 ) & 0xf ;
int V_10 = V_1 & 0xf ;
register unsigned long T_7 V_11 ( L_1 ) = V_5 -> V_12 [ V_16 ] ;
register unsigned long T_6 V_11 ( L_4 ) = V_5 -> V_12 [ V_10 ] ;
__asm__ __volatile__ (
BLX("%[fn]")
: "=r" (rdv)
: "0" (rdv), "r" (rmv), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_16 ] = T_7 ;
}
static void T_1
F_11 ( T_2 V_1 ,
struct V_2 * V_3 ,
struct V_4 * V_5 )
{
int V_21 = ( V_1 >> 12 ) & 0xf ;
int V_22 = ( V_1 >> 16 ) & 0xf ;
int V_9 = V_1 & 0xf ;
int V_10 = ( V_1 >> 8 ) & 0xf ;
register unsigned long T_9 V_11 ( L_1 ) = V_5 -> V_12 [ V_21 ] ;
register unsigned long T_10 V_11 ( L_3 ) = V_5 -> V_12 [ V_22 ] ;
register unsigned long T_5 V_11 ( L_4 ) = V_5 -> V_12 [ V_9 ] ;
register unsigned long T_6 V_11 ( L_2 ) = V_5 -> V_12 [ V_10 ] ;
unsigned long V_18 = V_5 -> V_19 ;
__asm__ __volatile__ (
"msr cpsr_fs, %[cpsr] \n\t"
BLX("%[fn]")
"mrs %[cpsr], cpsr \n\t"
: "=r" (rdlov), "=r" (rdhiv), [cpsr] "=r" (cpsr)
: "0" (rdlov), "1" (rdhiv), "r" (rnv), "r" (rmv),
"2" (cpsr), [fn] "r" (asi->insn_fn)
: "lr", "memory", "cc"
);
V_5 -> V_12 [ V_21 ] = T_9 ;
V_5 -> V_12 [ V_22 ] = T_10 ;
V_5 -> V_19 = ( V_5 -> V_19 & ~ V_20 ) | ( V_18 & V_20 ) ;
}
