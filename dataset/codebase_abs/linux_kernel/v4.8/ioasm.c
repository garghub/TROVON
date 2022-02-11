static inline int F_1 ( struct V_1 V_2 , struct V_3 * V_4 )
{
register struct V_1 T_1 V_5 ( L_1 ) = V_2 ;
int V_6 = - V_7 ;
asm volatile(
" stsch 0(%3)\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (ccode), "=m" (*addr)
: "d" (reg1), "a" (addr)
: "cc");
return V_6 ;
}
int F_2 ( struct V_1 V_2 , struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_4 ) ;
F_3 ( V_2 , V_4 , V_6 ) ;
return V_6 ;
}
static inline int F_4 ( struct V_1 V_2 , struct V_3 * V_4 )
{
register struct V_1 T_1 V_5 ( L_1 ) = V_2 ;
int V_6 = - V_7 ;
asm volatile(
" msch 0(%2)\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (ccode)
: "d" (reg1), "a" (addr), "m" (*addr)
: "cc");
return V_6 ;
}
int F_5 ( struct V_1 V_2 , struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_4 ( V_2 , V_4 ) ;
F_6 ( V_2 , V_4 , V_6 ) ;
return V_6 ;
}
static inline int F_7 ( struct V_1 V_2 , struct V_8 * V_4 )
{
register struct V_1 T_1 V_5 ( L_1 ) = V_2 ;
int V_6 ;
asm volatile(
" tsch 0(%3)\n"
" ipm %0\n"
" srl %0,28"
: "=d" (ccode), "=m" (*addr)
: "d" (reg1), "a" (addr)
: "cc");
return V_6 ;
}
int F_8 ( struct V_1 V_2 , struct V_8 * V_4 )
{
int V_6 ;
V_6 = F_7 ( V_2 , V_4 ) ;
F_9 ( V_2 , V_4 , V_6 ) ;
return V_6 ;
}
static inline int F_10 ( struct V_1 V_2 , union V_9 * V_4 )
{
register struct V_1 T_1 V_5 ( L_1 ) = V_2 ;
int V_6 = - V_7 ;
asm volatile(
" ssch 0(%2)\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "+d" (ccode)
: "d" (reg1), "a" (addr), "m" (*addr)
: "cc", "memory");
return V_6 ;
}
int F_11 ( struct V_1 V_2 , union V_9 * V_4 )
{
int V_6 ;
V_6 = F_10 ( V_2 , V_4 ) ;
F_12 ( V_2 , V_4 , V_6 ) ;
return V_6 ;
}
static inline int F_13 ( struct V_1 V_2 )
{
register struct V_1 T_1 V_5 ( L_1 ) = V_2 ;
int V_6 ;
asm volatile(
" csch\n"
" ipm %0\n"
" srl %0,28"
: "=d" (ccode)
: "d" (reg1)
: "cc");
return V_6 ;
}
int F_14 ( struct V_1 V_2 )
{
int V_6 ;
V_6 = F_13 ( V_2 ) ;
F_15 ( V_2 , V_6 ) ;
return V_6 ;
}
int F_16 ( struct V_10 * V_4 )
{
int V_6 ;
asm volatile(
" tpi 0(%2)\n"
" ipm %0\n"
" srl %0,28"
: "=d" (ccode), "=m" (*addr)
: "a" (addr)
: "cc");
F_17 ( V_4 , V_6 ) ;
return V_6 ;
}
int F_18 ( void * V_11 )
{
typedef struct { char _ [ 4096 ] ; } T_2;
int V_12 ;
asm volatile(
" .insn rre,0xb25f0000,%2,0\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (cc), "=m" (*(addr_type *) chsc_area)
: "d" (chsc_area), "m" (*(addr_type *) chsc_area)
: "cc");
F_19 ( V_11 , V_12 ) ;
return V_12 ;
}
static inline int F_20 ( struct V_13 V_14 )
{
register struct V_13 T_1 V_5 ( L_1 ) = V_14 ;
int V_6 ;
asm volatile(
" lr 1,%1\n"
" rchp\n"
" ipm %0\n"
" srl %0,28"
: "=d" (ccode) : "d" (reg1) : "cc");
return V_6 ;
}
int F_21 ( struct V_13 V_14 )
{
int V_6 ;
V_6 = F_20 ( V_14 ) ;
F_22 ( V_14 , V_6 ) ;
return V_6 ;
}
static inline int F_23 ( struct V_1 V_2 )
{
register struct V_1 T_1 V_5 ( L_1 ) = V_2 ;
int V_6 ;
asm volatile(
" rsch\n"
" ipm %0\n"
" srl %0,28"
: "=d" (ccode)
: "d" (reg1)
: "cc", "memory");
return V_6 ;
}
int F_24 ( struct V_1 V_2 )
{
int V_6 ;
V_6 = F_23 ( V_2 ) ;
F_25 ( V_2 , V_6 ) ;
return V_6 ;
}
static inline int F_26 ( struct V_1 V_2 )
{
register struct V_1 T_1 V_5 ( L_1 ) = V_2 ;
int V_6 ;
asm volatile(
" hsch\n"
" ipm %0\n"
" srl %0,28"
: "=d" (ccode)
: "d" (reg1)
: "cc");
return V_6 ;
}
int F_27 ( struct V_1 V_2 )
{
int V_6 ;
V_6 = F_26 ( V_2 ) ;
F_28 ( V_2 , V_6 ) ;
return V_6 ;
}
static inline int F_29 ( struct V_1 V_2 )
{
register struct V_1 T_1 V_5 ( L_1 ) = V_2 ;
int V_6 ;
asm volatile(
" xsch\n"
" ipm %0\n"
" srl %0,28"
: "=d" (ccode)
: "d" (reg1)
: "cc");
return V_6 ;
}
int F_30 ( struct V_1 V_2 )
{
int V_6 ;
V_6 = F_29 ( V_2 ) ;
F_31 ( V_2 , V_6 ) ;
return V_6 ;
}
int F_32 ( struct V_15 * V_15 )
{
int V_6 ;
asm volatile(
" stcrw 0(%2)\n"
" ipm %0\n"
" srl %0,28\n"
: "=d" (ccode), "=m" (*crw)
: "a" (crw)
: "cc");
F_33 ( V_15 , V_6 ) ;
return V_6 ;
}
