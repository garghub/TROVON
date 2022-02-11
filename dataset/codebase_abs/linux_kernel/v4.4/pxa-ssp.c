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
V_17 -> V_18 = V_14 ? V_19 :
V_20 ;
V_17 -> V_21 = 16 ;
V_17 -> V_22 = V_2 -> V_23 + V_24 ;
}
static int F_9 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
struct V_16 * V_17 ;
int V_31 = 0 ;
if ( ! V_28 -> V_32 ) {
F_11 ( V_2 -> V_33 ) ;
F_7 ( V_2 ) ;
}
V_17 = F_12 ( sizeof( struct V_16 ) , V_34 ) ;
if ( ! V_17 )
return - V_35 ;
V_17 -> V_36 = V_26 -> V_37 == V_38 ?
& V_2 -> V_39 : & V_2 -> V_40 ;
F_13 ( V_28 , V_26 , V_17 ) ;
return V_31 ;
}
static void F_14 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
if ( ! V_28 -> V_32 ) {
F_7 ( V_2 ) ;
F_15 ( V_2 -> V_33 ) ;
}
F_16 ( F_17 ( V_28 , V_26 ) ) ;
F_13 ( V_28 , V_26 , NULL ) ;
}
static int F_18 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
if ( ! V_28 -> V_32 )
F_11 ( V_2 -> V_33 ) ;
V_30 -> V_41 = F_5 ( V_2 -> V_12 + V_5 ) ;
V_30 -> V_42 = F_5 ( V_2 -> V_12 + V_6 ) ;
V_30 -> V_43 = F_5 ( V_2 -> V_12 + V_7 ) ;
V_30 -> V_44 = F_5 ( V_2 -> V_12 + V_8 ) ;
F_7 ( V_2 ) ;
F_15 ( V_2 -> V_33 ) ;
return 0 ;
}
static int F_19 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
T_1 V_45 = V_46 | V_47 | V_48 ;
F_11 ( V_2 -> V_33 ) ;
F_6 ( V_45 , V_2 -> V_12 + V_9 ) ;
F_6 ( V_30 -> V_41 & ~ V_13 , V_2 -> V_12 + V_5 ) ;
F_6 ( V_30 -> V_42 , V_2 -> V_12 + V_6 ) ;
F_6 ( V_30 -> V_43 , V_2 -> V_12 + V_7 ) ;
F_6 ( V_30 -> V_44 , V_2 -> V_12 + V_8 ) ;
if ( V_28 -> V_32 )
F_4 ( V_2 ) ;
else
F_15 ( V_2 -> V_33 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 , T_2 div )
{
T_2 V_11 = F_3 ( V_2 , V_5 ) ;
if ( V_2 -> type == V_49 ) {
V_11 &= ~ 0x0000ff00 ;
V_11 |= ( ( div - 2 ) / 2 ) << 8 ;
} else {
V_11 &= ~ 0x000fff00 ;
V_11 |= ( div - 1 ) << 8 ;
}
F_21 ( V_2 , V_5 , V_11 ) ;
}
static T_2 F_22 ( struct V_1 * V_2 )
{
T_2 V_11 = F_3 ( V_2 , V_5 ) ;
T_2 div ;
if ( V_2 -> type == V_49 )
div = ( ( V_11 >> 8 ) & 0xff ) * 2 + 2 ;
else
div = ( ( V_11 >> 8 ) & 0xfff ) + 1 ;
return div ;
}
static int F_23 ( struct V_27 * V_28 ,
int V_50 , unsigned int V_51 , int V_52 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
int V_53 ;
T_2 V_11 = F_3 ( V_2 , V_5 ) &
~ ( V_54 | V_55 | V_56 | V_57 ) ;
F_2 ( & V_2 -> V_3 -> V_4 ,
L_3 ,
V_28 -> V_58 , V_50 , V_51 ) ;
switch ( V_50 ) {
case V_59 :
V_11 |= V_56 ;
break;
case V_60 :
if ( V_2 -> type == V_49 )
V_30 -> V_61 = 1843200 ;
else
V_30 -> V_61 = 13000000 ;
break;
case V_62 :
V_30 -> V_61 = V_51 ;
V_11 |= V_54 ;
break;
case V_63 :
V_30 -> V_61 = V_51 ;
V_11 |= V_55 | V_56 ;
break;
case V_64 :
V_30 -> V_61 = 0 ;
F_20 ( V_2 , 1 ) ;
V_11 |= V_57 ;
break;
default:
return - V_65 ;
}
if ( V_2 -> type != V_66 )
F_15 ( V_2 -> V_33 ) ;
V_53 = F_3 ( V_2 , V_5 ) | V_11 ;
F_21 ( V_2 , V_5 , V_53 ) ;
if ( V_2 -> type != V_66 )
F_11 ( V_2 -> V_33 ) ;
return 0 ;
}
static int F_24 ( struct V_27 * V_28 ,
int V_67 , int div )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
int V_53 ;
switch ( V_67 ) {
case V_68 :
V_53 = ( F_3 ( V_2 , V_10 ) & ~ 0x7 ) | F_25 ( div ) ;
F_21 ( V_2 , V_10 , V_53 ) ;
break;
case V_69 :
V_53 = F_3 ( V_2 , V_10 ) ;
V_53 &= ~ V_70 ;
if ( V_2 -> type == V_66 )
V_53 &= ~ V_71 ;
switch ( div ) {
case V_72 :
V_53 |= V_70 ;
break;
case V_73 :
break;
case V_74 :
if ( V_2 -> type == V_66 )
V_53 |= V_71 ;
else
return - V_75 ;
break;
default:
return - V_75 ;
}
F_21 ( V_2 , V_10 , V_53 ) ;
break;
case V_76 :
F_20 ( V_2 , div ) ;
break;
default:
return - V_65 ;
}
return 0 ;
}
static int F_26 ( struct V_27 * V_28 , int V_77 ,
int V_78 , unsigned int V_79 , unsigned int V_80 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
T_2 V_81 = F_3 ( V_2 , V_10 ) & ~ 0x70 ;
if ( V_2 -> type == V_66 )
F_21 ( V_2 , V_82 , 0 ) ;
switch ( V_80 ) {
case 5622000 :
break;
case 11345000 :
V_81 |= ( 0x1 << 4 ) ;
break;
case 12235000 :
V_81 |= ( 0x2 << 4 ) ;
break;
case 14857000 :
V_81 |= ( 0x3 << 4 ) ;
break;
case 32842000 :
V_81 |= ( 0x4 << 4 ) ;
break;
case 48000000 :
V_81 |= ( 0x5 << 4 ) ;
break;
case 0 :
break;
default:
if ( V_2 -> type == V_66 ) {
T_2 V_53 ;
T_3 V_83 = 19968 ;
V_83 *= 1000000 ;
F_27 ( V_83 , V_80 ) ;
V_53 = V_83 ;
V_53 = ( V_53 << 16 ) | 64 ;
F_21 ( V_2 , V_82 , V_53 ) ;
V_81 |= ( 0x6 << 4 ) ;
F_2 ( & V_2 -> V_3 -> V_4 ,
L_4 ,
V_53 , V_80 ) ;
break;
}
return - V_75 ;
}
F_21 ( V_2 , V_10 , V_81 ) ;
return 0 ;
}
static int F_28 ( struct V_27 * V_28 ,
unsigned int V_84 , unsigned int V_85 , int V_86 , int V_87 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
T_2 V_11 ;
V_11 = F_3 ( V_2 , V_5 ) ;
V_11 &= ~ ( V_56 | F_29 ( 8 ) | V_88 | V_89 ) ;
if ( V_87 > 16 )
V_11 |= V_88 | F_30 ( V_87 - 16 ) ;
else
V_11 |= F_30 ( V_87 ) ;
if ( V_86 > 1 ) {
V_11 |= V_56 ;
V_11 |= F_29 ( V_86 ) ;
F_21 ( V_2 , V_90 , V_84 ) ;
F_21 ( V_2 , V_91 , V_85 ) ;
}
F_21 ( V_2 , V_5 , V_11 ) ;
return 0 ;
}
static int F_31 ( struct V_27 * V_28 ,
int V_92 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
T_2 V_93 ;
V_93 = F_3 ( V_2 , V_6 ) ;
if ( V_92 )
V_93 &= ~ V_94 ;
else
V_93 |= V_94 ;
F_21 ( V_2 , V_6 , V_93 ) ;
return 0 ;
}
static int F_32 ( struct V_27 * V_28 ,
unsigned int V_95 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
T_2 V_11 , V_93 , V_96 , V_97 ;
if ( V_30 -> V_98 == V_95 )
return 0 ;
if ( F_3 ( V_2 , V_5 ) & V_13 ) {
F_33 ( & V_2 -> V_3 -> V_4 ,
L_5 ) ;
return - V_75 ;
}
V_11 = F_3 ( V_2 , V_5 ) &
~ ( V_54 | V_55 | V_56 | V_57 ) ;
V_93 = F_34 ( 8 ) | F_35 ( 7 ) ;
V_96 = 0 ;
switch ( V_95 & V_99 ) {
case V_100 :
V_93 |= V_101 | V_102 | V_103 ;
break;
case V_104 :
V_93 |= V_101 | V_103 ;
break;
case V_105 :
break;
default:
return - V_75 ;
}
switch ( V_95 & V_106 ) {
case V_107 :
V_96 |= V_108 ;
break;
case V_109 :
break;
case V_110 :
V_96 |= F_36 ( 2 ) ;
break;
case V_111 :
V_96 |= F_36 ( 2 ) | V_108 ;
break;
default:
return - V_75 ;
}
switch ( V_95 & V_112 ) {
case V_113 :
V_11 |= V_114 ;
V_93 |= V_115 | V_116 ;
break;
case V_117 :
V_96 |= V_118 ;
case V_119 :
V_11 |= V_56 | V_114 ;
V_93 |= V_116 | V_115 ;
break;
default:
return - V_75 ;
}
F_21 ( V_2 , V_5 , V_11 ) ;
F_21 ( V_2 , V_6 , V_93 ) ;
F_21 ( V_2 , V_8 , V_96 ) ;
switch ( V_95 & V_99 ) {
case V_100 :
case V_104 :
V_97 = F_3 ( V_2 , V_6 ) | V_103 ;
F_21 ( V_2 , V_6 , V_97 ) ;
while ( F_3 ( V_2 , V_9 ) & V_120 )
F_37 () ;
break;
}
F_1 ( V_2 ) ;
V_30 -> V_98 = V_95 ;
return 0 ;
}
static int F_38 ( struct V_25 * V_26 ,
struct V_121 * V_122 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
int V_123 = F_39 ( V_122 ) ;
T_2 V_11 ;
T_2 V_96 ;
int V_124 = F_40 ( F_41 ( V_122 ) ) ;
int V_125 = F_3 ( V_2 , V_90 ) & 0xf ;
struct V_16 * V_126 ;
V_126 = F_17 ( V_28 , V_26 ) ;
F_8 ( V_2 ,
( ( V_123 == 2 ) && ( V_125 != 1 ) ) || ( V_124 == 32 ) ,
V_26 -> V_37 == V_38 , V_126 ) ;
if ( F_3 ( V_2 , V_5 ) & V_13 )
return 0 ;
V_11 = F_3 ( V_2 , V_5 ) & ~ ( V_89 | V_88 ) ;
switch ( F_41 ( V_122 ) ) {
case V_127 :
if ( V_2 -> type == V_66 )
V_11 |= V_128 ;
V_11 |= F_30 ( 16 ) ;
break;
case V_129 :
V_11 |= ( V_88 | F_30 ( 8 ) ) ;
break;
case V_130 :
V_11 |= ( V_88 | F_30 ( 16 ) ) ;
break;
}
F_21 ( V_2 , V_5 , V_11 ) ;
switch ( V_30 -> V_98 & V_112 ) {
case V_113 :
V_96 = F_3 ( V_2 , V_8 ) ;
if ( ( F_22 ( V_2 ) == 4 ) && ( V_124 == 16 ) ) {
if ( V_2 -> type != V_66 )
return - V_75 ;
V_96 |= F_42 ( V_124 * 2 ) ;
V_96 |= F_43 ( V_124 * 4 ) ;
V_96 |= F_44 ( 3 ) ;
V_96 |= F_45 ( 3 ) ;
V_96 |= F_46 ( 1 ) ;
} else {
V_96 |= F_42 ( V_124 + 1 ) ;
V_96 |= F_43 ( ( V_124 + 1 ) * 2 ) ;
V_96 |= F_46 ( 1 ) ;
}
F_21 ( V_2 , V_8 , V_96 ) ;
break;
default:
break;
}
if ( ( V_11 & V_56 ) && ! V_125 ) {
F_33 ( & V_2 -> V_3 -> V_4 , L_6 ) ;
return - V_75 ;
}
F_1 ( V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_25 * V_26 ,
struct V_1 * V_2 , int V_131 )
{
T_1 V_11 = F_3 ( V_2 , V_5 ) ;
T_1 V_93 = F_3 ( V_2 , V_6 ) ;
T_1 V_96 = F_3 ( V_2 , V_8 ) ;
T_1 V_45 = F_3 ( V_2 , V_9 ) ;
if ( V_131 && ( V_11 & V_13 ) )
F_21 ( V_2 , V_5 , V_11 & ~ V_13 ) ;
if ( V_26 -> V_37 == V_38 ) {
if ( V_131 )
V_93 |= V_132 ;
else
V_93 &= ~ V_132 ;
} else {
if ( V_131 )
V_93 |= V_133 ;
else
V_93 &= ~ V_133 ;
}
F_21 ( V_2 , V_6 , V_93 ) ;
if ( V_131 ) {
F_21 ( V_2 , V_9 , V_45 ) ;
F_21 ( V_2 , V_8 , V_96 ) ;
F_21 ( V_2 , V_5 , V_11 | V_13 ) ;
}
}
static int F_48 ( struct V_25 * V_26 , int V_134 ,
struct V_27 * V_28 )
{
int V_31 = 0 ;
struct V_29 * V_30 = F_10 ( V_28 ) ;
struct V_1 * V_2 = V_30 -> V_2 ;
int V_53 ;
switch ( V_134 ) {
case V_135 :
F_4 ( V_2 ) ;
break;
case V_136 :
F_47 ( V_26 , V_2 , 1 ) ;
V_53 = F_3 ( V_2 , V_9 ) ;
F_21 ( V_2 , V_9 , V_53 ) ;
break;
case V_137 :
F_47 ( V_26 , V_2 , 1 ) ;
break;
case V_138 :
F_47 ( V_26 , V_2 , 0 ) ;
break;
case V_139 :
F_7 ( V_2 ) ;
break;
case V_140 :
F_47 ( V_26 , V_2 , 0 ) ;
break;
default:
V_31 = - V_75 ;
}
F_1 ( V_2 ) ;
return V_31 ;
}
static int F_49 ( struct V_27 * V_141 )
{
struct V_142 * V_4 = V_141 -> V_4 ;
struct V_29 * V_30 ;
int V_31 ;
V_30 = F_12 ( sizeof( struct V_29 ) , V_34 ) ;
if ( ! V_30 )
return - V_35 ;
if ( V_4 -> V_143 ) {
struct V_144 * V_145 ;
V_145 = F_50 ( V_4 -> V_143 , L_7 , 0 ) ;
if ( ! V_145 ) {
F_33 ( V_4 , L_8 ) ;
V_31 = - V_65 ;
goto V_146;
}
V_30 -> V_2 = F_51 ( V_145 , L_9 ) ;
if ( V_30 -> V_2 == NULL ) {
V_31 = - V_65 ;
goto V_146;
}
} else {
V_30 -> V_2 = F_52 ( V_141 -> V_58 + 1 , L_9 ) ;
if ( V_30 -> V_2 == NULL ) {
V_31 = - V_65 ;
goto V_146;
}
}
V_30 -> V_98 = ( unsigned int ) - 1 ;
F_53 ( V_141 , V_30 ) ;
return 0 ;
V_146:
F_16 ( V_30 ) ;
return V_31 ;
}
static int F_54 ( struct V_27 * V_141 )
{
struct V_29 * V_30 = F_10 ( V_141 ) ;
F_55 ( V_30 -> V_2 ) ;
F_16 ( V_30 ) ;
return 0 ;
}
static int F_56 ( struct V_147 * V_3 )
{
return F_57 ( & V_3 -> V_4 , & V_148 ,
& V_149 , 1 ) ;
}
