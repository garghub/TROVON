static T_1 int F_1 ( struct V_1 * V_2 ,
const union V_3 * V_4 )
{
T_2 V_5 ;
do {
V_5 = F_2 ( V_4 ) ;
V_2 -> V_6 = V_4 -> V_7 ;
V_2 -> V_8 = V_4 -> V_9 >> V_4 -> V_10 ;
} while ( F_3 ( V_4 , V_5 ) );
return 0 ;
}
static T_1 int F_4 ( struct V_1 * V_2 ,
const union V_3 * V_4 )
{
T_2 V_5 ;
T_2 V_11 ;
T_2 V_12 ;
do {
V_5 = F_2 ( V_4 ) ;
V_2 -> V_6 = V_4 -> V_7 ;
V_2 -> V_8 = V_4 -> V_9 >> V_4 -> V_10 ;
V_11 = V_4 -> V_13 ;
V_12 = V_4 -> V_14 ;
} while ( F_3 ( V_4 , V_5 ) );
V_2 -> V_6 += V_11 ;
F_5 ( V_2 , V_12 ) ;
return 0 ;
}
static T_1 T_3 F_6 ( void )
{
unsigned int V_15 ;
__asm__ __volatile__(
" .set push\n"
" .set mips32r2\n"
" rdhwr %0, $2\n"
" .set pop\n"
: "=r" (count));
return V_15 ;
}
static T_1 T_3 F_7 ( const union V_3 * V_4 )
{
void T_4 * V_16 = F_8 ( V_4 ) ;
T_2 V_17 , V_18 , V_19 ;
do {
V_17 = F_9 ( V_16 + V_20 ) ;
V_19 = F_9 ( V_16 + V_21 ) ;
V_18 = F_9 ( V_16 + V_20 ) ;
} while ( V_18 != V_17 );
return ( ( ( T_3 ) V_17 ) << 32 ) + V_19 ;
}
static T_1 T_3 F_10 ( const union V_3 * V_4 )
{
T_3 V_22 , V_23 , V_24 ;
switch ( V_4 -> V_25 ) {
#ifdef F_11
case V_26 :
V_22 = F_6 () ;
break;
#endif
#ifdef F_12
case V_27 :
V_22 = F_7 ( V_4 ) ;
break;
#endif
default:
return 0 ;
}
V_23 = ( V_22 - V_4 -> V_28 ) & V_4 -> V_29 ;
V_24 = ( V_23 * V_4 -> V_30 ) + V_4 -> V_9 ;
V_24 >>= V_4 -> V_10 ;
return V_24 ;
}
static T_1 int F_13 ( struct V_1 * V_2 ,
const union V_3 * V_4 )
{
T_2 V_5 ;
T_3 V_31 ;
do {
V_5 = F_2 ( V_4 ) ;
if ( V_4 -> V_25 == V_32 )
return - V_33 ;
V_2 -> V_6 = V_4 -> V_7 ;
V_31 = F_10 ( V_4 ) ;
} while ( F_3 ( V_4 , V_5 ) );
V_2 -> V_8 = 0 ;
F_5 ( V_2 , V_31 ) ;
return 0 ;
}
static T_1 int F_14 ( struct V_1 * V_2 ,
const union V_3 * V_4 )
{
T_2 V_5 ;
T_3 V_31 ;
T_2 V_11 ;
T_2 V_12 ;
do {
V_5 = F_2 ( V_4 ) ;
if ( V_4 -> V_25 == V_32 )
return - V_33 ;
V_2 -> V_6 = V_4 -> V_7 ;
V_31 = F_10 ( V_4 ) ;
V_11 = V_4 -> V_13 ;
V_12 = V_4 -> V_14 ;
} while ( F_3 ( V_4 , V_5 ) );
V_2 -> V_6 += V_11 ;
V_2 -> V_8 = 0 ;
F_5 ( V_2 , V_31 + V_12 ) ;
return 0 ;
}
int F_15 ( struct V_34 * V_35 , struct V_36 * V_37 )
{
const union V_3 * V_4 = F_16 () ;
struct V_1 V_2 ;
int V_38 ;
V_38 = F_13 ( & V_2 , V_4 ) ;
if ( V_38 )
return V_38 ;
if ( V_35 ) {
V_35 -> V_6 = V_2 . V_6 ;
V_35 -> V_39 = V_2 . V_8 / 1000 ;
}
if ( V_37 ) {
V_37 -> V_40 = V_4 -> V_40 ;
V_37 -> V_41 = V_4 -> V_41 ;
}
return 0 ;
}
int F_17 ( T_5 V_42 , struct V_1 * V_2 )
{
const union V_3 * V_4 = F_16 () ;
int V_38 ;
switch ( V_42 ) {
case V_43 :
V_38 = F_1 ( V_2 , V_4 ) ;
break;
case V_44 :
V_38 = F_4 ( V_2 , V_4 ) ;
break;
case V_45 :
V_38 = F_13 ( V_2 , V_4 ) ;
break;
case V_46 :
V_38 = F_14 ( V_2 , V_4 ) ;
break;
default:
V_38 = - V_33 ;
break;
}
return V_38 ;
}
