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
static int F_11 ( void )
{
int V_10 ;
if ( V_3 . V_11 == 0 )
V_10 = V_12 [ V_3 . V_10 ] ;
else
V_10 = V_13 [ V_3 . V_10 ] ;
if ( V_10 == - 1 ) {
V_3 . V_10 = 4 ;
V_3 . V_11 = V_14 ;
V_10 = V_12 [ V_3 . V_10 ] ;
}
return V_10 ;
}
static struct V_15 F_12 ( struct V_16 * V_17 )
{
int V_18 = 0 , V_10 = - 1 , V_19 = 0 , V_20 = 0 ;
int V_21 = 0 , V_22 = 0 ;
struct V_23 V_24 ;
struct V_15 V_25 = { - 1 } ;
F_2 ( L_4 ) ;
for ( V_18 = 0 ; V_18 < V_26 ; V_18 ++ ) {
V_24 = V_27 [ V_18 ] . V_28 ;
if ( ( V_24 . V_29 == V_17 -> V_29 ) &&
( V_24 . V_30 == V_17 -> V_30 ) &&
( V_24 . V_31 == V_17 -> V_31 ) ) {
V_20 = V_24 . V_32 + V_24 . V_33 + V_24 . V_34 ;
V_22 = V_17 -> V_32 + V_17 -> V_33 + V_17 -> V_34 ;
V_19 = V_24 . V_35 + V_24 . V_36 + V_24 . V_37 ;
V_21 = V_17 -> V_35 + V_17 -> V_36 + V_17 -> V_37 ;
F_2 ( L_5
L_6 ,
V_20 , V_20 ,
V_22 , V_21 ) ;
if ( ( V_20 == V_22 ) &&
( V_19 == V_21 ) ) {
V_10 = V_18 ;
V_25 . V_10 = V_38 [ V_18 ] ;
if ( V_10 < 14 )
V_25 . V_11 = V_39 ;
else
V_25 . V_11 = V_14 ;
F_2 ( L_7 ,
V_25 . V_10 , V_25 . V_11 ) ;
break;
}
}
}
return V_25 ;
}
static void F_13 ( struct V_40 * V_41 ,
struct V_16 * V_28 , int V_10 )
{
V_41 -> V_28 . V_28 . V_30 = V_28 -> V_30 ;
V_41 -> V_28 . V_28 . V_31 = V_28 -> V_31 ;
V_41 -> V_28 . V_28 . V_34 = V_28 -> V_34 ;
V_41 -> V_28 . V_28 . V_32 = V_28 -> V_32 ;
V_41 -> V_28 . V_28 . V_33 = V_28 -> V_33 ;
V_41 -> V_28 . V_28 . V_37 = V_28 -> V_37 ;
V_41 -> V_28 . V_28 . V_35 = V_28 -> V_35 ;
V_41 -> V_28 . V_28 . V_36 = V_28 -> V_36 ;
V_41 -> V_28 . V_28 . V_29 = V_28 -> V_29 ;
V_41 -> V_28 . V_42 = V_27 [ V_10 ] . V_42 ;
V_41 -> V_28 . V_43 = V_27 [ V_10 ] . V_43 ;
}
unsigned long F_14 ( void )
{
return V_3 . V_9 . V_41 . V_28 . V_28 . V_29 * 1000 ;
}
static void F_15 ( struct V_7 * V_8 , int V_44 ,
struct V_45 * V_46 )
{
unsigned long V_47 , V_48 ;
T_1 V_49 ;
V_47 = F_16 ( V_3 . V_50 ) / 10000 ;
if ( V_8 -> V_51 . V_3 . V_52 == 0 )
V_46 -> V_52 = V_53 ;
else
V_46 -> V_52 = V_8 -> V_51 . V_3 . V_52 ;
V_48 = V_47 / V_46 -> V_52 ;
V_46 -> V_54 = ( V_44 * 100 / ( V_48 ) ) / 100 ;
if ( V_8 -> V_51 . V_3 . V_55 == 0 )
V_46 -> V_55 = V_56 ;
else
V_46 -> V_55 = V_8 -> V_51 . V_3 . V_55 ;
V_49 = ( V_44 - V_46 -> V_54 * V_48 ) * 262144 ;
V_46 -> V_57 = V_49 / ( V_48 ) ;
V_46 -> V_58 = V_44 > 1000 * 100 ;
V_46 -> V_59 = ( ( V_46 -> V_54 * V_47 / 10 ) / ( V_46 -> V_52 * 250 ) + 5 ) / 10 ;
V_46 -> V_60 = V_61 ;
F_2 ( L_8 , V_46 -> V_54 , V_46 -> V_57 ) ;
F_2 ( L_9 , V_46 -> V_58 , V_46 -> V_59 ) ;
}
static int F_17 ( struct V_7 * V_8 )
{
int V_1 , V_10 = 0 ;
struct V_16 * V_62 ;
unsigned long V_44 ;
V_1 = F_1 () ;
if ( V_1 )
return V_1 ;
F_18 ( V_8 -> V_63 ) ;
V_62 = & V_8 -> V_64 . V_28 ;
F_2 ( L_10 ,
V_8 -> V_64 . V_28 . V_30 ,
V_8 -> V_64 . V_28 . V_31 ) ;
V_10 = F_11 () ;
F_13 ( & V_3 . V_9 . V_41 , V_62 , V_10 ) ;
V_44 = V_62 -> V_29 ;
F_15 ( V_8 , V_44 , & V_3 . V_9 . V_65 ) ;
V_3 . V_9 . V_66 -> V_67 ( & V_3 . V_9 , 0 ) ;
V_1 = V_3 . V_9 . V_66 -> V_68 ( & V_3 . V_9 ) ;
if ( V_1 ) {
F_2 ( L_11 ) ;
goto V_69;
}
V_1 = V_3 . V_9 . V_66 -> V_70 ( & V_3 . V_9 ) ;
if ( V_1 ) {
F_2 ( L_12 ) ;
goto V_69;
}
V_3 . V_9 . V_41 . V_25 . V_11 = V_3 . V_11 ;
V_3 . V_9 . V_41 . V_25 . V_10 = V_3 . V_10 ;
V_3 . V_9 . V_66 -> V_71 ( & V_3 . V_9 ) ;
F_19 ( V_72 ) ;
F_20 ( V_8 -> V_51 . V_73 . V_74 ) ;
F_21 ( 0 ) ;
F_22 ( V_8 -> V_64 . V_28 . V_30 ,
V_8 -> V_64 . V_28 . V_31 ) ;
V_3 . V_9 . V_66 -> V_67 ( & V_3 . V_9 , 1 ) ;
V_1 = F_23 ( V_8 -> V_63 ) ;
if ( V_1 )
goto V_75;
return 0 ;
V_75:
V_3 . V_9 . V_66 -> V_67 ( & V_3 . V_9 , 0 ) ;
V_3 . V_9 . V_66 -> V_76 ( & V_3 . V_9 ) ;
V_3 . V_9 . V_66 -> V_77 ( & V_3 . V_9 ) ;
V_69:
F_7 () ;
return - V_78 ;
}
static void F_24 ( struct V_7 * V_8 )
{
F_18 ( V_8 -> V_63 ) ;
V_3 . V_9 . V_66 -> V_67 ( & V_3 . V_9 , 0 ) ;
V_3 . V_9 . V_66 -> V_76 ( & V_3 . V_9 ) ;
V_3 . V_9 . V_66 -> V_77 ( & V_3 . V_9 ) ;
F_7 () ;
}
int F_25 ( struct V_7 * V_8 ,
struct V_16 * V_28 )
{
struct V_15 V_25 ;
V_25 = F_12 ( V_28 ) ;
if ( V_25 . V_10 == - 1 ) {
return - V_79 ;
}
return 0 ;
}
void F_26 ( struct V_7 * V_8 )
{
struct V_15 V_25 ;
V_25 = F_12 ( & V_8 -> V_64 . V_28 ) ;
V_3 . V_10 = V_25 . V_10 ;
V_3 . V_11 = V_25 . V_11 ;
if ( V_8 -> V_80 == V_81 ) {
int V_1 ;
F_24 ( V_8 ) ;
V_1 = F_17 ( V_8 ) ;
if ( V_1 )
F_27 ( L_13 ) ;
}
}
void F_28 ( struct V_82 * V_83 )
{
F_29 ( & V_3 . V_84 ) ;
if ( F_1 () )
return;
V_3 . V_9 . V_66 -> V_85 ( & V_3 . V_9 , V_83 ) ;
V_3 . V_9 . V_66 -> V_86 ( & V_3 . V_9 , V_83 ) ;
V_3 . V_9 . V_66 -> V_87 ( & V_3 . V_9 , V_83 ) ;
V_3 . V_9 . V_66 -> V_88 ( & V_3 . V_9 , V_83 ) ;
F_7 () ;
F_30 ( & V_3 . V_84 ) ;
}
int F_31 ( T_2 * V_89 , int V_90 )
{
int V_1 ;
F_29 ( & V_3 . V_84 ) ;
V_1 = F_1 () ;
F_32 ( V_1 ) ;
V_1 = V_3 . V_9 . V_66 -> V_91 ( & V_3 . V_9 , V_89 , V_90 ) ;
F_7 () ;
F_30 ( & V_3 . V_84 ) ;
return V_1 ;
}
bool F_33 ( void )
{
int V_1 ;
F_29 ( & V_3 . V_84 ) ;
V_1 = F_1 () ;
F_32 ( V_1 ) ;
V_1 = V_3 . V_9 . V_66 -> V_92 ( & V_3 . V_9 ) ;
F_7 () ;
F_30 ( & V_3 . V_84 ) ;
return V_1 == 1 ;
}
int F_34 ( struct V_7 * V_8 )
{
struct V_93 * V_94 = V_8 -> V_95 ;
int V_1 = 0 ;
F_2 ( L_14 ) ;
F_29 ( & V_3 . V_84 ) ;
if ( V_8 -> V_63 == NULL ) {
F_27 ( L_15 ) ;
V_1 = - V_96 ;
goto V_97;
}
V_3 . V_9 . V_98 = V_94 -> V_98 ;
V_1 = F_35 ( V_8 ) ;
if ( V_1 ) {
F_27 ( L_16 ) ;
goto V_97;
}
if ( V_8 -> V_99 ) {
V_1 = V_8 -> V_99 ( V_8 ) ;
if ( V_1 ) {
F_27 ( L_17 ) ;
goto V_100;
}
}
V_1 = F_17 ( V_8 ) ;
if ( V_1 ) {
F_27 ( L_13 ) ;
goto V_101;
}
F_30 ( & V_3 . V_84 ) ;
return 0 ;
V_101:
if ( V_8 -> V_102 )
V_8 -> V_102 ( V_8 ) ;
V_100:
F_36 ( V_8 ) ;
V_97:
F_30 ( & V_3 . V_84 ) ;
return V_1 ;
}
void F_37 ( struct V_7 * V_8 )
{
F_2 ( L_18 ) ;
F_29 ( & V_3 . V_84 ) ;
F_24 ( V_8 ) ;
if ( V_8 -> V_102 )
V_8 -> V_102 ( V_8 ) ;
F_36 ( V_8 ) ;
F_30 ( & V_3 . V_84 ) ;
}
static int F_38 ( struct V_103 * V_104 , int V_105 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 = V_104 -> V_110 ;
struct V_111 * V_112 = V_109 -> V_112 ;
struct V_113 * V_4 = F_39 ( V_112 -> V_5 ) ;
struct V_114 * V_9 = F_40 ( V_112 ) ;
int V_69 = 0 ;
if ( ! ( V_9 -> V_66 ) && ! ( V_9 -> V_66 -> V_115 ) ) {
F_41 ( & V_4 -> V_5 , L_19 ) ;
return - V_96 ;
}
switch ( V_105 ) {
case V_116 :
case V_117 :
case V_118 :
V_9 -> V_66 -> V_115 ( V_9 , true ) ;
break;
case V_119 :
case V_120 :
case V_121 :
V_9 -> V_66 -> V_115 ( V_9 , false ) ;
break;
default:
V_69 = - V_79 ;
}
return V_69 ;
}
static int F_42 ( struct V_103 * V_104 ,
struct V_122 * V_123 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 = V_104 -> V_110 ;
struct V_111 * V_112 = V_109 -> V_112 ;
struct V_114 * V_9 = F_40 ( V_112 ) ;
struct V_124 V_125 ;
struct V_126 V_127 ;
struct V_128 V_129 ;
struct V_130 V_131 ;
int V_69 , V_132 , V_133 ;
enum V_134 V_135 ;
switch ( F_43 ( V_123 ) ) {
case V_136 :
V_129 . V_137 . V_138 =
V_139 ;
V_129 . V_137 . V_140 = V_141 ;
V_129 . V_137 . V_142 =
V_143 ;
V_129 . V_137 . V_144 = V_145 ;
V_125 . V_146 = V_147 ;
V_125 . V_148 = V_149 ;
V_125 . V_144 = V_145 ;
V_127 . V_150 = 0x10 ;
break;
case V_151 :
V_129 . V_137 . V_138 =
V_152 ;
V_129 . V_137 . V_140 = V_153 ;
V_129 . V_137 . V_142 =
V_154 ;
V_125 . V_146 = V_155 ;
V_125 . V_148 = V_156 ;
V_125 . V_144 = V_157 ;
V_129 . V_137 . V_144 = V_157 ;
V_127 . V_150 = 0x20 ;
break;
default:
return - V_79 ;
}
switch ( F_44 ( V_123 ) ) {
case 32000 :
V_135 = V_158 ;
break;
case 44100 :
V_135 = V_159 ;
break;
case 48000 :
V_135 = V_160 ;
break;
default:
return - V_79 ;
}
V_69 = F_45 ( V_9 , F_44 ( V_123 ) , & V_132 , & V_133 ) ;
if ( V_69 < 0 )
return V_69 ;
V_125 . V_161 = V_162 ;
V_125 . V_163 = 0x03 ;
V_125 . type = V_164 ;
V_125 . V_165 = V_166 ;
V_125 . V_167 = V_168 ;
V_127 . V_169 = 0xC0 ;
V_127 . V_11 = V_170 ;
V_127 . V_171 = 0x20 ;
F_46 ( V_9 , & V_127 ) ;
F_47 ( V_9 , & V_125 ) ;
V_129 . V_137 . V_172 = false ;
V_129 . V_137 . V_173 = false ;
V_129 . V_137 . V_174 = V_175 ;
V_129 . V_137 . V_176 = V_177 ;
V_129 . V_137 . V_178 = V_179 ;
V_129 . V_137 . V_180 = V_181 ;
V_129 . V_137 . V_182 = V_183 ;
V_129 . V_137 . V_184 = V_185 ;
V_129 . V_186 = V_135 ;
V_129 . V_132 = V_132 ;
V_129 . V_133 = V_133 ;
if ( F_48 ( V_187 ) ) {
V_129 . V_188 = 0 ;
V_129 . V_189 = V_190 ;
V_129 . V_191 = false ;
} else {
V_129 . V_188 = ( ( ( 128 * 31 ) - 1 ) << 8 ) ;
V_129 . V_189 = V_192 ;
V_129 . V_191 = true ;
V_129 . V_193 = V_194 ;
}
V_129 . V_195 = V_196 ;
V_129 . V_197 = false ;
V_129 . V_198 = true ;
V_129 . V_199 = true ;
V_129 . V_200 = false ;
V_129 . V_201 = true ;
V_128 ( V_9 , & V_129 ) ;
V_131 . V_202 = V_203 ;
V_131 . V_204 = 2 ;
V_131 . V_205 = V_206 ;
V_131 . V_207 = V_208 ;
V_131 . V_209 = 0x00 ;
V_131 . V_210 = false ;
V_131 . V_211 = 0 ;
F_49 ( V_9 , & V_131 ) ;
return 0 ;
}
static int F_50 ( struct V_103 * V_104 ,
struct V_106 * V_107 )
{
if ( ! V_3 . V_11 ) {
F_51 ( L_20 ) ;
return - V_78 ;
}
return 0 ;
}
static int F_52 ( struct V_111 * V_112 )
{
struct V_114 * V_94 = & V_3 . V_9 ;
F_53 ( V_112 , V_94 ) ;
return 0 ;
}
static int F_54 ( struct V_113 * V_4 )
{
struct V_212 * V_212 ;
V_212 = F_55 ( & V_4 -> V_5 , L_21 ) ;
if ( F_56 ( V_212 ) ) {
F_27 ( L_22 ) ;
return F_57 ( V_212 ) ;
}
V_3 . V_50 = V_212 ;
return 0 ;
}
static void F_58 ( void )
{
if ( V_3 . V_50 )
F_59 ( V_3 . V_50 ) ;
}
static int F_60 ( struct V_113 * V_4 )
{
struct V_213 * V_214 ;
int V_1 ;
V_3 . V_215 = V_4 -> V_5 . V_216 ;
V_3 . V_4 = V_4 ;
F_61 ( & V_3 . V_84 ) ;
V_214 = F_62 ( V_3 . V_4 , V_217 , 0 ) ;
if ( ! V_214 ) {
F_27 ( L_23 ) ;
return - V_79 ;
}
V_3 . V_9 . V_218 = F_63 ( V_214 -> V_219 ,
F_64 ( V_214 ) ) ;
if ( ! V_3 . V_9 . V_218 ) {
F_27 ( L_24 ) ;
return - V_220 ;
}
V_1 = F_54 ( V_4 ) ;
if ( V_1 ) {
F_65 ( V_3 . V_9 . V_218 ) ;
return V_1 ;
}
F_66 ( & V_4 -> V_5 ) ;
V_3 . V_9 . V_221 = V_222 ;
V_3 . V_9 . V_223 = V_224 ;
V_3 . V_9 . V_225 = V_226 ;
V_3 . V_9 . V_227 = V_228 ;
F_67 () ;
#if F_68 ( V_229 ) || \
F_68 ( V_230 )
V_1 = F_69 ( & V_4 -> V_5 , & V_231 ,
& V_232 , 1 ) ;
if ( V_1 ) {
F_27 ( L_25 ) ;
return V_1 ;
}
#endif
return 0 ;
}
static int F_70 ( struct V_113 * V_4 )
{
F_71 () ;
#if F_68 ( V_229 ) || \
F_68 ( V_230 )
F_72 ( & V_4 -> V_5 ) ;
#endif
F_73 ( & V_4 -> V_5 ) ;
F_58 () ;
F_65 ( V_3 . V_9 . V_218 ) ;
return 0 ;
}
static int F_74 ( struct V_233 * V_5 )
{
F_75 ( V_3 . V_50 ) ;
F_76 () ;
F_6 () ;
return 0 ;
}
static int F_77 ( struct V_233 * V_5 )
{
int V_1 ;
V_1 = F_3 () ;
if ( V_1 < 0 )
goto V_2;
V_1 = F_78 () ;
if ( V_1 < 0 )
goto V_234;
F_79 ( V_3 . V_50 ) ;
return 0 ;
V_234:
F_6 () ;
V_2:
return V_1 ;
}
int F_80 ( void )
{
return F_81 ( & V_235 ) ;
}
void F_82 ( void )
{
return F_83 ( & V_235 ) ;
}
