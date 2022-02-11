static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_3 )
{
void T_3 * V_4 = V_1 -> V_5 + ( ( V_6 ) V_2 << 20 ) + V_3 ;
return F_2 ( V_4 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_3 , T_1 V_7 )
{
void T_3 * V_4 = V_1 -> V_5 + ( ( V_6 ) V_2 << 20 ) + V_3 ;
F_4 ( V_7 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_3 , T_1 V_7 )
{
void T_3 * V_4 = V_1 -> V_5 + ( ( V_6 ) V_2 << 20 ) + V_3 ;
F_4 ( V_7 | F_2 ( V_4 ) , V_4 ) ;
}
static int F_6 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_8 , T_1 V_9 , bool V_10 )
{
int V_11 = 100 ;
T_1 V_12 ;
while ( V_11 ) {
V_12 = F_1 ( V_1 , V_2 , V_8 ) ;
if ( V_10 && ! ( V_12 & V_9 ) )
return 0 ;
if ( ! V_10 && ( V_12 & V_9 ) )
return 0 ;
F_7 ( 1000 , 2000 ) ;
V_11 -- ;
}
return 1 ;
}
static void F_8 ( struct V_13 * V_14 )
{
T_4 V_15 ;
if ( V_16 )
return;
F_9 ( V_14 , V_17 , & V_15 ) ;
switch ( V_15 ) {
case V_18 :
case V_19 :
V_16 = V_20 ;
break;
case V_21 :
V_16 = V_22 ;
break;
case V_23 :
default:
V_16 = V_24 ;
break;
}
}
static struct V_1 * F_10 ( int V_25 , int V_26 )
{
int V_27 = ( V_25 * V_16 ) + V_26 ;
return V_28 [ V_27 ] ;
}
unsigned F_11 ( int V_25 )
{
int V_29 ;
unsigned V_30 = 0 ;
for ( V_29 = 0 ; V_29 < V_16 ; V_29 ++ ) {
if ( V_28 [ ( V_25 * V_16 ) + V_29 ] )
V_30 |= ( 1 << V_29 ) ;
}
return V_30 ;
}
int F_12 ( int V_25 , int V_26 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_25 , V_26 ) ;
if ( V_1 )
return V_1 -> V_31 ;
return 0 ;
}
void F_13 ( int V_25 , int V_26 , int V_32 , void * V_33 )
{
struct V_34 * V_35 = (struct V_34 * ) V_33 ;
struct V_1 * V_1 ;
struct V_2 * V_2 ;
V_1 = F_10 ( V_25 , V_26 ) ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_32 ] ;
V_35 -> V_36 = V_2 -> V_37 ;
V_35 -> V_38 = V_2 -> V_38 ;
V_35 -> V_39 = V_2 -> V_40 ;
V_35 -> V_41 = V_2 -> V_42 ;
}
const T_2 * F_14 ( int V_25 , int V_26 , int V_32 )
{
struct V_1 * V_1 = F_10 ( V_25 , V_26 ) ;
if ( V_1 )
return V_1 -> V_2 [ V_32 ] . V_43 ;
return NULL ;
}
void F_15 ( int V_25 , int V_26 , int V_32 , const T_2 * V_43 )
{
struct V_1 * V_1 = F_10 ( V_25 , V_26 ) ;
if ( ! V_1 )
return;
F_16 ( V_1 -> V_2 [ V_32 ] . V_43 , V_43 ) ;
}
void F_17 ( int V_25 , int V_26 , int V_32 , bool V_44 )
{
struct V_1 * V_1 = F_10 ( V_25 , V_26 ) ;
struct V_2 * V_2 ;
T_1 V_45 ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_32 ] ;
V_45 = F_1 ( V_1 , V_32 , V_46 ) ;
if ( V_44 )
V_45 |= V_47 | V_48 ;
else
V_45 &= ~ ( V_47 | V_48 ) ;
F_3 ( V_1 , V_32 , V_46 , V_45 ) ;
if ( V_1 -> V_49 )
F_18 ( V_44 ? V_2 -> V_38 : 0 , V_2 -> V_42 ) ;
}
void F_19 ( int V_25 , int V_26 , int V_32 , void * V_50 )
{
struct V_51 * V_51 = (struct V_51 * ) V_50 ;
struct V_1 * V_1 = F_10 ( V_25 , V_26 ) ;
struct V_2 * V_2 ;
T_1 V_45 ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_32 ] ;
if ( V_2 -> V_52 )
return;
V_45 = F_1 ( V_1 , V_32 , V_53 ) ;
V_51 -> V_54 = V_45 & V_55 ;
V_51 -> V_56 = V_45 & V_57 ;
V_51 -> V_58 = 0 ;
}
void F_20 ( int V_25 , int V_26 , int V_32 , void * V_50 )
{
struct V_51 * V_51 = (struct V_51 * ) V_50 ;
struct V_1 * V_1 = F_10 ( V_25 , V_26 ) ;
struct V_2 * V_2 ;
T_1 V_45 ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_32 ] ;
if ( V_2 -> V_52 )
return;
V_45 = F_1 ( V_1 , V_32 , V_53 ) ;
V_45 &= ~ ( V_55 | V_57 ) ;
V_45 |= ( V_51 -> V_54 ? V_55 : 0x00 ) ;
V_45 |= ( V_51 -> V_56 ? V_57 : 0x00 ) ;
F_3 ( V_1 , V_32 , V_53 , V_45 ) ;
}
static void F_21 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
T_1 V_59 ;
T_1 V_60 = 0 ;
T_1 V_61 = 0 ;
bool V_62 , V_63 ;
V_59 = F_1 ( V_1 , V_2 -> V_32 , V_46 ) ;
V_62 = V_59 & V_48 ;
V_63 = V_59 & V_47 ;
V_59 &= ~ ( V_47 | V_48 ) ;
F_3 ( V_1 , V_2 -> V_32 , V_46 , V_59 ) ;
if ( F_6 ( V_1 , V_2 -> V_32 , V_64 ,
V_65 , false ) ) {
F_22 ( & V_1 -> V_14 -> V_66 , L_1 ,
V_1 -> V_67 , V_2 -> V_32 ) ;
return;
}
if ( F_6 ( V_1 , V_2 -> V_32 , V_64 ,
V_68 , false ) ) {
F_22 ( & V_1 -> V_14 -> V_66 , L_2 ,
V_1 -> V_67 , V_2 -> V_32 ) ;
return;
}
V_60 = F_1 ( V_1 , V_2 -> V_32 , V_64 ) ;
V_61 = F_1 ( V_1 , V_2 -> V_32 , V_69 ) ;
if ( V_2 -> V_38 ) {
V_61 &= ~ V_70 ;
V_60 &= ~ V_71 ;
V_60 |= ( V_2 -> V_40 << 2 ) ;
} else {
V_61 |= V_70 ;
}
switch ( V_2 -> V_42 ) {
case 10 :
V_60 &= ~ V_72 ;
V_60 |= V_73 ;
V_60 &= ~ V_74 ;
V_61 &= ~ V_75 ;
V_61 |= 50 ;
F_3 ( V_1 , V_2 -> V_32 , V_76 , 64 ) ;
F_3 ( V_1 , V_2 -> V_32 , V_77 , 0 ) ;
break;
case 100 :
V_60 &= ~ V_72 ;
V_60 &= ~ V_73 ;
V_60 &= ~ V_74 ;
V_61 &= ~ V_75 ;
V_61 |= 5 ;
F_3 ( V_1 , V_2 -> V_32 , V_76 , 64 ) ;
F_3 ( V_1 , V_2 -> V_32 , V_77 , 0 ) ;
break;
case 1000 :
V_60 |= V_72 ;
V_60 &= ~ V_73 ;
V_60 |= V_74 ;
V_61 &= ~ V_75 ;
V_61 |= 1 ;
F_3 ( V_1 , V_2 -> V_32 , V_76 , 512 ) ;
if ( V_2 -> V_40 )
F_3 ( V_1 , V_2 -> V_32 ,
V_77 , 0 ) ;
else
F_3 ( V_1 , V_2 -> V_32 ,
V_77 , 8192 ) ;
break;
default:
break;
}
F_3 ( V_1 , V_2 -> V_32 , V_69 , V_61 ) ;
F_3 ( V_1 , V_2 -> V_32 , V_64 , V_60 ) ;
V_59 |= ( V_63 ? V_47 : 0 ) | ( V_62 ? V_48 : 0 ) ;
F_3 ( V_1 , V_2 -> V_32 , V_46 , V_59 ) ;
if ( V_1 -> V_49 && ( V_59 & ( V_47 | V_48 ) ) )
F_18 ( V_2 -> V_38 , V_2 -> V_42 ) ;
}
static void F_23 ( struct V_78 * V_79 )
{
struct V_2 * V_2 = F_24 ( V_79 , struct V_2 , V_79 ) ;
struct V_80 * V_81 ;
int V_82 = 0 ;
if ( ! V_2 )
return;
V_81 = V_2 -> V_81 ;
if ( ! V_81 -> V_35 && V_2 -> V_83 )
V_82 = - 1 ;
if ( V_81 -> V_35 &&
( V_2 -> V_40 != V_81 -> V_39 ||
V_2 -> V_83 != V_81 -> V_35 ||
V_2 -> V_42 != V_81 -> V_41 ) ) {
V_82 = 1 ;
}
V_2 -> V_83 = V_81 -> V_35 ;
V_2 -> V_42 = V_81 -> V_41 ;
V_2 -> V_40 = V_81 -> V_39 ;
if ( ! V_82 )
return;
if ( V_82 > 0 )
V_2 -> V_38 = true ;
else
V_2 -> V_38 = false ;
if ( V_2 -> V_52 )
F_21 ( V_2 ) ;
else
F_25 ( V_2 ) ;
}
T_1 F_26 ( int V_25 , int V_26 , int V_2 , int V_27 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_25 , V_26 ) ;
if ( ! V_1 )
return 0 ;
if ( V_27 > 8 )
V_2 = 0 ;
return F_1 ( V_1 , V_2 , V_84 + ( V_27 * 8 ) ) ;
}
T_1 F_27 ( int V_25 , int V_26 , int V_2 , int V_27 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_25 , V_26 ) ;
if ( ! V_1 )
return 0 ;
return F_1 ( V_1 , V_2 , V_85 + ( V_27 * 8 ) ) ;
}
static void F_28 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
while ( V_1 -> V_2 [ V_2 ] . V_86 > 0 ) {
V_3 = ( ( V_1 -> V_2 [ V_2 ] . V_86 - 1 ) * sizeof( T_1 ) ) +
( V_2 * V_87 * sizeof( T_1 ) ) ;
F_3 ( V_1 , 0 , V_88 + V_3 , 0 ) ;
V_1 -> V_2 [ V_2 ] . V_86 -- ;
}
}
void F_29 ( int V_25 , int V_26 ,
int V_89 , bool V_44 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
T_1 V_45 ;
V_1 = F_10 ( V_25 , V_26 ) ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_89 ] ;
if ( V_2 -> V_52 ) {
V_45 = F_1 ( V_1 , V_89 , V_90 ) ;
if ( V_44 )
V_45 |= V_91 ;
else
V_45 &= ~ V_91 ;
F_3 ( V_1 , V_89 , V_90 , V_45 ) ;
} else {
V_45 = F_1 ( V_1 , V_89 , V_92 ) ;
if ( V_44 )
V_45 |= V_93 ;
else
V_45 &= ~ V_93 ;
F_3 ( V_1 , V_89 , V_92 , V_45 ) ;
}
}
static int F_30 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_32 = V_2 -> V_32 ;
T_1 V_45 ;
F_5 ( V_1 , V_32 , V_94 , 0x30 ) ;
F_5 ( V_1 , V_32 , V_95 , V_96 ) ;
V_45 = F_1 ( V_1 , V_32 , V_97 ) ;
if ( V_45 & 1 )
F_3 ( V_1 , V_32 , V_98 , 0 ) ;
F_5 ( V_1 , V_32 , V_46 , V_99 ) ;
F_5 ( V_1 , V_32 , V_90 , V_100 ) ;
if ( F_6 ( V_1 , V_32 , V_90 ,
V_100 , true ) ) {
F_22 ( & V_1 -> V_14 -> V_66 , L_3 ) ;
return - 1 ;
}
V_45 = F_1 ( V_1 , V_32 , V_90 ) ;
V_45 &= ~ V_101 ;
V_45 |= V_102 ;
if ( V_2 -> V_81 ) {
V_45 |= V_103 ;
} else {
if ( V_45 & V_103 )
V_2 -> V_58 = true ;
}
F_3 ( V_1 , V_32 , V_90 , V_45 ) ;
if ( V_2 -> V_37 == V_104 ) {
V_45 = F_1 ( V_1 , V_32 , V_69 ) ;
V_45 &= ~ V_105 ;
F_3 ( V_1 , V_32 , V_69 , V_45 ) ;
return 0 ;
}
if ( ( V_2 -> V_37 == V_106 ) && V_2 -> V_81 ) {
if ( F_6 ( V_1 , V_32 , V_107 ,
V_108 , false ) ) {
F_22 ( & V_1 -> V_14 -> V_66 , L_4 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
T_1 V_45 ;
int V_32 = V_2 -> V_32 ;
F_5 ( V_1 , V_32 , V_92 , V_109 ) ;
if ( F_6 ( V_1 , V_32 , V_92 , V_109 , true ) ) {
F_22 ( & V_1 -> V_14 -> V_66 , L_5 ) ;
return - 1 ;
}
V_45 = F_1 ( V_1 , V_32 , V_46 ) ;
V_45 &= ~ V_99 ;
F_3 ( V_1 , V_32 , V_46 , V_45 ) ;
F_5 ( V_1 , V_32 , V_92 , V_110 ) ;
if ( V_2 -> V_37 == V_111 )
F_5 ( V_1 , V_32 , V_112 ,
V_113 ) ;
V_45 = F_1 ( V_1 , V_32 , V_112 ) ;
V_45 &= ~ V_114 ;
F_3 ( V_1 , V_32 , V_112 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_115 ) ;
F_3 ( V_1 , V_32 , V_115 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_116 ) ;
F_3 ( V_1 , V_32 , V_116 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_117 ) ;
F_3 ( V_1 , V_32 , V_117 , V_45 ) ;
if ( V_2 -> V_118 ) {
F_3 ( V_1 , V_32 , V_119 , 0x00 ) ;
F_3 ( V_1 , V_32 , V_120 , 0x00 ) ;
F_3 ( V_1 , V_32 , V_121 , 0x00 ) ;
F_5 ( V_1 , V_32 ,
V_122 , V_123 ) ;
}
F_5 ( V_1 , V_32 , V_124 , V_125 ) ;
V_45 = F_1 ( V_1 , V_32 , V_126 ) ;
V_45 &= ~ V_127 ;
F_3 ( V_1 , V_32 , V_126 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_128 ) ;
V_45 = V_45 & ~ ( V_129 | V_130 ) ;
F_3 ( V_1 , V_32 , V_128 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_131 ) ;
if ( V_2 -> V_37 == V_132 )
V_45 |= ( 1 << 23 ) ;
else if ( V_2 -> V_37 == V_133 )
V_45 |= ( 1 << 24 ) ;
else
V_45 &= ~ ( ( 1 << 23 ) | ( 1 << 24 ) ) ;
V_45 = V_45 & ( ~ ( ( 1ULL << 25 ) | ( 1ULL << 22 ) | ( 1ULL << 12 ) ) ) ;
F_3 ( V_1 , V_32 , V_131 , V_45 ) ;
V_45 = F_1 ( V_1 , 0 , V_134 ) ;
V_45 &= ~ V_135 ;
F_3 ( V_1 , 0 , V_134 , V_45 ) ;
F_5 ( V_1 , V_32 , V_46 , V_99 ) ;
V_45 = F_1 ( V_1 , V_32 , V_92 ) ;
V_45 &= ~ V_110 ;
F_3 ( V_1 , V_32 , V_92 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_136 ) ;
V_45 &= ~ V_137 ;
V_45 |= V_138 ;
F_3 ( V_1 , V_32 , V_136 , V_45 ) ;
F_3 ( V_1 , V_32 , V_53 , ( ( 0xffffULL << 32 ) |
V_139 | V_140 | V_57 | V_55 ) ) ;
F_3 ( V_1 , V_32 ,
V_141 , V_142 ) ;
V_45 = F_1 ( V_1 , V_32 , V_143 ) ;
V_45 &= ~ 0xFFFFull ;
F_3 ( V_1 , V_32 , V_143 ,
V_45 | ( V_142 - 0x1000 ) ) ;
F_3 ( V_1 , V_32 , V_144 , 0x01 ) ;
F_5 ( V_1 , V_32 , V_145 , ( 0x100 - 1 ) ) ;
F_5 ( V_1 , V_32 , V_146 , V_96 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
int V_32 = V_2 -> V_32 ;
int V_37 = V_2 -> V_37 ;
T_1 V_45 ;
if ( V_2 -> V_118 ) {
V_45 = F_1 ( V_1 , V_32 , V_117 ) ;
if ( ! ( V_45 & ( 1ull << 13 ) ) ) {
V_45 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_32 , V_117 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_122 ) ;
V_45 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_32 , V_122 , V_45 ) ;
return - 1 ;
}
}
if ( F_6 ( V_1 , V_32 , V_92 , V_109 , true ) ) {
F_22 ( & V_1 -> V_14 -> V_66 , L_5 ) ;
return - 1 ;
}
if ( ( V_37 == V_132 ) || ( V_37 == V_147 ) ||
( V_37 == V_133 ) || ( V_37 == V_148 ) ) {
if ( F_6 ( V_1 , V_32 , V_149 ,
V_150 , false ) ) {
F_22 ( & V_1 -> V_14 -> V_66 ,
L_6 ) ;
return - 1 ;
}
} else {
if ( F_6 ( V_1 , V_32 , V_151 ,
V_152 , false ) ) {
F_22 ( & V_1 -> V_14 -> V_66 ,
L_7 ) ;
return - 1 ;
}
}
if ( F_1 ( V_1 , V_32 , V_153 ) & V_154 )
F_5 ( V_1 , V_32 ,
V_153 , V_154 ) ;
if ( F_1 ( V_1 , V_32 , V_153 ) & V_154 ) {
F_22 ( & V_1 -> V_14 -> V_66 , L_8 ) ;
if ( V_2 -> V_118 ) {
V_45 = F_1 ( V_1 , V_32 , V_117 ) ;
if ( ! ( V_45 & ( 1ull << 13 ) ) ) {
V_45 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_32 , V_117 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 ,
V_122 ) ;
V_45 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_32 ,
V_122 , V_45 ) ;
return - 1 ;
}
}
return - 1 ;
}
if ( F_6 ( V_1 , V_32 , V_155 , V_156 , false ) ) {
F_22 ( & V_1 -> V_14 -> V_66 , L_9 ) ;
return - 1 ;
}
if ( F_6 ( V_1 , V_32 , V_155 , V_157 , false ) ) {
F_22 ( & V_1 -> V_14 -> V_66 , L_10 ) ;
return - 1 ;
}
V_45 = F_1 ( V_1 , V_32 , V_158 ) ;
V_45 &= V_159 ;
if ( ! V_45 )
return 0 ;
F_31 ( V_1 , V_2 ) ;
return - 1 ;
}
static void F_32 ( struct V_2 * V_2 )
{
T_1 V_160 , V_161 ;
T_2 V_41 ;
V_160 = F_1 ( V_2 -> V_1 , V_2 -> V_32 ,
V_107 ) ;
if ( ! ( V_160 & V_162 ) )
V_160 = F_1 ( V_2 -> V_1 , V_2 -> V_32 ,
V_107 ) ;
if ( F_6 ( V_2 -> V_1 , V_2 -> V_32 , V_107 ,
V_108 , false ) ) {
V_2 -> V_38 = false ;
V_2 -> V_42 = V_163 ;
V_2 -> V_40 = V_164 ;
goto V_165;
}
V_2 -> V_38 = ( ( V_160 & V_162 ) != 0 ) ? true : false ;
V_161 = F_1 ( V_2 -> V_1 , V_2 -> V_32 ,
V_166 ) ;
V_41 = ( V_161 >> 3 ) & 0x3 ;
V_2 -> V_40 = ( V_161 >> 1 ) & 0x1 ;
switch ( V_41 ) {
case 0 :
V_2 -> V_42 = 10 ;
break;
case 1 :
V_2 -> V_42 = 100 ;
break;
case 2 :
V_2 -> V_42 = 1000 ;
break;
default:
V_2 -> V_38 = false ;
V_2 -> V_42 = V_163 ;
V_2 -> V_40 = V_164 ;
break;
}
V_165:
if ( V_2 -> V_83 != V_2 -> V_38 ) {
if ( V_2 -> V_38 )
F_21 ( V_2 ) ;
V_2 -> V_83 = V_2 -> V_38 ;
}
F_33 ( V_2 -> V_167 , & V_2 -> V_168 , V_169 * 3 ) ;
}
static void F_34 ( struct V_170 * V_171 )
{
struct V_2 * V_2 ;
T_1 V_172 , V_173 ;
V_2 = F_24 ( V_171 , struct V_2 , V_168 . V_171 ) ;
if ( V_2 -> V_52 ) {
F_32 ( V_2 ) ;
return;
}
F_5 ( V_2 -> V_1 , V_2 -> V_32 ,
V_174 , V_175 ) ;
F_6 ( V_2 -> V_1 , V_2 -> V_32 , V_174 ,
V_175 , false ) ;
V_172 = F_1 ( V_2 -> V_1 , V_2 -> V_32 , V_174 ) ;
V_173 = F_1 ( V_2 -> V_1 , V_2 -> V_32 , V_158 ) ;
if ( ( V_172 & V_175 ) &&
! ( V_173 & V_159 ) ) {
V_2 -> V_38 = 1 ;
if ( V_2 -> V_37 == V_148 )
V_2 -> V_42 = 40000 ;
else
V_2 -> V_42 = 10000 ;
V_2 -> V_40 = 1 ;
} else {
V_2 -> V_38 = 0 ;
V_2 -> V_42 = V_163 ;
V_2 -> V_40 = V_164 ;
}
if ( V_2 -> V_83 != V_2 -> V_38 ) {
if ( V_2 -> V_38 ) {
if ( F_25 ( V_2 ) ) {
V_2 -> V_38 = 0 ;
V_2 -> V_42 = V_163 ;
V_2 -> V_40 = V_164 ;
}
}
V_2 -> V_83 = V_2 -> V_38 ;
}
F_33 ( V_2 -> V_167 , & V_2 -> V_168 , V_169 * 2 ) ;
}
static int F_35 ( T_2 V_37 )
{
if ( V_37 == V_104 )
return V_176 ;
if ( V_37 == V_177 )
return V_178 ;
return V_179 ;
}
static int F_36 ( struct V_1 * V_1 , T_2 V_32 )
{
struct V_2 * V_2 ;
T_1 V_45 ;
V_2 = & V_1 -> V_2 [ V_32 ] ;
V_2 -> V_1 = V_1 ;
if ( ( V_2 -> V_37 == V_106 ) ||
( V_2 -> V_37 == V_104 ) ||
( V_2 -> V_37 == V_177 ) ) {
V_2 -> V_52 = 1 ;
if ( F_30 ( V_1 , V_2 ) )
return - 1 ;
} else {
V_2 -> V_52 = 0 ;
if ( F_31 ( V_1 , V_2 ) )
return - 1 ;
}
if ( V_2 -> V_52 ) {
V_45 = F_1 ( V_1 , V_32 , V_97 ) ;
V_45 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_32 , V_97 , V_45 ) ;
F_3 ( V_1 , V_32 , V_180 , 60 - 1 ) ;
} else {
V_45 = F_1 ( V_1 , V_32 , V_124 ) ;
V_45 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_32 , V_124 , V_45 ) ;
F_3 ( V_1 , V_32 , V_181 , 60 + 4 ) ;
}
F_5 ( V_1 , V_32 , V_46 , V_99 ) ;
F_3 ( V_1 , V_32 , V_182 , 0x03 ) ;
if ( ( V_2 -> V_37 != V_147 ) &&
( V_2 -> V_37 != V_148 ) &&
( V_2 -> V_37 != V_133 ) &&
( V_2 -> V_37 != V_132 ) ) {
if ( ! V_2 -> V_81 ) {
if ( V_2 -> V_58 ) {
F_3 ( V_1 , V_32 ,
V_183 ,
V_184 ) ;
goto V_185;
} else {
V_2 -> V_38 = true ;
V_2 -> V_42 = 1000 ;
V_2 -> V_40 = 1 ;
F_21 ( V_2 ) ;
return 0 ;
}
}
V_2 -> V_81 -> V_186 = 0 ;
if ( F_37 ( & V_2 -> V_79 , V_2 -> V_81 ,
F_23 ,
F_35 ( V_2 -> V_37 ) ) )
return - V_187 ;
F_38 ( V_2 -> V_81 ) ;
return 0 ;
}
V_185:
V_2 -> V_167 = F_39 ( L_11 , V_188 |
V_189 , 1 ) ;
if ( ! V_2 -> V_167 )
return - V_190 ;
F_40 ( & V_2 -> V_168 , F_34 ) ;
F_33 ( V_2 -> V_167 , & V_2 -> V_168 , 0 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_1 , T_2 V_32 )
{
struct V_2 * V_2 ;
T_1 V_45 ;
V_2 = & V_1 -> V_2 [ V_32 ] ;
if ( V_2 -> V_167 ) {
F_42 ( & V_2 -> V_168 ) ;
F_43 ( V_2 -> V_167 ) ;
}
V_45 = F_1 ( V_1 , V_32 , V_46 ) ;
V_45 &= ~ V_47 ;
F_3 ( V_1 , V_32 , V_46 , V_45 ) ;
F_6 ( V_1 , V_32 , V_191 , ( T_1 ) 0x1FFF , true ) ;
F_6 ( V_1 , V_32 , V_192 , ( T_1 ) 0x3FFF , true ) ;
V_45 = F_1 ( V_1 , V_32 , V_46 ) ;
V_45 &= ~ V_48 ;
F_3 ( V_1 , V_32 , V_46 , V_45 ) ;
if ( ! V_2 -> V_52 )
F_5 ( V_1 , V_32 ,
V_92 , V_110 ) ;
else
F_5 ( V_1 , V_32 ,
V_90 , V_101 ) ;
V_45 = F_1 ( V_1 , V_32 , V_46 ) ;
V_45 &= ~ V_99 ;
F_3 ( V_1 , V_32 , V_46 , V_45 ) ;
F_28 ( V_1 , V_32 ) ;
if ( ( V_2 -> V_37 != V_147 ) &&
( V_2 -> V_37 != V_148 ) &&
( V_2 -> V_37 != V_133 ) &&
( V_2 -> V_37 != V_132 ) && V_2 -> V_81 )
F_44 ( V_2 -> V_81 ) ;
V_2 -> V_81 = NULL ;
}
static void F_45 ( struct V_1 * V_1 )
{
int V_29 ;
struct V_2 * V_2 ;
F_5 ( V_1 , 0 , V_193 , V_194 ) ;
if ( F_1 ( V_1 , 0 , V_195 ) )
F_22 ( & V_1 -> V_14 -> V_66 , L_12 , V_1 -> V_67 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_2 = & V_1 -> V_2 [ V_29 ] ;
F_3 ( V_1 , V_29 , V_46 ,
( V_2 -> V_37 << 8 ) | V_2 -> V_196 ) ;
V_1 -> V_2 [ V_29 ] . V_197 = V_31 ;
V_31 ++ ;
}
F_3 ( V_1 , 0 , V_198 , V_1 -> V_31 ) ;
F_3 ( V_1 , 0 , V_199 , V_1 -> V_31 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_5 ( V_1 , 0 , V_200 ,
( ( 1ULL << V_201 ) - 1 ) <<
( V_29 * V_201 ) ) ;
for ( V_29 = 0 ; V_29 < V_202 ; V_29 ++ )
F_3 ( V_1 , 0 , V_88 + ( V_29 * 8 ) , 0x00 ) ;
for ( V_29 = 0 ; V_29 < V_203 ; V_29 ++ )
F_3 ( V_1 , 0 , V_204 + ( V_29 * 8 ) , 0x00 ) ;
}
static T_2 F_46 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return ( T_2 ) ( F_1 ( V_1 , V_2 -> V_32 , V_46 ) & 0xFF ) ;
}
static void F_47 ( struct V_1 * V_1 , T_2 V_32 )
{
struct V_205 * V_66 = & V_1 -> V_14 -> V_66 ;
struct V_2 * V_2 ;
char V_206 [ 27 ] ;
if ( ! V_1 -> V_207 && V_32 )
return;
V_2 = & V_1 -> V_2 [ V_32 ] ;
if ( ! V_1 -> V_207 )
sprintf ( V_206 , L_13 , V_1 -> V_67 ) ;
else
sprintf ( V_206 , L_14 , V_1 -> V_67 , V_32 ) ;
switch ( V_2 -> V_37 ) {
case V_106 :
F_48 ( V_66 , L_15 , ( char * ) V_206 ) ;
break;
case V_208 :
F_48 ( V_66 , L_16 , ( char * ) V_206 ) ;
break;
case V_111 :
F_48 ( V_66 , L_17 , ( char * ) V_206 ) ;
break;
case V_147 :
if ( ! V_2 -> V_118 )
F_48 ( V_66 , L_18 , ( char * ) V_206 ) ;
else
F_48 ( V_66 , L_19 , ( char * ) V_206 ) ;
break;
case V_148 :
if ( ! V_2 -> V_118 )
F_48 ( V_66 , L_20 , ( char * ) V_206 ) ;
else
F_48 ( V_66 , L_21 , ( char * ) V_206 ) ;
break;
case V_104 :
F_48 ( V_66 , L_22 , ( char * ) V_206 ) ;
break;
case V_177 :
F_48 ( V_66 , L_23 , ( char * ) V_206 ) ;
break;
case V_209 :
break;
}
}
static void F_49 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
switch ( V_2 -> V_37 ) {
case V_106 :
case V_147 :
V_2 -> V_196 = V_2 -> V_32 ;
break;
case V_208 :
case V_148 :
case V_177 :
V_2 -> V_196 = 0xE4 ;
break;
case V_111 :
V_2 -> V_196 = ( V_2 -> V_32 ) ? 0xE : 0x4 ;
break;
case V_104 :
V_2 -> V_196 = F_46 ( V_1 , V_2 ) ;
break;
default:
V_2 -> V_196 = 0 ;
break;
}
}
static void F_50 ( struct V_1 * V_1 , struct V_2 * V_2 , int V_32 )
{
if ( ( V_2 -> V_37 != V_132 ) &&
( V_2 -> V_37 != V_133 ) ) {
V_2 -> V_118 = 0 ;
return;
}
V_2 -> V_118 = F_1 ( V_1 , V_32 , V_122 ) &
V_123 ;
}
static void F_51 ( struct V_1 * V_1 , T_2 V_27 )
{
struct V_2 * V_2 ;
T_1 V_59 ;
T_2 V_37 ;
T_2 V_196 ;
V_2 = & V_1 -> V_2 [ V_27 ] ;
if ( ! V_1 -> V_207 || V_1 -> V_49 ) {
V_59 = F_1 ( V_1 , 0 , V_46 ) ;
V_2 -> V_37 = ( V_59 >> 8 ) & 0x07 ;
if ( V_1 -> V_49 )
V_2 -> V_37 = V_177 ;
F_50 ( V_1 , V_2 , 0 ) ;
F_49 ( V_1 , V_2 ) ;
return;
}
V_59 = F_1 ( V_1 , V_27 , V_46 ) ;
V_37 = ( T_2 ) ( ( V_59 >> 8 ) & 0x07 ) ;
V_196 = ( T_2 ) ( V_59 & 0xFF ) ;
if ( ( V_37 == 0 ) && ( V_196 == 0xE4 ) )
V_2 -> V_37 = V_209 ;
else
V_2 -> V_37 = V_37 ;
V_2 -> V_196 = V_196 ;
F_50 ( V_1 , V_2 , V_2 -> V_32 ) ;
}
static void F_52 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
T_2 V_27 ;
for ( V_27 = 0 ; V_27 < V_1 -> V_210 ; V_27 ++ ) {
V_2 = & V_1 -> V_2 [ V_27 ] ;
V_2 -> V_32 = V_27 ;
V_2 -> V_37 = V_209 ;
V_2 -> V_118 = false ;
}
V_1 -> V_31 = F_1 ( V_1 , 0 , V_199 ) & 0x7 ;
if ( V_1 -> V_31 > V_1 -> V_210 )
V_1 -> V_31 = V_1 -> V_210 ;
for ( V_27 = 0 ; V_27 < V_1 -> V_31 ; V_27 ++ ) {
F_51 ( V_1 , V_27 ) ;
F_47 ( V_1 , V_27 ) ;
}
}
static int F_53 ( struct V_205 * V_66 , struct V_211 * V_212 ,
T_2 * V_213 )
{
T_2 V_43 [ V_214 ] ;
int V_215 ;
V_215 = F_54 ( F_55 ( V_212 ) ,
L_24 , V_43 , V_214 ) ;
if ( V_215 )
goto V_216;
if ( ! F_56 ( V_43 ) ) {
F_22 ( V_66 , L_25 , V_43 ) ;
V_215 = - V_217 ;
goto V_216;
}
F_48 ( V_66 , L_26 , V_43 ) ;
memcpy ( V_213 , V_43 , V_214 ) ;
V_216:
return V_215 ;
}
static T_5 F_57 ( T_6 V_218 ,
V_6 V_219 , void * V_220 , void * * V_221 )
{
struct V_1 * V_1 = V_220 ;
struct V_205 * V_66 = & V_1 -> V_14 -> V_66 ;
struct V_211 * V_212 ;
if ( F_58 ( V_218 , & V_212 ) )
goto V_216;
F_53 ( V_66 , V_212 , V_1 -> V_2 [ V_1 -> V_222 ] . V_43 ) ;
F_59 ( & V_1 -> V_2 [ V_1 -> V_222 ] . V_79 , V_66 ) ;
V_1 -> V_2 [ V_1 -> V_222 ] . V_32 = V_1 -> V_222 ;
V_1 -> V_222 ++ ;
V_216:
return V_223 ;
}
static T_5 F_60 ( T_6 V_218 , V_6 V_219 ,
void * V_220 , void * * V_224 )
{
struct V_225 string = { V_226 , NULL } ;
struct V_1 * V_1 = V_220 ;
char V_227 [ 5 ] ;
snprintf ( V_227 , 5 , L_27 , V_1 -> V_67 ) ;
if ( F_61 ( F_62 ( V_218 , V_228 , & string ) ) ) {
F_63 ( L_28 ) ;
return V_223 ;
}
if ( strncmp ( string . V_229 , V_227 , 4 ) )
return V_223 ;
F_64 ( V_230 , V_218 , 1 ,
F_57 , NULL , V_1 , NULL ) ;
F_65 ( string . V_229 ) ;
return V_231 ;
}
static int F_66 ( struct V_1 * V_1 )
{
F_67 ( NULL , F_60 , V_1 , ( void * * ) NULL ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_1 )
{
return - V_187 ;
}
static int F_68 ( struct V_1 * V_1 )
{
struct V_232 * V_233 ;
struct V_234 * V_25 = NULL ;
T_2 V_2 = 0 ;
F_69 (&bgx->pdev->dev, fwn) {
struct V_80 * V_235 ;
struct V_234 * V_236 ;
const char * V_43 ;
V_25 = F_70 ( V_233 ) ;
if ( ! V_25 )
break;
V_43 = F_71 ( V_25 ) ;
if ( V_43 )
F_16 ( V_1 -> V_2 [ V_2 ] . V_43 , V_43 ) ;
F_59 ( & V_1 -> V_2 [ V_2 ] . V_79 , & V_1 -> V_14 -> V_66 ) ;
V_1 -> V_2 [ V_2 ] . V_32 = V_2 ;
V_236 = F_72 ( V_25 , L_29 , 0 ) ;
if ( V_236 &&
! F_73 ( V_236 , L_30 ) ) {
V_235 = F_74 ( V_236 ) ;
if ( ! V_235 )
goto V_237;
V_1 -> V_2 [ V_2 ] . V_81 = V_235 ;
}
V_2 ++ ;
if ( V_2 == V_1 -> V_210 ) {
F_75 ( V_25 ) ;
break;
}
}
return 0 ;
V_237:
while ( V_2 ) {
if ( V_1 -> V_2 [ V_2 ] . V_81 ) {
F_76 ( & V_1 -> V_2 [ V_2 ] . V_81 -> V_238 . V_66 ) ;
V_1 -> V_2 [ V_2 ] . V_81 = NULL ;
}
V_2 -- ;
}
F_75 ( V_25 ) ;
return - V_239 ;
}
static int F_68 ( struct V_1 * V_1 )
{
return - V_187 ;
}
static int F_77 ( struct V_1 * V_1 )
{
if ( ! V_240 )
return F_66 ( V_1 ) ;
return F_68 ( V_1 ) ;
}
static int F_78 ( struct V_13 * V_14 , const struct V_241 * V_242 )
{
int V_243 ;
struct V_205 * V_66 = & V_14 -> V_66 ;
struct V_1 * V_1 = NULL ;
T_2 V_2 ;
T_4 V_15 ;
V_1 = F_79 ( V_66 , sizeof( * V_1 ) , V_244 ) ;
if ( ! V_1 )
return - V_190 ;
V_1 -> V_14 = V_14 ;
F_80 ( V_14 , V_1 ) ;
V_243 = F_81 ( V_14 ) ;
if ( V_243 ) {
F_22 ( V_66 , L_31 ) ;
F_80 ( V_14 , NULL ) ;
return V_243 ;
}
V_243 = F_82 ( V_14 , V_245 ) ;
if ( V_243 ) {
F_22 ( V_66 , L_32 , V_243 ) ;
goto V_246;
}
V_1 -> V_5 = F_83 ( V_14 , V_247 , 0 ) ;
if ( ! V_1 -> V_5 ) {
F_22 ( V_66 , L_33 ) ;
V_243 = - V_190 ;
goto V_248;
}
F_8 ( V_14 ) ;
F_9 ( V_14 , V_249 , & V_15 ) ;
if ( V_15 != V_250 ) {
V_1 -> V_67 = ( F_84 ( V_14 ,
V_247 ) >> 24 ) & V_251 ;
V_1 -> V_67 += F_85 ( V_14 ) * V_16 ;
V_1 -> V_210 = V_252 ;
V_28 [ V_1 -> V_67 ] = V_1 ;
} else {
V_1 -> V_49 = true ;
V_1 -> V_210 = 1 ;
V_1 -> V_67 = V_20 - 1 ;
V_28 [ V_1 -> V_67 ] = V_1 ;
F_86 () ;
}
F_9 ( V_14 , V_17 , & V_15 ) ;
if ( ( V_15 == V_18 ) ||
( ( V_15 == V_21 ) && ( V_1 -> V_67 == 2 ) ) )
V_1 -> V_207 = true ;
F_52 ( V_1 ) ;
V_243 = F_77 ( V_1 ) ;
if ( V_243 )
goto V_253;
F_45 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_31 ; V_2 ++ ) {
V_243 = F_36 ( V_1 , V_2 ) ;
if ( V_243 ) {
F_22 ( V_66 , L_34 ,
V_1 -> V_67 , V_2 ) ;
while ( V_2 )
F_41 ( V_1 , -- V_2 ) ;
goto V_253;
}
}
return 0 ;
V_253:
V_28 [ V_1 -> V_67 ] = NULL ;
V_248:
F_87 ( V_14 ) ;
V_246:
F_88 ( V_14 ) ;
F_80 ( V_14 , NULL ) ;
return V_243 ;
}
static void F_89 ( struct V_13 * V_14 )
{
struct V_1 * V_1 = F_90 ( V_14 ) ;
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_31 ; V_2 ++ )
F_41 ( V_1 , V_2 ) ;
V_28 [ V_1 -> V_67 ] = NULL ;
F_87 ( V_14 ) ;
F_88 ( V_14 ) ;
F_80 ( V_14 , NULL ) ;
}
static int T_7 F_91 ( void )
{
F_92 ( L_35 , V_245 , V_254 ) ;
return F_93 ( & V_255 ) ;
}
static void T_8 F_94 ( void )
{
F_95 ( & V_255 ) ;
}
