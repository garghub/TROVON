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
static void F_2 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_19 * V_20 = F_3 ( V_15 ) ;
F_4 ( & V_17 -> V_21 ) ;
if ( ! V_17 -> V_22 -> V_23 ) {
F_5 ( V_17 -> V_24 , L_1 ) ;
F_6 ( V_15 ) ;
goto V_25;
}
F_7 ( V_17 -> V_26 , V_15 , V_11 ) ;
V_20 -> V_27 [ 0 ] = V_13 -> V_28 ;
V_25:
F_8 ( & V_17 -> V_21 ) ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
bool V_29 ;
int V_30 ;
F_10 ( V_11 ) ;
F_4 ( & V_17 -> V_21 ) ;
V_29 = F_11 ( V_17 ) ;
F_8 ( & V_17 -> V_21 ) ;
if ( ! V_29 )
F_12 ( V_17 -> V_22 -> V_31 -> V_24 ) ;
F_4 ( & V_17 -> V_21 ) ;
V_17 -> V_32 = true ;
if ( ! V_17 -> V_22 -> V_23 )
if ( ! V_29 )
V_30 = F_13 ( V_17 ) ;
else
V_30 = - V_33 ;
else
V_30 = - V_34 ;
F_8 ( & V_17 -> V_21 ) ;
if ( V_30 != 0 )
F_5 ( V_11 -> V_24 , L_2 , V_35 ,
V_30 ) ;
return V_30 ;
}
static void F_14 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
int V_36 ;
F_15 ( V_11 ) ;
if ( V_17 -> V_26 == NULL )
return;
F_4 ( & V_17 -> V_21 ) ;
V_36 = F_16 ( V_17 -> V_26 -> V_11 -> V_37 ) ;
F_8 ( & V_17 -> V_21 ) ;
if ( ! V_36 ) {
F_5 ( V_17 -> V_24 ,
L_3 ) ;
return;
}
F_4 ( & V_17 -> V_21 ) ;
F_17 ( V_17 ) ;
F_8 ( & V_17 -> V_21 ) ;
}
static int
F_18 ( struct V_10 * V_11 , struct V_38 * V_39 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_39 -> type != V_40 ) {
F_5 ( V_11 -> V_24 , L_4
L_5 , V_35 , V_39 -> type ) ;
return - V_41 ;
}
V_17 -> V_32 = false ;
F_19 ( V_17 -> V_26 , false ) ;
return 0 ;
}
static void
F_20 ( struct V_10 * V_11 , struct V_38 * V_39 )
{
}
static int F_21 ( struct V_10 * V_11 , T_2 V_42 )
{
struct V_43 * V_44 = & V_11 -> V_44 ;
struct V_16 * V_17 = V_11 -> V_18 ;
int V_30 = 0 ;
int V_45 ;
struct V_24 * V_24 = V_11 -> V_24 ;
F_4 ( & V_17 -> V_21 ) ;
if ( V_42 & V_46 ) {
F_22 ( V_17 -> V_26 ,
V_44 -> V_47 ) ;
}
if ( V_42 & V_48 )
F_23 ( V_24 , L_6 ,
V_35 , V_44 -> V_49 & V_50 ?
L_7 : L_8 ) ;
if ( V_42 & V_51 )
F_5 ( V_24 , L_9 ,
V_35 , V_44 -> V_49 & V_52 ?
L_7 : L_8 ) ;
if ( V_42 & V_53 ) {
V_30 = F_24 ( V_17 -> V_26 , V_44 -> V_54 ) ;
if ( V_30 < 0 ) {
F_5 ( V_24 , L_10 ,
V_35 ) ;
goto V_55;
}
V_45 = F_25 ( V_17 -> V_26 ) ;
if ( V_45 != V_44 -> V_54 )
F_5 ( V_24 , L_11
L_12 , V_35 , V_44 -> V_54 ,
V_45 ) ;
}
if ( V_42 & V_56 ) {
if ( V_44 -> V_57 == V_58 ||
V_44 -> V_57 == V_59 )
V_30 = F_26 ( V_17 -> V_26 ,
V_44 -> V_60 -> V_61 ) ;
else
V_30 = - V_62 ;
}
if ( V_42 & V_63 )
V_30 = F_27 ( V_17 -> V_26 ,
V_44 -> V_64 ,
V_44 -> V_65 ) ;
V_55:
F_8 ( & V_17 -> V_21 ) ;
return V_30 ;
}
static void
F_28 ( struct V_10 * V_11 ,
struct V_38 * V_39 ,
struct V_66 * V_67 , T_2 V_42 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_24 * V_24 = V_11 -> V_24 ;
if ( V_42 & V_68 ) {
F_5 ( V_24 , L_13 , V_69 ,
V_35 , V_67 -> V_70 ? L_14 : L_15 ) ;
F_4 ( & V_17 -> V_21 ) ;
F_29 ( V_17 -> V_26 , V_67 -> V_70 ) ;
F_8 ( & V_17 -> V_21 ) ;
}
if ( V_42 & V_71 ) {
T_3 V_72 ;
if ( V_67 -> V_73 )
V_72 = 1 ;
else
V_72 = 0 ;
F_4 ( & V_17 -> V_21 ) ;
F_30 ( V_17 -> V_26 , V_72 ) ;
F_8 ( & V_17 -> V_21 ) ;
}
if ( V_42 & V_74 ) {
T_1 V_75 = V_67 -> V_76 ;
F_4 ( & V_17 -> V_21 ) ;
F_31 ( V_17 -> V_26 , V_77 ,
V_75 & V_78 ) ;
F_31 ( V_17 -> V_26 , V_79 ,
V_75 & V_80 ) ;
F_31 ( V_17 -> V_26 , V_81 ,
V_75 & V_82 ) ;
F_8 ( & V_17 -> V_21 ) ;
}
if ( V_42 & V_83 ) {
struct V_84 * V_85 ;
T_2 V_86 , V_5 ;
T_1 V_3 ;
struct V_1 V_2 ;
int error ;
F_4 ( & V_17 -> V_21 ) ;
F_32 ( V_17 -> V_26 , & V_2 ) ;
F_8 ( & V_17 -> V_21 ) ;
V_86 = V_67 -> V_87 ;
V_85 = V_11 -> V_24 -> V_88 [ F_33 ( V_17 -> V_26 ) ] ;
for ( V_5 = 0 ; V_5 < V_85 -> V_89 ; V_5 ++ ) {
V_3 = ( V_85 -> V_90 [ V_5 ] . V_91 << 1 ) / 10 ;
F_1 ( & V_2 , V_3 , V_86 & 1 ) ;
V_86 >>= 1 ;
}
F_4 ( & V_17 -> V_21 ) ;
error = F_34 ( V_17 -> V_26 , & V_2 ) ;
F_8 ( & V_17 -> V_21 ) ;
if ( error )
F_5 ( V_24 , L_16 ,
error ) ;
}
if ( V_42 & V_92 ) {
F_4 ( & V_17 -> V_21 ) ;
F_35 ( V_17 -> V_26 , V_67 -> V_93 ) ;
F_8 ( & V_17 -> V_21 ) ;
}
if ( V_42 & V_94 ) {
F_4 ( & V_17 -> V_21 ) ;
F_36 ( V_17 -> V_26 , V_95 , V_67 -> V_96 ) ;
F_8 ( & V_17 -> V_21 ) ;
}
if ( V_42 & V_97 )
F_5 ( V_24 , L_17 , V_35 ) ;
if ( V_42 & V_98 ) {
F_5 ( V_24 , L_18 , V_35 ,
V_67 -> V_99 ? L_7 : L_8 ) ;
}
if ( V_42 & V_100 ) {
F_5 ( V_24 , L_19
L_20 , V_35 , V_67 -> V_101 ,
V_67 -> V_102 ) ;
}
if ( V_42 & V_103 ) {
F_5 ( V_24 , L_21 , V_35 ,
V_67 -> V_104 ? L_7 : L_8 ) ;
}
if ( V_42 & V_105 ) {
F_5 ( V_24 , L_22
L_20 , V_35 , V_67 -> V_106 ?
L_7 : L_8 , V_67 -> V_107 ) ;
}
if ( V_42 & V_108 ) {
F_5 ( V_24 , L_23 , V_35 ,
V_67 -> V_109 ? L_7 : L_8 ) ;
}
return;
}
static void
F_37 ( struct V_10 * V_11 ,
unsigned int V_110 ,
unsigned int * V_111 , T_4 V_112 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_24 * V_24 = V_11 -> V_24 ;
V_110 &= V_113 ;
* V_111 &= V_113 ;
if ( V_110 & V_114 )
F_23 ( V_24 , L_24 ) ;
if ( V_110 & V_115 )
F_23 ( V_24 , L_25 ) ;
if ( V_110 & V_116 )
F_23 ( V_24 , L_26 ) ;
if ( V_110 & V_117 )
F_23 ( V_24 , L_27 ) ;
if ( V_110 & V_118 )
F_23 ( V_24 , L_28 ) ;
if ( V_110 & V_119 )
F_23 ( V_24 , L_29 ) ;
if ( V_110 & V_120 )
F_23 ( V_24 , L_30 ) ;
F_4 ( & V_17 -> V_21 ) ;
F_38 ( V_17 -> V_26 , * V_111 ) ;
F_8 ( & V_17 -> V_21 ) ;
return;
}
static void F_39 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
F_4 ( & V_17 -> V_21 ) ;
F_40 ( V_17 -> V_26 ) ;
F_8 ( & V_17 -> V_21 ) ;
return;
}
static void F_41 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
F_4 ( & V_17 -> V_21 ) ;
F_42 ( V_17 -> V_26 ) ;
F_8 ( & V_17 -> V_21 ) ;
return;
}
static int
F_43 ( struct V_10 * V_11 , struct V_38 * V_39 , T_1 V_121 ,
const struct V_122 * V_123 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
F_4 ( & V_17 -> V_21 ) ;
F_44 ( V_17 -> V_26 , V_121 , V_123 , true ) ;
F_8 ( & V_17 -> V_21 ) ;
return 0 ;
}
static int
F_45 ( struct V_10 * V_11 , struct V_38 * V_39 ,
struct V_124 * V_28 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_125 * V_125 = & V_17 -> V_26 -> V_126 ;
F_46 ( V_125 ) ;
V_17 -> V_22 -> V_127 = & ( V_125 -> V_128 ) ;
V_17 -> V_22 -> V_127 -> V_125 = V_125 ;
V_17 -> V_22 -> V_127 -> V_129 = 16 ;
return 0 ;
}
static int
F_47 ( struct V_10 * V_11 ,
struct V_38 * V_39 ,
enum V_130 V_131 ,
struct V_124 * V_28 , T_1 V_132 , T_1 * V_133 ,
T_5 V_134 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_125 * V_125 = & V_17 -> V_26 -> V_126 ;
int V_36 ;
if ( F_48 ( V_125 -> V_135 != V_136 ) )
return - V_137 ;
switch ( V_131 ) {
case V_138 :
break;
case V_139 :
break;
case V_140 :
F_4 ( & V_17 -> V_21 ) ;
V_36 = F_49 ( V_17 -> V_26 , V_132 ) ;
F_8 ( & V_17 -> V_21 ) ;
if ( ! V_36 ) {
F_5 ( V_17 -> V_24 , L_31 ,
V_132 ) ;
return - V_141 ;
}
F_50 ( V_39 , V_28 -> V_142 , V_132 ) ;
break;
case V_143 :
F_4 ( & V_17 -> V_21 ) ;
F_51 ( V_17 -> V_26 , V_28 , V_132 ) ;
F_8 ( & V_17 -> V_21 ) ;
F_52 ( V_39 , V_28 -> V_142 , V_132 ) ;
break;
case V_144 :
F_4 ( & V_17 -> V_21 ) ;
F_53 ( V_17 -> V_26 , V_132 , V_134 ,
( 1 << ( V_145 +
V_28 -> V_146 . V_147 ) ) - 1 ) ;
F_8 ( & V_17 -> V_21 ) ;
break;
default:
F_5 ( V_17 -> V_24 , L_32 ,
V_35 ) ;
}
return 0 ;
}
static void F_54 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
bool V_29 ;
F_4 ( & V_17 -> V_21 ) ;
V_29 = F_55 ( V_17 -> V_26 ) ;
F_8 ( & V_17 -> V_21 ) ;
F_56 ( V_17 -> V_22 -> V_31 -> V_24 , V_29 ) ;
}
static void F_57 ( struct V_10 * V_11 , bool V_148 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
F_58 ( L_33 , V_35 , V_148 ? L_7 : L_8 ) ;
F_4 ( & V_17 -> V_21 ) ;
F_59 ( V_17 -> V_26 , V_148 ) ;
F_8 ( & V_17 -> V_21 ) ;
}
void F_60 ( unsigned long V_149 )
{
struct V_16 * V_17 ;
V_17 = (struct V_16 * ) V_149 ;
F_4 ( & V_17 -> V_21 ) ;
if ( V_17 -> V_22 -> V_23 ) {
if ( V_17 -> V_150 ) {
unsigned long V_49 ;
F_61 ( & V_17 -> V_151 , V_49 ) ;
F_62 ( V_17 -> V_26 ) ;
F_63 ( & V_17 -> V_151 , V_49 ) ;
}
V_17 -> V_150 = F_64 ( V_17 -> V_26 , true ) ;
}
if ( ! V_17 -> V_22 -> V_23 )
goto V_25;
if ( V_17 -> V_150 )
F_65 ( & V_17 -> V_152 ) ;
else
F_66 ( V_17 ) ;
V_25:
F_8 ( & V_17 -> V_21 ) ;
}
static int F_67 ( struct V_16 * V_17 , struct V_153 * V_154 )
{
int V_36 ;
struct V_155 * V_155 = & V_154 -> V_156 ;
char V_157 [ 100 ] ;
int V_5 ;
memset ( & V_17 -> V_158 , 0 , sizeof( struct V_159 ) ) ;
for ( V_5 = 0 ; V_5 < V_160 ; V_5 ++ ) {
if ( V_161 [ V_5 ] == NULL )
break;
sprintf ( V_157 , L_34 , V_161 [ V_5 ] ,
V_162 ) ;
V_36 = F_68 ( & V_17 -> V_158 . V_163 [ V_5 ] , V_157 , V_155 ) ;
if ( V_36 ) {
F_5 ( V_17 -> V_24 , L_35 ,
V_69 , V_157 ) ;
return V_36 ;
}
sprintf ( V_157 , L_36 , V_161 [ V_5 ] ,
V_162 ) ;
V_36 = F_68 ( & V_17 -> V_158 . V_164 [ V_5 ] , V_157 , V_155 ) ;
if ( V_36 ) {
F_5 ( V_17 -> V_24 , L_35 ,
V_69 , V_157 ) ;
return V_36 ;
}
V_17 -> V_158 . V_165 [ V_5 ] =
V_17 -> V_158 . V_164 [ V_5 ] -> V_166 / ( sizeof( struct V_167 ) ) ;
}
V_17 -> V_158 . V_168 = V_5 ;
return F_69 ( V_17 , & V_17 -> V_169 ) ;
}
static void F_70 ( struct V_16 * V_17 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_160 ; V_5 ++ ) {
F_71 ( V_17 -> V_158 . V_163 [ V_5 ] ) ;
F_71 ( V_17 -> V_158 . V_164 [ V_5 ] ) ;
}
}
static void F_72 ( struct V_16 * V_17 )
{
struct V_170 * V_171 , * V_172 ;
if ( V_17 -> V_158 . V_168 )
F_73 ( & V_17 -> V_169 ) ;
if ( V_17 -> V_173 )
F_74 ( V_17 -> V_173 , V_17 ) ;
F_75 ( & V_17 -> V_152 ) ;
if ( V_17 -> V_22 )
F_76 ( V_17 -> V_22 , L_37 , V_17 ) ;
if ( V_17 -> V_26 ) {
F_77 ( V_17 -> V_26 ) ;
V_17 -> V_26 = NULL ;
V_17 -> V_22 = NULL ;
}
while ( F_78 ( & V_17 -> V_174 ) > 0 )
F_79 () ;
for ( V_171 = V_17 -> V_175 ; V_171 ; V_171 = V_172 ) {
V_172 = V_171 -> V_172 ;
#ifdef F_80
F_81 ( V_171 -> V_176 ) ;
#endif
F_81 ( V_171 ) ;
}
}
static void F_82 ( struct V_153 * V_154 )
{
struct V_10 * V_11 = F_83 ( V_154 ) ;
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_26 ) {
F_56 ( V_17 -> V_22 -> V_31 -> V_24 , false ) ;
F_12 ( V_17 -> V_22 -> V_31 -> V_24 ) ;
F_84 ( V_11 ) ;
}
F_72 ( V_17 ) ;
F_85 ( V_154 , NULL ) ;
F_86 ( V_11 ) ;
}
static T_6 F_87 ( int V_173 , void * V_177 )
{
struct V_16 * V_17 ;
bool V_178 , V_179 ;
V_17 = (struct V_16 * ) V_177 ;
F_88 ( & V_17 -> V_151 ) ;
V_178 = F_89 ( V_17 -> V_26 , & V_179 ) ;
if ( V_178 ) {
if ( V_179 ) {
F_65 ( & V_17 -> V_152 ) ;
}
}
F_90 ( & V_17 -> V_151 ) ;
return F_91 ( V_178 ) ;
}
static int F_92 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_180 * V_26 = V_17 -> V_26 ;
struct V_84 * V_181 ;
int V_182 = 0 ;
T_1 V_183 ;
V_11 -> V_24 -> V_88 [ V_184 ] = NULL ;
V_11 -> V_24 -> V_88 [ V_185 ] = NULL ;
V_183 = F_93 ( V_17 -> V_26 , 0 ) ;
if ( V_183 == V_186 || V_183 == V_187 ) {
V_181 = & V_26 -> V_188 [ V_189 ] -> V_181 ;
* V_181 = V_190 ;
if ( V_183 == V_187 ) {
V_181 -> V_146 . V_191 . V_192 [ 1 ] = 0 ;
V_181 -> V_146 . V_191 . V_193 = F_94 ( 72 ) ;
}
V_11 -> V_24 -> V_88 [ V_184 ] = V_181 ;
} else {
return - V_194 ;
}
if ( V_17 -> V_22 -> V_195 > 1 ) {
V_182 ++ ;
if ( V_183 == V_186 || V_183 == V_187 ) {
V_181 = & V_26 -> V_188 [ V_196 ] -> V_181 ;
* V_181 = V_197 ;
V_11 -> V_24 -> V_88 [ V_185 ] = V_181 ;
} else {
return - V_194 ;
}
}
return 0 ;
}
static int F_95 ( struct V_10 * V_11 )
{
V_11 -> V_49 = V_198
| V_199
| V_200 ;
V_11 -> V_201 = F_96 () ;
V_11 -> V_202 = V_203 ;
V_11 -> V_204 = 2 ;
V_11 -> V_205 = 7 * 1000 ;
V_11 -> V_24 -> V_206 = F_97 ( V_40 ) ;
V_11 -> V_207 = L_38 ;
V_11 -> V_208 = 0 ;
return F_92 ( V_11 ) ;
}
static struct V_16 * F_98 ( struct V_153 * V_154 )
{
struct V_16 * V_17 = NULL ;
int V_209 , V_30 ;
struct V_10 * V_11 ;
T_5 V_210 [ V_211 ] ;
V_209 = V_212 ;
V_30 = 0 ;
if ( V_209 < 0 )
return NULL ;
V_11 = F_83 ( V_154 ) ;
if ( V_11 != NULL )
V_17 = V_11 -> V_18 ;
if ( F_48 ( V_11 == NULL ) || F_48 ( V_17 == NULL ) )
return NULL ;
V_17 -> V_24 = V_11 -> V_24 ;
F_99 ( & V_17 -> V_174 , 0 ) ;
F_100 ( & V_17 -> V_152 , F_60 , ( unsigned long ) V_17 ) ;
F_101 ( & V_17 -> V_21 ) ;
F_101 ( & V_17 -> V_151 ) ;
if ( F_67 ( V_17 , V_154 ) < 0 ) {
F_5 ( V_17 -> V_24 , L_39
L_40 , V_69 , L_41 ) ;
F_70 ( V_17 ) ;
F_82 ( V_154 ) ;
return NULL ;
}
V_17 -> V_26 = F_102 ( ( void * ) V_17 , V_154 , V_209 , false , & V_30 ) ;
F_70 ( V_17 ) ;
if ( ! V_17 -> V_26 ) {
F_5 ( V_17 -> V_24 , L_42 ,
V_69 , V_30 ) ;
goto V_213;
}
V_17 -> V_22 = F_103 ( V_17 -> V_26 ) ;
V_17 -> V_22 -> V_31 = V_11 ;
if ( F_104 ( V_154 -> V_173 , F_87 ,
V_214 , V_69 , V_17 ) ) {
F_5 ( V_17 -> V_24 , L_43 , V_209 ) ;
goto V_213;
}
V_17 -> V_173 = V_154 -> V_173 ;
F_105 ( V_17 -> V_22 , L_37 , V_17 , NULL ) ;
if ( F_95 ( V_11 ) ) {
F_5 ( V_17 -> V_24 , L_44 , V_209 ,
V_35 ) ;
goto V_213;
}
F_106 ( V_17 -> V_26 ) ;
memcpy ( V_210 , & V_17 -> V_22 -> V_215 , V_211 ) ;
if ( F_48 ( ! F_107 ( V_210 ) ) )
goto V_213;
F_108 ( V_11 , V_210 ) ;
V_30 = F_109 ( V_11 ) ;
if ( V_30 )
F_5 ( V_17 -> V_24 , L_45
L_46 , V_35 , V_30 ) ;
if ( V_17 -> V_22 -> V_216 [ 0 ] &&
F_110 ( V_17 -> V_24 , V_17 -> V_22 -> V_216 ) )
F_5 ( V_17 -> V_24 , L_47 , V_35 ) ;
V_212 ++ ;
return V_17 ;
V_213:
F_72 ( V_17 ) ;
return NULL ;
}
static int T_7 F_111 ( struct V_153 * V_154 )
{
struct V_16 * V_17 ;
struct V_10 * V_11 ;
F_112 ( & V_154 -> V_156 , L_48 ,
V_154 -> V_217 . V_218 , V_154 -> V_217 . V_217 , V_154 -> V_217 . V_219 , V_154 -> V_217 . V_220 ,
V_154 -> V_173 ) ;
if ( ( V_154 -> V_217 . V_218 != V_221 ) ||
( V_154 -> V_217 . V_217 != V_222 ) )
return - V_34 ;
V_11 = F_113 ( sizeof( struct V_16 ) , & V_223 ) ;
if ( ! V_11 ) {
F_114 ( L_49 , V_35 ) ;
return - V_224 ;
}
F_115 ( V_11 , & V_154 -> V_156 ) ;
F_85 ( V_154 , V_11 ) ;
memset ( V_11 -> V_18 , 0 , sizeof( * V_17 ) ) ;
V_17 = F_98 ( V_154 ) ;
if ( ! V_17 ) {
F_114 ( L_50 , V_35 ) ;
return - V_34 ;
}
return 0 ;
}
static int F_116 ( struct V_153 * V_154 )
{
struct V_16 * V_17 ;
struct V_10 * V_11 ;
V_11 = F_83 ( V_154 ) ;
V_17 = V_11 -> V_18 ;
if ( ! V_17 ) {
F_114 ( L_51 , V_69 ,
V_35 ) ;
return - V_34 ;
}
F_4 ( & V_17 -> V_21 ) ;
V_17 -> V_22 -> V_225 = false ;
F_8 ( & V_17 -> V_21 ) ;
F_117 ( L_52 ) ;
return 0 ;
}
static int F_118 ( struct V_153 * V_154 )
{
F_117 ( L_53 ) ;
return 0 ;
}
static void F_119 ( struct V_226 * V_227 )
{
int error ;
error = F_120 ( & V_228 ) ;
if ( error )
F_114 ( L_54 , V_35 , error ) ;
}
static int T_8 F_121 ( void )
{
#ifdef F_80
if ( V_229 != 0xdeadbeef )
V_230 = V_229 ;
#endif
if ( ! F_122 ( & V_231 ) )
return - V_232 ;
return 0 ;
}
static void T_9 F_123 ( void )
{
F_124 ( & V_231 ) ;
F_125 ( & V_228 ) ;
}
void F_126 ( struct V_16 * V_17 , struct V_233 * V_234 ,
bool V_235 , int V_236 )
{
F_5 ( V_17 -> V_24 , L_55 , V_35 ) ;
}
void F_127 ( struct V_16 * V_17 )
{
F_128 ( V_17 -> V_22 -> V_31 -> V_24 , L_56 , V_17 -> V_22 -> V_209 ) ;
F_129 ( V_17 ) ;
F_130 ( V_17 -> V_26 , V_17 -> V_32 ) ;
}
T_10 F_129 ( struct V_16 * V_17 )
{
F_128 ( V_17 -> V_22 -> V_31 -> V_24 , L_56 , V_17 -> V_22 -> V_209 ) ;
F_131 ( V_17 -> V_26 ) ;
V_17 -> V_150 = false ;
V_17 -> V_22 -> V_23 = false ;
return 0 ;
}
void F_132 ( struct V_16 * V_17 )
{
F_5 ( V_17 -> V_26 -> V_24 , L_57 ,
V_17 -> V_26 -> V_22 -> V_209 ) ;
F_129 ( V_17 ) ;
F_133 ( V_17 -> V_22 -> V_31 ) ;
}
void F_66 ( struct V_16 * V_17 )
{
unsigned long V_49 ;
F_61 ( & V_17 -> V_151 , V_49 ) ;
F_134 ( V_17 -> V_26 ) ;
F_63 ( & V_17 -> V_151 , V_49 ) ;
}
T_2 F_135 ( struct V_16 * V_17 )
{
unsigned long V_49 ;
T_2 V_36 ;
F_61 ( & V_17 -> V_151 , V_49 ) ;
V_36 = F_136 ( V_17 -> V_26 ) ;
F_63 ( & V_17 -> V_151 , V_49 ) ;
return V_36 ;
}
void F_137 ( struct V_16 * V_17 , T_2 V_237 )
{
unsigned long V_49 ;
F_61 ( & V_17 -> V_151 , V_49 ) ;
F_138 ( V_17 -> V_26 , V_237 ) ;
F_63 ( & V_17 -> V_151 , V_49 ) ;
}
int F_13 ( struct V_16 * V_17 )
{
int error = 0 ;
if ( V_17 -> V_22 -> V_23 )
return 0 ;
error = F_139 ( V_17 -> V_26 ) ;
return error ;
}
void F_17 ( struct V_16 * V_17 )
{
T_10 V_174 , V_238 = 0 ;
V_238 = F_140 ( V_17 -> V_26 ) ;
V_174 = F_78 ( & V_17 -> V_174 ) - V_238 ;
F_8 ( & V_17 -> V_21 ) ;
F_141 ( ( F_78 ( & V_17 -> V_174 ) > V_174 ) , 100 * 1000 ) ;
F_4 ( & V_17 -> V_21 ) ;
}
static void F_142 ( struct V_226 * V_227 )
{
struct V_170 * V_171 = F_143 ( V_227 , struct V_170 ,
V_239 . V_227 ) ;
F_4 ( & V_171 -> V_17 -> V_21 ) ;
if ( V_171 -> V_240 ) {
if ( V_171 -> V_241 ) {
F_144 ( & V_171 -> V_17 -> V_174 ) ;
F_145 ( V_171 -> V_17 -> V_22 -> V_31 ,
& V_171 -> V_239 ,
F_146 ( V_171 -> V_242 ) ) ;
} else {
V_171 -> V_240 = false ;
}
V_171 -> V_243 ( V_171 -> V_244 ) ;
}
F_147 ( & V_171 -> V_17 -> V_174 ) ;
F_8 ( & V_171 -> V_17 -> V_21 ) ;
}
struct V_170 * F_148 ( struct V_16 * V_17 ,
void (* V_243) ( void * V_244 ) ,
void * V_244 , const char * V_176 )
{
struct V_170 * V_171 ;
V_171 = F_149 ( sizeof( struct V_170 ) , V_245 ) ;
if ( ! V_171 )
return NULL ;
F_150 ( & V_171 -> V_239 , F_142 ) ;
V_171 -> V_17 = V_17 ;
V_171 -> V_243 = V_243 ;
V_171 -> V_244 = V_244 ;
V_171 -> V_172 = V_17 -> V_175 ;
V_17 -> V_175 = V_171 ;
#ifdef F_80
V_171 -> V_176 = F_151 ( strlen ( V_176 ) + 1 , V_245 ) ;
if ( V_171 -> V_176 )
strcpy ( V_171 -> V_176 , V_176 ) ;
#endif
return V_171 ;
}
void F_152 ( struct V_170 * V_171 , T_10 V_242 , int V_241 )
{
struct V_10 * V_11 = V_171 -> V_17 -> V_22 -> V_31 ;
#ifdef F_80
if ( V_171 -> V_240 )
F_5 ( V_11 -> V_24 , L_58 ,
V_35 , V_171 -> V_176 , V_241 ) ;
#endif
V_171 -> V_242 = V_242 ;
V_171 -> V_241 = ( bool ) V_241 ;
V_171 -> V_240 = true ;
F_144 ( & V_171 -> V_17 -> V_174 ) ;
F_145 ( V_11 , & V_171 -> V_239 , F_146 ( V_242 ) ) ;
}
bool F_153 ( struct V_170 * V_171 )
{
if ( V_171 -> V_240 ) {
V_171 -> V_240 = false ;
if ( ! F_154 ( & V_171 -> V_239 ) )
return false ;
F_147 ( & V_171 -> V_17 -> V_174 ) ;
}
return true ;
}
void F_155 ( struct V_170 * V_171 )
{
struct V_16 * V_17 = V_171 -> V_17 ;
struct V_170 * V_246 ;
F_153 ( V_171 ) ;
if ( V_17 -> V_175 == V_171 ) {
V_17 -> V_175 = V_17 -> V_175 -> V_172 ;
#ifdef F_80
F_81 ( V_171 -> V_176 ) ;
#endif
F_81 ( V_171 ) ;
return;
}
V_246 = V_17 -> V_175 ;
while ( V_246 ) {
if ( V_246 -> V_172 == V_171 ) {
V_246 -> V_172 = V_171 -> V_172 ;
#ifdef F_80
F_81 ( V_171 -> V_176 ) ;
#endif
F_81 ( V_171 ) ;
return;
}
V_246 = V_246 -> V_172 ;
}
}
int F_156 ( struct V_16 * V_17 , void * * V_247 , T_2 V_248 )
{
int V_5 , V_249 ;
const T_5 * V_250 ;
struct V_167 * V_251 ;
for ( V_5 = 0 ; V_5 < V_17 -> V_158 . V_168 ; V_5 ++ ) {
V_251 = (struct V_167 * ) V_17 -> V_158 . V_164 [ V_5 ] -> V_149 ;
for ( V_249 = 0 ; V_249 < V_17 -> V_158 . V_165 [ V_5 ] ;
V_249 ++ , V_251 ++ ) {
T_2 V_252 = F_157 ( V_251 -> V_252 ) ;
if ( F_157 ( V_251 -> V_248 ) == V_248 ) {
V_250 = V_17 -> V_158 . V_163 [ V_5 ] -> V_149 +
F_157 ( V_251 -> V_253 ) ;
* V_247 = F_158 ( V_250 , V_252 , V_245 ) ;
if ( * V_247 == NULL )
goto V_213;
return 0 ;
}
}
}
F_5 ( V_17 -> V_24 , L_59 ,
V_248 ) ;
* V_247 = NULL ;
V_213:
return - V_254 ;
}
int F_159 ( struct V_16 * V_17 , T_11 * V_255 , T_2 V_248 )
{
int V_5 , V_249 ;
const T_5 * V_250 ;
struct V_167 * V_251 ;
for ( V_5 = 0 ; V_5 < V_17 -> V_158 . V_168 ; V_5 ++ ) {
V_251 = (struct V_167 * ) V_17 -> V_158 . V_164 [ V_5 ] -> V_149 ;
for ( V_249 = 0 ; V_249 < V_17 -> V_158 . V_165 [ V_5 ] ;
V_249 ++ , V_251 ++ ) {
if ( F_157 ( V_251 -> V_248 ) == V_248 ) {
V_250 = V_17 -> V_158 . V_163 [ V_5 ] -> V_149 +
F_157 ( V_251 -> V_253 ) ;
if ( F_157 ( V_251 -> V_252 ) != 4 ) {
F_5 ( V_17 -> V_24 ,
L_60 ) ;
return - V_256 ;
}
* V_255 = F_157 ( * ( ( V_257 * ) V_250 ) ) ;
return 0 ;
}
}
}
F_5 ( V_17 -> V_24 , L_61 , V_248 ) ;
return - V_256 ;
}
void F_160 ( void * V_258 )
{
F_81 ( V_258 ) ;
}
int F_161 ( struct V_16 * V_17 )
{
int V_5 ;
int V_249 ;
int V_259 = 0 ;
const struct V_260 * V_158 ;
const struct V_260 * V_164 ;
struct V_167 * V_261 ;
for ( V_5 = 0 ; V_5 < V_160 && V_259 == 0 ; V_5 ++ ) {
V_158 = V_17 -> V_158 . V_163 [ V_5 ] ;
V_164 = V_17 -> V_158 . V_164 [ V_5 ] ;
if ( V_158 == NULL && V_164 == NULL ) {
break;
} else if ( V_158 == NULL || V_164 == NULL ) {
F_5 ( V_17 -> V_24 , L_62 ,
V_35 ) ;
V_259 = - V_262 ;
} else if ( V_164 -> V_166 % sizeof( struct V_167 ) ) {
F_5 ( V_17 -> V_24 , L_63
L_64 , V_35 , V_164 -> V_166 ,
sizeof( struct V_167 ) ) ;
V_259 = - V_262 ;
} else if ( V_158 -> V_166 < V_263 || V_158 -> V_166 > V_264 ) {
F_5 ( V_17 -> V_24 , L_65
L_66 , V_35 , V_158 -> V_166 ) ;
V_259 = - V_262 ;
} else {
V_261 = (struct V_167 * ) V_164 -> V_149 ;
for ( V_249 = 0 ; V_249 < V_17 -> V_158 . V_165 [ V_5 ] &&
! V_259 ; V_249 ++ , V_261 ++ ) {
if ( F_157 ( V_261 -> V_253 ) +
F_157 ( V_261 -> V_252 ) >
V_158 -> V_166 ) {
F_5 ( V_17 -> V_24 ,
L_67 ,
V_35 ) ;
V_259 = - V_262 ;
}
}
}
}
if ( V_259 == 0 && V_17 -> V_158 . V_168 != V_5 ) {
F_5 ( V_17 -> V_24 , L_68 , V_35 ,
V_17 -> V_158 . V_168 ) ;
V_259 = - V_262 ;
}
return V_259 ;
}
bool F_11 ( struct V_16 * V_17 )
{
bool V_29 = F_55 ( V_17 -> V_26 ) ;
F_8 ( & V_17 -> V_21 ) ;
F_56 ( V_17 -> V_22 -> V_31 -> V_24 , V_29 ) ;
if ( V_29 )
F_162 ( V_17 -> V_22 -> V_31 -> V_24 ) ;
F_4 ( & V_17 -> V_21 ) ;
return V_29 ;
}
void F_163 ( struct V_16 * V_17 , T_10 V_242 )
{
F_8 ( & V_17 -> V_21 ) ;
F_164 ( V_242 ) ;
F_4 ( & V_17 -> V_21 ) ;
}
