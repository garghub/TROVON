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
static void F_2 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_17 * V_18 = F_3 ( V_13 ) ;
F_4 ( & V_15 -> V_19 ) ;
if ( ! V_15 -> V_20 -> V_21 ) {
F_5 ( V_15 -> V_22 , L_1 ) ;
F_6 ( V_13 ) ;
goto V_23;
}
F_7 ( V_15 -> V_24 , V_13 , V_11 ) ;
V_18 -> V_25 [ 0 ] = V_18 -> V_26 . V_27 ;
V_23:
F_8 ( & V_15 -> V_19 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
bool V_28 ;
int V_29 ;
F_10 ( V_11 ) ;
F_4 ( & V_15 -> V_19 ) ;
V_28 = F_11 ( V_15 ) ;
F_8 ( & V_15 -> V_19 ) ;
if ( ! V_28 )
F_12 ( V_15 -> V_20 -> V_30 -> V_22 ) ;
F_4 ( & V_15 -> V_19 ) ;
V_15 -> V_31 = true ;
if ( ! V_15 -> V_20 -> V_21 )
V_29 = F_13 ( V_15 ) ;
else
V_29 = - V_32 ;
F_8 ( & V_15 -> V_19 ) ;
if ( V_29 != 0 )
F_5 ( V_11 -> V_22 , L_2 , V_33 ,
V_29 ) ;
return V_29 ;
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
int V_34 ;
F_15 ( V_11 ) ;
if ( V_15 -> V_24 == NULL )
return;
F_4 ( & V_15 -> V_19 ) ;
V_34 = F_16 ( V_15 -> V_24 -> V_11 -> V_35 ) ;
F_8 ( & V_15 -> V_19 ) ;
if ( ! V_34 ) {
F_5 ( V_15 -> V_22 ,
L_3 ) ;
return;
}
F_4 ( & V_15 -> V_19 ) ;
F_17 ( V_15 ) ;
F_8 ( & V_15 -> V_19 ) ;
}
static int
F_18 ( struct V_10 * V_11 , struct V_36 * V_37 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
if ( V_37 -> type != V_38 ) {
F_5 ( V_11 -> V_22 , L_4
L_5 , V_33 , V_37 -> type ) ;
return - V_39 ;
}
V_15 -> V_31 = false ;
F_19 ( V_15 -> V_24 , false ) ;
return 0 ;
}
static void
F_20 ( struct V_10 * V_11 , struct V_36 * V_37 )
{
}
static int F_21 ( struct V_10 * V_11 , T_2 V_40 )
{
struct V_41 * V_42 = & V_11 -> V_42 ;
struct V_14 * V_15 = V_11 -> V_16 ;
int V_29 = 0 ;
int V_43 ;
struct V_22 * V_22 = V_11 -> V_22 ;
F_4 ( & V_15 -> V_19 ) ;
if ( V_40 & V_44 ) {
F_22 ( V_15 -> V_24 ,
V_42 -> V_45 ) ;
}
if ( V_40 & V_46 )
F_23 ( V_22 , L_6 ,
V_33 , V_42 -> V_47 & V_48 ?
L_7 : L_8 ) ;
if ( V_40 & V_49 )
F_5 ( V_22 , L_9 ,
V_33 , V_42 -> V_47 & V_50 ?
L_7 : L_8 ) ;
if ( V_40 & V_51 ) {
V_29 = F_24 ( V_15 -> V_24 , V_42 -> V_52 ) ;
if ( V_29 < 0 ) {
F_5 ( V_22 , L_10 ,
V_33 ) ;
goto V_53;
}
V_43 = F_25 ( V_15 -> V_24 ) ;
if ( V_43 != V_42 -> V_52 )
F_5 ( V_22 , L_11
L_12 , V_33 , V_42 -> V_52 ,
V_43 ) ;
}
if ( V_40 & V_54 ) {
if ( V_42 -> V_55 == V_56 ||
V_42 -> V_55 == V_57 )
V_29 = F_26 ( V_15 -> V_24 ,
V_42 -> V_58 -> V_59 ) ;
else
V_29 = - V_60 ;
}
if ( V_40 & V_61 )
V_29 = F_27 ( V_15 -> V_24 ,
V_42 -> V_62 ,
V_42 -> V_63 ) ;
V_53:
F_8 ( & V_15 -> V_19 ) ;
return V_29 ;
}
static void
F_28 ( struct V_10 * V_11 ,
struct V_36 * V_37 ,
struct V_64 * V_65 , T_2 V_40 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_22 * V_22 = V_11 -> V_22 ;
if ( V_40 & V_66 ) {
F_5 ( V_22 , L_13 , V_67 ,
V_33 , V_65 -> V_68 ? L_14 : L_15 ) ;
F_4 ( & V_15 -> V_19 ) ;
F_29 ( V_15 -> V_24 , V_65 -> V_68 ) ;
F_8 ( & V_15 -> V_19 ) ;
}
if ( V_40 & V_69 ) {
T_3 V_70 ;
if ( V_65 -> V_71 )
V_70 = 1 ;
else
V_70 = 0 ;
F_4 ( & V_15 -> V_19 ) ;
F_30 ( V_15 -> V_24 , V_70 ) ;
F_8 ( & V_15 -> V_19 ) ;
}
if ( V_40 & V_72 ) {
T_1 V_73 = V_65 -> V_74 ;
F_4 ( & V_15 -> V_19 ) ;
F_31 ( V_15 -> V_24 , V_75 ,
V_73 & V_76 ) ;
F_31 ( V_15 -> V_24 , V_77 ,
V_73 & V_78 ) ;
F_31 ( V_15 -> V_24 , V_79 ,
V_73 & V_80 ) ;
F_8 ( & V_15 -> V_19 ) ;
}
if ( V_40 & V_81 ) {
struct V_82 * V_83 ;
T_2 V_84 , V_5 ;
T_1 V_3 ;
struct V_1 V_2 ;
int error ;
F_4 ( & V_15 -> V_19 ) ;
F_32 ( V_15 -> V_24 , & V_2 ) ;
F_8 ( & V_15 -> V_19 ) ;
V_84 = V_65 -> V_85 ;
V_83 = V_11 -> V_22 -> V_86 [ F_33 ( V_15 -> V_24 ) ] ;
for ( V_5 = 0 ; V_5 < V_83 -> V_87 ; V_5 ++ ) {
V_3 = ( V_83 -> V_88 [ V_5 ] . V_89 << 1 ) / 10 ;
F_1 ( & V_2 , V_3 , V_84 & 1 ) ;
V_84 >>= 1 ;
}
F_4 ( & V_15 -> V_19 ) ;
error = F_34 ( V_15 -> V_24 , & V_2 ) ;
F_8 ( & V_15 -> V_19 ) ;
if ( error )
F_5 ( V_22 , L_16 ,
error ) ;
}
if ( V_40 & V_90 ) {
F_4 ( & V_15 -> V_19 ) ;
F_35 ( V_15 -> V_24 , V_65 -> V_91 ) ;
F_8 ( & V_15 -> V_19 ) ;
}
if ( V_40 & V_92 ) {
F_4 ( & V_15 -> V_19 ) ;
F_36 ( V_15 -> V_24 , V_93 , V_65 -> V_94 ) ;
F_8 ( & V_15 -> V_19 ) ;
}
if ( V_40 & V_95 )
F_5 ( V_22 , L_17 , V_33 ) ;
if ( V_40 & V_96 ) {
F_5 ( V_22 , L_18 , V_33 ,
V_65 -> V_97 ? L_7 : L_8 ) ;
}
if ( V_40 & V_98 ) {
F_5 ( V_22 , L_19
L_20 , V_33 , V_65 -> V_99 ,
V_65 -> V_100 ) ;
}
if ( V_40 & V_101 ) {
F_5 ( V_22 , L_21 , V_33 ,
V_65 -> V_102 ? L_7 : L_8 ) ;
}
if ( V_40 & V_103 ) {
F_5 ( V_22 , L_22
L_20 , V_33 , V_65 -> V_104 ?
L_7 : L_8 , V_65 -> V_105 ) ;
}
if ( V_40 & V_106 ) {
F_5 ( V_22 , L_23 , V_33 ,
V_65 -> V_107 ? L_7 : L_8 ) ;
}
return;
}
static void
F_37 ( struct V_10 * V_11 ,
unsigned int V_108 ,
unsigned int * V_109 , T_4 V_110 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_22 * V_22 = V_11 -> V_22 ;
V_108 &= V_111 ;
* V_109 &= V_111 ;
if ( V_108 & V_112 )
F_23 ( V_22 , L_24 ) ;
if ( V_108 & V_113 )
F_23 ( V_22 , L_25 ) ;
if ( V_108 & V_114 )
F_23 ( V_22 , L_26 ) ;
if ( V_108 & V_115 )
F_23 ( V_22 , L_27 ) ;
if ( V_108 & V_116 )
F_23 ( V_22 , L_28 ) ;
if ( V_108 & V_117 )
F_23 ( V_22 , L_29 ) ;
if ( V_108 & V_118 )
F_23 ( V_22 , L_30 ) ;
F_4 ( & V_15 -> V_19 ) ;
F_38 ( V_15 -> V_24 , * V_109 ) ;
F_8 ( & V_15 -> V_19 ) ;
return;
}
static void F_39 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_4 ( & V_15 -> V_19 ) ;
F_40 ( V_15 -> V_24 ) ;
F_8 ( & V_15 -> V_19 ) ;
return;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_4 ( & V_15 -> V_19 ) ;
F_42 ( V_15 -> V_24 ) ;
F_8 ( & V_15 -> V_19 ) ;
return;
}
static int
F_43 ( struct V_10 * V_11 , struct V_36 * V_37 , T_1 V_119 ,
const struct V_120 * V_121 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_4 ( & V_15 -> V_19 ) ;
F_44 ( V_15 -> V_24 , V_119 , V_121 , true ) ;
F_8 ( & V_15 -> V_19 ) ;
return 0 ;
}
static int
F_45 ( struct V_10 * V_11 , struct V_36 * V_37 ,
struct V_122 * V_27 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_123 * V_123 = & V_15 -> V_24 -> V_124 ;
F_46 ( V_123 ) ;
V_15 -> V_20 -> V_125 = & ( V_123 -> V_126 ) ;
V_15 -> V_20 -> V_125 -> V_123 = V_123 ;
V_15 -> V_20 -> V_125 -> V_127 = 16 ;
return 0 ;
}
static int
F_47 ( struct V_10 * V_11 ,
struct V_36 * V_37 ,
enum V_128 V_129 ,
struct V_122 * V_27 , T_1 V_130 , T_1 * V_131 ,
T_5 V_132 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_123 * V_123 = & V_15 -> V_24 -> V_124 ;
int V_34 ;
if ( F_48 ( V_123 -> V_133 != V_134 ) )
return - V_135 ;
switch ( V_129 ) {
case V_136 :
break;
case V_137 :
break;
case V_138 :
F_4 ( & V_15 -> V_19 ) ;
V_34 = F_49 ( V_15 -> V_24 , V_130 ) ;
F_8 ( & V_15 -> V_19 ) ;
if ( ! V_34 ) {
F_5 ( V_15 -> V_22 , L_31 ,
V_130 ) ;
return - V_139 ;
}
F_50 ( V_37 , V_27 -> V_140 , V_130 ) ;
break;
case V_141 :
F_4 ( & V_15 -> V_19 ) ;
F_51 ( V_15 -> V_24 , V_27 , V_130 ) ;
F_8 ( & V_15 -> V_19 ) ;
F_52 ( V_37 , V_27 -> V_140 , V_130 ) ;
break;
case V_142 :
F_4 ( & V_15 -> V_19 ) ;
F_53 ( V_15 -> V_24 , V_130 , V_132 ,
( 1 << ( V_143 +
V_27 -> V_144 . V_145 ) ) - 1 ) ;
F_8 ( & V_15 -> V_19 ) ;
break;
default:
F_5 ( V_15 -> V_22 , L_32 ,
V_33 ) ;
}
return 0 ;
}
static void F_54 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
bool V_28 ;
F_4 ( & V_15 -> V_19 ) ;
V_28 = F_55 ( V_15 -> V_24 ) ;
F_8 ( & V_15 -> V_19 ) ;
F_56 ( V_15 -> V_20 -> V_30 -> V_22 , V_28 ) ;
}
static void F_57 ( struct V_10 * V_11 , bool V_146 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_58 ( L_33 , V_33 , V_146 ? L_7 : L_8 ) ;
F_4 ( & V_15 -> V_19 ) ;
F_59 ( V_15 -> V_24 , V_146 ) ;
F_8 ( & V_15 -> V_19 ) ;
}
void F_60 ( unsigned long V_147 )
{
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) V_147 ;
F_4 ( & V_15 -> V_19 ) ;
if ( V_15 -> V_20 -> V_21 ) {
if ( V_15 -> V_148 ) {
unsigned long V_47 ;
F_61 ( & V_15 -> V_149 , V_47 ) ;
F_62 ( V_15 -> V_24 ) ;
F_63 ( & V_15 -> V_149 , V_47 ) ;
}
V_15 -> V_148 = F_64 ( V_15 -> V_24 , true ) ;
}
if ( ! V_15 -> V_20 -> V_21 )
goto V_23;
if ( V_15 -> V_148 )
F_65 ( & V_15 -> V_150 ) ;
else
F_66 ( V_15 ) ;
V_23:
F_8 ( & V_15 -> V_19 ) ;
}
static int F_67 ( struct V_14 * V_15 , struct V_151 * V_152 )
{
int V_34 ;
struct V_153 * V_153 = & V_152 -> V_154 ;
char V_155 [ 100 ] ;
int V_5 ;
memset ( & V_15 -> V_156 , 0 , sizeof( struct V_157 ) ) ;
for ( V_5 = 0 ; V_5 < V_158 ; V_5 ++ ) {
if ( V_159 [ V_5 ] == NULL )
break;
sprintf ( V_155 , L_34 , V_159 [ V_5 ] ,
V_160 ) ;
V_34 = F_68 ( & V_15 -> V_156 . V_161 [ V_5 ] , V_155 , V_153 ) ;
if ( V_34 ) {
F_5 ( V_15 -> V_22 , L_35 ,
V_67 , V_155 ) ;
return V_34 ;
}
sprintf ( V_155 , L_36 , V_159 [ V_5 ] ,
V_160 ) ;
V_34 = F_68 ( & V_15 -> V_156 . V_162 [ V_5 ] , V_155 , V_153 ) ;
if ( V_34 ) {
F_5 ( V_15 -> V_22 , L_35 ,
V_67 , V_155 ) ;
return V_34 ;
}
V_15 -> V_156 . V_163 [ V_5 ] =
V_15 -> V_156 . V_162 [ V_5 ] -> V_164 / ( sizeof( struct V_165 ) ) ;
}
V_15 -> V_156 . V_166 = V_5 ;
return F_69 ( V_15 , & V_15 -> V_167 ) ;
}
static void F_70 ( struct V_14 * V_15 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_158 ; V_5 ++ ) {
F_71 ( V_15 -> V_156 . V_161 [ V_5 ] ) ;
F_71 ( V_15 -> V_156 . V_162 [ V_5 ] ) ;
}
}
static void F_72 ( struct V_14 * V_15 )
{
struct V_168 * V_169 , * V_170 ;
if ( V_15 -> V_156 . V_166 )
F_73 ( & V_15 -> V_167 ) ;
if ( V_15 -> V_171 )
F_74 ( V_15 -> V_171 , V_15 ) ;
F_75 ( & V_15 -> V_150 ) ;
if ( V_15 -> V_20 )
F_76 ( V_15 -> V_20 , L_37 , V_15 ) ;
if ( V_15 -> V_24 ) {
F_77 ( V_15 -> V_24 ) ;
V_15 -> V_24 = NULL ;
V_15 -> V_20 = NULL ;
}
while ( F_78 ( & V_15 -> V_172 ) > 0 )
F_79 () ;
for ( V_169 = V_15 -> V_173 ; V_169 ; V_169 = V_170 ) {
V_170 = V_169 -> V_170 ;
#ifdef F_80
F_81 ( V_169 -> V_174 ) ;
#endif
F_81 ( V_169 ) ;
}
}
static void F_82 ( struct V_151 * V_152 )
{
struct V_10 * V_11 = F_83 ( V_152 ) ;
struct V_14 * V_15 = V_11 -> V_16 ;
if ( V_15 -> V_24 ) {
F_56 ( V_15 -> V_20 -> V_30 -> V_22 , false ) ;
F_12 ( V_15 -> V_20 -> V_30 -> V_22 ) ;
F_84 ( V_11 ) ;
}
F_72 ( V_15 ) ;
F_85 ( V_152 , NULL ) ;
F_86 ( V_11 ) ;
}
static T_6 F_87 ( int V_171 , void * V_175 )
{
struct V_14 * V_15 ;
bool V_176 , V_177 ;
V_15 = (struct V_14 * ) V_175 ;
F_88 ( & V_15 -> V_149 ) ;
V_176 = F_89 ( V_15 -> V_24 , & V_177 ) ;
if ( V_176 ) {
if ( V_177 ) {
F_65 ( & V_15 -> V_150 ) ;
}
}
F_90 ( & V_15 -> V_149 ) ;
return F_91 ( V_176 ) ;
}
static int F_92 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_178 * V_24 = V_15 -> V_24 ;
struct V_82 * V_179 ;
int V_180 = 0 ;
T_1 V_181 ;
V_11 -> V_22 -> V_86 [ V_182 ] = NULL ;
V_11 -> V_22 -> V_86 [ V_183 ] = NULL ;
V_181 = F_93 ( V_15 -> V_24 , 0 ) ;
if ( V_181 == V_184 || V_181 == V_185 ) {
V_179 = & V_24 -> V_186 [ V_187 ] -> V_179 ;
* V_179 = V_188 ;
if ( V_181 == V_185 ) {
V_179 -> V_144 . V_189 . V_190 [ 1 ] = 0 ;
V_179 -> V_144 . V_189 . V_191 = F_94 ( 72 ) ;
}
V_11 -> V_22 -> V_86 [ V_182 ] = V_179 ;
} else {
return - V_192 ;
}
if ( V_15 -> V_20 -> V_193 > 1 ) {
V_180 ++ ;
if ( V_181 == V_184 || V_181 == V_185 ) {
V_179 = & V_24 -> V_186 [ V_194 ] -> V_179 ;
* V_179 = V_195 ;
V_11 -> V_22 -> V_86 [ V_183 ] = V_179 ;
} else {
return - V_192 ;
}
}
return 0 ;
}
static int F_95 ( struct V_10 * V_11 )
{
V_11 -> V_47 = V_196
| V_197
| V_198 ;
V_11 -> V_199 = F_96 () ;
V_11 -> V_200 = V_201 ;
V_11 -> V_202 = 2 ;
V_11 -> V_203 = 7 * 1000 ;
V_11 -> V_22 -> V_204 = F_97 ( V_38 ) ;
V_11 -> V_205 = L_38 ;
V_11 -> V_206 = 0 ;
return F_92 ( V_11 ) ;
}
static struct V_14 * F_98 ( struct V_151 * V_152 )
{
struct V_14 * V_15 = NULL ;
int V_207 , V_29 ;
struct V_10 * V_11 ;
T_5 V_208 [ V_209 ] ;
V_207 = V_210 ;
V_29 = 0 ;
if ( V_207 < 0 )
return NULL ;
V_11 = F_83 ( V_152 ) ;
if ( V_11 != NULL )
V_15 = V_11 -> V_16 ;
if ( F_48 ( V_11 == NULL ) || F_48 ( V_15 == NULL ) )
return NULL ;
V_15 -> V_22 = V_11 -> V_22 ;
F_99 ( & V_15 -> V_172 , 0 ) ;
F_100 ( & V_15 -> V_150 , F_60 , ( unsigned long ) V_15 ) ;
F_101 ( & V_15 -> V_19 ) ;
F_101 ( & V_15 -> V_149 ) ;
if ( F_67 ( V_15 , V_152 ) < 0 ) {
F_5 ( V_15 -> V_22 , L_39
L_40 , V_67 , L_41 ) ;
F_70 ( V_15 ) ;
F_82 ( V_152 ) ;
return NULL ;
}
V_15 -> V_24 = F_102 ( ( void * ) V_15 , V_152 , V_207 , false , & V_29 ) ;
F_70 ( V_15 ) ;
if ( ! V_15 -> V_24 ) {
F_5 ( V_15 -> V_22 , L_42 ,
V_67 , V_29 ) ;
goto V_211;
}
V_15 -> V_20 = F_103 ( V_15 -> V_24 ) ;
V_15 -> V_20 -> V_30 = V_11 ;
if ( F_104 ( V_152 -> V_171 , F_87 ,
V_212 , V_67 , V_15 ) ) {
F_5 ( V_15 -> V_22 , L_43 , V_207 ) ;
goto V_211;
}
V_15 -> V_171 = V_152 -> V_171 ;
F_105 ( V_15 -> V_20 , L_37 , V_15 , NULL ) ;
if ( F_95 ( V_11 ) ) {
F_5 ( V_15 -> V_22 , L_44 , V_207 ,
V_33 ) ;
goto V_211;
}
F_106 ( V_15 -> V_24 ) ;
memcpy ( V_208 , & V_15 -> V_20 -> V_213 , V_209 ) ;
if ( F_48 ( ! F_107 ( V_208 ) ) )
goto V_211;
F_108 ( V_11 , V_208 ) ;
V_29 = F_109 ( V_11 ) ;
if ( V_29 )
F_5 ( V_15 -> V_22 , L_45
L_46 , V_33 , V_29 ) ;
if ( V_15 -> V_20 -> V_214 [ 0 ] &&
F_110 ( V_15 -> V_22 , V_15 -> V_20 -> V_214 ) )
F_5 ( V_15 -> V_22 , L_47 , V_33 ) ;
V_210 ++ ;
return V_15 ;
V_211:
F_72 ( V_15 ) ;
return NULL ;
}
static int T_7 F_111 ( struct V_151 * V_152 )
{
struct V_14 * V_15 ;
struct V_10 * V_11 ;
F_112 ( & V_152 -> V_154 , L_48 ,
V_152 -> V_215 . V_216 , V_152 -> V_215 . V_215 , V_152 -> V_215 . V_217 , V_152 -> V_215 . V_218 ,
V_152 -> V_171 ) ;
if ( ( V_152 -> V_215 . V_216 != V_219 ) ||
( V_152 -> V_215 . V_215 != V_220 ) )
return - V_32 ;
V_11 = F_113 ( sizeof( struct V_14 ) , & V_221 ) ;
if ( ! V_11 ) {
F_114 ( L_49 , V_33 ) ;
return - V_222 ;
}
F_115 ( V_11 , & V_152 -> V_154 ) ;
F_85 ( V_152 , V_11 ) ;
memset ( V_11 -> V_16 , 0 , sizeof( * V_15 ) ) ;
V_15 = F_98 ( V_152 ) ;
if ( ! V_15 ) {
F_114 ( L_50 , V_33 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_116 ( struct V_151 * V_152 )
{
struct V_14 * V_15 ;
struct V_10 * V_11 ;
V_11 = F_83 ( V_152 ) ;
V_15 = V_11 -> V_16 ;
if ( ! V_15 ) {
F_114 ( L_51 , V_67 ,
V_33 ) ;
return - V_32 ;
}
F_4 ( & V_15 -> V_19 ) ;
V_15 -> V_20 -> V_223 = false ;
F_8 ( & V_15 -> V_19 ) ;
F_117 ( L_52 ) ;
return 0 ;
}
static int F_118 ( struct V_151 * V_152 )
{
F_117 ( L_53 ) ;
return 0 ;
}
static void F_119 ( struct V_224 * V_225 )
{
int error ;
error = F_120 ( & V_226 ) ;
if ( error )
F_114 ( L_54 , V_33 , error ) ;
}
static int T_8 F_121 ( void )
{
#ifdef F_80
if ( V_227 != 0xdeadbeef )
V_228 = V_227 ;
#endif
if ( ! F_122 ( & V_229 ) )
return - V_230 ;
return 0 ;
}
static void T_9 F_123 ( void )
{
F_124 ( & V_229 ) ;
F_125 ( & V_226 ) ;
}
void F_126 ( struct V_14 * V_15 , struct V_231 * V_232 ,
bool V_233 , int V_234 )
{
F_5 ( V_15 -> V_22 , L_55 , V_33 ) ;
}
void F_127 ( struct V_14 * V_15 )
{
F_128 ( V_15 -> V_20 -> V_30 -> V_22 , L_56 , V_15 -> V_20 -> V_207 ) ;
F_129 ( V_15 ) ;
F_130 ( V_15 -> V_24 , V_15 -> V_31 ) ;
}
T_10 F_129 ( struct V_14 * V_15 )
{
F_128 ( V_15 -> V_20 -> V_30 -> V_22 , L_56 , V_15 -> V_20 -> V_207 ) ;
F_131 ( V_15 -> V_24 ) ;
V_15 -> V_148 = false ;
V_15 -> V_20 -> V_21 = false ;
return 0 ;
}
void F_132 ( struct V_14 * V_15 )
{
F_5 ( V_15 -> V_24 -> V_22 , L_57 ,
V_15 -> V_24 -> V_20 -> V_207 ) ;
F_129 ( V_15 ) ;
F_133 ( V_15 -> V_20 -> V_30 ) ;
}
void F_66 ( struct V_14 * V_15 )
{
unsigned long V_47 ;
F_61 ( & V_15 -> V_149 , V_47 ) ;
F_134 ( V_15 -> V_24 ) ;
F_63 ( & V_15 -> V_149 , V_47 ) ;
}
T_2 F_135 ( struct V_14 * V_15 )
{
unsigned long V_47 ;
T_2 V_34 ;
F_61 ( & V_15 -> V_149 , V_47 ) ;
V_34 = F_136 ( V_15 -> V_24 ) ;
F_63 ( & V_15 -> V_149 , V_47 ) ;
return V_34 ;
}
void F_137 ( struct V_14 * V_15 , T_2 V_235 )
{
unsigned long V_47 ;
F_61 ( & V_15 -> V_149 , V_47 ) ;
F_138 ( V_15 -> V_24 , V_235 ) ;
F_63 ( & V_15 -> V_149 , V_47 ) ;
}
int F_13 ( struct V_14 * V_15 )
{
int error = 0 ;
if ( V_15 -> V_20 -> V_21 )
return 0 ;
error = F_139 ( V_15 -> V_24 ) ;
return error ;
}
void F_17 ( struct V_14 * V_15 )
{
T_10 V_172 , V_236 = 0 ;
V_236 = F_140 ( V_15 -> V_24 ) ;
V_172 = F_78 ( & V_15 -> V_172 ) - V_236 ;
F_8 ( & V_15 -> V_19 ) ;
F_141 ( ( F_78 ( & V_15 -> V_172 ) > V_172 ) , 100 * 1000 ) ;
F_4 ( & V_15 -> V_19 ) ;
}
static void F_142 ( struct V_224 * V_225 )
{
struct V_168 * V_169 = F_143 ( V_225 , struct V_168 ,
V_237 . V_225 ) ;
F_4 ( & V_169 -> V_15 -> V_19 ) ;
if ( V_169 -> V_238 ) {
if ( V_169 -> V_239 ) {
F_144 ( & V_169 -> V_15 -> V_172 ) ;
F_145 ( V_169 -> V_15 -> V_20 -> V_30 ,
& V_169 -> V_237 ,
F_146 ( V_169 -> V_240 ) ) ;
} else {
V_169 -> V_238 = false ;
}
V_169 -> V_241 ( V_169 -> V_242 ) ;
}
F_147 ( & V_169 -> V_15 -> V_172 ) ;
F_8 ( & V_169 -> V_15 -> V_19 ) ;
}
struct V_168 * F_148 ( struct V_14 * V_15 ,
void (* V_241) ( void * V_242 ) ,
void * V_242 , const char * V_174 )
{
struct V_168 * V_169 ;
V_169 = F_149 ( sizeof( struct V_168 ) , V_243 ) ;
if ( ! V_169 )
return NULL ;
F_150 ( & V_169 -> V_237 , F_142 ) ;
V_169 -> V_15 = V_15 ;
V_169 -> V_241 = V_241 ;
V_169 -> V_242 = V_242 ;
V_169 -> V_170 = V_15 -> V_173 ;
V_15 -> V_173 = V_169 ;
#ifdef F_80
V_169 -> V_174 = F_151 ( strlen ( V_174 ) + 1 , V_243 ) ;
if ( V_169 -> V_174 )
strcpy ( V_169 -> V_174 , V_174 ) ;
#endif
return V_169 ;
}
void F_152 ( struct V_168 * V_169 , T_10 V_240 , int V_239 )
{
struct V_10 * V_11 = V_169 -> V_15 -> V_20 -> V_30 ;
#ifdef F_80
if ( V_169 -> V_238 )
F_5 ( V_11 -> V_22 , L_58 ,
V_33 , V_169 -> V_174 , V_239 ) ;
#endif
V_169 -> V_240 = V_240 ;
V_169 -> V_239 = ( bool ) V_239 ;
V_169 -> V_238 = true ;
F_144 ( & V_169 -> V_15 -> V_172 ) ;
F_145 ( V_11 , & V_169 -> V_237 , F_146 ( V_240 ) ) ;
}
bool F_153 ( struct V_168 * V_169 )
{
if ( V_169 -> V_238 ) {
V_169 -> V_238 = false ;
if ( ! F_154 ( & V_169 -> V_237 ) )
return false ;
F_147 ( & V_169 -> V_15 -> V_172 ) ;
}
return true ;
}
void F_155 ( struct V_168 * V_169 )
{
struct V_14 * V_15 = V_169 -> V_15 ;
struct V_168 * V_244 ;
F_153 ( V_169 ) ;
if ( V_15 -> V_173 == V_169 ) {
V_15 -> V_173 = V_15 -> V_173 -> V_170 ;
#ifdef F_80
F_81 ( V_169 -> V_174 ) ;
#endif
F_81 ( V_169 ) ;
return;
}
V_244 = V_15 -> V_173 ;
while ( V_244 ) {
if ( V_244 -> V_170 == V_169 ) {
V_244 -> V_170 = V_169 -> V_170 ;
#ifdef F_80
F_81 ( V_169 -> V_174 ) ;
#endif
F_81 ( V_169 ) ;
return;
}
V_244 = V_244 -> V_170 ;
}
}
int F_156 ( struct V_14 * V_15 , void * * V_245 , T_2 V_246 )
{
int V_5 , V_247 ;
const T_5 * V_248 ;
struct V_165 * V_249 ;
for ( V_5 = 0 ; V_5 < V_15 -> V_156 . V_166 ; V_5 ++ ) {
V_249 = (struct V_165 * ) V_15 -> V_156 . V_162 [ V_5 ] -> V_147 ;
for ( V_247 = 0 ; V_247 < V_15 -> V_156 . V_163 [ V_5 ] ;
V_247 ++ , V_249 ++ ) {
T_2 V_250 = F_157 ( V_249 -> V_250 ) ;
if ( F_157 ( V_249 -> V_246 ) == V_246 ) {
V_248 = V_15 -> V_156 . V_161 [ V_5 ] -> V_147 +
F_157 ( V_249 -> V_251 ) ;
* V_245 = F_158 ( V_248 , V_250 , V_243 ) ;
if ( * V_245 == NULL )
goto V_211;
return 0 ;
}
}
}
F_5 ( V_15 -> V_22 , L_59 ,
V_246 ) ;
* V_245 = NULL ;
V_211:
return - V_252 ;
}
int F_159 ( struct V_14 * V_15 , T_11 * V_253 , T_2 V_246 )
{
int V_5 , V_247 ;
const T_5 * V_248 ;
struct V_165 * V_249 ;
for ( V_5 = 0 ; V_5 < V_15 -> V_156 . V_166 ; V_5 ++ ) {
V_249 = (struct V_165 * ) V_15 -> V_156 . V_162 [ V_5 ] -> V_147 ;
for ( V_247 = 0 ; V_247 < V_15 -> V_156 . V_163 [ V_5 ] ;
V_247 ++ , V_249 ++ ) {
if ( F_157 ( V_249 -> V_246 ) == V_246 ) {
V_248 = V_15 -> V_156 . V_161 [ V_5 ] -> V_147 +
F_157 ( V_249 -> V_251 ) ;
if ( F_157 ( V_249 -> V_250 ) != 4 ) {
F_5 ( V_15 -> V_22 ,
L_60 ) ;
return - V_254 ;
}
* V_253 = F_157 ( * ( ( V_255 * ) V_248 ) ) ;
return 0 ;
}
}
}
F_5 ( V_15 -> V_22 , L_61 , V_246 ) ;
return - V_254 ;
}
void F_160 ( void * V_256 )
{
F_81 ( V_256 ) ;
}
int F_161 ( struct V_14 * V_15 )
{
int V_5 ;
int V_247 ;
int V_257 = 0 ;
const struct V_258 * V_156 ;
const struct V_258 * V_162 ;
struct V_165 * V_259 ;
for ( V_5 = 0 ; V_5 < V_158 && V_257 == 0 ; V_5 ++ ) {
V_156 = V_15 -> V_156 . V_161 [ V_5 ] ;
V_162 = V_15 -> V_156 . V_162 [ V_5 ] ;
if ( V_156 == NULL && V_162 == NULL ) {
break;
} else if ( V_156 == NULL || V_162 == NULL ) {
F_5 ( V_15 -> V_22 , L_62 ,
V_33 ) ;
V_257 = - V_260 ;
} else if ( V_162 -> V_164 % sizeof( struct V_165 ) ) {
F_5 ( V_15 -> V_22 , L_63
L_64 , V_33 , V_162 -> V_164 ,
sizeof( struct V_165 ) ) ;
V_257 = - V_260 ;
} else if ( V_156 -> V_164 < V_261 || V_156 -> V_164 > V_262 ) {
F_5 ( V_15 -> V_22 , L_65
L_66 , V_33 , V_156 -> V_164 ) ;
V_257 = - V_260 ;
} else {
V_259 = (struct V_165 * ) V_162 -> V_147 ;
for ( V_247 = 0 ; V_247 < V_15 -> V_156 . V_163 [ V_5 ] &&
! V_257 ; V_247 ++ , V_259 ++ ) {
if ( F_157 ( V_259 -> V_251 ) +
F_157 ( V_259 -> V_250 ) >
V_156 -> V_164 ) {
F_5 ( V_15 -> V_22 ,
L_67 ,
V_33 ) ;
V_257 = - V_260 ;
}
}
}
}
if ( V_257 == 0 && V_15 -> V_156 . V_166 != V_5 ) {
F_5 ( V_15 -> V_22 , L_68 , V_33 ,
V_15 -> V_156 . V_166 ) ;
V_257 = - V_260 ;
}
return V_257 ;
}
bool F_11 ( struct V_14 * V_15 )
{
bool V_28 = F_55 ( V_15 -> V_24 ) ;
F_8 ( & V_15 -> V_19 ) ;
F_56 ( V_15 -> V_20 -> V_30 -> V_22 , V_28 ) ;
if ( V_28 )
F_162 ( V_15 -> V_20 -> V_30 -> V_22 ) ;
F_4 ( & V_15 -> V_19 ) ;
return V_28 ;
}
void F_163 ( struct V_14 * V_15 , T_10 V_240 )
{
F_8 ( & V_15 -> V_19 ) ;
F_164 ( V_240 ) ;
F_4 ( & V_15 -> V_19 ) ;
}
