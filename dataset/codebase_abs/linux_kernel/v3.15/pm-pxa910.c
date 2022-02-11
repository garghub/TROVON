int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 = 0 , V_5 = 0 ;
int V_6 = V_2 -> V_6 ;
switch ( V_6 ) {
case V_7 :
V_4 = F_2 ( 2 ) ;
V_5 |= V_8 ;
break;
case V_9 :
V_4 = F_2 ( 3 ) | V_10 ;
V_5 |= V_11 ;
break;
case V_12 :
V_4 = F_2 ( 3 ) | V_13 ;
V_5 |= V_11 ;
break;
case V_14 :
V_4 = F_2 ( 3 ) | V_15 ;
V_5 |= V_11 ;
break;
case V_16 :
V_4 = F_2 ( 4 ) | V_17 ;
V_5 |= V_18 ;
break;
case V_19 :
V_4 = F_2 ( 4 ) | V_20 ;
V_5 |= V_18 ;
break;
case V_21 :
V_4 = F_2 ( 4 ) | V_22 ;
V_5 |= V_18 ;
break;
case V_23 :
V_4 = F_2 ( 4 ) | V_24 ;
V_5 |= V_18 ;
break;
case V_25 :
V_4 = F_2 ( 4 ) | V_26 ;
V_5 |= V_18 ;
break;
case V_27 :
V_4 = F_2 ( 4 ) | V_28 ;
V_5 |= V_18 ;
break;
case V_29 :
V_4 = F_2 ( 4 ) | V_30 ;
V_5 |= V_18 ;
break;
case V_31 :
case V_32 :
V_4 = F_2 ( 5 ) ;
V_5 |= V_33 ;
break;
case V_34 :
V_4 = F_2 ( 6 )
| V_35
| V_36 ;
V_5 |= V_37 ;
break;
case V_38 :
V_4 = F_2 ( 7 ) ;
V_5 |= V_39 ;
break;
default:
if ( V_6 >= V_40 && V_6 < V_41 ) {
V_4 = F_2 ( 2 ) ;
V_5 |= V_8 ;
} else {
F_3 ( V_42 L_1 ,
V_6 ) ;
}
}
if ( V_3 ) {
if ( V_4 ) {
V_4 |= F_4 ( V_43 ) ;
F_5 ( V_4 , V_43 ) ;
}
if ( V_5 ) {
V_5 = ~ V_5 & F_4 ( V_44 ) ;
F_5 ( V_5 , V_44 ) ;
}
} else {
if ( V_4 ) {
V_4 = ~ V_4 & F_4 ( V_43 ) ;
F_5 ( V_4 , V_43 ) ;
}
if ( V_5 ) {
V_5 |= F_4 ( V_44 ) ;
F_5 ( V_5 , V_44 ) ;
}
}
return 0 ;
}
void F_6 ( int V_45 )
{
T_1 V_46 , V_5 ;
V_46 = F_4 ( V_47 ) ;
V_5 = F_4 ( V_44 ) ;
V_5 &= ~ ( V_48 | V_49 | V_50
| V_51 | V_52 ) ;
V_46 &= ~ ( V_53
| V_54 ) ;
switch ( V_45 ) {
case V_55 :
V_5 |= V_52 | V_49 ;
case V_56 :
V_5 |= V_57 ;
V_5 |= V_51 ;
case V_58 :
V_5 |= V_48 ;
case V_59 :
V_5 |= V_50 ;
case V_60 :
V_46 |= V_53 ;
V_46 |= V_54 ;
V_46 |= F_7 ( 3 )
| F_8 ( 3 ) ;
case V_61 :
break;
}
V_46 |= V_62 ;
V_46 |= V_63 ;
F_5 ( 0x0 , V_64 ) ;
V_5 |= V_65 | V_66 | V_67
| V_68 ;
V_5 |= V_57 ;
F_5 ( V_46 , V_47 ) ;
F_5 ( V_5 , V_44 ) ;
}
static int F_9 ( T_2 V_45 )
{
unsigned int V_46 , V_69 = 0 ;
V_69 = F_4 ( F_10 ( V_38 ) ) ;
if ( ( V_69 & 0x3 ) == 0 )
return - V_70 ;
V_46 = F_4 ( V_47 ) ;
V_46 |= V_54
| V_71 ;
F_5 ( V_46 , V_47 ) ;
F_11 () ;
while ( ! ( F_12 ( F_13 ( 0x8 ) ) & ( 1 << 16 ) ) )
F_14 ( 1 ) ;
F_15 () ;
F_16 () ;
while ( ! ( F_12 ( F_13 ( 0x8 ) ) & ( 1 << 16 ) ) )
F_14 ( 1 ) ;
V_46 = F_4 ( V_47 ) ;
V_46 &= ~ ( V_54
| V_71 ) ;
F_5 ( V_46 , V_47 ) ;
return 0 ;
}
static int F_17 ( void )
{
F_6 ( V_55 ) ;
return 0 ;
}
static void F_18 ( void )
{
F_6 ( V_61 ) ;
}
static int F_19 ( T_2 V_45 )
{
return ( ( V_45 == V_72 ) || ( V_45 == V_73 ) ) ;
}
static int T_3 F_20 ( void )
{
T_1 V_4 = 0 ;
if ( ! F_21 () )
return - V_74 ;
F_22 ( & V_75 ) ;
F_5 ( F_4 ( V_76 ) | ( 1 << 30 ) ,
V_76 ) ;
F_5 ( F_4 ( V_77 ) | ( 1 << 28 ) , V_77 ) ;
V_4 |= V_78 | V_79 ;
F_5 ( V_4 , V_43 ) ;
return 0 ;
}
