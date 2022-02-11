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
static void F_10 ( struct V_9 * V_11 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ )
F_11 ( V_11 -> V_27 [ V_40 ] . V_28 . V_29 ) ;
F_12 ( V_11 ) ;
}
static inline bool F_13 ( const struct V_9 * V_1 ,
T_1 V_42 )
{
const struct V_43 * V_44 = & V_1 -> V_27 [ V_42 ] ;
return F_14 ( & V_1 -> V_45 ) == 0 &&
F_14 ( & V_44 -> V_46 ) == 0 ;
}
static struct V_9 * F_15 ( struct V_6 * V_47 )
{
struct V_9 * V_1 = F_16 ( V_47 ) ;
if ( V_1 && V_1 -> V_33 )
V_1 = NULL ;
return V_1 ;
}
static void F_17 ( struct V_6 * V_47 )
{
struct V_12 * V_48 ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
struct V_9 * V_1 = F_19 ( V_2 ) ;
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
if ( V_49 != 0 ) {
F_20 ( V_2 , L_1
L_2 ) ;
return;
}
}
if ( V_1 -> V_56 ) {
V_49 = F_21 ( V_47 -> V_24 ,
V_1 -> V_56 ) ;
if ( V_49 != 0 ) {
F_20 ( V_2 ,
L_3 ) ;
return;
}
V_1 -> V_56 = 0 ;
}
if ( V_1 -> V_57 ) {
F_11 ( V_1 -> V_57 ) ;
V_1 -> V_57 = NULL ;
}
if ( V_1 -> V_58 ) {
V_1 -> V_50 = 0 ;
F_12 ( V_1 -> V_58 ) ;
V_1 -> V_58 = NULL ;
}
if ( V_1 -> V_59 ) {
V_48 = & V_1 -> V_48 ;
memset ( V_48 , 0 , sizeof( struct V_12 ) ) ;
V_48 -> V_15 . V_16 =
V_60 ;
V_48 -> V_18 . V_52 . V_61 . V_54 =
V_62 ;
V_49 = F_3 ( V_47 -> V_24 ,
V_48 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_48 ,
V_25 , 0 ) ;
if ( V_49 != 0 ) {
F_20 ( V_2 , L_1
L_4 ) ;
return;
}
}
if ( V_1 -> V_63 ) {
V_49 = F_21 ( V_47 -> V_24 ,
V_1 -> V_63 ) ;
if ( V_49 != 0 ) {
F_20 ( V_2 ,
L_5 ) ;
return;
}
V_1 -> V_63 = 0 ;
}
if ( V_1 -> V_64 ) {
F_11 ( V_1 -> V_64 ) ;
V_1 -> V_64 = NULL ;
}
F_12 ( V_1 -> V_65 ) ;
}
static int F_22 ( struct V_6 * V_47 )
{
int V_49 = 0 ;
struct V_9 * V_1 ;
struct V_12 * V_66 ;
struct V_1 * V_2 ;
T_2 V_67 ;
int V_68 ;
V_1 = F_15 ( V_47 ) ;
if ( ! V_1 )
return - V_69 ;
V_2 = F_18 ( V_47 ) ;
V_68 = F_23 ( V_47 -> V_24 -> V_70 ) ;
V_1 -> V_57 = F_24 ( V_1 -> V_71 , V_68 ) ;
if ( ! V_1 -> V_57 )
V_1 -> V_57 = F_6 ( V_1 -> V_71 ) ;
if ( ! V_1 -> V_57 ) {
F_20 ( V_2 , L_6
L_7 , V_1 -> V_71 ) ;
V_49 = - V_72 ;
goto V_73;
}
V_49 = F_25 ( V_47 -> V_24 , V_1 -> V_57 ,
V_1 -> V_71 ,
& V_1 -> V_56 ) ;
if ( V_49 != 0 ) {
F_20 ( V_2 ,
L_8 ) ;
goto V_73;
}
V_66 = & V_1 -> V_14 ;
memset ( V_66 , 0 , sizeof( struct V_12 ) ) ;
V_66 -> V_15 . V_16 = V_74 ;
V_66 -> V_18 . V_52 . V_75 .
V_76 = V_1 -> V_56 ;
V_66 -> V_18 . V_52 .
V_75 . V_54 = V_55 ;
V_49 = F_3 ( V_47 -> V_24 , V_66 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_66 ,
V_25 ,
V_77 ) ;
if ( V_49 != 0 ) {
F_20 ( V_2 ,
L_9 ) ;
goto V_73;
}
F_26 ( & V_1 -> V_39 ) ;
if ( V_66 -> V_18 . V_52 .
V_78 . V_79 != V_80 ) {
F_20 ( V_2 , L_10
L_11 ,
V_66 -> V_18 . V_52 .
V_78 . V_79 ) ;
V_49 = - V_81 ;
goto V_73;
}
V_1 -> V_50 = V_66 -> V_18 .
V_52 . V_78 . V_82 ;
V_1 -> V_58 = F_27 (
V_66 -> V_18 . V_52 . V_78 . V_83 ,
V_1 -> V_50 *
sizeof( struct V_84 ) ,
V_26 ) ;
if ( V_1 -> V_58 == NULL ) {
V_49 = - V_81 ;
goto V_73;
}
if ( V_1 -> V_50 != 1 ||
V_1 -> V_58 -> V_85 != 0 ) {
V_49 = - V_81 ;
goto V_73;
}
V_1 -> V_64 = F_24 ( V_1 -> V_86 , V_68 ) ;
if ( ! V_1 -> V_64 )
V_1 -> V_64 = F_6 ( V_1 -> V_86 ) ;
if ( ! V_1 -> V_64 ) {
F_20 ( V_2 , L_12
L_7 , V_1 -> V_86 ) ;
V_49 = - V_72 ;
goto V_73;
}
V_49 = F_25 ( V_47 -> V_24 , V_1 -> V_64 ,
V_1 -> V_86 ,
& V_1 -> V_63 ) ;
if ( V_49 != 0 ) {
F_20 ( V_2 ,
L_13 ) ;
goto V_73;
}
V_66 = & V_1 -> V_14 ;
memset ( V_66 , 0 , sizeof( struct V_12 ) ) ;
V_66 -> V_15 . V_16 = V_87 ;
V_66 -> V_18 . V_52 . V_88 . V_76 =
V_1 -> V_63 ;
V_66 -> V_18 . V_52 . V_88 . V_54 = V_62 ;
V_49 = F_3 ( V_47 -> V_24 , V_66 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_66 ,
V_25 ,
V_77 ) ;
if ( V_49 != 0 ) {
F_20 ( V_2 ,
L_14 ) ;
goto V_73;
}
F_26 ( & V_1 -> V_39 ) ;
if ( V_66 -> V_18 . V_52 .
V_89 . V_79 != V_80 ) {
F_20 ( V_2 , L_15
L_11 ,
V_66 -> V_18 . V_52 .
V_89 . V_79 ) ;
V_49 = - V_81 ;
goto V_73;
}
V_1 -> V_59 = V_66 -> V_18 .
V_52 . V_89 . V_90 ;
V_1 -> V_91 =
V_1 -> V_86 / V_1 -> V_59 ;
F_28 ( V_2 , L_16 ,
V_1 -> V_59 , V_1 -> V_91 ) ;
V_67 = F_29 ( V_1 -> V_91 , V_92 ) ;
V_1 -> V_65 = F_30 ( V_67 , sizeof( V_93 ) , V_26 ) ;
if ( V_1 -> V_65 == NULL ) {
V_49 = - V_72 ;
goto V_73;
}
goto exit;
V_73:
F_17 ( V_47 ) ;
exit:
return V_49 ;
}
static int F_31 ( struct V_6 * V_47 ,
struct V_9 * V_1 ,
struct V_12 * V_66 ,
T_3 V_94 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
int V_49 ;
memset ( V_66 , 0 , sizeof( struct V_12 ) ) ;
V_66 -> V_15 . V_16 = V_95 ;
V_66 -> V_18 . V_96 . V_97 . V_98 = V_94 ;
V_66 -> V_18 . V_96 . V_97 . V_99 = V_94 ;
V_49 = F_3 ( V_47 -> V_24 , V_66 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_66 ,
V_25 ,
V_77 ) ;
if ( V_49 != 0 )
return V_49 ;
F_26 ( & V_1 -> V_39 ) ;
if ( V_66 -> V_18 . V_96 . V_100 . V_79 !=
V_80 )
return - V_81 ;
if ( V_94 == V_101 )
return 0 ;
memset ( V_66 , 0 , sizeof( struct V_12 ) ) ;
V_66 -> V_15 . V_16 = V_102 ;
V_66 -> V_18 . V_103 . V_104 . V_105 = V_2 -> V_105 + V_106 ;
V_66 -> V_18 . V_103 . V_104 . V_107 . V_108 = 1 ;
if ( V_94 >= V_109 ) {
V_66 -> V_18 . V_103 . V_104 . V_107 . V_110 = 1 ;
V_66 -> V_18 . V_103 . V_104 . V_107 . V_111 = 1 ;
}
V_49 = F_3 ( V_47 -> V_24 , V_66 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_66 ,
V_25 , 0 ) ;
return V_49 ;
}
static int F_32 ( struct V_6 * V_47 )
{
int V_49 ;
struct V_9 * V_1 ;
struct V_12 * V_66 ;
int V_112 ;
const T_3 V_113 [] = {
V_101 , V_114 ,
V_115 , V_109 } ;
int V_40 ;
V_1 = F_15 ( V_47 ) ;
if ( ! V_1 )
return - V_69 ;
V_66 = & V_1 -> V_14 ;
for ( V_40 = F_33 ( V_113 ) - 1 ; V_40 >= 0 ; V_40 -- )
if ( F_31 ( V_47 , V_1 , V_66 ,
V_113 [ V_40 ] ) == 0 ) {
V_1 -> V_116 = V_113 [ V_40 ] ;
break;
}
if ( V_40 < 0 ) {
V_49 = - V_117 ;
goto V_73;
}
F_34 ( L_17 , V_1 -> V_116 ) ;
memset ( V_66 , 0 , sizeof( struct V_12 ) ) ;
if ( V_1 -> V_116 <= V_115 )
V_112 = 0x00060001 ;
else
V_112 = 0x0006001e ;
V_66 -> V_15 . V_16 = V_118 ;
V_66 -> V_18 . V_52 .
V_119 . V_120 =
( V_112 & 0xFFFF0000 ) >> 16 ;
V_66 -> V_18 . V_52 .
V_119 . V_121 =
V_112 & 0xFFFF ;
V_49 = F_3 ( V_47 -> V_24 , V_66 ,
sizeof( struct V_12 ) ,
( unsigned long ) V_66 ,
V_25 , 0 ) ;
if ( V_49 != 0 )
goto V_73;
if ( V_1 -> V_116 <= V_114 )
V_1 -> V_71 = V_122 ;
else
V_1 -> V_71 = V_123 ;
V_1 -> V_86 = V_124 ;
V_49 = F_22 ( V_47 ) ;
V_73:
return V_49 ;
}
static void F_35 ( struct V_6 * V_47 )
{
F_17 ( V_47 ) ;
}
void F_36 ( struct V_6 * V_47 )
{
struct V_1 * V_2 = F_18 ( V_47 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_9 * V_1 = V_5 -> V_11 ;
F_35 ( V_47 ) ;
V_5 -> V_11 = NULL ;
F_28 ( V_2 , L_18 ) ;
F_37 ( V_47 -> V_24 ) ;
F_10 ( V_1 ) ;
}
static inline T_3 F_38 (
struct V_125 * V_126 )
{
T_3 V_127 , V_128 ;
F_39 ( V_126 , & V_127 , & V_128 ) ;
return V_128 * 100 / V_126 -> V_129 ;
}
static inline void F_40 ( struct V_9 * V_1 ,
T_3 V_130 )
{
F_41 ( V_130 , V_1 -> V_65 ) ;
}
static void F_42 ( struct V_9 * V_1 ,
struct V_131 * V_132 ,
struct V_6 * V_47 ,
struct V_133 * V_134 )
{
struct V_135 * V_136 = (struct V_135 * ) ( unsigned long ) V_134 -> V_137 ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_131 * V_24 = V_47 -> V_24 ;
T_1 V_42 = 0 ;
int V_46 ;
if ( F_43 ( V_136 ) ) {
const struct V_138 * V_134
= (struct V_138 * ) V_136 -> V_139 ;
T_3 V_140 = V_134 -> V_141 ;
struct V_142 * V_143 ;
if ( V_140 != V_144 )
F_40 ( V_1 , V_140 ) ;
V_42 = V_134 -> V_42 ;
V_24 = V_132 ;
V_143 = & V_1 -> V_27 [ V_42 ] . V_143 ;
F_44 ( & V_143 -> V_145 ) ;
V_143 -> V_146 += V_134 -> V_147 ;
V_143 -> V_148 += V_134 -> V_149 ;
F_45 ( & V_143 -> V_145 ) ;
F_46 ( V_136 ) ;
}
V_46 =
F_47 ( & V_1 -> V_27 [ V_42 ] . V_46 ) ;
if ( V_1 -> V_33 && V_46 == 0 )
F_48 ( & V_1 -> V_32 ) ;
if ( F_49 ( F_50 ( V_2 , V_42 ) ) &&
! V_5 -> V_150 &&
( F_38 ( & V_24 -> V_151 ) > V_152 ||
V_46 < 1 ) )
F_51 ( F_50 ( V_2 , V_42 ) ) ;
}
static void F_52 ( struct V_9 * V_1 ,
struct V_131 * V_132 ,
struct V_6 * V_47 ,
struct V_133 * V_134 )
{
struct V_12 * V_153 ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
V_153 = (struct V_12 * ) ( ( unsigned long ) V_134 +
( V_134 -> V_154 << 3 ) ) ;
switch ( V_153 -> V_15 . V_16 ) {
case V_155 :
case V_156 :
case V_157 :
case V_158 :
memcpy ( & V_1 -> V_14 , V_153 ,
sizeof( struct V_12 ) ) ;
F_53 ( & V_1 -> V_39 ) ;
break;
case V_159 :
F_42 ( V_1 , V_132 ,
V_47 , V_134 ) ;
break;
default:
F_20 ( V_2 ,
L_19 ,
V_153 -> V_15 . V_16 ) ;
}
}
static T_3 F_54 ( struct V_9 * V_1 )
{
unsigned long * V_160 = V_1 -> V_65 ;
unsigned int V_40 ;
F_55 (i, map_addr, net_device->send_section_cnt) {
if ( F_56 ( V_40 , V_160 ) == 0 )
return V_40 ;
}
return V_144 ;
}
static T_3 F_57 ( struct V_9 * V_1 ,
unsigned int V_161 ,
T_3 V_162 ,
struct V_138 * V_134 ,
struct V_163 * V_164 ,
struct V_165 * * V_166 ,
struct V_135 * V_136 )
{
char * V_167 = V_1 -> V_64 ;
char * V_168 = V_167 + ( V_161 * V_1 -> V_59 )
+ V_162 ;
int V_40 ;
T_3 V_169 = 0 ;
T_3 V_170 = 0 ;
T_3 V_171 = V_134 -> V_172 % V_1 -> V_37 ;
T_3 V_173 = V_134 -> V_174 ? V_134 -> V_175 :
V_134 -> V_176 ;
if ( V_136 && V_136 -> V_177 && V_171 &&
! V_134 -> V_174 ) {
V_170 = V_1 -> V_37 - V_171 ;
V_164 -> V_178 += V_170 ;
V_134 -> V_172 += V_170 ;
}
for ( V_40 = 0 ; V_40 < V_173 ; V_40 ++ ) {
char * V_179 = F_58 ( ( * V_166 ) [ V_40 ] . V_180 << V_181 ) ;
T_3 V_85 = ( * V_166 ) [ V_40 ] . V_85 ;
T_3 V_182 = ( * V_166 ) [ V_40 ] . V_182 ;
memcpy ( V_168 , ( V_179 + V_85 ) , V_182 ) ;
V_169 += V_182 ;
V_168 += V_182 ;
}
if ( V_170 ) {
memset ( V_168 , 0 , V_170 ) ;
V_169 += V_170 ;
}
return V_169 ;
}
static inline int F_59 (
struct V_6 * V_47 ,
struct V_138 * V_134 ,
struct V_9 * V_1 ,
struct V_165 * * V_166 ,
struct V_135 * V_136 )
{
struct V_12 V_183 ;
struct V_43 * V_44
= & V_1 -> V_27 [ V_134 -> V_42 ] ;
struct V_131 * V_184 = V_44 -> V_24 ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
struct V_185 * V_186 = F_50 ( V_2 , V_134 -> V_42 ) ;
T_4 V_187 ;
int V_49 ;
struct V_165 * V_188 ;
T_3 V_189 = F_38 ( & V_184 -> V_151 ) ;
V_183 . V_15 . V_16 = V_190 ;
if ( V_136 != NULL ) {
V_183 . V_18 . V_52 . V_191 . V_192 = 0 ;
} else {
V_183 . V_18 . V_52 . V_191 . V_192 = 1 ;
}
V_183 . V_18 . V_52 . V_191 . V_193 =
V_134 -> V_141 ;
if ( V_134 -> V_141 == V_144 )
V_183 . V_18 . V_52 . V_191 . V_194 = 0 ;
else
V_183 . V_18 . V_52 . V_191 . V_194 =
V_134 -> V_172 ;
V_187 = ( V_93 ) V_136 ;
if ( V_184 -> V_195 )
return - V_69 ;
if ( V_134 -> V_176 ) {
V_188 = V_134 -> V_174 ? ( * V_166 ) +
V_134 -> V_175 : ( * V_166 ) ;
V_49 = F_60 ( V_184 ,
V_188 ,
V_134 -> V_176 ,
& V_183 ,
sizeof( struct V_12 ) ,
V_187 ,
V_77 ) ;
} else {
V_49 = F_61 ( V_184 , & V_183 ,
sizeof( struct V_12 ) ,
V_187 ,
V_25 ,
V_77 ) ;
}
if ( V_49 == 0 ) {
F_62 ( & V_44 -> V_46 ) ;
if ( V_189 < V_196 )
F_63 ( V_186 ) ;
} else if ( V_49 == - V_197 ) {
F_63 ( V_186 ) ;
if ( F_14 ( & V_44 -> V_46 ) < 1 ) {
F_51 ( V_186 ) ;
V_49 = - V_198 ;
}
} else {
F_20 ( V_2 , L_20 ,
V_134 , V_49 ) ;
}
return V_49 ;
}
static inline void F_64 ( struct V_138 * * V_199 ,
struct V_135 * * V_200 ,
struct V_201 * V_202 )
{
* V_200 = V_202 -> V_136 ;
* V_199 = V_202 -> V_203 ;
V_202 -> V_136 = NULL ;
V_202 -> V_203 = NULL ;
V_202 -> V_204 = 0 ;
}
int F_65 ( struct V_6 * V_47 ,
struct V_138 * V_134 ,
struct V_163 * V_164 ,
struct V_165 * * V_166 ,
struct V_135 * V_136 )
{
struct V_9 * V_1 ;
int V_49 = 0 ;
struct V_43 * V_44 ;
T_3 V_205 = V_134 -> V_172 , V_206 = 0 ;
unsigned int V_161 = V_144 ;
struct V_201 * V_202 ;
struct V_138 * V_199 = NULL , * V_207 = NULL ;
struct V_135 * V_200 = NULL ;
bool V_208 ;
bool V_177 = ( V_136 != NULL ) ? V_136 -> V_177 : false ;
V_1 = F_15 ( V_47 ) ;
if ( ! V_1 )
return - V_69 ;
if ( ! V_1 -> V_65 )
return - V_197 ;
V_44 = & V_1 -> V_27 [ V_134 -> V_42 ] ;
V_134 -> V_141 = V_144 ;
V_134 -> V_174 = false ;
if ( ! V_136 ) {
V_207 = V_134 ;
goto V_209;
}
V_202 = & V_44 -> V_210 ;
if ( V_202 -> V_203 )
V_206 = V_202 -> V_203 -> V_172 ;
V_208 = ( V_136 != NULL ) && V_206 > 0 && V_202 -> V_204 <
V_1 -> V_35 ;
if ( V_208 && V_206 + V_205 + V_1 -> V_37 <
V_1 -> V_59 ) {
V_161 = V_202 -> V_203 -> V_141 ;
} else if ( V_208 && V_206 + V_134 -> V_211 <
V_1 -> V_59 ) {
V_161 = V_202 -> V_203 -> V_141 ;
V_134 -> V_174 = true ;
} else if ( ( V_136 != NULL ) && V_205 + V_1 -> V_37 <
V_1 -> V_59 ) {
V_161 = F_54 ( V_1 ) ;
if ( V_161 != V_144 ) {
F_64 ( & V_199 , & V_200 , V_202 ) ;
V_206 = 0 ;
}
}
if ( V_161 != V_144 ) {
F_57 ( V_1 ,
V_161 , V_206 ,
V_134 , V_164 , V_166 , V_136 ) ;
V_134 -> V_141 = V_161 ;
if ( V_134 -> V_174 ) {
V_134 -> V_176 -= V_134 -> V_175 ;
V_134 -> V_172 = V_206 + V_134 -> V_211 ;
} else {
V_134 -> V_176 = 0 ;
V_134 -> V_172 += V_206 ;
}
if ( V_202 -> V_203 ) {
V_134 -> V_147 += V_202 -> V_203 -> V_147 ;
V_134 -> V_149 += V_202 -> V_203 -> V_149 ;
}
if ( V_202 -> V_136 )
F_46 ( V_202 -> V_136 ) ;
if ( V_177 && ! V_134 -> V_174 ) {
V_202 -> V_136 = V_136 ;
V_202 -> V_203 = V_134 ;
V_202 -> V_204 ++ ;
} else {
V_207 = V_134 ;
V_202 -> V_136 = NULL ;
V_202 -> V_203 = NULL ;
V_202 -> V_204 = 0 ;
}
} else {
F_64 ( & V_199 , & V_200 , V_202 ) ;
V_207 = V_134 ;
}
if ( V_199 ) {
int V_212 = F_59 ( V_47 , V_199 , V_1 ,
NULL , V_200 ) ;
if ( V_212 != 0 ) {
F_40 ( V_1 ,
V_199 -> V_141 ) ;
F_66 ( V_200 ) ;
}
}
V_209:
if ( V_207 )
V_49 = F_59 ( V_47 , V_207 , V_1 , V_166 , V_136 ) ;
if ( V_49 != 0 && V_161 != V_144 )
F_40 ( V_1 , V_161 ) ;
return V_49 ;
}
static int F_67 ( struct V_131 * V_24 ,
T_4 V_213 , T_3 V_79 )
{
struct V_12 V_214 ;
int V_49 ;
V_214 . V_15 . V_16 =
V_159 ;
V_214 . V_18 . V_52 . V_215 . V_79 = V_79 ;
V_49 = F_3 ( V_24 , & V_214 ,
sizeof( struct V_216 ) + sizeof( T_3 ) ,
V_213 , V_217 , 0 ) ;
return V_49 ;
}
static inline void F_68 ( struct V_9 * V_11 , T_1 V_42 ,
T_3 * V_218 , T_3 * V_219 )
{
struct V_220 * V_28 = & V_11 -> V_27 [ V_42 ] . V_28 ;
T_3 V_221 = V_28 -> V_221 ;
T_3 V_222 = V_28 -> V_222 ;
* V_218 = ( V_221 > V_222 ) ? V_30 - V_221 + V_222 :
V_222 - V_221 ;
* V_219 = V_30 - * V_218 - 1 ;
}
static inline struct V_31 * F_69 ( struct V_9
* V_11 , T_1 V_42 )
{
struct V_220 * V_28 = & V_11 -> V_27 [ V_42 ] . V_28 ;
T_3 V_218 , V_219 ;
if ( F_70 ( ! V_28 -> V_29 ) )
return NULL ;
F_68 ( V_11 , V_42 , & V_218 , & V_219 ) ;
if ( ! V_218 )
return NULL ;
return V_28 -> V_29 + V_28 -> V_221 * sizeof( struct V_31 ) ;
}
static inline void F_71 ( struct V_9 * V_11 , T_1 V_42 )
{
struct V_220 * V_28 = & V_11 -> V_27 [ V_42 ] . V_28 ;
int V_223 ;
V_28 -> V_221 = ( V_28 -> V_221 + 1 ) % V_30 ;
V_223 = F_47 ( & V_11 -> V_45 ) ;
if ( V_11 -> V_33 && V_223 == 0 )
F_48 ( & V_11 -> V_32 ) ;
}
static void F_72 ( struct V_9 * V_11 ,
struct V_131 * V_24 , T_1 V_42 )
{
struct V_31 * V_224 ;
int V_49 ;
while ( true ) {
V_224 = F_69 ( V_11 , V_42 ) ;
if ( ! V_224 )
break;
V_49 = F_67 ( V_24 , V_224 -> V_225 ,
V_224 -> V_79 ) ;
if ( V_49 )
break;
F_71 ( V_11 , V_42 ) ;
}
}
static inline struct V_31 * F_73 (
struct V_9 * V_11 , struct V_131 * V_24 , T_1 V_42 )
{
struct V_220 * V_28 = & V_11 -> V_27 [ V_42 ] . V_28 ;
T_3 V_218 , V_219 , V_222 ;
struct V_31 * V_224 ;
if ( F_70 ( ! V_11 -> V_58 ) )
return NULL ;
if ( F_70 ( ! V_28 -> V_29 ) )
return NULL ;
if ( F_14 ( & V_11 -> V_45 ) >
V_11 -> V_58 -> V_226 * V_227 / 100 )
F_72 ( V_11 , V_24 , V_42 ) ;
F_68 ( V_11 , V_42 , & V_218 , & V_219 ) ;
if ( ! V_219 )
return NULL ;
V_222 = V_28 -> V_222 ;
V_224 = V_28 -> V_29 + V_222 * sizeof( struct V_31 ) ;
V_28 -> V_222 = ( V_222 + 1 ) % V_30 ;
F_74 ( & V_11 -> V_45 ) ;
return V_224 ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_9 * V_1 ,
struct V_4 * V_5 ,
struct V_6 * V_47 ,
struct V_131 * V_24 ,
struct V_228 * V_229 ,
struct V_12 * V_230 )
{
char * V_57 = V_1 -> V_57 ;
T_3 V_79 = V_80 ;
int V_40 ;
int V_204 = 0 ;
int V_49 ;
struct V_31 * V_224 ;
T_1 V_42 = V_24 -> V_231 . V_232 . V_233 ;
if ( F_70 ( V_230 -> V_15 . V_16 != V_190 ) ) {
F_76 ( V_5 , V_234 , V_2 ,
L_21 ,
V_230 -> V_15 . V_16 ) ;
return;
}
if ( F_70 ( V_229 -> V_235 != V_55 ) ) {
F_76 ( V_5 , V_234 , V_2 ,
L_22 ,
V_55 ,
V_229 -> V_235 ) ;
return;
}
V_204 = V_229 -> V_236 ;
for ( V_40 = 0 ; V_40 < V_204 ; V_40 ++ ) {
void * V_237 = V_57
+ V_229 -> V_238 [ V_40 ] . V_239 ;
T_3 V_240 = V_229 -> V_238 [ V_40 ] . V_241 ;
V_79 = F_77 ( V_2 , V_1 , V_47 ,
V_24 , V_237 , V_240 ) ;
}
if ( ! V_1 -> V_27 [ V_42 ] . V_28 . V_29 ) {
V_49 = F_67 ( V_24 ,
V_229 -> V_242 . V_137 ,
V_79 ) ;
if ( V_49 )
F_20 ( V_2 , L_23 ,
V_42 , V_229 -> V_242 . V_137 , V_49 ) ;
return;
}
V_224 = F_73 ( V_1 , V_24 , V_42 ) ;
if ( ! V_224 ) {
F_20 ( V_2 , L_24 ,
V_42 , V_229 -> V_242 . V_137 ) ;
return;
}
V_224 -> V_225 = V_229 -> V_242 . V_137 ;
V_224 -> V_79 = V_79 ;
}
static void F_78 ( struct V_6 * V_243 ,
struct V_12 * V_183 )
{
struct V_1 * V_2 = F_18 ( V_243 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_40 ;
T_3 V_204 , * V_244 ;
V_204 = V_183 -> V_18 . V_245 . V_246 . V_204 ;
if ( V_204 != V_247 ) {
F_20 ( V_2 , L_25 , V_204 ) ;
return;
}
V_244 = ( T_3 * ) ( ( unsigned long ) & V_183 -> V_18 . V_245 . V_246 +
V_183 -> V_18 . V_245 . V_246 . V_85 ) ;
for ( V_40 = 0 ; V_40 < V_204 ; V_40 ++ )
V_5 -> V_248 [ V_40 ] = V_244 [ V_40 ] ;
}
static void F_79 ( struct V_4 * V_5 ,
struct V_12 * V_183 )
{
V_5 -> V_249 = V_183 -> V_18 . V_19 . V_250 . V_251 ;
V_5 -> V_252 = V_183 -> V_18 . V_19 . V_250 . V_253 ;
}
static inline void F_80 ( struct V_6 * V_243 ,
struct V_4 * V_5 ,
struct V_12 * V_183 )
{
switch ( V_183 -> V_15 . V_16 ) {
case V_254 :
F_78 ( V_243 , V_183 ) ;
break;
case V_255 :
F_79 ( V_5 , V_183 ) ;
break;
}
}
static void F_81 ( struct V_6 * V_47 ,
struct V_131 * V_24 ,
struct V_9 * V_1 ,
struct V_1 * V_2 ,
T_4 V_256 ,
struct V_133 * V_257 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_12 * V_183
= (struct V_12 * ) ( ( unsigned long ) V_257
+ ( V_257 -> V_154 << 3 ) ) ;
switch ( V_257 -> type ) {
case V_217 :
F_52 ( V_1 , V_24 , V_47 , V_257 ) ;
break;
case V_258 :
F_75 ( V_2 , V_1 , V_5 ,
V_47 , V_24 ,
(struct V_228 * ) V_257 ,
V_183 ) ;
break;
case V_25 :
F_80 ( V_47 , V_5 , V_183 ) ;
break;
default:
F_20 ( V_2 , L_26 ,
V_257 -> type , V_256 ) ;
break;
}
}
void F_82 ( void * V_259 )
{
struct V_131 * V_24 = V_259 ;
T_1 V_42 = V_24 -> V_231 . V_232 . V_233 ;
struct V_6 * V_47 ;
struct V_9 * V_1 ;
struct V_133 * V_257 ;
struct V_1 * V_2 ;
bool V_260 = false ;
if ( V_24 -> V_261 != NULL )
V_47 = V_24 -> V_261 -> V_262 ;
else
V_47 = V_24 -> V_262 ;
V_2 = F_18 ( V_47 ) ;
if ( F_70 ( ! V_2 ) )
return;
V_1 = F_19 ( V_2 ) ;
if ( F_70 ( ! V_1 ) )
return;
if ( F_70 ( V_1 -> V_33 &&
F_13 ( V_1 , V_42 ) ) )
return;
F_83 ( V_24 ) ;
while ( ( V_257 = F_84 ( V_24 ) ) != NULL ) {
F_81 ( V_47 , V_24 , V_1 ,
V_2 , V_257 -> V_137 , V_257 ) ;
F_85 ( V_24 , V_257 ) ;
V_260 = true ;
}
if ( V_260 )
F_86 ( V_24 ) ;
F_72 ( V_1 , V_24 , V_42 ) ;
}
int F_87 ( struct V_6 * V_47 ,
const struct V_263 * V_264 )
{
int V_40 , V_49 = 0 ;
int V_265 = V_264 -> V_265 ;
struct V_9 * V_1 ;
struct V_1 * V_2 = F_18 ( V_47 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_1 = F_4 () ;
if ( ! V_1 )
return - V_72 ;
V_1 -> V_265 = V_265 ;
V_49 = F_88 ( V_47 -> V_24 , V_265 * V_266 ,
V_265 * V_266 , NULL , 0 ,
F_82 , V_47 -> V_24 ) ;
if ( V_49 != 0 ) {
F_20 ( V_2 , L_27 , V_49 ) ;
goto V_73;
}
F_28 ( V_2 , L_28 ) ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ )
V_1 -> V_27 [ V_40 ] . V_24 = V_47 -> V_24 ;
F_89 () ;
V_5 -> V_11 = V_1 ;
V_49 = F_32 ( V_47 ) ;
if ( V_49 != 0 ) {
F_20 ( V_2 ,
L_29 , V_49 ) ;
goto V_267;
}
return V_49 ;
V_267:
F_37 ( V_47 -> V_24 ) ;
V_73:
F_10 ( V_1 ) ;
return V_49 ;
}
