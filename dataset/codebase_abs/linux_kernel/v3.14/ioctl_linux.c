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
if ( ! memcmp ( V_269 , V_268 , V_23 ) )
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
V_285 -> V_291 . V_135 = 178 ;
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
T_5 V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_323 * V_324 = (struct V_323 * ) V_322 ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_325 * V_326 ;
T_1 * V_327 , * V_328 ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
enum V_332 V_333 ;
V_167 ;
if ( V_188 == F_51 ( V_8 ) ) {
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_334 ) {
V_140 = - 1 ;
goto exit;
}
if ( V_324 -> V_17 != V_18 ) {
V_140 = - V_156 ;
goto exit;
}
V_333 = V_8 -> V_143 . V_146 ;
F_59 ( & V_330 -> V_335 ) ;
V_326 = F_60 ( V_330 ) ;
V_14 -> V_336 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( ( F_62 ( V_326 , V_14 -> V_336 ) ) == true )
break;
V_29 = F_63 ( V_14 -> V_336 , struct V_28 , V_337 ) ;
V_14 -> V_336 = F_61 ( V_14 -> V_336 ) ;
V_327 = V_29 -> V_21 . V_22 ;
V_328 = V_324 -> V_19 ;
if ( ( ! memcmp ( V_327 , V_328 , V_23 ) ) ) {
if ( ! F_52 ( V_8 , V_29 -> V_21 . V_338 ) ) {
V_140 = - 1 ;
F_64 ( & V_330 -> V_335 ) ;
goto exit;
}
break;
}
}
F_64 ( & V_330 -> V_335 ) ;
F_65 ( V_8 , V_333 ) ;
if ( F_66 ( V_8 , V_324 -> V_19 ) == false ) {
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
T_2 V_339 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_340 * V_341 = (struct V_340 * ) V_243 ;
if ( V_341 == NULL )
return - 1 ;
F_29 ( L_57 , V_342 ) ;
V_339 = V_341 -> V_343 ;
F_29 ( L_58 , V_342 , V_341 -> V_60 , V_339 ) ;
switch ( V_341 -> V_60 ) {
case V_344 :
if ( ! F_69 ( V_8 ) )
V_140 = - 1 ;
break;
case V_345 :
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
T_1 V_346 = false ;
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_347 V_348 [ V_349 ] ;
#ifdef F_10
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
#endif
F_23 ( V_112 , V_113 , ( L_59 ) ) ;
V_167 ;
if ( V_8 -> V_350 . V_351 == 1 ) {
if ( F_25 ( V_14 , V_201 ) ) {
V_140 = - 1 ;
goto exit;
}
}
if ( V_188 == F_51 ( V_8 ) ) {
V_140 = - 1 ;
goto exit;
}
if ( V_8 -> V_352 ) {
F_29 ( L_60 , V_8 -> V_352 ) ;
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_334 ) {
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_254 ) {
V_140 = - 1 ;
goto exit;
}
if ( V_14 -> V_353 . V_354 ) {
F_3 ( V_8 ) ;
goto exit;
}
if ( F_25 ( V_14 , V_355 | V_356 ) ) {
F_3 ( V_8 ) ;
goto exit;
}
#ifdef F_10
if ( V_49 -> V_357 != V_51 ) {
F_71 ( V_49 , F_72 ( V_49 ) ) ;
F_38 ( V_49 , V_358 ) ;
F_73 ( V_49 , V_359 ) ;
F_74 ( V_8 , true ) ;
}
#endif
F_4 ( V_348 , 0 , sizeof( struct V_347 ) * V_349 ) ;
if ( V_10 -> V_64 . V_66 == sizeof( struct V_360 ) ) {
struct V_360 * V_361 = (struct V_360 * ) V_243 ;
if ( V_10 -> V_64 . V_65 & V_362 ) {
int V_363 = F_75 ( ( int ) V_361 -> V_364 , V_365 ) ;
memcpy ( V_348 [ 0 ] . V_53 , V_361 -> V_366 , V_363 ) ;
V_348 [ 0 ] . V_67 = V_363 ;
F_29 ( L_61 , V_361 -> V_366 , V_361 -> V_364 ) ;
F_59 ( & V_14 -> V_335 ) ;
V_346 = F_76 ( V_8 , V_348 , 1 , NULL , 0 ) ;
F_64 ( & V_14 -> V_335 ) ;
} else if ( V_361 -> V_367 == V_368 ) {
F_29 ( L_62 ) ;
}
} else {
if ( V_10 -> V_64 . V_66 >= V_369 &&
! memcmp ( V_243 , V_370 , V_369 ) ) {
int V_363 = V_10 -> V_64 . V_66 - V_369 ;
char * V_371 = V_243 + V_369 ;
char V_372 ;
char V_373 ;
int V_374 = 0 ;
while ( V_363 >= 1 ) {
V_372 = * ( V_371 ++ ) ;
V_363 -= 1 ;
switch ( V_372 ) {
case V_375 :
if ( V_363 < 1 ) {
V_363 = 0 ;
break;
}
V_373 = * ( V_371 ++ ) ; V_363 -= 1 ;
if ( V_373 > 0 && V_373 <= V_363 ) {
V_348 [ V_374 ] . V_67 = V_373 ;
memcpy ( V_348 [ V_374 ] . V_53 , V_371 , V_348 [ V_374 ] . V_67 ) ;
V_374 ++ ;
}
V_371 += V_373 ;
V_363 -= V_373 ;
break;
case V_376 :
case V_377 :
V_371 += 1 ;
V_363 -= 1 ;
break;
case V_378 :
case V_379 :
case V_380 :
V_371 += 2 ;
V_363 -= 2 ;
break;
default:
V_363 = 0 ;
}
}
V_346 = F_77 ( V_8 , V_348 , V_349 ) ;
} else {
V_346 = F_77 ( V_8 , NULL , 0 ) ;
}
}
if ( ! V_346 )
V_140 = - 1 ;
exit:
V_217 ;
return V_140 ;
}
static int F_78 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_243 )
{
struct V_325 * V_381 , * V_326 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
char * V_382 = V_243 ;
char * V_31 = V_382 + V_10 -> V_64 . V_66 ;
T_4 V_140 = 0 ;
T_4 V_116 = 0 ;
T_4 V_383 ;
int V_384 ;
#ifdef F_10
struct V_48 * V_49 = & V_8 -> V_50 ;
#endif
F_23 ( V_112 , V_113 , ( L_63 ) ) ;
F_23 ( V_177 , V_113 , ( L_64 ) ) ;
V_167 ;
if ( V_8 -> V_385 . V_386 && V_8 -> V_352 ) {
V_140 = - V_156 ;
goto exit;
}
#ifdef F_10
if ( ! F_11 ( V_49 , V_51 ) ) {
V_383 = 200 ;
} else {
V_383 = 100 ;
}
#else
{
V_383 = 100 ;
}
#endif
V_384 = V_355 | V_356 ;
while ( F_25 ( V_14 , V_384 ) ) {
F_79 ( 30 ) ;
V_116 ++ ;
if ( V_116 > V_383 )
break;
}
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) )
break;
if ( ( V_31 - V_382 ) < V_387 ) {
V_140 = - V_388 ;
break;
}
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
if ( F_80 ( V_8 -> V_249 . V_305 , V_29 -> V_21 . V_80 . V_81 ) >= 0 )
V_382 = F_9 ( V_8 , V_5 , V_29 , V_382 , V_31 ) ;
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
V_10 -> V_64 . V_66 = V_382 - V_243 ;
V_10 -> V_64 . V_65 = 0 ;
exit:
V_217 ;
return V_140 ;
}
static int F_81 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_329 * V_330 = & V_14 -> V_331 ;
struct V_325 * V_326 ;
struct V_28 * V_29 = NULL ;
enum V_332 V_333 ;
struct V_347 V_389 ;
T_1 * V_390 , * V_391 ;
T_5 V_140 = 0 , V_363 ;
V_167 ;
F_23 ( V_177 , V_113 ,
( L_65 , F_82 ( V_14 ) ) ) ;
if ( V_188 == F_51 ( V_8 ) ) {
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_334 ) {
V_140 = - 1 ;
goto exit;
}
if ( V_10 -> V_366 . V_66 > V_365 ) {
V_140 = - V_388 ;
goto exit;
}
if ( F_25 ( V_14 , V_263 ) ) {
V_140 = - 1 ;
goto exit;
}
V_333 = V_8 -> V_143 . V_146 ;
F_29 ( L_66 , V_342 ) ;
if ( V_10 -> V_366 . V_65 && V_10 -> V_366 . V_66 ) {
V_363 = ( V_10 -> V_366 . V_66 < V_365 ) ? V_10 -> V_366 . V_66 : V_365 ;
if ( V_10 -> V_366 . V_66 != 33 )
F_29 ( L_67 , V_243 , V_10 -> V_366 . V_66 ) ;
F_4 ( & V_389 , 0 , sizeof( struct V_347 ) ) ;
V_389 . V_67 = V_363 ;
memcpy ( V_389 . V_53 , V_243 , V_363 ) ;
V_391 = V_389 . V_53 ;
F_23 ( V_177 , V_113 , ( L_68 , V_391 ) ) ;
F_59 ( & V_330 -> V_335 ) ;
V_326 = F_60 ( V_330 ) ;
V_14 -> V_336 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_14 -> V_336 ) == true ) {
F_23 ( V_177 , V_392 ,
( L_69 ) ) ;
break;
}
V_29 = F_63 ( V_14 -> V_336 , struct V_28 , V_337 ) ;
V_14 -> V_336 = F_61 ( V_14 -> V_336 ) ;
V_390 = V_29 -> V_21 . V_53 . V_53 ;
F_23 ( V_177 , V_113 ,
( L_70 ,
V_29 -> V_21 . V_53 . V_53 ) ) ;
if ( ( ! memcmp ( V_390 , V_391 , V_389 . V_67 ) ) &&
( V_29 -> V_21 . V_53 . V_67 == V_389 . V_67 ) ) {
F_23 ( V_177 , V_113 ,
( L_71 ) ) ;
if ( F_25 ( V_14 , V_262 ) == true ) {
if ( V_29 -> V_21 . V_338 != V_14 -> V_20 . V_21 . V_338 )
continue;
}
if ( ! F_52 ( V_8 , V_29 -> V_21 . V_338 ) ) {
V_140 = - 1 ;
F_64 ( & V_330 -> V_335 ) ;
goto exit;
}
break;
}
}
F_64 ( & V_330 -> V_335 ) ;
F_23 ( V_177 , V_113 ,
( L_72 , V_333 ) ) ;
F_65 ( V_8 , V_333 ) ;
if ( F_83 ( V_8 , & V_389 ) == false ) {
V_140 = - 1 ;
goto exit;
}
}
exit:
F_29 ( L_73 , V_342 , V_140 ) ;
V_217 ;
return V_140 ;
}
static int F_84 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_243 )
{
T_4 V_363 , V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_244 * V_245 = & V_14 -> V_20 . V_21 ;
F_23 ( V_112 , V_113 , ( L_74 ) ) ;
V_167 ;
if ( ( F_25 ( V_14 , V_128 ) ) ||
( F_25 ( V_14 , V_247 ) ) ) {
V_363 = V_245 -> V_53 . V_67 ;
V_10 -> V_366 . V_66 = V_363 ;
memcpy ( V_243 , V_245 -> V_53 . V_53 , V_363 ) ;
V_10 -> V_366 . V_65 = 1 ;
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
T_1 V_393 [ V_394 ] ;
T_4 V_395 = V_10 -> V_101 . V_104 ;
T_4 V_102 = V_10 -> V_101 . V_102 ;
T_4 V_396 = 0 ;
T_1 V_397 [ V_394 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
V_167 ;
F_23 ( V_112 , V_113 , ( L_75 ) ) ;
F_23 ( V_177 , V_113 , ( L_76 , V_395 , V_102 ) ) ;
if ( V_395 == - 1 ) {
V_396 = 11 ;
goto V_398;
}
V_395 = V_395 / 100000 ;
switch ( V_395 ) {
case 10 :
V_396 = 0 ;
break;
case 20 :
V_396 = 1 ;
break;
case 55 :
V_396 = 2 ;
break;
case 60 :
V_396 = 3 ;
break;
case 90 :
V_396 = 4 ;
break;
case 110 :
V_396 = 5 ;
break;
case 120 :
V_396 = 6 ;
break;
case 180 :
V_396 = 7 ;
break;
case 240 :
V_396 = 8 ;
break;
case 360 :
V_396 = 9 ;
break;
case 480 :
V_396 = 10 ;
break;
case 540 :
V_396 = 11 ;
break;
default:
V_396 = 11 ;
break;
}
V_398:
for ( V_4 = 0 ; V_4 < V_394 ; V_4 ++ ) {
if ( V_396 == V_397 [ V_4 ] ) {
V_393 [ V_4 ] = V_397 [ V_4 ] ;
if ( V_102 == 0 )
break;
} else {
V_393 [ V_4 ] = 0xff ;
}
F_23 ( V_177 , V_113 , ( L_77 , V_393 [ V_4 ] ) ) ;
}
if ( F_86 ( V_8 , V_393 ) != V_225 ) {
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
if ( V_10 -> V_399 . V_103 ) {
V_8 -> V_350 . V_400 = 2347 ;
} else {
if ( V_10 -> V_399 . V_104 < 0 ||
V_10 -> V_399 . V_104 > 2347 )
return - V_156 ;
V_8 -> V_350 . V_400 = V_10 -> V_399 . V_104 ;
}
F_29 ( L_79 , V_342 , V_8 -> V_350 . V_400 ) ;
V_217 ;
return 0 ;
}
static int F_90 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_167 ;
F_29 ( L_79 , V_342 , V_8 -> V_350 . V_400 ) ;
V_10 -> V_399 . V_104 = V_8 -> V_350 . V_400 ;
V_10 -> V_399 . V_102 = 0 ;
V_217 ;
return 0 ;
}
static int F_91 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_167 ;
if ( V_10 -> V_401 . V_103 ) {
V_8 -> V_402 . V_403 = V_299 ;
} else {
if ( V_10 -> V_401 . V_104 < V_297 ||
V_10 -> V_401 . V_104 > V_299 )
return - V_156 ;
V_8 -> V_402 . V_403 = V_10 -> V_401 . V_104 & ~ 0x1 ;
}
F_29 ( L_80 , V_342 , V_8 -> V_402 . V_403 ) ;
V_217 ;
return 0 ;
}
static int F_92 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_167 ;
F_29 ( L_80 , V_342 , V_8 -> V_402 . V_403 ) ;
V_10 -> V_401 . V_104 = V_8 -> V_402 . V_403 ;
V_10 -> V_401 . V_102 = 0 ;
V_217 ;
return 0 ;
}
static int F_93 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
V_10 -> V_404 . V_104 = 7 ;
V_10 -> V_404 . V_102 = 0 ;
V_10 -> V_404 . V_103 = 1 ;
return 0 ;
}
static int F_94 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_405 )
{
T_4 V_172 , V_140 = 0 ;
T_4 V_406 ;
struct V_163 V_407 ;
enum V_332 V_333 ;
struct V_408 * V_409 = & ( V_10 -> V_410 ) ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_411 * V_412 = & V_8 -> V_385 ;
F_29 ( L_81 , V_409 -> V_65 ) ;
F_4 ( & V_407 , 0 , sizeof( struct V_163 ) ) ;
V_172 = V_409 -> V_65 & V_413 ;
V_167 ;
if ( V_409 -> V_65 & V_99 ) {
F_29 ( L_82 ) ;
V_8 -> V_143 . V_144 = V_230 ;
V_8 -> V_143 . V_179 = V_229 ;
V_8 -> V_143 . V_181 = V_229 ;
V_8 -> V_143 . V_148 = V_154 ;
V_333 = V_153 ;
V_8 -> V_143 . V_146 = V_333 ;
goto exit;
}
if ( V_172 ) {
if ( V_172 > V_176 )
return - V_156 ;
V_172 -- ;
V_406 = 1 ;
} else {
V_406 = 0 ;
V_172 = V_8 -> V_143 . V_414 ;
F_29 ( L_83 , V_172 ) ;
}
if ( V_409 -> V_65 & V_415 ) {
F_29 ( L_84 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_148 = V_154 ;
V_8 -> V_143 . V_179 = V_229 ;
V_8 -> V_143 . V_181 = V_229 ;
V_333 = V_153 ;
V_8 -> V_143 . V_146 = V_333 ;
} else if ( V_409 -> V_65 & V_416 ) {
F_29 ( L_85 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_148 = V_151 ;
V_8 -> V_143 . V_179 = V_180 ;
V_8 -> V_143 . V_181 = V_180 ;
V_333 = V_150 ;
V_8 -> V_143 . V_146 = V_333 ;
} else {
F_29 ( L_86 , V_409 -> V_65 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_148 = V_154 ;
V_8 -> V_143 . V_179 = V_229 ;
V_8 -> V_143 . V_181 = V_229 ;
V_333 = V_153 ;
V_8 -> V_143 . V_146 = V_333 ;
}
V_407 . V_186 = V_172 ;
if ( V_409 -> V_66 > 0 ) {
V_407 . V_183 = V_409 -> V_66 <= 5 ? 5 : 13 ;
V_407 . V_184 = V_407 . V_183 + F_31 ( struct V_163 , V_182 ) ;
} else {
V_407 . V_183 = 0 ;
if ( V_406 == 1 ) {
V_8 -> V_143 . V_414 = V_172 ;
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
V_407 . V_186 |= 0x80000000 ;
memcpy ( V_407 . V_182 , V_405 , V_407 . V_183 ) ;
if ( F_33 ( V_8 , & V_407 ) == false ) {
if ( V_417 == V_412 -> V_418 )
V_140 = - V_189 ;
goto exit;
}
exit:
V_217 ;
return V_140 ;
}
static int F_95 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_405 )
{
T_5 V_172 , V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_408 * V_409 = & ( V_10 -> V_410 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
V_167 ;
if ( F_25 ( V_14 , V_128 ) != true ) {
if ( ! F_25 ( V_14 , V_247 ) ) {
V_409 -> V_66 = 0 ;
V_409 -> V_65 |= V_99 ;
return 0 ;
}
}
V_172 = V_409 -> V_65 & V_413 ;
if ( V_172 ) {
if ( V_172 > V_176 )
return - V_156 ;
V_172 -- ;
} else {
V_172 = V_8 -> V_143 . V_414 ;
}
V_409 -> V_65 = V_172 + 1 ;
switch ( V_8 -> V_143 . V_144 ) {
case V_419 :
case V_230 :
V_409 -> V_66 = 0 ;
V_409 -> V_65 |= V_99 ;
break;
case V_145 :
V_409 -> V_66 = V_8 -> V_143 . V_192 [ V_172 ] ;
if ( V_409 -> V_66 ) {
memcpy ( V_405 , V_8 -> V_143 . V_190 [ V_172 ] . V_191 , V_8 -> V_143 . V_192 [ V_172 ] ) ;
V_409 -> V_65 |= V_97 ;
if ( V_8 -> V_143 . V_146 == V_153 )
V_409 -> V_65 |= V_415 ;
else if ( V_8 -> V_143 . V_146 == V_150 )
V_409 -> V_65 |= V_416 ;
} else {
V_409 -> V_66 = 0 ;
V_409 -> V_65 |= V_99 ;
}
break;
case V_203 :
case V_204 :
V_409 -> V_66 = 16 ;
V_409 -> V_65 |= ( V_97 | V_415 | V_98 ) ;
break;
default:
V_409 -> V_66 = 0 ;
V_409 -> V_65 |= V_99 ;
break;
}
V_217 ;
return V_140 ;
}
static int F_96 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
V_10 -> V_420 . V_104 = 0 ;
V_10 -> V_420 . V_102 = 0 ;
V_10 -> V_420 . V_103 = 1 ;
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
struct V_421 * V_158 = (struct V_421 * ) & ( V_10 -> V_158 ) ;
int V_140 = 0 ;
switch ( V_158 -> V_65 & V_422 ) {
case V_423 :
break;
case V_424 :
break;
case V_425 :
break;
case V_426 :
break;
case V_427 :
if ( V_158 -> V_104 ) {
V_8 -> V_143 . V_428 = true ;
} else {
V_8 -> V_143 . V_428 = false ;
}
break;
case V_429 :
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
case V_430 :
if ( F_25 ( & V_8 -> V_15 , V_128 ) ) {
F_99 ( V_8 ) ;
F_100 ( V_8 , 500 , false ) ;
F_29 ( L_88 , V_342 ) ;
F_101 ( V_8 ) ;
F_102 ( V_8 , 1 ) ;
}
V_140 = F_27 ( V_139 , ( T_4 ) V_158 -> V_104 ) ;
break;
case V_431 :
break;
case V_432 :
break;
case V_433 :
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
char * V_434 ;
T_4 V_159 ;
struct V_157 * V_158 = NULL ;
struct V_408 * V_435 = & V_10 -> V_410 ;
struct V_436 * V_437 = (struct V_436 * ) V_243 ;
int V_140 = 0 ;
V_159 = sizeof( struct V_157 ) + V_437 -> V_173 ;
V_158 = (struct V_157 * ) F_32 ( V_159 ) ;
if ( V_158 == NULL )
return - 1 ;
F_4 ( V_158 , 0 , V_159 ) ;
V_158 -> V_60 = V_438 ;
F_4 ( V_158 -> V_174 , 0xff , V_23 ) ;
switch ( V_437 -> V_170 ) {
case V_439 :
V_434 = L_32 ;
break;
case V_440 :
V_434 = L_25 ;
break;
case V_441 :
V_434 = L_33 ;
break;
case V_442 :
V_434 = L_89 ;
break;
default:
return - 1 ;
}
strncpy ( ( char * ) V_158 -> V_61 . V_168 . V_170 , V_434 , V_171 ) ;
if ( V_437 -> V_443 & V_444 )
V_158 -> V_61 . V_168 . V_187 = 1 ;
if ( ( V_437 -> V_170 != V_440 ) &&
( V_437 -> V_443 & V_445 ) )
V_158 -> V_61 . V_168 . V_187 = 0 ;
V_158 -> V_61 . V_168 . V_175 = ( V_435 -> V_65 & 0x00FF ) - 1 ;
if ( V_437 -> V_443 & V_446 )
memcpy ( V_158 -> V_61 . V_168 . V_447 , V_437 -> V_448 , 8 ) ;
if ( V_437 -> V_173 ) {
V_158 -> V_61 . V_168 . V_173 = V_437 -> V_173 ;
memcpy ( V_158 -> V_61 . V_168 . V_172 , V_437 + 1 , V_437 -> V_173 ) ;
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
struct V_408 * V_39 ;
T_2 V_363 ;
T_4 V_3 ;
T_4 V_449 ;
T_4 V_450 ;
T_1 * V_451 ;
V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_39 = & V_10 -> V_64 ;
V_363 = V_39 -> V_66 ;
V_451 = ( T_1 * ) F_32 ( V_363 ) ;
if ( NULL == V_451 )
return - V_223 ;
if ( F_106 ( V_451 , V_39 -> V_452 , V_363 ) ) {
F_40 ( V_451 ) ;
return - V_453 ;
}
V_450 = 0 ;
V_3 = 0 ;
sscanf ( V_451 , L_91 , & V_450 , & V_3 ) ;
switch ( V_450 ) {
case 1 :
V_449 = F_107 ( V_8 , V_3 ) ;
sprintf ( V_243 , L_92 , V_449 ) ;
break;
case 2 :
V_449 = F_108 ( V_8 , V_3 ) ;
sprintf ( V_243 , L_93 , V_449 ) ;
break;
case 4 :
V_449 = F_109 ( V_8 , V_3 ) ;
sprintf ( V_243 , L_94 , V_449 ) ;
break;
default:
F_29 ( V_454 L_95 , V_342 ) ;
return - V_156 ;
}
F_29 ( V_454 L_96 , V_342 , V_3 , V_243 ) ;
F_40 ( V_451 ) ;
return 0 ;
}
static int F_110 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_3 ;
T_4 V_449 ;
T_4 V_450 ;
V_450 = 0 ;
V_3 = 0 ;
V_449 = 0 ;
sscanf ( V_243 , L_97 , & V_450 , & V_3 , & V_449 ) ;
switch ( V_450 ) {
case 1 :
F_111 ( V_8 , V_3 , ( T_1 ) V_449 ) ;
F_29 ( V_454 L_98 , V_342 , V_3 , ( T_1 ) V_449 ) ;
break;
case 2 :
F_112 ( V_8 , V_3 , ( T_2 ) V_449 ) ;
F_29 ( V_454 L_99 , V_342 , V_3 , ( T_2 ) V_449 ) ;
break;
case 4 :
F_113 ( V_8 , V_3 , V_449 ) ;
F_29 ( V_454 L_100 , V_342 , V_3 , V_449 ) ;
break;
default:
F_29 ( V_454 L_101 , V_342 ) ;
return - V_156 ;
}
return 0 ;
}
static int F_114 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_455 , V_3 , V_449 ;
V_455 = * ( T_4 * ) V_243 ;
V_3 = * ( ( T_4 * ) V_243 + 1 ) ;
V_449 = F_115 ( V_8 , V_455 , V_3 , 0xFFFFF ) ;
sprintf ( V_243 , L_102 , V_449 ) ;
return 0 ;
}
static int F_116 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_455 , V_3 , V_449 ;
V_455 = * ( T_4 * ) V_243 ;
V_3 = * ( ( T_4 * ) V_243 + 1 ) ;
V_449 = * ( ( T_4 * ) V_243 + 2 ) ;
F_117 ( V_8 , V_455 , V_3 , 0xFFFFF , V_449 ) ;
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
T_1 V_456 = ( T_1 ) ( * ( ( int * ) V_10 ) ) ;
if ( V_225 == F_121 ( V_8 , V_456 , 1 ) )
F_29 ( L_103 , V_342 , V_14 -> V_457 ) ;
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
static void F_126 ( struct V_7 * V_8 , T_4 V_458 , T_1 * V_459 , T_4 V_363 )
{
struct V_460 * V_461 ;
struct V_462 * V_463 ;
T_1 V_455 ;
T_1 V_464 ;
T_4 V_104 ;
F_29 ( L_57 , V_342 ) ;
switch ( V_458 ) {
case F_127 ( V_465 ) :
F_29 ( L_104 ) ;
break;
case F_127 ( V_466 ) :
V_461 = (struct V_460 * ) V_459 ;
switch ( V_461 -> V_467 ) {
case 1 :
V_461 -> V_104 = F_107 ( V_8 , V_461 -> V_464 ) ;
break;
case 2 :
V_461 -> V_104 = F_108 ( V_8 , V_461 -> V_464 ) ;
break;
case 4 :
V_461 -> V_104 = F_109 ( V_8 , V_461 -> V_464 ) ;
break;
default:
break;
}
break;
case F_127 ( V_468 ) :
V_461 = (struct V_460 * ) V_459 ;
switch ( V_461 -> V_467 ) {
case 1 :
F_111 ( V_8 , V_461 -> V_464 , ( T_1 ) V_461 -> V_104 ) ;
break;
case 2 :
F_112 ( V_8 , V_461 -> V_464 , ( T_2 ) V_461 -> V_104 ) ;
break;
case 4 :
F_113 ( V_8 , V_461 -> V_464 , ( T_4 ) V_461 -> V_104 ) ;
break;
default:
break;
}
break;
case F_127 ( V_469 ) :
V_463 = (struct V_462 * ) V_459 ;
V_455 = ( T_1 ) V_463 -> V_455 ;
V_464 = ( T_1 ) V_463 -> V_464 ;
V_104 = F_115 ( V_8 , V_455 , V_464 , 0xffffffff ) ;
V_463 -> V_104 = V_104 ;
break;
case F_127 ( V_470 ) :
V_463 = (struct V_462 * ) V_459 ;
V_455 = ( T_1 ) V_463 -> V_455 ;
V_464 = ( T_1 ) V_463 -> V_464 ;
V_104 = V_463 -> V_104 ;
F_117 ( V_8 , V_455 , V_464 , 0xffffffff , V_104 ) ;
break;
case F_127 ( V_471 ) :
F_29 ( L_105 ) ;
F_128 ( V_8 , V_472 , NULL ) ;
break;
case F_127 ( V_473 ) :
* V_459 = F_129 ( V_8 ) ;
break;
default:
break;
}
}
static int F_130 ( struct V_138 * V_139 , struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
T_4 V_474 , V_475 , V_476 ;
struct V_477 V_478 ;
struct V_479 * V_480 ;
struct V_481 * V_482 ;
T_5 V_483 = 0 ;
T_2 V_363 ;
T_1 * V_484 = NULL , V_485 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_408 * V_39 = & V_10 -> V_64 ;
if ( ( ! V_39 -> V_66 ) || ( ! V_39 -> V_452 ) ) {
V_140 = - V_156 ;
goto V_486;
}
V_484 = NULL ;
V_485 = ( T_1 ) ( V_39 -> V_65 & 0xFFFF ) ;
V_363 = V_39 -> V_66 ;
V_484 = ( T_1 * ) F_32 ( V_363 ) ;
if ( V_484 == NULL ) {
V_140 = - V_223 ;
goto V_486;
}
if ( F_106 ( V_484 , V_39 -> V_452 , V_363 ) ) {
V_140 = - V_453 ;
goto V_486;
}
V_482 = (struct V_481 * ) V_484 ;
F_23 ( V_177 , V_113 ,
( L_106 ,
V_482 -> V_487 , V_482 -> V_363 , V_363 ) ) ;
if ( V_482 -> V_487 >= F_131 ( V_488 ) ) {
F_23 ( V_177 , V_178 , ( L_107 ) ) ;
V_140 = - V_156 ;
goto V_486;
}
if ( V_8 -> V_350 . V_351 == 1 ) {
V_480 = V_488 + V_482 -> V_487 ;
if ( ( V_480 -> V_489 != 0 ) && ( V_482 -> V_363 < V_480 -> V_489 ) ) {
F_23 ( V_177 , V_178 ,
( L_108 ,
V_482 -> V_363 , V_480 -> V_489 ) ) ;
V_140 = - V_156 ;
goto V_486;
}
if ( V_480 -> V_490 ) {
V_478 . V_491 = V_8 ;
V_478 . V_492 = V_480 -> V_492 ;
V_478 . V_493 = V_482 -> V_64 ;
V_478 . V_494 = V_482 -> V_363 ;
V_478 . V_495 = 0 ;
V_475 = 0 ;
V_476 = 0 ;
if ( V_485 ) {
V_478 . V_496 = & V_474 ;
V_478 . V_497 = & V_476 ;
V_478 . V_498 = V_499 ;
} else {
V_478 . V_496 = & V_475 ;
V_478 . V_497 = & V_476 ;
V_478 . V_498 = V_500 ;
}
V_483 = V_480 -> V_490 ( & V_478 ) ;
} else {
F_29 ( L_109 ,
V_482 -> V_487 , V_480 -> V_492 , V_480 -> V_490 ) ;
V_140 = - V_453 ;
goto V_486;
}
} else {
F_126 ( V_8 , V_482 -> V_487 , V_482 -> V_64 , V_482 -> V_363 ) ;
}
if ( V_485 == 0x00 ) {
if ( F_132 ( V_39 -> V_452 , V_484 , V_363 ) )
V_140 = - V_453 ;
}
if ( V_483 ) {
V_140 = - V_453 ;
goto V_486;
}
V_486:
F_40 ( V_484 ) ;
return V_140 ;
}
static int F_133 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
T_4 V_116 = 0 , V_501 ;
struct V_325 * V_381 , * V_326 ;
unsigned char * V_502 ;
T_1 V_270 [ V_23 ] ;
char V_64 [ 32 ] ;
struct V_28 * V_29 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_408 * V_459 = & V_10 -> V_64 ;
F_29 ( L_110 ) ;
if ( ( V_8 -> V_352 ) || ( V_459 == NULL ) ) {
V_140 = - V_156 ;
goto exit;
}
while ( ( F_25 ( V_14 , ( V_355 | V_356 ) ) ) ) {
F_79 ( 30 ) ;
V_116 ++ ;
if ( V_116 > 100 )
break;
}
V_459 -> V_65 = 0 ;
if ( V_459 -> V_66 >= 32 ) {
if ( F_106 ( V_64 , V_459 -> V_452 , 32 ) ) {
V_140 = - V_156 ;
goto exit;
}
} else {
V_140 = - V_156 ;
goto exit;
}
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) == true )
break;
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
if ( F_2 ( V_64 , V_270 ) ) {
F_29 ( L_111 , ( T_1 * ) V_64 ) ;
F_64 ( & V_14 -> V_331 . V_335 ) ;
return - V_156 ;
}
if ( ! memcmp ( V_270 , V_29 -> V_21 . V_22 , V_23 ) ) {
F_29 ( L_112 , ( V_270 ) ) ;
V_502 = F_134 ( & V_29 -> V_21 . V_58 [ 12 ] , & V_501 , V_29 -> V_21 . V_59 - 12 ) ;
if ( V_502 && ( V_501 > 0 ) ) {
V_459 -> V_65 = 1 ;
break;
}
V_502 = F_135 ( & V_29 -> V_21 . V_58 [ 12 ] , & V_501 , V_29 -> V_21 . V_59 - 12 ) ;
if ( V_502 && ( V_501 > 0 ) ) {
V_459 -> V_65 = 2 ;
break;
}
}
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
if ( V_459 -> V_66 >= 34 ) {
if ( F_132 ( V_459 -> V_452 + 32 , ( T_1 * ) & V_459 -> V_65 , 1 ) ) {
V_140 = - V_156 ;
goto exit;
}
}
exit:
return V_140 ;
}
static int F_136 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
int * V_459 = ( int * ) V_10 ;
int V_503 ;
if ( ( V_8 -> V_352 ) || ( V_459 == NULL ) ) {
V_140 = - V_156 ;
goto exit;
}
V_503 = * V_459 ;
if ( V_503 < 3 && V_503 >= 0 ) {
V_8 -> V_504 [ V_503 ] = * ( V_459 + 1 ) ;
V_505 [ V_503 ] = * ( V_459 + 1 ) ;
F_29 ( L_113 , V_342 , V_503 , V_8 -> V_504 [ V_503 ] ) ;
} else {
F_29 ( L_114 , V_342 , V_503 ) ;
}
exit:
return V_140 ;
}
static int F_137 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_408 * V_459 = & V_10 -> V_64 ;
T_4 V_506 = 0 ;
V_140 = F_106 ( ( void * ) & V_506 , V_459 -> V_452 , 4 ) ;
if ( V_140 ) {
V_140 = - V_156 ;
goto exit;
}
if ( ( V_8 -> V_352 ) || ( V_459 == NULL ) ) {
V_140 = - V_156 ;
goto exit;
}
if ( V_506 == 0 )
V_506 = * V_243 ;
F_29 ( L_115 , V_342 , V_506 ) ;
if ( V_506 == 1 )
F_138 ( V_8 , V_507 ) ;
else if ( V_506 == 2 )
F_138 ( V_8 , V_508 ) ;
else if ( V_506 == 3 )
F_138 ( V_8 , V_509 ) ;
exit:
return V_140 ;
}
static int F_139 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
struct V_286 * V_287 = & V_8 -> V_249 ;
enum V_510 V_511 = V_512 ;
if ( * V_243 == '0' )
V_511 = V_512 ;
else if ( * V_243 == '1' )
V_511 = V_513 ;
else if ( * V_243 == '2' )
V_511 = V_514 ;
else if ( * V_243 == '3' )
V_511 = V_515 ;
if ( V_188 == F_140 ( V_8 , V_511 ) ) {
V_140 = - V_453 ;
goto exit;
}
if ( V_511 != V_512 ) {
T_1 V_516 , V_517 ;
T_2 V_518 ;
if ( F_11 ( V_49 , V_519 ) ) {
V_516 = V_49 -> V_520 ;
V_49 -> V_521 = V_49 -> V_520 ;
V_517 = V_522 ;
V_518 = V_523 ;
} else {
V_49 -> V_521 = V_287 -> V_250 ;
V_516 = V_49 -> V_521 ;
V_517 = V_287 -> V_524 ;
V_518 = V_287 -> V_525 ;
}
F_141 ( V_8 , V_516 , V_517 , V_518 ) ;
}
exit:
return V_140 ;
}
static int F_142 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_116 , V_342 , V_243 , strlen ( V_243 ) ) ;
memcpy ( V_49 -> V_526 , V_243 , strlen ( V_243 ) ) ;
V_49 -> V_527 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_143 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_528 = V_49 -> V_528 ;
switch ( V_10 -> V_64 . V_66 ) {
case 1 :
V_528 = V_243 [ 0 ] - '0' ;
break;
case 2 :
V_528 = F_144 ( V_243 [ 0 ] , V_243 [ 1 ] ) ;
break;
}
if ( V_528 <= 15 )
V_49 -> V_528 = V_528 ;
else
V_140 = - 1 ;
F_29 ( L_117 , V_342 , V_528 ) ;
return V_140 ;
}
static int F_145 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_529 = V_49 -> V_520 ;
switch ( V_10 -> V_64 . V_66 ) {
case 1 :
V_529 = V_243 [ 0 ] - '0' ;
break;
case 2 :
V_529 = F_144 ( V_243 [ 0 ] , V_243 [ 1 ] ) ;
break;
}
if ( ( V_529 == 1 ) || ( V_529 == 6 ) || ( V_529 == 11 ) ) {
V_49 -> V_520 = V_529 ;
F_141 ( V_8 , V_49 -> V_520 , V_522 , V_523 ) ;
} else {
V_140 = - 1 ;
}
F_29 ( L_118 , V_342 , V_49 -> V_520 ) ;
return V_140 ;
}
static int F_146 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_530 = V_49 -> V_521 ;
switch ( V_10 -> V_64 . V_66 ) {
case 1 :
V_530 = V_243 [ 0 ] - '0' ;
break;
case 2 :
V_530 = F_144 ( V_243 [ 0 ] , V_243 [ 1 ] ) ;
break;
}
if ( V_530 > 0 )
V_49 -> V_521 = V_530 ;
else
V_140 = - 1 ;
F_29 ( L_119 , V_342 , V_49 -> V_521 ) ;
return V_140 ;
}
static int F_147 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_120 , V_342 , V_243 , V_10 -> V_64 . V_66 - 1 ) ;
if ( ! F_11 ( V_49 , V_51 ) ) {
if ( V_243 [ 0 ] == '0' ) {
F_4 ( & V_49 -> V_531 [ 0 ] , 0x00 , sizeof( struct V_532 ) * V_533 ) ;
V_49 -> V_534 = 0 ;
} else {
if ( V_49 -> V_534 >= V_533 ) {
V_140 = - 1 ;
} else {
int V_535 , V_536 ;
for ( V_535 = 0 , V_536 = 1 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_49 -> V_531 [ V_49 -> V_534 ] . V_537 [ V_535 ] = F_148 ( V_243 [ V_536 ] , V_243 [ V_536 + 1 ] ) ;
V_49 -> V_531 [ V_49 -> V_534 ] . V_538 = ( V_243 [ 18 ] - '0' ) * 10 + ( V_243 [ 19 ] - '0' ) ;
memcpy ( V_49 -> V_531 [ V_49 -> V_534 ] . V_348 , & V_243 [ 20 ] , V_49 -> V_531 [ V_49 -> V_534 ] . V_538 ) ;
V_49 -> V_534 ++ ;
}
}
}
return V_140 ;
}
static int F_149 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_121 , V_342 , V_243 , V_10 -> V_64 . V_66 - 1 ) ;
F_4 ( V_49 -> V_539 , 0x00 , V_540 ) ;
memcpy ( V_49 -> V_539 , V_243 , V_10 -> V_64 . V_66 - 1 ) ;
V_49 -> V_541 = V_10 -> V_64 . V_66 - 1 ;
return V_140 ;
}
static int F_150 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
if ( V_8 -> V_542 )
F_29 ( L_122 , V_342 , F_151 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_543 [ 0 ] , V_49 -> V_543 [ 1 ] , V_49 -> V_543 [ 2 ] ,
V_49 -> V_543 [ 3 ] , V_49 -> V_543 [ 4 ] , V_49 -> V_543 [ 5 ] ) ;
sprintf ( V_243 , L_123 , F_72 ( V_49 ) ) ;
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
sprintf ( V_243 , L_124 , V_49 -> V_544 . V_545 ) ;
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
F_29 ( L_122 , V_342 , F_151 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_543 [ 0 ] , V_49 -> V_543 [ 1 ] , V_49 -> V_543 [ 2 ] ,
V_49 -> V_543 [ 3 ] , V_49 -> V_543 [ 4 ] , V_49 -> V_543 [ 5 ] ) ;
sprintf ( V_243 , L_125 , F_151 ( V_49 ) ) ;
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
F_29 ( L_126 , V_342 ,
F_151 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_543 ) ;
sprintf ( V_243 , L_127 ,
V_49 -> V_543 ) ;
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
F_29 ( L_126 , V_342 ,
F_151 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_544 . V_546 ) ;
sprintf ( V_243 , L_128 ,
V_49 -> V_544 . V_546 ) ;
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
F_29 ( L_126 ,
V_342 , F_151 ( V_49 ) , F_72 ( V_49 ) ,
V_49 -> V_547 ) ;
sprintf ( V_243 , L_127 ,
V_49 -> V_547 ) ;
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
sprintf ( V_243 , L_129 ,
V_49 -> V_548 . V_549 [ 0 ] , V_49 -> V_548 . V_549 [ 1 ] ,
V_49 -> V_548 . V_549 [ 2 ] , V_49 -> V_548 . V_549 [ 3 ] ,
V_49 -> V_548 . V_549 [ 4 ] , V_49 -> V_548 . V_549 [ 5 ] ,
V_49 -> V_548 . V_348 ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_158 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_130 , V_342 , V_49 -> V_521 ) ;
sprintf ( V_243 , L_131 , V_49 -> V_521 ) ;
V_10 -> V_64 . V_66 = strlen ( V_243 ) ;
return V_140 ;
}
static int F_159 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_325 * V_381 , * V_326 ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_2 V_553 = 0 ;
T_5 V_554 = 0 ;
T_1 V_555 [ 6 + 17 ] = { 0x00 } ;
F_29 ( L_132 , V_342 , ( char * ) V_243 ) ;
if ( F_106 ( V_551 , V_10 -> V_64 . V_452 + 6 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_148 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) == true )
break;
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
T_1 * V_556 ;
T_5 V_557 = 0 ;
T_7 V_558 ;
V_556 = F_160 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_557 ) ;
if ( V_556 ) {
F_161 ( V_556 , V_557 , V_559 , ( T_1 * ) & V_558 , & V_554 ) ;
if ( V_554 ) {
V_553 = F_162 ( V_558 ) ;
sprintf ( V_555 , L_133 , V_553 ) ;
V_552 = 1 ;
}
}
break;
}
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
if ( ! V_552 )
sprintf ( V_555 , L_134 ) ;
if ( F_132 ( V_10 -> V_64 . V_452 , V_555 , 6 + 17 ) )
return - V_453 ;
return V_140 ;
}
static int F_163 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_325 * V_381 , * V_326 ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_1 * V_560 ;
T_5 V_56 = 0 , V_554 = 0 ;
T_1 V_553 [ 100 ] = { 0x00 } ;
T_1 V_561 [ 17 + 12 ] = {} ;
F_29 ( L_132 , V_342 , ( char * ) V_243 ) ;
if ( F_106 ( V_551 , V_10 -> V_64 . V_452 + 10 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_148 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) == true )
break;
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
V_560 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_560 ) {
while ( V_560 ) {
F_4 ( V_553 , 0x00 , 100 ) ;
if ( F_164 ( V_560 , V_56 , V_562 , V_553 , & V_554 ) ) {
V_552 = 1 ;
break;
} else if ( F_164 ( V_560 , V_56 , V_563 , V_553 , & V_554 ) ) {
V_552 = 1 ;
break;
}
V_560 = F_12 ( V_560 + V_56 , V_29 -> V_21 . V_59 - 12 - ( V_560 - & V_29 -> V_21 . V_58 [ 12 ] + V_56 ) , NULL , & V_56 ) ;
}
}
}
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
if ( ! V_552 )
snprintf ( V_561 , sizeof( V_561 ) , L_135 ) ;
else
snprintf ( V_561 , sizeof( V_561 ) , L_136 ,
V_553 [ 0 ] , V_553 [ 1 ] , V_553 [ 2 ] , V_553 [ 3 ] , V_553 [ 4 ] , V_553 [ 5 ] ) ;
if ( F_132 ( V_10 -> V_64 . V_452 , V_561 , sizeof( V_561 ) ) )
return - V_453 ;
return V_140 ;
}
static int F_165 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_325 * V_381 , * V_326 ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_1 V_564 [ 8 ] = { 0x00 } ;
T_5 V_565 = 0 ;
T_1 V_566 [ 17 + 9 ] = { 0x00 } ;
F_29 ( L_132 , V_342 , ( char * ) V_243 ) ;
if ( F_106 ( V_551 , V_10 -> V_64 . V_452 + 9 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_148 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) == true )
break;
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
T_1 * V_556 ;
T_5 V_557 = 0 ;
V_556 = F_160 ( & V_29 -> V_21 . V_58 [ 12 ] ,
V_29 -> V_21 . V_59 - 12 ,
NULL , & V_557 ) ;
if ( V_556 ) {
F_161 ( V_556 , V_557 , V_567 , V_564 , & V_565 ) ;
if ( V_565 ) {
T_2 type = 0 ;
T_7 V_558 ;
memcpy ( & V_558 , V_564 , 2 ) ;
type = F_162 ( V_558 ) ;
sprintf ( V_566 , L_137 , type ) ;
V_552 = 1 ;
}
}
break;
}
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
if ( ! V_552 )
sprintf ( V_566 , L_138 ) ;
if ( F_132 ( V_10 -> V_64 . V_452 , V_566 , 9 + 17 ) ) {
return - V_453 ;
}
return V_140 ;
}
static int F_166 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_325 * V_381 , * V_326 ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_1 V_568 [ V_540 ] = { 0x00 } ;
T_5 V_569 = 0 ;
T_1 V_570 [ V_540 + 5 ] = { 0x00 } ;
F_29 ( L_132 , V_342 , ( char * ) V_243 ) ;
if ( F_106 ( V_551 , V_10 -> V_64 . V_452 + 5 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_148 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) == true )
break;
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
T_1 * V_556 ;
T_5 V_557 = 0 ;
V_556 = F_160 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_557 ) ;
if ( V_556 ) {
F_161 ( V_556 , V_557 , V_571 , V_568 , & V_569 ) ;
if ( V_569 ) {
sprintf ( V_570 , L_139 , V_568 ) ;
V_552 = 1 ;
}
}
break;
}
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
if ( ! V_552 )
sprintf ( V_570 , L_140 ) ;
if ( F_132 ( V_10 -> V_64 . V_452 , V_570 , 5 + ( ( V_569 > 17 ) ? V_569 : 17 ) ) )
return - V_453 ;
return V_140 ;
}
static int F_167 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_325 * V_381 , * V_326 ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_1 * V_560 ;
T_5 V_56 = 0 , V_554 = 0 ;
T_1 V_553 [ 2 ] = { 0x00 } ;
T_1 V_572 [ 17 + 8 ] = { 0x00 } ;
F_29 ( L_132 , V_342 , ( char * ) V_243 ) ;
if ( F_106 ( V_551 , V_10 -> V_64 . V_452 + 8 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_148 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) == true )
break;
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
V_560 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_560 ) {
while ( V_560 ) {
if ( F_164 ( V_560 , V_56 , V_573 , V_553 , & V_554 ) ) {
V_552 = 1 ;
break;
}
V_560 = F_12 ( V_560 + V_56 , V_29 -> V_21 . V_59 - 12 - ( V_560 - & V_29 -> V_21 . V_58 [ 12 ] + V_56 ) , NULL , & V_56 ) ;
}
}
}
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
if ( ! V_552 ) {
sprintf ( V_572 , L_141 ) ;
} else {
if ( V_553 [ 0 ] & 0x20 )
sprintf ( V_572 , L_142 ) ;
else
sprintf ( V_572 , L_143 ) ;
}
if ( F_132 ( V_10 -> V_64 . V_452 , V_572 , 8 + 17 ) )
return - V_453 ;
return V_140 ;
}
static int F_168 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_325 * V_381 , * V_326 ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
T_5 V_574 = 0 ;
F_29 ( L_132 , V_342 , V_243 ) ;
if ( V_49 -> V_357 == V_51 ) {
F_29 ( L_144 , V_342 ) ;
return V_140 ;
}
if ( V_49 -> V_575 == V_576 )
return - 1 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_148 ( V_243 [ V_536 ] , V_243 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) == true )
break;
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
if ( V_574 ) {
F_4 ( & V_49 -> V_577 , 0x00 , sizeof( struct V_578 ) ) ;
F_4 ( & V_49 -> V_548 , 0x00 , sizeof( struct V_579 ) ) ;
V_49 -> V_577 . V_580 [ 0 ] = V_574 ;
memcpy ( V_49 -> V_577 . V_546 , V_29 -> V_21 . V_22 , V_23 ) ;
V_49 -> V_577 . V_581 = true ;
F_169 ( & V_49 -> V_582 ) ;
if ( F_72 ( V_49 ) != V_242 ) {
F_38 ( V_49 , V_519 ) ;
}
F_71 ( V_49 , F_72 ( V_49 ) ) ;
F_38 ( V_49 , V_583 ) ;
F_29 ( L_145 , V_342 ) ;
F_170 ( & V_49 -> V_584 , V_585 ) ;
F_170 ( & V_49 -> V_582 , V_586 ) ;
} else {
F_29 ( L_146 , V_342 ) ;
V_140 = - 1 ;
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
int V_535 , V_536 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_325 * V_381 , * V_326 ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
T_5 V_574 = 0 ;
T_1 V_553 [ 50 ] = { 0x00 } ;
T_1 * V_560 ;
T_5 V_56 = 0 , V_554 = 0 ;
struct V_587 * V_588 = & V_49 -> V_589 ;
F_29 ( L_132 , V_342 , V_243 ) ;
if ( V_10 -> V_64 . V_66 <= 37 ) {
F_29 ( L_147 , V_342 ) ;
return V_140 ;
}
if ( F_11 ( V_49 , V_51 ) ) {
F_29 ( L_144 , V_342 ) ;
return V_140 ;
} else {
V_588 -> V_581 = false ;
F_4 ( V_588 -> V_590 , 0x00 , V_23 ) ;
F_4 ( V_588 -> V_591 , 0x00 , V_592 ) ;
V_588 -> V_538 = 0x00 ;
V_588 -> V_593 = V_49 -> V_521 ;
F_4 ( V_588 -> V_594 , 0x00 , V_23 ) ;
V_588 -> V_595 = 3 ;
}
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_588 -> V_594 [ V_535 ] = F_148 ( V_243 [ V_536 ] , V_243 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) == true )
break;
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
V_560 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_560 ) {
if ( F_164 ( V_560 , V_56 , V_562 , V_553 , & V_554 ) ) {
if ( ! memcmp ( V_553 , V_588 -> V_594 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
} else if ( F_164 ( V_560 , V_56 , V_563 , V_553 , & V_554 ) ) {
if ( ! memcmp ( V_553 , V_588 -> V_594 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
}
}
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
if ( V_574 ) {
for ( V_535 = 0 , V_536 = 18 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_588 -> V_590 [ V_535 ] = F_148 ( V_243 [ V_536 ] , V_243 [ V_536 + 1 ] ) ;
V_588 -> V_538 = V_10 -> V_64 . V_66 - 36 ;
memcpy ( V_588 -> V_591 , & V_243 [ 36 ] , ( T_4 ) V_588 -> V_538 ) ;
V_588 -> V_581 = true ;
V_588 -> V_596 = V_574 ;
F_71 ( V_49 , F_72 ( V_49 ) ) ;
F_38 ( V_49 , V_597 ) ;
F_141 ( V_8 , V_574 , V_522 , V_523 ) ;
F_170 ( & V_49 -> V_584 , V_585 ) ;
F_170 ( & V_49 -> V_582 , V_598 ) ;
} else {
F_29 ( L_148 , V_342 ) ;
}
return V_140 ;
}
static int F_172 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_132 , V_342 , V_243 ) ;
if ( F_11 ( V_49 , V_51 ) ) {
F_29 ( L_144 , V_342 ) ;
return V_140 ;
} else {
if ( V_243 [ 0 ] == '0' )
V_49 -> V_599 = false ;
else if ( V_243 [ 0 ] == '1' )
V_49 -> V_599 = true ;
else
V_49 -> V_599 = false ;
}
F_173 ( L_149 , V_342 , V_49 -> V_599 ) ;
return V_140 ;
}
static int F_174 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_325 * V_381 , * V_326 ;
struct V_329 * V_330 = & ( V_14 -> V_331 ) ;
struct V_28 * V_29 = NULL ;
T_5 V_574 = 0 ;
T_1 V_553 [ 100 ] = { 0x00 } ;
T_1 * V_560 ;
T_5 V_56 = 0 , V_554 = 0 ;
F_29 ( L_132 , V_342 , V_243 ) ;
if ( V_49 -> V_357 == V_51 ) {
F_29 ( L_144 , V_342 ) ;
return V_140 ;
} else {
F_4 ( V_49 -> V_600 . V_546 , 0x00 , V_23 ) ;
F_4 ( V_49 -> V_600 . V_601 , 0x00 , V_23 ) ;
F_4 ( & V_49 -> V_600 . V_348 , 0x00 , sizeof( struct V_347 ) ) ;
V_49 -> V_600 . V_580 [ 0 ] = 0 ;
V_49 -> V_600 . V_580 [ 1 ] = 0 ;
V_49 -> V_600 . V_581 = false ;
}
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_148 ( V_243 [ V_536 ] , V_243 [ V_536 + 1 ] ) ;
if ( ! memcmp ( & V_243 [ 18 ] , L_150 , 7 ) ) {
V_49 -> V_600 . V_602 = V_603 ;
} else if ( ! memcmp ( & V_243 [ 18 ] , L_151 , 7 ) ) {
V_49 -> V_600 . V_602 = V_604 ;
} else if ( ! memcmp ( & V_243 [ 18 ] , L_152 , 3 ) ) {
V_49 -> V_600 . V_602 = V_605 ;
} else if ( ! memcmp ( & V_243 [ 18 ] , L_153 , 5 ) ) {
V_49 -> V_600 . V_602 = V_606 ;
} else {
F_29 ( L_154 , V_342 ) ;
return V_140 ;
}
F_59 ( & ( V_14 -> V_331 . V_335 ) ) ;
V_326 = F_60 ( V_330 ) ;
V_381 = F_61 ( V_326 ) ;
while ( 1 ) {
if ( F_62 ( V_326 , V_381 ) == true )
break;
if ( V_574 != 0 )
break;
V_29 = F_63 ( V_381 , struct V_28 , V_337 ) ;
V_560 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_560 ) {
while ( V_560 ) {
if ( F_164 ( V_560 , V_56 , V_562 , V_553 , & V_554 ) ) {
if ( ! memcmp ( V_553 , V_550 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
} else if ( F_164 ( V_560 , V_56 , V_563 , V_553 , & V_554 ) ) {
if ( ! memcmp ( V_553 , V_550 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
}
V_560 = F_12 ( V_560 + V_56 , V_29 -> V_21 . V_59 - 12 - ( V_560 - & V_29 -> V_21 . V_58 [ 12 ] + V_56 ) , NULL , & V_56 ) ;
}
}
V_381 = F_61 ( V_381 ) ;
}
F_64 ( & V_14 -> V_331 . V_335 ) ;
if ( V_574 ) {
F_29 ( L_155 , V_342 , V_574 ) ;
memcpy ( V_49 -> V_600 . V_601 , V_29 -> V_21 . V_22 , V_23 ) ;
memcpy ( V_49 -> V_600 . V_546 , V_550 , V_23 ) ;
V_49 -> V_600 . V_580 [ 0 ] = ( T_2 ) V_574 ;
V_49 -> V_600 . V_581 = true ;
F_71 ( V_49 , F_72 ( V_49 ) ) ;
F_38 ( V_49 , V_607 ) ;
if ( F_175 ( V_49 , V_514 ) ) {
memcpy ( & V_49 -> V_600 . V_348 , & V_29 -> V_21 . V_53 , sizeof( struct V_347 ) ) ;
} else if ( F_175 ( V_49 , V_513 ) || F_175 ( V_49 , V_515 ) ) {
memcpy ( V_49 -> V_600 . V_348 . V_53 , V_49 -> V_54 , V_55 ) ;
V_49 -> V_600 . V_348 . V_67 = V_55 ;
}
F_141 ( V_8 , V_574 , V_522 , V_523 ) ;
F_170 ( & V_49 -> V_584 , V_585 ) ;
F_170 ( & V_49 -> V_582 , V_608 ) ;
} else {
F_29 ( L_148 , V_342 ) ;
}
return V_140 ;
}
static int F_176 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_132 , V_342 , V_243 ) ;
if ( * V_243 == '0' )
V_49 -> V_575 = V_576 ;
else if ( * V_243 == '1' )
V_49 -> V_575 = V_609 ;
else if ( * V_243 == '2' )
V_49 -> V_575 = V_610 ;
else if ( * V_243 == '3' )
V_49 -> V_575 = V_611 ;
else
V_49 -> V_575 = V_576 ;
return V_140 ;
}
static int F_177 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
#ifdef F_10
F_29 ( L_156 , V_342 , V_243 ) ;
if ( ! memcmp ( V_243 , L_157 , 7 ) ) {
F_139 ( V_139 , V_27 , V_10 , & V_243 [ 7 ] ) ;
} else if ( ! memcmp ( V_243 , L_158 , 6 ) ) {
V_10 -> V_64 . V_66 -= 6 ;
F_149 ( V_139 , V_27 , V_10 , & V_243 [ 6 ] ) ;
} else if ( ! memcmp ( V_243 , L_159 , 13 ) ) {
V_10 -> V_64 . V_66 -= 13 ;
F_147 ( V_139 , V_27 , V_10 , & V_243 [ 13 ] ) ;
} else if ( ! memcmp ( V_243 , L_160 , 10 ) ) {
V_10 -> V_64 . V_66 -= 10 ;
F_174 ( V_139 , V_27 , V_10 , & V_243 [ 10 ] ) ;
} else if ( ! memcmp ( V_243 , L_161 , 5 ) ) {
V_10 -> V_64 . V_66 -= 5 ;
F_168 ( V_139 , V_27 , V_10 , & V_243 [ 5 ] ) ;
} else if ( ! memcmp ( V_243 , L_162 , 7 ) ) {
V_10 -> V_64 . V_66 -= 8 ;
F_143 ( V_139 , V_27 , V_10 , & V_243 [ 7 ] ) ;
} else if ( ! memcmp ( V_243 , L_163 , 5 ) ) {
V_10 -> V_64 . V_66 -= 5 ;
F_142 ( V_139 , V_27 , V_10 , & V_243 [ 5 ] ) ;
} else if ( ! memcmp ( V_243 , L_164 , 12 ) ) {
V_10 -> V_64 . V_66 -= 12 ;
F_176 ( V_139 , V_27 , V_10 , & V_243 [ 12 ] ) ;
} else if ( ! memcmp ( V_243 , L_165 , 10 ) ) {
V_10 -> V_64 . V_66 -= 11 ;
F_145 ( V_139 , V_27 , V_10 , & V_243 [ 10 ] ) ;
} else if ( ! memcmp ( V_243 , L_166 , 6 ) ) {
V_10 -> V_64 . V_66 -= 7 ;
F_146 ( V_139 , V_27 , V_10 , & V_243 [ 6 ] ) ;
} else if ( ! memcmp ( V_243 , L_167 , 7 ) ) {
V_10 -> V_64 . V_66 -= 8 ;
F_171 ( V_139 , V_27 , V_10 , & V_243 [ 7 ] ) ;
} else if ( ! memcmp ( V_243 , L_168 , 11 ) ) {
V_10 -> V_64 . V_66 -= 11 ;
F_172 ( V_139 , V_27 , V_10 , & V_243 [ 11 ] ) ;
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
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
if ( V_8 -> V_542 )
F_29 ( L_156 , V_342 , ( char * ) V_10 -> V_64 . V_452 ) ;
if ( ! memcmp ( V_10 -> V_64 . V_452 , L_169 , 6 ) ) {
F_150 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_452 , L_170 , 4 ) ) {
F_153 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_452 , L_171 , 8 ) ) {
F_154 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_452 , L_172 , 6 ) ) {
F_152 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_452 , L_173 , 9 ) ) {
F_155 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_452 , L_174 , 8 ) ) {
F_157 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_452 , L_175 , 9 ) ) {
F_156 ( V_139 , V_27 , V_10 , V_243 ) ;
} else if ( ! memcmp ( V_10 -> V_64 . V_452 , L_176 , 5 ) ) {
F_158 ( V_139 , V_27 , V_10 , V_243 ) ;
}
#endif
return V_140 ;
}
static int F_179 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
#ifdef F_10
F_29 ( L_156 , V_342 , ( char * ) V_10 -> V_64 . V_452 ) ;
if ( ! memcmp ( V_243 , L_177 , 6 ) ) {
V_10 -> V_64 . V_66 -= 6 ;
F_159 ( V_139 , V_27 , V_10 , & V_243 [ 6 ] ) ;
} else if ( ! memcmp ( V_243 , L_178 , 5 ) ) {
V_10 -> V_64 . V_66 -= 5 ;
F_166 ( V_139 , V_27 , V_10 , & V_243 [ 5 ] ) ;
} else if ( ! memcmp ( V_243 , L_179 , 9 ) ) {
V_10 -> V_64 . V_66 -= 9 ;
F_165 ( V_139 , V_27 , V_10 , & V_243 [ 9 ] ) ;
} else if ( ! memcmp ( V_243 , L_180 , 10 ) ) {
V_10 -> V_64 . V_66 -= 10 ;
F_163 ( V_139 , V_27 , V_10 , & V_243 [ 10 ] ) ;
} else if ( ! memcmp ( V_243 , L_181 , 8 ) ) {
V_10 -> V_64 . V_66 -= 8 ;
F_167 ( V_139 , V_27 , V_10 , & V_243 [ 8 ] ) ;
}
#endif
return V_140 ;
}
static int F_180 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_182 , V_342 , V_243 ) ;
if ( ! strcmp ( V_243 , L_183 ) )
V_8 -> V_612 = 1 ;
else
V_8 -> V_612 = 0 ;
if ( V_8 -> V_612 ) {
T_4 V_613 = F_109 ( V_8 , V_614 ) ;
V_613 &= ~ ( V_615 | V_616 ) ;
F_113 ( V_8 , V_614 , V_613 ) ;
F_29 ( L_184 ) ;
} else {
T_4 V_613 = F_109 ( V_8 , V_614 ) ;
V_613 |= V_615 | V_616 ;
F_113 ( V_8 , V_614 , V_613 ) ;
F_29 ( L_185 ) ;
}
return V_140 ;
}
static int F_181 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
struct V_617 * V_618 = & V_8 -> V_619 ;
char V_620 [ V_79 ] ;
if ( V_618 -> V_621 [ 0 ] == 0 ) {
char * V_622 ;
V_622 = V_8 -> V_350 . V_623 ;
strncpy ( V_618 -> V_621 , V_622 , V_79 ) ;
V_618 -> V_621 [ V_79 - 1 ] = 0 ;
}
if ( V_10 -> V_64 . V_66 > V_79 )
return - V_453 ;
if ( F_106 ( V_620 , V_10 -> V_64 . V_452 , V_79 ) )
return - V_453 ;
if ( 0 == strcmp ( V_618 -> V_621 , V_620 ) )
return V_140 ;
F_29 ( L_186 , V_342 , V_620 ) ;
V_140 = F_182 ( V_8 , V_620 ) ;
if ( 0 != V_140 )
goto exit;
if ( ! memcmp ( V_618 -> V_621 , L_187 , 9 ) ) {
V_8 -> V_624 . V_625 = V_618 -> V_626 ;
F_183 ( V_8 ) ;
F_184 ( & V_8 -> V_385 , V_618 -> V_627 ) ;
}
strncpy ( V_618 -> V_621 , V_620 , V_79 ) ;
V_618 -> V_621 [ V_79 - 1 ] = 0 ;
if ( ! memcmp ( V_620 , L_187 , 9 ) ) {
F_29 ( L_188 , V_342 ) ;
F_74 ( V_8 , true ) ;
F_138 ( V_8 , V_628 ) ;
V_618 -> V_626 = V_8 -> V_624 . V_625 ;
V_8 -> V_624 . V_625 = false ;
F_185 ( V_8 ) ;
V_618 -> V_627 = F_186 ( & V_8 -> V_385 ) ;
F_184 ( & V_8 -> V_385 , V_629 ) ;
}
exit:
return V_140 ;
}
static void F_187 ( struct V_7 * V_8 )
{
int V_4 , V_264 = 1 ;
F_173 ( L_189 ) ;
for ( V_4 = 0x0 ; V_4 < 0x300 ; V_4 += 4 ) {
if ( V_264 % 4 == 1 )
F_173 ( L_190 , V_4 ) ;
F_173 ( L_191 , F_109 ( V_8 , V_4 ) ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_173 ( L_192 ) ;
}
for ( V_4 = 0x400 ; V_4 < 0x800 ; V_4 += 4 ) {
if ( V_264 % 4 == 1 )
F_173 ( L_190 , V_4 ) ;
F_173 ( L_191 , F_109 ( V_8 , V_4 ) ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_173 ( L_192 ) ;
}
}
static void F_188 ( struct V_7 * V_8 )
{
int V_4 , V_264 = 1 ;
F_173 ( L_193 ) ;
for ( V_4 = 0x800 ; V_4 < 0x1000 ; V_4 += 4 ) {
if ( V_264 % 4 == 1 )
F_173 ( L_190 , V_4 ) ;
F_173 ( L_191 , F_109 ( V_8 , V_4 ) ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_173 ( L_192 ) ;
}
}
static void F_189 ( struct V_7 * V_8 )
{
int V_4 , V_264 = 1 , V_455 ;
T_4 V_104 ;
T_1 V_630 , V_631 = 0 ;
F_190 ( V_8 , V_632 , ( T_1 * ) ( & V_630 ) ) ;
F_173 ( L_194 ) ;
if ( ( V_633 == V_630 ) || ( V_634 == V_630 ) )
V_631 = 1 ;
else
V_631 = 2 ;
for ( V_455 = 0 ; V_455 < V_631 ; V_455 ++ ) {
F_173 ( L_195 , V_455 ) ;
for ( V_4 = 0 ; V_4 < 0x100 ; V_4 ++ ) {
V_104 = F_115 ( V_8 , V_455 , V_4 , 0xffffffff ) ;
if ( V_264 % 4 == 1 )
F_173 ( L_196 , V_4 ) ;
F_173 ( L_191 , V_104 ) ;
if ( ( V_264 ++ ) % 4 == 0 )
F_173 ( L_192 ) ;
}
}
}
static int F_191 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
T_1 V_635 , V_636 ;
T_2 V_637 ;
T_8 V_638 ;
T_4 * V_459 , V_639 ;
struct V_194 * V_195 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_286 * V_287 = & V_8 -> V_249 ;
struct V_640 * V_641 = & ( V_287 -> V_642 ) ;
struct V_165 * V_166 = & V_8 -> V_143 ;
struct V_28 * V_20 = & ( V_14 -> V_20 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
V_459 = ( T_4 * ) & V_10 -> V_64 ;
V_639 = * V_459 ;
V_637 = ( T_2 ) ( V_639 & 0x0000ffff ) ;
V_635 = ( T_1 ) ( V_639 >> 24 ) ;
V_636 = ( T_1 ) ( ( V_639 >> 16 ) & 0x00ff ) ;
V_638 = * ( V_459 + 1 ) ;
switch ( V_635 ) {
case 0x70 :
switch ( V_636 ) {
case 1 :
F_29 ( L_197 , V_637 , F_107 ( V_8 , V_637 ) ) ;
break;
case 2 :
F_29 ( L_198 , V_637 , F_108 ( V_8 , V_637 ) ) ;
break;
case 4 :
F_29 ( L_199 , V_637 , F_109 ( V_8 , V_637 ) ) ;
break;
}
break;
case 0x71 :
switch ( V_636 ) {
case 1 :
F_111 ( V_8 , V_637 , V_638 ) ;
F_29 ( L_200 , V_637 , F_107 ( V_8 , V_637 ) ) ;
break;
case 2 :
F_112 ( V_8 , V_637 , V_638 ) ;
F_29 ( L_201 , V_637 , F_108 ( V_8 , V_637 ) ) ;
break;
case 4 :
F_113 ( V_8 , V_637 , V_638 ) ;
F_29 ( L_202 , V_637 , F_109 ( V_8 , V_637 ) ) ;
break;
}
break;
case 0x72 :
F_29 ( L_203 , V_637 , F_192 ( V_8 , V_637 , 0xffffffff ) ) ;
break;
case 0x73 :
F_193 ( V_8 , V_637 , 0xffffffff , V_638 ) ;
F_29 ( L_204 , V_637 , F_192 ( V_8 , V_637 , 0xffffffff ) ) ;
break;
case 0x74 :
F_29 ( L_205 , V_636 , V_637 , F_115 ( V_8 , V_636 , V_637 , 0xffffffff ) ) ;
break;
case 0x75 :
F_117 ( V_8 , V_636 , V_637 , 0xffffffff , V_638 ) ;
F_29 ( L_206 , V_636 , V_637 , F_115 ( V_8 , V_636 , V_637 , 0xffffffff ) ) ;
break;
case 0x76 :
switch ( V_636 ) {
case 0x00 :
V_8 -> V_129 . V_643 = 0 ;
break;
case 0x01 :
V_8 -> V_129 . V_643 = 1 ;
V_638 = V_638 > 100 ? 100 : V_638 ;
V_638 = V_638 < 0 ? 0 : V_638 ;
V_8 -> V_129 . V_644 = V_638 ;
break;
}
break;
case 0x78 :
switch ( V_636 ) {
case 0x04 :
{
T_1 V_645 = 0xf9 ;
struct V_646 * V_646 ;
V_646 = F_194 ( V_8 ) ;
if ( V_646 == NULL ) {
V_140 = - V_223 ;
break;
}
F_195 ( V_646 , V_645 ) ;
if ( V_225 != F_196 ( V_8 , V_646 , 500 , 0 ) )
V_140 = - V_253 ;
}
break;
case 0x05 :
{
T_2 V_647 = 0x4c ;
T_4 V_648 = 50 ;
T_4 V_649 = 200 ;
int V_4 ;
struct V_646 * V_646 ;
V_646 = F_194 ( V_8 ) ;
if ( V_646 == NULL ) {
V_140 = - V_223 ;
break;
}
for ( V_4 = 0 ; V_4 < V_648 ; V_4 ++ ) {
F_197 ( V_646 , V_647 , 0x00 , 0xff ) ;
F_198 ( V_646 , V_649 ) ;
F_197 ( V_646 , V_647 , 0x08 , 0xff ) ;
F_198 ( V_646 , V_649 ) ;
}
if ( V_225 != F_196 ( V_8 , V_646 , ( V_649 * V_648 * 2 ) + 200 , 0 ) )
V_140 = - V_253 ;
}
break;
case 0x06 :
{
T_2 V_647 = V_637 ;
T_2 V_650 = 0 ;
T_4 V_651 = V_638 ;
int V_4 ;
T_1 V_652 ;
struct V_646 * V_646 ;
V_646 = F_194 ( V_8 ) ;
if ( V_646 == NULL ) {
V_140 = - V_223 ;
break;
}
for ( V_4 = 0 ; V_4 < V_651 ; V_4 ++ )
F_197 ( V_646 , V_647 , V_4 + V_650 , 0xFF ) ;
if ( V_225 != F_196 ( V_8 , V_646 , 5000 , 0 ) )
V_140 = - V_253 ;
V_652 = F_107 ( V_8 , V_647 ) ;
if ( V_650 + V_651 - 1 == V_652 )
F_29 ( L_207 , V_647 , V_651 , V_650 , V_652 ) ;
else
F_29 ( L_208 , V_647 , V_651 , V_650 , V_652 ) ;
}
break;
case 0x07 :
{
T_2 V_647 = V_637 ;
T_2 V_650 = 200 ;
T_4 V_651 = V_638 ;
int V_4 ;
T_2 V_652 ;
struct V_646 * V_646 ;
V_646 = F_194 ( V_8 ) ;
if ( V_646 == NULL ) {
V_140 = - V_223 ;
break;
}
for ( V_4 = 0 ; V_4 < V_651 ; V_4 ++ )
F_199 ( V_646 , V_647 , V_4 + V_650 , 0xFFFF ) ;
if ( V_225 != F_196 ( V_8 , V_646 , 5000 , 0 ) )
V_140 = - V_253 ;
V_652 = F_108 ( V_8 , V_647 ) ;
if ( V_650 + V_651 - 1 == V_652 )
F_29 ( L_209 , V_647 , V_651 , V_650 , V_652 ) ;
else
F_29 ( L_210 , V_647 , V_651 , V_650 , V_652 ) ;
}
break;
case 0x08 :
{
T_2 V_647 = V_637 ;
T_4 V_650 = 0x110000c7 ;
T_4 V_651 = V_638 ;
int V_4 ;
T_4 V_652 ;
struct V_646 * V_646 ;
V_646 = F_194 ( V_8 ) ;
if ( V_646 == NULL ) {
V_140 = - V_223 ;
break;
}
for ( V_4 = 0 ; V_4 < V_651 ; V_4 ++ )
F_200 ( V_646 , V_647 , V_4 + V_650 , 0xFFFFFFFF ) ;
if ( V_225 != F_196 ( V_8 , V_646 , 5000 , 0 ) )
V_140 = - V_253 ;
V_652 = F_109 ( V_8 , V_647 ) ;
if ( V_650 + V_651 - 1 == V_652 )
F_29 ( L_211 ,
V_647 , V_651 , V_650 , V_652 ) ;
else
F_29 ( L_212 ,
V_647 , V_651 , V_650 , V_652 ) ;
}
break;
}
break;
case 0x79 :
{
T_1 V_104 = V_638 & 0x0f ;
T_1 V_653 = V_636 ;
T_2 V_654 = 0 ;
F_29 ( L_213 , V_342 , V_653 ? L_214 : L_215 , V_104 ) ;
if ( V_653 )
V_104 = V_104 | 0x10 ;
V_654 = V_104 | ( V_104 << 5 ) ;
F_112 ( V_8 , 0x6d9 , V_654 ) ;
}
break;
case 0x7a :
F_201 ( V_8 , V_641 -> V_21 . V_22
, V_655 ) ;
break;
case 0x7F :
switch ( V_636 ) {
case 0x0 :
F_29 ( L_216 , F_82 ( V_14 ) ) ;
break;
case 0x01 :
F_29 ( L_217 ,
V_166 -> V_148 , V_166 -> V_179 ,
V_166 -> V_146 , V_166 -> V_144 ) ;
break;
case 0x02 :
F_29 ( L_218 , V_641 -> V_656 ) ;
break;
case 0x03 :
F_29 ( L_219 , V_14 -> V_657 . V_658 ) ;
F_29 ( L_220 , V_14 -> V_659 . V_660 ) ;
break;
case 0x04 :
F_29 ( L_221 , V_287 -> V_250 ) ;
F_29 ( L_222 , V_287 -> V_525 ) ;
F_29 ( L_223 , V_287 -> V_524 ) ;
break;
case 0x05 :
V_195 = F_35 ( V_198 , V_20 -> V_21 . V_22 ) ;
if ( V_195 ) {
int V_4 ;
struct V_661 * V_662 ;
F_29 ( L_224 , V_20 -> V_21 . V_53 . V_53 ) ;
F_29 ( L_225 , V_195 -> V_663 ) ;
F_29 ( L_226 , V_287 -> V_250 , V_287 -> V_525 , V_287 -> V_524 ) ;
F_29 ( L_227 , V_195 -> V_664 , V_195 -> V_665 ) ;
F_29 ( L_228 , V_195 -> V_656 , V_195 -> V_666 , V_195 -> V_667 , V_195 -> V_668 ) ;
F_29 ( L_229 , V_195 -> V_658 , V_195 -> V_659 . V_660 , V_195 -> V_669 ) ;
F_29 ( L_230 , V_195 -> V_659 . V_518 , V_195 -> V_659 . V_517 , V_195 -> V_659 . V_670 ) ;
F_29 ( L_231 , V_195 -> V_659 . V_671 ) ;
F_29 ( L_232 , V_195 -> V_659 . V_672 , V_195 -> V_659 . V_673 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
V_662 = & V_195 -> V_674 [ V_4 ] ;
if ( V_662 -> V_675 )
F_29 ( L_233 , V_4 , V_662 -> V_676 ) ;
}
} else {
F_29 ( L_234 , ( V_20 -> V_21 . V_22 ) ) ;
}
break;
case 0x06 :
{
T_4 V_677 ;
F_190 ( V_8 , V_678 , ( T_1 * ) ( & V_677 ) ) ;
F_29 ( L_235 , V_677 , V_637 ) ;
V_677 = ( T_4 ) ( 0x0f & V_637 ) ;
F_29 ( L_236 , V_677 ) ;
F_128 ( V_8 , V_678 , ( T_1 * ) ( & V_677 ) ) ;
}
break;
case 0x07 :
F_29 ( L_237 ,
V_8 -> V_679 , V_8 -> V_352 ) ;
break;
case 0x08 :
{
struct V_680 * V_681 = & V_8 -> V_402 ;
struct V_682 * V_683 = & V_8 -> V_129 ;
F_29 ( L_238 ,
V_681 -> V_684 , V_681 -> V_685 , V_681 -> V_686 ) ;
F_29 ( L_239 , V_683 -> V_687 ) ;
}
break;
case 0x09 :
{
int V_4 , V_264 ;
struct V_325 * V_381 , * V_326 ;
struct V_661 * V_662 ;
#ifdef F_202
F_29 ( L_240 , V_198 -> V_688 , V_198 -> V_689 ) ;
#endif
F_59 ( & V_198 -> V_690 ) ;
for ( V_4 = 0 ; V_4 < V_691 ; V_4 ++ ) {
V_326 = & ( V_198 -> V_692 [ V_4 ] ) ;
V_381 = F_61 ( V_326 ) ;
while ( ( F_62 ( V_326 , V_381 ) ) == false ) {
V_195 = F_63 ( V_381 , struct V_194 , V_693 ) ;
V_381 = F_61 ( V_381 ) ;
if ( V_638 == V_195 -> V_666 ) {
F_29 ( L_241 , ( V_195 -> V_663 ) ) ;
F_29 ( L_227 , V_195 -> V_664 , V_195 -> V_665 ) ;
F_29 ( L_228 , V_195 -> V_656 , V_195 -> V_666 , V_195 -> V_667 , V_195 -> V_668 ) ;
F_29 ( L_229 , V_195 -> V_658 , V_195 -> V_659 . V_660 , V_195 -> V_669 ) ;
F_29 ( L_230 , V_195 -> V_659 . V_518 , V_195 -> V_659 . V_517 , V_195 -> V_659 . V_670 ) ;
F_29 ( L_231 , V_195 -> V_659 . V_671 ) ;
F_29 ( L_232 , V_195 -> V_659 . V_672 , V_195 -> V_659 . V_673 ) ;
#ifdef F_202
F_29 ( L_242 , V_195 -> V_694 ) ;
F_29 ( L_243 , V_195 -> V_65 ) ;
F_29 ( L_244 , V_195 -> V_695 ) ;
F_29 ( L_245 , V_195 -> V_696 ) ;
F_29 ( L_246 , V_195 -> V_697 ) ;
F_29 ( L_247 , V_195 -> V_698 ) ;
#endif
F_29 ( L_248 , V_195 -> V_205 ) ;
for ( V_264 = 0 ; V_264 < 16 ; V_264 ++ ) {
V_662 = & V_195 -> V_674 [ V_264 ] ;
if ( V_662 -> V_675 )
F_29 ( L_233 , V_264 , V_662 -> V_676 ) ;
}
}
}
}
F_64 ( & V_198 -> V_690 ) ;
}
break;
case 0x0c :
if ( V_637 == 0 ) {
F_29 ( L_249 , V_638 ) ;
F_203 ( V_8 , V_699 , & ( V_638 ) ) ;
} else if ( V_637 == 1 ) {
F_29 ( L_250 , V_638 ) ;
F_203 ( V_8 , V_700 , & ( V_638 ) ) ;
}
break;
case 0x0f :
if ( V_638 == 0 ) {
F_29 ( L_251 ) ;
F_204 ( V_8 ) ;
}
break;
case 0x15 :
{
struct V_411 * V_412 = & V_8 -> V_385 ;
F_29 ( L_252 , V_412 -> V_701 ) ;
}
break;
case 0x10 :
F_29 ( L_253 , V_702 ) ;
break;
case 0x11 :
F_29 ( L_254 , ( V_638 == 1 ) ? L_255 : L_256 ) ;
V_8 -> V_703 = V_638 ;
F_203 ( V_8 , V_704 , & V_638 ) ;
break;
case 0x12 :
{
struct V_705 * V_706 = & V_8 -> V_350 ;
if ( V_706 &&
( V_638 == 0 ||
V_638 == 1 ||
V_638 == 2 ||
V_638 == 3 ) ) {
V_706 -> V_707 = V_638 ;
F_29 ( L_257 , V_706 -> V_707 ) ;
} else {
F_29 ( L_258 , V_706 -> V_707 ) ;
}
}
break;
case 0x13 :
{
struct V_705 * V_706 = & V_8 -> V_350 ;
if ( V_706 && V_638 >= 0 && V_638 < 3 ) {
V_706 -> V_671 = V_638 ;
F_29 ( L_259 , V_706 -> V_671 ) ;
} else {
F_29 ( L_260 , V_706 -> V_671 ) ;
}
}
break;
case 0x14 :
{
struct V_705 * V_706 = & V_8 -> V_350 ;
F_29 ( L_261 , V_706 -> V_708 ) ;
}
break;
case 0x16 :
if ( V_637 == 0xff ) {
F_173 ( L_262 ) ;
F_173 ( L_263 ) ;
F_173 ( L_264 ) ;
F_173 ( L_265 ) ;
F_173 ( L_266 ) ;
F_173 ( L_267 ) ;
F_173 ( L_268 ) ;
F_173 ( L_269 ) ;
F_173 ( L_270 ) ;
F_173 ( L_271 ) ;
F_173 ( L_272 ) ;
F_173 ( L_273 ) ;
F_173 ( L_274 ) ;
F_173 ( L_275 ) ;
F_173 ( L_276 ) ;
F_173 ( L_277 ) ;
F_173 ( L_278 ) ;
F_173 ( L_279 ) ;
F_173 ( L_280 ) ;
F_205 ( V_8 , V_709 , & V_638 ) ;
} else {
F_203 ( V_8 , V_709 , & V_638 ) ;
}
break;
case 0x23 :
F_29 ( L_281 , ( V_638 == 1 ) ? L_255 : L_256 ) ;
V_8 -> V_710 = V_638 ;
break;
case 0x24 :
#ifdef F_10
F_29 ( L_282 , ( V_638 == 1 ) ? L_255 : L_256 ) ;
V_8 -> V_542 = V_638 ;
#endif
break;
case 0xaa :
if ( V_638 > 0x13 )
V_638 = 0xFF ;
F_29 ( L_283 , V_638 ) ;
V_8 -> V_711 = V_638 ;
break;
case 0xdd :
if ( V_638 == 0 )
F_187 ( V_8 ) ;
else if ( V_638 == 1 )
F_188 ( V_8 ) ;
else if ( V_638 == 2 )
F_189 ( V_8 ) ;
break;
case 0xee :
{
T_4 V_712 ;
if ( 0xf == V_638 ) {
F_205 ( V_8 , V_713 , & V_712 ) ;
F_29 ( L_284 , V_712 ) ;
F_29 ( L_285 ) ;
F_29 ( L_286 ) ;
F_29 ( L_287 ) ;
F_29 ( L_288 ) ;
F_29 ( L_289 ) ;
F_29 ( L_290 ) ;
F_29 ( L_291 ) ;
} else {
F_203 ( V_8 , V_713 , & ( V_638 ) ) ;
F_205 ( V_8 , V_713 , & V_712 ) ;
F_29 ( L_284 , V_712 ) ;
}
}
break;
case 0xfd :
F_111 ( V_8 , 0xc50 , V_637 ) ;
F_29 ( L_292 , F_107 ( V_8 , 0xc50 ) ) ;
F_111 ( V_8 , 0xc58 , V_637 ) ;
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
static int F_206 ( struct V_138 * V_139 , T_1 V_78 , T_4 V_104 )
{
T_5 V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
switch ( V_78 ) {
case V_714 :
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
case V_715 :
break;
case V_716 : {
break;
}
case V_717 :
break;
case V_718 :
V_140 = F_27 ( V_139 , V_104 ) ;
break;
case V_719 :
break;
case V_720 :
break;
default:
V_140 = - V_189 ;
break;
}
return V_140 ;
}
static int F_207 ( struct V_138 * V_139 , T_4 V_721 , T_4 V_339 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
switch ( V_721 ) {
case V_722 :
if ( ! F_69 ( V_8 ) )
V_140 = - 1 ;
break;
case V_723 :
if ( ! F_69 ( V_8 ) )
V_140 = - 1 ;
break;
default:
V_140 = - V_189 ;
break;
}
return V_140 ;
}
static int F_208 ( struct V_138 * V_139 , struct V_408 * V_39 )
{
struct V_157 * V_158 ;
T_5 V_140 = 0 ;
if ( V_39 -> V_66 < sizeof( struct V_157 ) || ! V_39 -> V_452 ) {
V_140 = - V_156 ;
goto V_724;
}
V_158 = (struct V_157 * ) F_32 ( V_39 -> V_66 ) ;
if ( V_158 == NULL ) {
V_140 = - V_223 ;
goto V_724;
}
if ( F_106 ( V_158 , V_39 -> V_452 , V_39 -> V_66 ) ) {
F_40 ( V_158 ) ;
V_140 = - V_453 ;
goto V_724;
}
switch ( V_158 -> V_60 ) {
case V_725 :
V_140 = F_206 ( V_139 , V_158 -> V_61 . V_726 . V_78 , V_158 -> V_61 . V_726 . V_104 ) ;
break;
case V_727 :
V_140 = F_41 ( (struct V_7 * ) F_28 ( V_139 ) ,
( char * ) V_158 -> V_61 . V_108 . V_64 , ( T_2 ) V_158 -> V_61 . V_108 . V_363 ) ;
break;
case V_438 :
V_140 = F_30 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_728 :
V_140 = F_207 ( V_139 , V_158 -> V_61 . V_341 . V_721 , V_158 -> V_61 . V_341 . V_343 ) ;
break;
default:
F_29 ( L_314 , V_158 -> V_60 ) ;
V_140 = - V_189 ;
break;
}
if ( V_140 == 0 && F_132 ( V_39 -> V_452 , V_158 , V_39 -> V_66 ) )
V_140 = - V_453 ;
F_40 ( V_158 ) ;
V_724:
return V_140 ;
}
static T_1 F_209 ( struct V_7 * V_8 , struct V_194 * V_195 )
{
struct V_729 * V_730 ;
struct V_731 * V_732 ;
struct V_733 * V_734 = & V_8 -> V_735 ;
T_1 V_736 = V_225 ;
V_730 = (struct V_729 * ) F_43 ( sizeof( struct V_729 ) ) ;
if ( V_730 == NULL ) {
V_736 = V_188 ;
goto exit;
}
V_732 = (struct V_731 * ) F_43 ( sizeof( struct V_731 ) ) ;
if ( V_732 == NULL ) {
F_40 ( V_730 ) ;
V_736 = V_188 ;
goto exit;
}
F_210 ( V_730 , V_732 , V_737 ) ;
V_732 -> V_738 = ( T_1 ) V_195 -> V_205 ;
memcpy ( V_732 -> V_3 , V_195 -> V_663 , V_23 ) ;
memcpy ( V_732 -> V_172 , & V_195 -> V_206 , 16 ) ;
V_736 = F_211 ( V_734 , V_730 ) ;
exit:
return V_736 ;
}
static int F_212 ( struct V_7 * V_8 , T_1 * V_172 , T_1 V_170 , int V_739 )
{
T_1 V_740 ;
struct V_729 * V_741 ;
struct V_742 * V_743 ;
struct V_733 * V_734 = & ( V_8 -> V_735 ) ;
int V_736 = V_225 ;
F_29 ( L_57 , V_342 ) ;
V_741 = (struct V_729 * ) F_43 ( sizeof( struct V_729 ) ) ;
if ( V_741 == NULL ) {
V_736 = V_188 ;
goto exit;
}
V_743 = (struct V_742 * ) F_43 ( sizeof( struct V_742 ) ) ;
if ( V_743 == NULL ) {
F_40 ( V_741 ) ;
V_736 = V_188 ;
goto exit;
}
F_4 ( V_743 , 0 , sizeof( struct V_742 ) ) ;
V_743 -> V_739 = ( T_1 ) V_739 ;
V_743 -> V_738 = V_170 ;
V_743 -> V_187 = 1 ;
switch ( V_170 ) {
case V_180 :
V_740 = 5 ;
break;
case V_185 :
V_740 = 13 ;
break;
case V_233 :
case V_744 :
case V_235 :
default:
V_740 = 16 ;
}
memcpy ( & ( V_743 -> V_172 [ 0 ] ) , V_172 , V_740 ) ;
V_741 -> V_745 = V_746 ;
V_741 -> V_747 = ( T_1 * ) V_743 ;
V_741 -> V_748 = ( sizeof( struct V_742 ) ) ;
V_741 -> V_749 = NULL ;
V_741 -> V_750 = 0 ;
F_213 ( & V_741 -> V_337 ) ;
V_736 = F_211 ( V_734 , V_741 ) ;
exit:
return V_736 ;
}
static int F_214 ( struct V_7 * V_8 , T_1 * V_172 , T_1 V_740 , int V_739 )
{
T_1 V_170 ;
switch ( V_740 ) {
case 5 :
V_170 = V_180 ;
break;
case 13 :
V_170 = V_185 ;
break;
default:
V_170 = V_229 ;
}
return F_212 ( V_8 , V_172 , V_170 , V_739 ) ;
}
static int F_215 ( struct V_138 * V_139 , struct V_157 * V_158 , T_4 V_159 )
{
int V_140 = 0 ;
T_4 V_160 , V_161 , V_162 ;
struct V_163 * V_164 = NULL ;
struct V_194 * V_195 = NULL , * V_196 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_165 * V_166 = & ( V_8 -> V_143 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
F_29 ( L_57 , V_342 ) ;
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
V_166 -> V_414 = V_160 ;
memcpy ( & ( V_166 -> V_190 [ V_160 ] . V_191 [ 0 ] ) , V_164 -> V_182 , V_164 -> V_183 ) ;
V_166 -> V_192 [ V_160 ] = V_164 -> V_183 ;
F_214 ( V_8 , V_164 -> V_182 , V_164 -> V_183 , V_160 ) ;
} else {
F_29 ( L_31 ) ;
memcpy ( & ( V_166 -> V_190 [ V_160 ] . V_191 [ 0 ] ) , V_164 -> V_182 , V_164 -> V_183 ) ;
V_166 -> V_192 [ V_160 ] = V_164 -> V_183 ;
F_214 ( V_8 , V_164 -> V_182 , V_164 -> V_183 , V_160 ) ;
}
goto exit;
}
if ( ! V_195 && F_25 ( V_14 , V_263 ) ) {
if ( V_158 -> V_61 . V_168 . V_187 == 1 ) {
if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_25 ) == 0 ) {
F_29 ( L_320 , V_342 ) ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 ,
V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
V_166 -> V_181 = V_180 ;
if ( V_158 -> V_61 . V_168 . V_173 == 13 )
V_166 -> V_181 = V_185 ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_33 ) == 0 ) {
F_29 ( L_321 , V_342 ) ;
V_166 -> V_181 = V_233 ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 ,
V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
memcpy ( V_166 -> V_211 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 16 ] ) , 8 ) ;
memcpy ( V_166 -> V_212 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 24 ] ) , 8 ) ;
V_166 -> V_209 = true ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_89 ) == 0 ) {
F_29 ( L_322 , V_342 ) ;
V_166 -> V_181 = V_235 ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_168 . V_175 ] . V_191 ,
V_158 -> V_61 . V_168 . V_172 , ( V_158 -> V_61 . V_168 . V_173 > 16 ? 16 : V_158 -> V_61 . V_168 . V_173 ) ) ;
} else {
F_29 ( L_323 , V_342 ) ;
V_166 -> V_181 = V_229 ;
}
V_166 -> V_214 = V_158 -> V_61 . V_168 . V_175 ;
V_166 -> V_213 = true ;
V_166 -> V_179 = V_166 -> V_181 ;
F_212 ( V_8 , V_158 -> V_61 . V_168 . V_172 , V_166 -> V_181 , V_158 -> V_61 . V_168 . V_175 ) ;
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
F_29 ( L_324 , V_342 ) ;
V_195 -> V_205 = V_180 ;
if ( V_158 -> V_61 . V_168 . V_173 == 13 )
V_195 -> V_205 = V_185 ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_33 ) == 0 ) {
F_29 ( L_325 , V_342 ) ;
V_195 -> V_205 = V_233 ;
memcpy ( V_195 -> V_207 . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 16 ] ) , 8 ) ;
memcpy ( V_195 -> V_208 . V_191 , & ( V_158 -> V_61 . V_168 . V_172 [ 24 ] ) , 8 ) ;
V_166 -> V_209 = true ;
} else if ( strcmp ( V_158 -> V_61 . V_168 . V_170 , L_89 ) == 0 ) {
F_29 ( L_326 , V_342 ) ;
V_195 -> V_205 = V_235 ;
} else {
F_29 ( L_327 , V_342 ) ;
V_195 -> V_205 = V_229 ;
}
F_209 ( V_8 , V_195 ) ;
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
F_212 ( V_8 , V_158 -> V_61 . V_168 . V_172 , V_166 -> V_181 , V_158 -> V_61 . V_168 . V_175 ) ;
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
static int F_216 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_363 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
unsigned char * V_502 = V_158 -> V_61 . V_751 . V_106 ;
F_29 ( L_328 , V_342 , V_363 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
memcpy ( & V_198 -> V_752 , V_158 -> V_61 . V_751 . V_753 , 2 ) ;
if ( ( V_198 -> V_752 > V_691 ) || ( V_198 -> V_752 <= 0 ) )
V_198 -> V_752 = V_691 ;
if ( F_217 ( V_8 , V_502 , ( V_363 - 12 - 2 ) ) == V_225 )
V_140 = 0 ;
else
V_140 = - V_156 ;
return V_140 ;
}
static int F_218 ( struct V_138 * V_139 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_57 , V_342 ) ;
F_219 ( V_8 ) ;
V_140 = F_220 ( V_8 ) ;
return V_140 ;
}
static int F_221 ( struct V_138 * V_139 , struct V_157 * V_158 )
{
int V_140 = 0 ;
struct V_194 * V_195 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
F_29 ( L_329 , V_158 -> V_61 . V_754 . V_666 , ( V_158 -> V_174 ) ) ;
if ( ! F_25 ( V_14 , ( V_128 | V_263 ) ) )
return - V_156 ;
if ( V_158 -> V_174 [ 0 ] == 0xff && V_158 -> V_174 [ 1 ] == 0xff &&
V_158 -> V_174 [ 2 ] == 0xff && V_158 -> V_174 [ 3 ] == 0xff &&
V_158 -> V_174 [ 4 ] == 0xff && V_158 -> V_174 [ 5 ] == 0xff )
return - V_156 ;
V_195 = F_35 ( V_198 , V_158 -> V_174 ) ;
if ( V_195 ) {
int V_65 = V_158 -> V_61 . V_754 . V_65 ;
V_195 -> V_666 = V_158 -> V_61 . V_754 . V_666 ;
memcpy ( V_195 -> V_755 , V_158 -> V_61 . V_754 . V_756 , 16 ) ;
if ( V_757 & V_65 )
V_195 -> V_658 = 1 ;
else
V_195 -> V_658 = 0 ;
if ( V_14 -> V_657 . V_658 == 0 )
V_195 -> V_658 = 0 ;
if ( V_758 & V_65 ) {
V_195 -> V_659 . V_660 = true ;
V_195 -> V_658 = 1 ;
memcpy ( ( void * ) & V_195 -> V_659 . V_42 , ( void * ) & V_158 -> V_61 . V_754 . V_42 , sizeof( struct V_69 ) ) ;
} else {
V_195 -> V_659 . V_660 = false ;
}
if ( V_14 -> V_659 . V_660 == false )
V_195 -> V_659 . V_660 = false ;
F_222 ( V_8 , V_195 ) ;
} else {
V_140 = - V_223 ;
}
return V_140 ;
}
static int F_223 ( struct V_138 * V_139 , struct V_157 * V_158 )
{
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
F_59 ( & V_198 -> V_759 ) ;
if ( ! F_224 ( & V_195 -> V_760 ) ) {
F_225 ( & V_195 -> V_760 ) ;
V_198 -> V_761 -- ;
V_124 = F_226 ( V_8 , V_195 , true , V_762 ) ;
}
F_64 ( & V_198 -> V_759 ) ;
F_227 ( V_8 , V_124 ) ;
V_195 = NULL ;
} else {
F_29 ( L_331 ) ;
}
return V_140 ;
}
static int F_228 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_363 )
{
int V_140 = 0 ;
struct V_194 * V_195 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_197 * V_198 = & V_8 -> V_199 ;
struct V_763 * V_764 = (struct V_763 * ) V_158 ;
struct V_765 * V_766 = (struct V_765 * ) V_764 -> V_64 ;
F_29 ( L_332 , ( V_764 -> V_174 ) ) ;
if ( F_25 ( V_14 , ( V_128 | V_263 ) ) != true )
return - V_156 ;
if ( V_764 -> V_174 [ 0 ] == 0xff && V_764 -> V_174 [ 1 ] == 0xff &&
V_764 -> V_174 [ 2 ] == 0xff && V_764 -> V_174 [ 3 ] == 0xff &&
V_764 -> V_174 [ 4 ] == 0xff && V_764 -> V_174 [ 5 ] == 0xff )
return - V_156 ;
V_195 = F_35 ( V_198 , V_764 -> V_174 ) ;
if ( V_195 ) {
V_766 -> V_666 = ( T_2 ) V_195 -> V_666 ;
V_766 -> V_694 = V_195 -> V_694 ;
V_766 -> V_65 = V_195 -> V_65 ;
V_766 -> V_767 = ( ( V_195 -> V_768 ) |
( V_195 -> V_769 << 1 ) |
( V_195 -> V_770 << 2 ) |
( V_195 -> V_771 << 3 ) |
( V_195 -> V_772 << 4 ) |
( V_195 -> V_773 << 5 ) ) ;
V_766 -> V_774 = V_195 -> V_775 ;
memcpy ( V_766 -> V_756 , V_195 -> V_755 , V_195 -> V_775 ) ;
memcpy ( & V_766 -> V_42 , & V_195 -> V_659 . V_42 , sizeof( struct V_69 ) ) ;
V_766 -> V_776 = V_195 -> V_777 . V_778 ;
V_766 -> V_779 = V_195 -> V_777 . V_779 ;
V_766 -> V_780 = V_195 -> V_777 . V_780 ;
V_766 -> V_781 = V_195 -> V_777 . V_781 ;
V_766 -> V_782 = V_195 -> V_777 . V_782 ;
V_766 -> V_783 = V_195 -> V_777 . V_783 ;
} else {
V_140 = - 1 ;
}
return V_140 ;
}
static int F_229 ( struct V_138 * V_139 , struct V_157 * V_158 )
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
if ( ( V_195 -> V_108 [ 0 ] == V_784 ) || ( V_195 -> V_108 [ 0 ] == V_785 ) ) {
int V_786 ;
int V_787 ;
V_786 = V_195 -> V_108 [ 1 ] ;
V_787 = ( ( V_786 + 2 ) > sizeof( V_195 -> V_108 ) ) ? ( sizeof( V_195 -> V_108 ) ) : ( V_786 + 2 ) ;
V_158 -> V_61 . V_108 . V_363 = V_787 ;
memcpy ( V_158 -> V_61 . V_108 . V_753 , V_195 -> V_108 , V_787 ) ;
} else {
F_29 ( L_334 ) ;
}
} else {
V_140 = - 1 ;
}
return V_140 ;
}
static int F_230 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_363 )
{
int V_140 = 0 ;
unsigned char V_238 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_286 * V_287 = & ( V_8 -> V_249 ) ;
int V_788 ;
F_29 ( L_328 , V_342 , V_363 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
V_788 = V_363 - 12 - 2 ;
if ( V_14 -> V_789 ) {
F_40 ( V_14 -> V_789 ) ;
V_14 -> V_789 = NULL ;
}
if ( V_788 > 0 ) {
V_14 -> V_789 = F_32 ( V_788 ) ;
V_14 -> V_790 = V_788 ;
if ( V_14 -> V_789 == NULL ) {
F_29 ( L_335 , V_342 , __LINE__ ) ;
return - V_156 ;
}
memcpy ( V_14 -> V_789 , V_158 -> V_61 . V_751 . V_106 , V_788 ) ;
F_231 ( V_8 , V_239 , V_238 , true ) ;
V_287 -> V_791 = true ;
}
return V_140 ;
}
static int F_232 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_363 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
int V_788 ;
F_29 ( L_328 , V_342 , V_363 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
V_788 = V_363 - 12 - 2 ;
if ( V_14 -> V_792 ) {
F_40 ( V_14 -> V_792 ) ;
V_14 -> V_792 = NULL ;
}
if ( V_788 > 0 ) {
V_14 -> V_792 = F_32 ( V_788 ) ;
V_14 -> V_793 = V_788 ;
if ( V_14 -> V_792 == NULL ) {
F_29 ( L_335 , V_342 , __LINE__ ) ;
return - V_156 ;
}
memcpy ( V_14 -> V_792 , V_158 -> V_61 . V_751 . V_106 , V_788 ) ;
}
return V_140 ;
}
static int F_233 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_363 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
int V_788 ;
F_29 ( L_328 , V_342 , V_363 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
V_788 = V_363 - 12 - 2 ;
if ( V_14 -> V_794 ) {
F_40 ( V_14 -> V_794 ) ;
V_14 -> V_794 = NULL ;
}
if ( V_788 > 0 ) {
V_14 -> V_794 = F_32 ( V_788 ) ;
V_14 -> V_795 = V_788 ;
if ( V_14 -> V_794 == NULL ) {
F_29 ( L_335 , V_342 , __LINE__ ) ;
return - V_156 ;
}
memcpy ( V_14 -> V_794 , V_158 -> V_61 . V_751 . V_106 , V_788 ) ;
}
return V_140 ;
}
static int F_234 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_363 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_286 * V_287 = & ( V_8 -> V_249 ) ;
struct V_640 * V_641 = & ( V_287 -> V_642 ) ;
T_1 V_104 ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
if ( V_158 -> V_61 . V_726 . V_78 != 0 )
F_29 ( L_336 , V_342 , V_158 -> V_61 . V_726 . V_78 ) ;
V_104 = V_158 -> V_61 . V_726 . V_104 ;
if ( V_104 != 1 && V_104 != 2 )
V_104 = 0 ;
F_29 ( L_337 , V_342 , V_104 ) ;
V_641 -> V_796 = V_104 ;
return V_140 ;
}
static int F_235 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_363 )
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
V_140 = F_236 ( V_8 , V_158 -> V_174 ) ;
return V_140 ;
}
static int F_237 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_363 )
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
V_140 = F_238 ( V_8 , V_158 -> V_174 ) ;
return V_140 ;
}
static int F_239 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_363 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
if ( F_25 ( V_14 , V_263 ) != true )
return - V_156 ;
F_240 ( V_8 , V_158 -> V_61 . V_341 . V_721 ) ;
return V_140 ;
}
static int F_241 ( struct V_138 * V_139 , struct V_408 * V_39 )
{
struct V_157 * V_158 ;
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
if ( ! V_8 -> V_254 ) {
V_140 = - V_253 ;
goto V_724;
}
if ( ! V_39 -> V_452 ) {
V_140 = - V_156 ;
goto V_724;
}
V_158 = (struct V_157 * ) F_32 ( V_39 -> V_66 ) ;
if ( V_158 == NULL ) {
V_140 = - V_223 ;
goto V_724;
}
if ( F_106 ( V_158 , V_39 -> V_452 , V_39 -> V_66 ) ) {
F_40 ( V_158 ) ;
V_140 = - V_453 ;
goto V_724;
}
switch ( V_158 -> V_60 ) {
case V_797 :
V_140 = F_218 ( V_139 ) ;
break;
case V_798 :
V_140 = F_221 ( V_139 , V_158 ) ;
break;
case V_799 :
V_140 = F_223 ( V_139 , V_158 ) ;
break;
case V_800 :
V_140 = F_216 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_801 :
V_140 = F_215 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_802 :
V_140 = F_229 ( V_139 , V_158 ) ;
break;
case V_803 :
V_140 = F_230 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_804 :
V_140 = F_232 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_805 :
V_140 = F_233 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_806 :
V_140 = F_234 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_807 :
V_140 = F_228 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_808 :
V_140 = F_239 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_809 :
V_140 = F_237 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_810 :
V_140 = F_235 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
default:
F_29 ( L_338 , V_158 -> V_60 ) ;
V_140 = - V_189 ;
break;
}
if ( V_140 == 0 && F_132 ( V_39 -> V_452 , V_158 , V_39 -> V_66 ) )
V_140 = - V_453 ;
F_40 ( V_158 ) ;
V_724:
return V_140 ;
}
static int F_242 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_322 ,
char * V_243 )
{
int V_140 = 0 ;
int V_363 = 0 ;
char * V_811 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_408 * V_812 = (struct V_408 * ) V_322 ;
if ( V_812 -> V_66 == 0 )
return - V_453 ;
V_363 = V_812 -> V_66 ;
V_811 = F_243 ( V_363 ) ;
if ( ! V_811 )
return - V_223 ;
if ( F_106 ( V_811 , V_812 -> V_452 , V_363 ) ) {
F_244 ( V_811 , V_363 ) ;
return - V_453 ;
}
if ( V_812 -> V_65 == 0x8766 && V_363 > 8 ) {
T_4 V_813 ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
T_1 * V_814 = V_811 ;
int V_815 = V_363 ;
T_1 V_238 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
if ( ( V_239 == V_814 [ 0 ] ) &&
( ! memcmp ( & V_814 [ 2 ] , V_238 , 4 ) ) ) {
V_813 = V_815 > V_816 ? V_816 : V_815 ;
V_14 -> V_817 = 0 ;
F_40 ( V_14 -> V_818 ) ;
V_14 -> V_818 = NULL ;
V_14 -> V_818 = F_32 ( V_813 ) ;
if ( V_14 -> V_818 == NULL ) {
F_173 ( L_335 , V_342 , __LINE__ ) ;
V_140 = - V_156 ;
goto V_819;
}
memcpy ( V_14 -> V_818 , V_814 , V_813 ) ;
V_14 -> V_817 = V_813 ;
}
goto V_819;
}
if ( V_363 >= V_369 &&
! memcmp ( V_811 , V_370 , V_369 ) ) {
V_140 = F_70 ( V_139 , V_27 , V_322 , V_811 ) ;
goto V_819;
}
V_819:
F_244 ( V_811 , V_363 ) ;
return V_140 ;
}
static int F_245 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
int V_140 = 0 ;
unsigned V_86 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_156 , V_342 , V_243 ) ;
if ( ! memcmp ( V_243 , L_339 , 4 ) ) {
sscanf ( V_243 + 4 , L_340 , & V_86 ) ;
V_140 = F_246 ( V_8 , V_86 ) ;
} else if ( ! memcmp ( V_243 , L_341 , 4 ) ) {
sscanf ( V_243 + 4 , L_340 , & V_86 ) ;
V_140 = F_247 ( V_8 , V_86 ) ;
} else {
V_140 = - V_156 ;
}
return V_140 ;
}
static int F_248 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_820 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
struct V_821 * V_822 = F_249 ( V_8 ) ;
struct V_823 * V_824 = F_250 ( V_8 ) ;
struct V_825 * V_826 ;
struct V_408 * V_10 ;
T_1 * V_827 = V_822 -> V_828 ;
T_1 V_829 = 0 , V_830 = 0 ;
struct V_411 * V_385 ;
T_1 * V_64 = NULL ;
T_1 * V_831 = NULL ;
char * V_832 , * V_451 , * V_595 , * V_833 [ 3 ] = { NULL , NULL , NULL } ;
T_2 V_4 = 0 , V_264 = 0 , V_834 = 0 , V_3 = 0 , V_835 = 0 ;
T_2 V_836 = 0 , V_837 = 0 , V_838 = 0 ;
int V_169 ;
T_1 V_839 = V_8 -> V_350 . V_840 ;
V_10 = (struct V_408 * ) V_820 ;
V_385 = & V_8 -> V_385 ;
V_826 = & V_824 -> V_841 ;
V_169 = 0 ;
V_64 = F_251 ( V_842 ) ;
if ( V_64 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_831 = F_251 ( V_842 ) ;
if ( V_831 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
if ( F_106 ( V_243 , V_10 -> V_452 , V_10 -> V_66 ) ) {
V_169 = - V_453 ;
goto exit;
}
V_830 = V_385 -> V_843 ;
F_246 ( V_8 , V_844 ) ;
V_829 = V_385 -> V_829 ;
F_247 ( V_8 , V_845 ) ;
V_832 = V_243 ;
F_29 ( L_342 , V_342 , V_243 ) ;
V_4 = 0 ;
while ( ( V_595 = F_252 ( & V_832 , L_343 ) ) != NULL ) {
if ( V_4 > 2 )
break;
V_833 [ V_4 ] = V_595 ;
V_4 ++ ;
}
V_8 -> V_350 . V_840 = 0 ;
if ( strcmp ( V_833 [ 0 ] , L_169 ) == 0 ) {
sprintf ( V_243 , L_344 , ( V_822 -> V_846 ? L_345 : L_346 ) , ( V_822 -> V_847 ? L_345 : L_346 ) ) ;
goto exit;
} else if ( strcmp ( V_833 [ 0 ] , L_347 ) == 0 ) {
V_834 = V_848 ;
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_848 ; V_4 += 16 ) {
sprintf ( V_243 , L_348 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_827 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_827 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_351 ) == 0 ) {
V_834 = V_848 ;
if ( F_253 ( V_8 , 0 , V_834 , V_826 -> V_849 ) == V_188 ) {
F_29 ( L_352 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_848 ; V_4 += 16 ) {
sprintf ( V_243 , L_348 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_849 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_849 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_353 ) == 0 ) {
if ( ( V_833 [ 1 ] == NULL ) || ( V_833 [ 2 ] == NULL ) ) {
F_29 ( L_354 , V_342 ) ;
V_169 = - V_156 ;
goto exit;
}
V_3 = F_254 ( V_833 [ 1 ] , & V_451 , 16 ) ;
F_29 ( L_355 , V_342 , V_3 ) ;
V_835 = F_254 ( V_833 [ 2 ] , & V_451 , 10 ) ;
if ( V_835 == 0 ) {
F_29 ( L_356 , V_342 ) ;
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_357 , V_342 , V_835 ) ;
F_255 ( V_8 , V_850 , V_851 , ( void * ) & V_836 , false ) ;
if ( ( V_3 + V_835 ) > V_836 ) {
F_29 ( L_358 , V_342 , V_3 , V_835 ) ;
V_169 = - V_156 ;
goto exit;
}
if ( F_253 ( V_8 , V_3 , V_835 , V_64 ) == V_188 ) {
F_29 ( L_359 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
* V_243 = 0 ;
for ( V_4 = 0 ; V_4 < V_835 ; V_4 ++ )
sprintf ( V_243 , L_360 , V_243 , V_64 [ V_4 ] ) ;
} else if ( strcmp ( V_833 [ 0 ] , L_361 ) == 0 ) {
V_3 = 0 ;
V_834 = V_852 ;
if ( F_256 ( V_8 , false , V_3 , V_834 , V_831 ) == V_188 ) {
F_29 ( L_362 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_834 ; V_4 ++ ) {
sprintf ( V_243 , L_363 , V_243 , V_831 [ V_4 ] ) ;
if ( ( V_4 & 0xF ) == 0xF )
sprintf ( V_243 , L_57 , V_243 ) ;
else if ( ( V_4 & 0x7 ) == 0x7 )
sprintf ( V_243 , L_350 , V_243 ) ;
else
sprintf ( V_243 , L_364 , V_243 ) ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_365 ) == 0 ) {
V_835 = 6 ;
F_255 ( V_8 , V_850 , V_851 , ( void * ) & V_836 , false ) ;
if ( ( V_3 + V_835 ) > V_836 ) {
F_29 ( L_366 , V_342 , V_3 , V_835 ) ;
V_169 = - V_453 ;
goto exit;
}
if ( F_253 ( V_8 , V_3 , V_835 , V_64 ) == V_188 ) {
F_29 ( L_359 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
* V_243 = 0 ;
for ( V_4 = 0 ; V_4 < V_835 ; V_4 ++ ) {
sprintf ( V_243 , L_363 , V_243 , V_64 [ V_4 ] ) ;
if ( V_4 != ( V_835 - 1 ) )
sprintf ( V_243 , L_367 , V_243 ) ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_368 ) == 0 ) {
V_835 = 4 ;
F_255 ( V_8 , V_850 , V_851 , ( void * ) & V_836 , false ) ;
if ( ( V_3 + V_835 ) > V_836 ) {
F_29 ( L_366 , V_342 , V_3 , V_835 ) ;
V_169 = - V_453 ;
goto exit;
}
if ( F_253 ( V_8 , V_3 , V_835 , V_64 ) == V_188 ) {
F_29 ( L_369 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
* V_243 = 0 ;
for ( V_4 = 0 ; V_4 < V_835 ; V_4 ++ ) {
sprintf ( V_243 , L_370 , V_243 , V_64 [ V_4 ] ) ;
if ( V_4 != ( V_835 - 1 ) )
sprintf ( V_243 , L_371 , V_243 ) ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_372 ) == 0 ) {
F_257 ( V_8 , & V_837 ) ;
V_838 = F_258 ( V_8 ) ;
sprintf ( V_243 , L_373 , V_838 - V_837 ) ;
} else if ( strcmp ( V_833 [ 0 ] , L_374 ) == 0 ) {
V_834 = V_842 ;
if ( F_259 ( V_8 , 0 , V_834 , V_826 -> V_853 ) == V_188 ) {
F_29 ( L_375 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < 512 ; V_4 += 16 ) {
sprintf ( V_243 , L_376 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_853 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_853 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_377 ) == 0 ) {
V_834 = V_842 ;
if ( F_259 ( V_8 , 0 , V_834 , V_826 -> V_853 ) == V_188 ) {
F_29 ( L_375 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 512 ; V_4 < 1024 ; V_4 += 16 ) {
sprintf ( V_243 , L_376 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_853 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_853 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_378 ) == 0 ) {
if ( ( V_833 [ 1 ] == NULL ) || ( V_833 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_254 ( V_833 [ 1 ] , & V_451 , 16 ) ;
F_29 ( L_379 , V_342 , V_3 ) ;
V_835 = F_254 ( V_833 [ 2 ] , & V_451 , 10 ) ;
if ( V_835 == 0 ) {
F_29 ( L_380 , V_342 ) ;
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_357 , V_342 , V_835 ) ;
F_255 ( V_8 , V_854 , V_851 , ( void * ) & V_836 , false ) ;
if ( ( V_3 + V_835 ) > V_836 ) {
F_29 ( L_358 , V_342 , V_3 , V_835 ) ;
V_169 = - V_453 ;
goto exit;
}
if ( F_259 ( V_8 , V_3 , V_835 , V_64 ) == V_188 ) {
F_29 ( L_381 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
* V_243 = 0 ;
for ( V_4 = 0 ; V_4 < V_835 ; V_4 ++ )
sprintf ( V_243 , L_382 , V_243 , V_64 [ V_4 ] ) ;
} else if ( strcmp ( V_833 [ 0 ] , L_383 ) == 0 ) {
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < 512 ; V_4 += 16 ) {
sprintf ( V_243 , L_376 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_855 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_855 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_384 ) == 0 ) {
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 512 ; V_4 < 1024 ; V_4 += 16 ) {
sprintf ( V_243 , L_376 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_855 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_855 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_385 ) == 0 ) {
sprintf ( V_243 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_848 ; V_4 += 16 ) {
sprintf ( V_243 , L_348 , V_243 , V_4 ) ;
for ( V_264 = 0 ; V_264 < 8 ; V_264 ++ )
sprintf ( V_243 , L_349 , V_243 , V_826 -> V_856 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_350 , V_243 ) ;
for (; V_264 < 16 ; V_264 ++ )
sprintf ( V_243 , L_386 , V_243 , V_826 -> V_856 [ V_4 + V_264 ] ) ;
sprintf ( V_243 , L_57 , V_243 ) ;
}
} else {
sprintf ( V_243 , L_387 ) ;
}
exit:
F_40 ( V_64 ) ;
F_40 ( V_831 ) ;
if ( ! V_169 )
V_10 -> V_66 = strlen ( V_243 ) ;
F_247 ( V_8 , V_829 ) ;
F_246 ( V_8 , V_830 ) ;
V_8 -> V_350 . V_840 = V_839 ;
return V_169 ;
}
static int F_260 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_820 , char * V_243 )
{
struct V_7 * V_8 ;
struct V_411 * V_385 ;
struct V_823 * V_824 ;
struct V_825 * V_826 ;
T_1 V_829 = 0 , V_830 = 0 ;
T_4 V_4 , V_535 , V_536 ;
T_1 * V_857 = NULL ;
T_1 * V_858 = NULL ;
T_1 * V_859 = NULL ;
T_1 * V_860 = NULL ;
char * V_832 , * V_451 , * V_595 , * V_833 [ 3 ] = { NULL , NULL , NULL } ;
T_2 V_3 = 0 , V_835 = 0 , V_836 = 0 ;
int V_169 ;
V_8 = F_28 ( V_139 ) ;
V_385 = & V_8 -> V_385 ;
V_824 = F_250 ( V_8 ) ;
V_826 = & V_824 -> V_841 ;
V_169 = 0 ;
V_857 = F_251 ( 1024 ) ;
if ( V_857 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_858 = F_261 ( V_842 ) ;
if ( V_858 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_859 = F_261 ( V_848 ) ;
if ( V_859 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_860 = F_261 ( V_852 ) ;
if ( V_860 == NULL ) {
V_169 = - V_223 ;
goto exit;
}
V_830 = V_385 -> V_843 ;
F_246 ( V_8 , V_844 ) ;
V_829 = V_385 -> V_829 ;
F_247 ( V_8 , V_845 ) ;
V_832 = V_243 ;
F_29 ( L_342 , V_342 , V_243 ) ;
V_4 = 0 ;
while ( ( V_595 = F_252 ( & V_832 , L_343 ) ) != NULL ) {
if ( V_4 > 2 )
break;
V_833 [ V_4 ] = V_595 ;
V_4 ++ ;
}
if ( strcmp ( V_833 [ 0 ] , L_388 ) == 0 ) {
if ( ( V_833 [ 1 ] == NULL ) || ( V_833 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_254 ( V_833 [ 1 ] , & V_451 , 16 ) ;
V_3 &= 0xFFF ;
V_835 = strlen ( V_833 [ 2 ] ) ;
if ( V_835 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_835 /= 2 ;
if ( V_835 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_342 , V_3 ) ;
F_29 ( L_357 , V_342 , V_835 ) ;
F_29 ( L_389 , V_342 , V_833 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_835 ; V_535 ++ , V_536 += 2 )
V_857 [ V_535 ] = F_148 ( V_833 [ 2 ] [ V_536 ] , V_833 [ 2 ] [ V_536 + 1 ] ) ;
F_255 ( V_8 , V_850 , V_861 , ( void * ) & V_836 , false ) ;
if ( ( V_3 + V_835 ) > V_836 ) {
F_29 ( L_358 , V_342 , V_3 , V_835 ) ;
V_169 = - V_453 ;
goto exit;
}
if ( F_262 ( V_8 , V_3 , V_835 , V_857 ) == V_188 ) {
F_29 ( L_390 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_833 [ 0 ] , L_391 ) == 0 ) {
if ( ( V_833 [ 1 ] == NULL ) || ( V_833 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_254 ( V_833 [ 1 ] , & V_451 , 16 ) ;
V_3 &= 0xFFF ;
V_835 = strlen ( V_833 [ 2 ] ) ;
if ( V_835 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_835 /= 2 ;
if ( V_835 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_342 , V_3 ) ;
F_29 ( L_357 , V_342 , V_835 ) ;
F_29 ( L_392 , V_342 , V_833 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_835 ; V_535 ++ , V_536 += 2 )
V_860 [ V_535 ] = F_148 ( V_833 [ 2 ] [ V_536 ] , V_833 [ 2 ] [ V_536 + 1 ] ) ;
if ( F_256 ( V_8 , true , V_3 , V_835 , V_860 ) == V_188 ) {
F_29 ( L_369 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_833 [ 0 ] , L_365 ) == 0 ) {
if ( V_833 [ 1 ] == NULL ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = V_862 ;
V_835 = strlen ( V_833 [ 1 ] ) ;
if ( V_835 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_835 /= 2 ;
if ( V_835 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
if ( V_835 > 6 ) {
F_29 ( L_393 , V_342 , V_833 [ 1 ] ) ;
V_169 = - V_453 ;
goto exit;
}
F_29 ( L_379 , V_342 , V_3 ) ;
F_29 ( L_357 , V_342 , V_835 ) ;
F_29 ( L_394 , V_342 , V_833 [ 1 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_835 ; V_535 ++ , V_536 += 2 )
V_857 [ V_535 ] = F_148 ( V_833 [ 1 ] [ V_536 ] , V_833 [ 1 ] [ V_536 + 1 ] ) ;
F_255 ( V_8 , V_850 , V_861 , ( void * ) & V_836 , false ) ;
if ( ( V_3 + V_835 ) > V_836 ) {
F_29 ( L_358 , V_342 , V_3 , V_835 ) ;
V_169 = - V_453 ;
goto exit;
}
if ( F_262 ( V_8 , V_3 , V_835 , V_857 ) == V_188 ) {
F_29 ( L_390 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_833 [ 0 ] , L_368 ) == 0 ) {
if ( V_833 [ 1 ] == NULL ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = V_863 ;
V_835 = strlen ( V_833 [ 1 ] ) ;
if ( V_835 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_835 /= 2 ;
if ( V_835 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_342 , V_3 ) ;
F_29 ( L_357 , V_342 , V_835 ) ;
F_29 ( L_395 , V_342 , V_833 [ 1 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_835 ; V_535 ++ , V_536 += 2 )
V_857 [ V_535 ] = F_148 ( V_833 [ 1 ] [ V_536 ] , V_833 [ 1 ] [ V_536 + 1 ] ) ;
F_255 ( V_8 , V_850 , V_851 , ( void * ) & V_836 , false ) ;
if ( ( V_3 + V_835 ) > V_836 ) {
F_29 ( L_358 , V_342 , V_3 , V_835 ) ;
V_169 = - V_453 ;
goto exit;
}
if ( F_262 ( V_8 , V_3 , V_835 , V_857 ) == V_188 ) {
F_29 ( L_390 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_833 [ 0 ] , L_396 ) == 0 ) {
if ( ( V_833 [ 1 ] == NULL ) || ( V_833 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_254 ( V_833 [ 1 ] , & V_451 , 16 ) ;
V_3 &= 0xFFF ;
V_835 = strlen ( V_833 [ 2 ] ) ;
if ( V_835 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_835 /= 2 ;
if ( V_835 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_342 , V_3 ) ;
F_29 ( L_357 , V_342 , V_835 ) ;
F_29 ( L_397 , V_342 , V_833 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_835 ; V_535 ++ , V_536 += 2 )
V_857 [ V_535 ] = F_148 ( V_833 [ 2 ] [ V_536 ] , V_833 [ 2 ] [ V_536 + 1 ] ) ;
F_255 ( V_8 , V_854 , V_851 , ( void * ) & V_836 , false ) ;
if ( ( V_3 + V_835 ) > V_836 ) {
F_29 ( L_358 , V_342 , V_3 , V_835 ) ;
V_169 = - V_453 ;
goto exit;
}
if ( F_263 ( V_8 , V_3 , V_835 , V_857 ) == V_188 ) {
F_29 ( L_398 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_833 [ 0 ] , L_399 ) == 0 ) {
if ( ( V_833 [ 1 ] == NULL ) || ( V_833 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_254 ( V_833 [ 1 ] , & V_451 , 16 ) ;
V_3 &= 0xFFF ;
V_835 = strlen ( V_833 [ 2 ] ) ;
if ( V_835 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_835 /= 2 ;
if ( V_835 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_342 , V_3 ) ;
F_29 ( L_357 , V_342 , V_835 ) ;
F_29 ( L_400 , V_342 , V_833 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_835 ; V_535 ++ , V_536 += 2 )
V_826 -> V_855 [ V_3 + V_535 ] = F_148 ( V_833 [ 2 ] [ V_536 ] , V_833 [ 2 ] [ V_536 + 1 ] ) ;
} else if ( strcmp ( V_833 [ 0 ] , L_401 ) == 0 ) {
if ( F_259 ( V_8 , 0 , V_842 , V_826 -> V_855 ) == V_225 ) {
F_29 ( L_402 , V_342 ) ;
} else {
F_29 ( L_403 , V_342 ) ;
V_169 = - V_453 ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_404 ) == 0 ) {
if ( F_253 ( V_8 , 0 , V_842 , V_826 -> V_856 ) == V_225 ) {
F_29 ( L_402 , V_342 ) ;
} else {
F_29 ( L_405 , V_342 ) ;
V_169 = - V_453 ;
}
} else if ( strcmp ( V_833 [ 0 ] , L_406 ) == 0 ) {
memcpy ( V_826 -> V_864 , V_826 -> V_855 , V_842 ) ;
F_255 ( V_8 , V_854 , V_851 , ( void * ) & V_836 , false ) ;
if ( V_836 < 1 ) {
V_169 = - V_453 ;
goto exit;
}
if ( F_263 ( V_8 , 0x00 , V_842 , V_826 -> V_855 ) == V_188 ) {
F_29 ( L_407 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_833 [ 0 ] , L_408 ) == 0 ) {
F_255 ( V_8 , V_850 , V_851 , ( void * ) & V_836 , false ) ;
if ( V_836 < 1 ) {
V_169 = - V_453 ;
goto exit;
}
if ( F_262 ( V_8 , 0x00 , V_865 , V_826 -> V_856 ) == V_188 ) {
F_29 ( L_409 , V_342 ) ;
V_169 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_833 [ 0 ] , L_410 ) == 0 ) {
if ( ( V_833 [ 1 ] == NULL ) || ( V_833 [ 2 ] == NULL ) ) {
V_169 = - V_156 ;
goto exit;
}
V_3 = F_254 ( V_833 [ 1 ] , & V_451 , 16 ) ;
V_3 &= 0xFFF ;
V_835 = strlen ( V_833 [ 2 ] ) ;
if ( V_835 % 2 ) {
V_169 = - V_156 ;
goto exit;
}
V_835 /= 2 ;
if ( V_835 == 0 ) {
V_169 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_342 , V_3 ) ;
F_29 ( L_357 , V_342 , V_835 ) ;
F_29 ( L_411 , V_342 , V_833 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_835 ; V_535 ++ , V_536 += 2 )
V_826 -> V_856 [ V_3 + V_535 ] = F_148 ( V_833 [ 2 ] [ V_536 ] , V_833 [ 2 ] [ V_536 + 1 ] ) ;
}
exit:
F_40 ( V_857 ) ;
F_40 ( V_858 ) ;
F_40 ( V_859 ) ;
F_40 ( V_860 ) ;
F_247 ( V_8 , V_829 ) ;
F_246 ( V_8 , V_830 ) ;
return V_169 ;
}
static int F_264 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
char * V_832 , * V_866 , * V_451 ;
char * V_867 ;
char V_467 ;
T_4 V_3 , V_64 ;
int V_140 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_832 = V_243 ;
V_866 = strpbrk ( V_832 , L_412 ) ;
if ( V_866 == NULL )
return - V_156 ;
* V_866 = 0 ;
V_867 = V_832 ;
V_832 = V_866 + 1 ;
V_866 = strpbrk ( V_832 , L_412 ) ;
if ( V_866 == NULL )
return - V_156 ;
* V_866 = 0 ;
V_3 = F_254 ( V_832 , & V_451 , 16 ) ;
if ( V_3 > 0x3FFF )
return - V_156 ;
V_832 = V_866 + 1 ;
if ( ( V_832 - V_243 ) >= V_10 -> V_66 )
return - V_156 ;
V_64 = F_254 ( V_832 , & V_451 , 16 ) ;
V_140 = 0 ;
V_467 = V_867 [ 0 ] ;
switch ( V_467 ) {
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
static int F_265 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
char * V_832 , * V_866 , * V_451 ;
char * V_867 ;
char V_467 ;
char V_64 [ 20 ] , V_833 [ 20 ] ;
T_4 V_3 ;
T_4 V_140 , V_4 = 0 , V_264 = 0 , V_870 = 0 ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
F_4 ( V_64 , 0 , 20 ) ;
F_4 ( V_833 , 0 , 20 ) ;
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
V_832 = V_868 ;
V_866 = strpbrk ( V_832 , L_412 ) ;
if ( V_866 == NULL ) {
F_40 ( V_868 ) ;
return - V_156 ;
}
* V_866 = 0 ;
V_867 = V_832 ;
V_832 = V_866 + 1 ;
if ( ( V_832 - V_868 ) >= V_10 -> V_66 ) {
F_40 ( V_868 ) ;
return - V_156 ;
}
F_40 ( V_868 ) ;
V_3 = F_254 ( V_832 , & V_451 , 16 ) ;
if ( V_3 > 0x3FFF )
return - V_156 ;
V_140 = 0 ;
V_467 = V_867 [ 0 ] ;
switch ( V_467 ) {
case 'b' :
sprintf ( V_243 , L_413 , F_107 ( V_8 , V_3 ) ) ;
V_10 -> V_66 = strlen ( V_243 ) ;
break;
case 'w' :
sprintf ( V_64 , L_414 , F_108 ( V_8 , V_3 ) ) ;
for ( V_4 = 0 ; V_4 <= strlen ( V_64 ) ; V_4 ++ ) {
if ( V_4 % 2 == 0 ) {
V_833 [ V_264 ] = ' ' ;
V_264 ++ ;
}
if ( V_64 [ V_4 ] != '\0' )
V_833 [ V_264 ] = V_64 [ V_4 ] ;
V_264 ++ ;
}
V_832 = V_833 ;
F_29 ( L_415 , V_832 ) ;
while ( * V_832 != '\0' ) {
V_866 = strpbrk ( V_832 , L_416 ) ;
if ( ! V_866 )
break;
V_866 ++ ;
if ( * V_866 != '\0' ) {
V_870 = F_254 ( V_866 , & V_451 , 16 ) ;
sprintf ( V_243 , L_417 , V_243 , V_870 ) ;
} else {
break;
}
V_832 = V_866 ;
}
V_10 -> V_66 = 6 ;
break;
case 'd' :
sprintf ( V_64 , L_418 , F_109 ( V_8 , V_3 ) ) ;
for ( V_4 = 0 ; V_4 <= strlen ( V_64 ) ; V_4 ++ ) {
if ( V_4 % 2 == 0 ) {
V_833 [ V_264 ] = ' ' ;
V_264 ++ ;
}
if ( V_64 [ V_4 ] != '\0' )
V_833 [ V_264 ] = V_64 [ V_4 ] ;
V_264 ++ ;
}
V_832 = V_833 ;
F_29 ( L_415 , V_832 ) ;
while ( * V_832 != '\0' ) {
V_866 = strpbrk ( V_832 , L_416 ) ;
if ( ! V_866 )
break;
V_866 ++ ;
if ( * V_866 != '\0' ) {
V_870 = F_254 ( V_866 , & V_451 , 16 ) ;
sprintf ( V_243 , L_417 , V_243 , V_870 ) ;
} else {
break;
}
V_832 = V_866 ;
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
static int F_267 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_4 V_455 , V_3 , V_64 ;
int V_140 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_140 = sscanf ( V_243 , L_97 , & V_455 , & V_3 , & V_64 ) ;
if ( V_140 < 3 )
return - V_156 ;
if ( V_455 >= V_871 )
return - V_156 ;
if ( V_3 > 0xFF )
return - V_156 ;
if ( V_64 > 0xFFFFF )
return - V_156 ;
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
F_268 ( V_8 , V_455 , V_3 , V_64 ) ;
sprintf ( V_243 , L_419 ) ;
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_269 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
char * V_832 , * V_866 , * V_451 ;
char V_64 [ 20 ] , V_833 [ 20 ] ;
T_4 V_455 , V_3 ;
T_4 V_140 , V_4 = 0 , V_264 = 0 , V_872 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
V_140 = sscanf ( V_868 , L_91 , & V_455 , & V_3 ) ;
F_40 ( V_868 ) ;
if ( V_140 < 2 )
return - V_156 ;
if ( V_455 >= V_871 )
return - V_156 ;
if ( V_3 > 0xFF )
return - V_156 ;
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
sprintf ( V_64 , L_418 , F_270 ( V_8 , V_455 , V_3 ) ) ;
for ( V_4 = 0 ; V_4 <= strlen ( V_64 ) ; V_4 ++ ) {
if ( V_4 % 2 == 0 ) {
V_833 [ V_264 ] = ' ' ;
V_264 ++ ;
}
V_833 [ V_264 ] = V_64 [ V_4 ] ;
V_264 ++ ;
}
V_832 = V_833 ;
F_29 ( L_415 , V_832 ) ;
while ( * V_832 != '\0' ) {
V_866 = strpbrk ( V_832 , L_416 ) ;
V_866 ++ ;
if ( * V_866 != '\0' ) {
V_872 = F_254 ( V_866 , & V_451 , 16 ) ;
sprintf ( V_243 , L_417 , V_243 , V_872 ) ;
} else {
break;
}
V_832 = V_866 ;
}
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_271 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 -> V_350 . V_351 == 0 ) {
V_8 -> V_350 . V_351 = 1 ;
F_247 ( V_8 , V_845 ) ;
F_99 ( V_8 ) ;
F_272 ( V_8 , 1 ) ;
}
if ( V_8 -> V_350 . V_351 == 0 )
return - V_253 ;
if ( V_8 -> V_873 . V_86 == V_874 ) {
if ( F_273 ( V_8 ) == V_188 )
return - V_253 ;
V_8 -> V_873 . V_86 = V_875 ;
}
return 0 ;
}
static int F_274 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 -> V_350 . V_351 == 1 ) {
F_275 ( V_8 ) ;
V_8 -> V_350 . V_351 = 0 ;
}
if ( V_8 -> V_873 . V_86 != V_874 ) {
F_276 ( V_8 ) ;
V_8 -> V_873 . V_86 = V_874 ;
}
return 0 ;
}
static int F_277 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_4 V_41 = V_876 ;
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
V_41 = F_278 ( V_868 ) ;
sprintf ( V_243 , L_420 , V_41 ) ;
F_40 ( V_868 ) ;
if ( V_41 <= 0x7f )
V_41 = F_279 ( ( T_1 ) V_41 ) ;
else
V_41 = ( V_41 - 0x80 + V_877 ) ;
if ( V_41 >= V_878 )
return - V_156 ;
V_8 -> V_873 . V_879 = V_41 ;
F_280 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
return 0 ;
}
static int F_281 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
T_4 V_516 = 1 ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
V_516 = F_278 ( V_868 ) ;
sprintf ( V_243 , L_421 , V_8 -> V_873 . V_516 , V_516 ) ;
V_8 -> V_873 . V_516 = V_516 ;
F_282 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_868 ) ;
return 0 ;
}
static int F_283 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_4 V_880 = 0 , V_881 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
sscanf ( V_243 , L_422 , & V_880 , & V_881 ) ;
if ( V_880 != V_882 )
V_880 = V_523 ;
V_8 -> V_873 . V_880 = ( T_1 ) V_880 ;
V_8 -> V_873 . V_883 = V_881 ;
F_284 ( V_8 ) ;
return 0 ;
}
static int F_285 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_4 V_884 = 0 , V_885 = 0 ;
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
sscanf ( V_868 , L_423 , & V_884 , & V_885 ) ;
sprintf ( V_243 , L_424 , V_884 , V_885 ) ;
V_8 -> V_873 . V_886 = ( T_1 ) V_884 ;
V_8 -> V_873 . V_887 = ( T_1 ) V_885 ;
V_8 -> V_873 . V_888 = 1 ;
F_286 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_868 ) ;
return 0 ;
}
static int F_287 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_1 V_4 ;
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
T_2 V_889 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
sprintf ( V_243 , L_425 , V_868 ) ;
for ( V_4 = 0 ; V_4 < strlen ( V_868 ) ; V_4 ++ ) {
switch ( V_868 [ V_4 ] ) {
case 'a' :
V_889 |= V_890 ;
break;
case 'b' :
V_889 |= V_891 ;
break;
}
}
V_8 -> V_873 . V_892 = V_889 ;
F_288 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_868 ) ;
return 0 ;
}
static int F_289 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_1 V_4 ;
T_2 V_889 = 0 ;
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
sprintf ( V_243 , L_426 , V_868 ) ;
for ( V_4 = 0 ; V_4 < strlen ( V_868 ) ; V_4 ++ ) {
switch ( V_868 [ V_4 ] ) {
case 'a' :
V_889 |= V_890 ;
break;
case 'b' :
V_889 |= V_891 ;
break;
}
}
V_8 -> V_873 . V_893 = V_889 ;
F_288 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_243 ) ;
F_40 ( V_868 ) ;
return 0 ;
}
static int F_290 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_4 V_894 = 1 , V_895 = 1 , V_896 = 1 , V_897 = 1 , V_898 = 1 , V_899 = 1 , V_31 = 1 ;
T_4 V_900 = 1 ;
T_4 V_901 = 0 ;
struct V_902 * V_903 ;
struct V_904 * V_905 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_903 = & V_8 -> V_873 ;
if ( F_106 ( V_243 , V_10 -> V_452 , V_10 -> V_66 ) )
return - V_453 ;
F_29 ( L_342 , V_342 , V_243 ) ;
V_895 = strncmp ( V_243 , L_427 , 5 ) ;
V_896 = strncmp ( V_243 , L_428 , 20 ) ;
V_897 = strncmp ( V_243 , L_429 , 20 ) ;
V_898 = strncmp ( V_243 , L_430 , 20 ) ;
V_899 = strncmp ( V_243 , L_431 , 20 ) ;
V_894 = strncmp ( V_243 , L_432 , 20 ) ;
V_31 = strncmp ( V_243 , L_433 , 4 ) ;
sscanf ( V_243 , L_434 , & V_901 ) ;
F_4 ( V_243 , '\0' , sizeof( * V_243 ) ) ;
if ( V_31 == 0 ) {
V_900 = 0 ;
V_903 -> V_906 . V_31 = 1 ;
sprintf ( V_243 , L_435 ) ;
} else {
V_900 = 1 ;
if ( V_903 -> V_86 != V_875 ) {
if ( V_903 -> V_906 . V_31 != 1 ) {
F_29 ( L_436 , V_342 , V_903 -> V_86 ) ;
return - V_453 ;
}
}
}
if ( V_894 == 0 || V_895 == 0 )
V_903 -> V_86 = V_907 ;
if ( V_899 == 0 )
V_903 -> V_86 = V_908 ;
if ( V_896 == 0 )
V_903 -> V_86 = V_909 ;
if ( V_897 == 0 )
V_903 -> V_86 = V_910 ;
if ( V_898 == 0 )
V_903 -> V_86 = V_911 ;
switch ( V_903 -> V_86 ) {
case V_907 :
if ( V_900 == 0 ) {
V_903 -> V_906 . V_31 = 1 ;
V_903 -> V_86 = V_875 ;
sprintf ( V_243 , L_435 ) ;
} else if ( V_903 -> V_906 . V_31 == 1 ) {
sprintf ( V_243 , L_437 , V_901 ) ;
V_903 -> V_906 . V_31 = 0 ;
V_903 -> V_906 . V_901 = V_901 ;
V_903 -> V_906 . V_912 = 2 ;
V_905 = & V_903 -> V_906 . V_913 ;
V_905 -> V_914 = 1500 ;
F_4 ( V_905 -> V_915 , 0xFF , V_23 ) ;
F_291 ( V_8 ) ;
} else {
return - V_453 ;
}
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
case V_908 :
if ( V_900 != 0 )
sprintf ( V_243 , L_438 ) ;
F_292 ( V_8 , ( T_1 ) V_900 ) ;
break;
case V_909 :
if ( V_900 != 0 )
sprintf ( V_243 , L_438 ) ;
F_293 ( V_8 , ( T_1 ) V_900 ) ;
break;
case V_910 :
if ( V_900 != 0 ) {
if ( V_903 -> V_879 <= V_916 ) {
sprintf ( V_243 , L_438 ) ;
F_294 ( V_8 , ( T_1 ) V_900 ) ;
} else {
sprintf ( V_243 , L_439 ) ;
}
}
break;
case V_911 :
if ( V_900 != 0 )
sprintf ( V_243 , L_438 ) ;
F_295 ( V_8 , ( T_1 ) V_900 ) ;
break;
default:
sprintf ( V_243 , L_440 ) ;
return - V_453 ;
}
if ( V_900 == 1 && V_903 -> V_86 != V_875 ) {
struct V_902 * V_903 = & V_8 -> V_873 ;
if ( V_903 -> V_906 . V_31 == 0 ) {
V_903 -> V_906 . V_31 = 1 ;
F_79 ( 5 ) ;
}
V_903 -> V_906 . V_31 = 0 ;
V_903 -> V_906 . V_901 = 1 ;
F_291 ( V_8 ) ;
} else {
V_903 -> V_86 = V_875 ;
}
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_296 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_1 V_917 = 0 , V_918 = 0 , V_919 ;
T_4 V_920 = 0 , V_921 = 0 , V_922 = 0 , V_923 = 0 , V_924 = 0 , V_925 = 0 , V_926 = 0 , V_927 = 0 ;
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
F_29 ( L_441 , V_342 , V_868 ) ;
V_917 = ( strncmp ( V_868 , L_442 , 5 ) == 0 ) ? 1 : 0 ;
V_918 = ( strncmp ( V_868 , L_433 , 5 ) == 0 ) ? 1 : 0 ;
V_919 = ( strncmp ( V_868 , L_443 , 3 ) == 0 ) ? 1 : 0 ;
if ( V_917 ) {
sprintf ( V_243 , L_442 ) ;
F_297 ( V_8 , V_917 ) ;
} else if ( V_918 ) {
F_297 ( V_8 , 0 ) ;
sprintf ( V_243 , L_444 , V_8 -> V_873 . V_928 , V_8 -> V_873 . V_929 ) ;
} else if ( V_919 ) {
V_920 = F_298 ( V_8 , 0xf88 , 0xffffffff ) ;
V_921 = F_298 ( V_8 , 0xf84 , 0xffffffff ) ;
V_922 = F_298 ( V_8 , 0xf94 , 0x0000FFFF ) ;
V_923 = F_298 ( V_8 , 0xf94 , 0xFFFF0000 ) ;
V_924 = F_298 ( V_8 , 0xf90 , 0x0000FFFF ) ;
V_925 = F_298 ( V_8 , 0xf90 , 0xFFFF0000 ) ;
V_926 = F_298 ( V_8 , 0xcf0 , 0x0000FFFF ) ;
V_926 = F_298 ( V_8 , 0xcf2 , 0xFFFF0000 ) ;
V_926 = F_298 ( V_8 , 0xda0 , 0xFFFF0000 ) ;
V_926 = F_298 ( V_8 , 0xda4 , 0x0000FFFF ) ;
V_926 = F_298 ( V_8 , 0xda4 , 0xFFFF0000 ) ;
V_926 = F_298 ( V_8 , 0xda8 , 0x0000FFFF ) ;
V_927 = ( F_107 ( V_8 , 0xa5b ) << 8 ) | ( F_107 ( V_8 , 0xa5c ) ) ;
sprintf ( V_243 , L_445 , V_920 + V_922 + V_924 , V_921 + V_923 + V_925 , V_926 + V_927 ) ;
}
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_868 ) ;
return 0 ;
}
static int F_299 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_4 V_930 , V_931 , V_932 , V_933 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_930 = V_8 -> V_873 . V_906 . V_934 ;
V_931 = 0 ;
V_932 = V_8 -> V_873 . V_928 ;
V_933 = V_8 -> V_873 . V_929 ;
F_4 ( V_243 , '\0' , 128 ) ;
sprintf ( V_243 , L_446 , V_930 , V_931 , V_932 , V_933 ) ;
V_10 -> V_66 = strlen ( V_243 ) + 1 ;
return 0 ;
}
static int F_300 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_1 V_675 ;
T_4 V_935 ;
T_8 V_140 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
F_4 ( V_243 , 0 , V_10 -> V_66 ) ;
V_675 = 1 ;
if ( V_10 -> V_66 > 1 ) {
if ( strncmp ( V_868 , L_433 , 4 ) == 0 ) {
V_675 = 0 ;
sprintf ( V_243 , L_447 ) ;
} else if ( sscanf ( V_868 , L_448 , & V_935 ) ) {
V_140 = F_301 ( V_8 , ( T_1 ) V_935 ) ;
if ( V_140 == V_188 )
return - V_253 ;
sprintf ( V_243 , L_449 , V_935 ) ;
} else {
F_40 ( V_868 ) ;
return - V_156 ;
}
}
F_40 ( V_868 ) ;
V_140 = F_302 ( V_8 , V_675 ) ;
if ( V_140 == V_188 )
return - V_253 ;
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_303 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
strcpy ( V_243 , V_868 ) ;
V_10 -> V_66 = F_304 ( V_8 , V_243 ) ;
F_40 ( V_868 ) ;
return 0 ;
}
static int F_305 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_1 V_288 ;
T_2 V_936 = 1 ;
T_2 V_3 = V_937 ;
T_2 V_116 = 1 ;
T_2 V_836 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( F_106 ( V_243 , V_10 -> V_452 , V_10 -> V_66 ) )
return - V_453 ;
V_936 = strncmp ( V_243 , L_450 , 6 ) ;
F_306 ( V_8 , & V_288 ) ;
if ( V_936 == 0 ) {
F_255 ( V_8 , V_850 , V_851 , ( void * ) & V_836 , false ) ;
if ( 2 > V_836 ) {
F_29 ( L_451 ) ;
return - V_453 ;
}
if ( F_262 ( V_8 , V_3 , V_116 , & V_288 ) == V_188 ) {
F_29 ( L_452 ) ;
return - V_453 ;
} else {
sprintf ( V_243 , L_453 , V_288 ) ;
}
} else {
sprintf ( V_243 , L_454 , V_288 ) ;
}
V_10 -> V_66 = strlen ( V_243 ) ;
return 0 ;
}
static int F_307 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
struct V_902 * V_903 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_903 = & V_8 -> V_873 ;
V_903 -> V_906 . V_934 = 0 ;
V_903 -> V_938 = 0 ;
V_903 -> V_928 = 0 ;
V_903 -> V_929 = 0 ;
F_308 ( V_8 , 0xf14 , V_939 , 0x1 ) ;
F_79 ( 10 ) ;
F_308 ( V_8 , 0xf14 , V_939 , 0x0 ) ;
return 0 ;
}
static int F_309 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
T_4 V_104 ;
T_1 V_630 , V_631 = 0 ;
T_4 V_4 , V_264 = 1 , V_455 ;
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
F_190 ( V_8 , V_632 , ( T_1 * ) ( & V_630 ) ) ;
F_29 ( L_194 ) ;
if ( ( V_633 == V_630 ) || ( V_634 == V_630 ) )
V_631 = 1 ;
else
V_631 = 2 ;
for ( V_455 = 0 ; V_455 < V_631 ; V_455 ++ ) {
for ( V_4 = 0 ; V_4 < 0x34 ; V_4 ++ ) {
V_104 = F_115 ( V_8 , V_455 , V_4 , 0xffffffff ) ;
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
static int F_310 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_408 * V_10 , char * V_243 )
{
char * V_868 = F_266 ( V_10 -> V_66 , V_869 ) ;
T_4 V_940 ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_868 ) ;
return - V_453 ;
}
F_29 ( L_456 , V_342 , V_868 ) ;
sscanf ( V_868 , L_457 , & V_940 ) ;
F_40 ( V_868 ) ;
return 0 ;
}
static int F_311 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_868 = F_266 ( V_10 -> V_64 . V_66 , V_869 ) ;
T_1 V_941 = 1 , V_942 = 1 ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_64 . V_452 , V_10 -> V_64 . V_66 ) )
return - V_453 ;
F_29 ( L_456 , V_342 , V_868 ) ;
V_941 = strncmp ( V_868 , L_183 , 2 ) ;
V_942 = strncmp ( V_868 , L_458 , 3 ) ;
if ( V_941 == 0 ) {
F_312 ( V_8 , true ) ;
F_29 ( L_459 , V_342 ) ;
} else if ( V_942 == 0 ) {
F_312 ( V_8 , false ) ;
F_29 ( L_460 , V_342 ) ;
}
F_40 ( V_868 ) ;
return 0 ;
}
static int F_313 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_868 = F_266 ( V_10 -> V_64 . V_66 , V_869 ) ;
T_1 V_943 = 1 ;
struct V_821 * V_822 = F_249 ( V_8 ) ;
if ( ! V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_10 -> V_64 . V_452 , V_10 -> V_64 . V_66 ) )
return - V_453 ;
F_29 ( L_456 , V_342 , V_868 ) ;
V_943 = strncmp ( V_868 , L_461 , 8 ) ;
if ( V_943 == 0 ) {
F_29 ( L_462 , V_342 ) ;
if ( V_822 -> V_944 )
sprintf ( V_243 , L_463 ) ;
else
sprintf ( V_243 , L_464 ) ;
}
V_10 -> V_64 . V_66 = strlen ( V_243 ) + 1 ;
F_40 ( V_868 ) ;
return 0 ;
}
static int F_314 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_820 , char * V_243 )
{
struct V_408 * V_10 = (struct V_408 * ) V_820 ;
T_4 V_945 = V_10 -> V_65 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 == NULL )
return - V_946 ;
if ( V_243 == NULL ) {
V_10 -> V_66 = 0 ;
return - V_947 ;
}
switch ( V_945 ) {
case V_465 :
F_29 ( L_465 ) ;
F_271 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_948 :
F_29 ( L_466 ) ;
F_274 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_949 :
F_29 ( L_467 ) ;
F_283 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_950 :
F_29 ( L_468 ) ;
F_307 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_951 :
F_29 ( L_469 ) ;
F_311 ( V_139 , V_27 , V_820 , V_243 ) ;
break;
case V_952 :
F_29 ( L_470 ) ;
F_180 ( V_139 , V_27 , V_820 , V_243 ) ;
break;
}
return 0 ;
}
static int F_315 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_820 , char * V_243 )
{
struct V_408 * V_10 = (struct V_408 * ) V_820 ;
T_4 V_945 = V_10 -> V_65 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 == NULL )
return - V_946 ;
if ( V_243 == NULL ) {
V_10 -> V_66 = 0 ;
return - V_947 ;
}
switch ( V_945 ) {
case V_468 :
F_264 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_953 :
F_267 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_954 :
F_29 ( L_471 ) ;
F_310 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_955 :
F_29 ( L_472 ) ;
F_281 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_466 :
F_29 ( L_473 ) ;
F_265 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_956 :
F_29 ( L_474 ) ;
F_269 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_957 :
F_29 ( L_475 ) ;
F_277 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_958 :
F_29 ( L_476 ) ;
F_285 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_959 :
F_29 ( L_477 ) ;
F_287 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_960 :
F_29 ( L_478 ) ;
F_289 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_961 :
F_299 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_962 :
F_29 ( L_479 ) ;
F_290 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_963 :
F_29 ( L_480 ) ;
F_296 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_964 :
F_29 ( L_481 ) ;
F_248 ( V_139 , V_27 , V_820 , V_243 ) ;
break;
case V_965 :
F_29 ( L_482 ) ;
F_309 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_966 :
F_29 ( L_483 ) ;
F_303 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_967 :
F_29 ( L_484 ) ;
F_305 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_968 :
F_29 ( L_485 ) ;
F_313 ( V_139 , V_27 , V_820 , V_243 ) ;
break;
case V_969 :
F_29 ( L_486 ) ;
F_300 ( V_139 , V_27 , V_10 , V_243 ) ;
break;
case V_970 :
F_29 ( L_487 ) ;
F_260 ( V_139 , V_27 , V_820 , V_243 ) ;
break;
}
F_79 ( 10 ) ;
return 0 ;
}
static int F_316 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
return 0 ;
}
static int F_317 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
return 0 ;
}
static int F_318 (
struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_243 )
{
T_4 V_363 ;
T_1 * V_502 , * V_832 ;
char * V_451 ;
T_1 * V_971 = L_343 ;
F_29 ( L_488 , V_342 ) ;
V_363 = V_10 -> V_64 . V_66 ;
V_502 = ( T_1 * ) F_43 ( V_363 ) ;
if ( V_502 == NULL ) {
F_29 ( L_489 , V_342 ) ;
return - V_223 ;
}
if ( F_106 ( V_502 , V_10 -> V_64 . V_452 , V_363 ) ) {
F_40 ( V_502 ) ;
F_29 ( L_490 , V_342 ) ;
return - V_453 ;
}
F_29 ( L_491 , V_342 , V_502 ) ;
V_451 = ( char * ) V_502 ;
V_832 = F_252 ( & V_451 , V_971 ) ;
if ( ( V_832 == NULL ) || ( strlen ( V_832 ) == 0 ) ) {
F_40 ( V_502 ) ;
F_29 ( L_492 , V_342 ) ;
return - V_453 ;
}
F_40 ( V_502 ) ;
return 0 ;
}
static struct V_972 * F_319 ( struct V_138 * V_139 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_972 * V_973 = & V_8 -> V_974 ;
int V_975 = 0 ;
int V_976 = 0 ;
int V_977 = 0 ;
if ( ! F_25 ( & V_8 -> V_15 , V_128 ) ) {
V_973 -> V_123 . V_123 = 0 ;
V_973 -> V_123 . V_135 = 0 ;
V_973 -> V_123 . V_136 = 0 ;
} else {
V_975 = V_8 -> V_129 . V_130 ;
V_976 = V_8 -> V_129 . V_131 ;
V_977 = V_8 -> V_129 . V_136 ;
V_973 -> V_123 . V_135 = V_975 ;
V_973 -> V_123 . V_123 = V_976 ;
V_973 -> V_123 . V_136 = V_977 ;
}
V_973 -> V_123 . V_124 = V_978 ;
return & V_8 -> V_974 ;
}
static int F_320 ( T_9 args )
{
int V_979 = args & V_980 ;
int type = ( args & V_981 ) >> 12 ;
return V_979 * V_982 [ type ] ;
}
static int F_321 ( struct V_138 * V_139 , union V_9 * V_983 )
{
int V_169 = 0 ;
T_1 * V_868 = NULL ;
T_4 V_984 = 0 ;
const char V_971 [] = L_416 ;
T_1 * V_985 = NULL ;
T_4 V_986 = 0 ;
T_4 V_901 = 0 ;
T_1 * V_987 = NULL ;
T_4 V_988 = 0 ;
char * V_989 = NULL ;
T_1 V_990 [ 17 ] = { 0 } ;
T_4 V_991 ;
T_8 V_363 ;
T_1 * V_243 = NULL ;
T_4 V_992 = 0 ;
T_8 V_993 ;
const T_10 * V_994 ;
const struct V_995 * V_996 ;
T_4 V_997 ;
T_10 V_490 ;
int V_324 ;
int V_945 = 0 ;
int V_464 = 0 ;
union V_9 V_820 ;
memcpy ( & V_820 , V_983 , sizeof( V_820 ) ) ;
V_984 = V_820 . V_64 . V_66 ;
V_868 = F_43 ( V_984 ) ;
if ( NULL == V_868 )
return - V_223 ;
if ( F_106 ( V_868 , V_820 . V_64 . V_452 , V_984 ) ) {
V_169 = - V_453 ;
goto exit;
}
V_989 = V_868 ;
V_363 = V_984 ;
sscanf ( V_989 , L_493 , V_990 ) ;
V_991 = strlen ( V_990 ) ;
F_29 ( L_494 , V_342 , V_990 ) ;
if ( V_991 > 0 )
V_991 += 1 ;
V_989 += V_991 ;
V_363 -= V_991 ;
F_29 ( L_495 , V_342 , V_989 ) ;
V_994 = V_998 ;
V_996 = V_999 ;
V_997 = sizeof( V_999 ) / sizeof( struct V_995 ) ;
if ( V_997 == 0 ) {
V_169 = - V_189 ;
goto exit;
}
V_993 = - 1 ;
while ( ( ++ V_993 < V_997 ) && strcmp ( V_996 [ V_993 ] . V_78 , V_990 ) ) ;
if ( V_993 == V_997 ) {
V_169 = - V_189 ;
goto exit;
}
if ( V_996 [ V_993 ] . V_60 < V_1000 ) {
int V_264 = - 1 ;
while ( ( ++ V_264 < V_997 ) && ( ( V_996 [ V_264 ] . V_78 [ 0 ] != '\0' ) ||
( V_996 [ V_264 ] . V_1001 != V_996 [ V_993 ] . V_1001 ) ||
( V_996 [ V_264 ] . V_1002 != V_996 [ V_993 ] . V_1002 ) ) ) ;
if ( V_264 == V_997 ) {
V_169 = - V_156 ;
goto exit;
}
V_945 = V_996 [ V_993 ] . V_60 ;
V_464 = sizeof( V_1003 ) ;
V_993 = V_264 ;
}
V_987 = F_43 ( 4096 ) ;
if ( NULL == V_987 ) {
V_169 = - V_223 ;
goto exit;
}
if ( ( V_996 [ V_993 ] . V_1001 & V_981 ) &&
( V_996 [ V_993 ] . V_1001 & V_980 ) ) {
T_1 * V_1004 ;
switch ( V_996 [ V_993 ] . V_1001 & V_981 ) {
case V_1005 :
V_901 = 0 ;
do {
V_1004 = F_252 ( & V_989 , V_971 ) ;
if ( NULL == V_1004 )
break;
sscanf ( V_1004 , L_496 , & V_324 ) ;
V_987 [ V_901 ++ ] = ( T_1 ) V_324 ;
} while ( 1 );
V_988 = V_901 ;
V_820 . V_64 . V_66 = V_901 ;
if ( V_820 . V_64 . V_66 > ( V_996 [ V_993 ] . V_1001 & V_980 ) )
V_820 . V_64 . V_66 = V_996 [ V_993 ] . V_1001 & V_980 ;
break;
case V_1006 :
V_901 = 0 ;
do {
V_1004 = F_252 ( & V_989 , V_971 ) ;
if ( NULL == V_1004 )
break;
sscanf ( V_1004 , L_496 , & V_324 ) ;
( ( T_8 * ) V_987 ) [ V_901 ++ ] = ( T_8 ) V_324 ;
} while ( 1 );
V_988 = V_901 * sizeof( T_8 ) ;
V_820 . V_64 . V_66 = V_901 ;
if ( V_820 . V_64 . V_66 > ( V_996 [ V_993 ] . V_1001 & V_980 ) )
V_820 . V_64 . V_66 = V_996 [ V_993 ] . V_1001 & V_980 ;
break;
case V_1007 :
if ( V_363 > 0 ) {
V_820 . V_64 . V_66 = V_363 ;
if ( V_820 . V_64 . V_66 > ( V_996 [ V_993 ] . V_1001 & V_980 ) )
V_820 . V_64 . V_66 = V_996 [ V_993 ] . V_1001 & V_980 ;
memcpy ( V_987 , V_989 , V_820 . V_64 . V_66 ) ;
} else {
V_820 . V_64 . V_66 = 1 ;
V_987 [ 0 ] = '\0' ;
}
V_988 = V_820 . V_64 . V_66 ;
break;
default:
F_29 ( L_497 , V_342 ) ;
V_169 = - 1 ;
goto exit;
}
if ( ( V_996 [ V_993 ] . V_1001 & V_1008 ) &&
( V_820 . V_64 . V_66 != ( V_996 [ V_993 ] . V_1001 & V_980 ) ) ) {
F_29 ( L_498 ,
V_342 , V_990 , V_996 [ V_993 ] . V_1001 & V_980 ) ;
V_169 = - V_156 ;
goto exit;
}
} else {
V_820 . V_64 . V_66 = 0L ;
}
if ( ( V_996 [ V_993 ] . V_1001 & V_1008 ) &&
( ( F_320 ( V_996 [ V_993 ] . V_1001 ) + V_464 ) <= V_79 ) ) {
if ( V_464 )
V_820 . V_86 = V_945 ;
memcpy ( V_820 . V_78 + V_464 , V_987 , V_79 - V_464 ) ;
} else {
if ( ( V_996 [ V_993 ] . V_1001 == 0 ) &&
( V_996 [ V_993 ] . V_1002 & V_1008 ) &&
( F_320 ( V_996 [ V_993 ] . V_1002 ) <= V_79 ) ) {
if ( V_464 )
V_820 . V_86 = V_945 ;
} else {
if ( F_132 ( V_820 . V_64 . V_452 , V_987 , V_988 ) ) {
V_169 = - V_453 ;
goto exit;
}
V_820 . V_64 . V_65 = V_945 ;
}
}
F_40 ( V_868 ) ;
V_868 = NULL ;
V_992 = 0 ;
if ( F_322 ( V_996 [ V_993 ] . V_60 ) ) {
V_992 = F_320 ( V_996 [ V_993 ] . V_1001 ) ;
if ( ( V_996 [ V_993 ] . V_1001 & V_1008 ) &&
( ( V_992 + V_464 ) <= V_79 ) )
V_992 = 0 ;
} else {
V_992 = F_320 ( V_996 [ V_993 ] . V_1002 ) ;
if ( ( V_996 [ V_993 ] . V_1002 & V_1008 ) &&
( V_992 <= V_79 ) )
V_992 = 0 ;
}
if ( V_992 == 0 ) {
V_243 = ( T_1 * ) & V_820 ;
F_40 ( V_987 ) ;
V_987 = NULL ;
} else {
V_243 = V_987 ;
}
V_490 = V_994 [ V_996 [ V_993 ] . V_60 - V_1009 ] ;
V_169 = V_490 ( V_139 , NULL , & V_820 , V_243 ) ;
if ( ( V_996 [ V_993 ] . V_1002 & V_981 ) &&
( V_996 [ V_993 ] . V_1002 & V_980 ) ) {
int V_264 ;
int V_1010 = 0 ;
T_1 V_1004 [ 20 ] = { 0 } ;
if ( ( V_996 [ V_993 ] . V_1002 & V_1008 ) &&
( F_320 ( V_996 [ V_993 ] . V_1002 ) <= V_79 ) )
V_1010 = V_996 [ V_993 ] . V_1002 & V_980 ;
else
V_1010 = V_820 . V_64 . V_66 ;
V_985 = F_43 ( 4096 ) ;
if ( NULL == V_985 ) {
V_169 = - V_223 ;
goto exit;
}
switch ( V_996 [ V_993 ] . V_1002 & V_981 ) {
case V_1005 :
for ( V_264 = 0 ; V_264 < V_1010 ; V_264 ++ ) {
sprintf ( V_1004 , L_499 , V_243 [ V_264 ] ) ;
V_363 = strlen ( V_1004 ) ;
V_986 = strlen ( V_985 ) ;
if ( ( V_986 + V_363 + 1 ) > 4096 ) {
V_169 = - V_388 ;
goto exit;
}
memcpy ( V_985 + V_986 , V_1004 , V_363 ) ;
}
break;
case V_1006 :
for ( V_264 = 0 ; V_264 < V_1010 ; V_264 ++ ) {
sprintf ( V_1004 , L_499 , ( ( V_1011 * ) V_243 ) [ V_264 ] ) ;
V_363 = strlen ( V_1004 ) ;
V_986 = strlen ( V_985 ) ;
if ( ( V_986 + V_363 + 1 ) > 4096 ) {
V_169 = - V_388 ;
goto exit;
}
memcpy ( V_985 + V_986 , V_1004 , V_363 ) ;
}
break;
case V_1007 :
memcpy ( V_985 , V_243 , V_1010 ) ;
break;
default:
F_29 ( L_497 , V_342 ) ;
V_169 = - 1 ;
goto exit;
}
V_986 = strlen ( V_985 ) + 1 ;
V_983 -> V_64 . V_66 = V_986 ;
if ( F_132 ( V_983 -> V_64 . V_452 , V_985 , V_986 ) ) {
V_169 = - V_453 ;
goto exit;
}
} else {
V_983 -> V_64 . V_66 = 0 ;
}
exit:
F_40 ( V_868 ) ;
F_40 ( V_987 ) ;
F_40 ( V_985 ) ;
return V_169 ;
}
int F_323 ( struct V_138 * V_139 , struct V_1012 * V_1013 , int V_60 )
{
struct V_1014 * V_1015 = (struct V_1014 * ) V_1013 ;
int V_140 = 0 ;
switch ( V_60 ) {
case V_1016 :
V_140 = F_208 ( V_139 , & V_1015 -> V_61 . V_64 ) ;
break;
#ifdef F_202
case V_1017 :
V_140 = F_241 ( V_139 , & V_1015 -> V_61 . V_64 ) ;
break;
#endif
case V_1000 :
V_140 = F_321 ( V_139 , & V_1015 -> V_61 ) ;
break;
case ( V_1000 + 1 ) :
V_140 = F_324 ( V_139 , V_1013 , V_60 ) ;
break;
default:
V_140 = - V_189 ;
break;
}
return V_140 ;
}
