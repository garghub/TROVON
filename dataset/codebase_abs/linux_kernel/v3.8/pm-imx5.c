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
if ( F_5 () != V_28 )
F_4 ( V_4 , V_29 ) ;
if ( V_8 ) {
V_6 |= V_14 ;
V_7 |= V_14 ;
F_4 ( V_6 , V_15 ) ;
F_4 ( V_7 , V_16 ) ;
}
}
static int F_6 ( T_2 V_30 )
{
switch ( V_30 ) {
case V_31 :
F_1 ( V_21 ) ;
break;
case V_32 :
break;
default:
return - V_33 ;
}
if ( V_30 == V_31 ) {
F_7 () ;
F_8 () ;
F_4 ( 0 , V_15 ) ;
F_4 ( 0 , V_16 ) ;
}
F_9 () ;
F_1 ( V_34 ) ;
return 0 ;
}
static int F_10 ( T_2 V_30 )
{
return ( V_30 > V_35 && V_30 <= V_36 ) ;
}
static inline int F_11 ( void )
{
int V_37 = F_12 () ;
if ( F_13 ( ! V_37 ) )
F_9 () ;
return V_37 ;
}
static void F_14 ( void )
{
F_11 () ;
}
static int F_15 ( struct V_38 * V_39 ,
struct V_40 * V_41 , int V_42 )
{
int V_37 ;
V_37 = F_11 () ;
if ( V_37 < 0 )
return V_37 ;
return V_42 ;
}
static int T_3 F_16 ( void )
{
int V_37 ;
struct V_43 * V_44 = F_17 ( NULL , L_2 ) ;
if ( F_18 ( V_44 ) )
return F_19 ( V_44 ) ;
V_37 = F_20 ( V_44 ) ;
if ( V_37 )
return V_37 ;
V_45 = F_14 ;
F_1 ( V_34 ) ;
F_21 ( & V_46 ) ;
return 0 ;
}
void T_3 F_22 ( void )
{
int V_37 = F_16 () ;
if ( ! V_37 )
F_23 ( & V_47 ) ;
}
void T_3 F_24 ( void )
{
F_16 () ;
}
