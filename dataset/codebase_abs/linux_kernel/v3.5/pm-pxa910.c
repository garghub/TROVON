int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_2 -> V_4 ) ;
T_1 V_7 = 0 , V_8 = 0 ;
if ( F_3 ( V_4 >= V_9 ) ) {
F_4 ( L_1 ) ;
return - V_10 ;
}
if ( V_3 ) {
if ( V_6 -> V_11 )
V_6 -> V_11 -> V_12 |= V_13 ;
} else {
if ( V_6 -> V_11 )
V_6 -> V_11 -> V_12 &= ~ V_13 ;
}
switch ( V_4 ) {
case V_14 :
V_7 = F_5 ( 2 ) ;
V_8 |= V_15 ;
break;
case V_16 :
V_7 = F_5 ( 3 ) | V_17 ;
V_8 |= V_18 ;
break;
case V_19 :
V_7 = F_5 ( 3 ) | V_20 ;
V_8 |= V_18 ;
break;
case V_21 :
V_7 = F_5 ( 3 ) | V_22 ;
V_8 |= V_18 ;
break;
case V_23 :
V_7 = F_5 ( 4 ) | V_24 ;
V_8 |= V_25 ;
break;
case V_26 :
V_7 = F_5 ( 4 ) | V_27 ;
V_8 |= V_25 ;
break;
case V_28 :
V_7 = F_5 ( 4 ) | V_29 ;
V_8 |= V_25 ;
break;
case V_30 :
V_7 = F_5 ( 4 ) | V_31 ;
V_8 |= V_25 ;
break;
case V_32 :
V_7 = F_5 ( 4 ) | V_33 ;
V_8 |= V_25 ;
break;
case V_34 :
V_7 = F_5 ( 4 ) | V_35 ;
V_8 |= V_25 ;
break;
case V_36 :
V_7 = F_5 ( 4 ) | V_37 ;
V_8 |= V_25 ;
break;
case V_38 :
case V_39 :
V_7 = F_5 ( 5 ) ;
V_8 |= V_40 ;
break;
case V_41 :
V_7 = F_5 ( 6 )
| V_42
| V_43 ;
V_8 |= V_44 ;
break;
case V_45 :
V_7 = F_5 ( 7 ) ;
V_8 |= V_46 ;
break;
default:
if ( V_4 >= V_47 && V_4 < V_48 ) {
V_7 = F_5 ( 2 ) ;
V_8 |= V_15 ;
} else
F_6 ( V_49 L_2 ,
V_4 ) ;
}
if ( V_3 ) {
if ( V_7 ) {
V_7 |= F_7 ( V_50 ) ;
F_8 ( V_7 , V_50 ) ;
}
if ( V_8 ) {
V_8 = ~ V_8 & F_7 ( V_51 ) ;
F_8 ( V_8 , V_51 ) ;
}
} else {
if ( V_7 ) {
V_7 = ~ V_7 & F_7 ( V_50 ) ;
F_8 ( V_7 , V_50 ) ;
}
if ( V_8 ) {
V_8 |= F_7 ( V_51 ) ;
F_8 ( V_8 , V_51 ) ;
}
}
return 0 ;
}
void F_9 ( int V_52 )
{
T_1 V_53 , V_8 ;
V_53 = F_7 ( V_54 ) ;
V_8 = F_7 ( V_51 ) ;
V_8 &= ~ ( V_55 | V_56 | V_57
| V_58 | V_59 ) ;
V_53 &= ~ ( V_60
| V_61 ) ;
switch ( V_52 ) {
case V_62 :
V_8 |= V_59 | V_56 ;
case V_63 :
V_8 |= V_64 ;
V_8 |= V_58 ;
case V_65 :
V_8 |= V_55 ;
case V_66 :
V_8 |= V_57 ;
case V_67 :
V_53 |= V_60 ;
V_53 |= V_61 ;
V_53 |= F_10 ( 3 )
| F_11 ( 3 ) ;
case V_68 :
break;
}
V_53 |= V_69 ;
V_53 |= V_70 ;
F_8 ( 0x0 , V_71 ) ;
V_8 |= V_72 | V_73 | V_74
| V_75 ;
V_8 |= V_64 ;
F_8 ( V_53 , V_54 ) ;
F_8 ( V_8 , V_51 ) ;
}
static int F_12 ( T_2 V_52 )
{
unsigned int V_53 , V_76 = 0 ;
V_76 = F_7 ( F_13 ( V_45 ) ) ;
if ( ( V_76 & 0x3 ) == 0 )
return - V_77 ;
V_53 = F_7 ( V_54 ) ;
V_53 |= V_61
| V_78 ;
F_8 ( V_53 , V_54 ) ;
F_14 () ;
while ( ! ( F_15 ( F_16 ( 0x8 ) ) & ( 1 << 16 ) ) )
F_17 ( 1 ) ;
F_18 () ;
F_19 () ;
while ( ! ( F_15 ( F_16 ( 0x8 ) ) & ( 1 << 16 ) ) )
F_17 ( 1 ) ;
V_53 = F_7 ( V_54 ) ;
V_53 &= ~ ( V_61
| V_78 ) ;
F_8 ( V_53 , V_54 ) ;
return 0 ;
}
static int F_20 ( void )
{
F_9 ( V_62 ) ;
return 0 ;
}
static void F_21 ( void )
{
F_9 ( V_68 ) ;
}
static int F_22 ( T_2 V_52 )
{
return ( ( V_52 == V_79 ) || ( V_52 == V_80 ) ) ;
}
static int T_3 F_23 ( void )
{
T_1 V_7 = 0 ;
if ( ! F_24 () )
return - V_81 ;
F_25 ( & V_82 ) ;
F_8 ( F_7 ( V_83 ) | ( 1 << 30 ) ,
V_83 ) ;
F_8 ( F_7 ( V_84 ) | ( 1 << 28 ) , V_84 ) ;
V_7 |= V_85 | V_86 ;
F_8 ( V_7 , V_50 ) ;
return 0 ;
}
