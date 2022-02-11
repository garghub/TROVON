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
F_6 ( V_9 . V_13 . V_16 ) ;
F_4 ( V_7 -> V_21 , V_22 , & V_9 , NULL ) ;
}
static inline void F_7 ( struct V_23 * V_24 ,
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
F_8 ( & V_7 -> V_36 . V_38 ,
V_39 + F_9 ( 50 ) ) ;
}
F_10 ( V_7 , ( unsigned char * ) V_24 , true ) ;
}
static inline void F_11 ( struct V_25 * V_26 ,
struct V_6 * V_7 )
{
if ( 0 < V_26 -> V_29 . V_30 . V_40 &&
V_26 -> V_29 . V_30 . V_40 < 3 ) {
memcpy ( V_7 -> V_36 . V_41 [ V_26 -> V_29 . V_30 .
V_40 - 1 ] . V_28 , V_26 -> V_29 . V_30 . V_31 , ( V_26 -> V_29 . V_30 . V_32
> 16 ? 16 : V_26 -> V_29 . V_30 . V_32 ) ) ;
memcpy ( V_7 -> V_36 . V_42 [ V_26 ->
V_29 . V_30 . V_40 - 1 ] . V_28 , & ( V_26 -> V_29 . V_30 . V_31 [ 16 ] ) , 8 ) ;
memcpy ( V_7 -> V_36 . V_43 [ V_26 ->
V_29 . V_30 . V_40 - 1 ] . V_28 , & ( V_26 -> V_29 . V_30 . V_31 [ 24 ] ) , 8 ) ;
V_7 -> V_36 . V_44 = true ;
F_12 ( V_7 , & V_7 -> V_36 ,
V_26 -> V_29 . V_30 . V_40 ) ;
if ( V_7 -> V_45 . V_46 > V_47 ) {
if ( V_7 -> V_45 . V_46 != V_7 ->
V_48 . V_49 )
F_8 ( & V_7 -> V_12 . V_50 ,
V_39 + F_9 ( 60000 ) ) ;
}
}
}
static inline char * F_13 ( struct V_6 * V_7 ,
struct V_51 * V_52 ,
struct V_53 * V_54 ,
char * V_55 , char * V_56 )
{
struct V_57 V_58 ;
struct V_59 * V_60 ;
char * V_61 ;
T_2 * V_62 ;
T_3 V_3 = 0 , V_63 = 0 ;
T_4 V_64 , V_65 = false , V_66 ;
T_1 V_67 ;
if ( ( V_54 -> V_18 . V_68 . V_69 < 1 ) ||
( V_54 -> V_18 . V_68 . V_69 > 14 ) ) {
if ( V_54 -> V_18 . V_68 . V_69 < 1 )
V_54 -> V_18 . V_68 . V_69 = 1 ;
else
V_54 -> V_18 . V_68 . V_69 = 14 ;
}
V_58 . V_70 = V_22 ;
V_58 . V_29 . V_13 . V_14 = V_15 ;
F_14 ( V_58 . V_29 . V_13 . V_16 , V_54 -> V_18 . V_19 ) ;
V_55 = F_15 ( V_52 , V_55 , V_56 , & V_58 , V_71 ) ;
V_58 . V_70 = V_72 ;
V_58 . V_29 . V_73 . V_74 = 1 ;
V_58 . V_29 . V_73 . V_75 = F_16 ( T_3 , V_54 -> V_18 . V_76 . V_77 , 32 ) ;
V_55 = F_17 ( V_52 , V_55 , V_56 , & V_58 ,
V_54 -> V_18 . V_76 . V_76 ) ;
V_62 = F_18 ( & V_54 -> V_18 . V_78 [ 12 ] , V_79 ,
& V_63 , V_54 -> V_18 . V_80 - 12 ) ;
if ( V_62 && V_63 > 0 ) {
V_65 = true ;
V_60 = (struct V_59 * ) ( V_62 + 2 ) ;
memcpy ( & V_66 , V_60 -> V_81 , 2 ) ;
}
V_58 . V_70 = V_82 ;
if ( F_19 ( V_54 -> V_18 . V_83 ) ) {
if ( V_65 == true )
snprintf ( V_58 . V_29 . V_84 , V_85 , L_2 ) ;
else
snprintf ( V_58 . V_29 . V_84 , V_85 , L_3 ) ;
} else if ( F_20 ( V_54 -> V_18 . V_83 ) ) {
if ( V_65 == true )
snprintf ( V_58 . V_29 . V_84 , V_85 , L_4 ) ;
else
snprintf ( V_58 . V_29 . V_84 , V_85 , L_5 ) ;
} else {
if ( V_65 == true )
snprintf ( V_58 . V_29 . V_84 , V_85 , L_6 ) ;
else
snprintf ( V_58 . V_29 . V_84 , V_85 , L_7 ) ;
}
V_55 = F_15 ( V_52 , V_55 , V_56 , & V_58 , V_86 ) ;
V_58 . V_70 = V_87 ;
memcpy ( ( T_1 * ) & V_64 , F_21 ( V_54 -> V_18 . V_78 ) ,
2 ) ;
V_64 = F_22 ( V_64 ) ;
if ( V_64 & ( V_88 | V_89 ) ) {
if ( V_64 & V_89 )
V_58 . V_29 . V_90 = ( T_3 ) V_91 ;
else
V_58 . V_29 . V_90 = ( T_3 ) V_92 ;
V_55 = F_15 ( V_52 , V_55 , V_56 , & V_58 ,
V_93 ) ;
}
V_58 . V_70 = V_94 ;
{
T_1 V_95 = V_54 -> V_18 . V_68 . V_69 ;
if ( V_95 >= 1 && V_95 <= sizeof(
V_96 ) / sizeof( long ) )
V_58 . V_29 . V_97 . V_98 = ( V_99 ) ( V_96 [
V_54 -> V_18 . V_68 .
V_69 - 1 ] * 100000 ) ;
else
V_58 . V_29 . V_97 . V_98 = 0 ;
}
V_58 . V_29 . V_97 . V_100 = ( V_101 ) 1 ;
V_58 . V_29 . V_97 . V_3 = ( T_1 ) V_54 -> V_18 . V_68 . V_69 ;
V_55 = F_15 ( V_52 , V_55 , V_56 , & V_58 ,
V_102 ) ;
V_58 . V_70 = V_103 ;
if ( V_64 & V_104 )
V_58 . V_29 . V_73 . V_74 = ( T_4 ) ( V_105 |
V_106 ) ;
else
V_58 . V_29 . V_73 . V_74 = ( T_4 ) ( V_107 ) ;
V_58 . V_29 . V_73 . V_75 = ( T_4 ) 0 ;
V_55 = F_17 ( V_52 , V_55 , V_56 , & V_58 ,
V_54 -> V_18 . V_76 . V_76 ) ;
V_61 = V_55 + F_23 ( V_52 ) ;
V_58 . V_70 = V_108 ;
V_58 . V_29 . V_109 . V_110 = 0 ;
V_58 . V_29 . V_109 . V_111 = 0 ;
V_58 . V_29 . V_109 . V_112 = 0 ;
V_3 = 0 ;
while ( V_54 -> V_18 . V_83 [ V_3 ] != 0 ) {
V_58 . V_29 . V_109 . V_112 = ( V_54 -> V_18 . V_83 [ V_3 ++ ] &
0x7F ) * 500000 ;
V_61 = F_24 ( V_52 , V_55 , V_61 ,
V_56 , & V_58 , V_113 ) ;
}
if ( ( V_61 - V_55 ) > F_23 ( V_52 ) )
V_55 = V_61 ;
{
T_1 V_114 [ V_115 ] ;
T_1 V_116 [ 255 ] , V_117 [ 255 ] ;
T_4 V_118 = 0 , V_119 = 0 ;
int V_120 ;
F_25 ( V_54 -> V_18 . V_78 ,
V_54 -> V_18 . V_80 , V_117 , & V_119 ,
V_116 , & V_118 ) ;
if ( V_118 > 0 ) {
memset ( V_114 , 0 , V_115 ) ;
V_120 = sprintf ( V_114 , L_8 ) ;
for ( V_3 = 0 ; V_3 < V_118 ; V_3 ++ ) {
V_120 += snprintf ( V_114 + V_120 , V_115 - V_120 ,
L_9 , V_116 [ V_3 ] ) ;
if ( V_120 >= V_115 )
break;
}
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_70 = V_121 ;
V_58 . V_29 . V_73 . V_75 = ( T_4 ) strlen ( V_114 ) ;
V_55 = F_17 ( V_52 , V_55 , V_56 ,
& V_58 , V_114 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_70 = V_122 ;
V_58 . V_29 . V_73 . V_75 = ( T_4 ) V_118 ;
V_55 = F_17 ( V_52 , V_55 , V_56 ,
& V_58 , V_116 ) ;
}
if ( V_119 > 0 ) {
memset ( V_114 , 0 , V_115 ) ;
V_120 = sprintf ( V_114 , L_10 ) ;
for ( V_3 = 0 ; V_3 < V_119 ; V_3 ++ ) {
V_120 += snprintf ( V_114 + V_120 , V_115 - V_120 ,
L_9 , V_117 [ V_3 ] ) ;
if ( V_120 >= V_115 )
break;
}
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_70 = V_121 ;
V_58 . V_29 . V_73 . V_75 = strlen ( V_114 ) ;
V_55 = F_17 ( V_52 , V_55 , V_56 ,
& V_58 , V_114 ) ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_70 = V_122 ;
V_58 . V_29 . V_73 . V_75 = V_119 ;
V_55 = F_17 ( V_52 , V_55 , V_56 , & V_58 ,
V_117 ) ;
}
}
{
T_1 V_123 [ 512 ] ;
T_5 V_124 ;
if ( F_26 ( V_54 -> V_18 . V_78 ,
V_54 -> V_18 . V_80 ,
V_123 , & V_124 ) == true ) {
if ( V_124 > 2 ) {
V_58 . V_70 = V_122 ;
V_58 . V_29 . V_73 . V_75 = ( T_4 ) V_124 ;
V_55 = F_17 ( V_52 , V_55 , V_56 ,
& V_58 , V_123 ) ;
}
}
}
V_58 . V_70 = V_125 ;
V_67 = F_27 ( V_54 -> V_18 . V_126 ) ;
V_58 . V_29 . V_127 . V_128 = ( T_1 ) ( V_129 | V_130 |
V_131 ) ;
V_58 . V_29 . V_127 . V_132 = V_67 ;
V_58 . V_29 . V_127 . V_127 = 0 ;
V_58 . V_29 . V_127 . V_133 = 0 ;
V_55 = F_15 ( V_52 , V_55 , V_56 , & V_58 , V_134 ) ;
return V_55 ;
}
static int F_28 ( struct V_135 * V_136 , T_3 V_112 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
int V_137 = 0 ;
if ( ( V_112 & V_138 ) && ( V_112 & V_139 ) ) {
V_7 -> V_36 . V_140 =
V_141 ;
V_7 -> V_36 . V_142 =
V_143 ;
V_7 -> V_36 . V_144 = 3 ;
} else if ( V_112 & V_138 ) {
V_7 -> V_36 . V_140 =
V_141 ;
V_7 -> V_36 . V_142 = V_145 ;
V_7 -> V_36 . V_144 = 1 ;
} else if ( V_112 & V_139 ) {
if ( V_7 -> V_36 . V_142 <
V_146 ) {
V_7 -> V_36 . V_142 =
V_147 ;
V_7 -> V_36 . V_144 = 0 ;
}
} else
V_137 = - V_148 ;
return V_137 ;
}
static int F_30 ( struct V_135 * V_136 , struct V_25 * V_26 ,
T_3 V_149 )
{
int V_137 = 0 ;
T_3 V_150 , V_151 = 0 ;
struct V_152 * V_153 = NULL ;
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_154 * V_155 = & V_7 -> V_36 ;
V_26 -> V_29 . V_30 . V_156 = 0 ;
V_26 -> V_29 . V_30 . V_33 [ V_157 - 1 ] = '\0' ;
if ( V_149 != ( T_3 ) ( ( T_1 * ) V_26 -> V_29 . V_30 . V_31 - ( T_1 * ) V_26 ) +
V_26 -> V_29 . V_30 . V_32 )
return - V_148 ;
if ( F_31 ( V_26 -> V_158 ) ) {
if ( V_26 -> V_29 . V_30 . V_40 >= V_159 ) {
V_26 -> V_29 . V_30 . V_40 = 0 ;
}
} else
return - V_148 ;
if ( strcmp ( V_26 -> V_29 . V_30 . V_33 , L_11 ) == 0 ) {
F_32 ( V_136 , L_12 , V_160 ) ;
V_7 -> V_36 . V_140 =
V_141 ;
V_7 -> V_36 . V_161 = V_162 ;
V_7 -> V_36 . V_163 = V_162 ;
V_150 = V_26 -> V_29 . V_30 . V_40 ;
V_151 = V_26 -> V_29 . V_30 . V_32 ;
if ( V_150 >= V_159 )
V_150 = 0 ;
if ( V_151 > 0 ) {
V_151 = V_151 <= 5 ? 5 : 13 ;
V_153 = F_33 ( ( T_3 ) ( V_151 +
F_34 ( struct V_152 ,
V_164 ) ) , V_165 ) ;
if ( V_153 == NULL )
return - V_166 ;
memset ( V_153 , 0 , sizeof( struct V_152 ) ) ;
V_153 -> V_167 = V_151 ;
V_153 -> V_168 = V_151 +
F_34 ( struct V_152 ,
V_164 ) ;
if ( V_151 == 13 ) {
V_7 -> V_36 . V_161 =
V_169 ;
V_7 -> V_36 . V_163 =
V_169 ;
}
} else
return - V_148 ;
V_153 -> V_170 = V_150 ;
V_153 -> V_170 |= 0x80000000 ;
memcpy ( V_153 -> V_164 , V_26 -> V_29 . V_30 . V_31 , V_153 -> V_167 ) ;
if ( V_26 -> V_29 . V_30 . V_171 ) {
if ( F_35 ( V_7 , V_153 ) ==
( T_1 ) V_172 )
V_137 = - V_173 ;
} else {
if ( V_150 >= V_159 ) {
V_137 = - V_173 ;
goto exit;
}
memcpy ( & ( V_155 -> V_174 [ V_150 ] .
V_28 [ 0 ] ) , V_153 -> V_164 ,
V_153 -> V_167 ) ;
V_155 -> V_175 [ V_150 ] =
V_153 -> V_167 ;
F_12 ( V_7 , V_155 , V_150 ) ;
}
goto exit;
}
if ( V_7 -> V_36 . V_144 == 2 ) {
struct V_23 * V_24 , * V_176 ;
struct V_177 * V_178 = & V_7 -> V_179 ;
if ( F_36 ( V_11 , V_180 |
V_181 ) == true ) {
V_24 = F_37 ( V_178 ,
F_38 ( V_11 ) ) ;
if ( V_24 ) {
V_24 -> V_182 = false ;
if ( ( V_7 -> V_36 . V_140 ==
V_183 ) ||
( V_7 -> V_36 . V_140 ==
V_184 ) )
V_24 -> V_185 = V_7 ->
V_36 . V_161 ;
if ( V_26 -> V_29 . V_30 . V_171 == 1 )
F_7 ( V_24 , V_26 ,
V_7 ) ;
else
F_11 ( V_26 , V_7 ) ;
}
V_176 = F_39 ( V_7 ) ;
if ( V_176 ) {
V_176 -> V_182 = false ;
if ( ( V_7 -> V_36 . V_140 ==
V_183 ) ||
( V_7 -> V_36 . V_140 ==
V_184 ) )
V_176 -> V_185 =
V_7 -> V_36 .
V_161 ;
}
}
}
exit:
F_40 ( V_153 ) ;
return V_137 ;
}
static int F_41 ( struct V_6 * V_7 , char * V_186 ,
unsigned short V_187 )
{
T_1 * V_114 = NULL ;
int V_188 = 0 , V_189 = 0 ;
int V_137 = 0 ;
if ( ( V_187 > V_115 ) || ( V_186 == NULL ) )
return - V_148 ;
if ( V_187 ) {
V_114 = F_42 ( V_186 , V_187 , V_165 ) ;
if ( V_114 == NULL )
return - V_166 ;
if ( V_187 < V_190 ) {
V_137 = - V_148 ;
goto exit;
}
if ( F_43 ( V_114 , V_187 , & V_188 ,
& V_189 ) == V_191 ) {
V_7 -> V_36 . V_144 = 2 ;
V_7 -> V_36 . V_142 =
V_146 ;
}
if ( F_44 ( V_114 , V_187 , & V_188 ,
& V_189 ) == V_191 ) {
V_7 -> V_36 . V_144 = 2 ;
V_7 -> V_36 . V_142 =
V_192 ;
}
switch ( V_188 ) {
case V_193 :
V_7 -> V_36 . V_163 =
V_194 ;
V_7 -> V_36 . V_140 =
V_195 ;
break;
case V_196 :
V_7 -> V_36 . V_163 = V_162 ;
V_7 -> V_36 . V_140 =
V_141 ;
break;
case V_197 :
V_7 -> V_36 . V_163 = V_198 ;
V_7 -> V_36 . V_140 =
V_183 ;
break;
case V_199 :
V_7 -> V_36 . V_163 = V_200 ;
V_7 -> V_36 . V_140 =
V_184 ;
break;
case V_201 :
V_7 -> V_36 . V_163 = V_169 ;
V_7 -> V_36 . V_140 =
V_141 ;
break;
}
switch ( V_189 ) {
case V_193 :
V_7 -> V_36 . V_161 =
V_194 ;
V_7 -> V_36 . V_140 =
V_195 ;
break;
case V_196 :
V_7 -> V_36 . V_161 = V_162 ;
V_7 -> V_36 . V_140 =
V_141 ;
break;
case V_197 :
V_7 -> V_36 . V_161 = V_198 ;
V_7 -> V_36 . V_140 =
V_183 ;
break;
case V_199 :
V_7 -> V_36 . V_161 = V_200 ;
V_7 -> V_36 . V_140 =
V_184 ;
break;
case V_201 :
V_7 -> V_36 . V_161 = V_169 ;
V_7 -> V_36 . V_140 =
V_141 ;
break;
}
V_7 -> V_36 . V_202 = false ;
{
T_4 V_203 = 0 ;
T_1 V_204 , V_205 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_203 < V_187 ) {
V_204 = V_114 [ V_203 ] ;
if ( ( V_204 == V_206 ) &&
( ! memcmp ( & V_114 [ V_203 + 2 ] , V_205 , 4 ) ) ) {
F_32 ( V_7 -> V_21 , L_13 ) ;
V_7 -> V_36 . V_207 =
( ( V_114 [ V_203 + 1 ] + 2 ) <
( V_115 << 2 ) ) ?
( V_114 [ V_203 + 1 ] + 2 ) :
( V_115 << 2 ) ;
memcpy ( V_7 -> V_36 . V_123 ,
& V_114 [ V_203 ] ,
V_7 -> V_36 . V_207 ) ;
V_7 -> V_36 . V_202 =
true ;
F_32 ( V_7 -> V_21 , L_14 ) ;
V_203 += V_114 [ V_203 + 1 ] + 2 ;
break;
} else
V_203 += V_114 [ V_203 + 1 ] + 2 ;
}
}
}
exit:
F_40 ( V_114 ) ;
return V_137 ;
}
static int F_45 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
T_3 V_63 = 0 ;
char * V_62 ;
T_1 V_65 = false ;
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
struct V_209 * V_210 = & V_11 -> V_17 . V_18 ;
T_1 * V_211 ;
if ( F_36 ( V_11 , V_212 | V_213 ) ==
true ) {
V_62 = F_18 ( & V_210 -> V_78 [ 12 ] , V_79 ,
& V_63 , V_210 -> V_80 - 12 ) ;
if ( V_62 && V_63 > 0 )
V_65 = true ;
V_211 = V_210 -> V_83 ;
if ( F_19 ( V_211 ) == true ) {
if ( V_65 == true )
snprintf ( V_9 -> V_84 , V_85 ,
L_2 ) ;
else
snprintf ( V_9 -> V_84 , V_85 ,
L_3 ) ;
} else if ( ( F_20 ( V_211 ) ) == true ) {
if ( V_65 == true )
snprintf ( V_9 -> V_84 , V_85 ,
L_4 ) ;
else
snprintf ( V_9 -> V_84 , V_85 ,
L_5 ) ;
} else {
if ( V_65 == true )
snprintf ( V_9 -> V_84 , V_85 ,
L_6 ) ;
else
snprintf ( V_9 -> V_84 , V_85 ,
L_7 ) ;
}
} else
snprintf ( V_9 -> V_84 , V_85 , L_15 ) ;
return 0 ;
}
static int F_46 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_214 * V_215 = & V_9 -> V_97 ;
int V_216 = 0 ;
if ( ( V_215 -> V_100 == 1 ) &&
( V_215 -> V_98 >= ( int ) 2.412e8 ) &&
( V_215 -> V_98 <= ( int ) 2.487e8 ) ) {
int V_217 = V_215 -> V_98 / 100000 ;
int V_218 = 0 ;
while ( ( V_218 < 14 ) && ( V_217 != V_219 [ V_218 ] ) )
V_218 ++ ;
V_215 -> V_100 = 0 ;
V_215 -> V_98 = V_218 + 1 ;
}
if ( ( V_215 -> V_98 > 14 ) || ( V_215 -> V_100 > 0 ) )
V_216 = - V_173 ;
else {
int V_220 = V_215 -> V_98 ;
if ( ( V_220 < 1 ) || ( V_220 > 14 ) )
V_216 = - V_148 ;
else {
V_7 -> V_45 . V_220 = V_220 ;
}
}
return V_216 ;
}
static int F_47 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_209 * V_210 = & V_11 -> V_17 . V_18 ;
if ( F_36 ( V_11 , V_212 ) == true ) {
V_9 -> V_97 . V_98 = V_96 [
V_210 -> V_68 . V_69 - 1 ] * 100000 ;
V_9 -> V_97 . V_100 = 1 ;
V_9 -> V_97 . V_3 = V_210 -> V_68 . V_69 ;
} else {
return - V_221 ;
}
return 0 ;
}
static int F_48 ( struct V_135 * V_136 ,
struct V_51 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
enum V_222 V_223 ;
switch ( V_9 -> V_90 ) {
case V_224 :
V_223 = V_225 ;
break;
case V_92 :
V_223 = V_226 ;
break;
case V_91 :
V_223 = V_227 ;
break;
case V_228 :
V_223 = V_229 ;
break;
default:
return - V_148 ;
}
if ( V_227 == V_223 )
F_49 ( V_7 , V_223 ) ;
else
F_49 ( V_7 , V_225 ) ;
F_50 ( V_7 , V_223 ) ;
return 0 ;
}
static int F_51 ( struct V_135 * V_136 , struct V_51 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
if ( F_36 ( V_11 , V_180 ) == true )
V_9 -> V_90 = V_228 ;
else if ( F_36 ( V_11 ,
V_213 | V_230 ) == true )
V_9 -> V_90 = V_92 ;
else if ( F_36 ( V_11 , V_231 ) == true )
V_9 -> V_90 = V_91 ;
else
V_9 -> V_90 = V_224 ;
return 0 ;
}
static int F_52 ( struct V_135 * V_136 ,
struct V_51 * V_4 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_154 * V_155 = & V_7 -> V_36 ;
struct V_232 * V_233 = (struct V_232 * ) V_208 ;
T_1 V_234 [ V_20 ] = { 0x00 } ;
T_1 V_235 [ V_20 ] = { 0x00 } ;
T_1 V_236 , V_237 = false ;
int V_238 = false ;
if ( V_233 == NULL )
return - V_148 ;
memcpy ( V_235 , V_233 -> V_239 . V_16 , V_20 ) ;
switch ( V_233 -> V_70 ) {
case V_240 :
if ( ! memcmp ( V_235 , V_234 , V_20 ) )
return V_238 ;
V_238 = true ;
V_237 = false ;
for ( V_236 = 0 ; V_236 < V_241 ; V_236 ++ ) {
if ( ! memcmp ( V_155 -> V_242 [ V_236 ] . V_243 ,
V_235 , V_20 ) ) {
F_32 ( V_136 , L_16 ,
V_160 ) ;
memcpy ( V_155 -> V_242 [ V_236 ] . V_244 ,
V_233 -> V_245 , V_246 ) ;
V_155 -> V_242 [ V_236 ] . V_247 = true ;
V_155 -> V_248 = V_236 + 1 ;
V_237 = true ;
break;
}
}
if ( ! V_237 ) {
F_32 ( V_136 , L_17 ,
V_160 , V_155 -> V_248 ) ;
memcpy ( V_155 -> V_242 [ V_155 ->
V_248 ] . V_243 , V_235 , V_20 ) ;
memcpy ( V_155 -> V_242 [ V_155 ->
V_248 ] . V_244 , V_233 -> V_245 , V_246 ) ;
V_155 -> V_242 [ V_155 -> V_248 ] .
V_247 = true ;
V_155 -> V_248 ++ ;
if ( V_155 -> V_248 == V_241 )
V_155 -> V_248 = 0 ;
}
break;
case V_249 :
V_238 = true ;
for ( V_236 = 0 ; V_236 < V_241 ; V_236 ++ ) {
if ( ! memcmp ( V_155 -> V_242 [ V_236 ] . V_243 ,
V_235 , V_20 ) ) {
F_6 ( V_155 -> V_242 [ V_236 ] . V_243 ) ;
V_155 -> V_242 [ V_236 ] . V_247 = false ;
break;
}
}
break;
case V_250 :
memset ( V_155 -> V_242 , 0 ,
sizeof( struct V_251 ) * V_241 ) ;
V_155 -> V_248 = 0 ;
V_238 = true ;
break;
default:
F_32 ( V_136 , L_18 , V_160 ) ;
V_238 = false ;
break;
}
return V_238 ;
}
static int F_53 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
V_9 -> V_252 . V_112 = 0 ;
V_9 -> V_252 . V_110 = 0 ;
V_9 -> V_252 . V_111 = 1 ;
return 0 ;
}
static int F_54 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_253 * V_254 = (struct V_253 * ) V_208 ;
T_4 V_255 ;
int V_3 ;
V_9 -> V_73 . V_75 = sizeof( * V_254 ) ;
memset ( V_254 , 0 , sizeof( * V_254 ) ) ;
V_254 -> V_256 = 5 * 1000 * 1000 ;
V_254 -> V_257 . V_127 = 100 ;
V_254 -> V_257 . V_132 = 100 ;
V_254 -> V_257 . V_133 = 100 ;
V_254 -> V_257 . V_128 = 7 ;
V_254 -> V_258 . V_127 = 92 ;
V_254 -> V_258 . V_132 = 20 + - 98 ;
V_254 -> V_258 . V_133 = 0 ;
V_254 -> V_258 . V_128 = 7 ;
V_254 -> V_259 = V_260 ;
for ( V_3 = 0 ; V_3 < V_260 && V_3 < V_261 ; V_3 ++ )
V_254 -> V_109 [ V_3 ] = V_262 [ V_3 ] ;
V_254 -> V_263 = V_264 ;
V_254 -> V_265 = V_266 ;
V_254 -> V_267 = 0 ;
V_254 -> V_268 = V_269 ;
V_254 -> V_270 = 16 ;
V_254 -> V_271 = 14 ;
for ( V_3 = 0 , V_255 = 0 ; V_3 < 14 ; V_3 ++ ) {
V_254 -> V_97 [ V_255 ] . V_3 = V_3 + 1 ;
V_254 -> V_97 [ V_255 ] . V_98 = V_96 [ V_3 ] * 100000 ;
V_254 -> V_97 [ V_255 ] . V_100 = 1 ;
V_255 ++ ;
if ( V_255 == V_272 )
break;
}
V_254 -> V_273 = V_255 ;
V_254 -> V_274 = V_275 |
V_276 |
V_277 |
V_278 ;
return 0 ;
}
static int F_55 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_279 ,
char * V_208 )
{
int V_137 = 0 , V_280 = 0 ;
char * V_281 ;
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_282 * V_283 = (struct V_282 * ) V_279 ;
V_280 = V_283 -> V_75 ;
V_281 = F_56 ( V_283 -> V_284 , V_280 ) ;
if ( F_57 ( V_281 ) )
return F_58 ( V_281 ) ;
if ( 0 == strcasecmp ( V_281 , L_19 ) ) {
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
struct V_53 * V_285 = & V_11 -> V_17 ;
if ( F_36 ( V_11 , V_212 ) == true ) {
sprintf ( V_281 , L_20 ,
V_285 -> V_18 . V_76 . V_76 ,
( ( V_7 -> V_286 . V_287 ) >> 1 ) - 95
) ;
} else {
sprintf ( V_281 , L_21 ) ;
}
} else if ( 0 == strcasecmp ( V_281 , L_22 ) ) {
union V_8 V_288 ;
int V_289 ;
int V_290 ;
V_289 = F_59 ( V_136 , V_52 , & V_288 , V_208 ) ;
if ( 0 != V_289 )
V_290 = 0 ;
else
V_290 = V_288 . V_109 . V_112 / 1000000 ;
sprintf ( V_281 , L_23 , V_290 ) ;
} else if ( 0 == strcasecmp ( V_281 , L_24 ) ) {
sprintf ( V_281 , L_25 , V_136 -> V_291 ) ;
} else if ( 0 == strcasecmp ( V_281 , L_26 ) ) {
struct V_10 * V_11 = & V_7 -> V_12 ;
V_11 -> V_292 = 1 ;
sprintf ( V_281 , L_21 ) ;
} else if ( 0 == strcasecmp ( V_281 , L_27 ) ) {
struct V_10 * V_11 = & V_7 -> V_12 ;
V_11 -> V_292 = 0 ;
sprintf ( V_281 , L_21 ) ;
} else if ( 0 == strncmp ( V_281 , L_28 , 5 ) ) {
F_60 ( V_7
, 1
, 5
, 100
, 5000
) ;
sprintf ( V_281 , L_21 ) ;
} else if ( 0 == strncmp ( V_281 , L_29 , 5 ) ) {
F_60 ( V_7
, 0
, 5
, 100
, 5000
) ;
sprintf ( V_281 , L_21 ) ;
} else {
F_32 ( V_136 , L_30 ,
V_160 , V_281 ) ;
goto V_293;
}
if ( F_61 ( V_283 -> V_284 , V_281 ,
F_62 ( V_283 -> V_75 , ( V_294 ) ( strlen ( V_281 ) + 1 ) ) ) )
V_137 = - V_295 ;
V_293:
F_40 ( V_281 ) ;
return V_137 ;
}
static int F_63 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_279 ,
char * V_208 )
{
int V_137 = - V_296 ;
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_297 * V_298 = & V_11 -> V_299 ;
struct V_300 * V_301 = (struct V_300 * ) V_279 ;
unsigned long V_302 ;
struct V_303 * V_304 ;
T_1 * V_305 ;
struct V_53 * V_54 = NULL ;
enum V_306 V_307 ;
if ( F_36 ( V_11 , V_308 ) == true )
return - V_309 ;
if ( F_36 ( V_11 , V_310 ) == true )
return V_137 ;
if ( V_301 -> V_14 != V_15 )
return - V_148 ;
V_307 = V_7 -> V_36 . V_142 ;
F_64 ( & V_298 -> V_311 , V_302 ) ;
V_304 = & V_298 -> V_298 ;
V_11 -> V_312 = V_304 -> V_313 ;
while ( 1 ) {
if ( F_65 ( V_304 , V_11 -> V_312 ) == true )
break;
V_54 = F_66 ( V_11 -> V_312 ,
struct V_53 , V_314 ) ;
V_11 -> V_312 = V_11 -> V_312 -> V_313 ;
V_305 = V_54 -> V_18 . V_19 ;
if ( ! memcmp ( V_305 , V_301 -> V_16 , V_20 ) ) {
F_50 ( V_7 ,
V_54 -> V_18 . V_315 ) ;
break;
}
}
F_67 ( & V_298 -> V_311 , V_302 ) ;
if ( ! V_137 ) {
if ( ! F_68 ( V_7 , V_307 ) )
V_137 = - V_166 ;
else {
if ( ! F_69 ( V_7 , V_301 -> V_16 ) )
V_137 = - 1 ;
}
}
return V_137 ;
}
static int F_70 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_209 * V_210 = & V_11 -> V_17 . V_18 ;
V_9 -> V_13 . V_14 = V_15 ;
if ( F_36 ( V_11 , V_212 | V_213 |
V_231 ) )
F_14 ( V_9 -> V_13 . V_16 , V_210 -> V_19 ) ;
else
F_6 ( V_9 -> V_13 . V_16 ) ;
return 0 ;
}
static int F_71 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
int V_137 = 0 ;
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_316 * V_317 = (struct V_316 * ) V_208 ;
if ( V_317 == NULL )
return - 1 ;
switch ( V_317 -> V_70 ) {
case V_318 :
if ( ! F_72 ( V_7 ) )
V_137 = - 1 ;
break;
case V_319 :
if ( ! F_72 ( V_7 ) )
V_137 = - 1 ;
break;
default:
return - V_173 ;
}
return V_137 ;
}
static int F_73 ( struct V_135 * V_136 ,
struct V_51 * V_4 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
T_1 V_320 = true ;
if ( V_7 -> V_321 == true ) {
F_32 ( V_136 , L_31 ,
V_160 , V_7 -> V_321 ) ;
return - 1 ;
}
if ( V_7 -> V_322 == false )
return - V_323 ;
if ( V_7 -> V_324 == false )
return - 1 ;
if ( ( F_36 ( V_11 , V_308 | V_310 ) ) ||
( V_11 -> V_325 . V_326 == true ) )
return 0 ;
if ( V_9 -> V_73 . V_75 == sizeof( struct V_327 ) ) {
struct V_327 * V_328 = (struct V_327 * ) V_208 ;
if ( V_9 -> V_73 . V_74 & V_329 ) {
struct V_330 V_331 ;
unsigned long V_302 ;
T_3 V_280 = F_16 ( T_1 , V_328 -> V_332 , V_333 ) ;
memset ( ( unsigned char * ) & V_331 , 0 ,
sizeof( struct V_330 ) ) ;
memcpy ( V_331 . V_76 , V_328 -> V_334 , V_280 ) ;
V_331 . V_77 = V_280 ;
F_64 ( & V_11 -> V_311 , V_302 ) ;
if ( ( F_36 ( V_11 , V_308 |
V_310 ) ) ||
( V_11 -> V_325 . V_326 == true ) ) {
if ( F_36 ( V_11 , V_310 ) )
V_320 = false ;
} else
V_320 = F_74 ( V_7 , & V_331 ) ;
F_67 ( & V_11 -> V_311 , V_302 ) ;
}
} else
V_320 = F_75 ( V_7 ) ;
if ( V_320 == false )
return - 1 ;
return 0 ;
}
static int F_76 ( struct V_135 * V_136 ,
struct V_51 * V_4 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_297 * V_298 = & V_11 -> V_299 ;
struct V_53 * V_54 = NULL ;
unsigned long V_302 ;
struct V_303 * V_335 , * V_304 ;
char * V_336 = V_208 ;
char * V_56 = V_336 + V_9 -> V_73 . V_75 ;
T_3 V_137 = 0 , V_203 = 0 ;
if ( V_7 -> V_321 )
return - V_148 ;
while ( F_36 ( V_11 , V_308 | V_310 ) ) {
F_77 ( 30 ) ;
V_203 ++ ;
if ( V_203 > 100 )
break;
}
F_64 ( & V_298 -> V_311 , V_302 ) ;
V_304 = & V_298 -> V_298 ;
V_335 = V_304 -> V_313 ;
while ( 1 ) {
if ( F_65 ( V_304 , V_335 ) == true )
break;
if ( ( V_56 - V_336 ) < V_337 ) {
V_137 = - V_338 ;
break;
}
V_54 = F_66 ( V_335 , struct V_53 , V_314 ) ;
V_336 = F_13 ( V_7 , V_4 , V_54 , V_336 , V_56 ) ;
V_335 = V_335 -> V_313 ;
}
F_67 ( & V_298 -> V_311 , V_302 ) ;
V_9 -> V_73 . V_75 = V_336 - V_208 ;
V_9 -> V_73 . V_74 = 0 ;
return V_137 ;
}
static int F_78 ( struct V_135 * V_136 ,
struct V_51 * V_4 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_297 * V_298 = & V_11 -> V_299 ;
struct V_53 * V_54 = NULL ;
enum V_306 V_307 ;
struct V_330 V_339 ;
T_1 * V_340 , * V_341 ;
struct V_303 * V_304 ;
T_3 V_280 ;
if ( F_36 ( V_11 , V_308 ) )
return - V_309 ;
if ( F_36 ( V_11 , V_310 ) )
return 0 ;
if ( V_9 -> V_334 . V_75 > V_333 )
return - V_338 ;
V_307 = V_7 -> V_36 . V_142 ;
if ( V_9 -> V_334 . V_74 && V_9 -> V_334 . V_75 ) {
V_280 = ( V_9 -> V_334 . V_75 < V_333 ) ?
V_9 -> V_334 . V_75 : V_333 ;
memset ( & V_339 , 0 , sizeof( struct V_330 ) ) ;
V_339 . V_77 = V_280 ;
memcpy ( V_339 . V_76 , V_208 , V_280 ) ;
V_341 = V_339 . V_76 ;
V_304 = & V_298 -> V_298 ;
V_11 -> V_312 = V_304 -> V_313 ;
while ( 1 ) {
if ( F_65 ( V_304 , V_11 -> V_312 ) )
break;
V_54 = F_66 ( V_11 -> V_312 ,
struct V_53 , V_314 ) ;
V_11 -> V_312 = V_11 -> V_312 -> V_313 ;
V_340 = V_54 -> V_18 . V_76 . V_76 ;
if ( ( ! memcmp ( V_340 , V_341 , V_339 . V_77 ) )
&& ( V_54 -> V_18 . V_76 . V_77 ==
V_339 . V_77 ) ) {
if ( F_36 ( V_11 ,
V_230 ) ) {
if ( V_54 -> V_18 .
V_315
!=
V_7 -> V_12 .
V_17 . V_18 .
V_315 )
continue;
}
F_50 (
V_7 ,
V_54 -> V_18 . V_315 ) ;
break;
}
}
F_68 ( V_7 , V_307 ) ;
F_79 ( V_7 , & V_339 ) ;
}
return - V_296 ;
}
static int F_80 ( struct V_135 * V_136 ,
struct V_51 * V_4 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_209 * V_210 = & V_11 -> V_17 . V_18 ;
T_3 V_280 , V_137 = 0 ;
if ( F_36 ( V_11 , V_212 | V_213 ) ) {
V_280 = V_210 -> V_76 . V_77 ;
V_9 -> V_334 . V_75 = V_280 ;
memcpy ( V_208 , V_210 -> V_76 . V_76 , V_280 ) ;
V_9 -> V_334 . V_74 = 1 ;
} else {
V_137 = - V_221 ;
}
return V_137 ;
}
static int F_81 ( struct V_135 * V_136 ,
struct V_51 * V_4 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
T_3 V_342 = V_9 -> V_109 . V_112 ;
T_3 V_110 = V_9 -> V_109 . V_110 ;
T_3 V_343 = 0 ;
T_1 V_344 [ V_345 ] ;
T_1 V_346 [ V_345 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
int V_3 , V_137 = 0 ;
if ( V_342 == - 1 ) {
V_343 = 11 ;
goto V_347;
}
V_342 = V_342 / 100000 ;
switch ( V_342 ) {
case 10 :
V_343 = 0 ;
break;
case 20 :
V_343 = 1 ;
break;
case 55 :
V_343 = 2 ;
break;
case 60 :
V_343 = 3 ;
break;
case 90 :
V_343 = 4 ;
break;
case 110 :
V_343 = 5 ;
break;
case 120 :
V_343 = 6 ;
break;
case 180 :
V_343 = 7 ;
break;
case 240 :
V_343 = 8 ;
break;
case 360 :
V_343 = 9 ;
break;
case 480 :
V_343 = 10 ;
break;
case 540 :
V_343 = 11 ;
break;
default:
V_343 = 11 ;
break;
}
V_347:
for ( V_3 = 0 ; V_3 < V_345 ; V_3 ++ ) {
if ( V_343 == V_346 [ V_3 ] ) {
V_344 [ V_3 ] = V_346 [ V_3 ] ;
if ( V_110 == 0 )
break;
} else
V_344 [ V_3 ] = 0xff ;
}
if ( F_82 ( V_7 , V_344 ) != V_191 )
V_137 = - V_166 ;
return V_137 ;
}
static int F_59 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_209 * V_210 = & V_11 -> V_17 . V_18 ;
struct V_59 * V_60 ;
unsigned char V_348 = V_7 -> V_45 . V_349 ;
int V_3 ;
T_1 * V_62 ;
T_4 V_350 , V_351 = 0 , V_65 = false ;
T_3 V_63 = 0 ;
T_1 V_352 = 0 , V_353 = 0 ;
T_4 V_66 = 0 ;
V_3 = 0 ;
if ( F_36 ( V_11 , V_212 | V_213 ) ) {
V_62 = F_18 ( & V_210 -> V_78 [ 12 ] ,
V_79 , & V_63 ,
V_210 -> V_80 - 12 ) ;
if ( V_62 && V_63 > 0 ) {
V_65 = true ;
V_60 = (struct V_59 * ) ( V_62 + 2 ) ;
memcpy ( & V_66 , V_60 -> V_81 , 2 ) ;
V_352 = ( V_60 -> V_354 &
V_355 ) ? 1 : 0 ;
V_353 = ( V_60 -> V_354 &
( V_356 |
V_357 ) ) ? 1 : 0 ;
}
while ( ( V_210 -> V_83 [ V_3 ] != 0 ) &&
( V_210 -> V_83 [ V_3 ] != 0xFF ) ) {
V_350 = V_210 -> V_83 [ V_3 ] & 0x7F ;
if ( V_350 > V_351 )
V_351 = V_350 ;
V_9 -> V_109 . V_110 = 0 ;
V_9 -> V_109 . V_112 = V_350 * 500000 ;
V_3 ++ ;
}
if ( V_65 == true ) {
if ( V_66 & 0x8000
&&
V_358 == V_348 )
V_351 = ( V_352 ) ? ( ( V_353 ) ? 300 :
270 ) : ( ( V_353 ) ? 144 : 130 ) ;
else
V_351 = ( V_352 ) ? ( ( V_353 ) ? 150 :
135 ) : ( ( V_353 ) ? 72 : 65 ) ;
V_351 *= 2 ;
}
V_9 -> V_109 . V_112 = V_351 * 500000 ;
} else
return - V_221 ;
return 0 ;
}
static int F_83 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
V_9 -> V_359 . V_112 = V_7 -> V_45 . V_360 ;
V_9 -> V_359 . V_110 = 0 ;
return 0 ;
}
static int F_84 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
if ( V_9 -> V_361 . V_111 )
V_7 -> V_362 . V_363 = V_266 ;
else {
if ( V_9 -> V_361 . V_112 < V_264 ||
V_9 -> V_361 . V_112 > V_266 )
return - V_148 ;
V_7 -> V_362 . V_363 = V_9 -> V_361 . V_112 & ~ 0x1 ;
}
return 0 ;
}
static int F_85 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
V_9 -> V_361 . V_112 = V_7 -> V_362 . V_363 ;
V_9 -> V_361 . V_110 = 0 ;
return 0 ;
}
static int F_86 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
V_9 -> V_364 . V_112 = 7 ;
V_9 -> V_364 . V_110 = 0 ;
V_9 -> V_364 . V_111 = 1 ;
return 0 ;
}
static int F_87 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_365 )
{
T_3 V_31 ;
T_3 V_366 ;
struct V_152 V_367 ;
enum V_306 V_307 ;
struct V_282 * V_368 = & ( V_9 -> V_369 ) ;
struct V_6 * V_7 = F_29 ( V_136 ) ;
V_31 = V_368 -> V_74 & V_370 ;
memset ( & V_367 , 0 , sizeof( struct V_152 ) ) ;
if ( V_368 -> V_74 & V_107 ) {
F_32 ( V_136 , L_32 , V_160 ) ;
V_7 -> V_36 . V_140 =
V_195 ;
V_7 -> V_36 . V_161 = V_194 ;
V_7 -> V_36 . V_163 = V_194 ;
V_7 -> V_36 . V_144 = 0 ;
V_307 = V_147 ;
V_7 -> V_36 . V_142 = V_307 ;
return 0 ;
}
if ( V_31 ) {
if ( V_31 > V_159 )
return - V_148 ;
V_31 -- ;
V_366 = 1 ;
} else {
V_366 = 0 ;
V_31 = V_7 -> V_36 . V_371 ;
}
if ( V_368 -> V_74 & V_372 ) {
F_32 ( V_136 , L_33 , V_160 ) ;
V_7 -> V_36 . V_140 =
V_141 ;
V_7 -> V_36 . V_144 = 0 ;
V_7 -> V_36 . V_161 = V_194 ;
V_7 -> V_36 . V_163 = V_194 ;
V_307 = V_147 ;
V_7 -> V_36 . V_142 = V_307 ;
} else if ( V_368 -> V_74 & V_373 ) {
F_32 ( V_136 ,
L_34 , V_160 ) ;
V_7 -> V_36 . V_140 =
V_141 ;
V_7 -> V_36 . V_144 = 1 ;
V_7 -> V_36 . V_161 = V_162 ;
V_7 -> V_36 . V_163 = V_162 ;
V_307 = V_145 ;
V_7 -> V_36 . V_142 = V_307 ;
} else {
V_7 -> V_36 . V_140 =
V_141 ;
V_7 -> V_36 . V_144 = 0 ;
V_7 -> V_36 . V_161 = V_194 ;
V_7 -> V_36 . V_163 = V_194 ;
V_307 = V_147 ;
V_7 -> V_36 . V_142 = V_307 ;
}
V_367 . V_170 = V_31 ;
if ( V_368 -> V_75 > 0 ) {
V_367 . V_167 = V_368 -> V_75 <= 5 ? 5 : 13 ;
V_367 . V_168 = V_367 . V_167 +
F_34 ( struct V_152 , V_164 ) ;
} else {
V_367 . V_167 = 0 ;
if ( V_366 == 1 ) {
V_7 -> V_36 . V_371 = V_31 ;
switch ( V_7 -> V_36 . V_175 [ V_31 ] ) {
case 5 :
V_7 -> V_36 . V_161 =
V_162 ;
break;
case 13 :
V_7 -> V_36 . V_161 =
V_169 ;
break;
default:
V_7 -> V_36 . V_161 =
V_194 ;
break;
}
return 0 ;
}
}
V_367 . V_170 |= 0x80000000 ;
memcpy ( V_367 . V_164 , V_365 , V_367 . V_167 ) ;
if ( F_35 ( V_7 , & V_367 ) == V_172 )
return - V_173 ;
return 0 ;
}
static int F_88 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_365 )
{
T_5 V_31 , V_137 = 0 ;
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_282 * V_368 = & ( V_9 -> V_369 ) ;
struct V_10 * V_11 = & ( V_7 -> V_12 ) ;
if ( F_36 ( V_11 , V_212 ) == false ) {
if ( ! F_36 ( V_11 , V_213 ) ) {
V_368 -> V_75 = 0 ;
V_368 -> V_74 |= V_107 ;
return 0 ;
}
}
V_31 = V_368 -> V_74 & V_370 ;
if ( V_31 ) {
if ( V_31 > V_159 )
return - V_148 ;
V_31 -- ;
} else {
V_31 = V_7 -> V_36 . V_371 ;
}
V_368 -> V_74 = V_31 + 1 ;
switch ( V_7 -> V_36 . V_140 ) {
case V_374 :
case V_195 :
V_368 -> V_75 = 0 ;
V_368 -> V_74 |= V_107 ;
break;
case V_141 :
V_368 -> V_75 = V_7 -> V_36 . V_175 [ V_31 ] ;
if ( V_368 -> V_75 ) {
memcpy ( V_365 , V_7 -> V_36 . V_174 [
V_31 ] . V_28 , V_7 -> V_36 .
V_175 [ V_31 ] ) ;
V_368 -> V_74 |= V_105 ;
if ( V_7 -> V_36 . V_142 ==
V_147 )
V_368 -> V_74 |= V_372 ;
else if ( V_7 -> V_36 . V_142 ==
V_145 )
V_368 -> V_74 |= V_373 ;
} else {
V_368 -> V_75 = 0 ;
V_368 -> V_74 |= V_107 ;
}
break;
case V_183 :
case V_184 :
V_368 -> V_75 = 16 ;
V_368 -> V_74 |= ( V_105 | V_372 |
V_106 ) ;
break;
default:
V_368 -> V_75 = 0 ;
V_368 -> V_74 |= V_107 ;
break;
}
return V_137 ;
}
static int F_89 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
V_9 -> V_375 . V_112 = 0 ;
V_9 -> V_375 . V_110 = 0 ;
V_9 -> V_375 . V_111 = 1 ;
return 0 ;
}
static int F_90 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
return F_41 ( V_7 , V_208 , V_9 -> V_73 . V_75 ) ;
}
static int F_91 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_376 * V_26 = (struct V_376 * ) & ( V_9 -> V_26 ) ;
int V_377 ;
int V_378 ;
int V_137 = 0 ;
V_377 = V_26 -> V_74 & V_379 ;
V_378 = V_26 -> V_112 ;
switch ( V_377 ) {
case V_380 :
break;
case V_381 :
break;
case V_382 :
break;
case V_383 :
break;
case V_384 :
if ( V_378 ) {
V_7 -> V_36 . V_385 = true ;
} else {
V_7 -> V_36 . V_385 = false ;
}
break;
case V_386 :
if ( V_7 -> V_36 . V_140 ==
V_141 ) {
break;
}
if ( V_378 ) {
V_7 -> V_36 . V_140 =
V_195 ;
V_7 -> V_36 . V_161 =
V_194 ;
V_7 -> V_36 . V_163 =
V_194 ;
V_7 -> V_36 . V_144 = 0 ;
V_7 -> V_36 . V_142 =
V_147 ;
}
break;
case V_387 :
V_137 = F_28 ( V_136 , ( T_3 ) V_378 ) ;
break;
case V_388 :
break;
case V_389 :
break;
case V_390 :
break;
default:
return - V_173 ;
}
return V_137 ;
}
static int F_92 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_282 * V_391 = & V_9 -> V_369 ;
struct V_392 * V_393 = (struct V_392 * ) V_208 ;
struct V_25 * V_26 = NULL ;
char * V_394 ;
T_3 V_149 ;
int V_137 = 0 ;
switch ( V_393 -> V_33 ) {
case V_395 :
V_394 = L_35 ;
break;
case V_396 :
V_394 = L_11 ;
break;
case V_397 :
V_394 = L_1 ;
break;
case V_398 :
V_394 = L_36 ;
break;
default:
return - V_148 ;
}
V_149 = sizeof( struct V_25 ) + V_393 -> V_32 ;
V_26 = F_93 ( V_149 , V_165 ) ;
if ( V_26 == NULL )
return - V_166 ;
V_26 -> V_70 = V_399 ;
memset ( V_26 -> V_158 , 0xff , V_20 ) ;
strncpy ( ( char * ) V_26 -> V_29 . V_30 . V_33 , V_394 , V_157 ) ;
if ( V_393 -> V_400 & V_401 )
V_26 -> V_29 . V_30 . V_171 = 0 ;
if ( V_393 -> V_400 & V_402 )
V_26 -> V_29 . V_30 . V_171 = 1 ;
V_26 -> V_29 . V_30 . V_40 = ( V_391 -> V_74 & 0x00FF ) - 1 ;
if ( V_393 -> V_400 & V_403 )
memcpy ( V_26 -> V_29 . V_30 . V_404 , V_393 -> V_405 , 8 ) ;
if ( V_393 -> V_32 ) {
V_26 -> V_29 . V_30 . V_32 = V_393 -> V_32 ;
memcpy ( V_26 + 1 , V_393 + 1 , V_393 -> V_32 ) ;
}
V_137 = F_30 ( V_136 , V_26 , V_149 ) ;
F_40 ( V_26 ) ;
return V_137 ;
}
static int F_94 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
if ( V_208 ) {
V_9 -> V_73 . V_75 = 8 ;
V_9 -> V_73 . V_74 = 1 ;
memcpy ( V_208 , L_37 , 8 ) ;
}
return 0 ;
}
static int F_95 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_365 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
T_3 V_2 ;
T_3 V_406 ;
F_96 ( V_2 , ( T_3 V_407 * ) V_9 -> V_73 . V_284 ) ;
V_406 = F_97 ( V_7 , V_2 ) ;
F_98 ( V_406 , ( T_3 V_407 * ) V_9 -> V_73 . V_284 ) ;
V_9 -> V_73 . V_75 = ( V_406 & 0xffff0000 ) >> 16 ;
V_9 -> V_73 . V_74 = V_406 & 0xffff ;
F_96 ( V_2 , ( T_3 V_407 * ) V_9 -> V_73 . V_284 ) ;
return 0 ;
}
static int F_99 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_365 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
T_3 V_2 ;
T_3 V_406 ;
F_96 ( V_2 , ( T_3 V_407 * ) V_9 -> V_73 . V_284 ) ;
V_406 = ( ( T_3 ) V_9 -> V_73 . V_75 << 16 ) | ( T_3 ) V_9 -> V_73 . V_74 ;
F_100 ( V_7 , V_2 , V_406 ) ;
return 0 ;
}
static int F_101 ( struct V_135 * V_136 ,
struct V_51 * V_4 ,
union V_8 * V_9 , char * V_5 )
{
return - V_408 ;
}
static int F_102 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
return 0 ;
}
static int F_103 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_282 * V_62 = & V_9 -> V_73 ;
struct V_409 V_410 ;
struct V_411 * V_412 ;
struct V_413 * V_414 ;
unsigned long V_415 , V_416 , V_417 ;
T_1 * V_418 , V_419 ;
T_4 V_280 ;
T_5 V_320 ;
int V_137 = 0 ;
if ( ( ! V_62 -> V_75 ) || ( ! V_62 -> V_284 ) )
return - V_148 ;
V_419 = ( T_1 ) ( V_62 -> V_74 & 0xFFFF ) ;
V_280 = V_62 -> V_75 ;
V_418 = F_56 ( V_62 -> V_284 , V_280 ) ;
if ( F_57 ( V_418 ) )
return F_58 ( V_418 ) ;
V_414 = (struct V_413 * ) V_418 ;
if ( V_414 -> V_420 >= V_421 ) {
V_137 = - V_148 ;
goto V_422;
}
V_412 = V_423 + V_414 -> V_420 ;
if ( ( V_412 -> V_424 != 0 ) &&
( V_414 -> V_280 < V_412 -> V_424 ) ) {
V_137 = - V_148 ;
goto V_422;
}
if ( V_412 -> V_425 == 0 && V_412 -> V_426 )
V_320 = V_412 -> V_426 ( & V_410 ) ;
else if ( V_412 -> V_426 ) {
V_410 . V_427 = V_7 ;
V_410 . V_425 = V_412 -> V_425 ;
V_410 . V_428 = V_414 -> V_73 ;
V_410 . V_429 = V_414 -> V_280 ;
V_410 . V_430 = 0 ;
V_416 = 0 ;
V_417 = 0 ;
if ( V_419 ) {
V_410 . V_431 = & V_415 ;
V_410 . V_432 = & V_417 ;
V_410 . V_433 = V_434 ;
} else {
V_410 . V_431 = & V_416 ;
V_410 . V_432 = & V_417 ;
V_410 . V_433 = V_435 ;
}
V_320 = V_412 -> V_426 ( & V_410 ) ;
} else {
F_32 ( V_136 , L_38 ,
V_160 , V_414 -> V_420 , V_412 -> V_425 ,
V_412 -> V_426 ) ;
V_137 = - V_295 ;
goto V_422;
}
if ( V_419 == 0x00 ) {
if ( F_61 ( V_62 -> V_284 , V_418 , V_280 ) )
V_137 = - V_295 ;
}
if ( V_320 ) {
V_137 = - V_295 ;
goto V_422;
}
V_422:
F_40 ( V_418 ) ;
return V_137 ;
}
static int F_104 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_10 * V_11 = & V_7 -> V_12 ;
struct V_297 * V_298 = & V_11 -> V_299 ;
struct V_282 * V_436 = & V_9 -> V_73 ;
struct V_53 * V_54 = NULL ;
T_3 V_203 = 0 , V_437 ;
unsigned long V_302 ;
struct V_303 * V_335 , * V_304 ;
unsigned char * V_438 ;
T_1 V_239 [ V_20 ] ;
char V_73 [ 32 ] ;
if ( V_7 -> V_321 || ( V_436 == NULL ) )
return - V_148 ;
while ( F_36 ( V_11 , V_308 | V_310 ) ) {
F_77 ( 30 ) ;
V_203 ++ ;
if ( V_203 > 100 )
break;
}
V_436 -> V_74 = 0 ;
if ( V_436 -> V_75 >= 32 ) {
if ( F_105 ( V_73 , V_436 -> V_284 , 32 ) )
return - V_148 ;
} else
return - V_148 ;
F_64 ( & ( V_11 -> V_299 . V_311 ) , V_302 ) ;
V_304 = & V_298 -> V_298 ;
V_335 = V_304 -> V_313 ;
while ( 1 ) {
if ( F_65 ( V_304 , V_335 ) == true )
break;
V_54 = F_66 ( V_335 , struct V_53 , V_314 ) ;
if ( F_1 ( V_73 , V_239 ) ) {
F_32 ( V_136 , L_39 ,
( T_1 * ) V_73 ) ;
F_67 ( & ( V_11 -> V_299 . V_311 ) ,
V_302 ) ;
return - V_148 ;
}
F_32 ( V_136 , L_40 , V_239 ) ;
if ( ! memcmp ( V_239 , V_54 -> V_18 . V_19 , V_20 ) ) {
V_438 = F_106 ( & V_54 -> V_18 . V_78 [ 12 ] ,
& V_437 , V_54 -> V_18 . V_80 - 12 ) ;
if ( V_438 && ( V_437 > 0 ) ) {
V_436 -> V_74 = 1 ;
break;
}
V_438 = F_107 ( & V_54 -> V_18 . V_78 [ 12 ] ,
& V_437 , V_54 -> V_18 . V_80 - 12 ) ;
if ( V_438 && ( V_437 > 0 ) ) {
V_436 -> V_74 = 2 ;
break;
}
}
V_335 = V_335 -> V_313 ;
}
F_67 ( & ( V_11 -> V_299 . V_311 ) , V_302 ) ;
if ( V_436 -> V_75 >= 34 ) {
if ( F_61 ( ( T_1 V_407 * ) V_436 -> V_284 + 32 ,
( T_1 * ) & V_436 -> V_74 , 1 ) )
return - V_148 ;
}
return 0 ;
}
static int F_108 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_282 * V_436 = & V_9 -> V_73 ;
if ( ( V_7 -> V_321 ) || ( V_436 == NULL ) )
return - V_148 ;
if ( F_105 ( & V_7 -> V_439 , V_436 -> V_284 , sizeof( int ) ) )
return - V_148 ;
return 0 ;
}
static int F_109 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
int V_137 = 0 ;
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_282 * V_436 = & V_9 -> V_73 ;
int V_440 = - 1 ;
if ( ( V_7 -> V_321 ) || ( V_436 == NULL ) ) {
V_137 = - V_148 ;
goto exit;
}
V_440 = ( int ) * V_208 ;
F_110 ( V_7 , V_440 ) ;
exit:
return V_137 ;
}
static int F_111 ( struct V_135 * V_136 ,
struct V_51 * V_52 ,
union V_8 * V_9 , char * V_208 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_282 * V_436 = & V_9 -> V_73 ;
T_3 V_441 = 0 ;
if ( ( V_7 -> V_321 ) || ( V_436 == NULL ) )
return - V_148 ;
if ( F_105 ( ( void * ) & V_441 , V_436 -> V_284 , 4 ) )
return - V_295 ;
if ( V_441 == 0 )
V_441 = * V_208 ;
if ( V_441 == 1 )
V_7 -> V_442 . V_443 ( V_7 ,
V_444 ) ;
else if ( V_441 == 2 )
V_7 -> V_442 . V_443 ( V_7 ,
V_445 ) ;
else if ( V_441 == 3 )
V_7 -> V_442 . V_443 ( V_7 ,
V_446 ) ;
return 0 ;
}
static int F_112 ( struct V_135 * V_136 , T_1 V_84 , T_3 V_112 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
switch ( V_84 ) {
case V_447 :
V_7 -> V_36 . V_144 = 2 ;
switch ( ( V_112 ) & 0xff ) {
case 1 :
V_7 -> V_36 . V_142 =
V_146 ;
V_7 -> V_36 . V_140 =
V_183 ;
break;
case 2 :
V_7 -> V_36 . V_142 =
V_192 ;
V_7 -> V_36 . V_140 =
V_184 ;
break;
}
break;
case V_448 :
break;
case V_449 :
break;
case V_450 :
break;
case V_451 :
return F_28 ( V_136 , V_112 ) ;
case V_452 :
break;
case V_453 :
break;
default:
return - V_173 ;
}
return 0 ;
}
static int F_113 ( struct V_135 * V_136 , T_3 V_454 , T_3 V_455 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
switch ( V_454 ) {
case V_456 :
if ( ! F_72 ( V_7 ) )
return - 1 ;
break;
case V_457 :
if ( ! F_72 ( V_7 ) )
return - 1 ;
break;
default:
return - V_173 ;
}
return 0 ;
}
static int F_114 ( struct V_135 * V_136 , struct V_282 * V_62 )
{
struct V_25 * V_26 ;
int V_137 = 0 ;
struct V_6 * V_7 = F_29 ( V_136 ) ;
if ( V_62 -> V_75 < sizeof( struct V_25 ) || ! V_62 -> V_284 )
return - V_148 ;
V_26 = F_56 ( V_62 -> V_284 , V_62 -> V_75 ) ;
if ( F_57 ( V_26 ) )
return F_58 ( V_26 ) ;
switch ( V_26 -> V_70 ) {
case V_458 :
V_137 = F_112 ( V_136 , V_26 -> V_29 . V_459 . V_84 ,
V_26 -> V_29 . V_459 . V_112 ) ;
break;
case V_460 :
V_137 = F_41 ( V_7 , ( char * ) V_26 -> V_29 . V_116 . V_73 ,
( T_4 ) V_26 -> V_29 . V_116 . V_280 ) ;
break;
case V_399 :
V_137 = F_30 ( V_136 , V_26 , V_62 -> V_75 ) ;
break;
case V_461 :
V_137 = F_113 ( V_136 , V_26 -> V_29 . V_317 . V_454 ,
V_26 -> V_29 . V_317 . V_462 ) ;
break;
default:
V_137 = - V_173 ;
break;
}
if ( V_137 == 0 && F_61 ( V_62 -> V_284 , V_26 , V_62 -> V_75 ) )
V_137 = - V_295 ;
F_40 ( V_26 ) ;
return V_137 ;
}
int F_115 ( struct V_135 * V_136 , struct V_463 * V_464 , int V_70 )
{
struct V_465 * V_466 = (struct V_465 * ) V_464 ;
switch ( V_70 ) {
case V_467 :
return F_114 ( V_136 , & V_466 -> V_29 . V_73 ) ;
default:
return - V_173 ;
}
return 0 ;
}
static struct V_468 * F_116 ( struct V_135 * V_136 )
{
struct V_6 * V_7 = F_29 ( V_136 ) ;
struct V_468 * V_469 = & V_7 -> V_470 ;
int V_471 = 0 ;
int V_472 = 0 ;
int V_473 = 0 ;
if ( F_36 ( & V_7 -> V_12 , V_212 ) != true ) {
V_469 -> V_127 . V_127 = 0 ;
V_469 -> V_127 . V_132 = 0 ;
V_469 -> V_127 . V_133 = 0 ;
} else {
V_471 = V_7 -> V_286 . V_287 ;
V_472 = V_7 -> V_286 . signal ;
V_473 = V_7 -> V_286 . V_133 ;
V_469 -> V_127 . V_132 = V_471 ;
V_469 -> V_127 . V_127 = V_472 ;
V_469 -> V_127 . V_133 = V_473 ;
}
V_469 -> V_127 . V_128 = V_474 ;
return & V_7 -> V_470 ;
}
