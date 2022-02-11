static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_3 )
F_2 ( V_5 , V_6 ,
V_7 ,
V_7 ) ;
else
F_2 ( V_5 , V_6 ,
V_7 , 0 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_8 ,
unsigned int V_9 , int V_10 , int V_11 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_12 = F_4 ( V_5 , V_13 ) ;
int V_14 = F_4 ( V_5 , V_15 ) ;
V_12 &= ~ V_16 ;
V_14 &= ~ V_17 ;
switch ( V_10 ) {
case 2 :
V_12 |= V_18 << V_19 ;
V_14 |= V_20 << V_21 ;
break;
case 4 :
V_12 |= V_22 << V_19 ;
V_14 |= V_23 << V_21 ;
break;
case 8 :
V_12 |= V_24 << V_19 ;
V_14 |= V_25 << V_21 ;
break;
case 16 :
V_12 |= V_26 << V_19 ;
V_14 |= V_27 << V_21 ;
break;
default:
return - V_28 ;
}
F_5 ( V_5 , V_13 , V_12 ) ;
F_5 ( V_5 , V_15 , V_14 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_29 ,
unsigned int V_30 )
{
struct V_4 * V_5 = V_29 -> V_5 ;
int V_31 , V_32 , V_12 ;
V_31 = F_4 ( V_5 , V_33 ) ;
V_32 = F_4 ( V_5 , V_15 ) ;
V_12 = F_4 ( V_5 , V_13 ) ;
switch ( V_30 & V_34 ) {
case V_35 :
V_31 &= ~ V_36 ;
V_31 |= V_37 ;
break;
case V_38 :
V_31 &= ~ V_36 ;
V_31 |= V_39 ;
break;
default:
return - V_28 ;
}
switch ( V_30 & V_40 ) {
case V_41 :
V_32 &= ~ V_42 ;
V_32 &= ~ V_43 ;
V_12 &= ~ V_44 ;
V_12 &= ~ V_45 ;
break;
case V_46 :
V_32 |= V_42 ;
V_32 &= ~ V_43 ;
V_12 |= V_44 ;
V_12 &= ~ V_45 ;
break;
case V_47 :
V_32 &= ~ V_42 ;
V_32 |= V_43 ;
V_12 &= ~ V_44 ;
V_12 |= V_45 ;
break;
case V_48 :
V_32 |= V_42 ;
V_32 |= V_43 ;
V_12 |= V_44 ;
V_12 |= V_45 ;
break;
default:
return - V_28 ;
}
switch ( V_30 & V_49 ) {
case V_50 :
V_32 |= V_51 ;
V_32 |= V_52 ;
V_12 |= V_53 ;
V_12 |= V_54 ;
break;
case V_55 :
V_32 |= V_51 ;
V_32 &= ~ V_52 ;
V_12 |= V_53 ;
V_12 &= ~ V_54 ;
break;
case V_56 :
V_32 &= ~ V_51 ;
V_32 |= V_52 ;
V_12 &= ~ V_53 ;
V_12 |= V_54 ;
break;
case V_57 :
V_32 &= ~ V_51 ;
V_32 &= ~ V_52 ;
V_12 &= ~ V_53 ;
V_12 &= ~ V_54 ;
break;
default:
return - V_28 ;
}
F_5 ( V_5 , V_33 , V_31 ) ;
F_5 ( V_5 , V_15 , V_32 ) ;
F_5 ( V_5 , V_13 , V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_29 ,
int V_58 , unsigned int V_59 , int V_60 )
{
struct V_4 * V_5 = V_29 -> V_5 ;
struct V_61 * V_62 = F_8 ( V_5 ) ;
switch ( V_59 ) {
case 12288000 :
case 18432000 :
case 24576000 :
case 36864000 :
V_62 -> V_63 = V_59 ;
return 0 ;
}
return - V_28 ;
}
static int F_9 ( struct V_64 * V_65 ,
struct V_66 * V_67 ,
struct V_1 * V_2 )
{
int V_68 = 0 , V_69 = 0 ;
struct V_70 * V_71 = V_65 -> V_72 ;
struct V_4 * V_5 = V_71 -> V_5 ;
struct V_61 * V_62 = F_8 ( V_5 ) ;
switch ( F_10 ( V_67 ) ) {
case V_73 :
V_68 = 3 ;
break;
case V_74 :
V_68 = 1 ;
break;
case V_75 :
case V_76 :
V_68 = 0 ;
break;
}
switch ( V_62 -> V_63 ) {
case 12288000 :
V_69 = V_77 ;
break;
case 18432000 :
V_69 = V_78 ;
break;
case 24576000 :
V_69 = V_79 ;
break;
case 36864000 :
V_69 = V_80 ;
break;
}
F_2 ( V_5 , V_81 ,
V_82 , V_69 ) ;
F_2 ( V_5 , V_6 ,
V_83 ,
V_68 << V_84 ) ;
F_2 ( V_5 , V_33 ,
V_85 , V_68 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_61 * V_62 = F_8 ( V_5 ) ;
struct V_86 * V_87 = & V_5 -> V_87 ;
int V_88 ;
V_5 -> V_89 = V_62 -> V_90 ;
V_88 = F_12 ( V_5 , 0 , 0 , V_91 ) ;
if ( V_88 < 0 ) {
F_13 ( V_5 -> V_92 , L_1 , V_88 ) ;
return V_88 ;
}
F_5 ( V_5 , V_93 , 0x0 ) ;
F_5 ( V_5 , V_6 , 0x1A ) ;
F_5 ( V_5 , V_94 , 0x41 ) ;
F_5 ( V_5 , V_95 , 0x3 ) ;
F_5 ( V_5 , V_33 , 0x43 ) ;
F_5 ( V_5 , V_81 , 0x99 ) ;
F_5 ( V_5 , V_96 , 0x04 ) ;
F_14 ( V_5 , V_97 ,
F_15 ( V_97 ) ) ;
F_16 ( V_87 , V_98 ,
F_15 ( V_98 ) ) ;
F_17 ( V_87 , V_99 , F_15 ( V_99 ) ) ;
return V_88 ;
}
static int T_1 F_18 ( struct V_100 * V_101 )
{
struct V_61 * V_62 ;
int V_88 ;
V_62 = F_19 ( sizeof( struct V_61 ) , V_102 ) ;
if ( V_62 == NULL )
return - V_103 ;
V_62 -> V_90 = F_20 ( V_101 , & V_104 ) ;
if ( F_21 ( V_62 -> V_90 ) ) {
V_88 = F_22 ( V_62 -> V_90 ) ;
goto V_105;
}
F_23 ( V_101 , V_62 ) ;
V_88 = F_24 ( & V_101 -> V_92 ,
& V_106 , & V_107 , 1 ) ;
if ( V_88 < 0 )
goto V_108;
return 0 ;
V_108:
F_25 ( V_62 -> V_90 ) ;
V_105:
F_26 ( V_62 ) ;
return V_88 ;
}
static int T_2 F_27 ( struct V_100 * V_101 )
{
struct V_61 * V_62 = F_28 ( V_101 ) ;
F_29 ( & V_101 -> V_92 ) ;
F_25 ( V_62 -> V_90 ) ;
F_26 ( V_62 ) ;
return 0 ;
}
static int T_1 F_30 ( struct V_109 * V_110 ,
const struct V_111 * V_112 )
{
struct V_61 * V_62 ;
int V_88 ;
V_62 = F_19 ( sizeof( struct V_61 ) , V_102 ) ;
if ( V_62 == NULL )
return - V_103 ;
V_62 -> V_90 = F_31 ( V_110 , & V_113 ) ;
if ( F_21 ( V_62 -> V_90 ) ) {
V_88 = F_22 ( V_62 -> V_90 ) ;
goto V_105;
}
F_32 ( V_110 , V_62 ) ;
V_88 = F_24 ( & V_110 -> V_92 ,
& V_106 , & V_107 , 1 ) ;
if ( V_88 < 0 )
goto V_108;
return 0 ;
V_108:
F_25 ( V_62 -> V_90 ) ;
V_105:
F_26 ( V_62 ) ;
return V_88 ;
}
static int T_2 F_33 ( struct V_109 * V_110 )
{
struct V_61 * V_62 = F_34 ( V_110 ) ;
F_29 ( & V_110 -> V_92 ) ;
F_25 ( V_62 -> V_90 ) ;
F_26 ( V_62 ) ;
return 0 ;
}
static int T_3 F_35 ( void )
{
int V_88 ;
#if F_36 ( V_114 ) || F_36 ( V_115 )
V_88 = F_37 ( & V_116 ) ;
if ( V_88 != 0 ) {
F_38 ( V_117 L_2 ,
V_88 ) ;
}
#endif
#if F_36 ( V_118 )
V_88 = F_39 ( & V_119 ) ;
if ( V_88 != 0 ) {
F_38 ( V_117 L_3 ,
V_88 ) ;
}
#endif
return V_88 ;
}
static void T_4 F_40 ( void )
{
#if F_36 ( V_118 )
F_41 ( & V_119 ) ;
#endif
#if F_36 ( V_114 ) || F_36 ( V_115 )
F_42 ( & V_116 ) ;
#endif
}
