void F_1 ( enum V_1 V_2 )
{
T_1 V_3 , V_4 , V_5 ;
T_1 V_6 , V_7 ;
int V_8 = 0 ;
V_3 = F_2 ( V_9 ) &
~ ( V_10 ) ;
V_5 = F_2 ( V_11 ) & ~ ( V_12 ) ;
V_4 = F_2 ( V_13 ) & ~ ( V_14 ) ;
V_6 = F_2 ( V_15 ) & ~ ( V_14 ) ;
V_7 = F_2 ( V_16 ) & ~ ( V_14 ) ;
switch ( V_2 ) {
case V_17 :
break;
case V_18 :
V_5 |= 0x1 << V_19 ;
break;
case V_20 :
case V_21 :
V_3 |= V_10
| V_22 ;
if ( V_2 == V_20 ) {
V_5 |= 0x1 << V_19 ;
V_5 &= ~ V_23 ;
V_5 &= ~ V_24 ;
V_8 = 0 ;
} else {
V_5 |= 0x2 << V_19 ;
V_5 |= 0x3 << V_25 ;
V_5 |= V_23 ;
V_5 |= V_24 ;
V_8 = 1 ;
}
V_4 |= V_14 ;
break;
case V_26 :
V_5 |= 0x2 << V_19 ;
break;
default:
F_3 ( V_27 L_1 , V_2 ) ;
return;
}
F_4 ( V_3 , V_9 ) ;
F_4 ( V_5 , V_11 ) ;
F_4 ( V_4 , V_13 ) ;
if ( F_5 () != V_28 )
F_4 ( V_4 , V_29 ) ;
if ( V_8 ) {
V_6 |= V_14 ;
V_7 |= V_14 ;
F_4 ( V_6 , V_15 ) ;
F_4 ( V_7 , V_16 ) ;
}
}
static int F_6 ( void )
{
return F_7 ( V_30 ) ;
}
static int F_8 ( T_2 V_31 )
{
switch ( V_31 ) {
case V_32 :
F_1 ( V_21 ) ;
break;
case V_33 :
F_1 ( V_20 ) ;
break;
default:
return - V_34 ;
}
if ( V_31 == V_32 ) {
F_9 () ;
F_10 () ;
F_4 ( 0 , V_15 ) ;
F_4 ( 0 , V_16 ) ;
}
F_11 () ;
return 0 ;
}
static void F_12 ( void )
{
F_13 ( V_30 ) ;
}
static int F_14 ( T_2 V_31 )
{
return ( V_31 > V_35 && V_31 <= V_36 ) ;
}
static int T_3 F_15 ( void )
{
if ( ! F_16 () && ! F_17 () )
return 0 ;
if ( V_30 == NULL )
V_30 = F_18 ( NULL , L_2 ) ;
if ( ! F_19 ( V_30 ) ) {
if ( F_16 () )
F_20 ( & V_37 ) ;
} else
return - V_38 ;
return 0 ;
}
