static int F_1 ( char V_1 )
{
if ( V_1 >= '0' && V_1 <= '9' )
return V_1 - '0' ;
if ( V_1 >= 'a' && V_1 <= 'f' )
return V_1 - 'a' + 10 ;
if ( V_1 >= 'A' && V_1 <= 'F' )
return V_1 - 'A' + 10 ;
return - 1 ;
}
static int F_2 ( const char * V_2 , T_1 * V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 6 ; V_4 ++ ) {
int V_5 , V_6 ;
V_5 = F_1 ( * V_2 ++ ) ;
if ( V_5 < 0 )
return - 1 ;
V_6 = F_1 ( * V_2 ++ ) ;
if ( V_6 < 0 )
return - 1 ;
* V_3 ++ = ( V_5 << 4 ) | V_6 ;
if ( V_4 < 5 && * V_2 ++ != ':' )
return - 1 ;
}
return 0 ;
}
void F_3 ( struct V_7 * V_8 )
{
union V_9 V_10 ;
F_4 ( & V_10 , 0 , sizeof( union V_9 ) ) ;
F_5 ( V_8 -> V_11 , V_12 , & V_10 , NULL ) ;
}
void F_6 ( struct V_7 * V_8 )
{
union V_9 V_10 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
F_4 ( & V_10 , 0 , sizeof( union V_9 ) ) ;
V_10 . V_16 . V_17 = V_18 ;
memcpy ( V_10 . V_16 . V_19 , V_14 -> V_20 . V_21 . V_22 , V_23 ) ;
F_7 ( V_24 , L_1 ) ;
F_5 ( V_8 -> V_11 , V_25 , & V_10 , NULL ) ;
}
void F_8 ( struct V_7 * V_8 )
{
union V_9 V_10 ;
F_4 ( & V_10 , 0 , sizeof( union V_9 ) ) ;
V_10 . V_16 . V_17 = V_18 ;
F_4 ( V_10 . V_16 . V_19 , 0 , V_23 ) ;
F_7 ( V_24 , L_2 ) ;
F_5 ( V_8 -> V_11 , V_25 , & V_10 , NULL ) ;
}
static char * F_9 ( struct V_7 * V_8 ,
struct V_26 * V_27 ,
struct V_28 * V_29 ,
char * V_30 , char * V_31 )
{
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_32 V_33 ;
T_2 V_34 ;
T_3 V_35 ;
T_4 V_36 = 0 ;
char V_37 [ V_38 ] ;
char * V_39 ;
T_2 V_40 = 0 , V_41 , V_42 = false ;
T_4 V_4 = 0 ;
T_1 V_43 = 0 , V_44 = 0 ;
T_2 V_45 = 0 ;
T_1 V_46 , V_47 ;
#ifdef F_10
struct V_48 * V_49 = & V_8 -> V_50 ;
if ( ! F_11 ( V_49 , V_51 ) ) {
T_4 V_52 = false ;
if ( ! memcmp ( V_29 -> V_21 . V_53 . V_53 , V_49 -> V_54 , V_55 ) ) {
T_4 V_56 = 0 ;
if ( V_29 -> V_21 . V_57 [ 0 ] == 2 ) {
if ( F_12 ( V_29 -> V_21 . V_58 , V_29 -> V_21 . V_59 , NULL , & V_56 ) )
V_52 = true ;
} else {
if ( F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) )
V_52 = true ;
}
}
if ( ! V_52 )
return V_30 ;
}
#endif
V_33 . V_60 = V_25 ;
V_33 . V_61 . V_16 . V_17 = V_18 ;
memcpy ( V_33 . V_61 . V_16 . V_19 , V_29 -> V_21 . V_22 , V_23 ) ;
V_30 = F_13 ( V_27 , V_30 , V_31 , & V_33 , V_62 ) ;
V_33 . V_60 = V_63 ;
V_33 . V_61 . V_64 . V_65 = 1 ;
V_33 . V_61 . V_64 . V_66 = F_14 ( T_2 , V_29 -> V_21 . V_53 . V_67 , 32 ) ;
V_30 = F_15 ( V_27 , V_30 , V_31 , & V_33 , V_29 -> V_21 . V_53 . V_53 ) ;
V_39 = F_16 ( & V_29 -> V_21 . V_58 [ 12 ] , V_68 , & V_36 , V_29 -> V_21 . V_59 - 12 ) ;
if ( V_39 && V_36 > 0 ) {
struct V_69 * V_70 ;
V_42 = true ;
V_70 = (struct V_69 * ) ( V_39 + 2 ) ;
memcpy ( & V_45 , V_70 -> V_71 , 2 ) ;
V_43 = ( V_70 -> V_72 & V_73 ) ? 1 : 0 ;
V_44 = ( V_70 -> V_72 & ( V_74 | V_75 ) ) ? 1 : 0 ;
}
V_33 . V_60 = V_76 ;
if ( ( F_17 ( ( T_1 * ) & V_29 -> V_21 . V_77 ) ) ) {
if ( V_42 )
snprintf ( V_33 . V_61 . V_78 , V_79 , L_3 ) ;
else
snprintf ( V_33 . V_61 . V_78 , V_79 , L_4 ) ;
} else if ( ( F_18 ( ( T_1 * ) & V_29 -> V_21 . V_77 ) ) ) {
if ( V_42 )
snprintf ( V_33 . V_61 . V_78 , V_79 , L_5 ) ;
else
snprintf ( V_33 . V_61 . V_78 , V_79 , L_6 ) ;
} else {
if ( V_29 -> V_21 . V_80 . V_81 > 14 ) {
if ( V_42 )
snprintf ( V_33 . V_61 . V_78 , V_79 , L_7 ) ;
else
snprintf ( V_33 . V_61 . V_78 , V_79 , L_8 ) ;
} else {
if ( V_42 )
snprintf ( V_33 . V_61 . V_78 , V_79 , L_9 ) ;
else
snprintf ( V_33 . V_61 . V_78 , V_79 , L_10 ) ;
}
}
V_30 = F_13 ( V_27 , V_30 , V_31 , & V_33 , V_82 ) ;
V_33 . V_60 = V_83 ;
memcpy ( & V_35 , F_19 ( V_29 -> V_21 . V_58 ) , 2 ) ;
V_34 = F_20 ( V_35 ) ;
if ( V_34 & ( V_84 | V_85 ) ) {
if ( V_34 & V_85 )
V_33 . V_61 . V_86 = V_87 ;
else
V_33 . V_61 . V_86 = V_88 ;
V_30 = F_13 ( V_27 , V_30 , V_31 , & V_33 , V_89 ) ;
}
if ( V_29 -> V_21 . V_80 . V_81 < 1 )
V_29 -> V_21 . V_80 . V_81 = 1 ;
V_33 . V_60 = V_90 ;
V_33 . V_61 . V_91 . V_92 = F_21 ( V_29 -> V_21 . V_80 . V_81 ) * 100000 ;
V_33 . V_61 . V_91 . V_93 = 1 ;
V_33 . V_61 . V_91 . V_4 = V_29 -> V_21 . V_80 . V_81 ;
V_30 = F_13 ( V_27 , V_30 , V_31 , & V_33 , V_94 ) ;
V_33 . V_60 = V_95 ;
if ( V_34 & V_96 )
V_33 . V_61 . V_64 . V_65 = V_97 | V_98 ;
else
V_33 . V_61 . V_64 . V_65 = V_99 ;
V_33 . V_61 . V_64 . V_66 = 0 ;
V_30 = F_15 ( V_27 , V_30 , V_31 , & V_33 , V_29 -> V_21 . V_53 . V_53 ) ;
V_40 = 0 ;
V_39 = V_37 ;
V_39 += snprintf ( V_39 , V_38 - ( V_39 - V_37 ) , L_11 ) ;
while ( V_29 -> V_21 . V_77 [ V_4 ] != 0 ) {
V_41 = V_29 -> V_21 . V_77 [ V_4 ] & 0x7F ;
if ( V_41 > V_40 )
V_40 = V_41 ;
V_39 += snprintf ( V_39 , V_38 - ( V_39 - V_37 ) ,
L_12 , V_41 >> 1 , ( V_41 & 1 ) ? L_13 : L_14 ) ;
V_4 ++ ;
}
if ( V_42 ) {
if ( V_45 & 0x8000 )
V_40 = ( V_43 ) ? ( ( V_44 ) ? 300 : 270 ) : ( ( V_44 ) ? 144 : 130 ) ;
else if ( V_45 & 0x0080 )
;
else
V_40 = ( V_43 ) ? ( ( V_44 ) ? 150 : 135 ) : ( ( V_44 ) ? 72 : 65 ) ;
V_40 = V_40 * 2 ;
}
V_33 . V_60 = V_100 ;
V_33 . V_61 . V_101 . V_102 = 0 ;
V_33 . V_61 . V_101 . V_103 = 0 ;
V_33 . V_61 . V_101 . V_104 = V_40 * 500000 ;
V_30 = F_13 ( V_27 , V_30 , V_31 , & V_33 , V_105 ) ;
{
T_1 V_106 [ V_107 ] ;
T_1 V_108 [ 255 ] , V_109 [ 255 ] ;
T_2 V_110 = 0 , V_111 = 0 ;
T_1 * V_39 ;
F_22 ( V_29 -> V_21 . V_58 , V_29 -> V_21 . V_59 , V_109 , & V_111 , V_108 , & V_110 ) ;
F_23 ( V_112 , V_113 , ( L_15 , V_29 -> V_21 . V_53 . V_53 ) ) ;
F_23 ( V_112 , V_113 , ( L_16 , V_110 , V_111 ) ) ;
if ( V_110 > 0 ) {
V_39 = V_106 ;
F_4 ( V_106 , 0 , V_107 ) ;
V_39 += sprintf ( V_39 , L_17 ) ;
for ( V_4 = 0 ; V_4 < V_110 ; V_4 ++ )
V_39 += sprintf ( V_39 , L_18 , V_108 [ V_4 ] ) ;
F_4 ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_60 = V_114 ;
V_33 . V_61 . V_64 . V_66 = strlen ( V_106 ) ;
V_30 = F_15 ( V_27 , V_30 , V_31 , & V_33 , V_106 ) ;
F_4 ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_60 = V_115 ;
V_33 . V_61 . V_64 . V_66 = V_110 ;
V_30 = F_15 ( V_27 , V_30 , V_31 , & V_33 , V_108 ) ;
}
if ( V_111 > 0 ) {
V_39 = V_106 ;
F_4 ( V_106 , 0 , V_107 ) ;
V_39 += sprintf ( V_39 , L_19 ) ;
for ( V_4 = 0 ; V_4 < V_111 ; V_4 ++ )
V_39 += sprintf ( V_39 , L_18 , V_109 [ V_4 ] ) ;
F_4 ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_60 = V_114 ;
V_33 . V_61 . V_64 . V_66 = strlen ( V_106 ) ;
V_30 = F_15 ( V_27 , V_30 , V_31 , & V_33 , V_106 ) ;
F_4 ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_60 = V_115 ;
V_33 . V_61 . V_64 . V_66 = V_111 ;
V_30 = F_15 ( V_27 , V_30 , V_31 , & V_33 , V_109 ) ;
}
}
{
T_5 V_116 = 0 , V_117 ;
T_1 * V_118 = NULL ;
T_5 V_119 = 0 ;
T_1 * V_120 = V_29 -> V_21 . V_58 + V_121 ;
V_117 = V_29 -> V_21 . V_59 - V_121 ;
while ( V_116 < V_117 ) {
if ( F_24 ( & V_120 [ V_116 ] , & V_119 ) && ( V_119 > 2 ) ) {
V_118 = & V_120 [ V_116 ] ;
V_33 . V_60 = V_115 ;
V_33 . V_61 . V_64 . V_66 = ( T_2 ) V_119 ;
V_30 = F_15 ( V_27 , V_30 , V_31 , & V_33 , V_118 ) ;
}
V_116 += V_120 [ V_116 + 1 ] + 2 ;
}
}
V_33 . V_60 = V_122 ;
V_33 . V_61 . V_123 . V_124 = V_125 | V_126 | V_127 ;
if ( F_25 ( V_14 , V_128 ) == true &&
F_26 ( & V_14 -> V_20 . V_21 , & V_29 -> V_21 ) ) {
V_46 = V_8 -> V_129 . V_130 ;
V_47 = V_8 -> V_129 . V_131 ;
} else {
V_46 = V_29 -> V_21 . V_132 . V_133 ;
V_47 = V_29 -> V_21 . V_132 . V_134 ;
}
V_33 . V_61 . V_123 . V_135 = ( T_1 ) V_46 ;
V_33 . V_61 . V_123 . V_123 = ( T_1 ) V_47 ;
V_33 . V_61 . V_123 . V_136 = 0 ;
V_30 = F_13 ( V_27 , V_30 , V_31 , & V_33 , V_137 ) ;
return V_30 ;
}
static int F_27 ( struct V_138 * V_139 , T_4 V_104 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
int V_140 = 0 ;
if ( ( V_104 & V_141 ) && ( V_104 & V_142 ) ) {
F_29 ( L_20 , V_104 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_146 = V_147 ;
V_8 -> V_143 . V_148 = V_149 ;
} else if ( V_104 & V_141 ) {
F_29 ( L_21 , V_104 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_146 = V_150 ;
V_8 -> V_143 . V_148 = V_151 ;
} else if ( V_104 & V_142 ) {
F_29 ( L_22 ) ;
if ( V_8 -> V_143 . V_146 < V_152 ) {
V_8 -> V_143 . V_146 = V_153 ;
V_8 -> V_143 . V_148 = V_154 ;
}
} else if ( V_104 & V_155 ) {
F_29 ( L_23 ) ;
} else {
F_29 ( L_24 ) ;
V_140 = - V_156 ;
}
return V_140 ;
}
static int F_30 ( struct V_138 * V_139 , struct V_157 * V_158 , T_4 V_159 )
{
int V_140 = 0 ;
T_4 V_160 , V_161 , V_162 ;
struct V_163 * V_164 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_165 * V_166 = & V_8 -> V_143 ;
#ifdef F_10
struct V_48 * V_49 = & V_8 -> V_50 ;
#endif
V_167 ;
V_158 -> V_61 . V_168 . V_169 = 0 ;
V_158 -> V_61 . V_168 . V_170 [ V_171 - 1 ] = '\0' ;
if ( V_159 < ( T_4 ) ( ( T_1 * ) V_158 -> V_61 . V_168 . V_172 - ( T_1 * ) V_158 ) + V_158 -> V_61 . V_168 . V_173 ) {
V_140 = - V_156 ;
goto exit;
}
if ( V_158 -> V_174 [ 0 ] == 0xff && V_158 -> V_174 [ 1 ] == 0xff &&
V_158 -> V_174 [ 2 ] == 0xff && V_158 -> V_174 [ 3 ] == 0xff &&
V_158 -> V_174 [ 4 ] == 0xff && V_158 -> V_174 [ 5 ] == 0xff ) {
if ( V_158 -> V_61 . V_168 . V_175 >= V_176 ) {
V_140 = - V_156 ;
goto exit;
}
} else {
V_140 = - V_156 ;
goto exit;
}
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_25 ) == 0 ) {
F_23 ( V_177 , V_178 , ( L_26 ) ) ;
F_29 ( L_26 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_179 = V_180 ;
V_8 -> V_143 . V_181 = V_180 ;
V_160 = V_158 -> V_61 . V_168 . V_175 ;
V_161 = V_158 -> V_61 . V_168 . V_173 ;
F_23 ( V_177 , V_113 , ( L_27 , V_160 ) ) ;
F_29 ( L_27 , V_160 ) ;
if ( V_160 > V_176 )
return - V_156 ;
F_23 ( V_177 , V_113 , ( L_28 , V_160 ) ) ;
if ( V_161 > 0 ) {
V_161 = V_161 <= 5 ? 5 : 13 ;
V_162 = V_161 + F_31 ( struct V_163 , V_182 ) ;
V_164 = (struct V_163 * ) F_32 ( V_162 ) ;
if ( V_164 == NULL ) {
F_23 ( V_177 , V_178 , ( L_29 ) ) ;
goto exit;
}
F_4 ( V_164 , 0 , V_162 ) ;
V_164 -> V_183 = V_161 ;
V_164 -> V_184 = V_162 ;
if ( V_161 == 13 ) {
V_8 -> V_143 . V_179 = V_185 ;
V_8 -> V_143 . V_181 = V_185 ;
}
} else {
V_140 = - V_156 ;
goto exit;
}
V_164 -> V_186 = V_160 ;
V_164 -> V_186 |= 0x80000000 ;
memcpy ( V_164 -> V_182 , V_158 -> V_61 . V_168 . V_172 , V_164 -> V_183 ) ;
if ( V_158 -> V_61 . V_168 . V_187 ) {
F_29 ( L_30 ) ;
if ( F_33 ( V_8 , V_164 ) == ( T_1 ) V_188 )
V_140 = - V_189 ;
} else {
F_29 ( L_31 ) ;
if ( V_160 >= V_176 ) {
V_140 = - V_189 ;
goto exit;
}
memcpy ( & ( V_166 -> V_190 [ V_160 ] . V_191 [ 0 ] ) , V_164 -> V_182 , V_164 -> V_183 ) ;
V_166 -> V_192 [ V_160 ] = V_164 -> V_183 ;
F_34 ( V_8 , V_166 , V_160 , 0 ) ;
}
goto exit;
}
if ( V_8 -> V_143 . V_148 == V_193 ) {
struct V_194 * V_195 , * V_196 ;
struct V_197 * V_198 = & V_8 -> V_199 ;
if ( F_25 ( V_14 , V_200 | V_201 ) ) {
V_195 = F_35 ( V_198 , F_36 ( V_14 ) ) ;
if ( V_195 == NULL ) {
;
} else {
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_32 ) != 0 )
V_195 -> V_202 = false ;
if ( ( V_8 -> V_143 . V_144 == V_203 ) ||
( V_8 -> V_143 . V_144 == V_204 ) )
V_195 -> V_205 = V_8 -> V_143 . V_179 ;
if ( V_158 -> V_61 . V_168 . V_187 == 1 ) {
memcpy ( V_195 -> V_206 . V_191 , V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_33 ) == 0 ) {
memcpy ( V_195 -> V_207 . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 16 ] ) , 8 ) ;
memcpy ( V_195 -> V_208 . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 24 ] ) , 8 ) ;
V_8 -> V_143 . V_209 = false ;
}
F_29 ( L_34 ) ;
F_37 ( V_8 , ( unsigned char * ) V_195 , true ) ;
} else {
memcpy ( V_8 -> V_143 . V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 , V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
memcpy ( V_8 -> V_143 . V_211 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 16 ] ) , 8 ) ;
memcpy ( V_8 -> V_143 . V_212 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 24 ] ) , 8 ) ;
V_8 -> V_143 . V_213 = true ;
F_29 ( L_35 ) ;
V_8 -> V_143 . V_214 = V_158 -> V_61 . V_168 . V_175 ;
F_34 ( V_8 , & V_8 -> V_143 , V_158 -> V_61 . V_168 . V_175 , 1 ) ;
#ifdef F_10
if ( F_11 ( V_49 , V_215 ) )
F_38 ( V_49 , V_216 ) ;
#endif
}
}
V_196 = F_39 ( V_8 ) ;
if ( V_196 == NULL ) {
;
} else {
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_32 ) != 0 )
V_196 -> V_202 = false ;
if ( ( V_8 -> V_143 . V_144 == V_203 ) ||
( V_8 -> V_143 . V_144 == V_204 ) )
V_196 -> V_205 = V_8 -> V_143 . V_179 ;
}
}
}
exit:
F_40 ( V_164 ) ;
V_217 ;
return V_140 ;
}
static int F_41 ( struct V_7 * V_8 , char * V_218 , unsigned short V_219 )
{
T_1 * V_106 = NULL ;
int V_220 = 0 , V_221 = 0 ;
int V_140 = 0 ;
#ifdef F_10
struct V_48 * V_49 = & V_8 -> V_50 ;
#endif
if ( ( V_219 > V_107 ) || ( V_218 == NULL ) ) {
F_42 ( & V_8 -> V_15 , V_222 ) ;
if ( V_218 == NULL )
return V_140 ;
else
return - V_156 ;
}
if ( V_219 ) {
V_106 = F_43 ( V_219 ) ;
if ( V_106 == NULL ) {
V_140 = - V_223 ;
goto exit;
}
memcpy ( V_106 , V_218 , V_219 ) ;
{
int V_4 ;
F_29 ( L_36 , V_219 ) ;
for ( V_4 = 0 ; V_4 < V_219 ; V_4 += 8 )
F_29 ( L_37 , V_106 [ V_4 ] , V_106 [ V_4 + 1 ] , V_106 [ V_4 + 2 ] , V_106 [ V_4 + 3 ] , V_106 [ V_4 + 4 ] , V_106 [ V_4 + 5 ] , V_106 [ V_4 + 6 ] , V_106 [ V_4 + 7 ] ) ;
}
if ( V_219 < V_224 ) {
F_23 ( V_177 , V_178 , ( L_38 , V_219 ) ) ;
V_140 = - 1 ;
goto exit;
}
if ( F_44 ( V_106 , V_219 , & V_220 , & V_221 , NULL ) == V_225 ) {
V_8 -> V_143 . V_148 = V_193 ;
V_8 -> V_143 . V_146 = V_152 ;
memcpy ( V_8 -> V_143 . V_226 , & V_106 [ 0 ] , V_219 ) ;
}
if ( F_45 ( V_106 , V_219 , & V_220 , & V_221 , NULL ) == V_225 ) {
V_8 -> V_143 . V_148 = V_193 ;
V_8 -> V_143 . V_146 = V_227 ;
memcpy ( V_8 -> V_143 . V_226 , & V_106 [ 0 ] , V_219 ) ;
}
switch ( V_220 ) {
case V_228 :
V_8 -> V_143 . V_181 = V_229 ;
V_8 -> V_143 . V_144 = V_230 ;
break;
case V_231 :
V_8 -> V_143 . V_181 = V_180 ;
V_8 -> V_143 . V_144 = V_145 ;
break;
case V_232 :
V_8 -> V_143 . V_181 = V_233 ;
V_8 -> V_143 . V_144 = V_203 ;
break;
case V_234 :
V_8 -> V_143 . V_181 = V_235 ;
V_8 -> V_143 . V_144 = V_204 ;
break;
case V_236 :
V_8 -> V_143 . V_181 = V_185 ;
V_8 -> V_143 . V_144 = V_145 ;
break;
}
switch ( V_221 ) {
case V_228 :
V_8 -> V_143 . V_179 = V_229 ;
V_8 -> V_143 . V_144 = V_230 ;
break;
case V_231 :
V_8 -> V_143 . V_179 = V_180 ;
V_8 -> V_143 . V_144 = V_145 ;
break;
case V_232 :
V_8 -> V_143 . V_179 = V_233 ;
V_8 -> V_143 . V_144 = V_203 ;
break;
case V_234 :
V_8 -> V_143 . V_179 = V_235 ;
V_8 -> V_143 . V_144 = V_204 ;
break;
case V_236 :
V_8 -> V_143 . V_179 = V_185 ;
V_8 -> V_143 . V_144 = V_145 ;
break;
}
F_42 ( & V_8 -> V_15 , V_222 ) ;
{
T_2 V_116 = 0 ;
T_1 V_237 , V_238 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_116 < V_219 ) {
V_237 = V_106 [ V_116 ] ;
if ( ( V_237 == V_239 ) && ( ! memcmp ( & V_106 [ V_116 + 2 ] , V_238 , 4 ) ) ) {
F_29 ( L_39 ) ;
V_8 -> V_143 . V_240 = ( ( V_106 [ V_116 + 1 ] + 2 ) < ( V_107 << 2 ) ) ? ( V_106 [ V_116 + 1 ] + 2 ) : ( V_107 << 2 ) ;
memcpy ( V_8 -> V_143 . V_241 , & V_106 [ V_116 ] , V_8 -> V_143 . V_240 ) ;
F_46 ( & V_8 -> V_15 , V_222 ) ;
#ifdef F_10
if ( F_11 ( V_49 , V_242 ) )
F_38 ( V_49 , V_215 ) ;
#endif
V_116 += V_106 [ V_116 + 1 ] + 2 ;
break;
} else {
V_116 += V_106 [ V_116 + 1 ] + 2 ;
}
}
}
}
F_23 ( V_177 , V_113 ,
( L_40 ,
V_221 , V_8 -> V_143 . V_144 , V_8 -> V_143 . V_146 ) ) ;
exit:
F_40 ( V_106 ) ;
return V_140 ;
}
static int F_47 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_36 = 0 ;
char * V_39 ;
T_1 V_42 = false ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_244 * V_245 = & V_14 -> V_20 . V_21 ;
T_6 * V_246 = NULL ;
F_23 ( V_112 , V_113 , ( L_41 , V_27 -> V_60 ) ) ;
V_167 ;
if ( F_25 ( V_14 , V_128 | V_247 ) == true ) {
V_39 = F_16 ( & V_245 -> V_58 [ 12 ] , V_68 , & V_36 , V_245 -> V_59 - 12 ) ;
if ( V_39 && V_36 > 0 )
V_42 = true ;
V_246 = & V_245 -> V_77 ;
if ( F_17 ( ( T_1 * ) V_246 ) == true ) {
if ( V_42 )
snprintf ( V_10 -> V_78 , V_79 , L_3 ) ;
else
snprintf ( V_10 -> V_78 , V_79 , L_4 ) ;
} else if ( ( F_18 ( ( T_1 * ) V_246 ) ) == true ) {
if ( V_42 )
snprintf ( V_10 -> V_78 , V_79 , L_5 ) ;
else
snprintf ( V_10 -> V_78 , V_79 , L_6 ) ;
} else {
if ( V_245 -> V_80 . V_81 > 14 ) {
if ( V_42 )
snprintf ( V_10 -> V_78 , V_79 , L_7 ) ;
else
snprintf ( V_10 -> V_78 , V_79 , L_8 ) ;
} else {
if ( V_42 )
snprintf ( V_10 -> V_78 , V_79 , L_9 ) ;
else
snprintf ( V_10 -> V_78 , V_79 , L_10 ) ;
}
}
} else {
snprintf ( V_10 -> V_78 , V_79 , L_42 ) ;
}
V_217 ;
return 0 ;
}
static int F_48 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
V_167 ;
F_23 ( V_112 , V_248 , ( L_43 ) ) ;
V_217 ;
return 0 ;
}
static int F_49 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_244 * V_245 = & V_14 -> V_20 . V_21 ;
if ( F_25 ( V_14 , V_128 ) ) {
V_10 -> V_91 . V_92 = F_21 ( V_245 -> V_80 . V_81 ) * 100000 ;
V_10 -> V_91 . V_93 = 1 ;
V_10 -> V_91 . V_4 = V_245 -> V_80 . V_81 ;
} else {
V_10 -> V_91 . V_92 = F_21 ( V_8 -> V_249 . V_250 ) * 100000 ;
V_10 -> V_91 . V_93 = 1 ;
V_10 -> V_91 . V_4 = V_8 -> V_249 . V_250 ;
}
return 0 ;
}
static int F_50 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
enum V_251 V_252 ;
int V_140 = 0 ;
V_167 ;
if ( V_188 == F_51 ( V_8 ) ) {
V_140 = - V_253 ;
goto exit;
}
if ( ! V_8 -> V_254 ) {
V_140 = - V_253 ;
goto exit;
}
switch ( V_10 -> V_86 ) {
case V_255 :
V_252 = V_256 ;
F_29 ( L_44 ) ;
break;
case V_88 :
V_252 = V_257 ;
F_29 ( L_45 ) ;
break;
case V_87 :
V_252 = V_258 ;
F_29 ( L_46 ) ;
break;
case V_259 :
V_252 = V_260 ;
F_29 ( L_47 ) ;
break;
default:
V_140 = - V_156 ;
F_23 ( V_177 , V_178 , ( L_48 , V_261 [ V_10 -> V_86 ] ) ) ;
goto exit;
}
if ( F_52 ( V_8 , V_252 ) == false ) {
V_140 = - V_253 ;
goto exit;
}
F_53 ( V_8 , V_252 ) ;
exit:
V_217 ;
return V_140 ;
}
static int F_54 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
F_23 ( V_112 , V_113 , ( L_49 ) ) ;
V_167 ;
if ( F_25 ( V_14 , V_200 ) )
V_10 -> V_86 = V_259 ;
else if ( ( F_25 ( V_14 , V_247 ) ) ||
( F_25 ( V_14 , V_262 ) ) )
V_10 -> V_86 = V_88 ;
else if ( F_25 ( V_14 , V_263 ) )
V_10 -> V_86 = V_87 ;
else
V_10 -> V_86 = V_255 ;
V_217 ;
return 0 ;
}
static int F_55 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_264 , V_265 = false ;
int V_140 = false ;
struct V_165 * V_166 = & V_8 -> V_143 ;
struct V_266 * V_267 = (struct V_266 * ) V_243 ;
T_1 V_268 [ V_23 ] = { 0x00 } ;
T_1 V_269 [ V_23 ] = { 0x00 } ;
memcpy ( V_269 , V_267 -> V_270 . V_19 , V_23 ) ;
if ( V_267 -> V_60 == V_271 ) {
F_29 ( L_50 ) ;
if ( ! memcmp ( V_269 , V_268 , V_23 ) == true )
return V_140 ;
else
V_140 = true ;
V_265 = false ;
for ( V_264 = 0 ; V_264 < V_272 ; V_264 ++ ) {
if ( ! memcmp ( V_166 -> V_273 [ V_264 ] . V_274 , V_269 , V_23 ) ) {
F_29 ( L_51 ) ;
memcpy ( V_166 -> V_273 [ V_264 ] . V_275 , V_267 -> V_276 , V_277 ) ;
V_166 -> V_273 [ V_264 ] . V_278 = true ;
V_166 -> V_279 = V_264 + 1 ;
V_265 = true ;
break;
}
}
if ( ! V_265 ) {
F_29 ( L_52 ,
V_166 -> V_279 ) ;
memcpy ( V_166 -> V_273 [ V_166 -> V_279 ] . V_274 , V_269 , V_23 ) ;
memcpy ( V_166 -> V_273 [ V_166 -> V_279 ] . V_275 , V_267 -> V_276 , V_277 ) ;
V_166 -> V_273 [ V_166 -> V_279 ] . V_278 = true ;
V_166 -> V_279 ++ ;
if ( V_166 -> V_279 == 16 )
V_166 -> V_279 = 0 ;
}
} else if ( V_267 -> V_60 == V_280 ) {
F_29 ( L_53 ) ;
V_140 = true ;
for ( V_264 = 0 ; V_264 < V_272 ; V_264 ++ ) {
if ( ! memcmp ( V_166 -> V_273 [ V_264 ] . V_274 , V_269 , V_23 ) ) {
F_4 ( V_166 -> V_273 [ V_264 ] . V_274 , 0x00 , V_23 ) ;
V_166 -> V_273 [ V_264 ] . V_278 = false ;
break;
}
}
} else if ( V_267 -> V_60 == V_281 ) {
F_29 ( L_54 ) ;
F_4 ( & V_166 -> V_273 [ 0 ] , 0x00 , sizeof( struct V_282 ) * V_272 ) ;
V_166 -> V_279 = 0 ;
V_140 = true ;
}
return V_140 ;
}
static int F_56 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
V_10 -> V_283 . V_104 = 0 ;
V_10 -> V_283 . V_102 = 0 ;
V_10 -> V_283 . V_103 = 1 ;
return 0 ;
}
static int F_57 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_284 * V_285 = (struct V_284 * ) V_243 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_286 * V_287 = & V_8 -> V_249 ;
T_2 V_288 ;
int V_4 ;
V_167 ;
F_23 ( V_112 , V_113 , ( L_55 , V_27 -> V_60 ) ) ;
V_10 -> V_64 . V_66 = sizeof( * V_285 ) ;
F_4 ( V_285 , 0 , sizeof( * V_285 ) ) ;
V_285 -> V_289 = 5 * 1000 * 1000 ;
V_285 -> V_290 . V_123 = 100 ;
V_285 -> V_290 . V_135 = 100 ;
V_285 -> V_290 . V_136 = 100 ;
V_285 -> V_290 . V_124 = 7 ;
V_285 -> V_291 . V_123 = 92 ;
V_285 -> V_291 . V_135 = 20 + - 98 ;
V_285 -> V_291 . V_136 = 0 ;
V_285 -> V_291 . V_124 = 7 ;
V_285 -> V_292 = V_293 ;
for ( V_4 = 0 ; V_4 < V_293 && V_4 < V_294 ; V_4 ++ )
V_285 -> V_101 [ V_4 ] = V_295 [ V_4 ] ;
V_285 -> V_296 = V_297 ;
V_285 -> V_298 = V_299 ;
V_285 -> V_300 = 0 ;
V_285 -> V_301 = V_302 ;
V_285 -> V_303 = 16 ;
for ( V_4 = 0 , V_288 = 0 ; V_4 < V_304 ; V_4 ++ ) {
if ( V_287 -> V_305 [ V_4 ] . V_306 != 0 ) {
V_285 -> V_91 [ V_288 ] . V_4 = V_287 -> V_305 [ V_4 ] . V_306 ;
V_285 -> V_91 [ V_288 ] . V_92 = F_21 ( V_287 -> V_305 [ V_4 ] . V_306 ) * 100000 ;
V_285 -> V_91 [ V_288 ] . V_93 = 1 ;
V_288 ++ ;
}
if ( V_288 == V_307 )
break;
}
V_285 -> V_308 = V_288 ;
V_285 -> V_309 = V_288 ;
V_285 -> V_310 = V_311 | V_312 |
V_313 | V_314 ;
V_285 -> V_315 = V_316 | V_317 |
V_318 | V_319 |
V_320 | V_321 ;
V_217 ;
return 0 ;
}
static int F_58 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_322 ,
char * V_243 )
{
unsigned long V_323 ;
T_5 V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_324 * V_325 = (struct V_324 * ) V_322 ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_326 * V_327 ;
T_1 * V_328 , * V_329 ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
enum V_333 V_334 ;
V_167 ;
if ( V_188 == F_51 ( V_8 ) ) {
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_335 ) {
V_140 = - 1 ;
goto exit;
}
if ( V_325 -> V_17 != V_18 ) {
V_140 = - V_156 ;
goto exit;
}
V_334 = V_8 -> V_143 . V_146 ;
F_59 ( & V_331 -> V_336 , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_14 -> V_337 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( ( F_62 ( V_327 , V_14 -> V_337 ) ) == true )
break;
V_29 = F_63 ( V_14 -> V_337 , struct V_28 , V_338 ) ;
V_14 -> V_337 = F_61 ( V_14 -> V_337 ) ;
V_328 = V_29 -> V_21 . V_22 ;
V_329 = V_325 -> V_19 ;
if ( ( ! memcmp ( V_328 , V_329 , V_23 ) ) ) {
if ( ! F_52 ( V_8 , V_29 -> V_21 . V_339 ) ) {
V_140 = - 1 ;
F_64 ( & V_331 -> V_336 , & V_323 ) ;
goto exit;
}
break;
}
}
F_64 ( & V_331 -> V_336 , & V_323 ) ;
F_65 ( V_8 , V_334 ) ;
if ( F_66 ( V_8 , V_325 -> V_19 ) == false ) {
V_140 = - 1 ;
goto exit;
}
exit:
V_217 ;
return V_140 ;
}
static int F_67 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_244 * V_245 = & V_14 -> V_20 . V_21 ;
V_10 -> V_16 . V_17 = V_18 ;
F_4 ( V_10 -> V_16 . V_19 , 0 , V_23 ) ;
F_23 ( V_112 , V_113 , ( L_56 ) ) ;
V_167 ;
if ( ( ( F_25 ( V_14 , V_128 ) ) == true ) ||
( ( F_25 ( V_14 , V_247 ) ) == true ) ||
( ( F_25 ( V_14 , V_263 ) ) == true ) )
memcpy ( V_10 -> V_16 . V_19 , V_245 -> V_22 , V_23 ) ;
else
F_4 ( V_10 -> V_16 . V_19 , 0 , V_23 ) ;
V_217 ;
return 0 ;
}
static int F_68 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
T_2 V_340 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_341 * V_342 = (struct V_341 * ) V_243 ;
if ( V_342 == NULL )
return - 1 ;
F_29 ( L_57 , V_343 ) ;
V_340 = V_342 -> V_344 ;
F_29 ( L_58 , V_343 , V_342 -> V_60 , V_340 ) ;
switch ( V_342 -> V_60 ) {
case V_345 :
if ( ! F_69 ( V_8 ) )
V_140 = - 1 ;
break;
case V_346 :
if ( ! F_69 ( V_8 ) )
V_140 = - 1 ;
break;
default:
return - V_189 ;
}
return V_140 ;
}
static int F_70 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_243 )
{
T_1 V_347 = false ;
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_348 V_349 [ V_350 ] ;
unsigned long V_323 ;
#ifdef F_10
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
#endif
F_23 ( V_112 , V_113 , ( L_59 ) ) ;
V_167 ;
if ( V_8 -> V_351 . V_352 == 1 ) {
if ( F_25 ( V_14 , V_201 ) ) {
V_140 = - 1 ;
goto exit;
}
}
if ( V_188 == F_51 ( V_8 ) ) {
V_140 = - 1 ;
goto exit;
}
if ( V_8 -> V_353 ) {
F_29 ( L_60 , V_8 -> V_353 ) ;
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_335 ) {
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_254 ) {
V_140 = - 1 ;
goto exit;
}
if ( V_14 -> V_354 . V_355 ) {
F_3 ( V_8 ) ;
goto exit;
}
if ( F_25 ( V_14 , V_356 | V_357 ) ) {
F_3 ( V_8 ) ;
goto exit;
}
#ifdef F_10
if ( V_49 -> V_358 != V_51 ) {
F_71 ( V_49 , F_72 ( V_49 ) ) ;
F_38 ( V_49 , V_359 ) ;
F_73 ( V_49 , V_360 ) ;
F_74 ( V_8 , true ) ;
}
#endif
F_4 ( V_349 , 0 , sizeof( struct V_348 ) * V_350 ) ;
if ( V_10 -> V_64 . V_66 == sizeof( struct V_361 ) ) {
struct V_361 * V_362 = (struct V_361 * ) V_243 ;
if ( V_10 -> V_64 . V_65 & V_363 ) {
int V_364 = F_75 ( ( int ) V_362 -> V_365 , V_366 ) ;
memcpy ( V_349 [ 0 ] . V_53 , V_362 -> V_367 , V_364 ) ;
V_349 [ 0 ] . V_67 = V_364 ;
F_29 ( L_61 , V_362 -> V_367 , V_362 -> V_365 ) ;
F_59 ( & V_14 -> V_336 , & V_323 ) ;
V_347 = F_76 ( V_8 , V_349 , 1 , NULL , 0 ) ;
F_64 ( & V_14 -> V_336 , & V_323 ) ;
} else if ( V_362 -> V_368 == V_369 ) {
F_29 ( L_62 ) ;
}
} else {
if ( V_10 -> V_64 . V_66 >= V_370 &&
! memcmp ( V_243 , V_371 , V_370 ) ) {
int V_364 = V_10 -> V_64 . V_66 - V_370 ;
char * V_372 = V_243 + V_370 ;
char V_373 ;
char V_374 ;
int V_375 = 0 ;
while ( V_364 >= 1 ) {
V_373 = * ( V_372 ++ ) ;
V_364 -= 1 ;
switch ( V_373 ) {
case V_376 :
if ( V_364 < 1 ) {
V_364 = 0 ;
break;
}
V_374 = * ( V_372 ++ ) ; V_364 -= 1 ;
if ( V_374 > 0 && V_374 <= V_364 ) {
V_349 [ V_375 ] . V_67 = V_374 ;
memcpy ( V_349 [ V_375 ] . V_53 , V_372 , V_349 [ V_375 ] . V_67 ) ;
V_375 ++ ;
}
V_372 += V_374 ;
V_364 -= V_374 ;
break;
case V_377 :
case V_378 :
V_372 += 1 ;
V_364 -= 1 ;
break;
case V_379 :
case V_380 :
case V_381 :
V_372 += 2 ;
V_364 -= 2 ;
break;
default:
V_364 = 0 ;
}
}
V_347 = F_77 ( V_8 , V_349 , V_350 ) ;
} else {
V_347 = F_77 ( V_8 , NULL , 0 ) ;
}
}
if ( ! V_347 )
V_140 = - 1 ;
exit:
V_217 ;
return V_140 ;
}
static int F_78 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_243 )
{
unsigned long V_323 ;
struct V_326 * V_382 , * V_327 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
char * V_383 = V_243 ;
char * V_31 = V_383 + V_10 -> V_64 . V_66 ;
T_4 V_140 = 0 ;
T_4 V_116 = 0 ;
T_4 V_384 ;
int V_385 ;
#ifdef F_10
struct V_48 * V_49 = & V_8 -> V_50 ;
#endif
F_23 ( V_112 , V_113 , ( L_63 ) ) ;
F_23 ( V_177 , V_113 , ( L_64 ) ) ;
V_167 ;
if ( V_8 -> V_386 . V_387 && V_8 -> V_353 ) {
V_140 = - V_156 ;
goto exit;
}
#ifdef F_10
if ( ! F_11 ( V_49 , V_51 ) ) {
V_384 = 200 ;
} else {
V_384 = 100 ;
}
#else
{
V_384 = 100 ;
}
#endif
V_385 = V_356 | V_357 ;
while ( F_25 ( V_14 , V_385 ) ) {
F_79 ( 30 ) ;
V_116 ++ ;
if ( V_116 > V_384 )
break;
}
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) )
break;
if ( ( V_31 - V_383 ) < V_388 ) {
V_140 = - V_389 ;
break;
}
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
if ( F_80 ( V_8 -> V_249 . V_305 , V_29 -> V_21 . V_80 . V_81 ) >= 0 )
V_383 = F_9 ( V_8 , V_5 , V_29 , V_383 , V_31 ) ;
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_10 -> V_64 . V_66 = V_383 - V_243 ;
V_10 -> V_64 . V_65 = 0 ;
exit:
V_217 ;
return V_140 ;
}
static int F_81 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_243 )
{
unsigned long V_323 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_330 * V_331 = & V_14 -> V_332 ;
struct V_326 * V_327 ;
struct V_28 * V_29 = NULL ;
enum V_333 V_334 ;
struct V_348 V_390 ;
T_1 * V_391 , * V_392 ;
T_5 V_140 = 0 , V_364 ;
V_167 ;
F_23 ( V_177 , V_113 ,
( L_65 , F_82 ( V_14 ) ) ) ;
if ( V_188 == F_51 ( V_8 ) ) {
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_335 ) {
V_140 = - 1 ;
goto exit;
}
if ( V_10 -> V_367 . V_66 > V_366 ) {
V_140 = - V_389 ;
goto exit;
}
if ( F_25 ( V_14 , V_263 ) ) {
V_140 = - 1 ;
goto exit;
}
V_334 = V_8 -> V_143 . V_146 ;
F_29 ( L_66 , V_343 ) ;
if ( V_10 -> V_367 . V_65 && V_10 -> V_367 . V_66 ) {
V_364 = ( V_10 -> V_367 . V_66 < V_366 ) ? V_10 -> V_367 . V_66 : V_366 ;
if ( V_10 -> V_367 . V_66 != 33 )
F_29 ( L_67 , V_243 , V_10 -> V_367 . V_66 ) ;
F_4 ( & V_390 , 0 , sizeof( struct V_348 ) ) ;
V_390 . V_67 = V_364 ;
memcpy ( V_390 . V_53 , V_243 , V_364 ) ;
V_392 = V_390 . V_53 ;
F_23 ( V_177 , V_113 , ( L_68 , V_392 ) ) ;
F_59 ( & V_331 -> V_336 , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_14 -> V_337 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_14 -> V_337 ) == true ) {
F_23 ( V_177 , V_393 ,
( L_69 ) ) ;
break;
}
V_29 = F_63 ( V_14 -> V_337 , struct V_28 , V_338 ) ;
V_14 -> V_337 = F_61 ( V_14 -> V_337 ) ;
V_391 = V_29 -> V_21 . V_53 . V_53 ;
F_23 ( V_177 , V_113 ,
( L_70 ,
V_29 -> V_21 . V_53 . V_53 ) ) ;
if ( ( ! memcmp ( V_391 , V_392 , V_390 . V_67 ) ) &&
( V_29 -> V_21 . V_53 . V_67 == V_390 . V_67 ) ) {
F_23 ( V_177 , V_113 ,
( L_71 ) ) ;
if ( F_25 ( V_14 , V_262 ) == true ) {
if ( V_29 -> V_21 . V_339 != V_14 -> V_20 . V_21 . V_339 )
continue;
}
if ( ! F_52 ( V_8 , V_29 -> V_21 . V_339 ) ) {
V_140 = - 1 ;
F_64 ( & V_331 -> V_336 , & V_323 ) ;
goto exit;
}
break;
}
}
F_64 ( & V_331 -> V_336 , & V_323 ) ;
F_23 ( V_177 , V_113 ,
( L_72 , V_334 ) ) ;
F_65 ( V_8 , V_334 ) ;
if ( F_83 ( V_8 , & V_390 ) == false ) {
V_140 = - 1 ;
goto exit;
}
}
exit:
F_29 ( L_73 , V_343 , V_140 ) ;
V_217 ;
return V_140 ;
}
static int F_84 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_243 )
{
T_4 V_364 , V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_244 * V_245 = & V_14 -> V_20 . V_21 ;
F_23 ( V_112 , V_113 , ( L_74 ) ) ;
V_167 ;
if ( ( F_25 ( V_14 , V_128 ) ) ||
( F_25 ( V_14 , V_247 ) ) ) {
V_364 = V_245 -> V_53 . V_67 ;
V_10 -> V_367 . V_66 = V_364 ;
memcpy ( V_243 , V_245 -> V_53 . V_53 , V_364 ) ;
V_10 -> V_367 . V_65 = 1 ;
} else {
V_140 = - 1 ;
goto exit;
}
exit:
V_217 ;
return V_140 ;
}
static int F_85 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_243 )
{
int V_4 , V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_394 [ V_395 ] ;
T_4 V_396 = V_10 -> V_101 . V_104 ;
T_4 V_102 = V_10 -> V_101 . V_102 ;
T_4 V_397 = 0 ;
T_1 V_398 [ V_395 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
V_167 ;
F_23 ( V_112 , V_113 , ( L_75 ) ) ;
F_23 ( V_177 , V_113 , ( L_76 , V_396 , V_102 ) ) ;
if ( V_396 == - 1 ) {
V_397 = 11 ;
goto V_399;
}
V_396 = V_396 / 100000 ;
switch ( V_396 ) {
case 10 :
V_397 = 0 ;
break;
case 20 :
V_397 = 1 ;
break;
case 55 :
V_397 = 2 ;
break;
case 60 :
V_397 = 3 ;
break;
case 90 :
V_397 = 4 ;
break;
case 110 :
V_397 = 5 ;
break;
case 120 :
V_397 = 6 ;
break;
case 180 :
V_397 = 7 ;
break;
case 240 :
V_397 = 8 ;
break;
case 360 :
V_397 = 9 ;
break;
case 480 :
V_397 = 10 ;
break;
case 540 :
V_397 = 11 ;
break;
default:
V_397 = 11 ;
break;
}
V_399:
for ( V_4 = 0 ; V_4 < V_395 ; V_4 ++ ) {
if ( V_397 == V_398 [ V_4 ] ) {
V_394 [ V_4 ] = V_398 [ V_4 ] ;
if ( V_102 == 0 )
break;
} else {
V_394 [ V_4 ] = 0xff ;
}
F_23 ( V_177 , V_113 , ( L_77 , V_394 [ V_4 ] ) ) ;
}
if ( F_86 ( V_8 , V_394 ) != V_225 ) {
F_23 ( V_177 , V_178 , ( L_78 ) ) ;
V_140 = - 1 ;
}
V_217 ;
return V_140 ;
}
static int F_87 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
T_2 V_40 = 0 ;
V_40 = F_88 ( (struct V_7 * ) F_28 ( V_139 ) ) ;
if ( V_40 == 0 )
return - V_253 ;
V_10 -> V_101 . V_102 = 0 ;
V_10 -> V_101 . V_104 = V_40 * 100000 ;
return 0 ;
}
static int F_89 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_167 ;
if ( V_10 -> V_400 . V_103 ) {
V_8 -> V_351 . V_401 = 2347 ;
} else {
if ( V_10 -> V_400 . V_104 < 0 ||
V_10 -> V_400 . V_104 > 2347 )
return - V_156 ;
V_8 -> V_351 . V_401 = V_10 -> V_400 . V_104 ;
}
F_29 ( L_79 , V_343 , V_8 -> V_351 . V_401 ) ;
V_217 ;
return 0 ;
}
static int F_90 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_167 ;
F_29 ( L_79 , V_343 , V_8 -> V_351 . V_401 ) ;
V_10 -> V_400 . V_104 = V_8 -> V_351 . V_401 ;
V_10 -> V_400 . V_102 = 0 ;
V_217 ;
return 0 ;
}
static int F_91 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_167 ;
if ( V_10 -> V_402 . V_103 ) {
V_8 -> V_403 . V_404 = V_299 ;
} else {
if ( V_10 -> V_402 . V_104 < V_297 ||
V_10 -> V_402 . V_104 > V_299 )
return - V_156 ;
V_8 -> V_403 . V_404 = V_10 -> V_402 . V_104 & ~ 0x1 ;
}
F_29 ( L_80 , V_343 , V_8 -> V_403 . V_404 ) ;
V_217 ;
return 0 ;
}
static int F_92 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_167 ;
F_29 ( L_80 , V_343 , V_8 -> V_403 . V_404 ) ;
V_10 -> V_402 . V_104 = V_8 -> V_403 . V_404 ;
V_10 -> V_402 . V_102 = 0 ;
V_217 ;
return 0 ;
}
static int F_93 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
V_10 -> V_405 . V_104 = 7 ;
V_10 -> V_405 . V_102 = 0 ;
V_10 -> V_405 . V_103 = 1 ;
return 0 ;
}
static int F_94 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_406 )
{
T_4 V_172 , V_140 = 0 ;
T_4 V_407 ;
struct V_163 V_408 ;
enum V_333 V_334 ;
struct V_409 * V_410 = & ( V_10 -> V_411 ) ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_412 * V_413 = & V_8 -> V_386 ;
F_29 ( L_81 , V_410 -> V_65 ) ;
F_4 ( & V_408 , 0 , sizeof( struct V_163 ) ) ;
V_172 = V_410 -> V_65 & V_414 ;
V_167 ;
if ( V_410 -> V_65 & V_99 ) {
F_29 ( L_82 ) ;
V_8 -> V_143 . V_144 = V_230 ;
V_8 -> V_143 . V_179 = V_229 ;
V_8 -> V_143 . V_181 = V_229 ;
V_8 -> V_143 . V_148 = V_154 ;
V_334 = V_153 ;
V_8 -> V_143 . V_146 = V_334 ;
goto exit;
}
if ( V_172 ) {
if ( V_172 > V_176 )
return - V_156 ;
V_172 -- ;
V_407 = 1 ;
} else {
V_407 = 0 ;
V_172 = V_8 -> V_143 . V_415 ;
F_29 ( L_83 , V_172 ) ;
}
if ( V_410 -> V_65 & V_416 ) {
F_29 ( L_84 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_148 = V_154 ;
V_8 -> V_143 . V_179 = V_229 ;
V_8 -> V_143 . V_181 = V_229 ;
V_334 = V_153 ;
V_8 -> V_143 . V_146 = V_334 ;
} else if ( V_410 -> V_65 & V_417 ) {
F_29 ( L_85 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_148 = V_151 ;
V_8 -> V_143 . V_179 = V_180 ;
V_8 -> V_143 . V_181 = V_180 ;
V_334 = V_150 ;
V_8 -> V_143 . V_146 = V_334 ;
} else {
F_29 ( L_86 , V_410 -> V_65 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_148 = V_154 ;
V_8 -> V_143 . V_179 = V_229 ;
V_8 -> V_143 . V_181 = V_229 ;
V_334 = V_153 ;
V_8 -> V_143 . V_146 = V_334 ;
}
V_408 . V_186 = V_172 ;
if ( V_410 -> V_66 > 0 ) {
V_408 . V_183 = V_410 -> V_66 <= 5 ? 5 : 13 ;
V_408 . V_184 = V_408 . V_183 + F_31 ( struct V_163 , V_182 ) ;
} else {
V_408 . V_183 = 0 ;
if ( V_407 == 1 ) {
V_8 -> V_143 . V_415 = V_172 ;
F_29 ( L_87 , V_172 , V_8 -> V_143 . V_192 [ V_172 ] ) ;
switch ( V_8 -> V_143 . V_192 [ V_172 ] ) {
case 5 :
V_8 -> V_143 . V_179 = V_180 ;
break;
case 13 :
V_8 -> V_143 . V_179 = V_185 ;
break;
default:
V_8 -> V_143 . V_179 = V_229 ;
break;
}
goto exit;
}
}
V_408 . V_186 |= 0x80000000 ;
memcpy ( V_408 . V_182 , V_406 , V_408 . V_183 ) ;
if ( F_33 ( V_8 , & V_408 ) == false ) {
if ( V_418 == V_413 -> V_419 )
V_140 = - V_189 ;
goto exit;
}
exit:
V_217 ;
return V_140 ;
}
static int F_95 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_406 )
{
T_5 V_172 , V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_409 * V_410 = & ( V_10 -> V_411 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
V_167 ;
if ( F_25 ( V_14 , V_128 ) != true ) {
if ( ! F_25 ( V_14 , V_247 ) ) {
V_410 -> V_66 = 0 ;
V_410 -> V_65 |= V_99 ;
return 0 ;
}
}
V_172 = V_410 -> V_65 & V_414 ;
if ( V_172 ) {
if ( V_172 > V_176 )
return - V_156 ;
V_172 -- ;
} else {
V_172 = V_8 -> V_143 . V_415 ;
}
V_410 -> V_65 = V_172 + 1 ;
switch ( V_8 -> V_143 . V_144 ) {
case V_420 :
case V_230 :
V_410 -> V_66 = 0 ;
V_410 -> V_65 |= V_99 ;
break;
case V_145 :
V_410 -> V_66 = V_8 -> V_143 . V_192 [ V_172 ] ;
if ( V_410 -> V_66 ) {
memcpy ( V_406 , V_8 -> V_143 . V_190 [ V_172 ] . V_191 , V_8 -> V_143 . V_192 [ V_172 ] ) ;
V_410 -> V_65 |= V_97 ;
if ( V_8 -> V_143 . V_146 == V_153 )
V_410 -> V_65 |= V_416 ;
else if ( V_8 -> V_143 . V_146 == V_150 )
V_410 -> V_65 |= V_417 ;
} else {
V_410 -> V_66 = 0 ;
V_410 -> V_65 |= V_99 ;
}
break;
case V_203 :
case V_204 :
V_410 -> V_66 = 16 ;
V_410 -> V_65 |= ( V_97 | V_416 | V_98 ) ;
break;
default:
V_410 -> V_66 = 0 ;
V_410 -> V_65 |= V_99 ;
break;
}
V_217 ;
return V_140 ;
}
static int F_96 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
V_10 -> V_421 . V_104 = 0 ;
V_10 -> V_421 . V_102 = 0 ;
V_10 -> V_421 . V_103 = 1 ;
return 0 ;
}
static int F_97 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_140 = F_41 ( V_8 , V_243 , V_10 -> V_64 . V_66 ) ;
return V_140 ;
}
static int F_98 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_422 * V_158 = (struct V_422 * ) & ( V_10 -> V_158 ) ;
int V_140 = 0 ;
switch ( V_158 -> V_65 & V_423 ) {
case V_424 :
break;
case V_425 :
break;
case V_426 :
break;
case V_427 :
break;
case V_428 :
if ( V_158 -> V_104 ) {
V_8 -> V_143 . V_429 = true ;
} else {
V_8 -> V_143 . V_429 = false ;
}
break;
case V_430 :
if ( V_8 -> V_143 . V_144 == V_145 )
break;
if ( V_158 -> V_104 ) {
V_8 -> V_143 . V_144 = V_230 ;
V_8 -> V_143 . V_179 = V_229 ;
V_8 -> V_143 . V_181 = V_229 ;
V_8 -> V_143 . V_148 = V_154 ;
V_8 -> V_143 . V_146 = V_153 ;
}
break;
case V_431 :
if ( F_25 ( & V_8 -> V_15 , V_128 ) ) {
F_99 ( V_8 ) ;
F_100 ( V_8 , 500 , false ) ;
F_29 ( L_88 , V_343 ) ;
F_101 ( V_8 ) ;
F_102 ( V_8 , 1 ) ;
}
V_140 = F_27 ( V_139 , ( T_4 ) V_158 -> V_104 ) ;
break;
case V_432 :
break;
case V_433 :
break;
case V_434 :
break;
default:
return - V_189 ;
}
return V_140 ;
}
static int F_103 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
char * V_435 ;
T_4 V_159 ;
struct V_157 * V_158 = NULL ;
struct V_409 * V_436 = & V_10 -> V_411 ;
struct V_437 * V_438 = (struct V_437 * ) V_243 ;
int V_140 = 0 ;
V_159 = sizeof( struct V_157 ) + V_438 -> V_173 ;
V_158 = (struct V_157 * ) F_32 ( V_159 ) ;
if ( V_158 == NULL )
return - 1 ;
F_4 ( V_158 , 0 , V_159 ) ;
V_158 -> V_60 = V_439 ;
F_4 ( V_158 -> V_174 , 0xff , V_23 ) ;
switch ( V_438 -> V_170 ) {
case V_440 :
V_435 = L_32 ;
break;
case V_441 :
V_435 = L_25 ;
break;
case V_442 :
V_435 = L_33 ;
break;
case V_443 :
V_435 = L_89 ;
break;
default:
return - 1 ;
}
strncpy ( ( char * ) V_158 -> V_61 . V_168 . V_170 , V_435 , V_171 ) ;
if ( V_438 -> V_444 & V_445 )
V_158 -> V_61 . V_168 . V_187 = 1 ;
if ( ( V_438 -> V_170 != V_441 ) &&
( V_438 -> V_444 & V_446 ) )
V_158 -> V_61 . V_168 . V_187 = 0 ;
V_158 -> V_61 . V_168 . V_175 = ( V_436 -> V_65 & 0x00FF ) - 1 ;
if ( V_438 -> V_444 & V_447 )
memcpy ( V_158 -> V_61 . V_168 . V_448 , V_438 -> V_449 , 8 ) ;
if ( V_438 -> V_173 ) {
V_158 -> V_61 . V_168 . V_173 = V_438 -> V_173 ;
memcpy ( V_158 -> V_61 . V_168 . V_172 , V_438 + 1 , V_438 -> V_173 ) ;
}
V_140 = F_30 ( V_139 , V_158 , V_159 ) ;
F_40 ( V_158 ) ;
return V_140 ;
}
static int F_104 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
if ( V_243 ) {
V_10 -> V_64 . V_66 = 14 ;
V_10 -> V_64 . V_65 = 1 ;
memcpy ( V_243 , L_90 , 14 ) ;
}
return 0 ;
}
static int F_105 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 ;
struct V_409 * V_39 ;
T_2 V_364 ;
T_4 V_3 ;
T_4 V_450 ;
T_4 V_451 ;
T_1 * V_452 ;
V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_39 = & V_10 -> V_64 ;
V_364 = V_39 -> V_66 ;
V_452 = ( T_1 * ) F_32 ( V_364 ) ;
if ( NULL == V_452 )
return - V_223 ;
if ( F_106 ( V_452 , V_39 -> V_453 , V_364 ) ) {
F_40 ( V_452 ) ;
return - V_454 ;
}
V_451 = 0 ;
V_3 = 0 ;
sscanf ( V_452 , L_91 , & V_451 , & V_3 ) ;
switch ( V_451 ) {
case 1 :
V_450 = F_107 ( V_8 , V_3 ) ;
sprintf ( V_243 , L_92 , V_450 ) ;
break;
case 2 :
V_450 = F_108 ( V_8 , V_3 ) ;
sprintf ( V_243 , L_93 , V_450 ) ;
break;
case 4 :
V_450 = F_109 ( V_8 , V_3 ) ;
sprintf ( V_243 , L_94 , V_450 ) ;
break;
default:
F_29 ( V_455 L_95 , V_343 ) ;
return - V_156 ;
}
F_29 ( V_455 L_96 , V_343 , V_3 , V_243 ) ;
F_40 ( V_452 ) ;
return 0 ;
}
static int F_110 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_3 ;
T_4 V_450 ;
T_4 V_451 ;
V_451 = 0 ;
V_3 = 0 ;
V_450 = 0 ;
sscanf ( V_243 , L_97 , & V_451 , & V_3 , & V_450 ) ;
switch ( V_451 ) {
case 1 :
F_111 ( V_8 , V_3 , ( T_1 ) V_450 ) ;
F_29 ( V_455 L_98 , V_343 , V_3 , ( T_1 ) V_450 ) ;
break;
case 2 :
F_112 ( V_8 , V_3 , ( T_2 ) V_450 ) ;
F_29 ( V_455 L_99 , V_343 , V_3 , ( T_2 ) V_450 ) ;
break;
case 4 :
F_113 ( V_8 , V_3 , V_450 ) ;
F_29 ( V_455 L_100 , V_343 , V_3 , V_450 ) ;
break;
default:
F_29 ( V_455 L_101 , V_343 ) ;
return - V_156 ;
}
return 0 ;
}
static int F_114 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_456 , V_3 , V_450 ;
V_456 = * ( T_4 * ) V_243 ;
V_3 = * ( ( T_4 * ) V_243 + 1 ) ;
V_450 = F_115 ( V_8 , V_456 , V_3 , 0xFFFFF ) ;
sprintf ( V_243 , L_102 , V_450 ) ;
return 0 ;
}
static int F_116 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_456 , V_3 , V_450 ;
V_456 = * ( T_4 * ) V_243 ;
V_3 = * ( ( T_4 * ) V_243 + 1 ) ;
V_450 = * ( ( T_4 * ) V_243 + 2 ) ;
F_117 ( V_8 , V_456 , V_3 , 0xFFFFF , V_450 ) ;
return 0 ;
}
static int F_118 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
return - 1 ;
}
static int F_119 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
return - 1 ;
}
static int F_120 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
T_1 V_457 = ( T_1 ) ( * ( ( int * ) V_10 ) ) ;
if ( V_225 == F_121 ( V_8 , V_457 , 1 ) )
F_29 ( L_103 , V_343 , V_14 -> V_458 ) ;
else
return - V_253 ;
return 0 ;
}
static int F_122 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
return 0 ;
}
static int F_123 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_106 )
{
return 0 ;
}
static int F_124 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
return 0 ;
}
static int F_125 ( struct V_138 * V_139 , struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
return 0 ;
}
static void F_126 ( struct V_7 * V_8 , T_4 V_459 , T_1 * V_460 , T_4 V_364 )
{
struct V_461 * V_462 ;
struct V_463 * V_464 ;
T_1 V_456 ;
T_1 V_465 ;
T_4 V_104 ;
F_29 ( L_57 , V_343 ) ;
switch ( V_459 ) {
case F_127 ( V_466 ) :
F_29 ( L_104 ) ;
break;
case F_127 ( V_467 ) :
V_462 = (struct V_461 * ) V_460 ;
switch ( V_462 -> V_468 ) {
case 1 :
V_462 -> V_104 = F_107 ( V_8 , V_462 -> V_465 ) ;
break;
case 2 :
V_462 -> V_104 = F_108 ( V_8 , V_462 -> V_465 ) ;
break;
case 4 :
V_462 -> V_104 = F_109 ( V_8 , V_462 -> V_465 ) ;
break;
default:
break;
}
break;
case F_127 ( V_469 ) :
V_462 = (struct V_461 * ) V_460 ;
switch ( V_462 -> V_468 ) {
case 1 :
F_111 ( V_8 , V_462 -> V_465 , ( T_1 ) V_462 -> V_104 ) ;
break;
case 2 :
F_112 ( V_8 , V_462 -> V_465 , ( T_2 ) V_462 -> V_104 ) ;
break;
case 4 :
F_113 ( V_8 , V_462 -> V_465 , ( T_4 ) V_462 -> V_104 ) ;
break;
default:
break;
}
break;
case F_127 ( V_470 ) :
V_464 = (struct V_463 * ) V_460 ;
V_456 = ( T_1 ) V_464 -> V_456 ;
V_465 = ( T_1 ) V_464 -> V_465 ;
V_104 = F_115 ( V_8 , V_456 , V_465 , 0xffffffff ) ;
V_464 -> V_104 = V_104 ;
break;
case F_127 ( V_471 ) :
V_464 = (struct V_463 * ) V_460 ;
V_456 = ( T_1 ) V_464 -> V_456 ;
V_465 = ( T_1 ) V_464 -> V_465 ;
V_104 = V_464 -> V_104 ;
F_117 ( V_8 , V_456 , V_465 , 0xffffffff , V_104 ) ;
break;
case F_127 ( V_472 ) :
F_29 ( L_105 ) ;
F_128 ( V_8 , V_473 , NULL ) ;
break;
case F_127 ( V_474 ) :
* V_460 = F_129 ( V_8 ) ;
break;
default:
break;
}
}
static int F_130 ( struct V_138 * V_139 , struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
T_4 V_475 , V_476 , V_477 ;
struct V_478 V_479 ;
struct V_480 * V_481 ;
struct V_482 * V_483 ;
T_5 V_484 = 0 ;
T_2 V_364 ;
T_1 * V_485 = NULL , V_486 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_409 * V_39 = & V_10 -> V_64 ;
if ( ( ! V_39 -> V_66 ) || ( ! V_39 -> V_453 ) ) {
V_140 = - V_156 ;
goto V_487;
}
V_485 = NULL ;
V_486 = ( T_1 ) ( V_39 -> V_65 & 0xFFFF ) ;
V_364 = V_39 -> V_66 ;
V_485 = ( T_1 * ) F_32 ( V_364 ) ;
if ( V_485 == NULL ) {
V_140 = - V_223 ;
goto V_487;
}
if ( F_106 ( V_485 , V_39 -> V_453 , V_364 ) ) {
V_140 = - V_454 ;
goto V_487;
}
V_483 = (struct V_482 * ) V_485 ;
F_23 ( V_177 , V_113 ,
( L_106 ,
V_483 -> V_488 , V_483 -> V_364 , V_364 ) ) ;
if ( V_483 -> V_488 >= V_489 ) {
F_23 ( V_177 , V_178 , ( L_107 ) ) ;
V_140 = - V_156 ;
goto V_487;
}
if ( V_8 -> V_351 . V_352 == 1 ) {
V_481 = V_490 + V_483 -> V_488 ;
if ( ( V_481 -> V_491 != 0 ) && ( V_483 -> V_364 < V_481 -> V_491 ) ) {
F_23 ( V_177 , V_178 ,
( L_108 ,
V_483 -> V_364 , V_481 -> V_491 ) ) ;
V_140 = - V_156 ;
goto V_487;
}
if ( V_481 -> V_492 ) {
V_479 . V_493 = V_8 ;
V_479 . V_494 = V_481 -> V_494 ;
V_479 . V_495 = V_483 -> V_64 ;
V_479 . V_496 = V_483 -> V_364 ;
V_479 . V_497 = 0 ;
V_476 = 0 ;
V_477 = 0 ;
if ( V_486 ) {
V_479 . V_498 = & V_475 ;
V_479 . V_499 = & V_477 ;
V_479 . V_500 = V_501 ;
} else {
V_479 . V_498 = & V_476 ;
V_479 . V_499 = & V_477 ;
V_479 . V_500 = V_502 ;
}
V_484 = V_481 -> V_492 ( & V_479 ) ;
} else {
F_29 ( L_109 ,
V_483 -> V_488 , V_481 -> V_494 , V_481 -> V_492 ) ;
V_140 = - V_454 ;
goto V_487;
}
} else {
F_126 ( V_8 , V_483 -> V_488 , V_483 -> V_64 , V_483 -> V_364 ) ;
}
if ( V_486 == 0x00 ) {
if ( F_131 ( V_39 -> V_453 , V_485 , V_364 ) )
V_140 = - V_454 ;
}
if ( V_484 ) {
V_140 = - V_454 ;
goto V_487;
}
V_487:
F_40 ( V_485 ) ;
return V_140 ;
}
static int F_132 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
T_4 V_116 = 0 , V_503 ;
unsigned long V_323 ;
struct V_326 * V_382 , * V_327 ;
unsigned char * V_504 ;
T_1 V_270 [ V_23 ] ;
char V_64 [ 32 ] ;
struct V_28 * V_29 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_409 * V_460 = & V_10 -> V_64 ;
F_29 ( L_110 ) ;
if ( ( V_8 -> V_353 ) || ( V_460 == NULL ) ) {
V_140 = - V_156 ;
goto exit;
}
while ( ( F_25 ( V_14 , ( V_356 | V_357 ) ) ) ) {
F_79 ( 30 ) ;
V_116 ++ ;
if ( V_116 > 100 )
break;
}
V_460 -> V_65 = 0 ;
if ( V_460 -> V_66 >= 32 ) {
if ( F_106 ( V_64 , V_460 -> V_453 , 32 ) ) {
V_140 = - V_156 ;
goto exit;
}
} else {
V_140 = - V_156 ;
goto exit;
}
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) == true )
break;
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
if ( F_2 ( V_64 , V_270 ) ) {
F_29 ( L_111 , ( T_1 * ) V_64 ) ;
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
return - V_156 ;
}
if ( ! memcmp ( V_270 , V_29 -> V_21 . V_22 , V_23 ) == true ) {
F_29 ( L_112 , ( V_270 ) ) ;
V_504 = F_133 ( & V_29 -> V_21 . V_58 [ 12 ] , & V_503 , V_29 -> V_21 . V_59 - 12 ) ;
if ( V_504 && ( V_503 > 0 ) ) {
V_460 -> V_65 = 1 ;
break;
}
V_504 = F_134 ( & V_29 -> V_21 . V_58 [ 12 ] , & V_503 , V_29 -> V_21 . V_59 - 12 ) ;
if ( V_504 && ( V_503 > 0 ) ) {
V_460 -> V_65 = 2 ;
break;
}
}
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
if ( V_460 -> V_66 >= 34 ) {
if ( F_131 ( V_460 -> V_453 + 32 , ( T_1 * ) & V_460 -> V_65 , 1 ) ) {
V_140 = - V_156 ;
goto exit;
}
}
exit:
return V_140 ;
}
static int F_135 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
int * V_460 = ( int * ) V_10 ;
int V_505 ;
if ( ( V_8 -> V_353 ) || ( V_460 == NULL ) ) {
V_140 = - V_156 ;
goto exit;
}
V_505 = * V_460 ;
if ( V_505 < 3 && V_505 >= 0 ) {
V_8 -> V_506 [ V_505 ] = * ( V_460 + 1 ) ;
V_507 [ V_505 ] = * ( V_460 + 1 ) ;
F_29 ( L_113 , V_343 , V_505 , V_8 -> V_506 [ V_505 ] ) ;
} else {
F_29 ( L_114 , V_343 , V_505 ) ;
}
exit:
return V_140 ;
}
static int F_136 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_409 * V_460 = & V_10 -> V_64 ;
T_4 V_508 = 0 ;
V_140 = F_106 ( ( void * ) & V_508 , V_460 -> V_453 , 4 ) ;
if ( V_140 ) {
V_140 = - V_156 ;
goto exit;
}
if ( ( V_8 -> V_353 ) || ( V_460 == NULL ) ) {
V_140 = - V_156 ;
goto exit;
}
if ( V_508 == 0 )
V_508 = * V_243 ;
F_29 ( L_115 , V_343 , V_508 ) ;
if ( V_508 == 1 )
F_137 ( V_8 , V_509 ) ;
else if ( V_508 == 2 )
F_137 ( V_8 , V_510 ) ;
else if ( V_508 == 3 )
F_137 ( V_8 , V_511 ) ;
exit:
return V_140 ;
}
static int F_138 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
struct V_286 * V_287 = & V_8 -> V_249 ;
enum V_512 V_513 = V_514 ;
if ( * V_243 == '0' )
V_513 = V_514 ;
else if ( * V_243 == '1' )
V_513 = V_515 ;
else if ( * V_243 == '2' )
V_513 = V_516 ;
else if ( * V_243 == '3' )
V_513 = V_517 ;
if ( V_188 == F_139 ( V_8 , V_513 ) ) {
V_140 = - V_454 ;
goto exit;
}
if ( V_513 != V_514 ) {
T_1 V_518 , V_519 ;
T_2 V_520 ;
if ( F_11 ( V_49 , V_521 ) ) {
V_518 = V_49 -> V_522 ;
V_49 -> V_523 = V_49 -> V_522 ;
V_519 = V_524 ;
V_520 = V_525 ;
} else {
V_49 -> V_523 = V_287 -> V_250 ;
V_518 = V_49 -> V_523 ;
V_519 = V_287 -> V_526 ;
V_520 = V_287 -> V_527 ;
}
F_140 ( V_8 , V_518 , V_519 , V_520 ) ;
}
exit:
return V_140 ;
}
static int F_141 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_116 , V_343 , V_243 , strlen ( V_243 ) ) ;
memcpy ( V_49 -> V_528 , V_243 , strlen ( V_243 ) ) ;
V_49 -> V_529 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_142 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_530 = V_49 -> V_530 ;
switch ( V_10 -> V_64 . V_66 ) {
case 1 :
V_530 = V_243 [ 0 ] - '0' ;
break;
case 2 :
V_530 = F_143 ( V_243 [ 0 ] , V_243 [ 1 ] ) ;
break;
}
if ( V_530 <= 15 )
V_49 -> V_530 = V_530 ;
else
V_140 = - 1 ;
F_29 ( L_117 , V_343 , V_530 ) ;
return V_140 ;
}
static int F_144 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_531 = V_49 -> V_522 ;
switch ( V_10 -> V_64 . V_66 ) {
case 1 :
V_531 = V_243 [ 0 ] - '0' ;
break;
case 2 :
V_531 = F_143 ( V_243 [ 0 ] , V_243 [ 1 ] ) ;
break;
}
if ( ( V_531 == 1 ) || ( V_531 == 6 ) || ( V_531 == 11 ) ) {
V_49 -> V_522 = V_531 ;
F_140 ( V_8 , V_49 -> V_522 , V_524 , V_525 ) ;
} else {
V_140 = - 1 ;
}
F_29 ( L_118 , V_343 , V_49 -> V_522 ) ;
return V_140 ;
}
static int F_145 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_532 = V_49 -> V_523 ;
switch ( V_10 -> V_64 . V_66 ) {
case 1 :
V_532 = V_243 [ 0 ] - '0' ;
break;
case 2 :
V_532 = F_143 ( V_243 [ 0 ] , V_243 [ 1 ] ) ;
break;
}
if ( V_532 > 0 )
V_49 -> V_523 = V_532 ;
else
V_140 = - 1 ;
F_29 ( L_119 , V_343 , V_49 -> V_523 ) ;
return V_140 ;
}
static int F_146 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_120 , V_343 , V_243 , V_10 -> V_64 . V_66 - 1 ) ;
if ( ! F_11 ( V_49 , V_51 ) ) {
if ( V_243 [ 0 ] == '0' ) {
F_4 ( & V_49 -> V_533 [ 0 ] , 0x00 , sizeof( struct V_534 ) * V_535 ) ;
V_49 -> V_536 = 0 ;
} else {
if ( V_49 -> V_536 >= V_535 ) {
V_140 = - 1 ;
} else {
int V_537 , V_538 ;
for ( V_537 = 0 , V_538 = 1 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_49 -> V_533 [ V_49 -> V_536 ] . V_539 [ V_537 ] = F_147 ( V_243 [ V_538 ] , V_243 [ V_538 + 1 ] ) ;
V_49 -> V_533 [ V_49 -> V_536 ] . V_540 = ( V_243 [ 18 ] - '0' ) * 10 + ( V_243 [ 19 ] - '0' ) ;
memcpy ( V_49 -> V_533 [ V_49 -> V_536 ] . V_349 , & V_243 [ 20 ] , V_49 -> V_533 [ V_49 -> V_536 ] . V_540 ) ;
V_49 -> V_536 ++ ;
}
}
}
return V_140 ;
}
static int F_148 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_121 , V_343 , V_243 , V_10 -> V_64 . V_66 - 1 ) ;
F_4 ( V_49 -> V_541 , 0x00 , V_542 ) ;
memcpy ( V_49 -> V_541 , V_243 , V_10 -> V_64 . V_66 - 1 ) ;
V_49 -> V_543 = V_10 -> V_64 . V_66 - 1 ;
return V_140 ;
}
static int F_149 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
if ( V_8 -> V_544 )
F_29 ( L_122 , V_343 , F_150 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_545 [ 0 ] , V_49 -> V_545 [ 1 ] , V_49 -> V_545 [ 2 ] ,
V_49 -> V_545 [ 3 ] , V_49 -> V_545 [ 4 ] , V_49 -> V_545 [ 5 ] ) ;
sprintf ( V_243 , L_123 , F_72 ( V_49 ) ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_151 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
sprintf ( V_243 , L_124 , V_49 -> V_546 . V_547 ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_152 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_122 , V_343 , F_150 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_545 [ 0 ] , V_49 -> V_545 [ 1 ] , V_49 -> V_545 [ 2 ] ,
V_49 -> V_545 [ 3 ] , V_49 -> V_545 [ 4 ] , V_49 -> V_545 [ 5 ] ) ;
sprintf ( V_243 , L_125 , F_150 ( V_49 ) ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_153 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_126 , V_343 ,
F_150 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_545 ) ;
sprintf ( V_243 , L_127 ,
V_49 -> V_545 ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_154 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_126 , V_343 ,
F_150 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_546 . V_548 ) ;
sprintf ( V_243 , L_128 ,
V_49 -> V_546 . V_548 ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_155 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_126 ,
V_343 , F_150 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_549 ) ;
sprintf ( V_243 , L_127 ,
V_49 -> V_549 ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_156 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
sprintf ( V_243 , L_129 ,
V_49 -> V_550 . V_551 [ 0 ] , V_49 -> V_550 . V_551 [ 1 ] ,
V_49 -> V_550 . V_551 [ 2 ] , V_49 -> V_550 . V_551 [ 3 ] ,
V_49 -> V_550 . V_551 [ 4 ] , V_49 -> V_550 . V_551 [ 5 ] ,
V_49 -> V_550 . V_349 ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_157 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_130 , V_343 , V_49 -> V_523 ) ;
sprintf ( V_243 , L_131 , V_49 -> V_523 ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_158 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_552 [ V_23 ] = { 0x00 } ;
int V_537 , V_538 ;
T_1 V_553 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
unsigned long V_323 ;
struct V_326 * V_382 , * V_327 ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_554 = 0 ;
T_2 V_555 = 0 ;
T_5 V_556 = 0 ;
T_1 V_557 [ 6 + 17 ] = { 0x00 } ;
F_29 ( L_132 , V_343 , ( char * ) V_243 ) ;
if ( F_106 ( V_553 , V_10 -> V_64 . V_453 + 6 , 17 ) )
return - V_454 ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_552 [ V_537 ] = F_147 ( V_553 [ V_538 ] , V_553 [ V_538 + 1 ] ) ;
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) == true )
break;
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_552 , V_23 ) ) {
T_1 * V_558 ;
T_5 V_559 = 0 ;
T_7 V_560 ;
V_558 = F_159 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_559 ) ;
if ( V_558 ) {
F_160 ( V_558 , V_559 , V_561 , ( T_1 * ) & V_560 , & V_556 ) ;
if ( V_556 ) {
V_555 = F_161 ( V_560 ) ;
sprintf ( V_557 , L_133 , V_555 ) ;
V_554 = 1 ;
}
}
break;
}
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
if ( ! V_554 )
sprintf ( V_557 , L_134 ) ;
if ( F_131 ( V_10 -> V_64 . V_453 , V_557 , 6 + 17 ) )
return - V_454 ;
return V_140 ;
}
static int F_162 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_552 [ V_23 ] = { 0x00 } ;
int V_537 , V_538 ;
T_1 V_553 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
unsigned long V_323 ;
struct V_326 * V_382 , * V_327 ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_554 = 0 ;
T_1 * V_562 ;
T_5 V_56 = 0 , V_556 = 0 ;
T_1 V_555 [ 100 ] = { 0x00 } ;
T_1 V_563 [ 17 + 10 ] = { 0x00 } ;
F_29 ( L_132 , V_343 , ( char * ) V_243 ) ;
if ( F_106 ( V_553 , V_10 -> V_64 . V_453 + 10 , 17 ) )
return - V_454 ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_552 [ V_537 ] = F_147 ( V_553 [ V_538 ] , V_553 [ V_538 + 1 ] ) ;
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) == true )
break;
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_552 , V_23 ) ) {
V_562 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_562 ) {
while ( V_562 ) {
F_4 ( V_555 , 0x00 , 100 ) ;
if ( F_163 ( V_562 , V_56 , V_564 , V_555 , & V_556 ) ) {
V_554 = 1 ;
break;
} else if ( F_163 ( V_562 , V_56 , V_565 , V_555 , & V_556 ) ) {
V_554 = 1 ;
break;
}
V_562 = F_12 ( V_562 + V_56 , V_29 -> V_21 . V_59 - 12 - ( V_562 - & V_29 -> V_21 . V_58 [ 12 ] + V_56 ) , NULL , & V_56 ) ;
}
}
}
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
if ( ! V_554 )
sprintf ( V_563 , L_135 ) ;
else
sprintf ( V_563 , L_136 ,
V_555 [ 0 ] , V_555 [ 1 ] , V_555 [ 2 ] , V_555 [ 3 ] , V_555 [ 4 ] , V_555 [ 5 ] ) ;
if ( F_131 ( V_10 -> V_64 . V_453 , V_563 , 10 + 17 ) )
return - V_454 ;
return V_140 ;
}
static int F_164 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_552 [ V_23 ] = { 0x00 } ;
int V_537 , V_538 ;
T_1 V_553 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
unsigned long V_323 ;
struct V_326 * V_382 , * V_327 ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_554 = 0 ;
T_1 V_566 [ 8 ] = { 0x00 } ;
T_5 V_567 = 0 ;
T_1 V_568 [ 17 + 9 ] = { 0x00 } ;
F_29 ( L_132 , V_343 , ( char * ) V_243 ) ;
if ( F_106 ( V_553 , V_10 -> V_64 . V_453 + 9 , 17 ) )
return - V_454 ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_552 [ V_537 ] = F_147 ( V_553 [ V_538 ] , V_553 [ V_538 + 1 ] ) ;
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) == true )
break;
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_552 , V_23 ) ) {
T_1 * V_558 ;
T_5 V_559 = 0 ;
V_558 = F_159 ( & V_29 -> V_21 . V_58 [ 12 ] ,
V_29 -> V_21 . V_59 - 12 ,
NULL , & V_559 ) ;
if ( V_558 ) {
F_160 ( V_558 , V_559 , V_569 , V_566 , & V_567 ) ;
if ( V_567 ) {
T_2 type = 0 ;
T_7 V_560 ;
memcpy ( & V_560 , V_566 , 2 ) ;
type = F_161 ( V_560 ) ;
sprintf ( V_568 , L_137 , type ) ;
V_554 = 1 ;
}
}
break;
}
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
if ( ! V_554 )
sprintf ( V_568 , L_138 ) ;
if ( F_131 ( V_10 -> V_64 . V_453 , V_568 , 9 + 17 ) ) {
return - V_454 ;
}
return V_140 ;
}
static int F_165 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_552 [ V_23 ] = { 0x00 } ;
int V_537 , V_538 ;
T_1 V_553 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
unsigned long V_323 ;
struct V_326 * V_382 , * V_327 ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_554 = 0 ;
T_1 V_570 [ V_542 ] = { 0x00 } ;
T_5 V_571 = 0 ;
T_1 V_572 [ V_542 + 5 ] = { 0x00 } ;
F_29 ( L_132 , V_343 , ( char * ) V_243 ) ;
if ( F_106 ( V_553 , V_10 -> V_64 . V_453 + 5 , 17 ) )
return - V_454 ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_552 [ V_537 ] = F_147 ( V_553 [ V_538 ] , V_553 [ V_538 + 1 ] ) ;
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) == true )
break;
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_552 , V_23 ) ) {
T_1 * V_558 ;
T_5 V_559 = 0 ;
V_558 = F_159 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_559 ) ;
if ( V_558 ) {
F_160 ( V_558 , V_559 , V_573 , V_570 , & V_571 ) ;
if ( V_571 ) {
sprintf ( V_572 , L_139 , V_570 ) ;
V_554 = 1 ;
}
}
break;
}
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
if ( ! V_554 )
sprintf ( V_572 , L_140 ) ;
if ( F_131 ( V_10 -> V_64 . V_453 , V_572 , 5 + ( ( V_571 > 17 ) ? V_571 : 17 ) ) )
return - V_454 ;
return V_140 ;
}
static int F_166 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_552 [ V_23 ] = { 0x00 } ;
int V_537 , V_538 ;
T_1 V_553 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
unsigned long V_323 ;
struct V_326 * V_382 , * V_327 ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_554 = 0 ;
T_1 * V_562 ;
T_5 V_56 = 0 , V_556 = 0 ;
T_1 V_555 [ 2 ] = { 0x00 } ;
T_1 V_574 [ 17 + 8 ] = { 0x00 } ;
F_29 ( L_132 , V_343 , ( char * ) V_243 ) ;
if ( F_106 ( V_553 , V_10 -> V_64 . V_453 + 8 , 17 ) )
return - V_454 ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_552 [ V_537 ] = F_147 ( V_553 [ V_538 ] , V_553 [ V_538 + 1 ] ) ;
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) == true )
break;
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_552 , V_23 ) ) {
V_562 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_562 ) {
while ( V_562 ) {
if ( F_163 ( V_562 , V_56 , V_575 , V_555 , & V_556 ) ) {
V_554 = 1 ;
break;
}
V_562 = F_12 ( V_562 + V_56 , V_29 -> V_21 . V_59 - 12 - ( V_562 - & V_29 -> V_21 . V_58 [ 12 ] + V_56 ) , NULL , & V_56 ) ;
}
}
}
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
if ( ! V_554 ) {
sprintf ( V_574 , L_141 ) ;
} else {
if ( V_555 [ 0 ] & 0x20 )
sprintf ( V_574 , L_142 ) ;
else
sprintf ( V_574 , L_143 ) ;
}
if ( F_131 ( V_10 -> V_64 . V_453 , V_574 , 8 + 17 ) )
return - V_454 ;
return V_140 ;
}
static int F_167 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_552 [ V_23 ] = { 0x00 } ;
int V_537 , V_538 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
unsigned long V_323 ;
struct V_326 * V_382 , * V_327 ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
T_5 V_576 = 0 ;
F_29 ( L_132 , V_343 , V_243 ) ;
if ( V_49 -> V_358 == V_51 ) {
F_29 ( L_144 , V_343 ) ;
return V_140 ;
}
if ( V_49 -> V_577 == V_578 )
return - 1 ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_552 [ V_537 ] = F_147 ( V_243 [ V_538 ] , V_243 [ V_538 + 1 ] ) ;
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) == true )
break;
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_552 , V_23 ) ) {
V_576 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
if ( V_576 ) {
F_4 ( & V_49 -> V_579 , 0x00 , sizeof( struct V_580 ) ) ;
F_4 ( & V_49 -> V_550 , 0x00 , sizeof( struct V_581 ) ) ;
V_49 -> V_579 . V_582 [ 0 ] = V_576 ;
memcpy ( V_49 -> V_579 . V_548 , V_29 -> V_21 . V_22 , V_23 ) ;
V_49 -> V_579 . V_583 = true ;
F_168 ( & V_49 -> V_584 ) ;
if ( F_72 ( V_49 ) != V_242 ) {
F_38 ( V_49 , V_521 ) ;
}
F_71 ( V_49 , F_72 ( V_49 ) ) ;
F_38 ( V_49 , V_585 ) ;
F_29 ( L_145 , V_343 ) ;
F_169 ( & V_49 -> V_586 , V_587 ) ;
F_169 ( & V_49 -> V_584 , V_588 ) ;
} else {
F_29 ( L_146 , V_343 ) ;
V_140 = - 1 ;
}
return V_140 ;
}
static int F_170 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
int V_537 , V_538 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_326 * V_382 , * V_327 ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
T_5 V_576 = 0 ;
T_1 V_555 [ 50 ] = { 0x00 } ;
T_1 * V_562 ;
T_5 V_56 = 0 , V_556 = 0 ;
unsigned long V_323 ;
struct V_589 * V_590 = & V_49 -> V_591 ;
F_29 ( L_132 , V_343 , V_243 ) ;
if ( V_10 -> V_64 . V_66 <= 37 ) {
F_29 ( L_147 , V_343 ) ;
return V_140 ;
}
if ( F_11 ( V_49 , V_51 ) ) {
F_29 ( L_144 , V_343 ) ;
return V_140 ;
} else {
V_590 -> V_583 = false ;
F_4 ( V_590 -> V_592 , 0x00 , V_23 ) ;
F_4 ( V_590 -> V_593 , 0x00 , V_594 ) ;
V_590 -> V_540 = 0x00 ;
V_590 -> V_595 = V_49 -> V_523 ;
F_4 ( V_590 -> V_596 , 0x00 , V_23 ) ;
V_590 -> V_597 = 3 ;
}
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_590 -> V_596 [ V_537 ] = F_147 ( V_243 [ V_538 ] , V_243 [ V_538 + 1 ] ) ;
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) == true )
break;
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
V_562 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_562 ) {
if ( F_163 ( V_562 , V_56 , V_564 , V_555 , & V_556 ) ) {
if ( ! memcmp ( V_555 , V_590 -> V_596 , V_23 ) ) {
V_576 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
} else if ( F_163 ( V_562 , V_56 , V_565 , V_555 , & V_556 ) ) {
if ( ! memcmp ( V_555 , V_590 -> V_596 , V_23 ) ) {
V_576 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
}
}
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
if ( V_576 ) {
for ( V_537 = 0 , V_538 = 18 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_590 -> V_592 [ V_537 ] = F_147 ( V_243 [ V_538 ] , V_243 [ V_538 + 1 ] ) ;
V_590 -> V_540 = V_10 -> V_64 . V_66 - 36 ;
memcpy ( V_590 -> V_593 , & V_243 [ 36 ] , ( T_4 ) V_590 -> V_540 ) ;
V_590 -> V_583 = true ;
V_590 -> V_598 = V_576 ;
F_71 ( V_49 , F_72 ( V_49 ) ) ;
F_38 ( V_49 , V_599 ) ;
F_140 ( V_8 , V_576 , V_524 , V_525 ) ;
F_169 ( & V_49 -> V_586 , V_587 ) ;
F_169 ( & V_49 -> V_584 , V_600 ) ;
} else {
F_29 ( L_148 , V_343 ) ;
}
return V_140 ;
}
static int F_171 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_132 , V_343 , V_243 ) ;
if ( F_11 ( V_49 , V_51 ) ) {
F_29 ( L_144 , V_343 ) ;
return V_140 ;
} else {
if ( V_243 [ 0 ] == '0' )
V_49 -> V_601 = false ;
else if ( V_243 [ 0 ] == '1' )
V_49 -> V_601 = true ;
else
V_49 -> V_601 = false ;
}
F_172 ( L_149 , V_343 , V_49 -> V_601 ) ;
return V_140 ;
}
static int F_173 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_552 [ V_23 ] = { 0x00 } ;
int V_537 , V_538 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_326 * V_382 , * V_327 ;
struct V_330 * V_331 = & ( V_14 -> V_332 ) ;
struct V_28 * V_29 = NULL ;
T_5 V_576 = 0 ;
T_1 V_555 [ 100 ] = { 0x00 } ;
T_1 * V_562 ;
T_5 V_56 = 0 , V_556 = 0 ;
unsigned long V_323 ;
F_29 ( L_132 , V_343 , V_243 ) ;
if ( V_49 -> V_358 == V_51 ) {
F_29 ( L_144 , V_343 ) ;
return V_140 ;
} else {
F_4 ( V_49 -> V_602 . V_548 , 0x00 , V_23 ) ;
F_4 ( V_49 -> V_602 . V_603 , 0x00 , V_23 ) ;
F_4 ( & V_49 -> V_602 . V_349 , 0x00 , sizeof( struct V_348 ) ) ;
V_49 -> V_602 . V_582 [ 0 ] = 0 ;
V_49 -> V_602 . V_582 [ 1 ] = 0 ;
V_49 -> V_602 . V_583 = false ;
}
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_23 ; V_537 ++ , V_538 += 3 )
V_552 [ V_537 ] = F_147 ( V_243 [ V_538 ] , V_243 [ V_538 + 1 ] ) ;
if ( ! memcmp ( & V_243 [ 18 ] , L_150 , 7 ) ) {
V_49 -> V_602 . V_604 = V_605 ;
} else if ( ! memcmp ( & V_243 [ 18 ] , L_151 , 7 ) ) {
V_49 -> V_602 . V_604 = V_606 ;
} else if ( ! memcmp ( & V_243 [ 18 ] , L_152 , 3 ) ) {
V_49 -> V_602 . V_604 = V_607 ;
} else if ( ! memcmp ( & V_243 [ 18 ] , L_153 , 5 ) ) {
V_49 -> V_602 . V_604 = V_608 ;
} else {
F_29 ( L_154 , V_343 ) ;
return V_140 ;
}
F_59 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
V_327 = F_60 ( V_331 ) ;
V_382 = F_61 ( V_327 ) ;
while ( 1 ) {
if ( F_62 ( V_327 , V_382 ) == true )
break;
if ( V_576 != 0 )
break;
V_29 = F_63 ( V_382 , struct V_28 , V_338 ) ;
V_562 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_562 ) {
while ( V_562 ) {
if ( F_163 ( V_562 , V_56 , V_564 , V_555 , & V_556 ) ) {
if ( ! memcmp ( V_555 , V_552 , V_23 ) ) {
V_576 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
} else if ( F_163 ( V_562 , V_56 , V_565 , V_555 , & V_556 ) ) {
if ( ! memcmp ( V_555 , V_552 , V_23 ) ) {
V_576 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
}
V_562 = F_12 ( V_562 + V_56 , V_29 -> V_21 . V_59 - 12 - ( V_562 - & V_29 -> V_21 . V_58 [ 12 ] + V_56 ) , NULL , & V_56 ) ;
}
}
V_382 = F_61 ( V_382 ) ;
}
F_64 ( & ( V_14 -> V_332 . V_336 ) , & V_323 ) ;
if ( V_576 ) {
F_29 ( L_155 , V_343 , V_576 ) ;
memcpy ( V_49 -> V_602 . V_603 , V_29 -> V_21 . V_22 , V_23 ) ;
memcpy ( V_49 -> V_602 . V_548 , V_552 , V_23 ) ;
V_49 -> V_602 . V_582 [ 0 ] = ( T_2 ) V_576 ;
V_49 -> V_602 . V_583 = true ;
F_71 ( V_49 , F_72 ( V_49 ) ) ;
F_38 ( V_49 , V_609 ) ;
if ( F_174 ( V_49 , V_516 ) ) {
memcpy ( & V_49 -> V_602 . V_349 , & V_29 -> V_21 . V_53 , sizeof( struct V_348 ) ) ;
} else if ( F_174 ( V_49 , V_515 ) || F_174 ( V_49 , V_517 ) ) {
memcpy ( V_49 -> V_602 . V_349 . V_53 , V_49 -> V_54 , V_55 ) ;
V_49 -> V_602 . V_349 . V_67 = V_55 ;
}
F_140 ( V_8 , V_576 , V_524 , V_525 ) ;
F_169 ( & V_49 -> V_586 , V_587 ) ;
F_169 ( & V_49 -> V_584 , V_610 ) ;
} else {
F_29 ( L_148 , V_343 ) ;
}
return V_140 ;
}
static int F_175 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_132 , V_343 , V_243 ) ;
if ( * V_243 == '0' )
V_49 -> V_577 = V_578 ;
else if ( * V_243 == '1' )
V_49 -> V_577 = V_611 ;
else if ( * V_243 == '2' )
V_49 -> V_577 = V_612 ;
else if ( * V_243 == '3' )
V_49 -> V_577 = V_613 ;
else
V_49 -> V_577 = V_578 ;
return V_140 ;
}
static int F_176 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
#ifdef F_10
F_29 ( L_156 , V_343 , V_243 ) ;
if ( ! memcmp ( V_243 , L_157 , 7 ) ) {
F_138 ( V_139 , V_27 , V_10 , & V_243 [ 7 ] ) ;
} else if ( ! memcmp ( V_243 , L_158 , 6 ) ) {
V_10 -> V_64 . V_66 -= 6 ;
F_148 ( V_139 , V_27 , V_10 , & V_243 [ 6 ] ) ;
} else if ( ! memcmp ( V_243 , L_159 , 13 ) ) {
V_10 -> V_64 . V_66 -= 13 ;
F_146 ( V_139 , V_27 , V_10 , & V_243 [ 13 ] ) ;
} else if ( ! memcmp ( V_243 , L_160 , 10 ) ) {
V_10 -> V_64 . V_66 -= 10 ;
F_173 ( V_139 , V_27 , V_10 , & V_243 [ 10 ] ) ;
} else if ( ! memcmp ( V_243 , L_161 , 5 ) ) {
V_10 -> V_64 . V_66 -= 5 ;
F_167 ( V_139 , V_27 , V_10 , & V_243 [ 5 ] ) ;
} else if ( ! memcmp ( V_243 , L_162 , 7 ) ) {
V_10 -> V_64 . V_66 -= 8 ;
F_142 ( V_139 , V_27 , V_10 , & V_243 [ 7 ] ) ;
} else if ( ! memcmp ( V_243 , L_163 , 5 ) ) {
V_10 -> V_64 . V_66 -= 5 ;
F_141 ( V_139 , V_27 , V_10 , & V_243 [ 5 ] ) ;
} else if ( ! memcmp ( V_243 , L_164 , 12 ) ) {
V_10 -> V_64 . V_66 -= 12 ;
F_175 ( V_139 , V_27 , V_10 , & V_243 [ 12 ] ) ;
} else if ( ! memcmp ( V_243 , L_165 , 10 ) ) {
V_10 -> V_64 . V_66 -= 11 ;
F_144 ( V_139 , V_27 , V_10 , & V_243 [ 10 ] ) ;
} else if ( ! memcmp ( V_243 , L_166 , 6 ) ) {
V_10 -> V_64 . V_66 -= 7 ;
F_145 ( V_139 , V_27 , V_10 , & V_243 [ 6 ] ) ;
} else if ( ! memcmp ( V_243 , L_167 , 7 ) ) {
V_10 -> V_64 . V_66 -= 8 ;
F_170 ( V_139 , V_27 , V_10 , & V_243 [ 7 ] ) ;
} else if ( ! memcmp ( V_243 , L_168 , 11 ) ) {
V_10 -> V_64 . V_66 -= 11 ;
F_171 ( V_139 , V_27 , V_10 , & V_243 [ 11 ] ) ;
}
#endif
return V_140 ;
}
static int F_177 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
#ifdef F_10
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
if ( V_8 -> V_544 )
F_29 ( L_156 , V_343 , ( char * ) V_10 -> V_64 . V_453 ) ;
if ( ! memcmp ( V_10 -> V_64 . V_453 , L_169 , 6 ) ) {
F_149 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_453 , L_170 , 4 ) ) {
F_152 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_453 , L_171 , 8 ) ) {
F_153 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_453 , L_172 , 6 ) ) {
F_151 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_453 , L_173 , 9 ) ) {
F_154 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_453 , L_174 , 8 ) ) {
F_156 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_453 , L_175 , 9 ) ) {
F_155 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_453 , L_176 , 5 ) ) {
F_157 ( V_139 , V_27 , V_10 , V_243 ) ;
}
#endif
return V_140 ;
}
static int F_178 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
#ifdef F_10
F_29 ( L_156 , V_343 , ( char * ) V_10 -> V_64 . V_453 ) ;
if ( ! memcmp ( V_243 , L_177 , 6 ) ) {
V_10 -> V_64 . V_66 -= 6 ;
F_158 ( V_139 , V_27 , V_10 , & V_243 [ 6 ] ) ;
} else if ( ! memcmp ( V_243 , L_178 , 5 ) ) {
V_10 -> V_64 . V_66 -= 5 ;
F_165 ( V_139 , V_27 , V_10 , & V_243 [ 5 ] ) ;
} else if ( ! memcmp ( V_243 , L_179 , 9 ) ) {
V_10 -> V_64 . V_66 -= 9 ;
F_164 ( V_139 , V_27 , V_10 , & V_243 [ 9 ] ) ;
} else if ( ! memcmp ( V_243 , L_180 , 10 ) ) {
V_10 -> V_64 . V_66 -= 10 ;
F_162 ( V_139 , V_27 , V_10 , & V_243 [ 10 ] ) ;
} else if ( ! memcmp ( V_243 , L_181 , 8 ) ) {
V_10 -> V_64 . V_66 -= 8 ;
F_166 ( V_139 , V_27 , V_10 , & V_243 [ 8 ] ) ;
}
#endif
return V_140 ;
}
static int F_179 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_182 , V_343 , V_243 ) ;
if ( ! strcmp ( V_243 , L_183 ) )
V_8 -> V_614 = 1 ;
else
V_8 -> V_614 = 0 ;
if ( V_8 -> V_614 ) {
T_4 V_615 = F_109 ( V_8 , V_616 ) ;
V_615 &= ~ ( V_617 | V_618 ) ;
F_113 ( V_8 , V_616 , V_615 ) ;
F_29 ( L_184 ) ;
} else {
T_4 V_615 = F_109 ( V_8 , V_616 ) ;
V_615 |= V_617 | V_618 ;
F_113 ( V_8 , V_616 , V_615 ) ;
F_29 ( L_185 ) ;
}
return V_140 ;
}
static int F_180 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
struct V_619 * V_620 = & V_8 -> V_621 ;
char V_622 [ V_79 ] ;
if ( V_620 -> V_623 [ 0 ] == 0 ) {
char * V_624 ;
V_624 = V_8 -> V_351 . V_625 ;
strncpy ( V_620 -> V_623 , V_624 , V_79 ) ;
V_620 -> V_623 [ V_79 - 1 ] = 0 ;
}
if ( V_10 -> V_64 . V_66 > V_79 )
return - V_454 ;
if ( F_106 ( V_622 , V_10 -> V_64 . V_453 , V_79 ) )
return - V_454 ;
if ( 0 == strcmp ( V_620 -> V_623 , V_622 ) )
return V_140 ;
F_29 ( L_186 , V_343 , V_622 ) ;
V_140 = F_181 ( V_8 , V_622 ) ;
if ( 0 != V_140 )
goto exit;
if ( ! memcmp ( V_620 -> V_623 , L_187 , 9 ) == true ) {
V_8 -> V_626 . V_627 = V_620 -> V_628 ;
F_182 ( V_8 ) ;
F_183 ( & V_8 -> V_386 , V_620 -> V_629 ) ;
}
strncpy ( V_620 -> V_623 , V_622 , V_79 ) ;
V_620 -> V_623 [ V_79 - 1 ] = 0 ;
if ( ! memcmp ( V_622 , L_187 , 9 ) == true ) {
F_29 ( L_188 , V_343 ) ;
F_74 ( V_8 , true ) ;
F_137 ( V_8 , V_630 ) ;
V_620 -> V_628 = V_8 -> V_626 . V_627 ;
V_8 -> V_626 . V_627 = false ;
F_184 ( V_8 ) ;
V_620 -> V_629 = F_185 ( & V_8 -> V_386 ) ;
F_183 ( & V_8 -> V_386 , V_631 ) ;
}
exit:
return V_140 ;
}
static void F_186 ( struct V_7 * V_8 )
{
int V_4 , V_264 = 1 ;
F_172 ( L_189 ) ;
for ( V_4 = 0x0 ; V_4 < 0x300 ; V_4 += 4 ) {
if ( V_264 % 4 == 1 )
F_172 ( L_190 , V_4 ) ;
F_172 ( L_191 , F_109 ( V_8 , V_4 ) ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_172 ( L_192 ) ;
}
for ( V_4 = 0x400 ; V_4 < 0x800 ; V_4 += 4 ) {
if ( V_264 % 4 == 1 )
F_172 ( L_190 , V_4 ) ;
F_172 ( L_191 , F_109 ( V_8 , V_4 ) ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_172 ( L_192 ) ;
}
}
static void F_187 ( struct V_7 * V_8 )
{
int V_4 , V_264 = 1 ;
F_172 ( L_193 ) ;
for ( V_4 = 0x800 ; V_4 < 0x1000 ; V_4 += 4 ) {
if ( V_264 % 4 == 1 )
F_172 ( L_190 , V_4 ) ;
F_172 ( L_191 , F_109 ( V_8 , V_4 ) ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_172 ( L_192 ) ;
}
}
static void F_188 ( struct V_7 * V_8 )
{
int V_4 , V_264 = 1 , V_456 ;
T_4 V_104 ;
T_1 V_632 , V_633 = 0 ;
F_189 ( V_8 , V_634 , ( T_1 * ) ( & V_632 ) ) ;
F_172 ( L_194 ) ;
if ( ( V_635 == V_632 ) || ( V_636 == V_632 ) )
V_633 = 1 ;
else
V_633 = 2 ;
for ( V_456 = 0 ; V_456 < V_633 ; V_456 ++ ) {
F_172 ( L_195 , V_456 ) ;
for ( V_4 = 0 ; V_4 < 0x100 ; V_4 ++ ) {
V_104 = F_115 ( V_8 , V_456 , V_4 , 0xffffffff ) ;
if ( V_264 % 4 == 1 )
F_172 ( L_196 , V_4 ) ;
F_172 ( L_191 , V_104 ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_172 ( L_192 ) ;
}
}
}
static int F_190 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
unsigned long V_323 ;
int V_140 = 0 ;
T_1 V_637 , V_638 ;
T_2 V_639 ;
T_8 V_640 ;
T_4 * V_460 , V_641 ;
struct V_194 * V_195 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_286 * V_287 = & V_8 -> V_249 ;
struct V_642 * V_643 = & ( V_287 -> V_644 ) ;
struct V_165 * V_166 = & V_8 -> V_143 ;
struct V_28 * V_20 = & ( V_14 -> V_20 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
V_460 = ( T_4 * ) & V_10 -> V_64 ;
V_641 = * V_460 ;
V_639 = ( T_2 ) ( V_641 & 0x0000ffff ) ;
V_637 = ( T_1 ) ( V_641 >> 24 ) ;
V_638 = ( T_1 ) ( ( V_641 >> 16 ) & 0x00ff ) ;
V_640 = * ( V_460 + 1 ) ;
switch ( V_637 ) {
case 0x70 :
switch ( V_638 ) {
case 1 :
F_29 ( L_197 , V_639 , F_107 ( V_8 , V_639 ) ) ;
break;
case 2 :
F_29 ( L_198 , V_639 , F_108 ( V_8 , V_639 ) ) ;
break;
case 4 :
F_29 ( L_199 , V_639 , F_109 ( V_8 , V_639 ) ) ;
break;
}
break;
case 0x71 :
switch ( V_638 ) {
case 1 :
F_111 ( V_8 , V_639 , V_640 ) ;
F_29 ( L_200 , V_639 , F_107 ( V_8 , V_639 ) ) ;
break;
case 2 :
F_112 ( V_8 , V_639 , V_640 ) ;
F_29 ( L_201 , V_639 , F_108 ( V_8 , V_639 ) ) ;
break;
case 4 :
F_113 ( V_8 , V_639 , V_640 ) ;
F_29 ( L_202 , V_639 , F_109 ( V_8 , V_639 ) ) ;
break;
}
break;
case 0x72 :
F_29 ( L_203 , V_639 , F_191 ( V_8 , V_639 , 0xffffffff ) ) ;
break;
case 0x73 :
F_192 ( V_8 , V_639 , 0xffffffff , V_640 ) ;
F_29 ( L_204 , V_639 , F_191 ( V_8 , V_639 , 0xffffffff ) ) ;
break;
case 0x74 :
F_29 ( L_205 , V_638 , V_639 , F_115 ( V_8 , V_638 , V_639 , 0xffffffff ) ) ;
break;
case 0x75 :
F_117 ( V_8 , V_638 , V_639 , 0xffffffff , V_640 ) ;
F_29 ( L_206 , V_638 , V_639 , F_115 ( V_8 , V_638 , V_639 , 0xffffffff ) ) ;
break;
case 0x76 :
switch ( V_638 ) {
case 0x00 :
V_8 -> V_129 . V_645 = 0 ;
break;
case 0x01 :
V_8 -> V_129 . V_645 = 1 ;
V_640 = V_640 > 100 ? 100 : V_640 ;
V_640 = V_640 < 0 ? 0 : V_640 ;
V_8 -> V_129 . V_646 = V_640 ;
break;
}
break;
case 0x78 :
switch ( V_638 ) {
case 0x04 :
{
T_1 V_647 = 0xf9 ;
struct V_648 * V_648 ;
V_648 = F_193 ( V_8 ) ;
if ( V_648 == NULL ) {
V_140 = - V_223 ;
break;
}
F_194 ( V_648 , V_647 ) ;
if ( V_225 != F_195 ( V_8 , V_648 , 500 , 0 ) )
V_140 = - V_253 ;
}
break;
case 0x05 :
{
T_2 V_649 = 0x4c ;
T_4 V_650 = 50 ;
T_4 V_651 = 200 ;
int V_4 ;
struct V_648 * V_648 ;
V_648 = F_193 ( V_8 ) ;
if ( V_648 == NULL ) {
V_140 = - V_223 ;
break;
}
for ( V_4 = 0 ; V_4 < V_650 ; V_4 ++ ) {
F_196 ( V_648 , V_649 , 0x00 , 0xff ) ;
F_197 ( V_648 , V_651 ) ;
F_196 ( V_648 , V_649 , 0x08 , 0xff ) ;
F_197 ( V_648 , V_651 ) ;
}
if ( V_225 != F_195 ( V_8 , V_648 , ( V_651 * V_650 * 2 ) + 200 , 0 ) )
V_140 = - V_253 ;
}
break;
case 0x06 :
{
T_2 V_649 = V_639 ;
T_2 V_652 = 0 ;
T_4 V_653 = V_640 ;
int V_4 ;
T_1 V_654 ;
struct V_648 * V_648 ;
V_648 = F_193 ( V_8 ) ;
if ( V_648 == NULL ) {
V_140 = - V_223 ;
break;
}
for ( V_4 = 0 ; V_4 < V_653 ; V_4 ++ )
F_196 ( V_648 , V_649 , V_4 + V_652 , 0xFF ) ;
if ( V_225 != F_195 ( V_8 , V_648 , 5000 , 0 ) )
V_140 = - V_253 ;
V_654 = F_107 ( V_8 , V_649 ) ;
if ( V_652 + V_653 - 1 == V_654 )
F_29 ( L_207 , V_649 , V_653 , V_652 , V_654 ) ;
else
F_29 ( L_208 , V_649 , V_653 , V_652 , V_654 ) ;
}
break;
case 0x07 :
{
T_2 V_649 = V_639 ;
T_2 V_652 = 200 ;
T_4 V_653 = V_640 ;
int V_4 ;
T_2 V_654 ;
struct V_648 * V_648 ;
V_648 = F_193 ( V_8 ) ;
if ( V_648 == NULL ) {
V_140 = - V_223 ;
break;
}
for ( V_4 = 0 ; V_4 < V_653 ; V_4 ++ )
F_198 ( V_648 , V_649 , V_4 + V_652 , 0xFFFF ) ;
if ( V_225 != F_195 ( V_8 , V_648 , 5000 , 0 ) )
V_140 = - V_253 ;
V_654 = F_108 ( V_8 , V_649 ) ;
if ( V_652 + V_653 - 1 == V_654 )
F_29 ( L_209 , V_649 , V_653 , V_652 , V_654 ) ;
else
F_29 ( L_210 , V_649 , V_653 , V_652 , V_654 ) ;
}
break;
case 0x08 :
{
T_2 V_649 = V_639 ;
T_4 V_652 = 0x110000c7 ;
T_4 V_653 = V_640 ;
int V_4 ;
T_4 V_654 ;
struct V_648 * V_648 ;
V_648 = F_193 ( V_8 ) ;
if ( V_648 == NULL ) {
V_140 = - V_223 ;
break;
}
for ( V_4 = 0 ; V_4 < V_653 ; V_4 ++ )
F_199 ( V_648 , V_649 , V_4 + V_652 , 0xFFFFFFFF ) ;
if ( V_225 != F_195 ( V_8 , V_648 , 5000 , 0 ) )
V_140 = - V_253 ;
V_654 = F_109 ( V_8 , V_649 ) ;
if ( V_652 + V_653 - 1 == V_654 )
F_29 ( L_211 ,
V_649 , V_653 , V_652 , V_654 ) ;
else
F_29 ( L_212 ,
V_649 , V_653 , V_652 , V_654 ) ;
}
break;
}
break;
case 0x79 :
{
T_1 V_104 = V_640 & 0x0f ;
T_1 V_655 = V_638 ;
T_2 V_656 = 0 ;
F_29 ( L_213 , V_343 , V_655 ? L_214 : L_215 , V_104 ) ;
if ( V_655 )
V_104 = V_104 | 0x10 ;
V_656 = V_104 | ( V_104 << 5 ) ;
F_112 ( V_8 , 0x6d9 , V_656 ) ;
}
break;
case 0x7a :
F_200 ( V_8 , V_643 -> V_21 . V_22
, V_657 ) ;
break;
case 0x7F :
switch ( V_638 ) {
case 0x0 :
F_29 ( L_216 , F_82 ( V_14 ) ) ;
break;
case 0x01 :
F_29 ( L_217 ,
V_166 -> V_148 , V_166 -> V_179 ,
V_166 -> V_146 , V_166 -> V_144 ) ;
break;
case 0x02 :
F_29 ( L_218 , V_643 -> V_658 ) ;
break;
case 0x03 :
F_29 ( L_219 , V_14 -> V_659 . V_660 ) ;
F_29 ( L_220 , V_14 -> V_661 . V_662 ) ;
break;
case 0x04 :
F_29 ( L_221 , V_287 -> V_250 ) ;
F_29 ( L_222 , V_287 -> V_527 ) ;
F_29 ( L_223 , V_287 -> V_526 ) ;
break;
case 0x05 :
V_195 = F_35 ( V_198 , V_20 -> V_21 . V_22 ) ;
if ( V_195 ) {
int V_4 ;
struct V_663 * V_664 ;
F_29 ( L_224 , V_20 -> V_21 . V_53 . V_53 ) ;
F_29 ( L_225 , V_195 -> V_665 ) ;
F_29 ( L_226 , V_287 -> V_250 , V_287 -> V_527 , V_287 -> V_526 ) ;
F_29 ( L_227 , V_195 -> V_666 , V_195 -> V_667 ) ;
F_29 ( L_228 , V_195 -> V_658 , V_195 -> V_668 , V_195 -> V_669 , V_195 -> V_670 ) ;
F_29 ( L_229 , V_195 -> V_660 , V_195 -> V_661 . V_662 , V_195 -> V_671 ) ;
F_29 ( L_230 , V_195 -> V_661 . V_520 , V_195 -> V_661 . V_519 , V_195 -> V_661 . V_672 ) ;
F_29 ( L_231 , V_195 -> V_661 . V_673 ) ;
F_29 ( L_232 , V_195 -> V_661 . V_674 , V_195 -> V_661 . V_675 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
V_664 = & V_195 -> V_676 [ V_4 ] ;
if ( V_664 -> V_677 )
F_29 ( L_233 , V_4 , V_664 -> V_678 ) ;
}
} else {
F_29 ( L_234 , ( V_20 -> V_21 . V_22 ) ) ;
}
break;
case 0x06 :
{
T_4 V_679 ;
F_189 ( V_8 , V_680 , ( T_1 * ) ( & V_679 ) ) ;
F_29 ( L_235 , V_679 , V_639 ) ;
V_679 = ( T_4 ) ( 0x0f & V_639 ) ;
F_29 ( L_236 , V_679 ) ;
F_128 ( V_8 , V_680 , ( T_1 * ) ( & V_679 ) ) ;
}
break;
case 0x07 :
F_29 ( L_237 ,
V_8 -> V_681 , V_8 -> V_353 ) ;
break;
case 0x08 :
{
struct V_682 * V_683 = & V_8 -> V_403 ;
struct V_684 * V_685 = & V_8 -> V_129 ;
F_29 ( L_238 ,
V_683 -> V_686 , V_683 -> V_687 , V_683 -> V_688 ) ;
F_29 ( L_239 , V_685 -> V_689 ) ;
}
break;
case 0x09 :
{
int V_4 , V_264 ;
struct V_326 * V_382 , * V_327 ;
struct V_663 * V_664 ;
#ifdef F_201
F_29 ( L_240 , V_198 -> V_690 , V_198 -> V_691 ) ;
#endif
F_59 ( & V_198 -> V_692 , & V_323 ) ;
for ( V_4 = 0 ; V_4 < V_693 ; V_4 ++ ) {
V_327 = & ( V_198 -> V_694 [ V_4 ] ) ;
V_382 = F_61 ( V_327 ) ;
while ( ( F_62 ( V_327 , V_382 ) ) == false ) {
V_195 = F_63 ( V_382 , struct V_194 , V_695 ) ;
V_382 = F_61 ( V_382 ) ;
if ( V_640 == V_195 -> V_668 ) {
F_29 ( L_241 , ( V_195 -> V_665 ) ) ;
F_29 ( L_227 , V_195 -> V_666 , V_195 -> V_667 ) ;
F_29 ( L_228 , V_195 -> V_658 , V_195 -> V_668 , V_195 -> V_669 , V_195 -> V_670 ) ;
F_29 ( L_229 , V_195 -> V_660 , V_195 -> V_661 . V_662 , V_195 -> V_671 ) ;
F_29 ( L_230 , V_195 -> V_661 . V_520 , V_195 -> V_661 . V_519 , V_195 -> V_661 . V_672 ) ;
F_29 ( L_231 , V_195 -> V_661 . V_673 ) ;
F_29 ( L_232 , V_195 -> V_661 . V_674 , V_195 -> V_661 . V_675 ) ;
#ifdef F_201
F_29 ( L_242 , V_195 -> V_696 ) ;
F_29 ( L_243 , V_195 -> V_65 ) ;
F_29 ( L_244 , V_195 -> V_697 ) ;
F_29 ( L_245 , V_195 -> V_698 ) ;
F_29 ( L_246 , V_195 -> V_699 ) ;
F_29 ( L_247 , V_195 -> V_700 ) ;
#endif
F_29 ( L_248 , V_195 -> V_205 ) ;
for ( V_264 = 0 ; V_264 < 16 ; V_264 ++ ) {
V_664 = & V_195 -> V_676 [ V_264 ] ;
if ( V_664 -> V_677 )
F_29 ( L_233 , V_264 , V_664 -> V_678 ) ;
}
}
}
}
F_64 ( & V_198 -> V_692 , & V_323 ) ;
}
break;
case 0x0c :
if ( V_639 == 0 ) {
F_29 ( L_249 , V_640 ) ;
F_202 ( V_8 , V_701 , & ( V_640 ) ) ;
} else if ( V_639 == 1 ) {
F_29 ( L_250 , V_640 ) ;
F_202 ( V_8 , V_702 , & ( V_640 ) ) ;
}
break;
case 0x0f :
if ( V_640 == 0 ) {
F_29 ( L_251 ) ;
F_203 ( V_8 ) ;
}
break;
case 0x15 :
{
struct V_412 * V_413 = & V_8 -> V_386 ;
F_29 ( L_252 , V_413 -> V_703 ) ;
}
break;
case 0x10 :
F_29 ( L_253 , V_704 ) ;
break;
case 0x11 :
F_29 ( L_254 , ( V_640 == 1 ) ? L_255 : L_256 ) ;
V_8 -> V_705 = V_640 ;
F_202 ( V_8 , V_706 , & V_640 ) ;
break;
case 0x12 :
{
struct V_707 * V_708 = & V_8 -> V_351 ;
if ( V_708 &&
( V_640 == 0 ||
V_640 == 1 ||
V_640 == 2 ||
V_640 == 3 ) ) {
V_708 -> V_709 = V_640 ;
F_29 ( L_257 , V_708 -> V_709 ) ;
} else {
F_29 ( L_258 , V_708 -> V_709 ) ;
}
}
break;
case 0x13 :
{
struct V_707 * V_708 = & V_8 -> V_351 ;
if ( V_708 && V_640 >= 0 && V_640 < 3 ) {
V_708 -> V_673 = V_640 ;
F_29 ( L_259 , V_708 -> V_673 ) ;
} else {
F_29 ( L_260 , V_708 -> V_673 ) ;
}
}
break;
case 0x14 :
{
struct V_707 * V_708 = & V_8 -> V_351 ;
F_29 ( L_261 , V_708 -> V_710 ) ;
}
break;
case 0x16 :
if ( V_639 == 0xff ) {
F_172 ( L_262 ) ;
F_172 ( L_263 ) ;
F_172 ( L_264 ) ;
F_172 ( L_265 ) ;
F_172 ( L_266 ) ;
F_172 ( L_267 ) ;
F_172 ( L_268 ) ;
F_172 ( L_269 ) ;
F_172 ( L_270 ) ;
F_172 ( L_271 ) ;
F_172 ( L_272 ) ;
F_172 ( L_273 ) ;
F_172 ( L_274 ) ;
F_172 ( L_275 ) ;
F_172 ( L_276 ) ;
F_172 ( L_277 ) ;
F_172 ( L_278 ) ;
F_172 ( L_279 ) ;
F_172 ( L_280 ) ;
F_204 ( V_8 , V_711 , & V_640 ) ;
} else {
F_202 ( V_8 , V_711 , & V_640 ) ;
}
break;
case 0x23 :
F_29 ( L_281 , ( V_640 == 1 ) ? L_255 : L_256 ) ;
V_8 -> V_712 = V_640 ;
break;
case 0x24 :
#ifdef F_10
F_29 ( L_282 , ( V_640 == 1 ) ? L_255 : L_256 ) ;
V_8 -> V_544 = V_640 ;
#endif
break;
case 0xaa :
if ( V_640 > 0x13 )
V_640 = 0xFF ;
F_29 ( L_283 , V_640 ) ;
V_8 -> V_713 = V_640 ;
break;
case 0xdd :
if ( V_640 == 0 )
F_186 ( V_8 ) ;
else if ( V_640 == 1 )
F_187 ( V_8 ) ;
else if ( V_640 == 2 )
F_188 ( V_8 ) ;
break;
case 0xee :
{
T_4 V_714 ;
if ( 0xf == V_640 ) {
F_204 ( V_8 , V_715 , & V_714 ) ;
F_29 ( L_284 , V_714 ) ;
F_29 ( L_285 ) ;
F_29 ( L_286 ) ;
F_29 ( L_287 ) ;
F_29 ( L_288 ) ;
F_29 ( L_289 ) ;
F_29 ( L_290 ) ;
F_29 ( L_291 ) ;
} else {
F_202 ( V_8 , V_715 , & ( V_640 ) ) ;
F_204 ( V_8 , V_715 , & V_714 ) ;
F_29 ( L_284 , V_714 ) ;
}
}
break;
case 0xfd :
F_111 ( V_8 , 0xc50 , V_639 ) ;
F_29 ( L_292 , F_107 ( V_8 , 0xc50 ) ) ;
F_111 ( V_8 , 0xc58 , V_639 ) ;
F_29 ( L_293 , F_107 ( V_8 , 0xc58 ) ) ;
break;
case 0xfe :
F_29 ( L_294 , F_107 ( V_8 , 0xc50 ) ) ;
F_29 ( L_295 , F_107 ( V_8 , 0xc58 ) ) ;
break;
case 0xff :
F_29 ( L_296 , F_109 ( V_8 , 0x210 ) ) ;
F_29 ( L_297 , F_109 ( V_8 , 0x608 ) ) ;
F_29 ( L_298 , F_109 ( V_8 , 0x280 ) ) ;
F_29 ( L_299 , F_109 ( V_8 , 0x284 ) ) ;
F_29 ( L_300 , F_109 ( V_8 , 0x288 ) ) ;
F_29 ( L_301 , F_109 ( V_8 , 0x664 ) ) ;
F_29 ( L_192 ) ;
F_29 ( L_302 , F_109 ( V_8 , 0x430 ) ) ;
F_29 ( L_303 , F_109 ( V_8 , 0x438 ) ) ;
F_29 ( L_304 , F_109 ( V_8 , 0x440 ) ) ;
F_29 ( L_305 , F_109 ( V_8 , 0x458 ) ) ;
F_29 ( L_306 , F_109 ( V_8 , 0x484 ) ) ;
F_29 ( L_307 , F_109 ( V_8 , 0x488 ) ) ;
F_29 ( L_308 , F_109 ( V_8 , 0x444 ) ) ;
F_29 ( L_309 , F_109 ( V_8 , 0x448 ) ) ;
F_29 ( L_310 , F_109 ( V_8 , 0x44c ) ) ;
F_29 ( L_311 , F_109 ( V_8 , 0x450 ) ) ;
break;
}
break;
default:
F_29 ( L_312 ) ;
break;
}
return V_140 ;
}
static int F_205 ( struct V_138 * V_139 , T_1 V_78 , T_4 V_104 )
{
T_5 V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
switch ( V_78 ) {
case V_716 :
V_8 -> V_143 . V_148 = V_193 ;
switch ( ( V_104 ) & 0xff ) {
case 1 :
V_8 -> V_143 . V_146 = V_152 ;
V_8 -> V_143 . V_144 = V_203 ;
break;
case 2 :
V_8 -> V_143 . V_146 = V_227 ;
V_8 -> V_143 . V_144 = V_204 ;
break;
}
F_23 ( V_177 , V_113 ,
( L_313 , V_8 -> V_143 . V_146 ) ) ;
break;
case V_717 :
break;
case V_718 : {
break;
}
case V_719 :
break;
case V_720 :
V_140 = F_27 ( V_139 , V_104 ) ;
break;
case V_721 :
break;
case V_722 :
break;
default:
V_140 = - V_189 ;
break;
}
return V_140 ;
}
static int F_206 ( struct V_138 * V_139 , T_4 V_723 , T_4 V_340 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
switch ( V_723 ) {
case V_724 :
if ( ! F_69 ( V_8 ) )
V_140 = - 1 ;
break;
case V_725 :
if ( ! F_69 ( V_8 ) )
V_140 = - 1 ;
break;
default:
V_140 = - V_189 ;
break;
}
return V_140 ;
}
static int F_207 ( struct V_138 * V_139 , struct V_409 * V_39 )
{
struct V_157 * V_158 ;
T_5 V_140 = 0 ;
if ( V_39 -> V_66 < sizeof( struct V_157 ) || ! V_39 -> V_453 ) {
V_140 = - V_156 ;
goto V_726;
}
V_158 = (struct V_157 * ) F_32 ( V_39 -> V_66 ) ;
if ( V_158 == NULL ) {
V_140 = - V_223 ;
goto V_726;
}
if ( F_106 ( V_158 , V_39 -> V_453 , V_39 -> V_66 ) ) {
F_40 ( V_158 ) ;
V_140 = - V_454 ;
goto V_726;
}
switch ( V_158 -> V_60 ) {
case V_727 :
V_140 = F_205 ( V_139 , V_158 -> V_61 . V_728 . V_78 , V_158 -> V_61 . V_728 . V_104 ) ;
break;
case V_729 :
V_140 = F_41 ( (struct V_7 * ) F_28 ( V_139 ) ,
( char * ) V_158 -> V_61 . V_108 . V_64 , ( T_2 ) V_158 -> V_61 . V_108 . V_364 ) ;
break;
case V_439 :
V_140 = F_30 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_730 :
V_140 = F_206 ( V_139 , V_158 -> V_61 . V_342 . V_723 , V_158 -> V_61 . V_342 . V_344 ) ;
break;
default:
F_29 ( L_314 , V_158 -> V_60 ) ;
V_140 = - V_189 ;
break;
}
if ( V_140 == 0 && F_131 ( V_39 -> V_453 , V_158 , V_39 -> V_66 ) )
V_140 = - V_454 ;
F_40 ( V_158 ) ;
V_726:
return V_140 ;
}
static T_1 F_208 ( struct V_7 * V_8 , struct V_194 * V_195 )
{
struct V_731 * V_732 ;
struct V_733 * V_734 ;
struct V_735 * V_736 = & V_8 -> V_737 ;
T_1 V_738 = V_225 ;
V_732 = (struct V_731 * ) F_43 ( sizeof( struct V_731 ) ) ;
if ( V_732 == NULL ) {
V_738 = V_188 ;
goto exit;
}
V_734 = (struct V_733 * ) F_43 ( sizeof( struct V_733 ) ) ;
if ( V_734 == NULL ) {
F_40 ( V_732 ) ;
V_738 = V_188 ;
goto exit;
}
F_209 ( V_732 , V_734 , V_739 ) ;
V_734 -> V_740 = ( T_1 ) V_195 -> V_205 ;
memcpy ( V_734 -> V_3 , V_195 -> V_665 , V_23 ) ;
memcpy ( V_734 -> V_172 , & V_195 -> V_206 , 16 ) ;
V_738 = F_210 ( V_736 , V_732 ) ;
exit:
return V_738 ;
}
static int F_211 ( struct V_7 * V_8 , T_1 * V_172 , T_1 V_170 , int V_741 )
{
T_1 V_742 ;
struct V_731 * V_743 ;
struct V_744 * V_745 ;
struct V_735 * V_736 = & ( V_8 -> V_737 ) ;
int V_738 = V_225 ;
F_29 ( L_57 , V_343 ) ;
V_743 = (struct V_731 * ) F_43 ( sizeof( struct V_731 ) ) ;
if ( V_743 == NULL ) {
V_738 = V_188 ;
goto exit;
}
V_745 = (struct V_744 * ) F_43 ( sizeof( struct V_744 ) ) ;
if ( V_745 == NULL ) {
F_40 ( V_743 ) ;
V_738 = V_188 ;
goto exit;
}
F_4 ( V_745 , 0 , sizeof( struct V_744 ) ) ;
V_745 -> V_741 = ( T_1 ) V_741 ;
V_745 -> V_740 = V_170 ;
V_745 -> V_187 = 1 ;
switch ( V_170 ) {
case V_180 :
V_742 = 5 ;
break;
case V_185 :
V_742 = 13 ;
break;
case V_233 :
case V_746 :
case V_235 :
V_742 = 16 ;
default:
V_742 = 16 ;
}
memcpy ( & ( V_745 -> V_172 [ 0 ] ) , V_172 , V_742 ) ;
V_743 -> V_747 = V_748 ;
V_743 -> V_749 = ( T_1 * ) V_745 ;
V_743 -> V_750 = ( sizeof( struct V_744 ) ) ;
V_743 -> V_751 = NULL ;
V_743 -> V_752 = 0 ;
F_212 ( & V_743 -> V_338 ) ;
V_738 = F_210 ( V_736 , V_743 ) ;
exit:
return V_738 ;
}
static int F_213 ( struct V_7 * V_8 , T_1 * V_172 , T_1 V_742 , int V_741 )
{
T_1 V_170 ;
switch ( V_742 ) {
case 5 :
V_170 = V_180 ;
break;
case 13 :
V_170 = V_185 ;
break;
default:
V_170 = V_229 ;
}
return F_211 ( V_8 , V_172 , V_170 , V_741 ) ;
}
static int F_214 ( struct V_138 * V_139 , struct V_157 * V_158 , T_4 V_159 )
{
int V_140 = 0 ;
T_4 V_160 , V_161 , V_162 ;
struct V_163 * V_164 = NULL ;
struct V_194 * V_195 = NULL , * V_196 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_165 * V_166 = & ( V_8 -> V_143 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
F_29 ( L_57 , V_343 ) ;
V_158 -> V_61 . V_168 . V_169 = 0 ;
V_158 -> V_61 . V_168 . V_170 [ V_171 - 1 ] = '\0' ;
if ( V_159 != sizeof( struct V_157 ) + V_158 -> V_61 . V_168 . V_173 ) {
V_140 = - V_156 ;
goto exit;
}
if ( V_158 -> V_174 [ 0 ] == 0xff && V_158 -> V_174 [ 1 ] == 0xff &&
V_158 -> V_174 [ 2 ] == 0xff && V_158 -> V_174 [ 3 ] == 0xff &&
V_158 -> V_174 [ 4 ] == 0xff && V_158 -> V_174 [ 5 ] == 0xff ) {
if ( V_158 -> V_61 . V_168 . V_175 >= V_176 ) {
V_140 = - V_156 ;
goto exit;
}
} else {
V_195 = F_35 ( V_198 , V_158 -> V_174 ) ;
if ( ! V_195 ) {
F_29 ( L_315 ) ;
goto exit;
}
}
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_32 ) == 0 && ( V_195 == NULL ) ) {
F_29 ( L_316 , V_158 -> V_61 . V_168 . V_175 ) ;
goto exit;
}
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_25 ) == 0 && ( V_195 == NULL ) ) {
F_29 ( L_317 ) ;
V_160 = V_158 -> V_61 . V_168 . V_175 ;
V_161 = V_158 -> V_61 . V_168 . V_173 ;
F_29 ( L_318 , V_160 , V_161 ) ;
if ( ( V_160 >= V_176 ) || ( V_161 <= 0 ) ) {
V_140 = - V_156 ;
goto exit;
}
if ( V_161 > 0 ) {
V_161 = V_161 <= 5 ? 5 : 13 ;
V_162 = V_161 + F_31 ( struct V_163 , V_182 ) ;
V_164 = (struct V_163 * ) F_32 ( V_162 ) ;
if ( V_164 == NULL ) {
F_29 ( L_319 ) ;
goto exit;
}
F_4 ( V_164 , 0 , V_162 ) ;
V_164 -> V_183 = V_161 ;
V_164 -> V_184 = V_162 ;
}
V_164 -> V_186 = V_160 ;
memcpy ( V_164 -> V_182 , V_158 -> V_61 . V_168 . V_172 , V_164 -> V_183 ) ;
if ( V_158 -> V_61 . V_168 . V_187 ) {
F_29 ( L_30 ) ;
V_166 -> V_144 = V_145 ;
V_166 -> V_179 = V_180 ;
V_166 -> V_181 = V_180 ;
if ( V_164 -> V_183 == 13 ) {
V_166 -> V_179 = V_185 ;
V_166 -> V_181 = V_185 ;
}
V_166 -> V_415 = V_160 ;
memcpy ( & ( V_166 -> V_190 [ V_160 ] . V_191 [ 0 ] ) , V_164 -> V_182 , V_164 -> V_183 ) ;
V_166 -> V_192 [ V_160 ] = V_164 -> V_183 ;
F_213 ( V_8 , V_164 -> V_182 , V_164 -> V_183 , V_160 ) ;
} else {
F_29 ( L_31 ) ;
memcpy ( & ( V_166 -> V_190 [ V_160 ] . V_191 [ 0 ] ) , V_164 -> V_182 , V_164 -> V_183 ) ;
V_166 -> V_192 [ V_160 ] = V_164 -> V_183 ;
F_213 ( V_8 , V_164 -> V_182 , V_164 -> V_183 , V_160 ) ;
}
goto exit;
}
if ( ! V_195 && F_25 ( V_14 , V_263 ) ) {
if ( V_158 -> V_61 . V_168 . V_187 == 1 ) {
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_25 ) == 0 ) {
F_29 ( L_320 , V_343 ) ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 ,
V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
V_166 -> V_181 = V_180 ;
if ( V_158 -> V_61 . V_168 . V_173 == 13 )
V_166 -> V_181 = V_185 ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_33 ) == 0 ) {
F_29 ( L_321 , V_343 ) ;
V_166 -> V_181 = V_233 ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 ,
V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
memcpy ( V_166 -> V_211 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 16 ] ) , 8 ) ;
memcpy ( V_166 -> V_212 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 24 ] ) , 8 ) ;
V_166 -> V_209 = true ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_89 ) == 0 ) {
F_29 ( L_322 , V_343 ) ;
V_166 -> V_181 = V_235 ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 ,
V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
} else {
F_29 ( L_323 , V_343 ) ;
V_166 -> V_181 = V_229 ;
}
V_166 -> V_214 = V_158 -> V_61 . V_168 . V_175 ;
V_166 -> V_213 = true ;
V_166 -> V_179 = V_166 -> V_181 ;
F_211 ( V_8 , V_158 -> V_61 . V_168 . V_172 , V_166 -> V_181 , V_158 -> V_61 . V_168 . V_175 ) ;
V_196 = F_39 ( V_8 ) ;
if ( V_196 ) {
V_196 -> V_202 = false ;
V_196 -> V_205 = V_166 -> V_181 ;
}
}
goto exit;
}
if ( V_166 -> V_148 == V_193 && V_195 ) {
if ( F_25 ( V_14 , V_263 ) ) {
if ( V_158 -> V_61 . V_168 . V_187 == 1 ) {
memcpy ( V_195 -> V_206 . V_191 , V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_25 ) == 0 ) {
F_29 ( L_324 , V_343 ) ;
V_195 -> V_205 = V_180 ;
if ( V_158 -> V_61 . V_168 . V_173 == 13 )
V_195 -> V_205 = V_185 ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_33 ) == 0 ) {
F_29 ( L_325 , V_343 ) ;
V_195 -> V_205 = V_233 ;
memcpy ( V_195 -> V_207 . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 16 ] ) , 8 ) ;
memcpy ( V_195 -> V_208 . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 24 ] ) , 8 ) ;
V_166 -> V_209 = true ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_89 ) == 0 ) {
F_29 ( L_326 , V_343 ) ;
V_195 -> V_205 = V_235 ;
} else {
F_29 ( L_327 , V_343 ) ;
V_195 -> V_205 = V_229 ;
}
F_208 ( V_8 , V_195 ) ;
V_195 -> V_202 = false ;
} else {
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_25 ) == 0 ) {
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 ,
V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
V_166 -> V_181 = V_180 ;
if ( V_158 -> V_61 . V_168 . V_173 == 13 )
V_166 -> V_181 = V_185 ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_33 ) == 0 ) {
V_166 -> V_181 = V_233 ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 ,
V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
memcpy ( V_166 -> V_211 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 16 ] ) , 8 ) ;
memcpy ( V_166 -> V_212 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 24 ] ) , 8 ) ;
V_166 -> V_209 = true ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_89 ) == 0 ) {
V_166 -> V_181 = V_235 ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 ,
V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
} else {
V_166 -> V_181 = V_229 ;
}
V_166 -> V_214 = V_158 -> V_61 . V_168 . V_175 ;
V_166 -> V_213 = true ;
V_166 -> V_179 = V_166 -> V_181 ;
F_211 ( V_8 , V_158 -> V_61 . V_168 . V_172 , V_166 -> V_181 , V_158 -> V_61 . V_168 . V_175 ) ;
V_196 = F_39 ( V_8 ) ;
if ( V_196 ) {
V_196 -> V_202 = false ;
V_196 -> V_205 = V_166 -> V_181 ;
}
}
}
}
exit:
F_40 ( V_164 ) ;
return V_140 ;
}
static int F_215 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_364 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
unsigned char * V_504 = V_158 -> V_61 . V_753 . V_106 ;
F_29 ( L_328 , V_343 , V_364 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
memcpy ( & V_198 -> V_754 , V_158 -> V_61 . V_753 . V_755 , 2 ) ;
if ( ( V_198 -> V_754 > V_693 ) || ( V_198 -> V_754 <= 0 ) )
V_198 -> V_754 = V_693 ;
if ( F_216 ( V_8 , V_504 , ( V_364 - 12 - 2 ) ) == V_225 )
V_140 = 0 ;
else
V_140 = - V_156 ;
return V_140 ;
}
static int F_217 ( struct V_138 * V_139 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_57 , V_343 ) ;
F_218 ( V_8 ) ;
V_140 = F_219 ( V_8 ) ;
return V_140 ;
}
static int F_220 ( struct V_138 * V_139 , struct V_157 * V_158 )
{
int V_140 = 0 ;
struct V_194 * V_195 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
F_29 ( L_329 , V_158 -> V_61 . V_756 . V_668 , ( V_158 -> V_174 ) ) ;
if ( ! F_25 ( V_14 , ( V_128 | V_263 ) ) )
return - V_156 ;
if ( V_158 -> V_174 [ 0 ] == 0xff && V_158 -> V_174 [ 1 ] == 0xff &&
V_158 -> V_174 [ 2 ] == 0xff && V_158 -> V_174 [ 3 ] == 0xff &&
V_158 -> V_174 [ 4 ] == 0xff && V_158 -> V_174 [ 5 ] == 0xff )
return - V_156 ;
V_195 = F_35 ( V_198 , V_158 -> V_174 ) ;
if ( V_195 ) {
int V_65 = V_158 -> V_61 . V_756 . V_65 ;
V_195 -> V_668 = V_158 -> V_61 . V_756 . V_668 ;
memcpy ( V_195 -> V_757 , V_158 -> V_61 . V_756 . V_758 , 16 ) ;
if ( V_759 & V_65 )
V_195 -> V_660 = 1 ;
else
V_195 -> V_660 = 0 ;
if ( V_14 -> V_659 . V_660 == 0 )
V_195 -> V_660 = 0 ;
if ( V_760 & V_65 ) {
V_195 -> V_661 . V_662 = true ;
V_195 -> V_660 = 1 ;
memcpy ( ( void * ) & V_195 -> V_661 . V_42 , ( void * ) & V_158 -> V_61 . V_756 . V_42 , sizeof( struct V_69 ) ) ;
} else {
V_195 -> V_661 . V_662 = false ;
}
if ( V_14 -> V_661 . V_662 == false )
V_195 -> V_661 . V_662 = false ;
F_221 ( V_8 , V_195 ) ;
} else {
V_140 = - V_223 ;
}
return V_140 ;
}
static int F_222 ( struct V_138 * V_139 , struct V_157 * V_158 )
{
unsigned long V_323 ;
int V_140 = 0 ;
struct V_194 * V_195 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
int V_124 = 0 ;
F_29 ( L_330 , ( V_158 -> V_174 ) ) ;
if ( F_25 ( V_14 , ( V_128 | V_263 ) ) != true )
return - V_156 ;
if ( V_158 -> V_174 [ 0 ] == 0xff && V_158 -> V_174 [ 1 ] == 0xff &&
V_158 -> V_174 [ 2 ] == 0xff && V_158 -> V_174 [ 3 ] == 0xff &&
V_158 -> V_174 [ 4 ] == 0xff && V_158 -> V_174 [ 5 ] == 0xff )
return - V_156 ;
V_195 = F_35 ( V_198 , V_158 -> V_174 ) ;
if ( V_195 ) {
F_59 ( & V_198 -> V_761 , & V_323 ) ;
if ( ! F_223 ( & V_195 -> V_762 ) ) {
F_224 ( & V_195 -> V_762 ) ;
V_198 -> V_763 -- ;
V_124 = F_225 ( V_8 , V_195 , true , V_764 ) ;
}
F_64 ( & V_198 -> V_761 , & V_323 ) ;
F_226 ( V_8 , V_124 ) ;
V_195 = NULL ;
} else {
F_29 ( L_331 ) ;
}
return V_140 ;
}
static int F_227 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_364 )
{
int V_140 = 0 ;
struct V_194 * V_195 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
struct V_765 * V_766 = (struct V_765 * ) V_158 ;
struct V_767 * V_768 = (struct V_767 * ) V_766 -> V_64 ;
F_29 ( L_332 , ( V_766 -> V_174 ) ) ;
if ( F_25 ( V_14 , ( V_128 | V_263 ) ) != true )
return - V_156 ;
if ( V_766 -> V_174 [ 0 ] == 0xff && V_766 -> V_174 [ 1 ] == 0xff &&
V_766 -> V_174 [ 2 ] == 0xff && V_766 -> V_174 [ 3 ] == 0xff &&
V_766 -> V_174 [ 4 ] == 0xff && V_766 -> V_174 [ 5 ] == 0xff )
return - V_156 ;
V_195 = F_35 ( V_198 , V_766 -> V_174 ) ;
if ( V_195 ) {
V_768 -> V_668 = ( T_2 ) V_195 -> V_668 ;
V_768 -> V_696 = V_195 -> V_696 ;
V_768 -> V_65 = V_195 -> V_65 ;
V_768 -> V_769 = ( ( V_195 -> V_770 ) |
( V_195 -> V_771 << 1 ) |
( V_195 -> V_772 << 2 ) |
( V_195 -> V_773 << 3 ) |
( V_195 -> V_774 << 4 ) |
( V_195 -> V_775 << 5 ) ) ;
V_768 -> V_776 = V_195 -> V_777 ;
memcpy ( V_768 -> V_758 , V_195 -> V_757 , V_195 -> V_777 ) ;
memcpy ( & V_768 -> V_42 , & V_195 -> V_661 . V_42 , sizeof( struct V_69 ) ) ;
V_768 -> V_778 = V_195 -> V_779 . V_780 ;
V_768 -> V_781 = V_195 -> V_779 . V_781 ;
V_768 -> V_782 = V_195 -> V_779 . V_782 ;
V_768 -> V_783 = V_195 -> V_779 . V_783 ;
V_768 -> V_784 = V_195 -> V_779 . V_784 ;
V_768 -> V_785 = V_195 -> V_779 . V_785 ;
} else {
V_140 = - 1 ;
}
return V_140 ;
}
static int F_228 ( struct V_138 * V_139 , struct V_157 * V_158 )
{
int V_140 = 0 ;
struct V_194 * V_195 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
F_29 ( L_333 , ( V_158 -> V_174 ) ) ;
if ( F_25 ( V_14 , ( V_128 | V_263 ) ) != true )
return - V_156 ;
if ( V_158 -> V_174 [ 0 ] == 0xff && V_158 -> V_174 [ 1 ] == 0xff &&
V_158 -> V_174 [ 2 ] == 0xff && V_158 -> V_174 [ 3 ] == 0xff &&
V_158 -> V_174 [ 4 ] == 0xff && V_158 -> V_174 [ 5 ] == 0xff )
return - V_156 ;
V_195 = F_35 ( V_198 , V_158 -> V_174 ) ;
if ( V_195 ) {
if ( ( V_195 -> V_108 [ 0 ] == V_786 ) || ( V_195 -> V_108 [ 0 ] == V_787 ) ) {
int V_788 ;
int V_789 ;
V_788 = V_195 -> V_108 [ 1 ] ;
V_789 = ( ( V_788 + 2 ) > sizeof( V_195 -> V_108 ) ) ? ( sizeof( V_195 -> V_108 ) ) : ( V_788 + 2 ) ;
V_158 -> V_61 . V_108 . V_364 = V_789 ;
memcpy ( V_158 -> V_61 . V_108 . V_755 , V_195 -> V_108 , V_789 ) ;
} else {
F_29 ( L_334 ) ;
}
} else {
V_140 = - 1 ;
}
return V_140 ;
}
static int F_229 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_364 )
{
int V_140 = 0 ;
unsigned char V_238 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_286 * V_287 = & ( V_8 -> V_249 ) ;
int V_790 ;
F_29 ( L_328 , V_343 , V_364 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
V_790 = V_364 - 12 - 2 ;
if ( V_14 -> V_791 ) {
F_40 ( V_14 -> V_791 ) ;
V_14 -> V_791 = NULL ;
}
if ( V_790 > 0 ) {
V_14 -> V_791 = F_32 ( V_790 ) ;
V_14 -> V_792 = V_790 ;
if ( V_14 -> V_791 == NULL ) {
F_29 ( L_335 , V_343 , __LINE__ ) ;
return - V_156 ;
}
memcpy ( V_14 -> V_791 , V_158 -> V_61 . V_753 . V_106 , V_790 ) ;
F_230 ( V_8 , V_239 , V_238 , true ) ;
V_287 -> V_793 = true ;
}
return V_140 ;
}
static int F_231 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_364 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
int V_790 ;
F_29 ( L_328 , V_343 , V_364 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
V_790 = V_364 - 12 - 2 ;
if ( V_14 -> V_794 ) {
F_40 ( V_14 -> V_794 ) ;
V_14 -> V_794 = NULL ;
}
if ( V_790 > 0 ) {
V_14 -> V_794 = F_32 ( V_790 ) ;
V_14 -> V_795 = V_790 ;
if ( V_14 -> V_794 == NULL ) {
F_29 ( L_335 , V_343 , __LINE__ ) ;
return - V_156 ;
}
memcpy ( V_14 -> V_794 , V_158 -> V_61 . V_753 . V_106 , V_790 ) ;
}
return V_140 ;
}
static int F_232 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_364 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
int V_790 ;
F_29 ( L_328 , V_343 , V_364 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
V_790 = V_364 - 12 - 2 ;
if ( V_14 -> V_796 ) {
F_40 ( V_14 -> V_796 ) ;
V_14 -> V_796 = NULL ;
}
if ( V_790 > 0 ) {
V_14 -> V_796 = F_32 ( V_790 ) ;
V_14 -> V_797 = V_790 ;
if ( V_14 -> V_796 == NULL ) {
F_29 ( L_335 , V_343 , __LINE__ ) ;
return - V_156 ;
}
memcpy ( V_14 -> V_796 , V_158 -> V_61 . V_753 . V_106 , V_790 ) ;
}
return V_140 ;
}
static int F_233 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_364 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_286 * V_287 = & ( V_8 -> V_249 ) ;
struct V_642 * V_643 = & ( V_287 -> V_644 ) ;
T_1 V_104 ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
if ( V_158 -> V_61 . V_728 . V_78 != 0 )
F_29 ( L_336 , V_343 , V_158 -> V_61 . V_728 . V_78 ) ;
V_104 = V_158 -> V_61 . V_728 . V_104 ;
if ( V_104 != 1 && V_104 != 2 )
V_104 = 0 ;
F_29 ( L_337 , V_343 , V_104 ) ;
V_643 -> V_798 = V_104 ;
return V_140 ;
}
static int F_234 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_364 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
if ( V_158 -> V_174 [ 0 ] == 0xff && V_158 -> V_174 [ 1 ] == 0xff &&
V_158 -> V_174 [ 2 ] == 0xff && V_158 -> V_174 [ 3 ] == 0xff &&
V_158 -> V_174 [ 4 ] == 0xff && V_158 -> V_174 [ 5 ] == 0xff )
return - V_156 ;
V_140 = F_235 ( V_8 , V_158 -> V_174 ) ;
return V_140 ;
}
static int F_236 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_364 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
if ( V_158 -> V_174 [ 0 ] == 0xff && V_158 -> V_174 [ 1 ] == 0xff &&
V_158 -> V_174 [ 2 ] == 0xff && V_158 -> V_174 [ 3 ] == 0xff &&
V_158 -> V_174 [ 4 ] == 0xff && V_158 -> V_174 [ 5 ] == 0xff )
return - V_156 ;
V_140 = F_237 ( V_8 , V_158 -> V_174 ) ;
return V_140 ;
}
static int F_238 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_364 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
F_239 ( V_8 , V_158 -> V_61 . V_342 . V_723 ) ;
return V_140 ;
}
static int F_240 ( struct V_138 * V_139 , struct V_409 * V_39 )
{
struct V_157 * V_158 ;
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
if ( ! V_8 -> V_254 ) {
V_140 = - V_253 ;
goto V_726;
}
if ( ! V_39 -> V_453 ) {
V_140 = - V_156 ;
goto V_726;
}
V_158 = (struct V_157 * ) F_32 ( V_39 -> V_66 ) ;
if ( V_158 == NULL ) {
V_140 = - V_223 ;
goto V_726;
}
if ( F_106 ( V_158 , V_39 -> V_453 , V_39 -> V_66 ) ) {
F_40 ( V_158 ) ;
V_140 = - V_454 ;
goto V_726;
}
switch ( V_158 -> V_60 ) {
case V_799 :
V_140 = F_217 ( V_139 ) ;
break;
case V_800 :
V_140 = F_220 ( V_139 , V_158 ) ;
break;
case V_801 :
V_140 = F_222 ( V_139 , V_158 ) ;
break;
case V_802 :
V_140 = F_215 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_803 :
V_140 = F_214 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_804 :
V_140 = F_228 ( V_139 , V_158 ) ;
break;
case V_805 :
V_140 = F_229 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_806 :
V_140 = F_231 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_807 :
V_140 = F_232 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_808 :
V_140 = F_233 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_809 :
V_140 = F_227 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_810 :
V_140 = F_238 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_811 :
V_140 = F_236 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_812 :
V_140 = F_234 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
default:
F_29 ( L_338 , V_158 -> V_60 ) ;
V_140 = - V_189 ;
break;
}
if ( V_140 == 0 && F_131 ( V_39 -> V_453 , V_158 , V_39 -> V_66 ) )
V_140 = - V_454 ;
F_40 ( V_158 ) ;
V_726:
return V_140 ;
}
static int F_241 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_322 ,
char * V_243 )
{
int V_140 = 0 ;
int V_364 = 0 ;
char * V_813 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_409 * V_814 = (struct V_409 * ) V_322 ;
if ( V_814 -> V_66 == 0 )
return - V_454 ;
V_364 = V_814 -> V_66 ;
V_813 = F_242 ( V_364 ) ;
if ( ! V_813 )
return - V_223 ;
if ( F_106 ( V_813 , V_814 -> V_453 , V_364 ) ) {
F_243 ( V_813 , V_364 ) ;
return - V_454 ;
}
if ( V_814 -> V_65 == 0x8766 && V_364 > 8 ) {
T_4 V_815 ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
T_1 * V_816 = V_813 ;
int V_817 = V_364 ;
T_1 V_238 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
if ( ( V_239 == V_816 [ 0 ] ) &&
( ! memcmp ( & V_816 [ 2 ] , V_238 , 4 ) ) ) {
V_815 = V_817 > V_818 ? V_818 : V_817 ;
V_14 -> V_819 = 0 ;
F_40 ( V_14 -> V_820 ) ;
V_14 -> V_820 = NULL ;
V_14 -> V_820 = F_32 ( V_815 ) ;
if ( V_14 -> V_820 == NULL ) {
F_172 ( L_335 , V_343 , __LINE__ ) ;
V_140 = - V_156 ;
goto V_821;
}
memcpy ( V_14 -> V_820 , V_816 , V_815 ) ;
V_14 -> V_819 = V_815 ;
}
goto V_821;
}
if ( V_364 >= V_370 &&
! memcmp ( V_813 , V_371 , V_370 ) ) {
V_140 = F_70 ( V_139 , V_27 , V_322 , V_813 ) ;
goto V_821;
}
V_821:
F_243 ( V_813 , V_364 ) ;
return V_140 ;
}
static int F_244 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
unsigned V_86 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_156 , V_343 , V_243 ) ;
if ( ! memcmp ( V_243 , L_339 , 4 ) ) {
sscanf ( V_243 + 4 , L_340 , & V_86 ) ;
V_140 = F_245 ( V_8 , V_86 ) ;
} else if ( ! memcmp ( V_243 , L_341 , 4 ) ) {
sscanf ( V_243 + 4 , L_340 , & V_86 ) ;
V_140 = F_246 ( V_8 , V_86 ) ;
} else {
V_140 = - V_156 ;
}
return V_140 ;
}
static int F_247 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_822 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
struct V_823 * V_824 = F_248 ( V_8 ) ;
struct V_825 * V_826 = F_249 ( V_8 ) ;
struct V_827 * V_828 ;
struct V_409 * V_10 ;
T_1 * V_829 = V_824 -> V_830 ;
T_1 V_831 = 0 , V_832 = 0 ;
struct V_412 * V_386 ;
T_1 * V_64 = NULL ;
T_1 * V_833 = NULL ;
char * V_834 , * V_452 , * V_597 , * V_835 [ 3 ] = { NULL , NULL , NULL } ;
T_2 V_4 = 0 , V_264 = 0 , V_836 = 0 , V_3 = 0 , V_837 = 0 ;
T_2 V_838 = 0 , V_839 = 0 , V_840 = 0 ;
int V_169 ;
T_1 V_841 = V_8 -> V_351 . V_842 ;
V_10 = (struct V_409 * ) V_822 ;
V_386 = & V_8 -> V_386 ;
V_828 = & V_826 -> V_843 ;
V_169 = 0 ;
V_64 = F_250 ( V_844 ) ;
if ( V_64 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_833 = F_250 ( V_844 ) ;
if ( V_833 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
if ( F_106 ( V_243 , V_10 -> V_453 , V_10 -> V_66 ) ) {
V_169 = - V_454 ;
goto exit;
}
V_832 = V_386 -> V_845 ;
F_245 ( V_8 , V_846 ) ;
V_831 = V_386 -> V_831 ;
F_246 ( V_8 , V_847 ) ;
V_834 = V_243 ;
F_29 ( L_342 , V_343 , V_243 ) ;
V_4 = 0 ;
while ( ( V_597 = F_251 ( & V_834 , L_343 ) ) != NULL ) {
if ( V_4 > 2 )
break;
V_835 [ V_4 ] = V_597 ;
V_4 ++ ;
}
V_8 -> V_351 . V_842 = 0 ;
if ( strcmp ( V_835 [ 0 ] , L_169 ) == 0 ) {
sprintf ( V_243 , L_344 , ( V_824 -> V_848 ? L_345 : L_346 ) , ( V_824 -> V_849 ? L_345 : L_346 ) ) ;
goto exit;
} else if ( strcmp ( V_835 [ 0 ] , L_347 ) == 0 ) {
V_836 = V_850 ;
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_850 ; V_4 += 16 ) {
sprintf ( V_243 , L_348 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_829 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_829 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_351 ) == 0 ) {
V_836 = V_850 ;
if ( F_252 ( V_8 , 0 , V_836 , V_828 -> V_851 ) == V_188 ) {
F_29 ( L_352 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_850 ; V_4 += 16 ) {
sprintf ( V_243 , L_348 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_851 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_851 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_353 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
F_29 ( L_354 , V_343 ) ;
V_169 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_452 , 16 ) ;
F_29 ( L_355 , V_343 , V_3 ) ;
V_837 = F_253 ( V_835 [ 2 ] , & V_452 , 10 ) ;
if ( V_837 == 0 ) {
F_29 ( L_356 , V_343 ) ;
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_357 , V_343 , V_837 ) ;
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_343 , V_3 , V_837 ) ;
V_169 = - V_156 ;
goto exit;
}
if ( F_252 ( V_8 , V_3 , V_837 , V_64 ) == V_188 ) {
F_29 ( L_359 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
* V_243 = 0 ;
for ( V_4 = 0 ; V_4 < V_837 ; V_4 ++ )
sprintf ( V_243 , L_360 , V_243 , V_64 [ V_4 ] ) ;
} else if ( strcmp ( V_835 [ 0 ] , L_361 ) == 0 ) {
V_3 = 0 ;
V_836 = V_854 ;
if ( F_255 ( V_8 , false , V_3 , V_836 , V_833 ) == V_188 ) {
F_29 ( L_362 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_836 ; V_4 ++ ) {
sprintf ( V_243 , L_363 , V_243 , V_833 [ V_4 ] ) ;
if ( ( V_4 & 0xF ) == 0xF )
sprintf ( V_243 , L_57 , V_243 ) ;
else if ( ( V_4 & 0x7 ) == 0x7 )
sprintf ( V_243 , L_350 , V_243 ) ;
else
sprintf ( V_243 , L_364 , V_243 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_365 ) == 0 ) {
V_837 = 6 ;
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_366 , V_343 , V_3 , V_837 ) ;
V_169 = - V_454 ;
goto exit;
}
if ( F_252 ( V_8 , V_3 , V_837 , V_64 ) == V_188 ) {
F_29 ( L_359 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
* V_243 = 0 ;
for ( V_4 = 0 ; V_4 < V_837 ; V_4 ++ ) {
sprintf ( V_243 , L_363 , V_243 , V_64 [ V_4 ] ) ;
if ( V_4 != ( V_837 - 1 ) )
sprintf ( V_243 , L_367 , V_243 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_368 ) == 0 ) {
V_837 = 4 ;
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_366 , V_343 , V_3 , V_837 ) ;
V_169 = - V_454 ;
goto exit;
}
if ( F_252 ( V_8 , V_3 , V_837 , V_64 ) == V_188 ) {
F_29 ( L_369 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
* V_243 = 0 ;
for ( V_4 = 0 ; V_4 < V_837 ; V_4 ++ ) {
sprintf ( V_243 , L_370 , V_243 , V_64 [ V_4 ] ) ;
if ( V_4 != ( V_837 - 1 ) )
sprintf ( V_243 , L_371 , V_243 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_372 ) == 0 ) {
F_256 ( V_8 , & V_839 ) ;
V_840 = F_257 ( V_8 ) ;
sprintf ( V_243 , L_373 , V_840 - V_839 ) ;
} else if ( strcmp ( V_835 [ 0 ] , L_374 ) == 0 ) {
V_836 = V_844 ;
if ( F_258 ( V_8 , 0 , V_836 , V_828 -> V_855 ) == V_188 ) {
F_29 ( L_375 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < 512 ; V_4 += 16 ) {
sprintf ( V_243 , L_376 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_855 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_855 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_377 ) == 0 ) {
V_836 = V_844 ;
if ( F_258 ( V_8 , 0 , V_836 , V_828 -> V_855 ) == V_188 ) {
F_29 ( L_375 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 512 ; V_4 < 1024 ; V_4 += 16 ) {
sprintf ( V_243 , L_376 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_855 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_855 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_378 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_452 , 16 ) ;
F_29 ( L_379 , V_343 , V_3 ) ;
V_837 = F_253 ( V_835 [ 2 ] , & V_452 , 10 ) ;
if ( V_837 == 0 ) {
F_29 ( L_380 , V_343 ) ;
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_357 , V_343 , V_837 ) ;
F_254 ( V_8 , V_856 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_343 , V_3 , V_837 ) ;
V_169 = - V_454 ;
goto exit;
}
if ( F_258 ( V_8 , V_3 , V_837 , V_64 ) == V_188 ) {
F_29 ( L_381 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
* V_243 = 0 ;
for ( V_4 = 0 ; V_4 < V_837 ; V_4 ++ )
sprintf ( V_243 , L_382 , V_243 , V_64 [ V_4 ] ) ;
} else if ( strcmp ( V_835 [ 0 ] , L_383 ) == 0 ) {
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < 512 ; V_4 += 16 ) {
sprintf ( V_243 , L_376 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_857 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_857 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_384 ) == 0 ) {
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 512 ; V_4 < 1024 ; V_4 += 16 ) {
sprintf ( V_243 , L_376 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_857 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_857 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_385 ) == 0 ) {
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_850 ; V_4 += 16 ) {
sprintf ( V_243 , L_348 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_828 -> V_858 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_386 , V_243 , V_828 -> V_858 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else {
sprintf ( V_243 , L_387 ) ;
}
exit:
F_40 ( V_64 ) ;
F_40 ( V_833 ) ;
if ( ! V_169 )
V_10 -> V_66 = strlen ( V_243 ) ;
F_246 ( V_8 , V_831 ) ;
F_245 ( V_8 , V_832 ) ;
V_8 -> V_351 . V_842 = V_841 ;
return V_169 ;
}
static int F_259 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_822 , char * V_243 )
{
struct V_7 * V_8 ;
struct V_412 * V_386 ;
struct V_825 * V_826 ;
struct V_827 * V_828 ;
T_1 V_831 = 0 , V_832 = 0 ;
T_4 V_4 , V_537 , V_538 ;
T_1 * V_859 = NULL ;
T_1 * V_860 = NULL ;
T_1 * V_861 = NULL ;
T_1 * V_862 = NULL ;
char * V_834 , * V_452 , * V_597 , * V_835 [ 3 ] = { NULL , NULL , NULL } ;
T_2 V_3 = 0 , V_837 = 0 , V_838 = 0 ;
int V_169 ;
V_8 = F_28 ( V_139 ) ;
V_386 = & V_8 -> V_386 ;
V_826 = F_249 ( V_8 ) ;
V_828 = & V_826 -> V_843 ;
V_169 = 0 ;
V_859 = F_250 ( 1024 ) ;
if ( V_859 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_860 = F_260 ( V_844 ) ;
if ( V_860 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_861 = F_260 ( V_850 ) ;
if ( V_861 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_862 = F_260 ( V_854 ) ;
if ( V_862 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_832 = V_386 -> V_845 ;
F_245 ( V_8 , V_846 ) ;
V_831 = V_386 -> V_831 ;
F_246 ( V_8 , V_847 ) ;
V_834 = V_243 ;
F_29 ( L_342 , V_343 , V_243 ) ;
V_4 = 0 ;
while ( ( V_597 = F_251 ( & V_834 , L_343 ) ) != NULL ) {
if ( V_4 > 2 )
break;
V_835 [ V_4 ] = V_597 ;
V_4 ++ ;
}
if ( strcmp ( V_835 [ 0 ] , L_388 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_452 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_343 , V_3 ) ;
F_29 ( L_357 , V_343 , V_837 ) ;
F_29 ( L_389 , V_343 , V_835 [ 2 ] ) ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_837 ; V_537 ++ , V_538 += 2 )
V_859 [ V_537 ] = F_147 ( V_835 [ 2 ] [ V_538 ] , V_835 [ 2 ] [ V_538 + 1 ] ) ;
F_254 ( V_8 , V_852 , V_863 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_343 , V_3 , V_837 ) ;
V_169 = - V_454 ;
goto exit;
}
if ( F_261 ( V_8 , V_3 , V_837 , V_859 ) == V_188 ) {
F_29 ( L_390 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_391 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_452 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_343 , V_3 ) ;
F_29 ( L_357 , V_343 , V_837 ) ;
F_29 ( L_392 , V_343 , V_835 [ 2 ] ) ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_837 ; V_537 ++ , V_538 += 2 )
V_862 [ V_537 ] = F_147 ( V_835 [ 2 ] [ V_538 ] , V_835 [ 2 ] [ V_538 + 1 ] ) ;
if ( F_255 ( V_8 , true , V_3 , V_837 , V_862 ) == V_188 ) {
F_29 ( L_369 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_365 ) == 0 ) {
if ( V_835 [ 1 ] == NULL ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = V_864 ;
V_837 = strlen ( V_835 [ 1 ] ) ;
if ( V_837 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
if ( V_837 > 6 ) {
F_29 ( L_393 , V_343 , V_835 [ 1 ] ) ;
V_169 = - V_454 ;
goto exit;
}
F_29 ( L_379 , V_343 , V_3 ) ;
F_29 ( L_357 , V_343 , V_837 ) ;
F_29 ( L_394 , V_343 , V_835 [ 1 ] ) ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_837 ; V_537 ++ , V_538 += 2 )
V_859 [ V_537 ] = F_147 ( V_835 [ 1 ] [ V_538 ] , V_835 [ 1 ] [ V_538 + 1 ] ) ;
F_254 ( V_8 , V_852 , V_863 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_343 , V_3 , V_837 ) ;
V_169 = - V_454 ;
goto exit;
}
if ( F_261 ( V_8 , V_3 , V_837 , V_859 ) == V_188 ) {
F_29 ( L_390 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_368 ) == 0 ) {
if ( V_835 [ 1 ] == NULL ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = V_865 ;
V_837 = strlen ( V_835 [ 1 ] ) ;
if ( V_837 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_343 , V_3 ) ;
F_29 ( L_357 , V_343 , V_837 ) ;
F_29 ( L_395 , V_343 , V_835 [ 1 ] ) ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_837 ; V_537 ++ , V_538 += 2 )
V_859 [ V_537 ] = F_147 ( V_835 [ 1 ] [ V_538 ] , V_835 [ 1 ] [ V_538 + 1 ] ) ;
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_343 , V_3 , V_837 ) ;
V_169 = - V_454 ;
goto exit;
}
if ( F_261 ( V_8 , V_3 , V_837 , V_859 ) == V_188 ) {
F_29 ( L_390 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_396 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_452 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_343 , V_3 ) ;
F_29 ( L_357 , V_343 , V_837 ) ;
F_29 ( L_397 , V_343 , V_835 [ 2 ] ) ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_837 ; V_537 ++ , V_538 += 2 )
V_859 [ V_537 ] = F_147 ( V_835 [ 2 ] [ V_538 ] , V_835 [ 2 ] [ V_538 + 1 ] ) ;
F_254 ( V_8 , V_856 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_343 , V_3 , V_837 ) ;
V_169 = - V_454 ;
goto exit;
}
if ( F_262 ( V_8 , V_3 , V_837 , V_859 ) == V_188 ) {
F_29 ( L_398 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_399 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_452 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_343 , V_3 ) ;
F_29 ( L_357 , V_343 , V_837 ) ;
F_29 ( L_400 , V_343 , V_835 [ 2 ] ) ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_837 ; V_537 ++ , V_538 += 2 )
V_828 -> V_857 [ V_3 + V_537 ] = F_147 ( V_835 [ 2 ] [ V_538 ] , V_835 [ 2 ] [ V_538 + 1 ] ) ;
} else if ( strcmp ( V_835 [ 0 ] , L_401 ) == 0 ) {
if ( F_258 ( V_8 , 0 , V_844 , V_828 -> V_857 ) == V_225 ) {
F_29 ( L_402 , V_343 ) ;
} else {
F_29 ( L_403 , V_343 ) ;
V_169 = - V_454 ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_404 ) == 0 ) {
if ( F_252 ( V_8 , 0 , V_844 , V_828 -> V_858 ) == V_225 ) {
F_29 ( L_402 , V_343 ) ;
} else {
F_29 ( L_405 , V_343 ) ;
V_169 = - V_454 ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_406 ) == 0 ) {
memcpy ( V_828 -> V_866 , V_828 -> V_857 , V_844 ) ;
F_254 ( V_8 , V_856 , V_853 , ( void * ) & V_838 , false ) ;
if ( V_838 < 1 ) {
V_169 = - V_454 ;
goto exit;
}
if ( F_262 ( V_8 , 0x00 , V_844 , V_828 -> V_857 ) == V_188 ) {
F_29 ( L_407 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_408 ) == 0 ) {
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( V_838 < 1 ) {
V_169 = - V_454 ;
goto exit;
}
if ( F_261 ( V_8 , 0x00 , V_867 , V_828 -> V_858 ) == V_188 ) {
F_29 ( L_409 , V_343 ) ;
V_169 = - V_454 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_410 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_452 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_343 , V_3 ) ;
F_29 ( L_357 , V_343 , V_837 ) ;
F_29 ( L_411 , V_343 , V_835 [ 2 ] ) ;
for ( V_537 = 0 , V_538 = 0 ; V_537 < V_837 ; V_537 ++ , V_538 += 2 )
V_828 -> V_858 [ V_3 + V_537 ] = F_147 ( V_835 [ 2 ] [ V_538 ] , V_835 [ 2 ] [ V_538 + 1 ] ) ;
}
exit:
F_40 ( V_859 ) ;
F_40 ( V_860 ) ;
F_40 ( V_861 ) ;
F_40 ( V_862 ) ;
F_246 ( V_8 , V_831 ) ;
F_245 ( V_8 , V_832 ) ;
return V_169 ;
}
static int F_263 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
char * V_834 , * V_868 , * V_452 ;
char * V_869 ;
char V_468 ;
T_4 V_3 , V_64 ;
int V_140 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_834 = V_243 ;
V_868 = strpbrk ( V_834 , L_412 ) ;
if ( V_868 == NULL )
return - V_156 ;
* V_868 = 0 ;
V_869 = V_834 ;
V_834 = V_868 + 1 ;
V_868 = strpbrk ( V_834 , L_412 ) ;
if ( V_868 == NULL )
return - V_156 ;
* V_868 = 0 ;
V_3 = F_253 ( V_834 , & V_452 , 16 ) ;
if ( V_3 > 0x3FFF )
return - V_156 ;
V_834 = V_868 + 1 ;
if ( ( V_834 - V_243 ) >= V_10 -> V_66 )
return - V_156 ;
V_64 = F_253 ( V_834 , & V_452 , 16 ) ;
V_140 = 0 ;
V_468 = V_869 [ 0 ] ;
switch ( V_468 ) {
case 'b' :
if ( V_64 > 0xFF ) {
V_140 = - V_156 ;
break;
}
F_111 ( V_8 , V_3 , V_64 ) ;
break;
case 'w' :
if ( V_64 > 0xFFFF ) {
V_140 = - V_156 ;
break;
}
F_112 ( V_8 , V_3 , V_64 ) ;
break;
case 'd' :
F_113 ( V_8 , V_3 , V_64 ) ;
break;
default:
V_140 = - V_156 ;
break;
}
return V_140 ;
}
static int F_264 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
char * V_834 , * V_868 , * V_452 ;
char * V_869 ;
char V_468 ;
char V_64 [ 20 ] , V_835 [ 20 ] ;
T_4 V_3 ;
T_4 V_140 , V_4 = 0 , V_264 = 0 , V_872 = 0 ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
F_4 ( V_64 , 0 , 20 ) ;
F_4 ( V_835 , 0 , 20 ) ;
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
V_834 = V_870 ;
V_868 = strpbrk ( V_834 , L_412 ) ;
if ( V_868 == NULL ) {
F_40 ( V_870 ) ;
return - V_156 ;
}
* V_868 = 0 ;
V_869 = V_834 ;
V_834 = V_868 + 1 ;
if ( ( V_834 - V_870 ) >= V_10 -> V_66 ) {
F_40 ( V_870 ) ;
return - V_156 ;
}
F_40 ( V_870 ) ;
V_3 = F_253 ( V_834 , & V_452 , 16 ) ;
if ( V_3 > 0x3FFF )
return - V_156 ;
V_140 = 0 ;
V_468 = V_869 [ 0 ] ;
switch ( V_468 ) {
case 'b' :
sprintf ( V_243 , L_413 , F_107 ( V_8 , V_3 ) ) ;
V_10 -> V_66 = strlen ( V_243 ) ;
break;
case 'w' :
sprintf ( V_64 , L_414 , F_108 ( V_8 , V_3 ) ) ;
for ( V_4 = 0 ; V_4 <= strlen ( V_64 ) ; V_4 ++ ) {
if ( V_4 % 2 == 0 ) {
V_835 [ V_264 ] = ' ' ;
V_264 ++ ;
}
if ( V_64 [ V_4 ] != '\0' )
V_835 [ V_264 ] = V_64 [ V_4 ] ;
V_264 ++ ;
}
V_834 = V_835 ;
F_29 ( L_415 , V_834 ) ;
while ( * V_834 != '\0' ) {
V_868 = strpbrk ( V_834 , L_416 ) ;
if ( ! V_868 )
break;
V_868 ++ ;
if ( * V_868 != '\0' ) {
V_872 = F_253 ( V_868 , & V_452 , 16 ) ;
sprintf ( V_243 , L_417 , V_243 , V_872 ) ;
} else {
break;
}
V_834 = V_868 ;
}
V_10 -> V_66 = 6 ;
break;
case 'd' :
sprintf ( V_64 , L_418 , F_109 ( V_8 , V_3 ) ) ;
for ( V_4 = 0 ; V_4 <= strlen ( V_64 ) ; V_4 ++ ) {
if ( V_4 % 2 == 0 ) {
V_835 [ V_264 ] = ' ' ;
V_264 ++ ;
}
if ( V_64 [ V_4 ] != '\0' )
V_835 [ V_264 ] = V_64 [ V_4 ] ;
V_264 ++ ;
}
V_834 = V_835 ;
F_29 ( L_415 , V_834 ) ;
while ( * V_834 != '\0' ) {
V_868 = strpbrk ( V_834 , L_416 ) ;
if ( ! V_868 )
break;
V_868 ++ ;
if ( * V_868 != '\0' ) {
V_872 = F_253 ( V_868 , & V_452 , 16 ) ;
sprintf ( V_243 , L_417 , V_243 , V_872 ) ;
} else {
break;
}
V_834 = V_868 ;
}
V_10 -> V_66 = strlen ( V_243 ) ;
break;
default:
V_10 -> V_66 = 0 ;
V_140 = - V_156 ;
break;
}
return V_140 ;
}
static int F_266 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_4 V_456 , V_3 , V_64 ;
int V_140 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_140 = sscanf ( V_243 , L_97 , & V_456 , & V_3 , & V_64 ) ;
if ( V_140 < 3 )
return - V_156 ;
if ( V_456 >= V_873 )
return - V_156 ;
if ( V_3 > 0xFF )
return - V_156 ;
if ( V_64 > 0xFFFFF )
return - V_156 ;
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
F_267 ( V_8 , V_456 , V_3 , V_64 ) ;
sprintf ( V_243 , L_419 ) ;
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_268 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
char * V_834 , * V_868 , * V_452 ;
char V_64 [ 20 ] , V_835 [ 20 ] ;
T_4 V_456 , V_3 ;
T_4 V_140 , V_4 = 0 , V_264 = 0 , V_874 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
V_140 = sscanf ( V_870 , L_91 , & V_456 , & V_3 ) ;
F_40 ( V_870 ) ;
if ( V_140 < 2 )
return - V_156 ;
if ( V_456 >= V_873 )
return - V_156 ;
if ( V_3 > 0xFF )
return - V_156 ;
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
sprintf ( V_64 , L_418 , F_269 ( V_8 , V_456 , V_3 ) ) ;
for ( V_4 = 0 ; V_4 <= strlen ( V_64 ) ; V_4 ++ ) {
if ( V_4 % 2 == 0 ) {
V_835 [ V_264 ] = ' ' ;
V_264 ++ ;
}
V_835 [ V_264 ] = V_64 [ V_4 ] ;
V_264 ++ ;
}
V_834 = V_835 ;
F_29 ( L_415 , V_834 ) ;
while ( * V_834 != '\0' ) {
V_868 = strpbrk ( V_834 , L_416 ) ;
V_868 ++ ;
if ( * V_868 != '\0' ) {
V_874 = F_253 ( V_868 , & V_452 , 16 ) ;
sprintf ( V_243 , L_417 , V_243 , V_874 ) ;
} else {
break;
}
V_834 = V_868 ;
}
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_270 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 -> V_351 . V_352 == 0 ) {
V_8 -> V_351 . V_352 = 1 ;
F_246 ( V_8 , V_847 ) ;
F_99 ( V_8 ) ;
F_271 ( V_8 , 1 ) ;
}
if ( V_8 -> V_351 . V_352 == 0 )
return - V_253 ;
if ( V_8 -> V_875 . V_86 == V_876 ) {
if ( F_272 ( V_8 ) == V_188 )
return - V_253 ;
V_8 -> V_875 . V_86 = V_877 ;
}
return 0 ;
}
static int F_273 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 -> V_351 . V_352 == 1 ) {
F_274 ( V_8 ) ;
V_8 -> V_351 . V_352 = 0 ;
}
if ( V_8 -> V_875 . V_86 != V_876 ) {
F_275 ( V_8 ) ;
V_8 -> V_875 . V_86 = V_876 ;
}
return 0 ;
}
static int F_276 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_4 V_41 = V_878 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
V_41 = F_277 ( V_870 ) ;
sprintf ( V_243 , L_420 , V_41 ) ;
F_40 ( V_870 ) ;
if ( V_41 <= 0x7f )
V_41 = F_278 ( ( T_1 ) V_41 ) ;
else
V_41 = ( V_41 - 0x80 + V_879 ) ;
if ( V_41 >= V_880 )
return - V_156 ;
V_8 -> V_875 . V_881 = V_41 ;
F_279 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
return 0 ;
}
static int F_280 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
T_4 V_518 = 1 ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
V_518 = F_277 ( V_870 ) ;
sprintf ( V_243 , L_421 , V_8 -> V_875 . V_518 , V_518 ) ;
V_8 -> V_875 . V_518 = V_518 ;
F_281 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_282 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_4 V_882 = 0 , V_883 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
sscanf ( V_243 , L_422 , & V_882 , & V_883 ) ;
if ( V_882 != V_884 )
V_882 = V_525 ;
V_8 -> V_875 . V_882 = ( T_1 ) V_882 ;
V_8 -> V_875 . V_885 = V_883 ;
F_283 ( V_8 ) ;
return 0 ;
}
static int F_284 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_4 V_886 = 0 , V_887 = 0 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
sscanf ( V_870 , L_423 , & V_886 , & V_887 ) ;
sprintf ( V_243 , L_424 , V_886 , V_887 ) ;
V_8 -> V_875 . V_888 = ( T_1 ) V_886 ;
V_8 -> V_875 . V_889 = ( T_1 ) V_887 ;
V_8 -> V_875 . V_890 = 1 ;
F_285 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_286 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_1 V_4 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
T_2 V_891 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
sprintf ( V_243 , L_425 , V_870 ) ;
for ( V_4 = 0 ; V_4 < strlen ( V_870 ) ; V_4 ++ ) {
switch ( V_870 [ V_4 ] ) {
case 'a' :
V_891 |= V_892 ;
break;
case 'b' :
V_891 |= V_893 ;
break;
}
}
V_8 -> V_875 . V_894 = V_891 ;
F_287 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_288 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_1 V_4 ;
T_2 V_891 = 0 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
sprintf ( V_243 , L_426 , V_870 ) ;
for ( V_4 = 0 ; V_4 < strlen ( V_870 ) ; V_4 ++ ) {
switch ( V_870 [ V_4 ] ) {
case 'a' :
V_891 |= V_892 ;
break;
case 'b' :
V_891 |= V_893 ;
break;
}
}
V_8 -> V_875 . V_895 = V_891 ;
F_287 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_289 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_4 V_896 = 1 , V_897 = 1 , V_898 = 1 , V_899 = 1 , V_900 = 1 , V_901 = 1 , V_31 = 1 ;
T_4 V_902 = 1 ;
T_4 V_903 = 0 ;
struct V_904 * V_905 ;
struct V_906 * V_907 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_905 = & V_8 -> V_875 ;
if ( F_106 ( V_243 , V_10 -> V_453 , V_10 -> V_66 ) )
return - V_454 ;
F_29 ( L_342 , V_343 , V_243 ) ;
V_897 = strncmp ( V_243 , L_427 , 5 ) ;
V_898 = strncmp ( V_243 , L_428 , 20 ) ;
V_899 = strncmp ( V_243 , L_429 , 20 ) ;
V_900 = strncmp ( V_243 , L_430 , 20 ) ;
V_901 = strncmp ( V_243 , L_431 , 20 ) ;
V_896 = strncmp ( V_243 , L_432 , 20 ) ;
V_31 = strncmp ( V_243 , L_433 , 4 ) ;
sscanf ( V_243 , L_434 , & V_903 ) ;
F_4 ( V_243 , '\0' , sizeof( * V_243 ) ) ;
if ( V_31 == 0 ) {
V_902 = 0 ;
V_905 -> V_908 . V_31 = 1 ;
sprintf ( V_243 , L_435 ) ;
} else {
V_902 = 1 ;
if ( V_905 -> V_86 != V_877 ) {
if ( V_905 -> V_908 . V_31 != 1 ) {
F_29 ( L_436 , V_343 , V_905 -> V_86 ) ;
return - V_454 ;
}
}
}
if ( V_896 == 0 || V_897 == 0 )
V_905 -> V_86 = V_909 ;
if ( V_901 == 0 )
V_905 -> V_86 = V_910 ;
if ( V_898 == 0 )
V_905 -> V_86 = V_911 ;
if ( V_899 == 0 )
V_905 -> V_86 = V_912 ;
if ( V_900 == 0 )
V_905 -> V_86 = V_913 ;
switch ( V_905 -> V_86 ) {
case V_909 :
if ( V_902 == 0 ) {
V_905 -> V_908 . V_31 = 1 ;
V_905 -> V_86 = V_877 ;
sprintf ( V_243 , L_435 ) ;
} else if ( V_905 -> V_908 . V_31 == 1 ) {
sprintf ( V_243 , L_437 , V_903 ) ;
V_905 -> V_908 . V_31 = 0 ;
V_905 -> V_908 . V_903 = V_903 ;
V_905 -> V_908 . V_914 = 2 ;
V_907 = & V_905 -> V_908 . V_915 ;
V_907 -> V_916 = 1500 ;
F_4 ( V_907 -> V_917 , 0xFF , V_23 ) ;
F_290 ( V_8 ) ;
} else {
return - V_454 ;
}
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
case V_910 :
if ( V_902 != 0 )
sprintf ( V_243 , L_438 ) ;
F_291 ( V_8 , ( T_1 ) V_902 ) ;
break;
case V_911 :
if ( V_902 != 0 )
sprintf ( V_243 , L_438 ) ;
F_292 ( V_8 , ( T_1 ) V_902 ) ;
break;
case V_912 :
if ( V_902 != 0 ) {
if ( V_905 -> V_881 <= V_918 ) {
sprintf ( V_243 , L_438 ) ;
F_293 ( V_8 , ( T_1 ) V_902 ) ;
} else {
sprintf ( V_243 , L_439 ) ;
}
}
break;
case V_913 :
if ( V_902 != 0 )
sprintf ( V_243 , L_438 ) ;
F_294 ( V_8 , ( T_1 ) V_902 ) ;
break;
default:
sprintf ( V_243 , L_440 ) ;
return - V_454 ;
}
if ( V_902 == 1 && V_905 -> V_86 != V_877 ) {
struct V_904 * V_905 = & V_8 -> V_875 ;
if ( V_905 -> V_908 . V_31 == 0 ) {
V_905 -> V_908 . V_31 = 1 ;
F_79 ( 5 ) ;
}
V_905 -> V_908 . V_31 = 0 ;
V_905 -> V_908 . V_903 = 1 ;
F_290 ( V_8 ) ;
} else {
V_905 -> V_86 = V_877 ;
}
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_295 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_1 V_919 = 0 , V_920 = 0 , V_921 ;
T_4 V_922 = 0 , V_923 = 0 , V_924 = 0 , V_925 = 0 , V_926 = 0 , V_927 = 0 , V_928 = 0 , V_929 = 0 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
F_29 ( L_441 , V_343 , V_870 ) ;
V_919 = ( strncmp ( V_870 , L_442 , 5 ) == 0 ) ? 1 : 0 ;
V_920 = ( strncmp ( V_870 , L_433 , 5 ) == 0 ) ? 1 : 0 ;
V_921 = ( strncmp ( V_870 , L_443 , 3 ) == 0 ) ? 1 : 0 ;
if ( V_919 ) {
sprintf ( V_243 , L_442 ) ;
F_296 ( V_8 , V_919 ) ;
} else if ( V_920 ) {
F_296 ( V_8 , 0 ) ;
sprintf ( V_243 , L_444 , V_8 -> V_875 . V_930 , V_8 -> V_875 . V_931 ) ;
} else if ( V_921 ) {
V_922 = F_297 ( V_8 , 0xf88 , 0xffffffff ) ;
V_923 = F_297 ( V_8 , 0xf84 , 0xffffffff ) ;
V_924 = F_297 ( V_8 , 0xf94 , 0x0000FFFF ) ;
V_925 = F_297 ( V_8 , 0xf94 , 0xFFFF0000 ) ;
V_926 = F_297 ( V_8 , 0xf90 , 0x0000FFFF ) ;
V_927 = F_297 ( V_8 , 0xf90 , 0xFFFF0000 ) ;
V_928 = F_297 ( V_8 , 0xcf0 , 0x0000FFFF ) ;
V_928 = F_297 ( V_8 , 0xcf2 , 0xFFFF0000 ) ;
V_928 = F_297 ( V_8 , 0xda0 , 0xFFFF0000 ) ;
V_928 = F_297 ( V_8 , 0xda4 , 0x0000FFFF ) ;
V_928 = F_297 ( V_8 , 0xda4 , 0xFFFF0000 ) ;
V_928 = F_297 ( V_8 , 0xda8 , 0x0000FFFF ) ;
V_929 = ( F_107 ( V_8 , 0xa5b ) << 8 ) | ( F_107 ( V_8 , 0xa5c ) ) ;
sprintf ( V_243 , L_445 , V_922 + V_924 + V_926 , V_923 + V_925 + V_927 , V_928 + V_929 ) ;
}
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_298 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_4 V_932 , V_933 , V_934 , V_935 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_932 = V_8 -> V_875 . V_908 . V_936 ;
V_933 = 0 ;
V_934 = V_8 -> V_875 . V_930 ;
V_935 = V_8 -> V_875 . V_931 ;
F_4 ( V_243 , '\0' , 128 ) ;
sprintf ( V_243 , L_446 , V_932 , V_933 , V_934 , V_935 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
return 0 ;
}
static int F_299 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_1 V_677 ;
T_4 V_937 ;
T_8 V_140 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
V_677 = 1 ;
if ( V_10 -> V_66 > 1 ) {
if ( strncmp ( V_870 , L_433 , 4 ) == 0 ) {
V_677 = 0 ;
sprintf ( V_243 , L_447 ) ;
} else if ( sscanf ( V_870 , L_448 , & V_937 ) ) {
V_140 = F_300 ( V_8 , ( T_1 ) V_937 ) ;
if ( V_140 == V_188 )
return - V_253 ;
sprintf ( V_243 , L_449 , V_937 ) ;
} else {
F_40 ( V_870 ) ;
return - V_156 ;
}
}
F_40 ( V_870 ) ;
V_140 = F_301 ( V_8 , V_677 ) ;
if ( V_140 == V_188 )
return - V_253 ;
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_302 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
strcpy ( V_243 , V_870 ) ;
V_10 -> V_66 = F_303 ( V_8 , V_243 ) ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_304 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_1 V_288 ;
T_2 V_938 = 1 ;
T_2 V_3 = V_939 ;
T_2 V_116 = 1 ;
T_2 V_838 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( F_106 ( V_243 , V_10 -> V_453 , V_10 -> V_66 ) )
return - V_454 ;
V_938 = strncmp ( V_243 , L_450 , 6 ) ;
F_305 ( V_8 , & V_288 ) ;
if ( V_938 == 0 ) {
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( 2 > V_838 ) {
F_29 ( L_451 ) ;
return - V_454 ;
}
if ( F_261 ( V_8 , V_3 , V_116 , & V_288 ) == V_188 ) {
F_29 ( L_452 ) ;
return - V_454 ;
} else {
sprintf ( V_243 , L_453 , V_288 ) ;
}
} else {
sprintf ( V_243 , L_454 , V_288 ) ;
}
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_306 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
struct V_904 * V_905 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_905 = & V_8 -> V_875 ;
V_905 -> V_908 . V_936 = 0 ;
V_905 -> V_940 = 0 ;
V_905 -> V_930 = 0 ;
V_905 -> V_931 = 0 ;
F_307 ( V_8 , 0xf14 , V_941 , 0x1 ) ;
F_79 ( 10 ) ;
F_307 ( V_8 , 0xf14 , V_941 , 0x0 ) ;
return 0 ;
}
static int F_308 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
T_4 V_104 ;
T_1 V_632 , V_633 = 0 ;
T_4 V_4 , V_264 = 1 , V_456 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( strncmp ( V_243 , L_455 , 4 ) == 0 ) {
F_29 ( L_189 ) ;
for ( V_4 = 0x0 ; V_4 < 0x300 ; V_4 += 4 ) {
if ( V_264 % 4 == 1 )
F_29 ( L_190 , V_4 ) ;
F_29 ( L_191 , F_109 ( V_8 , V_4 ) ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_29 ( L_192 ) ;
}
for ( V_4 = 0x400 ; V_4 < 0x1000 ; V_4 += 4 ) {
if ( V_264 % 4 == 1 )
F_29 ( L_190 , V_4 ) ;
F_29 ( L_191 , F_109 ( V_8 , V_4 ) ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_29 ( L_192 ) ;
}
V_264 = 1 ;
F_189 ( V_8 , V_634 , ( T_1 * ) ( & V_632 ) ) ;
F_29 ( L_194 ) ;
if ( ( V_635 == V_632 ) || ( V_636 == V_632 ) )
V_633 = 1 ;
else
V_633 = 2 ;
for ( V_456 = 0 ; V_456 < V_633 ; V_456 ++ ) {
for ( V_4 = 0 ; V_4 < 0x34 ; V_4 ++ ) {
V_104 = F_115 ( V_8 , V_456 , V_4 , 0xffffffff ) ;
if ( V_264 % 4 == 1 )
F_29 ( L_196 , V_4 ) ;
F_29 ( L_191 , V_104 ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_29 ( L_192 ) ;
}
}
}
return 0 ;
}
static int F_309 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_409 * V_10 , char * V_243 )
{
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
T_4 V_942 ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_453 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_454 ;
}
F_29 ( L_456 , V_343 , V_870 ) ;
sscanf ( V_870 , L_457 , & V_942 ) ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_310 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_64 . V_66 , V_871 ) ;
T_1 V_943 = 1 , V_944 = 1 ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_64 . V_453 , V_10 -> V_64 . V_66 ) )
return - V_454 ;
F_29 ( L_456 , V_343 , V_870 ) ;
V_943 = strncmp ( V_870 , L_183 , 2 ) ;
V_944 = strncmp ( V_870 , L_458 , 3 ) ;
if ( V_943 == 0 ) {
F_311 ( V_8 , true ) ;
F_29 ( L_459 , V_343 ) ;
} else if ( V_944 == 0 ) {
F_311 ( V_8 , false ) ;
F_29 ( L_460 , V_343 ) ;
}
F_40 ( V_870 ) ;
return 0 ;
}
static int F_312 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_64 . V_66 , V_871 ) ;
T_1 V_945 = 1 ;
struct V_823 * V_824 = F_248 ( V_8 ) ;
if ( ! V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_10 -> V_64 . V_453 , V_10 -> V_64 . V_66 ) )
return - V_454 ;
F_29 ( L_456 , V_343 , V_870 ) ;
V_945 = strncmp ( V_870 , L_461 , 8 ) ;
if ( V_945 == 0 ) {
F_29 ( L_462 , V_343 ) ;
if ( V_824 -> V_946 )
sprintf ( V_243 , L_463 ) ;
else
sprintf ( V_243 , L_464 ) ;
}
V_10 -> V_64 . V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_313 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_822 , char * V_243 )
{
struct V_409 * V_10 = (struct V_409 * ) V_822 ;
T_4 V_947 = V_10 -> V_65 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 == NULL )
return - V_948 ;
if ( V_243 == NULL ) {
V_10 -> V_66 = 0 ;
return - V_949 ;
}
switch ( V_947 ) {
case V_466 :
F_29 ( L_465 ) ;
F_270 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_950 :
F_29 ( L_466 ) ;
F_273 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_951 :
F_29 ( L_467 ) ;
F_282 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_952 :
F_29 ( L_468 ) ;
F_306 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_953 :
F_29 ( L_469 ) ;
F_310 ( V_139 , V_27 , V_822 , V_243 ) ;
break;
case V_954 :
F_29 ( L_470 ) ;
F_179 ( V_139 , V_27 , V_822 , V_243 ) ;
break;
}
return 0 ;
}
static int F_314 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_822 , char * V_243 )
{
struct V_409 * V_10 = (struct V_409 * ) V_822 ;
T_4 V_947 = V_10 -> V_65 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 == NULL )
return - V_948 ;
if ( V_243 == NULL ) {
V_10 -> V_66 = 0 ;
return - V_949 ;
}
switch ( V_947 ) {
case V_469 :
F_263 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_955 :
F_266 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_956 :
F_29 ( L_471 ) ;
F_309 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_957 :
F_29 ( L_472 ) ;
F_280 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_467 :
F_29 ( L_473 ) ;
F_264 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_958 :
F_29 ( L_474 ) ;
F_268 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_959 :
F_29 ( L_475 ) ;
F_276 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_960 :
F_29 ( L_476 ) ;
F_284 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_961 :
F_29 ( L_477 ) ;
F_286 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_962 :
F_29 ( L_478 ) ;
F_288 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_963 :
F_298 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_964 :
F_29 ( L_479 ) ;
F_289 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_965 :
F_29 ( L_480 ) ;
F_295 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_966 :
F_29 ( L_481 ) ;
F_247 ( V_139 , V_27 , V_822 , V_243 ) ;
break;
case V_967 :
F_29 ( L_482 ) ;
F_308 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_968 :
F_29 ( L_483 ) ;
F_302 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_969 :
F_29 ( L_484 ) ;
F_304 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_970 :
F_29 ( L_485 ) ;
F_312 ( V_139 , V_27 , V_822 , V_243 ) ;
break;
case V_971 :
F_29 ( L_486 ) ;
F_299 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_972 :
F_29 ( L_487 ) ;
F_259 ( V_139 , V_27 , V_822 , V_243 ) ;
break;
}
F_79 ( 10 ) ;
return 0 ;
}
static int F_315 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
return 0 ;
}
static int F_316 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
return 0 ;
}
static int F_317 (
struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
T_4 V_364 ;
T_1 * V_504 , * V_834 ;
char * V_452 ;
T_1 * V_973 = L_343 ;
F_29 ( L_488 , V_343 ) ;
V_364 = V_10 -> V_64 . V_66 ;
V_504 = ( T_1 * ) F_43 ( V_364 ) ;
if ( V_504 == NULL ) {
F_29 ( L_489 , V_343 ) ;
return - V_223 ;
}
if ( F_106 ( V_504 , V_10 -> V_64 . V_453 , V_364 ) ) {
F_40 ( V_504 ) ;
F_29 ( L_490 , V_343 ) ;
return - V_454 ;
}
F_29 ( L_491 , V_343 , V_504 ) ;
V_452 = ( char * ) V_504 ;
V_834 = F_251 ( & V_452 , V_973 ) ;
if ( ( V_834 == NULL ) || ( strlen ( V_834 ) == 0 ) ) {
F_40 ( V_504 ) ;
F_29 ( L_492 , V_343 ) ;
return - V_454 ;
}
F_40 ( V_504 ) ;
return 0 ;
}
static struct V_974 * F_318 ( struct V_138 * V_139 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_974 * V_975 = & V_8 -> V_976 ;
int V_977 = 0 ;
int V_978 = 0 ;
int V_979 = 0 ;
if ( ! F_25 ( & V_8 -> V_15 , V_128 ) ) {
V_975 -> V_123 . V_123 = 0 ;
V_975 -> V_123 . V_135 = 0 ;
V_975 -> V_123 . V_136 = 0 ;
} else {
V_977 = V_8 -> V_129 . V_130 ;
V_978 = V_8 -> V_129 . V_131 ;
V_979 = V_8 -> V_129 . V_136 ;
V_975 -> V_123 . V_135 = V_977 ;
V_975 -> V_123 . V_123 = V_978 ;
V_975 -> V_123 . V_136 = V_979 ;
}
V_975 -> V_123 . V_124 = V_980 ;
return & V_8 -> V_976 ;
}
static int F_319 ( T_9 args )
{
int V_981 = args & V_982 ;
int type = ( args & V_983 ) >> 12 ;
return V_981 * V_984 [ type ] ;
}
static int F_320 ( struct V_138 * V_139 , union V_9 * V_985 )
{
int V_169 = 0 ;
T_1 * V_870 = NULL ;
T_4 V_986 = 0 ;
const char V_973 [] = L_416 ;
T_1 * V_987 = NULL ;
T_4 V_988 = 0 ;
T_4 V_903 = 0 ;
T_1 * V_989 = NULL ;
T_4 V_990 = 0 ;
char * V_991 = NULL ;
T_1 V_992 [ 17 ] = { 0 } ;
T_4 V_993 ;
T_8 V_364 ;
T_1 * V_243 = NULL ;
T_4 V_994 = 0 ;
T_8 V_995 ;
const T_10 * V_996 ;
const struct V_997 * V_998 ;
T_4 V_999 ;
T_10 V_492 ;
int V_325 ;
int V_947 = 0 ;
int V_465 = 0 ;
union V_9 V_822 ;
memcpy ( & V_822 , V_985 , sizeof( V_822 ) ) ;
V_986 = V_822 . V_64 . V_66 ;
V_870 = F_43 ( V_986 ) ;
if ( NULL == V_870 )
return - V_223 ;
if ( F_106 ( V_870 , V_822 . V_64 . V_453 , V_986 ) ) {
V_169 = - V_454 ;
goto exit;
}
V_991 = V_870 ;
V_364 = V_986 ;
sscanf ( V_991 , L_493 , V_992 ) ;
V_993 = strlen ( V_992 ) ;
F_29 ( L_494 , V_343 , V_992 ) ;
if ( V_993 > 0 )
V_993 += 1 ;
V_991 += V_993 ;
V_364 -= V_993 ;
F_29 ( L_495 , V_343 , V_991 ) ;
V_996 = V_1000 ;
V_998 = V_1001 ;
V_999 = sizeof( V_1001 ) / sizeof( struct V_997 ) ;
if ( V_999 == 0 ) {
V_169 = - V_189 ;
goto exit;
}
V_995 = - 1 ;
while ( ( ++ V_995 < V_999 ) && strcmp ( V_998 [ V_995 ] . V_78 , V_992 ) ) ;
if ( V_995 == V_999 ) {
V_169 = - V_189 ;
goto exit;
}
if ( V_998 [ V_995 ] . V_60 < V_1002 ) {
int V_264 = - 1 ;
while ( ( ++ V_264 < V_999 ) && ( ( V_998 [ V_264 ] . V_78 [ 0 ] != '\0' ) ||
( V_998 [ V_264 ] . V_1003 != V_998 [ V_995 ] . V_1003 ) ||
( V_998 [ V_264 ] . V_1004 != V_998 [ V_995 ] . V_1004 ) ) ) ;
if ( V_264 == V_999 ) {
V_169 = - V_156 ;
goto exit;
}
V_947 = V_998 [ V_995 ] . V_60 ;
V_465 = sizeof( V_1005 ) ;
V_995 = V_264 ;
}
V_989 = F_43 ( 4096 ) ;
if ( NULL == V_989 ) {
V_169 = - V_223 ;
goto exit;
}
if ( ( V_998 [ V_995 ] . V_1003 & V_983 ) &&
( V_998 [ V_995 ] . V_1003 & V_982 ) ) {
T_1 * V_1006 ;
switch ( V_998 [ V_995 ] . V_1003 & V_983 ) {
case V_1007 :
V_903 = 0 ;
do {
V_1006 = F_251 ( & V_991 , V_973 ) ;
if ( NULL == V_1006 )
break;
sscanf ( V_1006 , L_496 , & V_325 ) ;
V_989 [ V_903 ++ ] = ( T_1 ) V_325 ;
} while ( 1 );
V_990 = V_903 ;
V_822 . V_64 . V_66 = V_903 ;
if ( V_822 . V_64 . V_66 > ( V_998 [ V_995 ] . V_1003 & V_982 ) )
V_822 . V_64 . V_66 = V_998 [ V_995 ] . V_1003 & V_982 ;
break;
case V_1008 :
V_903 = 0 ;
do {
V_1006 = F_251 ( & V_991 , V_973 ) ;
if ( NULL == V_1006 )
break;
sscanf ( V_1006 , L_496 , & V_325 ) ;
( ( T_8 * ) V_989 ) [ V_903 ++ ] = ( T_8 ) V_325 ;
} while ( 1 );
V_990 = V_903 * sizeof( T_8 ) ;
V_822 . V_64 . V_66 = V_903 ;
if ( V_822 . V_64 . V_66 > ( V_998 [ V_995 ] . V_1003 & V_982 ) )
V_822 . V_64 . V_66 = V_998 [ V_995 ] . V_1003 & V_982 ;
break;
case V_1009 :
if ( V_364 > 0 ) {
V_822 . V_64 . V_66 = V_364 ;
if ( V_822 . V_64 . V_66 > ( V_998 [ V_995 ] . V_1003 & V_982 ) )
V_822 . V_64 . V_66 = V_998 [ V_995 ] . V_1003 & V_982 ;
memcpy ( V_989 , V_991 , V_822 . V_64 . V_66 ) ;
} else {
V_822 . V_64 . V_66 = 1 ;
V_989 [ 0 ] = '\0' ;
}
V_990 = V_822 . V_64 . V_66 ;
break;
default:
F_29 ( L_497 , V_343 ) ;
V_169 = - 1 ;
goto exit;
}
if ( ( V_998 [ V_995 ] . V_1003 & V_1010 ) &&
( V_822 . V_64 . V_66 != ( V_998 [ V_995 ] . V_1003 & V_982 ) ) ) {
F_29 ( L_498 ,
V_343 , V_992 , V_998 [ V_995 ] . V_1003 & V_982 ) ;
V_169 = - V_156 ;
goto exit;
}
} else {
V_822 . V_64 . V_66 = 0L ;
}
if ( ( V_998 [ V_995 ] . V_1003 & V_1010 ) &&
( ( F_319 ( V_998 [ V_995 ] . V_1003 ) + V_465 ) <= V_79 ) ) {
if ( V_465 )
V_822 . V_86 = V_947 ;
memcpy ( V_822 . V_78 + V_465 , V_989 , V_79 - V_465 ) ;
} else {
if ( ( V_998 [ V_995 ] . V_1003 == 0 ) &&
( V_998 [ V_995 ] . V_1004 & V_1010 ) &&
( F_319 ( V_998 [ V_995 ] . V_1004 ) <= V_79 ) ) {
if ( V_465 )
V_822 . V_86 = V_947 ;
} else {
if ( F_131 ( V_822 . V_64 . V_453 , V_989 , V_990 ) ) {
V_169 = - V_454 ;
goto exit;
}
V_822 . V_64 . V_65 = V_947 ;
}
}
F_40 ( V_870 ) ;
V_870 = NULL ;
V_994 = 0 ;
if ( F_321 ( V_998 [ V_995 ] . V_60 ) ) {
V_994 = F_319 ( V_998 [ V_995 ] . V_1003 ) ;
if ( ( V_998 [ V_995 ] . V_1003 & V_1010 ) &&
( ( V_994 + V_465 ) <= V_79 ) )
V_994 = 0 ;
} else {
V_994 = F_319 ( V_998 [ V_995 ] . V_1004 ) ;
if ( ( V_998 [ V_995 ] . V_1004 & V_1010 ) &&
( V_994 <= V_79 ) )
V_994 = 0 ;
}
if ( V_994 == 0 ) {
V_243 = ( T_1 * ) & V_822 ;
F_40 ( V_989 ) ;
V_989 = NULL ;
} else {
V_243 = V_989 ;
}
V_492 = V_996 [ V_998 [ V_995 ] . V_60 - V_1011 ] ;
V_169 = V_492 ( V_139 , NULL , & V_822 , V_243 ) ;
if ( ( V_998 [ V_995 ] . V_1004 & V_983 ) &&
( V_998 [ V_995 ] . V_1004 & V_982 ) ) {
int V_264 ;
int V_1012 = 0 ;
T_1 V_1006 [ 20 ] = { 0 } ;
if ( ( V_998 [ V_995 ] . V_1004 & V_1010 ) &&
( F_319 ( V_998 [ V_995 ] . V_1004 ) <= V_79 ) )
V_1012 = V_998 [ V_995 ] . V_1004 & V_982 ;
else
V_1012 = V_822 . V_64 . V_66 ;
V_987 = F_43 ( 4096 ) ;
if ( NULL == V_987 ) {
V_169 = - V_223 ;
goto exit;
}
switch ( V_998 [ V_995 ] . V_1004 & V_983 ) {
case V_1007 :
for ( V_264 = 0 ; V_264 < V_1012 ; V_264 ++ ) {
sprintf ( V_1006 , L_499 , V_243 [ V_264 ] ) ;
V_364 = strlen ( V_1006 ) ;
V_988 = strlen ( V_987 ) ;
if ( ( V_988 + V_364 + 1 ) > 4096 ) {
V_169 = - V_389 ;
goto exit;
}
memcpy ( V_987 + V_988 , V_1006 , V_364 ) ;
}
break;
case V_1008 :
for ( V_264 = 0 ; V_264 < V_1012 ; V_264 ++ ) {
sprintf ( V_1006 , L_499 , ( ( V_1013 * ) V_243 ) [ V_264 ] ) ;
V_364 = strlen ( V_1006 ) ;
V_988 = strlen ( V_987 ) ;
if ( ( V_988 + V_364 + 1 ) > 4096 ) {
V_169 = - V_389 ;
goto exit;
}
memcpy ( V_987 + V_988 , V_1006 , V_364 ) ;
}
break;
case V_1009 :
memcpy ( V_987 , V_243 , V_1012 ) ;
break;
default:
F_29 ( L_497 , V_343 ) ;
V_169 = - 1 ;
goto exit;
}
V_988 = strlen ( V_987 ) + 1 ;
V_985 -> V_64 . V_66 = V_988 ;
if ( F_131 ( V_985 -> V_64 . V_453 , V_987 , V_988 ) ) {
V_169 = - V_454 ;
goto exit;
}
} else {
V_985 -> V_64 . V_66 = 0 ;
}
exit:
F_40 ( V_870 ) ;
F_40 ( V_989 ) ;
F_40 ( V_987 ) ;
return V_169 ;
}
int F_322 ( struct V_138 * V_139 , struct V_1014 * V_1015 , int V_60 )
{
struct V_1016 * V_1017 = (struct V_1016 * ) V_1015 ;
int V_140 = 0 ;
switch ( V_60 ) {
case V_1018 :
V_140 = F_207 ( V_139 , & V_1017 -> V_61 . V_64 ) ;
break;
#ifdef F_201
case V_1019 :
V_140 = F_240 ( V_139 , & V_1017 -> V_61 . V_64 ) ;
break;
#endif
case V_1002 :
V_140 = F_320 ( V_139 , & V_1017 -> V_61 ) ;
break;
case ( V_1002 + 1 ) :
V_140 = F_323 ( V_139 , V_1015 , V_60 ) ;
break;
default:
V_140 = - V_189 ;
break;
}
return V_140 ;
}
