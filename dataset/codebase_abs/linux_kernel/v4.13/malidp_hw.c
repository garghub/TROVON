static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_4 ) ;
T_2 V_5 = V_3 & 0x10 ? 2 : 1 ;
V_2 -> V_6 = 2 ;
V_2 -> V_7 = V_8 * V_5 ;
V_2 -> V_9 [ 0 ] = V_10 * 64 * V_5 ;
V_2 -> V_9 [ 1 ] = 0 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_4 ( V_2 , V_13 , V_14 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_13 ) == V_13 )
break;
F_5 ( 1000 , 10000 ) ;
V_12 -- ;
}
F_6 ( V_12 == 0 , L_1 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_8 ( V_2 , V_18 , V_19 ) ;
F_8 ( V_2 , V_13 , V_14 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_13 ) == 0 )
break;
F_5 ( 100 , 1000 ) ;
V_12 -- ;
}
F_6 ( V_12 == 0 , L_2 ) ;
}
static bool F_9 ( struct V_1 * V_2 )
{
T_1 V_11 ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_13 ) == V_13 )
return true ;
return false ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_18 , V_19 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
T_1 V_22 = 0 ;
F_8 ( V_2 , V_23 , V_14 ) ;
if ( V_21 -> V_24 & V_25 )
V_22 |= V_26 ;
if ( V_21 -> V_24 & V_27 )
V_22 |= V_28 ;
V_22 |= V_29 ;
F_4 ( V_2 , V_22 , V_14 ) ;
V_22 = ( ( V_30 & 0xfff ) << 16 ) |
( V_31 & 0xfff ) ;
F_12 ( V_2 , V_22 , V_32 ) ;
F_12 ( V_2 , V_33 , V_32 + 4 ) ;
V_22 = F_13 ( V_21 -> V_34 ) |
F_14 ( V_21 -> V_35 ) ;
F_12 ( V_2 , V_22 , V_36 + V_37 ) ;
V_22 = F_15 ( V_21 -> V_38 ) |
F_16 ( V_21 -> V_39 ) ;
F_12 ( V_2 , V_22 , V_36 + V_40 ) ;
V_22 = F_17 ( V_21 -> V_41 ) |
F_18 ( V_21 -> V_42 ) ;
F_12 ( V_2 , V_22 , V_36 + V_43 ) ;
V_22 = F_19 ( V_21 -> V_44 ) | F_20 ( V_21 -> V_45 ) ;
F_12 ( V_2 , V_22 , V_36 + V_46 ) ;
if ( V_21 -> V_24 & V_47 )
F_4 ( V_2 , V_48 , V_49 ) ;
else
F_8 ( V_2 , V_48 , V_49 ) ;
}
static int F_21 ( struct V_1 * V_2 , T_3 V_50 , T_3 V_51 , T_1 V_52 )
{
if ( ( V_52 == V_53 ) || ( V_52 == V_54 ) )
return - V_55 ;
return V_50 * F_22 ( V_52 , 0 ) * 8 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_1 V_56 ,
T_3 V_57 ,
T_2 V_58 )
{
int V_59 ;
T_3 V_60 = V_61 + V_62 ;
F_12 ( V_2 ,
V_56 | ( V_57 & V_63 ) ,
V_60 + V_64 ) ;
for ( V_59 = 0 ; V_59 < F_24 ( V_65 ) ; ++ V_59 )
F_12 ( V_2 , F_25 (
V_65 [ V_58 ] [ V_59 ] ) ,
V_60 + V_66 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_67 * V_69 )
{
T_2 V_51 = ( T_2 ) V_68 -> V_70 - 1 ;
T_2 V_71 = ( T_2 ) V_68 -> V_72 - 1 ;
if ( F_27 ( V_51 >= F_24 ( V_65 ) ||
V_71 >= F_24 ( V_65 ) ) )
return - V_55 ;
if ( ( V_51 == V_71 ) && ( V_68 -> V_70 != V_69 -> V_70 ||
V_68 -> V_72 != V_69 -> V_72 ) ) {
F_23 ( V_2 ,
( V_73 |
V_74 ) ,
0 , V_71 ) ;
} else {
if ( V_68 -> V_72 != V_69 -> V_72 )
F_23 ( V_2 ,
V_73 ,
0 , V_71 ) ;
if ( V_68 -> V_70 != V_69 -> V_70 )
F_23 ( V_2 ,
V_74 ,
0 , V_51 ) ;
}
return 0 ;
}
static long F_28 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_20 * V_75 )
{
unsigned long V_76 ;
unsigned long V_77 = V_75 -> V_78 ;
unsigned long V_79 = V_75 -> V_44 + V_75 -> V_34 +
V_75 -> V_35 + V_75 -> V_41 ;
unsigned long V_80 = V_68 -> V_81 * V_68 -> V_82 ;
unsigned long V_83 = 10 ;
long V_84 ;
if ( V_68 -> V_85 ) {
V_83 = 15 * V_80 / ( V_79 * V_68 -> V_86 ) ;
if ( V_83 < 15 )
V_83 = 15 ;
}
V_76 = V_83 * V_77 / 10 ;
V_84 = F_29 ( V_2 -> V_76 ) ;
if ( V_84 < V_76 ) {
F_30 ( L_3 ,
V_76 / 1000 ) ;
return - V_55 ;
}
return V_84 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_87 ) ;
T_2 V_88 = ( V_3 >> 4 ) & 0x3 , V_89 ;
V_2 -> V_6 = 2 ;
switch ( V_88 ) {
case 0 :
V_2 -> V_7 = V_8 ;
V_89 = 64 ;
break;
case 1 :
V_2 -> V_7 = V_90 ;
V_89 = 128 ;
break;
case 2 :
V_2 -> V_7 = 1280 ;
V_89 = 40 ;
break;
case 3 :
V_2 -> V_7 = 0 ;
return - V_55 ;
}
V_2 -> V_9 [ 0 ] = V_2 -> V_9 [ 1 ] = V_89 * V_10 ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_4 ( V_2 , V_91 , V_92 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_91 ) == V_91 )
break;
F_5 ( 1000 , 10000 ) ;
V_12 -- ;
}
F_6 ( V_12 == 0 , L_1 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_11 , V_12 = 100 ;
F_8 ( V_2 , V_18 , V_93 ) ;
F_8 ( V_2 , V_91 , V_92 ) ;
while ( V_12 ) {
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_91 ) == 0 )
break;
F_5 ( 100 , 1000 ) ;
V_12 -- ;
}
F_6 ( V_12 == 0 , L_2 ) ;
}
static bool F_34 ( struct V_1 * V_2 )
{
T_1 V_11 ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( ( V_11 & V_91 ) == V_91 )
return true ;
return false ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_18 , V_93 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
T_1 V_22 = V_29 ;
F_12 ( V_2 , V_22 , V_94 ) ;
V_22 = ( ( ( V_31 >> 4 ) & 0xff ) << 16 ) |
( ( ( V_30 >> 4 ) & 0xff ) << 8 ) |
( ( V_33 >> 4 ) & 0xff ) ;
F_12 ( V_2 , V_22 , V_95 ) ;
V_22 = F_13 ( V_21 -> V_34 ) |
F_14 ( V_21 -> V_35 ) ;
F_12 ( V_2 , V_22 , V_96 + V_37 ) ;
V_22 = F_37 ( V_21 -> V_38 ) |
F_16 ( V_21 -> V_39 ) ;
F_12 ( V_2 , V_22 , V_96 + V_40 ) ;
V_22 = F_17 ( V_21 -> V_41 ) |
F_18 ( V_21 -> V_42 ) ;
if ( V_21 -> V_24 & V_25 )
V_22 |= V_97 ;
if ( V_21 -> V_24 & V_27 )
V_22 |= V_98 ;
F_12 ( V_2 , V_22 , V_96 + V_43 ) ;
V_22 = F_19 ( V_21 -> V_44 ) | F_20 ( V_21 -> V_45 ) ;
F_12 ( V_2 , V_22 , V_96 + V_46 ) ;
if ( V_21 -> V_24 & V_47 )
F_4 ( V_2 , V_48 , V_49 ) ;
else
F_8 ( V_2 , V_48 , V_49 ) ;
}
static int F_38 ( struct V_1 * V_2 , T_3 V_50 , T_3 V_51 , T_1 V_52 )
{
T_1 V_99 ;
if ( ( V_52 == V_53 ) || ( V_52 == V_54 ) )
return - V_55 ;
switch ( V_52 ) {
case V_100 :
case V_101 :
case V_102 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_53 :
case V_54 :
case V_112 :
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
V_99 = 32 ;
break;
case V_118 :
case V_119 :
V_99 = 24 ;
break;
default:
return - V_55 ;
}
return V_50 * V_99 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_67 * V_69 )
{
T_1 V_120 = F_40 ( V_121 ) |
F_41 ( V_121 ) ;
T_1 V_122 = F_40 ( V_68 -> V_72 ) |
F_41 ( V_68 -> V_70 ) ;
F_8 ( V_2 , V_120 , V_123 ) ;
F_4 ( V_2 , V_122 , V_123 ) ;
return 0 ;
}
static long F_42 ( struct V_1 * V_2 ,
struct V_67 * V_68 ,
struct V_20 * V_75 )
{
unsigned long V_76 ;
unsigned long V_77 = V_75 -> V_78 ;
unsigned long V_79 = V_75 -> V_44 + V_75 -> V_34 +
V_75 -> V_35 + V_75 -> V_41 ;
unsigned long V_124 = 1 , V_125 = 1 ;
long V_84 ;
if ( V_68 -> V_85 ) {
V_124 = F_43 ( V_68 -> V_81 , V_68 -> V_126 ) *
V_68 -> V_82 ;
V_124 += V_68 -> V_126 *
( V_68 -> V_86 -
F_44 ( V_68 -> V_82 , V_68 -> V_86 ) ) ;
V_125 = ( V_79 - 2 ) * V_68 -> V_86 ;
}
if ( V_124 < V_125 )
V_124 = V_125 = 1 ;
V_76 = ( V_77 * V_124 ) / V_125 ;
V_84 = F_29 ( V_2 -> V_76 ) ;
if ( V_84 < V_76 ) {
F_30 ( L_3 ,
V_76 / 1000 ) ;
return - V_55 ;
}
return V_84 ;
}
static int F_45 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 , V_87 ) ;
T_2 V_88 = ( V_3 >> 4 ) & 0x3 , V_89 ;
V_2 -> V_6 = 4 ;
switch ( V_88 ) {
case 0 :
case 2 :
V_2 -> V_7 = 0 ;
return - V_55 ;
case 1 :
V_2 -> V_7 = V_90 ;
V_89 = 128 ;
break;
case 3 :
V_2 -> V_7 = 2560 ;
V_89 = 80 ;
}
V_2 -> V_9 [ 0 ] = V_2 -> V_9 [ 1 ] = V_89 * V_10 ;
return 0 ;
}
T_2 F_46 ( const struct V_127 * V_15 ,
T_2 V_128 , T_1 V_129 )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_15 -> V_130 ; V_59 ++ ) {
if ( ( ( V_15 -> V_131 [ V_59 ] . V_132 & V_128 ) == V_128 ) &&
( V_15 -> V_131 [ V_59 ] . V_129 == V_129 ) )
return V_15 -> V_131 [ V_59 ] . V_133 ;
}
return V_134 ;
}
static void F_47 ( struct V_1 * V_2 , T_2 V_135 , T_1 V_136 )
{
T_1 V_137 = F_48 ( V_2 , V_135 ) ;
if ( V_2 -> V_15 . V_138 & V_139 )
F_12 ( V_2 , V_136 , V_137 + V_140 ) ;
else
F_12 ( V_2 , V_136 , V_137 + V_17 ) ;
}
static T_4 F_49 ( int V_136 , void * V_141 )
{
struct V_142 * V_143 = V_141 ;
struct V_144 * V_145 = V_143 -> V_146 ;
struct V_1 * V_2 ;
const struct V_147 * V_148 ;
T_1 V_11 , V_120 , V_149 ;
T_4 V_84 = V_150 ;
V_2 = V_145 -> V_151 ;
V_148 = & V_2 -> V_15 . V_152 ;
if ( V_2 -> V_153 )
return V_150 ;
V_149 = F_2 ( V_2 , V_2 -> V_15 . V_16 + V_17 ) ;
if ( V_149 & V_2 -> V_15 . V_154 . V_155 ) {
F_50 ( & V_145 -> V_156 , 1 ) ;
F_47 ( V_2 , V_157 , V_149 ) ;
V_84 = V_158 ;
}
V_11 = F_2 ( V_2 , V_17 ) ;
if ( ! ( V_11 & V_148 -> V_159 ) )
return V_84 ;
V_120 = F_2 ( V_2 , V_160 ) ;
V_11 &= V_120 ;
if ( V_11 & V_148 -> V_155 )
F_51 ( & V_145 -> V_161 ) ;
F_47 ( V_2 , V_162 , V_11 ) ;
return ( V_84 == V_150 ) ? V_163 : V_84 ;
}
static T_4 F_52 ( int V_136 , void * V_141 )
{
struct V_142 * V_143 = V_141 ;
struct V_144 * V_145 = V_143 -> V_146 ;
F_53 ( & V_145 -> V_164 ) ;
return V_163 ;
}
int F_54 ( struct V_142 * V_143 , int V_136 )
{
struct V_144 * V_145 = V_143 -> V_146 ;
struct V_1 * V_2 = V_145 -> V_151 ;
int V_84 ;
F_55 ( V_2 , V_162 , 0xffffffff ) ;
F_47 ( V_2 , V_162 , 0xffffffff ) ;
F_55 ( V_2 , V_157 , 0xffffffff ) ;
F_47 ( V_2 , V_157 , 0xffffffff ) ;
V_84 = F_56 ( V_143 -> V_151 , V_136 , F_49 ,
F_52 ,
V_165 , L_4 , V_143 ) ;
if ( V_84 < 0 ) {
F_57 ( L_5 ) ;
return V_84 ;
}
F_58 ( V_2 , V_157 ,
V_2 -> V_15 . V_154 . V_159 ) ;
F_58 ( V_2 , V_162 ,
V_2 -> V_15 . V_152 . V_159 ) ;
return 0 ;
}
void F_59 ( struct V_142 * V_143 )
{
struct V_144 * V_145 = V_143 -> V_146 ;
struct V_1 * V_2 = V_145 -> V_151 ;
F_55 ( V_2 , V_162 ,
V_2 -> V_15 . V_152 . V_159 ) ;
F_55 ( V_2 , V_157 ,
V_2 -> V_15 . V_154 . V_159 ) ;
}
static T_4 F_60 ( int V_136 , void * V_141 )
{
struct V_142 * V_143 = V_141 ;
struct V_144 * V_145 = V_143 -> V_146 ;
struct V_1 * V_2 = V_145 -> V_151 ;
T_1 V_11 , V_120 ;
if ( V_2 -> V_153 )
return V_150 ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_166 + V_17 ) ;
if ( ! ( V_11 & V_2 -> V_15 . V_167 . V_159 ) )
return V_150 ;
V_120 = F_2 ( V_2 , V_2 -> V_15 . V_166 + V_160 ) ;
V_11 = F_2 ( V_2 , V_2 -> V_15 . V_166 + V_17 ) ;
V_11 &= V_120 ;
F_47 ( V_2 , V_168 , V_11 ) ;
return V_163 ;
}
static T_4 F_61 ( int V_136 , void * V_141 )
{
return V_163 ;
}
int F_62 ( struct V_142 * V_143 , int V_136 )
{
struct V_144 * V_145 = V_143 -> V_146 ;
struct V_1 * V_2 = V_145 -> V_151 ;
int V_84 ;
F_55 ( V_2 , V_168 , 0xffffffff ) ;
F_47 ( V_2 , V_168 , 0xffffffff ) ;
V_84 = F_56 ( V_143 -> V_151 , V_136 , F_60 ,
F_61 ,
V_165 , L_6 , V_143 ) ;
if ( V_84 < 0 ) {
F_57 ( L_7 ) ;
return V_84 ;
}
F_58 ( V_2 , V_168 ,
V_2 -> V_15 . V_167 . V_159 ) ;
return 0 ;
}
void F_63 ( struct V_142 * V_143 )
{
struct V_144 * V_145 = V_143 -> V_146 ;
struct V_1 * V_2 = V_145 -> V_151 ;
F_55 ( V_2 , V_168 ,
V_2 -> V_15 . V_167 . V_159 ) ;
}
