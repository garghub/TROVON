static inline bool F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
return ! memcmp ( V_2 , V_3 , sizeof( struct V_1 ) ) ;
}
int F_2 ( struct V_4 * V_5 , void * V_6 ,
const struct V_7 * V_8 ,
struct V_9 * * V_10 ,
bool * V_11 )
{
struct V_9 * V_12 = NULL ;
int V_13 = 0 ;
* V_10 = NULL ;
V_12 = F_3 ( sizeof( struct V_9 ) , V_14 ) ;
if ( V_12 == NULL ) {
V_13 = - V_15 ;
} else {
V_12 -> V_16 = V_11 ;
V_12 -> V_17 = 0 ;
V_12 -> V_5 = V_5 ;
V_12 -> V_6 = V_6 ;
V_12 -> V_18 = V_8 -> V_19 . V_20 ;
if ( V_8 -> V_21 == V_22 ) {
V_12 -> V_23 = true ;
V_12 -> V_24 [ V_25 ] = ( V_26 )
( V_8 -> V_27 >> V_28 ) &
V_29 ;
V_12 -> V_30 |=
( ( V_8 -> V_27 >>
( V_28 + V_31 ) ) & 1 ) << V_25 ;
V_12 -> V_24 [ V_32 ] = ( V_26 )
( V_8 -> V_33 >>
V_28 ) & V_29 ;
V_12 -> V_30 |=
( ( V_8 -> V_33 >>
( V_28 + V_31 ) ) & 1 ) << V_32 ;
V_12 -> V_24 [ V_34 ] = ( V_26 )
( V_8 -> V_27 >>
V_35 ) & V_29 ;
V_12 -> V_30 |=
( ( V_8 -> V_27 >>
( V_35 + V_31 ) ) & 1 ) <<
V_34 ;
V_12 -> V_24 [ V_36 ] = ( V_26 )
( V_8 -> V_33 >>
V_35 ) & V_29 ;
V_12 -> V_30 |=
( ( V_8 -> V_33 >>
( V_35 + V_31 ) ) & 1 ) <<
V_36 ;
V_12 -> V_24 [ V_37 ] = ( V_26 )
( V_8 -> V_27 >> V_38 ) &
V_29 ;
V_12 -> V_30 |=
( ( V_8 -> V_27 >>
( V_38 + V_31 ) ) & 1 ) << V_37 ;
V_12 -> V_24 [ V_39 ] = ( V_26 )
( V_8 -> V_33 >>
V_38 ) & V_29 ;
V_12 -> V_30 |=
( ( V_8 -> V_33 >>
( V_38 + V_31 ) ) & 1 ) << V_39 ;
} else {
V_12 -> V_40 . V_41 = V_5 -> V_42 ;
if ( V_8 -> V_21 == V_43 )
V_12 -> V_44 = true ;
}
* V_10 = (struct V_9 * ) V_12 ;
}
if ( V_13 && V_12 )
F_4 ( V_12 ) ;
return V_13 ;
}
int F_5 ( struct V_4 * * V_45 ,
struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
struct V_50 * V_51 ;
char * V_52 = NULL ;
char V_53 [ V_54 ] ;
struct V_4 * V_5 = NULL ;
struct V_55 V_56 ;
struct V_55 V_57 ;
T_1 V_58 ;
T_2 V_59 ;
V_26 V_60 = 0 ;
struct V_61 * V_62 ;
T_2 V_63 = 0 ;
T_2 V_64 ;
struct V_65 * V_66 = NULL ;
V_26 V_67 ;
int V_13 = 0 ;
V_5 = F_3 ( sizeof( struct V_4 ) , V_14 ) ;
if ( V_5 ) {
V_5 -> V_68 = V_47 ;
F_6 ( V_47 , & V_51 ) ;
if ( V_51 ) {
V_13 = F_7 ( V_51 , & V_5 -> V_69 ) ;
V_13 = F_8 ( V_51 , & V_5 -> V_42 ) ;
V_13 =
F_9 ( V_51 , V_53 ,
V_54 ) ;
}
V_13 = 0 ;
V_5 -> V_70 = V_49 -> V_70 ;
V_5 -> V_71 = V_49 -> V_71 ;
V_5 -> V_72 = V_72 ;
if ( ! ( V_5 -> V_72 . V_73 () ) )
V_13 = - V_15 ;
} else {
V_13 = - V_15 ;
}
if ( ! V_13 )
V_13 = F_10 ( NULL , & V_5 -> V_74 ) ;
if ( ! V_13 ) {
V_13 =
V_5 -> V_72 . V_75 ( V_5 -> V_42 ,
V_76 , & V_64 ,
& V_63 ) ;
if ( ! V_13 ) {
V_52 =
F_3 ( V_63 * V_5 -> V_70 ,
V_14 ) ;
if ( ! V_52 )
V_13 = - V_15 ;
} else {
V_13 = 0 ;
V_63 = 0 ;
F_11 ( V_77 , L_1
L_2 , V_78 , V_13 ) ;
}
}
if ( ! V_13 && V_63 > 0 ) {
V_13 =
V_5 -> V_72 . V_79 ( V_5 -> V_42 ,
V_76 , V_52 ,
V_63 ) ;
}
if ( ! V_13 && V_63 > 0 ) {
V_60 = ( V_26 ) ( * ( ( T_2 * ) V_52 ) ) ;
if ( V_60 > V_80 )
V_13 = - V_81 ;
}
if ( ! V_13 && V_60 > 0 ) {
V_66 = F_3 ( sizeof( struct V_65 ) * V_60 ,
V_14 ) ;
V_5 -> V_82 =
F_3 ( sizeof( T_2 ) * V_60 , V_14 ) ;
if ( V_66 == NULL || V_5 -> V_82 == NULL ) {
V_13 = - V_15 ;
} else {
V_5 -> V_60 = V_60 ;
V_62 = (struct V_61 * ) ( V_52 +
sizeof( T_2 ) ) ;
for ( V_67 = 0 ; V_67 < V_60 ; V_67 ++ ) {
V_66 [ V_67 ] . V_83 = ( V_62 + V_67 ) -> V_83 ;
V_66 [ V_67 ] . V_84 = ( V_62 + V_67 ) -> V_85 ;
V_66 [ V_67 ] . V_86 = 0 ;
V_5 -> V_82 [ V_67 ] =
( V_62 + V_67 ) -> type ;
F_11 ( V_77 ,
L_3
L_4 , V_67 ,
V_66 [ V_67 ] . V_83 , V_66 [ V_67 ] . V_84 ) ;
}
}
}
if ( ! V_13 )
V_13 = F_12 ( & V_5 -> V_87 , V_66 , V_60 ) ;
if ( ! V_13 ) {
V_5 -> V_72 . V_88 ( V_5 -> V_69 , & V_56 ) ;
V_57 = V_56 ;
V_57 . V_89 = ( V_90 ) V_91 ;
V_57 . free = ( V_92 ) V_93 ;
V_57 . V_94 = ( V_95 ) V_96 ;
V_57 . V_97 = V_5 ;
V_57 . V_98 = ( V_99 ) V_49 -> V_98 ;
V_5 -> V_100 = V_49 -> V_101 ;
V_5 -> V_102 = V_49 -> V_98 ;
V_5 -> V_103 = V_57 ;
}
F_4 ( V_66 ) ;
F_4 ( V_52 ) ;
if ( ! V_13 ) {
V_13 =
F_9 ( V_51 , V_53 , V_54 ) ;
V_13 =
F_13 ( V_5 -> V_74 , V_53 ,
V_104 , ( void * ) V_5 ) ;
if ( ! V_13 && V_5 -> V_105 > 0 ) {
V_5 -> V_106 =
F_3 ( sizeof( struct V_107 ) *
V_5 -> V_105 , V_14 ) ;
V_5 -> V_108 = 0 ;
V_13 = F_13 ( V_5 -> V_74 , V_53 ,
V_104 ,
( void * ) V_5 ) ;
}
}
if ( ! V_13 && V_5 -> V_105 > 0 ) {
V_56 . V_98 = V_109 ;
V_56 . V_110 = V_111 ;
V_56 . V_112 = V_5 ;
V_58 = V_113 | V_114 | V_115 ;
V_13 = V_5 -> V_72 . V_116 ( V_5 -> V_42 , V_58 ,
& V_56 , & V_59 ) ;
}
if ( ! V_13 ) {
* V_45 = (struct V_4 * ) V_5 ;
} else {
if ( V_5 )
F_14 ( (struct V_4 * ) V_5 ) ;
* V_45 = NULL ;
}
return V_13 ;
}
void F_14 ( struct V_4 * V_5 )
{
struct V_117 * V_118 ;
struct V_117 * V_119 ;
V_26 V_67 ;
V_5 -> V_72 . V_120 () ;
if ( V_5 -> V_87 )
F_15 ( V_5 -> V_87 ) ;
F_4 ( V_5 -> V_82 ) ;
if ( V_5 -> V_74 )
F_16 ( V_5 -> V_74 ) ;
if ( V_5 -> V_106 ) {
for ( V_67 = 0 ; V_67 < V_5 -> V_105 ; V_67 ++ ) {
V_118 =
V_5 -> V_106 [ V_67 ] . V_121 ;
while ( V_118 ) {
V_119 = V_118 -> V_122 ;
F_4 ( V_118 ) ;
V_118 = V_119 ;
}
V_118 =
V_5 -> V_106 [ V_67 ] . V_123 ;
while ( V_118 ) {
V_119 = V_118 -> V_122 ;
F_4 ( V_118 ) ;
V_118 = V_119 ;
}
V_118 =
V_5 -> V_106 [ V_67 ] . V_124 ;
while ( V_118 ) {
V_119 = V_118 -> V_122 ;
F_4 ( V_118 ) ;
V_118 = V_119 ;
}
V_118 = V_5 -> V_106 [ V_67 ] . V_125 ;
while ( V_118 ) {
V_119 = V_118 -> V_122 ;
F_4 ( V_118 ) ;
V_118 = V_119 ;
}
}
F_4 ( V_5 -> V_106 ) ;
}
F_4 ( V_5 ) ;
}
int F_17 ( struct V_9 * V_12 ,
char * V_126 , T_2 * V_127 )
{
struct V_128 * V_129 ;
struct V_4 * V_5 ;
int V_13 = 0 ;
bool V_130 = false ;
T_3 V_67 = 0 ;
struct V_131 V_40 = { NULL , 0 , NULL } ;
V_5 = V_12 -> V_5 ;
if ( V_12 -> V_23 && * V_12 -> V_16 ) {
switch ( V_12 -> V_132 ) {
case V_133 :
V_40 = V_12 -> V_134 ;
break;
case V_135 :
V_40 = V_12 -> V_136 ;
break;
case V_137 :
V_40 = V_12 -> V_138 ;
break;
default:
break;
}
} else {
V_40 = V_12 -> V_40 ;
}
V_130 =
V_5 -> V_72 . V_139 ( V_40 . V_41 , V_126 , & V_129 ) ;
if ( ! V_130 )
V_130 =
V_5 -> V_72 . V_140 ( V_40 . V_41 , V_126 ,
& V_129 ) ;
if ( ! V_130 ) {
for ( V_67 = 0 ; V_67 < V_40 . V_141 ; V_67 ++ ) {
V_130 =
V_5 -> V_72 . V_140 ( V_40 . V_142
[ V_67 ] . V_41 , V_126 ,
& V_129 ) ;
if ( ! V_130 ) {
V_130 =
V_5 -> V_72 .
V_139 ( V_40 . V_142 [ V_67 ] . V_41 ,
V_126 , & V_129 ) ;
}
if ( V_130 ) {
break;
}
}
}
if ( ! V_130 ) {
for ( V_67 = 0 ; V_67 < V_12 -> V_17 ; V_67 ++ ) {
V_130 =
V_5 -> V_72 .
V_140 ( V_12 -> V_143 [ V_67 ] . V_41 ,
V_126 , & V_129 ) ;
if ( ! V_130 ) {
V_130 =
V_5 -> V_72 .
V_139 ( V_12 -> V_143
[ V_67 ] . V_41 , V_126 , & V_129 ) ;
}
if ( V_130 ) {
break;
}
}
}
if ( V_130 )
* V_127 = V_129 -> V_144 ;
else
V_13 = - V_145 ;
return V_13 ;
}
int F_18 ( struct V_4 * V_45 ,
struct V_146 * * V_147 )
{
int V_13 = 0 ;
struct V_4 * V_5 = V_45 ;
if ( V_45 ) {
* V_147 = V_5 -> V_87 ;
} else {
* V_147 = NULL ;
V_13 = - V_148 ;
}
return V_13 ;
}
int F_19 ( struct V_9 * V_12 ,
enum V_149 V_132 )
{
struct V_4 * V_5 ;
struct V_1 V_150 ;
int V_13 = 0 ;
V_5 = V_12 -> V_5 ;
if ( V_12 -> V_23 ) {
V_12 -> V_132 = V_132 ;
V_150 = V_12 -> V_18 ;
V_13 =
F_20 ( V_12 , & V_12 -> V_40 , V_150 ,
false , V_12 -> V_151 , V_132 , 0 ) ;
if ( ! V_13 ) {
if ( * V_12 -> V_16 ) {
switch ( V_132 ) {
case V_133 :
V_12 -> V_134 =
V_12 -> V_40 ;
break;
case V_135 :
V_12 -> V_136 =
V_12 -> V_40 ;
break;
case V_137 :
V_12 -> V_138 =
V_12 -> V_40 ;
break;
default:
break;
}
}
}
} else {
if ( V_12 -> V_44 )
V_13 = F_21 ( V_12 , V_132 ) ;
}
return V_13 ;
}
int F_22 ( struct V_9 * V_12 ,
enum V_149 V_132 )
{
int V_13 = 0 ;
struct V_131 * V_152 = NULL ;
T_3 V_67 = 0 ;
if ( V_12 != NULL ) {
if ( V_12 -> V_23 ) {
if ( * V_12 -> V_16 ) {
switch ( V_132 ) {
case V_133 :
V_152 = & V_12 -> V_134 ;
break;
case V_135 :
V_152 = & V_12 -> V_136 ;
break;
case V_137 :
V_152 = & V_12 -> V_138 ;
for ( V_67 = 0 ;
V_67 < V_12 -> V_17 ;
V_67 ++ ) {
F_23 ( V_12 ,
& V_12 ->
V_143 [ V_67 ] ) ;
}
V_12 -> V_17 = 0 ;
break;
default:
break;
}
} else {
V_152 = & V_12 -> V_40 ;
}
if ( V_152 )
F_23 ( V_12 , V_152 ) ;
} else {
if ( V_12 -> V_44 )
F_24 ( V_12 , V_132 ) ;
}
}
return V_13 ;
}
static int V_111 ( void * V_153 , struct V_154 * V_155 ,
T_2 V_127 , T_2 V_156 )
{
char * V_157 ;
char * V_158 = ( char * ) V_155 -> V_159 ;
bool V_160 = false ;
char V_161 = ':' ;
char * V_162 ;
V_26 V_67 ;
struct V_4 * V_5 = (struct V_4 * ) V_153 ;
int V_13 = 0 ;
if ( V_155 -> V_163 == V_155 -> V_164 )
goto V_165;
for ( V_67 = 0 ; V_67 < V_5 -> V_105 ; V_67 ++ ) {
V_157 = V_5 -> V_106 [ V_67 ] . V_157 ;
if ( strncmp ( V_157 , V_158 + 1 , strlen ( V_157 ) ) == 0 ) {
break;
}
}
if ( ! ( V_67 < V_5 -> V_105 ) )
goto V_165;
for ( V_162 = V_158 + 1 ; * V_162 && * V_162 != V_161 ; V_162 ++ )
;
if ( * V_162 ) {
V_162 ++ ;
if ( strncmp ( V_162 , V_166 , strlen ( V_166 ) ) == 0 ) {
V_13 =
F_25 ( V_5 ,
& V_5 ->
V_106 [ V_67 ] . V_121 ,
V_155 , & V_160 , V_127 , V_156 ) ;
if ( ! V_13 && ! V_160 )
V_5 -> V_106 [ V_67 ] . V_167 ++ ;
} else if ( strncmp ( V_162 , V_168 , strlen ( V_168 ) ) == 0 ) {
V_13 =
F_25 ( V_5 ,
& V_5 ->
V_106 [ V_67 ] . V_123 ,
V_155 , & V_160 , V_127 , V_156 ) ;
if ( ! V_13 && ! V_160 )
V_5 -> V_106 [ V_67 ] . V_169 ++ ;
} else if ( strncmp ( V_162 , V_170 , strlen ( V_170 ) ) == 0 ) {
V_13 =
F_25 ( V_5 ,
& V_5 ->
V_106 [ V_67 ] . V_124 ,
V_155 , & V_160 , V_127 , V_156 ) ;
if ( ! V_13 && ! V_160 )
V_5 -> V_106 [ V_67 ] . V_171 ++ ;
} else {
V_13 =
F_25 ( V_5 ,
& V_5 ->
V_106 [ V_67 ] . V_125 ,
V_155 , & V_160 , V_127 , V_156 ) ;
if ( ! V_13 && ! V_160 )
V_5 -> V_106 [ V_67 ] . V_172 ++ ;
}
}
V_165:
return V_13 ;
}
static int V_104 ( struct V_1 * V_173 ,
enum V_174 V_175 , void * V_153 )
{
struct V_4 * V_5 = (struct V_4 * ) V_153 ;
char * V_157 = NULL ;
char * V_176 = NULL ;
T_2 V_85 ;
struct V_177 V_178 ;
int V_13 = 0 ;
if ( V_175 != V_179 )
goto V_165;
V_13 =
F_26 ( V_5 -> V_74 , V_173 , V_175 ,
& V_178 ) ;
if ( V_13 )
goto V_165;
if ( V_178 . V_180 . V_181 . V_21 == V_43 ) {
if ( V_5 -> V_106 == NULL ) {
V_5 -> V_105 ++ ;
} else {
V_5 -> V_106 [ V_5 -> V_108 ] . V_18 =
* V_173 ;
V_85 =
strlen ( V_178 . V_180 . V_181 . V_19 . V_182 ) ;
V_157 = V_178 . V_180 . V_181 . V_19 . V_182 ;
V_176 = F_3 ( V_85 + 1 , V_14 ) ;
if ( V_176 == NULL ) {
V_13 = - V_15 ;
} else {
strncpy ( V_176 , V_157 , V_85 ) ;
V_5 -> V_106 [ V_5 -> V_108 ] .
V_157 = V_176 ;
V_5 -> V_108 ++ ;
}
}
}
F_4 ( V_178 . V_180 . V_181 . V_183 ) ;
F_4 ( V_178 . V_180 . V_181 . V_184 ) ;
F_4 ( V_178 . V_180 . V_181 . V_185 ) ;
F_4 ( V_178 . V_180 . V_181 . V_186 ) ;
V_165:
return V_13 ;
}
static int F_25 ( struct V_4 * V_5 ,
struct V_117 * * V_187 ,
struct V_154 * V_188 ,
bool * V_189 , T_2 V_127 , T_2 V_156 )
{
struct V_117 * V_190 = NULL ;
struct V_117 * V_191 ;
struct V_117 * V_118 ;
int V_13 = 0 ;
V_118 = V_191 = * V_187 ;
* V_189 = false ;
while ( V_118 ) {
if ( V_118 -> V_163 == V_127 ) {
* V_189 = true ;
break;
}
V_191 = V_118 ;
V_118 = V_118 -> V_122 ;
}
if ( ! V_118 ) {
V_190 = F_3 ( sizeof( struct V_117 ) , V_14 ) ;
if ( V_190 == NULL ) {
V_13 = - V_15 ;
} else {
V_190 -> V_163 = V_127 ;
V_190 -> V_164 = V_188 -> V_164 +
( V_127 - V_188 -> V_163 ) ;
V_190 -> V_192 = V_156 ;
V_190 -> V_193 = V_188 -> type ;
}
if ( ! V_13 ) {
if ( * V_187 == NULL ) {
* V_187 = V_190 ;
} else {
V_191 -> V_122 = V_190 ;
}
}
}
return V_13 ;
}
static T_3 V_109 ( void * V_153 , T_2 V_194 , void * V_195 , T_2 V_156 ,
T_3 V_196 )
{
return ( T_3 ) V_156 ;
}
static void F_27 ( struct V_4 * V_5 ,
struct V_117 * V_197 , V_26 V_198 )
{
struct V_117 * V_118 = V_197 ;
V_26 V_67 = 0 ;
bool V_199 ;
while ( V_118 && V_67 < V_198 ) {
V_199 =
F_28 ( V_5 -> V_87 , 0 , V_118 -> V_164 ,
V_118 -> V_192 , true ) ;
V_118 = V_118 -> V_122 ;
V_67 ++ ;
}
}
static bool V_96 ( void * V_153 , void * V_200 , void * V_201 ,
char * V_202 , struct V_128 * * V_203 )
{
struct V_4 * V_5 = (struct V_4 * ) V_153 ;
struct V_9 * V_12 =
(struct V_9 * ) V_201 ;
struct V_131 * V_40 = (struct V_131 * ) V_200 ;
V_26 V_67 ;
bool V_13 = false ;
V_13 = V_5 -> V_72 . V_140 ( V_5 -> V_42 ,
V_202 , V_203 ) ;
if ( ! V_13 )
V_13 =
V_5 -> V_72 . V_139 ( V_5 -> V_42 ,
V_202 , V_203 ) ;
if ( ! V_13 ) {
V_13 = V_5 -> V_72 . V_140 ( V_40 -> V_41 , V_202 ,
V_203 ) ;
if ( ! V_13 ) {
V_13 =
V_5 -> V_72 . V_139 ( V_40 -> V_41 ,
V_202 , V_203 ) ;
}
}
if ( ! V_13 ) {
for ( V_67 = 0 ; V_67 < V_40 -> V_141 ; V_67 ++ ) {
V_13 =
V_5 -> V_72 . V_140 ( V_40 ->
V_142
[ V_67 ] . V_41 ,
V_202 , V_203 ) ;
if ( ! V_13 ) {
V_13 =
V_5 -> V_72 .
V_139 ( V_40 -> V_142 [ V_67 ] . V_41 ,
V_202 , V_203 ) ;
}
if ( V_13 ) {
break;
}
}
}
if ( ! V_13 ) {
for ( V_67 = 0 ; V_67 < V_12 -> V_17 ; V_67 ++ ) {
V_13 =
V_5 -> V_72 .
V_140 ( V_12 -> V_143 [ V_67 ] . V_41 ,
V_202 , V_203 ) ;
if ( ! V_13 ) {
V_13 = V_5 -> V_72 . V_139
( V_12 -> V_143 [ V_67 ] . V_41 ,
V_202 , V_203 ) ;
}
if ( V_13 ) {
break;
}
}
}
return V_13 ;
}
static int F_20 ( struct V_9 * V_12 ,
struct V_131 * V_40 , struct V_1 V_18 ,
bool V_204 ,
struct V_205 * * V_151 ,
enum V_149 V_132 , V_26 V_206 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
V_26 V_207 = 0 ;
V_26 V_208 = 0 ;
V_26 V_209 = 0 ;
V_26 V_67 ;
T_2 V_210 ;
T_2 V_211 = V_212 ;
T_1 V_58 = V_115 | V_113 | V_114 | V_213 ;
struct V_55 V_57 ;
char * V_214 = NULL ;
struct V_1 * V_215 = NULL ;
bool * V_216 = NULL ;
int V_13 = 0 ;
bool V_217 = false ;
struct V_131 * V_218 ;
if ( V_206 > V_219 ) {
}
V_40 -> V_41 = NULL ;
V_214 = F_3 ( V_220 , V_14 ) ;
if ( V_214 == NULL )
V_13 = - V_15 ;
if ( ! V_13 ) {
if ( V_206 == 0 ) {
V_13 =
F_29 ( V_12 -> V_5 ->
V_74 , & V_18 , V_214 ,
& V_211 , V_132 ,
V_12 -> V_16 ) ;
} else {
V_13 =
F_29 ( V_12 -> V_5 ->
V_74 , & V_18 , V_214 ,
& V_211 , V_221 ,
NULL ) ;
}
}
if ( ! V_13 ) {
V_13 =
V_5 -> V_72 . V_222 ( V_5 -> V_69 , V_214 ,
V_223 , & V_40 -> V_41 ) ;
}
F_4 ( V_214 ) ;
if ( ! V_13 && V_204 ) {
V_217 =
F_30 ( V_12 , V_40 -> V_41 ) ;
if ( V_217 ) {
V_5 -> V_72 . V_224 ( V_40 -> V_41 ) ;
return 0 ;
}
}
if ( ! V_13 ) {
for ( V_67 = 0 ; V_67 < V_206 ; V_67 ++ ) {
if ( V_40 -> V_41 == V_151 [ V_67 ] ) {
V_13 = - V_225 ;
}
}
}
if ( ! V_13 ) {
V_151 [ V_206 ] = V_40 -> V_41 ;
V_206 ++ ;
V_13 =
F_31 ( V_12 -> V_5 -> V_74 ,
& V_18 , & V_207 , & V_208 , V_132 ) ;
}
if ( ! V_13 ) {
if ( ! ( * V_12 -> V_16 ) )
V_208 = 0 ;
V_40 -> V_141 = V_207 - V_208 ;
if ( V_207 > 0 ) {
V_215 = F_3 ( sizeof( struct V_1 ) *
V_207 , V_14 ) ;
V_216 =
F_3 ( sizeof( bool ) * V_207 , V_14 ) ;
if ( ! V_215 || ! V_216 )
V_13 = - V_15 ;
if ( V_40 -> V_141 > 0 ) {
V_40 -> V_142 = F_3
( sizeof( struct V_131 ) *
( V_40 -> V_141 ) , V_14 ) ;
if ( ! ( V_40 -> V_142 ) )
V_13 = - V_15 ;
}
if ( ! V_13 ) {
V_13 =
F_32 ( V_12 ->
V_5 -> V_74 , & V_18 ,
V_207 , V_215 ,
V_216 ,
V_132 ) ;
}
}
}
if ( ! V_13 ) {
for ( V_67 = 0 ; V_67 < V_207 ; V_67 ++ ) {
if ( ! V_204 && V_216 [ V_67 ] &&
* V_12 -> V_16 ) {
if ( ( V_12 -> V_17 ) >= V_226 ) {
V_13 = - V_225 ;
break;
}
V_218 =
& V_12 -> V_143
[ V_12 -> V_17 ] ;
} else {
if ( V_204 )
V_216 [ V_67 ] = true ;
V_218 = & V_40 -> V_142 [ V_209 ] ;
}
V_13 = F_20 ( V_12 , V_218 ,
V_215 [ V_67 ] ,
V_216 [ V_67 ] , V_151 ,
V_132 , V_206 ) ;
if ( ! V_13 ) {
if ( ( V_13 != 0 ) &&
! V_204 && V_216 [ V_67 ] &&
* V_12 -> V_16 ) {
( V_12 -> V_17 ) ++ ;
} else {
if ( ! V_216 [ V_67 ] ||
! ( * V_12 -> V_16 ) ) {
V_209 ++ ;
}
}
} else {
break;
}
}
}
if ( ! V_13 ) {
V_57 = V_5 -> V_103 ;
V_57 . V_227 = V_40 ;
V_57 . V_201 = V_12 ;
V_57 . V_228 = V_12 -> V_6 ;
V_57 . V_229 = false ;
V_13 =
V_5 -> V_72 . V_116 ( V_40 -> V_41 , V_58 , & V_57 ,
& V_210 ) ;
}
if ( V_13 ) {
if ( V_132 != V_135 ) {
for ( V_67 = 0 ; V_67 < V_12 -> V_17 ; V_67 ++ )
F_23 ( V_12 ,
& V_12 -> V_143 [ V_67 ] ) ;
V_12 -> V_17 = 0 ;
}
for ( V_67 = 0 ; V_67 < V_209 ; V_67 ++ )
F_23 ( V_12 , & V_40 -> V_142 [ V_67 ] ) ;
if ( V_40 -> V_41 )
V_5 -> V_72 . V_224 ( V_40 -> V_41 ) ;
}
V_206 -- ;
F_4 ( V_215 ) ;
V_215 = NULL ;
F_4 ( V_216 ) ;
V_216 = NULL ;
return V_13 ;
}
static int F_21 ( struct V_9 * V_12 ,
enum V_149 V_132 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
struct V_107 * V_230 = NULL ;
struct V_117 * V_197 = NULL ;
struct V_117 * V_125 = NULL ;
V_26 V_67 ;
V_26 V_198 = 0 ;
V_26 V_231 = 0 ;
V_26 * V_232 = NULL ;
V_26 * V_233 = NULL ;
T_2 V_156 ;
struct V_117 * V_118 ;
int V_13 = 0 ;
for ( V_67 = 0 ; V_67 < V_5 -> V_105 ; V_67 ++ ) {
if ( F_1
( & V_12 -> V_18 , & V_5 -> V_106 [ V_67 ] . V_18 ) ) {
V_230 = & ( V_5 -> V_106 [ V_67 ] ) ;
break;
}
}
if ( ! V_230 ) {
V_13 = - V_234 ;
goto V_165;
}
switch ( V_132 ) {
case V_133 :
V_232 = & ( V_230 -> V_235 ) ;
V_233 = & ( V_230 -> V_233 ) ;
V_197 = V_230 -> V_121 ;
V_125 = V_230 -> V_125 ;
break;
case V_135 :
V_232 = & ( V_230 -> V_236 ) ;
V_197 = V_230 -> V_124 ;
break;
case V_137 :
V_232 = & ( V_230 -> V_237 ) ;
V_197 = V_230 -> V_123 ;
break;
default:
break;
}
if ( V_232 == NULL )
goto V_165;
if ( * V_232 != 0 )
goto V_165;
V_118 = V_197 ;
while ( V_118 ) {
V_13 = F_33 ( V_5 -> V_87 , 0 , V_118 -> V_192 , 0 ,
& ( V_118 -> V_164 ) , true ) ;
if ( ! V_13 ) {
V_118 = V_118 -> V_122 ;
V_198 ++ ;
} else {
break;
}
}
if ( V_233 && * V_233 == 0 ) {
if ( ! V_13 ) {
V_118 = V_125 ;
while ( V_118 ) {
V_13 =
F_33 ( V_5 -> V_87 , 0 ,
V_118 -> V_192 , 0 ,
& ( V_118 -> V_164 ) ,
true ) ;
if ( ! V_13 ) {
V_118 = V_118 -> V_122 ;
V_231 ++ ;
} else {
break;
}
}
}
}
if ( * V_232 == 0 ) {
if ( ! V_13 ) {
V_118 = V_197 ;
while ( V_118 && ! V_13 ) {
V_156 =
(* V_5 -> V_100 ) ( V_12 ->
V_6 ,
V_118 ->
V_164 ,
V_118 ->
V_163 ,
V_118 -> V_192 ,
V_118 -> V_193 ) ;
if ( V_156 != V_118 -> V_192 )
V_13 = - V_238 ;
V_118 = V_118 -> V_122 ;
}
}
}
if ( V_233 && * V_233 == 0 ) {
if ( ! V_13 ) {
V_118 = V_125 ;
while ( V_118 && ! V_13 ) {
V_156 =
(* V_5 -> V_100 ) ( V_12 ->
V_6 ,
V_118 ->
V_164 ,
V_118 ->
V_163 ,
V_118 -> V_192 ,
V_118 -> V_193 ) ;
if ( V_156 != V_118 -> V_192 )
V_13 = - V_238 ;
V_118 = V_118 -> V_122 ;
}
}
}
if ( V_13 ) {
F_27 ( V_5 , V_197 , V_198 ) ;
F_27 ( V_5 , V_125 , V_231 ) ;
}
V_165:
if ( ! V_13 && ( V_232 != NULL ) ) {
* V_232 += 1 ;
if ( V_233 )
* V_233 += 1 ;
}
return V_13 ;
}
static int V_91 ( void * * V_239 , V_26 V_240 , T_2 V_192 ,
T_2 V_241 , T_2 * V_194 ,
T_3 V_242 , T_3 V_243 ,
bool V_244 )
{
struct V_9 * V_245 = (struct V_9 * ) V_239 ;
struct V_4 * V_5 ;
struct V_146 * V_87 ;
V_26 V_246 = V_247 ;
V_26 V_248 = 0 ;
V_26 V_67 ;
V_26 V_249 ;
T_2 V_250 ;
struct V_251 * V_252 = (struct V_251 * ) V_194 ;
bool V_253 = false ;
int V_13 = - V_15 ;
V_5 = V_245 -> V_5 ;
V_87 = V_5 -> V_87 ;
V_250 =
( V_192 + V_5 -> V_71 -
1 ) / V_5 -> V_71 ;
V_241 = F_34 ( V_254 , V_241 ) ;
F_11 ( V_77 , L_5 , V_78 , V_241 ) ;
if ( V_242 != - 1 ) {
V_252 -> V_248 = V_242 ;
V_248 = V_242 ;
V_253 = V_243 ;
} else {
switch ( V_245 -> V_132 ) {
case V_133 :
V_246 = V_25 ;
break;
case V_137 :
V_246 = V_37 ;
break;
case V_135 :
V_246 = V_34 ;
break;
default:
break;
}
if ( V_240 == V_113 )
V_246 ++ ;
if ( V_246 < V_247 )
V_248 = V_245 -> V_24 [ V_246 ] ;
if ( ( V_245 -> V_30 >> V_246 ) & 0x1 )
V_253 = true ;
}
V_249 = ( V_240 == V_113 ) ? V_255 : V_256 ;
if ( V_248 == V_257 ) {
goto V_258;
}
if ( V_248 <= V_259 ) {
V_252 -> V_248 = V_248 ;
V_13 =
F_33 ( V_87 , V_248 , V_250 , V_241 , V_194 , false ) ;
if ( V_13 ) {
F_11 ( V_77 , L_6 ,
V_78 , V_248 ) ;
}
} else {
V_249 |= V_248 == V_260 ?
V_261 : V_262 ;
for ( V_67 = 0 ; V_67 < V_5 -> V_60 ; V_67 ++ ) {
if ( ( V_5 -> V_82 [ V_67 ] & V_249 ) !=
V_249 )
continue;
V_13 = F_33 ( V_87 , V_67 , V_250 , V_241 ,
V_194 , false ) ;
if ( ! V_13 ) {
V_252 -> V_248 = V_67 ;
break;
}
}
}
V_258:
if ( V_13 == - V_15 && ! V_253 ) {
F_11 ( V_77 , L_7
L_8 , V_78 ) ;
for ( V_67 = 0 ; V_67 < V_5 -> V_60 ; V_67 ++ ) {
if ( ( V_5 -> V_82 [ V_67 ] & V_249 ) !=
V_249 )
continue;
V_13 = F_33 ( V_87 , V_67 , V_250 , V_241 ,
V_194 , false ) ;
if ( ! V_13 ) {
V_252 -> V_248 = V_67 ;
break;
}
}
}
return V_13 ;
}
static int V_93 ( void * * V_239 , V_26 V_86 , T_2 V_194 ,
T_2 V_192 , bool V_244 )
{
struct V_4 * V_5 = (struct V_4 * ) V_239 ;
struct V_146 * V_87 ;
T_2 V_250 ;
int V_13 = - V_15 ;
V_87 = V_5 -> V_87 ;
V_250 =
( V_192 + V_5 -> V_71 -
1 ) / V_5 -> V_71 ;
if ( F_28 ( V_87 , V_86 , V_194 , V_250 , V_244 ) )
V_13 = 0 ;
return V_13 ;
}
static void F_23 ( struct V_9 * V_12 ,
struct V_131 * V_40 )
{
struct V_55 V_57 ;
struct V_4 * V_5 = V_12 -> V_5 ;
V_26 V_67 ;
for ( V_67 = 0 ; V_67 < V_40 -> V_141 ; V_67 ++ )
F_23 ( V_12 , & V_40 -> V_142 [ V_67 ] ) ;
V_40 -> V_141 = 0 ;
V_57 = V_5 -> V_103 ;
V_57 . V_201 = V_5 -> V_87 ;
V_57 . V_228 = V_12 -> V_6 ;
V_57 . V_229 = false ;
V_57 . V_227 = V_40 ;
if ( V_40 -> V_41 ) {
V_5 -> V_72 . V_263 ( V_40 -> V_41 , & V_57 ) ;
V_5 -> V_72 . V_224 ( V_40 -> V_41 ) ;
}
F_4 ( V_40 -> V_142 ) ;
V_40 -> V_142 = NULL ;
}
static void F_24 ( struct V_9 * V_12 ,
enum V_149 V_132 )
{
struct V_4 * V_5 = V_12 -> V_5 ;
struct V_107 * V_230 = NULL ;
struct V_117 * V_197 = NULL ;
struct V_117 * V_125 = NULL ;
V_26 V_67 ;
V_26 V_198 = 0 ;
V_26 V_231 = 0 ;
V_26 * V_232 = NULL ;
V_26 * V_233 = NULL ;
for ( V_67 = 0 ; V_67 < V_5 -> V_105 ; V_67 ++ ) {
if ( F_1
( & V_12 -> V_18 , & V_5 -> V_106 [ V_67 ] . V_18 ) ) {
V_230 = & ( V_5 -> V_106 [ V_67 ] ) ;
break;
}
}
if ( ! V_230 )
return;
switch ( V_132 ) {
case V_133 :
V_232 = & ( V_230 -> V_235 ) ;
V_197 = V_230 -> V_121 ;
V_198 = V_230 -> V_167 ;
break;
case V_135 :
V_232 = & ( V_230 -> V_236 ) ;
V_197 = V_230 -> V_124 ;
V_198 = V_230 -> V_171 ;
break;
case V_137 :
V_232 = & ( V_230 -> V_237 ) ;
V_233 = & ( V_230 -> V_233 ) ;
V_197 = V_230 -> V_123 ;
V_125 = V_230 -> V_125 ;
V_198 = V_230 -> V_169 ;
V_231 = V_230 -> V_172 ;
break;
default:
break;
}
if ( V_232 && ( * V_232 > 0 ) ) {
* V_232 -= 1 ;
if ( V_233 ) {
* V_233 -= 1 ;
}
}
if ( V_232 && * V_232 == 0 ) {
F_27 ( V_5 , V_197 , V_198 ) ;
}
if ( V_233 && * V_233 == 0 )
F_27 ( V_5 , V_125 , V_231 ) ;
}
static bool F_30 ( struct V_9 * V_12 ,
struct V_205 * V_41 )
{
T_3 V_67 = 0 ;
for ( V_67 = 0 ; V_67 < V_12 -> V_17 ; V_67 ++ ) {
if ( V_41 == V_12 -> V_143 [ V_67 ] . V_41 )
return true ;
}
return false ;
}
int F_35 ( struct V_9 * V_264 , T_2 V_265 ,
T_2 V_266 , void * V_267 , char * V_202 )
{
int V_13 = 0 ;
bool V_130 = false ;
T_3 V_67 = 0 ;
struct V_131 V_40 = { NULL , 0 , NULL } ;
if ( V_264 -> V_23 && * V_264 -> V_16 ) {
switch ( V_264 -> V_132 ) {
case V_133 :
V_40 = V_264 -> V_134 ;
break;
case V_135 :
V_40 = V_264 -> V_136 ;
break;
case V_137 :
V_40 = V_264 -> V_138 ;
break;
default:
break;
}
} else {
V_40 = V_264 -> V_40 ;
}
V_130 = F_36 ( V_40 . V_41 , V_265 ,
V_266 , V_267 , V_202 ) ;
if ( ! V_130 )
for ( V_67 = 0 ; V_67 < V_40 . V_141 ; V_67 ++ ) {
V_130 = F_36 (
V_40 . V_142 [ V_67 ] . V_41 , V_265 ,
V_266 , V_267 , V_202 ) ;
if ( V_130 )
break;
}
if ( ! V_130 )
for ( V_67 = 0 ; V_67 < V_264 -> V_17 ; V_67 ++ ) {
V_130 = F_36 (
V_264 -> V_143 [ V_67 ] . V_41 , V_265 ,
V_266 , V_267 , V_202 ) ;
if ( V_130 )
break;
}
if ( ! V_130 ) {
F_37 ( L_9 ,
V_78 , V_265 , V_266 ) ;
V_13 = - V_145 ;
} else {
F_37 ( L_10 ,
V_78 , ( T_2 ) V_264 , V_265 , V_266 ,
( T_2 ) V_267 , V_202 ) ;
}
return V_13 ;
}
