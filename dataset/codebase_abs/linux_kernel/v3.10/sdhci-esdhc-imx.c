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
return F_19 ( V_18 -> V_70 ) / 256 / 16 ;
}
static unsigned int F_20 ( struct V_9 * V_10 )
{
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
struct V_71 * V_72 = & V_19 -> V_72 ;
switch ( V_72 -> V_73 ) {
case V_74 :
return F_21 ( V_10 -> V_75 ) ;
case V_76 :
return ! ( F_8 ( V_10 -> V_15 + V_77 ) &
V_78 ) ;
case V_79 :
break;
}
return - V_80 ;
}
static int F_22 ( struct V_9 * V_10 , int V_81 )
{
T_1 V_82 ;
switch ( V_81 ) {
case V_83 :
V_82 = V_84 ;
break;
case V_85 :
V_82 = V_86 ;
break;
default:
V_82 = 0 ;
break;
}
F_6 ( V_10 , V_67 , V_82 ,
V_34 ) ;
return 0 ;
}
static int
F_23 ( struct V_87 * V_88 ,
struct V_71 * V_72 )
{
struct V_89 * V_90 = V_88 -> V_91 . V_92 ;
if ( ! V_90 )
return - V_93 ;
if ( F_24 ( V_90 , L_1 , NULL ) )
V_72 -> V_94 = V_95 ;
if ( F_24 ( V_90 , L_2 , NULL ) )
V_72 -> V_94 = V_96 ;
if ( F_24 ( V_90 , L_3 , NULL ) )
V_72 -> V_73 = V_76 ;
V_72 -> V_97 = F_25 ( V_90 , L_4 , 0 ) ;
if ( F_26 ( V_72 -> V_97 ) )
V_72 -> V_94 = V_98 ;
V_72 -> V_99 = F_25 ( V_90 , L_5 , 0 ) ;
if ( F_26 ( V_72 -> V_99 ) )
V_72 -> V_73 = V_74 ;
F_27 ( V_90 , L_6 , & V_72 -> V_100 ) ;
return 0 ;
}
static inline int
F_23 ( struct V_87 * V_88 ,
struct V_71 * V_72 )
{
return - V_93 ;
}
static int F_28 ( struct V_87 * V_88 )
{
const struct V_101 * V_102 =
F_29 ( V_103 , & V_88 -> V_91 ) ;
struct V_17 * V_18 ;
struct V_9 * V_10 ;
struct V_71 * V_72 ;
int V_104 ;
struct V_1 * V_19 ;
V_10 = F_30 ( V_88 , & V_105 ) ;
if ( F_31 ( V_10 ) )
return F_32 ( V_10 ) ;
V_18 = F_10 ( V_10 ) ;
V_19 = F_33 ( & V_88 -> V_91 , sizeof( * V_19 ) , V_106 ) ;
if ( ! V_19 ) {
V_104 = - V_107 ;
goto V_108;
}
if ( V_102 )
V_88 -> V_109 = V_102 -> V_2 ;
V_19 -> V_3 = V_88 -> V_109 -> V_110 ;
V_18 -> V_20 = V_19 ;
V_19 -> V_111 = F_34 ( & V_88 -> V_91 , L_7 ) ;
if ( F_31 ( V_19 -> V_111 ) ) {
V_104 = F_32 ( V_19 -> V_111 ) ;
goto V_108;
}
V_19 -> V_112 = F_34 ( & V_88 -> V_91 , L_8 ) ;
if ( F_31 ( V_19 -> V_112 ) ) {
V_104 = F_32 ( V_19 -> V_112 ) ;
goto V_108;
}
V_19 -> V_113 = F_34 ( & V_88 -> V_91 , L_9 ) ;
if ( F_31 ( V_19 -> V_113 ) ) {
V_104 = F_32 ( V_19 -> V_113 ) ;
goto V_108;
}
V_18 -> V_70 = V_19 -> V_113 ;
F_35 ( V_19 -> V_113 ) ;
F_35 ( V_19 -> V_111 ) ;
F_35 ( V_19 -> V_112 ) ;
V_19 -> V_114 = F_36 ( & V_88 -> V_91 ) ;
if ( F_31 ( V_19 -> V_114 ) ) {
V_104 = F_32 ( V_19 -> V_114 ) ;
goto V_115;
}
V_10 -> V_116 |= V_117 ;
if ( F_1 ( V_19 ) || F_2 ( V_19 ) )
V_10 -> V_116 |= V_118
| V_119 ;
if ( F_4 ( V_19 ) )
V_19 -> V_36 |= V_37 ;
if ( F_5 ( V_19 ) )
F_7 ( 0x08100810 , V_10 -> V_15 + V_120 ) ;
V_72 = & V_19 -> V_72 ;
if ( F_23 ( V_88 , V_72 ) < 0 ) {
if ( ! V_10 -> V_75 -> V_121 -> V_122 ) {
F_37 ( F_38 ( V_10 -> V_75 ) , L_10 ) ;
V_104 = - V_123 ;
goto V_115;
}
V_19 -> V_72 = * ( (struct V_71 * )
V_10 -> V_75 -> V_121 -> V_122 ) ;
}
if ( V_72 -> V_73 == V_74 ) {
V_104 = F_39 ( V_10 -> V_75 , V_72 -> V_99 ) ;
if ( V_104 ) {
F_37 ( F_38 ( V_10 -> V_75 ) ,
L_11 ) ;
goto V_115;
}
V_10 -> V_75 -> V_124 |= V_125 ;
}
switch ( V_72 -> V_94 ) {
case V_98 :
V_104 = F_40 ( V_10 -> V_75 , V_72 -> V_97 ) ;
if ( V_104 ) {
F_37 ( F_38 ( V_10 -> V_75 ) ,
L_12 ) ;
goto V_115;
}
case V_96 :
V_10 -> V_116 &= ~ V_126 ;
break;
case V_95 :
V_10 -> V_75 -> V_127 = V_128 ;
break;
case V_129 :
break;
}
switch ( V_72 -> V_100 ) {
case 8 :
V_10 -> V_75 -> V_127 |= V_130 | V_131 ;
break;
case 4 :
V_10 -> V_75 -> V_127 |= V_131 ;
break;
case 1 :
default:
V_10 -> V_116 |= V_132 ;
break;
}
V_104 = F_41 ( V_10 ) ;
if ( V_104 )
goto V_115;
return 0 ;
V_115:
F_42 ( V_19 -> V_113 ) ;
F_42 ( V_19 -> V_111 ) ;
F_42 ( V_19 -> V_112 ) ;
V_108:
F_43 ( V_88 ) ;
return V_104 ;
}
static int F_44 ( struct V_87 * V_88 )
{
struct V_9 * V_10 = F_45 ( V_88 ) ;
struct V_17 * V_18 = F_10 ( V_10 ) ;
struct V_1 * V_19 = V_18 -> V_20 ;
int V_133 = ( F_8 ( V_10 -> V_15 + V_24 ) == 0xffffffff ) ;
F_46 ( V_10 , V_133 ) ;
F_42 ( V_19 -> V_113 ) ;
F_42 ( V_19 -> V_111 ) ;
F_42 ( V_19 -> V_112 ) ;
F_43 ( V_88 ) ;
return 0 ;
}
