static void F_1 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_6 ; V_5 ++ ) {
if ( V_3 != ( V_2 -> V_7 [ V_5 ] & 0x7f ) )
continue;
if ( V_4 )
V_2 -> V_7 [ V_5 ] |= V_8 ;
else
V_2 -> V_7 [ V_5 ] &= V_9 ;
return;
}
}
static void F_2 ( struct V_10 * V_11 )
{
struct V_12 * V_13 , * V_14 ;
if ( V_11 -> V_15 . V_16 )
F_3 ( & V_11 -> V_17 ) ;
if ( V_11 -> V_18 )
F_4 ( V_11 -> V_18 , V_11 ) ;
F_5 ( & V_11 -> V_19 ) ;
if ( V_11 -> V_20 ) {
F_6 ( V_11 -> V_20 ) ;
F_7 ( V_11 -> V_20 , L_1 , V_11 ) ;
}
if ( V_11 -> V_21 ) {
F_8 ( V_11 -> V_21 ) ;
V_11 -> V_21 = NULL ;
V_11 -> V_20 = NULL ;
}
while ( F_9 ( & V_11 -> V_22 ) > 0 )
F_10 () ;
for ( V_13 = V_11 -> V_23 ; V_13 ; V_13 = V_14 ) {
V_14 = V_13 -> V_14 ;
#ifdef F_11
F_12 ( V_13 -> V_24 ) ;
#endif
F_12 ( V_13 ) ;
}
}
static void F_13 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = F_14 ( V_26 ) ;
struct V_10 * V_11 = V_28 -> V_29 ;
if ( V_11 -> V_21 ) {
F_15 ( V_11 -> V_20 -> V_30 -> V_31 , false ) ;
F_16 ( V_11 -> V_20 -> V_30 -> V_31 ) ;
F_17 ( V_28 ) ;
}
F_2 ( V_11 ) ;
F_18 ( V_26 , NULL ) ;
F_19 ( V_28 ) ;
}
static void F_20 ( struct V_10 * V_11 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
F_21 ( V_11 -> V_15 . V_33 [ V_5 ] ) ;
F_21 ( V_11 -> V_15 . V_34 [ V_5 ] ) ;
}
}
static int F_22 ( struct V_10 * V_11 , struct V_25 * V_26 )
{
int V_35 ;
struct V_36 * V_36 = & V_26 -> V_37 ;
char V_38 [ 100 ] ;
int V_5 ;
memset ( & V_11 -> V_15 , 0 , sizeof( struct V_39 ) ) ;
for ( V_5 = 0 ; V_5 < V_32 ; V_5 ++ ) {
if ( V_40 [ V_5 ] == NULL )
break;
sprintf ( V_38 , L_2 , V_40 [ V_5 ] ,
V_41 ) ;
V_35 = F_23 ( & V_11 -> V_15 . V_33 [ V_5 ] , V_38 , V_36 ) ;
if ( V_35 ) {
F_24 ( V_11 -> V_31 , L_3 ,
V_42 , V_38 ) ;
return V_35 ;
}
sprintf ( V_38 , L_4 , V_40 [ V_5 ] ,
V_41 ) ;
V_35 = F_23 ( & V_11 -> V_15 . V_34 [ V_5 ] , V_38 , V_36 ) ;
if ( V_35 ) {
F_24 ( V_11 -> V_31 , L_3 ,
V_42 , V_38 ) ;
return V_35 ;
}
V_11 -> V_15 . V_43 [ V_5 ] =
V_11 -> V_15 . V_34 [ V_5 ] -> V_44 / ( sizeof( struct V_45 ) ) ;
}
V_11 -> V_15 . V_16 = V_5 ;
V_35 = F_25 ( V_11 , & V_11 -> V_17 ) ;
F_20 ( V_11 ) ;
return V_35 ;
}
static void F_26 ( struct V_27 * V_28 ,
struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
struct V_50 * V_51 = F_27 ( V_49 ) ;
F_28 ( & V_11 -> V_52 ) ;
if ( ! V_11 -> V_20 -> V_53 ) {
F_29 ( V_11 -> V_21 -> V_28 -> V_54 , L_5 ) ;
F_30 ( V_49 ) ;
goto V_55;
}
if ( F_31 ( V_11 -> V_21 , V_49 , V_28 ) )
V_51 -> V_56 [ 0 ] = V_47 -> V_57 ;
V_55:
F_32 ( & V_11 -> V_52 ) ;
}
static int F_33 ( struct V_27 * V_28 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
bool V_58 ;
int V_59 ;
F_34 ( V_28 ) ;
F_28 ( & V_11 -> V_52 ) ;
V_58 = F_35 ( V_11 ) ;
F_32 ( & V_11 -> V_52 ) ;
if ( ! V_58 )
F_16 ( V_11 -> V_20 -> V_30 -> V_31 ) ;
if ( ! V_11 -> V_17 . V_60 ) {
V_59 = F_22 ( V_11 , V_11 -> V_21 -> V_28 -> V_54 ) ;
if ( V_59 ) {
F_13 ( V_11 -> V_21 -> V_28 -> V_54 ) ;
return - V_61 ;
}
}
F_28 ( & V_11 -> V_52 ) ;
V_11 -> V_62 = true ;
if ( ! V_11 -> V_20 -> V_53 )
if ( ! V_58 )
V_59 = F_36 ( V_11 ) ;
else
V_59 = - V_63 ;
else
V_59 = - V_64 ;
F_32 ( & V_11 -> V_52 ) ;
if ( V_59 != 0 )
F_29 ( V_11 -> V_21 -> V_28 -> V_54 , L_6 ,
V_65 , V_59 ) ;
return V_59 ;
}
static void F_37 ( struct V_27 * V_28 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
int V_35 ;
F_38 ( V_28 ) ;
if ( V_11 -> V_21 == NULL )
return;
F_28 ( & V_11 -> V_52 ) ;
V_35 = F_39 ( V_11 -> V_21 -> V_28 -> V_54 ) ;
F_32 ( & V_11 -> V_52 ) ;
if ( ! V_35 ) {
F_29 ( V_11 -> V_21 -> V_28 -> V_54 ,
L_7 ) ;
return;
}
F_28 ( & V_11 -> V_52 ) ;
F_40 ( V_11 ) ;
F_32 ( & V_11 -> V_52 ) ;
}
static int
F_41 ( struct V_27 * V_28 , struct V_66 * V_67 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
if ( V_67 -> type != V_68 ) {
F_29 ( V_11 -> V_21 -> V_28 -> V_54 ,
L_8 ,
V_65 , V_67 -> type ) ;
return - V_69 ;
}
F_28 ( & V_11 -> V_52 ) ;
memcpy ( V_11 -> V_20 -> V_70 , V_67 -> V_71 , sizeof( V_67 -> V_71 ) ) ;
V_11 -> V_62 = false ;
F_42 ( V_11 -> V_21 , false ) ;
F_32 ( & V_11 -> V_52 ) ;
return 0 ;
}
static void
F_43 ( struct V_27 * V_28 , struct V_66 * V_67 )
{
}
static int F_44 ( struct V_27 * V_28 , T_2 V_72 )
{
struct V_73 * V_74 = & V_28 -> V_74 ;
struct V_10 * V_11 = V_28 -> V_29 ;
struct V_25 * V_75 = V_11 -> V_21 -> V_28 -> V_54 ;
int V_59 = 0 ;
int V_76 ;
F_28 ( & V_11 -> V_52 ) ;
if ( V_72 & V_77 ) {
F_45 ( V_11 -> V_21 ,
V_74 -> V_78 ) ;
}
if ( V_72 & V_79 )
F_46 ( V_75 , L_9 ,
V_65 , V_74 -> V_80 & V_81 ?
L_10 : L_11 ) ;
if ( V_72 & V_82 )
F_29 ( V_75 , L_12 ,
V_65 , V_74 -> V_80 & V_83 ?
L_10 : L_11 ) ;
if ( V_72 & V_84 ) {
V_59 = F_47 ( V_11 -> V_21 , V_74 -> V_85 ) ;
if ( V_59 < 0 ) {
F_29 ( V_75 , L_13 ,
V_65 ) ;
goto V_86;
}
V_76 = F_48 ( V_11 -> V_21 ) ;
if ( V_76 != V_74 -> V_85 )
F_29 ( V_75 ,
L_14 ,
V_65 , V_74 -> V_85 ,
V_76 ) ;
}
if ( V_72 & V_87 ) {
if ( V_74 -> V_88 == V_89 ||
V_74 -> V_88 == V_90 )
V_59 = F_49 ( V_11 -> V_21 ,
V_74 -> V_91 -> V_92 ) ;
else
V_59 = - V_93 ;
}
if ( V_72 & V_94 )
V_59 = F_50 ( V_11 -> V_21 ,
V_74 -> V_95 ,
V_74 -> V_96 ) ;
V_86:
F_32 ( & V_11 -> V_52 ) ;
return V_59 ;
}
static void
F_51 ( struct V_27 * V_28 ,
struct V_66 * V_67 ,
struct V_97 * V_98 , T_2 V_72 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
struct V_25 * V_75 = V_11 -> V_21 -> V_28 -> V_54 ;
if ( V_72 & V_99 ) {
F_29 ( V_75 , L_15 , V_42 ,
V_65 , V_98 -> V_100 ? L_16 : L_17 ) ;
F_28 ( & V_11 -> V_52 ) ;
F_52 ( V_11 -> V_21 , V_98 -> V_100 ) ;
F_32 ( & V_11 -> V_52 ) ;
}
if ( V_72 & V_101 ) {
T_3 V_102 ;
if ( V_98 -> V_103 )
V_102 = 1 ;
else
V_102 = 0 ;
F_28 ( & V_11 -> V_52 ) ;
F_53 ( V_11 -> V_21 , V_102 ) ;
F_32 ( & V_11 -> V_52 ) ;
}
if ( V_72 & V_104 ) {
T_1 V_105 = V_98 -> V_106 ;
F_28 ( & V_11 -> V_52 ) ;
F_54 ( V_11 -> V_21 , V_107 ,
V_105 & V_108 ) ;
F_54 ( V_11 -> V_21 , V_109 ,
V_105 & V_110 ) ;
F_54 ( V_11 -> V_21 , V_111 ,
V_105 & V_112 ) ;
F_32 ( & V_11 -> V_52 ) ;
}
if ( V_72 & V_113 ) {
struct V_114 * V_115 ;
T_2 V_116 , V_5 ;
T_1 V_3 ;
struct V_1 V_2 ;
int error ;
F_28 ( & V_11 -> V_52 ) ;
F_55 ( V_11 -> V_21 , & V_2 ) ;
F_32 ( & V_11 -> V_52 ) ;
V_116 = V_98 -> V_117 ;
V_115 = V_28 -> V_31 -> V_118 [ F_56 ( V_11 -> V_21 ) ] ;
for ( V_5 = 0 ; V_5 < V_115 -> V_119 ; V_5 ++ ) {
V_3 = ( V_115 -> V_120 [ V_5 ] . V_121 << 1 ) / 10 ;
F_1 ( & V_2 , V_3 , V_116 & 1 ) ;
V_116 >>= 1 ;
}
F_28 ( & V_11 -> V_52 ) ;
error = F_57 ( V_11 -> V_21 , & V_2 ) ;
F_32 ( & V_11 -> V_52 ) ;
if ( error )
F_29 ( V_75 , L_18 ,
error ) ;
}
if ( V_72 & V_122 ) {
F_28 ( & V_11 -> V_52 ) ;
F_58 ( V_11 -> V_21 , V_98 -> V_123 ) ;
F_32 ( & V_11 -> V_52 ) ;
}
if ( V_72 & V_124 ) {
F_28 ( & V_11 -> V_52 ) ;
F_59 ( V_11 -> V_21 , V_125 , V_98 -> V_126 ) ;
F_32 ( & V_11 -> V_52 ) ;
}
if ( V_72 & V_127 )
F_29 ( V_75 , L_19 , V_65 ) ;
if ( V_72 & V_128 ) {
F_29 ( V_75 , L_20 , V_65 ,
V_98 -> V_129 ? L_10 : L_11 ) ;
}
if ( V_72 & V_130 ) {
F_29 ( V_75 , L_21
L_22 , V_65 , V_98 -> V_131 ,
V_98 -> V_132 ) ;
}
if ( V_72 & V_133 ) {
F_29 ( V_75 , L_23 ,
V_65 , V_98 -> V_134 ? L_10 : L_11 ) ;
}
if ( V_72 & V_135 ) {
F_29 ( V_75 , L_24
L_22 , V_65 , V_98 -> V_136 ) ;
}
if ( V_72 & V_137 ) {
F_29 ( V_75 , L_25 ,
V_65 , V_98 -> V_138 ? L_10 : L_11 ) ;
}
return;
}
static void
F_60 ( struct V_27 * V_28 ,
unsigned int V_139 ,
unsigned int * V_140 , T_4 V_141 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
struct V_25 * V_75 = V_11 -> V_21 -> V_28 -> V_54 ;
V_139 &= V_142 ;
* V_140 &= V_142 ;
if ( V_139 & V_143 )
F_46 ( V_75 , L_26 ) ;
if ( V_139 & V_144 )
F_46 ( V_75 , L_27 ) ;
if ( V_139 & V_145 )
F_46 ( V_75 , L_28 ) ;
if ( V_139 & V_146 )
F_46 ( V_75 , L_29 ) ;
if ( V_139 & V_147 )
F_46 ( V_75 , L_30 ) ;
if ( V_139 & V_148 )
F_46 ( V_75 , L_31 ) ;
if ( V_139 & V_149 )
F_46 ( V_75 , L_32 ) ;
F_28 ( & V_11 -> V_52 ) ;
F_61 ( V_11 -> V_21 , * V_140 ) ;
F_32 ( & V_11 -> V_52 ) ;
return;
}
static void F_62 ( struct V_27 * V_28 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
F_28 ( & V_11 -> V_52 ) ;
F_63 ( V_11 -> V_21 ) ;
F_32 ( & V_11 -> V_52 ) ;
return;
}
static void F_64 ( struct V_27 * V_28 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
F_28 ( & V_11 -> V_52 ) ;
F_65 ( V_11 -> V_21 ) ;
F_32 ( & V_11 -> V_52 ) ;
return;
}
static int
F_66 ( struct V_27 * V_28 , struct V_66 * V_67 , T_1 V_150 ,
const struct V_151 * V_152 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
F_28 ( & V_11 -> V_52 ) ;
F_67 ( V_11 -> V_21 , V_150 , V_152 , true ) ;
F_32 ( & V_11 -> V_52 ) ;
return 0 ;
}
static int
F_68 ( struct V_27 * V_28 , struct V_66 * V_67 ,
struct V_153 * V_57 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
struct V_154 * V_154 = & V_11 -> V_21 -> V_155 ;
F_69 ( V_154 ) ;
V_11 -> V_20 -> V_156 = & ( V_154 -> V_157 ) ;
V_11 -> V_20 -> V_156 -> V_154 = V_154 ;
V_11 -> V_20 -> V_156 -> V_158 = 16 ;
return 0 ;
}
static int
F_70 ( struct V_27 * V_28 ,
struct V_66 * V_67 ,
enum V_159 V_160 ,
struct V_153 * V_57 , T_1 V_161 , T_1 * V_162 ,
T_5 V_163 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
struct V_154 * V_154 = & V_11 -> V_21 -> V_155 ;
int V_35 ;
if ( F_71 ( V_154 -> V_164 != V_165 ) )
return - V_166 ;
switch ( V_160 ) {
case V_167 :
break;
case V_168 :
break;
case V_169 :
F_28 ( & V_11 -> V_52 ) ;
V_35 = F_72 ( V_11 -> V_21 , V_161 ) ;
F_32 ( & V_11 -> V_52 ) ;
if ( ! V_35 ) {
F_29 ( V_11 -> V_21 -> V_28 -> V_54 ,
L_33 , V_161 ) ;
return - V_170 ;
}
F_73 ( V_67 , V_57 -> V_71 , V_161 ) ;
break;
case V_171 :
case V_172 :
case V_173 :
F_28 ( & V_11 -> V_52 ) ;
F_74 ( V_11 -> V_21 , V_57 , V_161 ) ;
F_32 ( & V_11 -> V_52 ) ;
F_75 ( V_67 , V_57 -> V_71 , V_161 ) ;
break;
case V_174 :
F_28 ( & V_11 -> V_52 ) ;
F_76 ( V_11 -> V_21 , V_161 , V_163 ,
( 1 << ( V_175 +
V_57 -> V_176 . V_177 ) ) - 1 ) ;
F_32 ( & V_11 -> V_52 ) ;
break;
default:
F_29 ( V_11 -> V_21 -> V_28 -> V_54 ,
L_34 , V_65 ) ;
}
return 0 ;
}
static void F_77 ( struct V_27 * V_28 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
bool V_58 ;
F_28 ( & V_11 -> V_52 ) ;
V_58 = F_78 ( V_11 -> V_21 ) ;
F_32 ( & V_11 -> V_52 ) ;
F_15 ( V_11 -> V_20 -> V_30 -> V_31 , V_58 ) ;
}
static bool F_79 ( struct V_10 * V_11 )
{
bool V_178 ;
F_28 ( & V_11 -> V_52 ) ;
V_178 = F_80 ( V_11 -> V_21 ) ;
F_32 ( & V_11 -> V_52 ) ;
return V_178 ;
}
static void F_81 ( struct V_27 * V_28 , bool V_179 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
int V_180 ;
F_82 ( L_35 , V_65 , V_179 ? L_10 : L_11 ) ;
V_180 = F_83 ( V_11 -> V_181 ,
F_79 ( V_11 ) ,
F_84 ( V_182 ) ) ;
F_85 ( V_11 -> V_21 -> V_28 -> V_54 ,
L_36 , F_86 ( V_180 ) ) ;
}
void F_87 ( unsigned long V_183 )
{
struct V_10 * V_11 ;
V_11 = (struct V_10 * ) V_183 ;
F_28 ( & V_11 -> V_52 ) ;
if ( V_11 -> V_20 -> V_53 ) {
if ( V_11 -> V_184 ) {
unsigned long V_80 ;
F_88 ( & V_11 -> V_185 , V_80 ) ;
F_89 ( V_11 -> V_21 ) ;
F_90 ( & V_11 -> V_185 , V_80 ) ;
}
V_11 -> V_184 = F_91 ( V_11 -> V_21 , true ) ;
}
if ( ! V_11 -> V_20 -> V_53 )
goto V_55;
if ( V_11 -> V_184 )
F_92 ( & V_11 -> V_19 ) ;
else
F_93 ( V_11 ) ;
V_55:
F_32 ( & V_11 -> V_52 ) ;
F_94 ( & V_11 -> V_181 ) ;
}
static T_6 F_95 ( int V_18 , void * V_186 )
{
struct V_10 * V_11 ;
T_6 V_180 = V_187 ;
V_11 = (struct V_10 * ) V_186 ;
F_96 ( & V_11 -> V_185 ) ;
if ( F_97 ( V_11 -> V_21 ) ) {
F_92 ( & V_11 -> V_19 ) ;
V_180 = V_188 ;
}
F_98 ( & V_11 -> V_185 ) ;
return V_180 ;
}
static int F_99 ( struct V_27 * V_28 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
struct V_189 * V_21 = V_11 -> V_21 ;
struct V_114 * V_190 ;
int V_191 = 0 ;
T_1 V_192 ;
V_28 -> V_31 -> V_118 [ V_193 ] = NULL ;
V_28 -> V_31 -> V_118 [ V_194 ] = NULL ;
V_192 = F_100 ( V_11 -> V_21 , 0 ) ;
if ( V_192 == V_195 || V_192 == V_196 ) {
V_190 = & V_21 -> V_197 [ V_198 ] -> V_190 ;
* V_190 = V_199 ;
if ( V_192 == V_196 ) {
V_190 -> V_176 . V_200 . V_201 [ 1 ] = 0 ;
V_190 -> V_176 . V_200 . V_202 = F_101 ( 72 ) ;
}
V_28 -> V_31 -> V_118 [ V_193 ] = V_190 ;
} else {
return - V_203 ;
}
if ( V_11 -> V_20 -> V_204 > 1 ) {
V_191 ++ ;
if ( V_192 == V_195 || V_192 == V_196 ) {
V_190 = & V_21 -> V_197 [ V_205 ] -> V_190 ;
* V_190 = V_206 ;
V_28 -> V_31 -> V_118 [ V_194 ] = V_190 ;
} else {
return - V_203 ;
}
}
return 0 ;
}
static int F_102 ( struct V_27 * V_28 )
{
V_28 -> V_80 = V_207
| V_208
| V_209 ;
V_28 -> V_210 = F_103 () ;
V_28 -> V_211 = V_212 ;
V_28 -> V_213 = 2 ;
V_28 -> V_214 = 7 * 1000 ;
V_28 -> V_31 -> V_215 = F_104 ( V_68 ) ;
V_28 -> V_216 = L_37 ;
V_28 -> V_217 = 0 ;
return F_99 ( V_28 ) ;
}
static struct V_10 * F_105 ( struct V_25 * V_26 )
{
struct V_10 * V_11 = NULL ;
int V_218 , V_59 ;
struct V_27 * V_28 ;
T_5 V_219 [ V_220 ] ;
V_218 = V_221 ;
V_59 = 0 ;
if ( V_218 < 0 )
return NULL ;
V_28 = F_14 ( V_26 ) ;
if ( V_28 != NULL )
V_11 = V_28 -> V_29 ;
if ( F_71 ( V_28 == NULL ) || F_71 ( V_11 == NULL ) )
return NULL ;
V_11 -> V_31 = V_28 -> V_31 ;
F_106 ( & V_11 -> V_22 , 0 ) ;
F_107 ( & V_11 -> V_181 ) ;
F_108 ( & V_11 -> V_19 , F_87 , ( unsigned long ) V_11 ) ;
F_109 ( & V_11 -> V_52 ) ;
F_109 ( & V_11 -> V_185 ) ;
V_11 -> V_21 = F_110 ( ( void * ) V_11 , V_26 , V_218 , false , & V_59 ) ;
if ( ! V_11 -> V_21 ) {
F_24 ( V_11 -> V_31 , L_38 ,
V_42 , V_59 ) ;
goto V_222;
}
V_11 -> V_20 = F_111 ( V_11 -> V_21 ) ;
V_11 -> V_20 -> V_30 = V_28 ;
if ( F_112 ( V_26 -> V_18 , F_95 ,
V_223 , V_42 , V_11 ) ) {
F_24 ( V_11 -> V_31 , L_39 , V_218 ) ;
goto V_222;
}
V_11 -> V_18 = V_26 -> V_18 ;
F_113 ( V_11 -> V_20 , L_1 , V_11 , NULL ) ;
if ( F_102 ( V_28 ) ) {
F_24 ( V_11 -> V_31 , L_40 , V_218 ,
V_65 ) ;
goto V_222;
}
F_114 ( V_11 -> V_21 ) ;
memcpy ( V_219 , & V_11 -> V_20 -> V_70 , V_220 ) ;
if ( F_71 ( ! F_115 ( V_219 ) ) )
goto V_222;
F_116 ( V_28 , V_219 ) ;
V_59 = F_117 ( V_28 ) ;
if ( V_59 )
F_24 ( V_11 -> V_31 , L_41
L_42 , V_65 , V_59 ) ;
if ( V_11 -> V_20 -> V_224 [ 0 ] &&
F_118 ( V_11 -> V_31 , V_11 -> V_20 -> V_224 ) )
F_24 ( V_11 -> V_31 , L_43 , V_65 ) ;
F_119 ( V_11 -> V_20 ) ;
F_120 ( V_11 -> V_20 ) ;
V_221 ++ ;
return V_11 ;
V_222:
F_2 ( V_11 ) ;
return NULL ;
}
static int F_121 ( struct V_25 * V_26 )
{
struct V_10 * V_11 ;
struct V_27 * V_28 ;
F_122 ( & V_26 -> V_37 , L_44 ,
V_26 -> V_225 . V_226 , V_26 -> V_225 . V_225 , V_26 -> V_225 . V_227 , V_26 -> V_225 . V_228 ,
V_26 -> V_18 ) ;
if ( ( V_26 -> V_225 . V_226 != V_229 ) ||
( V_26 -> V_225 . V_225 != V_230 ) )
return - V_64 ;
V_28 = F_123 ( sizeof( struct V_10 ) , & V_231 ) ;
if ( ! V_28 ) {
F_124 ( L_45 , V_65 ) ;
return - V_232 ;
}
F_125 ( V_28 , & V_26 -> V_37 ) ;
F_18 ( V_26 , V_28 ) ;
memset ( V_28 -> V_29 , 0 , sizeof( * V_11 ) ) ;
V_11 = F_105 ( V_26 ) ;
if ( ! V_11 ) {
F_124 ( L_46 , V_65 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_126 ( struct V_25 * V_26 )
{
struct V_10 * V_11 ;
struct V_27 * V_28 ;
V_28 = F_14 ( V_26 ) ;
V_11 = V_28 -> V_29 ;
if ( ! V_11 ) {
F_124 ( L_47 , V_42 ,
V_65 ) ;
return - V_64 ;
}
F_28 ( & V_11 -> V_52 ) ;
V_11 -> V_20 -> V_233 = false ;
F_32 ( & V_11 -> V_52 ) ;
F_46 ( V_11 -> V_21 -> V_28 -> V_54 , L_48 ) ;
return 0 ;
}
static int F_127 ( struct V_25 * V_26 )
{
return 0 ;
}
static void F_128 ( struct V_234 * V_235 )
{
int error ;
error = F_129 ( & V_236 ) ;
if ( error )
F_124 ( L_49 , V_65 , error ) ;
}
static int T_7 F_130 ( void )
{
F_131 () ;
if ( ! F_132 ( & V_237 ) )
return - V_238 ;
return 0 ;
}
static void T_8 F_133 ( void )
{
F_134 ( & V_237 ) ;
F_135 ( & V_236 ) ;
F_136 () ;
}
void F_137 ( struct V_10 * V_11 , struct V_239 * V_240 ,
bool V_241 , int V_242 )
{
F_29 ( V_11 -> V_21 -> V_28 -> V_54 , L_50 , V_65 ) ;
}
void F_138 ( struct V_10 * V_11 )
{
F_46 ( V_11 -> V_21 -> V_28 -> V_54 , L_51 ,
V_11 -> V_20 -> V_218 ) ;
F_139 ( V_11 ) ;
F_140 ( V_11 -> V_21 , V_11 -> V_62 ) ;
}
T_9 F_139 ( struct V_10 * V_11 )
{
F_46 ( V_11 -> V_21 -> V_28 -> V_54 , L_52 , V_11 -> V_20 -> V_218 ) ;
F_141 ( V_11 -> V_21 ) ;
V_11 -> V_184 = false ;
V_11 -> V_20 -> V_53 = false ;
return 0 ;
}
void F_142 ( struct V_10 * V_11 )
{
F_29 ( V_11 -> V_21 -> V_28 -> V_54 , L_53 ,
V_11 -> V_21 -> V_20 -> V_218 ) ;
F_139 ( V_11 ) ;
F_143 ( V_11 -> V_20 -> V_30 ) ;
}
void F_93 ( struct V_10 * V_11 )
{
unsigned long V_80 ;
F_88 ( & V_11 -> V_185 , V_80 ) ;
F_144 ( V_11 -> V_21 ) ;
F_90 ( & V_11 -> V_185 , V_80 ) ;
}
T_2 F_145 ( struct V_10 * V_11 )
{
unsigned long V_80 ;
T_2 V_35 ;
F_88 ( & V_11 -> V_185 , V_80 ) ;
V_35 = F_146 ( V_11 -> V_21 ) ;
F_90 ( & V_11 -> V_185 , V_80 ) ;
return V_35 ;
}
void F_147 ( struct V_10 * V_11 , T_2 V_243 )
{
unsigned long V_80 ;
F_88 ( & V_11 -> V_185 , V_80 ) ;
F_148 ( V_11 -> V_21 , V_243 ) ;
F_90 ( & V_11 -> V_185 , V_80 ) ;
}
int F_36 ( struct V_10 * V_11 )
{
int error = 0 ;
if ( V_11 -> V_20 -> V_53 )
return 0 ;
error = F_149 ( V_11 -> V_21 ) ;
return error ;
}
void F_40 ( struct V_10 * V_11 )
{
T_9 V_22 , V_244 = 0 ;
V_244 = F_150 ( V_11 -> V_21 ) ;
V_22 = F_9 ( & V_11 -> V_22 ) - V_244 ;
F_32 ( & V_11 -> V_52 ) ;
F_151 ( ( F_9 ( & V_11 -> V_22 ) > V_22 ) , 100 * 1000 ) ;
F_28 ( & V_11 -> V_52 ) ;
}
static void F_152 ( struct V_234 * V_235 )
{
struct V_12 * V_13 = F_153 ( V_235 , struct V_12 ,
V_245 . V_235 ) ;
F_28 ( & V_13 -> V_11 -> V_52 ) ;
if ( V_13 -> V_246 ) {
if ( V_13 -> V_247 ) {
F_154 ( & V_13 -> V_11 -> V_22 ) ;
F_155 ( V_13 -> V_11 -> V_20 -> V_30 ,
& V_13 -> V_245 ,
F_84 ( V_13 -> V_248 ) ) ;
} else {
V_13 -> V_246 = false ;
}
V_13 -> V_249 ( V_13 -> V_250 ) ;
}
F_156 ( & V_13 -> V_11 -> V_22 ) ;
F_32 ( & V_13 -> V_11 -> V_52 ) ;
}
struct V_12 * F_157 ( struct V_10 * V_11 ,
void (* V_249) ( void * V_250 ) ,
void * V_250 , const char * V_24 )
{
struct V_12 * V_13 ;
V_13 = F_158 ( sizeof( struct V_12 ) , V_251 ) ;
if ( ! V_13 )
return NULL ;
F_159 ( & V_13 -> V_245 , F_152 ) ;
V_13 -> V_11 = V_11 ;
V_13 -> V_249 = V_249 ;
V_13 -> V_250 = V_250 ;
V_13 -> V_14 = V_11 -> V_23 ;
V_11 -> V_23 = V_13 ;
#ifdef F_11
V_13 -> V_24 = F_160 ( strlen ( V_24 ) + 1 , V_251 ) ;
if ( V_13 -> V_24 )
strcpy ( V_13 -> V_24 , V_24 ) ;
#endif
return V_13 ;
}
void F_161 ( struct V_12 * V_13 , T_9 V_248 , int V_247 )
{
struct V_27 * V_28 = V_13 -> V_11 -> V_20 -> V_30 ;
#ifdef F_11
if ( V_13 -> V_246 )
F_46 ( V_13 -> V_11 -> V_21 -> V_28 -> V_54 ,
L_54 ,
V_65 , V_13 -> V_24 , V_247 ) ;
#endif
V_13 -> V_248 = V_248 ;
V_13 -> V_247 = ( bool ) V_247 ;
if ( ! V_13 -> V_246 ) {
V_13 -> V_246 = true ;
F_154 ( & V_13 -> V_11 -> V_22 ) ;
}
F_155 ( V_28 , & V_13 -> V_245 , F_84 ( V_248 ) ) ;
}
bool F_162 ( struct V_12 * V_13 )
{
if ( V_13 -> V_246 ) {
V_13 -> V_246 = false ;
if ( ! F_163 ( & V_13 -> V_245 ) )
return false ;
F_156 ( & V_13 -> V_11 -> V_22 ) ;
}
return true ;
}
void F_164 ( struct V_12 * V_13 )
{
struct V_10 * V_11 = V_13 -> V_11 ;
struct V_12 * V_252 ;
F_162 ( V_13 ) ;
if ( V_11 -> V_23 == V_13 ) {
V_11 -> V_23 = V_11 -> V_23 -> V_14 ;
#ifdef F_11
F_12 ( V_13 -> V_24 ) ;
#endif
F_12 ( V_13 ) ;
return;
}
V_252 = V_11 -> V_23 ;
while ( V_252 ) {
if ( V_252 -> V_14 == V_13 ) {
V_252 -> V_14 = V_13 -> V_14 ;
#ifdef F_11
F_12 ( V_13 -> V_24 ) ;
#endif
F_12 ( V_13 ) ;
return;
}
V_252 = V_252 -> V_14 ;
}
}
int F_165 ( struct V_10 * V_11 , void * * V_253 , T_2 V_254 )
{
int V_5 , V_255 ;
const T_5 * V_256 ;
struct V_45 * V_257 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_15 . V_16 ; V_5 ++ ) {
V_257 = (struct V_45 * ) V_11 -> V_15 . V_34 [ V_5 ] -> V_183 ;
for ( V_255 = 0 ; V_255 < V_11 -> V_15 . V_43 [ V_5 ] ;
V_255 ++ , V_257 ++ ) {
T_2 V_258 = F_166 ( V_257 -> V_258 ) ;
if ( F_166 ( V_257 -> V_254 ) == V_254 ) {
V_256 = V_11 -> V_15 . V_33 [ V_5 ] -> V_183 +
F_166 ( V_257 -> V_259 ) ;
* V_253 = F_167 ( V_256 , V_258 , V_251 ) ;
if ( * V_253 == NULL )
goto V_222;
return 0 ;
}
}
}
F_29 ( V_11 -> V_21 -> V_28 -> V_54 ,
L_55 , V_254 ) ;
* V_253 = NULL ;
V_222:
return - V_260 ;
}
int F_168 ( struct V_10 * V_11 , T_10 * V_261 , T_2 V_254 )
{
int V_5 , V_255 ;
const T_5 * V_256 ;
struct V_45 * V_257 ;
for ( V_5 = 0 ; V_5 < V_11 -> V_15 . V_16 ; V_5 ++ ) {
V_257 = (struct V_45 * ) V_11 -> V_15 . V_34 [ V_5 ] -> V_183 ;
for ( V_255 = 0 ; V_255 < V_11 -> V_15 . V_43 [ V_5 ] ;
V_255 ++ , V_257 ++ ) {
if ( F_166 ( V_257 -> V_254 ) == V_254 ) {
V_256 = V_11 -> V_15 . V_33 [ V_5 ] -> V_183 +
F_166 ( V_257 -> V_259 ) ;
if ( F_166 ( V_257 -> V_258 ) != 4 ) {
F_29 ( V_11 -> V_21 -> V_28 -> V_54 ,
L_56 ) ;
return - V_262 ;
}
* V_261 = F_166 ( * ( ( V_263 * ) V_256 ) ) ;
return 0 ;
}
}
}
F_29 ( V_11 -> V_21 -> V_28 -> V_54 ,
L_57 , V_254 ) ;
return - V_262 ;
}
void F_169 ( void * V_264 )
{
F_12 ( V_264 ) ;
}
int F_170 ( struct V_10 * V_11 )
{
int V_5 ;
int V_255 ;
int V_265 = 0 ;
const struct V_266 * V_15 ;
const struct V_266 * V_34 ;
struct V_45 * V_267 ;
for ( V_5 = 0 ; V_5 < V_32 && V_265 == 0 ; V_5 ++ ) {
V_15 = V_11 -> V_15 . V_33 [ V_5 ] ;
V_34 = V_11 -> V_15 . V_34 [ V_5 ] ;
if ( V_15 == NULL && V_34 == NULL ) {
break;
} else if ( V_15 == NULL || V_34 == NULL ) {
F_24 ( V_11 -> V_31 , L_58 ,
V_65 ) ;
V_265 = - V_268 ;
} else if ( V_34 -> V_44 % sizeof( struct V_45 ) ) {
F_24 ( V_11 -> V_31 , L_59
L_60 , V_65 , V_34 -> V_44 ,
sizeof( struct V_45 ) ) ;
V_265 = - V_268 ;
} else if ( V_15 -> V_44 < V_269 || V_15 -> V_44 > V_270 ) {
F_24 ( V_11 -> V_31 , L_61 ,
V_65 , V_15 -> V_44 ) ;
V_265 = - V_268 ;
} else {
V_267 = (struct V_45 * ) V_34 -> V_183 ;
for ( V_255 = 0 ; V_255 < V_11 -> V_15 . V_43 [ V_5 ] &&
! V_265 ; V_255 ++ , V_267 ++ ) {
if ( F_166 ( V_267 -> V_259 ) +
F_166 ( V_267 -> V_258 ) >
V_15 -> V_44 ) {
F_24 ( V_11 -> V_31 ,
L_62 ,
V_65 ) ;
V_265 = - V_268 ;
}
}
}
}
if ( V_265 == 0 && V_11 -> V_15 . V_16 != V_5 ) {
F_24 ( V_11 -> V_31 , L_63 , V_65 ,
V_11 -> V_15 . V_16 ) ;
V_265 = - V_268 ;
}
return V_265 ;
}
bool F_35 ( struct V_10 * V_11 )
{
bool V_58 = F_78 ( V_11 -> V_21 ) ;
F_32 ( & V_11 -> V_52 ) ;
F_15 ( V_11 -> V_20 -> V_30 -> V_31 , V_58 ) ;
if ( V_58 )
F_171 ( V_11 -> V_20 -> V_30 -> V_31 ) ;
F_28 ( & V_11 -> V_52 ) ;
return V_58 ;
}
