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
T_1 * V_61 = ( T_1 * ) F_12 ( V_53 -> V_18 . V_62 * 2 ) ;
T_1 * V_63 = ( T_1 * ) F_12 ( 255 ) ;
T_1 * V_64 = ( T_1 * ) F_12 ( 255 ) ;
T_1 * V_65 = ( T_1 * ) F_12 ( V_66 ) ;
T_2 * V_67 ;
T_3 V_3 = 0 , V_68 = 0 ;
T_4 V_69 , V_70 = false , V_71 ;
T_1 V_72 , V_73 = 0 , V_74 = 0 ;
if ( ( V_53 -> V_18 . V_75 . V_76 < 1 ) ||
( V_53 -> V_18 . V_75 . V_76 > 14 ) ) {
if ( V_53 -> V_18 . V_75 . V_76 < 1 )
V_53 -> V_18 . V_75 . V_76 = 1 ;
else
V_53 -> V_18 . V_75 . V_76 = 14 ;
}
V_57 . V_77 = V_22 ;
V_57 . V_29 . V_13 . V_14 = V_15 ;
memcpy ( V_57 . V_29 . V_13 . V_16 , V_53 -> V_18 . V_19 , V_20 ) ;
V_54 = F_13 ( V_51 , V_54 , V_55 , & V_57 , V_78 ) ;
V_57 . V_77 = V_79 ;
V_57 . V_29 . V_80 . V_81 = 1 ;
V_57 . V_29 . V_80 . V_82 = ( T_4 ) F_14 ( ( T_4 ) V_53 -> V_18 . V_83 . V_84 ,
( T_4 ) 32 ) ;
V_54 = F_15 ( V_51 , V_54 , V_55 , & V_57 ,
V_53 -> V_18 . V_83 . V_83 ) ;
V_67 = F_16 ( & V_53 -> V_18 . V_85 [ 12 ] , V_86 ,
& V_68 , V_53 -> V_18 . V_62 - 12 ) ;
if ( V_67 && V_68 > 0 ) {
V_70 = true ;
V_59 = (struct V_58 * ) ( V_67 + 2 ) ;
memcpy ( & V_71 , V_59 -> V_87 , 2 ) ;
V_73 = ( V_59 -> V_88 & V_89 )
? 1 : 0 ;
V_74 = ( V_59 -> V_88 & ( V_90 |
V_91 ) ) ? 1 : 0 ;
}
V_57 . V_77 = V_92 ;
if ( ( F_17 ( ( T_1 * ) & V_53 -> V_18 .
V_93 ) ) == true ) {
if ( V_70 == true )
snprintf ( V_57 . V_29 . V_94 , V_95 , L_2 ) ;
else
snprintf ( V_57 . V_29 . V_94 , V_95 , L_3 ) ;
} else if ( ( F_18 ( ( T_1 * ) & V_53 -> V_18 .
V_93 ) ) == true ) {
if ( V_70 == true )
snprintf ( V_57 . V_29 . V_94 , V_95 , L_4 ) ;
else
snprintf ( V_57 . V_29 . V_94 , V_95 , L_5 ) ;
} else {
if ( V_70 == true )
snprintf ( V_57 . V_29 . V_94 , V_95 , L_6 ) ;
else
snprintf ( V_57 . V_29 . V_94 , V_95 , L_7 ) ;
}
V_54 = F_13 ( V_51 , V_54 , V_55 , & V_57 , V_96 ) ;
V_57 . V_77 = V_97 ;
memcpy ( ( T_1 * ) & V_69 , F_19 ( V_53 -> V_18 . V_85 ) ,
2 ) ;
V_69 = F_20 ( V_69 ) ;
if ( V_69 & ( V_98 | V_99 ) ) {
if ( V_69 & V_99 )
V_57 . V_29 . V_100 = ( T_3 ) V_101 ;
else
V_57 . V_29 . V_100 = ( T_3 ) V_102 ;
V_54 = F_13 ( V_51 , V_54 , V_55 , & V_57 ,
V_103 ) ;
}
V_57 . V_77 = V_104 ;
{
T_1 V_105 = V_53 -> V_18 . V_75 . V_76 ;
if ( V_105 >= 1 && V_105 <= sizeof(
V_106 ) / sizeof( long ) )
V_57 . V_29 . V_107 . V_108 = ( V_109 ) ( V_106 [
V_53 -> V_18 . V_75 .
V_76 - 1 ] * 100000 ) ;
else
V_57 . V_29 . V_107 . V_108 = 0 ;
}
V_57 . V_29 . V_107 . V_110 = ( V_111 ) 1 ;
V_57 . V_29 . V_107 . V_3 = ( T_1 ) V_53 -> V_18 . V_75 . V_76 ;
V_54 = F_13 ( V_51 , V_54 , V_55 , & V_57 ,
V_112 ) ;
V_57 . V_77 = V_113 ;
if ( V_69 & V_114 )
V_57 . V_29 . V_80 . V_81 = ( T_4 ) ( V_115 |
V_116 ) ;
else
V_57 . V_29 . V_80 . V_81 = ( T_4 ) ( V_117 ) ;
V_57 . V_29 . V_80 . V_82 = ( T_4 ) 0 ;
V_54 = F_15 ( V_51 , V_54 , V_55 , & V_57 ,
V_53 -> V_18 . V_83 . V_83 ) ;
V_60 = V_54 + F_21 ( V_51 ) ;
V_57 . V_77 = V_118 ;
V_57 . V_29 . V_119 . V_120 = 0 ;
V_57 . V_29 . V_119 . V_121 = 0 ;
V_57 . V_29 . V_119 . V_122 = 0 ;
V_3 = 0 ;
while ( V_53 -> V_18 . V_93 [ V_3 ] != 0 ) {
V_57 . V_29 . V_119 . V_122 = ( V_53 -> V_18 . V_93 [ V_3 ++ ] &
0x7F ) * 500000 ;
V_60 = F_22 ( V_51 , V_54 , V_60 ,
V_55 , & V_57 , V_123 ) ;
}
if ( ( V_60 - V_54 ) > F_21 ( V_51 ) )
V_54 = V_60 ;
{
T_4 V_124 = 0 , V_125 = 0 ;
int V_126 ;
T_5 V_127 = 0 ;
V_127 = F_23 ( V_53 -> V_18 . V_85 ,
V_53 -> V_18 .
V_62 , V_64 , & V_125 ,
V_63 , & V_124 ) ;
if ( V_124 > 0 ) {
memset ( V_61 , 0 , V_128 ) ;
V_126 = sprintf ( V_61 , L_8 ) ;
for ( V_3 = 0 ; V_3 < V_124 ; V_3 ++ ) {
V_126 += snprintf ( V_61 + V_126 , V_128 - V_126 ,
L_9 , V_63 [ V_3 ] ) ;
if ( V_126 >= V_128 )
break;
}
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_77 = V_129 ;
V_57 . V_29 . V_80 . V_82 = ( T_4 ) strlen ( V_61 ) ;
V_54 = F_15 ( V_51 , V_54 , V_55 ,
& V_57 , V_61 ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_77 = V_130 ;
V_57 . V_29 . V_80 . V_82 = ( T_4 ) V_124 ;
V_54 = F_15 ( V_51 , V_54 , V_55 ,
& V_57 , V_63 ) ;
}
if ( V_125 > 0 ) {
memset ( V_61 , 0 , V_128 ) ;
V_126 = sprintf ( V_61 , L_10 ) ;
for ( V_3 = 0 ; V_3 < V_125 ; V_3 ++ ) {
V_126 += snprintf ( V_61 + V_126 , V_128 - V_126 ,
L_9 , V_64 [ V_3 ] ) ;
if ( V_126 >= V_128 )
break;
}
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_77 = V_129 ;
V_57 . V_29 . V_80 . V_82 = strlen ( V_61 ) ;
V_54 = F_15 ( V_51 , V_54 , V_55 ,
& V_57 , V_61 ) ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_77 = V_130 ;
V_57 . V_29 . V_80 . V_82 = V_125 ;
V_54 = F_15 ( V_51 , V_54 , V_55 , & V_57 ,
V_64 ) ;
}
}
{
T_6 V_131 ;
if ( F_24 ( V_53 -> V_18 . V_85 ,
V_53 -> V_18 . V_62 ,
V_65 , & V_131 ) == true ) {
if ( V_131 > 2 ) {
V_57 . V_77 = V_130 ;
V_57 . V_29 . V_80 . V_82 = ( T_4 ) V_131 ;
V_54 = F_15 ( V_51 , V_54 , V_55 ,
& V_57 , V_65 ) ;
}
}
}
V_57 . V_77 = V_132 ;
V_72 = F_25 ( V_53 -> V_18 . V_133 ) ;
V_57 . V_29 . V_134 . V_135 = ( T_1 ) ( V_136 | V_137 |
V_138 ) ;
V_57 . V_29 . V_134 . V_139 = V_72 ;
V_57 . V_29 . V_134 . V_134 = 0 ;
V_57 . V_29 . V_134 . V_140 = 0 ;
V_54 = F_13 ( V_51 , V_54 , V_55 , & V_57 , V_141 ) ;
F_26 ( V_61 ) ;
F_26 ( V_63 ) ;
F_26 ( V_64 ) ;
F_26 ( V_65 ) ;
return V_54 ;
}
static int F_27 ( struct V_142 * V_143 , T_3 V_122 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
int V_144 = 0 ;
if ( ( V_122 & V_145 ) && ( V_122 & V_146 ) ) {
V_7 -> V_36 . V_147 =
V_148 ;
V_7 -> V_36 . V_149 =
V_150 ;
V_7 -> V_36 . V_151 = 3 ;
} else if ( V_122 & V_145 ) {
V_7 -> V_36 . V_147 =
V_148 ;
V_7 -> V_36 . V_149 = V_152 ;
V_7 -> V_36 . V_151 = 1 ;
} else if ( V_122 & V_146 ) {
if ( V_7 -> V_36 . V_149 <
V_153 ) {
V_7 -> V_36 . V_149 =
V_154 ;
V_7 -> V_36 . V_151 = 0 ;
}
} else
V_144 = - V_155 ;
return V_144 ;
}
static int F_29 ( struct V_142 * V_143 , struct V_25 * V_26 ,
T_3 V_156 )
{
int V_144 = 0 ;
T_3 V_157 , V_158 = 0 ;
struct V_159 * V_160 = NULL ;
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_161 * V_162 = & V_7 -> V_36 ;
V_26 -> V_29 . V_30 . V_163 = 0 ;
V_26 -> V_29 . V_30 . V_33 [ V_164 - 1 ] = '\0' ;
if ( V_156 != ( T_3 ) ( ( T_1 * ) V_26 -> V_29 . V_30 . V_31 - ( T_1 * ) V_26 ) +
V_26 -> V_29 . V_30 . V_32 )
return - V_155 ;
if ( V_26 -> V_165 [ 0 ] == 0xff && V_26 -> V_165 [ 1 ] == 0xff &&
V_26 -> V_165 [ 2 ] == 0xff && V_26 -> V_165 [ 3 ] == 0xff &&
V_26 -> V_165 [ 4 ] == 0xff && V_26 -> V_165 [ 5 ] == 0xff ) {
if ( V_26 -> V_29 . V_30 . V_39 >= V_166 ) {
V_26 -> V_29 . V_30 . V_39 = 0 ;
}
} else
return - V_155 ;
if ( strcmp ( V_26 -> V_29 . V_30 . V_33 , L_11 ) == 0 ) {
F_30 ( V_167 L_12
L_13 ) ;
V_7 -> V_36 . V_147 =
V_148 ;
V_7 -> V_36 . V_168 = V_169 ;
V_7 -> V_36 . V_170 = V_169 ;
V_157 = V_26 -> V_29 . V_30 . V_39 ;
V_158 = V_26 -> V_29 . V_30 . V_32 ;
if ( V_157 >= V_166 )
V_157 = 0 ;
if ( V_158 > 0 ) {
V_158 = V_158 <= 5 ? 5 : 13 ;
V_160 = (struct V_159 * ) F_12 ( ( T_3 )
( V_158 +
F_31 ( struct V_159 ,
V_171 ) ) ) ;
if ( V_160 == NULL )
return - V_172 ;
memset ( V_160 , 0 , sizeof( struct V_159 ) ) ;
V_160 -> V_173 = V_158 ;
V_160 -> V_174 = V_158 +
F_31 ( struct V_159 ,
V_171 ) ;
if ( V_158 == 13 ) {
V_7 -> V_36 . V_168 =
V_175 ;
V_7 -> V_36 . V_170 =
V_175 ;
}
} else
return - V_155 ;
V_160 -> V_176 = V_157 ;
V_160 -> V_176 |= 0x80000000 ;
memcpy ( V_160 -> V_171 , V_26 -> V_29 . V_30 . V_31 , V_160 -> V_173 ) ;
if ( V_26 -> V_29 . V_30 . V_177 ) {
if ( F_32 ( V_7 , V_160 ) ==
( T_1 ) V_178 )
V_144 = - V_179 ;
} else {
if ( V_157 >= V_166 ) {
V_144 = - V_179 ;
goto exit;
}
memcpy ( & ( V_162 -> V_180 [ V_157 ] .
V_28 [ 0 ] ) , V_160 -> V_171 ,
V_160 -> V_173 ) ;
V_162 -> V_181 [ V_157 ] =
V_160 -> V_173 ;
F_10 ( V_7 , V_162 , V_157 ) ;
}
goto exit;
}
if ( V_7 -> V_36 . V_151 == 2 ) {
struct V_23 * V_24 , * V_182 ;
struct V_183 * V_184 = & V_7 -> V_185 ;
if ( F_33 ( V_11 , V_186 |
V_187 ) == true ) {
V_24 = F_34 ( V_184 ,
F_35 ( V_11 ) ) ;
if ( V_24 ) {
V_24 -> V_188 = false ;
if ( ( V_7 -> V_36 . V_147 ==
V_189 ) ||
( V_7 -> V_36 . V_147 ==
V_190 ) )
V_24 -> V_191 = V_7 ->
V_36 . V_168 ;
if ( V_26 -> V_29 . V_30 . V_177 == 1 )
F_6 ( V_24 , V_26 ,
V_7 ) ;
else
F_9 ( V_26 , V_7 ) ;
}
V_182 = F_36 ( V_7 ) ;
if ( V_182 ) {
V_182 -> V_188 = false ;
if ( ( V_7 -> V_36 . V_147 ==
V_189 ) ||
( V_7 -> V_36 . V_147 ==
V_190 ) )
V_182 -> V_191 =
V_7 -> V_36 .
V_168 ;
}
}
}
exit:
F_26 ( ( T_1 * ) V_160 ) ;
return V_144 ;
}
static int F_37 ( struct V_6 * V_7 , char * V_192 ,
unsigned short V_193 )
{
T_1 * V_61 = NULL , * V_194 = NULL ;
int V_195 = 0 , V_196 = 0 ;
int V_144 = 0 ;
if ( ( V_193 > V_128 ) || ( V_192 == NULL ) )
return - V_155 ;
if ( V_193 ) {
V_61 = F_12 ( V_193 ) ;
if ( V_61 == NULL )
return - V_172 ;
memcpy ( V_61 , V_192 , V_193 ) ;
V_194 = V_61 ;
if ( V_193 < V_197 ) {
V_144 = - 1 ;
goto exit;
}
if ( F_38 ( V_61 , V_193 , & V_195 ,
& V_196 ) == V_198 ) {
V_7 -> V_36 . V_151 = 2 ;
V_7 -> V_36 . V_149 =
V_153 ;
}
if ( F_39 ( V_61 , V_193 , & V_195 ,
& V_196 ) == V_198 ) {
V_7 -> V_36 . V_151 = 2 ;
V_7 -> V_36 . V_149 =
V_199 ;
}
switch ( V_195 ) {
case V_200 :
V_7 -> V_36 . V_170 =
V_201 ;
V_7 -> V_36 . V_147 =
V_202 ;
break;
case V_203 :
V_7 -> V_36 . V_170 = V_169 ;
V_7 -> V_36 . V_147 =
V_148 ;
break;
case V_204 :
V_7 -> V_36 . V_170 = V_205 ;
V_7 -> V_36 . V_147 =
V_189 ;
break;
case V_206 :
V_7 -> V_36 . V_170 = V_207 ;
V_7 -> V_36 . V_147 =
V_190 ;
break;
case V_208 :
V_7 -> V_36 . V_170 = V_175 ;
V_7 -> V_36 . V_147 =
V_148 ;
break;
}
switch ( V_196 ) {
case V_200 :
V_7 -> V_36 . V_168 =
V_201 ;
V_7 -> V_36 . V_147 =
V_202 ;
break;
case V_203 :
V_7 -> V_36 . V_168 = V_169 ;
V_7 -> V_36 . V_147 =
V_148 ;
break;
case V_204 :
V_7 -> V_36 . V_168 = V_205 ;
V_7 -> V_36 . V_147 =
V_189 ;
break;
case V_206 :
V_7 -> V_36 . V_168 = V_207 ;
V_7 -> V_36 . V_147 =
V_190 ;
break;
case V_208 :
V_7 -> V_36 . V_168 = V_175 ;
V_7 -> V_36 . V_147 =
V_148 ;
break;
}
V_7 -> V_36 . V_209 = false ;
{
T_4 V_210 = 0 ;
T_1 V_211 , V_212 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_210 < V_193 ) {
V_211 = V_61 [ V_210 ] ;
if ( ( V_211 == V_213 ) &&
( ! memcmp ( & V_61 [ V_210 + 2 ] , V_212 , 4 ) ) ) {
F_30 ( V_167 L_14
L_15 ) ;
V_7 -> V_36 . V_214 =
( ( V_61 [ V_210 + 1 ] + 2 ) <
( V_128 << 2 ) ) ?
( V_61 [ V_210 + 1 ] + 2 ) :
( V_128 << 2 ) ;
memcpy ( V_7 -> V_36 . V_65 ,
& V_61 [ V_210 ] ,
V_7 -> V_36 . V_214 ) ;
V_7 -> V_36 . V_209 =
true ;
F_30 ( V_167 L_16
L_17 ) ;
V_210 += V_61 [ V_210 + 1 ] + 2 ;
break;
} else
V_210 += V_61 [ V_210 + 1 ] + 2 ;
}
}
}
exit:
F_26 ( V_61 ) ;
return V_144 ;
}
static int F_40 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
T_3 V_68 = 0 ;
char * V_67 ;
T_1 V_70 = false ;
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
T_7 * V_218 = NULL ;
if ( F_33 ( V_11 , V_219 | V_220 ) ==
true ) {
V_67 = F_16 ( & V_217 -> V_85 [ 12 ] , V_86 ,
& V_68 , V_217 -> V_62 - 12 ) ;
if ( V_67 && V_68 > 0 )
V_70 = true ;
V_218 = & V_217 -> V_93 ;
if ( F_17 ( ( T_1 * ) V_218 ) == true ) {
if ( V_70 == true )
snprintf ( V_9 -> V_94 , V_95 ,
L_2 ) ;
else
snprintf ( V_9 -> V_94 , V_95 ,
L_3 ) ;
} else if ( ( F_18 ( ( T_1 * ) V_218 ) ) == true ) {
if ( V_70 == true )
snprintf ( V_9 -> V_94 , V_95 ,
L_4 ) ;
else
snprintf ( V_9 -> V_94 , V_95 ,
L_5 ) ;
} else {
if ( V_70 == true )
snprintf ( V_9 -> V_94 , V_95 ,
L_6 ) ;
else
snprintf ( V_9 -> V_94 , V_95 ,
L_7 ) ;
}
} else
snprintf ( V_9 -> V_94 , V_95 , L_18 ) ;
return 0 ;
}
static int F_41 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_221 * V_222 = & V_9 -> V_107 ;
int V_223 = 0 ;
if ( ( V_222 -> V_110 == 1 ) &&
( V_222 -> V_108 >= ( int ) 2.412e8 ) &&
( V_222 -> V_108 <= ( int ) 2.487e8 ) ) {
int V_224 = V_222 -> V_108 / 100000 ;
int V_225 = 0 ;
while ( ( V_225 < 14 ) && ( V_224 != V_226 [ V_225 ] ) )
V_225 ++ ;
V_222 -> V_110 = 0 ;
V_222 -> V_108 = V_225 + 1 ;
}
if ( ( V_222 -> V_108 > 14 ) || ( V_222 -> V_110 > 0 ) )
V_223 = - V_179 ;
else {
int V_227 = V_222 -> V_108 ;
if ( ( V_227 < 1 ) || ( V_227 > 14 ) )
V_223 = - V_155 ;
else {
V_7 -> V_44 . V_227 = V_227 ;
}
}
return V_223 ;
}
static int F_42 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
if ( F_33 ( V_11 , V_219 ) == true ) {
V_9 -> V_107 . V_108 = V_106 [
V_217 -> V_75 . V_76 - 1 ] * 100000 ;
V_9 -> V_107 . V_110 = 1 ;
V_9 -> V_107 . V_3 = V_217 -> V_75 . V_76 ;
} else
return - 1 ;
return 0 ;
}
static int F_43 ( struct V_142 * V_143 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
enum V_228 V_229 ;
switch ( V_9 -> V_100 ) {
case V_230 :
V_229 = V_231 ;
break;
case V_102 :
V_229 = V_232 ;
break;
case V_101 :
V_229 = V_233 ;
break;
case V_234 :
V_229 = V_235 ;
break;
default:
return - V_155 ;
}
if ( V_233 == V_229 )
F_44 ( V_7 , V_229 ) ;
else
F_44 ( V_7 , V_231 ) ;
if ( ! F_45 ( V_7 , V_229 ) )
return - 1 ;
return 0 ;
}
static int F_46 ( struct V_142 * V_143 , struct V_50 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
if ( F_33 ( V_11 , V_186 ) == true )
V_9 -> V_100 = V_234 ;
else if ( F_33 ( V_11 ,
V_220 | V_236 ) == true )
V_9 -> V_100 = V_102 ;
else if ( F_33 ( V_11 , V_237 ) == true )
V_9 -> V_100 = V_101 ;
else
V_9 -> V_100 = V_230 ;
return 0 ;
}
static int F_47 ( struct V_142 * V_143 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_161 * V_162 = & V_7 -> V_36 ;
struct V_238 * V_239 = (struct V_238 * ) V_215 ;
T_1 V_240 [ V_20 ] = { 0x00 } ;
T_1 V_241 [ V_20 ] = { 0x00 } ;
T_1 V_242 , V_243 = false ;
int V_244 = false ;
if ( V_239 == NULL )
return - V_155 ;
memcpy ( V_241 , V_239 -> V_245 . V_16 , V_20 ) ;
switch ( V_239 -> V_77 ) {
case V_246 :
if ( ! memcmp ( V_241 , V_240 , V_20 ) )
return V_244 ;
else
V_244 = true ;
V_243 = false ;
for ( V_242 = 0 ; V_242 < V_247 ; V_242 ++ ) {
if ( ! memcmp ( V_162 -> V_248 [ V_242 ] . V_249 ,
V_241 , V_20 ) ) {
F_30 ( V_167 L_19
L_20 ) ;
memcpy ( V_162 -> V_248 [ V_242 ] . V_250 ,
V_239 -> V_251 , V_252 ) ;
V_162 -> V_248 [ V_242 ] . V_253 = true ;
V_162 -> V_254 = V_242 + 1 ;
V_243 = true ;
break;
}
}
if ( ! V_243 ) {
F_30 ( V_167 L_21
L_22 ,
V_162 -> V_254 ) ;
memcpy ( V_162 -> V_248 [ V_162 ->
V_254 ] . V_249 , V_241 , V_20 ) ;
memcpy ( V_162 -> V_248 [ V_162 ->
V_254 ] . V_250 , V_239 -> V_251 , V_252 ) ;
V_162 -> V_248 [ V_162 -> V_254 ] .
V_253 = true ;
V_162 -> V_254 ++ ;
if ( V_162 -> V_254 == V_247 )
V_162 -> V_254 = 0 ;
}
break;
case V_255 :
V_244 = true ;
for ( V_242 = 0 ; V_242 < V_247 ; V_242 ++ ) {
if ( ! memcmp ( V_162 -> V_248 [ V_242 ] . V_249 ,
V_241 , V_20 ) ) {
memset ( V_162 -> V_248 [ V_242 ] . V_249 ,
0x00 , V_20 ) ;
V_162 -> V_248 [ V_242 ] . V_253 = false ;
break;
}
}
break;
case V_256 :
memset ( V_162 -> V_248 , 0 ,
sizeof( struct V_257 ) * V_247 ) ;
V_162 -> V_254 = 0 ;
V_244 = true ;
break;
default:
F_30 ( V_167 L_23
L_24 ) ;
V_244 = false ;
break;
}
return V_244 ;
}
static int F_48 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
V_9 -> V_258 . V_122 = 0 ;
V_9 -> V_258 . V_120 = 0 ;
V_9 -> V_258 . V_121 = 1 ;
return 0 ;
}
static int F_49 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_259 * V_260 = (struct V_259 * ) V_215 ;
T_4 V_261 ;
int V_3 ;
V_9 -> V_80 . V_82 = sizeof( * V_260 ) ;
memset ( V_260 , 0 , sizeof( * V_260 ) ) ;
V_260 -> V_262 = 5 * 1000 * 1000 ;
V_260 -> V_263 . V_134 = 100 ;
V_260 -> V_263 . V_139 = 100 ;
V_260 -> V_263 . V_140 = 100 ;
V_260 -> V_263 . V_135 = 7 ;
V_260 -> V_264 . V_134 = 92 ;
V_260 -> V_264 . V_139 = 20 + - 98 ;
V_260 -> V_264 . V_140 = 0 ;
V_260 -> V_264 . V_135 = 7 ;
V_260 -> V_265 = V_266 ;
for ( V_3 = 0 ; V_3 < V_266 && V_3 < V_267 ; V_3 ++ )
V_260 -> V_119 [ V_3 ] = V_268 [ V_3 ] ;
V_260 -> V_269 = V_270 ;
V_260 -> V_271 = V_272 ;
V_260 -> V_273 = 0 ;
V_260 -> V_274 = V_275 ;
V_260 -> V_276 = 16 ;
V_260 -> V_277 = 14 ;
for ( V_3 = 0 , V_261 = 0 ; V_3 < 14 ; V_3 ++ ) {
V_260 -> V_107 [ V_261 ] . V_3 = V_3 + 1 ;
V_260 -> V_107 [ V_261 ] . V_108 = V_106 [ V_3 ] * 100000 ;
V_260 -> V_107 [ V_261 ] . V_110 = 1 ;
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
static int F_50 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_285 ,
char * V_215 )
{
int V_144 = 0 , V_286 = 0 ;
char * V_287 ;
struct V_288 * V_289 = (struct V_288 * ) V_285 ;
V_286 = V_289 -> V_82 ;
V_287 = F_12 ( V_286 ) ;
if ( ! V_287 )
return - V_172 ;
if ( F_51 ( V_287 , V_289 -> V_290 , V_286 ) ) {
F_26 ( V_287 ) ;
return - V_291 ;
}
F_26 ( V_287 ) ;
return V_144 ;
}
static int F_52 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_285 ,
char * V_215 )
{
int V_144 = - V_292 ;
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_293 * V_294 = & V_11 -> V_295 ;
struct V_296 * V_297 = (struct V_296 * ) V_285 ;
unsigned long V_298 ;
struct V_299 * V_300 ;
T_1 * V_301 ;
struct V_52 * V_53 = NULL ;
enum V_302 V_303 ;
if ( V_7 -> V_304 == false )
return - 1 ;
if ( F_33 ( V_11 , V_305 ) == true )
return - 1 ;
if ( F_33 ( V_11 , V_306 ) == true )
return V_144 ;
if ( V_297 -> V_14 != V_15 )
return - V_155 ;
V_303 = V_7 -> V_36 . V_149 ;
F_53 ( & V_294 -> V_307 , V_298 ) ;
V_300 = F_54 ( V_294 ) ;
V_11 -> V_308 = F_55 ( V_300 ) ;
while ( 1 ) {
if ( F_56 ( V_300 , V_11 -> V_308 ) == true )
break;
V_53 = F_57 ( V_11 -> V_308 ,
struct V_52 , V_309 ) ;
V_11 -> V_308 = F_55 ( V_11 -> V_308 ) ;
V_301 = V_53 -> V_18 . V_19 ;
if ( ! memcmp ( V_301 , V_297 -> V_16 , V_20 ) ) {
if ( F_45 ( V_7 ,
V_53 -> V_18 . V_310 ) == false )
V_144 = - 1 ;
break;
}
}
F_58 ( & V_294 -> V_307 , V_298 ) ;
if ( ! V_144 ) {
if ( ! F_59 ( V_7 , V_303 ) )
V_144 = - 1 ;
else {
if ( ! F_60 ( V_7 , V_297 -> V_16 ) )
V_144 = - 1 ;
}
}
return V_144 ;
}
static int F_61 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
V_9 -> V_13 . V_14 = V_15 ;
memset ( V_9 -> V_13 . V_16 , 0 , V_20 ) ;
if ( F_33 ( V_11 , V_219 |
V_220 | V_237 ) ) {
memcpy ( V_9 -> V_13 . V_16 , V_217 -> V_19 , V_20 ) ;
}
return 0 ;
}
static int F_62 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
int V_144 = 0 ;
T_4 V_311 ;
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_312 * V_313 = (struct V_312 * ) V_215 ;
if ( V_313 == NULL )
return - 1 ;
V_311 = F_63 ( V_313 -> V_314 ) ;
switch ( V_313 -> V_77 ) {
case V_315 :
if ( ! F_64 ( V_7 ) )
V_144 = - 1 ;
break;
case V_316 :
if ( ! F_64 ( V_7 ) )
V_144 = - 1 ;
break;
default:
return - V_179 ;
}
return V_144 ;
}
static int F_65 ( struct V_142 * V_143 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_317 = true ;
if ( V_7 -> V_318 == true ) {
F_30 ( V_319 L_25
L_26 , V_7 -> V_318 ) ;
return - 1 ;
}
if ( V_7 -> V_304 == false )
return - 1 ;
if ( V_7 -> V_320 == false )
return - 1 ;
if ( ( F_33 ( V_11 , V_305 | V_306 ) ) ||
( V_11 -> V_321 . V_322 == true ) )
return 0 ;
if ( V_9 -> V_80 . V_82 == sizeof( struct V_323 ) ) {
struct V_323 * V_324 = (struct V_323 * ) V_215 ;
if ( V_9 -> V_80 . V_81 & V_325 ) {
struct V_326 V_327 ;
unsigned long V_298 ;
T_3 V_286 = ( T_3 ) F_14 ( ( T_1 ) V_324 -> V_328 ,
( T_1 ) V_329 ) ;
memset ( ( unsigned char * ) & V_327 , 0 ,
sizeof( struct V_326 ) ) ;
memcpy ( V_327 . V_83 , V_324 -> V_330 , V_286 ) ;
V_327 . V_84 = V_286 ;
F_53 ( & V_11 -> V_307 , V_298 ) ;
if ( ( F_33 ( V_11 , V_305 |
V_306 ) ) ||
( V_11 -> V_321 . V_322 == true ) ) {
if ( F_33 ( V_11 , V_306 ) )
V_317 = false ;
} else
V_317 = F_66 ( V_7 , & V_327 ) ;
F_58 ( & V_11 -> V_307 , V_298 ) ;
}
} else
V_317 = F_67 ( V_7 ) ;
if ( V_317 == false )
return - 1 ;
return 0 ;
}
static int F_68 ( struct V_142 * V_143 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_293 * V_294 = & V_11 -> V_295 ;
struct V_52 * V_53 = NULL ;
unsigned long V_298 ;
struct V_299 * V_331 , * V_300 ;
char * V_332 = V_215 ;
char * V_55 = V_332 + V_9 -> V_80 . V_82 ;
T_3 V_144 = 0 , V_210 = 0 ;
if ( V_7 -> V_318 )
return - V_155 ;
while ( F_33 ( V_11 , V_305 | V_306 ) ) {
F_69 ( 30 ) ;
V_210 ++ ;
if ( V_210 > 1000 )
break;
}
F_53 ( & V_294 -> V_307 , V_298 ) ;
V_300 = F_54 ( V_294 ) ;
V_331 = F_55 ( V_300 ) ;
while ( 1 ) {
if ( F_56 ( V_300 , V_331 ) == true )
break;
if ( ( V_55 - V_332 ) < V_333 ) {
V_144 = - V_334 ;
break;
}
V_53 = F_57 ( V_331 , struct V_52 , V_309 ) ;
V_332 = F_11 ( V_7 , V_4 , V_53 , V_332 , V_55 ) ;
V_331 = F_55 ( V_331 ) ;
}
F_58 ( & V_294 -> V_307 , V_298 ) ;
V_9 -> V_80 . V_82 = V_332 - V_215 ;
V_9 -> V_80 . V_81 = 0 ;
return V_144 ;
}
static int F_70 ( struct V_142 * V_143 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_293 * V_294 = & V_11 -> V_295 ;
struct V_52 * V_53 = NULL ;
enum V_302 V_303 ;
struct V_326 V_335 ;
T_1 * V_336 , * V_337 ;
struct V_299 * V_300 ;
T_3 V_286 ;
if ( V_7 -> V_304 == false )
return - 1 ;
if ( F_33 ( V_11 , V_305 ) )
return - 1 ;
if ( F_33 ( V_11 , V_306 ) )
return 0 ;
if ( V_9 -> V_330 . V_82 > V_329 )
return - V_334 ;
V_303 = V_7 -> V_36 . V_149 ;
if ( V_9 -> V_330 . V_81 && V_9 -> V_330 . V_82 ) {
V_286 = ( V_9 -> V_330 . V_82 < V_329 ) ?
V_9 -> V_330 . V_82 : V_329 ;
memset ( & V_335 , 0 , sizeof( struct V_326 ) ) ;
V_335 . V_84 = V_286 ;
memcpy ( V_335 . V_83 , V_215 , V_286 ) ;
V_337 = V_335 . V_83 ;
V_300 = F_54 ( V_294 ) ;
V_11 -> V_308 = F_55 ( V_300 ) ;
while ( 1 ) {
if ( F_56 ( V_300 , V_11 -> V_308 ) )
break;
V_53 = F_57 ( V_11 -> V_308 ,
struct V_52 , V_309 ) ;
V_11 -> V_308 = F_55 ( V_11 -> V_308 ) ;
V_336 = V_53 -> V_18 . V_83 . V_83 ;
if ( ( ! memcmp ( V_336 , V_337 , V_335 . V_84 ) )
&& ( V_53 -> V_18 . V_83 . V_84 ==
V_335 . V_84 ) ) {
if ( ! F_45 (
V_7 ,
V_53 -> V_18 . V_310 ) )
return - 1 ;
break;
}
}
F_59 ( V_7 , V_303 ) ;
F_71 ( V_7 , & V_335 ) ;
}
return - V_292 ;
}
static int F_72 ( struct V_142 * V_143 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
T_3 V_286 , V_144 = 0 ;
if ( F_33 ( V_11 , V_219 | V_220 ) ) {
V_286 = V_217 -> V_83 . V_84 ;
V_9 -> V_330 . V_82 = V_286 ;
memcpy ( V_215 , V_217 -> V_83 . V_83 , V_286 ) ;
V_9 -> V_330 . V_81 = 1 ;
} else
V_144 = - 1 ;
return V_144 ;
}
static int F_73 ( struct V_142 * V_143 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
T_3 V_338 = V_9 -> V_119 . V_122 ;
T_3 V_120 = V_9 -> V_119 . V_120 ;
T_3 V_339 = 0 ;
T_1 V_340 [ V_341 ] ;
T_1 V_342 [ V_341 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
int V_3 , V_144 = 0 ;
if ( V_338 == - 1 ) {
V_339 = 11 ;
goto V_343;
}
V_338 = V_338 / 100000 ;
switch ( V_338 ) {
case 10 :
V_339 = 0 ;
break;
case 20 :
V_339 = 1 ;
break;
case 55 :
V_339 = 2 ;
break;
case 60 :
V_339 = 3 ;
break;
case 90 :
V_339 = 4 ;
break;
case 110 :
V_339 = 5 ;
break;
case 120 :
V_339 = 6 ;
break;
case 180 :
V_339 = 7 ;
break;
case 240 :
V_339 = 8 ;
break;
case 360 :
V_339 = 9 ;
break;
case 480 :
V_339 = 10 ;
break;
case 540 :
V_339 = 11 ;
break;
default:
V_339 = 11 ;
break;
}
V_343:
for ( V_3 = 0 ; V_3 < V_341 ; V_3 ++ ) {
if ( V_339 == V_342 [ V_3 ] ) {
V_340 [ V_3 ] = V_342 [ V_3 ] ;
if ( V_120 == 0 )
break;
} else
V_340 [ V_3 ] = 0xff ;
}
if ( F_74 ( V_7 , V_340 ) != V_198 )
V_144 = - 1 ;
return V_144 ;
}
static int F_75 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_216 * V_217 = & V_11 -> V_17 . V_18 ;
struct V_58 * V_59 ;
int V_3 ;
T_1 * V_67 ;
T_4 V_344 , V_345 = 0 , V_70 = false ;
T_3 V_68 = 0 ;
T_1 V_73 = 0 , V_74 = 0 ;
T_4 V_71 = 0 ;
V_3 = 0 ;
if ( F_33 ( V_11 , V_219 | V_220 ) ) {
V_67 = F_16 ( & V_217 -> V_85 [ 12 ] ,
V_86 , & V_68 ,
V_217 -> V_62 - 12 ) ;
if ( V_67 && V_68 > 0 ) {
V_70 = true ;
V_59 = (struct V_58 * ) ( V_67 + 2 ) ;
memcpy ( & V_71 , V_59 -> V_87 , 2 ) ;
V_73 = ( V_59 -> V_88 &
V_89 ) ? 1 : 0 ;
V_74 = ( V_59 -> V_88 &
( V_90 |
V_91 ) ) ? 1 : 0 ;
}
while ( ( V_217 -> V_93 [ V_3 ] != 0 ) &&
( V_217 -> V_93 [ V_3 ] != 0xFF ) ) {
V_344 = V_217 -> V_93 [ V_3 ] & 0x7F ;
if ( V_344 > V_345 )
V_345 = V_344 ;
V_9 -> V_119 . V_120 = 0 ;
V_9 -> V_119 . V_122 = V_344 * 500000 ;
V_3 ++ ;
}
if ( V_70 == true ) {
if ( V_71 & 0x8000 )
V_345 = ( V_73 ) ? ( ( V_74 ) ? 300 :
270 ) : ( ( V_74 ) ? 144 : 130 ) ;
else if ( V_71 & 0x0080 )
V_345 = ( V_73 ) ? ( ( V_74 ) ? 150 :
135 ) : ( ( V_74 ) ? 72 : 65 ) ;
else
V_345 = ( V_73 ) ? ( ( V_74 ) ? 150 :
135 ) : ( ( V_74 ) ? 72 : 65 ) ;
V_345 *= 2 ;
V_9 -> V_119 . V_122 = V_345 * 500000 ;
} else {
V_9 -> V_119 . V_122 = V_345 * 500000 ;
}
} else
return - 1 ;
return 0 ;
}
static int F_76 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
V_9 -> V_346 . V_122 = V_7 -> V_44 . V_347 ;
V_9 -> V_346 . V_120 = 0 ;
return 0 ;
}
static int F_77 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
if ( V_9 -> V_348 . V_121 )
V_7 -> V_349 . V_350 = V_272 ;
else {
if ( V_9 -> V_348 . V_122 < V_270 ||
V_9 -> V_348 . V_122 > V_272 )
return - V_155 ;
V_7 -> V_349 . V_350 = V_9 -> V_348 . V_122 & ~ 0x1 ;
}
return 0 ;
}
static int F_78 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
V_9 -> V_348 . V_122 = V_7 -> V_349 . V_350 ;
V_9 -> V_348 . V_120 = 0 ;
return 0 ;
}
static int F_79 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
V_9 -> V_351 . V_122 = 7 ;
V_9 -> V_351 . V_120 = 0 ;
V_9 -> V_351 . V_121 = 1 ;
return 0 ;
}
static int F_80 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_352 )
{
T_3 V_31 ;
T_3 V_353 ;
struct V_159 V_354 ;
enum V_302 V_303 ;
struct V_288 * V_355 = & ( V_9 -> V_356 ) ;
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
V_31 = V_355 -> V_81 & V_357 ;
memset ( & V_354 , 0 , sizeof( struct V_159 ) ) ;
if ( V_355 -> V_81 & V_117 ) {
F_30 ( V_167 L_27
L_28 ) ;
V_7 -> V_36 . V_147 =
V_202 ;
V_7 -> V_36 . V_168 = V_201 ;
V_7 -> V_36 . V_170 = V_201 ;
V_7 -> V_36 . V_151 = 0 ;
V_303 = V_154 ;
V_7 -> V_36 . V_149 = V_303 ;
return 0 ;
}
if ( V_31 ) {
if ( V_31 > V_166 )
return - V_155 ;
V_31 -- ;
V_353 = 1 ;
} else {
V_353 = 0 ;
V_31 = V_7 -> V_36 . V_358 ;
}
if ( V_355 -> V_81 & V_359 ) {
F_30 ( V_167 L_27
L_29 ) ;
V_7 -> V_36 . V_147 =
V_148 ;
V_7 -> V_36 . V_151 = 0 ;
V_7 -> V_36 . V_168 = V_201 ;
V_7 -> V_36 . V_170 = V_201 ;
V_303 = V_154 ;
V_7 -> V_36 . V_149 = V_303 ;
} else if ( V_355 -> V_81 & V_360 ) {
F_30 ( V_167 L_27
L_30 ) ;
V_7 -> V_36 . V_147 =
V_148 ;
V_7 -> V_36 . V_151 = 1 ;
V_7 -> V_36 . V_168 = V_169 ;
V_7 -> V_36 . V_170 = V_169 ;
V_303 = V_152 ;
V_7 -> V_36 . V_149 = V_303 ;
} else {
V_7 -> V_36 . V_147 =
V_148 ;
V_7 -> V_36 . V_151 = 0 ;
V_7 -> V_36 . V_168 = V_201 ;
V_7 -> V_36 . V_170 = V_201 ;
V_303 = V_154 ;
V_7 -> V_36 . V_149 = V_303 ;
}
V_354 . V_176 = V_31 ;
if ( V_355 -> V_82 > 0 ) {
V_354 . V_173 = V_355 -> V_82 <= 5 ? 5 : 13 ;
V_354 . V_174 = V_354 . V_173 +
F_31 ( struct V_159 , V_171 ) ;
} else {
V_354 . V_173 = 0 ;
if ( V_353 == 1 ) {
V_7 -> V_36 . V_358 = V_31 ;
switch ( V_7 -> V_36 . V_181 [ V_31 ] ) {
case 5 :
V_7 -> V_36 . V_168 =
V_169 ;
break;
case 13 :
V_7 -> V_36 . V_168 =
V_175 ;
break;
default:
V_7 -> V_36 . V_168 =
V_201 ;
break;
}
return 0 ;
}
}
V_354 . V_176 |= 0x80000000 ;
memcpy ( V_354 . V_171 , V_352 , V_354 . V_173 ) ;
if ( F_32 ( V_7 , & V_354 ) == V_178 )
return - V_179 ;
return 0 ;
}
static int F_81 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_352 )
{
T_6 V_31 , V_144 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_288 * V_355 = & ( V_9 -> V_356 ) ;
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
if ( F_33 ( V_11 , V_219 ) == false ) {
if ( ! F_33 ( V_11 , V_220 ) ) {
V_355 -> V_82 = 0 ;
V_355 -> V_81 |= V_117 ;
return 0 ;
}
}
V_31 = V_355 -> V_81 & V_357 ;
if ( V_31 ) {
if ( V_31 > V_166 )
return - V_155 ;
V_31 -- ;
} else {
V_31 = V_7 -> V_36 . V_358 ;
}
V_355 -> V_81 = V_31 + 1 ;
switch ( V_7 -> V_36 . V_147 ) {
case V_361 :
case V_202 :
V_355 -> V_82 = 0 ;
V_355 -> V_81 |= V_117 ;
break;
case V_148 :
V_355 -> V_82 = V_7 -> V_36 . V_181 [ V_31 ] ;
if ( V_355 -> V_82 ) {
memcpy ( V_352 , V_7 -> V_36 . V_180 [
V_31 ] . V_28 , V_7 -> V_36 .
V_181 [ V_31 ] ) ;
V_355 -> V_81 |= V_115 ;
if ( V_7 -> V_36 . V_149 ==
V_154 )
V_355 -> V_81 |= V_359 ;
else if ( V_7 -> V_36 . V_149 ==
V_152 )
V_355 -> V_81 |= V_360 ;
} else {
V_355 -> V_82 = 0 ;
V_355 -> V_81 |= V_117 ;
}
break;
case V_189 :
case V_190 :
V_355 -> V_82 = 16 ;
V_355 -> V_81 |= ( V_115 | V_359 |
V_116 ) ;
break;
default:
V_355 -> V_82 = 0 ;
V_355 -> V_81 |= V_117 ;
break;
}
return V_144 ;
}
static int F_82 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
V_9 -> V_362 . V_122 = 0 ;
V_9 -> V_362 . V_120 = 0 ;
V_9 -> V_362 . V_121 = 1 ;
return 0 ;
}
static int F_83 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
return F_37 ( V_7 , V_215 , V_9 -> V_80 . V_82 ) ;
}
static int F_84 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_363 * V_26 = (struct V_363 * ) & ( V_9 -> V_26 ) ;
int V_364 ;
int V_365 ;
int V_144 = 0 ;
V_364 = V_26 -> V_81 & V_366 ;
V_365 = V_26 -> V_122 ;
switch ( V_364 ) {
case V_367 :
break;
case V_368 :
break;
case V_369 :
break;
case V_370 :
break;
case V_371 :
if ( V_365 ) {
V_7 -> V_36 . V_372 = true ;
} else {
V_7 -> V_36 . V_372 = false ;
}
break;
case V_373 :
if ( V_7 -> V_36 . V_147 ==
V_148 ) {
break;
}
if ( V_365 ) {
V_7 -> V_36 . V_147 =
V_202 ;
V_7 -> V_36 . V_168 =
V_201 ;
V_7 -> V_36 . V_170 =
V_201 ;
V_7 -> V_36 . V_151 = 0 ;
V_7 -> V_36 . V_149 =
V_154 ;
}
break;
case V_374 :
V_144 = F_27 ( V_143 , ( T_3 ) V_365 ) ;
break;
case V_375 :
break;
case V_376 :
break;
case V_377 :
break;
default:
return - V_179 ;
}
return V_144 ;
}
static int F_85 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_288 * V_378 = & V_9 -> V_356 ;
struct V_379 * V_380 = (struct V_379 * ) V_215 ;
struct V_25 * V_26 = NULL ;
char * V_381 ;
T_3 V_156 ;
int V_144 = 0 ;
V_156 = sizeof( struct V_25 ) + V_380 -> V_32 ;
V_26 = (struct V_25 * ) F_12 ( V_156 ) ;
if ( V_26 == NULL )
return - 1 ;
memset ( V_26 , 0 , V_156 ) ;
V_26 -> V_77 = V_382 ;
memset ( V_26 -> V_165 , 0xff , V_20 ) ;
switch ( V_380 -> V_33 ) {
case V_383 :
V_381 = L_31 ;
break;
case V_384 :
V_381 = L_11 ;
break;
case V_385 :
V_381 = L_1 ;
break;
case V_386 :
V_381 = L_32 ;
break;
default:
return - 1 ;
}
strncpy ( ( char * ) V_26 -> V_29 . V_30 . V_33 , V_381 , V_164 ) ;
if ( V_380 -> V_387 & V_388 )
V_26 -> V_29 . V_30 . V_177 = 0 ;
if ( V_380 -> V_387 & V_389 )
V_26 -> V_29 . V_30 . V_177 = 1 ;
V_26 -> V_29 . V_30 . V_39 = ( V_378 -> V_81 & 0x00FF ) - 1 ;
if ( V_380 -> V_387 & V_390 )
memcpy ( V_26 -> V_29 . V_30 . V_391 , V_380 -> V_392 , 8 ) ;
if ( V_380 -> V_32 ) {
V_26 -> V_29 . V_30 . V_32 = V_380 -> V_32 ;
memcpy ( V_26 + 1 , V_380 + 1 , V_380 -> V_32 ) ;
}
V_144 = F_29 ( V_143 , V_26 , V_156 ) ;
F_26 ( V_26 ) ;
return V_144 ;
}
static int F_86 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
if ( V_215 ) {
V_9 -> V_80 . V_82 = 8 ;
V_9 -> V_80 . V_81 = 1 ;
memcpy ( V_215 , L_33 , 8 ) ;
}
return 0 ;
}
static int F_87 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_352 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
T_3 V_2 ;
T_3 V_393 ;
F_88 ( V_2 , ( T_3 V_394 * ) V_9 -> V_80 . V_290 ) ;
V_393 = F_89 ( V_7 , V_2 ) ;
F_90 ( V_393 , ( T_3 V_394 * ) V_9 -> V_80 . V_290 ) ;
V_9 -> V_80 . V_82 = ( V_393 & 0xffff0000 ) >> 16 ;
V_9 -> V_80 . V_81 = V_393 & 0xffff ;
F_88 ( V_2 , ( T_3 V_394 * ) V_9 -> V_80 . V_290 ) ;
return 0 ;
}
static int F_91 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_352 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
T_3 V_2 ;
T_3 V_393 ;
F_88 ( V_2 , ( T_3 V_394 * ) V_9 -> V_80 . V_290 ) ;
V_393 = ( ( T_3 ) V_9 -> V_80 . V_82 << 16 ) | ( T_3 ) V_9 -> V_80 . V_81 ;
F_92 ( V_7 , V_2 , V_393 ) ;
return 0 ;
}
static int F_93 ( struct V_142 * V_143 ,
struct V_50 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
return - 1 ;
}
static int F_94 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
return 0 ;
}
static int F_95 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_288 * V_67 = & V_9 -> V_80 ;
struct V_395 V_396 ;
struct V_397 * V_398 ;
struct V_399 * V_400 ;
unsigned long V_401 , V_402 , V_403 ;
T_1 * V_404 = NULL , V_405 ;
T_4 V_286 ;
T_6 V_317 ;
int V_144 = 0 ;
if ( ( ! V_67 -> V_82 ) || ( ! V_67 -> V_290 ) ) {
V_144 = - V_155 ;
goto V_406;
}
V_405 = ( T_1 ) ( V_67 -> V_81 & 0xFFFF ) ;
V_286 = V_67 -> V_82 ;
V_404 = NULL ;
V_404 = ( T_1 * ) F_12 ( V_286 ) ;
if ( V_404 == NULL ) {
V_144 = - V_172 ;
goto V_406;
}
if ( F_51 ( V_404 , V_67 -> V_290 , V_286 ) ) {
V_144 = - V_291 ;
goto V_406;
}
V_400 = (struct V_399 * ) V_404 ;
if ( V_400 -> V_407 >= V_408 ) {
V_144 = - V_155 ;
goto V_406;
}
V_398 = V_409 + V_400 -> V_407 ;
if ( ( V_398 -> V_410 != 0 ) &&
( V_400 -> V_286 < V_398 -> V_410 ) ) {
V_144 = - V_155 ;
goto V_406;
}
if ( V_398 -> V_411 == 0 && V_398 -> V_412 )
V_317 = V_398 -> V_412 ( & V_396 ) ;
else if ( V_398 -> V_412 ) {
V_396 . V_413 = V_7 ;
V_396 . V_411 = V_398 -> V_411 ;
V_396 . V_414 = V_400 -> V_80 ;
V_396 . V_415 = V_400 -> V_286 ;
V_396 . V_416 = 0 ;
V_402 = 0 ;
V_403 = 0 ;
if ( V_405 ) {
V_396 . V_417 = & V_401 ;
V_396 . V_418 = & V_403 ;
V_396 . V_419 = V_420 ;
} else {
V_396 . V_417 = & V_402 ;
V_396 . V_418 = & V_403 ;
V_396 . V_419 = V_421 ;
}
V_317 = V_398 -> V_412 ( & V_396 ) ;
} else {
F_30 ( V_167 L_34
L_35 ,
V_400 -> V_407 , V_398 -> V_411 , V_398 -> V_412 ) ;
V_144 = - V_291 ;
goto V_406;
}
if ( V_405 == 0x00 ) {
if ( F_96 ( V_67 -> V_290 , V_404 , V_286 ) )
V_144 = - V_291 ;
}
if ( V_317 ) {
V_144 = - V_291 ;
goto V_406;
}
V_406:
F_26 ( V_404 ) ;
return V_144 ;
}
static int F_97 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_293 * V_294 = & V_11 -> V_295 ;
struct V_288 * V_422 = & V_9 -> V_80 ;
struct V_52 * V_53 = NULL ;
T_3 V_210 = 0 , V_423 ;
unsigned long V_298 ;
struct V_299 * V_331 , * V_300 ;
unsigned char * V_424 ;
T_1 V_245 [ V_20 ] ;
char V_80 [ 32 ] ;
if ( V_7 -> V_318 || ( V_422 == NULL ) )
return - V_155 ;
while ( F_33 ( V_11 , V_305 | V_306 ) ) {
F_69 ( 30 ) ;
V_210 ++ ;
if ( V_210 > 100 )
break;
}
V_422 -> V_81 = 0 ;
if ( V_422 -> V_82 >= 32 ) {
if ( F_51 ( V_80 , V_422 -> V_290 , 32 ) )
return - V_155 ;
} else
return - V_155 ;
F_53 ( & ( V_11 -> V_295 . V_307 ) , V_298 ) ;
V_300 = F_54 ( V_294 ) ;
V_331 = F_55 ( V_300 ) ;
while ( 1 ) {
if ( F_56 ( V_300 , V_331 ) == true )
break;
V_53 = F_57 ( V_331 , struct V_52 , V_309 ) ;
if ( F_1 ( V_80 , V_245 ) ) {
F_30 ( V_167 L_36 ,
( T_1 * ) V_80 ) ;
F_58 ( & ( V_11 -> V_295 . V_307 ) ,
V_298 ) ;
return - V_155 ;
}
F_30 ( V_167 L_37 , V_245 ) ;
if ( ! memcmp ( V_245 , V_53 -> V_18 . V_19 , V_20 ) ) {
V_424 = F_98 ( & V_53 -> V_18 . V_85 [ 12 ] ,
& V_423 , V_53 -> V_18 . V_62 - 12 ) ;
if ( V_424 && ( V_423 > 0 ) ) {
V_422 -> V_81 = 1 ;
break;
}
V_424 = F_99 ( & V_53 -> V_18 . V_85 [ 12 ] ,
& V_423 , V_53 -> V_18 . V_62 - 12 ) ;
if ( V_424 && ( V_423 > 0 ) ) {
V_422 -> V_81 = 2 ;
break;
}
}
V_331 = F_55 ( V_331 ) ;
}
F_58 ( & ( V_11 -> V_295 . V_307 ) , V_298 ) ;
if ( V_422 -> V_82 >= 34 ) {
if ( F_96 ( ( T_1 V_394 * ) V_422 -> V_290 + 32 ,
( T_1 * ) & V_422 -> V_81 , 1 ) )
return - V_155 ;
}
return 0 ;
}
static int F_100 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_288 * V_422 = & V_9 -> V_80 ;
if ( ( V_7 -> V_318 ) || ( V_422 == NULL ) )
return - V_155 ;
if ( F_51 ( & V_7 -> V_425 , V_422 -> V_290 , sizeof( int ) ) )
return - V_155 ;
return 0 ;
}
static int F_101 ( struct V_142 * V_143 ,
struct V_50 * V_51 ,
union V_8 * V_9 , char * V_215 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_288 * V_422 = & V_9 -> V_80 ;
T_3 V_426 = 0 ;
if ( F_51 ( ( void * ) & V_426 , V_422 -> V_290 , 4 ) )
return - V_291 ;
if ( ( V_7 -> V_318 ) || ( V_422 == NULL ) )
return - V_155 ;
if ( V_426 == 0 )
V_426 = * V_215 ;
if ( V_426 == 1 )
V_7 -> V_427 . V_428 ( V_7 ,
V_429 ) ;
else if ( V_426 == 2 )
V_7 -> V_427 . V_428 ( V_7 ,
V_430 ) ;
else if ( V_426 == 3 )
V_7 -> V_427 . V_428 ( V_7 ,
V_431 ) ;
return 0 ;
}
static int F_102 ( struct V_142 * V_143 , T_1 V_94 , T_3 V_122 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
switch ( V_94 ) {
case V_432 :
V_7 -> V_36 . V_151 = 2 ;
switch ( ( V_122 ) & 0xff ) {
case 1 :
V_7 -> V_36 . V_149 =
V_153 ;
V_7 -> V_36 . V_147 =
V_189 ;
break;
case 2 :
V_7 -> V_36 . V_149 =
V_199 ;
V_7 -> V_36 . V_147 =
V_190 ;
break;
}
break;
case V_433 :
break;
case V_434 :
break;
case V_435 :
break;
case V_436 :
return F_27 ( V_143 , V_122 ) ;
break;
case V_437 :
break;
case V_438 :
break;
default:
return - V_179 ;
}
return 0 ;
}
static int F_103 ( struct V_142 * V_143 , T_3 V_439 , T_3 V_311 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
switch ( V_439 ) {
case V_440 :
if ( ! F_64 ( V_7 ) )
return - 1 ;
break;
case V_441 :
if ( ! F_64 ( V_7 ) )
return - 1 ;
break;
default:
return - V_179 ;
}
return 0 ;
}
static int F_104 ( struct V_142 * V_143 , struct V_288 * V_67 )
{
struct V_25 * V_26 ;
int V_144 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
if ( V_67 -> V_82 < sizeof( struct V_25 ) || ! V_67 -> V_290 )
return - V_155 ;
V_26 = (struct V_25 * ) F_12 ( V_67 -> V_82 ) ;
if ( V_26 == NULL )
return - V_172 ;
if ( F_51 ( V_26 , V_67 -> V_290 , V_67 -> V_82 ) )
F_26 ( ( T_1 * ) V_26 ) ;
return - V_291 ;
switch ( V_26 -> V_77 ) {
case V_442 :
V_144 = F_102 ( V_143 , V_26 -> V_29 . V_443 . V_94 ,
V_26 -> V_29 . V_443 . V_122 ) ;
break;
case V_444 :
V_144 = F_37 ( V_7 , ( char * ) V_26 -> V_29 . V_63 . V_80 ,
( T_4 ) V_26 -> V_29 . V_63 . V_286 ) ;
break;
case V_382 :
V_144 = F_29 ( V_143 , V_26 , V_67 -> V_82 ) ;
break;
case V_445 :
V_144 = F_103 ( V_143 , V_26 -> V_29 . V_313 . V_439 ,
V_26 -> V_29 . V_313 . V_314 ) ;
break;
default:
V_144 = - V_179 ;
break;
}
if ( V_144 == 0 && F_96 ( V_67 -> V_290 , V_26 , V_67 -> V_82 ) )
V_144 = - V_291 ;
F_26 ( ( T_1 * ) V_26 ) ;
return V_144 ;
}
int F_105 ( struct V_142 * V_143 , struct V_446 * V_447 , int V_77 )
{
struct V_448 * V_449 = (struct V_448 * ) V_447 ;
switch ( V_77 ) {
case V_450 :
return F_104 ( V_143 , & V_449 -> V_29 . V_80 ) ;
default:
return - V_179 ;
}
return 0 ;
}
static struct V_451 * F_106 ( struct V_142 * V_143 )
{
struct V_6 * V_7 = (struct V_6 * ) F_28 ( V_143 ) ;
struct V_451 * V_452 = & V_7 -> V_453 ;
int V_454 = 0 ;
int V_455 = 0 ;
int V_456 = 0 ;
if ( F_33 ( & V_7 -> V_12 , V_219 ) != true ) {
V_452 -> V_134 . V_134 = 0 ;
V_452 -> V_134 . V_139 = 0 ;
V_452 -> V_134 . V_140 = 0 ;
} else {
V_454 = V_7 -> V_457 . V_458 ;
V_455 = V_7 -> V_457 . signal ;
V_456 = V_7 -> V_457 . V_140 ;
V_452 -> V_134 . V_139 = V_454 ;
V_452 -> V_134 . V_134 = V_455 ;
V_452 -> V_134 . V_140 = V_456 ;
}
V_452 -> V_134 . V_135 = V_459 ;
return & V_7 -> V_453 ;
}
