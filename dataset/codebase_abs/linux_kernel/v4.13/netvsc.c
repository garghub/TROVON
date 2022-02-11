void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_12 * V_13 = & V_10 -> V_14 ;
memset ( V_13 , 0 , sizeof( struct V_12 ) ) ;
V_13 -> V_15 . V_16 = V_17 ;
if ( V_3 )
V_13 -> V_18 . V_19 . V_20 . V_21 =
V_22 ;
else
V_13 -> V_18 . V_19 . V_20 . V_21 =
V_23 ;
F_3 ( V_7 -> V_24 , V_13 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_13 ,
V_25 , 0 ) ;
V_5 -> V_26 = V_3 ;
}
static struct V_9 * F_4 ( void )
{
struct V_9 * V_1 ;
V_1 = F_5 ( sizeof( struct V_9 ) , V_27 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_28 [ 0 ] . V_29 . V_30
= F_6 ( V_31 * sizeof( struct V_32 ) ) ;
F_7 ( & V_1 -> V_33 ) ;
V_1 -> V_34 = false ;
F_8 ( & V_1 -> V_35 , 0 ) ;
V_1 -> V_36 = V_37 ;
V_1 -> V_38 = V_39 ;
F_9 ( & V_1 -> V_40 ) ;
F_7 ( & V_1 -> V_41 ) ;
return V_1 ;
}
static void F_10 ( struct V_42 * V_43 )
{
struct V_9 * V_11
= F_11 ( V_43 , struct V_9 , V_44 ) ;
int V_45 ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ )
F_12 ( V_11 -> V_28 [ V_45 ] . V_29 . V_30 ) ;
F_13 ( V_11 ) ;
}
static void F_14 ( struct V_9 * V_11 )
{
F_15 ( & V_11 -> V_44 , F_10 ) ;
}
static void F_16 ( struct V_6 * V_47 )
{
struct V_12 * V_48 ;
struct V_1 * V_2 = F_17 ( V_47 ) ;
struct V_9 * V_1 = F_18 ( V_2 ) ;
int V_49 ;
if ( V_1 -> V_50 ) {
V_48 = & V_1 -> V_48 ;
memset ( V_48 , 0 , sizeof( struct V_12 ) ) ;
V_48 -> V_15 . V_16 =
V_51 ;
V_48 -> V_18 . V_52 .
V_53 . V_54 = V_55 ;
V_49 = F_3 ( V_47 -> V_24 ,
V_48 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_48 ,
V_25 , 0 ) ;
if ( V_47 -> V_24 -> V_56 )
V_49 = 0 ;
if ( V_49 != 0 ) {
F_19 ( V_2 , L_1
L_2 ) ;
return;
}
}
if ( V_1 -> V_57 ) {
V_49 = F_20 ( V_47 -> V_24 ,
V_1 -> V_57 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_3 ) ;
return;
}
V_1 -> V_57 = 0 ;
}
if ( V_1 -> V_58 ) {
F_12 ( V_1 -> V_58 ) ;
V_1 -> V_58 = NULL ;
}
if ( V_1 -> V_59 ) {
V_1 -> V_50 = 0 ;
F_13 ( V_1 -> V_59 ) ;
V_1 -> V_59 = NULL ;
}
if ( V_1 -> V_60 ) {
V_48 = & V_1 -> V_48 ;
memset ( V_48 , 0 , sizeof( struct V_12 ) ) ;
V_48 -> V_15 . V_16 =
V_61 ;
V_48 -> V_18 . V_52 . V_62 . V_54 =
V_63 ;
V_49 = F_3 ( V_47 -> V_24 ,
V_48 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_48 ,
V_25 , 0 ) ;
if ( V_47 -> V_24 -> V_56 )
V_49 = 0 ;
if ( V_49 != 0 ) {
F_19 ( V_2 , L_1
L_4 ) ;
return;
}
}
if ( V_1 -> V_64 ) {
V_49 = F_20 ( V_47 -> V_24 ,
V_1 -> V_64 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_5 ) ;
return;
}
V_1 -> V_64 = 0 ;
}
if ( V_1 -> V_65 ) {
F_12 ( V_1 -> V_65 ) ;
V_1 -> V_65 = NULL ;
}
F_13 ( V_1 -> V_66 ) ;
}
static int F_21 ( struct V_6 * V_47 ,
struct V_9 * V_1 )
{
int V_49 = 0 ;
struct V_12 * V_67 ;
struct V_1 * V_2 ;
T_1 V_68 ;
int V_69 ;
V_2 = F_17 ( V_47 ) ;
V_69 = F_22 ( V_47 -> V_24 -> V_70 ) ;
V_1 -> V_58 = F_23 ( V_1 -> V_71 , V_69 ) ;
if ( ! V_1 -> V_58 )
V_1 -> V_58 = F_6 ( V_1 -> V_71 ) ;
if ( ! V_1 -> V_58 ) {
F_19 ( V_2 , L_6
L_7 , V_1 -> V_71 ) ;
V_49 = - V_72 ;
goto V_73;
}
V_49 = F_24 ( V_47 -> V_24 , V_1 -> V_58 ,
V_1 -> V_71 ,
& V_1 -> V_57 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_8 ) ;
goto V_73;
}
V_67 = & V_1 -> V_14 ;
memset ( V_67 , 0 , sizeof( struct V_12 ) ) ;
V_67 -> V_15 . V_16 = V_74 ;
V_67 -> V_18 . V_52 . V_75 .
V_76 = V_1 -> V_57 ;
V_67 -> V_18 . V_52 .
V_75 . V_54 = V_55 ;
V_49 = F_3 ( V_47 -> V_24 , V_67 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_67 ,
V_25 ,
V_77 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_9 ) ;
goto V_73;
}
F_25 ( & V_1 -> V_40 ) ;
if ( V_67 -> V_18 . V_52 .
V_78 . V_79 != V_80 ) {
F_19 ( V_2 , L_10
L_11 ,
V_67 -> V_18 . V_52 .
V_78 . V_79 ) ;
V_49 = - V_81 ;
goto V_73;
}
V_1 -> V_50 = V_67 -> V_18 .
V_52 . V_78 . V_82 ;
V_1 -> V_59 = F_26 (
V_67 -> V_18 . V_52 . V_78 . V_83 ,
V_1 -> V_50 *
sizeof( struct V_84 ) ,
V_27 ) ;
if ( V_1 -> V_59 == NULL ) {
V_49 = - V_81 ;
goto V_73;
}
if ( V_1 -> V_50 != 1 ||
V_1 -> V_59 -> V_85 != 0 ) {
V_49 = - V_81 ;
goto V_73;
}
V_1 -> V_65 = F_23 ( V_1 -> V_86 , V_69 ) ;
if ( ! V_1 -> V_65 )
V_1 -> V_65 = F_6 ( V_1 -> V_86 ) ;
if ( ! V_1 -> V_65 ) {
F_19 ( V_2 , L_12
L_7 , V_1 -> V_86 ) ;
V_49 = - V_72 ;
goto V_73;
}
V_49 = F_24 ( V_47 -> V_24 , V_1 -> V_65 ,
V_1 -> V_86 ,
& V_1 -> V_64 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_13 ) ;
goto V_73;
}
V_67 = & V_1 -> V_14 ;
memset ( V_67 , 0 , sizeof( struct V_12 ) ) ;
V_67 -> V_15 . V_16 = V_87 ;
V_67 -> V_18 . V_52 . V_88 . V_76 =
V_1 -> V_64 ;
V_67 -> V_18 . V_52 . V_88 . V_54 = V_63 ;
V_49 = F_3 ( V_47 -> V_24 , V_67 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_67 ,
V_25 ,
V_77 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_14 ) ;
goto V_73;
}
F_25 ( & V_1 -> V_40 ) ;
if ( V_67 -> V_18 . V_52 .
V_89 . V_79 != V_80 ) {
F_19 ( V_2 , L_15
L_11 ,
V_67 -> V_18 . V_52 .
V_89 . V_79 ) ;
V_49 = - V_81 ;
goto V_73;
}
V_1 -> V_60 = V_67 -> V_18 .
V_52 . V_89 . V_90 ;
V_1 -> V_91 =
V_1 -> V_86 / V_1 -> V_60 ;
F_27 ( V_2 , L_16 ,
V_1 -> V_60 , V_1 -> V_91 ) ;
V_68 = F_28 ( V_1 -> V_91 , V_92 ) ;
V_1 -> V_66 = F_29 ( V_68 , sizeof( V_93 ) , V_27 ) ;
if ( V_1 -> V_66 == NULL ) {
V_49 = - V_72 ;
goto V_73;
}
goto exit;
V_73:
F_16 ( V_47 ) ;
exit:
return V_49 ;
}
static int F_30 ( struct V_6 * V_47 ,
struct V_9 * V_1 ,
struct V_12 * V_67 ,
T_2 V_94 )
{
struct V_1 * V_2 = F_17 ( V_47 ) ;
int V_49 ;
memset ( V_67 , 0 , sizeof( struct V_12 ) ) ;
V_67 -> V_15 . V_16 = V_95 ;
V_67 -> V_18 . V_96 . V_97 . V_98 = V_94 ;
V_67 -> V_18 . V_96 . V_97 . V_99 = V_94 ;
V_49 = F_3 ( V_47 -> V_24 , V_67 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_67 ,
V_25 ,
V_77 ) ;
if ( V_49 != 0 )
return V_49 ;
F_25 ( & V_1 -> V_40 ) ;
if ( V_67 -> V_18 . V_96 . V_100 . V_79 !=
V_80 )
return - V_81 ;
if ( V_94 == V_101 )
return 0 ;
memset ( V_67 , 0 , sizeof( struct V_12 ) ) ;
V_67 -> V_15 . V_16 = V_102 ;
V_67 -> V_18 . V_103 . V_104 . V_105 = V_2 -> V_105 + V_106 ;
V_67 -> V_18 . V_103 . V_104 . V_107 . V_108 = 1 ;
if ( V_94 >= V_109 ) {
V_67 -> V_18 . V_103 . V_104 . V_107 . V_110 = 1 ;
V_67 -> V_18 . V_103 . V_104 . V_107 . V_111 = 1 ;
}
V_49 = F_3 ( V_47 -> V_24 , V_67 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_67 ,
V_25 , 0 ) ;
return V_49 ;
}
static int F_31 ( struct V_6 * V_47 ,
struct V_9 * V_1 )
{
const T_2 V_112 [] = {
V_101 , V_113 ,
V_114 , V_109
} ;
struct V_12 * V_67 ;
int V_115 , V_45 , V_49 ;
V_67 = & V_1 -> V_14 ;
for ( V_45 = F_32 ( V_112 ) - 1 ; V_45 >= 0 ; V_45 -- )
if ( F_30 ( V_47 , V_1 , V_67 ,
V_112 [ V_45 ] ) == 0 ) {
V_1 -> V_116 = V_112 [ V_45 ] ;
break;
}
if ( V_45 < 0 ) {
V_49 = - V_117 ;
goto V_73;
}
F_33 ( L_17 , V_1 -> V_116 ) ;
memset ( V_67 , 0 , sizeof( struct V_12 ) ) ;
if ( V_1 -> V_116 <= V_114 )
V_115 = 0x00060001 ;
else
V_115 = 0x0006001e ;
V_67 -> V_15 . V_16 = V_118 ;
V_67 -> V_18 . V_52 .
V_119 . V_120 =
( V_115 & 0xFFFF0000 ) >> 16 ;
V_67 -> V_18 . V_52 .
V_119 . V_121 =
V_115 & 0xFFFF ;
V_49 = F_3 ( V_47 -> V_24 , V_67 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_67 ,
V_25 , 0 ) ;
if ( V_49 != 0 )
goto V_73;
if ( V_1 -> V_116 <= V_113 )
V_1 -> V_71 = V_122 ;
else
V_1 -> V_71 = V_123 ;
V_1 -> V_86 = V_124 ;
V_49 = F_21 ( V_47 , V_1 ) ;
V_73:
return V_49 ;
}
static void F_34 ( struct V_6 * V_47 )
{
F_16 ( V_47 ) ;
}
void F_35 ( struct V_6 * V_47 )
{
struct V_1 * V_2 = F_17 ( V_47 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1 = V_5 -> V_11 ;
int V_45 ;
F_34 ( V_47 ) ;
F_36 ( V_5 -> V_11 , NULL ) ;
F_27 ( V_2 , L_18 ) ;
F_37 ( V_47 -> V_24 ) ;
for ( V_45 = 0 ; V_45 < V_1 -> V_125 ; V_45 ++ )
F_38 ( & V_1 -> V_28 [ V_45 ] . V_126 ) ;
F_14 ( V_1 ) ;
}
static inline T_2 F_39 (
struct V_127 * V_128 )
{
T_2 V_129 , V_130 ;
F_40 ( V_128 , & V_129 , & V_130 ) ;
return V_130 * 100 / V_128 -> V_131 ;
}
static inline void F_41 ( struct V_9 * V_1 ,
T_2 V_132 )
{
F_42 ( V_132 , V_1 -> V_66 ) ;
}
static void F_43 ( struct V_9 * V_1 ,
struct V_133 * V_134 ,
struct V_6 * V_47 ,
const struct V_135 * V_136 ,
int V_137 )
{
struct V_138 * V_139 = (struct V_138 * ) ( unsigned long ) V_136 -> V_140 ;
struct V_1 * V_2 = F_17 ( V_47 ) ;
struct V_133 * V_24 = V_47 -> V_24 ;
T_3 V_141 = 0 ;
int V_142 ;
if ( F_44 ( V_139 ) ) {
const struct V_143 * V_144
= (struct V_143 * ) V_139 -> V_145 ;
T_2 V_146 = V_144 -> V_147 ;
struct V_148 * V_149 ;
if ( V_146 != V_150 )
F_41 ( V_1 , V_146 ) ;
V_141 = V_144 -> V_141 ;
V_24 = V_134 ;
V_149 = & V_1 -> V_28 [ V_141 ] . V_149 ;
F_45 ( & V_149 -> V_151 ) ;
V_149 -> V_152 += V_144 -> V_153 ;
V_149 -> V_154 += V_144 -> V_155 ;
F_46 ( & V_149 -> V_151 ) ;
F_47 ( V_139 , V_137 ) ;
}
V_142 =
F_48 ( & V_1 -> V_28 [ V_141 ] . V_142 ) ;
if ( V_1 -> V_34 && V_142 == 0 )
F_49 ( & V_1 -> V_33 ) ;
if ( F_50 ( F_51 ( V_2 , V_141 ) ) &&
( F_39 ( & V_24 -> V_156 ) > V_157 ||
V_142 < 1 ) )
F_52 ( F_51 ( V_2 , V_141 ) ) ;
}
static void F_53 ( struct V_9 * V_1 ,
struct V_133 * V_134 ,
struct V_6 * V_47 ,
const struct V_135 * V_136 ,
int V_137 )
{
struct V_12 * V_158 = F_54 ( V_136 ) ;
struct V_1 * V_2 = F_17 ( V_47 ) ;
switch ( V_158 -> V_15 . V_16 ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
memcpy ( & V_1 -> V_14 , V_158 ,
sizeof( struct V_12 ) ) ;
F_55 ( & V_1 -> V_40 ) ;
break;
case V_163 :
F_43 ( V_1 , V_134 ,
V_47 , V_136 , V_137 ) ;
break;
default:
F_19 ( V_2 ,
L_19 ,
V_158 -> V_15 . V_16 ) ;
}
}
static T_2 F_56 ( struct V_9 * V_1 )
{
unsigned long * V_164 = V_1 -> V_66 ;
unsigned int V_45 ;
F_57 (i, map_addr, net_device->send_section_cnt) {
if ( F_58 ( V_45 , V_164 ) == 0 )
return V_45 ;
}
return V_150 ;
}
static T_2 F_59 ( struct V_9 * V_1 ,
unsigned int V_165 ,
T_2 V_166 ,
struct V_143 * V_144 ,
struct V_167 * V_168 ,
struct V_169 * * V_170 ,
struct V_138 * V_139 )
{
char * V_171 = V_1 -> V_65 ;
char * V_172 = V_171 + ( V_165 * V_1 -> V_60 )
+ V_166 ;
int V_45 ;
T_2 V_173 = 0 ;
T_2 V_174 = 0 ;
T_2 V_175 = V_144 -> V_176 % V_1 -> V_38 ;
T_2 V_177 = V_144 -> V_178 ? V_144 -> V_179 :
V_144 -> V_180 ;
if ( V_139 -> V_181 && V_175 && ! V_144 -> V_178 ) {
V_174 = V_1 -> V_38 - V_175 ;
V_168 -> V_182 += V_174 ;
V_144 -> V_176 += V_174 ;
}
for ( V_45 = 0 ; V_45 < V_177 ; V_45 ++ ) {
char * V_183 = F_60 ( ( * V_170 ) [ V_45 ] . V_184 << V_185 ) ;
T_2 V_85 = ( * V_170 ) [ V_45 ] . V_85 ;
T_2 V_186 = ( * V_170 ) [ V_45 ] . V_186 ;
memcpy ( V_172 , ( V_183 + V_85 ) , V_186 ) ;
V_173 += V_186 ;
V_172 += V_186 ;
}
if ( V_174 ) {
memset ( V_172 , 0 , V_174 ) ;
V_173 += V_174 ;
}
return V_173 ;
}
static inline int F_61 (
struct V_6 * V_47 ,
struct V_143 * V_144 ,
struct V_9 * V_1 ,
struct V_169 * * V_170 ,
struct V_138 * V_139 )
{
struct V_12 V_187 ;
struct V_188 * V_189
= & V_1 -> V_28 [ V_144 -> V_141 ] ;
struct V_133 * V_190 = V_189 -> V_24 ;
struct V_1 * V_2 = F_17 ( V_47 ) ;
struct V_191 * V_192 = F_51 ( V_2 , V_144 -> V_141 ) ;
T_4 V_193 ;
int V_49 ;
struct V_169 * V_194 ;
T_2 V_195 = F_39 ( & V_190 -> V_156 ) ;
V_187 . V_15 . V_16 = V_196 ;
if ( V_139 != NULL ) {
V_187 . V_18 . V_52 . V_197 . V_198 = 0 ;
} else {
V_187 . V_18 . V_52 . V_197 . V_198 = 1 ;
}
V_187 . V_18 . V_52 . V_197 . V_199 =
V_144 -> V_147 ;
if ( V_144 -> V_147 == V_150 )
V_187 . V_18 . V_52 . V_197 . V_200 = 0 ;
else
V_187 . V_18 . V_52 . V_197 . V_200 =
V_144 -> V_176 ;
V_193 = ( V_93 ) V_139 ;
if ( V_190 -> V_56 )
return - V_201 ;
if ( V_144 -> V_180 ) {
V_194 = V_144 -> V_178 ? ( * V_170 ) +
V_144 -> V_179 : ( * V_170 ) ;
V_49 = F_62 ( V_190 ,
V_194 ,
V_144 -> V_180 ,
& V_187 ,
sizeof( struct V_12 ) ,
V_193 ,
V_77 ) ;
} else {
V_49 = F_63 ( V_190 , & V_187 ,
sizeof( struct V_12 ) ,
V_193 ,
V_25 ,
V_77 ) ;
}
if ( V_49 == 0 ) {
F_64 ( & V_189 -> V_142 ) ;
if ( V_195 < V_202 )
F_65 ( V_192 ) ;
} else if ( V_49 == - V_203 ) {
F_65 ( V_192 ) ;
if ( F_66 ( & V_189 -> V_142 ) < 1 ) {
F_52 ( V_192 ) ;
V_49 = - V_204 ;
}
} else {
F_19 ( V_2 , L_20 ,
V_144 , V_49 ) ;
}
return V_49 ;
}
static inline void F_67 ( struct V_143 * * V_205 ,
struct V_138 * * V_206 ,
struct V_207 * V_208 )
{
* V_206 = V_208 -> V_139 ;
* V_205 = V_208 -> V_209 ;
V_208 -> V_139 = NULL ;
V_208 -> V_209 = NULL ;
V_208 -> V_210 = 0 ;
}
int F_68 ( struct V_6 * V_47 ,
struct V_143 * V_144 ,
struct V_167 * V_168 ,
struct V_169 * * V_170 ,
struct V_138 * V_139 )
{
struct V_9 * V_1 = F_69 ( V_47 ) ;
int V_49 = 0 ;
struct V_188 * V_189 ;
T_2 V_211 = V_144 -> V_176 , V_212 = 0 ;
unsigned int V_165 = V_150 ;
struct V_207 * V_208 ;
struct V_143 * V_205 = NULL , * V_213 = NULL ;
struct V_138 * V_206 = NULL ;
bool V_214 ;
bool V_181 = ( V_139 != NULL ) ? V_139 -> V_181 : false ;
if ( F_70 ( V_1 -> V_34 ) )
return - V_201 ;
if ( F_70 ( ! V_1 -> V_66 ) )
return - V_203 ;
V_189 = & V_1 -> V_28 [ V_144 -> V_141 ] ;
V_144 -> V_147 = V_150 ;
V_144 -> V_178 = false ;
if ( ! V_139 ) {
V_213 = V_144 ;
goto V_215;
}
V_208 = & V_189 -> V_216 ;
if ( V_208 -> V_209 )
V_212 = V_208 -> V_209 -> V_176 ;
V_214 = V_212 > 0 && V_208 -> V_210 < V_1 -> V_36 ;
if ( V_214 && V_212 + V_211 + V_1 -> V_38 <
V_1 -> V_60 ) {
V_165 = V_208 -> V_209 -> V_147 ;
} else if ( V_214 && V_212 + V_144 -> V_217 <
V_1 -> V_60 ) {
V_165 = V_208 -> V_209 -> V_147 ;
V_144 -> V_178 = true ;
} else if ( V_211 + V_1 -> V_38 <
V_1 -> V_60 ) {
V_165 = F_56 ( V_1 ) ;
if ( V_165 != V_150 ) {
F_67 ( & V_205 , & V_206 , V_208 ) ;
V_212 = 0 ;
}
}
if ( V_165 != V_150 ) {
F_59 ( V_1 ,
V_165 , V_212 ,
V_144 , V_168 , V_170 , V_139 ) ;
V_144 -> V_147 = V_165 ;
if ( V_144 -> V_178 ) {
V_144 -> V_180 -= V_144 -> V_179 ;
V_144 -> V_176 = V_212 + V_144 -> V_217 ;
} else {
V_144 -> V_180 = 0 ;
V_144 -> V_176 += V_212 ;
}
if ( V_208 -> V_209 ) {
V_144 -> V_153 += V_208 -> V_209 -> V_153 ;
V_144 -> V_155 += V_208 -> V_209 -> V_155 ;
}
if ( V_208 -> V_139 )
F_71 ( V_208 -> V_139 ) ;
if ( V_181 && ! V_144 -> V_178 ) {
V_208 -> V_139 = V_139 ;
V_208 -> V_209 = V_144 ;
V_208 -> V_210 ++ ;
} else {
V_213 = V_144 ;
V_208 -> V_139 = NULL ;
V_208 -> V_209 = NULL ;
V_208 -> V_210 = 0 ;
}
} else {
F_67 ( & V_205 , & V_206 , V_208 ) ;
V_213 = V_144 ;
}
if ( V_205 ) {
int V_218 = F_61 ( V_47 , V_205 , V_1 ,
NULL , V_206 ) ;
if ( V_218 != 0 ) {
F_41 ( V_1 ,
V_205 -> V_147 ) ;
F_72 ( V_206 ) ;
}
}
V_215:
if ( V_213 )
V_49 = F_61 ( V_47 , V_213 , V_1 , V_170 , V_139 ) ;
if ( V_49 != 0 && V_165 != V_150 )
F_41 ( V_1 , V_165 ) ;
return V_49 ;
}
static int F_73 ( struct V_133 * V_24 ,
T_4 V_219 , T_2 V_79 )
{
struct V_12 V_220 ;
int V_49 ;
V_220 . V_15 . V_16 =
V_163 ;
V_220 . V_18 . V_52 . V_221 . V_79 = V_79 ;
V_49 = F_3 ( V_24 , & V_220 ,
sizeof( struct V_222 ) + sizeof( T_2 ) ,
V_219 , V_223 , 0 ) ;
return V_49 ;
}
static inline void F_74 ( struct V_9 * V_11 , T_3 V_141 ,
T_2 * V_224 , T_2 * V_225 )
{
struct V_226 * V_29 = & V_11 -> V_28 [ V_141 ] . V_29 ;
T_2 V_227 = V_29 -> V_227 ;
T_2 V_228 = V_29 -> V_228 ;
* V_224 = ( V_227 > V_228 ) ? V_31 - V_227 + V_228 :
V_228 - V_227 ;
* V_225 = V_31 - * V_224 - 1 ;
}
static inline struct V_32 * F_75 ( struct V_9
* V_11 , T_3 V_141 )
{
struct V_226 * V_29 = & V_11 -> V_28 [ V_141 ] . V_29 ;
T_2 V_224 , V_225 ;
if ( F_70 ( ! V_29 -> V_30 ) )
return NULL ;
F_74 ( V_11 , V_141 , & V_224 , & V_225 ) ;
if ( ! V_224 )
return NULL ;
return V_29 -> V_30 + V_29 -> V_227 * sizeof( struct V_32 ) ;
}
static inline void F_76 ( struct V_9 * V_11 , T_3 V_141 )
{
struct V_226 * V_29 = & V_11 -> V_28 [ V_141 ] . V_29 ;
int V_229 ;
V_29 -> V_227 = ( V_29 -> V_227 + 1 ) % V_31 ;
V_229 = F_48 ( & V_11 -> V_230 ) ;
if ( V_11 -> V_34 && V_229 == 0 )
F_49 ( & V_11 -> V_33 ) ;
}
static void F_77 ( struct V_9 * V_11 ,
struct V_133 * V_24 , T_3 V_141 )
{
struct V_32 * V_231 ;
int V_49 ;
while ( true ) {
V_231 = F_75 ( V_11 , V_141 ) ;
if ( ! V_231 )
break;
V_49 = F_73 ( V_24 , V_231 -> V_232 ,
V_231 -> V_79 ) ;
if ( V_49 )
break;
F_76 ( V_11 , V_141 ) ;
}
}
static inline struct V_32 * F_78 (
struct V_9 * V_11 , struct V_133 * V_24 , T_3 V_141 )
{
struct V_226 * V_29 = & V_11 -> V_28 [ V_141 ] . V_29 ;
T_2 V_224 , V_225 , V_228 ;
struct V_32 * V_231 ;
if ( F_70 ( ! V_11 -> V_59 ) )
return NULL ;
if ( F_70 ( ! V_29 -> V_30 ) )
return NULL ;
if ( F_66 ( & V_11 -> V_230 ) >
V_11 -> V_59 -> V_233 * V_234 / 100 )
F_77 ( V_11 , V_24 , V_141 ) ;
F_74 ( V_11 , V_141 , & V_224 , & V_225 ) ;
if ( ! V_225 )
return NULL ;
V_228 = V_29 -> V_228 ;
V_231 = V_29 -> V_30 + V_228 * sizeof( struct V_32 ) ;
V_29 -> V_228 = ( V_228 + 1 ) % V_31 ;
F_79 ( & V_11 -> V_230 ) ;
return V_231 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_9 * V_1 ,
struct V_4 * V_5 ,
struct V_6 * V_47 ,
struct V_133 * V_24 ,
const struct V_135 * V_136 ,
struct V_12 * V_235 )
{
const struct V_236 * V_237
= F_11 ( V_136 , const struct V_236 , V_238 ) ;
T_3 V_141 = V_24 -> V_239 . V_240 . V_241 ;
char * V_58 = V_1 -> V_58 ;
T_2 V_79 = V_80 ;
int V_45 ;
int V_210 = 0 ;
int V_49 ;
if ( F_70 ( V_235 -> V_15 . V_16 != V_196 ) ) {
F_81 ( V_5 , V_242 , V_2 ,
L_21 ,
V_235 -> V_15 . V_16 ) ;
return 0 ;
}
if ( F_70 ( V_237 -> V_243 != V_55 ) ) {
F_81 ( V_5 , V_242 , V_2 ,
L_22 ,
V_55 ,
V_237 -> V_243 ) ;
return 0 ;
}
V_210 = V_237 -> V_244 ;
for ( V_45 = 0 ; V_45 < V_210 ; V_45 ++ ) {
void * V_245 = V_58
+ V_237 -> V_246 [ V_45 ] . V_247 ;
T_2 V_248 = V_237 -> V_246 [ V_45 ] . V_249 ;
V_79 = F_82 ( V_2 , V_1 , V_47 ,
V_24 , V_245 , V_248 ) ;
}
if ( V_1 -> V_28 [ V_141 ] . V_29 . V_30 ) {
struct V_32 * V_231 ;
V_231 = F_78 ( V_1 , V_24 , V_141 ) ;
if ( V_231 ) {
V_231 -> V_232 = V_237 -> V_238 . V_140 ;
V_231 -> V_79 = V_79 ;
} else {
F_19 ( V_2 , L_23 ,
V_141 , V_237 -> V_238 . V_140 ) ;
}
} else {
V_49 = F_73 ( V_24 ,
V_237 -> V_238 . V_140 ,
V_79 ) ;
if ( V_49 )
F_19 ( V_2 , L_24 ,
V_141 , V_237 -> V_238 . V_140 , V_49 ) ;
}
return V_210 ;
}
static void F_83 ( struct V_6 * V_250 ,
struct V_12 * V_187 )
{
struct V_1 * V_2 = F_17 ( V_250 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_45 ;
T_2 V_210 , * V_251 ;
V_210 = V_187 -> V_18 . V_252 . V_253 . V_210 ;
if ( V_210 != V_254 ) {
F_19 ( V_2 , L_25 , V_210 ) ;
return;
}
V_251 = ( T_2 * ) ( ( unsigned long ) & V_187 -> V_18 . V_252 . V_253 +
V_187 -> V_18 . V_252 . V_253 . V_85 ) ;
for ( V_45 = 0 ; V_45 < V_210 ; V_45 ++ )
V_5 -> V_255 [ V_45 ] = V_251 [ V_45 ] ;
}
static void F_84 ( struct V_4 * V_5 ,
struct V_12 * V_187 )
{
V_5 -> V_256 = V_187 -> V_18 . V_19 . V_257 . V_258 ;
V_5 -> V_259 = V_187 -> V_18 . V_19 . V_257 . V_260 ;
}
static inline void F_85 ( struct V_6 * V_250 ,
struct V_4 * V_5 ,
struct V_12 * V_187 )
{
switch ( V_187 -> V_15 . V_16 ) {
case V_261 :
F_83 ( V_250 , V_187 ) ;
break;
case V_262 :
F_84 ( V_5 , V_187 ) ;
break;
}
}
static int F_86 ( struct V_6 * V_47 ,
struct V_133 * V_24 ,
struct V_9 * V_1 ,
struct V_1 * V_2 ,
const struct V_135 * V_136 ,
int V_137 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_12 * V_187 = F_54 ( V_136 ) ;
switch ( V_136 -> type ) {
case V_223 :
F_53 ( V_1 , V_24 , V_47 ,
V_136 , V_137 ) ;
break;
case V_263 :
return F_80 ( V_2 , V_1 , V_5 ,
V_47 , V_24 , V_136 , V_187 ) ;
break;
case V_25 :
F_85 ( V_47 , V_5 , V_187 ) ;
break;
default:
F_19 ( V_2 , L_26 ,
V_136 -> type , V_136 -> V_140 ) ;
break;
}
return 0 ;
}
static struct V_6 * F_87 ( struct V_133 * V_24 )
{
struct V_133 * V_264 = V_24 -> V_265 ;
return V_264 ? V_264 -> V_266 : V_24 -> V_266 ;
}
int F_88 ( struct V_267 * V_126 , int V_137 )
{
struct V_188 * V_189
= F_11 ( V_126 , struct V_188 , V_126 ) ;
struct V_133 * V_24 = V_189 -> V_24 ;
struct V_6 * V_47 = F_87 ( V_24 ) ;
T_3 V_141 = V_24 -> V_239 . V_240 . V_241 ;
struct V_1 * V_2 = F_17 ( V_47 ) ;
struct V_9 * V_1 = F_18 ( V_2 ) ;
int V_268 = 0 ;
if ( ! V_189 -> V_136 )
V_189 -> V_136 = F_89 ( V_24 ) ;
while ( V_189 -> V_136 && V_268 < V_137 ) {
V_268 += F_86 ( V_47 , V_24 , V_1 ,
V_2 , V_189 -> V_136 , V_137 ) ;
V_189 -> V_136 = F_90 ( V_24 , V_189 -> V_136 ) ;
}
if ( V_268 < V_137 &&
F_91 ( V_126 , V_268 ) &&
F_92 ( & V_24 -> V_269 ) != 0 )
F_93 ( V_126 ) ;
F_77 ( V_1 , V_24 , V_141 ) ;
return F_94 ( V_268 , V_137 ) ;
}
void F_95 ( void * V_270 )
{
struct V_188 * V_189 = V_270 ;
if ( F_96 ( & V_189 -> V_126 ) ) {
F_97 ( & V_189 -> V_24 -> V_269 ) ;
F_98 ( & V_189 -> V_126 ) ;
}
}
int F_99 ( struct V_6 * V_47 ,
const struct V_271 * V_272 )
{
int V_45 , V_49 = 0 ;
int V_273 = V_272 -> V_273 ;
struct V_9 * V_1 ;
struct V_1 * V_2 = F_17 ( V_47 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_1 = F_4 () ;
if ( ! V_1 )
return - V_72 ;
V_1 -> V_273 = V_273 ;
F_100 ( V_47 -> V_24 , V_274 ) ;
for ( V_45 = 0 ; V_45 < V_46 ; V_45 ++ ) {
struct V_188 * V_189 = & V_1 -> V_28 [ V_45 ] ;
V_189 -> V_24 = V_47 -> V_24 ;
F_101 ( & V_189 -> V_149 . V_151 ) ;
F_101 ( & V_189 -> V_275 . V_151 ) ;
}
F_102 ( V_2 , & V_1 -> V_28 [ 0 ] . V_126 ,
F_88 , V_276 ) ;
V_49 = F_103 ( V_47 -> V_24 , V_273 * V_277 ,
V_273 * V_277 , NULL , 0 ,
F_95 ,
V_1 -> V_28 ) ;
if ( V_49 != 0 ) {
F_38 ( & V_1 -> V_28 [ 0 ] . V_126 ) ;
F_19 ( V_2 , L_27 , V_49 ) ;
goto V_73;
}
F_27 ( V_2 , L_28 ) ;
F_104 ( & V_1 -> V_28 [ 0 ] . V_126 ) ;
F_105 ( V_5 -> V_11 , V_1 ) ;
V_49 = F_31 ( V_47 , V_1 ) ;
if ( V_49 != 0 ) {
F_19 ( V_2 ,
L_29 , V_49 ) ;
goto V_278;
}
return V_49 ;
V_278:
F_38 ( & V_1 -> V_28 [ 0 ] . V_126 ) ;
F_37 ( V_47 -> V_24 ) ;
V_73:
F_10 ( & V_1 -> V_44 ) ;
return V_49 ;
}
