static void F_1 ( enum V_1 V_2 )
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
F_4 ( V_4 , V_28 ) ;
if ( V_8 ) {
V_6 |= V_14 ;
V_7 |= V_14 ;
F_4 ( V_6 , V_15 ) ;
F_4 ( V_7 , V_16 ) ;
}
}
static int F_5 ( T_2 V_29 )
{
switch ( V_29 ) {
case V_30 :
F_1 ( V_21 ) ;
break;
case V_31 :
break;
default:
return - V_32 ;
}
if ( V_29 == V_30 ) {
F_6 () ;
F_7 () ;
F_4 ( 0 , V_15 ) ;
F_4 ( 0 , V_16 ) ;
}
F_8 () ;
F_1 ( V_33 ) ;
return 0 ;
}
static int F_9 ( T_2 V_29 )
{
return ( V_29 > V_34 && V_29 <= V_35 ) ;
}
static inline int F_10 ( void )
{
int V_36 = F_11 () ;
if ( F_12 ( ! V_36 ) )
F_8 () ;
return V_36 ;
}
static void F_13 ( void )
{
F_10 () ;
}
static int T_3 F_14 ( void )
{
int V_36 ;
struct V_37 * V_38 = F_15 ( NULL , L_2 ) ;
if ( F_16 ( V_38 ) )
return F_17 ( V_38 ) ;
V_36 = F_18 ( V_38 ) ;
if ( V_36 )
return V_36 ;
V_39 = F_13 ;
F_1 ( V_33 ) ;
return F_19 () ;
}
void T_3 F_20 ( void )
{
int V_36 = F_14 () ;
if ( ! V_36 )
F_21 ( & V_40 ) ;
}
void T_3 F_22 ( void )
{
F_14 () ;
}
