static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
return true ;
}
return false ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
return false ;
}
return true ;
}
static int F_3 ( struct V_15 * V_16 , unsigned int V_3 ,
unsigned int V_17 , unsigned int V_18 , int V_19 ,
int V_20 )
{
unsigned int V_21 ;
int V_22 = V_20 ;
int V_23 = F_4 ( V_16 -> V_24 , V_3 , & V_21 ) ;
while ( ( V_21 & V_17 ) != V_18 && V_22 && ! V_23 ) {
F_5 ( V_19 , V_19 * 2 ) ;
V_23 = F_4 ( V_16 -> V_24 , V_3 , & V_21 ) ;
V_22 -- ;
}
if ( ( V_21 & V_17 ) != V_18 ) {
F_6 ( V_16 -> V_2 ,
L_1 ,
V_25 , V_3 , V_21 , V_18 , V_23 , V_17 ,
( V_20 - V_22 ) * V_19 ) ;
V_23 = - 1 ;
}
return V_23 ;
}
static int F_7 ( struct V_26 * V_27 ,
struct V_28 * V_29 , int V_30 )
{
struct V_15 * V_16 = F_8 ( V_27 -> V_31 ) ;
unsigned int V_3 = V_8 ;
unsigned int V_17 ;
switch ( F_9 ( V_27 -> V_3 , V_27 -> V_32 ) ) {
case F_9 ( V_33 , 7 ) :
V_17 = V_34 ;
break;
case F_9 ( V_33 , 6 ) :
V_17 = V_35 ;
break;
case F_9 ( V_36 , 7 ) :
V_17 = V_37 ;
break;
case F_9 ( V_36 , 6 ) :
V_17 = V_38 ;
break;
case F_9 ( V_39 , 7 ) :
V_17 = V_40 ;
break;
case F_9 ( V_39 , 6 ) :
V_17 = V_41 ;
break;
case F_9 ( V_42 , 7 ) :
V_17 = V_43 ;
V_3 = V_7 ;
break;
default:
F_6 ( V_27 -> V_31 -> V_2 , L_2 ,
V_27 -> V_44 , V_25 ) ;
return - V_45 ;
}
switch ( V_30 ) {
case V_46 :
return F_3 ( V_16 , V_3 , V_17 , V_17 , 5000 , 100 ) ;
case V_47 :
return F_3 ( V_16 , V_3 , V_17 , 0 , 5000 , 100 ) ;
default:
F_10 ( V_27 -> V_31 -> V_2 ,
L_3 ,
V_30 , V_27 -> V_44 ) ;
}
return 0 ;
}
static int F_11 ( struct V_26 * V_27 ,
struct V_28 * V_29 , int V_30 )
{
struct V_48 * V_31 = V_27 -> V_31 ;
struct V_15 * V_16 = F_8 ( V_31 ) ;
switch ( V_30 ) {
case V_46 :
F_12 ( V_31 , V_49 ,
V_50 ,
V_16 -> V_51 . V_52 <<
V_53 ) ;
F_10 ( V_31 -> V_2 , L_4 , V_25 ) ;
break;
case V_54 :
F_12 ( V_31 , V_49 ,
V_50 , 0 ) ;
F_10 ( V_31 -> V_2 , L_5 , V_25 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_48 * V_31 )
{
int V_23 = 0 ;
struct V_15 * V_16 = F_8 ( V_31 ) ;
if ( V_16 -> V_51 . V_55 & V_56 )
V_23 = F_14 (
V_31 , V_57 ,
F_15 ( V_57 ) ) ;
else
V_23 = F_14 (
V_31 , V_58 ,
F_15 ( V_58 ) ) ;
return V_23 ;
}
static int F_16 ( struct V_48 * V_31 )
{
struct V_59 * V_60 = & V_31 -> V_60 ;
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_23 = 0 ;
if ( V_16 -> V_51 . V_55 & V_56 ) {
V_23 = F_17 (
V_60 , V_61 ,
F_15 ( V_61 ) ) ;
if ( V_23 )
return V_23 ;
V_23 = F_18 ( V_60 , V_62 ,
F_15 ( V_62 ) ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = F_17 (
V_60 , V_63 ,
F_15 ( V_63 ) ) ;
if ( V_23 )
return V_23 ;
V_23 = F_18 ( V_60 , V_64 ,
F_15 ( V_64 ) ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_19 ( struct V_48 * V_31 ,
struct V_65 * V_66 )
{
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_67 = 0 ;
int V_68 ;
F_12 ( V_31 , V_69 ,
V_70 , V_71 ) ;
F_12 ( V_31 , V_72 ,
V_73 , V_74 ) ;
for ( V_68 = 0 ; V_68 < F_15 ( V_75 ) ; V_68 ++ ) {
if ( V_75 [ V_68 ] . V_76 == F_20 ( V_66 ) &&
V_75 [ V_68 ] . V_77 == V_16 -> V_78 )
break;
}
if ( V_68 == F_15 ( V_75 ) ) {
F_6 ( V_31 -> V_2 , L_6 ,
V_25 , F_20 ( V_66 ) ) ;
return - V_45 ;
}
F_12 ( V_31 , V_79 , V_80 ,
( V_75 [ V_68 ] . V_81 << 4 ) | 0x01 ) ;
F_21 ( V_31 , V_82 , V_75 [ V_68 ] . V_83 ) ;
F_21 ( V_31 , V_84 ,
V_75 [ V_68 ] . V_85 >> 8 ) ;
F_21 ( V_31 , V_86 ,
V_75 [ V_68 ] . V_85 & 0xff ) ;
F_12 ( V_31 , V_87 , V_80 ,
V_75 [ V_68 ] . V_88 ) ;
F_12 ( V_31 , V_89 , V_80 ,
V_75 [ V_68 ] . V_90 ) ;
F_21 ( V_31 , V_91 , V_75 [ V_68 ] . V_92 >> 8 ) ;
F_21 ( V_31 , V_93 , V_75 [ V_68 ] . V_92 & 0xff ) ;
F_12 ( V_31 , V_94 , V_80 ,
V_75 [ V_68 ] . V_95 ? V_75 [ V_68 ] . V_95 : 1 ) ;
F_12 ( V_31 , V_96 , V_80 ,
V_75 [ V_68 ] . V_97 ? V_75 [ V_68 ] . V_97 : 1 ) ;
F_21 ( V_31 , V_98 , V_75 [ V_68 ] . V_99 ) ;
V_67 = ( V_75 [ V_68 ] . V_92 * V_75 [ V_68 ] . V_90 )
/ F_22 ( V_66 ) ;
if ( V_67 == 0 ) {
F_6 ( V_31 -> V_2 , L_7 ,
V_25 ) ;
return - V_45 ;
}
F_12 ( V_31 , V_100 ,
V_80 , V_67 ) ;
V_16 -> V_101 = V_68 ;
F_10 ( V_31 -> V_2 ,
L_8 ,
V_75 [ V_68 ] . V_83 , V_75 [ V_68 ] . V_85 ,
V_75 [ V_68 ] . V_81 , V_75 [ V_68 ] . V_92 ,
V_75 [ V_68 ] . V_88 , V_75 [ V_68 ] . V_90 ,
V_75 [ V_68 ] . V_99 , V_75 [ V_68 ] . V_95 ,
V_75 [ V_68 ] . V_97 , V_67 ) ;
return 0 ;
}
static int F_23 ( struct V_102 * V_103 ,
struct V_65 * V_66 ,
struct V_104 * V_105 )
{
struct V_48 * V_31 = V_105 -> V_31 ;
T_1 V_106 = 0 ;
F_10 ( V_31 -> V_2 , L_9 ,
V_25 , F_24 ( V_66 ) , F_25 ( V_66 ) ,
F_20 ( V_66 ) ) ;
switch ( F_25 ( V_66 ) ) {
case 16 :
break;
case 20 :
V_106 = ( V_107 <<
V_108 ) ;
break;
case 24 :
V_106 = ( V_109 <<
V_108 ) ;
break;
case 32 :
V_106 = ( V_110 <<
V_108 ) ;
break;
default:
F_6 ( V_31 -> V_2 , L_10 ,
V_25 , F_24 ( V_66 ) ) ;
return - V_45 ;
}
F_12 ( V_31 , V_111 ,
V_112 ,
V_106 ) ;
return F_19 ( V_31 , V_66 ) ;
}
static int F_26 ( struct V_104 * V_113 , int V_114 )
{
struct V_48 * V_31 = V_113 -> V_31 ;
if ( V_114 ) {
F_12 ( V_31 , V_115 ,
V_116 ,
V_116 ) ;
} else {
F_12 ( V_31 , V_115 ,
V_116 , 0x0 ) ;
}
return 0 ;
}
static int F_27 ( struct V_104 * V_113 ,
unsigned int V_117 )
{
struct V_48 * V_31 = V_113 -> V_31 ;
T_1 V_118 = 0 ;
T_1 V_119 = 0 ;
T_1 V_120 = 0 ;
F_10 ( V_31 -> V_2 , L_11 , V_25 , V_117 ) ;
switch ( V_117 & V_121 ) {
case V_122 :
V_118 |= V_123 | V_124 ;
break;
default:
F_28 ( V_31 -> V_2 , L_12 ) ;
return - V_45 ;
}
switch ( V_117 & V_125 ) {
case V_126 :
break;
case V_127 :
V_120 = 0x1 ;
case V_128 :
switch ( V_117 & V_129 ) {
case V_130 :
V_119 |= V_131 ;
break;
case V_132 :
break;
default:
return - V_45 ;
}
V_118 |= ( V_133 <<
V_134 ) ;
break;
case V_135 :
V_118 |= ( V_136 <<
V_134 ) ;
break;
case V_137 :
V_118 |= ( V_138 <<
V_134 ) ;
break;
default:
F_6 ( V_31 -> V_2 , L_13 ) ;
return - V_45 ;
}
F_12 ( V_31 , V_111 ,
V_139 |
V_140 ,
V_118 ) ;
F_12 ( V_31 , V_141 ,
V_142 ,
V_120 ) ;
F_12 ( V_31 , V_72 ,
V_131 ,
V_119 ) ;
return 0 ;
}
static int F_29 ( struct V_104 * V_113 ,
int V_143 , unsigned int V_144 , int V_145 )
{
struct V_48 * V_31 = V_113 -> V_31 ;
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_68 ;
F_10 ( V_31 -> V_2 , L_14 ,
V_25 , V_143 , V_144 , V_145 ) ;
for ( V_68 = 0 ; V_75 [ V_68 ] . V_77 != V_144 ; V_68 ++ ) {
if ( V_68 == F_15 ( V_75 ) ) {
F_6 ( V_16 -> V_2 , L_15 ,
V_25 , V_144 ) ;
return - V_45 ;
}
}
F_12 ( V_31 , V_69 , V_146 ,
V_143 << V_147 ) ;
V_16 -> V_78 = V_144 ;
return 0 ;
}
static int F_30 ( struct V_148 * V_149 ,
unsigned long V_30 , void * V_106 )
{
struct V_150 * V_151 =
F_31 ( V_149 , struct V_150 , V_149 ) ;
struct V_15 * V_16 = V_151 -> V_16 ;
if ( V_30 & V_152 ) {
if ( F_32 ( V_16 -> V_51 . V_153 ) )
F_33 ( V_16 -> V_51 . V_153 , 0 ) ;
F_34 ( V_16 -> V_24 ) ;
F_10 ( V_16 -> V_2 , L_16 , V_25 ) ;
}
return 0 ;
}
static void F_35 ( struct V_48 * V_31 )
{
struct V_15 * V_16 = F_8 ( V_31 ) ;
T_1 V_17 = V_154 ;
T_1 V_155 = V_154 ;
F_10 ( V_31 -> V_2 , L_17 ,
V_75 [ V_16 -> V_101 ] . V_76 ) ;
F_12 ( V_31 , V_79 , V_17 , V_155 ) ;
F_36 ( 10 ) ;
F_12 ( V_31 , V_87 , V_17 , V_155 ) ;
F_12 ( V_31 , V_89 , V_17 , V_155 ) ;
if ( V_75 [ V_16 -> V_101 ] . V_95 )
F_12 ( V_31 , V_94 , V_17 , V_155 ) ;
if ( V_75 [ V_16 -> V_101 ] . V_97 )
F_12 ( V_31 , V_96 , V_17 , V_155 ) ;
F_12 ( V_31 , V_100 , V_17 , V_155 ) ;
}
static void F_37 ( struct V_48 * V_31 )
{
T_1 V_17 = V_154 ;
T_1 V_156 = 0 ;
F_10 ( V_31 -> V_2 , L_18 ) ;
F_12 ( V_31 , V_100 , V_17 , V_156 ) ;
F_12 ( V_31 , V_96 , V_17 , V_156 ) ;
F_12 ( V_31 , V_94 , V_17 , V_156 ) ;
F_12 ( V_31 , V_89 , V_17 , V_156 ) ;
F_12 ( V_31 , V_87 , V_17 , V_156 ) ;
F_12 ( V_31 , V_79 , V_17 , V_156 ) ;
}
static int F_38 ( struct V_48 * V_31 )
{
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_23 = 0 ;
V_23 = F_39 ( F_15 ( V_16 -> V_157 ) ,
V_16 -> V_157 ) ;
if ( V_23 )
return V_23 ;
if ( F_32 ( V_16 -> V_51 . V_153 ) ) {
F_33 ( V_16 -> V_51 . V_153 , 1 ) ;
F_40 ( 100 ) ;
}
F_41 ( V_16 -> V_24 , false ) ;
V_23 = F_42 ( V_16 -> V_24 ) ;
if ( V_23 != 0 ) {
F_6 ( V_31 -> V_2 ,
L_19 , V_23 ) ;
F_41 ( V_16 -> V_24 , true ) ;
F_43 ( F_15 ( V_16 -> V_157 ) ,
V_16 -> V_157 ) ;
return V_23 ;
}
return 0 ;
}
static int F_44 ( struct V_48 * V_31 )
{
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_23 = 0 ;
F_41 ( V_16 -> V_24 , true ) ;
V_23 = F_43 ( F_15 ( V_16 -> V_157 ) ,
V_16 -> V_157 ) ;
return V_23 ;
}
static int F_45 ( struct V_48 * V_31 ,
enum V_158 V_159 )
{
F_10 ( V_31 -> V_2 , L_20 , V_25 ,
V_31 -> V_60 . V_160 , V_159 ) ;
switch ( V_159 ) {
case V_161 :
break;
case V_162 :
if ( V_31 -> V_60 . V_160 == V_163 )
F_35 ( V_31 ) ;
break;
case V_163 :
switch ( V_31 -> V_60 . V_160 ) {
case V_164 :
F_38 ( V_31 ) ;
break;
case V_162 :
F_37 ( V_31 ) ;
break;
default:
F_46 () ;
}
break;
case V_164 :
if ( V_31 -> V_60 . V_160 == V_163 )
F_44 ( V_31 ) ;
break;
}
V_31 -> V_60 . V_160 = V_159 ;
return 0 ;
}
static int F_47 ( struct V_48 * V_31 )
{
F_45 ( V_31 , V_164 ) ;
return 0 ;
}
static int F_48 ( struct V_48 * V_31 )
{
F_45 ( V_31 , V_163 ) ;
return 0 ;
}
static int F_49 ( struct V_48 * V_31 )
{
int V_23 = 0 ;
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_68 ;
F_10 ( V_16 -> V_2 , L_21 , V_25 ) ;
V_16 = F_8 ( V_31 ) ;
V_16 -> V_31 = V_31 ;
for ( V_68 = 0 ; V_68 < F_15 ( V_16 -> V_157 ) ; V_68 ++ ) {
V_16 -> V_151 [ V_68 ] . V_149 . V_165 =
F_30 ;
V_16 -> V_151 [ V_68 ] . V_16 = V_16 ;
V_23 = F_50 ( V_16 -> V_157 [ V_68 ] . V_166 ,
& V_16 -> V_151 [ V_68 ] . V_149 ) ;
if ( V_23 ) {
F_6 ( V_31 -> V_2 ,
L_22 ,
V_23 ) ;
return V_23 ;
}
}
F_41 ( V_16 -> V_24 , true ) ;
F_34 ( V_16 -> V_24 ) ;
V_23 = F_13 ( V_31 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_16 ( V_31 ) ;
return V_23 ;
}
static int F_51 ( struct V_48 * V_31 )
{
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_68 ;
F_45 ( V_31 , V_164 ) ;
for ( V_68 = 0 ; V_68 < F_15 ( V_16 -> V_157 ) ; V_68 ++ )
F_52 ( V_16 -> V_157 [ V_68 ] . V_166 ,
& V_16 -> V_151 [ V_68 ] . V_149 ) ;
return 0 ;
}
static void F_53 ( struct V_15 * V_16 )
{
struct V_167 * V_168 = V_16 -> V_2 -> V_169 ;
unsigned int V_170 = V_171 ;
int V_23 ;
F_54 ( V_168 , L_23 , & V_170 ) ;
switch ( V_170 ) {
case V_171 :
case V_172 :
case V_173 :
V_16 -> V_51 . V_52 = V_170 ;
break;
default:
F_6 ( V_16 -> V_2 ,
L_24 ,
V_170 ) ;
V_16 -> V_51 . V_52 = V_171 ;
}
V_23 = F_55 ( V_168 , L_25 , 0 ) ;
if ( V_23 > 0 )
V_16 -> V_51 . V_153 = V_23 ;
}
static void F_53 ( struct V_15 * V_16 )
{
}
static void F_56 ( struct V_15 * V_16 )
{
int V_23 , V_68 ;
F_57 ( V_16 -> V_2 , V_16 ) ;
if ( F_58 ( V_16 -> V_2 ) )
memcpy ( & V_16 -> V_51 , F_58 ( V_16 -> V_2 ) ,
sizeof( V_16 -> V_51 ) ) ;
else if ( V_16 -> V_2 -> V_169 )
F_53 ( V_16 ) ;
if ( V_16 -> V_51 . V_153 ) {
V_23 = F_59 ( V_16 -> V_2 ,
V_16 -> V_51 . V_153 ,
V_174 ,
L_26 ) ;
if ( V_23 < 0 ) {
F_6 ( V_16 -> V_2 , L_27 ) ;
return;
}
}
for ( V_68 = 0 ; V_68 < F_15 ( V_16 -> V_157 ) ; V_68 ++ )
V_16 -> V_157 [ V_68 ] . V_175 = V_176 [ V_68 ] ;
V_23 = F_60 ( V_16 -> V_2 ,
F_15 ( V_16 -> V_157 ) ,
V_16 -> V_157 ) ;
if ( V_23 != 0 )
F_6 ( V_16 -> V_2 , L_28 , V_23 ) ;
}
static int F_61 ( struct V_177 * V_178 ,
const struct V_179 * V_180 )
{
struct V_15 * V_16 ;
int V_23 ;
const struct V_181 * V_181 ;
F_10 ( & V_178 -> V_2 , L_29 , V_25 ,
V_180 -> V_44 , ( int ) V_180 -> V_182 ) ;
V_181 = & V_183 ;
V_16 = F_62 ( & V_178 -> V_2 , sizeof( * V_16 ) , V_184 ) ;
if ( V_16 == NULL )
return - V_185 ;
V_16 -> V_24 = F_63 ( V_178 , V_181 ) ;
if ( F_64 ( V_16 -> V_24 ) ) {
V_23 = F_65 ( V_16 -> V_24 ) ;
F_6 ( & V_178 -> V_2 , L_30 ,
V_23 ) ;
return V_23 ;
}
V_16 -> V_2 = & V_178 -> V_2 ;
V_16 -> V_51 . V_55 = V_180 -> V_182 ;
F_56 ( V_16 ) ;
return F_66 ( & V_178 -> V_2 , & V_186 ,
V_187 ,
F_15 ( V_187 ) ) ;
}
static int F_67 ( struct V_177 * V_178 )
{
F_68 ( & V_178 -> V_2 ) ;
return 0 ;
}
