static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_6 , V_7 ) ;
V_2 -> V_8 = V_9 ;
return V_2 ;
}
static struct V_10 * F_6 ( struct V_1 * V_11 ,
T_1 V_12 ,
T_1 V_13 )
{
struct V_10 * V_14 ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
unsigned long V_19 ;
V_14 = F_2 ( sizeof( struct V_10 ) , V_3 ) ;
if ( ! V_14 )
return NULL ;
F_7 ( & V_14 -> V_20 ) ;
V_16 = & V_14 -> V_21 ;
V_16 -> V_22 = V_12 ;
V_16 -> V_13 = V_13 ;
V_14 -> V_23 . V_24 = 0 ;
V_18 = & V_16 -> V_25 . V_26 ;
V_18 -> V_27 = F_8 ( & V_11 -> V_28 ) ;
F_9 ( & V_11 -> V_4 , V_19 ) ;
F_10 ( & V_14 -> V_29 , & V_11 -> V_5 ) ;
F_11 ( & V_11 -> V_4 , V_19 ) ;
return V_14 ;
}
static void F_12 ( struct V_1 * V_11 ,
struct V_10 * V_30 )
{
unsigned long V_19 ;
F_9 ( & V_11 -> V_4 , V_19 ) ;
F_13 ( & V_30 -> V_29 ) ;
F_11 ( & V_11 -> V_4 , V_19 ) ;
F_14 ( V_30 ) ;
}
static void F_15 ( struct V_31 * V_32 ,
const struct V_15 * V_16 )
{
struct V_33 * V_34 = F_16 ( V_32 ) ;
switch ( V_16 -> V_22 ) {
case V_35 :
F_17 ( V_34 , L_1
L_2
L_3
L_4 ,
V_16 -> V_13 ,
V_16 -> V_25 . V_23 . V_36 ,
V_16 -> V_25 . V_23 . V_37 ,
V_16 -> V_25 . V_23 . V_38 ,
V_16 -> V_25 . V_23 . V_39 ,
V_16 -> V_25 . V_23 . V_40 ,
V_16 -> V_25 . V_23 . V_41 ,
V_16 -> V_25 . V_23 . V_42 ) ;
break;
case V_43 :
F_17 ( V_34 , L_5
L_6
L_7
L_8 ,
V_16 -> V_13 ,
V_16 -> V_25 . V_44 . V_27 ,
V_16 -> V_25 . V_44 . V_45 ,
V_16 -> V_25 . V_44 . V_46 ,
V_16 -> V_25 . V_44 . V_47 ,
V_16 -> V_25 . V_44 . V_48 ,
V_16 -> V_25 . V_44 . V_49 ,
V_16 -> V_25 . V_44 .
V_50 ,
V_16 -> V_25 . V_44 .
V_51 ) ;
break;
case V_52 :
F_17 ( V_34 , L_9
L_10
L_11 ,
V_16 -> V_13 ,
V_16 -> V_25 . V_53 . V_27 ,
V_16 -> V_25 . V_53 . V_45 ,
V_16 -> V_25 . V_53 .
V_54 ,
V_16 -> V_25 . V_53 .
V_55 ) ;
break;
case V_56 :
F_17 ( V_34 ,
L_12 ,
V_16 -> V_13 ,
V_16 -> V_25 . V_57 . V_27 ,
V_16 -> V_25 . V_57 . V_45 ) ;
break;
case V_58 :
F_17 ( V_34 , L_13
L_14 ,
V_16 -> V_13 ,
V_16 -> V_25 . V_59 . V_45 ,
V_16 -> V_25 . V_59 . V_60 ,
V_16 -> V_25 . V_59 . V_61 ) ;
break;
default:
F_17 ( V_34 , L_15 ,
V_16 -> V_22 ,
V_16 -> V_13 ) ;
break;
}
}
static int F_18 ( struct V_1 * V_11 ,
struct V_10 * V_30 )
{
int V_62 ;
struct V_63 * V_64 ;
struct V_65 V_66 [ 2 ] ;
struct V_65 * V_67 = V_66 ;
struct V_68 * V_69 = F_19 ( V_11 -> V_70 ) ;
V_64 = & V_30 -> V_23 ;
V_64 -> V_71 = V_30 -> V_21 . V_13 ;
V_64 -> V_72 = 1 ;
V_67 [ 0 ] . V_73 = F_20 ( & V_30 -> V_21 ) >>
V_74 ;
V_67 [ 0 ] . V_75 = V_30 -> V_21 . V_13 ;
V_67 [ 0 ] . V_76 =
( unsigned long ) & V_30 -> V_21 & ( V_77 - 1 ) ;
if ( V_67 [ 0 ] . V_76 + V_67 [ 0 ] . V_75 > V_77 ) {
V_64 -> V_72 ++ ;
V_67 [ 0 ] . V_75 = V_77 -
V_67 [ 0 ] . V_76 ;
V_67 [ 1 ] . V_73 = F_20 ( ( void * ) & V_30 -> V_21
+ V_67 [ 0 ] . V_75 ) >> V_74 ;
V_67 [ 1 ] . V_76 = 0 ;
V_67 [ 1 ] . V_75 = V_30 -> V_21 . V_13 -
V_67 [ 0 ] . V_75 ;
}
V_62 = F_21 ( V_69 -> V_78 , V_64 , NULL , & V_67 , NULL ) ;
return V_62 ;
}
static void F_22 ( struct V_1 * V_79 ,
struct V_10 * V_14 )
{
T_1 V_80 ;
struct V_81 * V_53 ;
V_53 = & V_14 -> V_82 . V_25 . V_53 ;
if ( V_53 -> V_45 == V_83 &&
V_53 -> V_54 == sizeof( T_1 ) ) {
memcpy ( & V_80 , ( void * ) ( ( unsigned long ) V_53 +
V_53 -> V_55 ) , sizeof( T_1 ) ) ;
V_79 -> V_84 = V_80 != 0 ;
}
}
static void F_23 ( struct V_1 * V_11 ,
struct V_15 * V_85 )
{
struct V_10 * V_14 = NULL ;
bool V_86 = false ;
unsigned long V_19 ;
struct V_33 * V_70 = V_11 -> V_70 ;
F_9 ( & V_11 -> V_4 , V_19 ) ;
F_24 (request, &dev->req_list, list_ent) {
if ( V_14 -> V_21 . V_25 . V_87 . V_27
== V_85 -> V_25 . V_44 . V_27 ) {
V_86 = true ;
break;
}
}
F_11 ( & V_11 -> V_4 , V_19 ) ;
if ( V_86 ) {
if ( V_85 -> V_13 <=
sizeof( struct V_15 ) + V_88 ) {
memcpy ( & V_14 -> V_82 , V_85 ,
V_85 -> V_13 ) ;
if ( V_14 -> V_21 . V_22 ==
V_89 && V_14 -> V_21 . V_25 .
V_90 . V_91 == V_92 )
F_22 ( V_11 , V_14 ) ;
} else {
F_25 ( V_70 ,
L_16
L_17 ,
V_85 -> V_13 ,
sizeof( struct V_15 ) ) ;
if ( V_85 -> V_22 ==
V_93 ) {
V_14 -> V_82 . V_25 . V_94 .
V_45 = V_95 ;
} else {
V_14 -> V_82 . V_25 .
V_44 . V_45 =
V_95 ;
}
}
F_26 ( & V_14 -> V_20 ) ;
} else {
F_25 ( V_70 ,
L_18
L_19 ,
V_85 -> V_25 . V_44 . V_27 ,
V_85 -> V_22 ) ;
}
}
static inline void * F_27 ( struct V_96 * V_97 , T_1 type )
{
struct V_98 * V_99 ;
int V_75 ;
if ( V_97 -> V_41 == 0 )
return NULL ;
V_99 = (struct V_98 * ) ( ( V_100 ) V_97 +
V_97 -> V_41 ) ;
V_75 = V_97 -> V_42 ;
while ( V_75 > 0 ) {
if ( V_99 -> type == type )
return ( void * ) ( ( V_100 ) V_99 + V_99 -> V_101 ) ;
V_75 -= V_99 -> V_102 ;
V_99 = (struct V_98 * ) ( ( V_100 ) V_99 + V_99 -> V_102 ) ;
}
return NULL ;
}
static int F_28 ( struct V_33 * V_70 ,
struct V_1 * V_11 ,
struct V_15 * V_25 ,
struct V_103 * V_104 ,
void * V_105 , T_1 V_106 )
{
struct V_96 * V_107 = & V_25 -> V_25 . V_23 ;
const struct V_108 * V_109 ;
const struct V_110 * V_111 ;
T_1 V_36 ;
V_36 = V_112 + V_107 -> V_36 ;
V_106 -= V_36 ;
if ( F_29 ( V_106 < V_107 -> V_37 ) ) {
F_25 ( V_11 -> V_70 , L_20
L_21
L_22 ,
V_106 , V_107 -> V_37 ) ;
return V_113 ;
}
V_111 = F_27 ( V_107 , V_114 ) ;
V_105 = ( void * ) ( ( unsigned long ) V_105 + V_36 ) ;
V_109 = F_27 ( V_107 , V_115 ) ;
return F_30 ( V_70 , V_104 ,
V_105 , V_107 -> V_37 ,
V_109 , V_111 ) ;
}
int F_31 ( struct V_33 * V_70 ,
struct V_116 * V_117 ,
struct V_31 * V_11 ,
struct V_103 * V_104 ,
void * V_105 , T_1 V_118 )
{
struct V_68 * V_69 = F_19 ( V_70 ) ;
struct V_1 * V_119 = V_117 -> V_120 ;
struct V_15 * V_16 = V_105 ;
if ( F_29 ( ! V_119 ) ) {
F_32 ( V_69 , V_121 , V_70 ,
L_23 ) ;
return V_113 ;
}
if ( F_29 ( V_119 -> V_8 == V_9 ) ) {
F_32 ( V_69 , V_121 , V_70 ,
L_24 ) ;
return V_113 ;
}
if ( F_33 ( V_69 ) )
F_15 ( V_11 , V_16 ) ;
switch ( V_16 -> V_22 ) {
case V_35 :
return F_28 ( V_70 , V_119 , V_16 ,
V_104 , V_105 , V_118 ) ;
case V_43 :
case V_52 :
case V_56 :
F_23 ( V_119 , V_16 ) ;
break;
case V_58 :
F_34 ( V_11 , V_16 ) ;
break;
default:
F_25 ( V_70 ,
L_25 ,
V_16 -> V_22 ,
V_16 -> V_13 ) ;
break;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_11 , T_1 V_91 ,
void * V_122 , T_1 * V_123 )
{
struct V_10 * V_14 ;
T_1 V_124 = * V_123 ;
struct V_125 * V_126 ;
struct V_81 * V_53 ;
int V_62 = 0 ;
if ( ! V_122 )
return - V_127 ;
* V_123 = 0 ;
V_14 = F_6 ( V_11 , V_89 ,
F_36 ( struct V_125 ) ) ;
if ( ! V_14 ) {
V_62 = - V_128 ;
goto V_129;
}
V_126 = & V_14 -> V_21 . V_25 . V_90 ;
V_126 -> V_91 = V_91 ;
V_126 -> V_55 = sizeof( struct V_125 ) ;
V_126 -> V_54 = 0 ;
V_126 -> V_130 = 0 ;
if ( V_91 == V_131 ) {
struct V_68 * V_132 = F_19 ( V_11 -> V_70 ) ;
struct V_116 * V_133 = V_132 -> V_133 ;
struct V_134 * V_135 ;
T_1 V_136 = V_133 -> V_136 ;
T_2 V_137 ;
T_3 V_102 ;
if ( V_136 >= V_138 ) {
V_137 = V_139 ;
V_102 = V_140 ;
} else if ( V_136 >= V_141 ) {
V_137 = V_142 ;
V_102 = V_143 ;
} else {
V_137 = V_144 ;
V_102 = V_145 ;
}
V_14 -> V_21 . V_13 += V_102 ;
V_126 -> V_54 = V_102 ;
V_135 = (struct V_134 * )
( ( unsigned long ) V_126 + V_126 -> V_55 ) ;
V_135 -> V_146 . type = V_147 ;
V_135 -> V_146 . V_148 = V_137 ;
V_135 -> V_146 . V_102 = V_102 ;
} else if ( V_91 == V_149 ) {
struct V_150 * V_151 ;
V_14 -> V_21 . V_13 +=
sizeof( struct V_150 ) ;
V_126 -> V_54 = sizeof( struct V_150 ) ;
V_151 = (struct V_150 * ) ( ( unsigned long ) V_126 +
V_126 -> V_55 ) ;
V_151 -> V_152 . type = V_153 ;
V_151 -> V_152 . V_154 = V_155 ;
V_151 -> V_152 . V_102 = sizeof( struct V_150 ) ;
}
V_62 = F_18 ( V_11 , V_14 ) ;
if ( V_62 != 0 )
goto V_129;
F_37 ( & V_14 -> V_20 ) ;
V_53 = & V_14 -> V_82 . V_25 . V_53 ;
if ( V_53 -> V_54 > V_124 ) {
V_62 = - 1 ;
goto V_129;
}
memcpy ( V_122 ,
( void * ) ( ( unsigned long ) V_53 +
V_53 -> V_55 ) ,
V_53 -> V_54 ) ;
* V_123 = V_53 -> V_54 ;
V_129:
if ( V_14 )
F_12 ( V_11 , V_14 ) ;
return V_62 ;
}
static int
F_38 ( struct V_1 * V_11 , struct V_134 * V_156 )
{
T_1 V_157 = sizeof( * V_156 ) ;
int V_62 ;
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
V_62 = F_35 ( V_11 ,
V_131 ,
V_156 , & V_157 ) ;
if ( V_62 )
return V_62 ;
if ( V_156 -> V_146 . type != V_147 ) {
F_39 ( V_11 -> V_70 , L_26 ,
V_156 -> V_146 . type ) ;
return - V_127 ;
}
if ( V_156 -> V_146 . V_148 < V_144 ) {
F_39 ( V_11 -> V_70 , L_27 ,
V_156 -> V_146 . V_148 ) ;
return - V_127 ;
}
if ( V_156 -> V_146 . V_102 > V_157 ||
V_156 -> V_146 . V_102 < V_145 ) {
F_39 ( V_11 -> V_70 ,
L_28 ,
V_156 -> V_146 . V_102 , V_157 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_11 )
{
T_1 V_102 = V_158 ;
return F_35 ( V_11 ,
V_159 ,
V_11 -> V_160 , & V_102 ) ;
}
int F_41 ( struct V_33 * V_70 , char * V_161 )
{
struct V_116 * V_133 = F_42 ( V_70 ) ;
struct V_1 * V_79 = V_133 -> V_120 ;
struct V_10 * V_14 ;
struct V_17 * V_18 ;
struct V_162 * V_163 ;
T_4 * V_164 , * V_165 ;
struct V_166 * V_57 ;
char V_167 [ 2 * V_158 + 1 ] ;
T_1 V_168 = sizeof( struct V_162 ) +
2 * V_169 + 4 * V_158 ;
int V_62 ;
V_14 = F_6 ( V_79 , V_170 ,
F_36 ( struct V_17 ) + V_168 ) ;
if ( ! V_14 )
return - V_128 ;
V_18 = & V_14 -> V_21 . V_25 . V_26 ;
V_18 -> V_91 = V_171 ;
V_18 -> V_54 = V_168 ;
V_18 -> V_55 = sizeof( struct V_17 ) ;
V_18 -> V_130 = 0 ;
V_163 = (struct V_162 * ) ( ( V_100 ) V_18 +
V_18 -> V_55 ) ;
V_163 -> V_172 =
sizeof( struct V_162 ) ;
V_163 -> V_173 = 2 * V_169 ;
V_163 -> V_174 = V_175 ;
V_163 -> V_176 =
V_163 -> V_172 + V_163 -> V_173 ;
V_163 -> V_177 = 4 * V_158 ;
V_164 = ( T_4 * ) ( ( V_100 ) V_163 + V_163 -> V_172 ) ;
V_165 = ( T_4 * ) ( ( V_100 ) V_163 + V_163 -> V_176 ) ;
V_62 = F_43 ( V_178 , V_169 , V_179 ,
V_164 , V_169 ) ;
if ( V_62 < 0 )
goto V_129;
snprintf ( V_167 , 2 * V_158 + 1 , L_29 , V_161 ) ;
V_62 = F_43 ( V_167 , 2 * V_158 , V_179 ,
V_165 , 2 * V_158 ) ;
if ( V_62 < 0 )
goto V_129;
V_62 = F_18 ( V_79 , V_14 ) ;
if ( V_62 != 0 )
goto V_129;
F_37 ( & V_14 -> V_20 ) ;
V_57 = & V_14 -> V_82 . V_25 . V_57 ;
if ( V_57 -> V_45 != V_83 ) {
F_25 ( V_70 , L_30 ,
V_57 -> V_45 ) ;
V_62 = - V_127 ;
}
V_129:
F_12 ( V_79 , V_14 ) ;
return V_62 ;
}
static int
F_44 ( struct V_33 * V_70 ,
struct V_180 * V_181 )
{
struct V_116 * V_133 = F_42 ( V_70 ) ;
struct V_1 * V_79 = V_133 -> V_120 ;
struct V_10 * V_14 ;
struct V_17 * V_18 ;
struct V_180 * V_182 ;
struct V_166 * V_57 ;
T_1 V_168 = sizeof( struct V_180 ) ;
int V_62 ;
T_1 V_183 = V_133 -> V_136 ;
if ( V_183 <= V_141 ) {
V_168 = V_184 ;
V_181 -> V_185 = 0 ;
V_181 -> V_186 = 0 ;
}
V_14 = F_6 ( V_79 , V_170 ,
F_36 ( struct V_17 ) + V_168 ) ;
if ( ! V_14 )
return - V_128 ;
V_18 = & V_14 -> V_21 . V_25 . V_26 ;
V_18 -> V_91 = V_187 ;
V_18 -> V_54 = V_168 ;
V_18 -> V_55 = sizeof( struct V_17 ) ;
V_18 -> V_130 = 0 ;
V_182 = (struct V_180 * ) ( ( V_100 ) V_18 +
V_18 -> V_55 ) ;
* V_182 = * V_181 ;
V_182 -> V_146 . type = V_188 ;
V_182 -> V_146 . V_148 = V_139 ;
V_182 -> V_146 . V_102 = V_168 ;
V_62 = F_18 ( V_79 , V_14 ) ;
if ( V_62 != 0 )
goto V_129;
F_37 ( & V_14 -> V_20 ) ;
V_57 = & V_14 -> V_82 . V_25 . V_57 ;
if ( V_57 -> V_45 != V_83 ) {
F_25 ( V_70 , L_31 ,
V_57 -> V_45 ) ;
V_62 = - V_127 ;
}
V_129:
F_12 ( V_79 , V_14 ) ;
return V_62 ;
}
int F_45 ( struct V_1 * V_79 ,
const T_2 * V_189 , int V_190 )
{
struct V_33 * V_70 = V_79 -> V_70 ;
struct V_10 * V_14 ;
struct V_17 * V_18 ;
struct V_166 * V_57 ;
T_1 V_168 = sizeof( struct V_191 ) +
4 * V_192 + V_193 ;
struct V_191 * V_194 ;
T_1 * V_195 ;
T_2 * V_196 ;
int V_197 , V_62 ;
V_14 = F_6 (
V_79 , V_170 ,
F_36 ( struct V_17 ) + V_168 ) ;
if ( ! V_14 )
return - V_128 ;
V_18 = & V_14 -> V_21 . V_25 . V_26 ;
V_18 -> V_91 = V_198 ;
V_18 -> V_54 = V_168 ;
V_18 -> V_55 = sizeof( struct V_17 ) ;
V_18 -> V_130 = 0 ;
V_194 = (struct V_191 * ) ( V_18 + 1 ) ;
V_194 -> V_152 . type = V_199 ;
V_194 -> V_152 . V_154 = V_200 ;
V_194 -> V_152 . V_102 = sizeof( struct V_191 ) ;
V_194 -> V_201 = 0 ;
V_194 -> V_202 = V_203 | V_204 |
V_205 | V_206 |
V_207 ;
V_194 -> V_208 = 4 * V_192 ;
V_194 -> V_209 = sizeof( struct V_191 ) ;
V_194 -> V_210 = V_193 ;
V_194 -> V_211 = V_194 -> V_209 +
V_194 -> V_208 ;
V_195 = ( T_1 * ) ( V_194 + 1 ) ;
for ( V_197 = 0 ; V_197 < V_192 ; V_197 ++ )
V_195 [ V_197 ] = V_79 -> V_212 [ V_197 ] ;
V_196 = ( T_2 * ) ( ( unsigned long ) V_194 + V_194 -> V_211 ) ;
memcpy ( V_196 , V_189 , V_193 ) ;
V_62 = F_18 ( V_79 , V_14 ) ;
if ( V_62 != 0 )
goto V_129;
F_37 ( & V_14 -> V_20 ) ;
V_57 = & V_14 -> V_82 . V_25 . V_57 ;
if ( V_57 -> V_45 == V_83 )
memcpy ( V_79 -> V_189 , V_189 , V_193 ) ;
else {
F_25 ( V_70 , L_32 ,
V_57 -> V_45 ) ;
V_62 = - V_127 ;
}
V_129:
F_12 ( V_79 , V_14 ) ;
return V_62 ;
}
static int F_46 ( struct V_1 * V_11 )
{
T_1 V_102 = sizeof( T_1 ) ;
T_1 V_80 ;
int V_62 ;
V_62 = F_35 ( V_11 ,
V_92 ,
& V_80 , & V_102 ) ;
return V_62 ;
}
static int F_47 ( struct V_1 * V_11 )
{
T_1 V_102 = sizeof( T_1 ) ;
T_1 V_213 ;
struct V_68 * V_214 ;
int V_62 ;
V_62 = F_35 ( V_11 , V_215 ,
& V_213 , & V_102 ) ;
if ( ! V_62 ) {
V_214 = F_19 ( V_11 -> V_70 ) ;
V_214 -> V_216 = V_213 / 10000 ;
}
return V_62 ;
}
static int F_48 ( struct V_1 * V_11 ,
T_1 V_217 )
{
struct V_10 * V_14 ;
struct V_17 * V_18 ;
int V_62 ;
V_14 = F_6 ( V_11 , V_170 ,
F_36 ( struct V_17 ) +
sizeof( T_1 ) ) ;
if ( ! V_14 )
return - V_128 ;
V_18 = & V_14 -> V_21 . V_25 . V_26 ;
V_18 -> V_91 = V_218 ;
V_18 -> V_54 = sizeof( T_1 ) ;
V_18 -> V_55 = sizeof( struct V_17 ) ;
memcpy ( ( void * ) ( unsigned long ) V_18 + sizeof( struct V_17 ) ,
& V_217 , sizeof( T_1 ) ) ;
V_62 = F_18 ( V_11 , V_14 ) ;
if ( V_62 == 0 )
F_37 ( & V_14 -> V_20 ) ;
F_12 ( V_11 , V_14 ) ;
return V_62 ;
}
static void V_7 ( struct V_219 * V_220 )
{
struct V_1 * V_79
= F_49 ( V_220 , struct V_1 , V_6 ) ;
if ( V_79 -> V_70 -> V_19 & V_221 )
F_48 ( V_79 ,
V_222 ) ;
else
F_48 ( V_79 ,
V_223 |
V_224 |
V_225 ) ;
}
void F_50 ( struct V_116 * V_133 )
{
struct V_1 * V_79 = V_133 -> V_120 ;
F_51 ( & V_79 -> V_6 ) ;
}
static int F_52 ( struct V_1 * V_11 )
{
struct V_10 * V_14 ;
struct V_226 * V_227 ;
struct V_228 * V_44 ;
T_1 V_45 ;
int V_62 ;
struct V_116 * V_133 = F_42 ( V_11 -> V_70 ) ;
V_14 = F_6 ( V_11 , V_229 ,
F_36 ( struct V_226 ) ) ;
if ( ! V_14 ) {
V_62 = - V_128 ;
goto V_129;
}
V_227 = & V_14 -> V_21 . V_25 . V_87 ;
V_227 -> V_46 = V_230 ;
V_227 -> V_47 = V_231 ;
V_227 -> V_49 = 0x4000 ;
V_11 -> V_8 = V_232 ;
V_62 = F_18 ( V_11 , V_14 ) ;
if ( V_62 != 0 ) {
V_11 -> V_8 = V_9 ;
goto V_129;
}
F_37 ( & V_14 -> V_20 ) ;
V_44 = & V_14 -> V_82 . V_25 . V_44 ;
V_45 = V_44 -> V_45 ;
if ( V_45 == V_83 ) {
V_11 -> V_8 = V_233 ;
V_133 -> V_234 = V_44 -> V_50 ;
V_133 -> V_235 = 1 << V_44 -> V_51 ;
V_62 = 0 ;
} else {
V_11 -> V_8 = V_9 ;
V_62 = - V_127 ;
}
V_129:
if ( V_14 )
F_12 ( V_11 , V_14 ) ;
return V_62 ;
}
static bool F_53 ( const struct V_116 * V_133 )
{
int V_197 ;
if ( F_54 ( & V_133 -> V_236 ) > 0 )
return false ;
for ( V_197 = 0 ; V_197 < V_133 -> V_237 ; V_197 ++ ) {
const struct V_238 * V_239 = & V_133 -> V_240 [ V_197 ] ;
if ( F_54 ( & V_239 -> V_241 ) > 0 )
return false ;
}
return true ;
}
static void F_55 ( struct V_1 * V_11 )
{
struct V_10 * V_14 ;
struct V_242 * V_243 ;
struct V_68 * V_69 = F_19 ( V_11 -> V_70 ) ;
struct V_116 * V_133 = V_69 -> V_133 ;
V_14 = F_6 ( V_11 , V_244 ,
F_36 ( struct V_242 ) ) ;
if ( ! V_14 )
goto V_129;
V_243 = & V_14 -> V_21 . V_25 . V_245 ;
V_243 -> V_27 = F_8 ( & V_11 -> V_28 ) ;
F_18 ( V_11 , V_14 ) ;
V_11 -> V_8 = V_9 ;
V_129:
V_133 -> V_246 = true ;
F_56 () ;
V_20 ( V_133 -> V_247 , F_53 ( V_133 ) ) ;
if ( V_14 )
F_12 ( V_11 , V_14 ) ;
}
static int F_57 ( struct V_1 * V_11 )
{
int V_62 ;
if ( V_11 -> V_8 != V_233 )
return 0 ;
V_62 = F_48 ( V_11 ,
V_223 |
V_224 |
V_225 ) ;
if ( V_62 == 0 )
V_11 -> V_8 = V_248 ;
return V_62 ;
}
static int F_58 ( struct V_1 * V_11 )
{
int V_62 ;
if ( V_11 -> V_8 != V_248 )
return 0 ;
F_59 ( & V_11 -> V_6 ) ;
V_62 = F_48 ( V_11 , 0 ) ;
if ( V_62 == - V_249 )
V_62 = 0 ;
if ( V_62 == 0 )
V_11 -> V_8 = V_233 ;
return V_62 ;
}
static void F_60 ( struct V_103 * V_250 )
{
struct V_33 * V_70 =
F_16 ( V_250 -> V_251 -> V_252 ) ;
struct V_116 * V_253 = F_42 ( V_70 ) ;
T_5 V_254 = V_250 -> V_255 . V_256 . V_257 ;
struct V_238 * V_239 ;
int V_62 ;
if ( V_254 >= V_253 -> V_237 )
return;
V_239 = V_253 -> V_240 + V_254 ;
V_239 -> V_258 . V_259
= F_61 ( V_260 * sizeof( struct V_261 ) ) ;
if ( ! V_239 -> V_258 . V_259 )
return;
F_62 ( V_250 , V_262 ) ;
V_239 -> V_104 = V_250 ;
F_63 ( V_70 , & V_239 -> V_263 ,
V_264 , V_265 ) ;
V_62 = F_64 ( V_250 , V_253 -> V_266 * V_77 ,
V_253 -> V_266 * V_77 , NULL , 0 ,
V_267 , V_239 ) ;
if ( V_62 == 0 )
F_65 ( & V_239 -> V_263 ) ;
else
F_66 ( & V_239 -> V_263 ) ;
F_67 ( & V_253 -> V_268 ) ;
F_68 ( & V_253 -> V_269 ) ;
}
int F_69 ( struct V_31 * V_11 ,
struct V_270 * V_271 )
{
struct V_33 * V_272 = F_16 ( V_11 ) ;
struct V_68 * V_69 = F_19 ( V_272 ) ;
struct V_116 * V_33 ;
struct V_1 * V_1 ;
struct V_134 V_135 ;
struct V_180 V_273 ;
struct V_274 * V_275 ;
struct V_150 V_276 ;
T_1 V_277 = sizeof( struct V_150 ) ;
unsigned int V_278 = V_279 ;
T_1 V_280 , V_102 , V_281 ;
const struct V_282 * V_283 ;
T_1 V_284 ;
int V_197 , V_62 ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_249 ;
V_62 = F_70 ( V_11 , V_271 ) ;
if ( V_62 != 0 ) {
F_14 ( V_1 ) ;
return V_62 ;
}
V_33 = V_69 -> V_133 ;
V_33 -> V_285 = 1 ;
V_33 -> V_237 = 1 ;
V_33 -> V_120 = V_1 ;
V_1 -> V_70 = V_272 ;
V_62 = F_52 ( V_1 ) ;
if ( V_62 != 0 ) {
F_71 ( V_11 , V_33 ) ;
return V_62 ;
}
V_102 = sizeof( T_1 ) ;
V_62 = F_35 ( V_1 ,
V_286 ,
& V_280 , & V_102 ) ;
if ( V_62 == 0 && V_102 == sizeof( T_1 ) && V_280 < V_272 -> V_280 )
V_272 -> V_280 = V_280 ;
V_62 = F_40 ( V_1 ) ;
if ( V_62 != 0 ) {
F_71 ( V_11 , V_33 ) ;
return V_62 ;
}
memcpy ( V_271 -> V_287 , V_1 -> V_160 , V_158 ) ;
V_62 = F_38 ( V_1 , & V_135 ) ;
if ( V_62 != 0 ) {
F_71 ( V_11 , V_33 ) ;
return V_62 ;
}
memset ( & V_273 , 0 , sizeof( struct V_180 ) ) ;
V_273 . V_288 = V_289 ;
V_272 -> V_290 = V_291 ;
if ( ( V_135 . V_292 . V_293 & V_294 ) == V_294 ) {
V_272 -> V_290 |= V_295 ;
V_69 -> V_296 |= V_297 ;
V_273 . V_298 = V_299 ;
if ( V_135 . V_300 . V_301 & V_302 ) {
V_273 . V_303 = V_304 ;
V_272 -> V_290 |= V_305 ;
if ( V_135 . V_300 . V_306 < V_278 )
V_278 = V_135 . V_300 . V_306 ;
}
if ( V_135 . V_292 . V_293 & V_307 ) {
V_273 . V_185 = V_299 ;
V_69 -> V_296 |= V_308 ;
}
}
if ( ( V_135 . V_292 . V_309 & V_310 ) == V_310 ) {
V_272 -> V_290 |= V_311 ;
V_273 . V_312 = V_299 ;
V_69 -> V_296 |= V_313 ;
if ( ( V_135 . V_300 . V_314 & V_302 ) &&
( V_135 . V_300 . V_315 & V_316 ) == V_316 ) {
V_273 . V_317 = V_304 ;
V_272 -> V_290 |= V_318 ;
if ( V_135 . V_300 . V_319 < V_278 )
V_278 = V_135 . V_300 . V_319 ;
}
if ( V_135 . V_292 . V_309 & V_320 ) {
V_273 . V_186 = V_299 ;
V_69 -> V_296 |= V_321 ;
}
}
F_72 ( V_272 , V_278 ) ;
V_62 = F_44 ( V_272 , & V_273 ) ;
if ( V_62 )
goto V_322;
F_46 ( V_1 ) ;
F_17 ( V_272 , L_33 ,
V_1 -> V_160 ,
V_1 -> V_84 ? L_34 : L_35 ) ;
if ( V_33 -> V_136 < V_138 )
return 0 ;
F_47 ( V_1 ) ;
memset ( & V_276 , 0 , V_277 ) ;
V_62 = F_35 ( V_1 ,
V_149 ,
& V_276 , & V_277 ) ;
if ( V_62 || V_276 . V_323 < 2 )
goto V_324;
V_283 = F_73 ( F_74 ( V_11 -> V_104 -> V_325 ) ) ;
V_284 = F_75 ( T_1 , F_76 ( V_283 ) ,
V_276 . V_323 ) ;
V_33 -> V_285 = F_75 ( T_1 , V_326 , V_284 ) ;
V_33 -> V_237 = F_77 ( V_33 -> V_285 , V_271 -> V_237 ) ;
for ( V_197 = 0 ; V_197 < V_192 ; V_197 ++ )
V_1 -> V_212 [ V_197 ] = F_78 ( V_197 ,
V_33 -> V_237 ) ;
F_79 ( & V_33 -> V_268 , 1 ) ;
V_281 = V_33 -> V_237 - 1 ;
if ( V_281 == 0 )
return 0 ;
F_80 ( V_11 -> V_104 , F_60 ) ;
V_275 = & V_33 -> V_327 ;
memset ( V_275 , 0 , sizeof( struct V_274 ) ) ;
V_275 -> V_152 . V_12 = V_328 ;
V_275 -> V_25 . V_329 . V_330 . V_331 = V_332 ;
V_275 -> V_25 . V_329 . V_330 . V_333 =
V_33 -> V_237 - 1 ;
V_62 = F_81 ( V_11 -> V_104 , V_275 ,
sizeof( struct V_274 ) ,
( unsigned long ) V_275 ,
V_334 ,
V_335 ) ;
if ( V_62 )
goto V_324;
F_37 ( & V_33 -> V_336 ) ;
if ( V_275 -> V_25 . V_329 . V_337 . V_45 != V_338 ) {
V_62 = - V_249 ;
goto V_324;
}
V_33 -> V_237 = 1 +
V_275 -> V_25 . V_329 . V_337 . V_333 ;
V_20 ( V_33 -> V_269 ,
F_54 ( & V_33 -> V_268 ) == V_33 -> V_237 ) ;
F_45 ( V_1 , V_339 ,
V_33 -> V_237 ) ;
V_324:
if ( V_62 ) {
V_33 -> V_285 = 1 ;
V_33 -> V_237 = 1 ;
}
return 0 ;
V_322:
F_71 ( V_11 , V_33 ) ;
return V_62 ;
}
void F_71 ( struct V_31 * V_11 ,
struct V_116 * V_117 )
{
struct V_1 * V_119 = V_117 -> V_120 ;
F_55 ( V_119 ) ;
F_14 ( V_119 ) ;
V_117 -> V_120 = NULL ;
F_82 ( V_11 ) ;
}
int F_83 ( struct V_116 * V_133 )
{
if ( ! V_133 )
return - V_127 ;
if ( F_8 ( & V_133 -> V_340 ) != 1 )
return 0 ;
return F_57 ( V_133 -> V_120 ) ;
}
int F_84 ( struct V_116 * V_133 )
{
if ( ! V_133 )
return - V_127 ;
if ( F_85 ( & V_133 -> V_340 ) != 0 )
return 0 ;
return F_58 ( V_133 -> V_120 ) ;
}
