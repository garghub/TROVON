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
struct V_31 * V_32 ;
struct V_33 * V_31 ;
V_31 = F_15 ( V_30 ) ;
V_32 = V_31 -> V_34 ;
switch ( V_14 -> V_20 ) {
case V_35 :
F_16 ( V_32 , L_1
L_2
L_3
L_4 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_21 . V_36 ,
V_14 -> V_23 . V_21 . V_37 ,
V_14 -> V_23 . V_21 . V_38 ,
V_14 -> V_23 . V_21 . V_39 ,
V_14 -> V_23 . V_21 . V_40 ,
V_14 -> V_23 . V_21 . V_41 ,
V_14 -> V_23 . V_21 . V_42 ) ;
break;
case V_43 :
F_16 ( V_32 , L_5
L_6
L_7
L_8 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_44 . V_25 ,
V_14 -> V_23 . V_44 . V_45 ,
V_14 -> V_23 . V_44 . V_46 ,
V_14 -> V_23 . V_44 . V_47 ,
V_14 -> V_23 . V_44 . V_48 ,
V_14 -> V_23 . V_44 . V_49 ,
V_14 -> V_23 . V_44 .
V_50 ,
V_14 -> V_23 . V_44 .
V_51 ) ;
break;
case V_52 :
F_16 ( V_32 , L_9
L_10
L_11 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_53 . V_25 ,
V_14 -> V_23 . V_53 . V_45 ,
V_14 -> V_23 . V_53 .
V_54 ,
V_14 -> V_23 . V_53 .
V_55 ) ;
break;
case V_56 :
F_16 ( V_32 ,
L_12 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_57 . V_25 ,
V_14 -> V_23 . V_57 . V_45 ) ;
break;
case V_58 :
F_16 ( V_32 , L_13
L_14 ,
V_14 -> V_11 ,
V_14 -> V_23 . V_59 . V_45 ,
V_14 -> V_23 . V_59 . V_60 ,
V_14 -> V_23 . V_59 . V_61 ) ;
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
int V_62 ;
struct V_63 * V_64 ;
struct V_65 V_66 [ 2 ] ;
struct V_65 * V_67 = V_66 ;
V_64 = & V_28 -> V_21 ;
V_64 -> V_68 = V_28 -> V_19 . V_11 ;
V_64 -> V_69 = 1 ;
V_67 [ 0 ] . V_70 = F_18 ( & V_28 -> V_19 ) >>
V_71 ;
V_67 [ 0 ] . V_72 = V_28 -> V_19 . V_11 ;
V_67 [ 0 ] . V_73 =
( unsigned long ) & V_28 -> V_19 & ( V_74 - 1 ) ;
if ( V_67 [ 0 ] . V_73 + V_67 [ 0 ] . V_72 > V_74 ) {
V_64 -> V_69 ++ ;
V_67 [ 0 ] . V_72 = V_74 -
V_67 [ 0 ] . V_73 ;
V_67 [ 1 ] . V_70 = F_18 ( ( void * ) & V_28 -> V_19
+ V_67 [ 0 ] . V_72 ) >> V_71 ;
V_67 [ 1 ] . V_73 = 0 ;
V_67 [ 1 ] . V_72 = V_28 -> V_19 . V_11 -
V_67 [ 0 ] . V_72 ;
}
V_62 = F_19 ( V_9 -> V_75 -> V_9 , V_64 , NULL , & V_67 , NULL ) ;
return V_62 ;
}
static void F_20 ( struct V_1 * V_76 ,
struct V_8 * V_12 )
{
T_1 V_77 ;
struct V_78 * V_53 ;
V_53 = & V_12 -> V_79 . V_23 . V_53 ;
if ( V_53 -> V_45 == V_80 &&
V_53 -> V_54 == sizeof( T_1 ) ) {
memcpy ( & V_77 , ( void * ) ( ( unsigned long ) V_53 +
V_53 -> V_55 ) , sizeof( T_1 ) ) ;
V_76 -> V_81 = V_77 != 0 ;
}
}
static void F_21 ( struct V_1 * V_9 ,
struct V_13 * V_82 )
{
struct V_8 * V_12 = NULL ;
bool V_83 = false ;
unsigned long V_17 ;
struct V_31 * V_34 ;
V_34 = V_9 -> V_75 -> V_34 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_22 (request, &dev->req_list, list_ent) {
if ( V_12 -> V_19 . V_23 . V_84 . V_25
== V_82 -> V_23 . V_44 . V_25 ) {
V_83 = true ;
break;
}
}
F_10 ( & V_9 -> V_4 , V_17 ) ;
if ( V_83 ) {
if ( V_82 -> V_11 <=
sizeof( struct V_13 ) + V_85 ) {
memcpy ( & V_12 -> V_79 , V_82 ,
V_82 -> V_11 ) ;
if ( V_12 -> V_19 . V_20 ==
V_86 && V_12 -> V_19 . V_23 .
V_87 . V_88 == V_89 )
F_20 ( V_9 , V_12 ) ;
} else {
F_23 ( V_34 ,
L_16
L_17 ,
V_82 -> V_11 ,
sizeof( struct V_13 ) ) ;
if ( V_82 -> V_20 ==
V_90 ) {
V_12 -> V_79 . V_23 . V_91 .
V_45 = V_92 ;
} else {
V_12 -> V_79 . V_23 .
V_44 . V_45 =
V_92 ;
}
}
F_24 ( & V_12 -> V_18 ) ;
} else {
F_23 ( V_34 ,
L_18
L_19 ,
V_82 -> V_23 . V_44 . V_25 ,
V_82 -> V_20 ) ;
}
}
static inline void * F_25 ( struct V_93 * V_94 , T_1 type )
{
struct V_95 * V_96 ;
int V_72 ;
if ( V_94 -> V_41 == 0 )
return NULL ;
V_96 = (struct V_95 * ) ( ( V_97 ) V_94 +
V_94 -> V_41 ) ;
V_72 = V_94 -> V_42 ;
while ( V_72 > 0 ) {
if ( V_96 -> type == type )
return ( void * ) ( ( V_97 ) V_96 + V_96 -> V_98 ) ;
V_72 -= V_96 -> V_99 ;
V_96 = (struct V_95 * ) ( ( V_97 ) V_96 + V_96 -> V_99 ) ;
}
return NULL ;
}
static int F_26 ( struct V_1 * V_9 ,
struct V_13 * V_23 ,
struct V_63 * V_21 ,
void * * V_100 ,
struct V_101 * V_102 )
{
struct V_93 * V_103 ;
T_1 V_36 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
T_2 V_108 = 0 ;
V_103 = & V_23 -> V_23 . V_21 ;
V_36 = V_109 + V_103 -> V_36 ;
V_21 -> V_68 -= V_36 ;
if ( V_21 -> V_68 < V_103 -> V_37 ) {
F_23 ( V_9 -> V_75 -> V_34 , L_20
L_21
L_22 ,
V_21 -> V_68 , V_103 -> V_37 ) ;
return V_110 ;
}
V_21 -> V_68 = V_103 -> V_37 ;
* V_100 = ( void * ) ( ( unsigned long ) ( * V_100 ) + V_36 ) ;
V_105 = F_25 ( V_103 , V_111 ) ;
if ( V_105 ) {
V_108 = V_112 | V_105 -> V_113 |
( V_105 -> V_114 << V_115 ) ;
}
V_107 = F_25 ( V_103 , V_116 ) ;
return F_27 ( V_9 -> V_75 -> V_9 , V_21 , V_100 ,
V_107 , V_102 , V_108 ) ;
}
int F_28 ( struct V_29 * V_9 ,
struct V_63 * V_21 ,
void * * V_100 ,
struct V_101 * V_102 )
{
struct V_33 * V_75 = F_15 ( V_9 ) ;
struct V_1 * V_117 ;
struct V_13 * V_14 ;
struct V_31 * V_34 ;
int V_62 = 0 ;
if ( ! V_75 ) {
V_62 = V_110 ;
goto exit;
}
V_34 = V_75 -> V_34 ;
if ( ! V_75 -> V_118 ) {
F_23 ( V_34 , L_23
L_24 ) ;
V_62 = V_110 ;
goto exit;
}
V_117 = (struct V_1 * ) V_75 -> V_118 ;
if ( V_117 -> V_6 == V_7 ) {
F_23 ( V_34 , L_25
L_26 ) ;
V_62 = V_110 ;
goto exit;
}
V_14 = * V_100 ;
if ( F_29 ( V_75 -> V_119 ) )
F_14 ( V_9 , V_14 ) ;
switch ( V_14 -> V_20 ) {
case V_35 :
V_62 = F_26 ( V_117 , V_14 , V_21 ,
V_100 , V_102 ) ;
break;
case V_43 :
case V_52 :
case V_56 :
F_21 ( V_117 , V_14 ) ;
break;
case V_58 :
F_30 ( V_9 , V_14 ) ;
break;
default:
F_23 ( V_34 ,
L_27 ,
V_14 -> V_20 ,
V_14 -> V_11 ) ;
break;
}
exit:
return V_62 ;
}
static int F_31 ( struct V_1 * V_9 , T_1 V_88 ,
void * V_120 , T_1 * V_121 )
{
struct V_8 * V_12 ;
T_1 V_122 = * V_121 ;
struct V_123 * V_124 ;
struct V_78 * V_53 ;
int V_62 = 0 ;
unsigned long V_125 ;
if ( ! V_120 )
return - V_126 ;
* V_121 = 0 ;
V_12 = F_5 ( V_9 , V_86 ,
F_32 ( struct V_123 ) ) ;
if ( ! V_12 ) {
V_62 = - V_127 ;
goto V_128;
}
V_124 = & V_12 -> V_19 . V_23 . V_87 ;
V_124 -> V_88 = V_88 ;
V_124 -> V_55 = sizeof( struct V_123 ) ;
V_124 -> V_54 = 0 ;
V_124 -> V_129 = 0 ;
if ( V_88 == V_130 ) {
struct V_131 * V_132 ;
V_12 -> V_19 . V_11 +=
sizeof( struct V_131 ) ;
V_124 -> V_54 = sizeof( struct V_131 ) ;
V_132 = (struct V_131 * ) ( ( unsigned long ) V_124 +
V_124 -> V_55 ) ;
V_132 -> V_133 . type = V_134 ;
V_132 -> V_133 . V_135 = V_136 ;
V_132 -> V_133 . V_99 = sizeof( struct V_131 ) ;
}
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 )
goto V_128;
V_125 = F_33 ( & V_12 -> V_18 , 5 * V_137 ) ;
if ( V_125 == 0 ) {
V_62 = - V_138 ;
goto V_128;
}
V_53 = & V_12 -> V_79 . V_23 . V_53 ;
if ( V_53 -> V_54 > V_122 ) {
V_62 = - 1 ;
goto V_128;
}
memcpy ( V_120 ,
( void * ) ( ( unsigned long ) V_53 +
V_53 -> V_55 ) ,
V_53 -> V_54 ) ;
* V_121 = V_53 -> V_54 ;
V_128:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_62 ;
}
static int F_34 ( struct V_1 * V_9 )
{
T_1 V_99 = V_139 ;
return F_31 ( V_9 ,
V_140 ,
V_9 -> V_141 , & V_99 ) ;
}
int F_35 ( struct V_29 * V_142 , char * V_143 )
{
struct V_33 * V_144 = F_15 ( V_142 ) ;
struct V_1 * V_76 = V_144 -> V_118 ;
struct V_31 * V_34 = V_144 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_145 * V_146 ;
T_3 * V_147 , * V_148 ;
struct V_149 * V_57 ;
char V_150 [ 2 * V_139 + 1 ] ;
T_1 V_151 = sizeof( struct V_145 ) +
2 * V_152 + 4 * V_139 ;
int V_62 ;
unsigned long V_125 ;
V_12 = F_5 ( V_76 , V_153 ,
F_32 ( struct V_15 ) + V_151 ) ;
if ( ! V_12 )
return - V_127 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_154 ;
V_16 -> V_54 = V_151 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_129 = 0 ;
V_146 = (struct V_145 * ) ( ( V_97 ) V_16 +
V_16 -> V_55 ) ;
V_146 -> V_155 =
sizeof( struct V_145 ) ;
V_146 -> V_156 = 2 * V_152 ;
V_146 -> V_157 = V_158 ;
V_146 -> V_159 =
V_146 -> V_155 + V_146 -> V_156 ;
V_146 -> V_160 = 4 * V_139 ;
V_147 = ( T_3 * ) ( ( V_97 ) V_146 + V_146 -> V_155 ) ;
V_148 = ( T_3 * ) ( ( V_97 ) V_146 + V_146 -> V_159 ) ;
V_62 = F_36 ( V_161 , V_152 , V_162 ,
V_147 , V_152 ) ;
if ( V_62 < 0 )
goto V_128;
snprintf ( V_150 , 2 * V_139 + 1 , L_28 , V_143 ) ;
V_62 = F_36 ( V_150 , 2 * V_139 , V_162 ,
V_148 , 2 * V_139 ) ;
if ( V_62 < 0 )
goto V_128;
V_62 = F_17 ( V_76 , V_12 ) ;
if ( V_62 != 0 )
goto V_128;
V_125 = F_33 ( & V_12 -> V_18 , 5 * V_137 ) ;
if ( V_125 == 0 ) {
F_23 ( V_34 , L_29 ) ;
return - V_163 ;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_80 ) {
F_23 ( V_34 , L_30 ,
V_57 -> V_45 ) ;
V_62 = - V_126 ;
}
}
V_128:
F_11 ( V_76 , V_12 ) ;
return V_62 ;
}
static int
F_37 ( struct V_29 * V_142 ,
struct V_164 * V_165 )
{
struct V_33 * V_144 = F_15 ( V_142 ) ;
struct V_1 * V_76 = V_144 -> V_118 ;
struct V_31 * V_34 = V_144 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_164 * V_166 ;
struct V_149 * V_57 ;
T_1 V_151 = sizeof( struct V_164 ) ;
int V_62 ;
unsigned long V_125 ;
T_1 V_167 = V_144 -> V_168 ;
if ( V_167 <= V_169 ) {
V_151 = V_170 ;
V_165 -> V_171 = 0 ;
V_165 -> V_172 = 0 ;
}
V_12 = F_5 ( V_76 , V_153 ,
F_32 ( struct V_15 ) + V_151 ) ;
if ( ! V_12 )
return - V_127 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_173 ;
V_16 -> V_54 = V_151 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_129 = 0 ;
V_166 = (struct V_164 * ) ( ( V_97 ) V_16 +
V_16 -> V_55 ) ;
* V_166 = * V_165 ;
V_166 -> V_174 . type = V_175 ;
V_166 -> V_174 . V_176 = V_177 ;
V_166 -> V_174 . V_99 = V_151 ;
V_62 = F_17 ( V_76 , V_12 ) ;
if ( V_62 != 0 )
goto V_128;
V_125 = F_33 ( & V_12 -> V_18 , 5 * V_137 ) ;
if ( V_125 == 0 ) {
F_23 ( V_34 , L_31 ) ;
return - V_163 ;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_80 ) {
F_23 ( V_34 , L_32 ,
V_57 -> V_45 ) ;
V_62 = - V_126 ;
}
}
V_128:
F_11 ( V_76 , V_12 ) ;
return V_62 ;
}
static int F_38 ( struct V_1 * V_76 , int V_178 )
{
struct V_31 * V_34 = V_76 -> V_75 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_149 * V_57 ;
T_1 V_151 = sizeof( struct V_179 ) +
4 * V_180 + V_181 ;
struct V_179 * V_182 ;
T_1 * V_183 ;
T_4 * V_184 ;
int V_185 , V_62 ;
unsigned long V_125 ;
V_12 = F_5 (
V_76 , V_153 ,
F_32 ( struct V_15 ) + V_151 ) ;
if ( ! V_12 )
return - V_127 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_186 ;
V_16 -> V_54 = V_151 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_129 = 0 ;
V_182 = (struct V_179 * ) ( V_16 + 1 ) ;
V_182 -> V_133 . type = V_187 ;
V_182 -> V_133 . V_135 = V_188 ;
V_182 -> V_133 . V_99 = sizeof( struct V_179 ) ;
V_182 -> V_189 = 0 ;
V_182 -> V_190 = V_191 | V_192 |
V_193 | V_194 |
V_195 ;
V_182 -> V_196 = 4 * V_180 ;
V_182 -> V_197 = sizeof( struct V_179 ) ;
V_182 -> V_198 = V_181 ;
V_182 -> V_199 = V_182 -> V_197 +
V_182 -> V_196 ;
V_183 = ( T_1 * ) ( V_182 + 1 ) ;
for ( V_185 = 0 ; V_185 < V_180 ; V_185 ++ )
V_183 [ V_185 ] = V_185 % V_178 ;
V_184 = ( T_4 * ) ( ( unsigned long ) V_182 + V_182 -> V_199 ) ;
for ( V_185 = 0 ; V_185 < V_181 ; V_185 ++ )
V_184 [ V_185 ] = V_200 [ V_185 ] ;
V_62 = F_17 ( V_76 , V_12 ) ;
if ( V_62 != 0 )
goto V_128;
V_125 = F_33 ( & V_12 -> V_18 , 5 * V_137 ) ;
if ( V_125 == 0 ) {
F_23 ( V_34 , L_29 ) ;
return - V_138 ;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_80 ) {
F_23 ( V_34 , L_33 ,
V_57 -> V_45 ) ;
V_62 = - V_126 ;
}
}
V_128:
F_11 ( V_76 , V_12 ) ;
return V_62 ;
}
static int F_39 ( struct V_1 * V_9 )
{
T_1 V_99 = sizeof( T_1 ) ;
T_1 V_77 ;
int V_62 ;
V_62 = F_31 ( V_9 ,
V_89 ,
& V_77 , & V_99 ) ;
return V_62 ;
}
int F_40 ( struct V_1 * V_9 , T_1 V_201 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_149 * V_57 ;
T_1 V_45 ;
int V_62 ;
unsigned long V_125 ;
struct V_31 * V_34 ;
V_34 = V_9 -> V_75 -> V_34 ;
V_12 = F_5 ( V_9 , V_153 ,
F_32 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_62 = - V_127 ;
goto V_128;
}
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_202 ;
V_16 -> V_54 = sizeof( T_1 ) ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_201 , sizeof( T_1 ) ) ;
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 )
goto V_128;
V_125 = F_33 ( & V_12 -> V_18 , 5 * V_137 ) ;
if ( V_125 == 0 ) {
F_23 ( V_34 ,
L_29 ) ;
V_62 = - V_138 ;
goto exit;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
V_45 = V_57 -> V_45 ;
}
V_128:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
exit:
return V_62 ;
}
static int F_41 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_203 * V_204 ;
struct V_205 * V_44 ;
T_1 V_45 ;
int V_62 ;
unsigned long V_125 ;
struct V_33 * V_144 = V_9 -> V_75 ;
V_12 = F_5 ( V_9 , V_206 ,
F_32 ( struct V_203 ) ) ;
if ( ! V_12 ) {
V_62 = - V_127 ;
goto V_128;
}
V_204 = & V_12 -> V_19 . V_23 . V_84 ;
V_204 -> V_46 = V_207 ;
V_204 -> V_47 = V_208 ;
V_204 -> V_49 = 0x4000 ;
V_9 -> V_6 = V_209 ;
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_128;
}
V_125 = F_33 ( & V_12 -> V_18 , 5 * V_137 ) ;
if ( V_125 == 0 ) {
V_62 = - V_138 ;
goto V_128;
}
V_44 = & V_12 -> V_79 . V_23 . V_44 ;
V_45 = V_44 -> V_45 ;
if ( V_45 == V_80 ) {
V_9 -> V_6 = V_210 ;
V_144 -> V_211 = V_44 -> V_50 ;
V_144 -> V_212 = 1 << V_44 -> V_51 ;
V_62 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_62 = - V_126 ;
}
V_128:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_62 ;
}
static void F_42 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_213 * V_214 ;
struct V_33 * V_144 = V_9 -> V_75 ;
struct V_29 * V_142 = V_144 -> V_9 ;
V_97 V_17 ;
V_12 = F_5 ( V_9 , V_215 ,
F_32 ( struct V_213 ) ) ;
if ( ! V_12 )
goto V_128;
V_214 = & V_12 -> V_19 . V_23 . V_216 ;
V_214 -> V_25 = F_7 ( & V_9 -> V_26 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_128:
F_8 ( & V_142 -> V_102 -> V_217 , V_17 ) ;
V_144 -> V_218 = true ;
F_10 ( & V_142 -> V_102 -> V_217 , V_17 ) ;
V_18 ( V_144 -> V_219 ,
F_43 ( & V_144 -> V_220 ) == 0 ) ;
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_44 ( struct V_1 * V_9 )
{
int V_62 ;
if ( V_9 -> V_6 != V_210 )
return 0 ;
V_62 = F_40 ( V_9 ,
V_221 |
V_222 |
V_223 ) ;
if ( V_62 == 0 )
V_9 -> V_6 = V_224 ;
return V_62 ;
}
static int F_45 ( struct V_1 * V_9 )
{
int V_62 ;
if ( V_9 -> V_6 != V_224 )
return 0 ;
V_62 = F_40 ( V_9 , 0 ) ;
if ( V_62 == - V_225 )
V_62 = 0 ;
if ( V_62 == 0 )
V_9 -> V_6 = V_210 ;
return V_62 ;
}
static void F_46 ( struct V_101 * V_226 )
{
struct V_33 * V_227 ;
T_2 V_228 = V_226 -> V_229 . V_230 . V_231 ;
int V_62 ;
unsigned long V_17 ;
V_227 = F_15 ( V_226 -> V_232 -> V_233 ) ;
F_8 ( & V_227 -> V_234 , V_17 ) ;
V_227 -> V_235 -- ;
F_10 ( & V_227 -> V_234 , V_17 ) ;
if ( V_227 -> V_235 == 0 )
F_24 ( & V_227 -> V_236 ) ;
if ( V_228 >= V_227 -> V_237 )
return;
F_47 ( V_226 , V_227 -> V_238 + ( V_228 - 1 ) *
V_239 ) ;
V_62 = F_48 ( V_226 , V_227 -> V_240 * V_74 ,
V_227 -> V_240 * V_74 , NULL , 0 ,
V_241 , V_226 ) ;
if ( V_62 == 0 )
V_227 -> V_242 [ V_228 ] = V_226 ;
}
int F_49 ( struct V_29 * V_9 ,
void * V_243 )
{
int V_62 ;
struct V_33 * V_31 ;
struct V_1 * V_1 ;
struct V_244 * V_245 = V_243 ;
struct V_164 V_246 ;
struct V_247 * V_248 ;
unsigned long V_125 ;
struct V_131 V_249 ;
T_1 V_250 = sizeof( struct V_131 ) ;
T_1 V_251 , V_99 ;
T_1 V_252 ;
T_1 V_253 ;
const struct V_254 * V_255 ;
T_1 V_256 ;
unsigned long V_17 ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_225 ;
V_62 = F_50 ( V_9 , V_243 ) ;
if ( V_62 != 0 ) {
F_13 ( V_1 ) ;
return V_62 ;
}
V_31 = F_15 ( V_9 ) ;
V_31 -> V_257 = 1 ;
V_31 -> V_237 = 1 ;
F_3 ( & V_31 -> V_234 ) ;
V_31 -> V_118 = V_1 ;
V_1 -> V_75 = V_31 ;
V_62 = F_41 ( V_1 ) ;
if ( V_62 != 0 ) {
F_51 ( V_9 ) ;
return V_62 ;
}
V_99 = sizeof( T_1 ) ;
V_62 = F_31 ( V_1 ,
V_258 ,
& V_251 , & V_99 ) ;
if ( V_62 == 0 && V_99 == sizeof( T_1 ) && V_251 < V_31 -> V_34 -> V_251 )
V_31 -> V_34 -> V_251 = V_251 ;
V_62 = F_34 ( V_1 ) ;
if ( V_62 != 0 ) {
F_51 ( V_9 ) ;
return V_62 ;
}
memcpy ( V_245 -> V_259 , V_1 -> V_141 , V_139 ) ;
memset ( & V_246 , 0 , sizeof( struct V_164 ) ) ;
V_246 . V_260 = V_261 ;
V_246 . V_262 = V_261 ;
V_246 . V_171 = V_261 ;
V_246 . V_263 = V_261 ;
V_246 . V_172 = V_261 ;
V_246 . V_264 = V_265 ;
V_62 = F_37 ( V_9 , & V_246 ) ;
if ( V_62 )
goto V_266;
F_39 ( V_1 ) ;
V_245 -> V_81 = V_1 -> V_81 ;
F_52 ( & V_9 -> V_2 , L_34 ,
V_1 -> V_141 ,
V_245 -> V_81 ? L_35 : L_36 ) ;
if ( V_31 -> V_168 < V_267 )
return 0 ;
memset ( & V_249 , 0 , V_250 ) ;
V_62 = F_31 ( V_1 ,
V_130 ,
& V_249 , & V_250 ) ;
if ( V_62 || V_249 . V_268 < 2 )
goto V_269;
V_252 = F_53 ( V_245 -> V_270 , V_249 . V_268 ) ;
V_31 -> V_257 = V_249 . V_268 ;
V_255 = F_54 ( F_55 ( V_9 -> V_102 -> V_271 ) ) ;
V_256 = F_56 ( V_255 ) ;
if ( V_245 -> V_237 && V_245 -> V_237 < V_31 -> V_257 )
V_31 -> V_237 = V_245 -> V_237 ;
else
V_31 -> V_237 = F_53 ( V_256 , V_252 ) ;
V_252 = V_31 -> V_237 - 1 ;
V_31 -> V_235 = V_252 ;
if ( V_31 -> V_237 == 1 )
goto V_269;
V_31 -> V_238 = F_57 ( ( V_31 -> V_237 - 1 ) *
V_239 ) ;
if ( ! V_31 -> V_238 ) {
V_31 -> V_237 = 1 ;
F_52 ( & V_9 -> V_2 , L_37 ) ;
goto V_269;
}
F_58 ( V_9 -> V_102 , F_46 ) ;
V_248 = & V_31 -> V_272 ;
memset ( V_248 , 0 , sizeof( struct V_247 ) ) ;
V_248 -> V_133 . V_10 = V_273 ;
V_248 -> V_23 . V_274 . V_275 . V_276 = V_277 ;
V_248 -> V_23 . V_274 . V_275 . V_278 =
V_31 -> V_237 - 1 ;
V_62 = F_59 ( V_9 -> V_102 , V_248 ,
sizeof( struct V_247 ) ,
( unsigned long ) V_248 ,
V_279 ,
V_280 ) ;
if ( V_62 )
goto V_269;
V_125 = F_33 ( & V_31 -> V_236 , 5 * V_137 ) ;
if ( V_125 == 0 ) {
V_62 = - V_138 ;
goto V_269;
}
if ( V_248 -> V_23 . V_274 . V_281 . V_45 !=
V_282 ) {
V_62 = - V_225 ;
goto V_269;
}
V_31 -> V_237 = 1 +
V_248 -> V_23 . V_274 . V_281 . V_278 ;
V_62 = F_38 ( V_1 , V_31 -> V_237 ) ;
F_8 ( & V_31 -> V_234 , V_17 ) ;
V_253 = V_252 - ( V_31 -> V_237 - 1 ) ;
V_31 -> V_235 -= V_253 ;
F_10 ( & V_31 -> V_234 , V_17 ) ;
while ( V_31 -> V_235 != 0 ) {
V_125 = F_33 ( & V_31 -> V_236 , 10 * V_137 ) ;
if ( V_125 == 0 )
F_60 ( 1 , L_38 ) ;
}
V_269:
if ( V_62 ) {
V_31 -> V_257 = 1 ;
V_31 -> V_237 = 1 ;
}
return 0 ;
V_266:
F_51 ( V_9 ) ;
return V_62 ;
}
void F_51 ( struct V_29 * V_9 )
{
struct V_33 * V_75 = F_15 ( V_9 ) ;
struct V_1 * V_117 = V_75 -> V_118 ;
F_42 ( V_117 ) ;
F_13 ( V_117 ) ;
V_75 -> V_118 = NULL ;
F_61 ( V_9 ) ;
}
int F_62 ( struct V_29 * V_9 )
{
struct V_33 * V_31 = F_15 ( V_9 ) ;
if ( ! V_31 )
return - V_126 ;
return F_44 ( V_31 -> V_118 ) ;
}
int F_63 ( struct V_29 * V_9 )
{
struct V_33 * V_144 = F_15 ( V_9 ) ;
if ( ! V_144 )
return - V_126 ;
return F_45 ( V_144 -> V_118 ) ;
}
