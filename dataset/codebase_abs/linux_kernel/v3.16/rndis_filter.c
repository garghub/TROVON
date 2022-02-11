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
static void F_25 ( struct V_1 * V_9 ,
struct V_13 * V_82 )
{
struct V_93 * V_94 =
& V_82 -> V_23 . V_59 ;
if ( V_94 -> V_45 == V_95 ) {
F_26 (
V_9 -> V_75 -> V_9 , 1 ) ;
} else if ( V_94 -> V_45 == V_96 ) {
F_26 (
V_9 -> V_75 -> V_9 , 0 ) ;
} else {
}
}
static inline void * F_27 ( struct V_97 * V_98 , T_1 type )
{
struct V_99 * V_100 ;
int V_71 ;
if ( V_98 -> V_41 == 0 )
return NULL ;
V_100 = (struct V_99 * ) ( ( V_101 ) V_98 +
V_98 -> V_41 ) ;
V_71 = V_98 -> V_42 ;
while ( V_71 > 0 ) {
if ( V_100 -> type == type )
return ( void * ) ( ( V_101 ) V_100 + V_100 -> V_102 ) ;
V_71 -= V_100 -> V_103 ;
V_100 = (struct V_99 * ) ( ( V_101 ) V_100 + V_100 -> V_103 ) ;
}
return NULL ;
}
static void F_28 ( struct V_1 * V_9 ,
struct V_13 * V_23 ,
struct V_63 * V_21 )
{
struct V_97 * V_104 ;
T_1 V_36 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
V_104 = & V_23 -> V_23 . V_21 ;
V_36 = V_109 + V_104 -> V_36 ;
V_21 -> V_66 -= V_36 ;
if ( V_21 -> V_66 < V_104 -> V_37 ) {
F_23 ( V_9 -> V_75 -> V_34 , L_20
L_21
L_22 ,
V_21 -> V_66 , V_104 -> V_37 ) ;
return;
}
V_21 -> V_66 = V_104 -> V_37 ;
V_21 -> V_110 = ( void * ) ( ( unsigned long ) V_21 -> V_110 + V_36 ) ;
V_106 = F_27 ( V_104 , V_111 ) ;
if ( V_106 ) {
V_21 -> V_112 = V_113 | V_106 -> V_114 |
( V_106 -> V_115 << V_116 ) ;
} else {
V_21 -> V_112 = 0 ;
}
V_108 = F_27 ( V_104 , V_117 ) ;
F_29 ( V_9 -> V_75 -> V_9 , V_21 , V_108 ) ;
}
int F_30 ( struct V_29 * V_9 ,
struct V_63 * V_21 )
{
struct V_33 * V_75 = F_15 ( V_9 ) ;
struct V_1 * V_118 ;
struct V_13 * V_14 ;
struct V_31 * V_34 ;
int V_62 = 0 ;
if ( ! V_75 ) {
V_62 = - V_119 ;
goto exit;
}
V_34 = V_75 -> V_34 ;
if ( ! V_75 -> V_120 ) {
F_23 ( V_34 , L_23
L_24 ) ;
V_62 = - V_121 ;
goto exit;
}
V_118 = (struct V_1 * ) V_75 -> V_120 ;
if ( V_118 -> V_6 == V_7 ) {
F_23 ( V_34 , L_25
L_26 ) ;
V_62 = - V_121 ;
goto exit;
}
V_14 = V_21 -> V_110 ;
F_14 ( V_9 , V_14 ) ;
switch ( V_14 -> V_20 ) {
case V_35 :
F_28 ( V_118 , V_14 , V_21 ) ;
break;
case V_43 :
case V_52 :
case V_56 :
F_21 ( V_118 , V_14 ) ;
break;
case V_58 :
F_25 ( V_118 , V_14 ) ;
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
V_21 -> V_45 = V_122 ;
return V_62 ;
}
static int F_31 ( struct V_1 * V_9 , T_1 V_88 ,
void * V_123 , T_1 * V_124 )
{
struct V_8 * V_12 ;
T_1 V_125 = * V_124 ;
struct V_126 * V_127 ;
struct V_78 * V_53 ;
int V_62 = 0 ;
int V_128 ;
if ( ! V_123 )
return - V_119 ;
* V_124 = 0 ;
V_12 = F_5 ( V_9 , V_86 ,
F_32 ( struct V_126 ) ) ;
if ( ! V_12 ) {
V_62 = - V_129 ;
goto V_130;
}
V_127 = & V_12 -> V_19 . V_23 . V_87 ;
V_127 -> V_88 = V_88 ;
V_127 -> V_55 = sizeof( struct V_126 ) ;
V_127 -> V_54 = 0 ;
V_127 -> V_131 = 0 ;
if ( V_88 == V_132 ) {
struct V_133 * V_134 ;
V_12 -> V_19 . V_11 +=
sizeof( struct V_133 ) ;
V_127 -> V_54 = sizeof( struct V_133 ) ;
V_134 = (struct V_133 * ) ( ( unsigned long ) V_127 +
V_127 -> V_55 ) ;
V_134 -> V_135 . type = V_136 ;
V_134 -> V_135 . V_137 = V_138 ;
V_134 -> V_135 . V_103 = sizeof( struct V_133 ) ;
}
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 )
goto V_130;
V_128 = F_33 ( & V_12 -> V_18 , 5 * V_139 ) ;
if ( V_128 == 0 ) {
V_62 = - V_140 ;
goto V_130;
}
V_53 = & V_12 -> V_79 . V_23 . V_53 ;
if ( V_53 -> V_54 > V_125 ) {
V_62 = - 1 ;
goto V_130;
}
memcpy ( V_123 ,
( void * ) ( ( unsigned long ) V_53 +
V_53 -> V_55 ) ,
V_53 -> V_54 ) ;
* V_124 = V_53 -> V_54 ;
V_130:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_62 ;
}
static int F_34 ( struct V_1 * V_9 )
{
T_1 V_103 = V_141 ;
return F_31 ( V_9 ,
V_142 ,
V_9 -> V_143 , & V_103 ) ;
}
int F_35 ( struct V_29 * V_144 , char * V_145 )
{
struct V_33 * V_146 = F_15 ( V_144 ) ;
struct V_1 * V_76 = V_146 -> V_120 ;
struct V_31 * V_34 = V_146 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_147 * V_148 ;
T_2 * V_149 , * V_150 ;
struct V_151 * V_57 ;
char V_152 [ 2 * V_141 + 1 ] ;
T_1 V_153 = sizeof( struct V_147 ) +
2 * V_154 + 4 * V_141 ;
int V_62 , V_128 ;
V_12 = F_5 ( V_76 , V_155 ,
F_32 ( struct V_15 ) + V_153 ) ;
if ( ! V_12 )
return - V_129 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_156 ;
V_16 -> V_54 = V_153 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_131 = 0 ;
V_148 = (struct V_147 * ) ( ( V_101 ) V_16 +
V_16 -> V_55 ) ;
V_148 -> V_157 =
sizeof( struct V_147 ) ;
V_148 -> V_158 = 2 * V_154 ;
V_148 -> V_159 = V_160 ;
V_148 -> V_161 =
V_148 -> V_157 + V_148 -> V_158 ;
V_148 -> V_162 = 4 * V_141 ;
V_149 = ( T_2 * ) ( ( V_101 ) V_148 + V_148 -> V_157 ) ;
V_150 = ( T_2 * ) ( ( V_101 ) V_148 + V_148 -> V_161 ) ;
V_62 = F_36 ( V_163 , V_154 , V_164 ,
V_149 , V_154 ) ;
if ( V_62 < 0 )
goto V_130;
snprintf ( V_152 , 2 * V_141 + 1 , L_28 , V_145 ) ;
V_62 = F_36 ( V_152 , 2 * V_141 , V_164 ,
V_150 , 2 * V_141 ) ;
if ( V_62 < 0 )
goto V_130;
V_62 = F_17 ( V_76 , V_12 ) ;
if ( V_62 != 0 )
goto V_130;
V_128 = F_33 ( & V_12 -> V_18 , 5 * V_139 ) ;
if ( V_128 == 0 ) {
F_23 ( V_34 , L_29 ) ;
return - V_165 ;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_80 ) {
F_23 ( V_34 , L_30 ,
V_57 -> V_45 ) ;
V_62 = - V_119 ;
}
}
V_130:
F_11 ( V_76 , V_12 ) ;
return V_62 ;
}
int F_37 ( struct V_29 * V_144 ,
struct V_166 * V_167 )
{
struct V_33 * V_146 = F_15 ( V_144 ) ;
struct V_1 * V_76 = V_146 -> V_120 ;
struct V_31 * V_34 = V_146 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_166 * V_168 ;
struct V_151 * V_57 ;
T_1 V_153 = sizeof( struct V_166 ) ;
int V_62 , V_128 ;
T_1 V_169 = V_146 -> V_170 ;
if ( V_169 <= V_171 ) {
V_153 = V_172 ;
V_167 -> V_173 = 0 ;
V_167 -> V_174 = 0 ;
}
V_12 = F_5 ( V_76 , V_155 ,
F_32 ( struct V_15 ) + V_153 ) ;
if ( ! V_12 )
return - V_129 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_175 ;
V_16 -> V_54 = V_153 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_131 = 0 ;
V_168 = (struct V_166 * ) ( ( V_101 ) V_16 +
V_16 -> V_55 ) ;
* V_168 = * V_167 ;
V_168 -> V_176 . type = V_177 ;
V_168 -> V_176 . V_178 = V_179 ;
V_168 -> V_176 . V_103 = V_153 ;
V_62 = F_17 ( V_76 , V_12 ) ;
if ( V_62 != 0 )
goto V_130;
V_128 = F_33 ( & V_12 -> V_18 , 5 * V_139 ) ;
if ( V_128 == 0 ) {
F_23 ( V_34 , L_31 ) ;
return - V_165 ;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_80 ) {
F_23 ( V_34 , L_32 ,
V_57 -> V_45 ) ;
V_62 = - V_119 ;
}
}
V_130:
F_11 ( V_76 , V_12 ) ;
return V_62 ;
}
int F_38 ( struct V_1 * V_76 , int V_180 )
{
struct V_31 * V_34 = V_76 -> V_75 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_151 * V_57 ;
T_1 V_153 = sizeof( struct V_181 ) +
4 * V_182 + V_183 ;
struct V_181 * V_184 ;
T_1 * V_185 ;
T_3 * V_186 ;
int V_187 , V_128 , V_62 ;
V_12 = F_5 (
V_76 , V_155 ,
F_32 ( struct V_15 ) + V_153 ) ;
if ( ! V_12 )
return - V_129 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_188 ;
V_16 -> V_54 = V_153 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_131 = 0 ;
V_184 = (struct V_181 * ) ( V_16 + 1 ) ;
V_184 -> V_135 . type = V_189 ;
V_184 -> V_135 . V_137 = V_190 ;
V_184 -> V_135 . V_103 = sizeof( struct V_181 ) ;
V_184 -> V_191 = 0 ;
V_184 -> V_192 = V_193 | V_194 |
V_195 ;
V_184 -> V_196 = 4 * V_182 ;
V_184 -> V_197 = sizeof( struct V_181 ) ;
V_184 -> V_198 = V_183 ;
V_184 -> V_199 = V_184 -> V_197 +
V_184 -> V_196 ;
V_185 = ( T_1 * ) ( V_184 + 1 ) ;
for ( V_187 = 0 ; V_187 < V_182 ; V_187 ++ )
V_185 [ V_187 ] = V_187 % V_180 ;
V_186 = ( T_3 * ) ( ( unsigned long ) V_184 + V_184 -> V_199 ) ;
for ( V_187 = 0 ; V_187 < V_183 ; V_187 ++ )
V_186 [ V_187 ] = V_200 [ V_187 ] ;
V_62 = F_17 ( V_76 , V_12 ) ;
if ( V_62 != 0 )
goto V_130;
V_128 = F_33 ( & V_12 -> V_18 , 5 * V_139 ) ;
if ( V_128 == 0 ) {
F_23 ( V_34 , L_29 ) ;
return - V_140 ;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_80 ) {
F_23 ( V_34 , L_33 ,
V_57 -> V_45 ) ;
V_62 = - V_119 ;
}
}
V_130:
F_11 ( V_76 , V_12 ) ;
return V_62 ;
}
static int F_39 ( struct V_1 * V_9 )
{
T_1 V_103 = sizeof( T_1 ) ;
T_1 V_77 ;
int V_62 ;
V_62 = F_31 ( V_9 ,
V_89 ,
& V_77 , & V_103 ) ;
return V_62 ;
}
int F_40 ( struct V_1 * V_9 , T_1 V_201 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_151 * V_57 ;
T_1 V_45 ;
int V_62 , V_128 ;
struct V_31 * V_34 ;
V_34 = V_9 -> V_75 -> V_34 ;
V_12 = F_5 ( V_9 , V_155 ,
F_32 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_62 = - V_129 ;
goto V_130;
}
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_88 = V_202 ;
V_16 -> V_54 = sizeof( T_1 ) ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_201 , sizeof( T_1 ) ) ;
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 )
goto V_130;
V_128 = F_33 ( & V_12 -> V_18 , 5 * V_139 ) ;
if ( V_128 == 0 ) {
F_23 ( V_34 ,
L_29 ) ;
V_62 = - V_140 ;
goto exit;
} else {
V_57 = & V_12 -> V_79 . V_23 . V_57 ;
V_45 = V_57 -> V_45 ;
}
V_130:
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
int V_62 , V_128 ;
V_12 = F_5 ( V_9 , V_206 ,
F_32 ( struct V_203 ) ) ;
if ( ! V_12 ) {
V_62 = - V_129 ;
goto V_130;
}
V_204 = & V_12 -> V_19 . V_23 . V_84 ;
V_204 -> V_46 = V_207 ;
V_204 -> V_47 = V_208 ;
V_204 -> V_49 = 0x4000 ;
V_9 -> V_6 = V_209 ;
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_130;
}
V_128 = F_33 ( & V_12 -> V_18 , 5 * V_139 ) ;
if ( V_128 == 0 ) {
V_62 = - V_140 ;
goto V_130;
}
V_44 = & V_12 -> V_79 . V_23 . V_44 ;
V_45 = V_44 -> V_45 ;
if ( V_45 == V_80 ) {
V_9 -> V_6 = V_210 ;
V_62 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_62 = - V_119 ;
}
V_130:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_62 ;
}
static void F_42 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_211 * V_212 ;
struct V_33 * V_146 = V_9 -> V_75 ;
struct V_29 * V_144 = V_146 -> V_9 ;
V_101 V_17 ;
V_12 = F_5 ( V_9 , V_213 ,
F_32 ( struct V_211 ) ) ;
if ( ! V_12 )
goto V_130;
V_212 = & V_12 -> V_19 . V_23 . V_214 ;
V_212 -> V_25 = F_7 ( & V_9 -> V_26 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_130:
F_8 ( & V_144 -> V_215 -> V_216 , V_17 ) ;
V_146 -> V_217 = true ;
F_10 ( & V_144 -> V_215 -> V_216 , V_17 ) ;
V_18 ( V_146 -> V_218 ,
F_43 ( & V_146 -> V_219 ) == 0 ) ;
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
V_220 |
V_221 |
V_222 ) ;
if ( V_62 == 0 )
V_9 -> V_6 = V_223 ;
return V_62 ;
}
static int F_45 ( struct V_1 * V_9 )
{
int V_62 ;
if ( V_9 -> V_6 != V_223 )
return 0 ;
V_62 = F_40 ( V_9 , 0 ) ;
if ( V_62 == 0 )
V_9 -> V_6 = V_210 ;
return V_62 ;
}
static void F_46 ( struct V_224 * V_225 )
{
struct V_33 * V_226 ;
T_4 V_227 = V_225 -> V_228 . V_229 . V_230 ;
int V_62 ;
V_226 = F_15 ( V_225 -> V_231 -> V_232 ) ;
if ( V_227 >= V_226 -> V_233 )
return;
F_47 ( V_225 , V_226 -> V_234 + ( V_227 - 1 ) *
V_235 ) ;
V_62 = F_48 ( V_225 , V_226 -> V_236 * V_73 ,
V_226 -> V_236 * V_73 , NULL , 0 ,
V_237 , V_225 ) ;
if ( V_62 == 0 )
V_226 -> V_238 [ V_227 ] = V_225 ;
}
int F_49 ( struct V_29 * V_9 ,
void * V_239 )
{
int V_62 ;
struct V_33 * V_31 ;
struct V_1 * V_1 ;
struct V_240 * V_241 = V_239 ;
struct V_166 V_242 ;
struct V_243 * V_244 ;
int V_128 ;
struct V_133 V_245 ;
T_1 V_246 = sizeof( struct V_133 ) ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_121 ;
V_62 = F_50 ( V_9 , V_239 ) ;
if ( V_62 != 0 ) {
F_13 ( V_1 ) ;
return V_62 ;
}
V_31 = F_15 ( V_9 ) ;
V_31 -> V_233 = 1 ;
V_31 -> V_120 = V_1 ;
V_1 -> V_75 = V_31 ;
V_62 = F_41 ( V_1 ) ;
if ( V_62 != 0 ) {
F_51 ( V_9 ) ;
return V_62 ;
}
V_62 = F_34 ( V_1 ) ;
if ( V_62 != 0 ) {
F_51 ( V_9 ) ;
return V_62 ;
}
memcpy ( V_241 -> V_247 , V_1 -> V_143 , V_141 ) ;
memset ( & V_242 , 0 , sizeof( struct V_166 ) ) ;
V_242 . V_248 = V_249 ;
V_242 . V_250 = V_249 ;
V_242 . V_173 = V_249 ;
V_242 . V_251 = V_249 ;
V_242 . V_174 = V_249 ;
V_242 . V_252 = V_253 ;
V_62 = F_37 ( V_9 , & V_242 ) ;
if ( V_62 )
goto V_254;
F_39 ( V_1 ) ;
V_241 -> V_81 = V_1 -> V_81 ;
F_52 ( & V_9 -> V_2 , L_34 ,
V_1 -> V_143 ,
V_241 -> V_81 ? L_35 : L_36 ) ;
if ( V_31 -> V_170 < V_255 )
return 0 ;
memset ( & V_245 , 0 , V_246 ) ;
V_62 = F_31 ( V_1 ,
V_132 ,
& V_245 , & V_246 ) ;
if ( V_62 || V_245 . V_256 < 2 )
goto V_257;
V_31 -> V_233 = ( F_53 () < V_245 . V_256 ) ?
F_53 () : V_245 . V_256 ;
if ( V_31 -> V_233 == 1 )
goto V_257;
V_31 -> V_234 = F_54 ( ( V_31 -> V_233 - 1 ) *
V_235 ) ;
if ( ! V_31 -> V_234 ) {
V_31 -> V_233 = 1 ;
F_52 ( & V_9 -> V_2 , L_37 ) ;
goto V_257;
}
F_55 ( V_9 -> V_215 , F_46 ) ;
V_244 = & V_31 -> V_258 ;
memset ( V_244 , 0 , sizeof( struct V_243 ) ) ;
V_244 -> V_135 . V_10 = V_259 ;
V_244 -> V_23 . V_260 . V_261 . V_262 = V_263 ;
V_244 -> V_23 . V_260 . V_261 . V_264 =
V_31 -> V_233 - 1 ;
V_62 = F_56 ( V_9 -> V_215 , V_244 ,
sizeof( struct V_243 ) ,
( unsigned long ) V_244 ,
V_265 ,
V_266 ) ;
if ( V_62 )
goto V_257;
V_128 = F_33 ( & V_31 -> V_267 , 5 * V_139 ) ;
if ( V_128 == 0 ) {
V_62 = - V_140 ;
goto V_257;
}
if ( V_244 -> V_23 . V_260 . V_268 . V_45 !=
V_269 ) {
V_62 = - V_121 ;
goto V_257;
}
V_31 -> V_233 = 1 +
V_244 -> V_23 . V_260 . V_268 . V_264 ;
F_57 ( V_9 -> V_215 ) ;
V_62 = F_38 ( V_1 , V_31 -> V_233 ) ;
V_257:
if ( V_62 )
V_31 -> V_233 = 1 ;
return 0 ;
V_254:
F_51 ( V_9 ) ;
return V_62 ;
}
void F_51 ( struct V_29 * V_9 )
{
struct V_33 * V_75 = F_15 ( V_9 ) ;
struct V_1 * V_118 = V_75 -> V_120 ;
F_42 ( V_118 ) ;
F_13 ( V_118 ) ;
V_75 -> V_120 = NULL ;
F_58 ( V_9 ) ;
}
int F_59 ( struct V_29 * V_9 )
{
struct V_33 * V_31 = F_15 ( V_9 ) ;
if ( ! V_31 )
return - V_119 ;
return F_44 ( V_31 -> V_120 ) ;
}
int F_60 ( struct V_29 * V_9 )
{
struct V_33 * V_146 = F_15 ( V_9 ) ;
if ( ! V_146 )
return - V_119 ;
return F_45 ( V_146 -> V_120 ) ;
}
