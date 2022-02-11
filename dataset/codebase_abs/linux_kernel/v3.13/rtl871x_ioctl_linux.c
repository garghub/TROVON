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
V_159 = (struct V_158 * ) F_30 ( ( T_3 )
( V_157 +
F_31 ( struct V_158 ,
V_170 ) ) ) ;
if ( V_159 == NULL )
return - V_171 ;
memset ( V_159 , 0 , sizeof( struct V_158 ) ) ;
V_159 -> V_172 = V_157 ;
V_159 -> V_173 = V_157 +
F_31 ( struct V_158 ,
V_170 ) ;
if ( V_157 == 13 ) {
V_7 -> V_36 . V_167 =
V_174 ;
V_7 -> V_36 . V_169 =
V_174 ;
}
} else
return - V_154 ;
V_159 -> V_175 = V_156 ;
V_159 -> V_175 |= 0x80000000 ;
memcpy ( V_159 -> V_170 , V_26 -> V_29 . V_30 . V_31 , V_159 -> V_172 ) ;
if ( V_26 -> V_29 . V_30 . V_176 ) {
if ( F_32 ( V_7 , V_159 ) ==
( T_1 ) V_177 )
V_143 = - V_178 ;
} else {
if ( V_156 >= V_165 ) {
V_143 = - V_178 ;
goto exit;
}
memcpy ( & ( V_161 -> V_179 [ V_156 ] .
V_28 [ 0 ] ) , V_159 -> V_170 ,
V_159 -> V_172 ) ;
V_161 -> V_180 [ V_156 ] =
V_159 -> V_172 ;
F_10 ( V_7 , V_161 , V_156 ) ;
}
goto exit;
}
if ( V_7 -> V_36 . V_150 == 2 ) {
struct V_23 * V_24 , * V_181 ;
struct V_182 * V_183 = & V_7 -> V_184 ;
if ( F_33 ( V_11 , V_185 |
V_186 ) == true ) {
V_24 = F_34 ( V_183 ,
F_35 ( V_11 ) ) ;
if ( V_24 ) {
V_24 -> V_187 = false ;
if ( ( V_7 -> V_36 . V_146 ==
V_188 ) ||
( V_7 -> V_36 . V_146 ==
V_189 ) )
V_24 -> V_190 = V_7 ->
V_36 . V_167 ;
if ( V_26 -> V_29 . V_30 . V_176 == 1 )
F_6 ( V_24 , V_26 ,
V_7 ) ;
else
F_9 ( V_26 , V_7 ) ;
}
V_181 = F_36 ( V_7 ) ;
if ( V_181 ) {
V_181 -> V_187 = false ;
if ( ( V_7 -> V_36 . V_146 ==
V_188 ) ||
( V_7 -> V_36 . V_146 ==
V_189 ) )
V_181 -> V_190 =
V_7 -> V_36 .
V_167 ;
}
}
}
exit:
F_37 ( ( T_1 * ) V_159 ) ;
return V_143 ;
}
static int F_38 ( struct V_6 * V_7 , char * V_191 ,
unsigned short V_192 )
{
T_1 * V_119 = NULL , * V_193 = NULL ;
int V_194 = 0 , V_195 = 0 ;
int V_143 = 0 ;
if ( ( V_192 > V_120 ) || ( V_191 == NULL ) )
return - V_154 ;
if ( V_192 ) {
V_119 = F_30 ( V_192 ) ;
if ( V_119 == NULL )
return - V_171 ;
memcpy ( V_119 , V_191 , V_192 ) ;
V_193 = V_119 ;
if ( V_192 < V_196 ) {
V_143 = - V_154 ;
goto exit;
}
if ( F_39 ( V_119 , V_192 , & V_194 ,
& V_195 ) == V_197 ) {
V_7 -> V_36 . V_150 = 2 ;
V_7 -> V_36 . V_148 =
V_152 ;
}
if ( F_40 ( V_119 , V_192 , & V_194 ,
& V_195 ) == V_197 ) {
V_7 -> V_36 . V_150 = 2 ;
V_7 -> V_36 . V_148 =
V_198 ;
}
switch ( V_194 ) {
case V_199 :
V_7 -> V_36 . V_169 =
V_200 ;
V_7 -> V_36 . V_146 =
V_201 ;
break;
case V_202 :
V_7 -> V_36 . V_169 = V_168 ;
V_7 -> V_36 . V_146 =
V_147 ;
break;
case V_203 :
V_7 -> V_36 . V_169 = V_204 ;
V_7 -> V_36 . V_146 =
V_188 ;
break;
case V_205 :
V_7 -> V_36 . V_169 = V_206 ;
V_7 -> V_36 . V_146 =
V_189 ;
break;
case V_207 :
V_7 -> V_36 . V_169 = V_174 ;
V_7 -> V_36 . V_146 =
V_147 ;
break;
}
switch ( V_195 ) {
case V_199 :
V_7 -> V_36 . V_167 =
V_200 ;
V_7 -> V_36 . V_146 =
V_201 ;
break;
case V_202 :
V_7 -> V_36 . V_167 = V_168 ;
V_7 -> V_36 . V_146 =
V_147 ;
break;
case V_203 :
V_7 -> V_36 . V_167 = V_204 ;
V_7 -> V_36 . V_146 =
V_188 ;
break;
case V_205 :
V_7 -> V_36 . V_167 = V_206 ;
V_7 -> V_36 . V_146 =
V_189 ;
break;
case V_207 :
V_7 -> V_36 . V_167 = V_174 ;
V_7 -> V_36 . V_146 =
V_147 ;
break;
}
V_7 -> V_36 . V_208 = false ;
{
T_4 V_209 = 0 ;
T_1 V_210 , V_211 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_209 < V_192 ) {
V_210 = V_119 [ V_209 ] ;
if ( ( V_210 == V_212 ) &&
( ! memcmp ( & V_119 [ V_209 + 2 ] , V_211 , 4 ) ) ) {
F_29 ( V_7 -> V_21 , L_13 ) ;
V_7 -> V_36 . V_213 =
( ( V_119 [ V_209 + 1 ] + 2 ) <
( V_120 << 2 ) ) ?
( V_119 [ V_209 + 1 ] + 2 ) :
( V_120 << 2 ) ;
memcpy ( V_7 -> V_36 . V_129 ,
& V_119 [ V_209 ] ,
V_7 -> V_36 . V_213 ) ;
V_7 -> V_36 . V_208 =
true ;
F_29 ( V_7 -> V_21 , L_14 ) ;
V_209 += V_119 [ V_209 + 1 ] + 2 ;
break;
} else
V_209 += V_119 [ V_209 + 1 ] + 2 ;
}
}
}
exit:
F_37 ( V_119 ) ;
return V_143 ;
}
static int F_41 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
T_3 V_62 = 0 ;
char * V_61 ;
T_1 V_64 = false ;
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
struct V_215 * V_216 = & V_11 -> V_17 . V_18 ;
T_7 * V_217 = NULL ;
if ( F_33 ( V_11 , V_218 | V_219 ) ==
true ) {
V_61 = F_15 ( & V_216 -> V_79 [ 12 ] , V_80 ,
& V_62 , V_216 -> V_81 - 12 ) ;
if ( V_61 && V_62 > 0 )
V_64 = true ;
V_217 = & V_216 -> V_88 ;
if ( F_16 ( ( T_1 * ) V_217 ) == true ) {
if ( V_64 == true )
snprintf ( V_9 -> V_89 , V_90 ,
L_2 ) ;
else
snprintf ( V_9 -> V_89 , V_90 ,
L_3 ) ;
} else if ( ( F_17 ( ( T_1 * ) V_217 ) ) == true ) {
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
static int F_42 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_220 * V_221 = & V_9 -> V_102 ;
int V_222 = 0 ;
if ( ( V_221 -> V_105 == 1 ) &&
( V_221 -> V_103 >= ( int ) 2.412e8 ) &&
( V_221 -> V_103 <= ( int ) 2.487e8 ) ) {
int V_223 = V_221 -> V_103 / 100000 ;
int V_224 = 0 ;
while ( ( V_224 < 14 ) && ( V_223 != V_225 [ V_224 ] ) )
V_224 ++ ;
V_221 -> V_105 = 0 ;
V_221 -> V_103 = V_224 + 1 ;
}
if ( ( V_221 -> V_103 > 14 ) || ( V_221 -> V_105 > 0 ) )
V_222 = - V_178 ;
else {
int V_226 = V_221 -> V_103 ;
if ( ( V_226 < 1 ) || ( V_226 > 14 ) )
V_222 = - V_154 ;
else {
V_7 -> V_44 . V_226 = V_226 ;
}
}
return V_222 ;
}
static int F_43 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_215 * V_216 = & V_11 -> V_17 . V_18 ;
if ( F_33 ( V_11 , V_218 ) == true ) {
V_9 -> V_102 . V_103 = V_101 [
V_216 -> V_69 . V_70 - 1 ] * 100000 ;
V_9 -> V_102 . V_105 = 1 ;
V_9 -> V_102 . V_3 = V_216 -> V_69 . V_70 ;
} else {
return - V_227 ;
}
return 0 ;
}
static int F_44 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
enum V_228 V_229 ;
switch ( V_9 -> V_95 ) {
case V_230 :
V_229 = V_231 ;
break;
case V_97 :
V_229 = V_232 ;
break;
case V_96 :
V_229 = V_233 ;
break;
case V_234 :
V_229 = V_235 ;
break;
default:
return - V_154 ;
}
if ( V_233 == V_229 )
F_45 ( V_7 , V_229 ) ;
else
F_45 ( V_7 , V_231 ) ;
F_46 ( V_7 , V_229 ) ;
return 0 ;
}
static int F_47 ( struct V_141 * V_142 , struct V_50 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
if ( F_33 ( V_11 , V_185 ) == true )
V_9 -> V_95 = V_234 ;
else if ( F_33 ( V_11 ,
V_219 | V_236 ) == true )
V_9 -> V_95 = V_97 ;
else if ( F_33 ( V_11 , V_237 ) == true )
V_9 -> V_95 = V_96 ;
else
V_9 -> V_95 = V_230 ;
return 0 ;
}
static int F_48 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_160 * V_161 = & V_7 -> V_36 ;
struct V_238 * V_239 = (struct V_238 * ) V_214 ;
T_1 V_240 [ V_20 ] = { 0x00 } ;
T_1 V_241 [ V_20 ] = { 0x00 } ;
T_1 V_242 , V_243 = false ;
int V_244 = false ;
if ( V_239 == NULL )
return - V_154 ;
memcpy ( V_241 , V_239 -> V_245 . V_16 , V_20 ) ;
switch ( V_239 -> V_71 ) {
case V_246 :
if ( ! memcmp ( V_241 , V_240 , V_20 ) )
return V_244 ;
else
V_244 = true ;
V_243 = false ;
for ( V_242 = 0 ; V_242 < V_247 ; V_242 ++ ) {
if ( ! memcmp ( V_161 -> V_248 [ V_242 ] . V_249 ,
V_241 , V_20 ) ) {
F_29 ( V_142 , L_16 ,
V_166 ) ;
memcpy ( V_161 -> V_248 [ V_242 ] . V_250 ,
V_239 -> V_251 , V_252 ) ;
V_161 -> V_248 [ V_242 ] . V_253 = true ;
V_161 -> V_254 = V_242 + 1 ;
V_243 = true ;
break;
}
}
if ( ! V_243 ) {
F_29 ( V_142 , L_17 ,
V_166 , V_161 -> V_254 ) ;
memcpy ( V_161 -> V_248 [ V_161 ->
V_254 ] . V_249 , V_241 , V_20 ) ;
memcpy ( V_161 -> V_248 [ V_161 ->
V_254 ] . V_250 , V_239 -> V_251 , V_252 ) ;
V_161 -> V_248 [ V_161 -> V_254 ] .
V_253 = true ;
V_161 -> V_254 ++ ;
if ( V_161 -> V_254 == V_247 )
V_161 -> V_254 = 0 ;
}
break;
case V_255 :
V_244 = true ;
for ( V_242 = 0 ; V_242 < V_247 ; V_242 ++ ) {
if ( ! memcmp ( V_161 -> V_248 [ V_242 ] . V_249 ,
V_241 , V_20 ) ) {
memset ( V_161 -> V_248 [ V_242 ] . V_249 ,
0x00 , V_20 ) ;
V_161 -> V_248 [ V_242 ] . V_253 = false ;
break;
}
}
break;
case V_256 :
memset ( V_161 -> V_248 , 0 ,
sizeof( struct V_257 ) * V_247 ) ;
V_161 -> V_254 = 0 ;
V_244 = true ;
break;
default:
F_29 ( V_142 , L_18 , V_166 ) ;
V_244 = false ;
break;
}
return V_244 ;
}
static int F_49 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
V_9 -> V_258 . V_117 = 0 ;
V_9 -> V_258 . V_115 = 0 ;
V_9 -> V_258 . V_116 = 1 ;
return 0 ;
}
static int F_50 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_259 * V_260 = (struct V_259 * ) V_214 ;
T_4 V_261 ;
int V_3 ;
V_9 -> V_74 . V_76 = sizeof( * V_260 ) ;
memset ( V_260 , 0 , sizeof( * V_260 ) ) ;
V_260 -> V_262 = 5 * 1000 * 1000 ;
V_260 -> V_263 . V_133 = 100 ;
V_260 -> V_263 . V_138 = 100 ;
V_260 -> V_263 . V_139 = 100 ;
V_260 -> V_263 . V_134 = 7 ;
V_260 -> V_264 . V_133 = 92 ;
V_260 -> V_264 . V_138 = 20 + - 98 ;
V_260 -> V_264 . V_139 = 0 ;
V_260 -> V_264 . V_134 = 7 ;
V_260 -> V_265 = V_266 ;
for ( V_3 = 0 ; V_3 < V_266 && V_3 < V_267 ; V_3 ++ )
V_260 -> V_114 [ V_3 ] = V_268 [ V_3 ] ;
V_260 -> V_269 = V_270 ;
V_260 -> V_271 = V_272 ;
V_260 -> V_273 = 0 ;
V_260 -> V_274 = V_275 ;
V_260 -> V_276 = 16 ;
V_260 -> V_277 = 14 ;
for ( V_3 = 0 , V_261 = 0 ; V_3 < 14 ; V_3 ++ ) {
V_260 -> V_102 [ V_261 ] . V_3 = V_3 + 1 ;
V_260 -> V_102 [ V_261 ] . V_103 = V_101 [ V_3 ] * 100000 ;
V_260 -> V_102 [ V_261 ] . V_105 = 1 ;
V_261 ++ ;
if ( V_261 == V_278 )
break;
}
V_260 -> V_279 = V_261 ;
V_260 -> V_280 = V_281 |
V_282 |
V_283 |
V_284 ;
return 0 ;
}
static int F_51 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_285 ,
char * V_214 )
{
int V_143 = 0 , V_286 = 0 ;
char * V_287 ;
struct V_6 * V_7 = F_26 ( V_142 ) ;
struct V_288 * V_289 = (struct V_288 * ) V_285 ;
V_286 = V_289 -> V_76 ;
V_287 = F_30 ( V_286 ) ;
if ( ! V_287 )
return - V_171 ;
if ( F_52 ( V_287 , V_289 -> V_290 , V_286 ) ) {
F_37 ( V_287 ) ;
return - V_291 ;
}
if ( 0 == strcasecmp ( V_287 , L_19 ) ) {
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
struct V_52 * V_292 = & V_11 -> V_17 ;
if ( F_33 ( V_11 , V_218 ) == true ) {
sprintf ( V_287 , L_20 ,
V_292 -> V_18 . V_77 . V_77 ,
( ( V_7 -> V_293 . V_294 ) >> 1 ) - 95
) ;
} else {
sprintf ( V_287 , L_21 ) ;
}
} else if ( 0 == strcasecmp ( V_287 , L_22 ) ) {
union V_8 V_295 ;
int V_296 ;
int V_297 ;
V_296 = F_53 ( V_142 , V_51 , & V_295 , V_214 ) ;
if ( 0 != V_296 )
V_297 = 0 ;
else
V_297 = V_295 . V_114 . V_117 / 1000000 ;
sprintf ( V_287 , L_23 , V_297 ) ;
} else if ( 0 == strcasecmp ( V_287 , L_24 ) ) {
sprintf ( V_287 , L_25 , V_142 -> V_298 ) ;
} else if ( 0 == strcasecmp ( V_287 , L_26 ) ) {
struct V_10 * V_11 = & V_7 -> V_12 ;
V_11 -> V_299 = 1 ;
sprintf ( V_287 , L_21 ) ;
} else if ( 0 == strcasecmp ( V_287 , L_27 ) ) {
struct V_10 * V_11 = & V_7 -> V_12 ;
V_11 -> V_299 = 0 ;
sprintf ( V_287 , L_21 ) ;
} else if ( 0 == strncmp ( V_287 , L_28 , 5 ) ) {
F_54 ( V_7
, 1
, 5
, 100
, 5000
) ;
sprintf ( V_287 , L_21 ) ;
} else if ( 0 == strncmp ( V_287 , L_29 , 5 ) ) {
F_54 ( V_7
, 0
, 5
, 100
, 5000
) ;
sprintf ( V_287 , L_21 ) ;
} else {
F_29 ( V_142 , L_30 ,
V_166 , V_287 ) ;
goto V_300;
}
if ( F_55 ( V_289 -> V_290 , V_287 ,
F_56 ( V_289 -> V_76 , ( V_301 ) ( strlen ( V_287 ) + 1 ) ) ) )
V_143 = - V_291 ;
V_300:
F_37 ( V_287 ) ;
return V_143 ;
}
static int F_57 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_285 ,
char * V_214 )
{
int V_143 = - V_302 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_303 * V_304 = & V_11 -> V_305 ;
struct V_306 * V_307 = (struct V_306 * ) V_285 ;
unsigned long V_308 ;
struct V_309 * V_310 ;
T_1 * V_311 ;
struct V_52 * V_53 = NULL ;
enum V_312 V_313 ;
if ( F_33 ( V_11 , V_314 ) == true )
return - V_315 ;
if ( F_33 ( V_11 , V_316 ) == true )
return V_143 ;
if ( V_307 -> V_14 != V_15 )
return - V_154 ;
V_313 = V_7 -> V_36 . V_148 ;
F_58 ( & V_304 -> V_317 , V_308 ) ;
V_310 = F_59 ( V_304 ) ;
V_11 -> V_318 = F_60 ( V_310 ) ;
while ( 1 ) {
if ( F_61 ( V_310 , V_11 -> V_318 ) == true )
break;
V_53 = F_62 ( V_11 -> V_318 ,
struct V_52 , V_319 ) ;
V_11 -> V_318 = F_60 ( V_11 -> V_318 ) ;
V_311 = V_53 -> V_18 . V_19 ;
if ( ! memcmp ( V_311 , V_307 -> V_16 , V_20 ) ) {
F_46 ( V_7 ,
V_53 -> V_18 . V_320 ) ;
break;
}
}
F_63 ( & V_304 -> V_317 , V_308 ) ;
if ( ! V_143 ) {
if ( ! F_64 ( V_7 , V_313 ) )
V_143 = - V_171 ;
else {
if ( ! F_65 ( V_7 , V_307 -> V_16 ) )
V_143 = - 1 ;
}
}
return V_143 ;
}
static int F_66 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_215 * V_216 = & V_11 -> V_17 . V_18 ;
V_9 -> V_13 . V_14 = V_15 ;
if ( F_33 ( V_11 , V_218 | V_219 |
V_237 ) )
memcpy ( V_9 -> V_13 . V_16 , V_216 -> V_19 , V_20 ) ;
else
memset ( V_9 -> V_13 . V_16 , 0 , V_20 ) ;
return 0 ;
}
static int F_67 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
int V_143 = 0 ;
T_4 V_321 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_322 * V_323 = (struct V_322 * ) V_214 ;
if ( V_323 == NULL )
return - 1 ;
V_321 = F_68 ( V_323 -> V_324 ) ;
switch ( V_323 -> V_71 ) {
case V_325 :
if ( ! F_69 ( V_7 ) )
V_143 = - 1 ;
break;
case V_326 :
if ( ! F_69 ( V_7 ) )
V_143 = - 1 ;
break;
default:
return - V_178 ;
}
return V_143 ;
}
static int F_70 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_327 = true ;
if ( V_7 -> V_328 == true ) {
F_29 ( V_142 , L_31 ,
V_166 , V_7 -> V_328 ) ;
return - 1 ;
}
if ( V_7 -> V_329 == false )
return - V_330 ;
if ( V_7 -> V_331 == false )
return - 1 ;
if ( ( F_33 ( V_11 , V_314 | V_316 ) ) ||
( V_11 -> V_332 . V_333 == true ) )
return 0 ;
if ( V_9 -> V_74 . V_76 == sizeof( struct V_334 ) ) {
struct V_334 * V_335 = (struct V_334 * ) V_214 ;
if ( V_9 -> V_74 . V_75 & V_336 ) {
struct V_337 V_338 ;
unsigned long V_308 ;
T_3 V_286 = F_13 ( T_1 , V_335 -> V_339 , V_340 ) ;
memset ( ( unsigned char * ) & V_338 , 0 ,
sizeof( struct V_337 ) ) ;
memcpy ( V_338 . V_77 , V_335 -> V_341 , V_286 ) ;
V_338 . V_78 = V_286 ;
F_58 ( & V_11 -> V_317 , V_308 ) ;
if ( ( F_33 ( V_11 , V_314 |
V_316 ) ) ||
( V_11 -> V_332 . V_333 == true ) ) {
if ( F_33 ( V_11 , V_316 ) )
V_327 = false ;
} else
V_327 = F_71 ( V_7 , & V_338 ) ;
F_63 ( & V_11 -> V_317 , V_308 ) ;
}
} else
V_327 = F_72 ( V_7 ) ;
if ( V_327 == false )
return - 1 ;
return 0 ;
}
static int F_73 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_303 * V_304 = & V_11 -> V_305 ;
struct V_52 * V_53 = NULL ;
unsigned long V_308 ;
struct V_309 * V_342 , * V_310 ;
char * V_343 = V_214 ;
char * V_55 = V_343 + V_9 -> V_74 . V_76 ;
T_3 V_143 = 0 , V_209 = 0 ;
if ( V_7 -> V_328 )
return - V_154 ;
while ( F_33 ( V_11 , V_314 | V_316 ) ) {
F_74 ( 30 ) ;
V_209 ++ ;
if ( V_209 > 100 )
break;
}
F_58 ( & V_304 -> V_317 , V_308 ) ;
V_310 = F_59 ( V_304 ) ;
V_342 = F_60 ( V_310 ) ;
while ( 1 ) {
if ( F_61 ( V_310 , V_342 ) == true )
break;
if ( ( V_55 - V_343 ) < V_344 ) {
V_143 = - V_345 ;
break;
}
V_53 = F_62 ( V_342 , struct V_52 , V_319 ) ;
V_343 = F_11 ( V_7 , V_4 , V_53 , V_343 , V_55 ) ;
V_342 = F_60 ( V_342 ) ;
}
F_63 ( & V_304 -> V_317 , V_308 ) ;
V_9 -> V_74 . V_76 = V_343 - V_214 ;
V_9 -> V_74 . V_75 = 0 ;
return V_143 ;
}
static int F_75 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_303 * V_304 = & V_11 -> V_305 ;
struct V_52 * V_53 = NULL ;
enum V_312 V_313 ;
struct V_337 V_346 ;
T_1 * V_347 , * V_348 ;
struct V_309 * V_310 ;
T_3 V_286 ;
if ( F_33 ( V_11 , V_314 ) )
return - V_315 ;
if ( F_33 ( V_11 , V_316 ) )
return 0 ;
if ( V_9 -> V_341 . V_76 > V_340 )
return - V_345 ;
V_313 = V_7 -> V_36 . V_148 ;
if ( V_9 -> V_341 . V_75 && V_9 -> V_341 . V_76 ) {
V_286 = ( V_9 -> V_341 . V_76 < V_340 ) ?
V_9 -> V_341 . V_76 : V_340 ;
memset ( & V_346 , 0 , sizeof( struct V_337 ) ) ;
V_346 . V_78 = V_286 ;
memcpy ( V_346 . V_77 , V_214 , V_286 ) ;
V_348 = V_346 . V_77 ;
V_310 = F_59 ( V_304 ) ;
V_11 -> V_318 = F_60 ( V_310 ) ;
while ( 1 ) {
if ( F_61 ( V_310 , V_11 -> V_318 ) )
break;
V_53 = F_62 ( V_11 -> V_318 ,
struct V_52 , V_319 ) ;
V_11 -> V_318 = F_60 ( V_11 -> V_318 ) ;
V_347 = V_53 -> V_18 . V_77 . V_77 ;
if ( ( ! memcmp ( V_347 , V_348 , V_346 . V_78 ) )
&& ( V_53 -> V_18 . V_77 . V_78 ==
V_346 . V_78 ) ) {
if ( F_33 ( V_11 ,
V_236 ) ) {
if ( V_53 -> V_18 .
V_320
!=
V_7 -> V_12 .
V_17 . V_18 .
V_320 )
continue;
}
F_46 (
V_7 ,
V_53 -> V_18 . V_320 ) ;
break;
}
}
F_64 ( V_7 , V_313 ) ;
F_76 ( V_7 , & V_346 ) ;
}
return - V_302 ;
}
static int F_77 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_215 * V_216 = & V_11 -> V_17 . V_18 ;
T_3 V_286 , V_143 = 0 ;
if ( F_33 ( V_11 , V_218 | V_219 ) ) {
V_286 = V_216 -> V_77 . V_78 ;
V_9 -> V_341 . V_76 = V_286 ;
memcpy ( V_214 , V_216 -> V_77 . V_77 , V_286 ) ;
V_9 -> V_341 . V_75 = 1 ;
} else {
V_143 = - V_227 ;
}
return V_143 ;
}
static int F_78 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
T_3 V_349 = V_9 -> V_114 . V_117 ;
T_3 V_115 = V_9 -> V_114 . V_115 ;
T_3 V_350 = 0 ;
T_1 V_351 [ V_352 ] ;
T_1 V_353 [ V_352 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
int V_3 , V_143 = 0 ;
if ( V_349 == - 1 ) {
V_350 = 11 ;
goto V_354;
}
V_349 = V_349 / 100000 ;
switch ( V_349 ) {
case 10 :
V_350 = 0 ;
break;
case 20 :
V_350 = 1 ;
break;
case 55 :
V_350 = 2 ;
break;
case 60 :
V_350 = 3 ;
break;
case 90 :
V_350 = 4 ;
break;
case 110 :
V_350 = 5 ;
break;
case 120 :
V_350 = 6 ;
break;
case 180 :
V_350 = 7 ;
break;
case 240 :
V_350 = 8 ;
break;
case 360 :
V_350 = 9 ;
break;
case 480 :
V_350 = 10 ;
break;
case 540 :
V_350 = 11 ;
break;
default:
V_350 = 11 ;
break;
}
V_354:
for ( V_3 = 0 ; V_3 < V_352 ; V_3 ++ ) {
if ( V_350 == V_353 [ V_3 ] ) {
V_351 [ V_3 ] = V_353 [ V_3 ] ;
if ( V_115 == 0 )
break;
} else
V_351 [ V_3 ] = 0xff ;
}
if ( F_79 ( V_7 , V_351 ) != V_197 )
V_143 = - V_171 ;
return V_143 ;
}
static int F_53 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_215 * V_216 = & V_11 -> V_17 . V_18 ;
struct V_58 * V_59 ;
unsigned char V_355 = V_7 -> V_44 . V_356 ;
int V_3 ;
T_1 * V_61 ;
T_4 V_357 , V_358 = 0 , V_64 = false ;
T_3 V_62 = 0 ;
T_1 V_67 = 0 , V_68 = 0 ;
T_4 V_65 = 0 ;
V_3 = 0 ;
if ( F_33 ( V_11 , V_218 | V_219 ) ) {
V_61 = F_15 ( & V_216 -> V_79 [ 12 ] ,
V_80 , & V_62 ,
V_216 -> V_81 - 12 ) ;
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
while ( ( V_216 -> V_88 [ V_3 ] != 0 ) &&
( V_216 -> V_88 [ V_3 ] != 0xFF ) ) {
V_357 = V_216 -> V_88 [ V_3 ] & 0x7F ;
if ( V_357 > V_358 )
V_358 = V_357 ;
V_9 -> V_114 . V_115 = 0 ;
V_9 -> V_114 . V_117 = V_357 * 500000 ;
V_3 ++ ;
}
if ( V_64 == true ) {
if ( V_65 & 0x8000
&&
V_359 == V_355 )
V_358 = ( V_67 ) ? ( ( V_68 ) ? 300 :
270 ) : ( ( V_68 ) ? 144 : 130 ) ;
else if ( V_65 & 0x0080 )
V_358 = ( V_67 ) ? ( ( V_68 ) ? 150 :
135 ) : ( ( V_68 ) ? 72 : 65 ) ;
else
V_358 = ( V_67 ) ? ( ( V_68 ) ? 150 :
135 ) : ( ( V_68 ) ? 72 : 65 ) ;
V_358 *= 2 ;
V_9 -> V_114 . V_117 = V_358 * 500000 ;
} else {
V_9 -> V_114 . V_117 = V_358 * 500000 ;
}
} else
return - V_227 ;
return 0 ;
}
static int F_80 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
V_9 -> V_360 . V_117 = V_7 -> V_44 . V_361 ;
V_9 -> V_360 . V_115 = 0 ;
return 0 ;
}
static int F_81 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
if ( V_9 -> V_362 . V_116 )
V_7 -> V_363 . V_364 = V_272 ;
else {
if ( V_9 -> V_362 . V_117 < V_270 ||
V_9 -> V_362 . V_117 > V_272 )
return - V_154 ;
V_7 -> V_363 . V_364 = V_9 -> V_362 . V_117 & ~ 0x1 ;
}
return 0 ;
}
static int F_82 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
V_9 -> V_362 . V_117 = V_7 -> V_363 . V_364 ;
V_9 -> V_362 . V_115 = 0 ;
return 0 ;
}
static int F_83 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
V_9 -> V_365 . V_117 = 7 ;
V_9 -> V_365 . V_115 = 0 ;
V_9 -> V_365 . V_116 = 1 ;
return 0 ;
}
static int F_84 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_366 )
{
T_3 V_31 ;
T_3 V_367 ;
struct V_158 V_368 ;
enum V_312 V_313 ;
struct V_288 * V_369 = & ( V_9 -> V_370 ) ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
V_31 = V_369 -> V_75 & V_371 ;
memset ( & V_368 , 0 , sizeof( struct V_158 ) ) ;
if ( V_369 -> V_75 & V_112 ) {
F_29 ( V_142 , L_32 , V_166 ) ;
V_7 -> V_36 . V_146 =
V_201 ;
V_7 -> V_36 . V_167 = V_200 ;
V_7 -> V_36 . V_169 = V_200 ;
V_7 -> V_36 . V_150 = 0 ;
V_313 = V_153 ;
V_7 -> V_36 . V_148 = V_313 ;
return 0 ;
}
if ( V_31 ) {
if ( V_31 > V_165 )
return - V_154 ;
V_31 -- ;
V_367 = 1 ;
} else {
V_367 = 0 ;
V_31 = V_7 -> V_36 . V_372 ;
}
if ( V_369 -> V_75 & V_373 ) {
F_29 ( V_142 , L_33 , V_166 ) ;
V_7 -> V_36 . V_146 =
V_147 ;
V_7 -> V_36 . V_150 = 0 ;
V_7 -> V_36 . V_167 = V_200 ;
V_7 -> V_36 . V_169 = V_200 ;
V_313 = V_153 ;
V_7 -> V_36 . V_148 = V_313 ;
} else if ( V_369 -> V_75 & V_374 ) {
F_29 ( V_142 , L_34 , V_166 ) ;
V_7 -> V_36 . V_146 =
V_147 ;
V_7 -> V_36 . V_150 = 1 ;
V_7 -> V_36 . V_167 = V_168 ;
V_7 -> V_36 . V_169 = V_168 ;
V_313 = V_151 ;
V_7 -> V_36 . V_148 = V_313 ;
} else {
V_7 -> V_36 . V_146 =
V_147 ;
V_7 -> V_36 . V_150 = 0 ;
V_7 -> V_36 . V_167 = V_200 ;
V_7 -> V_36 . V_169 = V_200 ;
V_313 = V_153 ;
V_7 -> V_36 . V_148 = V_313 ;
}
V_368 . V_175 = V_31 ;
if ( V_369 -> V_76 > 0 ) {
V_368 . V_172 = V_369 -> V_76 <= 5 ? 5 : 13 ;
V_368 . V_173 = V_368 . V_172 +
F_31 ( struct V_158 , V_170 ) ;
} else {
V_368 . V_172 = 0 ;
if ( V_367 == 1 ) {
V_7 -> V_36 . V_372 = V_31 ;
switch ( V_7 -> V_36 . V_180 [ V_31 ] ) {
case 5 :
V_7 -> V_36 . V_167 =
V_168 ;
break;
case 13 :
V_7 -> V_36 . V_167 =
V_174 ;
break;
default:
V_7 -> V_36 . V_167 =
V_200 ;
break;
}
return 0 ;
}
}
V_368 . V_175 |= 0x80000000 ;
memcpy ( V_368 . V_170 , V_366 , V_368 . V_172 ) ;
if ( F_32 ( V_7 , & V_368 ) == V_177 )
return - V_178 ;
return 0 ;
}
static int F_85 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_366 )
{
T_6 V_31 , V_143 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_288 * V_369 = & ( V_9 -> V_370 ) ;
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
if ( F_33 ( V_11 , V_218 ) == false ) {
if ( ! F_33 ( V_11 , V_219 ) ) {
V_369 -> V_76 = 0 ;
V_369 -> V_75 |= V_112 ;
return 0 ;
}
}
V_31 = V_369 -> V_75 & V_371 ;
if ( V_31 ) {
if ( V_31 > V_165 )
return - V_154 ;
V_31 -- ;
} else {
V_31 = V_7 -> V_36 . V_372 ;
}
V_369 -> V_75 = V_31 + 1 ;
switch ( V_7 -> V_36 . V_146 ) {
case V_375 :
case V_201 :
V_369 -> V_76 = 0 ;
V_369 -> V_75 |= V_112 ;
break;
case V_147 :
V_369 -> V_76 = V_7 -> V_36 . V_180 [ V_31 ] ;
if ( V_369 -> V_76 ) {
memcpy ( V_366 , V_7 -> V_36 . V_179 [
V_31 ] . V_28 , V_7 -> V_36 .
V_180 [ V_31 ] ) ;
V_369 -> V_75 |= V_110 ;
if ( V_7 -> V_36 . V_148 ==
V_153 )
V_369 -> V_75 |= V_373 ;
else if ( V_7 -> V_36 . V_148 ==
V_151 )
V_369 -> V_75 |= V_374 ;
} else {
V_369 -> V_76 = 0 ;
V_369 -> V_75 |= V_112 ;
}
break;
case V_188 :
case V_189 :
V_369 -> V_76 = 16 ;
V_369 -> V_75 |= ( V_110 | V_373 |
V_111 ) ;
break;
default:
V_369 -> V_76 = 0 ;
V_369 -> V_75 |= V_112 ;
break;
}
return V_143 ;
}
static int F_86 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
V_9 -> V_376 . V_117 = 0 ;
V_9 -> V_376 . V_115 = 0 ;
V_9 -> V_376 . V_116 = 1 ;
return 0 ;
}
static int F_87 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
return F_38 ( V_7 , V_214 , V_9 -> V_74 . V_76 ) ;
}
static int F_88 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_377 * V_26 = (struct V_377 * ) & ( V_9 -> V_26 ) ;
int V_378 ;
int V_379 ;
int V_143 = 0 ;
V_378 = V_26 -> V_75 & V_380 ;
V_379 = V_26 -> V_117 ;
switch ( V_378 ) {
case V_381 :
break;
case V_382 :
break;
case V_383 :
break;
case V_384 :
break;
case V_385 :
if ( V_379 ) {
V_7 -> V_36 . V_386 = true ;
} else {
V_7 -> V_36 . V_386 = false ;
}
break;
case V_387 :
if ( V_7 -> V_36 . V_146 ==
V_147 ) {
break;
}
if ( V_379 ) {
V_7 -> V_36 . V_146 =
V_201 ;
V_7 -> V_36 . V_167 =
V_200 ;
V_7 -> V_36 . V_169 =
V_200 ;
V_7 -> V_36 . V_150 = 0 ;
V_7 -> V_36 . V_148 =
V_153 ;
}
break;
case V_388 :
V_143 = F_25 ( V_142 , ( T_3 ) V_379 ) ;
break;
case V_389 :
break;
case V_390 :
break;
case V_391 :
break;
default:
return - V_178 ;
}
return V_143 ;
}
static int F_89 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_288 * V_392 = & V_9 -> V_370 ;
struct V_393 * V_394 = (struct V_393 * ) V_214 ;
struct V_25 * V_26 = NULL ;
char * V_395 ;
T_3 V_155 ;
int V_143 = 0 ;
V_155 = sizeof( struct V_25 ) + V_394 -> V_32 ;
V_26 = (struct V_25 * ) F_30 ( V_155 ) ;
if ( V_26 == NULL )
return - V_171 ;
memset ( V_26 , 0 , V_155 ) ;
V_26 -> V_71 = V_396 ;
memset ( V_26 -> V_164 , 0xff , V_20 ) ;
switch ( V_394 -> V_33 ) {
case V_397 :
V_395 = L_35 ;
break;
case V_398 :
V_395 = L_11 ;
break;
case V_399 :
V_395 = L_1 ;
break;
case V_400 :
V_395 = L_36 ;
break;
default:
return - V_154 ;
}
strncpy ( ( char * ) V_26 -> V_29 . V_30 . V_33 , V_395 , V_163 ) ;
if ( V_394 -> V_401 & V_402 )
V_26 -> V_29 . V_30 . V_176 = 0 ;
if ( V_394 -> V_401 & V_403 )
V_26 -> V_29 . V_30 . V_176 = 1 ;
V_26 -> V_29 . V_30 . V_39 = ( V_392 -> V_75 & 0x00FF ) - 1 ;
if ( V_394 -> V_401 & V_404 )
memcpy ( V_26 -> V_29 . V_30 . V_405 , V_394 -> V_406 , 8 ) ;
if ( V_394 -> V_32 ) {
V_26 -> V_29 . V_30 . V_32 = V_394 -> V_32 ;
memcpy ( V_26 + 1 , V_394 + 1 , V_394 -> V_32 ) ;
}
V_143 = F_27 ( V_142 , V_26 , V_155 ) ;
F_37 ( V_26 ) ;
return V_143 ;
}
static int F_90 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
if ( V_214 ) {
V_9 -> V_74 . V_76 = 8 ;
V_9 -> V_74 . V_75 = 1 ;
memcpy ( V_214 , L_37 , 8 ) ;
}
return 0 ;
}
static int F_91 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_366 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
T_3 V_2 ;
T_3 V_407 ;
F_92 ( V_2 , ( T_3 V_408 * ) V_9 -> V_74 . V_290 ) ;
V_407 = F_93 ( V_7 , V_2 ) ;
F_94 ( V_407 , ( T_3 V_408 * ) V_9 -> V_74 . V_290 ) ;
V_9 -> V_74 . V_76 = ( V_407 & 0xffff0000 ) >> 16 ;
V_9 -> V_74 . V_75 = V_407 & 0xffff ;
F_92 ( V_2 , ( T_3 V_408 * ) V_9 -> V_74 . V_290 ) ;
return 0 ;
}
static int F_95 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_366 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
T_3 V_2 ;
T_3 V_407 ;
F_92 ( V_2 , ( T_3 V_408 * ) V_9 -> V_74 . V_290 ) ;
V_407 = ( ( T_3 ) V_9 -> V_74 . V_76 << 16 ) | ( T_3 ) V_9 -> V_74 . V_75 ;
F_96 ( V_7 , V_2 , V_407 ) ;
return 0 ;
}
static int F_97 ( struct V_141 * V_142 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
return - V_409 ;
}
static int F_98 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
return 0 ;
}
static int F_99 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_288 * V_61 = & V_9 -> V_74 ;
struct V_410 V_411 ;
struct V_412 * V_413 ;
struct V_414 * V_415 ;
unsigned long V_416 , V_417 , V_418 ;
T_1 * V_419 = NULL , V_420 ;
T_4 V_286 ;
T_6 V_327 ;
int V_143 = 0 ;
if ( ( ! V_61 -> V_76 ) || ( ! V_61 -> V_290 ) ) {
V_143 = - V_154 ;
goto V_421;
}
V_420 = ( T_1 ) ( V_61 -> V_75 & 0xFFFF ) ;
V_286 = V_61 -> V_76 ;
V_419 = NULL ;
V_419 = ( T_1 * ) F_30 ( V_286 ) ;
if ( V_419 == NULL ) {
V_143 = - V_171 ;
goto V_421;
}
if ( F_52 ( V_419 , V_61 -> V_290 , V_286 ) ) {
V_143 = - V_291 ;
goto V_421;
}
V_415 = (struct V_414 * ) V_419 ;
if ( V_415 -> V_422 >= V_423 ) {
V_143 = - V_154 ;
goto V_421;
}
V_413 = V_424 + V_415 -> V_422 ;
if ( ( V_413 -> V_425 != 0 ) &&
( V_415 -> V_286 < V_413 -> V_425 ) ) {
V_143 = - V_154 ;
goto V_421;
}
if ( V_413 -> V_426 == 0 && V_413 -> V_427 )
V_327 = V_413 -> V_427 ( & V_411 ) ;
else if ( V_413 -> V_427 ) {
V_411 . V_428 = V_7 ;
V_411 . V_426 = V_413 -> V_426 ;
V_411 . V_429 = V_415 -> V_74 ;
V_411 . V_430 = V_415 -> V_286 ;
V_411 . V_431 = 0 ;
V_417 = 0 ;
V_418 = 0 ;
if ( V_420 ) {
V_411 . V_432 = & V_416 ;
V_411 . V_433 = & V_418 ;
V_411 . V_434 = V_435 ;
} else {
V_411 . V_432 = & V_417 ;
V_411 . V_433 = & V_418 ;
V_411 . V_434 = V_436 ;
}
V_327 = V_413 -> V_427 ( & V_411 ) ;
} else {
F_29 ( V_142 , L_38 ,
V_166 , V_415 -> V_422 , V_413 -> V_426 ,
V_413 -> V_427 ) ;
V_143 = - V_291 ;
goto V_421;
}
if ( V_420 == 0x00 ) {
if ( F_55 ( V_61 -> V_290 , V_419 , V_286 ) )
V_143 = - V_291 ;
}
if ( V_327 ) {
V_143 = - V_291 ;
goto V_421;
}
V_421:
F_37 ( V_419 ) ;
return V_143 ;
}
static int F_100 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_303 * V_304 = & V_11 -> V_305 ;
struct V_288 * V_437 = & V_9 -> V_74 ;
struct V_52 * V_53 = NULL ;
T_3 V_209 = 0 , V_438 ;
unsigned long V_308 ;
struct V_309 * V_342 , * V_310 ;
unsigned char * V_439 ;
T_1 V_245 [ V_20 ] ;
char V_74 [ 32 ] ;
if ( V_7 -> V_328 || ( V_437 == NULL ) )
return - V_154 ;
while ( F_33 ( V_11 , V_314 | V_316 ) ) {
F_74 ( 30 ) ;
V_209 ++ ;
if ( V_209 > 100 )
break;
}
V_437 -> V_75 = 0 ;
if ( V_437 -> V_76 >= 32 ) {
if ( F_52 ( V_74 , V_437 -> V_290 , 32 ) )
return - V_154 ;
} else
return - V_154 ;
F_58 ( & ( V_11 -> V_305 . V_317 ) , V_308 ) ;
V_310 = F_59 ( V_304 ) ;
V_342 = F_60 ( V_310 ) ;
while ( 1 ) {
if ( F_61 ( V_310 , V_342 ) == true )
break;
V_53 = F_62 ( V_342 , struct V_52 , V_319 ) ;
if ( F_1 ( V_74 , V_245 ) ) {
F_29 ( V_142 , L_39 ,
( T_1 * ) V_74 ) ;
F_63 ( & ( V_11 -> V_305 . V_317 ) ,
V_308 ) ;
return - V_154 ;
}
F_29 ( V_142 , L_40 , V_245 ) ;
if ( ! memcmp ( V_245 , V_53 -> V_18 . V_19 , V_20 ) ) {
V_439 = F_101 ( & V_53 -> V_18 . V_79 [ 12 ] ,
& V_438 , V_53 -> V_18 . V_81 - 12 ) ;
if ( V_439 && ( V_438 > 0 ) ) {
V_437 -> V_75 = 1 ;
break;
}
V_439 = F_102 ( & V_53 -> V_18 . V_79 [ 12 ] ,
& V_438 , V_53 -> V_18 . V_81 - 12 ) ;
if ( V_439 && ( V_438 > 0 ) ) {
V_437 -> V_75 = 2 ;
break;
}
}
V_342 = F_60 ( V_342 ) ;
}
F_63 ( & ( V_11 -> V_305 . V_317 ) , V_308 ) ;
if ( V_437 -> V_76 >= 34 ) {
if ( F_55 ( ( T_1 V_408 * ) V_437 -> V_290 + 32 ,
( T_1 * ) & V_437 -> V_75 , 1 ) )
return - V_154 ;
}
return 0 ;
}
static int F_103 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_288 * V_437 = & V_9 -> V_74 ;
if ( ( V_7 -> V_328 ) || ( V_437 == NULL ) )
return - V_154 ;
if ( F_52 ( & V_7 -> V_440 , V_437 -> V_290 , sizeof( int ) ) )
return - V_154 ;
return 0 ;
}
static int F_104 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
int V_143 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_288 * V_437 = & V_9 -> V_74 ;
int V_441 = - 1 ;
if ( ( V_7 -> V_328 ) || ( V_437 == NULL ) ) {
V_143 = - V_154 ;
goto exit;
}
V_441 = ( int ) * V_214 ;
F_105 ( V_7 , V_441 ) ;
exit:
return V_143 ;
}
static int F_106 ( struct V_141 * V_142 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_214 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_288 * V_437 = & V_9 -> V_74 ;
T_3 V_442 = 0 ;
if ( ( V_7 -> V_328 ) || ( V_437 == NULL ) )
return - V_154 ;
if ( F_52 ( ( void * ) & V_442 , V_437 -> V_290 , 4 ) )
return - V_291 ;
if ( V_442 == 0 )
V_442 = * V_214 ;
if ( V_442 == 1 )
V_7 -> V_443 . V_444 ( V_7 ,
V_445 ) ;
else if ( V_442 == 2 )
V_7 -> V_443 . V_444 ( V_7 ,
V_446 ) ;
else if ( V_442 == 3 )
V_7 -> V_443 . V_444 ( V_7 ,
V_447 ) ;
return 0 ;
}
static int F_107 ( struct V_141 * V_142 , T_1 V_89 , T_3 V_117 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
switch ( V_89 ) {
case V_448 :
V_7 -> V_36 . V_150 = 2 ;
switch ( ( V_117 ) & 0xff ) {
case 1 :
V_7 -> V_36 . V_148 =
V_152 ;
V_7 -> V_36 . V_146 =
V_188 ;
break;
case 2 :
V_7 -> V_36 . V_148 =
V_198 ;
V_7 -> V_36 . V_146 =
V_189 ;
break;
}
break;
case V_449 :
break;
case V_450 :
break;
case V_451 :
break;
case V_452 :
return F_25 ( V_142 , V_117 ) ;
break;
case V_453 :
break;
case V_454 :
break;
default:
return - V_178 ;
}
return 0 ;
}
static int F_108 ( struct V_141 * V_142 , T_3 V_455 , T_3 V_321 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
switch ( V_455 ) {
case V_456 :
if ( ! F_69 ( V_7 ) )
return - 1 ;
break;
case V_457 :
if ( ! F_69 ( V_7 ) )
return - 1 ;
break;
default:
return - V_178 ;
}
return 0 ;
}
static int F_109 ( struct V_141 * V_142 , struct V_288 * V_61 )
{
struct V_25 * V_26 ;
int V_143 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
if ( V_61 -> V_76 < sizeof( struct V_25 ) || ! V_61 -> V_290 )
return - V_154 ;
V_26 = (struct V_25 * ) F_30 ( V_61 -> V_76 ) ;
if ( V_26 == NULL )
return - V_171 ;
if ( F_52 ( V_26 , V_61 -> V_290 , V_61 -> V_76 ) ) {
F_37 ( ( T_1 * ) V_26 ) ;
return - V_291 ;
}
switch ( V_26 -> V_71 ) {
case V_458 :
V_143 = F_107 ( V_142 , V_26 -> V_29 . V_459 . V_89 ,
V_26 -> V_29 . V_459 . V_117 ) ;
break;
case V_460 :
V_143 = F_38 ( V_7 , ( char * ) V_26 -> V_29 . V_121 . V_74 ,
( T_4 ) V_26 -> V_29 . V_121 . V_286 ) ;
break;
case V_396 :
V_143 = F_27 ( V_142 , V_26 , V_61 -> V_76 ) ;
break;
case V_461 :
V_143 = F_108 ( V_142 , V_26 -> V_29 . V_323 . V_455 ,
V_26 -> V_29 . V_323 . V_324 ) ;
break;
default:
V_143 = - V_178 ;
break;
}
if ( V_143 == 0 && F_55 ( V_61 -> V_290 , V_26 , V_61 -> V_76 ) )
V_143 = - V_291 ;
F_37 ( ( T_1 * ) V_26 ) ;
return V_143 ;
}
int F_110 ( struct V_141 * V_142 , struct V_462 * V_463 , int V_71 )
{
struct V_464 * V_465 = (struct V_464 * ) V_463 ;
switch ( V_71 ) {
case V_466 :
return F_109 ( V_142 , & V_465 -> V_29 . V_74 ) ;
default:
return - V_178 ;
}
return 0 ;
}
static struct V_467 * F_111 ( struct V_141 * V_142 )
{
struct V_6 * V_7 = (struct V_6 * ) F_26 ( V_142 ) ;
struct V_467 * V_468 = & V_7 -> V_469 ;
int V_470 = 0 ;
int V_471 = 0 ;
int V_472 = 0 ;
if ( F_33 ( & V_7 -> V_12 , V_218 ) != true ) {
V_468 -> V_133 . V_133 = 0 ;
V_468 -> V_133 . V_138 = 0 ;
V_468 -> V_133 . V_139 = 0 ;
} else {
V_470 = V_7 -> V_293 . V_294 ;
V_471 = V_7 -> V_293 . signal ;
V_472 = V_7 -> V_293 . V_139 ;
V_468 -> V_133 . V_138 = V_470 ;
V_468 -> V_133 . V_133 = V_471 ;
V_468 -> V_133 . V_139 = V_472 ;
}
V_468 -> V_133 . V_134 = V_473 ;
return & V_7 -> V_469 ;
}
