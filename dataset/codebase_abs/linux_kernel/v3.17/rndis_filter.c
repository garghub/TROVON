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
V_64 = & V_28 -> V_21 ;
V_64 -> V_65 = false ;
V_64 -> V_66 = V_28 -> V_19 . V_11 ;
V_64 -> V_67 = 1 ;
V_64 -> V_68 [ 0 ] . V_69 = F_18 ( & V_28 -> V_19 ) >>
V_70 ;
V_64 -> V_68 [ 0 ] . V_71 = V_28 -> V_19 . V_11 ;
V_64 -> V_68 [ 0 ] . V_72 =
( unsigned long ) & V_28 -> V_19 & ( V_73 - 1 ) ;
if ( V_64 -> V_68 [ 0 ] . V_72 + V_64 -> V_68 [ 0 ] . V_71 > V_73 ) {
V_64 -> V_67 ++ ;
V_64 -> V_68 [ 0 ] . V_71 = V_73 -
V_64 -> V_68 [ 0 ] . V_72 ;
V_64 -> V_68 [ 1 ] . V_69 = F_18 ( ( void * ) & V_28 -> V_19
+ V_64 -> V_68 [ 0 ] . V_71 ) >> V_70 ;
V_64 -> V_68 [ 1 ] . V_72 = 0 ;
V_64 -> V_68 [ 1 ] . V_71 = V_28 -> V_19 . V_11 -
V_64 -> V_68 [ 0 ] . V_71 ;
}
V_64 -> V_74 = NULL ;
V_62 = F_19 ( V_9 -> V_75 -> V_9 , V_64 ) ;
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
int V_71 ;
if ( V_94 -> V_41 == 0 )
return NULL ;
V_96 = (struct V_95 * ) ( ( V_97 ) V_94 +
V_94 -> V_41 ) ;
V_71 = V_94 -> V_42 ;
while ( V_71 > 0 ) {
if ( V_96 -> type == type )
return ( void * ) ( ( V_97 ) V_96 + V_96 -> V_98 ) ;
V_71 -= V_96 -> V_99 ;
V_96 = (struct V_95 * ) ( ( V_97 ) V_96 + V_96 -> V_99 ) ;
}
return NULL ;
}
static void F_26 ( struct V_1 * V_9 ,
struct V_13 * V_23 ,
struct V_63 * V_21 )
{
struct V_93 * V_100 ;
T_1 V_36 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
V_100 = & V_23 -> V_23 . V_21 ;
V_36 = V_105 + V_100 -> V_36 ;
V_21 -> V_66 -= V_36 ;
if ( V_21 -> V_66 < V_100 -> V_37 ) {
F_23 ( V_9 -> V_75 -> V_34 , L_20
L_21
L_22 ,
V_21 -> V_66 , V_100 -> V_37 ) ;
return;
}
V_21 -> V_66 = V_100 -> V_37 ;
V_21 -> V_106 = ( void * ) ( ( unsigned long ) V_21 -> V_106 + V_36 ) ;
V_102 = F_25 ( V_100 , V_107 ) ;
if ( V_102 ) {
V_21 -> V_108 = V_109 | V_102 -> V_110 |
( V_102 -> V_111 << V_112 ) ;
} else {
V_21 -> V_108 = 0 ;
}
V_104 = F_25 ( V_100 , V_113 ) ;
F_27 ( V_9 -> V_75 -> V_9 , V_21 , V_104 ) ;
}
int F_28 ( struct V_29 * V_9 ,
struct V_63 * V_21 )
{
struct V_33 * V_75 = F_15 ( V_9 ) ;
struct V_1 * V_114 ;
struct V_13 * V_14 ;
struct V_31 * V_34 ;
int V_62 = 0 ;
if ( ! V_75 ) {
V_62 = - V_115 ;
goto exit;
}
V_34 = V_75 -> V_34 ;
if ( ! V_75 -> V_116 ) {
F_23 ( V_34 , L_23
L_24 ) ;
V_62 = - V_117 ;
goto exit;
}
V_114 = (struct V_1 * ) V_75 -> V_116 ;
if ( V_114 -> V_6 == V_7 ) {
F_23 ( V_34 , L_25
L_26 ) ;
V_62 = - V_117 ;
goto exit;
}
V_14 = V_21 -> V_106 ;
F_14 ( V_9 , V_14 ) ;
switch ( V_14 -> V_20 ) {
case V_35 :
F_26 ( V_114 , V_14 , V_21 ) ;
break;
case V_43 :
case V_52 :
case V_56 :
F_21 ( V_114 , V_14 ) ;
break;
case V_58 :
F_29 ( V_9 , V_14 ) ;
break;
default:
F_23 ( V_34 ,
L_27 ,
V_14 -> V_20 ,
V_14 -> V_11 ) ;
break;
}
exit:
if ( V_62 != 0 )
V_21 -> V_45 = V_118 ;
return V_62 ;
}
static int F_30 ( struct V_1 * V_9 , T_1 V_88 ,
void * V_119 , T_1 * V_120 )
{
struct V_8 * V_12 ;
T_1 V_121 = * V_120 ;
struct V_122 * V_123 ;
struct V_78 * V_53 ;
int V_62 = 0 ;
int V_124 ;
if ( ! V_119 )
return - V_115 ;
* V_120 = 0 ;
V_12 = F_5 ( V_9 , V_86 ,
F_31 ( struct V_122 ) ) ;
if ( ! V_12 ) {
V_62 = - V_125 ;
goto V_126;
}
V_123 = & V_12 -> V_19 . V_23 . V_87 ;
V_123 -> V_88 = V_88 ;
V_123 -> V_55 = sizeof( struct V_122 ) ;
V_123 -> V_54 = 0 ;
V_123 -> V_127 = 0 ;
if ( V_88 == V_128 ) {
struct V_129 * V_130 ;
V_12 -> V_19 . V_11 +=
sizeof( struct V_129 ) ;
V_123 -> V_54 = sizeof( struct V_129 ) ;
V_130 = (struct V_129 * ) ( ( unsigned long ) V_123 +
V_123 -> V_55 ) ;
V_130 -> V_131 . type = V_132 ;
V_130 -> V_131 . V_133 = V_134 ;
V_130 -> V_131 . V_99 = sizeof( struct V_129 ) ;
}
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 )
goto V_126;
V_124 = F_32 ( & V_12 -> V_18 , 5 * V_135 ) ;
if ( V_124 == 0 ) {
V_62 = - V_136 ;
goto V_126;
}
V_53 = & V_12 -> V_79 . V_23 . V_53 ;
if ( V_53 -> V_54 > V_121 ) {
V_62 = - 1 ;
goto V_126;
}
memcpy ( V_119 ,
( void * ) ( ( unsigned long ) V_53 +
V_53 -> V_55 ) ,
V_53 -> V_54 ) ;
* V_120 = V_53 -> V_54 ;
V_126:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_62 ;
}
static int F_33 ( struct V_1 * V_9 )
{
T_1 V_99 = V_137 ;
return F_30 ( V_9 ,
V_138 ,
V_9 -> V_139 , & V_99 ) ;
}
int F_34 ( struct V_29 * V_140 , char * V_141 )
{
struct V_33 * V_142 = F_15 ( V_140 ) ;
struct V_1 * V_76 = V_142 -> V_116 ;
struct V_31 * V_34 = V_142 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_143 * V_144 ;
T_2 * V_145 , * V_146 ;
struct V_147 * V_57 ;
char V_148 [ 2 * V_137 + 1 ] ;
T_1 V_149 = sizeof( struct V_143 ) +
2 * V_150 + 4 * V_137 ;
int V_62 , V_124 ;
V_12 = F_5 ( V_76 , V_151 ,
F_31 ( struct V_15 ) + V_149 ) ;
if ( ! V_12 )
return - V_125 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_152 ;
V_16 -> V_54 = V_149 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_127 = 0 ;
V_144 = (struct V_143 * ) ( ( V_97 ) V_16 +
V_16 -> V_55 ) ;
V_144 -> V_153 =
sizeof( struct V_143 ) ;
V_144 -> V_154 = 2 * V_150 ;
V_144 -> V_155 = V_156 ;
V_144 -> V_157 =
V_144 -> V_153 + V_144 -> V_154 ;
V_144 -> V_158 = 4 * V_137 ;
V_145 = ( T_2 * ) ( ( V_97 ) V_144 + V_144 -> V_153 ) ;
V_146 = ( T_2 * ) ( ( V_97 ) V_144 + V_144 -> V_157 ) ;
V_62 = F_35 ( V_159 , V_150 , V_160 ,
V_145 , V_150 ) ;
if ( V_62 < 0 )
goto V_126;
snprintf ( V_148 , 2 * V_137 + 1 , L_28 , V_141 ) ;
V_62 = F_35 ( V_148 , 2 * V_137 , V_160 ,
V_146 , 2 * V_137 ) ;
if ( V_62 < 0 )
goto V_126;
V_62 = F_17 ( V_76 , V_12 ) ;
if ( V_62 != 0 )
goto V_126;
V_124 = F_32 ( & V_12 -> V_18 , 5 * V_135 ) ;
if ( V_124 == 0 ) {
F_23 ( V_34 , L_29 ) ;
return - V_161 ;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_80 ) {
F_23 ( V_34 , L_30 ,
V_57 -> V_45 ) ;
V_62 = - V_115 ;
}
}
V_126:
F_11 ( V_76 , V_12 ) ;
return V_62 ;
}
int F_36 ( struct V_29 * V_140 ,
struct V_162 * V_163 )
{
struct V_33 * V_142 = F_15 ( V_140 ) ;
struct V_1 * V_76 = V_142 -> V_116 ;
struct V_31 * V_34 = V_142 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_162 * V_164 ;
struct V_147 * V_57 ;
T_1 V_149 = sizeof( struct V_162 ) ;
int V_62 , V_124 ;
T_1 V_165 = V_142 -> V_166 ;
if ( V_165 <= V_167 ) {
V_149 = V_168 ;
V_163 -> V_169 = 0 ;
V_163 -> V_170 = 0 ;
}
V_12 = F_5 ( V_76 , V_151 ,
F_31 ( struct V_15 ) + V_149 ) ;
if ( ! V_12 )
return - V_125 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_171 ;
V_16 -> V_54 = V_149 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_127 = 0 ;
V_164 = (struct V_162 * ) ( ( V_97 ) V_16 +
V_16 -> V_55 ) ;
* V_164 = * V_163 ;
V_164 -> V_172 . type = V_173 ;
V_164 -> V_172 . V_174 = V_175 ;
V_164 -> V_172 . V_99 = V_149 ;
V_62 = F_17 ( V_76 , V_12 ) ;
if ( V_62 != 0 )
goto V_126;
V_124 = F_32 ( & V_12 -> V_18 , 5 * V_135 ) ;
if ( V_124 == 0 ) {
F_23 ( V_34 , L_31 ) ;
return - V_161 ;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_80 ) {
F_23 ( V_34 , L_32 ,
V_57 -> V_45 ) ;
V_62 = - V_115 ;
}
}
V_126:
F_11 ( V_76 , V_12 ) ;
return V_62 ;
}
int F_37 ( struct V_1 * V_76 , int V_176 )
{
struct V_31 * V_34 = V_76 -> V_75 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_147 * V_57 ;
T_1 V_149 = sizeof( struct V_177 ) +
4 * V_178 + V_179 ;
struct V_177 * V_180 ;
T_1 * V_181 ;
T_3 * V_182 ;
int V_183 , V_124 , V_62 ;
V_12 = F_5 (
V_76 , V_151 ,
F_31 ( struct V_15 ) + V_149 ) ;
if ( ! V_12 )
return - V_125 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_184 ;
V_16 -> V_54 = V_149 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_127 = 0 ;
V_180 = (struct V_177 * ) ( V_16 + 1 ) ;
V_180 -> V_131 . type = V_185 ;
V_180 -> V_131 . V_133 = V_186 ;
V_180 -> V_131 . V_99 = sizeof( struct V_177 ) ;
V_180 -> V_187 = 0 ;
V_180 -> V_188 = V_189 | V_190 |
V_191 ;
V_180 -> V_192 = 4 * V_178 ;
V_180 -> V_193 = sizeof( struct V_177 ) ;
V_180 -> V_194 = V_179 ;
V_180 -> V_195 = V_180 -> V_193 +
V_180 -> V_192 ;
V_181 = ( T_1 * ) ( V_180 + 1 ) ;
for ( V_183 = 0 ; V_183 < V_178 ; V_183 ++ )
V_181 [ V_183 ] = V_183 % V_176 ;
V_182 = ( T_3 * ) ( ( unsigned long ) V_180 + V_180 -> V_195 ) ;
for ( V_183 = 0 ; V_183 < V_179 ; V_183 ++ )
V_182 [ V_183 ] = V_196 [ V_183 ] ;
V_62 = F_17 ( V_76 , V_12 ) ;
if ( V_62 != 0 )
goto V_126;
V_124 = F_32 ( & V_12 -> V_18 , 5 * V_135 ) ;
if ( V_124 == 0 ) {
F_23 ( V_34 , L_29 ) ;
return - V_136 ;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_80 ) {
F_23 ( V_34 , L_33 ,
V_57 -> V_45 ) ;
V_62 = - V_115 ;
}
}
V_126:
F_11 ( V_76 , V_12 ) ;
return V_62 ;
}
static int F_38 ( struct V_1 * V_9 )
{
T_1 V_99 = sizeof( T_1 ) ;
T_1 V_77 ;
int V_62 ;
V_62 = F_30 ( V_9 ,
V_89 ,
& V_77 , & V_99 ) ;
return V_62 ;
}
int F_39 ( struct V_1 * V_9 , T_1 V_197 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_147 * V_57 ;
T_1 V_45 ;
int V_62 , V_124 ;
struct V_31 * V_34 ;
V_34 = V_9 -> V_75 -> V_34 ;
V_12 = F_5 ( V_9 , V_151 ,
F_31 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_62 = - V_125 ;
goto V_126;
}
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_198 ;
V_16 -> V_54 = sizeof( T_1 ) ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_197 , sizeof( T_1 ) ) ;
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 )
goto V_126;
V_124 = F_32 ( & V_12 -> V_18 , 5 * V_135 ) ;
if ( V_124 == 0 ) {
F_23 ( V_34 ,
L_29 ) ;
V_62 = - V_136 ;
goto exit;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
V_45 = V_57 -> V_45 ;
}
V_126:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
exit:
return V_62 ;
}
static int F_40 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_199 * V_200 ;
struct V_201 * V_44 ;
T_1 V_45 ;
int V_62 , V_124 ;
V_12 = F_5 ( V_9 , V_202 ,
F_31 ( struct V_199 ) ) ;
if ( ! V_12 ) {
V_62 = - V_125 ;
goto V_126;
}
V_200 = & V_12 -> V_19 . V_23 . V_84 ;
V_200 -> V_46 = V_203 ;
V_200 -> V_47 = V_204 ;
V_200 -> V_49 = 0x4000 ;
V_9 -> V_6 = V_205 ;
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_126;
}
V_124 = F_32 ( & V_12 -> V_18 , 5 * V_135 ) ;
if ( V_124 == 0 ) {
V_62 = - V_136 ;
goto V_126;
}
V_44 = & V_12 -> V_79 . V_23 . V_44 ;
V_45 = V_44 -> V_45 ;
if ( V_45 == V_80 ) {
V_9 -> V_6 = V_206 ;
V_62 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_62 = - V_115 ;
}
V_126:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_62 ;
}
static void F_41 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_207 * V_208 ;
struct V_33 * V_142 = V_9 -> V_75 ;
struct V_29 * V_140 = V_142 -> V_9 ;
V_97 V_17 ;
V_12 = F_5 ( V_9 , V_209 ,
F_31 ( struct V_207 ) ) ;
if ( ! V_12 )
goto V_126;
V_208 = & V_12 -> V_19 . V_23 . V_210 ;
V_208 -> V_25 = F_7 ( & V_9 -> V_26 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_126:
F_8 ( & V_140 -> V_211 -> V_212 , V_17 ) ;
V_142 -> V_213 = true ;
F_10 ( & V_140 -> V_211 -> V_212 , V_17 ) ;
V_18 ( V_142 -> V_214 ,
F_42 ( & V_142 -> V_215 ) == 0 ) ;
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_43 ( struct V_1 * V_9 )
{
int V_62 ;
if ( V_9 -> V_6 != V_206 )
return 0 ;
V_62 = F_39 ( V_9 ,
V_216 |
V_217 |
V_218 ) ;
if ( V_62 == 0 )
V_9 -> V_6 = V_219 ;
return V_62 ;
}
static int F_44 ( struct V_1 * V_9 )
{
int V_62 ;
if ( V_9 -> V_6 != V_219 )
return 0 ;
V_62 = F_39 ( V_9 , 0 ) ;
if ( V_62 == 0 )
V_9 -> V_6 = V_206 ;
return V_62 ;
}
static void F_45 ( struct V_220 * V_221 )
{
struct V_33 * V_222 ;
T_4 V_223 = V_221 -> V_224 . V_225 . V_226 ;
int V_62 ;
V_222 = F_15 ( V_221 -> V_227 -> V_228 ) ;
if ( V_223 >= V_222 -> V_229 )
return;
F_46 ( V_221 , V_222 -> V_230 + ( V_223 - 1 ) *
V_231 ) ;
V_62 = F_47 ( V_221 , V_222 -> V_232 * V_73 ,
V_222 -> V_232 * V_73 , NULL , 0 ,
V_233 , V_221 ) ;
if ( V_62 == 0 )
V_222 -> V_234 [ V_223 ] = V_221 ;
}
int F_48 ( struct V_29 * V_9 ,
void * V_235 )
{
int V_62 ;
struct V_33 * V_31 ;
struct V_1 * V_1 ;
struct V_236 * V_237 = V_235 ;
struct V_162 V_238 ;
struct V_239 * V_240 ;
int V_124 ;
struct V_129 V_241 ;
T_1 V_242 = sizeof( struct V_129 ) ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_117 ;
V_62 = F_49 ( V_9 , V_235 ) ;
if ( V_62 != 0 ) {
F_13 ( V_1 ) ;
return V_62 ;
}
V_31 = F_15 ( V_9 ) ;
V_31 -> V_229 = 1 ;
V_31 -> V_116 = V_1 ;
V_1 -> V_75 = V_31 ;
V_62 = F_40 ( V_1 ) ;
if ( V_62 != 0 ) {
F_50 ( V_9 ) ;
return V_62 ;
}
V_62 = F_33 ( V_1 ) ;
if ( V_62 != 0 ) {
F_50 ( V_9 ) ;
return V_62 ;
}
memcpy ( V_237 -> V_243 , V_1 -> V_139 , V_137 ) ;
memset ( & V_238 , 0 , sizeof( struct V_162 ) ) ;
V_238 . V_244 = V_245 ;
V_238 . V_246 = V_245 ;
V_238 . V_169 = V_245 ;
V_238 . V_247 = V_245 ;
V_238 . V_170 = V_245 ;
V_238 . V_248 = V_249 ;
V_62 = F_36 ( V_9 , & V_238 ) ;
if ( V_62 )
goto V_250;
F_38 ( V_1 ) ;
V_237 -> V_81 = V_1 -> V_81 ;
F_51 ( & V_9 -> V_2 , L_34 ,
V_1 -> V_139 ,
V_237 -> V_81 ? L_35 : L_36 ) ;
if ( V_31 -> V_166 < V_251 )
return 0 ;
memset ( & V_241 , 0 , V_242 ) ;
V_62 = F_30 ( V_1 ,
V_128 ,
& V_241 , & V_242 ) ;
if ( V_62 || V_241 . V_252 < 2 )
goto V_253;
V_31 -> V_229 = ( F_52 () < V_241 . V_252 ) ?
F_52 () : V_241 . V_252 ;
if ( V_31 -> V_229 == 1 )
goto V_253;
V_31 -> V_230 = F_53 ( ( V_31 -> V_229 - 1 ) *
V_231 ) ;
if ( ! V_31 -> V_230 ) {
V_31 -> V_229 = 1 ;
F_51 ( & V_9 -> V_2 , L_37 ) ;
goto V_253;
}
F_54 ( V_9 -> V_211 , F_45 ) ;
V_240 = & V_31 -> V_254 ;
memset ( V_240 , 0 , sizeof( struct V_239 ) ) ;
V_240 -> V_131 . V_10 = V_255 ;
V_240 -> V_23 . V_256 . V_257 . V_258 = V_259 ;
V_240 -> V_23 . V_256 . V_257 . V_260 =
V_31 -> V_229 - 1 ;
V_62 = F_55 ( V_9 -> V_211 , V_240 ,
sizeof( struct V_239 ) ,
( unsigned long ) V_240 ,
V_261 ,
V_262 ) ;
if ( V_62 )
goto V_253;
V_124 = F_32 ( & V_31 -> V_263 , 5 * V_135 ) ;
if ( V_124 == 0 ) {
V_62 = - V_136 ;
goto V_253;
}
if ( V_240 -> V_23 . V_256 . V_264 . V_45 !=
V_265 ) {
V_62 = - V_117 ;
goto V_253;
}
V_31 -> V_229 = 1 +
V_240 -> V_23 . V_256 . V_264 . V_260 ;
F_56 ( V_9 -> V_211 ) ;
V_62 = F_37 ( V_1 , V_31 -> V_229 ) ;
V_253:
if ( V_62 )
V_31 -> V_229 = 1 ;
return 0 ;
V_250:
F_50 ( V_9 ) ;
return V_62 ;
}
void F_50 ( struct V_29 * V_9 )
{
struct V_33 * V_75 = F_15 ( V_9 ) ;
struct V_1 * V_114 = V_75 -> V_116 ;
F_41 ( V_114 ) ;
F_13 ( V_114 ) ;
V_75 -> V_116 = NULL ;
F_57 ( V_9 ) ;
}
int F_58 ( struct V_29 * V_9 )
{
struct V_33 * V_31 = F_15 ( V_9 ) ;
if ( ! V_31 )
return - V_115 ;
return F_43 ( V_31 -> V_116 ) ;
}
int F_59 ( struct V_29 * V_9 )
{
struct V_33 * V_142 = F_15 ( V_9 ) ;
if ( ! V_142 )
return - V_115 ;
return F_44 ( V_142 -> V_116 ) ;
}
