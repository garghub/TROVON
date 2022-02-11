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
static void F_8 ( struct V_1 * V_2 , int V_14 ,
int V_15 , struct V_16 * V_17 )
{
struct V_18 * V_19 ;
V_19 = F_9 ( V_17 , struct V_18 , V_20 ) ;
snprintf ( V_19 -> V_21 , 20 , L_3 , V_2 -> V_22 ,
V_14 ? L_4 : L_5 , V_15 ? L_6 : L_7 ) ;
V_19 -> V_20 . V_21 = V_19 -> V_21 ;
V_19 -> V_20 . V_23 = & F_10 ( V_15 ? V_2 -> V_24 : V_2 -> V_25 ) ;
V_19 -> V_20 . V_26 = ( V_15 ? ( V_27 | V_28 ) :
( V_29 | V_30 ) ) |
( V_14 ? V_31 : V_32 ) | V_33 ;
V_19 -> V_20 . V_34 = V_2 -> V_35 + V_36 ;
}
static int F_11 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_18 * V_19 ;
int V_43 = 0 ;
if ( ! V_40 -> V_44 ) {
F_13 ( V_2 -> V_45 ) ;
F_7 ( V_2 ) ;
}
V_19 = F_14 ( sizeof( struct V_18 ) , V_46 ) ;
if ( ! V_19 )
return - V_47 ;
F_15 ( V_40 , V_38 , & V_19 -> V_20 ) ;
return V_43 ;
}
static void F_16 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
if ( ! V_40 -> V_44 ) {
F_7 ( V_2 ) ;
F_17 ( V_2 -> V_45 ) ;
}
F_18 ( F_19 ( V_40 , V_38 ) ) ;
F_15 ( V_40 , V_38 , NULL ) ;
}
static int F_20 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
if ( ! V_40 -> V_44 )
F_13 ( V_2 -> V_45 ) ;
V_42 -> V_48 = F_5 ( V_2 -> V_12 + V_5 ) ;
V_42 -> V_49 = F_5 ( V_2 -> V_12 + V_6 ) ;
V_42 -> V_50 = F_5 ( V_2 -> V_12 + V_7 ) ;
V_42 -> V_51 = F_5 ( V_2 -> V_12 + V_8 ) ;
F_7 ( V_2 ) ;
F_17 ( V_2 -> V_45 ) ;
return 0 ;
}
static int F_21 ( struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_1 V_52 = V_53 | V_54 | V_55 ;
F_13 ( V_2 -> V_45 ) ;
F_6 ( V_52 , V_2 -> V_12 + V_9 ) ;
F_6 ( V_42 -> V_48 & ~ V_13 , V_2 -> V_12 + V_5 ) ;
F_6 ( V_42 -> V_49 , V_2 -> V_12 + V_6 ) ;
F_6 ( V_42 -> V_50 , V_2 -> V_12 + V_7 ) ;
F_6 ( V_42 -> V_51 , V_2 -> V_12 + V_8 ) ;
if ( V_40 -> V_44 )
F_4 ( V_2 ) ;
else
F_17 ( V_2 -> V_45 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , T_2 div )
{
T_2 V_11 = F_3 ( V_2 , V_5 ) ;
if ( V_2 -> type == V_56 ) {
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
if ( V_2 -> type == V_56 )
div = ( ( V_11 >> 8 ) & 0xff ) * 2 + 2 ;
else
div = ( ( V_11 >> 8 ) & 0xfff ) + 1 ;
return div ;
}
static int F_25 ( struct V_39 * V_40 ,
int V_57 , unsigned int V_58 , int V_59 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_60 ;
T_2 V_11 = F_3 ( V_2 , V_5 ) &
~ ( V_61 | V_62 | V_63 | V_64 ) ;
F_2 ( & V_2 -> V_3 -> V_4 ,
L_8 ,
V_40 -> V_65 , V_57 , V_58 ) ;
switch ( V_57 ) {
case V_66 :
V_11 |= V_63 ;
break;
case V_67 :
if ( V_2 -> type == V_56 )
V_42 -> V_68 = 1843200 ;
else
V_42 -> V_68 = 13000000 ;
break;
case V_69 :
V_42 -> V_68 = V_58 ;
V_11 |= V_61 ;
break;
case V_70 :
V_42 -> V_68 = V_58 ;
V_11 |= V_62 | V_63 ;
break;
case V_71 :
V_42 -> V_68 = 0 ;
F_22 ( V_2 , 1 ) ;
V_11 |= V_64 ;
break;
default:
return - V_72 ;
}
if ( V_2 -> type != V_73 )
F_17 ( V_2 -> V_45 ) ;
V_60 = F_3 ( V_2 , V_5 ) | V_11 ;
F_23 ( V_2 , V_5 , V_60 ) ;
if ( V_2 -> type != V_73 )
F_13 ( V_2 -> V_45 ) ;
return 0 ;
}
static int F_26 ( struct V_39 * V_40 ,
int V_74 , int div )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_60 ;
switch ( V_74 ) {
case V_75 :
V_60 = ( F_3 ( V_2 , V_10 ) & ~ 0x7 ) | F_27 ( div ) ;
F_23 ( V_2 , V_10 , V_60 ) ;
break;
case V_76 :
V_60 = F_3 ( V_2 , V_10 ) ;
V_60 &= ~ V_77 ;
if ( V_2 -> type == V_73 )
V_60 &= ~ V_78 ;
switch ( div ) {
case V_79 :
V_60 |= V_77 ;
break;
case V_80 :
break;
case V_81 :
if ( V_2 -> type == V_73 )
V_60 |= V_78 ;
else
return - V_82 ;
break;
default:
return - V_82 ;
}
F_23 ( V_2 , V_10 , V_60 ) ;
break;
case V_83 :
F_22 ( V_2 , div ) ;
break;
default:
return - V_72 ;
}
return 0 ;
}
static int F_28 ( struct V_39 * V_40 , int V_84 ,
int V_85 , unsigned int V_86 , unsigned int V_87 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_2 V_88 = F_3 ( V_2 , V_10 ) & ~ 0x70 ;
if ( V_2 -> type == V_73 )
F_23 ( V_2 , V_89 , 0 ) ;
switch ( V_87 ) {
case 5622000 :
break;
case 11345000 :
V_88 |= ( 0x1 << 4 ) ;
break;
case 12235000 :
V_88 |= ( 0x2 << 4 ) ;
break;
case 14857000 :
V_88 |= ( 0x3 << 4 ) ;
break;
case 32842000 :
V_88 |= ( 0x4 << 4 ) ;
break;
case 48000000 :
V_88 |= ( 0x5 << 4 ) ;
break;
case 0 :
break;
default:
if ( V_2 -> type == V_73 ) {
T_2 V_60 ;
T_3 V_90 = 19968 ;
V_90 *= 1000000 ;
F_29 ( V_90 , V_87 ) ;
V_60 = V_90 ;
V_60 = ( V_60 << 16 ) | 64 ;
F_23 ( V_2 , V_89 , V_60 ) ;
V_88 |= ( 0x6 << 4 ) ;
F_2 ( & V_2 -> V_3 -> V_4 ,
L_9 ,
V_60 , V_87 ) ;
break;
}
return - V_82 ;
}
F_23 ( V_2 , V_10 , V_88 ) ;
return 0 ;
}
static int F_30 ( struct V_39 * V_40 ,
unsigned int V_91 , unsigned int V_92 , int V_93 , int V_94 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_2 V_11 ;
V_11 = F_3 ( V_2 , V_5 ) ;
V_11 &= ~ ( V_63 | F_31 ( 8 ) | V_95 | V_96 ) ;
if ( V_94 > 16 )
V_11 |= V_95 | F_32 ( V_94 - 16 ) ;
else
V_11 |= F_32 ( V_94 ) ;
if ( V_93 > 1 ) {
V_11 |= V_63 ;
V_11 |= F_31 ( V_93 ) ;
F_23 ( V_2 , V_97 , V_91 ) ;
F_23 ( V_2 , V_98 , V_92 ) ;
}
F_23 ( V_2 , V_5 , V_11 ) ;
return 0 ;
}
static int F_33 ( struct V_39 * V_40 ,
int V_99 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_2 V_100 ;
V_100 = F_3 ( V_2 , V_6 ) ;
if ( V_99 )
V_100 &= ~ V_101 ;
else
V_100 |= V_101 ;
F_23 ( V_2 , V_6 , V_100 ) ;
return 0 ;
}
static int F_34 ( struct V_39 * V_40 ,
unsigned int V_102 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
T_2 V_11 , V_100 , V_103 , V_104 ;
if ( V_42 -> V_105 == V_102 )
return 0 ;
if ( F_3 ( V_2 , V_5 ) & V_13 ) {
F_35 ( & V_2 -> V_3 -> V_4 ,
L_10 ) ;
return - V_82 ;
}
V_11 = F_3 ( V_2 , V_5 ) &
~ ( V_61 | V_62 | V_63 | V_64 ) ;
V_100 = F_36 ( 8 ) | F_37 ( 7 ) ;
V_103 = 0 ;
switch ( V_102 & V_106 ) {
case V_107 :
V_100 |= V_108 | V_109 | V_110 ;
break;
case V_111 :
V_100 |= V_108 | V_110 ;
break;
case V_112 :
break;
default:
return - V_82 ;
}
switch ( V_102 & V_113 ) {
case V_114 :
V_103 |= V_115 ;
break;
case V_116 :
break;
case V_117 :
V_103 |= F_38 ( 2 ) ;
break;
case V_118 :
V_103 |= F_38 ( 2 ) | V_115 ;
break;
default:
return - V_82 ;
}
switch ( V_102 & V_119 ) {
case V_120 :
V_11 |= V_121 ;
V_100 |= V_122 | V_123 ;
break;
case V_124 :
V_103 |= V_125 ;
case V_126 :
V_11 |= V_63 | V_121 ;
V_100 |= V_123 | V_122 ;
break;
default:
return - V_82 ;
}
F_23 ( V_2 , V_5 , V_11 ) ;
F_23 ( V_2 , V_6 , V_100 ) ;
F_23 ( V_2 , V_8 , V_103 ) ;
switch ( V_102 & V_106 ) {
case V_107 :
case V_111 :
V_104 = F_3 ( V_2 , V_6 ) | V_110 ;
F_23 ( V_2 , V_6 , V_104 ) ;
while ( F_3 ( V_2 , V_9 ) & V_127 )
F_39 () ;
break;
}
F_1 ( V_2 ) ;
V_42 -> V_105 = V_102 ;
return 0 ;
}
static int F_40 ( struct V_37 * V_38 ,
struct V_128 * V_20 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_129 = F_41 ( V_20 ) ;
T_2 V_11 ;
T_2 V_103 ;
int V_130 = F_42 ( F_43 ( V_20 ) ) ;
int V_131 = F_3 ( V_2 , V_97 ) & 0xf ;
struct V_16 * V_17 ;
V_17 = F_19 ( V_40 , V_38 ) ;
F_8 ( V_2 ,
( ( V_129 == 2 ) && ( V_131 != 1 ) ) || ( V_130 == 32 ) ,
V_38 -> V_132 == V_133 , V_17 ) ;
if ( F_3 ( V_2 , V_5 ) & V_13 )
return 0 ;
V_11 = F_3 ( V_2 , V_5 ) & ~ ( V_96 | V_95 ) ;
switch ( F_43 ( V_20 ) ) {
case V_134 :
if ( V_2 -> type == V_73 )
V_11 |= V_135 ;
V_11 |= F_32 ( 16 ) ;
break;
case V_136 :
V_11 |= ( V_95 | F_32 ( 8 ) ) ;
break;
case V_137 :
V_11 |= ( V_95 | F_32 ( 16 ) ) ;
break;
}
F_23 ( V_2 , V_5 , V_11 ) ;
switch ( V_42 -> V_105 & V_119 ) {
case V_120 :
V_103 = F_3 ( V_2 , V_8 ) ;
if ( ( F_24 ( V_2 ) == 4 ) && ( V_130 == 16 ) ) {
if ( V_2 -> type != V_73 )
return - V_82 ;
V_103 |= F_44 ( V_130 * 2 ) ;
V_103 |= F_45 ( V_130 * 4 ) ;
V_103 |= F_46 ( 3 ) ;
V_103 |= F_47 ( 3 ) ;
V_103 |= F_48 ( 1 ) ;
} else {
V_103 |= F_44 ( V_130 + 1 ) ;
V_103 |= F_45 ( ( V_130 + 1 ) * 2 ) ;
V_103 |= F_48 ( 1 ) ;
}
F_23 ( V_2 , V_8 , V_103 ) ;
break;
default:
break;
}
if ( ( V_11 & V_63 ) && ! V_131 ) {
F_35 ( & V_2 -> V_3 -> V_4 , L_11 ) ;
return - V_82 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static void F_49 ( struct V_37 * V_38 ,
struct V_1 * V_2 , int V_138 )
{
T_1 V_11 = F_3 ( V_2 , V_5 ) ;
T_1 V_100 = F_3 ( V_2 , V_6 ) ;
T_1 V_103 = F_3 ( V_2 , V_8 ) ;
T_1 V_52 = F_3 ( V_2 , V_9 ) ;
if ( V_138 && ( V_11 & V_13 ) )
F_23 ( V_2 , V_5 , V_11 & ~ V_13 ) ;
if ( V_38 -> V_132 == V_133 ) {
if ( V_138 )
V_100 |= V_139 ;
else
V_100 &= ~ V_139 ;
} else {
if ( V_138 )
V_100 |= V_140 ;
else
V_100 &= ~ V_140 ;
}
F_23 ( V_2 , V_6 , V_100 ) ;
if ( V_138 ) {
F_23 ( V_2 , V_9 , V_52 ) ;
F_23 ( V_2 , V_8 , V_103 ) ;
F_23 ( V_2 , V_5 , V_11 | V_13 ) ;
}
}
static int F_50 ( struct V_37 * V_38 , int V_141 ,
struct V_39 * V_40 )
{
int V_43 = 0 ;
struct V_41 * V_42 = F_12 ( V_40 ) ;
struct V_1 * V_2 = V_42 -> V_2 ;
int V_60 ;
switch ( V_141 ) {
case V_142 :
F_4 ( V_2 ) ;
break;
case V_143 :
F_49 ( V_38 , V_2 , 1 ) ;
V_60 = F_3 ( V_2 , V_9 ) ;
F_23 ( V_2 , V_9 , V_60 ) ;
break;
case V_144 :
F_49 ( V_38 , V_2 , 1 ) ;
break;
case V_145 :
F_49 ( V_38 , V_2 , 0 ) ;
break;
case V_146 :
F_7 ( V_2 ) ;
break;
case V_147 :
F_49 ( V_38 , V_2 , 0 ) ;
break;
default:
V_43 = - V_82 ;
}
F_1 ( V_2 ) ;
return V_43 ;
}
static int F_51 ( struct V_39 * V_148 )
{
struct V_41 * V_42 ;
int V_43 ;
V_42 = F_14 ( sizeof( struct V_41 ) , V_46 ) ;
if ( ! V_42 )
return - V_47 ;
V_42 -> V_2 = F_52 ( V_148 -> V_65 + 1 , L_12 ) ;
if ( V_42 -> V_2 == NULL ) {
V_43 = - V_72 ;
goto V_149;
}
V_42 -> V_105 = ( unsigned int ) - 1 ;
F_53 ( V_148 , V_42 ) ;
return 0 ;
V_149:
F_18 ( V_42 ) ;
return V_43 ;
}
static int F_54 ( struct V_39 * V_148 )
{
struct V_41 * V_42 = F_12 ( V_148 ) ;
F_55 ( V_42 -> V_2 ) ;
F_18 ( V_42 ) ;
return 0 ;
}
static int F_56 ( struct V_150 * V_3 )
{
return F_57 ( & V_3 -> V_4 , & V_151 ,
& V_152 , 1 ) ;
}
static int F_58 ( struct V_150 * V_3 )
{
F_59 ( & V_3 -> V_4 ) ;
return 0 ;
}
