static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
V_6 = F_2 ( V_5 , V_7 ) ;
V_6 = ( V_3 > 0 ) ? V_6 | V_8 : V_6 &
( ~ V_8 ) ;
F_3 ( V_5 , V_7 , V_6 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_9 ,
unsigned int V_10 , int V_11 , int V_12 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_13 = F_2 ( V_5 , V_14 ) ;
int V_15 = F_2 ( V_5 , V_16 ) ;
V_13 &= ~ V_17 ;
V_15 &= ~ V_18 ;
switch ( V_11 ) {
case 2 :
V_13 |= V_19 << V_20 ;
V_15 |= V_21 << V_22 ;
break;
case 4 :
V_13 |= V_23 << V_20 ;
V_15 |= V_24 << V_22 ;
break;
case 8 :
V_13 |= V_25 << V_20 ;
V_15 |= V_26 << V_22 ;
break;
case 16 :
V_13 |= V_27 << V_20 ;
V_15 |= V_28 << V_22 ;
break;
default:
return - V_29 ;
}
F_3 ( V_5 , V_14 , V_13 ) ;
F_3 ( V_5 , V_16 , V_15 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_30 ,
unsigned int V_31 )
{
struct V_4 * V_5 = V_30 -> V_5 ;
int V_32 , V_33 , V_13 ;
V_32 = F_2 ( V_5 , V_34 ) ;
V_33 = F_2 ( V_5 , V_16 ) ;
V_13 = F_2 ( V_5 , V_14 ) ;
switch ( V_31 & V_35 ) {
case V_36 :
V_32 &= ~ V_37 ;
V_32 |= V_38 ;
break;
case V_39 :
V_32 &= ~ V_37 ;
V_32 |= V_40 ;
break;
default:
return - V_29 ;
}
switch ( V_31 & V_41 ) {
case V_42 :
V_33 &= ~ V_43 ;
V_33 &= ~ V_44 ;
V_13 &= ~ V_45 ;
V_13 &= ~ V_46 ;
break;
case V_47 :
V_33 |= V_43 ;
V_33 &= ~ V_44 ;
V_13 |= V_45 ;
V_13 &= ~ V_46 ;
break;
case V_48 :
V_33 &= ~ V_43 ;
V_33 |= V_44 ;
V_13 &= ~ V_45 ;
V_13 |= V_46 ;
break;
case V_49 :
V_33 |= V_43 ;
V_33 |= V_44 ;
V_13 |= V_45 ;
V_13 |= V_46 ;
break;
default:
return - V_29 ;
}
switch ( V_31 & V_50 ) {
case V_51 :
V_33 |= V_52 ;
V_33 |= V_53 ;
V_13 |= V_54 ;
V_13 |= V_55 ;
break;
case V_56 :
V_33 |= V_52 ;
V_33 &= ~ V_53 ;
V_13 |= V_54 ;
V_13 &= ~ V_55 ;
break;
case V_57 :
V_33 &= ~ V_52 ;
V_33 |= V_53 ;
V_13 &= ~ V_54 ;
V_13 |= V_55 ;
break;
case V_58 :
V_33 &= ~ V_52 ;
V_33 &= ~ V_53 ;
V_13 &= ~ V_54 ;
V_13 &= ~ V_55 ;
break;
default:
return - V_29 ;
}
F_3 ( V_5 , V_34 , V_32 ) ;
F_3 ( V_5 , V_16 , V_33 ) ;
F_3 ( V_5 , V_14 , V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_30 ,
int V_59 , unsigned int V_60 , int V_61 )
{
struct V_4 * V_5 = V_30 -> V_5 ;
struct V_62 * V_63 = F_7 ( V_5 ) ;
switch ( V_60 ) {
case 12288000 :
case 18432000 :
case 24576000 :
case 36864000 :
V_63 -> V_64 = V_60 ;
return 0 ;
}
return - V_29 ;
}
static int F_8 ( struct V_65 * V_66 ,
struct V_67 * V_68 ,
struct V_1 * V_2 )
{
int V_69 = 0 , V_6 = 0 , V_70 = 0 ;
struct V_71 * V_72 = V_66 -> V_73 ;
struct V_4 * V_5 = V_72 -> V_5 ;
struct V_62 * V_63 = F_7 ( V_5 ) ;
switch ( F_9 ( V_68 ) ) {
case V_74 :
V_69 = 3 ;
break;
case V_75 :
V_69 = 1 ;
break;
case V_76 :
case V_77 :
V_69 = 0 ;
break;
}
switch ( V_63 -> V_64 ) {
case 12288000 :
V_70 = V_78 ;
break;
case 18432000 :
V_70 = V_79 ;
break;
case 24576000 :
V_70 = V_80 ;
break;
case 36864000 :
V_70 = V_81 ;
break;
}
V_6 = F_2 ( V_5 , V_82 ) ;
V_6 = ( V_6 & V_83 ) | V_70 ;
F_3 ( V_5 , V_82 , V_6 ) ;
V_6 = F_2 ( V_5 , V_7 ) ;
V_6 = ( V_6 & ( ~ V_84 ) )
| ( V_69 << V_85 ) ;
F_3 ( V_5 , V_7 , V_6 ) ;
V_6 = F_2 ( V_5 , V_34 ) ;
V_6 = ( V_6 & ( ~ V_86 ) ) | V_69 ;
F_3 ( V_5 , V_34 , V_6 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_62 * V_63 = F_7 ( V_5 ) ;
struct V_87 * V_88 = & V_5 -> V_88 ;
int V_89 ;
if ( V_63 -> V_90 == V_91 )
V_89 = F_11 ( V_5 , 8 , 8 , V_63 -> V_90 ) ;
else
V_89 = F_11 ( V_5 , 16 , 8 , V_63 -> V_90 ) ;
if ( V_89 < 0 ) {
F_12 ( V_5 -> V_92 , L_1 , V_89 ) ;
return V_89 ;
}
F_3 ( V_5 , V_93 , 0x0 ) ;
F_3 ( V_5 , V_7 , 0x1A ) ;
F_3 ( V_5 , V_94 , 0x41 ) ;
F_3 ( V_5 , V_95 , 0x3 ) ;
F_3 ( V_5 , V_34 , 0x43 ) ;
F_3 ( V_5 , V_82 , 0x99 ) ;
F_3 ( V_5 , V_96 , 0x04 ) ;
F_13 ( V_5 , V_97 ,
F_14 ( V_97 ) ) ;
F_15 ( V_88 , V_98 ,
F_14 ( V_98 ) ) ;
F_16 ( V_88 , V_99 , F_14 ( V_99 ) ) ;
return V_89 ;
}
static int T_1 F_17 ( struct V_100 * V_101 )
{
struct V_62 * V_63 ;
int V_89 ;
V_63 = F_18 ( sizeof( struct V_62 ) , V_102 ) ;
if ( V_63 == NULL )
return - V_103 ;
F_19 ( V_101 , V_63 ) ;
V_63 -> V_90 = V_104 ;
V_89 = F_20 ( & V_101 -> V_92 ,
& V_105 , & V_106 , 1 ) ;
if ( V_89 < 0 )
F_21 ( V_63 ) ;
return V_89 ;
}
static int T_2 F_22 ( struct V_100 * V_101 )
{
F_23 ( & V_101 -> V_92 ) ;
F_21 ( F_24 ( V_101 ) ) ;
return 0 ;
}
static int T_1 F_25 ( struct V_107 * V_108 ,
const struct V_109 * V_110 )
{
struct V_62 * V_63 ;
int V_89 ;
V_63 = F_18 ( sizeof( struct V_62 ) , V_102 ) ;
if ( V_63 == NULL )
return - V_103 ;
F_26 ( V_108 , V_63 ) ;
V_63 -> V_90 = V_91 ;
V_89 = F_20 ( & V_108 -> V_92 ,
& V_105 , & V_106 , 1 ) ;
if ( V_89 < 0 )
F_21 ( V_63 ) ;
return V_89 ;
}
static int T_2 F_27 ( struct V_107 * V_108 )
{
F_23 ( & V_108 -> V_92 ) ;
F_21 ( F_28 ( V_108 ) ) ;
return 0 ;
}
static int T_3 F_29 ( void )
{
int V_89 ;
#if F_30 ( V_111 ) || F_30 ( V_112 )
V_89 = F_31 ( & V_113 ) ;
if ( V_89 != 0 ) {
F_32 ( V_114 L_2 ,
V_89 ) ;
}
#endif
#if F_30 ( V_115 )
V_89 = F_33 ( & V_116 ) ;
if ( V_89 != 0 ) {
F_32 ( V_114 L_3 ,
V_89 ) ;
}
#endif
return V_89 ;
}
static void T_4 F_34 ( void )
{
#if F_30 ( V_115 )
F_35 ( & V_116 ) ;
#endif
#if F_30 ( V_111 ) || F_30 ( V_112 )
F_36 ( & V_113 ) ;
#endif
}
