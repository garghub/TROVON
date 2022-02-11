void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_5 -> V_11 ) ;
struct V_12 * V_13 = & V_10 -> V_14 ;
memset ( V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 -> V_15 . V_16 = V_17 ;
if ( V_3 )
V_13 -> V_18 . V_19 . V_20 . V_21 =
V_22 ;
else
V_13 -> V_18 . V_19 . V_20 . V_21 =
V_23 ;
F_4 ( V_7 -> V_24 , V_13 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_13 ,
V_25 , 0 ) ;
}
static struct V_9 * F_5 ( void )
{
struct V_9 * V_1 ;
V_1 = F_6 ( sizeof( struct V_9 ) , V_26 ) ;
if ( ! V_1 )
return NULL ;
F_7 ( & V_1 -> V_27 ) ;
V_1 -> V_28 = false ;
F_8 ( & V_1 -> V_29 , 0 ) ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_33 ;
F_9 ( & V_1 -> V_34 ) ;
F_7 ( & V_1 -> V_35 ) ;
F_10 ( & V_1 -> V_36 , V_37 ) ;
return V_1 ;
}
static void F_11 ( struct V_38 * V_39 )
{
struct V_9 * V_11
= F_12 ( V_39 , struct V_9 , V_40 ) ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ )
F_13 ( V_11 -> V_43 [ V_41 ] . V_44 . V_45 ) ;
F_14 ( V_11 ) ;
}
static void F_15 ( struct V_9 * V_11 )
{
F_16 ( & V_11 -> V_40 , F_11 ) ;
}
static void F_17 ( struct V_6 * V_46 )
{
struct V_12 * V_47 ;
struct V_1 * V_2 = F_18 ( V_46 ) ;
struct V_4 * V_48 = F_2 ( V_2 ) ;
struct V_9 * V_1 = F_3 ( V_48 -> V_11 ) ;
int V_49 ;
if ( V_1 -> V_50 ) {
V_47 = & V_1 -> V_47 ;
memset ( V_47 , 0 , sizeof( struct V_12 ) ) ;
V_47 -> V_15 . V_16 =
V_51 ;
V_47 -> V_18 . V_52 .
V_53 . V_54 = V_55 ;
V_49 = F_4 ( V_46 -> V_24 ,
V_47 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_47 ,
V_25 , 0 ) ;
if ( V_46 -> V_24 -> V_56 )
V_49 = 0 ;
if ( V_49 != 0 ) {
F_19 ( V_2 , L_1
L_2 ) ;
return;
}
V_1 -> V_50 = 0 ;
}
if ( V_1 -> V_57 ) {
V_49 = F_20 ( V_46 -> V_24 ,
V_1 -> V_57 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_3 ) ;
return;
}
V_1 -> V_57 = 0 ;
}
if ( V_1 -> V_58 ) {
F_13 ( V_1 -> V_58 ) ;
V_1 -> V_58 = NULL ;
}
if ( V_1 -> V_59 ) {
V_47 = & V_1 -> V_47 ;
memset ( V_47 , 0 , sizeof( struct V_12 ) ) ;
V_47 -> V_15 . V_16 =
V_60 ;
V_47 -> V_18 . V_52 . V_61 . V_54 =
V_62 ;
V_49 = F_4 ( V_46 -> V_24 ,
V_47 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_47 ,
V_25 , 0 ) ;
if ( V_46 -> V_24 -> V_56 )
V_49 = 0 ;
if ( V_49 != 0 ) {
F_19 ( V_2 , L_1
L_4 ) ;
return;
}
V_1 -> V_59 = 0 ;
}
if ( V_1 -> V_63 ) {
V_49 = F_20 ( V_46 -> V_24 ,
V_1 -> V_63 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_5 ) ;
return;
}
V_1 -> V_63 = 0 ;
}
if ( V_1 -> V_64 ) {
F_13 ( V_1 -> V_64 ) ;
V_1 -> V_64 = NULL ;
}
F_14 ( V_1 -> V_65 ) ;
}
int F_21 ( struct V_9 * V_1 , T_1 V_66 )
{
struct V_67 * V_68 = & V_1 -> V_43 [ V_66 ] ;
int V_69 = F_22 ( V_68 -> V_24 -> V_70 ) ;
T_2 V_71 ;
V_71 = V_1 -> V_72 * sizeof( struct V_73 ) ;
V_68 -> V_44 . V_45 = F_23 ( V_71 , V_69 ) ;
if ( ! V_68 -> V_44 . V_45 )
V_68 -> V_44 . V_45 = F_24 ( V_71 ) ;
return V_68 -> V_44 . V_45 ? 0 : - V_74 ;
}
static int F_25 ( struct V_6 * V_46 ,
struct V_9 * V_1 ,
const struct V_75 * V_76 )
{
struct V_77 * V_78 ;
struct V_1 * V_2 = F_18 ( V_46 ) ;
struct V_12 * V_79 ;
unsigned int V_80 ;
T_2 V_81 ;
int V_49 = 0 ;
V_80 = V_76 -> V_82 * V_76 -> V_83 ;
V_80 = F_26 ( V_80 , V_84 ) ;
V_1 -> V_58 = F_24 ( V_80 ) ;
if ( ! V_1 -> V_58 ) {
F_19 ( V_2 ,
L_6 ,
V_80 ) ;
V_49 = - V_74 ;
goto V_85;
}
V_49 = F_27 ( V_46 -> V_24 , V_1 -> V_58 ,
V_80 ,
& V_1 -> V_57 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_7 ) ;
goto V_85;
}
V_79 = & V_1 -> V_14 ;
memset ( V_79 , 0 , sizeof( struct V_12 ) ) ;
V_79 -> V_15 . V_16 = V_86 ;
V_79 -> V_18 . V_52 . V_87 .
V_88 = V_1 -> V_57 ;
V_79 -> V_18 . V_52 .
V_87 . V_54 = V_55 ;
V_49 = F_4 ( V_46 -> V_24 , V_79 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_79 ,
V_25 ,
V_89 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_8 ) ;
goto V_85;
}
F_28 ( & V_1 -> V_34 ) ;
V_78 = & V_79 -> V_18 . V_52 . V_90 ;
if ( V_78 -> V_91 != V_92 ) {
F_19 ( V_2 ,
L_9 ,
V_78 -> V_91 ) ;
V_49 = - V_93 ;
goto V_85;
}
F_29 ( V_2 , L_10 ,
V_78 -> V_94 , V_78 -> V_95 [ 0 ] . V_96 ,
V_78 -> V_95 [ 0 ] . V_97 ) ;
if ( V_78 -> V_94 != 1 || V_78 -> V_95 [ 0 ] . V_98 != 0 ) {
V_49 = - V_93 ;
goto V_85;
}
V_1 -> V_83 = V_78 -> V_95 [ 0 ] . V_96 ;
V_1 -> V_50 = V_78 -> V_95 [ 0 ] . V_97 ;
V_1 -> V_72
= F_30 ( V_1 -> V_50 + 1 ,
V_84 / sizeof( V_99 ) ) ;
V_49 = F_21 ( V_1 , 0 ) ;
if ( V_49 )
goto V_85;
V_80 = V_76 -> V_100 * V_76 -> V_101 ;
V_80 = F_30 ( V_80 , V_84 ) ;
V_1 -> V_64 = F_24 ( V_80 ) ;
if ( ! V_1 -> V_64 ) {
F_19 ( V_2 , L_11 ,
V_80 ) ;
V_49 = - V_74 ;
goto V_85;
}
V_49 = F_27 ( V_46 -> V_24 , V_1 -> V_64 ,
V_80 ,
& V_1 -> V_63 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_12 ) ;
goto V_85;
}
V_79 = & V_1 -> V_14 ;
memset ( V_79 , 0 , sizeof( struct V_12 ) ) ;
V_79 -> V_15 . V_16 = V_102 ;
V_79 -> V_18 . V_52 . V_103 . V_88 =
V_1 -> V_63 ;
V_79 -> V_18 . V_52 . V_103 . V_54 = V_62 ;
V_49 = F_4 ( V_46 -> V_24 , V_79 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_79 ,
V_25 ,
V_89 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_13 ) ;
goto V_85;
}
F_28 ( & V_1 -> V_34 ) ;
if ( V_79 -> V_18 . V_52 .
V_104 . V_91 != V_92 ) {
F_19 ( V_2 , L_14
L_15 ,
V_79 -> V_18 . V_52 .
V_104 . V_91 ) ;
V_49 = - V_93 ;
goto V_85;
}
V_1 -> V_101 = V_79 -> V_18 .
V_52 . V_104 . V_105 ;
V_1 -> V_59 = V_80 / V_1 -> V_101 ;
F_29 ( V_2 , L_16 ,
V_1 -> V_101 , V_1 -> V_59 ) ;
V_81 = F_31 ( V_1 -> V_59 , V_106 ) ;
V_1 -> V_65 = F_32 ( V_81 , sizeof( V_107 ) , V_26 ) ;
if ( V_1 -> V_65 == NULL ) {
V_49 = - V_74 ;
goto V_85;
}
goto exit;
V_85:
F_17 ( V_46 ) ;
exit:
return V_49 ;
}
static int F_33 ( struct V_6 * V_46 ,
struct V_9 * V_1 ,
struct V_12 * V_79 ,
T_1 V_108 )
{
struct V_1 * V_2 = F_18 ( V_46 ) ;
int V_49 ;
memset ( V_79 , 0 , sizeof( struct V_12 ) ) ;
V_79 -> V_15 . V_16 = V_109 ;
V_79 -> V_18 . V_110 . V_111 . V_112 = V_108 ;
V_79 -> V_18 . V_110 . V_111 . V_113 = V_108 ;
V_49 = F_4 ( V_46 -> V_24 , V_79 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_79 ,
V_25 ,
V_89 ) ;
if ( V_49 != 0 )
return V_49 ;
F_28 ( & V_1 -> V_34 ) ;
if ( V_79 -> V_18 . V_110 . V_114 . V_91 !=
V_92 )
return - V_93 ;
if ( V_108 == V_115 )
return 0 ;
memset ( V_79 , 0 , sizeof( struct V_12 ) ) ;
V_79 -> V_15 . V_16 = V_116 ;
V_79 -> V_18 . V_117 . V_118 . V_119 = V_2 -> V_119 + V_120 ;
V_79 -> V_18 . V_117 . V_118 . V_121 . V_122 = 1 ;
if ( V_108 >= V_123 ) {
V_79 -> V_18 . V_117 . V_118 . V_121 . V_124 = 1 ;
V_79 -> V_18 . V_117 . V_118 . V_121 . V_125 = 1 ;
}
V_49 = F_4 ( V_46 -> V_24 , V_79 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_79 ,
V_25 , 0 ) ;
return V_49 ;
}
static int F_34 ( struct V_6 * V_46 ,
struct V_9 * V_1 ,
const struct V_75 * V_76 )
{
const T_1 V_126 [] = {
V_115 , V_127 ,
V_128 , V_123
} ;
struct V_12 * V_79 ;
int V_129 , V_41 , V_49 ;
V_79 = & V_1 -> V_14 ;
for ( V_41 = F_35 ( V_126 ) - 1 ; V_41 >= 0 ; V_41 -- )
if ( F_33 ( V_46 , V_1 , V_79 ,
V_126 [ V_41 ] ) == 0 ) {
V_1 -> V_130 = V_126 [ V_41 ] ;
break;
}
if ( V_41 < 0 ) {
V_49 = - V_131 ;
goto V_85;
}
F_36 ( L_17 , V_1 -> V_130 ) ;
memset ( V_79 , 0 , sizeof( struct V_12 ) ) ;
if ( V_1 -> V_130 <= V_128 )
V_129 = 0x00060001 ;
else
V_129 = 0x0006001e ;
V_79 -> V_15 . V_16 = V_132 ;
V_79 -> V_18 . V_52 .
V_133 . V_134 =
( V_129 & 0xFFFF0000 ) >> 16 ;
V_79 -> V_18 . V_52 .
V_133 . V_135 =
V_129 & 0xFFFF ;
V_49 = F_4 ( V_46 -> V_24 , V_79 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_79 ,
V_25 , 0 ) ;
if ( V_49 != 0 )
goto V_85;
V_49 = F_25 ( V_46 , V_1 , V_76 ) ;
V_85:
return V_49 ;
}
static void F_37 ( struct V_6 * V_46 )
{
F_17 ( V_46 ) ;
}
void F_38 ( struct V_6 * V_46 )
{
struct V_1 * V_2 = F_18 ( V_46 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1
= F_3 ( V_5 -> V_11 ) ;
int V_41 ;
F_39 ( & V_1 -> V_36 ) ;
F_37 ( V_46 ) ;
F_40 ( V_5 -> V_11 , NULL ) ;
F_29 ( V_2 , L_18 ) ;
F_41 ( V_46 -> V_24 ) ;
for ( V_41 = 0 ; V_41 < V_1 -> V_136 ; V_41 ++ )
F_42 ( & V_1 -> V_43 [ V_41 ] . V_137 ) ;
F_15 ( V_1 ) ;
}
static inline T_1 F_43 (
struct V_138 * V_139 )
{
T_1 V_140 , V_141 ;
F_44 ( V_139 , & V_140 , & V_141 ) ;
return V_141 * 100 / V_139 -> V_142 ;
}
static inline void F_45 ( struct V_9 * V_1 ,
T_1 V_143 )
{
F_46 ( V_143 , V_1 -> V_65 ) ;
}
static void F_47 ( struct V_9 * V_1 ,
struct V_144 * V_145 ,
struct V_6 * V_46 ,
const struct V_146 * V_147 ,
int V_148 )
{
struct V_149 * V_150 = (struct V_149 * ) ( unsigned long ) V_147 -> V_151 ;
struct V_1 * V_2 = F_18 ( V_46 ) ;
struct V_144 * V_24 = V_46 -> V_24 ;
T_3 V_66 = 0 ;
int V_152 ;
if ( F_48 ( V_150 ) ) {
const struct V_153 * V_154
= (struct V_153 * ) V_150 -> V_155 ;
T_1 V_156 = V_154 -> V_157 ;
struct V_158 * V_159 ;
if ( V_156 != V_160 )
F_45 ( V_1 , V_156 ) ;
V_66 = V_154 -> V_66 ;
V_24 = V_145 ;
V_159 = & V_1 -> V_43 [ V_66 ] . V_159 ;
F_49 ( & V_159 -> V_161 ) ;
V_159 -> V_162 += V_154 -> V_163 ;
V_159 -> V_164 += V_154 -> V_165 ;
F_50 ( & V_159 -> V_161 ) ;
F_51 ( V_150 , V_148 ) ;
}
V_152 =
F_52 ( & V_1 -> V_43 [ V_66 ] . V_152 ) ;
if ( V_1 -> V_28 && V_152 == 0 )
F_53 ( & V_1 -> V_27 ) ;
if ( F_54 ( F_55 ( V_2 , V_66 ) ) &&
( F_43 ( & V_24 -> V_166 ) > V_167 ||
V_152 < 1 ) )
F_56 ( F_55 ( V_2 , V_66 ) ) ;
}
static void F_57 ( struct V_9 * V_1 ,
struct V_144 * V_145 ,
struct V_6 * V_46 ,
const struct V_146 * V_147 ,
int V_148 )
{
struct V_12 * V_168 = F_58 ( V_147 ) ;
struct V_1 * V_2 = F_18 ( V_46 ) ;
switch ( V_168 -> V_15 . V_16 ) {
case V_169 :
case V_170 :
case V_171 :
case V_172 :
memcpy ( & V_1 -> V_14 , V_168 ,
sizeof( struct V_12 ) ) ;
F_59 ( & V_1 -> V_34 ) ;
break;
case V_173 :
F_47 ( V_1 , V_145 ,
V_46 , V_147 , V_148 ) ;
break;
default:
F_19 ( V_2 ,
L_19 ,
V_168 -> V_15 . V_16 ) ;
}
}
static T_1 F_60 ( struct V_9 * V_1 )
{
unsigned long * V_174 = V_1 -> V_65 ;
unsigned int V_41 ;
F_61 (i, map_addr, net_device->send_section_cnt) {
if ( F_62 ( V_41 , V_174 ) == 0 )
return V_41 ;
}
return V_160 ;
}
static T_1 F_63 ( struct V_9 * V_1 ,
unsigned int V_175 ,
T_1 V_176 ,
struct V_153 * V_154 ,
struct V_177 * V_178 ,
struct V_179 * V_180 ,
struct V_149 * V_150 )
{
char * V_181 = V_1 -> V_64 ;
char * V_182 = V_181 + ( V_175 * V_1 -> V_101 )
+ V_176 ;
int V_41 ;
T_1 V_183 = 0 ;
T_1 V_184 = 0 ;
T_1 V_185 = V_154 -> V_186 % V_1 -> V_32 ;
T_1 V_187 = V_154 -> V_188 ? V_154 -> V_189 :
V_154 -> V_190 ;
if ( V_150 -> V_191 && V_185 && ! V_154 -> V_188 ) {
V_184 = V_1 -> V_32 - V_185 ;
V_178 -> V_192 += V_184 ;
V_154 -> V_186 += V_184 ;
}
for ( V_41 = 0 ; V_41 < V_187 ; V_41 ++ ) {
char * V_193 = F_64 ( V_180 [ V_41 ] . V_194 << V_195 ) ;
T_1 V_98 = V_180 [ V_41 ] . V_98 ;
T_1 V_196 = V_180 [ V_41 ] . V_196 ;
memcpy ( V_182 , ( V_193 + V_98 ) , V_196 ) ;
V_183 += V_196 ;
V_182 += V_196 ;
}
if ( V_184 ) {
memset ( V_182 , 0 , V_184 ) ;
V_183 += V_184 ;
}
return V_183 ;
}
static inline int F_65 (
struct V_6 * V_46 ,
struct V_153 * V_154 ,
struct V_9 * V_1 ,
struct V_179 * V_180 ,
struct V_149 * V_150 )
{
struct V_12 V_197 ;
struct V_198 * const V_199 =
& V_197 . V_18 . V_52 . V_200 ;
struct V_67 * const V_68 =
& V_1 -> V_43 [ V_154 -> V_66 ] ;
struct V_144 * V_201 = V_68 -> V_24 ;
struct V_1 * V_2 = F_18 ( V_46 ) ;
struct V_202 * V_203 = F_55 ( V_2 , V_154 -> V_66 ) ;
V_99 V_204 ;
int V_49 ;
T_1 V_205 = F_43 ( & V_201 -> V_166 ) ;
V_197 . V_15 . V_16 = V_206 ;
if ( V_150 )
V_199 -> V_207 = 0 ;
else
V_199 -> V_207 = 1 ;
V_199 -> V_208 = V_154 -> V_157 ;
if ( V_154 -> V_157 == V_160 )
V_199 -> V_209 = 0 ;
else
V_199 -> V_209 = V_154 -> V_186 ;
V_204 = ( V_107 ) V_150 ;
if ( V_201 -> V_56 )
return - V_210 ;
if ( V_154 -> V_190 ) {
if ( V_154 -> V_188 )
V_180 += V_154 -> V_189 ;
V_49 = F_66 ( V_201 ,
V_180 , V_154 -> V_190 ,
& V_197 , sizeof( V_197 ) ,
V_204 ) ;
} else {
V_49 = F_4 ( V_201 ,
& V_197 , sizeof( V_197 ) ,
V_204 , V_25 ,
V_89 ) ;
}
if ( V_49 == 0 ) {
F_67 ( & V_68 -> V_152 ) ;
if ( V_205 < V_211 )
F_68 ( V_203 ) ;
} else if ( V_49 == - V_212 ) {
F_68 ( V_203 ) ;
if ( F_69 ( & V_68 -> V_152 ) < 1 ) {
F_56 ( V_203 ) ;
V_49 = - V_213 ;
}
} else {
F_19 ( V_2 ,
L_20 ,
V_154 -> V_190 , V_154 -> V_186 ,
V_49 ) ;
}
return V_49 ;
}
static inline void F_70 ( struct V_153 * * V_214 ,
struct V_149 * * V_215 ,
struct V_216 * V_217 )
{
* V_215 = V_217 -> V_150 ;
* V_214 = V_217 -> V_218 ;
V_217 -> V_150 = NULL ;
V_217 -> V_218 = NULL ;
V_217 -> V_219 = 0 ;
}
int F_71 ( struct V_4 * V_220 ,
struct V_153 * V_154 ,
struct V_177 * V_178 ,
struct V_179 * V_180 ,
struct V_149 * V_150 )
{
struct V_9 * V_1
= F_72 ( V_220 -> V_11 ) ;
struct V_6 * V_46 = V_220 -> V_8 ;
int V_49 = 0 ;
struct V_67 * V_68 ;
T_1 V_221 = V_154 -> V_186 , V_222 = 0 ;
unsigned int V_175 = V_160 ;
struct V_216 * V_217 ;
struct V_153 * V_214 = NULL , * V_223 = NULL ;
struct V_149 * V_215 = NULL ;
bool V_224 ;
bool V_191 = ( V_150 != NULL ) ? V_150 -> V_191 : false ;
if ( F_73 ( ! V_1 || V_1 -> V_28 ) )
return - V_210 ;
if ( F_73 ( ! V_1 -> V_65 ) )
return - V_212 ;
V_68 = & V_1 -> V_43 [ V_154 -> V_66 ] ;
V_154 -> V_157 = V_160 ;
V_154 -> V_188 = false ;
if ( ! V_150 ) {
V_223 = V_154 ;
goto V_225;
}
V_217 = & V_68 -> V_226 ;
if ( V_217 -> V_218 )
V_222 = V_217 -> V_218 -> V_186 ;
V_224 = V_222 > 0 && V_217 -> V_219 < V_1 -> V_30 ;
if ( V_224 && V_222 + V_221 + V_1 -> V_32 <
V_1 -> V_101 ) {
V_175 = V_217 -> V_218 -> V_157 ;
} else if ( V_224 && V_222 + V_154 -> V_227 <
V_1 -> V_101 ) {
V_175 = V_217 -> V_218 -> V_157 ;
V_154 -> V_188 = true ;
} else if ( V_221 + V_1 -> V_32 <
V_1 -> V_101 ) {
V_175 = F_60 ( V_1 ) ;
if ( F_73 ( V_175 == V_160 ) ) {
++ V_220 -> V_228 . V_229 ;
} else {
F_70 ( & V_214 , & V_215 , V_217 ) ;
V_222 = 0 ;
}
}
if ( V_175 != V_160 ) {
F_63 ( V_1 ,
V_175 , V_222 ,
V_154 , V_178 , V_180 , V_150 ) ;
V_154 -> V_157 = V_175 ;
if ( V_154 -> V_188 ) {
V_154 -> V_190 -= V_154 -> V_189 ;
V_154 -> V_186 = V_222 + V_154 -> V_227 ;
} else {
V_154 -> V_190 = 0 ;
V_154 -> V_186 += V_222 ;
}
if ( V_217 -> V_218 ) {
V_154 -> V_163 += V_217 -> V_218 -> V_163 ;
V_154 -> V_165 += V_217 -> V_218 -> V_165 ;
}
if ( V_217 -> V_150 )
F_74 ( V_217 -> V_150 ) ;
if ( V_191 && ! V_154 -> V_188 ) {
V_217 -> V_150 = V_150 ;
V_217 -> V_218 = V_154 ;
V_217 -> V_219 ++ ;
} else {
V_223 = V_154 ;
V_217 -> V_150 = NULL ;
V_217 -> V_218 = NULL ;
V_217 -> V_219 = 0 ;
}
} else {
F_70 ( & V_214 , & V_215 , V_217 ) ;
V_223 = V_154 ;
}
if ( V_214 ) {
int V_230 = F_65 ( V_46 , V_214 , V_1 ,
NULL , V_215 ) ;
if ( V_230 != 0 ) {
F_45 ( V_1 ,
V_214 -> V_157 ) ;
F_75 ( V_215 ) ;
}
}
V_225:
if ( V_223 )
V_49 = F_65 ( V_46 , V_223 , V_1 , V_180 , V_150 ) ;
if ( V_49 != 0 && V_175 != V_160 )
F_45 ( V_1 , V_175 ) ;
return V_49 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_9 * V_11 ,
struct V_67 * V_68 )
{
struct V_231 * V_44 = & V_68 -> V_44 ;
struct V_232 {
struct V_233 V_15 ;
T_1 V_91 ;
} V_234 ;
struct V_232 V_18 = {
. V_15 . V_16 = V_173 ,
} ;
int V_49 ;
while ( V_44 -> V_235 != V_44 -> V_236 ) {
const struct V_73 * V_237
= V_44 -> V_45 + V_44 -> V_235 ;
V_18 . V_91 = V_237 -> V_91 ;
V_49 = F_4 ( V_68 -> V_24 , & V_18 , sizeof( V_18 ) ,
V_237 -> V_238 , V_239 , 0 ) ;
if ( F_73 ( V_49 ) ) {
struct V_4 * V_220 = F_2 ( V_2 ) ;
++ V_220 -> V_228 . V_240 ;
return V_49 ;
}
if ( ++ V_44 -> V_235 == V_11 -> V_72 )
V_44 -> V_235 = 0 ;
}
if ( F_73 ( V_11 -> V_28 ) )
F_53 ( & V_11 -> V_27 ) ;
return 0 ;
}
static void F_77 ( const struct V_9 * V_11 ,
const struct V_231 * V_44 ,
T_1 * V_241 , T_1 * V_242 )
{
T_1 V_219 = V_11 -> V_72 ;
if ( V_44 -> V_236 >= V_44 -> V_235 )
* V_241 = V_44 -> V_236 - V_44 -> V_235 ;
else
* V_241 = ( V_219 - V_44 -> V_235 ) + V_44 -> V_236 ;
* V_242 = V_219 - * V_241 - 1 ;
}
static void F_78 ( struct V_1 * V_2 ,
struct V_9 * V_11 , T_3 V_66 ,
V_99 V_238 , T_1 V_91 )
{
struct V_67 * V_68 = & V_11 -> V_43 [ V_66 ] ;
struct V_231 * V_44 = & V_68 -> V_44 ;
struct V_73 * V_237 ;
T_1 V_241 , V_242 ;
F_77 ( V_11 , V_44 , & V_241 , & V_242 ) ;
if ( F_73 ( V_241 > V_243 ) ) {
F_76 ( V_2 , V_11 , V_68 ) ;
F_77 ( V_11 , V_44 , & V_241 , & V_242 ) ;
}
if ( F_73 ( ! V_242 ) ) {
F_19 ( V_2 , L_21 ,
V_66 , V_238 ) ;
return;
}
V_237 = V_44 -> V_45 + V_44 -> V_236 ;
V_237 -> V_238 = V_238 ;
V_237 -> V_91 = V_91 ;
if ( ++ V_44 -> V_236 == V_11 -> V_72 )
V_44 -> V_236 = 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_9 * V_1 ,
struct V_4 * V_5 ,
struct V_6 * V_46 ,
struct V_144 * V_24 ,
const struct V_146 * V_147 ,
struct V_12 * V_244 )
{
const struct V_245 * V_246
= F_12 ( V_147 , const struct V_245 , V_247 ) ;
T_3 V_66 = V_24 -> V_248 . V_249 . V_250 ;
char * V_58 = V_1 -> V_58 ;
T_1 V_91 = V_92 ;
int V_41 ;
int V_219 = 0 ;
if ( F_73 ( V_244 -> V_15 . V_16 != V_206 ) ) {
F_80 ( V_5 , V_251 , V_2 ,
L_22 ,
V_244 -> V_15 . V_16 ) ;
return 0 ;
}
if ( F_73 ( V_246 -> V_252 != V_55 ) ) {
F_80 ( V_5 , V_251 , V_2 ,
L_23 ,
V_55 ,
V_246 -> V_252 ) ;
return 0 ;
}
V_219 = V_246 -> V_253 ;
for ( V_41 = 0 ; V_41 < V_219 ; V_41 ++ ) {
void * V_254 = V_58
+ V_246 -> V_255 [ V_41 ] . V_256 ;
T_1 V_257 = V_246 -> V_255 [ V_41 ] . V_258 ;
V_91 = F_81 ( V_2 , V_1 , V_46 ,
V_24 , V_254 , V_257 ) ;
}
F_78 ( V_2 , V_1 , V_66 ,
V_246 -> V_247 . V_151 , V_91 ) ;
return V_219 ;
}
static void F_82 ( struct V_6 * V_259 ,
struct V_12 * V_197 )
{
struct V_1 * V_2 = F_18 ( V_259 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_41 ;
T_1 V_219 , * V_260 ;
V_219 = V_197 -> V_18 . V_261 . V_262 . V_219 ;
if ( V_219 != V_263 ) {
F_19 ( V_2 , L_24 , V_219 ) ;
return;
}
V_260 = ( T_1 * ) ( ( unsigned long ) & V_197 -> V_18 . V_261 . V_262 +
V_197 -> V_18 . V_261 . V_262 . V_98 ) ;
for ( V_41 = 0 ; V_41 < V_219 ; V_41 ++ )
V_5 -> V_264 [ V_41 ] = V_260 [ V_41 ] ;
}
static void F_83 ( struct V_4 * V_5 ,
struct V_12 * V_197 )
{
V_5 -> V_265 = V_197 -> V_18 . V_19 . V_266 . V_267 ;
V_5 -> V_268 = V_197 -> V_18 . V_19 . V_266 . V_269 ;
}
static inline void F_84 ( struct V_6 * V_259 ,
struct V_4 * V_5 ,
struct V_12 * V_197 )
{
switch ( V_197 -> V_15 . V_16 ) {
case V_270 :
F_82 ( V_259 , V_197 ) ;
break;
case V_271 :
F_83 ( V_5 , V_197 ) ;
break;
}
}
static int F_85 ( struct V_6 * V_46 ,
struct V_144 * V_24 ,
struct V_9 * V_1 ,
struct V_1 * V_2 ,
const struct V_146 * V_147 ,
int V_148 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_12 * V_197 = F_58 ( V_147 ) ;
switch ( V_147 -> type ) {
case V_239 :
F_57 ( V_1 , V_24 , V_46 ,
V_147 , V_148 ) ;
break;
case V_272 :
return F_79 ( V_2 , V_1 , V_5 ,
V_46 , V_24 , V_147 , V_197 ) ;
break;
case V_25 :
F_84 ( V_46 , V_5 , V_197 ) ;
break;
default:
F_19 ( V_2 , L_25 ,
V_147 -> type , V_147 -> V_151 ) ;
break;
}
return 0 ;
}
static struct V_6 * F_86 ( struct V_144 * V_24 )
{
struct V_144 * V_273 = V_24 -> V_274 ;
return V_273 ? V_273 -> V_275 : V_24 -> V_275 ;
}
int F_87 ( struct V_276 * V_137 , int V_148 )
{
struct V_67 * V_68
= F_12 ( V_137 , struct V_67 , V_137 ) ;
struct V_9 * V_1 = V_68 -> V_1 ;
struct V_144 * V_24 = V_68 -> V_24 ;
struct V_6 * V_46 = F_86 ( V_24 ) ;
struct V_1 * V_2 = F_18 ( V_46 ) ;
int V_277 = 0 ;
if ( ! V_68 -> V_147 )
V_68 -> V_147 = F_88 ( V_24 ) ;
while ( V_68 -> V_147 && V_277 < V_148 ) {
V_277 += F_85 ( V_46 , V_24 , V_1 ,
V_2 , V_68 -> V_147 , V_148 ) ;
V_68 -> V_147 = F_89 ( V_24 , V_68 -> V_147 ) ;
}
if ( F_76 ( V_2 , V_1 , V_68 ) == 0 &&
V_277 < V_148 &&
F_90 ( V_137 , V_277 ) &&
F_91 ( & V_24 -> V_278 ) ) {
F_92 ( & V_24 -> V_278 ) ;
F_93 ( V_137 ) ;
}
return F_94 ( V_277 , V_148 ) ;
}
void F_95 ( void * V_279 )
{
struct V_67 * V_68 = V_279 ;
struct V_144 * V_24 = V_68 -> V_24 ;
struct V_138 * V_280 = & V_24 -> V_278 ;
F_96 ( F_97 ( V_280 ) + V_280 -> V_281 ) ;
if ( F_98 ( & V_68 -> V_137 ) ) {
F_92 ( V_280 ) ;
F_99 ( & V_68 -> V_137 ) ;
}
}
struct V_9 * F_100 ( struct V_6 * V_46 ,
const struct V_75 * V_76 )
{
int V_41 , V_49 = 0 ;
int V_282 = V_76 -> V_282 ;
struct V_9 * V_1 ;
struct V_1 * V_2 = F_18 ( V_46 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_1 = F_5 () ;
if ( ! V_1 )
return F_101 ( - V_74 ) ;
V_1 -> V_282 = V_282 ;
F_102 ( V_46 -> V_24 , V_283 ) ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
struct V_67 * V_68 = & V_1 -> V_43 [ V_41 ] ;
V_68 -> V_24 = V_46 -> V_24 ;
V_68 -> V_1 = V_1 ;
F_103 ( & V_68 -> V_159 . V_161 ) ;
F_103 ( & V_68 -> V_284 . V_161 ) ;
}
F_104 ( V_2 , & V_1 -> V_43 [ 0 ] . V_137 ,
F_87 , V_243 ) ;
V_49 = F_105 ( V_46 -> V_24 , V_282 * V_84 ,
V_282 * V_84 , NULL , 0 ,
F_95 ,
V_1 -> V_43 ) ;
if ( V_49 != 0 ) {
F_42 ( & V_1 -> V_43 [ 0 ] . V_137 ) ;
F_19 ( V_2 , L_26 , V_49 ) ;
goto V_85;
}
F_29 ( V_2 , L_27 ) ;
F_106 ( & V_1 -> V_43 [ 0 ] . V_137 ) ;
F_107 ( V_5 -> V_11 , V_1 ) ;
V_49 = F_34 ( V_46 , V_1 , V_76 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_28 , V_49 ) ;
goto V_285;
}
return V_1 ;
V_285:
F_40 ( V_5 -> V_11 , NULL ) ;
F_108 ( & V_1 -> V_43 [ 0 ] . V_137 ) ;
F_41 ( V_46 -> V_24 ) ;
V_85:
F_11 ( & V_1 -> V_40 ) ;
return F_101 ( V_49 ) ;
}
