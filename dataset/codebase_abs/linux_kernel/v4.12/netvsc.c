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
}
static struct V_9 * F_4 ( void )
{
struct V_9 * V_1 ;
V_1 = F_5 ( sizeof( struct V_9 ) , V_26 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_27 [ 0 ] . V_28 . V_29
= F_6 ( V_30 * sizeof( struct V_31 ) ) ;
F_7 ( & V_1 -> V_32 ) ;
V_1 -> V_33 = false ;
F_8 ( & V_1 -> V_34 , 0 ) ;
V_1 -> V_35 = V_36 ;
V_1 -> V_37 = V_38 ;
F_9 ( & V_1 -> V_39 ) ;
return V_1 ;
}
static void F_10 ( struct V_40 * V_41 )
{
struct V_9 * V_11
= F_11 ( V_41 , struct V_9 , V_42 ) ;
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ )
F_12 ( V_11 -> V_27 [ V_43 ] . V_28 . V_29 ) ;
F_13 ( V_11 ) ;
}
static void F_14 ( struct V_9 * V_11 )
{
F_15 ( & V_11 -> V_42 , F_10 ) ;
}
static struct V_9 * F_16 ( struct V_6 * V_45 )
{
struct V_9 * V_1 = F_17 ( V_45 ) ;
if ( V_1 && V_1 -> V_33 )
V_1 = NULL ;
return V_1 ;
}
static void F_18 ( struct V_6 * V_45 )
{
struct V_12 * V_46 ;
struct V_1 * V_2 = F_19 ( V_45 ) ;
struct V_9 * V_1 = F_20 ( V_2 ) ;
int V_47 ;
if ( V_1 -> V_48 ) {
V_46 = & V_1 -> V_46 ;
memset ( V_46 , 0 , sizeof( struct V_12 ) ) ;
V_46 -> V_15 . V_16 =
V_49 ;
V_46 -> V_18 . V_50 .
V_51 . V_52 = V_53 ;
V_47 = F_3 ( V_45 -> V_24 ,
V_46 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_46 ,
V_25 , 0 ) ;
if ( V_45 -> V_24 -> V_54 )
V_47 = 0 ;
if ( V_47 != 0 ) {
F_21 ( V_2 , L_1
L_2 ) ;
return;
}
}
if ( V_1 -> V_55 ) {
V_47 = F_22 ( V_45 -> V_24 ,
V_1 -> V_55 ) ;
if ( V_47 != 0 ) {
F_21 ( V_2 ,
L_3 ) ;
return;
}
V_1 -> V_55 = 0 ;
}
if ( V_1 -> V_56 ) {
F_12 ( V_1 -> V_56 ) ;
V_1 -> V_56 = NULL ;
}
if ( V_1 -> V_57 ) {
V_1 -> V_48 = 0 ;
F_13 ( V_1 -> V_57 ) ;
V_1 -> V_57 = NULL ;
}
if ( V_1 -> V_58 ) {
V_46 = & V_1 -> V_46 ;
memset ( V_46 , 0 , sizeof( struct V_12 ) ) ;
V_46 -> V_15 . V_16 =
V_59 ;
V_46 -> V_18 . V_50 . V_60 . V_52 =
V_61 ;
V_47 = F_3 ( V_45 -> V_24 ,
V_46 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_46 ,
V_25 , 0 ) ;
if ( V_45 -> V_24 -> V_54 )
V_47 = 0 ;
if ( V_47 != 0 ) {
F_21 ( V_2 , L_1
L_4 ) ;
return;
}
}
if ( V_1 -> V_62 ) {
V_47 = F_22 ( V_45 -> V_24 ,
V_1 -> V_62 ) ;
if ( V_47 != 0 ) {
F_21 ( V_2 ,
L_5 ) ;
return;
}
V_1 -> V_62 = 0 ;
}
if ( V_1 -> V_63 ) {
F_12 ( V_1 -> V_63 ) ;
V_1 -> V_63 = NULL ;
}
F_13 ( V_1 -> V_64 ) ;
}
static int F_23 ( struct V_6 * V_45 )
{
int V_47 = 0 ;
struct V_9 * V_1 ;
struct V_12 * V_65 ;
struct V_1 * V_2 ;
T_1 V_66 ;
int V_67 ;
V_1 = F_16 ( V_45 ) ;
if ( ! V_1 )
return - V_68 ;
V_2 = F_19 ( V_45 ) ;
V_67 = F_24 ( V_45 -> V_24 -> V_69 ) ;
V_1 -> V_56 = F_25 ( V_1 -> V_70 , V_67 ) ;
if ( ! V_1 -> V_56 )
V_1 -> V_56 = F_6 ( V_1 -> V_70 ) ;
if ( ! V_1 -> V_56 ) {
F_21 ( V_2 , L_6
L_7 , V_1 -> V_70 ) ;
V_47 = - V_71 ;
goto V_72;
}
V_47 = F_26 ( V_45 -> V_24 , V_1 -> V_56 ,
V_1 -> V_70 ,
& V_1 -> V_55 ) ;
if ( V_47 != 0 ) {
F_21 ( V_2 ,
L_8 ) ;
goto V_72;
}
V_65 = & V_1 -> V_14 ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
V_65 -> V_15 . V_16 = V_73 ;
V_65 -> V_18 . V_50 . V_74 .
V_75 = V_1 -> V_55 ;
V_65 -> V_18 . V_50 .
V_74 . V_52 = V_53 ;
V_47 = F_3 ( V_45 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 ,
V_76 ) ;
if ( V_47 != 0 ) {
F_21 ( V_2 ,
L_9 ) ;
goto V_72;
}
F_27 ( & V_1 -> V_39 ) ;
if ( V_65 -> V_18 . V_50 .
V_77 . V_78 != V_79 ) {
F_21 ( V_2 , L_10
L_11 ,
V_65 -> V_18 . V_50 .
V_77 . V_78 ) ;
V_47 = - V_80 ;
goto V_72;
}
V_1 -> V_48 = V_65 -> V_18 .
V_50 . V_77 . V_81 ;
V_1 -> V_57 = F_28 (
V_65 -> V_18 . V_50 . V_77 . V_82 ,
V_1 -> V_48 *
sizeof( struct V_83 ) ,
V_26 ) ;
if ( V_1 -> V_57 == NULL ) {
V_47 = - V_80 ;
goto V_72;
}
if ( V_1 -> V_48 != 1 ||
V_1 -> V_57 -> V_84 != 0 ) {
V_47 = - V_80 ;
goto V_72;
}
V_1 -> V_63 = F_25 ( V_1 -> V_85 , V_67 ) ;
if ( ! V_1 -> V_63 )
V_1 -> V_63 = F_6 ( V_1 -> V_85 ) ;
if ( ! V_1 -> V_63 ) {
F_21 ( V_2 , L_12
L_7 , V_1 -> V_85 ) ;
V_47 = - V_71 ;
goto V_72;
}
V_47 = F_26 ( V_45 -> V_24 , V_1 -> V_63 ,
V_1 -> V_85 ,
& V_1 -> V_62 ) ;
if ( V_47 != 0 ) {
F_21 ( V_2 ,
L_13 ) ;
goto V_72;
}
V_65 = & V_1 -> V_14 ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
V_65 -> V_15 . V_16 = V_86 ;
V_65 -> V_18 . V_50 . V_87 . V_75 =
V_1 -> V_62 ;
V_65 -> V_18 . V_50 . V_87 . V_52 = V_61 ;
V_47 = F_3 ( V_45 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 ,
V_76 ) ;
if ( V_47 != 0 ) {
F_21 ( V_2 ,
L_14 ) ;
goto V_72;
}
F_27 ( & V_1 -> V_39 ) ;
if ( V_65 -> V_18 . V_50 .
V_88 . V_78 != V_79 ) {
F_21 ( V_2 , L_15
L_11 ,
V_65 -> V_18 . V_50 .
V_88 . V_78 ) ;
V_47 = - V_80 ;
goto V_72;
}
V_1 -> V_58 = V_65 -> V_18 .
V_50 . V_88 . V_89 ;
V_1 -> V_90 =
V_1 -> V_85 / V_1 -> V_58 ;
F_29 ( V_2 , L_16 ,
V_1 -> V_58 , V_1 -> V_90 ) ;
V_66 = F_30 ( V_1 -> V_90 , V_91 ) ;
V_1 -> V_64 = F_31 ( V_66 , sizeof( V_92 ) , V_26 ) ;
if ( V_1 -> V_64 == NULL ) {
V_47 = - V_71 ;
goto V_72;
}
goto exit;
V_72:
F_18 ( V_45 ) ;
exit:
return V_47 ;
}
static int F_32 ( struct V_6 * V_45 ,
struct V_9 * V_1 ,
struct V_12 * V_65 ,
T_2 V_93 )
{
struct V_1 * V_2 = F_19 ( V_45 ) ;
int V_47 ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
V_65 -> V_15 . V_16 = V_94 ;
V_65 -> V_18 . V_95 . V_96 . V_97 = V_93 ;
V_65 -> V_18 . V_95 . V_96 . V_98 = V_93 ;
V_47 = F_3 ( V_45 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 ,
V_76 ) ;
if ( V_47 != 0 )
return V_47 ;
F_27 ( & V_1 -> V_39 ) ;
if ( V_65 -> V_18 . V_95 . V_99 . V_78 !=
V_79 )
return - V_80 ;
if ( V_93 == V_100 )
return 0 ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
V_65 -> V_15 . V_16 = V_101 ;
V_65 -> V_18 . V_102 . V_103 . V_104 = V_2 -> V_104 + V_105 ;
V_65 -> V_18 . V_102 . V_103 . V_106 . V_107 = 1 ;
if ( V_93 >= V_108 ) {
V_65 -> V_18 . V_102 . V_103 . V_106 . V_109 = 1 ;
V_65 -> V_18 . V_102 . V_103 . V_106 . V_110 = 1 ;
}
V_47 = F_3 ( V_45 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 , 0 ) ;
return V_47 ;
}
static int F_33 ( struct V_6 * V_45 )
{
int V_47 ;
struct V_9 * V_1 ;
struct V_12 * V_65 ;
int V_111 ;
const T_2 V_112 [] = {
V_100 , V_113 ,
V_114 , V_108 } ;
int V_43 ;
V_1 = F_16 ( V_45 ) ;
if ( ! V_1 )
return - V_68 ;
V_65 = & V_1 -> V_14 ;
for ( V_43 = F_34 ( V_112 ) - 1 ; V_43 >= 0 ; V_43 -- )
if ( F_32 ( V_45 , V_1 , V_65 ,
V_112 [ V_43 ] ) == 0 ) {
V_1 -> V_115 = V_112 [ V_43 ] ;
break;
}
if ( V_43 < 0 ) {
V_47 = - V_116 ;
goto V_72;
}
F_35 ( L_17 , V_1 -> V_115 ) ;
memset ( V_65 , 0 , sizeof( struct V_12 ) ) ;
if ( V_1 -> V_115 <= V_114 )
V_111 = 0x00060001 ;
else
V_111 = 0x0006001e ;
V_65 -> V_15 . V_16 = V_117 ;
V_65 -> V_18 . V_50 .
V_118 . V_119 =
( V_111 & 0xFFFF0000 ) >> 16 ;
V_65 -> V_18 . V_50 .
V_118 . V_120 =
V_111 & 0xFFFF ;
V_47 = F_3 ( V_45 -> V_24 , V_65 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_65 ,
V_25 , 0 ) ;
if ( V_47 != 0 )
goto V_72;
if ( V_1 -> V_115 <= V_113 )
V_1 -> V_70 = V_121 ;
else
V_1 -> V_70 = V_122 ;
V_1 -> V_85 = V_123 ;
V_47 = F_23 ( V_45 ) ;
V_72:
return V_47 ;
}
static void F_36 ( struct V_6 * V_45 )
{
F_18 ( V_45 ) ;
}
void F_37 ( struct V_6 * V_45 )
{
struct V_1 * V_2 = F_19 ( V_45 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1 = V_5 -> V_11 ;
int V_43 ;
F_36 ( V_45 ) ;
F_38 ( V_5 -> V_11 , NULL ) ;
F_29 ( V_2 , L_18 ) ;
F_39 ( V_45 -> V_24 ) ;
for ( V_43 = 0 ; V_43 < V_1 -> V_124 ; V_43 ++ )
F_40 ( & V_1 -> V_27 [ V_43 ] . V_125 ) ;
F_14 ( V_1 ) ;
}
static inline T_2 F_41 (
struct V_126 * V_127 )
{
T_2 V_128 , V_129 ;
F_42 ( V_127 , & V_128 , & V_129 ) ;
return V_129 * 100 / V_127 -> V_130 ;
}
static inline void F_43 ( struct V_9 * V_1 ,
T_2 V_131 )
{
F_44 ( V_131 , V_1 -> V_64 ) ;
}
static void F_45 ( struct V_9 * V_1 ,
struct V_132 * V_133 ,
struct V_6 * V_45 ,
const struct V_134 * V_135 ,
int V_136 )
{
struct V_137 * V_138 = (struct V_137 * ) ( unsigned long ) V_135 -> V_139 ;
struct V_1 * V_2 = F_19 ( V_45 ) ;
struct V_132 * V_24 = V_45 -> V_24 ;
T_3 V_140 = 0 ;
int V_141 ;
if ( F_46 ( V_138 ) ) {
const struct V_142 * V_143
= (struct V_142 * ) V_138 -> V_144 ;
T_2 V_145 = V_143 -> V_146 ;
struct V_147 * V_148 ;
if ( V_145 != V_149 )
F_43 ( V_1 , V_145 ) ;
V_140 = V_143 -> V_140 ;
V_24 = V_133 ;
V_148 = & V_1 -> V_27 [ V_140 ] . V_148 ;
F_47 ( & V_148 -> V_150 ) ;
V_148 -> V_151 += V_143 -> V_152 ;
V_148 -> V_153 += V_143 -> V_154 ;
F_48 ( & V_148 -> V_150 ) ;
F_49 ( V_138 , V_136 ) ;
}
V_141 =
F_50 ( & V_1 -> V_27 [ V_140 ] . V_141 ) ;
if ( V_1 -> V_33 && V_141 == 0 )
F_51 ( & V_1 -> V_32 ) ;
if ( F_52 ( F_53 ( V_2 , V_140 ) ) &&
( F_41 ( & V_24 -> V_155 ) > V_156 ||
V_141 < 1 ) )
F_54 ( F_53 ( V_2 , V_140 ) ) ;
}
static void F_55 ( struct V_9 * V_1 ,
struct V_132 * V_133 ,
struct V_6 * V_45 ,
const struct V_134 * V_135 ,
int V_136 )
{
struct V_12 * V_157 = F_56 ( V_135 ) ;
struct V_1 * V_2 = F_19 ( V_45 ) ;
switch ( V_157 -> V_15 . V_16 ) {
case V_158 :
case V_159 :
case V_160 :
case V_161 :
memcpy ( & V_1 -> V_14 , V_157 ,
sizeof( struct V_12 ) ) ;
F_57 ( & V_1 -> V_39 ) ;
break;
case V_162 :
F_45 ( V_1 , V_133 ,
V_45 , V_135 , V_136 ) ;
break;
default:
F_21 ( V_2 ,
L_19 ,
V_157 -> V_15 . V_16 ) ;
}
}
static T_2 F_58 ( struct V_9 * V_1 )
{
unsigned long * V_163 = V_1 -> V_64 ;
unsigned int V_43 ;
F_59 (i, map_addr, net_device->send_section_cnt) {
if ( F_60 ( V_43 , V_163 ) == 0 )
return V_43 ;
}
return V_149 ;
}
static T_2 F_61 ( struct V_9 * V_1 ,
unsigned int V_164 ,
T_2 V_165 ,
struct V_142 * V_143 ,
struct V_166 * V_167 ,
struct V_168 * * V_169 ,
struct V_137 * V_138 )
{
char * V_170 = V_1 -> V_63 ;
char * V_171 = V_170 + ( V_164 * V_1 -> V_58 )
+ V_165 ;
int V_43 ;
T_2 V_172 = 0 ;
T_2 V_173 = 0 ;
T_2 V_174 = V_143 -> V_175 % V_1 -> V_37 ;
T_2 V_176 = V_143 -> V_177 ? V_143 -> V_178 :
V_143 -> V_179 ;
if ( V_138 -> V_180 && V_174 && ! V_143 -> V_177 ) {
V_173 = V_1 -> V_37 - V_174 ;
V_167 -> V_181 += V_173 ;
V_143 -> V_175 += V_173 ;
}
for ( V_43 = 0 ; V_43 < V_176 ; V_43 ++ ) {
char * V_182 = F_62 ( ( * V_169 ) [ V_43 ] . V_183 << V_184 ) ;
T_2 V_84 = ( * V_169 ) [ V_43 ] . V_84 ;
T_2 V_185 = ( * V_169 ) [ V_43 ] . V_185 ;
memcpy ( V_171 , ( V_182 + V_84 ) , V_185 ) ;
V_172 += V_185 ;
V_171 += V_185 ;
}
if ( V_173 ) {
memset ( V_171 , 0 , V_173 ) ;
V_172 += V_173 ;
}
return V_172 ;
}
static inline int F_63 (
struct V_6 * V_45 ,
struct V_142 * V_143 ,
struct V_9 * V_1 ,
struct V_168 * * V_169 ,
struct V_137 * V_138 )
{
struct V_12 V_186 ;
struct V_187 * V_188
= & V_1 -> V_27 [ V_143 -> V_140 ] ;
struct V_132 * V_189 = V_188 -> V_24 ;
struct V_1 * V_2 = F_19 ( V_45 ) ;
struct V_190 * V_191 = F_53 ( V_2 , V_143 -> V_140 ) ;
T_4 V_192 ;
int V_47 ;
struct V_168 * V_193 ;
T_2 V_194 = F_41 ( & V_189 -> V_155 ) ;
V_186 . V_15 . V_16 = V_195 ;
if ( V_138 != NULL ) {
V_186 . V_18 . V_50 . V_196 . V_197 = 0 ;
} else {
V_186 . V_18 . V_50 . V_196 . V_197 = 1 ;
}
V_186 . V_18 . V_50 . V_196 . V_198 =
V_143 -> V_146 ;
if ( V_143 -> V_146 == V_149 )
V_186 . V_18 . V_50 . V_196 . V_199 = 0 ;
else
V_186 . V_18 . V_50 . V_196 . V_199 =
V_143 -> V_175 ;
V_192 = ( V_92 ) V_138 ;
if ( V_189 -> V_54 )
return - V_68 ;
if ( V_143 -> V_179 ) {
V_193 = V_143 -> V_177 ? ( * V_169 ) +
V_143 -> V_178 : ( * V_169 ) ;
V_47 = F_64 ( V_189 ,
V_193 ,
V_143 -> V_179 ,
& V_186 ,
sizeof( struct V_12 ) ,
V_192 ,
V_76 ) ;
} else {
V_47 = F_65 ( V_189 , & V_186 ,
sizeof( struct V_12 ) ,
V_192 ,
V_25 ,
V_76 ) ;
}
if ( V_47 == 0 ) {
F_66 ( & V_188 -> V_141 ) ;
if ( V_194 < V_200 )
F_67 ( V_191 ) ;
} else if ( V_47 == - V_201 ) {
F_67 ( V_191 ) ;
if ( F_68 ( & V_188 -> V_141 ) < 1 ) {
F_54 ( V_191 ) ;
V_47 = - V_202 ;
}
} else {
F_21 ( V_2 , L_20 ,
V_143 , V_47 ) ;
}
return V_47 ;
}
static inline void F_69 ( struct V_142 * * V_203 ,
struct V_137 * * V_204 ,
struct V_205 * V_206 )
{
* V_204 = V_206 -> V_138 ;
* V_203 = V_206 -> V_207 ;
V_206 -> V_138 = NULL ;
V_206 -> V_207 = NULL ;
V_206 -> V_208 = 0 ;
}
int F_70 ( struct V_6 * V_45 ,
struct V_142 * V_143 ,
struct V_166 * V_167 ,
struct V_168 * * V_169 ,
struct V_137 * V_138 )
{
struct V_9 * V_1 ;
int V_47 = 0 ;
struct V_187 * V_188 ;
T_2 V_209 = V_143 -> V_175 , V_210 = 0 ;
unsigned int V_164 = V_149 ;
struct V_205 * V_206 ;
struct V_142 * V_203 = NULL , * V_211 = NULL ;
struct V_137 * V_204 = NULL ;
bool V_212 ;
bool V_180 = ( V_138 != NULL ) ? V_138 -> V_180 : false ;
V_1 = F_16 ( V_45 ) ;
if ( ! V_1 )
return - V_68 ;
if ( ! V_1 -> V_64 )
return - V_201 ;
V_188 = & V_1 -> V_27 [ V_143 -> V_140 ] ;
V_143 -> V_146 = V_149 ;
V_143 -> V_177 = false ;
if ( ! V_138 ) {
V_211 = V_143 ;
goto V_213;
}
V_206 = & V_188 -> V_214 ;
if ( V_206 -> V_207 )
V_210 = V_206 -> V_207 -> V_175 ;
V_212 = V_210 > 0 && V_206 -> V_208 < V_1 -> V_35 ;
if ( V_212 && V_210 + V_209 + V_1 -> V_37 <
V_1 -> V_58 ) {
V_164 = V_206 -> V_207 -> V_146 ;
} else if ( V_212 && V_210 + V_143 -> V_215 <
V_1 -> V_58 ) {
V_164 = V_206 -> V_207 -> V_146 ;
V_143 -> V_177 = true ;
} else if ( V_209 + V_1 -> V_37 <
V_1 -> V_58 ) {
V_164 = F_58 ( V_1 ) ;
if ( V_164 != V_149 ) {
F_69 ( & V_203 , & V_204 , V_206 ) ;
V_210 = 0 ;
}
}
if ( V_164 != V_149 ) {
F_61 ( V_1 ,
V_164 , V_210 ,
V_143 , V_167 , V_169 , V_138 ) ;
V_143 -> V_146 = V_164 ;
if ( V_143 -> V_177 ) {
V_143 -> V_179 -= V_143 -> V_178 ;
V_143 -> V_175 = V_210 + V_143 -> V_215 ;
} else {
V_143 -> V_179 = 0 ;
V_143 -> V_175 += V_210 ;
}
if ( V_206 -> V_207 ) {
V_143 -> V_152 += V_206 -> V_207 -> V_152 ;
V_143 -> V_154 += V_206 -> V_207 -> V_154 ;
}
if ( V_206 -> V_138 )
F_71 ( V_206 -> V_138 ) ;
if ( V_180 && ! V_143 -> V_177 ) {
V_206 -> V_138 = V_138 ;
V_206 -> V_207 = V_143 ;
V_206 -> V_208 ++ ;
} else {
V_211 = V_143 ;
V_206 -> V_138 = NULL ;
V_206 -> V_207 = NULL ;
V_206 -> V_208 = 0 ;
}
} else {
F_69 ( & V_203 , & V_204 , V_206 ) ;
V_211 = V_143 ;
}
if ( V_203 ) {
int V_216 = F_63 ( V_45 , V_203 , V_1 ,
NULL , V_204 ) ;
if ( V_216 != 0 ) {
F_43 ( V_1 ,
V_203 -> V_146 ) ;
F_72 ( V_204 ) ;
}
}
V_213:
if ( V_211 )
V_47 = F_63 ( V_45 , V_211 , V_1 , V_169 , V_138 ) ;
if ( V_47 != 0 && V_164 != V_149 )
F_43 ( V_1 , V_164 ) ;
return V_47 ;
}
static int F_73 ( struct V_132 * V_24 ,
T_4 V_217 , T_2 V_78 )
{
struct V_12 V_218 ;
int V_47 ;
V_218 . V_15 . V_16 =
V_162 ;
V_218 . V_18 . V_50 . V_219 . V_78 = V_78 ;
V_47 = F_3 ( V_24 , & V_218 ,
sizeof( struct V_220 ) + sizeof( T_2 ) ,
V_217 , V_221 , 0 ) ;
return V_47 ;
}
static inline void F_74 ( struct V_9 * V_11 , T_3 V_140 ,
T_2 * V_222 , T_2 * V_223 )
{
struct V_224 * V_28 = & V_11 -> V_27 [ V_140 ] . V_28 ;
T_2 V_225 = V_28 -> V_225 ;
T_2 V_226 = V_28 -> V_226 ;
* V_222 = ( V_225 > V_226 ) ? V_30 - V_225 + V_226 :
V_226 - V_225 ;
* V_223 = V_30 - * V_222 - 1 ;
}
static inline struct V_31 * F_75 ( struct V_9
* V_11 , T_3 V_140 )
{
struct V_224 * V_28 = & V_11 -> V_27 [ V_140 ] . V_28 ;
T_2 V_222 , V_223 ;
if ( F_76 ( ! V_28 -> V_29 ) )
return NULL ;
F_74 ( V_11 , V_140 , & V_222 , & V_223 ) ;
if ( ! V_222 )
return NULL ;
return V_28 -> V_29 + V_28 -> V_225 * sizeof( struct V_31 ) ;
}
static inline void F_77 ( struct V_9 * V_11 , T_3 V_140 )
{
struct V_224 * V_28 = & V_11 -> V_27 [ V_140 ] . V_28 ;
int V_227 ;
V_28 -> V_225 = ( V_28 -> V_225 + 1 ) % V_30 ;
V_227 = F_50 ( & V_11 -> V_228 ) ;
if ( V_11 -> V_33 && V_227 == 0 )
F_51 ( & V_11 -> V_32 ) ;
}
static void F_78 ( struct V_9 * V_11 ,
struct V_132 * V_24 , T_3 V_140 )
{
struct V_31 * V_229 ;
int V_47 ;
while ( true ) {
V_229 = F_75 ( V_11 , V_140 ) ;
if ( ! V_229 )
break;
V_47 = F_73 ( V_24 , V_229 -> V_230 ,
V_229 -> V_78 ) ;
if ( V_47 )
break;
F_77 ( V_11 , V_140 ) ;
}
}
static inline struct V_31 * F_79 (
struct V_9 * V_11 , struct V_132 * V_24 , T_3 V_140 )
{
struct V_224 * V_28 = & V_11 -> V_27 [ V_140 ] . V_28 ;
T_2 V_222 , V_223 , V_226 ;
struct V_31 * V_229 ;
if ( F_76 ( ! V_11 -> V_57 ) )
return NULL ;
if ( F_76 ( ! V_28 -> V_29 ) )
return NULL ;
if ( F_68 ( & V_11 -> V_228 ) >
V_11 -> V_57 -> V_231 * V_232 / 100 )
F_78 ( V_11 , V_24 , V_140 ) ;
F_74 ( V_11 , V_140 , & V_222 , & V_223 ) ;
if ( ! V_223 )
return NULL ;
V_226 = V_28 -> V_226 ;
V_229 = V_28 -> V_29 + V_226 * sizeof( struct V_31 ) ;
V_28 -> V_226 = ( V_226 + 1 ) % V_30 ;
F_80 ( & V_11 -> V_228 ) ;
return V_229 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_9 * V_1 ,
struct V_4 * V_5 ,
struct V_6 * V_45 ,
struct V_132 * V_24 ,
const struct V_134 * V_135 ,
struct V_12 * V_233 )
{
const struct V_234 * V_235
= F_11 ( V_135 , const struct V_234 , V_236 ) ;
T_3 V_140 = V_24 -> V_237 . V_238 . V_239 ;
char * V_56 = V_1 -> V_56 ;
T_2 V_78 = V_79 ;
int V_43 ;
int V_208 = 0 ;
int V_47 ;
if ( F_76 ( V_233 -> V_15 . V_16 != V_195 ) ) {
F_82 ( V_5 , V_240 , V_2 ,
L_21 ,
V_233 -> V_15 . V_16 ) ;
return 0 ;
}
if ( F_76 ( V_235 -> V_241 != V_53 ) ) {
F_82 ( V_5 , V_240 , V_2 ,
L_22 ,
V_53 ,
V_235 -> V_241 ) ;
return 0 ;
}
V_208 = V_235 -> V_242 ;
for ( V_43 = 0 ; V_43 < V_208 ; V_43 ++ ) {
void * V_243 = V_56
+ V_235 -> V_244 [ V_43 ] . V_245 ;
T_2 V_246 = V_235 -> V_244 [ V_43 ] . V_247 ;
V_78 = F_83 ( V_2 , V_1 , V_45 ,
V_24 , V_243 , V_246 ) ;
}
if ( V_1 -> V_27 [ V_140 ] . V_28 . V_29 ) {
struct V_31 * V_229 ;
V_229 = F_79 ( V_1 , V_24 , V_140 ) ;
if ( V_229 ) {
V_229 -> V_230 = V_235 -> V_236 . V_139 ;
V_229 -> V_78 = V_78 ;
} else {
F_21 ( V_2 , L_23 ,
V_140 , V_235 -> V_236 . V_139 ) ;
}
} else {
V_47 = F_73 ( V_24 ,
V_235 -> V_236 . V_139 ,
V_78 ) ;
if ( V_47 )
F_21 ( V_2 , L_24 ,
V_140 , V_235 -> V_236 . V_139 , V_47 ) ;
}
return V_208 ;
}
static void F_84 ( struct V_6 * V_248 ,
struct V_12 * V_186 )
{
struct V_1 * V_2 = F_19 ( V_248 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_43 ;
T_2 V_208 , * V_249 ;
V_208 = V_186 -> V_18 . V_250 . V_251 . V_208 ;
if ( V_208 != V_252 ) {
F_21 ( V_2 , L_25 , V_208 ) ;
return;
}
V_249 = ( T_2 * ) ( ( unsigned long ) & V_186 -> V_18 . V_250 . V_251 +
V_186 -> V_18 . V_250 . V_251 . V_84 ) ;
for ( V_43 = 0 ; V_43 < V_208 ; V_43 ++ )
V_5 -> V_253 [ V_43 ] = V_249 [ V_43 ] ;
}
static void F_85 ( struct V_4 * V_5 ,
struct V_12 * V_186 )
{
V_5 -> V_254 = V_186 -> V_18 . V_19 . V_255 . V_256 ;
V_5 -> V_257 = V_186 -> V_18 . V_19 . V_255 . V_258 ;
}
static inline void F_86 ( struct V_6 * V_248 ,
struct V_4 * V_5 ,
struct V_12 * V_186 )
{
switch ( V_186 -> V_15 . V_16 ) {
case V_259 :
F_84 ( V_248 , V_186 ) ;
break;
case V_260 :
F_85 ( V_5 , V_186 ) ;
break;
}
}
static int F_87 ( struct V_6 * V_45 ,
struct V_132 * V_24 ,
struct V_9 * V_1 ,
struct V_1 * V_2 ,
const struct V_134 * V_135 ,
int V_136 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_12 * V_186 = F_56 ( V_135 ) ;
switch ( V_135 -> type ) {
case V_221 :
F_55 ( V_1 , V_24 , V_45 ,
V_135 , V_136 ) ;
break;
case V_261 :
return F_81 ( V_2 , V_1 , V_5 ,
V_45 , V_24 , V_135 , V_186 ) ;
break;
case V_25 :
F_86 ( V_45 , V_5 , V_186 ) ;
break;
default:
F_21 ( V_2 , L_26 ,
V_135 -> type , V_135 -> V_139 ) ;
break;
}
return 0 ;
}
static struct V_6 * F_88 ( struct V_132 * V_24 )
{
struct V_132 * V_262 = V_24 -> V_263 ;
return V_262 ? V_262 -> V_264 : V_24 -> V_264 ;
}
int F_89 ( struct V_265 * V_125 , int V_136 )
{
struct V_187 * V_188
= F_11 ( V_125 , struct V_187 , V_125 ) ;
struct V_132 * V_24 = V_188 -> V_24 ;
struct V_6 * V_45 = F_88 ( V_24 ) ;
T_3 V_140 = V_24 -> V_237 . V_238 . V_239 ;
struct V_1 * V_2 = F_19 ( V_45 ) ;
struct V_9 * V_1 = F_20 ( V_2 ) ;
int V_266 = 0 ;
if ( ! V_188 -> V_135 )
V_188 -> V_135 = F_90 ( V_24 ) ;
while ( V_188 -> V_135 && V_266 < V_136 ) {
V_266 += F_87 ( V_45 , V_24 , V_1 ,
V_2 , V_188 -> V_135 , V_136 ) ;
V_188 -> V_135 = F_91 ( V_24 , V_188 -> V_135 ) ;
}
if ( V_266 < V_136 &&
F_92 ( V_125 , V_266 ) &&
F_93 ( & V_24 -> V_267 ) != 0 )
F_94 ( V_125 ) ;
F_78 ( V_1 , V_24 , V_140 ) ;
return F_95 ( V_266 , V_136 ) ;
}
void F_96 ( void * V_268 )
{
struct V_187 * V_188 = V_268 ;
if ( F_97 ( & V_188 -> V_125 ) ) {
F_98 ( & V_188 -> V_24 -> V_267 ) ;
F_99 ( & V_188 -> V_125 ) ;
}
}
int F_100 ( struct V_6 * V_45 ,
const struct V_269 * V_270 )
{
int V_43 , V_47 = 0 ;
int V_271 = V_270 -> V_271 ;
struct V_9 * V_1 ;
struct V_1 * V_2 = F_19 ( V_45 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_1 = F_4 () ;
if ( ! V_1 )
return - V_71 ;
V_1 -> V_271 = V_271 ;
F_101 ( V_45 -> V_24 , V_272 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
struct V_187 * V_188 = & V_1 -> V_27 [ V_43 ] ;
V_188 -> V_24 = V_45 -> V_24 ;
}
F_102 ( V_2 , & V_1 -> V_27 [ 0 ] . V_125 ,
F_89 , V_273 ) ;
V_47 = F_103 ( V_45 -> V_24 , V_271 * V_274 ,
V_271 * V_274 , NULL , 0 ,
F_96 ,
V_1 -> V_27 ) ;
if ( V_47 != 0 ) {
F_40 ( & V_1 -> V_27 [ 0 ] . V_125 ) ;
F_21 ( V_2 , L_27 , V_47 ) ;
goto V_72;
}
F_29 ( V_2 , L_28 ) ;
F_104 ( & V_1 -> V_27 [ 0 ] . V_125 ) ;
F_105 ( V_5 -> V_11 , V_1 ) ;
V_47 = F_33 ( V_45 ) ;
if ( V_47 != 0 ) {
F_21 ( V_2 ,
L_29 , V_47 ) ;
goto V_275;
}
return V_47 ;
V_275:
F_40 ( & V_1 -> V_27 [ 0 ] . V_125 ) ;
F_39 ( V_45 -> V_24 ) ;
V_72:
F_10 ( & V_1 -> V_42 ) ;
return V_47 ;
}
