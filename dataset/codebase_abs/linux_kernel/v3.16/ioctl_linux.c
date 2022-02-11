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
V_158 -> V_61 . V_167 . V_168 = 0 ;
V_158 -> V_61 . V_167 . V_169 [ V_170 - 1 ] = '\0' ;
if ( V_159 < ( T_4 ) ( ( T_1 * ) V_158 -> V_61 . V_167 . V_171 - ( T_1 * ) V_158 ) + V_158 -> V_61 . V_167 . V_172 ) {
V_140 = - V_156 ;
goto exit;
}
if ( V_158 -> V_173 [ 0 ] == 0xff && V_158 -> V_173 [ 1 ] == 0xff &&
V_158 -> V_173 [ 2 ] == 0xff && V_158 -> V_173 [ 3 ] == 0xff &&
V_158 -> V_173 [ 4 ] == 0xff && V_158 -> V_173 [ 5 ] == 0xff ) {
if ( V_158 -> V_61 . V_167 . V_174 >= V_175 ) {
V_140 = - V_156 ;
goto exit;
}
} else {
V_140 = - V_156 ;
goto exit;
}
if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_25 ) == 0 ) {
F_23 ( V_176 , V_177 , ( L_26 ) ) ;
F_29 ( L_26 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_178 = V_179 ;
V_8 -> V_143 . V_180 = V_179 ;
V_160 = V_158 -> V_61 . V_167 . V_174 ;
V_161 = V_158 -> V_61 . V_167 . V_172 ;
F_23 ( V_176 , V_113 , ( L_27 , V_160 ) ) ;
F_29 ( L_27 , V_160 ) ;
if ( V_160 > V_175 )
return - V_156 ;
F_23 ( V_176 , V_113 , ( L_28 , V_160 ) ) ;
if ( V_161 > 0 ) {
V_161 = V_161 <= 5 ? 5 : 13 ;
V_162 = V_161 + F_31 ( struct V_163 , V_181 ) ;
V_164 = (struct V_163 * ) F_32 ( V_162 ) ;
if ( V_164 == NULL ) {
F_23 ( V_176 , V_177 , ( L_29 ) ) ;
goto exit;
}
F_4 ( V_164 , 0 , V_162 ) ;
V_164 -> V_182 = V_161 ;
V_164 -> V_183 = V_162 ;
if ( V_161 == 13 ) {
V_8 -> V_143 . V_178 = V_184 ;
V_8 -> V_143 . V_180 = V_184 ;
}
} else {
V_140 = - V_156 ;
goto exit;
}
V_164 -> V_185 = V_160 ;
V_164 -> V_185 |= 0x80000000 ;
memcpy ( V_164 -> V_181 , V_158 -> V_61 . V_167 . V_171 , V_164 -> V_182 ) ;
if ( V_158 -> V_61 . V_167 . V_186 ) {
F_29 ( L_30 ) ;
if ( F_33 ( V_8 , V_164 ) == ( T_1 ) V_187 )
V_140 = - V_188 ;
} else {
F_29 ( L_31 ) ;
if ( V_160 >= V_175 ) {
V_140 = - V_188 ;
goto exit;
}
memcpy ( & ( V_166 -> V_189 [ V_160 ] . V_190 [ 0 ] ) , V_164 -> V_181 , V_164 -> V_182 ) ;
V_166 -> V_191 [ V_160 ] = V_164 -> V_182 ;
F_34 ( V_8 , V_166 , V_160 , 0 ) ;
}
goto exit;
}
if ( V_8 -> V_143 . V_148 == V_192 ) {
struct V_193 * V_194 , * V_195 ;
struct V_196 * V_197 = & V_8 -> V_198 ;
if ( F_25 ( V_14 , V_199 | V_200 ) ) {
V_194 = F_35 ( V_197 , F_36 ( V_14 ) ) ;
if ( V_194 == NULL ) {
;
} else {
if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_32 ) != 0 )
V_194 -> V_201 = false ;
if ( ( V_8 -> V_143 . V_144 == V_202 ) ||
( V_8 -> V_143 . V_144 == V_203 ) )
V_194 -> V_204 = V_8 -> V_143 . V_178 ;
if ( V_158 -> V_61 . V_167 . V_186 == 1 ) {
memcpy ( V_194 -> V_205 . V_190 , V_158 -> V_61 . V_167 . V_171 , ( V_158 -> V_61 . V_167 . V_172 > 16 ? 16 : V_158 -> V_61 . V_167 . V_172 ) ) ;
if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_33 ) == 0 ) {
memcpy ( V_194 -> V_206 . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 16 ] ) , 8 ) ;
memcpy ( V_194 -> V_207 . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 24 ] ) , 8 ) ;
V_8 -> V_143 . V_208 = false ;
}
F_29 ( L_34 ) ;
F_37 ( V_8 , ( unsigned char * ) V_194 , true ) ;
} else {
memcpy ( V_8 -> V_143 . V_209 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 , V_158 -> V_61 . V_167 . V_171 , ( V_158 -> V_61 . V_167 . V_172 > 16 ? 16 : V_158 -> V_61 . V_167 . V_172 ) ) ;
memcpy ( V_8 -> V_143 . V_210 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 16 ] ) , 8 ) ;
memcpy ( V_8 -> V_143 . V_211 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 24 ] ) , 8 ) ;
V_8 -> V_143 . V_212 = true ;
F_29 ( L_35 ) ;
V_8 -> V_143 . V_213 = V_158 -> V_61 . V_167 . V_174 ;
F_34 ( V_8 , & V_8 -> V_143 , V_158 -> V_61 . V_167 . V_174 , 1 ) ;
#ifdef F_10
if ( F_11 ( V_49 , V_214 ) )
F_38 ( V_49 , V_215 ) ;
#endif
}
}
V_195 = F_39 ( V_8 ) ;
if ( V_195 == NULL ) {
;
} else {
if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_32 ) != 0 )
V_195 -> V_201 = false ;
if ( ( V_8 -> V_143 . V_144 == V_202 ) ||
( V_8 -> V_143 . V_144 == V_203 ) )
V_195 -> V_204 = V_8 -> V_143 . V_178 ;
}
}
}
exit:
F_40 ( V_164 ) ;
return V_140 ;
}
static int F_41 ( struct V_7 * V_8 , char * V_216 , unsigned short V_217 )
{
T_1 * V_106 = NULL ;
int V_218 = 0 , V_219 = 0 ;
int V_140 = 0 ;
#ifdef F_10
struct V_48 * V_49 = & V_8 -> V_50 ;
#endif
if ( ( V_217 > V_107 ) || ( V_216 == NULL ) ) {
F_42 ( & V_8 -> V_15 , V_220 ) ;
if ( V_216 == NULL )
return V_140 ;
else
return - V_156 ;
}
if ( V_217 ) {
V_106 = F_43 ( V_217 ) ;
if ( V_106 == NULL ) {
V_140 = - V_221 ;
goto exit;
}
memcpy ( V_106 , V_216 , V_217 ) ;
{
int V_4 ;
F_29 ( L_36 , V_217 ) ;
for ( V_4 = 0 ; V_4 < V_217 ; V_4 += 8 )
F_29 ( L_37 , V_106 [ V_4 ] , V_106 [ V_4 + 1 ] , V_106 [ V_4 + 2 ] , V_106 [ V_4 + 3 ] , V_106 [ V_4 + 4 ] , V_106 [ V_4 + 5 ] , V_106 [ V_4 + 6 ] , V_106 [ V_4 + 7 ] ) ;
}
if ( V_217 < V_222 ) {
F_23 ( V_176 , V_177 , ( L_38 , V_217 ) ) ;
V_140 = - 1 ;
goto exit;
}
if ( F_44 ( V_106 , V_217 , & V_218 , & V_219 , NULL ) == V_223 ) {
V_8 -> V_143 . V_148 = V_192 ;
V_8 -> V_143 . V_146 = V_152 ;
memcpy ( V_8 -> V_143 . V_224 , & V_106 [ 0 ] , V_217 ) ;
}
if ( F_45 ( V_106 , V_217 , & V_218 , & V_219 , NULL ) == V_223 ) {
V_8 -> V_143 . V_148 = V_192 ;
V_8 -> V_143 . V_146 = V_225 ;
memcpy ( V_8 -> V_143 . V_224 , & V_106 [ 0 ] , V_217 ) ;
}
switch ( V_218 ) {
case V_226 :
V_8 -> V_143 . V_180 = V_227 ;
V_8 -> V_143 . V_144 = V_228 ;
break;
case V_229 :
V_8 -> V_143 . V_180 = V_179 ;
V_8 -> V_143 . V_144 = V_145 ;
break;
case V_230 :
V_8 -> V_143 . V_180 = V_231 ;
V_8 -> V_143 . V_144 = V_202 ;
break;
case V_232 :
V_8 -> V_143 . V_180 = V_233 ;
V_8 -> V_143 . V_144 = V_203 ;
break;
case V_234 :
V_8 -> V_143 . V_180 = V_184 ;
V_8 -> V_143 . V_144 = V_145 ;
break;
}
switch ( V_219 ) {
case V_226 :
V_8 -> V_143 . V_178 = V_227 ;
V_8 -> V_143 . V_144 = V_228 ;
break;
case V_229 :
V_8 -> V_143 . V_178 = V_179 ;
V_8 -> V_143 . V_144 = V_145 ;
break;
case V_230 :
V_8 -> V_143 . V_178 = V_231 ;
V_8 -> V_143 . V_144 = V_202 ;
break;
case V_232 :
V_8 -> V_143 . V_178 = V_233 ;
V_8 -> V_143 . V_144 = V_203 ;
break;
case V_234 :
V_8 -> V_143 . V_178 = V_184 ;
V_8 -> V_143 . V_144 = V_145 ;
break;
}
F_42 ( & V_8 -> V_15 , V_220 ) ;
{
T_2 V_116 = 0 ;
T_1 V_235 , V_236 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_116 < V_217 ) {
V_235 = V_106 [ V_116 ] ;
if ( ( V_235 == V_237 ) && ( ! memcmp ( & V_106 [ V_116 + 2 ] , V_236 , 4 ) ) ) {
F_29 ( L_39 ) ;
V_8 -> V_143 . V_238 = ( ( V_106 [ V_116 + 1 ] + 2 ) < ( V_107 << 2 ) ) ? ( V_106 [ V_116 + 1 ] + 2 ) : ( V_107 << 2 ) ;
memcpy ( V_8 -> V_143 . V_239 , & V_106 [ V_116 ] , V_8 -> V_143 . V_238 ) ;
F_46 ( & V_8 -> V_15 , V_220 ) ;
#ifdef F_10
if ( F_11 ( V_49 , V_240 ) )
F_38 ( V_49 , V_214 ) ;
#endif
V_116 += V_106 [ V_116 + 1 ] + 2 ;
break;
} else {
V_116 += V_106 [ V_116 + 1 ] + 2 ;
}
}
}
}
F_23 ( V_176 , V_113 ,
( L_40 ,
V_219 , V_8 -> V_143 . V_144 , V_8 -> V_143 . V_146 ) ) ;
exit:
F_40 ( V_106 ) ;
return V_140 ;
}
static int F_47 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_36 = 0 ;
char * V_39 ;
T_1 V_42 = false ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_242 * V_243 = & V_14 -> V_20 . V_21 ;
T_6 * V_244 = NULL ;
F_23 ( V_112 , V_113 , ( L_41 , V_27 -> V_60 ) ) ;
if ( F_25 ( V_14 , V_128 | V_245 ) == true ) {
V_39 = F_16 ( & V_243 -> V_58 [ 12 ] , V_68 , & V_36 , V_243 -> V_59 - 12 ) ;
if ( V_39 && V_36 > 0 )
V_42 = true ;
V_244 = & V_243 -> V_77 ;
if ( F_17 ( ( T_1 * ) V_244 ) == true ) {
if ( V_42 )
snprintf ( V_10 -> V_78 , V_79 , L_3 ) ;
else
snprintf ( V_10 -> V_78 , V_79 , L_4 ) ;
} else if ( ( F_18 ( ( T_1 * ) V_244 ) ) == true ) {
if ( V_42 )
snprintf ( V_10 -> V_78 , V_79 , L_5 ) ;
else
snprintf ( V_10 -> V_78 , V_79 , L_6 ) ;
} else {
if ( V_243 -> V_80 . V_81 > 14 ) {
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
return 0 ;
}
static int F_48 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
F_23 ( V_112 , V_246 , ( L_43 ) ) ;
return 0 ;
}
static int F_49 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_242 * V_243 = & V_14 -> V_20 . V_21 ;
if ( F_25 ( V_14 , V_128 ) ) {
V_10 -> V_91 . V_92 = F_21 ( V_243 -> V_80 . V_81 ) * 100000 ;
V_10 -> V_91 . V_93 = 1 ;
V_10 -> V_91 . V_4 = V_243 -> V_80 . V_81 ;
} else {
V_10 -> V_91 . V_92 = F_21 ( V_8 -> V_247 . V_248 ) * 100000 ;
V_10 -> V_91 . V_93 = 1 ;
V_10 -> V_91 . V_4 = V_8 -> V_247 . V_248 ;
}
return 0 ;
}
static int F_50 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
enum V_249 V_250 ;
int V_140 = 0 ;
if ( V_187 == F_51 ( V_8 ) ) {
V_140 = - V_251 ;
goto exit;
}
if ( ! V_8 -> V_252 ) {
V_140 = - V_251 ;
goto exit;
}
switch ( V_10 -> V_86 ) {
case V_253 :
V_250 = V_254 ;
F_29 ( L_44 ) ;
break;
case V_88 :
V_250 = V_255 ;
F_29 ( L_45 ) ;
break;
case V_87 :
V_250 = V_256 ;
F_29 ( L_46 ) ;
break;
case V_257 :
V_250 = V_258 ;
F_29 ( L_47 ) ;
break;
default:
V_140 = - V_156 ;
F_23 ( V_176 , V_177 , ( L_48 , V_259 [ V_10 -> V_86 ] ) ) ;
goto exit;
}
if ( F_52 ( V_8 , V_250 ) == false ) {
V_140 = - V_251 ;
goto exit;
}
F_53 ( V_8 , V_250 ) ;
exit:
return V_140 ;
}
static int F_54 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
F_23 ( V_112 , V_113 , ( L_49 ) ) ;
if ( F_25 ( V_14 , V_199 ) )
V_10 -> V_86 = V_257 ;
else if ( ( F_25 ( V_14 , V_245 ) ) ||
( F_25 ( V_14 , V_260 ) ) )
V_10 -> V_86 = V_88 ;
else if ( F_25 ( V_14 , V_261 ) )
V_10 -> V_86 = V_87 ;
else
V_10 -> V_86 = V_253 ;
return 0 ;
}
static int F_55 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_262 , V_263 = false ;
int V_140 = false ;
struct V_165 * V_166 = & V_8 -> V_143 ;
struct V_264 * V_265 = (struct V_264 * ) V_241 ;
T_1 V_266 [ V_23 ] = { 0x00 } ;
T_1 V_267 [ V_23 ] = { 0x00 } ;
memcpy ( V_267 , V_265 -> V_268 . V_19 , V_23 ) ;
if ( V_265 -> V_60 == V_269 ) {
F_29 ( L_50 ) ;
if ( ! memcmp ( V_267 , V_266 , V_23 ) )
return V_140 ;
else
V_140 = true ;
V_263 = false ;
for ( V_262 = 0 ; V_262 < V_270 ; V_262 ++ ) {
if ( ! memcmp ( V_166 -> V_271 [ V_262 ] . V_272 , V_267 , V_23 ) ) {
F_29 ( L_51 ) ;
memcpy ( V_166 -> V_271 [ V_262 ] . V_273 , V_265 -> V_274 , V_275 ) ;
V_166 -> V_271 [ V_262 ] . V_276 = true ;
V_166 -> V_277 = V_262 + 1 ;
V_263 = true ;
break;
}
}
if ( ! V_263 ) {
F_29 ( L_52 ,
V_166 -> V_277 ) ;
memcpy ( V_166 -> V_271 [ V_166 -> V_277 ] . V_272 , V_267 , V_23 ) ;
memcpy ( V_166 -> V_271 [ V_166 -> V_277 ] . V_273 , V_265 -> V_274 , V_275 ) ;
V_166 -> V_271 [ V_166 -> V_277 ] . V_276 = true ;
V_166 -> V_277 ++ ;
if ( V_166 -> V_277 == 16 )
V_166 -> V_277 = 0 ;
}
} else if ( V_265 -> V_60 == V_278 ) {
F_29 ( L_53 ) ;
V_140 = true ;
for ( V_262 = 0 ; V_262 < V_270 ; V_262 ++ ) {
if ( ! memcmp ( V_166 -> V_271 [ V_262 ] . V_272 , V_267 , V_23 ) ) {
F_4 ( V_166 -> V_271 [ V_262 ] . V_272 , 0x00 , V_23 ) ;
V_166 -> V_271 [ V_262 ] . V_276 = false ;
break;
}
}
} else if ( V_265 -> V_60 == V_279 ) {
F_29 ( L_54 ) ;
F_4 ( & V_166 -> V_271 [ 0 ] , 0x00 , sizeof( struct V_280 ) * V_270 ) ;
V_166 -> V_277 = 0 ;
V_140 = true ;
}
return V_140 ;
}
static int F_56 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
V_10 -> V_281 . V_104 = 0 ;
V_10 -> V_281 . V_102 = 0 ;
V_10 -> V_281 . V_103 = 1 ;
return 0 ;
}
static int F_57 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_282 * V_283 = (struct V_282 * ) V_241 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_284 * V_285 = & V_8 -> V_247 ;
T_2 V_286 ;
int V_4 ;
F_23 ( V_112 , V_113 , ( L_55 , V_27 -> V_60 ) ) ;
V_10 -> V_64 . V_66 = sizeof( * V_283 ) ;
F_4 ( V_283 , 0 , sizeof( * V_283 ) ) ;
V_283 -> V_287 = 5 * 1000 * 1000 ;
V_283 -> V_288 . V_123 = 100 ;
V_283 -> V_288 . V_135 = 100 ;
V_283 -> V_288 . V_136 = 100 ;
V_283 -> V_288 . V_124 = 7 ;
V_283 -> V_289 . V_123 = 92 ;
V_283 -> V_289 . V_135 = 178 ;
V_283 -> V_289 . V_136 = 0 ;
V_283 -> V_289 . V_124 = 7 ;
V_283 -> V_290 = V_291 ;
for ( V_4 = 0 ; V_4 < V_291 && V_4 < V_292 ; V_4 ++ )
V_283 -> V_101 [ V_4 ] = V_293 [ V_4 ] ;
V_283 -> V_294 = V_295 ;
V_283 -> V_296 = V_297 ;
V_283 -> V_298 = 0 ;
V_283 -> V_299 = V_300 ;
V_283 -> V_301 = 16 ;
for ( V_4 = 0 , V_286 = 0 ; V_4 < V_302 ; V_4 ++ ) {
if ( V_285 -> V_303 [ V_4 ] . V_304 != 0 ) {
V_283 -> V_91 [ V_286 ] . V_4 = V_285 -> V_303 [ V_4 ] . V_304 ;
V_283 -> V_91 [ V_286 ] . V_92 = F_21 ( V_285 -> V_303 [ V_4 ] . V_304 ) * 100000 ;
V_283 -> V_91 [ V_286 ] . V_93 = 1 ;
V_286 ++ ;
}
if ( V_286 == V_305 )
break;
}
V_283 -> V_306 = V_286 ;
V_283 -> V_307 = V_286 ;
V_283 -> V_308 = V_309 | V_310 |
V_311 | V_312 ;
V_283 -> V_313 = V_314 | V_315 |
V_316 | V_317 |
V_318 | V_319 ;
return 0 ;
}
static int F_58 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_320 ,
char * V_241 )
{
T_5 V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_321 * V_322 = (struct V_321 * ) V_320 ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_323 * V_324 ;
T_1 * V_325 , * V_326 ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
enum V_330 V_331 ;
if ( V_187 == F_51 ( V_8 ) ) {
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_332 ) {
V_140 = - 1 ;
goto exit;
}
if ( V_322 -> V_17 != V_18 ) {
V_140 = - V_156 ;
goto exit;
}
V_331 = V_8 -> V_143 . V_146 ;
F_59 ( & V_328 -> V_333 ) ;
V_324 = F_60 ( V_328 ) ;
V_14 -> V_334 = V_324 -> V_335 ;
while ( 1 ) {
if ( ( F_61 ( V_324 , V_14 -> V_334 ) ) == true )
break;
V_29 = F_62 ( V_14 -> V_334 , struct V_28 , V_336 ) ;
V_14 -> V_334 = V_14 -> V_334 -> V_335 ;
V_325 = V_29 -> V_21 . V_22 ;
V_326 = V_322 -> V_19 ;
if ( ( ! memcmp ( V_325 , V_326 , V_23 ) ) ) {
if ( ! F_52 ( V_8 , V_29 -> V_21 . V_337 ) ) {
V_140 = - 1 ;
F_63 ( & V_328 -> V_333 ) ;
goto exit;
}
break;
}
}
F_63 ( & V_328 -> V_333 ) ;
F_64 ( V_8 , V_331 ) ;
if ( F_65 ( V_8 , V_322 -> V_19 ) == false ) {
V_140 = - 1 ;
goto exit;
}
exit:
return V_140 ;
}
static int F_66 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_242 * V_243 = & V_14 -> V_20 . V_21 ;
V_10 -> V_16 . V_17 = V_18 ;
F_4 ( V_10 -> V_16 . V_19 , 0 , V_23 ) ;
F_23 ( V_112 , V_113 , ( L_56 ) ) ;
if ( ( ( F_25 ( V_14 , V_128 ) ) == true ) ||
( ( F_25 ( V_14 , V_245 ) ) == true ) ||
( ( F_25 ( V_14 , V_261 ) ) == true ) )
memcpy ( V_10 -> V_16 . V_19 , V_243 -> V_22 , V_23 ) ;
else
F_4 ( V_10 -> V_16 . V_19 , 0 , V_23 ) ;
return 0 ;
}
static int F_67 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
T_2 V_338 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_339 * V_340 = (struct V_339 * ) V_241 ;
if ( V_340 == NULL )
return - 1 ;
F_29 ( L_57 , V_341 ) ;
V_338 = V_340 -> V_342 ;
F_29 ( L_58 , V_341 , V_340 -> V_60 , V_338 ) ;
switch ( V_340 -> V_60 ) {
case V_343 :
if ( ! F_68 ( V_8 ) )
V_140 = - 1 ;
break;
case V_344 :
if ( ! F_68 ( V_8 ) )
V_140 = - 1 ;
break;
default:
return - V_188 ;
}
return V_140 ;
}
static int F_69 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_241 )
{
T_1 V_345 = false ;
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_346 V_347 [ V_348 ] ;
#ifdef F_10
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
#endif
F_23 ( V_112 , V_113 , ( L_59 ) ) ;
if ( V_8 -> V_349 . V_350 == 1 ) {
if ( F_25 ( V_14 , V_200 ) ) {
V_140 = - 1 ;
goto exit;
}
}
if ( V_187 == F_51 ( V_8 ) ) {
V_140 = - 1 ;
goto exit;
}
if ( V_8 -> V_351 ) {
F_29 ( L_60 , V_8 -> V_351 ) ;
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_332 ) {
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_252 ) {
V_140 = - 1 ;
goto exit;
}
if ( V_14 -> V_352 . V_353 ) {
F_3 ( V_8 ) ;
goto exit;
}
if ( F_25 ( V_14 , V_354 | V_355 ) ) {
F_3 ( V_8 ) ;
goto exit;
}
#ifdef F_10
if ( V_49 -> V_356 != V_51 ) {
F_70 ( V_49 , F_71 ( V_49 ) ) ;
F_38 ( V_49 , V_357 ) ;
F_72 ( V_49 , V_358 ) ;
F_73 ( V_8 , true ) ;
}
#endif
F_4 ( V_347 , 0 , sizeof( struct V_346 ) * V_348 ) ;
if ( V_10 -> V_64 . V_66 == sizeof( struct V_359 ) ) {
struct V_359 * V_360 = (struct V_359 * ) V_241 ;
if ( V_10 -> V_64 . V_65 & V_361 ) {
int V_362 = F_74 ( ( int ) V_360 -> V_363 , V_364 ) ;
memcpy ( V_347 [ 0 ] . V_53 , V_360 -> V_365 , V_362 ) ;
V_347 [ 0 ] . V_67 = V_362 ;
F_29 ( L_61 , V_360 -> V_365 , V_360 -> V_363 ) ;
F_59 ( & V_14 -> V_333 ) ;
V_345 = F_75 ( V_8 , V_347 , 1 , NULL , 0 ) ;
F_63 ( & V_14 -> V_333 ) ;
} else if ( V_360 -> V_366 == V_367 ) {
F_29 ( L_62 ) ;
}
} else {
if ( V_10 -> V_64 . V_66 >= V_368 &&
! memcmp ( V_241 , V_369 , V_368 ) ) {
int V_362 = V_10 -> V_64 . V_66 - V_368 ;
char * V_370 = V_241 + V_368 ;
char V_371 ;
char V_372 ;
int V_373 = 0 ;
while ( V_362 >= 1 ) {
V_371 = * ( V_370 ++ ) ;
V_362 -= 1 ;
switch ( V_371 ) {
case V_374 :
if ( V_362 < 1 ) {
V_362 = 0 ;
break;
}
V_372 = * ( V_370 ++ ) ; V_362 -= 1 ;
if ( V_372 > 0 && V_372 <= V_362 ) {
V_347 [ V_373 ] . V_67 = V_372 ;
memcpy ( V_347 [ V_373 ] . V_53 , V_370 , V_347 [ V_373 ] . V_67 ) ;
V_373 ++ ;
}
V_370 += V_372 ;
V_362 -= V_372 ;
break;
case V_375 :
case V_376 :
V_370 += 1 ;
V_362 -= 1 ;
break;
case V_377 :
case V_378 :
case V_379 :
V_370 += 2 ;
V_362 -= 2 ;
break;
default:
V_362 = 0 ;
}
}
V_345 = F_76 ( V_8 , V_347 , V_348 ) ;
} else {
V_345 = F_76 ( V_8 , NULL , 0 ) ;
}
}
if ( ! V_345 )
V_140 = - 1 ;
exit:
return V_140 ;
}
static int F_77 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_241 )
{
struct V_323 * V_380 , * V_324 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
char * V_381 = V_241 ;
char * V_31 = V_381 + V_10 -> V_64 . V_66 ;
T_4 V_140 = 0 ;
T_4 V_116 = 0 ;
T_4 V_382 ;
int V_383 ;
#ifdef F_10
struct V_48 * V_49 = & V_8 -> V_50 ;
#endif
F_23 ( V_112 , V_113 , ( L_63 ) ) ;
F_23 ( V_176 , V_113 , ( L_64 ) ) ;
if ( V_8 -> V_384 . V_385 && V_8 -> V_351 ) {
V_140 = - V_156 ;
goto exit;
}
#ifdef F_10
if ( ! F_11 ( V_49 , V_51 ) ) {
V_382 = 200 ;
} else {
V_382 = 100 ;
}
#else
{
V_382 = 100 ;
}
#endif
V_383 = V_354 | V_355 ;
while ( F_25 ( V_14 , V_383 ) ) {
F_78 ( 30 ) ;
V_116 ++ ;
if ( V_116 > V_382 )
break;
}
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) )
break;
if ( ( V_31 - V_381 ) < V_386 ) {
V_140 = - V_387 ;
break;
}
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
if ( F_79 ( V_8 -> V_247 . V_303 , V_29 -> V_21 . V_80 . V_81 ) >= 0 )
V_381 = F_9 ( V_8 , V_5 , V_29 , V_381 , V_31 ) ;
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
V_10 -> V_64 . V_66 = V_381 - V_241 ;
V_10 -> V_64 . V_65 = 0 ;
exit:
return V_140 ;
}
static int F_80 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_327 * V_328 = & V_14 -> V_329 ;
struct V_323 * V_324 ;
struct V_28 * V_29 = NULL ;
enum V_330 V_331 ;
struct V_346 V_388 ;
T_1 * V_389 , * V_390 ;
T_5 V_140 = 0 , V_362 ;
F_23 ( V_176 , V_113 ,
( L_65 , F_81 ( V_14 ) ) ) ;
if ( V_187 == F_51 ( V_8 ) ) {
V_140 = - 1 ;
goto exit;
}
if ( ! V_8 -> V_332 ) {
V_140 = - 1 ;
goto exit;
}
if ( V_10 -> V_365 . V_66 > V_364 ) {
V_140 = - V_387 ;
goto exit;
}
if ( F_25 ( V_14 , V_261 ) ) {
V_140 = - 1 ;
goto exit;
}
V_331 = V_8 -> V_143 . V_146 ;
F_29 ( L_66 , V_341 ) ;
if ( V_10 -> V_365 . V_65 && V_10 -> V_365 . V_66 ) {
V_362 = ( V_10 -> V_365 . V_66 < V_364 ) ? V_10 -> V_365 . V_66 : V_364 ;
if ( V_10 -> V_365 . V_66 != 33 )
F_29 ( L_67 , V_241 , V_10 -> V_365 . V_66 ) ;
F_4 ( & V_388 , 0 , sizeof( struct V_346 ) ) ;
V_388 . V_67 = V_362 ;
memcpy ( V_388 . V_53 , V_241 , V_362 ) ;
V_390 = V_388 . V_53 ;
F_23 ( V_176 , V_113 , ( L_68 , V_390 ) ) ;
F_59 ( & V_328 -> V_333 ) ;
V_324 = F_60 ( V_328 ) ;
V_14 -> V_334 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_14 -> V_334 ) == true ) {
F_23 ( V_176 , V_391 ,
( L_69 ) ) ;
break;
}
V_29 = F_62 ( V_14 -> V_334 , struct V_28 , V_336 ) ;
V_14 -> V_334 = V_14 -> V_334 -> V_335 ;
V_389 = V_29 -> V_21 . V_53 . V_53 ;
F_23 ( V_176 , V_113 ,
( L_70 ,
V_29 -> V_21 . V_53 . V_53 ) ) ;
if ( ( ! memcmp ( V_389 , V_390 , V_388 . V_67 ) ) &&
( V_29 -> V_21 . V_53 . V_67 == V_388 . V_67 ) ) {
F_23 ( V_176 , V_113 ,
( L_71 ) ) ;
if ( F_25 ( V_14 , V_260 ) == true ) {
if ( V_29 -> V_21 . V_337 != V_14 -> V_20 . V_21 . V_337 )
continue;
}
if ( ! F_52 ( V_8 , V_29 -> V_21 . V_337 ) ) {
V_140 = - 1 ;
F_63 ( & V_328 -> V_333 ) ;
goto exit;
}
break;
}
}
F_63 ( & V_328 -> V_333 ) ;
F_23 ( V_176 , V_113 ,
( L_72 , V_331 ) ) ;
F_64 ( V_8 , V_331 ) ;
if ( F_82 ( V_8 , & V_388 ) == false ) {
V_140 = - 1 ;
goto exit;
}
}
exit:
F_29 ( L_73 , V_341 , V_140 ) ;
return V_140 ;
}
static int F_83 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_241 )
{
T_4 V_362 , V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_242 * V_243 = & V_14 -> V_20 . V_21 ;
F_23 ( V_112 , V_113 , ( L_74 ) ) ;
if ( ( F_25 ( V_14 , V_128 ) ) ||
( F_25 ( V_14 , V_245 ) ) ) {
V_362 = V_243 -> V_53 . V_67 ;
V_10 -> V_365 . V_66 = V_362 ;
memcpy ( V_241 , V_243 -> V_53 . V_53 , V_362 ) ;
V_10 -> V_365 . V_65 = 1 ;
} else {
V_140 = - 1 ;
goto exit;
}
exit:
return V_140 ;
}
static int F_84 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_241 )
{
int V_4 , V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_392 [ V_393 ] ;
T_4 V_394 = V_10 -> V_101 . V_104 ;
T_4 V_102 = V_10 -> V_101 . V_102 ;
T_4 V_395 = 0 ;
T_1 V_396 [ V_393 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
F_23 ( V_112 , V_113 , ( L_75 ) ) ;
F_23 ( V_176 , V_113 , ( L_76 , V_394 , V_102 ) ) ;
if ( V_394 == - 1 ) {
V_395 = 11 ;
goto V_397;
}
V_394 = V_394 / 100000 ;
switch ( V_394 ) {
case 10 :
V_395 = 0 ;
break;
case 20 :
V_395 = 1 ;
break;
case 55 :
V_395 = 2 ;
break;
case 60 :
V_395 = 3 ;
break;
case 90 :
V_395 = 4 ;
break;
case 110 :
V_395 = 5 ;
break;
case 120 :
V_395 = 6 ;
break;
case 180 :
V_395 = 7 ;
break;
case 240 :
V_395 = 8 ;
break;
case 360 :
V_395 = 9 ;
break;
case 480 :
V_395 = 10 ;
break;
case 540 :
V_395 = 11 ;
break;
default:
V_395 = 11 ;
break;
}
V_397:
for ( V_4 = 0 ; V_4 < V_393 ; V_4 ++ ) {
if ( V_395 == V_396 [ V_4 ] ) {
V_392 [ V_4 ] = V_396 [ V_4 ] ;
if ( V_102 == 0 )
break;
} else {
V_392 [ V_4 ] = 0xff ;
}
F_23 ( V_176 , V_113 , ( L_77 , V_392 [ V_4 ] ) ) ;
}
if ( F_85 ( V_8 , V_392 ) != V_223 ) {
F_23 ( V_176 , V_177 , ( L_78 ) ) ;
V_140 = - 1 ;
}
return V_140 ;
}
static int F_86 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
T_2 V_40 = 0 ;
V_40 = F_87 ( (struct V_7 * ) F_28 ( V_139 ) ) ;
if ( V_40 == 0 )
return - V_251 ;
V_10 -> V_101 . V_102 = 0 ;
V_10 -> V_101 . V_104 = V_40 * 100000 ;
return 0 ;
}
static int F_88 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
if ( V_10 -> V_398 . V_103 ) {
V_8 -> V_349 . V_399 = 2347 ;
} else {
if ( V_10 -> V_398 . V_104 < 0 ||
V_10 -> V_398 . V_104 > 2347 )
return - V_156 ;
V_8 -> V_349 . V_399 = V_10 -> V_398 . V_104 ;
}
F_29 ( L_79 , V_341 , V_8 -> V_349 . V_399 ) ;
return 0 ;
}
static int F_89 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_79 , V_341 , V_8 -> V_349 . V_399 ) ;
V_10 -> V_398 . V_104 = V_8 -> V_349 . V_399 ;
V_10 -> V_398 . V_102 = 0 ;
return 0 ;
}
static int F_90 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
if ( V_10 -> V_400 . V_103 ) {
V_8 -> V_401 . V_402 = V_297 ;
} else {
if ( V_10 -> V_400 . V_104 < V_295 ||
V_10 -> V_400 . V_104 > V_297 )
return - V_156 ;
V_8 -> V_401 . V_402 = V_10 -> V_400 . V_104 & ~ 0x1 ;
}
F_29 ( L_80 , V_341 , V_8 -> V_401 . V_402 ) ;
return 0 ;
}
static int F_91 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_80 , V_341 , V_8 -> V_401 . V_402 ) ;
V_10 -> V_400 . V_104 = V_8 -> V_401 . V_402 ;
V_10 -> V_400 . V_102 = 0 ;
return 0 ;
}
static int F_92 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
V_10 -> V_403 . V_104 = 7 ;
V_10 -> V_403 . V_102 = 0 ;
V_10 -> V_403 . V_103 = 1 ;
return 0 ;
}
static int F_93 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_404 )
{
T_4 V_171 , V_140 = 0 ;
T_4 V_405 ;
struct V_163 V_406 ;
enum V_330 V_331 ;
struct V_407 * V_408 = & ( V_10 -> V_409 ) ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_410 * V_411 = & V_8 -> V_384 ;
F_29 ( L_81 , V_408 -> V_65 ) ;
F_4 ( & V_406 , 0 , sizeof( struct V_163 ) ) ;
V_171 = V_408 -> V_65 & V_412 ;
if ( V_408 -> V_65 & V_99 ) {
F_29 ( L_82 ) ;
V_8 -> V_143 . V_144 = V_228 ;
V_8 -> V_143 . V_178 = V_227 ;
V_8 -> V_143 . V_180 = V_227 ;
V_8 -> V_143 . V_148 = V_154 ;
V_331 = V_153 ;
V_8 -> V_143 . V_146 = V_331 ;
goto exit;
}
if ( V_171 ) {
if ( V_171 > V_175 )
return - V_156 ;
V_171 -- ;
V_405 = 1 ;
} else {
V_405 = 0 ;
V_171 = V_8 -> V_143 . V_413 ;
F_29 ( L_83 , V_171 ) ;
}
if ( V_408 -> V_65 & V_414 ) {
F_29 ( L_84 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_148 = V_154 ;
V_8 -> V_143 . V_178 = V_227 ;
V_8 -> V_143 . V_180 = V_227 ;
V_331 = V_153 ;
V_8 -> V_143 . V_146 = V_331 ;
} else if ( V_408 -> V_65 & V_415 ) {
F_29 ( L_85 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_148 = V_151 ;
V_8 -> V_143 . V_178 = V_179 ;
V_8 -> V_143 . V_180 = V_179 ;
V_331 = V_150 ;
V_8 -> V_143 . V_146 = V_331 ;
} else {
F_29 ( L_86 , V_408 -> V_65 ) ;
V_8 -> V_143 . V_144 = V_145 ;
V_8 -> V_143 . V_148 = V_154 ;
V_8 -> V_143 . V_178 = V_227 ;
V_8 -> V_143 . V_180 = V_227 ;
V_331 = V_153 ;
V_8 -> V_143 . V_146 = V_331 ;
}
V_406 . V_185 = V_171 ;
if ( V_408 -> V_66 > 0 ) {
V_406 . V_182 = V_408 -> V_66 <= 5 ? 5 : 13 ;
V_406 . V_183 = V_406 . V_182 + F_31 ( struct V_163 , V_181 ) ;
} else {
V_406 . V_182 = 0 ;
if ( V_405 == 1 ) {
V_8 -> V_143 . V_413 = V_171 ;
F_29 ( L_87 , V_171 , V_8 -> V_143 . V_191 [ V_171 ] ) ;
switch ( V_8 -> V_143 . V_191 [ V_171 ] ) {
case 5 :
V_8 -> V_143 . V_178 = V_179 ;
break;
case 13 :
V_8 -> V_143 . V_178 = V_184 ;
break;
default:
V_8 -> V_143 . V_178 = V_227 ;
break;
}
goto exit;
}
}
V_406 . V_185 |= 0x80000000 ;
memcpy ( V_406 . V_181 , V_404 , V_406 . V_182 ) ;
if ( F_33 ( V_8 , & V_406 ) == false ) {
if ( V_416 == V_411 -> V_417 )
V_140 = - V_188 ;
goto exit;
}
exit:
return V_140 ;
}
static int F_94 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_404 )
{
T_5 V_171 , V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_407 * V_408 = & ( V_10 -> V_409 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
if ( F_25 ( V_14 , V_128 ) != true ) {
if ( ! F_25 ( V_14 , V_245 ) ) {
V_408 -> V_66 = 0 ;
V_408 -> V_65 |= V_99 ;
return 0 ;
}
}
V_171 = V_408 -> V_65 & V_412 ;
if ( V_171 ) {
if ( V_171 > V_175 )
return - V_156 ;
V_171 -- ;
} else {
V_171 = V_8 -> V_143 . V_413 ;
}
V_408 -> V_65 = V_171 + 1 ;
switch ( V_8 -> V_143 . V_144 ) {
case V_418 :
case V_228 :
V_408 -> V_66 = 0 ;
V_408 -> V_65 |= V_99 ;
break;
case V_145 :
V_408 -> V_66 = V_8 -> V_143 . V_191 [ V_171 ] ;
if ( V_408 -> V_66 ) {
memcpy ( V_404 , V_8 -> V_143 . V_189 [ V_171 ] . V_190 , V_8 -> V_143 . V_191 [ V_171 ] ) ;
V_408 -> V_65 |= V_97 ;
if ( V_8 -> V_143 . V_146 == V_153 )
V_408 -> V_65 |= V_414 ;
else if ( V_8 -> V_143 . V_146 == V_150 )
V_408 -> V_65 |= V_415 ;
} else {
V_408 -> V_66 = 0 ;
V_408 -> V_65 |= V_99 ;
}
break;
case V_202 :
case V_203 :
V_408 -> V_66 = 16 ;
V_408 -> V_65 |= ( V_97 | V_414 | V_98 ) ;
break;
default:
V_408 -> V_66 = 0 ;
V_408 -> V_65 |= V_99 ;
break;
}
return V_140 ;
}
static int F_95 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
V_10 -> V_419 . V_104 = 0 ;
V_10 -> V_419 . V_102 = 0 ;
V_10 -> V_419 . V_103 = 1 ;
return 0 ;
}
static int F_96 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_140 = F_41 ( V_8 , V_241 , V_10 -> V_64 . V_66 ) ;
return V_140 ;
}
static int F_97 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_420 * V_158 = (struct V_420 * ) & ( V_10 -> V_158 ) ;
int V_140 = 0 ;
switch ( V_158 -> V_65 & V_421 ) {
case V_422 :
break;
case V_423 :
break;
case V_424 :
break;
case V_425 :
break;
case V_426 :
if ( V_158 -> V_104 ) {
V_8 -> V_143 . V_427 = true ;
} else {
V_8 -> V_143 . V_427 = false ;
}
break;
case V_428 :
if ( V_8 -> V_143 . V_144 == V_145 )
break;
if ( V_158 -> V_104 ) {
V_8 -> V_143 . V_144 = V_228 ;
V_8 -> V_143 . V_178 = V_227 ;
V_8 -> V_143 . V_180 = V_227 ;
V_8 -> V_143 . V_148 = V_154 ;
V_8 -> V_143 . V_146 = V_153 ;
}
break;
case V_429 :
if ( F_25 ( & V_8 -> V_15 , V_128 ) ) {
F_98 ( V_8 ) ;
F_99 ( V_8 , 500 , false ) ;
F_29 ( L_88 , V_341 ) ;
F_100 ( V_8 ) ;
F_101 ( V_8 , 1 ) ;
}
V_140 = F_27 ( V_139 , ( T_4 ) V_158 -> V_104 ) ;
break;
case V_430 :
break;
case V_431 :
break;
case V_432 :
break;
default:
return - V_188 ;
}
return V_140 ;
}
static int F_102 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
char * V_433 ;
T_4 V_159 ;
struct V_157 * V_158 = NULL ;
struct V_407 * V_434 = & V_10 -> V_409 ;
struct V_435 * V_436 = (struct V_435 * ) V_241 ;
int V_140 = 0 ;
V_159 = sizeof( struct V_157 ) + V_436 -> V_172 ;
V_158 = (struct V_157 * ) F_32 ( V_159 ) ;
if ( V_158 == NULL )
return - 1 ;
F_4 ( V_158 , 0 , V_159 ) ;
V_158 -> V_60 = V_437 ;
F_4 ( V_158 -> V_173 , 0xff , V_23 ) ;
switch ( V_436 -> V_169 ) {
case V_438 :
V_433 = L_32 ;
break;
case V_439 :
V_433 = L_25 ;
break;
case V_440 :
V_433 = L_33 ;
break;
case V_441 :
V_433 = L_89 ;
break;
default:
V_140 = - 1 ;
goto exit;
}
strncpy ( ( char * ) V_158 -> V_61 . V_167 . V_169 , V_433 , V_170 ) ;
if ( V_436 -> V_442 & V_443 )
V_158 -> V_61 . V_167 . V_186 = 1 ;
if ( ( V_436 -> V_169 != V_439 ) &&
( V_436 -> V_442 & V_444 ) )
V_158 -> V_61 . V_167 . V_186 = 0 ;
V_158 -> V_61 . V_167 . V_174 = ( V_434 -> V_65 & 0x00FF ) - 1 ;
if ( V_436 -> V_442 & V_445 )
memcpy ( V_158 -> V_61 . V_167 . V_446 , V_436 -> V_447 , 8 ) ;
if ( V_436 -> V_172 ) {
V_158 -> V_61 . V_167 . V_172 = V_436 -> V_172 ;
memcpy ( V_158 -> V_61 . V_167 . V_171 , V_436 + 1 , V_436 -> V_172 ) ;
}
V_140 = F_30 ( V_139 , V_158 , V_159 ) ;
exit:
F_40 ( V_158 ) ;
return V_140 ;
}
static int F_103 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
if ( V_241 ) {
V_10 -> V_64 . V_66 = 14 ;
V_10 -> V_64 . V_65 = 1 ;
memcpy ( V_241 , L_90 , 14 ) ;
}
return 0 ;
}
static int F_104 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 ;
struct V_407 * V_39 ;
T_2 V_362 ;
T_4 V_3 ;
T_4 V_448 ;
T_4 V_449 ;
T_1 * V_450 ;
int V_451 ;
int V_140 = 0 ;
V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
V_39 = & V_10 -> V_64 ;
V_362 = V_39 -> V_66 ;
V_450 = ( T_1 * ) F_32 ( V_362 ) ;
if ( NULL == V_450 )
return - V_221 ;
if ( F_105 ( V_450 , V_39 -> V_452 , V_362 ) ) {
V_140 = - V_453 ;
goto exit;
}
V_449 = 0 ;
V_3 = 0 ;
V_451 = sscanf ( V_450 , L_91 , & V_449 , & V_3 ) ;
if ( V_451 != 2 ) {
V_140 = - V_156 ;
goto exit;
}
switch ( V_449 ) {
case 1 :
V_448 = F_106 ( V_8 , V_3 ) ;
sprintf ( V_241 , L_92 , V_448 ) ;
break;
case 2 :
V_448 = F_107 ( V_8 , V_3 ) ;
sprintf ( V_241 , L_93 , V_448 ) ;
break;
case 4 :
V_448 = F_108 ( V_8 , V_3 ) ;
sprintf ( V_241 , L_94 , V_448 ) ;
break;
default:
F_29 ( V_454 L_95 , V_341 ) ;
V_140 = - V_156 ;
goto exit;
}
F_29 ( V_454 L_96 , V_341 , V_3 , V_241 ) ;
exit:
F_40 ( V_450 ) ;
return V_140 ;
}
static int F_109 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
int V_451 ;
T_4 V_3 ;
T_4 V_448 ;
T_4 V_449 ;
V_449 = 0 ;
V_3 = 0 ;
V_448 = 0 ;
V_451 = sscanf ( V_241 , L_97 , & V_449 , & V_3 , & V_448 ) ;
if ( V_451 != 3 )
return - V_156 ;
switch ( V_449 ) {
case 1 :
F_110 ( V_8 , V_3 , ( T_1 ) V_448 ) ;
F_29 ( V_454 L_98 , V_341 , V_3 , ( T_1 ) V_448 ) ;
break;
case 2 :
F_111 ( V_8 , V_3 , ( T_2 ) V_448 ) ;
F_29 ( V_454 L_99 , V_341 , V_3 , ( T_2 ) V_448 ) ;
break;
case 4 :
F_112 ( V_8 , V_3 , V_448 ) ;
F_29 ( V_454 L_100 , V_341 , V_3 , V_448 ) ;
break;
default:
F_29 ( V_454 L_101 , V_341 ) ;
return - V_156 ;
}
return 0 ;
}
static int F_113 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_455 , V_3 , V_448 ;
V_455 = * ( T_4 * ) V_241 ;
V_3 = * ( ( T_4 * ) V_241 + 1 ) ;
V_448 = F_114 ( V_8 , V_455 , V_3 , 0xFFFFF ) ;
sprintf ( V_241 , L_102 , V_448 ) ;
return 0 ;
}
static int F_115 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_4 V_455 , V_3 , V_448 ;
V_455 = * ( T_4 * ) V_241 ;
V_3 = * ( ( T_4 * ) V_241 + 1 ) ;
V_448 = * ( ( T_4 * ) V_241 + 2 ) ;
F_116 ( V_8 , V_455 , V_3 , 0xFFFFF , V_448 ) ;
return 0 ;
}
static int F_117 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
return - 1 ;
}
static int F_118 ( struct V_138 * V_139 , struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
return - 1 ;
}
static int F_119 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
T_1 V_456 = ( T_1 ) ( * ( ( int * ) V_10 ) ) ;
if ( V_223 == F_120 ( V_8 , V_456 , 1 ) )
F_29 ( L_103 , V_341 , V_14 -> V_457 ) ;
else
return - V_251 ;
return 0 ;
}
static int F_121 ( struct V_138 * V_139 ,
struct V_26 * V_5 ,
union V_9 * V_10 , char * V_6 )
{
return 0 ;
}
static int F_122 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_106 )
{
return 0 ;
}
static int F_123 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
return 0 ;
}
static int F_124 ( struct V_138 * V_139 , struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
return 0 ;
}
static void F_125 ( struct V_7 * V_8 , T_4 V_458 , T_1 * V_459 , T_4 V_362 )
{
struct V_460 * V_461 ;
struct V_462 * V_463 ;
T_1 V_455 ;
T_1 V_464 ;
T_4 V_104 ;
F_29 ( L_57 , V_341 ) ;
switch ( V_458 ) {
case F_126 ( V_465 ) :
F_29 ( L_104 ) ;
break;
case F_126 ( V_466 ) :
V_461 = (struct V_460 * ) V_459 ;
switch ( V_461 -> V_467 ) {
case 1 :
V_461 -> V_104 = F_106 ( V_8 , V_461 -> V_464 ) ;
break;
case 2 :
V_461 -> V_104 = F_107 ( V_8 , V_461 -> V_464 ) ;
break;
case 4 :
V_461 -> V_104 = F_108 ( V_8 , V_461 -> V_464 ) ;
break;
default:
break;
}
break;
case F_126 ( V_468 ) :
V_461 = (struct V_460 * ) V_459 ;
switch ( V_461 -> V_467 ) {
case 1 :
F_110 ( V_8 , V_461 -> V_464 , ( T_1 ) V_461 -> V_104 ) ;
break;
case 2 :
F_111 ( V_8 , V_461 -> V_464 , ( T_2 ) V_461 -> V_104 ) ;
break;
case 4 :
F_112 ( V_8 , V_461 -> V_464 , ( T_4 ) V_461 -> V_104 ) ;
break;
default:
break;
}
break;
case F_126 ( V_469 ) :
V_463 = (struct V_462 * ) V_459 ;
V_455 = ( T_1 ) V_463 -> V_455 ;
V_464 = ( T_1 ) V_463 -> V_464 ;
V_104 = F_114 ( V_8 , V_455 , V_464 , 0xffffffff ) ;
V_463 -> V_104 = V_104 ;
break;
case F_126 ( V_470 ) :
V_463 = (struct V_462 * ) V_459 ;
V_455 = ( T_1 ) V_463 -> V_455 ;
V_464 = ( T_1 ) V_463 -> V_464 ;
V_104 = V_463 -> V_104 ;
F_116 ( V_8 , V_455 , V_464 , 0xffffffff , V_104 ) ;
break;
case F_126 ( V_471 ) :
F_29 ( L_105 ) ;
F_127 ( V_8 , V_472 , NULL ) ;
break;
case F_126 ( V_473 ) :
* V_459 = F_128 ( V_8 ) ;
break;
default:
break;
}
}
static int F_129 ( struct V_138 * V_139 , struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
T_4 V_474 , V_475 , V_476 ;
struct V_477 V_478 ;
struct V_479 * V_480 ;
struct V_481 * V_482 ;
T_5 V_483 = 0 ;
T_2 V_362 ;
T_1 * V_484 = NULL , V_485 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_407 * V_39 = & V_10 -> V_64 ;
if ( ( ! V_39 -> V_66 ) || ( ! V_39 -> V_452 ) ) {
V_140 = - V_156 ;
goto V_486;
}
V_484 = NULL ;
V_485 = ( T_1 ) ( V_39 -> V_65 & 0xFFFF ) ;
V_362 = V_39 -> V_66 ;
V_484 = ( T_1 * ) F_32 ( V_362 ) ;
if ( V_484 == NULL ) {
V_140 = - V_221 ;
goto V_486;
}
if ( F_105 ( V_484 , V_39 -> V_452 , V_362 ) ) {
V_140 = - V_453 ;
goto V_486;
}
V_482 = (struct V_481 * ) V_484 ;
F_23 ( V_176 , V_113 ,
( L_106 ,
V_482 -> V_487 , V_482 -> V_362 , V_362 ) ) ;
if ( V_482 -> V_487 >= F_130 ( V_488 ) ) {
F_23 ( V_176 , V_177 , ( L_107 ) ) ;
V_140 = - V_156 ;
goto V_486;
}
if ( V_8 -> V_349 . V_350 == 1 ) {
V_480 = V_488 + V_482 -> V_487 ;
if ( ( V_480 -> V_489 != 0 ) && ( V_482 -> V_362 < V_480 -> V_489 ) ) {
F_23 ( V_176 , V_177 ,
( L_108 ,
V_482 -> V_362 , V_480 -> V_489 ) ) ;
V_140 = - V_156 ;
goto V_486;
}
if ( V_480 -> V_490 ) {
V_478 . V_491 = V_8 ;
V_478 . V_492 = V_480 -> V_492 ;
V_478 . V_493 = V_482 -> V_64 ;
V_478 . V_494 = V_482 -> V_362 ;
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
F_125 ( V_8 , V_482 -> V_487 , V_482 -> V_64 , V_482 -> V_362 ) ;
}
if ( V_485 == 0x00 ) {
if ( F_131 ( V_39 -> V_452 , V_484 , V_362 ) )
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
static int F_132 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
T_4 V_116 = 0 , V_501 ;
struct V_323 * V_380 , * V_324 ;
unsigned char * V_502 ;
T_1 V_268 [ V_23 ] ;
char V_64 [ 32 ] ;
struct V_28 * V_29 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_407 * V_459 = & V_10 -> V_64 ;
F_29 ( L_110 ) ;
if ( ( V_8 -> V_351 ) || ( V_459 == NULL ) ) {
V_140 = - V_156 ;
goto exit;
}
while ( ( F_25 ( V_14 , ( V_354 | V_355 ) ) ) ) {
F_78 ( 30 ) ;
V_116 ++ ;
if ( V_116 > 100 )
break;
}
V_459 -> V_65 = 0 ;
if ( V_459 -> V_66 >= 32 ) {
if ( F_105 ( V_64 , V_459 -> V_452 , 32 ) ) {
V_140 = - V_156 ;
goto exit;
}
} else {
V_140 = - V_156 ;
goto exit;
}
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) == true )
break;
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
if ( F_2 ( V_64 , V_268 ) ) {
F_29 ( L_111 , ( T_1 * ) V_64 ) ;
F_63 ( & V_14 -> V_329 . V_333 ) ;
return - V_156 ;
}
if ( ! memcmp ( V_268 , V_29 -> V_21 . V_22 , V_23 ) ) {
F_29 ( L_112 , ( V_268 ) ) ;
V_502 = F_133 ( & V_29 -> V_21 . V_58 [ 12 ] , & V_501 , V_29 -> V_21 . V_59 - 12 ) ;
if ( V_502 && ( V_501 > 0 ) ) {
V_459 -> V_65 = 1 ;
break;
}
V_502 = F_134 ( & V_29 -> V_21 . V_58 [ 12 ] , & V_501 , V_29 -> V_21 . V_59 - 12 ) ;
if ( V_502 && ( V_501 > 0 ) ) {
V_459 -> V_65 = 2 ;
break;
}
}
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
if ( V_459 -> V_66 >= 34 ) {
if ( F_131 ( V_459 -> V_452 + 32 , ( T_1 * ) & V_459 -> V_65 , 1 ) ) {
V_140 = - V_156 ;
goto exit;
}
}
exit:
return V_140 ;
}
static int F_135 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
int * V_459 = ( int * ) V_10 ;
int V_503 ;
if ( ( V_8 -> V_351 ) || ( V_459 == NULL ) ) {
V_140 = - V_156 ;
goto exit;
}
V_503 = * V_459 ;
if ( V_503 < 3 && V_503 >= 0 ) {
V_8 -> V_504 [ V_503 ] = * ( V_459 + 1 ) ;
V_505 [ V_503 ] = * ( V_459 + 1 ) ;
F_29 ( L_113 , V_341 , V_503 , V_8 -> V_504 [ V_503 ] ) ;
} else {
F_29 ( L_114 , V_341 , V_503 ) ;
}
exit:
return V_140 ;
}
static int F_136 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_407 * V_459 = & V_10 -> V_64 ;
T_4 V_506 = 0 ;
if ( ( V_8 -> V_351 ) || ( V_459 == NULL ) ) {
V_140 = - V_156 ;
goto exit;
}
V_140 = F_105 ( ( void * ) & V_506 , V_459 -> V_452 , 4 ) ;
if ( V_140 ) {
V_140 = - V_156 ;
goto exit;
}
if ( V_506 == 0 )
V_506 = * V_241 ;
F_29 ( L_115 , V_341 , V_506 ) ;
if ( V_506 == 1 )
F_137 ( V_8 , V_507 ) ;
else if ( V_506 == 2 )
F_137 ( V_8 , V_508 ) ;
else if ( V_506 == 3 )
F_137 ( V_8 , V_509 ) ;
exit:
return V_140 ;
}
static int F_138 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
struct V_284 * V_285 = & V_8 -> V_247 ;
enum V_510 V_511 = V_512 ;
if ( * V_241 == '0' )
V_511 = V_512 ;
else if ( * V_241 == '1' )
V_511 = V_513 ;
else if ( * V_241 == '2' )
V_511 = V_514 ;
else if ( * V_241 == '3' )
V_511 = V_515 ;
if ( V_187 == F_139 ( V_8 , V_511 ) ) {
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
V_49 -> V_521 = V_285 -> V_248 ;
V_516 = V_49 -> V_521 ;
V_517 = V_285 -> V_524 ;
V_518 = V_285 -> V_525 ;
}
F_140 ( V_8 , V_516 , V_517 , V_518 ) ;
}
exit:
return V_140 ;
}
static int F_141 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_116 , V_341 , V_241 , strlen ( V_241 ) ) ;
memcpy ( V_49 -> V_526 , V_241 , strlen ( V_241 ) ) ;
V_49 -> V_527 = strlen ( V_241 ) ;
return V_140 ;
}
static int F_142 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_528 = V_49 -> V_528 ;
switch ( V_10 -> V_64 . V_66 ) {
case 1 :
V_528 = V_241 [ 0 ] - '0' ;
break;
case 2 :
V_528 = F_143 ( V_241 [ 0 ] , V_241 [ 1 ] ) ;
break;
}
if ( V_528 <= 15 )
V_49 -> V_528 = V_528 ;
else
V_140 = - 1 ;
F_29 ( L_117 , V_341 , V_528 ) ;
return V_140 ;
}
static int F_144 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_529 = V_49 -> V_520 ;
switch ( V_10 -> V_64 . V_66 ) {
case 1 :
V_529 = V_241 [ 0 ] - '0' ;
break;
case 2 :
V_529 = F_143 ( V_241 [ 0 ] , V_241 [ 1 ] ) ;
break;
}
if ( ( V_529 == 1 ) || ( V_529 == 6 ) || ( V_529 == 11 ) ) {
V_49 -> V_520 = V_529 ;
F_140 ( V_8 , V_49 -> V_520 , V_522 , V_523 ) ;
} else {
V_140 = - 1 ;
}
F_29 ( L_118 , V_341 , V_49 -> V_520 ) ;
return V_140 ;
}
static int F_145 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_530 = V_49 -> V_521 ;
switch ( V_10 -> V_64 . V_66 ) {
case 1 :
V_530 = V_241 [ 0 ] - '0' ;
break;
case 2 :
V_530 = F_143 ( V_241 [ 0 ] , V_241 [ 1 ] ) ;
break;
}
if ( V_530 > 0 )
V_49 -> V_521 = V_530 ;
else
V_140 = - 1 ;
F_29 ( L_119 , V_341 , V_49 -> V_521 ) ;
return V_140 ;
}
static int F_146 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_120 , V_341 , V_241 , V_10 -> V_64 . V_66 - 1 ) ;
if ( ! F_11 ( V_49 , V_51 ) ) {
if ( V_241 [ 0 ] == '0' ) {
F_4 ( & V_49 -> V_531 [ 0 ] , 0x00 , sizeof( struct V_532 ) * V_533 ) ;
V_49 -> V_534 = 0 ;
} else {
if ( V_49 -> V_534 >= V_533 ) {
V_140 = - 1 ;
} else {
int V_535 , V_536 ;
for ( V_535 = 0 , V_536 = 1 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_49 -> V_531 [ V_49 -> V_534 ] . V_537 [ V_535 ] = F_147 ( V_241 [ V_536 ] , V_241 [ V_536 + 1 ] ) ;
V_49 -> V_531 [ V_49 -> V_534 ] . V_538 = ( V_241 [ 18 ] - '0' ) * 10 + ( V_241 [ 19 ] - '0' ) ;
memcpy ( V_49 -> V_531 [ V_49 -> V_534 ] . V_347 , & V_241 [ 20 ] , V_49 -> V_531 [ V_49 -> V_534 ] . V_538 ) ;
V_49 -> V_534 ++ ;
}
}
}
return V_140 ;
}
static int F_148 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_121 , V_341 , V_241 , V_10 -> V_64 . V_66 - 1 ) ;
F_4 ( V_49 -> V_539 , 0x00 , V_540 ) ;
memcpy ( V_49 -> V_539 , V_241 , V_10 -> V_64 . V_66 - 1 ) ;
V_49 -> V_541 = V_10 -> V_64 . V_66 - 1 ;
return V_140 ;
}
static int F_149 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
if ( V_8 -> V_542 )
F_29 ( L_122 , V_341 , F_150 ( V_49 ) , F_71 ( V_49 ) ,
V_49 -> V_543 [ 0 ] , V_49 -> V_543 [ 1 ] , V_49 -> V_543 [ 2 ] ,
V_49 -> V_543 [ 3 ] , V_49 -> V_543 [ 4 ] , V_49 -> V_543 [ 5 ] ) ;
sprintf ( V_241 , L_123 , F_71 ( V_49 ) ) ;
V_10 -> V_64 . V_66 = strlen ( V_241 ) ;
return V_140 ;
}
static int F_151 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
sprintf ( V_241 , L_124 , V_49 -> V_544 . V_545 ) ;
V_10 -> V_64 . V_66 = strlen ( V_241 ) ;
return V_140 ;
}
static int F_152 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_122 , V_341 , F_150 ( V_49 ) , F_71 ( V_49 ) ,
V_49 -> V_543 [ 0 ] , V_49 -> V_543 [ 1 ] , V_49 -> V_543 [ 2 ] ,
V_49 -> V_543 [ 3 ] , V_49 -> V_543 [ 4 ] , V_49 -> V_543 [ 5 ] ) ;
sprintf ( V_241 , L_125 , F_150 ( V_49 ) ) ;
V_10 -> V_64 . V_66 = strlen ( V_241 ) ;
return V_140 ;
}
static int F_153 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_126 , V_341 ,
F_150 ( V_49 ) , F_71 ( V_49 ) ,
V_49 -> V_543 ) ;
sprintf ( V_241 , L_127 ,
V_49 -> V_543 ) ;
V_10 -> V_64 . V_66 = strlen ( V_241 ) ;
return V_140 ;
}
static int F_154 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_126 , V_341 ,
F_150 ( V_49 ) , F_71 ( V_49 ) ,
V_49 -> V_544 . V_546 ) ;
sprintf ( V_241 , L_128 ,
V_49 -> V_544 . V_546 ) ;
V_10 -> V_64 . V_66 = strlen ( V_241 ) ;
return V_140 ;
}
static int F_155 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_126 ,
V_341 , F_150 ( V_49 ) , F_71 ( V_49 ) ,
V_49 -> V_547 ) ;
sprintf ( V_241 , L_127 ,
V_49 -> V_547 ) ;
V_10 -> V_64 . V_66 = strlen ( V_241 ) ;
return V_140 ;
}
static int F_156 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
sprintf ( V_241 , L_129 ,
V_49 -> V_548 . V_549 [ 0 ] , V_49 -> V_548 . V_549 [ 1 ] ,
V_49 -> V_548 . V_549 [ 2 ] , V_49 -> V_548 . V_549 [ 3 ] ,
V_49 -> V_548 . V_549 [ 4 ] , V_49 -> V_548 . V_549 [ 5 ] ,
V_49 -> V_548 . V_347 ) ;
V_10 -> V_64 . V_66 = strlen ( V_241 ) ;
return V_140 ;
}
static int F_157 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_130 , V_341 , V_49 -> V_521 ) ;
sprintf ( V_241 , L_131 , V_49 -> V_521 ) ;
V_10 -> V_64 . V_66 = strlen ( V_241 ) ;
return V_140 ;
}
static int F_158 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_323 * V_380 , * V_324 ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_2 V_553 = 0 ;
T_5 V_554 = 0 ;
T_1 V_555 [ 6 + 17 ] = { 0x00 } ;
F_29 ( L_132 , V_341 , ( char * ) V_241 ) ;
if ( F_105 ( V_551 , V_10 -> V_64 . V_452 + 6 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_147 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) == true )
break;
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
T_1 * V_556 ;
T_5 V_557 = 0 ;
T_7 V_558 ;
V_556 = F_159 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_557 ) ;
if ( V_556 ) {
F_160 ( V_556 , V_557 , V_559 , ( T_1 * ) & V_558 , & V_554 ) ;
if ( V_554 ) {
V_553 = F_161 ( V_558 ) ;
sprintf ( V_555 , L_133 , V_553 ) ;
V_552 = 1 ;
}
}
break;
}
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
if ( ! V_552 )
sprintf ( V_555 , L_134 ) ;
if ( F_131 ( V_10 -> V_64 . V_452 , V_555 , 6 + 17 ) )
return - V_453 ;
return V_140 ;
}
static int F_162 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_323 * V_380 , * V_324 ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_1 * V_560 ;
T_5 V_56 = 0 , V_554 = 0 ;
T_1 V_553 [ 100 ] = { 0x00 } ;
T_1 V_561 [ 17 + 12 ] = {} ;
F_29 ( L_132 , V_341 , ( char * ) V_241 ) ;
if ( F_105 ( V_551 , V_10 -> V_64 . V_452 + 10 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_147 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) == true )
break;
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
V_560 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_560 ) {
while ( V_560 ) {
F_4 ( V_553 , 0x00 , 100 ) ;
if ( F_163 ( V_560 , V_56 , V_562 , V_553 , & V_554 ) ) {
V_552 = 1 ;
break;
} else if ( F_163 ( V_560 , V_56 , V_563 , V_553 , & V_554 ) ) {
V_552 = 1 ;
break;
}
V_560 = F_12 ( V_560 + V_56 , V_29 -> V_21 . V_59 - 12 - ( V_560 - & V_29 -> V_21 . V_58 [ 12 ] + V_56 ) , NULL , & V_56 ) ;
}
}
}
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
if ( ! V_552 )
snprintf ( V_561 , sizeof( V_561 ) , L_135 ) ;
else
snprintf ( V_561 , sizeof( V_561 ) , L_136 ,
V_553 [ 0 ] , V_553 [ 1 ] , V_553 [ 2 ] , V_553 [ 3 ] , V_553 [ 4 ] , V_553 [ 5 ] ) ;
if ( F_131 ( V_10 -> V_64 . V_452 , V_561 , sizeof( V_561 ) ) )
return - V_453 ;
return V_140 ;
}
static int F_164 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_323 * V_380 , * V_324 ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_1 V_564 [ 8 ] = { 0x00 } ;
T_5 V_565 = 0 ;
T_1 V_566 [ 17 + 9 ] = { 0x00 } ;
F_29 ( L_132 , V_341 , ( char * ) V_241 ) ;
if ( F_105 ( V_551 , V_10 -> V_64 . V_452 + 9 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_147 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) == true )
break;
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
T_1 * V_556 ;
T_5 V_557 = 0 ;
V_556 = F_159 ( & V_29 -> V_21 . V_58 [ 12 ] ,
V_29 -> V_21 . V_59 - 12 ,
NULL , & V_557 ) ;
if ( V_556 ) {
F_160 ( V_556 , V_557 , V_567 , V_564 , & V_565 ) ;
if ( V_565 ) {
T_2 type = 0 ;
T_7 V_558 ;
memcpy ( & V_558 , V_564 , 2 ) ;
type = F_161 ( V_558 ) ;
sprintf ( V_566 , L_137 , type ) ;
V_552 = 1 ;
}
}
break;
}
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
if ( ! V_552 )
sprintf ( V_566 , L_138 ) ;
if ( F_131 ( V_10 -> V_64 . V_452 , V_566 , 9 + 17 ) ) {
return - V_453 ;
}
return V_140 ;
}
static int F_165 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_323 * V_380 , * V_324 ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_1 V_568 [ V_540 ] = { 0x00 } ;
T_5 V_569 = 0 ;
T_1 V_570 [ V_540 + 5 ] = { 0x00 } ;
F_29 ( L_132 , V_341 , ( char * ) V_241 ) ;
if ( F_105 ( V_551 , V_10 -> V_64 . V_452 + 5 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_147 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) == true )
break;
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
T_1 * V_556 ;
T_5 V_557 = 0 ;
V_556 = F_159 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_557 ) ;
if ( V_556 ) {
F_160 ( V_556 , V_557 , V_571 , V_568 , & V_569 ) ;
if ( V_569 ) {
sprintf ( V_570 , L_139 , V_568 ) ;
V_552 = 1 ;
}
}
break;
}
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
if ( ! V_552 )
sprintf ( V_570 , L_140 ) ;
if ( F_131 ( V_10 -> V_64 . V_452 , V_570 , 5 + ( ( V_569 > 17 ) ? V_569 : 17 ) ) )
return - V_453 ;
return V_140 ;
}
static int F_166 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
T_1 V_551 [ 17 ] = { 0x00 } ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_323 * V_380 , * V_324 ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
T_1 V_552 = 0 ;
T_1 * V_560 ;
T_5 V_56 = 0 , V_554 = 0 ;
T_1 V_553 [ 2 ] = { 0x00 } ;
T_1 V_572 [ 17 + 8 ] = { 0x00 } ;
F_29 ( L_132 , V_341 , ( char * ) V_241 ) ;
if ( F_105 ( V_551 , V_10 -> V_64 . V_452 + 8 , 17 ) )
return - V_453 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_147 ( V_551 [ V_536 ] , V_551 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) == true )
break;
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
V_560 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_560 ) {
while ( V_560 ) {
if ( F_163 ( V_560 , V_56 , V_573 , V_553 , & V_554 ) ) {
V_552 = 1 ;
break;
}
V_560 = F_12 ( V_560 + V_56 , V_29 -> V_21 . V_59 - 12 - ( V_560 - & V_29 -> V_21 . V_58 [ 12 ] + V_56 ) , NULL , & V_56 ) ;
}
}
}
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
if ( ! V_552 ) {
sprintf ( V_572 , L_141 ) ;
} else {
if ( V_553 [ 0 ] & 0x20 )
sprintf ( V_572 , L_142 ) ;
else
sprintf ( V_572 , L_143 ) ;
}
if ( F_131 ( V_10 -> V_64 . V_452 , V_572 , 8 + 17 ) )
return - V_453 ;
return V_140 ;
}
static int F_167 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_323 * V_380 , * V_324 ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
T_5 V_574 = 0 ;
F_29 ( L_132 , V_341 , V_241 ) ;
if ( V_49 -> V_356 == V_51 ) {
F_29 ( L_144 , V_341 ) ;
return V_140 ;
}
if ( V_49 -> V_575 == V_576 )
return - 1 ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_147 ( V_241 [ V_536 ] , V_241 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) == true )
break;
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
if ( ! memcmp ( V_29 -> V_21 . V_22 , V_550 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
if ( V_574 ) {
F_4 ( & V_49 -> V_577 , 0x00 , sizeof( struct V_578 ) ) ;
F_4 ( & V_49 -> V_548 , 0x00 , sizeof( struct V_579 ) ) ;
V_49 -> V_577 . V_580 [ 0 ] = V_574 ;
memcpy ( V_49 -> V_577 . V_546 , V_29 -> V_21 . V_22 , V_23 ) ;
V_49 -> V_577 . V_581 = true ;
F_168 ( & V_49 -> V_582 ) ;
if ( F_71 ( V_49 ) != V_240 ) {
F_38 ( V_49 , V_519 ) ;
}
F_70 ( V_49 , F_71 ( V_49 ) ) ;
F_38 ( V_49 , V_583 ) ;
F_29 ( L_145 , V_341 ) ;
F_169 ( & V_49 -> V_584 , V_585 ) ;
F_169 ( & V_49 -> V_582 , V_586 ) ;
} else {
F_29 ( L_146 , V_341 ) ;
V_140 = - 1 ;
}
return V_140 ;
}
static int F_170 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
int V_535 , V_536 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_323 * V_380 , * V_324 ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
T_5 V_574 = 0 ;
T_1 V_553 [ 50 ] = { 0x00 } ;
T_1 * V_560 ;
T_5 V_56 = 0 , V_554 = 0 ;
struct V_587 * V_588 = & V_49 -> V_589 ;
F_29 ( L_132 , V_341 , V_241 ) ;
if ( V_10 -> V_64 . V_66 <= 37 ) {
F_29 ( L_147 , V_341 ) ;
return V_140 ;
}
if ( F_11 ( V_49 , V_51 ) ) {
F_29 ( L_144 , V_341 ) ;
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
V_588 -> V_594 [ V_535 ] = F_147 ( V_241 [ V_536 ] , V_241 [ V_536 + 1 ] ) ;
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) == true )
break;
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
V_560 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_560 ) {
if ( F_163 ( V_560 , V_56 , V_562 , V_553 , & V_554 ) ) {
if ( ! memcmp ( V_553 , V_588 -> V_594 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
} else if ( F_163 ( V_560 , V_56 , V_563 , V_553 , & V_554 ) ) {
if ( ! memcmp ( V_553 , V_588 -> V_594 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
}
}
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
if ( V_574 ) {
for ( V_535 = 0 , V_536 = 18 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_588 -> V_590 [ V_535 ] = F_147 ( V_241 [ V_536 ] , V_241 [ V_536 + 1 ] ) ;
V_588 -> V_538 = V_10 -> V_64 . V_66 - 36 ;
memcpy ( V_588 -> V_591 , & V_241 [ 36 ] , ( T_4 ) V_588 -> V_538 ) ;
V_588 -> V_581 = true ;
V_588 -> V_596 = V_574 ;
F_70 ( V_49 , F_71 ( V_49 ) ) ;
F_38 ( V_49 , V_597 ) ;
F_140 ( V_8 , V_574 , V_522 , V_523 ) ;
F_169 ( & V_49 -> V_584 , V_585 ) ;
F_169 ( & V_49 -> V_582 , V_598 ) ;
} else {
F_29 ( L_148 , V_341 ) ;
}
return V_140 ;
}
static int F_171 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_132 , V_341 , V_241 ) ;
if ( F_11 ( V_49 , V_51 ) ) {
F_29 ( L_144 , V_341 ) ;
return V_140 ;
} else {
if ( V_241 [ 0 ] == '0' )
V_49 -> V_599 = false ;
else if ( V_241 [ 0 ] == '1' )
V_49 -> V_599 = true ;
else
V_49 -> V_599 = false ;
}
F_172 ( L_149 , V_341 , V_49 -> V_599 ) ;
return V_140 ;
}
static int F_173 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
T_1 V_550 [ V_23 ] = { 0x00 } ;
int V_535 , V_536 ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_323 * V_380 , * V_324 ;
struct V_327 * V_328 = & ( V_14 -> V_329 ) ;
struct V_28 * V_29 = NULL ;
T_5 V_574 = 0 ;
T_1 V_553 [ 100 ] = { 0x00 } ;
T_1 * V_560 ;
T_5 V_56 = 0 , V_554 = 0 ;
F_29 ( L_132 , V_341 , V_241 ) ;
if ( V_49 -> V_356 == V_51 ) {
F_29 ( L_144 , V_341 ) ;
return V_140 ;
} else {
F_4 ( V_49 -> V_600 . V_546 , 0x00 , V_23 ) ;
F_4 ( V_49 -> V_600 . V_601 , 0x00 , V_23 ) ;
F_4 ( & V_49 -> V_600 . V_347 , 0x00 , sizeof( struct V_346 ) ) ;
V_49 -> V_600 . V_580 [ 0 ] = 0 ;
V_49 -> V_600 . V_580 [ 1 ] = 0 ;
V_49 -> V_600 . V_581 = false ;
}
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_23 ; V_535 ++ , V_536 += 3 )
V_550 [ V_535 ] = F_147 ( V_241 [ V_536 ] , V_241 [ V_536 + 1 ] ) ;
if ( ! memcmp ( & V_241 [ 18 ] , L_150 , 7 ) ) {
V_49 -> V_600 . V_602 = V_603 ;
} else if ( ! memcmp ( & V_241 [ 18 ] , L_151 , 7 ) ) {
V_49 -> V_600 . V_602 = V_604 ;
} else if ( ! memcmp ( & V_241 [ 18 ] , L_152 , 3 ) ) {
V_49 -> V_600 . V_602 = V_605 ;
} else if ( ! memcmp ( & V_241 [ 18 ] , L_153 , 5 ) ) {
V_49 -> V_600 . V_602 = V_606 ;
} else {
F_29 ( L_154 , V_341 ) ;
return V_140 ;
}
F_59 ( & ( V_14 -> V_329 . V_333 ) ) ;
V_324 = F_60 ( V_328 ) ;
V_380 = V_324 -> V_335 ;
while ( 1 ) {
if ( F_61 ( V_324 , V_380 ) == true )
break;
if ( V_574 != 0 )
break;
V_29 = F_62 ( V_380 , struct V_28 , V_336 ) ;
V_560 = F_12 ( & V_29 -> V_21 . V_58 [ 12 ] , V_29 -> V_21 . V_59 - 12 , NULL , & V_56 ) ;
if ( V_560 ) {
while ( V_560 ) {
if ( F_163 ( V_560 , V_56 , V_562 , V_553 , & V_554 ) ) {
if ( ! memcmp ( V_553 , V_550 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
} else if ( F_163 ( V_560 , V_56 , V_563 , V_553 , & V_554 ) ) {
if ( ! memcmp ( V_553 , V_550 , V_23 ) ) {
V_574 = V_29 -> V_21 . V_80 . V_81 ;
break;
}
}
V_560 = F_12 ( V_560 + V_56 , V_29 -> V_21 . V_59 - 12 - ( V_560 - & V_29 -> V_21 . V_58 [ 12 ] + V_56 ) , NULL , & V_56 ) ;
}
}
V_380 = V_380 -> V_335 ;
}
F_63 ( & V_14 -> V_329 . V_333 ) ;
if ( V_574 ) {
F_29 ( L_155 , V_341 , V_574 ) ;
memcpy ( V_49 -> V_600 . V_601 , V_29 -> V_21 . V_22 , V_23 ) ;
memcpy ( V_49 -> V_600 . V_546 , V_550 , V_23 ) ;
V_49 -> V_600 . V_580 [ 0 ] = ( T_2 ) V_574 ;
V_49 -> V_600 . V_581 = true ;
F_70 ( V_49 , F_71 ( V_49 ) ) ;
F_38 ( V_49 , V_607 ) ;
if ( F_174 ( V_49 , V_514 ) ) {
memcpy ( & V_49 -> V_600 . V_347 , & V_29 -> V_21 . V_53 , sizeof( struct V_346 ) ) ;
} else if ( F_174 ( V_49 , V_513 ) || F_174 ( V_49 , V_515 ) ) {
memcpy ( V_49 -> V_600 . V_347 . V_53 , V_49 -> V_54 , V_55 ) ;
V_49 -> V_600 . V_347 . V_67 = V_55 ;
}
F_140 ( V_8 , V_574 , V_522 , V_523 ) ;
F_169 ( & V_49 -> V_584 , V_585 ) ;
F_169 ( & V_49 -> V_582 , V_608 ) ;
} else {
F_29 ( L_148 , V_341 ) ;
}
return V_140 ;
}
static int F_175 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_48 * V_49 = & ( V_8 -> V_50 ) ;
F_29 ( L_132 , V_341 , V_241 ) ;
if ( * V_241 == '0' )
V_49 -> V_575 = V_576 ;
else if ( * V_241 == '1' )
V_49 -> V_575 = V_609 ;
else if ( * V_241 == '2' )
V_49 -> V_575 = V_610 ;
else if ( * V_241 == '3' )
V_49 -> V_575 = V_611 ;
else
V_49 -> V_575 = V_576 ;
return V_140 ;
}
static int F_176 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
#ifdef F_10
F_29 ( L_156 , V_341 , V_241 ) ;
if ( ! memcmp ( V_241 , L_157 , 7 ) ) {
F_138 ( V_139 , V_27 , V_10 , & V_241 [ 7 ] ) ;
} else if ( ! memcmp ( V_241 , L_158 , 6 ) ) {
V_10 -> V_64 . V_66 -= 6 ;
F_148 ( V_139 , V_27 , V_10 , & V_241 [ 6 ] ) ;
} else if ( ! memcmp ( V_241 , L_159 , 13 ) ) {
V_10 -> V_64 . V_66 -= 13 ;
F_146 ( V_139 , V_27 , V_10 , & V_241 [ 13 ] ) ;
} else if ( ! memcmp ( V_241 , L_160 , 10 ) ) {
V_10 -> V_64 . V_66 -= 10 ;
F_173 ( V_139 , V_27 , V_10 , & V_241 [ 10 ] ) ;
} else if ( ! memcmp ( V_241 , L_161 , 5 ) ) {
V_10 -> V_64 . V_66 -= 5 ;
F_167 ( V_139 , V_27 , V_10 , & V_241 [ 5 ] ) ;
} else if ( ! memcmp ( V_241 , L_162 , 7 ) ) {
V_10 -> V_64 . V_66 -= 8 ;
F_142 ( V_139 , V_27 , V_10 , & V_241 [ 7 ] ) ;
} else if ( ! memcmp ( V_241 , L_163 , 5 ) ) {
V_10 -> V_64 . V_66 -= 5 ;
F_141 ( V_139 , V_27 , V_10 , & V_241 [ 5 ] ) ;
} else if ( ! memcmp ( V_241 , L_164 , 12 ) ) {
V_10 -> V_64 . V_66 -= 12 ;
F_175 ( V_139 , V_27 , V_10 , & V_241 [ 12 ] ) ;
} else if ( ! memcmp ( V_241 , L_165 , 10 ) ) {
V_10 -> V_64 . V_66 -= 11 ;
F_144 ( V_139 , V_27 , V_10 , & V_241 [ 10 ] ) ;
} else if ( ! memcmp ( V_241 , L_166 , 6 ) ) {
V_10 -> V_64 . V_66 -= 7 ;
F_145 ( V_139 , V_27 , V_10 , & V_241 [ 6 ] ) ;
} else if ( ! memcmp ( V_241 , L_167 , 7 ) ) {
V_10 -> V_64 . V_66 -= 8 ;
F_170 ( V_139 , V_27 , V_10 , & V_241 [ 7 ] ) ;
} else if ( ! memcmp ( V_241 , L_168 , 11 ) ) {
V_10 -> V_64 . V_66 -= 11 ;
F_171 ( V_139 , V_27 , V_10 , & V_241 [ 11 ] ) ;
}
#endif
return V_140 ;
}
static int F_177 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
#ifdef F_10
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
if ( V_8 -> V_542 )
F_29 ( L_156 , V_341 ,
( char V_612 * ) V_10 -> V_64 . V_452 ) ;
if ( ! memcmp ( ( V_613 const char * ) V_10 -> V_64 . V_452 ,
L_169 , 6 ) ) {
F_149 ( V_139 , V_27 , V_10 , V_241 ) ;
} else if ( ! memcmp ( ( V_613 const char * ) V_10 -> V_64 . V_452 ,
L_170 , 4 ) ) {
F_152 ( V_139 , V_27 , V_10 , V_241 ) ;
} else if ( ! memcmp ( ( V_613 const char * ) V_10 -> V_64 . V_452 ,
L_171 , 8 ) ) {
F_153 ( V_139 , V_27 , V_10 , V_241 ) ;
} else if ( ! memcmp ( ( V_613 const char * ) V_10 -> V_64 . V_452 ,
L_172 , 6 ) ) {
F_151 ( V_139 , V_27 , V_10 , V_241 ) ;
} else if ( ! memcmp ( ( V_613 const char * ) V_10 -> V_64 . V_452 ,
L_173 , 9 ) ) {
F_154 ( V_139 , V_27 , V_10 , V_241 ) ;
} else if ( ! memcmp ( ( V_613 const char * ) V_10 -> V_64 . V_452 ,
L_174 , 8 ) ) {
F_156 ( V_139 , V_27 , V_10 , V_241 ) ;
} else if ( ! memcmp ( ( V_613 const char * ) V_10 -> V_64 . V_452 ,
L_175 , 13 ) ) {
F_155 ( V_139 , V_27 , V_10 , V_241 ) ;
} else if ( ! memcmp ( ( V_613 const char * ) V_10 -> V_64 . V_452 ,
L_176 , 5 ) ) {
F_157 ( V_139 , V_27 , V_10 , V_241 ) ;
}
#endif
return V_140 ;
}
static int F_178 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
#ifdef F_10
F_29 ( L_156 , V_341 ,
( char V_612 * ) V_10 -> V_64 . V_452 ) ;
if ( ! memcmp ( V_241 , L_177 , 6 ) ) {
V_10 -> V_64 . V_66 -= 6 ;
F_158 ( V_139 , V_27 , V_10 , & V_241 [ 6 ] ) ;
} else if ( ! memcmp ( V_241 , L_178 , 5 ) ) {
V_10 -> V_64 . V_66 -= 5 ;
F_165 ( V_139 , V_27 , V_10 , & V_241 [ 5 ] ) ;
} else if ( ! memcmp ( V_241 , L_179 , 9 ) ) {
V_10 -> V_64 . V_66 -= 9 ;
F_164 ( V_139 , V_27 , V_10 , & V_241 [ 9 ] ) ;
} else if ( ! memcmp ( V_241 , L_180 , 10 ) ) {
V_10 -> V_64 . V_66 -= 10 ;
F_162 ( V_139 , V_27 , V_10 , & V_241 [ 10 ] ) ;
} else if ( ! memcmp ( V_241 , L_181 , 8 ) ) {
V_10 -> V_64 . V_66 -= 8 ;
F_166 ( V_139 , V_27 , V_10 , & V_241 [ 8 ] ) ;
}
#endif
return V_140 ;
}
static int F_179 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_182 , V_341 , V_241 ) ;
if ( ! strcmp ( V_241 , L_183 ) )
V_8 -> V_614 = 1 ;
else
V_8 -> V_614 = 0 ;
if ( V_8 -> V_614 ) {
T_4 V_615 = F_108 ( V_8 , V_616 ) ;
V_615 &= ~ ( V_617 | V_618 ) ;
F_112 ( V_8 , V_616 , V_615 ) ;
F_29 ( L_184 ) ;
} else {
T_4 V_615 = F_108 ( V_8 , V_616 ) ;
V_615 |= V_617 | V_618 ;
F_112 ( V_8 , V_616 , V_615 ) ;
F_29 ( L_185 ) ;
}
return V_140 ;
}
static int F_180 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
struct V_619 * V_620 = & V_8 -> V_621 ;
char V_622 [ V_79 ] ;
if ( V_620 -> V_623 [ 0 ] == 0 ) {
char * V_624 ;
V_624 = V_8 -> V_349 . V_625 ;
strncpy ( V_620 -> V_623 , V_624 , V_79 ) ;
V_620 -> V_623 [ V_79 - 1 ] = 0 ;
}
if ( V_10 -> V_64 . V_66 > V_79 )
return - V_453 ;
if ( F_105 ( V_622 , V_10 -> V_64 . V_452 , V_79 ) )
return - V_453 ;
if ( 0 == strcmp ( V_620 -> V_623 , V_622 ) )
return V_140 ;
F_29 ( L_186 , V_341 , V_622 ) ;
V_140 = F_181 ( V_8 , V_622 ) ;
if ( 0 != V_140 )
goto exit;
if ( ! memcmp ( V_620 -> V_623 , L_187 , 9 ) ) {
V_8 -> V_626 . V_627 = V_620 -> V_628 ;
F_182 ( V_8 ) ;
F_183 ( & V_8 -> V_384 , V_620 -> V_629 ) ;
}
strncpy ( V_620 -> V_623 , V_622 , V_79 ) ;
V_620 -> V_623 [ V_79 - 1 ] = 0 ;
if ( ! memcmp ( V_622 , L_187 , 9 ) ) {
F_29 ( L_188 , V_341 ) ;
F_73 ( V_8 , true ) ;
F_137 ( V_8 , V_630 ) ;
V_620 -> V_628 = V_8 -> V_626 . V_627 ;
V_8 -> V_626 . V_627 = false ;
F_184 ( V_8 ) ;
V_620 -> V_629 = F_185 ( & V_8 -> V_384 ) ;
F_183 ( & V_8 -> V_384 , V_631 ) ;
}
exit:
return V_140 ;
}
static void F_186 ( struct V_7 * V_8 )
{
int V_4 , V_262 = 1 ;
F_172 ( L_189 ) ;
for ( V_4 = 0x0 ; V_4 < 0x300 ; V_4 += 4 ) {
if ( V_262 % 4 == 1 )
F_172 ( L_190 , V_4 ) ;
F_172 ( L_191 , F_108 ( V_8 , V_4 ) ) ;
if ( ( V_262 ++ ) % 4 == 0 )
F_172 ( L_192 ) ;
}
for ( V_4 = 0x400 ; V_4 < 0x800 ; V_4 += 4 ) {
if ( V_262 % 4 == 1 )
F_172 ( L_190 , V_4 ) ;
F_172 ( L_191 , F_108 ( V_8 , V_4 ) ) ;
if ( ( V_262 ++ ) % 4 == 0 )
F_172 ( L_192 ) ;
}
}
static void F_187 ( struct V_7 * V_8 )
{
int V_4 , V_262 = 1 ;
F_172 ( L_193 ) ;
for ( V_4 = 0x800 ; V_4 < 0x1000 ; V_4 += 4 ) {
if ( V_262 % 4 == 1 )
F_172 ( L_190 , V_4 ) ;
F_172 ( L_191 , F_108 ( V_8 , V_4 ) ) ;
if ( ( V_262 ++ ) % 4 == 0 )
F_172 ( L_192 ) ;
}
}
static void F_188 ( struct V_7 * V_8 )
{
int V_4 , V_262 = 1 , V_455 ;
T_4 V_104 ;
T_1 V_632 , V_633 = 0 ;
F_189 ( V_8 , V_634 , ( T_1 * ) ( & V_632 ) ) ;
F_172 ( L_194 ) ;
if ( ( V_635 == V_632 ) || ( V_636 == V_632 ) )
V_633 = 1 ;
else
V_633 = 2 ;
for ( V_455 = 0 ; V_455 < V_633 ; V_455 ++ ) {
F_172 ( L_195 , V_455 ) ;
for ( V_4 = 0 ; V_4 < 0x100 ; V_4 ++ ) {
V_104 = F_114 ( V_8 , V_455 , V_4 , 0xffffffff ) ;
if ( V_262 % 4 == 1 )
F_172 ( L_196 , V_4 ) ;
F_172 ( L_191 , V_104 ) ;
if ( ( V_262 ++ ) % 4 == 0 )
F_172 ( L_192 ) ;
}
}
}
static int F_190 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
T_1 V_637 , V_638 ;
T_2 V_639 ;
T_8 V_640 ;
T_4 * V_459 , V_641 ;
struct V_193 * V_194 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_284 * V_285 = & V_8 -> V_247 ;
struct V_642 * V_643 = & ( V_285 -> V_644 ) ;
struct V_165 * V_166 = & V_8 -> V_143 ;
struct V_28 * V_20 = & ( V_14 -> V_20 ) ;
struct V_196 * V_197 = & V_8 -> V_198 ;
V_459 = ( T_4 * ) & V_10 -> V_64 ;
V_641 = * V_459 ;
V_639 = ( T_2 ) ( V_641 & 0x0000ffff ) ;
V_637 = ( T_1 ) ( V_641 >> 24 ) ;
V_638 = ( T_1 ) ( ( V_641 >> 16 ) & 0x00ff ) ;
V_640 = * ( V_459 + 1 ) ;
switch ( V_637 ) {
case 0x70 :
switch ( V_638 ) {
case 1 :
F_29 ( L_197 , V_639 , F_106 ( V_8 , V_639 ) ) ;
break;
case 2 :
F_29 ( L_198 , V_639 , F_107 ( V_8 , V_639 ) ) ;
break;
case 4 :
F_29 ( L_199 , V_639 , F_108 ( V_8 , V_639 ) ) ;
break;
}
break;
case 0x71 :
switch ( V_638 ) {
case 1 :
F_110 ( V_8 , V_639 , V_640 ) ;
F_29 ( L_200 , V_639 , F_106 ( V_8 , V_639 ) ) ;
break;
case 2 :
F_111 ( V_8 , V_639 , V_640 ) ;
F_29 ( L_201 , V_639 , F_107 ( V_8 , V_639 ) ) ;
break;
case 4 :
F_112 ( V_8 , V_639 , V_640 ) ;
F_29 ( L_202 , V_639 , F_108 ( V_8 , V_639 ) ) ;
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
F_29 ( L_205 , V_638 , V_639 , F_114 ( V_8 , V_638 , V_639 , 0xffffffff ) ) ;
break;
case 0x75 :
F_116 ( V_8 , V_638 , V_639 , 0xffffffff , V_640 ) ;
F_29 ( L_206 , V_638 , V_639 , F_114 ( V_8 , V_638 , V_639 , 0xffffffff ) ) ;
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
V_140 = - V_221 ;
break;
}
F_194 ( V_648 , V_647 ) ;
if ( V_223 != F_195 ( V_8 , V_648 , 500 , 0 ) )
V_140 = - V_251 ;
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
V_140 = - V_221 ;
break;
}
for ( V_4 = 0 ; V_4 < V_650 ; V_4 ++ ) {
F_196 ( V_648 , V_649 , 0x00 , 0xff ) ;
F_197 ( V_648 , V_651 ) ;
F_196 ( V_648 , V_649 , 0x08 , 0xff ) ;
F_197 ( V_648 , V_651 ) ;
}
if ( V_223 != F_195 ( V_8 , V_648 , ( V_651 * V_650 * 2 ) + 200 , 0 ) )
V_140 = - V_251 ;
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
V_140 = - V_221 ;
break;
}
for ( V_4 = 0 ; V_4 < V_653 ; V_4 ++ )
F_196 ( V_648 , V_649 , V_4 + V_652 , 0xFF ) ;
if ( V_223 != F_195 ( V_8 , V_648 , 5000 , 0 ) )
V_140 = - V_251 ;
V_654 = F_106 ( V_8 , V_649 ) ;
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
V_140 = - V_221 ;
break;
}
for ( V_4 = 0 ; V_4 < V_653 ; V_4 ++ )
F_198 ( V_648 , V_649 , V_4 + V_652 , 0xFFFF ) ;
if ( V_223 != F_195 ( V_8 , V_648 , 5000 , 0 ) )
V_140 = - V_251 ;
V_654 = F_107 ( V_8 , V_649 ) ;
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
V_140 = - V_221 ;
break;
}
for ( V_4 = 0 ; V_4 < V_653 ; V_4 ++ )
F_199 ( V_648 , V_649 , V_4 + V_652 , 0xFFFFFFFF ) ;
if ( V_223 != F_195 ( V_8 , V_648 , 5000 , 0 ) )
V_140 = - V_251 ;
V_654 = F_108 ( V_8 , V_649 ) ;
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
F_29 ( L_213 , V_341 , V_655 ? L_214 : L_215 , V_104 ) ;
if ( V_655 )
V_104 = V_104 | 0x10 ;
V_656 = V_104 | ( V_104 << 5 ) ;
F_111 ( V_8 , 0x6d9 , V_656 ) ;
}
break;
case 0x7a :
F_200 ( V_8 , V_643 -> V_21 . V_22
, V_657 ) ;
break;
case 0x7F :
switch ( V_638 ) {
case 0x0 :
F_29 ( L_216 , F_81 ( V_14 ) ) ;
break;
case 0x01 :
F_29 ( L_217 ,
V_166 -> V_148 , V_166 -> V_178 ,
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
F_29 ( L_221 , V_285 -> V_248 ) ;
F_29 ( L_222 , V_285 -> V_525 ) ;
F_29 ( L_223 , V_285 -> V_524 ) ;
break;
case 0x05 :
V_194 = F_35 ( V_197 , V_20 -> V_21 . V_22 ) ;
if ( V_194 ) {
int V_4 ;
struct V_663 * V_664 ;
F_29 ( L_224 , V_20 -> V_21 . V_53 . V_53 ) ;
F_29 ( L_225 , V_194 -> V_665 ) ;
F_29 ( L_226 , V_285 -> V_248 , V_285 -> V_525 , V_285 -> V_524 ) ;
F_29 ( L_227 , V_194 -> V_666 , V_194 -> V_667 ) ;
F_29 ( L_228 , V_194 -> V_658 , V_194 -> V_668 , V_194 -> V_669 , V_194 -> V_670 ) ;
F_29 ( L_229 , V_194 -> V_660 , V_194 -> V_661 . V_662 , V_194 -> V_671 ) ;
F_29 ( L_230 , V_194 -> V_661 . V_518 , V_194 -> V_661 . V_517 , V_194 -> V_661 . V_672 ) ;
F_29 ( L_231 , V_194 -> V_661 . V_673 ) ;
F_29 ( L_232 , V_194 -> V_661 . V_674 , V_194 -> V_661 . V_675 ) ;
for ( V_4 = 0 ; V_4 < 16 ; V_4 ++ ) {
V_664 = & V_194 -> V_676 [ V_4 ] ;
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
F_127 ( V_8 , V_680 , ( T_1 * ) ( & V_679 ) ) ;
}
break;
case 0x07 :
F_29 ( L_237 ,
V_8 -> V_681 , V_8 -> V_351 ) ;
break;
case 0x08 :
{
struct V_682 * V_683 = & V_8 -> V_401 ;
struct V_684 * V_685 = & V_8 -> V_129 ;
F_29 ( L_238 ,
V_683 -> V_686 , V_683 -> V_687 , V_683 -> V_688 ) ;
F_29 ( L_239 , V_685 -> V_689 ) ;
}
break;
case 0x09 :
{
int V_4 , V_262 ;
struct V_323 * V_380 , * V_324 ;
struct V_663 * V_664 ;
#ifdef F_201
F_29 ( L_240 , V_197 -> V_690 , V_197 -> V_691 ) ;
#endif
F_59 ( & V_197 -> V_692 ) ;
for ( V_4 = 0 ; V_4 < V_693 ; V_4 ++ ) {
V_324 = & ( V_197 -> V_694 [ V_4 ] ) ;
V_380 = V_324 -> V_335 ;
while ( ( F_61 ( V_324 , V_380 ) ) == false ) {
V_194 = F_62 ( V_380 , struct V_193 , V_695 ) ;
V_380 = V_380 -> V_335 ;
if ( V_640 == V_194 -> V_668 ) {
F_29 ( L_241 , ( V_194 -> V_665 ) ) ;
F_29 ( L_227 , V_194 -> V_666 , V_194 -> V_667 ) ;
F_29 ( L_228 , V_194 -> V_658 , V_194 -> V_668 , V_194 -> V_669 , V_194 -> V_670 ) ;
F_29 ( L_229 , V_194 -> V_660 , V_194 -> V_661 . V_662 , V_194 -> V_671 ) ;
F_29 ( L_230 , V_194 -> V_661 . V_518 , V_194 -> V_661 . V_517 , V_194 -> V_661 . V_672 ) ;
F_29 ( L_231 , V_194 -> V_661 . V_673 ) ;
F_29 ( L_232 , V_194 -> V_661 . V_674 , V_194 -> V_661 . V_675 ) ;
#ifdef F_201
F_29 ( L_242 , V_194 -> V_696 ) ;
F_29 ( L_243 , V_194 -> V_65 ) ;
F_29 ( L_244 , V_194 -> V_697 ) ;
F_29 ( L_245 , V_194 -> V_698 ) ;
F_29 ( L_246 , V_194 -> V_699 ) ;
F_29 ( L_247 , V_194 -> V_700 ) ;
#endif
F_29 ( L_248 , V_194 -> V_204 ) ;
for ( V_262 = 0 ; V_262 < 16 ; V_262 ++ ) {
V_664 = & V_194 -> V_676 [ V_262 ] ;
if ( V_664 -> V_677 )
F_29 ( L_233 , V_262 , V_664 -> V_678 ) ;
}
}
}
}
F_63 ( & V_197 -> V_692 ) ;
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
struct V_410 * V_411 = & V_8 -> V_384 ;
F_29 ( L_252 , V_411 -> V_703 ) ;
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
struct V_707 * V_708 = & V_8 -> V_349 ;
if ( ! V_708 )
break;
if ( V_640 >= 0 && V_640 <= 3 ) {
V_708 -> V_709 = V_640 ;
F_29 ( L_257 , V_708 -> V_709 ) ;
} else {
F_29 ( L_258 , V_708 -> V_709 ) ;
}
}
break;
case 0x13 :
{
struct V_707 * V_708 = & V_8 -> V_349 ;
if ( ! V_708 )
break;
if ( V_640 >= 0 && V_640 < 3 ) {
V_708 -> V_673 = V_640 ;
F_29 ( L_259 , V_708 -> V_673 ) ;
} else {
F_29 ( L_260 , V_708 -> V_673 ) ;
}
}
break;
case 0x14 :
{
struct V_707 * V_708 = & V_8 -> V_349 ;
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
V_8 -> V_542 = V_640 ;
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
F_110 ( V_8 , 0xc50 , V_639 ) ;
F_29 ( L_292 , F_106 ( V_8 , 0xc50 ) ) ;
F_110 ( V_8 , 0xc58 , V_639 ) ;
F_29 ( L_293 , F_106 ( V_8 , 0xc58 ) ) ;
break;
case 0xfe :
F_29 ( L_294 , F_106 ( V_8 , 0xc50 ) ) ;
F_29 ( L_295 , F_106 ( V_8 , 0xc58 ) ) ;
break;
case 0xff :
F_29 ( L_296 , F_108 ( V_8 , 0x210 ) ) ;
F_29 ( L_297 , F_108 ( V_8 , 0x608 ) ) ;
F_29 ( L_298 , F_108 ( V_8 , 0x280 ) ) ;
F_29 ( L_299 , F_108 ( V_8 , 0x284 ) ) ;
F_29 ( L_300 , F_108 ( V_8 , 0x288 ) ) ;
F_29 ( L_301 , F_108 ( V_8 , 0x664 ) ) ;
F_29 ( L_192 ) ;
F_29 ( L_302 , F_108 ( V_8 , 0x430 ) ) ;
F_29 ( L_303 , F_108 ( V_8 , 0x438 ) ) ;
F_29 ( L_304 , F_108 ( V_8 , 0x440 ) ) ;
F_29 ( L_305 , F_108 ( V_8 , 0x458 ) ) ;
F_29 ( L_306 , F_108 ( V_8 , 0x484 ) ) ;
F_29 ( L_307 , F_108 ( V_8 , 0x488 ) ) ;
F_29 ( L_308 , F_108 ( V_8 , 0x444 ) ) ;
F_29 ( L_309 , F_108 ( V_8 , 0x448 ) ) ;
F_29 ( L_310 , F_108 ( V_8 , 0x44c ) ) ;
F_29 ( L_311 , F_108 ( V_8 , 0x450 ) ) ;
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
V_8 -> V_143 . V_148 = V_192 ;
switch ( ( V_104 ) & 0xff ) {
case 1 :
V_8 -> V_143 . V_146 = V_152 ;
V_8 -> V_143 . V_144 = V_202 ;
break;
case 2 :
V_8 -> V_143 . V_146 = V_225 ;
V_8 -> V_143 . V_144 = V_203 ;
break;
}
F_23 ( V_176 , V_113 ,
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
V_140 = - V_188 ;
break;
}
return V_140 ;
}
static int F_206 ( struct V_138 * V_139 , T_4 V_723 , T_4 V_338 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
switch ( V_723 ) {
case V_724 :
if ( ! F_68 ( V_8 ) )
V_140 = - 1 ;
break;
case V_725 :
if ( ! F_68 ( V_8 ) )
V_140 = - 1 ;
break;
default:
V_140 = - V_188 ;
break;
}
return V_140 ;
}
static int F_207 ( struct V_138 * V_139 , struct V_407 * V_39 )
{
struct V_157 * V_158 ;
T_5 V_140 = 0 ;
if ( V_39 -> V_66 < sizeof( struct V_157 ) || ! V_39 -> V_452 ) {
V_140 = - V_156 ;
goto V_726;
}
V_158 = (struct V_157 * ) F_32 ( V_39 -> V_66 ) ;
if ( V_158 == NULL ) {
V_140 = - V_221 ;
goto V_726;
}
if ( F_105 ( V_158 , V_39 -> V_452 , V_39 -> V_66 ) ) {
F_40 ( V_158 ) ;
V_140 = - V_453 ;
goto V_726;
}
switch ( V_158 -> V_60 ) {
case V_727 :
V_140 = F_205 ( V_139 , V_158 -> V_61 . V_728 . V_78 , V_158 -> V_61 . V_728 . V_104 ) ;
break;
case V_729 :
V_140 = F_41 ( (struct V_7 * ) F_28 ( V_139 ) ,
( char * ) V_158 -> V_61 . V_108 . V_64 , ( T_2 ) V_158 -> V_61 . V_108 . V_362 ) ;
break;
case V_437 :
V_140 = F_30 ( V_139 , V_158 , V_39 -> V_66 ) ;
break;
case V_730 :
V_140 = F_206 ( V_139 , V_158 -> V_61 . V_340 . V_723 , V_158 -> V_61 . V_340 . V_342 ) ;
break;
default:
F_29 ( L_314 , V_158 -> V_60 ) ;
V_140 = - V_188 ;
break;
}
if ( V_140 == 0 && F_131 ( V_39 -> V_452 , V_158 , V_39 -> V_66 ) )
V_140 = - V_453 ;
F_40 ( V_158 ) ;
V_726:
return V_140 ;
}
static T_1 F_208 ( struct V_7 * V_8 , struct V_193 * V_194 )
{
struct V_731 * V_732 ;
struct V_733 * V_734 ;
struct V_735 * V_736 = & V_8 -> V_737 ;
T_1 V_738 = V_223 ;
V_732 = (struct V_731 * ) F_43 ( sizeof( struct V_731 ) ) ;
if ( V_732 == NULL ) {
V_738 = V_187 ;
goto exit;
}
V_734 = (struct V_733 * ) F_43 ( sizeof( struct V_733 ) ) ;
if ( V_734 == NULL ) {
F_40 ( V_732 ) ;
V_738 = V_187 ;
goto exit;
}
F_209 ( V_732 , V_734 , V_739 ) ;
V_734 -> V_740 = ( T_1 ) V_194 -> V_204 ;
memcpy ( V_734 -> V_3 , V_194 -> V_665 , V_23 ) ;
memcpy ( V_734 -> V_171 , & V_194 -> V_205 , 16 ) ;
V_738 = F_210 ( V_736 , V_732 ) ;
exit:
return V_738 ;
}
static int F_211 ( struct V_7 * V_8 , T_1 * V_171 , T_1 V_169 , int V_741 )
{
T_1 V_742 ;
struct V_731 * V_743 ;
struct V_744 * V_745 ;
struct V_735 * V_736 = & ( V_8 -> V_737 ) ;
int V_738 = V_223 ;
F_29 ( L_57 , V_341 ) ;
V_743 = (struct V_731 * ) F_43 ( sizeof( struct V_731 ) ) ;
if ( V_743 == NULL ) {
V_738 = V_187 ;
goto exit;
}
V_745 = (struct V_744 * ) F_43 ( sizeof( struct V_744 ) ) ;
if ( V_745 == NULL ) {
F_40 ( V_743 ) ;
V_738 = V_187 ;
goto exit;
}
F_4 ( V_745 , 0 , sizeof( struct V_744 ) ) ;
V_745 -> V_741 = ( T_1 ) V_741 ;
V_745 -> V_740 = V_169 ;
V_745 -> V_186 = 1 ;
switch ( V_169 ) {
case V_179 :
V_742 = 5 ;
break;
case V_184 :
V_742 = 13 ;
break;
case V_231 :
case V_746 :
case V_233 :
default:
V_742 = 16 ;
}
memcpy ( & ( V_745 -> V_171 [ 0 ] ) , V_171 , V_742 ) ;
V_743 -> V_747 = V_748 ;
V_743 -> V_749 = ( T_1 * ) V_745 ;
V_743 -> V_750 = ( sizeof( struct V_744 ) ) ;
V_743 -> V_751 = NULL ;
V_743 -> V_752 = 0 ;
F_212 ( & V_743 -> V_336 ) ;
V_738 = F_210 ( V_736 , V_743 ) ;
exit:
return V_738 ;
}
static int F_213 ( struct V_7 * V_8 , T_1 * V_171 , T_1 V_742 , int V_741 )
{
T_1 V_169 ;
switch ( V_742 ) {
case 5 :
V_169 = V_179 ;
break;
case 13 :
V_169 = V_184 ;
break;
default:
V_169 = V_227 ;
}
return F_211 ( V_8 , V_171 , V_169 , V_741 ) ;
}
static int F_214 ( struct V_138 * V_139 , struct V_157 * V_158 , T_4 V_159 )
{
int V_140 = 0 ;
T_4 V_160 , V_161 , V_162 ;
struct V_163 * V_164 = NULL ;
struct V_193 * V_194 = NULL , * V_195 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & V_8 -> V_15 ;
struct V_165 * V_166 = & ( V_8 -> V_143 ) ;
struct V_196 * V_197 = & V_8 -> V_198 ;
F_29 ( L_57 , V_341 ) ;
V_158 -> V_61 . V_167 . V_168 = 0 ;
V_158 -> V_61 . V_167 . V_169 [ V_170 - 1 ] = '\0' ;
if ( V_159 != sizeof( struct V_157 ) + V_158 -> V_61 . V_167 . V_172 ) {
V_140 = - V_156 ;
goto exit;
}
if ( V_158 -> V_173 [ 0 ] == 0xff && V_158 -> V_173 [ 1 ] == 0xff &&
V_158 -> V_173 [ 2 ] == 0xff && V_158 -> V_173 [ 3 ] == 0xff &&
V_158 -> V_173 [ 4 ] == 0xff && V_158 -> V_173 [ 5 ] == 0xff ) {
if ( V_158 -> V_61 . V_167 . V_174 >= V_175 ) {
V_140 = - V_156 ;
goto exit;
}
} else {
V_194 = F_35 ( V_197 , V_158 -> V_173 ) ;
if ( ! V_194 ) {
F_29 ( L_315 ) ;
goto exit;
}
}
if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_32 ) == 0 && ( V_194 == NULL ) ) {
F_29 ( L_316 , V_158 -> V_61 . V_167 . V_174 ) ;
goto exit;
}
if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_25 ) == 0 && ( V_194 == NULL ) ) {
F_29 ( L_317 ) ;
V_160 = V_158 -> V_61 . V_167 . V_174 ;
V_161 = V_158 -> V_61 . V_167 . V_172 ;
F_29 ( L_318 , V_160 , V_161 ) ;
if ( ( V_160 >= V_175 ) || ( V_161 <= 0 ) ) {
V_140 = - V_156 ;
goto exit;
}
if ( V_161 > 0 ) {
V_161 = V_161 <= 5 ? 5 : 13 ;
V_162 = V_161 + F_31 ( struct V_163 , V_181 ) ;
V_164 = (struct V_163 * ) F_32 ( V_162 ) ;
if ( V_164 == NULL ) {
F_29 ( L_319 ) ;
goto exit;
}
F_4 ( V_164 , 0 , V_162 ) ;
V_164 -> V_182 = V_161 ;
V_164 -> V_183 = V_162 ;
}
V_164 -> V_185 = V_160 ;
memcpy ( V_164 -> V_181 , V_158 -> V_61 . V_167 . V_171 , V_164 -> V_182 ) ;
if ( V_158 -> V_61 . V_167 . V_186 ) {
F_29 ( L_30 ) ;
V_166 -> V_144 = V_145 ;
V_166 -> V_178 = V_179 ;
V_166 -> V_180 = V_179 ;
if ( V_164 -> V_182 == 13 ) {
V_166 -> V_178 = V_184 ;
V_166 -> V_180 = V_184 ;
}
V_166 -> V_413 = V_160 ;
memcpy ( & ( V_166 -> V_189 [ V_160 ] . V_190 [ 0 ] ) , V_164 -> V_181 , V_164 -> V_182 ) ;
V_166 -> V_191 [ V_160 ] = V_164 -> V_182 ;
F_213 ( V_8 , V_164 -> V_181 , V_164 -> V_182 , V_160 ) ;
} else {
F_29 ( L_31 ) ;
memcpy ( & ( V_166 -> V_189 [ V_160 ] . V_190 [ 0 ] ) , V_164 -> V_181 , V_164 -> V_182 ) ;
V_166 -> V_191 [ V_160 ] = V_164 -> V_182 ;
F_213 ( V_8 , V_164 -> V_181 , V_164 -> V_182 , V_160 ) ;
}
goto exit;
}
if ( ! V_194 && F_25 ( V_14 , V_261 ) ) {
if ( V_158 -> V_61 . V_167 . V_186 == 1 ) {
if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_25 ) == 0 ) {
F_29 ( L_320 , V_341 ) ;
memcpy ( V_166 -> V_209 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 ,
V_158 -> V_61 . V_167 . V_171 , ( V_158 -> V_61 . V_167 . V_172 > 16 ? 16 : V_158 -> V_61 . V_167 . V_172 ) ) ;
V_166 -> V_180 = V_179 ;
if ( V_158 -> V_61 . V_167 . V_172 == 13 )
V_166 -> V_180 = V_184 ;
} else if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_33 ) == 0 ) {
F_29 ( L_321 , V_341 ) ;
V_166 -> V_180 = V_231 ;
memcpy ( V_166 -> V_209 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 ,
V_158 -> V_61 . V_167 . V_171 , ( V_158 -> V_61 . V_167 . V_172 > 16 ? 16 : V_158 -> V_61 . V_167 . V_172 ) ) ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 16 ] ) , 8 ) ;
memcpy ( V_166 -> V_211 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 24 ] ) , 8 ) ;
V_166 -> V_208 = true ;
} else if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_89 ) == 0 ) {
F_29 ( L_322 , V_341 ) ;
V_166 -> V_180 = V_233 ;
memcpy ( V_166 -> V_209 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 ,
V_158 -> V_61 . V_167 . V_171 , ( V_158 -> V_61 . V_167 . V_172 > 16 ? 16 : V_158 -> V_61 . V_167 . V_172 ) ) ;
} else {
F_29 ( L_323 , V_341 ) ;
V_166 -> V_180 = V_227 ;
}
V_166 -> V_213 = V_158 -> V_61 . V_167 . V_174 ;
V_166 -> V_212 = true ;
V_166 -> V_178 = V_166 -> V_180 ;
F_211 ( V_8 , V_158 -> V_61 . V_167 . V_171 , V_166 -> V_180 , V_158 -> V_61 . V_167 . V_174 ) ;
V_195 = F_39 ( V_8 ) ;
if ( V_195 ) {
V_195 -> V_201 = false ;
V_195 -> V_204 = V_166 -> V_180 ;
}
}
goto exit;
}
if ( V_166 -> V_148 == V_192 && V_194 ) {
if ( F_25 ( V_14 , V_261 ) ) {
if ( V_158 -> V_61 . V_167 . V_186 == 1 ) {
memcpy ( V_194 -> V_205 . V_190 , V_158 -> V_61 . V_167 . V_171 , ( V_158 -> V_61 . V_167 . V_172 > 16 ? 16 : V_158 -> V_61 . V_167 . V_172 ) ) ;
if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_25 ) == 0 ) {
F_29 ( L_324 , V_341 ) ;
V_194 -> V_204 = V_179 ;
if ( V_158 -> V_61 . V_167 . V_172 == 13 )
V_194 -> V_204 = V_184 ;
} else if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_33 ) == 0 ) {
F_29 ( L_325 , V_341 ) ;
V_194 -> V_204 = V_231 ;
memcpy ( V_194 -> V_206 . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 16 ] ) , 8 ) ;
memcpy ( V_194 -> V_207 . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 24 ] ) , 8 ) ;
V_166 -> V_208 = true ;
} else if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_89 ) == 0 ) {
F_29 ( L_326 , V_341 ) ;
V_194 -> V_204 = V_233 ;
} else {
F_29 ( L_327 , V_341 ) ;
V_194 -> V_204 = V_227 ;
}
F_208 ( V_8 , V_194 ) ;
V_194 -> V_201 = false ;
} else {
if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_25 ) == 0 ) {
memcpy ( V_166 -> V_209 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 ,
V_158 -> V_61 . V_167 . V_171 , ( V_158 -> V_61 . V_167 . V_172 > 16 ? 16 : V_158 -> V_61 . V_167 . V_172 ) ) ;
V_166 -> V_180 = V_179 ;
if ( V_158 -> V_61 . V_167 . V_172 == 13 )
V_166 -> V_180 = V_184 ;
} else if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_33 ) == 0 ) {
V_166 -> V_180 = V_231 ;
memcpy ( V_166 -> V_209 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 ,
V_158 -> V_61 . V_167 . V_171 , ( V_158 -> V_61 . V_167 . V_172 > 16 ? 16 : V_158 -> V_61 . V_167 . V_172 ) ) ;
memcpy ( V_166 -> V_210 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 16 ] ) , 8 ) ;
memcpy ( V_166 -> V_211 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 , & ( V_158 -> V_61 . V_167 . V_171 [ 24 ] ) , 8 ) ;
V_166 -> V_208 = true ;
} else if ( strcmp ( V_158 -> V_61 . V_167 . V_169 , L_89 ) == 0 ) {
V_166 -> V_180 = V_233 ;
memcpy ( V_166 -> V_209 [ V_158 -> V_61 . V_167 . V_174 ] . V_190 ,
V_158 -> V_61 . V_167 . V_171 , ( V_158 -> V_61 . V_167 . V_172 > 16 ? 16 : V_158 -> V_61 . V_167 . V_172 ) ) ;
} else {
V_166 -> V_180 = V_227 ;
}
V_166 -> V_213 = V_158 -> V_61 . V_167 . V_174 ;
V_166 -> V_212 = true ;
V_166 -> V_178 = V_166 -> V_180 ;
F_211 ( V_8 , V_158 -> V_61 . V_167 . V_171 , V_166 -> V_180 , V_158 -> V_61 . V_167 . V_174 ) ;
V_195 = F_39 ( V_8 ) ;
if ( V_195 ) {
V_195 -> V_201 = false ;
V_195 -> V_204 = V_166 -> V_180 ;
}
}
}
}
exit:
F_40 ( V_164 ) ;
return V_140 ;
}
static int F_215 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_362 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_196 * V_197 = & V_8 -> V_198 ;
unsigned char * V_502 = V_158 -> V_61 . V_753 . V_106 ;
F_29 ( L_328 , V_341 , V_362 ) ;
if ( F_25 ( V_14 , V_261 ) != true )
return - V_156 ;
memcpy ( & V_197 -> V_754 , V_158 -> V_61 . V_753 . V_755 , 2 ) ;
if ( ( V_197 -> V_754 > V_693 ) || ( V_197 -> V_754 <= 0 ) )
V_197 -> V_754 = V_693 ;
if ( F_216 ( V_8 , V_502 , ( V_362 - 12 - 2 ) ) == V_223 )
V_140 = 0 ;
else
V_140 = - V_156 ;
return V_140 ;
}
static int F_217 ( struct V_138 * V_139 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_57 , V_341 ) ;
F_218 ( V_8 ) ;
V_140 = F_219 ( V_8 ) ;
return V_140 ;
}
static int F_220 ( struct V_138 * V_139 , struct V_157 * V_158 )
{
int V_140 = 0 ;
struct V_193 * V_194 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_196 * V_197 = & V_8 -> V_198 ;
F_29 ( L_329 , V_158 -> V_61 . V_756 . V_668 , ( V_158 -> V_173 ) ) ;
if ( ! F_25 ( V_14 , ( V_128 | V_261 ) ) )
return - V_156 ;
if ( V_158 -> V_173 [ 0 ] == 0xff && V_158 -> V_173 [ 1 ] == 0xff &&
V_158 -> V_173 [ 2 ] == 0xff && V_158 -> V_173 [ 3 ] == 0xff &&
V_158 -> V_173 [ 4 ] == 0xff && V_158 -> V_173 [ 5 ] == 0xff )
return - V_156 ;
V_194 = F_35 ( V_197 , V_158 -> V_173 ) ;
if ( V_194 ) {
int V_65 = V_158 -> V_61 . V_756 . V_65 ;
V_194 -> V_668 = V_158 -> V_61 . V_756 . V_668 ;
memcpy ( V_194 -> V_757 , V_158 -> V_61 . V_756 . V_758 , 16 ) ;
if ( V_759 & V_65 )
V_194 -> V_660 = 1 ;
else
V_194 -> V_660 = 0 ;
if ( V_14 -> V_659 . V_660 == 0 )
V_194 -> V_660 = 0 ;
if ( V_760 & V_65 ) {
V_194 -> V_661 . V_662 = true ;
V_194 -> V_660 = 1 ;
memcpy ( ( void * ) & V_194 -> V_661 . V_42 , ( void * ) & V_158 -> V_61 . V_756 . V_42 , sizeof( struct V_69 ) ) ;
} else {
V_194 -> V_661 . V_662 = false ;
}
if ( V_14 -> V_661 . V_662 == false )
V_194 -> V_661 . V_662 = false ;
F_221 ( V_8 , V_194 ) ;
} else {
V_140 = - V_221 ;
}
return V_140 ;
}
static int F_222 ( struct V_138 * V_139 , struct V_157 * V_158 )
{
int V_140 = 0 ;
struct V_193 * V_194 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_196 * V_197 = & V_8 -> V_198 ;
int V_124 = 0 ;
F_29 ( L_330 , ( V_158 -> V_173 ) ) ;
if ( F_25 ( V_14 , ( V_128 | V_261 ) ) != true )
return - V_156 ;
if ( V_158 -> V_173 [ 0 ] == 0xff && V_158 -> V_173 [ 1 ] == 0xff &&
V_158 -> V_173 [ 2 ] == 0xff && V_158 -> V_173 [ 3 ] == 0xff &&
V_158 -> V_173 [ 4 ] == 0xff && V_158 -> V_173 [ 5 ] == 0xff )
return - V_156 ;
V_194 = F_35 ( V_197 , V_158 -> V_173 ) ;
if ( V_194 ) {
F_59 ( & V_197 -> V_761 ) ;
if ( ! F_223 ( & V_194 -> V_762 ) ) {
F_224 ( & V_194 -> V_762 ) ;
V_197 -> V_763 -- ;
V_124 = F_225 ( V_8 , V_194 , true , V_764 ) ;
}
F_63 ( & V_197 -> V_761 ) ;
F_226 ( V_8 , V_124 ) ;
V_194 = NULL ;
} else {
F_29 ( L_331 ) ;
}
return V_140 ;
}
static int F_227 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_362 )
{
int V_140 = 0 ;
struct V_193 * V_194 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_196 * V_197 = & V_8 -> V_198 ;
struct V_765 * V_766 = (struct V_765 * ) V_158 ;
struct V_767 * V_768 = (struct V_767 * ) V_766 -> V_64 ;
F_29 ( L_332 , ( V_766 -> V_173 ) ) ;
if ( F_25 ( V_14 , ( V_128 | V_261 ) ) != true )
return - V_156 ;
if ( V_766 -> V_173 [ 0 ] == 0xff && V_766 -> V_173 [ 1 ] == 0xff &&
V_766 -> V_173 [ 2 ] == 0xff && V_766 -> V_173 [ 3 ] == 0xff &&
V_766 -> V_173 [ 4 ] == 0xff && V_766 -> V_173 [ 5 ] == 0xff )
return - V_156 ;
V_194 = F_35 ( V_197 , V_766 -> V_173 ) ;
if ( V_194 ) {
V_768 -> V_668 = ( T_2 ) V_194 -> V_668 ;
V_768 -> V_696 = V_194 -> V_696 ;
V_768 -> V_65 = V_194 -> V_65 ;
V_768 -> V_769 = ( ( V_194 -> V_770 ) |
( V_194 -> V_771 << 1 ) |
( V_194 -> V_772 << 2 ) |
( V_194 -> V_773 << 3 ) |
( V_194 -> V_774 << 4 ) |
( V_194 -> V_775 << 5 ) ) ;
V_768 -> V_776 = V_194 -> V_777 ;
memcpy ( V_768 -> V_758 , V_194 -> V_757 , V_194 -> V_777 ) ;
memcpy ( & V_768 -> V_42 , & V_194 -> V_661 . V_42 , sizeof( struct V_69 ) ) ;
V_768 -> V_778 = V_194 -> V_779 . V_780 ;
V_768 -> V_781 = V_194 -> V_779 . V_781 ;
V_768 -> V_782 = V_194 -> V_779 . V_782 ;
V_768 -> V_783 = V_194 -> V_779 . V_783 ;
V_768 -> V_784 = V_194 -> V_779 . V_784 ;
V_768 -> V_785 = V_194 -> V_779 . V_785 ;
} else {
V_140 = - 1 ;
}
return V_140 ;
}
static int F_228 ( struct V_138 * V_139 , struct V_157 * V_158 )
{
int V_140 = 0 ;
struct V_193 * V_194 = NULL ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_196 * V_197 = & V_8 -> V_198 ;
F_29 ( L_333 , ( V_158 -> V_173 ) ) ;
if ( F_25 ( V_14 , ( V_128 | V_261 ) ) != true )
return - V_156 ;
if ( V_158 -> V_173 [ 0 ] == 0xff && V_158 -> V_173 [ 1 ] == 0xff &&
V_158 -> V_173 [ 2 ] == 0xff && V_158 -> V_173 [ 3 ] == 0xff &&
V_158 -> V_173 [ 4 ] == 0xff && V_158 -> V_173 [ 5 ] == 0xff )
return - V_156 ;
V_194 = F_35 ( V_197 , V_158 -> V_173 ) ;
if ( V_194 ) {
if ( ( V_194 -> V_108 [ 0 ] == V_786 ) || ( V_194 -> V_108 [ 0 ] == V_787 ) ) {
int V_788 ;
int V_789 ;
V_788 = V_194 -> V_108 [ 1 ] ;
V_789 = ( ( V_788 + 2 ) > sizeof( V_194 -> V_108 ) ) ? ( sizeof( V_194 -> V_108 ) ) : ( V_788 + 2 ) ;
V_158 -> V_61 . V_108 . V_362 = V_789 ;
memcpy ( V_158 -> V_61 . V_108 . V_755 , V_194 -> V_108 , V_789 ) ;
} else {
F_29 ( L_334 ) ;
}
} else {
V_140 = - 1 ;
}
return V_140 ;
}
static int F_229 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_362 )
{
int V_140 = 0 ;
unsigned char V_236 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_284 * V_285 = & ( V_8 -> V_247 ) ;
int V_790 ;
F_29 ( L_328 , V_341 , V_362 ) ;
if ( F_25 ( V_14 , V_261 ) != true )
return - V_156 ;
V_790 = V_362 - 12 - 2 ;
if ( V_14 -> V_791 ) {
F_40 ( V_14 -> V_791 ) ;
V_14 -> V_791 = NULL ;
}
if ( V_790 > 0 ) {
V_14 -> V_791 = F_32 ( V_790 ) ;
V_14 -> V_792 = V_790 ;
if ( V_14 -> V_791 == NULL ) {
F_29 ( L_335 , V_341 , __LINE__ ) ;
return - V_156 ;
}
memcpy ( V_14 -> V_791 , V_158 -> V_61 . V_753 . V_106 , V_790 ) ;
F_230 ( V_8 , V_237 , V_236 , true ) ;
V_285 -> V_793 = true ;
}
return V_140 ;
}
static int F_231 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_362 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
int V_790 ;
F_29 ( L_328 , V_341 , V_362 ) ;
if ( F_25 ( V_14 , V_261 ) != true )
return - V_156 ;
V_790 = V_362 - 12 - 2 ;
if ( V_14 -> V_794 ) {
F_40 ( V_14 -> V_794 ) ;
V_14 -> V_794 = NULL ;
}
if ( V_790 > 0 ) {
V_14 -> V_794 = F_32 ( V_790 ) ;
V_14 -> V_795 = V_790 ;
if ( V_14 -> V_794 == NULL ) {
F_29 ( L_335 , V_341 , __LINE__ ) ;
return - V_156 ;
}
memcpy ( V_14 -> V_794 , V_158 -> V_61 . V_753 . V_106 , V_790 ) ;
}
return V_140 ;
}
static int F_232 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_362 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
int V_790 ;
F_29 ( L_328 , V_341 , V_362 ) ;
if ( F_25 ( V_14 , V_261 ) != true )
return - V_156 ;
V_790 = V_362 - 12 - 2 ;
if ( V_14 -> V_796 ) {
F_40 ( V_14 -> V_796 ) ;
V_14 -> V_796 = NULL ;
}
if ( V_790 > 0 ) {
V_14 -> V_796 = F_32 ( V_790 ) ;
V_14 -> V_797 = V_790 ;
if ( V_14 -> V_796 == NULL ) {
F_29 ( L_335 , V_341 , __LINE__ ) ;
return - V_156 ;
}
memcpy ( V_14 -> V_796 , V_158 -> V_61 . V_753 . V_106 , V_790 ) ;
}
return V_140 ;
}
static int F_233 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_362 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
struct V_284 * V_285 = & ( V_8 -> V_247 ) ;
struct V_642 * V_643 = & ( V_285 -> V_644 ) ;
T_1 V_104 ;
if ( F_25 ( V_14 , V_261 ) != true )
return - V_156 ;
if ( V_158 -> V_61 . V_728 . V_78 != 0 )
F_29 ( L_336 , V_341 , V_158 -> V_61 . V_728 . V_78 ) ;
V_104 = V_158 -> V_61 . V_728 . V_104 ;
if ( V_104 != 1 && V_104 != 2 )
V_104 = 0 ;
F_29 ( L_337 , V_341 , V_104 ) ;
V_643 -> V_798 = V_104 ;
return V_140 ;
}
static int F_234 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_362 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
if ( F_25 ( V_14 , V_261 ) != true )
return - V_156 ;
if ( V_158 -> V_173 [ 0 ] == 0xff && V_158 -> V_173 [ 1 ] == 0xff &&
V_158 -> V_173 [ 2 ] == 0xff && V_158 -> V_173 [ 3 ] == 0xff &&
V_158 -> V_173 [ 4 ] == 0xff && V_158 -> V_173 [ 5 ] == 0xff )
return - V_156 ;
V_140 = F_235 ( V_8 , V_158 -> V_173 ) ;
return V_140 ;
}
static int F_236 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_362 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
if ( F_25 ( V_14 , V_261 ) != true )
return - V_156 ;
if ( V_158 -> V_173 [ 0 ] == 0xff && V_158 -> V_173 [ 1 ] == 0xff &&
V_158 -> V_173 [ 2 ] == 0xff && V_158 -> V_173 [ 3 ] == 0xff &&
V_158 -> V_173 [ 4 ] == 0xff && V_158 -> V_173 [ 5 ] == 0xff )
return - V_156 ;
V_140 = F_237 ( V_8 , V_158 -> V_173 ) ;
return V_140 ;
}
static int F_238 ( struct V_138 * V_139 , struct V_157 * V_158 , int V_362 )
{
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
if ( F_25 ( V_14 , V_261 ) != true )
return - V_156 ;
F_239 ( V_8 , V_158 -> V_61 . V_340 . V_723 ) ;
return V_140 ;
}
static int F_240 ( struct V_138 * V_139 , struct V_407 * V_39 )
{
struct V_157 * V_158 ;
int V_140 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
if ( ! V_8 -> V_252 ) {
V_140 = - V_251 ;
goto V_726;
}
if ( ! V_39 -> V_452 ) {
V_140 = - V_156 ;
goto V_726;
}
V_158 = (struct V_157 * ) F_32 ( V_39 -> V_66 ) ;
if ( V_158 == NULL ) {
V_140 = - V_221 ;
goto V_726;
}
if ( F_105 ( V_158 , V_39 -> V_452 , V_39 -> V_66 ) ) {
F_40 ( V_158 ) ;
V_140 = - V_453 ;
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
V_140 = - V_188 ;
break;
}
if ( V_140 == 0 && F_131 ( V_39 -> V_452 , V_158 , V_39 -> V_66 ) )
V_140 = - V_453 ;
F_40 ( V_158 ) ;
V_726:
return V_140 ;
}
static int F_241 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_320 ,
char * V_241 )
{
int V_140 = 0 ;
int V_362 = 0 ;
char * V_813 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
struct V_407 * V_814 = (struct V_407 * ) V_320 ;
if ( V_814 -> V_66 == 0 )
return - V_453 ;
V_362 = V_814 -> V_66 ;
V_813 = F_242 ( V_362 ) ;
if ( ! V_813 )
return - V_221 ;
if ( F_105 ( V_813 , V_814 -> V_452 , V_362 ) ) {
F_243 ( V_813 ) ;
return - V_453 ;
}
if ( V_814 -> V_65 == 0x8766 && V_362 > 8 ) {
T_4 V_815 ;
struct V_13 * V_14 = & ( V_8 -> V_15 ) ;
T_1 * V_816 = V_813 ;
int V_817 = V_362 ;
T_1 V_236 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
if ( ( V_237 == V_816 [ 0 ] ) &&
( ! memcmp ( & V_816 [ 2 ] , V_236 , 4 ) ) ) {
V_815 = V_817 > V_818 ? V_818 : V_817 ;
V_14 -> V_819 = 0 ;
F_40 ( V_14 -> V_820 ) ;
V_14 -> V_820 = NULL ;
V_14 -> V_820 = F_32 ( V_815 ) ;
if ( V_14 -> V_820 == NULL ) {
F_172 ( L_335 , V_341 , __LINE__ ) ;
V_140 = - V_156 ;
goto V_821;
}
memcpy ( V_14 -> V_820 , V_816 , V_815 ) ;
V_14 -> V_819 = V_815 ;
}
goto V_821;
}
if ( V_362 >= V_368 &&
! memcmp ( V_813 , V_369 , V_368 ) ) {
V_140 = F_69 ( V_139 , V_27 , V_320 , V_813 ) ;
goto V_821;
}
V_821:
F_243 ( V_813 ) ;
return V_140 ;
}
static int F_244 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
int V_140 = 0 ;
unsigned V_86 = 0 ;
struct V_7 * V_8 = (struct V_7 * ) F_28 ( V_139 ) ;
F_29 ( L_156 , V_341 , V_241 ) ;
if ( ! memcmp ( V_241 , L_339 , 4 ) ) {
V_140 = sscanf ( V_241 + 4 , L_340 , & V_86 ) ;
if ( V_140 != 1 )
return - V_156 ;
V_140 = F_245 ( V_8 , V_86 ) ;
} else if ( ! memcmp ( V_241 , L_341 , 4 ) ) {
V_140 = sscanf ( V_241 + 4 , L_340 , & V_86 ) ;
if ( V_140 != 1 )
return - V_156 ;
V_140 = F_246 ( V_8 , V_86 ) ;
} else {
V_140 = - V_156 ;
}
return V_140 ;
}
static int F_247 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_822 , char * V_241 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
struct V_823 * V_824 = F_248 ( V_8 ) ;
struct V_825 * V_826 = F_249 ( V_8 ) ;
struct V_827 * V_828 ;
struct V_407 * V_10 ;
T_1 * V_829 = V_824 -> V_830 ;
T_1 V_831 = 0 , V_832 = 0 ;
struct V_410 * V_384 ;
T_1 * V_64 = NULL ;
T_1 * V_833 = NULL ;
char * V_834 , * V_450 , * V_595 , * V_835 [ 3 ] = { NULL , NULL , NULL } ;
T_2 V_4 = 0 , V_262 = 0 , V_836 = 0 , V_3 = 0 , V_837 = 0 ;
T_2 V_838 = 0 , V_839 = 0 , V_840 = 0 ;
int V_168 ;
T_1 V_841 = V_8 -> V_349 . V_842 ;
V_10 = (struct V_407 * ) V_822 ;
V_384 = & V_8 -> V_384 ;
V_828 = & V_826 -> V_843 ;
V_168 = 0 ;
V_64 = F_250 ( V_844 ) ;
if ( V_64 == NULL ) {
V_168 = - V_221 ;
goto exit;
}
V_833 = F_250 ( V_844 ) ;
if ( V_833 == NULL ) {
V_168 = - V_221 ;
goto exit;
}
if ( F_105 ( V_241 , V_10 -> V_452 , V_10 -> V_66 ) ) {
V_168 = - V_453 ;
goto exit;
}
V_832 = V_384 -> V_845 ;
F_245 ( V_8 , V_846 ) ;
V_831 = V_384 -> V_831 ;
F_246 ( V_8 , V_847 ) ;
V_834 = V_241 ;
F_29 ( L_342 , V_341 , V_241 ) ;
V_4 = 0 ;
while ( ( V_595 = F_251 ( & V_834 , L_343 ) ) != NULL ) {
if ( V_4 > 2 )
break;
V_835 [ V_4 ] = V_595 ;
V_4 ++ ;
}
V_8 -> V_349 . V_842 = 0 ;
if ( strcmp ( V_835 [ 0 ] , L_169 ) == 0 ) {
sprintf ( V_241 , L_344 , ( V_824 -> V_848 ? L_345 : L_346 ) , ( V_824 -> V_849 ? L_345 : L_346 ) ) ;
goto exit;
} else if ( strcmp ( V_835 [ 0 ] , L_347 ) == 0 ) {
V_836 = V_850 ;
sprintf ( V_241 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_850 ; V_4 += 16 ) {
sprintf ( V_241 , L_348 , V_241 , V_4 ) ;
for ( V_262 = 0 ; V_262 < 8 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_829 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_350 , V_241 ) ;
for (; V_262 < 16 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_829 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_57 , V_241 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_351 ) == 0 ) {
V_836 = V_850 ;
if ( F_252 ( V_8 , 0 , V_836 , V_828 -> V_851 ) == V_187 ) {
F_29 ( L_352 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
sprintf ( V_241 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_850 ; V_4 += 16 ) {
sprintf ( V_241 , L_348 , V_241 , V_4 ) ;
for ( V_262 = 0 ; V_262 < 8 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_851 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_350 , V_241 ) ;
for (; V_262 < 16 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_851 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_57 , V_241 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_353 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
F_29 ( L_354 , V_341 ) ;
V_168 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_450 , 16 ) ;
F_29 ( L_355 , V_341 , V_3 ) ;
V_837 = F_253 ( V_835 [ 2 ] , & V_450 , 10 ) ;
if ( V_837 == 0 ) {
F_29 ( L_356 , V_341 ) ;
V_168 = - V_156 ;
goto exit;
}
F_29 ( L_357 , V_341 , V_837 ) ;
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_341 , V_3 , V_837 ) ;
V_168 = - V_156 ;
goto exit;
}
if ( F_252 ( V_8 , V_3 , V_837 , V_64 ) == V_187 ) {
F_29 ( L_359 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
* V_241 = 0 ;
for ( V_4 = 0 ; V_4 < V_837 ; V_4 ++ )
sprintf ( V_241 , L_360 , V_241 , V_64 [ V_4 ] ) ;
} else if ( strcmp ( V_835 [ 0 ] , L_361 ) == 0 ) {
V_3 = 0 ;
V_836 = V_854 ;
if ( F_255 ( V_8 , false , V_3 , V_836 , V_833 ) == V_187 ) {
F_29 ( L_362 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
sprintf ( V_241 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_836 ; V_4 ++ ) {
sprintf ( V_241 , L_363 , V_241 , V_833 [ V_4 ] ) ;
if ( ( V_4 & 0xF ) == 0xF )
sprintf ( V_241 , L_57 , V_241 ) ;
else if ( ( V_4 & 0x7 ) == 0x7 )
sprintf ( V_241 , L_350 , V_241 ) ;
else
sprintf ( V_241 , L_364 , V_241 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_365 ) == 0 ) {
V_837 = 6 ;
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_366 , V_341 , V_3 , V_837 ) ;
V_168 = - V_453 ;
goto exit;
}
if ( F_252 ( V_8 , V_3 , V_837 , V_64 ) == V_187 ) {
F_29 ( L_359 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
* V_241 = 0 ;
for ( V_4 = 0 ; V_4 < V_837 ; V_4 ++ ) {
sprintf ( V_241 , L_363 , V_241 , V_64 [ V_4 ] ) ;
if ( V_4 != ( V_837 - 1 ) )
sprintf ( V_241 , L_367 , V_241 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_368 ) == 0 ) {
V_837 = 4 ;
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_366 , V_341 , V_3 , V_837 ) ;
V_168 = - V_453 ;
goto exit;
}
if ( F_252 ( V_8 , V_3 , V_837 , V_64 ) == V_187 ) {
F_29 ( L_369 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
* V_241 = 0 ;
for ( V_4 = 0 ; V_4 < V_837 ; V_4 ++ ) {
sprintf ( V_241 , L_370 , V_241 , V_64 [ V_4 ] ) ;
if ( V_4 != ( V_837 - 1 ) )
sprintf ( V_241 , L_371 , V_241 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_372 ) == 0 ) {
F_256 ( V_8 , & V_839 ) ;
V_840 = F_257 ( V_8 ) ;
sprintf ( V_241 , L_373 , V_840 - V_839 ) ;
} else if ( strcmp ( V_835 [ 0 ] , L_374 ) == 0 ) {
V_836 = V_844 ;
if ( F_258 ( V_8 , 0 , V_836 , V_828 -> V_855 ) == V_187 ) {
F_29 ( L_375 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
sprintf ( V_241 , L_192 ) ;
for ( V_4 = 0 ; V_4 < 512 ; V_4 += 16 ) {
sprintf ( V_241 , L_376 , V_241 , V_4 ) ;
for ( V_262 = 0 ; V_262 < 8 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_855 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_350 , V_241 ) ;
for (; V_262 < 16 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_855 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_57 , V_241 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_377 ) == 0 ) {
V_836 = V_844 ;
if ( F_258 ( V_8 , 0 , V_836 , V_828 -> V_855 ) == V_187 ) {
F_29 ( L_375 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
sprintf ( V_241 , L_192 ) ;
for ( V_4 = 512 ; V_4 < 1024 ; V_4 += 16 ) {
sprintf ( V_241 , L_376 , V_241 , V_4 ) ;
for ( V_262 = 0 ; V_262 < 8 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_855 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_350 , V_241 ) ;
for (; V_262 < 16 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_855 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_57 , V_241 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_378 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_168 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_450 , 16 ) ;
F_29 ( L_379 , V_341 , V_3 ) ;
V_837 = F_253 ( V_835 [ 2 ] , & V_450 , 10 ) ;
if ( V_837 == 0 ) {
F_29 ( L_380 , V_341 ) ;
V_168 = - V_156 ;
goto exit;
}
F_29 ( L_357 , V_341 , V_837 ) ;
F_254 ( V_8 , V_856 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_341 , V_3 , V_837 ) ;
V_168 = - V_453 ;
goto exit;
}
if ( F_258 ( V_8 , V_3 , V_837 , V_64 ) == V_187 ) {
F_29 ( L_381 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
* V_241 = 0 ;
for ( V_4 = 0 ; V_4 < V_837 ; V_4 ++ )
sprintf ( V_241 , L_382 , V_241 , V_64 [ V_4 ] ) ;
} else if ( strcmp ( V_835 [ 0 ] , L_383 ) == 0 ) {
sprintf ( V_241 , L_192 ) ;
for ( V_4 = 0 ; V_4 < 512 ; V_4 += 16 ) {
sprintf ( V_241 , L_376 , V_241 , V_4 ) ;
for ( V_262 = 0 ; V_262 < 8 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_857 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_350 , V_241 ) ;
for (; V_262 < 16 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_857 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_57 , V_241 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_384 ) == 0 ) {
sprintf ( V_241 , L_192 ) ;
for ( V_4 = 512 ; V_4 < 1024 ; V_4 += 16 ) {
sprintf ( V_241 , L_376 , V_241 , V_4 ) ;
for ( V_262 = 0 ; V_262 < 8 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_857 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_350 , V_241 ) ;
for (; V_262 < 16 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_857 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_57 , V_241 ) ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_385 ) == 0 ) {
sprintf ( V_241 , L_192 ) ;
for ( V_4 = 0 ; V_4 < V_850 ; V_4 += 16 ) {
sprintf ( V_241 , L_348 , V_241 , V_4 ) ;
for ( V_262 = 0 ; V_262 < 8 ; V_262 ++ )
sprintf ( V_241 , L_349 , V_241 , V_828 -> V_858 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_350 , V_241 ) ;
for (; V_262 < 16 ; V_262 ++ )
sprintf ( V_241 , L_386 , V_241 , V_828 -> V_858 [ V_4 + V_262 ] ) ;
sprintf ( V_241 , L_57 , V_241 ) ;
}
} else {
sprintf ( V_241 , L_387 ) ;
}
exit:
F_40 ( V_64 ) ;
F_40 ( V_833 ) ;
if ( ! V_168 )
V_10 -> V_66 = strlen ( V_241 ) ;
F_246 ( V_8 , V_831 ) ;
F_245 ( V_8 , V_832 ) ;
V_8 -> V_349 . V_842 = V_841 ;
return V_168 ;
}
static int F_259 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_822 , char * V_241 )
{
struct V_7 * V_8 ;
struct V_410 * V_384 ;
struct V_825 * V_826 ;
struct V_827 * V_828 ;
T_1 V_831 = 0 , V_832 = 0 ;
T_4 V_4 , V_535 , V_536 ;
T_1 * V_859 = NULL ;
T_1 * V_860 = NULL ;
T_1 * V_861 = NULL ;
T_1 * V_862 = NULL ;
char * V_834 , * V_450 , * V_595 , * V_835 [ 3 ] = { NULL , NULL , NULL } ;
T_2 V_3 = 0 , V_837 = 0 , V_838 = 0 ;
int V_168 ;
V_8 = F_28 ( V_139 ) ;
V_384 = & V_8 -> V_384 ;
V_826 = F_249 ( V_8 ) ;
V_828 = & V_826 -> V_843 ;
V_168 = 0 ;
V_859 = F_250 ( 1024 ) ;
if ( V_859 == NULL ) {
V_168 = - V_221 ;
goto exit;
}
V_860 = F_260 ( V_844 ) ;
if ( V_860 == NULL ) {
V_168 = - V_221 ;
goto exit;
}
V_861 = F_260 ( V_850 ) ;
if ( V_861 == NULL ) {
V_168 = - V_221 ;
goto exit;
}
V_862 = F_260 ( V_854 ) ;
if ( V_862 == NULL ) {
V_168 = - V_221 ;
goto exit;
}
V_832 = V_384 -> V_845 ;
F_245 ( V_8 , V_846 ) ;
V_831 = V_384 -> V_831 ;
F_246 ( V_8 , V_847 ) ;
V_834 = V_241 ;
F_29 ( L_342 , V_341 , V_241 ) ;
V_4 = 0 ;
while ( ( V_595 = F_251 ( & V_834 , L_343 ) ) != NULL ) {
if ( V_4 > 2 )
break;
V_835 [ V_4 ] = V_595 ;
V_4 ++ ;
}
if ( strcmp ( V_835 [ 0 ] , L_388 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_168 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_450 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_168 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_168 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_341 , V_3 ) ;
F_29 ( L_357 , V_341 , V_837 ) ;
F_29 ( L_389 , V_341 , V_835 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_837 ; V_535 ++ , V_536 += 2 )
V_859 [ V_535 ] = F_147 ( V_835 [ 2 ] [ V_536 ] , V_835 [ 2 ] [ V_536 + 1 ] ) ;
F_254 ( V_8 , V_852 , V_863 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_341 , V_3 , V_837 ) ;
V_168 = - V_453 ;
goto exit;
}
if ( F_261 ( V_8 , V_3 , V_837 , V_859 ) == V_187 ) {
F_29 ( L_390 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_391 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_168 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_450 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_168 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_168 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_341 , V_3 ) ;
F_29 ( L_357 , V_341 , V_837 ) ;
F_29 ( L_392 , V_341 , V_835 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_837 ; V_535 ++ , V_536 += 2 )
V_862 [ V_535 ] = F_147 ( V_835 [ 2 ] [ V_536 ] , V_835 [ 2 ] [ V_536 + 1 ] ) ;
if ( F_255 ( V_8 , true , V_3 , V_837 , V_862 ) == V_187 ) {
F_29 ( L_369 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_365 ) == 0 ) {
if ( V_835 [ 1 ] == NULL ) {
V_168 = - V_156 ;
goto exit;
}
V_3 = V_864 ;
V_837 = strlen ( V_835 [ 1 ] ) ;
if ( V_837 % 2 ) {
V_168 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_168 = - V_156 ;
goto exit;
}
if ( V_837 > 6 ) {
F_29 ( L_393 , V_341 , V_835 [ 1 ] ) ;
V_168 = - V_453 ;
goto exit;
}
F_29 ( L_379 , V_341 , V_3 ) ;
F_29 ( L_357 , V_341 , V_837 ) ;
F_29 ( L_394 , V_341 , V_835 [ 1 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_837 ; V_535 ++ , V_536 += 2 )
V_859 [ V_535 ] = F_147 ( V_835 [ 1 ] [ V_536 ] , V_835 [ 1 ] [ V_536 + 1 ] ) ;
F_254 ( V_8 , V_852 , V_863 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_341 , V_3 , V_837 ) ;
V_168 = - V_453 ;
goto exit;
}
if ( F_261 ( V_8 , V_3 , V_837 , V_859 ) == V_187 ) {
F_29 ( L_390 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_368 ) == 0 ) {
if ( V_835 [ 1 ] == NULL ) {
V_168 = - V_156 ;
goto exit;
}
V_3 = V_865 ;
V_837 = strlen ( V_835 [ 1 ] ) ;
if ( V_837 % 2 ) {
V_168 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_168 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_341 , V_3 ) ;
F_29 ( L_357 , V_341 , V_837 ) ;
F_29 ( L_395 , V_341 , V_835 [ 1 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_837 ; V_535 ++ , V_536 += 2 )
V_859 [ V_535 ] = F_147 ( V_835 [ 1 ] [ V_536 ] , V_835 [ 1 ] [ V_536 + 1 ] ) ;
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_341 , V_3 , V_837 ) ;
V_168 = - V_453 ;
goto exit;
}
if ( F_261 ( V_8 , V_3 , V_837 , V_859 ) == V_187 ) {
F_29 ( L_390 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_396 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_168 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_450 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_168 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_168 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_341 , V_3 ) ;
F_29 ( L_357 , V_341 , V_837 ) ;
F_29 ( L_397 , V_341 , V_835 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_837 ; V_535 ++ , V_536 += 2 )
V_859 [ V_535 ] = F_147 ( V_835 [ 2 ] [ V_536 ] , V_835 [ 2 ] [ V_536 + 1 ] ) ;
F_254 ( V_8 , V_856 , V_853 , ( void * ) & V_838 , false ) ;
if ( ( V_3 + V_837 ) > V_838 ) {
F_29 ( L_358 , V_341 , V_3 , V_837 ) ;
V_168 = - V_453 ;
goto exit;
}
if ( F_262 ( V_8 , V_3 , V_837 , V_859 ) == V_187 ) {
F_29 ( L_398 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_399 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_168 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_450 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_168 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_168 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_341 , V_3 ) ;
F_29 ( L_357 , V_341 , V_837 ) ;
F_29 ( L_400 , V_341 , V_835 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_837 ; V_535 ++ , V_536 += 2 )
V_828 -> V_857 [ V_3 + V_535 ] = F_147 ( V_835 [ 2 ] [ V_536 ] , V_835 [ 2 ] [ V_536 + 1 ] ) ;
} else if ( strcmp ( V_835 [ 0 ] , L_401 ) == 0 ) {
if ( F_258 ( V_8 , 0 , V_844 , V_828 -> V_857 ) == V_223 ) {
F_29 ( L_402 , V_341 ) ;
} else {
F_29 ( L_403 , V_341 ) ;
V_168 = - V_453 ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_404 ) == 0 ) {
if ( F_252 ( V_8 , 0 , V_844 , V_828 -> V_858 ) == V_223 ) {
F_29 ( L_402 , V_341 ) ;
} else {
F_29 ( L_405 , V_341 ) ;
V_168 = - V_453 ;
}
} else if ( strcmp ( V_835 [ 0 ] , L_406 ) == 0 ) {
memcpy ( V_828 -> V_866 , V_828 -> V_857 , V_844 ) ;
F_254 ( V_8 , V_856 , V_853 , ( void * ) & V_838 , false ) ;
if ( V_838 < 1 ) {
V_168 = - V_453 ;
goto exit;
}
if ( F_262 ( V_8 , 0x00 , V_844 , V_828 -> V_857 ) == V_187 ) {
F_29 ( L_407 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_408 ) == 0 ) {
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( V_838 < 1 ) {
V_168 = - V_453 ;
goto exit;
}
if ( F_261 ( V_8 , 0x00 , V_867 , V_828 -> V_858 ) == V_187 ) {
F_29 ( L_409 , V_341 ) ;
V_168 = - V_453 ;
goto exit;
}
} else if ( strcmp ( V_835 [ 0 ] , L_410 ) == 0 ) {
if ( ( V_835 [ 1 ] == NULL ) || ( V_835 [ 2 ] == NULL ) ) {
V_168 = - V_156 ;
goto exit;
}
V_3 = F_253 ( V_835 [ 1 ] , & V_450 , 16 ) ;
V_3 &= 0xFFF ;
V_837 = strlen ( V_835 [ 2 ] ) ;
if ( V_837 % 2 ) {
V_168 = - V_156 ;
goto exit;
}
V_837 /= 2 ;
if ( V_837 == 0 ) {
V_168 = - V_156 ;
goto exit;
}
F_29 ( L_379 , V_341 , V_3 ) ;
F_29 ( L_357 , V_341 , V_837 ) ;
F_29 ( L_411 , V_341 , V_835 [ 2 ] ) ;
for ( V_535 = 0 , V_536 = 0 ; V_535 < V_837 ; V_535 ++ , V_536 += 2 )
V_828 -> V_858 [ V_3 + V_535 ] = F_147 ( V_835 [ 2 ] [ V_536 ] , V_835 [ 2 ] [ V_536 + 1 ] ) ;
}
exit:
F_40 ( V_859 ) ;
F_40 ( V_860 ) ;
F_40 ( V_861 ) ;
F_40 ( V_862 ) ;
F_246 ( V_8 , V_831 ) ;
F_245 ( V_8 , V_832 ) ;
return V_168 ;
}
static int F_263 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
char * V_834 , * V_868 , * V_450 ;
char * V_869 ;
char V_467 ;
T_4 V_3 , V_64 ;
int V_140 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_834 = V_241 ;
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
V_3 = F_253 ( V_834 , & V_450 , 16 ) ;
if ( V_3 > 0x3FFF )
return - V_156 ;
V_834 = V_868 + 1 ;
if ( ( V_834 - V_241 ) >= V_10 -> V_66 )
return - V_156 ;
V_64 = F_253 ( V_834 , & V_450 , 16 ) ;
V_140 = 0 ;
V_467 = V_869 [ 0 ] ;
switch ( V_467 ) {
case 'b' :
if ( V_64 > 0xFF ) {
V_140 = - V_156 ;
break;
}
F_110 ( V_8 , V_3 , V_64 ) ;
break;
case 'w' :
if ( V_64 > 0xFFFF ) {
V_140 = - V_156 ;
break;
}
F_111 ( V_8 , V_3 , V_64 ) ;
break;
case 'd' :
F_112 ( V_8 , V_3 , V_64 ) ;
break;
default:
V_140 = - V_156 ;
break;
}
return V_140 ;
}
static int F_264 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
char * V_834 , * V_868 , * V_450 ;
char * V_869 ;
char V_467 ;
char V_64 [ 20 ] , V_835 [ 20 ] ;
T_4 V_3 ;
T_4 V_140 , V_4 = 0 , V_262 = 0 , V_872 = 0 ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
F_4 ( V_64 , 0 , 20 ) ;
F_4 ( V_835 , 0 , 20 ) ;
F_4 ( V_241 , 0 , V_10 -> V_66 ) ;
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
V_3 = F_253 ( V_834 , & V_450 , 16 ) ;
if ( V_3 > 0x3FFF )
return - V_156 ;
V_140 = 0 ;
V_467 = V_869 [ 0 ] ;
switch ( V_467 ) {
case 'b' :
sprintf ( V_241 , L_413 , F_106 ( V_8 , V_3 ) ) ;
V_10 -> V_66 = strlen ( V_241 ) ;
break;
case 'w' :
sprintf ( V_64 , L_414 , F_107 ( V_8 , V_3 ) ) ;
for ( V_4 = 0 ; V_4 <= strlen ( V_64 ) ; V_4 ++ ) {
if ( V_4 % 2 == 0 ) {
V_835 [ V_262 ] = ' ' ;
V_262 ++ ;
}
if ( V_64 [ V_4 ] != '\0' )
V_835 [ V_262 ] = V_64 [ V_4 ] ;
V_262 ++ ;
}
V_834 = V_835 ;
F_29 ( L_415 , V_834 ) ;
while ( * V_834 != '\0' ) {
V_868 = strpbrk ( V_834 , L_416 ) ;
if ( ! V_868 )
break;
V_868 ++ ;
if ( * V_868 != '\0' ) {
V_872 = F_253 ( V_868 , & V_450 , 16 ) ;
sprintf ( V_241 , L_417 , V_241 , V_872 ) ;
} else {
break;
}
V_834 = V_868 ;
}
V_10 -> V_66 = 6 ;
break;
case 'd' :
sprintf ( V_64 , L_418 , F_108 ( V_8 , V_3 ) ) ;
for ( V_4 = 0 ; V_4 <= strlen ( V_64 ) ; V_4 ++ ) {
if ( V_4 % 2 == 0 ) {
V_835 [ V_262 ] = ' ' ;
V_262 ++ ;
}
if ( V_64 [ V_4 ] != '\0' )
V_835 [ V_262 ] = V_64 [ V_4 ] ;
V_262 ++ ;
}
V_834 = V_835 ;
F_29 ( L_415 , V_834 ) ;
while ( * V_834 != '\0' ) {
V_868 = strpbrk ( V_834 , L_416 ) ;
if ( ! V_868 )
break;
V_868 ++ ;
if ( * V_868 != '\0' ) {
V_872 = F_253 ( V_868 , & V_450 , 16 ) ;
sprintf ( V_241 , L_417 , V_241 , V_872 ) ;
} else {
break;
}
V_834 = V_868 ;
}
V_10 -> V_66 = strlen ( V_241 ) ;
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
struct V_407 * V_10 , char * V_241 )
{
T_4 V_455 , V_3 , V_64 ;
int V_140 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_140 = sscanf ( V_241 , L_97 , & V_455 , & V_3 , & V_64 ) ;
if ( V_140 < 3 )
return - V_156 ;
if ( V_455 >= V_873 )
return - V_156 ;
if ( V_3 > 0xFF )
return - V_156 ;
if ( V_64 > 0xFFFFF )
return - V_156 ;
F_4 ( V_241 , 0 , V_10 -> V_66 ) ;
F_267 ( V_8 , V_455 , V_3 , V_64 ) ;
sprintf ( V_241 , L_419 ) ;
V_10 -> V_66 = strlen ( V_241 ) ;
return 0 ;
}
static int F_268 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
char * V_834 , * V_868 , * V_450 ;
char V_64 [ 20 ] , V_835 [ 20 ] ;
T_4 V_455 , V_3 ;
T_4 V_140 , V_4 = 0 , V_262 = 0 , V_874 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
V_140 = sscanf ( V_870 , L_91 , & V_455 , & V_3 ) ;
F_40 ( V_870 ) ;
if ( V_140 < 2 )
return - V_156 ;
if ( V_455 >= V_873 )
return - V_156 ;
if ( V_3 > 0xFF )
return - V_156 ;
F_4 ( V_241 , 0 , V_10 -> V_66 ) ;
sprintf ( V_64 , L_418 , F_269 ( V_8 , V_455 , V_3 ) ) ;
for ( V_4 = 0 ; V_4 <= strlen ( V_64 ) ; V_4 ++ ) {
if ( V_4 % 2 == 0 ) {
V_835 [ V_262 ] = ' ' ;
V_262 ++ ;
}
V_835 [ V_262 ] = V_64 [ V_4 ] ;
V_262 ++ ;
}
V_834 = V_835 ;
F_29 ( L_415 , V_834 ) ;
while ( * V_834 != '\0' ) {
V_868 = strpbrk ( V_834 , L_416 ) ;
V_868 ++ ;
if ( * V_868 != '\0' ) {
V_874 = F_253 ( V_868 , & V_450 , 16 ) ;
sprintf ( V_241 , L_417 , V_241 , V_874 ) ;
} else {
break;
}
V_834 = V_868 ;
}
V_10 -> V_66 = strlen ( V_241 ) ;
return 0 ;
}
static int F_270 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 -> V_349 . V_350 == 0 ) {
V_8 -> V_349 . V_350 = 1 ;
F_246 ( V_8 , V_847 ) ;
F_98 ( V_8 ) ;
F_271 ( V_8 , 1 ) ;
}
if ( V_8 -> V_349 . V_350 == 0 )
return - V_251 ;
if ( V_8 -> V_875 . V_86 == V_876 ) {
if ( F_272 ( V_8 ) == V_187 )
return - V_251 ;
V_8 -> V_875 . V_86 = V_877 ;
}
return 0 ;
}
static int F_273 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 -> V_349 . V_350 == 1 ) {
F_274 ( V_8 ) ;
V_8 -> V_349 . V_350 = 0 ;
}
if ( V_8 -> V_875 . V_86 != V_876 ) {
F_275 ( V_8 ) ;
V_8 -> V_875 . V_86 = V_876 ;
}
return 0 ;
}
static int F_276 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_4 V_41 = V_878 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
V_41 = F_277 ( V_870 ) ;
sprintf ( V_241 , L_420 , V_41 ) ;
F_40 ( V_870 ) ;
if ( V_41 <= 0x7f )
V_41 = F_278 ( ( T_1 ) V_41 ) ;
else
V_41 = ( V_41 - 0x80 + V_879 ) ;
if ( V_41 >= V_880 )
return - V_156 ;
V_8 -> V_875 . V_881 = V_41 ;
F_279 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_241 ) + 1 ;
return 0 ;
}
static int F_280 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
T_4 V_516 = 1 ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
V_516 = F_277 ( V_870 ) ;
sprintf ( V_241 , L_421 , V_8 -> V_875 . V_516 , V_516 ) ;
V_8 -> V_875 . V_516 = V_516 ;
F_281 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_241 ) + 1 ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_282 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_4 V_882 = 0 , V_883 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
int V_451 ;
V_451 = sscanf ( V_241 , L_422 , & V_882 , & V_883 ) ;
if ( V_451 != 2 )
return - V_156 ;
if ( V_882 != V_884 )
V_882 = V_523 ;
V_8 -> V_875 . V_882 = ( T_1 ) V_882 ;
V_8 -> V_875 . V_885 = V_883 ;
F_283 ( V_8 ) ;
return 0 ;
}
static int F_284 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_4 V_886 = 0 , V_887 = 0 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
int V_451 ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
V_451 = sscanf ( V_870 , L_423 , & V_886 , & V_887 ) ;
if ( V_451 != 2 ) {
F_40 ( V_870 ) ;
return - V_156 ;
}
sprintf ( V_241 , L_424 , V_886 , V_887 ) ;
V_8 -> V_875 . V_888 = ( T_1 ) V_886 ;
V_8 -> V_875 . V_889 = ( T_1 ) V_887 ;
V_8 -> V_875 . V_890 = 1 ;
F_285 ( V_8 ) ;
V_10 -> V_66 = strlen ( V_241 ) + 1 ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_286 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_1 V_4 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
T_2 V_891 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
sprintf ( V_241 , L_425 , V_870 ) ;
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
V_10 -> V_66 = strlen ( V_241 ) + 1 ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_288 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_1 V_4 ;
T_2 V_891 = 0 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
F_4 ( V_241 , 0 , V_10 -> V_66 ) ;
sprintf ( V_241 , L_426 , V_870 ) ;
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
V_10 -> V_66 = strlen ( V_241 ) ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_289 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_4 V_896 = 1 , V_897 = 1 , V_898 = 1 , V_899 = 1 , V_900 = 1 , V_901 = 1 , V_31 = 1 ;
T_4 V_902 = 1 ;
T_4 V_903 = 0 ;
int V_451 ;
struct V_904 * V_905 ;
struct V_906 * V_907 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_905 = & V_8 -> V_875 ;
if ( F_105 ( V_241 , V_10 -> V_452 , V_10 -> V_66 ) )
return - V_453 ;
F_29 ( L_342 , V_341 , V_241 ) ;
V_897 = strncmp ( V_241 , L_427 , 6 ) ;
V_898 = strncmp ( V_241 , L_428 , 20 ) ;
V_899 = strncmp ( V_241 , L_429 , 20 ) ;
V_900 = strncmp ( V_241 , L_430 , 20 ) ;
V_901 = strncmp ( V_241 , L_431 , 20 ) ;
V_896 = strncmp ( V_241 , L_432 , 20 ) ;
V_31 = strncmp ( V_241 , L_433 , 4 ) ;
V_451 = sscanf ( V_241 , L_434 , & V_903 ) ;
if ( V_451 != 2 )
return - V_156 ;
F_4 ( V_241 , '\0' , sizeof( * V_241 ) ) ;
if ( V_31 == 0 ) {
V_902 = 0 ;
V_905 -> V_908 . V_31 = 1 ;
sprintf ( V_241 , L_435 ) ;
} else {
V_902 = 1 ;
if ( V_905 -> V_86 != V_877 ) {
if ( V_905 -> V_908 . V_31 != 1 ) {
F_29 ( L_436 , V_341 , V_905 -> V_86 ) ;
return - V_453 ;
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
sprintf ( V_241 , L_435 ) ;
} else if ( V_905 -> V_908 . V_31 == 1 ) {
sprintf ( V_241 , L_437 , V_903 ) ;
V_905 -> V_908 . V_31 = 0 ;
V_905 -> V_908 . V_903 = V_903 ;
V_905 -> V_908 . V_914 = 2 ;
V_907 = & V_905 -> V_908 . V_915 ;
V_907 -> V_916 = 1500 ;
F_4 ( V_907 -> V_917 , 0xFF , V_23 ) ;
F_290 ( V_8 ) ;
} else {
return - V_453 ;
}
V_10 -> V_66 = strlen ( V_241 ) ;
return 0 ;
case V_910 :
if ( V_902 != 0 )
sprintf ( V_241 , L_438 ) ;
F_291 ( V_8 , ( T_1 ) V_902 ) ;
break;
case V_911 :
if ( V_902 != 0 )
sprintf ( V_241 , L_438 ) ;
F_292 ( V_8 , ( T_1 ) V_902 ) ;
break;
case V_912 :
if ( V_902 != 0 ) {
if ( V_905 -> V_881 <= V_918 ) {
sprintf ( V_241 , L_438 ) ;
F_293 ( V_8 , ( T_1 ) V_902 ) ;
} else {
sprintf ( V_241 , L_439 ) ;
}
}
break;
case V_913 :
if ( V_902 != 0 )
sprintf ( V_241 , L_438 ) ;
F_294 ( V_8 , ( T_1 ) V_902 ) ;
break;
default:
sprintf ( V_241 , L_440 ) ;
return - V_453 ;
}
if ( V_902 == 1 && V_905 -> V_86 != V_877 ) {
struct V_904 * V_905 = & V_8 -> V_875 ;
if ( V_905 -> V_908 . V_31 == 0 ) {
V_905 -> V_908 . V_31 = 1 ;
F_78 ( 5 ) ;
}
V_905 -> V_908 . V_31 = 0 ;
V_905 -> V_908 . V_903 = 1 ;
F_290 ( V_8 ) ;
} else {
V_905 -> V_86 = V_877 ;
}
V_10 -> V_66 = strlen ( V_241 ) ;
return 0 ;
}
static int F_295 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_1 V_919 = 0 , V_920 = 0 , V_921 ;
T_4 V_922 = 0 , V_923 = 0 , V_924 = 0 , V_925 = 0 , V_926 = 0 , V_927 = 0 , V_928 = 0 , V_929 = 0 ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
F_29 ( L_441 , V_341 , V_870 ) ;
V_919 = ( strncmp ( V_870 , L_442 , 5 ) == 0 ) ? 1 : 0 ;
V_920 = ( strncmp ( V_870 , L_433 , 4 ) == 0 ) ? 1 : 0 ;
V_921 = ( strncmp ( V_870 , L_443 , 3 ) == 0 ) ? 1 : 0 ;
if ( V_919 ) {
sprintf ( V_241 , L_442 ) ;
F_296 ( V_8 , V_919 ) ;
} else if ( V_920 ) {
F_296 ( V_8 , 0 ) ;
sprintf ( V_241 , L_444 , V_8 -> V_875 . V_930 , V_8 -> V_875 . V_931 ) ;
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
V_929 = ( F_106 ( V_8 , 0xa5b ) << 8 ) | ( F_106 ( V_8 , 0xa5c ) ) ;
sprintf ( V_241 , L_445 , V_922 + V_924 + V_926 , V_923 + V_925 + V_927 , V_928 + V_929 ) ;
}
V_10 -> V_66 = strlen ( V_241 ) + 1 ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_298 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_4 V_932 , V_933 , V_934 , V_935 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_932 = V_8 -> V_875 . V_908 . V_936 ;
V_933 = 0 ;
V_934 = V_8 -> V_875 . V_930 ;
V_935 = V_8 -> V_875 . V_931 ;
F_4 ( V_241 , '\0' , 128 ) ;
sprintf ( V_241 , L_446 , V_932 , V_933 , V_934 , V_935 ) ;
V_10 -> V_66 = strlen ( V_241 ) + 1 ;
return 0 ;
}
static int F_299 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_1 V_677 ;
T_4 V_937 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
int V_140 = 0 ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
V_140 = - V_453 ;
goto exit;
}
F_4 ( V_241 , 0 , V_10 -> V_66 ) ;
V_677 = 1 ;
if ( V_10 -> V_66 > 1 ) {
if ( strncmp ( V_870 , L_433 , 4 ) == 0 ) {
V_677 = 0 ;
sprintf ( V_241 , L_447 ) ;
} else if ( sscanf ( V_870 , L_448 , & V_937 ) ) {
V_140 = F_300 ( V_8 , ( T_1 ) V_937 ) ;
if ( V_140 == V_187 ) {
V_140 = - V_251 ;
goto exit;
}
sprintf ( V_241 , L_449 , V_937 ) ;
} else {
V_140 = - V_156 ;
goto exit;
}
}
V_140 = F_301 ( V_8 , V_677 ) ;
if ( V_140 == V_187 ) {
V_140 = - V_251 ;
goto exit;
}
V_10 -> V_66 = strlen ( V_241 ) ;
exit:
F_40 ( V_870 ) ;
return V_140 ;
}
static int F_302 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
strcpy ( V_241 , V_870 ) ;
V_10 -> V_66 = F_303 ( V_8 , V_241 ) ;
F_40 ( V_870 ) ;
return 0 ;
}
static int F_304 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_1 V_286 ;
T_2 V_938 = 1 ;
T_2 V_3 = V_939 ;
T_2 V_116 = 1 ;
T_2 V_838 = 0 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( F_105 ( V_241 , V_10 -> V_452 , V_10 -> V_66 ) )
return - V_453 ;
V_938 = strncmp ( V_241 , L_450 , 6 ) ;
F_305 ( V_8 , & V_286 ) ;
if ( V_938 == 0 ) {
F_254 ( V_8 , V_852 , V_853 , ( void * ) & V_838 , false ) ;
if ( 2 > V_838 ) {
F_29 ( L_451 ) ;
return - V_453 ;
}
if ( F_261 ( V_8 , V_3 , V_116 , & V_286 ) == V_187 ) {
F_29 ( L_452 ) ;
return - V_453 ;
} else {
sprintf ( V_241 , L_453 , V_286 ) ;
}
} else {
sprintf ( V_241 , L_454 , V_286 ) ;
}
V_10 -> V_66 = strlen ( V_241 ) ;
return 0 ;
}
static int F_306 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
struct V_904 * V_905 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
V_905 = & V_8 -> V_875 ;
V_905 -> V_908 . V_936 = 0 ;
V_905 -> V_940 = 0 ;
V_905 -> V_930 = 0 ;
V_905 -> V_931 = 0 ;
F_307 ( V_8 , 0xf14 , V_941 , 0x1 ) ;
F_78 ( 10 ) ;
F_307 ( V_8 , 0xf14 , V_941 , 0x0 ) ;
return 0 ;
}
static int F_308 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
T_4 V_104 ;
T_1 V_632 , V_633 = 0 ;
T_4 V_4 , V_262 = 1 , V_455 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( strncmp ( V_241 , L_455 , 4 ) == 0 ) {
F_29 ( L_189 ) ;
for ( V_4 = 0x0 ; V_4 < 0x300 ; V_4 += 4 ) {
if ( V_262 % 4 == 1 )
F_29 ( L_190 , V_4 ) ;
F_29 ( L_191 , F_108 ( V_8 , V_4 ) ) ;
if ( ( V_262 ++ ) % 4 == 0 )
F_29 ( L_192 ) ;
}
for ( V_4 = 0x400 ; V_4 < 0x1000 ; V_4 += 4 ) {
if ( V_262 % 4 == 1 )
F_29 ( L_190 , V_4 ) ;
F_29 ( L_191 , F_108 ( V_8 , V_4 ) ) ;
if ( ( V_262 ++ ) % 4 == 0 )
F_29 ( L_192 ) ;
}
V_262 = 1 ;
F_189 ( V_8 , V_634 , ( T_1 * ) ( & V_632 ) ) ;
F_29 ( L_194 ) ;
if ( ( V_635 == V_632 ) || ( V_636 == V_632 ) )
V_633 = 1 ;
else
V_633 = 2 ;
for ( V_455 = 0 ; V_455 < V_633 ; V_455 ++ ) {
for ( V_4 = 0 ; V_4 < 0x34 ; V_4 ++ ) {
V_104 = F_114 ( V_8 , V_455 , V_4 , 0xffffffff ) ;
if ( V_262 % 4 == 1 )
F_29 ( L_196 , V_4 ) ;
F_29 ( L_191 , V_104 ) ;
if ( ( V_262 ++ ) % 4 == 0 )
F_29 ( L_192 ) ;
}
}
}
return 0 ;
}
static int F_309 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
struct V_407 * V_10 , char * V_241 )
{
char * V_870 = F_265 ( V_10 -> V_66 , V_871 ) ;
T_4 V_942 ;
int V_451 ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_452 , V_10 -> V_66 ) ) {
F_40 ( V_870 ) ;
return - V_453 ;
}
F_29 ( L_456 , V_341 , V_870 ) ;
V_451 = sscanf ( V_870 , L_457 , & V_942 ) ;
if ( V_451 != 1 ) {
F_40 ( V_870 ) ;
return - V_156 ;
}
F_40 ( V_870 ) ;
return 0 ;
}
static int F_310 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_64 . V_66 , V_871 ) ;
T_1 V_943 = 1 , V_944 = 1 ;
int V_140 = 0 ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_64 . V_452 , V_10 -> V_64 . V_66 ) ) {
V_140 = - V_453 ;
goto exit;
}
F_29 ( L_456 , V_341 , V_870 ) ;
V_943 = strncmp ( V_870 , L_183 , 2 ) ;
V_944 = strncmp ( V_870 , L_458 , 3 ) ;
if ( V_943 == 0 ) {
F_311 ( V_8 , true ) ;
F_29 ( L_459 , V_341 ) ;
} else if ( V_944 == 0 ) {
F_311 ( V_8 , false ) ;
F_29 ( L_460 , V_341 ) ;
}
exit:
F_40 ( V_870 ) ;
return V_140 ;
}
static int F_312 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
struct V_7 * V_8 = F_28 ( V_139 ) ;
char * V_870 = F_265 ( V_10 -> V_64 . V_66 , V_871 ) ;
T_1 V_945 = 1 ;
struct V_823 * V_824 = F_248 ( V_8 ) ;
int V_140 = 0 ;
if ( ! V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_10 -> V_64 . V_452 , V_10 -> V_64 . V_66 ) ) {
V_140 = - V_453 ;
goto exit;
}
F_29 ( L_456 , V_341 , V_870 ) ;
V_945 = strncmp ( V_870 , L_461 , 8 ) ;
if ( V_945 == 0 ) {
F_29 ( L_462 , V_341 ) ;
if ( V_824 -> V_946 )
sprintf ( V_241 , L_463 ) ;
else
sprintf ( V_241 , L_464 ) ;
}
V_10 -> V_64 . V_66 = strlen ( V_241 ) + 1 ;
exit:
F_40 ( V_870 ) ;
return V_140 ;
}
static int F_313 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_822 , char * V_241 )
{
struct V_407 * V_10 = (struct V_407 * ) V_822 ;
T_4 V_947 = V_10 -> V_65 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 == NULL )
return - V_948 ;
if ( V_241 == NULL ) {
V_10 -> V_66 = 0 ;
return - V_949 ;
}
switch ( V_947 ) {
case V_465 :
F_29 ( L_465 ) ;
F_270 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_950 :
F_29 ( L_466 ) ;
F_273 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_951 :
F_29 ( L_467 ) ;
F_282 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_952 :
F_29 ( L_468 ) ;
F_306 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_953 :
F_29 ( L_469 ) ;
F_310 ( V_139 , V_27 , V_822 , V_241 ) ;
break;
case V_954 :
F_29 ( L_470 ) ;
F_179 ( V_139 , V_27 , V_822 , V_241 ) ;
break;
}
return 0 ;
}
static int F_314 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_822 , char * V_241 )
{
struct V_407 * V_10 = (struct V_407 * ) V_822 ;
T_4 V_947 = V_10 -> V_65 ;
struct V_7 * V_8 = F_28 ( V_139 ) ;
if ( V_8 == NULL )
return - V_948 ;
if ( V_241 == NULL ) {
V_10 -> V_66 = 0 ;
return - V_949 ;
}
switch ( V_947 ) {
case V_468 :
F_263 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_955 :
F_266 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_956 :
F_29 ( L_471 ) ;
F_309 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_957 :
F_29 ( L_472 ) ;
F_280 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_466 :
F_29 ( L_473 ) ;
F_264 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_958 :
F_29 ( L_474 ) ;
F_268 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_959 :
F_29 ( L_475 ) ;
F_276 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_960 :
F_29 ( L_476 ) ;
F_284 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_961 :
F_29 ( L_477 ) ;
F_286 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_962 :
F_29 ( L_478 ) ;
F_288 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_963 :
F_298 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_964 :
F_29 ( L_479 ) ;
F_289 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_965 :
F_29 ( L_480 ) ;
F_295 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_966 :
F_29 ( L_481 ) ;
F_247 ( V_139 , V_27 , V_822 , V_241 ) ;
break;
case V_967 :
F_29 ( L_482 ) ;
F_308 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_968 :
F_29 ( L_483 ) ;
F_302 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_969 :
F_29 ( L_484 ) ;
F_304 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_970 :
F_29 ( L_485 ) ;
F_312 ( V_139 , V_27 , V_822 , V_241 ) ;
break;
case V_971 :
F_29 ( L_486 ) ;
F_299 ( V_139 , V_27 , V_10 , V_241 ) ;
break;
case V_972 :
F_29 ( L_487 ) ;
F_259 ( V_139 , V_27 , V_822 , V_241 ) ;
break;
}
F_78 ( 10 ) ;
return 0 ;
}
static int F_315 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
return 0 ;
}
static int F_316 ( struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
return 0 ;
}
static int F_317 (
struct V_138 * V_139 ,
struct V_26 * V_27 ,
union V_9 * V_10 , char * V_241 )
{
T_4 V_362 ;
T_1 * V_502 , * V_834 ;
char * V_450 ;
T_1 * V_973 = L_343 ;
F_29 ( L_488 , V_341 ) ;
V_362 = V_10 -> V_64 . V_66 ;
V_502 = ( T_1 * ) F_43 ( V_362 ) ;
if ( V_502 == NULL ) {
F_29 ( L_489 , V_341 ) ;
return - V_221 ;
}
if ( F_105 ( V_502 , V_10 -> V_64 . V_452 , V_362 ) ) {
F_40 ( V_502 ) ;
F_29 ( L_490 , V_341 ) ;
return - V_453 ;
}
F_29 ( L_491 , V_341 , V_502 ) ;
V_450 = ( char * ) V_502 ;
V_834 = F_251 ( & V_450 , V_973 ) ;
if ( ( V_834 == NULL ) || ( strlen ( V_834 ) == 0 ) ) {
F_40 ( V_502 ) ;
F_29 ( L_492 , V_341 ) ;
return - V_453 ;
}
F_40 ( V_502 ) ;
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
int V_168 = 0 ;
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
T_8 V_362 ;
T_1 * V_241 = NULL ;
T_4 V_994 = 0 ;
int V_451 ;
T_8 V_995 ;
const T_10 * V_996 ;
const struct V_997 * V_998 ;
T_4 V_999 ;
T_10 V_490 ;
int V_322 ;
int V_947 = 0 ;
int V_464 = 0 ;
union V_9 V_822 ;
memcpy ( & V_822 , V_985 , sizeof( V_822 ) ) ;
V_986 = V_822 . V_64 . V_66 ;
V_870 = F_43 ( V_986 ) ;
if ( NULL == V_870 )
return - V_221 ;
if ( F_105 ( V_870 , V_822 . V_64 . V_452 , V_986 ) ) {
V_168 = - V_453 ;
goto exit;
}
V_991 = V_870 ;
V_362 = V_986 ;
V_451 = sscanf ( V_991 , L_493 , V_992 ) ;
if ( V_451 != 1 ) {
V_168 = - V_156 ;
goto exit;
}
V_993 = strlen ( V_992 ) ;
F_29 ( L_494 , V_341 , V_992 ) ;
if ( V_993 > 0 )
V_993 += 1 ;
V_991 += V_993 ;
V_362 -= V_993 ;
F_29 ( L_495 , V_341 , V_991 ) ;
V_996 = V_1000 ;
V_998 = V_1001 ;
V_999 = sizeof( V_1001 ) / sizeof( struct V_997 ) ;
if ( V_999 == 0 ) {
V_168 = - V_188 ;
goto exit;
}
V_995 = - 1 ;
while ( ( ++ V_995 < V_999 ) && strcmp ( V_998 [ V_995 ] . V_78 , V_992 ) ) ;
if ( V_995 == V_999 ) {
V_168 = - V_188 ;
goto exit;
}
if ( V_998 [ V_995 ] . V_60 < V_1002 ) {
int V_262 = - 1 ;
while ( ( ++ V_262 < V_999 ) && ( ( V_998 [ V_262 ] . V_78 [ 0 ] != '\0' ) ||
( V_998 [ V_262 ] . V_1003 != V_998 [ V_995 ] . V_1003 ) ||
( V_998 [ V_262 ] . V_1004 != V_998 [ V_995 ] . V_1004 ) ) ) ;
if ( V_262 == V_999 ) {
V_168 = - V_156 ;
goto exit;
}
V_947 = V_998 [ V_995 ] . V_60 ;
V_464 = sizeof( V_1005 ) ;
V_995 = V_262 ;
}
V_989 = F_43 ( 4096 ) ;
if ( NULL == V_989 ) {
V_168 = - V_221 ;
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
sscanf ( V_1006 , L_496 , & V_322 ) ;
V_989 [ V_903 ++ ] = ( T_1 ) V_322 ;
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
sscanf ( V_1006 , L_496 , & V_322 ) ;
( ( T_8 * ) V_989 ) [ V_903 ++ ] = ( T_8 ) V_322 ;
} while ( 1 );
V_990 = V_903 * sizeof( T_8 ) ;
V_822 . V_64 . V_66 = V_903 ;
if ( V_822 . V_64 . V_66 > ( V_998 [ V_995 ] . V_1003 & V_982 ) )
V_822 . V_64 . V_66 = V_998 [ V_995 ] . V_1003 & V_982 ;
break;
case V_1009 :
if ( V_362 > 0 ) {
V_822 . V_64 . V_66 = V_362 ;
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
F_29 ( L_497 , V_341 ) ;
V_168 = - 1 ;
goto exit;
}
if ( ( V_998 [ V_995 ] . V_1003 & V_1010 ) &&
( V_822 . V_64 . V_66 != ( V_998 [ V_995 ] . V_1003 & V_982 ) ) ) {
F_29 ( L_498 ,
V_341 , V_992 , V_998 [ V_995 ] . V_1003 & V_982 ) ;
V_168 = - V_156 ;
goto exit;
}
} else {
V_822 . V_64 . V_66 = 0L ;
}
if ( ( V_998 [ V_995 ] . V_1003 & V_1010 ) &&
( ( F_319 ( V_998 [ V_995 ] . V_1003 ) + V_464 ) <= V_79 ) ) {
if ( V_464 )
V_822 . V_86 = V_947 ;
memcpy ( V_822 . V_78 + V_464 , V_989 , V_79 - V_464 ) ;
} else {
if ( ( V_998 [ V_995 ] . V_1003 == 0 ) &&
( V_998 [ V_995 ] . V_1004 & V_1010 ) &&
( F_319 ( V_998 [ V_995 ] . V_1004 ) <= V_79 ) ) {
if ( V_464 )
V_822 . V_86 = V_947 ;
} else {
if ( F_131 ( V_822 . V_64 . V_452 , V_989 , V_990 ) ) {
V_168 = - V_453 ;
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
( ( V_994 + V_464 ) <= V_79 ) )
V_994 = 0 ;
} else {
V_994 = F_319 ( V_998 [ V_995 ] . V_1004 ) ;
if ( ( V_998 [ V_995 ] . V_1004 & V_1010 ) &&
( V_994 <= V_79 ) )
V_994 = 0 ;
}
if ( V_994 == 0 ) {
V_241 = ( T_1 * ) & V_822 ;
F_40 ( V_989 ) ;
V_989 = NULL ;
} else {
V_241 = V_989 ;
}
V_490 = V_996 [ V_998 [ V_995 ] . V_60 - V_1011 ] ;
V_168 = V_490 ( V_139 , NULL , & V_822 , V_241 ) ;
if ( ( V_998 [ V_995 ] . V_1004 & V_983 ) &&
( V_998 [ V_995 ] . V_1004 & V_982 ) ) {
int V_262 ;
int V_1012 = 0 ;
T_1 V_1006 [ 20 ] = { 0 } ;
if ( ( V_998 [ V_995 ] . V_1004 & V_1010 ) &&
( F_319 ( V_998 [ V_995 ] . V_1004 ) <= V_79 ) )
V_1012 = V_998 [ V_995 ] . V_1004 & V_982 ;
else
V_1012 = V_822 . V_64 . V_66 ;
V_987 = F_43 ( 4096 ) ;
if ( NULL == V_987 ) {
V_168 = - V_221 ;
goto exit;
}
switch ( V_998 [ V_995 ] . V_1004 & V_983 ) {
case V_1007 :
for ( V_262 = 0 ; V_262 < V_1012 ; V_262 ++ ) {
sprintf ( V_1006 , L_499 , V_241 [ V_262 ] ) ;
V_362 = strlen ( V_1006 ) ;
V_988 = strlen ( V_987 ) ;
if ( ( V_988 + V_362 + 1 ) > 4096 ) {
V_168 = - V_387 ;
goto exit;
}
memcpy ( V_987 + V_988 , V_1006 , V_362 ) ;
}
break;
case V_1008 :
for ( V_262 = 0 ; V_262 < V_1012 ; V_262 ++ ) {
sprintf ( V_1006 , L_499 , ( ( V_1013 * ) V_241 ) [ V_262 ] ) ;
V_362 = strlen ( V_1006 ) ;
V_988 = strlen ( V_987 ) ;
if ( ( V_988 + V_362 + 1 ) > 4096 ) {
V_168 = - V_387 ;
goto exit;
}
memcpy ( V_987 + V_988 , V_1006 , V_362 ) ;
}
break;
case V_1009 :
memcpy ( V_987 , V_241 , V_1012 ) ;
break;
default:
F_29 ( L_497 , V_341 ) ;
V_168 = - 1 ;
goto exit;
}
V_988 = strlen ( V_987 ) + 1 ;
V_985 -> V_64 . V_66 = V_988 ;
if ( F_131 ( V_985 -> V_64 . V_452 , V_987 , V_988 ) ) {
V_168 = - V_453 ;
goto exit;
}
} else {
V_985 -> V_64 . V_66 = 0 ;
}
exit:
F_40 ( V_870 ) ;
F_40 ( V_989 ) ;
F_40 ( V_987 ) ;
return V_168 ;
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
V_140 = - V_188 ;
break;
}
return V_140 ;
}
