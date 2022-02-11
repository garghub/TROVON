static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 V_8 [ 2 ] ;
T_1 V_9 ;
int V_10 ;
if ( ! V_5 -> V_11 )
return - V_12 ;
V_8 [ 0 ] . V_13 = V_5 -> V_13 ;
V_8 [ 0 ] . V_14 = 0 ;
V_8 [ 0 ] . V_15 = & V_3 ;
V_8 [ 0 ] . V_16 = sizeof( V_3 ) ;
V_8 [ 1 ] . V_13 = V_5 -> V_13 ;
V_8 [ 1 ] . V_14 = V_17 ;
V_8 [ 1 ] . V_15 = & V_9 ;
V_8 [ 1 ] . V_16 = sizeof( V_9 ) ;
F_3 ( & V_18 ) ;
V_10 = F_4 ( V_5 -> V_11 , V_8 , F_5 ( V_8 ) ) ;
F_6 ( & V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_9 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_19 , T_1 V_20 )
{
int V_10 ;
if ( V_20 > 8 )
return - V_21 ;
V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
return ( V_10 & V_19 ) >> V_20 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_22 )
{
if ( V_22 > 8 )
return - V_21 ;
return F_7 ( V_2 , V_3 , F_9 ( V_22 ) , V_22 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
struct V_7 V_8 [ 1 ] ;
T_1 V_23 [ 2 ] ;
int V_10 ;
V_23 [ 0 ] = V_3 ;
V_23 [ 1 ] = V_9 ;
V_8 [ 0 ] . V_13 = V_5 -> V_13 ;
V_8 [ 0 ] . V_14 = 0 ;
V_8 [ 0 ] . V_15 = V_23 ;
V_8 [ 0 ] . V_16 = F_5 ( V_23 ) ;
F_3 ( & V_18 ) ;
V_10 = F_4 ( V_5 -> V_11 , V_8 , F_5 ( V_8 ) ) ;
F_6 ( & V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
else if ( V_10 != 1 )
return - V_24 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 ,
T_1 V_19 , T_1 V_20 )
{
int V_10 ;
if ( V_20 > 8 )
return - V_21 ;
V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 &= ~ V_19 ;
V_10 |= V_9 << V_20 ;
return F_10 ( V_2 , V_3 , V_10 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_9 , T_1 V_22 )
{
if ( V_22 > 8 )
return - V_21 ;
return F_11 ( V_2 , V_3 , V_9 , F_9 ( V_22 ) , V_22 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
enum V_25 V_26 )
{
int V_10 ;
switch ( V_26 ) {
case V_27 :
return F_12 ( V_2 , V_28 ,
1 , V_29 ) ;
case V_30 :
return F_8 ( V_2 , V_28 ,
V_31 ) ;
case V_32 :
return F_8 ( V_2 , V_28 ,
V_33 ) ;
case V_34 :
return F_12 ( V_2 , V_28 , 1 ,
V_33 ) ;
case V_35 :
return F_12 ( V_2 , V_28 , 0 ,
V_33 ) ;
case V_36 :
return F_7 ( V_2 , V_28 ,
V_37 , V_38 ) ;
case V_39 :
return F_8 ( V_2 , V_28 ,
V_40 ) ;
case V_41 :
return F_7 ( V_2 , V_28 ,
V_42 , V_43 ) ;
case V_44 :
return F_8 ( V_2 , V_45 ,
V_46 ) ;
case V_47 :
return F_12 ( V_2 , V_45 ,
1 , V_46 ) ;
case V_48 :
return F_12 ( V_2 , V_45 ,
0 , V_46 ) ;
case V_49 :
V_10 = F_8 ( V_2 , V_45 ,
V_50 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_10 > 0 ? 0 : 1 ;
case V_51 :
return F_12 ( V_2 , V_45 ,
0 , V_50 ) ;
case V_52 :
return F_12 ( V_2 , V_45 ,
1 , V_50 ) ;
case V_53 :
return F_8 ( V_2 , V_45 ,
V_54 ) ;
case V_55 :
return F_12 ( V_2 , V_45 ,
1 , V_54 ) ;
case V_56 :
return F_12 ( V_2 , V_45 ,
0 , V_54 ) ;
case V_57 :
return F_8 ( V_2 , V_45 ,
V_58 ) ;
case V_59 :
return F_12 ( V_2 , V_45 ,
1 , V_58 ) ;
case V_60 :
return F_12 ( V_2 , V_45 ,
0 , V_58 ) ;
case V_61 :
return F_8 ( V_2 , V_62 ,
V_63 ) ;
case V_64 :
return F_12 ( V_2 , V_62 ,
1 , V_63 ) ;
case V_65 :
return F_12 ( V_2 , V_62 ,
0 , V_63 ) ;
case V_66 :
return F_8 ( V_2 , V_62 ,
V_67 ) ;
case V_68 :
return F_12 ( V_2 , V_62 ,
1 , V_67 ) ;
case V_69 :
return F_12 ( V_2 , V_62 ,
0 , V_67 ) ;
case V_70 :
return F_7 ( V_2 , V_71 ,
V_72 , V_73 ) ;
case V_74 :
return F_7 ( V_2 , V_71 ,
V_75 , V_76 ) ;
case V_77 :
return F_7 ( V_2 , V_71 ,
V_78 , V_79 ) ;
}
return - V_21 ;
}
static enum V_80 F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 ) ;
int V_10 = F_13 ( V_2 , V_74 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_5 -> V_13 ) {
case 0x6b :
switch ( V_10 ) {
case 0 :
if ( V_2 -> V_81 == V_82 )
return V_2 -> V_81 ;
return V_83 ;
case 1 :
if ( V_2 -> V_81 == V_84 ||
V_2 -> V_81 == V_85 ||
V_2 -> V_81 == V_86 )
return V_2 -> V_81 ;
return V_87 ;
case 2 :
if ( V_2 -> V_81 == V_88 )
return V_2 -> V_81 ;
return V_89 ;
default:
return V_90 ;
}
break;
case 0x6a :
switch ( V_10 ) {
case 0 :
if ( V_2 -> V_81 == V_91 )
return V_2 -> V_81 ;
return V_92 ;
case 2 :
if ( V_2 -> V_81 == V_93 )
return V_2 -> V_81 ;
return V_94 ;
default:
return V_90 ;
}
break;
}
return V_90 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_10 = F_13 ( V_2 , V_77 ) ;
int V_81 = F_14 ( V_2 ) ;
if ( V_10 < 0 || V_81 < 0 )
return - 1 ;
switch ( V_81 ) {
case V_87 :
case V_84 :
case V_83 :
case V_82 :
case V_85 :
if ( V_10 >= 0 && V_10 <= 3 )
return V_10 ;
return - 1 ;
case V_89 :
case V_88 :
case V_92 :
case V_91 :
case V_93 :
case V_94 :
if ( V_10 == 3 )
return 0 ;
else if ( V_10 == 1 )
return 1 ;
return - 1 ;
case V_86 :
if ( V_10 == 3 )
return 3 ;
return - 1 ;
case V_90 :
return - 1 ;
}
return - 1 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_13 ( V_2 , V_70 ) ;
if ( V_10 < 0 )
return 0 ;
return ( V_10 & 0x1 ) +
( ( V_10 >> 1 ) & 0x1 ) * 10 +
( ( V_10 >> 2 ) & 0x1 ) * 100 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_95 , V_96 ) ;
F_10 ( V_2 , V_62 , V_97 ) ;
F_10 ( V_2 , V_45 , V_98 ) ;
F_10 ( V_2 , V_28 , V_99 ) ;
V_2 -> V_100 = NULL ;
}
static int F_18 ( struct V_1 * V_2 , int V_101 )
{
int V_9 ;
if ( V_101 <= 100 )
V_9 = 0 ;
else if ( V_101 <= 500 )
V_9 = 1 ;
else if ( V_101 <= 800 )
V_9 = 2 ;
else
V_9 = 3 ;
return F_11 ( V_2 , V_45 , V_9 ,
V_102 , V_103 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_7 ( V_2 , V_45 ,
V_102 , V_103 ) ;
if ( V_10 < 0 )
return V_10 ;
else if ( V_10 == 0 )
return 100 ;
else if ( V_10 == 1 )
return 500 ;
else if ( V_10 == 2 )
return 800 ;
else if ( V_10 == 3 )
return 1800 ;
return - V_21 ;
}
static int F_20 ( struct V_1 * V_2 , int V_104 )
{
int V_9 ;
if ( V_104 <= 3400 + 50 )
V_9 = 0 ;
else if ( V_104 <= 3500 + 50 )
V_9 = 1 ;
else if ( V_104 <= 3600 + 50 )
V_9 = 2 ;
else
V_9 = 3 ;
return F_11 ( V_2 , V_45 , V_9 ,
V_105 , V_106 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_7 ( V_2 , V_45 ,
V_105 , V_106 ) ;
if ( V_10 < 0 )
return V_10 ;
return 100 * ( 34 + V_10 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_104 )
{
int V_9 = ( V_104 / 10 - 350 ) / 2 ;
if ( V_9 < 0 )
V_9 = 0 ;
else if ( V_9 > 47 )
return - V_21 ;
return F_11 ( V_2 , V_62 , V_9 ,
V_107 , V_108 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_10 = F_7 ( V_2 , V_62 ,
V_107 , V_108 ) ;
if ( V_10 < 0 )
return V_10 ;
return 10 * ( 350 + 2 * V_10 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_101 )
{
int V_9 ;
if ( V_2 -> V_109 . V_110 <= 0 )
return - V_111 ;
V_9 = ( V_101 * V_2 -> V_109 . V_110 - 37400 ) / 6800 ;
if ( V_9 < 0 )
V_9 = 0 ;
else if ( V_9 > 7 )
V_9 = 7 ;
return F_11 ( V_2 , V_95 , V_9 ,
V_112 | V_113 ,
V_114 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_109 . V_110 <= 0 )
return - V_111 ;
V_10 = F_7 ( V_2 , V_95 ,
V_112 , V_114 ) ;
if ( V_10 < 0 )
return V_10 ;
return ( 37400 + 6800 * V_10 ) / V_2 -> V_109 . V_110 ;
}
static int F_26 ( struct V_1 * V_2 , int V_101 )
{
int V_9 ;
if ( V_2 -> V_109 . V_110 <= 0 )
return - V_111 ;
V_9 = ( V_101 * V_2 -> V_109 . V_110 - 3400 ) / 3400 ;
if ( V_9 < 0 )
V_9 = 0 ;
else if ( V_9 > 7 )
V_9 = 7 ;
return F_11 ( V_2 , V_95 , V_9 ,
V_115 | V_113 ,
V_116 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_109 . V_110 <= 0 )
return - V_111 ;
V_10 = F_7 ( V_2 , V_95 ,
V_115 , V_116 ) ;
if ( V_10 < 0 )
return V_10 ;
return ( 3400 + 3400 * V_10 ) / V_2 -> V_109 . V_110 ;
}
static int F_28 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_60 ) ;
F_13 ( V_2 , V_52 ) ;
F_13 ( V_2 , V_48 ) ;
F_29 ( V_2 , V_117 ) ;
F_29 ( V_2 , V_118 ) ;
F_29 ( V_2 , V_119 ) ;
if ( V_2 -> V_109 . V_110 > 0 ) {
F_29 ( V_2 , V_120 ) ;
F_29 ( V_2 , V_121 ) ;
F_13 ( V_2 , V_47 ) ;
}
F_13 ( V_2 , V_51 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , enum V_122 V_123 )
{
int V_10 = 0 ;
int V_124 = 0 ;
int V_125 = 0 ;
if ( V_123 == V_126 )
V_125 = 1 ;
else if ( V_123 != V_127 )
V_124 = 1 ;
if ( ! V_124 )
V_10 = F_13 ( V_2 , V_52 ) ;
if ( ! V_125 )
V_10 = F_13 ( V_2 , V_60 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_123 ) {
case V_127 :
F_31 ( V_2 -> V_6 , L_1 ) ;
V_10 = F_18 ( V_2 , 100 ) ;
break;
case V_128 :
F_31 ( V_2 -> V_6 , L_2 ) ;
V_10 = F_18 ( V_2 , 100 ) ;
break;
case V_129 :
F_31 ( V_2 -> V_6 , L_3 ) ;
V_10 = F_18 ( V_2 , 500 ) ;
break;
case V_130 :
F_31 ( V_2 -> V_6 , L_4 ) ;
V_10 = F_18 ( V_2 , 1800 ) ;
break;
case V_126 :
F_31 ( V_2 -> V_6 , L_5 ) ;
V_10 = F_18 ( V_2 , 100 ) ;
break;
}
if ( V_10 < 0 )
return V_10 ;
if ( V_124 )
V_10 = F_13 ( V_2 , V_51 ) ;
else if ( V_125 )
V_10 = F_13 ( V_2 , V_59 ) ;
if ( V_10 < 0 )
return V_10 ;
F_29 ( V_2 , V_118 ) ;
F_29 ( V_2 , V_119 ) ;
V_2 -> V_123 = V_123 ;
F_32 ( & V_2 -> V_124 -> V_6 . V_131 , NULL , L_6 ) ;
return 0 ;
}
static int F_33 ( struct V_132 * V_133 ,
unsigned long V_9 , void * V_134 )
{
struct V_1 * V_2 =
F_34 ( V_133 , struct V_1 , V_133 ) ;
struct V_135 * V_136 = V_134 ;
enum V_122 V_123 ;
union V_137 V_138 ;
int V_10 ;
int V_101 ;
if ( V_9 != V_139 )
return V_140 ;
if ( V_136 != V_2 -> V_141 )
return V_140 ;
F_31 ( V_2 -> V_6 , L_7 ) ;
V_10 = F_35 ( V_136 , V_142 ,
& V_138 ) ;
if ( V_10 != 0 )
return V_140 ;
V_101 = V_138 . V_143 ;
if ( V_101 == 0 )
V_123 = V_127 ;
else if ( V_101 < 500 )
V_123 = V_128 ;
else if ( V_101 < 1800 )
V_123 = V_129 ;
else
V_123 = V_130 ;
if ( V_2 -> V_144 == V_123 )
return V_140 ;
V_2 -> V_144 = V_123 ;
if ( V_2 -> V_145 < 1 )
return V_140 ;
F_36 ( & V_2 -> V_146 , 0 ) ;
return V_140 ;
}
static void F_37 ( struct V_1 * V_2 , int V_147 )
{
F_3 ( & V_148 ) ;
if ( V_2 -> V_149 == V_147 ) {
F_6 ( & V_148 ) ;
return;
}
V_2 -> V_149 = V_147 ;
if ( V_147 ) {
F_36 ( & V_2 -> V_146 , V_150 * V_151 ) ;
F_13 ( V_2 , V_27 ) ;
V_2 -> V_100 = NULL ;
} else {
F_38 ( & V_2 -> V_146 ) ;
}
F_6 ( & V_148 ) ;
}
static void F_39 ( struct V_1 * V_2 , const char * V_8 )
{
V_2 -> V_100 = V_8 ;
F_32 ( & V_2 -> V_124 -> V_6 . V_131 , NULL , L_8 ) ;
F_40 ( V_2 -> V_6 , L_9 , V_8 ) ;
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
F_30 ( V_2 , V_127 ) ;
F_37 ( V_2 , 0 ) ;
}
static void F_41 ( struct V_152 * V_146 )
{
struct V_1 * V_2 = F_34 ( V_146 , struct V_1 ,
V_146 . V_146 ) ;
int V_10 ;
int error ;
int V_125 ;
if ( V_2 -> V_145 > 0 && ( V_2 -> V_144 != V_2 -> V_123 ) ) {
F_32 ( & V_2 -> V_124 -> V_6 . V_131 , NULL , L_10 ) ;
F_30 ( V_2 , V_2 -> V_144 ) ;
}
if ( ! V_2 -> V_149 )
return;
V_10 = F_13 ( V_2 , V_27 ) ;
if ( V_10 < 0 ) {
F_39 ( V_2 , L_11 ) ;
return;
}
V_125 = F_13 ( V_2 , V_57 ) ;
if ( V_125 < 0 ) {
F_39 ( V_2 , L_12 ) ;
return;
}
error = F_13 ( V_2 , V_41 ) ;
if ( error < 0 ) {
F_39 ( V_2 , L_12 ) ;
return;
}
if ( V_125 ) {
switch ( error ) {
case 0 :
break;
case 6 :
F_40 ( V_2 -> V_6 , L_13 ) ;
break;
case 3 :
F_40 ( V_2 -> V_6 , L_14 ) ;
break;
case 1 :
F_39 ( V_2 ,
L_15 ) ;
return;
case 2 :
F_39 ( V_2 , L_16 ) ;
return;
case 4 :
F_39 ( V_2 ,
L_17 ) ;
return;
case 5 :
F_39 ( V_2 ,
L_18 ) ;
return;
case 7 :
F_39 ( V_2 , L_12 ) ;
return;
}
} else {
switch ( error ) {
case 0 :
break;
case 2 :
F_40 ( V_2 -> V_6 , L_19 ) ;
break;
case 3 :
F_40 ( V_2 -> V_6 , L_20 ) ;
break;
case 6 :
F_40 ( V_2 -> V_6 , L_13 ) ;
break;
case 7 :
F_40 ( V_2 -> V_6 , L_21 ) ;
break;
case 1 :
F_39 ( V_2 ,
L_15 ) ;
return;
case 4 :
F_39 ( V_2 ,
L_17 ) ;
return;
case 5 :
F_39 ( V_2 ,
L_18 ) ;
return;
}
}
F_36 ( & V_2 -> V_146 , V_150 * V_151 ) ;
}
static int F_42 ( struct V_135 * V_136 ,
enum V_153 V_154 ,
union V_137 * V_9 )
{
struct V_1 * V_2 = F_43 ( V_136 ) ;
int V_10 ;
switch ( V_154 ) {
case V_155 :
V_10 = F_13 ( V_2 , V_36 ) ;
if ( V_10 < 0 )
return V_10 ;
else if ( V_10 == 0 )
V_9 -> V_143 = V_156 ;
else if ( V_10 == 1 )
V_9 -> V_143 = V_157 ;
else if ( V_10 == 2 )
V_9 -> V_143 = V_158 ;
else
V_9 -> V_143 = V_159 ;
break;
case V_160 :
V_9 -> V_161 = V_2 -> V_162 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_10 ;
int V_81 ;
char V_163 [ 8 ] ;
struct V_164 V_165 = { . V_166 = V_2 , } ;
V_2 -> V_167 . V_168 = V_2 -> V_168 ;
V_2 -> V_167 . type = V_169 ;
V_2 -> V_167 . V_170 = V_171 ;
V_2 -> V_167 . V_172 =
F_5 ( V_171 ) ;
V_2 -> V_167 . V_173 = F_42 ;
V_10 = F_14 ( V_2 ) ;
if ( V_10 < 0 )
V_81 = V_90 ;
else
V_81 = V_10 ;
V_10 = F_15 ( V_2 ) ;
if ( V_10 < 0 )
strcpy ( V_163 , L_22 ) ;
else
sprintf ( V_163 , L_23 , V_10 ) ;
V_2 -> V_162 = F_45 ( V_174 ,
L_24 ,
V_175 [ V_81 ] , V_163 ,
F_16 ( V_2 ) ) ;
if ( ! V_2 -> V_162 ) {
F_40 ( V_2 -> V_6 , L_25 ) ;
return - V_176 ;
}
V_2 -> V_124 = F_46 ( V_2 -> V_6 , & V_2 -> V_167 ,
& V_165 ) ;
if ( F_47 ( V_2 -> V_124 ) ) {
F_48 ( V_2 -> V_162 ) ;
return F_49 ( V_2 -> V_124 ) ;
}
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
V_2 -> V_149 = 0 ;
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
F_38 ( & V_2 -> V_146 ) ;
F_51 ( V_2 -> V_124 ) ;
F_48 ( V_2 -> V_162 ) ;
}
static T_2 F_52 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
char * V_15 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
enum V_25 V_26 ;
int V_10 ;
if ( strcmp ( V_179 -> V_179 . V_168 , L_26 ) == 0 )
V_26 = V_30 ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_27 ) == 0 )
V_26 = V_36 ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_28 ) == 0 )
V_26 = V_39 ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_29 ) == 0 )
V_26 = V_41 ;
else
return - V_21 ;
V_10 = F_13 ( V_2 , V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_15 , L_30 , V_10 ) ;
}
static T_2 F_54 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
const char * V_15 ,
T_3 V_180 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
int V_10 = 0 ;
if ( strncmp ( V_15 , L_31 , 4 ) == 0 )
F_37 ( V_2 , 1 ) ;
else if ( strncmp ( V_15 , L_32 , 3 ) == 0 )
F_37 ( V_2 , 0 ) ;
else
V_10 = F_13 ( V_2 , V_27 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_180 ;
}
static T_2 F_55 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
char * V_15 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
if ( V_2 -> V_100 )
return sprintf ( V_15 , L_9 , V_2 -> V_100 ) ;
if ( V_2 -> V_149 )
return sprintf ( V_15 , L_33 ) ;
return sprintf ( V_15 , L_34 ) ;
}
static T_2 F_56 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
const char * V_15 ,
T_3 V_180 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
enum V_122 V_123 ;
int V_10 = 0 ;
if ( strncmp ( V_15 , L_31 , 4 ) == 0 ) {
if ( V_2 -> V_145 < 0 )
return - V_111 ;
V_2 -> V_145 = 1 ;
V_123 = V_2 -> V_144 ;
} else if ( strncmp ( V_15 , L_32 , 3 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_123 = V_127 ;
} else if ( strncmp ( V_15 , L_35 , 4 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_123 = V_128 ;
} else if ( strncmp ( V_15 , L_36 , 4 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_123 = V_129 ;
} else if ( strncmp ( V_15 , L_37 , 9 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_123 = V_130 ;
} else if ( strncmp ( V_15 , L_38 , 5 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_123 = V_126 ;
} else if ( strncmp ( V_15 , L_39 , 5 ) == 0 ) {
F_17 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_145 <= 0 )
return V_180 ;
V_2 -> V_145 = 1 ;
V_123 = V_2 -> V_144 ;
} else {
return - V_21 ;
}
V_10 = F_30 ( V_2 , V_123 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_180 ;
}
static T_2 F_57 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
char * V_15 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
T_2 V_10 = 0 ;
if ( V_2 -> V_145 > 0 )
V_10 += sprintf ( V_15 + V_10 , L_40 ) ;
switch ( V_2 -> V_123 ) {
case V_127 :
V_10 += sprintf ( V_15 + V_10 , L_32 ) ;
break;
case V_128 :
V_10 += sprintf ( V_15 + V_10 , L_35 ) ;
break;
case V_129 :
V_10 += sprintf ( V_15 + V_10 , L_36 ) ;
break;
case V_130 :
V_10 += sprintf ( V_15 + V_10 , L_37 ) ;
break;
case V_126 :
V_10 += sprintf ( V_15 + V_10 , L_38 ) ;
break;
}
if ( V_2 -> V_145 > 0 )
V_10 += sprintf ( V_15 + V_10 , L_41 ) ;
V_10 += sprintf ( V_15 + V_10 , L_42 ) ;
return V_10 ;
}
static T_2 F_58 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
char * V_15 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
if ( V_2 -> V_145 < 0 )
return - V_21 ;
switch ( V_2 -> V_144 ) {
case V_127 :
return sprintf ( V_15 , L_34 ) ;
case V_128 :
return sprintf ( V_15 , L_43 ) ;
case V_129 :
return sprintf ( V_15 , L_44 ) ;
case V_130 :
return sprintf ( V_15 , L_45 ) ;
case V_126 :
return sprintf ( V_15 , L_46 ) ;
}
return - V_21 ;
}
static T_2 F_59 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
const char * V_15 ,
T_3 V_180 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
T_2 V_10 = 0 ;
unsigned int V_3 ;
unsigned int V_9 ;
if ( sscanf ( V_15 , L_47 , & V_3 , & V_9 ) != 2 )
return - V_21 ;
if ( V_3 > 4 || V_9 > 255 )
return - V_21 ;
V_10 = F_10 ( V_2 , V_3 , V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_180 ;
}
static T_2 F_60 ( struct V_1 * V_2 ,
T_1 V_3 ,
char * V_15 )
{
int V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return sprintf ( V_15 , L_48 , V_3 , V_10 ) ;
return sprintf ( V_15 , L_49 , V_3 , V_10 ) ;
}
static T_2 F_61 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
char * V_15 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
T_2 V_10 = 0 ;
V_10 += F_60 ( V_2 , V_28 , V_15 + V_10 ) ;
V_10 += F_60 ( V_2 , V_45 , V_15 + V_10 ) ;
V_10 += F_60 ( V_2 , V_62 , V_15 + V_10 ) ;
V_10 += F_60 ( V_2 , V_71 , V_15 + V_10 ) ;
V_10 += F_60 ( V_2 , V_95 , V_15 + V_10 ) ;
return V_10 ;
}
static T_2 F_62 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
const char * V_15 ,
T_3 V_180 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
long V_9 ;
int V_10 ;
if ( F_63 ( V_15 , 10 , & V_9 ) < 0 )
return - V_21 ;
if ( strcmp ( V_179 -> V_179 . V_168 , L_50 ) == 0 )
V_10 = F_18 ( V_2 , V_9 ) ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_51 ) == 0 )
V_10 = F_20 ( V_2 , V_9 ) ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_52 ) == 0 )
V_10 = F_22 ( V_2 , V_9 ) ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_53 ) == 0 )
V_10 = F_24 ( V_2 , V_9 ) ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_54 ) == 0 )
V_10 = F_26 ( V_2 , V_9 ) ;
else
return - V_21 ;
if ( V_10 < 0 )
return V_10 ;
return V_180 ;
}
static T_2 F_64 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
char * V_15 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
int V_10 ;
if ( strcmp ( V_179 -> V_179 . V_168 , L_50 ) == 0 )
V_10 = F_19 ( V_2 ) ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_51 ) == 0 )
V_10 = F_21 ( V_2 ) ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_52 ) == 0 )
V_10 = F_23 ( V_2 ) ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_53 ) == 0 )
V_10 = F_25 ( V_2 ) ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_54 ) == 0 )
V_10 = F_27 ( V_2 ) ;
else
return - V_21 ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_15 , L_30 , V_10 ) ;
}
static T_2 F_65 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
const char * V_15 ,
T_3 V_180 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
enum V_25 V_26 ;
long V_9 ;
int V_10 ;
if ( F_63 ( V_15 , 10 , & V_9 ) < 0 )
return - V_21 ;
if ( strcmp ( V_179 -> V_179 . V_168 , L_55 ) == 0 )
V_26 = V_9 ? V_47 :
V_48 ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_56 ) == 0 )
V_26 = V_9 ? V_55 :
V_56 ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_57 ) == 0 )
V_26 = V_9 ? V_68 :
V_69 ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_58 ) == 0 )
V_26 = V_9 ? V_34 :
V_35 ;
else
return - V_21 ;
V_10 = F_13 ( V_2 , V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_180 ;
}
static T_2 F_66 ( struct V_177 * V_6 ,
struct V_178 * V_179 ,
char * V_15 )
{
struct V_135 * V_136 = F_53 ( V_6 ) ;
struct V_1 * V_2 = F_43 ( V_136 ) ;
enum V_25 V_26 ;
int V_10 ;
if ( strcmp ( V_179 -> V_179 . V_168 , L_55 ) == 0 )
V_26 = V_44 ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_56 ) == 0 )
V_26 = V_53 ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_57 ) == 0 )
V_26 = V_66 ;
else if ( strcmp ( V_179 -> V_179 . V_168 , L_58 ) == 0 )
V_26 = V_32 ;
else
return - V_21 ;
V_10 = F_13 ( V_2 , V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_15 , L_30 , V_10 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
return F_68 ( & V_2 -> V_124 -> V_6 . V_131 ,
& V_181 ) ;
}
static void F_69 ( struct V_1 * V_2 )
{
F_70 ( & V_2 -> V_124 -> V_6 . V_131 , & V_181 ) ;
}
static int F_71 ( struct V_4 * V_5 ,
const struct V_182 * V_183 )
{
int V_10 ;
int V_184 ;
char * V_168 ;
struct V_1 * V_2 ;
struct V_185 * V_186 = V_5 -> V_6 . V_187 ;
struct V_188 * V_189 = V_5 -> V_6 . V_190 ;
if ( ! V_186 && ! V_189 ) {
F_40 ( & V_5 -> V_6 , L_59 ) ;
return - V_12 ;
}
F_3 ( & V_191 ) ;
V_184 = F_72 ( & V_192 , V_5 , 0 , 0 , V_174 ) ;
F_6 ( & V_191 ) ;
if ( V_184 < 0 )
return V_184 ;
V_168 = F_45 ( V_174 , L_60 , V_183 -> V_168 , V_184 ) ;
if ( ! V_168 ) {
F_40 ( & V_5 -> V_6 , L_61 ) ;
V_10 = - V_176 ;
goto V_193;
}
V_2 = F_73 ( & V_5 -> V_6 , sizeof( * V_2 ) , V_174 ) ;
if ( ! V_2 ) {
F_40 ( & V_5 -> V_6 , L_62 ) ;
V_10 = - V_176 ;
goto V_194;
}
if ( V_186 ) {
V_2 -> V_141 = F_74 ( V_186 , L_63 ) ;
if ( F_47 ( V_2 -> V_141 ) ) {
F_75 ( & V_5 -> V_6 ,
L_64 ,
F_49 ( V_2 -> V_141 ) ) ;
V_2 -> V_141 = NULL ;
} else if ( ! V_2 -> V_141 ) {
V_10 = - V_195 ;
goto V_194;
}
}
else if ( V_189 -> V_196 )
V_2 -> V_141 = F_76 ( V_189 -> V_196 ) ;
else
V_2 -> V_141 = NULL ;
F_77 ( V_5 , V_2 ) ;
V_2 -> V_183 = V_184 ;
V_2 -> V_6 = & V_5 -> V_6 ;
V_2 -> V_81 = V_183 -> V_197 ;
V_2 -> V_168 = V_168 ;
V_2 -> V_123 = V_127 ;
V_2 -> V_144 = V_127 ;
V_2 -> V_149 = 0 ;
V_2 -> V_145 = 0 ;
if ( V_186 ) {
V_10 = F_78 ( V_186 , L_65 ,
& V_2 -> V_109 . V_117 ) ;
if ( V_10 )
goto V_198;
V_10 = F_78 ( V_186 , L_66 ,
& V_2 -> V_109 . V_118 ) ;
if ( V_10 )
goto V_198;
V_10 = F_78 ( V_186 , L_67 ,
& V_2 -> V_109 . V_119 ) ;
if ( V_10 )
goto V_198;
V_10 = F_78 ( V_186 , L_68 ,
& V_2 -> V_109 . V_120 ) ;
if ( V_10 )
goto V_198;
V_10 = F_78 ( V_186 , L_69 ,
& V_2 -> V_109 . V_121 ) ;
if ( V_10 )
goto V_198;
V_10 = F_78 ( V_186 , L_70 ,
& V_2 -> V_109 . V_110 ) ;
if ( V_10 )
goto V_198;
} else {
memcpy ( & V_2 -> V_109 , V_189 , sizeof( V_2 -> V_109 ) ) ;
}
F_17 ( V_2 ) ;
V_10 = F_44 ( V_2 ) ;
if ( V_10 ) {
F_40 ( V_2 -> V_6 , L_71 , V_10 ) ;
goto V_198;
}
V_10 = F_67 ( V_2 ) ;
if ( V_10 ) {
F_40 ( V_2 -> V_6 , L_72 , V_10 ) ;
goto V_199;
}
V_10 = F_28 ( V_2 ) ;
if ( V_10 ) {
F_40 ( V_2 -> V_6 , L_73 , V_10 ) ;
goto V_200;
}
if ( V_2 -> V_141 ) {
V_2 -> V_133 . V_201 = F_33 ;
V_10 = F_79 ( & V_2 -> V_133 ) ;
if ( V_10 ) {
F_40 ( V_2 -> V_6 , L_74 , V_10 ) ;
goto V_202;
}
F_33 ( & V_2 -> V_133 , V_139 , V_2 -> V_141 ) ;
F_30 ( V_2 , V_2 -> V_144 ) ;
V_2 -> V_145 = 1 ;
F_75 ( V_2 -> V_6 , L_75 ) ;
} else {
V_2 -> V_145 = - 1 ;
F_75 ( V_2 -> V_6 , L_76 ) ;
}
F_80 ( & V_2 -> V_146 , F_41 ) ;
F_37 ( V_2 , 1 ) ;
F_75 ( V_2 -> V_6 , L_77 ) ;
return 0 ;
V_202:
V_200:
F_69 ( V_2 ) ;
V_199:
F_50 ( V_2 ) ;
V_198:
if ( V_2 -> V_141 )
F_81 ( V_2 -> V_141 ) ;
V_194:
F_48 ( V_168 ) ;
V_193:
F_3 ( & V_191 ) ;
F_82 ( & V_192 , V_184 ) ;
F_6 ( & V_191 ) ;
return V_10 ;
}
static int F_83 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_84 ( V_5 ) ;
if ( V_2 -> V_141 ) {
F_85 ( & V_2 -> V_133 ) ;
F_81 ( V_2 -> V_141 ) ;
}
F_69 ( V_2 ) ;
F_50 ( V_2 ) ;
F_17 ( V_2 ) ;
F_3 ( & V_191 ) ;
F_82 ( & V_192 , V_2 -> V_183 ) ;
F_6 ( & V_191 ) ;
F_75 ( V_2 -> V_6 , L_78 ) ;
F_48 ( V_2 -> V_168 ) ;
return 0 ;
}
