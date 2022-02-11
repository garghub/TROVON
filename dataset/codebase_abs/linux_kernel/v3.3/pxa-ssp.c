static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 -> V_4 , L_1 ,
F_3 ( V_2 , V_5 ) , F_3 ( V_2 , V_6 ) ,
F_3 ( V_2 , V_7 ) ) ;
F_2 ( & V_2 -> V_3 -> V_4 , L_2 ,
F_3 ( V_2 , V_8 ) , F_3 ( V_2 , V_9 ) ,
F_3 ( V_2 , V_10 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_11 ;
V_11 = F_5 ( V_2 -> V_12 + V_5 ) | V_13 ;
F_6 ( V_11 , V_2 -> V_12 + V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_11 ;
V_11 = F_5 ( V_2 -> V_12 + V_5 ) & ~ V_13 ;
F_6 ( V_11 , V_2 -> V_12 + V_5 ) ;
}
static struct V_14 *
F_8 ( struct V_1 * V_2 , int V_15 , int V_16 )
{
struct V_17 * V_18 ;
V_18 = F_9 ( sizeof( struct V_17 ) , V_19 ) ;
if ( V_18 == NULL )
return NULL ;
snprintf ( V_18 -> V_20 , 20 , L_3 , V_2 -> V_21 ,
V_15 ? L_4 : L_5 , V_16 ? L_6 : L_7 ) ;
V_18 -> V_22 . V_20 = V_18 -> V_20 ;
V_18 -> V_22 . V_23 = & F_10 ( V_16 ? V_2 -> V_24 : V_2 -> V_25 ) ;
V_18 -> V_22 . V_26 = ( V_16 ? ( V_27 | V_28 ) :
( V_29 | V_30 ) ) |
( V_15 ? V_31 : V_32 ) | V_33 ;
V_18 -> V_22 . V_34 = V_2 -> V_35 + V_36 ;
return & V_18 -> V_22 ;
}
static int F_11 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_43 = 0 ;
if ( ! V_40 -> V_44 ) {
F_13 ( V_2 -> V_45 ) ;
F_7 ( V_2 ) ;
}
F_14 ( F_15 ( V_40 , V_38 ) ) ;
F_16 ( V_40 , V_38 , NULL ) ;
return V_43 ;
}
static void F_17 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
if ( ! V_40 -> V_44 ) {
F_7 ( V_2 ) ;
F_18 ( V_2 -> V_45 ) ;
}
F_14 ( F_15 ( V_40 , V_38 ) ) ;
F_16 ( V_40 , V_38 , NULL ) ;
}
static int F_19 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
if ( ! V_40 -> V_44 )
F_13 ( V_2 -> V_45 ) ;
V_42 -> V_46 = F_5 ( V_2 -> V_12 + V_5 ) ;
V_42 -> V_47 = F_5 ( V_2 -> V_12 + V_6 ) ;
V_42 -> V_48 = F_5 ( V_2 -> V_12 + V_7 ) ;
V_42 -> V_49 = F_5 ( V_2 -> V_12 + V_8 ) ;
F_7 ( V_2 ) ;
F_18 ( V_2 -> V_45 ) ;
return 0 ;
}
static int F_20 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_1 V_50 = V_51 | V_52 | V_53 ;
F_13 ( V_2 -> V_45 ) ;
F_6 ( V_50 , V_2 -> V_12 + V_9 ) ;
F_6 ( V_42 -> V_46 & ~ V_13 , V_2 -> V_12 + V_5 ) ;
F_6 ( V_42 -> V_47 , V_2 -> V_12 + V_6 ) ;
F_6 ( V_42 -> V_48 , V_2 -> V_12 + V_7 ) ;
F_6 ( V_42 -> V_49 , V_2 -> V_12 + V_8 ) ;
if ( V_40 -> V_44 )
F_4 ( V_2 ) ;
else
F_18 ( V_2 -> V_45 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , T_2 div )
{
T_2 V_11 = F_3 ( V_2 , V_5 ) ;
if ( F_22 () && V_2 -> type == V_54 ) {
V_11 &= ~ 0x0000ff00 ;
V_11 |= ( ( div - 2 ) / 2 ) << 8 ;
} else {
V_11 &= ~ 0x000fff00 ;
V_11 |= ( div - 1 ) << 8 ;
}
F_23 ( V_2 , V_5 , V_11 ) ;
}
static T_2 F_24 ( struct V_1 * V_2 )
{
T_2 V_11 = F_3 ( V_2 , V_5 ) ;
T_2 div ;
if ( F_22 () && V_2 -> type == V_54 )
div = ( ( V_11 >> 8 ) & 0xff ) * 2 + 2 ;
else
div = ( ( V_11 >> 8 ) & 0xfff ) + 1 ;
return div ;
}
static int F_25 ( struct V_39 * V_40 ,
int V_55 , unsigned int V_56 , int V_57 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_58 ;
T_2 V_11 = F_3 ( V_2 , V_5 ) &
~ ( V_59 | V_60 | V_61 | V_62 ) ;
F_2 ( & V_2 -> V_3 -> V_4 ,
L_8 ,
V_40 -> V_63 , V_55 , V_56 ) ;
switch ( V_55 ) {
case V_64 :
V_11 |= V_61 ;
break;
case V_65 :
if ( F_22 () )
V_42 -> V_66 = 1843200 ;
else
V_42 -> V_66 = 13000000 ;
break;
case V_67 :
V_42 -> V_66 = V_56 ;
V_11 |= V_59 ;
break;
case V_68 :
V_42 -> V_66 = V_56 ;
V_11 |= V_60 | V_61 ;
break;
case V_69 :
V_42 -> V_66 = 0 ;
F_21 ( V_2 , 1 ) ;
V_11 |= V_62 ;
break;
default:
return - V_70 ;
}
if ( ! F_26 () )
F_18 ( V_2 -> V_45 ) ;
V_58 = F_3 ( V_2 , V_5 ) | V_11 ;
F_23 ( V_2 , V_5 , V_58 ) ;
if ( ! F_26 () )
F_13 ( V_2 -> V_45 ) ;
return 0 ;
}
static int F_27 ( struct V_39 * V_40 ,
int V_71 , int div )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_58 ;
switch ( V_71 ) {
case V_72 :
V_58 = ( F_3 ( V_2 , V_10 ) & ~ 0x7 ) | F_28 ( div ) ;
F_23 ( V_2 , V_10 , V_58 ) ;
break;
case V_73 :
V_58 = F_3 ( V_2 , V_10 ) ;
V_58 &= ~ V_74 ;
#if F_29 ( V_75 )
if ( F_26 () )
V_58 &= ~ V_76 ;
#endif
switch ( div ) {
case V_77 :
V_58 |= V_74 ;
break;
case V_78 :
break;
#if F_29 ( V_75 )
case V_79 :
if ( F_26 () )
V_58 |= V_76 ;
else
return - V_80 ;
break;
#endif
default:
return - V_80 ;
}
F_23 ( V_2 , V_10 , V_58 ) ;
break;
case V_81 :
F_21 ( V_2 , div ) ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static int F_30 ( struct V_39 * V_40 , int V_82 ,
int V_83 , unsigned int V_84 , unsigned int V_85 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_2 V_86 = F_3 ( V_2 , V_10 ) & ~ 0x70 ;
#if F_29 ( V_75 )
if ( F_26 () )
F_23 ( V_2 , V_87 , 0 ) ;
#endif
switch ( V_85 ) {
case 5622000 :
break;
case 11345000 :
V_86 |= ( 0x1 << 4 ) ;
break;
case 12235000 :
V_86 |= ( 0x2 << 4 ) ;
break;
case 14857000 :
V_86 |= ( 0x3 << 4 ) ;
break;
case 32842000 :
V_86 |= ( 0x4 << 4 ) ;
break;
case 48000000 :
V_86 |= ( 0x5 << 4 ) ;
break;
case 0 :
break;
default:
#ifdef V_75
if ( F_26 () ) {
T_2 V_58 ;
T_3 V_88 = 19968 ;
V_88 *= 1000000 ;
F_31 ( V_88 , V_85 ) ;
V_58 = V_88 ;
V_58 = ( V_58 << 16 ) | 64 ;
F_23 ( V_2 , V_87 , V_58 ) ;
V_86 |= ( 0x6 << 4 ) ;
F_2 ( & V_2 -> V_3 -> V_4 ,
L_9 ,
V_58 , V_85 ) ;
break;
}
#endif
return - V_80 ;
}
F_23 ( V_2 , V_10 , V_86 ) ;
return 0 ;
}
static int F_32 ( struct V_39 * V_40 ,
unsigned int V_89 , unsigned int V_90 , int V_91 , int V_92 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_2 V_11 ;
V_11 = F_3 ( V_2 , V_5 ) ;
V_11 &= ~ ( V_61 | F_33 ( 8 ) | V_93 | V_94 ) ;
if ( V_92 > 16 )
V_11 |= V_93 | F_34 ( V_92 - 16 ) ;
else
V_11 |= F_34 ( V_92 ) ;
if ( V_91 > 1 ) {
V_11 |= V_61 ;
V_11 |= F_33 ( V_91 ) ;
F_23 ( V_2 , V_95 , V_89 ) ;
F_23 ( V_2 , V_96 , V_90 ) ;
}
F_23 ( V_2 , V_5 , V_11 ) ;
return 0 ;
}
static int F_35 ( struct V_39 * V_40 ,
int V_97 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_2 V_98 ;
V_98 = F_3 ( V_2 , V_6 ) ;
if ( V_97 )
V_98 &= ~ V_99 ;
else
V_98 |= V_99 ;
F_23 ( V_2 , V_6 , V_98 ) ;
return 0 ;
}
static int F_36 ( struct V_39 * V_40 ,
unsigned int V_100 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_2 V_11 , V_98 , V_101 , V_102 ;
if ( V_42 -> V_103 == V_100 )
return 0 ;
if ( F_3 ( V_2 , V_5 ) & V_13 ) {
F_37 ( & V_2 -> V_3 -> V_4 ,
L_10 ) ;
return - V_80 ;
}
V_11 = F_3 ( V_2 , V_5 ) &
~ ( V_59 | V_60 | V_61 | V_62 ) ;
V_98 = F_38 ( 8 ) | F_39 ( 7 ) ;
V_101 = 0 ;
switch ( V_100 & V_104 ) {
case V_105 :
V_98 |= V_106 | V_107 | V_108 ;
break;
case V_109 :
V_98 |= V_106 | V_108 ;
break;
case V_110 :
break;
default:
return - V_80 ;
}
switch ( V_100 & V_111 ) {
case V_112 :
V_101 |= V_113 ;
break;
case V_114 :
break;
case V_115 :
V_101 |= F_40 ( 2 ) ;
break;
case V_116 :
V_101 |= F_40 ( 2 ) | V_113 ;
break;
default:
return - V_80 ;
}
switch ( V_100 & V_117 ) {
case V_118 :
V_11 |= V_119 ;
V_98 |= V_120 | V_121 ;
break;
case V_122 :
V_101 |= V_123 ;
case V_124 :
V_11 |= V_61 | V_119 ;
V_98 |= V_121 | V_120 ;
break;
default:
return - V_80 ;
}
F_23 ( V_2 , V_5 , V_11 ) ;
F_23 ( V_2 , V_6 , V_98 ) ;
F_23 ( V_2 , V_8 , V_101 ) ;
switch ( V_100 & V_104 ) {
case V_105 :
case V_109 :
V_102 = F_3 ( V_2 , V_6 ) | V_108 ;
F_23 ( V_2 , V_6 , V_102 ) ;
while ( F_3 ( V_2 , V_9 ) & V_125 )
F_41 () ;
break;
}
F_1 ( V_2 ) ;
V_42 -> V_103 = V_100 ;
return 0 ;
}
static int F_42 ( struct V_37 * V_38 ,
struct V_126 * V_22 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_127 = F_43 ( V_22 ) ;
T_2 V_11 ;
T_2 V_101 ;
int V_128 = F_44 ( F_45 ( V_22 ) ) ;
int V_129 = F_3 ( V_2 , V_95 ) & 0xf ;
struct V_14 * V_130 ;
V_130 = F_15 ( V_40 , V_38 ) ;
F_14 ( V_130 ) ;
V_130 = F_8 ( V_2 ,
( ( V_127 == 2 ) && ( V_129 != 1 ) ) || ( V_128 == 32 ) ,
V_38 -> V_131 == V_132 ) ;
F_16 ( V_40 , V_38 , V_130 ) ;
if ( F_3 ( V_2 , V_5 ) & V_13 )
return 0 ;
V_11 = F_3 ( V_2 , V_5 ) & ~ ( V_94 | V_93 ) ;
switch ( F_45 ( V_22 ) ) {
case V_133 :
#ifdef V_75
if ( F_26 () )
V_11 |= V_134 ;
#endif
V_11 |= F_34 ( 16 ) ;
break;
case V_135 :
V_11 |= ( V_93 | F_34 ( 8 ) ) ;
break;
case V_136 :
V_11 |= ( V_93 | F_34 ( 16 ) ) ;
break;
}
F_23 ( V_2 , V_5 , V_11 ) ;
switch ( V_42 -> V_103 & V_117 ) {
case V_118 :
V_101 = F_3 ( V_2 , V_8 ) ;
if ( ( F_24 ( V_2 ) == 4 ) && ( V_128 == 16 ) ) {
#ifdef V_75
if ( ! F_26 () )
return - V_80 ;
V_101 |= F_46 ( V_128 * 2 ) ;
V_101 |= F_47 ( V_128 * 4 ) ;
V_101 |= F_48 ( 3 ) ;
V_101 |= F_49 ( 3 ) ;
V_101 |= F_50 ( 1 ) ;
#else
return - V_80 ;
#endif
} else {
V_101 |= F_46 ( V_128 + 1 ) ;
V_101 |= F_47 ( ( V_128 + 1 ) * 2 ) ;
V_101 |= F_50 ( 1 ) ;
}
F_23 ( V_2 , V_8 , V_101 ) ;
break;
default:
break;
}
if ( ( V_11 & V_61 ) && ! V_129 ) {
F_37 ( & V_2 -> V_3 -> V_4 , L_11 ) ;
return - V_80 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static int F_51 ( struct V_37 * V_38 , int V_137 ,
struct V_39 * V_40 )
{
int V_43 = 0 ;
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_58 ;
switch ( V_137 ) {
case V_138 :
F_4 ( V_2 ) ;
break;
case V_139 :
V_58 = F_3 ( V_2 , V_6 ) ;
if ( V_38 -> V_131 == V_132 )
V_58 |= V_140 ;
else
V_58 |= V_141 ;
F_23 ( V_2 , V_6 , V_58 ) ;
V_58 = F_3 ( V_2 , V_9 ) ;
F_23 ( V_2 , V_9 , V_58 ) ;
break;
case V_142 :
V_58 = F_3 ( V_2 , V_6 ) ;
if ( V_38 -> V_131 == V_132 )
V_58 |= V_140 ;
else
V_58 |= V_141 ;
F_23 ( V_2 , V_6 , V_58 ) ;
F_4 ( V_2 ) ;
break;
case V_143 :
V_58 = F_3 ( V_2 , V_6 ) ;
if ( V_38 -> V_131 == V_132 )
V_58 &= ~ V_140 ;
else
V_58 &= ~ V_141 ;
F_23 ( V_2 , V_6 , V_58 ) ;
break;
case V_144 :
F_7 ( V_2 ) ;
break;
case V_145 :
V_58 = F_3 ( V_2 , V_6 ) ;
if ( V_38 -> V_131 == V_132 )
V_58 &= ~ V_140 ;
else
V_58 &= ~ V_141 ;
F_23 ( V_2 , V_6 , V_58 ) ;
break;
default:
V_43 = - V_80 ;
}
F_1 ( V_2 ) ;
return V_43 ;
}
static int F_52 ( struct V_39 * V_146 )
{
struct V_41 * V_42 ;
int V_43 ;
V_42 = F_9 ( sizeof( struct V_41 ) , V_19 ) ;
if ( ! V_42 )
return - V_147 ;
V_42 -> V_2 = F_53 ( V_146 -> V_63 + 1 , L_12 ) ;
if ( V_42 -> V_2 == NULL ) {
V_43 = - V_70 ;
goto V_148;
}
V_42 -> V_103 = ( unsigned int ) - 1 ;
F_54 ( V_146 , V_42 ) ;
return 0 ;
V_148:
F_14 ( V_42 ) ;
return V_43 ;
}
static int F_55 ( struct V_39 * V_146 )
{
struct V_41 * V_42 = F_12 ( V_146 ) ;
F_56 ( V_42 -> V_2 ) ;
F_14 ( V_42 ) ;
return 0 ;
}
static T_4 int F_57 ( struct V_149 * V_3 )
{
return F_58 ( & V_3 -> V_4 , & V_150 ) ;
}
static int T_5 F_59 ( struct V_149 * V_3 )
{
F_60 ( & V_3 -> V_4 ) ;
return 0 ;
}
