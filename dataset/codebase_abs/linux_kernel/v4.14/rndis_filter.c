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
struct V_62 * V_63 ;
struct V_64 V_65 [ 2 ] ;
struct V_64 * V_66 = V_65 ;
struct V_67 * V_68 = F_19 ( V_11 -> V_69 ) ;
int V_70 ;
V_63 = & V_30 -> V_23 ;
V_63 -> V_71 = V_30 -> V_21 . V_13 ;
V_63 -> V_72 = 1 ;
V_66 [ 0 ] . V_73 = F_20 ( & V_30 -> V_21 ) >>
V_74 ;
V_66 [ 0 ] . V_75 = V_30 -> V_21 . V_13 ;
V_66 [ 0 ] . V_76 =
( unsigned long ) & V_30 -> V_21 & ( V_77 - 1 ) ;
if ( V_66 [ 0 ] . V_76 + V_66 [ 0 ] . V_75 > V_77 ) {
V_63 -> V_72 ++ ;
V_66 [ 0 ] . V_75 = V_77 -
V_66 [ 0 ] . V_76 ;
V_66 [ 1 ] . V_73 = F_20 ( ( void * ) & V_30 -> V_21
+ V_66 [ 0 ] . V_75 ) >> V_74 ;
V_66 [ 1 ] . V_76 = 0 ;
V_66 [ 1 ] . V_75 = V_30 -> V_21 . V_13 -
V_66 [ 0 ] . V_75 ;
}
F_21 () ;
V_70 = F_22 ( V_68 , V_63 , NULL , V_66 , NULL ) ;
F_23 () ;
return V_70 ;
}
static void F_24 ( struct V_1 * V_78 ,
struct V_10 * V_14 )
{
T_1 V_79 ;
struct V_80 * V_53 ;
V_53 = & V_14 -> V_81 . V_25 . V_53 ;
if ( V_53 -> V_45 == V_82 &&
V_53 -> V_54 == sizeof( T_1 ) ) {
memcpy ( & V_79 , ( void * ) ( ( unsigned long ) V_53 +
V_53 -> V_55 ) , sizeof( T_1 ) ) ;
V_78 -> V_83 = V_79 != 0 ;
}
}
static void F_25 ( struct V_1 * V_11 ,
struct V_15 * V_84 )
{
struct V_10 * V_14 = NULL ;
bool V_85 = false ;
unsigned long V_19 ;
struct V_33 * V_69 = V_11 -> V_69 ;
F_9 ( & V_11 -> V_4 , V_19 ) ;
F_26 (request, &dev->req_list, list_ent) {
if ( V_14 -> V_21 . V_25 . V_86 . V_27
== V_84 -> V_25 . V_44 . V_27 ) {
V_85 = true ;
break;
}
}
F_11 ( & V_11 -> V_4 , V_19 ) ;
if ( V_85 ) {
if ( V_84 -> V_13 <=
sizeof( struct V_15 ) + V_87 ) {
memcpy ( & V_14 -> V_81 , V_84 ,
V_84 -> V_13 ) ;
if ( V_14 -> V_21 . V_22 ==
V_88 && V_14 -> V_21 . V_25 .
V_89 . V_90 == V_91 )
F_24 ( V_11 , V_14 ) ;
} else {
F_27 ( V_69 ,
L_16
L_17 ,
V_84 -> V_13 ,
sizeof( struct V_15 ) ) ;
if ( V_84 -> V_22 ==
V_92 ) {
V_14 -> V_81 . V_25 . V_93 .
V_45 = V_94 ;
} else {
V_14 -> V_81 . V_25 .
V_44 . V_45 =
V_94 ;
}
}
F_28 ( & V_14 -> V_20 ) ;
} else {
F_27 ( V_69 ,
L_18
L_19 ,
V_84 -> V_25 . V_44 . V_27 ,
V_84 -> V_22 ) ;
}
}
static inline void * F_29 ( struct V_95 * V_96 , T_1 type )
{
struct V_97 * V_98 ;
int V_75 ;
if ( V_96 -> V_41 == 0 )
return NULL ;
V_98 = (struct V_97 * ) ( ( V_99 ) V_96 +
V_96 -> V_41 ) ;
V_75 = V_96 -> V_42 ;
while ( V_75 > 0 ) {
if ( V_98 -> type == type )
return ( void * ) ( ( V_99 ) V_98 + V_98 -> V_100 ) ;
V_75 -= V_98 -> V_101 ;
V_98 = (struct V_97 * ) ( ( V_99 ) V_98 + V_98 -> V_101 ) ;
}
return NULL ;
}
static int F_30 ( struct V_33 * V_69 ,
struct V_1 * V_11 ,
struct V_15 * V_25 ,
struct V_102 * V_103 ,
void * V_104 , T_1 V_105 )
{
struct V_95 * V_106 = & V_25 -> V_25 . V_23 ;
const struct V_107 * V_108 ;
const struct V_109 * V_110 ;
T_1 V_36 ;
V_36 = V_111 + V_106 -> V_36 ;
V_105 -= V_36 ;
if ( F_31 ( V_105 < V_106 -> V_37 ) ) {
F_27 ( V_11 -> V_69 , L_20
L_21
L_22 ,
V_105 , V_106 -> V_37 ) ;
return V_112 ;
}
V_110 = F_29 ( V_106 , V_113 ) ;
V_104 = ( void * ) ( ( unsigned long ) V_104 + V_36 ) ;
V_108 = F_29 ( V_106 , V_114 ) ;
return F_32 ( V_69 , V_103 ,
V_104 , V_106 -> V_37 ,
V_108 , V_110 ) ;
}
int F_33 ( struct V_33 * V_69 ,
struct V_115 * V_116 ,
struct V_31 * V_11 ,
struct V_102 * V_103 ,
void * V_104 , T_1 V_117 )
{
struct V_67 * V_68 = F_19 ( V_69 ) ;
struct V_1 * V_118 = V_116 -> V_119 ;
struct V_15 * V_16 = V_104 ;
if ( F_31 ( ! V_118 ) ) {
F_34 ( V_68 , V_120 , V_69 ,
L_23 ) ;
return V_112 ;
}
if ( F_31 ( V_118 -> V_8 == V_9 ) ) {
F_34 ( V_68 , V_120 , V_69 ,
L_24 ) ;
return V_112 ;
}
if ( F_35 ( V_68 ) )
F_15 ( V_11 , V_16 ) ;
switch ( V_16 -> V_22 ) {
case V_35 :
return F_30 ( V_69 , V_118 , V_16 ,
V_103 , V_104 , V_117 ) ;
case V_43 :
case V_52 :
case V_56 :
F_25 ( V_118 , V_16 ) ;
break;
case V_58 :
F_36 ( V_11 , V_16 ) ;
break;
default:
F_27 ( V_69 ,
L_25 ,
V_16 -> V_22 ,
V_16 -> V_13 ) ;
break;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_11 ,
struct V_115 * V_121 ,
T_1 V_90 , void * V_122 , T_1 * V_123 )
{
struct V_10 * V_14 ;
T_1 V_124 = * V_123 ;
struct V_125 * V_126 ;
struct V_80 * V_53 ;
int V_70 = 0 ;
if ( ! V_122 )
return - V_127 ;
* V_123 = 0 ;
V_14 = F_6 ( V_11 , V_88 ,
F_38 ( struct V_125 ) ) ;
if ( ! V_14 ) {
V_70 = - V_128 ;
goto V_129;
}
V_126 = & V_14 -> V_21 . V_25 . V_89 ;
V_126 -> V_90 = V_90 ;
V_126 -> V_55 = sizeof( struct V_125 ) ;
V_126 -> V_54 = 0 ;
V_126 -> V_130 = 0 ;
if ( V_90 == V_131 ) {
struct V_132 * V_133 ;
T_1 V_134 = V_121 -> V_134 ;
T_2 V_135 ;
T_3 V_101 ;
if ( V_134 >= V_136 ) {
V_135 = V_137 ;
V_101 = V_138 ;
} else if ( V_134 >= V_139 ) {
V_135 = V_140 ;
V_101 = V_141 ;
} else {
V_135 = V_142 ;
V_101 = V_143 ;
}
V_14 -> V_21 . V_13 += V_101 ;
V_126 -> V_54 = V_101 ;
V_133 = (struct V_132 * )
( ( unsigned long ) V_126 + V_126 -> V_55 ) ;
V_133 -> V_144 . type = V_145 ;
V_133 -> V_144 . V_146 = V_135 ;
V_133 -> V_144 . V_101 = V_101 ;
} else if ( V_90 == V_147 ) {
struct V_148 * V_149 ;
V_14 -> V_21 . V_13 +=
sizeof( struct V_148 ) ;
V_126 -> V_54 = sizeof( struct V_148 ) ;
V_149 = (struct V_148 * ) ( ( unsigned long ) V_126 +
V_126 -> V_55 ) ;
V_149 -> V_150 . type = V_151 ;
V_149 -> V_150 . V_152 = V_153 ;
V_149 -> V_150 . V_101 = sizeof( struct V_148 ) ;
}
V_70 = F_18 ( V_11 , V_14 ) ;
if ( V_70 != 0 )
goto V_129;
F_39 ( & V_14 -> V_20 ) ;
V_53 = & V_14 -> V_81 . V_25 . V_53 ;
if ( V_53 -> V_54 > V_124 ) {
V_70 = - 1 ;
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
return V_70 ;
}
static int
F_40 ( struct V_1 * V_11 , struct V_115 * V_33 ,
struct V_132 * V_154 )
{
T_1 V_155 = sizeof( * V_154 ) ;
int V_70 ;
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
V_70 = F_37 ( V_11 , V_33 ,
V_131 ,
V_154 , & V_155 ) ;
if ( V_70 )
return V_70 ;
if ( V_154 -> V_144 . type != V_145 ) {
F_41 ( V_11 -> V_69 , L_26 ,
V_154 -> V_144 . type ) ;
return - V_127 ;
}
if ( V_154 -> V_144 . V_146 < V_142 ) {
F_41 ( V_11 -> V_69 , L_27 ,
V_154 -> V_144 . V_146 ) ;
return - V_127 ;
}
if ( V_154 -> V_144 . V_101 > V_155 ||
V_154 -> V_144 . V_101 < V_143 ) {
F_41 ( V_11 -> V_69 ,
L_28 ,
V_154 -> V_144 . V_101 , V_155 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_11 ,
struct V_115 * V_33 )
{
T_1 V_101 = V_156 ;
return F_37 ( V_11 , V_33 ,
V_157 ,
V_11 -> V_158 , & V_101 ) ;
}
int F_43 ( struct V_115 * V_121 ,
const char * V_159 )
{
struct V_1 * V_78 = V_121 -> V_119 ;
struct V_10 * V_14 ;
struct V_17 * V_18 ;
struct V_160 * V_161 ;
T_4 * V_162 , * V_163 ;
struct V_164 * V_57 ;
char V_165 [ 2 * V_156 + 1 ] ;
T_1 V_166 = sizeof( struct V_160 ) +
2 * V_167 + 4 * V_156 ;
int V_70 ;
V_14 = F_6 ( V_78 , V_168 ,
F_38 ( struct V_17 ) + V_166 ) ;
if ( ! V_14 )
return - V_128 ;
V_18 = & V_14 -> V_21 . V_25 . V_26 ;
V_18 -> V_90 = V_169 ;
V_18 -> V_54 = V_166 ;
V_18 -> V_55 = sizeof( struct V_17 ) ;
V_18 -> V_130 = 0 ;
V_161 = (struct V_160 * ) ( ( V_99 ) V_18 +
V_18 -> V_55 ) ;
V_161 -> V_170 =
sizeof( struct V_160 ) ;
V_161 -> V_171 = 2 * V_167 ;
V_161 -> V_172 = V_173 ;
V_161 -> V_174 =
V_161 -> V_170 + V_161 -> V_171 ;
V_161 -> V_175 = 4 * V_156 ;
V_162 = ( T_4 * ) ( ( V_99 ) V_161 + V_161 -> V_170 ) ;
V_163 = ( T_4 * ) ( ( V_99 ) V_161 + V_161 -> V_174 ) ;
V_70 = F_44 ( V_176 , V_167 , V_177 ,
V_162 , V_167 ) ;
if ( V_70 < 0 )
goto V_129;
snprintf ( V_165 , 2 * V_156 + 1 , L_29 , V_159 ) ;
V_70 = F_44 ( V_165 , 2 * V_156 , V_177 ,
V_163 , 2 * V_156 ) ;
if ( V_70 < 0 )
goto V_129;
V_70 = F_18 ( V_78 , V_14 ) ;
if ( V_70 != 0 )
goto V_129;
F_39 ( & V_14 -> V_20 ) ;
V_57 = & V_14 -> V_81 . V_25 . V_57 ;
if ( V_57 -> V_45 != V_82 )
V_70 = - V_178 ;
V_129:
F_12 ( V_78 , V_14 ) ;
return V_70 ;
}
static int
F_45 ( struct V_33 * V_69 ,
struct V_115 * V_121 ,
struct V_179 * V_180 )
{
struct V_1 * V_78 = V_121 -> V_119 ;
struct V_10 * V_14 ;
struct V_17 * V_18 ;
struct V_179 * V_181 ;
struct V_164 * V_57 ;
T_1 V_166 = sizeof( struct V_179 ) ;
int V_70 ;
T_1 V_182 = V_121 -> V_134 ;
if ( V_182 <= V_139 ) {
V_166 = V_183 ;
V_180 -> V_184 = 0 ;
V_180 -> V_185 = 0 ;
}
V_14 = F_6 ( V_78 , V_168 ,
F_38 ( struct V_17 ) + V_166 ) ;
if ( ! V_14 )
return - V_128 ;
V_18 = & V_14 -> V_21 . V_25 . V_26 ;
V_18 -> V_90 = V_186 ;
V_18 -> V_54 = V_166 ;
V_18 -> V_55 = sizeof( struct V_17 ) ;
V_18 -> V_130 = 0 ;
V_181 = (struct V_179 * ) ( ( V_99 ) V_18 +
V_18 -> V_55 ) ;
* V_181 = * V_180 ;
V_181 -> V_144 . type = V_187 ;
V_181 -> V_144 . V_146 = V_137 ;
V_181 -> V_144 . V_101 = V_166 ;
V_70 = F_18 ( V_78 , V_14 ) ;
if ( V_70 != 0 )
goto V_129;
F_39 ( & V_14 -> V_20 ) ;
V_57 = & V_14 -> V_81 . V_25 . V_57 ;
if ( V_57 -> V_45 != V_82 ) {
F_27 ( V_69 , L_30 ,
V_57 -> V_45 ) ;
V_70 = - V_127 ;
}
V_129:
F_12 ( V_78 , V_14 ) ;
return V_70 ;
}
int F_46 ( struct V_1 * V_78 ,
const T_2 * V_188 )
{
struct V_33 * V_69 = V_78 -> V_69 ;
struct V_10 * V_14 ;
struct V_17 * V_18 ;
struct V_164 * V_57 ;
T_1 V_166 = sizeof( struct V_189 ) +
4 * V_190 + V_191 ;
struct V_189 * V_192 ;
T_1 * V_193 ;
T_2 * V_194 ;
int V_195 , V_70 ;
V_14 = F_6 (
V_78 , V_168 ,
F_38 ( struct V_17 ) + V_166 ) ;
if ( ! V_14 )
return - V_128 ;
V_18 = & V_14 -> V_21 . V_25 . V_26 ;
V_18 -> V_90 = V_196 ;
V_18 -> V_54 = V_166 ;
V_18 -> V_55 = sizeof( struct V_17 ) ;
V_18 -> V_130 = 0 ;
V_192 = (struct V_189 * ) ( V_18 + 1 ) ;
V_192 -> V_150 . type = V_197 ;
V_192 -> V_150 . V_152 = V_198 ;
V_192 -> V_150 . V_101 = sizeof( struct V_189 ) ;
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
V_193 [ V_195 ] = V_78 -> V_210 [ V_195 ] ;
V_194 = ( T_2 * ) ( ( unsigned long ) V_192 + V_192 -> V_209 ) ;
memcpy ( V_194 , V_188 , V_191 ) ;
V_70 = F_18 ( V_78 , V_14 ) ;
if ( V_70 != 0 )
goto V_129;
F_39 ( & V_14 -> V_20 ) ;
V_57 = & V_14 -> V_81 . V_25 . V_57 ;
if ( V_57 -> V_45 == V_82 )
memcpy ( V_78 -> V_188 , V_188 , V_191 ) ;
else {
F_27 ( V_69 , L_31 ,
V_57 -> V_45 ) ;
V_70 = - V_127 ;
}
V_129:
F_12 ( V_78 , V_14 ) ;
return V_70 ;
}
static int F_47 ( struct V_1 * V_11 ,
struct V_115 * V_33 )
{
T_1 V_101 = sizeof( T_1 ) ;
T_1 V_79 ;
return F_37 ( V_11 , V_33 ,
V_91 ,
& V_79 , & V_101 ) ;
}
static int F_48 ( struct V_1 * V_11 ,
struct V_115 * V_33 )
{
T_1 V_101 = sizeof( T_1 ) ;
T_1 V_211 ;
struct V_67 * V_212 ;
int V_70 ;
V_70 = F_37 ( V_11 , V_33 ,
V_213 ,
& V_211 , & V_101 ) ;
if ( ! V_70 ) {
V_212 = F_19 ( V_11 -> V_69 ) ;
V_212 -> V_214 = V_211 / 10000 ;
}
return V_70 ;
}
static int F_49 ( struct V_1 * V_11 ,
T_1 V_215 )
{
struct V_10 * V_14 ;
struct V_17 * V_18 ;
int V_70 ;
V_14 = F_6 ( V_11 , V_168 ,
F_38 ( struct V_17 ) +
sizeof( T_1 ) ) ;
if ( ! V_14 )
return - V_128 ;
V_18 = & V_14 -> V_21 . V_25 . V_26 ;
V_18 -> V_90 = V_216 ;
V_18 -> V_54 = sizeof( T_1 ) ;
V_18 -> V_55 = sizeof( struct V_17 ) ;
memcpy ( ( void * ) ( unsigned long ) V_18 + sizeof( struct V_17 ) ,
& V_215 , sizeof( T_1 ) ) ;
V_70 = F_18 ( V_11 , V_14 ) ;
if ( V_70 == 0 )
F_39 ( & V_14 -> V_20 ) ;
F_12 ( V_11 , V_14 ) ;
return V_70 ;
}
static void V_7 ( struct V_217 * V_218 )
{
struct V_1 * V_78
= F_50 ( V_218 , struct V_1 , V_6 ) ;
if ( V_78 -> V_69 -> V_19 & V_219 )
F_49 ( V_78 ,
V_220 ) ;
else
F_49 ( V_78 ,
V_221 |
V_222 |
V_223 ) ;
}
void F_51 ( struct V_115 * V_121 )
{
struct V_1 * V_78 = V_121 -> V_119 ;
F_52 ( & V_78 -> V_6 ) ;
}
static int F_53 ( struct V_1 * V_11 ,
struct V_115 * V_121 )
{
struct V_10 * V_14 ;
struct V_224 * V_225 ;
struct V_226 * V_44 ;
T_1 V_45 ;
int V_70 ;
V_14 = F_6 ( V_11 , V_227 ,
F_38 ( struct V_224 ) ) ;
if ( ! V_14 ) {
V_70 = - V_128 ;
goto V_129;
}
V_225 = & V_14 -> V_21 . V_25 . V_86 ;
V_225 -> V_46 = V_228 ;
V_225 -> V_47 = V_229 ;
V_225 -> V_49 = 0x4000 ;
V_11 -> V_8 = V_230 ;
V_70 = F_18 ( V_11 , V_14 ) ;
if ( V_70 != 0 ) {
V_11 -> V_8 = V_9 ;
goto V_129;
}
F_39 ( & V_14 -> V_20 ) ;
V_44 = & V_14 -> V_81 . V_25 . V_44 ;
V_45 = V_44 -> V_45 ;
if ( V_45 == V_82 ) {
V_11 -> V_8 = V_231 ;
V_121 -> V_232 = V_44 -> V_50 ;
V_121 -> V_233 = 1 << V_44 -> V_51 ;
V_70 = 0 ;
} else {
V_11 -> V_8 = V_9 ;
V_70 = - V_127 ;
}
V_129:
if ( V_14 )
F_12 ( V_11 , V_14 ) ;
return V_70 ;
}
static bool F_54 ( const struct V_115 * V_121 )
{
int V_195 ;
for ( V_195 = 0 ; V_195 < V_121 -> V_234 ; V_195 ++ ) {
const struct V_235 * V_236 = & V_121 -> V_237 [ V_195 ] ;
if ( V_236 -> V_238 . V_239 != V_236 -> V_238 . V_240 )
return false ;
if ( F_55 ( & V_236 -> V_241 ) > 0 )
return false ;
}
return true ;
}
static void F_56 ( struct V_1 * V_11 )
{
struct V_10 * V_14 ;
struct V_242 * V_243 ;
struct V_67 * V_68 = F_19 ( V_11 -> V_69 ) ;
struct V_115 * V_121 = F_57 ( V_68 -> V_121 ) ;
V_14 = F_6 ( V_11 , V_244 ,
F_38 ( struct V_242 ) ) ;
if ( ! V_14 )
goto V_129;
V_243 = & V_14 -> V_21 . V_25 . V_245 ;
V_243 -> V_27 = F_8 ( & V_11 -> V_28 ) ;
F_18 ( V_11 , V_14 ) ;
V_11 -> V_8 = V_9 ;
V_129:
V_121 -> V_246 = true ;
F_58 () ;
V_20 ( V_121 -> V_247 , F_54 ( V_121 ) ) ;
if ( V_14 )
F_12 ( V_11 , V_14 ) ;
}
static int F_59 ( struct V_1 * V_11 )
{
int V_70 ;
if ( V_11 -> V_8 != V_231 )
return 0 ;
V_70 = F_49 ( V_11 ,
V_221 |
V_222 |
V_223 ) ;
if ( V_70 == 0 )
V_11 -> V_8 = V_248 ;
return V_70 ;
}
static int F_60 ( struct V_1 * V_11 )
{
int V_70 ;
if ( V_11 -> V_8 != V_248 )
return 0 ;
F_61 ( & V_11 -> V_6 ) ;
V_70 = F_49 ( V_11 , 0 ) ;
if ( V_70 == - V_249 )
V_70 = 0 ;
if ( V_70 == 0 )
V_11 -> V_8 = V_231 ;
return V_70 ;
}
static void F_62 ( struct V_102 * V_250 )
{
struct V_33 * V_69 =
F_16 ( V_250 -> V_251 -> V_252 ) ;
struct V_67 * V_253 = F_19 ( V_69 ) ;
struct V_115 * V_254 ;
T_5 V_255 = V_250 -> V_256 . V_257 . V_258 ;
struct V_235 * V_236 ;
int V_70 ;
V_254 = F_63 ( V_253 -> V_121 ) ;
if ( ! V_254 || V_255 >= V_254 -> V_234 )
return;
V_236 = V_254 -> V_237 + V_255 ;
F_64 ( V_250 , V_259 ) ;
V_236 -> V_103 = V_250 ;
V_70 = F_65 ( V_250 , V_254 -> V_260 * V_77 ,
V_254 -> V_260 * V_77 , NULL , 0 ,
V_261 , V_236 ) ;
if ( V_70 == 0 )
F_66 ( & V_236 -> V_262 ) ;
else
F_67 ( V_69 , L_32 , V_70 ) ;
if ( F_8 ( & V_254 -> V_263 ) == V_254 -> V_234 )
F_68 ( & V_254 -> V_264 ) ;
}
void F_69 ( struct V_217 * V_218 )
{
struct V_115 * V_121
= F_50 ( V_218 , struct V_115 , V_265 ) ;
struct V_266 * V_267 = & V_121 -> V_268 ;
struct V_67 * V_253 ;
struct V_1 * V_78 ;
struct V_33 * V_69 ;
struct V_31 * V_32 ;
int V_195 , V_70 ;
if ( ! F_70 () ) {
F_52 ( V_218 ) ;
return;
}
V_78 = V_121 -> V_119 ;
if ( ! V_78 )
goto V_269;
V_69 = V_78 -> V_69 ;
V_253 = F_19 ( V_69 ) ;
V_32 = V_253 -> V_270 ;
memset ( V_267 , 0 , sizeof( struct V_266 ) ) ;
V_267 -> V_150 . V_12 = V_271 ;
V_267 -> V_25 . V_272 . V_273 . V_274 = V_275 ;
V_267 -> V_25 . V_272 . V_273 . V_276 =
V_121 -> V_234 - 1 ;
V_70 = F_71 ( V_32 -> V_103 , V_267 ,
sizeof( struct V_266 ) ,
( unsigned long ) V_267 ,
V_277 ,
V_278 ) ;
if ( V_70 ) {
F_27 ( V_69 , L_33 , V_70 ) ;
goto V_279;
}
F_39 ( & V_121 -> V_280 ) ;
if ( V_267 -> V_25 . V_272 . V_281 . V_45 != V_282 ) {
F_27 ( V_69 , L_34 ) ;
goto V_279;
}
V_121 -> V_234 = 1 +
V_267 -> V_25 . V_272 . V_281 . V_276 ;
V_20 ( V_121 -> V_264 ,
F_55 ( & V_121 -> V_263 ) == V_121 -> V_234 ) ;
F_46 ( V_78 , V_283 ) ;
F_72 ( V_69 , V_121 -> V_234 ) ;
F_73 ( V_69 , V_121 -> V_234 ) ;
F_74 () ;
return;
V_279:
for ( V_195 = 1 ; V_195 < V_121 -> V_234 ; V_195 ++ )
F_75 ( & V_121 -> V_237 [ V_195 ] . V_262 ) ;
V_121 -> V_284 = 1 ;
V_121 -> V_234 = 1 ;
V_269:
F_74 () ;
}
struct V_115 * F_76 ( struct V_31 * V_11 ,
struct V_285 * V_286 )
{
struct V_33 * V_287 = F_16 ( V_11 ) ;
struct V_67 * V_68 = F_19 ( V_287 ) ;
struct V_115 * V_33 ;
struct V_1 * V_1 ;
struct V_132 V_133 ;
struct V_179 V_288 ;
struct V_148 V_289 ;
T_1 V_290 = sizeof( struct V_148 ) ;
unsigned int V_291 = V_292 ;
T_1 V_293 , V_101 ;
const struct V_294 * V_295 ;
T_1 V_296 ;
int V_195 , V_70 ;
V_1 = F_1 () ;
if ( ! V_1 )
return F_77 ( - V_249 ) ;
V_33 = F_78 ( V_11 , V_286 ) ;
if ( F_79 ( V_33 ) ) {
F_14 ( V_1 ) ;
return V_33 ;
}
V_33 -> V_284 = 1 ;
V_33 -> V_234 = 1 ;
V_33 -> V_119 = V_1 ;
V_1 -> V_69 = V_287 ;
V_70 = F_53 ( V_1 , V_33 ) ;
if ( V_70 != 0 )
goto V_297;
V_101 = sizeof( T_1 ) ;
V_70 = F_37 ( V_1 , V_33 ,
V_298 ,
& V_293 , & V_101 ) ;
if ( V_70 == 0 && V_101 == sizeof( T_1 ) && V_293 < V_287 -> V_293 )
V_287 -> V_293 = V_293 ;
V_70 = F_42 ( V_1 , V_33 ) ;
if ( V_70 != 0 )
goto V_297;
memcpy ( V_286 -> V_299 , V_1 -> V_158 , V_156 ) ;
V_70 = F_40 ( V_1 , V_33 , & V_133 ) ;
if ( V_70 != 0 )
goto V_297;
memset ( & V_288 , 0 , sizeof( struct V_179 ) ) ;
V_288 . V_300 = V_301 ;
V_287 -> V_302 = V_303 ;
if ( ( V_133 . V_304 . V_305 & V_306 ) == V_306 ) {
V_287 -> V_302 |= V_307 ;
V_68 -> V_308 |= V_309 ;
V_288 . V_310 = V_311 ;
if ( V_133 . V_312 . V_313 & V_314 ) {
V_288 . V_315 = V_316 ;
V_287 -> V_302 |= V_317 ;
if ( V_133 . V_312 . V_318 < V_291 )
V_291 = V_133 . V_312 . V_318 ;
}
if ( V_133 . V_304 . V_305 & V_319 ) {
V_288 . V_184 = V_311 ;
V_68 -> V_308 |= V_320 ;
}
}
if ( ( V_133 . V_304 . V_321 & V_322 ) == V_322 ) {
V_287 -> V_302 |= V_323 ;
V_288 . V_324 = V_311 ;
V_68 -> V_308 |= V_325 ;
if ( ( V_133 . V_312 . V_326 & V_314 ) &&
( V_133 . V_312 . V_327 & V_328 ) == V_328 ) {
V_288 . V_329 = V_316 ;
V_287 -> V_302 |= V_330 ;
if ( V_133 . V_312 . V_331 < V_291 )
V_291 = V_133 . V_312 . V_331 ;
}
if ( V_133 . V_304 . V_321 & V_332 ) {
V_288 . V_185 = V_311 ;
V_68 -> V_308 |= V_333 ;
}
}
F_80 ( V_287 , V_291 ) ;
V_70 = F_45 ( V_287 , V_33 , & V_288 ) ;
if ( V_70 )
goto V_297;
F_47 ( V_1 , V_33 ) ;
F_17 ( V_287 , L_35 ,
V_1 -> V_158 ,
V_1 -> V_83 ? L_36 : L_37 ) ;
if ( V_33 -> V_134 < V_136 )
return V_33 ;
F_48 ( V_1 , V_33 ) ;
memset ( & V_289 , 0 , V_290 ) ;
V_70 = F_37 ( V_1 , V_33 ,
V_147 ,
& V_289 , & V_290 ) ;
if ( V_70 || V_289 . V_334 < 2 )
goto V_335;
V_295 = F_81 ( F_82 ( V_11 -> V_103 -> V_336 ) ) ;
V_296 = F_83 ( T_1 , F_84 ( V_295 ) ,
V_289 . V_334 ) ;
V_33 -> V_284 = F_83 ( T_1 , V_337 , V_296 ) ;
V_33 -> V_234 = F_85 ( V_33 -> V_284 , V_286 -> V_234 ) ;
for ( V_195 = 0 ; V_195 < V_190 ; V_195 ++ )
V_1 -> V_210 [ V_195 ] = F_86 ( V_195 ,
V_33 -> V_234 ) ;
F_87 ( & V_33 -> V_263 , 1 ) ;
F_88 ( V_11 -> V_103 , F_62 ) ;
for ( V_195 = 1 ; V_195 < V_33 -> V_234 ; V_195 ++ ) {
V_70 = F_89 ( V_33 , V_195 ) ;
if ( V_70 ) {
while ( -- V_195 != 0 )
F_90 ( V_33 -> V_237 [ V_195 ] . V_238 . V_338 ) ;
goto V_335;
}
}
for ( V_195 = 1 ; V_195 < V_33 -> V_234 ; V_195 ++ )
F_91 ( V_287 , & V_33 -> V_237 [ V_195 ] . V_262 ,
V_339 , V_340 ) ;
if ( V_33 -> V_234 > 1 )
F_52 ( & V_33 -> V_265 ) ;
V_335:
if ( V_70 ) {
V_33 -> V_284 = 1 ;
V_33 -> V_234 = 1 ;
}
return V_33 ;
V_297:
F_92 ( V_11 , V_33 ) ;
return F_77 ( V_70 ) ;
}
void F_92 ( struct V_31 * V_11 ,
struct V_115 * V_116 )
{
struct V_1 * V_118 = V_116 -> V_119 ;
F_56 ( V_118 ) ;
V_116 -> V_119 = NULL ;
F_93 ( V_11 ) ;
F_14 ( V_118 ) ;
}
int F_94 ( struct V_115 * V_121 )
{
if ( ! V_121 )
return - V_127 ;
if ( F_8 ( & V_121 -> V_341 ) != 1 )
return 0 ;
return F_59 ( V_121 -> V_119 ) ;
}
int F_95 ( struct V_115 * V_121 )
{
if ( ! V_121 )
return - V_127 ;
if ( F_96 ( & V_121 -> V_341 ) != 0 )
return 0 ;
return F_60 ( V_121 -> V_119 ) ;
}
bool F_97 ( const struct V_115 * V_121 )
{
return F_55 ( & V_121 -> V_341 ) > 0 ;
}
