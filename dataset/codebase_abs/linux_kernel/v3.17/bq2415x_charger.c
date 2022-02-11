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
else
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
else
return V_83 ;
case 1 :
if ( V_2 -> V_81 == V_84 ||
V_2 -> V_81 == V_85 ||
V_2 -> V_81 == V_86 )
return V_2 -> V_81 ;
else
return V_87 ;
case 2 :
if ( V_2 -> V_81 == V_88 )
return V_2 -> V_81 ;
else
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
else
return V_92 ;
case 2 :
return V_93 ;
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
else
return - 1 ;
case V_89 :
case V_88 :
case V_92 :
case V_91 :
case V_93 :
if ( V_10 == 3 )
return 0 ;
else if ( V_10 == 1 )
return 1 ;
else
return - 1 ;
case V_86 :
if ( V_10 == 3 )
return 3 ;
else
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
F_10 ( V_2 , V_94 , V_95 ) ;
F_10 ( V_2 , V_62 , V_96 ) ;
F_10 ( V_2 , V_45 , V_97 ) ;
F_10 ( V_2 , V_28 , V_98 ) ;
V_2 -> V_99 = NULL ;
}
static int F_18 ( struct V_1 * V_2 , int V_100 )
{
int V_9 ;
if ( V_100 <= 100 )
V_9 = 0 ;
else if ( V_100 <= 500 )
V_9 = 1 ;
else if ( V_100 <= 800 )
V_9 = 2 ;
else
V_9 = 3 ;
return F_11 ( V_2 , V_45 , V_9 ,
V_101 , V_102 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_7 ( V_2 , V_45 ,
V_101 , V_102 ) ;
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
static int F_20 ( struct V_1 * V_2 , int V_103 )
{
int V_9 ;
if ( V_103 <= 3400 + 50 )
V_9 = 0 ;
else if ( V_103 <= 3500 + 50 )
V_9 = 1 ;
else if ( V_103 <= 3600 + 50 )
V_9 = 2 ;
else
V_9 = 3 ;
return F_11 ( V_2 , V_45 , V_9 ,
V_104 , V_105 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_7 ( V_2 , V_45 ,
V_104 , V_105 ) ;
if ( V_10 < 0 )
return V_10 ;
return 100 * ( 34 + V_10 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_103 )
{
int V_9 = ( V_103 / 10 - 350 ) / 2 ;
if ( V_9 < 0 )
V_9 = 0 ;
else if ( V_9 > 47 )
return - V_21 ;
return F_11 ( V_2 , V_62 , V_9 ,
V_106 , V_107 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_10 = F_7 ( V_2 , V_62 ,
V_106 , V_107 ) ;
if ( V_10 < 0 )
return V_10 ;
return 10 * ( 350 + 2 * V_10 ) ;
}
static int F_24 ( struct V_1 * V_2 , int V_100 )
{
int V_9 ;
if ( V_2 -> V_108 . V_109 <= 0 )
return - V_110 ;
V_9 = ( V_100 * V_2 -> V_108 . V_109 - 37400 ) / 6800 ;
if ( V_9 < 0 )
V_9 = 0 ;
else if ( V_9 > 7 )
V_9 = 7 ;
return F_11 ( V_2 , V_94 , V_9 ,
V_111 | V_112 ,
V_113 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_108 . V_109 <= 0 )
return - V_110 ;
V_10 = F_7 ( V_2 , V_94 ,
V_111 , V_113 ) ;
if ( V_10 < 0 )
return V_10 ;
return ( 37400 + 6800 * V_10 ) / V_2 -> V_108 . V_109 ;
}
static int F_26 ( struct V_1 * V_2 , int V_100 )
{
int V_9 ;
if ( V_2 -> V_108 . V_109 <= 0 )
return - V_110 ;
V_9 = ( V_100 * V_2 -> V_108 . V_109 - 3400 ) / 3400 ;
if ( V_9 < 0 )
V_9 = 0 ;
else if ( V_9 > 7 )
V_9 = 7 ;
return F_11 ( V_2 , V_94 , V_9 ,
V_114 | V_112 ,
V_115 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_108 . V_109 <= 0 )
return - V_110 ;
V_10 = F_7 ( V_2 , V_94 ,
V_114 , V_115 ) ;
if ( V_10 < 0 )
return V_10 ;
return ( 3400 + 3400 * V_10 ) / V_2 -> V_108 . V_109 ;
}
static int F_28 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_60 ) ;
F_13 ( V_2 , V_52 ) ;
F_13 ( V_2 , V_48 ) ;
F_29 ( V_2 , V_116 ) ;
F_29 ( V_2 , V_117 ) ;
F_29 ( V_2 , V_118 ) ;
if ( V_2 -> V_108 . V_109 > 0 ) {
F_29 ( V_2 , V_119 ) ;
F_29 ( V_2 , V_120 ) ;
F_13 ( V_2 , V_47 ) ;
}
F_13 ( V_2 , V_51 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , enum V_121 V_122 )
{
int V_10 = 0 ;
int V_123 = 0 ;
int V_124 = 0 ;
if ( V_122 == V_125 )
V_124 = 1 ;
else if ( V_122 != V_126 )
V_123 = 1 ;
if ( ! V_123 )
V_10 = F_13 ( V_2 , V_52 ) ;
if ( ! V_124 )
V_10 = F_13 ( V_2 , V_60 ) ;
if ( V_10 < 0 )
return V_10 ;
switch ( V_122 ) {
case V_126 :
F_31 ( V_2 -> V_6 , L_1 ) ;
V_10 = F_18 ( V_2 , 100 ) ;
break;
case V_127 :
F_31 ( V_2 -> V_6 , L_2 ) ;
V_10 = F_18 ( V_2 , 100 ) ;
break;
case V_128 :
F_31 ( V_2 -> V_6 , L_3 ) ;
V_10 = F_18 ( V_2 , 500 ) ;
break;
case V_129 :
F_31 ( V_2 -> V_6 , L_4 ) ;
V_10 = F_18 ( V_2 , 1800 ) ;
break;
case V_125 :
F_31 ( V_2 -> V_6 , L_5 ) ;
V_10 = F_18 ( V_2 , 100 ) ;
break;
}
if ( V_10 < 0 )
return V_10 ;
if ( V_123 )
V_10 = F_13 ( V_2 , V_51 ) ;
else if ( V_124 )
V_10 = F_13 ( V_2 , V_59 ) ;
if ( V_10 < 0 )
return V_10 ;
F_29 ( V_2 , V_117 ) ;
F_29 ( V_2 , V_118 ) ;
V_2 -> V_122 = V_122 ;
F_32 ( & V_2 -> V_123 . V_6 -> V_130 , NULL , L_6 ) ;
return 0 ;
}
static int F_33 ( struct V_131 * V_132 ,
unsigned long V_9 , void * V_133 )
{
struct V_1 * V_2 =
F_34 ( V_132 , struct V_1 , V_132 ) ;
struct V_134 * V_135 = V_133 ;
enum V_121 V_122 ;
union V_136 V_137 ;
int V_10 ;
int V_100 ;
if ( V_9 != V_138 )
return V_139 ;
if ( V_135 != V_2 -> V_140 )
return V_139 ;
F_31 ( V_2 -> V_6 , L_7 ) ;
V_10 = V_135 -> V_141 ( V_135 , V_142 , & V_137 ) ;
if ( V_10 != 0 )
return V_139 ;
V_100 = V_137 . V_143 ;
if ( V_100 == 0 )
V_122 = V_126 ;
else if ( V_100 < 500 )
V_122 = V_127 ;
else if ( V_100 < 1800 )
V_122 = V_128 ;
else
V_122 = V_129 ;
if ( V_2 -> V_144 == V_122 )
return V_139 ;
V_2 -> V_144 = V_122 ;
if ( V_2 -> V_145 < 1 )
return V_139 ;
F_35 ( & V_2 -> V_146 , 0 ) ;
return V_139 ;
}
static void F_36 ( struct V_1 * V_2 , int V_147 )
{
F_3 ( & V_148 ) ;
if ( V_2 -> V_149 == V_147 ) {
F_6 ( & V_148 ) ;
return;
}
V_2 -> V_149 = V_147 ;
if ( V_147 ) {
F_35 ( & V_2 -> V_146 , V_150 * V_151 ) ;
F_13 ( V_2 , V_27 ) ;
V_2 -> V_99 = NULL ;
} else {
F_37 ( & V_2 -> V_146 ) ;
}
F_6 ( & V_148 ) ;
}
static void F_38 ( struct V_1 * V_2 , const char * V_8 )
{
V_2 -> V_99 = V_8 ;
F_32 ( & V_2 -> V_123 . V_6 -> V_130 , NULL , L_8 ) ;
F_39 ( V_2 -> V_6 , L_9 , V_8 ) ;
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
F_30 ( V_2 , V_126 ) ;
F_36 ( V_2 , 0 ) ;
}
static void F_40 ( struct V_152 * V_146 )
{
struct V_1 * V_2 = F_34 ( V_146 , struct V_1 ,
V_146 . V_146 ) ;
int V_10 ;
int error ;
int V_124 ;
if ( V_2 -> V_145 > 0 && ( V_2 -> V_144 != V_2 -> V_122 ) ) {
F_32 ( & V_2 -> V_123 . V_6 -> V_130 , NULL , L_10 ) ;
F_30 ( V_2 , V_2 -> V_144 ) ;
}
if ( ! V_2 -> V_149 )
return;
V_10 = F_13 ( V_2 , V_27 ) ;
if ( V_10 < 0 ) {
F_38 ( V_2 , L_11 ) ;
return;
}
V_124 = F_13 ( V_2 , V_57 ) ;
if ( V_124 < 0 ) {
F_38 ( V_2 , L_12 ) ;
return;
}
error = F_13 ( V_2 , V_41 ) ;
if ( error < 0 ) {
F_38 ( V_2 , L_12 ) ;
return;
}
if ( V_124 ) {
switch ( error ) {
case 0 :
break;
case 6 :
F_39 ( V_2 -> V_6 , L_13 ) ;
break;
case 3 :
F_39 ( V_2 -> V_6 , L_14 ) ;
break;
case 1 :
F_38 ( V_2 ,
L_15 ) ;
return;
case 2 :
F_38 ( V_2 , L_16 ) ;
return;
case 4 :
F_38 ( V_2 ,
L_17 ) ;
return;
case 5 :
F_38 ( V_2 ,
L_18 ) ;
return;
case 7 :
F_38 ( V_2 , L_12 ) ;
return;
}
} else {
switch ( error ) {
case 0 :
break;
case 2 :
F_39 ( V_2 -> V_6 , L_19 ) ;
break;
case 3 :
F_39 ( V_2 -> V_6 , L_20 ) ;
break;
case 6 :
F_39 ( V_2 -> V_6 , L_13 ) ;
break;
case 7 :
F_39 ( V_2 -> V_6 , L_21 ) ;
break;
case 1 :
F_38 ( V_2 ,
L_15 ) ;
return;
case 4 :
F_38 ( V_2 ,
L_17 ) ;
return;
case 5 :
F_38 ( V_2 ,
L_18 ) ;
return;
}
}
F_35 ( & V_2 -> V_146 , V_150 * V_151 ) ;
}
static int F_41 ( struct V_134 * V_135 ,
enum V_153 V_154 ,
union V_136 * V_9 )
{
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
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
static int F_42 ( struct V_1 * V_2 )
{
int V_10 ;
int V_81 ;
char V_163 [ 8 ] ;
V_2 -> V_123 . V_164 = V_2 -> V_164 ;
V_2 -> V_123 . type = V_165 ;
V_2 -> V_123 . V_166 = V_167 ;
V_2 -> V_123 . V_168 = F_5 ( V_167 ) ;
V_2 -> V_123 . V_141 = F_41 ;
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
V_2 -> V_162 = F_43 ( V_169 ,
L_24 ,
V_170 [ V_81 ] , V_163 ,
F_16 ( V_2 ) ) ;
if ( ! V_2 -> V_162 ) {
F_39 ( V_2 -> V_6 , L_25 ) ;
return - V_171 ;
}
V_10 = F_44 ( V_2 -> V_6 , & V_2 -> V_123 ) ;
if ( V_10 ) {
F_45 ( V_2 -> V_162 ) ;
return V_10 ;
}
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
V_2 -> V_149 = 0 ;
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
F_37 ( & V_2 -> V_146 ) ;
F_47 ( & V_2 -> V_123 ) ;
F_45 ( V_2 -> V_162 ) ;
}
static T_2 F_48 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
char * V_15 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
enum V_25 V_26 ;
int V_10 ;
if ( strcmp ( V_174 -> V_174 . V_164 , L_26 ) == 0 )
V_26 = V_30 ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_27 ) == 0 )
V_26 = V_36 ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_28 ) == 0 )
V_26 = V_39 ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_29 ) == 0 )
V_26 = V_41 ;
else
return - V_21 ;
V_10 = F_13 ( V_2 , V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_15 , L_30 , V_10 ) ;
}
static T_2 F_50 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
const char * V_15 ,
T_3 V_175 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
int V_10 = 0 ;
if ( strncmp ( V_15 , L_31 , 4 ) == 0 )
F_36 ( V_2 , 1 ) ;
else if ( strncmp ( V_15 , L_32 , 3 ) == 0 )
F_36 ( V_2 , 0 ) ;
else
V_10 = F_13 ( V_2 , V_27 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_175 ;
}
static T_2 F_51 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
char * V_15 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
if ( V_2 -> V_99 )
return sprintf ( V_15 , L_9 , V_2 -> V_99 ) ;
if ( V_2 -> V_149 )
return sprintf ( V_15 , L_33 ) ;
return sprintf ( V_15 , L_34 ) ;
}
static T_2 F_52 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
const char * V_15 ,
T_3 V_175 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
enum V_121 V_122 ;
int V_10 = 0 ;
if ( strncmp ( V_15 , L_31 , 4 ) == 0 ) {
if ( V_2 -> V_145 < 0 )
return - V_110 ;
V_2 -> V_145 = 1 ;
V_122 = V_2 -> V_144 ;
} else if ( strncmp ( V_15 , L_32 , 3 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_122 = V_126 ;
} else if ( strncmp ( V_15 , L_35 , 4 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_122 = V_127 ;
} else if ( strncmp ( V_15 , L_36 , 4 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_122 = V_128 ;
} else if ( strncmp ( V_15 , L_37 , 9 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_122 = V_129 ;
} else if ( strncmp ( V_15 , L_38 , 5 ) == 0 ) {
if ( V_2 -> V_145 > 0 )
V_2 -> V_145 = 0 ;
V_122 = V_125 ;
} else if ( strncmp ( V_15 , L_39 , 5 ) == 0 ) {
F_17 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_145 <= 0 )
return V_175 ;
V_2 -> V_145 = 1 ;
V_122 = V_2 -> V_144 ;
} else {
return - V_21 ;
}
V_10 = F_30 ( V_2 , V_122 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_175 ;
}
static T_2 F_53 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
char * V_15 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
T_2 V_10 = 0 ;
if ( V_2 -> V_145 > 0 )
V_10 += sprintf ( V_15 + V_10 , L_40 ) ;
switch ( V_2 -> V_122 ) {
case V_126 :
V_10 += sprintf ( V_15 + V_10 , L_32 ) ;
break;
case V_127 :
V_10 += sprintf ( V_15 + V_10 , L_35 ) ;
break;
case V_128 :
V_10 += sprintf ( V_15 + V_10 , L_36 ) ;
break;
case V_129 :
V_10 += sprintf ( V_15 + V_10 , L_37 ) ;
break;
case V_125 :
V_10 += sprintf ( V_15 + V_10 , L_38 ) ;
break;
}
if ( V_2 -> V_145 > 0 )
V_10 += sprintf ( V_15 + V_10 , L_41 ) ;
V_10 += sprintf ( V_15 + V_10 , L_42 ) ;
return V_10 ;
}
static T_2 F_54 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
char * V_15 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
if ( V_2 -> V_145 < 0 )
return - V_21 ;
switch ( V_2 -> V_144 ) {
case V_126 :
return sprintf ( V_15 , L_34 ) ;
case V_127 :
return sprintf ( V_15 , L_43 ) ;
case V_128 :
return sprintf ( V_15 , L_44 ) ;
case V_129 :
return sprintf ( V_15 , L_45 ) ;
case V_125 :
return sprintf ( V_15 , L_46 ) ;
}
return - V_21 ;
}
static T_2 F_55 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
const char * V_15 ,
T_3 V_175 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
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
return V_175 ;
}
static T_2 F_56 ( struct V_1 * V_2 ,
T_1 V_3 ,
char * V_15 )
{
int V_10 = F_1 ( V_2 , V_3 ) ;
if ( V_10 < 0 )
return sprintf ( V_15 , L_48 , V_3 , V_10 ) ;
return sprintf ( V_15 , L_49 , V_3 , V_10 ) ;
}
static T_2 F_57 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
char * V_15 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
T_2 V_10 = 0 ;
V_10 += F_56 ( V_2 , V_28 , V_15 + V_10 ) ;
V_10 += F_56 ( V_2 , V_45 , V_15 + V_10 ) ;
V_10 += F_56 ( V_2 , V_62 , V_15 + V_10 ) ;
V_10 += F_56 ( V_2 , V_71 , V_15 + V_10 ) ;
V_10 += F_56 ( V_2 , V_94 , V_15 + V_10 ) ;
return V_10 ;
}
static T_2 F_58 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
const char * V_15 ,
T_3 V_175 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
long V_9 ;
int V_10 ;
if ( F_59 ( V_15 , 10 , & V_9 ) < 0 )
return - V_21 ;
if ( strcmp ( V_174 -> V_174 . V_164 , L_50 ) == 0 )
V_10 = F_18 ( V_2 , V_9 ) ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_51 ) == 0 )
V_10 = F_20 ( V_2 , V_9 ) ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_52 ) == 0 )
V_10 = F_22 ( V_2 , V_9 ) ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_53 ) == 0 )
V_10 = F_24 ( V_2 , V_9 ) ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_54 ) == 0 )
V_10 = F_26 ( V_2 , V_9 ) ;
else
return - V_21 ;
if ( V_10 < 0 )
return V_10 ;
return V_175 ;
}
static T_2 F_60 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
char * V_15 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
int V_10 ;
if ( strcmp ( V_174 -> V_174 . V_164 , L_50 ) == 0 )
V_10 = F_19 ( V_2 ) ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_51 ) == 0 )
V_10 = F_21 ( V_2 ) ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_52 ) == 0 )
V_10 = F_23 ( V_2 ) ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_53 ) == 0 )
V_10 = F_25 ( V_2 ) ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_54 ) == 0 )
V_10 = F_27 ( V_2 ) ;
else
return - V_21 ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_15 , L_30 , V_10 ) ;
}
static T_2 F_61 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
const char * V_15 ,
T_3 V_175 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
enum V_25 V_26 ;
long V_9 ;
int V_10 ;
if ( F_59 ( V_15 , 10 , & V_9 ) < 0 )
return - V_21 ;
if ( strcmp ( V_174 -> V_174 . V_164 , L_55 ) == 0 )
V_26 = V_9 ? V_47 :
V_48 ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_56 ) == 0 )
V_26 = V_9 ? V_55 :
V_56 ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_57 ) == 0 )
V_26 = V_9 ? V_68 :
V_69 ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_58 ) == 0 )
V_26 = V_9 ? V_34 :
V_35 ;
else
return - V_21 ;
V_10 = F_13 ( V_2 , V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
return V_175 ;
}
static T_2 F_62 ( struct V_172 * V_6 ,
struct V_173 * V_174 ,
char * V_15 )
{
struct V_134 * V_135 = F_49 ( V_6 ) ;
struct V_1 * V_2 = F_34 ( V_135 , struct V_1 ,
V_123 ) ;
enum V_25 V_26 ;
int V_10 ;
if ( strcmp ( V_174 -> V_174 . V_164 , L_55 ) == 0 )
V_26 = V_44 ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_56 ) == 0 )
V_26 = V_53 ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_57 ) == 0 )
V_26 = V_66 ;
else if ( strcmp ( V_174 -> V_174 . V_164 , L_58 ) == 0 )
V_26 = V_32 ;
else
return - V_21 ;
V_10 = F_13 ( V_2 , V_26 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_15 , L_30 , V_10 ) ;
}
static int F_63 ( struct V_1 * V_2 )
{
return F_64 ( & V_2 -> V_123 . V_6 -> V_130 ,
& V_176 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_66 ( & V_2 -> V_123 . V_6 -> V_130 , & V_176 ) ;
}
static int F_67 ( struct V_4 * V_5 ,
const struct V_177 * V_178 )
{
int V_10 ;
int V_179 ;
char * V_164 ;
struct V_1 * V_2 ;
struct V_180 * V_181 = V_5 -> V_6 . V_182 ;
struct V_183 * V_184 = V_5 -> V_6 . V_185 ;
if ( ! V_181 && ! V_184 ) {
F_39 ( & V_5 -> V_6 , L_59 ) ;
return - V_12 ;
}
F_3 ( & V_186 ) ;
V_179 = F_68 ( & V_187 , V_5 , 0 , 0 , V_169 ) ;
F_6 ( & V_186 ) ;
if ( V_179 < 0 )
return V_179 ;
V_164 = F_43 ( V_169 , L_60 , V_178 -> V_164 , V_179 ) ;
if ( ! V_164 ) {
F_39 ( & V_5 -> V_6 , L_61 ) ;
V_10 = - V_171 ;
goto V_188;
}
V_2 = F_69 ( & V_5 -> V_6 , sizeof( * V_2 ) , V_169 ) ;
if ( ! V_2 ) {
F_39 ( & V_5 -> V_6 , L_62 ) ;
V_10 = - V_171 ;
goto V_189;
}
if ( V_181 ) {
V_2 -> V_140 = F_70 ( V_181 , L_63 ) ;
if ( ! V_2 -> V_140 )
return - V_190 ;
}
else if ( V_184 -> V_191 )
V_2 -> V_140 = F_71 ( V_184 -> V_191 ) ;
else
V_2 -> V_140 = NULL ;
F_72 ( V_5 , V_2 ) ;
V_2 -> V_178 = V_179 ;
V_2 -> V_6 = & V_5 -> V_6 ;
V_2 -> V_81 = V_178 -> V_192 ;
V_2 -> V_164 = V_164 ;
V_2 -> V_122 = V_126 ;
V_2 -> V_144 = V_126 ;
V_2 -> V_149 = 0 ;
V_2 -> V_145 = 0 ;
if ( V_181 ) {
V_10 = F_73 ( V_181 , L_64 ,
& V_2 -> V_108 . V_116 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_73 ( V_181 , L_65 ,
& V_2 -> V_108 . V_117 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_73 ( V_181 , L_66 ,
& V_2 -> V_108 . V_118 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_73 ( V_181 , L_67 ,
& V_2 -> V_108 . V_119 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_73 ( V_181 , L_68 ,
& V_2 -> V_108 . V_120 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_73 ( V_181 , L_69 ,
& V_2 -> V_108 . V_109 ) ;
if ( V_10 )
return V_10 ;
} else {
memcpy ( & V_2 -> V_108 , V_184 , sizeof( V_2 -> V_108 ) ) ;
}
F_17 ( V_2 ) ;
V_10 = F_42 ( V_2 ) ;
if ( V_10 ) {
F_39 ( V_2 -> V_6 , L_70 , V_10 ) ;
goto V_189;
}
V_10 = F_63 ( V_2 ) ;
if ( V_10 ) {
F_39 ( V_2 -> V_6 , L_71 , V_10 ) ;
goto V_193;
}
V_10 = F_28 ( V_2 ) ;
if ( V_10 ) {
F_39 ( V_2 -> V_6 , L_72 , V_10 ) ;
goto V_194;
}
if ( V_2 -> V_140 ) {
V_2 -> V_132 . V_195 = F_33 ;
V_10 = F_74 ( & V_2 -> V_132 ) ;
if ( V_10 ) {
F_39 ( V_2 -> V_6 , L_73 , V_10 ) ;
goto V_196;
}
F_33 ( & V_2 -> V_132 , V_138 , V_2 -> V_140 ) ;
F_30 ( V_2 , V_2 -> V_144 ) ;
V_2 -> V_145 = 1 ;
F_75 ( V_2 -> V_6 , L_74 ) ;
} else {
V_2 -> V_145 = - 1 ;
F_75 ( V_2 -> V_6 , L_75 ) ;
}
F_76 ( & V_2 -> V_146 , F_40 ) ;
F_36 ( V_2 , 1 ) ;
F_75 ( V_2 -> V_6 , L_76 ) ;
return 0 ;
V_196:
V_194:
F_65 ( V_2 ) ;
V_193:
F_46 ( V_2 ) ;
V_189:
F_45 ( V_164 ) ;
V_188:
F_3 ( & V_186 ) ;
F_77 ( & V_187 , V_179 ) ;
F_6 ( & V_186 ) ;
return V_10 ;
}
static int F_78 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_79 ( V_5 ) ;
if ( V_2 -> V_140 )
F_80 ( & V_2 -> V_132 ) ;
F_65 ( V_2 ) ;
F_46 ( V_2 ) ;
F_17 ( V_2 ) ;
F_3 ( & V_186 ) ;
F_77 ( & V_187 , V_2 -> V_178 ) ;
F_6 ( & V_186 ) ;
F_75 ( V_2 -> V_6 , L_77 ) ;
F_45 ( V_2 -> V_164 ) ;
return 0 ;
}
