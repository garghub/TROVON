void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( union V_3 ) ) ;
F_2 ( V_2 -> V_5 , V_6 , & V_4 , NULL ) ;
}
void F_3 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
memset ( & V_4 , 0 , sizeof( union V_3 ) ) ;
V_4 . V_10 . V_11 = V_12 ;
memcpy ( V_4 . V_10 . V_13 , V_8 -> V_14 . V_15 . V_16 , V_17 ) ;
F_4 ( V_18 , L_1 ) ;
F_2 ( V_2 -> V_5 , V_19 , & V_4 , NULL ) ;
}
void F_5 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( union V_3 ) ) ;
V_4 . V_10 . V_11 = V_12 ;
F_6 ( V_4 . V_10 . V_13 ) ;
F_4 ( V_18 , L_2 ) ;
F_2 ( V_2 -> V_5 , V_19 , & V_4 , NULL ) ;
}
static char * F_7 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_22 * V_23 ,
char * V_24 , char * V_25 )
{
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_26 V_27 ;
T_1 V_28 ;
T_2 V_29 ;
T_3 V_30 = 0 ;
char V_31 [ V_32 ] ;
char * V_33 ;
T_1 V_34 = 0 , V_35 , V_36 = false ;
T_3 V_37 = 0 ;
T_4 V_38 = 0 , V_39 = 0 ;
T_1 V_40 = 0 ;
T_4 V_41 , V_42 ;
V_27 . V_43 = V_19 ;
V_27 . V_44 . V_10 . V_11 = V_12 ;
memcpy ( V_27 . V_44 . V_10 . V_13 , V_23 -> V_15 . V_16 , V_17 ) ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_45 ) ;
V_27 . V_43 = V_46 ;
V_27 . V_44 . V_47 . V_48 = 1 ;
V_27 . V_44 . V_47 . V_49 = F_9 ( T_1 , V_23 -> V_15 . V_50 . V_51 , 32 ) ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_23 -> V_15 . V_50 . V_50 ) ;
V_33 = F_11 ( & V_23 -> V_15 . V_52 [ 12 ] , V_53 , & V_30 , V_23 -> V_15 . V_54 - 12 ) ;
if ( V_33 && V_30 > 0 ) {
struct V_55 * V_56 ;
V_36 = true ;
V_56 = (struct V_55 * ) ( V_33 + 2 ) ;
memcpy ( & V_40 , V_56 -> V_57 , 2 ) ;
V_38 = ( V_56 -> V_58 & V_59 ) ? 1 : 0 ;
V_39 = ( V_56 -> V_58 & ( V_60 | V_61 ) ) ? 1 : 0 ;
}
V_27 . V_43 = V_62 ;
if ( ( F_12 ( ( T_4 * ) & V_23 -> V_15 . V_63 ) ) ) {
if ( V_36 )
snprintf ( V_27 . V_44 . V_64 , V_65 , L_3 ) ;
else
snprintf ( V_27 . V_44 . V_64 , V_65 , L_4 ) ;
} else if ( ( F_13 ( ( T_4 * ) & V_23 -> V_15 . V_63 ) ) ) {
if ( V_36 )
snprintf ( V_27 . V_44 . V_64 , V_65 , L_5 ) ;
else
snprintf ( V_27 . V_44 . V_64 , V_65 , L_6 ) ;
} else {
if ( V_23 -> V_15 . V_66 . V_67 > 14 ) {
if ( V_36 )
snprintf ( V_27 . V_44 . V_64 , V_65 , L_7 ) ;
else
snprintf ( V_27 . V_44 . V_64 , V_65 , L_8 ) ;
} else {
if ( V_36 )
snprintf ( V_27 . V_44 . V_64 , V_65 , L_9 ) ;
else
snprintf ( V_27 . V_44 . V_64 , V_65 , L_10 ) ;
}
}
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_68 ) ;
V_27 . V_43 = V_69 ;
memcpy ( & V_29 , F_14 ( V_23 -> V_15 . V_52 ) , 2 ) ;
V_28 = F_15 ( V_29 ) ;
if ( ! F_16 ( V_28 ) ) {
if ( V_28 & V_70 )
V_27 . V_44 . V_71 = V_72 ;
else
V_27 . V_44 . V_71 = V_73 ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_74 ) ;
}
if ( V_23 -> V_15 . V_66 . V_67 < 1 )
V_23 -> V_15 . V_66 . V_67 = 1 ;
V_27 . V_43 = V_75 ;
V_27 . V_44 . V_76 . V_77 = F_17 ( V_23 -> V_15 . V_66 . V_67 ) * 100000 ;
V_27 . V_44 . V_76 . V_78 = 1 ;
V_27 . V_44 . V_76 . V_37 = V_23 -> V_15 . V_66 . V_67 ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_79 ) ;
V_27 . V_43 = V_80 ;
if ( V_28 & V_81 )
V_27 . V_44 . V_47 . V_48 = V_82 | V_83 ;
else
V_27 . V_44 . V_47 . V_48 = V_84 ;
V_27 . V_44 . V_47 . V_49 = 0 ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_23 -> V_15 . V_50 . V_50 ) ;
V_34 = 0 ;
V_33 = V_31 ;
V_33 += snprintf ( V_33 , V_32 - ( V_33 - V_31 ) , L_11 ) ;
while ( V_23 -> V_15 . V_63 [ V_37 ] != 0 ) {
V_35 = V_23 -> V_15 . V_63 [ V_37 ] & 0x7F ;
if ( V_35 > V_34 )
V_34 = V_35 ;
V_33 += snprintf ( V_33 , V_32 - ( V_33 - V_31 ) ,
L_12 , V_35 >> 1 , ( V_35 & 1 ) ? L_13 : L_14 ) ;
V_37 ++ ;
}
if ( V_36 ) {
if ( V_40 & 0x8000 )
V_34 = ( V_38 ) ? ( ( V_39 ) ? 300 : 270 ) : ( ( V_39 ) ? 144 : 130 ) ;
else if ( V_40 & 0x0080 )
;
else
V_34 = ( V_38 ) ? ( ( V_39 ) ? 150 : 135 ) : ( ( V_39 ) ? 72 : 65 ) ;
V_34 = V_34 * 2 ;
}
V_27 . V_43 = V_85 ;
V_27 . V_44 . V_86 . V_87 = 0 ;
V_27 . V_44 . V_86 . V_88 = 0 ;
V_27 . V_44 . V_86 . V_89 = V_34 * 500000 ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_90 ) ;
{
T_4 V_91 [ V_92 ] ;
T_4 V_93 [ 255 ] , V_94 [ 255 ] ;
T_1 V_95 = 0 , V_96 = 0 ;
T_4 * V_33 ;
F_18 ( V_23 -> V_15 . V_52 , V_23 -> V_15 . V_54 , V_94 , & V_96 , V_93 , & V_95 ) ;
F_19 ( V_97 , V_98 , ( L_15 , V_23 -> V_15 . V_50 . V_50 ) ) ;
F_19 ( V_97 , V_98 , ( L_16 , V_95 , V_96 ) ) ;
if ( V_95 > 0 ) {
V_33 = V_91 ;
memset ( V_91 , 0 , V_92 ) ;
V_33 += sprintf ( V_33 , L_17 ) ;
for ( V_37 = 0 ; V_37 < V_95 ; V_37 ++ )
V_33 += sprintf ( V_33 , L_18 , V_93 [ V_37 ] ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_43 = V_99 ;
V_27 . V_44 . V_47 . V_49 = strlen ( V_91 ) ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_91 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_43 = V_100 ;
V_27 . V_44 . V_47 . V_49 = V_95 ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_93 ) ;
}
if ( V_96 > 0 ) {
V_33 = V_91 ;
memset ( V_91 , 0 , V_92 ) ;
V_33 += sprintf ( V_33 , L_19 ) ;
for ( V_37 = 0 ; V_37 < V_96 ; V_37 ++ )
V_33 += sprintf ( V_33 , L_18 , V_94 [ V_37 ] ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_43 = V_99 ;
V_27 . V_44 . V_47 . V_49 = strlen ( V_91 ) ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_91 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_43 = V_100 ;
V_27 . V_44 . V_47 . V_49 = V_96 ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_94 ) ;
}
}
{
T_5 V_101 = 0 , V_102 ;
T_4 * V_103 = NULL ;
T_5 V_104 = 0 ;
T_4 * V_105 = V_23 -> V_15 . V_52 + V_106 ;
V_102 = V_23 -> V_15 . V_54 - V_106 ;
while ( V_101 < V_102 ) {
if ( F_20 ( & V_105 [ V_101 ] , & V_104 ) && ( V_104 > 2 ) ) {
V_103 = & V_105 [ V_101 ] ;
V_27 . V_43 = V_100 ;
V_27 . V_44 . V_47 . V_49 = ( T_1 ) V_104 ;
V_24 = F_10 ( V_21 , V_24 , V_25 , & V_27 , V_103 ) ;
}
V_101 += V_105 [ V_101 + 1 ] + 2 ;
}
}
V_27 . V_43 = V_107 ;
V_27 . V_44 . V_108 . V_109 = V_110 | V_111 | V_112 ;
if ( F_21 ( V_8 , V_113 ) == true &&
F_22 ( & V_8 -> V_14 . V_15 , & V_23 -> V_15 ) ) {
V_41 = V_2 -> V_114 . V_115 ;
V_42 = V_2 -> V_114 . V_116 ;
} else {
V_41 = V_23 -> V_15 . V_117 . V_118 ;
V_42 = V_23 -> V_15 . V_117 . V_119 ;
}
V_27 . V_44 . V_108 . V_120 = ( T_4 ) V_41 ;
V_27 . V_44 . V_108 . V_108 = ( T_4 ) V_42 ;
V_27 . V_44 . V_108 . V_121 = 0 ;
V_24 = F_8 ( V_21 , V_24 , V_25 , & V_27 , V_122 ) ;
return V_24 ;
}
static int F_23 ( struct V_123 * V_124 , T_3 V_89 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
int V_125 = 0 ;
if ( ( V_89 & V_126 ) && ( V_89 & V_127 ) ) {
F_25 ( L_20 , V_89 ) ;
V_2 -> V_128 . V_129 = V_130 ;
V_2 -> V_128 . V_131 = V_132 ;
V_2 -> V_128 . V_133 = V_134 ;
} else if ( V_89 & V_126 ) {
F_25 ( L_21 , V_89 ) ;
V_2 -> V_128 . V_129 = V_130 ;
V_2 -> V_128 . V_131 = V_135 ;
V_2 -> V_128 . V_133 = V_136 ;
} else if ( V_89 & V_127 ) {
F_25 ( L_22 ) ;
if ( V_2 -> V_128 . V_131 < V_137 ) {
V_2 -> V_128 . V_131 = V_138 ;
V_2 -> V_128 . V_133 = V_139 ;
}
} else if ( V_89 & V_140 ) {
F_25 ( L_23 ) ;
} else {
F_25 ( L_24 ) ;
V_125 = - V_141 ;
}
return V_125 ;
}
static int F_26 ( struct V_123 * V_124 , struct V_142 * V_143 , T_3 V_144 )
{
int V_125 = 0 ;
T_3 V_145 , V_146 , V_147 ;
struct V_148 * V_149 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_150 * V_151 = & V_2 -> V_128 ;
V_143 -> V_44 . V_152 . V_153 = 0 ;
V_143 -> V_44 . V_152 . V_154 [ V_155 - 1 ] = '\0' ;
if ( V_144 < ( T_3 ) ( ( T_4 * ) V_143 -> V_44 . V_152 . V_156 - ( T_4 * ) V_143 ) + V_143 -> V_44 . V_152 . V_157 ) {
V_125 = - V_141 ;
goto exit;
}
if ( V_143 -> V_158 [ 0 ] == 0xff && V_143 -> V_158 [ 1 ] == 0xff &&
V_143 -> V_158 [ 2 ] == 0xff && V_143 -> V_158 [ 3 ] == 0xff &&
V_143 -> V_158 [ 4 ] == 0xff && V_143 -> V_158 [ 5 ] == 0xff ) {
if ( V_143 -> V_44 . V_152 . V_159 >= V_160 ) {
V_125 = - V_141 ;
goto exit;
}
} else {
V_125 = - V_141 ;
goto exit;
}
if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_25 ) == 0 ) {
F_19 ( V_161 , V_162 , ( L_26 ) ) ;
F_25 ( L_26 ) ;
V_2 -> V_128 . V_129 = V_130 ;
V_2 -> V_128 . V_163 = V_164 ;
V_2 -> V_128 . V_165 = V_164 ;
V_145 = V_143 -> V_44 . V_152 . V_159 ;
V_146 = V_143 -> V_44 . V_152 . V_157 ;
F_19 ( V_161 , V_98 , ( L_27 , V_145 ) ) ;
F_25 ( L_27 , V_145 ) ;
if ( V_145 > V_160 )
return - V_141 ;
F_19 ( V_161 , V_98 , ( L_28 , V_145 ) ) ;
if ( V_146 > 0 ) {
V_146 = V_146 <= 5 ? 5 : 13 ;
V_147 = V_146 + F_27 ( struct V_148 , V_166 ) ;
V_149 = (struct V_148 * ) F_28 ( V_147 ) ;
if ( V_149 == NULL ) {
F_19 ( V_161 , V_162 , ( L_29 ) ) ;
goto exit;
}
memset ( V_149 , 0 , V_147 ) ;
V_149 -> V_167 = V_146 ;
V_149 -> V_168 = V_147 ;
if ( V_146 == 13 ) {
V_2 -> V_128 . V_163 = V_169 ;
V_2 -> V_128 . V_165 = V_169 ;
}
} else {
V_125 = - V_141 ;
goto exit;
}
V_149 -> V_170 = V_145 ;
V_149 -> V_170 |= 0x80000000 ;
memcpy ( V_149 -> V_166 , V_143 -> V_44 . V_152 . V_156 , V_149 -> V_167 ) ;
if ( V_143 -> V_44 . V_152 . V_171 ) {
F_25 ( L_30 ) ;
if ( F_29 ( V_2 , V_149 ) == ( T_4 ) V_172 )
V_125 = - V_173 ;
} else {
F_25 ( L_31 ) ;
if ( V_145 >= V_160 ) {
V_125 = - V_173 ;
goto exit;
}
memcpy ( & ( V_151 -> V_174 [ V_145 ] . V_175 [ 0 ] ) , V_149 -> V_166 , V_149 -> V_167 ) ;
V_151 -> V_176 [ V_145 ] = V_149 -> V_167 ;
F_30 ( V_2 , V_151 , V_145 , 0 ) ;
}
goto exit;
}
if ( V_2 -> V_128 . V_133 == V_177 ) {
struct V_178 * V_179 , * V_180 ;
struct V_181 * V_182 = & V_2 -> V_183 ;
if ( F_21 ( V_8 , V_184 | V_185 ) ) {
V_179 = F_31 ( V_182 , F_32 ( V_8 ) ) ;
if ( V_179 == NULL ) {
;
} else {
if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_32 ) != 0 )
V_179 -> V_186 = false ;
if ( ( V_2 -> V_128 . V_129 == V_187 ) ||
( V_2 -> V_128 . V_129 == V_188 ) )
V_179 -> V_189 = V_2 -> V_128 . V_163 ;
if ( V_143 -> V_44 . V_152 . V_171 == 1 ) {
memcpy ( V_179 -> V_190 . V_175 , V_143 -> V_44 . V_152 . V_156 , F_9 ( T_1 , V_143 -> V_44 . V_152 . V_157 , 16 ) ) ;
if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_33 ) == 0 ) {
memcpy ( V_179 -> V_191 . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 16 ] ) , 8 ) ;
memcpy ( V_179 -> V_192 . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 24 ] ) , 8 ) ;
V_2 -> V_128 . V_193 = false ;
}
F_25 ( L_34 ) ;
F_33 ( V_2 , ( unsigned char * ) V_179 , true ) ;
} else {
memcpy ( V_2 -> V_128 . V_194 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 , V_143 -> V_44 . V_152 . V_156 , F_9 ( T_1 , V_143 -> V_44 . V_152 . V_157 , 16 ) ) ;
memcpy ( V_2 -> V_128 . V_195 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 16 ] ) , 8 ) ;
memcpy ( V_2 -> V_128 . V_196 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 24 ] ) , 8 ) ;
V_2 -> V_128 . V_197 = true ;
F_25 ( L_35 ) ;
V_2 -> V_128 . V_198 = V_143 -> V_44 . V_152 . V_159 ;
F_30 ( V_2 , & V_2 -> V_128 , V_143 -> V_44 . V_152 . V_159 , 1 ) ;
}
}
V_180 = F_34 ( V_2 ) ;
if ( V_180 == NULL ) {
;
} else {
if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_32 ) != 0 )
V_180 -> V_186 = false ;
if ( ( V_2 -> V_128 . V_129 == V_187 ) ||
( V_2 -> V_128 . V_129 == V_188 ) )
V_180 -> V_189 = V_2 -> V_128 . V_163 ;
}
}
}
exit:
F_35 ( V_149 ) ;
return V_125 ;
}
static int F_36 ( struct V_1 * V_2 , char * V_199 , unsigned short V_200 )
{
T_4 * V_91 = NULL ;
int V_201 = 0 , V_202 = 0 ;
int V_125 = 0 ;
if ( ( V_200 > V_92 ) || ( V_199 == NULL ) ) {
F_37 ( & V_2 -> V_9 , V_203 ) ;
if ( V_199 == NULL )
return V_125 ;
else
return - V_141 ;
}
if ( V_200 ) {
V_91 = F_38 ( V_199 , V_200 , V_204 ) ;
if ( V_91 == NULL ) {
V_125 = - V_205 ;
goto exit;
}
{
int V_37 ;
F_25 ( L_36 , V_200 ) ;
for ( V_37 = 0 ; V_37 < V_200 ; V_37 += 8 )
F_25 ( L_37 , V_91 [ V_37 ] , V_91 [ V_37 + 1 ] , V_91 [ V_37 + 2 ] , V_91 [ V_37 + 3 ] , V_91 [ V_37 + 4 ] , V_91 [ V_37 + 5 ] , V_91 [ V_37 + 6 ] , V_91 [ V_37 + 7 ] ) ;
}
if ( V_200 < V_206 ) {
F_19 ( V_161 , V_162 , ( L_38 , V_200 ) ) ;
V_125 = - 1 ;
goto exit;
}
if ( F_39 ( V_91 , V_200 , & V_201 , & V_202 , NULL ) == V_207 ) {
V_2 -> V_128 . V_133 = V_177 ;
V_2 -> V_128 . V_131 = V_137 ;
memcpy ( V_2 -> V_128 . V_208 , & V_91 [ 0 ] , V_200 ) ;
}
if ( F_40 ( V_91 , V_200 , & V_201 , & V_202 , NULL ) == V_207 ) {
V_2 -> V_128 . V_133 = V_177 ;
V_2 -> V_128 . V_131 = V_209 ;
memcpy ( V_2 -> V_128 . V_208 , & V_91 [ 0 ] , V_200 ) ;
}
switch ( V_201 ) {
case V_210 :
V_2 -> V_128 . V_165 = V_211 ;
V_2 -> V_128 . V_129 = V_212 ;
break;
case V_213 :
V_2 -> V_128 . V_165 = V_164 ;
V_2 -> V_128 . V_129 = V_130 ;
break;
case V_214 :
V_2 -> V_128 . V_165 = V_215 ;
V_2 -> V_128 . V_129 = V_187 ;
break;
case V_216 :
V_2 -> V_128 . V_165 = V_217 ;
V_2 -> V_128 . V_129 = V_188 ;
break;
case V_218 :
V_2 -> V_128 . V_165 = V_169 ;
V_2 -> V_128 . V_129 = V_130 ;
break;
}
switch ( V_202 ) {
case V_210 :
V_2 -> V_128 . V_163 = V_211 ;
V_2 -> V_128 . V_129 = V_212 ;
break;
case V_213 :
V_2 -> V_128 . V_163 = V_164 ;
V_2 -> V_128 . V_129 = V_130 ;
break;
case V_214 :
V_2 -> V_128 . V_163 = V_215 ;
V_2 -> V_128 . V_129 = V_187 ;
break;
case V_216 :
V_2 -> V_128 . V_163 = V_217 ;
V_2 -> V_128 . V_129 = V_188 ;
break;
case V_218 :
V_2 -> V_128 . V_163 = V_169 ;
V_2 -> V_128 . V_129 = V_130 ;
break;
}
F_37 ( & V_2 -> V_9 , V_203 ) ;
{
T_1 V_101 = 0 ;
T_4 V_219 , V_220 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
while ( V_101 < V_200 ) {
V_219 = V_91 [ V_101 ] ;
if ( ( V_219 == V_221 ) && ( ! memcmp ( & V_91 [ V_101 + 2 ] , V_220 , 4 ) ) ) {
F_25 ( L_39 ) ;
V_2 -> V_128 . V_222 = F_41 ( V_91 [ V_101 + 1 ] + 2 , V_92 << 2 ) ;
memcpy ( V_2 -> V_128 . V_223 , & V_91 [ V_101 ] , V_2 -> V_128 . V_222 ) ;
F_42 ( & V_2 -> V_9 , V_203 ) ;
V_101 += V_91 [ V_101 + 1 ] + 2 ;
break;
} else {
V_101 += V_91 [ V_101 + 1 ] + 2 ;
}
}
}
}
F_19 ( V_161 , V_98 ,
( L_40 ,
V_202 , V_2 -> V_128 . V_129 , V_2 -> V_128 . V_131 ) ) ;
exit:
F_35 ( V_91 ) ;
return V_125 ;
}
static int F_43 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
T_3 V_30 = 0 ;
char * V_33 ;
T_4 V_36 = false ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_225 * V_226 = & V_8 -> V_14 . V_15 ;
T_6 * V_227 = NULL ;
F_19 ( V_97 , V_98 , ( L_41 , V_21 -> V_43 ) ) ;
if ( F_21 ( V_8 , V_113 | V_228 ) == true ) {
V_33 = F_11 ( & V_226 -> V_52 [ 12 ] , V_53 , & V_30 , V_226 -> V_54 - 12 ) ;
if ( V_33 && V_30 > 0 )
V_36 = true ;
V_227 = & V_226 -> V_63 ;
if ( F_12 ( ( T_4 * ) V_227 ) == true ) {
if ( V_36 )
snprintf ( V_4 -> V_64 , V_65 , L_3 ) ;
else
snprintf ( V_4 -> V_64 , V_65 , L_4 ) ;
} else if ( ( F_13 ( ( T_4 * ) V_227 ) ) == true ) {
if ( V_36 )
snprintf ( V_4 -> V_64 , V_65 , L_5 ) ;
else
snprintf ( V_4 -> V_64 , V_65 , L_6 ) ;
} else {
if ( V_226 -> V_66 . V_67 > 14 ) {
if ( V_36 )
snprintf ( V_4 -> V_64 , V_65 , L_7 ) ;
else
snprintf ( V_4 -> V_64 , V_65 , L_8 ) ;
} else {
if ( V_36 )
snprintf ( V_4 -> V_64 , V_65 , L_9 ) ;
else
snprintf ( V_4 -> V_64 , V_65 , L_10 ) ;
}
}
} else {
snprintf ( V_4 -> V_64 , V_65 , L_42 ) ;
}
return 0 ;
}
static int F_44 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
F_19 ( V_97 , V_229 , ( L_43 ) ) ;
return 0 ;
}
static int F_45 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_225 * V_226 = & V_8 -> V_14 . V_15 ;
if ( F_21 ( V_8 , V_113 ) ) {
V_4 -> V_76 . V_77 = F_17 ( V_226 -> V_66 . V_67 ) * 100000 ;
V_4 -> V_76 . V_78 = 1 ;
V_4 -> V_76 . V_37 = V_226 -> V_66 . V_67 ;
} else {
V_4 -> V_76 . V_77 = F_17 ( V_2 -> V_230 . V_231 ) * 100000 ;
V_4 -> V_76 . V_78 = 1 ;
V_4 -> V_76 . V_37 = V_2 -> V_230 . V_231 ;
}
return 0 ;
}
static int F_46 ( struct V_123 * V_124 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
enum V_234 V_235 ;
int V_125 = 0 ;
if ( V_172 == F_47 ( V_2 ) ) {
V_125 = - V_236 ;
goto exit;
}
if ( ! V_2 -> V_237 ) {
V_125 = - V_236 ;
goto exit;
}
switch ( V_4 -> V_71 ) {
case V_238 :
V_235 = V_239 ;
F_25 ( L_44 ) ;
break;
case V_73 :
V_235 = V_240 ;
F_25 ( L_45 ) ;
break;
case V_72 :
V_235 = V_241 ;
F_25 ( L_46 ) ;
break;
case V_242 :
V_235 = V_243 ;
F_25 ( L_47 ) ;
break;
default:
V_125 = - V_141 ;
F_19 ( V_161 , V_162 , ( L_48 , V_244 [ V_4 -> V_71 ] ) ) ;
goto exit;
}
if ( F_48 ( V_2 , V_235 ) == false ) {
V_125 = - V_236 ;
goto exit;
}
F_49 ( V_2 , V_235 ) ;
exit:
return V_125 ;
}
static int F_50 ( struct V_123 * V_124 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_233 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
F_19 ( V_97 , V_98 , ( L_49 ) ) ;
if ( F_21 ( V_8 , V_184 ) )
V_4 -> V_71 = V_242 ;
else if ( ( F_21 ( V_8 , V_228 ) ) ||
( F_21 ( V_8 , V_245 ) ) )
V_4 -> V_71 = V_73 ;
else if ( F_21 ( V_8 , V_246 ) )
V_4 -> V_71 = V_72 ;
else
V_4 -> V_71 = V_238 ;
return 0 ;
}
static int F_51 ( struct V_123 * V_124 ,
struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
T_4 V_247 , V_248 = false ;
int V_125 = false ;
struct V_150 * V_151 = & V_2 -> V_128 ;
struct V_249 * V_250 = (struct V_249 * ) V_224 ;
T_4 V_251 [ V_17 ] = { 0x00 } ;
T_4 V_252 [ V_17 ] = { 0x00 } ;
memcpy ( V_252 , V_250 -> V_253 . V_13 , V_17 ) ;
if ( V_250 -> V_43 == V_254 ) {
F_25 ( L_50 ) ;
if ( ! memcmp ( V_252 , V_251 , V_17 ) )
return V_125 ;
else
V_125 = true ;
V_248 = false ;
for ( V_247 = 0 ; V_247 < V_255 ; V_247 ++ ) {
if ( ! memcmp ( V_151 -> V_256 [ V_247 ] . V_257 , V_252 , V_17 ) ) {
F_25 ( L_51 ) ;
memcpy ( V_151 -> V_256 [ V_247 ] . V_258 , V_250 -> V_259 , V_260 ) ;
V_151 -> V_256 [ V_247 ] . V_261 = true ;
V_151 -> V_262 = V_247 + 1 ;
V_248 = true ;
break;
}
}
if ( ! V_248 ) {
F_25 ( L_52 ,
V_151 -> V_262 ) ;
memcpy ( V_151 -> V_256 [ V_151 -> V_262 ] . V_257 , V_252 , V_17 ) ;
memcpy ( V_151 -> V_256 [ V_151 -> V_262 ] . V_258 , V_250 -> V_259 , V_260 ) ;
V_151 -> V_256 [ V_151 -> V_262 ] . V_261 = true ;
V_151 -> V_262 ++ ;
if ( V_151 -> V_262 == 16 )
V_151 -> V_262 = 0 ;
}
} else if ( V_250 -> V_43 == V_263 ) {
F_25 ( L_53 ) ;
V_125 = true ;
for ( V_247 = 0 ; V_247 < V_255 ; V_247 ++ ) {
if ( ! memcmp ( V_151 -> V_256 [ V_247 ] . V_257 , V_252 , V_17 ) ) {
F_6 ( V_151 -> V_256 [ V_247 ] . V_257 ) ;
V_151 -> V_256 [ V_247 ] . V_261 = false ;
break;
}
}
} else if ( V_250 -> V_43 == V_264 ) {
F_25 ( L_54 ) ;
memset ( & V_151 -> V_256 [ 0 ] , 0x00 , sizeof( struct V_265 ) * V_255 ) ;
V_151 -> V_262 = 0 ;
V_125 = true ;
}
return V_125 ;
}
static int F_52 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
V_4 -> V_266 . V_89 = 0 ;
V_4 -> V_266 . V_87 = 0 ;
V_4 -> V_266 . V_88 = 1 ;
return 0 ;
}
static int F_53 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_267 * V_268 = (struct V_267 * ) V_224 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_269 * V_270 = & V_2 -> V_230 ;
T_1 V_271 ;
int V_37 ;
F_19 ( V_97 , V_98 , ( L_55 , V_21 -> V_43 ) ) ;
V_4 -> V_47 . V_49 = sizeof( * V_268 ) ;
memset ( V_268 , 0 , sizeof( * V_268 ) ) ;
V_268 -> V_272 = 5 * 1000 * 1000 ;
V_268 -> V_273 . V_108 = 100 ;
V_268 -> V_273 . V_120 = 100 ;
V_268 -> V_273 . V_121 = 100 ;
V_268 -> V_273 . V_109 = 7 ;
V_268 -> V_274 . V_108 = 92 ;
V_268 -> V_274 . V_120 = 178 ;
V_268 -> V_274 . V_121 = 0 ;
V_268 -> V_274 . V_109 = 7 ;
V_268 -> V_275 = V_276 ;
for ( V_37 = 0 ; V_37 < V_276 && V_37 < V_277 ; V_37 ++ )
V_268 -> V_86 [ V_37 ] = V_278 [ V_37 ] ;
V_268 -> V_279 = V_280 ;
V_268 -> V_281 = V_282 ;
V_268 -> V_283 = 0 ;
V_268 -> V_284 = V_285 ;
V_268 -> V_286 = 16 ;
for ( V_37 = 0 , V_271 = 0 ; V_37 < V_287 ; V_37 ++ ) {
if ( V_270 -> V_288 [ V_37 ] . V_289 != 0 ) {
V_268 -> V_76 [ V_271 ] . V_37 = V_270 -> V_288 [ V_37 ] . V_289 ;
V_268 -> V_76 [ V_271 ] . V_77 = F_17 ( V_270 -> V_288 [ V_37 ] . V_289 ) * 100000 ;
V_268 -> V_76 [ V_271 ] . V_78 = 1 ;
V_271 ++ ;
}
if ( V_271 == V_290 )
break;
}
V_268 -> V_291 = V_271 ;
V_268 -> V_292 = V_271 ;
V_268 -> V_293 = V_294 | V_295 |
V_296 | V_297 ;
V_268 -> V_298 = V_299 | V_300 |
V_301 | V_302 |
V_303 | V_304 ;
return 0 ;
}
static int F_54 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_305 ,
char * V_224 )
{
T_5 V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_306 * V_307 = (struct V_306 * ) V_305 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_308 * V_309 ;
T_4 * V_310 , * V_311 ;
struct V_312 * V_313 = & ( V_8 -> V_314 ) ;
struct V_22 * V_23 = NULL ;
enum V_315 V_316 ;
if ( V_172 == F_47 ( V_2 ) ) {
V_125 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_317 ) {
V_125 = - 1 ;
goto exit;
}
if ( V_307 -> V_11 != V_12 ) {
V_125 = - V_141 ;
goto exit;
}
V_316 = V_2 -> V_128 . V_131 ;
F_55 ( & V_313 -> V_318 ) ;
V_309 = F_56 ( V_313 ) ;
V_8 -> V_319 = V_309 -> V_320 ;
while ( V_309 != V_8 -> V_319 ) {
V_23 = F_57 ( V_8 -> V_319 , struct V_22 , V_321 ) ;
V_8 -> V_319 = V_8 -> V_319 -> V_320 ;
V_310 = V_23 -> V_15 . V_16 ;
V_311 = V_307 -> V_13 ;
if ( ( ! memcmp ( V_310 , V_311 , V_17 ) ) ) {
if ( ! F_48 ( V_2 , V_23 -> V_15 . V_322 ) ) {
V_125 = - 1 ;
F_58 ( & V_313 -> V_318 ) ;
goto exit;
}
break;
}
}
F_58 ( & V_313 -> V_318 ) ;
F_59 ( V_2 , V_316 ) ;
if ( F_60 ( V_2 , V_307 -> V_13 ) == false ) {
V_125 = - 1 ;
goto exit;
}
exit:
return V_125 ;
}
static int F_61 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_225 * V_226 = & V_8 -> V_14 . V_15 ;
V_4 -> V_10 . V_11 = V_12 ;
F_6 ( V_4 -> V_10 . V_13 ) ;
F_19 ( V_97 , V_98 , ( L_56 ) ) ;
if ( ( ( F_21 ( V_8 , V_113 ) ) == true ) ||
( ( F_21 ( V_8 , V_228 ) ) == true ) ||
( ( F_21 ( V_8 , V_246 ) ) == true ) )
memcpy ( V_4 -> V_10 . V_13 , V_226 -> V_16 , V_17 ) ;
else
F_6 ( V_4 -> V_10 . V_13 ) ;
return 0 ;
}
static int F_62 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
int V_125 = 0 ;
T_1 V_323 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_324 * V_325 = (struct V_324 * ) V_224 ;
if ( V_325 == NULL )
return - 1 ;
F_25 ( L_57 , V_326 ) ;
V_323 = V_325 -> V_327 ;
F_25 ( L_58 , V_326 , V_325 -> V_43 , V_323 ) ;
switch ( V_325 -> V_43 ) {
case V_328 :
if ( ! F_63 ( V_2 ) )
V_125 = - 1 ;
break;
case V_329 :
if ( ! F_63 ( V_2 ) )
V_125 = - 1 ;
break;
default:
return - V_173 ;
}
return V_125 ;
}
static int F_64 ( struct V_123 * V_124 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
T_4 V_330 = false ;
int V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_331 V_332 [ V_333 ] ;
F_19 ( V_97 , V_98 , ( L_59 ) ) ;
if ( V_2 -> V_334 . V_335 == 1 ) {
if ( F_21 ( V_8 , V_185 ) ) {
V_125 = - 1 ;
goto exit;
}
}
if ( V_172 == F_47 ( V_2 ) ) {
V_125 = - 1 ;
goto exit;
}
if ( V_2 -> V_336 ) {
F_25 ( L_60 , V_2 -> V_336 ) ;
V_125 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_317 ) {
V_125 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_237 ) {
V_125 = - 1 ;
goto exit;
}
if ( V_8 -> V_337 . V_338 ) {
F_1 ( V_2 ) ;
goto exit;
}
if ( F_21 ( V_8 , V_339 | V_340 ) ) {
F_1 ( V_2 ) ;
goto exit;
}
memset ( V_332 , 0 , sizeof( struct V_331 ) * V_333 ) ;
if ( V_4 -> V_47 . V_49 == sizeof( struct V_341 ) ) {
struct V_341 * V_342 = (struct V_341 * ) V_224 ;
if ( V_4 -> V_47 . V_48 & V_343 ) {
int V_344 = F_9 ( int , V_342 -> V_345 ,
V_346 ) ;
memcpy ( V_332 [ 0 ] . V_50 , V_342 -> V_347 , V_344 ) ;
V_332 [ 0 ] . V_51 = V_344 ;
F_25 ( L_61 , V_342 -> V_347 , V_342 -> V_345 ) ;
F_55 ( & V_8 -> V_318 ) ;
V_330 = F_65 ( V_2 , V_332 , 1 , NULL , 0 ) ;
F_58 ( & V_8 -> V_318 ) ;
} else if ( V_342 -> V_348 == V_349 ) {
F_25 ( L_62 ) ;
}
} else {
if ( V_4 -> V_47 . V_49 >= V_350 &&
! memcmp ( V_224 , V_351 , V_350 ) ) {
int V_344 = V_4 -> V_47 . V_49 - V_350 ;
char * V_352 = V_224 + V_350 ;
char V_353 ;
char V_354 ;
int V_355 = 0 ;
while ( V_344 >= 1 ) {
V_353 = * ( V_352 ++ ) ;
V_344 -= 1 ;
switch ( V_353 ) {
case V_356 :
if ( V_344 < 1 ) {
V_344 = 0 ;
break;
}
V_354 = * ( V_352 ++ ) ; V_344 -= 1 ;
if ( V_354 > 0 && V_354 <= V_344 ) {
V_332 [ V_355 ] . V_51 = V_354 ;
memcpy ( V_332 [ V_355 ] . V_50 , V_352 , V_332 [ V_355 ] . V_51 ) ;
V_355 ++ ;
}
V_352 += V_354 ;
V_344 -= V_354 ;
break;
case V_357 :
case V_358 :
V_352 += 1 ;
V_344 -= 1 ;
break;
case V_359 :
case V_360 :
case V_361 :
V_352 += 2 ;
V_344 -= 2 ;
break;
default:
V_344 = 0 ;
}
}
V_330 = F_66 ( V_2 , V_332 , V_333 ) ;
} else {
V_330 = F_66 ( V_2 , NULL , 0 ) ;
}
}
if ( ! V_330 )
V_125 = - 1 ;
exit:
return V_125 ;
}
static int F_67 ( struct V_123 * V_124 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
struct V_308 * V_362 , * V_309 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_312 * V_313 = & ( V_8 -> V_314 ) ;
struct V_22 * V_23 = NULL ;
char * V_363 = V_224 ;
char * V_25 = V_363 + V_4 -> V_47 . V_49 ;
T_3 V_125 = 0 ;
T_3 V_101 = 0 ;
T_3 V_364 ;
int V_365 ;
F_19 ( V_97 , V_98 , ( L_63 ) ) ;
F_19 ( V_161 , V_98 , ( L_64 ) ) ;
if ( V_2 -> V_366 . V_367 && V_2 -> V_336 ) {
V_125 = - V_141 ;
goto exit;
}
V_364 = 100 ;
V_365 = V_339 | V_340 ;
while ( F_21 ( V_8 , V_365 ) ) {
F_68 ( 30 ) ;
V_101 ++ ;
if ( V_101 > V_364 )
break;
}
F_55 ( & ( V_8 -> V_314 . V_318 ) ) ;
V_309 = F_56 ( V_313 ) ;
V_362 = V_309 -> V_320 ;
while ( V_309 != V_362 ) {
if ( ( V_25 - V_363 ) < V_368 ) {
V_125 = - V_369 ;
break;
}
V_23 = F_57 ( V_362 , struct V_22 , V_321 ) ;
if ( F_69 ( V_2 -> V_230 . V_288 , V_23 -> V_15 . V_66 . V_67 ) >= 0 )
V_363 = F_7 ( V_2 , V_232 , V_23 , V_363 , V_25 ) ;
V_362 = V_362 -> V_320 ;
}
F_58 ( & V_8 -> V_314 . V_318 ) ;
V_4 -> V_47 . V_49 = V_363 - V_224 ;
V_4 -> V_47 . V_48 = 0 ;
exit:
return V_125 ;
}
static int F_70 ( struct V_123 * V_124 ,
struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_312 * V_313 = & V_8 -> V_314 ;
struct V_308 * V_309 ;
struct V_22 * V_23 = NULL ;
enum V_315 V_316 ;
struct V_331 V_370 ;
T_4 * V_371 , * V_372 ;
T_5 V_125 = 0 , V_344 ;
F_19 ( V_161 , V_98 ,
( L_65 , F_71 ( V_8 ) ) ) ;
if ( V_172 == F_47 ( V_2 ) ) {
V_125 = - 1 ;
goto exit;
}
if ( ! V_2 -> V_317 ) {
V_125 = - 1 ;
goto exit;
}
if ( V_4 -> V_347 . V_49 > V_346 ) {
V_125 = - V_369 ;
goto exit;
}
if ( F_21 ( V_8 , V_246 ) ) {
V_125 = - 1 ;
goto exit;
}
V_316 = V_2 -> V_128 . V_131 ;
F_25 ( L_66 , V_326 ) ;
if ( V_4 -> V_347 . V_48 && V_4 -> V_347 . V_49 ) {
V_344 = F_9 ( T_5 , V_4 -> V_347 . V_49 , V_346 ) ;
if ( V_4 -> V_347 . V_49 != 33 )
F_25 ( L_67 , V_224 , V_4 -> V_347 . V_49 ) ;
memset ( & V_370 , 0 , sizeof( struct V_331 ) ) ;
V_370 . V_51 = V_344 ;
memcpy ( V_370 . V_50 , V_224 , V_344 ) ;
V_372 = V_370 . V_50 ;
F_19 ( V_161 , V_98 , ( L_68 , V_372 ) ) ;
F_55 ( & V_313 -> V_318 ) ;
V_309 = F_56 ( V_313 ) ;
V_8 -> V_319 = V_309 -> V_320 ;
while ( V_309 != V_8 -> V_319 ) {
V_23 = F_57 ( V_8 -> V_319 , struct V_22 , V_321 ) ;
V_8 -> V_319 = V_8 -> V_319 -> V_320 ;
V_371 = V_23 -> V_15 . V_50 . V_50 ;
F_19 ( V_161 , V_98 ,
( L_69 ,
V_23 -> V_15 . V_50 . V_50 ) ) ;
if ( ( ! memcmp ( V_371 , V_372 , V_370 . V_51 ) ) &&
( V_23 -> V_15 . V_50 . V_51 == V_370 . V_51 ) ) {
F_19 ( V_161 , V_98 ,
( L_70 ) ) ;
if ( F_21 ( V_8 , V_245 ) == true ) {
if ( V_23 -> V_15 . V_322 != V_8 -> V_14 . V_15 . V_322 )
continue;
}
if ( ! F_48 ( V_2 , V_23 -> V_15 . V_322 ) ) {
V_125 = - 1 ;
F_58 ( & V_313 -> V_318 ) ;
goto exit;
}
break;
}
}
F_58 ( & V_313 -> V_318 ) ;
F_19 ( V_161 , V_98 ,
( L_71 , V_316 ) ) ;
F_59 ( V_2 , V_316 ) ;
if ( F_72 ( V_2 , & V_370 ) == false ) {
V_125 = - 1 ;
goto exit;
}
}
exit:
F_25 ( L_72 , V_326 , V_125 ) ;
return V_125 ;
}
static int F_73 ( struct V_123 * V_124 ,
struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
T_3 V_344 , V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_225 * V_226 = & V_8 -> V_14 . V_15 ;
F_19 ( V_97 , V_98 , ( L_73 ) ) ;
if ( ( F_21 ( V_8 , V_113 ) ) ||
( F_21 ( V_8 , V_228 ) ) ) {
V_344 = V_226 -> V_50 . V_51 ;
V_4 -> V_347 . V_49 = V_344 ;
memcpy ( V_224 , V_226 -> V_50 . V_50 , V_344 ) ;
V_4 -> V_347 . V_48 = 1 ;
} else {
V_125 = - 1 ;
goto exit;
}
exit:
return V_125 ;
}
static int F_74 ( struct V_123 * V_124 ,
struct V_20 * V_232 ,
union V_3 * V_4 , char * V_224 )
{
int V_37 ;
T_4 V_373 [ V_374 ] ;
T_3 V_375 = V_4 -> V_86 . V_89 ;
T_3 V_87 = V_4 -> V_86 . V_87 ;
T_3 V_376 = 0 ;
T_4 V_377 [ V_374 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
F_19 ( V_97 , V_98 , ( L_74 ) ) ;
F_19 ( V_161 , V_98 , ( L_75 , V_375 , V_87 ) ) ;
if ( V_375 == - 1 ) {
V_376 = 11 ;
goto V_378;
}
V_375 = V_375 / 100000 ;
switch ( V_375 ) {
case 10 :
V_376 = 0 ;
break;
case 20 :
V_376 = 1 ;
break;
case 55 :
V_376 = 2 ;
break;
case 60 :
V_376 = 3 ;
break;
case 90 :
V_376 = 4 ;
break;
case 110 :
V_376 = 5 ;
break;
case 120 :
V_376 = 6 ;
break;
case 180 :
V_376 = 7 ;
break;
case 240 :
V_376 = 8 ;
break;
case 360 :
V_376 = 9 ;
break;
case 480 :
V_376 = 10 ;
break;
case 540 :
V_376 = 11 ;
break;
default:
V_376 = 11 ;
break;
}
V_378:
for ( V_37 = 0 ; V_37 < V_374 ; V_37 ++ ) {
if ( V_376 == V_377 [ V_37 ] ) {
V_373 [ V_37 ] = V_377 [ V_37 ] ;
if ( V_87 == 0 )
break;
} else {
V_373 [ V_37 ] = 0xff ;
}
F_19 ( V_161 , V_98 , ( L_76 , V_373 [ V_37 ] ) ) ;
}
return 0 ;
}
static int F_75 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
T_1 V_34 = 0 ;
V_34 = F_76 ( (struct V_1 * ) F_24 ( V_124 ) ) ;
if ( V_34 == 0 )
return - V_236 ;
V_4 -> V_86 . V_87 = 0 ;
V_4 -> V_86 . V_89 = V_34 * 100000 ;
return 0 ;
}
static int F_77 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
if ( V_4 -> V_379 . V_88 ) {
V_2 -> V_334 . V_380 = 2347 ;
} else {
if ( V_4 -> V_379 . V_89 < 0 ||
V_4 -> V_379 . V_89 > 2347 )
return - V_141 ;
V_2 -> V_334 . V_380 = V_4 -> V_379 . V_89 ;
}
F_25 ( L_77 , V_326 , V_2 -> V_334 . V_380 ) ;
return 0 ;
}
static int F_78 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
F_25 ( L_77 , V_326 , V_2 -> V_334 . V_380 ) ;
V_4 -> V_379 . V_89 = V_2 -> V_334 . V_380 ;
V_4 -> V_379 . V_87 = 0 ;
return 0 ;
}
static int F_79 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
if ( V_4 -> V_381 . V_88 ) {
V_2 -> V_382 . V_383 = V_282 ;
} else {
if ( V_4 -> V_381 . V_89 < V_280 ||
V_4 -> V_381 . V_89 > V_282 )
return - V_141 ;
V_2 -> V_382 . V_383 = V_4 -> V_381 . V_89 & ~ 0x1 ;
}
F_25 ( L_78 , V_326 , V_2 -> V_382 . V_383 ) ;
return 0 ;
}
static int F_80 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
F_25 ( L_78 , V_326 , V_2 -> V_382 . V_383 ) ;
V_4 -> V_381 . V_89 = V_2 -> V_382 . V_383 ;
V_4 -> V_381 . V_87 = 0 ;
return 0 ;
}
static int F_81 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
V_4 -> V_384 . V_89 = 7 ;
V_4 -> V_384 . V_87 = 0 ;
V_4 -> V_384 . V_88 = 1 ;
return 0 ;
}
static int F_82 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_385 )
{
T_3 V_156 , V_125 = 0 ;
T_3 V_386 ;
struct V_148 V_387 ;
enum V_315 V_316 ;
struct V_388 * V_389 = & ( V_4 -> V_390 ) ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_391 * V_392 = & V_2 -> V_366 ;
F_25 ( L_79 , V_389 -> V_48 ) ;
memset ( & V_387 , 0 , sizeof( struct V_148 ) ) ;
V_156 = V_389 -> V_48 & V_393 ;
if ( V_389 -> V_48 & V_84 ) {
F_25 ( L_80 ) ;
V_2 -> V_128 . V_129 = V_212 ;
V_2 -> V_128 . V_163 = V_211 ;
V_2 -> V_128 . V_165 = V_211 ;
V_2 -> V_128 . V_133 = V_139 ;
V_316 = V_138 ;
V_2 -> V_128 . V_131 = V_316 ;
goto exit;
}
if ( V_156 ) {
if ( V_156 > V_160 )
return - V_141 ;
V_156 -- ;
V_386 = 1 ;
} else {
V_386 = 0 ;
V_156 = V_2 -> V_128 . V_394 ;
F_25 ( L_81 , V_156 ) ;
}
if ( V_389 -> V_48 & V_395 ) {
F_25 ( L_82 ) ;
V_2 -> V_128 . V_129 = V_130 ;
V_2 -> V_128 . V_133 = V_139 ;
V_2 -> V_128 . V_163 = V_211 ;
V_2 -> V_128 . V_165 = V_211 ;
V_316 = V_138 ;
V_2 -> V_128 . V_131 = V_316 ;
} else if ( V_389 -> V_48 & V_396 ) {
F_25 ( L_83 ) ;
V_2 -> V_128 . V_129 = V_130 ;
V_2 -> V_128 . V_133 = V_136 ;
V_2 -> V_128 . V_163 = V_164 ;
V_2 -> V_128 . V_165 = V_164 ;
V_316 = V_135 ;
V_2 -> V_128 . V_131 = V_316 ;
} else {
F_25 ( L_84 , V_389 -> V_48 ) ;
V_2 -> V_128 . V_129 = V_130 ;
V_2 -> V_128 . V_133 = V_139 ;
V_2 -> V_128 . V_163 = V_211 ;
V_2 -> V_128 . V_165 = V_211 ;
V_316 = V_138 ;
V_2 -> V_128 . V_131 = V_316 ;
}
V_387 . V_170 = V_156 ;
if ( V_389 -> V_49 > 0 ) {
V_387 . V_167 = V_389 -> V_49 <= 5 ? 5 : 13 ;
V_387 . V_168 = V_387 . V_167 + F_27 ( struct V_148 , V_166 ) ;
} else {
V_387 . V_167 = 0 ;
if ( V_386 == 1 ) {
V_2 -> V_128 . V_394 = V_156 ;
F_25 ( L_85 , V_156 , V_2 -> V_128 . V_176 [ V_156 ] ) ;
switch ( V_2 -> V_128 . V_176 [ V_156 ] ) {
case 5 :
V_2 -> V_128 . V_163 = V_164 ;
break;
case 13 :
V_2 -> V_128 . V_163 = V_169 ;
break;
default:
V_2 -> V_128 . V_163 = V_211 ;
break;
}
goto exit;
}
}
V_387 . V_170 |= 0x80000000 ;
memcpy ( V_387 . V_166 , V_385 , V_387 . V_167 ) ;
if ( F_29 ( V_2 , & V_387 ) == false ) {
if ( V_397 == V_392 -> V_398 )
V_125 = - V_173 ;
goto exit;
}
exit:
return V_125 ;
}
static int F_83 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_385 )
{
T_5 V_156 , V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_388 * V_389 = & ( V_4 -> V_390 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_113 ) != true ) {
if ( ! F_21 ( V_8 , V_228 ) ) {
V_389 -> V_49 = 0 ;
V_389 -> V_48 |= V_84 ;
return 0 ;
}
}
V_156 = V_389 -> V_48 & V_393 ;
if ( V_156 ) {
if ( V_156 > V_160 )
return - V_141 ;
V_156 -- ;
} else {
V_156 = V_2 -> V_128 . V_394 ;
}
V_389 -> V_48 = V_156 + 1 ;
switch ( V_2 -> V_128 . V_129 ) {
case V_399 :
case V_212 :
V_389 -> V_49 = 0 ;
V_389 -> V_48 |= V_84 ;
break;
case V_130 :
V_389 -> V_49 = V_2 -> V_128 . V_176 [ V_156 ] ;
if ( V_389 -> V_49 ) {
memcpy ( V_385 , V_2 -> V_128 . V_174 [ V_156 ] . V_175 , V_2 -> V_128 . V_176 [ V_156 ] ) ;
V_389 -> V_48 |= V_82 ;
if ( V_2 -> V_128 . V_131 == V_138 )
V_389 -> V_48 |= V_395 ;
else if ( V_2 -> V_128 . V_131 == V_135 )
V_389 -> V_48 |= V_396 ;
} else {
V_389 -> V_49 = 0 ;
V_389 -> V_48 |= V_84 ;
}
break;
case V_187 :
case V_188 :
V_389 -> V_49 = 16 ;
V_389 -> V_48 |= ( V_82 | V_395 | V_83 ) ;
break;
default:
V_389 -> V_49 = 0 ;
V_389 -> V_48 |= V_84 ;
break;
}
return V_125 ;
}
static int F_84 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
V_4 -> V_400 . V_89 = 0 ;
V_4 -> V_400 . V_87 = 0 ;
V_4 -> V_400 . V_88 = 1 ;
return 0 ;
}
static int F_85 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
return F_36 ( V_2 , V_224 , V_4 -> V_47 . V_49 ) ;
}
static int F_86 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_401 * V_143 = (struct V_401 * ) & ( V_4 -> V_143 ) ;
int V_125 = 0 ;
switch ( V_143 -> V_48 & V_402 ) {
case V_403 :
break;
case V_404 :
break;
case V_405 :
break;
case V_406 :
break;
case V_407 :
if ( V_143 -> V_89 ) {
V_2 -> V_128 . V_408 = true ;
} else {
V_2 -> V_128 . V_408 = false ;
}
break;
case V_409 :
if ( V_2 -> V_128 . V_129 == V_130 )
break;
if ( V_143 -> V_89 ) {
V_2 -> V_128 . V_129 = V_212 ;
V_2 -> V_128 . V_163 = V_211 ;
V_2 -> V_128 . V_165 = V_211 ;
V_2 -> V_128 . V_133 = V_139 ;
V_2 -> V_128 . V_131 = V_138 ;
}
break;
case V_410 :
if ( F_21 ( & V_2 -> V_9 , V_113 ) ) {
F_87 ( V_2 ) ;
F_88 ( V_2 , 500 , false ) ;
F_25 ( L_86 , V_326 ) ;
F_89 ( V_2 ) ;
F_90 ( V_2 ) ;
}
V_125 = F_23 ( V_124 , ( T_3 ) V_143 -> V_89 ) ;
break;
case V_411 :
break;
case V_412 :
break;
case V_413 :
break;
default:
return - V_173 ;
}
return V_125 ;
}
static int F_91 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
char * V_414 ;
T_3 V_144 ;
struct V_142 * V_143 = NULL ;
struct V_388 * V_415 = & V_4 -> V_390 ;
struct V_416 * V_417 = (struct V_416 * ) V_224 ;
int V_125 = 0 ;
V_144 = sizeof( struct V_142 ) + V_417 -> V_157 ;
V_143 = (struct V_142 * ) F_28 ( V_144 ) ;
if ( V_143 == NULL )
return - 1 ;
memset ( V_143 , 0 , V_144 ) ;
V_143 -> V_43 = V_418 ;
F_92 ( V_143 -> V_158 ) ;
switch ( V_417 -> V_154 ) {
case V_419 :
V_414 = L_32 ;
break;
case V_420 :
V_414 = L_25 ;
break;
case V_421 :
V_414 = L_33 ;
break;
case V_422 :
V_414 = L_87 ;
break;
default:
V_125 = - 1 ;
goto exit;
}
strncpy ( ( char * ) V_143 -> V_44 . V_152 . V_154 , V_414 , V_155 ) ;
if ( V_417 -> V_423 & V_424 )
V_143 -> V_44 . V_152 . V_171 = 1 ;
if ( ( V_417 -> V_154 != V_420 ) &&
( V_417 -> V_423 & V_425 ) )
V_143 -> V_44 . V_152 . V_171 = 0 ;
V_143 -> V_44 . V_152 . V_159 = ( V_415 -> V_48 & 0x00FF ) - 1 ;
if ( V_417 -> V_423 & V_426 )
memcpy ( V_143 -> V_44 . V_152 . V_427 , V_417 -> V_428 , 8 ) ;
if ( V_417 -> V_157 ) {
V_143 -> V_44 . V_152 . V_157 = V_417 -> V_157 ;
memcpy ( V_143 -> V_44 . V_152 . V_156 , V_417 + 1 , V_417 -> V_157 ) ;
}
V_125 = F_26 ( V_124 , V_143 , V_144 ) ;
exit:
F_35 ( V_143 ) ;
return V_125 ;
}
static int F_93 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_4 , char * V_224 )
{
if ( V_224 ) {
V_4 -> V_47 . V_49 = 14 ;
V_4 -> V_47 . V_48 = 1 ;
memcpy ( V_224 , L_88 , 14 ) ;
}
return 0 ;
}
static int F_94 ( struct V_123 * V_124 , struct V_20 * V_232 ,
union V_3 * V_4 , char * V_233 )
{
return - 1 ;
}
static int F_95 ( struct V_123 * V_124 , T_4 V_64 , T_3 V_89 )
{
T_5 V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
switch ( V_64 ) {
case V_429 :
V_2 -> V_128 . V_133 = V_177 ;
switch ( ( V_89 ) & 0xff ) {
case 1 :
V_2 -> V_128 . V_131 = V_137 ;
V_2 -> V_128 . V_129 = V_187 ;
break;
case 2 :
V_2 -> V_128 . V_131 = V_209 ;
V_2 -> V_128 . V_129 = V_188 ;
break;
}
F_19 ( V_161 , V_98 ,
( L_89 , V_2 -> V_128 . V_131 ) ) ;
break;
case V_430 :
break;
case V_431 : {
break;
}
case V_432 :
break;
case V_433 :
V_125 = F_23 ( V_124 , V_89 ) ;
break;
case V_434 :
break;
case V_435 :
break;
default:
V_125 = - V_173 ;
break;
}
return V_125 ;
}
static int F_96 ( struct V_123 * V_124 , T_3 V_436 , T_3 V_323 )
{
int V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
switch ( V_436 ) {
case V_437 :
if ( ! F_63 ( V_2 ) )
V_125 = - 1 ;
break;
case V_438 :
if ( ! F_63 ( V_2 ) )
V_125 = - 1 ;
break;
default:
V_125 = - V_173 ;
break;
}
return V_125 ;
}
static int F_97 ( struct V_123 * V_124 , struct V_388 * V_33 )
{
struct V_142 * V_143 ;
T_5 V_125 = 0 ;
if ( V_33 -> V_49 < sizeof( struct V_142 ) || ! V_33 -> V_439 ) {
V_125 = - V_141 ;
goto V_440;
}
V_143 = (struct V_142 * ) F_28 ( V_33 -> V_49 ) ;
if ( V_143 == NULL ) {
V_125 = - V_205 ;
goto V_440;
}
if ( F_98 ( V_143 , V_33 -> V_439 , V_33 -> V_49 ) ) {
F_35 ( V_143 ) ;
V_125 = - V_441 ;
goto V_440;
}
switch ( V_143 -> V_43 ) {
case V_442 :
V_125 = F_95 ( V_124 , V_143 -> V_44 . V_443 . V_64 , V_143 -> V_44 . V_443 . V_89 ) ;
break;
case V_444 :
V_125 = F_36 ( (struct V_1 * ) F_24 ( V_124 ) ,
( char * ) V_143 -> V_44 . V_93 . V_47 , ( T_1 ) V_143 -> V_44 . V_93 . V_344 ) ;
break;
case V_418 :
V_125 = F_26 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_445 :
V_125 = F_96 ( V_124 , V_143 -> V_44 . V_325 . V_436 , V_143 -> V_44 . V_325 . V_327 ) ;
break;
default:
F_25 ( L_90 , V_143 -> V_43 ) ;
V_125 = - V_173 ;
break;
}
if ( V_125 == 0 && F_99 ( V_33 -> V_439 , V_143 , V_33 -> V_49 ) )
V_125 = - V_441 ;
F_35 ( V_143 ) ;
V_440:
return V_125 ;
}
static T_4 F_100 ( struct V_1 * V_2 , struct V_178 * V_179 )
{
struct V_446 * V_447 ;
struct V_448 * V_449 ;
struct V_450 * V_451 = & V_2 -> V_452 ;
T_4 V_453 = V_207 ;
V_447 = F_101 ( sizeof( struct V_446 ) , V_204 ) ;
if ( ! V_447 ) {
V_453 = V_172 ;
goto exit;
}
V_449 = F_101 ( sizeof( struct V_448 ) , V_204 ) ;
if ( ! V_449 ) {
F_35 ( V_447 ) ;
V_453 = V_172 ;
goto exit;
}
F_102 ( V_447 , V_449 , V_454 ) ;
V_449 -> V_455 = ( T_4 ) V_179 -> V_189 ;
memcpy ( V_449 -> V_456 , V_179 -> V_457 , V_17 ) ;
memcpy ( V_449 -> V_156 , & V_179 -> V_190 , 16 ) ;
V_453 = F_103 ( V_451 , V_447 ) ;
exit:
return V_453 ;
}
static int F_104 ( struct V_1 * V_2 , T_4 * V_156 , T_4 V_154 , int V_458 )
{
T_4 V_459 ;
struct V_446 * V_460 ;
struct V_461 * V_462 ;
struct V_450 * V_451 = & ( V_2 -> V_452 ) ;
int V_453 = V_207 ;
F_25 ( L_57 , V_326 ) ;
V_460 = F_101 ( sizeof( struct V_446 ) , V_204 ) ;
if ( ! V_460 ) {
V_453 = V_172 ;
goto exit;
}
V_462 = F_101 ( sizeof( struct V_461 ) , V_204 ) ;
if ( ! V_462 ) {
F_35 ( V_460 ) ;
V_453 = V_172 ;
goto exit;
}
memset ( V_462 , 0 , sizeof( struct V_461 ) ) ;
V_462 -> V_458 = ( T_4 ) V_458 ;
V_462 -> V_455 = V_154 ;
V_462 -> V_171 = 1 ;
switch ( V_154 ) {
case V_164 :
V_459 = 5 ;
break;
case V_169 :
V_459 = 13 ;
break;
case V_215 :
case V_463 :
case V_217 :
default:
V_459 = 16 ;
}
memcpy ( & ( V_462 -> V_156 [ 0 ] ) , V_156 , V_459 ) ;
V_460 -> V_464 = V_465 ;
V_460 -> V_466 = ( T_4 * ) V_462 ;
V_460 -> V_467 = ( sizeof( struct V_461 ) ) ;
V_460 -> V_468 = NULL ;
V_460 -> V_469 = 0 ;
F_105 ( & V_460 -> V_321 ) ;
V_453 = F_103 ( V_451 , V_460 ) ;
exit:
return V_453 ;
}
static int F_106 ( struct V_1 * V_2 , T_4 * V_156 , T_4 V_459 , int V_458 )
{
T_4 V_154 ;
switch ( V_459 ) {
case 5 :
V_154 = V_164 ;
break;
case 13 :
V_154 = V_169 ;
break;
default:
V_154 = V_211 ;
}
return F_104 ( V_2 , V_156 , V_154 , V_458 ) ;
}
static int F_107 ( struct V_123 * V_124 , struct V_142 * V_143 , T_3 V_144 )
{
int V_125 = 0 ;
T_3 V_145 , V_146 , V_147 ;
struct V_148 * V_149 = NULL ;
struct V_178 * V_179 = NULL , * V_180 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_150 * V_151 = & ( V_2 -> V_128 ) ;
struct V_181 * V_182 = & V_2 -> V_183 ;
F_25 ( L_57 , V_326 ) ;
V_143 -> V_44 . V_152 . V_153 = 0 ;
V_143 -> V_44 . V_152 . V_154 [ V_155 - 1 ] = '\0' ;
if ( V_144 != sizeof( struct V_142 ) + V_143 -> V_44 . V_152 . V_157 ) {
V_125 = - V_141 ;
goto exit;
}
if ( V_143 -> V_158 [ 0 ] == 0xff && V_143 -> V_158 [ 1 ] == 0xff &&
V_143 -> V_158 [ 2 ] == 0xff && V_143 -> V_158 [ 3 ] == 0xff &&
V_143 -> V_158 [ 4 ] == 0xff && V_143 -> V_158 [ 5 ] == 0xff ) {
if ( V_143 -> V_44 . V_152 . V_159 >= V_160 ) {
V_125 = - V_141 ;
goto exit;
}
} else {
V_179 = F_31 ( V_182 , V_143 -> V_158 ) ;
if ( ! V_179 ) {
F_25 ( L_91 ) ;
goto exit;
}
}
if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_32 ) == 0 && ( V_179 == NULL ) ) {
F_25 ( L_92 , V_143 -> V_44 . V_152 . V_159 ) ;
goto exit;
}
if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_25 ) == 0 && ( V_179 == NULL ) ) {
F_25 ( L_93 ) ;
V_145 = V_143 -> V_44 . V_152 . V_159 ;
V_146 = V_143 -> V_44 . V_152 . V_157 ;
F_25 ( L_94 , V_145 , V_146 ) ;
if ( ( V_145 >= V_160 ) || ( V_146 <= 0 ) ) {
V_125 = - V_141 ;
goto exit;
}
if ( V_146 > 0 ) {
V_146 = V_146 <= 5 ? 5 : 13 ;
V_147 = V_146 + F_27 ( struct V_148 , V_166 ) ;
V_149 = (struct V_148 * ) F_28 ( V_147 ) ;
if ( V_149 == NULL ) {
F_25 ( L_95 ) ;
goto exit;
}
memset ( V_149 , 0 , V_147 ) ;
V_149 -> V_167 = V_146 ;
V_149 -> V_168 = V_147 ;
}
V_149 -> V_170 = V_145 ;
memcpy ( V_149 -> V_166 , V_143 -> V_44 . V_152 . V_156 , V_149 -> V_167 ) ;
if ( V_143 -> V_44 . V_152 . V_171 ) {
F_25 ( L_30 ) ;
V_151 -> V_129 = V_130 ;
V_151 -> V_163 = V_164 ;
V_151 -> V_165 = V_164 ;
if ( V_149 -> V_167 == 13 ) {
V_151 -> V_163 = V_169 ;
V_151 -> V_165 = V_169 ;
}
V_151 -> V_394 = V_145 ;
memcpy ( & ( V_151 -> V_174 [ V_145 ] . V_175 [ 0 ] ) , V_149 -> V_166 , V_149 -> V_167 ) ;
V_151 -> V_176 [ V_145 ] = V_149 -> V_167 ;
F_106 ( V_2 , V_149 -> V_166 , V_149 -> V_167 , V_145 ) ;
} else {
F_25 ( L_31 ) ;
memcpy ( & ( V_151 -> V_174 [ V_145 ] . V_175 [ 0 ] ) , V_149 -> V_166 , V_149 -> V_167 ) ;
V_151 -> V_176 [ V_145 ] = V_149 -> V_167 ;
F_106 ( V_2 , V_149 -> V_166 , V_149 -> V_167 , V_145 ) ;
}
goto exit;
}
if ( ! V_179 && F_21 ( V_8 , V_246 ) ) {
if ( V_143 -> V_44 . V_152 . V_171 == 1 ) {
if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_25 ) == 0 ) {
F_25 ( L_96 , V_326 ) ;
memcpy ( V_151 -> V_194 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 ,
V_143 -> V_44 . V_152 . V_156 , F_9 ( T_1 , V_143 -> V_44 . V_152 . V_157 , 16 ) ) ;
V_151 -> V_165 = V_164 ;
if ( V_143 -> V_44 . V_152 . V_157 == 13 )
V_151 -> V_165 = V_169 ;
} else if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_33 ) == 0 ) {
F_25 ( L_97 , V_326 ) ;
V_151 -> V_165 = V_215 ;
memcpy ( V_151 -> V_194 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 ,
V_143 -> V_44 . V_152 . V_156 , F_9 ( T_1 , V_143 -> V_44 . V_152 . V_157 , 16 ) ) ;
memcpy ( V_151 -> V_195 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 16 ] ) , 8 ) ;
memcpy ( V_151 -> V_196 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 24 ] ) , 8 ) ;
V_151 -> V_193 = true ;
} else if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_87 ) == 0 ) {
F_25 ( L_98 , V_326 ) ;
V_151 -> V_165 = V_217 ;
memcpy ( V_151 -> V_194 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 ,
V_143 -> V_44 . V_152 . V_156 , F_9 ( T_1 , V_143 -> V_44 . V_152 . V_157 , 16 ) ) ;
} else {
F_25 ( L_99 , V_326 ) ;
V_151 -> V_165 = V_211 ;
}
V_151 -> V_198 = V_143 -> V_44 . V_152 . V_159 ;
V_151 -> V_197 = true ;
V_151 -> V_163 = V_151 -> V_165 ;
F_104 ( V_2 , V_143 -> V_44 . V_152 . V_156 , V_151 -> V_165 , V_143 -> V_44 . V_152 . V_159 ) ;
V_180 = F_34 ( V_2 ) ;
if ( V_180 ) {
V_180 -> V_186 = false ;
V_180 -> V_189 = V_151 -> V_165 ;
}
}
goto exit;
}
if ( V_151 -> V_133 == V_177 && V_179 ) {
if ( F_21 ( V_8 , V_246 ) ) {
if ( V_143 -> V_44 . V_152 . V_171 == 1 ) {
memcpy ( V_179 -> V_190 . V_175 , V_143 -> V_44 . V_152 . V_156 , F_9 ( T_1 , V_143 -> V_44 . V_152 . V_157 , 16 ) ) ;
if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_25 ) == 0 ) {
F_25 ( L_100 , V_326 ) ;
V_179 -> V_189 = V_164 ;
if ( V_143 -> V_44 . V_152 . V_157 == 13 )
V_179 -> V_189 = V_169 ;
} else if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_33 ) == 0 ) {
F_25 ( L_101 , V_326 ) ;
V_179 -> V_189 = V_215 ;
memcpy ( V_179 -> V_191 . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 16 ] ) , 8 ) ;
memcpy ( V_179 -> V_192 . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 24 ] ) , 8 ) ;
V_151 -> V_193 = true ;
} else if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_87 ) == 0 ) {
F_25 ( L_102 , V_326 ) ;
V_179 -> V_189 = V_217 ;
} else {
F_25 ( L_103 , V_326 ) ;
V_179 -> V_189 = V_211 ;
}
F_100 ( V_2 , V_179 ) ;
V_179 -> V_186 = false ;
} else {
if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_25 ) == 0 ) {
memcpy ( V_151 -> V_194 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 ,
V_143 -> V_44 . V_152 . V_156 , F_9 ( T_1 , V_143 -> V_44 . V_152 . V_157 , 16 ) ) ;
V_151 -> V_165 = V_164 ;
if ( V_143 -> V_44 . V_152 . V_157 == 13 )
V_151 -> V_165 = V_169 ;
} else if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_33 ) == 0 ) {
V_151 -> V_165 = V_215 ;
memcpy ( V_151 -> V_194 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 ,
V_143 -> V_44 . V_152 . V_156 , F_9 ( T_1 , V_143 -> V_44 . V_152 . V_157 , 16 ) ) ;
memcpy ( V_151 -> V_195 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 16 ] ) , 8 ) ;
memcpy ( V_151 -> V_196 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 , & ( V_143 -> V_44 . V_152 . V_156 [ 24 ] ) , 8 ) ;
V_151 -> V_193 = true ;
} else if ( strcmp ( V_143 -> V_44 . V_152 . V_154 , L_87 ) == 0 ) {
V_151 -> V_165 = V_217 ;
memcpy ( V_151 -> V_194 [ V_143 -> V_44 . V_152 . V_159 ] . V_175 ,
V_143 -> V_44 . V_152 . V_156 , F_9 ( T_1 , V_143 -> V_44 . V_152 . V_157 , 16 ) ) ;
} else {
V_151 -> V_165 = V_211 ;
}
V_151 -> V_198 = V_143 -> V_44 . V_152 . V_159 ;
V_151 -> V_197 = true ;
V_151 -> V_163 = V_151 -> V_165 ;
F_104 ( V_2 , V_143 -> V_44 . V_152 . V_156 , V_151 -> V_165 , V_143 -> V_44 . V_152 . V_159 ) ;
V_180 = F_34 ( V_2 ) ;
if ( V_180 ) {
V_180 -> V_186 = false ;
V_180 -> V_189 = V_151 -> V_165 ;
}
}
}
}
exit:
F_35 ( V_149 ) ;
return V_125 ;
}
static int F_108 ( struct V_123 * V_124 , struct V_142 * V_143 , int V_344 )
{
int V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_181 * V_182 = & V_2 -> V_183 ;
unsigned char * V_470 = V_143 -> V_44 . V_471 . V_91 ;
F_25 ( L_104 , V_326 , V_344 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_141 ;
memcpy ( & V_182 -> V_472 , V_143 -> V_44 . V_471 . V_473 , 2 ) ;
if ( ( V_182 -> V_472 > V_474 ) || ( V_182 -> V_472 <= 0 ) )
V_182 -> V_472 = V_474 ;
if ( F_109 ( V_2 , V_470 , ( V_344 - 12 - 2 ) ) == V_207 )
V_125 = 0 ;
else
V_125 = - V_141 ;
return V_125 ;
}
static int F_110 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
F_25 ( L_57 , V_326 ) ;
F_111 ( V_2 ) ;
return F_112 ( V_2 ) ;
}
static int F_113 ( struct V_123 * V_124 , struct V_142 * V_143 )
{
int V_125 = 0 ;
struct V_178 * V_179 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_181 * V_182 = & V_2 -> V_183 ;
F_25 ( L_105 , V_143 -> V_44 . V_475 . V_476 , ( V_143 -> V_158 ) ) ;
if ( ! F_21 ( V_8 , ( V_113 | V_246 ) ) )
return - V_141 ;
if ( V_143 -> V_158 [ 0 ] == 0xff && V_143 -> V_158 [ 1 ] == 0xff &&
V_143 -> V_158 [ 2 ] == 0xff && V_143 -> V_158 [ 3 ] == 0xff &&
V_143 -> V_158 [ 4 ] == 0xff && V_143 -> V_158 [ 5 ] == 0xff )
return - V_141 ;
V_179 = F_31 ( V_182 , V_143 -> V_158 ) ;
if ( V_179 ) {
int V_48 = V_143 -> V_44 . V_475 . V_48 ;
V_179 -> V_476 = V_143 -> V_44 . V_475 . V_476 ;
memcpy ( V_179 -> V_477 , V_143 -> V_44 . V_475 . V_478 , 16 ) ;
if ( V_479 & V_48 )
V_179 -> V_480 = 1 ;
else
V_179 -> V_480 = 0 ;
if ( V_8 -> V_481 . V_480 == 0 )
V_179 -> V_480 = 0 ;
if ( V_482 & V_48 ) {
V_179 -> V_483 . V_484 = true ;
V_179 -> V_480 = 1 ;
memcpy ( ( void * ) & V_179 -> V_483 . V_36 , ( void * ) & V_143 -> V_44 . V_475 . V_36 , sizeof( struct V_55 ) ) ;
} else {
V_179 -> V_483 . V_484 = false ;
}
if ( V_8 -> V_483 . V_484 == false )
V_179 -> V_483 . V_484 = false ;
F_114 ( V_2 , V_179 ) ;
} else {
V_125 = - V_205 ;
}
return V_125 ;
}
static int F_115 ( struct V_123 * V_124 , struct V_142 * V_143 )
{
int V_125 = 0 ;
struct V_178 * V_179 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_181 * V_182 = & V_2 -> V_183 ;
int V_109 = 0 ;
F_25 ( L_106 , ( V_143 -> V_158 ) ) ;
if ( F_21 ( V_8 , ( V_113 | V_246 ) ) != true )
return - V_141 ;
if ( V_143 -> V_158 [ 0 ] == 0xff && V_143 -> V_158 [ 1 ] == 0xff &&
V_143 -> V_158 [ 2 ] == 0xff && V_143 -> V_158 [ 3 ] == 0xff &&
V_143 -> V_158 [ 4 ] == 0xff && V_143 -> V_158 [ 5 ] == 0xff )
return - V_141 ;
V_179 = F_31 ( V_182 , V_143 -> V_158 ) ;
if ( V_179 ) {
F_55 ( & V_182 -> V_485 ) ;
if ( ! F_116 ( & V_179 -> V_486 ) ) {
F_117 ( & V_179 -> V_486 ) ;
V_182 -> V_487 -- ;
V_109 = F_118 ( V_2 , V_179 , true , V_488 ) ;
}
F_58 ( & V_182 -> V_485 ) ;
F_119 ( V_2 , V_109 ) ;
V_179 = NULL ;
} else {
F_25 ( L_107 ) ;
}
return V_125 ;
}
static int F_120 ( struct V_123 * V_124 , struct V_142 * V_143 , int V_344 )
{
int V_125 = 0 ;
struct V_178 * V_179 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_181 * V_182 = & V_2 -> V_183 ;
struct V_489 * V_490 = (struct V_489 * ) V_143 ;
struct V_491 * V_492 = (struct V_491 * ) V_490 -> V_47 ;
F_25 ( L_108 , ( V_490 -> V_158 ) ) ;
if ( F_21 ( V_8 , ( V_113 | V_246 ) ) != true )
return - V_141 ;
if ( V_490 -> V_158 [ 0 ] == 0xff && V_490 -> V_158 [ 1 ] == 0xff &&
V_490 -> V_158 [ 2 ] == 0xff && V_490 -> V_158 [ 3 ] == 0xff &&
V_490 -> V_158 [ 4 ] == 0xff && V_490 -> V_158 [ 5 ] == 0xff )
return - V_141 ;
V_179 = F_31 ( V_182 , V_490 -> V_158 ) ;
if ( V_179 ) {
V_492 -> V_476 = ( T_1 ) V_179 -> V_476 ;
V_492 -> V_493 = V_179 -> V_493 ;
V_492 -> V_48 = V_179 -> V_48 ;
V_492 -> V_494 = ( ( V_179 -> V_495 ) |
( V_179 -> V_496 << 1 ) |
( V_179 -> V_497 << 2 ) |
( V_179 -> V_498 << 3 ) |
( V_179 -> V_499 << 4 ) |
( V_179 -> V_500 << 5 ) ) ;
V_492 -> V_501 = V_179 -> V_502 ;
memcpy ( V_492 -> V_478 , V_179 -> V_477 , V_179 -> V_502 ) ;
memcpy ( & V_492 -> V_36 , & V_179 -> V_483 . V_36 , sizeof( struct V_55 ) ) ;
V_492 -> V_503 = V_179 -> V_504 . V_505 ;
V_492 -> V_506 = V_179 -> V_504 . V_506 ;
V_492 -> V_507 = V_179 -> V_504 . V_507 ;
V_492 -> V_508 = V_179 -> V_504 . V_508 ;
V_492 -> V_509 = V_179 -> V_504 . V_509 ;
V_492 -> V_510 = V_179 -> V_504 . V_510 ;
} else {
V_125 = - 1 ;
}
return V_125 ;
}
static int F_121 ( struct V_123 * V_124 , struct V_142 * V_143 )
{
int V_125 = 0 ;
struct V_178 * V_179 = NULL ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_181 * V_182 = & V_2 -> V_183 ;
F_25 ( L_109 , ( V_143 -> V_158 ) ) ;
if ( F_21 ( V_8 , ( V_113 | V_246 ) ) != true )
return - V_141 ;
if ( V_143 -> V_158 [ 0 ] == 0xff && V_143 -> V_158 [ 1 ] == 0xff &&
V_143 -> V_158 [ 2 ] == 0xff && V_143 -> V_158 [ 3 ] == 0xff &&
V_143 -> V_158 [ 4 ] == 0xff && V_143 -> V_158 [ 5 ] == 0xff )
return - V_141 ;
V_179 = F_31 ( V_182 , V_143 -> V_158 ) ;
if ( V_179 ) {
if ( V_179 -> V_93 [ 0 ] == V_511 ||
V_179 -> V_93 [ 0 ] == V_512 ) {
int V_513 ;
int V_514 ;
V_513 = V_179 -> V_93 [ 1 ] ;
V_514 = F_9 ( int , V_513 + 2 , sizeof( V_179 -> V_93 ) ) ;
V_143 -> V_44 . V_93 . V_344 = V_514 ;
memcpy ( V_143 -> V_44 . V_93 . V_473 , V_179 -> V_93 , V_514 ) ;
} else {
F_25 ( L_110 ) ;
}
} else {
V_125 = - 1 ;
}
return V_125 ;
}
static int F_122 ( struct V_123 * V_124 , struct V_142 * V_143 , int V_344 )
{
int V_125 = 0 ;
unsigned char V_220 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_269 * V_270 = & ( V_2 -> V_230 ) ;
int V_515 ;
F_25 ( L_104 , V_326 , V_344 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_141 ;
V_515 = V_344 - 12 - 2 ;
F_35 ( V_8 -> V_516 ) ;
V_8 -> V_516 = NULL ;
if ( V_515 > 0 ) {
V_8 -> V_516 = F_28 ( V_515 ) ;
V_8 -> V_517 = V_515 ;
if ( V_8 -> V_516 == NULL ) {
F_25 ( L_111 , V_326 , __LINE__ ) ;
return - V_141 ;
}
memcpy ( V_8 -> V_516 , V_143 -> V_44 . V_471 . V_91 , V_515 ) ;
F_123 ( V_2 , V_221 , V_220 , true ) ;
V_270 -> V_518 = true ;
}
return V_125 ;
}
static int F_124 ( struct V_123 * V_124 , struct V_142 * V_143 , int V_344 )
{
int V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
int V_515 ;
F_25 ( L_104 , V_326 , V_344 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_141 ;
V_515 = V_344 - 12 - 2 ;
F_35 ( V_8 -> V_519 ) ;
V_8 -> V_519 = NULL ;
if ( V_515 > 0 ) {
V_8 -> V_519 = F_28 ( V_515 ) ;
V_8 -> V_520 = V_515 ;
if ( V_8 -> V_519 == NULL ) {
F_25 ( L_111 , V_326 , __LINE__ ) ;
return - V_141 ;
}
memcpy ( V_8 -> V_519 , V_143 -> V_44 . V_471 . V_91 , V_515 ) ;
}
return V_125 ;
}
static int F_125 ( struct V_123 * V_124 , struct V_142 * V_143 , int V_344 )
{
int V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
int V_515 ;
F_25 ( L_104 , V_326 , V_344 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_141 ;
V_515 = V_344 - 12 - 2 ;
F_35 ( V_8 -> V_521 ) ;
V_8 -> V_521 = NULL ;
if ( V_515 > 0 ) {
V_8 -> V_521 = F_28 ( V_515 ) ;
V_8 -> V_522 = V_515 ;
if ( V_8 -> V_521 == NULL ) {
F_25 ( L_111 , V_326 , __LINE__ ) ;
return - V_141 ;
}
memcpy ( V_8 -> V_521 , V_143 -> V_44 . V_471 . V_91 , V_515 ) ;
}
return V_125 ;
}
static int F_126 ( struct V_123 * V_124 , struct V_142 * V_143 , int V_344 )
{
int V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_269 * V_270 = & ( V_2 -> V_230 ) ;
struct V_523 * V_524 = & ( V_270 -> V_525 ) ;
T_4 V_89 ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_141 ;
if ( V_143 -> V_44 . V_443 . V_64 != 0 )
F_25 ( L_112 , V_326 , V_143 -> V_44 . V_443 . V_64 ) ;
V_89 = V_143 -> V_44 . V_443 . V_89 ;
if ( V_89 != 1 && V_89 != 2 )
V_89 = 0 ;
F_25 ( L_113 , V_326 , V_89 ) ;
V_524 -> V_526 = V_89 ;
return V_125 ;
}
static int F_127 ( struct V_123 * V_124 , struct V_142 * V_143 , int V_344 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_141 ;
if ( V_143 -> V_158 [ 0 ] == 0xff && V_143 -> V_158 [ 1 ] == 0xff &&
V_143 -> V_158 [ 2 ] == 0xff && V_143 -> V_158 [ 3 ] == 0xff &&
V_143 -> V_158 [ 4 ] == 0xff && V_143 -> V_158 [ 5 ] == 0xff )
return - V_141 ;
return F_128 ( V_2 , V_143 -> V_158 ) ;
}
static int F_129 ( struct V_123 * V_124 , struct V_142 * V_143 , int V_344 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_141 ;
if ( V_143 -> V_158 [ 0 ] == 0xff && V_143 -> V_158 [ 1 ] == 0xff &&
V_143 -> V_158 [ 2 ] == 0xff && V_143 -> V_158 [ 3 ] == 0xff &&
V_143 -> V_158 [ 4 ] == 0xff && V_143 -> V_158 [ 5 ] == 0xff )
return - V_141 ;
return F_130 ( V_2 , V_143 -> V_158 ) ;
}
static int F_131 ( struct V_123 * V_124 , struct V_142 * V_143 , int V_344 )
{
int V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
if ( F_21 ( V_8 , V_246 ) != true )
return - V_141 ;
F_132 ( V_2 , V_143 -> V_44 . V_325 . V_436 ) ;
return V_125 ;
}
static int F_133 ( struct V_123 * V_124 , struct V_388 * V_33 )
{
struct V_142 * V_143 ;
int V_125 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
if ( ! V_2 -> V_237 ) {
V_125 = - V_236 ;
goto V_440;
}
if ( ! V_33 -> V_439 ) {
V_125 = - V_141 ;
goto V_440;
}
V_143 = (struct V_142 * ) F_28 ( V_33 -> V_49 ) ;
if ( V_143 == NULL ) {
V_125 = - V_205 ;
goto V_440;
}
if ( F_98 ( V_143 , V_33 -> V_439 , V_33 -> V_49 ) ) {
F_35 ( V_143 ) ;
V_125 = - V_441 ;
goto V_440;
}
switch ( V_143 -> V_43 ) {
case V_527 :
V_125 = F_110 ( V_124 ) ;
break;
case V_528 :
V_125 = F_113 ( V_124 , V_143 ) ;
break;
case V_529 :
V_125 = F_115 ( V_124 , V_143 ) ;
break;
case V_530 :
V_125 = F_108 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_531 :
V_125 = F_107 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_532 :
V_125 = F_121 ( V_124 , V_143 ) ;
break;
case V_533 :
V_125 = F_122 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_534 :
V_125 = F_124 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_535 :
V_125 = F_125 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_536 :
V_125 = F_126 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_537 :
V_125 = F_120 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_538 :
V_125 = F_131 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_539 :
V_125 = F_129 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
case V_540 :
V_125 = F_127 ( V_124 , V_143 , V_33 -> V_49 ) ;
break;
default:
F_25 ( L_114 , V_143 -> V_43 ) ;
V_125 = - V_173 ;
break;
}
if ( V_125 == 0 && F_99 ( V_33 -> V_439 , V_143 , V_33 -> V_49 ) )
V_125 = - V_441 ;
F_35 ( V_143 ) ;
V_440:
return V_125 ;
}
static int F_134 ( struct V_123 * V_124 ,
struct V_20 * V_21 ,
union V_3 * V_305 ,
char * V_224 )
{
int V_125 = 0 ;
int V_344 = 0 ;
char * V_541 ;
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_388 * V_542 = (struct V_388 * ) V_305 ;
if ( V_542 -> V_49 == 0 )
return - V_441 ;
V_344 = V_542 -> V_49 ;
V_541 = F_135 ( V_344 ) ;
if ( ! V_541 )
return - V_205 ;
if ( F_98 ( V_541 , V_542 -> V_439 , V_344 ) ) {
F_136 ( V_541 ) ;
return - V_441 ;
}
if ( V_542 -> V_48 == 0x8766 && V_344 > 8 ) {
T_3 V_543 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
T_4 * V_544 = V_541 ;
int V_545 = V_344 ;
T_4 V_220 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
if ( ( V_221 == V_544 [ 0 ] ) &&
( ! memcmp ( & V_544 [ 2 ] , V_220 , 4 ) ) ) {
V_543 = F_41 ( V_545 , V_546 ) ;
V_8 -> V_547 = 0 ;
F_35 ( V_8 -> V_548 ) ;
V_8 -> V_548 = NULL ;
V_8 -> V_548 = F_28 ( V_543 ) ;
if ( V_8 -> V_548 == NULL ) {
F_137 ( L_111 , V_326 , __LINE__ ) ;
V_125 = - V_141 ;
goto V_549;
}
memcpy ( V_8 -> V_548 , V_544 , V_543 ) ;
V_8 -> V_547 = V_543 ;
}
goto V_549;
}
if ( V_344 >= V_350 &&
! memcmp ( V_541 , V_351 , V_350 ) ) {
V_125 = F_64 ( V_124 , V_21 , V_305 , V_541 ) ;
goto V_549;
}
V_549:
F_136 ( V_541 ) ;
return V_125 ;
}
static struct V_550 * F_138 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = (struct V_1 * ) F_24 ( V_124 ) ;
struct V_550 * V_551 = & V_2 -> V_552 ;
int V_553 = 0 ;
int V_554 = 0 ;
int V_555 = 0 ;
if ( ! F_21 ( & V_2 -> V_9 , V_113 ) ) {
V_551 -> V_108 . V_108 = 0 ;
V_551 -> V_108 . V_120 = 0 ;
V_551 -> V_108 . V_121 = 0 ;
} else {
V_553 = V_2 -> V_114 . V_115 ;
V_554 = V_2 -> V_114 . V_116 ;
V_555 = V_2 -> V_114 . V_121 ;
V_551 -> V_108 . V_120 = V_553 ;
V_551 -> V_108 . V_108 = V_554 ;
V_551 -> V_108 . V_121 = V_555 ;
}
V_551 -> V_108 . V_109 = V_556 ;
return & V_2 -> V_552 ;
}
int F_139 ( struct V_123 * V_124 , struct V_557 * V_558 , int V_43 )
{
struct V_559 * V_560 = (struct V_559 * ) V_558 ;
int V_125 = 0 ;
switch ( V_43 ) {
case V_561 :
V_125 = F_97 ( V_124 , & V_560 -> V_44 . V_47 ) ;
break;
#ifdef F_140
case V_562 :
V_125 = F_133 ( V_124 , & V_560 -> V_44 . V_47 ) ;
break;
#endif
case ( V_563 + 1 ) :
V_125 = F_141 ( V_124 , V_558 , V_43 ) ;
break;
default:
V_125 = - V_173 ;
break;
}
return V_125 ;
}
