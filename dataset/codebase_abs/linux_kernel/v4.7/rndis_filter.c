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
unsigned long V_128 ;
if ( ! V_123 )
return - V_129 ;
* V_124 = 0 ;
V_12 = F_5 ( V_9 , V_87 ,
F_33 ( struct V_126 ) ) ;
if ( ! V_12 ) {
V_60 = - V_130 ;
goto V_131;
}
V_127 = & V_12 -> V_19 . V_23 . V_88 ;
V_127 -> V_89 = V_89 ;
V_127 -> V_53 = sizeof( struct V_126 ) ;
V_127 -> V_52 = 0 ;
V_127 -> V_132 = 0 ;
if ( V_89 == V_133 ) {
struct V_134 * V_135 ;
V_12 -> V_19 . V_11 +=
sizeof( struct V_134 ) ;
V_127 -> V_52 = sizeof( struct V_134 ) ;
V_135 = (struct V_134 * ) ( ( unsigned long ) V_127 +
V_127 -> V_53 ) ;
V_135 -> V_136 . type = V_137 ;
V_135 -> V_136 . V_138 = V_139 ;
V_135 -> V_136 . V_100 = sizeof( struct V_134 ) ;
}
V_60 = F_17 ( V_9 , V_12 ) ;
if ( V_60 != 0 )
goto V_131;
V_128 = F_34 ( & V_12 -> V_18 , 5 * V_140 ) ;
if ( V_128 == 0 ) {
V_60 = - V_141 ;
goto V_131;
}
V_51 = & V_12 -> V_80 . V_23 . V_51 ;
if ( V_51 -> V_52 > V_125 ) {
V_60 = - 1 ;
goto V_131;
}
memcpy ( V_123 ,
( void * ) ( ( unsigned long ) V_51 +
V_51 -> V_53 ) ,
V_51 -> V_52 ) ;
* V_124 = V_51 -> V_52 ;
V_131:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_60 ;
}
static int F_35 ( struct V_1 * V_9 )
{
T_1 V_100 = V_142 ;
return F_32 ( V_9 ,
V_143 ,
V_9 -> V_144 , & V_100 ) ;
}
int F_36 ( struct V_29 * V_145 , char * V_146 )
{
struct V_31 * V_68 = F_15 ( V_145 ) ;
struct V_66 * V_67 = F_18 ( V_68 ) ;
struct V_118 * V_120 = V_67 -> V_120 ;
struct V_1 * V_77 = V_120 -> V_122 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_147 * V_148 ;
T_3 * V_149 , * V_150 ;
struct V_151 * V_55 ;
char V_152 [ 2 * V_142 + 1 ] ;
T_1 V_153 = sizeof( struct V_147 ) +
2 * V_154 + 4 * V_142 ;
int V_60 ;
unsigned long V_128 ;
V_12 = F_5 ( V_77 , V_155 ,
F_33 ( struct V_15 ) + V_153 ) ;
if ( ! V_12 )
return - V_130 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_156 ;
V_16 -> V_52 = V_153 ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
V_16 -> V_132 = 0 ;
V_148 = (struct V_147 * ) ( ( V_98 ) V_16 +
V_16 -> V_53 ) ;
V_148 -> V_157 =
sizeof( struct V_147 ) ;
V_148 -> V_158 = 2 * V_154 ;
V_148 -> V_159 = V_160 ;
V_148 -> V_161 =
V_148 -> V_157 + V_148 -> V_158 ;
V_148 -> V_162 = 4 * V_142 ;
V_149 = ( T_3 * ) ( ( V_98 ) V_148 + V_148 -> V_157 ) ;
V_150 = ( T_3 * ) ( ( V_98 ) V_148 + V_148 -> V_161 ) ;
V_60 = F_37 ( V_163 , V_154 , V_164 ,
V_149 , V_154 ) ;
if ( V_60 < 0 )
goto V_131;
snprintf ( V_152 , 2 * V_142 + 1 , L_28 , V_146 ) ;
V_60 = F_37 ( V_152 , 2 * V_142 , V_164 ,
V_150 , 2 * V_142 ) ;
if ( V_60 < 0 )
goto V_131;
V_60 = F_17 ( V_77 , V_12 ) ;
if ( V_60 != 0 )
goto V_131;
V_128 = F_34 ( & V_12 -> V_18 , 5 * V_140 ) ;
if ( V_128 == 0 ) {
F_24 ( V_68 , L_29 ) ;
return - V_165 ;
} else {
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
if ( V_55 -> V_43 != V_81 ) {
F_24 ( V_68 , L_30 ,
V_55 -> V_43 ) ;
V_60 = - V_129 ;
}
}
V_131:
F_11 ( V_77 , V_12 ) ;
return V_60 ;
}
static int
F_38 ( struct V_29 * V_145 ,
struct V_166 * V_167 )
{
struct V_31 * V_68 = F_15 ( V_145 ) ;
struct V_66 * V_67 = F_18 ( V_68 ) ;
struct V_118 * V_120 = V_67 -> V_120 ;
struct V_1 * V_77 = V_120 -> V_122 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_166 * V_168 ;
struct V_151 * V_55 ;
T_1 V_153 = sizeof( struct V_166 ) ;
int V_60 ;
unsigned long V_128 ;
T_1 V_169 = V_120 -> V_170 ;
if ( V_169 <= V_171 ) {
V_153 = V_172 ;
V_167 -> V_173 = 0 ;
V_167 -> V_174 = 0 ;
}
V_12 = F_5 ( V_77 , V_155 ,
F_33 ( struct V_15 ) + V_153 ) ;
if ( ! V_12 )
return - V_130 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_175 ;
V_16 -> V_52 = V_153 ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
V_16 -> V_132 = 0 ;
V_168 = (struct V_166 * ) ( ( V_98 ) V_16 +
V_16 -> V_53 ) ;
* V_168 = * V_167 ;
V_168 -> V_176 . type = V_177 ;
V_168 -> V_176 . V_178 = V_179 ;
V_168 -> V_176 . V_100 = V_153 ;
V_60 = F_17 ( V_77 , V_12 ) ;
if ( V_60 != 0 )
goto V_131;
V_128 = F_34 ( & V_12 -> V_18 , 5 * V_140 ) ;
if ( V_128 == 0 ) {
F_24 ( V_68 , L_31 ) ;
return - V_165 ;
} else {
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
if ( V_55 -> V_43 != V_81 ) {
F_24 ( V_68 , L_32 ,
V_55 -> V_43 ) ;
V_60 = - V_129 ;
}
}
V_131:
F_11 ( V_77 , V_12 ) ;
return V_60 ;
}
static int F_39 ( struct V_1 * V_77 , int V_180 )
{
struct V_31 * V_68 = V_77 -> V_68 ;
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_151 * V_55 ;
T_1 V_153 = sizeof( struct V_181 ) +
4 * V_182 + V_183 ;
struct V_181 * V_184 ;
T_1 * V_185 ;
T_4 * V_186 ;
int V_187 , V_60 ;
unsigned long V_128 ;
V_12 = F_5 (
V_77 , V_155 ,
F_33 ( struct V_15 ) + V_153 ) ;
if ( ! V_12 )
return - V_130 ;
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_188 ;
V_16 -> V_52 = V_153 ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
V_16 -> V_132 = 0 ;
V_184 = (struct V_181 * ) ( V_16 + 1 ) ;
V_184 -> V_136 . type = V_189 ;
V_184 -> V_136 . V_138 = V_190 ;
V_184 -> V_136 . V_100 = sizeof( struct V_181 ) ;
V_184 -> V_191 = 0 ;
V_184 -> V_192 = V_193 | V_194 |
V_195 | V_196 |
V_197 ;
V_184 -> V_198 = 4 * V_182 ;
V_184 -> V_199 = sizeof( struct V_181 ) ;
V_184 -> V_200 = V_183 ;
V_184 -> V_201 = V_184 -> V_199 +
V_184 -> V_198 ;
V_185 = ( T_1 * ) ( V_184 + 1 ) ;
for ( V_187 = 0 ; V_187 < V_182 ; V_187 ++ )
V_185 [ V_187 ] = V_187 % V_180 ;
V_186 = ( T_4 * ) ( ( unsigned long ) V_184 + V_184 -> V_201 ) ;
for ( V_187 = 0 ; V_187 < V_183 ; V_187 ++ )
V_186 [ V_187 ] = V_202 [ V_187 ] ;
V_60 = F_17 ( V_77 , V_12 ) ;
if ( V_60 != 0 )
goto V_131;
V_128 = F_34 ( & V_12 -> V_18 , 5 * V_140 ) ;
if ( V_128 == 0 ) {
F_24 ( V_68 , L_29 ) ;
return - V_141 ;
} else {
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
if ( V_55 -> V_43 != V_81 ) {
F_24 ( V_68 , L_33 ,
V_55 -> V_43 ) ;
V_60 = - V_129 ;
}
}
V_131:
F_11 ( V_77 , V_12 ) ;
return V_60 ;
}
static int F_40 ( struct V_1 * V_9 )
{
T_1 V_100 = sizeof( T_1 ) ;
T_1 V_78 ;
int V_60 ;
V_60 = F_32 ( V_9 ,
V_90 ,
& V_78 , & V_100 ) ;
return V_60 ;
}
int F_41 ( struct V_1 * V_9 , T_1 V_203 )
{
struct V_8 * V_12 ;
struct V_15 * V_16 ;
struct V_151 * V_55 ;
T_1 V_43 ;
int V_60 ;
unsigned long V_128 ;
struct V_31 * V_68 = V_9 -> V_68 ;
V_12 = F_5 ( V_9 , V_155 ,
F_33 ( struct V_15 ) +
sizeof( T_1 ) ) ;
if ( ! V_12 ) {
V_60 = - V_130 ;
goto V_131;
}
V_16 = & V_12 -> V_19 . V_23 . V_24 ;
V_16 -> V_89 = V_204 ;
V_16 -> V_52 = sizeof( T_1 ) ;
V_16 -> V_53 = sizeof( struct V_15 ) ;
memcpy ( ( void * ) ( unsigned long ) V_16 + sizeof( struct V_15 ) ,
& V_203 , sizeof( T_1 ) ) ;
V_60 = F_17 ( V_9 , V_12 ) ;
if ( V_60 != 0 )
goto V_131;
V_128 = F_34 ( & V_12 -> V_18 , 5 * V_140 ) ;
if ( V_128 == 0 ) {
F_24 ( V_68 ,
L_29 ) ;
V_60 = - V_141 ;
goto exit;
} else {
V_55 = & V_12 -> V_80 . V_23 . V_55 ;
V_43 = V_55 -> V_43 ;
}
V_131:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
exit:
return V_60 ;
}
static int F_42 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_205 * V_206 ;
struct V_207 * V_42 ;
T_1 V_43 ;
int V_60 ;
unsigned long V_128 ;
struct V_66 * V_67 = F_18 ( V_9 -> V_68 ) ;
struct V_118 * V_120 = V_67 -> V_120 ;
V_12 = F_5 ( V_9 , V_208 ,
F_33 ( struct V_205 ) ) ;
if ( ! V_12 ) {
V_60 = - V_130 ;
goto V_131;
}
V_206 = & V_12 -> V_19 . V_23 . V_85 ;
V_206 -> V_44 = V_209 ;
V_206 -> V_45 = V_210 ;
V_206 -> V_47 = 0x4000 ;
V_9 -> V_6 = V_211 ;
V_60 = F_17 ( V_9 , V_12 ) ;
if ( V_60 != 0 ) {
V_9 -> V_6 = V_7 ;
goto V_131;
}
V_128 = F_34 ( & V_12 -> V_18 , 5 * V_140 ) ;
if ( V_128 == 0 ) {
V_60 = - V_141 ;
goto V_131;
}
V_42 = & V_12 -> V_80 . V_23 . V_42 ;
V_43 = V_42 -> V_43 ;
if ( V_43 == V_81 ) {
V_9 -> V_6 = V_212 ;
V_120 -> V_213 = V_42 -> V_48 ;
V_120 -> V_214 = 1 << V_42 -> V_49 ;
V_60 = 0 ;
} else {
V_9 -> V_6 = V_7 ;
V_60 = - V_129 ;
}
V_131:
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return V_60 ;
}
static void F_43 ( struct V_1 * V_9 )
{
struct V_8 * V_12 ;
struct V_215 * V_216 ;
struct V_66 * V_67 = F_18 ( V_9 -> V_68 ) ;
struct V_118 * V_120 = V_67 -> V_120 ;
struct V_29 * V_145 = V_67 -> V_76 ;
V_98 V_17 ;
V_12 = F_5 ( V_9 , V_217 ,
F_33 ( struct V_215 ) ) ;
if ( ! V_12 )
goto V_131;
V_216 = & V_12 -> V_19 . V_23 . V_218 ;
V_216 -> V_25 = F_7 ( & V_9 -> V_26 ) ;
F_17 ( V_9 , V_12 ) ;
V_9 -> V_6 = V_7 ;
V_131:
F_8 ( & V_145 -> V_103 -> V_219 , V_17 ) ;
V_120 -> V_220 = true ;
F_10 ( & V_145 -> V_103 -> V_219 , V_17 ) ;
V_18 ( V_120 -> V_221 ,
F_44 ( & V_120 -> V_222 ) == 0 ) ;
if ( V_12 )
F_11 ( V_9 , V_12 ) ;
return;
}
static int F_45 ( struct V_1 * V_9 )
{
int V_60 ;
if ( V_9 -> V_6 != V_212 )
return 0 ;
V_60 = F_41 ( V_9 ,
V_223 |
V_224 |
V_225 ) ;
if ( V_60 == 0 )
V_9 -> V_6 = V_226 ;
return V_60 ;
}
static int F_46 ( struct V_1 * V_9 )
{
int V_60 ;
if ( V_9 -> V_6 != V_226 )
return 0 ;
V_60 = F_41 ( V_9 , 0 ) ;
if ( V_60 == - V_227 )
V_60 = 0 ;
if ( V_60 == 0 )
V_9 -> V_6 = V_212 ;
return V_60 ;
}
static void F_47 ( struct V_102 * V_228 )
{
struct V_31 * V_68 =
F_15 ( V_228 -> V_229 -> V_230 ) ;
struct V_66 * V_67 = F_18 ( V_68 ) ;
struct V_118 * V_231 = V_67 -> V_120 ;
T_2 V_232 = V_228 -> V_233 . V_234 . V_235 ;
int V_60 ;
unsigned long V_17 ;
if ( V_232 >= V_231 -> V_236 )
return;
F_48 ( V_228 , V_231 -> V_237 + ( V_232 - 1 ) *
V_238 ) ;
V_60 = F_49 ( V_228 , V_231 -> V_239 * V_75 ,
V_231 -> V_239 * V_75 , NULL , 0 ,
V_240 , V_228 ) ;
if ( V_60 == 0 )
V_231 -> V_241 [ V_232 ] = V_228 ;
F_8 ( & V_231 -> V_242 , V_17 ) ;
V_231 -> V_243 -- ;
F_10 ( & V_231 -> V_242 , V_17 ) ;
if ( V_231 -> V_243 == 0 )
F_25 ( & V_231 -> V_244 ) ;
}
int F_50 ( struct V_29 * V_9 ,
void * V_245 )
{
int V_60 ;
struct V_31 * V_246 = F_15 ( V_9 ) ;
struct V_66 * V_67 = F_18 ( V_246 ) ;
struct V_118 * V_31 ;
struct V_1 * V_1 ;
struct V_247 * V_248 = V_245 ;
struct V_166 V_249 ;
struct V_250 * V_251 ;
unsigned long V_128 ;
struct V_134 V_252 ;
T_1 V_253 = sizeof( struct V_134 ) ;
T_1 V_254 , V_100 ;
T_1 V_255 ;
T_1 V_256 ;
const struct V_257 * V_258 ;
T_1 V_259 ;
unsigned long V_17 ;
V_1 = F_1 () ;
if ( ! V_1 )
return - V_227 ;
V_60 = F_51 ( V_9 , V_245 ) ;
if ( V_60 != 0 ) {
F_13 ( V_1 ) ;
return V_60 ;
}
V_31 = V_67 -> V_120 ;
V_31 -> V_260 = 1 ;
V_31 -> V_236 = 1 ;
F_3 ( & V_31 -> V_242 ) ;
V_31 -> V_122 = V_1 ;
V_1 -> V_68 = V_246 ;
V_60 = F_42 ( V_1 ) ;
if ( V_60 != 0 ) {
F_52 ( V_9 ) ;
return V_60 ;
}
V_100 = sizeof( T_1 ) ;
V_60 = F_32 ( V_1 ,
V_261 ,
& V_254 , & V_100 ) ;
if ( V_60 == 0 && V_100 == sizeof( T_1 ) && V_254 < V_246 -> V_254 )
V_246 -> V_254 = V_254 ;
V_60 = F_35 ( V_1 ) ;
if ( V_60 != 0 ) {
F_52 ( V_9 ) ;
return V_60 ;
}
memcpy ( V_248 -> V_262 , V_1 -> V_144 , V_142 ) ;
memset ( & V_249 , 0 , sizeof( struct V_166 ) ) ;
V_249 . V_263 = V_264 ;
V_249 . V_265 = V_264 ;
V_249 . V_173 = V_264 ;
V_249 . V_266 = V_264 ;
V_249 . V_174 = V_264 ;
V_249 . V_267 = V_268 ;
V_60 = F_38 ( V_9 , & V_249 ) ;
if ( V_60 )
goto V_269;
F_40 ( V_1 ) ;
V_248 -> V_82 = V_1 -> V_82 ;
F_53 ( & V_9 -> V_2 , L_34 ,
V_1 -> V_144 ,
V_248 -> V_82 ? L_35 : L_36 ) ;
if ( V_31 -> V_170 < V_270 )
return 0 ;
memset ( & V_252 , 0 , V_253 ) ;
V_60 = F_32 ( V_1 ,
V_133 ,
& V_252 , & V_253 ) ;
if ( V_60 || V_252 . V_271 < 2 )
goto V_272;
V_31 -> V_260 = F_54 ( T_1 , V_273 , V_252 . V_271 ) ;
V_255 = F_55 ( V_248 -> V_274 , V_31 -> V_260 ) ;
V_258 = F_56 ( F_57 ( V_9 -> V_103 -> V_275 ) ) ;
V_259 = F_58 ( V_258 ) ;
if ( V_248 -> V_236 && V_248 -> V_236 < V_31 -> V_260 )
V_31 -> V_236 = V_248 -> V_236 ;
else
V_31 -> V_236 = F_55 ( V_259 , V_255 ) ;
V_255 = V_31 -> V_236 - 1 ;
V_31 -> V_243 = V_255 ;
if ( V_31 -> V_236 == 1 )
goto V_272;
V_31 -> V_237 = F_59 ( ( V_31 -> V_236 - 1 ) *
V_238 ) ;
if ( ! V_31 -> V_237 ) {
V_31 -> V_236 = 1 ;
F_53 ( & V_9 -> V_2 , L_37 ) ;
goto V_272;
}
F_60 ( V_9 -> V_103 , F_47 ) ;
V_251 = & V_31 -> V_276 ;
memset ( V_251 , 0 , sizeof( struct V_250 ) ) ;
V_251 -> V_136 . V_10 = V_277 ;
V_251 -> V_23 . V_278 . V_279 . V_280 = V_281 ;
V_251 -> V_23 . V_278 . V_279 . V_282 =
V_31 -> V_236 - 1 ;
V_60 = F_61 ( V_9 -> V_103 , V_251 ,
sizeof( struct V_250 ) ,
( unsigned long ) V_251 ,
V_283 ,
V_284 ) ;
if ( V_60 )
goto V_272;
V_128 = F_34 ( & V_31 -> V_244 , 5 * V_140 ) ;
if ( V_128 == 0 ) {
V_60 = - V_141 ;
goto V_272;
}
if ( V_251 -> V_23 . V_278 . V_285 . V_43 !=
V_286 ) {
V_60 = - V_227 ;
goto V_272;
}
V_31 -> V_236 = 1 +
V_251 -> V_23 . V_278 . V_285 . V_282 ;
V_60 = F_39 ( V_1 , V_31 -> V_236 ) ;
F_8 ( & V_31 -> V_242 , V_17 ) ;
V_256 = V_255 - ( V_31 -> V_236 - 1 ) ;
V_31 -> V_243 -= V_256 ;
F_10 ( & V_31 -> V_242 , V_17 ) ;
V_272:
if ( V_60 ) {
V_31 -> V_260 = 1 ;
V_31 -> V_236 = 1 ;
V_31 -> V_243 = 0 ;
}
return 0 ;
V_269:
F_52 ( V_9 ) ;
return V_60 ;
}
void F_52 ( struct V_29 * V_9 )
{
struct V_31 * V_68 = F_15 ( V_9 ) ;
struct V_66 * V_67 = F_18 ( V_68 ) ;
struct V_118 * V_119 = V_67 -> V_120 ;
struct V_1 * V_121 = V_119 -> V_122 ;
unsigned long V_128 ;
while ( V_119 -> V_243 > 0 ) {
V_128 = F_34 ( & V_119 -> V_244 ,
10 * V_140 ) ;
if ( V_128 == 0 )
F_62 ( 1 , L_38 ) ;
}
F_43 ( V_121 ) ;
F_13 ( V_121 ) ;
V_119 -> V_122 = NULL ;
F_63 ( V_9 ) ;
}
int F_64 ( struct V_29 * V_9 )
{
struct V_31 * V_68 = F_15 ( V_9 ) ;
struct V_66 * V_67 = F_18 ( V_68 ) ;
struct V_118 * V_31 = V_67 -> V_120 ;
if ( ! V_31 )
return - V_129 ;
if ( F_7 ( & V_31 -> V_287 ) != 1 )
return 0 ;
return F_45 ( V_31 -> V_122 ) ;
}
int F_65 ( struct V_29 * V_9 )
{
struct V_31 * V_68 = F_15 ( V_9 ) ;
struct V_66 * V_67 = F_18 ( V_68 ) ;
struct V_118 * V_120 = V_67 -> V_120 ;
if ( ! V_120 )
return - V_129 ;
if ( F_66 ( & V_120 -> V_287 ) != 0 )
return 0 ;
return F_46 ( V_120 -> V_122 ) ;
}
