static struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) , V_3 ) ;
if ( ! V_2 )
return NULL ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = V_7 ;
return V_2 ;
}
static struct V_8 * F_5 ( struct V_1 * V_9 ,
T_1 V_10 ,
T_1 V_11 )
{
struct V_8 * V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
unsigned long V_17 ;
V_12 = F_2 ( sizeof( struct V_8 ) , V_3 ) ;
if ( ! V_12 )
return NULL ;
F_6 ( & V_12 -> V_18 ) ;
V_14 = & V_12 -> V_19 ;
V_14 -> V_20 = V_10 ;
V_14 -> V_11 = V_11 ;
V_12 -> V_21 . V_22 = 0 ;
V_16 = & V_14 -> V_23 . V_24 ;
V_16 -> V_25 = F_7 ( & V_9 -> V_26 ) ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_9 ( & V_12 -> V_27 , & V_9 -> V_5 ) ;
F_10 ( & V_9 -> V_4 , V_17 ) ;
return V_12 ;
}
static void F_11 ( struct V_1 * V_9 ,
struct V_8 * V_28 )
{
unsigned long V_17 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_12 ( & V_28 -> V_27 ) ;
F_10 ( & V_9 -> V_4 , V_17 ) ;
F_13 ( V_28 ) ;
}
static void F_14 ( struct V_29 * V_30 ,
const struct V_13 * V_14 )
{
struct V_31 * V_32 = F_15 ( V_30 ) ;
switch ( V_14 -> V_20 ) {
case V_33 :
F_16 ( V_32 , L_1
L_2
L_3
L_4 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_21 . V_34 ,
V_14 -> V_23 . V_21 . V_35 ,
V_14 -> V_23 . V_21 . V_36 ,
V_14 -> V_23 . V_21 . V_37 ,
V_14 -> V_23 . V_21 . V_38 ,
V_14 -> V_23 . V_21 . V_39 ,
V_14 -> V_23 . V_21 . V_40 ) ;
break;
case V_41 :
F_16 ( V_32 , L_5
L_6
L_7
L_8 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_42 . V_25 ,
V_14 -> V_23 . V_42 . V_43 ,
V_14 -> V_23 . V_42 . V_44 ,
V_14 -> V_23 . V_42 . V_45 ,
V_14 -> V_23 . V_42 . V_46 ,
V_14 -> V_23 . V_42 . V_47 ,
V_14 -> V_23 . V_42 .
V_48 ,
V_14 -> V_23 . V_42 .
V_49 ) ;
break;
case V_50 :
F_16 ( V_32 , L_9
L_10
L_11 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_51 . V_25 ,
V_14 -> V_23 . V_51 . V_43 ,
V_14 -> V_23 . V_51 .
V_52 ,
V_14 -> V_23 . V_51 .
V_53 ) ;
break;
case V_54 :
F_16 ( V_32 ,
L_12 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_55 . V_25 ,
V_14 -> V_23 . V_55 . V_43 ) ;
break;
case V_56 :
F_16 ( V_32 , L_13
L_14 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_57 . V_43 ,
V_14 -> V_23 . V_57 . V_58 ,
V_14 -> V_23 . V_57 . V_59 ) ;
break;
default:
F_16 ( V_32 , L_15 ,
V_14 -> V_20 ,
V_14 -> V_11 ) ;
break;
}
}
static int F_17 ( struct V_1 * V_9 ,
struct V_8 * V_28 )
{
int V_60 ;
struct V_61 * V_62 ;
struct V_63 V_64 [ 2 ] ;
struct V_63 * V_65 = V_64 ;
struct V_66 * V_67 = F_18 ( V_9 -> V_68 ) ;
V_62 = & V_28 -> V_21 ;
V_62 -> V_69 = V_28 -> V_19 . V_11 ;
V_62 -> V_70 = 1 ;
V_65 [ 0 ] . V_71 = F_19 ( & V_28 -> V_19 ) >>
V_72 ;
V_65 [ 0 ] . V_73 = V_28 -> V_19 . V_11 ;
V_65 [ 0 ] . V_74 =
( unsigned long ) & V_28 -> V_19 & ( V_75 - 1 ) ;
if ( V_65 [ 0 ] . V_74 + V_65 [ 0 ] . V_73 > V_75 ) {
V_62 -> V_70 ++ ;
V_65 [ 0 ] . V_73 = V_75 -
V_65 [ 0 ] . V_74 ;
V_65 [ 1 ] . V_71 = F_19 ( ( void * ) & V_28 -> V_19
+ V_65 [ 0 ] . V_73 ) >> V_72 ;
V_65 [ 1 ] . V_74 = 0 ;
V_65 [ 1 ] . V_73 = V_28 -> V_19 . V_11 -
V_65 [ 0 ] . V_73 ;
}
V_60 = F_20 ( V_67 -> V_76 , V_62 , NULL , & V_65 , NULL ) ;
return V_60 ;
}
static void F_21 ( struct V_1 * V_77 ,
struct V_8 * V_12 )
{
T_1 V_78 ;
struct V_79 * V_51 ;
V_51 = & V_12 -> V_80 . V_23 . V_51 ;
if ( V_51 -> V_43 == V_81 &&
V_51 -> V_52 == sizeof( T_1 ) ) {
memcpy ( & V_78 , ( void * ) ( ( unsigned long ) V_51 +
V_51 -> V_53 ) , sizeof( T_1 ) ) ;
V_77 -> V_82 = V_78 != 0 ;
}
}
static void F_22 ( struct V_1 * V_9 ,
struct V_13 * V_83 )
{
struct V_8 * V_12 = NULL ;
bool V_84 = false ;
unsigned long V_17 ;
struct V_31 * V_68 = V_9 -> V_68 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_23 (request, &dev->req_list, list_ent) {
if ( V_12 -> V_19 . V_23 . V_85 . V_25
== V_83 -> V_23 . V_42 . V_25 ) {
V_84 = true ;
break;
}
}
F_10 ( & V_9 -> V_4 , V_17 ) ;
if ( V_84 ) {
if ( V_83 -> V_11 <=
sizeof( struct V_13 ) + V_86 ) {
memcpy ( & V_12 -> V_80 , V_83 ,
V_83 -> V_11 ) ;
if ( V_12 -> V_19 . V_20 ==
V_87 && V_12 -> V_19 . V_23 .
V_88 . V_89 == V_90 )
F_21 ( V_9 , V_12 ) ;
} else {
F_24 ( V_68 ,
L_16
L_17 ,
V_83 -> V_11 ,
sizeof( struct V_13 ) ) ;
if ( V_83 -> V_20 ==
V_91 ) {
V_12 -> V_80 . V_23 . V_92 .
V_43 = V_93 ;
} else {
V_12 -> V_80 . V_23 .
V_42 . V_43 =
V_93 ;
}
}
F_25 ( & V_12 -> V_18 ) ;
} else {
F_24 ( V_68 ,
L_18
L_19 ,
V_83 -> V_23 . V_42 . V_25 ,
V_83 -> V_20 ) ;
}
}
static inline void * F_26 ( struct V_94 * V_95 , T_1 type )
{
struct V_96 * V_97 ;
int V_73 ;
if ( V_95 -> V_39 == 0 )
return NULL ;
V_97 = (struct V_96 * ) ( ( V_98 ) V_95 +
V_95 -> V_39 ) ;
V_73 = V_95 -> V_40 ;
while ( V_73 > 0 ) {
if ( V_97 -> type == type )
return ( void * ) ( ( V_98 ) V_97 + V_97 -> V_99 ) ;
V_73 -= V_97 -> V_100 ;
V_97 = (struct V_96 * ) ( ( V_98 ) V_97 + V_97 -> V_100 ) ;
}
return NULL ;
}
static int F_27 ( struct V_31 * V_68 ,
struct V_1 * V_9 ,
struct V_13 * V_23 ,
struct V_101 * V_102 ,
void * V_103 , T_1 V_104 )
{
struct V_94 * V_105 = & V_23 -> V_23 . V_21 ;
const struct V_106 * V_107 ;
const struct V_108 * V_109 ;
T_1 V_34 ;
V_34 = V_110 + V_105 -> V_34 ;
V_104 -= V_34 ;
if ( F_28 ( V_104 < V_105 -> V_35 ) ) {
F_24 ( V_9 -> V_68 , L_20
L_21
L_22 ,
V_104 , V_105 -> V_35 ) ;
return V_111 ;
}
V_109 = F_26 ( V_105 , V_112 ) ;
V_103 = ( void * ) ( ( unsigned long ) V_103 + V_34 ) ;
V_107 = F_26 ( V_105 , V_113 ) ;
return F_29 ( V_68 , V_102 ,
V_103 , V_105 -> V_35 ,
V_107 , V_109 ) ;
}
int F_30 ( struct V_31 * V_68 ,
struct V_114 * V_115 ,
struct V_29 * V_9 ,
struct V_101 * V_102 ,
void * V_103 , T_1 V_116 )
{
struct V_66 * V_67 = F_18 ( V_68 ) ;
struct V_1 * V_117 = V_115 -> V_118 ;
struct V_13 * V_14 = V_103 ;
if ( F_28 ( ! V_117 ) ) {
F_31 ( V_67 , V_119 , V_68 ,
L_23 ) ;
return V_111 ;
}
if ( F_28 ( V_117 -> V_6 == V_7 ) ) {
F_31 ( V_67 , V_119 , V_68 ,
L_24 ) ;
return V_111 ;
}
if ( F_32 ( V_67 ) )
F_14 ( V_9 , V_14 ) ;
switch ( V_14 -> V_20 ) {
case V_33 :
return F_27 ( V_68 , V_117 , V_14 ,
V_102 , V_103 , V_116 ) ;
case V_41 :
case V_50 :
case V_54 :
F_22 ( V_117 , V_14 ) ;
break;
case V_56 :
F_33 ( V_9 , V_14 ) ;
break;
default:
F_24 ( V_68 ,
L_25 ,
V_14 -> V_20 ,
V_14 -> V_11 ) ;
break;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_9 , T_1 V_89 ,
void * V_120 , T_1 * V_121 )
{
struct V_8 * V_12 ;
T_1 V_122 = * V_121 ;
struct V_123 * V_124 ;
struct V_79 * V_51 ;
int V_60 = 0 ;
if ( ! V_120 )
return - V_125 ;
* V_121 = 0 ;
V_12 = F_5 ( V_9 , V_87 ,
F_35 ( struct V_123 ) ) ;
if ( ! V_12 ) {
V_60 = - V_126 ;
goto V_127;
}
V_124 = & V_12 -> V_19 . V_23 . V_88 ;
V_124 -> V_89 = V_89 ;
V_124 -> V_53 = sizeof( struct V_123 ) ;
V_124 -> V_52 = 0 ;
V_124 -> V_128 = 0 ;
if ( V_89 == V_129 ) {
struct V_66 * V_130 = F_18 ( V_9 -> V_68 ) ;
struct V_114 * V_131 = V_130 -> V_131 ;
struct V_132 * V_133 ;
T_1 V_134 = V_131 -> V_134 ;
T_2 V_135 ;
T_3 V_100 ;
if ( V_134 >= V_136 ) {
V_135 = V_137 ;
V_100 = V_138 ;
} else if ( V_134 >= V_139 ) {
V_135 = V_140 ;
V_100 = V_141 ;
} else {
V_135 = V_142 ;
V_100 = V_143 ;
}
V_12 -> V_19 . V_11 += V_100 ;
V_124 -> V_52 = V_100 ;
V_133 = (struct V_132 * )
( ( unsigned long ) V_124 + V_124 -> V_53 ) ;
V_133 -> V_144 . type = V_145 ;
V_133 -> V_144 . V_146 = V_135 ;
V_133 -> V_144 . V_100 = V_100 ;
} else if ( V_89 == V_147 ) {
struct V_148 * V_149 ;
V_12 -> V_19 . V_11 +=
sizeof( struct V_148 ) ;
V_124 -> V_52 = sizeof( struct V_148 ) ;
V_149 = (struct V_148 * ) ( ( unsigned long ) V_124 +
V_124 -> V_53 ) ;
V_149 -> V_150 . type = V_151 ;
V_149 -> V_150 . V_152 = V_153 ;
V_149 -> V_150 . V_100 = sizeof( struct V_148 ) ;
}
V_60 = F_17 ( V_9 , V_12 ) ;
if ( V_60 != 0 )
goto V_127;
F_36 ( & V_12 -> V_18 ) ;
V_51 = & V_12 -> V_80 . V_23 . V_51 ;
if ( V_51 -> V_52 > V_122 ) {
V_60 = - 1 ;
goto V_127;
}
memcpy ( V_120 ,
( void * ) ( ( unsigned long ) V_51 +
V_51 -> V_53 ) ,
V_51 -> V_52 ) ;
* V_121 = V_51 -> V_52 ;
V_127:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_60 ;
}
static int
F_37 ( struct V_1 * V_9 , struct V_132 * V_154 )
{
T_1 V_155 = sizeof( * V_154 ) ;
int V_60 ;
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
V_60 = F_34 ( V_9 ,
V_129 ,
V_154 , & V_155 ) ;
if ( V_60 )
return V_60 ;
if ( V_154 -> V_144 . type != V_145 ) {
F_38 ( V_9 -> V_68 , L_26 ,
V_154 -> V_144 . type ) ;
return - V_125 ;
}
if ( V_154 -> V_144 . V_146 < V_142 ) {
F_38 ( V_9 -> V_68 , L_27 ,
V_154 -> V_144 . V_146 ) ;
return - V_125 ;
}
if ( V_154 -> V_144 . V_100 > V_155 ||
V_154 -> V_144 . V_100 < V_143 ) {
F_38 ( V_9 -> V_68 ,
L_28 ,
V_154 -> V_144 . V_100 , V_155 ) ;
return - V_125 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_9 )
{
T_1 V_100 = V_156 ;
return F_34 ( V_9 ,
V_157 ,
V_9 -> V_158 , & V_100 ) ;
}
int F_40 ( struct V_31 * V_68 , char * V_159 )
{
struct V_114 * V_131 = F_41 ( V_68 ) ;
struct V_1 * V_77 = V_131 -> V_118 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_160 * V_161 ;
T_4 * V_162 , * V_163 ;
struct V_164 * V_55 ;
char V_165 [ 2 * V_156 + 1 ] ;
T_1 V_166 = sizeof( struct V_160 ) +
2 * V_167 + 4 * V_156 ;
int V_60 ;
V_12 = F_5 ( V_77 , V_168 ,
F_35 ( struct V_15 ) + V_166 ) ;
if ( ! V_12 )
return - V_126 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_169 ;
V_16 -> V_52 = V_166 ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
V_16 -> V_128 = 0 ;
V_161 = (struct V_160 * ) ( ( V_98 ) V_16 +
V_16 -> V_53 ) ;
V_161 -> V_170 =
sizeof( struct V_160 ) ;
V_161 -> V_171 = 2 * V_167 ;
V_161 -> V_172 = V_173 ;
V_161 -> V_174 =
V_161 -> V_170 + V_161 -> V_171 ;
V_161 -> V_175 = 4 * V_156 ;
V_162 = ( T_4 * ) ( ( V_98 ) V_161 + V_161 -> V_170 ) ;
V_163 = ( T_4 * ) ( ( V_98 ) V_161 + V_161 -> V_174 ) ;
V_60 = F_42 ( V_176 , V_167 , V_177 ,
V_162 , V_167 ) ;
if ( V_60 < 0 )
goto V_127;
snprintf ( V_165 , 2 * V_156 + 1 , L_29 , V_159 ) ;
V_60 = F_42 ( V_165 , 2 * V_156 , V_177 ,
V_163 , 2 * V_156 ) ;
if ( V_60 < 0 )
goto V_127;
V_60 = F_17 ( V_77 , V_12 ) ;
if ( V_60 != 0 )
goto V_127;
F_36 ( & V_12 -> V_18 ) ;
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
if ( V_55 -> V_43 != V_81 ) {
F_24 ( V_68 , L_30 ,
V_55 -> V_43 ) ;
V_60 = - V_125 ;
}
V_127:
F_11 ( V_77 , V_12 ) ;
return V_60 ;
}
static int
F_43 ( struct V_31 * V_68 ,
struct V_178 * V_179 )
{
struct V_114 * V_131 = F_41 ( V_68 ) ;
struct V_1 * V_77 = V_131 -> V_118 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_178 * V_180 ;
struct V_164 * V_55 ;
T_1 V_166 = sizeof( struct V_178 ) ;
int V_60 ;
T_1 V_181 = V_131 -> V_134 ;
if ( V_181 <= V_139 ) {
V_166 = V_182 ;
V_179 -> V_183 = 0 ;
V_179 -> V_184 = 0 ;
}
V_12 = F_5 ( V_77 , V_168 ,
F_35 ( struct V_15 ) + V_166 ) ;
if ( ! V_12 )
return - V_126 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_185 ;
V_16 -> V_52 = V_166 ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
V_16 -> V_128 = 0 ;
V_180 = (struct V_178 * ) ( ( V_98 ) V_16 +
V_16 -> V_53 ) ;
* V_180 = * V_179 ;
V_180 -> V_144 . type = V_186 ;
V_180 -> V_144 . V_146 = V_137 ;
V_180 -> V_144 . V_100 = V_166 ;
V_60 = F_17 ( V_77 , V_12 ) ;
if ( V_60 != 0 )
goto V_127;
F_36 ( & V_12 -> V_18 ) ;
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
if ( V_55 -> V_43 != V_81 ) {
F_24 ( V_68 , L_31 ,
V_55 -> V_43 ) ;
V_60 = - V_125 ;
}
V_127:
F_11 ( V_77 , V_12 ) ;
return V_60 ;
}
int F_44 ( struct V_1 * V_77 ,
const T_2 * V_187 , int V_188 )
{
struct V_31 * V_68 = V_77 -> V_68 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_164 * V_55 ;
T_1 V_166 = sizeof( struct V_189 ) +
4 * V_190 + V_191 ;
struct V_189 * V_192 ;
T_1 * V_193 ;
T_2 * V_194 ;
int V_195 , V_60 ;
V_12 = F_5 (
V_77 , V_168 ,
F_35 ( struct V_15 ) + V_166 ) ;
if ( ! V_12 )
return - V_126 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_196 ;
V_16 -> V_52 = V_166 ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
V_16 -> V_128 = 0 ;
V_192 = (struct V_189 * ) ( V_16 + 1 ) ;
V_192 -> V_150 . type = V_197 ;
V_192 -> V_150 . V_152 = V_198 ;
V_192 -> V_150 . V_100 = sizeof( struct V_189 ) ;
V_192 -> V_199 = 0 ;
V_192 -> V_200 = V_201 | V_202 |
V_203 | V_204 |
V_205 ;
V_192 -> V_206 = 4 * V_190 ;
V_192 -> V_207 = sizeof( struct V_189 ) ;
V_192 -> V_208 = V_191 ;
V_192 -> V_209 = V_192 -> V_207 +
V_192 -> V_206 ;
V_193 = ( T_1 * ) ( V_192 + 1 ) ;
for ( V_195 = 0 ; V_195 < V_190 ; V_195 ++ )
V_193 [ V_195 ] = V_77 -> V_210 [ V_195 ] ;
V_194 = ( T_2 * ) ( ( unsigned long ) V_192 + V_192 -> V_209 ) ;
memcpy ( V_194 , V_187 , V_191 ) ;
V_60 = F_17 ( V_77 , V_12 ) ;
if ( V_60 != 0 )
goto V_127;
F_36 ( & V_12 -> V_18 ) ;
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
if ( V_55 -> V_43 == V_81 )
memcpy ( V_77 -> V_187 , V_187 , V_191 ) ;
else {
F_24 ( V_68 , L_32 ,
V_55 -> V_43 ) ;
V_60 = - V_125 ;
}
V_127:
F_11 ( V_77 , V_12 ) ;
return V_60 ;
}
static int F_45 ( struct V_1 * V_9 )
{
T_1 V_100 = sizeof( T_1 ) ;
T_1 V_78 ;
int V_60 ;
V_60 = F_34 ( V_9 ,
V_90 ,
& V_78 , & V_100 ) ;
return V_60 ;
}
static int F_46 ( struct V_1 * V_9 )
{
T_1 V_100 = sizeof( T_1 ) ;
T_1 V_211 ;
struct V_66 * V_212 ;
int V_60 ;
V_60 = F_34 ( V_9 , V_213 ,
& V_211 , & V_100 ) ;
if ( ! V_60 ) {
V_212 = F_18 ( V_9 -> V_68 ) ;
V_212 -> V_214 = V_211 / 10000 ;
}
return V_60 ;
}
int F_47 ( struct V_1 * V_9 , T_1 V_215 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_164 * V_55 ;
int V_60 ;
V_12 = F_5 ( V_9 , V_168 ,
F_35 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_60 = - V_126 ;
goto V_127;
}
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_216 ;
V_16 -> V_52 = sizeof( T_1 ) ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_215 , sizeof( T_1 ) ) ;
V_60 = F_17 ( V_9 , V_12 ) ;
if ( V_60 != 0 )
goto V_127;
F_36 ( & V_12 -> V_18 ) ;
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
V_127:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_60 ;
}
static int F_48 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_217 * V_218 ;
struct V_219 * V_42 ;
T_1 V_43 ;
int V_60 ;
struct V_114 * V_131 = F_41 ( V_9 -> V_68 ) ;
V_12 = F_5 ( V_9 , V_220 ,
F_35 ( struct V_217 ) ) ;
if ( ! V_12 ) {
V_60 = - V_126 ;
goto V_127;
}
V_218 = & V_12 -> V_19 . V_23 . V_85 ;
V_218 -> V_44 = V_221 ;
V_218 -> V_45 = V_222 ;
V_218 -> V_47 = 0x4000 ;
V_9 -> V_6 = V_223 ;
V_60 = F_17 ( V_9 , V_12 ) ;
if ( V_60 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_127;
}
F_36 ( & V_12 -> V_18 ) ;
V_42 = & V_12 -> V_80 . V_23 . V_42 ;
V_43 = V_42 -> V_43 ;
if ( V_43 == V_81 ) {
V_9 -> V_6 = V_224 ;
V_131 -> V_225 = V_42 -> V_48 ;
V_131 -> V_226 = 1 << V_42 -> V_49 ;
V_60 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_60 = - V_125 ;
}
V_127:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_60 ;
}
static bool F_49 ( const struct V_114 * V_131 )
{
int V_195 ;
if ( F_50 ( & V_131 -> V_227 ) > 0 )
return false ;
for ( V_195 = 0 ; V_195 < V_131 -> V_228 ; V_195 ++ ) {
const struct V_229 * V_230 = & V_131 -> V_231 [ V_195 ] ;
if ( F_50 ( & V_230 -> V_232 ) > 0 )
return false ;
}
return true ;
}
static void F_51 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_233 * V_234 ;
struct V_66 * V_67 = F_18 ( V_9 -> V_68 ) ;
struct V_114 * V_131 = V_67 -> V_131 ;
struct V_29 * V_235 = V_67 -> V_76 ;
V_98 V_17 ;
V_12 = F_5 ( V_9 , V_236 ,
F_35 ( struct V_233 ) ) ;
if ( ! V_12 )
goto V_127;
V_234 = & V_12 -> V_19 . V_23 . V_237 ;
V_234 -> V_25 = F_7 ( & V_9 -> V_26 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_127:
F_8 ( & V_235 -> V_102 -> V_238 , V_17 ) ;
V_131 -> V_239 = true ;
F_10 ( & V_235 -> V_102 -> V_238 , V_17 ) ;
V_18 ( V_131 -> V_240 , F_49 ( V_131 ) ) ;
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
}
static int F_52 ( struct V_1 * V_9 )
{
int V_60 ;
if ( V_9 -> V_6 != V_224 )
return 0 ;
V_60 = F_47 ( V_9 ,
V_241 |
V_242 |
V_243 ) ;
if ( V_60 == 0 )
V_9 -> V_6 = V_244 ;
return V_60 ;
}
static int F_53 ( struct V_1 * V_9 )
{
int V_60 ;
if ( V_9 -> V_6 != V_244 )
return 0 ;
V_60 = F_47 ( V_9 , 0 ) ;
if ( V_60 == - V_245 )
V_60 = 0 ;
if ( V_60 == 0 )
V_9 -> V_6 = V_224 ;
return V_60 ;
}
static void F_54 ( struct V_101 * V_246 )
{
struct V_31 * V_68 =
F_15 ( V_246 -> V_247 -> V_248 ) ;
struct V_114 * V_249 = F_41 ( V_68 ) ;
T_5 V_250 = V_246 -> V_251 . V_252 . V_253 ;
int V_60 ;
unsigned long V_17 ;
if ( V_250 >= V_249 -> V_228 )
return;
V_249 -> V_231 [ V_250 ] . V_254 . V_255
= F_55 ( V_256 * sizeof( struct V_257 ) ) ;
V_60 = F_56 ( V_246 , V_249 -> V_258 * V_75 ,
V_249 -> V_258 * V_75 , NULL , 0 ,
V_259 , V_246 ) ;
if ( V_60 == 0 )
V_249 -> V_231 [ V_250 ] . V_102 = V_246 ;
F_8 ( & V_249 -> V_260 , V_17 ) ;
V_249 -> V_261 -- ;
F_10 ( & V_249 -> V_260 , V_17 ) ;
if ( V_249 -> V_261 == 0 )
F_25 ( & V_249 -> V_262 ) ;
}
int F_57 ( struct V_29 * V_9 ,
struct V_263 * V_264 )
{
struct V_31 * V_265 = F_15 ( V_9 ) ;
struct V_66 * V_67 = F_18 ( V_265 ) ;
struct V_114 * V_31 ;
struct V_1 * V_1 ;
struct V_132 V_133 ;
struct V_178 V_266 ;
struct V_267 * V_268 ;
struct V_148 V_269 ;
T_1 V_270 = sizeof( struct V_148 ) ;
unsigned int V_271 = V_272 ;
T_1 V_273 , V_100 ;
T_1 V_274 ;
T_1 V_275 ;
const struct V_276 * V_277 ;
T_1 V_278 ;
unsigned long V_17 ;
int V_195 , V_60 ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_245 ;
V_60 = F_58 ( V_9 , V_264 ) ;
if ( V_60 != 0 ) {
F_13 ( V_1 ) ;
return V_60 ;
}
V_31 = V_67 -> V_131 ;
V_31 -> V_279 = 1 ;
V_31 -> V_228 = 1 ;
F_3 ( & V_31 -> V_260 ) ;
V_31 -> V_118 = V_1 ;
V_1 -> V_68 = V_265 ;
V_60 = F_48 ( V_1 ) ;
if ( V_60 != 0 ) {
F_59 ( V_9 , V_31 ) ;
return V_60 ;
}
V_100 = sizeof( T_1 ) ;
V_60 = F_34 ( V_1 ,
V_280 ,
& V_273 , & V_100 ) ;
if ( V_60 == 0 && V_100 == sizeof( T_1 ) && V_273 < V_265 -> V_273 )
V_265 -> V_273 = V_273 ;
V_60 = F_39 ( V_1 ) ;
if ( V_60 != 0 ) {
F_59 ( V_9 , V_31 ) ;
return V_60 ;
}
memcpy ( V_264 -> V_281 , V_1 -> V_158 , V_156 ) ;
V_60 = F_37 ( V_1 , & V_133 ) ;
if ( V_60 != 0 ) {
F_59 ( V_9 , V_31 ) ;
return V_60 ;
}
memset ( & V_266 , 0 , sizeof( struct V_178 ) ) ;
V_266 . V_282 = V_283 ;
V_265 -> V_284 = V_285 ;
if ( ( V_133 . V_286 . V_287 & V_288 ) == V_288 ) {
V_265 -> V_284 |= V_289 ;
V_67 -> V_290 |= V_291 ;
V_266 . V_292 = V_293 ;
if ( V_133 . V_294 . V_295 & V_296 ) {
V_266 . V_297 = V_298 ;
V_265 -> V_284 |= V_299 ;
if ( V_133 . V_294 . V_300 < V_271 )
V_271 = V_133 . V_294 . V_300 ;
}
if ( V_133 . V_286 . V_287 & V_301 ) {
V_266 . V_183 = V_293 ;
V_67 -> V_290 |= V_302 ;
}
}
if ( ( V_133 . V_286 . V_303 & V_304 ) == V_304 ) {
V_265 -> V_284 |= V_305 ;
V_266 . V_306 = V_293 ;
V_67 -> V_290 |= V_307 ;
if ( ( V_133 . V_294 . V_308 & V_296 ) &&
( V_133 . V_294 . V_309 & V_310 ) == V_310 ) {
V_266 . V_311 = V_298 ;
V_265 -> V_284 |= V_312 ;
if ( V_133 . V_294 . V_313 < V_271 )
V_271 = V_133 . V_294 . V_313 ;
}
if ( V_133 . V_286 . V_303 & V_314 ) {
V_266 . V_184 = V_293 ;
V_67 -> V_290 |= V_315 ;
}
}
F_60 ( V_265 , V_271 ) ;
V_60 = F_43 ( V_265 , & V_266 ) ;
if ( V_60 )
goto V_316;
F_45 ( V_1 ) ;
V_264 -> V_82 = V_1 -> V_82 ;
F_16 ( V_265 , L_33 ,
V_1 -> V_158 ,
V_264 -> V_82 ? L_34 : L_35 ) ;
if ( V_31 -> V_134 < V_136 )
return 0 ;
F_46 ( V_1 ) ;
memset ( & V_269 , 0 , V_270 ) ;
V_60 = F_34 ( V_1 ,
V_147 ,
& V_269 , & V_270 ) ;
if ( V_60 || V_269 . V_317 < 2 )
goto V_318;
V_31 -> V_279 = F_61 ( T_1 , V_319 , V_269 . V_317 ) ;
V_274 = F_62 ( V_264 -> V_320 , V_31 -> V_279 ) ;
V_277 = F_63 ( F_64 ( V_9 -> V_102 -> V_321 ) ) ;
V_278 = F_65 ( V_277 ) ;
if ( V_264 -> V_228 && V_264 -> V_228 < V_31 -> V_279 )
V_31 -> V_228 = V_264 -> V_228 ;
else
V_31 -> V_228 = F_62 ( V_278 , V_274 ) ;
V_274 = V_31 -> V_228 - 1 ;
for ( V_195 = 0 ; V_195 < V_190 ; V_195 ++ )
V_1 -> V_210 [ V_195 ] = F_66 ( V_195 ,
V_31 -> V_228 ) ;
V_31 -> V_261 = V_274 ;
if ( V_31 -> V_228 == 1 )
goto V_318;
F_67 ( V_9 -> V_102 , F_54 ) ;
V_268 = & V_31 -> V_322 ;
memset ( V_268 , 0 , sizeof( struct V_267 ) ) ;
V_268 -> V_150 . V_10 = V_323 ;
V_268 -> V_23 . V_324 . V_325 . V_326 = V_327 ;
V_268 -> V_23 . V_324 . V_325 . V_328 =
V_31 -> V_228 - 1 ;
V_60 = F_68 ( V_9 -> V_102 , V_268 ,
sizeof( struct V_267 ) ,
( unsigned long ) V_268 ,
V_329 ,
V_330 ) ;
if ( V_60 )
goto V_318;
F_36 ( & V_31 -> V_262 ) ;
if ( V_268 -> V_23 . V_324 . V_331 . V_43 !=
V_332 ) {
V_60 = - V_245 ;
goto V_318;
}
V_31 -> V_228 = 1 +
V_268 -> V_23 . V_324 . V_331 . V_328 ;
V_60 = F_44 ( V_1 , V_333 ,
V_31 -> V_228 ) ;
F_8 ( & V_31 -> V_260 , V_17 ) ;
V_275 = V_274 - ( V_31 -> V_228 - 1 ) ;
V_31 -> V_261 -= V_275 ;
F_10 ( & V_31 -> V_260 , V_17 ) ;
V_318:
if ( V_60 ) {
V_31 -> V_279 = 1 ;
V_31 -> V_228 = 1 ;
V_31 -> V_261 = 0 ;
}
return 0 ;
V_316:
F_59 ( V_9 , V_31 ) ;
return V_60 ;
}
void F_59 ( struct V_29 * V_9 ,
struct V_114 * V_115 )
{
struct V_1 * V_117 = V_115 -> V_118 ;
if ( V_115 -> V_261 > 0 )
F_36 ( & V_115 -> V_262 ) ;
F_51 ( V_117 ) ;
F_13 ( V_117 ) ;
V_115 -> V_118 = NULL ;
F_69 ( V_9 ) ;
}
int F_70 ( struct V_114 * V_131 )
{
if ( ! V_131 )
return - V_125 ;
if ( F_7 ( & V_131 -> V_334 ) != 1 )
return 0 ;
return F_52 ( V_131 -> V_118 ) ;
}
int F_71 ( struct V_114 * V_131 )
{
if ( ! V_131 )
return - V_125 ;
if ( F_72 ( & V_131 -> V_334 ) != 0 )
return 0 ;
return F_53 ( V_131 -> V_118 ) ;
}
