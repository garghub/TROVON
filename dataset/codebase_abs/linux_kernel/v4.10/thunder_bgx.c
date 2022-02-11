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
unsigned F_8 ( int V_13 )
{
int V_14 ;
unsigned V_15 = 0 ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
if ( V_17 [ ( V_13 * V_16 ) + V_14 ] )
V_15 |= ( 1 << V_14 ) ;
}
return V_15 ;
}
int F_9 ( int V_13 , int V_18 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( V_1 )
return V_1 -> V_19 ;
return 0 ;
}
void F_10 ( int V_13 , int V_18 , int V_20 , void * V_21 )
{
struct V_22 * V_23 = (struct V_22 * ) V_21 ;
struct V_1 * V_1 ;
struct V_2 * V_2 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_23 -> V_24 = V_2 -> V_25 ;
V_23 -> V_26 = V_2 -> V_26 ;
V_23 -> V_27 = V_2 -> V_28 ;
V_23 -> V_29 = V_2 -> V_30 ;
}
const T_2 * F_11 ( int V_13 , int V_18 , int V_20 )
{
struct V_1 * V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( V_1 )
return V_1 -> V_2 [ V_20 ] . V_31 ;
return NULL ;
}
void F_12 ( int V_13 , int V_18 , int V_20 , const T_2 * V_31 )
{
struct V_1 * V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return;
F_13 ( V_1 -> V_2 [ V_20 ] . V_31 , V_31 ) ;
}
void F_14 ( int V_13 , int V_18 , int V_20 , bool V_32 )
{
struct V_1 * V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
struct V_2 * V_2 ;
T_1 V_33 ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_33 = F_1 ( V_1 , V_20 , V_34 ) ;
if ( V_32 )
V_33 |= V_35 | V_36 ;
else
V_33 &= ~ ( V_35 | V_36 ) ;
F_3 ( V_1 , V_20 , V_34 , V_33 ) ;
if ( V_1 -> V_37 )
F_15 ( V_32 ? V_2 -> V_26 : 0 , V_2 -> V_30 ) ;
}
void F_16 ( int V_13 , int V_18 , int V_20 , void * V_38 )
{
struct V_39 * V_39 = (struct V_39 * ) V_38 ;
struct V_1 * V_1 = V_17 [ ( V_13 * V_40 ) + V_18 ] ;
struct V_2 * V_2 ;
T_1 V_33 ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_20 ] ;
if ( V_2 -> V_41 )
return;
V_33 = F_1 ( V_1 , V_20 , V_42 ) ;
V_39 -> V_43 = V_33 & V_44 ;
V_39 -> V_45 = V_33 & V_46 ;
V_39 -> V_47 = 0 ;
}
void F_17 ( int V_13 , int V_18 , int V_20 , void * V_38 )
{
struct V_39 * V_39 = (struct V_39 * ) V_38 ;
struct V_1 * V_1 = V_17 [ ( V_13 * V_40 ) + V_18 ] ;
struct V_2 * V_2 ;
T_1 V_33 ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_20 ] ;
if ( V_2 -> V_41 )
return;
V_33 = F_1 ( V_1 , V_20 , V_42 ) ;
V_33 &= ~ ( V_44 | V_46 ) ;
V_33 |= ( V_39 -> V_43 ? V_44 : 0x00 ) ;
V_33 |= ( V_39 -> V_45 ? V_46 : 0x00 ) ;
F_3 ( V_1 , V_20 , V_42 , V_33 ) ;
}
static void F_18 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
T_1 V_48 ;
T_1 V_49 = 0 ;
T_1 V_50 = 0 ;
V_48 = F_1 ( V_1 , V_2 -> V_20 , V_34 ) ;
V_48 &= ~ V_51 ;
F_3 ( V_1 , V_2 -> V_20 , V_34 , V_48 ) ;
V_49 = F_1 ( V_1 , V_2 -> V_20 , V_52 ) ;
V_50 = F_1 ( V_1 , V_2 -> V_20 , V_53 ) ;
if ( V_2 -> V_26 ) {
V_50 &= ~ V_54 ;
V_49 &= ~ V_55 ;
V_49 |= ( V_2 -> V_28 << 2 ) ;
} else {
V_50 |= V_54 ;
}
switch ( V_2 -> V_30 ) {
case 10 :
V_49 &= ~ V_56 ;
V_49 |= V_57 ;
V_49 &= ~ V_58 ;
V_50 &= ~ V_59 ;
V_50 |= 50 ;
F_3 ( V_1 , V_2 -> V_20 , V_60 , 64 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_61 , 0 ) ;
break;
case 100 :
V_49 &= ~ V_56 ;
V_49 &= ~ V_57 ;
V_49 &= ~ V_58 ;
V_50 &= ~ V_59 ;
V_50 |= 5 ;
F_3 ( V_1 , V_2 -> V_20 , V_60 , 64 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_61 , 0 ) ;
break;
case 1000 :
V_49 |= V_56 ;
V_49 &= ~ V_57 ;
V_49 |= V_58 ;
V_50 &= ~ V_59 ;
V_50 |= 1 ;
F_3 ( V_1 , V_2 -> V_20 , V_60 , 512 ) ;
if ( V_2 -> V_28 )
F_3 ( V_1 , V_2 -> V_20 ,
V_61 , 0 ) ;
else
F_3 ( V_1 , V_2 -> V_20 ,
V_61 , 8192 ) ;
break;
default:
break;
}
F_3 ( V_1 , V_2 -> V_20 , V_53 , V_50 ) ;
F_3 ( V_1 , V_2 -> V_20 , V_52 , V_49 ) ;
V_49 = F_1 ( V_1 , V_2 -> V_20 , V_52 ) ;
V_48 |= V_51 ;
F_3 ( V_1 , V_2 -> V_20 , V_34 , V_48 ) ;
if ( V_1 -> V_37 && ( V_48 & ( V_35 | V_36 ) ) )
F_15 ( V_2 -> V_26 , V_2 -> V_30 ) ;
}
static void F_19 ( struct V_62 * V_63 )
{
struct V_2 * V_2 = F_20 ( V_63 , struct V_2 , V_63 ) ;
struct V_64 * V_65 ;
int V_66 = 0 ;
if ( ! V_2 )
return;
V_65 = V_2 -> V_65 ;
if ( ! V_65 -> V_23 && V_2 -> V_67 )
V_66 = - 1 ;
if ( V_65 -> V_23 &&
( V_2 -> V_28 != V_65 -> V_27 ||
V_2 -> V_67 != V_65 -> V_23 ||
V_2 -> V_30 != V_65 -> V_29 ) ) {
V_66 = 1 ;
}
V_2 -> V_67 = V_65 -> V_23 ;
V_2 -> V_30 = V_65 -> V_29 ;
V_2 -> V_28 = V_65 -> V_27 ;
if ( ! V_66 )
return;
if ( V_66 > 0 )
V_2 -> V_26 = true ;
else
V_2 -> V_26 = false ;
if ( V_2 -> V_41 )
F_18 ( V_2 ) ;
else
F_21 ( V_2 ) ;
}
T_1 F_22 ( int V_13 , int V_18 , int V_2 , int V_68 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return 0 ;
if ( V_68 > 8 )
V_2 = 0 ;
return F_1 ( V_1 , V_2 , V_69 + ( V_68 * 8 ) ) ;
}
T_1 F_23 ( int V_13 , int V_18 , int V_2 , int V_68 )
{
struct V_1 * V_1 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return 0 ;
return F_1 ( V_1 , V_2 , V_70 + ( V_68 * 8 ) ) ;
}
static void F_24 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
while ( V_1 -> V_2 [ V_2 ] . V_71 > 0 ) {
V_3 = ( ( V_1 -> V_2 [ V_2 ] . V_71 - 1 ) * sizeof( T_1 ) ) +
( V_2 * V_72 * sizeof( T_1 ) ) ;
F_3 ( V_1 , 0 , V_73 + V_3 , 0 ) ;
V_1 -> V_2 [ V_2 ] . V_71 -- ;
}
}
void F_25 ( int V_13 , int V_18 ,
int V_74 , bool V_32 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
T_1 V_33 ;
V_1 = V_17 [ ( V_13 * V_16 ) + V_18 ] ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_74 ] ;
if ( V_2 -> V_41 ) {
V_33 = F_1 ( V_1 , V_74 , V_75 ) ;
if ( V_32 )
V_33 |= V_76 ;
else
V_33 &= ~ V_76 ;
F_3 ( V_1 , V_74 , V_75 , V_33 ) ;
} else {
V_33 = F_1 ( V_1 , V_74 , V_77 ) ;
if ( V_32 )
V_33 |= V_78 ;
else
V_33 &= ~ V_78 ;
F_3 ( V_1 , V_74 , V_77 , V_33 ) ;
}
}
static int F_26 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_20 = V_2 -> V_20 ;
T_1 V_33 ;
F_5 ( V_1 , V_20 , V_79 , 0x30 ) ;
F_5 ( V_1 , V_20 , V_80 , V_81 ) ;
V_33 = F_1 ( V_1 , V_20 , V_82 ) ;
if ( V_33 & 1 )
F_3 ( V_1 , V_20 , V_83 , 0 ) ;
F_5 ( V_1 , V_20 , V_34 , V_51 ) ;
F_5 ( V_1 , V_20 , V_75 , V_84 ) ;
if ( F_6 ( V_1 , V_20 , V_75 ,
V_84 , true ) ) {
F_27 ( & V_1 -> V_85 -> V_86 , L_1 ) ;
return - 1 ;
}
V_33 = F_1 ( V_1 , V_20 , V_75 ) ;
V_33 &= ~ V_87 ;
V_33 |= V_88 ;
if ( V_2 -> V_65 ) {
V_33 |= V_89 ;
} else {
if ( V_33 & V_89 )
V_2 -> V_47 = true ;
}
F_3 ( V_1 , V_20 , V_75 , V_33 ) ;
if ( V_2 -> V_25 == V_90 ) {
V_33 = F_1 ( V_1 , V_20 , V_53 ) ;
V_33 &= ~ V_91 ;
F_3 ( V_1 , V_20 , V_53 , V_33 ) ;
return 0 ;
}
if ( ( V_2 -> V_25 == V_92 ) && V_2 -> V_65 ) {
if ( F_6 ( V_1 , V_20 , V_93 ,
V_94 , false ) ) {
F_27 ( & V_1 -> V_85 -> V_86 , L_2 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
T_1 V_33 ;
int V_20 = V_2 -> V_20 ;
F_5 ( V_1 , V_20 , V_77 , V_95 ) ;
if ( F_6 ( V_1 , V_20 , V_77 , V_95 , true ) ) {
F_27 ( & V_1 -> V_85 -> V_86 , L_3 ) ;
return - 1 ;
}
V_33 = F_1 ( V_1 , V_20 , V_34 ) ;
V_33 &= ~ V_51 ;
F_3 ( V_1 , V_20 , V_34 , V_33 ) ;
F_5 ( V_1 , V_20 , V_77 , V_96 ) ;
if ( V_2 -> V_25 == V_97 )
F_5 ( V_1 , V_20 , V_98 ,
V_99 ) ;
V_33 = F_1 ( V_1 , V_20 , V_98 ) ;
V_33 &= ~ V_100 ;
F_3 ( V_1 , V_20 , V_98 , V_33 ) ;
V_33 = F_1 ( V_1 , V_20 , V_101 ) ;
F_3 ( V_1 , V_20 , V_101 , V_33 ) ;
V_33 = F_1 ( V_1 , V_20 , V_102 ) ;
F_3 ( V_1 , V_20 , V_102 , V_33 ) ;
V_33 = F_1 ( V_1 , V_20 , V_103 ) ;
F_3 ( V_1 , V_20 , V_103 , V_33 ) ;
if ( V_2 -> V_104 ) {
F_3 ( V_1 , V_20 , V_105 , 0x00 ) ;
F_3 ( V_1 , V_20 , V_106 , 0x00 ) ;
F_3 ( V_1 , V_20 , V_107 , 0x00 ) ;
F_5 ( V_1 , V_20 ,
V_108 , V_109 ) ;
}
F_5 ( V_1 , V_20 , V_110 , V_111 ) ;
V_33 = F_1 ( V_1 , V_20 , V_112 ) ;
V_33 &= ~ V_113 ;
F_3 ( V_1 , V_20 , V_112 , V_33 ) ;
V_33 = F_1 ( V_1 , V_20 , V_114 ) ;
V_33 = V_33 & ~ ( V_115 | V_116 ) ;
F_3 ( V_1 , V_20 , V_114 , V_33 ) ;
V_33 = F_1 ( V_1 , V_20 , V_117 ) ;
if ( V_2 -> V_25 == V_118 )
V_33 |= ( 1 << 23 ) ;
else if ( V_2 -> V_25 == V_119 )
V_33 |= ( 1 << 24 ) ;
else
V_33 &= ~ ( ( 1 << 23 ) | ( 1 << 24 ) ) ;
V_33 = V_33 & ( ~ ( ( 1ULL << 25 ) | ( 1ULL << 22 ) | ( 1ULL << 12 ) ) ) ;
F_3 ( V_1 , V_20 , V_117 , V_33 ) ;
V_33 = F_1 ( V_1 , 0 , V_120 ) ;
V_33 &= ~ V_121 ;
F_3 ( V_1 , 0 , V_120 , V_33 ) ;
F_5 ( V_1 , V_20 , V_34 , V_51 ) ;
V_33 = F_1 ( V_1 , V_20 , V_77 ) ;
V_33 &= ~ V_96 ;
F_3 ( V_1 , V_20 , V_77 , V_33 ) ;
V_33 = F_1 ( V_1 , V_20 , V_122 ) ;
V_33 &= ~ V_123 ;
V_33 |= V_124 ;
F_3 ( V_1 , V_20 , V_122 , V_33 ) ;
F_3 ( V_1 , V_20 , V_42 , ( ( 0xffffULL << 32 ) |
V_125 | V_126 | V_46 | V_44 ) ) ;
F_3 ( V_1 , V_20 ,
V_127 , V_128 ) ;
V_33 = F_1 ( V_1 , V_20 , V_129 ) ;
V_33 &= ~ 0xFFFFull ;
F_3 ( V_1 , V_20 , V_129 ,
V_33 | ( V_128 - 0x1000 ) ) ;
F_3 ( V_1 , V_20 , V_130 , 0x01 ) ;
F_5 ( V_1 , V_20 , V_131 , ( 0x100 - 1 ) ) ;
F_5 ( V_1 , V_20 , V_132 , V_81 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
int V_20 = V_2 -> V_20 ;
int V_25 = V_2 -> V_25 ;
T_1 V_33 ;
if ( V_2 -> V_104 ) {
V_33 = F_1 ( V_1 , V_20 , V_103 ) ;
if ( ! ( V_33 & ( 1ull << 13 ) ) ) {
V_33 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_20 , V_103 , V_33 ) ;
V_33 = F_1 ( V_1 , V_20 , V_108 ) ;
V_33 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_20 , V_108 , V_33 ) ;
return - 1 ;
}
}
if ( F_6 ( V_1 , V_20 , V_77 , V_95 , true ) ) {
F_27 ( & V_1 -> V_85 -> V_86 , L_3 ) ;
return - 1 ;
}
if ( ( V_25 == V_118 ) || ( V_25 == V_133 ) ||
( V_25 == V_119 ) || ( V_25 == V_134 ) ) {
if ( F_6 ( V_1 , V_20 , V_135 ,
V_136 , false ) ) {
F_27 ( & V_1 -> V_85 -> V_86 ,
L_4 ) ;
return - 1 ;
}
} else {
if ( F_6 ( V_1 , V_20 , V_137 ,
V_138 , false ) ) {
F_27 ( & V_1 -> V_85 -> V_86 ,
L_5 ) ;
return - 1 ;
}
}
if ( F_1 ( V_1 , V_20 , V_139 ) & V_140 )
F_5 ( V_1 , V_20 ,
V_139 , V_140 ) ;
if ( F_1 ( V_1 , V_20 , V_139 ) & V_140 ) {
F_27 ( & V_1 -> V_85 -> V_86 , L_6 ) ;
if ( V_2 -> V_104 ) {
V_33 = F_1 ( V_1 , V_20 , V_103 ) ;
if ( ! ( V_33 & ( 1ull << 13 ) ) ) {
V_33 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_20 , V_103 , V_33 ) ;
V_33 = F_1 ( V_1 , V_20 ,
V_108 ) ;
V_33 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_20 ,
V_108 , V_33 ) ;
return - 1 ;
}
}
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_141 , V_142 , false ) ) {
F_27 ( & V_1 -> V_85 -> V_86 , L_7 ) ;
return - 1 ;
}
if ( F_6 ( V_1 , V_20 , V_141 , V_143 , false ) ) {
F_27 ( & V_1 -> V_85 -> V_86 , L_8 ) ;
return - 1 ;
}
V_33 = F_1 ( V_1 , V_20 , V_144 ) ;
V_33 &= V_145 ;
if ( ! V_33 )
return 0 ;
F_28 ( V_1 , V_2 ) ;
return - 1 ;
}
static void F_29 ( struct V_2 * V_2 )
{
T_1 V_146 , V_147 ;
T_2 V_29 ;
V_146 = F_1 ( V_2 -> V_1 , V_2 -> V_20 ,
V_93 ) ;
if ( ! ( V_146 & V_148 ) )
V_146 = F_1 ( V_2 -> V_1 , V_2 -> V_20 ,
V_93 ) ;
if ( F_6 ( V_2 -> V_1 , V_2 -> V_20 , V_93 ,
V_94 , false ) ) {
V_2 -> V_26 = false ;
V_2 -> V_30 = V_149 ;
V_2 -> V_28 = V_150 ;
goto V_151;
}
V_2 -> V_26 = ( ( V_146 & V_148 ) != 0 ) ? true : false ;
V_147 = F_1 ( V_2 -> V_1 , V_2 -> V_20 ,
V_152 ) ;
V_29 = ( V_147 >> 3 ) & 0x3 ;
V_2 -> V_28 = ( V_147 >> 1 ) & 0x1 ;
switch ( V_29 ) {
case 0 :
V_2 -> V_30 = 10 ;
break;
case 1 :
V_2 -> V_30 = 100 ;
break;
case 2 :
V_2 -> V_30 = 1000 ;
break;
default:
V_2 -> V_26 = false ;
V_2 -> V_30 = V_149 ;
V_2 -> V_28 = V_150 ;
break;
}
V_151:
if ( V_2 -> V_67 != V_2 -> V_26 ) {
if ( V_2 -> V_26 )
F_18 ( V_2 ) ;
V_2 -> V_67 = V_2 -> V_26 ;
}
F_30 ( V_2 -> V_153 , & V_2 -> V_154 , V_155 * 3 ) ;
}
static void F_31 ( struct V_156 * V_157 )
{
struct V_2 * V_2 ;
T_1 V_158 , V_159 ;
V_2 = F_20 ( V_157 , struct V_2 , V_154 . V_157 ) ;
if ( V_2 -> V_41 ) {
F_29 ( V_2 ) ;
return;
}
F_5 ( V_2 -> V_1 , V_2 -> V_20 ,
V_160 , V_161 ) ;
F_6 ( V_2 -> V_1 , V_2 -> V_20 , V_160 ,
V_161 , false ) ;
V_158 = F_1 ( V_2 -> V_1 , V_2 -> V_20 , V_160 ) ;
V_159 = F_1 ( V_2 -> V_1 , V_2 -> V_20 , V_144 ) ;
if ( ( V_158 & V_161 ) &&
! ( V_159 & V_145 ) ) {
V_2 -> V_26 = 1 ;
if ( V_2 -> V_25 == V_134 )
V_2 -> V_30 = 40000 ;
else
V_2 -> V_30 = 10000 ;
V_2 -> V_28 = 1 ;
} else {
V_2 -> V_26 = 0 ;
V_2 -> V_30 = V_149 ;
V_2 -> V_28 = V_150 ;
}
if ( V_2 -> V_67 != V_2 -> V_26 ) {
if ( V_2 -> V_26 ) {
if ( F_21 ( V_2 ) ) {
V_2 -> V_26 = 0 ;
V_2 -> V_30 = V_149 ;
V_2 -> V_28 = V_150 ;
}
}
V_2 -> V_67 = V_2 -> V_26 ;
}
F_30 ( V_2 -> V_153 , & V_2 -> V_154 , V_155 * 2 ) ;
}
static int F_32 ( T_2 V_25 )
{
if ( V_25 == V_90 )
return V_162 ;
if ( V_25 == V_163 )
return V_164 ;
return V_165 ;
}
static int F_33 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_33 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_2 -> V_1 = V_1 ;
if ( ( V_2 -> V_25 == V_92 ) ||
( V_2 -> V_25 == V_90 ) ||
( V_2 -> V_25 == V_163 ) ) {
V_2 -> V_41 = 1 ;
if ( F_26 ( V_1 , V_2 ) )
return - 1 ;
} else {
V_2 -> V_41 = 0 ;
if ( F_28 ( V_1 , V_2 ) )
return - 1 ;
}
if ( V_2 -> V_41 ) {
V_33 = F_1 ( V_1 , V_20 , V_82 ) ;
V_33 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_20 , V_82 , V_33 ) ;
F_3 ( V_1 , V_20 , V_166 , 60 - 1 ) ;
} else {
V_33 = F_1 ( V_1 , V_20 , V_110 ) ;
V_33 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_20 , V_110 , V_33 ) ;
F_3 ( V_1 , V_20 , V_167 , 60 + 4 ) ;
}
F_5 ( V_1 , V_20 , V_34 , V_51 ) ;
F_3 ( V_1 , V_20 , V_168 , 0x03 ) ;
if ( ( V_2 -> V_25 != V_133 ) &&
( V_2 -> V_25 != V_134 ) &&
( V_2 -> V_25 != V_119 ) &&
( V_2 -> V_25 != V_118 ) ) {
if ( ! V_2 -> V_65 ) {
if ( V_2 -> V_47 ) {
F_3 ( V_1 , V_20 ,
V_169 ,
V_170 ) ;
goto V_171;
} else {
V_2 -> V_26 = true ;
V_2 -> V_30 = 1000 ;
V_2 -> V_28 = 1 ;
F_18 ( V_2 ) ;
return 0 ;
}
}
V_2 -> V_65 -> V_172 = 0 ;
if ( F_34 ( & V_2 -> V_63 , V_2 -> V_65 ,
F_19 ,
F_32 ( V_2 -> V_25 ) ) )
return - V_173 ;
F_35 ( V_2 -> V_65 ) ;
return 0 ;
}
V_171:
V_2 -> V_153 = F_36 ( L_9 , V_174 |
V_175 , 1 ) ;
if ( ! V_2 -> V_153 )
return - V_176 ;
F_37 ( & V_2 -> V_154 , F_31 ) ;
F_30 ( V_2 -> V_153 , & V_2 -> V_154 , 0 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_2 * V_2 ;
T_1 V_33 ;
V_2 = & V_1 -> V_2 [ V_20 ] ;
if ( V_2 -> V_153 ) {
F_39 ( & V_2 -> V_154 ) ;
F_40 ( V_2 -> V_153 ) ;
}
V_33 = F_1 ( V_1 , V_20 , V_34 ) ;
V_33 &= ~ V_35 ;
F_3 ( V_1 , V_20 , V_34 , V_33 ) ;
F_6 ( V_1 , V_20 , V_177 , ( T_1 ) 0x1FFF , true ) ;
F_6 ( V_1 , V_20 , V_178 , ( T_1 ) 0x3FFF , true ) ;
V_33 = F_1 ( V_1 , V_20 , V_34 ) ;
V_33 &= ~ V_36 ;
F_3 ( V_1 , V_20 , V_34 , V_33 ) ;
if ( ! V_2 -> V_41 )
F_5 ( V_1 , V_20 ,
V_77 , V_96 ) ;
else
F_5 ( V_1 , V_20 ,
V_75 , V_87 ) ;
V_33 = F_1 ( V_1 , V_20 , V_34 ) ;
V_33 &= ~ V_51 ;
F_3 ( V_1 , V_20 , V_34 , V_33 ) ;
F_24 ( V_1 , V_20 ) ;
if ( ( V_2 -> V_25 != V_133 ) &&
( V_2 -> V_25 != V_134 ) &&
( V_2 -> V_25 != V_119 ) &&
( V_2 -> V_25 != V_118 ) && V_2 -> V_65 )
F_41 ( V_2 -> V_65 ) ;
V_2 -> V_65 = NULL ;
}
static void F_42 ( struct V_1 * V_1 )
{
int V_14 ;
struct V_2 * V_2 ;
F_5 ( V_1 , 0 , V_179 , V_180 ) ;
if ( F_1 ( V_1 , 0 , V_181 ) )
F_27 ( & V_1 -> V_85 -> V_86 , L_10 , V_1 -> V_182 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ ) {
V_2 = & V_1 -> V_2 [ V_14 ] ;
F_3 ( V_1 , V_14 , V_34 ,
( V_2 -> V_25 << 8 ) | V_2 -> V_183 ) ;
V_1 -> V_2 [ V_14 ] . V_184 = V_19 ;
V_19 ++ ;
}
F_3 ( V_1 , 0 , V_185 , V_1 -> V_19 ) ;
F_3 ( V_1 , 0 , V_186 , V_1 -> V_19 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_19 ; V_14 ++ )
F_5 ( V_1 , 0 , V_187 ,
( ( 1ULL << V_188 ) - 1 ) <<
( V_14 * V_188 ) ) ;
for ( V_14 = 0 ; V_14 < V_189 ; V_14 ++ )
F_3 ( V_1 , 0 , V_73 + ( V_14 * 8 ) , 0x00 ) ;
for ( V_14 = 0 ; V_14 < V_190 ; V_14 ++ )
F_3 ( V_1 , 0 , V_191 + ( V_14 * 8 ) , 0x00 ) ;
}
static T_2 F_43 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return ( T_2 ) ( F_1 ( V_1 , V_2 -> V_20 , V_34 ) & 0xFF ) ;
}
static void F_44 ( struct V_1 * V_1 , T_2 V_20 )
{
struct V_192 * V_86 = & V_1 -> V_85 -> V_86 ;
struct V_2 * V_2 ;
char V_193 [ 20 ] ;
T_2 V_194 ;
if ( V_20 > V_1 -> V_195 )
return;
V_2 = & V_1 -> V_2 [ V_20 ] ;
V_194 = ( V_20 / 2 ) + ( V_1 -> V_182 * 2 ) ;
if ( ! V_1 -> V_196 )
sprintf ( V_193 , L_11 , V_1 -> V_182 ) ;
else
sprintf ( V_193 , L_12 , V_1 -> V_182 , V_194 ) ;
switch ( V_2 -> V_25 ) {
case V_92 :
F_45 ( V_86 , L_13 , ( char * ) V_193 ) ;
break;
case V_197 :
F_45 ( V_86 , L_14 , ( char * ) V_193 ) ;
break;
case V_97 :
F_45 ( V_86 , L_15 , ( char * ) V_193 ) ;
break;
case V_133 :
if ( ! V_2 -> V_104 )
F_45 ( V_86 , L_16 , ( char * ) V_193 ) ;
else
F_45 ( V_86 , L_17 , ( char * ) V_193 ) ;
break;
case V_134 :
if ( ! V_2 -> V_104 )
F_45 ( V_86 , L_18 , ( char * ) V_193 ) ;
else
F_45 ( V_86 , L_19 , ( char * ) V_193 ) ;
break;
case V_90 :
if ( ( V_20 == 0 ) &&
( F_43 ( V_1 , V_2 ) != V_20 ) )
return;
if ( ( V_20 == 2 ) &&
( F_43 ( V_1 , V_2 ) == V_20 ) )
return;
F_45 ( V_86 , L_20 , ( char * ) V_193 ) ;
break;
case V_163 :
F_45 ( V_86 , L_21 , ( char * ) V_193 ) ;
break;
case V_198 :
break;
}
}
static void F_46 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
switch ( V_2 -> V_25 ) {
case V_92 :
case V_133 :
V_2 -> V_183 = V_2 -> V_20 ;
break;
case V_197 :
case V_134 :
case V_163 :
V_2 -> V_183 = 0xE4 ;
break;
case V_97 :
V_2 -> V_183 = ( V_2 -> V_20 ) ? 0xE : 0x4 ;
break;
case V_90 :
V_2 -> V_183 = F_43 ( V_1 , V_2 ) ;
break;
default:
V_2 -> V_183 = 0 ;
break;
}
}
static void F_47 ( struct V_1 * V_1 , struct V_2 * V_2 , int V_20 )
{
if ( ( V_2 -> V_25 != V_118 ) &&
( V_2 -> V_25 != V_119 ) ) {
V_2 -> V_104 = 0 ;
return;
}
V_2 -> V_104 = F_1 ( V_1 , V_20 , V_108 ) &
V_109 ;
}
static void F_48 ( struct V_1 * V_1 , T_2 V_68 )
{
struct V_2 * V_2 ;
struct V_2 * V_199 ;
T_1 V_48 ;
T_2 V_25 ;
T_2 V_183 ;
V_2 = & V_1 -> V_2 [ V_68 ] ;
if ( ! V_1 -> V_196 || V_1 -> V_37 ) {
V_48 = F_1 ( V_1 , 0 , V_34 ) ;
V_2 -> V_25 = ( V_48 >> 8 ) & 0x07 ;
if ( V_1 -> V_37 )
V_2 -> V_25 = V_163 ;
F_47 ( V_1 , V_2 , 0 ) ;
F_46 ( V_1 , V_2 ) ;
return;
}
if ( ( V_68 == 0 ) || ( V_68 == 2 ) ) {
V_48 = F_1 ( V_1 , V_68 , V_34 ) ;
V_25 = ( T_2 ) ( ( V_48 >> 8 ) & 0x07 ) ;
V_183 = ( T_2 ) ( V_48 & 0xFF ) ;
if ( ( V_25 == 0 ) && ( V_183 == 0xE4 ) )
V_2 -> V_25 = V_198 ;
else
V_2 -> V_25 = V_25 ;
F_47 ( V_1 , V_2 , V_2 -> V_20 ) ;
F_46 ( V_1 , V_2 ) ;
V_199 = & V_1 -> V_2 [ V_68 + 1 ] ;
V_48 = F_1 ( V_1 , V_68 + 1 , V_34 ) ;
V_25 = ( T_2 ) ( ( V_48 >> 8 ) & 0x07 ) ;
V_183 = ( T_2 ) ( V_48 & 0xFF ) ;
if ( ( V_25 == 0 ) && ( V_183 == 0xE4 ) ) {
V_199 -> V_25 = V_2 -> V_25 ;
F_46 ( V_1 , V_199 ) ;
} else {
V_199 -> V_25 = V_25 ;
V_199 -> V_183 = V_183 ;
}
F_47 ( V_1 , V_199 , V_199 -> V_20 ) ;
}
}
static bool F_49 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
if ( ! V_1 -> V_196 )
return true ;
V_2 = & V_1 -> V_2 [ 0 ] ;
if ( V_2 -> V_25 == V_198 )
return false ;
return true ;
}
static void F_50 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
struct V_2 * V_200 ;
struct V_2 * V_201 ;
T_2 V_68 ;
for ( V_68 = 0 ; V_68 < V_1 -> V_195 ; V_68 ++ ) {
V_2 = & V_1 -> V_2 [ V_68 ] ;
V_2 -> V_20 = V_68 ;
V_2 -> V_25 = V_198 ;
V_2 -> V_104 = false ;
}
V_1 -> V_19 = F_1 ( V_1 , 0 , V_186 ) & 0x7 ;
if ( V_1 -> V_19 > V_1 -> V_195 )
V_1 -> V_19 = V_1 -> V_195 ;
for ( V_68 = 0 ; V_68 < V_1 -> V_195 ; V_68 ++ )
F_48 ( V_1 , V_68 ) ;
if ( ! V_1 -> V_196 || V_1 -> V_37 ) {
F_44 ( V_1 , 0 ) ;
return;
}
if ( V_1 -> V_19 ) {
F_44 ( V_1 , 0 ) ;
F_44 ( V_1 , 2 ) ;
}
if ( F_49 ( V_1 ) || ( V_1 -> V_19 > 2 ) )
return;
for ( V_68 = 0 ; V_68 < V_1 -> V_19 ; V_68 ++ ) {
V_200 = & V_1 -> V_2 [ V_68 ] ;
V_201 = & V_1 -> V_2 [ V_68 + 2 ] ;
V_200 -> V_25 = V_201 -> V_25 ;
V_200 -> V_183 = V_201 -> V_183 ;
}
}
static int F_51 ( struct V_192 * V_86 , struct V_202 * V_203 ,
T_2 * V_204 )
{
T_2 V_31 [ V_205 ] ;
int V_206 ;
V_206 = F_52 ( F_53 ( V_203 ) ,
L_22 , V_31 , V_205 ) ;
if ( V_206 )
goto V_207;
if ( ! F_54 ( V_31 ) ) {
F_27 ( V_86 , L_23 , V_31 ) ;
V_206 = - V_208 ;
goto V_207;
}
F_45 ( V_86 , L_24 , V_31 ) ;
memcpy ( V_204 , V_31 , V_205 ) ;
V_207:
return V_206 ;
}
static T_4 F_55 ( T_5 V_209 ,
V_6 V_210 , void * V_211 , void * * V_212 )
{
struct V_1 * V_1 = V_211 ;
struct V_192 * V_86 = & V_1 -> V_85 -> V_86 ;
struct V_202 * V_203 ;
if ( F_56 ( V_209 , & V_203 ) )
goto V_207;
F_51 ( V_86 , V_203 , V_1 -> V_2 [ V_1 -> V_213 ] . V_31 ) ;
F_57 ( & V_1 -> V_2 [ V_1 -> V_213 ] . V_63 , V_86 ) ;
V_1 -> V_2 [ V_1 -> V_213 ] . V_20 = V_1 -> V_213 ;
V_1 -> V_213 ++ ;
V_207:
return V_214 ;
}
static T_4 F_58 ( T_5 V_209 , V_6 V_210 ,
void * V_211 , void * * V_215 )
{
struct V_216 string = { V_217 , NULL } ;
struct V_1 * V_1 = V_211 ;
char V_218 [ 5 ] ;
snprintf ( V_218 , 5 , L_25 , V_1 -> V_182 ) ;
if ( F_59 ( F_60 ( V_209 , V_219 , & string ) ) ) {
F_61 ( L_26 ) ;
return V_214 ;
}
if ( strncmp ( string . V_220 , V_218 , 4 ) )
return V_214 ;
F_62 ( V_221 , V_209 , 1 ,
F_55 , NULL , V_1 , NULL ) ;
F_63 ( string . V_220 ) ;
return V_222 ;
}
static int F_64 ( struct V_1 * V_1 )
{
F_65 ( NULL , F_58 , V_1 , ( void * * ) NULL ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_1 )
{
return - V_173 ;
}
static int F_66 ( struct V_1 * V_1 )
{
struct V_223 * V_224 ;
struct V_225 * V_13 = NULL ;
T_2 V_2 = 0 ;
F_67 (&bgx->pdev->dev, fwn) {
struct V_64 * V_226 ;
struct V_225 * V_227 ;
const char * V_31 ;
V_13 = F_68 ( V_224 ) ;
if ( ! V_13 )
break;
V_31 = F_69 ( V_13 ) ;
if ( V_31 )
F_13 ( V_1 -> V_2 [ V_2 ] . V_31 , V_31 ) ;
F_57 ( & V_1 -> V_2 [ V_2 ] . V_63 , & V_1 -> V_85 -> V_86 ) ;
V_1 -> V_2 [ V_2 ] . V_20 = V_2 ;
V_227 = F_70 ( V_13 , L_27 , 0 ) ;
if ( V_227 &&
! F_71 ( V_227 , L_28 ) ) {
V_226 = F_72 ( V_227 ) ;
if ( ! V_226 )
goto V_228;
V_1 -> V_2 [ V_2 ] . V_65 = V_226 ;
}
V_2 ++ ;
if ( V_2 == V_1 -> V_195 ) {
F_73 ( V_13 ) ;
break;
}
}
return 0 ;
V_228:
while ( V_2 ) {
if ( V_1 -> V_2 [ V_2 ] . V_65 ) {
F_74 ( & V_1 -> V_2 [ V_2 ] . V_65 -> V_229 . V_86 ) ;
V_1 -> V_2 [ V_2 ] . V_65 = NULL ;
}
V_2 -- ;
}
F_73 ( V_13 ) ;
return - V_230 ;
}
static int F_66 ( struct V_1 * V_1 )
{
return - V_173 ;
}
static int F_75 ( struct V_1 * V_1 )
{
if ( ! V_231 )
return F_64 ( V_1 ) ;
return F_66 ( V_1 ) ;
}
static int F_76 ( struct V_232 * V_85 , const struct V_233 * V_234 )
{
int V_235 ;
struct V_192 * V_86 = & V_85 -> V_86 ;
struct V_1 * V_1 = NULL ;
T_2 V_2 ;
T_6 V_236 ;
V_1 = F_77 ( V_86 , sizeof( * V_1 ) , V_237 ) ;
if ( ! V_1 )
return - V_176 ;
V_1 -> V_85 = V_85 ;
F_78 ( V_85 , V_1 ) ;
V_235 = F_79 ( V_85 ) ;
if ( V_235 ) {
F_27 ( V_86 , L_29 ) ;
F_78 ( V_85 , NULL ) ;
return V_235 ;
}
V_235 = F_80 ( V_85 , V_238 ) ;
if ( V_235 ) {
F_27 ( V_86 , L_30 , V_235 ) ;
goto V_239;
}
V_1 -> V_5 = F_81 ( V_85 , V_240 , 0 ) ;
if ( ! V_1 -> V_5 ) {
F_27 ( V_86 , L_31 ) ;
V_235 = - V_176 ;
goto V_241;
}
F_82 ( V_85 , V_242 , & V_236 ) ;
if ( V_236 != V_243 ) {
V_1 -> V_182 = ( F_83 ( V_85 ,
V_240 ) >> 24 ) & V_244 ;
V_1 -> V_182 += F_84 ( V_85 ) * V_16 ;
V_1 -> V_195 = V_245 ;
V_17 [ V_1 -> V_182 ] = V_1 ;
} else {
V_1 -> V_37 = true ;
V_1 -> V_195 = 1 ;
V_1 -> V_182 = V_246 - 1 ;
V_17 [ V_1 -> V_182 ] = V_1 ;
F_85 () ;
}
F_82 ( V_85 , V_247 , & V_236 ) ;
if ( ( V_236 == V_248 ) ||
( ( V_236 == V_249 ) && ( V_1 -> V_182 == 2 ) ) )
V_1 -> V_196 = true ;
F_50 ( V_1 ) ;
V_235 = F_75 ( V_1 ) ;
if ( V_235 )
goto V_250;
F_42 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ ) {
V_235 = F_33 ( V_1 , V_2 ) ;
if ( V_235 ) {
F_27 ( V_86 , L_32 ,
V_1 -> V_182 , V_2 ) ;
while ( V_2 )
F_38 ( V_1 , -- V_2 ) ;
goto V_250;
}
}
return 0 ;
V_250:
V_17 [ V_1 -> V_182 ] = NULL ;
V_241:
F_86 ( V_85 ) ;
V_239:
F_87 ( V_85 ) ;
F_78 ( V_85 , NULL ) ;
return V_235 ;
}
static void F_88 ( struct V_232 * V_85 )
{
struct V_1 * V_1 = F_89 ( V_85 ) ;
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_19 ; V_2 ++ )
F_38 ( V_1 , V_2 ) ;
V_17 [ V_1 -> V_182 ] = NULL ;
F_86 ( V_85 ) ;
F_87 ( V_85 ) ;
F_78 ( V_85 , NULL ) ;
}
static int T_7 F_90 ( void )
{
F_91 ( L_33 , V_238 , V_251 ) ;
return F_92 ( & V_252 ) ;
}
static void T_8 F_93 ( void )
{
F_94 ( & V_252 ) ;
}
