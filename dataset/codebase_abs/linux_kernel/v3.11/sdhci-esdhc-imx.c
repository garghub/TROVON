static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_6 ;
}
static inline int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_7 ;
}
static inline int F_5 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_8 ;
}
static inline void F_6 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 , int V_13 )
{
void T_2 * V_14 = V_10 -> V_15 + ( V_13 & ~ 0x3 ) ;
T_1 V_16 = ( V_13 & 0x3 ) * 8 ;
F_7 ( ( ( F_8 ( V_14 ) & ~ ( V_11 << V_16 ) ) | ( V_12 << V_16 ) ) , V_14 ) ;
}
static T_1 F_9 ( struct V_9 * V_10 , int V_13 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
T_1 V_12 = F_8 ( V_10 -> V_15 + V_13 ) ;
if ( F_11 ( V_13 == V_21 ) ) {
if ( V_12 & V_22 ) {
V_12 &= ~ V_22 ;
V_12 |= V_23 ;
}
}
if ( F_11 ( V_13 == V_24 ) ) {
if ( V_12 & V_25 ) {
V_12 &= ~ V_25 ;
V_12 |= V_26 ;
}
if ( ( V_19 -> V_27 == V_28 ) &&
( ( V_12 & V_29 ) == V_29 ) ) {
V_12 &= ~ V_29 ;
F_7 ( V_29 , V_10 -> V_15 +
V_24 ) ;
V_19 -> V_27 = V_30 ;
}
}
return V_12 ;
}
static void F_12 ( struct V_9 * V_10 , T_1 V_12 , int V_13 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
T_1 V_2 ;
if ( F_11 ( V_13 == V_31 || V_13 == V_32 ) ) {
if ( V_12 & V_33 ) {
V_2 = F_8 ( V_10 -> V_15 + V_34 ) ;
V_2 &= ~ V_35 ;
F_7 ( V_2 , V_10 -> V_15 + V_34 ) ;
V_2 |= V_35 ;
F_7 ( V_2 , V_10 -> V_15 + V_34 ) ;
}
}
if ( F_11 ( ( V_19 -> V_36 & V_37 )
&& ( V_13 == V_24 )
&& ( V_12 & V_38 ) ) ) {
T_1 V_39 ;
V_39 = F_8 ( V_10 -> V_15 + V_40 ) ;
V_39 &= ~ V_41 ;
F_7 ( V_39 , V_10 -> V_15 + V_40 ) ;
if ( V_19 -> V_27 == V_42 )
{
V_2 = V_43 << 24 |
V_44 << 16 ;
F_7 ( V_2 , V_10 -> V_15 + V_45 ) ;
V_19 -> V_27 = V_28 ;
}
}
if ( F_11 ( V_13 == V_31 || V_13 == V_32 ) ) {
if ( V_12 & V_26 ) {
V_12 &= ~ V_26 ;
V_12 |= V_25 ;
}
}
F_7 ( V_12 , V_10 -> V_15 + V_13 ) ;
}
static T_3 F_13 ( struct V_9 * V_10 , int V_13 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
if ( F_11 ( V_13 == V_46 ) ) {
V_13 ^= 2 ;
if ( F_5 ( V_19 ) ) {
return V_47 ;
}
}
return F_14 ( V_10 -> V_15 + V_13 ) ;
}
static void F_15 ( struct V_9 * V_10 , T_3 V_12 , int V_13 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
switch ( V_13 ) {
case V_45 :
if ( ( V_19 -> V_36 & V_37 )
&& ( V_10 -> V_48 -> V_49 == V_50 )
&& ( V_10 -> V_48 -> V_2 -> V_51 > 1 )
&& ( V_10 -> V_48 -> V_2 -> V_36 & V_52 ) ) {
T_1 V_39 ;
V_39 = F_8 ( V_10 -> V_15 + V_40 ) ;
V_39 |= V_41 ;
F_7 ( V_39 , V_10 -> V_15 + V_40 ) ;
}
if ( F_5 ( V_19 ) ) {
T_1 V_53 = F_8 ( V_10 -> V_15 + V_54 ) ;
if ( V_12 & V_55 ) {
V_12 &= ~ V_55 ;
V_12 |= V_56 ;
}
V_53 = V_12 | ( V_53 & ~ V_57 ) ;
F_7 ( V_53 , V_10 -> V_15 + V_54 ) ;
} else {
V_19 -> V_58 = V_12 ;
}
return;
case V_59 :
if ( V_10 -> V_48 -> V_49 == V_43 )
V_12 |= V_44 ;
if ( ( V_10 -> V_48 -> V_49 == V_60 ) &&
( V_19 -> V_36 & V_37 ) )
V_19 -> V_27 = V_42 ;
if ( F_5 ( V_19 ) )
F_7 ( V_12 << 16 ,
V_10 -> V_15 + V_45 ) ;
else
F_7 ( V_12 << 16 | V_19 -> V_58 ,
V_10 -> V_15 + V_45 ) ;
return;
case V_61 :
V_12 &= ~ F_16 ( 0x7 , 0 ) ;
break;
}
F_6 ( V_10 , 0xffff , V_12 , V_13 ) ;
}
static void F_17 ( struct V_9 * V_10 , T_4 V_12 , int V_13 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
T_1 V_62 ;
T_1 V_11 ;
switch ( V_13 ) {
case V_63 :
return;
case V_34 :
V_62 = V_12 & V_64 ;
V_62 |= V_65 ;
if ( ! F_1 ( V_19 ) ) {
V_62 |= ( V_12 & V_66 ) << 5 ;
}
V_11 = 0xffff & ~ ( V_67 | V_35 ) ;
F_6 ( V_10 , V_11 , V_62 , V_13 ) ;
return;
}
F_6 ( V_10 , 0xff , V_12 , V_13 ) ;
if ( ( V_13 == V_68 ) && ( V_12 & 1 ) ) {
F_6 ( V_10 , 0x7 , 0x7 , V_69 ) ;
if ( F_5 ( V_19 ) )
F_7 ( 0 , V_10 -> V_15 + V_54 ) ;
}
}
static unsigned int F_18 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_70 * V_71 = & V_19 -> V_71 ;
T_1 V_72 = F_19 ( V_18 -> V_73 ) ;
if ( V_71 -> V_74 && ( V_71 -> V_74 < V_72 ) )
return V_71 -> V_74 ;
else
return V_72 ;
}
static unsigned int F_20 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
return F_19 ( V_18 -> V_73 ) / 256 / 16 ;
}
static inline void F_21 ( struct V_9 * V_10 ,
unsigned int clock )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
F_22 ( V_10 , clock , F_19 ( V_18 -> V_73 ) ) ;
}
static unsigned int F_23 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_70 * V_71 = & V_19 -> V_71 ;
switch ( V_71 -> V_75 ) {
case V_76 :
return F_24 ( V_10 -> V_77 ) ;
case V_78 :
return ! ( F_8 ( V_10 -> V_15 + V_79 ) &
V_80 ) ;
case V_81 :
break;
}
return - V_82 ;
}
static int F_25 ( struct V_9 * V_10 , int V_83 )
{
T_1 V_84 ;
switch ( V_83 ) {
case V_85 :
V_84 = V_86 ;
break;
case V_87 :
V_84 = V_88 ;
break;
default:
V_84 = 0 ;
break;
}
F_6 ( V_10 , V_67 , V_84 ,
V_34 ) ;
return 0 ;
}
static int
F_26 ( struct V_89 * V_90 ,
struct V_70 * V_71 )
{
struct V_91 * V_92 = V_90 -> V_93 . V_94 ;
if ( ! V_92 )
return - V_95 ;
if ( F_27 ( V_92 , L_1 , NULL ) )
V_71 -> V_96 = V_97 ;
if ( F_27 ( V_92 , L_2 , NULL ) )
V_71 -> V_96 = V_98 ;
if ( F_27 ( V_92 , L_3 , NULL ) )
V_71 -> V_75 = V_78 ;
V_71 -> V_99 = F_28 ( V_92 , L_4 , 0 ) ;
if ( F_29 ( V_71 -> V_99 ) )
V_71 -> V_96 = V_100 ;
V_71 -> V_101 = F_28 ( V_92 , L_5 , 0 ) ;
if ( F_29 ( V_71 -> V_101 ) )
V_71 -> V_75 = V_76 ;
F_30 ( V_92 , L_6 , & V_71 -> V_102 ) ;
F_30 ( V_92 , L_7 , & V_71 -> V_74 ) ;
return 0 ;
}
static inline int
F_26 ( struct V_89 * V_90 ,
struct V_70 * V_71 )
{
return - V_95 ;
}
static int F_31 ( struct V_89 * V_90 )
{
const struct V_103 * V_104 =
F_32 ( V_105 , & V_90 -> V_93 ) ;
struct V_17 * V_18 ;
struct V_9 * V_10 ;
struct V_70 * V_71 ;
int V_106 ;
struct V_1 * V_19 ;
V_10 = F_33 ( V_90 , & V_107 , 0 ) ;
if ( F_34 ( V_10 ) )
return F_35 ( V_10 ) ;
V_18 = F_10 ( V_10 ) ;
V_19 = F_36 ( & V_90 -> V_93 , sizeof( * V_19 ) , V_108 ) ;
if ( ! V_19 ) {
V_106 = - V_109 ;
goto V_110;
}
if ( V_104 )
V_90 -> V_111 = V_104 -> V_2 ;
V_19 -> V_3 = V_90 -> V_111 -> V_112 ;
V_18 -> V_20 = V_19 ;
V_19 -> V_113 = F_37 ( & V_90 -> V_93 , L_8 ) ;
if ( F_34 ( V_19 -> V_113 ) ) {
V_106 = F_35 ( V_19 -> V_113 ) ;
goto V_110;
}
V_19 -> V_114 = F_37 ( & V_90 -> V_93 , L_9 ) ;
if ( F_34 ( V_19 -> V_114 ) ) {
V_106 = F_35 ( V_19 -> V_114 ) ;
goto V_110;
}
V_19 -> V_115 = F_37 ( & V_90 -> V_93 , L_10 ) ;
if ( F_34 ( V_19 -> V_115 ) ) {
V_106 = F_35 ( V_19 -> V_115 ) ;
goto V_110;
}
V_18 -> V_73 = V_19 -> V_115 ;
F_38 ( V_19 -> V_115 ) ;
F_38 ( V_19 -> V_113 ) ;
F_38 ( V_19 -> V_114 ) ;
V_19 -> V_116 = F_39 ( & V_90 -> V_93 ) ;
if ( F_34 ( V_19 -> V_116 ) ) {
V_106 = F_35 ( V_19 -> V_116 ) ;
goto V_117;
}
V_10 -> V_118 |= V_119 ;
if ( F_1 ( V_19 ) || F_2 ( V_19 ) )
V_10 -> V_118 |= V_120
| V_121 ;
if ( F_4 ( V_19 ) )
V_19 -> V_36 |= V_37 ;
if ( F_5 ( V_19 ) )
F_7 ( 0x08100810 , V_10 -> V_15 + V_122 ) ;
V_71 = & V_19 -> V_71 ;
if ( F_26 ( V_90 , V_71 ) < 0 ) {
if ( ! V_10 -> V_77 -> V_123 -> V_124 ) {
F_40 ( F_41 ( V_10 -> V_77 ) , L_11 ) ;
V_106 = - V_125 ;
goto V_117;
}
V_19 -> V_71 = * ( (struct V_70 * )
V_10 -> V_77 -> V_123 -> V_124 ) ;
}
if ( V_71 -> V_75 == V_76 ) {
V_106 = F_42 ( V_10 -> V_77 , V_71 -> V_101 ) ;
if ( V_106 ) {
F_40 ( F_41 ( V_10 -> V_77 ) ,
L_12 ) ;
goto V_117;
}
V_10 -> V_77 -> V_126 |= V_127 ;
}
switch ( V_71 -> V_96 ) {
case V_100 :
V_106 = F_43 ( V_10 -> V_77 , V_71 -> V_99 ) ;
if ( V_106 ) {
F_40 ( F_41 ( V_10 -> V_77 ) ,
L_13 ) ;
goto V_117;
}
case V_98 :
V_10 -> V_118 &= ~ V_128 ;
break;
case V_97 :
V_10 -> V_77 -> V_129 = V_130 ;
break;
case V_131 :
break;
}
switch ( V_71 -> V_102 ) {
case 8 :
V_10 -> V_77 -> V_129 |= V_132 | V_133 ;
break;
case 4 :
V_10 -> V_77 -> V_129 |= V_133 ;
break;
case 1 :
default:
V_10 -> V_118 |= V_134 ;
break;
}
V_106 = F_44 ( V_10 ) ;
if ( V_106 )
goto V_117;
return 0 ;
V_117:
F_45 ( V_19 -> V_115 ) ;
F_45 ( V_19 -> V_113 ) ;
F_45 ( V_19 -> V_114 ) ;
V_110:
F_46 ( V_90 ) ;
return V_106 ;
}
static int F_47 ( struct V_89 * V_90 )
{
struct V_9 * V_10 = F_48 ( V_90 ) ;
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
int V_135 = ( F_8 ( V_10 -> V_15 + V_24 ) == 0xffffffff ) ;
F_49 ( V_10 , V_135 ) ;
F_45 ( V_19 -> V_115 ) ;
F_45 ( V_19 -> V_113 ) ;
F_45 ( V_19 -> V_114 ) ;
F_46 ( V_90 ) ;
return 0 ;
}
