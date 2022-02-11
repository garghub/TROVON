static int F_1 ( const char * V_1 , T_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
int V_4 , V_5 ;
V_4 = F_2 ( * V_1 ++ ) ;
if ( V_4 < 0 )
return - 1 ;
V_5 = F_2 ( * V_1 ++ ) ;
if ( V_5 < 0 )
return - 1 ;
* V_2 ++ = ( V_4 << 4 ) | V_5 ;
if ( V_3 < 5 && * V_1 ++ != ':' )
return - 1 ;
}
return 0 ;
}
void F_3 ( struct V_6 * V_7 )
{
union V_8 V_9 ;
struct V_10 * V_11 = & V_7 -> V_12 ;
V_9 . V_13 . V_14 = V_15 ;
memcpy ( V_9 . V_13 . V_16 , V_11 -> V_17 . V_18 . V_19 ,
V_20 ) ;
F_4 ( V_7 -> V_21 , V_22 , & V_9 , NULL ) ;
}
void F_5 ( struct V_6 * V_7 )
{
union V_8 V_9 ;
V_9 . V_13 . V_14 = V_15 ;
memset ( V_9 . V_13 . V_16 , 0 , V_20 ) ;
F_4 ( V_7 -> V_21 , V_22 , & V_9 , NULL ) ;
}
static inline void F_6 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
struct V_6 * V_7 )
{
memcpy ( V_24 -> V_27 . V_28 , V_26 -> V_29 . V_30 . V_31 ,
( V_26 -> V_29 . V_30 . V_32 > 16 ? 16 : V_26 -> V_29 . V_30 . V_32 ) ) ;
if ( strcmp ( V_26 -> V_29 . V_30 . V_33 , L_1 ) == 0 ) {
memcpy ( V_24 -> V_34 . V_28 , & ( V_26 -> V_29 . V_30 .
V_31 [ 16 ] ) , 8 ) ;
memcpy ( V_24 -> V_35 . V_28 , & ( V_26 -> V_29 . V_30 .
V_31 [ 24 ] ) , 8 ) ;
V_7 -> V_36 . V_37 = false ;
F_7 ( & V_7 -> V_36 . V_38 , 50 ) ;
}
F_8 ( V_7 , ( unsigned char * ) V_24 , true ) ;
}
static inline void F_9 ( struct V_25 * V_26 ,
struct V_6 * V_7 )
{
if ( 0 < V_26 -> V_29 . V_30 . V_39 &&
V_26 -> V_29 . V_30 . V_39 < 3 ) {
memcpy ( V_7 -> V_36 . V_40 [ V_26 -> V_29 . V_30 .
V_39 - 1 ] . V_28 , V_26 -> V_29 . V_30 . V_31 , ( V_26 -> V_29 . V_30 . V_32
> 16 ? 16 : V_26 -> V_29 . V_30 . V_32 ) ) ;
memcpy ( V_7 -> V_36 . V_41 [ V_26 ->
V_29 . V_30 . V_39 - 1 ] . V_28 , & ( V_26 -> V_29 . V_30 . V_31 [ 16 ] ) , 8 ) ;
memcpy ( V_7 -> V_36 . V_42 [ V_26 ->
V_29 . V_30 . V_39 - 1 ] . V_28 , & ( V_26 -> V_29 . V_30 . V_31 [ 24 ] ) , 8 ) ;
V_7 -> V_36 . V_43 = true ;
F_10 ( V_7 , & V_7 -> V_36 ,
V_26 -> V_29 . V_30 . V_39 ) ;
if ( V_7 -> V_44 . V_45 > V_46 ) {
if ( V_7 -> V_44 . V_45 != V_7 ->
V_47 . V_48 )
F_7 ( & ( V_7 -> V_12 . V_49 ) ,
60000 ) ;
}
}
}
static inline char * F_11 ( struct V_6 * V_7 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
char * V_54 , char * V_55 )
{
struct V_56 V_57 ;
struct V_58 * V_59 ;
char * V_60 ;
T_2 * V_61 ;
T_3 V_3 = 0 , V_62 = 0 ;
T_4 V_63 , V_64 = false , V_65 ;
T_1 V_66 , V_67 = 0 , V_68 = 0 ;
if ( ( V_53 -> V_18 . V_69 . V_70 < 1 ) ||
( V_53 -> V_18 . V_69 . V_70 > 14 ) ) {
if ( V_53 -> V_18 . V_69 . V_70 < 1 )
V_53 -> V_18 . V_69 . V_70 = 1 ;
else
V_53 -> V_18 . V_69 . V_70 = 14 ;
}
V_57 . V_71 = V_22 ;
V_57 . V_29 . V_13 . V_14 = V_15 ;
memcpy ( V_57 . V_29 . V_13 . V_16 , V_53 -> V_18 . V_19 , V_20 ) ;
V_54 = F_12 ( V_51 , V_54 , V_55 , & V_57 , V_72 ) ;
V_57 . V_71 = V_73 ;
V_57 . V_29 . V_74 . V_75 = 1 ;
V_57 . V_29 . V_74 . V_76 = F_13 ( T_3 , V_53 -> V_18 . V_77 . V_78 , 32 ) ;
V_54 = F_14 ( V_51 , V_54 , V_55 , & V_57 ,
V_53 -> V_18 . V_77 . V_77 ) ;
V_61 = F_15 ( & V_53 -> V_18 . V_79 [ 12 ] , V_80 ,
& V_62 , V_53 -> V_18 . V_81 - 12 ) ;
if ( V_61 && V_62 > 0 ) {
V_64 = true ;
V_59 = (struct V_58 * ) ( V_61 + 2 ) ;
memcpy ( & V_65 , V_59 -> V_82 , 2 ) ;
V_67 = ( V_59 -> V_83 & V_84 )
? 1 : 0 ;
V_68 = ( V_59 -> V_83 & ( V_85 |
V_86 ) ) ? 1 : 0 ;
}
V_57 . V_71 = V_87 ;
if ( ( F_16 ( ( T_1 * ) & V_53 -> V_18 .
V_88 ) ) == true ) {
if ( V_64 == true )
snprintf ( V_57 . V_29 . V_89 , V_90 , L_2 ) ;
else
snprintf ( V_57 . V_29 . V_89 , V_90 , L_3 ) ;
} else if ( ( F_17 ( ( T_1 * ) & V_53 -> V_18 .
V_88 ) ) == true ) {
if ( V_64 == true )
snprintf ( V_57 . V_29 . V_89 , V_90 , L_4 ) ;
else
snprintf ( V_57 . V_29 . V_89 , V_90 , L_5 ) ;
} else {
if ( V_64 == true )
snprintf ( V_57 . V_29 . V_89 , V_90 , L_6 ) ;
else
snprintf ( V_57 . V_29 . V_89 , V_90 , L_7 ) ;
}
V_54 = F_12 ( V_51 , V_54 , V_55 , & V_57 , V_91 ) ;
V_57 . V_71 = V_92 ;
memcpy ( ( T_1 * ) & V_63 , F_18 ( V_53 -> V_18 . V_79 ) ,
2 ) ;
V_63 = F_19 ( V_63 ) ;
if ( V_63 & ( V_93 | V_94 ) ) {
if ( V_63 & V_94 )
V_57 . V_29 . V_95 = ( T_3 ) V_96 ;
else
V_57 . V_29 . V_95 = ( T_3 ) V_97 ;
V_54 = F_12 ( V_51 , V_54 , V_55 , & V_57 ,
V_98 ) ;
}
V_57 . V_71 = V_99 ;
{
T_1 V_100 = V_53 -> V_18 . V_69 . V_70 ;
if ( V_100 >= 1 && V_100 <= sizeof(
V_101 ) / sizeof( long ) )
V_57 . V_29 . V_102 . V_103 = ( V_104 ) ( V_101 [
V_53 -> V_18 . V_69 .
V_70 - 1 ] * 100000 ) ;
else
V_57 . V_29 . V_102 . V_103 = 0 ;
}
V_57 . V_29 . V_102 . V_105 = ( V_106 ) 1 ;
V_57 . V_29 . V_102 . V_3 = ( T_1 ) V_53 -> V_18 . V_69 . V_70 ;
V_54 = F_12 ( V_51 , V_54 , V_55 , & V_57 ,
V_107 ) ;
V_57 . V_71 = V_108 ;
if ( V_63 & V_109 )
V_57 . V_29 . V_74 . V_75 = ( T_4 ) ( V_110 |
V_111 ) ;
else
V_57 . V_29 . V_74 . V_75 = ( T_4 ) ( V_112 ) ;
V_57 . V_29 . V_74 . V_76 = ( T_4 ) 0 ;
V_54 = F_14 ( V_51 , V_54 , V_55 , & V_57 ,
V_53 -> V_18 . V_77 . V_77 ) ;
V_60 = V_54 + F_20 ( V_51 ) ;
V_57 . V_71 = V_113 ;
V_57 . V_29 . V_114 . V_115 = 0 ;
V_57 . V_29 . V_114 . V_116 = 0 ;
V_57 . V_29 . V_114 . V_117 = 0 ;
V_3 = 0 ;
while ( V_53 -> V_18 . V_88 [ V_3 ] != 0 ) {
V_57 . V_29 . V_114 . V_117 = ( V_53 -> V_18 . V_88 [ V_3 ++ ] &
0x7F ) * 500000 ;
V_60 = F_21 ( V_51 , V_54 , V_60 ,
V_55 , & V_57 , V_118 ) ;
}
if ( ( V_60 - V_54 ) > F_20 ( V_51 ) )
V_54 = V_60 ;
{
T_1 V_119 [ V_120 ] ;
T_1 V_121 [ 255 ] , V_122 [ 255 ] ;
T_4 V_123 = 0 , V_124 = 0 ;
int V_125 ;
T_5 V_126 = 0 ;
V_126 = F_22 ( V_53 -> V_18 . V_79 ,
V_53 -> V_18 .
V_81 , V_122 , & V_124 ,
V_121 , & V_123 ) ;
if ( V_123 > 0 ) {
memset ( V_119 , 0 , V_120 ) ;
V_125 = sprintf ( V_119 , L_8 ) ;
for ( V_3 = 0 ; V_3 < V_123 ; V_3 ++ ) {
V_125 += snprintf ( V_119 + V_125 , V_120 - V_125 ,
L_9 , V_121 [ V_3 ] ) ;
if ( V_125 >= V_120 )
break;
}
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_71 = V_127 ;
V_57 . V_29 . V_74 . V_76 = ( T_4 ) strlen ( V_119 ) ;
V_54 = F_14 ( V_51 , V_54 , V_55 ,
& V_57 , V_119 ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_71 = V_128 ;
V_57 . V_29 . V_74 . V_76 = ( T_4 ) V_123 ;
V_54 = F_14 ( V_51 , V_54 , V_55 ,
& V_57 , V_121 ) ;
}
if ( V_124 > 0 ) {
memset ( V_119 , 0 , V_120 ) ;
V_125 = sprintf ( V_119 , L_10 ) ;
for ( V_3 = 0 ; V_3 < V_124 ; V_3 ++ ) {
V_125 += snprintf ( V_119 + V_125 , V_120 - V_125 ,
L_9 , V_122 [ V_3 ] ) ;
if ( V_125 >= V_120 )
break;
}
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_71 = V_127 ;
V_57 . V_29 . V_74 . V_76 = strlen ( V_119 ) ;
V_54 = F_14 ( V_51 , V_54 , V_55 ,
& V_57 , V_119 ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_71 = V_128 ;
V_57 . V_29 . V_74 . V_76 = V_124 ;
V_54 = F_14 ( V_51 , V_54 , V_55 , & V_57 ,
V_122 ) ;
}
}
{
T_1 V_129 [ 512 ] ;
T_6 V_130 ;
if ( F_23 ( V_53 -> V_18 . V_79 ,
V_53 -> V_18 . V_81 ,
V_129 , & V_130 ) == true ) {
if ( V_130 > 2 ) {
V_57 . V_71 = V_128 ;
V_57 . V_29 . V_74 . V_76 = ( T_4 ) V_130 ;
V_54 = F_14 ( V_51 , V_54 , V_55 ,
& V_57 , V_129 ) ;
}
}
}
V_57 . V_71 = V_131 ;
V_66 = F_24 ( V_53 -> V_18 . V_132 ) ;
V_57 . V_29 . V_133 . V_134 = ( T_1 ) ( V_135 | V_136 |
V_137 ) ;
V_57 . V_29 . V_133 . V_138 = V_66 ;
V_57 . V_29 . V_133 . V_133 = 0 ;
V_57 . V_29 . V_133 . V_139 = 0 ;
V_54 = F_12 ( V_51 , V_54 , V_55 , & V_57 , V_140 ) ;
return V_54 ;
}
static int F_25 ( struct V_141 * V_142 , T_3 V_117 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
int V_143 = 0 ;
if ( ( V_117 & V_144 ) && ( V_117 & V_145 ) ) {
V_7 -> V_36 . V_146 =
V_147 ;
V_7 -> V_36 . V_148 =
V_149 ;
V_7 -> V_36 . V_150 = 3 ;
} else if ( V_117 & V_144 ) {
V_7 -> V_36 . V_146 =
V_147 ;
V_7 -> V_36 . V_148 = V_151 ;
V_7 -> V_36 . V_150 = 1 ;
} else if ( V_117 & V_145 ) {
if ( V_7 -> V_36 . V_148 <
V_152 ) {
V_7 -> V_36 . V_148 =
V_153 ;
V_7 -> V_36 . V_150 = 0 ;
}
} else
V_143 = - V_154 ;
return V_143 ;
}
static int F_27 ( struct V_141 * V_142 , struct V_25 * V_26 ,
T_3 V_155 )
{
int V_143 = 0 ;
T_3 V_156 , V_157 = 0 ;
struct V_158 * V_159 = NULL ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_160 * V_161 = & V_7 -> V_36 ;
V_26 -> V_29 . V_30 . V_162 = 0 ;
V_26 -> V_29 . V_30 . V_33 [ V_163 - 1 ] = '\0' ;
if ( V_155 != ( T_3 ) ( ( T_1 * ) V_26 -> V_29 . V_30 . V_31 - ( T_1 * ) V_26 ) +
V_26 -> V_29 . V_30 . V_32 )
return - V_154 ;
if ( F_28 ( V_26 -> V_164 ) ) {
if ( V_26 -> V_29 . V_30 . V_39 >= V_165 ) {
V_26 -> V_29 . V_30 . V_39 = 0 ;
}
} else
return - V_154 ;
if ( strcmp ( V_26 -> V_29 . V_30 . V_33 , L_11 ) == 0 ) {
F_29 ( V_142 , L_12 , V_166 ) ;
V_7 -> V_36 . V_146 =
V_147 ;
V_7 -> V_36 . V_167 = V_168 ;
V_7 -> V_36 . V_169 = V_168 ;
V_156 = V_26 -> V_29 . V_30 . V_39 ;
V_157 = V_26 -> V_29 . V_30 . V_32 ;
if ( V_156 >= V_165 )
V_156 = 0 ;
if ( V_157 > 0 ) {
V_157 = V_157 <= 5 ? 5 : 13 ;
V_159 = F_30 ( ( T_3 ) ( V_157 +
F_31 ( struct V_158 , V_170 ) ) ,
V_171 ) ;
if ( V_159 == NULL )
return - V_172 ;
memset ( V_159 , 0 , sizeof( struct V_158 ) ) ;
V_159 -> V_173 = V_157 ;
V_159 -> V_174 = V_157 +
F_31 ( struct V_158 ,
V_170 ) ;
if ( V_157 == 13 ) {
V_7 -> V_36 . V_167 =
V_175 ;
V_7 -> V_36 . V_169 =
V_175 ;
}
} else
return - V_154 ;
V_159 -> V_176 = V_156 ;
V_159 -> V_176 |= 0x80000000 ;
memcpy ( V_159 -> V_170 , V_26 -> V_29 . V_30 . V_31 , V_159 -> V_173 ) ;
if ( V_26 -> V_29 . V_30 . V_177 ) {
if ( F_32 ( V_7 , V_159 ) ==
( T_1 ) V_178 )
V_143 = - V_179 ;
} else {
if ( V_156 >= V_165 ) {
V_143 = - V_179 ;
goto exit;
}
memcpy ( & ( V_161 -> V_180 [ V_156 ] .
V_28 [ 0 ] ) , V_159 -> V_170 ,
V_159 -> V_173 ) ;
V_161 -> V_181 [ V_156 ] =
V_159 -> V_173 ;
F_10 ( V_7 , V_161 , V_156 ) ;
}
goto exit;
}
if ( V_7 -> V_36 . V_150 == 2 ) {
struct V_23 * V_24 , * V_182 ;
struct V_183 * V_184 = & V_7 -> V_185 ;
if ( F_33 ( V_11 , V_186 |
V_187 ) == true ) {
V_24 = F_34 ( V_184 ,
F_35 ( V_11 ) ) ;
if ( V_24 ) {
V_24 -> V_188 = false ;
if ( ( V_7 -> V_36 . V_146 ==
V_189 ) ||
( V_7 -> V_36 . V_146 ==
V_190 ) )
V_24 -> V_191 = V_7 ->
V_36 . V_167 ;
if ( V_26 -> V_29 . V_30 . V_177 == 1 )
F_6 ( V_24 , V_26 ,
V_7 ) ;
else
F_9 ( V_26 , V_7 ) ;
}
V_182 = F_36 ( V_7 ) ;
if ( V_182 ) {
V_182 -> V_188 = false ;
if ( ( V_7 -> V_36 . V_146 ==
V_189 ) ||
( V_7 -> V_36 . V_146 ==
V_190 ) )
V_182 -> V_191 =
V_7 -> V_36 .
V_167 ;
}
}
}
exit:
F_37 ( ( T_1 * ) V_159 ) ;
return V_143 ;
}
static int F_38 ( struct V_6 * V_7 , char * V_192 ,
unsigned short V_193 )
{
T_1 * V_119 = NULL , * V_194 = NULL ;
int V_195 = 0 , V_196 = 0 ;
int V_143 = 0 ;
if ( ( V_193 > V_120 ) || ( V_192 == NULL ) )
return - V_154 ;
if ( V_193 ) {
V_119 = F_39 ( V_192 , V_193 , V_171 ) ;
if ( V_119 == NULL )
return - V_172 ;
V_194 = V_119 ;
if ( V_193 < V_197 ) {
V_143 = - V_154 ;
goto exit;
}
if ( F_40 ( V_119 , V_193 , & V_195 ,
& V_196 ) == V_198 ) {
V_7 -> V_36 . V_150 = 2 ;
V_7 -> V_36 . V_148 =
V_152 ;
}
if ( F_41 ( V_119 , V_193 , & V_195 ,
& V_196 ) == V_198 ) {
V_7 -> V_36 . V_150 = 2 ;
V_7 -> V_36 . V_148 =
V_199 ;
}
switch ( V_195 ) {
case V_200 :
V_7 -> V_36 . V_169 =
V_201 ;
V_7 -> V_36 . V_146 =
V_202 ;
break;
case V_203 :
V_7 -> V_36 . V_169 = V_168 ;
V_7 -> V_36 . V_146 =
V_147 ;
break;
case V_204 :
V_7 -> V_36 . V_169 = V_205 ;
V_7 -> V_36 . V_146 =
V_189 ;
break;
case V_206 :
V_7 -> V_36 . V_169 = V_207 ;
V_7 -> V_36 . V_146 =
V_190 ;
break;
case V_208 :
V_7 -> V_36 . V_169 = V_175 ;
V_7 -> V_36 . V_146 =
V_147 ;
break;
}
switch ( V_196 ) {
case V_200 :
V_7 -> V_36 . V_167 =
V_201 ;
V_7 -> V_36 . V_146 =
V_202 ;
break;
case V_203 :
V_7 -> V_36 . V_167 = V_168 ;
V_7 -> V_36 . V_146 =
V_147 ;
break;
case V_204 :
V_7 -> V_36 . V_167 = V_205 ;
V_7 -> V_36 . V_146 =
V_189 ;
break;
case V_206 :
V_7 -> V_36 . V_167 = V_207 ;
V_7 -> V_36 . V_146 =
V_190 ;
break;
case V_208 :
V_7 -> V_36 . V_167 = V_175 ;
V_7 -> V_36 . V_146 =
V_147 ;
break;
}
V_7 -> V_36 . V_209 = false ;
{
T_4 V_210 = 0 ;
T_1 V_211 , V_212 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_210 < V_193 ) {
V_211 = V_119 [ V_210 ] ;
if ( ( V_211 == V_213 ) &&
( ! memcmp ( & V_119 [ V_210 + 2 ] , V_212 , 4 ) ) ) {
F_29 ( V_7 -> V_21 , L_13 ) ;
V_7 -> V_36 . V_214 =
( ( V_119 [ V_210 + 1 ] + 2 ) <
( V_120 << 2 ) ) ?
( V_119 [ V_210 + 1 ] + 2 ) :
( V_120 << 2 ) ;
memcpy ( V_7 -> V_36 . V_129 ,
& V_119 [ V_210 ] ,
V_7 -> V_36 . V_214 ) ;
V_7 -> V_36 . V_209 =
true ;
F_29 ( V_7 -> V_21 , L_14 ) ;
V_210 += V_119 [ V_210 + 1 ] + 2 ;
break;
} else
V_210 += V_119 [ V_210 + 1 ] + 2 ;
}
}
}
exit:
F_37 ( V_119 ) ;
return V_143 ;
}
static int F_42 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
T_3 V_62 = 0 ;
char * V_61 ;
T_1 V_64 = false ;
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
T_7 * V_218 = NULL ;
if ( F_33 ( V_11 , V_219 | V_220 ) ==
true ) {
V_61 = F_15 ( & V_217 -> V_79 [ 12 ] , V_80 ,
& V_62 , V_217 -> V_81 - 12 ) ;
if ( V_61 && V_62 > 0 )
V_64 = true ;
V_218 = & V_217 -> V_88 ;
if ( F_16 ( ( T_1 * ) V_218 ) == true ) {
if ( V_64 == true )
snprintf ( V_9 -> V_89 , V_90 ,
L_2 ) ;
else
snprintf ( V_9 -> V_89 , V_90 ,
L_3 ) ;
} else if ( ( F_17 ( ( T_1 * ) V_218 ) ) == true ) {
if ( V_64 == true )
snprintf ( V_9 -> V_89 , V_90 ,
L_4 ) ;
else
snprintf ( V_9 -> V_89 , V_90 ,
L_5 ) ;
} else {
if ( V_64 == true )
snprintf ( V_9 -> V_89 , V_90 ,
L_6 ) ;
else
snprintf ( V_9 -> V_89 , V_90 ,
L_7 ) ;
}
} else
snprintf ( V_9 -> V_89 , V_90 , L_15 ) ;
return 0 ;
}
static int F_43 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_221 * V_222 = & V_9 -> V_102 ;
int V_223 = 0 ;
if ( ( V_222 -> V_105 == 1 ) &&
( V_222 -> V_103 >= ( int ) 2.412e8 ) &&
( V_222 -> V_103 <= ( int ) 2.487e8 ) ) {
int V_224 = V_222 -> V_103 / 100000 ;
int V_225 = 0 ;
while ( ( V_225 < 14 ) && ( V_224 != V_226 [ V_225 ] ) )
V_225 ++ ;
V_222 -> V_105 = 0 ;
V_222 -> V_103 = V_225 + 1 ;
}
if ( ( V_222 -> V_103 > 14 ) || ( V_222 -> V_105 > 0 ) )
V_223 = - V_179 ;
else {
int V_227 = V_222 -> V_103 ;
if ( ( V_227 < 1 ) || ( V_227 > 14 ) )
V_223 = - V_154 ;
else {
V_7 -> V_44 . V_227 = V_227 ;
}
}
return V_223 ;
}
static int F_44 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
if ( F_33 ( V_11 , V_219 ) == true ) {
V_9 -> V_102 . V_103 = V_101 [
V_217 -> V_69 . V_70 - 1 ] * 100000 ;
V_9 -> V_102 . V_105 = 1 ;
V_9 -> V_102 . V_3 = V_217 -> V_69 . V_70 ;
} else {
return - V_228 ;
}
return 0 ;
}
static int F_45 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
enum V_229 V_230 ;
switch ( V_9 -> V_95 ) {
case V_231 :
V_230 = V_232 ;
break;
case V_97 :
V_230 = V_233 ;
break;
case V_96 :
V_230 = V_234 ;
break;
case V_235 :
V_230 = V_236 ;
break;
default:
return - V_154 ;
}
if ( V_234 == V_230 )
F_46 ( V_7 , V_230 ) ;
else
F_46 ( V_7 , V_232 ) ;
F_47 ( V_7 , V_230 ) ;
return 0 ;
}
static int F_48 ( struct V_141 * V_142 , struct V_50 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
if ( F_33 ( V_11 , V_186 ) == true )
V_9 -> V_95 = V_235 ;
else if ( F_33 ( V_11 ,
V_220 | V_237 ) == true )
V_9 -> V_95 = V_97 ;
else if ( F_33 ( V_11 , V_238 ) == true )
V_9 -> V_95 = V_96 ;
else
V_9 -> V_95 = V_231 ;
return 0 ;
}
static int F_49 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_160 * V_161 = & V_7 -> V_36 ;
struct V_239 * V_240 = (struct V_239 * ) V_215 ;
T_1 V_241 [ V_20 ] = { 0x00 } ;
T_1 V_242 [ V_20 ] = { 0x00 } ;
T_1 V_243 , V_244 = false ;
int V_245 = false ;
if ( V_240 == NULL )
return - V_154 ;
memcpy ( V_242 , V_240 -> V_246 . V_16 , V_20 ) ;
switch ( V_240 -> V_71 ) {
case V_247 :
if ( ! memcmp ( V_242 , V_241 , V_20 ) )
return V_245 ;
else
V_245 = true ;
V_244 = false ;
for ( V_243 = 0 ; V_243 < V_248 ; V_243 ++ ) {
if ( ! memcmp ( V_161 -> V_249 [ V_243 ] . V_250 ,
V_242 , V_20 ) ) {
F_29 ( V_142 , L_16 ,
V_166 ) ;
memcpy ( V_161 -> V_249 [ V_243 ] . V_251 ,
V_240 -> V_252 , V_253 ) ;
V_161 -> V_249 [ V_243 ] . V_254 = true ;
V_161 -> V_255 = V_243 + 1 ;
V_244 = true ;
break;
}
}
if ( ! V_244 ) {
F_29 ( V_142 , L_17 ,
V_166 , V_161 -> V_255 ) ;
memcpy ( V_161 -> V_249 [ V_161 ->
V_255 ] . V_250 , V_242 , V_20 ) ;
memcpy ( V_161 -> V_249 [ V_161 ->
V_255 ] . V_251 , V_240 -> V_252 , V_253 ) ;
V_161 -> V_249 [ V_161 -> V_255 ] .
V_254 = true ;
V_161 -> V_255 ++ ;
if ( V_161 -> V_255 == V_248 )
V_161 -> V_255 = 0 ;
}
break;
case V_256 :
V_245 = true ;
for ( V_243 = 0 ; V_243 < V_248 ; V_243 ++ ) {
if ( ! memcmp ( V_161 -> V_249 [ V_243 ] . V_250 ,
V_242 , V_20 ) ) {
memset ( V_161 -> V_249 [ V_243 ] . V_250 ,
0x00 , V_20 ) ;
V_161 -> V_249 [ V_243 ] . V_254 = false ;
break;
}
}
break;
case V_257 :
memset ( V_161 -> V_249 , 0 ,
sizeof( struct V_258 ) * V_248 ) ;
V_161 -> V_255 = 0 ;
V_245 = true ;
break;
default:
F_29 ( V_142 , L_18 , V_166 ) ;
V_245 = false ;
break;
}
return V_245 ;
}
static int F_50 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
V_9 -> V_259 . V_117 = 0 ;
V_9 -> V_259 . V_115 = 0 ;
V_9 -> V_259 . V_116 = 1 ;
return 0 ;
}
static int F_51 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_260 * V_261 = (struct V_260 * ) V_215 ;
T_4 V_262 ;
int V_3 ;
V_9 -> V_74 . V_76 = sizeof( * V_261 ) ;
memset ( V_261 , 0 , sizeof( * V_261 ) ) ;
V_261 -> V_263 = 5 * 1000 * 1000 ;
V_261 -> V_264 . V_133 = 100 ;
V_261 -> V_264 . V_138 = 100 ;
V_261 -> V_264 . V_139 = 100 ;
V_261 -> V_264 . V_134 = 7 ;
V_261 -> V_265 . V_133 = 92 ;
V_261 -> V_265 . V_138 = 20 + - 98 ;
V_261 -> V_265 . V_139 = 0 ;
V_261 -> V_265 . V_134 = 7 ;
V_261 -> V_266 = V_267 ;
for ( V_3 = 0 ; V_3 < V_267 && V_3 < V_268 ; V_3 ++ )
V_261 -> V_114 [ V_3 ] = V_269 [ V_3 ] ;
V_261 -> V_270 = V_271 ;
V_261 -> V_272 = V_273 ;
V_261 -> V_274 = 0 ;
V_261 -> V_275 = V_276 ;
V_261 -> V_277 = 16 ;
V_261 -> V_278 = 14 ;
for ( V_3 = 0 , V_262 = 0 ; V_3 < 14 ; V_3 ++ ) {
V_261 -> V_102 [ V_262 ] . V_3 = V_3 + 1 ;
V_261 -> V_102 [ V_262 ] . V_103 = V_101 [ V_3 ] * 100000 ;
V_261 -> V_102 [ V_262 ] . V_105 = 1 ;
V_262 ++ ;
if ( V_262 == V_279 )
break;
}
V_261 -> V_280 = V_262 ;
V_261 -> V_281 = V_282 |
V_283 |
V_284 |
V_285 ;
return 0 ;
}
static int F_52 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_286 ,
char * V_215 )
{
int V_143 = 0 , V_287 = 0 ;
char * V_288 ;
struct V_6 * V_7 = F_26 ( V_142 ) ;
struct V_289 * V_290 = (struct V_289 * ) V_286 ;
V_287 = V_290 -> V_76 ;
V_288 = F_53 ( V_290 -> V_291 , V_287 ) ;
if ( F_54 ( V_288 ) )
return F_55 ( V_288 ) ;
if ( 0 == strcasecmp ( V_288 , L_19 ) ) {
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
struct V_52 * V_292 = & V_11 -> V_17 ;
if ( F_33 ( V_11 , V_219 ) == true ) {
sprintf ( V_288 , L_20 ,
V_292 -> V_18 . V_77 . V_77 ,
( ( V_7 -> V_293 . V_294 ) >> 1 ) - 95
) ;
} else {
sprintf ( V_288 , L_21 ) ;
}
} else if ( 0 == strcasecmp ( V_288 , L_22 ) ) {
union V_8 V_295 ;
int V_296 ;
int V_297 ;
V_296 = F_56 ( V_142 , V_51 , & V_295 , V_215 ) ;
if ( 0 != V_296 )
V_297 = 0 ;
else
V_297 = V_295 . V_114 . V_117 / 1000000 ;
sprintf ( V_288 , L_23 , V_297 ) ;
} else if ( 0 == strcasecmp ( V_288 , L_24 ) ) {
sprintf ( V_288 , L_25 , V_142 -> V_298 ) ;
} else if ( 0 == strcasecmp ( V_288 , L_26 ) ) {
struct V_10 * V_11 = & V_7 -> V_12 ;
V_11 -> V_299 = 1 ;
sprintf ( V_288 , L_21 ) ;
} else if ( 0 == strcasecmp ( V_288 , L_27 ) ) {
struct V_10 * V_11 = & V_7 -> V_12 ;
V_11 -> V_299 = 0 ;
sprintf ( V_288 , L_21 ) ;
} else if ( 0 == strncmp ( V_288 , L_28 , 5 ) ) {
F_57 ( V_7
, 1
, 5
, 100
, 5000
) ;
sprintf ( V_288 , L_21 ) ;
} else if ( 0 == strncmp ( V_288 , L_29 , 5 ) ) {
F_57 ( V_7
, 0
, 5
, 100
, 5000
) ;
sprintf ( V_288 , L_21 ) ;
} else {
F_29 ( V_142 , L_30 ,
V_166 , V_288 ) ;
goto V_300;
}
if ( F_58 ( V_290 -> V_291 , V_288 ,
F_59 ( V_290 -> V_76 , ( V_301 ) ( strlen ( V_288 ) + 1 ) ) ) )
V_143 = - V_302 ;
V_300:
F_37 ( V_288 ) ;
return V_143 ;
}
static int F_60 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_286 ,
char * V_215 )
{
int V_143 = - V_303 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_304 * V_305 = & V_11 -> V_306 ;
struct V_307 * V_308 = (struct V_307 * ) V_286 ;
unsigned long V_309 ;
struct V_310 * V_311 ;
T_1 * V_312 ;
struct V_52 * V_53 = NULL ;
enum V_313 V_314 ;
if ( F_33 ( V_11 , V_315 ) == true )
return - V_316 ;
if ( F_33 ( V_11 , V_317 ) == true )
return V_143 ;
if ( V_308 -> V_14 != V_15 )
return - V_154 ;
V_314 = V_7 -> V_36 . V_148 ;
F_61 ( & V_305 -> V_318 , V_309 ) ;
V_311 = F_62 ( V_305 ) ;
V_11 -> V_319 = F_63 ( V_311 ) ;
while ( 1 ) {
if ( F_64 ( V_311 , V_11 -> V_319 ) == true )
break;
V_53 = F_65 ( V_11 -> V_319 ,
struct V_52 , V_320 ) ;
V_11 -> V_319 = F_63 ( V_11 -> V_319 ) ;
V_312 = V_53 -> V_18 . V_19 ;
if ( ! memcmp ( V_312 , V_308 -> V_16 , V_20 ) ) {
F_47 ( V_7 ,
V_53 -> V_18 . V_321 ) ;
break;
}
}
F_66 ( & V_305 -> V_318 , V_309 ) ;
if ( ! V_143 ) {
if ( ! F_67 ( V_7 , V_314 ) )
V_143 = - V_172 ;
else {
if ( ! F_68 ( V_7 , V_308 -> V_16 ) )
V_143 = - 1 ;
}
}
return V_143 ;
}
static int F_69 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
V_9 -> V_13 . V_14 = V_15 ;
if ( F_33 ( V_11 , V_219 | V_220 |
V_238 ) )
memcpy ( V_9 -> V_13 . V_16 , V_217 -> V_19 , V_20 ) ;
else
memset ( V_9 -> V_13 . V_16 , 0 , V_20 ) ;
return 0 ;
}
static int F_70 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
int V_143 = 0 ;
T_4 V_322 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_323 * V_324 = (struct V_323 * ) V_215 ;
if ( V_324 == NULL )
return - 1 ;
V_322 = F_71 ( V_324 -> V_325 ) ;
switch ( V_324 -> V_71 ) {
case V_326 :
if ( ! F_72 ( V_7 ) )
V_143 = - 1 ;
break;
case V_327 :
if ( ! F_72 ( V_7 ) )
V_143 = - 1 ;
break;
default:
return - V_179 ;
}
return V_143 ;
}
static int F_73 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_328 = true ;
if ( V_7 -> V_329 == true ) {
F_29 ( V_142 , L_31 ,
V_166 , V_7 -> V_329 ) ;
return - 1 ;
}
if ( V_7 -> V_330 == false )
return - V_331 ;
if ( V_7 -> V_332 == false )
return - 1 ;
if ( ( F_33 ( V_11 , V_315 | V_317 ) ) ||
( V_11 -> V_333 . V_334 == true ) )
return 0 ;
if ( V_9 -> V_74 . V_76 == sizeof( struct V_335 ) ) {
struct V_335 * V_336 = (struct V_335 * ) V_215 ;
if ( V_9 -> V_74 . V_75 & V_337 ) {
struct V_338 V_339 ;
unsigned long V_309 ;
T_3 V_287 = F_13 ( T_1 , V_336 -> V_340 , V_341 ) ;
memset ( ( unsigned char * ) & V_339 , 0 ,
sizeof( struct V_338 ) ) ;
memcpy ( V_339 . V_77 , V_336 -> V_342 , V_287 ) ;
V_339 . V_78 = V_287 ;
F_61 ( & V_11 -> V_318 , V_309 ) ;
if ( ( F_33 ( V_11 , V_315 |
V_317 ) ) ||
( V_11 -> V_333 . V_334 == true ) ) {
if ( F_33 ( V_11 , V_317 ) )
V_328 = false ;
} else
V_328 = F_74 ( V_7 , & V_339 ) ;
F_66 ( & V_11 -> V_318 , V_309 ) ;
}
} else
V_328 = F_75 ( V_7 ) ;
if ( V_328 == false )
return - 1 ;
return 0 ;
}
static int F_76 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_304 * V_305 = & V_11 -> V_306 ;
struct V_52 * V_53 = NULL ;
unsigned long V_309 ;
struct V_310 * V_343 , * V_311 ;
char * V_344 = V_215 ;
char * V_55 = V_344 + V_9 -> V_74 . V_76 ;
T_3 V_143 = 0 , V_210 = 0 ;
if ( V_7 -> V_329 )
return - V_154 ;
while ( F_33 ( V_11 , V_315 | V_317 ) ) {
F_77 ( 30 ) ;
V_210 ++ ;
if ( V_210 > 100 )
break;
}
F_61 ( & V_305 -> V_318 , V_309 ) ;
V_311 = F_62 ( V_305 ) ;
V_343 = F_63 ( V_311 ) ;
while ( 1 ) {
if ( F_64 ( V_311 , V_343 ) == true )
break;
if ( ( V_55 - V_344 ) < V_345 ) {
V_143 = - V_346 ;
break;
}
V_53 = F_65 ( V_343 , struct V_52 , V_320 ) ;
V_344 = F_11 ( V_7 , V_4 , V_53 , V_344 , V_55 ) ;
V_343 = F_63 ( V_343 ) ;
}
F_66 ( & V_305 -> V_318 , V_309 ) ;
V_9 -> V_74 . V_76 = V_344 - V_215 ;
V_9 -> V_74 . V_75 = 0 ;
return V_143 ;
}
static int F_78 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_304 * V_305 = & V_11 -> V_306 ;
struct V_52 * V_53 = NULL ;
enum V_313 V_314 ;
struct V_338 V_347 ;
T_1 * V_348 , * V_349 ;
struct V_310 * V_311 ;
T_3 V_287 ;
if ( F_33 ( V_11 , V_315 ) )
return - V_316 ;
if ( F_33 ( V_11 , V_317 ) )
return 0 ;
if ( V_9 -> V_342 . V_76 > V_341 )
return - V_346 ;
V_314 = V_7 -> V_36 . V_148 ;
if ( V_9 -> V_342 . V_75 && V_9 -> V_342 . V_76 ) {
V_287 = ( V_9 -> V_342 . V_76 < V_341 ) ?
V_9 -> V_342 . V_76 : V_341 ;
memset ( & V_347 , 0 , sizeof( struct V_338 ) ) ;
V_347 . V_78 = V_287 ;
memcpy ( V_347 . V_77 , V_215 , V_287 ) ;
V_349 = V_347 . V_77 ;
V_311 = F_62 ( V_305 ) ;
V_11 -> V_319 = F_63 ( V_311 ) ;
while ( 1 ) {
if ( F_64 ( V_311 , V_11 -> V_319 ) )
break;
V_53 = F_65 ( V_11 -> V_319 ,
struct V_52 , V_320 ) ;
V_11 -> V_319 = F_63 ( V_11 -> V_319 ) ;
V_348 = V_53 -> V_18 . V_77 . V_77 ;
if ( ( ! memcmp ( V_348 , V_349 , V_347 . V_78 ) )
&& ( V_53 -> V_18 . V_77 . V_78 ==
V_347 . V_78 ) ) {
if ( F_33 ( V_11 ,
V_237 ) ) {
if ( V_53 -> V_18 .
V_321
!=
V_7 -> V_12 .
V_17 . V_18 .
V_321 )
continue;
}
F_47 (
V_7 ,
V_53 -> V_18 . V_321 ) ;
break;
}
}
F_67 ( V_7 , V_314 ) ;
F_79 ( V_7 , & V_347 ) ;
}
return - V_303 ;
}
static int F_80 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
T_3 V_287 , V_143 = 0 ;
if ( F_33 ( V_11 , V_219 | V_220 ) ) {
V_287 = V_217 -> V_77 . V_78 ;
V_9 -> V_342 . V_76 = V_287 ;
memcpy ( V_215 , V_217 -> V_77 . V_77 , V_287 ) ;
V_9 -> V_342 . V_75 = 1 ;
} else {
V_143 = - V_228 ;
}
return V_143 ;
}
static int F_81 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
T_3 V_350 = V_9 -> V_114 . V_117 ;
T_3 V_115 = V_9 -> V_114 . V_115 ;
T_3 V_351 = 0 ;
T_1 V_352 [ V_353 ] ;
T_1 V_354 [ V_353 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
int V_3 , V_143 = 0 ;
if ( V_350 == - 1 ) {
V_351 = 11 ;
goto V_355;
}
V_350 = V_350 / 100000 ;
switch ( V_350 ) {
case 10 :
V_351 = 0 ;
break;
case 20 :
V_351 = 1 ;
break;
case 55 :
V_351 = 2 ;
break;
case 60 :
V_351 = 3 ;
break;
case 90 :
V_351 = 4 ;
break;
case 110 :
V_351 = 5 ;
break;
case 120 :
V_351 = 6 ;
break;
case 180 :
V_351 = 7 ;
break;
case 240 :
V_351 = 8 ;
break;
case 360 :
V_351 = 9 ;
break;
case 480 :
V_351 = 10 ;
break;
case 540 :
V_351 = 11 ;
break;
default:
V_351 = 11 ;
break;
}
V_355:
for ( V_3 = 0 ; V_3 < V_353 ; V_3 ++ ) {
if ( V_351 == V_354 [ V_3 ] ) {
V_352 [ V_3 ] = V_354 [ V_3 ] ;
if ( V_115 == 0 )
break;
} else
V_352 [ V_3 ] = 0xff ;
}
if ( F_82 ( V_7 , V_352 ) != V_198 )
V_143 = - V_172 ;
return V_143 ;
}
static int F_56 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
struct V_58 * V_59 ;
unsigned char V_356 = V_7 -> V_44 . V_357 ;
int V_3 ;
T_1 * V_61 ;
T_4 V_358 , V_359 = 0 , V_64 = false ;
T_3 V_62 = 0 ;
T_1 V_67 = 0 , V_68 = 0 ;
T_4 V_65 = 0 ;
V_3 = 0 ;
if ( F_33 ( V_11 , V_219 | V_220 ) ) {
V_61 = F_15 ( & V_217 -> V_79 [ 12 ] ,
V_80 , & V_62 ,
V_217 -> V_81 - 12 ) ;
if ( V_61 && V_62 > 0 ) {
V_64 = true ;
V_59 = (struct V_58 * ) ( V_61 + 2 ) ;
memcpy ( & V_65 , V_59 -> V_82 , 2 ) ;
V_67 = ( V_59 -> V_83 &
V_84 ) ? 1 : 0 ;
V_68 = ( V_59 -> V_83 &
( V_85 |
V_86 ) ) ? 1 : 0 ;
}
while ( ( V_217 -> V_88 [ V_3 ] != 0 ) &&
( V_217 -> V_88 [ V_3 ] != 0xFF ) ) {
V_358 = V_217 -> V_88 [ V_3 ] & 0x7F ;
if ( V_358 > V_359 )
V_359 = V_358 ;
V_9 -> V_114 . V_115 = 0 ;
V_9 -> V_114 . V_117 = V_358 * 500000 ;
V_3 ++ ;
}
if ( V_64 == true ) {
if ( V_65 & 0x8000
&&
V_360 == V_356 )
V_359 = ( V_67 ) ? ( ( V_68 ) ? 300 :
270 ) : ( ( V_68 ) ? 144 : 130 ) ;
else if ( V_65 & 0x0080 )
V_359 = ( V_67 ) ? ( ( V_68 ) ? 150 :
135 ) : ( ( V_68 ) ? 72 : 65 ) ;
else
V_359 = ( V_67 ) ? ( ( V_68 ) ? 150 :
135 ) : ( ( V_68 ) ? 72 : 65 ) ;
V_359 *= 2 ;
V_9 -> V_114 . V_117 = V_359 * 500000 ;
} else {
V_9 -> V_114 . V_117 = V_359 * 500000 ;
}
} else
return - V_228 ;
return 0 ;
}
static int F_83 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
V_9 -> V_361 . V_117 = V_7 -> V_44 . V_362 ;
V_9 -> V_361 . V_115 = 0 ;
return 0 ;
}
static int F_84 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
if ( V_9 -> V_363 . V_116 )
V_7 -> V_364 . V_365 = V_273 ;
else {
if ( V_9 -> V_363 . V_117 < V_271 ||
V_9 -> V_363 . V_117 > V_273 )
return - V_154 ;
V_7 -> V_364 . V_365 = V_9 -> V_363 . V_117 & ~ 0x1 ;
}
return 0 ;
}
static int F_85 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
V_9 -> V_363 . V_117 = V_7 -> V_364 . V_365 ;
V_9 -> V_363 . V_115 = 0 ;
return 0 ;
}
static int F_86 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
V_9 -> V_366 . V_117 = 7 ;
V_9 -> V_366 . V_115 = 0 ;
V_9 -> V_366 . V_116 = 1 ;
return 0 ;
}
static int F_87 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_367 )
{
T_3 V_31 ;
T_3 V_368 ;
struct V_158 V_369 ;
enum V_313 V_314 ;
struct V_289 * V_370 = & ( V_9 -> V_371 ) ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
V_31 = V_370 -> V_75 & V_372 ;
memset ( & V_369 , 0 , sizeof( struct V_158 ) ) ;
if ( V_370 -> V_75 & V_112 ) {
F_29 ( V_142 , L_32 , V_166 ) ;
V_7 -> V_36 . V_146 =
V_202 ;
V_7 -> V_36 . V_167 = V_201 ;
V_7 -> V_36 . V_169 = V_201 ;
V_7 -> V_36 . V_150 = 0 ;
V_314 = V_153 ;
V_7 -> V_36 . V_148 = V_314 ;
return 0 ;
}
if ( V_31 ) {
if ( V_31 > V_165 )
return - V_154 ;
V_31 -- ;
V_368 = 1 ;
} else {
V_368 = 0 ;
V_31 = V_7 -> V_36 . V_373 ;
}
if ( V_370 -> V_75 & V_374 ) {
F_29 ( V_142 , L_33 , V_166 ) ;
V_7 -> V_36 . V_146 =
V_147 ;
V_7 -> V_36 . V_150 = 0 ;
V_7 -> V_36 . V_167 = V_201 ;
V_7 -> V_36 . V_169 = V_201 ;
V_314 = V_153 ;
V_7 -> V_36 . V_148 = V_314 ;
} else if ( V_370 -> V_75 & V_375 ) {
F_29 ( V_142 , L_34 , V_166 ) ;
V_7 -> V_36 . V_146 =
V_147 ;
V_7 -> V_36 . V_150 = 1 ;
V_7 -> V_36 . V_167 = V_168 ;
V_7 -> V_36 . V_169 = V_168 ;
V_314 = V_151 ;
V_7 -> V_36 . V_148 = V_314 ;
} else {
V_7 -> V_36 . V_146 =
V_147 ;
V_7 -> V_36 . V_150 = 0 ;
V_7 -> V_36 . V_167 = V_201 ;
V_7 -> V_36 . V_169 = V_201 ;
V_314 = V_153 ;
V_7 -> V_36 . V_148 = V_314 ;
}
V_369 . V_176 = V_31 ;
if ( V_370 -> V_76 > 0 ) {
V_369 . V_173 = V_370 -> V_76 <= 5 ? 5 : 13 ;
V_369 . V_174 = V_369 . V_173 +
F_31 ( struct V_158 , V_170 ) ;
} else {
V_369 . V_173 = 0 ;
if ( V_368 == 1 ) {
V_7 -> V_36 . V_373 = V_31 ;
switch ( V_7 -> V_36 . V_181 [ V_31 ] ) {
case 5 :
V_7 -> V_36 . V_167 =
V_168 ;
break;
case 13 :
V_7 -> V_36 . V_167 =
V_175 ;
break;
default:
V_7 -> V_36 . V_167 =
V_201 ;
break;
}
return 0 ;
}
}
V_369 . V_176 |= 0x80000000 ;
memcpy ( V_369 . V_170 , V_367 , V_369 . V_173 ) ;
if ( F_32 ( V_7 , & V_369 ) == V_178 )
return - V_179 ;
return 0 ;
}
static int F_88 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_367 )
{
T_6 V_31 , V_143 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_289 * V_370 = & ( V_9 -> V_371 ) ;
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
if ( F_33 ( V_11 , V_219 ) == false ) {
if ( ! F_33 ( V_11 , V_220 ) ) {
V_370 -> V_76 = 0 ;
V_370 -> V_75 |= V_112 ;
return 0 ;
}
}
V_31 = V_370 -> V_75 & V_372 ;
if ( V_31 ) {
if ( V_31 > V_165 )
return - V_154 ;
V_31 -- ;
} else {
V_31 = V_7 -> V_36 . V_373 ;
}
V_370 -> V_75 = V_31 + 1 ;
switch ( V_7 -> V_36 . V_146 ) {
case V_376 :
case V_202 :
V_370 -> V_76 = 0 ;
V_370 -> V_75 |= V_112 ;
break;
case V_147 :
V_370 -> V_76 = V_7 -> V_36 . V_181 [ V_31 ] ;
if ( V_370 -> V_76 ) {
memcpy ( V_367 , V_7 -> V_36 . V_180 [
V_31 ] . V_28 , V_7 -> V_36 .
V_181 [ V_31 ] ) ;
V_370 -> V_75 |= V_110 ;
if ( V_7 -> V_36 . V_148 ==
V_153 )
V_370 -> V_75 |= V_374 ;
else if ( V_7 -> V_36 . V_148 ==
V_151 )
V_370 -> V_75 |= V_375 ;
} else {
V_370 -> V_76 = 0 ;
V_370 -> V_75 |= V_112 ;
}
break;
case V_189 :
case V_190 :
V_370 -> V_76 = 16 ;
V_370 -> V_75 |= ( V_110 | V_374 |
V_111 ) ;
break;
default:
V_370 -> V_76 = 0 ;
V_370 -> V_75 |= V_112 ;
break;
}
return V_143 ;
}
static int F_89 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
V_9 -> V_377 . V_117 = 0 ;
V_9 -> V_377 . V_115 = 0 ;
V_9 -> V_377 . V_116 = 1 ;
return 0 ;
}
static int F_90 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
return F_38 ( V_7 , V_215 , V_9 -> V_74 . V_76 ) ;
}
static int F_91 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_378 * V_26 = (struct V_378 * ) & ( V_9 -> V_26 ) ;
int V_379 ;
int V_380 ;
int V_143 = 0 ;
V_379 = V_26 -> V_75 & V_381 ;
V_380 = V_26 -> V_117 ;
switch ( V_379 ) {
case V_382 :
break;
case V_383 :
break;
case V_384 :
break;
case V_385 :
break;
case V_386 :
if ( V_380 ) {
V_7 -> V_36 . V_387 = true ;
} else {
V_7 -> V_36 . V_387 = false ;
}
break;
case V_388 :
if ( V_7 -> V_36 . V_146 ==
V_147 ) {
break;
}
if ( V_380 ) {
V_7 -> V_36 . V_146 =
V_202 ;
V_7 -> V_36 . V_167 =
V_201 ;
V_7 -> V_36 . V_169 =
V_201 ;
V_7 -> V_36 . V_150 = 0 ;
V_7 -> V_36 . V_148 =
V_153 ;
}
break;
case V_389 :
V_143 = F_25 ( V_142 , ( T_3 ) V_380 ) ;
break;
case V_390 :
break;
case V_391 :
break;
case V_392 :
break;
default:
return - V_179 ;
}
return V_143 ;
}
static int F_92 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_289 * V_393 = & V_9 -> V_371 ;
struct V_394 * V_395 = (struct V_394 * ) V_215 ;
struct V_25 * V_26 = NULL ;
char * V_396 ;
T_3 V_155 ;
int V_143 = 0 ;
switch ( V_395 -> V_33 ) {
case V_397 :
V_396 = L_35 ;
break;
case V_398 :
V_396 = L_11 ;
break;
case V_399 :
V_396 = L_1 ;
break;
case V_400 :
V_396 = L_36 ;
break;
default:
return - V_154 ;
}
V_155 = sizeof( struct V_25 ) + V_395 -> V_32 ;
V_26 = F_93 ( V_155 , V_171 ) ;
if ( V_26 == NULL )
return - V_172 ;
V_26 -> V_71 = V_401 ;
memset ( V_26 -> V_164 , 0xff , V_20 ) ;
strncpy ( ( char * ) V_26 -> V_29 . V_30 . V_33 , V_396 , V_163 ) ;
if ( V_395 -> V_402 & V_403 )
V_26 -> V_29 . V_30 . V_177 = 0 ;
if ( V_395 -> V_402 & V_404 )
V_26 -> V_29 . V_30 . V_177 = 1 ;
V_26 -> V_29 . V_30 . V_39 = ( V_393 -> V_75 & 0x00FF ) - 1 ;
if ( V_395 -> V_402 & V_405 )
memcpy ( V_26 -> V_29 . V_30 . V_406 , V_395 -> V_407 , 8 ) ;
if ( V_395 -> V_32 ) {
V_26 -> V_29 . V_30 . V_32 = V_395 -> V_32 ;
memcpy ( V_26 + 1 , V_395 + 1 , V_395 -> V_32 ) ;
}
V_143 = F_27 ( V_142 , V_26 , V_155 ) ;
F_37 ( V_26 ) ;
return V_143 ;
}
static int F_94 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
if ( V_215 ) {
V_9 -> V_74 . V_76 = 8 ;
V_9 -> V_74 . V_75 = 1 ;
memcpy ( V_215 , L_37 , 8 ) ;
}
return 0 ;
}
static int F_95 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_367 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
T_3 V_2 ;
T_3 V_408 ;
F_96 ( V_2 , ( T_3 V_409 * ) V_9 -> V_74 . V_291 ) ;
V_408 = F_97 ( V_7 , V_2 ) ;
F_98 ( V_408 , ( T_3 V_409 * ) V_9 -> V_74 . V_291 ) ;
V_9 -> V_74 . V_76 = ( V_408 & 0xffff0000 ) >> 16 ;
V_9 -> V_74 . V_75 = V_408 & 0xffff ;
F_96 ( V_2 , ( T_3 V_409 * ) V_9 -> V_74 . V_291 ) ;
return 0 ;
}
static int F_99 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_367 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
T_3 V_2 ;
T_3 V_408 ;
F_96 ( V_2 , ( T_3 V_409 * ) V_9 -> V_74 . V_291 ) ;
V_408 = ( ( T_3 ) V_9 -> V_74 . V_76 << 16 ) | ( T_3 ) V_9 -> V_74 . V_75 ;
F_100 ( V_7 , V_2 , V_408 ) ;
return 0 ;
}
static int F_101 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
return - V_410 ;
}
static int F_102 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
return 0 ;
}
static int F_103 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_289 * V_61 = & V_9 -> V_74 ;
struct V_411 V_412 ;
struct V_413 * V_414 ;
struct V_415 * V_416 ;
unsigned long V_417 , V_418 , V_419 ;
T_1 * V_420 = NULL , V_421 ;
T_4 V_287 ;
T_6 V_328 ;
int V_143 = 0 ;
if ( ( ! V_61 -> V_76 ) || ( ! V_61 -> V_291 ) ) {
V_143 = - V_154 ;
goto V_422;
}
V_421 = ( T_1 ) ( V_61 -> V_75 & 0xFFFF ) ;
V_287 = V_61 -> V_76 ;
V_420 = NULL ;
V_420 = F_30 ( V_287 , V_171 ) ;
if ( V_420 == NULL ) {
V_143 = - V_172 ;
goto V_422;
}
if ( F_104 ( V_420 , V_61 -> V_291 , V_287 ) ) {
V_143 = - V_302 ;
goto V_422;
}
V_416 = (struct V_415 * ) V_420 ;
if ( V_416 -> V_423 >= V_424 ) {
V_143 = - V_154 ;
goto V_422;
}
V_414 = V_425 + V_416 -> V_423 ;
if ( ( V_414 -> V_426 != 0 ) &&
( V_416 -> V_287 < V_414 -> V_426 ) ) {
V_143 = - V_154 ;
goto V_422;
}
if ( V_414 -> V_427 == 0 && V_414 -> V_428 )
V_328 = V_414 -> V_428 ( & V_412 ) ;
else if ( V_414 -> V_428 ) {
V_412 . V_429 = V_7 ;
V_412 . V_427 = V_414 -> V_427 ;
V_412 . V_430 = V_416 -> V_74 ;
V_412 . V_431 = V_416 -> V_287 ;
V_412 . V_432 = 0 ;
V_418 = 0 ;
V_419 = 0 ;
if ( V_421 ) {
V_412 . V_433 = & V_417 ;
V_412 . V_434 = & V_419 ;
V_412 . V_435 = V_436 ;
} else {
V_412 . V_433 = & V_418 ;
V_412 . V_434 = & V_419 ;
V_412 . V_435 = V_437 ;
}
V_328 = V_414 -> V_428 ( & V_412 ) ;
} else {
F_29 ( V_142 , L_38 ,
V_166 , V_416 -> V_423 , V_414 -> V_427 ,
V_414 -> V_428 ) ;
V_143 = - V_302 ;
goto V_422;
}
if ( V_421 == 0x00 ) {
if ( F_58 ( V_61 -> V_291 , V_420 , V_287 ) )
V_143 = - V_302 ;
}
if ( V_328 ) {
V_143 = - V_302 ;
goto V_422;
}
V_422:
F_37 ( V_420 ) ;
return V_143 ;
}
static int F_105 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_304 * V_305 = & V_11 -> V_306 ;
struct V_289 * V_438 = & V_9 -> V_74 ;
struct V_52 * V_53 = NULL ;
T_3 V_210 = 0 , V_439 ;
unsigned long V_309 ;
struct V_310 * V_343 , * V_311 ;
unsigned char * V_440 ;
T_1 V_246 [ V_20 ] ;
char V_74 [ 32 ] ;
if ( V_7 -> V_329 || ( V_438 == NULL ) )
return - V_154 ;
while ( F_33 ( V_11 , V_315 | V_317 ) ) {
F_77 ( 30 ) ;
V_210 ++ ;
if ( V_210 > 100 )
break;
}
V_438 -> V_75 = 0 ;
if ( V_438 -> V_76 >= 32 ) {
if ( F_104 ( V_74 , V_438 -> V_291 , 32 ) )
return - V_154 ;
} else
return - V_154 ;
F_61 ( & ( V_11 -> V_306 . V_318 ) , V_309 ) ;
V_311 = F_62 ( V_305 ) ;
V_343 = F_63 ( V_311 ) ;
while ( 1 ) {
if ( F_64 ( V_311 , V_343 ) == true )
break;
V_53 = F_65 ( V_343 , struct V_52 , V_320 ) ;
if ( F_1 ( V_74 , V_246 ) ) {
F_29 ( V_142 , L_39 ,
( T_1 * ) V_74 ) ;
F_66 ( & ( V_11 -> V_306 . V_318 ) ,
V_309 ) ;
return - V_154 ;
}
F_29 ( V_142 , L_40 , V_246 ) ;
if ( ! memcmp ( V_246 , V_53 -> V_18 . V_19 , V_20 ) ) {
V_440 = F_106 ( & V_53 -> V_18 . V_79 [ 12 ] ,
& V_439 , V_53 -> V_18 . V_81 - 12 ) ;
if ( V_440 && ( V_439 > 0 ) ) {
V_438 -> V_75 = 1 ;
break;
}
V_440 = F_107 ( & V_53 -> V_18 . V_79 [ 12 ] ,
& V_439 , V_53 -> V_18 . V_81 - 12 ) ;
if ( V_440 && ( V_439 > 0 ) ) {
V_438 -> V_75 = 2 ;
break;
}
}
V_343 = F_63 ( V_343 ) ;
}
F_66 ( & ( V_11 -> V_306 . V_318 ) , V_309 ) ;
if ( V_438 -> V_76 >= 34 ) {
if ( F_58 ( ( T_1 V_409 * ) V_438 -> V_291 + 32 ,
( T_1 * ) & V_438 -> V_75 , 1 ) )
return - V_154 ;
}
return 0 ;
}
static int F_108 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_289 * V_438 = & V_9 -> V_74 ;
if ( ( V_7 -> V_329 ) || ( V_438 == NULL ) )
return - V_154 ;
if ( F_104 ( & V_7 -> V_441 , V_438 -> V_291 , sizeof( int ) ) )
return - V_154 ;
return 0 ;
}
static int F_109 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
int V_143 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_289 * V_438 = & V_9 -> V_74 ;
int V_442 = - 1 ;
if ( ( V_7 -> V_329 ) || ( V_438 == NULL ) ) {
V_143 = - V_154 ;
goto exit;
}
V_442 = ( int ) * V_215 ;
F_110 ( V_7 , V_442 ) ;
exit:
return V_143 ;
}
static int F_111 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_289 * V_438 = & V_9 -> V_74 ;
T_3 V_443 = 0 ;
if ( ( V_7 -> V_329 ) || ( V_438 == NULL ) )
return - V_154 ;
if ( F_104 ( ( void * ) & V_443 , V_438 -> V_291 , 4 ) )
return - V_302 ;
if ( V_443 == 0 )
V_443 = * V_215 ;
if ( V_443 == 1 )
V_7 -> V_444 . V_445 ( V_7 ,
V_446 ) ;
else if ( V_443 == 2 )
V_7 -> V_444 . V_445 ( V_7 ,
V_447 ) ;
else if ( V_443 == 3 )
V_7 -> V_444 . V_445 ( V_7 ,
V_448 ) ;
return 0 ;
}
static int F_112 ( struct V_141 * V_142 , T_1 V_89 , T_3 V_117 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
switch ( V_89 ) {
case V_449 :
V_7 -> V_36 . V_150 = 2 ;
switch ( ( V_117 ) & 0xff ) {
case 1 :
V_7 -> V_36 . V_148 =
V_152 ;
V_7 -> V_36 . V_146 =
V_189 ;
break;
case 2 :
V_7 -> V_36 . V_148 =
V_199 ;
V_7 -> V_36 . V_146 =
V_190 ;
break;
}
break;
case V_450 :
break;
case V_451 :
break;
case V_452 :
break;
case V_453 :
return F_25 ( V_142 , V_117 ) ;
break;
case V_454 :
break;
case V_455 :
break;
default:
return - V_179 ;
}
return 0 ;
}
static int F_113 ( struct V_141 * V_142 , T_3 V_456 , T_3 V_322 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
switch ( V_456 ) {
case V_457 :
if ( ! F_72 ( V_7 ) )
return - 1 ;
break;
case V_458 :
if ( ! F_72 ( V_7 ) )
return - 1 ;
break;
default:
return - V_179 ;
}
return 0 ;
}
static int F_114 ( struct V_141 * V_142 , struct V_289 * V_61 )
{
struct V_25 * V_26 ;
int V_143 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
if ( V_61 -> V_76 < sizeof( struct V_25 ) || ! V_61 -> V_291 )
return - V_154 ;
V_26 = F_53 ( V_61 -> V_291 , V_61 -> V_76 ) ;
if ( F_54 ( V_26 ) )
return F_55 ( V_26 ) ;
switch ( V_26 -> V_71 ) {
case V_459 :
V_143 = F_112 ( V_142 , V_26 -> V_29 . V_460 . V_89 ,
V_26 -> V_29 . V_460 . V_117 ) ;
break;
case V_461 :
V_143 = F_38 ( V_7 , ( char * ) V_26 -> V_29 . V_121 . V_74 ,
( T_4 ) V_26 -> V_29 . V_121 . V_287 ) ;
break;
case V_401 :
V_143 = F_27 ( V_142 , V_26 , V_61 -> V_76 ) ;
break;
case V_462 :
V_143 = F_113 ( V_142 , V_26 -> V_29 . V_324 . V_456 ,
V_26 -> V_29 . V_324 . V_325 ) ;
break;
default:
V_143 = - V_179 ;
break;
}
if ( V_143 == 0 && F_58 ( V_61 -> V_291 , V_26 , V_61 -> V_76 ) )
V_143 = - V_302 ;
F_37 ( ( T_1 * ) V_26 ) ;
return V_143 ;
}
int F_115 ( struct V_141 * V_142 , struct V_463 * V_464 , int V_71 )
{
struct V_465 * V_466 = (struct V_465 * ) V_464 ;
switch ( V_71 ) {
case V_467 :
return F_114 ( V_142 , & V_466 -> V_29 . V_74 ) ;
default:
return - V_179 ;
}
return 0 ;
}
static struct V_468 * F_116 ( struct V_141 * V_142 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_468 * V_469 = & V_7 -> V_470 ;
int V_471 = 0 ;
int V_472 = 0 ;
int V_473 = 0 ;
if ( F_33 ( & V_7 -> V_12 , V_219 ) != true ) {
V_469 -> V_133 . V_133 = 0 ;
V_469 -> V_133 . V_138 = 0 ;
V_469 -> V_133 . V_139 = 0 ;
} else {
V_471 = V_7 -> V_293 . V_294 ;
V_472 = V_7 -> V_293 . signal ;
V_473 = V_7 -> V_293 . V_139 ;
V_469 -> V_133 . V_138 = V_471 ;
V_469 -> V_133 . V_133 = V_472 ;
V_469 -> V_133 . V_139 = V_473 ;
}
V_469 -> V_133 . V_134 = V_474 ;
return & V_7 -> V_470 ;
}
