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
T_1 V_12 = F_8 ( V_10 -> V_15 + V_13 ) ;
if ( F_10 ( V_13 == V_17 ) ) {
if ( V_12 & V_18 ) {
V_12 &= ~ V_18 ;
V_12 |= V_19 ;
}
}
if ( F_10 ( V_13 == V_20 ) ) {
if ( V_12 & V_21 ) {
V_12 &= ~ V_21 ;
V_12 |= V_22 ;
}
}
return V_12 ;
}
static void F_11 ( struct V_9 * V_10 , T_1 V_12 , int V_13 )
{
struct V_23 * V_24 = F_12 ( V_10 ) ;
struct V_1 * V_25 = V_24 -> V_26 ;
T_1 V_2 ;
if ( F_10 ( V_13 == V_27 || V_13 == V_28 ) ) {
if ( V_12 & V_29 ) {
V_2 = F_8 ( V_10 -> V_15 + V_30 ) ;
V_2 &= ~ V_31 ;
F_7 ( V_2 , V_10 -> V_15 + V_30 ) ;
V_2 |= V_31 ;
F_7 ( V_2 , V_10 -> V_15 + V_30 ) ;
}
}
if ( F_10 ( ( V_25 -> V_32 & V_33 )
&& ( V_13 == V_20 )
&& ( V_12 & V_34 ) ) ) {
T_1 V_35 ;
V_35 = F_8 ( V_10 -> V_15 + V_36 ) ;
V_35 &= ~ V_37 ;
F_7 ( V_35 , V_10 -> V_15 + V_36 ) ;
}
if ( F_10 ( V_13 == V_27 || V_13 == V_28 ) ) {
if ( V_12 & V_22 ) {
V_12 &= ~ V_22 ;
V_12 |= V_21 ;
}
}
F_7 ( V_12 , V_10 -> V_15 + V_13 ) ;
}
static T_3 F_13 ( struct V_9 * V_10 , int V_13 )
{
struct V_23 * V_24 = F_12 ( V_10 ) ;
struct V_1 * V_25 = V_24 -> V_26 ;
if ( F_10 ( V_13 == V_38 ) ) {
V_13 ^= 2 ;
if ( F_5 ( V_25 ) ) {
return V_39 ;
}
}
return F_14 ( V_10 -> V_15 + V_13 ) ;
}
static void F_15 ( struct V_9 * V_10 , T_3 V_12 , int V_13 )
{
struct V_23 * V_24 = F_12 ( V_10 ) ;
struct V_1 * V_25 = V_24 -> V_26 ;
switch ( V_13 ) {
case V_40 :
if ( ( V_25 -> V_32 & V_33 )
&& ( V_10 -> V_41 -> V_42 == V_43 )
&& ( V_10 -> V_41 -> V_2 -> V_44 > 1 )
&& ( V_10 -> V_41 -> V_2 -> V_32 & V_45 ) ) {
T_1 V_35 ;
V_35 = F_8 ( V_10 -> V_15 + V_36 ) ;
V_35 |= V_37 ;
F_7 ( V_35 , V_10 -> V_15 + V_36 ) ;
}
if ( F_5 ( V_25 ) ) {
T_1 V_46 = F_8 ( V_10 -> V_15 + V_47 ) ;
if ( V_12 & V_48 ) {
V_12 &= ~ V_48 ;
V_12 |= V_49 ;
}
V_46 = V_12 | ( V_46 & ~ V_50 ) ;
F_7 ( V_46 , V_10 -> V_15 + V_47 ) ;
} else {
V_25 -> V_51 = V_12 ;
}
return;
case V_52 :
if ( ( V_10 -> V_41 -> V_42 == V_53 ||
V_10 -> V_41 -> V_42 == V_54 ) &&
( V_25 -> V_32 & V_33 ) )
V_12 |= V_55 ;
if ( F_5 ( V_25 ) )
F_7 ( V_12 << 16 ,
V_10 -> V_15 + V_40 ) ;
else
F_7 ( V_12 << 16 | V_25 -> V_51 ,
V_10 -> V_15 + V_40 ) ;
return;
case V_56 :
V_12 &= ~ F_16 ( 0x7 , 0 ) ;
break;
}
F_6 ( V_10 , 0xffff , V_12 , V_13 ) ;
}
static void F_17 ( struct V_9 * V_10 , T_4 V_12 , int V_13 )
{
struct V_23 * V_24 = F_12 ( V_10 ) ;
struct V_1 * V_25 = V_24 -> V_26 ;
T_1 V_57 ;
T_1 V_11 ;
switch ( V_13 ) {
case V_58 :
return;
case V_30 :
V_57 = V_12 & V_59 ;
V_57 |= V_60 ;
if ( ! F_1 ( V_25 ) ) {
V_57 |= ( V_12 & V_61 ) << 5 ;
}
V_11 = 0xffff & ~ V_62 ;
F_6 ( V_10 , V_11 , V_57 , V_13 ) ;
return;
}
F_6 ( V_10 , 0xff , V_12 , V_13 ) ;
if ( ( V_13 == V_63 ) && ( V_12 & 1 ) ) {
F_6 ( V_10 , 0x7 , 0x7 , V_64 ) ;
if ( F_5 ( V_25 ) )
F_7 ( 0 , V_10 -> V_15 + V_47 ) ;
}
}
static unsigned int F_18 ( struct V_9 * V_10 )
{
struct V_23 * V_24 = F_12 ( V_10 ) ;
return F_19 ( V_24 -> V_65 ) / 256 / 16 ;
}
static unsigned int F_20 ( struct V_9 * V_10 )
{
struct V_23 * V_24 = F_12 ( V_10 ) ;
struct V_1 * V_25 = V_24 -> V_26 ;
struct V_66 * V_67 = & V_25 -> V_67 ;
switch ( V_67 -> V_68 ) {
case V_69 :
return F_21 ( V_10 -> V_70 ) ;
case V_71 :
return ! ( F_8 ( V_10 -> V_15 + V_72 ) &
V_73 ) ;
case V_74 :
break;
}
return - V_75 ;
}
static int F_22 ( struct V_9 * V_10 , int V_76 )
{
T_1 V_77 ;
switch ( V_76 ) {
case V_78 :
V_77 = V_79 ;
break;
case V_80 :
V_77 = V_81 ;
break;
default:
V_77 = 0 ;
break;
}
F_6 ( V_10 , V_62 , V_77 ,
V_30 ) ;
return 0 ;
}
static int
F_23 ( struct V_82 * V_83 ,
struct V_66 * V_67 )
{
struct V_84 * V_85 = V_83 -> V_86 . V_87 ;
if ( ! V_85 )
return - V_88 ;
if ( F_24 ( V_85 , L_1 , NULL ) )
V_67 -> V_89 = V_90 ;
if ( F_24 ( V_85 , L_2 , NULL ) )
V_67 -> V_89 = V_91 ;
if ( F_24 ( V_85 , L_3 , NULL ) )
V_67 -> V_68 = V_71 ;
V_67 -> V_92 = F_25 ( V_85 , L_4 , 0 ) ;
if ( F_26 ( V_67 -> V_92 ) )
V_67 -> V_89 = V_93 ;
V_67 -> V_94 = F_25 ( V_85 , L_5 , 0 ) ;
if ( F_26 ( V_67 -> V_94 ) )
V_67 -> V_68 = V_69 ;
F_27 ( V_85 , L_6 , & V_67 -> V_95 ) ;
return 0 ;
}
static inline int
F_23 ( struct V_82 * V_83 ,
struct V_66 * V_67 )
{
return - V_88 ;
}
static int F_28 ( struct V_82 * V_83 )
{
const struct V_96 * V_97 =
F_29 ( V_98 , & V_83 -> V_86 ) ;
struct V_23 * V_24 ;
struct V_9 * V_10 ;
struct V_66 * V_67 ;
int V_99 ;
struct V_1 * V_25 ;
V_10 = F_30 ( V_83 , & V_100 ) ;
if ( F_31 ( V_10 ) )
return F_32 ( V_10 ) ;
V_24 = F_12 ( V_10 ) ;
V_25 = F_33 ( & V_83 -> V_86 , sizeof( * V_25 ) , V_101 ) ;
if ( ! V_25 ) {
V_99 = - V_102 ;
goto V_103;
}
if ( V_97 )
V_83 -> V_104 = V_97 -> V_2 ;
V_25 -> V_3 = V_83 -> V_104 -> V_105 ;
V_24 -> V_26 = V_25 ;
V_25 -> V_106 = F_34 ( & V_83 -> V_86 , L_7 ) ;
if ( F_31 ( V_25 -> V_106 ) ) {
V_99 = F_32 ( V_25 -> V_106 ) ;
goto V_103;
}
V_25 -> V_107 = F_34 ( & V_83 -> V_86 , L_8 ) ;
if ( F_31 ( V_25 -> V_107 ) ) {
V_99 = F_32 ( V_25 -> V_107 ) ;
goto V_103;
}
V_25 -> V_108 = F_34 ( & V_83 -> V_86 , L_9 ) ;
if ( F_31 ( V_25 -> V_108 ) ) {
V_99 = F_32 ( V_25 -> V_108 ) ;
goto V_103;
}
V_24 -> V_65 = V_25 -> V_108 ;
F_35 ( V_25 -> V_108 ) ;
F_35 ( V_25 -> V_106 ) ;
F_35 ( V_25 -> V_107 ) ;
V_25 -> V_109 = F_36 ( & V_83 -> V_86 ) ;
if ( F_31 ( V_25 -> V_109 ) ) {
V_99 = F_32 ( V_25 -> V_109 ) ;
goto V_110;
}
V_10 -> V_111 |= V_112 ;
if ( F_1 ( V_25 ) || F_2 ( V_25 ) )
V_10 -> V_111 |= V_113
| V_114 ;
if ( F_4 ( V_25 ) )
V_25 -> V_32 |= V_33 ;
if ( F_5 ( V_25 ) )
F_7 ( 0x08100810 , V_10 -> V_15 + V_115 ) ;
V_67 = & V_25 -> V_67 ;
if ( F_23 ( V_83 , V_67 ) < 0 ) {
if ( ! V_10 -> V_70 -> V_116 -> V_117 ) {
F_37 ( F_38 ( V_10 -> V_70 ) , L_10 ) ;
V_99 = - V_118 ;
goto V_110;
}
V_25 -> V_67 = * ( (struct V_66 * )
V_10 -> V_70 -> V_116 -> V_117 ) ;
}
if ( V_67 -> V_68 == V_69 ) {
V_99 = F_39 ( V_10 -> V_70 , V_67 -> V_94 ) ;
if ( V_99 ) {
F_37 ( F_38 ( V_10 -> V_70 ) ,
L_11 ) ;
goto V_110;
}
V_10 -> V_70 -> V_119 |= V_120 ;
}
switch ( V_67 -> V_89 ) {
case V_93 :
V_99 = F_40 ( V_10 -> V_70 , V_67 -> V_92 ) ;
if ( V_99 ) {
F_37 ( F_38 ( V_10 -> V_70 ) ,
L_12 ) ;
goto V_110;
}
case V_91 :
V_10 -> V_111 &= ~ V_121 ;
break;
case V_90 :
V_10 -> V_70 -> V_122 = V_123 ;
break;
case V_124 :
break;
}
switch ( V_67 -> V_95 ) {
case 8 :
V_10 -> V_70 -> V_122 |= V_125 | V_126 ;
break;
case 4 :
V_10 -> V_70 -> V_122 |= V_126 ;
break;
case 1 :
default:
V_10 -> V_111 |= V_127 ;
break;
}
V_99 = F_41 ( V_10 ) ;
if ( V_99 )
goto V_110;
return 0 ;
V_110:
F_42 ( V_25 -> V_108 ) ;
F_42 ( V_25 -> V_106 ) ;
F_42 ( V_25 -> V_107 ) ;
V_103:
F_43 ( V_83 ) ;
return V_99 ;
}
static int F_44 ( struct V_82 * V_83 )
{
struct V_9 * V_10 = F_45 ( V_83 ) ;
struct V_23 * V_24 = F_12 ( V_10 ) ;
struct V_1 * V_25 = V_24 -> V_26 ;
int V_128 = ( F_8 ( V_10 -> V_15 + V_20 ) == 0xffffffff ) ;
F_46 ( V_10 , V_128 ) ;
F_42 ( V_25 -> V_108 ) ;
F_42 ( V_25 -> V_106 ) ;
F_42 ( V_25 -> V_107 ) ;
F_43 ( V_83 ) ;
return 0 ;
}
