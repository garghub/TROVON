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
struct V_31 * V_32 = F_8 ( V_27 -> V_33 ) ;
struct V_15 * V_16 = F_9 ( V_32 ) ;
unsigned int V_3 = V_8 ;
unsigned int V_17 ;
switch ( F_10 ( V_27 -> V_3 , V_27 -> V_34 ) ) {
case F_10 ( V_35 , 7 ) :
V_17 = V_36 ;
break;
case F_10 ( V_35 , 6 ) :
V_17 = V_37 ;
break;
case F_10 ( V_38 , 7 ) :
V_17 = V_39 ;
break;
case F_10 ( V_38 , 6 ) :
V_17 = V_40 ;
break;
case F_10 ( V_41 , 7 ) :
V_17 = V_42 ;
break;
case F_10 ( V_41 , 6 ) :
V_17 = V_43 ;
break;
case F_10 ( V_44 , 7 ) :
V_17 = V_45 ;
V_3 = V_7 ;
break;
default:
F_6 ( V_32 -> V_2 , L_2 ,
V_27 -> V_46 , V_25 ) ;
return - V_47 ;
}
switch ( V_30 ) {
case V_48 :
return F_3 ( V_16 , V_3 , V_17 , V_17 , 5000 , 100 ) ;
case V_49 :
return F_3 ( V_16 , V_3 , V_17 , 0 , 5000 , 100 ) ;
default:
F_11 ( V_32 -> V_2 ,
L_3 ,
V_30 , V_27 -> V_46 ) ;
}
return 0 ;
}
static int F_12 ( struct V_26 * V_27 ,
struct V_28 * V_29 , int V_30 )
{
struct V_31 * V_32 = F_8 ( V_27 -> V_33 ) ;
struct V_15 * V_16 = F_9 ( V_32 ) ;
switch ( V_30 ) {
case V_48 :
F_13 ( V_32 , V_50 ,
V_51 ,
V_16 -> V_52 . V_53 <<
V_54 ) ;
F_11 ( V_32 -> V_2 , L_4 , V_25 ) ;
break;
case V_55 :
F_13 ( V_32 , V_50 ,
V_51 , 0 ) ;
F_11 ( V_32 -> V_2 , L_5 , V_25 ) ;
break;
}
return 0 ;
}
static int F_14 ( struct V_31 * V_32 )
{
int V_23 = 0 ;
struct V_15 * V_16 = F_9 ( V_32 ) ;
if ( ! ( V_16 -> V_52 . V_56 & V_57 ) )
V_23 = F_15 (
V_32 , V_58 ,
F_16 ( V_58 ) ) ;
if ( V_23 )
return V_23 ;
if ( V_16 -> V_52 . V_56 & V_59 )
V_23 = F_15 (
V_32 , V_60 ,
F_16 ( V_60 ) ) ;
else
V_23 = F_15 (
V_32 , V_61 ,
F_16 ( V_61 ) ) ;
return V_23 ;
}
static int F_17 ( struct V_31 * V_32 )
{
struct V_62 * V_33 = F_18 ( V_32 ) ;
struct V_15 * V_16 = F_9 ( V_32 ) ;
int V_23 = 0 ;
if ( V_16 -> V_52 . V_56 & V_57 ) {
V_23 = F_19 (
V_33 , V_63 ,
F_16 ( V_63 ) ) ;
if ( V_23 )
return V_23 ;
V_23 = F_20 ( V_33 , V_64 ,
F_16 ( V_64 ) ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = F_19 (
V_33 , V_65 ,
F_16 ( V_65 ) ) ;
if ( V_23 )
return V_23 ;
V_23 = F_20 ( V_33 , V_66 ,
F_16 ( V_66 ) ) ;
if ( V_23 )
return V_23 ;
}
if ( V_16 -> V_52 . V_56 & V_59 ) {
V_23 = F_19 (
V_33 , V_67 ,
F_16 ( V_67 ) ) ;
if ( V_23 )
return V_23 ;
V_23 = F_20 ( V_33 , V_68 ,
F_16 ( V_68 ) ) ;
if ( V_23 )
return V_23 ;
} else {
V_23 = F_19 (
V_33 , V_69 ,
F_16 ( V_69 ) ) ;
if ( V_23 )
return V_23 ;
V_23 = F_20 ( V_33 , V_70 ,
F_16 ( V_70 ) ) ;
if ( V_23 )
return V_23 ;
}
return 0 ;
}
static int F_21 ( struct V_31 * V_32 ,
struct V_71 * V_72 )
{
struct V_15 * V_16 = F_9 ( V_32 ) ;
int V_73 = F_22 ( V_72 ) ;
int V_74 = V_16 -> V_75 / V_16 -> V_76 ;
int V_77 = 0 ;
int V_78 = - 1 ;
int V_79 ;
F_13 ( V_32 , V_80 ,
V_81 , V_82 ) ;
F_13 ( V_32 , V_83 ,
V_84 , V_85 ) ;
for ( V_79 = 0 ; V_79 < F_16 ( V_86 ) ; V_79 ++ ) {
if ( V_86 [ V_79 ] . V_87 == F_23 ( V_72 ) &&
V_86 [ V_79 ] . V_74 == V_74 ) {
int V_88 = ( V_86 [ V_79 ] . V_89 * V_86 [ V_79 ] . V_90 ) %
F_22 ( V_72 ) ;
int V_91 = ( V_86 [ V_79 ] . V_89 * V_86 [ V_79 ] . V_90 ) /
F_22 ( V_72 ) ;
if ( V_88 < V_73 && V_91 > 0 ) {
V_78 = V_79 ;
V_77 = V_91 ;
V_73 = V_88 ;
}
}
}
if ( V_78 == - 1 ) {
F_6 ( V_32 -> V_2 ,
L_6 ,
V_25 , F_23 ( V_72 ) ) ;
return - V_47 ;
}
if ( V_73 != 0 ) {
F_24 ( V_32 -> V_2 , L_7 ) ;
}
V_79 = V_78 ;
F_13 ( V_32 , V_92 , V_93 ,
( V_16 -> V_76 << 4 ) | 0x01 ) ;
F_25 ( V_32 , V_94 , V_86 [ V_79 ] . V_95 ) ;
F_25 ( V_32 , V_96 ,
V_86 [ V_79 ] . V_97 >> 8 ) ;
F_25 ( V_32 , V_98 ,
V_86 [ V_79 ] . V_97 & 0xff ) ;
F_13 ( V_32 , V_99 , V_93 ,
V_86 [ V_79 ] . V_100 ) ;
F_13 ( V_32 , V_101 , V_93 ,
V_86 [ V_79 ] . V_90 ) ;
F_25 ( V_32 , V_102 , V_86 [ V_79 ] . V_89 >> 8 ) ;
F_25 ( V_32 , V_103 , V_86 [ V_79 ] . V_89 & 0xff ) ;
F_13 ( V_32 , V_104 , V_93 ,
V_86 [ V_79 ] . V_105 ? V_86 [ V_79 ] . V_105 : 1 ) ;
F_13 ( V_32 , V_106 , V_93 ,
V_86 [ V_79 ] . V_107 ? V_86 [ V_79 ] . V_107 : 1 ) ;
F_25 ( V_32 , V_108 , V_86 [ V_79 ] . V_109 ) ;
F_13 ( V_32 , V_110 ,
V_93 , V_77 ) ;
V_16 -> V_111 = V_79 ;
F_11 ( V_32 -> V_2 ,
L_8 ,
V_86 [ V_79 ] . V_95 , V_86 [ V_79 ] . V_97 ,
V_16 -> V_76 , V_86 [ V_79 ] . V_89 ,
V_86 [ V_79 ] . V_100 , V_86 [ V_79 ] . V_90 ,
V_86 [ V_79 ] . V_109 , V_86 [ V_79 ] . V_105 ,
V_86 [ V_79 ] . V_107 , V_77 ) ;
return 0 ;
}
static int F_26 ( struct V_112 * V_113 ,
struct V_71 * V_72 ,
struct V_114 * V_115 )
{
struct V_31 * V_32 = V_115 -> V_32 ;
T_1 V_116 = 0 ;
F_11 ( V_32 -> V_2 , L_9 ,
V_25 , F_27 ( V_72 ) ,
F_23 ( V_72 ) ) ;
switch ( F_27 ( V_72 ) ) {
case 16 :
break;
case 20 :
V_116 = ( V_117 <<
V_118 ) ;
break;
case 24 :
V_116 = ( V_119 <<
V_118 ) ;
break;
case 32 :
V_116 = ( V_120 <<
V_118 ) ;
break;
default:
F_6 ( V_32 -> V_2 , L_10 ,
V_25 , F_27 ( V_72 ) ) ;
return - V_47 ;
}
F_13 ( V_32 , V_121 ,
V_122 ,
V_116 ) ;
return F_21 ( V_32 , V_72 ) ;
}
static int F_28 ( struct V_114 * V_123 , int V_124 )
{
struct V_31 * V_32 = V_123 -> V_32 ;
if ( V_124 ) {
F_13 ( V_32 , V_125 ,
V_126 ,
V_126 ) ;
} else {
F_13 ( V_32 , V_125 ,
V_126 , 0x0 ) ;
}
return 0 ;
}
static int F_29 ( struct V_114 * V_123 ,
unsigned int V_127 )
{
struct V_31 * V_32 = V_123 -> V_32 ;
T_1 V_128 = 0 ;
T_1 V_129 = 0 ;
T_1 V_130 = 0 ;
F_11 ( V_32 -> V_2 , L_11 , V_25 , V_127 ) ;
switch ( V_127 & V_131 ) {
case V_132 :
V_128 |= V_133 | V_134 ;
break;
default:
F_30 ( V_32 -> V_2 , L_12 ) ;
return - V_47 ;
}
switch ( V_127 & V_135 ) {
case V_136 :
break;
case V_137 :
V_130 = 0x1 ;
case V_138 :
switch ( V_127 & V_139 ) {
case V_140 :
V_129 |= V_141 ;
break;
case V_142 :
break;
default:
return - V_47 ;
}
V_128 |= ( V_143 <<
V_144 ) ;
break;
case V_145 :
V_128 |= ( V_146 <<
V_144 ) ;
break;
case V_147 :
V_128 |= ( V_148 <<
V_144 ) ;
break;
default:
F_6 ( V_32 -> V_2 , L_13 ) ;
return - V_47 ;
}
F_13 ( V_32 , V_121 ,
V_149 |
V_150 ,
V_128 ) ;
F_13 ( V_32 , V_151 ,
V_152 ,
V_130 ) ;
F_13 ( V_32 , V_83 ,
V_141 ,
V_129 ) ;
return 0 ;
}
static int F_31 ( struct V_114 * V_123 ,
int V_153 , unsigned int V_154 , int V_155 )
{
struct V_31 * V_32 = V_123 -> V_32 ;
struct V_15 * V_16 = F_9 ( V_32 ) ;
int V_79 ;
F_11 ( V_32 -> V_2 , L_14 ,
V_25 , V_153 , V_154 , V_155 ) ;
for ( V_79 = 1 ; V_154 / V_79 > 20000000 && V_79 < 8 ; V_79 ++ )
;
if ( V_154 / V_79 > 20000000 ) {
F_6 ( V_16 -> V_2 , L_15 ,
V_25 , V_154 ) ;
return - V_47 ;
}
V_16 -> V_76 = V_79 ;
for ( V_79 = 0 ; V_79 < F_16 ( V_86 ) &&
V_86 [ V_79 ] . V_74 != V_154 / V_16 -> V_76 ; V_79 ++ )
;
if ( V_79 == F_16 ( V_86 ) ) {
F_6 ( V_16 -> V_2 , L_16 ,
V_25 , V_154 ) ;
return - V_47 ;
}
F_13 ( V_32 , V_80 , V_156 ,
V_153 << V_157 ) ;
V_16 -> V_75 = V_154 ;
return 0 ;
}
static int F_32 ( struct V_158 * V_159 ,
unsigned long V_30 , void * V_116 )
{
struct V_160 * V_161 =
F_33 ( V_159 , struct V_160 , V_159 ) ;
struct V_15 * V_16 = V_161 -> V_16 ;
if ( V_30 & V_162 ) {
if ( F_34 ( V_16 -> V_52 . V_163 ) )
F_35 ( V_16 -> V_52 . V_163 , 0 ) ;
F_36 ( V_16 -> V_24 ) ;
F_11 ( V_16 -> V_2 , L_17 , V_25 ) ;
}
return 0 ;
}
static void F_37 ( struct V_31 * V_32 )
{
struct V_15 * V_16 = F_9 ( V_32 ) ;
T_1 V_17 = V_164 ;
T_1 V_165 = V_164 ;
F_11 ( V_32 -> V_2 , L_18 ,
V_86 [ V_16 -> V_111 ] . V_87 ) ;
F_13 ( V_32 , V_92 , V_17 , V_165 ) ;
F_38 ( 10 ) ;
F_13 ( V_32 , V_99 , V_17 , V_165 ) ;
F_13 ( V_32 , V_101 , V_17 , V_165 ) ;
if ( V_86 [ V_16 -> V_111 ] . V_105 )
F_13 ( V_32 , V_104 , V_17 , V_165 ) ;
if ( V_86 [ V_16 -> V_111 ] . V_107 )
F_13 ( V_32 , V_106 , V_17 , V_165 ) ;
F_13 ( V_32 , V_110 , V_17 , V_165 ) ;
}
static void F_39 ( struct V_31 * V_32 )
{
T_1 V_17 = V_164 ;
T_1 V_166 = 0 ;
F_11 ( V_32 -> V_2 , L_19 ) ;
F_13 ( V_32 , V_110 , V_17 , V_166 ) ;
F_13 ( V_32 , V_106 , V_17 , V_166 ) ;
F_13 ( V_32 , V_104 , V_17 , V_166 ) ;
F_13 ( V_32 , V_101 , V_17 , V_166 ) ;
F_13 ( V_32 , V_99 , V_17 , V_166 ) ;
F_13 ( V_32 , V_92 , V_17 , V_166 ) ;
}
static int F_40 ( struct V_31 * V_32 )
{
struct V_15 * V_16 = F_9 ( V_32 ) ;
int V_23 = 0 ;
V_23 = F_41 ( F_16 ( V_16 -> V_167 ) ,
V_16 -> V_167 ) ;
if ( V_23 )
return V_23 ;
if ( F_34 ( V_16 -> V_52 . V_163 ) ) {
F_35 ( V_16 -> V_52 . V_163 , 1 ) ;
F_42 ( 100 ) ;
}
F_43 ( V_16 -> V_24 , false ) ;
V_23 = F_44 ( V_16 -> V_24 ) ;
if ( V_23 != 0 ) {
F_6 ( V_32 -> V_2 ,
L_20 , V_23 ) ;
F_43 ( V_16 -> V_24 , true ) ;
F_45 ( F_16 ( V_16 -> V_167 ) ,
V_16 -> V_167 ) ;
return V_23 ;
}
return 0 ;
}
static int F_46 ( struct V_31 * V_32 )
{
struct V_15 * V_16 = F_9 ( V_32 ) ;
int V_23 = 0 ;
F_43 ( V_16 -> V_24 , true ) ;
V_23 = F_45 ( F_16 ( V_16 -> V_167 ) ,
V_16 -> V_167 ) ;
return V_23 ;
}
static int F_47 ( struct V_31 * V_32 ,
enum V_168 V_169 )
{
F_11 ( V_32 -> V_2 , L_21 , V_25 ,
F_48 ( V_32 ) , V_169 ) ;
switch ( V_169 ) {
case V_170 :
break;
case V_171 :
if ( F_48 ( V_32 ) == V_172 )
F_37 ( V_32 ) ;
break;
case V_172 :
switch ( F_48 ( V_32 ) ) {
case V_173 :
F_40 ( V_32 ) ;
break;
case V_171 :
F_39 ( V_32 ) ;
break;
default:
F_49 () ;
}
break;
case V_173 :
if ( F_48 ( V_32 ) == V_172 )
F_46 ( V_32 ) ;
break;
}
return 0 ;
}
static int F_50 ( struct V_31 * V_32 )
{
int V_23 = 0 ;
struct V_15 * V_16 = F_9 ( V_32 ) ;
int V_79 ;
F_11 ( V_16 -> V_2 , L_22 , V_25 ) ;
V_16 = F_9 ( V_32 ) ;
V_16 -> V_32 = V_32 ;
for ( V_79 = 0 ; V_79 < F_16 ( V_16 -> V_167 ) ; V_79 ++ ) {
V_16 -> V_161 [ V_79 ] . V_159 . V_174 =
F_32 ;
V_16 -> V_161 [ V_79 ] . V_16 = V_16 ;
V_23 = F_51 ( V_16 -> V_167 [ V_79 ] . V_175 ,
& V_16 -> V_161 [ V_79 ] . V_159 ) ;
if ( V_23 ) {
F_6 ( V_32 -> V_2 ,
L_23 ,
V_23 ) ;
return V_23 ;
}
}
F_43 ( V_16 -> V_24 , true ) ;
F_36 ( V_16 -> V_24 ) ;
V_23 = F_14 ( V_32 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_17 ( V_32 ) ;
return V_23 ;
}
static int F_52 ( struct V_31 * V_32 )
{
struct V_15 * V_16 = F_9 ( V_32 ) ;
int V_79 ;
for ( V_79 = 0 ; V_79 < F_16 ( V_16 -> V_167 ) ; V_79 ++ )
F_53 ( V_16 -> V_167 [ V_79 ] . V_175 ,
& V_16 -> V_161 [ V_79 ] . V_159 ) ;
return 0 ;
}
static void F_54 ( struct V_15 * V_16 )
{
struct V_176 * V_177 = V_16 -> V_2 -> V_178 ;
unsigned int V_179 = V_180 ;
int V_23 ;
F_55 ( V_177 , L_24 , & V_179 ) ;
switch ( V_179 ) {
case V_180 :
case V_181 :
case V_182 :
V_16 -> V_52 . V_53 = V_179 ;
break;
default:
F_6 ( V_16 -> V_2 ,
L_25 ,
V_179 ) ;
V_16 -> V_52 . V_53 = V_180 ;
}
V_23 = F_56 ( V_177 , L_26 , 0 ) ;
if ( V_23 > 0 )
V_16 -> V_52 . V_163 = V_23 ;
}
static void F_54 ( struct V_15 * V_16 )
{
}
static int F_57 ( struct V_15 * V_16 )
{
int V_23 , V_79 ;
F_58 ( V_16 -> V_2 , V_16 ) ;
if ( F_59 ( V_16 -> V_2 ) )
memcpy ( & V_16 -> V_52 , F_59 ( V_16 -> V_2 ) ,
sizeof( V_16 -> V_52 ) ) ;
else if ( V_16 -> V_2 -> V_178 )
F_54 ( V_16 ) ;
if ( V_16 -> V_52 . V_163 ) {
V_23 = F_60 ( V_16 -> V_2 ,
V_16 -> V_52 . V_163 ,
V_183 ,
L_27 ) ;
if ( V_23 < 0 ) {
F_6 ( V_16 -> V_2 , L_28 ) ;
return V_23 ;
}
}
for ( V_79 = 0 ; V_79 < F_16 ( V_16 -> V_167 ) ; V_79 ++ )
V_16 -> V_167 [ V_79 ] . V_184 = V_185 [ V_79 ] ;
V_23 = F_61 ( V_16 -> V_2 ,
F_16 ( V_16 -> V_167 ) ,
V_16 -> V_167 ) ;
if ( V_23 != 0 )
F_6 ( V_16 -> V_2 , L_29 , V_23 ) ;
return V_23 ;
}
static int F_62 ( struct V_186 * V_187 ,
const struct V_188 * V_189 )
{
struct V_15 * V_16 ;
int V_23 ;
const struct V_190 * V_190 ;
F_11 ( & V_187 -> V_2 , L_30 , V_25 ,
V_189 -> V_46 , ( int ) V_189 -> V_191 ) ;
V_190 = & V_192 ;
V_16 = F_63 ( & V_187 -> V_2 , sizeof( * V_16 ) , V_193 ) ;
if ( V_16 == NULL )
return - V_194 ;
V_16 -> V_24 = F_64 ( V_187 , V_190 ) ;
if ( F_65 ( V_16 -> V_24 ) ) {
V_23 = F_66 ( V_16 -> V_24 ) ;
F_6 ( & V_187 -> V_2 , L_31 ,
V_23 ) ;
return V_23 ;
}
V_16 -> V_2 = & V_187 -> V_2 ;
V_16 -> V_52 . V_56 = V_189 -> V_191 ;
V_23 = F_57 ( V_16 ) ;
if ( V_23 )
return V_23 ;
if ( V_16 -> V_52 . V_56 & V_57 )
return F_67 ( & V_187 -> V_2 ,
& V_195 ,
V_196 ,
F_16 ( V_196 ) ) ;
else
return F_67 ( & V_187 -> V_2 ,
& V_195 ,
V_197 ,
F_16 ( V_197 ) ) ;
}
static int F_68 ( struct V_186 * V_187 )
{
F_69 ( & V_187 -> V_2 ) ;
return 0 ;
}
