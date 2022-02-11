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
F_3 ( & V_15 -> V_17 ) ;
if ( ! V_15 -> V_18 -> V_19 ) {
F_4 ( V_15 -> V_20 , L_1 ) ;
F_5 ( V_13 ) ;
goto V_21;
}
F_6 ( V_15 -> V_22 , V_13 , V_11 ) ;
V_21:
F_7 ( & V_15 -> V_17 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
bool V_23 ;
int V_24 ;
F_9 ( V_11 ) ;
F_3 ( & V_15 -> V_17 ) ;
V_23 = F_10 ( V_15 ) ;
F_7 ( & V_15 -> V_17 ) ;
if ( ! V_23 )
F_11 ( V_15 -> V_18 -> V_25 -> V_20 ) ;
F_3 ( & V_15 -> V_17 ) ;
V_15 -> V_26 = true ;
if ( ! V_15 -> V_18 -> V_19 )
V_24 = F_12 ( V_15 ) ;
else
V_24 = - V_27 ;
F_7 ( & V_15 -> V_17 ) ;
if ( V_24 != 0 )
F_4 ( V_11 -> V_20 , L_2 , V_28 ,
V_24 ) ;
return V_24 ;
}
static void F_13 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
int V_29 ;
F_14 ( V_11 ) ;
if ( V_15 -> V_22 == NULL )
return;
F_3 ( & V_15 -> V_17 ) ;
V_29 = F_15 ( V_15 -> V_22 -> V_11 -> V_30 ,
V_15 -> V_22 -> V_11 -> V_31 ) ;
F_7 ( & V_15 -> V_17 ) ;
if ( ! V_29 ) {
F_4 ( V_15 -> V_20 ,
L_3 ) ;
return;
}
F_3 ( & V_15 -> V_17 ) ;
F_16 ( V_15 ) ;
F_7 ( & V_15 -> V_17 ) ;
}
static int
F_17 ( struct V_10 * V_11 , struct V_32 * V_33 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
if ( V_33 -> type != V_34 ) {
F_4 ( V_11 -> V_20 , L_4
L_5 , V_28 , V_33 -> type ) ;
return - V_35 ;
}
V_15 -> V_26 = false ;
F_18 ( V_15 -> V_22 , false ) ;
return 0 ;
}
static void
F_19 ( struct V_10 * V_11 , struct V_32 * V_33 )
{
}
static int F_20 ( struct V_10 * V_11 , T_2 V_36 )
{
struct V_37 * V_38 = & V_11 -> V_38 ;
struct V_14 * V_15 = V_11 -> V_16 ;
int V_24 = 0 ;
int V_39 ;
struct V_20 * V_20 = V_11 -> V_20 ;
F_3 ( & V_15 -> V_17 ) ;
if ( V_36 & V_40 ) {
F_21 ( V_15 -> V_22 ,
V_38 -> V_41 ) ;
}
if ( V_36 & V_42 )
F_22 ( V_20 , L_6 ,
V_28 , V_38 -> V_43 & V_44 ?
L_7 : L_8 ) ;
if ( V_36 & V_45 )
F_4 ( V_20 , L_9 ,
V_28 , V_38 -> V_43 & V_46 ?
L_7 : L_8 ) ;
if ( V_36 & V_47 ) {
V_24 = F_23 ( V_15 -> V_22 , V_38 -> V_48 ) ;
if ( V_24 < 0 ) {
F_4 ( V_20 , L_10 ,
V_28 ) ;
goto V_49;
}
V_39 = F_24 ( V_15 -> V_22 ) ;
if ( V_39 != V_38 -> V_48 )
F_4 ( V_20 , L_11
L_12 , V_28 , V_38 -> V_48 ,
V_39 ) ;
}
if ( V_36 & V_50 ) {
if ( V_38 -> V_51 == V_52 ||
V_38 -> V_51 == V_53 )
V_24 = F_25 ( V_15 -> V_22 ,
V_38 -> V_54 -> V_55 ) ;
else
V_24 = - V_56 ;
}
if ( V_36 & V_57 )
V_24 = F_26 ( V_15 -> V_22 ,
V_38 -> V_58 ,
V_38 -> V_59 ) ;
V_49:
F_7 ( & V_15 -> V_17 ) ;
return V_24 ;
}
static void
F_27 ( struct V_10 * V_11 ,
struct V_32 * V_33 ,
struct V_60 * V_61 , T_2 V_36 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_20 * V_20 = V_11 -> V_20 ;
if ( V_36 & V_62 ) {
F_4 ( V_20 , L_13 , V_63 ,
V_28 , V_61 -> V_64 ? L_14 : L_15 ) ;
F_3 ( & V_15 -> V_17 ) ;
F_28 ( V_15 -> V_22 , V_61 -> V_64 ) ;
F_7 ( & V_15 -> V_17 ) ;
}
if ( V_36 & V_65 ) {
T_3 V_66 ;
if ( V_61 -> V_67 )
V_66 = 1 ;
else
V_66 = 0 ;
F_3 ( & V_15 -> V_17 ) ;
F_29 ( V_15 -> V_22 , V_66 ) ;
F_7 ( & V_15 -> V_17 ) ;
}
if ( V_36 & V_68 ) {
T_1 V_69 = V_61 -> V_70 ;
F_3 ( & V_15 -> V_17 ) ;
F_30 ( V_15 -> V_22 , V_71 ,
V_69 & V_72 ) ;
F_30 ( V_15 -> V_22 , V_73 ,
V_69 & V_74 ) ;
F_30 ( V_15 -> V_22 , V_75 ,
V_69 & V_76 ) ;
F_7 ( & V_15 -> V_17 ) ;
}
if ( V_36 & V_77 ) {
struct V_78 * V_79 ;
T_2 V_80 , V_5 ;
T_1 V_3 ;
struct V_1 V_2 ;
int error ;
F_3 ( & V_15 -> V_17 ) ;
F_31 ( V_15 -> V_22 , & V_2 ) ;
F_7 ( & V_15 -> V_17 ) ;
V_80 = V_61 -> V_81 ;
V_79 = V_11 -> V_20 -> V_82 [ F_32 ( V_15 -> V_22 ) ] ;
for ( V_5 = 0 ; V_5 < V_79 -> V_83 ; V_5 ++ ) {
V_3 = ( V_79 -> V_84 [ V_5 ] . V_85 << 1 ) / 10 ;
F_1 ( & V_2 , V_3 , V_80 & 1 ) ;
V_80 >>= 1 ;
}
F_3 ( & V_15 -> V_17 ) ;
error = F_33 ( V_15 -> V_22 , & V_2 ) ;
F_7 ( & V_15 -> V_17 ) ;
if ( error )
F_4 ( V_20 , L_16 ,
error ) ;
}
if ( V_36 & V_86 ) {
F_3 ( & V_15 -> V_17 ) ;
F_34 ( V_15 -> V_22 , V_61 -> V_87 ) ;
F_7 ( & V_15 -> V_17 ) ;
}
if ( V_36 & V_88 ) {
F_3 ( & V_15 -> V_17 ) ;
F_35 ( V_15 -> V_22 , V_89 , V_61 -> V_90 ) ;
F_7 ( & V_15 -> V_17 ) ;
}
if ( V_36 & V_91 )
F_4 ( V_20 , L_17 , V_28 ) ;
if ( V_36 & V_92 ) {
F_4 ( V_20 , L_18 , V_28 ,
V_61 -> V_93 ? L_7 : L_8 ) ;
}
if ( V_36 & V_94 ) {
F_4 ( V_20 , L_19
L_20 , V_28 , V_61 -> V_95 ,
V_61 -> V_96 ) ;
}
if ( V_36 & V_97 ) {
F_4 ( V_20 , L_21 , V_28 ,
V_61 -> V_98 ? L_7 : L_8 ) ;
}
if ( V_36 & V_99 ) {
F_4 ( V_20 , L_22
L_20 , V_28 , V_61 -> V_100 ?
L_7 : L_8 , V_61 -> V_101 ) ;
}
if ( V_36 & V_102 ) {
F_4 ( V_20 , L_23 , V_28 ,
V_61 -> V_103 ? L_7 : L_8 ) ;
}
return;
}
static void
F_36 ( struct V_10 * V_11 ,
unsigned int V_104 ,
unsigned int * V_105 , T_4 V_106 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_20 * V_20 = V_11 -> V_20 ;
V_104 &= V_107 ;
* V_105 &= V_107 ;
if ( V_104 & V_108 )
F_22 ( V_20 , L_24 ) ;
if ( V_104 & V_109 )
F_22 ( V_20 , L_25 ) ;
if ( V_104 & V_110 )
F_22 ( V_20 , L_26 ) ;
if ( V_104 & V_111 )
F_22 ( V_20 , L_27 ) ;
if ( V_104 & V_112 )
F_22 ( V_20 , L_28 ) ;
if ( V_104 & V_113 )
F_22 ( V_20 , L_29 ) ;
if ( V_104 & V_114 )
F_22 ( V_20 , L_30 ) ;
F_3 ( & V_15 -> V_17 ) ;
F_37 ( V_15 -> V_22 , * V_105 ) ;
F_7 ( & V_15 -> V_17 ) ;
return;
}
static void F_38 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_3 ( & V_15 -> V_17 ) ;
F_39 ( V_15 -> V_22 ) ;
F_7 ( & V_15 -> V_17 ) ;
return;
}
static void F_40 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_3 ( & V_15 -> V_17 ) ;
F_41 ( V_15 -> V_22 ) ;
F_7 ( & V_15 -> V_17 ) ;
return;
}
static int
F_42 ( struct V_10 * V_11 , struct V_32 * V_33 , T_1 V_115 ,
const struct V_116 * V_117 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_3 ( & V_15 -> V_17 ) ;
F_43 ( V_15 -> V_22 , V_115 , V_117 , true ) ;
F_7 ( & V_15 -> V_17 ) ;
return 0 ;
}
static int
F_44 ( struct V_10 * V_11 , struct V_32 * V_33 ,
struct V_118 * V_119 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_120 * V_120 = & V_15 -> V_22 -> V_121 ;
F_45 ( V_120 ) ;
V_15 -> V_18 -> V_122 = & ( V_120 -> V_123 ) ;
V_15 -> V_18 -> V_122 -> V_120 = V_120 ;
V_15 -> V_18 -> V_122 -> V_124 = 16 ;
return 0 ;
}
static int
F_46 ( struct V_10 * V_11 ,
struct V_32 * V_33 ,
enum V_125 V_126 ,
struct V_118 * V_119 , T_1 V_127 , T_1 * V_128 ,
T_5 V_129 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_120 * V_120 = & V_15 -> V_22 -> V_121 ;
int V_29 ;
if ( F_47 ( V_120 -> V_130 != V_131 ) )
return - V_132 ;
switch ( V_126 ) {
case V_133 :
break;
case V_134 :
break;
case V_135 :
F_3 ( & V_15 -> V_17 ) ;
V_29 = F_48 ( V_15 -> V_22 , V_127 ) ;
F_7 ( & V_15 -> V_17 ) ;
if ( ! V_29 ) {
F_4 ( V_15 -> V_20 , L_31 ,
V_127 ) ;
return - V_136 ;
}
F_49 ( V_33 , V_119 -> V_137 , V_127 ) ;
break;
case V_138 :
F_3 ( & V_15 -> V_17 ) ;
F_50 ( V_15 -> V_22 , V_119 , V_127 ) ;
F_7 ( & V_15 -> V_17 ) ;
F_51 ( V_33 , V_119 -> V_137 , V_127 ) ;
break;
case V_139 :
F_3 ( & V_15 -> V_17 ) ;
F_52 ( V_15 -> V_22 , V_127 , V_129 ,
( 1 << ( V_140 +
V_119 -> V_141 . V_142 ) ) - 1 ) ;
F_7 ( & V_15 -> V_17 ) ;
break;
default:
F_4 ( V_15 -> V_20 , L_32 ,
V_28 ) ;
}
return 0 ;
}
static void F_53 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
bool V_23 ;
F_3 ( & V_15 -> V_17 ) ;
V_23 = F_54 ( V_15 -> V_22 ) ;
F_7 ( & V_15 -> V_17 ) ;
F_55 ( V_15 -> V_18 -> V_25 -> V_20 , V_23 ) ;
}
static void F_56 ( struct V_10 * V_11 , bool V_143 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_57 ( L_33 , V_28 , V_143 ? L_7 : L_8 ) ;
F_3 ( & V_15 -> V_17 ) ;
F_58 ( V_15 -> V_22 , V_143 ) ;
F_7 ( & V_15 -> V_17 ) ;
}
static int F_59 ( struct V_14 * V_15 , char * V_144 )
{
return F_60 ( V_15 -> V_18 -> V_25 -> V_20 , V_144 ) ;
}
void F_61 ( unsigned long V_145 )
{
struct V_14 * V_15 ;
V_15 = (struct V_14 * ) V_145 ;
F_3 ( & V_15 -> V_17 ) ;
if ( V_15 -> V_18 -> V_19 ) {
if ( V_15 -> V_146 ) {
unsigned long V_43 ;
F_62 ( & V_15 -> V_147 , V_43 ) ;
F_63 ( V_15 -> V_22 ) ;
F_64 ( & V_15 -> V_147 , V_43 ) ;
}
V_15 -> V_146 = F_65 ( V_15 -> V_22 , true ) ;
}
if ( ! V_15 -> V_18 -> V_19 )
goto V_21;
if ( V_15 -> V_146 )
F_66 ( & V_15 -> V_148 ) ;
else
F_67 ( V_15 ) ;
V_21:
F_7 ( & V_15 -> V_17 ) ;
}
static int F_68 ( struct V_14 * V_15 , struct V_149 * V_150 )
{
int V_29 ;
struct V_151 * V_151 = & V_150 -> V_152 ;
char V_153 [ 100 ] ;
int V_5 ;
memset ( & V_15 -> V_154 , 0 , sizeof( struct V_155 ) ) ;
for ( V_5 = 0 ; V_5 < V_156 ; V_5 ++ ) {
if ( V_157 [ V_5 ] == NULL )
break;
sprintf ( V_153 , L_34 , V_157 [ V_5 ] ,
V_158 ) ;
V_29 = F_69 ( & V_15 -> V_154 . V_159 [ V_5 ] , V_153 , V_151 ) ;
if ( V_29 ) {
F_4 ( V_15 -> V_20 , L_35 ,
V_63 , V_153 ) ;
return V_29 ;
}
sprintf ( V_153 , L_36 , V_157 [ V_5 ] ,
V_158 ) ;
V_29 = F_69 ( & V_15 -> V_154 . V_160 [ V_5 ] , V_153 , V_151 ) ;
if ( V_29 ) {
F_4 ( V_15 -> V_20 , L_35 ,
V_63 , V_153 ) ;
return V_29 ;
}
V_15 -> V_154 . V_161 [ V_5 ] =
V_15 -> V_154 . V_160 [ V_5 ] -> V_162 / ( sizeof( struct V_163 ) ) ;
}
V_15 -> V_154 . V_164 = V_5 ;
return F_70 ( V_15 , & V_15 -> V_165 ) ;
}
static void F_71 ( struct V_14 * V_15 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_156 ; V_5 ++ ) {
F_72 ( V_15 -> V_154 . V_159 [ V_5 ] ) ;
F_72 ( V_15 -> V_154 . V_160 [ V_5 ] ) ;
}
}
static void F_73 ( struct V_14 * V_15 )
{
struct V_166 * V_167 , * V_168 ;
if ( V_15 -> V_154 . V_164 )
F_74 ( & V_15 -> V_165 ) ;
if ( V_15 -> V_169 )
F_75 ( V_15 -> V_169 , V_15 ) ;
F_76 ( & V_15 -> V_148 ) ;
if ( V_15 -> V_18 )
F_77 ( V_15 -> V_18 , L_37 , V_15 ) ;
if ( V_15 -> V_22 ) {
F_78 ( V_15 -> V_22 ) ;
V_15 -> V_22 = NULL ;
V_15 -> V_18 = NULL ;
}
while ( F_79 ( & V_15 -> V_170 ) > 0 )
F_80 () ;
for ( V_167 = V_15 -> V_171 ; V_167 ; V_167 = V_168 ) {
V_168 = V_167 -> V_168 ;
#ifdef F_81
F_82 ( V_167 -> V_172 ) ;
#endif
F_82 ( V_167 ) ;
}
}
static void F_83 ( struct V_149 * V_150 )
{
struct V_10 * V_11 = F_84 ( V_150 ) ;
struct V_14 * V_15 = V_11 -> V_16 ;
if ( V_15 -> V_22 ) {
F_55 ( V_15 -> V_18 -> V_25 -> V_20 , false ) ;
F_11 ( V_15 -> V_18 -> V_25 -> V_20 ) ;
F_85 ( V_11 ) ;
}
F_73 ( V_15 ) ;
F_86 ( V_150 , NULL ) ;
F_87 ( V_11 ) ;
}
static T_6 F_88 ( int V_169 , void * V_173 )
{
struct V_14 * V_15 ;
bool V_174 , V_175 ;
V_15 = (struct V_14 * ) V_173 ;
F_89 ( & V_15 -> V_147 ) ;
V_174 = F_90 ( V_15 -> V_22 , & V_175 ) ;
if ( V_174 ) {
if ( V_175 ) {
F_66 ( & V_15 -> V_148 ) ;
}
}
F_91 ( & V_15 -> V_147 ) ;
return F_92 ( V_174 ) ;
}
static int F_93 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_176 * V_22 = V_15 -> V_22 ;
struct V_78 * V_177 ;
int V_178 = 0 ;
T_1 V_179 ;
V_11 -> V_20 -> V_82 [ V_180 ] = NULL ;
V_11 -> V_20 -> V_82 [ V_181 ] = NULL ;
V_179 = F_94 ( V_15 -> V_22 , 0 ) ;
if ( V_179 == V_182 || V_179 == V_183 ) {
V_177 = & V_22 -> V_184 [ V_185 ] -> V_177 ;
* V_177 = V_186 ;
if ( V_179 == V_183 ) {
V_177 -> V_141 . V_187 . V_188 [ 1 ] = 0 ;
V_177 -> V_141 . V_187 . V_189 = F_95 ( 72 ) ;
}
V_11 -> V_20 -> V_82 [ V_180 ] = V_177 ;
} else {
return - V_190 ;
}
if ( V_15 -> V_18 -> V_191 > 1 ) {
V_178 ++ ;
if ( V_179 == V_182 || V_179 == V_183 ) {
V_177 = & V_22 -> V_184 [ V_192 ] -> V_177 ;
* V_177 = V_193 ;
V_11 -> V_20 -> V_82 [ V_181 ] = V_177 ;
} else {
return - V_190 ;
}
}
return 0 ;
}
static int F_96 ( struct V_10 * V_11 )
{
V_11 -> V_43 = V_194
| V_195
| V_196 ;
V_11 -> V_197 = F_97 () ;
V_11 -> V_198 = V_199 ;
V_11 -> V_200 = 2 ;
V_11 -> V_201 = 7 * 1000 ;
V_11 -> V_20 -> V_202 = F_98 ( V_34 ) ;
V_11 -> V_203 = L_38 ;
V_11 -> V_204 = 0 ;
return F_93 ( V_11 ) ;
}
static struct V_14 * F_99 ( struct V_149 * V_150 )
{
struct V_14 * V_15 = NULL ;
int V_205 , V_24 ;
struct V_10 * V_11 ;
T_5 V_206 [ V_207 ] ;
V_205 = V_208 ;
V_24 = 0 ;
if ( V_205 < 0 )
return NULL ;
V_11 = F_84 ( V_150 ) ;
if ( V_11 != NULL )
V_15 = V_11 -> V_16 ;
if ( F_47 ( V_11 == NULL ) || F_47 ( V_15 == NULL ) )
return NULL ;
V_15 -> V_20 = V_11 -> V_20 ;
F_100 ( & V_15 -> V_170 , 0 ) ;
F_101 ( & V_15 -> V_148 , F_61 , ( unsigned long ) V_15 ) ;
F_102 ( & V_15 -> V_17 ) ;
F_102 ( & V_15 -> V_147 ) ;
if ( F_68 ( V_15 , V_150 ) < 0 ) {
F_4 ( V_15 -> V_20 , L_39
L_40 , V_63 , L_41 ) ;
F_71 ( V_15 ) ;
F_83 ( V_150 ) ;
return NULL ;
}
V_15 -> V_22 = F_103 ( ( void * ) V_15 , V_150 , V_205 , false , & V_24 ) ;
F_71 ( V_15 ) ;
if ( ! V_15 -> V_22 ) {
F_4 ( V_15 -> V_20 , L_42 ,
V_63 , V_24 ) ;
goto V_209;
}
V_15 -> V_18 = F_104 ( V_15 -> V_22 ) ;
V_15 -> V_18 -> V_25 = V_11 ;
if ( F_105 ( V_150 -> V_169 , F_88 ,
V_210 , V_63 , V_15 ) ) {
F_4 ( V_15 -> V_20 , L_43 , V_205 ) ;
goto V_209;
}
V_15 -> V_169 = V_150 -> V_169 ;
F_106 ( V_15 -> V_18 , L_37 , V_15 , NULL ) ;
if ( F_96 ( V_11 ) ) {
F_4 ( V_15 -> V_20 , L_44 , V_205 ,
V_28 ) ;
goto V_209;
}
memcpy ( V_206 , & V_15 -> V_18 -> V_211 , V_207 ) ;
if ( F_47 ( ! F_107 ( V_206 ) ) )
goto V_209;
F_108 ( V_11 , V_206 ) ;
V_24 = F_109 ( V_11 ) ;
if ( V_24 )
F_4 ( V_15 -> V_20 , L_45
L_46 , V_28 , V_24 ) ;
if ( V_15 -> V_18 -> V_212 [ 0 ] && F_59 ( V_15 , V_15 -> V_18 -> V_212 ) )
F_4 ( V_15 -> V_20 , L_47 ,
V_28 , V_24 ) ;
V_208 ++ ;
return V_15 ;
V_209:
F_73 ( V_15 ) ;
return NULL ;
}
static int T_7 F_110 ( struct V_149 * V_150 )
{
struct V_14 * V_15 ;
struct V_10 * V_11 ;
F_111 ( & V_150 -> V_152 , L_48 ,
V_150 -> V_213 . V_214 , V_150 -> V_213 . V_213 , V_150 -> V_213 . V_215 , V_150 -> V_213 . V_216 ,
V_150 -> V_169 ) ;
if ( ( V_150 -> V_213 . V_214 != V_217 ) ||
( V_150 -> V_213 . V_213 != V_218 ) )
return - V_27 ;
V_11 = F_112 ( sizeof( struct V_14 ) , & V_219 ) ;
if ( ! V_11 ) {
F_113 ( L_49 , V_28 ) ;
return - V_220 ;
}
F_114 ( V_11 , & V_150 -> V_152 ) ;
F_86 ( V_150 , V_11 ) ;
memset ( V_11 -> V_16 , 0 , sizeof( * V_15 ) ) ;
V_15 = F_99 ( V_150 ) ;
if ( ! V_15 ) {
F_113 ( L_50 , V_28 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_115 ( struct V_149 * V_150 )
{
struct V_14 * V_15 ;
struct V_10 * V_11 ;
V_11 = F_84 ( V_150 ) ;
V_15 = V_11 -> V_16 ;
if ( ! V_15 ) {
F_113 ( L_51 , V_63 ,
V_28 ) ;
return - V_27 ;
}
F_3 ( & V_15 -> V_17 ) ;
V_15 -> V_18 -> V_221 = false ;
F_7 ( & V_15 -> V_17 ) ;
F_116 ( L_52 ) ;
return 0 ;
}
static int F_117 ( struct V_149 * V_150 )
{
F_116 ( L_53 ) ;
return 0 ;
}
static void F_118 ( struct V_222 * V_223 )
{
int error ;
error = F_119 ( & V_224 ) ;
if ( error )
F_113 ( L_54 , V_28 , error ) ;
}
static int T_8 F_120 ( void )
{
#ifdef F_81
if ( V_225 != 0xdeadbeef )
V_226 = V_225 ;
#endif
if ( ! F_121 ( & V_227 ) )
return - V_228 ;
return 0 ;
}
static void T_9 F_122 ( void )
{
F_123 ( & V_227 ) ;
F_124 ( & V_224 ) ;
}
void F_125 ( struct V_14 * V_15 , struct V_229 * V_230 ,
bool V_231 , int V_232 )
{
F_4 ( V_15 -> V_20 , L_55 , V_28 ) ;
}
void F_126 ( struct V_14 * V_15 )
{
F_127 ( V_15 -> V_18 -> V_25 -> V_20 , L_56 , V_15 -> V_18 -> V_205 ) ;
F_128 ( V_15 ) ;
F_129 ( V_15 -> V_22 , V_15 -> V_26 ) ;
}
T_10 F_128 ( struct V_14 * V_15 )
{
F_127 ( V_15 -> V_18 -> V_25 -> V_20 , L_56 , V_15 -> V_18 -> V_205 ) ;
F_130 ( V_15 -> V_22 ) ;
V_15 -> V_146 = false ;
return 0 ;
}
void F_131 ( struct V_14 * V_15 )
{
F_4 ( V_15 -> V_22 -> V_20 , L_57 ,
V_15 -> V_22 -> V_18 -> V_205 ) ;
F_128 ( V_15 ) ;
F_132 ( V_15 -> V_18 -> V_25 ) ;
}
void F_67 ( struct V_14 * V_15 )
{
unsigned long V_43 ;
F_62 ( & V_15 -> V_147 , V_43 ) ;
F_133 ( V_15 -> V_22 ) ;
F_64 ( & V_15 -> V_147 , V_43 ) ;
}
T_2 F_134 ( struct V_14 * V_15 )
{
unsigned long V_43 ;
T_2 V_29 ;
F_62 ( & V_15 -> V_147 , V_43 ) ;
V_29 = F_135 ( V_15 -> V_22 ) ;
F_64 ( & V_15 -> V_147 , V_43 ) ;
return V_29 ;
}
void F_136 ( struct V_14 * V_15 , T_2 V_233 )
{
unsigned long V_43 ;
F_62 ( & V_15 -> V_147 , V_43 ) ;
F_137 ( V_15 -> V_22 , V_233 ) ;
F_64 ( & V_15 -> V_147 , V_43 ) ;
}
int F_12 ( struct V_14 * V_15 )
{
int error = 0 ;
if ( V_15 -> V_18 -> V_19 )
return 0 ;
error = F_138 ( V_15 -> V_22 ) ;
return error ;
}
void F_16 ( struct V_14 * V_15 )
{
T_10 V_170 , V_234 = 0 ;
V_234 = F_139 ( V_15 -> V_22 ) ;
V_170 = F_79 ( & V_15 -> V_170 ) - V_234 ;
F_7 ( & V_15 -> V_17 ) ;
F_140 ( ( F_79 ( & V_15 -> V_170 ) > V_170 ) , 100 * 1000 ) ;
F_3 ( & V_15 -> V_17 ) ;
}
static void F_141 ( struct V_222 * V_223 )
{
struct V_166 * V_167 = F_142 ( V_223 , struct V_166 ,
V_235 . V_223 ) ;
F_3 ( & V_167 -> V_15 -> V_17 ) ;
if ( V_167 -> V_236 ) {
if ( V_167 -> V_237 ) {
F_143 ( & V_167 -> V_15 -> V_170 ) ;
F_144 ( V_167 -> V_15 -> V_18 -> V_25 ,
& V_167 -> V_235 ,
F_145 ( V_167 -> V_238 ) ) ;
} else {
V_167 -> V_236 = false ;
}
V_167 -> V_239 ( V_167 -> V_240 ) ;
}
F_146 ( & V_167 -> V_15 -> V_170 ) ;
F_7 ( & V_167 -> V_15 -> V_17 ) ;
}
struct V_166 * F_147 ( struct V_14 * V_15 ,
void (* V_239) ( void * V_240 ) ,
void * V_240 , const char * V_172 )
{
struct V_166 * V_167 ;
V_167 = F_148 ( sizeof( struct V_166 ) , V_241 ) ;
if ( ! V_167 )
return NULL ;
F_149 ( & V_167 -> V_235 , F_141 ) ;
V_167 -> V_15 = V_15 ;
V_167 -> V_239 = V_239 ;
V_167 -> V_240 = V_240 ;
V_167 -> V_168 = V_15 -> V_171 ;
V_15 -> V_171 = V_167 ;
#ifdef F_81
V_167 -> V_172 = F_150 ( strlen ( V_172 ) + 1 , V_241 ) ;
if ( V_167 -> V_172 )
strcpy ( V_167 -> V_172 , V_172 ) ;
#endif
return V_167 ;
}
void F_151 ( struct V_166 * V_167 , T_10 V_238 , int V_237 )
{
struct V_10 * V_11 = V_167 -> V_15 -> V_18 -> V_25 ;
#ifdef F_81
if ( V_167 -> V_236 )
F_4 ( V_11 -> V_20 , L_58 ,
V_28 , V_167 -> V_172 , V_237 ) ;
#endif
V_167 -> V_238 = V_238 ;
V_167 -> V_237 = ( bool ) V_237 ;
V_167 -> V_236 = true ;
F_143 ( & V_167 -> V_15 -> V_170 ) ;
F_144 ( V_11 , & V_167 -> V_235 , F_145 ( V_238 ) ) ;
}
bool F_152 ( struct V_166 * V_167 )
{
if ( V_167 -> V_236 ) {
V_167 -> V_236 = false ;
if ( ! F_153 ( & V_167 -> V_235 ) )
return false ;
F_146 ( & V_167 -> V_15 -> V_170 ) ;
}
return true ;
}
void F_154 ( struct V_166 * V_167 )
{
struct V_14 * V_15 = V_167 -> V_15 ;
struct V_166 * V_242 ;
F_152 ( V_167 ) ;
if ( V_15 -> V_171 == V_167 ) {
V_15 -> V_171 = V_15 -> V_171 -> V_168 ;
#ifdef F_81
F_82 ( V_167 -> V_172 ) ;
#endif
F_82 ( V_167 ) ;
return;
}
V_242 = V_15 -> V_171 ;
while ( V_242 ) {
if ( V_242 -> V_168 == V_167 ) {
V_242 -> V_168 = V_167 -> V_168 ;
#ifdef F_81
F_82 ( V_167 -> V_172 ) ;
#endif
F_82 ( V_167 ) ;
return;
}
V_242 = V_242 -> V_168 ;
}
}
int F_155 ( struct V_14 * V_15 , void * * V_243 , T_2 V_244 )
{
int V_5 , V_245 ;
const T_5 * V_246 ;
struct V_163 * V_247 ;
for ( V_5 = 0 ; V_5 < V_15 -> V_154 . V_164 ; V_5 ++ ) {
V_247 = (struct V_163 * ) V_15 -> V_154 . V_160 [ V_5 ] -> V_145 ;
for ( V_245 = 0 ; V_245 < V_15 -> V_154 . V_161 [ V_5 ] ;
V_245 ++ , V_247 ++ ) {
T_2 V_248 = F_156 ( V_247 -> V_248 ) ;
if ( F_156 ( V_247 -> V_244 ) == V_244 ) {
V_246 = V_15 -> V_154 . V_159 [ V_5 ] -> V_145 +
F_156 ( V_247 -> V_249 ) ;
* V_243 = F_157 ( V_246 , V_248 , V_241 ) ;
if ( * V_243 == NULL )
goto V_209;
return 0 ;
}
}
}
F_4 ( V_15 -> V_20 , L_59 ,
V_244 ) ;
* V_243 = NULL ;
V_209:
return - V_250 ;
}
int F_158 ( struct V_14 * V_15 , T_11 * V_251 , T_2 V_244 )
{
int V_5 , V_245 ;
const T_5 * V_246 ;
struct V_163 * V_247 ;
for ( V_5 = 0 ; V_5 < V_15 -> V_154 . V_164 ; V_5 ++ ) {
V_247 = (struct V_163 * ) V_15 -> V_154 . V_160 [ V_5 ] -> V_145 ;
for ( V_245 = 0 ; V_245 < V_15 -> V_154 . V_161 [ V_5 ] ;
V_245 ++ , V_247 ++ ) {
if ( F_156 ( V_247 -> V_244 ) == V_244 ) {
V_246 = V_15 -> V_154 . V_159 [ V_5 ] -> V_145 +
F_156 ( V_247 -> V_249 ) ;
if ( F_156 ( V_247 -> V_248 ) != 4 ) {
F_4 ( V_15 -> V_20 ,
L_60 ) ;
return - V_252 ;
}
* V_251 = F_156 ( * ( ( V_253 * ) V_246 ) ) ;
return 0 ;
}
}
}
F_4 ( V_15 -> V_20 , L_61 , V_244 ) ;
return - V_252 ;
}
void F_159 ( void * V_254 )
{
F_82 ( V_254 ) ;
}
int F_160 ( struct V_14 * V_15 )
{
int V_5 ;
int V_245 ;
int V_255 = 0 ;
const struct V_256 * V_154 ;
const struct V_256 * V_160 ;
struct V_163 * V_257 ;
for ( V_5 = 0 ; V_5 < V_156 && V_255 == 0 ; V_5 ++ ) {
V_154 = V_15 -> V_154 . V_159 [ V_5 ] ;
V_160 = V_15 -> V_154 . V_160 [ V_5 ] ;
if ( V_154 == NULL && V_160 == NULL ) {
break;
} else if ( V_154 == NULL || V_160 == NULL ) {
F_4 ( V_15 -> V_20 , L_62 ,
V_28 ) ;
V_255 = - V_258 ;
} else if ( V_160 -> V_162 % sizeof( struct V_163 ) ) {
F_4 ( V_15 -> V_20 , L_63
L_64 , V_28 , V_160 -> V_162 ,
sizeof( struct V_163 ) ) ;
V_255 = - V_258 ;
} else if ( V_154 -> V_162 < V_259 || V_154 -> V_162 > V_260 ) {
F_4 ( V_15 -> V_20 , L_65
L_66 , V_28 , V_154 -> V_162 ) ;
V_255 = - V_258 ;
} else {
V_257 = (struct V_163 * ) V_160 -> V_145 ;
for ( V_245 = 0 ; V_245 < V_15 -> V_154 . V_161 [ V_5 ] &&
! V_255 ; V_245 ++ , V_257 ++ ) {
if ( F_156 ( V_257 -> V_249 ) +
F_156 ( V_257 -> V_248 ) >
V_154 -> V_162 ) {
F_4 ( V_15 -> V_20 ,
L_67 ,
V_28 ) ;
V_255 = - V_258 ;
}
}
}
}
if ( V_255 == 0 && V_15 -> V_154 . V_164 != V_5 ) {
F_4 ( V_15 -> V_20 , L_68 , V_28 ,
V_15 -> V_154 . V_164 ) ;
V_255 = - V_258 ;
}
return V_255 ;
}
bool F_10 ( struct V_14 * V_15 )
{
bool V_23 = F_54 ( V_15 -> V_22 ) ;
F_7 ( & V_15 -> V_17 ) ;
F_55 ( V_15 -> V_18 -> V_25 -> V_20 , V_23 ) ;
if ( V_23 )
F_161 ( V_15 -> V_18 -> V_25 -> V_20 ) ;
F_3 ( & V_15 -> V_17 ) ;
return V_23 ;
}
void F_162 ( struct V_14 * V_15 , T_10 V_238 )
{
F_7 ( & V_15 -> V_17 ) ;
F_163 ( V_238 ) ;
F_3 ( & V_15 -> V_17 ) ;
}
