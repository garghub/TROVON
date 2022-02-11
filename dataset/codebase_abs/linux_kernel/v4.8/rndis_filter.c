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
struct V_13 * V_14 )
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
static int F_27 ( struct V_1 * V_9 ,
struct V_13 * V_23 ,
struct V_61 * V_21 ,
void * * V_101 ,
struct V_102 * V_103 )
{
struct V_94 * V_104 ;
T_1 V_34 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
T_2 V_109 = 0 ;
struct V_66 * V_67 = F_18 ( V_9 -> V_68 ) ;
V_104 = & V_23 -> V_23 . V_21 ;
V_34 = V_110 + V_104 -> V_34 ;
V_21 -> V_69 -= V_34 ;
if ( V_21 -> V_69 < V_104 -> V_35 ) {
F_24 ( V_9 -> V_68 , L_20
L_21
L_22 ,
V_21 -> V_69 , V_104 -> V_35 ) ;
return V_111 ;
}
V_21 -> V_69 = V_104 -> V_35 ;
* V_101 = ( void * ) ( ( unsigned long ) ( * V_101 ) + V_34 ) ;
V_106 = F_26 ( V_104 , V_112 ) ;
if ( V_106 ) {
V_109 = V_113 | V_106 -> V_114 |
( V_106 -> V_115 << V_116 ) ;
}
V_108 = F_26 ( V_104 , V_117 ) ;
return F_28 ( V_67 -> V_76 , V_21 , V_101 ,
V_108 , V_103 , V_109 ) ;
}
int F_29 ( struct V_29 * V_9 ,
struct V_61 * V_21 ,
void * * V_101 ,
struct V_102 * V_103 )
{
struct V_31 * V_68 = F_15 ( V_9 ) ;
struct V_66 * V_67 = F_18 ( V_68 ) ;
struct V_118 * V_119 = V_67 -> V_120 ;
struct V_1 * V_121 ;
struct V_13 * V_14 ;
int V_60 = 0 ;
if ( ! V_119 ) {
V_60 = V_111 ;
goto exit;
}
if ( ! V_119 -> V_122 ) {
F_24 ( V_68 , L_23
L_24 ) ;
V_60 = V_111 ;
goto exit;
}
V_121 = (struct V_1 * ) V_119 -> V_122 ;
if ( V_121 -> V_6 == V_7 ) {
F_24 ( V_68 , L_25
L_26 ) ;
V_60 = V_111 ;
goto exit;
}
V_14 = * V_101 ;
if ( F_30 ( V_67 ) )
F_14 ( V_9 , V_14 ) ;
switch ( V_14 -> V_20 ) {
case V_33 :
V_60 = F_27 ( V_121 , V_14 , V_21 ,
V_101 , V_103 ) ;
break;
case V_41 :
case V_50 :
case V_54 :
F_22 ( V_121 , V_14 ) ;
break;
case V_56 :
F_31 ( V_9 , V_14 ) ;
break;
default:
F_24 ( V_68 ,
L_27 ,
V_14 -> V_20 ,
V_14 -> V_11 ) ;
break;
}
exit:
return V_60 ;
}
static int F_32 ( struct V_1 * V_9 , T_1 V_89 ,
void * V_123 , T_1 * V_124 )
{
struct V_8 * V_12 ;
T_1 V_125 = * V_124 ;
struct V_126 * V_127 ;
struct V_79 * V_51 ;
int V_60 = 0 ;
if ( ! V_123 )
return - V_128 ;
* V_124 = 0 ;
V_12 = F_5 ( V_9 , V_87 ,
F_33 ( struct V_126 ) ) ;
if ( ! V_12 ) {
V_60 = - V_129 ;
goto V_130;
}
V_127 = & V_12 -> V_19 . V_23 . V_88 ;
V_127 -> V_89 = V_89 ;
V_127 -> V_53 = sizeof( struct V_126 ) ;
V_127 -> V_52 = 0 ;
V_127 -> V_131 = 0 ;
if ( V_89 == V_132 ) {
struct V_133 * V_134 ;
V_12 -> V_19 . V_11 +=
sizeof( struct V_133 ) ;
V_127 -> V_52 = sizeof( struct V_133 ) ;
V_134 = (struct V_133 * ) ( ( unsigned long ) V_127 +
V_127 -> V_53 ) ;
V_134 -> V_135 . type = V_136 ;
V_134 -> V_135 . V_137 = V_138 ;
V_134 -> V_135 . V_100 = sizeof( struct V_133 ) ;
}
V_60 = F_17 ( V_9 , V_12 ) ;
if ( V_60 != 0 )
goto V_130;
F_34 ( & V_12 -> V_18 ) ;
V_51 = & V_12 -> V_80 . V_23 . V_51 ;
if ( V_51 -> V_52 > V_125 ) {
V_60 = - 1 ;
goto V_130;
}
memcpy ( V_123 ,
( void * ) ( ( unsigned long ) V_51 +
V_51 -> V_53 ) ,
V_51 -> V_52 ) ;
* V_124 = V_51 -> V_52 ;
V_130:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_60 ;
}
static int F_35 ( struct V_1 * V_9 )
{
T_1 V_100 = V_139 ;
return F_32 ( V_9 ,
V_140 ,
V_9 -> V_141 , & V_100 ) ;
}
int F_36 ( struct V_31 * V_68 , char * V_142 )
{
struct V_118 * V_120 = F_37 ( V_68 ) ;
struct V_1 * V_77 = V_120 -> V_122 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_143 * V_144 ;
T_3 * V_145 , * V_146 ;
struct V_147 * V_55 ;
char V_148 [ 2 * V_139 + 1 ] ;
T_1 V_149 = sizeof( struct V_143 ) +
2 * V_150 + 4 * V_139 ;
int V_60 ;
V_12 = F_5 ( V_77 , V_151 ,
F_33 ( struct V_15 ) + V_149 ) ;
if ( ! V_12 )
return - V_129 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_152 ;
V_16 -> V_52 = V_149 ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
V_16 -> V_131 = 0 ;
V_144 = (struct V_143 * ) ( ( V_98 ) V_16 +
V_16 -> V_53 ) ;
V_144 -> V_153 =
sizeof( struct V_143 ) ;
V_144 -> V_154 = 2 * V_150 ;
V_144 -> V_155 = V_156 ;
V_144 -> V_157 =
V_144 -> V_153 + V_144 -> V_154 ;
V_144 -> V_158 = 4 * V_139 ;
V_145 = ( T_3 * ) ( ( V_98 ) V_144 + V_144 -> V_153 ) ;
V_146 = ( T_3 * ) ( ( V_98 ) V_144 + V_144 -> V_157 ) ;
V_60 = F_38 ( V_159 , V_150 , V_160 ,
V_145 , V_150 ) ;
if ( V_60 < 0 )
goto V_130;
snprintf ( V_148 , 2 * V_139 + 1 , L_28 , V_142 ) ;
V_60 = F_38 ( V_148 , 2 * V_139 , V_160 ,
V_146 , 2 * V_139 ) ;
if ( V_60 < 0 )
goto V_130;
V_60 = F_17 ( V_77 , V_12 ) ;
if ( V_60 != 0 )
goto V_130;
F_34 ( & V_12 -> V_18 ) ;
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
if ( V_55 -> V_43 != V_81 ) {
F_24 ( V_68 , L_29 ,
V_55 -> V_43 ) ;
V_60 = - V_128 ;
}
V_130:
F_11 ( V_77 , V_12 ) ;
return V_60 ;
}
static int
F_39 ( struct V_31 * V_68 ,
struct V_161 * V_162 )
{
struct V_118 * V_120 = F_37 ( V_68 ) ;
struct V_1 * V_77 = V_120 -> V_122 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_161 * V_163 ;
struct V_147 * V_55 ;
T_1 V_149 = sizeof( struct V_161 ) ;
int V_60 ;
T_1 V_164 = V_120 -> V_165 ;
if ( V_164 <= V_166 ) {
V_149 = V_167 ;
V_162 -> V_168 = 0 ;
V_162 -> V_169 = 0 ;
}
V_12 = F_5 ( V_77 , V_151 ,
F_33 ( struct V_15 ) + V_149 ) ;
if ( ! V_12 )
return - V_129 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_170 ;
V_16 -> V_52 = V_149 ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
V_16 -> V_131 = 0 ;
V_163 = (struct V_161 * ) ( ( V_98 ) V_16 +
V_16 -> V_53 ) ;
* V_163 = * V_162 ;
V_163 -> V_171 . type = V_172 ;
V_163 -> V_171 . V_173 = V_174 ;
V_163 -> V_171 . V_100 = V_149 ;
V_60 = F_17 ( V_77 , V_12 ) ;
if ( V_60 != 0 )
goto V_130;
F_34 ( & V_12 -> V_18 ) ;
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
if ( V_55 -> V_43 != V_81 ) {
F_24 ( V_68 , L_30 ,
V_55 -> V_43 ) ;
V_60 = - V_128 ;
}
V_130:
F_11 ( V_77 , V_12 ) ;
return V_60 ;
}
static int F_40 ( struct V_1 * V_77 , int V_175 )
{
struct V_31 * V_68 = V_77 -> V_68 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_147 * V_55 ;
T_1 V_149 = sizeof( struct V_176 ) +
4 * V_177 + V_178 ;
struct V_176 * V_179 ;
T_1 * V_180 ;
T_4 * V_181 ;
int V_182 , V_60 ;
V_12 = F_5 (
V_77 , V_151 ,
F_33 ( struct V_15 ) + V_149 ) ;
if ( ! V_12 )
return - V_129 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_183 ;
V_16 -> V_52 = V_149 ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
V_16 -> V_131 = 0 ;
V_179 = (struct V_176 * ) ( V_16 + 1 ) ;
V_179 -> V_135 . type = V_184 ;
V_179 -> V_135 . V_137 = V_185 ;
V_179 -> V_135 . V_100 = sizeof( struct V_176 ) ;
V_179 -> V_186 = 0 ;
V_179 -> V_187 = V_188 | V_189 |
V_190 | V_191 |
V_192 ;
V_179 -> V_193 = 4 * V_177 ;
V_179 -> V_194 = sizeof( struct V_176 ) ;
V_179 -> V_195 = V_178 ;
V_179 -> V_196 = V_179 -> V_194 +
V_179 -> V_193 ;
V_180 = ( T_1 * ) ( V_179 + 1 ) ;
for ( V_182 = 0 ; V_182 < V_177 ; V_182 ++ )
V_180 [ V_182 ] = V_182 % V_175 ;
V_181 = ( T_4 * ) ( ( unsigned long ) V_179 + V_179 -> V_196 ) ;
for ( V_182 = 0 ; V_182 < V_178 ; V_182 ++ )
V_181 [ V_182 ] = V_197 [ V_182 ] ;
V_60 = F_17 ( V_77 , V_12 ) ;
if ( V_60 != 0 )
goto V_130;
F_34 ( & V_12 -> V_18 ) ;
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
if ( V_55 -> V_43 != V_81 ) {
F_24 ( V_68 , L_31 ,
V_55 -> V_43 ) ;
V_60 = - V_128 ;
}
V_130:
F_11 ( V_77 , V_12 ) ;
return V_60 ;
}
static int F_41 ( struct V_1 * V_9 )
{
T_1 V_100 = sizeof( T_1 ) ;
T_1 V_78 ;
int V_60 ;
V_60 = F_32 ( V_9 ,
V_90 ,
& V_78 , & V_100 ) ;
return V_60 ;
}
int F_42 ( struct V_1 * V_9 , T_1 V_198 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_147 * V_55 ;
T_1 V_43 ;
int V_60 ;
V_12 = F_5 ( V_9 , V_151 ,
F_33 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_60 = - V_129 ;
goto V_130;
}
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_199 ;
V_16 -> V_52 = sizeof( T_1 ) ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_198 , sizeof( T_1 ) ) ;
V_60 = F_17 ( V_9 , V_12 ) ;
if ( V_60 != 0 )
goto V_130;
F_34 ( & V_12 -> V_18 ) ;
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
V_43 = V_55 -> V_43 ;
V_130:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_60 ;
}
static int F_43 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_200 * V_201 ;
struct V_202 * V_42 ;
T_1 V_43 ;
int V_60 ;
struct V_118 * V_120 = F_37 ( V_9 -> V_68 ) ;
V_12 = F_5 ( V_9 , V_203 ,
F_33 ( struct V_200 ) ) ;
if ( ! V_12 ) {
V_60 = - V_129 ;
goto V_130;
}
V_201 = & V_12 -> V_19 . V_23 . V_85 ;
V_201 -> V_44 = V_204 ;
V_201 -> V_45 = V_205 ;
V_201 -> V_47 = 0x4000 ;
V_9 -> V_6 = V_206 ;
V_60 = F_17 ( V_9 , V_12 ) ;
if ( V_60 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_130;
}
F_34 ( & V_12 -> V_18 ) ;
V_42 = & V_12 -> V_80 . V_23 . V_42 ;
V_43 = V_42 -> V_43 ;
if ( V_43 == V_81 ) {
V_9 -> V_6 = V_207 ;
V_120 -> V_208 = V_42 -> V_48 ;
V_120 -> V_209 = 1 << V_42 -> V_49 ;
V_60 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_60 = - V_128 ;
}
V_130:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_60 ;
}
static void F_44 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_210 * V_211 ;
struct V_66 * V_67 = F_18 ( V_9 -> V_68 ) ;
struct V_118 * V_120 = V_67 -> V_120 ;
struct V_29 * V_212 = V_67 -> V_76 ;
V_98 V_17 ;
V_12 = F_5 ( V_9 , V_213 ,
F_33 ( struct V_210 ) ) ;
if ( ! V_12 )
goto V_130;
V_211 = & V_12 -> V_19 . V_23 . V_214 ;
V_211 -> V_25 = F_7 ( & V_9 -> V_26 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_130:
F_8 ( & V_212 -> V_103 -> V_215 , V_17 ) ;
V_120 -> V_216 = true ;
F_10 ( & V_212 -> V_103 -> V_215 , V_17 ) ;
V_18 ( V_120 -> V_217 ,
F_45 ( & V_120 -> V_218 ) == 0 ) ;
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_46 ( struct V_1 * V_9 )
{
int V_60 ;
if ( V_9 -> V_6 != V_207 )
return 0 ;
V_60 = F_42 ( V_9 ,
V_219 |
V_220 |
V_221 ) ;
if ( V_60 == 0 )
V_9 -> V_6 = V_222 ;
return V_60 ;
}
static int F_47 ( struct V_1 * V_9 )
{
int V_60 ;
if ( V_9 -> V_6 != V_222 )
return 0 ;
V_60 = F_42 ( V_9 , 0 ) ;
if ( V_60 == - V_223 )
V_60 = 0 ;
if ( V_60 == 0 )
V_9 -> V_6 = V_207 ;
return V_60 ;
}
static void F_48 ( struct V_102 * V_224 )
{
struct V_31 * V_68 =
F_15 ( V_224 -> V_225 -> V_226 ) ;
struct V_118 * V_227 = F_37 ( V_68 ) ;
T_2 V_228 = V_224 -> V_229 . V_230 . V_231 ;
int V_60 ;
unsigned long V_17 ;
if ( V_228 >= V_227 -> V_232 )
return;
F_49 ( V_224 , V_227 -> V_233 + ( V_228 - 1 ) *
V_234 ) ;
V_60 = F_50 ( V_224 , V_227 -> V_235 * V_75 ,
V_227 -> V_235 * V_75 , NULL , 0 ,
V_236 , V_224 ) ;
if ( V_60 == 0 )
V_227 -> V_237 [ V_228 ] = V_224 ;
F_8 ( & V_227 -> V_238 , V_17 ) ;
V_227 -> V_239 -- ;
F_10 ( & V_227 -> V_238 , V_17 ) ;
if ( V_227 -> V_239 == 0 )
F_25 ( & V_227 -> V_240 ) ;
}
int F_51 ( struct V_29 * V_9 ,
void * V_241 )
{
int V_60 ;
struct V_31 * V_242 = F_15 ( V_9 ) ;
struct V_66 * V_67 = F_18 ( V_242 ) ;
struct V_118 * V_31 ;
struct V_1 * V_1 ;
struct V_243 * V_244 = V_241 ;
struct V_161 V_245 ;
struct V_246 * V_247 ;
struct V_133 V_248 ;
T_1 V_249 = sizeof( struct V_133 ) ;
T_1 V_250 , V_100 ;
T_1 V_251 ;
T_1 V_252 ;
const struct V_253 * V_254 ;
T_1 V_255 ;
unsigned long V_17 ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_223 ;
V_60 = F_52 ( V_9 , V_241 ) ;
if ( V_60 != 0 ) {
F_13 ( V_1 ) ;
return V_60 ;
}
V_31 = V_67 -> V_120 ;
V_31 -> V_256 = 1 ;
V_31 -> V_232 = 1 ;
F_3 ( & V_31 -> V_238 ) ;
V_31 -> V_122 = V_1 ;
V_1 -> V_68 = V_242 ;
V_60 = F_43 ( V_1 ) ;
if ( V_60 != 0 ) {
F_53 ( V_9 ) ;
return V_60 ;
}
V_100 = sizeof( T_1 ) ;
V_60 = F_32 ( V_1 ,
V_257 ,
& V_250 , & V_100 ) ;
if ( V_60 == 0 && V_100 == sizeof( T_1 ) && V_250 < V_242 -> V_250 )
V_242 -> V_250 = V_250 ;
V_60 = F_35 ( V_1 ) ;
if ( V_60 != 0 ) {
F_53 ( V_9 ) ;
return V_60 ;
}
memcpy ( V_244 -> V_258 , V_1 -> V_141 , V_139 ) ;
memset ( & V_245 , 0 , sizeof( struct V_161 ) ) ;
V_245 . V_259 = V_260 ;
V_245 . V_261 = V_260 ;
V_245 . V_168 = V_260 ;
V_245 . V_262 = V_260 ;
V_245 . V_169 = V_260 ;
V_245 . V_263 = V_264 ;
V_60 = F_39 ( V_242 , & V_245 ) ;
if ( V_60 )
goto V_265;
F_41 ( V_1 ) ;
V_244 -> V_82 = V_1 -> V_82 ;
F_54 ( & V_9 -> V_2 , L_32 ,
V_1 -> V_141 ,
V_244 -> V_82 ? L_33 : L_34 ) ;
if ( V_31 -> V_165 < V_266 )
return 0 ;
memset ( & V_248 , 0 , V_249 ) ;
V_60 = F_32 ( V_1 ,
V_132 ,
& V_248 , & V_249 ) ;
if ( V_60 || V_248 . V_267 < 2 )
goto V_268;
V_31 -> V_256 = F_55 ( T_1 , V_269 , V_248 . V_267 ) ;
V_251 = F_56 ( V_244 -> V_270 , V_31 -> V_256 ) ;
V_254 = F_57 ( F_58 ( V_9 -> V_103 -> V_271 ) ) ;
V_255 = F_59 ( V_254 ) ;
if ( V_244 -> V_232 && V_244 -> V_232 < V_31 -> V_256 )
V_31 -> V_232 = V_244 -> V_232 ;
else
V_31 -> V_232 = F_56 ( V_255 , V_251 ) ;
V_251 = V_31 -> V_232 - 1 ;
V_31 -> V_239 = V_251 ;
if ( V_31 -> V_232 == 1 )
goto V_268;
V_31 -> V_233 = F_60 ( ( V_31 -> V_232 - 1 ) *
V_234 ) ;
if ( ! V_31 -> V_233 ) {
V_31 -> V_232 = 1 ;
F_54 ( & V_9 -> V_2 , L_35 ) ;
goto V_268;
}
F_61 ( V_9 -> V_103 , F_48 ) ;
V_247 = & V_31 -> V_272 ;
memset ( V_247 , 0 , sizeof( struct V_246 ) ) ;
V_247 -> V_135 . V_10 = V_273 ;
V_247 -> V_23 . V_274 . V_275 . V_276 = V_277 ;
V_247 -> V_23 . V_274 . V_275 . V_278 =
V_31 -> V_232 - 1 ;
V_60 = F_62 ( V_9 -> V_103 , V_247 ,
sizeof( struct V_246 ) ,
( unsigned long ) V_247 ,
V_279 ,
V_280 ) ;
if ( V_60 )
goto V_268;
F_34 ( & V_31 -> V_240 ) ;
if ( V_247 -> V_23 . V_274 . V_281 . V_43 !=
V_282 ) {
V_60 = - V_223 ;
goto V_268;
}
V_31 -> V_232 = 1 +
V_247 -> V_23 . V_274 . V_281 . V_278 ;
V_60 = F_40 ( V_1 , V_31 -> V_232 ) ;
F_8 ( & V_31 -> V_238 , V_17 ) ;
V_252 = V_251 - ( V_31 -> V_232 - 1 ) ;
V_31 -> V_239 -= V_252 ;
F_10 ( & V_31 -> V_238 , V_17 ) ;
V_268:
if ( V_60 ) {
V_31 -> V_256 = 1 ;
V_31 -> V_232 = 1 ;
V_31 -> V_239 = 0 ;
}
return 0 ;
V_265:
F_53 ( V_9 ) ;
return V_60 ;
}
void F_53 ( struct V_29 * V_9 )
{
struct V_118 * V_119 = F_63 ( V_9 ) ;
struct V_1 * V_121 = V_119 -> V_122 ;
if ( V_119 -> V_239 > 0 )
F_34 ( & V_119 -> V_240 ) ;
F_44 ( V_121 ) ;
F_13 ( V_121 ) ;
V_119 -> V_122 = NULL ;
F_64 ( V_9 ) ;
}
int F_65 ( struct V_118 * V_120 )
{
if ( ! V_120 )
return - V_128 ;
if ( F_7 ( & V_120 -> V_283 ) != 1 )
return 0 ;
return F_46 ( V_120 -> V_122 ) ;
}
int F_66 ( struct V_118 * V_120 )
{
if ( ! V_120 )
return - V_128 ;
if ( F_67 ( & V_120 -> V_283 ) != 0 )
return 0 ;
return F_47 ( V_120 -> V_122 ) ;
}
