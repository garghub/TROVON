static T_1 T_2 F_1 ( void )
{
return ( T_1 ) F_2 ( V_1 + F_3 ( V_2 ) ) ;
}
static void F_4 ( unsigned char V_3 )
{
T_3 V_4 = F_2 ( V_1 + V_5 ) ;
F_5 ( V_4 & ~ F_6 ( V_3 ) , V_1 + V_5 ) ;
}
static void F_7 ( unsigned char V_3 , unsigned long V_6 )
{
F_5 ( V_6 , V_1 + F_3 ( V_3 ) ) ;
}
static void F_8 ( unsigned char V_3 , bool V_7 )
{
T_3 V_4 = F_2 ( V_1 + V_5 ) ;
if ( V_7 )
V_4 |= F_9 ( V_3 ) ;
else
V_4 &= ~ F_9 ( V_3 ) ;
F_5 ( V_4 | F_6 ( V_3 ) , V_1 + V_5 ) ;
}
static void F_10 ( enum V_8 V_9 ,
struct V_10 * V_11 )
{
switch ( V_9 ) {
case V_12 :
F_4 ( V_13 ) ;
F_7 ( V_13 , V_14 / V_15 - 1 ) ;
F_8 ( V_13 , true ) ;
break;
case V_16 :
F_4 ( V_13 ) ;
F_8 ( V_13 , false ) ;
break;
case V_17 :
case V_18 :
default:
F_4 ( V_13 ) ;
break;
}
}
static int F_11 ( unsigned long V_19 ,
struct V_10 * V_20 )
{
F_4 ( V_13 ) ;
F_7 ( V_13 , V_19 ) ;
F_8 ( V_13 , false ) ;
return 0 ;
}
static T_4 F_12 ( int V_21 , void * V_22 )
{
struct V_10 * V_19 = (struct V_10 * ) V_22 ;
V_19 -> V_23 ( V_19 ) ;
return V_24 ;
}
static void T_5 F_13 ( struct V_25 * V_26 )
{
T_3 V_4 ;
int V_27 , V_21 ;
V_1 = F_14 ( V_26 , 0 , L_1 ) ;
if ( F_15 ( V_1 ) )
F_16 ( L_2 ) ;
V_21 = F_17 ( V_26 , 0 ) ;
if ( V_21 <= 0 )
F_16 ( L_3 ) ;
V_4 = F_2 ( V_1 + V_5 ) ;
V_4 &= ~ V_28 ;
V_4 |= V_29 << F_18 ( V_2 ) ;
F_5 ( V_4 , V_1 + V_5 ) ;
F_19 ( F_1 , 32 , V_14 ) ;
F_20 ( V_1 + F_3 ( V_2 ) , V_26 -> V_30 ,
1000 * 1000 , 300 , 32 , V_31 ) ;
V_4 &= ~ V_32 ;
V_4 |= V_33 << F_18 ( V_13 ) ;
F_5 ( V_4 , V_1 + V_5 ) ;
F_4 ( V_13 ) ;
V_27 = F_21 ( V_21 , & V_34 ) ;
if ( V_27 )
F_22 ( L_4 , V_21 ) ;
V_35 . V_36 = V_37 ;
V_35 . V_21 = V_21 ;
F_23 ( & V_35 , V_14 ,
1 , 0xfffe ) ;
}
