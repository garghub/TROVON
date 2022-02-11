void T_1 F_1 ( void T_2 * V_1 )
{
V_2 = V_1 ;
}
static void F_2 ( enum V_3 V_4 )
{
T_3 V_5 , V_6 , V_7 ;
T_3 V_8 , V_9 ;
int V_10 = 0 ;
V_5 = F_3 ( V_11 + V_12 ) &
~ ( V_13 ) ;
V_7 = F_3 ( V_2 + V_14 ) &
~ ( V_15 ) ;
V_6 = F_3 ( V_16 + V_17 ) &
~ ( V_18 ) ;
V_8 = F_3 ( V_16 + V_19 ) &
~ ( V_18 ) ;
V_9 = F_3 ( V_16 + V_20 ) &
~ ( V_18 ) ;
switch ( V_4 ) {
case V_21 :
break;
case V_22 :
V_7 |= 0x1 << V_23 ;
break;
case V_24 :
case V_25 :
V_5 |= V_13
| V_26 ;
if ( V_4 == V_24 ) {
V_7 |= 0x1 << V_23 ;
V_7 &= ~ V_27 ;
V_7 &= ~ V_28 ;
V_10 = 0 ;
} else {
V_7 |= 0x2 << V_23 ;
V_7 |= 0x3 << V_29 ;
V_7 |= V_27 ;
V_7 |= V_28 ;
V_10 = 1 ;
}
V_6 |= V_18 ;
break;
case V_30 :
V_7 |= 0x2 << V_23 ;
break;
default:
F_4 ( V_31 L_1 , V_4 ) ;
return;
}
F_5 ( V_5 , V_11 + V_12 ) ;
F_5 ( V_7 , V_2 + V_14 ) ;
F_5 ( V_6 , V_16 + V_17 ) ;
F_5 ( V_6 , V_16 + V_32 ) ;
if ( V_10 ) {
V_8 |= V_18 ;
V_9 |= V_18 ;
F_5 ( V_8 , V_16 + V_19 ) ;
F_5 ( V_9 , V_16 + V_20 ) ;
}
}
static int F_6 ( T_4 V_33 )
{
switch ( V_33 ) {
case V_34 :
F_2 ( V_25 ) ;
break;
case V_35 :
break;
default:
return - V_36 ;
}
if ( V_33 == V_34 ) {
F_7 () ;
F_8 () ;
F_5 ( 0 , V_16 + V_19 ) ;
F_5 ( 0 , V_16 + V_20 ) ;
}
F_9 () ;
F_2 ( V_37 ) ;
return 0 ;
}
static int F_10 ( T_4 V_33 )
{
return ( V_33 > V_38 && V_33 <= V_39 ) ;
}
static inline int F_11 ( void )
{
int V_40 = F_12 () ;
if ( F_13 ( ! V_40 ) )
F_9 () ;
return V_40 ;
}
static void F_14 ( void )
{
F_11 () ;
}
static int T_1 F_15 ( const struct V_41 * V_42 )
{
int V_40 ;
struct V_43 * V_44 = F_16 ( NULL , L_2 ) ;
if ( F_17 ( V_44 ) )
return F_18 ( V_44 ) ;
V_40 = F_19 ( V_44 ) ;
if ( V_40 )
return V_40 ;
V_45 = F_14 ;
V_11 = F_20 ( V_42 -> V_46 , V_47 ) ;
V_16 = F_20 ( V_42 -> V_48 , V_47 ) ;
F_21 ( ! V_2 || ! V_11 || ! V_16 ) ;
F_2 ( V_37 ) ;
V_40 = F_22 () ;
if ( V_40 )
F_23 ( L_3 , V_49 , V_40 ) ;
F_24 ( & V_50 ) ;
return 0 ;
}
void T_1 F_25 ( void )
{
F_15 ( & V_51 ) ;
}
void T_1 F_26 ( void )
{
F_15 ( & V_52 ) ;
}
