static T_1 long F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
register struct V_3 * T_2 V_5 ( L_1 ) = V_4 ;
register struct V_1 * T_3 V_5 ( L_2 ) = V_2 ;
register long T_4 V_5 ( L_3 ) ;
register long T_5 V_5 ( L_3 ) = V_6 ;
register long error V_5 ( L_4 ) ;
asm volatile(
" syscall\n"
: "=r" (ret), "=r" (error)
: "r" (tv), "r" (tz), "r" (nr)
: "$1", "$3", "$8", "$9", "$10", "$11", "$12", "$13",
"$14", "$15", "$24", "$25", "hi", "lo", "memory");
return error ? - T_4 : T_4 ;
}
static T_1 long F_2 ( T_6 V_7 ,
struct V_8 * V_9 )
{
register struct V_8 * T_7 V_5 ( L_1 ) = V_9 ;
register T_6 T_8 V_5 ( L_2 ) = V_7 ;
register long T_4 V_5 ( L_3 ) ;
register long T_5 V_5 ( L_3 ) = V_10 ;
register long error V_5 ( L_4 ) ;
asm volatile(
" syscall\n"
: "=r" (ret), "=r" (error)
: "r" (clkid), "r" (ts), "r" (nr)
: "$1", "$3", "$8", "$9", "$10", "$11", "$12", "$13",
"$14", "$15", "$24", "$25", "hi", "lo", "memory");
return error ? - T_4 : T_4 ;
}
static T_1 int F_3 ( struct V_8 * T_7 ,
const union V_11 * V_12 )
{
T_9 V_13 ;
do {
V_13 = F_4 ( V_12 ) ;
T_7 -> V_14 = V_12 -> V_15 ;
T_7 -> V_16 = V_12 -> V_17 >> V_12 -> V_18 ;
} while ( F_5 ( V_12 , V_13 ) );
return 0 ;
}
static T_1 int F_6 ( struct V_8 * T_7 ,
const union V_11 * V_12 )
{
T_9 V_13 ;
T_10 V_19 ;
T_10 V_20 ;
do {
V_13 = F_4 ( V_12 ) ;
T_7 -> V_14 = V_12 -> V_15 ;
T_7 -> V_16 = V_12 -> V_17 >> V_12 -> V_18 ;
V_19 = V_12 -> V_21 ;
V_20 = V_12 -> V_22 ;
} while ( F_5 ( V_12 , V_13 ) );
T_7 -> V_14 += V_19 ;
F_7 ( T_7 , V_20 ) ;
return 0 ;
}
static T_1 T_10 F_8 ( void )
{
unsigned int V_23 ;
__asm__ __volatile__(
" .set push\n"
" .set mips32r2\n"
" rdhwr %0, $2\n"
" .set pop\n"
: "=r" (count));
return V_23 ;
}
static T_1 T_10 F_9 ( const union V_11 * V_12 )
{
void T_11 * V_24 = F_10 ( V_12 ) ;
T_9 V_25 , V_26 , V_27 ;
do {
V_25 = F_11 ( V_24 + V_28 ) ;
V_27 = F_11 ( V_24 + V_29 ) ;
V_26 = F_11 ( V_24 + V_28 ) ;
} while ( V_26 != V_25 );
return ( ( ( T_10 ) V_25 ) << 32 ) + V_27 ;
}
static T_1 T_10 F_12 ( const union V_11 * V_12 )
{
T_10 V_30 , V_31 , V_32 ;
switch ( V_12 -> V_33 ) {
#ifdef F_13
case V_34 :
V_30 = F_8 () ;
break;
#endif
#ifdef F_14
case V_35 :
V_30 = F_9 ( V_12 ) ;
break;
#endif
default:
return 0 ;
}
V_31 = ( V_30 - V_12 -> V_36 ) & V_12 -> V_37 ;
V_32 = ( V_31 * V_12 -> V_38 ) + V_12 -> V_17 ;
V_32 >>= V_12 -> V_18 ;
return V_32 ;
}
static T_1 int F_15 ( struct V_8 * T_7 ,
const union V_11 * V_12 )
{
T_9 V_13 ;
T_10 V_39 ;
do {
V_13 = F_4 ( V_12 ) ;
if ( V_12 -> V_33 == V_40 )
return - V_41 ;
T_7 -> V_14 = V_12 -> V_15 ;
V_39 = F_12 ( V_12 ) ;
} while ( F_5 ( V_12 , V_13 ) );
T_7 -> V_16 = 0 ;
F_7 ( T_7 , V_39 ) ;
return 0 ;
}
static T_1 int F_16 ( struct V_8 * T_7 ,
const union V_11 * V_12 )
{
T_9 V_13 ;
T_10 V_39 ;
T_10 V_19 ;
T_10 V_20 ;
do {
V_13 = F_4 ( V_12 ) ;
if ( V_12 -> V_33 == V_40 )
return - V_41 ;
T_7 -> V_14 = V_12 -> V_15 ;
V_39 = F_12 ( V_12 ) ;
V_19 = V_12 -> V_21 ;
V_20 = V_12 -> V_22 ;
} while ( F_5 ( V_12 , V_13 ) );
T_7 -> V_14 += V_19 ;
T_7 -> V_16 = 0 ;
F_7 ( T_7 , V_39 + V_20 ) ;
return 0 ;
}
int F_17 ( struct V_1 * T_3 , struct V_3 * T_2 )
{
const union V_11 * V_12 = F_18 () ;
struct V_8 T_7 ;
int T_4 ;
T_4 = F_15 ( & T_7 , V_12 ) ;
if ( T_4 )
return F_1 ( T_3 , T_2 ) ;
if ( T_3 ) {
T_3 -> V_14 = T_7 . V_14 ;
T_3 -> V_42 = T_7 . V_16 / 1000 ;
}
if ( T_2 ) {
T_2 -> V_43 = V_12 -> V_43 ;
T_2 -> V_44 = V_12 -> V_44 ;
}
return 0 ;
}
int F_19 ( T_6 T_8 , struct V_8 * T_7 )
{
const union V_11 * V_12 = F_18 () ;
int T_4 = - 1 ;
switch ( T_8 ) {
case V_45 :
T_4 = F_3 ( T_7 , V_12 ) ;
break;
case V_46 :
T_4 = F_6 ( T_7 , V_12 ) ;
break;
case V_47 :
T_4 = F_15 ( T_7 , V_12 ) ;
break;
case V_48 :
T_4 = F_16 ( T_7 , V_12 ) ;
break;
default:
break;
}
if ( T_4 )
T_4 = F_2 ( T_8 , T_7 ) ;
return T_4 ;
}
