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
int V_67 = F_20 ( V_66 ) ;
int V_68 = 0 ;
int V_69 = - 1 ;
int V_70 ;
F_12 ( V_31 , V_71 ,
V_72 , V_73 ) ;
F_12 ( V_31 , V_74 ,
V_75 , V_76 ) ;
for ( V_70 = 0 ; V_70 < F_15 ( V_77 ) ; V_70 ++ ) {
if ( V_77 [ V_70 ] . V_78 == F_21 ( V_66 ) &&
V_77 [ V_70 ] . V_79 == V_16 -> V_80 ) {
int V_81 = ( V_77 [ V_70 ] . V_82 * V_77 [ V_70 ] . V_83 ) %
F_20 ( V_66 ) ;
int V_84 = ( V_77 [ V_70 ] . V_82 * V_77 [ V_70 ] . V_83 ) /
F_20 ( V_66 ) ;
if ( V_81 < V_67 && V_84 > 0 ) {
V_69 = V_70 ;
V_68 = V_84 ;
V_67 = V_81 ;
}
}
}
if ( V_69 == - 1 ) {
F_6 ( V_31 -> V_2 ,
L_6 ,
V_25 , F_21 ( V_66 ) ) ;
return - V_45 ;
}
if ( V_67 != 0 ) {
F_22 ( V_31 -> V_2 , L_7 ) ;
}
V_70 = V_69 ;
F_12 ( V_31 , V_85 , V_86 ,
( V_77 [ V_70 ] . V_87 << 4 ) | 0x01 ) ;
F_23 ( V_31 , V_88 , V_77 [ V_70 ] . V_89 ) ;
F_23 ( V_31 , V_90 ,
V_77 [ V_70 ] . V_91 >> 8 ) ;
F_23 ( V_31 , V_92 ,
V_77 [ V_70 ] . V_91 & 0xff ) ;
F_12 ( V_31 , V_93 , V_86 ,
V_77 [ V_70 ] . V_94 ) ;
F_12 ( V_31 , V_95 , V_86 ,
V_77 [ V_70 ] . V_83 ) ;
F_23 ( V_31 , V_96 , V_77 [ V_70 ] . V_82 >> 8 ) ;
F_23 ( V_31 , V_97 , V_77 [ V_70 ] . V_82 & 0xff ) ;
F_12 ( V_31 , V_98 , V_86 ,
V_77 [ V_70 ] . V_99 ? V_77 [ V_70 ] . V_99 : 1 ) ;
F_12 ( V_31 , V_100 , V_86 ,
V_77 [ V_70 ] . V_101 ? V_77 [ V_70 ] . V_101 : 1 ) ;
F_23 ( V_31 , V_102 , V_77 [ V_70 ] . V_103 ) ;
F_12 ( V_31 , V_104 ,
V_86 , V_68 ) ;
V_16 -> V_105 = V_70 ;
F_10 ( V_31 -> V_2 ,
L_8 ,
V_77 [ V_70 ] . V_89 , V_77 [ V_70 ] . V_91 ,
V_77 [ V_70 ] . V_87 , V_77 [ V_70 ] . V_82 ,
V_77 [ V_70 ] . V_94 , V_77 [ V_70 ] . V_83 ,
V_77 [ V_70 ] . V_103 , V_77 [ V_70 ] . V_99 ,
V_77 [ V_70 ] . V_101 , V_68 ) ;
return 0 ;
}
static int F_24 ( struct V_106 * V_107 ,
struct V_65 * V_66 ,
struct V_108 * V_109 )
{
struct V_48 * V_31 = V_109 -> V_31 ;
T_1 V_110 = 0 ;
F_10 ( V_31 -> V_2 , L_9 ,
V_25 , F_25 ( V_66 ) ,
F_21 ( V_66 ) ) ;
switch ( F_25 ( V_66 ) ) {
case 16 :
break;
case 20 :
V_110 = ( V_111 <<
V_112 ) ;
break;
case 24 :
V_110 = ( V_113 <<
V_112 ) ;
break;
case 32 :
V_110 = ( V_114 <<
V_112 ) ;
break;
default:
F_6 ( V_31 -> V_2 , L_10 ,
V_25 , F_25 ( V_66 ) ) ;
return - V_45 ;
}
F_12 ( V_31 , V_115 ,
V_116 ,
V_110 ) ;
return F_19 ( V_31 , V_66 ) ;
}
static int F_26 ( struct V_108 * V_117 , int V_118 )
{
struct V_48 * V_31 = V_117 -> V_31 ;
if ( V_118 ) {
F_12 ( V_31 , V_119 ,
V_120 ,
V_120 ) ;
} else {
F_12 ( V_31 , V_119 ,
V_120 , 0x0 ) ;
}
return 0 ;
}
static int F_27 ( struct V_108 * V_117 ,
unsigned int V_121 )
{
struct V_48 * V_31 = V_117 -> V_31 ;
T_1 V_122 = 0 ;
T_1 V_123 = 0 ;
T_1 V_124 = 0 ;
F_10 ( V_31 -> V_2 , L_11 , V_25 , V_121 ) ;
switch ( V_121 & V_125 ) {
case V_126 :
V_122 |= V_127 | V_128 ;
break;
default:
F_28 ( V_31 -> V_2 , L_12 ) ;
return - V_45 ;
}
switch ( V_121 & V_129 ) {
case V_130 :
break;
case V_131 :
V_124 = 0x1 ;
case V_132 :
switch ( V_121 & V_133 ) {
case V_134 :
V_123 |= V_135 ;
break;
case V_136 :
break;
default:
return - V_45 ;
}
V_122 |= ( V_137 <<
V_138 ) ;
break;
case V_139 :
V_122 |= ( V_140 <<
V_138 ) ;
break;
case V_141 :
V_122 |= ( V_142 <<
V_138 ) ;
break;
default:
F_6 ( V_31 -> V_2 , L_13 ) ;
return - V_45 ;
}
F_12 ( V_31 , V_115 ,
V_143 |
V_144 ,
V_122 ) ;
F_12 ( V_31 , V_145 ,
V_146 ,
V_124 ) ;
F_12 ( V_31 , V_74 ,
V_135 ,
V_123 ) ;
return 0 ;
}
static int F_29 ( struct V_108 * V_117 ,
int V_147 , unsigned int V_148 , int V_149 )
{
struct V_48 * V_31 = V_117 -> V_31 ;
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_70 ;
F_10 ( V_31 -> V_2 , L_14 ,
V_25 , V_147 , V_148 , V_149 ) ;
for ( V_70 = 0 ; V_77 [ V_70 ] . V_79 != V_148 ; V_70 ++ ) {
if ( V_70 == F_15 ( V_77 ) ) {
F_6 ( V_16 -> V_2 , L_15 ,
V_25 , V_148 ) ;
return - V_45 ;
}
}
F_12 ( V_31 , V_71 , V_150 ,
V_147 << V_151 ) ;
V_16 -> V_80 = V_148 ;
return 0 ;
}
static int F_30 ( struct V_152 * V_153 ,
unsigned long V_30 , void * V_110 )
{
struct V_154 * V_155 =
F_31 ( V_153 , struct V_154 , V_153 ) ;
struct V_15 * V_16 = V_155 -> V_16 ;
if ( V_30 & V_156 ) {
if ( F_32 ( V_16 -> V_51 . V_157 ) )
F_33 ( V_16 -> V_51 . V_157 , 0 ) ;
F_34 ( V_16 -> V_24 ) ;
F_10 ( V_16 -> V_2 , L_16 , V_25 ) ;
}
return 0 ;
}
static void F_35 ( struct V_48 * V_31 )
{
struct V_15 * V_16 = F_8 ( V_31 ) ;
T_1 V_17 = V_158 ;
T_1 V_159 = V_158 ;
F_10 ( V_31 -> V_2 , L_17 ,
V_77 [ V_16 -> V_105 ] . V_78 ) ;
F_12 ( V_31 , V_85 , V_17 , V_159 ) ;
F_36 ( 10 ) ;
F_12 ( V_31 , V_93 , V_17 , V_159 ) ;
F_12 ( V_31 , V_95 , V_17 , V_159 ) ;
if ( V_77 [ V_16 -> V_105 ] . V_99 )
F_12 ( V_31 , V_98 , V_17 , V_159 ) ;
if ( V_77 [ V_16 -> V_105 ] . V_101 )
F_12 ( V_31 , V_100 , V_17 , V_159 ) ;
F_12 ( V_31 , V_104 , V_17 , V_159 ) ;
}
static void F_37 ( struct V_48 * V_31 )
{
T_1 V_17 = V_158 ;
T_1 V_160 = 0 ;
F_10 ( V_31 -> V_2 , L_18 ) ;
F_12 ( V_31 , V_104 , V_17 , V_160 ) ;
F_12 ( V_31 , V_100 , V_17 , V_160 ) ;
F_12 ( V_31 , V_98 , V_17 , V_160 ) ;
F_12 ( V_31 , V_95 , V_17 , V_160 ) ;
F_12 ( V_31 , V_93 , V_17 , V_160 ) ;
F_12 ( V_31 , V_85 , V_17 , V_160 ) ;
}
static int F_38 ( struct V_48 * V_31 )
{
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_23 = 0 ;
V_23 = F_39 ( F_15 ( V_16 -> V_161 ) ,
V_16 -> V_161 ) ;
if ( V_23 )
return V_23 ;
if ( F_32 ( V_16 -> V_51 . V_157 ) ) {
F_33 ( V_16 -> V_51 . V_157 , 1 ) ;
F_40 ( 100 ) ;
}
F_41 ( V_16 -> V_24 , false ) ;
V_23 = F_42 ( V_16 -> V_24 ) ;
if ( V_23 != 0 ) {
F_6 ( V_31 -> V_2 ,
L_19 , V_23 ) ;
F_41 ( V_16 -> V_24 , true ) ;
F_43 ( F_15 ( V_16 -> V_161 ) ,
V_16 -> V_161 ) ;
return V_23 ;
}
return 0 ;
}
static int F_44 ( struct V_48 * V_31 )
{
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_23 = 0 ;
F_41 ( V_16 -> V_24 , true ) ;
V_23 = F_43 ( F_15 ( V_16 -> V_161 ) ,
V_16 -> V_161 ) ;
return V_23 ;
}
static int F_45 ( struct V_48 * V_31 ,
enum V_162 V_163 )
{
F_10 ( V_31 -> V_2 , L_20 , V_25 ,
V_31 -> V_60 . V_164 , V_163 ) ;
switch ( V_163 ) {
case V_165 :
break;
case V_166 :
if ( V_31 -> V_60 . V_164 == V_167 )
F_35 ( V_31 ) ;
break;
case V_167 :
switch ( V_31 -> V_60 . V_164 ) {
case V_168 :
F_38 ( V_31 ) ;
break;
case V_166 :
F_37 ( V_31 ) ;
break;
default:
F_46 () ;
}
break;
case V_168 :
if ( V_31 -> V_60 . V_164 == V_167 )
F_44 ( V_31 ) ;
break;
}
V_31 -> V_60 . V_164 = V_163 ;
return 0 ;
}
static int F_47 ( struct V_48 * V_31 )
{
F_45 ( V_31 , V_168 ) ;
return 0 ;
}
static int F_48 ( struct V_48 * V_31 )
{
F_45 ( V_31 , V_167 ) ;
return 0 ;
}
static int F_49 ( struct V_48 * V_31 )
{
int V_23 = 0 ;
struct V_15 * V_16 = F_8 ( V_31 ) ;
int V_70 ;
F_10 ( V_16 -> V_2 , L_21 , V_25 ) ;
V_16 = F_8 ( V_31 ) ;
V_16 -> V_31 = V_31 ;
for ( V_70 = 0 ; V_70 < F_15 ( V_16 -> V_161 ) ; V_70 ++ ) {
V_16 -> V_155 [ V_70 ] . V_153 . V_169 =
F_30 ;
V_16 -> V_155 [ V_70 ] . V_16 = V_16 ;
V_23 = F_50 ( V_16 -> V_161 [ V_70 ] . V_170 ,
& V_16 -> V_155 [ V_70 ] . V_153 ) ;
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
int V_70 ;
F_45 ( V_31 , V_168 ) ;
for ( V_70 = 0 ; V_70 < F_15 ( V_16 -> V_161 ) ; V_70 ++ )
F_52 ( V_16 -> V_161 [ V_70 ] . V_170 ,
& V_16 -> V_155 [ V_70 ] . V_153 ) ;
return 0 ;
}
static void F_53 ( struct V_15 * V_16 )
{
struct V_171 * V_172 = V_16 -> V_2 -> V_173 ;
unsigned int V_174 = V_175 ;
int V_23 ;
F_54 ( V_172 , L_23 , & V_174 ) ;
switch ( V_174 ) {
case V_175 :
case V_176 :
case V_177 :
V_16 -> V_51 . V_52 = V_174 ;
break;
default:
F_6 ( V_16 -> V_2 ,
L_24 ,
V_174 ) ;
V_16 -> V_51 . V_52 = V_175 ;
}
V_23 = F_55 ( V_172 , L_25 , 0 ) ;
if ( V_23 > 0 )
V_16 -> V_51 . V_157 = V_23 ;
}
static void F_53 ( struct V_15 * V_16 )
{
}
static int F_56 ( struct V_15 * V_16 )
{
int V_23 , V_70 ;
F_57 ( V_16 -> V_2 , V_16 ) ;
if ( F_58 ( V_16 -> V_2 ) )
memcpy ( & V_16 -> V_51 , F_58 ( V_16 -> V_2 ) ,
sizeof( V_16 -> V_51 ) ) ;
else if ( V_16 -> V_2 -> V_173 )
F_53 ( V_16 ) ;
if ( V_16 -> V_51 . V_157 ) {
V_23 = F_59 ( V_16 -> V_2 ,
V_16 -> V_51 . V_157 ,
V_178 ,
L_26 ) ;
if ( V_23 < 0 ) {
F_6 ( V_16 -> V_2 , L_27 ) ;
return V_23 ;
}
}
for ( V_70 = 0 ; V_70 < F_15 ( V_16 -> V_161 ) ; V_70 ++ )
V_16 -> V_161 [ V_70 ] . V_179 = V_180 [ V_70 ] ;
V_23 = F_60 ( V_16 -> V_2 ,
F_15 ( V_16 -> V_161 ) ,
V_16 -> V_161 ) ;
if ( V_23 != 0 )
F_6 ( V_16 -> V_2 , L_28 , V_23 ) ;
return V_23 ;
}
static int F_61 ( struct V_181 * V_182 ,
const struct V_183 * V_184 )
{
struct V_15 * V_16 ;
int V_23 ;
const struct V_185 * V_185 ;
F_10 ( & V_182 -> V_2 , L_29 , V_25 ,
V_184 -> V_44 , ( int ) V_184 -> V_186 ) ;
V_185 = & V_187 ;
V_16 = F_62 ( & V_182 -> V_2 , sizeof( * V_16 ) , V_188 ) ;
if ( V_16 == NULL )
return - V_189 ;
V_16 -> V_24 = F_63 ( V_182 , V_185 ) ;
if ( F_64 ( V_16 -> V_24 ) ) {
V_23 = F_65 ( V_16 -> V_24 ) ;
F_6 ( & V_182 -> V_2 , L_30 ,
V_23 ) ;
return V_23 ;
}
V_16 -> V_2 = & V_182 -> V_2 ;
V_16 -> V_51 . V_55 = V_184 -> V_186 ;
V_23 = F_56 ( V_16 ) ;
if ( V_23 )
return V_23 ;
return F_66 ( & V_182 -> V_2 , & V_190 ,
V_191 ,
F_15 ( V_191 ) ) ;
}
static int F_67 ( struct V_181 * V_182 )
{
F_68 ( & V_182 -> V_2 ) ;
return 0 ;
}
