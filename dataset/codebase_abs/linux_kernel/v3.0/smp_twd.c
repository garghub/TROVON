static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
switch ( V_2 ) {
case V_6 :
V_5 = V_7 | V_8
| V_9 ;
F_2 ( V_10 / V_11 , V_12 + V_13 ) ;
break;
case V_14 :
V_5 = V_8 | V_15 ;
break;
case V_16 :
case V_17 :
default:
V_5 = 0 ;
}
F_2 ( V_5 , V_12 + V_18 ) ;
}
static int F_3 ( unsigned long V_19 ,
struct V_3 * V_20 )
{
unsigned long V_5 = F_4 ( V_12 + V_18 ) ;
V_5 |= V_7 ;
F_2 ( V_19 , V_12 + V_21 ) ;
F_2 ( V_5 , V_12 + V_18 ) ;
return 0 ;
}
int F_5 ( void )
{
if ( F_4 ( V_12 + V_22 ) ) {
F_2 ( 1 , V_12 + V_22 ) ;
return 1 ;
}
return 0 ;
}
static void T_1 F_6 ( void )
{
unsigned long V_23 ;
T_2 V_24 ;
if ( V_10 == 0 ) {
F_7 ( V_25 L_1 ) ;
V_24 = F_8 () + 1 ;
while ( F_8 () < V_24 )
F_9 ( 10 ) ;
V_24 += 5 ;
F_2 ( 0x1 , V_12 + V_18 ) ;
F_2 ( 0xFFFFFFFFU , V_12 + V_21 ) ;
while ( F_8 () < V_24 )
F_9 ( 10 ) ;
V_23 = F_4 ( V_12 + V_21 ) ;
V_10 = ( 0xFFFFFFFFU - V_23 ) * ( V_11 / 5 ) ;
F_7 ( L_2 , V_10 / 1000000 ,
( V_10 / 10000 ) % 100 ) ;
}
}
void T_1 F_10 ( struct V_3 * V_4 )
{
F_6 () ;
V_4 -> V_26 = L_3 ;
V_4 -> V_27 = V_28 | V_29 |
V_30 ;
V_4 -> V_31 = 350 ;
V_4 -> V_32 = F_1 ;
V_4 -> V_33 = F_3 ;
V_4 -> V_34 = 20 ;
V_4 -> V_35 = F_11 ( V_10 , V_36 , V_4 -> V_34 ) ;
V_4 -> V_37 = F_12 ( 0xffffffff , V_4 ) ;
V_4 -> V_38 = F_12 ( 0xf , V_4 ) ;
F_13 ( V_4 -> V_39 ) ;
F_14 ( V_4 ) ;
}
