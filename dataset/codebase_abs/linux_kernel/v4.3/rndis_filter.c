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
V_64 = & V_28 -> V_21 ;
V_64 -> V_67 = false ;
V_64 -> V_68 = V_28 -> V_19 . V_11 ;
V_64 -> V_69 = 1 ;
V_64 -> V_66 = V_66 ;
V_64 -> V_66 [ 0 ] . V_70 = F_18 ( & V_28 -> V_19 ) >>
V_71 ;
V_64 -> V_66 [ 0 ] . V_72 = V_28 -> V_19 . V_11 ;
V_64 -> V_66 [ 0 ] . V_73 =
( unsigned long ) & V_28 -> V_19 & ( V_74 - 1 ) ;
if ( V_64 -> V_66 [ 0 ] . V_73 + V_64 -> V_66 [ 0 ] . V_72 > V_74 ) {
V_64 -> V_69 ++ ;
V_64 -> V_66 [ 0 ] . V_72 = V_74 -
V_64 -> V_66 [ 0 ] . V_73 ;
V_64 -> V_66 [ 1 ] . V_70 = F_18 ( ( void * ) & V_28 -> V_19
+ V_64 -> V_66 [ 0 ] . V_72 ) >> V_71 ;
V_64 -> V_66 [ 1 ] . V_73 = 0 ;
V_64 -> V_66 [ 1 ] . V_72 = V_28 -> V_19 . V_11 -
V_64 -> V_66 [ 0 ] . V_72 ;
}
V_64 -> V_75 = NULL ;
V_64 -> V_76 = false ;
V_62 = F_19 ( V_9 -> V_77 -> V_9 , V_64 ) ;
return V_62 ;
}
static void F_20 ( struct V_1 * V_78 ,
struct V_8 * V_12 )
{
T_1 V_79 ;
struct V_80 * V_53 ;
V_53 = & V_12 -> V_81 . V_23 . V_53 ;
if ( V_53 -> V_45 == V_82 &&
V_53 -> V_54 == sizeof( T_1 ) ) {
memcpy ( & V_79 , ( void * ) ( ( unsigned long ) V_53 +
V_53 -> V_55 ) , sizeof( T_1 ) ) ;
V_78 -> V_83 = V_79 != 0 ;
}
}
static void F_21 ( struct V_1 * V_9 ,
struct V_13 * V_84 )
{
struct V_8 * V_12 = NULL ;
bool V_85 = false ;
unsigned long V_17 ;
struct V_31 * V_34 ;
V_34 = V_9 -> V_77 -> V_34 ;
F_8 ( & V_9 -> V_4 , V_17 ) ;
F_22 (request, &dev->req_list, list_ent) {
if ( V_12 -> V_19 . V_23 . V_86 . V_25
== V_84 -> V_23 . V_44 . V_25 ) {
V_85 = true ;
break;
}
}
F_10 ( & V_9 -> V_4 , V_17 ) ;
if ( V_85 ) {
if ( V_84 -> V_11 <=
sizeof( struct V_13 ) + V_87 ) {
memcpy ( & V_12 -> V_81 , V_84 ,
V_84 -> V_11 ) ;
if ( V_12 -> V_19 . V_20 ==
V_88 && V_12 -> V_19 . V_23 .
V_89 . V_90 == V_91 )
F_20 ( V_9 , V_12 ) ;
} else {
F_23 ( V_34 ,
L_16
L_17 ,
V_84 -> V_11 ,
sizeof( struct V_13 ) ) ;
if ( V_84 -> V_20 ==
V_92 ) {
V_12 -> V_81 . V_23 . V_93 .
V_45 = V_94 ;
} else {
V_12 -> V_81 . V_23 .
V_44 . V_45 =
V_94 ;
}
}
F_24 ( & V_12 -> V_18 ) ;
} else {
F_23 ( V_34 ,
L_18
L_19 ,
V_84 -> V_23 . V_44 . V_25 ,
V_84 -> V_20 ) ;
}
}
static inline void * F_25 ( struct V_95 * V_96 , T_1 type )
{
struct V_97 * V_98 ;
int V_72 ;
if ( V_96 -> V_41 == 0 )
return NULL ;
V_98 = (struct V_97 * ) ( ( V_99 ) V_96 +
V_96 -> V_41 ) ;
V_72 = V_96 -> V_42 ;
while ( V_72 > 0 ) {
if ( V_98 -> type == type )
return ( void * ) ( ( V_99 ) V_98 + V_98 -> V_100 ) ;
V_72 -= V_98 -> V_101 ;
V_98 = (struct V_97 * ) ( ( V_99 ) V_98 + V_98 -> V_101 ) ;
}
return NULL ;
}
static void F_26 ( struct V_1 * V_9 ,
struct V_13 * V_23 ,
struct V_63 * V_21 )
{
struct V_95 * V_102 ;
T_1 V_36 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
V_102 = & V_23 -> V_23 . V_21 ;
V_36 = V_107 + V_102 -> V_36 ;
V_21 -> V_68 -= V_36 ;
if ( V_21 -> V_68 < V_102 -> V_37 ) {
F_23 ( V_9 -> V_77 -> V_34 , L_20
L_21
L_22 ,
V_21 -> V_68 , V_102 -> V_37 ) ;
return;
}
V_21 -> V_68 = V_102 -> V_37 ;
V_21 -> V_108 = ( void * ) ( ( unsigned long ) V_21 -> V_108 + V_36 ) ;
V_104 = F_25 ( V_102 , V_109 ) ;
if ( V_104 ) {
V_21 -> V_110 = V_111 | V_104 -> V_112 |
( V_104 -> V_113 << V_114 ) ;
} else {
V_21 -> V_110 = 0 ;
}
V_106 = F_25 ( V_102 , V_115 ) ;
F_27 ( V_9 -> V_77 -> V_9 , V_21 , V_106 ) ;
}
int F_28 ( struct V_29 * V_9 ,
struct V_63 * V_21 )
{
struct V_33 * V_77 = F_15 ( V_9 ) ;
struct V_1 * V_116 ;
struct V_13 * V_14 ;
struct V_31 * V_34 ;
int V_62 = 0 ;
if ( ! V_77 ) {
V_62 = - V_117 ;
goto exit;
}
V_34 = V_77 -> V_34 ;
if ( ! V_77 -> V_118 ) {
F_23 ( V_34 , L_23
L_24 ) ;
V_62 = - V_119 ;
goto exit;
}
V_116 = (struct V_1 * ) V_77 -> V_118 ;
if ( V_116 -> V_6 == V_7 ) {
F_23 ( V_34 , L_25
L_26 ) ;
V_62 = - V_119 ;
goto exit;
}
V_14 = V_21 -> V_108 ;
if ( F_29 ( V_77 -> V_120 ) )
F_14 ( V_9 , V_14 ) ;
switch ( V_14 -> V_20 ) {
case V_35 :
F_26 ( V_116 , V_14 , V_21 ) ;
break;
case V_43 :
case V_52 :
case V_56 :
F_21 ( V_116 , V_14 ) ;
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
if ( V_62 != 0 )
V_21 -> V_45 = V_121 ;
return V_62 ;
}
static int F_31 ( struct V_1 * V_9 , T_1 V_90 ,
void * V_122 , T_1 * V_123 )
{
struct V_8 * V_12 ;
T_1 V_124 = * V_123 ;
struct V_125 * V_126 ;
struct V_80 * V_53 ;
int V_62 = 0 ;
unsigned long V_127 ;
if ( ! V_122 )
return - V_117 ;
* V_123 = 0 ;
V_12 = F_5 ( V_9 , V_88 ,
F_32 ( struct V_125 ) ) ;
if ( ! V_12 ) {
V_62 = - V_128 ;
goto V_129;
}
V_126 = & V_12 -> V_19 . V_23 . V_89 ;
V_126 -> V_90 = V_90 ;
V_126 -> V_55 = sizeof( struct V_125 ) ;
V_126 -> V_54 = 0 ;
V_126 -> V_130 = 0 ;
if ( V_90 == V_131 ) {
struct V_132 * V_133 ;
V_12 -> V_19 . V_11 +=
sizeof( struct V_132 ) ;
V_126 -> V_54 = sizeof( struct V_132 ) ;
V_133 = (struct V_132 * ) ( ( unsigned long ) V_126 +
V_126 -> V_55 ) ;
V_133 -> V_134 . type = V_135 ;
V_133 -> V_134 . V_136 = V_137 ;
V_133 -> V_134 . V_101 = sizeof( struct V_132 ) ;
}
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 )
goto V_129;
V_127 = F_33 ( & V_12 -> V_18 , 5 * V_138 ) ;
if ( V_127 == 0 ) {
V_62 = - V_139 ;
goto V_129;
}
V_53 = & V_12 -> V_81 . V_23 . V_53 ;
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
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_62 ;
}
static int F_34 ( struct V_1 * V_9 )
{
T_1 V_101 = V_140 ;
return F_31 ( V_9 ,
V_141 ,
V_9 -> V_142 , & V_101 ) ;
}
int F_35 ( struct V_29 * V_143 , char * V_144 )
{
struct V_33 * V_145 = F_15 ( V_143 ) ;
struct V_1 * V_78 = V_145 -> V_118 ;
struct V_31 * V_34 = V_145 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_146 * V_147 ;
T_2 * V_148 , * V_149 ;
struct V_150 * V_57 ;
char V_151 [ 2 * V_140 + 1 ] ;
T_1 V_152 = sizeof( struct V_146 ) +
2 * V_153 + 4 * V_140 ;
int V_62 ;
unsigned long V_127 ;
V_12 = F_5 ( V_78 , V_154 ,
F_32 ( struct V_15 ) + V_152 ) ;
if ( ! V_12 )
return - V_128 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_90 = V_155 ;
V_16 -> V_54 = V_152 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_130 = 0 ;
V_147 = (struct V_146 * ) ( ( V_99 ) V_16 +
V_16 -> V_55 ) ;
V_147 -> V_156 =
sizeof( struct V_146 ) ;
V_147 -> V_157 = 2 * V_153 ;
V_147 -> V_158 = V_159 ;
V_147 -> V_160 =
V_147 -> V_156 + V_147 -> V_157 ;
V_147 -> V_161 = 4 * V_140 ;
V_148 = ( T_2 * ) ( ( V_99 ) V_147 + V_147 -> V_156 ) ;
V_149 = ( T_2 * ) ( ( V_99 ) V_147 + V_147 -> V_160 ) ;
V_62 = F_36 ( V_162 , V_153 , V_163 ,
V_148 , V_153 ) ;
if ( V_62 < 0 )
goto V_129;
snprintf ( V_151 , 2 * V_140 + 1 , L_28 , V_144 ) ;
V_62 = F_36 ( V_151 , 2 * V_140 , V_163 ,
V_149 , 2 * V_140 ) ;
if ( V_62 < 0 )
goto V_129;
V_62 = F_17 ( V_78 , V_12 ) ;
if ( V_62 != 0 )
goto V_129;
V_127 = F_33 ( & V_12 -> V_18 , 5 * V_138 ) ;
if ( V_127 == 0 ) {
F_23 ( V_34 , L_29 ) ;
return - V_164 ;
} else {
V_57 = & V_12 -> V_81 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_82 ) {
F_23 ( V_34 , L_30 ,
V_57 -> V_45 ) ;
V_62 = - V_117 ;
}
}
V_129:
F_11 ( V_78 , V_12 ) ;
return V_62 ;
}
static int
F_37 ( struct V_29 * V_143 ,
struct V_165 * V_166 )
{
struct V_33 * V_145 = F_15 ( V_143 ) ;
struct V_1 * V_78 = V_145 -> V_118 ;
struct V_31 * V_34 = V_145 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_165 * V_167 ;
struct V_150 * V_57 ;
T_1 V_152 = sizeof( struct V_165 ) ;
int V_62 ;
unsigned long V_127 ;
T_1 V_168 = V_145 -> V_169 ;
if ( V_168 <= V_170 ) {
V_152 = V_171 ;
V_166 -> V_172 = 0 ;
V_166 -> V_173 = 0 ;
}
V_12 = F_5 ( V_78 , V_154 ,
F_32 ( struct V_15 ) + V_152 ) ;
if ( ! V_12 )
return - V_128 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_90 = V_174 ;
V_16 -> V_54 = V_152 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_130 = 0 ;
V_167 = (struct V_165 * ) ( ( V_99 ) V_16 +
V_16 -> V_55 ) ;
* V_167 = * V_166 ;
V_167 -> V_175 . type = V_176 ;
V_167 -> V_175 . V_177 = V_178 ;
V_167 -> V_175 . V_101 = V_152 ;
V_62 = F_17 ( V_78 , V_12 ) ;
if ( V_62 != 0 )
goto V_129;
V_127 = F_33 ( & V_12 -> V_18 , 5 * V_138 ) ;
if ( V_127 == 0 ) {
F_23 ( V_34 , L_31 ) ;
return - V_164 ;
} else {
V_57 = & V_12 -> V_81 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_82 ) {
F_23 ( V_34 , L_32 ,
V_57 -> V_45 ) ;
V_62 = - V_117 ;
}
}
V_129:
F_11 ( V_78 , V_12 ) ;
return V_62 ;
}
static int F_38 ( struct V_1 * V_78 , int V_179 )
{
struct V_31 * V_34 = V_78 -> V_77 -> V_34 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_150 * V_57 ;
T_1 V_152 = sizeof( struct V_180 ) +
4 * V_181 + V_182 ;
struct V_180 * V_183 ;
T_1 * V_184 ;
T_3 * V_185 ;
int V_186 , V_62 ;
unsigned long V_127 ;
V_12 = F_5 (
V_78 , V_154 ,
F_32 ( struct V_15 ) + V_152 ) ;
if ( ! V_12 )
return - V_128 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_90 = V_187 ;
V_16 -> V_54 = V_152 ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
V_16 -> V_130 = 0 ;
V_183 = (struct V_180 * ) ( V_16 + 1 ) ;
V_183 -> V_134 . type = V_188 ;
V_183 -> V_134 . V_136 = V_189 ;
V_183 -> V_134 . V_101 = sizeof( struct V_180 ) ;
V_183 -> V_190 = 0 ;
V_183 -> V_191 = V_192 | V_193 |
V_194 | V_195 |
V_196 ;
V_183 -> V_197 = 4 * V_181 ;
V_183 -> V_198 = sizeof( struct V_180 ) ;
V_183 -> V_199 = V_182 ;
V_183 -> V_200 = V_183 -> V_198 +
V_183 -> V_197 ;
V_184 = ( T_1 * ) ( V_183 + 1 ) ;
for ( V_186 = 0 ; V_186 < V_181 ; V_186 ++ )
V_184 [ V_186 ] = V_186 % V_179 ;
V_185 = ( T_3 * ) ( ( unsigned long ) V_183 + V_183 -> V_200 ) ;
for ( V_186 = 0 ; V_186 < V_182 ; V_186 ++ )
V_185 [ V_186 ] = V_201 [ V_186 ] ;
V_62 = F_17 ( V_78 , V_12 ) ;
if ( V_62 != 0 )
goto V_129;
V_127 = F_33 ( & V_12 -> V_18 , 5 * V_138 ) ;
if ( V_127 == 0 ) {
F_23 ( V_34 , L_29 ) ;
return - V_139 ;
} else {
V_57 = & V_12 -> V_81 . V_23 . V_57 ;
if ( V_57 -> V_45 != V_82 ) {
F_23 ( V_34 , L_33 ,
V_57 -> V_45 ) ;
V_62 = - V_117 ;
}
}
V_129:
F_11 ( V_78 , V_12 ) ;
return V_62 ;
}
static int F_39 ( struct V_1 * V_9 )
{
T_1 V_101 = sizeof( T_1 ) ;
T_1 V_79 ;
int V_62 ;
V_62 = F_31 ( V_9 ,
V_91 ,
& V_79 , & V_101 ) ;
return V_62 ;
}
int F_40 ( struct V_1 * V_9 , T_1 V_202 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_150 * V_57 ;
T_1 V_45 ;
int V_62 ;
unsigned long V_127 ;
struct V_31 * V_34 ;
V_34 = V_9 -> V_77 -> V_34 ;
V_12 = F_5 ( V_9 , V_154 ,
F_32 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_62 = - V_128 ;
goto V_129;
}
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_90 = V_203 ;
V_16 -> V_54 = sizeof( T_1 ) ;
V_16 -> V_55 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_202 , sizeof( T_1 ) ) ;
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 )
goto V_129;
V_127 = F_33 ( & V_12 -> V_18 , 5 * V_138 ) ;
if ( V_127 == 0 ) {
F_23 ( V_34 ,
L_29 ) ;
V_62 = - V_139 ;
goto exit;
} else {
V_57 = & V_12 -> V_81 . V_23 . V_57 ;
V_45 = V_57 -> V_45 ;
}
V_129:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
exit:
return V_62 ;
}
static int F_41 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_204 * V_205 ;
struct V_206 * V_44 ;
T_1 V_45 ;
int V_62 ;
unsigned long V_127 ;
struct V_33 * V_145 = V_9 -> V_77 ;
V_12 = F_5 ( V_9 , V_207 ,
F_32 ( struct V_204 ) ) ;
if ( ! V_12 ) {
V_62 = - V_128 ;
goto V_129;
}
V_205 = & V_12 -> V_19 . V_23 . V_86 ;
V_205 -> V_46 = V_208 ;
V_205 -> V_47 = V_209 ;
V_205 -> V_49 = 0x4000 ;
V_9 -> V_6 = V_210 ;
V_62 = F_17 ( V_9 , V_12 ) ;
if ( V_62 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_129;
}
V_127 = F_33 ( & V_12 -> V_18 , 5 * V_138 ) ;
if ( V_127 == 0 ) {
V_62 = - V_139 ;
goto V_129;
}
V_44 = & V_12 -> V_81 . V_23 . V_44 ;
V_45 = V_44 -> V_45 ;
if ( V_45 == V_82 ) {
V_9 -> V_6 = V_211 ;
V_145 -> V_212 = V_44 -> V_50 ;
V_145 -> V_213 = 1 << V_44 -> V_51 ;
V_62 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_62 = - V_117 ;
}
V_129:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_62 ;
}
static void F_42 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_214 * V_215 ;
struct V_33 * V_145 = V_9 -> V_77 ;
struct V_29 * V_143 = V_145 -> V_9 ;
V_99 V_17 ;
V_12 = F_5 ( V_9 , V_216 ,
F_32 ( struct V_214 ) ) ;
if ( ! V_12 )
goto V_129;
V_215 = & V_12 -> V_19 . V_23 . V_217 ;
V_215 -> V_25 = F_7 ( & V_9 -> V_26 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_129:
F_8 ( & V_143 -> V_218 -> V_219 , V_17 ) ;
V_145 -> V_220 = true ;
F_10 ( & V_143 -> V_218 -> V_219 , V_17 ) ;
V_18 ( V_145 -> V_221 ,
F_43 ( & V_145 -> V_222 ) == 0 ) ;
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_44 ( struct V_1 * V_9 )
{
int V_62 ;
if ( V_9 -> V_6 != V_211 )
return 0 ;
V_62 = F_40 ( V_9 ,
V_223 |
V_224 |
V_225 ) ;
if ( V_62 == 0 )
V_9 -> V_6 = V_226 ;
return V_62 ;
}
static int F_45 ( struct V_1 * V_9 )
{
int V_62 ;
if ( V_9 -> V_6 != V_226 )
return 0 ;
V_62 = F_40 ( V_9 , 0 ) ;
if ( V_62 == - V_119 )
V_62 = 0 ;
if ( V_62 == 0 )
V_9 -> V_6 = V_211 ;
return V_62 ;
}
static void F_46 ( struct V_227 * V_228 )
{
struct V_33 * V_229 ;
T_4 V_230 = V_228 -> V_231 . V_232 . V_233 ;
int V_62 ;
unsigned long V_17 ;
V_229 = F_15 ( V_228 -> V_234 -> V_235 ) ;
F_8 ( & V_229 -> V_236 , V_17 ) ;
V_229 -> V_237 -- ;
F_10 ( & V_229 -> V_236 , V_17 ) ;
if ( V_229 -> V_237 == 0 )
F_24 ( & V_229 -> V_238 ) ;
if ( V_230 >= V_229 -> V_239 )
return;
F_47 ( V_228 , V_229 -> V_240 + ( V_230 - 1 ) *
V_241 ) ;
V_62 = F_48 ( V_228 , V_229 -> V_242 * V_74 ,
V_229 -> V_242 * V_74 , NULL , 0 ,
V_243 , V_228 ) ;
if ( V_62 == 0 )
V_229 -> V_244 [ V_230 ] = V_228 ;
}
int F_49 ( struct V_29 * V_9 ,
void * V_245 )
{
int V_62 ;
struct V_33 * V_31 ;
struct V_1 * V_1 ;
struct V_246 * V_247 = V_245 ;
struct V_165 V_248 ;
struct V_249 * V_250 ;
unsigned long V_127 ;
struct V_132 V_251 ;
T_1 V_252 = sizeof( struct V_132 ) ;
T_1 V_253 , V_101 ;
T_1 V_254 ;
T_1 V_255 ;
const struct V_256 * V_257 ;
T_1 V_258 ;
unsigned long V_17 ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_119 ;
V_62 = F_50 ( V_9 , V_245 ) ;
if ( V_62 != 0 ) {
F_13 ( V_1 ) ;
return V_62 ;
}
V_31 = F_15 ( V_9 ) ;
V_31 -> V_259 = 1 ;
V_31 -> V_239 = 1 ;
F_3 ( & V_31 -> V_236 ) ;
V_31 -> V_118 = V_1 ;
V_1 -> V_77 = V_31 ;
V_62 = F_41 ( V_1 ) ;
if ( V_62 != 0 ) {
F_51 ( V_9 ) ;
return V_62 ;
}
V_101 = sizeof( T_1 ) ;
V_62 = F_31 ( V_1 ,
V_260 ,
& V_253 , & V_101 ) ;
if ( V_62 == 0 && V_101 == sizeof( T_1 ) && V_253 < V_31 -> V_34 -> V_253 )
V_31 -> V_34 -> V_253 = V_253 ;
V_62 = F_34 ( V_1 ) ;
if ( V_62 != 0 ) {
F_51 ( V_9 ) ;
return V_62 ;
}
memcpy ( V_247 -> V_261 , V_1 -> V_142 , V_140 ) ;
memset ( & V_248 , 0 , sizeof( struct V_165 ) ) ;
V_248 . V_262 = V_263 ;
V_248 . V_264 = V_263 ;
V_248 . V_172 = V_263 ;
V_248 . V_265 = V_263 ;
V_248 . V_173 = V_263 ;
V_248 . V_266 = V_267 ;
V_62 = F_37 ( V_9 , & V_248 ) ;
if ( V_62 )
goto V_268;
F_39 ( V_1 ) ;
V_247 -> V_83 = V_1 -> V_83 ;
F_52 ( & V_9 -> V_2 , L_34 ,
V_1 -> V_142 ,
V_247 -> V_83 ? L_35 : L_36 ) ;
if ( V_31 -> V_169 < V_269 )
return 0 ;
memset ( & V_251 , 0 , V_252 ) ;
V_62 = F_31 ( V_1 ,
V_131 ,
& V_251 , & V_252 ) ;
if ( V_62 || V_251 . V_270 < 2 )
goto V_271;
V_254 = F_53 ( V_247 -> V_272 , V_251 . V_270 ) ;
V_31 -> V_259 = V_251 . V_270 ;
V_257 = F_54 ( F_55 ( V_9 -> V_218 -> V_273 ) ) ;
V_258 = F_56 ( V_257 ) ;
if ( V_247 -> V_239 && V_247 -> V_239 < V_31 -> V_259 )
V_31 -> V_239 = V_247 -> V_239 ;
else
V_31 -> V_239 = F_53 ( V_258 , V_254 ) ;
V_254 = V_31 -> V_239 - 1 ;
V_31 -> V_237 = V_254 ;
if ( V_31 -> V_239 == 1 )
goto V_271;
V_31 -> V_240 = F_57 ( ( V_31 -> V_239 - 1 ) *
V_241 ) ;
if ( ! V_31 -> V_240 ) {
V_31 -> V_239 = 1 ;
F_52 ( & V_9 -> V_2 , L_37 ) ;
goto V_271;
}
F_58 ( V_9 -> V_218 , F_46 ) ;
V_250 = & V_31 -> V_274 ;
memset ( V_250 , 0 , sizeof( struct V_249 ) ) ;
V_250 -> V_134 . V_10 = V_275 ;
V_250 -> V_23 . V_276 . V_277 . V_278 = V_279 ;
V_250 -> V_23 . V_276 . V_277 . V_280 =
V_31 -> V_239 - 1 ;
V_62 = F_59 ( V_9 -> V_218 , V_250 ,
sizeof( struct V_249 ) ,
( unsigned long ) V_250 ,
V_281 ,
V_282 ) ;
if ( V_62 )
goto V_271;
V_127 = F_33 ( & V_31 -> V_238 , 5 * V_138 ) ;
if ( V_127 == 0 ) {
V_62 = - V_139 ;
goto V_271;
}
if ( V_250 -> V_23 . V_276 . V_283 . V_45 !=
V_284 ) {
V_62 = - V_119 ;
goto V_271;
}
V_31 -> V_239 = 1 +
V_250 -> V_23 . V_276 . V_283 . V_280 ;
V_62 = F_38 ( V_1 , V_31 -> V_239 ) ;
F_8 ( & V_31 -> V_236 , V_17 ) ;
V_255 = V_254 - ( V_31 -> V_239 - 1 ) ;
V_31 -> V_237 -= V_255 ;
F_10 ( & V_31 -> V_236 , V_17 ) ;
while ( V_31 -> V_237 != 0 ) {
V_127 = F_33 ( & V_31 -> V_238 , 10 * V_138 ) ;
if ( V_127 == 0 )
F_60 ( 1 , L_38 ) ;
}
V_271:
if ( V_62 ) {
V_31 -> V_259 = 1 ;
V_31 -> V_239 = 1 ;
}
return 0 ;
V_268:
F_51 ( V_9 ) ;
return V_62 ;
}
void F_51 ( struct V_29 * V_9 )
{
struct V_33 * V_77 = F_15 ( V_9 ) ;
struct V_1 * V_116 = V_77 -> V_118 ;
F_42 ( V_116 ) ;
F_13 ( V_116 ) ;
V_77 -> V_118 = NULL ;
F_61 ( V_9 ) ;
}
int F_62 ( struct V_29 * V_9 )
{
struct V_33 * V_31 = F_15 ( V_9 ) ;
if ( ! V_31 )
return - V_117 ;
return F_44 ( V_31 -> V_118 ) ;
}
int F_63 ( struct V_29 * V_9 )
{
struct V_33 * V_145 = F_15 ( V_9 ) ;
if ( ! V_145 )
return - V_117 ;
return F_45 ( V_145 -> V_118 ) ;
}
