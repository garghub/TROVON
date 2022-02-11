static int F_1 ( void )
{
int V_1 ;
F_2 ( L_1 ) ;
V_1 = F_3 () ;
if ( V_1 < 0 )
goto V_2;
V_1 = F_4 ( & V_3 . V_4 -> V_5 ) ;
F_5 ( V_1 < 0 ) ;
if ( V_1 < 0 )
goto V_6;
return 0 ;
V_6:
F_6 () ;
V_2:
return V_1 ;
}
static void F_7 ( void )
{
int V_1 ;
F_2 ( L_2 ) ;
V_1 = F_8 ( & V_3 . V_4 -> V_5 ) ;
F_5 ( V_1 < 0 ) ;
F_6 () ;
}
int F_9 ( struct V_7 * V_8 )
{
F_2 ( L_3 ) ;
F_10 ( & V_3 . V_9 ) ;
return 0 ;
}
static const struct V_10 * F_11 (
const struct V_10 * V_11 ,
int V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ ) {
if ( V_11 [ V_13 ] . V_14 . V_15 == V_3 . V_9 . V_16 . V_14 . V_15 )
return & V_11 [ V_13 ] ;
}
return NULL ;
}
static const struct V_10 * F_12 ( void )
{
const struct V_10 * V_17 ;
int V_12 ;
if ( V_3 . V_9 . V_16 . V_14 . V_18 == V_19 ) {
V_17 = V_20 ;
V_12 = F_13 ( V_20 ) ;
} else {
V_17 = V_21 ;
V_12 = F_13 ( V_21 ) ;
}
return F_11 ( V_17 , V_12 ) ;
}
static bool F_14 ( struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
int V_26 , V_27 , V_28 , V_29 ;
if ( ( V_25 -> V_30 == V_23 -> V_30 ) &&
( V_25 -> V_31 == V_23 -> V_31 ) &&
( V_25 -> V_32 == V_23 -> V_32 ) ) {
V_29 = V_25 -> V_33 + V_25 -> V_34 + V_25 -> V_35 ;
V_27 = V_23 -> V_33 + V_23 -> V_34 + V_23 -> V_35 ;
V_28 = V_25 -> V_36 + V_25 -> V_37 + V_25 -> V_38 ;
V_26 = V_25 -> V_36 + V_25 -> V_37 + V_25 -> V_38 ;
F_2 ( L_4\
L_5 ,
V_27 , V_26 ,
V_29 , V_28 ) ;
if ( ( V_27 == V_29 ) &&
( V_26 == V_28 ) ) {
return true ;
}
}
return false ;
}
static struct V_39 F_15 ( struct V_22 * V_40 )
{
int V_13 ;
struct V_39 V_14 = { - 1 } ;
F_2 ( L_6 ) ;
for ( V_13 = 0 ; V_13 < F_13 ( V_21 ) ; V_13 ++ ) {
if ( F_14 ( V_40 , & V_21 [ V_13 ] . V_41 ) ) {
V_14 = V_21 [ V_13 ] . V_14 ;
goto V_42;
}
}
for ( V_13 = 0 ; V_13 < F_13 ( V_20 ) ; V_13 ++ ) {
if ( F_14 ( V_40 , & V_20 [ V_13 ] . V_41 ) ) {
V_14 = V_20 [ V_13 ] . V_14 ;
goto V_42;
}
}
V_42: return V_14 ;
}
unsigned long F_16 ( void )
{
return V_3 . V_9 . V_16 . V_41 . V_30 * 1000 ;
}
static void F_17 ( struct V_7 * V_8 , int V_43 ,
struct V_44 * V_45 )
{
unsigned long V_46 , V_47 ;
T_1 V_48 ;
V_46 = F_18 ( V_3 . V_49 ) / 10000 ;
if ( V_8 -> V_50 . V_3 . V_51 == 0 )
V_45 -> V_51 = V_52 ;
else
V_45 -> V_51 = V_8 -> V_50 . V_3 . V_51 ;
V_47 = V_46 / V_45 -> V_51 ;
if ( V_8 -> V_50 . V_3 . V_53 == 0 )
V_45 -> V_53 = V_54 ;
else
V_45 -> V_53 = V_8 -> V_50 . V_3 . V_53 ;
V_45 -> V_55 = V_43 * V_45 -> V_53 / V_47 ;
V_48 = ( V_43 - V_45 -> V_55 / V_45 -> V_53 * V_47 ) * 262144 ;
V_45 -> V_56 = V_45 -> V_53 * V_48 / V_47 ;
V_45 -> V_57 = V_43 > 1000 * 100 ;
V_45 -> V_58 = ( ( V_45 -> V_55 * V_46 / 10 ) / ( V_45 -> V_51 * 250 ) + 5 ) / 10 ;
V_45 -> V_59 = V_60 ;
F_2 ( L_7 , V_45 -> V_55 , V_45 -> V_56 ) ;
F_2 ( L_8 , V_45 -> V_57 , V_45 -> V_58 ) ;
}
static int F_19 ( struct V_7 * V_8 )
{
int V_1 ;
const struct V_10 * V_40 ;
struct V_22 * V_61 ;
unsigned long V_43 ;
V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
F_20 ( V_8 -> V_62 ) ;
V_61 = & V_8 -> V_63 . V_41 ;
F_2 ( L_9 ,
V_8 -> V_63 . V_41 . V_31 ,
V_8 -> V_63 . V_41 . V_32 ) ;
V_40 = F_12 () ;
if ( V_40 == NULL ) {
V_3 . V_9 . V_16 . V_14 . V_15 = 4 ;
V_3 . V_9 . V_16 . V_14 . V_18 = V_19 ;
V_3 . V_9 . V_16 = V_20 [ 0 ] ;
} else {
V_3 . V_9 . V_16 = * V_40 ;
}
V_43 = V_61 -> V_30 ;
F_17 ( V_8 , V_43 , & V_3 . V_9 . V_64 ) ;
V_3 . V_9 . V_65 -> V_66 ( & V_3 . V_9 , 0 ) ;
V_1 = V_3 . V_9 . V_65 -> V_67 ( & V_3 . V_9 ) ;
if ( V_1 ) {
F_2 ( L_10 ) ;
goto V_68;
}
V_1 = V_3 . V_9 . V_65 -> V_69 ( & V_3 . V_9 ) ;
if ( V_1 ) {
F_2 ( L_11 ) ;
goto V_68;
}
V_3 . V_9 . V_65 -> V_70 ( & V_3 . V_9 ) ;
F_21 ( V_71 ) ;
F_22 ( V_8 -> V_50 . V_72 . V_73 ) ;
F_23 ( 0 ) ;
F_24 ( V_8 -> V_63 . V_41 . V_31 ,
V_8 -> V_63 . V_41 . V_32 ) ;
V_3 . V_9 . V_65 -> V_66 ( & V_3 . V_9 , 1 ) ;
V_1 = F_25 ( V_8 -> V_62 ) ;
if ( V_1 )
goto V_74;
return 0 ;
V_74:
V_3 . V_9 . V_65 -> V_66 ( & V_3 . V_9 , 0 ) ;
V_3 . V_9 . V_65 -> V_75 ( & V_3 . V_9 ) ;
V_3 . V_9 . V_65 -> V_76 ( & V_3 . V_9 ) ;
V_68:
F_7 () ;
return - V_77 ;
}
static void F_26 ( struct V_7 * V_8 )
{
F_20 ( V_8 -> V_62 ) ;
V_3 . V_9 . V_65 -> V_66 ( & V_3 . V_9 , 0 ) ;
V_3 . V_9 . V_65 -> V_75 ( & V_3 . V_9 ) ;
V_3 . V_9 . V_65 -> V_76 ( & V_3 . V_9 ) ;
F_7 () ;
}
int F_27 ( struct V_7 * V_8 ,
struct V_22 * V_41 )
{
struct V_39 V_14 ;
V_14 = F_15 ( V_41 ) ;
if ( V_14 . V_15 == - 1 ) {
return - V_78 ;
}
return 0 ;
}
void F_28 ( struct V_7 * V_8 )
{
struct V_39 V_14 ;
V_14 = F_15 ( & V_8 -> V_63 . V_41 ) ;
V_3 . V_9 . V_16 . V_14 . V_15 = V_14 . V_15 ;
V_3 . V_9 . V_16 . V_14 . V_18 = V_14 . V_18 ;
if ( V_8 -> V_79 == V_80 ) {
int V_1 ;
F_26 ( V_8 ) ;
V_1 = F_19 ( V_8 ) ;
if ( V_1 )
F_29 ( L_12 ) ;
}
}
void F_30 ( struct V_81 * V_82 )
{
F_31 ( & V_3 . V_83 ) ;
if ( F_1 () )
return;
V_3 . V_9 . V_65 -> V_84 ( & V_3 . V_9 , V_82 ) ;
V_3 . V_9 . V_65 -> V_85 ( & V_3 . V_9 , V_82 ) ;
V_3 . V_9 . V_65 -> V_86 ( & V_3 . V_9 , V_82 ) ;
V_3 . V_9 . V_65 -> V_87 ( & V_3 . V_9 , V_82 ) ;
F_7 () ;
F_32 ( & V_3 . V_83 ) ;
}
int F_33 ( T_2 * V_88 , int V_12 )
{
int V_1 ;
F_31 ( & V_3 . V_83 ) ;
V_1 = F_1 () ;
F_34 ( V_1 ) ;
V_1 = V_3 . V_9 . V_65 -> V_89 ( & V_3 . V_9 , V_88 , V_12 ) ;
F_7 () ;
F_32 ( & V_3 . V_83 ) ;
return V_1 ;
}
bool F_35 ( void )
{
int V_1 ;
F_31 ( & V_3 . V_83 ) ;
V_1 = F_1 () ;
F_34 ( V_1 ) ;
V_1 = V_3 . V_9 . V_65 -> V_90 ( & V_3 . V_9 ) ;
F_7 () ;
F_32 ( & V_3 . V_83 ) ;
return V_1 == 1 ;
}
int F_36 ( struct V_7 * V_8 )
{
struct V_91 * V_92 = V_8 -> V_93 ;
int V_1 = 0 ;
F_2 ( L_13 ) ;
F_31 ( & V_3 . V_83 ) ;
if ( V_8 -> V_62 == NULL ) {
F_29 ( L_14 ) ;
V_1 = - V_94 ;
goto V_95;
}
V_3 . V_9 . V_96 = V_92 -> V_96 ;
V_1 = F_37 ( V_8 ) ;
if ( V_1 ) {
F_29 ( L_15 ) ;
goto V_95;
}
if ( V_8 -> V_97 ) {
V_1 = V_8 -> V_97 ( V_8 ) ;
if ( V_1 ) {
F_29 ( L_16 ) ;
goto V_98;
}
}
V_1 = F_19 ( V_8 ) ;
if ( V_1 ) {
F_29 ( L_12 ) ;
goto V_99;
}
F_32 ( & V_3 . V_83 ) ;
return 0 ;
V_99:
if ( V_8 -> V_100 )
V_8 -> V_100 ( V_8 ) ;
V_98:
F_38 ( V_8 ) ;
V_95:
F_32 ( & V_3 . V_83 ) ;
return V_1 ;
}
void F_39 ( struct V_7 * V_8 )
{
F_2 ( L_17 ) ;
F_31 ( & V_3 . V_83 ) ;
F_26 ( V_8 ) ;
if ( V_8 -> V_100 )
V_8 -> V_100 ( V_8 ) ;
F_38 ( V_8 ) ;
F_32 ( & V_3 . V_83 ) ;
}
static int F_40 ( struct V_101 * V_102 , int V_103 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = V_102 -> V_108 ;
struct V_109 * V_110 = V_107 -> V_110 ;
struct V_111 * V_4 = F_41 ( V_110 -> V_5 ) ;
struct V_112 * V_9 = F_42 ( V_110 ) ;
int V_68 = 0 ;
if ( ! ( V_9 -> V_65 ) && ! ( V_9 -> V_65 -> V_113 ) ) {
F_43 ( & V_4 -> V_5 , L_18 ) ;
return - V_94 ;
}
switch ( V_103 ) {
case V_114 :
case V_115 :
case V_116 :
V_9 -> V_65 -> V_113 ( V_9 , true ) ;
break;
case V_117 :
case V_118 :
case V_119 :
V_9 -> V_65 -> V_113 ( V_9 , false ) ;
break;
default:
V_68 = - V_78 ;
}
return V_68 ;
}
static int F_44 ( struct V_101 * V_102 ,
struct V_120 * V_121 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = V_102 -> V_108 ;
struct V_109 * V_110 = V_107 -> V_110 ;
struct V_112 * V_9 = F_42 ( V_110 ) ;
struct V_122 V_123 ;
struct V_124 V_125 ;
struct V_126 V_127 ;
struct V_128 V_129 ;
int V_68 , V_130 , V_131 ;
enum V_132 V_133 ;
switch ( F_45 ( V_121 ) ) {
case V_134 :
V_127 . V_135 . V_136 =
V_137 ;
V_127 . V_135 . V_138 = V_139 ;
V_127 . V_135 . V_140 =
V_141 ;
V_127 . V_135 . V_142 = V_143 ;
V_123 . V_144 = V_145 ;
V_123 . V_146 = V_147 ;
V_123 . V_142 = V_143 ;
V_125 . V_148 = 0x10 ;
break;
case V_149 :
V_127 . V_135 . V_136 =
V_150 ;
V_127 . V_135 . V_138 = V_151 ;
V_127 . V_135 . V_140 =
V_152 ;
V_123 . V_144 = V_153 ;
V_123 . V_146 = V_154 ;
V_123 . V_142 = V_155 ;
V_127 . V_135 . V_142 = V_155 ;
V_125 . V_148 = 0x20 ;
break;
default:
return - V_78 ;
}
switch ( F_46 ( V_121 ) ) {
case 32000 :
V_133 = V_156 ;
break;
case 44100 :
V_133 = V_157 ;
break;
case 48000 :
V_133 = V_158 ;
break;
default:
return - V_78 ;
}
V_68 = F_47 ( V_9 , F_46 ( V_121 ) , & V_130 , & V_131 ) ;
if ( V_68 < 0 )
return V_68 ;
V_123 . V_159 = V_160 ;
V_123 . V_161 = 0x03 ;
V_123 . type = V_162 ;
V_123 . V_163 = V_164 ;
V_123 . V_165 = V_166 ;
V_125 . V_167 = 0xC0 ;
V_125 . V_18 = V_168 ;
V_125 . V_169 = 0x20 ;
F_48 ( V_9 , & V_125 ) ;
F_49 ( V_9 , & V_123 ) ;
V_127 . V_135 . V_170 = false ;
V_127 . V_135 . V_171 = false ;
V_127 . V_135 . V_172 = V_173 ;
V_127 . V_135 . V_174 = V_175 ;
V_127 . V_135 . V_176 = V_177 ;
V_127 . V_135 . V_178 = V_179 ;
V_127 . V_135 . V_180 = V_181 ;
V_127 . V_135 . V_182 = V_183 ;
V_127 . V_184 = V_133 ;
V_127 . V_130 = V_130 ;
V_127 . V_131 = V_131 ;
if ( F_50 ( V_185 ) ) {
V_127 . V_186 = 0 ;
V_127 . V_187 = V_188 ;
V_127 . V_189 = F_50 ( V_190 ) ;
} else {
V_127 . V_186 = ( ( ( 128 * 31 ) - 1 ) << 8 ) ;
V_127 . V_187 = V_191 ;
V_127 . V_189 = true ;
}
if ( V_127 . V_189 )
V_127 . V_192 = V_193 ;
V_127 . V_194 = V_195 ;
V_127 . V_196 = false ;
V_127 . V_197 = true ;
V_127 . V_198 = true ;
V_127 . V_199 = false ;
V_127 . V_200 = true ;
V_126 ( V_9 , & V_127 ) ;
V_129 . V_201 = V_202 ;
V_129 . V_203 = 2 ;
V_129 . V_204 = V_205 ;
V_129 . V_206 = V_207 ;
V_129 . V_208 = 0x00 ;
V_129 . V_209 = false ;
V_129 . V_210 = 0 ;
F_51 ( V_9 , & V_129 ) ;
return 0 ;
}
static int F_52 ( struct V_101 * V_102 ,
struct V_104 * V_105 )
{
if ( ! V_3 . V_9 . V_16 . V_14 . V_18 ) {
F_53 ( L_19 ) ;
return - V_77 ;
}
return 0 ;
}
static int F_54 ( struct V_109 * V_110 )
{
struct V_112 * V_92 = & V_3 . V_9 ;
F_55 ( V_110 , V_92 ) ;
return 0 ;
}
static int F_56 ( struct V_111 * V_4 )
{
struct V_211 * V_211 ;
V_211 = F_57 ( & V_4 -> V_5 , L_20 ) ;
if ( F_58 ( V_211 ) ) {
F_29 ( L_21 ) ;
return F_59 ( V_211 ) ;
}
V_3 . V_49 = V_211 ;
return 0 ;
}
static void F_60 ( void )
{
if ( V_3 . V_49 )
F_61 ( V_3 . V_49 ) ;
}
static int F_62 ( struct V_111 * V_4 )
{
struct V_212 * V_213 ;
int V_1 ;
V_3 . V_214 = V_4 -> V_5 . V_215 ;
V_3 . V_4 = V_4 ;
F_63 ( & V_3 . V_83 ) ;
V_213 = F_64 ( V_3 . V_4 , V_216 , 0 ) ;
if ( ! V_213 ) {
F_29 ( L_22 ) ;
return - V_78 ;
}
V_3 . V_9 . V_217 = F_65 ( V_213 -> V_218 ,
F_66 ( V_213 ) ) ;
if ( ! V_3 . V_9 . V_217 ) {
F_29 ( L_23 ) ;
return - V_219 ;
}
V_1 = F_56 ( V_4 ) ;
if ( V_1 ) {
F_67 ( V_3 . V_9 . V_217 ) ;
return V_1 ;
}
F_68 ( & V_4 -> V_5 ) ;
V_3 . V_9 . V_220 = V_221 ;
V_3 . V_9 . V_222 = V_223 ;
V_3 . V_9 . V_224 = V_225 ;
V_3 . V_9 . V_226 = V_227 ;
F_69 () ;
#if F_70 ( V_228 ) || \
F_70 ( V_229 )
V_1 = F_71 ( & V_4 -> V_5 , & V_230 ,
& V_231 , 1 ) ;
if ( V_1 ) {
F_29 ( L_24 ) ;
return V_1 ;
}
#endif
return 0 ;
}
static int F_72 ( struct V_111 * V_4 )
{
F_73 () ;
#if F_70 ( V_228 ) || \
F_70 ( V_229 )
F_74 ( & V_4 -> V_5 ) ;
#endif
F_75 ( & V_4 -> V_5 ) ;
F_60 () ;
F_67 ( V_3 . V_9 . V_217 ) ;
return 0 ;
}
static int F_76 ( struct V_232 * V_5 )
{
F_77 ( V_3 . V_49 ) ;
F_78 () ;
F_6 () ;
return 0 ;
}
static int F_79 ( struct V_232 * V_5 )
{
int V_1 ;
V_1 = F_3 () ;
if ( V_1 < 0 )
goto V_2;
V_1 = F_80 () ;
if ( V_1 < 0 )
goto V_233;
F_81 ( V_3 . V_49 ) ;
return 0 ;
V_233:
F_6 () ;
V_2:
return V_1 ;
}
int F_82 ( void )
{
return F_83 ( & V_234 ) ;
}
void F_84 ( void )
{
return F_85 ( & V_234 ) ;
}
