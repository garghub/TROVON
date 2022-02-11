void F_1 ( struct V_1 * V_2 )
{
asm volatile(
".set push\n"
".set noat\n"
"dmfc2 $1, $0, 0\n"
"sd $1, 0(%1)\n"
"dmfc2 $1, $0, 1\n"
"sd $1, 8(%1)\n"
"dmfc2 $1, $0, 2\n"
"sd $1, 16(%1)\n"
"dmfc2 $1, $0, 3\n"
"sd $1, 24(%1)\n"
"dmfc2 $1, $1, 0\n"
"sd $1, 0(%2)\n"
"dmfc2 $1, $1, 1\n"
"sd $1, 8(%2)\n"
"dmfc2 $1, $1, 2\n"
"sd $1, 16(%2)\n"
"dmfc2 $1, $1, 3\n"
"sd $1, 24(%2)\n"
".set pop\n"
: "=m"(*r)
: "r"(r->tx), "r"(r->rx));
V_2 -> V_3 = F_2 ( V_4 , 0 ) ;
V_2 -> V_5 = F_2 ( V_6 , 0 ) & 0x0fffffff ;
}
void F_3 ( struct V_1 * V_2 )
{
T_1 V_7 ;
asm volatile(
".set push\n"
".set noat\n"
"ld $1, 0(%1)\n"
"dmtc2 $1, $0, 0\n"
"ld $1, 8(%1)\n"
"dmtc2 $1, $0, 1\n"
"ld $1, 16(%1)\n"
"dmtc2 $1, $0, 2\n"
"ld $1, 24(%1)\n"
"dmtc2 $1, $0, 3\n"
"ld $1, 0(%2)\n"
"dmtc2 $1, $1, 0\n"
"ld $1, 8(%2)\n"
"dmtc2 $1, $1, 1\n"
"ld $1, 16(%2)\n"
"dmtc2 $1, $1, 2\n"
"ld $1, 24(%2)\n"
"dmtc2 $1, $1, 3\n"
".set pop\n"
: : "m"(*r), "r"(r->tx), "r"(r->rx));
F_4 ( V_4 , 0 , V_2 -> V_3 ) ;
V_7 = F_2 ( V_6 , 0 ) & 0xf0000000u ;
F_4 ( V_6 , 0 , V_2 -> V_5 | V_7 ) ;
}
static int F_5 ( struct V_8 * V_9 , unsigned long V_10 ,
void * V_11 )
{
unsigned long V_12 ;
unsigned int V_13 ;
switch ( V_10 ) {
case V_14 :
if ( ! F_6 ( V_15 ) || ! F_6 ( V_16 ) )
break;
F_7 ( V_12 ) ;
F_8 ( V_17 ) |= V_18 ;
V_13 = F_9 () ;
F_10 ( V_13 | V_18 ) ;
F_3 ( & ( V_17 -> V_19 . V_20 ) ) ;
F_10 ( V_13 & ~ V_18 ) ;
F_11 ( V_12 ) ;
F_12 ( L_1 ,
V_17 -> V_21 , V_17 -> V_22 ) ;
return V_23 ;
}
return V_24 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( F_5 , 0 ) ;
}
