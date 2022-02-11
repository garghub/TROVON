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
V_59 = F_1 ( V_1 , V_2 -> V_32 , V_46 ) ;
V_59 &= ~ V_62 ;
F_3 ( V_1 , V_2 -> V_32 , V_46 , V_59 ) ;
V_60 = F_1 ( V_1 , V_2 -> V_32 , V_63 ) ;
V_61 = F_1 ( V_1 , V_2 -> V_32 , V_64 ) ;
if ( V_2 -> V_38 ) {
V_61 &= ~ V_65 ;
V_60 &= ~ V_66 ;
V_60 |= ( V_2 -> V_40 << 2 ) ;
} else {
V_61 |= V_65 ;
}
switch ( V_2 -> V_42 ) {
case 10 :
V_60 &= ~ V_67 ;
V_60 |= V_68 ;
V_60 &= ~ V_69 ;
V_61 &= ~ V_70 ;
V_61 |= 50 ;
F_3 ( V_1 , V_2 -> V_32 , V_71 , 64 ) ;
F_3 ( V_1 , V_2 -> V_32 , V_72 , 0 ) ;
break;
case 100 :
V_60 &= ~ V_67 ;
V_60 &= ~ V_68 ;
V_60 &= ~ V_69 ;
V_61 &= ~ V_70 ;
V_61 |= 5 ;
F_3 ( V_1 , V_2 -> V_32 , V_71 , 64 ) ;
F_3 ( V_1 , V_2 -> V_32 , V_72 , 0 ) ;
break;
case 1000 :
V_60 |= V_67 ;
V_60 &= ~ V_68 ;
V_60 |= V_69 ;
V_61 &= ~ V_70 ;
V_61 |= 1 ;
F_3 ( V_1 , V_2 -> V_32 , V_71 , 512 ) ;
if ( V_2 -> V_40 )
F_3 ( V_1 , V_2 -> V_32 ,
V_72 , 0 ) ;
else
F_3 ( V_1 , V_2 -> V_32 ,
V_72 , 8192 ) ;
break;
default:
break;
}
F_3 ( V_1 , V_2 -> V_32 , V_64 , V_61 ) ;
F_3 ( V_1 , V_2 -> V_32 , V_63 , V_60 ) ;
V_60 = F_1 ( V_1 , V_2 -> V_32 , V_63 ) ;
V_59 |= V_62 ;
F_3 ( V_1 , V_2 -> V_32 , V_46 , V_59 ) ;
if ( V_1 -> V_49 && ( V_59 & ( V_47 | V_48 ) ) )
F_18 ( V_2 -> V_38 , V_2 -> V_42 ) ;
}
static void F_22 ( struct V_73 * V_74 )
{
struct V_2 * V_2 = F_23 ( V_74 , struct V_2 , V_74 ) ;
struct V_75 * V_76 ;
int V_77 = 0 ;
if ( ! V_2 )
return;
V_76 = V_2 -> V_76 ;
if ( ! V_76 -> V_35 && V_2 -> V_78 )
V_77 = - 1 ;
if ( V_76 -> V_35 &&
( V_2 -> V_40 != V_76 -> V_39 ||
V_2 -> V_78 != V_76 -> V_35 ||
V_2 -> V_42 != V_76 -> V_41 ) ) {
V_77 = 1 ;
}
V_2 -> V_78 = V_76 -> V_35 ;
V_2 -> V_42 = V_76 -> V_41 ;
V_2 -> V_40 = V_76 -> V_39 ;
if ( ! V_77 )
return;
if ( V_77 > 0 )
V_2 -> V_38 = true ;
else
V_2 -> V_38 = false ;
if ( V_2 -> V_52 )
F_21 ( V_2 ) ;
else
F_24 ( V_2 ) ;
}
T_1 F_25 ( int V_25 , int V_26 , int V_2 , int V_27 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_25 , V_26 ) ;
if ( ! V_1 )
return 0 ;
if ( V_27 > 8 )
V_2 = 0 ;
return F_1 ( V_1 , V_2 , V_79 + ( V_27 * 8 ) ) ;
}
T_1 F_26 ( int V_25 , int V_26 , int V_2 , int V_27 )
{
struct V_1 * V_1 ;
V_1 = F_10 ( V_25 , V_26 ) ;
if ( ! V_1 )
return 0 ;
return F_1 ( V_1 , V_2 , V_80 + ( V_27 * 8 ) ) ;
}
static void F_27 ( struct V_1 * V_1 , int V_2 )
{
T_1 V_3 ;
while ( V_1 -> V_2 [ V_2 ] . V_81 > 0 ) {
V_3 = ( ( V_1 -> V_2 [ V_2 ] . V_81 - 1 ) * sizeof( T_1 ) ) +
( V_2 * V_82 * sizeof( T_1 ) ) ;
F_3 ( V_1 , 0 , V_83 + V_3 , 0 ) ;
V_1 -> V_2 [ V_2 ] . V_81 -- ;
}
}
void F_28 ( int V_25 , int V_26 ,
int V_84 , bool V_44 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
T_1 V_45 ;
V_1 = F_10 ( V_25 , V_26 ) ;
if ( ! V_1 )
return;
V_2 = & V_1 -> V_2 [ V_84 ] ;
if ( V_2 -> V_52 ) {
V_45 = F_1 ( V_1 , V_84 , V_85 ) ;
if ( V_44 )
V_45 |= V_86 ;
else
V_45 &= ~ V_86 ;
F_3 ( V_1 , V_84 , V_85 , V_45 ) ;
} else {
V_45 = F_1 ( V_1 , V_84 , V_87 ) ;
if ( V_44 )
V_45 |= V_88 ;
else
V_45 &= ~ V_88 ;
F_3 ( V_1 , V_84 , V_87 , V_45 ) ;
}
}
static int F_29 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_32 = V_2 -> V_32 ;
T_1 V_45 ;
F_5 ( V_1 , V_32 , V_89 , 0x30 ) ;
F_5 ( V_1 , V_32 , V_90 , V_91 ) ;
V_45 = F_1 ( V_1 , V_32 , V_92 ) ;
if ( V_45 & 1 )
F_3 ( V_1 , V_32 , V_93 , 0 ) ;
F_5 ( V_1 , V_32 , V_46 , V_62 ) ;
F_5 ( V_1 , V_32 , V_85 , V_94 ) ;
if ( F_6 ( V_1 , V_32 , V_85 ,
V_94 , true ) ) {
F_30 ( & V_1 -> V_14 -> V_95 , L_1 ) ;
return - 1 ;
}
V_45 = F_1 ( V_1 , V_32 , V_85 ) ;
V_45 &= ~ V_96 ;
V_45 |= V_97 ;
if ( V_2 -> V_76 ) {
V_45 |= V_98 ;
} else {
if ( V_45 & V_98 )
V_2 -> V_58 = true ;
}
F_3 ( V_1 , V_32 , V_85 , V_45 ) ;
if ( V_2 -> V_37 == V_99 ) {
V_45 = F_1 ( V_1 , V_32 , V_64 ) ;
V_45 &= ~ V_100 ;
F_3 ( V_1 , V_32 , V_64 , V_45 ) ;
return 0 ;
}
if ( ( V_2 -> V_37 == V_101 ) && V_2 -> V_76 ) {
if ( F_6 ( V_1 , V_32 , V_102 ,
V_103 , false ) ) {
F_30 ( & V_1 -> V_14 -> V_95 , L_2 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
T_1 V_45 ;
int V_32 = V_2 -> V_32 ;
F_5 ( V_1 , V_32 , V_87 , V_104 ) ;
if ( F_6 ( V_1 , V_32 , V_87 , V_104 , true ) ) {
F_30 ( & V_1 -> V_14 -> V_95 , L_3 ) ;
return - 1 ;
}
V_45 = F_1 ( V_1 , V_32 , V_46 ) ;
V_45 &= ~ V_62 ;
F_3 ( V_1 , V_32 , V_46 , V_45 ) ;
F_5 ( V_1 , V_32 , V_87 , V_105 ) ;
if ( V_2 -> V_37 == V_106 )
F_5 ( V_1 , V_32 , V_107 ,
V_108 ) ;
V_45 = F_1 ( V_1 , V_32 , V_107 ) ;
V_45 &= ~ V_109 ;
F_3 ( V_1 , V_32 , V_107 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_110 ) ;
F_3 ( V_1 , V_32 , V_110 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_111 ) ;
F_3 ( V_1 , V_32 , V_111 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_112 ) ;
F_3 ( V_1 , V_32 , V_112 , V_45 ) ;
if ( V_2 -> V_113 ) {
F_3 ( V_1 , V_32 , V_114 , 0x00 ) ;
F_3 ( V_1 , V_32 , V_115 , 0x00 ) ;
F_3 ( V_1 , V_32 , V_116 , 0x00 ) ;
F_5 ( V_1 , V_32 ,
V_117 , V_118 ) ;
}
F_5 ( V_1 , V_32 , V_119 , V_120 ) ;
V_45 = F_1 ( V_1 , V_32 , V_121 ) ;
V_45 &= ~ V_122 ;
F_3 ( V_1 , V_32 , V_121 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_123 ) ;
V_45 = V_45 & ~ ( V_124 | V_125 ) ;
F_3 ( V_1 , V_32 , V_123 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_126 ) ;
if ( V_2 -> V_37 == V_127 )
V_45 |= ( 1 << 23 ) ;
else if ( V_2 -> V_37 == V_128 )
V_45 |= ( 1 << 24 ) ;
else
V_45 &= ~ ( ( 1 << 23 ) | ( 1 << 24 ) ) ;
V_45 = V_45 & ( ~ ( ( 1ULL << 25 ) | ( 1ULL << 22 ) | ( 1ULL << 12 ) ) ) ;
F_3 ( V_1 , V_32 , V_126 , V_45 ) ;
V_45 = F_1 ( V_1 , 0 , V_129 ) ;
V_45 &= ~ V_130 ;
F_3 ( V_1 , 0 , V_129 , V_45 ) ;
F_5 ( V_1 , V_32 , V_46 , V_62 ) ;
V_45 = F_1 ( V_1 , V_32 , V_87 ) ;
V_45 &= ~ V_105 ;
F_3 ( V_1 , V_32 , V_87 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_131 ) ;
V_45 &= ~ V_132 ;
V_45 |= V_133 ;
F_3 ( V_1 , V_32 , V_131 , V_45 ) ;
F_3 ( V_1 , V_32 , V_53 , ( ( 0xffffULL << 32 ) |
V_134 | V_135 | V_57 | V_55 ) ) ;
F_3 ( V_1 , V_32 ,
V_136 , V_137 ) ;
V_45 = F_1 ( V_1 , V_32 , V_138 ) ;
V_45 &= ~ 0xFFFFull ;
F_3 ( V_1 , V_32 , V_138 ,
V_45 | ( V_137 - 0x1000 ) ) ;
F_3 ( V_1 , V_32 , V_139 , 0x01 ) ;
F_5 ( V_1 , V_32 , V_140 , ( 0x100 - 1 ) ) ;
F_5 ( V_1 , V_32 , V_141 , V_91 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_1 ;
int V_32 = V_2 -> V_32 ;
int V_37 = V_2 -> V_37 ;
T_1 V_45 ;
if ( V_2 -> V_113 ) {
V_45 = F_1 ( V_1 , V_32 , V_112 ) ;
if ( ! ( V_45 & ( 1ull << 13 ) ) ) {
V_45 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_32 , V_112 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 , V_117 ) ;
V_45 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_32 , V_117 , V_45 ) ;
return - 1 ;
}
}
if ( F_6 ( V_1 , V_32 , V_87 , V_104 , true ) ) {
F_30 ( & V_1 -> V_14 -> V_95 , L_3 ) ;
return - 1 ;
}
if ( ( V_37 == V_127 ) || ( V_37 == V_142 ) ||
( V_37 == V_128 ) || ( V_37 == V_143 ) ) {
if ( F_6 ( V_1 , V_32 , V_144 ,
V_145 , false ) ) {
F_30 ( & V_1 -> V_14 -> V_95 ,
L_4 ) ;
return - 1 ;
}
} else {
if ( F_6 ( V_1 , V_32 , V_146 ,
V_147 , false ) ) {
F_30 ( & V_1 -> V_14 -> V_95 ,
L_5 ) ;
return - 1 ;
}
}
if ( F_1 ( V_1 , V_32 , V_148 ) & V_149 )
F_5 ( V_1 , V_32 ,
V_148 , V_149 ) ;
if ( F_1 ( V_1 , V_32 , V_148 ) & V_149 ) {
F_30 ( & V_1 -> V_14 -> V_95 , L_6 ) ;
if ( V_2 -> V_113 ) {
V_45 = F_1 ( V_1 , V_32 , V_112 ) ;
if ( ! ( V_45 & ( 1ull << 13 ) ) ) {
V_45 = ( 1ull << 13 ) | ( 1ull << 14 ) ;
F_3 ( V_1 , V_32 , V_112 , V_45 ) ;
V_45 = F_1 ( V_1 , V_32 ,
V_117 ) ;
V_45 |= ( 1ull << 0 ) ;
F_3 ( V_1 , V_32 ,
V_117 , V_45 ) ;
return - 1 ;
}
}
return - 1 ;
}
if ( F_6 ( V_1 , V_32 , V_150 , V_151 , false ) ) {
F_30 ( & V_1 -> V_14 -> V_95 , L_7 ) ;
return - 1 ;
}
if ( F_6 ( V_1 , V_32 , V_150 , V_152 , false ) ) {
F_30 ( & V_1 -> V_14 -> V_95 , L_8 ) ;
return - 1 ;
}
V_45 = F_1 ( V_1 , V_32 , V_153 ) ;
V_45 &= V_154 ;
if ( ! V_45 )
return 0 ;
F_31 ( V_1 , V_2 ) ;
return - 1 ;
}
static void F_32 ( struct V_2 * V_2 )
{
T_1 V_155 , V_156 ;
T_2 V_41 ;
V_155 = F_1 ( V_2 -> V_1 , V_2 -> V_32 ,
V_102 ) ;
if ( ! ( V_155 & V_157 ) )
V_155 = F_1 ( V_2 -> V_1 , V_2 -> V_32 ,
V_102 ) ;
if ( F_6 ( V_2 -> V_1 , V_2 -> V_32 , V_102 ,
V_103 , false ) ) {
V_2 -> V_38 = false ;
V_2 -> V_42 = V_158 ;
V_2 -> V_40 = V_159 ;
goto V_160;
}
V_2 -> V_38 = ( ( V_155 & V_157 ) != 0 ) ? true : false ;
V_156 = F_1 ( V_2 -> V_1 , V_2 -> V_32 ,
V_161 ) ;
V_41 = ( V_156 >> 3 ) & 0x3 ;
V_2 -> V_40 = ( V_156 >> 1 ) & 0x1 ;
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
V_2 -> V_42 = V_158 ;
V_2 -> V_40 = V_159 ;
break;
}
V_160:
if ( V_2 -> V_78 != V_2 -> V_38 ) {
if ( V_2 -> V_38 )
F_21 ( V_2 ) ;
V_2 -> V_78 = V_2 -> V_38 ;
}
F_33 ( V_2 -> V_162 , & V_2 -> V_163 , V_164 * 3 ) ;
}
static void F_34 ( struct V_165 * V_166 )
{
struct V_2 * V_2 ;
T_1 V_167 , V_168 ;
V_2 = F_23 ( V_166 , struct V_2 , V_163 . V_166 ) ;
if ( V_2 -> V_52 ) {
F_32 ( V_2 ) ;
return;
}
F_5 ( V_2 -> V_1 , V_2 -> V_32 ,
V_169 , V_170 ) ;
F_6 ( V_2 -> V_1 , V_2 -> V_32 , V_169 ,
V_170 , false ) ;
V_167 = F_1 ( V_2 -> V_1 , V_2 -> V_32 , V_169 ) ;
V_168 = F_1 ( V_2 -> V_1 , V_2 -> V_32 , V_153 ) ;
if ( ( V_167 & V_170 ) &&
! ( V_168 & V_154 ) ) {
V_2 -> V_38 = 1 ;
if ( V_2 -> V_37 == V_143 )
V_2 -> V_42 = 40000 ;
else
V_2 -> V_42 = 10000 ;
V_2 -> V_40 = 1 ;
} else {
V_2 -> V_38 = 0 ;
V_2 -> V_42 = V_158 ;
V_2 -> V_40 = V_159 ;
}
if ( V_2 -> V_78 != V_2 -> V_38 ) {
if ( V_2 -> V_38 ) {
if ( F_24 ( V_2 ) ) {
V_2 -> V_38 = 0 ;
V_2 -> V_42 = V_158 ;
V_2 -> V_40 = V_159 ;
}
}
V_2 -> V_78 = V_2 -> V_38 ;
}
F_33 ( V_2 -> V_162 , & V_2 -> V_163 , V_164 * 2 ) ;
}
static int F_35 ( T_2 V_37 )
{
if ( V_37 == V_99 )
return V_171 ;
if ( V_37 == V_172 )
return V_173 ;
return V_174 ;
}
static int F_36 ( struct V_1 * V_1 , T_2 V_32 )
{
struct V_2 * V_2 ;
T_1 V_45 ;
V_2 = & V_1 -> V_2 [ V_32 ] ;
V_2 -> V_1 = V_1 ;
if ( ( V_2 -> V_37 == V_101 ) ||
( V_2 -> V_37 == V_99 ) ||
( V_2 -> V_37 == V_172 ) ) {
V_2 -> V_52 = 1 ;
if ( F_29 ( V_1 , V_2 ) )
return - 1 ;
} else {
V_2 -> V_52 = 0 ;
if ( F_31 ( V_1 , V_2 ) )
return - 1 ;
}
if ( V_2 -> V_52 ) {
V_45 = F_1 ( V_1 , V_32 , V_92 ) ;
V_45 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_32 , V_92 , V_45 ) ;
F_3 ( V_1 , V_32 , V_175 , 60 - 1 ) ;
} else {
V_45 = F_1 ( V_1 , V_32 , V_119 ) ;
V_45 |= ( ( 1ull << 2 ) | ( 1ull << 1 ) ) ;
F_5 ( V_1 , V_32 , V_119 , V_45 ) ;
F_3 ( V_1 , V_32 , V_176 , 60 + 4 ) ;
}
F_5 ( V_1 , V_32 , V_46 , V_62 ) ;
F_3 ( V_1 , V_32 , V_177 , 0x03 ) ;
if ( ( V_2 -> V_37 != V_142 ) &&
( V_2 -> V_37 != V_143 ) &&
( V_2 -> V_37 != V_128 ) &&
( V_2 -> V_37 != V_127 ) ) {
if ( ! V_2 -> V_76 ) {
if ( V_2 -> V_58 ) {
F_3 ( V_1 , V_32 ,
V_178 ,
V_179 ) ;
goto V_180;
} else {
V_2 -> V_38 = true ;
V_2 -> V_42 = 1000 ;
V_2 -> V_40 = 1 ;
F_21 ( V_2 ) ;
return 0 ;
}
}
V_2 -> V_76 -> V_181 = 0 ;
if ( F_37 ( & V_2 -> V_74 , V_2 -> V_76 ,
F_22 ,
F_35 ( V_2 -> V_37 ) ) )
return - V_182 ;
F_38 ( V_2 -> V_76 ) ;
return 0 ;
}
V_180:
V_2 -> V_162 = F_39 ( L_9 , V_183 |
V_184 , 1 ) ;
if ( ! V_2 -> V_162 )
return - V_185 ;
F_40 ( & V_2 -> V_163 , F_34 ) ;
F_33 ( V_2 -> V_162 , & V_2 -> V_163 , 0 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_1 , T_2 V_32 )
{
struct V_2 * V_2 ;
T_1 V_45 ;
V_2 = & V_1 -> V_2 [ V_32 ] ;
if ( V_2 -> V_162 ) {
F_42 ( & V_2 -> V_163 ) ;
F_43 ( V_2 -> V_162 ) ;
}
V_45 = F_1 ( V_1 , V_32 , V_46 ) ;
V_45 &= ~ V_47 ;
F_3 ( V_1 , V_32 , V_46 , V_45 ) ;
F_6 ( V_1 , V_32 , V_186 , ( T_1 ) 0x1FFF , true ) ;
F_6 ( V_1 , V_32 , V_187 , ( T_1 ) 0x3FFF , true ) ;
V_45 = F_1 ( V_1 , V_32 , V_46 ) ;
V_45 &= ~ V_48 ;
F_3 ( V_1 , V_32 , V_46 , V_45 ) ;
if ( ! V_2 -> V_52 )
F_5 ( V_1 , V_32 ,
V_87 , V_105 ) ;
else
F_5 ( V_1 , V_32 ,
V_85 , V_96 ) ;
V_45 = F_1 ( V_1 , V_32 , V_46 ) ;
V_45 &= ~ V_62 ;
F_3 ( V_1 , V_32 , V_46 , V_45 ) ;
F_27 ( V_1 , V_32 ) ;
if ( ( V_2 -> V_37 != V_142 ) &&
( V_2 -> V_37 != V_143 ) &&
( V_2 -> V_37 != V_128 ) &&
( V_2 -> V_37 != V_127 ) && V_2 -> V_76 )
F_44 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
static void F_45 ( struct V_1 * V_1 )
{
int V_29 ;
struct V_2 * V_2 ;
F_5 ( V_1 , 0 , V_188 , V_189 ) ;
if ( F_1 ( V_1 , 0 , V_190 ) )
F_30 ( & V_1 -> V_14 -> V_95 , L_10 , V_1 -> V_191 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ ) {
V_2 = & V_1 -> V_2 [ V_29 ] ;
F_3 ( V_1 , V_29 , V_46 ,
( V_2 -> V_37 << 8 ) | V_2 -> V_192 ) ;
V_1 -> V_2 [ V_29 ] . V_193 = V_31 ;
V_31 ++ ;
}
F_3 ( V_1 , 0 , V_194 , V_1 -> V_31 ) ;
F_3 ( V_1 , 0 , V_195 , V_1 -> V_31 ) ;
for ( V_29 = 0 ; V_29 < V_1 -> V_31 ; V_29 ++ )
F_5 ( V_1 , 0 , V_196 ,
( ( 1ULL << V_197 ) - 1 ) <<
( V_29 * V_197 ) ) ;
for ( V_29 = 0 ; V_29 < V_198 ; V_29 ++ )
F_3 ( V_1 , 0 , V_83 + ( V_29 * 8 ) , 0x00 ) ;
for ( V_29 = 0 ; V_29 < V_199 ; V_29 ++ )
F_3 ( V_1 , 0 , V_200 + ( V_29 * 8 ) , 0x00 ) ;
}
static T_2 F_46 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return ( T_2 ) ( F_1 ( V_1 , V_2 -> V_32 , V_46 ) & 0xFF ) ;
}
static void F_47 ( struct V_1 * V_1 , T_2 V_32 )
{
struct V_201 * V_95 = & V_1 -> V_14 -> V_95 ;
struct V_2 * V_2 ;
char V_202 [ 20 ] ;
if ( ! V_1 -> V_203 && V_32 )
return;
V_2 = & V_1 -> V_2 [ V_32 ] ;
if ( ! V_1 -> V_203 )
sprintf ( V_202 , L_11 , V_1 -> V_191 ) ;
else
sprintf ( V_202 , L_12 , V_1 -> V_191 , V_32 ) ;
switch ( V_2 -> V_37 ) {
case V_101 :
F_48 ( V_95 , L_13 , ( char * ) V_202 ) ;
break;
case V_204 :
F_48 ( V_95 , L_14 , ( char * ) V_202 ) ;
break;
case V_106 :
F_48 ( V_95 , L_15 , ( char * ) V_202 ) ;
break;
case V_142 :
if ( ! V_2 -> V_113 )
F_48 ( V_95 , L_16 , ( char * ) V_202 ) ;
else
F_48 ( V_95 , L_17 , ( char * ) V_202 ) ;
break;
case V_143 :
if ( ! V_2 -> V_113 )
F_48 ( V_95 , L_18 , ( char * ) V_202 ) ;
else
F_48 ( V_95 , L_19 , ( char * ) V_202 ) ;
break;
case V_99 :
F_48 ( V_95 , L_20 , ( char * ) V_202 ) ;
break;
case V_172 :
F_48 ( V_95 , L_21 , ( char * ) V_202 ) ;
break;
case V_205 :
break;
}
}
static void F_49 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
switch ( V_2 -> V_37 ) {
case V_101 :
case V_142 :
V_2 -> V_192 = V_2 -> V_32 ;
break;
case V_204 :
case V_143 :
case V_172 :
V_2 -> V_192 = 0xE4 ;
break;
case V_106 :
V_2 -> V_192 = ( V_2 -> V_32 ) ? 0xE : 0x4 ;
break;
case V_99 :
V_2 -> V_192 = F_46 ( V_1 , V_2 ) ;
break;
default:
V_2 -> V_192 = 0 ;
break;
}
}
static void F_50 ( struct V_1 * V_1 , struct V_2 * V_2 , int V_32 )
{
if ( ( V_2 -> V_37 != V_127 ) &&
( V_2 -> V_37 != V_128 ) ) {
V_2 -> V_113 = 0 ;
return;
}
V_2 -> V_113 = F_1 ( V_1 , V_32 , V_117 ) &
V_118 ;
}
static void F_51 ( struct V_1 * V_1 , T_2 V_27 )
{
struct V_2 * V_2 ;
T_1 V_59 ;
T_2 V_37 ;
T_2 V_192 ;
V_2 = & V_1 -> V_2 [ V_27 ] ;
if ( ! V_1 -> V_203 || V_1 -> V_49 ) {
V_59 = F_1 ( V_1 , 0 , V_46 ) ;
V_2 -> V_37 = ( V_59 >> 8 ) & 0x07 ;
if ( V_1 -> V_49 )
V_2 -> V_37 = V_172 ;
F_50 ( V_1 , V_2 , 0 ) ;
F_49 ( V_1 , V_2 ) ;
return;
}
V_59 = F_1 ( V_1 , V_27 , V_46 ) ;
V_37 = ( T_2 ) ( ( V_59 >> 8 ) & 0x07 ) ;
V_192 = ( T_2 ) ( V_59 & 0xFF ) ;
if ( ( V_37 == 0 ) && ( V_192 == 0xE4 ) )
V_2 -> V_37 = V_205 ;
else
V_2 -> V_37 = V_37 ;
V_2 -> V_192 = V_192 ;
F_50 ( V_1 , V_2 , V_2 -> V_32 ) ;
}
static void F_52 ( struct V_1 * V_1 )
{
struct V_2 * V_2 ;
T_2 V_27 ;
for ( V_27 = 0 ; V_27 < V_1 -> V_206 ; V_27 ++ ) {
V_2 = & V_1 -> V_2 [ V_27 ] ;
V_2 -> V_32 = V_27 ;
V_2 -> V_37 = V_205 ;
V_2 -> V_113 = false ;
}
V_1 -> V_31 = F_1 ( V_1 , 0 , V_195 ) & 0x7 ;
if ( V_1 -> V_31 > V_1 -> V_206 )
V_1 -> V_31 = V_1 -> V_206 ;
for ( V_27 = 0 ; V_27 < V_1 -> V_31 ; V_27 ++ ) {
F_51 ( V_1 , V_27 ) ;
F_47 ( V_1 , V_27 ) ;
}
}
static int F_53 ( struct V_201 * V_95 , struct V_207 * V_208 ,
T_2 * V_209 )
{
T_2 V_43 [ V_210 ] ;
int V_211 ;
V_211 = F_54 ( F_55 ( V_208 ) ,
L_22 , V_43 , V_210 ) ;
if ( V_211 )
goto V_212;
if ( ! F_56 ( V_43 ) ) {
F_30 ( V_95 , L_23 , V_43 ) ;
V_211 = - V_213 ;
goto V_212;
}
F_48 ( V_95 , L_24 , V_43 ) ;
memcpy ( V_209 , V_43 , V_210 ) ;
V_212:
return V_211 ;
}
static T_5 F_57 ( T_6 V_214 ,
V_6 V_215 , void * V_216 , void * * V_217 )
{
struct V_1 * V_1 = V_216 ;
struct V_201 * V_95 = & V_1 -> V_14 -> V_95 ;
struct V_207 * V_208 ;
if ( F_58 ( V_214 , & V_208 ) )
goto V_212;
F_53 ( V_95 , V_208 , V_1 -> V_2 [ V_1 -> V_218 ] . V_43 ) ;
F_59 ( & V_1 -> V_2 [ V_1 -> V_218 ] . V_74 , V_95 ) ;
V_1 -> V_2 [ V_1 -> V_218 ] . V_32 = V_1 -> V_218 ;
V_1 -> V_218 ++ ;
V_212:
return V_219 ;
}
static T_5 F_60 ( T_6 V_214 , V_6 V_215 ,
void * V_216 , void * * V_220 )
{
struct V_221 string = { V_222 , NULL } ;
struct V_1 * V_1 = V_216 ;
char V_223 [ 5 ] ;
snprintf ( V_223 , 5 , L_25 , V_1 -> V_191 ) ;
if ( F_61 ( F_62 ( V_214 , V_224 , & string ) ) ) {
F_63 ( L_26 ) ;
return V_219 ;
}
if ( strncmp ( string . V_225 , V_223 , 4 ) )
return V_219 ;
F_64 ( V_226 , V_214 , 1 ,
F_57 , NULL , V_1 , NULL ) ;
F_65 ( string . V_225 ) ;
return V_227 ;
}
static int F_66 ( struct V_1 * V_1 )
{
F_67 ( NULL , F_60 , V_1 , ( void * * ) NULL ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_1 )
{
return - V_182 ;
}
static int F_68 ( struct V_1 * V_1 )
{
struct V_228 * V_229 ;
struct V_230 * V_25 = NULL ;
T_2 V_2 = 0 ;
F_69 (&bgx->pdev->dev, fwn) {
struct V_75 * V_231 ;
struct V_230 * V_232 ;
const char * V_43 ;
V_25 = F_70 ( V_229 ) ;
if ( ! V_25 )
break;
V_43 = F_71 ( V_25 ) ;
if ( V_43 )
F_16 ( V_1 -> V_2 [ V_2 ] . V_43 , V_43 ) ;
F_59 ( & V_1 -> V_2 [ V_2 ] . V_74 , & V_1 -> V_14 -> V_95 ) ;
V_1 -> V_2 [ V_2 ] . V_32 = V_2 ;
V_232 = F_72 ( V_25 , L_27 , 0 ) ;
if ( V_232 &&
! F_73 ( V_232 , L_28 ) ) {
V_231 = F_74 ( V_232 ) ;
if ( ! V_231 )
goto V_233;
V_1 -> V_2 [ V_2 ] . V_76 = V_231 ;
}
V_2 ++ ;
if ( V_2 == V_1 -> V_206 ) {
F_75 ( V_25 ) ;
break;
}
}
return 0 ;
V_233:
while ( V_2 ) {
if ( V_1 -> V_2 [ V_2 ] . V_76 ) {
F_76 ( & V_1 -> V_2 [ V_2 ] . V_76 -> V_234 . V_95 ) ;
V_1 -> V_2 [ V_2 ] . V_76 = NULL ;
}
V_2 -- ;
}
F_75 ( V_25 ) ;
return - V_235 ;
}
static int F_68 ( struct V_1 * V_1 )
{
return - V_182 ;
}
static int F_77 ( struct V_1 * V_1 )
{
if ( ! V_236 )
return F_66 ( V_1 ) ;
return F_68 ( V_1 ) ;
}
static int F_78 ( struct V_13 * V_14 , const struct V_237 * V_238 )
{
int V_239 ;
struct V_201 * V_95 = & V_14 -> V_95 ;
struct V_1 * V_1 = NULL ;
T_2 V_2 ;
T_4 V_15 ;
V_1 = F_79 ( V_95 , sizeof( * V_1 ) , V_240 ) ;
if ( ! V_1 )
return - V_185 ;
V_1 -> V_14 = V_14 ;
F_80 ( V_14 , V_1 ) ;
V_239 = F_81 ( V_14 ) ;
if ( V_239 ) {
F_30 ( V_95 , L_29 ) ;
F_80 ( V_14 , NULL ) ;
return V_239 ;
}
V_239 = F_82 ( V_14 , V_241 ) ;
if ( V_239 ) {
F_30 ( V_95 , L_30 , V_239 ) ;
goto V_242;
}
V_1 -> V_5 = F_83 ( V_14 , V_243 , 0 ) ;
if ( ! V_1 -> V_5 ) {
F_30 ( V_95 , L_31 ) ;
V_239 = - V_185 ;
goto V_244;
}
F_8 ( V_14 ) ;
F_9 ( V_14 , V_245 , & V_15 ) ;
if ( V_15 != V_246 ) {
V_1 -> V_191 = ( F_84 ( V_14 ,
V_243 ) >> 24 ) & V_247 ;
V_1 -> V_191 += F_85 ( V_14 ) * V_16 ;
V_1 -> V_206 = V_248 ;
V_28 [ V_1 -> V_191 ] = V_1 ;
} else {
V_1 -> V_49 = true ;
V_1 -> V_206 = 1 ;
V_1 -> V_191 = V_20 - 1 ;
V_28 [ V_1 -> V_191 ] = V_1 ;
F_86 () ;
}
F_9 ( V_14 , V_17 , & V_15 ) ;
if ( ( V_15 == V_18 ) ||
( ( V_15 == V_21 ) && ( V_1 -> V_191 == 2 ) ) )
V_1 -> V_203 = true ;
F_52 ( V_1 ) ;
V_239 = F_77 ( V_1 ) ;
if ( V_239 )
goto V_249;
F_45 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_1 -> V_31 ; V_2 ++ ) {
V_239 = F_36 ( V_1 , V_2 ) ;
if ( V_239 ) {
F_30 ( V_95 , L_32 ,
V_1 -> V_191 , V_2 ) ;
while ( V_2 )
F_41 ( V_1 , -- V_2 ) ;
goto V_249;
}
}
return 0 ;
V_249:
V_28 [ V_1 -> V_191 ] = NULL ;
V_244:
F_87 ( V_14 ) ;
V_242:
F_88 ( V_14 ) ;
F_80 ( V_14 , NULL ) ;
return V_239 ;
}
static void F_89 ( struct V_13 * V_14 )
{
struct V_1 * V_1 = F_90 ( V_14 ) ;
T_2 V_2 ;
for ( V_2 = 0 ; V_2 < V_1 -> V_31 ; V_2 ++ )
F_41 ( V_1 , V_2 ) ;
V_28 [ V_1 -> V_191 ] = NULL ;
F_87 ( V_14 ) ;
F_88 ( V_14 ) ;
F_80 ( V_14 , NULL ) ;
}
static int T_7 F_91 ( void )
{
F_92 ( L_33 , V_241 , V_250 ) ;
return F_93 ( & V_251 ) ;
}
static void T_8 F_94 ( void )
{
F_95 ( & V_251 ) ;
}
